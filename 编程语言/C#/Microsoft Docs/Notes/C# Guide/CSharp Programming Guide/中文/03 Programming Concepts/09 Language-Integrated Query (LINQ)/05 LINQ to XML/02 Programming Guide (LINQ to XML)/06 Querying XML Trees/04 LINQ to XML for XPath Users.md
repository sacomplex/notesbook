# [LINQ to XML for XPath Users](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/linqtoxmlforxpathusers)

这组主题演示很多 XPath 表达式及其 LINQ to XML 等效表达式。

所有这些示例都使用 LINQ to XML 中的 XPath 功能，该功能是通过 [System.Xml.XPath.Extensions](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xpath.extensions) 中的扩展方法实现的。 这些示例既执行 XPath 表达式也执行 LINQ to XML 表达式。 然后，每个示例都对这两种查询的结果进行比较，验证 XPath 表达式与 LINQ to XML 查询的功能等效性。 由于这两种类型的查询都从相同的 XML 树返回节点，因此查询结果的比较是使用引用标识进行的。

## 本节内容

| 主题                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [XPath 和 LINQ to XML 的比较](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/comparison-of-xpath-and-linq-to-xml) | 概述 XPath 和 LINQ to XML 的异同。                           |
| [如何：查找子元素 (XPath-LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-find-a-child-element-xpath-linq-to-xml) | 将 XPath 子元素轴与 LINQ to XML[Element](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.element) 方法进行比较。  关联的 XPath 表达式为：`"DeliveryNotes"`。 |
| [如何：查找子元素列表 (XPath-LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-find-a-list-of-child-elements-xpath-linq-to-xml) | 将 XPath 子元素轴与 LINQ to XML[Elements](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.elements) 轴进行比较。  关联的 XPath 表达式为：`"./*"` |
| [如何：查找根元素 (XPath-LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-find-the-root-element-xpath-linq-to-xml) | 比较如何使用 XPath 和 LINQ to XML 获取根元素。  关联的 XPath 表达式为：`"/PurchaseOrders"` |
| [如何：查找子代元素 (XPath-LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-find-descendant-elements-xpath-linq-to-xml) | 比较如何使用 XPath 和 LINQ to XML 获取具有特定名称的子代元素。  关联的 XPath 表达式为：`"//Name"` |
| [如何：根据属性进行筛选 (XPath-LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-filter-on-an-attribute-xpath-linq-to-xml) | 比较如何使用 XPath 和 LINQ to XML 获取子代元素，这些子代元素具有指定的名称，并具有一个带指定值的属性。  关联的 XPath 表达式为：`".//Address[@Type='Shipping']"` |
| [如何：查找相关元素 (XPath-LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-find-related-elements-xpath-linq-to-xml) | 比较如何使用 XPath 和 LINQ to XML 在由其他元素的值所引用的属性上获取元素选择。  关联的 XPath 表达式为：`".//Customer[@CustomerID=/Root/Orders/Order[12]/CustomerID]"` |
| [如何：查找命名空间中的元素 (XPath-LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-find-elements-in-a-namespace-xpath-linq-to-xml) | 比较 XPath [XmlNamespaceManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlnamespacemanager) 类与 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 类的 LINQ to XML[Namespace](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname.namespace) 属性在处理 XML 命名空间时的用法。  关联的 XPath 表达式为：`"./aw:*"` |
| [如何：查找前面的同级 (XPath-LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-find-preceding-siblings-xpath-linq-to-xml) | 将 XPath `preceding-sibling` 轴与 LINQ to XML 子 [XNode.ElementsBeforeSelf](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.elementsbeforeself) 轴进行比较。  关联的 XPath 表达式为：`"preceding-sibling::*"` |
| [如何：查找子元素的后代 (XPath-LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-find-descendants-of-a-child-element-xpath-linq-to-xml) | 比较如何使用 XPath 和 LINQ to XML 获取具有特定名称的子元素的子代元素。  关联的 XPath 表达式为：`"./Paragraph//Text/text()"` |
| [如何：查找两个位置路径的联合 (XPath-LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-find-a-union-of-two-location-paths-xpath-linq-to-xml) | 将 XPath 中的联合运算符 `|` 与 [Concat](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.concat) 中的 LINQ to XML 标准查询运算符进行比较。  关联的 XPath 表达式为：`"//Category|//Price"` |
| [如何：查找同级节点 (XPath-LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-find-sibling-nodes-xpath-linq-to-xml) | 比较如何使用 XPath 和 LINQ to XML 查找所有具有特定名称的节点同级。  关联的 XPath 表达式为：`"../Book"` |
| [如何：查找父元素的属性 (XPath-LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-find-an-attribute-of-the-parent-xpath-linq-to-xml) | 比较如何使用 XPath 和 LINQ to XML 定位到父元素并查找关联的属性。  关联的 XPath 表达式为：`"../@id"` |
| [如何：查找具有特定名称的同级属性 (XPath-LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-find-attributes-of-siblings-with-a-specific-name-xpath-linq-to-xml) | 比较如何使用 XPath 和 LINQ to XML 查找上下文节点的同级的特定属性。  关联的 XPath 表达式为：`"../Book/@id"` |
| [如何：查找具有特定属性的元素 (XPath-LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-find-elements-with-a-specific-attribute-xpath-linq-to-xml) | 比较如何使用 XPath 和 LINQ to XML 查找所有包含特定属性的元素。  关联的 XPath 表达式为：`"./*[@Select]"` |
| [如何：根据位置查找子元素 (XPath-LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-find-child-elements-based-on-position-xpath-linq-to-xml) | 比较如何使用 XPath 和 LINQ to XML 根据元素的相对位置查找元素。  关联的 XPath 表达式为：`"Test[position() >= 2 and position() <= 4]"` |
| [如何：查找前面紧邻的同级 (XPath-LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-find-the-immediate-preceding-sibling-xpath-linq-to-xml) | 比较如何使用 XPath 和 LINQ to XML 查找节点前面紧邻的同级。  关联的 XPath 表达式为：`"preceding-sibling::*[1]"` |

## [Comparison of XPath and LINQ to XML](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/comparisonofxpathandlinqtoxml)

XPath 和 LINQ to XML 提供一些类似的功能。 二者都可用于查询 XML 树，返回诸如元素集合、属性集合、节点集合或者元素或属性的值等这样的结果。 但也有一些差异。

###### XPath 和 LINQ to XML 之间的差异

XPath 不允许新类型的投影。 它只能从树中返回节点集合，而 LINQ to XML 可以执行查询并将对象图或 XML 树投影为新形状。 LINQ to XML 查询包含更多功能并且比 XPath 表达式的功能强大得多。

XPath 表达式在字符串中孤立存在。 C# 编译器无法在编译时帮助分析 XPath 表达式。 相反，C# 编译器可以分析和编译 LINQ to XML 查询。 编译器能够捕捉许多查询错误。

XPath 结果不是强类型。 在许多情况下，XPath 表达式的计算结果是一个对象，并且该对象需要由开发人员确定属性类型并根据需要强制转换结果。 相比之下，LINQ to XML 查询生成的投影是强类型。

###### 结果排序

XPath 1.0 建议规定，作为 XPath 表达式计算结果的集合是无序的。

但在循环访问由 LINQ to XML XPath 轴方法返回的集合时，集合中的节点将按文档顺序返回。 即使是在访问按反向文档顺序表示谓词的 XPath 轴（如 `preceding` 和 `preceding-sibling`）时，情况也如此。

相比之下，多数 LINQ to XML 轴都按文档顺序返回集合，但其中 [Ancestors](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.ancestors) 和 [AncestorsAndSelf](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.ancestorsandself) 两个轴按反向文档顺序返回集合。 下表枚举各个轴并指示每个轴的集合顺序：

| LINQ to XML 轴                  | 订购         |
| ------------------------------- | ------------ |
| XContainer.DescendantNodes      | 文档顺序     |
| XContainer.Descendants          | 文档顺序     |
| XContainer.Elements             | 文档顺序     |
| XContainer.Nodes                | 文档顺序     |
| XContainer.NodesAfterSelf       | 文档顺序     |
| XContainer.NodesBeforeSelf      | 文档顺序     |
| XElement.AncestorsAndSelf       | 反向文档顺序 |
| XElement.Attributes             | 文档顺序     |
| XElement.DescendantNodesAndSelf | 文档顺序     |
| XElement.DescendantsAndSelf     | 文档顺序     |
| XNode.Ancestors                 | 反向文档顺序 |
| XNode.ElementsAfterSelf         | 文档顺序     |
| XNode.ElementsBeforeSelf        | 文档顺序     |
| XNode.NodesAfterSelf            | 文档顺序     |
| XNode.NodesBeforeSelf           | 文档顺序     |

###### 位置谓词

在 XPath 表达式中，很多轴的位置谓词都按文档顺序表示，但是反向轴 `preceding`、`preceding-sibling`、`ancestor` 和 `ancestor-or-self` 则按反向文档顺序表示。 例如，XPath 表达式 `preceding-sibling::*[1]` 返回前面紧邻的同级。 即使最终结果集按文档顺序表示，情况也是这样。

相比之下，LINQ to XML 中的所有位置谓词始终按轴顺序表示。 例如，`anElement.ElementsBeforeSelf().ElementAt(0)` 返回所查询元素的父级的第一个子元素，而不是前面紧邻的同级。再例如：`anElement.Ancestors().ElementAt(0)` 返回父元素。

如果要查找 LINQ to XML 中的前面紧邻元素，则应编写下面的表达式：

```csharp
ElementsBeforeSelf().Last()
```

###### 性能差异

使用 LINQ to XML 中 XPath 功能的 XPath 查询的执行性能比 LINQ to XML 查询低。

###### 撰写方式的比较

LINQ to XML 查询的撰写在某种程度上类似于 XPath 表达式的撰写，但其语法大不相同。

例如，如果名为 `customers` 的变量中有一个元素，并且您想在所有名为 `CompanyName` 的子级元素下查找名为 `Customer` 的孙级元素，则应编写如下所示的 XPath 表达式：

```csharp
customers.XPathSelectElements("./Customer/CompanyName")
```

等效的 LINQ to XML 查询是：

```csharp
customers.Elements("Customer").Elements("CompanyName")
```

每个 XPath 轴都有一些相似处。

| XPath 轴       | LINQ to XML 轴                                               |
| -------------- | ------------------------------------------------------------ |
| 子级（默认轴） | [XContainer.Elements](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.elements) |
| 父级 (..)      | [XObject.Parent](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobject.parent) |
| 属性轴 (@)     | [XElement.Attribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.attribute)  或  [XElement.Attributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.attributes) |
| 上级轴         | [XNode.Ancestors](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.ancestors) |
| 上级或自身轴   | [XElement.AncestorsAndSelf](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.ancestorsandself) |
| 后代轴 (//)    | [XContainer.Descendants](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.descendants)  或  [XContainer.DescendantNodes](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.descendantnodes) |
| 后代或自身     | [XElement.DescendantsAndSelf](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.descendantsandself)  或  [XElement.DescendantNodesAndSelf](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.descendantnodesandself) |
| 后面同级       | [XNode.ElementsAfterSelf](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.elementsafterself)  或  [XNode.NodesAfterSelf](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.nodesafterself) |
| 前面同级       | [XNode.ElementsBeforeSelf](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.elementsbeforeself)  或  [XNode.NodesBeforeSelf](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.nodesbeforeself) |
| 后面           | 无直接等效项。                                               |
| 前面           | 无直接等效项。                                               |

## [How to: Find a Child Element (XPathLINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtofindachildelementxpathlinqtoxml)

本主题将 XPath 子元素轴与 LINQ to XML [Element](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.element) 方法进行比较。

XPath 表达式为 `DeliveryNotes`。

- 示例

本示例查找子元素 `DeliveryNotes`。

本示例使用下面的 XML 文档：[示例 XML 文件：多个采购订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-multiple-purchase-orders-linq-to-xml)。

```csharp
XDocument cpo = XDocument.Load("PurchaseOrders.xml");  
XElement po = cpo.Root.Element("PurchaseOrder");  
  
// LINQ to XML query  
XElement el1 = po.Element("DeliveryNotes");  
  
// XPath expression  
XElement el2 = po.XPathSelectElement("DeliveryNotes");  
// same as "child::DeliveryNotes"  
// same as "./DeliveryNotes"  
  
if (el1 == el2)  
    Console.WriteLine("Results are identical");  
else  
    Console.WriteLine("Results differ");  
Console.WriteLine(el1);  
```

该示例产生下面的输出：

```
Results are identical  
<DeliveryNotes>Please leave packages in shed by driveway.</DeliveryNotes>  
```

## [How to: Find a List of Child Elements (XPathLINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtofindalistofchildelementsxpathlinqtoxml)

本主题将 XPath 子元素轴与 LINQ to XML [Elements](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.elements) 轴进行比较。

XPath 表达式为：`./*`

- 示例

本示例查找 `Address` 元素的所有子元素。

本示例使用下面的 XML 文档：[示例 XML 文件：多个采购订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-multiple-purchase-orders-linq-to-xml)。

```csharp
XDocument cpo = XDocument.Load("PurchaseOrders.xml");  
XElement po = cpo.Root.Element("PurchaseOrder").Element("Address");  
  
// LINQ to XML query  
IEnumerable<XElement> list1 = po.Elements();  
  
// XPath expression  
IEnumerable<XElement> list2 = po.XPathSelectElements("./*");  
  
if (list1.Count() == list2.Count() &&  
        list1.Intersect(list2).Count() == list1.Count())  
    Console.WriteLine("Results are identical");  
else  
    Console.WriteLine("Results differ");  
foreach (XElement el in list1)  
    Console.WriteLine(el);  
```

该示例产生下面的输出：

```
Results are identical  
<Name>Ellen Adams</Name>  
<Street>123 Maple Street</Street>  
<City>Mill Valley</City>  
<State>CA</State>  
<Zip>10999</Zip>  
<Country>USA</Country>  
```

## [How to: Find the Root Element (XPathLINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtofindtherootelementxpathlinqtoxml)

本主题演示如何使用 XPath 和 LINQ to XML 获取根元素。

XPath 表达式为：

```
/PurchaseOrders
```

- 示例

此示例查找根元素。

本示例使用下面的 XML 文档：[示例 XML 文件：多个采购订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-multiple-purchase-orders-linq-to-xml)。

```csharp
XDocument po = XDocument.Load("PurchaseOrders.xml");  
  
// LINQ to XML query  
XElement el1 = po.Root;  
  
// XPath expression  
XElement el2 = po.XPathSelectElement("/PurchaseOrders");  
  
if (el1 == el2)  
    Console.WriteLine("Results are identical");  
else  
    Console.WriteLine("Results differ");  
Console.WriteLine(el1.Name);  
```

该示例产生下面的输出：

```
Results are identical  
PurchaseOrders  
```

## [How to: Find Descendant Elements (XPathLINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtofinddescendantelementsxpathlinqtoxml)

本主题演示如何获取具有特定名称的后代元素。

XPath 表达式为 `//Name`。

- 示例

本示例查找名为 `Name` 的所有后代。

本示例使用下面的 XML 文档：[示例 XML 文件：多个采购订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-multiple-purchase-orders-linq-to-xml)。

```csharp
XDocument po = XDocument.Load("PurchaseOrders.xml");  
  
// LINQ to XML query  
IEnumerable<XElement> list1 = po.Root.Descendants("Name");  
  
// XPath expression  
IEnumerable<XElement> list2 = po.XPathSelectElements("//Name");  
  
if (list1.Count() == list2.Count() &&  
        list1.Intersect(list2).Count() == list1.Count())  
    Console.WriteLine("Results are identical");  
else  
    Console.WriteLine("Results differ");  
foreach (XElement el in list1)  
    Console.WriteLine(el);  
```

该示例产生下面的输出：

```
Results are identical  
<Name>Ellen Adams</Name>  
<Name>Tai Yee</Name>  
<Name>Cristian Osorio</Name>  
<Name>Cristian Osorio</Name>  
<Name>Jessica Arnold</Name>  
<Name>Jessica Arnold</Name>  
```

## [How to: Filter on an Attribute (XPathLINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtofilteronanattributexpathlinqtoxml)

本主题演示如何获取具有指定名称、并具有一个带指定值的属性的子代元素。

XPath 表达式为：

```
.//Address[@Type='Shipping']
```

- 示例

本示例查找名称为 `Address`，`Type`、并具有一个带“Shipping”值的属性的子代元素。

本示例使用下面的 XML 文档：[示例 XML 文件：多个采购订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-multiple-purchase-orders-linq-to-xml)。

```csharp
XDocument po = XDocument.Load("PurchaseOrders.xml");  
  
// LINQ to XML query  
IEnumerable<XElement> list1 =  
    from el in po.Descendants("Address")  
    where (string)el.Attribute("Type") == "Shipping"  
    select el;  
  
// XPath expression  
IEnumerable<XElement> list2 = po.XPathSelectElements(".//Address[@Type='Shipping']");  
  
if (list1.Count() == list2.Count() &&  
        list1.Intersect(list2).Count() == list1.Count())  
    Console.WriteLine("Results are identical");  
else  
    Console.WriteLine("Results differ");  
foreach (XElement el in list1)  
    Console.WriteLine(el);  
```

该示例产生下面的输出：

```
Results are identical  
<Address Type="Shipping">  
  <Name>Ellen Adams</Name>  
  <Street>123 Maple Street</Street>  
  <City>Mill Valley</City>  
  <State>CA</State>  
  <Zip>10999</Zip>  
  <Country>USA</Country>  
</Address>  
<Address Type="Shipping">  
  <Name>Cristian Osorio</Name>  
  <Street>456 Main Street</Street>  
  <City>Buffalo</City>  
  <State>NY</State>  
  <Zip>98112</Zip>  
  <Country>USA</Country>  
</Address>  
<Address Type="Shipping">  
  <Name>Jessica Arnold</Name>  
  <Street>4055 Madison Ave</Street>  
  <City>Seattle</City>  
  <State>WA</State>  
  <Zip>98112</Zip>  
  <Country>USA</Country>  
</Address>  
```

## [How to: Find Related Elements (XPathLINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtofindrelatedelementsxpathlinqtoxml)

本主题演示如何在由其他元素的值所引用的属性上获取元素选择。

XPath 表达式为：

```
.//Customer[@CustomerID=/Root/Orders/Order[12]/CustomerID]
```

- 示例

本示例查找第 12 个 `Order` 元素，然后查找该订单的客户。

注意，在 .Net 中，对列表的索引是从零开始的。 在 XPath 谓词中，对节点集合的索引是从 1 开始的。 本示例反映了这种差别。

本示例使用下面的 XML 文档：[示例 XML 文件：客户和订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-customers-and-orders-linq-to-xml-2)。

```csharp
XDocument co = XDocument.Load("CustomersOrders.xml");  
  
// LINQ to XML query  
XElement customer1 =  
    (from el in co.Descendants("Customer")  
     where (string)el.Attribute("CustomerID") ==  
          (string)(co  
              .Element("Root")  
              .Element("Orders")  
              .Elements("Order")  
              .ToList()[11]  
              .Element("CustomerID"))  
    select el)  
    .First();  
  
// An alternate way to write the query that avoids creation  
// of a System.Collections.Generic.List:  
XElement customer2 =  
    (from el in co.Descendants("Customer")  
     where (string)el.Attribute("CustomerID") ==  
          (string)(co  
              .Element("Root")  
              .Element("Orders")  
              .Elements("Order")  
              .Skip(11).First()  
              .Element("CustomerID"))  
    select el)  
    .First();  
  
// XPath expression  
XElement customer3 = co.XPathSelectElement(  
  ".//Customer[@CustomerID=/Root/Orders/Order[12]/CustomerID]");  
  
if (customer1 == customer2 && customer1 == customer3)  
    Console.WriteLine("Results are identical");  
else  
    Console.WriteLine("Results differ");  
Console.WriteLine(customer1);  
```

该示例产生下面的输出：

```
Results are identical  
<Customer CustomerID="HUNGC">  
  <CompanyName>Hungry Coyote Import Store</CompanyName>  
  <ContactName>Yoshi Latimer</ContactName>  
  <ContactTitle>Sales Representative</ContactTitle>  
  <Phone>(503) 555-6874</Phone>  
  <Fax>(503) 555-2376</Fax>  
  <FullAddress>  
    <Address>City Center Plaza 516 Main St.</Address>  
    <City>Elgin</City>  
    <Region>OR</Region>  
    <PostalCode>97827</PostalCode>  
    <Country>USA</Country>  
  </FullAddress>  
</Customer>  
```

## [How to: Find Elements in a Namespace (XPathLINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtofindelementsinanamespacexpathlinqtoxml)

XPath 表达式可以在特定命名空间中查找节点。 XPath 表达式使用命名空间前缀来指定命名空间。 若要分析包含命名空间前缀的 XPath 表达式，必须向实现 [IXmlNamespaceResolver](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.ixmlnamespaceresolver) 的 XPath 方法传递一个对象。 本示例使用[XmlNamespaceManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlnamespacemanager)。

XPath 表达式为：

```
./aw:*
```

- 示例

下面的示例读取包含两个命名空间的 XML 树。 它使用 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 来读取 XML 文档。 然后获取 [XmlNameTable](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlnametable)中的 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 和 [XmlNamespaceManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlnamespacemanager) 中的 [XmlNameTable](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlnametable)。 示例在选择元素时使用 [XmlNamespaceManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlnamespacemanager)。

```csharp
XmlReader reader = XmlReader.Create("ConsolidatedPurchaseOrders.xml");  
XElement root = XElement.Load(reader);  
XmlNameTable nameTable = reader.NameTable;  
XmlNamespaceManager namespaceManager = new XmlNamespaceManager(nameTable);  
namespaceManager.AddNamespace("aw", "http://www.adventure-works.com");  
IEnumerable<XElement> list1 = root.XPathSelectElements("./aw:*", namespaceManager);  
IEnumerable<XElement> list2 =  
    from el in root.Elements()  
    where el.Name.Namespace == "http://www.adventure-works.com"  
    select el;  
if (list1.Count() == list2.Count() &&  
        list1.Intersect(list2).Count() == list1.Count())  
    Console.WriteLine("Results are identical");  
else  
    Console.WriteLine("Results differ");  
foreach (XElement el in list2)  
    Console.WriteLine(el);  
```

该示例产生下面的输出：

```
Results are identical  
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
```

## [How to: Find Preceding Siblings (XPathLINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtofindprecedingsiblingsxpathlinqtoxml)

本主题将 XPath `preceding-sibling` 轴与 LINQ to XML 子 [XNode.ElementsBeforeSelf](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.elementsbeforeself) 轴进行比较。

XPath 表达式为：

```
preceding-sibling::*
```

请注意，[XPathSelectElements](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xpath.extensions.xpathselectelements) 和 [XNode.ElementsBeforeSelf](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.elementsbeforeself) 的结果都遵循文档顺序。

- 示例

下面的示例查找 `FullAddress` 元素，然后使用 `preceding-sibling` 轴检索前面的元素。

本示例使用下面的 XML 文档：[示例 XML 文件：客户和订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-customers-and-orders-linq-to-xml-2)。

```csharp
XElement co = XElement.Load("CustomersOrders.xml");  
  
XElement add = co.Element("Customers").Element("Customer").Element("FullAddress");  
  
// LINQ to XML query  
IEnumerable<XElement> list1 = add.ElementsBeforeSelf();  
  
// XPath expression  
IEnumerable<XElement> list2 = add.XPathSelectElements("preceding-sibling::*");  
  
if (list1.Count() == list2.Count() &&  
        list1.Intersect(list2).Count() == list1.Count())  
    Console.WriteLine("Results are identical");  
else  
    Console.WriteLine("Results differ");  
foreach (XElement el in list2)  
    Console.WriteLine(el);  
```

该示例产生下面的输出：

```
Results are identical  
<CompanyName>Great Lakes Food Market</CompanyName>  
<ContactName>Howard Snyder</ContactName>  
<ContactTitle>Marketing Manager</ContactTitle>  
<Phone>(503) 555-7555</Phone>  
```

## [How to: Find Descendants of a Child Element (XPathLINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtofinddescendantsofachildelementxpathlinqtoxml)

本主题演示如何获取具有特定名称的子元素的后代元素。

XPath 表达式为：

```
./Paragraph//Text/text()
```

- 示例

本示例模拟从文字处理文档的 XML 表示形式中提取文本的问题。 示例首先选择所有 `Paragraph` 元素，然后选择每个 `Text` 元素的所有 `Paragraph` 后代元素。 它不选择 `Text` 元素的后代 `Comment` 元素。

```csharp
XElement root = XElement.Parse(  
@"<Root>  
  <Paragraph>  
    <Text>This is the start of</Text>  
  </Paragraph>  
  <Comment>  
    <Text>This comment is not part of the paragraph text.</Text>  
  </Comment>  
  <Paragraph>  
    <Annotation Emphasis='true'>  
      <Text> a sentence.</Text>  
    </Annotation>  
  </Paragraph>  
  <Paragraph>  
    <Text>  This is a second sentence.</Text>  
  </Paragraph>  
</Root>");  
  
// LINQ to XML query  
string str1 =  
    root  
    .Elements("Paragraph")  
    .Descendants("Text")  
    .Select(s => s.Value)  
    .Aggregate(  
        new StringBuilder(),  
        (s, i) => s.Append(i),  
        s => s.ToString()  
    );  
  
// XPath expression  
string str2 =  
    ((IEnumerable)root.XPathEvaluate("./Paragraph//Text/text()"))  
    .Cast<XText>()  
    .Select(s => s.Value)  
    .Aggregate(  
        new StringBuilder(),  
        (s, i) => s.Append(i),  
        s => s.ToString()  
    );  
  
if (str1 == str2)  
    Console.WriteLine("Results are identical");  
else  
    Console.WriteLine("Results differ");  
Console.WriteLine(str2);  
```

该示例产生下面的输出：

```
Results are identical  
This is the start of a sentence.  This is a second sentence.  
```

## [How to: Find a Union of Two Location Paths (XPathLINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtofindaunionoftwolocationpathsxpathlinqtoxml)

使用 XPath 可以查找两个 XPath 位置路径结果的联合。

XPath 表达式为：

```
//Category|//Price
```

通过使用 [Concat](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.concat) 标准查询运算符可以获得相同的结果。

- 示例

本示例查找所有 `Category` 元素和所有 `Price` 元素，并将它们连接到单个集合中。 请注意，LINQ to XML 查询会调用 [InDocumentOrder](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.extensions.indocumentorder) 以对结果进行排序。 XPath 表达式的计算结果也按文档顺序排列。

本示例使用下面的 XML 文档：[示例 XML 文件：数值数据 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-numerical-data-linq-to-xml)。

```csharp
XDocument data = XDocument.Load("Data.xml");  
  
// LINQ to XML query  
IEnumerable<XElement> list1 =  
    data  
    .Descendants("Category")  
    .Concat(  
        data  
        .Descendants("Price")  
    )  
    .InDocumentOrder();  
  
// XPath expression  
IEnumerable<XElement> list2 = data.XPathSelectElements("//Category|//Price");  
  
if (list1.Count() == list2.Count() &&  
        list1.Intersect(list2).Count() == list1.Count())  
    Console.WriteLine("Results are identical");  
else  
    Console.WriteLine("Results differ");  
foreach (XElement el in list1)  
    Console.WriteLine(el);  
```

该示例产生下面的输出：

```
Results are identical  
<Category>A</Category>  
<Price>24.50</Price>  
<Category>B</Category>  
<Price>89.99</Price>  
<Category>A</Category>  
<Price>4.95</Price>  
<Category>A</Category>  
<Price>66.00</Price>  
<Category>B</Category>  
<Price>.99</Price>  
<Category>A</Category>  
<Price>29.00</Price>  
<Category>B</Category>  
<Price>6.99</Price>  
```

## [How to: Find Sibling Nodes (XPathLINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtofindsiblingnodesxpathlinqtoxml)

您可能需要查找某一节点的具有特定名称的所有同级。 如果上下文节点也具有该特定名称，则生成的集合可能会包括上下文节点。

XPath 表达式为：

```
../Book
```

- 示例

本示例首先查找一个 `Book` 元素，然后查找名为 `Book` 的所有同级元素。 生成的集合包括上下文节点。

本示例使用下面的 XML 文档：[示例 XML 文件：图书 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-books-linq-to-xml)。

```csharp
XDocument books = XDocument.Load("Books.xml");  
  
XElement book =   
    books  
    .Root  
    .Elements("Book")  
    .Skip(1)  
    .First();  
  
// LINQ to XML query  
IEnumerable<XElement> list1 =  
    book  
    .Parent  
    .Elements("Book");  
  
// XPath expression  
IEnumerable<XElement> list2 = book.XPathSelectElements("../Book");  
  
if (list1.Count() == list2.Count() &&  
        list1.Intersect(list2).Count() == list1.Count())  
    Console.WriteLine("Results are identical");  
else  
    Console.WriteLine("Results differ");  
foreach (XElement el in list1)  
    Console.WriteLine(el);  
```

该示例产生下面的输出：

```
Results are identical  
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
```

## [How to: Find an Attribute of the Parent (XPathLINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtofindanattributeoftheparentxpathlinqtoxml)

本主题演示如何定位到父元素并查找其属性。

XPath 表达式为：

```
../@id
```

- 示例

此示例首先查找 `Author` 元素。 然后，查找父元素的 `id` 属性。

本示例使用下面的 XML 文档：[示例 XML 文件：图书 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-books-linq-to-xml)。

```csharp
XDocument books = XDocument.Load("Books.xml");  
  
XElement author =   
    books  
    .Root  
    .Element("Book")  
    .Element("Author");  
  
// LINQ to XML query  
XAttribute att1 =  
    author  
    .Parent  
    .Attribute("id");  
  
// XPath expression  
XAttribute att2 = ((IEnumerable)author.XPathEvaluate("../@id")).Cast<XAttribute>().First();  
  
if (att1 == att2)  
    Console.WriteLine("Results are identical");  
else  
    Console.WriteLine("Results differ");  
Console.WriteLine(att1);  
```

该示例产生下面的输出：

```
Results are identical  
id="bk101"  
```

## [How to: Find Attributes of Siblings with a Specific Name (XPathLINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtofindattributesofsiblingswithaspecificnamexpathlinqtoxml)

本主题演示如何查找上下文节点的同级的所有属性。 只返回集合中具有特定名称的属性。

XPath 表达式为：

```
../Book/@id
```

- 示例

本示例首先查找 `Book` 元素，然后查找名为 `Book` 的所有同级元素，再查找名为 `id` 的所有属性。 结果是一个属性集合。

本示例使用下面的 XML 文档：[示例 XML 文件：图书 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-books-linq-to-xml)。

```csharp
XDocument books = XDocument.Load("Books.xml");  
  
XElement book =   
    books  
    .Root  
    .Element("Book");  
  
// LINQ to XML query  
IEnumerable<XAttribute> list1 =  
    from el in book.Parent.Elements("Book")  
    select el.Attribute("id");  
  
// XPath expression  
IEnumerable<XAttribute> list2 =  
  ((IEnumerable)book.XPathEvaluate("../Book/@id")).Cast<XAttribute>();  
  
if (list1.Count() == list2.Count() &&  
        list1.Intersect(list2).Count() == list1.Count())  
    Console.WriteLine("Results are identical");  
else  
    Console.WriteLine("Results differ");  
foreach (XAttribute el in list1)  
    Console.WriteLine(el);  
```

该示例产生下面的输出：

```
Results are identical  
id="bk101"  
id="bk102"  
```

## [How to: Find Elements with a Specific Attribute (XPathLINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtofindelementswithaspecificattributexpathlinqtoxml)

有时需要查找具有特定属性的所有元素。 您并不关心属性的内容， 而是根据属性是否存在进行选择。

XPath 表达式为：

```
./*[@Select]
```

- 示例

下面的代码选择具有 `Select` 属性的所有元素。

```csharp
XElement doc = XElement.Parse(  
@"<Root>  
    <Child1>1</Child1>  
    <Child2 Select='true'>2</Child2>  
    <Child3>3</Child3>  
    <Child4 Select='true'>4</Child4>  
    <Child5>5</Child5>  
</Root>");  
  
// LINQ to XML query  
IEnumerable<XElement> list1 =  
    from el in doc.Elements()  
    where el.Attribute("Select") != null  
    select el;  
  
// XPath expression  
IEnumerable<XElement> list2 =  
    ((IEnumerable)doc.XPathEvaluate("./*[@Select]")).Cast<XElement>();  
  
if (list1.Count() == list2.Count() &&  
        list1.Intersect(list2).Count() == list1.Count())  
    Console.WriteLine("Results are identical");  
else  
    Console.WriteLine("Results differ");  
foreach (XElement el in list1)  
    Console.WriteLine(el);  
```

该示例产生下面的输出：

```
Results are identical  
<Child2 Select="true">2</Child2>  
<Child4 Select="true">4</Child4>  
```

## [How to: Find Child Elements Based on Position (XPathLINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtofindchildelementsbasedonpositionxpathlinqtoxml)

有时需要查找具有特定属性的所有元素。 您并不关心属性的内容， 而是根据属性是否存在进行选择。

XPath 表达式为：

```
./*[@Select]
```

- 示例

下面的代码选择具有 `Select` 属性的所有元素。

```csharp
XElement doc = XElement.Parse(  
@"<Root>  
    <Child1>1</Child1>  
    <Child2 Select='true'>2</Child2>  
    <Child3>3</Child3>  
    <Child4 Select='true'>4</Child4>  
    <Child5>5</Child5>  
</Root>");  
  
// LINQ to XML query  
IEnumerable<XElement> list1 =  
    from el in doc.Elements()  
    where el.Attribute("Select") != null  
    select el;  
  
// XPath expression  
IEnumerable<XElement> list2 =  
    ((IEnumerable)doc.XPathEvaluate("./*[@Select]")).Cast<XElement>();  
  
if (list1.Count() == list2.Count() &&  
        list1.Intersect(list2).Count() == list1.Count())  
    Console.WriteLine("Results are identical");  
else  
    Console.WriteLine("Results differ");  
foreach (XElement el in list1)  
    Console.WriteLine(el);  
```

该示例产生下面的输出：

```
Results are identical  
<Child2 Select="true">2</Child2>  
<Child4 Select="true">4</Child4>  
```

## [How to: Find the Immediate Preceding Sibling (XPathLINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtofindtheimmediateprecedingsiblingxpathlinqtoxml)

有时，您需要查找某一节点的前面紧邻同级。 由于与 LINQ to XML 相比，XPath 中前面紧邻轴的位置谓词的语义同，因此这是一个更值得关注的比较。

- 示例

在本示例中，LINQ to XML 查询使用 [Last](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.last) 运算符查找由 [ElementsBeforeSelf](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.elementsbeforeself) 返回的集合中的最后一个节点。 相比之下，XPath 表达式使用值为 1 的谓词来查找前面紧邻的元素。

```csharp
XElement root = XElement.Parse(  
    @"<Root>  
    <Child1/>  
    <Child2/>  
    <Child3/>  
    <Child4/>  
</Root>");  
XElement child4 = root.Element("Child4");  
  
// LINQ to XML query  
XElement el1 =  
    child4  
    .ElementsBeforeSelf()  
    .Last();  
  
// XPath expression  
XElement el2 =  
    ((IEnumerable)child4  
                 .XPathEvaluate("preceding-sibling::*[1]"))  
                 .Cast<XElement>()  
                 .First();  
  
if (el1 == el2)  
    Console.WriteLine("Results are identical");  
else  
    Console.WriteLine("Results differ");  
Console.WriteLine(el1);  
```

该示例产生下面的输出：

```
Results are identical  
<Child3 />  
```