# palang

**当前文档适用于如下palang版本**  
v1.0.1

## 概要

palang是用于管理pilipala系统的一门无状态交互式命令语言。

本教程基于尽量简化语言使用表述的原则编写。

---

## 约定

* 带有`高亮`的文本为命令文本或是命令关键字，例如：

  `title` 或 `create comment`

* 被尖括号（<>）包裹的文本表示可以被替换的文本，例如：

  `create <type_name>`  
  其中的type_name需被替换为指定格式的文本。

* *斜体*表示用户自定义文本，例如：
  
  > 我们现在演示如何将一篇文章的标题设置为*Good Morning!*。

* 在代码框中的文本表示交互式命令行中的输入与输出，例如：

  ```palang
  >create meta
  new meta created with id 1450455144255852544
  ```

  输入的文本是：`create meta`  
  输出的文本是：new meta created with id 1450455144255852544

---

## 泛用型返回值

此处定义了一系列通用的返回值，它们可能出现在任何命令的输出中。

* `op failed with : <message>`

  出现于：命令的执行由于服务器内部问题而失败时。

  * message 由服务器生成的错误信息

  > 当服务器没有可供描述错误的信息时，会直接返回`op failed`。

* `op timeout`
  
  出现于：命令因网络延迟非常大而被服务器拒绝时。

* `unknown syntax`

  出现于：命令语法不受识别时。

---

## tag

[为文章元信息添加标签](/tag.md)

## detag

[为文章元信息去除标签](/detag.md)

## rebase

[为文章元信息指定新的层级关系](/rebase.md)

## set

[设置指定类型数据的属性值](/set.md)

## erase

[抹除数据](/erase.md)

## recycle

[回收数据](/recycle.md)

## create

[创建数据](/create.md)

## bind

[将文章记录绑定到文章元信息](/bind.md)
