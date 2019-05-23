# [Properties](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/properties-wpf)

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

## [Dependency Properties Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/dependency-properties-overview)

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

为了生成数据绑定操作的 [DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject) 源属性值的更改通知，依赖属性或 [DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject) 类本身不支持 [INotifyPropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.inotifypropertychanged)。 有关如何创建要用在数据绑定中并且可以向数据绑定目标报告变化的属性的详细信息，请参阅[数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview)。

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

请看下面的示例。 该示例包含适用于所有按钮及其 [Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background) 属性的样式，但也会指定一个具有本地设置的[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background) 值的按钮。

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

## [Attached Properties Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/attached-properties-overview)

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

 备注

如果省略附加的属性的 get 访问器，在属性上的数据绑定不会在设计工具，如 Visual Studio 和 Expression Blend 中。

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

## [Dependency Property Callbacks and Validation](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/dependency-property-callbacks-and-validation)

本主题介绍如何使用与属性相关的功能（如验证确定、更改属性的有效值时调用的回调）的替代自定义实现，并重写对值确定的外部可能影响来创建依赖属性。 本主题还讨论使用这些技术扩展默认属性系统行为所适用的方案。

### 系统必备

本主题假定你了解实现依赖属性的基本方案，以及如何将元数据应用于自定义依赖属性。 有关上下文，请参阅[自定义依赖属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/custom-dependency-properties)和[依赖属性元数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-metadata)。

### 验证回叫

在首次注册依赖属性时，可以为其分配验证回叫。 验证回叫不属于属性元数据;是的直接输入[Register](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.register)方法。 因此，在为某个依赖属性创建验证回叫后，新实现无法重写该验证回叫。

```csharp
public static readonly DependencyProperty CurrentReadingProperty = DependencyProperty.Register(
    "CurrentReading",
    typeof(double),
    typeof(Gauge),
    new FrameworkPropertyMetadata(
        Double.NaN,
        FrameworkPropertyMetadataOptions.AffectsMeasure,
        new PropertyChangedCallback(OnCurrentReadingChanged),
        new CoerceValueCallback(CoerceCurrentReading)
    ),
    new ValidateValueCallback(IsValidReading)
);
public double CurrentReading
{
  get { return (double)GetValue(CurrentReadingProperty); }
  set { SetValue(CurrentReadingProperty, value); }
}
```

实现回叫，以便为其提供对象值。 如果提供的值对属性有效，回叫会返回 `true`；否则，回叫返回 `false`。 假定按照向属性系统注册的类型，属性的类型是正确的，因此通常不会在回叫内执行类型检查。 属性系统可在多种不同操作中使用回叫。 这包括按默认值的初始类型初始化、 以编程方式更改通过调用[SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue)，或尝试使用提供的新默认值重写元数据。 如果验证回叫是通过其中任何一种操作调用的，并且返回 `false`，则会引发异常。 应用程序编写器必须准备处理这些异常。 验证回叫常用于验证枚举值，或在属性设置的度量值必须大于等于零时约束整数值或双精度型值。

验证回叫专用作类验证程序，而不用作实例验证程序。 回叫参数不会与特定通信[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)上设置要验证的属性。 因此，验证回叫不能用来强制执行可能会影响属性值的“依赖项”，其中，某个属性特定于实例的值依赖于其他属性特定于实例的值或运行时状态等因素。

以下是非常简单的验证回叫方案的代码示例： 验证属性被类型化为[Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double)基元不是[PositiveInfinity](https://docs.microsoft.com/zh-cn/dotnet/api/system.double.positiveinfinity)或[NegativeInfinity](https://docs.microsoft.com/zh-cn/dotnet/api/system.double.negativeinfinity)。

```csharp
public static bool IsValidReading(object value)
{
    Double v = (Double)value;
    return (!v.Equals(Double.NegativeInfinity) && !v.Equals(Double.PositiveInfinity));
}
```



### 强制值回叫和属性更改事件

强制值回叫传递属性特定于[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)实例的属性，如执行[PropertyChangedCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertychangedcallback)依赖项属性的值发生更改时由属性系统调用的实现。 通过将这两种回叫组合使用，可以对元素创建一系列属性，其中，一个属性的更改会对另一个属性实施强制或重新计算。

使用依赖属性链接的典型方案是：具有用户界面驱动属性，其中，元素为最小值和最大值分别保留一个属性，为实际值或当前值保留第三个属性。 此时，如果按照当前值超出新的最大值的方式调整最大值，则可能需要强制当前值不超过新的最大值，并对最小值与当前值强制类似的关系。

下面是一个非常简短的代码示例，仅针对阐释此关系的三个依赖属性之一。 该示例演示如何注册相关的 *Reading 属性的最小/最大/当前值集的 `CurrentReading` 属性。 它使用上一节中所示的验证。

```csharp
public static readonly DependencyProperty CurrentReadingProperty = DependencyProperty.Register(
    "CurrentReading",
    typeof(double),
    typeof(Gauge),
    new FrameworkPropertyMetadata(
        Double.NaN,
        FrameworkPropertyMetadataOptions.AffectsMeasure,
        new PropertyChangedCallback(OnCurrentReadingChanged),
        new CoerceValueCallback(CoerceCurrentReading)
    ),
    new ValidateValueCallback(IsValidReading)
);
public double CurrentReading
{
  get { return (double)GetValue(CurrentReadingProperty); }
  set { SetValue(CurrentReadingProperty, value); }
}
```

当前值的属性更改回叫用于将更改转发到其他依赖属性，方法是显式调用为这些属性注册的强制值回叫：

```csharp
private static void OnCurrentReadingChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
{
  d.CoerceValue(MinReadingProperty);
  d.CoerceValue(MaxReadingProperty);
}
```

强制值回叫会检查当前属性可能依赖的属性的值，并在必要时强制当前值：

```csharp
private static object CoerceCurrentReading(DependencyObject d, object value)
{
  Gauge g = (Gauge)d;
  double current = (double)value;
  if (current < g.MinReading) current = g.MinReading;
  if (current > g.MaxReading) current = g.MaxReading;
  return current;
}
```

> 不会强制属性的默认值。 如果属性值仍有其初始默认值，或通过清除使用其他值的属性值等于默认值可能会出现[ClearValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.clearvalue)。

强制值回叫和属性更改回叫属于属性元数据的一部分。 因此，可以通过在类型上重写特定依赖属性的元数据来更改对该属性的回叫，因为其所在的类型派生自拥有该依赖属性的类型。

### 高级强制和回叫方案

#### 约束和所需的值

[CoerceValueCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.coercevaluecallback)回调将由属性系统来强制值根据所声明的逻辑，但强制转换后的本地设置值属性将仍会在内部保留"所需的值"。 如果约束基于可能会在应用程序生存期间动态更改的其他属性值，则强制约束也会进行动态更改，并且在给定新约束的情况下约束属性可更改其值以尽可能接近所需的值。 如果解除所有约束，该值会成为所需的值。 如果多个属性以循环方式相互依赖，则可能会引入某些相当复杂的依赖项方案。 例如，在最小/最大/当前值方案中，可以选择将最小值和最大值作为用户可设置的资源。 在这种情况下，可能需要强制最大值始终大于最小值，反之亦然。 但是，如果该强制处于活动状态，并且最大值强制为最小值，则会将当前值保留在不可设置的状态，因为它依赖于这二者，且被约束在这些值之间的范围内，即为零。 这样，如果调整最大值或最小值，当前值可能会“沿用”这些值之一，因为仍然存储了当前值所需的值，并且当前值会在放松约束时尝试接近所需的值。

复杂依赖项没有任何技术错误，但是，如果它们需要大量重新计算，则可能会略微降低性能，而且还可能导致用户混淆（如果直接影响 UI）。 请小心使用属性更改回叫和强制值回叫，确保尽可能地明确处理所尝试的强制，并且不会“过度约束”。

#### 使用 CoerceValue 取消值更改

属性系统会将任何[CoerceValueCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.coercevaluecallback)返回的值[UnsetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.unsetvalue)作为一种特殊情况。 此特殊情况意味着，导致属性更改[CoerceValueCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.coercevaluecallback)属性系统中，应会拒绝被调用，并且属性系统应改为报告该属性具有以前的任何值。 该机制可用于检查异步启动的属性更改对当前对象状态是否仍然有效，如果无效，则可取消这些更改。 另一个可能的方案是：可以根据负责所报告的值的属性值确定组件，有选择地取消该值。 若要执行此操作，可以使用[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)回叫和属性标识符作为输入传递[GetValueSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencypropertyhelper.getvaluesource)，然后处理[ValueSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.valuesource)。

## [Custom Dependency Properties](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/custom-dependency-properties)

本主题介绍了 Windows Presentation Foundation (WPF) 应用程序开发者和组件作者想要创建自定义依赖属性的原因，并介绍了一些可以提高属性的性能、可用性或通用性的实现步骤以及实现选项。

### 系统必备

本主题假设你作为 WPF 类的现有依赖属性的使用者已经对依赖属性有所了解，并且已经阅读了[依赖属性概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-properties-overview)主题。 若要理解本主题中的示例，还应当了解 可扩展应用程序标记语言 (XAML) 并知道如何编写 WPF 应用程序。

### 什么是依赖属性？

可以通过启用原本是公共语言运行时 (CLR) 属性的属性来支持样式设置、数据绑定、继承、动画和默认值，方法是将该属性作为依赖属性进行实现。 依赖项属性是使用注册的属性WPF通过调用属性系统[Register](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.register)方法 (或[RegisterReadOnly](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.registerreadonly))，并由支持[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)标识符字段。 可以仅通过使用依赖关系属性[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)类型，但[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)中很高WPF类层次结构中，因此大部分可用的类中WPF可以支持依赖项属性。 若要详细了解依赖属性和此 SDK 中对依赖属性进行描述所使用的术语和约定，请参阅[依赖属性概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-properties-overview)。

### 依赖属性示例

实现的依赖项属性的示例WPF类包括[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)属性，[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)属性，并[Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.text)属性，此外还有许多其他属性。 类公开的每个依赖属性具有相应类型的公共静态字段[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)相同的类上公开。 这是依赖属性的标识符。 此标识符的命名约定为：依赖属性名称后面加上字符串 `Property`。 例如，在相应[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)的标识符字段[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)属性是[BackgroundProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.backgroundproperty)。 标识符存储有关依赖项属性的信息，因为它已注册，并在然后涉及依赖项属性，例如，调用其他操作的更高版本使用标识符[SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue)。

如[依赖属性概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-properties-overview)中所述，因为“包装器”实现，WPF 中的所有依赖属性（大多数附加属性除外）也是 CLR 属性。 因此，在代码中通过调用定义包装器的 CLR 访问器（调用方法与使用其他 CLR 属性相同）可以获取或设置依赖属性。 建立的依赖属性的使用者，您通常不会使用[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)方法[GetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.getvalue)和[SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue)，这是基础属性系统的连接点。 而是，现有的实施CLR属性将已经调用了[GetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.getvalue)和[SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue)内`get`和`set`适当地使用标识符字段的属性的包装器实现. 若要自己实现自定义依赖属性，则需要使用类似的方法定义包装器。

### 应该何时实现依赖属性？

上一个类，实现属性，只要类派生自[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)，可以选择支持与属性[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)标识符，因此若要使其依赖项属性。 不必总是将属性实现为依赖属性，这不一定合适，具体取决于方案需要。 有时，使用私有字段支持属性的通常方法已足够满足需求。 但是，如果要使属性支持以下一个或多个 WPF 功能，则应该将属性实现为依赖属性：

- 需要可以在样式中设置属性。 有关详细信息，请参阅[样式设置和模板化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/styling-and-templating)。
- 需要属性支持数据绑定。 有关数据绑定依赖属性的详细信息，请参阅[绑定两个控件的属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-bind-the-properties-of-two-controls)。
- 需要可以使用动态资源引用设置属性。 有关详细信息，请参阅 [XAML 资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-resources)。
- 需要从元素树中的父元素自动继承属性值。 在这种情况下，注册[RegisterAttached](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.registerattached)方法，即使您还创建了属性包装器的CLR访问。 有关详细信息，请参阅[属性值继承](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/property-value-inheritance)。
- 需要属性可以进行动画处理。 有关详细信息，请参阅 [动画概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/animation-overview)。
- 需要属性系统在先前的值因属性系统、环境或用户执行的操作而发生更改，或者因读取和使用样式而发生更改时进行报告。 通过使用属性元素据，属性可以指定回调方法，每次属性系统确定属性值已明确改动时将调用此回调方法。 与此相关的一个概念是属性值强制转换。 有关详细信息，请参阅[依赖属性回调和验证](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-callbacks-and-validation)。
- 需要使用同时也被 WPF 进程使用的已建立的元数据约定，例如报告更改属性值是否应需要布局系统重新安排元素的可视内容。 或者需要能够使用元素据替代，以便派生类可以更改基于元数据的特性，例如默认值。
- 你想接收 Visual Studio WPF 设计器的自定义控件的属性支持，如**属性**窗口编辑。 有关详细信息，请参阅[控件创作概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/control-authoring-overview)。

检查这些方案时，还应考虑是否可以通过替代现有依赖属性的元素据而不是通过实现一个全新的属性来实现方案。元素据替代是否可行取决于方案以及方案与现有的 WPF 依赖属性和类中的实现的相似度。 有关替代现有属性上的元素据的详细信息，请参阅[依赖属性元素据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-metadata)。

### 定义依赖属性的检查清单

定义依赖属性包含 4 个不同的概念。 这些概念并不一定是严格的过程步骤，因为其中一些概念在实现中会被合并为一行代码：

- （可选）创建依赖属性的属性元素据。
- 在属性系统中注册属性名称，并指定所有者类型和属性值类型。 此外，还应指定属性元素据（如果用到）。
- 定义[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)标识符作为`public` `static` `readonly`字段上的所有者类型。
- 定义一个 CLR“包装器”属性，并且其名称与依赖属性名称相匹配。 实现 CLR“包装器”属性的 `get` 和 `set` 访问器，以连接支持此属性的依赖属性。

#### 在属性系统中注册属性

为使属性成为依赖属性，必须在属性系统维护的表中注册该属性，并为属性指定一个唯一标识符。此唯一标识符会用作后续属性系统操作的限定符。 这些操作可能是内部操作，也可能使用你自己的代码调用属性系统 API。 若要注册该属性，请调用[Register](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.register)类 （在类中，但任何成员定义外） 的正文中的方法。 此外提供标识符字段[Register](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.register)方法调用，作为返回值。 原因，[Register](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.register)完成调用之外其他成员定义是因为使用此返回值分配并创建`public` `static` `readonly`类型的字段[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)作为您的类的一部分。 此字段会作为依赖属性的标识符。

```csharp
public static readonly DependencyProperty AquariumGraphicProperty = DependencyProperty.Register(
  "AquariumGraphic",
  typeof(Uri),
  typeof(AquariumObject),
  new FrameworkPropertyMetadata(null,
      FrameworkPropertyMetadataOptions.AffectsRender, 
      new PropertyChangedCallback(OnUriChanged)
  )
);
```

#### 依赖属性命名约定

必需完全遵循已有的依赖属性命名约定，例外情况除外。

依赖项属性本身有一个基本的名称，"AquariumGraphic 此示例中，它被指定为第一个参数的[Register](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.register)。 此名称在每个注册类型内必须唯一。 通过基类型继承的依赖属性会被视为注册类型的已有部分；无法再次注册已继承属性的名称。 但是，即使不继承依赖属性，也有方法可将类添加为依赖属性的所有者；有关详细信息，请参阅[依赖属性元素据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-metadata)。

创建标识符字段时，按注册时的属性名称命名此字段，再加上后缀 `Property`。 该字段是依赖属性的标识符，它将在稍后用作的输入[SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue)和[GetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.getvalue)允许您将在包装器，通过任何其他代码访问权限由你自己的代码，该属性由外部代码中你的调用由属性系统，以及可能通过XAML处理器。

> 在类的主体中定义依赖属性是典型的实现，但也可以在类静态构造函数中定义依赖属性。 需要多行代码来初始化依赖属性时，此方法会很有用。

#### 实现“包装器”

应调用包装器实现[GetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.getvalue)中`get`实现中，并[SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue)中`set`（原始注册调用和字段，此处也显示为清楚起见） 的实现。

在所有例外情况除外，应仅执行包装器实现[GetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.getvalue)和[SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue)操作，分别。 其原因请参阅 [XAML 加载和依赖属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-loading-and-dependency-properties)主题。

WPF 类上提供的所有现有公共依赖属性都使用这一简单的包装器实现模型；大多数情况下，依赖属性工作原理的复杂性本质上在于它是属性系统的行为，还是通过其他概念（例如强制转换或通过属性元数据进行的属性更改回调）实现的行为。

```csharp
public static readonly DependencyProperty AquariumGraphicProperty = DependencyProperty.Register(
  "AquariumGraphic",
  typeof(Uri),
  typeof(AquariumObject),
  new FrameworkPropertyMetadata(null,
      FrameworkPropertyMetadataOptions.AffectsRender, 
      new PropertyChangedCallback(OnUriChanged)
  )
);
public Uri AquariumGraphic
{
  get { return (Uri)GetValue(AquariumGraphicProperty); }
  set { SetValue(AquariumGraphicProperty, value); }
}
```

同样，按照约定，包装器属性的名称必须是选择并指定为第一个参数的名称相同[Register](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.register)注册属性的调用。 如果属性不遵从此约定，尽管不一定会禁用所有可能的用法，但你会遇到几个比较突出的问题：

- 样式和模板的某些方面不起作用。
- 大多数工具和设计器必须依赖命名约定，才能正确序列化 XAML 或在每个属性级别提供设计器环境帮助。
- 处理特性值时，WPF XAML 加载程序的会完全跳过包装器，并依赖于命名约定。 有关详细信息，请参阅 [XAML 加载和依赖属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-loading-and-dependency-properties)。

####  新依赖属性的属性元数据

注册依赖属性时，通过属性系统进行注册会创建一个存储属性特征的元素据对象。 其中许多特性具有默认值，如果该属性是否已注册的简单签名都将设置[Register](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.register)。 其他签名[Register](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.register)，可以指定你想为您注册该属性的元数据。为依赖属性使用的最常见元数据是为其使用默认值。该默认值适用于使用此属性的新实例。

如果要创建存在的依赖关系属性在派生类的[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)，可以使用更专业的元数据类[FrameworkPropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata)而不是基[PropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata)类。 构造函数[FrameworkPropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata)类具有多个签名可在其中指定各种元数据特性结合使用。 如果你想要指定的默认值，使用采用单个参数的类型的签名[Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object)。将该对象参数作为属性的特定于类型的默认值 (提供的默认值必须是作为提供类型`propertyType`中的参数[Register](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.register)调用)。

有关[FrameworkPropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata)，您还可以指定该属性的元数据选项标志。 注册后这些标记会转换为属性元素据上的不同属性，并用于将某些条件传送给布局引擎等其他进程。

#### 设置合适的元数据标记

- 如果属性 （或值的更改） 将影响用户界面 (UI)，并特别是影响布局系统的大小或呈现的页上，将元素的方式将设置一个或多个下列标志： [AffectsMeasure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadataoptions#System_Windows_FrameworkPropertyMetadataOptions_AffectsMeasure)， [AffectsArrange](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadataoptions#System_Windows_FrameworkPropertyMetadataOptions_AffectsArrange)， [AffectsRender](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadataoptions#System_Windows_FrameworkPropertyMetadataOptions_AffectsRender)。
  - [AffectsMeasure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadataoptions#System_Windows_FrameworkPropertyMetadataOptions_AffectsMeasure) 指示对此属性的更改需要更改UI呈现其中包含的对象可能需要增加或减少空间父级范围内的。 例如，“宽度”属性应该设置此标记。
  - [AffectsArrange](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadataoptions#System_Windows_FrameworkPropertyMetadataOptions_AffectsArrange) 指示对此属性的更改需要更改UI呈现，通常不需要更改在专用空间中，但不指明该空间内的位置已更改。 例如，“对齐”属性应该设置此标记。
  - [AffectsRender](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadataoptions#System_Windows_FrameworkPropertyMetadataOptions_AffectsRender) 指示发生的一些其他更改不会影响布局和度量值，但需要其他的呈现。 更改现有元素的颜色的属性便是一个示例，例如“背景”。
  - 对属性系统或布局回调进行自己的替代实现时，这些标记通常用作元数据中的协议。 例如，您可能有[OnPropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.onpropertychanged)将调用的回调[InvalidateArrange](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.invalidatearrange)如果实例的任何属性报告值发生了更改，并具有[AffectsArrange](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata.affectsarrange)作为`true`其元数据中。
- 超出上述所需大小时，某些属性可能会影响所含父元素的呈现特征。 例如，[MinOrphanLines](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph.minorphanlines)对该属性的更改可以在其中更改包含段落的流文档的整个呈现流文档模型中使用的属性。 使用[AffectsParentArrange](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadataoptions#System_Windows_FrameworkPropertyMetadataOptions_AffectsParentArrange)或[AffectsParentMeasure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadataoptions#System_Windows_FrameworkPropertyMetadataOptions_AffectsParentMeasure)来标识您自己的属性中相似的情况。
- 默认情况下，依赖属性支持数据绑定。 在无实际的数据绑定方案或大型对象的数据绑定性能构成问题的情况下，可有意禁用数据绑定。
- 默认情况下，数据绑定[Mode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.mode)的依赖项属性值默认为[OneWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_OneWay)。 您始终可以更改绑定要[TwoWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_TwoWay)每个绑定实例; 有关详细信息，请参阅[指定绑定的方向](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-specify-the-direction-of-the-binding)。 作为依赖属性的作者，你可以选择要使用的属性，但[TwoWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_TwoWay)默认情况下的绑定模式。 现有依赖属性的一个示例是[MenuItem.IsSubmenuOpen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem.issubmenuopen); 此属性的方案是[IsSubmenuOpen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem.issubmenuopen)设置逻辑和的合成[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)与默认主题样式交互。 [IsSubmenuOpen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem.issubmenuopen)属性逻辑在以本机方式使用数据绑定来根据其他状态属性和方法调用保持的属性的状态。 绑定的另一个示例属性[TwoWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_TwoWay)默认情况下是[TextBox.Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.text)。
- 此外可以通过设置启用属性继承自定义依赖属性中的[Inherits](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadataoptions#System_Windows_FrameworkPropertyMetadataOptions_Inherits)标志。 在父元素和子元素具有相同属性的情况中，属性继承非常有用，它可以使子元素将该特定属性值设置为与父元素设置的值相同。 示例可继承的属性是[DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext)，这用于绑定操作，启用数据演示的重要母版-详细信息方案。 通过使[DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext)可继承的任何子元素继承该数据上下文还。 因为使用了属性值继承，你可以在页面或应用程序根目录上指定数据上下文，而无需对所有可能子元素中的绑定重新指定上下文。 [DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext) 也是一个很好的示例来演示继承覆盖默认值，但它可以始终在本地上设置的任何特定的子元素;有关详细信息，请参阅[对分层数据使用主-从模式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-use-the-master-detail-pattern-with-hierarchical-data)。属性值继承确实可能存在性能成本，因此应谨慎使用；有关详细信息，请参阅[属性值继承](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/property-value-inheritance)。
- 设置[Journal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadataoptions#System_Windows_FrameworkPropertyMetadataOptions_Journal)标志，用于指示是否应检测到或者使用导航日志服务的依赖项属性。 例如，[SelectedIndex](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.selector.selectedindex)属性; 在所选内容中选择任何项时导航日志历史记录应保留控件。

### 只读依赖项属性

可以定义只读的依赖属性。 但是，为何将属性定义为只读的情况略有不同，其过程与在属性系统中注册属性并公开标识符相同。 有关详细信息，请参阅[只读依赖属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/read-only-dependency-properties)。

### 集合类型依赖项属性

集合类型依赖属性要考虑一些其他实现问题。 有关详细信息，请参阅[集合类型依赖属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/collection-type-dependency-properties)。

### 依赖属性安全注意事项

依赖属性应声明为公共属性。 依赖属性标识符字段应声明为公共静态字段。 即使尝试声明其他访问级别（例如受保护），也始终可以通过标识符和属性系统 API 来访问依赖属性。 由于元数据报告或值确定受保护的标识符字段，甚至是可以访问API属于属性系统，如[LocalValueEnumerator](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.localvalueenumerator)。 有关详细信息，请参阅[依赖属性的安全性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-security)。

### 依赖属性和类构造函数

托管代码编程（通常通过FxCop 等代码分析工具强制执行）的一般原则是：类构造函数不应调用虚方法。 这是因为构造函数可以作为派生的类构造函数的基本初始化来调用，并且可能会在所构造的对象实例不完全初始化状态下通过构造函数输入虚方法。 从已派生自任何类派生时[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)，应注意，属性系统本身调用，并在内部公开虚方法。 这些虚方法属于 WPF 属性系统服务。 替代方法会使派生类参与值确定。 为避免运行时初始化出现潜在问题，，不应该在类的构造函数中设置依赖属性值，除非遵循特定的构造函数模式进行操作。 有关详细信息，请参阅 [DependencyObject 的安全构造函数模式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/safe-constructor-patterns-for-dependencyobjects)。

## [Dependency Property Metadata](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/dependency-property-metadata)

Windows Presentation Foundation (WPF) 属性系统包括一个元数据报告系统，该系统不局限于可以通过反射或常规公共语言运行时 (CLR) 特征报告的关于某个属性的内容。 依赖属性的元数据还可以由定义依赖属性的类来唯一地分配，可以在依赖属性添加到另一个类时进行更改，可以由所有从定义基类继承依赖属性的派生类来明确地重写。

### 系统必备

本主题假定你从 Windows Presentation Foundation (WPF) 类的现有依赖属性的使用者角度了解依赖属性，并且已阅读[依赖属性概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-properties-overview)。 若要理解本主题中的示例，还应当了解 XAML 并知道如何编写 WPF 应用程序。

### 依赖属性元数据的使用方式

依赖属性的元数据作为一个对象存在，可以通过查询该对象来检查依赖属性的特征。 当属性系统处理任何给定的依赖属性时，也会经常访问这些元数据。 依赖属性的元数据对象可以包含以下类型的信息：

- 依赖属性的默认值（如果通过本地值、样式和继承等信息不能确定依赖属性的其他任何值）。有关在为依赖属性赋值时，默认值如何参与属性系统所使用的优先级的完整讨论，请参阅[依赖属性值优先级](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-value-precedence)。
- 对影响每个所有者类型的强制行为或更改通知行为的回叫实现的引用。 请注意，这些回叫通常是用非公共访问级别定义的，因此，除非实际引用位于允许的访问范围内，否则通常无法从元数据获得这些引用。 有关依赖属性回叫的详细信息，请参阅[依赖属性回调和验证](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-callbacks-and-validation)。
- 如果所讨论的依赖属性被视为一个 WPF 框架级别的属性，则元数据中可能包含 WPF 框架级别的依赖属性特征，这些特征报告各种服务（如 WPF 框架级别的布局引擎和属性继承逻辑）的信息和状态。 有关依赖属性元数据的这一方面的详细信息，请参阅[框架属性元数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/framework-property-metadata)。

### 元数据 API

报告的大多数属性系统使用的元数据信息的类型是[PropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata)类。 在向属性系统注册依赖属性时，可以选择指定元数据实例，并且可以为以下附加类型再次指定这些实例：将自身作为所有者添加的类型，或者重写它们从基类依赖属性定义继承的元数据的类型。 (未指定默认值的元数据属性注册的情况下为[PropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata)创建该类的默认值。)作为返回的已注册的元数据[PropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata)当您调用各种[GetMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.getmetadata)获取依赖属性元数据的重载[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)实例。

[PropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata)类然后派生自，如 WPF 框架级别类的体系结构区域提供更多特定元数据。 [UIPropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uipropertymetadata)添加动画报告功能，和[FrameworkPropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata)提供上一部分中提到的 WPF 框架级别属性。 注册依赖属性之后，他们可以注册使用这些[PropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata)派生的类。 检查元数据之后，即基[PropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata)可能进行类型转换为派生类，以使您可以检查更具体的属性。

> 可以在中指定的属性特征[FrameworkPropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata)有时称为在本文档中称为"标志"。 当你使用新的元数据实例中创建依赖关系属性注册或元数据重写时，指定使用按标志枚举这些值[FrameworkPropertyMetadataOptions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadataoptions)，然后提供到枚举的可能连接的值[FrameworkPropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata)构造函数。 但是，构造后，这些选项特征公开内[FrameworkPropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata)作为一系列布尔属性，而不是构造枚举值。 使用布尔属性，可以检查每个条件，而不必为了获得感兴趣的信息而向按标志枚举值应用掩码。 构造函数使用连接[FrameworkPropertyMetadataOptions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadataoptions)为了使构造函数签名的长度合理的而实际构造的元数据公开不同的属性，使查询更直观的元数据。

### 何时重写元数据以及何时派生类

WPF 属性系统已经建立了如下功能：在不必完全重新实现依赖属性的情况下，更改依赖属性的某些特征。 这是通过为特定类型上所存在的依赖属性构造不同的属性元数据实例来完成的。 请注意，现有的大多数依赖属性都不是虚拟属性，因此，严格地说，只能通过隐藏现有成员来针对继承类“重新实现”依赖属性。

如果尝试对某个类型的依赖属性启用的方案不能通过修改现有依赖属性的特征来完成，则可能有必要创建一个派生类，然后为该派生类声明一个自定义依赖属性。 自定义依赖属性与 WPF API 定义的依赖属性具有相同的行为。 有关自定义依赖属性的更多详细信息，请参阅[自定义依赖属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/custom-dependency-properties)。

不能重写的依赖属性的一个显著特征就是它的值类型。 如果要继承的依赖属性的行为与所需的行为大体相同，但是要求它具有另一种类型，则必须实现一个自定义依赖属性，可能还需要通过类型转换或其他实现机制在自定义类上链接这些属性。 此外，不能替换现有[ValidateValueCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.validatevaluecallback)，因为此回叫存在于注册字段本身而不是在其元数据。

### 更改现有元数据的方案

如果要处理现有依赖属性的元数据，则更改依赖属性元数据的一种常见方案是更改默认值。 更改或添加属性系统回叫是一种更高级的方案。 如果所实现的派生类的依赖属性之间具有不同的相互关系，则你可能希望这样做。 让编程模型既支持代码又支持声明性用法的条件之一就是，属性必须能够按任何顺序设置。 因此，需要在没有上下文的情况下实时设置任何依赖属性，而且可以不必知道设置顺序（例如，可能在构造函数中找到的顺序）。 有关属性系统这一方面的详细信息，请参阅[依赖属性回调和验证](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-callbacks-and-validation)。 请注意，验证回叫不是元数据的一部分，而是依赖属性标识符的一部分。 因此，不能通过重写元数据来更改验证回叫。

在某些情况下，可能还希望在现有的依赖属性上改变 WPF 框架级别的属性元数据选项。 这些选项将有关 WPF 框架级别属性的某些已知条件传递到其他 WPF 框架级别的进程，例如布局系统。 设置选项通常这是注册新的依赖项属性，但也可以作为的一部分更改 WPF 框架级别的属性元数据[OverrideMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.overridemetadata)或[AddOwner](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.addowner)调用。 有关要使用的特定值以及详细信息，请参阅[框架属性元数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/framework-property-metadata)。 有关应当如何为新注册的依赖属性设置这些选项的详细信息，请参阅[自定义依赖属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/custom-dependency-properties)。

#### 重写元数据

重写元数据的主要目的在于，使你有机会更改各种派生自元数据的行为，这些行为应用于类型上存在的依赖属性。[元数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-metadata#dp_metadata_contents)一节中更详细地介绍了重写元数据的原因。 有关详细信息（包括一些代码示例），请参阅[重写依赖属性的元数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-override-metadata-for-a-dependency-property)。

属性元数据可以在注册调用期间提供的依赖项属性 ([Register](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.register))。 但是，在许多情况下，当类继承该依赖属性时，你可能希望为该类提供特定于类型的元数据。 您可以执行此操作通过调用[OverrideMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.overridemetadata)方法。 例如，从WPFAPI，则[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)类是第一次注册的类型[Focusable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.focusable)依赖项属性。 但[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)类重写依赖属性提供自己的初始默认值，将它从元数据`false`到`true`，否则重新使用原始和[Focusable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.focusable)实现。

当你重写元数据时，系统会合并或替换不同的元数据特征。

- [PropertyChangedCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.propertychangedcallback) 合并。 如果您将添加一个新[PropertyChangedCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.propertychangedcallback)，该回叫存储在元数据。 如果未指定[PropertyChangedCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.propertychangedcallback)重写时，值[PropertyChangedCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.propertychangedcallback)升级为从在元数据中指定它的最近上级的引用。
- 实际属性系统行为[PropertyChangedCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.propertychangedcallback)是层次结构中的所有元数据所有者的实现都保留并添加到表中，属性系统的执行顺序是首先调用派生程度最高的类的回叫。
- [DefaultValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.defaultvalue) 将被替换。 如果未指定[DefaultValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.defaultvalue)重写时，值[DefaultValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.defaultvalue)来自元数据中指定的最近上级。
- [CoerceValueCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.coercevaluecallback) 实现将替换为。 如果您将添加一个新[CoerceValueCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.coercevaluecallback)，该回叫存储在元数据。 如果未指定[CoerceValueCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.coercevaluecallback)重写时，值[CoerceValueCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.coercevaluecallback)升级为从在元数据中指定它的最近上级的引用。
- 属性系统行为是仅[CoerceValueCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.coercevaluecallback)调用直接元数据中。 没有对其他引用[CoerceValueCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.coercevaluecallback)保留层次结构中的实现。

此行为通过[Merge](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.merge)，并可以对派生的元数据类中重写。

#### 重写附加属性元数据

在 WPF 中，附加属性作为依赖属性来实现。 这意味着它们还具有能够由个别类重写的属性元数据。 中的附加属性的作用域注意事项WPF通常是，任何[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)可以具有在其上设置附加的属性。 因此，任何[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)因为它可能会设置类的实例上，派生的类可以重写任何附加属性的元数据。 可以重写默认值、回叫或 WPF 框架级别的特征报告属性。 如果针对类的实例设置了附加属性，则这些重写属性元数据特征将适用。例如，可以重写默认值，这样，只要未以其他方式设置附加属性，重写值就会报告为类实例的附加属性的值。

> [Inherits](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata.inherits)属性不相关的附加属性。

#### 将类作为现有依赖属性的所有者来添加

一个类可以将其自身添加为已注册，通过使用依赖属性的所有者[AddOwner](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.addowner)方法。 这使得该类可以使用最初针对另一个类型注册的依赖属性。 添加类通常不是首先将该依赖属性注册为所有者的类型的派生类。 实际上，这使类及其派生类可以“继承”依赖属性实现，而不需要最初的所有者类，而且添加类也不必位于同一个实际的类层次结构中。 另外，添加类（以及所有派生类）随后可以为最初的依赖属性提供特定于类型的元数据。

添加类除了通过属性系统的实用工具方法将自身添加为所有者以外，还应当在自身声明其他公共成员，以使依赖属性向代码和标记公开，从而完全参与属性系统。 就为依赖属性公开对象模型而言，添加现有依赖属性的类与定义新的自定义依赖属性的类具有相同的职责。 要公开的第一个此类成员是依赖属性标识符字段。 此字段应`public static readonly`类型的字段[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)，该值将赋给的返回值[AddOwner](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.addowner)调用。 要定义的第二个成员是公共语言运行时 (CLR)“包装器”属性。 包装器，可以更方便地操作在代码中的依赖属性 (避免调用[SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue)每个时间，并可以在包装器本身进行此调用一次)。 包装器的实现方式与在注册自定义依赖属性时的实现方式完全相同。 有关实现依赖属性的详细信息，请参阅[自定义依赖属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/custom-dependency-properties)和[为依赖属性添加所有者类型](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-add-an-owner-type-for-a-dependency-property)。

#### AddOwner 和附加属性

您可以调用[AddOwner](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.addowner)由所有者类定义为附加属性的依赖项属性。 这样做的目的通常是为了将以前附加的属性作为非附加依赖属性来公开。 然后将公开[AddOwner](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.addowner)返回值作为`public static readonly`用作依赖项属性标识符字段，将定义适当的"包装"属性，以便该属性出现在成员表中并支持非附加属性在类中的使用情况。

## [Framework Property Metadata](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/framework-property-metadata)

对于 Windows Presentation Foundation (WPF) 体系结构中被视为 WPF 框架级的对象元素的属性，将报告框架属性元数据选项。 通常，WPF 框架级指示要求 WPF 演示 API 和可执行文件处理呈现、数据绑定和属性系统优化等功能。 这些系统对框架属性元数据进行查询，以便为特定的元素属性确定特定于功能的特征。



### 先决条件

本主题假定你从 Windows Presentation Foundation (WPF) 类的现有依赖属性的使用者角度了解依赖属性，并且已阅读[依赖属性概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-properties-overview)。 另外，应当已阅读[依赖属性元数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-metadata)。

### 框架属性元数据传达的信息

框架属性元数据分为以下类别：

- 报告影响某个元素的布局属性 ([AffectsArrange](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata.affectsarrange)， [AffectsMeasure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata.affectsmeasure)， [AffectsRender](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata.affectsrender))。 如果的属性会影响这些相应方面，和你要实现，则可能会在元数据中设置这些标志[MeasureOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.measureoverride) / [ArrangeOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.arrangeoverride)中您的类提供特定的呈现行为和布局信息的方法系统。 通常，如果在属性元数据中有布局属性为 true，则此类实现会在依赖属性中检查属性是否无效，并且只有无效属性才必须请求新的布局处理过程。

- 报告影响元素的父元素的布局属性 ([AffectsParentArrange](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata.affectsparentarrange)， [AffectsParentMeasure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata.affectsparentmeasure))。 下面是一些示例，默认情况下设置了这些标志[FixedPage.Left](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.fixedpage.left)和[Paragraph.KeepWithNext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph.keepwithnext)。

- [Inherits](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata.inherits)。 默认情况下，依赖属性不会继承值。 [OverridesInheritanceBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata.overridesinheritancebehavior) 允许继承纳入可视化树中，这是某些控件复合方案所需的路径。

   备注

  属性值上下文中的术语“继承”指特定于依赖属性的情况；它意味着由于存在 WPF 属性系统的 WPF 框架级功能，子元素可以从父元素继承实际的依赖属性值。 它与通过派生类型的托管代码类型和成员继承没有直接关系。 有关详细信息，请参阅[属性值继承](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/property-value-inheritance)。

- 报告数据绑定特性 ([IsNotDataBindable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata.isnotdatabindable)， [BindsTwoWayByDefault](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata.bindstwowaybydefault))。 默认情况下，框架中的依赖属性支持具有单向绑定行为的数据绑定。 如果数据绑定没有适用的方案，则可禁用数据绑定（因为这些属性应该是灵活且可扩展的，所以在默认的 WPF API 中没有太多此类属性的示例）。 您可能会将绑定设置为具有双向绑定在一起在其组件部分之间的控件的行为的属性默认值 ([IsSubmenuOpen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem.issubmenuopen)是一个示例) 或双向绑定时的常见、 最期望的方案，为用户的 ([Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.text)是一个示例)。 更改与数据绑定相关的元数据只会影响默认值；始终可以根据各个绑定更改此默认值。 若要详细了解常规的绑定模式和绑定，请参阅[数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview)。

- 报告属性是否应记录的应用程序或服务支持日记功能 ([Journal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata.journal))。 对于一般的元素，默认情况下不会启用日记记录功能，但可针对特定用户输入控件有选择性地启用。 此属性专门由日记记录的 WPF 实现等日记记录服务读取，并且通常针对用户控件（例如用户在列表中选择的应在各导航步骤中保留的控件）设置此属性。 有关日记的信息，请参阅[导航概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-overview)。

### 读取 FrameworkPropertyMetadata

每个以上链接的属性是特定属性的[FrameworkPropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata)将添加到其直接基类[UIPropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uipropertymetadata)。 默认情况下，这些属性都为 `false`。 在其中了解这些属性的值很重要的属性的元数据请求应尝试强制转换为返回的元数据[FrameworkPropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata)，然后根据需要检查各个属性的值。

### 指定元数据

创建元数据的新实例用于将元数据应用于新的依赖关系属性注册时，必须选择要使用的元数据类： 基[PropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata)或某些派生类，如[FrameworkPropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata)。 一般情况下，应使用[FrameworkPropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata)，尤其是在您的属性具有与属性系统进行任何交互和WPF布局和数据绑定之类的函数。 对于更复杂的方案的另一个选项是派生自[FrameworkPropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata)创建你自己的元数据报告以及附加信息的类成员中执行。 或者您可能使用[PropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata)或[UIPropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uipropertymetadata)进行通信的功能的实现支持的程度。

对于现有属性 ([AddOwner](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.addowner)或[OverrideMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.overridemetadata)调用)，则应始终会重写与原始注册所使用的元数据类型。

如果要创建[FrameworkPropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata)实例时，有两种方法来填充该元数据与特定通信框架属性特征的属性的值：

1. 使用[FrameworkPropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata)构造函数的签名，使`flags`参数。 此参数应填入所有所需的组合值的[FrameworkPropertyMetadataOptions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadataoptions)枚举标志。
2. 使用而无需签名之一`flags`参数，然后将每个报告布尔值属性上设置[FrameworkPropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata)到`true`为每个所需的特征更改。 为此，必须在构造具有此依赖属性的任何元素之前对这些属性进行设置；布尔属性是可读写属性，以允许此项避免 `flags` 参数的行为，同时仍然可以填充元数据，但元数据必须在属性使用之前进行有效密封。 因此，尝试在请求元数据之后设置属性是无效操作。

### 框架属性元数据合并行为

重写框架属性元数据时，会合并或替换不同的元数据特征。

- [PropertyChangedCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.propertychangedcallback) 合并。 如果您将添加一个新[PropertyChangedCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.propertychangedcallback)，该回叫存储在元数据。 如果未指定[PropertyChangedCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.propertychangedcallback)重写时，值[PropertyChangedCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.propertychangedcallback)升级为从在元数据中指定它的最近上级的引用。
- 实际属性系统行为[PropertyChangedCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.propertychangedcallback)是实现为层次结构中的所有元数据所有者都将保留并添加到表的最深派生类的回调属性系统的执行顺序第一次调用。 继承的回叫仅运行一次，当将这些回叫放置在元数据中的类占有时计数。
- [DefaultValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.defaultvalue) 将被替换。 如果未指定[PropertyChangedCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.propertychangedcallback)重写时，值[DefaultValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.defaultvalue)来自元数据中指定的最近上级。
- [CoerceValueCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.coercevaluecallback) 实现将替换为。 如果您将添加一个新[CoerceValueCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.coercevaluecallback)，该回叫存储在元数据。 如果未指定[CoerceValueCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.coercevaluecallback)重写时，值[CoerceValueCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.coercevaluecallback)升级为从在元数据中指定它的最近上级的引用。
- 属性系统行为是仅[CoerceValueCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.coercevaluecallback)调用直接元数据中。 没有对其他引用[CoerceValueCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata.coercevaluecallback)保留层次结构中的实现。
- 所用的标志[FrameworkPropertyMetadataOptions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadataoptions)枚举组合为按位或运算。 如果指定[FrameworkPropertyMetadataOptions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadataoptions)，不会覆盖原始选项。 若要更改某个选项，设置相应的属性上[FrameworkPropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata)。 例如，如果原始[FrameworkPropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata)对象集[FrameworkPropertyMetadataOptions.NotDataBindable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadataoptions#System_Windows_FrameworkPropertyMetadataOptions_NotDataBindable)标志，你可以通过设置更改[FrameworkPropertyMetadata.IsNotDataBindable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata.isnotdatabindable)到`false`。

此行为通过[Merge](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata.merge)，并可以对派生的元数据类中重写。

## [Dependency Property Value Precedence](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/dependency-property-value-precedence)

本主题说明 Windows Presentation Foundation (WPF) 属性系统的工作机制如何影响依赖属性的值，并介绍应用于属性有效值的属性系统的各方面所依据的优先级。

### 系统必备

本主题假定你从 WPF 类的现有依赖属性的使用者角度了解依赖属性，并且已阅读[依赖属性概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-properties-overview)。 若要采用本主题中的示例，还应当了解可扩展应用程序标记语言 (XAML) 并知道如何编写 WPF 应用程序。

### WPF 属性系统

WPF 属性系统提供一种强大的方法，使得依赖属性的值由多种因素决定，从而实现诸如实时属性验证、后期绑定以及向相关属性发出有关其他属性值发生更改的通知等功能。 用来确定依赖属性值的确切顺序和逻辑相当复杂。了解此顺序有助于避免不必要的属性设置，并且还有可能澄清混淆，使你正确了解为何某些影响或预测依赖属性值的尝试最终却没有得出所期望的值。

### 依赖属性可以在多个位置“设置”

下面是示例XAML其中相同的属性 ([Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)) 具有三个不同"set"可能会影响值的操作。

```xaml
    <Button Background="Red">
      <Button.Style>
        <Style TargetType="{x:Type Button}">
          <Setter Property="Background" Value="Green"/>
          <Style.Triggers>
            <Trigger Property="IsMouseOver" Value="True">
              <Setter Property="Background" Value="Blue" />
            </Trigger>
          </Style.Triggers>
        </Style>
      </Button.Style>
Click
    </Button>
```

这里，你希望应用什么颜色：红色、绿色还是蓝色？

本地属性集在设置时具有最高优先级，动画值和强制除外。 如果在本地设置某个值，你可以期待该值优先得到应用，甚至期待其优先级高于任何样式或控件模板。 在本示例中[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)本地设置为红色。 因此，即使它可能会应用于该作用域中该类型的所有元素的隐式样式定义在此范围内的样式不是为提供的最高优先级[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)属性及其值。 如果从该 Button 实例中删除本地值“Red”，样式将获得优先级，而按钮将从该样式中获得 Background 值。 在该样式中，触发器具有优先级，因此当鼠标位于按钮上时，按钮为蓝色，其他情况下则为绿色。

### 依赖属性设置优先级列表

下面是属性系统在分配依赖属性的运行时值时所使用的最终顺序。 最高优先级最先列出。 此列表对[依赖属性概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-properties-overview)中的某些一般化内容进行了扩充。

1. **属性系统强制。** 有关强制的详细信息，请参阅本主题后面的[强制、动画和基值](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-value-precedence#animations)。
2. **活动动画或具有 Hold 行为的动画。** 为了获得任何实用效果，属性的动画必须优先于基（未动画）值，即使该值是在本地设置的也是如此。 有关详细信息，请参阅本主题后面的[强制、动画和基值](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-value-precedence#animations)。
3. **本地值。** 可能会通过"包装器"属性，这也相当于为属性或属性元素中设置的方便地设置本地值XAML，或通过调用[SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue)API使用特定实例的属性。 如果使用绑定或资源来设置本地值，则每个值都按照直接设置值的优先级顺序来应用。
4. **TemplatedParent 模板属性。** 元素具有[TemplatedParent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.templatedparent)如果将其创建为模板的一部分 ([ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)或[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate))。 有关何时应用此原则的详细信息，请参阅本主题后面的 [TemplatedParent](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-value-precedence#templatedparent)。 在模板中，按以下优先级顺序应用：
   1. 从触发[TemplatedParent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.templatedparent)模板。
   2. 属性集 (通常通过XAML属性) 中[TemplatedParent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.templatedparent)模板。
5. **隐式样式。** 仅应用于 `Style` 属性。 `Style` 属性是由任何样式资源通过与其类型匹配的键来填充的。 该样式资源必须存在于页面或应用程序中；查找隐式样式资源不会进入到主题中。
6. **样式触发器。** 来自页面或应用程序的样式中的触发器（这些样式可以是显式或隐式样式，但不是来自优先级较低的默认样式）。
7. **模板触发器。** 来自样式中的模板或者直接应用的模板的任何触发器。
8. **样式资源库。** 从值[Setter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.setter)来自页面或应用程序的样式中。
9. **默认（主题）样式。** 有关何时应用此样式以及主题样式如何与主题样式中的模板相关的详细信息，请参阅本主题后面的[默认（主题）样式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-value-precedence#themestyles)。 在默认样式中，按以下优先级顺序应用：
   1. 主题样式中的活动触发器。
   2. 主题样式中的资源库。
10. **继承。** 有几个依赖属性从父元素向子元素继承值，因此不需要在应用程序中的每个元素上专门设置这些属性。 有关详细信息，请参阅[属性值继承](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/property-value-inheritance)。
11. **来自依赖属性元数据的默认值。** 任何给定的依赖属性都可能有一个默认值，它由该特定属性的属性系统注册来确定。 而且，继承依赖属性的派生类可以选择按照类型重写该元数据（包括默认值）。 有关详细信息，请参阅[依赖属性元数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-metadata)。 因为继承是在默认值之前检查的，所以对于继承的属性，父元素的默认值优先于子元素。 因此，如果任何地方都没有设置可继承的属性，将使用在根元素或父元素中指定的默认值，而不是子元素的默认值。

### TemplatedParent

TemplatedParent 作为一个优先级项并不应用于在标准应用程序标记中直接声明的元素的任何属性。 只有对于通过应用模板而产生的可视化树中的子项而言，才存在 TemplatedParent 概念。 当属性系统搜索[TemplatedParent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.templatedparent)值的模板，就在搜索创建该元素的模板。 属性值从[TemplatedParent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.templatedparent)模板通常就像它们在子元素上设置本地值一样，但此优先级低于本地值存在，因为模板有可能被共享。 有关详细信息，请参阅[TemplatedParent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.templatedparent)。

### Style 属性

前面介绍的查找顺序适用于之外的所有可能的依赖关系属性：[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.style)属性。 [Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.style)属性是唯一的因为它不能为自己设置样式，因此优先级项 5 到 8 不适用。 此外，进行动画处理，或强制[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.style)建议不要 (和动画处理[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.style)需要自定义动画类)。 这两种处理均通过三种方式[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.style)可能设置属性：

- **显式样式。** [Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.style)直接设置属性。 在大多数情况下，样式不是内联定义的，而是作为资源由显式键进行引用的。 在这种情况下，Style 属性本身就像本地值（优先级项 3）一样来应用。
- **隐式样式。** [Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.style)未直接设置属性。 但是，[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.style)资源查找序列 （页面、 应用程序） 中的某级别上存在，并且使用的样式是要应用于的类型匹配的资源键进行键控。 在这种情况下，[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.style)属性本身就标识为第 5 项序列中的优先级来。 可以通过使用检测到该条件[DependencyPropertyHelper](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencypropertyhelper)针对[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.style)属性，然后查找[ImplicitStyleReference](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.basevaluesource#System_Windows_BaseValueSource_ImplicitStyleReference)结果中。
- **默认样式**，也称为**主题样式。** [Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.style)属性不直接，设置和实际上将读作`null`直到运行时。 在这种情况下，样式来自作为 WPF 表示引擎一部分的运行时主题评估。

对于主题中不存在的隐式样式，该类型必须完全-匹配`MyButton``Button`的派生的类不会隐式使用的样式`Button`。

### 默认（主题）样式

WPF 附带的每个控件都有一个默认样式。 默认样式可能因主题而异，这就是默认样式有时候称为主题样式的原因。

最重要的信息的控件为其控件模板，主题样式中存在的资源作为默认样式中找到其[Template](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.template)属性。 如果默认样式中没有模板，自定义样式中没有自定义模板的控件将根本没有可视化外观。 默认样式中的模板为每个控件的可视化外观提供一个基本结构，还定义在模板的可视化树中定义的属性与对应的控件类之间的联系。 每个控件都公开一组属性，这些属性可以影响控件的可视化外观，而无需完全替换模板。 例如，考虑的默认可视外观[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)控件，它是一个组件的[ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar)。

一个[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)具有某些可自定义属性。 默认模板[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)创建一个基本结构 / 可视化树与多个嵌套[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)组件创建凹凸效果的外观。 如果是模板的一部分属性应为自定义通过公开[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)类，则该属性必须公开[TemplateBinding](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/templatebinding-markup-extension)，模板中。 情况下[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)，这些边界的各种属性共享模板绑定到属性，如[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border.background)或[BorderThickness](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border.borderthickness)。 但是其他某些属性或可视化排列被硬编码到控件模板中，或者绑定到直接来自主题的值，除了替换整个模板外，不能对其进行更改。 一般而言，如果属性来自模板化的父元素，并且不是通过模板绑定公开的，则不能通过样式进行调整，因为没有简单的方法可以将其设置为目标。 但是，该属性仍然可能受所应用的模板中的属性值继承的影响，或受默认值的影响。

主题样式将类型用作其定义中的键。 但是，当主题应用到给定的元素实例，则此类型的主题查找执行通过检查[DefaultStyleKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.defaultstylekey)控件上的属性。 这与使用文本类型的隐式样式正好相反。 值[DefaultStyleKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.defaultstylekey)会为派生类继承，即使实施者未更改 （更改属性的方式并不是重写该级别的属性，但到改为其默认值属性元数据中的更改）。 这种间接方式使基类可以为没有样式（或者该样式中没有模板，因此根本没有默认的可视化外观，这一点更为重要）的派生元素定义主题样式。 因此，可以派生`MyButton`从[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)并且仍然能够获得[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)默认模板。 如果您的控件作者`MyButton`并希望不同的行为，可以重写的依赖项属性元数据[DefaultStyleKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.defaultstylekey)上`MyButton`以返回不同的密钥，然后定义相关主题样式，包括模板有关`MyButton`，则必须使用打包你`MyButton`控件。 有关主题、样式和控件创作的更多详细信息，请参阅[控件创作概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/control-authoring-overview)。

### 动态资源引用和绑定

动态资源引用和绑定操作遵守其设置位置的优先级。 例如，应用于本地值的动态资源作为优先级项 3 进行应用，主题样式中的属性资源库的绑定作为优先级项 9 进行应用，依此类推。 由于动态资源引用和绑定必须都能够从应用程序的运行时状态中获得值，这使确定任何给定属性的属性值优先级的实际处理也将扩展到运行时。

严格来讲，动态资源引用并不是属性系统的一部分，但它们的确具有自己的查找顺序，该顺序与上面列出的序列交互。 [XAML 资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-resources)中对该优先级进行了更全面的介绍。 该优先级的基本概括是：元素到页面根元素、应用程序、主题、系统。

动态资源和绑定具有其设置位置的优先级，但是值会延迟。 这样的一个后果是，如果将动态资源或绑定设置为某个本地值，则对该本地值的任何更改都会完全替换该动态资源或绑定。 即使你调用[ClearValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.clearvalue)方法以清除本地设置将不会还原值、 动态资源或绑定。 事实上，如果您调用[ClearValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.clearvalue)他们清除的操作 （使用任何文本的本地值） 中具有动态资源或绑定的属性，[ClearValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.clearvalue)调用过。

### SetCurrentValue

[SetCurrentValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setcurrentvalue)方法是另一种方法来设置属性，但它不具有优先级顺序。 相反， [SetCurrentValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setcurrentvalue) ，您可以更改属性的值而不会覆盖以前值的源。 可以使用[SetCurrentValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setcurrentvalue)任何你想要设置一个值，而无需向该值提供某个本地值的优先级的时间。 例如，如果属性是通过触发器设置，然后分配另一个值，通过[SetCurrentValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setcurrentvalue)、 属性系统仍将遵循该触发器和触发器的操作时，该属性将更改。 [SetCurrentValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setcurrentvalue) 可以更改属性的值，而向其提供具有较高优先级的源。 同样，可以使用[SetCurrentValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setcurrentvalue)不覆盖绑定的情况下更改属性的值。

### 强制、动画和基值

强制和动画在本 SDK 中都作用于称为“基值”的值。 因此，基值是在各项中通过向上计算一直到第 2 项为止而确定的任何值。

对于动画，如果没有为某些行为指定“From”和“To”值，或者动画在完成时故意还原为基值，那么基值将影响动画值。 若要了解实际效果，请运行 [From, To, and By Animation Target Values Sample](https://go.microsoft.com/fwlink/?LinkID=159988)（From、To 和 By 动画目标值示例）。 尝试为示例中的矩形高度设置本地值，使初始本地值不同于动画中的任何“From”值。 你会注意到动画立即使用“From”值开始，并在开始后替换基值。 可以指定要返回到是指定 Stop 完成后，在动画之前找到的值[FillBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.fillbehavior)。 然后，根据正常优先级来确定基值。

多个动画可能应用于一个属性，而每个动画可能是从值优先级中的不同点进行定义的。 但是，这些动画的值可能会组合起来，而不仅仅是从较高的优先级开始应用动画。 这完全取决于动画的定义方式以及进行动画处理的值类型。 有关对属性进行动画处理的详细信息，请参阅[动画概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/animation-overview)。

强制在最高级别应用。 即使正在运行的动画也会受到值强制的制约。 WPF 中的某些现有的依赖属性具有内置的强制行为。 通过编写自定义依赖项属性，定义自定义依赖属性的强制行为[CoerceValueCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.coercevaluecallback)和元数据的一部分传递回叫来创建该属性时。 还可以通过在派生类中重写现有属性的元数据来重写其强制行为。 强制与基值的交互使强制约束就像当时存在这些约束一样进行应用，但基值仍将保留。 因此，如果强制约束后来被解除，强制将返回与基值最接近的值，并且一旦所有约束都解除，强制对属性的影响可能会立即停止。 有关强制行为的详细信息，请参阅[依赖属性回调和验证](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-callbacks-and-validation)。

### 触发器行为

控件常常在主题中将触发器行为定义为其默认样式的一部分。 为控件设置本地属性可能会阻止触发器从视觉或行为上响应用户驱动的事件。 属性触发器的最常见用途是为控件或状态属性，例如[IsSelected](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.selector.isselected)。 例如，默认情况下时[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)已禁用 (针对触发[IsEnabled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.isenabled)是`false`) 则[Foreground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.foreground)主题样式中的值是什么导致控件"灰显"。 但是，如果设置了本地[Foreground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.foreground)值，普通灰显颜色将优先级中无效的本地属性集，即使在此属性触发的方案。 为具有主题级触发器行为的属性设置值时要倍加小心，并确保不要过度妨碍该控件应有的用户体验。

### ClearValue 和值优先级

[ClearValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.clearvalue)方法提供了一个有利的途径来清除任何本地应用的值从一个元素设置的依赖项属性。 但是，调用[ClearValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.clearvalue)并不保证数据的默认值为元数据中建立在注册过程，是的新生效值。 值优先级中的所有其他参与者仍然有效。 只有在本地设置的值才会从优先级序列中删除。 例如，如果您调用[ClearValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.clearvalue)属性也由主题样式中，设置该属性，然后为新值而不是基于元数据的默认应用的主题值上。 如果你想要获取进程外的所有属性值参与者并将值设置为已注册的元数据默认值，则可以获取默认值明确通过查询依赖属性元数据，然后可以本地使用的默认值将通过调用属性设置[SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue)。

## [Read-Only Dependency Properties](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/read-only-dependency-properties)

本主题介绍只读依赖属性，包括现有只读依赖属性、创建自定义只读依赖属性的方案和技术。

### 系统必备

本主题假定你了解实现依赖属性的基本方案，以及如何将元数据应用于自定义依赖属性。 有关上下文，请参阅[自定义依赖属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/custom-dependency-properties)和[依赖属性元数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-metadata)。

### 现有只读依赖属性

在 Windows Presentation Foundation (WPF) 框架中定义的某些依赖属性是只读的。 指定只读依赖属性的一般原因如下：这些属性应该用于状态确定，但是有多种因素影响该状态，从用户界面设计的角度看，仅将属性设置为该状态并不能达到预期的效果。 例如，属性[IsMouseOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ismouseover)实际上只显示从鼠标输入确定的状态。 任何通过避开实际的鼠标输入以编程方式设置此值的尝试都是不可预期的，并将导致不一致。

由于其不可设置性，只读依赖属性不适用于依赖属性通常为其提供一个解决方案（即：数据绑定，直接样式化为某个值、验证、动画和继承）的多种方案。 尽管不可设置，但只读依赖属性仍具有一些由属性系统中的依赖属性支持的其他功能。 只读依赖属性仍可以用作样式中的属性触发器，这是其他功能中最重要的功能。 无法使用常规的公共语言运行时 (CLR) 属性启用触发器；必须使用依赖属性才行。 前面提到[IsMouseOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ismouseover)属性是一个最好的例子，它可能是非常有用，可以定义一个控件的样式，其中，某些方案的背景、 前景或类似内复合元素的属性等的可见属性用户将鼠标悬停在控件的某些定义区域时，会更改控件。 只读依赖属性中的更改还可以由属性系统的固有失效进程检测并报告，这实际上是在内部支持属性触发器功能。

### 创建自定义只读依赖属性

请务必阅读上一节中有关只读依赖属性为何不适用于许多典型依赖属性方案的内容。 但是如果有适当的方案，可能需要创建自己的只读依赖属性。

创建只读依赖属性的大多数过程与[自定义依赖属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/custom-dependency-properties)和[实现依赖属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-implement-a-dependency-property)主题中介绍的过程相同。 但有三个重要的差异：

- 当注册属性，调用[RegisterReadOnly](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.registerreadonly)方法而非普通[Register](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.register)属性注册的方法。
- 实现 CLR“包装器”属性时，请确保该包装器也没有设置的实现，以便在公开的公共包装器的只读状态中不存在不一致现象。
- 由只读注册返回的对象是[DependencyPropertyKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencypropertykey)而非[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)。 仍应将该字段存储为成员，但通常不将其设置为类型的公共成员。

无论你具有什么专用字段或值，可使用你确定的任何逻辑来完全编写对只读依赖属性的支持。 但是，在最初或运行时逻辑过程中设置属性的最简单方法是使用属性系统的 API，而不是避开属性系统并直接设置专有支持字段。具体而言，没有的签名[SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue)接受类型参数的[DependencyPropertyKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencypropertykey)。 如何以及在何处设置此值以编程方式在应用程序逻辑中你如何可能想要设置的访问将影响[DependencyPropertyKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencypropertykey)首次注册依赖属性时创建。 如果完全在专有类中处理此逻辑，或者如果要求从程序集的其他部分对其进行设置，可以在内部进行设置。 一种方法是调用[SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue)通知存储的属性值需要为其更改的类实例的相关事件的类事件处理程序中。 另一种方法是将绑定依赖关系属性在一起使用配对[PropertyChangedCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertychangedcallback)和[CoerceValueCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.coercevaluecallback)回调在注册过程中的这些属性的元数据的一部分。

因为[DependencyPropertyKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencypropertykey)是专用容器，并不会传播由属性系统在代码之外，更好的安全设置比读写依赖属性具有只读依赖属性。 对于读写依赖属性，标识字段是显式或隐式公用的，因此该属性可广泛设置。 有关更多详细信息，请参阅[依赖属性的安全性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-security)。

## [Property Value Inheritance](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/property-value-inheritance)

属性值继承是 Windows Presentation Foundation (WPF) 属性系统的一项功能。 属性值继承使元素树中的子元素可以从父元素获取特定属性的值，并继承该值，就如同它是在最近的父元素中任意位置设置的一样。 父元素可能也已通过属性值继承获得了其值，因此系统有可能一直递归到页面根。 属性值继承不是默认属性系统行为；属性必须用特定的元数据设置来建立，以便使该属性对子元素启动属性值继承。

### 属性值继承是内含继承

此处作为术语的“继承”与类型和常规的面向对象的编程中提到的继承并非完全相同的概念，后者指派生类从其基类继承成员定义。 继承的这一含义在 WPF 中也适用：当在代码中用作元素且公开为成员时，各基类中定义的属性将公开为 XAML 派生类的特性。 属性值继承则是关于属性值如何基于元素树中的父子关系从一个元素继承到另一个元素。 如果在 XAML 标记中定义应用程序时将元素嵌套在其他元素中，则该元素树在此种情况下最直接可见。 还可以通过向其他对象的指定集合中添加对象来以编程方式创建对象树，在运行时，属性值继承在完成树中以相同方式工作。

### 属性值继承的实际应用

WPF API 包括几个启用属性继承的属性。 通常，使用这些属性的情况是当涉及到一个属性，每页可以仅对该属性设置一次，但是该属性还是某个基元素类的成员，因此还存在于大多数子元素中。 例如，[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)属性控制哪个方向流动内容应提供程序并在页面上的排列。 通常做法是在所有子元素中以一致的方式处理文本流概念。 如果用户或环境操作因某种原因在元素树的某一层重置了流方向，则流方向通常会在整个树中重置。 当[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)属性进行继承，值仅需要设置或重置的每个页面在应用程序中需要演示的元素树中级别的一次。 即使是最初的默认值也将按照这种方式继承。 在需有意混用流方向的极罕见情况下，属性值继承模型也仍允许个别元素重置该值。

### 使自定义属性可继承

通过更改自定义属性的元数据，还可以使自己的自定义属性可继承。 但是，请注意，将属性指定为可继承需要考虑到性能问题。 如果该属性没有已建立的本地值或通过样式、模板或数据绑定获取的值，则可继承的属性会将赋予它的属性值提供给逻辑树中的所有子元素。

为了让属性参与值继承，请按照[注册附加属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-register-an-attached-property)中所述创建自定义附加属性。 注册元数据属性 ([FrameworkPropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata)) 并在该元数据内的选项设置中指定"Inherits"选项。 同时确保该属性已建立了默认值，因为该值现将继承。 尽管已将该属性注册为附加属性，可能还需像对“非附加”依赖项属性一样，为所有者类型上的 get/set 访问创建属性“包装”。 这样做之后，可继承的属性可以设置所有者类型或派生的类型上使用直接属性包装或它可以在任何使用附加的属性语法设置[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)。

附加的属性是从概念上讲类似于全局属性;您可以检查任何值[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)并获取有效结果。 附加属性的典型方案是在子元素上设置属性值和该方案会更为有效，如果有问题的属性是将始终作为附加属性的每个元素隐式存在一个附加的属性 ([DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)) 在树中。

> 尽管属性值继承看起来对非附加依赖项属性有效，但通过运行时树中特定元素边界的非附加属性的继承行为并未定义。 始终使用[RegisterAttached](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.registerattached)来注册您在其中指定的属性[Inherits](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata.inherits)元数据中。

### 跨树边界继承属性值

属性继承通过遍历元素树来工作。 此树通常与逻辑树并行。 但是，每当您包括 WPF 核心级别对象中的标记，用于定义元素树，如[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)，已创建一个不连续的逻辑树。 真正的逻辑树不会从概念上讲扩展通过[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)，因为逻辑树是 WPF 框架级别概念。 您可以看到这反映在结果中使用的方法时[LogicalTreeHelper](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.logicaltreehelper)。 但是，属性值继承可填补此间隙逻辑树中的，并且只要可继承的属性注册为附加的属性，而且没有有意的继承阻止边界可以仍可通过继承的值，(例如[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)) 遇到。

## [Dependency Property Security](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/dependency-property-security)

依赖属性通常应当被视为公共属性。 Windows Presentation Foundation (WPF) 属性系统在本质上无法对依赖属性值提供安全保证。

### 包装器和依赖属性的访问和安全性

通常，依赖属性是随“包装器”公共语言运行时 (CLR) 属性一起实现的，这些包装器属性可以简化从实例获取或设置属性的过程。 但是，包装器实际上只是方便的方法，实现基础[GetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.getvalue)和[SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue)与依赖属性交互时使用的静态调用。 从另外一个角度考虑，这些属性作为恰好由依赖属性（而非私有字段）支持的公共语言运行时 (CLR) 属性公开。 应用于包装器的安全机制与属性系统行为以及基础依赖属性的访问并不可比。 包装器设置安全要求将只是防止使用便捷方法，但不是会阻止调用[GetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.getvalue)或[SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue)。 同样，为包装器设置受保护或私有访问级别也不会提供任何有效的安全性。

如果你正在编写您自己的依赖项属性，应声明包装器和[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)标识符字段为公共成员，以便调用方执行未得到令人误解的该属性的实际访问级别有关的信息 （由于其存储在实现为依赖属性）。

对于自定义依赖项属性，可以将属性注册为只读依赖属性，并且这确实提供了一种有效方法阻止任何人都不包含对引用设置的属性的[DependencyPropertyKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencypropertykey)该属性。 有关详细信息，请参阅[只读依赖属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/read-only-dependency-properties)。

> 声明[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)不禁止标识符字段专用，并想象可用于帮助减少直接公开命名空间的自定义类，但这样的属性不应被视为"私有"作为相同意义上公共语言运行时 (CLR)语言定义所定义的访问级别下, 一节中描述的原因。

### 依赖属性的属性系统公开

它不是通常很有用，并且可能具有误导性，以声明[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)任何访问级别以外的公钥。 该访问级别设置只是防止某人从声明类获得对实例的引用。 但有几个方面的属性系统将返回[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)作为一种标识特定属性，因为它存在于上一个类的实例或派生的类实例，而且该标识符中仍然可以使用[SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue)甚至调用如果最初的静态标识符声明为非公共。 此外，[OnPropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.onpropertychanged)虚方法接收的任何现有的依赖属性的值进行了更改的信息。 此外，[GetLocalValueEnumerator](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.getlocalvalueenumerator)方法返回具有在本地设置的实例上的任何属性的标识符值。

#### 验证和安全

应用到一个要求[ValidateValueCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.validatevaluecallback)并且需要验证失败以防止设置属性上不具有足够的安全性机制。 通过强制执行的 set-value 失效[ValidateValueCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.validatevaluecallback)还可能会禁止恶意调用方，如果应用程序域中运行这些调用方。

## [Safe Constructor Patterns for DependencyObjects](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/safe-constructor-patterns-for-dependencyobjects)

通常，类构造函数不应调用诸如虚拟方法或委托等回叫，其原因是构造函数可作为派生类的构造函数的基本初始化进行调用。 输入该虚拟的操作可能会在任何给定对象的不完全初始化状态下进行。 但是，属性系统本身在内部调用并公开回叫，作为依赖属性系统的一部分。 与设置具有依赖项属性值一样简单操作[SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue)调用可能包括回叫某个位置在决定中。 因此，在构造函数体内设置依赖属性值时应保持谨慎（将类型用作基类可能会导致问题）。没有特定的模式，用于实现[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)构造函数可避免对依赖属性状态和内在回叫的特定问题此处进行了说明。

### 属性系统虚拟方法

在的计算结果的过程可能会调用以下虚拟方法或回叫[SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue)调用，用于设置依赖项属性值： [ValidateValueCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.validatevaluecallback)， [PropertyChangedCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertychangedcallback)， [CoerceValueCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.coercevaluecallback)， [OnPropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.onpropertychanged)。 这些虚拟方法或回叫中的每一个在扩展 Windows Presentation Foundation (WPF) 属性系统和依赖属性的多样性方面都具有特定的用途。 有关如何使用这些虚拟方法对属性值确定进行自定义的详细信息，请参阅[依赖属性回调和验证](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-callbacks-and-validation)。

#### FXCop 规则强制与属性系统虚拟方法

如果将 Microsoft 工具 FXCop 用作生成过程的一部分，并从某些调用基构造函数的 WPF 框架类派生，或在派生的类上实现自己的依赖属性，则可能会违反某个 FXCop 规则。 此违反事件的名称字符串为：

```
DoNotCallOverridableMethodsInConstructors
```

此规则是为 FXCop 设置的默认公共规则的一部分。 此规则所报告的内容可能为通过依赖属性系统实现的跟踪情况，该系统会最终调用依赖属性系统虚拟方法。 即使遵循本主题中介绍并建议使用的构造函数模式，仍可能存在此规则冲突，因此可能需要在 FXCop 规则设置配置中禁用或取消该规则。

#### 大多数问题是因派生类导致的，而不是因为使用现有类所致

当按构造顺序使用虚拟方法实现一个类后从该类进行派生时，便会发生此规则所报告的问题。 如果密封了类，或者确信不会派生自此类或强制不得派生自此类，则此处介绍的注意事项和触发 FXCop 规则的问题将不适用。 但是，如果出于将类用作基类的目的来创作类，例如，如果正创建模板或可扩展的控件库集，则应遵循此处建议的用于构造函数的模式。

#### 默认构造函数必须初始化由回叫请求的所有值

由类重写或回叫（来自“属性系统虚拟方法”部分列表中的回叫）使用的任何实例成员必须在类的默认构造函数中进行初始化，即使其中的某些值通过非默认构造函数的参数填充为“真实”值时也是如此。

以下代码示例（和后面的示例）是一个与此规则冲突的伪 C# 示例，其中对问题进行了说明：

```
public class MyClass : DependencyObject  
{  
    public MyClass() {}  
    public MyClass(object toSetWobble)  
        : this()  
    {  
        Wobble = toSetWobble; //this is backed by a DependencyProperty  
        _myList = new ArrayList();    // this line should be in the default ctor  
    }  
    public static readonly DependencyProperty WobbleProperty =   
        DependencyProperty.Register("Wobble", typeof(object), typeof(MyClass));  
    public object Wobble  
    {  
        get { return GetValue(WobbleProperty); }  
        set { SetValue(WobbleProperty, value); }  
    }  
    protected override void OnPropertyChanged(DependencyPropertyChangedEventArgs e)  
    {  
        int count = _myList.Count;    // null-reference exception  
    }  
    private ArrayList _myList;  
}  
```

当应用程序代码调用 `new MyClass(objectvalue)` 时，这会调用默认构造函数和基类构造函数。 然后它会设置`Property1 = object1`，它调用虚拟方法`OnPropertyChanged`上的拥有`MyClass` [DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)。 重写引用尚未初始化的 `_myList`。

避免这些问题的一个方法是：确保回叫仅使用其他依赖属性，并且每个这样的依赖属性都有一个确立的默认值作为其注册元数据的一部分。

### 安全构造函数模式

若要在将类用作基类的情况下规避未完全实现初始化的风险，请遵循以下模式：

#### 用于调用基本初始化的默认构造函数

实现以下用于调用基本默认值的构造函数：

```
public MyClass : SomeBaseClass {  
    public MyClass() : base() {  
        // ALL class initialization, including initial defaults for   
        // possible values that other ctors specify or that callbacks need.  
    }  
}  
```

#### 非默认（方便）构造函数，不与任何基本签名匹配

如果这些构造函数使用参数来设置初始化中的依赖属性，首先应调用自己的类默认构造函数进行初始化，然后使用参数来设置依赖属性。 这些可能是类所定义的依赖属性，也可能是从基类继承的依赖属性，但在这两种情况下都使用以下模式：

```
public MyClass : SomeBaseClass {  
    public MyClass(object toSetProperty1) : this() {  
        // Class initialization NOT done by default.  
        // Then, set properties to values as passed in ctor parameters.  
        Property1 = toSetProperty1;  
    }  
}  
```

#### 非默认（方便）构造函数，确实与基本签名匹配

不调用具有相同参数设置的基构造函数，而是再次调用自己的类的默认构造函数。 请勿调用基本初始值设定项，而应调用 `this()`。 然后使用传递的参数作为用于设置相关属性的值来重现原始构造函数行为。 将原始基本构造函数文档用作指导依据，确定要对特定参数设置的属性：

```
public MyClass : SomeBaseClass {  
    public MyClass(object toSetProperty1) : this() {  
        // Class initialization NOT done by default.  
        // Then, set properties to values as passed in ctor parameters.  
        Property1 = toSetProperty1;  
    }  
}  
```

#### 必须匹配所有签名

对于基类型具有多个签名的情况，必须在设置更多属性之前特意将所有可能的签名与自己的构造函数的实现相匹配，该实现使用建议的类默认构造函数调用模式。

#### 使用 SetValue 设置依赖属性

如果您在设置一个属性，没有为属性设置方便起见，包装，并且设置的值，这些模式同样适用[SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue)。 对调用[SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue)通过构造函数参数阶段还应调用类的默认构造函数进行初始化。

## [Collection-Type Dependency Properties](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/collection-type-dependency-properties)

本主题就如何实现属性类型为集合类型的依赖属性提供相应指导和建议模式。



### 实现集合类型依赖属性

依赖属性的一般情况下，遵循的实现模式是您定义CLR属性的包装器，该属性由[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)标识符而不是字段或其他构造。 实现集合类型属性时也应按照此相同模式。 但是，集合类型属性带来了一些复杂性的模式时该集合内包含的类型本身[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)或[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)派生的类。

### 不使用默认值初始化集合

创建依赖属性时，不要将属性默认值指定为初始字段值。 相反，应通过依赖属性元数据指定默认值。 如果属性为引用类型，则依赖属性元数据中指定的默认值不是每个实例分别的默认值，而是应用到类型的所有实例的默认值。因此，对于类型的新创建实例，必须小心，不要将集合属性元数据定义的单个静态集合用作工作默认值。 相反，必须确保有意将集合值设置为唯一（实例）集合，作为类构造函数逻辑的一部分。 否则，你会创建一个不需要的单例类。

请看下面的示例。 示例的以下部分显示类 `Aquarium` 的定义。 类定义集合类型依赖属性`AquariumObjects`，它使用泛型[List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1)类型具有[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)类型约束。 在中[Register(String, Type, Type, PropertyMetadata)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.register#System_Windows_DependencyProperty_Register_System_String_System_Type_System_Type_System_Windows_PropertyMetadata_)依赖属性元数据的调用会建立此默认值为一个新的泛型[List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1)。

```csharp
public class Fish : FrameworkElement { }
public class Aquarium : DependencyObject {
    private static readonly DependencyPropertyKey AquariumContentsPropertyKey =
        DependencyProperty.RegisterReadOnly(
          "AquariumContents",
          typeof(List<FrameworkElement>),
          typeof(Aquarium),
          new FrameworkPropertyMetadata(new List<FrameworkElement>())
        );
    public static readonly DependencyProperty AquariumContentsProperty =
        AquariumContentsPropertyKey.DependencyProperty;

    public List<FrameworkElement> AquariumContents
    {
        get { return (List<FrameworkElement>)GetValue(AquariumContentsProperty); }
    }

    // ...

}
```

但是，如果仅如上所示保留代码，该单一列表默认值会对 `Aquarium` 的所有实例共享。 如果运行以下测试代码（用于演示如何实例化两个单独的 `Aquarium` 实例并向二者皆添加一个不同的 `Fish`），则其结果可能出乎意料：

```csharp
Aquarium myAq1 = new Aquarium();
Aquarium myAq2 = new Aquarium();
Fish f1 = new Fish();
Fish f2 = new Fish();
myAq1.AquariumContents.Add(f1);
myAq2.AquariumContents.Add(f2);
MessageBox.Show("aq1 contains " + myAq1.AquariumContents.Count.ToString() + " things");
MessageBox.Show("aq2 contains " + myAq2.AquariumContents.Count.ToString() + " things");
```

每个集合具有两个计数，而不是一个！ 这是因为，每个 `Aquarium` 将其 `Fish` 添加到默认值集合，此默认值集合因元数据中单个构造函数调用而产生，因此会在所有实例之间共享。 而你全然不希望出现这种情况。

为纠正此问题，必须将集合依赖属性值重置为唯一实例，作为类构造函数调用的一部分。 由于属性是只读的依赖项属性，因此使用[SetValue(DependencyPropertyKey, Object)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue#System_Windows_DependencyObject_SetValue_System_Windows_DependencyPropertyKey_System_Object_)方法以设置它，使用[DependencyPropertyKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencypropertykey)，才可访问的类中。

```csharp
public Aquarium() : base()
{
    SetValue(AquariumContentsPropertyKey, new List<FrameworkElement>()); 
}
```

现在，如果再次运行此相同测试代码，则每个 `Aquarium` 会仅支持自己的唯一集合，这样的结果更符合预期。

如果选择集合属性为读写，则此模式会稍有变化。 在这种情况下，您可以从构造函数来执行初始化，仍会调用的非键签名调用公共集访问器[SetValue(DependencyProperty, Object)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue#System_Windows_DependencyObject_SetValue_System_Windows_DependencyProperty_System_Object_)内集包装器，使用的是公共[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)标识符。

### 报告集合属性中的绑定值更改

本身为依赖属性的集合属性不会自动将更改报告给其子属性。 如果将绑定创建到集合，这可阻止绑定报告更改，从而使某些数据绑定方案无效。 但是，如果使用的集合类型[FreezableCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezablecollection-1)作为集合类型，然后在集合中包含的元素的子属性更改会正常报告，并按预期方式工作的绑定。

若要启用依赖项对象集合中的子属性绑定，将集合属性创建为类型[FreezableCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezablecollection-1)，任何对该集合的类型约束[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)派生的类。

## [XAML Loading and Dependency Properties](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/xaml-loading-and-dependency-properties)

XAML 处理器的当前 WPF 实现固有地知道依赖属性。 WPF XAML 处理器在加载二进制 XAML 和处理作为依赖属性的特性时对依赖属性使用属性系统方法。 这会有效地跳过属性包装器。 实现自定义依赖属性时，必须考虑到这种行为，应避免在之外的其他属性系统在属性包装器中放置的任何其他代码[GetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.getvalue)和[SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue)。

### 系统必备

本主题假定你已从使用者和创作者角度了解依赖属性，并已阅读[依赖属性概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-properties-overview)和[自定义依赖属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/custom-dependency-properties)。 你应也已阅读 [XAML 概述 (WPF)](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-overview-wpf) 和 [XAML 语法详述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-syntax-in-detail)。

### WPF XAML 加载程序实现和性能

出于实现原因，它是计算属性标识为依赖项属性和访问属性系统更便宜[SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue)方法设置它，而不是使用属性包装器和 setter。 这是因为 XAML 处理器必须仅通过了解由标记结构和多种字符串所指示的类型和成员关系来推断支持代码的整个对象模型。

通过结合 xmlns 和程序集特性，但标识成员、 确定支持设置为属性，查找类型和解决哪些类型的属性值支持原本需要的扩展反射使用[PropertyInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.propertyinfo)。 由于给定类型的依赖项属性是通过属性系统的存储表的可访问性WPF的实现及其XAML处理器使用此表，并推断的任何属性的指定属性*ABC*可以通过调用更有效地设置[SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue)上包含[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)派生类型，使用依赖项属性标识符*ABCProperty*。

### 自定义依赖属性的影响

由于进行属性设置的 XAML 处理器行为的当前 WPF 实现会完全跳过包装器，因此对于自定义依赖属性不应将任何其他逻辑放入包装器的设置定义中。 如果将此类逻辑放入设置定义，则在 XAML 而不是代码中设置属性时不会执行逻辑。

同样，其他方面XAML获取的属性值的处理器XAML还处理使用[GetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.getvalue)而不是使用包装器。 因此，还应避免在任何其他实现`get`超出定义[GetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.getvalue)调用。

如下示例是包装器的推荐依赖属性定义，其中属性标识符存储为 `public` `static` `readonly` 字段，`get` 和 `set` 定义不包含除定义依赖属性支持所需属性系统方法外的任何代码。

```csharp
public static readonly DependencyProperty AquariumGraphicProperty = DependencyProperty.Register(
  "AquariumGraphic",
  typeof(Uri),
  typeof(AquariumObject),
  new FrameworkPropertyMetadata(null,
      FrameworkPropertyMetadataOptions.AffectsRender, 
      new PropertyChangedCallback(OnUriChanged)
  )
);
public Uri AquariumGraphic
{
  get { return (Uri)GetValue(AquariumGraphicProperty); }
  set { SetValue(AquariumGraphicProperty, value); }
}
```

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/properties-how-to-topics)

### 本节内容

[实现依赖属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-implement-a-dependency-property)
[添加依赖属性的所有者类型](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-add-an-owner-type-for-a-dependency-property)
[注册附加属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-register-an-attached-property)
[重写依赖属性的元数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-override-metadata-for-a-dependency-property)

### [Implement a Dependency Property](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-implement-a-dependency-property)

此示例演示如何重新公共语言运行时 (CLR)具有属性[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)字段，从而定义依赖项属性。 定义自己的属性并需要其支持 Windows Presentation Foundation (WPF) 功能的诸多方面（包括样式、数据绑定、继承、动画和默认值）时，应将其作为依赖属性实现。

#### 示例

下面的示例第一次注册依赖属性通过调用[Register](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.register)方法。 用于存储名称，并且必须依赖项属性的特征的标识符字段的名称[Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.name)作为的一部分为依赖属性选择了[Register](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.register)调用中，文字字符串由追加`Property`。 例如，如果你注册具有的依赖关系属性[Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.name)的`Location`，则定义的依赖项属性标识符字段必须命名为`LocationProperty`。

在此示例中，依赖项属性的名称并将其CLR访问器已`State`; 标识符字段`StateProperty`; 属性的类型是[Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean); 注册依赖属性的类型是`MyStateControl`。

如果不遵循此命名模式，则设计器可能无法正确地报告属性，而且属性系统样式应用程序的某些方面可能不会以预期的方式工作。

还可为依赖属性指定默认元数据。 此示例将 `State` 依赖属性的默认值注册为 `false`。

```csharp
public class MyStateControl : ButtonBase
{
  public MyStateControl() : base() { }
  public Boolean State
  {
    get { return (Boolean)this.GetValue(StateProperty); }
    set { this.SetValue(StateProperty, value); } 
  }
  public static readonly DependencyProperty StateProperty = DependencyProperty.Register(
    "State", typeof(Boolean), typeof(MyStateControl),new PropertyMetadata(false));
}
```

若要深入了解实现依赖属性而非仅使用私有字段支持 CLR 属性的原因及其实现方式，请参阅[依赖属性概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-properties-overview)。

### [Add an Owner Type for a Dependency Property](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-add-an-owner-type-for-a-dependency-property)

此示例演示如何将类添加为所有者为不同类型注册依赖属性。 通过执行此操作，请WPFXAML读取器和属性系统都能够识别此类为附加属性的所有者。 （可选） 将添加为所有者可以选择添加类以提供特定于类型的元数据。

在以下示例中，`StateProperty`通过注册一个属性`MyStateControl`类。 该类`UnrelatedStateControl`将自身添加为所有者`StateProperty`使用[AddOwner](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.addowner)方法，特别使用它位于添加类型上允许进行新的依赖项属性的元数据的签名。 请注意，应提供公共语言运行时 (CLR)中所示的示例类似的属性的访问器[实现依赖属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-implement-a-dependency-property)示例中，以及重新公开要添加的类上的依赖项属性标识符作为所有者。

未使用包装，依赖项属性仍将从以编程方式访问使用的角度来看有效[GetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.getvalue)或[SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue)。 但你通常想要使用此属性系统行为的并行CLR属性包装器。 这些包装更加轻松地以编程方式设置依赖项属性，使其可以将设置为属性XAML属性。

若要了解如何重写默认元数据，请参阅[重写依赖属性的元数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-override-metadata-for-a-dependency-property)。

#### 示例

```csharp
public class MyStateControl : ButtonBase
{
  public MyStateControl() : base() { }
  public Boolean State
  {
    get { return (Boolean)this.GetValue(StateProperty); }
    set { this.SetValue(StateProperty, value); } 
  }
  public static readonly DependencyProperty StateProperty = DependencyProperty.Register(
    "State", typeof(Boolean), typeof(MyStateControl),new PropertyMetadata(false));
}
```

```csharp
public class UnrelatedStateControl : Control
{
  public UnrelatedStateControl() { }
  public static readonly DependencyProperty StateProperty = MyStateControl.StateProperty.AddOwner(typeof(UnrelatedStateControl), new PropertyMetadata(true));
  public Boolean State
  {
    get { return (Boolean)this.GetValue(StateProperty); }
    set { this.SetValue(StateProperty, value); }
  }
}
```

### [Register an Attached Property](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-register-an-attached-property)

此示例演示如何注册附加属性和提供公共访问器，以便可以在 可扩展应用程序标记语言 (XAML) 和代码中使用该属性。 附加属性是由 可扩展应用程序标记语言 (XAML) 定义的语法概念。 WPF 类型的大多数附加属性还作为依赖属性实现。 可以对任何使用依赖项属性[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)类型。

#### 示例

下面的示例演示如何注册附加的属性为依赖属性，通过使用[RegisterAttached](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.registerattached)方法。 在其他类上使用属性时，提供程序类可以选择为适用的属性提供默认元数据，除非该类会重写元数据。 在此示例中，`IsBubbleSource` 属性的默认值设置为 `false`。

附加属性（即使未注册为依赖属性）的提供程序类必须提供遵循 `Set`*[附加属性名称]* 和 `Get`*[附加属性名称]* 命名约定的静态 get 和 set 访问器。 需要这些访问器目的是生效的 XAML 读取器可以在 XAML 中将属性识别为特性，并解析相应的类型。

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

### [Override Metadata for a Dependency Property](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-override-metadata-for-a-dependency-property)

此示例演示如何重写默认依赖关系属性的元数据来自于继承的类，通过调用[OverrideMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.overridemetadata)方法并提供特定于类型的元数据。

#### 示例

通过定义其[PropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata)，类可以定义依赖项属性的行为，例如其默认值和属性系统回叫。 很多依赖属性类都已经将默认元数据创建为其注册过程的一部分。 这包含作为 WPF API 一部分的依赖属性。 通过其类继承继承依赖属性的类可重写原始的元数据，以便可通过元数据更改的属性的特征与任何特定于子类的要求相匹配。

在依赖属性上重写元数据的操作必须在属性系统使用该属性之前进行，也就是说，在对注册属性的对象的特定实例进行实例化之前进行。 调用[OverrideMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.overridemetadata)必须为自己提供的类型的静态构造函数中执行`forType`参数的[OverrideMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.overridemetadata)。 所有者类型的实例存在之后尝试更改元数据不会引发异常，但会在属性系统中导致不一致的行为。 此外，每种类型只可以重写一次元数据。 以后在同一类型上重写元数据的尝试会引发异常。

在下面示例中，自定义类 `MyAdvancedStateControl` 重写了由带有新属性元数据的 `MyAdvancedStateControl` 为 `StateProperty` 提供的元数据。 例如，在新构造的 `MyAdvancedStateControl` 实例上查询 `StateProperty` 时，其默认值现在是 `true`。

```csharp
public class MyStateControl : ButtonBase
{
  public MyStateControl() : base() { }
  public Boolean State
  {
    get { return (Boolean)this.GetValue(StateProperty); }
    set { this.SetValue(StateProperty, value); } 
  }
  public static readonly DependencyProperty StateProperty = DependencyProperty.Register(
    "State", typeof(Boolean), typeof(MyStateControl),new PropertyMetadata(false));
}
```

```csharp
public class MyAdvancedStateControl : MyStateControl
{
  public MyAdvancedStateControl() : base() { }
  static MyAdvancedStateControl()
  {
    MyStateControl.StateProperty.OverrideMetadata(typeof(MyAdvancedStateControl), new PropertyMetadata(true));
  }
}
```