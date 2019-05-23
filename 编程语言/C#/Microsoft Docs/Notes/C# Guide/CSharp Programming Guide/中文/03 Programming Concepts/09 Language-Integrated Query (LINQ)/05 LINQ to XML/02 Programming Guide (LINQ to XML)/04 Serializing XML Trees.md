# [Serializing XML Trees](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/serializingxmltrees)

序列化 XML 树意味着从 XML 树生成 XML。 可以将 XML 树序列化到文件、[TextWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.textwriter) 类的具体实现或 [XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwriter)的具体实现。

可以控制序列化的各个方面。 例如，可以控制是否缩进序列化的 XML，以及是否写入 XML 声明。

## 本节内容

| 主题                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [在序列化时保留空白](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/preserving-white-space-while-serializing) | 介绍如何在序列化 XML 树时控制空白行为。                      |
| [带 XML 声明的序列化 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/serializing-with-an-xml-declaration) | 介绍如何序列化包含 XML 声明的 XML 树。                       |
| [序列化为文件、TextWriter 和 XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/serializing-to-files-textwriters-and-xmlwriters) | 描述如何将文档序列化到 [File](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.file)、[TextWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.textwriter) 或 [XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwriter)。 |
| [序列化为 XmlReader（调用 XSLT）(C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/serializing-to-an-xmlreader-invoking-xslt) | 描述如何创建一个 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader)，使另一个模块能够通过它读取 XML 树的内容。 |

## [Preserving White Space While Serializing](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/preservingwhitespacewhileserializing)

本主题描述在序列化 XML 树时如何控制空白。

一种常见方案是，读取缩进式 XML，创建不含任何空白符文本节点（即不保留空白符）的内存中 XML 树，对 XML 执行一些操作，再保存带缩进的 XML。 在序列化带格式的 XML 时，只保留 XML 树中有意义的空白。 这是 LINQ to XML 的默认行为。

另一个常见的情况是读取和修改已经有意缩进的 XML。 您可能不想以任何方式更改这种缩进。 若要在 LINQ to XML 中执行此操作，您要在加载或解析 XML 时保留空白，并在序列化 XML 时禁用格式设置。

##### 用于序列化 XML 树的方法的空白符行为

[XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 和 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 类中的以下方法用于序列化 XML 树。 可以将 XML 树序列化为文件、[TextReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.textreader) 或 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader)。 `ToString` 方法序列化为字符串。

- [XElement.Save](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.save)
- [XDocument.Save](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument.save)
- [ToString](https://msdn.microsoft.com/library/system.xml.linq.xelement.tostring(v=vs.110).aspx)
- [ToString](https://msdn.microsoft.com/library/system.xml.linq.xdocument.tostring(v=vs.110).aspx)

如果方法不接受 [SaveOptions](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.saveoptions) 作为参数，那么该方法将格式化（缩进）序列化的 XML。 在这种情况下，将丢弃 XML 树中所有无意义的空白。

如果方法接受 [SaveOptions](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.saveoptions) 作为参数，那么您可以指定不格式化（缩进）序列化的 XML。 在这种情况下，将保留 XML 树中的所有空白。

## [Serializing with an XML Declaration](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/serializingwithanxmldeclaration)

本主题说明如何控制序列化是否生成 XML 声明。

##### XML 声明的生成

使用 [File](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.file) 方法或 [TextWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.textwriter) 方法序列化为 [XElement.Save](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.save) 或 [XDocument.Save](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument.save) 将生成 XML 声明。 在序列化为 [XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwriter) 时，编写器设置（在 [XmlWriterSettings](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwritersettings) 对象中指定）将确定是否生成 XML 声明。

如果要使用 `ToString` 方法序列化为字符串，则生成的 XML 不会包括 XML 声明。

##### 使用 XML 声明进行序列化

下面的示例创建一个 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)，将文档保存到文件，然后将文件打印到控制台：

```csharp
XElement root = new XElement("Root",  
    new XElement("Child", "child content")  
);  
root.Save("Root.xml");  
string str = File.ReadAllText("Root.xml");  
Console.WriteLine(str);  
```

该示例产生下面的输出：

```xml
<?xml version="1.0" encoding="utf-8"?>  
<Root>  
  <Child>child content</Child>  
</Root>  
```

##### 不带 XML 声明的序列化

下面的示例演示如何将一个 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 保存到一个 [XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwriter)。

```csharp
StringBuilder sb = new StringBuilder();  
XmlWriterSettings xws = new XmlWriterSettings();  
xws.OmitXmlDeclaration = true;  
  
using (XmlWriter xw = XmlWriter.Create(sb, xws)) {  
    XElement root = new XElement("Root",  
        new XElement("Child", "child content")  
    );  
    root.Save(xw);  
}  
Console.WriteLine(sb.ToString());  
```

该示例产生下面的输出：

```xml
<Root><Child>child content</Child></Root>  
```

## [Serializing to Files, TextWriters, and XmlWriters](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/serializingtofilestextwritersandxmlwriters)

可以将 XML 树序列化为 [File](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.file)、[TextWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.textwriter) 或 [XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwriter)。

可以使用 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 方法，将任何 XML 组件（包括 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 和 `ToString`）序列化为一个字符串。

在序列化为字符串时，如果要禁止格式化，可以使用 [XNode.ToString](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.tostring) 方法。

序列化为文件时，默认行为是格式化（缩进）生成的 XML 文档。 缩进时，不会保留 XML 树中无意义的空白。 若要使用格式化方式进行序列化，请使用不将 [SaveOptions](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.saveoptions) 作为参数的以下方法的重载之一：

- [XDocument.Save](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument.save)
- [XElement.Save](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.save)

如果要选择不在 XML 树中缩进，并保留无意义空白，请使用将 [SaveOptions](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.saveoptions) 作为参数的以下方法的重载之一：

- [XDocument.Save](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument.save)
- [XElement.Save](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.save)

有关示例，请参见相应的参考主题。

## [Serializing to an XmlReader (Invoking XSLT)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/serializingtoanxmlreaderinvokingxslt)

在使用 LINQ to XML 的 [System.Xml](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml) 互操作性功能时，可以使用 [CreateReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.createreader) 来创建 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader)。 从该 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 进行读取的模块从 XML 树读取节点，并对它们进行相应的处理。

##### 调用 XSLT 转换

此方法可能在调用 XSLT 转换时使用。 可以创建 XML 树，从 XML 树创建 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader)，创建新文档，然后创建 [XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwriter) 以写入新文档。 接着，可以调用 XSLT 转换，传入 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 和 [XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwriter)。 在转换成功完成后，使用转换的结果，填充新的 XML 树。

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