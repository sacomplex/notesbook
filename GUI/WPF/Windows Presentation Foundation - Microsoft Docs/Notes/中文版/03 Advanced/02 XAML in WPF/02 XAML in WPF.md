# [XAML in WPF](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/xaml-in-wpf)

可扩展应用程序标记语言 (XAML) 编程一种声明性应用程序标记语言。 Windows Presentation Foundation (WPF)实现 aXAML 处理器实现中，并提供 XAML 语言支持。 WPF类型实现，这样它们可以为所需的类型支持的 XAML 表示形式。 一般情况下，可以创建的大多数您WPFXAML 标记中的应用程序 UI。

## 本节内容

[XAML 概述 (WPF)](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-overview-wpf)
[XAML 语法详述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-syntax-in-detail)
[WPF 中的代码隐藏和 XAML](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/code-behind-and-xaml-in-wpf)
[XAML 及 WPF 的自定义类](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-and-custom-classes-for-wpf)
[标记扩展和 WPF XAML](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/markup-extensions-and-wpf-xaml)
[WPF XAML 的 XAML 命名空间和命名空间映射](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-namespaces-and-namespace-mapping-for-wpf-xaml)
[WPF XAML 名称范围](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/wpf-xaml-namescopes)
[嵌入式样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/inline-styles-and-templates)
[在 XAML 中处理空白](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/whitespace-processing-in-xaml)
[TypeConverter 和 XAML](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/typeconverters-and-xaml)
[XML 字符实体和 XAML](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/xml-character-entities-and-xaml)
[XAML 命名空间 (x:) 语言功能](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/xaml-namespace-x-language-features)
[WPF XAML 扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/wpf-xaml-extensions)
[标记兼容 (mc:) 语言功能](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/markup-compatibility-mc-language-features)

## [XAML Overview (WPF)](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/xaml-overview-wpf)

本主题介绍 XAML 语言的功能，并演示如何使用 XAML 编写 Windows Presentation Foundation (WPF) 应用程序。本主题专门介绍 WPF 实现的 XAML。 XAML 本身是一个比 WPF 大的语言概念。

### 什么是 XAML？

XAML 是一种声明性标记语言。 应用于.NET Framework 编程模型，XAML 简化了创建UI为.NET Framework 应用程序。 可以在声明性 XAML 标记中创建可见的 UI 元素，然后使用代码隐藏文件（通过分部类定义与标记相连接）将UI 定义与运行时逻辑相分离。 XAML 直接以程序集中定义的一组特定后备类型表示对象的实例化。 这与大多数其他标记语言不同，后者通常是与后备类型系统没有此类直接关系的解释语言。 XAML 实现了一个工作流，通过此工作流，各方可以采用不同的工具来处理 UI 和应用程序的逻辑。

以文本表示时，XAML 文件是通常具有 `.xaml` 扩展名的 XML 文件。 可通过任何 XML 编码对文件进行编码，但通常以 UTF-8 编码。

以下示例演示如何创建 UI 中的按钮。 此示例仅用于初步了解 XAML 如何表示常用 UI 编程形式（它不是一个完整的示例）。

```xaml
<StackPanel>
  <Button Content="Click Me"/>
</StackPanel>
```

### XAML 语法概述

下面章节介绍 XAML 语法的基本形式，并提供一个简短的标记示例。 这些章节并不提供每个语法形式的完整信息，例如这些语法形式如何在后备类型系统中表示。 有关本主题中介绍的每种语法形式的 XAML 语法详情，请参阅 [XAML 语法详述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-syntax-in-detail)。

如果熟悉 XML 语言，则下面几节中的很多内容对你而言都是基础知识。 这归因于 XAML 的一个基本设计原则。XAML 语言可以定义其自己的概念，但这些概念也适用 XML 语言和标记形式。

#### XAML 对象元素

对象元素通常声明一个类型的实例。 该类型在程序集中定义，而后者则为使用 XAML 作为语言的技术提供后备类型。

对象元素语法始终以左尖括号 (<) 开头。 后跟要创建实例的类型的名称。 （该名称可能包含前缀，下文将解释前缀的概念。）此后可以选择声明该对象元素的特性。 要完成对象元素标记，请以右尖括号 (>) 结尾。 也可以使用不含任何内容的自结束形式，方法是用一个正斜杠后接一个右尖括号 (/>) 来完成标记。 例如，请再次查看之前演示的标记片段：

```xaml
<StackPanel>
  <Button Content="Click Me"/>
</StackPanel>
```

这指定了两个对象元素：`<StackPanel>`（含有内容，后面有一个结束标记）和 `<Button .../>`（自结束形式，包含几个特性）。 对象元素 `StackPanel` 和 `Button` 各映射到一个类名，该类由 WPF 定义并且属于 WPF 程序集。指定对象元素标记时，会创建一条指令，指示 XAML 处理创建新实例。 每个实例都是在分析和加载 XAML 时通过调用基础类型的默认构造函数来创建。

#### 特性语法 （属性）

对象的属性通常可表示为对象元素的特性。 特性语法对在特性语法中设置的属性命名，后跟赋值运算符 (=)。 特性的值始终指定为包含在引号中的字符串。

特性语法是最简化的属性设置语法，并且对曾使用过标记语言的开发人员而言是最直观的语法。 例如，以下标记将创建一个具有红色文本和蓝色背景的按钮，还将创建指定为 `Content` 的显示文本。

```xaml
<Button Background="Blue" Foreground="Red" Content="This is a button"/>
```

#### 属性元素语法

对于对象元素的某些属性，无法使用特性语法，因为无法在特性语法的引号和字符串限制内充分地表达提供属性值所必需的对象或信息。 对于这些情况，可以使用另一个语法，即属性元素语法。

属性元素开始标记的语法为 `<`*typeName*`.`*propertyName*`>`。 通常，该标记的内容是类型的对象元素，属性会将该元素作为其值。 指定内容之后，必须用结束标记结束属性元素。 结束标记的语法为 `</`*typeName*`.`*propertyName*`>`。

如果可以使用特性语法，那么使用特性语法通常更为方便，且能够实现更为精简的标记，但这通常只是样式问题，而不是技术限制。 以下示例演示在前面的特性语法示例中设置的相同属性，但这次对 `Button` 的所有属性使用属性元素语法。

```xaml
<Button>
  <Button.Background>
    <SolidColorBrush Color="Blue"/>
  </Button.Background>
  <Button.Foreground>
    <SolidColorBrush Color="Red"/>
  </Button.Foreground>
  <Button.Content>
    This is a button
  </Button.Content>
</Button>
```

#### 集合语法

XAML 语言包含一些优化，可以生成更易于阅读的标记。 其中一项优化是：如果某个特定属性采用集合类型，则在标记中声明为该属性的值内的子元素的项将成为集合的一部分。 在这种情况下，子对象元素的集合是设置为集合属性的值。

下面的示例显示了设置的值的集合语法[GradientStops](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientbrush.gradientstops)属性：

```xaml
<LinearGradientBrush>  
  <LinearGradientBrush.GradientStops>  
    <!-- no explicit new GradientStopCollection, parser knows how to find or create -->  
    <GradientStop Offset="0.0" Color="Red" />  
    <GradientStop Offset="1.0" Color="Blue" />  
  </LinearGradientBrush.GradientStops>  
</LinearGradientBrush>  
```

#### XAML 内容属性

XAML 指定了一个语言功能，通过该功能，类可以指定它的一个且仅一个属性为 XAML 内容属性。 该对象元素的子元素用于设置该内容属性的值。 换言之，仅对内容属性而言，可以在 XAML 标记中设置该属性时省略属性元素，并在标记中生成更直观的父级/子级形式。

例如，[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)指定的 content 属性[Child](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.decorator.child)。 以下两个[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)以相同方式处理元素。 第一个元素利用内容属性语法并省略 `Border.Child` 属性元素。 第二个元素显式显示 `Border.Child`。

```xaml
<Border>  
  <TextBox Width="300"/>  
</Border>  
<!--explicit equivalent-->  
<Border>  
  <Border.Child>  
    <TextBox Width="300"/>  
  </Border.Child>  
</Border>  
```

作为 XAML 语言的规则，XAML 内容属性的值必须完全在该对象元素的其他任何属性元素之前或之后指定。 例如，以下标记不会进行编译：

```
<Button>I am a   
  <Button.Background>Blue</Button.Background>  
  blue button</Button>  
```

若要深入了解 XAML 内容属性的此项限制，请参阅 [XAML 语法详述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-syntax-in-detail)的“XAML 内容属性”一节。

#### 文本内容

有少量 XAML 元素可直接将文本作为其内容来处理。 若要实现此功能，必须满足以下条件之一：

- 类必须声明一个内容属性，并且该内容属性必须属于类型可分配给一个字符串 (该类型可以是[Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object))。 例如，任何[ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)使用[Content](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.content)作为它的内容属性，它是类型[Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object)，，这在实际的上支持以下使用情况[ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)如[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button): `<Button>Hello</Button>`。
- 类型必须声明一个类型转换器，该类型转换器将文本内容用作初始化文本。 例如 `<Brush>Blue</Brush>`。 这种情况实际上并不常见。
- 类型必须为已知的 XAML 语言基元。

#### 内容属性和集合语法组合

请看以下示例：

```xaml
<StackPanel>  
  <Button>First Button</Button>  
  <Button>Second Button</Button>  
</StackPanel>  
```

在这里，每个[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)子元素的[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)。 这是一个简单直观的标记，此标记由于两个不同的原因省略了两个标记。

- **省略的 StackPanel.Children 属性元素：** [StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)派生自[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)。 [Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel) 定义[Panel.Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.children)作为其 XAML 内容属性。
- **省略的 UIElementCollection 对象元素：**[Panel.Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.children)属性采用类型[UIElementCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.uielementcollection)，它可以实现[IList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ilist)。 可以省略集合的元素标记，如处理集合的 XAML 规则基于[IList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ilist)。 (在这种情况下，[UIElementCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.uielementcollection)实际无法实例化，因为它不公开默认构造函数，而这正是[UIElementCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.uielementcollection)对象元素显示为注释掉)。

```xaml
<StackPanel>  
  <StackPanel.Children>  
    <!--<UIElementCollection>-->  
    <Button>First Button</Button>  
    <Button>Second Button</Button>  
    <!--</UIElementCollection>-->  
  </StackPanel.Children>  
</StackPanel>  
```

#### 特性语法 （事件）

特性语法还可用于事件成员，而非属性成员。 在这种情况下，特性的名称为事件的名称。 在 XAML 事件的 WPF 实现中，特性的值是实现该事件的委托的处理程序的名称。 例如，以下标记将分配的处理程序[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)在标记中创建：

```xaml
<Page 
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  x:Class="ExampleNamespace.ExamplePage">
  <Button Click="Button_Click" >Click Me!</Button>
</Page>
```

除此特性语法示例外，还有更多关于 WPF 中的事件和 XAML 的内容。 例如，可了解此处引用的 `ClickHandler` 表示什么，以及它是如何定义的。 这将在本主题后面的[事件和 XAML 代码隐藏](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-overview-wpf#events_and_xaml_codebehind)一节中介绍。

### 用例和 XAML 中的空白区域

XAML 通常区分大小写。 出于解析后备类型的目的，WPF XAML 按照 CLR 区分大小写的相同规则来区分大小写。遇到以下情况时，对象元素、属性元素和特性名称均需使用区分大小写的形式来指定：按名称与程序集中的基础类型进行比较，或者与类型的成员进行比较。 XAML 语言关键字和基元也区分大小写。 值并不总是区分大小写。 值是否区分大小写将取决于与采用该值的属性关联的类型转换器行为，或取决于属性值类型。 例如，采用 [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean)类型的属性可以使用 `true` 或 `True` 作为等效值，但只是因为在将字符串的本机 WPF XAML 分析器类型转换为 [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) 时，已允许将这些作为等效项。

WPF XAML 处理器和序列化程序将忽略或删除所有无意义的空白区域，并标准化任何有意义的空白。 这是与 XAML 规范的默认空白行为建议一致。 通常，只有在 XAML 内容属性中指定字符串时，此行为的重要性才会体现出来。 简言之，XAML 将空格、换行符和制表符转化为空格，如果它们出现在一个连续字符串的任一端，则保留一个空格。 本主题中未涉及的 XAML 空白处理的完整说明。 有关详细信息，请参阅[处理在 XAML 中的空白区域](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/whitespace-processing-in-xaml)。

### 标记扩展

标记扩展是一个 XAML 语言概念。 用于提供特性语法的值时，大括号（`{` 和 `}`）表示标记扩展用法。 此用法指示 XAML 处理不要像通常那样将特性值视为文本字符串或者可转换为字符串的值。

WPF 应用程序编程中最常用的标记扩展是 [Binding](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/binding-markup-extension)（用于数据绑定表达式）以及资源引用 [StaticResource](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/staticresource-markup-extension) 和 [DynamicResource](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dynamicresource-markup-extension)。 通过使用标记扩展，即使属性通常不支持特性语法，也可以使用特性语法为属性提供值。 标记扩展经常使用中间表达式类型实现一些功能，例如，推迟值或引用仅在运行时才存在的其他对象。

例如，以下标记设置的值[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.style)使用特性语法的属性。 [Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.style)属性采用的实例[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)类，它默认情况下不可能通过特性语法字符串实例化。 但在本例中，特性引用了特定的标记扩展 [StaticResource](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/staticresource-markup-extension)。 处理该标记扩展时，将返回对以前在资源字典中作为键控资源进行实例化的某个样式的引用。

```xaml
<Page.Resources>
  <SolidColorBrush x:Key="MyBrush" Color="Gold"/>
  <Style TargetType="Border" x:Key="PageBackground">
    <Setter Property="Background" Value="Blue"/>
  </Style>
</Page.Resources>
<StackPanel>
  <Border Style="{StaticResource PageBackground}">
  </Border>
</StackPanel>
```

有关特定在 WPF 中实现的所有 XAML 标记扩展的参考列表，请参阅 [WPF XAML 扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/wpf-xaml-extensions)。 有关由 System.Xaml 和可更广泛的.NET Framework XAML 实现定义的标记扩展的引用列表，请参阅[XAML Namespace （x:）语言功能](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/xaml-namespace-x-language-features)。 有关标记扩展概念的详细信息，请参阅[标记扩展和 WPF XAML](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/markup-extensions-and-wpf-xaml)。

### 类型转换器

在 [XAML 语法概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-overview-wpf#xaml_syntax_in_brief)一节中，曾提到特性值必须能够通过字符串进行设置。 如何将字符串转换为其他对象类型或基元值的基本本机处理取决于[String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)类型本身，除了为本机代码处理某些类型，如[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)或[Uri](https://docs.microsoft.com/zh-cn/dotnet/api/system.uri)。 但是很多 WPF 类型或这些类型的成员扩展了基本字符串特性处理行为，因此可以将更复杂的对象类型的实例指定为字符串和特性。

[Thickness](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.thickness)结构是一种具有 XAML 用法的类型转换的类型。 [Thickness](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.thickness) 指示嵌套矩形中的度量值，用于为值属性如[Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)。 通过在上放置类型转换器[Thickness](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.thickness)，使用的所有属性[Thickness](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.thickness)更轻松地指定在 XAML 中，因为它们可以指定为属性。 下面的示例使用类型转换和特性语法提供的值[Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin):

```xaml
<Button Margin="10,20,10,30" Content="Click me"/>
```

以上特性语法示例等效于以下更详细的语法示例中，其中[Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)改为通过属性元素语法，其中包含设置[Thickness](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.thickness)对象元素。 四个重要的属性的[Thickness](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.thickness)都设置为特性的新实例：

```xaml
<Button Content="Click me">
  <Button.Margin>
    <Thickness Left="10" Top="20" Right="10" Bottom="30"/>
  </Button.Margin>
</Button>
```

> 对于少数对象，类型转换是在不涉及子类的情况下将属性设置为此类型的唯一公开方式，因为类型自身没有默认构造函数。 例如， [Cursor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.cursor)。

若要深入了解如何支持类型转换及其在特性语法上的应用，请参阅 [TypeConverters 和 XAML](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/typeconverters-and-xaml)。

### XAML 根元素和 XAML 命名空间

一个 XAML 文件只能有一个根元素，这样才能同时作为格式正确的 XML 文件和有效的 XAML 文件。 对于典型的 WPF 方案，你可以使用 WPF 应用程序模型中具有重要意义的根元素 (例如，[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)或[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)页上，对于[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)为外部字典，或[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)应用程序定义)。 下面的示例显示了典型的 XAML 文件的根元素WPF页上，使用的根元素[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)。

```xaml
<Page
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
</Page>
```

根元素还包含特性 `xmlns` 和 `xmlns:x`。 这些特性向 XAML 处理器指示哪些 XAML 命名空间包含标记将其作为元素引用的后备类型的类型定义。 `xmlns` 特性明确指示默认的 XAML 命名空间。 在默认的 XAML 命名空间中，可以不使用前缀指定标记中的对象元素。 对于大多数 WPF 应用程序方案以及 SDK 的 WPF 部分中给出的几乎所有示例，默认的 XAML 命名空间均映射到 WPF 命名空间 http://schemas.microsoft.com/winfx/2006/xaml/presentation。 `xmlns:x` 特性指示另一个 XAML 命名空间，该命名空间映射 XAML 语言命名空间http://schemas.microsoft.com/winfx/2006/xaml。

使用 `xmlns` 定义用法范围和名称范围映射的做法符合 XML 1.0 规范。 XAML 名称范围与 XML 名称范围的不同仅在于：XAML 名称范围还包含有关进行类型解析和分析 XAML 时名称范围的元素如何受类型支持的信息。

请注意，只有在每个 XAML 文件的根元素上，`xmlns` 特性才是绝对必需的。 `xmlns` 定义将适用于根元素的所有子代元素（此行为也符合 `xmlns` 的 XML 1.0 规范）。同时允许根以下的其他元素上具有 `xmlns` 特性，这些特性将适用于定义元素的任何子代元素。 但是，频繁定义或重新定义 XAML 命名空间会导致难以阅读 XAML 标记样式。

其 XAML 处理器的 WPF 实现包括可识别 WPF 核心程序集的基础结构。 已知 WPF 核心程序集包含支持指向默认 XAML 命名空间的 WPF 映射的类型。 这是通过项目生成文件中的配置以及 WPF 生成和项目系统实现的。 因此，为了引用来自 WPF 程序集的 XAML 元素，只需将默认 XAML 命名空间声明为默认 `xmlns`。

#### X： 前缀

在之前的根元素示例中，前缀 `x:` 用于映射 XAML 命名空间 http://schemas.microsoft.com/winfx/2006/xaml，该命名空间是支持 XAML 语言构造的专用 XAML 命名空间。 在这整个 SDK 的项目模板、示例以及文档中，此 `x:`前缀用于映射该 XAML 命名空间。 XAML 语言的 XAML 命名空间包含多个将在 XAML 中频繁使用的编程构造。 下面列出了最常用的 `x:` 前缀编程构造：

- [X:key](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-key-directive):设置的每个资源的唯一键[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)（或其他框架中的类似字典概念）。 在典型的 WPF 应用程序标记中的所有 `x:` 用法中，`x:Key` 可能占到 90%。
- [x： 类](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-class-directive):指定CLR为 XAML 页提供代码隐藏类的命名空间和类名。 必须具有这样一个类才能支持每个 WPF 编程模型的代码隐藏，因此即使没有资源，也几乎总是能看到映射的 `x:`。
- [x： 名称](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-name-directive):处理对象元素后，在运行时代码中指定存在的实例的运行时对象名称。 通常，经常为 [x:Name](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-name-directive) 使用 WPF 定义的等效属性。 此类属性特定映射到 CLR 后备属性，因此更便于进行应用程序编程，在应用程序编程中，经常使用运行时代码从初始化的 XAML 中查找命名元素。 最常见的此类属性是[FrameworkElement.Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.name)。 仍然可以使用[X:name](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-name-directive)时等效的 WPF 框架级[Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.name)特定类型中不支持属性。 某些动画方案中会发生这种情况。
- [x:Static](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-static-markup-extension):可以返回一个静态值，否则不是 XAML 兼容属性的引用。
- [x： 类型](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-type-markup-extension):构造[Type](https://docs.microsoft.com/zh-cn/dotnet/api/system.type)引用基于类型名称。 这用于指定需要的属性[Type](https://docs.microsoft.com/zh-cn/dotnet/api/system.type)，如[Style.TargetType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style.targettype)，但属性经常具有本机字符串-到-[Type](https://docs.microsoft.com/zh-cn/dotnet/api/system.type)转换的方式， [x： 类型](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-type-markup-extension)标记扩展用法是可选。

`x:` 前缀/XAML 命名空间中还有其他一些不太常见的编程构造。 有关详细信息，请参阅[XAML Namespace （x:）语言功能](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/xaml-namespace-x-language-features)。

### 自定义前缀和 XAML 中的自定义类型

对于自身的自定义程序集或 PresentationCore、PresentationFramework 和 WindowsBase 的 WPF 核心以外的程序集，可以将该程序集指定为自定义 `xmlns` 映射的一部分。 只要该类型能够正确地实现以支持正在尝试的 XAML 用法，就可以在 XAML 中引用该程序集中的类型。

下面是一个说明自定义前缀如何在 XAML 标记中工作的基本示例。 前缀 `custom` 在根元素标记中定义，并映射为打包在应用程序中并随应用程序一起提供的特定程序集。 此程序集包含 `NumericUpDown` 类型，实现该类型的目的是在支持常规 XAML 用法之外，还可以使用允许在 WPF XAML 内容模型的此特定点执行插入的类继承。 通过使用该前缀，此 `NumericUpDown` 控件的一个实例声明为对象元素，以便 XAML 分析程序可找到包含该类型的 XAML 命名空间，从而找到包含该类型定义的后备程序集的位置。

```
<Page  
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"   
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"   
    xmlns:custom="clr-namespace:NumericUpDownCustomControl;assembly=CustomLibrary"  
    >  
  <StackPanel Name="LayoutRoot">  
    <custom:NumericUpDown Name="numericCtrl1" Width="100" Height="60"/>  
...  
  </StackPanel>  
</Page>  
```

有关 XAML 中自定义类型的详细信息，请参阅 [XAML 及 WPF 的自定义类](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-and-custom-classes-for-wpf)。

若要深入了解 XML 命名空间与程序集中后备代码的命名空间之间的关系，请参阅 [WPF XAML 的 XAML 命名空间和命名空间映射](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-namespaces-and-namespace-mapping-for-wpf-xaml)。

### 事件和 XAML 代码隐藏

大多数 WPF 应用程序既包括 XAML 标记，也包括代码隐藏。 在项目中，XAML 编写为`.xaml`文件，和一个CLR使用如 Microsoft Visual Basic 或 C# 的语言来编写代码隐藏文件。 在 WPF 编程和应用程序模型中对 XAML 文件进行标记编译时，XAML 文件的 XAML 代码隐藏文件的位置是通过如下方式来标识的：以 XAML 根元素的 `x:Class` 特性形式指定一个命名空间和类。

通过目前已介绍的示例，你已了解了几个按钮，但这其中没有一个按钮具有任何与其关联的逻辑行为。 为对象元素添加行为的主要应用程序级机制是使用元素类的现有事件，并为在运行时引发该事件时调用的该事件编写特定的处理程序。 在标记中指定事件名称以及要使用的处理程序的名称，而在代码隐藏中定义实现处理程序的代码。

```xaml
<Page 
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  x:Class="ExampleNamespace.ExamplePage">
  <Button Click="Button_Click" >Click Me!</Button>
</Page>
```

```csharp
namespace ExampleNamespace
{
  public partial class ExamplePage
  {
    void Button_Click(object sender, RoutedEventArgs e)
    {
      Button b = e.Source as Button;
      b.Foreground = Brushes.Red;
    }
  }
}
```

请注意，代码隐藏文件使用 CLR 命名空间 `ExampleNamespace` 并将 `ExamplePage` 声明为该命名空间内的一个分部类。 这相当于 `ExampleNamespace`.`ExamplePage` 的 `x:Class` 特性值， 前者在标记根中提供。 WPF 标记编译器将通过从根元素类型派生一个类，为编译的任何 XAML 文件创建一个分部类。 在提供定义同一分部类的代码隐藏时，将在与编译的应用程序相同的命名空间和类中合并生成的代码。

若要深入了解 WPF 中代码隐藏编程的要求，请参阅 [WPF 中的代码隐藏和 XAML ](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/code-behind-and-xaml-in-wpf)中的“代码隐藏、事件处理程序和分部类要求”一节。

如果不需要创建单独的代码隐藏文件，还可以将代码内联到 XAML 文件中。 但是，内联代码是一种通用性较低的方法，具有很多的限制。 有关详细信息，请参阅 [WPF 中的代码隐藏和 XAML](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/code-behind-and-xaml-in-wpf)。

#### 路由的事件

路由事件是一个特殊的事件功能，该功能是 WPF 的基础。 路由事件使一个元素可以处理另一个元素引发的事件，前提是这些元素通过树关系连接在一起。 使用 XAML 特性指定事件处理时，可以对任何元素（包括未在类成员表中列出该特定事件的元素）侦听和处理该路由事件。 这是通过以所属类名限定事件名特性来实现的。 例如，父`StackPanel`在持续`StackPanel` / `Button`示例无法注册的子元素按钮的处理程序[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)通过指定属性的事件`Button.Click`上`StackPanel`带有处理程序的名称作为属性值的对象元素。 若要深入了解路由事件的工作原理，请参阅[路由事件概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/routed-events-overview)。

### XAML 命名元素

默认情况下，通过处理 XAML 对象元素在对象图中创建的对象实例没有唯一标识符或对象引用。 相反，如果在代码中调用构造函数，则几乎总是使用构造函数结果为构造的实例设置变量，以便以后在代码中引用该实例。 为了对通过标记定义创建的对象提供标准化访问，XAML 定义了 [x:Name 特性](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-name-directive)。 可以在任何对象元素上设置 `x:Name`特性的值。 在代码隐藏中，所选标识符等效于引用所构造的实例的实例变量。 在所有方面，命名元素以类似于对象实例的方式工作（名称引用实例），并且代码隐藏可以通过引用命名元素来处理应用程序内的运行时交互。 此连接实例和变量之间实现由 WPF XAML 标记编译器，并更具体涉及到功能和模式如[InitializeComponent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.icomponentconnector.initializecomponent)不会在本主题中详细讨论的。

WPF 框架级 XAML 元素继承[Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.name)属性，它等效于定义 XAML`x:Name`属性。 其他某些类也为 `x:Name`（通常也定义为 `Name` 属性）提供属性级等效项。 一般而言，如果在所选元素/类型的成员表中找不到 `Name` 属性，则可以改用 `x:Name`。 `x:Name`值将提供可在运行时，通过特定子系统或实用工具方法，如的 XAML 元素标识符[FindName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.findname)。

下面的示例设置[Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.name)上[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)元素。 然后，处理程序上的[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)中的[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)引用[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)通过其实例引用`buttonContainer`通过设置[Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.name)。

```xaml
<StackPanel Name="buttonContainer">
  <Button Click="RemoveThis">Click to remove this button</Button>
</StackPanel>
```
```csharp
void RemoveThis(object sender, RoutedEventArgs e)
{
    FrameworkElement fe = e.Source as FrameworkElement;
    if (buttonContainer.Children.Contains(fe))
    {
        buttonContainer.Children.Remove(fe);
    }
}
```

和变量一样，实例的 XAML 名称受范围概念约束，因此可以在可预测的某个范围内强制名称唯一。 定义页面的主标记表示一个唯一的 XAML 名称范围，而该 XAML 名称范围的边界是该页面的根元素。 但是，其他标记源（如样式或样式中的模板）可以在运行时与页面交互，这种标记源常常具有自己的 XAML 名称范围，这些名称范围不一定与页面的 XAML 名称范围相关联。 有关详细信息`x:Name`和 XAML 名称范围，请参阅[Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.name)， [X:name 指令](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-name-directive)，或[WPF XAML 名称范围](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/wpf-xaml-namescopes)。

### 附加的属性和附加的事件

XAML 指定了一个语言功能，该功能允许对任何元素指定某些属性或事件，而不管要设置属性或事件的元素的类型定义中是否存在该属性或事件。 该功能的属性版本称为附加属性，事件版本称为附加事件。 从概念上讲，可以将附加属性和附加事件视为可以在任何 XAML 元素/对象实例上设置的全局成员。 但是，元素/类或更大的基础结构必须支持附加值的后备属性存储。

通常通过特性语法来使用 XAML 中的附加属性。 在特性语法中，可以采用 *ownerType*.*propertyName* 的形式指定附加属性。

表面上，这与属性元素用法类似，但在这种情况下，所指定的 *ownerType* 始终是一种与从中要设置附加属性的对象元素不同的类型。 *ownerType* 这种类型提供 XAML 处理器为获取或设置附加属性值所需要的访问器方法。

附加属性的最常见方案是使子元素向其父元素报告属性值。

下面的示例演示[DockPanel.Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.dock)附加属性。 [DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)类定义的访问器[DockPanel.Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.dock)，因此拥有附加的属性。[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)类还包括逻辑迭代其子元素并具体检查每个元素的设置值[DockPanel.Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.dock)。 如果找到一个值，将在布局过程中使用该值定位子元素。 利用[DockPanel.Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.dock)附加的属性和这种定位功能事实上是激动人心的一面[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)类。

```xaml
<DockPanel>
  <Button DockPanel.Dock="Left" Width="100" Height="20">I am on the left</Button>
  <Button DockPanel.Dock="Right" Width="100" Height="20">I am on the right</Button>
</DockPanel>
```

在 WPF 中，大部分或所有附加属性还作为依赖属性实现。 有关详细信息，请参阅[附加属性概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/attached-properties-overview)。

附加事件使用类似的 *ownerType*.*eventName* 特性语法形式。 和非附加事件一样，XAML 中附加事件的特性值指定对元素处理事件时调用的处理程序方法的名称。 在 WPF XAML 中使用附加事件并不常见。 有关详细信息，请参阅[附加事件概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/attached-events-overview)。

### 基类型和 XAML

基础 WPF XAML 及其 XAML 命名空间是类型的一个集合，这些类型对应于 CLR 对象以及 XAML 的标记元素。 但是，并不是所有的类都能映射到元素。 抽象类，如[ButtonBase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase)，并且某些非抽象基类，这些类用于中的继承CLR对象模型。 基类（包括抽象类）对于 XAML 开发仍然很重要，因为每个具体的 XAML 元素都从其层次结构中的某个基类继承成员。 通常，这些成员包括可以设置为元素特性的属性或者可以处理的事件。 [FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement) 是的具体基础UI的类WPFWPF 框架级别。 在设计时UI，将使用各种形状、 面板、 装饰器，或从派生控件类，其中所有[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)。 相关的基类[FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement)，支持适合流布局表示形式的工作的面向文档的元素使用API特意镜像API中[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)。 元素级的特性和 CLR 对象模型的组合提供一组通用的属性，这些属性可以在大多数具体的 XAML 元素上设置，而不管具体的 XAML 元素及其基础类型。

### XAML 安全性

XAML 是一种直接表示对象实例化和执行的标记语言。 因此，在 XAML 中创建的元素能够像等效的生成代码那样与系统资源（如网络访问、文件系统 IO）进行交互。

WPF 支持 .NET Framework 4 安全框架代码访问安全性 (CAS)。 这意味着在 Internet 区域中运行的 WPF 内容具有缩减的执行权限。 “宽松型 XAML”（由 XAML 查看器在加载时解释的非编译 XAML 的页面）和 XAML 浏览器应用程序 (XBAP) 通常在此 Internet 区域中运行，并且使用相同的权限集。 但是，加载到完全受信任的应用程序中的 XAML 与承载应用程序具有相同的系统资源访问权限。 有关详细信息，请参阅 [WPF 部分信任安全性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/wpf-partial-trust-security)。

### 从代码加载 XAML

XAML 可用于定义整个 UI，但有时也适合在 XAML 中定义一部分 UI。 此功能可用于实现部分自定义、在本地存储信息，使用 XAML 提供业务对象或者各种可能的方案。 这些方案的关键在于[XamlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.xamlreader)类并将其[Load](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.xamlreader.load)方法。 输入是 XAML 文件，而输出是对象，该对象表示从该标记创建的整个运行时对象树。 然后可以插入该对象，作为应用程序中已存在的另一个对象的属性。 只要该属性在内容模型中是一个合适的属性，而该内容模型具有最终显示功能并且将通知执行引擎已向应用程序添加新内容，就可以通过在 XAML 中进行加载非常轻松地修改正在运行的应用程序的内容。 请注意，通常只在完全受信任的应用程序中使用此功能，因为将文件加载到正在运行的应用程序中会带来明显的安全隐患。

### 后续步骤

本主题简单介绍适用于 WPF 的 XAML 语法概念和术语。 若要深入了解本文使用的术语，请参阅 [XAML 语法详述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-syntax-in-detail)。

如果尚未这样做，请尝试教程主题中的练习[演练：我第一个 WPF 桌面应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/getting-started/walkthrough-my-first-wpf-desktop-application)。 创建该教程中介绍的以标记为中心的应用程序时，该练习有助于巩固本主题中介绍的许多概念。

WPF 使用特定应用程序模型为基础的[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)类。 有关详细信息，请参阅[应用程序管理概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/application-management-overview)。

[生成 WPF 应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/building-a-wpf-application-wpf)详细介绍如何通过命令行以及使用 Microsoft Visual Studio 生成包含 XAML 的应用程序。

[依赖属性概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-properties-overview)详细介绍 WPF 中属性的多样性，并介绍依赖属性的概念。

## [XAML Syntax In Detail](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/xaml-syntax-in-detail)

本主题定义的术语，用于描述的 XAML 语法的元素。 这些条款通常使用，本文档中，同时用于 WPF 文档的其余部分专门以及其他使用 XAML 或通过 XAML 语言支持在 System.Xaml 级别启用的基本 XAML 概念的框架。 本主题进一步在本主题中引入的基本术语[XAML 概述 (WPF)](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-overview-wpf)。

### XAML 语言规范

在此处定义的 XAML 语法术语还定义或引用中 XAML 语言规范。 XAML 是一种基于 XML 语言并遵循或 XML 结构规则进行了扩展。 一些术语从共享或基于描述 XML 语言或 XML 文档对象模型时，通常使用的术语。

有关 XAML 语言规范的详细信息，请下载[ [MS XAML\] ](https://go.microsoft.com/fwlink/?LinkId=114525)从 Microsoft 下载中心获得。

### XAML 和 CLR

XAML 是一种标记语言。 公共语言运行时 (CLR)、 为隐含按其名称，启用运行时执行。 XAML 不是本身直接由 CLR 运行时的常见语言之一。 相反，您可以将 XAML 为支持其自己的类型系统。 CLR 和 CLR 类型系统上构建 WPF 使用的特定 XAML 分析系统。 XAML 类型映射到 CLR 类型时用于 WPF XAML 分析实例化的运行的时表示形式。 出于此原因，讨论本文档中的语法的其余部分将包括对 CLR 类型系统，即使在 XAML 语言规范中的等效语法讨论不这样做也是如此。 （每个 XAML 语言规范级别，XAML 类型无法映射到任何其他类型的系统，这不一定要 CLR，但这需要创建和使用不同的 XAML 分析器。）

#### 类型和类继承的成员

属性和事件作为它们显示为的 XAML 成员WPF类型通常继承自基类型。 例如，请考虑以下示例： `<Button Background="Blue" .../>`。 [Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)属性不是立即声明的属性上[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)类，如果要查看的类定义、 反射结果或文档。 相反，[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)继承自基类[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)类。

类继承行为的WPFXAML 元素是从 XML 标记的架构上强制实施解释大不同之处。 类继承可能非常复杂，特别是在中间基类为抽象类，或当涉及到接口时。 这是原因之一，很难进行表示准确完整地使用架构类型的 XAML 元素和其允许的属性集通常用于XML编程，如 DTD 或 XSD 格式。 另一个原因是可扩展性和类型映射功能的 XAML 语言本身不允许的类型和成员的任何固定表示形式的完整性。



### 对象元素语法

*对象元素语法*是实例的 CLR 类或结构化通过声明的 XML 元素的 XAML 标记语法。 此语法类似于其他标记语言，如 HTML 元素语法。 对象元素语法开头左尖括号 (<)，然后立即由类或结构被实例化的类型名称。 类型名称，后面可以有零个或多个空格和零个或多个属性还可以声明的对象元素上使用一个或多个空格来分隔每个特性名称 ="值"对。 最后，必须是以下值之一，则返回 true:

- 必须由正斜杠 （/） 后紧跟右尖括号 (>) 关闭的元素和标记。
- 必须是右尖括号 (>) 完成的开始标记。 其他对象元素、 属性元素或内部文本，可以按照开始标记。 完全可能此处包含哪些内容通常受对象模型的元素。 关闭对象元素标记的等效项也必须位于正确的嵌套，并与其他开始和结束标记对之间实现平衡。

由.NET 实现的 XAML 具有一组规则可将对象元素映射到类型，为属性或事件和 XAML 命名空间到 CLR 命名空间和程序集的属性。 对于 WPF 和.NET Framework 中，XAML 对象元素将映射到Microsoft .NET中定义的类型引用的程序集，它的属性映射到这些类型的成员。 在引用 XAML 中的 CLR 类型时，你有权访问该类型的继承成员。

例如，下面的示例是实例化的新实例的对象元素语法[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)类，并且还指定了[Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.name)属性和该属性值：

XAML复制

```xaml
<Button Name="CheckoutButton"/>
```

下面的示例是对象元素语法，它还包括 XAML 内容属性语法。 中包含的内部文本将用于设置[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)XAML 内容属性[Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.text)。

XAML复制

```xaml
<TextBox>This is a Text Box</TextBox>
```

#### 内容模型

类可能支持作为 XAML 对象元素语法中，根据使用情况，但该元素将仅在中正常工作的应用程序或页放在整体内容的模型或元素树的预期位置。 例如，[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)通常只能放置的小孩[MenuBase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.menubase)派生类，如[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)。 内容模型的特定元素编写为的控件和其他类页上的备注部分一部分WPF可以用作 XAML 元素的类。

### 对象元素的属性

在 XAML 中的属性是设置各种可能的语法。 根据要设置的属性的基础类型系统特征，哪种语法可用于特定属性将有所不同。

通过设置属性的值，您向特性或功能对象存在于运行的时对象图中。 从对象元素创建的对象的初始状态基于默认构造函数行为。 通常情况下，应用程序将使用的任何给定的对象的完全默认实例以外的内容。

### 特性语法（属性）

特性语法是通过现有的对象元素上声明属性来设置属性的值的 XAML 标记语法。 属性名称必须与支持相关对象元素的类的属性的 CLR 成员名称相匹配。 属性名称后跟赋值运算符 （=）。 特性值必须括在引号内的字符串。

> 可以使用替代引号将文本引号在特性中。 例如可以作为一种方式使用单引号来声明包含在其中一个双引号字符的字符串。 无论使用单引号或双引号时，应使用匹配对用于打开和关闭属性值字符串。 也有转义序列或其他技术可用于解决施加任何特定的 XAML 语法的字符限制。 请参阅[XML 字符实体和 XAML](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/xml-character-entities-and-xaml)。

若要通过特性语法进行设置，属性必须是公共的并且必须是可写。 在后备类型系统中的属性的值必须是值类型，或必须一个引用类型，可以实例化或访问相关时引用由 XAML 处理器支持类型。

WPF XAML 事件的事件的属性名称作为引用必须是公共的和具有公共委托。

属性或事件必须是类或结构，它包含的对象元素由实例化的成员。

#### 处理的属性值

由 XAML 处理器进行处理的开始和结束引号内包含的字符串值。 对于属性，由基础的 CLR 属性的类型确定的默认处理行为。

通过下列选项之一来填充属性值使用此处理顺序：

1. 如果 XAML 处理器遇到大括号或从派生的对象元素[MarkupExtension](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.markupextension)、 然后引用的标记扩展而不是处理为字符串，值首先计算和标记扩展返回的对象用作值。 在许多情况下通过标记扩展返回的对象将对现有对象或一个表达式，用于将计算推迟到运行时，不是一个新实例化的对象的引用。
2. 如果属性声明与特性化[TypeConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter)，或该属性的值类型声明与特性化[TypeConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter)属性的字符串值提交到作为转换输入的类型转换器，则转换器将返回新的对象实例。
3. 如果没有任何[TypeConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter)，尝试直接转换为属性类型。 最后一个级别是在 XAML 语言基元类型或检查枚举 （分析器，然后访问匹配的值） 中的命名常量的名称之间的分析器本机值的直接转换。

##### 枚举属性值

XAML 中的枚举本质上处理的 XAML 分析程序，并应通过指定一个枚举的已命名常数的字符串名称来指定枚举的成员。

无标志枚举值，对于本机行为是处理的属性值的字符串，并将其解析为枚举值之一。 未指定枚举的格式*枚举*。*值*，如代码中执行操作。 相反，您指定仅*值*，并*枚举*由你设置的属性的类型推断。 如果指定中的属性*枚举*。*值*窗体，它将无法正确解析。

对于按标志枚举，该行为基于[Enum.Parse](https://docs.microsoft.com/zh-cn/dotnet/api/system.enum.parse)方法。 可以用逗号分隔每个值来指定多个按标志枚举值。 但是，不能合并不按标志的枚举值。 例如，不能使用逗号语法以尝试创建[Trigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.trigger)作用于无标志枚举的多个条件：

复制

```
<!--This will not compile, because Visibility is not a flagwise enumeration.-->  
...  
<Trigger Property="Visibility" Value="Collapsed,Hidden">  
  <Setter ... />  
</Trigger>  
...  
```

支持可在 XAML 中设置的属性的按标志枚举是在 WPF 中不常见。 但是，一个此类枚举是[StyleSimulations](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stylesimulations)。 例如，可以使用以逗号分隔按标志特性语法来修改提供的备注中的示例[Glyphs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.glyphs)类;`StyleSimulations = "BoldSimulation"`可能会变得`StyleSimulations = "BoldSimulation,ItalicSimulation"`。[KeyBinding.Modifiers](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keybinding.modifiers) 是另一个属性可以指定多个枚举值的位置。 但是，此属性恰好是一种特殊情况，因为[ModifierKeys](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.modifierkeys)枚举支持其自己的类型转换器。 修饰符的类型转换器使用加号 （+） 作为分隔符，而不是逗号 （，）。 此转换支持更传统的语法来表示在 Microsoft Windows 编程中，如"Ctrl + Alt"键组合。

#### 属性和事件成员名称的引用

在指定特性时，可以引用任何属性或作为您实例化包含的对象元素的 CLR 类型的成员存在的事件。

或者，可以引用的附加的属性或附加事件，独立于包含的对象元素。 （下一节讨论是附加的属性）。

也可以命名通过使用可通过默认命名空间访问的任何对象中的任何事件*typeName*。*事件*部分限定的名称; 此语法支持附加路由事件的处理程序用于处理从子元素，但父元素路由事件处理程序未安装该事件在其成员表中。 此语法类似于附加的事件语法，但此处的事件不是真正的附加的事件。 相反，正在引用具有限定名称的事件。 有关详细信息，请参阅[路由事件概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/routed-events-overview)。

在某些情况下，作为一个属性，而不是属性名称的值有时提供属性名称。 该属性名称还可以包括限定符，例如窗体中指定的属性*ownerType*。*依赖项属性名称*。 在 XAML 中编写样式或模板时，此方案中很常见。 处理规则的属性名称用作属性值不同，并按所设置的属性的类型或特定 WPF 子系统的行为受控。 有关详细信息，请参阅[样式和模板化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/styling-and-templating)。

当属性值描述的属性关系时，属性名称的另一个使用情况。 此功能用于数据绑定和情节提要目标和情况下启用[PropertyPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertypath)类，其类型转换器。 查找语义的更完整说明，请参阅[PropertyPath XAML 语法](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/propertypath-xaml-syntax)。

### 属性元素语法

*属性元素语法*是一种语法与元素的基本 XML 语法规则略有不同。 在 XML 中，属性值是一个实际的字符串，唯一可能的变化是正在使用哪种字符串编码格式。 在 XAML 中，可以将其他对象元素的属性的值。 此功能启用的属性元素语法。 而不是作为元素标记中的属性所指定的属性，属性使用指定的开始元素标记中的*元素类型名称*。*propertyName*窗体中，指定的属性的值，然后结束属性元素。

具体而言，该语法以左尖括号 (<)，然后立即由类或结构中包含的属性元素语法的类型名称。 这被紧跟由单个点 （.），然后属性的名称，然后是右尖括号 (>)。 与特性语法中，该属性必须存在于指定类型的声明的公共成员。要分配给属性的值包含在属性元素中。 通常情况下，给出的值作为一个或多个对象元素，因为对象指定为值是该方案的属性元素语法的意图是地址。 最后，指定相同的等效的结束标记*元素类型名称*。*propertyName*必须提供组合中正确嵌套和与其他元素标记的平衡。

例如，以下是属性元素语法[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.contextmenu)属性的[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。

```xaml
<Button>
  <Button.ContextMenu>
    <ContextMenu>
      <MenuItem Header="1">First item</MenuItem>
      <MenuItem Header="2">Second item</MenuItem>
    </ContextMenu>
  </Button.ContextMenu>
  Right-click me!</Button>
```

属性元素中的值可以还提供内部文本，在所指定的属性类型的基元值类型，情况下如[String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)，或指定名称的枚举。这两种用法是某种程度上不常见，因为每个这种情况下也可以使用更简单的属性语法。 用字符串填充的属性元素的一个方案是不是 XAML 内容属性，但仍用于 UI 文本表示形式的属性和特定的空白元素，如的换行所需的 UI 文本中显示。 特性语法不能保留的换行，但属性元素语法可以前提是重要的空白区域保留处于活动状态 (有关详细信息，请参阅[处理在 XAML 中的空白区域](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/whitespace-processing-in-xaml))。 另一种情况是，以便[X:uid 指令](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-uid-directive)可以应用于属性元素，并作为一个值，应在 WPF 中本地化输出 BAML 或通过其他技术，因此标记内的值。

WPF 逻辑树中不会显示的属性元素。 Property 元素是只是一种特定的语法，来设置属性，并且不具有的实例或对象支持它的元素。 (逻辑树概念的详细信息，请参阅[WPF 中的树](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/trees-in-wpf)。)

对于支持属性和属性元素语法的位置的属性，这两种语法通常具有相同的结果，尽管微妙之处，例如空白处理语法之间略有不同。

### 集合语法

XAML 规范要求 XAML 处理器实现来标识的属性的值类型的集合。 在.NET 中的常规 XAML 处理器实现取决于托管的代码和 CLR，并标识集合类型通过以下项之一：

- 类型实现[IList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ilist)。
- 类型实现[IDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.idictionary)。
- 派生自类型[Array](https://docs.microsoft.com/zh-cn/dotnet/api/system.array)(有关在 XAML 中数组的详细信息，请参阅[X:array 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-array-markup-extension)。)

如果属性的类型是一个集合，然后不需要为对象元素标记中指定推断的集合类型。 相反，旨在成为集合中的项的元素被指定为一个或多个属性元素的子元素。 每个此类项在加载期间计算为一个对象，然后通过调用添加到集合`Add`隐式集合的方法。 例如，[Triggers](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style.triggers)的属性[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)采用专用的集合类型[TriggerCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.triggercollection)，它可以实现[IList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ilist)。 不需要实例化[TriggerCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.triggercollection)标记中的对象元素。 相反，您可以指定一个或多个[Trigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.trigger)项中的元素作为`Style.Triggers`属性元素中，其中[Trigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.trigger)（或派生的类） 是应作为项类型的强类型化和隐式类型[TriggerCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.triggercollection)。

```xaml
<Style x:Key="SpecialButton" TargetType="{x:Type Button}">
  <Style.Triggers>
    <Trigger Property="Button.IsMouseOver" Value="true">
      <Setter Property = "Background" Value="Red"/>
    </Trigger>
    <Trigger Property="Button.IsPressed" Value="true">
      <Setter Property = "Foreground" Value="Green"/>
    </Trigger>
  </Style.Triggers>
</Style>
```

属性可能是集合类型和该类型的 XAML 内容属性和派生类型，对其进行讨论此主题的下一节中。

尽管不会显示为元素的标记中，隐式集合元素中的逻辑树表示形式中，创建的成员。 父类型的构造函数通常是其属性之一的集合执行实例化并最初为空集合成为对象树的一部分。

> 泛型列表和字典接口 ([IList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ilist-1)和[IDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.idictionary-2)) 不支持对于集合检测。 但是，可以使用[List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1)类作为基类，因为它实现[IList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ilist)直接，或[Dictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.dictionary-2)作为基类，因为它实现了[IDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.idictionary)直接。

在集合类型的.NET 参考页，此语法与集合的对象元素有意省略偶尔需要注意的 XAML 语法部分中作为隐式集合语法。

除了根元素中，嵌套另一个元素的子元素作为 XAML 文件中的每个对象元素实际上是一个或两个在以下情况下的元素： 其父元素的隐式集合属性的成员或指定的父元素 (XAML 内容属性将在下一节中讨论) 的 XAML 内容属性的值的元素。 换而言之，父元素和标记页面中的子元素的关系实际上是单个对象根位置，并对根下的每个对象元素都是单个实例提供的父代、 属性值或列中的项之一也是父项的集合类型属性值的 lection。 此单根概念通常是使用 XML，并且还经常进一步巩固 Api，如加载 XAML 行为中[Load](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.xamlreader.load)。

下面的示例是使用集合的对象元素语法 ([GradientStopCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientstopcollection)) 显式指定。

```xaml
<LinearGradientBrush>  
  <LinearGradientBrush.GradientStops>  
    <GradientStopCollection>  
      <GradientStop Offset="0.0" Color="Red" />  
      <GradientStop Offset="1.0" Color="Blue" />  
    </GradientStopCollection>  
  </LinearGradientBrush.GradientStops>  
</LinearGradientBrush>  
```

请注意，它并不总是可以显式声明集合。 例如，尝试声明[TriggerCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.triggercollection)中前面所示显式[Triggers](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style.triggers)示例将失败。显式声明集合需要集合类必须支持默认构造函数，和[TriggerCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.triggercollection)没有默认构造函数。

### XAML 内容属性

XAML 内容语法是一种语法仅启用指定的类上的[ContentPropertyAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.contentpropertyattribute)作为其类声明的一部分。[ContentPropertyAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.contentpropertyattribute)引用该类型的元素 （包括派生的类） 的 content 属性的属性名称。 当 XAML 处理器处理，将分配的任何子元素或找到开始标记和结束标记的对象元素之间的内部文本，该对象的 XAML 内容属性的值。 允许您指定显式属性元素的内容属性，但.NET 参考中的 XAML 语法部分中一般不介绍这种用法。 显式/详细的方法有偶尔值标记起见或作为一种标记样式，但通常内容属性的目的是简化标记，以便可以直接嵌套的直观相关的父-子元素。 作为"内容"每个严格的 XAML 语言定义; 未分配的上一个元素的其他属性的属性元素标记它们以前 XAML 分析器处理顺序进行处理，并且不会考虑为"内容"。

#### 必须是连续的 XAML 内容属性值

XAML 内容属性的值必须在该对象元素完全之前或之后的任何其他属性元素指定。 XAML 内容属性的值指定为字符串，或作为一个或多个对象是否也是如此。 例如，以下标记不会分析：

```
<Button>I am a   
  <Button.Background>Blue</Button.Background>  
  blue button</Button>  
```

这是非法的实质上是因为此语法所做的内容属性使用属性元素语法显式，如果内容的属性将设置两次：

```xml
<Button>  
  <Button.Content>I am a </Button.Content>  
  <Button.Background>Blue</Button.Background>  
  <Button.Content> blue button</Button.Content>  
</Button>  
```

类似的非法示例是如果内容属性是一个集合，并且子元素混杂在一起属性元素：

```xml
<StackPanel>  
  <Button>This example</Button>  
  <StackPanel.Resources>  
    <SolidColorBrush x:Key="BlueBrush" Color="Blue"/>  
  </StackPanel.Resources>  
  <Button>... is illegal XAML</Button>  
</StackPanel>  
```

### 内容属性和集合语法组合

多个单个对象元素作为内容，以便接受内容属性的类型具体而言必须是集合类型。 为集合类型的属性元素语法类似，XAML 处理器必须确定属于集合类型的类型。 如果元素具有 XAML 内容属性，XAML 内容属性的类型是一个集合，然后隐含的集合类型不需要为对象元素标记中指定并不需要指定为属性 el XAML 内容属性ement。 因此在标记中明显的内容模型现在有多个分配作为内容的子元素。 以下是内容语法[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)派生的类。 所有[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)派生的类建立 XAML 内容属性为[Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.children)，这需要类型的值[UIElementCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.uielementcollection)。

```xaml
<Page
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  >
  <StackPanel>
    <Button>Button 1</Button>
    <Button>Button 2</Button>
    <Button>Button 3</Button>
  </StackPanel>
</Page>
```

请注意，对于既不在属性元素[Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.children)也不为元素[UIElementCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.uielementcollection)所需的标记中。 这是 XAML 设计功能，使其以递归方式包含用于定义元素的UI更直观地表示为具有直接父-子元素间的关系，而无需干预属性元素标记嵌套元素树或集合对象。 事实上，[UIElementCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.uielementcollection)不能指定显式标记为对象元素，通过设计。 因为其唯一用途是作为隐式的集合，[UIElementCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.uielementcollection)不公开公共默认构造函数，因此无法实例化作为对象元素。

#### 混合使用属性元素和具有内容的属性的对象中的对象元素

XAML 规范声明用于填充对象元素内的 XAML 内容属性的对象元素必须是连续的并且必须不混合型 XAML 处理器可以强制执行。 通过强制实施此限制针对混合使用属性元素和内容WPFXAML 处理器。

您可以将子对象元素作为对象元素中的第一个即时标记。 然后，可以引入属性元素。 或者，你可以指定一个或多个属性元素的内容，然后更多属性元素。 但是，一旦属性元素内容后面跟，不能引入任何进一步的内容，你可以仅添加属性元素。

此内容 / 属性元素顺序要求并不适用于作为内容的内部文本。 但是，它仍是要保留的内部文本连续的因为有意义的空白将很难直观地检测到的标记中如果混杂内部文本的属性元素的好的标记样式。

### XAML 命名空间

上述语法示例未指定默认 XAML 命名空间之外的 XAML 命名空间。 在典型WPF应用程序，默认 XAML 命名空间指定为WPF命名空间。 您可以指定默认 XAML 命名空间之外的 XAML 命名空间，而且仍使用类似的语法。 但是，然后，任何位置其中一个类名为无法访问默认 XAML 命名空间内，则该类的名称必须在前面加上的 XAML 命名空间前缀映射到相应的 CLR 命名空间。 例如，`<custom:Example/>`是对象元素语法来实例化的实例`Example`类，其中包含此类 （和可能包含后备类型的外部程序集信息） 的 CLR 命名空间之前映射到`custom`前缀。

有关 XAML 命名空间的详细信息，请参阅[XAML 命名空间和 WPF XAML Namespace 映射](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-namespaces-and-namespace-mapping-for-wpf-xaml)。

### 标记扩展

XAML 定义编程实体，使从正常的 XAML 处理器处理的字符串属性值或对象元素，转义符并将推迟到支持类处理标记扩展。 标识 XAML 处理器的标记扩展时使用特性语法是左大括号 （{}） 后, 跟右大括号 （}） 以外的任何字符的字符。 后面的左大括号的第一个字符串必须引用此子字符串是否真正的类名称的一部分提供的特定扩展行为，该引用可能会省略子字符串"Extension"的类。 此后，可能会出现一个空格，而然后每个后续字符用作输入的扩展插件实现中，直至遇到的右大括号。

.NET XAML 实现使用[MarkupExtension](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.markupextension)抽象类为所有支持的标记扩展的基础WPF以及其他框架或技术。 标记扩展的WPF专门实现通常用于提供一种方法，以引用其他现有对象，或使延迟将在运行时计算的对象引用。 例如，通过简单的 WPF 数据绑定指定`{Binding}`标记扩展通常将采用特定属性值的位置。 许多 WPF 标记扩展启用特性语法的其中一种属性语法，否则是不可能的属性。 例如，[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)对象是相对较复杂类型包含一系列嵌套的对象和属性。 通常将在 WPF 中的样式定义中的资源作为[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)，然后通过一个请求资源的两个 WPF 标记扩展引用。 标记扩展将推迟到一种资源查找的属性值的计算，并使提供的价值[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.style)属性，采用类型[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)，在特性语法，如以下示例所示：

```
<Button Style="{StaticResource MyStyle}">My button</Button>
```

在这里，`StaticResource`标识[StaticResourceExtension](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.staticresourceextension)类，用于提供标记扩展实现。 下一个字符串`MyStyle`作为输入用于非默认[StaticResourceExtension](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.staticresourceextension)构造函数中，从扩展的字符串中提取的参数声明请求[ResourceKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcekey)。 `MyStyle` 应为[X:key](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-key-directive)的值[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)定义为资源。 [StaticResource 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/staticresource-markup-extension)用法要求使用的资源，以提供[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)静态资源查找逻辑在加载时通过属性值。

有关标记扩展的详细信息，请参阅[标记扩展和 WPF XAML](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/markup-extensions-and-wpf-xaml)。 有关标记扩展和编程功能在常规的.NET XAML 实现中启用其他 XAML 的参考，请参阅[XAML Namespace （x:）语言功能](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/xaml-namespace-x-language-features)。 有关特定于 WPF 的标记扩展，请参阅[WPF XAML 扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/wpf-xaml-extensions)。

### 附加属性

附加的属性是在 XAML 属性可以拥有和某个特定类型定义，由此引入了一个编程概念但设置为属性或属性元素上的任何元素。 主要方案用于附加的属性是能够向父元素报告信息的标记结构中的子元素而无需在所有元素之间的广泛共享的对象模型。 相反，报表信息传递到子元素的父元素可以使用附加的属性。 有关详细信息的附加的属性以及如何创建你自己的目的附加属性，请参阅[附加属性概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/attached-properties-overview)。

附加的属性使用语法看起来类似于属性元素语法中，您还指定*typeName*。*propertyName*组合。 有两个重要的差异：

- 可以使用*typeName*。*propertyName*甚至设置附加的属性通过特性语法时的组合。 附加的属性是唯一的用例，其中，符合条件的属性名称是在特性语法要求。
- 此外可以附加属性使用属性元素语法。 但是，对于典型的属性元素语法*typeName*指定为包含属性的元素的对象元素。 如果您引用的附加属性，则*typeName*是定义附加的属性不包含的对象元素的类。

### 附加事件

附加的事件也是的 XAML 特定的类型，可以定义事件，但可能在任何对象元素上附加处理程序中引入的另一个编程概念。 在 WOF 实现中，定义附加的事件的类型通常是静态类型，用于定义一种服务，并公开该服务的类型中的路由的事件别名有时公开这些附加的事件。 通过特性语法指定的附加事件处理程序。 使用附加事件附加事件，以允许展开特性语法时*typeName*。*eventName*使用情况，其中*typeName*是类，提供`Add`并`Remove`事件附加的事件基础结构，处理程序的访问器和*eventName*是事件名称。

### XAML 根元素的剖析

下表显示了一个典型 XAML 根元素细分它们，显示根元素的特定属性：

|                                                              |                                                           |
| ------------------------------------------------------------ | --------------------------------------------------------- |
| `<Page`                                                      | 打开根元素的对象元素                                      |
| `xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"` | 默认值 (WPF) XAML 命名空间                                |
| `xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"`     | XAML 语言 XAML 命名空间                                   |
| `x:Class="ExampleNamespace.ExampleCode"`                     | 连接到任何代码隐藏的标记的分部类声明为分部类定义          |
| `>`                                                          | 根对象元素的末尾。 因为该元素包含子元素，不是尚未关闭对象 |



#### 可选的查找 XAML 用法

以下各节介绍 XAML 用法，从技术上讲支持由 XAML 处理器，但的生成详细级别或开发包含 XAML 源的应用程序时剩余的可读的 XAML 文件会干扰其他美观问题。

#### 可选属性元素用法

可选属性元素用法包括显式写出元素内容属性的 XAML 处理器将视为隐式。 例如，当声明的内容[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)，你可以选择显式声明[Items](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.items)系列[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)作为`<Menu.Items>`属性元素标记和位置[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)内`<Menu.Items>`，而不是比使用隐式的 XAML 处理器行为的所有子元素[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)必须是[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)并放入[Items](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.items)集合。 有时可选用法可以帮助直观地阐明对象结构，按标记中的表示形式。 或者，有时显式属性元素用法可以避免从技术上讲功能，但在视觉混乱，例如嵌套的标记扩展的特性值中的标记。

#### 完全限定的类型属性

*TypeName*。*memberName*窗体的属性的实际工作比仅仅使用路由的事件的情况更为普遍。 但在其他情况下该窗体是多余的应避免它，如果只是为了实现标记样式和可读性。 在以下示例中，这三个对引用[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)属性是完全等效：

```xaml
<Button Background="Blue">Background</Button>
<Button Button.Background="Blue">Button.Background</Button>
<Button Control.Background="Blue">Control.Background</Button>
```

`Button.Background` 有效，因为该属性的限定的查找[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)成功 ([Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)从控件继承) 和[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)是对象元素的类或基类。 `Control.Background` 有效，因为[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)类实际上定义了[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)并[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)是[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)基类。

但是，以下*typeName*。*memberName*窗体示例不起作用，因此显示为注释：

```xaml
<!--<Button Label.Background="Blue">Does not work</Button> -->
```

[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label) 作为另一个派生的类的[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)，并且如果已指定`Label.Background`内[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)对象元素，这种用法会起作用。但是，由于[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)不是类或类的基类[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)，然后处理指定的 XAML 处理器行为是`Label.Background`作为附加属性。 `Label.Background` 不是可附加的属性，并将故障这种用法。

### baseTypeName.memberName 属性元素

如何以类似方式*typeName*。*memberName*窗体适用于特性语法*b t y p*。*memberName*语法适用于属性元素语法。例如，以下语法的工作原理：

```xaml
<Button>Control.Background PE
  <Control.Background>
    <LinearGradientBrush StartPoint="0,0" EndPoint="1,1">
      <GradientStop Color="Yellow" Offset="0.0" />
      <GradientStop Color="LimeGreen" Offset="1.0" />
    </LinearGradientBrush>
    </Control.Background>
</Button>
```

在这里，为提供的属性元素`Control.Background`即使属性元素已包含在`Button`。

但是，正如*typeName*。*memberName*属性，用于窗体*b t y p*。*memberName*是在标记中，良好的样式，应避免它。

## [Code-Behind and XAML in WPF](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/code-behind-and-xaml-in-wpf)

代码隐藏是一个术语，用于描述标记定义的对象，与联接的代码时XAML页进行标记编译。 本主题介绍了代码隐藏的要求以及代码中的可选内联代码机制XAML。

本主题包含以下各节：

- [系统必备](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/code-behind-and-xaml-in-wpf#Prerequisites)
- [代码隐藏和 XAML 语言](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/code-behind-and-xaml-in-wpf#codebehind_and_the_xaml_language)
- [代码隐藏、 事件处理程序和 WPF 中的分部类要求](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/code-behind-and-xaml-in-wpf#Code_behind__Event_Handler__and_Partial_Class)
- [x:Code](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/code-behind-and-xaml-in-wpf#x_Code)
- [内联代码的限制](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/code-behind-and-xaml-in-wpf#Inline_Code_Limitations)

### 系统必备

本主题假定你已阅读[XAML 概述 (WPF)](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-overview-wpf)具备的一些基础知识和CLR和面向对象的编程。

### 代码隐藏和 XAML 语言

XAML 语言包含语言级别功能，使得可以将代码文件与标记文件，然后在标记文件端相关联。 具体而言，XAML 语言定义的语言功能[X:class 指令](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-class-directive)， [X:subclass 指令](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-subclass-directive)，并[X:classmodifier 指令](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-classmodifier-directive)。 完全应该如何生成代码，以及如何将集成标记和代码，不是 XAML 语言指定的一部分。 它应由 WPF 来确定如何将代码集成之类的框架、 如何为使用 XAML 在应用程序和编程模型和生成操作或其他支持的所有这些要求。

### 代码隐藏、 事件处理程序和 WPF 中的分部类要求

- 分部类必须派生自支持的根元素的类型。
- 请注意，标记编译生成操作的默认行为下, 您可以将派生留空的分部类定义中的代码隐藏侧。 即使未指定，编译的结果将假定页面根后备类型的分部类的基础。 但是，依赖于此行为不是一种最佳做法。
- 在代码隐藏中编写的事件处理程序的实例方法，并且不能为静态方法。 这些方法必须由标识的 CLR 命名空间中的分部类定义`x:Class`。 您不能有资格的一个事件处理程序，以指示名称XAML处理器，查找事件布线，另一个类作用域中的事件处理程序。
- 该处理程序必须在后备类型系统中匹配相应的事件的委托。
- 对于 Microsoft Visual Basic 语言具体而言，您使用的是特定于语言的`Handles`关键字将处理程序相关联的实例和事件处理程序声明，而不是附加处理程序中的属性中XAML。 但是，此方法也存在一些限制，因为`Handles`关键字不能支持所有的特定功能WPF事件系统，如某些路由事件方案或附加事件。 有关详细信息，请参阅[Visual Basic 和 WPF 事件处理](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/visual-basic-and-wpf-event-handling)。

### x:Code

[X:code](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-code-intrinsic-xaml-type)中定义的指令元素XAML。 `x:Code`指令元素可以包含嵌入式编程代码。 是以内联方式定义的代码可以与交互XAML同一页面上。 下面的示例说明了内联 C# 代码。 请注意，该代码位于`x:Code`元素和代码必须用引起`<CDATA[`...`]]>`用于对内容进行转义XML，以便XAML处理器 (解释任一XAML架构或WPF架构) 不会尝试解释内容按字面意思为XML。

```xaml
<Page
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  x:Class="MyNamespace.MyCanvasCodeInline"
>
  <Button Name="button1" Click="Clicked">Click Me!</Button>
  <x:Code><![CDATA[
    void Clicked(object sender, RoutedEventArgs e)
    {
        button1.Content = "Hello World";
    }
  ]]></x:Code>
</Page>
```

### 内联代码的限制

应考虑避免或限制的内联代码使用。 根据体系结构和编码基本原理，维护分离标记和代码隐藏保留设计器和开发人员角色得更为明显。 在更多技术级别中，为内联代码编写的代码可能难以编写，因为始终写入XAML生成的分部类，并且只能使用默认 XML 命名空间映射。 因为不能添加`using`语句，您必须完全限定的许多API所做的调用。默认值WPF映射包括最而不是全部CLR命名空间中存在的WPF程序集; 必须完全限定的类型和成员中的其他 CLR 命名空间包含对的调用。 您还不能定义分部类以外的项目中的内联代码，并且您引用的所有用户代码实体必须都存在作为成员或生成的分部类中的变量。 其他语言特定编程功能，例如宏或`#ifdef`对全局变量或生成变量，也不是可用。 有关详细信息，请参阅[X:code 内部 XAML 类型](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-code-intrinsic-xaml-type)。

## [XAML and Custom Classes for WPF](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/xaml-and-custom-classes-for-wpf)

公共语言运行时 (CLR) 框架中实现的 XAML 支持定义任何 公共语言运行时 (CLR) 语言的自定义类或结构，然后使用 XAML 标记访问类。 通常通过将自定义类型映射到 XAML 命名空间前缀，可在同一标记文件中混合使用Windows Presentation Foundation (WPF) 定义类型和自定义类型。 本主题讨论将自定义类用作 XAML 元素必须满足的要求。

### 应用程序或程序集中的自定义类

XAML 中使用的自定义类可通过两种不同的方式进行定义：在代码隐藏或其他生成主 Windows Presentation Foundation (WPF) 应用程序的代码内，或者在单独程序集中作为类（例如用作类库的可执行文件或 DLL）。 这些方法各有特定的优点和缺点。

- 创建类库的优点在于可在多个不同的应用程序间共享任意此类自定义类。 通过使用单独的库，更易于控制应用程序的版本控制问题，并可简化类创建过程，在此过程中，所需的类用法是作为 XAML 页面上的根元素。
- 在应用程序中定义自定义类的优点在于此方法相对轻量，可减少在主应用程序可执行文件外引入单独程序集时遇到的部署和测试问题。
- 无论定义在相同还是不同的程序集中，自定义类若要在 XAML 中用作元素，都需要在 CLR 命名空间和 XML 命名空间之间进行映射。 请参阅 [WPF XAML 的 XAML 命名空间和命名空间映射](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-namespaces-and-namespace-mapping-for-wpf-xaml)。

### 将自定义类用作 XAML 元素的要求

为能够实例化为对象元素，类必须满足以下要求：

- 自定义类必须是公共的且支持默认（无参数）公共构造函数。 （有关结构注释，请参阅下节内容。）
- 自定义类不得为嵌套类。 嵌套类及其常规 CLR 使用语法中的“点”会干扰其他 WPF 和/或 XAML 功能（例如附加属性）。

除启用对象元素语法外，对象定义还会对任何其他将该对象作为值类型的公共属性启用属性元素语法。 这是因为对象现在可被实例化为对象元素，且可填充此类属性的属性元素值。

#### 结构

可始终在 WPF 的 XAML 中构造定义为自定义类型的结构。这是因为 CLR 编译器会对将所有属性值初始化为默认值的结构隐式创建默认构造函数。 某些情况下，结构并不需要默认构造行为和/或对象元素用法。 这可能是因为结构需要通过概念方式将值和函数作为联合来填充，其中包含的值可能具有互斥的解释，因而其不存在任何可设置属性。 一个WPF这种结构的示例是[GridLength](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.gridlength)。 通常情况下，此类结构应实现类型转换器，以便可通过属性形式表达值，方法是使用创建结构值的不同解释或模式的字符串约定。 结构还应通过非默认构造函数对代码构造公开类似的行为。

### 将自定义类属性用作 XAML 特性的要求

属性必须引用按值类型（例如基元），或者使用特定类型的一个类（此特定类型需具有默认构造函数或 XAML 处理器可访问的专用类型转换器）。 在 CLR XAML 实现中，XAML 处理器，查找通过语言基元的本机支持或应用程序的此类转换器[TypeConverterAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverterattribute)类型或后备类型定义中的成员

或者，属性可引用抽象类类型或接口。 对于抽象类或接口，XAML 分析的所需条件是必须用实现接口的实际类实例或派生自抽象类的类型实例填充属性值。

属性可在抽象类上声明，但仅可在派生自抽象类的实际类上设置。 这是因为创建类的对象元素需要类上的公共默认构造函数。

#### 启用 TypeConverter 的特性语法

如果提供类级别的专用特性化类型转换器，则应用的类型转换会对需实例化该类型的任何属性启用特性语法。 类型转换器不会启用类型的对象元素用法；仅在该类型存在默认构造函数时启用对象元素用法。 因此，启用类型转换器的属性通常不适用于属性语法，除非类型本身也支持对象元素语法。 此规则存在一个例外，即可指定属性元素语法，但使属性元素包含一个字符串。 实质上相当于特性语法用法，该使用情况，这类使用情况不常见，除非需要进行更可靠的空白处理的属性值。 例如，以下是一个采用字符串的属性元素用法以及一个特性用法等效项：

```xaml
<Button>Hallo!
  <Button.Language>
    de-DE
  </Button.Language>
</Button>
```

```xaml
<Button Language="de-DE">Hallo!</Button>
```

属性允许特性语法，但包含的对象元素的属性元素语法不允许使用通过 XAML 的示例包括的各种属性[Cursor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.cursor)类型。 [Cursor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.cursor)类具有专用的类型转换器[CursorConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.cursorconverter)，但不公开默认构造函数，因此[Cursor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.cursor)属性只能设置通过特性语法即使实际[Cursor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.cursor)类型是引用类型。

#### 按属性类型转换器

或者，属性本身可能声明属性级别的类型转换器。 这样，"最小语言"作为输入处理传入的字符串值的属性通过实例化内联属性类型的对象[ConvertFrom](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter.convertfrom)操作根据适当的类型。 此操作的目的通常是提供方便的访问器，且这不是在 XAML 中启用属性设置的唯一方式。 但是，如果要使用不提供默认构造函数或特性化类型转换器的现有 CLR 类型，也可使用特性的类型转换器。 从示例WPFAPI 将某些属性[CultureInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.globalization.cultureinfo)类型。 在这种情况下，WPF使用现有的 Microsoft.NET Framework[CultureInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.globalization.cultureinfo)类型，以更好地解决兼容性和迁移方案使用在早期版本的框架，但[CultureInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.globalization.cultureinfo)类型不支持所需的构造函数或类型级别的类型转换为直接用作 XAML 属性值。

每当公开具有 XAML 用法的属性时，特别是对于控件作者，应特别考虑使用依赖属性支持此属性。 这是如果您使用现有Windows Presentation Foundation (WPF)实现的 XAML 处理器，因为可以通过使用提高性能[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)备份。 依赖属性将对用户针对 XAML 可访问属性所需的属性公开属性系统功能。 这包括动画、数据绑定和样式支持等功能。 有关详细信息，请参阅[自定义依赖属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/custom-dependency-properties)和 [XAML 加载和依赖属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-loading-and-dependency-properties)。

#### 编写和特性化类型转换器

您偶尔需要编写自定义[TypeConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter)派生的类提供对属性类型的类型转换。 有关如何派生和创建可以支持 XAML 用法的类型转换器以及如何将应用的说明[TypeConverterAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverterattribute)，请参阅[TypeConverters 和 XAML](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/typeconverters-and-xaml)。

### 自定义类事件上 XAML 事件处理程序特性语法的要求

若要用作 CLR 事件，事件必须在支持默认构造函数的类上或在派生类可访问事件的抽象类上公开为公共事件。 以可方便地用作路由事件，你CLR事件应实现显式`add`并`remove`方法，这些添加和删除处理程序方法CLR事件签名并转发到这些处理程序[AddHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.addhandler)和[RemoveHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.removehandler)方法。 这些方法添加或删除事件所附加到的实例上的路由事件处理程序存储的处理程序。

> 可以直接为使用的路由事件注册处理程序[AddHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.addhandler)，并在特意不定义CLR公开路由的事件的事件。 通常不建议采用此操作，因为事件不会启用 XAML 特性语法用于附加处理程序，并且生成类提供的类型功能的 XAML 视图透明度较低。

### 编写集合属性

采用集合类型的属性所具有的 XAML 语法使你可指定添加到集合的对象。 此语法具有两个重要功能。

- 无需在对象元素语法中指定作为集合对象的对象。 无论何时在采用集合类型的 XAML 中指定属性，该集合类型的状态总是隐式。
- 标记中集合属性的子元素经处理后变成集合的成员。 对集合成员的代码访问通常通过列表/字典方法（例如 `Add`）或通过索引器执行。 但 XAML 语法不支持方法和索引器 (异常：XAML 2009 可以支持这些方法，但使用 XAML 2009 会限制可能的 WPF 用法;请参阅[XAML 2009 语言功能](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/xaml-2009-language-features))。 对生成元素树而言，集合显然是非常常见的要求，并且你需要某种方法来填充声明 XAML 中的这些集合。 因此，通过将集合属性的子元素添加到作为集合属性类型值的集合中来对其进行处理。

.NET Framework XAML 服务实现和 WPF XAML 处理器将以下定义用于组成集合属性的项。 属性的属性类型必须实现以下项之一：

- 实现[IList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ilist)。
- 实现[IDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.idictionary)或泛型等效项 ([IDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.idictionary-2))。
- 派生自[Array](https://docs.microsoft.com/zh-cn/dotnet/api/system.array)(有关在 XAML 中数组的详细信息，请参阅[X:array 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-array-markup-extension)。)
- 实现[IAddChild](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.iaddchild)(通过定义的接口WPF)。

CLR 中这些类型每个都具有 `Add` 方法，创建对象图时，XAML 处理器使用该方法将项添加到基础集合。

> 泛型`List`并`Dictionary`接口 ([IList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ilist-1)并[IDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.idictionary-2)) 不支持对于集合检测通过WPFXAML 处理器。 但是，可以使用[List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1)类作为基类，因为它实现[IList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ilist)直接，或[Dictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.dictionary-2)作为基类，因为它实现了[IDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.idictionary)直接。

声明采用集合的属性时，请注意类型的新实例中如何实例化此属性值。 如果不将此属性实现为依赖属性，则使属性使用调用此集合类型构造函数的支持字段已可满足使用需求。 如果属性为依赖属性，则可能需要将集合属性初始化为默认类型构造函数的一部分。 这是因为依赖属性从元数据获取其默认值，而通常不希望集合属性的初始值为静态共享集合。 每个包含类型实例应具有一个集合实例。 有关详细信息，请参阅[自定义依赖属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/custom-dependency-properties)。

可为集合属性实现自定义集合类型。 由于隐式集合属性处理的原因，自定义集合类型无需提供默认构造函数即可隐式用于 XAML 中。 但是，可选择为集合类型提供默认构造函数。 此做法是有用的。 除非提供默认构造函数，否则无法显式将集合声明为对象元素。 一些标记作者可能希望看到作为标记样式的显式集合。 此外，创建将集合类型用作属性值的新对象时，默认构造函数可简化初始化要求。

### 声明 XAML 内容属性

XAML 语言定义 XAML 内容属性的概念。 对象语法中可用的每个类仅可具有一个 XAML 内容属性。 若要将属性声明为 XAML 内容属性为您的类，应用[ContentPropertyAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.contentpropertyattribute)为类定义的一部分。 指定作为目标的 XAML 内容属性的名称[Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.contentpropertyattribute.name)属性中。 指定的属性是作为字符串名称，不与反射构造如[PropertyInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.propertyinfo)。

可将集合属性指定为 XAML 内容属性。 这产生一种属性的用法，通过此用法，对象元素可具有一个或多个子元素，不干扰集合对象元素或属性元素标记。 这些元素被视为 XAML 内容属性的值，并添加到支持集合实例中。

一些现有 XAML 内容属性使用 `Object` 的属性类型。 这使 XAML 内容属性可接受基元值如[String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)和单一引用对象值。 如果按照此模型，类型负责类型确定以及处理可能的类型。 典型的原因[Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object)内容类型是为了支持这两个简单的方法，将对象内容添加为字符串 （接收默认演示文稿处理），或添加的高级的方法对象指定非默认演示文稿的内容或其他数据。

### 序列化 XAML

某些情况下（例如对于控件作者），可能还需要确保任何可在 XAML 中实例化的对象演示文稿也可被序列化到等效的 XAML 标记。 本主题中未介绍序列化要求。 请参阅[控件创作概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/control-authoring-overview)和[元素树和序列化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/element-tree-and-serialization)。

## [Markup Extensions and WPF XAML](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/markup-extensions-and-wpf-xaml)

本主题介绍 XAML 的标记扩展概念，包括其语法规则、用途以及作为其基础的类对象模型。 标记扩展是 XAML 语言以及 XAML 服务的 .NET 实现的常规功能。 本主题专门详细讨论用于 WPF XAML 的标记扩展。



### XAML 处理器和标记扩展

通常，XAML 分析器可将特性值解释为可转换成基元的文本字符串，或可通过某种方法将特性值转换为对象。 其中一种方法是引用类型转换器；详情请参阅主题 [TypeConverters 和 XAML](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/typeconverters-and-xaml)。 不过，也存在要求其他行为的情况。例如，可以指示 XAML 处理器，特性的值不应在对象图中生成新对象。 相反，特性应生成引用对象图另一部分中的已构造对象或引用静态对象的对象图。 另一种情况是，可以指示 XAML 处理器使用向对象的构造函数提供非默认参数的语法。 在这些类型的情况中，标记扩展可以提供解决方案。

### 基本标记扩展语法

可以实现标记扩展来为特性用法中的属性和/或属性元素用法中的属性提供值。

当用于提供特性值时，将标记扩展序列与 XAML 处理器区分开的语法是左右大括号（{ 和 }）。 然后，由紧跟在左大括号后面的字符串标记来标识标记扩展的类型。

当用在属性元素语法中时，标记扩展在外观上与任何其他用于提供属性元素值的元素相同，即：一个将标记扩展类作为元素引用并以尖括号 (<>) 括起的 XAML 元素声明。

### XAML 定义的标记扩展

存在这么几种标记扩展，它们并非特定于 XAML 的 WPF 实现，而是语言形式的 XAML 的内部函数或功能的实现。这些标记扩展在 System.Xaml 程序集中作为常规 .NET Framework XAML 服务的一部分而实现，并且位于 XAML 语言 XAML 命名空间内。 就常见标记用法而言，这些标记扩展通常可由用法中的 `x:` 前缀标识。 [MarkupExtension](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.markupextension)基类 （也在 System.Xaml 中定义） 提供了所有标记扩展应都使用以支持在 XAML 读取器和 XAML 编写器，包括 WPF XAML 中的模式。

- `x:Type` 为命名类型提供 [Type](https://docs.microsoft.com/zh-cn/dotnet/api/system.type) 对象。 此扩展最常用于样式和模板。 有关详细信息，请参阅 [x:Type 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-type-markup-extension)。
- `x:Static` 生成静态值。 这些值来自于值类型代码实体，它们不直接是目标属性值的类型，但可以计算为该类型。 有关详细信息，请参阅 [x:Static 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-static-markup-extension)。
- `x:Null` 将 `null` 指定为属性的值，可用于特性或属性元素值。 有关详细信息，请参阅 [x:Null 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-null-markup-extension)。
- 在特意不使用 WPF 基元素和控件模型提供的集合支持的情况下，`x:Array` 为 XAML 语法中常规数组的创建提供支持。 有关详细信息，请参阅 [x:Array 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-array-markup-extension)。

> `x:` 前缀在 XAML 文件或生成的根元素中用于 XAML 语言内部函数的典型 XAML 命名空间映射。 例如，WPF 应用程序的 Visual Studio 模板启动使用这一个 XAML 文件`x:`映射。 可以在自己的 XAML 命名空间映射中选择不同的前缀标记，但本文档将采用默认的 `x:` 映射，并通过它来标识属于 XAML 语言的 XAML 命名空间已定义部分的那些实体，这与 WPF 默认命名空间或与特定框架不相关的其他 XAML 命名空间相反。

### 特定于 WPF 的标记扩展

WPF 编程中最常用的标记扩展是支持资源引用的标记扩展（`StaticResource` 和 `DynamicResource`），和支持数据绑定的标记扩展 (`Binding`)。

- `StaticResource` 通过替换已定义资源的值来为属性提供值。 `StaticResource` 计算最终在 XAML 加载时进行，并且在运行时没有访问对象图的权限。 有关详细信息，请访问 [StaticResource 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/staticresource-markup-extension)。
- `DynamicResource` 通过将值推迟为对资源的运行时引用来为属性提供值。 动态资源引用强制在每次访问此类资源时都进行新查找，且在运行时有权访问对象图。 为了获取此访问权限，WPF 属性系统中的依赖项属性和计算出的表达式支持 `DynamicResource` 概念。 因此，只能对依赖项属性目标使用 `DynamicResource`。 有关详细信息，请参阅 [DynamicResource 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dynamicresource-markup-extension)。
- `Binding` 使用在运行时应用于父对象的数据上下文来为属性提供数据绑定值。 此标记扩展相对复杂，因为它会启用大量内联语法来指定数据绑定。 有关详细信息，请参阅 [Binding 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/binding-markup-extension)。
- `RelativeSource` 提供源信息[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)，可以定位在运行时对象树中的若干可能关系。 对于在多用途模板中创建的绑定，或在未充分了解周围的对象树的情况下以代码创建的绑定，此标记扩展为其提供专用源。 有关详细信息，请参阅 [RelativeSource 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/relativesource-markupextension)。
- `TemplateBinding` 使控件模板能够使用模板化属性的值，这些属性来自于将使用该模板的类的对象模型定义属性。 换言之，模板定义中的属性可访问仅在应用了模板之后才存在的上下文。 有关详细信息，请参阅 [TemplateBinding 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/templatebinding-markup-extension)。 有关 `TemplateBinding` 的实际使用的详细信息，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。
- `ColorConvertedBitmap` 支持相对高级的映像方案。 有关详细信息，请参阅 [ColorConvertedBitmap 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/colorconvertedbitmap-markup-extension)。
- `ComponentResourceKey` 和 `ThemeDictionary` 支持资源查找的各个方面，特别是支持查找与自定义控件一起打包的资源和主题。 有关详细信息，请参阅 [ComponentResourceKey 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/componentresourcekey-markup-extension)、[ThemeDictionary 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/themedictionary-markup-extension)或[控件创作概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/control-authoring-overview)。

### *Extension 类

对于常规 XAML 语言和特定于 WPF 的标记扩展，通过一个 XAML 处理器的标识的每个标记扩展行为`*Extension`派生的类[MarkupExtension](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.markupextension)，并提供的实现[ProvideValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.staticextension.providevalue)方法。 每个扩展上的此方法都会提供在计算标记扩展时返回的对象。 通常会基于传递给标记扩展的各个字符串标记来计算返回的对象。

例如，[StaticResourceExtension](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.staticresourceextension)类提供实际资源查找的图面实现，以便其[ProvideValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.markupextension.providevalue)实现返回一个字符串，用于该特定实现的输入请求的对象查找资源通过其`x:Key`。 如果使用的是现有标记扩展，则其大部分实现详细信息都无关紧要。

有些标记扩展不使用字符串标记参数。 这是因为它们返回静态值或一致的值，或者因为应返回何值的上下文可通过经 `serviceProvider` 参数传递的服务之一提供。

`*Extension` 命名模式的目的是为了实现方便和一致。 XAML 处理器不必将该类标识为支持标记扩展。 只要基本代码包含 System.Xaml 并使用.NET Framework XAML 服务实现，仅需以被识别为 XAML 标记扩展是从派生[MarkupExtension](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.markupextension)和以支持构造语法。 WPF 定义标记扩展启用类不遵循`*Extension`命名模式，例如[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)。 原因通常是该类支持纯标记扩展支持以外的方案。 情况下[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)，类具有与 XAML 无关的情况下支持运行时访问方法和对象的属性。

#### 初始化文本的扩展类解释

跟在标记扩展名称后且仍在括号内的字符串标记由 XAML 处理器通过以下方式之一进行解释：

- 逗号始终表示各个标记的分隔符。

- 如果各个分隔的标记不包含任何等号，则每个标记都将被视为构造函数参数。 必须按该签名所期望的类型和该签名所期望的适当顺序给出每个构造函数参数。

   备注

  XAML 处理器必须调用与对的数量这一参数计数匹配的构造函数。 出于此原因，如果要实现自定义标记扩展，不提供多个构造函数具有相同数量的参数。 如果多个标记扩展构造函数路径具有相同的参数计数，则不会定义 XAML 处理器的行为方式，但应预计到如果这种情况存在于标记扩展类型定义中，则会允许 XAML 处理器引发有关使用情况的异常。

- 如果各个分隔的标记包含等号，则 XAML 处理器会首先为标记扩展调用默认构造函数。 之后，每个“名称=值”对会解释为标记扩展上存在的属性名称以及赋给该属性的值。

- 如果标记扩展中的构造函数行为与属性设置行为之间存在并行结果，则使用哪个行为都无关紧要。 较常见的用法是将“属性`=`值”对用于具有多个可设置属性的标记扩展，因为这可使标记意图性更强，并减少意外转置构造函数参数的可能性。 （当指定“属性=值”对时，这些属性可以按任意顺序排列。）另外，无法保证标记扩展提供设置其每个可设置属性的构造函数参数。 例如，[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)是标记扩展，具有许多可通过扩展以设置的属性*属性*`=`*值*窗体，但[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)仅支持两个构造函数： 默认构造函数和一个设置初始路径。

- 文本逗号在未转义的情况下无法传递给标记扩展。



### 转义序列和标记扩展

XAML 处理器中的特性处理使用大括号作为标记扩展序列的指示符。 必要时，也可以使用后跟文本大括号的空大括号对输入转义序列，来生成文本大括号字符特性值。 请参阅[{}转义序列-标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/escape-sequence-markup-extension)。

### XAML 中的嵌套标记扩展用法

支持多个标记扩展的嵌套，并且将首先计算每个标记扩展的最里层。 例如，考虑下面的用法：

```
<Setter Property="Background"  
  Value="{DynamicResource {x:Static SystemColors.ControlBrushKey}}" />  
```

在此用法中，将首先计算 `x:Static` 语句并返回字符串。 该字符串随后用作 `DynamicResource` 的参数。

### 标记扩展和属性元素语法

当用作填写属性元素值的对象元素时，标记扩展类在外观上与可用在 XAML 中的基于典型类型的对象元素没有区别。 典型对象元素与标记扩展之间的实际差异是，标记扩展要么计算为类型化值，要么延迟为表达式。 因此，标记扩展的属性值的任何可能类型错误的机制都将是不同的，这与在其他编程模型中处理后期绑定属性的方式类似。普通对象元素将针对分析 XAML 时它设置的目标属性进行类型匹配计算。

当用在对象元素语法中以填充属性元素时，大多数标记扩展都不会包含任何内容或深层属性元素语法。 这样你便可以关闭对象元素标记，而不提供任何子元素。 不论何时 XAML 处理器遇到任何对象元素，都会调用该类的构造函数来实例化从已分析元素创建的对象。 标记扩展类也一样：如果希望标记扩展可在对象元素语法中使用，就必须提供默认构造函数。 有些现有标记扩展具有至少一个必需的属性值，必须指定该属性值才能使实例化生效。 如果是这样，该属性值通常会作为对象元素上的属性特性而给出。 在[XAML Namespace （x:）语言功能](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/xaml-namespace-x-language-features)并[WPF XAML 扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/wpf-xaml-extensions)参考页中，将显示具有所需的属性 （和所需属性的名称） 的扩展的标记。 参考页还将指出特定标记扩展是否禁止使用对象元素语法或特性语法。 需要注意 [x:Array 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-array-markup-extension)，它无法支持特性语法，因为该数组的内容必须在标记内作为内容指定。 数组内容的处理方式与常规对象一样，因此特性可以没有默认的类型转换器。 此外，[x:Array 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-array-markup-extension)需要 `type` 参数。

## [XAML Namespaces and Namespace Mapping for WPF XAML](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/xaml-namespaces-and-namespace-mapping-for-wpf-xaml)

本主题进一步解释通常在 WPF XAML 文件的根标记中出现的两个 XAML 命名空间映射的存在性和用途。 此外，还介绍如何生成相似映射以使用代码中和/或单独程序集内定义的元素。

### 什么是 XAML 命名空间？

XAML 命名空间实际上是 XML 命名空间概念的扩展。 指定 XAML 命名空间的方法依赖于 XML 命名空间语法、将 URI 用作命名空间标识符以及使用前缀提供从相同标记源引用多个命名空间等约定。 XML 命名空间的 XAML 定义增添的主要概念是，XAML 命名空间表示标记用法唯一性范围，还影响标记实体可如何受特定 CLR 命名空间和引用程序集支持。 后者也会受 XAML 架构上下文概念影响。 但是出于 WPF 如何处理 XAML 命名空间的目的，对于默认 XAML 命名空间、XAML 语言命名空间以及任何其他由 XAML 标记直接映射到特定支持 CLR 命名空间和引用程序集的 XAML 命名空间，可通常考虑为 XAML 命名空间。

### WPF 和 XAML 命名空间声明

在许多 XAML 文件的根标记中的命名空间声明内，通常可看到两个 XML 命名空间声明。 第一个声明默认映射整个 WPF 客户端/框架 XAML 命名空间：

```
xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
```

第二个声明映射单独的 XAML 命名空间，（通常）将其映射到 `x:` 前缀。

```
xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
```

这些声明之间的关系是 `x:` 前缀映射支持 XAML 语言定义中的内部函数，并且 WPF 是将 XAML 用作语言并为 XAML 定义对象词汇的一种实现。 因为 WPF 词汇用法远比 XAML 内部函数用法常见，因此默认映射 WPF 词汇。

此 SDK 内，映射 XAML 语言内部函数支持的 `x:` 前缀约定后跟项目模板、示例代码和语言功能文档。 XAML 命名空间定义许多常用功能，即使对于基本 WPF 应用程序而言，这些功能也是必需的。 例如，若要通过分部类将任何代码隐藏加入到 XAML 文件，必须将该类命名为相关 XAML 文件根元素中的 `x:Class` 属性。 或者，XAML 页面中定义的任何要作为键控资源访问的元素都应在当前元素上设置 `x:Key` 属性。 有关 XAML 的这些方面和其他方面的详细信息，请参阅 [XAML 概述 (WPF)](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-overview-wpf) 或 [XAML 语法详述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-syntax-in-detail)。

### 映射到自定义类和程序集

在 `xmlns` 前缀声明内使用一系列标记可将 XML 命名空间映射到程序集，方法类似于将标准 WPF 和 XAML 内部函数 XAML 命名空间映射到前缀。

此语法采用以下可能的已命名标记和以下值：

`clr-namespace:` 在程序集中声明的 CLR 命名空间，此程序集包含要作为元素公开的公共类型。

`assembly=` 包含部分或全部引用 CLR 命名空间的程序集。 此值通常为程序集的名称而不是路径，且不包含扩展名（例如 .dll 或 .exe）。 程序集路径必须创建为包含要映射的 XAML 的项目文件中的项目引用。 版本控制和强名称签名，`assembly`值可以是字符串由定义[AssemblyName](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.assemblyname)，而不是简单的字符串名称。

请注意，分隔 `clr-namespace` 标记和其值的字符是冒号 (:)，而分隔 `assembly` 标记和其值的字符为等号 (=)。 这两个标记之间应使用的字符是分号。 此外，不包括任何空白区域任何位置的声明中。

#### 基本自定义映射示例

如下代码定义一个示例自定义类：

```csharp
namespace SDKSample {  
    public class ExampleClass : ContentControl {  
        public ExampleClass() {  
        ...  
        }  
    }  
}  
```

此自定义类随后编译到库，库按项目设置（未显示）命名为 `SDKSampleLibrary`。

为引用此自定义类，还需将其添加为当前项目的引用（通常可使用 Visual Studio 中的解决方案资源管理器 UI 完成此操作）。

具有包含类的库并在项目设置中对其进行引用后，可将如下前缀映射到 XAML 中的根元素中：

```
xmlns:custom="clr-namespace:SDKSample;assembly=SDKSampleLibrary"
```

综合而言，以下为根标记中包含自定义映射、典型默认值和 x: 映射的 XAML，然后使用前缀引用实例化此 UI 中的 `ExampleClass`：

```xaml
<Page x:Class="WPFApplication1.MainPage"  
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"   
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"  
    xmlns:custom="clr-namespace:SDKSample;assembly=SDKSampleLibrary">  
  ...  
  <custom:ExampleClass/>  
...  
</Page>  
```

### 映射到当前程序集

如果要在与引用自定义类的应用程序代码相同的程序集内定义引用的 `clr-namespace`，则可省略 `assembly`。 或者，这种情况的等效语法是指定 `assembly=` 且等号后不含任何字符串标记。

如果在同一程序集中定义，则自定义类无法用作页面的根元素。 分部类无需映射；仅需映射应用程序中不是页面分部类的类（若要将其引用为 XAML 中的元素）。

### 将 CLR 命名空间映射到程序集中的 XML 命名空间

WPF 定义 XAML 处理器使用的 CLR 属性，以便将多个 CLR 命名空间映射到单个 XAML 命名空间。 此属性， [XmlnsDefinitionAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.xmlnsdefinitionattribute)，放置在生成程序集的源代码中的程序集级别。 WPF 程序集源代码使用此属性以映射不同的公共命名空间，如[System.Windows](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows)并[System.Windows.Controls](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls)到http://schemas.microsoft.com/winfx/2006/xaml/presentation命名空间。

[XmlnsDefinitionAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.xmlnsdefinitionattribute)采用两个参数： XML/XAML 命名空间名称和 CLR 命名空间名称。 多个[XmlnsDefinitionAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.xmlnsdefinitionattribute)可以存在多个 CLR 命名空间映射到同一个 XML 命名空间。 映射后，通过在分部类代码隐藏页中提供相应 `using` 语句，可在无完全限定的情况下引用这些命名空间的成员（如果需要）。 有关更多详细信息，请参阅 [XmlnsDefinitionAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.xmlnsdefinitionattribute)。

### 设计器命名空间和 XAML 模板中的其他前缀

如果使用 WPF XAML 的开发环境和/或设计工具，你可能会注意到 XAML 标记内存在其他定义的 XAML 命名空间/前缀。

适用于 Visual Studio 的 WPF 设计器 使用通常映射到前缀 `d:` 的设计器命名空间。 WPF 的较新项目模板可能会预映射此 XAML 命名空间，以支持 适用于 Visual Studio 的 WPF 设计器 和其他设计环境之间的交换。 此设计 XAML 命名空间用于在设计器中往返基于 XAML 的 UI 时保持设计状态。 它也用于 `d:IsDataSource`（在设计器中启用运行时数据源）等功能。

可能看到的另一个映射前缀是 `mc:`。 `mc:` 用于标记兼容，使用一种并不一定特定于 XAML 的标记兼容模式。 某种程度上，标记兼容功能可用于在框架之间或跨后备实现的其他边界交换 XAML、在 XAML 架构上下文之间运行、为设计器中限制模式提供兼容性等。 标记兼容概念和如何与 WPF 的关系的详细信息，请参阅[标记兼容 (mc:)语言功能](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/markup-compatibility-mc-language-features)。

### WPF 和程序集加载

WPF 的 XAML 架构上下文与 WPF 应用程序模型，后者又使用的 CLR 定义概念[AppDomain](https://docs.microsoft.com/zh-cn/dotnet/api/system.appdomain)。 以下序列描述 XAML 架构上下文如何解释如何加载程序集或查找类型在运行的时或设计时，根据 WPF 使用的[AppDomain](https://docs.microsoft.com/zh-cn/dotnet/api/system.appdomain)和其他因素。

1. 循环访问[AppDomain](https://docs.microsoft.com/zh-cn/dotnet/api/system.appdomain)，寻找匹配名称的所有方面的已加载程序集，从最近加载的程序集。
2. 如果名称限定，调用[Assembly.Load(String)](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.assembly.load#System_Reflection_Assembly_Load_System_String_)限定名称。
3. 如果限定名称的短名称和公钥标记匹配从中加载标记的程序集，则返回此程序集。
4. 使用短名称和公钥标记调用[Assembly.Load(String)](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.assembly.load#System_Reflection_Assembly_Load_System_String_)。
5. 如果非限定名称，调用[Assembly.LoadWithPartialName](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.assembly.loadwithpartialname)。

宽松型 XAML 不使用步骤 3；不存在从中加载标记的程序集。

Wpf （通过 XamlBuildTask 生成） 的已编译的 XAML 不使用已加载程序集从[AppDomain](https://docs.microsoft.com/zh-cn/dotnet/api/system.appdomain)(步骤 1)。 此外，名称应不会从 XamlBuildTask 输出进行限定，因此步骤 5 不适用。

虽然 BAML 也不应包含非限定程序集名称，但是已编译 BAML（通过 PresentationBuildTask 生成）会使用所有步骤。

## [WPF XAML Namescopes](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/wpf-xaml-namescopes)

XAML 名称范围是关于标识 XAML 中定义的对象的一个概念。 XAML 名称范围中的名称可用于在对象树的对象 XAML 定义名称和其实例等效项之间建立关系。 通常，在加载 XAML 应用程序的各个 XAML 页面根时会以 WPF 托管代码创建 XAML 名称范围。 由定义作为编程对象的 XAML 名称范围[INameScope](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.inamescope)接口，并由实际类还实现[NameScope](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.namescope)。

### 加载的 XAML 应用程序中的名称范围

从更广泛的编程或计算机科学来说，编程概念通常包括可用于访问对象的唯一标识符或名称的原则。 对于使用标识符或名称的系统，名称范围会定义边界，在该边界中，进程或技术会搜索是否请求了具有该名称的对象或者是否执行了标识名称唯一性。 这些一般原则适用于 XAML 名称范围。 在 WPF 中，当 XAML 页面加载时，会在该页面的根元素上创建 XAML 名称范围。 在 XAML 页面的页面根位置处指定的每个名称会添加到相关的 XAML 名称范围中。

在 WPF XAML，是常见的根元素的元素 (如[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)，和[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)) 始终控制 XAML 名称范围。 如果一个元素，如[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)或[FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement)是在标记中，页面的根元素XAML处理器添加[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)隐式根以便[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)可以提供工作 XAML 名称范围。

> 即使在 XAML 标记中的任何元素上都没有定义 `Name` 或 `x:Name` 特性，WPF 生成操作也将为 XAML 生产创建 XAML 名称范围。

如果尝试在任何 XAML 名称范围中两次使用相同的名称，将引发异常。 对于具有代码隐藏且作为已编译应用程序的一部分的 WPF XAML，在初始标记编译期间为页面创建生成类时，WPF 生成操作在生成时会引发异常。 对于不由任何生成操作进行标记编译的 XAML，加载 XAML 时可能会引发与 XAML 名称范围问题相关的异常。 XAML 设计器在设计时也可能会出现 XAML 名称范围问题。

#### 将对象添加到运行时对象树

分析 XAML 时即意味着创建并定义 WPF XAML 名称范围的时刻。 如果在分析生成对象树的 XAML 之后的时间点将对象添加到对象树，新对象上的 `Name` 或 `x:Name` 值不会在 XAML 名称范围中自动更新信息。 若要将一个对象的名称添加到 WPF XAML 名称范围，加载 XAML 后，必须调用的相应实现[RegisterName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.inamescope.registername)上定义的 XAML 名称范围的对象，通常是 XAML 页面根。 如果未注册名称，添加的对象不能按名称引用通过方法如[FindName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.findname)，也不能使用该名称用于动画定位。

应用程序开发人员的最常见方案是，将使用[RegisterName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.registername)名称注册到当前页的根上的 XAML 名称范围。[RegisterName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.registername) 是的情节提要的一个重要用途一部分动画的目标对象。 有关详细信息，请参阅[情节提要概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/storyboards-overview)。

如果您调用[RegisterName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.registername)上定义的 XAML 名称范围的对象以外的对象，该名称仍会注册到中，保留调用对象的 XAML 名称范围就像已调用[RegisterName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.registername)上定义对象的 XAML 名称范围。

#### 代码中的 XAML 名称范围

可以通过代码创建然后使用 XAML 名称范围。 创建 XAML 名称范围所涉及的 API 和概念甚至与使用纯代码相同，因为 WPF 的 XAML 处理器在自身处理 XAML 时就会使用这些 API 和概念。 这些概念和 API 存在的主要目的是为了能够在对象树中按名称查找对象（此对象树通常在 XAML 中完全或部分定义）。

有关以编程方式创建的应用程序而不是从已加载的 XAML，定义 XAML 名称范围的对象必须实现[INameScope](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.inamescope)，或者是[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)或[FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement)派生类，以便在支持的 XAML 名称范围创建其实例。

此外，对于任何不由 XAML 处理器加载和处理的元素，默认情况下不会创建或初始化对象的 XAML 名称范围。 必须为随后要将名称注册到其中的任何对象显式创建新的 XAML 名称范围。 若要创建 XAML 名称范围，则可以调用静态[SetNameScope](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.namescope.setnamescope)方法。 指定的对象，将拥有其作为`dependencyObject`参数，和一个新[NameScope](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.namescope.-ctor)构造函数的调用`value`参数。

如果该对象提供作为`dependencyObject`有关[SetNameScope](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.namescope.setnamescope)不是[INameScope](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.inamescope)实现中，[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)或[FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement)，则调用[RegisterName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.registername)对任何子元素不会产生影响。 如果您不能显式创建新的 XAML 名称范围，然后调用[RegisterName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.registername)将引发异常。

有关以代码方式使用 XAML 名称范围 API 的示例，请参阅[定义名称范围](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-define-a-name-scope)。

### 样式和模板中的 XAML 名称范围

通过 WPF 中的样式和模板，可以直接重复使用和重复应用内容。 但是，样式和模板可能还包含具有模板级别定义的 XAML 名称的元素。 此相同模板可在一个页面中多次使用。 出于此原因，样式和模板皆定义其自身的 XAML 名称范围，与在应用样式或模板的对象树中的位置无关。

请看下面的示例：

```xaml
<Page
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  >
  <Page.Resources>
    <ControlTemplate x:Key="MyButtonTemplate" TargetType="{x:Type Button}">
      <Border BorderBrush="Red" Name="TheBorder" BorderThickness="2">
        <ContentPresenter/>
      </Border>      
    </ControlTemplate>
  </Page.Resources>
  <StackPanel>
    <Button Template="{StaticResource MyButtonTemplate}">My first button</Button>
    <Button Template="{StaticResource MyButtonTemplate}">My second button</Button>
  </StackPanel>
</Page>
```

此处，同一模板应用到两个不同的按钮。 如果模板不具有离散的 XAML 名称范围，则模板中使用的 `TheBorder` 名称会导致 XAML 名称范围中的名称冲突。 模板的每个实例都具有其自己的 XAML 名称范围，因此在本例中，每个实例化模板的 XAML 名称范围仅包含一个名称。

样式也定义其自身的 XAML 名称范围，因此情节提要的各部分均可分配有特定的名称。 即使在控件自定义过程中重新定义模板，这些名称也可实现控件特定行为，定位具有该名称的元素。

由于这些分开的 XAML 名称范围，在模板中查找命名元素比在页面中查找非模板命名元素难度更大。 首先需要确定所应用的模板，通过获取[Template](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.template)应用模板的控件属性值。 然后，调用的模板版本的[FindName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworktemplate.findname)，将控件传递的第二个参数应用了模板。

如果你是控件作者且要生成其中特定名称的应用的模板中的元素是一种行为，由控件本身定义的目标的约定，则可以使用[GetTemplateChild](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.gettemplatechild)从您的控件实现代码的方法。 [GetTemplateChild](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.gettemplatechild)保护方法，因此只有控件作者有权访问它。

如果你正在从模板中，并需要获取应用模板的 XAML 名称范围内，获取的值[TemplatedParent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.templatedparent)，然后调用[FindName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.findname)存在。 从模板内入手的一个示例是编写事件将从已应用模板中的元素引发的事件处理程序实现。

### XAML 名称范围和与名称相关的 API

[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement) 具有[FindName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.findname)，[RegisterName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.registername)和[UnregisterName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.unregistername)方法。 如果在其上调用这些方法的对象拥有 XAML 名称范围，则这些方法会调入相关 XAML 名称范围的方法。 否则，将检查父元素以查看其是否拥有 XAML 名称范围，此过程以递归方式持续发生，直到找到 XAML 名称范围（由于 XAML 处理器行为，根处必定存在一个 XAML 名称范围）。 [FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement) 具有类似行为，出现异常，没有[FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement)会拥有 XAML 名称范围。 这些方法存在上[FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement)，以便可以为最终转发调用[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)父元素。

[SetNameScope](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.namescope.setnamescope) 用于将新的 XAML 名称范围映射到现有对象。 您可以调用[SetNameScope](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.namescope.setnamescope)不止一次来重置或清除 XAML 名称范围，但这不是常见的用法。 此外，[GetNameScope](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.namescope.getnamescope)通常不使用代码中。

#### XAML 名称范围实现

以下类实现[INameScope](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.inamescope)直接：

- [NameScope](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.namescope)
- [Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)
- [ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)
- [FrameworkTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworktemplate)

[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary) 不使用 XAML 名称范围;因为它是一种字典实现，它而是使用密钥。 唯一原因[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)实现[INameScope](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.inamescope)是引发异常对用户代码，可帮助阐明，则返回 true 的 XAML 名称范围之间的区别以及如何[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)处理键，并还确保 XAML 名称范围不应用于[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)由父元素。

[FrameworkTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworktemplate) 并[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)实现[INameScope](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.inamescope)通过显式接口定义。 显式实现可使这些 XAML 名称范围，当通过访问按约定发生行为[INameScope](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.inamescope)接口，这是如何传达 XAML 名称范围通过WPF内部进程。 显式接口定义不属于的传统 API 图面，但是[FrameworkTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworktemplate)并[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)，因为很少需要调用[INameScope](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.inamescope)上的方法[FrameworkTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworktemplate)和[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)直接，并改为使用其他 API如[GetTemplateChild](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.gettemplatechild)。

以下类定义其自己的 XAML 名称范围，通过使用[System.Windows.NameScope](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.namescope)帮助器类，并连接到通过其 XAML 名称范围实现[NameScope.NameScope](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.namescope.namescope)附加属性：

- [FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)
- [FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement)

## [Inline Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/inline-styles-and-templates)

Windows Presentation Foundation (WPF) 提供了[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)对象和模板对象 ([FrameworkTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworktemplate)子类) 作为一种方式在资源中定义的元素的可视外观，以便它们可以使用多次。 出于此原因中的属性XAML采用类型[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)和[FrameworkTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworktemplate)几乎总是进行对现有样式和模板的资源引用而不是内联定义新的。

### 内联样式和模板的限制

在可扩展应用程序标记语言 (XAML)，可以从技术上讲中两种方式之一设置样式和模板属性。 您可以使用特性语法引用已在其中定义资源，例如样式`<`*对象*`Style="{StaticResource`*myResourceKey*`}" .../>`。 或者，可以使用属性元素语法来定义内联样式，例如：

```
<` *object* `>
<` *object* `.Style>
<` `Style` `.../>
</` *object* `.Style>
</` *object* `>
```

特性用法是更常见。 是以内联方式定义和未定义中资源的样式的一定范围限定为包含元素，且无法重新使用一样轻松因为它不有任何资源键。 一般情况下为资源定义的样式是更多情形且有用的并更符合一般原则是Windows Presentation Foundation (WPF)编程模型将在代码中的程序逻辑分离从标记中的设计原则。

通常没有理由以设置内联样式或模板，即使只想要在该位置中使用该样式或模板。 可以采用的样式或模板的大多数元素还支持内容的属性和内容模型。 如果您仅使用任何逻辑树一次通过样式或模板创建，会更容易，只需直接标记中的等效子元素填充该内容属性。 这会完全跳过的样式和模板机制。

其他情况下，返回的对象标记扩展启用的语法也可使用的样式和模板。 有可能的方案的两个此类扩展包括[TemplateBinding](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/templatebinding-markup-extension)和[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)。

## [TypeConverters and XAML](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/typeconverters-and-xaml)

本主题介绍将从字符串进行的类型转换作为常规 XAML 语言功能的用途。 在.NET Framework 中，[TypeConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter)类作为某种特定用途可以用作 XAML 特性用法中的属性值的托管自定义类的实现的一部分。 如果您编写的自定义类，并且你希望类用作 XAML 可设置属性值的实例，您可能需要应用[TypeConverterAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverterattribute)到类，编写自定义[TypeConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter)类，或两者。

### 类型转换概念

#### XAML 和字符串值

在 XAML 文件中设置特性值时，该值的初始类型是纯文本形式的字符串。 如甚至其他基元[Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double)最初是为 XAML 处理器的文本字符串。

XAML 处理器需要两条信息来处理特性值。 第一条信息是所设置的属性的值类型。 定义特性值以及在 XAML 中进行处理的任何字符串都必须最终转换或解析为该类型的值。 如果值是 XAML 分析器可理解的基元（如数值），则会尝试直接转换字符串。 如果值是枚举，则字符串用于检查是否存在与该枚举中的命名常量匹配的名称。 如果值既不是分析器可理解的基元，也不是枚举，则所讨论的类型必须能够基于转换后的字符串提供类型的实例或值。可通过指示类型转换器类达到此目的。 类型转换器实际上是提供其他类的值的帮助器类，可用于的 XAML 方案和 .NET 代码中的代码调用。

#### 在 XAML 中使用现有的类型转换行为

你可能已经在基础应用程序 XAML 中使用了类型转换行为，只是你还不知道，具体取决于你对基础 XAML 概念的熟悉程度。 例如，WPF 定义成百上千个采用类型的值的属性[Point](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.point)。 一个[Point](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.point)是描述二维坐标空间中中的坐标的值，它实际上只是具有两个重要属性：[X](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.point.x)和[Y](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.point.y)。 如果在 XAML 中指定一个点，将其指定为分隔符 （通常为逗号） 的字符串之间[X](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.point.x)和[Y](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.point.y)你提供的值。 例如：`<LinearGradientBrush StartPoint="0,0" EndPoint="1,1">`。

即使这种简单的[Point](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.point)，而其简单的用法在 XAML 中涉及的类型转换器。 在这种情况下，这是类[PointConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.pointconverter)。

类型转换器[Point](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.point)采用的所有属性的标记用法定义在类级别简化[Point](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.point)。 如果没有类型转换器，那么对于前面显示的同一示例，将需要更冗长的标记，如下所示：

```
<LinearGradientBrush>
<LinearGradientBrush.StartPoint>
<Point X="0" Y="0"/>
</LinearGradientBrush.StartPoint>
<LinearGradientBrush.EndPoint>
<Point X="1" Y="1"/>
</LinearGradientBrush.EndPoint>
<LinearGradientBrush>
```

使用类型转换字符串或使用更复杂的等效语法通常是编码风格的选择。 XAML 工具工作流也可能会影响值的设置方式。 某些 XAML 工具可能会生成最复杂的标记窗体，以便更容易往返于设计器视图或其自身的序列化机制。

现有的类型转换器可以通常会发现 WPF 和.NET Framework 类型通过检查类 （或属性） 的应用是否存在[TypeConverterAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverterattribute)。 此属性将对支持类型转换器转换类型的值的类进行命名，用于 XAML 或其他可能的用途。

#### 类型转换器和标记扩展

标记扩展和类型转换器根据 XAML 处理器行为及其应用场景来实现正交角色。 尽管上下文可用于标记扩展用途，但通常不会在标记扩展实现中检查属性的类型转换行为（其中标记扩展提供了一个值）。 换言之，即使标记扩展返回一个文本字符串作为其 `ProvideValue` 输出，该字符串上应用于特定属性或属性值类型的类型转换行为也不会被调用。通常，标记扩展的目的是在不调用任何类型转换器的情况下，处理字符串和返回对象。

需要标记扩展而不是类型转换器的一种常见情况是使对已存在的对象进行引用。 无状态类型转换器最多只能生成新实例，这可能并不理想。 若要深入了解标记扩展，请参阅[标记扩展和 WPF XAML](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/markup-extensions-and-wpf-xaml)。

#### 本机类型转换器

在 XAML 分析器的 WPF 和 .NET XAML 实现中，某些特定类型具有本机类型转换处理，但在传统上可能不会将这些类型视为基元。 这种类型的一个示例是 [DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)。 这样做的原因基于.NET Framework 体系结构的工作原理： 类型[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)在 mscorlib，在.NET 中最基本的库中定义。 [DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime) 不允许使用来自引入依赖关系的另一个程序集的属性特性 ([TypeConverterAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverterattribute)来自系统) 因此不能支持通过特性的正常类型转换器发现机制。 相反，XAML 分析器具有需要此类本机处理的类型的列表，它可通过与真正基元的处理方式类似的方式来处理这些类型。(的情况下[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)这涉及调用[Parse](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime.parse)。)

### 实现类型转换器

#### TypeConverter

在中[Point](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.point)以前，给定类的示例[PointConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.pointconverter)提到过。 适用于 XAML 的.NET 实现，用于 XAML 目的的所有类型转换器都是从基类派生的类[TypeConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter)。 [TypeConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter)类存在于版本的.NET Framework 出现之前的 XAML 中; 其原始用法之一是提供可视化设计器中的属性对话框的字符串转换。 为 XAML 的角色[TypeConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter)扩展以包含要启用分析字符串特性值，并可能返回到一个字符串处理特定对象属性的运行时间值的字符串到和从字符串转换类的基类为属性的序列化。

[TypeConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter) 定义了四个成员与相关的转换以及从 XAML 处理用途的字符串转换为：

- [CanConvertTo](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter.canconvertto)
- [CanConvertFrom](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter.canconvertfrom)
- [ConvertTo](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter.convertto)
- [ConvertFrom](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter.convertfrom)

其中，最重要的方法是[ConvertFrom](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter.convertfrom)。 此方法将输入字符串转换为所需的对象类型。 严格地说，[ConvertFrom](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter.convertfrom)方法可以实现更广泛的类型转换为转换器的预期的目标类型，并因此有超出 XAML，如支持运行时的转换，但出于 XAML 目的的用途这是可以处理的代码路径[String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)很重要的输入。

下一步最重要的方法是[ConvertTo](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter.convertto)。 如果应用程序转换为标记表示形式 （例如，如果它已保存到 XAML 作为一个文件），[ConvertTo](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter.convertto)负责生成标记表示形式。 在这种情况下，对 XAML 很重要的代码路径是传递`destinationType`的[String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)。

[CanConvertTo](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter.canconvertto) 和 [CanConvertFrom](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter.canconvertfrom) 是在服务查询 [TypeConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter) 实现的功能时使用的支持方法。 必须实现这些方法以便为转换器的等效转换方法支持的特定于类型的情况返回 `true` 。 对于 XAML 用途，这通常意味着 [String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string) 类型。

#### XAML 的区域性信息和类型转换器

每个[TypeConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter)实现可以有其自己的什么构成有效的字符串转换，解释，还可以使用或忽略作为参数传递的类型说明。 对于区域性和 XAML 类型转换，有一个重要的注意事项。 XAML 完全支持使用可本地化的字符串作为特性值。 但不支持将该可本地化字符串用作具有特定区域性要求的类型转换器输入，因为 XAML 特性值的类型转换器包含一个必要的固定语言分析行为，该行为使用 `en-US` 区域性。 有关此限制的设计原因的更多信息，请查阅 XAML 语言规范 ([[MS-XAML\]](https://go.microsoft.com/fwlink/?LinkId=114525))。

区域性可能会产生问题的示例之一是，某些区域性使用逗号作为数字的小数点分隔符。 这将与许多 WPF XAML 类型转换器所具有的使用逗号作为分隔符的行为发生冲突（根据常用的 X,Y 形式等过去的先例，或逗号分隔的列表）。 即使在周围的 XAML 中传递区域性（将 `Language` 或 `xml:lang` 设置为 `sl-SI` 区域性，以此方式使用逗号作为小数点的区域性的一个示例）也不能解决此问题。

#### 实现 ConvertFrom

若要能够用作支持 XAML 的 [TypeConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter) 实现，该转换器的 [ConvertFrom](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter.convertfrom) 方法必须接受字符串作为 `value` 参数。 如果字符串的有效格式，并可以通过转换[TypeConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter)实现中，则返回的对象必须支持强制转换为属性预期的类型。 否则， [ConvertFrom](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter.convertfrom) 实现必须返回 `null`。

每个[TypeConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter)实现可以具有其自己的什么构成有效的字符串转换，解释，还可以使用或忽略作为参数传递的类型说明或区域性上下文。 但是，WPF XAML 处理可能不会在所有情况下都将值传递给类型说明上下文，还可能不会基于 `xml:lang` 传递区域性。

> 请勿使用大括号字符（尤其是 {）作为字符串格式的可能元素。 这些字符保留作为标记扩展序列的入口和出口。

#### 实现 ConvertTo

[ConvertTo](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter.convertto) 可能用于序列化支持。 通过 [ConvertTo](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter.convertto) 为自定义类型及其类型转换器实现的序列化支持不是绝对要求。 但是，如果要实现控件，或使用序列化作为类的功能或设计的一部分，则应实现 [ConvertTo](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter.convertto)。

若要能够用作[TypeConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter)支持 XAML，实现[ConvertTo](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter.convertto)该转换器的方法必须接受的类型 （或值），它支持实例作为`value`参数。 当`destinationType`参数的类型为[String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)，则返回的对象必须能够强制转换为[String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)。 返回字符串必须表示 `value`的序列化值。 理想情况下，你选择的序列化格式应能够生成相同的值，如果该字符串传递到[ConvertFrom](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter.convertfrom)而丢失大量信息不相同转换器的实现。

如果值不能序列化，或转换器不支持序列化[ConvertTo](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter.convertto)实现必须返回`null`，并允许在此情况下引发异常。 如果引发了异常，则应报告无法使用该转换作为的一部分，但你[CanConvertTo](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter.canconvertto)实现，以便检查功能的最佳做法[CanConvertTo](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter.canconvertto)首先以避免异常支持。

如果`destinationType`参数的类型不是[String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)，可以选择自己的转换器处理。 通常情况下，你要恢复处理，这会在最基本的基实现[ConvertTo](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter.convertto)引发特定异常。

#### 实现 CanConvertTo

对于 [CanConvertTo](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter.canconvertto) 类型的 `true` ， `destinationType` 实现应返回 [String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)，否则遵从基实现。

#### 实现 CanConvertFrom

对于 [CanConvertFrom](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverter.canconvertfrom) 类型的 `true` ， `sourceType` 实现应返回 [String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)，否则遵从基实现。

### 应用 TypeConverterAttribute

为了使你的自定义类型转换器作为使用由 XAML 处理器的自定义类的类型转换器，必须应用.NET Framework 特性[TypeConverterAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverterattribute)向类定义。 通过特性指定的 [ConverterTypeName](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverterattribute.convertertypename) 必须是自定义类型转换器的类型名。 应用此特性后，当 XAML 处理器处理属性类型使用自定义类类型的值时，它可以输入字符串并返回对象实例。

还可以基于每个属性提供类型转换器。 应将 .NET Framework 特性 [TypeConverterAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverterattribute) 应用于属性定义（主定义，不是它包含的 `get`/`set` 的实现），而不是将它应用于类定义。 属性的类型必须与自定义类型转换器处理的类型匹配。 应用此特性后，当 XAML 处理器处理该属性的值时，它可以处理输入字符串并返回对象实例。 每个属性类型转换器方法会特别有用，如果您选择使用 Microsoft.NET Framework 中或某些其他库其中无法控制类定义并且无法应用的属性类型[TypeConverterAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverterattribute)存在。

## [WPF XAML Extensions](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/wpf-xaml-extensions)

### 本节内容

[绑定标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/binding-markup-extension)
[ColorConvertedBitmap 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/colorconvertedbitmap-markup-extension)
[ComponentResourceKey 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/componentresourcekey-markup-extension)
[DynamicResource 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dynamicresource-markup-extension)
[RelativeSource 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/relativesource-markupextension)
[StaticResource 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/staticresource-markup-extension)
[TemplateBinding 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/templatebinding-markup-extension)
[ThemeDictionary 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/themedictionary-markup-extension)
[PropertyPath XAML 语法](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/propertypath-xaml-syntax)
[PresentationOptions:Freeze 特性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/presentationoptions-freeze-attribute)

### [Binding Markup Extension](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/binding-markup-extension)

延迟输入属性值，将数据绑定值，创建一个中间表达式对象，并解释适用于的元素，并在运行时与其绑定的数据上下文。

#### 绑定表达式的使用

```
<object property="{Binding}" .../>  
-or-  
<object property="{Binding  bindProp1=value1[, bindPropN=valueN]*}" ...  
/>  
-or-  
<object property="{Binding path}" .../>  
-or  
<object property="{Binding path[, bindPropN=valueN]*}" .../>  
```

#### 语法说明

在这些语法`[]`和`*`不是文本。 它们是一部分表示法表示的零个或多个*绑定属性*`=`*值*可以使用对，使用`,`它们与上述之间的分隔符*绑定属性* `=`*值*对。

在"绑定属性，可以使用绑定扩展设置"一节中列出的任何的属性可以改为设置使用特性的[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)对象元素。 但是，这并非真正意义的标记扩展用法[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)，它是一种 XAML 处理的设置的 CLR 属性的属性只是常规[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)类。 换而言之， `<Binding` *绑定属性 1*`="`*value1* `"[` *绑定属性 n*`="`*valueN*`"]*/>`是属性的等效语法[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)对象而不是元素用法`Binding`表达式的使用。 若要了解有关的特定属性的 XAML 属性用法[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)，请参阅相关的属性的"XAML 属性用法"部分[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding).NET Framework 类库中。

#### XAML 值

|                        |                                                              |
| ---------------------- | ------------------------------------------------------------ |
| `bindProp1, bindPropN` | 名称[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)或[BindingBase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingbase)属性来设置。 不是所有[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)属性可以用来设置`Binding`扩展和某些属性是可在设置`Binding`表达式只能通过进一步使用嵌套标记扩展。 请参阅"绑定属性，可以将设置与绑定扩展"部分。 |
| `value1, valueN`       | 要将属性设置为的值。 属性值处理方法是最终特定于类型和特定的逻辑[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)要设置属性。 |
| `path`                 | 设置的隐式的路径字符串[Binding.Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.path)属性。 另请参阅[PropertyPath XAML 语法](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/propertypath-xaml-syntax)。 |

#### 非限定 {Binding}

`{Binding}` "绑定表达式使用情况"中所示的使用情况创建[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)对象的默认值，其中包括一个初始[Binding.Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.path)的`null`。 这仍可在许多情况下，因为创建[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)可能依赖于重要的数据绑定属性如[Binding.Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.path)和[Binding.Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.source)设置在运行时数据上下文中。 数据上下文的概念的详细信息，请参阅[数据绑定](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-wpf)。

#### 隐式的路径

`Binding`标记扩展用法[Binding.Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.path)作为概念"默认属性"，其中`Path=`不需要该表达式中出现。 如果指定`Binding`具有隐式路径表达式，隐式的路径必须首先出现在表达式中，在任何其他之前`bindProp` = `value`对，其中[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)按名称指定属性。 例如： `{Binding PathString}`，其中`PathString`是一个字符串的计算结果为的值，[Binding.Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.path)中[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)创建的标记扩展用法。 您可以与其他命名属性的隐式路径后追加逗号分隔符，例如， `{Binding LastName, Mode=TwoWay}`。

#### 可以使用绑定扩展设置的绑定属性

本主题中所示的语法使用泛型`bindProp` = `value`近似值，因为提供了许多的读/写属性[BindingBase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingbase)或[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)，可以通过设置`Binding`标记扩展 /表达式语法。 它们可以按任何顺序，除了隐式设置[Binding.Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.path)。 (您可以选择显式指定`Path=`，在这种情况下可以按任何顺序设置它)。 基本上，您可以设置零个或多个属性，下面的列表中使用`bindProp` = `value`对以逗号分隔。

这些属性值的几个需要的对象类型，不支持 XAML 中的文本语法中的本机类型转换，因此需标记扩展设置作为属性值。 检查每个属性以获取详细信息;.NET Framework 类库中的 XAML 属性用法部分有关使用 XAML 特性语法使用字符串或而无需进一步的标记扩展用法基本上是在中指定的值相同`Binding`表达式，与您未放置引号将每个异常`bindProp` =`value`在`Binding`表达式。

- [BindingGroupName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingbase.bindinggroupname)： 一个字符串，标识可能的绑定组。 这是一个相对高级的绑定的概念;请参阅参考页面的[BindingGroupName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingbase.bindinggroupname)。
- [BindsDirectlyToSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.bindsdirectlytosource)：布尔值，可以是`true`或`false`。 默认值为 `false`。
- [Converter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.converter)： 可设置为`bindProp` = `value`在表达式中，但若要执行此操作的字符串值，需要对象引用，如[StaticResource 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/staticresource-markup-extension)。 在这种情况下，值是自定义转换器类的实例。
- [ConverterCulture](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.converterculture)： 可设置为基于标准的标识符; 表达式中请参阅参考主题[ConverterCulture](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.converterculture)。
- [ConverterParameter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.converterparameter)： 可设置为`bindProp` = `value`字符串表达式，但这是依赖于所传递的参数的类型。 如果传递引用类型的值，这种用法需要对象引用，如嵌套[StaticResource 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/staticresource-markup-extension)。
- [ElementName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.elementname)： 与互斥[RelativeSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.relativesource)和[Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.source); 每个绑定属性表示的这些特定的绑定方法。 请参阅[数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview)。
- [FallbackValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingbase.fallbackvalue)： 可设置为`bindProp` = `value`字符串表达式，但这是依赖于所传递的值的类型。 如果传递引用类型，需要对象引用，如嵌套[StaticResource 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/staticresource-markup-extension)。
- [IsAsync](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.isasync)：布尔值，可以是`true`或`false`。 默认值为 `false`。
- [Mode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.mode):*值*是中的常量名[BindingMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode)枚举。 例如 `{Binding Mode=OneWay}`。
- [NotifyOnSourceUpdated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.notifyonsourceupdated)：布尔值，可以是`true`或`false`。 默认值为 `false`。
- [NotifyOnTargetUpdated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.notifyontargetupdated)：布尔值，可以是`true`或`false`。 默认值为 `false`。
- [NotifyOnValidationError](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.notifyonvalidationerror)：布尔值，可以是`true`或`false`。 默认值为 `false`。
- [Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.path)： 为数据对象或常规对象模型中描述的路径的字符串。 格式为遍历不能进行详细介绍本主题中的对象模型提供多个不同的约定。 请参阅[PropertyPath XAML 语法](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/propertypath-xaml-syntax)。
- [RelativeSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.relativesource)： 与互斥[ElementName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.elementname)和[Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.source); 每个绑定属性表示的这些特定的绑定方法。 请参阅[数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview)。 需要一个嵌套[RelativeSource 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/relativesource-markupextension)使用情况，以指定的值。
- [Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.source)： 与互斥[RelativeSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.relativesource)和[ElementName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.elementname); 每个绑定属性表示的这些特定的绑定方法。 请参阅[数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview)。 需要嵌套的扩展用法，通常[StaticResource 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/staticresource-markup-extension)到对象数据源引用键控的资源字典中。
- [StringFormat](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingbase.stringformat)： 一个字符串，描述绑定的数据的字符串格式约定。 这是一个相对高级的绑定的概念;请参阅参考页面的[StringFormat](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingbase.stringformat)。
- [TargetNullValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingbase.targetnullvalue)： 可设置为`bindProp` = `value`字符串表达式，但这是依赖于所传递的参数的类型。 如果传递引用类型的值需要对象引用，如嵌套[StaticResource 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/staticresource-markup-extension)。
- [UpdateSourceTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.updatesourcetrigger):*值*是中的常量名[UpdateSourceTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.updatesourcetrigger)枚举。 例如 `{Binding UpdateSourceTrigger=LostFocus}`。 特定控件可能具有不同的默认值为此绑定属性。 请参阅 [UpdateSourceTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.updatesourcetrigger)。
- [ValidatesOnDataErrors](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.validatesondataerrors)：布尔值，可以是`true`或`false`。 默认值为 `false`。 请参阅“备注”。
- [ValidatesOnExceptions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.validatesonexceptions)：布尔值，可以是`true`或`false`。 默认值为 `false`。 请参阅“备注”。
- [XPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.xpath)： 描述到 XML 数据源的 XMLDOM 的路径的字符串。 请参阅[绑定到 XML 数据使用 XMLDataProvider 和 XPath 查询](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-bind-to-xml-data-using-an-xmldataprovider-and-xpath-queries)。

以下是属性的[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)不能使用设置的`Binding`标记扩展 /`{Binding}`表达式形式。

- [UpdateSourceExceptionFilter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.updatesourceexceptionfilter)： 此属性需要对回调实现的引用。 不能在 XAML 语法引用回调/事件处理程序之外的方法。
- [ValidationRules](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.validationrules)： 该属性会采用的泛型集合[ValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule)对象。 这可能表示为属性元素中[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)对象元素，但具有中的使用情况没有现成的特性分析技术`Binding`表达式。 请参阅参考主题[ValidationRules](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.validationrules)。
- [XmlNamespaceManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.xmlnamespacemanager)

#### 备注

> 依赖关系属性在优先级方面，`Binding`表达式等效于本地设置值。 如果将以前的属性的本地值`Binding`表达式，`Binding`完全删除。 有关详细信息，请参阅[依赖属性值优先级](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-value-precedence)。

本主题未介绍基本级别的数据绑定。 请参阅[数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview)。

> [MultiBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.multibinding) 并[PriorityBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.prioritybinding)不支持XAML扩展语法。 应改用属性元素。 请参阅参考主题[MultiBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.multibinding)和[PriorityBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.prioritybinding)。

有关 XAML 的布尔值为不区分大小写。 例如，您可以指定`{Binding NotifyOnValidationError=true}`或`{Binding NotifyOnValidationError=True}`。

涉及数据验证的绑定通常由显式指定`Binding`元素而不是`{Binding ...}`表达式，并设置[ValidatesOnDataErrors](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.validatesondataerrors)或[ValidatesOnExceptions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.validatesonexceptions)在表达式中不常见。 这是因为配套属性[ValidationRules](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.validationrules)不能以表达式形式轻松设置。 有关详细信息，请参阅[实现绑定验证](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-implement-binding-validation)。

`Binding` 是标记扩展。 当要求转义特性值应为非文本值或处理程序名称，并且要求是更具有全局性比基于特定的类型或属性特性化类型转换器，通常会实现标记扩展。 在 XAML 使用的所有标记扩展`{`和`}`是依据 XAML 处理器认定标记扩展必须处理字符串的内容的约定其特性语法中的字符。 有关详细信息，请参阅[标记扩展和 WPF XAML](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/markup-extensions-and-wpf-xaml)。

`Binding` 是中的异常标记扩展[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)实现 WPF 的 XAML 实现的扩展功能的类还实现多种其他方法和与 XAML 无关的属性。 其他成员旨在使[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)可以解决许多数据绑定方案，除了作为 XAML 标记扩展的更多情形且自包含类。

### [ColorConvertedBitmap Markup Extension](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/colorconvertedbitmap-markup-extension)

提供了一种方法来指定不具有嵌入的配置文件是位图源。 颜色上下文 / 配置文件指定的URI，如映像源URI。

#### XAML 属性用法

```xml
<object property="{ColorConvertedBitmap imageSource sourceIIC destinationIIC}" .../>  
```

#### XAML 值

|                  |                       |
| ---------------- | --------------------- |
| `imageSource`    | URI的方式的位图。     |
| `sourceIIC`      | URI源配置文件配置。   |
| `destinationIIC` | URI的目标配置文件配置 |

#### 备注

此标记扩展旨在如填充一组相关的映像源属性值的[UriSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage.urisource)。

特性语法是最常用于该标记扩展的语法。 `ColorConvertedBitmap` (或`ColorConvertedBitmapExtension`) 因为值的字符串的初始构造函数上仅设置为值不能在属性元素语法中，使用以下的扩展标识符。

`ColorConvertedBitmap` 是标记扩展。 当要求转义特性值应为非文本值或非处理程序名称时，通常会实现标记扩展，相对于只在某些类型或属性上放置类型转换器而言，此需求更具有全局性。 XAML 中的所有标记扩展在其特性语法中都使用 { 和 } 字符，XAML 处理器通过这一约定确认标记扩展必须处理该特性。 有关详细信息，请参阅[标记扩展和 WPF XAML](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/markup-extensions-and-wpf-xaml)。

### [ComponentResourceKey Markup Extension](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/componentresourcekey-markup-extension)

定义和引用从外部程序集加载的资源键。 这样一种资源查找程序集，而不是显式的资源字典在程序集或对类中指定目标类型。

#### XAML 特性用法 （设置键，compact）

```xml
<object x:Key="{ComponentResourceKey {x:Type targetTypeName}, targetID}" .../>  
```

#### XAML 特性用法 （设置键、 verbose）

```xml
<object x:Key="{ComponentResourceKey TypeInTargetAssembly={x:Type targetTypeName}, ResourceID=targetID}" .../>  
```

#### XAML 特性用法 （请求资源，compact）

```xml
<object property="{DynamicResource {ComponentResourceKey {x:Type targetTypeName}, targetID}}" .../>  
```

#### XAML 特性用法 （请求资源，详细）

```xml
<object property="{DynamicResource {ComponentResourceKey TypeInTargetAssembly={x:Type targetTypeName}, ResourceID=targetID}}" .../>  
```

#### XAML 值

|                  |                                                              |
| ---------------- | ------------------------------------------------------------ |
| `targetTypeName` | 公共名称公共语言运行时 (CLR)资源程序集中定义的类型。         |
| `targetID`       | 资源键。 当资源查找`targetID`将类似于[X:key 指令](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-key-directive)的资源。 |

#### 备注

如上面的用法中所示 {`ComponentResourceKey`} 标记扩展用法在两个位置找到：

- 内的主题资源字典，由控件作者提供的键的定义。
- 从程序集访问主题资源，当你重新模板化控件但想要使用来自控件的主题提供资源的属性值。

用于引用来自主题的组件资源，通常建议您使用`{DynamicResource}`而非`{StaticResource}`。 这是与用法中所示。`{DynamicResource}` 建议，因为用户可以更改主题本身。 如果你想与支持该主题的控件作者的意图最匹配的组件资源，应启用组件资源参考，用于也是动态的。

[TypeInTargetAssembly](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.componentresourcekey.typeintargetassembly)标识存在于实际定义资源所在的目标集中的类型。 一个`ComponentResourceKey`可以定义和使用独立于完全了解其中[TypeInTargetAssembly](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.componentresourcekey.typeintargetassembly)已定义，但最终必须解决通过引用的程序集的类型。

常见用法[ComponentResourceKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.componentresourcekey)是定义键，然后公开为类的成员。 对于此用法中，你使用[ComponentResourceKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.componentresourcekey)类构造函数，不是标记扩展。 有关详细信息，请参阅[ComponentResourceKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.componentresourcekey)，或主题的"定义和引用主题资源的键"部分[控件创作概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/control-authoring-overview)。

有关建立键和引用键控资源，特性语法通常用于`ComponentResourceKey`标记扩展。

依赖于简洁的语法所示[ComponentResourceKey.ComponentResourceKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.componentresourcekey.-ctor)构造函数签名和标记扩展的位置参数用法。 依据的顺序`targetTypeName`和`targetID`提供非常重要。 详细语法依赖[ComponentResourceKey.ComponentResourceKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.componentresourcekey.-ctor)默认构造函数，然后设置[TypeInTargetAssembly](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.componentresourcekey.typeintargetassembly)和[ResourceId](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.componentresourcekey.resourceid)类似于在对象元素上的实际特性语法的方式。 在详细的语法中，将设置属性的顺序并不重要。 主题中的更多详细信息中所述的以下两个替代方法 （compact 和 verbose） 机制以及关系[标记扩展和 WPF XAML](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/markup-extensions-and-wpf-xaml)。

从技术上讲，值`targetID`可以是任何对象，它不需要为的字符串。 但是，在 WPF 中最常见的用法是对齐`targetID`值，该值具有窗体的字符串，并且其中此类字符串中可[XamlName 语法](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/xamlname-grammar)。

`ComponentResourceKey` 可以在对象元素语法中使用。 在这种情况下，指定的值都[TypeInTargetAssembly](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.componentresourcekey.typeintargetassembly)和[ResourceId](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.componentresourcekey.resourceid)正确初始化该扩展所需的属性。

在中WPFXAML读取器实现，对此标记扩展的处理由定义[ComponentResourceKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.componentresourcekey)类。

`ComponentResourceKey` 是标记扩展。 当要求转义特性值应为非文本值或非处理程序名称时，通常会实现标记扩展，相对于只在某些类型或属性上放置类型转换器而言，此需求更具有全局性。 XAML 中的所有标记扩展在其特性语法中都使用 { 和 } 字符，XAML 处理器通过这一约定确认标记扩展必须处理该特性。 有关详细信息，请参阅[标记扩展和 WPF XAML](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/markup-extensions-and-wpf-xaml)。

### [DateTime XAML Syntax](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/datetime-xaml-syntax)

某些控件，例如[Calendar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.calendar)并[DatePicker](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datepicker)，具有使用的属性[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)类型。 虽然通常会在运行时在代码隐藏中指定这些控件的初始日期或时间，但可以在 XAML 中指定初始日期或时间。 WPF XAML 分析器处理的分析[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)值使用内置的 XAML 文本语法。 本主题介绍的细节[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)XAML 文本语法。

#### DateTime XAML 语法的使用场合

无需经常对 XAML 中的日期进行设置，而且设置也可能并不合适。 例如，可以使用[DateTime.Now](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime.now)属性传入以初始化日期在运行的时，也可以根据用户输入在代码隐藏中为日历执行所有日期进行调整。 但是，有些的情况下，可能要硬编码日期到[Calendar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.calendar)和[DatePicker](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datepicker)控件模板中。 [DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime) XAML 语法必须用于这些方案。

##### DateTime XAML 语法是本机行为

[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime) 是在 CLR 基类库中定义的类。 由于如何基类库与 CLR 的其余部分相关联，它不能应用[TypeConverterAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typeconverterattribute)的类和使用的类型转换器处理 XAML 中的字符串，并将它们转换为[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)运行的时对象模型中。 没有提供转换行为的 `DateTimeConverter` 类；本主题中描述的转换行为源于 WPF XAML 分析器。

#### DateTime XAML 语法的格式字符串

你可以指定的格式[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)有一个格式字符串。 格式字符串会规范可用于创建值的文本语法。 [DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime) 对于现有 WPF 控件通常仅使用日期组成部分的值[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)而不是时间组件。

指定时[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)在 XAML，您可以使用任何格式字符串互换。

还可以使用未在本主题中专门显示的格式和格式字符串。 从技术上讲，任何 XAML[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)值，该值指定，然后分析 WPF XAML 分析器使用的内部调用[DateTime.Parse](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime.parse)，因此可以使用接受的任何字符串[DateTime.Parse](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime.parse)对于你的 XAML 输入。 有关详细信息，请参阅 [DateTime.Parse](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime.parse)。

> DateTime XAML 语法始终使用`en-us`作为[CultureInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.globalization.cultureinfo)其本机转换。 这不受[Language](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.language)值或`xml:lang`XAML，这是因为 XAML 属性级别的类型转换操作而无需该上下文值。 出于区域性差异的原因，请不要尝试插入此处所示的格式字符串，例如，日期和月份的显示顺序。 此处所示的格式字符串是在分析 XAML 时（不考虑其他区域性设置）使用的确切格式字符串。

以下各节介绍了一些常见[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)格式字符串。

##### 短日期模式（“d”）

以下显示的短日期格式[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)在 XAML 中：

```
M/d/YYYY
```

这是最简单的形式，可指定 WPF 控件一般使用的所有必要信息，并且不受针对时间部分的偶然时区偏移的影响，因此比其他格式更适用。

例如，若要指定日期 2010 年 6 月 1 日，可使用以下字符串：

```
3/1/2010
```

有关详细信息，请参阅 [DateTimeFormatInfo.ShortDatePattern](https://docs.microsoft.com/zh-cn/dotnet/api/system.globalization.datetimeformatinfo.shortdatepattern)。

##### 可排序 DateTime 模式（“s”）

下面的示例演示可排序[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)在 XAML 中的模式：

```
yyyy'-'MM'-'dd'T'HH':'mm':'ss
```

例如，若要指定日期 2010 年 6 月 1 日，可使用以下字符串（时间部分全部输入为 0）：

```
2010-06-01T000:00:00
```

##### RFC1123 模式（“r”）

RFC1123 模式很有用，因为它可以是来自其他日期生成器的字符串输入，这些字符生成器出于区域性固定原因同样使用 RFC1123 模式。 下面的示例演示 RFC1123[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)在 XAML 中的模式：

```
ddd, dd MMM yyyy HH':'mm':'ss 'UTC'
```

例如，若要指定日期 2010 年 6 月 1 日，可使用以下字符串（时间部分全部输入为 0）：

```
Mon, 01 Jun 2010 00:00:00 UTC
```

##### 其他格式和模式

如前所述，[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)在 XAML 中可以指定为可接受任何字符串作为输入的[DateTime.Parse](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime.parse)。 这包括其他正式化的格式 (例如[UniversalSortableDateTimePattern](https://docs.microsoft.com/zh-cn/dotnet/api/system.globalization.datetimeformatinfo.universalsortabledatetimepattern))，以及未正式化为特定的格式[DateTimeFormatInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.globalization.datetimeformatinfo)窗体。 例如，窗体`YYYY/mm/dd`是可接受作为输入的[DateTime.Parse](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime.parse)。 本主题并没有试图介绍所有可能有效的格式，而是推荐将短日期模式作为一种标准做法。

### [DynamicResource Markup Extension](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/dynamicresource-markup-extension)

提供值的任何XAML通过推迟将对定义资源的引用值的属性特性。 类似于运行时查找该资源的查找行为。

#### XAML 属性用法

```xml
<object property="{DynamicResource key}" .../>  
```

#### XAML 属性元素用法

```xml
<object>  
  <object.property>  
    <DynamicResource ResourceKey="key" .../>  
  </object.property>  
</object>  
```

#### XAML 值

|       |                                                              |
| ----- | ------------------------------------------------------------ |
| `key` | 所请求资源的密钥。 最初由该键[X:key 指令](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-key-directive)如果资源已在标记中，或作为提供`key`参数调用时[ResourceDictionary.Add](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary.add)如果资源在代码中创建的。 |

#### 备注

一个`DynamicResource`将创建初始编译期间的临时表达式并因此延迟的资源查找，直到实际需要来构造对象请求的资源值为止。 这可能后XAML加载页面。 资源值将基于与当前的页范围，从开始的所有活动的资源字典的密钥搜索找到并替换为从编译的占位符表达式。

> 依赖关系属性在优先级方面，`DynamicResource`表达式等效于应用的动态资源引用的位置的位置。 如果将以前的属性的本地值`DynamicResource`作为本地值，表达式`DynamicResource`完全删除。 有关详细信息，请参阅[依赖属性值优先级](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-value-precedence)。

某些资源的访问方案是特别适合`DynamicResource`而不是[StaticResource 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/staticresource-markup-extension)。 请参阅[XAML 资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-resources)有关的相对优点和性能产生的影响的讨论`DynamicResource`和`StaticResource`。

指定[ResourceKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dynamicresourceextension.resourcekey)应该对应于现有的资源由[X:key 指令](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-key-directive)在您的页面、 应用程序、 可用的控件的主题和外部资源或系统资源，在某种程度上和查找资源也将按该顺序。 有关静态和动态资源的资源查找的详细信息，请参阅[XAML 资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-resources)。

资源键可以是任何字符串中定义[XamlName 语法](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/xamlname-grammar)。 资源键也可以是其他对象类型，如[Type](https://docs.microsoft.com/zh-cn/dotnet/api/system.type)。 一个[Type](https://docs.microsoft.com/zh-cn/dotnet/api/system.type)密钥是如何可以由主题样式控件的基础。 有关详细信息，请参阅[控件创作概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/control-authoring-overview)。

API 用于查找资源值，如[FindResource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.findresource)，遵循所使用的相同的资源查找逻辑`DynamicResource`。

引用资源的可选声明性方式是作为[StaticResource 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/staticresource-markup-extension)。

特性语法是最常用于该标记扩展的语法。 在 `DynamicResource` 标识符字符串之后提供的字符串标记被指定为基础 [ResourceKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dynamicresourceextension.resourcekey) 扩展类的 [DynamicResourceExtension](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dynamicresourceextension) 值。

`DynamicResource` 可以在对象元素语法中使用。 在这种情况下，指定的值[ResourceKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dynamicresourceextension.resourcekey)属性是必需的。

`DynamicResource` 还可以在详细特性用法中使用，以便将 [ResourceKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dynamicresourceextension.resourcekey) 属性指定为一个 property=value 对：

```xml
<object property="{DynamicResource ResourceKey=key}" .../>  
```

如果扩展具有一个以上的可设置属性，或者某些属性是可选的，则详细用法通常会很有用。 由于 `DynamicResource` 仅有一个可设置的属性，并且此属性是必需的，因此该详细用法不具有典型性。

在中WPFXAML处理器实现中，对此标记扩展的处理由定义[DynamicResourceExtension](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dynamicresourceextension)类。

`DynamicResource` 是标记扩展。 当要求转义特性值应为非文本值或非处理程序名称时，通常会实现标记扩展，相对于只在某些类型或属性上放置类型转换器而言，此需求更具有全局性。 XAML 中的所有标记扩展在其特性语法中都使用 { 和 } 字符，XAML 处理器通过这一约定确认标记扩展必须处理该特性。 有关详细信息，请参阅[标记扩展和 WPF XAML](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/markup-extensions-and-wpf-xaml)。

### [RelativeSource MarkupExtension](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/relativesource-markupextension)

指定的属性[RelativeSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.relativesource)绑定源中使用[绑定标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/binding-markup-extension)，或设置时[RelativeSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.relativesource)属性[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)建立在 XAML 中的元素。

#### XAML 属性用法

```xml
<Binding RelativeSource="{RelativeSource modeEnumValue}" .../>  
```

#### XAML 属性用法（嵌套在 Binding 扩展内）

```xml
<object property="{Binding RelativeSource={RelativeSource modeEnumValue} ...}" .../>  
```

#### XAML 对象元素用法

```xml
<Binding>  
  <Binding.RelativeSource>  
    <RelativeSource Mode="modeEnumValue"/>  
  </Binding.RelativeSource>  
</Binding>  
```

或

```xml
<Binding>  
  <Binding.RelativeSource>  
    <RelativeSource  
      Mode="FindAncestor"  
      AncestorType="{x:Type typeName}"  
      AncestorLevel="intLevel"  
    />  
  </Binding.RelativeSource>  
</Binding>  
```

#### XAML 值

|                 |                                                              |
| --------------- | ------------------------------------------------------------ |
| `modeEnumValue` | 以下项之一：  字符串标记`Self`; 对应于[RelativeSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.relativesource)创建具有其[Mode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.relativesource.mode)属性设置为[Self](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.relativesourcemode#System_Windows_Data_RelativeSourceMode_Self)。 字符串标记`TemplatedParent`; 对应于[RelativeSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.relativesource)创建具有其[Mode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.relativesource.mode)属性设置为[TemplatedParent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.relativesourcemode#System_Windows_Data_RelativeSourceMode_TemplatedParent)。 字符串标记`PreviousData`; 对应于[RelativeSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.relativesource)创建具有其[Mode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.relativesource.mode)属性设置为[PreviousData](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.relativesourcemode#System_Windows_Data_RelativeSourceMode_PreviousData)。 -请参阅下面的信息有关`FindAncestor`模式。 |
| `FindAncestor`  | 字符串标记 `FindAncestor`。 使用此标记可输入一个模式，以便 `RelativeSource` 指定上级类型和可选的上级级别。 它对应于通过将 [RelativeSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.relativesource) 属性设置为 [Mode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.relativesource.mode) 而创建的 [FindAncestor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.relativesourcemode#System_Windows_Data_RelativeSourceMode_FindAncestor)。 |
| `typeName`      | 对于 `FindAncestor` 模式是必需的。 类型的名称，用于填充 [AncestorType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.relativesource.ancestortype) 属性。 |
| `intLevel`      | 对于 `FindAncestor` 模式是可选的。 上级级别（在逻辑树中向父级方向计算）。 |

#### 备注

`{RelativeSource TemplatedParent}` 绑定用法是一项关键技术的一大概念的控件的用户界面和控件的逻辑分离。 这可以实现从模板定义内绑定到模板化父级（在其中应用模板的运行时对象实例）。 这种情况下， [TemplateBinding 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/templatebinding-markup-extension)实际上是以下绑定表达式的简写形式： `{Binding RelativeSource={RelativeSource TemplatedParent}}`。 `TemplateBinding` 或`{RelativeSource TemplatedParent}`用法都仅定义了一个模板 XAML 内部适用。 有关详细信息，请参阅[TemplateBinding 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/templatebinding-markup-extension)

`{RelativeSource FindAncestor}` 主要用于控件模板或可预测的自包含的 UI 组合，其中一个控件始终应位于某个上级类型的可视树的情况。 例如，项控件的项可能使用 `FindAncestor` 用法绑定到其项控件父级/祖先级。 或者，属于模板中控件组合一部分的元素可使用 `FindAncestor` 绑定到同一组合结构中的父元素。

在 XAML 语法章节显示的 `FindAncestor` 模式的对象元素语法中，第二个对象元素语法专门用于 `FindAncestor` 模式。 `FindAncestor` 模式需要 [AncestorType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.relativesource.ancestortype) 值。 必须设置[AncestorType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.relativesource.ancestortype)作为属性使用[X:type 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-type-markup-extension)要查找的上级节点的类型引用。 当在运行时处理绑定请求时，将会用到 [AncestorType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.relativesource.ancestortype) 值。

对于 `FindAncestor` 模式，当元素树中可能存在多个该类型的上级时，可以使用可选属性 [AncestorLevel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.relativesource.ancestorlevel) 帮助消除上级查找的歧义。

有关如何使用 `FindAncestor` 模式的详细信息，请参阅 [RelativeSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.relativesource)。

`{RelativeSource Self}` 适用于方案这两个属性之间的一个实例属性应依赖于同一个实例，并 （如强制） 任何一般依赖属性关系的另一个属性的值已存在。 虽然很少见，对象上存在两个属性值可以说完全相同 （并以相同方式键入），您还可以应用`Converter`具有一个绑定到参数`{RelativeSource Self}`，并使用此转换器转换源之间和目标类型。 另一方案`{RelativeSource Self}`作为的一部分是[MultiDataTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.multidatatrigger)。

例如，以下 XAML 定义了一个 [Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle) 元素，以便无论为 [Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width) 输入什么值，都确保 [Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle) 始终是一个方形：`<Rectangle Width="200" Height="{Binding RelativeSource={RelativeSource Self}, Path=Width}" .../>`

`{RelativeSource PreviousData}` 数据模板中或在其中绑定将使用集合作为数据源的情况下非常有用。 可以使用`{RelativeSource PreviousData}`以突出显示集合中相邻数据项之间的关系。 相关技术是在数据源中的当前项和前一个项之间建立 [MultiBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.multibinding)，并使用此绑定上的转换器来确定这两个项及其属性的差异。

在下面的示例中，项目模板中的第一个 [TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock) 可显示当前编号。 第二个[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)绑定[MultiBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.multibinding)，名义上有两个[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)构成要素： 当前记录，并刻意采用前一个数据记录使用的绑定`{RelativeSource PreviousData}`。 然后，[MultiBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.multibinding) 上的转换器将计算差异，并将其返回到绑定。

```xml
<ListBox Name="fibolist">  
    <ListBox.ItemTemplate>  
        <DataTemplate>  
            <StackPanel Orientation="Horizontal">  
            <TextBlock Text="{Binding}"/>  
            <TextBlock>, difference = </TextBlock>  
                <TextBlock>  
                    <TextBlock.Text>  
                        <MultiBinding Converter="{StaticResource DiffConverter}">  
                            <Binding/>  
                            <Binding RelativeSource="{RelativeSource PreviousData}"/>  
                        </MultiBinding>  
                    </TextBlock.Text>  
                </TextBlock>  
            </StackPanel>  
        </DataTemplate>  
    </ListBox.ItemTemplate>  
```

数据绑定概念未在此处，请参阅[数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview)。

在中WPFXAML 处理器实现中，对此标记扩展的处理由定义[RelativeSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.relativesource)类。

`RelativeSource` 是标记扩展。 当要求转义特性值应为非文本值或非处理程序名称时，通常会实现标记扩展，相对于只在某些类型或属性上放置类型转换器而言，此需求更具有全局性。 在 XAML 使用的所有标记扩展`{`和`}`约定所依据的 XAML 处理器识别标记扩展必须处理该属性其特性语法中的字符。 有关详细信息，请参阅[标记扩展和 WPF XAML](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/markup-extensions-and-wpf-xaml)。   

### [StaticResource Markup Extension](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/staticresource-markup-extension)

提供值的任何XAML通过查找对已定义资源的引用的属性特性。 对该资源的查找行为是类似于加载时查找，将在当前的标记从先前加载的资源查找XAML以及其他应用程序源页上，将生成与该资源值在运行时对象的属性值。

#### XAML 属性用法

```xml
<object property="{StaticResource key}" .../>  
```

#### XAML 对象元素用法

```xml
<object>  
  <object.property>  
<StaticResource ResourceKey="key" .../>  
  </object.property>  
</object>  
```

#### XAML 值

|       |                                                              |
| ----- | ------------------------------------------------------------ |
| `key` | 所请求资源的密钥。 最初由该键[X:key 指令](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-key-directive)如果资源已在标记中，或作为提供`key`参数调用时[ResourceDictionary.Add](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary.add)如果资源在代码中创建的。 |

#### 备注

> 一个`StaticResource`不能尝试使对资源定义前向引用在词法上进一步XAML文件。 不支持尝试这样做，并且即使此类引用不会失败，尝试前向引用将会产生对加载时间性能产生负面影响时表示的内部哈希表[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)搜索。 为获得最佳结果，调整资源字典的组合，这样可以避免前向引用。 如果无法避免前向引用，使用[DynamicResource 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dynamicresource-markup-extension)相反。

指定[ResourceKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.staticresourceextension.resourcekey)应该对应于现有资源，以标识[X:key 指令](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-key-directive)页面、 应用程序，可用的控件的主题和外部资源或系统资源中的某个级别。 资源查找发生的顺序。 有关静态和动态资源的资源查找行为的详细信息，请参阅[XAML 资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-resources)。

资源键可以是任何字符串中定义[XamlName 语法](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/xamlname-grammar)。 资源键也可以是其他对象类型，如[Type](https://docs.microsoft.com/zh-cn/dotnet/api/system.type)。 一个[Type](https://docs.microsoft.com/zh-cn/dotnet/api/system.type)密钥是如何控件可以设置的样式的主题，通过隐式样式项的基础。 有关详细信息，请参阅[控件创作概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/control-authoring-overview)。

引用资源的可选声明性方式是作为[DynamicResource 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dynamicresource-markup-extension)。

特性语法是最常用于该标记扩展的语法。 在 `StaticResource` 标识符字符串之后提供的字符串标记被指定为基础[ResourceKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.staticresourceextension.resourcekey) 扩展类的 [StaticResourceExtension](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.staticresourceextension) 值。

`StaticResource` 可以在对象元素语法中使用。 在这种情况下，指定的值[ResourceKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.staticresourceextension.resourcekey)属性是必需的。

`StaticResource` 还可以在详细特性用法中使用，以便将 [ResourceKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.staticresourceextension.resourcekey) 属性指定为一个 property=value 对：

```xml
<object property="{StaticResource ResourceKey=key}" .../>  
```

如果扩展具有一个以上的可设置属性，或者某些属性是可选的，则详细用法通常会很有用。 由于 `StaticResource`仅有一个可设置的属性，并且此属性是必需的，因此该详细用法不具有典型性。

在中WPFXAML处理器实现中，对此标记扩展的处理由定义[StaticResourceExtension](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.staticresourceextension)类。

`StaticResource` 是标记扩展。 当要求转义特性值应为非文本值或非处理程序名称时，通常会实现标记扩展，相对于只在某些类型或属性上放置类型转换器而言，此需求更具有全局性。 XAML 中的所有标记扩展在其特性语法中都使用 { 和 } 字符，XAML 处理器通过这一约定确认标记扩展必须处理该特性。 有关详细信息，请参阅[标记扩展和 WPF XAML](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/markup-extensions-and-wpf-xaml)。

### [TemplateBinding Markup Extension](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/templatebinding-markup-extension)

连接某一控件模板中的属性值，使之成为模板化控件上另一个属性的值。

#### XAML 属性用法

```xml
<object property="{TemplateBinding sourceProperty}" .../>  
```

#### XAML 特性用法（适用于模板或样式的 Setter 属性）

```xml
<Setter Property="propertyName" Value="{TemplateBinding sourceProperty}" .../>  
```

#### XAML 值

|                  |                                                              |
| ---------------- | ------------------------------------------------------------ |
| `propertyName`   | 在资源库语法中设置的属性的 [DependencyProperty.Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.name)。 |
| `sourceProperty` | 另一个在要模板化的类型上存在的依赖项属性，由其 [DependencyProperty.Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.name) 来指定。  - 或 -  由要模板化的目标类型之外的类型所定义的“dotted-down”属性名称。 这实际上是 [PropertyPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertypath)。请参阅[PropertyPath XAML 语法](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/propertypath-xaml-syntax)。 |

#### 备注

一个`TemplateBinding`是的优化的形式[绑定](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/binding-markup-extension)对于模板方案，类似于`Binding`构造`{Binding RelativeSource={RelativeSource TemplatedParent}}`。 `TemplateBinding` 始终为单向绑定，即使所涉及的属性默认为双向绑定。 所涉及的两个属性都必须是依赖项属性。 若要实现双向绑定到模板化父级以下绑定语句改为使用`{Binding RelativeSource={RelativeSource TemplatedParent}, Mode=TwoWay, Path=MyDependencyProperty}`。

[RelativeSource](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/relativesource-markupextension)是另一个标记扩展，有时结合使用或者代替`TemplateBinding`以便执行相对属性绑定在模板中的。

描述控件模板作为一个概念是此处未介绍;有关详细信息，请参阅[Control 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/control-styles-and-templates)。

特性语法是最常用于该标记扩展的语法。 在 `TemplateBinding` 标识符字符串之后提供的字符串标记被指定为基础 [Property](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.templatebindingextension.property) 扩展类的 [TemplateBindingExtension](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.templatebindingextension) 值。

对象元素语法也可行，但因为没有实际的应用，所以未进行演示。 `TemplateBinding` 用于使用计算的表达式来填充资源库内的值，因此使用 `TemplateBinding` 的对象元素语法来填充 `<Setter.Property>` 属性元素语法就会变得繁冗而多余。

`TemplateBinding` 还可以在详细特性用法中使用，以便将 [Property](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.templatebindingextension.property) 属性指定为一个 property=value 对：

```xml
<object property="{TemplateBinding Property=sourceProperty}" .../>  
```

如果扩展具有一个以上的可设置属性，或者某些属性是可选的，则详细用法通常会很有用。 由于 `TemplateBinding` 仅有一个可设置的属性，并且此属性是必需的，因此该详细用法不具有典型性。

在中WPFXAML 处理器实现中，对此标记扩展的处理由定义[TemplateBindingExtension](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.templatebindingextension)类。

`TemplateBinding` 是标记扩展。 当要求转义特性值应为非文本值或非处理程序名称时，通常会实现标记扩展，相对于只在某些类型或属性上放置类型转换器而言，此需求更具有全局性。 在 XAML 使用的所有标记扩展`{`和`}`约定所依据的 XAML 处理器识别标记扩展必须处理该属性其特性语法中的字符。 有关详细信息，请参阅[标记扩展和 WPF XAML](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/markup-extensions-and-wpf-xaml)。

### [ThemeDictionary Markup Extension](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/themedictionary-markup-extension)

为集成第三方控件的自定义控件创作者或应用程序提供一种方法，用于加载要在设置控件样式时使用的特定于主题的资源字典。

#### XAML 属性用法

```xml
<object property="{ThemeDictionary assemblyUri}" .../>  
```

#### XAML 对象元素用法

```xml
<object>  
  <object.property>  
    <ThemeDictionary AssemblyName="assemblyUri"/>  
  <object.property>  
<object>  
```

#### XAML 值

|               |                                                              |
| ------------- | ------------------------------------------------------------ |
| `assemblyUri` | 程序集的 统一资源标识符 (URI)，其中包含主题信息。 通常，这是一个引用较大包中程序集的 Pack URI。 程序集资源和 Pack URI 可以简化部署问题。 有关详细信息，请参阅 [WPF 中的 Pack URI](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/pack-uris-in-wpf)。 |

#### 备注

此扩展旨在填补只有一个特定属性值： 的值[ResourceDictionary.Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary.source)。

通过使用此扩展，可以指定一个纯资源程序集，该程序集包含一些仅在向用户系统应用 Windows Aero 主题时使用的样式、当 Luna 主题处于活动状态时的其他样式等。 通过使用此扩展，可以自动让特定于控件的资源字典的内容失效，并在需要时重新将其加载为特定于其他主题的内容。

`assemblyUri`字符串 ([AssemblyName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.themedictionaryextension.assemblyname)属性值) 标识的字典适用于特定主题的命名约定的基础。 [ProvideValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.markupextension.providevalue)逻辑`ThemeDictionary`通过生成来完成约定统一资源标识符 (URI)，它指向特定主题字典变体，包含在预编译的资源程序集中。 本文并未将该约定（即主题与一般控件样式设置和页/应用程序级样式设置之间的交互）作为一个概念进行详细介绍。 使用的基本情形`ThemeDictionary`是指定[Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary.source)属性的`ResourceDictionary`应用程序级别的声明。将 URI 通过 `ThemeDictionary` 扩展而不是作为一个直接的 URI 提供给程序集时，扩展逻辑将提供系统主题更改时适用的失效逻辑。

特性语法是最常用于该标记扩展的语法。 在 `ThemeDictionary` 标识符字符串之后提供的字符串标记被指定为基础 [AssemblyName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.themedictionaryextension.assemblyname) 扩展类的 [ThemeDictionaryExtension](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.themedictionaryextension) 值。

`ThemeDictionary` 还可以在对象元素语法中使用。 在这种情况下，指定的值[AssemblyName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.themedictionaryextension.assemblyname)属性是必需的。

`ThemeDictionary` 还可以在详细特性用法中使用，以便将 [Member](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.staticextension.member) 属性指定为一个 property=value 对：

```xml
<object property="{ThemeDictionary AssemblyName=assemblyUri}" .../>  
```

如果扩展具有一个以上的可设置属性，或者某些属性是可选的，则详细用法通常会很有用。 由于 `ThemeDictionary` 仅有一个可设置的属性，并且此属性是必需的，因此该详细用法不具有典型性。

在中WPFXAML处理器实现中，对此标记扩展的处理由定义[ThemeDictionaryExtension](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.themedictionaryextension)类。

`ThemeDictionary` 是标记扩展。 当要求转义特性值应为非文本值或非处理程序名称时，通常会实现标记扩展，相对于只在某些类型或属性上放置类型转换器而言，此需求更具有全局性。 XAML 中的所有标记扩展在其特性语法中都使用 { 和 } 字符，XAML 处理器通过这一约定确认标记扩展必须处理该特性。 有关详细信息，请参阅[标记扩展和 WPF XAML](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/markup-extensions-and-wpf-xaml)。

### [PropertyPath XAML Syntax](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/propertypath-xaml-syntax)

[PropertyPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertypath)对象支持复杂内联XAML设置的各种属性的语法[PropertyPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertypath)类型作为其值。 本主题介绍[PropertyPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertypath)应用于绑定和动画语法的语法。

#### PropertyPath 的使用情景

[PropertyPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertypath) 是一个常见对象，用于多种Windows Presentation Foundation (WPF)功能。 尽管使用通用[PropertyPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertypath)传输属性路径信息，为每个使用情况功能区域其中[PropertyPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertypath)用作一种类型会有所不同。 因此，基于每个功能来讨论语法更为可行。

主要WPF使用[PropertyPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertypath)来描述对象模型路径以遍历属性的对象数据源，并描述目标动画的目标路径。

某些样式和模板的属性，如[Setter.Property](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.setter.property)需要看起来类似的限定的属性名[PropertyPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertypath)。 但这不是真正[PropertyPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertypath); 相反，它是限定*owner.property*字符串格式用法启用由 WPFXAML处理器的类型转换器与[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)。

#### 数据绑定中对象的 PropertyPath

数据绑定是 WPF 功能，借此可以绑定到任意依赖属性的目标值。 但是，此类数据绑定的源不需要是依赖属性；可以是适用数据提供程序能识别的任意属性类型。 属性路径特别用于[ObjectDataProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.objectdataprovider)，用于获取从绑定源公共语言运行时 (CLR)对象及其属性。

请注意，数据绑定到XML不使用[PropertyPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertypath)，因为它不使用[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.path)中[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)。 相反，使用[XPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.xpath)并指定到有效的 XPath 语法XML 文档对象模型 (DOM)的数据。 [XPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.xpath) 此外指定为字符串，但未在此处; 介绍请参阅[XMLDataProvider 和 XPath 查询绑定到 XML 数据使用](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-bind-to-xml-data-using-an-xmldataprovider-and-xpath-queries)。

理解数据绑定中的属性路径的关键是将绑定到单个属性值设置为目标，或者改为绑定到采用列表或集合的目标属性。 如果要绑定的集合，例如绑定[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)，具体取决于在集合中，有多少数据项将展开，则属性路径应引用集合对象，而不是单个集合项。 数据绑定引擎将匹配的数据源的绑定目标的类型为自动，从而导致的行为，例如填充用作集合[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)使用项数组。

##### 直接对象上作为数据上下文的单个属性

```xml
<Binding Path="propertyName" .../>  
```

*propertyName*必须解析为位于当前属性的名称[DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext)为[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.path)使用情况。 如果绑定更新源，则属性必须是可读取/写入的，并且源对象必须可变。

##### 直接对象上作为数据上下文的单个索引器

```xml
<Binding Path="[key]" .../>  
```

`key` 必须是字典或哈希表的类型化索引，或者是数组的整数索引。 此外，键值必须是可直接绑定到所应用属性的类型。 例如，包含字符串键和字符串值的哈希表可用于这种方式将绑定到文本[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。 或者，如果键指向集合或子索引，则可使用此语法绑定到目标集合属性。 否则，需要通过 `<Binding Path="[key].propertyName" .../>` 等语法来引用特定属性。

如有必要，可以指定索引的类型。 有关此方面的索引的属性路径的详细信息，请参阅[Binding.Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.path)。

##### 多个属性（间接属性目标设置）

```xml
<Binding Path="propertyName.propertyName2" .../>  
```

`propertyName` 必须解析为的一个属性，它是当前名称[DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext)。 路径属性 `propertyName` 和 `propertyName2`可以是关系中的任意属性，其中 `propertyName2` 是存在于类型中的值为 `propertyName` 的属性。

##### 附加的或类型限定的单个属性

```xml
<object property="(ownerType.propertyName)" .../>  
```

括号指示此属性在[PropertyPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertypath)应使用部分限定构造。 它可以使用 XML 命名空间来查找具有适当映射的类型。 `ownerType`搜索类型XAML处理器有权访问，通过[XmlnsDefinitionAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.xmlnsdefinitionattribute)中每个程序集的声明。 大部分应用程序都具有映射到 http://schemas.microsoft.com/winfx/2006/xaml/presentation 命名空间的默认 XML 命名空间，因此通常仅有自定义类型或该命名空间之外的类型才需要前缀。 `propertyName` 必须解析为 `ownerType` 中存在的属性名称。 此语法一般用于以下任一情况：

- 路径是在 XAML 中的样式或模板（该样式或模板没有指定的目标类型）中指定的。 除此之外，限定用法一般无效，因为在非样式、非模板情况下，属性存在于实例中，而不是类型中。
- 属性为附加属性。
- 要绑定到静态属性中。

用作情节提要目标，该属性指定为`propertyName`必须是[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)。

##### 源遍历（绑定到集合的层次结构）

```xml
<object Path="propertyName/propertyNameX" .../>  
```

此语法中的 / 用于在分层数据源对象中导航，并且支持使用连续的 / 字符分多个步骤导航层次结构。 源遍历说明了当前记录指针位置，该位置是通过将数据与其视图的 UI 同步而确定的。 有关与分层数据源对象绑定的详细信息，以及数据绑定中当前记录指针的概念，请参阅[对分层数据使用主-从模式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-use-the-master-detail-pattern-with-hierarchical-data)或[数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview)。

> 此语法看起来类似 XPath。 真正XPath绑定到表达式XML数据源不用作[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.path)值，而是应为互相排斥[XPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.xpath)属性。

##### 集合视图

若要引用一个已命名的集合视图，请使用哈希字符 (`#`) 为集合视图名称添加前缀。

##### 当前记录指针

若要引用集合视图的当前记录指针或引用主从数据绑定方案，请启用带正斜杠 (`/`) 的路径字符串。 从当前记录指针开始遍历任何超出正斜杠的路径。

##### 多个索引器

```
<object Path="[index1,index2...]" .../>  
or  
<object Path="propertyName[index,index2...]" .../>  
```

如果给定的对象支持多个索引器，则可以按顺序指定这些索引器，类似于数组引用语法。 上述对象可以是当前上下文，也可以是包含多个索引对象的属性的值。

默认情况下，通过使用基础对象的特性来类型化索引器值。 如有必要，可以指定索引的类型。 键入索引器的详细信息，请参阅[Binding.Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.path)。

##### 混合语法

上述每条语法都可以独立使用。 例如，下面是在特定的 x 和 y 值创建颜色的属性路径的示例`ColorGrid`属性，其中包含像素网格数组的[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)对象：

```xml
<Rectangle Fill="{Binding ColorGrid[20,30].SolidColorBrushResult}" .../>  
```

##### 属性路径字符串的转义

对于某些业务对象，你可能会遇到这样的情况：属性路径字符串需要转义序列以进行正确分析。 因为大多数此类字符在常用于定义业务对象的语言方面具有类似的命名交互问题，因此转义需要非常少见。

- 在索引器 ([ ]) 内部，脱字符号 (^) 用于对下一个字符进行转义。
- 必须（使用 XML 实体）对 XML 语言定义专用的某些字符进行转义。 使用 `&` 对字符“&”进行转义。 使用 `>` 对结束标记“>”进行转义。
- 必须（使用反斜杠 `\`）对特定于 WPF XAML 分析程序行为的字符进行转义，以处理标记扩展。
  - 反斜杠 (`\`) 本身是转义字符。
  - 等号 (`=`) 将属性名与属性值分隔开。
  - 逗号 (`,`) 用于分隔属性。
  - 右大括号 (`}`) 是标记扩展的结尾。

> 从技术上讲，这些转义符还适用于情节提要属性路径，但通常会遍历适用于现有 WPF 对象的对象模型，转义应该是不必要的。

#### 动画目标的 PropertyPath

动画的目标属性必须是使用的依赖项属性[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)或基元类型。 但是，类型中的目标属性和最终动画属性可以存在于不同的对象中。 对于动画，属性路径用于通过遍历属性值中的对象-属性关系，定义命名动画目标对象的属性和预期目标动画属性之间的连接。

##### 动画的一般对象-属性注意事项

有关一般动画概念的详细信息，请参阅[情节提要概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/storyboards-overview)和[动画概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/animation-overview)。

值类型或要进行动画处理的属性必须是[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)类型或基元。 开始路径的属性必须解析为存在于指定的依赖属性的名称[TargetName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard.targetname)类型。

为了支持克隆进行动画处理[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)已冻结，由指定的对象[TargetName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard.targetname)必须是[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)或[FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement)派生的类。

##### 目标对象上的单个属性

```xml
<animation Storyboard.TargetProperty="propertyName" .../>  
```

`propertyName` 必须解析为存在于指定的依赖属性的名称[TargetName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard.targetname)类型。

##### 间接属性目标设定

```xml
<animation Storyboard.TargetProperty="propertyName.propertyName2" .../>  
```

`propertyName` 必须是一个属性，它可以是[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)值类型或基元，存在于指定[TargetName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard.targetname)类型。

`propertyName2` 必须为依赖属性的名称，该属性存在于作为 `propertyName` 值的对象中。 换而言之，`propertyName2`作为依赖属性的类型上必须存在`propertyName` [PropertyType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.propertytype)。

因为应用了样式和模板，所以间接设定动画的目标是必要的。 为了设定动画的目标，您需要[TargetName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard.targetname)上的目标对象，并且名称由[X:name](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-name-directive)或[Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.name)。 虽然模板和样式元素也可以有名称，但这些名称仅在样式和模板的命名范围内有效。 （如果模板和样式与应用程序标记共享命名范围，则名称不唯一。 样式和模板的确在实例之间共享，并将保留重复名称。）因此，如果要进行动画处理的元素的各个属性来自样式或模板，则需要从不是来自样式模板的命名元素实例开始，然后将样式或模板可视化树设定为目标，以到达要进行动画处理的属性。

例如，[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.background)的属性[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)是一个完整[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)(实际上[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)) 来自主题模板。 若要进行动画处理[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)完全，则需要 BrushAnimation (可能是一个用于每个[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)类型) 并不存在此类的类型。 若要对一个画笔进行动画处理，而是进行动画处理的特定属性[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)类型。 您需要获得[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)到其[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush.color)应用[ColorAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.coloranimation)存在。 本示例的属性路径是 `Background.Color`。

##### 附加属性

```xml
<animation Storyboard.TargetProperty="(ownerType.propertyName)" .../>  
```

括号指示此属性在[PropertyPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertypath)应使用部分限定构造。 可以使用 XML 命名空间来查找类型。 `ownerType`搜索类型XAML处理器有权访问，通过[XmlnsDefinitionAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.xmlnsdefinitionattribute)中每个程序集的声明。 大部分应用程序都具有映射到http://schemas.microsoft.com/winfx/2006/xaml/presentation 命名空间的默认 XML 命名空间，因此通常仅有自定义类型或该命名空间之外的类型才需要前缀。 `propertyName` 必须解析为 `ownerType` 中存在的属性名称。 为指定的属性`propertyName`必须是[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)。 （所有 WPF 附加属性都实现为依赖属性，因此该问题仅与自定义附加属性相关。）

##### 索引器

```xml
<animation Storyboard.TargetProperty="propertyName.propertyName2[index].propertyName3" .../>  
```

大多数依赖项属性或[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)类型不支持索引器。 因此，动画路径中唯一使用索引器的地方是在用于启动命名目标上的链的属性与最终动画属性之间的中间位置。 在提供的语法中，为 `propertyName2`。 例如，索引器使用情况可能是如果中间属性是一个集合，如有必要[TransformGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transformgroup)，在属性路径，如`RenderTransform.Children[1].Angle`。

#### 代码中的 PropertyPath

代码的使用情况[PropertyPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertypath)，包括如何构建[PropertyPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertypath)，将的参考主题中所述[PropertyPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertypath)。

一般情况下，[PropertyPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertypath)设计为使用两个不同的构造函数，另一个用于绑定用法和最简单的动画用法，一个用于复杂动画用法。 使用[PropertyPath(Object)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertypath.-ctor#System_Windows_PropertyPath__ctor_System_Object_)签名对绑定用法，其中对象一个字符串。 使用[PropertyPath(Object)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertypath.-ctor#System_Windows_PropertyPath__ctor_System_Object_)单步动画路径，其中对象是签名[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)。 使用[PropertyPath(String, Object[\])](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertypath.-ctor#System_Windows_PropertyPath__ctor_System_String_System_Object___)复杂动画的签名。 后一种构造函数使用第一个参数的令牌字符串，以及在该令牌字符串中填充位置的对象的数组，以定义属性路径关系。

### [PresentationOptions:Freeze Attribute](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/presentationoptions-freeze-attribute)

集[IsFrozen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.isfrozen)状态变为`true`上包含[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)元素。 默认行为[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)而无需`PresentationOptions:Freeze`指定的属性是[IsFrozen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.isfrozen)是`false`加载时间和依赖于一般[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)在运行时的行为。

#### XAML 属性用法

```
<object  
  xmlns:PresentationOptions="http://schemas.microsoft.com/winfx/2006/xaml/presentation/options"  
  xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"  
  mc:Ignorable="PresentationOptions">  
    <freezableElement PresentationOptions:Freeze="true"/>  
</object>  
```

#### XAML 值

|                       |                                                              |
| --------------------- | ------------------------------------------------------------ |
| `PresentationOptions` | XML 命名空间前缀，这可以是任何有效的前缀字符串，每个 XML 1.0 规范。 前缀`PresentationOptions`用于标识此文档中使用。 |
| `freezableElement`    | 实例化任何元素派生的类[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)。 |

#### 备注

`Freeze`属性是唯一的属性或其他编程元素中定义`http://schemas.microsoft.com/winfx/2006/xaml/presentation/options`XML 命名空间。 `Freeze`具体来说，以便可以将其指定为可忽略，使用此特殊的命名空间中存在的属性[mc: Ignorable 特性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/mc-ignorable-attribute)作为根元素声明的一部分。 原因，`Freeze`必须是可以忽略是因为并非所有XAML处理器实现可冻结[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)在加载时; 此功能不是属于XAML规范。

处理的能力`Freeze`属性专门的内置XAML处理器，用于处理XAML为编译的应用程序。 该属性不受任何类和属性语法不可扩展或可修改。 如果要实现您自己XAML处理器可以选择并行的冻结行为WPFXAML处理器处理时`Freeze`特性，可以在[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)在加载时的元素。

任何值`Freeze`特性，除`true`（不区分大小写） 生成的负载时错误。 (指定`Freeze`属性作为`false`不是错误，但这已经是默认值，因此将设置为`false`不执行任何操作)。

## [Markup Compatibility (mc:) Language Features](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/markup-compatibility-mc-language-features)

### [mc:Ignorable Attribute](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/mc-ignorable-attribute)

指定哪些XML可能会忽略在标记文件中遇到的命名空间前缀XAML处理器。 `mc:Ignorable`属性支持标记兼容性，对自定义的命名空间映射以及XAML版本控制。

#### XAML 特性用法 （单个前缀）

```
<object  
  xmlns:ignorablePrefix="ignorableUri"  
  xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"  
  mc:Ignorable="ignorablePrefix"...>  
    <ignorablePrefix1:ThisElementCanBeIgnored/>  
</object>  
```

#### XAML 特性用法 （两个前缀）

```
<object  
  xmlns:ignorablePrefix1="ignorableUri"  
  xmlns:ignorablePrefix2="ignorableUri2"  
  xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"  
  mc:Ignorable="ignorablePrefix1 ignorablePrefix2"...>  
    <ignorablePrefix1:ThisElementCanBeIgnored/>  
</object>  
```

#### XAML 值

|                                              |                                                              |
| -------------------------------------------- | ------------------------------------------------------------ |
| *ignorablePrefix、 ignorablePrefix1，等等。* | 任何有效的前缀字符串，每个 XML 1.0 规范。                    |
| *ignorableUri*                               | 任何有效的 URI 指定一个命名空间，每个 XML 1.0 规范。         |
| *ThisElementCanBeIgnored*                    | 元素，可以忽略可扩展应用程序标记语言 (XAML)处理器实现中，如果基础类型不能被解析。 |

#### 备注

`mc` XML命名空间前缀是映射时要使用的建议的前缀约定XAML兼容性命名空间http://schemas.openxmlformats.org/markup-compatibility/2006。

元素或属性的元素名称的前缀部分被视为`mc:Ignorable`不会引发错误时由处理XAML处理器。 如果该属性不能解析为基础类型或编程构造，则忽略该元素。 但是请注意，被忽略的元素仍可能生成其他分析错误，因为将会不处理该元素的负面影响的其他元素要求。 例如，特定元素内容模型可能需要一个子元素，但指定的子元素是否在`mc:Ignorable`前缀和指定的子元素不能被解析为类型，则XAML处理器可能引发错误。

`mc:Ignorable` 仅适用于命名空间映射为标识符字符串。 `mc:Ignorable` 不适用于命名空间映射到指定的程序集中CLR命名空间和程序集 （或与程序集的当前可执行文件的默认值）。

如果要实现XAML处理器，处理器实现不能引发分析或处理的任何元素或属性由标识为前缀限定的类型解析错误`mc:Ignorable`。 但仍可以引发作为是辅助的结果无法加载或处理，如前面给出的一个子元素示例某元素的异常。

默认情况下，XAML处理器将忽略已忽略元素中的内容。 但是，可以指定其他属性， [mc: processcontent 特性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/mc-processcontent-attribute)、 需要继续的处理中忽略了元素的下一个可用的父元素的内容。

可以使用一个或多个空白字符作为分隔符，例如在属性中指定多个前缀： `mc:Ignorable="ignore1 ignore2"`。

http://schemas.openxmlformats.org/markup-compatibility/2006命名空间定义其他元素和属性的未记录的此区域内软件开发工具包 (SDK)。 有关详细信息，请参阅[XML 标记兼容性规范](https://docs.microsoft.com/zh-cn/office/open-xml/introduction-to-markup-compatibility#markup-compatibility-in-the-open-xml-file-formats-specification)。

### [mc:ProcessContent Attribute](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/mc-processcontent-attribute)

指定哪些XAML元素仍应具有处理相关的父元素的内容，即使可能忽略的直接父元素XAML由于指定的处理器[mc: Ignorable 特性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/mc-ignorable-attribute). `mc:ProcessContent`属性支持标记兼容性，对自定义的命名空间映射以及XAML版本控制。

#### XAML 属性用法

```
<object  
  xmlns:ignorablePrefix="ignorableUri"  
  xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"  
  mc:Ignorable="ignorablePrefix"...  
  mc:ProcessContent="ignorablePrefix:ThisElementCanBeIgnored"  
>  
    <ignorablePrefix:ThisElementCanBeIgnored>  
        [content]  
    </ignorablePrefix:ThisElementCanBeIgnored>  
</object>  
```

#### XAML 值

|                           |                                                              |
| ------------------------- | ------------------------------------------------------------ |
| *ignorablePrefix*         | 任何有效的前缀字符串，每个 XML 1.0 规范。                    |
| *ignorableUri*            | 任何有效的 URI 指定一个命名空间，每个 XML 1.0 规范。         |
| *ThisElementCanBeIgnored* | 元素，可以忽略可扩展应用程序标记语言 (XAML)处理器实现中，如果基础类型不能被解析。 |
| *[content]*               | *ThisElementCanBeIgnored*被标记为可忽略。 如果处理器忽略该元素， *[内容]* 由处理*对象*。 |

#### 备注

默认情况下，XAML处理器将忽略已忽略元素中的内容。 可以指定特定元素由`mc:ProcessContent`，和一个XAML处理器将继续处理中忽略了元素的内容。 这通常可在内容嵌套在多个标记，在至少一个可以忽略，并在至少一个不被可忽略。

可以使用空间分隔符，例如在特性中指定多个前缀： `mc:ProcessContent="ignore:Element1 ignore:Element2"`。

http://schemas.openxmlformats.org/markup-compatibility/2006命名空间定义其他元素和属性的未记录的此区域内软件开发工具包 (SDK)。 有关详细信息，请参阅[XML 标记兼容性规范](https://go.microsoft.com/fwlink/?LinkId=73824)。