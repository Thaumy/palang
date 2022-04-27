# `create` 命令

**当前文档适用于如下palang版本**  
v1.0.1

创建数据。

* 格式

  `create <type_name> [tag_name]`

  type_name应为如下取值之一：

  * `record` 文章记录
  * `meta` 文章元信息
  * `comment` 评论
  * `tag` 标签
  * `token` 凭据

  可选参数：

  * tag_name 标签名，此参数仅当type_name为`tag`时可用。

* 返回

  `new <type_name> was created with <1> <2>`

  替换文本由下表给出：

  |      type_name       |   1   |      2      |
  | :------------------: | :---: | :---------: |
  | record/meta/comment |  id   |   type_id   |
  |         tag          | name  |  tag_name   |
  |        token         | value | token_value |

  * type_id type_name的唯一uint64标识
  * tag_name 标签名
  * token_value 凭据值，32字符的UUID

* 示例

  * 新建文章记录

    ```palang
    >create meta
    new meta was created with id 1450455144255852544
    ```

    新建了一个id为*1450455144255852544*的文章记录。

  * 新建标签

    ```palang
    >create tag life
    new tag was created with name life
    ```

    新建了一个名为*life*的标签。

  * 新建凭据

    ```palang
    >create token
    new token was created with value 57a74f6e93f14116bca9832b2b528c46
    ```

    新建了一个值为*57a74f6e93f14116bca9832b2b528c46*的凭据。
