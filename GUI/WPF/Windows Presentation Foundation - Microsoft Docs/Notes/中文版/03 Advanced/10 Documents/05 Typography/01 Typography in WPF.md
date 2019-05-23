# [Typography in WPF](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/typography-in-wpf)

本主题介绍 WPF 的主要版式功能。 这些功能包括改进的文本呈现质量和性能、OpenType 版式支持、增强的国际文本、增强的字体支持和新的文本应用程序编程接口 (API)。



## 改进的文本质量和性能

WPF 中的文本通过 Microsoft ClearType 技术呈现，该技术增强了文本的清晰度和可读性。 ClearType 是一种由Microsoft 开发的软件技术，可提高现有 LCD（液晶显示器，如笔记本电脑屏幕、Pocket PC 屏幕和平板显示器）上文本的可读性。 ClearType 使用亚像素呈现技术，通过将字符对齐到像素的小数部分，以更高的保真度显示文本的真实形状。 超高的分辨率增加了文本显示中细节的清晰度，使其更便于长时间阅读。 WPF 中 ClearType 的另一个改进是可以朝 Y 轴方向抗锯齿，使文本字符中平缓曲线的顶端和底端变得平滑。 有关 ClearType 功能的详细信息，请参阅 [ClearType 概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/cleartype-overview)。

![文本与 ClearType y-的反方向-别名](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/typographyinwpf02.gif)
采用 ClearType y 向抗锯齿的文本

所有文本呈现管道都可以在 WPF 中实现硬件加速，前提是计算机满足所需硬件的最低要求。 不能使用硬件执行加速的呈现会退回软件呈现。 硬件加速会影响文本呈现管道的所有阶段 - 从存储单个字形、将字形组成字形串、应用效果，到向最终显示输出应用 ClearType 混合算法。 有关硬件加速的详细信息，请参阅[图形呈现层](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/graphics-rendering-tiers)。

![文本呈现管道示意图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/typographyinwpf01.png)
文本呈现管线示意图

此外，动画文本（无论是按字符还是按字形进行动画处理）可充分利用由 WPF 启用的图形硬件功能。 因此，可生成平滑的文本动画。



## 丰富的版式

OpenType 字体格式是 TrueType® 字体格式的扩展。 OpenType 字体格式由 Microsoft 和 Adobe 共同开发，可提供多种高级版式功能。 [Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography)对象公开的许多高级功能OpenType字体，如样式备用项和花体。 Windows SDK 提供了一组具有丰富特色的 OpenType 字体示例，如 Pericles 和 Pescadero 字体。 有关详细信息，请参阅[示例 OpenType 字体包](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/sample-opentype-font-pack)。

Pericles OpenType 字体包含其他字形，可为标准自行集提供样式备用项。 以下文本显示样式备用字形。

![使用 OpenType 样式备用字形的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/opentypefont02.gif)
使用 OpenType 样式备用标志符号的文本

花体是使用精美修饰的装饰性字形，通常与书法相关。 以下文本显示 Pescadero 字体的标准和花体字形。

![使用 OpenType 标准和花体字形的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/opentypefont08.gif)
使用 OpenType 标准和花体连字的文本

有关 OpenType 功能的详细信息，请参阅 [OpenType 字体功能](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/opentype-font-features)。



## 增强的国际文本支持

WPF 通过提供下列功能来提供增强的国际文本支持：

- 使用自适应测量功能，在所有书写系统中实现自动行距调整。
- 对国际文本的广泛支持。 有关详细信息，请参阅 [WPF 的全球化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/globalization-for-wpf)。
- 根据不同的语言进行分行、连字和对齐。



## 增强的字体支持

WPF 通过提供下列功能来提供增强的字体支持：

- 所有文本均采用 Unicode。 字体行为和选择不再需要字符集或代码页。
- 字体行为与全局设置（如系统区域设置）无关。
- 单独[FontWeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontweight)， [FontStretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontstretch)，并[FontStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontstyle)类型，用于定义[FontFamily](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.fontfamily)。 因此其灵活性高于 Win32 编程（在这种编程环境中，使用斜体和粗体的布尔组合来定义字体系列）。
- 在处理书写方向（横向与纵向）时不受字体名称的影响。
- 使用复合字体技术，在可移植 XML 文件中链接和回退字体。 使用复合字体可以构造全面的多语言字体。 复合字体还提供一种可避免显示缺失字形的机制。 有关详细信息，请参阅中的备注部分[FontFamily](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.fontfamily)类。
- 使用一组单语言字体，根据复合字体生成国际字体。 在开发多语言字体时，该功能可节省资源成本。
- 在文档中嵌入复合字体，从而能够提供文档可移植性。 有关详细信息，请参阅中的备注部分[FontFamily](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.fontfamily)类。



## 新的文本应用程序编程接口 (API)

WPF 提供了多种文本 API供开发人员在其应用程序中包括文本时使用。 这些 API 分为以下三类：

- **布局和用户界面**。 图形用户界面 (GUI) 常见的文本控件。
- **轻量文本绘制**。 可直接在对象上绘制文本。
- **高级文本格式设置**。 可实现自定义文本引擎。

### 布局和用户界面

在最高级的功能，文本API提供常见用户界面 (UI)控件，如[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)， [TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)，和[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。 这些控件提供应用程序中的基本 UI 元素，并提供一种表示文本和与文本交互的简便方法。 控件，如[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)和[PasswordBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.passwordbox)启用更高级或专用文本处理。 和类，如[TextRange](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.textrange)， [TextSelection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.textselection)，和[TextPointer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.textpointer)启用有用的文本操作。 这些UI控件提供属性，例如[FontFamily](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontfamily)， [FontSize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontsize)，和[FontStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontstyle)，使你能够控制用于呈现文本的字体。

#### 使用位图效果、转换和文本效果

通过 WPF，可以借助位图效果、转换和文本效果等功能，来创建悦目的文本用法。 下面的示例演示了应用于文本的典型类型的投影效果。

![文本阴影的柔和度=0.25](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/shadowtext01.jpg)
使用了投影的文本

下面的示例演示了应用于文本的投影效果和噪音。

![有噪音的文本阴影](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/shadowtext04.jpg)
使用了投影和噪音的文本

下面的示例演示了应用于文本的外发光效果。

![使用 OuterGlowBitmapEffect 的文本阴影](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/shadowtext05.jpg)
使用外发光效果的文本

以下示例显示了应用于文本的模糊效果。

![使用 BlurBitmapEffect 的文本阴影](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/shadowtext06.jpg)
使用模糊效果的文本

下面的示例演示沿 X 轴放大 150% 得到第二行文本，沿 Y 轴放大 150% 得到第三行文本。

![使用 ScaleTransform 缩放的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/transformedtext02.jpg)
使用 ScaleTransform 的文本

以下示例演示沿 X 轴倾斜的文本。

![使用 SkewTransform 倾斜的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/transformedtext03.jpg)
使用 SkewTransform 的文本

一个[TextEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.texteffect)对象是一个帮助程序对象，您可以将文本数据视为文本字符串中的字符的一个或多个组。 下面的示例演示发生旋转的单个字符。 每个字符都将以 1 秒为间隔单独旋转。

![旋转文本的文本效果屏幕截图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/texteffect01.jpg)
旋转文本效果动画的示例

#### 使用流文档

除了常见UI控件，WPF提供用于呈现文本的布局控件-[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)元素。 [FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)元素，结合[DocumentViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.documentviewer)元素，提供了一个控件，用于为大量具有不同布局要求的文本。 布局控件提供访问权限通过高级版式[Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography)对象和其他与字体相关属性UI控件。

下面的示例演示中承载的文本内容[FlowDocumentReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentreader)，它提供搜索、 导航、 分页和内容缩放支持。

![使用 OpenType 字体示例屏幕截图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/typographyinwpf-03.png)
FlowDocumentReader 中承载的文本

有关详细信息，请参阅 [WPF 中的文档](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/documents-in-wpf)。

### 轻量文本绘制

您可以直接向绘制文本WPF通过使用对象[DrawText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingcontext.drawtext)方法的[DrawingContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingcontext)对象。 若要使用此方法，您创建[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext)对象。 使用该对象可以绘制多行文本，可对文本中的每个字符单独设置格式。 功能[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext)对象包含很多 Win32 API 中 DrawText 标志的功能。 此外，[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext)对象包含省略号支持，当文本超过其边界时在其中显示一个省略号等功能。 下面的示例演示应用多种格式的文本，其中第二个和第三个单词应用了线性渐变。

![使用 FormattedText 对象显示的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/formattedtext01.jpg)
使用 FormattedText 对象显示的文本

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

有关详细信息[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext)对象，请参阅[绘制格式化文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/drawing-formatted-text)。

### 高级文本格式设置

在最高级的文本API，WPF能够通过创建自定义文本布局[TextFormatter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textformatter)对象中和其他类型[System.Windows.Media.TextFormatting](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting)命名空间。 [TextFormatter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textformatter)和关联的类可以实现支持的字符格式、 段落样式定义的自定义文本布局换行规则和其他布局功能对国际文本。 只有在极少数情况下才需要重写 WPF 文本布局支持的默认实现。 但是，如果要创建文本编辑控件或应用程序，则可能需要非默认的 WPF 实现。

与传统文本不同API，则[TextFormatter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textformatter)与通过回调方法的一组文本布局客户端进行交互。 它要求客户端提供这些方法的实现中[TextSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textsource)类。 下图说明了客户端应用程序之间的文本布局交互和[TextFormatter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.textformatting.textformatter)。

![文本布局客户端和 TextFormatter 示意图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/textformatter01.png)
应用程序和 TextFormatter 之间的交互

有关创建自定义文本布局的详细信息，请参阅[高级文本格式设置](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/advanced-text-formatting)。