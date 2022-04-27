# `recycle` 命令

**当前文档适用于如下palang版本**  
v1.0.1

回收数据

* 格式

  `recycle <type_name> <type_id>`

  * type_name应为如下取值之一：

    * meta 文章元信息
    * comment 评论

  * type_id type_name的id

* 返回

  `<type_name> <type_id> was recycled`

* 示例

  * 回收评论

    ```palang
    >recycle comment 1350055134211877544
    comment 1350055134211877544 was recycled
    ```

    回收了id为*1350055134211877544*的评论。

* 注解
  
  此命令会将指定数据隐藏在系统中以使用户不可见，但它们是可恢复的。  
  由于文章记录、标签和凭据的回收意义不大，所以它们无法被回收（但可以被`erase`命令抹除）。
