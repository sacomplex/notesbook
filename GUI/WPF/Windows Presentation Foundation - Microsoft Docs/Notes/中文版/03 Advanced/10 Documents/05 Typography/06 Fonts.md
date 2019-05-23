# [Fonts](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/fonts-wpf)

Windows Presentation Foundation (WPF) 包括对文本使用的丰富的演示支持OpenType字体。 一个示例包OpenType字体随Windows SDK。

[OpenType 字体功能](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/opentype-font-features)
[将字体与应用程序一起打包](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/packaging-fonts-with-applications)
[示例 OpenType 字体包](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/sample-opentype-font-pack)
[帮助主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/fonts-how-to-topics)

## [OpenType Font Features](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/opentype-font-features)

本主题概述 Windows Presentation Foundation (WPF) 中 OpenType 字体技术的一些主要功能。

### OpenType 字体格式

OpenType 字体格式是 TrueType® 字体格式的扩展，添加了对 PostScript 字体数据的支持。 OpenType 字体格式由 Microsoft 和 Adobe Corporation 联合开发。 无论字体包含 TrueType 边框还是 CFF (PostScript) 边框，OpenType 字体和支持 OpenType 字体的操作系统服务都向用户提供一种简单的字体安装和使用方式。

OpenType 字体格式解决了开发人员面临的以下挑战：

- 更广泛的多平台支持。
- 更出色的国际字符集支持。
- 更优的字体数据保护。
- 更小的文件大小，让字体发布更加高效。
- 更广泛的高级版式控件支持。

> Windows SDK 包含了一组可用于 Windows Presentation Foundation (WPF) 应用程序的示例 OpenType 字体。 这些字体提供本主题余下部分所述的大多数功能。 有关详细信息，请参阅[示例 OpenType 字体包](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/sample-opentype-font-pack)。

有关 OpenType 字体格式的详细信息，请参阅 [OpenType 规范](https://go.microsoft.com/fwlink/?LinkId=96731)。

#### 高级版式扩展

高级版式表格（OpenType 布局表格）扩展了具有 TrueType 或 CFF 边框的字体的功能。 OpenType 布局字体包含一些其他信息，可扩展字体功能以支持高质量国际版式。 大多数 OpenType 字体仅体现全部可用 OpenType 功能的一部分。 OpenType 字体提供以下功能。

- 字符与字形之间的丰富映射，可支持连字、定位格式、备用项以及其他字体替换功能。
- 支持二维定位和字形附加。
- 字体中包含的显式脚本和语言信息，使文本处理应用程序可相应调整其行为。

OpenType 布局表格在 OpenType 规范的[“字体文件表格”](https://www.microsoft.com/typography/otspec/otff.htm)部分中进行了更详细的描述。

本概述的其余部分介绍的广度和灵活性的一些直观有趣OpenType的属性公开的功能[Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography)对象。 有关此对象的详细信息，请参阅[版式类](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/opentype-font-features#typography_class)。

### 变量

变量用于呈现不同的版式风格，例如上标和下标。

#### 上标和下标

[Variants](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.variants)属性可以设置上标和下标值OpenType字体。

以下文本显示 Palatino Linotype 字体的上标。

![使用 OpenType 上标的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/opentypefont14.gif)
使用 OpenType 上标的文本

以下标记示例演示如何定义使用的属性的 Palatino Linotype 字体的上标[Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography)对象。

XAML复制

```xaml
<Paragraph FontFamily="Palatino Linotype">
  2<Run Typography.Variants="Superscript">3</Run>
  14<Run Typography.Variants="Superscript">th</Run>
</Paragraph>
```

以下文本显示 Palatino Linotype 字体的下标。

![使用 OpenType 下标的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/opentypefont15.gif)
使用 OpenType 下标的文本

以下标记示例演示如何定义 Palatino Linotype 字体的使用的属性的下标[Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography)对象。

XAML复制

```xaml
<Paragraph FontFamily="Palatino Linotype">
  H<Run Typography.Variants="Subscript">2</Run>O
  Footnote<Run Typography.Variants="Subscript">4</Run>
</Paragraph>
```

#### 上标和下标的修饰用法

也可使用上标和下标来营造混合大小写文本的修饰效果。 以下文本显示 Palatino Linotype 字体的上标和下标文本。 注意，大写字母不受影响。

![使用 OpenType 上标和下标的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/opentypefont16.gif)
使用 OpenType 上标和下标的文本

以下标记示例演示如何定义上标和下标字体使用的属性的[Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography)对象。

XAML复制

```xaml
<Paragraph FontFamily="Palatino Linotype" Typography.Variants="Superscript">
  Chapter One
</Paragraph>
<Paragraph FontFamily="Palatino Linotype" Typography.Variants="Subscript">
  Chapter One
</Paragraph>
```

### 大写字母

大写字母是一组以大写样式字形呈现文本的版式形式。 通常情况下，当以全大写呈现文本时，字母之间的间距可能看起来很小，字母的权重和比例看起来会很大。 OpenType 支持多种大写字母的样式格式，包括小体大写字母、小号大写字母、标题和大写字母间距。 通过这些样式格式可控制大写字母的外观。

以下文本显示 Pescadero 字体的标准大写字母，其后接样式为“SmallCaps”和“AllSmallCaps”的字母。 本例中，对所有三个单词均使用相同的字体大小。

![使用 OpenType 大写字母的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/opentypefont11.gif)
使用 OpenType 大写字母的文本

以下标记示例演示如何定义使用的属性的 Pescadero 字体的大写字母[Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography)对象。 使用“SmallCaps”格式时会忽略任何前导大写字母。

XAML复制

```xaml
<Paragraph FontFamily="Pescadero" FontSize="48">
  <Run>CAPITALS</Run>
  <Run Typography.Capitals="SmallCaps">Capitals</Run>
  <Run Typography.Capitals="AllSmallCaps">Capitals</Run>
</Paragraph>
```

#### 标题大写字母

标题大写字母权重和比例更小，外观比普通大写字母更加雅致。 标题大写字母通常用于作为标题的大号字体中。以下文本显示 Pescadero 字体的普通大写字母和标题大写字母。 请注意第二行文本的宽度更窄。

![使用 OpenType 标题大写字母的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/opentypefont20.gif)
使用 OpenType 标题大写字母的文本

以下标记示例演示如何定义 Pescadero 字体使用的属性的标题大写字母[Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography)对象。

XAML复制

```xaml
<Paragraph FontFamily="Pescadero">
  <Run Typography.Capitals="Titling">chapter one</Run>
</Paragraph>
```

#### 大写字母间距

大写字母间距功能让你可以在使用全大写字母文本时提供更宽的间距。 大写字母通常设计为与小写字母混合使用。 大写字母和小写字母之间看起来比较美观的间距在使用全大写字母时可能会显得过紧。 以下文本显示 Pescadero 字体的普通间距和大写字母间距。

![使用 OpenType 大写字母间距的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/opentypefont21.gif)
使用 OpenType 大写字母间距的文本

以下标记示例演示如何定义使用的属性的 Pescadero 字体的大写字母间距[Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography)对象。

XAML复制

```xaml
<Paragraph FontFamily="Pescadero">
  <Run Typography.CapitalSpacing="True">CHAPTER ONE</Run>
</Paragraph>
```

### 连字

连子是为使文本更具可读性或更加美观而由两个或更多字形形成的一个单一字形。 OpenType 字体支持四种类型的连字：

- **标准连字**。 旨在增强可读性。 标准连字包括“fi”、“fl”和“ff”。
- **上下文连字**。 旨在通过在组成连字的字符之间提供更好的联结行为来增强可读性。
- **自由连字**。 重在修饰性，并非专为可读性而设计。
- **历史连字**。 重在历史性，并非专为可读性而设计。

以下文本显示 Pericles 字体的标准连字字形。

![使用 OpenType 标准连字的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/opentypefont04.gif)
使用 OpenType 标准连字的文本

以下标记示例演示如何定义使用的属性的 Pericles 字体的标准连字字形[Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography)对象。

XAML复制

```xaml
<Paragraph FontFamily="Pericles" Typography.StandardLigatures="True">
  <Run Typography.StylisticAlternates="1">FI</Run>
  <Run Typography.StylisticAlternates="1">FL</Run>
  <Run Typography.StylisticAlternates="1">TH</Run>
  <Run Typography.StylisticAlternates="1">TT</Run>
  <Run Typography.StylisticAlternates="1">TV</Run>
  <Run Typography.StylisticAlternates="1">TW</Run>
  <Run Typography.StylisticAlternates="1">TY</Run>
  <Run Typography.StylisticAlternates="1">VT</Run>
  <Run Typography.StylisticAlternates="1">WT</Run>
  <Run Typography.StylisticAlternates="1">YT</Run>
</Paragraph>
```

以下文本显示 Pericles 字体的自由连字字形。

![使用 OpenType 自由连字的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/opentypefont05.gif)
使用 OpenType 自由连字的文本

以下标记示例演示如何定义使用的属性的 Pericles 字体的自由连字字形[Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography)对象。

XAML复制

```xaml
<Paragraph FontFamily="Pericles" Typography.DiscretionaryLigatures="True">
  <Run Typography.StylisticAlternates="1">CO</Run>
  <Run Typography.StylisticAlternates="1">LA</Run>
  <Run Typography.StylisticAlternates="1">LE</Run>
  <Run Typography.StylisticAlternates="1">LI</Run>
  <Run Typography.StylisticAlternates="1">LL</Run>
  <Run Typography.StylisticAlternates="1">LO</Run>
  <Run Typography.StylisticAlternates="1">LU</Run>
</Paragraph>
```

Windows Presentation Foundation (WPF) 中的 OpenType 字体默认启用标准连字。 例如，如果使用 Palatino Linotype 字体，则标准连字“fi”、“ff”和“fl”显示为组合字符字形。 请注意，每个标准连字的字符对之间彼此相连。

![使用 OpenType 标准连字的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/opentypefont06.gif)
使用 OpenType 标准连字的文本

但是，可禁用标准连字功能，从而使“ff”等标准连字显示为两个单独的字形，而不显示为一个组合字符字形。

![文本使用禁用的 OpenType 标准连字](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/opentypefont07.gif)
使用禁用的 OpenType 标准连字的文本

以下标记示例演示如何禁用 Palatino Linotype 字体的使用的属性的标准连字字形[Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography)对象。

XAML复制

```xaml
<!-- Set standard ligatures to false in order to disable feature. -->
<Paragraph Typography.StandardLigatures="False" FontFamily="Palatino Linotype" FontSize="72">
  fi ff fl
</Paragraph>
```

### 花体

花体是使用精美修饰的装饰性字形，通常与书法相关。 以下文本显示 Pescadero 字体的标准和花体字形。

![使用 OpenType 标准和花体字形的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/opentypefont08.gif)
使用 OpenType 标准和花体连字的文本

花体通常用作事件公告等简短文章中的修饰元素。 以下文本使用花体强调事件名称的大写字母。

![使用 OpenType 连接形式花体的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/opentypefont09.gif)
使用 OpenType 花体的文本

以下标记示例演示如何定义字体花体，使用的属性[Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography)对象。

XAML复制

```xaml
<Paragraph FontFamily="Pescadero" TextBlock.TextAlignment="Center">
  Wishing you a<LineBreak/>
  <Run Typography.StandardSwashes="1" FontSize="36">Happy New Year!</Run>
</Paragraph>
```

#### 连接形式花体

花体字形的某些组合可能导致文本外观欠佳，例如相邻字母的下行处出现重叠。 通过连接形式花体，可使用能生成更佳外观的替代花体字形。 以下文本显示同一单词应用连接形式花体前后的外观。

![使用 OpenType 花体的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/opentypefont19.gif)
使用 OpenType 连接形式花体的文本

以下标记示例演示如何定义 Pescadero 字体使用的属性的上下文花体[Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography)对象。

XAML复制

```xaml
<Paragraph FontFamily="Pescadero" Typography.StandardSwashes="1">
  Lyon <Run Typography.ContextualSwashes="1">L</Run>yon
</Paragraph>
```



### 备用项

备用项是可替代标准字形的字形。 OpenType 字体（例如以下示例中使用的 Pericles 字体）可包含用于塑造不同文本外观的备用字形。 以下文本显示 Pericles 字体的标准字形。

![使用 OpenType 标准字形的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/opentypefont01.gif)
使用 OpenType 标准字形的文本

Pericles OpenType 字体包含其他字形，可为标准自行集提供样式备用项。 以下文本显示样式备用字形。

![使用 OpenType 样式备用字形的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/opentypefont02.gif)
使用 OpenType 样式备用标志符号的文本

以下标记示例演示如何定义 Pericles 字体的使用的属性的样式备用字形[Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography)对象。

XAML复制

```xaml
<Paragraph FontFamily="Pericles">
  <Run Typography.StylisticAlternates="1">A</Run>NCIENT
  GR<Run Typography.StylisticAlternates="1">EE</Run>K
  MYTH<Run Typography.StylisticAlternates="1">O</Run>LOGY
</Paragraph>
```

以下文本显示 Pericles 字体的几种其他样式备用字形。

![使用 OpenType 样式备用字形的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/opentypefont03.gif)
使用 OpenType 样式备用标志符号的文本

以下标记示例演示如何定义其他样式备用字形。

XAML复制

```xaml
<Paragraph FontFamily="Pericles">
  <Run Typography.StylisticAlternates="1">A</Run>
  <Run Typography.StylisticAlternates="2">A</Run>
  <Run Typography.StylisticAlternates="3">A</Run>
  <Run Typography.StylisticAlternates="1">C</Run>
  <Run Typography.StylisticAlternates="1">E</Run>
  <Run Typography.StylisticAlternates="1">G</Run>
  <Run Typography.StylisticAlternates="1">O</Run>
  <Run Typography.StylisticAlternates="1">Q</Run>
  <Run Typography.StylisticAlternates="1">R</Run>
  <Run Typography.StylisticAlternates="2">R</Run>
  <Run Typography.StylisticAlternates="1">S</Run>
  <Run Typography.StylisticAlternates="1">Y</Run>
</Paragraph>
```

#### 随机备用连接形式

随机备用连接形式为单个字符提供多种备用字形。 实现脚本类型字体时，此功能可通过使用一组随机选择的外观稍有差异的字形来模拟手写内容。 以下文本使用 Lindsey 字体的随机备用连接形式。 请注意字母“a”外观稍有变化

![使用 OpenType 随机备用连接形式的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/opentypefont23.gif)
使用 OpenType 随机备用连接形式的文本

以下标记示例演示如何定义 Lindsey 字体使用的属性的随机备用[Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography)对象。

XAML复制

```xaml
<TextBlock FontFamily="Lindsey">
  <Run Typography.ContextualAlternates="True">
    a banana in a cabana
  </Run>
</TextBlock>
```

#### 历史形式

历史形式指过去常见的版式约定。 以下文本使用 Palatino Linotype 字体的一种历史字形形式显示短语“Boston, Massachusetts”。

![使用 OpenType 历史形式的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/opentypefont10.gif)
使用 OpenType 历史形式的文本

以下标记示例演示如何定义 Palatino Linotype 字体的使用的属性的历史记录格式[Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography)对象。

XAML复制

```xaml
<Paragraph FontFamily="Palatino Linotype">
  <Run Typography.HistoricalForms="True">Boston, Massachusetts</Run>
</Paragraph>
```



### 数字样式

OpenType 字体支持多种可用于文本中数值的功能。

#### 分数

OpenType 字体支持多种分数样式，包括横式分数和竖式分数。

以下文本显示 Palatino Linotype 字体的分数样式。

![文本使用 OpenType 横式分数和竖式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/opentypefont12.gif)
使用 OpenType 横式分数和竖式分数的文本

以下标记示例演示如何定义 Palatino Linotype 字体的使用的属性的分数样式[Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography)对象。

XAML复制

```xaml
<Paragraph FontFamily="Palatino Linotype" Typography.Fraction="Slashed">
  1/8 1/4 3/8 1/2 5/8 3/4 7/8
</Paragraph>
<Paragraph FontFamily="Palatino Linotype" Typography.Fraction="Stacked">
  1/8 1/4 3/8 1/2 5/8 3/4 7/8
</Paragraph>
```

#### 旧样式数字

OpenType 字体支持旧样式数字格式。 此格式对于显示不再是标准样式的数字非常有用。 以下文本以 Palatino Linotype 字体的标准和旧样式数字格式显示 18 世纪日期。

![使用 OpenType 旧样式数字的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/opentypefont24.gif)
使用 OpenType 旧样式数字的文本

以下文本显示 Palatino Linotype 字体的标准数字，后跟旧样式数字。

![使用 OpenType 旧样式数字集的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/opentypefont13.gif)
使用 OpenType 旧样式数字集的文本

以下标记示例演示如何定义 Palatino Linotype 字体的使用的属性的旧样式数字[Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography)对象。

XAML复制

```xaml
<Paragraph FontFamily="Palatino Linotype">
  <Run Typography.NumeralStyle="Normal">1234567890</Run>
  <Run Typography.NumeralStyle="OldStyle">1234567890</Run>
</Paragraph>
```

#### 比例数字和表格式数字

OpenType 字体支持比例数字和表格式数字功能，可在使用数字时控制宽度对齐。 比例数字将每个数字视为具有不同的宽度—“1”窄于“5”。 表格式数字被视为宽度相等的数字，因此它们可垂直对齐，从而增强财务类型信息的可读性。

以下文本使用 Miramonte 字体显示第一列中的两个表格式数字。 请注意数字“5”和“1”之间的宽度差异。 第二列显示相同的两个数值，并通过使用表格式数字功能调整其宽度。

![使用 OpenType 比例数字和表格式数字的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/opentypefont22.gif)
使用 OpenType 比例数字和表格式数字的文本

以下标记示例演示如何定义比例数字和表格式数字 Miramonte 字体使用的属性的[Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography)对象。

XAML复制

```xaml
<TextBlock FontFamily="Miramonte">
  <Run Typography.NumeralAlignment="Proportional">114,131</Run>
</TextBlock>
<TextBlock FontFamily="Miramonte">
  <Run Typography.NumeralAlignment="Tabular">114,131</Run>
</TextBlock>
```

#### 斜线零

OpenType 字体支持斜线零数字格式来强调字母“O”和数字“0”之间的差异。 斜线零数字通常用于财务和商务信息中的标识符。

以下文本显示使用 Miramonte 字体的订单标识符。 第一行使用标准数字。 第二行使用斜线零数字，以便更易于与大写字母“O”进行区分。

![文本使用 OpenType 斜线零数字](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/opentypefont17.gif)
使用 OpenType 斜线零数字的文本

以下标记示例演示如何定义使用的属性的 Miramonte 字体的斜线零数字[Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography)对象。

XAML复制

```xaml
<Paragraph FontFamily="Miramonte">
  <Run>Order #0048-OTC-390</Run>
  <LineBreak/>
  <Run Typography.SlashedZero="True">Order #0048-OTC-390</Run>
</Paragraph>
```



### 版式类

[Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography)对象公开的功能集的OpenType字体支持。 通过设置的属性[Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography)在标记中，您可以轻松地编写文档，充分利用OpenType功能。

以下文本显示 Pescadero 字体的标准大写字母，其后接样式为“SmallCaps”和“AllSmallCaps”的字母。 本例中，对所有三个单词均使用相同的字体大小。

![使用 OpenType 大写字母的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/opentypefont11.gif)
使用 OpenType 大写字母的文本

以下标记示例演示如何定义使用的属性的 Pescadero 字体的大写字母[Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography)对象。 使用“SmallCaps”格式时会忽略任何前导大写字母。

XAML复制

```xaml
<Paragraph FontFamily="Pescadero" FontSize="48">
  <Run>CAPITALS</Run>
  <Run Typography.Capitals="SmallCaps">Capitals</Run>
  <Run Typography.Capitals="AllSmallCaps">Capitals</Run>
</Paragraph>
```

以下代码示例完成与先前的标记事例相同的任务。

C#复制

```csharp
MyParagraph.FontFamily = new FontFamily("Pescadero");
MyParagraph.FontSize = 48;

Run run_1 = new Run("CAPITALS ");
MyParagraph.Inlines.Add(run_1);

Run run_2 = new Run("Capitals ");
run_2.Typography.Capitals = FontCapitals.SmallCaps;
MyParagraph.Inlines.Add(run_2);

Run run_3 = new Run("Capitals");
run_3.Typography.Capitals = FontCapitals.AllSmallCaps;
MyParagraph.Inlines.Add(run_3);

MyParagraph.Inlines.Add(new LineBreak());
```

#### 版式类属性

下表列出了属性、 值和默认设置[Typography](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography)对象。

| 属性                                                         | 值                                                           | 默认值                                                       |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| [AnnotationAlternates](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.annotationalternates) | 数值 - 字节                                                  | 0                                                            |
| [Capitals](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.capitals) | [AllPetiteCaps](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontcapitals#System_Windows_FontCapitals_AllPetiteCaps) \| [AllSmallCaps](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontcapitals#System_Windows_FontCapitals_AllSmallCaps) \| [Normal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontcapitals#System_Windows_FontCapitals_Normal) \| [PetiteCaps](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontcapitals#System_Windows_FontCapitals_PetiteCaps) \| [SmallCaps](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontcapitals#System_Windows_FontCapitals_SmallCaps) \| [Titling](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontcapitals#System_Windows_FontCapitals_Titling) \| [Unicase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontcapitals#System_Windows_FontCapitals_Unicase) | [FontCapitals.Normal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontcapitals#System_Windows_FontCapitals_Normal) |
| [CapitalSpacing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.capitalspacing) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `false`                                                      |
| [CaseSensitiveForms](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.casesensitiveforms) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `false`                                                      |
| [ContextualAlternates](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.contextualalternates) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `true`                                                       |
| [ContextualLigatures](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.contextualligatures) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `true`                                                       |
| [ContextualSwashes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.contextualswashes) | 数值 - 字节                                                  | 0                                                            |
| [DiscretionaryLigatures](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.discretionaryligatures) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `false`                                                      |
| [EastAsianExpertForms](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.eastasianexpertforms) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `false`                                                      |
| [EastAsianLanguage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.eastasianlanguage) | [HojoKanji](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fonteastasianlanguage#System_Windows_FontEastAsianLanguage_HojoKanji) \| [Jis04](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fonteastasianlanguage#System_Windows_FontEastAsianLanguage_Jis04) \| [Jis78](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fonteastasianlanguage#System_Windows_FontEastAsianLanguage_Jis78) \| [Jis83](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fonteastasianlanguage#System_Windows_FontEastAsianLanguage_Jis83) \| [Jis90](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fonteastasianlanguage#System_Windows_FontEastAsianLanguage_Jis90) \| [NlcKanji](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fonteastasianlanguage#System_Windows_FontEastAsianLanguage_NlcKanji) \| [Normal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fonteastasianlanguage#System_Windows_FontEastAsianLanguage_Normal) \| [Simplified](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fonteastasianlanguage#System_Windows_FontEastAsianLanguage_Simplified) \| [Traditional](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fonteastasianlanguage#System_Windows_FontEastAsianLanguage_Traditional) \| [TraditionalNames](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fonteastasianlanguage#System_Windows_FontEastAsianLanguage_TraditionalNames) | [FontEastAsianLanguage.Normal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fonteastasianlanguage#System_Windows_FontEastAsianLanguage_Normal) |
| [EastAsianWidths](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.eastasianwidths) | [Full](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fonteastasianwidths#System_Windows_FontEastAsianWidths_Full) \| [Half](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fonteastasianwidths#System_Windows_FontEastAsianWidths_Half) \| [Normal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fonteastasianwidths#System_Windows_FontEastAsianWidths_Normal) \| [Proportional](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fonteastasianwidths#System_Windows_FontEastAsianWidths_Proportional) \| [Quarter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fonteastasianwidths#System_Windows_FontEastAsianWidths_Quarter) \| [Third](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fonteastasianwidths#System_Windows_FontEastAsianWidths_Third) | [FontEastAsianWidths.Normal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fonteastasianwidths#System_Windows_FontEastAsianWidths_Normal) |
| [Fraction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.fraction) | [Normal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontfraction#System_Windows_FontFraction_Normal) \| [Slashed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontfraction#System_Windows_FontFraction_Slashed) \| [Stacked](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontfraction#System_Windows_FontFraction_Stacked) | [FontFraction.Normal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontfraction#System_Windows_FontFraction_Normal) |
| [HistoricalForms](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.historicalforms) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `false`                                                      |
| [HistoricalLigatures](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.historicalligatures) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `false`                                                      |
| [Kerning](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.kerning) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `true`                                                       |
| [MathematicalGreek](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.mathematicalgreek) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `false`                                                      |
| [NumeralAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.numeralalignment) | [Normal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontnumeralalignment#System_Windows_FontNumeralAlignment_Normal) \| [Proportional](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontnumeralalignment#System_Windows_FontNumeralAlignment_Proportional) \| [Tabular](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontnumeralalignment#System_Windows_FontNumeralAlignment_Tabular) | [FontNumeralAlignment.Normal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontnumeralalignment#System_Windows_FontNumeralAlignment_Normal) |
| [NumeralStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.numeralstyle) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | [FontNumeralStyle.Normal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontnumeralstyle#System_Windows_FontNumeralStyle_Normal) |
| [SlashedZero](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.slashedzero) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `false`                                                      |
| [StandardLigatures](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.standardligatures) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `true`                                                       |
| [StandardSwashes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.standardswashes) | 数值 - 字节                                                  | 0                                                            |
| [StylisticAlternates](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.stylisticalternates) | 数值 - 字节                                                  | 0                                                            |
| [StylisticSet1](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.stylisticset1) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `false`                                                      |
| [StylisticSet2](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.stylisticset2) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `false`                                                      |
| [StylisticSet3](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.stylisticset3) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `false`                                                      |
| [StylisticSet4](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.stylisticset4) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `false`                                                      |
| [StylisticSet5](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.stylisticset5) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `false`                                                      |
| [StylisticSet6](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.stylisticset6) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `false`                                                      |
| [StylisticSet7](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.stylisticset7) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `false`                                                      |
| [StylisticSet8](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.stylisticset8) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `false`                                                      |
| [StylisticSet9](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.stylisticset9) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `false`                                                      |
| [StylisticSet10](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.stylisticset10) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `false`                                                      |
| [StylisticSet11](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.stylisticset11) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `false`                                                      |
| [StylisticSet12](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.stylisticset12) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `false`                                                      |
| [StylisticSet13](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.stylisticset13) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `false`                                                      |
| [StylisticSet14](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.stylisticset14) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `false`                                                      |
| [StylisticSet15](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.stylisticset15) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `false`                                                      |
| [StylisticSet16](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.stylisticset16) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `false`                                                      |
| [StylisticSet17](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.stylisticset17) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `false`                                                      |
| [StylisticSet18](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.stylisticset18) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `false`                                                      |
| [StylisticSet19](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.stylisticset19) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `false`                                                      |
| [StylisticSet20](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.stylisticset20) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | `false`                                                      |
| [Variants](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.typography.variants) | [Inferior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontvariants#System_Windows_FontVariants_Inferior) \| [Normal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontvariants#System_Windows_FontVariants_Normal) \| [Ordinal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontvariants#System_Windows_FontVariants_Ordinal) \| [Ruby](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontvariants#System_Windows_FontVariants_Ruby) \| [Subscript](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontvariants#System_Windows_FontVariants_Subscript) \| [Superscript](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontvariants#System_Windows_FontVariants_Superscript) | [FontVariants.Normal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontvariants#System_Windows_FontVariants_Normal) |

## [Packaging Fonts with Applications](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/packaging-fonts-with-applications)

本主题提供概述了如何使用包字体在Windows Presentation Foundation (WPF)应用程序。

 备注

与大多数软件类型一样，字体文件也采用许可模式，而不是出售。 许可证来控制字体使用不同供应商，但一般情况下大多数许可证，包括那些涵盖字体Microsoft提供与应用程序和Windows，不允许将字体嵌入应用程序中或以其他方式重新分发。 因此，开发人员有责任确保自己具备必要的许可权，可以在应用程序中嵌入相应的字体或者以其他方式重新分布。



### 字体打包简介

您可以轻松地字体作为资源打包在您WPF应用程序显示用户界面文本和其他类型的文本基于内容。 字体可以与应用程序的程序集文件分开，也可以嵌入到这些程序集文件中。 还可以创建纯资源字体库，以供应用程序引用。

OpenType 和TrueType®字体包含类型标志 fsType，指示字体的字体嵌入许可权。 但是，这个类型标志仅引用存储在文档中的嵌入字体，而不引用嵌入到应用程序中的字体。 您可以检索字体的字体嵌入字体的权限通过创建[GlyphTypeface](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.glyphtypeface)对象并引用其[EmbeddingRights](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.glyphtypeface.embeddingrights)属性。 请参阅的"OS/2 和 Windows 指标"部分[OpenType 规范](https://www.microsoft.com/typography/otspec/os2.htm)有关 fsType 标志的详细信息。

[Microsoft 版式](https://www.microsoft.com/typography/links/)网站包括可帮助您找到特定的字体供应商或查找自定义工作的字体供应商的联系信息。



### 将字体作为内容项添加

可以将字体作为项目内容项添加到应用程序中，这些项目内容项与应用程序的程序集文件是分开的。 这意味着内容项不会作为程序集中的资源嵌入。 以下项目文件示例演示如何定义内容项。

XML复制

```xml
<Project DefaultTargets="Build"  
                xmlns="http://schemas.microsoft.com/developer/msbuild/2003">  
  <!-- Other project build settings ... -->  
  
  <ItemGroup>  
    <Content Include="Peric.ttf" />  
    <Content Include="Pericl.ttf" />  
  </ItemGroup>  
</Project>  
```

为了确保应用程序可以在运行时使用字体，这些字体必须能够从应用程序的部署目录中访问。 `<CopyToOutputDirectory>`应用程序的项目文件中的元素可用于将字体自动复制到应用程序部署目录在生成过程。以下项目文件示例演示如何将字体复制到部署目录中。

XML复制

```xml
<ItemGroup>  
  <Content Include="Peric.ttf">  
    <CopyToOutputDirectory>PreserveNewest</CopyToOutputDirectory>  
  </Content>  
  <Content Include="Pericl.ttf">  
    <CopyToOutputDirectory>PreserveNewest</CopyToOutputDirectory>  
  </Content>  
</ItemGroup>  
```

以下代码示例演示如何将应用程序的字体作为内容项来引用，所引用的内容项必须与应用程序的程序集文件位于同一个目录中。

XAML复制

```xaml
<TextBlock FontFamily="./#Pericles Light">
  Aegean Sea
</TextBlock>
```



### 将字体作为资源项添加

可以将字体作为项目资源项添加到应用程序中，这些项目资源项会嵌入到应用程序的程序集文件中。 对资源使用单独的子目录有助于对应用程序的项目文件进行整理。 以下项目文件示例演示如何在单独的子目录中将字体定义为资源项。

XML复制

```xml
<Project DefaultTargets="Build"  
                xmlns="http://schemas.microsoft.com/developer/msbuild/2003">  
  <!-- Other project build settings ... -->  
  
  <ItemGroup>  
    <Resource Include="resources\Peric.ttf" />  
    <Resource Include="resources\Pericl.ttf" />  
  </ItemGroup>  
</Project>  
```

 备注

时将字体作为资源添加到你的应用程序时，请确保您设置`<Resource>`元素，而不`<EmbeddedResource>`应用程序的项目文件中的元素。 `<EmbeddedResource>`不支持生成操作的元素。

以下标记示例演示如何引用应用程序的字体资源。

XAML复制

```xaml
<TextBlock FontFamily="./resources/#Pericles Light">
  Aegean Sea
</TextBlock>
```

#### 在代码中引用字体资源项

若要从代码中引用字体资源项，必须提供两个部分组成的字体资源引用： 基统一资源标识符 (URI); 和字体位置引用。 这些值用作参数[FontFamily](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.fontfamily.-ctor)方法。 下面的代码示例演示如何引用名为的项目子目录中的应用程序的字体资源`resources`。

C#复制

```csharp
// The font resource reference includes the base URI reference (application directory level),
// and a relative URI reference.
myTextBlock.FontFamily = new FontFamily(new Uri("pack://application:,,,/"), "./resources/#Pericles Light");
```

基统一资源标识符 (URI)可以包括字体资源所在的应用程序子目录。 在这种情况下，字体位置引用不需要指定一个目录，但必须包括前缀"`./`"，指示字体资源是指定的基的相同目录中统一资源标识符 (URI)。 以下代码示例演示另一种引用字体资源项的方法，该示例与上面的代码示例等效。

C#复制

```csharp
// The base URI reference can include an application subdirectory.
myTextBlock.FontFamily = new FontFamily(new Uri("pack://application:,,,/resources/"), "./#Pericles Light");
```

#### 在同一应用程序子目录中引用字体

可以将应用程序内容和资源文件放在应用程序项目中由用户定义的同一子目录中。 以下项目文件示例显示在同一子目录中定义的内容页和字体资源。

XML复制

```xml
<ItemGroup>  
  <Page Include="pages\HomePage.xaml" />  
</ItemGroup>  
<ItemGroup>  
  <Resource Include="pages\Peric.ttf" />  
  <Resource Include="pages\Pericl.ttf" />  
</ItemGroup>  
```

由于应用程序内容和字体位于同一子目录中，因此字体引用是相对于应用程序内容的。 以下示例演示当字体与应用程序位于同一目录中时，如何引用应用程序的字体资源。

XAML复制

```xaml
<TextBlock FontFamily="./#Pericles Light">
  Aegean Sea
</TextBlock>
```

C#复制

```csharp
// The font resource reference includes the base Uri (application directory level),
// and the file resource location, which is relative to the base Uri.
myTextBlock.FontFamily = new FontFamily(new Uri("pack://application:,,,/"), "/pages/#Pericles Light");
```

#### 在应用程序中枚举字体

若要枚举字体作为资源应用程序中的项，请使用[GetFontFamilies](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.fonts.getfontfamilies)或[GetTypefaces](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.fonts.gettypefaces)方法。 下面的示例演示如何使用[GetFontFamilies](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.fonts.getfontfamilies)方法返回的集合[FontFamily](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.fontfamily)从应用程序字体位置的对象。 在本示例中，应用程序包含一个名为“resources”的子目录。

C#复制

```csharp
foreach (FontFamily fontFamily in Fonts.GetFontFamilies(new Uri("pack://application:,,,/"), "./resources/"))
{
    // Perform action.
}
```

下面的示例演示如何使用[GetTypefaces](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.fonts.gettypefaces)方法返回的集合[Typeface](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.typeface)从应用程序字体位置的对象。 在本示例中，应用程序包含一个名为“resources”的子目录。

C#复制

```csharp
foreach (Typeface typeface in Fonts.GetTypefaces(new Uri("pack://application:,,,/"), "./resources/"))
{
    // Perform action.
}
```



#### 创建字体资源库

可以创建仅包含字体的纯资源库，这种类型的库项目中没有任何代码。 创建纯资源库是将资源与使用它们的应用程序代码分开的一种常用方法。 这还使得库程序集可以包括在多个应用程序项目中。 以下项目文件示例演示纯资源库项目的关键部分。

XML复制

```xml
<PropertyGroup>  
  <AssemblyName>FontLibrary</AssemblyName>  
  <OutputType>library</OutputType>  
  ...  
</PropertyGroup>  
...  
<ItemGroup>  
  <Resource Include="Kooten.ttf" />  
  <Resource Include="Pesca.ttf" />  
</ItemGroup  
```

#### 引用资源库中的字体

若要在应用程序中引用资源库中的字体，必须将库程序集的名称作为字体引用的前缀。 在本例中，字体资源程序集是“FontLibrary”。 若要将程序集名称与程序集内的引用分开，请使用“;”字符。 添加后跟字体名引用的“Component”关键字即完成字体库资源的完整引用。 以下代码示例演示如何引用资源库程序集内的字体。

XAML复制

```xaml
<Run FontFamily="/FontLibrary;Component/#Kootenay" FontSize="36">
  ABCDEFGHIJKLMNOPQRSTUVWXYZ
</Run>
```

> 此 SDK 包含一组示例OpenType您可以使用的字体WPF应用程序。 这些字体是在纯资源库中定义的。 有关详细信息，请参阅[示例 OpenType 字体包](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/sample-opentype-font-pack)。

### 字体的使用限制

以下列表介绍上打包和字体中使用的几个限制WPF应用程序：

- **字体嵌入权限位：**WPF 应用程序不检查或实施任何字体嵌入权限位。 请参阅[Introduction_to_Packing Fonts](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/packaging-fonts-with-applications#introduction_to_packaging_fonts)部分，了解详细信息。
- **源字体站点：** WPF应用程序不允许对 http 或 ftp 的字体引用统一资源标识符 (URI)。
- **使用包的绝对 URI： 表示法：** WPF应用程序不允许您创建[FontFamily](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.fontfamily)对象以编程方式使用"pack:"作为一部分绝对统一资源标识符 (URI)对字体引用。 例如，`"pack://application:,,,/resources/#Pericles Light"`是无效的字体引用。
- **自动嵌入字体：** 在设计时，没有用于搜索应用程序使用的字体和自动在应用程序的资源中嵌入字体支持。
- **字体子集：**WPF 应用程序不支持为非固定文档创建字体子集。
- 如果存在不正确的引用，应用程序将回退到使用可用字体。

## [Sample OpenType Font Pack](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/sample-opentype-font-pack)

本主题概述随 Windows SDK 一起分发的示例 OpenType 字体。 这些示例字体支持可供 Windows Presentation Foundation (WPF) 应用程序使用的扩展的 OpenType 功能。

### OpenType 字体包中的字体

Windows SDK 提供一组可用来创建 Windows Presentation Foundation (WPF) 应用程序的示例 OpenType 字体。这些示例字体在 Ascender Corporation 的许可下提供。 它们仅实现由 OpenType 格式所定义的全部功能的一部分。 下表列出了示例 OpenType 字体的名称。

| **名称**       | **文件**    |
| -------------- | ----------- |
| Kootenay       | Kooten.ttf  |
| Lindsey        | Linds.ttf   |
| Miramonte      | Miramo.ttf  |
| Miramonte Bold | Miramob.ttf |
| Pericles       | Peric.ttf   |
| Pericles Light | Pericl.ttf  |
| Pescadero      | Pesca.ttf   |
| Pescadero Bold | Pescab.ttf  |

下图展示了示例 OpenType 字体。

![示例字体包中的字体名称的列表](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/samplefontpack01.gif)
OpenType 字体包中的字体

这些示例字体在 Ascender Corporation 的许可下提供。 Ascender 是一家高级字体产品提供商。 若要对示例字体的扩展版本或自定义版本进行授权，请参阅 [Ascender Corporation 的网站](https://go.microsoft.com/fwlink/?LinkId=182627)。

> 开发人员有责任确保自己具备必要的许可权，可以在应用程序中嵌入相应的字体或者以其他方式重新分布。

### 安装字体

可以选择将示例 OpenType 字体安装到默认 Windows 字体目录：**\WINDOWS\Fonts**。 使用“字体”控制面板安装字体。 在计算机上安装这些字体后，引用默认 Windows 字体的所有应用程序都可访问这些字体。 可以通过双击字体文件以多种字体大小来显示具有代表性的字符集。 下面的屏幕截图显示 Lindsey 字体文件 Linds.ttf。

![Lindsey 字体(OpenType)](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/typographyinwpf-04.png)
显示 Lindsey 字体

### 使用字体

可以通过两种方法在应用程序中使用字体。 可以将字体作为项目内容项添加到应用程序中，这些项目内容项不会作为资源嵌入到程序集中。 此外，还可以将字体作为嵌入到应用程序程序集文件中的项目资源项添加到应用程序中。 有关详细信息，请参阅[将字体与应用程序一起打包](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/packaging-fonts-with-applications)。

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/fonts-how-to-topics)

在本部分中的主题演示如何使用包含的字体特性Windows Presentation Foundation (WPF)。

[枚举系统字体](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-enumerate-system-fonts)
[使用 FontSizeConverter 类](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-use-the-fontsizeconverter-class)

### [Enumerate System Fonts](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-enumerate-system-fonts)

下面的示例演示如何枚举系统字体集合中的字体。 每个字体系列名称[FontFamily](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.fontfamily)内[SystemFontFamilies](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.fonts.systemfontfamilies)作为一项添加到组合框。

C#复制

```csharp
public void FillFontComboBox(ComboBox comboBoxFonts)
{
    // Enumerate the current set of system fonts,
    // and fill the combo box with the names of the fonts.
    foreach (FontFamily fontFamily in Fonts.SystemFontFamilies)
    {
        // FontFamily.Source contains the font family name.
        comboBoxFonts.Items.Add(fontFamily.Source);
    }

    comboBoxFonts.SelectedIndex = 0;
}
```

如果多个版本的相同的字体系列驻留在相同的目录中，Windows Presentation Foundation (WPF)字体枚举返回的字体的最新版本。 如果版本信息不提供解析，则返回具有最新时间戳的字体。 如果时间戳信息是等效的则返回的字体文件，按字母顺序中排名第一。

### [Use the FontSizeConverter Class](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-use-the-fontsizeconverter-class)

此示例演示如何创建的实例[FontSizeConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontsizeconverter)并使用它来更改字体大小。

该示例定义一个名为的自定义方法`changeSize`的内容的转换[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)在单独的定义，可扩展应用程序标记语言 (XAML)的实例的文件， [Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double)，然后再转换[String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)。 此方法将传递[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)到[FontSizeConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontsizeconverter)对象，它将转换[Content](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.content)的[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)的实例[Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double)。 然后将此值传递的值为[FontSize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.fontsize)属性的[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素。

此示例还定义调用的第二个自定义方法`changeFamily`。 此方法将转换[Content](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.content)的[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)到[String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)，然后将传递到该值[FontFamily](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.fontfamily)属性[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素。

此示例不运行。

C#复制

```csharp
private void changeSize(object sender, SelectionChangedEventArgs args)
{
    ListBoxItem li = ((sender as ListBox).SelectedItem as ListBoxItem);
    FontSizeConverter myFontSizeConverter = new FontSizeConverter();
    text1.FontSize = (Double)myFontSizeConverter.ConvertFromString(li.Content.ToString());
}

private void changeFamily(object sender, SelectionChangedEventArgs args)
{
    ListBoxItem li2 = ((sender as ListBox).SelectedItem as ListBoxItem);
    text1.FontFamily = new System.Windows.Media.FontFamily(li2.Content.ToString());
}
```