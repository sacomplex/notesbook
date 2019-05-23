# [Advanced Query Techniques (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/advancedquerytechniqueslinqtoxml)

本节提供更多高级 LINQ to XML 查询技术的示例。

## 本节内容

| 主题                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [如何：联接两个集合 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-join-two-collections-linq-to-xml) | 演示如何使用 `Join` 子句来利用 XML 数据中的关系。            |
| [如何：使用分组创建层次结构 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-create-hierarchy-using-grouping) | 演示如何将数据分组，再基于分组生成 XML。                     |
| [如何：使用 XPath 查询 LINQ to XML (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-query-linq-to-xml-using-xpath) | 演示如何基于 XPath 查询来检索集合。                          |
| [如何：编写 LINQ to XML 轴方法 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-write-a-linq-to-xml-axis-method) | 演示如何编写 LINQ to XML 轴方法。                            |
| [如何：执行文本到 XML 的流式转换 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-perform-streaming-transformations-of-text-to-xml) | 演示如何在保持很小的内存需求量的同时将非常大的文本文件转换为 XML。 |
| [如何：列出树中的所有节点 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-list-all-nodes-in-a-tree) | 演示一种用于列出 XML 树中所有节点的实用工具方法。 此方法可用于调试修改 XML 树的代码。 |
| [如何：从 Office Open XML 文档检索段落 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-retrieve-paragraphs-from-an-office-open-xml-document) | 演示打开 Office Open XML 文档；检索 XElement 对象集合中的段落、段落文本和段落样式的代码。 |
| [如何：修改 Office Open XML 文档 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-modify-an-office-open-xml-document) | 演示打开、修改和保存 Office Open XML 文档的代码。            |
| [如何：从文件系统填充 XML 树 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-populate-an-xml-tree-from-the-file-system) | 演示从文件系统创建 XML 树的代码。                            |

## [How to: Join Two Collections (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtojointwocollectionslinqtoxml)

XML 文档中的元素或属性有时可以引用另一个其他元素或属性。 例如，[示例 XML 文件：客户和订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-customers-and-orders-linq-to-xml-2) XML 文档包含客户列表和订单列表。 每个 `Customer` 元素都包含一个 `CustomerID` 属性。 每个 `Order` 元素都包含一个 `CustomerID` 元素。 每个订单中的 `CustomerID` 元素都引用客户中的 `CustomerID` 属性。

主题[示例 XSD 文件：客户和订单](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xsd-file-customers-and-orders1)包含可用于验证此文档的 XSD。 它使用 XSD 的 `xs:key` 和 `xs:keyref` 功能，将`CustomerID` 元素的 `Customer` 属性设置为键，并在每个 `CustomerID` 元素的 `Order` 元素和每个 `CustomerID` 元素的 `Customer` 属性之间建立关系。

使用 LINQ to XML，可以通过使用 `join` 子句利用这种关系。

请注意，由于没有可用的索引，这种联接的运行时性能较差。

有关 `join` 的详细信息，请参阅[联接操作 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/join-operations)。

- 示例

下面的示例将 `Customer` 元素与 `Order` 元素联接在一起，并生成一个新的 XML 文档，该文档包含订单中的 `CompanyName` 元素。

执行查询之前，示例确认文档符合[示例 XSD 文件：客户和订单](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xsd-file-customers-and-orders1)中的架构。 这样可确保联接子句始终能运行。

此查询首先检索所有 `Customer` 元素，然后将它们联接到 `Order` 元素。 此查询仅选择 `CustomerID` 大于“K”的客户的订单。 然后投影一个新的 `Order` 元素，该元素包含每个订单内的客户信息。

本示例使用下面的 XML 文档：[示例 XML 文件：客户和订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-customers-and-orders-linq-to-xml-2)。

本示例使用下面的 XSD 架构：[示例 XSD 文件：客户和订单](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xsd-file-customers-and-orders1)。

请注意，这种方式的联接将不能很好地执行。 联接是通过线性搜索执行的。 没有任何哈希表或索引来帮助改善性能。

```csharp
XmlSchemaSet schemas = new XmlSchemaSet();  
schemas.Add("", "CustomersOrders.xsd");  
  
Console.Write("Attempting to validate, ");  
XDocument custOrdDoc = XDocument.Load("CustomersOrders.xml");  
  
bool errors = false;  
custOrdDoc.Validate(schemas, (o, e) =>  
                     {  
                         Console.WriteLine("{0}", e.Message);  
                         errors = true;  
                     });  
Console.WriteLine("custOrdDoc {0}", errors ? "did not validate" : "validated");  
  
if (!errors)  
{  
    // Join customers and orders, and create a new XML document with  
    // a different shape.  
  
    // The new document contains orders only for customers with a  
    // CustomerID > 'K'  
    XElement custOrd = custOrdDoc.Element("Root");  
    XElement newCustOrd = new XElement("Root",  
        from c in custOrd.Element("Customers").Elements("Customer")  
        join o in custOrd.Element("Orders").Elements("Order")  
                   on (string)c.Attribute("CustomerID") equals  
                      (string)o.Element("CustomerID")  
        where ((string)c.Attribute("CustomerID")).CompareTo("K") > 0  
        select new XElement("Order",  
            new XElement("CustomerID", (string)c.Attribute("CustomerID")),  
            new XElement("CompanyName", (string)c.Element("CompanyName")),  
            new XElement("ContactName", (string)c.Element("ContactName")),  
            new XElement("EmployeeID", (string)o.Element("EmployeeID")),  
            new XElement("OrderDate", (DateTime)o.Element("OrderDate"))  
        )  
    );  
    Console.WriteLine(newCustOrd);  
}  
```

此代码生成以下输出：

```
Attempting to validate, custOrdDoc validated  
<Root>  
  <Order>  
    <CustomerID>LAZYK</CustomerID>  
    <CompanyName>Lazy K Kountry Store</CompanyName>  
    <ContactName>John Steel</ContactName>  
    <EmployeeID>1</EmployeeID>  
    <OrderDate>1997-03-21T00:00:00</OrderDate>  
  </Order>  
  <Order>  
    <CustomerID>LAZYK</CustomerID>  
    <CompanyName>Lazy K Kountry Store</CompanyName>  
    <ContactName>John Steel</ContactName>  
    <EmployeeID>8</EmployeeID>  
    <OrderDate>1997-05-22T00:00:00</OrderDate>  
  </Order>  
  <Order>  
    <CustomerID>LETSS</CustomerID>  
    <CompanyName>Let's Stop N Shop</CompanyName>  
    <ContactName>Jaime Yorres</ContactName>  
    <EmployeeID>1</EmployeeID>  
    <OrderDate>1997-06-25T00:00:00</OrderDate>  
  </Order>  
  <Order>  
    <CustomerID>LETSS</CustomerID>  
    <CompanyName>Let's Stop N Shop</CompanyName>  
    <ContactName>Jaime Yorres</ContactName>  
    <EmployeeID>8</EmployeeID>  
    <OrderDate>1997-10-27T00:00:00</OrderDate>  
  </Order>  
  <Order>  
    <CustomerID>LETSS</CustomerID>  
    <CompanyName>Let's Stop N Shop</CompanyName>  
    <ContactName>Jaime Yorres</ContactName>  
    <EmployeeID>6</EmployeeID>  
    <OrderDate>1997-11-10T00:00:00</OrderDate>  
  </Order>  
  <Order>  
    <CustomerID>LETSS</CustomerID>  
    <CompanyName>Let's Stop N Shop</CompanyName>  
    <ContactName>Jaime Yorres</ContactName>  
    <EmployeeID>4</EmployeeID>  
    <OrderDate>1998-02-12T00:00:00</OrderDate>  
  </Order>  
</Root>  
```

## [How to: Create Hierarchy Using Grouping](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtocreatehierarchyusinggrouping)

本示例演示如何将数据分组，再基于分组生成 XML。

- 示例

本示例首先按类别对数据分组，再生成新的 XML 文件，其中的 XML 层次结构反映了分组。

本示例使用下面的 XML 文档：[示例 XML 文件：数值数据 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-numerical-data-linq-to-xml)。

```csharp
XElement doc = XElement.Load("Data.xml");  
var newData =  
    new XElement("Root",  
        from data in doc.Elements("Data")  
        group data by (string)data.Element("Category") into groupedData  
        select new XElement("Group",  
            new XAttribute("ID", groupedData.Key),  
            from g in groupedData  
            select new XElement("Data",  
                g.Element("Quantity"),  
                g.Element("Price")  
            )  
        )  
    );  
Console.WriteLine(newData);  
```

该示例产生下面的输出：

```xml
<Root>  
  <Group ID="A">  
    <Data>  
      <Quantity>3</Quantity>  
      <Price>24.50</Price>  
    </Data>  
    <Data>  
      <Quantity>5</Quantity>  
      <Price>4.95</Price>  
    </Data>  
    <Data>  
      <Quantity>3</Quantity>  
      <Price>66.00</Price>  
    </Data>  
    <Data>  
      <Quantity>15</Quantity>  
      <Price>29.00</Price>  
    </Data>  
  </Group>  
  <Group ID="B">  
    <Data>  
      <Quantity>1</Quantity>  
      <Price>89.99</Price>  
    </Data>  
    <Data>  
      <Quantity>10</Quantity>  
      <Price>.99</Price>  
    </Data>  
    <Data>  
      <Quantity>8</Quantity>  
      <Price>6.99</Price>  
    </Data>  
  </Group>  
</Root>  
```

## [How to: Query LINQ to XML Using XPath](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoquerylinqtoxmlusingxpath)

本主题介绍一些扩展方法，通过这些扩展方法可以使用 XPath 查询 XML 树。 有关使用这些扩展方法的详细信息，请参见 [System.Xml.XPath.Extensions](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xpath.extensions)。

除非有很特别的理由（例如大量使用旧代码）需要使用 XPath 进行查询，否则不建议将 XPath 用于 LINQ to XML。 XPath 查询的执行性能比 LINQ to XML 查询低。

- 示例

下面的示例创建一个小型 XML 树，并使用 [XPathSelectElements](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xpath.extensions.xpathselectelements) 选择一组元素。

```csharp
XElement root = new XElement("Root",  
    new XElement("Child1", 1),  
    new XElement("Child1", 2),  
    new XElement("Child1", 3),  
    new XElement("Child2", 4),  
    new XElement("Child2", 5),  
    new XElement("Child2", 6)  
);  
IEnumerable<XElement> list = root.XPathSelectElements("./Child2");  
foreach (XElement el in list)  
    Console.WriteLine(el);  
```

该示例产生下面的输出：

```xml
<Child2>4</Child2>  
<Child2>5</Child2>  
<Child2>6</Child2>  
```

## [How to: Write a LINQ to XML Axis Method](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtowritealinqtoxmlaxismethod)

你可以编写自己的轴方法以便从 XML 树中检索集合。 执行此操作的最佳方式之一是编写可返回元素或属性集合的扩展方法。 您可以基于应用程序的需求编写扩展方法以返回元素或属性的特定子集。

- 示例

下面的示例使用两个扩展方法。 第一个扩展方法 `GetXPath` 在 [XObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobject) 上操作并返回一个 XPath 表达式，在计算该表达式时，将返回节点或属性。 第二个扩展方法 `Find` 在 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 上操作。 它返回 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 对象和包含某些指定文本的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 对象的集合。

本示例使用下面的 XML 文档：[示例 XML 文件：多个采购订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-multiple-purchase-orders-linq-to-xml)。

```csharp
public static class MyExtensions  
{  
    private static string GetQName(XElement xe)  
    {  
        string prefix = xe.GetPrefixOfNamespace(xe.Name.Namespace);  
        if (xe.Name.Namespace == XNamespace.None || prefix == null)  
            return xe.Name.LocalName.ToString();  
        else  
            return prefix + ":" + xe.Name.LocalName.ToString();  
    }  
  
    private static string GetQName(XAttribute xa)  
    {  
        string prefix =  
            xa.Parent.GetPrefixOfNamespace(xa.Name.Namespace);  
        if (xa.Name.Namespace == XNamespace.None || prefix == null)  
            return xa.Name.ToString();  
        else  
            return prefix + ":" + xa.Name.LocalName;  
    }  
  
    private static string NameWithPredicate(XElement el)  
    {  
        if (el.Parent != null && el.Parent.Elements(el.Name).Count() != 1)  
            return GetQName(el) + "[" +   
                (el.ElementsBeforeSelf(el.Name).Count() + 1) + "]";  
        else  
            return GetQName(el);  
    }  
  
    public static string StrCat<T>(this IEnumerable<T> source,  
        string separator)  
    {  
        return source.Aggregate(new StringBuilder(),  
                   (sb, i) => sb  
                       .Append(i.ToString())  
                       .Append(separator),  
                   s => s.ToString());  
    }  
  
    public static string GetXPath(this XObject xobj)  
    {  
        if (xobj.Parent == null)  
        {  
            XDocument doc = xobj as XDocument;  
            if (doc != null)  
                return ".";  
            XElement el = xobj as XElement;  
            if (el != null)  
                return "/" + NameWithPredicate(el);  
            // the XPath data model does not include white space text nodes  
            // that are children of a document, so this method returns null.  
            XText xt = xobj as XText;  
            if (xt != null)  
                return null;  
            XComment com = xobj as XComment;  
            if (com != null)  
                return  
                    "/" +  
                    (  
                        com  
                        .Document  
                        .Nodes()  
                        .OfType<XComment>()  
                        .Count() != 1 ?  
                        "comment()[" +  
                        (com  
                        .NodesBeforeSelf()  
                        .OfType<XComment>()  
                        .Count() + 1) +  
                        "]" :  
                        "comment()"  
                    );  
            XProcessingInstruction pi = xobj as XProcessingInstruction;  
            if (pi != null)  
                return  
                    "/" +  
                    (  
                        pi.Document.Nodes()  
                        .OfType<XProcessingInstruction>()  
                        .Count() != 1 ?  
                        "processing-instruction()[" +  
                        (pi  
                        .NodesBeforeSelf()  
                        .OfType<XProcessingInstruction>()  
                        .Count() + 1) +  
                        "]" :  
                        "processing-instruction()"  
                    );  
            return null;  
        }  
        else  
        {  
            XElement el = xobj as XElement;  
            if (el != null)  
            {  
                return  
                    "/" +  
                    el  
                    .Ancestors()  
                    .InDocumentOrder()  
                    .Select(e => NameWithPredicate(e))  
                    .StrCat("/") +  
                    NameWithPredicate(el);  
            }  
            XAttribute at = xobj as XAttribute;  
            if (at != null)  
                return  
                    "/" +  
                    at  
                    .Parent  
                    .AncestorsAndSelf()  
                    .InDocumentOrder()  
                    .Select(e => NameWithPredicate(e))  
                    .StrCat("/") +  
                    "@" + GetQName(at);  
            XComment com = xobj as XComment;  
            if (com != null)  
                return  
                    "/" +  
                    com  
                    .Parent  
                    .AncestorsAndSelf()  
                    .InDocumentOrder()  
                    .Select(e => NameWithPredicate(e))  
                    .StrCat("/") +  
                    (  
                        com  
                        .Parent  
                        .Nodes()  
                        .OfType<XComment>()  
                        .Count() != 1 ?  
                        "comment()[" +  
                        (com  
                        .NodesBeforeSelf()  
                        .OfType<XComment>()  
                        .Count() + 1) + "]" :  
                        "comment()"  
                    );  
            XCData cd = xobj as XCData;  
            if (cd != null)  
                return  
                    "/" +  
                    cd  
                    .Parent  
                    .AncestorsAndSelf()  
                    .InDocumentOrder()  
                    .Select(e => NameWithPredicate(e))  
                    .StrCat("/") +  
                    (  
                        cd  
                        .Parent  
                        .Nodes()  
                        .OfType<XText>()  
                        .Count() != 1 ?  
                        "text()[" +  
                        (cd  
                        .NodesBeforeSelf()  
                        .OfType<XText>()  
                        .Count() + 1) + "]" :  
                        "text()"  
                    );  
            XText tx = xobj as XText;  
            if (tx != null)  
                return  
                    "/" +  
                    tx  
                    .Parent  
                    .AncestorsAndSelf()  
                    .InDocumentOrder()  
                    .Select(e => NameWithPredicate(e))  
                    .StrCat("/") +  
                    (  
                        tx  
                        .Parent  
                        .Nodes()  
                        .OfType<XText>()  
                        .Count() != 1 ?  
                        "text()[" +  
                        (tx  
                        .NodesBeforeSelf()  
                        .OfType<XText>()  
                        .Count() + 1) + "]" :  
                        "text()"  
                    );  
            XProcessingInstruction pi = xobj as XProcessingInstruction;  
            if (pi != null)  
                return  
                    "/" +  
                    pi  
                    .Parent  
                    .AncestorsAndSelf()  
                    .InDocumentOrder()  
                    .Select(e => NameWithPredicate(e))  
                    .StrCat("/") +  
                    (  
                        pi  
                        .Parent  
                        .Nodes()  
                        .OfType<XProcessingInstruction>()  
                        .Count() != 1 ?  
                        "processing-instruction()[" +  
                        (pi  
                        .NodesBeforeSelf()  
                        .OfType<XProcessingInstruction>()  
                        .Count() + 1) + "]" :  
                        "processing-instruction()"  
                    );  
            return null;  
        }  
    }  
  
    public static IEnumerable<XObject> Find(this XElement source, string value)  
    {  
        if (source.Attributes().Any())  
        {  
            foreach (XAttribute att in source.Attributes())  
            {  
                string contents = (string)att;  
                if (contents.Contains(value))  
                    yield return att;  
            }  
        }  
        if (source.Elements().Any())  
        {  
            foreach (XElement child in source.Elements())  
                foreach (XObject s in child.Find(value))  
                    yield return s;  
        }  
        else  
        {  
            string contents = (string)source;  
            if (contents.Contains(value))  
                yield return source;  
        }  
    }  
}  
  
class Program  
{  
    static void Main(string[] args)  
    {  
        XElement purchaseOrders = XElement.Load("PurchaseOrders.xml");  
  
        IEnumerable<XObject> subset =  
            from xobj in purchaseOrders.Find("1999")  
            select xobj;  
  
        foreach (XObject obj in subset)  
        {  
            Console.WriteLine(obj.GetXPath());  
            if (obj.GetType() == typeof(XElement))  
                Console.WriteLine(((XElement)obj).Value);  
            else if (obj.GetType() == typeof(XAttribute))  
                Console.WriteLine(((XAttribute)obj).Value);  
        }  
    }  
}  
```

此代码生成以下输出：

```
/PurchaseOrders/PurchaseOrder[1]/@OrderDate  
1999-10-20  
/PurchaseOrders/PurchaseOrder[1]/Items/Item[2]/ShipDate  
1999-05-21  
/PurchaseOrders/PurchaseOrder[2]/@OrderDate  
1999-10-22  
/PurchaseOrders/PurchaseOrder[3]/@OrderDate  
1999-10-22  
```

## [How to: Perform Streaming Transformations of Text to XML](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoperformstreamingtransformationsoftexttoxml)

处理文本文件的一种方法是编写使用 `yield return` 构造一次流式处理一行文本文件的扩展方法。 然后可以编写以迟缓延迟方式处理文本文件的 LINQ 查询。 如果之后使用 [XStreamingElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xstreamingelement) 对输出进行流式处理，则可以创建占用最少量内存的从文本文件到 XML 的转换，而不管源文本文件大小如何。

关于流式转换存在一些告诫。 流式转换最适用于可以一次性处理整个文件并且可以按照源文档中的行顺序处理各行的情况。 如果必须多次处理文件或者必须在处理行之前对行进行排序，则将失去使用流式技术所具有的许多好处。

- 示例

下面的文本文件 People.txt 是本示例的源文件。

```
#This is a comment  
1,Tai,Yee,Writer  
2,Nikolay,Grachev,Programmer  
3,David,Wright,Inventor  
```

下面的代码包含以延迟方式流式处理文本文件中各行的扩展方法。

```csharp
public static class StreamReaderSequence  
{  
    public static IEnumerable<string> Lines(this StreamReader source)  
    {  
        String line;  
  
        if (source == null)  
            throw new ArgumentNullException("source");  
        while ((line = source.ReadLine()) != null)  
        {  
            yield return line;  
        }  
    }  
}  
  
class Program  
{  
    static void Main(string[] args)  
    {  
        StreamReader sr = new StreamReader("People.txt");  
        XStreamingElement xmlTree = new XStreamingElement("Root",  
            from line in sr.Lines()  
            let items = line.Split(',')  
            where !line.StartsWith("#")  
            select new XElement("Person",  
                       new XAttribute("ID", items[0]),  
                       new XElement("First", items[1]),  
                       new XElement("Last", items[2]),  
                       new XElement("Occupation", items[3])  
                   )  
        );  
        Console.WriteLine(xmlTree);  
        sr.Close();  
    }  
}  
```

该示例产生下面的输出：

```xml
<Root>  
  <Person ID="1">  
    <First>Tai</First>  
    <Last>Yee</Last>  
    <Occupation>Writer</Occupation>  
  </Person>  
  <Person ID="2">  
    <First>Nikolay</First>  
    <Last>Grachev</Last>  
    <Occupation>Programmer</Occupation>  
  </Person>  
  <Person ID="3">  
    <First>David</First>  
    <Last>Wright</Last>  
    <Occupation>Inventor</Occupation>  
  </Person>  
</Root>  
```

## [How to: List All Nodes in a Tree](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtolistallnodesinatree)

有时，列出树中的所有节点会有帮助。 它可帮助准确了解方法或属性是如何影响树的。 以文本形式列出所有节点的一种方法是生成准确逐一地标识树中所有节点的 XPath 表达式。

使用 LINQ to XML 执行 XPath 表达式不特别有用。 XPath 表达式的性能不如 LINQ to XML 查询，并且 LINQ to XML 查询的功能更强大。 但作为标识 XML 树中节点的一种方式，XPath 可以有效地工作。

- 示例

本示例演示一个名为 `GetXPath` 的函数，该函数为 XML 树中的每个节点生成一个特定的 XPath 表达式。 即使节点位于命名空间中，此示例也可生成相应的 XPath 表达式。 这些 XPath 表达式通过使用命名空间前缀生成。

然后，示例创建一个包含若干类型节点示例的小型 XML 树。 然后循环访问后代节点并打印每个节点的 XPath 表达式。

您会注意到，XML 声明不是树中的节点。

下面是一个包含若干类型节点的 XML 文件：

```xml
<?xml version="1.0" encoding="utf-8" standalone="yes"?>  
<?target data?>  
<Root AttName="An Attribute" xmlns:aw="http://www.adventure-works.com">  
  <!--This is a comment-->  
  <Child>Text</Child>  
  <Child>Other Text</Child>  
  <ChildWithMixedContent>text<b>BoldText</b>otherText</ChildWithMixedContent>  
  <aw:ElementInNamespace>  
    <aw:ChildInNamespace />  
  </aw:ElementInNamespace>  
</Root>  
```

下面是上述 XML 树中节点的列表，以 XPath 表达式表示：

```
/processing-instruction()  
/Root  
/Root/@AttName  
/Root/@xmlns:aw  
/Root/comment()  
/Root/Child[1]  
/Root/Child[1]/text()  
/Root/Child[2]  
/Root/Child[2]/text()  
/Root/ChildWithMixedContent  
/Root/ChildWithMixedContent/text()[1]  
/Root/ChildWithMixedContent/b  
/Root/ChildWithMixedContent/b/text()  
/Root/ChildWithMixedContent/text()[2]  
/Root/aw:ElementInNamespace  
/Root/aw:ElementInNamespace/aw:ChildInNamespace  
```

```csharp
public static class MyExtensions  
{  
    private static string GetQName(XElement xe)  
    {  
        string prefix = xe.GetPrefixOfNamespace(xe.Name.Namespace);  
        if (xe.Name.Namespace == XNamespace.None || prefix == null)  
            return xe.Name.LocalName.ToString();  
        else  
            return prefix + ":" + xe.Name.LocalName.ToString();  
    }  
  
    private static string GetQName(XAttribute xa)  
    {  
        string prefix =  
            xa.Parent.GetPrefixOfNamespace(xa.Name.Namespace);  
        if (xa.Name.Namespace == XNamespace.None || prefix == null)  
            return xa.Name.ToString();  
        else  
            return prefix + ":" + xa.Name.LocalName;  
    }  
  
    private static string NameWithPredicate(XElement el)  
    {  
        if (el.Parent != null && el.Parent.Elements(el.Name).Count() != 1)  
            return GetQName(el) + "[" +  
                (el.ElementsBeforeSelf(el.Name).Count() + 1) + "]";  
        else  
            return GetQName(el);  
    }  
  
    public static string StrCat<T>(this IEnumerable<T> source,  
        string separator)  
    {  
        return source.Aggregate(new StringBuilder(),  
                   (sb, i) => sb  
                       .Append(i.ToString())  
                       .Append(separator),  
                   s => s.ToString());  
    }  
  
    public static string GetXPath(this XObject xobj)  
    {  
        if (xobj.Parent == null)  
        {  
            XDocument doc = xobj as XDocument;  
            if (doc != null)  
                return ".";  
            XElement el = xobj as XElement;  
            if (el != null)  
                return "/" + NameWithPredicate(el);  
            // the XPath data model does not include white space text nodes  
            // that are children of a document, so this method returns null.  
            XText xt = xobj as XText;  
            if (xt != null)  
                return null;  
            XComment com = xobj as XComment;  
            if (com != null)  
                return  
                    "/" +  
                    (  
                        com  
                        .Document  
                        .Nodes()  
                        .OfType<XComment>()  
                        .Count() != 1 ?  
                        "comment()[" +  
                        (com  
                        .NodesBeforeSelf()  
                        .OfType<XComment>()  
                        .Count() + 1) +  
                        "]" :  
                        "comment()"  
                    );  
            XProcessingInstruction pi = xobj as XProcessingInstruction;  
            if (pi != null)  
                return  
                    "/" +  
                    (  
                        pi.Document.Nodes()  
                        .OfType<XProcessingInstruction>()  
                        .Count() != 1 ?  
                        "processing-instruction()[" +  
                        (pi  
                        .NodesBeforeSelf()  
                        .OfType<XProcessingInstruction>()  
                        .Count() + 1) +  
                        "]" :  
                        "processing-instruction()"  
                    );  
            return null;  
        }  
        else  
        {  
            XElement el = xobj as XElement;  
            if (el != null)  
            {  
                return  
                    "/" +  
                    el  
                    .Ancestors()  
                    .InDocumentOrder()  
                    .Select(e => NameWithPredicate(e))  
                    .StrCat("/") +  
                    NameWithPredicate(el);  
            }  
            XAttribute at = xobj as XAttribute;  
            if (at != null)  
                return  
                    "/" +  
                    at  
                    .Parent  
                    .AncestorsAndSelf()  
                    .InDocumentOrder()  
                    .Select(e => NameWithPredicate(e))  
                    .StrCat("/") +  
                    "@" + GetQName(at);  
            XComment com = xobj as XComment;  
            if (com != null)  
                return  
                    "/" +  
                    com  
                    .Parent  
                    .AncestorsAndSelf()  
                    .InDocumentOrder()  
                    .Select(e => NameWithPredicate(e))  
                    .StrCat("/") +  
                    (  
                        com  
                        .Parent  
                        .Nodes()  
                        .OfType<XComment>()  
                        .Count() != 1 ?  
                        "comment()[" +  
                        (com  
                        .NodesBeforeSelf()  
                        .OfType<XComment>()  
                        .Count() + 1) + "]" :  
                        "comment()"  
                    );  
            XCData cd = xobj as XCData;  
            if (cd != null)  
                return  
                    "/" +  
                    cd  
                    .Parent  
                    .AncestorsAndSelf()  
                    .InDocumentOrder()  
                    .Select(e => NameWithPredicate(e))  
                    .StrCat("/") +  
                    (  
                        cd  
                        .Parent  
                        .Nodes()  
                        .OfType<XText>()  
                        .Count() != 1 ?  
                        "text()[" +  
                        (cd  
                        .NodesBeforeSelf()  
                        .OfType<XText>()  
                        .Count() + 1) + "]" :  
                        "text()"  
                    );  
            XText tx = xobj as XText;  
            if (tx != null)  
                return  
                    "/" +  
                    tx  
                    .Parent  
                    .AncestorsAndSelf()  
                    .InDocumentOrder()  
                    .Select(e => NameWithPredicate(e))  
                    .StrCat("/") +  
                    (  
                        tx  
                        .Parent  
                        .Nodes()  
                        .OfType<XText>()  
                        .Count() != 1 ?  
                        "text()[" +  
                        (tx  
                        .NodesBeforeSelf()  
                        .OfType<XText>()  
                        .Count() + 1) + "]" :  
                        "text()"  
                    );  
            XProcessingInstruction pi = xobj as XProcessingInstruction;  
            if (pi != null)  
                return  
                    "/" +  
                    pi  
                    .Parent  
                    .AncestorsAndSelf()  
                    .InDocumentOrder()  
                    .Select(e => NameWithPredicate(e))  
                    .StrCat("/") +  
                    (  
                        pi  
                        .Parent  
                        .Nodes()  
                        .OfType<XProcessingInstruction>()  
                        .Count() != 1 ?  
                        "processing-instruction()[" +  
                        (pi  
                        .NodesBeforeSelf()  
                        .OfType<XProcessingInstruction>()  
                        .Count() + 1) + "]" :  
                        "processing-instruction()"  
                    );  
            return null;  
        }  
    }  
}  
  
class Program  
{  
    static void Main(string[] args)  
    {  
        XNamespace aw = "http://www.adventure-works.com";  
        XDocument doc = new XDocument(  
            new XDeclaration("1.0", "utf-8", "yes"),  
            new XProcessingInstruction("target", "data"),  
            new XElement("Root",  
                new XAttribute("AttName", "An Attribute"),  
                new XAttribute(XNamespace.Xmlns + "aw", aw.ToString()),  
                new XComment("This is a comment"),  
                new XElement("Child",  
                    new XText("Text")  
                ),  
                new XElement("Child",  
                    new XText("Other Text")  
                ),  
                new XElement("ChildWithMixedContent",  
                    new XText("text"),  
                    new XElement("b", "BoldText"),  
                    new XText("otherText")  
                ),  
                new XElement(aw + "ElementInNamespace",  
                    new XElement(aw + "ChildInNamespace")  
                )  
            )  
        );  
        doc.Save("Test.xml");  
        Console.WriteLine(File.ReadAllText("Test.xml"));  
        Console.WriteLine("------");  
        foreach (XObject obj in doc.DescendantNodes())  
        {  
            Console.WriteLine(obj.GetXPath());  
            XElement el = obj as XElement;  
            if (el != null)  
                foreach (XAttribute at in el.Attributes())  
                    Console.WriteLine(at.GetXPath());  
        }  
    }  
}  
```

该示例产生下面的输出：

```
<?xml version="1.0" encoding="utf-8" standalone="yes"?>  
<?target data?>  
<Root AttName="An Attribute" xmlns:aw="http://www.adventure-works.com">  
  <!--This is a comment-->  
  <Child>Text</Child>  
  <Child>Other Text</Child>  
  <ChildWithMixedContent>text<b>BoldText</b>otherText</ChildWithMixedContent>  
  <aw:ElementInNamespace>  
    <aw:ChildInNamespace />  
  </aw:ElementInNamespace>  
</Root>  
------  
/processing-instruction()  
/Root  
/Root/@AttName  
/Root/@xmlns:aw  
/Root/comment()  
/Root/Child[1]  
/Root/Child[1]/text()  
/Root/Child[2]  
/Root/Child[2]/text()  
/Root/ChildWithMixedContent  
/Root/ChildWithMixedContent/text()[1]  
/Root/ChildWithMixedContent/b  
/Root/ChildWithMixedContent/b/text()  
/Root/ChildWithMixedContent/text()[2]  
/Root/aw:ElementInNamespace  
/Root/aw:ElementInNamespace/aw:ChildInNamespace  
```

## [How to: Retrieve Paragraphs from an Office Open XML Document](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoretrieveparagraphsfromanofficeopenxmldocument)

本主题提供一个示例，该示例打开一个 Office Open XML 文档，然后检索文档中所有段落所构成的集合。

若要详细了解 Office Open XML，请参阅 [Open XML SDK](https://github.com/OfficeDev/Open-XML-SDK) 和 [www.ericwhite.com](http://ericwhite.com/)。

- 示例

此示例打开一个 Office Open XML 包，使用 Open XML 包中的关系查找文档和样式部件。 然后，它查询文档，投影一个匿名类型的集合，该集合包含段落 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 节点、每个段落的样式名称和每个段落的文本。

此示例使用一个名为 `StringConcatenate` 的扩展方法，示例中也提供了该方法。

有关对此示例的工作原理进行说明的详细教程，请参阅 [XML 的纯功能转换 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/pure-functional-transformations-of-xml)。

本示例使用 WindowsBase 程序集中的类。 它使用 [System.IO.Packaging](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging) 命名空间中的类型。

```csharp
public static class LocalExtensions  
{  
    public static string StringConcatenate(this IEnumerable<string> source)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (string s in source)  
            sb.Append(s);  
        return sb.ToString();  
    }  
  
    public static string StringConcatenate<T>(this IEnumerable<T> source,  
        Func<T, string> func)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (T item in source)  
            sb.Append(func(item));  
        return sb.ToString();  
    }  
  
    public static string StringConcatenate(this IEnumerable<string> source, string separator)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (string s in source)  
            sb.Append(s).Append(separator);  
        return sb.ToString();  
    }  
  
    public static string StringConcatenate<T>(this IEnumerable<T> source,  
        Func<T, string> func, string separator)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (T item in source)  
            sb.Append(func(item)).Append(separator);  
        return sb.ToString();  
    }  
}  
  
class Program  
{  
    public static string ParagraphText(XElement e)  
    {  
        XNamespace w = e.Name.Namespace;  
        return e  
               .Elements(w + "r")  
               .Elements(w + "t")  
               .StringConcatenate(element => (string)element);  
    }  
  
    static void Main(string[] args)  
    {  
        const string fileName = "SampleDoc.docx";  
  
        const string documentRelationshipType =  
          "http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument";  
        const string stylesRelationshipType =  
          "http://schemas.openxmlformats.org/officeDocument/2006/relationships/styles";  
        const string wordmlNamespace =  
          "http://schemas.openxmlformats.org/wordprocessingml/2006/main";  
        XNamespace w = wordmlNamespace;  
  
        XDocument xDoc = null;  
        XDocument styleDoc = null;  
  
        using (Package wdPackage = Package.Open(fileName, FileMode.Open, FileAccess.Read))  
        {  
            PackageRelationship docPackageRelationship =  
              wdPackage  
              .GetRelationshipsByType(documentRelationshipType)  
              .FirstOrDefault();  
            if (docPackageRelationship != null)  
            {  
                Uri documentUri =  
                    PackUriHelper  
                    .ResolvePartUri(  
                       new Uri("/", UriKind.Relative),  
                             docPackageRelationship.TargetUri);  
                PackagePart documentPart =  
                    wdPackage.GetPart(documentUri);  
  
                //  Load the document XML in the part into an XDocument instance.  
                xDoc = XDocument.Load(XmlReader.Create(documentPart.GetStream()));  
  
                //  Find the styles part. There will only be one.  
                PackageRelationship styleRelation =  
                  documentPart.GetRelationshipsByType(stylesRelationshipType)  
                  .FirstOrDefault();  
                if (styleRelation != null)  
                {  
                    Uri styleUri = PackUriHelper.ResolvePartUri(documentUri, styleRelation.TargetUri);  
                    PackagePart stylePart = wdPackage.GetPart(styleUri);  
  
                    //  Load the style XML in the part into an XDocument instance.  
                    styleDoc = XDocument.Load(XmlReader.Create(stylePart.GetStream()));  
                }  
            }  
        }  
  
        string defaultStyle =  
            (string)(  
                from style in styleDoc.Root.Elements(w + "style")  
                where (string)style.Attribute(w + "type") == "paragraph" &&  
                      (string)style.Attribute(w + "default") == "1"  
                select style  
            ).First().Attribute(w + "styleId");  
  
        // Find all paragraphs in the document.  
        var paragraphs =  
            from para in xDoc  
                         .Root  
                         .Element(w + "body")  
                         .Descendants(w + "p")  
            let styleNode = para  
                            .Elements(w + "pPr")  
                            .Elements(w + "pStyle")  
                            .FirstOrDefault()  
            select new  
            {  
                ParagraphNode = para,  
                StyleName = styleNode != null ?  
                    (string)styleNode.Attribute(w + "val") :  
                    defaultStyle  
            };  
  
        // Retrieve the text of each paragraph.  
        var paraWithText =  
            from para in paragraphs  
            select new  
            {  
                ParagraphNode = para.ParagraphNode,  
                StyleName = para.StyleName,  
                Text = ParagraphText(para.ParagraphNode)  
            };  
  
        foreach (var p in paraWithText)  
            Console.WriteLine("StyleName:{0} >{1}<", p.StyleName, p.Text);  
    }  
}  
```

当针对[创建 Source Office Open XML 文档 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/creating-the-source-office-open-xml-document) 中说明的示例 Open XML 文档运行时，此示例生成以下输出：

```
StyleName:Heading1 >Parsing WordprocessingML with LINQ to XML<  
StyleName:Normal ><  
StyleName:Normal >The following example prints to the console.<  
StyleName:Normal ><  
StyleName:Code >using System;<  
StyleName:Code ><  
StyleName:Code >class Program {<  
StyleName:Code >    public static void (string[] args) {<  
StyleName:Code >        Console.WriteLine("Hello World");<  
StyleName:Code >    }<  
StyleName:Code >}<  
StyleName:Normal ><  
StyleName:Normal >This example produces the following output:<  
StyleName:Normal ><  
StyleName:Code >Hello World<  
```

## [How to: Modify an Office Open XML Document](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtomodifyanofficeopenxmldocument)

本主题显演示一个打开、修改和保存 Office Open XML 文档的示例。

若要详细了解 Office Open XML，请参阅 [Open XML SDK](https://github.com/OfficeDev/Open-XML-SDK) 和 [www.ericwhite.com](http://ericwhite.com/)。

- 示例

本示例查找文档中的第一个段落元素。 示例从段落中检索文本，然后删除段落中的所有文本域。 它创建一个由第一个段落已转换为大写的文本构成的新文本域。 然后将已更改的 XML 序列化为 Open XML 包并关闭该包。

本示例使用 WindowsBase 程序集中的类。 它使用 [System.IO.Packaging](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging) 命名空间中的类型。

```csharp
public static class LocalExtensions  
{  
    public static string StringConcatenate(this IEnumerable<string> source)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (string s in source)  
            sb.Append(s);  
        return sb.ToString();  
    }  
  
    public static string StringConcatenate<T>(this IEnumerable<T> source,  
        Func<T, string> func)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (T item in source)  
            sb.Append(func(item));  
        return sb.ToString();  
    }  
  
    public static string StringConcatenate(this IEnumerable<string> source, string separator)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (string s in source)  
            sb.Append(s).Append(separator);  
        return sb.ToString();  
    }  
  
    public static string StringConcatenate<T>(this IEnumerable<T> source,  
        Func<T, string> func, string separator)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (T item in source)  
            sb.Append(func(item)).Append(separator);  
        return sb.ToString();  
    }  
}  
  
class Program  
{  
    public static string ParagraphText(XElement e)  
    {  
        XNamespace w = e.Name.Namespace;  
        return e  
               .Elements(w + "r")  
               .Elements(w + "t")  
               .StringConcatenate(element => (string)element);  
    }  
  
    static void Main(string[] args)  
    {  
        const string fileName = "SampleDoc.docx";  
  
        const string documentRelationshipType =  
          "http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument";  
        const string stylesRelationshipType =  
          "http://schemas.openxmlformats.org/officeDocument/2006/relationships/styles";  
        const string wordmlNamespace =  
          "http://schemas.openxmlformats.org/wordprocessingml/2006/main";  
        XNamespace w = wordmlNamespace;  
  
        using (Package wdPackage = Package.Open(fileName, FileMode.Open, FileAccess.ReadWrite))  
        {  
            PackageRelationship docPackageRelationship =  
              wdPackage.GetRelationshipsByType(documentRelationshipType).FirstOrDefault();  
            if (docPackageRelationship != null)  
            {  
                Uri documentUri = PackUriHelper.ResolvePartUri(new Uri("/", UriKind.Relative),  
                  docPackageRelationship.TargetUri);  
                PackagePart documentPart = wdPackage.GetPart(documentUri);  
  
                //  Load the document XML in the part into an XDocument instance.  
                XDocument xDoc = XDocument.Load(XmlReader.Create(documentPart.GetStream()));  
  
                //  Find the styles part. There will only be one.  
                PackageRelationship styleRelation =  
                  documentPart.GetRelationshipsByType(stylesRelationshipType).FirstOrDefault();  
                PackagePart stylePart = null;  
                XDocument styleDoc = null;  
  
                if (styleRelation != null)  
                {  
                    Uri styleUri = PackUriHelper.ResolvePartUri(documentUri, styleRelation.TargetUri);  
                    stylePart = wdPackage.GetPart(styleUri);  
  
                    //  Load the style XML in the part into an XDocument instance.  
                    styleDoc = XDocument.Load(XmlReader.Create(stylePart.GetStream()));  
                }  
  
                XElement paraNode = xDoc  
                                    .Root  
                                    .Element(w + "body")  
                                    .Descendants(w + "p")  
                                    .FirstOrDefault();  
  
                string paraText = ParagraphText(paraNode);  
  
                // remove all text runs  
                paraNode.Descendants(w + "r").Remove();  
  
                paraNode.Add(  
                    new XElement(w + "r",  
                        new XElement(w + "t", paraText.ToUpper())  
                    )  
                );  
  
                //  Save the XML into the package  
                using (XmlWriter xw =  
                  XmlWriter.Create(documentPart.GetStream(FileMode.Create, FileAccess.Write)))  
                {  
                    xDoc.Save(xw);  
                }  
  
                Console.WriteLine("New first paragraph: >{0}<", paraText.ToUpper());  
            }  
        }  
    }  
}  
```

如果在运行此程序之后打开 `SampleDoc.docx`，则可以看到此程序已将文档中的第一个段落转换为大写。

当针对[创建 Source Office Open XML 文档 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/creating-the-source-office-open-xml-document) 中说明的示例 Open XML 文档运行时，此示例生成以下输出：

```
New first paragraph: >PARSING WORDPROCESSINGML WITH LINQ TO XML<  
```

## [How to: Populate an XML Tree from the File System](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtopopulateanxmltreefromthefilesystem)

XML 树有一种有用的常见应用，即作为层次结构名称/值数据存储区。 您可以使用层次结构数据填充 XML 树，然后对它进行查询、转换和序列化（如有必要）。 在这种用法中，很多 XML 特定的语义（如命名空间和空白行为）都不重要。 相反，你将 XML 树用作内存中的小型单用户层次结构数据库。

- 示例

下面的示例使用递归从本地文件系统填充 XML 树。 然后查询该树，计算树中所有文件的总大小。

```csharp
class Program  
{  
    static XElement CreateFileSystemXmlTree(string source)  
    {  
        DirectoryInfo di = new DirectoryInfo(source);  
        return new XElement("Dir",  
            new XAttribute("Name", di.Name),  
            from d in Directory.GetDirectories(source)  
            select CreateFileSystemXmlTree(d),  
            from fi in di.GetFiles()  
            select new XElement("File",  
                new XElement("Name", fi.Name),  
                new XElement("Length", fi.Length)  
            )  
        );  
    }  
  
    static void Main(string[] args)  
    {  
        XElement fileSystemTree = CreateFileSystemXmlTree("C:/Tmp");  
        Console.WriteLine(fileSystemTree);  
        Console.WriteLine("------");  
        long totalFileSize =  
            (from f in fileSystemTree.Descendants("File")  
             select (long)f.Element("Length")).Sum();  
        Console.WriteLine("Total File Size:{0}", totalFileSize);  
    }  
}  
```

本示例生成类似下面的输出：

```xml
<Dir Name="Tmp">  
  <Dir Name="ConsoleApplication1">  
    <Dir Name="bin">  
      <Dir Name="Debug">  
        <File>  
          <Name>ConsoleApplication1.exe</Name>  
          <Length>4608</Length>  
        </File>  
        <File>  
          <Name>ConsoleApplication1.pdb</Name>  
          <Length>11776</Length>  
        </File>  
        <File>  
          <Name>ConsoleApplication1.vshost.exe</Name>  
          <Length>9568</Length>  
        </File>  
        <File>  
          <Name>ConsoleApplication1.vshost.exe.manifest</Name>  
          <Length>473</Length>  
        </File>  
      </Dir>  
    </Dir>  
    <Dir Name="obj">  
      <Dir Name="Debug">  
        <Dir Name="TempPE" />  
        <File>  
          <Name>ConsoleApplication1.csproj.FileListAbsolute.txt</Name>  
          <Length>322</Length>  
        </File>  
        <File>  
          <Name>ConsoleApplication1.exe</Name>  
          <Length>4608</Length>  
        </File>  
        <File>  
          <Name>ConsoleApplication1.pdb</Name>  
          <Length>11776</Length>  
        </File>  
      </Dir>  
    </Dir>  
    <Dir Name="Properties">  
      <File>  
        <Name>AssemblyInfo.cs</Name>  
        <Length>1454</Length>  
      </File>  
    </Dir>  
    <File>  
      <Name>ConsoleApplication1.csproj</Name>  
      <Length>2546</Length>  
    </File>  
    <File>  
      <Name>ConsoleApplication1.sln</Name>  
      <Length>937</Length>  
    </File>  
    <File>  
      <Name>ConsoleApplication1.suo</Name>  
      <Length>10752</Length>  
    </File>  
    <File>  
      <Name>Program.cs</Name>  
      <Length>269</Length>  
    </File>  
  </Dir>  
</Dir>  
------  
Total File Size:59089  
```