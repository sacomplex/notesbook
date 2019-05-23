# [Basic Queries (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/basicquerieslinqtoxml)

本节提供基本 LINQ to XML 查询的示例。

## 本节内容

| 主题                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [如何：查找具有特定属性的元素 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-find-an-element-with-a-specific-attribute) | 演示如何查找特定的元素，该元素包含具有特定值的属性。         |
| [如何：查找具有特定子元素的元素 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-find-an-element-with-a-specific-child-element) | 演示如何查找特定的元素，该元素包含具有特定值的子元素。       |
| [查询 XDocument 与查询 XElement (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/querying-an-xdocument-vs-querying-an-xelement) | 解释针对根部位于 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 中的 XML 树编写查询与针对根部位于 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 中的 XML 树编写查询有何差异。 |
| [如何：查找具有特定元素名称的子代 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-find-descendants-with-a-specific-element-name) | 演示如何查找元素的具有特定名称的所有子代。 该示例使用 [Descendants](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.descendants) 轴。 |
| [如何：使用 Descendants 方法查找单个后代 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-find-a-single-descendant-using-the-descendants-method) | 演示如何使用 [Descendants](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.descendants) 轴方法来查找单个具有唯一名称的元素。 |
| [如何：编写使用复杂筛选的查询 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-write-queries-with-complex-filtering) | 演示如何编写具有更复杂的筛选器的查询。                       |
| [如何：筛选可选元素 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-filter-on-an-optional-element) | 演示如何在形状不规则的树中查找节点。                         |
| [如何：查找命名空间中的所有节点 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-find-all-nodes-in-a-namespace) | 演示如何查找特定命名空间中的所有节点。                       |
| [如何：对元素进行排序 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-sort-elements) | 演示如何编写对查询结果进行排序的查询。                       |
| [如何：对多个键上的元素进行排序 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-sort-elements-on-multiple-keys) | 演示如何对多个键进行排序。                                   |
| [如何：计算中间值 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-calculate-intermediate-values) | 演示如何使用 `Let` 子句在 LINQ to XML 查询中计算中间值。     |
| [如何：编写基于上下文查找元素的查询 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-write-a-query-that-finds-elements-based-on-context) | 演示如何根据树中的其他元素来选择元素。                       |
| [如何：调试空查询结果集 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-debug-empty-query-results-sets) | 显示在对针对默认命名空间中 XML 的查询进行调试时相应的修补程序。 |

## [How to: Find an Element with a Specific Attribute](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtofindanelementwithaspecificattribute)

本主题演示如何查找其属性具有特定值的元素。

- 示例

本示例演示如何查找具有值为“Billing”的 `Address` 属性的 `Type` 元素。

本示例使用下面的 XML 文档：[示例 XML 文件：典型采购订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-typical-purchase-order-linq-to-xml-1)。

```csharp
XElement root = XElement.Load("PurchaseOrder.xml");  
IEnumerable<XElement> address =  
    from el in root.Elements("Address")  
    where (string)el.Attribute("Type") == "Billing"  
    select el;  
foreach (XElement el in address)  
    Console.WriteLine(el);  
```

此代码生成以下输出：

```xml
<Address Type="Billing">  
  <Name>Tai Yee</Name>  
  <Street>8 Oak Avenue</Street>  
  <City>Old Town</City>  
  <State>PA</State>  
  <Zip>95819</Zip>  
  <Country>USA</Country>  
</Address>  
```

- 示例

下面的示例演示如何对命名空间中的 XML 进行同样的查询。 有关详细信息，请参阅[使用 XML 命名空间 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/working-with-xml-namespaces)。

本示例使用下面的 XML 文档：[示例 XML 文件：命名空间中的典型采购单](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-typical-purchase-order-in-a-namespace)。

```csharp
XElement root = XElement.Load("PurchaseOrderInNamespace.xml");  
XNamespace aw = "http://www.adventure-works.com";  
IEnumerable<XElement> address =  
    from el in root.Elements(aw + "Address")  
    where (string)el.Attribute(aw + "Type") == "Billing"  
    select el;  
foreach (XElement el in address)  
    Console.WriteLine(el);  
```

此代码生成以下输出：

```xml
<aw:Address aw:Type="Billing" xmlns:aw="http://www.adventure-works.com">  
  <aw:Name>Tai Yee</aw:Name>  
  <aw:Street>8 Oak Avenue</aw:Street>  
  <aw:City>Old Town</aw:City>  
  <aw:State>PA</aw:State>  
  <aw:Zip>95819</aw:Zip>  
  <aw:Country>USA</aw:Country>  
</aw:Address>  
```

## [How to: Find an Element with a Specific Child Element](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtofindanelementwithaspecificchildelement)

本主题演示如何查找特定元素，该特定元素包含具有特定值的子元素。

- 示例

示例查找 `Test` 元素，该元素包含具有值为“Examp2.EXE”的 `CommandLine` 子元素。

本示例使用下面的 XML 文档：[示例 XML 文件：测试配置 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-test-configuration-linq-to-xml)。

```csharp
XElement root = XElement.Load("TestConfig.xml");  
IEnumerable<XElement> tests =  
    from el in root.Elements("Test")  
    where (string)el.Element("CommandLine") == "Examp2.EXE"  
    select el;  
foreach (XElement el in tests)  
    Console.WriteLine((string)el.Attribute("TestId"));  
```

此代码生成以下输出：

```
0002  
0006  
```

- 示例

下面的示例演示如何对命名空间中的 XML 进行同样的查询。 有关详细信息，请参阅[使用 XML 命名空间 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/working-with-xml-namespaces)。

本示例使用下面的 XML 文档：[示例 XML 文件：命名空间中的测试配置](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-test-configuration-in-a-namespace1)。

```csharp
XElement root = XElement.Load("TestConfigInNamespace.xml");  
XNamespace ad = "http://www.adatum.com";  
IEnumerable<XElement> tests =  
    from el in root.Elements(ad + "Test")  
    where (string)el.Element(ad + "CommandLine") == "Examp2.EXE"  
    select el;  
foreach (XElement el in tests)  
    Console.WriteLine((string)el.Attribute("TestId"));  
```

此代码生成以下输出：

```
0002  
0006  
```

## [Querying an XDocument vs. Querying an XElement](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/queryinganxdocumentvsqueryinganxelement)

通过 [XDocument.Load](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument.load) 加载文档时，您会注意到，您要编写的查询与通过 [XElement.Load](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.load) 加载文档时稍有不同。

###### XDocument.Load 与 XElement.Load 的比较

通过 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 将 XML 文档加载到 [XElement.Load](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.load) 中时，位于 XML 树根部的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 包含所加载文档的根元素。 然而，通过 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 将同一个 XML 文档加载到 [XDocument.Load](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument.load) 中时，树根部为 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 节点，所加载文档的根元素为 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 所允许的一个子 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 节点。 LINQ to XML 轴相对于根节点进行操作。

第一个示例使用 [Load](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.load) 加载 XML 树。 然后它查询树根部的子元素。

```csharp
// Create a simple document and write it to a file  
File.WriteAllText("Test.xml", @"<Root>  
    <Child1>1</Child1>  
    <Child2>2</Child2>  
    <Child3>3</Child3>  
</Root>");  
  
Console.WriteLine("Querying tree loaded with XElement.Load");  
Console.WriteLine("----");  
XElement doc = XElement.Load("Test.xml");  
IEnumerable<XElement> childList =  
    from el in doc.Elements()  
    select el;  
foreach (XElement e in childList)  
    Console.WriteLine(e);  
```

此示例将按预期产生以下输出：

```
Querying tree loaded with XElement.Load  
----  
<Child1>1</Child1>  
<Child2>2</Child2>  
<Child3>3</Child3>  
```

下面的示例与上面的基本相同，不同之处在于 XML 树是加载到 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument)，而不是加载到 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)。

```csharp
// Create a simple document and write it to a file  
File.WriteAllText("Test.xml", @"<Root>  
    <Child1>1</Child1>  
    <Child2>2</Child2>  
    <Child3>3</Child3>  
</Root>");  
  
Console.WriteLine("Querying tree loaded with XDocument.Load");  
Console.WriteLine("----");  
XDocument doc = XDocument.Load("Test.xml");  
IEnumerable<XElement> childList =  
    from el in doc.Elements()  
    select el;  
foreach (XElement e in childList)  
    Console.WriteLine(e);  
```

该示例产生下面的输出：

```
Querying tree loaded with XDocument.Load  
----  
<Root>  
  <Child1>1</Child1>  
  <Child2>2</Child2>  
  <Child3>3</Child3>  
</Root>  
```

请注意，同样的查询返回一个 `Root` 节点，而不是返回三个子节点。

处理这一问题的一种方法是在访问轴方法之前使用 [Root](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument.root) 属性，如下所示：

```csharp
// Create a simple document and write it to a file  
File.WriteAllText("Test.xml", @"<Root>  
    <Child1>1</Child1>  
    <Child2>2</Child2>  
    <Child3>3</Child3>  
</Root>");  
  
Console.WriteLine("Querying tree loaded with XDocument.Load");  
Console.WriteLine("----");  
XDocument doc = XDocument.Load("Test.xml");  
IEnumerable<XElement> childList =  
    from el in doc.Root.Elements()  
    select el;  
foreach (XElement e in childList)  
    Console.WriteLine(e);  
```

此查询现在的执行方式与根部位于 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 中的树中的查询相同。 此示例产生以下输出：

```
Querying tree loaded with XDocument.Load  
----  
<Child1>1</Child1>  
<Child2>2</Child2>  
<Child3>3</Child3>  
```

## [How to: Find Descendants with a Specific Element Name](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtofinddescendantswithaspecificelementname)

有时，您想要查找所有具有特定名称的子代。 可以编写代码用于循环访问所有子代，但使用 [Descendants](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.descendants) 轴更简单。

- 示例

下面的示例演示如何根据元素名称查找子代。

```csharp
XElement root = XElement.Parse(@"<root>  
  <para>  
    <r>  
      <t>Some text </t>  
    </r>  
    <n>  
      <r>  
        <t>that is broken up into </t>  
      </r>  
    </n>  
    <n>  
      <r>  
        <t>multiple segments.</t>  
      </r>  
    </n>  
  </para>  
</root>");  
IEnumerable<string> textSegs =  
    from seg in root.Descendants("t")  
    select (string)seg;  
  
string str = textSegs.Aggregate(new StringBuilder(),  
    (sb, i) => sb.Append(i),  
    sp => sp.ToString()  
);  
  
Console.WriteLine(str);  
```

此代码生成以下输出：

```
Some text that is broken up into multiple segments.  
```

- 示例

下面的示例演示如何对命名空间中的 XML 进行同样的查询。 有关详细信息，请参阅[使用 XML 命名空间 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/working-with-xml-namespaces)。

```csharp
XElement root = XElement.Parse(@"<root xmlns='http://www.adatum.com'>  
  <para>  
    <r>  
      <t>Some text </t>  
    </r>  
    <n>  
      <r>  
        <t>that is broken up into </t>  
      </r>  
    </n>  
    <n>  
      <r>  
        <t>multiple segments.</t>  
      </r>  
    </n>  
  </para>  
</root>");  
XNamespace ad = "http://www.adatum.com";  
IEnumerable<string> textSegs =  
    from seg in root.Descendants(ad + "t")  
    select (string)seg;  
  
string str = textSegs.Aggregate(new StringBuilder(),  
    (sb, i) => sb.Append(i),  
    sp => sp.ToString()  
);  
  
Console.WriteLine(str);  
```

此代码生成以下输出：

```
Some text that is broken up into multiple segments.  
```

## [How to: Find a Single Descendant Using the Descendants Method](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtofindasingledescendantusingthedescendantsmethod)

可以使用 [Descendants](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.descendants) 轴方法快速编写代码来查找名称唯一的单个元素。 如果想要查找具有特定名称的特定后代，则此技术特别有用。 虽然可以编写代码以导航到需要的元素，但使用 [Descendants](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.descendants) 轴编写代码通常更快更容易。

- 示例

本示例使用 [First](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.first) 标准查询运算符。

```csharp
XElement root = XElement.Parse(@"<Root>  
  <Child1>  
    <GrandChild1>GC1 Value</GrandChild1>  
  </Child1>  
  <Child2>  
    <GrandChild2>GC2 Value</GrandChild2>  
  </Child2>  
  <Child3>  
    <GrandChild3>GC3 Value</GrandChild3>  
  </Child3>  
  <Child4>  
    <GrandChild4>GC4 Value</GrandChild4>  
  </Child4>  
</Root>");  
string grandChild3 = (string)  
    (from el in root.Descendants("GrandChild3")  
    select el).First();  
Console.WriteLine(grandChild3);  
```

此代码生成以下输出：

```
GC3 Value  
```

- 示例

下面的示例演示如何对命名空间中的 XML 进行同样的查询。 有关详细信息，请参阅[使用 XML 命名空间 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/working-with-xml-namespaces)。

```csharp
XElement root = XElement.Parse(@"<aw:Root xmlns:aw='http://www.adventure-works.com'>  
  <aw:Child1>  
    <aw:GrandChild1>GC1 Value</aw:GrandChild1>  
  </aw:Child1>  
  <aw:Child2>  
    <aw:GrandChild2>GC2 Value</aw:GrandChild2>  
  </aw:Child2>  
  <aw:Child3>  
    <aw:GrandChild3>GC3 Value</aw:GrandChild3>  
  </aw:Child3>  
  <aw:Child4>  
    <aw:GrandChild4>GC4 Value</aw:GrandChild4>  
  </aw:Child4>  
</aw:Root>");  
XNamespace aw = "http://www.adventure-works.com";  
string grandChild3 = (string)  
    (from el in root.Descendants(aw + "GrandChild3")  
     select el).First();  
Console.WriteLine(grandChild3);  
```

此代码生成以下输出：

```
GC3 Value  
```

## [How to: Write Queries with Complex Filtering](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtowritequerieswithcomplexfiltering)

有时，您需要编写使用复杂筛选器的 LINQ to XML 查询。 例如，您可能必须查找其子元素具有特定名称和值的所有元素。 本主题提供一个编写使用复杂筛选的查询的示例。

- 示例

本示例演示如何查找具有 `PurchaseOrder` 属性等于“Shipping”的子 `Address` 元素和等于“NY”的子 `Type` 元素的所有 `State` 元素。 示例在 `Where` 子句中使用嵌套查询，如果集合中有任何元素，则 `Any` 运算符返回 `true`。 有关使用基于方法的查询语法的信息，请参阅 [LINQ 中的查询语法和方法语法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/query-syntax-and-method-syntax-in-linq)。

本示例使用下面的 XML 文档：[示例 XML 文件：多个采购订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-multiple-purchase-orders-linq-to-xml)。

有关 `Any` 运算符的详细信息，请参阅[限定符运算 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/quantifier-operations)。

```csharp
XElement root = XElement.Load("PurchaseOrders.xml");  
IEnumerable<XElement> purchaseOrders =  
    from el in root.Elements("PurchaseOrder")  
    where   
        (from add in el.Elements("Address")  
        where  
            (string)add.Attribute("Type") == "Shipping" &&  
            (string)add.Element("State") == "NY"  
        select add)  
        .Any()  
    select el;  
foreach (XElement el in purchaseOrders)  
    Console.WriteLine((string)el.Attribute("PurchaseOrderNumber"));  
```

此代码生成以下输出：

```
99505  
```

- 示例

下面的示例演示如何对命名空间中的 XML 进行同样的查询。 有关详细信息，请参阅[使用 XML 命名空间 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/working-with-xml-namespaces)。

本示例使用下面的 XML 文档：[示例 XML 文件：命名空间中的多个采购订单](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-multiple-purchase-orders-in-a-namespace)。

```csharp
XElement root = XElement.Load("PurchaseOrdersInNamespace.xml");  
XNamespace aw = "http://www.adventure-works.com";  
IEnumerable<XElement> purchaseOrders =  
    from el in root.Elements(aw + "PurchaseOrder")  
    where  
        (from add in el.Elements(aw + "Address")  
         where  
             (string)add.Attribute(aw + "Type") == "Shipping" &&  
             (string)add.Element(aw + "State") == "NY"  
         select add)  
        .Any()  
    select el;  
foreach (XElement el in purchaseOrders)  
    Console.WriteLine((string)el.Attribute(aw + "PurchaseOrderNumber"));  
```

此代码生成以下输出：

```
99505  
```

## [How to: Filter on an Optional Element](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtofilteronanoptionalelement)

有时，尽管不能确定某个元素是否存在于 XML 文档中，您还是会尝试筛选该元素。 应当执行搜索，这样如果特定元素没有子元素，就不会因为筛选它而触发空引用异常。 在下面的示例中，`Child5` 元素没有 `Type` 子元素，但是查询仍可以正确执行。

- 示例

本示例使用 [Elements](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.extensions.elements) 扩展方法。

```csharp
XElement root = XElement.Parse(@"<Root>  
  <Child1>  
    <Text>Child One Text</Text>  
    <Type Value=""Yes""/>  
  </Child1>  
  <Child2>  
    <Text>Child Two Text</Text>  
    <Type Value=""Yes""/>  
  </Child2>  
  <Child3>  
    <Text>Child Three Text</Text>  
    <Type Value=""No""/>  
  </Child3>  
  <Child4>  
    <Text>Child Four Text</Text>  
    <Type Value=""Yes""/>  
  </Child4>  
  <Child5>  
    <Text>Child Five Text</Text>  
  </Child5>  
</Root>");  
var cList =  
    from typeElement in root.Elements().Elements("Type")  
    where (string)typeElement.Attribute("Value") == "Yes"  
    select (string)typeElement.Parent.Element("Text");  
foreach(string str in cList)  
    Console.WriteLine(str);  
```

此代码生成以下输出：

```
Child One Text  
Child Two Text  
Child Four Text  
```

- 示例

下面的示例演示如何对命名空间中的 XML 进行同样的查询。 有关详细信息，请参阅[使用 XML 命名空间 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/working-with-xml-namespaces)。

```csharp
XElement root = XElement.Parse(@"<Root xmlns='http://www.adatum.com'>  
  <Child1>  
    <Text>Child One Text</Text>  
    <Type Value=""Yes""/>  
  </Child1>  
  <Child2>  
    <Text>Child Two Text</Text>  
    <Type Value=""Yes""/>  
  </Child2>  
  <Child3>  
    <Text>Child Three Text</Text>  
    <Type Value=""No""/>  
  </Child3>  
  <Child4>  
    <Text>Child Four Text</Text>  
    <Type Value=""Yes""/>  
  </Child4>  
  <Child5>  
    <Text>Child Five Text</Text>  
  </Child5>  
</Root>");  
XNamespace ad = "http://www.adatum.com";  
var cList =  
    from typeElement in root.Elements().Elements(ad + "Type")  
    where (string)typeElement.Attribute("Value") == "Yes"  
    select (string)typeElement.Parent.Element(ad + "Text");  
foreach (string str in cList)  
    Console.WriteLine(str);  
```

此代码生成以下输出：

```
Child One Text  
Child Two Text  
Child Four Text  
```

## [How to: Find All Nodes in a Namespace](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtofindallnodesinanamespace)

您可以对每个元素或属性的命名空间进行筛选，以便查找该特定命名空间中的所有节点。

- 示例

下面的示例创建一个包含两个命名空间的 XML 树。 然后循环访问该树并将打印其中一个命名空间中所有元素和属性的名称。

```csharp
string markup = @"<aw:Root xmlns:aw='http://www.adventure-works.com' xmlns:fc='www.fourthcoffee.com'>  
  <fc:Child1>abc</fc:Child1>  
  <fc:Child2>def</fc:Child2>  
  <aw:Child3>ghi</aw:Child3>  
  <fc:Child4>  
    <fc:GrandChild1>jkl</fc:GrandChild1>  
    <aw:GrandChild2>mno</aw:GrandChild2>  
  </fc:Child4>  
</aw:Root>";  
XElement xmlTree = XElement.Parse(markup);  
Console.WriteLine("Nodes in the http://www.adventure-works.com namespace");  
IEnumerable<XElement> awElements =  
    from el in xmlTree.Descendants()  
    where el.Name.Namespace == "http://www.adventure-works.com"  
    select el;  
foreach (XElement el in awElements)  
    Console.WriteLine(el.Name.ToString());  
```

此代码生成以下输出：

```
Nodes in the http://www.adventure-works.com namespace  
{http://www.adventure-works.com}Child3  
{http://www.adventure-works.com}GrandChild2  
```

- 示例

下面的查询所访问的 XML 文件包含两个位于不同命名空间中的采购订单。 该查询只用其中一个命名空间中的元素创建一个新树。

本示例使用下面的 XML 文档：[示例 XML 文件：合并采购单](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-consolidated-purchase-orders)。

```csharp
XDocument cpo = XDocument.Load("ConsolidatedPurchaseOrders.xml");  
XNamespace aw = "http://www.adventure-works.com";  
XElement newTree = new XElement("Root",  
    from el in cpo.Root.Elements()  
    where el.Name.Namespace == aw  
    select el  
);  
Console.WriteLine(newTree);  
```

此代码生成以下输出：

```xml
<Root>  
  <aw:PurchaseOrder PONumber="11223" Date="2000-01-15" xmlns:aw="http://www.adventure-works.com">  
    <aw:ShippingAddress>  
      <aw:Name>Chris Preston</aw:Name>  
      <aw:Street>123 Main St.</aw:Street>  
      <aw:City>Seattle</aw:City>  
      <aw:State>WA</aw:State>  
      <aw:Zip>98113</aw:Zip>  
      <aw:Country>USA</aw:Country>  
    </aw:ShippingAddress>  
    <aw:BillingAddress>  
      <aw:Name>Chris Preston</aw:Name>  
      <aw:Street>123 Main St.</aw:Street>  
      <aw:City>Seattle</aw:City>  
      <aw:State>WA</aw:State>  
      <aw:Zip>98113</aw:Zip>  
      <aw:Country>USA</aw:Country>  
    </aw:BillingAddress>  
    <aw:DeliveryInstructions>Ship only complete order.</aw:DeliveryInstructions>  
    <aw:Item PartNum="LIT-01">  
      <aw:ProductID>Litware Networking Card</aw:ProductID>  
      <aw:Qty>1</aw:Qty>  
      <aw:Price>20.99</aw:Price>  
    </aw:Item>  
    <aw:Item PartNum="LIT-25">  
      <aw:ProductID>Litware 17in LCD Monitor</aw:ProductID>  
      <aw:Qty>1</aw:Qty>  
      <aw:Price>199.99</aw:Price>  
    </aw:Item>  
  </aw:PurchaseOrder>  
</Root>  
```

## [How to: Sort Elements](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtosortelements)

本示例演示如何编写对查询结果进行排序的查询。

- 示例

本示例使用下面的 XML 文档：[示例 XML 文件：数值数据 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-numerical-data-linq-to-xml)。

```csharp
XElement root = XElement.Load("Data.xml");  
IEnumerable<decimal> prices =  
    from el in root.Elements("Data")  
    let price = (decimal)el.Element("Price")  
    orderby price  
    select price;  
foreach (decimal el in prices)  
    Console.WriteLine(el);  
```

此代码生成以下输出：

```
0.99  
4.95  
6.99  
24.50  
29.00  
66.00  
89.99  
```

- 示例

下面的示例演示如何对命名空间中的 XML 进行同样的查询。 有关详细信息，请参阅[使用 XML 命名空间 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/working-with-xml-namespaces)。

本示例使用下面的 XML 文档：[示例 XML 文件：命名空间中的数值数据](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-numerical-data-in-a-namespace)。

```csharp
XElement root = XElement.Load("DataInNamespace.xml");  
XNamespace aw = "http://www.adatum.com";  
IEnumerable<decimal> prices =  
    from el in root.Elements(aw + "Data")  
    let price = (decimal)el.Element(aw + "Price")  
    orderby price  
    select price;  
foreach (decimal el in prices)  
    Console.WriteLine(el);  
```

此代码生成以下输出：

```
0.99  
4.95  
6.99  
24.50  
29.00  
66.00  
89.99  
```

## [How to: Sort Elements on Multiple Keys](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtosortelementsonmultiplekeys)

本主题演示如何对多个键进行排序。

- 示例

在本示例中，首先按运输邮政编码，然后再按订单日期对结果进行排序。

本示例使用下面的 XML 文档：[示例 XML 文件：客户和订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-customers-and-orders-linq-to-xml-2)。

```csharp
XElement co = XElement.Load("CustomersOrders.xml");  
var sortedElements =  
    from c in co.Element("Orders").Elements("Order")  
    orderby (string)c.Element("ShipInfo").Element("ShipPostalCode"),  
            (DateTime)c.Element("OrderDate")  
    select new {  
        CustomerID = (string)c.Element("CustomerID"),  
        EmployeeID = (string)c.Element("EmployeeID"),  
        ShipPostalCode = (string)c.Element("ShipInfo").Element("ShipPostalCode"),  
        OrderDate = (DateTime)c.Element("OrderDate")  
    };  
foreach (var r in sortedElements)  
    Console.WriteLine("CustomerID:{0} EmployeeID:{1} ShipPostalCode:{2} OrderDate:{3:d}",  
        r.CustomerID, r.EmployeeID, r.ShipPostalCode, r.OrderDate);  
```

此代码生成以下输出：

```
CustomerID:LETSS EmployeeID:1 ShipPostalCode:94117 OrderDate:6/25/1997  
CustomerID:LETSS EmployeeID:8 ShipPostalCode:94117 OrderDate:10/27/1997  
CustomerID:LETSS EmployeeID:6 ShipPostalCode:94117 OrderDate:11/10/1997  
CustomerID:LETSS EmployeeID:4 ShipPostalCode:94117 OrderDate:2/12/1998  
CustomerID:GREAL EmployeeID:6 ShipPostalCode:97403 OrderDate:5/6/1997  
CustomerID:GREAL EmployeeID:8 ShipPostalCode:97403 OrderDate:7/4/1997  
CustomerID:GREAL EmployeeID:1 ShipPostalCode:97403 OrderDate:7/31/1997  
CustomerID:GREAL EmployeeID:4 ShipPostalCode:97403 OrderDate:7/31/1997  
CustomerID:GREAL EmployeeID:6 ShipPostalCode:97403 OrderDate:9/4/1997  
CustomerID:GREAL EmployeeID:3 ShipPostalCode:97403 OrderDate:9/25/1997  
CustomerID:GREAL EmployeeID:4 ShipPostalCode:97403 OrderDate:1/6/1998  
CustomerID:GREAL EmployeeID:3 ShipPostalCode:97403 OrderDate:3/9/1998  
CustomerID:GREAL EmployeeID:3 ShipPostalCode:97403 OrderDate:4/7/1998  
CustomerID:GREAL EmployeeID:4 ShipPostalCode:97403 OrderDate:4/22/1998  
CustomerID:GREAL EmployeeID:4 ShipPostalCode:97403 OrderDate:4/30/1998  
CustomerID:HUNGC EmployeeID:3 ShipPostalCode:97827 OrderDate:12/6/1996  
CustomerID:HUNGC EmployeeID:1 ShipPostalCode:97827 OrderDate:12/25/1996  
CustomerID:HUNGC EmployeeID:3 ShipPostalCode:97827 OrderDate:1/15/1997  
CustomerID:HUNGC EmployeeID:4 ShipPostalCode:97827 OrderDate:7/16/1997  
CustomerID:HUNGC EmployeeID:8 ShipPostalCode:97827 OrderDate:9/8/1997  
CustomerID:LAZYK EmployeeID:1 ShipPostalCode:99362 OrderDate:3/21/1997  
CustomerID:LAZYK EmployeeID:8 ShipPostalCode:99362 OrderDate:5/22/1997  
```

- 示例

下面的示例演示如何对命名空间中的 XML 进行同样的查询。 有关详细信息，请参阅[使用 XML 命名空间 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/working-with-xml-namespaces)。

本示例使用下面的 XML 文档：[示例 XML 文件：命名空间中的客户和订单](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-customers-and-orders-in-a-namespace)。



```csharp
XElement co = XElement.Load("CustomersOrdersInNamespace.xml");  
XNamespace aw = "http://www.adventure-works.com";  
var sortedElements =  
    from c in co.Element(aw + "Orders").Elements(aw + "Order")  
    orderby (string)c.Element(aw + "ShipInfo").Element(aw + "ShipPostalCode"),  
            (DateTime)c.Element(aw + "OrderDate")  
    select new  
    {  
        CustomerID = (string)c.Element(aw + "CustomerID"),  
        EmployeeID = (string)c.Element(aw + "EmployeeID"),  
        ShipPostalCode = (string)c.Element(aw + "ShipInfo").Element(aw + "ShipPostalCode"),  
        OrderDate = (DateTime)c.Element(aw + "OrderDate")  
    };  
foreach (var r in sortedElements)  
    Console.WriteLine("CustomerID:{0} EmployeeID:{1} ShipPostalCode:{2} OrderDate:{3:d}",  
        r.CustomerID, r.EmployeeID, r.ShipPostalCode, r.OrderDate);  
```

此代码生成以下输出：

```
CustomerID:LETSS EmployeeID:1 ShipPostalCode:94117 OrderDate:6/25/1997  
CustomerID:LETSS EmployeeID:8 ShipPostalCode:94117 OrderDate:10/27/1997  
CustomerID:LETSS EmployeeID:6 ShipPostalCode:94117 OrderDate:11/10/1997  
CustomerID:LETSS EmployeeID:4 ShipPostalCode:94117 OrderDate:2/12/1998  
CustomerID:GREAL EmployeeID:6 ShipPostalCode:97403 OrderDate:5/6/1997  
CustomerID:GREAL EmployeeID:8 ShipPostalCode:97403 OrderDate:7/4/1997  
CustomerID:GREAL EmployeeID:1 ShipPostalCode:97403 OrderDate:7/31/1997  
CustomerID:GREAL EmployeeID:4 ShipPostalCode:97403 OrderDate:7/31/1997  
CustomerID:GREAL EmployeeID:6 ShipPostalCode:97403 OrderDate:9/4/1997  
CustomerID:GREAL EmployeeID:3 ShipPostalCode:97403 OrderDate:9/25/1997  
CustomerID:GREAL EmployeeID:4 ShipPostalCode:97403 OrderDate:1/6/1998  
CustomerID:GREAL EmployeeID:3 ShipPostalCode:97403 OrderDate:3/9/1998  
CustomerID:GREAL EmployeeID:3 ShipPostalCode:97403 OrderDate:4/7/1998  
CustomerID:GREAL EmployeeID:4 ShipPostalCode:97403 OrderDate:4/22/1998  
CustomerID:GREAL EmployeeID:4 ShipPostalCode:97403 OrderDate:4/30/1998  
CustomerID:HUNGC EmployeeID:3 ShipPostalCode:97827 OrderDate:12/6/1996  
CustomerID:HUNGC EmployeeID:1 ShipPostalCode:97827 OrderDate:12/25/1996  
CustomerID:HUNGC EmployeeID:3 ShipPostalCode:97827 OrderDate:1/15/1997  
CustomerID:HUNGC EmployeeID:4 ShipPostalCode:97827 OrderDate:7/16/1997  
CustomerID:HUNGC EmployeeID:8 ShipPostalCode:97827 OrderDate:9/8/1997  
CustomerID:LAZYK EmployeeID:1 ShipPostalCode:99362 OrderDate:3/21/1997  
CustomerID:LAZYK EmployeeID:8 ShipPostalCode:99362 OrderDate:5/22/1997  
```

## [How to: Calculate Intermediate Values](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtocalculateintermediatevalues)

本示例演示如何计算可用于进行排序、筛选和选择的中间值。

- 示例

下面的示例使用 `Let` 子句。

本示例使用下面的 XML 文档：[示例 XML 文件：数值数据 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-numerical-data-linq-to-xml)。

```csharp
XElement root = XElement.Load("Data.xml");  
IEnumerable<decimal> extensions =  
    from el in root.Elements("Data")  
    let extension = (decimal)el.Element("Quantity") * (decimal)el.Element("Price")  
    where extension >= 25  
    orderby extension  
    select extension;  
foreach (decimal ex in extensions)  
    Console.WriteLine(ex);  
```

此代码生成以下输出：

```
55.92  
73.50  
89.99  
198.00  
435.00  
```

- 示例

下面的示例演示如何对命名空间中的 XML 进行同样的查询。 有关详细信息，请参阅[使用 XML 命名空间 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/working-with-xml-namespaces)。

本示例使用下面的 XML 文档：[示例 XML 文件：命名空间中的数值数据](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-numerical-data-in-a-namespace)。

```csharp
XElement root = XElement.Load("DataInNamespace.xml");  
XNamespace ad = "http://www.adatum.com";  
IEnumerable<decimal> extensions =  
    from el in root.Elements(ad + "Data")  
    let extension = (decimal)el.Element(ad + "Quantity") * (decimal)el.Element(ad + "Price")  
    where extension >= 25  
    orderby extension  
    select extension;  
foreach (decimal ex in extensions)  
    Console.WriteLine(ex);  
```

此代码生成以下输出：

```
55.92  
73.50  
89.99  
198.00  
435.00  
```

## [How to: Write a Query that Finds Elements Based on Context](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtowriteaquerythatfindselementsbasedoncontext)

有时，您可能必须编写基于元素上下文选择元素的查询。 您可能需要基于前面或后面的同级元素进行筛选。 您可能需要基于子元素或上级元素进行筛选。

通过编写查询并在 `where` 子句中使用查询的结果可以实现此目的。 如果在测试值之前必须先测试空值，则更适合在 `let` 子句中执行查询，然后在 `where` 子句中使用查询结果。

- 示例

下面的示例选择后面紧接 `p` 元素的所有 `ul` 元素。

```csharp
XElement doc = XElement.Parse(@"<Root>  
    <p id=""1""/>  
    <ul>abc</ul>  
    <Child>  
        <p id=""2""/>  
        <notul/>  
        <p id=""3""/>  
        <ul>def</ul>  
        <p id=""4""/>  
    </Child>  
    <Child>  
        <p id=""5""/>  
        <notul/>  
        <p id=""6""/>  
        <ul>abc</ul>  
        <p id=""7""/>  
    </Child>  
</Root>");  
  
IEnumerable<XElement> items =  
    from e in doc.Descendants("p")  
    let z = e.ElementsAfterSelf().FirstOrDefault()  
    where z != null && z.Name.LocalName == "ul"  
    select e;  
  
foreach (XElement e in items)  
    Console.WriteLine("id = {0}", (string)e.Attribute("id"));  
```

此代码生成以下输出：

```
id = 1  
id = 3  
id = 6  
```

- 示例

下面的示例演示如何对命名空间中的 XML 进行同样的查询。 有关详细信息，请参阅[使用 XML 命名空间 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/working-with-xml-namespaces)。

```csharp
XElement doc = XElement.Parse(@"<Root xmlns='http://www.adatum.com'>  
    <p id=""1""/>  
    <ul>abc</ul>  
    <Child>  
        <p id=""2""/>  
        <notul/>  
        <p id=""3""/>  
        <ul>def</ul>  
        <p id=""4""/>  
    </Child>  
    <Child>  
        <p id=""5""/>  
        <notul/>  
        <p id=""6""/>  
        <ul>abc</ul>  
        <p id=""7""/>  
    </Child>  
</Root>");  
  
XNamespace ad = "http://www.adatum.com";  
  
IEnumerable<XElement> items =  
    from e in doc.Descendants(ad + "p")  
    let z = e.ElementsAfterSelf().FirstOrDefault()  
    where z != null && z.Name == ad.GetName("ul")  
    select e;  
  
foreach (XElement e in items)  
    Console.WriteLine("id = {0}", (string)e.Attribute("id"));  
```

此代码生成以下输出：

```
id = 1  
id = 3  
id = 6  
```

## [How to: Debug Empty Query Results Sets](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtodebugemptyqueryresultssets)

查询 XML 树时遇到的一个最常见问题是，如果 XML 树具有默认命名空间，开发人员在编写查询时，有时会将 XML 视为不在命名空间内。

本主题的第一个示例集演示一种加载并按不正确方式查询默认命名空间中的 XML 的典型方式。

第二个示例集演示必需的更正，以便可以查询命名空间中的 XML。

有关详细信息，请参阅[使用 XML 命名空间 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/working-with-xml-namespaces)。

- 示例

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

- 示例

本示例演示如何在命名空间中创建 XML 和一个正确编码的查询。

解决方案为声明和初始化一个 [XNamespace](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnamespace) 对象，并在指定 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 对象时使用该对象。 在这种情况下，[Elements](https://msdn.microsoft.com/library/system.xml.linq.xelement.elements(v=vs.110).aspx) 方法的参数是一个 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 对象。

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