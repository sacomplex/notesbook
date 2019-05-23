# [Drawing Formatted Text](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/drawing-formatted-text)

本主题提供的功能的概述[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext)对象。 此对象为在 Windows Presentation Foundation (WPF) 应用程序中绘制文本提供低级别控制。

## 技术概述

[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext)对象可绘制多行文本，在其中的文本中的每个字符可以单独设置格式。 下例演示应用了多种格式的文本。

![使用 FormattedText 对象显示的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/formattedtext01.jpg)
使用 FormattedText 方法显示的文本

 备注

对于从 Win32 API 迁移的开发人员，[Win32 迁移](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/drawing-formatted-text#win32_migration)一节中的表列出了 Win32 DrawText 标志和 Windows Presentation Foundation (WPF) 中的近似等效项。

### 使用格式化文本的原因

WPF 包括多个用于在屏幕中绘制文本的控件。 每个控件都面向不同的方案，并具有自己的功能和限制列表。 一般情况下，[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)有限的文本支持是必需的例如中的简短句子时，应使用元素用户界面 (UI)。 [Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label) 需要最少的文本支持时，可以使用。 有关详细信息，请参阅 [WPF 中的文档](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/documents-in-wpf)。

[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext)对象提供更大的文本格式设置功能比Windows Presentation Foundation (WPF)文本控件，并可用于在你想要将文本用作装饰元素的情况下。 有关详细信息，请参阅下一节[将格式化文本转换为几何图形](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/drawing-formatted-text#converting_formatted_text)。

此外，[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext)对象可用于创建面向文本的[DrawingVisual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingvisual)-派生的对象。 [DrawingVisual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingvisual) 是轻量绘图类，用于呈现形状、 图像或文本。 有关详细信息，请参阅[使用 DrawingVisuals 执行测试示例](https://go.microsoft.com/fwlink/?LinkID=159994)。

## 使用 FormattedText 对象

若要创建带格式的文本，请调用[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.-ctor)构造函数创建[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext)对象。 创建初始格式化文本字符串后，便可应用某一范围的格式样式。

使用[MaxTextWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.maxtextwidth)属性可以将约束为特定宽度的文本。 文本将自动换行，避免超过指定宽度。 使用[MaxTextHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.maxtextheight)属性可以将约束为特定高度的文本。 超过指定高度的文本将显示一个省略号“…”。

![使用 FormattedText 对象显示的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/formattedtext02.png)
显示自动换行和省略号的文本

可向一个或多个字符应用多种格式样式。 例如，您可以调用[SetFontSize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.setfontsize)和[SetForegroundBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.setforegroundbrush)方法来更改格式设置的文本中的前五个字符。

下面的代码示例创建[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext)对象，然后向文本应用多种格式化样式。

C#复制

```csharp
protected override void OnRender(DrawingContext drawingContext)
{
    string testString = "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor";

    // Create the initial formatted text string.
    FormattedText formattedText = new FormattedText(
        testString,
        CultureInfo.GetCultureInfo("en-us"),
        FlowDirection.LeftToRight,
        new Typeface("Verdana"),
        32,
        Brushes.Black);

    // Set a maximum width and height. If the text overflows these values, an ellipsis "..." appears.
    formattedText.MaxTextWidth = 300;
    formattedText.MaxTextHeight = 240;

    // Use a larger font size beginning at the first (zero-based) character and continuing for 5 characters.
    // The font size is calculated in terms of points -- not as device-independent pixels.
    formattedText.SetFontSize(36 * (96.0 / 72.0), 0, 5);

    // Use a Bold font weight beginning at the 6th character and continuing for 11 characters.
    formattedText.SetFontWeight(FontWeights.Bold, 6, 11);

    // Use a linear gradient brush beginning at the 6th character and continuing for 11 characters.
    formattedText.SetForegroundBrush(
                            new LinearGradientBrush(
                            Colors.Orange,
                            Colors.Teal,
                            90.0),
                            6, 11);

    // Use an Italic font style beginning at the 28th character and continuing for 28 characters.
    formattedText.SetFontStyle(FontStyles.Italic, 28, 28);

    // Draw the formatted text string to the DrawingContext of the control.
    drawingContext.DrawText(formattedText, new Point(10, 0));
}
```

### 字号度量单位

中的其他文本对象如同Windows Presentation Foundation (WPF)应用程序，[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext)对象使用设备无关的像素作为度量单位。 但是，大多数 Win32 应用程序使用点作为度量单位。 如果要在 Windows Presentation Foundation (WPF) 应用程序中以点为单位显示文本，需要将 与设备无关的单位（每个单位 1/96 英寸） 转换为点。 以下代码示例演示如何执行此转换。

C#复制

```csharp
// The font size is calculated in terms of points -- not as device-independent pixels.
formattedText.SetFontSize(36 * (96.0 / 72.0), 0, 5);
```



### 将格式化文本转换为几何图形

可以将转换到带格式的文本[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)对象，它允许您创建其他类型的悦目文本。 例如，可以创建[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)基于对象的轮廓上的文本字符串。

![使用线性渐变画笔的文本轮廓](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/outlinedtext02.jpg)
使用线性渐变画笔的文本轮廓

以下示例说明了几种通过修改已转换文本的笔划、填充和突出显示来创建悦目的视觉效果的方法。

![对填充和笔画使用不同颜色的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/outlinedtext03.jpg)
将笔划和填充设置为不同颜色的示例

![笔划应用了图像画笔的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/outlinedtext04.jpg)
笔划应用了图像画笔的示例

![笔划应用了图像画笔的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/outlinedtext05.jpg)
笔划和突出显示应用了图像画笔的示例

当文本转换为[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)对象，它不再是一系列字符，不能修改文本字符串中的字符。 但是，可修改已转换文本的笔划和填充属性，以此来影响该文本的外观。 笔划是指已转换文本的轮廓；填充是指已转换文本的轮廓的内部区域。 有关详细信息，请参阅[创建轮廓文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-create-outlined-text)。

此外可以将转换到带格式的文本[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)对象，并将该对象用于突出显示文本。 例如，可以应用到动画[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)对象，以便此动画沿着格式化文本的轮廓。

下面的示例演示已转换为的格式化的文本[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)对象。 经过动画处理的椭圆会沿着所呈现文本的笔划路径显示。

![沿着文本路径几何图形](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/textpathgeometry01.gif)
沿着文本路径几何图形运动的球

有关详细信息，请参阅[如何：为文本创建 PathGeometry 动画](https://msdn.microsoft.com/library/29f8051e-798a-463f-a926-a099a99e9c67)。

您可以创建其他有趣的用法将格式化文本转换到后[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)对象。 例如，可剪辑视频，以便在格式化文本中显示。

![在文本路径几何图形中的视频显示](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/videotextdemo01.png)
文本路径几何图形中的视频显示



## Win32 迁移

功能[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext)用于绘制文本是类似的功能Win32DrawText 函数。 对于从 Win32 API 迁移的开发人员，下表列出了 Win32 DrawText 标志和 Windows Presentation Foundation (WPF) 中的近似等效项。

| DrawText 标志           | WPF 等效项                                                   | 说明                                                         |
| ----------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| DT_BOTTOM               | [Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.height) | 使用[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.height)属性计算相应Win32DrawText y 位置。 |
| DT_CALCRECT             | [Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.height)， [Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.width) | 使用[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.height)和[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.width)属性计算输出矩形。 |
| DT_CENTER               | [TextAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.textalignment) | 使用[TextAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.textalignment)属性值设置为[Center](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.textalignment#System_Windows_TextAlignment_Center)。 |
| DT_EDITCONTROL          | 无                                                           | 不要求。 间距宽度和最后一行的呈现与框架编辑控件中的相同。    |
| DT_END_ELLIPSIS         | [Trimming](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.trimming) | 使用[Trimming](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.trimming)属性的值[CharacterEllipsis](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.texttrimming#System_Windows_TextTrimming_CharacterEllipsis)。  使用[WordEllipsis](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.texttrimming#System_Windows_TextTrimming_WordEllipsis)若要获取Win32DT_END_ELLIPSIS 与 DT_WORD_ELIPSIS 尾部省略号 — 在这种情况下，省略号字符仅出现在单个行上无法容纳的词语。 |
| DT_EXPAND_TABS          | 无                                                           | 不要求。 制表符自动扩展为在每 4 个 em 后停止，这大约为 8 个与语言无关的字符的宽度。 |
| DT_EXTERNALLEADING      | 无                                                           | 不要求。 行距中始终包括外部间隙。 使用[LineHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.lineheight)属性以创建用户定义的行距。 |
| DT_HIDEPREFIX           | 无                                                           | 不支持。 移除 & 从字符串构造之前[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext)对象。 |
| DT_LEFT                 | [TextAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.textalignment) | 这是默认文本对齐方式。 使用[TextAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.textalignment)属性值设置为[Left](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.textalignment#System_Windows_TextAlignment_Left)。（仅限 WPF） |
| DT_MODIFYSTRING         | 无                                                           | 不支持。                                                     |
| DT_NOCLIP               | [VisualClip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual.visualclip) | 剪辑不会自动发生。 如果想要剪辑文本，使用[VisualClip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual.visualclip)属性。 |
| DT_NOFULLWIDTHCHARBREAK | 无                                                           | 不支持。                                                     |
| DT_NOPREFIX             | 无                                                           | 不要求。 字符串中的“&”字符始终作为正常字符处理。             |
| DT_PATHELLIPSIS         | 无                                                           | 使用[Trimming](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.trimming)属性的值[WordEllipsis](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.texttrimming#System_Windows_TextTrimming_WordEllipsis)。 |
| DT_PREFIX               | 无                                                           | 不支持。 如果你想要使用下划线的文本，如加速键或链接，使用[SetTextDecorations](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.settextdecorations)方法。 |
| DT_PREFIXONLY           | 无                                                           | 不支持。                                                     |
| DT_RIGHT                | [TextAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.textalignment) | 使用[TextAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.textalignment)属性值设置为[Right](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.textalignment#System_Windows_TextAlignment_Right)。 （仅限 WPF） |
| DT_RTLREADING           | [FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.flowdirection) | 将 [FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.flowdirection) 属性设置为 [RightToLeft](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection#System_Windows_FlowDirection_RightToLeft)。 |
| DT_SINGLELINE           | 无                                                           | 不要求。 [FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext) 对象的行为作为单行控件，除非任一[MaxTextWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.maxtextwidth)设置属性或者文本包含回车符/换行符 (CR/LF)。 |
| DT_TABSTOP              | 无                                                           | 不支持用户定义的制表位位置。                                 |
| DT_TOP                  | [Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.height) | 不要求。 上对齐是默认设置。 可以使用定义其他垂直定位值[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.height)属性计算相应Win32DrawText y 位置。 |
| DT_VCENTER              | [Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.height) | 使用[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.height)属性计算相应Win32DrawText y 位置。 |
| DT_WORDBREAK            | 无                                                           | 不要求。 自动断词与[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext)对象。 无法禁用它。 |
| DT_WORD_ELLIPSIS        | [Trimming](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.trimming) | 使用[Trimming](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.trimming)属性的值[WordEllipsis](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.texttrimming#System_Windows_TextTrimming_WordEllipsis)。 |