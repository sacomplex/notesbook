# [Working with XML Namespaces](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/workingwithxmlnamespaces)

本节中的主题描述 LINQ to XML 如何支持命名空间。

## 本节内容

| 主题                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [命名空间概述 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/namespaces-overview-linq-to-xml) | 本主题介绍命名空间、[XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 类和 [XNamespace](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnamespace) 类。 |
| [如何：创建包含命名空间的文档 (C#) (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-create-a-document-with-namespaces-linq-to-xml) | 演示如何创建包含命名空间的文档。                             |
| [如何：控制命名空间前缀 (C#) (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-control-namespace-prefixes-linq-to-xml) | 演示如何通过向 XML 树中插入命名空间属性来控制命名空间前缀。  |
| [C# 中默认命名空间的范围](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/scope-of-default-namespaces) | 演示为默认命名空间中的 XML 编写查询的适当方式。              |
| [如何：针对命名空间中的 XML 编写查询 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-write-queries-on-xml-in-namespaces) | 演示如何在 C# LINQ to XML 查询中指定 XML 命名空间。          |

## [Namespaces Overview (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/namespacesoverviewlinqtoxml)

本主题介绍命名空间、[XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 类和 [XNamespace](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnamespace) 类。

#### XML 名称

XML 名称常常是导致 XML 编程复杂性的原因。 XML 名称由 XML 命名空间（也称为 XML 命名空间 URI）和本地名称组成。 XML 命名空间类似于基于 .NET Framework 的程序中的命名空间。 它能够唯一限定元素和属性的名称。 这有助于避免 XML 文档各个部分之间的名称冲突。 声明 XML 命名空间后，可以选择只需在此命名空间内唯一的本地名称。

XML 名称的另一个方面是 XML 命名空间前缀。 XML 名称的复杂性大都是由 XML 前缀引起的。 这些前缀可用来创建 XML 命名空间的快捷方式，从而使 XML 文档更加简洁易懂。 但是，XML 前缀仅在其上下文中才有意义，这就增加了复杂性。 例如，XML 前缀 `aw` 可以与 XML 树的一部分中的一个 XML 命名空间关联，也可以与该 XML 树的另一部分中的另一个 XML 命名空间关联。

通过 C# 使用 LINQ to XML 的一个优点是您无须使用 XML 前缀。 当 LINQ to XML 加载或解析 XML 文档时，每个 XML 前缀都解析为它对应的 XML 命名空间。 之后，当您处理使用命名空间的文档时，您几乎总是通过命名空间 URI，而不是通过命名空间前缀来访问命名空间。 开发人员在 LINQ to XML 中使用 XML 名称时，他们始终使用完全限定的 XML 名称（即，XML 命名空间和本地名称）。 但是，如有必要，LINQ to XML 允许您使用和控制命名空间前缀。

在 LINQ to XML 中，表示 XML 名称的类为 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname)。 XML 名称在整个 LINQ to XML API 中频繁出现，任何时候只要需要 XML 名称，您就会发现 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 参数。 但是，很少会直接使用 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname)。 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 包含一个从字符串的隐式转换。

有关详细信息，请参阅 [XNamespace](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnamespace) 和 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname)。

## [How to: Create a Document with Namespaces (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtocreateadocumentwithnamespaceslinqtoxml)

本主题演示如何创建包含命名空间的文档。

##### 示例

若要创建一个属于命名空间的元素或属性，请首先声明和初始化一个 [XNamespace](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnamespace) 对象。 然后使用加法运算符重载来组合命名空间和本地名称（以字符串表示）。

下面的示例创建一个包含一个命名空间的文档。 默认情况下，LINQ to XML 使用默认命名空间序列化此文档。

```csharp
// Create an XML tree in a namespace.  
XNamespace aw = "http://www.adventure-works.com";  
XElement root = new XElement(aw + "Root",  
    new XElement(aw + "Child", "child content")  
);  
Console.WriteLine(root);  
```

该示例产生下面的输出：

```xml
<Root xmlns="http://www.adventure-works.com">  
  <Child>child content</Child>  
</Root>  
```

##### 示例

下面的示例创建一个包含一个命名空间的文档。 另外，还创建一个属性，该属性声明具有命名空间前缀的命名空间。 若要创建一个声明具有前缀的命名空间的属性，请创建一个属性，其中该属性的名称为命名空间前缀，并且此名称位于 [Xmlns](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnamespace.xmlns) 命名空间中。 此属性的值即是命名空间的 URI。

```csharp
// Create an XML tree in a namespace, with a specified prefix  
XNamespace aw = "http://www.adventure-works.com";  
XElement root = new XElement(aw + "Root",  
    new XAttribute(XNamespace.Xmlns + "aw", "http://www.adventure-works.com"),  
    new XElement(aw + "Child", "child content")  
);  
Console.WriteLine(root);  
```

该示例产生下面的输出：

```xml
<aw:Root xmlns:aw="http://www.adventure-works.com">  
  <aw:Child>child content</aw:Child>  
</aw:Root>  
```

##### 示例

下面的示例演示如何创建一个包含两个命名空间的文档。 一个是默认命名空间。 另一个是具有前缀的命名空间。

通过在根元素中包括命名空间属性，命名空间进行了序列化，从而 `http://www.adventure-works.com` 是默认命名空间，而 `www.fourthcoffee.com` 用“fc”前缀进行了序列化。 若要创建一个声明默认命名空间的属性，请创建一个名称为“xmlns”的属性，而无需命名空间。 该属性的值即是默认命名空间 URI。

```csharp
// The http://www.adventure-works.com namespace is forced to be the default namespace.  
XNamespace aw = "http://www.adventure-works.com";  
XNamespace fc = "www.fourthcoffee.com";  
XElement root = new XElement(aw + "Root",  
    new XAttribute("xmlns", "http://www.adventure-works.com"),  
    new XAttribute(XNamespace.Xmlns + "fc", "www.fourthcoffee.com"),  
    new XElement(fc + "Child",  
        new XElement(aw + "DifferentChild", "other content")  
    ),  
    new XElement(aw + "Child2", "c2 content"),  
    new XElement(fc + "Child3", "c3 content")  
);  
Console.WriteLine(root);  
```

该示例产生下面的输出：

```xml
<Root xmlns="http://www.adventure-works.com" xmlns:fc="www.fourthcoffee.com">  
  <fc:Child>  
    <DifferentChild>other content</DifferentChild>  
  </fc:Child>  
  <Child2>c2 content</Child2>  
  <fc:Child3>c3 content</fc:Child3>  
</Root>  
```

##### 示例

下面的示例创建一个包含两个命名空间的文档，这两个命名空间都具有命名空间前缀。

```csharp
XNamespace aw = "http://www.adventure-works.com";  
XNamespace fc = "www.fourthcoffee.com";  
XElement root = new XElement(aw + "Root",  
    new XAttribute(XNamespace.Xmlns + "aw", aw.NamespaceName),  
    new XAttribute(XNamespace.Xmlns + "fc", fc.NamespaceName),  
    new XElement(fc + "Child",  
        new XElement(aw + "DifferentChild", "other content")  
    ),  
    new XElement(aw + "Child2", "c2 content"),  
    new XElement(fc + "Child3", "c3 content")  
);  
Console.WriteLine(root);  
```

该示例产生下面的输出：

XML复制

```xml
<aw:Root xmlns:aw="http://www.adventure-works.com" xmlns:fc="www.fourthcoffee.com">  
  <fc:Child>  
    <aw:DifferentChild>other content</aw:DifferentChild>  
  </fc:Child>  
  <aw:Child2>c2 content</aw:Child2>  
  <fc:Child3>c3 content</fc:Child3>  
</aw:Root>  
```

##### 示例

另一种可获得相同结果的方法是使用扩展名，而不是声明和创建一个 [XNamespace](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnamespace) 对象。

这种方法的性能较低。 每次将包含扩展名的字符串传递给 LINQ to XML 时，LINQ to XML 都必须分析名称，查找原子化命名空间，再查找原子化名称。 这个过程会占用 CPU 时间。 如果性能很重要，则您可能希望显式声明和使用 [XNamespace](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnamespace) 对象。

如果性能是重要问题，请参阅 [XName 对象的预先原子化 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/pre-atomization-of-xname-objects-linq-to-xml) 了解详细信息

```csharp
// Create an XML tree in a namespace, with a specified prefix  
XElement root = new XElement("{http://www.adventure-works.com}Root",  
    new XAttribute(XNamespace.Xmlns + "aw", "http://www.adventure-works.com"),  
    new XElement("{http://www.adventure-works.com}Child", "child content")  
);  
Console.WriteLine(root);  
```

该示例产生下面的输出：

```xml
<aw:Root xmlns:aw="http://www.adventure-works.com">  
  <aw:Child>child content</aw:Child>  
</aw:Root>  
```

## [How to: Control Namespace Prefixes (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtocontrolnamespaceprefixeslinqtoxml)

本主题介绍在序列化 XML 树时如何控制命名空间前缀。

在很多情况下，不需要控制命名空间前缀。

但是，某些 XML 编程工具需要命名空间前缀的特定控制。 例如，您可能正在操作 XSLT 样式表或 XAML 文档，其中包含引用特定命名空间前缀的嵌入式 XPath 表达式，在这种情况下，一定要使用这些特定前缀对文档进行序列化。

这是控制命名空间前缀的最常见的原因。

需要控制命名空间前缀的另一个常见原因是：您希望用户手动编辑 XML 文档，而且您希望创建方便用户键入的命名空间前缀。 例如，您可能正在生成 XSD 文档。 架构约定建议您使用 `xs` 或 `xsd` 作为架构命名空间的前缀。

若要控制命名空间前缀，请插入声明命名空间的属性。 如果使用特定前缀声明命名空间，LINQ to XML 将在序列化时尝试接受此命名空间前缀。

若要创建一个声明具有前缀的命名空间的属性，请创建一个属性，该属性的名称的命名空间为 [Xmlns](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnamespace.xmlns)，该属性的名称为命名空间前缀。 该属性的值即是命名空间的 URI。

##### 示例

本示例声明两个命名空间。 它指定 `http://www.adventure-works.com` 命名空间具有 `aw` 前缀，`www.fourthcoffee.com` 命名空间具有 `fc` 前缀。

```csharp
XNamespace aw = "http://www.adventure-works.com";  
XNamespace fc = "www.fourthcoffee.com";  
XElement root = new XElement(aw + "Root",  
    new XAttribute(XNamespace.Xmlns + "aw", "http://www.adventure-works.com"),  
    new XAttribute(XNamespace.Xmlns + "fc", "www.fourthcoffee.com"),  
    new XElement(fc + "Child",  
        new XElement(aw + "DifferentChild", "other content")  
    ),  
    new XElement(aw + "Child2", "c2 content"),  
    new XElement(fc + "Child3", "c3 content")  
);  
Console.WriteLine(root);  
```

该示例产生下面的输出

```xml
<aw:Root xmlns:aw="http://www.adventure-works.com" xmlns:fc="www.fourthcoffee.com">  
  <fc:Child>  
    <aw:DifferentChild>other content</aw:DifferentChild>  
  </fc:Child>  
  <aw:Child2>c2 content</aw:Child2>  
  <fc:Child3>c3 content</fc:Child3>  
</aw:Root>  
```

## [Scope of Default Namespaces in C#](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/scopeofdefaultnamespaces)

XML 树中表示的默认命名空间不在查询范围内。 如果您的 XML 在默认命名空间内，仍须声明一个 [XNamespace](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnamespace)变量，并将该变量与本地名称组合在一起，生成一个限定名，在查询中使用。

查询 XML 树时遇到的一个最常见问题是，如果 XML 树具有默认命名空间，开发人员在编写查询时，有时会将 XML 视为不在命名空间内。

本主题的第一个示例集演示一种加载但是按不正确方式查询默认命名空间中的 XML 的典型方式。

第二个示例集演示必需的更正，以便可以查询命名空间中的 XML。

##### 示例

此示例演示如何在命名空间中创建 XML 和一个返回空结果集的查询。

```csharp
XElement root = XElement.Parse(  
@"<Root xmlns='http://www.adventure-works.com'>  
    <Child>1</Child>  
    <Child>2</Child>  
    <Child>3</Child>  
    <AnotherChild>4</AnotherChild>  
    <AnotherChild>5</AnotherChild>  
    <AnotherChild>6</AnotherChild>  
</Root>");  
IEnumerable<XElement> c1 =  
    from el in root.Elements("Child")  
    select el;  
Console.WriteLine("Result set follows:");  
foreach (XElement el in c1)  
    Console.WriteLine((int)el);  
Console.WriteLine("End of result set");  
```

此示例产生下面的结果：

```
Result set follows:  
End of result set  
```

##### 示例

本示例演示如何在命名空间中创建 XML 和一个正确编码的查询。

与上述不正确编码的示例相比，使用 C# 时的正确方法是声明和初始化一个 [XNamespace](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnamespace) 对象，并在指定 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname)对象时使用它。 在这种情况下，[Elements](https://msdn.microsoft.com/library/system.xml.linq.xelement.elements(v=vs.110).aspx) 方法的参数是一个 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 对象。

```csharp
XElement root = XElement.Parse(  
@"<Root xmlns='http://www.adventure-works.com'>  
    <Child>1</Child>  
    <Child>2</Child>  
    <Child>3</Child>  
    <AnotherChild>4</AnotherChild>  
    <AnotherChild>5</AnotherChild>  
    <AnotherChild>6</AnotherChild>  
</Root>");  
XNamespace aw = "http://www.adventure-works.com";  
IEnumerable<XElement> c1 =  
    from el in root.Elements(aw + "Child")  
    select el;  
Console.WriteLine("Result set follows:");  
foreach (XElement el in c1)  
    Console.WriteLine((int)el);  
Console.WriteLine("End of result set");  
```

此示例产生下面的结果：

```
Result set follows:  
1  
2  
3  
End of result set  
```

## [How to: Write Queries on XML in Namespaces](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtowritequeriesonxmlinnamespaces)

若要针对命名空间中的 XML 编写查询，必须使用具有正确命名空间的 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 对象。

对于 C#，最常用的方法是使用包含 URI 的字符串初始化 [XNamespace](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnamespace)，然后使用加法运算符重载来组合命名空间和本地名称。

本主题的第一个示例集演示如何在默认命名空间中创建一个 XML 树。 第二个示例集演示如何在带有前缀的命名空间中创建一个 XML 树。

##### 示例

下面的示例创建一个位于默认命名空间中的 XML 树。 然后检索元素的集合。

```csharp
XNamespace aw = "http://www.adventure-works.com";  
XElement root = XElement.Parse(  
@"<Root xmlns='http://www.adventure-works.com'>  
    <Child>1</Child>  
    <Child>2</Child>  
    <Child>3</Child>  
    <AnotherChild>4</AnotherChild>  
    <AnotherChild>5</AnotherChild>  
    <AnotherChild>6</AnotherChild>  
</Root>");  
IEnumerable<XElement> c1 =  
    from el in root.Elements(aw + "Child")  
    select el;  
foreach (XElement el in c1)  
    Console.WriteLine((int)el);  
```

该示例产生下面的输出：

```
1  
2  
3  
```

##### 示例

在 C# 中，无论是在使用带前缀的命名空间的 XML 树上编写查询，还是在使用默认命名空间的 XML 树上编写查询，都使用相同的方式。

下面的示例创建一个位于具有前缀的默认命名空间中的 XML 树。 然后检索元素的集合。

```csharp
XNamespace aw = "http://www.adventure-works.com";  
XElement root = XElement.Parse(  
@"<aw:Root xmlns:aw='http://www.adventure-works.com'>  
    <aw:Child>1</aw:Child>  
    <aw:Child>2</aw:Child>  
    <aw:Child>3</aw:Child>  
    <aw:AnotherChild>4</aw:AnotherChild>  
    <aw:AnotherChild>5</aw:AnotherChild>  
    <aw:AnotherChild>6</aw:AnotherChild>  
</aw:Root>");  
IEnumerable<XElement> c1 =  
    from el in root.Elements(aw + "Child")  
    select el;  
foreach (XElement el in c1)  
    Console.WriteLine((int)el);  
```

该示例产生下面的输出：

```
1  
2  
3  
```