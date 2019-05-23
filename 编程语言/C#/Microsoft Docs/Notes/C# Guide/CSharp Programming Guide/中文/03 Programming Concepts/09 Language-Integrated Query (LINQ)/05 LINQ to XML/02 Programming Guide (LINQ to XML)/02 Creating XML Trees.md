# [Creating XML Trees](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/creatingxmltrees)

最常见的 XML 任务之一是构造 XML 树。 本节介绍多种创建 XML 树的方法。
## 本节内容
| 主题                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [函数构造 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/functional-construction-linq-to-xml) | 提供对 LINQ to XML 中的功能构造的概述。 功能构造使您能在单条语句中创建全部或部分 XML 树。 本主题演示如何在构造 XML 树时嵌入查询。 |
| [在 C# 中创建 XML 树 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/creating-xml-trees-linq-to-xml-2) | 演示如何在 C# 中创建树。                                     |
| [分析 XML (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/parsing-xml) | 演示如何从不同的源分析 XML。 LINQ to XML 在 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 的上层，而后者用于分析 XML。 |
| [如何：使用 XmlWriter 填充 XML 树 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-populate-an-xml-tree-with-an-xmlwriter-linq-to-xml) | 演示如何使用 [XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwriter) 填充 XML 树。 |
| [如何：使用 XSD 进行验证 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-validate-using-xsd-linq-to-xml) | 演示如何使用 XSD 验证 XML 树。                               |
| [XElement 和 XDocument 对象的有效内容](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/valid-content-of-xelement-and-xdocument-objects3) | 描述可以传递给构造函数的有效自变量，以及用于向元素和文档添加内容的方法。 |

## [Functional Construction (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/functionalconstructionlinqtoxml)

LINQ to XML 为创建 XML 元素提供了一种称为“函数构造”的有效方式。 函数构造是指在单个语句中创建 XML 树的能力。

启用函数构造的 LINQ to XML 编程接口有几个重要功能：

- [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 构造函数可以对内容采用多种类型的参数。 例如，可以传递另一个 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 对象，该对象将成为一个子元素。 可以传递一个 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 对象，该对象将成为该元素的一个属性。 也可以传递任何其他类型的对象，该对象将转换为字符串并成为该元素的文本内容。
- [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 函数采用类型为 `params` 的 [Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object) 数组，因此可以向该构造函数传递任意数目的对象。 这使您可以创建具有复杂内容的元素。
- 如果对象实现 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1)，则枚举对象中的集合，并添加集合中的所有项。 如果集合包含 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)或 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 对象，则单独添加集合中的每一项。 这一功能很重要，因为它允许您将 LINQ 查询的结果传递给构造函数。

这些功能使你能够编写代码来创建 XML 树。 下面是一个示例：

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

这些功能还使您能够在创建 XML 树时，编写使用 LINQ 查询结果的代码，如下所示：

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

## [Creating XML Trees in C# (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/creatingxmltreeslinqtoxml2)

本节提供有关使用 C# 来创建 XML 树的信息。

有关使用 LINQ 查询结果作为 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 内容的信息，请参阅[功能构造 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/functional-construction-linq-to-xml)。

### 构造元素

通过 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 和 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 构造函数的签名，可以将元素或属性的内容作为参数传递到构造函数。 由于其中一个构造函数使用可变数目的参数，因此可以传递任意数目的子元素。 当然，这些子元素中的每一个都可以包含它们自己的子元素。 对任意元素，可以添加任意多个属性。

在添加 [XNode](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode)（包括 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)）或 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 对象时，如果新内容没有父级，则直接将这些对象附加到 XML 树中。 如果新内容已经有父级，并且是另一 XML 树的一部分，则克隆新内容，并将新克隆的内容附加到 XML 树。本主题最后一个示例对此进行了演示。

若要创建 `contacts`[XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)，可以使用下面的代码：

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

如果正确缩进，则构造 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 对象的代码十分类似于基础 XML 的结构。

### XElement 构造函数

[XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 类使用下面的构造函数用于函数构造。 请注意，对于 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)，存在其他一些构造函数，但是由于它们不用于函数构造，因此没有在此列出。

| 构造函数                                        | 说明                                                         |
| ----------------------------------------------- | ------------------------------------------------------------ |
| `XElement(XName name, object content)`          | 创建 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)。 `name` 参数指定元素的名称；`content` 指定元素的内容。 |
| `XElement(XName name)`                          | 创建一个 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)，其 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 初始化为指定名称。 |
| `XElement(XName name, params object[] content)` | 创建一个 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)，其 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 初始化为指定名称。 从参数列表的内容创建属性和/或子元素。 |

`content` 参数极其灵活。 它支持作为 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 的有效子对象的任何类型的对象。 下面的规则适用于在此参数中传递的不同类型的对象：

- 字符串添加为文本内容。
- [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 添加为子元素。
- [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 添加为属性。
- [XProcessingInstruction](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xprocessinginstruction)、[XComment](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcomment) 或 [XText](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xtext) 添加为子内容。
- 枚举 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable)，并且这些规则递归应用于结果。
- 对任何其他类型，调用其 `ToString` 方法，结果添加为文本内容。

### 创建包含内容的 XElement

可以使用单个方法调用来创建一个包含简单内容的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)。 为此，请指定内容作为第二个参数，如下所示：

```csharp
XElement n = new XElement("Customer", "Adventure Works");  
Console.WriteLine(n);  
```

该示例产生下面的输出：

```xml
<Customer>Adventure Works</Customer>  
```

可以将任意类型的对象作为内容进行传递。 例如，下面的代码创建一个包含浮点数作为内容的元素：

```csharp
XElement n = new XElement("Cost", 324.50);  
Console.WriteLine(n);  
```

该示例产生下面的输出：

```xml
<Cost>324.5</Cost>  
```

该浮点数被装箱并传递给构造函数。 装箱的数字转换为字符串，然后用作元素的内容。

### 创建具有子元素的 XElement

如果传递 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 类的一个实例作为内容参数，则构造函数将创建一个具有子元素的元素：

```csharp
XElement shippingUnit = new XElement("ShippingUnit",  
    new XElement("Cost", 324.50)  
);  
Console.WriteLine(shippingUnit);  
```

该示例产生下面的输出：

```xml
<ShippingUnit>  
  <Cost>324.5</Cost>  
</ShippingUnit>  
```

### 创建具有多个子元素的 XElement

可以传递多个 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 对象作为内容。 每个 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 对象都作为子元素包含进来。

```csharp
XElement address = new XElement("Address",  
    new XElement("Street1", "123 Main St"),  
    new XElement("City", "Mercer Island"),  
    new XElement("State", "WA"),  
    new XElement("Postal", "68042")  
);  
Console.WriteLine(address);  
```

该示例产生下面的输出：

```xml
<Address>  
  <Street1>123 Main St</Street1>  
  <City>Mercer Island</City>  
  <State>WA</State>  
  <Postal>68042</Postal>  
</Address>  
```

将上面的示例进行扩展，可以创建整个 XML 树，如下所示：

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
Console.WriteLine(contacts);  
```

该示例产生下面的输出：

```xml
<Contacts>  
  <Contact>  
    <Name>Patrick Hines</Name>  
    <Phone>206-555-0144</Phone>  
    <Address>  
      <Street1>123 Main St</Street1>  
      <City>Mercer Island</City>  
      <State>WA</State>  
      <Postal>68042</Postal>  
    </Address>  
  </Contact>  
</Contacts>  
```

### 创建具有 XAttribute 的 XElement

如果传递 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 类的一个实例作为内容参数，则构造函数将创建一个具有属性的元素：

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

### 创建空元素

若要创建空 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)，请不要将任何内容传递给构造函数。 下面的示例创建一个空元素：

```csharp
XElement n = new XElement("Customer");  
Console.WriteLine(n);  
```

该示例产生下面的输出：

```xml
<Customer />  
```

### 附加与克隆

前面提到，在添加 [XNode](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode)（包括 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)）或 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 对象时，如果新内容没有父级，则直接将这些对象附加到 XML 树。 如果新内容已经有父级，并且是另一 XML 树的一部分，则克隆新内容，并将新克隆的内容附加到 XML 树。

以下示例演示将有父级的元素添加到树中，以及将没有父级的元素添加到树中时的行为。

```csharp
// Create a tree with a child element.  
XElement xmlTree1 = new XElement("Root",  
    new XElement("Child1", 1)  
);  
  
// Create an element that is not parented.  
XElement child2 = new XElement("Child2", 2);  
  
// Create a tree and add Child1 and Child2 to it.  
XElement xmlTree2 = new XElement("Root",  
    xmlTree1.Element("Child1"),  
    child2  
);  
  
// Compare Child1 identity.  
Console.WriteLine("Child1 was {0}",  
    xmlTree1.Element("Child1") == xmlTree2.Element("Child1") ?  
    "attached" : "cloned");  
  
// Compare Child2 identity.  
Console.WriteLine("Child2 was {0}",  
    child2 == xmlTree2.Element("Child2") ?  
    "attached" : "cloned");  

// The example displays the following output:  
//    Child1 was cloned  
//    Child2 was attached  
```

## [Parsing XML](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/parsingxml)

本节中的主题介绍如何分析 XML 文档。

##### 本节内容

| 主题                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [如何：分析字符串 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-parse-a-string) | 演示如何分析字符串从而创建 XML 树。                          |
| [如何：从文件加载 XML (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-load-xml-from-a-file) | 演示如何使用 [Load](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.load) 方法从 URI 加载 XML。 |
| [在加载或分析 XML 时保留空白](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/preserving-white-space-while-loading-or-parsing-xml1) | 介绍如何在加载 XML 树时控制 LINQ to XML 的空白行为。         |
| [如何：捕捉分析错误 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-catch-parsing-errors) | 演示如何检测格式不正确或无效的 XML。                         |
| [如何：从 XmlReader 创建树 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-create-a-tree-from-an-xmlreader) | 演示如何从 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 直接创建 XML 树。 |
| [如何：流式处理 XmlReader 中的 XML 片段 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-stream-xml-fragments-from-an-xmlreader) | 演示如何使用 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 对 XML 片段进行流式处理。  如果必须处理很大的 XML 文件，将整个 XML 树加载到内存可能不可行。 这时，可以对 XML 片段进行流式处理。 |

##### [How to: Parse a String](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoparseastring)

本主题演示如何分析字符串，以在 C# 中创建 XML 树。

- 示例

下面的 C# 代码演示如何分析字符串。

```csharp
XElement contacts = XElement.Parse(  
    @"<Contacts>  
        <Contact>  
            <Name>Patrick Hines</Name>  
            <Phone Type=""home"">206-555-0144</Phone>  
            <Phone type=""work"">425-555-0145</Phone>  
            <Address>  
            <Street1>123 Main St</Street1>  
            <City>Mercer Island</City>  
            <State>WA</State>  
            <Postal>68042</Postal>  
            </Address>  
            <NetWorth>10</NetWorth>  
        </Contact>  
        <Contact>  
            <Name>Gretchen Rivas</Name>  
            <Phone Type=""mobile"">206-555-0163</Phone>  
            <Address>  
            <Street1>123 Main St</Street1>  
            <City>Mercer Island</City>  
            <State>WA</State>  
            <Postal>68042</Postal>  
            </Address>  
            <NetWorth>11</NetWorth>  
        </Contact>  
    </Contacts>");  
Console.WriteLine(contacts);  
```

##### [How to: Load XML from a File](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoloadxmlfromafile)

本主题演示如何通过使用 [XElement.Load](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.load) 方法从 URI 加载 XML。

- 示例

下面的示例演示如何从文件加载 XML 文档。 下面的示例加载 books.xml 并将 XML 树输出到控制台。

本示例使用下面的 XML 文档：[示例 XML 文件：图书 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-books-linq-to-xml)。

```csharp
XElement booksFromFile = XElement.Load(@"books.xml");  
Console.WriteLine(booksFromFile);  
```

此代码生成以下输出：

```xml
<Catalog>  
  <Book id="bk101">  
    <Author>Garghentini, Davide</Author>  
    <Title>XML Developer's Guide</Title>  
    <Genre>Computer</Genre>  
    <Price>44.95</Price>  
    <PublishDate>2000-10-01</PublishDate>  
    <Description>An in-depth look at creating applications   
      with XML.</Description>  
  </Book>  
  <Book id="bk102">  
    <Author>Garcia, Debra</Author>  
    <Title>Midnight Rain</Title>  
    <Genre>Fantasy</Genre>  
    <Price>5.95</Price>  
    <PublishDate>2000-12-16</PublishDate>  
    <Description>A former architect battles corporate zombies,   
      an evil sorceress, and her own childhood to become queen   
      of the world.</Description>  
  </Book>  
</Catalog>  
```

##### [Preserving White Space while Loading or Parsing XML](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/preservingwhitespacewhileloadingorparsingxml1)

本主题介绍了如何控制 LINQ to XML 的空白符行为。

一种常用情况是读取缩进的 XML，在内存中创建一个没有任何空白文本节点（即不保留空白）的 XML 树，对该 XML 执行某些操作，然后保存带缩进的 XML。 在序列化带格式的 XML 时，只保留 XML 树中有意义的空白。 这是 LINQ to XML 的默认行为。

另一个常见的情况是读取和修改已经有意缩进的 XML。 您可能不想以任何方式更改这种缩进。 若要在 LINQ to XML 中执行此操作，您要在加载或解析 XML 时保留空白，并在序列化 XML 时禁用格式设置。

本主题介绍了填充 XML 树的方法的空白符行为。 有关序列化 XML 树时如何控制空白的信息，请参阅[在序列化时保留空白](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/preserving-white-space-while-serializing)。

##### 用于填充 XML 树的方法的行为

[XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 和 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 类中的以下方法用于填充 XML 树。 可以从文件、[TextReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.textreader)、[XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 或字符串填充 XML 树：

- [XElement.Load](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.load)
- [XElement.Parse](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.parse)
- [XDocument.Load](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument.load)
- [XDocument.Parse](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument.parse)

如果方法不采用 [LoadOptions](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.loadoptions) 作为参数，则该方法将不会保留无意义的空白。

在多数情况下，如果方法采用 [LoadOptions](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.loadoptions) 作为参数，则您可以选择保留无意义的空白作为 XML 树中的文本节点。 但如果方法从 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 中加载 XML，则 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 将确定是否保留空白。 设置 [PreserveWhitespace](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.loadoptions#System_Xml_Linq_LoadOptions_PreserveWhitespace) 不会有影响。

使用这些方法时，如果保留空白，则会将无意义的空白插入到 XML 树中作为 [XText](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xtext) 节点。 如果不保留空白，则不会插入文本节点。

您可以使用 [XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwriter) 创建一个 XML 树。 写入到 [XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwriter) 的节点会在树中进行填充。 但在使用此方法生成 XML 树时，不管节点是否为空白或是否为无意义的空白，都将保留所有节点。

##### [How to: Catch Parsing Errors](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtocatchparsingerrors)

本主题演示如何检测格式不正确或无效的 XML。

LINQ to XML 通过使用 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 实现。 如果将格式不正确或无效的 XML 传递给 LINQ to XML，则基础 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 类将引发异常。 用于分析 XML 的各种方法（如 [XElement.Parse](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.parse)）不会捕捉异常；应用程序可以捕捉异常。

- 示例

下面的代码尝试分析无效的 XML：

```csharp
try {  
    XElement contacts = XElement.Parse(  
        @"<Contacts>  
            <Contact>  
                <Name>Jim Wilson</Name>  
            </Contact>  
          </Contcts>");  
  
    Console.WriteLine(contacts);  
}  
catch (System.Xml.XmlException e)  
{  
    Console.WriteLine(e.Message);  
}  
```

运行此代码时，会引发以下异常：

```
The 'Contacts' start tag on line 1 does not match the end tag of 'Contcts'. Line 5, position 13.  
```

有关 [XElement.Parse](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.parse)、[XDocument.Parse](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument.parse)、[XElement.Load](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.load) 和 [XDocument.Load](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument.load) 方法可能会引发的异常的更多信息，请参见 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 文档。

##### [How to: Create a Tree from an XmlReader](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtocreateatreefromanxmlreader)

本主题演示如何直接从 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 创建 XML 树。 若要从 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 创建 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader)，必须将 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 定位在元素节点上。 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 将跳过注释和处理指令，但如果 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 定位在文本节点上，则将引发错误。 若要避免这类错误，请在从 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 创建 XML 树之前，始终将 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 定位在元素上。

- 示例

本示例使用下面的 XML 文档：[示例 XML 文件：图书 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-books-linq-to-xml)。

下面的代码创建一个 `T:System.Xml.XmlReader` 对象，然后读取节点，直到找到第一个元素节点。 然后加载 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 对象。

```csharp
XmlReader r = XmlReader.Create("books.xml");  
while (r.NodeType != XmlNodeType.Element)  
    r.Read();  
XElement e = XElement.Load(r);  
Console.WriteLine(e);  
```

该示例产生下面的输出：

```xml
<Catalog>  
   <Book id="bk101">  
      <Author>Garghentini, Davide</Author>  
      <Title>XML Developer's Guide</Title>  
      <Genre>Computer</Genre>  
      <Price>44.95</Price>  
      <PublishDate>2000-10-01</PublishDate>  
      <Description>An in-depth look at creating applications   
      with XML.</Description>  
   </Book>  
   <Book id="bk102">  
      <Author>Garcia, Debra</Author>  
      <Title>Midnight Rain</Title>  
      <Genre>Fantasy</Genre>  
      <Price>5.95</Price>  
      <PublishDate>2000-12-16</PublishDate>  
      <Description>A former architect battles corporate zombies,   
      an evil sorceress, and her own childhood to become queen   
      of the world.</Description>  
   </Book>  
</Catalog>  
```

##### [How to: Stream XML Fragments from an XmlReader](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtostreamxmlfragmentsfromanxmlreader)

如果必须处理很大的 XML 文件，将整个 XML 树加载到内存可能不可行。 本主题演示如何使用 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 对片段进行流式处理。

使用 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 读取 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 对象的一种最有效方式是编写您自己的自定义轴方法。 轴方法通常会返回一个集合，比如 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)，如本主题中的示例所示。 在自定义轴方法中，在通过调用 [ReadFrom](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.readfrom) 方法创建 XML 片段后，可以使用 `yield return` 返回该集合。 这可为您的自定义轴方法提供延迟执行语义。

在从 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 对象创建 XML 树时，[XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 必须位于元素上。 [ReadFrom](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.readfrom) 方法在读取该元素的结束标记之前不会返回。

如果想要创建一个部分树，可实例化 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader)，将读取器定位在要转换为 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 树的节点上，然后创建 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 对象。

主题[如何：通过对标头信息的访问流式处理 XML 片段 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-stream-xml-fragments-with-access-to-header-information) 包含有关如何流式处理更复杂的文档的信息和示例。

主题[如何：执行大型 XML 文档的流式转换 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-perform-streaming-transform-of-large-xml-documents) 包含如何使用 LINQ to XML 在保持小内存需求量的同时转换超大型 XML 文档的示例。

- 示例

本示例创建一个自定义轴方法。 可以通过使用 LINQ 查询来查询该方法。 自定义轴方法 `StreamRootChildDoc` 是一个专门设计的方法，用于读取具有重复 `Child` 元素的文档。

```csharp
static IEnumerable<XElement> StreamRootChildDoc(StringReader stringReader)  
{  
    using (XmlReader reader = XmlReader.Create(stringReader))  
    {  
        reader.MoveToContent();  
        // Parse the file and display each of the nodes.  
        while (reader.Read())  
        {  
            switch (reader.NodeType)  
            {  
                case XmlNodeType.Element:  
                    if (reader.Name == "Child") {  
                        XElement el = XElement.ReadFrom(reader) as XElement;  
                        if (el != null)  
                            yield return el;  
                    }  
                    break;  
            }  
        }  
    }  
}  
  
static void Main(string[] args)  
{  
    string markup = @"<Root>  
      <Child Key=""01"">  
        <GrandChild>aaa</GrandChild>  
      </Child>  
      <Child Key=""02"">  
        <GrandChild>bbb</GrandChild>  
      </Child>  
      <Child Key=""03"">  
        <GrandChild>ccc</GrandChild>  
      </Child>  
    </Root>";  
  
    IEnumerable<string> grandChildData =  
        from el in StreamRootChildDoc(new StringReader(markup))  
        where (int)el.Attribute("Key") > 1  
        select (string)el.Element("GrandChild");  
  
    foreach (string str in grandChildData) {  
        Console.WriteLine(str);  
    }  
}  
```

该示例产生下面的输出：

```
bbb  
ccc  
```

在本示例中，源文档非常小。 但是即使有数百万个 `Child` 元素，本示例也仍具有很小的内存需求量。

## [How to: Populate an XML Tree with an XmlWriter (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtopopulateanxmltreewithanxmlwriterlinqtoxml)

填充 XML 树的一种方式是使用 [CreateWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.createwriter) 创建一个 [XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwriter)，然后写入 [XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwriter)。 XML 树将用写入到 [XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwriter) 的所有节点进行填充。

在与预期会向 LINQ to XML 写入数据的另一个类（如 [XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwriter)）一起使用 [XslCompiledTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xsl.xslcompiledtransform) 时，通常应使用此方法。

##### 示例

[CreateWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.createwriter) 可能在调用 XSLT 转换时使用。 本示例创建一个 XML 树，从该 XML 树创建一个 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader)，创建一个新文档，然后创建要写入到新文档的 [XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwriter)。 示例然后调用 XSLT 转换，传入 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 和 [XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwriter)。 在转换成功完成后，使用转换的结果，填充新的 XML 树。

```csharp
string xslMarkup = @"<?xml version='1.0'?>  
<xsl:stylesheet xmlns:xsl='http://www.w3.org/1999/XSL/Transform' version='1.0'>  
    <xsl:template match='/Parent'>  
        <Root>  
            <C1>  
            <xsl:value-of select='Child1'/>  
            </C1>  
            <C2>  
            <xsl:value-of select='Child2'/>  
            </C2>  
        </Root>  
    </xsl:template>  
</xsl:stylesheet>";  
  
XDocument xmlTree = new XDocument(  
    new XElement("Parent",  
        new XElement("Child1", "Child1 data"),  
        new XElement("Child2", "Child2 data")  
    )  
);  
  
XDocument newTree = new XDocument();  
using (XmlWriter writer = newTree.CreateWriter())  
{  
    // Load the style sheet.  
    XslCompiledTransform xslt = new XslCompiledTransform();  
    xslt.Load(XmlReader.Create(new StringReader(xslMarkup)));  
  
    // Execute the transformation and output the results to a writer.  
    xslt.Transform(xmlTree.CreateReader(), writer);  
}  
  
Console.WriteLine(newTree);  
```

该示例产生下面的输出：

```xml
<Root>  
  <C1>Child1 data</C1>  
  <C2>Child2 data</C2>  
</Root>  
```

## [How to: Validate Using XSD (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtovalidateusingxsdlinqtoxml)

[System.Xml.Schema](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.schema) 命名空间包含扩展方法，这些扩展方法可以简化针对 XML 架构定义语言 (XSD) 文件验证 XML 树的过程。 有关更多信息，请参见 [Validate](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.schema.extensions.validate) 方法文档。

- 示例

下面的示例创建一个 [XmlSchemaSet](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.schema.xmlschemaset)，然后针对架构集验证两个 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 对象。 其中一个文档为有效文档，而另一个则不是。

```csharp
string xsdMarkup =  
    @"<xsd:schema xmlns:xsd='http://www.w3.org/2001/XMLSchema'>  
       <xsd:element name='Root'>  
        <xsd:complexType>  
         <xsd:sequence>  
          <xsd:element name='Child1' minOccurs='1' maxOccurs='1'/>  
          <xsd:element name='Child2' minOccurs='1' maxOccurs='1'/>  
         </xsd:sequence>  
        </xsd:complexType>  
       </xsd:element>  
      </xsd:schema>";  
XmlSchemaSet schemas = new XmlSchemaSet();  
schemas.Add("", XmlReader.Create(new StringReader(xsdMarkup)));  
  
XDocument doc1 = new XDocument(  
    new XElement("Root",  
        new XElement("Child1", "content1"),  
        new XElement("Child2", "content1")  
    )  
);  
  
XDocument doc2 = new XDocument(  
    new XElement("Root",  
        new XElement("Child1", "content1"),  
        new XElement("Child3", "content1")  
    )  
);  
  
Console.WriteLine("Validating doc1");  
bool errors = false;  
doc1.Validate(schemas, (o, e) =>  
                     {  
                         Console.WriteLine("{0}", e.Message);  
                         errors = true;  
                     });  
Console.WriteLine("doc1 {0}", errors ? "did not validate" : "validated");  
  
Console.WriteLine();  
Console.WriteLine("Validating doc2");  
errors = false;  
doc2.Validate(schemas, (o, e) =>  
                     {  
                         Console.WriteLine("{0}", e.Message);  
                         errors = true;  
                     });  
Console.WriteLine("doc2 {0}", errors ? "did not validate" : "validated");  
```

该示例产生下面的输出：

```
Validating doc1  
doc1 validated  
  
Validating doc2  
The element 'Root' has invalid child element 'Child3'. List of possible elements expected: 'Child2'.  
doc2 did not validate  
```

- 示例

以下示例验证来自[示例 XML 文件：客户和订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-customers-and-orders-linq-to-xml-2)的 XML 文档对于[示例 XSD 文件：客户和订单](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xsd-file-customers-and-orders1)中的架构是否有效。 然后修改源 XML 文档。 它更改第一个客户的 `CustomerID` 属性。 更改后，订单将指向不存在的客户，因此该 XML 文档不再有效。

本示例使用下面的 XML 文档：[示例 XML 文件：客户和订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-customers-and-orders-linq-to-xml-2)。

本示例使用下面的 XSD 架构：[示例 XSD 文件：客户和订单](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xsd-file-customers-and-orders1).

```csharp
XmlSchemaSet schemas = new XmlSchemaSet();  
schemas.Add("", "CustomersOrders.xsd");  
  
Console.WriteLine("Attempting to validate");  
XDocument custOrdDoc = XDocument.Load("CustomersOrders.xml");  
bool errors = false;  
custOrdDoc.Validate(schemas, (o, e) =>  
                     {  
                         Console.WriteLine("{0}", e.Message);  
                         errors = true;  
                     });  
Console.WriteLine("custOrdDoc {0}", errors ? "did not validate" : "validated");  
  
Console.WriteLine();  
// Modify the source document so that it will not validate.  
custOrdDoc.Root.Element("Orders").Element("Order").Element("CustomerID").Value = "AAAAA";  
Console.WriteLine("Attempting to validate after modification");  
errors = false;  
custOrdDoc.Validate(schemas, (o, e) =>  
                     {  
                         Console.WriteLine("{0}", e.Message);  
                         errors = true;  
                     });  
Console.WriteLine("custOrdDoc {0}", errors ? "did not validate" : "validated");  
```

该示例产生下面的输出：

```
Attempting to validate  
custOrdDoc validated  
  
Attempting to validate after modification  
The key sequence 'AAAAA' in Keyref fails to refer to some key.  
custOrdDoc did not validate  
```

## [Valid Content of XElement and XDocument Objects](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/validcontentofxelementandxdocumentobjects3)

本主题描述可以传递给构造函数以及用于向元素和文档添加内容的方法的有效参数。

##### 有效内容

查询计算的结果通常是 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 或 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute)。 可以将 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 集合或 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 对象传递到 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 构造函数。 所以，可以很方便地将查询的结果作为内容，传递给用于填充 XML 树的方法和构造函数。

添加简单内容时，可以将多种类型传递给此方法。 有效类型包括：

- [String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)
- [Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double)
- [Single](https://docs.microsoft.com/zh-cn/dotnet/api/system.single)
- [Decimal](https://docs.microsoft.com/zh-cn/dotnet/api/system.decimal)
- [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean)
- [DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)
- [TimeSpan](https://docs.microsoft.com/zh-cn/dotnet/api/system.timespan)
- [DateTimeOffset](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetimeoffset)
- 实现 `Object.ToString` 的任何类型。
- 实现 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的任何类型。

添加复杂内容时，可以将多种类型传递给此方法：

- [XObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobject)
- [XNode](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode)
- [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute)
- 实现 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的任何类型

如果对象实现 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1)，则枚举对象中的集合，并添加集合中的所有项。 如果集合包含 [XNode](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode) 或 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 对象，则单独添加集合中的每一项。 如果集合包含文本（或转换成文本的对象），则集合中的文本是串联在一起的，并作为单个文本节点添加。

如果内容为 `null`，则不添加任何内容。 传递集合时，集合中的项可以为 `null`。 集合中的 `null` 项对树没有任何影响。

添加的属性必须在其包含元素内具有唯一名称。

在添加 [XNode](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode) 或 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 对象时，如果新内容没有父级，则直接将这些对象附加到 XML 树中。 如果新内容已经有父级，并且是另一 XML 树的一部分，则克隆新内容，并将新克隆的内容附加到 XML 树。

##### 文档的有效内容

属性和简单内容无法添加到文档。

需要您创建 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 的情况不是很多。 而是通常使用 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 根节点创建 XML 树。 除非对创建文档有特定要求（例如，因为必须在顶级创建处理指令和注释，或者必须支持文档类型），否则使用 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 作为根节点通常更为方便。

文档的有效内容包括：

- 零个或一个 [XDocumentType](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocumenttype) 对象。 文档类型必须在元素之前。
- 零个或一个元素。
- 零个或多个注释。
- 零个或多个处理指令。
- 零个或多个仅包含空白的文本节点。

##### 允许添加内容的构造函数和函数

下面的方法允许您将子内容添加到 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 或 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 中：

| 方法                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.-ctor) | 构造一个 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)。 |
| [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument.-ctor) | 构造一个 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument)。 |
| [Add](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.add) | 添加到 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 或 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 的子内容的末尾。 |
| [AddAfterSelf](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.addafterself) | 在 [XNode](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode) 后面添加内容。 |
| [AddBeforeSelf](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.addbeforeself) | 在 [XNode](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode) 前面添加内容。 |
| [AddFirst](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.addfirst) | 在 [XContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer) 的子内容的开头添加内容。 |
| [ReplaceAll](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.replaceall) | 替换 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 的所有内容（子节点和属性）。 |
| [ReplaceAttributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.replaceattributes) | 替换 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 的属性。 |
| [ReplaceNodes](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.replacenodes) | 用新内容替换子节点。                                         |
| [ReplaceWith](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.replacewith) | 用新内容替换节点。|


