## [Programming Guide (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/programmingguidelinqtoxml)

本节提供有关使用 LINQ to XML 进行编程的概念性和指导性信息。

### 本文档的目标读者

本文档面向已经了解 C# 以及 .NET Framework 的一些基本知识的开发人员。

本文档的目的在于降低各类开发人员对 LINQ to XML 的使用难度。 LINQ to XML 使 XML 编程变得更容易。 您无需成为一名专家级开发人员就可以使用它。

LINQ to XML 非常依赖于泛型类。 因此，了解泛型类的使用非常重要。 此外，熟悉作为参数化类型声明的委托也很有帮助。 如果不熟悉 C# 泛型类，请参阅[泛型类](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/generics/generic-classes)。

### 本节内容

| 主题                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [LINQ to XML 编程概述 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/linq-to-xml-programming-overview) | 提供对 LINQ to XML 类的概述以及有关以下三个最重要类的详细信息：[XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)、[XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 和[XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument)。 |
| [创建 XML 树 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/creating-xml-trees) | 提供有关创建 XML 树的概念性和基于任务的信息。 可以通过使用函数构造，或通过从字符串或文件解析 XML 文本来创建 XML 树。 也可以使用 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 来填充 XML 树。 |
| [使用 XML 命名空间 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/working-with-xml-namespaces) | 提供有关创建使用命名空间的 XML 树的详细信息。                |
| [序列化 XML 树 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/serializing-xml-trees) | 描述序列化 XML 树的多种方法，并给出选择使用方法的指导。      |
| [LINQ to XML 轴 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/linq-to-xml-axes) | 列举并介绍 LINQ to XML 轴方法，您必须了解轴方法才能编写 LINQ to XML 查询。 |
| [查询 XML 树 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/querying-xml-trees) | 提供查询 XML 树的常见示例。                                  |
| [修改 XML 树 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/modifying-xml-trees-linq-to-xml) | 如同文档对象模型 (DOM) 一样，LINQ to XML 也允许您就地修改 XML 树。 |
| [高级 LINQ to XML 编程 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/advanced-linq-to-xml-programming) | 提供有关批注、事件、流处理和其他高级方案的信息。             |
| [LINQ to XML 安全性 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/linq-to-xml-security) | 描述与 LINQ to XML 相关的安全问题并提供减小安全隐患的一些指导。 |
| [示例 XML 文档 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-documents-linq-to-xml) | 包含本文档中许多示例使用的示例 XML 文档。                    |