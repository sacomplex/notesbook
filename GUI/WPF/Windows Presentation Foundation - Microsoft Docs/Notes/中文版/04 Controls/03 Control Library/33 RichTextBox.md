# [RichTextBox](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/richtextbox)

[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)元素定义具有内置功能，例如剪切和粘贴、 丰富文档演示文稿和内容选择支持的编辑控件。

## 本节内容

[RichTextBox 概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/richtextbox-overview)
[帮助主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/richtextbox-how-to-topics)

## [RichTextBox Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/richtextbox-overview)

[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)控件可以显示或编辑流内容，包括段落、 图像、 表、 和的详细信息。 本主题介绍[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)类，并提供有关如何在两者中使用它的示例可扩展应用程序标记语言 (XAML)和C#。

### 使用 TextBox 还是 RichTextBox？

这两[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)和[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)允许用户编辑文本，但是，在不同的方案中使用两个控件。 一个[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)当用户编辑带格式的文本、 图像、 表或其他丰富的内容时，是更好的选择。 例如，编辑文档、 文章或博客需要格式、 图像，最好采用以下等[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)。 一个[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)需系统资源较少则[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)，仅纯文本必须是编辑 （即在窗体中的使用情况） 时，它是理想选择。 请参阅[TextBox 概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/textbox-overview)有关详细信息[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。 下表总结了的主要功能[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)和[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)。

| 控件                                                         | 实时拼写检查 | 上下文菜单 | 等格式设置命令[ToggleBold](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.editingcommands.togglebold)(Ctr + B) | [FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument) 如图像、 段落、 表等内容。 |
| ------------------------------------------------------------ | ------------ | ---------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) | 是           | 是         | 否                                                           | 不是。                                                       |
| [RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox) | 是           | 是         | 是                                                           | 是                                                           |

**注意：** 尽管[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)不支持格式设置相关的名利[ToggleBold](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.editingcommands.togglebold)(Ctr + B)，这两个控件如支持许多基本命令[MoveToLineEnd](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.editingcommands.movetolineend)。

后面将更详细地介绍上表中的功能。



### 创建 RichTextBox

下面的代码演示如何创建[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)用户可以编辑中的丰富内容。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">

    <!-- A RichTextBox with no initial content in it. -->
    <RichTextBox />

</Page>
```

具体而言，在编辑内容[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)是流内容。 流内容可包含许多类型的元素，包括带格式的文本、图像、列表和表格。 有关流文档的详细信息，请参阅[流文档概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/flow-document-overview)。 为了包含流内容[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)主机[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)对象，其中又包含可编辑的内容。 为了演示在流内容[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)，下面的代码演示如何创建[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)带有段落和某些加粗文本。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">

  <StackPanel>
    <RichTextBox>
      <FlowDocument>
        <Paragraph>
          This is flow content and you can <Bold>edit me!</Bold>
        </Paragraph>
      </FlowDocument>
    </RichTextBox>
  </StackPanel>

</Page>
```

C#复制

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Documents;
namespace SDKSample
{
    public partial class BasicRichTextBoxWithContentExample : Page
    {
        public BasicRichTextBoxWithContentExample()
        {
            StackPanel myStackPanel = new StackPanel();

            // Create a FlowDocument to contain content for the RichTextBox.
            FlowDocument myFlowDoc = new FlowDocument();

            // Create a Run of plain text and some bold text.
            Run myRun = new Run("This is flow content and you can ");
            Bold myBold = new Bold(new Run("edit me!"));

            // Create a paragraph and add the Run and Bold to it.
            Paragraph myParagraph = new Paragraph();
            myParagraph.Inlines.Add(myRun);
            myParagraph.Inlines.Add(myBold);

            // Add the paragraph to the FlowDocument.
            myFlowDoc.Blocks.Add(myParagraph);

            RichTextBox myRichTextBox = new RichTextBox();

            // Add initial content to the RichTextBox.
            myRichTextBox.Document = myFlowDoc;
            
            myStackPanel.Children.Add(myRichTextBox);
            this.Content = myStackPanel;
            
        }
    }
}
```

下图显示了此示例的呈现效果。

![RichTextBox with content](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/editing-richtextbox-with-content.png)

之类的元素[Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph)并[Bold](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.bold)确定如何将内容内[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)出现。 当用户编辑[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)内容，这些更改此流内容。 若要了解有关流内容的功能及其工作方式的详细信息，请参阅[流文档概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/flow-document-overview)。

**注意：** 内部的流内容[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)不符的其他控件中包含的流内容与完全相同。 例如，有中的没有列[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)并因此没有自动调整大小行为。 此外，内置的功能，如搜索、 查看模式、 页面导航和缩放中不能[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)。

### 实时拼写检查

可以启用实时拼写检查[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)或[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)。 启用拼写检查时，任何拼写错误的字词下方都会出现红线（见下图）。

![具有拼写检查功能的 Textbox](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/editing-textbox-with-spellchecking.png)

若要了解如何启用拼写检查，请参阅[在文本编辑控件中启用拼写检查](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-enable-spell-checking-in-a-text-editing-control)。

### 上下文菜单

默认情况下，同时[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)和[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)都会在用户右键单击该控件中时，将显示一个上下文菜单。 上下文菜单使用户可以剪切、复制或粘贴（见下图）。

![具有上下文菜单的 TextBox](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/editing-textbox-with-context-menu.png)

可以创建自己的自定义上下文菜单来重写默认的上下文菜单。 有关详细信息，请参阅[在 RichTextBox 中定位自定义上下文菜单](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-position-a-custom-context-menu-in-a-richtextbox)。

### 编辑命令

编辑命令使用户能够在可编辑内容进行格式设置[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)。 除了基本编辑命令，[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)包括格式设置命令的[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)不支持。 例如，在编辑时[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)，用户可以按 Ctr + B 来切换加粗文本格式。 请参阅[EditingCommands](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.editingcommands)有关可用命令的完整列表。 除了使用键盘快捷方式，还可以将命令与按钮之类的其他控件挂钩。 以下示例演示如何创建如何创建简单的工具栏，其中包含用户可用来更改文本格式的按钮。

```xaml
<Window x:Class="RichTextBoxInputPanelDemo.Window1"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml" Height="400" Width="600"
    >
  <Grid>

    <!-- Set the styles for the tool bar. -->
    <Grid.Resources>
      <Style TargetType="{x:Type Button}" x:Key="formatTextStyle">
        <Setter Property="FontFamily" Value="Palatino Linotype"></Setter>
        <Setter Property="Width" Value="30"></Setter>
        <Setter Property="FontSize" Value ="14"></Setter>
        <Setter Property="CommandTarget" Value="{Binding ElementName=mainRTB}"></Setter>
      </Style>

      <Style TargetType="{x:Type Button}" x:Key="formatImageStyle">
        <Setter Property="Width" Value="30"></Setter>
        <Setter Property="CommandTarget" Value="{Binding ElementName=mainRTB}"></Setter>
      </Style>
    </Grid.Resources>

    <DockPanel Name="mainPanel">

      <!-- This tool bar contains all the editing buttons. -->
      <ToolBar Name="mainToolBar" Height="30" DockPanel.Dock="Top">

        <Button Style="{StaticResource formatImageStyle}" Command="ApplicationCommands.Cut" ToolTip="Cut">
          <Image Source="Images\EditCut.png"></Image>
        </Button>
        <Button Style="{StaticResource formatImageStyle}" Command="ApplicationCommands.Copy" ToolTip="Copy">
          <Image Source="Images\EditCopy.png"></Image>
        </Button>
        <Button Style="{StaticResource formatImageStyle}" Command="ApplicationCommands.Paste" ToolTip="Paste">
          <Image Source="Images\EditPaste.png"></Image>
        </Button>
        <Button Style="{StaticResource formatImageStyle}" Command="ApplicationCommands.Undo" ToolTip="Undo">
          <Image Source="Images\EditUndo.png"></Image>
        </Button>
        <Button Style="{StaticResource formatImageStyle}" Command="ApplicationCommands.Redo" ToolTip="Redo">
          <Image Source="Images\EditRedo.png"></Image>
        </Button>

        <Button Style="{StaticResource formatTextStyle}" Command="EditingCommands.ToggleBold" ToolTip="Bold">
          <TextBlock FontWeight="Bold">B</TextBlock>
        </Button>
        <Button Style="{StaticResource formatTextStyle}" Command="EditingCommands.ToggleItalic" ToolTip="Italic">
          <TextBlock FontStyle="Italic" FontWeight="Bold">I</TextBlock>
        </Button>
        <Button Style="{StaticResource formatTextStyle}" Command="EditingCommands.ToggleUnderline" ToolTip="Underline">
          <TextBlock TextDecorations="Underline" FontWeight="Bold">U</TextBlock>
        </Button>
        <Button Style="{StaticResource formatImageStyle}" Command="EditingCommands.IncreaseFontSize" ToolTip="Grow Font">
          <Image Source="Images\CharacterGrowFont.png"></Image>
        </Button>
        <Button Style="{StaticResource formatImageStyle}" Command="EditingCommands.DecreaseFontSize" ToolTip="Shrink Font">
          <Image Source="Images\CharacterShrinkFont.png"></Image>
        </Button>

        <Button Style="{StaticResource formatImageStyle}" Command="EditingCommands.ToggleBullets" ToolTip="Bullets">
          <Image Source="Images\ListBullets.png"></Image>
        </Button>
        <Button Style="{StaticResource formatImageStyle}" Command="EditingCommands.ToggleNumbering" ToolTip="Numbering">
          <Image Source="Images/ListNumbering.png"></Image>
        </Button>
        <Button Style="{StaticResource formatImageStyle}" Command="EditingCommands.AlignLeft" ToolTip="Align Left">
          <Image Source="Images\ParagraphLeftJustify.png"></Image>
        </Button>
        <Button Style="{StaticResource formatImageStyle}" Command="EditingCommands.AlignCenter" ToolTip="Align Center">
          <Image Source="Images\ParagraphCenterJustify.png"></Image>
        </Button>
        <Button Style="{StaticResource formatImageStyle}" Command="EditingCommands.AlignRight" ToolTip="Align Right">
          <Image Source="Images\ParagraphRightJustify.png"></Image>
        </Button>
        <Button Style="{StaticResource formatImageStyle}" Command="EditingCommands.AlignJustify" ToolTip="Align Justify">
          <Image Source="Images\ParagraphFullJustify.png"></Image>
        </Button>
        <Button Style="{StaticResource formatImageStyle}" Command="EditingCommands.IncreaseIndentation" ToolTip="Increase Indent">
          <Image Source="Images\ParagraphIncreaseIndentation.png"></Image>
        </Button>
        <Button Style="{StaticResource formatImageStyle}" Command="EditingCommands.DecreaseIndentation" ToolTip="Decrease Indent">
          <Image Source="Images\ParagraphDecreaseIndentation.png"></Image>
        </Button>

      </ToolBar>

      <!-- By default pressing tab moves focus to the next control. Setting AcceptsTab to true allows the 
           RichTextBox to accept tab characters. -->
      <RichTextBox Name="mainRTB" AcceptsTab="True"></RichTextBox>
    </DockPanel>
  </Grid>
</Window>
```

下图显示此示例的显示效果。

![RichTextBox with ToolBar](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/editing-richtextbox-with-toobar.gif)

### 检测内容何时更改

通常[TextChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.textboxbase.textchanged)用于每当检测到事件中的文本[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)或[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)而不是更改[KeyDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.keydown)正如您所料。 有关示例，请参阅[检测 TextBox 中的文本何时更改](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-detect-when-text-in-a-textbox-has-changed)。

### 保存、加载和打印 RichTextBox 内容

下面的示例演示如何将保存的内容[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)到文件中，该内容重新加载到[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)，以及如何打印内容。下面是示例的标记。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  x:Class="SDKSample.SaveLoadPrintRTB" >

  <StackPanel>
    <RichTextBox Name="richTB">
      <FlowDocument>
        <Paragraph>
          <Run>Paragraph 1</Run>
        </Paragraph>
      </FlowDocument>
    </RichTextBox>

    <Button Click="SaveRTBContent">Save RTB Content</Button>
    <Button Click="LoadRTBContent">Load RTB Content</Button>
    <Button Click="PrintRTBContent">Print RTB Content</Button>
  </StackPanel>

</Page>
```

下面是该示例的隐藏代码。

```csharp
using System;
using System.IO;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Media;

namespace SDKSample
{

    public partial class SaveLoadPrintRTB : Page
    {

        // Handle "Save RichTextBox Content" button click.
        void SaveRTBContent(Object sender, RoutedEventArgs args)
        {

            // Send an arbitrary URL and file name string specifying
            // the location to save the XAML in.
            SaveXamlPackage("C:\\test.xaml");
        }

        // Handle "Load RichTextBox Content" button click.
        void LoadRTBContent(Object sender, RoutedEventArgs args)
        {
            // Send URL string specifying what file to retrieve XAML
            // from to load into the RichTextBox.
            LoadXamlPackage("C:\\test.xaml");
        }

        // Handle "Print RichTextBox Content" button click.
        void PrintRTBContent(Object sender, RoutedEventArgs args)
        {
            PrintCommand();
        }

        // Save XAML in RichTextBox to a file specified by _fileName
        void SaveXamlPackage(string _fileName)
        {
            TextRange range;
            FileStream fStream;
            range = new TextRange(richTB.Document.ContentStart, richTB.Document.ContentEnd);
            fStream = new FileStream(_fileName, FileMode.Create);
            range.Save(fStream, DataFormats.XamlPackage);
            fStream.Close();
        }

        // Load XAML into RichTextBox from a file specified by _fileName
        void LoadXamlPackage(string _fileName)
        {
            TextRange range;
            FileStream fStream;
            if (File.Exists(_fileName))
            {
                range = new TextRange(richTB.Document.ContentStart, richTB.Document.ContentEnd);
                fStream = new FileStream(_fileName, FileMode.OpenOrCreate);
                range.Load(fStream, DataFormats.XamlPackage);
                fStream.Close();
            }
        }

        // Print RichTextBox content
        private void PrintCommand()
        {
            PrintDialog pd = new PrintDialog();
            if ((pd.ShowDialog() == true))
            {
                //use either one of the below      
                pd.PrintVisual(richTB as Visual, "printing as visual");
                pd.PrintDocument((((IDocumentPaginatorSource)richTB.Document).DocumentPaginator), "printing as paginator");
            }
        }
    }
}
```

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/richtextbox-how-to-topics)

本部分提供示例来演示如何完成常见任务使用[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)控件。

### 本节内容

[从 RichTextBox 提取文本内容](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-extract-the-text-content-from-a-richtextbox)
[以编程方式在 RichTextBox 中更改选定内容](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/change-selection-in-a-richtextbox-programmatically)
[保存、加载和打印 RichTextBox 内容](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-save-load-and-print-richtextbox-content)
[在 RichTextBox 中确定自定义上下文菜单的位置](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-position-a-custom-context-menu-in-a-richtextbox)
[如何：将 RichTextBox 的默认内容主机](https://msdn.microsoft.com/library/dec1b2ce-9ca5-4bb2-bf54-f8a80a3c8beb)

### [Extract the Text Content from a RichTextBox](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-extract-the-text-content-from-a-richtextbox)

此示例演示如何将内容提取[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)以纯文本格式。

#### 示例

以下可扩展应用程序标记语言 (XAML)代码描述命名[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)具有简单内容的控件。

```xaml
<RichTextBox Name="richTB">
  <FlowDocument>
    <Paragraph>
      <Run>Paragraph 1</Run>
    </Paragraph>
    <Paragraph>
      <Run>Paragraph 2</Run>
    </Paragraph>
    <Paragraph>
      <Run>Paragraph 3</Run>
    </Paragraph>
  </FlowDocument>
</RichTextBox>
```

#### 示例

下面的代码实现采用的方法[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)作为参数，并返回一个字符串，表示的纯文本内容[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)。

该方法创建一个新[TextRange](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.textrange)中的内容[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)，并使用[ContentStart](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument.contentstart)和[ContentEnd](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument.contentend)以指示要提取的内容的范围。 [ContentStart](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument.contentstart) 并[ContentEnd](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument.contentend)每个属性返回[TextPointer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.textpointer)，并可以访问在表示的内容基础 FlowDocument [RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)。 [TextRange](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.textrange) 提供文本属性，返回的纯文本部分[TextRange](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.textrange)作为字符串。

```csharp
string StringFromRichTextBox(RichTextBox rtb)
{
    TextRange textRange = new TextRange(
        // TextPointer to the start of content in the RichTextBox.
        rtb.Document.ContentStart, 
        // TextPointer to the end of content in the RichTextBox.
        rtb.Document.ContentEnd
    );

    // The Text property on a TextRange object returns a string
    // representing the plain text content of the TextRange.
    return textRange.Text;
}
```

### [Change Selection in a RichTextBox Programmatically](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/change-selection-in-a-richtextbox-programmatically)

此示例演示如何以编程方式更改中的当前选定[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)。 选择此选项是相同的像用户通过使用用户界面选择的内容。

#### 示例

以下可扩展应用程序标记语言 (XAML)代码描述命名[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)具有简单内容的控件。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  x:Class="SDKSample.ChangeSelectionProgrammaticaly" >

  <StackPanel>
    <RichTextBox GotMouseCapture="ChangeSelection" Name="richTB">
      <FlowDocument>
        <Paragraph Name="myParagraph">
          <Run>
            When the user clicks in the RichTextBox, the selected
            text changes programmatically.
          </Run>
        </Paragraph>
      </FlowDocument>
    </RichTextBox>
  </StackPanel>

</Page>
```

#### 示例

下面的代码以编程方式选择一些任意文本，当用户单击内[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)。

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;

namespace SDKSample
{
    public partial class ChangeSelectionProgrammaticaly : Page
    {

        // Change the current selection.
        void ChangeSelection(Object sender, RoutedEventArgs args)
        {
            // Create two arbitrary TextPointers to specify the range of content to select.
            TextPointer myTextPointer1 = myParagraph.ContentStart.GetPositionAtOffset(20);
            TextPointer myTextPointer2 = myParagraph.ContentEnd.GetPositionAtOffset(-10);

            // Programmatically change the selection in the RichTextBox.
            richTB.Selection.Select(myTextPointer1, myTextPointer2);
        }
    }
}
```

### [Save, Load, and Print RichTextBox Content](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-save-load-and-print-richtextbox-content)

下面的示例演示如何将保存的内容[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)到文件中，该内容重新加载到[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)，以及如何打印内容。

#### 示例

下面是示例的标记。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  x:Class="SDKSample.SaveLoadPrintRTB" >

  <StackPanel>
    <RichTextBox Name="richTB">
      <FlowDocument>
        <Paragraph>
          <Run>Paragraph 1</Run>
        </Paragraph>
      </FlowDocument>
    </RichTextBox>

    <Button Click="SaveRTBContent">Save RTB Content</Button>
    <Button Click="LoadRTBContent">Load RTB Content</Button>
    <Button Click="PrintRTBContent">Print RTB Content</Button>
  </StackPanel>

</Page>
```

#### 示例

下面是该示例的隐藏代码。

```csharp
using System;
using System.IO;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Media;

namespace SDKSample
{

    public partial class SaveLoadPrintRTB : Page
    {

        // Handle "Save RichTextBox Content" button click.
        void SaveRTBContent(Object sender, RoutedEventArgs args)
        {

            // Send an arbitrary URL and file name string specifying
            // the location to save the XAML in.
            SaveXamlPackage("C:\\test.xaml");
        }

        // Handle "Load RichTextBox Content" button click.
        void LoadRTBContent(Object sender, RoutedEventArgs args)
        {
            // Send URL string specifying what file to retrieve XAML
            // from to load into the RichTextBox.
            LoadXamlPackage("C:\\test.xaml");
        }

        // Handle "Print RichTextBox Content" button click.
        void PrintRTBContent(Object sender, RoutedEventArgs args)
        {
            PrintCommand();
        }

        // Save XAML in RichTextBox to a file specified by _fileName
        void SaveXamlPackage(string _fileName)
        {
            TextRange range;
            FileStream fStream;
            range = new TextRange(richTB.Document.ContentStart, richTB.Document.ContentEnd);
            fStream = new FileStream(_fileName, FileMode.Create);
            range.Save(fStream, DataFormats.XamlPackage);
            fStream.Close();
        }

        // Load XAML into RichTextBox from a file specified by _fileName
        void LoadXamlPackage(string _fileName)
        {
            TextRange range;
            FileStream fStream;
            if (File.Exists(_fileName))
            {
                range = new TextRange(richTB.Document.ContentStart, richTB.Document.ContentEnd);
                fStream = new FileStream(_fileName, FileMode.OpenOrCreate);
                range.Load(fStream, DataFormats.XamlPackage);
                fStream.Close();
            }
        }

        // Print RichTextBox content
        private void PrintCommand()
        {
            PrintDialog pd = new PrintDialog();
            if ((pd.ShowDialog() == true))
            {
                //use either one of the below      
                pd.PrintVisual(richTB as Visual, "printing as visual");
                pd.PrintDocument((((IDocumentPaginatorSource)richTB.Document).DocumentPaginator), "printing as paginator");
            }
        }
    }
}
```

### [Position a Custom Context Menu in a RichTextBox](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-position-a-custom-context-menu-in-a-richtextbox)

此示例演示如何定位自定义上下文菜单的[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)。

当为 **RichTextBox** 定位自定义上下文菜单时，你负责处理上下文菜单的定位。 默认情况下，自定义上下文菜单在**RichTextBox** 的中心打开。

#### 示例

若要重写默认定位行为，将添加的侦听程序[ContextMenuOpening](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement.contextmenuopening)事件。 下面的示例演示如何通过编程方式执行此操作。

```csharp
richTextBox.ContextMenuOpening += new ContextMenuEventHandler(richTextBox_ContextMenuOpening);
```

#### 示例

下面的示例显示了实现相应[ContextMenuOpening](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement.contextmenuopening)事件侦听器。

```csharp
// This method is intended to listen for the ContextMenuOpening event from a RichTextBox.
// It will position the custom context menu at the end of the current selection.
void richTextBox_ContextMenuOpening(object sender, ContextMenuEventArgs e)
{
    // Sender must be RichTextBox.
    RichTextBox rtb = sender as RichTextBox;
    if (rtb == null) return;

    ContextMenu contextMenu = rtb.ContextMenu;
    contextMenu.PlacementTarget = rtb;

    // This uses HorizontalOffset and VerticalOffset properties to position the menu,
    // relative to the upper left corner of the parent element (RichTextBox in this case).
    contextMenu.Placement = PlacementMode.RelativePoint;

    // Compute horizontal and vertical offsets to place the menu relative to selection end.
    TextPointer position = rtb.Selection.End;

    if (position == null) return;
    
    Rect positionRect = position.GetCharacterRect(LogicalDirection.Forward);
    contextMenu.HorizontalOffset = positionRect.X;
    contextMenu.VerticalOffset = positionRect.Y;

    // Finally, mark the event has handled.
    contextMenu.IsOpen = true;
    e.Handled = true;
}
```

