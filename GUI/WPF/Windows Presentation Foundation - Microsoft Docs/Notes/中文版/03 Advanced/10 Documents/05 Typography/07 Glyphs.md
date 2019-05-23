# [Glyphs](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/glyphs)

标志符号是字符的要在屏幕上绘制的低级别描述。 Windows Presentation Foundation (WPF) 对于想要拦截和保留格式化后的文本的客户提供直接访问权限的标志符号。

[GlyphRun 对象和 Glyphs 元素简介](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/introduction-to-the-glyphrun-object-and-glyphs-element)
[如何：使用 Glyphs 绘制文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/draw-text-using-glyphs)

## [Introduction to the GlyphRun Object and Glyphs Element](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/introduction-to-the-glyphrun-object-and-glyphs-element)

本主题介绍[GlyphRun](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.glyphrun)对象和[Glyphs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.glyphs)元素。

### GlyphRun 简介

Windows Presentation Foundation (WPF) 提供高级的文本支持，包括直接访问的字形级标记[Glyphs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.glyphs)的客户想要拦截和保留格式化后的文本。 这些功能为以下每种方案中不同的文本呈现要求提供关键支持。

1. 固定格式文档的屏幕显示。
2. 打印方案。
   - 可扩展应用程序标记语言 (XAML) 作为设备打印机语言。
   - Microsoft XPS 文档编写器。
   - 以前的打印机驱动程序，从 Win32 应用程序输出为固定格式。
   - 打印后台处理格式。
3. 固定格式的文档演示，包括以前版本的 Windows 客户端和其他计算设备。

> [Glyphs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.glyphs) 和[GlyphRun](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.glyphrun)专为固定格式文档演示和打印方案。 Windows Presentation Foundation (WPF) 为常规布局提供若干元素和用户界面 (UI)如下方案[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)和[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)。 有关布局和 UI 方案的详细信息，请参阅 [WPF 中的版式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/typography-in-wpf)。

### GlyphRun 对象

[GlyphRun](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.glyphrun)对象表示来自单个字体按单个大小，并使用一种呈现样式的单个面部的一系列字形。

[GlyphRun](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.glyphrun) 包括如标志符号字体细节[Indices](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.glyphs.indices)和各字形位置。 它还包括原始Unicode码的位从字符到字形缓冲偏移的映射信息，以及每个字符和每字形标志生成运行。

[GlyphRun](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.glyphrun) 具有相应的高级别[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)， [Glyphs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.glyphs)。 [Glyphs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.glyphs) 可以在元素树中并在XAML标记来表示[GlyphRun](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.glyphrun)输出。

### Glyphs 元素

[Glyphs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.glyphs)元素表示的输出[GlyphRun](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.glyphrun)中XAML。 下面的标记语法用于描述[Glyphs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.glyphs)元素。

```xaml
<!-- The example shows how to use a Glyphs object. -->
<Page
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  >

   <StackPanel Background="PowderBlue">

      <Glyphs
         FontUri             = "C:\WINDOWS\Fonts\TIMES.TTF"
         FontRenderingEmSize = "100"
         StyleSimulations    = "BoldSimulation"
         UnicodeString       = "Hello World!"
         Fill                = "Black"
         OriginX             = "100"
         OriginY             = "200"
      />

   </StackPanel>
</Page>
```

以下属性定义对应于示例标记中的前四个特性。

| 属性                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [FontUri](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.glyphs.fonturi) | 指定资源标识符： 文件名、 Web 统一资源标识符 (URI)，或在应用程序.exe 或容器中的资源引用。 |
| [FontRenderingEmSize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.glyphs.fontrenderingemsize) | 以绘图图面单位指定字号（默认值为 .96 英寸）。                |
| [StyleSimulations](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.glyphs.stylesimulations) | 指定粗体和斜体样式的标志。                                   |
| [BidiLevel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.glyphs.bidilevel) | 指定双向布局级别。 偶数和零值表示从左到右布局；奇数值表示从右到左布局。 |



### Indices 属性

[Indices](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.glyphs.indices)属性是字形规范的字符串。 在一系列字形形成单个群集的情况下，群集中第一个字形的规范之前会跟有一个规范，说明组合了多少个字形和多少个代码点来形成群集。 [Indices](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.glyphs.indices)属性收集在一个字符串中的以下属性。

- 字形索引
- 字形步进宽度
- 组合字形附加矢量
- 从代码点映射到字形的群集
- 字形标志

每个字形规范具有以下形式。

```
[GlyphIndex][,[Advance][,[uOffset][,[vOffset][,[Flags]]]]]
```

### 字形度量值

每个字形定义度量值，指定与其他的对齐方式[Glyphs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.glyphs)。 以下图形定义两种不同字形字符的各种排版品质。

![字形度量示意图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/glyph-example.png)



### Glyphs 标记

下面的代码示例演示如何使用的各种属性[Glyphs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.glyphs)中的元素XAML。

```xaml
<!-- The example shows how to use different property settings of Glyphs objects. -->
<Canvas
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  Background="PowderBlue"
  >

<Glyphs 
   FontUri             = "C:\WINDOWS\Fonts\ARIAL.TTF"
   FontRenderingEmSize = "36"
   StyleSimulations    = "ItalicSimulation"
   UnicodeString       = "Hello World!"
   Fill                = "SteelBlue"
   OriginX             = "50"
   OriginY             = "75"
/>

<!-- "Hello World!" with default kerning -->
<Glyphs 
   FontUri             = "C:\WINDOWS\Fonts\ARIAL.TTF"
   FontRenderingEmSize = "36"
   UnicodeString       = "Hello World!"
   Fill                = "Maroon"
   OriginX             = "50"
   OriginY             = "150"
/>

<!-- "Hello World!" with explicit character widths for proportional font -->
<Glyphs 
   FontUri             = "C:\WINDOWS\Fonts\ARIAL.TTF"
   FontRenderingEmSize = "36"
   UnicodeString       = "Hello World!"
   Indices             = ",80;,80;,80;,80;,80;,80;,80;,80;,80;,80;,80"
   Fill                = "Maroon"
   OriginX             = "50"
   OriginY             = "225"
/>

<!-- "Hello World!" with fixed-width font -->
<Glyphs 
     FontUri             = "C:\WINDOWS\Fonts\COUR.TTF"
     FontRenderingEmSize = "36"
     StyleSimulations    = "BoldSimulation"
     UnicodeString       = "Hello World!"
     Fill                = "Maroon"
     OriginX             = "50"
     OriginY             = "300"
/>

<!-- "Open file" without "fi" ligature -->
<Glyphs
   FontUri             = "C:\WINDOWS\Fonts\TIMES.TTF"
   FontRenderingEmSize = "36"
   StyleSimulations    = "BoldSimulation"
   UnicodeString       = "Open file"
   Fill                = "SlateGray"
   OriginX             = "400"
   OriginY             = "75"
/>

<!-- "Open file" with "fi" ligature -->
<Glyphs
   FontUri             = "C:\WINDOWS\Fonts\TIMES.TTF"
   FontRenderingEmSize = "36"
   StyleSimulations    = "BoldSimulation"
   UnicodeString       = "Open file"
   Indices             = ";;;;;(2:1)191"
   Fill                = "SlateGray"
   OriginX             = "400"
   OriginY             = "150"
/>

</Canvas>
```

## [How to: Draw Text Using Glyphs](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/draw-text-using-glyphs)

本主题说明如何使用低级[Glyphs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.glyphs)对象中显示的文本可扩展应用程序标记语言 (XAML)。

以下示例演示如何定义的属性[Glyphs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.glyphs)对象中可扩展应用程序标记语言 (XAML)。 [Glyphs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.glyphs)对象表示的输出[GlyphRun](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.glyphrun)中XAML。 示例假定本地计算机上的 C:\WINDOWS\Fonts 文件夹中安装了 Arial、Courier New 和 Times New Roman 字体。

XAML复制

```xaml
<!-- The example shows how to use a Glyphs object. -->
<Page
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  >

   <StackPanel Background="PowderBlue">

      <Glyphs
         FontUri             = "C:\WINDOWS\Fonts\TIMES.TTF"
         FontRenderingEmSize = "100"
         StyleSimulations    = "BoldSimulation"
         UnicodeString       = "Hello World!"
         Fill                = "Black"
         OriginX             = "100"
         OriginY             = "200"
      />

   </StackPanel>
</Page>
```

此示例演示如何定义的其他属性[Glyphs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.glyphs)中的对象XAML。

XAML复制

```xaml
<!-- The example shows how to use different property settings of Glyphs objects. -->
<Canvas
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  Background="PowderBlue"
  >

<Glyphs 
   FontUri             = "C:\WINDOWS\Fonts\ARIAL.TTF"
   FontRenderingEmSize = "36"
   StyleSimulations    = "ItalicSimulation"
   UnicodeString       = "Hello World!"
   Fill                = "SteelBlue"
   OriginX             = "50"
   OriginY             = "75"
/>

<!-- "Hello World!" with default kerning -->
<Glyphs 
   FontUri             = "C:\WINDOWS\Fonts\ARIAL.TTF"
   FontRenderingEmSize = "36"
   UnicodeString       = "Hello World!"
   Fill                = "Maroon"
   OriginX             = "50"
   OriginY             = "150"
/>

<!-- "Hello World!" with explicit character widths for proportional font -->
<Glyphs 
   FontUri             = "C:\WINDOWS\Fonts\ARIAL.TTF"
   FontRenderingEmSize = "36"
   UnicodeString       = "Hello World!"
   Indices             = ",80;,80;,80;,80;,80;,80;,80;,80;,80;,80;,80"
   Fill                = "Maroon"
   OriginX             = "50"
   OriginY             = "225"
/>

<!-- "Hello World!" with fixed-width font -->
<Glyphs 
     FontUri             = "C:\WINDOWS\Fonts\COUR.TTF"
     FontRenderingEmSize = "36"
     StyleSimulations    = "BoldSimulation"
     UnicodeString       = "Hello World!"
     Fill                = "Maroon"
     OriginX             = "50"
     OriginY             = "300"
/>

<!-- "Open file" without "fi" ligature -->
<Glyphs
   FontUri             = "C:\WINDOWS\Fonts\TIMES.TTF"
   FontRenderingEmSize = "36"
   StyleSimulations    = "BoldSimulation"
   UnicodeString       = "Open file"
   Fill                = "SlateGray"
   OriginX             = "400"
   OriginY             = "75"
/>

<!-- "Open file" with "fi" ligature -->
<Glyphs
   FontUri             = "C:\WINDOWS\Fonts\TIMES.TTF"
   FontRenderingEmSize = "36"
   StyleSimulations    = "BoldSimulation"
   UnicodeString       = "Open file"
   Indices             = ";;;;;(2:1)191"
   Fill                = "SlateGray"
   OriginX             = "400"
   OriginY             = "150"
/>

</Canvas>
```