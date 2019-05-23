# [LINQ to XML Programming Overview](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/linqtoxmlprogrammingoverview)

这些主题提供有关 LINQ to XML 类的高级概述信息，以及有关三个最重要类的详细信息。

## 本节内容

| 主题                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [函数编程与过程编程 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/functional-vs-procedural-programming-linq-to-xml) | 总览介绍编写 LINQ to XML 应用程序的两种主要方法。            |
| [LINQ to XML 类概述 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/linq-to-xml-classes-overview) | 提供 LINQ to XML 类的概述。                                  |
| [XElement 类概述 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/xelement-class-overview) | 介绍 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 类，该类表示 XML 元素。 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 是 LINQ to XML 类层次结构中的基础类之一。 |
| [XAttribute 类概述 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/xattribute-class-overview) | 介绍 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 类，该类表示 XML 属性。 |
| [XDocument 类概述 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/xdocument-class-overview) | 介绍 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 类，该类表示 XML 文档。 |
| [如何：生成 LINQ to XML 示例 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-build-linq-to-xml-examples) | 包含生成 LINQ to XML 示例所需的 `Using` 指令。               |

## [Functional vs. Procedural Programming (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/functionalvsproceduralprogramminglinqtoxml)

XML 应用程序有多种类型：

- 有些应用程序采用源 XML 文档并生成与源文档形状不同的新 XML 文档。
- 有些应用程序采用源 XML 文档并生成格式完全不同的结果文档，如 HTML 或 CSV 文本文件。
- 有些应用程序采用源 XML 文档并将记录插入数据库。
- 有些应用程序采用另一个源（如数据库）中的数据并从该数据创建 XML 文档。

这些并不是所有的 XML 应用程序类型，但它们是 XML 程序员必须实现的一组有代表性的功能类型。

对于所有这些类型应用程序，开发人员可以采用两种对比方法：

- 使用声明性方法的函数构造。
- 使用过程代码的内存中 XML 树修改法。

LINQ to XML 同时支持这两种方法。

使用函数方法时，编写可采用源文档并生成具有所需形状的全新结果文档的转换。

就地修改 XML 树时，编写可遍历内存中 XML 树节点并在其中导航以便根据需要插入、删除和修改节点的代码。

可以对任一方法使用 LINQ to XML。 使用的类相同，在某些情况下使用的方法也相同。 但这两种方法的结构和目标却大相径庭。 例如，在不同情况下，其中一种方法通常具有更好的性能，使用更多或更少的内存。 另外，其中一种方法会更容易编写并生成更容易维护的代码。

若要对比查看这两种方法，请参阅[内存中 XML 树修改与函数构造 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/in-memory-xml-tree-modification-vs-functional-construction-linq-to-xml)。

有关编写功能转换的教程，请参阅 [XML 的纯功能转换 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/pure-functional-transformations-of-xml)。

## [LINQ to XML Classes Overview](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/linqtoxmlclassesoverview)

本主题提供 LINQ to XML 命名空间中 [System.Xml.Linq](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq) 类的列表及每个类的简短说明。

### LINQ to XML 类

#### XAttribute 类

[XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 表示一个 XML 属性。 有关详细信息和示例，请参阅 [XAttribute 类概述 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/xattribute-class-overview)。

#### XCData 类

[XCData](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcdata) 表示一个 CDATA 文本节点。

#### XComment 类

[XComment](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcomment) 表示一个 XML 注释。

#### XContainer 类

[XContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer) 是适用于可能具有子节点的所有节点的抽象基类。 下面的类派生自 [XContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer) 类：

- [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)
- [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument)

#### XDeclaration 类

[XDeclaration](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdeclaration) 表示一个 XML 声明。 XML 声明用于声明 XML 版本和文档的编码。 此外，XML 声明还指定 XML 文档是否为独立文档。 如果文档是独立文档，则在外部 DTD 或从内部子集引用的外部参数实体中不存在外部标记声明。

#### XDocument 类

[XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 表示一个 XML 文档。 有关详细信息和示例，请参阅 [XDocument 类概述 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/xdocument-class-overview)。

#### XDocumentType 类

[XDocumentType](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocumenttype) 表示一个 XML 文档类型定义 (DTD)。

#### XElement 类

[XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 表示一个 XML 元素。 有关详细信息和示例，请参阅 [XElement 类概述 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/xelement-class-overview)。

#### XName 类

[XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 表示元素 ([XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)) 和属性 ([XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute)) 的名称。 有关详细信息和示例，请参阅 [XDocument 类概述 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/xdocument-class-overview)。

LINQ to XML 旨在使 XML 名称尽可能简单。 XML 名称由于复杂而通常被视为 XML 中的高级主题。 有证据证明，这种复杂性不是由开发人员编程时通常使用的命名空间造成的，而是由命名空间前缀造成的。 使用命名空间前缀可以减少输入 XML 时需要的击键数或使 XML 更具可读性。 但是，前缀通常只是使用完整的 XML 命名空间的快捷方式，而且在大多数情况下都不是必需的。 LINQ to XML 通过将所有前缀解析为其对应的 XML 命名空间来简化 XML 名称。 如果需要，可以通过 [GetPrefixOfNamespace](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.getprefixofnamespace) 方法可以使用前缀。

如果有必要，可以控制命名空间前缀。 在某些情况下，如果使用的是其他 XML 系统（如 XSLT 或 XAML），则需要控制命名空间前缀。 例如，如果 XPath 表达式使用命名空间前缀且嵌入在 XSLT 样式表中，则将必须确保使用与 XPath 表达式中使用的前缀相匹配的命名空间前缀来序列化 XML 文档。

#### XNamespace 类

[XNamespace](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnamespace) 表示 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 或 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 的命名空间。 命名空间是 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 的一个组件。

#### XNode 类

[XNode](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode) 是一个抽象类，它表示 XML 树的节点。 下面的类派生自 [XNode](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode) 类：

- [XText](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xtext)
- [XContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer)
- [XComment](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcomment)
- [XProcessingInstruction](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xprocessinginstruction)
- [XDocumentType](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocumenttype)

#### XNodeDocumentOrderComparer 类

[XNodeDocumentOrderComparer](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnodedocumentordercomparer) 提供用于比较节点的文档顺序的功能。

#### XNodeEqualityComparer 类

[XNodeEqualityComparer](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnodeequalitycomparer) 提供用于比较节点的值是否相等的功能。

#### XObject 类

[XObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobject) 是 [XNode](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode) 和 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 的抽象基类。 它提供批注和事件功能。

#### XObjectChange 类

[XObjectChange](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobjectchange) 指定对 [XObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobject) 引发事件时的事件类型。

#### XObjectChangeEventArgs 类

[XObjectChangeEventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobjectchangeeventargs) 为 [Changing](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobject.changing) 和 [Changed](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobject.changed) 事件提供数据。

#### XProcessingInstruction 类

[XProcessingInstruction](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xprocessinginstruction) 表示一个 XML 处理指令。 处理指令将信息传递给处理 XML 的应用程序。

#### XText 类

[XText](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xtext) 表示一个文本节点。 多数情况下都不必使用此类。 此类主要用于混合内容。

## [XElement Class Overview](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/xelementclassoverview)

[XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 类是 LINQ to XML 中的基础类之一。 它表示一个 XML 元素。 可以使用该类创建元素；更改元素内容；添加、更改或删除子元素；向元素中添加属性；或以文本格式序列化元素内容。 还可以与 [System.Xml](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml) 中的其他类（例如 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader)、[XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwriter) 和 [XslCompiledTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xsl.xslcompiledtransform)）进行互操作。

### XElement 功能

本主题描述 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 类提供的功能。

#### 构造 XML 树

可以使用各种方式构造 XML 树，包括以下方式：

- 可以在代码中构造 XML 树。 有关详细信息，请参阅[创建 XML 树 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/creating-xml-trees)。
- 可以从包括 [TextReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.textreader)、文本文件或 Web 地址 (URL) 在内的各种源解析 XML。 有关详细信息，请参阅[解析 XML (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/parsing-xml)。
- 可以使用 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 来填充树。 有关更多信息，请参见[ReadFrom](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.readfrom)。
- 如果您有一个可以将内容写入 [XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwriter) 的模块，则可以使用 [CreateWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.createwriter) 方法来创建编写器，将该编写器传递到该模块，然后使用写入 [XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwriter) 的内容来填充 XML 树。

但是，创建 XML 树的最常见的方法如下：

```csharp
XElement contacts =  
    new XElement("Contacts",  
        new XElement("Contact",  
            new XElement("Name", "Patrick Hines"),   
            new XElement("Phone", "206-555-0144"),  
            new XElement("Address",  
                new XElement("Street1", "123 Main St"),  
                new XElement("City", "Mercer Island"),  
                new XElement("State", "WA"),  
                new XElement("Postal", "68042")  
            )  
        )  
    );  
```

另一个创建 XML 树的十分常用的方法是使用 LINQ 查询的结果来填充 XML 树，如下面的示例所示：

```csharp
XElement srcTree = new XElement("Root",  
    new XElement("Element", 1),  
    new XElement("Element", 2),  
    new XElement("Element", 3),  
    new XElement("Element", 4),  
    new XElement("Element", 5)  
);  
XElement xmlTree = new XElement("Root",  
    new XElement("Child", 1),  
    new XElement("Child", 2),  
    from el in srcTree.Elements()  
    where (int)el > 2  
    select el  
);  
Console.WriteLine(xmlTree);  
```

该示例产生下面的输出：

```xml
<Root>  
  <Child>1</Child>  
  <Child>2</Child>  
  <Element>3</Element>  
  <Element>4</Element>  
  <Element>5</Element>  
</Root>  
```

#### 序列化 XML 树

可以将 XML 树序列化为 [File](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.file)、[TextWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.textwriter) 或 [XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwriter)。

有关详细信息，请参阅[序列化 XML 树 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/serializing-xml-trees)。

#### 通过轴方法检索 XML 数据

可以使用轴方法检索属性、子元素、子代元素和上级元素。 LINQ 查询对轴方法进行操作，并提供了多种灵活而有效的方法导航和处理 XML 树。

有关详细信息，请参阅 [LINQ to XML 轴 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/linq-to-xml-axes)。

#### 查询 XML 树

可以编写从 XML 树提取数据的 LINQ 查询。

有关详细信息，请参阅[查询 XML 树 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/querying-xml-trees)。

#### 修改 XML 树

可以通过各种方式修改元素，例如更改元素的内容或属性。 还可以从元素的父级移除元素。

有关详细信息，请参阅[修改 XML 树 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/modifying-xml-trees-linq-to-xml)。

## [XAttribute Class Overview](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/xattributeclassoverview)

属性是与元素关联的名称/值对。 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 类表示 XML 属性。

### 概述

使用 LINQ to XML 中的属性，与使用元素非常相似。 它们的构造函数相似。 用于检索它们的集合的方法相似。属性集合的 LINQ 查询表达式与元素集合的 LINQ 查询表达式看起来非常相似。

将属性添加到元素中的顺序会保留下来。 也就是说，当循环访问属性时，所见到的属性顺序与它们的添加顺序相同。

### XAttribute 构造函数

下面的 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 类构造函数是您将最常使用的构造函数之一：

| 构造函数                                 | 说明                                                         |
| ---------------------------------------- | ------------------------------------------------------------ |
| `XAttribute(XName name, object content)` | 创建一个 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 对象。 `name` 参数指定属性的名称；`content` 指定属性的内容。 |

### 创建具有属性的元素

下面的代码演示创建包含属性的元素的常见任务：

```csharp
XElement phone = new XElement("Phone",  
    new XAttribute("Type", "Home"),  
    "555-555-5555");  
Console.WriteLine(phone);  
```

该示例产生下面的输出：

```xml
<Phone Type="Home">555-555-5555</Phone>  
```

### 属性的函数构造

可以构造与 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 对象的构造一致的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 对象，如下所示：

```csharp
XElement c = new XElement("Customers",  
    new XElement("Customer",  
        new XElement("Name", "John Doe"),  
        new XElement("PhoneNumbers",  
            new XElement("Phone",  
                new XAttribute("type", "home"),  
                "555-555-5555"),  
            new XElement("Phone",  
                new XAttribute("type", "work"),  
                "666-666-6666")  
        )  
    )  
);  
Console.WriteLine(c);  
```

该示例产生下面的输出：

```xml
<Customers>  
  <Customer>  
    <Name>John Doe</Name>  
    <PhoneNumbers>  
      <Phone type="home">555-555-5555</Phone>  
      <Phone type="work">666-666-6666</Phone>  
    </PhoneNumbers>  
  </Customer>  
</Customers>  
```

### 属性不是节点

属性与元素之间有些区别。 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 对象不是 XML 树中的节点。 它们是与 XML 元素关联的名称/值对。 与文档对象模型 (DOM) 相比，这更加贴切地反映了 XML 结构。 虽然 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 对象实际上不是 XML 树的节点，但使用 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 对象与使用 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 对象非常相似。

这一区别仅对编写在节点级使用 XML 树的代码的开发人员特别重要。 许多开发人员不会关心这种区别。

## [XDocument Class Overview](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/xdocumentclassoverview)

本主题介绍 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 类。

### XDocument 类概述

[XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 类包含有效的 XML 文档所需的信息。 其中包括 XML 声明、处理指令和注释。

请注意，如果需要 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 类提供的特定功能，您只需创建 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 对象。 在很多情况下，可以直接使用 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)。 直接使用 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 是一种比较简单的编程模型。

[XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 派生自 [XContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer)。 因此，它可以包含子节点。 但是，[XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 对象只能有一个子 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 节点。 这反映了 XML 标准，即在 XML 文档中只能有一个根元素。

### Xdocument 的组件

[XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 可以包含以下元素：

- 一个 [XDeclaration](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdeclaration) 对象。 [XDeclaration](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdeclaration) 使您能够指定 XML 声明的相关部分：XML 版本、文档的编码以及 XML 文档是否是独立的。
- 一个 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 对象。 这是 XML 文档的根节点。
- 任意数目的 [XProcessingInstruction](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xprocessinginstruction) 对象。 处理指令将信息传递给处理 XML 的应用程序。
- 任意数目的 [XComment](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcomment) 对象。 注释将与根元素同级。 [XComment](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcomment) 对象不能是列表中的第一个参数，因为 XML 文档以注释开头无效。
- 一个用于 DTD 的 [XDocumentType](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocumenttype)。

序列化 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 时，即使 `XDocument.Declaration` 为 `null`，输出也将具有 XML 声明，前提是编写器已经将 `Writer.Settings.OmitXmlDeclaration` 设置为 `false`（默认值）。

默认情况下，LINQ to XML 将版本设置为“1.0”，将编码设置为“utf-8”。

### 在没有 Xdocument 的情况下使用 XElement

如上所述，[XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 类是 LINQ to XML 编程接口中的主类。 在很多情况下，您的应用程序不需要您创建文档。通过使用 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 类，可以创建 XML 树，向它添加其他 XML 树，修改 XML 树并进行保存。

### 使用 XDocument

若要构造一个 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument)，可使用函数构造，正如您构造 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 对象那样。

下面的代码创建一个 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 对象及其关联的包含对象。

```csharp
XDocument d = new XDocument(  
    new XComment("This is a comment."),  
    new XProcessingInstruction("xml-stylesheet",  
        "href='mystyle.css' title='Compact' type='text/css'"),  
    new XElement("Pubs",  
        new XElement("Book",  
            new XElement("Title", "Artifacts of Roman Civilization"),  
            new XElement("Author", "Moreno, Jordao")  
        ),  
        new XElement("Book",  
            new XElement("Title", "Midieval Tools and Implements"),  
            new XElement("Author", "Gazit, Inbar")  
        )  
    ),  
    new XComment("This is another comment.")  
);  
d.Declaration = new XDeclaration("1.0", "utf-8", "true");  
Console.WriteLine(d);  
  
d.Save("test.xml");  
```

当你检查文件 test.xml 时, 会得到以下输出：

```xml
<?xml version="1.0" encoding="utf-8"?>  
<!--This is a comment.-->  
<?xml-stylesheet href='mystyle.css' title='Compact' type='text/css'?>  
<Pubs>  
  <Book>  
    <Title>Artifacts of Roman Civilization</Title>  
    <Author>Moreno, Jordao</Author>  
  </Book>  
  <Book>  
    <Title>Midieval Tools and Implements</Title>  
    <Author>Gazit, Inbar</Author>  
  </Book>  
</Pubs>  
<!--This is another comment.-->  
```

## [How to: Build LINQ to XML Examples](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtobuildlinqtoxmlexamples)

本文档中的各代码段和示例使用多个命名空间中的类和类型。 在编译 C# 代码时，您需要提供相应的 `using` 指令。

### 示例

下面的代码包含 C# 示例需要生成和运行的 `using` 指令。 并非每个示例都需要所有 `using` 指令。

```csharp
using System;  
using System.Diagnostics;  
using System.Collections;  
using System.Collections.Generic;  
using System.Collections.Specialized;  
using System.Text;  
using System.Linq;  
using System.Xml;  
using System.Xml.Linq;  
using System.Xml.Schema;  
using System.Xml.XPath;  
using System.Xml.Xsl;  
using System.IO;  
using System.Threading;  
using System.Reflection;  
using System.IO.Packaging;  
```