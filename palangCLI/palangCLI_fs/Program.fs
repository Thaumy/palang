open System
open System.Net
open System.Net.Sockets
open System.Security.Cryptography
open System.Text
open System.Threading
open pilipala.data.result
open pilipala.util.socket.tcp
open pilipala.util.crypto
open pilipala.util.crypto.aes
open pilipala.util.encoding
open pilipala.util.crypto.rsa


let client = connect "127.0.0.1" 16112us

let token = "a6abf30a015f47ecb3cc21fbce1400cc"

let cli (msg: string) = Console.WriteLine msg

client
>>= fun c ->
        c.send "hello"

        if c.recv = "hi" then
            cli "..........ready to auth"

        let keypair = genRsaKeyPair 2048us
        let pubKey = keypair.pubKey
        let priKey = keypair.priKey
        c.send <| pubKey
        cli ".....client pubKey sent"
        let sessionKey = c.recv |> rsa.decrypt priKey
        cli "....sessionKey received"
        token |> aes.encrypt sessionKey |> c.send

        if c.recv = "pass" then
            cli "..............auth pass\n"

        while c.Poll(200, SelectMode.SelectWrite) do
            Console.Write "palang> "
            let cmd = Console.ReadLine()

            if cmd <> "" then
                match cmd with
                | "bye" -> c.Close()
                | x when x.StartsWith("set") ->
                    Console.WriteLine("to(input 'q' to finish):")

                    let rec getValue (sb: StringBuilder) =
                        let line = Console.ReadLine()

                        match line with
                        | "q" -> sb
                        | _ -> $"{line}\n" |> sb.Append |> getValue

                    let attribute_value =
                        getValue(StringBuilder()).ToString().base64url

                    $"{cmd} to {attribute_value}"
                    |> aes.encrypt sessionKey
                    |> c.send
                | _ -> cmd |> aes.encrypt sessionKey |> c.send

                c.recv
                |> aes.decrypt sessionKey
                |> Console.WriteLine

        Ok()
|> ignore
