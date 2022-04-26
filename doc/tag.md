# `tag` 命令

**当前文档适用于如下palang版本**  
v1.0.1

为文章元信息添加标签

* 格式

  `tag <tag_name> to meta <meta_id>`

  * tag_name 标签名，只允许小写。若遇到大写会发生自动转换。
  * meta_id 文章元信息id

* 返回
  
  `tag <tag_name> was tagged to meta <meta_id>`

* 示例

  ```palang
  >tag life to meta 1481051131985215421
  tag life was tagged to meta 1481051131985215421
  ```

  命令将id为`1481051131985215421`的文章元信息加上了*life*标签。
