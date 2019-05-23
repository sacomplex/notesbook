# [LINQ to XML Axes](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/linqtoxmlaxes)

创建 XML 树或将 XML 文档加载到 XML 树之后，可以进行查询，从而查找元素和属性并检索它们的值。

在编写查询之前，必须了解 LINQ to XML 轴。 有两类轴方法：第一类，是调用单个 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 对象、[XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument)对象或 [XNode](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode) 对象的方法。 这些方法对单个对象操作，返回 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)、[XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 或 [XNode](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode) 对象的集合。 第二类，是对集合操作并返回集合的扩展方法。 这些扩展方法可以：枚举源集合，在集合的每一项上调用适当的轴方法，将结果串联起来。

## 本节内容

| 主题                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [LINQ to XML 轴概述 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/linq-to-xml-axes-overview) | 介绍轴的定义，并说明如何在 LINQ to XML 查询的上下文中使用轴。 |
| [如何：检索元素集合 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-retrieve-a-collection-of-elements-linq-to-xml) | 介绍 [Elements](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.elements) 方法。 此方法检索元素的子元素集合。 |
| [如何：检索元素的值 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-retrieve-the-value-of-an-element-linq-to-xml) | 演示如何获取元素的值。                                       |
| [如何：筛选元素名称 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-filter-on-element-names-linq-to-xml) | 演示如何在使用轴时筛选元素名称。                             |
| [如何：链接轴方法调用 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-chain-axis-method-calls-linq-to-xml) | 演示如何将调用链接到轴方法。                                 |
| [如何：检索单个子元素 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-retrieve-a-single-child-element-linq-to-xml) | 演示在给定子元素标记名的情况下，如何检索元素的单个子元素。   |
| [如何：检索属性集合 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-retrieve-a-collection-of-attributes-linq-to-xml) | 介绍 [Attributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.attributes) 方法。 此方法检索元素的属性。 |
| [如何：检索单个属性 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-retrieve-a-single-attribute-linq-to-xml) | 演示在给定属性名称的情况下，如何检索元素的单个属性。         |
| [如何：检索属性的值 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-retrieve-the-value-of-an-attribute-linq-to-xml) | 演示如何获取属性的值。                                       |
| [如何：检索元素的浅值 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-retrieve-the-shallow-value-of-an-element) | 演示如何检索元素的浅值。                                     |

## [LINQ to XML Axes Overview](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/linqtoxmlaxesoverview)

创建 XML 树或将 XML 文档加载到 XML 树之后，可以进行查询，从而查找元素和属性并检索它们的值。 通过*轴方法*（也叫做*轴*）来检索集合。 一些轴就是 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 和 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 类中返回 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 集合的方法。 另一些轴是 [Extensions](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.extensions) 类中的扩展方法。 实现为扩展方法的轴对集合进行操作，然后返回集合。

如同 [XElement 类概述](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/xelement-class-overview)中所述，[XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 对象表示单个元素节点。 元素的内容可以是复杂的（有时称为结构化内容），也可以是简单元素。 简单元素可以是空的，也可以包含值。 如果节点包含结构化内容，则可以使用各种轴方法来检索子代元素的枚举。 最常使用的轴方法是 [Elements](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.elements) 和 [Descendants](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.descendants)。

除了返回集合的轴方法之外，还有两个方法会在 LINQ to XML 查询中经常用到。 [Element](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.element) 方法返回单个 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)。 [Attribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.attribute) 方法返回单个 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute)。

对于很多应用来说，LINQ 查询提供了检查树、从树中提取数据以及转换树的最有效的方法。 LINQ 查询对实现 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的对象进行操作，LINQ to XML 轴返回 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 集合的 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1)，以及 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 集合的 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1)。 需要使用这些集合来执行查询。

除了检索元素和属性集合的轴方法之外，还有一些轴方法可以十分详尽地循环访问树。 例如，可以处理树的节点，而不是处理元素和属性。 节点比元素和属性有更细的粒度。 处理节点时，可以检查 XML 注释、文本节点、处理指令以及其他方面。 该功能很重要，例如对正在编写字处理器并希望将文档保存为 XML 的用户非常有用。但是，大部分 XML 程序员主要关心的是元素、属性和它们的值。

##### 用于检索元素集合的方法

下面是 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 类（或其基类）的方法汇总，您可以对 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 调用这些方法以返回元素集合。

| 方法                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [XNode.Ancestors](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.ancestors) | 返回此元素的上级的 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)。 重载方法返回上级的 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)，这些上级具有指定的 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname)。 |
| [XContainer.Descendants](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.descendants) | 返回此元素的子代的 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)。 重载方法返回子代的 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)，这些子代具有指定的 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname)。 |
| [XContainer.Elements](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.elements) | 返回此元素的子元素的 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)。 重载方法返回子元素的 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)，这些子元素具有指定的 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname)。 |
| [XNode.ElementsAfterSelf](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.elementsafterself) | 返回此元素之后的元素的 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)。 重载方法返回此元素之后的元素的 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)，此元素之后的这些元素具有指定的 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname)。 |
| [XNode.ElementsBeforeSelf](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.elementsbeforeself) | 返回此元素之前的元素的 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)。 重载方法返回此元素之前的元素的 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)，此元素之前的这些元素具有指定的 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname)。 |
| [XElement.AncestorsAndSelf](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.ancestorsandself) | 返回此元素及其上级的 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)。 重载方法返回元素的 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)，这些元素具有指定的 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname)。 |
| [XElement.DescendantsAndSelf](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.descendantsandself) | 返回此元素及其子代的 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)。 重载方法返回元素的 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)，这些元素具有指定的 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname)。 |

##### 用于检索单个元素的方法

下面的方法从 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 对象中检索单个子级。

| 方法                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [XContainer.Element](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.element) | 返回具有指定 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 的第一个子 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 对象。 |

##### 用于检索属性集合的方法

下面的方法从 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 对象中检索属性。

| 方法                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [XElement.Attributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.attributes) | 返回所有属性的 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute)。 |

##### 用于检索单个属性的方法

下面的方法从 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 对象中检索单个属性。

| 方法                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [XElement.Attribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.attribute) | 返回具有指定 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 的 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname)。 |

## [How to: Retrieve a Collection of Elements (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/cs#### harp/programmingguide/concepts/linq/howtoretrieveacollectionofelementslinqtoxml)

本主题演示 [Elements](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.elements) 方法。 此方法检索元素的子元素集合。

- 示例

本示例循环访问 `purchaseOrder` 元素的子元素。

本示例使用下面的 XML 文档：[示例 XML 文件：典型采购订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-typical-purchase-order-linq-to-xml-1)。

```csharp
XElement po = XElement.Load("PurchaseOrder.xml");  
IEnumerable<XElement> childElements =  
    from el in po.Elements()  
    select el;  
foreach (XElement el in childElements)  
    Console.WriteLine("Name: " + el.Name);  
```

本示例生成以下输出。

```
Name: Address  
Name: Address  
Name: DeliveryNotes  
Name: Items  
```

## [How to: Retrieve the Value of an Element (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoretrievethevalueofanelementlinqtoxml)

本主题演示如何获取元素的值。 有两种主要方法可以完成此操作。 一种方法是将 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 或 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 强制转换为所需的类型。 然后，显式转换运算符将元素或属性的内容转换为指定的类型，并将其分配给变量。 此外，还可以使用 [XElement.Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.value) 属性或 [XAttribute.Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute.value) 属性。

但是，对于 C#，强制转换通常是更好的方法。 在检索可能存在也可能不存在的元素（或属性）的值时，如果将元素或属性强制转换为可以为 null 的类型，则代码会更易于编写。 本主题最后一个示例对此进行了演示。 但是，无法通过强制转换设置元素的内容，而通过 [XElement.Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.value) 属性可以做到这一点。

##### 示例

若要检索元素的值，只需将 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 对象强制转换为所需的类型即可。 任何时候都可以将元素强制转换为字符串，如下所示：

```csharp
XElement e = new XElement("StringElement", "abcde");  
Console.WriteLine(e);  
Console.WriteLine("Value of e:" + (string)e);  
```

该示例产生下面的输出：

```
<StringElement>abcde</StringElement>  
Value of e:abcde  
```

##### 示例

此外，还可以将元素强制转换为字符串以外的其他类型。 例如，如果有一个包含一个整数的元素，可以将它强制转换为 `int`，如下面的代码所示：

```csharp
XElement e = new XElement("Age", "44");  
Console.WriteLine(e);  
Console.WriteLine("Value of e:" + (int)e);  
```

该示例产生下面的输出：

```
<Age>44</Age>  
Value of e:44  
```

LINQ to XML 提供了以下数据类型的显式强制转换运算符：`string`、`bool`、`bool?`、`int`、`int?`、`uint`、`uint?`、`long`、`long?`、`ulong`、`ulong?`、`float`、`float?`、`double`、`double?`、`decimal`、`decimal?`、`DateTime`、`DateTime?`、`TimeSpan`、`TimeSpan?`、`GUID` 和 `GUID?`。

LINQ to XML 为 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 对象提供了相同的强制转换运算符。

##### 示例

可以使用 [Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.value) 属性来检索元素的内容：

```csharp
XElement e = new XElement("StringElement", "abcde");   
Console.WriteLine(e);  
Console.WriteLine("Value of e:" + e.Value);  
```

该示例产生下面的输出：

```
<StringElement>abcde</StringElement>  
Value of e:abcde  
```

##### 示例

有时，尽管不能确定某个元素是否存在，还是会尝试检索该元素的值。 在这种情况下，将强制转换后的元素分配给可以为 null 的类型（`string` 或 .NET Framework 中可以为 null 的类型之一）时，如果该元素不存在，则将分配的变量设置为 `null`。 下面的代码演示当元素可能存在也可能不存在时，使用强制转换比使用 [Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.value) 属性更加简单。

```csharp
XElement root = new XElement("Root",  
    new XElement("Child1", "child 1 content"),  
    new XElement("Child2", "2")  
);  
  
// The following assignments show why it is easier to use  
// casting when the element might or might not exist.  
  
string c1 = (string)root.Element("Child1");  
Console.WriteLine("c1:{0}", c1 == null ? "element does not exist" : c1);  
  
int? c2 = (int?)root.Element("Child2");  
Console.WriteLine("c2:{0}", c2 == null ? "element does not exist" : c2.ToString());  
  
string c3 = (string)root.Element("Child3");  
Console.WriteLine("c3:{0}", c3 == null ? "element does not exist" : c3);  
  
int? c4 = (int?)root.Element("Child4");  
Console.WriteLine("c4:{0}", c4 == null ? "element does not exist" : c4.ToString());  
  
Console.WriteLine();  
  
// The following assignments show the required code when using  
// the Value property when the element might or might not exist.  
// Notice that this is more difficult than the casting approach.  
  
XElement e1 = root.Element("Child1");  
string v1;  
if (e1 == null)  
    v1 = null;  
else  
    v1 = e1.Value;  
Console.WriteLine("v1:{0}", v1 == null ? "element does not exist" : v1);  
  
XElement e2 = root.Element("Child2");  
int? v2;  
if (e2 == null)  
    v2 = null;  
else  
    v2 = Int32.Parse(e2.Value);  
Console.WriteLine("v2:{0}", v2 == null ? "element does not exist" : v2.ToString());  
  
XElement e3 = root.Element("Child3");  
string v3;  
if (e3 == null)  
    v3 = null;  
else  
    v3 = e3.Value;  
Console.WriteLine("v3:{0}", v3 == null ? "element does not exist" : v3);  
  
XElement e4 = root.Element("Child4");  
int? v4;  
if (e4 == null)  
    v4 = null;  
else  
    v4 = Int32.Parse(e4.Value);  
Console.WriteLine("v4:{0}", v4 == null ? "element does not exist" : v4.ToString());  
```

此代码生成以下输出：

```
c1:child 1 content  
c2:2  
c3:element does not exist  
c4:element does not exist  
  
v1:child 1 content  
v2:2  
v3:element does not exist  
v4:element does not exist  
```

通常情况下，当使用强制转换来检索元素和属性的内容时，可以编写更简易的代码。

## [How to: Filter on Element Names (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtofilteronelementnameslinqtoxml)

当调用返回 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 的方法之一时，可以根据元素名称进行筛选。

##### 示例

本示例说明如何检索经过筛选仅包含具有指定名称的子代的集合。

本示例使用下面的 XML 文档：[示例 XML 文件：典型采购订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-typical-purchase-order-linq-to-xml-1)。

```csharp
XElement po = XElement.Load("PurchaseOrder.xml");  
IEnumerable<XElement> items =  
    from el in po.Descendants("ProductName")  
    select el;  
foreach(XElement prdName in items)  
    Console.WriteLine(prdName.Name + ":" + (string) prdName);  
```

此代码生成以下输出：

```
ProductName:Lawnmower  
ProductName:Baby Monitor  
```

其他返回 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 集合的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 的方法都遵循相同的模式。 它们的签名类似于 [Elements](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.elements) 和 [Descendants](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.descendants)。 以下是具有相似方法签名的完整方法列表：

- [Ancestors](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.ancestors)
- [Descendants](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.descendants)
- [Elements](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.elements)
- [ElementsAfterSelf](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.elementsafterself)
- [ElementsBeforeSelf](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.elementsbeforeself)
- [AncestorsAndSelf](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.ancestorsandself)
- [DescendantsAndSelf](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.descendantsandself)

##### 示例

下面的示例演示如何对命名空间中的 XML 进行同样的查询。 有关详细信息，请参阅[使用 XML 命名空间 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/working-with-xml-namespaces)。

本示例使用下面的 XML 文档：[示例 XML 文件：命名空间中的典型采购单](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-typical-purchase-order-in-a-namespace)。

```csharp
XNamespace aw = "http://www.adventure-works.com";  
XElement po = XElement.Load("PurchaseOrderInNamespace.xml");  
IEnumerable<XElement> items =  
    from el in po.Descendants(aw + "ProductName")  
    select el;  
foreach (XElement prdName in items)  
    Console.WriteLine(prdName.Name + ":" + (string)prdName);  
```

此代码生成以下输出：

```
{http://www.adventure-works.com}ProductName:Lawnmower  
{http://www.adventure-works.com}ProductName:Baby Monitor  
```

## [How to: Chain Axis Method Calls (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtochainaxismethodcallslinqtoxml)

一个在代码中常用的模式是调用轴方法，然后调用一个扩展方法轴。

有两个返回元素集合、名称为 `Elements` 的轴：[XContainer.Elements](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.elements) 方法和 [Extensions.Elements](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.extensions.elements) 方法。 可以合并这两个轴，在树的给定深度，查找具有指定名称的所有元素。

##### 示例

本示例使用 [XContainer.Elements](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.elements) 和 [Extensions.Elements](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.extensions.elements) 在所有 `Name` 元素中查找所有 `Address` 元素中的所有 `PurchaseOrder` 元素。

本示例使用下面的 XML 文档：[示例 XML 文件：多个采购订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-multiple-purchase-orders-linq-to-xml)。

```csharp
XElement purchaseOrders = XElement.Load("PurchaseOrders.xml");  
IEnumerable<XElement> names =  
    from el in purchaseOrders  
        .Elements("PurchaseOrder")  
        .Elements("Address")  
        .Elements("Name")  
    select el;  
foreach (XElement e in names)  
    Console.WriteLine(e);  
```

该示例产生下面的输出：

```xml
<Name>Ellen Adams</Name>  
<Name>Tai Yee</Name>  
<Name>Cristian Osorio</Name>  
<Name>Cristian Osorio</Name>  
<Name>Jessica Arnold</Name>  
<Name>Jessica Arnold</Name>  
```

此方法有效是因为其中有一个 `Elements` 轴实现充当 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的 [XContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer) 的扩展方法。 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 是从 [XContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer) 派生的，因此可以对调用 [Extensions.Elements](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.extensions.elements) 方法的结果调用 [XContainer.Elements](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.elements) 方法。

##### 示例

有时，当可能存在或不存在间隔上级时，您希望在特定的元素深度，检索所有的元素。 例如，在下面的文档中，您可能要检索属于 `ConfigParameter` 元素的子元素的所有 `Customer` 元素，而不是属于 `ConfigParameter` 元素的子元素的 `Root`。

```xml
<Root>  
  <ConfigParameter>RootConfigParameter</ConfigParameter>  
  <Customer>  
    <Name>Frank</Name>  
    <Config>  
      <ConfigParameter>FirstConfigParameter</ConfigParameter>  
    </Config>  
  </Customer>  
  <Customer>  
    <Name>Bob</Name>  
    <!--This customer doesn't have a Config element-->  
  </Customer>  
  <Customer>  
    <Name>Bill</Name>  
    <Config>  
      <ConfigParameter>SecondConfigParameter</ConfigParameter>  
    </Config>  
  </Customer>  
</Root>  
```

若要执行此操作，您可以使用 [Extensions.Elements](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.extensions.elements) 轴，如下所示：

```csharp
XElement root = XElement.Load("Irregular.xml");  
IEnumerable<XElement> configParameters =   
    root.Elements("Customer").Elements("Config").  
    Elements("ConfigParameter");  
foreach (XElement cp in configParameters)  
    Console.WriteLine(cp);  
```

该示例产生下面的输出：

```xml
<ConfigParameter>FirstConfigParameter</ConfigParameter>  
<ConfigParameter>SecondConfigParameter</ConfigParameter>  
```

##### 示例

下面的示例演示针对命名空间中的 XML 的相同技术。 有关详细信息，请参阅[使用 XML 命名空间 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/working-with-xml-namespaces)。

本示例使用下面的 XML 文档：[示例 XML 文件：命名空间中的多个采购订单](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-multiple-purchase-orders-in-a-namespace)。

```csharp
XNamespace aw = "http://www.adventure-works.com";  
XElement purchaseOrders = XElement.Load("PurchaseOrdersInNamespace.xml");  
IEnumerable<XElement> names =  
    from el in purchaseOrders  
        .Elements(aw + "PurchaseOrder")  
        .Elements(aw + "Address")  
        .Elements(aw + "Name")  
    select el;  
foreach (XElement e in names)  
    Console.WriteLine(e);  
```

该示例产生下面的输出：

```xml
<aw:Name xmlns:aw="http://www.adventure-works.com">Ellen Adams</aw:Name>  
<aw:Name xmlns:aw="http://www.adventure-works.com">Tai Yee</aw:Name>  
<aw:Name xmlns:aw="http://www.adventure-works.com">Cristian Osorio</aw:Name>  
<aw:Name xmlns:aw="http://www.adventure-works.com">Cristian Osorio</aw:Name>  
<aw:Name xmlns:aw="http://www.adventure-works.com">Jessica Arnold</aw:Name>  
<aw:Name xmlns:aw="http://www.adventure-works.com">Jessica Arnold</aw:Name>  
```

## [How to: Retrieve a Single Child Element (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoretrieveasinglechildelementlinqtoxml)

本主题说明如何在给定子元素名称的情况下检索单个子元素。 如果知道子元素的名称并且只有一个元素具有此名称，则只检索一个元素而不是一个集合会很方便。

[Element](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.element) 方法返回具有指定 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 的第一个子 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname)。

如果想要在 Visual Basic 中检索单个子元素，常用的方法是使用 XML 属性，然后使用数组索引器表示法检索第一个元素。

##### 示例

下面的示例演示 [Element](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.element) 方法的用法。 本示例采用名为 `po` 的 XML 树并查找名为 `Comment` 的第一个元素。

Visual Basic 示例演示如何使用数组索引器表示法来检索单个元素。

本示例使用下面的 XML 文档：[示例 XML 文件：典型采购订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-typical-purchase-order-linq-to-xml-1)。

```csharp
XElement po = XElement.Load("PurchaseOrder.xml");  
XElement e = po.Element("DeliveryNotes");  
Console.WriteLine(e);  
```

该示例产生下面的输出：

```xml
<DeliveryNotes>Please leave packages in shed by driveway.</DeliveryNotes>  
```

##### 示例

下面的示例演示如何对命名空间中的 XML 使用相同的代码。 有关详细信息，请参阅[使用 XML 命名空间 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/working-with-xml-namespaces)。

本示例使用下面的 XML 文档：[示例 XML 文件：命名空间中的典型采购单](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-typical-purchase-order-in-a-namespace)。

```csharp
XElement po = XElement.Load("PurchaseOrderInNamespace.xml");  
XNamespace aw = "http://www.adventure-works.com";  
XElement e = po.Element(aw + "DeliveryNotes");  
Console.WriteLine(e);  
```

该示例产生下面的输出：

```xml
<aw:DeliveryNotes xmlns:aw="http://www.adventure-works.com">Please leave packages in shed by driveway.</aw:DeliveryNotes>  
```

## [How to: Retrieve a Collection of Attributes (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoretrieveacollectionofattributeslinqtoxml)

本主题介绍 [Attributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.attributes) 方法。 此方法检索元素的属性。

##### 示例

下面的示例演示如何循环访问一个元素的属性集合。

```csharp
XElement val = new XElement("Value",  
    new XAttribute("ID", "1243"),  
    new XAttribute("Type", "int"),  
    new XAttribute("ConvertableTo", "double"),  
    "100");  
IEnumerable<XAttribute> listOfAttributes =  
    from att in val.Attributes()  
    select att;  
foreach (XAttribute a in listOfAttributes)  
    Console.WriteLine(a);  
```

此代码生成以下输出：

```
ID="1243"  
Type="int"  
ConvertableTo="double"  
```

## [How to: Retrieve a Single Attribute (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoretrieveasingleattributelinqtoxml)

本主题说明在给定属性名称的情况下，如何检索元素的单个属性。 这对于编写查询表达式查找具有特定属性的元素十分有用。

[Attribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.attribute) 类的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 方法返回具有指定名称的 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute)。

##### 示例

下面的示例使用 [Attribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.attribute) 方法。

```csharp
XElement cust = new XElement("PhoneNumbers",  
    new XElement("Phone",  
        new XAttribute("type", "home"),  
        "555-555-5555"),  
    new XElement("Phone",  
        new XAttribute("type", "work"),  
        "555-555-6666")  
);  
IEnumerable<XElement> elList =  
    from el in cust.Descendants("Phone")  
    select el;  
foreach (XElement el in elList)  
    Console.WriteLine((string)el.Attribute("type"));  
```

本示例首先在名为 `Phone` 的树中查找所有后代，然后查找名为 `type` 的属性。

此代码生成以下输出：

```
home  
work  
```

##### 示例

如果希望检索属性的值，可以强制转换该值，就像使用 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 对象时一样。 下面的示例演示这一操作。

```csharp
XElement cust = new XElement("PhoneNumbers",  
    new XElement("Phone",  
        new XAttribute("type", "home"),  
        "555-555-5555"),  
    new XElement("Phone",  
        new XAttribute("type", "work"),  
        "555-555-6666")  
);  
IEnumerable<XElement> elList =   
    from el in cust.Descendants("Phone")  
    select el;  
foreach (XElement el in elList)  
    Console.WriteLine((string)el.Attribute("type"));  
```

此代码生成以下输出：

```
home  
work  
```

LINQ to XML 为 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 类提供了以下类型的显式强制转换运算符：`string`、`bool`、`bool?`、`int`、`int?`、`uint`、`uint?`、`long`、`long?`、`ulong`、`ulong?`、`float`、`float?`、`double`、`double?`、`decimal`、`decimal?`、`DateTime`、`DateTime?`、`TimeSpan`、`TimeSpan?`、`GUID` 和 `GUID?`。

##### 示例

下面的示例显式命名空间中的属性的相同代码。 有关详细信息，请参阅[使用 XML 命名空间 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/working-with-xml-namespaces)。

```csharp
XNamespace aw = "http://www.adventure-works.com";  
XElement cust = new XElement(aw + "PhoneNumbers",  
    new XElement(aw + "Phone",  
        new XAttribute(aw + "type", "home"),  
        "555-555-5555"),  
    new XElement(aw + "Phone",  
        new XAttribute(aw + "type", "work"),  
        "555-555-6666")  
);  
IEnumerable<XElement> elList =  
    from el in cust.Descendants(aw + "Phone")  
    select el;  
foreach (XElement el in elList)  
    Console.WriteLine((string)el.Attribute(aw + "type"));  
```

此代码生成以下输出：

```
home  
work  
```

## [How to: Retrieve the Value of an Attribute (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoretrievethevalueofanattributelinqtoxml)

本主题说明如何获取属性的值。 主要有两种方法：可以将 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 强制转换为所需的类型；然后，显式转换运算符将元素或属性的内容转换为指定的类型。 此外，还可以使用 [Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute.value) 属性。 但是，强制转换通常是更好的方法。 在检索可能存在也可能不存在的属性的值时，如果将属性强制转换为可以为 null 的类型，则代码会更易于编写。 有关此技术的示例，请参见[如何：检索元素的值 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-retrieve-the-value-of-an-element-linq-to-xml)。

##### 示例

若要检索属性的值，只需将 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 对象强制转换为所需的类型即可。

```csharp
XElement root = new XElement("Root",  
                    new XAttribute("Attr", "abcde")  
                );  
Console.WriteLine(root);  
string str = (string)root.Attribute("Attr");  
Console.WriteLine(str);  
```

该示例产生下面的输出：



```
<Root Attr="abcde" />  
abcde  
```

##### 示例

下面的示例演示在属性处于命名空间中时，如何检索属性的值。 有关详细信息，请参阅[使用 XML 命名空间 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/working-with-xml-namespaces)。

```csharp
XNamespace aw = "http://www.adventure-works.com";  
XElement root = new XElement(aw + "Root",  
                    new XAttribute(aw + "Attr", "abcde")  
                );  
string str = (string)root.Attribute(aw + "Attr");  
Console.WriteLine(str);  
```

该示例产生下面的输出：

```
abcde  
```

## [How to: Retrieve the Shallow Value of an Element](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoretrievetheshallowvalueofanelement)

本主题说明如何获取元素的浅值。 浅值只是特定元素的值，与深值相反，包括串联成一个单一字符串的所有子元素的值。

使用强制转换或 [XElement.Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.value) 属性检索元素值时，您可以检索深值。 要检索浅值，可以使用 `ShallowValue` 扩展方法，如以下示例所示。 当根据内容选择元素时，检索浅值十分有用。

下面的示例声明了检索元素浅值的扩展方法。 然后在查询中使用该扩展方法列出包含计算得出的值的所有元素。

##### 示例

下面的文本文件 Report.xml 是此示例的源。

```xml
<?xml version="1.0" encoding="utf-8" ?>  
<Report>  
  <Section>  
    <Heading>  
      <Column Name="CustomerId">=Customer.CustomerId.Heading</Column>  
      <Column Name="Name">=Customer.Name.Heading</Column>  
    </Heading>  
    <Detail>  
      <Column Name="CustomerId">=Customer.CustomerId</Column>  
      <Column Name="Name">=Customer.Name</Column>  
    </Detail>  
  </Section>  
</Report>  
```

```csharp
public static class MyExtensions  
{  
    public static string ShallowValue(this XElement xe)  
    {  
        return xe  
               .Nodes()  
               .OfType<XText>()  
               .Aggregate(new StringBuilder(),  
                          (s, c) => s.Append(c),  
                          s => s.ToString());  
    }  
}  
  
class Program  
{  
    static void Main(string[] args)  
    {  
        XElement root = XElement.Load("Report.xml");  
  
        IEnumerable<XElement> query = from el in root.Descendants()  
                                      where el.ShallowValue().StartsWith("=")  
                                      select el;  
  
        foreach (var q in query)  
        {  
            Console.WriteLine("{0}{1}{2}",  
                q.Name.ToString().PadRight(8),  
                q.Attribute("Name").ToString().PadRight(20),  
                q.ShallowValue());  
        }  
    }  
}  
```

该示例产生下面的输出：

```
Column  Name="CustomerId"   =Customer.CustomerId.Heading  
Column  Name="Name"         =Customer.Name.Heading  
Column  Name="CustomerId"   =Customer.CustomerId  
Column  Name="Name"         =Customer.Name  
```