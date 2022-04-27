# `rebase` 命令

**当前文档适用于如下palang版本**  
v1.0.1

为文章元信息指定新的层级关系

* 格式

  `rebase <meta_id> to <super_meta_id>`

  将`meta_id`的上级文章元信息设置为`super_meta_id`

  * 当`super_meta_id`为`0`时，表示将id为`meta_id`的文章设置为不从属于任何文章元信息的文章（即`根文章`，是新文章的默认状况）。

* 返回

  `now meta <meta_id> is based on <super_meta_id>`

* 示例

  ```palang
  >rebase 1450455144255852544 to 1201415141235252514
  now meta 1450455144255852544 is based on 1201415141235252514
  ```

  命令将id为`1450455144255852544`的文章元信息设置到从属于id为`1201415141235252514`的文章元信息。
