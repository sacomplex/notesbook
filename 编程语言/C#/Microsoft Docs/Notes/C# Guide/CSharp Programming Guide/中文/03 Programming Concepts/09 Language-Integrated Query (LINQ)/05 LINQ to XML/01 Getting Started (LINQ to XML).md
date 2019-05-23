# [Getting Started (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/gettingstartedlinqtoxml)

以下主题介绍 LINQ to XML。

## 本节内容

| 主题                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [LINQ to XML 概述 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/linq-to-xml-overview) | 提供 LINQ to XML 技术的概述。                                |
| [LINQ to XML 与DOM (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/linq-to-xml-vs-dom) | 将 LINQ to XML 与文档对象模型 (DOM) 进行比较。               |
| [LINQ to XML 与其他 XML 技术](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/linq-to-xml-vs-other-xml-technologies) | 将 LINQ to XML 与其他 XML 分析和操作技术进行比较：XmlReader、XSLT、MSXML 和 XmlLite。 |

## [LINQ to XML Overview](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/linqtoxmloverview)

在很多环境中，XML 已广泛采用为格式化数据的方式。 例如，在 Web 上，在配置文件、Microsoft Office Word 文件以及数据库中，都可以看到 XML。

LINQ to XML 经过了重新设计，是最新的 XML 编程方法。 它提供文档对象模型 (DOM) 的内存文档修改功能，支持 LINQ 查询表达式。 尽管这些查询表达式在语法上与 XPath 不同，但它们提供类似的功能。

### LINQ to XML 开发人员

LINQ to XML 是面向各种开发人员的。 对于只想完成某项工作的普通开发人员，LINQ to XML 通过提供与 SQL 相似的查询表达式，使 XML 变得更加简单。 只要稍加学习，程序员就能学会以自己选择的编程语言编写简洁、功能强大的查询。

专业开发人员可以使用 LINQ to XML 来大幅提高他们的工作效率。 通过使用 LINQ to XML，他们可以编写出表达能力更强、更为紧凑、功能更强的代码。 他们可以同时对多个数据域使用查询表达式。

### 什么是 LINQ to XML？

LINQ to XML 是一种启用了 LINQ 的内存 XML 编程接口，使用它，可以在 .NET Framework 编程语言中处理 XML。

LINQ to XML 将 XML 文档置于内存中，这一点很像文档对象模型 (DOM)。 您可以查询和修改 XML 文档，修改之后，可以将其另存为文件，也可以将其序列化然后通过 Internet 发送。 但是，LINQ to XML 与 DOM 不同：它提供一种新的对象模型，这是一种更轻量的模型，使用也更方便，这种模型利用了 C# 中的语言功能。

LINQ to XML 最重要的优势是它与 语言集成查询 (LINQ) 的集成。 由于实现了这一集成，因此，可以对内存 XML 文档编写查询，以检索元素和属性的集合。 LINQ to XML 的查询功能在功能上（尽管不是在语法上）与 XPath 和 XQuery 具有可比性。 C# 中的 LINQ 集成可提供更强的类型化功能、编译时检查和改进的调试器支持。

LINQ to XML 的另一个优势是通过将查询结果用作 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 和 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 对象构造函数的参数，实现了一种功能强大的创建 XML 树的方法。 此方法称为*功能构造*，可使开发人员轻松地将 XML 树从一个形状转换成另一个形状。

例如，可能有典型 XML 采购订单，如[示例 XML 文件：典型采购订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-typical-purchase-order-linq-to-xml-1) 中所述。 通过使用 LINQ to XML，可以运行以下查询，以获取采购单每个项元素的部件号属性值：

```csharp
// Load the XML file from our project directory containing the purchase orders
var filename = "PurchaseOrder.xml";
var currentDirectory = Directory.GetCurrentDirectory();
var purchaseOrderFilepath = Path.Combine(currentDirectory, filename);

XElement purchaseOrder = XElement.Load($"{purchaseOrderFilepath}");

IEnumerable<string> partNos =  from item in purchaseOrder.Descendants("Item")  
                               select (string) item.Attribute("PartNumber");  
```

这可以采用方法语法形式重写：

```csharp
IEnumerable<string> partNos = purchaseOrder.Descendants("Item").Select(x => (string) x.Attribute("PartNumber"));
```

另一个示例，您可能需要一个列表，列出值大于 100 美元的项，并根据部件号排序。 若要获取此信息，可以运行下面的查询：

```csharp
// Load the XML file from our project directory containing the purchase orders
var filename = "PurchaseOrder.xml";
var currentDirectory = Directory.GetCurrentDirectory();
var purchaseOrderFilepath = Path.Combine(currentDirectory, filename);

XElement purchaseOrder = XElement.Load($"{purchaseOrderFilepath}");

IEnumerable<XElement> pricesByPartNos =  from item in purchaseOrder.Descendants("Item")  
                                 where (int) item.Element("Quantity") * (decimal) item.Element("USPrice") > 100  
                                 orderby (string)item.Element("PartNumber")  
                                 select item;  
```

同样，这也可采用方法语法形式重写：

```csharp
IEnumerable<XElement> pricesByPartNos = purchaseOrder.Descendants("Item")
                                        .Where(item => (int)item.Element("Quantity") * (decimal)item.Element("USPrice") > 100)
                                        .OrderBy(order => order.Element("PartNumber"));
```

除了这些 LINQ 功能以外，LINQ to XML 提供了改进的 XML 编程接口。 使用 LINQ to XML，您可以：

- 从[文件](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-load-xml-from-a-file)或[流](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-stream-xml-fragments-from-an-xmlreader)加载 XML。
- 将 XML 序列化为文件或流。
- 使用函数构造从头开始创建 XML。
- 使用类似 XPath 的轴查询 XML。
- 使用 [Add](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.add)、[Remove](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.remove)、[ReplaceWith](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.replacewith) 和 [SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.setvalue) 等方法对内存 XML 树进行操作。
- 使用 XSD 验证 XML 树。
- 使用这些功能的组合，可将 XML 树从一种形状转换为另一种形状。

### 创建 XML 树

使用 LINQ to XML 编程的一个明显优势是易于创建 XML 树。 例如，若要创建一个小型 XML 树，可以编写以下代码：

```csharp
XElement contacts =  
new XElement("Contacts",  
    new XElement("Contact",  
        new XElement("Name", "Patrick Hines"),  
        new XElement("Phone", "206-555-0144",   
            new XAttribute("Type", "Home")),  
        new XElement("phone", "425-555-0145",  
            new XAttribute("Type", "Work")),  
        new XElement("Address",  
            new XElement("Street1", "123 Main St"),  
            new XElement("City", "Mercer Island"),  
            new XElement("State", "WA"),  
            new XElement("Postal", "68042")  
        )  
    )  
);  
```

有关详细信息，请参阅[创建 XML 树 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/creating-xml-trees)。

## [LINQ to XML vs. DOM](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/linqtoxmlvsdom)

本节说明 LINQ to XML 和当前主导 XML 编程 API（W3C 文档对象模型 (DOM)）之间的主要区别。

### 构造 XML 树的新方式

在 W3C DOM 中，应当从下至上生成 XML 树；即先创建文档，然后创建元素，再将元素添加到文档。

例如，下面是使用 DOM 的 Microsoft 实现 [XmlDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmldocument) 创建 XML 树的典型方式：

```csharp
XmlDocument doc = new XmlDocument();  
XmlElement name = doc.CreateElement("Name");  
name.InnerText = "Patrick Hines";  
XmlElement phone1 = doc.CreateElement("Phone");  
phone1.SetAttribute("Type", "Home");  
phone1.InnerText = "206-555-0144";          
XmlElement phone2 = doc.CreateElement("Phone");  
phone2.SetAttribute("Type", "Work");  
phone2.InnerText = "425-555-0145";          
XmlElement street1 = doc.CreateElement("Street1");          
street1.InnerText = "123 Main St";  
XmlElement city = doc.CreateElement("City");  
city.InnerText = "Mercer Island";  
XmlElement state = doc.CreateElement("State");  
state.InnerText = "WA";  
XmlElement postal = doc.CreateElement("Postal");  
postal.InnerText = "68042";  
XmlElement address = doc.CreateElement("Address");  
address.AppendChild(street1);  
address.AppendChild(city);  
address.AppendChild(state);  
address.AppendChild(postal);  
XmlElement contact = doc.CreateElement("Contact");  
contact.AppendChild(name);  
contact.AppendChild(phone1);  
contact.AppendChild(phone2);  
contact.AppendChild(address);  
XmlElement contacts = doc.CreateElement("Contacts");  
contacts.AppendChild(contact);  
doc.AppendChild(contacts);  
```

这种编码方式不会提供很多有关 XML 树结构的可视信息。 LINQ to XML 支持用此方法创建 XML 树，但也支持另一种方法，即函数构造。 函数构造使用 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 和 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 构造函数生成 XML 树。

下面演示如何通过使用 LINQ to XML 功能性构造法构造相同的 XML 树：

```csharp
XElement contacts =  
    new XElement("Contacts",  
        new XElement("Contact",  
            new XElement("Name", "Patrick Hines"),  
            new XElement("Phone", "206-555-0144",   
                new XAttribute("Type", "Home")),  
            new XElement("phone", "425-555-0145",  
                new XAttribute("Type", "Work")),  
            new XElement("Address",  
                new XElement("Street1", "123 Main St"),  
                new XElement("City", "Mercer Island"),  
                new XElement("State", "WA"),  
                new XElement("Postal", "68042")  
            )  
        )  
    );  
```

请注意，缩进用于构造 XML 树的代码可显示基础 XML 的结构。

有关详细信息，请参阅[创建 XML 树 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/creating-xml-trees)。

### 直接使用 XML 元素

在使用 XML 编程时，主要关注的通常是 XML 元素，也可能关注属性。 在 LINQ to XML 中，可以直接使用 XML 元素和属性。 例如，可以执行以下操作：

- 创建 XML 元素而根本不使用文档对象。 当必须使用 XML 树的片段时，这可简化编程。
- 直接从 XML 文件加载 `T:System.Xml.Linq.XElement` 对象。
- 将 `T:System.Xml.Linq.XElement` 对象序列化为文件或流。

比较而言，W3C DOM 中的 XML 文档用作 XML 树的逻辑容器。 在 DOM 中，必须在 XML 文档的上下文中创建 XML 节点，包括元素和属性。 下面是在 DOM 中创建一个 name 元素的代码片段：

```csharp
XmlDocument doc = new XmlDocument();  
XmlElement name = doc.CreateElement("Name");  
name.InnerText = "Patrick Hines";  
doc.AppendChild(name);  
```

如果要跨多个文档使用某个元素，则必须跨文档导入节点。 LINQ to XML 避免了这一复杂操作。

使用 LINQ to XML 时，仅在文档的根级别添加注释或处理说明时，才需使用 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 类。

### 名称和命名空间的简化处理

处理名称、命名空间和命名空间前缀通常是 XML 编程的复杂部分。 LINQ to XML 完全不需要处理命名空间前缀，从而简化了名称和命名空间。 可以轻松控制命名空间前缀。 但如果您决定不显式控制命名空间前缀，LINQ to XML 将会在序列化过程中分配命名空间前缀（如果需要）或使用默认命名空间进行序列化（如果不需要）。 如果使用默认命名空间，则生成的文档中将没有命名空间前缀。 有关详细信息，请参阅[使用 XML 命名空间 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/working-with-xml-namespaces)。

DOM 的另一个问题是它不允许您更改节点的名称。 您必须创建新节点并将所有子节点复制到此节点，从而会失去原始节点标识。 LINQ to XML 允许对节点设置 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 属性，因此可避免此问题。

### 对加载 XML 的静态方法支持

LINQ to XML 允许您通过使用静态方法而不是实例方法来加载 XML。 这简化了加载和分析。 有关详细信息，请参阅[如何：从文件加载 XML (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-load-xml-from-a-file)。

### 移除对 DTD 构造的支持

通过移除对实体和实体引用的支持，LINQ to XML 进一步简化了 XML 编程。 实体因管理复杂而很少使用。 移除对它们的支持可提高性能并简化编程接口。 在填充 LINQ to XML 树时，会展开所有 DTD 实体。

### 对片段的支持

LINQ to XML 未提供 `XmlDocumentFragment` 类的等效项。 但在很多情况下，`XmlDocumentFragment` 概念都可以通过执行类型化为[IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的 [XNode](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode) 或 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 的查询来进行处理。

### 对 XPathNavigator 的支持

LINQ to XML 通过 [XPathNavigator](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xpath.xpathnavigator) 命名空间中的扩展方法提供对 [System.Xml.XPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xpath) 的支持。 有关更多信息，请参见[System.Xml.XPath.Extensions](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xpath.extensions)。

### 对空白和缩进的支持

LINQ to XML 处理空白的方式比 DOM 更简单。

一种常用情况是读取缩进的 XML，在内存中创建一个没有任何空白文本节点（即不保留空白）的 XML 树，对该 XML 执行某些操作，然后保存带缩进的 XML。 在序列化带格式的 XML 时，只保留 XML 树中有意义的空白。 这是 LINQ to XML 的默认行为。

另一个常见的情况是读取和修改已经有意缩进的 XML。 您可能不想以任何方式更改这种缩进。 在 LINQ to XML中，可以通过在加载或解析 XML 时保留空白，并在序列化 XML 时禁用格式设置来实现此目的。

LINQ to XML 将空白存储为 [XText](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xtext) 节点，而不像 DOM 那样具有专门的 [Whitespace](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlnodetype#System_Xml_XmlNodeType_Whitespace) 节点类型。

### 对批注的支持

LINQ to XML 元素支持可扩展的批注集。 这对于跟踪有关元素的杂项信息（如架构信息、关于元素是否绑定到 UI 的信息或应用程序特定的任何其他信息）很有用。 有关详细信息，请参阅 [LINQ to XML 批注](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/linq-to-xml-annotations)。

### 对架构信息的支持

LINQ to XML 通过 [System.Xml.Schema](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.schema) 命名空间中的扩展方法提供对 XSD 验证的支持。 你可以验证 XML 树是否符合 XSD。 你可以用架构验证后信息集 (PSVI) 填充 XML 树。 有关详细信息，请参阅[如何：使用 XSD 进行验证](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-validate-using-xsd-linq-to-xml) 和 [Extensions](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.schema.extensions)。

## [LINQ to XML vs. Other XML Technologies](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/linqtoxmlvsotherxmltechnologies)

本主题将 LINQ to XML 与下面的 XML 技术进行比较：[XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader)、XSLT、MSXML 和 XmlLite。 了解这些信息，有助于确定要使用哪种技术。

有关比较 LINQ to XML 与文档对象模型 (DOM) 的信息，请参阅 [LINQ to XML 与DOM (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/linq-to-xml-vs-dom)。

### LINQ to XML 与XmlReader

[XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 是一种快速的只进非缓存分析器。

LINQ to XML 在 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 基础之上实现，它们紧密集成在一起。 但是，您也可以单独使用 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader)。

例如，假设要生成一项 Web 服务，该服务每秒将分析几百个 XML 文档，而这些文档具有相同的结构，因此，只需编写一种代码实现即可对 XML 进行分析。 在这种情况下，您可能希望单独使用 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader)。

相反，如果要生成一个系统，用以分析多种小型 XML 文档，而这些文档各不相同，则可能希望利用 LINQ to XML提高工作效率。

### LINQ to XML 与XSLT

LINQ to XML 和 XSLT 都提供丰富的 XML 文档转换功能。 XSLT 是基于规则的声明性方法。 XSLT 高级程序员以函数编程方式编写 XSLT，这种方式强调无状态方法。 可以使用实现后无副作用的纯函数编写转换。 许多开发人员还不熟悉这种基于规则的方法（即函数方法），需要付出努力和花费大量时间来学习这项技术。

XSLT 是非常高效的系统，可以生成高性能的应用程序。 例如，一些大型 Web 公司使用 XSLT 从 XML（提取自很多数据存储区）生成 HTML。 托管 XSLT 引擎将 XSLT 编译为 CLR 代码，在某些情况下，其性能甚至比本机 XSLT 引擎还要好。

但是，XSLT 没有利用许多开发人员都具备的 C# 和 Visual Basic 知识。 它要求开发人员用一种不同的复杂编程语言来编写代码。 如果使用两种非集成开发系统，例如 C#（或 Visual Basic）和 XSLT，软件系统的开发和维护会更加困难。

掌握 LINQ to XML 查询表达式之后，LINQ to XML转换就是一项功能强大、易于使用的技术。 本质上，XML 文档是这样形成的：使用函数构造，从各种源提取数据，动态构造 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 对象，再将全部内容组合到一个新 XML 树中。 经过这种转换，可以生成一个全新的文档。 相对来说，在 LINQ to XML 中构造转换比较容易、直观，编写出的代码可读性也较强。 这样可以减少开发和维护成本。

LINQ to XML 不是用来替代 XSLT 的。 对于复杂的以文档为中心的 XML 转换，XSLT 仍是很好的工具，如果文档结构的定义不完备，更是如此。

XSLT 的优势在于符合万维网联合会 (W3C) 标准。 如果要求只使用符合标准的技术，XSLT 可能更为合适。

XSLT 是 XML，因此可以以编程方式进行操作。

### LINQ to XML 与MSXML

MSXML 是基于 COM 的技术，用于处理 Microsoft Windows 提供的 XML。 MSXML 提供 DOM 的本机实现，并且支持 XPath 和 XSLT。 它还包含基于事件的 SAX2 非缓存分析器。

MSXML 性能良好，默认情况下，在大多数情况中都是安全的，在 Internet Explorer 中可以利用此功能来执行 AJAX 式应用程序中的客户端 XML 处理。 在任何支持 COM 的编程语言（包括 C++、JavaScript 和 Visual Basic 6.0）中，都可以使用 MSXML。

建议不要在基于公共语言运行库 (CLR) 的托管代码中使用 MSXML。

### LINQ to XML 与XmlLite

XmlLite 是一种只进非缓存提取型分析器。 开发人员主要将 XmlLite 用于 C++。 建议开发人员不要将 XmlLite 用于托管代码。

XmlLite 的主要优势在于它是快速的轻量 XML 分析器，在大多数方案中都是安全的。 它可能受到的威胁很少。 如果必须分析不受信任的文档，并且要预防受到拒绝服务或数据暴露等攻击，则 XmlLite 可能是很好的选择。

XmlLite 未与 语言集成查询 (LINQ) 集成。 它不会使程序员的工作效率得到提高，而工作效率提高正是 LINQ 背后的推动力量。