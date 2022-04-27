# `bind` 命令

**当前文档适用于如下palang版本**  
v1.0.1

将文章记录绑定到文章元信息

* 格式

  `bind record <record_id> to meta <meta_id>`

  * record_id 被压入目标文章元信息的文章记录id
  * meta_id 目标文章元信息的id

* 返回

  `now record <record_id> is bind to meta <meta_id>`

* 示例

  ```palang
  >bind record 1881051134251022514 to meta 1317051234256022512
  now record 1881051134251022514 is bind to meta 1317051234256022512
  ```

  命令将id为`1881051134251022514`的文章记录绑定到了id为`1317051234256022512`的文章元信息。
