# [Events](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/events-wpf)

Windows Presentation Foundation (WPF) 提供一组服务，这些服务可用于扩展 公共语言运行时 (CLR) 属性的功能。 这些服务通常统称为 WPF 属性系统。 由 WPF 属性系统支持的属性称为依赖属性。

## 本节内容

[依赖项属性概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-properties-overview)
[附加属性概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/attached-properties-overview)
[依赖属性回调和验证](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-callbacks-and-validation)
[自定义依赖属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/custom-dependency-properties)
[依赖属性元数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-metadata)
[框架属性元数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/framework-property-metadata)
[依赖项属性值优先级](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-value-precedence)
[只读依赖项属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/read-only-dependency-properties)
[属性值继承](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/property-value-inheritance)
[依赖属性的安全性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-security)
[DependencyObject 的安全构造函数模式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/safe-constructor-patterns-for-dependencyobjects)
[集合类型依赖属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/collection-type-dependency-properties)
[XAML 加载和依赖项属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-loading-and-dependency-properties)
[帮助主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/properties-how-to-topics)

## [Routed Events Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/routed-events-overview)

Windows Presentation Foundation (WPF) 提供一组服务，这些服务可用于扩展类型的[属性](https://docs.microsoft.com/zh-cn/dotnet/standard/base-types/common-type-system#Properties)的功能。 这些服务通常统称为 WPF 属性系统。 由 WPF 属性系统支持的属性称为依赖属性。 本概述介绍 WPF 属性系统以及依赖属性的功能。 这包括如何在 XAML 和在代码中使用现有依赖属性。 本概述还介绍依赖属性所特有的方面（如依赖属性元数据），并说明如何在自定义类中创建自己的依赖属性。

### 系统必备

本主题假设你在 .NET 类型系统和面向对象的编程方面有一些基础知识。 为了能理解本主题中的示例，还应了解 XAML 并知道如何编写 WPF 应用程序。 有关详细信息，请参见[演练：我第一个 WPF 桌面应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/getting-started/walkthrough-my-first-wpf-desktop-application)。

### 依赖属性和 CLR 属性

在 WPF 中，属性通常公开为标准 .NET [属性](https://docs.microsoft.com/zh-cn/dotnet/standard/base-types/common-type-system#Properties)。 在基本级别，可以直接与这些属性交互，而不必了解它们是以依赖属性的形式实现的。 但是，应当熟悉 WPF 属性系统的部分或全部功能，以便利用这些功能。

依赖属性的用途在于提供一种方法来基于其他输入的值计算属性值。 这些其他输入可能包括系统属性（如主题和用户首选项）、实时属性确定机制（如数据绑定和动画/情节提要）、重用模板（如资源和样式）或者通过与元素树中其他元素的父子关系来公开的值。 另外，可以通过实现依赖属性来提供独立验证、默认值、监视其他属性的更改的回叫以及可以基于可能的运行时信息来强制指定属性值的系统。 派生类还可以通过重写依赖属性元数据（而不是重写现有属性的实际实现或者创建新属性）来更改现有属性的某些具体特征。

在 SDK 参考中，可以根据某个属性的托管引用页上是否存在“依赖属性信息”部分来确定该属性是否为依赖属性。“依赖属性信息”部分包括一个指向该依赖属性的 [DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty) 标识符字段的链接，还包括一个为该属性设置的元数据选项列表、每个类的重写信息以及其他详细信息。

### 依赖属性支持 CLR 属性

依赖属性和 WPF 属性系统通过提供一个支持属性的类型来扩展属性功能，这是使用专用字段支持该属性的标准模式的替代实现方法。 此类型的名称为 [DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)。 定义 WPF 属性系统的另一个重要类型是 [DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)。 [DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject) 定义可以注册和拥有依赖属性的基类。

下面列出了与依赖属性一起使用的术语：

- **依赖项属性：** 一个属性，它由支持[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)。
- **依赖项属性标识符：** 一个[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)实例，这是注册依赖属性时，获取作为返回值，然后存储为类的静态成员。 对于与 WPF 属性系统交互的许多 API，此标识符用作一个参数。
- **CLR"包装器":** 实际 get 和 set 实现的属性。 这些实现通过在 [GetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.getvalue) 和 [SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue) 调用中使用依赖属性标识符来并入依赖属性标识符，从而使用 WPF 属性系统为属性提供支持。

下面的示例定义 `IsSpinning` 依赖属性，并说明 [DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty) 标识符与它所支持的属性之间的关系。

```csharp
public static readonly DependencyProperty IsSpinningProperty = 
    DependencyProperty.Register(
    "IsSpinning", typeof(Boolean),
    typeof(MyCode)
    );
public bool IsSpinning
{
    get { return (bool)GetValue(IsSpinningProperty); }
    set { SetValue(IsSpinningProperty, value); }
}
```

属性及其支持性 [DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty) 字段的命名约定非常重要。 字段总是与属性同名，但其后面追加了 `Property` 后缀。 有关此约定及其原因的详细信息，请参阅[自定义依赖属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/custom-dependency-properties)。

### 设置属性值

可以在代码或 XAML 中设置属性。

#### 在 XAML 中设置属性值

下面的 XAML 示例将按钮的背景色指定为红色。 此示例演示这样一种情况：在所生成的代码中，WPF XAML 分析器将 XAML 属性的简单字符串值类型转换为 WPF 类型（一个 [Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.color)，通过 [SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush) 实现）。

```xaml
<Button Background="Red" Content="Button!"/>
```

XAML 支持多种设置属性的语法格式。 要对特定的属性使用哪种语法取决于该属性所使用的值类型以及其他因素（例如，是否存在类型转换器）。 有关属性设置的 XAML 语法的详细信息，请参阅 [XAML 概述 (WPF)](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-overview-wpf) 和 [XAML 语法详述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-syntax-in-detail)。

作为非属性语法的示例，下面的 XAML 示例显示了另一种按钮背景。 这一次不是设置简单的纯色，而是将背景设置为图像，用一个元素表示该图像并将该图像的源指定为嵌套元素的属性。 这是属性元素语法的示例。

```xaml
<Button Content="Button!">
  <Button.Background>
    <ImageBrush ImageSource="wavy.jpg"/>
  </Button.Background>
</Button>
```

#### 在代码中设置属性

在代码中设置依赖属性值通常只是调用由 CLR“包装器”公开的 set 实现。

```csharp
Button myButton = new Button();
myButton.Width = 200.0;
```

获取属性值实质上也是在调用 get“包装器”实现：

```csharp
double whatWidth;
whatWidth = myButton.Width;
```

还可以直接调用属性系统 API [GetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.getvalue) 和 [SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue)。 如果使用的是现有属性，则上述操作通常不是必需的（使用包装器会更方便，并能够更好地向开发人员工具公开属性），但是在某些情况下适合直接调用 API。

还可以在 XAML 中设置属性，然后通过代码隐藏在代码中访问这些属性。 有关详细信息，请参阅 [WPF 中的代码隐藏和 XAML](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/code-behind-and-xaml-in-wpf)。

### 由依赖属性提供的属性功能

依赖属性提供用来扩展属性功能的功能，这与字段支持的属性相反。 通常，此类功能代表或支持以下特定功能之一：

- [资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-properties-overview#resources)
- [数据绑定](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-properties-overview#data-binding)
- [样式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-properties-overview#styles)
- [动画](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-properties-overview#animations)
- [元数据重写](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-properties-overview#metadata-overrides)
- [属性值继承](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-properties-overview#property-value-inheritance)
- [WPF 设计器集成](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-properties-overview#wpf-designer-integration)

#### 资源

依赖属性值可以通过引用资源来设置。 资源通常指定为页面根元素或应用程序的 `Resources` 属性值（通过这些位置可以非常方便地访问资源）。 以下示例演示如何定义 [SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush) 资源。

```xaml
<DockPanel.Resources>
  <SolidColorBrush x:Key="MyBrush" Color="Gold"/>
</DockPanel.Resources>
```

在定义该资源之后，可以引用该资源并使用它来提供属性值：

```xaml
<Button Background="{DynamicResource MyBrush}" Content="I am gold" />
```

这个特定资源称为 [DynamicResource 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dynamicresource-markup-extension)（在 WPF XAML 中，可以使用静态或动态资源引用）。 若要使用动态资源引用，必须设置为依赖属性，因此它专门是由 WPF 属性系统启用的动态资源引用用法。 有关详细信息，请参阅 [XAML 资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-resources)。

> 资源被视为本地值，这意味着，如果设置另一个本地值，该资源引用将被消除。 有关详细信息，请参阅[依赖属性值优先级](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-value-precedence)。

#### 数据绑定

依赖属性可以通过数据绑定来引用值。 数据绑定通过特定标记扩展语法（在 XAML 中）或 [Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding) 对象（在代码中）起作用。 使用数据绑定，最终属性值的确定将延迟到运行时，在运行时，将从数据源获取属性值。

以下示例使用在 XAML 中声明的绑定来设置 [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) 的 [Content](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.content) 属性。 该绑定使用继承的数据上下文和 [XmlDataProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.xmldataprovider) 数据源（未显示）。 绑定本身通过数据源中的 [XPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.xpath) 指定所需的源属性。

```xaml
<Button Content="{Binding XPath=Team/@TeamName}"/>
```

> 绑定被视为本地值，这意味着，如果设置另一个本地值，该绑定将被消除。 有关详细信息，请参阅[依赖属性值优先级](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-value-precedence)。

为了生成数据绑定操作的 [DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject) 源属性值的更改通知，依赖属性或 [DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject) 类本身不支持[INotifyPropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.inotifypropertychanged)。 有关如何创建要用在数据绑定中并且可以向数据绑定目标报告变化的属性的详细信息，请参阅[数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview)。

#### 样式

样式和模板是使用依赖属性的两个主要激发方案。 在设置定义应用程序用户界面 (UI) 的属性时，样式尤其有用。在 XAML 中，通常将样式定义为资源。 样式与属性系统交互，因为它们通常包含特定属性的“资源库”，以及基于另一个属性的实时值更改属性值的“触发器”。

以下示例创建非常简单的样式（该样式在 [Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.resources) 字典中定义，未显示），然后将该样式直接应用于 [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) 的 [Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.style) 属性。 样式中的资源库将带样式 [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) 的 [Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background) 属性设置为绿色。

```xaml
<Style x:Key="GreenButtonStyle">
  <Setter Property="Control.Background" Value="Green"/>
</Style>
```

```xaml
<Button Style="{StaticResource GreenButtonStyle}">I am green!</Button>
```

有关详细信息，请参阅[样式设置和模板化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/styling-and-templating)。

#### Animations

可以对依赖属性进行动画处理。 在应用和运行动画时，经过动画处理的值的操作优先级高于该属性以其他方式具有的任何值（如本地值）。

以下示例在 [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) 属性上对 [Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background) 进行动画处理（从技术上讲，通过使用属性元素语法将空白 [SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush) 指定为 [Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background) 来对 [Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background) 进行动画处理，然后该 [SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush) 的 [Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush.color) 属性就是直接动画处理过的属性）。

```xaml
<Button>I am animated
  <Button.Background>
    <SolidColorBrush x:Name="AnimBrush"/>
  </Button.Background>
  <Button.Triggers>
    <EventTrigger RoutedEvent="Button.Loaded">
      <BeginStoryboard>
        <Storyboard>
          <ColorAnimation
            Storyboard.TargetName="AnimBrush" 
            Storyboard.TargetProperty="(SolidColorBrush.Color)"
            From="Red" To="Green" Duration="0:0:5" 
            AutoReverse="True" RepeatBehavior="Forever" />
        </Storyboard>
      </BeginStoryboard>
    </EventTrigger>
  </Button.Triggers>
</Button>
```

有关对属性进行动画处理的详细信息，请参阅[动画概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/animation-overview)和[情节提要概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/storyboards-overview)。

#### 元数据重写

在从最初注册依赖属性的类派生时，可以通过重写依赖属性的元数据来更改该属性的某些行为。 重写元数据依赖于 [DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty) 标识符。 重写元数据不需要重新实现属性。 元数据的更改由属性系统在本机处理；对于所有从基类继承的属性，每个类都有可能基于每个类型保留元数据。

以下示例重写依赖属性 [DefaultStyleKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.defaultstylekey) 的元数据。 重写此特定依赖属性的元数据是某个实现模式的一部分，该模式创建可以使用主题中的默认样式的控件。

```csharp
public class SpinnerControl : ItemsControl
{
    static SpinnerControl()
    {
        DefaultStyleKeyProperty.OverrideMetadata(
            typeof(SpinnerControl), 
            new FrameworkPropertyMetadata(typeof(SpinnerControl))
        );
    }
}
```

有关替代或获取属性元数据的详细信息，请参阅[依赖属性元数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-metadata)。

#### 属性值继承

元素可以从其在对象树中的父级继承依赖属性的值。

> 属性值继承行为并未针对所有依赖属性在全局启用，因为继承的计算时间确实会对性能产生一定的影响。 属性值继承通常只有在特定方案指出适合使用属性值继承时才对属性启用。 可以通过在 SDK 参考中查看某个依赖属性的**依赖属性信息**部分，来确定该依赖属性是否继承属性值。

下面的示例演示一个绑定，并设置指定绑定（在前面的绑定示例中未显示出来）的源的 [DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext) 属性。 子对象中的任何后续绑定都无需指定源，它们可以使用父对象 [StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel) 中 [DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext) 的继承值。 （或者，子对象可以选择直接在 [Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding) 中指定自己的 [DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext) 或 [Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.source)，并且有意不将继承值用于其绑定的数据上下文。）

```xaml
<StackPanel Canvas.Top="50" DataContext="{Binding Source={StaticResource XmlTeamsSource}}">
  <Button Content="{Binding XPath=Team/@TeamName}"/>
</StackPanel>
```

有关详细信息，请参阅[属性值继承](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/property-value-inheritance)。

#### WPF 设计器集成

如果自定义控件具有实现为依赖属性的属性，则它会收到相应的适用于 Visual Studio 的 WPF 设计器支持。 一个示例就是能够在“属性”窗口中编辑直接依赖属性和附加依赖属性。 有关详细信息，请参阅[控件创作概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/control-authoring-overview)。

### 依赖项属性值优先级

获取依赖属性的值时，获得的值可能是通过参与 WPF 属性系统的其他任一基于属性的输入而在该属性上设置的。由于存在依赖属性值优先级，使得属性获取值的方式的各种方案得以按可预测的方式交互。

请看下面的示例。 该示例包含适用于所有按钮及其 [Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background) 属性的样式，但也会指定一个具有本地设置的 [Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background) 值的按钮。

> SDK 文档在讨论依赖属性时有时会使用“本地值”或“本地设置的值”等术语。 本地设置的值是指在代码中直接为对象实例设置的属性值，或者在 XAML 中设置为元素特性的属性值。

原则上，对于第一个按钮，该属性会设置两次，但是仅应用一个值，即具有最高优先级的值。 本地设置的值具有最高优先级（对于正在运行的动画除外，但是在本示例中没有应用动画），因此，对于第一个按钮的背景将使用本地设置的值，而不使用样式资源库值。 第二个按钮没有本地值（而且没有其他比样式资源库优先级更高的值），因此该按钮中的背景来自样式资源库。

```xaml
<StackPanel>
  <StackPanel.Resources>
    <Style x:Key="{x:Type Button}" TargetType="{x:Type Button}">
     <Setter Property="Background" Value="Red"/>
    </Style>
  </StackPanel.Resources>
  <Button Background="Green">I am NOT red!</Button>
  <Button>I am styled red</Button>
</StackPanel>
```

#### 为什么存在依赖属性优先级？

通常，你不会希望总是应用样式，而且不希望样式遮盖单个元素的哪怕一个本地设置值（否则，通常很难使用样式或元素）。 因此，来自样式的值的操作优先级低于本地设置的值。 有关依赖属性以及它的有效值可能来自何处的更完整列表，请参阅[依赖属性值优先级](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-value-precedence)。

> 在 WPF 元素定义了许多非依赖属性的属性。 一般说来，只有在需要支持至少一个由属性系统启用的方案（数据绑定、样式、动画、默认值支持、继承、附加属性或失效）时，才将属性实现为依赖属性。

### 了解有关依赖属性的详细信息

- 附加属性是一种支持 XAML 中的专用语法的属性。 附加属性通常与公共语言运行时 (CLR) 属性不具有 1:1 对应关系，而且不一定是依赖属性。 附加属性的典型用途是使子元素可以向其父元素报告属性值，即使父元素和子元素的类成员列表中均没有该属性也是如此。 一种主要情况是使子元素能够告知父元素应如何在 UI 中呈现它们；有关示例，请参阅 [Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.dock) 或 [Left](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas.left)。 有关详细信息，请参阅[附加属性概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/attached-properties-overview)。
- 组件开发人员或应用程序开发人员可能希望创建自己的依赖属性，以便实现数据绑定或样式支持之类的功能，或者实现对失效和值强制的支持。 有关详细信息，请参阅[自定义依赖属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/custom-dependency-properties)。
- 通常，依赖属性应当被视为公共属性，这些公共属性可以由任何具有实例访问权限的调用方访问，或至少可被这样的调用方发现。 有关详细信息，请参阅[依赖属性的安全性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-security)。

## [Attached Events Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/attached-events-overview)

附加属性是由 XAML 定义的概念。 附加属性旨在用作可在任何对象上设置的一类全局属性。 在 Windows Presentation Foundation (WPF) 中，附加属性通常定义为没有常规属性“包装器”的依赖性属性的专用形式。

### 系统必备组件

本主题假定你从 Windows Presentation Foundation (WPF) 类的现有依赖属性的使用者角度了解依赖属性，并且已阅读[依赖属性概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-properties-overview)。 若要遵循本主题中的示例，您应了解 XAML 并知道如何编写 WPF 应用程序。

### 为什么使用附加的属性

附加属性的一个用途是允许不同的子元素为实际在父元素中定义的属性指定唯一值。 此方案的一个具体应用是，让子元素通知父元素它们在 用户界面 (UI) 中的呈现方式。 一个示例是[DockPanel.Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.dock)属性。 [DockPanel.Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.dock)作为附加属性创建属性，因为这为了在中包含的元素上设置[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)，而不是在[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)本身。 [DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)类定义了静态[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)名为字段[DockProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.dockproperty)，然后提供[GetDock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.getdock)和[SetDock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.setdock)附加属性的方法作为公共访问器。

### XAML 中的附加的属性

在 XAML 中，可以使用语法 AttachedPropertyProvider.PropertyName 来设置附加属性

下面是举例说明如何设置[DockPanel.Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.dock)在 XAML 中：

```xaml
<DockPanel>
  <CheckBox DockPanel.Dock="Top">Hello</CheckBox>
</DockPanel>
```

请注意，有些类似于静态属性; 使用情况始终引用类型[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)，拥有并注册附加的属性，而不是引用通过名称指定的任何实例。

此外，由于 XAML 中的附加属性是在标记中设置的属性，因此，只有设置操作具有相关性。 尽管存在一些用于比较值的间接机制（如在样式中触发），但无法直接在 XAML 中直接获取属性（有关详细信息，请参阅[样式设置和模板化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/styling-and-templating)）。

#### WPF 中的附加属性实现

在Windows Presentation Foundation (WPF)，大部分与 UI 表示形式相关的 WPF 类型存在的附加属性实现为依赖属性。 附加的属性是一个 XAML 概念，而依赖项属性是 WPF 概念。 由于 WPF 附加属性是依赖项属性，它们支持依赖属性概念，如属性元数据和属性元数据的默认值。

### 如何使用附加的属性所属类型

尽管可以在任何对象上设置附加属性，但这并不自动意味着设置该属性会产生实际的结果，或者该值会被其他对象使用。 通常，附加属性是为了使来自各种可能的类层次结构或逻辑关系的对象都可以向用于定义附加属性的类型报告公用信息。 定义附加属性的类型通常采用以下模型之一：

- 设计定义附加属性的类型，以便它可以是将为附加属性设置值的元素的父元素。 随后，该类型将在内部逻辑中对照某些对象树结构循环访问其子对象，获取值，并以某种方式作用于这些值。
- 定义附加属性的类型将用作各种可能的父元素和内容模型的子元素。
- 定义附加属性的类型表示一项服务。 其他类型为该附加属性设置值。 然后，当在服务的上下文中计算设置该属性的元素时，将通过服务类的内部逻辑获取附加属性的值。

#### 父级定义的附加属性示例

其中 WPF 定义附加的属性的最典型方案是行为的父元素支持子元素集合，并且还实现了一种行为细节的单独报告每个子元素。

[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel) 定义[DockPanel.Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.dock)附加属性，并[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)作为其呈现逻辑的一部分具有类级别的代码 (具体而言，[MeasureOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.measureoverride)和[ArrangeOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.arrangeoverride))。 一个[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)实例将始终检查是否任何其直接子元素设置的值[DockPanel.Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.dock)。 如果已设置，这些值将变为应用于该特定子元素的呈现逻辑的输入。 嵌套[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)实例都处理自己的直接子元素集合，但该行为是特定于实现的如何[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)进程[DockPanel.Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.dock)值。 理论上，可以有影响直接父级之外的元素的附加属性。 如果[DockPanel.Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.dock)未包含任何元素上设置附加的属性[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)父元素不作用它、 任何错误或异常引发。 这只是意味着设置全局属性值，但它有没有当前[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)无法使用该信息的父级。

### 在代码中的附加的属性

WPF 中的附加的属性不具有典型CLR用于简化 get/set 访问的"包装"方法。 这是因为附加属性不是必须属于设置它的实例的 CLR 命名空间的一部分。 但是，分析 XAML 时，XAML 处理器必须能够设置这些值。 若要支持的有效的附加的属性用法，附加属性的所有者类型必须实现专用访问器方法在窗体**Get_PropertyName_** 并**Set_PropertyName_**。 这些专用访问器方法对在代码中设置附加属性也很有帮助。 从代码的角度来看，附加属性类似于具有方法访问器而不是属性访问器的支持字段，且支持字段可在任何对象上存在，无需专门定义。

下面的示例演示如何在代码中设置附加属性。 在此示例中，`myCheckBox`的一个实例[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)类。

```csharp
DockPanel myDockPanel = new DockPanel();
CheckBox myCheckBox = new CheckBox();
myCheckBox.Content = "Hello";
myDockPanel.Children.Add(myCheckBox);
DockPanel.SetDock(myCheckBox, Dock.Top);
```

类似于 XAML 用例中，如果`myCheckBox`不已添加的子元素作为`myDockPanel`由第三行代码，第四行代码不会引发异常，但属性值不会与交互[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)父级，因此将不执行任何操作。 仅[DockPanel.Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.dock)值且存在的子元素上设置[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)父元素将导致呈现的应用程序中有效的行为。 （在这种情况下，可以设置附加属性，然后附加到树。或者，可以先附加到该树中，然后设置附加属性。 这两种操作顺序结果都相同。）

### 附加的属性元数据

注册该属性时[FrameworkPropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata)设置为指定的属性，如的属性会影响呈现、 度量等特征。 附加属性的元数据通常与依赖属性上的元数据基本上都相同。 如果在附加属性元数据替代中指定默认值，该值将成为替代类实例上显式附加属性的默认值。 具体而言，当某些进程通过该属性的 `Get` 方法访问器请求附加属性值，并指定在其中指定元数据的类的示例时，将报告默认值，而不会设置该附加属性的值。

如果希望对属性启用属性值继承，应使用附加属性，而不是非附加的依赖属性。 有关详细信息，请参阅[属性值继承](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/property-value-inheritance)。

### 自定义附加属性

#### 何时创建附加的属性

当需要有一个可用于定义类之外的其他类的属性设置机制时，建议创建附加属性。 对于这一情况，最常见的方案是布局。 现有布局属性的示例有[DockPanel.Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.dock)， [Panel.ZIndex](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.zindex)，和[Canvas.Top](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas.top)。 这里启用的方案是，作为布局控制元素的子元素存在的元素能够分别向其布局父级元素表达布局要求，其中每个元素都设置一个被父级定义为附加属性的属性值。

使用附加属性的另一种情况是，你的类表示一种服务，且你希望类能够以更透明的方式继承该服务。

但另一个情况是收到 Visual Studio WPF 设计器支持，例如**属性**窗口编辑。 有关详细信息，请参阅[控件创作概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/control-authoring-overview)。

如前文所述，如果想要使用属性值继承，你应该注册为附加属性。

#### 如何创建附加的属性

如果您的类定义附加的属性严格使用其他类型，则不需要从派生类[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)。 但需要派生自[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)如果遵循使附加的属性也是依赖项属性的整体 WPF 模型。

将附加的属性定义为依赖属性通过声明`public static readonly`类型的字段[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)。 使用的返回值定义此字段[RegisterAttached](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.registerattached)方法。 字段名称必须匹配附加的属性名称，且追加字符串`Property`，以遵循命名标识字段及其它们所表示的属性的已建立的 WPF 模式。 附加的属性提供程序还必须提供静态**Get_PropertyName_**并**Set_PropertyName_** 方法访问器作为附加属性。 如果不这样做将导致属性系统无法使用附加的属性。

> 如果省略附加的属性的 get 访问器，在属性上的数据绑定不会在设计工具，如 Visual Studio 和 Expression Blend 中。

#### Get 访问器

签名**Get_PropertyName_** 访问器必须是：

```
public static object GetPropertyName(object target)
```

- `target` 对象在实现中可以指定为更具体的类型。 例如，[DockPanel.GetDock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.getdock)方法的类型参数作为[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)，因为附加的属性只是在上设置[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)实例。
- 返回值在实现中可以指定为更具体的类型。 例如，[GetDock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.getdock)方法将其作为类型[Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dock)，因为值只能设置为该枚举。

#### Set 访问器

签名**Set_PropertyName_** 访问器必须是：

```
public static void SetPropertyName(object target, object value)
```

- `target` 对象在实现中可以指定为更具体的类型。 例如，[SetDock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.setdock)方法将其作为类型[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)，因为附加的属性只是在上设置[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)实例。
- `value` 对象在实现中可以指定为更具体的类型。 例如，[SetDock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.setdock)方法将其作为类型[Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dock)，因为值只能设置为该枚举。 请记住，此方法的值是 XAML 加载器在标记中的附加属性用法中遇到附加属性时的输入。 该输入是在标记中指定为 XAML 属性值的值。 因此必须存在可用于你所使用的类型的类型转换、值序列化程序或标记扩展支持，以便可以从属性值（最终仅仅是一个字符串）创建相应的类型。

下面的示例显示了依赖关系属性注册 (使用[RegisterAttached](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.registerattached)方法)，并将**Get_PropertyName_** 并**Set_PropertyName_** 访问器。 在此示例中，附加属性名称为 `IsBubbleSource`。 因此，访问器必须名为 `GetIsBubbleSource` 和 `SetIsBubbleSource`。

```csharp
public static readonly DependencyProperty IsBubbleSourceProperty = DependencyProperty.RegisterAttached(
  "IsBubbleSource",
  typeof(Boolean),
  typeof(AquariumObject),
  new FrameworkPropertyMetadata(false, FrameworkPropertyMetadataOptions.AffectsRender)
);
public static void SetIsBubbleSource(UIElement element, Boolean value)
{
  element.SetValue(IsBubbleSourceProperty, value);
}
public static Boolean GetIsBubbleSource(UIElement element)
{
  return (Boolean)element.GetValue(IsBubbleSourceProperty);
}
```

#### 附加属性特性

WPF 定义了多个.NET Framework 特性，后者用于提供有关向反射进程和反射类型和属性的信息，例如设计器的典型用户的附加属性的信息。 由于附加属性的类型没有范围限制，因此设计者需要一种方法来避免用户查看全局列表时，看到使用 XAML 的特定技术实现中定义的所有附加属性。 .NET Framework 特性该 WPF 定义附加的属性可用于范围限定在属性窗口中，其中应显示给定的附加的属性的情况。 你还可考虑对自己的自定义附加属性应用这些特性。 有关 .NET Framework 特性 的用途和语法说明，请参阅相应的参考页面：

- [AttachedPropertyBrowsableAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.attachedpropertybrowsableattribute)
- [AttachedPropertyBrowsableForChildrenAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.attachedpropertybrowsableforchildrenattribute)
- [AttachedPropertyBrowsableForTypeAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.attachedpropertybrowsablefortypeattribute)
- [AttachedPropertyBrowsableWhenAttributePresentAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.attachedpropertybrowsablewhenattributepresentattribute)

### 了解更多关于附加属性

- 有关如何创建附加属性的详细信息，请参阅[注册附加属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-register-an-attached-property)。
- 有关依赖属性和附加属性的更多高级使用方案，请参阅[自定义依赖属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/custom-dependency-properties)。
- 还可将属性注册为附加属性和依赖属性，但仍需公开“包装器”实现。 在这种情况下，属性可在该元素上设置，也可通过 XAML 附加属性语法在任何元素上设置。 具有适当的方案的标准和附加用法的属性的一个示例是[FrameworkElement.FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)。

## [Object Lifetime Events](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/object-lifetime-events)

本主题介绍表示对象生存期（创建、使用和销毁）中的阶段的特定 WPF 事件。

### 系统必备

本主题假设你作为 Windows Presentation Foundation (WPF) 类的现有依赖属性的使用者已经对依赖属性有所了解，并且已经阅读了[依赖属性概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-properties-overview)主题。 若要理解本主题中的示例，还应当了解 可扩展应用程序标记语言 (XAML)（请参阅 [XAML 概述 (WPF)](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-overview-wpf)）并知道如何编写 WPF 应用程序。

### 对象生存期事件

Microsoft.NET Framework 托管代码中的所有对象都经过一组类似的生命周期、 创建、 使用和销毁的阶段。 许多对象还包括生命终止阶段，该阶段属于销毁阶段的一部分。 WPF 对象（更明确的说，WPF 标识为元素的视觉对象）还具有对象生命的一系列常见阶段。 WPF 编程和应用程序模型将这些阶段作为一系列事件公开。 WPF 中有四种与生存期事件有关的主要类型对象 - 即常规元素、窗口元素、导航宿主和应用程序对象。 窗口和导航宿主也都属于视觉对象（元素）这个较大的组。 本主题首先介绍所有元素的通用生存期事件，然后介绍应用于应用程序定义、窗口或导航宿主的更具针对性的生存期事件。

### 元素通用生存期事件

任何 WPF 框架级元素 (从派生[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)或[FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement)) 具有三个常见生存期事件： [Initialized](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.initialized)， [Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)，和[Unloaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.unloaded)。

#### Initialized

[Initialized](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.initialized) 首先引发，并大致对应于该对象的初始化通过其构造函数的调用。 由于事件为响应初始化而发生，因此可以确保对象的所有属性均已设置。 （动态资源或绑定等表达式用法除外；这些是不进行计算的表达式。）由于所有属性均都设置，要求的一系列[Initialized](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.initialized)首先，在元素树中最深层的元素的顺序出现时引发的标记中定义的嵌套元素似乎然后父直至根元素。 采用此顺序是鉴于父子关系和包容均为属性，因此在填充属性的子元素完全初始化前，父元素无法报告初始化。

当您编写处理程序以响应[Initialized](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.initialized)事件，必须考虑是围绕附加处理程序元素树 （逻辑树或可视化树） 中的所有其他元素已创建了，尤其是没有保证父元素。 成员变量可能为 null，或者基础绑定还未填充数据源（即使在表达式级别）。

#### 已加载

[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded) 接下来引发。 [Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)最终呈现之前但在布局系统已计算呈现所有必要的值之后引发事件。 [Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded) 需要一个元素包含在逻辑树已完成，并且连接到提供 HWND 和呈现图面的演示源。 标准数据绑定 （绑定到本地源，例如其他属性或直接定义的数据源） 将发生之前[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)。 可能已发生异步数据绑定（外部或动态源），但是根据其异步特性的定义不能保证已发生异步数据绑定。

通过该机制[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)引发事件不同于[Initialized](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.initialized)。 [Initialized](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.initialized)事件是元素的元素，而无需通过整个的元素树直接协调方式引发。 与此相反，[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)作为整个元素树 （具体而言，逻辑树） 协调的结果引发事件。 当在树中的所有元素都是在加载，它们都将被视为的状态[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)根元素上第一次发生事件。 [Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)然后每个子元素上连续引发事件。

> 这种行为看起来可能类似于路由事件的隧道。 但是，未将任何信息在事件之间传送。 每个元素始终有机会处理其[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)事件，并将事件数据标记为已处理已超出该元素不起作用。

#### 已卸载

[Unloaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.unloaded) 最后引发并由演示源或要删除的可视父级启动。 当[Unloaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.unloaded)引发并处理的事件源父元素 (由[Parent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.parent)属性) 或向上中逻辑或可视化树的任何给定的元素可能已经被取消设置，这意味着数据绑定、 资源引用并为其正常或最后一个已知的运行时间值不能设置样式。

### 生存期事件应用程序模型元素

构建在通用生存期事件的元素是以下应用程序模型元素： [Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)， [Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)， [Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)， [NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)，和[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)。 这些与特定用途相关的额外事件扩充了常见的生存期事件。 将在以下位置详细介绍这些内容：

- [Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)：[应用程序管理概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/application-management-overview)。
- [Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)：[WPF Windows 概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/wpf-windows-overview)。
- [Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)，和[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame):[导航概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-overview)。

## [Marking Routed Events as Handled, and Class Handling](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/marking-routed-events-as-handled-and-class-handling)

路由事件的处理程序可以在事件数据内将事件标记为已处理。 处理事件将有效地缩短路由。 类处理是一个编程概念，受路由事件支持。 类处理程序有机会在类级别使用处理程序处理特定路由事件，在类的任何实例上存在任何实例处理程序之前调用该处理程序。

### 系统必备

本主题将详细介绍[路由事件概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/routed-events-overview)中引入的概念。

### 何时将事件标记为“已处理”

如果设置的值[Handled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedeventargs.handled)属性设置为`true`在事件路由事件的数据，这被称为"标记处理的事件"。 对于应用程序创作者或者响应现有路由事件或实现新路由事件的控件创建者而言，何时应将路由事件标记为已处理，没有绝对规则。大多数情形下，路由事件的事件数据中携带的“已处理”概念应当用作一种限定协议，用于自己的应用程序响应 WPFAPI 中公开的各种路由事件时以及用于任意自定义路由事件。 考虑“已处理”问题的另一种方式为：如果代码以重要且相对完整的方式响应路由事件，则通常应将路由事件标记为已处理。 通常，重要响应不应该超过一个。所谓重要响应，是指对于单个任意路由事件，都需要单独的处理程序实现。 如果需要多个响应，则应通过在单个处理程序内链接的应用程序逻辑实现必要的代码，而不是使用路由事件系统进行转发。 是否“重要”这一概念比较主观，视应用程序或代码而定。 作为一般性指导原则，一些“重要响应”示例包括：设置焦点、修改公共状态、设置影响视觉表示形式的属性以及引发其他新事件。 非重要响应的示例包括：修改私有状态（无视觉影响，或编程表示形式）、记录事件或查看事件参数并选择不响应该事件。

路由的事件系统行为强调了此"重要响应"模型，用于使用路由事件的处理的状态，因为处理程序中添加XAML或公用签名来[AddHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.addhandler)不调用以响应路由事件的事件数据已标记为已处理。 您必须经过额外添加处理程序替换`handledEventsToo`参数版本 ([AddHandler(RoutedEvent, Delegate, Boolean)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.addhandler#System_Windows_UIElement_AddHandler_System_Windows_RoutedEvent_System_Delegate_System_Boolean_)) 若要处理的标记为已由早期参与者处理路由的事件在事件路由。

在某些情况下，控件本身会将某些路由事件标记为已处理。 已处理的路由事件表示 WPF 控件作者做出的以下决定：响应路由事件的控件操作是重要的，或者作为控件实现的一部分已完成，并且事件无需进一步处理。 通常，通过为事件添加一个类处理程序，或重写存在于基类上的其中一个类处理程序虚方法，可以完成此操作。 必要时仍然可以应对此事件处理；请参阅本主题后面部分的[通过控件解决事件禁止问题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/marking-routed-events-as-handled-and-class-handling#WorkingAroundEventSuppressionByControls)。

###  “预览”（隧道）事件与冒泡事件的对比以及事件处理

预览路由事件是指遵循元素树的隧道路由的事件。 命名约定中的“Preview”是指输入事件的一般原则，即预览（隧道）路由事件是在对等的冒泡路由事件之前引发的。 另外，具有隧道和冒泡对的输入路由事件具有截然不同的处理逻辑。 如果隧道/预览路由事件标记为已由事件侦听器处理，则冒泡路由事件将标记为已处理，然而此时冒泡路由事件的任何侦听器尚未接收到该事件。 隧道路由事件和冒泡路由事件在技术层面上是单独的事件，但是它们有意共享相同的事件数据实例以实现此行为。

任意给定的 WPF 类引发其声明的路由事件的方式的内部实现可在隧道路由事件与冒泡路由事件之间建立连接，对于成对的输入路由事件也是如此。 但是除非该类级实现存在，否则共享命名方案的隧道路由事件与冒泡路由事件之间将没有连接：没有上述实现，它们将是两个完全独立的路由事件，不会顺次引发，也不会共享事件数据。

有关如何在自定义类中实现隧道/冒泡输入路由事件对的详细信息，请参阅[创建自定义路由事件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-create-a-custom-routed-event)。

### 类处理程序和实例处理程序

路由事件会考虑事件的两种不同类型的侦听器：类侦听器和实例侦听器。 类侦听器已存在，因为类型具有名为特定[EventManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventmanager) API ，[RegisterClassHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventmanager.registerclasshandler)，在其静态构造函数，或已重写中的元素的基类的类处理程序虚方法。 实例侦听器是特定类实例/元素，其中一个或多个处理程序已附加为该路由事件调用[AddHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.addhandler)。 现有WPF路由的事件调用[AddHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.addhandler)作为的一部分公共语言运行时 (CLR)事件包装器添加{}并删除{}的事件，这也是如何实现简单XAML附加的机制启用通过特性语法的事件处理程序。 因此，即使简单XAML用法最终也等同于[AddHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.addhandler)调用。

将检查可视化树内的元素是否有注册的处理程序实现。 可能会在整个路由中以该路由事件的路由策略类型所固有的顺序调用处理程序。 例如，冒泡路由事件将首先调用那些附加到引发该路由事件的同一元素的处理程序。 然后，路由事件“冒泡”到下一父元素，以此类推，直到到达应用程序根元素。

从冒泡路由中的根元素的角度看，如果类处理或者更靠近路由事件源的任意元素调用那些将事件参数标记为正在处理的处理程序，那么就不会调用根元素上的处理程序，这样在到达该根元素之前的事件路由会大大缩短。 不过，路由并未完全停止，因为可以使用仍应调用处理程序的特殊条件来添加处理程序，即使类处理程序或实例处理程序已将路由事件标记为已处理也是如此。 本主题后面部分的[即使在事件标记为已处理时也要添加引发的实例处理程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/marking-routed-events-as-handled-and-class-handling#AddingInstanceHandlersthatAreRaisedEvenWhenEventsareMarkedHandled)对此进行了说明。

在比事件路由更深的级别上，还可能有多个类处理程序处理任意给定的类实例。 这是因为，路由事件的类处理模型使得类层次结构中的所有可能的类都可以针对每个路由事件注册自己的类处理程序。 每个类处理程序都会添加到一个内部存储，当构造应用程序的事件路由时，所有类处理程序都会添加到该事件路由中。 类处理程序按以下顺序添加到路由：最先调用派生程度最高的类处理程序，然后调用每个后续基类中的类处理程序。 通常，不会注册类处理程序以便它们也响应标记为已处理的路由事件。 因此，此类处理机制可提供以下两个选项之一：

- 派生类可以通过添加一个不将路由事件标记为已处理的处理程序，来补充从基类继承的类处理，因为有时会在派生类处理程序之后调用基类处理程序。
- 派生类可以通过添加一个将路由事件标记为已处理的类处理程序，来替换基类中的类处理。 应慎用此方法，因为它可能会更改视觉外观、状态逻辑、输入处理和命令处理等方面原本的基控件设计。

### 按控件基类进行的路由事件类处理

在事件路由中的每个给定元素节点上，类侦听器都有机会在元素的任意实例侦听器之前响应路由事件。 为此，类处理程序有时用于禁止某个特定控件类实现不希望继续传播的路由事件，或者用于提供类的一项功能，即对该路由事件进行特殊处理。 例如，类可能引发特定于其自身的事件，其中包含有关某个用户输入条件在该特定类的上下文中所代表的意义的更多具体信息。 然后，此类实现可能会将较为常规的路由事件标记为已处理。 类处理程序通常添加，以便它们不会调用的路由的事件在其中共享的事件数据已标记为已处理，但对于非典型情况还有[RegisterClassHandler(Type, RoutedEvent, Delegate, Boolean)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventmanager.registerclasshandler#System_Windows_EventManager_RegisterClassHandler_System_Type_System_Windows_RoutedEvent_System_Delegate_System_Boolean_)注册类处理程序来调用即使路由的事件在签名标记为已处理。

### 类处理程序虚方法

某些元素，尤其是元素，如基[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)，公开空"上 * 事件"和"OnPreview*事件"其公共路由事件的列表与对应的虚拟方法。 可以重写这些虚方法以便为该路由事件实现类处理程序。 基元素类注册这些虚拟方法，因为对于每个这样的类处理程序路由事件使用[RegisterClassHandler(Type, RoutedEvent, Delegate, Boolean)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventmanager.registerclasshandler#System_Windows_EventManager_RegisterClassHandler_System_Type_System_Windows_RoutedEvent_System_Delegate_System_Boolean_)如前面所述。 因为无需在静态构造函数中针对每个类型进行特殊初始化，所以 On*Event 虚方法使得为相关路由事件实现类处理变得简单得多。 例如，可以添加类处理[DragEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.dragenter)中任何事件[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)通过重写派生类[OnDragEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ondragenter)虚方法。 在重写内，可以处理路由事件、引发其他事件、启动可能更改实例的元素属性的特定于类的逻辑或上述操作的任意组合。通常情况下，在此类重写中，即使将事件标记为已处理，也应调用基实现。 强烈建议调用基实现，因为虚方法是在基类上。 从每个虚方法调用基实现的标准受保护虚拟模式实质上会替换和比较路由事件类处理所固有的类似机制，因此可以在任意给定实例上调用类层次结构中所有类的类处理程序，并从派生程度最高的类的处理程序开始，一直继续到基类处理程序。 如果类明确要求更改基类处理逻辑，则应仅忽略基实现调用。 在重写代码之前还是之后调用基实现取决于实现的性质。

#### 输入事件类处理

类处理程序虚方法均已注册，只有当存在任何共享事件数据尚未标记为已处理的情况时才调用这些方法。 另外，仅仅对于输入事件而言，隧道和冒泡版本通常是顺次引发的，并且共享事件数据。 对于一对给定的输入事件的类处理程序（其中一个是隧道版本，另一个是冒泡版本），当你可能不希望立即将事件标记为已处理时也需要此项。如果实现隧道类处理虚方法以便将事件标记为已处理，这将会阻止调用冒泡类处理程序（并阻止调用隧道或冒泡事件的任意正常注册的实例处理程序）。

节点上的类处理一经完成，就会考虑实例侦听器。

### 即使在事件标记为已处理时也要添加引发的实例处理程序

[AddHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.addhandler)方法提供的特定重载，可用于添加处理程序将调用事件系统只要事件到达的处理元素在路由中，即使其他处理程序已调整的事件数据标记，为已处理的事件。 但一般不这样操作。 通常情况下，不论事件是在元素树中的什么位置处理，即使需要多个最终结果，都可以通过编写处理程序来调整可能受事件影响的应用程序代码的各个方面。 另外，通常情况下，需要响应该事件的实际只有一个元素，并且已发生了适当的应用程序逻辑。 但是 `handledEventsToo` 重载适用于某些例外情况，例如元素数或控件复合中的某些其他元素已将事件标记为已处理，但是元素数中较高或较低的其他元素（视路由而定）仍希望调用自己的处理程序。

#### 何时将已处理事件标记为未处理

通常情况下，标记为已处理的路由的事件不应标记未处理 ([Handled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedeventargs.handled)重新设置为`false`) 甚至由处理程序，对`handledEventsToo`。 不过，某些输入事件具有高级别和低级别两种事件表示形式，当在树中的一个位置看到高级别事件，在另一个位置看到低级别事件时，这两种表示形式可以重叠。 例如，假设其中的子元素侦听高级别键事件如[TextInput](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.textinput)父元素侦听低级别事件如时[KeyDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.keydown)。 如果父元素处理低级别事件，则高级别事件甚至可能在子元素中被禁止，尽管直观看来子元素应该具有处理事件的先机。

在上述情形下，可能需要针对低级别事件向父元素和子元素中添加处理程序。 子元素处理程序实现可以将低级别事件标记为已处理，但父元素处理程序实现会再次将其设置为未处理，这样树上方的更多元素（以及高级别事件）就可以有机会响应。 这种情形应该非常少见。

### 有意对控件复合禁止输入事件

路由事件的类处理主要是用于输入事件和复合控件。 按照定义，复合控件是由多个实际控件或控件基类组成的。控件作者通常希望合并每个子组件可能引发的所有可能的输入事件，以便将整个控件报告为单事件源。 某些情况下，控件作者可能希望完全禁止来自组件的事件，或者替换上携带更多信息或者指示更具体行为的组件定义的事件。 是一个规范示例立即看到任何组件作者如何Windows Presentation Foundation (WPF)[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)处理最终会解析为直观的事件，所有按钮都有任何鼠标事件：[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件。

[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)基类 ([ButtonBase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase)) 派生自[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)又又派生自[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)和[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)，并且大部分事件基础结构所需的控件输入的处理，请参阅[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)级别。 具体而言，[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)处理常规[Mouse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.mouse)处理鼠标光标在其边界内的命中测试和最常见的提供不同的事件的事件按钮的操作，如[MouseLeftButtonDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouseleftbuttondown)。 [UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement) 此外提供了一个空的虚拟[OnMouseLeftButtonDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.onmouseleftbuttondown)为注册的类处理程序[MouseLeftButtonDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouseleftbuttondown)，和[ButtonBase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase)将重写它。 同样，[ButtonBase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase)使用类的处理程序[MouseLeftButtonUp](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouseleftbuttonup)。 中的替代，传递的事件数据，实现标记[RoutedEventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedeventargs)实例为已处理通过设置[Handled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedeventargs.handled)到`true`，和相同的事件数据，会继续沿路由到其他类处理程序的其余部分和指向实例处理程序或事件资源库。 此外，[OnMouseLeftButtonUp](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.onmouseleftbuttonup)重写接下来会引发[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件。 大多数侦听器的最终结果将是[MouseLeftButtonDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouseleftbuttondown)并[MouseLeftButtonUp](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouseleftbuttonup)事件"消失"，而是替换为[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)，保存更多意义，因为它从真正的按钮和一些不知道此事件源自的事件复合完全拼凑的按钮或其他某个元素。

#### 通过控件解决事件禁止问题

有时，各个控件内的此事件禁止行为可能会干扰应用程序的事件处理逻辑的某些较为常规的意图。 例如，如果出于某种原因，应用程序有一个处理程序[MouseLeftButtonDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouseleftbuttondown)位于应用程序根元素，您会注意到，将不会调用一个按钮上的任意单击鼠标[MouseLeftButtonDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouseleftbuttondown)或[MouseLeftButtonUp](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouseleftbuttonup)根级别的处理程序。 事件本身实际上会向上冒泡（同样，事件路由未真正结束，但路由事件系统会在事件标记为已处理后更改其处理程序调用行为）。 当路由的事件到达按钮时，[ButtonBase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase)类处理标记[MouseLeftButtonDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouseleftbuttondown)进行处理，因为它希望替换[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)具有更多意义的事件。 因此，任何标准[MouseLeftButtonDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouseleftbuttondown)进一步路由将不会调用处理程序。 可以使用两种方法来确保在此情形下会调用处理程序。

第一项技术是有意添加处理程序使用`handledEventsToo`的签名[AddHandler(RoutedEvent, Delegate, Boolean)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.addhandler#System_Windows_UIElement_AddHandler_System_Windows_RoutedEvent_System_Delegate_System_Boolean_)。 这种方法的局限性在于用于附加事件处理程序的这种技术只可能来自代码，而不能来自标记。 通过 可扩展应用程序标记语言 (XAML) 将事件处理程序名称指定为事件特性值的简单语法不能实现此行为。

第二种技术仅适用于输入事件，其中路由事件的隧道版本和冒泡版本是配对的。 对于这些路由事件，可以改为将处理程序添加到预览/隧道对等路由事件。 假如在应用程序的元素树中的某个上级元素级别附加了 Preview 处理程序，该路由事件将从根开始在路由中传递，所以按钮类处理代码不会截获到该事件。 如果使用此方法，则将任意 Preview 事件标记为已处理时一定要谨慎。 对于与给定的示例[PreviewMouseLeftButtonDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.previewmouseleftbuttondown)如果标记该事件作为根元素，在处理[Handled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedeventargs.handled)在处理程序实现中，实际上会禁止[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件。 这通常不是希望的行为。

## [Preview Events](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/preview-events)

预览事件，也称为隧道事件，也是路由的路由的事件，在应用程序根元素引发该事件并报告为事件数据中的源间传递的方向。 并非所有事件方案支持或要求预览事件;本主题介绍的情况下，预览事件存在，应用程序或组件应如何处理它们和在其中创建自定义组件或类中的预览事件可能是适当的情况。

### 预览事件和输入

在处理事件一般情况下，则应注意的预览版时将事件标记在事件中处理数据。 而不处理任何元素上的预览事件引发它 （将被报告为中的事件数据源的元素） 的元素具有不提供机会处理产生的事件元素的效果。 有时这是所需的结果，尤其是在控件的该组合中的关系中存在所涉及的元素。

输入事件的具体来说，预览事件也共享事件数据实例与等效的浮升事件。 如果使用预览事件类处理程序将处理该输入的事件标记，将不会调用浮升输入的事件的类处理程序。 或者，如果使用预览事件实例处理程序将处理该事件标记，浮升事件的处理程序将不通常会调用。 类处理程序或实例处理程序可以注册或附加要调用即使事件被标记为已处理，但该技术不常使用的选项。

有关类处理并将它与预览事件的详细信息请参阅[路由事件标记为已处理，和类处理](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/marking-routed-events-as-handled-and-class-handling)。

#### 通过控件解决事件禁止问题

通常用于预览事件的一个方案是，对于复合控件的输入事件的处理。 有时，控件作者禁止显示中的某些事件可能是为了替换上携带更多信息或者指示更具体的行为的组件定义事件源自其控件。 例如， Windows Presentation Foundation (WPF) [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)取消[MouseLeftButtonDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouseleftbuttondown)和[MouseRightButtonDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouserightbuttondown)引发浮升事件[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)或复合元素上的，以便支持捕获鼠标并引发[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)始终由引发的事件[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)本身。 事件和其数据仍继续沿路由，但由于[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)将标记作为事件数据[Handled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedeventargs.handled)，仅用于明确指定它们应在处理该事件的处理程序`handledEventsToo`调用用例。 如果其他元素指向你的应用程序的根目录仍想要处理控件取消事件的机会，一种替代方法是将在代码中使用的处理程序附加`handledEventsToo`指定为`true`。 但通常更简单方法是更改处理输入事件的预览等效路由方向。 例如，如果一个控件，将禁止[MouseLeftButtonDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouseleftbuttondown)，请尝试将附加的处理程序[PreviewMouseLeftButtonDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.previewmouseleftbuttondown)改为。 此方法仅适用于基元素输入事件如[MouseLeftButtonDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouseleftbuttondown)。 这些输入的事件使用隧道/冒泡对、 引发两个事件，并共享事件数据。

上述每种方法有负面影响或限制。 处理预览事件的副作用是在该点处理该事件可能会禁用为能够处理浮升事件的处理程序，并因此的限制是，它通常是不标记为已处理仍在使用 Previ 时一个好办法新路由的一部分。 限制`handledEventsToo`种方法是，不能指定`handledEventsToo`处理程序中的XAML作为属性，你必须注册事件处理程序代码中获取对该元素的对象引用，该处理程序附加后。

## [Property Change Events](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/property-change-events)

Windows Presentation Foundation (WPF) 定义几个为响应属性值的更改而引发的事件。 该属性通常是依赖项属性。 事件本身有时是路由事件，有时是标准 公共语言运行时 (CLR) 事件。 事件的定义因具体情况而异，因为有些属性更改更适于通过元素树路由，而其他属性更改则通常只与属性发生更改的对象有关。

### 标识属性更改事件

并非所有报告属性更改的事件都通过签名模式或命名模式显式地标识为属性更改事件。 通常，软件开发工具包 (SDK) 文档中的事件描述会指出事件是否直接与属性值更改相关，以及是否提供属性与事件之间的交叉引用。

#### RoutedPropertyChanged 事件

某些事件使用显式用于属性更改事件的事件数据类型和委托。 事件数据类型是[RoutedPropertyChangedEventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedpropertychangedeventargs-1)，委托是[RoutedPropertyChangedEventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedpropertychangedeventhandler-1)。 事件数据和委托都具有用于在定义处理程序时指定更改属性实际类型的泛型类型参数。 事件数据包含两个属性，[OldValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedpropertychangedeventargs-1.oldvalue)和[NewValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedpropertychangedeventargs-1.newvalue)，它们均然后作为类型参数在事件传递数据。

名称中的“Routed”部分表示属性更改事件注册为路由事件。 路由属性更改事件的好处是，如果子元素（控件的复合部分）上的属性更改了值，控件的顶层可以接收到属性更改事件。 例如，可能会创建控件，其中包含[RangeBase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.rangebase)控件如[Slider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider)。 如果的值[Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.rangebase.value)在滑块部分的属性更改，你可能想要处理父控件，而不是上一部分所做的更改。

因为有一个旧值和一个新值，所以很可能使用此事件处理程序作为属性值的验证程序。 但是，这不是大多数属性更改事件的设计意图。 通常，提供这些值是为了能够在代码的其他逻辑领域处理这些值，但实际上，在事件处理程序内更改值并不明智，并且可能导致意外的递归，具体取决于处理程序的实现方式。

如果您的属性是自定义依赖项属性，或如果您正在使用派生类定义了实例化代码，则多更好地跟踪的机制内置的属性更改WPF属性系统：属性系统回叫[CoerceValueCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.coercevaluecallback)和[PropertyChangedCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertychangedcallback)。 若要深入了解如何使用 WPF 属性系统进行验证和强制转换，请参阅[依赖属性回调和验证](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-callbacks-and-validation)和[自定义依赖属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/custom-dependency-properties)。

#### DependencyPropertyChanged 事件

另一对是属性更改的事件方案的一部分的类型是[DependencyPropertyChangedEventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencypropertychangedeventargs)和[DependencyPropertyChangedEventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencypropertychangedeventhandler)。 这些属性更改的事件不会路由；它们是标准 CLR 事件。[DependencyPropertyChangedEventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencypropertychangedeventargs) 是通常的事件数据报告类型，因为它不是派生自[EventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.eventargs);[DependencyPropertyChangedEventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencypropertychangedeventargs)是一种结构，不是类。

使用事件[DependencyPropertyChangedEventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencypropertychangedeventargs)并[DependencyPropertyChangedEventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencypropertychangedeventhandler)比稍微更常见`RoutedPropertyChanged`事件。 使用这些类型的事件的一个示例是[IsMouseCapturedChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ismousecapturedchanged)。

像[RoutedPropertyChangedEventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedpropertychangedeventargs-1)，[DependencyPropertyChangedEventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencypropertychangedeventargs)还报告的属性具有旧的和新值。 此外，关于如何处理这些值的注意事项也同样适用；通常不建议为响应事件而尝试在发送方再次更改值。

### 属性触发器

与属性更改事件密切相关的一个概念是属性触发器。 属性触发器是在样式或模板内创建的，通过它可以创建基于分配了属性触发器的属性的值的条件行为。

属性触发器的属性必须是依赖项属性。 它可以是（且通常是）只读依赖项属性。 判断控件公开的依赖项属性是否至少部分设计为属性触发器的一个好方法是查看属性名称是否以“Is”开头。 采用此命名规则的属性通常是只读的布尔依赖项属性，其属性的主要作用是报告可能与实时 UI 具有因果关系的控件状态，因此它是一个属性触发器候选。

其中一些属性还具有专用属性更改事件。 例如，属性[IsMouseCaptured](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ismousecaptured)具有属性更改事件[IsMouseCapturedChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ismousecapturedchanged)。 该属性本身是只读的其值由输入系统调整，并在输入的系统引发[IsMouseCapturedChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ismousecapturedchanged)上每次实时更改。

与真正的属性更改事件相比，使用属性触发器来处理属性更改具有一些限制。

属性触发器通过完全匹配逻辑来工作。 指定一个属性和一个值，该值指示触发器将执行操作的特定值。例如：`<Setter Property="IsMouseCaptured" Value="true"> ... </Setter>`。 由于此限制，大多数属性触发器用法都将针对布尔属性或者采用专用枚举值的属性，其可能值范围是可管理的，足以为每种情况定义一个触发器。 或者属性触发器可能仅仅用于特殊值，例如，当项计数达到零，却没有触发器来处理当属性值再次从零变为其他值（此处可能需要代码事件处理程序，或者当值不为零时再次从触发器状态切换回来的默认行为，而非针对所有情况的触发器）。

属性触发器语法与编程中的“if”语句类似。 如果触发器条件为 true，将“执行”属性触发器的“主体”。 属性触发器的“主体”是标记，而不是代码。 该标记被限制为使用一个或多个[Setter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.setter)元素来设置该对象的其他属性，其中应用样式或模板。

若要偏移的具有各种可能的值的属性触发器的"if"条件，通常，最好是使用相同的属性值设置为默认值[Setter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.setter)。 这样一来，[Trigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.trigger)包含的 setter 将具有优先权，如果触发器条件为 true，并[Setter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.setter)这是在不[Trigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.trigger)将具有优先权，只要触发器条件为 false。

属性触发器通常适合于一个或多个外观属性应基于同一元素的其他属性的状态而更改的情况。

若要深入了解属性触发器，请参阅[样式设置和模板化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/styling-and-templating)。

## [Visual Basic and WPF Event Handling](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/visual-basic-and-wpf-event-handling)

对于 Microsoft Visual Basic.NET 语言具体而言，您使用的是特定于语言的`Handles`关键字将事件处理程序相关联的实例，而不是附加事件处理程序具有属性或使用[AddHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.addhandler)方法。 但是，用于将处理程序附加到实例的 `Handles` 技术存在一些限制，因为 `Handles` 语法不支持 WPF 事件系统的某些特定路由事件功能。

### 在 WPF 应用程序中使用“Handles”

通过 `Handles` 连接到实例和事件的事件处理程序必须全部在实例的分部类声明中定义，此要求也适用于通过元素上的特性值进行分配的事件处理程序。 仅可以指定`Handles`具有的页上的元素[Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement.name)属性值 (或[X:name 指令](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-name-directive)声明)。 这是因为[Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement.name)中XAML创建可支持所需的实例引用*Instance.Event*所需的引用格式`Handles`语法。 可用于的唯一元素`Handles`而无需[Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement.name)引用是定义分部类的根元素实例。

可以通过使用逗号分隔 `Handles` 后面的 Instance.Event 引用，向多个元素分配相同的处理程序。

可以使用 `Handles` 将多个处理程序分配给同一 Instance.Event 引用。 请勿对 `Handles` 引用中特定处理程序的提供顺序赋予任何重要性；应假定可按任何顺序调用处理相同事件的处理程序。

若要删除的处理程序添加了`Handles`在声明中，可以调用[RemoveHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.removehandler)。

如果要将处理程序附加到实例成员表中用于定义要处理的事件的实例，可使用 `Handles` 附加路由事件的处理程序。 对于路由事件，具有附加的处理程序`Handles`一样作为附加的处理程序遵循相同的路由规则XAML属性，或使用的通用签名[AddHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.addhandler)。 这意味着，如果事件已标记为已处理 ([Handled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedeventargs.handled)在事件数据中的属性是`True`)，然后使用附加处理程序`Handles`不调用以响应该事件实例。 可通过路由中另一个元素上的实例处理程序，或通过在路由中当前元素或更早元素上进行类处理，将事件标记为已处理。 对于可支持成对的隧道事件/冒泡事件的输入事件，隧道路由可能已将事件对标记为已处理。 有关路由事件的详细信息，请参阅[路由事件概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/routed-events-overview)。

### 添加处理程序时的“Handles”限制

`Handles` 无法引用附加事件的处理程序。 必须对该附加事件使用 `add` 访问方法，或使用 XAML 中的 typename.eventname 事件特性。 有关详细信息，请参阅[路由事件概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/routed-events-overview)。

对于路由事件，只能使用 `Handles` 为实例成员表中存在该事件的实例分配处理程序。 但是，对于一般的路由事件，父元素可以是来自子元素的事件的侦听器，即使该父元素的成员表中没有此事件也是如此。 在特性语法中，这可以通过 typename.membername 特性形式来指定，此形式限定哪种类型实际定义要处理的事件。 例如，父`Page`(不带`Click`事件定义的) 可以通过将分配该窗体中的属性处理程序侦听按钮单击事件`Button.Click`。 但 `Handles` 不支持 typename.membername 形式，因为它必须支持与该形式冲突的 Instance.Event 形式。 有关详细信息，请参阅[路由事件概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/routed-events-overview)。

`Handles` 无法附加针对标记为已处理的事件而调用的处理程序。 相反，必须使用代码，并调用`handledEventsToo`重载[AddHandler(RoutedEvent, Delegate, Boolean)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.addhandler#System_Windows_UIElement_AddHandler_System_Windows_RoutedEvent_System_Delegate_System_Boolean_)。

> 不要使用`Handles`Visual Basic 代码时在 XAML 中指定相同的事件的事件处理程序中的语法。 在这种情况下，将调用事件处理程序两次。

### WPF 如何实现“Handles”功能

当可扩展应用程序标记语言 (XAML)编译页面，中间文件声明`Friend``WithEvents`对具有的页上的每个元素的引用[Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement.name)属性集 (或[X:name 指令](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-name-directive)声明)。 每个命名实例都可能是可通过 `Handles` 分配给处理程序的元素。

> 在 Microsoft Visual Studio 中，IntelliSense 可完整显示可用于页中的 `Handles` 引用的全部元素。 但是，这可能需要执行一个编译传递，以便中间文件可以填充所有 `Friends` 引用。

## [Weak Event Patterns](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/weak-event-patterns)

在应用程序，很可能附加到事件源的处理程序不会破坏与该处理程序附加到源的侦听器对象结合使用。 这种情况下可能会导致内存泄漏。 Windows Presentation Foundation (WPF) 引入了可用于解决此问题，请通过专用管理器类的特定事件并在该事件的侦听器上实现接口的设计模式。 这种设计模式被称为*弱事件模式*。

### 为什么要实现弱事件模式？

侦听事件可能会导致内存泄漏。 为要侦听的事件的典型方法是使用将一个处理程序附加到源中的事件的特定于语言的语法。 例如，在C#，语法是： `source.SomeEvent += new SomeEventHandler(MyEventHandler)`。

此方法创建事件源到事件侦听器的强引用。 通常，为侦听器附加事件处理程序会导致具有受到了源的对象生存期 （除非显式删除事件处理程序） 的对象生存期的侦听器。 但在某些情况下，你可能想要由其他因素控制的侦听器的对象生存期，如是否当前属于可视化树的应用程序，而不是由源的生存期。 只要源对象生存期超出侦听器的对象生存期，正常事件模式会导致内存泄漏： 侦听器保持活动状态比预期更长时间。

弱事件模式旨在解决此内存泄漏问题。 侦听器需要注册一个事件，但侦听器并不显式了解何时取消注册时，可以使用弱事件模式。 源的对象生存期超过侦听器的有用的对象生存期时，还可以使用弱事件模式。 (在这种情况下，*有用*由您决定。)弱事件模式允许注册和接收事件，而不会影响任何方式侦听器的对象生存期特征的侦听器。 实际上，来自源的隐式的引用不确定侦听器是否处于可进行垃圾回收。 引用是弱引用，因此命名弱事件模式和相关的API。 可以对侦听器进行垃圾回收或销毁，且源可以继续而不保留对现在销毁的对象的非可收集处理程序引用。

### 谁应该实现弱事件模式？

主要为控件创作者有趣的是实现弱事件模式。 作为控件作者，您有很大程度上责任的行为和包容控件以及对其插入到的应用程序的影响。 这包括控制对象生存期行为，特别是描述的内存泄漏问题的处理。

某些情况下本质上是有助于使自身在弱事件模式的应用程序。 其中一种方案是数据绑定。 数据绑定中很常见的源对象是完全独立于侦听器对象，它是绑定的目标。 许多方面WPF数据绑定已具有弱事件模式应用于事件的实现方式。

### 如何实现弱事件模式

有三种方法来实现弱事件模式。 下表列出了三种方法，并提供了应何时使用每个的一些指导。

| 方法                     | 何时实现                                                     |
| ------------------------ | ------------------------------------------------------------ |
| 使用现有的弱事件管理器类 | 如果你想要订阅的事件具有对应[WeakEventManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.weakeventmanager)，使用现有的弱事件管理器。 弱事件管理器所包含的 WPF 的列表，请参阅中的继承层次结构[WeakEventManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.weakeventmanager)类。 由于包含弱事件管理器是有限的可能需要选择其他方法之一。 |
| 使用泛型弱事件管理器类   | 使用通用[WeakEventManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.weakeventmanager-2)时的现有[WeakEventManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.weakeventmanager)不可用，您希望轻松地实现，而你并不关心的是效率。 泛型[WeakEventManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.weakeventmanager-2)效率低于现有或自定义的弱事件管理器。 例如，泛型类执行的更多的反射来发现给定事件的名称的事件。 此外，通过使用泛型注册事件的代码[WeakEventManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.weakeventmanager-2)是更详细比使用一个现有或自定义[WeakEventManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.weakeventmanager)。 |
| 创建自定义弱事件管理器类 | 创建自定义[WeakEventManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.weakeventmanager)时的现有[WeakEventManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.weakeventmanager)不可用，并且希望获得最佳的效率。 使用自定义[WeakEventManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.weakeventmanager)来订阅事件将会更高效，但确实会产生编写更多代码开头的成本。 |
| 使用第三方弱事件管理器   | NuGet 已[几个弱事件管理器](https://www.nuget.org/packages?q=weak+event+manager&prerel=false)和许多 WPF 框架还支持模式 (例如，请参阅[松散耦合的事件订阅的 Prism 的文档](https://github.com/PrismLibrary/Prism-Documentation/blob/master/docs/wpf/Communication.md#subscribing-to-events))。 |

以下部分介绍如何实现弱事件模式。 出于本文的讨论，以订阅该事件具有以下特征。

- 事件名称是`SomeEvent`。
- 引发事件`EventSource`类。
- 事件处理程序类型： `SomeEventEventHandler` (或`EventHandler<SomeEventEventArgs>`)。
- 该事件传递的类型参数`SomeEventEventArgs`到事件处理程序。

#### 使用现有的弱事件管理器类

1. 查找现有的弱事件管理器。

   弱事件管理器所包含的 WPF 的列表，请参阅中的继承层次结构[WeakEventManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.weakeventmanager)类。

2. 使用新的弱事件管理器，而不是普通事件挂钩。

   例如，如果你的代码使用以下模式来订阅事件：

   ```
   source.SomeEvent += new SomeEventEventHandler(OnSomeEvent);  
   ```

   将其更改为以下模式：

   ```
   SomeEventWeakEventManager.AddHandler(source, OnSomeEvent);  
   ```

   同样，如果你的代码使用以下模式来取消订阅事件：

   ```
   source.SomeEvent -= new SomeEventEventHandler(OnSome);  
   ```

   将其更改为以下模式：

   ```
   SomeEventWeakEventManager.RemoveHandler(source, OnSomeEvent);  
   ```

#### 使用泛型弱事件管理器类

1. 使用泛型[WeakEventManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.weakeventmanager-2)类而不是普通事件挂钩。

   当你使用[WeakEventManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.weakeventmanager-2)若要注册事件侦听器，您提供事件源和[EventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.eventargs)类型的类和调用的类型参数作为[AddHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.weakeventmanager-2.addhandler)如下面的代码中所示：

   ```
   WeakEventManager<EventSource, SomeEventEventArgs>.AddHandler(source, "SomeEvent", source_SomeEvent);  
   ```

#### 创建自定义的弱事件管理器类

1. 将以下类模板复制到你的项目。

   此类继承[WeakEventManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.weakeventmanager)类。

   ```csharp
   class SomeEventWeakEventManager : WeakEventManager
   {
   
       private SomeEventWeakEventManager()
       {
   
       }
   
       /// <summary>
       /// Add a handler for the given source's event.
       /// </summary>
       public static void AddHandler(EventSource source, 
                                     EventHandler<SomeEventEventArgs> handler)
       {
           if (source == null)
               throw new ArgumentNullException("source");
           if (handler == null)
               throw new ArgumentNullException("handler");
   
           CurrentManager.ProtectedAddHandler(source, handler);
       }
   
       /// <summary>
       /// Remove a handler for the given source's event.
       /// </summary>
       public static void RemoveHandler(EventSource source, 
                                        EventHandler<SomeEventEventArgs> handler)
       {
           if (source == null)
               throw new ArgumentNullException("source");
           if (handler == null)
               throw new ArgumentNullException("handler");
   
           CurrentManager.ProtectedRemoveHandler(source, handler);
       }
   
       /// <summary>
       /// Get the event manager for the current thread.
       /// </summary>
       private static SomeEventWeakEventManager CurrentManager
       {
           get
           {
               Type managerType = typeof(SomeEventWeakEventManager);
               SomeEventWeakEventManager manager = 
                   (SomeEventWeakEventManager)GetCurrentManager(managerType);
   
               // at first use, create and register a new manager
               if (manager == null)
               {
                   manager = new SomeEventWeakEventManager();
                   SetCurrentManager(managerType, manager);
               }
   
               return manager;
           }
       }
   
   
   
       /// <summary>
       /// Return a new list to hold listeners to the event.
       /// </summary>
       protected override ListenerList NewListenerList()
       {
           return new ListenerList<SomeEventEventArgs>();
       }
   
   
       /// <summary>
       /// Listen to the given source for the event.
       /// </summary>
       protected override void StartListening(object source)
       {
           EventSource typedSource = (EventSource)source;
           typedSource.SomeEvent += new EventHandler<SomeEventEventArgs>(OnSomeEvent);
       }
   
       /// <summary>
       /// Stop listening to the given source for the event.
       /// </summary>
       protected override void StopListening(object source)
       {
           EventSource typedSource = (EventSource)source;
           typedSource.SomeEvent -= new EventHandler<SomeEventEventArgs>(OnSomeEvent);
       }
   
       /// <summary>
       /// Event handler for the SomeEvent event.
       /// </summary>
       void OnSomeEvent(object sender, SomeEventEventArgs e)
       {
           DeliverEvent(sender, e);
       }
   }
   ```

2. 替换为`SomeEventWeakEventManager`名称与你自己的名称。

3. 替换为您的活动的相应名称的前面所述的三个名称。 (`SomeEvent`， `EventSource`，和`SomeEventEventArgs`)

4. 设置为相同的可见性为它所管理的事件的弱事件管理器类的可见性 （公共 / 内部 / 专用）。

5. 使用新的弱事件管理器，而不是普通事件挂钩。

   例如，如果你的代码使用以下模式来订阅事件：

   ```
   source.SomeEvent += new SomeEventEventHandler(OnSomeEvent);  
   ```

   将其更改为以下模式：

   ```
   SomeEventWeakEventManager.AddHandler(source, OnSomeEvent);  
   ```

   同样，如果你的代码使用以下模式来取消订阅某个事件：

   ```
   source.SomeEvent -= new SomeEventEventHandler(OnSome);  
   ```

   将其更改为以下模式：

   ```
   SomeEventWeakEventManager.RemoveHandler(source, OnSomeEvent);  
   ```

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/events-how-to-topics)

本部分中的主题介绍如何使用在 WPF 中的事件。

### 本节内容

[使用代码添加事件处理程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-add-an-event-handler-using-code)
[处理路由事件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-handle-a-routed-event)
[创建自定义路由事件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-create-a-custom-routed-event)
[在事件处理程序中查找源元素](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-find-the-source-element-in-an-event-handler)
[为路由事件添加类处理](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-add-class-handling-for-a-routed-event)

### [Add an Event Handler Using Code](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-add-an-event-handler-using-code)

此示例演示如何使用代码将事件处理程序添加到元素。

如果你想要添加到事件处理程序XAML已加载元素，并包含的元素的标记页面，则必须添加使用代码处理程序。 或者，如果您正在生成的应用程序完全使用代码而没有声明使用任何元素的元素树XAML，可以调用特定方法来将事件处理程序添加到构造的元素树。

#### 示例

下面的示例添加一个新[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)到现有的页面中最初定义XAML。 代码隐藏文件实现事件处理程序方法，然后将该方法添加为新的事件处理程序上[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。

C#的示例使用`+=`运算符分配的事件处理程序。 这是用于分配中的处理程序的相同运算符公共语言运行时 (CLR)事件处理模型。 作为一种方式添加事件处理程序的情况下，Microsoft Visual Basic 不支持此运算符。 相反，它要求两种技术之一：

- 使用[AddHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.addhandler)方法，一起`AddressOf`运算符，以引用的事件处理程序实现。
- 使用`Handles`关键字作为事件处理程序定义的一部分。 此处; 未显示这种方法请参阅[Visual Basic 和 WPF 事件处理](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/visual-basic-and-wpf-event-handling)。

```xaml
<TextBlock Name="text1">Start by clicking the button below</TextBlock>
<Button Name="b1" Click="MakeButton">Make new button and add handler to it</Button>
```

```csharp
public partial class RoutedEventAddRemoveHandler {
    void MakeButton(object sender, RoutedEventArgs e)
    {
        Button b2 = new Button();
        b2.Content = "New Button";
        // Associate event handler to the button. You can remove the event 
        // handler using "-=" syntax rather than "+=".
        b2.Click  += new RoutedEventHandler(Onb2Click);
        root.Children.Insert(root.Children.Count, b2);
        DockPanel.SetDock(b2, Dock.Top);
        text1.Text = "Now click the second button...";
        b1.IsEnabled = false;
    }
    void Onb2Click(object sender, RoutedEventArgs e)
    {
        text1.Text = "New Button (b2) Was Clicked!!";
    }
```

> 添加事件处理程序在最初分析XAML页是要简单得多。 在对象元素中你想要添加事件处理程序，将添加匹配你想要处理的事件名称的属性。 然后该属性的值指定的代码隐藏文件中定义的事件处理程序方法的名称为XAML页。 有关详细信息，请参阅[XAML 概述 (WPF)](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-overview-wpf)或[路由事件概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/routed-events-overview)。

### [Handle a Routed Event](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-handle-a-routed-event)

本示例演示了浮升事件的工作原理，以及如何编写可处理路由事件数据的处理程序。

#### 示例

在 Windows Presentation Foundation (WPF) 中，元素以元素树结构形式排列。 父元素可以参与处理最初由元素树中的子元素引发的事件。 这都是因为事件路由。

路由事件通常遵循以下两个路由策略之一：浮升和隧道。 此示例重点介绍浮升事件，并使用[ButtonBase.Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件可显示路由的工作原理。

下面的示例创建两个[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)控制，并使用XAML特性语法将事件处理程序附加到公用父元素，它在此示例中为[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)。 而不是将单个事件处理程序附加每个[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)子元素，该示例使用特性语法将附加到的事件处理程序[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)父元素。 此事件处理模式展示了如何使用事件路由技术来减少附加处理程序的元素数。 每个的所有浮升事件[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)通过父元素路由。

请注意，在父[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)元素中，[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)指定为该属性进行部分限定的命名的事件名称[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)类。 [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)类是[ButtonBase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase)派生的类具有[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件在其成员列表中的。 如果要处理的事件不在附加路由事件处理程序的元素的成员列表中，则有必要使用这种部分限定技术来附加事件处理程序。

```xaml
<StackPanel
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  x:Class="SDKSample.RoutedEventHandle"
  Name="dpanel"
  Button.Click="HandleClick"
>
  <StackPanel.Resources>
      <Style TargetType="{x:Type Button}">
        <Setter Property="Height" Value="20"/>
        <Setter Property="Width" Value="250"/>
        <Setter Property="HorizontalAlignment" Value="Left"/>
      </Style>
  </StackPanel.Resources>
  <Button Name="Button1">Item 1</Button>
  <Button Name="Button2">Item 2</Button>
  <TextBlock Name="results"/>
</StackPanel>
```

下面的示例处理[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件。 该示例会报告哪个元素处理事件以及哪个元素引发事件。 用户单击任一按钮时都将执行事件处理程序。

```csharp
public partial class RoutedEventHandle : StackPanel
{
    StringBuilder eventstr = new StringBuilder();
    void HandleClick(object sender, RoutedEventArgs args)
    {
        // Get the element that handled the event.
        FrameworkElement fe = (FrameworkElement)sender;
        eventstr.Append("Event handled by element named ");
        eventstr.Append(fe.Name);
        eventstr.Append("\n");

        // Get the element that raised the event. 
        FrameworkElement fe2 = (FrameworkElement)args.Source;
        eventstr.Append("Event originated from source element of type ");
        eventstr.Append(args.Source.GetType().ToString());
        eventstr.Append(" with Name ");
        eventstr.Append(fe2.Name);
        eventstr.Append("\n");

        // Get the routing strategy.
        eventstr.Append("Event used routing strategy ");
        eventstr.Append(args.RoutedEvent.RoutingStrategy);
        eventstr.Append("\n");

        results.Text = eventstr.ToString();
    }
}
```

### [Create a Custom Routed Event](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-create-a-custom-routed-event)

若要支持事件路由使自定义事件，你需要注册[RoutedEvent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedevent)使用[RegisterRoutedEvent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventmanager.registerroutedevent)方法。 本示例演示了创建自定义路由事件的基本原理。

#### 示例

下面的示例中所示，第一次注册[RoutedEvent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedevent)使用[RegisterRoutedEvent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventmanager.registerroutedevent)方法。 按照约定，[RoutedEvent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedevent)静态字段名称应以后缀结尾***事件***。 在此示例中，事件的名称是`Tap`事件的路由策略是[Bubble](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routingstrategy#System_Windows_RoutingStrategy_Bubble)。 在注册调用之后，可以为该事件提供添加和删除 公共语言运行时 (CLR) 事件访问器。

请注意，尽管事件在此特定示例中是通过 `OnTap` 虚拟方法引发的，但引发事件的方式或事件响应更改的方式取决于你的需要。

另请注意，本示例主要实现的一整个子类[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button); 该子类是作为单独的程序集生成，然后为在单独的自定义类实例化可扩展应用程序标记语言 (XAML)页。 这是为了说明这样一个概念：子类化的控件可以插入到由其他控件组成的树中，在这种情况下，这些控件上的自定义事件具有与任何固有 Windows Presentation Foundation (WPF) 元素完全相同的事件路由功能。

```csharp
public class MyButtonSimple: Button
{
    // Create a custom routed event by first registering a RoutedEventID
    // This event uses the bubbling routing strategy
    public static readonly RoutedEvent TapEvent = EventManager.RegisterRoutedEvent(
        "Tap", RoutingStrategy.Bubble, typeof(RoutedEventHandler), typeof(MyButtonSimple));

    // Provide CLR accessors for the event
    public event RoutedEventHandler Tap
    {
            add { AddHandler(TapEvent, value); } 
            remove { RemoveHandler(TapEvent, value); }
    }

    // This method raises the Tap event
    void RaiseTapEvent()
    {
            RoutedEventArgs newEventArgs = new RoutedEventArgs(MyButtonSimple.TapEvent);
            RaiseEvent(newEventArgs);
    }
    // For demonstration purposes we raise the event when the MyButtonSimple is clicked
    protected override void OnClick()
    {
        RaiseTapEvent();
    }

}
```

```xaml
<Window  
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    xmlns:custom="clr-namespace:SDKSample;assembly=SDKSampleLibrary"
    x:Class="SDKSample.RoutedEventCustomApp"

    >
    <Window.Resources>
      <Style TargetType="{x:Type custom:MyButtonSimple}">
        <Setter Property="Height" Value="20"/>
        <Setter Property="Width" Value="250"/>
        <Setter Property="HorizontalAlignment" Value="Left"/>
        <Setter Property="Background" Value="#808080"/>
      </Style>
    </Window.Resources>
    <StackPanel Background="LightGray">
        <custom:MyButtonSimple Name="mybtnsimple" Tap="TapHandler">Click to see Tap custom event work</custom:MyButtonSimple>
    </StackPanel>
</Window>
```

隧道事件创建相同，但[RoutingStrategy](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedevent.routingstrategy)设置为[Tunnel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routingstrategy#System_Windows_RoutingStrategy_Tunnel)在注册调用中。 按照约定，WPF 中的隧道事件以单词“Preview”开头。

若要查看浮升事件的工作原理示例，请参阅[处理路由事件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-handle-a-routed-event)。

### [Find the Source Element in an Event Handler](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-find-the-source-element-in-an-event-handler)

此示例演示如何在事件处理程序中查找源元素。

#### 示例

下面的示例演示[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)在代码隐藏文件中声明的事件处理程序。 当用户单击处理程序附加到的按钮时，该处理程序更改的属性值。 处理程序代码使用[Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedeventargs.source)路由的事件数据中的事件自变量报告更改的属性[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)上的属性值[Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedeventargs.source)元素。

```xaml
<Button Click="HandleClick">Button 1</Button>
```

```csharp
void HandleClick(object sender, RoutedEventArgs e)
{
    // You must cast the sender object as a Button element, or at least as FrameworkElement, to set Width
    Button srcButton = e.Source as Button;
    srcButton.Width = 200;
}
```

### [Add Class Handling for a Routed Event](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-add-class-handling-for-a-routed-event)

通过类处理程序或路由中的任何给定节点上的实例处理程序可以处理路由的事件。 类处理程序首先，调用，并可以由类实现来禁止显示来自实例处理的事件或引入其他事件上所拥有的基类的事件的特定行为。 此示例说明了实现类处理程序的两个密切相关的方法。

#### 示例

此示例使用自定义类基于[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)面板。 应用程序的基本前提是自定义类引入了包括截获任何鼠标按钮单击和它们的处理，然后将调用的子元素类或其任何实例处理程序的标记及其子元素上的行为。

[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)类公开一个虚拟方法，使类上处理[PreviewMouseLeftButtonDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.previewmouseleftbuttondown)事件，只需重写该事件。 这是实现类处理，如果此类的虚方法为您的类层次结构中的某处可用的最简单方法。 下面的代码演示[OnPreviewMouseLeftButtonDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.onpreviewmouseleftbuttondown)派生自"MyEditContainer"中的实现[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)。 实现将事件标记为已处理参数中，然后添加一些代码来提供基本明显的变化的源元素。

```csharp
protected override void OnPreviewMouseRightButtonDown(System.Windows.Input.MouseButtonEventArgs e)
{
    e.Handled = true; //suppress the click event and other leftmousebuttondown responders
    MyEditContainer ec = (MyEditContainer)e.Source;
    if (ec.EditState)
    { ec.EditState = false; }
    else
    { ec.EditState = true; }
    base.OnPreviewMouseRightButtonDown(e);
}
```

如果任何虚拟基类上或针对该特定方法可用，可以直接使用的实用程序方法添加类处理[EventManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventmanager)类， [RegisterClassHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventmanager.registerclasshandler)。 只应添加类处理的类的静态初始化内部调用此方法。 此示例将添加另一个处理程序[PreviewMouseLeftButtonDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.previewmouseleftbuttondown)，并在这种情况下注册的类是自定义的类。 与此相反，使用虚方法，注册的类时，真正[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)基类。 在基类和子类每个在其中注册类处理的情况下，首次调用子类处理程序。 在应用程序行为将是，此处理程序首先会显示其消息框，则会显示虚拟方法的处理程序中的可视更改。

```csharp
static MyEditContainer()
{
  EventManager.RegisterClassHandler(typeof(MyEditContainer), PreviewMouseRightButtonDownEvent, new RoutedEventHandler(LocalOnMouseRightButtonDown));
}
internal static void LocalOnMouseRightButtonDown(object sender, RoutedEventArgs e)
{
  MessageBox.Show("this is invoked before the On* class handler on UIElement");
  //e.Handled = true; //uncommenting this would cause ONLY the subclass' class handler to respond
}
```