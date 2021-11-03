open System
open System
open System.IO
open pilipala.util
open pilipala.util.socket.tcp
open System.Threading
open pilipala.data
open pilipala.kernel
open pilipala.kernel.token
open pilipala.util.io
open pilipala.kernel.palang
open pilipala.kernel.auth
open pilipala.util.socket.tcp
open pilipala.database
open pilipala.database.mysql
open pilipala.database.mysql.ext
open Snowflake.Core
open Microsoft.IdentityModel.Tokens
open pilipala.util.html
open pilipala.util.hash
open System.Text.RegularExpressions
open pilipala.util.encoding

let config =
    readFile @"C:\Users\Thaumy\Desktop\config.yml"

pilipala.start config

(*token.create ()
|> result.unwarp
|> Console.WriteLine*)

serveOn 16112us palangService

Thread.Sleep(Timeout.Infinite)