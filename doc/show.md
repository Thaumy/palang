# `show` 命令

**当前文档适用于如下palang版本**  
v1.0.1

获取数据

* 格式

  `show <type_name> <type_id>`

  | type_name |    注解    | type_id | 注解  |
  | :-------: | :--------: | :-----: | :---: |
  |  record   |  文章记录  | type_id |   -   |
  |   meta    | 文章元信息 | type_id |   -   |
  |  comment  |    评论    | type_id |   -   |

* 返回
  
  json数据，包含了指定数据的全部信息。

* 示例

  ```palang
  >show meta 1481051131985215421
  {
    ...
  }
  ```

  命令获取了id为`1481051131985215421`的文章元信息的所有数据。
