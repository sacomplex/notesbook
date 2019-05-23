# [Flow Content](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/flow-content)

流内容元素提供构建基块创建流内容适用于在中承载[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)。

[流文档概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/flow-document-overview)
[TextElement 内容模型概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/textelement-content-model-overview)
[表概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/table-overview)
[帮助主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/flow-content-elements-how-to-topics)

## [Flow Document Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/flow-document-overview)

流文档旨在优化查看和可读性。 流文档根据运行时变量（例如，窗口大小、设备分辨率和可选的用户首选项）来动态调整和重新排列内容，而不是设置为一个预定义的布局。 此外，流文档还提供一些高级文档功能，例如分页和分栏。 本主题概述了流文档及其创建方式。

### 什么是流文档？

流文档旨在根据窗口大小、设备分辨率和其他环境变量来“重排内容”。 此外，流文档还具有很多内置功能，包括搜索、能够优化可读性的查看模式以及更改字体大小和外观的功能。 当易读性是文档的主要使用要求时，最适合使用流文档。 相反，固定文档旨在提供静态表示形式。 当源内容的保真度至关重要时，就适合使用固定文档。请参阅[WPF 中的文档](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/documents-in-wpf)为不同类型的文档的详细信息。

下图演示在多个不同大小的窗口中查看同一个示例流文档的情况。 随着显示区域的变化，内容将重新布局，以充分利用可用空间。

![流文档内容重新布局](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/edocs-flowdocument.png)

如上图所示，流内容可包括多个组成部分，包括段落、列表、图像等等。 这些组成部分对应于标记中的元素和程序代码中的对象。 我们将详细阐述中详细介绍这些类在更高版本[流相关的类](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/flow-document-overview#flow_related_classes)本概述的部分。 现在，下面是一个简单的代码示例，创建一个包含部分粗体文本和列表的段落的流文档。

XAML复制

```xaml
<!-- This simple flow document includes a paragraph with some
     bold text in it and a list. -->
<FlowDocumentReader xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
  <FlowDocument>
    <Paragraph>
      <Bold>Some bold text in the paragraph.</Bold>
      Some text that is not bold.
    </Paragraph>

    <List>
      <ListItem>
        <Paragraph>ListItem 1</Paragraph>
      </ListItem>
      <ListItem>
        <Paragraph>ListItem 2</Paragraph>
      </ListItem>
      <ListItem>
        <Paragraph>ListItem 3</Paragraph>
      </ListItem>
    </List>

  </FlowDocument>
</FlowDocumentReader>
```

C#复制

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;

namespace SDKSample
{
    public partial class SimpleFlowExample : Page
    {
        public SimpleFlowExample()
        {

            Paragraph myParagraph = new Paragraph();

            // Add some Bold text to the paragraph
            myParagraph.Inlines.Add(new Bold(new Run("Some bold text in the paragraph.")));

            // Add some plain text to the paragraph
            myParagraph.Inlines.Add(new Run(" Some text that is not bold."));

            // Create a List and populate with three list items.
            List myList = new List();

            // First create paragraphs to go into the list item.
            Paragraph paragraphListItem1 = new Paragraph(new Run("ListItem 1"));
            Paragraph paragraphListItem2 = new Paragraph(new Run("ListItem 2"));
            Paragraph paragraphListItem3 = new Paragraph(new Run("ListItem 3"));

            // Add ListItems with paragraphs in them.
            myList.ListItems.Add(new ListItem(paragraphListItem1));
            myList.ListItems.Add(new ListItem(paragraphListItem2));
            myList.ListItems.Add(new ListItem(paragraphListItem3));

            // Create a FlowDocument with the paragraph and list.
            FlowDocument myFlowDocument = new FlowDocument();
            myFlowDocument.Blocks.Add(myParagraph);
            myFlowDocument.Blocks.Add(myList);

            // Add the FlowDocument to a FlowDocumentReader Control
            FlowDocumentReader myFlowDocumentReader = new FlowDocumentReader();
            myFlowDocumentReader.Document = myFlowDocument;

            this.Content = myFlowDocumentReader;
        }
    }
}
```

下图显示了此代码片段。

![屏幕快照：呈现的 FlowDocument 示例](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/flow-ovw-first-example.png)

在此示例中，[FlowDocumentReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentreader)控件用于托管流内容。 请参阅[流文档类型](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/flow-document-overview#flow_document_types)有关流内容托管控件的详细信息。[Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph)[List](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.list)， [ListItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.listitem)，和[Bold](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.bold)元素用于控制内容格式，根据其在标记中的顺序。 例如，[Bold](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.bold)元素跨越仅的段落中的文本的一部分; 因此，只有这一部分文本为粗体。 如果使用过 HTML，你就会了解这一点。

上图中突出显示，有多个流文档中内置的功能：

- 搜索:允许用户执行的整个文档的全文搜索。
- 查看模式：用户可以选择喜欢的查看模式包括单页 （页--一次） 查看模式、 两个---a-次一页 （书本阅读格式） 查看模式和连续滚动 （无界限） 查看模式。 有关这些查看模式的详细信息，请参阅[FlowDocumentReaderViewingMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentreaderviewingmode)。
- 页导航控件：如果文档的查看模式使用页面，页面导航控件包含一个按钮，用于跳转到下一页 （向下箭头） 或上一页 （向上箭头），以及当前页码和总页数的指示器。 也可使用键盘上的箭头键来实现翻页操作。
- 缩放：缩放控件使用户能够增加或减少的缩放级别，单击加号或减号按钮，分别。 缩放控件还包括一个用于调整缩放级别的滑块。 有关详细信息，请参阅 [Zoom](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentreader.zoom)。

这些功能可根据用于托管流内容的控件进行修改。 下一节介绍了各种控件。



### 流文档类型

流文档内容的显示和外观依赖于用于托管流内容的对象。 有四个支持查看流内容的控件： [FlowDocumentReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentreader)， [FlowDocumentPageViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentpageviewer)， [RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)，和[FlowDocumentScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentscrollviewer)。 下面简要介绍了这些控件。

**注意：** [FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument) ，则需要直接托管流内容，因此所有这些查看控件使用[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)若要启用流内容托管。

#### FlowDocumentReader

[FlowDocumentReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentreader) 包括功能，让用户能够动态选择各种查看模式，包括单页 （页--一次） 查看模式、 两个---a-次一页 （书本阅读格式） 查看模式和连续滚动 （无界限） 查看模式。 有关这些查看模式的详细信息，请参阅[FlowDocumentReaderViewingMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentreaderviewingmode)。 如果不需要进行不同查看模式之间动态切换的功能[FlowDocumentPageViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentpageviewer)和[FlowDocumentScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentscrollviewer)提供的轻量级流内容查看器中使用特定查看模式修复。

#### FlowDocumentPageViewer 和 FlowDocumentScrollViewer

[FlowDocumentPageViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentpageviewer) 显示的内容一次一页中查看模式，尽管[FlowDocumentScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentscrollviewer)以连续滚动模式显示内容。 这两[FlowDocumentPageViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentpageviewer)和[FlowDocumentScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentscrollviewer)都固定使用特定查看模式。 相比[FlowDocumentReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentreader)，包含的功能使用户能够动态选择各种查看模式 (由提供[FlowDocumentReaderViewingMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentreaderviewingmode)枚举)，但代价是多个资源占用量比[FlowDocumentPageViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentpageviewer)或[FlowDocumentScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentscrollviewer)。

默认情况下，总是显示垂直滚动条，而水平滚动条则在需要时显示。 默认值为 UI[FlowDocumentScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentscrollviewer)不包括工具栏; 但是，[IsToolBarVisible](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentscrollviewer.istoolbarvisible)属性可以用于启用内置工具栏。

#### RichTextBox

您使用[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)当你想要允许用户编辑流内容。 例如，如果你想要创建一种编辑器，允许用户处理表、 斜体和粗体格式等，将使用[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)。 请参阅[RichTextBox 概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/richtextbox-overview)有关详细信息。

**注意：** 内部的流内容[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)不符的其他控件中包含的流内容与完全相同。 例如，有中的没有列[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)并因此没有自动调整大小行为。 另外，通常内置的功能，例如搜索、 查看模式、 页面导航和缩放的流内容的不能在[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)。

### 创建流内容

流内容可能很复杂并包含各种元素，包括文本、 图像、 表、 甚至[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)派生的类，如控件。 若要了解如何创建复杂流内容，掌握下列知识点非常关键：

- **与流相关的类**:在流内容中使用每个类都有特定用途。 此外，了解各种流类之间的层次关系有助于了解其使用方式。 例如，类派生自[Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block)类用于包含其他对象，而类派生自[Inline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline)包含显示的对象。
- **内容架构**:流文档可能需要大量嵌套元素。 内容架构指定了元素之间可能存在的父/子关系。

以下各节详细介绍了上述每个方面。



### 与流相关的类

下图演示了流内容中最常使用的对象：

![关系图：流内容元素类层次结构](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/flow-class-hierarchy.png)

根据流内容的用途，可分为两个重要类别：

1. **Block 派生类**:也称为"Block 内容元素"或简称为"块元素"。 继承元素[Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block)可以在一个公共父级下的元素进行分组或将公用特性应用于组。
2. **Inline 派生类**:也称为"Inline 内容元素"或简称为"内联元素"。 继承元素[Inline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline)或者包含在是块元素或另一个 Inline 元素。 Inline 元素通常用作在屏幕上呈现的内容的直接容器。 例如， [Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph) （Block 元素） 可以包含[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run)（Inline 元素），但[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run)实际包含屏幕呈现的文本。

下面简要介绍了这两个类别中的每个类。

#### Block 派生类

**Paragraph**

[Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph) 常用于将内容分组到一个段落。 Paragraph 的最简单且最常见的用途是创建文本段落。

```xaml
<FlowDocument xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
  <Paragraph>
    Some paragraph text.
  </Paragraph>
</FlowDocument>
```

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;

namespace SDKSample
{
    public partial class ParagraphExample : Page
    {
        public ParagraphExample()
        {

            // Create paragraph with some text.
            Paragraph myParagraph = new Paragraph();
            myParagraph.Inlines.Add(new Run("Some paragraph text."));

            // Create a FlowDocument and add the paragraph to it.
            FlowDocument myFlowDocument = new FlowDocument();
            myFlowDocument.Blocks.Add(myParagraph);

            this.Content = myFlowDocument;
        }
    }
}
```

但是，正如您将看到如下，还可以包含其他 inline 派生元素。

**节**

[Section](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.section) 仅用于包含其他[Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block)-派生元素。 它不会向其中包含的元素应用任何默认格式。 但是，任何属性值集上[Section](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.section)适用于其子元素。 使用节能够以编程方式循环访问其子集合。 [Section](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.section) 中到类似的方式使用<d i V > 以 html 格式的标记。

在下面的示例中，三个段落定义一个下[Section](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.section)。 本部分包含[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.textelement.background)属性值 Red，因此段落的背景色也是红色。

XAML复制

```xaml
<FlowDocument xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
  <!-- By default, Section applies no formatting to elements contained
       within it. However, in this example, the section has a Background
       property value of "Red", therefore, the three paragraphs (the block)  
       inside the section also have a red background. -->
  <Section Background="Red">
    <Paragraph>
      Paragraph 1
    </Paragraph>
    <Paragraph>
      Paragraph 2
    </Paragraph>
    <Paragraph>
      Paragraph 3
    </Paragraph>
  </Section>
</FlowDocument>
```

C#复制

```csharp
using System;
using System.Windows;
using System.Windows.Media;
using System.Windows.Controls;
using System.Windows.Documents;

namespace SDKSample
{
    public partial class SectionExample : Page
    {
        public SectionExample()
        {

            // Create three paragraphs
            Paragraph myParagraph1 = new Paragraph(new Run("Paragraph 1"));
            Paragraph myParagraph2 = new Paragraph(new Run("Paragraph 2"));
            Paragraph myParagraph3 = new Paragraph(new Run("Paragraph 3"));

            // Create a Section and add the three paragraphs to it.
            Section mySection = new Section();
            mySection.Background = Brushes.Red;

            mySection.Blocks.Add(myParagraph1);
            mySection.Blocks.Add(myParagraph2);
            mySection.Blocks.Add(myParagraph3);

            // Create a FlowDocument and add the section to it.
            FlowDocument myFlowDocument = new FlowDocument();
            myFlowDocument.Blocks.Add(mySection);

            this.Content = myFlowDocument;
        }
    }
}
```

**BlockUIContainer**

[BlockUIContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.blockuicontainer) 使[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)元素 (即[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)) 能够嵌入到区块派生的流内容。 [InlineUIContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inlineuicontainer) （见下文） 用于将嵌入[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)内联派生的流内容中的元素。 [BlockUIContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.blockuicontainer) 并[InlineUIContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inlineuicontainer)非常重要，因为没有其他方法来使用[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)在流内容，除非它包含在这两个元素之一中。

下面的示例演示如何使用[BlockUIContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.blockuicontainer)元素来承载[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)流内容内的对象。

XAML复制

```xaml
<FlowDocument ColumnWidth="400">
  <Section Background="GhostWhite">
    <Paragraph>
      A UIElement element may be embedded directly in flow content
      by enclosing it in a BlockUIContainer element.
    </Paragraph>
    <BlockUIContainer>
      <Button>Click me!</Button>
    </BlockUIContainer>
    <Paragraph>
      The BlockUIContainer element may host no more than one top-level
      UIElement.  However, other UIElements may be nested within the
      UIElement contained by an BlockUIContainer element.  For example,
      a StackPanel can be used to host multiple UIElement elements within
      a BlockUIContainer element.
    </Paragraph>
    <BlockUIContainer>
      <StackPanel>
        <Label Foreground="Blue">Choose a value:</Label>
        <ComboBox>
          <ComboBoxItem IsSelected="True">a</ComboBoxItem>
          <ComboBoxItem>b</ComboBoxItem>
          <ComboBoxItem>c</ComboBoxItem>
        </ComboBox>
        <Label Foreground ="Red">Choose a value:</Label>
        <StackPanel>
          <RadioButton>x</RadioButton>
          <RadioButton>y</RadioButton>
          <RadioButton>z</RadioButton>
        </StackPanel>
        <Label>Enter a value:</Label>
        <TextBox>
          A text editor embedded in flow content.
        </TextBox>
      </StackPanel>
    </BlockUIContainer>
  </Section>
</FlowDocument>
```

下图显示了此示例的呈现效果。

![屏幕快照：嵌入在流内容中的 UIElement](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/blockuicontainer.png)

**List**

[List](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.list) 用于创建项目符号列表或数值列表。 设置[MarkerStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.list.markerstyle)属性设置为[TextMarkerStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.textmarkerstyle)枚举值，以确定列表的样式。 下例演示了如何创建简单列表。

XAML复制

```xaml
<FlowDocument xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
  <List>
    <ListItem>
      <Paragraph>
        List Item 1
      </Paragraph>
    </ListItem>
    <ListItem>
      <Paragraph>
        List Item 2
      </Paragraph>
    </ListItem>
    <ListItem>
      <Paragraph>
        List Item 3
      </Paragraph>
    </ListItem>
  </List>
</FlowDocument>
```

C#复制

```csharp
using System;
using System.Windows;
using System.Windows.Media;
using System.Windows.Controls;
using System.Windows.Documents;

namespace SDKSample
{
    public partial class ListExample : Page
    {
        public ListExample()
        {

            // Create three paragraphs
            Paragraph myParagraph1 = new Paragraph(new Run("List Item 1"));
            Paragraph myParagraph2 = new Paragraph(new Run("List Item 2"));
            Paragraph myParagraph3 = new Paragraph(new Run("List Item 3"));

            // Create the ListItem elements for the List and add the 
            // paragraphs to them.
            ListItem myListItem1 = new ListItem();
            myListItem1.Blocks.Add(myParagraph1);
            ListItem myListItem2 = new ListItem();
            myListItem2.Blocks.Add(myParagraph2);
            ListItem myListItem3 = new ListItem();
            myListItem3.Blocks.Add(myParagraph3);

            // Create a List and add the three ListItems to it.
            List myList = new List();

            myList.ListItems.Add(myListItem1);
            myList.ListItems.Add(myListItem2);
            myList.ListItems.Add(myListItem3);

            // Create a FlowDocument and add the section to it.
            FlowDocument myFlowDocument = new FlowDocument();
            myFlowDocument.Blocks.Add(myList);

            this.Content = myFlowDocument;
        }
    }
}
```

**注意：** [List](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.list)是使用的唯一流元素[ListItemCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.listitemcollection)来管理子元素。

**Table**

[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table) 用于创建表。 [Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table) 类似于[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素，但它会提供更多功能，因此，需要更大的资源开销。 因为[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)是[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)，除非它包含在不能在流内容中使用它[BlockUIContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.blockuicontainer)或[InlineUIContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inlineuicontainer)。 有关详细信息[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)，请参阅[表概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/table-overview)。

#### Inline 派生类

**运行**

[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run) 用于包含无格式的文本。 您所料[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run)对象中广泛使用流内容。 但是，在标记中，[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run)元素不需要显式使用。[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run) 需要创建或使用代码操作流文档时使用。 例如，在以下第一个标记[Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph)指定[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run)不明确时第二个元素。这两个段落生成相同的输出。

XAML复制

```xaml
<Paragraph>
  <Run>Paragraph that explicitly uses the Run element.</Run>
</Paragraph>

<Paragraph>
  This Paragraph omits the Run element in markup. It renders
  the same as a Paragraph with Run used explicitly. 
</Paragraph>
```

**注意：** 在中启动.NET Framework 4，则[Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run.text)属性的[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run)对象是依赖项属性。 可以将绑定[Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run.text)属性设置为数据源，如[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)。 [Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run.text)属性完全支持单向绑定。 [Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run.text)属性还支持双向绑定，除[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)。 有关示例，请参见 [Run.Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run.text)。

**Span**

[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span) 其他内联内容元素组合在一起。 中的内容应用任何继承呈现[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)元素。 但是，元素的继承自[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)包括[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)， [Bold](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.bold)，[Italic](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.italic)和[Underline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.underline)是否将格式应用于文本。

下面是举例[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)正在用于包含内联内容包括文本、[Bold](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.bold)元素，和一个[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。

XAML复制

```xaml
<FlowDocument xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">

  <Paragraph>
    Text before the Span. <Span Background="Red">Text within the Span is
    red and <Bold>this text is inside the Span-derived element Bold.</Bold>
    A Span can contain more then text, it can contain any inline content. For
    example, it can contain a 
    <InlineUIContainer>
      <Button>Button</Button>
    </InlineUIContainer>
    or other UIElement, a Floater, a Figure, etc.</Span>
  </Paragraph>

</FlowDocument>
```

下面的屏幕截图显示了此示例的呈现效果。

![屏幕快照：呈现的 Span 示例](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/flow-spanexample.gif)

**InlineUIContainer**

[InlineUIContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inlineuicontainer) 使[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)元素 (即控件喜欢[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)) 能够嵌入到[Inline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline)内容元素。 此元素是等效的 inline[BlockUIContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.blockuicontainer)上面所述。 下面是使用一个示例[InlineUIContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inlineuicontainer)插入[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)中的以内联方式[Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph)。

XAML复制

```xaml
<FlowDocument xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">

  <Paragraph>
    Text to precede the button...

    <!-- Set the BaselineAlignment property to "Bottom" 
         so that the Button aligns properly with the text. -->
    <InlineUIContainer BaselineAlignment="Bottom">
      <Button>Button</Button>
    </InlineUIContainer>
    Text to follow the button...
  </Paragraph>

</FlowDocument>
```

C#复制

```csharp
using System;
using System.Windows;
using System.Windows.Media;
using System.Windows.Controls;
using System.Windows.Documents;

namespace SDKSample
{
    public partial class InlineUIContainerExample : Page
    {
        public InlineUIContainerExample()
        {
            Run run1 = new Run(" Text to precede the button... ");
            Run run2 = new Run(" Text to follow the button... ");

            // Create a new button to be hosted in the paragraph.
            Button myButton = new Button();
            myButton.Content = "Click me!";

            // Create a new InlineUIContainer to contain the Button.
            InlineUIContainer myInlineUIContainer = new InlineUIContainer();

            // Set the BaselineAlignment property to "Bottom" so that the 
            // Button aligns properly with the text.
            myInlineUIContainer.BaselineAlignment = BaselineAlignment.Bottom;

            // Asign the button as the UI container's child.
            myInlineUIContainer.Child = myButton;

            // Create the paragraph and add content to it.
            Paragraph myParagraph = new Paragraph();
            myParagraph.Inlines.Add(run1);
            myParagraph.Inlines.Add(myInlineUIContainer);
            myParagraph.Inlines.Add(run2);

            // Create a FlowDocument and add the paragraph to it.
            FlowDocument myFlowDocument = new FlowDocument();
            myFlowDocument.Blocks.Add(myParagraph);

            this.Content = myFlowDocument;
        }
    }
}
```

**注意：** [InlineUIContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inlineuicontainer)不需要在标记中显式使用。 如果省略，[InlineUIContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inlineuicontainer)仍将创建编译代码。

**Figure 和 Floater**

[Figure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.figure) 和[Floater](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.floater)用于在流文档中嵌入内容，带有可进行自定义独立于主内容流的位置属性。 [Figure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.figure) 或[Floater](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.floater)元素通常用于突出显示或强调部分的内容，到主机的支持图像或其他内容中的主内容流，或用于插入松散相关内容，例如广告。

下面的示例演示如何嵌入[Figure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.figure)到一个段落的文本。

XAML复制

```xaml
<FlowDocument xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">

  <Paragraph>
    <Figure 
      Width="300" Height="100" 
      Background="GhostWhite" HorizontalAnchor="PageLeft" >
      <Paragraph FontStyle="Italic" Background="Beige" Foreground="DarkGreen" >
        A Figure embeds content into flow content with placement properties 
        that can be customized independently from the primary content flow
      </Paragraph>
    </Figure>
    Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy
    nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi
    enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis
    nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure.
  </Paragraph>

</FlowDocument>
```

C#复制

```csharp
using System;
using System.Windows;
using System.Windows.Media;
using System.Windows.Controls;
using System.Windows.Documents;

namespace SDKSample
{
    public partial class FigureExample : Page
    {
        public FigureExample()
        {
 
            // Create strings to use as content.
            string strFigure = "A Figure embeds content into flow content with" +
                               " placement properties that can be customized" +
                               " independently from the primary content flow"; 
            string strOther = "Lorem ipsum dolor sit amet, consectetuer adipiscing" +
                              " elit, sed diam nonummy nibh euismod tincidunt ut laoreet" +
                              " dolore magna aliquam erat volutpat. Ut wisi enim ad" +
                              " minim veniam, quis nostrud exerci tation ullamcorper" +
                              " suscipit lobortis nisl ut aliquip ex ea commodo consequat." +
                              " Duis autem vel eum iriure.";

            // Create a Figure and assign content and layout properties to it.
            Figure myFigure = new Figure();
            myFigure.Width = new FigureLength(300);
            myFigure.Height = new FigureLength(100);
            myFigure.Background = Brushes.GhostWhite;
            myFigure.HorizontalAnchor = FigureHorizontalAnchor.PageLeft;
            Paragraph myFigureParagraph = new Paragraph(new Run(strFigure));
            myFigureParagraph.FontStyle = FontStyles.Italic;
            myFigureParagraph.Background = Brushes.Beige;
            myFigureParagraph.Foreground = Brushes.DarkGreen;
            myFigure.Blocks.Add(myFigureParagraph);

            // Create the paragraph and add content to it.
            Paragraph myParagraph = new Paragraph();
            myParagraph.Inlines.Add(myFigure);
            myParagraph.Inlines.Add(new Run(strOther));

            // Create a FlowDocument and add the paragraph to it.
            FlowDocument myFlowDocument = new FlowDocument();
            myFlowDocument.Blocks.Add(myParagraph);

            this.Content = myFlowDocument;
        }
    }
}
```

下图显示了此示例的呈现效果。

![屏幕快照：Figure](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/flow-ovw-figure-example.png)

[Figure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.figure) 和[Floater](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.floater)在几个方面存在差异，并可用于不同的方案。

**Figure：**

- 可定位：您可以设置其水平和垂直定位点，以停放它相对于页面、 内容、 列或段落。 此外可以使用其[HorizontalOffset](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.figure.horizontaloffset)和[VerticalOffset](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.figure.verticaloffset)属性以指定任意偏移量。
- 是到多个列可调整大小：可以设置[Figure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.figure)高度和宽度设置为页面、 内容或列的高度或宽度的倍数。 请注意，对于页面和内容，倍数不能大于 1。 例如，可以设置的宽度[Figure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.figure)"页面的 0.5"或"0.25 content"或"2 列"。 还可将高度和宽度设置为绝对像素值。
- 不分页：如果中的内容[Figure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.figure)不适合在[Figure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.figure)，它会呈现能够容纳的内容和其余内容将丢失

**Floater：**

- 无法定位，可在能够为其提供空间的任何位置呈现。 不能设置偏移量或定位点[Floater](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.floater)。
- 不能进行大小调整为多个列：默认情况下，[Floater](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.floater)在一列的大小。 它具有[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.floater.width)一列大小为可以设置为绝对像素值，但如果此值大于一个列宽忽略它并将浮动对象的属性。 您可以其大小设置为小于 1 个列宽设置正确的像素宽度，但大小不是列相关，因此"0.5 倍栏宽"不是有效的表达式[Floater](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.floater)宽度。 [Floater](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.floater) 没有高度属性，因此它无法设置高度、 其高度取决于内容
- [Floater](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.floater) 对此进行分页：如果指定宽度其内容扩展到多个列高度，浮标会断开，并显示下一列、 下一页等。

[Figure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.figure) 是的最好的独立内容你想要控制的大小和定位，并且可以确信内容适合指定的大小。 [Floater](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.floater) 是将更多自由流动的内容流类似于主页面内容，但相分离的好时机。

**LineBreak**

[LineBreak](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.linebreak) 导致换行符在流内容中发生。 以下示例演示了 [LineBreak](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.linebreak) 的用法。

XAML复制

```xaml
<FlowDocument xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
  <Paragraph>
    Before the LineBreak in Paragraph.
    <LineBreak />
    After the LineBreak in Paragraph.
    <LineBreak/><LineBreak/>
    After two LineBreaks in Paragraph.
  </Paragraph>

  <Paragraph>
    <LineBreak/>
  </Paragraph>

  <Paragraph>
    After a Paragraph with only a LineBreak in it.
  </Paragraph>
</FlowDocument>
```

下面的屏幕截图显示了此示例的呈现效果。

![屏幕快照：LineBreak 示例](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/flow-ovw-linebreakexample.png)

#### 流集合元素

中的许多示例以上[BlockCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.blockcollection)和[InlineCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inlinecollection)用于以编程方式构造流内容。 例如，若要将元素添加到[Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph)，可以使用语法：

```
…
myParagraph.Inlines.Add(new Run("Some text"));
…
```

这将添加[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run)到[InlineCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inlinecollection)的[Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph)。 这是相同的隐式[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run)内找到[Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph)标记中：

```
…
<Paragraph>
Some Text
</Paragraph>
…
```

例如，使用[BlockCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.blockcollection)，下面的示例创建一个新[Section](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.section)，然后使用**添加**方法将添加一个新[Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph)到[Section](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.section)内容。

C#复制

```csharp
Section secx = new Section();
secx.Blocks.Add(new Paragraph(new Run("A bit of text content...")));
```

除向流集合中添加项之外，还可以移除项。 以下示例删除上次[Inline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline)中的元素[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)。

C#复制

```csharp
spanx.Inlines.Remove(spanx.Inlines.LastInline);
```

以下示例清除所有内容 ([Inline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline)元素) 从[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)。

C#复制

```csharp
spanx.Inlines.Clear();
```

以编程方式使用流内容时，可能会广泛使用这些集合。

流元素是使用是否[InlineCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inlinecollection)（内联） 或[BlockCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.blockcollection)（块） 来包含其子元素取决于子元素的类型 ([Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block)或[Inline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline)) 可以包含在父级。 下一节中的内容架构中概述了流内容元素的包容规则。

**注意：** 没有一种类型的集合可用于流内容[ListItemCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.listitemcollection)，但此集合仅适用于[List](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.list)。 此外，还有多个集合可用于[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)。 请参阅[表概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/table-overview)有关详细信息。



### 内容架构

不同流内容元素的数量是如此之多，因此了解某个元素可包含的子元素类型非常困难。 下面的关系图概述了流元素的包容规则。 箭头表示可能存在的父/子关系。

![关系图：流内容包含架构](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/flow-content-schema.png)

从上面的关系图可以看出，元素的子级不一定由它是否[Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block)元素或[Inline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline)元素。 例如， [Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span) ([Inline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline)元素) 只能有[Inline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline)子元素，而[Figure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.figure)(还[Inline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline)元素) 只能有[Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block)子元素。 因此，关系图可用于快速确定哪些元素可以包含在其他元素中。 例如，让我们使用关系图来确定如何构造流内容的[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)。

**1.** 一个[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)必须包含[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)又必须包含[Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block)-派生的对象。 下面是上述关系图中的对应部分。

![关系图：RichTextBox 包含规则](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/flow-ovw-schemawalkthrough1.png)

到此为止，标记可能类似于所示内容。

XAML复制

```xaml
<RichTextBox>
  <FlowDocument>
    <!-- One or more Block-derived object… -->
  </FlowDocument>
</RichTextBox>
```

**2.** 根据关系图中，有几个[Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block)元素可供选择包括[Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph)， [Section](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.section)， [Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)， [List](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.list)，并[BlockUIContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.blockuicontainer)（请参阅上面的 Block 派生类）。 假设我们想[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)。 按照上面，该关系图[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)包含[TableRowGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablerowgroup)包含[TableRow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablerow)元素，其中包含[TableCell](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablecell)元素包含[Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block)-派生的对象。 下面是有关的对应部分[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)取自上述关系图。

![关系图：父/表的子架构](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/flow-ovw-schemawalkthrough2.png)

下面是对应的标记。

XAML复制

```xaml
<RichTextBox>
  <FlowDocument>
    <Table>
      <TableRowGroup>
        <TableRow>
          <TableCell>
            <!-- One or more Block-derived object… -->
          </TableCell>
        </TableRow>
      </TableRowGroup>
    </Table>
  </FlowDocument>
</RichTextBox>
```

**3.** 同样，一个或多个[Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block)下需要元素[TableCell](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablecell)。 为简单起见，在单元格内部放置一些文本。 我们可以使用执行此类情况的操作[Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph)与[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run)元素。 下面是显示的关系图中的对应部分[Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph)花费[Inline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline)元素，而[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run)([Inline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline)元素) 只能采用纯文本。

![关系图：父/paragraph](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/flow-ovw-schemawalkthrough3.png)

![关系图：父/run](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/flow-ovw-schemawalkthrough4.png)

下面是标记中的完整示例。

XAML复制

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
  <RichTextBox>
    <FlowDocument>
      
      <!-- Normally a table would have multiple rows and multiple
           cells but this code is for demonstration purposes.-->
      <Table>
        <TableRowGroup>
          <TableRow>
            <TableCell>
              <Paragraph>

                <!-- The schema does not actually require
                     explicit use of the Run tag in markup. It 
                     is only included here for clarity. -->
                <Run>Paragraph in a Table Cell.</Run>
              </Paragraph>
            </TableCell>
          </TableRow>
        </TableRowGroup>
      </Table>

    </FlowDocument>
  </RichTextBox>
</Page>
```

### 自定义文本

通常，文本是流文档中最普遍的内容类型。 尽管上面介绍的对象可用于控制文本呈现方式的大多数方面，但本文还介绍了其他一些自定义文本的方法。

#### 文本修饰

使用文本修饰，可向文本应用下划线、上划线、基线和删除线效果（请参见下图）。 使用添加这些修饰[TextDecorations](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline.textdecorations)由多个包括的对象公开的属性[Inline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline)， [Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph)， [TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)，和[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。

以下示例演示如何设置 [TextDecorations](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph.textdecorations) 的 [Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph) 属性。

```xaml
<FlowDocument ColumnWidth="200">
  <Paragraph TextDecorations="Strikethrough">
    This text will render with the strikethrough effect.
  </Paragraph>
</FlowDocument>
```

```csharp
Paragraph parx = new Paragraph(new Run("This text will render with the strikethrough effect."));
parx.TextDecorations = TextDecorations.Strikethrough;
```

下图显示了此示例的呈现效果。

![屏幕快照：具有默认删除线效果的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/inline-textdec-strike.png)

下图显示如何**上划线**，**基线**，并**用下划线标出**修饰的呈现效果，分别。

![屏幕快照：上划线 TextDecorator](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/inline-textdec-over.png)

![屏幕快照：默认基线效果的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/inline-textdec-base.png)

![屏幕快照：具有默认下划线效果的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/inline-textdec-under.png)

#### 版式

[Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.textelement.typography)属性由大多数与流相关内容包括[TextElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.textelement)， [FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)， [TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)，和[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。 此属性用于控制文本的版式特征/变体（即小型大写字母或大型大写字母、设置上标和下标等）。

下面的示例演示如何设置[Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.textelement.typography)属性，使用[Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph)作为示例元素。

```xaml
<Paragraph
  TextAlignment="Left"
  FontSize="18" 
  FontFamily="Palatino Linotype"
  Typography.NumeralStyle="OldStyle"
  Typography.Fraction="Stacked"
  Typography.Variants="Inferior"
>
  <Run>
    This text has some altered typography characteristics.  Note
    that use of an open type font is necessary for most typographic
    properties to be effective.
  </Run>
  <LineBreak/><LineBreak/>
  <Run>
    0123456789 10 11 12 13
  </Run>
  <LineBreak/><LineBreak/>
  <Run>
    1/2 2/3 3/4
  </Run>
</Paragraph>
```

下图显示了此示例的呈现效果。

![屏幕快照：改变版式的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/textelement-typog.png)

与此相反，下图显示了一个具有默认版式属性的类似示例的呈现效果。

![屏幕快照：改变版式的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/textelement-typog-default.png)

下面的示例演示如何设置[Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.typography)属性以编程方式。

```csharp
Paragraph par = new Paragraph();

Run runText = new Run(
    "This text has some altered typography characteristics.  Note" +
    "that use of an open type font is necessary for most typographic" +
    "properties to be effective.");
Run runNumerals = new Run("0123456789 10 11 12 13");
Run runFractions = new Run("1/2 2/3 3/4");

par.Inlines.Add(runText);
par.Inlines.Add(new LineBreak());
par.Inlines.Add(new LineBreak());
par.Inlines.Add(runNumerals);
par.Inlines.Add(new LineBreak());
par.Inlines.Add(new LineBreak());
par.Inlines.Add(runFractions);

par.TextAlignment = TextAlignment.Left;
par.FontSize = 18;
par.FontFamily = new FontFamily("Palatino Linotype");

par.Typography.NumeralStyle = FontNumeralStyle.OldStyle;
par.Typography.Fraction = FontFraction.Stacked;
par.Typography.Variants = FontVariants.Inferior;
```

请参阅[WPF 中的版式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/typography-in-wpf)有关版式的详细信息。

## [TextElement Content Model Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/textelement-content-model-overview)

此内容模型概述介绍了支持的内容[TextElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.textelement)。 [Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph)类是一种[TextElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.textelement)。 内容模型描述哪些对象/元素可包含在其他对象/元素中。 本概述概括了用于从派生的对象的内容模型[TextElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.textelement)。 有关详细信息，请参阅[流文档概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/flow-document-overview)。

### 内容模型图

下图概括了内容模型，用于类派生自[TextElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.textelement)以及其他非`TextElement`适应此模型的类。

![关系图：流内容包含架构](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/flow-content-schema.png)

如上面的关系图所示，元素的子级不一定由类是否派生自[Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block)类或[Inline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline)类。 例如， [Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span) ([Inline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline)的派生类) 只能有[Inline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline)子元素，但[Figure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.figure)(还[Inline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline)的派生类) 只能有[Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block)子元素。 因此，关系图可用于快速确定哪些元素可以包含在其他元素中。 例如，让我们使用关系图来确定如何构造流内容的[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)。

1. 一个[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)必须包含[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)又必须包含[Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block)-派生的对象。 以下是上述关系图中的相应部分。

   ![关系图：RichTextBox 包含规则](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/flow-ovw-schemawalkthrough1.png)

   到此为止，标记可能类似于所示内容。

   XAML复制

   ```xaml
   <RichTextBox>
     <FlowDocument>
       <!-- One or more Block-derived object… -->
     </FlowDocument>
   </RichTextBox>
   ```

2. 根据关系图中，有几个[Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block)元素可供选择包括[Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph)， [Section](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.section)， [Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)， [List](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.list)，并[BlockUIContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.blockuicontainer)（请参阅上图中的 Block 派生类）。 假设我们想[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)。 上图中，根据[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)包含[TableRowGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablerowgroup)包含[TableRow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablerow)元素，其中包含[TableCell](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablecell)元素包含[Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block)-派生的对象。 以下是有关的对应部分[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)取自上述关系图。

   ![关系图：父/表的子架构](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/flow-ovw-schemawalkthrough2.png)

   下面是相应的标记。

   XAML复制

   ```xaml
   <RichTextBox>
     <FlowDocument>
       <Table>
         <TableRowGroup>
           <TableRow>
             <TableCell>
               <!-- One or more Block-derived object… -->
             </TableCell>
           </TableRow>
         </TableRowGroup>
       </Table>
     </FlowDocument>
   </RichTextBox>
   ```

3. 同样，一个或多个[Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block)下需要元素[TableCell](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablecell)。 为简单起见，在单元格内部放置一些文本。 我们可以使用执行此类情况的操作[Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph)与[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run)元素。 下面是显示的关系图中的对应部分[Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph)花费[Inline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline)元素，而[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run)([Inline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline)元素) 只能采用纯文本。

   ![关系图：父/paragraph](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/flow-ovw-schemawalkthrough3.png)

   ![关系图：父/run](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/flow-ovw-schemawalkthrough4.png)

下面是标记中的完整示例。

XAML复制

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
  <RichTextBox>
    <FlowDocument>
      
      <!-- Normally a table would have multiple rows and multiple
           cells but this code is for demonstration purposes.-->
      <Table>
        <TableRowGroup>
          <TableRow>
            <TableCell>
              <Paragraph>

                <!-- The schema does not actually require
                     explicit use of the Run tag in markup. It 
                     is only included here for clarity. -->
                <Run>Paragraph in a Table Cell.</Run>
              </Paragraph>
            </TableCell>
          </TableRow>
        </TableRowGroup>
      </Table>

    </FlowDocument>
  </RichTextBox>
</Page>
```



### 以编程方式处理 TextElement 内容

内容[TextElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.textelement)组成的集合，因此以编程方式操作的内容[TextElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.textelement)对象通过使用这些集合。 有三个不同的集合使用[TextElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.textelement)-派生的类：

- [InlineCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inlinecollection)：表示 [Inline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline) 元素的集合。 [InlineCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inlinecollection) 定义 [Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph)、[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span) 和 [TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock) 元素允许的子内容。
- [BlockCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.blockcollection)：表示 [Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block) 元素的集合。 [BlockCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.blockcollection) 定义 [FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)、[Section](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.section)、[ListItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.listitem)、[TableCell](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablecell)、[Floater](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.floater) 和 [Figure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.figure) 元素允许的子内容。
- [ListItemCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.listitemcollection)：流内容元素，表示特定内容项中有序或无序[List](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.list)。

您可以操作 （添加或删除项目） 从这些集合使用的相应属性**Inlines**，**块**，和**ListItems**。 以下示例演示如何操作 s p a n 使用的内容**Inlines**属性。

> 表格使用多个集合来操作其内容，但这里不对其进行说明。 有关详细信息，请参阅[表概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/table-overview)。

下面的示例创建一个新[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)对象，然后使用`Add`方法添加两个文本运行的子内容作为[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)。

```csharp
Span spanx = new Span();
spanx.Inlines.Add(new Run("A bit of text content..."));
spanx.Inlines.Add(new Run("A bit more text content..."));
```

下面的示例创建一个新[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run)元素，并将它插入的开始处[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)。

```csharp
Run runx = new Run("Text to insert...");
spanx.Inlines.InsertBefore(spanx.Inlines.FirstInline, runx);
```

以下示例删除上次[Inline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline)中的元素[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)。

```csharp
spanx.Inlines.Remove(spanx.Inlines.LastInline);
```

以下示例清除所有内容 ([Inline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline)元素) 从[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)。

```csharp
spanx.Inlines.Clear();
```

### 共享此内容模型的类型

以下类型均继承自[TextElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.textelement)类，并可用于显示本概述中所述的内容。

[Bold](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.bold), [Figure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.figure), [Floater](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.floater), [Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink), [InlineUIContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inlineuicontainer), [Italic](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.italic), [LineBreak](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.linebreak), [List](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.list), [ListItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.listitem), [Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph), [Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run), [Section](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.section), [Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span),[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table), [Underline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.underline).

请注意，此列表仅包含一起分发的非抽象类型Windows SDK。 你可能会使用继承自其他类型[TextElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.textelement)。

### 可包含 TextElement 对象的类型

请参阅[WPF 内容模型](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/wpf-content-model)。

## [Table Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/table-overview)

[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table) 为支持流文档内容的基于网格的表示形式的块级别元素。 此元素极具灵活性，因此很有用，但也因此显得更加复杂，从而不容易理解和正确使用。

本主题包含以下各节：

- [表基础](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/table-overview#table_basics)
- [表与网格有什么区别？](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/table-overview#table_vs_Grid)
- [基本表结构](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/table-overview#basic_table_structure)
- [表包含](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/table-overview#table_containment)
- [行分组](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/table-overview#row_groupings)
- [背景呈现优先级](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/table-overview#rendering_precedence)
- [跨行或列](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/table-overview#spanning_rows_or_columns)
- [使用代码生成表](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/table-overview#building_a_table_with_code)
- [相关主题]

### 表基础

#### 表与网格有什么区别？

[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table) 和[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)共享某些通用功能，但每个都是最适用于不同的方案。 一个[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)专为流内容内使用 (请参阅[流文档概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/flow-document-overview)有关流内容的详细信息)。 网格最适合在表单内（主要在流内容以外的任意位置）使用。 内[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)，[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)支持流内容行为，如分页、 列重排和内容时选择[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)却没有。 一个[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)另一方面最好使用之外[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)包括的原因有很多[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)根据行和列索引添加元素[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)却没有。 [Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素可对子内容，从而允许多个元素共存于单个"单元格。"内进行分层 [Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table) 不支持分层。 子元素的[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)相对于其"单元格"边界区域进行绝对定位。 [Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table) 不支持此功能。 最后，[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)需要较少的资源，然后[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)因此请考虑使用[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)以提高性能。

#### 基本表结构

[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table) 提供基于网格的表示形式，包括列 (由[TableColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablecolumn)元素) 和行 (由[TableRow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablerow)元素)。 [TableColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablecolumn) 元素不承载的内容;它们只需定义列和列的特征。 [TableRow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablerow) 元素必须承载于[TableRowGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablerowgroup)元素，它定义的表中行的分组。 [TableCell](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablecell) 元素，其中包含要显示的表的实际内容，必须承载于[TableRow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablerow)元素。 [TableCell](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablecell) 只能包含派生的元素[Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block)。 有效子元素[TableCell](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablecell)包括。

- [BlockUIContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.blockuicontainer)
- [List](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.list)
- [Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph)
- [Section](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.section)
- [Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)

 备注

[TableCell](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablecell) 元素不能直接承载文本内容。 有关流的包含规则的详细信息之类的内容元素[TableCell](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablecell)，请参阅[流文档概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/flow-document-overview)。

 备注

[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table) 类似于[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素但具有更多功能，因此，需要更大的资源开销。

下面的示例定义一个简单的 2 x 3 个表与XAML。

XAML复制

```xaml
<!-- 
  Table is a Block element, and as such must be hosted in a container
  for Block elements.  FlowDocument provides such a container. 
-->
<FlowDocument>
  <Table>
    <!-- 
      This table has 3 columns, each described by a TableColumn 
      element nested in a Table.Columns collection element. 
    -->
    <Table.Columns>
      <TableColumn />
      <TableColumn />
      <TableColumn />
    </Table.Columns>
    <!-- 
      This table includes a single TableRowGroup which hosts 2 rows,
      each described by a TableRow element.
    -->
    <TableRowGroup>
      <!--
        Each of the 2 TableRow elements hosts 3 cells, described by
        TableCell elements.
      -->
      <TableRow>
        <TableCell>
          <!-- 
            TableCell elements may only host elements derived from Block.
            In this example, Paragaph elements serve as the ultimate content
            containers for the cells in this table.
          -->
          <Paragraph>Cell at Row 1 Column 1</Paragraph>
        </TableCell>
        <TableCell>
          <Paragraph>Cell at Row 1 Column 2</Paragraph>
        </TableCell>
        <TableCell>
          <Paragraph>Cell at Row 1 Column 3</Paragraph>
        </TableCell>
      </TableRow>
      <TableRow>
        <TableCell>
          <Paragraph>Cell at Row 2 Column 1</Paragraph>
        </TableCell>
        <TableCell>
          <Paragraph>Cell at Row 2 Column 2</Paragraph>
        </TableCell>
        <TableCell>
          <Paragraph>Cell at Row 2 Column 3</Paragraph>
        </TableCell>
      </TableRow>
    </TableRowGroup>
  </Table>
</FlowDocument>
```

下图显示了此示例的呈现效果。

![屏幕快照：呈现一个基本表](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/basictablerrender.png)



#### 表包容

[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table) 派生自[Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block)元素，并遵循的常见规则[Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block)级别元素。 一个[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)元素可包含任何以下元素：

- [FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)
- [TableCell](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablecell)
- [ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)
- [ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listviewitem)
- [Section](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.section)
- [Floater](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.floater)
- [Figure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.figure)



#### 行分组

[TableRowGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablerowgroup)元素提供任意表中的组行的方式; 表中的每一行必须属于一个行分组。 行分组中的行通常具有相同的用途，并可作为一个组来设置样式。 行分组的一个常见使用方式是用于将特定用途的行（如标题行、标头和页脚行）与表中所含的主内容分隔开来。

下面的示例使用XAML定义具有带样式的页眉和页脚行的表。

XAML复制

```xaml
<Table>
  <Table.Resources>
    <!-- Style for header/footer rows. -->
    <Style x:Key="headerFooterRowStyle" TargetType="{x:Type TableRowGroup}">
      <Setter Property="FontWeight" Value="DemiBold"/>
      <Setter Property="FontSize" Value="16"/>
      <Setter Property="Background" Value="LightGray"/>
    </Style>

    <!-- Style for data rows. -->
    <Style x:Key="dataRowStyle" TargetType="{x:Type TableRowGroup}">
      <Setter Property="FontSize" Value="12"/>
      <Setter Property="FontStyle" Value="Italic"/>
    </Style>
  </Table.Resources>
  
  <Table.Columns>
    <TableColumn/> <TableColumn/> <TableColumn/> <TableColumn/>
  </Table.Columns>

  <!-- This TableRowGroup hosts a header row for the table. -->
  <TableRowGroup Style="{StaticResource headerFooterRowStyle}">
    <TableRow>
      <TableCell/>
      <TableCell><Paragraph>Gizmos</Paragraph></TableCell>
      <TableCell><Paragraph>Thingamajigs</Paragraph></TableCell>
      <TableCell><Paragraph>Doohickies</Paragraph></TableCell>
    </TableRow>
  </TableRowGroup>
  
  <!-- This TableRowGroup hosts the main data rows for the table. -->
  <TableRowGroup Style="{StaticResource dataRowStyle}">
    <TableRow>
      <TableCell><Paragraph Foreground="Blue">Blue</Paragraph></TableCell>
      <TableCell><Paragraph>1</Paragraph></TableCell>
      <TableCell><Paragraph>2</Paragraph></TableCell>
      <TableCell><Paragraph>3</Paragraph> </TableCell>
    </TableRow>
    <TableRow>
      <TableCell><Paragraph Foreground="Red">Red</Paragraph></TableCell>
      <TableCell><Paragraph>1</Paragraph></TableCell>
      <TableCell><Paragraph>2</Paragraph></TableCell>
      <TableCell><Paragraph>3</Paragraph></TableCell>
    </TableRow>
    <TableRow>
      <TableCell><Paragraph Foreground="Green">Green</Paragraph></TableCell>
      <TableCell><Paragraph>1</Paragraph></TableCell>
      <TableCell><Paragraph>2</Paragraph></TableCell>
      <TableCell><Paragraph>3</Paragraph></TableCell>
    </TableRow>
  </TableRowGroup>

  <!-- This TableRowGroup hosts a footer row for the table. -->
  <TableRowGroup Style="{StaticResource headerFooterRowStyle}">
    <TableRow>
      <TableCell><Paragraph>Totals</Paragraph></TableCell>
      <TableCell><Paragraph>3</Paragraph></TableCell>
      <TableCell><Paragraph>6</Paragraph></TableCell>
      <TableCell>
        <Table></Table>
      </TableCell>
    </TableRow>
  </TableRowGroup>
</Table>
```

下图显示了此示例的呈现效果。

![屏幕快照：表行进行分组](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/table-rowgroups.png)



#### 背景呈现优先级

表元素以下列顺序呈现（按 Z 顺序从最低到最高排列）。 此顺序不能更改。 例如，对于这些元素，没有可用于替换此已有顺序的“Z 顺序”属性。

1. [Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)
2. [TableColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablecolumn)
3. [TableRowGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablerowgroup)
4. [TableRow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablerow)
5. [TableCell](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablecell)

请参考以下示例，该示例对表内每个元素的背景色进行定义。

XAML复制

```xaml
<Table Background="Yellow">
  <Table.Columns>
    <TableColumn/>
    <TableColumn Background="LightGreen"/>
    <TableColumn/>
  </Table.Columns>
  <TableRowGroup>
    <TableRow>
      <TableCell/><TableCell/><TableCell/>
    </TableRow>
  </TableRowGroup>
  <TableRowGroup Background="Tan">
    <TableRow>
      <TableCell/><TableCell/><TableCell/>
    </TableRow>
    <TableRow Background="LightBlue">
      <TableCell/><TableCell Background="Purple"/><TableCell/>
    </TableRow>
    <TableRow>
      <TableCell/><TableCell/><TableCell/>
    </TableRow>
  </TableRowGroup>
  <TableRowGroup>
    <TableRow>
      <TableCell/><TableCell/><TableCell/>
    </TableRow>
  </TableRowGroup>
</Table>
```

下图显示了此示例的呈现方式（仅显示背景色）。

![屏幕快照：表 z-顺序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/table-zorder.png)



#### 跨行或列

表格单元格可能配置为使用跨越多个行或列[RowSpan](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablecell.rowspan)或[ColumnSpan](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablecell.columnspan)特性分别。

请参考以下示例，该示例中有一个跨三列的单元格。

XAML复制

```xaml
<Table>
  <Table.Columns>
    <TableColumn/>
    <TableColumn/>
    <TableColumn/>
  </Table.Columns>

  <TableRowGroup>
    <TableRow>
      <TableCell ColumnSpan="3" Background="Cyan">
        <Paragraph>This cell spans all three columns.</Paragraph>
      </TableCell>
    </TableRow>
    <TableRow>
      <TableCell Background="LightGray"><Paragraph>Cell 1</Paragraph></TableCell>
      <TableCell Background="LightGray"><Paragraph>Cell 2</Paragraph></TableCell>
      <TableCell Background="LightGray"><Paragraph>Cell 3</Paragraph></TableCell>
    </TableRow>
  </TableRowGroup>
</Table>
```

下图显示了此示例的呈现效果。

![屏幕快照：跨全部三列的单元格](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/table-columnspan.png)



### 使用代码生成表

以下示例演示如何以编程方式创建[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)并填充其内容。 表的内容被分为五个行 (由[TableRow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablerow)中所含对象[RowGroups](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table.rowgroups)对象) 和六列 (由[TableColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablecolumn)对象)。 各行用于不同的显示目的，其中，标题行用于显示整个表的标题，标头行用于描述表中的数据列，而页脚行则包含摘要信息。 请注意，“标题”行、“标头”行和“页脚”行并非表格所固有的，它们只是具有不同特征的行。 表单元格包含实际内容，可以包含文本、 图像或几乎任何其他用户界面 (UI)元素。

首先，[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)创建到主机[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)，和一个新[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)被创建并添加到的内容[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)。

```csharp
// Create the parent FlowDocument...
flowDoc = new FlowDocument();

// Create the Table...
table1 = new Table();
// ...and add it to the FlowDocument Blocks collection.
flowDoc.Blocks.Add(table1);


// Set some global formatting properties for the table.
table1.CellSpacing = 10;
table1.Background = Brushes.White;
```

下一步，六[TableColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablecolumn)创建对象，并添加到表的[Columns](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table.columns)集合中的，同时应用某些格式设置。

 备注

请注意，表的[Columns](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table.columns)集合使用标准的从零开始索引。

C#复制

```csharp
// Create 6 columns and add them to the table's Columns collection.
int numberOfColumns = 6;
for (int x = 0; x < numberOfColumns; x++)
{
    table1.Columns.Add(new TableColumn());

    // Set alternating background colors for the middle colums.
    if(x%2 == 0)
        table1.Columns[x].Background = Brushes.Beige;
    else
        table1.Columns[x].Background = Brushes.LightSteelBlue;
}
```

接下来，创建一个标题行，并将其添加到表中，同时应用某些格式设置。 标题行包含一个单元格，该单元格跨表中的全部六列。

C#复制

```csharp
// Create and add an empty TableRowGroup to hold the table's Rows.
table1.RowGroups.Add(new TableRowGroup());

// Add the first (title) row.
table1.RowGroups[0].Rows.Add(new TableRow());

// Alias the current working row for easy reference.
TableRow currentRow = table1.RowGroups[0].Rows[0];

// Global formatting for the title row.
currentRow.Background = Brushes.Silver;
currentRow.FontSize = 40;
currentRow.FontWeight = System.Windows.FontWeights.Bold;

// Add the header row with content, 
currentRow.Cells.Add(new TableCell(new Paragraph(new Run("2004 Sales Project"))));
// and set the row to span all 6 columns.
currentRow.Cells[0].ColumnSpan = 6;
```

接下来，创建一个标头行并将其添加到表中，同时创建标头行中的单元格并填充其内容。

C#复制

```csharp
// Add the second (header) row.
table1.RowGroups[0].Rows.Add(new TableRow());
currentRow = table1.RowGroups[0].Rows[1];

// Global formatting for the header row.
currentRow.FontSize = 18;
currentRow.FontWeight = FontWeights.Bold;

// Add cells with content to the second row.
currentRow.Cells.Add(new TableCell(new Paragraph(new Run("Product"))));
currentRow.Cells.Add(new TableCell(new Paragraph(new Run("Quarter 1"))));
currentRow.Cells.Add(new TableCell(new Paragraph(new Run("Quarter 2"))));
currentRow.Cells.Add(new TableCell(new Paragraph(new Run("Quarter 3"))));
currentRow.Cells.Add(new TableCell(new Paragraph(new Run("Quarter 4"))));
currentRow.Cells.Add(new TableCell(new Paragraph(new Run("TOTAL"))));
```

接下来，创建一个数据行并将其添加到表中，同时创建此行中的单元格并填充其内容。 生成此行的过程与生成标头行的过程类似，只是应用的格式设置略有不同。

C#复制

```csharp
// Add the third row.
table1.RowGroups[0].Rows.Add(new TableRow());
currentRow = table1.RowGroups[0].Rows[2];

// Global formatting for the row.
currentRow.FontSize = 12;
currentRow.FontWeight = FontWeights.Normal;

// Add cells with content to the third row.
currentRow.Cells.Add(new TableCell(new Paragraph(new Run("Widgets"))));
currentRow.Cells.Add(new TableCell(new Paragraph(new Run("$50,000"))));
currentRow.Cells.Add(new TableCell(new Paragraph(new Run("$55,000"))));
currentRow.Cells.Add(new TableCell(new Paragraph(new Run("$60,000"))));
currentRow.Cells.Add(new TableCell(new Paragraph(new Run("$65,000"))));
currentRow.Cells.Add(new TableCell(new Paragraph(new Run("$230,000"))));

// Bold the first cell.
currentRow.Cells[0].FontWeight = FontWeights.Bold;
```

最后，创建、添加脚注行并设置其格式。 与标题行类似，脚注包含的单元格的跨度为表中的全部六列。

C#复制

```csharp
table1.RowGroups[0].Rows.Add(new TableRow());
currentRow = table1.RowGroups[0].Rows[3];

// Global formatting for the footer row.
currentRow.Background = Brushes.LightGray;
currentRow.FontSize = 18;
currentRow.FontWeight = System.Windows.FontWeights.Normal;

// Add the header row with content, 
currentRow.Cells.Add(new TableCell(new Paragraph(new Run("Projected 2004 Revenue: $810,000"))));
// and set the row to span all 6 columns.
currentRow.Cells[0].ColumnSpan = 6;
```

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/flow-content-elements-how-to-topics)

本部分中的主题介绍如何完成使用各种流内容元素和相关的功能的常见任务。

[调整段落间距](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-adjust-spacing-between-paragraphs)
[以编程方式生成表](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-build-a-table-programmatically)
[以编程方式更改内容的 FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-change-the-flowdirection-of-content-programmatically)
[以编程方式更改 TextWrapping 属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-change-the-textwrapping-property-programmatically)
[使用 XAML 定义表](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-define-a-table-with-xaml)
[修改文本版式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-alter-the-typography-of-text)
[启用文本截断](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-enable-text-trimming)
[以编程方式将元素插入文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-insert-an-element-into-text-programmatically)
[通过 Blocks 属性控制流内容元素](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-manipulate-flow-content-elements-through-the-blocks-property)
[通过 Inlines 属性控制流内容元素](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-manipulate-flow-content-elements-through-the-inlines-property)
[通过 Blocks 属性控制 FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-manipulate-a-flowdocument-through-the-blocks-property)
[通过 Columns 属性控制表列](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-manipulate-table-columns-through-the-columns-property)
[通过 RowGroups 属性操作表的行组](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-manipulate-table-row-groups-through-the-rowgroups-property)
[使用流内容元素](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-use-flow-content-elements)
[使用 FlowDocument 列分隔特性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-use-flowdocument-column-separating-attributes)

### [Adjust Spacing Between Paragraphs](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-adjust-spacing-between-paragraphs)

此示例演示如何调整或消除在流内容中的段落之间的间距。

在流内容段落之间出现的额外空间是距这些段落; 上设置的结果因此，可以通过调整这些段落上的边距控制段落之间的间距。 若要完全消除两个段落的额外间距，请将设置到段落的边距**0**。 若要实现在整个整个段落的统一间距[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)，使用样式来设置中的所有段落一个统一的边距值[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)。

请务必注意，两个相邻段落的边距将"折叠"较大的两个边距，而不是相加。 因此，如果两个相邻段落分别具有 20 像素和 40 个像素的边距，段落之间生成的空间将是 40 像素，较大的两个边距值。

下面的示例使用样式来将边距设置所有[Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph)中的元素[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)到**0**，这有效地消除段落中的额外间距[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)。

XAML复制

```xaml
<FlowDocument>
  <FlowDocument.Resources>
    <!-- This style is used to set the margins for all paragraphs in the FlowDocument to 0. -->
    <Style TargetType="{x:Type Paragraph}">
      <Setter Property="Margin" Value="0"/>
    </Style>
  </FlowDocument.Resources>

  <Paragraph>
    Spacing between paragraphs is caused by margins set on the paragraphs.  Two adjacent margins
    will "collapse" to the larger of the two margin widths, rather than doubling up.
  </Paragraph>

  <Paragraph>
    To eliminate extra spacing between two paragraphs, just set the paragraph margins to 0.
  </Paragraph>
</FlowDocument>
```

### [Build a Table Programmatically](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-build-a-table-programmatically)

以下示例演示如何以编程方式创建[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)并填充其内容。 表的内容被分为五个行 (由[TableRow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablerow)中所含对象[RowGroups](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table.rowgroups)对象) 和六列 (由[TableColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablecolumn)对象)。 各行用于不同的显示目的，其中，标题行用于显示整个表的标题，标头行用于描述表中的数据列，而页脚行则包含摘要信息。 请注意，“标题”行、“标头”行和“页脚”行并非表格所固有的，它们只是具有不同特征的行。 表单元格包含实际内容，可以包含文本、 图像或几乎任何其他用户界面 (UI)元素。

首先，[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)创建到主机[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)，和一个新[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)被创建并添加到的内容[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)。

```csharp
// Create the parent FlowDocument...
flowDoc = new FlowDocument();

// Create the Table...
table1 = new Table();
// ...and add it to the FlowDocument Blocks collection.
flowDoc.Blocks.Add(table1);


// Set some global formatting properties for the table.
table1.CellSpacing = 10;
table1.Background = Brushes.White;
```

下一步，六[TableColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablecolumn)创建对象，并添加到表的[Columns](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table.columns)集合中的，同时应用某些格式设置。

> 请注意，表的[Columns](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table.columns)集合使用标准的从零开始索引。

```csharp
// Create 6 columns and add them to the table's Columns collection.
int numberOfColumns = 6;
for (int x = 0; x < numberOfColumns; x++)
{
    table1.Columns.Add(new TableColumn());

    // Set alternating background colors for the middle colums.
    if(x%2 == 0)
        table1.Columns[x].Background = Brushes.Beige;
    else
        table1.Columns[x].Background = Brushes.LightSteelBlue;
}
```

接下来，创建一个标题行，并将其添加到表中，同时应用某些格式设置。 标题行包含一个单元格，该单元格跨表中的全部六列。

```csharp
// Create and add an empty TableRowGroup to hold the table's Rows.
table1.RowGroups.Add(new TableRowGroup());

// Add the first (title) row.
table1.RowGroups[0].Rows.Add(new TableRow());

// Alias the current working row for easy reference.
TableRow currentRow = table1.RowGroups[0].Rows[0];

// Global formatting for the title row.
currentRow.Background = Brushes.Silver;
currentRow.FontSize = 40;
currentRow.FontWeight = System.Windows.FontWeights.Bold;

// Add the header row with content, 
currentRow.Cells.Add(new TableCell(new Paragraph(new Run("2004 Sales Project"))));
// and set the row to span all 6 columns.
currentRow.Cells[0].ColumnSpan = 6;
```

接下来，创建一个标头行并将其添加到表中，同时创建标头行中的单元格并填充其内容。

```csharp
// Add the second (header) row.
table1.RowGroups[0].Rows.Add(new TableRow());
currentRow = table1.RowGroups[0].Rows[1];

// Global formatting for the header row.
currentRow.FontSize = 18;
currentRow.FontWeight = FontWeights.Bold;

// Add cells with content to the second row.
currentRow.Cells.Add(new TableCell(new Paragraph(new Run("Product"))));
currentRow.Cells.Add(new TableCell(new Paragraph(new Run("Quarter 1"))));
currentRow.Cells.Add(new TableCell(new Paragraph(new Run("Quarter 2"))));
currentRow.Cells.Add(new TableCell(new Paragraph(new Run("Quarter 3"))));
currentRow.Cells.Add(new TableCell(new Paragraph(new Run("Quarter 4"))));
currentRow.Cells.Add(new TableCell(new Paragraph(new Run("TOTAL"))));
```

接下来，创建一个数据行并将其添加到表中，同时创建此行中的单元格并填充其内容。 生成此行的过程与生成标头行的过程类似，只是应用的格式设置略有不同。

```csharp
// Add the third row.
table1.RowGroups[0].Rows.Add(new TableRow());
currentRow = table1.RowGroups[0].Rows[2];

// Global formatting for the row.
currentRow.FontSize = 12;
currentRow.FontWeight = FontWeights.Normal;

// Add cells with content to the third row.
currentRow.Cells.Add(new TableCell(new Paragraph(new Run("Widgets"))));
currentRow.Cells.Add(new TableCell(new Paragraph(new Run("$50,000"))));
currentRow.Cells.Add(new TableCell(new Paragraph(new Run("$55,000"))));
currentRow.Cells.Add(new TableCell(new Paragraph(new Run("$60,000"))));
currentRow.Cells.Add(new TableCell(new Paragraph(new Run("$65,000"))));
currentRow.Cells.Add(new TableCell(new Paragraph(new Run("$230,000"))));

// Bold the first cell.
currentRow.Cells[0].FontWeight = FontWeights.Bold;
```

最后，创建、添加脚注行并设置其格式。 与标题行类似，脚注包含的单元格的跨度为表中的全部六列。

```csharp
table1.RowGroups[0].Rows.Add(new TableRow());
currentRow = table1.RowGroups[0].Rows[3];

// Global formatting for the footer row.
currentRow.Background = Brushes.LightGray;
currentRow.FontSize = 18;
currentRow.FontWeight = System.Windows.FontWeights.Normal;

// Add the header row with content, 
currentRow.Cells.Add(new TableCell(new Paragraph(new Run("Projected 2004 Revenue: $810,000"))));
// and set the row to span all 6 columns.
currentRow.Cells[0].ColumnSpan = 6;
```

### [Change the FlowDirection of Content Programmatically](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-change-the-flowdirection-of-content-programmatically)

此示例演示如何以编程方式更改[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)属性[FlowDocumentReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentreader)。

#### 示例

两个[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)会创建元素，每个表示一种可能的值的[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)。 单击按钮时，关联的属性值应用到的内容[FlowDocumentReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentreader)名为`tf1`。 属性值也会写入到[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)名为`txt1`。

```xaml
<StackPanel DockPanel.Dock="Top" Orientation="Horizontal" Margin="0,0,0,10">
  <Button Click="LR">LeftToRight</Button>
  <Button Click="RL">RightToLeft</Button>
</StackPanel>

<TextBlock Name="txt1" DockPanel.Dock="Bottom" Margin="0,50,0,0"/>

<FlowDocumentReader>
  <FlowDocument FontFamily="Arial" Name="tf1">
    <Paragraph>
    Lorem ipsum dolor sit amet, consectetuer adipiscing elit, 
    sed diam nonummy nibh euismod tincidunt ut laoreet dolore 
    magna aliquam erat volutpat.  Ut wisi enim ad minim veniam, 
    quis nostrud exerci tation ullamcorper suscipit lobortis nisl 
    ut aliquip ex ea commodo consequat. Duis autem vel eum iriure.
    Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed 
    diam nonummy nibh euismod tincidunt ut laoreet dolore magna 
    aliquam erat volutpat.  Ut wisi enim ad minim veniam, quis 
    nostrud exerci tation ullamcorper suscipit lobortis nisl ut 
    uliquip ex ea commodo consequat. Duis autem vel eum iriure. 
    Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed 
    diam nonummy nibh euismod tincidunt ut laoreet dolore magna 
    aliquam erat volutpat.  Ut wisi enim ad minim veniam, quis 
    nostrud exerci tation ullamcorper suscipit lobortis nisl ut 
    aliquip ex ea commodo consequat. Duis autem vel eum iriure.
    </Paragraph>
    <Paragraph>
    Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed 
    diam nonummy nibh euismod tincidunt ut laoreet dolore magna 
    aliquam erat volutpat.  Ut wisi enim ad minim veniam, quis 
    nostrud exerci tation ullamcorper suscipit lobortis nisl ut 
    aliquip ex ea commodo consequat. Duis autem vel eum iriure. 
    Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed 
    diam nonummy nibh euismod tincidunt ut laoreet dolore magna 
    aliquam erat volutpat.  Ut wisi enim ad minim veniam, quis 
    nostrud exerci tation ullamcorper suscipit lobortis nisl ut 
    aliquip ex ea commodo consequat. Duis autem vel eum iriure. 
    Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed 
    diam nonummy nibh euismod tincidunt ut laoreet dolore magna 
    aliquam erat volutpat.  Ut wisi enim ad minim veniam, quis 
    nostrud exerci tation ullamcorper suscipit lobortis nisl ut 
    aliquip ex ea commodo consequat. Duis autem vel eum iriure.
    </Paragraph>
  </FlowDocument>
</FlowDocumentReader>
```

#### 示例

与上面定义的按钮单击关联的事件处理在 C# 代码隐藏文件中。

```csharp
private void LR(object sender, RoutedEventArgs e)
{
    tf1.FlowDirection = FlowDirection.LeftToRight;
    txt1.Text = "FlowDirection is now " + tf1.FlowDirection;
}
private void RL(object sender, RoutedEventArgs e)
{
    tf1.FlowDirection = FlowDirection.RightToLeft;
    txt1.Text = "FlowDirection is now " + tf1.FlowDirection;
}
```

### [Change the TextWrapping Property Programmatically](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-change-the-textwrapping-property-programmatically)

下面的代码示例演示如何更改的值[TextWrapping](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.textwrapping)属性以编程方式。

三个[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)元素中放置[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)中的元素XAML。 每个[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)对应于代码中的事件处理程序。 事件处理程序使用相同的名称[TextWrapping](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.textwrapping)值，它们将应用于`txt2`时单击该按钮。 此外中的文本`txt1`([TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)不会显示XAML) 将更新以反映属性中的更改。

XAML复制

```xaml
<StackPanel Orientation="Horizontal" Margin="0,0,0,20">
  <Button Name="btn1" Background="Silver" Width="100" Click="Wrap">Wrap</Button>
  <Button Name="btn2" Background="Silver" Width="100" Click="NoWrap">NoWrap</Button>
  <Button Name="btn4" Background="Silver" Width="100" Click="WrapWithOverflow">WrapWithOverflow</Button>
</StackPanel>

<TextBlock Name="txt2" TextWrapping="Wrap" Margin="0,0,0,20" Foreground="Black">
  Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Lorem ipsum dolor sit amet, 
  consectetuer adipiscing elit.Lorem ipsum dolor sit aet, consectetuer adipiscing elit.
  Lorem ipsum dolor sit amet, consectetuer adipiscing elit.
</TextBlock>
```

C#复制

```csharp
private void Wrap(object sender, RoutedEventArgs e)
{
    txt2.TextWrapping = System.Windows.TextWrapping.Wrap;
    txt1.Text = "The TextWrap property is currently set to Wrap.";
}
private void NoWrap(object sender, RoutedEventArgs e)
{
    txt2.TextWrapping = System.Windows.TextWrapping.NoWrap;
    txt1.Text = "The TextWrap property is currently set to NoWrap.";
}
private void WrapWithOverflow(object sender, RoutedEventArgs e)
{
    txt2.TextWrapping = System.Windows.TextWrapping.WrapWithOverflow;
    txt1.Text = "The TextWrap property is currently set to WrapWithOverflow.";
}
```

### [Define a Table with XAML](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-define-a-table-with-xaml)

下面的示例演示如何定义[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)使用可扩展应用程序标记语言 (XAML)。 示例表有四个列 (由表示[TableColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablecolumn)元素) 和若干行 (由表示[TableRow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablerow)元素) 包含数据以及标题、 页眉和页脚信息。 行必须包含在[TableRowGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablerowgroup)元素。 表中的每个行组成一个或多个单元格 (由表示[TableCell](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablecell)元素)。 在表格单元格的内容必须包含在[Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block)元素; 在这种情况下[Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph)元素中使用。 表也承载超链接 (由表示[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)元素) 中的页脚行。

#### 示例

XAML复制

```xaml
<FlowDocumentReader>
  <FlowDocument>

    <Table CellSpacing="5">

      <Table.Columns>
        <TableColumn/>
        <TableColumn/>
        <TableColumn/>
        <TableColumn/>
      </Table.Columns>

      <TableRowGroup>

        <!-- Title row for the table. -->
        <TableRow Background="SkyBlue">
          <TableCell ColumnSpan="4" TextAlignment="Center">
            <Paragraph FontSize="24pt" FontWeight="Bold">Planetary Information</Paragraph>
          </TableCell>
        </TableRow>

        <!-- Header row for the table. -->
        <TableRow Background="LightGoldenrodYellow">
          <TableCell><Paragraph FontSize="14pt" FontWeight="Bold">Planet</Paragraph></TableCell>
          <TableCell><Paragraph FontSize="14pt" FontWeight="Bold">Mean Distance from Sun</Paragraph></TableCell>
          <TableCell><Paragraph FontSize="14pt" FontWeight="Bold">Mean Diameter</Paragraph></TableCell>
          <TableCell><Paragraph FontSize="14pt" FontWeight="Bold">Approximate Mass</Paragraph></TableCell>
        </TableRow>

        <!-- Sub-title row for the inner planets. -->
        <TableRow>
          <TableCell ColumnSpan="4"><Paragraph FontSize="14pt" FontWeight="Bold">The Inner Planets</Paragraph></TableCell>
        </TableRow>

        <!-- Four data rows for the inner planets. -->
        <TableRow>
          <TableCell><Paragraph>Mercury</Paragraph></TableCell>
          <TableCell><Paragraph>57,910,000 km</Paragraph></TableCell>
          <TableCell><Paragraph>4,880 km</Paragraph></TableCell>
          <TableCell><Paragraph>3.30e23 kg</Paragraph></TableCell>
        </TableRow>
        <TableRow Background="lightgray">
          <TableCell><Paragraph>Venus</Paragraph></TableCell>
          <TableCell><Paragraph>108,200,000 km</Paragraph></TableCell>
          <TableCell><Paragraph>12,103.6 km</Paragraph></TableCell>
          <TableCell><Paragraph>4.869e24 kg</Paragraph></TableCell>
        </TableRow>
        <TableRow>
          <TableCell><Paragraph>Earth</Paragraph></TableCell>
          <TableCell><Paragraph>149,600,000 km</Paragraph></TableCell>
          <TableCell><Paragraph>12,756.3 km</Paragraph></TableCell>
          <TableCell><Paragraph>5.972e24 kg</Paragraph></TableCell>
        </TableRow>
        <TableRow Background="lightgray">
          <TableCell><Paragraph>Mars</Paragraph></TableCell>
          <TableCell><Paragraph>227,940,000 km</Paragraph></TableCell>
          <TableCell><Paragraph>6,794 km</Paragraph></TableCell>
          <TableCell><Paragraph>6.4219e23 kg</Paragraph></TableCell>
        </TableRow>

        <!-- Sub-title row for the outter planets. -->
        <TableRow>
          <TableCell ColumnSpan="4"><Paragraph FontSize="14pt" FontWeight="Bold">The Major Outer Planets</Paragraph></TableCell>
        </TableRow>

        <!-- Four data rows for the major outter planets. -->
        <TableRow>
          <TableCell><Paragraph>Jupiter</Paragraph></TableCell>
          <TableCell><Paragraph>778,330,000 km</Paragraph></TableCell>
          <TableCell><Paragraph>142,984 km</Paragraph></TableCell>
          <TableCell><Paragraph>1.900e27 kg</Paragraph></TableCell>
        </TableRow>
        <TableRow Background="lightgray">
          <TableCell><Paragraph>Saturn</Paragraph></TableCell>
          <TableCell><Paragraph>1,429,400,000 km</Paragraph></TableCell>
          <TableCell><Paragraph>120,536 km</Paragraph></TableCell>
          <TableCell><Paragraph>5.68e26 kg</Paragraph></TableCell>
        </TableRow>
        <TableRow>
          <TableCell><Paragraph>Uranus</Paragraph></TableCell>
          <TableCell><Paragraph>2,870,990,000 km</Paragraph></TableCell>
          <TableCell><Paragraph>51,118 km</Paragraph></TableCell>
          <TableCell><Paragraph>8.683e25 kg</Paragraph></TableCell>
        </TableRow>
        <TableRow Background="lightgray">
          <TableCell><Paragraph>Neptune</Paragraph></TableCell>
          <TableCell><Paragraph>4,504,000,000 km</Paragraph></TableCell>
          <TableCell><Paragraph>49,532 km</Paragraph></TableCell>
          <TableCell><Paragraph>1.0247e26 kg</Paragraph></TableCell>
        </TableRow>

        <!-- Footer row for the table. -->
        <TableRow>
          <TableCell ColumnSpan="4"><Paragraph FontSize="10pt" FontStyle="Italic">
            Information from the 
            <Hyperlink NavigateUri="http://encarta.msn.com/encnet/refpages/artcenter.aspx">Encarta</Hyperlink> 
            web site.
            </Paragraph></TableCell>
        </TableRow>
      
      </TableRowGroup>
    </Table>
  </FlowDocument>
</FlowDocumentReader>
```

下图显示了此示例中定义的表的呈现效果。

![呈现的表。](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/tableeg.png)

### [Alter the Typography of Text](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-alter-the-typography-of-text)

下面的示例演示如何设置[Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.textelement.typography)属性，使用[Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph)作为示例元素。

#### 示例

```xaml
<Paragraph
  TextAlignment="Left"
  FontSize="18" 
  FontFamily="Palatino Linotype"
  Typography.NumeralStyle="OldStyle"
  Typography.Fraction="Stacked"
  Typography.Variants="Inferior"
>
  <Run>
    This text has some altered typography characteristics.  Note
    that use of an open type font is necessary for most typographic
    properties to be effective.
  </Run>
  <LineBreak/><LineBreak/>
  <Run>
    0123456789 10 11 12 13
  </Run>
  <LineBreak/><LineBreak/>
  <Run>
    1/2 2/3 3/4
  </Run>
</Paragraph>
```

下图显示了此示例的呈现效果。

![屏幕快照：改变版式的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/textelement-typog.png)

与此相反，下图显示了一个具有默认版式属性的类似示例的呈现效果。

![屏幕快照：改变版式的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/textelement-typog-default.png)

#### 示例

下面的示例演示如何设置[Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.typography)属性以编程方式。

```csharp
Paragraph par = new Paragraph();

Run runText = new Run(
    "This text has some altered typography characteristics.  Note" +
    "that use of an open type font is necessary for most typographic" +
    "properties to be effective.");
Run runNumerals = new Run("0123456789 10 11 12 13");
Run runFractions = new Run("1/2 2/3 3/4");

par.Inlines.Add(runText);
par.Inlines.Add(new LineBreak());
par.Inlines.Add(new LineBreak());
par.Inlines.Add(runNumerals);
par.Inlines.Add(new LineBreak());
par.Inlines.Add(new LineBreak());
par.Inlines.Add(runFractions);

par.TextAlignment = TextAlignment.Left;
par.FontSize = 18;
par.FontFamily = new FontFamily("Palatino Linotype");

par.Typography.NumeralStyle = FontNumeralStyle.OldStyle;
par.Typography.Fraction = FontFraction.Stacked;
par.Typography.Variants = FontVariants.Inferior;
```

### [Enable Text Trimming](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-enable-text-trimming)

此示例演示了使用情况和中提供的值的效果[TextTrimming](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.texttrimming)枚举。

#### 示例

下面的示例定义[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)具有元素[TextTrimming](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.texttrimming)属性设置。

```xaml
<TextBlock 
  Name="myTextBlock" 
  Margin="20" Background="LightGoldenrodYellow" 
  TextTrimming="WordEllipsis" TextWrapping="NoWrap"
  FontSize="14"
>
  One<LineBreak/>
  two two<LineBreak/>
  Three Three Three<LineBreak/>
  four four four four<LineBreak/>
  Five Five Five Five Five<LineBreak/>
  six six six six six six<LineBreak/>
  Seven Seven Seven Seven Seven Seven Seven
</TextBlock>
```

#### 示例

设置相应[TextTrimming](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.texttrimming)下面演示如何在代码中的属性。

```csharp
myTextBlock.TextTrimming = TextTrimming.CharacterEllipsis;
```

有修整文本的当前三个选项： **CharacterEllipsis**， **WordEllipsis**，和**无**。

当[TextTrimming](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.texttrimming)设置为**CharacterEllipsis**，修整文本并将其使用在接近修整边缘字符处省略号继续。 此设置旨在修整文本以使其更适应修整边界，但可能会导致某些单词仅部分修整。 下图显示在此设置的效果[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)类似于上面定义的一个。

![示例：TextTrimming.CharacterEllipsis](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/texttrimming-character.png)

当[TextTrimming](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.texttrimming)设置为**WordEllipsis**，修整文本并将其与修整边缘最接近的第一个完整单词末尾省略号使用继续。此设置将不会显示部分裁剪后的单词，但不是旨在修整文本真实地与为修整边缘**CharacterEllipsis**设置。 下图显示在此设置的效果[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)上面定义。

![示例：TextTrimming.WordEllipsis](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/texttrimming-word.png)

当[TextTrimming](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.texttrimming)设置为**无**，执行不进行任何文本修整。 在这种情况下，只会将文本裁切到父文本容器的边界。 下图显示在此设置的效果[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)类似于上面定义的一个。

![示例：TextTrimming.None](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/texttrimming-none.png)

### [Insert an Element Into Text Programmatically](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-insert-an-element-into-text-programmatically)

下面的示例演示如何使用两个[TextPointer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.textpointer)对象来指定要应用文本中的范围[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)元素。

#### 示例

```csharp
using System;
using System.Windows;
using System.Windows.Media;
using System.Windows.Controls;
using System.Windows.Documents;

namespace SDKSample
{
    public partial class InsertInlineIntoTextExample : Page
    {
        public InsertInlineIntoTextExample()
        {
 
            // Create a paragraph with a short sentence
            Paragraph myParagraph = new Paragraph(new Run("Neptune has 72 times Earth's volume..."));

            // Create two TextPointers that will specify the text range the Span will cover
            TextPointer myTextPointer1 = myParagraph.ContentStart.GetPositionAtOffset(10);
            TextPointer myTextPointer2 = myParagraph.ContentEnd.GetPositionAtOffset(-5);

            // Create a Span that covers the range between the two TextPointers.
            Span mySpan = new Span(myTextPointer1, myTextPointer2);
            mySpan.Background = Brushes.Red;
            
            // Create a FlowDocument with the paragraph as its initial content.
            FlowDocument myFlowDocument = new FlowDocument(myParagraph);

            this.Content = myFlowDocument;

        }
    }
}
```

下图显示此示例。

![应用于一定范围文本的 Span 元素](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/flow-insertelementintotextprogrammatically.png)

### [Manipulate Flow Content Elements through the Blocks Property](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-manipulate-flow-content-elements-through-the-blocks-property)

这些示例演示一些较常见的操作可通过流内容元素上执行**块**属性。 此属性用于添加和删除项从[BlockCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.blockcollection)。流内容元素，该功能**块**属性包括：

- [Figure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.figure)
- [Floater](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.floater)
- [ListItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.listitem)
- [Section](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.section)
- [TableCell](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablecell)

这些示例恰好使用[Section](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.section)与该流内容元素，但这些技术都适用于托管流内容元素集合的所有元素。

#### 示例

下面的示例创建一个新[Section](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.section)，然后使用**添加**方法添加到新段落**部分**内容。

C#复制

```csharp
Section secx = new Section();
secx.Blocks.Add(new Paragraph(new Run("A bit of text content...")));
```

#### 示例

下面的示例创建一个新[Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph)元素，并将它插入的开始处[Section](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.section)。

C#复制

```csharp
Paragraph parx = new Paragraph(new Run("Text to insert..."));
secx.Blocks.InsertBefore(secx.Blocks.FirstBlock, parx);
```

#### 示例

下面的示例获取的顶级数[Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block)中所含元素[Section](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.section)。

C#复制

```csharp
int countTopLevelBlocks = secx.Blocks.Count;
```

#### 示例

以下示例删除上次[Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block)中的元素[Section](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.section)。

C#复制

```csharp
secx.Blocks.Remove(secx.Blocks.LastBlock);
```

#### 示例

以下示例清除所有内容 ([Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block)元素) 从[Section](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.section)。

C#复制

```csharp
secx.Blocks.Clear();
```

### [Manipulate Flow Content Elements through the Inlines Property](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-manipulate-flow-content-elements-through-the-inlines-property)

这些示例演示一些较常见可内联流内容元素执行的操作 (和容器的此类元素，如[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)) 通过**Inlines**属性。 此属性用于添加和删除项从[InlineCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inlinecollection)。 流内容元素，该功能**Inlines**属性包括：

- [Bold](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.bold)
- [Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)
- [Italic](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.italic)
- [Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph)
- [Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)
- [Underline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.underline)

这些示例恰好使用[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)与该流内容元素，但这些技术都适用于所有元素或控件承载[InlineCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inlinecollection)集合。

#### 示例

下面的示例创建一个新[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)对象，然后使用**添加**方法添加两个文本运行的子内容作为[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)。

C#复制

```csharp
Span spanx = new Span();
spanx.Inlines.Add(new Run("A bit of text content..."));
spanx.Inlines.Add(new Run("A bit more text content..."));
```

#### 示例

下面的示例创建一个新[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run)元素，并将它插入的开始处[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)。

C#复制

```csharp
Run runx = new Run("Text to insert...");
spanx.Inlines.InsertBefore(spanx.Inlines.FirstInline, runx);
```

#### 示例

下面的示例获取的顶级数[Inline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline)中所含元素[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)。

C#复制

```csharp
int countTopLevelInlines = spanx.Inlines.Count;
```

#### 示例

以下示例删除上次[Inline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline)中的元素[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)。

C#复制

```csharp
spanx.Inlines.Remove(spanx.Inlines.LastInline);
```

#### 示例

以下示例清除所有内容 ([Inline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline)元素) 从[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)。

C#复制

```csharp
spanx.Inlines.Clear()
```

### [Manipulate a FlowDocument through the Blocks Property](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-manipulate-a-flowdocument-through-the-blocks-property)

这些示例演示一些较常见的操作可以在执行[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)通过[Blocks](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument.blocks)属性。

#### 示例

下面的示例创建一个新[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)，然后将追加一个新[Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph)元素[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)。

C#复制

```csharp
FlowDocument flowDoc = new FlowDocument(new Paragraph(new Run("A bit of text content...")));
flowDoc.Blocks.Add(new Paragraph(new Run("Text to append...")));
```

#### 示例

下面的示例创建一个新[Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph)元素，并将它插入的开始处[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)。

C#复制

```csharp
Paragraph p = new Paragraph(new Run("Text to insert..."));
flowDoc.Blocks.InsertBefore(flowDoc.Blocks.FirstBlock, p);
```

#### 示例

下面的示例获取的顶级数[Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block)中所含元素[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)。

C#复制

```csharp
int countTopLevelBlocks = flowDoc.Blocks.Count;
```

#### 示例

以下示例删除上次[Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block)中的元素[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)。

C#复制

```csharp
flowDoc.Blocks.Remove(flowDoc.Blocks.LastBlock);
```

#### 示例

以下示例清除所有内容 ([Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block)元素) 从[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)。

C#复制

```csharp
flowDoc.Blocks.Clear();
```

### [Manipulate a Table's Columns through the Columns Property](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-manipulate-table-columns-through-the-columns-property)

此示例演示了一些较常见的操作可通过表的列上执行[Columns](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table.columns)属性。

#### 示例

下面的示例创建一个新表，然后使用[Add](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablecolumncollection.add)方法将列添加到表的[Columns](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table.columns)集合。

C#复制

```csharp
Table tbl = new Table();
int columnsToAdd = 4;
for (int x = 0; x < columnsToAdd; x++)
    tbl.Columns.Add(new TableColumn());
```

#### 示例

下面的示例插入一个新[TableColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablecolumn)。 在索引位置 0，使之成为新的第一列在表中插入新列。

 备注

[TableColumnCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablecolumncollection)集合使用标准的从零开始索引。

C#复制

```csharp
tbl.Columns.Insert(0, new TableColumn());
```

#### 示例

以下示例将访问某些列中的任意属性[TableColumnCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablecolumncollection)集合，通过索引来引用特定列。

C#复制

```csharp
tbl.Columns[0].Width = new GridLength(20);
tbl.Columns[1].Background = Brushes.AliceBlue;
tbl.Columns[2].Width = new GridLength(20);
tbl.Columns[3].Background = Brushes.AliceBlue;
```

#### 示例

下面的示例获取当前由表承载的列数。

C#复制

```csharp
int columns = tbl.Columns.Count;
```

#### 示例

下面的示例通过引用来消除特定列。

C#复制

```csharp
tbl.Columns.Remove(tbl.Columns[3]);
```

#### 示例

下面的示例通过索引来消除特定列。

C#复制

```csharp
tbl.Columns.RemoveAt(2);
```

#### 示例

下面的示例从表的列集合中移除所有列。

C#复制

```csharp
tbl.Columns.Clear();
```

### [Manipulate a Table's Row Groups through the RowGroups Property](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-manipulate-table-row-groups-through-the-rowgroups-property)

此示例演示了一些较常见的操作可通过表的行组上执行[RowGroups](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table.rowgroups)属性。

#### 示例

下面的示例创建一个新表，然后使用[Add](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablerowgroupcollection.add)方法将列添加到表的[RowGroups](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table.rowgroups)集合。

C#复制

```csharp
Table tbl = new Table();
int rowGroupsToAdd = 4;
for (int x = 0; x < rowGroupsToAdd; x++)
    tbl.RowGroups.Add(new TableRowGroup());
```

#### 示例

下面的示例插入一个新[TableRowGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablerowgroup)。 新列插入到索引位置 0，使其新的第一个行组中的表。

 备注

[TableRowGroupCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablerowgroupcollection)集合使用标准的从零开始索引。

C#复制

```csharp
tbl.RowGroups.Insert(0, new TableRowGroup());
```

#### 示例

以下示例将多个行添加到特定[TableRowGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablerowgroup)（由索引指定） 的表中。

C#复制

```csharp
int rowsToAdd = 10;
for (int x = 0; x < rowsToAdd; x++)
    tbl.RowGroups[0].Rows.Add(new TableRow());
```

#### 示例

以下示例将访问某些表中的第一个行组中的行的任意属性。

C#复制

```csharp
// Alias the working TableRowGroup for ease in referencing.
TableRowGroup trg = tbl.RowGroups[0];
trg.Rows[0].Background = Brushes.CornflowerBlue;
trg.Rows[1].FontSize = 24;
trg.Rows[2].ToolTip = "This row's tooltip";
```

#### 示例

以下示例将多个单元格添加到特定[TableRow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablerow)（由索引指定） 的表中。

C#复制

```csharp
int cellsToAdd = 10;
for (int x = 0; x < cellsToAdd; x++)
    tbl.RowGroups[0].Rows[0].Cells.Add(new TableCell(new Paragraph(new Run("Cell " + (x + 1)))));
```

#### 示例

下面的示例访问一些任意方法和属性中的第一个行组中的第一行的单元格。

C#复制

```csharp
// Alias the working for for ease in referencing.
TableRow row = tbl.RowGroups[0].Rows[0];
row.Cells[0].Background = Brushes.PapayaWhip;
row.Cells[1].FontStyle = FontStyles.Italic;
// This call clears all of the content from this cell.
row.Cells[2].Blocks.Clear();
```

#### 示例

下面的示例返回的数[TableRowGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablerowgroup)由表承载的元素。

C#复制

```csharp
int rowGroups = tbl.RowGroups.Count;
```

#### 示例

下面的示例通过引用中删除特定行组。

C#复制

```csharp
tbl.RowGroups.Remove(tbl.RowGroups[0]);
```

#### 示例

下面的示例通过索引中删除特定行组。

C#复制

```csharp
tbl.RowGroups.RemoveAt(0);
```

#### 示例

下面的示例从表的行组集合中移除所有行组。

C#复制

```csharp
tbl.RowGroups.Clear();
```

### [Use Flow Content Elements](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-use-flow-content-elements)

下面的示例演示各种流内容元素及其相关联特性的声明性用法。 演示的元素和特性包括：

- [Bold](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.bold) 元素
- [BreakPageBefore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block.breakpagebefore) 特性
- [FontSize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.textelement.fontsize) 特性
- [Italic](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.italic) 元素
- [LineBreak](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.linebreak) 元素
- [List](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.list) 元素
- [ListItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.listitem) 元素
- [Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph) 元素
- [Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run) 元素
- [Section](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.section) 元素
- [Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span) 元素
- [Variants](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.variants) 属性 （上标和下标）
- [Underline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.underline) 元素

#### 示例

```xaml
<FlowDocument 
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
>
    <Paragraph FontSize="18">Flow Format Example</Paragraph>
  
    <Paragraph>
      Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy 
      nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi 
      enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis 
      nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure.
    </Paragraph>
    <Paragraph>
      Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh 
      euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim 
      ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl 
      ut aliquip ex ea commodo consequat. Duis autem vel eum iriure.
    </Paragraph>

    <Paragraph FontSize="18">More flow elements</Paragraph>
    <Paragraph FontSize="15">Inline, font type and weight, and a List</Paragraph>
    
    <List>
      <ListItem><Paragraph>ListItem 1</Paragraph></ListItem>
      <ListItem><Paragraph>ListItem 2</Paragraph></ListItem>
      <ListItem><Paragraph>ListItem 3</Paragraph></ListItem>
      <ListItem><Paragraph>ListItem 4</Paragraph></ListItem>
      <ListItem><Paragraph>ListItem 5</Paragraph></ListItem>
    </List>

    <Paragraph><Bold>Bolded</Bold></Paragraph>
    <Paragraph><Underline>Underlined</Underline></Paragraph>
    <Paragraph><Bold><Underline>Bolded and Underlined</Underline></Bold></Paragraph>
    <Paragraph><Italic>Italic</Italic></Paragraph>
    
    <Paragraph><Span>The Span element, no inherent rendering</Span></Paragraph>
    <Paragraph><Run>The Run element, no inherent rendering</Run></Paragraph>    

    <Paragraph FontSize="15">Subscript, Superscript</Paragraph>

    <Paragraph>
      <Run Typography.Variants="Superscript">This text is Superscripted.</Run> This text isn't.
    </Paragraph>
    <Paragraph>
      <Run Typography.Variants="Subscript">This text is Subscripted.</Run> This text isn't.
    </Paragraph>
    <Paragraph>
      If a font does not support a particular form (such as Superscript) a default font form will be displayed.
    </Paragraph>
    
    <Paragraph FontSize="15">Blocks, breaks, paragraph</Paragraph>
    
    <Section><Paragraph>A block section of text</Paragraph></Section>
    <Section><Paragraph>Another block section of text</Paragraph></Section>
    
    <Paragraph><LineBreak/></Paragraph>
    <Section><Paragraph>... and another section, preceded by a LineBreak</Paragraph></Section>
    
    <Section BreakPageBefore="True"/>
    <Section><Paragraph>... and another section, preceded by a PageBreak</Paragraph></Section>
        
    <Paragraph>Finally, a paragraph. Note the break between this paragraph ...</Paragraph>
    <Paragraph TextIndent="25">... and this paragraph, and also the left indention.</Paragraph>
        
    <Paragraph><LineBreak/></Paragraph>
    
</FlowDocument>
```

### [Use FlowDocument Column-Separating Attributes](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-use-flowdocument-column-separating-attributes)

此示例演示如何使用的列分隔功能[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)。

#### 示例

下面的示例定义[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)，并将设置[ColumnGap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument.columngap)， [ColumnRuleBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument.columnrulebrush)，和[ColumnRuleWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument.columnrulewidth)属性。 [FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)包含一段的示例内容。

XAML复制

```xaml
<FlowDocumentReader>
  <FlowDocument 
    ColumnGap="20.0" 
    ColumnRuleBrush="DodgerBlue" 
    ColumnRuleWidth="5.0" 
    ColumnWidth="140.0"
>
    <Paragraph  Background="AntiqueWhite" TextAlignment="Left">
      This paragraph has the background set to antique white to make its
      boundaries obvious.

      The column gap is the space between columns; this FlowDocument will
      have a column gap of 20 device-independend pixels.  The column rule
      is a vertical line drawn in the column gap, and is used to visually
      separate columns; this FlowDocument a Dodger-blue column rule that
      is 5 pixels wide.

      The column rule and column gap both take space between columns.  In
      this case, a column gap width of 20 plus a column rule of width of 5
      results in the space between columns being 25 pixels wide, 5 pixels
      for the column rule, and 10 pixels of column gap on either side of the column rule.
    </Paragraph>
  </FlowDocument>
</FlowDocumentReader>
```

下图显示的效果[ColumnGap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument.columngap)， [ColumnRuleBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument.columnrulebrush)，和[ColumnRuleWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument.columnrulewidth)特性在所呈现[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)。

![屏幕快照： FlowDocument Intra 列](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/flowdocumentintracolumn.png)