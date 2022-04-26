# `set` 命令

**当前文档适用于如下palang版本**  
v1.0.1

设置指定类型数据的属性值

* 格式
  `set <attribute> for <type_name> <type_id> to <base64url_attribute_value>`

  * type_name应为如下取值之一：

    * `record` 文章记录  
      此时attribute应为如下取值之一：
      * `cover` 封面
      * `title` 标题
      * `summary` 概述
      * `body` 正文
    * `meta` 文章元信息  
      此时attribute应为如下取值之一：
      * `view` 浏览数
      * `star` 星星数
    * `comment` 评论  
      此时attribute应为如下取值之一：
      * `reply_to` 回复到
      * `nick` 昵称
      * `content` 内容
      * `email` 电子邮箱
      * `site` 站点

  * type_id type_name的id
  * base64url_attribute_value attribute将被设置的值，以base64url编码

* 返回

  `the <attribute> of <type_name> <type_id> was updated`

* 示例

  > *Good Morning!*的base64url编码为*R29vZCBNb3JuaW5nIQ*

  ```palang
  >set title for record 1181055134211822544 to R29vZCBNb3JuaW5nIQ
  the title of record 1181055134211822544 was updated
  ```

  命令将id为`1181055134211822544`的文章记录的标题设置为了*Good Morning!*。
