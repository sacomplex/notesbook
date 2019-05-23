# [Performance (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/performancelinqtoxml)

本节提供有关 LINQ to XML 中的性能（尤其是函数构造和查询的性能）信息。

## 本节内容

[链接的查询的性能 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/performance-of-chained-queries-linq-to-xml)
提供有关链接 LINQ to XML 查询的性能信息。

[原子化的 XName 和 XNamespace 对象 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/atomized-xname-and-xnamespace-objects-linq-to-xml)
提供有关 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 和 [XNamespace](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnamespace) 对象的原子化的性能信息。

[XName 对象的预原子化 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/pre-atomization-of-xname-objects-linq-to-xml)
描述预原子化 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 和 [XNamespace](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnamespace) 对象的技术。 这可以极大提高某些方案中的性能。

[静态编译的查询 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/statically-compiled-queries-linq-to-xml)
提供有关静态编译查询（对比必须由 XPath 表达式计算器完成的分析和处理）的性能信息。

## [Performance of Chained Queries (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/performanceofchainedquerieslinqtoxml)

LINQ（以及 LINQ to XML）的一个最重要优点是，链接查询的执行性能与单个更大更复杂的查询一样好。

链接查询是一种将另一个查询作为其源的查询。 例如，在下面的简单代码中，`query2` 使用 `query1` 作为其源：

```csharp
XElement root = new XElement("Root",  
    new XElement("Child", 1),  
    new XElement("Child", 2),  
    new XElement("Child", 3),  
    new XElement("Child", 4)  
);  
  
var query1 = from x in root.Elements("Child")  
             where (int)x >= 3  
             select x;  
  
var query2 = from e in query1  
             where (int)e % 2 == 0  
             select e;  
  
foreach (var i in query2)  
    Console.WriteLine("{0}", (int)i);  
```

该示例产生下面的输出：

```
4  
```

此链接查询提供与循环访问链接列表相同的性能配置文件。

- [Elements](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.elements) 轴具有与循环访问链接列表基本相同的性能。 [Elements](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.elements) 作为具有延迟执行功能的迭代器实现。 这意味着它除了循环访问链接列表外还执行一些操作，例如分配迭代器对象和跟踪执行状态。 此项工作可以分为两类：设置迭代器时完成的工作和每次迭代过程中完成的工作。 设置工作是固定的少量工作，而每次迭代过程中完成的工作与源集合中的项数成正比。
- 在 `query1` 中，`where` 子句将使查询调用 [Where](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.where) 方法。 此方法也作为迭代器实现。 设置工作包括实例化将引用 lambda 表达式的委托和对迭代器的常规设置。 每次迭代时，都将调用该委托以执行谓词。 设置工作和每次迭代过程中完成的工作类似于循环访问轴期间完成的工作。
- 在 `query1` 中，select 子句将使查询调用 [Select](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.select) 方法。 此方法与 [Where](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.where) 方法具有相同的性能配置文件。
- `query2` 中的 `where` 子句和 `select` 子句与 `query1` 中的相应语句具有相同的性能配置文件。

因此，通过 `query2` 执行的迭代与第一个查询源中的项数（即，线形时间）成正比。 相应的 Visual Basic 示例将具有相同的性能配置文件。

有关迭代器的详细信息，请参阅 [yield](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/yield)。

有关将查询链接在一起的更详细教程，请参阅[教程：将查询链接在一起](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/tutorial-chaining-queries-together)。

## [Atomized XName and XNamespace Objects (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/atomizedxnameandxnamespaceobjectslinqtoxml)

[XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 和 [XNamespace](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnamespace) 对象进行了原子化；即，如果这两个对象包含相同的限定名，则它们将引用同一个对象。这将提高查询性能：当比较两个原子化名称是否相等时，基础中间语言只需确定这两个引用是否指向同一个对象。基础代码不必进行很耗费时间的字符串比较。

### 原子化语义

原子化是指如果两个 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 对象具有相同的本地名称并且位于同一个命名空间中，则它们共享相同的实例。 同样，如果两个 [XNamespace](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnamespace) 对象具有相同的命名空间 URI，则它们共享同一个实例。

对于启用原子化对象的类，该类的构造函数必须是私有的，而不是公共的。 这是因为如果构造函数是公共的，则您可以创建非原子化对象。 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 和 [XNamespace](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnamespace) 类实现一个隐式转换运算符，以将字符串转换为 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 或[XNamespace](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnamespace)。 这是获取这些对象的实例的方式。 不能通过使用构造函数来获得实例，因为构造函数是不可访问的。

[XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 和 [XNamespace](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnamespace) 还实现相等运算符和不相等运算符，以确定进行比较的两个对象是否引用相同的实例。

### 示例

下面的代码创建一些 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 对象，并演示相同的名称共享同一个实例。

```csharp
XElement r1 = new XElement("Root", "data1");  
XElement r2 = XElement.Parse("<Root>data2</Root>");  
  
if ((object)r1.Name == (object)r2.Name)  
    Console.WriteLine("r1 and r2 have names that refer to the same instance.");  
else  
    Console.WriteLine("Different");  
  
XName n = "Root";  
  
if ((object)n == (object)r1.Name)  
    Console.WriteLine("The name of r1 and the name in 'n' refer to the same instance.");  
else  
    Console.WriteLine("Different");  
```

该示例产生下面的输出：

```
r1 and r2 have names that refer to the same instance.  
The name of r1 and the name in 'n' refer to the same instance.  
```

如前面所述，原子化对象的好处是：当使用某个采用 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 作为参数的轴方法时，该轴方法只需确定这两个名称引用同一个实例来选择所需的元素。

下面的示例将 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 传递给 [Descendants](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.descendants) 方法调用，该调用会由于使用原子化模式而获得更好的性能。

```csharp
XElement root = new XElement("Root",  
    new XElement("C1", 1),  
    new XElement("Z1",  
        new XElement("C1", 2),  
        new XElement("C1", 1)  
    )  
);  
  
var query = from e in root.Descendants("C1")  
            where (int)e == 1  
            select e;  
  
foreach (var z in query)  
    Console.WriteLine(z);  
```

该示例产生下面的输出：

```xml
<C1>1</C1>  
<C1>1</C1>  
```

## [PreAtomization of XName Objects (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/preatomizationofxnameobjectslinqtoxml)

提高 LINQ to XML 中的性能的一种方法是预原子化 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 对象。 预原子化是指在通过使用 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 和 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)类的构造函数创建 XML 树之前，先将字符串分配给 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 对象。 然后传递初始化的 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 对象，而不是将字符串传递给构造函数（此过程将使用从字符串到 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 的隐式转换）。

当创建其中重复出现特定名称的大型 XML 树时，这样可以提高性能。 为此，请在构造 XML 树之前声明和初始化[XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 对象，然后使用 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 对象，而不是指定元素和属性名称的字符串。 当创建大量具有相同名称的元素（或属性）时，此技术可以显著提高性能。

应针对您的方案测试预原子化以确定是否应使用它。

### 示例

下面的示例演示这一操作。

```csharp
XName Root = "Root";  
XName Data = "Data";  
XName ID = "ID";  
  
XElement root = new XElement(Root,  
    new XElement(Data,  
        new XAttribute(ID, "1"),  
        "4,100,000"),  
    new XElement(Data,  
        new XAttribute(ID, "2"),  
        "3,700,000"),  
    new XElement(Data,  
        new XAttribute(ID, "3"),  
        "1,150,000")  
);  
  
Console.WriteLine(root);  
```

该示例产生下面的输出：

```xml
<Root>  
  <Data ID="1">4,100,000</Data>  
  <Data ID="2">3,700,000</Data>  
  <Data ID="3">1,150,000</Data>  
</Root>  
```

下面的示例演示针对命名空间中的 XML 文档的相同技术：

```csharp
XNamespace aw = "http://www.adventure-works.com";  
XName Root = aw + "Root";  
XName Data = aw + "Data";  
XName ID = "ID";  
  
XElement root = new XElement(Root,  
    new XAttribute(XNamespace.Xmlns + "aw", aw),  
    new XElement(Data,  
        new XAttribute(ID, "1"),  
        "4,100,000"),  
    new XElement(Data,  
        new XAttribute(ID, "2"),  
        "3,700,000"),  
    new XElement(Data,  
        new XAttribute(ID, "3"),  
        "1,150,000")  
);  
  
Console.WriteLine(root);  
```

该示例产生下面的输出：

```xml
<aw:Root xmlns:aw="http://www.adventure-works.com">  
  <aw:Data ID="1">4,100,000</aw:Data>  
  <aw:Data ID="2">3,700,000</aw:Data>  
  <aw:Data ID="3">1,150,000</aw:Data>  
</aw:Root>  
```

下面的示例更类似于实际中可能遇到的情况。 在此示例中，元素的内容由查询提供：

```csharp
XName Root = "Root";  
XName Data = "Data";  
XName ID = "ID";  
  
DateTime t1 = DateTime.Now;  
XElement root = new XElement(Root,  
    from i in System.Linq.Enumerable.Range(1, 100000)  
    select new XElement(Data,  
        new XAttribute(ID, i),  
        i * 5)  
);  
DateTime t2 = DateTime.Now;  
  
Console.WriteLine("Time to construct:{0}", t2 - t1);  
```

上一示例的执行性能优于下面的示例（其中未对名称进行预原子化）：

```csharp
DateTime t1 = DateTime.Now;  
XElement root = new XElement("Root",  
    from i in System.Linq.Enumerable.Range(1, 100000)  
    select new XElement("Data",  
        new XAttribute("ID", i),  
        i * 5)  
);  
DateTime t2 = DateTime.Now;  
  
Console.WriteLine("Time to construct:{0}", t2 - t1);  
```

## [Statically Compiled Queries (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/staticallycompiledquerieslinqtoxml)

LINQ to XML 的一个最重要的性能优势（与 [XmlDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmldocument) 相比）为：LINQ to XML 中的查询是静态编译的，而 XPath 查询则必须在运行时进行解释。 此功能是 LINQ to XML 的内置功能，因此您不必执行额外的步骤即可利用此功能，但在这两项技术之间做出选择时了解它们的区别将很有帮助。 本主题解释了其中的区别。

### 静态编译的查询与XPath

下面的示例演示如何获取具有指定名称并包含带有指定值的属性的子代元素。

以下是等效的 XPath 表达式：

```
//Address[@Type='Shipping']  
```

```csharp
XDocument po = XDocument.Load("PurchaseOrders.xml");  
  
IEnumerable<XElement> list1 =  
    from el in po.Descendants("Address")  
    where (string)el.Attribute("Type") == "Shipping"  
    select el;  
  
foreach (XElement el in list1)  
    Console.WriteLine(el);  
```

编译器将本示例中的查询表达式重新编写为基于方法的查询语法。 以下使用基于方法的查询语法编写的示例将生成与上一示例相同的结果：

```csharp
XDocument po = XDocument.Load("PurchaseOrders.xml");  
  
IEnumerable<XElement> list1 =  
    po  
    .Descendants("Address")  
    .Where(el => (string)el.Attribute("Type") == "Shipping");  
  
foreach (XElement el in list1)  
    Console.WriteLine(el);  
```

[Where](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.where) 方法为扩展方法。 有关详细信息，请参阅[扩展方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/extension-methods) 由于 [Where](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.where) 是一个扩展方法，因此会将上面的查询视为按以下形式编写的查询进行编译：

```csharp
XDocument po = XDocument.Load("PurchaseOrders.xml");  
  
IEnumerable<XElement> list1 =  
    System.Linq.Enumerable.Where(  
        po.Descendants("Address"),  
        el => (string)el.Attribute("Type") == "Shipping");  
  
foreach (XElement el in list1)  
    Console.WriteLine(el);  
```

此示例将生成与前面两个示例完全相同的结果。 这一结果表明：这些查询已被有效地编译成静态链接的方法调用。 这与迭代器的延迟执行语义一起可提高性能。 有关迭代器的延迟执行语义的详细信息，请参阅 [LINQ to XML 中的延迟执行和迟缓计算 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/deferred-execution-and-lazy-evaluation-in-linq-to-xml)。

> 这些示例代表了编译器可能编写的代码。 这些示例的实际实现可能会略有不同，但对于这些示例来说，执行的性能是相同或类似的。

### 使用 XmlDocument 执行 XPath 表达式

下面的示例使用 [XmlDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmldocument) 来完成与前面的示例相同的结果：

```csharp
XmlReader reader = XmlReader.Create("PurchaseOrders.xml");  
XmlDocument doc = new XmlDocument();  
doc.Load(reader);  
XmlNodeList nl = doc.SelectNodes(".//Address[@Type='Shipping']");  
foreach (XmlNode n in nl)  
    Console.WriteLine(n.OuterXml);  
reader.Close();  
```

此查询将返回与使用 LINQ to XML 的示例相同的输出；唯一的差别是：LINQ to XML 会缩进输出的 XML，而 [XmlDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmldocument) 不会。

但是，[XmlDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmldocument) 方法的执行性能通常不如 LINQ to XML，因为在每次调用 [SelectNodes](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlnode.selectnodes) 方法时，它都必须在内部执行以下操作：

- 分析包含 XPath 表达式的字符串，并将字符串划分成多个标记。
- 验证这些标记以确保 XPath 表达式有效。
- 将表达式转换为内部表达式树。
- 循环访问节点，为基于表达式计算的结果集选择适当的节点。

与相应的 LINQ to XML 查询完成的工作相比，这需要执行非常多的工作。 特定的性能差异将因不同的查询类型而异，但一般来说，与使用 [XmlDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmldocument) 计算 XPath 表达式相比，LINQ to XML 查询执行的工作较少，因此会获得更好的性能。