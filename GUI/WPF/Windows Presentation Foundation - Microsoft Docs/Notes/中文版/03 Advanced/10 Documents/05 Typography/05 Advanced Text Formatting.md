# [Advanced Text Formatting](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/advanced-text-formatting)

Windows Presentation Foundation (WPF) 提供了一套稳健的API用于在你的应用程序中包括的文本。 布局和用户界面 (UI) API，如[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)、 提供了最常见和常规使用用于呈现文本元素。 绘制API，如[GlyphRunDrawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.glyphrundrawing)和[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext)，在绘图中加入格式化的文本提供一种方法。 在最高级别，WPF提供了一个可扩展的文本格式引擎，用于控制文本呈现，如文本存储管理、 文本运行格式管理和嵌入的对象管理的各个方面。

本主题介绍了WPF文本格式设置。 它主要关注客户端实现和利用WPF文本格式引擎。

 备注

本文档中的所有代码示例都可在[高级文本格式设置示例](https://go.microsoft.com/fwlink/?LinkID=159965)。



## 系统必备

本主题假定你熟悉的较高级别API用于呈现文本。 大多数用户方案都不需要的高级的文本格式API本主题中讨论。有关不同的文本的介绍API，请参阅[WPF 中的文档](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/documents-in-wpf)。



## 高级文本格式设置

文本布局和UI中的控件WPF提供可用于轻松地在应用程序中加入格式化的文本的格式设置属性。 这些控件会公开许多用于处理文本呈现（包括字样、大小和颜色）的属性。 一般情况下，这些控件可以处理应用程序中的大部分文本呈现。 但是，某些高级方案要求控制文本存储和文本呈现。 为此，WPF 提供了一个可扩展的文本格式引擎。

高级的文本格式设置功能中找到WPF包括文本格式引擎、 文本存储、 文本运行和格式设置属性。 文本格式引擎， [TextFormatter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textformatter)，创建要用于显示的文本行。 这通过初始化行格式设置过程并调用文本格式化程序的实现[FormatLine](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textformatter.formatline)。 文本格式化程序通过调用的存储从文本存储检索文本运行[GetTextRun](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textsource.gettextrun)方法。 [TextRun](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textrun)然后形成的对象[TextLine](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textline)文本格式化程序对象和提供给应用程序进行检查或显示。



## 使用文本格式化程序

[TextFormatter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textformatter) 是WPF文本格式引擎，提供服务，用于设置格式及断开文本行。 文本格式化程序可处理各种文本字符格式和段落样式，并提供对国际文本布局的支持。

与传统文本不同API，则[TextFormatter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textformatter)与通过回调方法的一组文本布局客户端进行交互。 它要求客户端提供这些方法的实现中[TextSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textsource)类。 下图说明了客户端应用程序之间的文本布局交互和[TextFormatter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textformatter)。

![文本布局客户端和 TextFormatter 示意图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/textformatter01.png)
应用程序和 TextFormatter 之间的交互

文本格式化程序用于从文本存储中检索带格式的文本行即的实现[TextSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textsource)。 这是通过首先通过使用创建文本格式化程序实例[Create](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textformatter.create)方法。 此方法可创建一个文本格式化程序实例，并设置最大行高值和行宽值。 一旦创建文本格式化程序的实例，通过调用来启动行创建过程[FormatLine](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textformatter.formatline)方法。 [TextFormatter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textformatter) 回拨到要检索的文本和格式设置参数的文本运行的文本源构成一条线。

下例演示文本存储的格式设置过程。 [TextFormatter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textformatter)对象用于从文本存储中检索文本行，然后设置格式绘制到的文本行[DrawingContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingcontext)。

C#复制

```csharp
// Create a DrawingGroup object for storing formatted text.
textDest = new DrawingGroup();
DrawingContext dc = textDest.Open();

// Update the text store.
_textStore.Text = textToFormat.Text;
_textStore.FontRendering = _currentRendering;

// Create a TextFormatter object.
TextFormatter formatter = TextFormatter.Create();

// Format each line of text from the text store and draw it.
while (textStorePosition < _textStore.Text.Length)
{
   // Create a textline from the text store using the TextFormatter object.
   using (TextLine myTextLine = formatter.FormatLine(
       _textStore,
       textStorePosition,
       96*6,
       new GenericTextParagraphProperties(_currentRendering),
       null))
   {
       // Draw the formatted text into the drawing context.
       myTextLine.Draw(dc, linePosition, InvertAxes.None);

       // Update the index position in the text store.
       textStorePosition += myTextLine.Length;

       // Update the line position coordinate for the displayed line.
       linePosition.Y += myTextLine.Height;
   }
}

// Persist the drawn text content.
dc.Close();

// Display the formatted text in the DrawingGroup object.
myDrawingBrush.Drawing = textDest;
```



## 实现客户端文本存储

扩展文本格式引擎时，需要实现和管理文本存储的各个方面。 该任务不是无关紧要的。 文本存储负责跟踪文本运行属性、段落属性、嵌入对象和其他类似内容。 它还提供文本格式化程序包含单个[TextRun](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textrun)对象的文本格式化程序用于创建[TextLine](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textline)对象。

若要处理文本存储的虚拟化，文本存储必须派生自[TextSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textsource)。 [TextSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textsource) 定义文本格式化程序用于从文本存储中检索文本运行的方法。 [GetTextRun](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textsource.gettextrun) 是文本格式化程序用来检索文本的方法运行行格式设置中使用。 对调用[GetTextRun](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textsource.gettextrun)反复进行文本格式化程序直到发生以下情况之一：

- 一个[TextEndOfLine](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textendofline)或返回子类。
- 文本运行的累积的宽度超出创建文本格式化程序是调用或对文本格式化程序的调用中指定的最大线条宽度[FormatLine](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textformatter.formatline)方法。
- 一个Unicode返回换行序列，如"CF"、"LF"或"CRLF"。



## 提供文本运行

文本格式设置过程的核心是文本格式化程序和文本存储之间的交互。 实现[TextSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textsource)提供了为文本格式化程序[TextRun](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textrun)对象和要设置的格式与运行的文本的属性。 通过处理此交互[GetTextRun](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textsource.gettextrun)调用文本格式化程序的方法。

下表显示了一些预定义[TextRun](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textrun)对象。

| TextRun 类型                                                 | 用法                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [TextCharacters](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textcharacters) | 专用文本运行，用于将字符标志符号的表示形式传回给文本格式化程序。 |
| [TextEmbeddedObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textembeddedobject) | 专用文本运行，用于提供其中的度量、命中测试和绘制将作为整体执行的内容，例如文本中的按钮或图像。 |
| [TextEndOfLine](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textendofline) | 专用文本运行，用于对行尾进行标记。                           |
| [TextEndOfParagraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textendofparagraph) | 专用文本运行，用于对段落结尾进行标记。                       |
| [TextEndOfSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textendofsegment) | 专用的文本运行用于标记如段的结尾结束先前受影响的作用域[TextModifier](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textmodifier)运行。 |
| [TextHidden](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.texthidden) | 专用文本运行，用于对一系列隐藏字符进行标记。                 |
| [TextModifier](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textmodifier) | 专用文本运行，用于在其范围内修改文本运行属性。 该范围可扩展到下一个匹配[TextEndOfSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textendofsegment)文本运行或下一个[TextEndOfParagraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textendofparagraph)。 |

任意预定义[TextRun](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textrun)可以子类化的对象。 这样，文本源便可为文本格式化程序提供包含自定义数据的文本运行。

下面的示例演示[GetTextRun](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textsource.gettextrun)方法。 返回此文本存储[TextRun](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textrun)文本格式化程序以进行处理的对象。

C#复制

```csharp
// Used by the TextFormatter object to retrieve a run of text from the text source.
public override TextRun GetTextRun(int textSourceCharacterIndex)
{
   // Make sure text source index is in bounds.
   if (textSourceCharacterIndex < 0)
      throw new ArgumentOutOfRangeException("textSourceCharacterIndex", "Value must be greater than 0.");
   if (textSourceCharacterIndex >= _text.Length)
   {
      return new TextEndOfParagraph(1);
   }

   // Create TextCharacters using the current font rendering properties.
   if (textSourceCharacterIndex < _text.Length)
   {
      return new TextCharacters(
         _text,
         textSourceCharacterIndex,
         _text.Length - textSourceCharacterIndex,
         new GenericTextRunProperties(_currentRendering));
   }

   // Return an end-of-paragraph if no more text source.
   return new TextEndOfParagraph(1);
}
```

 备注

在此示例中，文本存储为所有文本提供了相同的文本属性。 高级文本存储需要实现各自的范围管理，以便单个字符具有不同的属性。



## 指定格式设置属性

[TextRun](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textrun) 使用提供的文本存储属性设置格式的对象。 这些属性有两种类型，[TextParagraphProperties](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textparagraphproperties)和[TextRunProperties](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textrunproperties)。 [TextParagraphProperties](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textparagraphproperties) 处理涉及段落的属性，如[TextAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.textalignment)和[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)。[TextRunProperties](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textrunproperties) 可以为每个文本运行中一个段落，如前景画笔、 不同的属性[Typeface](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.typeface)，和字体大小。 若要实现自定义段落和自定义文本运行属性类型，你的应用程序必须创建派生的类[TextParagraphProperties](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textparagraphproperties)和[TextRunProperties](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textrunproperties)分别。