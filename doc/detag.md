# `detag` 命令

**当前文档适用于如下palang版本**  
v1.0.1

为文章元信息去除标签

* 格式

  `detag <tag_name> for meta <meta_id>`

  * tag_name 标签名
  * meta_id 文章元信息id

* 返回
  
  `tag <tag_name> now removed from meta <meta_id>`

* 示例

  ```palang
  >detag life for meta 1451051231185215421
  tag life now removed from meta 1451051231185215421
  ```

  命令将*life*标签从id为`1451051231185215421`的文章元信息上去除了。
