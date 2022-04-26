# `erase` 命令

**当前文档适用于如下palang版本**  
v1.0.1

抹除数据

* 格式
  
  `erase <type_name> <1>`

  替换文本由下表给出：

  | type_name |    注解    |      1      |  注解  |
  | :-------: | :--------: | :---------: | :----: |
  |  record   |  文章记录  |   type_id   |   -    |
  |   meta    | 文章元信息 |   type_id   |   -    |
  |  comment  |    评论    |   type_id   |   -    |
  |    tag    |    标签    |  tag_name   | 标签名 |
  |   token   |    凭据    | token_value | 凭据值 |

* 返回

  `<type_name> <1> was erased`

  替换文本同上。

* 示例

  * 抹除标签
  
    ```palang
    >erase tag life
    tag life was erased
    ```

    抹除了名为*life*的标签。

* 注解

  此命令会将指定的数据从系统中永久性删除，适用于隐私要求苛刻的使用场景。
