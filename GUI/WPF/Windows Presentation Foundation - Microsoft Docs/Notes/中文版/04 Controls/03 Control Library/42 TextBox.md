# [TextBox](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/textbox)

[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控件为 WPF 应用程序中的基本的文本输入提供支持。

## [TextBox Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/textbox-overview)

[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)类，可显示或编辑无格式的文本。 一个常见用途[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)编辑窗体中的无格式的文本。 例如，一个表单要求输入用户的姓名、 电话号码等使用[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)文本输入控件。 本主题介绍[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)类，并提供有关如何在两者中使用它的示例可扩展应用程序标记语言 (XAML)和C#。

### 使用 TextBox 还是 RichTextBox？

这两[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)和[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)使用户可以输入文本，但两个控件用于不同的方案。 一个[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)需系统资源较少则[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)因此它非常适用于需要编辑纯文本 （即，在窗体中的使用情况）。 一个[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)是更好的选择时需要在用户编辑带格式的文本、 图像、 表或其他受支持的内容。 例如，编辑文档、 文章或博客需要格式、 图像，最好采用以下等[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)。 下表总结了的主要功能[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)和[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。

| 控件                                                         | 实时拼写检查 | 上下文菜单 | 等格式设置命令[ToggleBold](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.editingcommands.togglebold)(Ctr + B) | [FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument) 如图像、 段落、 表等内容。 |
| ------------------------------------------------------------ | ------------ | ---------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) | 是           | 是         | 否                                                           | 不是。                                                       |
| [RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox) | 是           | 是         | 是（请参阅 [RichTextBox 概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/richtextbox-overview)） | 是（请参阅 [RichTextBox 概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/richtextbox-overview)） |

 备注

尽管[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)不支持格式设置相关的编辑命令等的作用[ToggleBold](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.editingcommands.togglebold)(Ctr + B)，这两个控件如支持许多基本命令[MoveToLineEnd](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.editingcommands.movetolineend)。 有关更多信息，请参见[EditingCommands](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.editingcommands)。

支持的功能[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)在以下各节中介绍。 有关详细信息[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)，请参阅[RichTextBox 概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/richtextbox-overview)。

### 实时拼写检查

可以启用实时拼写检查中的[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)或[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)。 启用拼写检查时，任何拼写错误的字词下方都会出现红线（见下图）。

![具有拼写检查功能的 Textbox](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/editing-textbox-with-spellchecking.png)

若要了解如何启用拼写检查，请参阅[在文本编辑控件中启用拼写检查](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-enable-spell-checking-in-a-text-editing-control)。

### 上下文菜单

默认情况下，同时[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)和[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)都会在用户右键单击该控件中时，将显示一个上下文菜单。 上下文菜单使用户可以剪切、复制或粘贴（见下图）。

![具有上下文菜单的 TextBox](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/editing-textbox-with-context-menu.png)

可以创建自己的自定义上下文菜单来重写默认行为。 有关详细信息，请参阅[通过 TextBox 使用自定义上下文菜单](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-use-a-custom-context-menu-with-a-textbox)。



### 创建 TextBox

一个[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)可以是单个行的高度，也可以包含多个行。 单个行[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)最适合用于输入少量纯文本 （即表单中的“姓名”、“电话号码”等）。 下面的示例演示如何创建单行[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。

```xaml
<Page  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
  <StackPanel>
    <TextBox Width="200" MaxLength="100" />
  </StackPanel>
</Page>
```

此外可以创建[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)，允许用户输入多行文本。 例如，如果表单要求输入用户的自传，你会想要使用[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)支持多行文本。 下面的示例演示如何使用可扩展应用程序标记语言 (XAML)来定义[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)自动扩展以容纳多行文本的控件。

```xaml
<TextBox
  Name="tbMultiLine"
  TextWrapping="Wrap"
  AcceptsReturn="True"
  VerticalScrollBarVisibility="Visible"
>
  This TextBox will allow the user to enter multiple lines of text.  When the RETURN key is pressed, 
  or when typed text reaches the edge of the text box, a new line is automatically inserted.
</TextBox>
```

设置[TextWrapping](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.textwrapping)归于`Wrap`会导致将文本换行到新行时的边缘[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)达到控件时，自动扩展[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控件以包含为新行留出空间，如有必要。

设置[AcceptsReturn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.textboxbase.acceptsreturn)归于`true`会导致在新行时按 RETURN 键，再一次自动扩展插入[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)以便留出空间的新行，如有必要。

[VerticalScrollBarVisibility](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.textboxbase.verticalscrollbarvisibility)属性添加到一个滚动条[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)，这样的内容[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)可以滚动浏览如果[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)扩展到框架或窗口，其中包含它的大小。

有关详细信息与使用的不同任务[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)，请参阅[操作指南主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/textbox-how-to-topics)。

### 检测内容何时更改

通常[TextChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.textboxbase.textchanged)用于每当检测到事件中的文本[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)或[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)发生更改，而不是[KeyDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.keydown)正如您所料。有关示例，请参阅[检测 TextBox 中的文本何时更改](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-detect-when-text-in-a-textbox-has-changed)。

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/textbox-how-to-topics)

本部分提供示例来演示如何完成常见任务使用[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控件。

[创建多行 TextBox 控件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-create-a-multiline-textbox-control)
[检测 TextBox 中的文本何时更改](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-detect-when-text-in-a-textbox-has-changed)
[在 TextBox 控件中启用制表符](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-enable-tab-characters-in-a-textbox-control)
[从 TextBox 获取一系列文本行](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-get-a-collection-of-lines-from-a-textbox)
[将 TextBox 控件设为只读](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-make-a-textbox-control-read-only)
[将光标置于 TextBox 控件中文本的开头或结尾](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/position-the-cursor-at-the-beginning-or-end-of-text)
[检索选定文本内容](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-retrieve-a-text-selection)
[在 TextBox 控件中设置焦点](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-set-focus-in-a-textbox-control)
[设置 TextBox 控件的文本内容](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-set-the-text-content-of-a-textbox-control)
[在文本编辑控件中启用拼写检查](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-enable-spell-checking-in-a-text-editing-control)
[将自定义上下文菜单与 TextBox 结合使用](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-use-a-custom-context-menu-with-a-textbox)
[将拼写检查功能与上下文菜单结合使用](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-use-spell-checking-with-a-context-menu)
[向 TextBox 添加水印](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-add-a-watermark-to-a-textbox)

### [Create a Multiline TextBox Control](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-create-a-multiline-textbox-control)

此示例演示如何使用可扩展应用程序标记语言 (XAML)来定义[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)将自动扩展以容纳多行文本的控件。

设置[TextWrapping](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.textwrapping)归于**包装**将导致输入的文本换行到新行时的边缘[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)达到控件时，自动扩展[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控件为新行留出空间必需。

设置[AcceptsReturn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.textboxbase.acceptsreturn)归于**true**会导致在新行时按 RETURN 键，再一次自动扩展插入[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)以便留出空间的新行，如有必要。

[VerticalScrollBarVisibility](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.textboxbase.verticalscrollbarvisibility)属性添加到一个滚动条[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)，这样的内容[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)可以滚动浏览如果[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)扩展到框架或窗口，其中包含它的大小。

```xaml
<TextBox
  Name="tbMultiLine"
  TextWrapping="Wrap"
  AcceptsReturn="True"
  VerticalScrollBarVisibility="Visible"
>
  This TextBox will allow the user to enter multiple lines of text.  When the RETURN key is pressed, 
  or when typed text reaches the edge of the text box, a new line is automatically inserted.
</TextBox>
```

### [Detect When Text in a TextBox Has Changed](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-detect-when-text-in-a-textbox-has-changed)

此示例演示使用一种方法[TextChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.textboxbase.textchanged)事件来执行的方法时中的文本[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控制已更改。

中的代码隐藏类XAML，其中包含[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)想要监视的更改，控制插入要每当调用的方法[TextChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.textboxbase.textchanged)事件触发。 此方法必须具有匹配所需的签名[TextChangedEventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textchangedeventhandler)委托。

调用事件处理程序时的内容[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)由用户或以编程方式更改控制。

**注意：** 此事件，则会激发[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)创建并最初会填充文本控件。

在中可扩展应用程序标记语言 (XAML)，用于定义你[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控件，指定[TextChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.textboxbase.textchanged)属性值相匹配的事件处理程序方法名称。

```xaml
<TextBox  TextChanged="textChangedEventHandler">
  Here is the initial text in my TextBox.  Each time the contents of this TextBox are changed, 
  the TextChanged event  fires and textChangedEventHandler is called.
</TextBox>
```

中的代码隐藏类XAML，其中包含[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)想要监视的更改，控制插入要每当调用的方法[TextChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.textboxbase.textchanged)事件触发。 此方法必须具有匹配所需的签名[TextChangedEventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textchangedeventhandler)委托。

```csharp
// TextChangedEventHandler delegate method.
private void textChangedEventHandler(object sender, TextChangedEventArgs args)
{    
    // Omitted Code: Insert code that does something whenever
    // the text changes...
} // end textChangedEventHandler
```

调用事件处理程序时的内容[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)由用户或以编程方式更改控制。

**注意：** 此事件，则会激发[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)创建并最初会填充文本控件。

### [Enable Tab Characters in a TextBox Control](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-enable-tab-characters-in-a-textbox-control)

此示例演示如何作为正常输入中启用制表符接受[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控件。

若要启用的制表符字符数的接受作为输入[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控件，将[AcceptsTab](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.textboxbase.acceptstab)归于**true**。

```xaml
<TextBox AcceptsTab="True">
  If the AcceptsTab element is "True", the TextBox control will accept tab characters as regular input when the TAB key is pressed.  
  If AcceptsTab is "False" (the default), pressing TAB moves the focus to the next focusable control. 
</TextBox>
```

### [Get a Collection of Lines from a TextBox](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-get-a-collection-of-lines-from-a-textbox)

此示例演示如何获取一系列中的文本的文本行[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。

下面的示例演示一个简单的方法采用[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)作为参数，并返回[StringCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.specialized.stringcollection)包含中的文本行**文本框中**。 [LineCount](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.linecount)使用属性来确定行数是当前处于**文本框中**，和[GetLineText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.getlinetext)方法然后用于提取每个行，并将其添加到的行的集合。

```csharp
StringCollection GetLinesCollectionFromTextBox(TextBox textBox)
{
    StringCollection lines = new StringCollection();

    // lineCount may be -1 if TextBox layout info is not up-to-date.
    int lineCount = textBox.LineCount;

    for (int line = 0; line < lineCount; line++)
        // GetLineText takes a zero-based line index.
        lines.Add(textBox.GetLineText(line));

    return lines;
}
```

### [Make a TextBox Control Read-Only](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-make-a-textbox-control-read-only)

此示例演示如何配置[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控件不允许用户输入或修改。

若要防止用户修改的内容[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控件，将[IsReadOnly](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.textboxbase.isreadonly)归于**true**。

```xaml
<TextBox 
  IsReadOnly="True"
>
  The user may not modify the contents of this TextBox.
</TextBox>
```

[IsReadOnly](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.textboxbase.isreadonly)属性会影响仅用户输入; 不会影响文本中设置可扩展应用程序标记语言 (XAML)的说明[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控件或以编程方式通过设置文本[Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.text)属性。

默认值[IsReadOnly](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.textboxbase.isreadonly)是**false**。

### [Position the Cursor at the Beginning or End of Text in a TextBox Control](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/position-the-cursor-at-the-beginning-or-end-of-text)

此示例演示如何在开头或末尾的文本内容将光标置于[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控件。

以下可扩展应用程序标记语言 (XAML)代码描述[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控制并将其分配一个名称。

```xaml
<TextBox
  Name="tbPositionCursor"
>
  Here is some text in my text box...
</TextBox>
```

若要将光标放置的内容的开头[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控件，调用[Select](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.select)方法并指定所选起始位置为 0，并选择长度为 0。

```csharp
tbPositionCursor.Select(0, 0);
```

若要结束的内容将光标置于[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控件，调用[Select](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.select)方法并指定所选内容的起始位置相等长度的文本内容，并选择长度为 0。

```csharp
tbPositionCursor.Select(tbPositionCursor.Text.Length, 0);
```

### [Retrieve a Text Selection](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-retrieve-a-text-selection)

此示例演示使用一种方法[SelectedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.selectedtext)属性来检索用户已经选择了中的文本[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控件。

以下可扩展应用程序标记语言 (XAML)示例演示的定义[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控件，其中包含一些文本，若要选择，和一个[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)与指定的控件[OnClick](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button.onclick)方法。

在此示例中，一个具有一个关联的按钮[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件处理程序用于检索文本选定内容。 当用户单击按钮，[OnClick](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button.onclick)方法将任何所选的文本在文本框中复制到一个字符串。 在特定情况的文本选择检索 （单击某个按钮），还可以使用 （将选定文本复制到一个字符串） 所选内容，所执行的操作可以轻松修改以适应各种方案。

```xaml
<TextBox Name="tbSelectSomeText">
  Some text to select...
</TextBox>

<Button Click="OnClick">Retrieve Selection</Button>
```

以下C#的示例演示[OnClick](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button.onclick)事件处理程序中定义的按钮XAML对于此示例。

```csharp
void OnClick(object sender, RoutedEventArgs e)
{
    String sSelectedText = tbSelectSomeText.SelectedText;
}
```

### [Set Focus in a TextBox Control](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-set-focus-in-a-textbox-control)

此示例演示如何使用[Focus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.focus)方法上设置焦点[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控件。

以下可扩展应用程序标记语言 (XAML)的示例介绍了一个简单[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控件命名为*tbFocusMe*

```xaml
<TextBox Name="tbFocusMe">
  This is the text in my text box.
</TextBox>
```

下面的示例调用[Focus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.focus)方法上设置焦点[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)同名控件*tbFocusMe*。

```csharp
tbFocusMe.Focus();
```

### [Set the Text Content of a TextBox Control](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-set-the-text-content-of-a-textbox-control)

此示例演示如何使用[Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.text)属性设置的初始文本内容[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控件。

**请注意**尽管可扩展应用程序标记语言 (XAML)版本的示例可以使用`<TextBox.Text>`标记的每个按钮的文本周围[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)内容，则没有必要因为[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)适用[ContentPropertyAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.contentpropertyattribute)属性[Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.text)属性。 有关详细信息，请参阅[XAML 概述 (WPF)](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-overview-wpf)。

```xaml
<TextBox Name="tbSettingText">
  Initial text contents of the TextBox.
</TextBox>
```

```csharp
tbSettingText.Text = "Initial text contents of the TextBox.";
```

### [Enable Spell Checking in a Text Editing Control](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-enable-spell-checking-in-a-text-editing-control)

下面的示例演示如何启用实时拼写检查[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)通过使用[IsEnabled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.spellcheck.isenabled)属性的[SpellCheck](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.spellcheck)类。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">

  <StackPanel>
    <TextBox SpellCheck.IsEnabled="True" Name="myTextBox"></TextBox>
  </StackPanel>

</Page>
```

```csharp
using System;
using System.Windows;
using System.Windows.Controls;

namespace SDKSample
{
    public partial class SpellCheckExample : Page
    {
        public SpellCheckExample()
        {
            StackPanel myStackPanel = new StackPanel();

            //Create TextBox
            TextBox myTextBox = new TextBox();
            myTextBox.Width = 200;

            // Enable spellchecking on the TextBox.
            myTextBox.SpellCheck.IsEnabled = true;

            // Alternatively, the SetIsEnabled method could be used
            // to enable or disable spell checking like this:
            // SpellCheck.SetIsEnabled(myTextBox, true);

            myStackPanel.Children.Add(myTextBox);
            this.Content = myStackPanel;
        }
    }
}
```

### [Use a Custom Context Menu with a TextBox](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-use-a-custom-context-menu-with-a-textbox)

此示例演示如何定义和实现的简单自定义上下文菜单[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。

以下可扩展应用程序标记语言 (XAML)的示例定义了[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)包括自定义上下文菜单的控件。

使用定义的上下文菜单[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)元素。 本身的上下文菜单包含一系列[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)元素和[Separator](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.separator)元素。 每个[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)元素定义了一个命令在上下文菜单中;[Header](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headereditemscontrol.header)属性定义菜单命令的显示文本和[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem.click)属性指定每个菜单项的处理程序方法。 [Separator](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.separator)元素只会促使要呈现的前面与后面的菜单项之间的分隔行。

以下可扩展应用程序标记语言 (XAML)的示例定义了[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)包括自定义上下文菜单的控件。

使用定义的上下文菜单[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)元素。 本身的上下文菜单包含一系列[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)元素和[Separator](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.separator)元素。 每个[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)元素定义了一个命令在上下文菜单中;[Header](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headereditemscontrol.header)属性定义菜单命令的显示文本和[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem.click)属性指定每个菜单项的处理程序方法。 [Separator](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.separator)元素只会促使要呈现的前面与后面的菜单项之间的分隔行。

```xaml
<TextBox
  Name="cxmTextBox" 
  Grid.Row="1"
  AcceptsReturn="True"
  AcceptsTab="True"
  VerticalScrollBarVisibility="Visible"
  TextWrapping="Wrap"
>
  <TextBox.ContextMenu>
    <ContextMenu 
      Name="cxm"
      Opened="CxmOpened"
    >
      <MenuItem 
        Header="Cut"
        Name="cxmItemCut" 
        Click="ClickCut" 
      />
      <MenuItem 
        Header="Copy" 
        Name="cxmItemCopy"
        Click="ClickCopy" 
      />
      <MenuItem 
        Header="Paste"
        Name="cxmItemPaste"
        Click="ClickPaste" 
      />
      <Separator/>
      <MenuItem 
        Header="Select All"
        Name="cxmItemSelectAll"
        Click="ClickSelectAll" 
      />
      <MenuItem 
        Header="Select Current Line"
        Name="cxmItemSelectLine"
        Click="ClickSelectLine" 
      />
      <Separator/>
      <MenuItem 
        Header="Undo Last Action"
        Name="cxmItemUndo"
        Click="ClickUndo" 
      />
      <MenuItem 
        Header="Redo Last Action"
        Name="cxmItemRedo"
        Click="ClickRedo" 
      />
      <Separator/>
      <MenuItem 
        Header="Clear All Text"
        Name="cxmItemClear"
        Click="ClickClear" 
      />
    </ContextMenu>
  </TextBox.ContextMenu>
  This TextBox uses a simple custom context menu.  The context menu can be disabled by checking
  the CheckBox above, which simply sets the TextBox.ContextMenu property to null.
</TextBox>
```

下面的示例显示了前面的上下文菜单定义中，实现代码以及启用和禁用上下文菜单的代码。 [Opened](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu.opened)事件用来动态地启用或禁用某些命令，具体取决于当前状态的[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。

若要还原默认的上下文菜单，请使用[ClearValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.clearvalue)方法来清除的值[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.contextmenu)属性。 若要完全禁用上下文菜单，设置[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.contextmenu)属性设置为 null 引用 (`Nothing`在 Visual Basic 中)。

```csharp
private void MenuChange(Object sender, RoutedEventArgs ags)
{
    RadioButton rb = sender as RadioButton;
    if (rb == null || cxm == null) return;

    switch (rb.Name)
    {
        case "rbCustom":
            cxmTextBox.ContextMenu = cxm;
            break;
        case "rbDefault":
            // Clearing the value of the ContextMenu property
            // restores the default TextBox context menu.
            cxmTextBox.ClearValue(ContextMenuProperty);
            break;
        case "rbDisabled":
            // Setting the ContextMenu propety to 
            // null disables the context menu.
            cxmTextBox.ContextMenu = null;
            break;
        default:
            break;
    }

}

void ClickPaste(Object sender, RoutedEventArgs args)     { cxmTextBox.Paste(); }
void ClickCopy(Object sender, RoutedEventArgs args)      { cxmTextBox.Copy(); }
void ClickCut(Object sender, RoutedEventArgs args)       { cxmTextBox.Cut(); }
void ClickSelectAll(Object sender, RoutedEventArgs args) { cxmTextBox.SelectAll(); }
void ClickClear(Object sender, RoutedEventArgs args)     { cxmTextBox.Clear(); } 
void ClickUndo(Object sender, RoutedEventArgs args)      { cxmTextBox.Undo(); }
void ClickRedo(Object sender, RoutedEventArgs args)      { cxmTextBox.Redo(); }

void ClickSelectLine(Object sender, RoutedEventArgs args)
{
    int lineIndex = cxmTextBox.GetLineIndexFromCharacterIndex(cxmTextBox.CaretIndex);
    int lineStartingCharIndex = cxmTextBox.GetCharacterIndexFromLineIndex(lineIndex);
    int lineLength = cxmTextBox.GetLineLength(lineIndex);
    cxmTextBox.Select(lineStartingCharIndex, lineLength);
}

void CxmOpened(Object sender, RoutedEventArgs args)
{
    // Only allow copy/cut if something is selected to copy/cut.
    if (cxmTextBox.SelectedText == "")
        cxmItemCopy.IsEnabled = cxmItemCut.IsEnabled = false;
    else
        cxmItemCopy.IsEnabled = cxmItemCut.IsEnabled = true;

    // Only allow paste if there is text on the clipboard to paste.
    if (Clipboard.ContainsText())
        cxmItemPaste.IsEnabled = true;
    else
        cxmItemPaste.IsEnabled = false;
}
```

### [Use Spell Checking with a Context Menu](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-use-spell-checking-with-a-context-menu)

默认情况下，当启用拼写检查的编辑控件中时喜欢[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)或[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)，上下文菜单中获取拼写检查功能的选项。 例如，当用户右键单击拼错的单词，会得到一组拼写建议或选项**忽略所有**。 但是时重写默认上下文菜单与自己的自定义上下文菜单，, 此功能将丢失，并且您需要自己编写代码以重新启用的上下文菜单中的拼写检查功能。 下面的示例演示如何启用此配置[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。



下面的示例演示可扩展应用程序标记语言 (XAML)，创建[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)与用于实现的上下文菜单的某些事件。

```xaml
<Page x:Class="SDKSample.SpellerCustomContextMenu"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    Loaded="OnWindowLoaded">

  <TextBox
    Name="myTextBox" 
    TextWrapping="Wrap"
    SpellCheck.IsEnabled="True"
    ContextMenuOpening="tb_ContextMenuOpening">
    In a custum menu you need to write code to add speler choices
    because everything in a custom context menu has to be added explicitly.
  </TextBox>

</Page>
```

下面的示例显示了实现的上下文菜单的代码。

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace SDKSample
{
    public partial class SpellerCustomContextMenu : Page
    {

        void OnWindowLoaded(object sender, RoutedEventArgs e)
        {
            //This is required for the first time ContextMenu invocation so that TextEditor doesnt handle it.
            myTextBox.ContextMenu = GetContextMenu();
        }
        void tb_ContextMenuOpening(object sender, RoutedEventArgs e)
        {
            int caretIndex, cmdIndex;
            SpellingError spellingError;

            myTextBox.ContextMenu = GetContextMenu();
            caretIndex = myTextBox.CaretIndex;

            cmdIndex = 0;
            spellingError = myTextBox.GetSpellingError(caretIndex);
            if (spellingError != null)
            {
                foreach (string str in spellingError.Suggestions)
                {
                    MenuItem mi = new MenuItem();
                    mi.Header = str;
                    mi.FontWeight = FontWeights.Bold;
                    mi.Command = EditingCommands.CorrectSpellingError;
                    mi.CommandParameter = str;
                    mi.CommandTarget = myTextBox;
                    myTextBox.ContextMenu.Items.Insert(cmdIndex, mi);
                    cmdIndex++;
                }
                Separator separatorMenuItem1 = new Separator();
                myTextBox.ContextMenu.Items.Insert(cmdIndex, separatorMenuItem1);
                cmdIndex++;
                MenuItem ignoreAllMI = new MenuItem();
                ignoreAllMI.Header = "Ignore All";
                ignoreAllMI.Command = EditingCommands.IgnoreSpellingError;
                ignoreAllMI.CommandTarget = myTextBox;
                myTextBox.ContextMenu.Items.Insert(cmdIndex, ignoreAllMI);
                cmdIndex++;
                Separator separatorMenuItem2 = new Separator();
                myTextBox.ContextMenu.Items.Insert(cmdIndex, separatorMenuItem2);
            }
        }

        // Gets a fresh context menu. 
        private ContextMenu GetContextMenu()
        {
            ContextMenu cm = new ContextMenu();

            //Can create STATIC custom menu items if exists here...
            MenuItem m1, m2, m3, m4;
            m1 = new MenuItem();
            m1.Header = "File";
            m2 = new MenuItem();
            m2.Header = "Save";
            m3 = new MenuItem();
            m3.Header = "SaveAs";
            m4 = new MenuItem();
            m4.Header = "Recent Files";

            //Can add functionality for the custom menu items here...

            cm.Items.Add(m1);
            cm.Items.Add(m2);
            cm.Items.Add(m3);
            cm.Items.Add(m4);

            return cm;
        }

    }
}
```

使用实现这一点的代码[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)类似。 传递给在参数中的主要区别是`GetSpellingError`方法。 有关[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)，传递的插入符号位置的整数索引：

```
spellingError = myTextBox.GetSpellingError(caretIndex);
```

有关[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)，将传递[TextPointer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.textpointer)，它指定插入符号位置：

```
spellingError = myRichTextBox.GetSpellingError(myRichTextBox.CaretPosition);
```

### [Add a Watermark to a TextBox](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-add-a-watermark-to-a-textbox)

下面的示例演示如何帮助的可用性[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)通过显示说明性背景图像的内部[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)直到用户输入文本，此时删除映像。 此外，背景图像重新还原如果用户删除其输入。 请参阅下图。

![背景图像的文本框](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/editing-textbox-using-background-image.png)

> 在此示例中而不只操作使用的背景图像的原因[Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.text)属性的[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)，是背景图像不会干扰数据绑定。

```xaml
<Page
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  x:Class="SDKSample.TextBoxBackgroundExample"
  >

  <StackPanel>
    <TextBox Name="myTextBox" TextChanged="OnTextBoxTextChanged" Width="200">
      <TextBox.Background>
        <ImageBrush ImageSource="TextBoxBackground.gif" AlignmentX="Left" Stretch="None" />
      </TextBox.Background>
    </TextBox>
  </StackPanel>
</Page>
```

```csharp
using System;
using System.Windows;
using System.Windows.Input;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace SDKSample
{
    public partial class TextBoxBackgroundExample : Page
    {

        void OnTextBoxTextChanged(object sender, TextChangedEventArgs e)
        {

            if (myTextBox.Text == "")
            {
                // Create an ImageBrush.
                ImageBrush textImageBrush = new ImageBrush();
                textImageBrush.ImageSource =
                    new BitmapImage(
                        new Uri(@"TextBoxBackground.gif", UriKind.Relative)
                    );
                textImageBrush.AlignmentX = AlignmentX.Left;
                textImageBrush.Stretch = Stretch.None;
                // Use the brush to paint the button's background.
                myTextBox.Background = textImageBrush;

            }
            else
            {

                myTextBox.Background = null;
            }

        }

    }
 
}
```