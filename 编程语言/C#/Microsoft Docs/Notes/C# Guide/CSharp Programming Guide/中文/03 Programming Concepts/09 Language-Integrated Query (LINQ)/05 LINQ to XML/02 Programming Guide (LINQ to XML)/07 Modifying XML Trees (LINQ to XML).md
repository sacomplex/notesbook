# [Modifying XML Trees (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/modifyingxmltreeslinqtoxml)

LINQ to XML 是一个 XML 树在内存中的存储区。 在从源中加载或分析 XML 树之后，LINQ to XML 允许就地修改该树，然后序列化该树，可以将它保存到文件中或发送到远程服务器。

就地修改树时，可使用某些方法，例如 [Add](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.add)。

但是有另外一种方法，就是使用函数构造来生成具有不同形状的新树。 根据需要对 XML 树所做的更改类型的不同，以及根据树大小的不同，该方法可能更加强大，更易于开发。 本节第一个主题将比较这两种方法。

## 本节内容

| 主题                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [内存中 XML 树修改与函数构造 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/in-memory-xml-tree-modification-vs-functional-construction-linq-to-xml) | 在内存中修改 XML 树与使用函数构造的比较。                    |
| [向 XML 树添加元素、属性和节点 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/adding-elements-attributes-and-nodes-to-an-xml-tree) | 提供有关向 XML 树中添加元素、属性或节点的信息。              |
| [修改 XML 树中的元素、特性和节点](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/modifying-elements-attributes-and-nodes-in-an-xml-tree) | 提供有关修改现有元素、属性或节点的信息。                     |
| [从 XML 树中删除元素、属性和节点 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/removing-elements-attributes-and-nodes-from-an-xml-tree) | 提供有关从 XML 树中移除元素、属性或节点的信息。              |
| [维护名称/值对 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/maintaining-name-value-pairs) | 描述如何维护最好保存为名称/值对的应用程序信息，例如配置信息或全局设置。 |
| [如何：更改整个 XML 树的命名空间 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-change-the-namespace-for-an-entire-xml-tree) | 演示如何将 XML 树从一个命名空间移动到另一个命名空间。        |

## [InMemory XML Tree Modification vs. Functional Construction (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/inmemoryxmltreemodificationvsfunctionalconstructionlinqtoxml)

就地修改 XML 树是更改 XML 文档形状的传统方法。 典型的应用程序将文档加载到数据存储区（如 DOM 或 LINQ to XML）；使用编程接口插入节点、删除节点或更改节点的内容；然后将 XML 保存到文件或通过网络传输。

LINQ to XML 允许使用另一种可在许多方案中使用的方法：函数构造。 函数构造将修改数据视为转换问题，而不是数据存储区的具体操作。 如果您采用某种数据表示形式并有效地将其从一种形式转换为另一种形式，其结果等效于您采用一个数据存储区并对其以某种方式进行操作以采用另一种形状。 函数构造方法的关键是将查询的结果传递给 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 和 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 构造函数。

在许多情况下，您可以在操作数据存储区所需的很短时间内编写转换代码，并且该代码更稳定、更易于维护。 在这些情况下，虽然转换方法可能具有较强的处理能力，但它更适合用于修改数据。 如果开发人员熟悉函数方法，则在很多情况下，生成的代码会更易于理解。 可以很容易地找到修改树的每部分的代码。

DOM 程序员更熟悉就地修改 XML 树的方法，而不了解这种方法的开发人员可能会对使用函数方法编写的代码感到陌生。 如果您必须对大型 XML 树进行小修改，则在很多情况下，用于就地修改树的方法将花费更少的 CPU 时间。

本主题提供用这两种方法实现的一个示例。

### 将属性转换为元素

此示例假设您想修改下面的简单 XML 文档，使属性变为元素。 本节首先介绍传统的就地修改方法。 然后显示函数构造方法。

```xml
<?xml version="1.0" encoding="utf-8" ?>  
<Root Data1="123" Data2="456">  
  <Child1>Content</Child1>  
</Root>  
```

#### 修改 XML 树

您可以编写一些过程代码以便从属性创建元素，然后删除属性，如下所示：

```csharp
XElement root = XElement.Load("Data.xml");  
foreach (XAttribute att in root.Attributes()) {  
    root.Add(new XElement(att.Name, (string)att));  
}  
root.Attributes().Remove();  
Console.WriteLine(root);  
```

此代码生成以下输出：

```xml
<Root>  
  <Child1>Content</Child1>  
  <Data1>123</Data1>  
  <Data2>456</Data2>  
</Root>  
```

#### 函数构造方法

相比之下，函数方法包含用于形成新树的代码、从源树中选择元素和属性并在将其添加到新树中时进行相应的转换。 函数方法如下所示：

```csharp
XElement root = XElement.Load("Data.xml");  
XElement newTree = new XElement("Root",  
    root.Element("Child1"),  
    from att in root.Attributes()  
    select new XElement(att.Name, (string)att)  
);  
Console.WriteLine(newTree);  
```

本示例与第一个示例输出相同的 XML。 但请注意，您可以在函数方法中实际看到生成的新 XML 的结构。 您可以看到创建 `Root` 元素的代码、从源树中提取 `Child1` 元素的代码和将源树中的属性转换为新树中的元素的代码。

在本例中，函数示例一点也不比第一个示例简短，而且一点也不比第一个示例简单。 但如果要对一个 XML 树进行很多更改，则非函数方法将变得非常复杂，而且会显得很笨拙。 相比之下，使用函数方法时，您只需形成所需的 XML，嵌入适当的查询和表达式以提取需要的内容。 函数方法生成的代码更易于维护。

请注意，在本例中，函数方法的执行效果可能没有树操作方法好。 主要问题是函数方法创建了更多短生存期的对象。 但是，如果使用函数方法能够提高程序员的效率，则折中也是一种有效的方式。

这是一个很简单的示例，但它显示了这两种方法之间基本原理上的差异。 对于转换较大的 XML 文档，函数方法可以产生更高的效率增益。

## [Adding Elements, Attributes, and Nodes to an XML Tree](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/addingelementsattributesandnodestoanxmltree)

可以向现有的 XML 树中添加内容（包括元素、属性、注释、处理指令、文本和 CDATA）。

### 添加内容的方法

下面的方法将子内容添加到 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 或 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 中：

| 方法                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [Add](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.add) | 在 [XContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer) 的子内容的末尾添加内容。 |
| [AddFirst](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.addfirst) | 在 [XContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer) 的子内容的开头添加内容。 |

下面的方法将内容添加为 [XNode](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode) 的同级节点。 向其中添加同级内容的最常见的节点是 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)，不过你也可以将有效的同级内容添加到其他类型的节点，例如 [XText](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xtext) 或 [XComment](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcomment)。

| 方法                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [AddAfterSelf](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.addafterself) | 在 [XNode](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode) 后面添加内容。 |
| [AddBeforeSelf](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.addbeforeself) | 在 [XNode](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode) 前面添加内容。 |

### 示例

#### 说明

下面的示例创建两个 XML 树，然后修改其中一个树。

#### 代码

```csharp
XElement srcTree = new XElement("Root",   
    new XElement("Element1", 1),  
    new XElement("Element2", 2),  
    new XElement("Element3", 3),  
    new XElement("Element4", 4),  
    new XElement("Element5", 5)  
);  
XElement xmlTree = new XElement("Root",  
    new XElement("Child1", 1),  
    new XElement("Child2", 2),  
    new XElement("Child3", 3),  
    new XElement("Child4", 4),  
    new XElement("Child5", 5)  
);  
xmlTree.Add(new XElement("NewChild", "new content"));  
xmlTree.Add(  
    from el in srcTree.Elements()  
    where (int)el > 3  
    select el  
);  
// Even though Child9 does not exist in srcTree, the following statement will not  
// throw an exception, and nothing will be added to xmlTree.  
xmlTree.Add(srcTree.Element("Child9"));  
Console.WriteLine(xmlTree);  
```

#### 注释

此代码生成以下输出：

```xml
<Root>  
  <Child1>1</Child1>  
  <Child2>2</Child2>  
  <Child3>3</Child3>  
  <Child4>4</Child4>  
  <Child5>5</Child5>  
  <NewChild>new content</NewChild>  
  <Element4>4</Element4>  
  <Element5>5</Element5>  
</Root>  
```

## [Modifying Elements, Attributes, and Nodes in an XML Tree](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/modifyingelementsattributesandnodesinanxmltree)

下表汇总了修改元素、元素的子元素或元素属性 (Attribute) 时可以使用的方法和属性 (Property)。

下面的方法修改 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)。

| 方法                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [XElement.Parse](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.parse) | 用已分析的 XML 替换元素。                                    |
| [XElement.RemoveAll](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.removeall) | 移除元素的所有内容（子节点和属性）。                         |
| [XElement.RemoveAttributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.removeattributes) | 移除元素的属性。                                             |
| [XElement.ReplaceAll](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.replaceall) | 替换元素的所有内容（子节点和属性）。                         |
| [XElement.ReplaceAttributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.replaceattributes) | 替换元素的属性。                                             |
| [XElement.SetAttributeValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.setattributevalue) | 设置属性的值。 如果该属性不存在，则创建该属性。 如果值设置为 `null`，则移除该属性。 |
| [XElement.SetElementValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.setelementvalue) | 设置子元素的值。 如果该元素不存在，则创建该元素。 如果值设置为 `null`，则移除该元素。 |
| [XElement.Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.value) | 用指定的文本替换元素的内容（子节点）。                       |
| [XElement.SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.setvalue) | 设置元素的值。                                               |

下面的方法修改 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute)。

| 方法                                                         | 说明           |
| ------------------------------------------------------------ | -------------- |
| [XAttribute.Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute.value) | 设置属性的值。 |
| [XAttribute.SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute.setvalue) | 设置属性的值。 |

下面的方法修改 [XNode](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode)（包括 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 或 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument)）。

| 方法                                                         | 说明               |
| ------------------------------------------------------------ | ------------------ |
| [XNode.ReplaceWith](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.replacewith) | 用新内容替换节点。 |

下面的方法修改 [XContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer)（[XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 或 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument)）。

| 方法                                                         | 说明                 |
| ------------------------------------------------------------ | -------------------- |
| [XContainer.ReplaceNodes](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.replacenodes) | 用新内容替换子节点。 |

## [Removing Elements, Attributes, and Nodes from an XML Tree](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/removingelementsattributesandnodesfromanxmltree)

可以修改 XML 树，移除元素、属性和其他类型的节点。

从 XML 文档中移除单个元素或单个属性的操作非常简单。 但是，若要移除多个元素或属性的集合，则应首先将一个集合具体化为一个列表，然后从该列表中删除相应元素或属性。 最好的方法是使用 [Remove](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.extensions.remove) 扩展方法，该方法可以实现此操作。

这么做的主要原因在于，从 XML 树检索的大多数集合都是用延迟执行生成的。 如果不首先将集合具体化为列表，或者不使用扩展方法，则可能会遇到某类 Bug。 有关详细信息，请参阅[混合声明性代码/命令性代码的问题 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/mixed-declarative-code-imperative-code-bugs-linq-to-xml)。

下列方法可以从 XML 树中移除节点和属性。

| 方法                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [XAttribute.Remove](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute.remove) | 从父节点中移除 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute)。 |
| [XContainer.RemoveNodes](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.removenodes) | 从 [XContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer) 中移除子节点。 |
| [XElement.RemoveAll](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.removeall) | 从 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 中移除内容和属性。 |
| [XElement.RemoveAttributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.removeattributes) | 移除 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 的属性。 |
| [XElement.SetAttributeValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.setattributevalue) | 如果传递 `null` 作为值，则移除该属性。                       |
| [XElement.SetElementValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.setelementvalue) | 如果传递 `null` 作为值，则移除该子元素。                     |
| [XNode.Remove](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.remove) | 从父节点中移除 [XNode](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode)。 |
| [Extensions.Remove](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.extensions.remove) | 从父元素中移除源集合中的每个属性或元素。                     |

### 示例

#### 说明

此示例演示三种移除元素的方法。 第一种，移除单个元素。 第二种，检索元素的集合，使用 [Enumerable.ToList](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.tolist)运算符将它们具体化，然后移除集合。 最后一种，检索元素的集合，使用 [Remove](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.extensions.remove) 扩展方法移除元素。

有关 [ToList](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.tolist) 运算符的详细信息，请参阅[转换数据类型 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/converting-data-types)。

#### 代码

```csharp
XElement root = XElement.Parse(@"<Root>  
    <Child1>  
        <GrandChild1/>  
        <GrandChild2/>  
        <GrandChild3/>  
    </Child1>  
    <Child2>  
        <GrandChild4/>  
        <GrandChild5/>  
        <GrandChild6/>  
    </Child2>  
    <Child3>  
        <GrandChild7/>  
        <GrandChild8/>  
        <GrandChild9/>  
    </Child3>  
</Root>");  
root.Element("Child1").Element("GrandChild1").Remove();  
root.Element("Child2").Elements().ToList().Remove();  
root.Element("Child3").Elements().Remove();  
Console.WriteLine(root);  
```

#### 注释

此代码生成以下输出：

```xml
<Root>  
  <Child1>  
    <GrandChild2 />  
    <GrandChild3 />  
  </Child1>  
  <Child2 />  
  <Child3 />  
</Root>  
```

请注意，第一个孙元素已从 `Child1` 中移除。 所有孙元素都已从 `Child2` 和 `Child3` 中移除。

## [Maintaining NameValue Pairs](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/maintainingnamevaluepairs)

很多应用程序都必须维护需要保存为名称/值对的信息。 此信息可能是配置信息或全局设置。 LINQ to XML 包含一些方法，能轻松保存一组名称/值对。 可以将这些信息保存为属性，也可以保存为一组子元素。

将信息保存为属性和保存为子元素之间的区别在于属性具有约束，对于一个元素，只能有一个属性具有特定的名称。 而这种限制不适用于子元素。

### SetAttributeValue 与 SetElementValue

两种有助于保存名称/值对的方法是 [SetAttributeValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.setattributevalue) 和 [SetElementValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.setelementvalue)。 这两种方法具有相似的语义。

[SetAttributeValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.setattributevalue) 可以添加、修改或移除元素的属性。

- 如果使用不存在的属性的名称调用 [SetAttributeValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.setattributevalue)，则该方法会创建一个新属性并将该属性添加到指定的元素中。
- 如果使用现有属性的名称调用 [SetAttributeValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.setattributevalue)，并指定一些内容，则会用指定内容替换属性的内容。
- 如果使用现有属性的名称调用 [SetAttributeValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.setattributevalue)，并指定内容为空，则会从该属性的父级移除该属性。

[SetElementValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.setelementvalue) 可以添加、修改或移除元素的子元素。

- 如果使用不存在的子元素的名称调用 [SetElementValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.setelementvalue)，则该方法会创建一个新元素并将该新元素添加到指定的元素中。
- 如果使用现有元素的名称调用 [SetElementValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.setelementvalue)，并指定一些内容，则会用指定内容替换元素的内容。
- 如果使用现有元素的名称调用 [SetElementValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.setelementvalue)，并指定内容为空，则会从该元素的父级移除该元素。

### 示例

下面的示例创建一个没有属性的元素。 之后使用 [SetAttributeValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.setattributevalue) 方法创建一个名称/值对列表并维护该列表。

```csharp
// Create an element with no content.  
XElement root = new XElement("Root");  
  
// Add a number of name/value pairs as attributes.  
root.SetAttributeValue("Top", 22);  
root.SetAttributeValue("Left", 20);  
root.SetAttributeValue("Bottom", 122);  
root.SetAttributeValue("Right", 300);  
root.SetAttributeValue("DefaultColor", "Color.Red");  
Console.WriteLine(root);  
  
// Replace the value of Top.  
root.SetAttributeValue("Top", 10);  
Console.WriteLine(root);  
  
// Remove DefaultColor.  
root.SetAttributeValue("DefaultColor", null);  
Console.WriteLine(root);  
```

该示例产生下面的输出：

```xml
<Root Top="22" Left="20" Bottom="122" Right="300" DefaultColor="Color.Red" />  
<Root Top="10" Left="20" Bottom="122" Right="300" DefaultColor="Color.Red" />  
<Root Top="10" Left="20" Bottom="122" Right="300" />  
```

### 示例

下面的示例创建一个没有子元素的元素。 之后使用 [SetElementValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.setelementvalue) 方法创建一个名称/值对列表并维护该列表。

```csharp
// Create an element with no content.  
XElement root = new XElement("Root");  
  
// Add a number of name/value pairs as elements.  
root.SetElementValue("Top", 22);  
root.SetElementValue("Left", 20);  
root.SetElementValue("Bottom", 122);  
root.SetElementValue("Right", 300);  
root.SetElementValue("DefaultColor", "Color.Red");  
Console.WriteLine(root);  
Console.WriteLine("----");  
  
// Replace the value of Top.  
root.SetElementValue("Top", 10);  
Console.WriteLine(root);  
Console.WriteLine("----");  
  
// Remove DefaultColor.  
root.SetElementValue("DefaultColor", null);  
Console.WriteLine(root);  
```

该示例产生下面的输出：

```xml
<Root>  
  <Top>22</Top>  
  <Left>20</Left>  
  <Bottom>122</Bottom>  
  <Right>300</Right>  
  <DefaultColor>Color.Red</DefaultColor>  
</Root>  
----  
<Root>  
  <Top>10</Top>  
  <Left>20</Left>  
  <Bottom>122</Bottom>  
  <Right>300</Right>  
  <DefaultColor>Color.Red</DefaultColor>  
</Root>  
----  
<Root>  
  <Top>10</Top>  
  <Left>20</Left>  
  <Bottom>122</Bottom>  
  <Right>300</Right>  
</Root>  
```

## [How to: Change the Namespace for an Entire XML Tree](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtochangethenamespaceforanentirexmltree)

有时需要以编程方式更改元素或属性的命名空间。 LINQ to XML 可简化此任务。 可以设置 [XElement.Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.name) 属性。 不能设置 [XAttribute.Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute.name) 属性 (Property)，但是很容易将属性 (Attribute) 复制到[System.Collections.Generic.List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1) 中，移除现有属性 (Attribute)，然后添加位于新命名空间中的新属性 (Attribute)。

有关详细信息，请参阅[使用 XML 命名空间 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/working-with-xml-namespaces)。

### 示例

下面的代码创建两个不在命名空间中的 XML 树。 然后更改每个树的命名空间，再将它们合并到一个树中。

```csharp
XElement tree1 = new XElement("Data",  
    new XElement("Child", "content",  
        new XAttribute("MyAttr", "content")  
    )  
);  
XElement tree2 = new XElement("Data",  
    new XElement("Child", "content",  
        new XAttribute("MyAttr", "content")  
    )  
);  
XNamespace aw = "http://www.adventure-works.com";  
XNamespace ad = "http://www.adatum.com";  
// change the namespace of every element and attribute in the first tree  
foreach (XElement el in tree1.DescendantsAndSelf())  
{  
    el.Name = aw.GetName(el.Name.LocalName);  
    List<XAttribute> atList = el.Attributes().ToList();  
    el.Attributes().Remove();  
    foreach (XAttribute at in atList)  
        el.Add(new XAttribute(aw.GetName(at.Name.LocalName), at.Value));  
}  
// change the namespace of every element and attribute in the second tree  
foreach (XElement el in tree2.DescendantsAndSelf())  
{  
    el.Name = ad.GetName(el.Name.LocalName);  
    List<XAttribute> atList = el.Attributes().ToList();  
    el.Attributes().Remove();  
    foreach (XAttribute at in atList)  
        el.Add(new XAttribute(ad.GetName(at.Name.LocalName), at.Value));  
}  
// add attribute namespaces so that the tree will be serialized with  
// the aw and ad namespace prefixes  
tree1.Add(  
    new XAttribute(XNamespace.Xmlns + "aw", "http://www.adventure-works.com")  
);  
tree2.Add(  
    new XAttribute(XNamespace.Xmlns + "ad", "http://www.adatum.com")  
);  
// create a new composite tree  
XElement root = new XElement("Root",  
    tree1,  
    tree2  
);  
Console.WriteLine(root);  
```

该示例产生下面的输出：

```xml
<Root>  
  <aw:Data xmlns:aw="http://www.adventure-works.com">  
    <aw:Child aw:MyAttr="content">content</aw:Child>  
  </aw:Data>  
  <ad:Data xmlns:ad="http://www.adatum.com">  
    <ad:Child ad:MyAttr="content">content</ad:Child>  
  </ad:Data>  
</Root>  
```