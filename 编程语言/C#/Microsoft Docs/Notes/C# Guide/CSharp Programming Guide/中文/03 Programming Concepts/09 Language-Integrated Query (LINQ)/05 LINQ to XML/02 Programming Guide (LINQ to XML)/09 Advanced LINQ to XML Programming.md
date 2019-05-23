# [Advanced LINQ to XML Programming](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/advancedlinqtoxmlprogramming)

本节为高级开发人员提供一些只适用于某些 LINQ to XML 方案的信息。

## 本节内容

| 主题                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [LINQ to XML 批注](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/linq-to-xml-annotations) | 介绍如何将批注添加到 LINQ to XML 节点和属性。                |
| [LINQ to XML 事件 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/linq-to-xml-events) | 介绍如何为更改 XML 树时所发生的事件编写事件处理程序。        |
| [使用节点进行编程 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/programming-with-nodes) | 介绍如何在比元素和属性更精细的粒度级别上查询和操作节点。     |
| [混合声明性代码/命令性代码的问题 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/mixed-declarative-code-imperative-code-bugs-linq-to-xml) | 介绍在混合声明性代码（查询）与命令性代码（修改 XML 树的代码）时所出现的问题。 |
| [如何：通过对标头信息的访问流式处理 XML 片段 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-stream-xml-fragments-with-access-to-header-information) | 介绍如何在 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 中对 XML 片段进行流式处理。 使用此技术，可以控制应用程序的内存需求量。 |
| [如何：执行大型 XML 文档的流式转换 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-perform-streaming-transform-of-large-xml-documents) | 介绍如何在 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 中对 XML 进行流式处理，如何转换 XML 片段，如何使用[XStreamingElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xstreamingelement) 对输出进行流式处理。 |
| [如何：读取和写入编码的文档 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-read-and-write-an-encoded-document) | 介绍如何读取和写入经过编码的 XML 文档。                      |
| [使用 XSLT 转换 XML 树 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/using-xslt-to-transform-an-xml-tree) | 介绍如何使用 XSLT 转换 XML 树。                              |
| [如何：使用批注转换 XSLT 样式中的 LINQ to XML 树 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-use-annotations-to-transform-linq-to-xml-trees-in-an-xslt-style) | 介绍如何使用批注来帮助进行 XML 树的转换。                    |
| [序列化包含 XElement 对象的对象图 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/serializing-object-graphs-that-contain-xelement-objects) | 介绍如何序列化包含 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 和 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 对象的对象图。 |
| [使用 LINQ to XML 进行 WPF 数据绑定](https://docs.microsoft.com/zh-cn/visualstudio/designers/wpf-data-binding-with-linq-to-xml) | 介绍如何将 LINQ to XML 用作 Windows Presentation Foundation 应用程序中数据绑定的数据源。 |

## [LINQ to XML Annotations](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/linqtoxmlannotations)

LINQ to XML 中的注释可将任意类型的任意对象与 XML 树中的任何 XML 组件相关联。

若要向 XML 组件（例如 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 或 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute)）中添加批注，需调用 [AddAnnotation](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobject.addannotation) 方法。 批注是按类型检索的。

请注意，批注不是 XML 信息集的一部分，不对它们进行序列化和反序列化。

### 方法

处理批注时可以使用以下方法：

| 方法                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [AddAnnotation](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobject.addannotation) | 向 [XObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobject) 的批注列表中添加对象。 |
| [Annotation](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobject.annotation) | 从 [XObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobject) 获取指定类型的第一个批注对象。 |
| [Annotations](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobject.annotations) | 获取 [XObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobject) 的指定类型的批注集合。 |

## [LINQ to XML Events](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/linqtoxmlevents)

LINQ to XML 事件使你可以在 XML 树发生改变时得到通知。

可以将事件添加到任何 [XObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobject) 的实例。 事件处理程序然后将接收对该 [XObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobject) 及其所有子代进行修改的事件。例如，可以将事件处理程序添加到树根，然后从该事件处理程序中处理对树进行的所有修改。

有关 LINQ to XML 事件的示例，请参阅 [Changing](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobject.changing) 和 [Changed](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobject.changed)。

### 类型和事件

在处理事件时使用下面的类型：

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [XObjectChange](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobjectchange) | 当 [XObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobject) 发生事件时指定事件类型。 |
| [XObjectChangeEventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobjectchangeeventargs) | 提供有关 [Changing](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobject.changing) 和 [Changed](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobject.changed) 事件的数据。 |

修改 XML 树时将引发以下事件：

| 事件                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [Changing](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobject.changing) | 在此 [XObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobject) 或它的任何子代即将发生更改之前发生。 |
| [Changed](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobject.changed) | 在 [XObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobject) 或它的任何子代已经更改时发生。 |

### 示例

#### 说明

当您希望在 XML 树中保留一些聚合信息时事件非常有用。 例如，您可能想保留一份发票合计，计算发票上各个项目的总和。 本示例使用事件来维护复杂元素 `Items` 之下所有子元素的总和。

#### 代码

```csharp
XElement root = new XElement("Root",  
    new XElement("Total", "0"),  
    new XElement("Items")  
);  
XElement total = root.Element("Total");  
XElement items = root.Element("Items");  
items.Changed += (object sender, XObjectChangeEventArgs cea) =>  
{  
    switch (cea.ObjectChange)  
    {  
        case XObjectChange.Add:  
            if (sender is XElement)  
                total.Value = ((int)total + (int)(XElement)sender).ToString();  
            if (sender is XText)  
                total.Value = ((int)total + (int)((XText)sender).Parent).ToString();  
            break;  
        case XObjectChange.Remove:  
            if (sender is XElement)  
                total.Value = ((int)total - (int)(XElement)sender).ToString();  
            if (sender is XText)  
                total.Value = ((int)total - Int32.Parse(((XText)sender).Value)).ToString();  
            break;  
    }  
    Console.WriteLine("Changed {0} {1}",  
      sender.GetType().ToString(), cea.ObjectChange.ToString());  
};  
items.SetElementValue("Item1", 25);  
items.SetElementValue("Item2", 50);  
items.SetElementValue("Item2", 75);  
items.SetElementValue("Item3", 133);  
items.SetElementValue("Item1", null);  
items.SetElementValue("Item4", 100);  
Console.WriteLine("Total:{0}", (int)total);  
Console.WriteLine(root);  
```

#### 注释

此代码生成以下输出：

```
Changed System.Xml.Linq.XElement Add  
Changed System.Xml.Linq.XElement Add  
Changed System.Xml.Linq.XText Remove  
Changed System.Xml.Linq.XText Add  
Changed System.Xml.Linq.XElement Add  
Changed System.Xml.Linq.XElement Remove  
Changed System.Xml.Linq.XElement Add  
Total:308  
<Root>  
  <Total>308</Total>  
  <Items>  
    <Item2>75</Item2>  
    <Item3>133</Item3>  
    <Item4>100</Item4>  
  </Items>  
</Root>  
```

## [Programming with Nodes](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/programmingwithnodes)

需要编写 XML 编辑器、转换系统或报告编写器这类程序的 LINQ to XML 开发人员通常需要编写在比元素和属性更细的粒度下运行的程序。 开发人员通常需要在节点级别上工作，操作文本节点、处理指令和添加注释。 本主题提供有关在节点级别进行编程的一些详细信息。

### 节点详细信息

在节点级别上工作的程序员需要了解有关编程的许多细节。

#### XDocument 的子节点的父属性设置为 Null

[Parent](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobject.parent) 属性包含父 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)，而不是父节点。 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 的子节点没有父 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)。 它们的父级是文档，因此这些节点的 [Parent](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xobject.parent) 属性设置为 null。

下面的示例演示这一操作：

```csharp
XDocument doc = XDocument.Parse(@"<!-- a comment --><Root/>");  
Console.WriteLine(doc.Nodes().OfType<XComment>().First().Parent == null);  
Console.WriteLine(doc.Root.Parent == null);  
```

该示例产生下面的输出：

```
True  
True  
```

#### 可以存在相邻文本节点

在许多 XML 编程模型中，相邻的文本节点始终会合并到一起。 这有时也称为文本节点的规范化。 LINQ to XML 不规范化文本节点。 如果向同一个元素添加两个文本节点，则会产生相邻文本节点。 但如果将指定内容添加为字符串而不是 [XText](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xtext) 节点，则 LINQ to XML 可能会将该字符串与相邻的文本节点合并在一起。

下面的示例演示这一操作：

```csharp
XElement xmlTree = new XElement("Root", "Content");  
  
Console.WriteLine(xmlTree.Nodes().OfType<XText>().Count());  
  
// this does not add a new text node  
xmlTree.Add("new content");  
Console.WriteLine(xmlTree.Nodes().OfType<XText>().Count());  
  
// this does add a new, adjacent text node  
xmlTree.Add(new XText("more text"));  
Console.WriteLine(xmlTree.Nodes().OfType<XText>().Count());  
```

该示例产生下面的输出：

```
1  
1  
2  
```

### 可以存在空文本节点

在某些 XML 编程模型中，文本节点保证不包含空字符串。 原因是这种文本节点对 XML 的序列化没有影响。 但由于可以存在相邻文本节点这一相同的原因，如果您通过将文本节点的值设置为空字符串来移除文本节点中的文本，则不会删除文本节点本身。

```csharp
XElement xmlTree = new XElement("Root", "Content");  
XText textNode = xmlTree.Nodes().OfType<XText>().First();  
  
// the following line does not cause the removal of the text node.  
textNode.Value = "";  
  
XText textNode2 = xmlTree.Nodes().OfType<XText>().First();  
Console.WriteLine(">>{0}<<", textNode2);   
```

该示例产生下面的输出：

```
>><<  
```

### 空文本节点影响序列化

如果一个元素仅包含一个空的子文本节点，则会用长标记语法序列化该元素：`<Child></Child>`。 如果一个元素不包含任何子节点，则会用短标记语法序列化该元素：`<Child />`。

```csharp
XElement child1 = new XElement("Child1",  
    new XText("")  
);  
XElement child2 = new XElement("Child2");  
Console.WriteLine(child1);  
Console.WriteLine(child2);   
```

该示例产生下面的输出：

```xml
<Child1></Child1>  
<Child2 />  
```

### 命名空间是 LINQ to XML 树中的属性

即使命名空间声明与特性具有完全相同的语法，在某些编程接口（如 XSLT 和 XPath）中，也不会将命名空间声明视为属性。 但在 LINQ to XML 中，命名空间存储为 XML 树中的 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 对象。 如果您循环访问包含命名空间声明的元素的属性，则会在返回的集合中看到作为一项列出的命名空间声明。

[IsNamespaceDeclaration](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute.isnamespacedeclaration) 属性 (property) 指示某一属性 (attribute) 是否为命名空间声明。

```csharp
XElement root = XElement.Parse(  
@"<Root  
    xmlns='http://www.adventure-works.com'  
    xmlns:fc='www.fourthcoffee.com'  
    AnAttribute='abc'/>");  
foreach (XAttribute att in root.Attributes())  
    Console.WriteLine("{0}  IsNamespaceDeclaration:{1}", att, att.IsNamespaceDeclaration);  
```

该示例产生下面的输出：

```
xmlns="http://www.adventure-works.com"  IsNamespaceDeclaration:True  
xmlns:fc="www.fourthcoffee.com"  IsNamespaceDeclaration:True  
AnAttribute="abc"  IsNamespaceDeclaration:False  
```

### XPath 轴方法不返回 XDocument 的子空白

LINQ to XML 允许 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 具有子文本节点，但这些文本节点只能包含空白。 不过，XPath 对象模型没有将空白符添加为文档子节点。因此，如果使用 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 轴循环访问 [Nodes](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.nodes) 的子级，将会返回空白符文本节点。 然而，如果使用 XPath 轴方法循环访问 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 的子级，就不会返回空白符文本节点。

```csharp
// Create a document with some white-space child nodes of the document.  
XDocument root = XDocument.Parse(  
@"<?xml version='1.0' encoding='utf-8' standalone='yes'?>  
  
<Root/>  
  
<!--a comment-->  
", LoadOptions.PreserveWhitespace);  
  
// count the white-space child nodes using LINQ to XML  
Console.WriteLine(root.Nodes().OfType<XText>().Count());  
  
// count the white-space child nodes using XPathEvaluate  
Console.WriteLine(((IEnumerable)root.XPathEvaluate("text()")).OfType<XText>().Count());   
```

该示例产生下面的输出：

```
3  
0  
```

### XDeclaration 对象不是节点

在循环访问 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 的子节点时，将看不到 XML 声明对象。 它是文档的属性，不是文档的子节点。

```csharp
XDocument doc = new XDocument(  
    new XDeclaration("1.0", "utf-8", "yes"),  
    new XElement("Root")  
);  
doc.Save("Temp.xml");  
Console.WriteLine(File.ReadAllText("Temp.xml"));  
  
// this shows that there is only one child node of the document  
Console.WriteLine(doc.Nodes().Count());  
```

该示例产生下面的输出：

```
<?xml version="1.0" encoding="utf-8" standalone="yes"?>  
<Root />  
1  
```

## [Mixed Declarative CodeImperative Code Bugs (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/mixeddeclarativecodeimperativecodebugslinqtoxml)

LINQ to XML 包含各种不同的方法，使您能够直接修改 XML 树。 您可以添加元素、删除元素、更改元素的内容、添加属性等等。 在[修改 XML 树 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/modifying-xml-trees-linq-to-xml) 中详细介绍了此编程接口。 如果循环访问一个轴，例如[Elements](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.elements)，而在循环访问该轴时正在修改 XML 树，那么可能会发生一些异常问题。

此问题有时称为“万圣节问题”。

### 问题的定义

如果你使用 LINQ 编写循环访问集合的代码，那么你是以声明性风格在编写代码。 这种风格更像是描述要实现的内容，而不是描述所需要的实现方式。 如果你编写的代码要执行以下操作：1) 获取第一个元素；2) 测试该元素是否符合某种条件；3) 修改该元素；4) 将该元素放回列表中。那么，此代码就是命令性代码。 你是在告诉计算机希望以何种方式完成任务。

在同一操作中混合这些代码风格正是导致问题的原因。 考虑以下情况：

假设您有一个链接列表，其中有三个项（a、b 和 c）：

```
a -> b -> c
```

现在，假设您想在链接列表中移动，并添加三个新项（a'、b' 和 c'）。 您希望生成如下所示的链接列表：

```
a -> a' -> b -> b' -> c -> c'
```

因此您编写代码来循环访问该列表，在每一项后面紧接着添加一个新项。 而实际发生的情况是，您的代码首先将看到 `a` 元素，然后在它后面插入 `a'`。 现在，您的代码将移动到列表中的下一节点，此时下一节点是 `a'`！ 它会不假思索地向列表中添加一个新项 `a''`。

在实际中该如何解决这一问题？ 您可以创建原始链接列表的副本，然后创建一个全新的列表。 或者，如果您正在编写纯粹的命令性代码，您可以找到第一项，添加新项，然后在链接列表中前进两步，跳过刚添加的元素。

### 循环访问时添加

例如，假设您希望编写一段代码，让它为树中的每个元素创建一个重复的元素：

```csharp
XElement root = new XElement("Root",  
    new XElement("A", "1"),  
    new XElement("B", "2"),  
    new XElement("C", "3")  
);  
foreach (XElement e in root.Elements())  
    root.Add(new XElement(e.Name, (string)e));  
```

此代码将进入一个无限循环。 `foreach` 语句循环访问 `Elements()` 轴，将新元素添加到 `doc` 元素。 结果它也循环访问刚添加的元素。 由于它在每次循环访问中都分配新对象，最终将会耗尽所有可用内存。

可以通过使用 [ToList](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.tolist) 标准查询运算符将集合放入内存来修复此问题，如下所示：

```csharp
XElement root = new XElement("Root",  
    new XElement("A", "1"),  
    new XElement("B", "2"),  
    new XElement("C", "3")  
);  
foreach (XElement e in root.Elements().ToList())  
    root.Add(new XElement(e.Name, (string)e));  
Console.WriteLine(root);  
```

现在代码可以正常工作了。 生成的 XML 树如下所示：

```xml
<Root>  
  <A>1</A>  
  <B>2</B>  
  <C>3</C>  
  <A>1</A>  
  <B>2</B>  
  <C>3</C>  
</Root>  
```

### 循环访问时删除

如果想要删除某一级别上的所有节点，您可能立即想到编写类似如下所示的代码：

```csharp
XElement root = new XElement("Root",  
    new XElement("A", "1"),  
    new XElement("B", "2"),  
    new XElement("C", "3")  
);  
foreach (XElement e in root.Elements())  
    e.Remove();  
Console.WriteLine(root);  
```

然而，此代码执行起来不会如您所愿。 在这种情况下，在移除第一个元素 A 之后，将从包含在根中的 XML 树中移除该元素，Elements 方法中执行循环访问的代码将找不到下一个元素。

前面的代码产生以下输出：

```xml
<Root>  
  <B>2</B>  
  <C>3</C>  
</Root>  
```

解决方法仍是调用 [ToList](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.tolist) 来具体化集合，如下所示：

```csharp
XElement root = new XElement("Root",  
    new XElement("A", "1"),  
    new XElement("B", "2"),  
    new XElement("C", "3")  
);  
foreach (XElement e in root.Elements().ToList())  
    e.Remove();  
Console.WriteLine(root);  
```

此代码产生以下输出：

```xml
<Root />  
```

或者，可以通过对父元素调用 [RemoveAll](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.removeall) 来完全消除循环：

```csharp
XElement root = new XElement("Root",  
    new XElement("A", "1"),  
    new XElement("B", "2"),  
    new XElement("C", "3")  
);  
root.RemoveAll();  
Console.WriteLine(root);  
```

### 为何 LINQ 不能自动处理此问题？

一种方法是总是将所有内容放入内存，而不是执行迟缓计算。 但是，在性能和内存使用方面，这种方法开销非常大。 事实上，如果 LINQ 和 (LINQ to XML) 采用此方法，在实际情况中将会失败。

另一种可能的方法是将某种事务语法放入 LINQ，让编译器尝试分析代码并确定是否需要具体化任何特定的集合。但是，尝试确定具有副作用的所有代码将会非常复杂。 考虑下列代码：

```csharp
var z =  
    from e in root.Elements()  
    where TestSomeCondition(e)  
    select DoMyProjection(e);  
```

这种分析代码需要分析 TestSomeCondition 和 DoMyProjection 方法，以及这些方法调用的所有方法，以此来确定是否有任何代码会产生副作用。 但是，分析代码不能简单地查找所有具有副作用的代码。 在此情况下，它需要选择只对 `root` 的子元素具有副作用的代码。

LINQ to XML 不会尝试进行任何这样的分析。

因此，避免这些问题就靠您了。

### 指导

首先，不要将声明性代码和命令性代码混合。

即便您确切知道您的集合的语义以及修改 XML 树的方法的语义，可以更巧妙地编写代码来避免这类问题，但您的代码将来需要由其他开发人员来维护，而他们可能并不像您那样清楚这些问题。 如果混合使用声明性和命令性编码风格，您的代码将更加脆弱。

如果您编写代码将集合具体化从而避免这些问题，应在代码中适当加以注释，使负责维护的程序员能够了解问题所在。

其次，在性能和其他因素允许的情况下，仅使用声明性代码。 不要修改现有的 XML 树， 而是生成一个新树。

```csharp
XElement root = new XElement("Root",  
    new XElement("A", "1"),  
    new XElement("B", "2"),  
    new XElement("C", "3")  
);  
XElement newRoot = new XElement("Root",  
    root.Elements(),  
    root.Elements()  
);  
Console.WriteLine(newRoot);  
```

## [How to: Stream XML Fragments with Access to Header Information](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtostreamxmlfragmentswithaccesstoheaderinformation)

有时，您必须读取任意大的 XML 文件并在编写您的应用程序时可以预测应用程序的内存需求量。 如果您试图用大 XML 文件填充 XML 树，则内存占用量将与文件大小成正比，也就是说会占用过多内存。 因此，您应改用流处理技术。

一种选择是使用 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 来编写应用程序。 但您可能需要使用 LINQ 来查询 XML 树。 在这种情况下，您可以编写自己的自定义轴方法。 有关详细信息，请参阅[如何：编写 LINQ to XML 轴方法 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-write-a-linq-to-xml-axis-method)。

若要编写您自己的轴方法，请编写一个小方法，让该方法使用 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 来读取各个节点，直到达到您感兴趣的节点之一。 该方法然后调用 [ReadFrom](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.readfrom)，后者将从 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 中读取数据并实例化 XML 片段。 然后，该方法生成从 `yield return` 到该方法（枚举您的自定义轴方法的方法）的每个片段。 然后，您可以对自定义轴方法编写 LINQ 查询。

流处理技术最适合只需处理一次源文档的情况，您可以按文档顺序处理各个元素。 某些标准查询运算符（如[OrderBy](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.orderby)）可以循环访问其源、收集所有数据、对数据排序，最后生成序列中的第一项。 请注意，如果使用可在生成第一项之前具体化源的查询运算符，则不会保持小的内存需求量。

### 示例

有时，问题会变得更有意思。 在下面的 XML 文档中，自定义轴方法的使用方也必须知道每一项所属的使用方名称。

```xml
<?xml version="1.0" encoding="utf-8" ?>  
<Root>  
  <Customer>  
    <Name>A. Datum Corporation</Name>  
    <Item>  
      <Key>0001</Key>  
    </Item>  
    <Item>  
      <Key>0002</Key>  
    </Item>  
    <Item>  
      <Key>0003</Key>  
    </Item>  
    <Item>  
      <Key>0004</Key>  
    </Item>  
  </Customer>  
  <Customer>  
    <Name>Fabrikam, Inc.</Name>  
    <Item>  
      <Key>0005</Key>  
    </Item>  
    <Item>  
      <Key>0006</Key>  
    </Item>  
    <Item>  
      <Key>0007</Key>  
    </Item>  
    <Item>  
      <Key>0008</Key>  
    </Item>  
  </Customer>  
  <Customer>  
    <Name>Southridge Video</Name>  
    <Item>  
      <Key>0009</Key>  
    </Item>  
    <Item>  
      <Key>0010</Key>  
    </Item>  
  </Customer>  
</Root>  
```

本示例采用的方法还将监视此标头信息、保存标头信息，然后生成包含标头信息和所要枚举的详细信息的小型 XML 树。 该轴方法然后生成这个新的小型 XML 树。 之后，查询将可以访问标头信息以及详细信息。

此方法具有小的内存需求量。 由于生成了所有的详细 XML 片段，不再需要保留对前一个片段的引用，因此，此方法可用于垃圾回收。 请注意，此技术会在堆上创建许多短生存期的对象。

下面的示例演示如何实现和使用可流处理由 URI 指定的文件中的 XML 片段的自定义轴方法。 此自定义轴经过专门编写，可以处理具有 `Customer`、`Name` 和 `Item` 元素，并且这些元素按上述 `Source.xml` 文档排列的文档。 这是一个过于简单的实现。 将会准备一个更可靠的实现以分析无效文档。

```csharp
static IEnumerable<XElement> StreamCustomerItem(string uri)  
{  
    using (XmlReader reader = XmlReader.Create(uri))  
    {  
        XElement name = null;  
        XElement item = null;  
  
        reader.MoveToContent();  
  
        // Parse the file, save header information when encountered, and yield the  
        // Item XElement objects as they are created.  
  
        // loop through Customer elements  
        while (reader.Read())  
        {  
            if (reader.NodeType == XmlNodeType.Element  
                && reader.Name == "Customer")  
            {  
                // move to Name element  
                while (reader.Read())  
                {  
                    if (reader.NodeType == XmlNodeType.Element &&  
                        reader.Name == "Name")  
                    {  
                        name = XElement.ReadFrom(reader) as XElement;  
                        break;  
                    }  
                }  
  
                // loop through Item elements  
                while (reader.Read())  
                {  
                    if (reader.NodeType == XmlNodeType.EndElement)  
                        break;  
                    if (reader.NodeType == XmlNodeType.Element  
                        && reader.Name == "Item")  
                    {  
                        item = XElement.ReadFrom(reader) as XElement;  
                        if (item != null) {  
                            XElement tempRoot = new XElement("Root",  
                                new XElement(name)  
                            );  
                            tempRoot.Add(item);  
                            yield return item;  
                        }  
                    }  
                }  
            }  
        }  
    }  
}  
  
static void Main(string[] args)  
{  
    XElement xmlTree = new XElement("Root",  
        from el in StreamCustomerItem("Source.xml")  
        where (int)el.Element("Key") >= 3 && (int)el.Element("Key") <= 7  
        select new XElement("Item",  
            new XElement("Customer", (string)el.Parent.Element("Name")),  
            new XElement(el.Element("Key"))  
        )  
    );  
    Console.WriteLine(xmlTree);  
}  
```

此代码生成以下输出：

```xml
<Root>  
  <Item>  
    <Customer>A. Datum Corporation</Customer>  
    <Key>0003</Key>  
  </Item>  
  <Item>  
    <Customer>A. Datum Corporation</Customer>  
    <Key>0004</Key>  
  </Item>  
  <Item>  
    <Customer>Fabrikam, Inc.</Customer>  
    <Key>0005</Key>  
  </Item>  
  <Item>  
    <Customer>Fabrikam, Inc.</Customer>  
    <Key>0006</Key>  
  </Item>  
  <Item>  
    <Customer>Fabrikam, Inc.</Customer>  
    <Key>0007</Key>  
  </Item>  
</Root>  
```

## [How to: Perform Streaming Transform of Large XML Documents](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoperformstreamingtransformoflargexmldocuments)

有时，你必须转换任意大的 XML 文件并在编写你的应用程序时可以预测应用程序的内存需求量。 如果您试图用大 XML 文件填充 XML 树，则内存占用量将与文件大小成正比，也就是说会占用过多内存。 因此，您应改用流处理技术。

流处理技术最适合只需处理一次源文档的情况，您可以按文档顺序处理各个元素。 某些标准查询运算符（如[OrderBy](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.orderby)）可以循环访问其源、收集所有数据、对数据排序，最后生成序列中的第一项。 请注意，如果使用可在生成第一项之前具体化源的查询运算符，则不会使应用程序保持小的内存需求量。

即使使用[如何：通过对标头信息的访问流式处理 XML 片段 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-stream-xml-fragments-with-access-to-header-information) 中说明的技术，在试图装配包含转换的文档的 XML 树时，内存占用量也会过大。

主要方法有两种。 一种方法是使用 [XStreamingElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xstreamingelement) 的延迟处理特性。 另一种方法是创建一个 [XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwriter) 并使用 LINQ to XML 的功能将元素写入 [XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwriter)。 本主题演示这两种方法。

### 示例

以下示例基于[如何：通过对标头信息的访问流式处理 XML 片段 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-stream-xml-fragments-with-access-to-header-information) 中的示例。

本示例使用 [XStreamingElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xstreamingelement) 的延迟执行功能对输出进行流式处理。 本示例可在保持很小的内存需求量的同时转换非常大的文档。

请注意，自定义轴 (`StreamCustomerItem`) 经过专门编写，可以处理具有 `Customer`、`Name` 和 `Item` 元素，并且这些元素将按下面 Source.xml 文档排列的文档。 不过，将会准备一个更可靠的实现以分析无效文档。

下面是源文档 Source.xml：

```xml
<?xml version="1.0" encoding="utf-8" ?>   
<Root>  
  <Customer>  
    <Name>A. Datum Corporation</Name>  
    <Item>  
      <Key>0001</Key>  
    </Item>  
    <Item>  
      <Key>0002</Key>  
    </Item>  
    <Item>  
      <Key>0003</Key>  
    </Item>  
    <Item>  
      <Key>0004</Key>  
    </Item>  
  </Customer>  
  <Customer>  
    <Name>Fabrikam, Inc.</Name>  
    <Item>  
      <Key>0005</Key>  
    </Item>  
    <Item>  
      <Key>0006</Key>  
    </Item>  
    <Item>  
      <Key>0007</Key>  
    </Item>  
    <Item>  
      <Key>0008</Key>  
    </Item>  
  </Customer>  
  <Customer>  
    <Name>Southridge Video</Name>  
    <Item>  
      <Key>0009</Key>  
    </Item>  
    <Item>  
      <Key>0010</Key>  
    </Item>  
  </Customer>  
</Root>  
```

```csharp
static IEnumerable<XElement> StreamCustomerItem(string uri)  
{  
    using (XmlReader reader = XmlReader.Create(uri))  
    {  
        XElement name = null;  
        XElement item = null;  
  
        reader.MoveToContent();  
  
        // Parse the file, save header information when encountered, and yield the  
        // Item XElement objects as they are created.  
  
        // loop through Customer elements  
        while (reader.Read())  
        {  
            if (reader.NodeType == XmlNodeType.Element  
                && reader.Name == "Customer")  
            {  
                // move to Name element  
                while (reader.Read())  
                {  
                    if (reader.NodeType == XmlNodeType.Element &&  
                        reader.Name == "Name")  
                    {  
                        name = XElement.ReadFrom(reader) as XElement;  
                        break;  
                    }  
                }  
  
                // loop through Item elements  
                while (reader.Read())  
                {  
                    if (reader.NodeType == XmlNodeType.EndElement)  
                        break;  
                    if (reader.NodeType == XmlNodeType.Element  
                        && reader.Name == "Item")  
                    {  
                        item = XElement.ReadFrom(reader) as XElement;  
                        if (item != null)  
                        {  
                            XElement tempRoot = new XElement("Root",  
                                new XElement(name)  
                            );  
                            tempRoot.Add(item);  
                            yield return item;  
                        }  
                    }  
                }  
            }  
        }  
    }  
}  
  
static void Main(string[] args)  
{  
    XStreamingElement root = new XStreamingElement("Root",  
        from el in StreamCustomerItem("Source.xml")  
        select new XElement("Item",  
            new XElement("Customer", (string)el.Parent.Element("Name")),  
            new XElement(el.Element("Key"))  
        )  
    );  
    root.Save("Test.xml");  
    Console.WriteLine(File.ReadAllText("Test.xml"));  
}  
```

此代码生成以下输出：

```xml
<?xml version="1.0" encoding="utf-8"?>  
<Root>  
  <Item>  
    <Customer>A. Datum Corporation</Customer>  
    <Key>0001</Key>  
  </Item>  
  <Item>  
    <Customer>A. Datum Corporation</Customer>  
    <Key>0002</Key>  
  </Item>  
  <Item>  
    <Customer>A. Datum Corporation</Customer>  
    <Key>0003</Key>  
  </Item>  
  <Item>  
    <Customer>A. Datum Corporation</Customer>  
    <Key>0004</Key>  
  </Item>  
  <Item>  
    <Customer>Fabrikam, Inc.</Customer>  
    <Key>0005</Key>  
  </Item>  
  <Item>  
    <Customer>Fabrikam, Inc.</Customer>  
    <Key>0006</Key>  
  </Item>  
  <Item>  
    <Customer>Fabrikam, Inc.</Customer>  
    <Key>0007</Key>  
  </Item>  
  <Item>  
    <Customer>Fabrikam, Inc.</Customer>  
    <Key>0008</Key>  
  </Item>  
  <Item>  
    <Customer>Southridge Video</Customer>  
    <Key>0009</Key>  
  </Item>  
  <Item>  
    <Customer>Southridge Video</Customer>  
    <Key>0010</Key>  
  </Item>  
</Root>  
```

### 示例

以下示例也基于[如何：通过对标头信息的访问流式处理 XML 片段 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-stream-xml-fragments-with-access-to-header-information) 中的示例。

本示例使用 LINQ to XML 的功能将元素写入 [XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwriter)。 本示例可在保持很小的内存需求量的同时转换非常大的文档。

请注意，自定义轴 (`StreamCustomerItem`) 经过专门编写，可以处理具有 `Customer`、`Name` 和 `Item` 元素，并且这些元素将按下面 Source.xml 文档排列的文档。 不过，更可靠的实现将会使用 XSD 验证源文档或将会准备一个更可靠的实现以分析无效文档。

本示例与本主题中的前一示例使用同一个源文档 Source.xml。 它也生成完全相同的输出。

使用 [XStreamingElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xstreamingelement) 对输出 XML 进行流式处理胜于写入到 [XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwriter)。

```csharp
static IEnumerable<XElement> StreamCustomerItem(string uri)  
{  
    using (XmlReader reader = XmlReader.Create(uri))  
    {  
        XElement name = null;  
        XElement item = null;  
  
        reader.MoveToContent();  
  
        // Parse the file, save header information when encountered, and yield the  
        // Item XElement objects as they are created.  
  
        // loop through Customer elements  
        while (reader.Read())  
        {  
            if (reader.NodeType == XmlNodeType.Element  
                && reader.Name == "Customer")  
            {  
                // move to Name element  
                while (reader.Read())  
                {  
                    if (reader.NodeType == XmlNodeType.Element &&  
                        reader.Name == "Name")  
                    {  
                        name = XElement.ReadFrom(reader) as XElement;  
                        break;  
                    }  
                }  
  
                // loop through Item elements  
                while (reader.Read())  
                {  
                    if (reader.NodeType == XmlNodeType.EndElement)  
                        break;  
                    if (reader.NodeType == XmlNodeType.Element  
                        && reader.Name == "Item")  
                    {  
                        item = XElement.ReadFrom(reader) as XElement;  
                        if (item != null) {  
                            XElement tempRoot = new XElement("Root",  
                                new XElement(name)  
                            );  
                            tempRoot.Add(item);  
                            yield return item;  
                        }  
                    }  
                }  
            }  
        }  
    }  
}  
  
static void Main(string[] args)  
{  
    IEnumerable<XElement> srcTree =  
        from el in StreamCustomerItem("Source.xml")  
        select new XElement("Item",  
            new XElement("Customer", (string)el.Parent.Element("Name")),  
            new XElement(el.Element("Key"))  
        );  
    XmlWriterSettings xws = new XmlWriterSettings();  
    xws.OmitXmlDeclaration = true;  
    xws.Indent = true;  
    using (XmlWriter xw = XmlWriter.Create("Output.xml", xws)) {  
        xw.WriteStartElement("Root");  
        foreach (XElement el in srcTree)  
            el.WriteTo(xw);  
        xw.WriteEndElement();  
    }  
  
    string str = File.ReadAllText("Output.xml");  
    Console.WriteLine(str);  
}  
```

此代码生成以下输出：

```xml
<Root>  
  <Item>  
    <Customer>A. Datum Corporation</Customer>  
    <Key>0001</Key>  
  </Item>  
  <Item>  
    <Customer>A. Datum Corporation</Customer>  
    <Key>0002</Key>  
  </Item>  
  <Item>  
    <Customer>A. Datum Corporation</Customer>  
    <Key>0003</Key>  
  </Item>  
  <Item>  
    <Customer>A. Datum Corporation</Customer>  
    <Key>0004</Key>  
  </Item>  
  <Item>  
    <Customer>Fabrikam, Inc.</Customer>  
    <Key>0005</Key>  
  </Item>  
  <Item>  
    <Customer>Fabrikam, Inc.</Customer>  
    <Key>0006</Key>  
  </Item>  
  <Item>  
    <Customer>Fabrikam, Inc.</Customer>  
    <Key>0007</Key>  
  </Item>  
  <Item>  
    <Customer>Fabrikam, Inc.</Customer>  
    <Key>0008</Key>  
  </Item>  
  <Item>  
    <Customer>Southridge Video</Customer>  
    <Key>0009</Key>  
  </Item>  
  <Item>  
    <Customer>Southridge Video</Customer>  
    <Key>0010</Key>  
  </Item>  
</Root>  
```

## [How to: Read and Write an Encoded Document](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoreadandwriteanencodeddocument)

若要创建编码的 XML 文档，请向 XML 树中添加一个 [XDeclaration](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdeclaration)，将编码设置为需要的代码页名称。

由 [WebName](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.encoding.webname) 返回的任何值都是有效值。

如果您读取编码的文档，则要将 [Encoding](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdeclaration.encoding) 属性设置为该代码页名称。

如果将 [Encoding](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdeclaration.encoding) 设置为一个有效的代码页名称，则 LINQ to XML 将用指定的编码进行序列化。

### 示例

下面的示例创建两个文档，一个文档使用 utf-8 编码，另一个使用 utf-16 编码。 然后，该示例加载这两个文档并将编码输出到控制台。

```csharp
Console.WriteLine("Creating a document with utf-8 encoding");  
XDocument encodedDoc8 = new XDocument(  
    new XDeclaration("1.0", "utf-8", "yes"),  
    new XElement("Root", "Content")  
);  
encodedDoc8.Save("EncodedUtf8.xml");  
Console.WriteLine("Encoding is:{0}", encodedDoc8.Declaration.Encoding);  
Console.WriteLine();  
  
Console.WriteLine("Creating a document with utf-16 encoding");  
XDocument encodedDoc16 = new XDocument(  
    new XDeclaration("1.0", "utf-16", "yes"),  
    new XElement("Root", "Content")  
);  
encodedDoc16.Save("EncodedUtf16.xml");  
Console.WriteLine("Encoding is:{0}", encodedDoc16.Declaration.Encoding);  
Console.WriteLine();  
  
XDocument newDoc8 = XDocument.Load("EncodedUtf8.xml");  
Console.WriteLine("Encoded document:");  
Console.WriteLine(File.ReadAllText("EncodedUtf8.xml"));  
Console.WriteLine();  
Console.WriteLine("Encoding of loaded document is:{0}", newDoc8.Declaration.Encoding);  
Console.WriteLine();  
  
XDocument newDoc16 = XDocument.Load("EncodedUtf16.xml");  
Console.WriteLine("Encoded document:");  
Console.WriteLine(File.ReadAllText("EncodedUtf16.xml"));  
Console.WriteLine();  
Console.WriteLine("Encoding of loaded document is:{0}", newDoc16.Declaration.Encoding);  
```

该示例产生下面的输出：

```
Creating a document with utf-8 encoding  
Encoding is:utf-8  
  
Creating a document with utf-16 encoding  
Encoding is:utf-16  
  
Encoded document:  
<?xml version="1.0" encoding="utf-8" standalone="yes"?>  
<Root>Content</Root>  
  
Encoding of loaded document is:utf-8  
  
Encoded document:  
<?xml version="1.0" encoding="utf-16" standalone="yes"?>  
<Root>Content</Root>  
  
Encoding of loaded document is:utf-16  
```

## [Using XSLT to Transform an XML Tree](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/usingxslttotransformanxmltree)

可以创建 XML 树，从 XML 树创建 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader)，创建新文档，然后创建 [XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwriter)，以写入新文档。 然后，您可以调用 XSLT 转换，并可以将 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 和 [XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwriter) 传递到转换中。 在转换成功完成后，使用转换的结果，填充新的 XML 树。

### 示例

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
using (XmlWriter writer = newTree.CreateWriter()) {  
    // Load the style sheet.  
    XslCompiledTransform xslt = new XslCompiledTransform();  
    xslt.Load(XmlReader.Create(new StringReader(xslMarkup)));  
  
    // Execute the transform and output the results to a writer.  
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

## [How to: Use Annotations to Transform LINQ to XML Trees in an XSLT Style](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtouseannotationstotransformlinqtoxmltreesinanxsltstyle)

使用批注可帮助进行 XML 树的转换。

有些 XML 文档“以文档为中心兼有混合内容”。 对于这样的文档，您不必知道元素的子节点的形状。 例如，包含文本的节点可能具有像下面这样的外观：

```xml
<text>A phrase with <b>bold</b> and <i>italic</i> text.</text>  
```

任何给定的文本节点都可以具有任意数量的子 `<b>` 和 `<i>` 元素。 此方法可扩展到很多其他情况：如页面可以包含各种子元素（如规则段落、带项目符号的段落和位图）。 表中的单元格可以包含文本，下拉列表或位图。 以文档为中心的 XML 的一个主要特性是您不必知道任一特定元素将具有哪些子元素。

如果在转换树中的元素时不必知道有关要转换元素的子级的太多信息，则这种方法（使用批注）就是一种有效的方法。

这种方法摘要如下：

- 首先，用替换元素批注树中的元素。
- 然后，循环访问整个树，创建一个新树，并用其批注替换树中的每个元素。 本示例在名为 `XForm` 的函数中实现迭代和创建新树。

具体地说，此方法包括：

- 执行一个或多个 LINQ to XML 查询，用这些查询返回要从一种形状转换为另一种形状的元素集。 对于查询中的每个元素，添加一个新 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 对象作为该元素的批注。 在转换的新树中会用此新元素替换批注的元素。 这是示例中所示的唯一需要编写的代码。
- 作为批注添加的新元素可以包含新的子节点，它可以形成一个具有任意形状的子树。
- 有一条特殊规则：如果新元素的子节点位于不同的命名空间，即专门为此建立的命名空间（在本示例中，此命名空间为 `http://www.microsoft.com/LinqToXmlTransform/2007`），则不会将该子元素复制到新树。 而如果命名空间是上面提到的特殊命名空间，并且元素的本地名称为 `ApplyTransforms`，则会迭代源树中该元素的子节点并将其复制到新树（但批注的子元素本身例外，它们将根据这些规则进行转换）。
- 这有些类似于 XSL 中的转换规范。 用于选择一组节点的查询类似于用于模板的 XPath 表达式。 用于创建以批注形式保存的新 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 的代码类似于 XSL 中的序列构造函数，`ApplyTransforms` 元素的功能类似于 XSL 中的 `xsl:apply-templates` 元素。
- 采用此方法的优势之一是在用公式表述查询时，您始终是对未修改的源树编写查询。 您不必担心对树所做的修改如何影响要编写的查询。

### 转换一个树

下面的第一个示例将所有 `Paragraph` 节点重命名为 `para`。

```csharp
XNamespace xf = "http://www.microsoft.com/LinqToXmlTransform/2007";  
XName at = xf + "ApplyTransforms";  
  
XElement root = XElement.Parse(@"  
<Root>  
    <Paragraph>This is a sentence with <b>bold</b> and <i>italic</i> text.</Paragraph>  
    <Paragraph>More text.</Paragraph>  
</Root>");  
  
// replace Paragraph with para  
foreach (var el in root.Descendants("Paragraph"))  
    el.AddAnnotation(  
        new XElement("para",  
            // same idea as xsl:apply-templates  
            new XElement(xf + "ApplyTransforms")  
        )  
    );  
  
// The XForm method, shown later in this topic, accomplishes the transform  
XElement newRoot = XForm(root);  
  
Console.WriteLine(newRoot);  
```

该示例产生下面的输出：

```xml
<Root>  
  <para>This is a sentence with <b>bold</b> and <i>italic</i> text.</para>  
  <para>More text.</para>  
</Root>  
```

### 更复杂的转换

下面的示例对树进行查询并计算 `Data` 元素的平均值和总和，并将它们作为新元素添加到树中。

```csharp
XNamespace xf = "http://www.microsoft.com/LinqToXmlTransform/2007";  
XName at = xf + "ApplyTransforms";  
  
XElement data = new XElement("Root",  
    new XElement("Data", 20),  
    new XElement("Data", 10),  
    new XElement("Data", 3)  
);  
  
// while adding annotations, you can query the source tree all you want,  
// as the tree is not mutated while annotating.
var avg = data.Elements("Data").Select(z => (Decimal)z).Average();
data.AddAnnotation(  
    new XElement("Root",  
        new XElement(xf + "ApplyTransforms"),  
        new XElement("Average", $"{avg:F4}"),
        new XElement("Sum",  
            data  
            .Elements("Data")  
            .Select(z => (int)z)  
            .Sum()  
        )  
    )  
);  
  
Console.WriteLine("Before Transform");  
Console.WriteLine("----------------");  
Console.WriteLine(data);  
Console.WriteLine();  
Console.WriteLine();  
  
// The XForm method, shown later in this topic, accomplishes the transform  
XElement newData = XForm(data);  
  
Console.WriteLine("After Transform");  
Console.WriteLine("----------------");  
Console.WriteLine(newData);  
```

该示例产生下面的输出：

```
Before Transform  
----------------  
<Root>  
  <Data>20</Data>  
  <Data>10</Data>  
  <Data>3</Data>  
</Root>  
  
After Transform  
----------------  
<Root>  
  <Data>20</Data>  
  <Data>10</Data>  
  <Data>3</Data>  
  <Average>11.0000</Average>  
  <Sum>33</Sum>  
</Root>  
```

### 实施转换

小函数 `XForm` 可以从原始的、已批注的树创建新的、转换后的树。

- 该函数的伪代码非常简单：

```
The function takes an XElement as an argument and returns an XElement.   
If an element has an XElement annotation, then  
    Return a new XElement  
        The name of the new XElement is the annotation element's name.  
        All attributes are copied from the annotation to the new node.  
        All child nodes are copied from the annotation, with the  
            exception that the special node xf:ApplyTransforms is  
            recognized, and the source element's child nodes are  
            iterated. If the source child node is not an XElement, it  
            is copied to the new tree. If the source child is an  
            XElement, then it is transformed by calling this function  
            recursively.  
If an element is not annotated  
    Return a new XElement  
        The name of the new XElement is the source element's name  
        All attributes are copied from the source element to the  
            destination's element.  
        All child nodes are copied from the source element.  
        If the source child node is not an XElement, it is copied to  
            the new tree. If the source child is an XElement, then it  
            is transformed by calling this function recursively.  
```

下面是此函数的实现：

```csharp
// Build a transformed XML tree per the annotations  
static XElement XForm(XElement source)  
{  
    XNamespace xf = "http://www.microsoft.com/LinqToXmlTransform/2007";  
    XName at = xf + "ApplyTransforms";  
  
    if (source.Annotation<XElement>() != null)  
    {  
        XElement anno = source.Annotation<XElement>();  
        return new XElement(anno.Name,  
            anno.Attributes(),  
            anno  
            .Nodes()  
            .Select(  
                (XNode n) =>  
                {  
                    XElement annoEl = n as XElement;  
                    if (annoEl != null)  
                    {  
                        if (annoEl.Name == at)  
                            return (object)(  
                                source.Nodes()  
                                .Select(  
                                    (XNode n2) =>  
                                    {  
                                        XElement e2 = n2 as XElement;  
                                        if (e2 == null)  
                                            return n2;  
                                        else  
                                            return XForm(e2);  
                                    }  
                                )  
                            );  
                        else  
                            return n;  
                    }  
                    else  
                        return n;  
                }  
            )  
        );  
    }  
    else  
    {  
        return new XElement(source.Name,  
            source.Attributes(),  
            source  
                .Nodes()  
                .Select(n =>  
                {  
                    XElement el = n as XElement;  
                    if (el == null)  
                        return n;  
                    else  
                        return XForm(el);  
                }  
                )  
        );  
    }  
}   
```

### 完整的示例

下面的代码是包括 `XForm` 函数的完整示例。 它包括此类型转换的几种典型用法：

```csharp
using System;  
using System.Collections.Generic;  
using System.Linq;  
using System.Text;  
using System.Xml;  
using System.Xml.Linq;  
  
class Program  
{  
    static XNamespace xf = "http://www.microsoft.com/LinqToXmlTransform/2007";  
    static XName at = xf + "ApplyTransforms";  
  
    // Build a transformed XML tree per the annotations  
    static XElement XForm(XElement source)  
    {  
        if (source.Annotation<XElement>() != null)  
        {  
            XElement anno = source.Annotation<XElement>();  
            return new XElement(anno.Name,  
                anno.Attributes(),  
                anno  
                .Nodes()  
                .Select(  
                    (XNode n) =>  
                    {  
                        XElement annoEl = n as XElement;  
                        if (annoEl != null)  
                        {  
                            if (annoEl.Name == at)  
                                return (object)(  
                                    source.Nodes()  
                                    .Select(  
                                        (XNode n2) =>  
                                        {  
                                            XElement e2 = n2 as XElement;  
                                            if (e2 == null)  
                                                return n2;  
                                            else  
                                                return XForm(e2);  
                                        }  
                                    )  
                                );  
                            else  
                                return n;  
                        }  
                        else  
                            return n;  
                    }  
                )  
            );  
        }  
        else  
        {  
            return new XElement(source.Name,  
                source.Attributes(),  
                source  
                    .Nodes()  
                    .Select(n =>  
                    {  
                        XElement el = n as XElement;  
                        if (el == null)  
                            return n;  
                        else  
                            return XForm(el);  
                    }  
                    )  
            );  
        }  
    }  
  
    static void Main(string[] args)  
    {  
        XElement root = new XElement("Root",  
            new XComment("A comment"),  
            new XAttribute("Att1", 123),  
            new XElement("Child", 1),  
            new XElement("Child", 2),  
            new XElement("Other",  
                new XElement("GC", 3),  
                new XElement("GC", 4)  
            ),  
            XElement.Parse(  
              "<SomeMixedContent>This is <i>an</i> element that " +  
              "<b>has</b> some mixed content</SomeMixedContent>"),  
            new XElement("AnUnchangedElement", 42)  
        );  
  
        // each of the following serves the same semantic purpose as  
        // XSLT templates and sequence constructors  
  
        // replace Child with NewChild  
        foreach (var el in root.Elements("Child"))  
            el.AddAnnotation(new XElement("NewChild", (string)el));  
  
        // replace first GC with GrandChild, add an attribute  
        foreach (var el in root.Descendants("GC").Take(1))  
            el.AddAnnotation(  
                new XElement("GrandChild",  
                    new XAttribute("ANewAttribute", 999),  
                    (string)el  
                )  
            );  
  
        // replace Other with NewOther, add new child elements around original content  
        foreach (var el in root.Elements("Other"))  
            el.AddAnnotation(  
                new XElement("NewOther",  
                    new XElement("MyNewChild", 1),  
                    // same idea as xsl:apply-templates  
                    new XElement(xf + "ApplyTransforms"),  
                    new XElement("ChildThatComesAfter")  
                )  
            );  
  
        // change name of element that has mixed content  
        root.Descendants("SomeMixedContent").First().AddAnnotation(  
            new XElement("MixedContent",  
                new XElement(xf + "ApplyTransforms")  
            )  
        );  
  
        // replace <b> with <Bold>  
        foreach (var el in root.Descendants("b"))  
            el.AddAnnotation(  
                new XElement("Bold",  
                    new XElement(xf + "ApplyTransforms")  
                )  
            );  
  
        // replace <i> with <Italic>  
        foreach (var el in root.Descendants("i"))  
            el.AddAnnotation(  
                new XElement("Italic",  
                    new XElement(xf + "ApplyTransforms")  
                )  
            );  
  
        Console.WriteLine("Before Transform");  
        Console.WriteLine("----------------");  
        Console.WriteLine(root);  
        Console.WriteLine();  
        Console.WriteLine();  
        XElement newRoot = XForm(root);  
  
        Console.WriteLine("After Transform");  
        Console.WriteLine("----------------");  
        Console.WriteLine(newRoot);  
    }  
}  
```

该示例产生下面的输出：

```
Before Transform  
----------------  
<Root Att1="123">  
  <!--A comment-->  
  <Child>1</Child>  
  <Child>2</Child>  
  <Other>  
    <GC>3</GC>  
    <GC>4</GC>  
  </Other>  
  <SomeMixedContent>This is <i>an</i> element that <b>has</b> some mixed content</SomeMixedContent>  
  <AnUnchangedElement>42</AnUnchangedElement>  
</Root>  
  
After Transform  
----------------  
<Root Att1="123">  
  <!--A comment-->  
  <NewChild>1</NewChild>  
  <NewChild>2</NewChild>  
  <NewOther>  
    <MyNewChild>1</MyNewChild>  
    <GrandChild ANewAttribute="999">3</GrandChild>  
    <GC>4</GC>  
    <ChildThatComesAfter />  
  </NewOther>  
  <MixedContent>This is <Italic>an</Italic> element that <Bold>has</Bold> some mixed content</MixedContent>  
  <AnUnchangedElement>42</AnUnchangedElement>  
</Root>  
```

## [Serializing Object Graphs that Contain XElement Objects](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/serializingobjectgraphsthatcontainxelementobjects)

本主题介绍序列化对象图的功能，其中对象图包含对类型为 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 的对象的引用。 为便于执行这种类型的序列化，[XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 实现了 [IXmlSerializable](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.serialization.ixmlserializable) 接口。

请注意，只有 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 类才实现序列化。

### 本节内容

| 主题                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [如何：使用 XmlSerializer (C#) 进行序列化](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-serialize-using-xmlserializer) | 演示如何使用 [XmlSerializer](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.serialization.xmlserializer) 进行序列化。 |
| [如何：使用 DataContractSerializer 进行序列化 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-serialize-using-datacontractserializer) | 演示如何使用 [DataContractSerializer](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.serialization.datacontractserializer) 进行序列化。 |

## [How to: Serialize Using XmlSerializer](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoserializeusingxmlserializer)

本主题显示一个使用 [XmlSerializer](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.serialization.xmlserializer) 进行序列化和反序列化的示例。

### 示例

下面的示例创建多个包含 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 对象的对象。 然后将它们序列化为内存流，接着从内存流对它们进行反序列化。

```csharp
using System;  
using System.IO;  
using System.Linq;  
using System.Xml;  
using System.Xml.Serialization;  
using System.Xml.Linq;  
  
public class XElementContainer  
{  
    public XElement member;  
  
    public XElementContainer()  
    {  
        member = XLinqTest.CreateXElement();  
    }  
  
    public override string ToString()  
    {  
        return member.ToString();  
    }  
}  
  
public class XElementNullContainer  
{  
    public XElement member;  
  
    public XElementNullContainer()  
    {  
    }  
}  
  
class XLinqTest  
{  
    static void Main(string[] args)  
    {  
        Test<XElementNullContainer>(new XElementNullContainer());  
        Test<XElement>(CreateXElement());  
        Test<XElementContainer>(new XElementContainer());  
    }  
  
    public static XElement CreateXElement()  
    {  
        XNamespace ns = "http://www.adventure-works.com";  
        return new XElement(ns + "aw");  
    }  
  
    static void Test<T>(T obj)  
    {  
        using (MemoryStream stream = new MemoryStream())  
        {  
            XmlSerializer s = new XmlSerializer(typeof(T));  
            Console.WriteLine("Testing for type: {0}", typeof(T));  
            s.Serialize(XmlWriter.Create(stream), obj);  
            stream.Flush();  
            stream.Seek(0, SeekOrigin.Begin);  
            object o = s.Deserialize(XmlReader.Create(stream));  
            Console.WriteLine("  Deserialized type: {0}", o.GetType());  
        }  
    }  
}  
```

该示例产生下面的输出：

```
Testing for type: XElementNullContainer  
  Deserialized type: XElementNullContainer  
Testing for type: System.Xml.Linq.XElement  
  Deserialized type: System.Xml.Linq.XElement  
Testing for type: XElementContainer  
  Deserialized type: XElementContainer  
```

## [How to: Serialize Using DataContractSerializer](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoserializeusingdatacontractserializer)

本主题显示一个使用 [DataContractSerializer](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.serialization.datacontractserializer) 进行序列化和反序列化的示例。

### 示例

下面的示例创建多个包含 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 对象的对象。 然后将它们序列化为文本文件，接着从文本文件对它们进行反序列化。

```csharp
using System;  
using System.Xml;  
using System.Xml.Linq;  
using System.IO;  
using System.Runtime.Serialization;  
  
public class XLinqTest  
{  
    public static void Main()  
    {  
        Test<XElement>(CreateXElement());  
        Test<XElementContainer>(new XElementContainer());  
        Test<XElementNullContainer>(new XElementNullContainer());  
    }  
  
    public static void Test<T>(T obj)  
    {  
        DataContractSerializer s = new DataContractSerializer(typeof(T));  
        using (FileStream fs = File.Open("test" + typeof(T).Name + ".xml", FileMode.Create))  
        {  
            Console.WriteLine("Testing for type: {0}", typeof(T));   
            s.WriteObject(fs, obj);  
        }  
        using (FileStream fs = File.Open("test" + typeof(T).Name + ".xml", FileMode.Open))  
        {  
            object s2 = s.ReadObject(fs);  
            if (s2 == null)  
                Console.WriteLine("  Deserialized object is null (Nothing in VB)");  
            else  
                Console.WriteLine("  Deserialized type: {0}", s2.GetType());  
        }  
    }  
  
    public static XElement CreateXElement()  
    {  
        return new XElement(XName.Get("NameInNamespace", "http://www.adventure-works.org"));  
    }  
}  
  
[DataContract]  
public class XElementContainer  
{  
    [DataMember]  
    public XElement member;  
  
    public XElementContainer()  
    {  
        member = XLinqTest.CreateXElement();  
    }  
}  
  
[DataContract]  
public class XElementNullContainer  
{  
    [DataMember]  
    public XElement member;  
  
    public XElementNullContainer()  
    {  
        member = null;  
    }  
}  
```

该示例产生下面的输出：

```
Testing for type: System.Xml.Linq.XElement  
  Deserialized type: System.Xml.Linq.XElement  
Testing for type: XElementContainer  
  Deserialized type: XElementContainer  
Testing for type: XElementNullContainer  
  Deserialized type: XElementNullContainer  
```