# [Base Elements](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/base-elements)

四个关键类-[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)， [ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement)， [FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)，和[FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement)-实现可用于 WPF 编程的常见元素功能的大部分。 这四个类在此 SDK 中称为基元素类。

## 本节内容

[基元素概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/base-elements-overview)
[Freezable 对象概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/freezable-objects-overview)
[对齐、边距和填充概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/alignment-margins-and-padding-overview)
[帮助主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/base-elements-how-to-topics)

## [Base Elements Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/base-elements-overview)

Windows Presentation Foundation (WPF) 中较高比重的类都派生自四类，它们通常在 SDK 文档中称为基元素。 这些类是[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)， [FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)， [ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement)，和[FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement)。 [DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)类也相关，因为它是这两者的一个公共基类[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)和 [ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement)

### WPF 类中的基元素 API

这两[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)并[ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement)派生自[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)，通过某种程度上不同的途径。 如何处理此级别拆分[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)或[ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement)中的用户界面和什么作用其处理的应用程序中使用。 [UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement) 还有[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)在其类层次结构，它是一个类公开低级别图形支持基础Windows Presentation Foundation (WPF)。 [Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual) 通过定义独立矩形屏幕区域提供呈现框架。 在实践中，[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)是将支持较大的对象模型的元素为目标来呈现和分成若干个区域，可以描述为矩形屏幕区域和内容模型是有意更加开放，以允许不同的布局元素的组合。 [ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement) 不是派生自[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual); 其模型是[ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement)将由其他用途，如读取器或查看器，然后解释元素，并生成完整[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)为Windows Presentation Foundation (WPF)来使用。 某些[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)类旨在成为内容宿主： 它们提供了一个或多个承载和呈现[ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement)类 ([DocumentViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.documentviewer)举例说明这样的类)。 [ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement) 用于内承载带有某种程度上较小的对象模型的元素的基类和文档内容的或更多地址的文本的信息，如[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)。

#### 框架级别和核心级别

[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement) 用作类的基类[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)，并[ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement)用作类的基类[FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement)。 此下一级别类的目的是支持独立于 WPF 框架级别的 WPF 核心级别，同时这种划分也存在于 PresentationCore 和 PresentationFramework 程序集间如何划分 API。 WPF 框架级别表示一种更完整的解决方案，以满足基本应用程序需求，其中包括实现演示文稿的布局管理器。 WPF 核心级别可提供一种方法，使你能够充分利用 WPF，而无需使用其他程序集的开销。 这些级别间的区别对大多数典型的应用程序开发方案几乎没影响，但一般情况下，你应整体考虑 WPF API，而不是关注 WPF 框架级别和 WPF 核心级别间的差异。 如果应用程序设计选择替换大量 WPF 框架级别功能，建议了解级别差异，例如，整体解决方案是否已有其自己的 用户界面 (UI) 组合和布局的实现。

### 选择要从其中派生的元素

若要创建扩展 WPF 的自定义类，最实用的方法是派生自 WPF 类之一，你可在其中通过现有类层次结构获得尽可能多的所需功能。 本节列出了以下三个最重要的元素类附带的功能，以帮助决定要从其中继承的类。

如果要实现一个控件，这的确是从派生更常见的原因之一WPF类中，你可能想要派生自的类的实际控件、 控件系列基类，也在至少从[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)基类。 有关指导和实际示例，请参阅[控件创作概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/control-authoring-overview)。

如果没有创建控件且需要派生自位于层次结构中较高层次的类，以下各节可用于指导在每个基元素类中定义哪些特征。

如果创建派生的类[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)，还将继承以下功能：

- [GetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.getvalue) 和[SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue)支持以及常规属性系统支持。
- 能够使用依赖属性和实现为依赖属性的附加属性。

如果创建派生自类[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)，还将继承以下功能之外，提供的[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject):

- 对已动画处理的属性值的基本支持。 有关详细信息，请参阅 [动画概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/animation-overview)。
- 基本输入事件支持以及命令支持。 有关详细信息，请参阅[输入概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/input-overview)和[命令概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/commanding-overview)。
- 可进行替代以便介绍布局系统的虚拟方法。

如果创建派生自类[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)，还将继承以下功能之外，提供的[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement):

- 样式和情节提要支持。 有关详细信息，请参阅[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)并[演示图板概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/storyboards-overview)。
- 数据绑定支持。 有关详细信息，请参阅 [数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview)。
- 动态资源引用支持。 有关详细信息，请参阅 [XAML 资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-resources)。
- 属性值继承支持，以及元数据中的其他标记，这些标记有助于报告关于框架服务属性的情况，例如数据绑定、样式或布局的框架实现。 有关详细信息，请参阅[框架属性元数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/framework-property-metadata)。
- 逻辑树概念。 有关详细信息，请参见 [WPF 中的树](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/trees-in-wpf)。
- 布局系统的实用 WPF 框架级别实现的支持包括[OnPropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.onpropertychanged)可以检测到的重写更改为属性影响布局。

如果创建派生自类[ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement)，还将继承以下功能之外，提供的[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject):

- 支持动画。 有关详细信息，请参阅 [动画概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/animation-overview)。
- 基本输入事件支持以及命令支持。 有关详细信息，请参阅[输入概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/input-overview)和[命令概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/commanding-overview)。

如果创建派生自类[FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement)，你将获得以下功能之外，提供的[ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement):

- 样式和情节提要支持。 有关详细信息，请参阅[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)并[动画概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/animation-overview)。
- 数据绑定支持。 有关详细信息，请参阅 [数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview)。
- 动态资源引用支持。 有关详细信息，请参阅 [XAML 资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-resources)。
- 属性值继承支持，以及元数据中的其他标记，这些标记有助于报告关于框架服务属性的情况，例如数据绑定、样式或布局的框架实现。 有关详细信息，请参阅[框架属性元数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/framework-property-metadata)。
- 你不会继承布局系统修改访问 (如[ArrangeOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.arrangeoverride))。 布局系统实现才可在上找到[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)。 但是，继承[OnPropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.onpropertychanged)可以检测对影响布局，并报告给任何内容宿主的属性的更改的替代。

针对各种类记录内容模型。 如果想要查找相应的类进行派生，类的内容模型是应该考虑的一个可能因素。 有关详细信息，请参阅 [WPF 内容模型](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/wpf-content-model)。

### 其他基类

#### DispatcherObject

[DispatcherObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcherobject) 提供对支持WPF线程处理模型还可为创建的所有对象WPF与关联的应用程序[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)。 即使您并非派生[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)， [DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)，或[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)，则应考虑派生自[DispatcherObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcherobject)以便获得此线程模型支持。 有关详细信息，请参阅[线程模型](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/threading-model)。

#### 视觉对象

[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual) 实现通常要求在大致矩形的区域中的可视化展示了 2D 对象的概念。 实际呈现[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)发生在其他类 （它不是自包含），但[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)类提供了呈现进程在不同级别使用的已知的类型。 [Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual) 实现命中测试，但它不公开报告点击测试阳性的事件 (这些对象位于[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement))。 有关详细信息，请参阅[可视化层编程](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/visual-layer-programming)。

#### Freezable

[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable) 通过提供所需或出于性能原因不可变对象时生成的对象的副本的方法来模拟可变对象的不可变性。[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)类型提供了公共基础对于某些图形元素，如几何和画笔以及动画。 值得注意的是，[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)不是[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual); 它可保留成为子属性的属性时[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)应用以填充属性值的另一个对象，并且这些子属性可能会影响呈现。 有关详细信息，请参阅 [Freezable 对象概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/freezable-objects-overview)。

[Animatable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animatable)

[Animatable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animatable) 是[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)派生的类，它特别添加了动画控件层和一些实用程序成员，以便可以区分当前动画的属性的属性区分开。

#### 控件

[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control) 是所需的基类的类型的对象，该控件或组件，具体取决于该技术称为对象。 一般情况下，WPF 控件类可直接表示 UI 控件或积极参与控件组合。 主要功能的[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)启用是控制模板化。

## [Freezable Objects Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/freezable-objects-overview)

本主题介绍如何有效地使用和创建[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)对象，它们提供特殊功能，可帮助提高应用程序性能。 Freezable 对象的示例包括画笔、 笔、 转换、 几何和动画。



### 什么是 Freezable？

一个[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)是一种特殊的对象，它有两种状态： 解冻和冻结。 当未冻结，[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)看起来就像任何其他对象的行为。 当冻结，[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)无法再进行修改。

一个[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)提供了[Changed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.changed)事件，以通知观察者的对对象进行任何修改。 冻结[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)可以提高其性能，因为它不再需要更改通知而消耗资源。 冻结[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)还可以在时未冻结的线程之间共享[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)不能。

尽管[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)类具有许多应用程序，最[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)中的对象Windows Presentation Foundation (WPF)与图形子系统相关。

[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)类可以容易地使用某些图形系统对象，并有助于提高应用程序性能。 继承的类型的示例[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)包括[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)， [Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transform)，和[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)类。 因为它们包含非托管的资源，系统必须监视这些对象的修改，并对原始对象的更改时，然后更新其相应的非托管的资源。 即使你实际上无需修改图形系统对象，系统必须仍需花一些资源来监视对象，以防对其进行更改。

例如，假设您创建[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)画笔，并使用它来绘制按钮的背景。

```csharp
Button myButton = new Button();
SolidColorBrush myBrush = new SolidColorBrush(Colors.Yellow);
myButton.Background = myBrush;  
```

当呈现该按钮时，WPF图形子系统使用您提供要绘制的一组像素，若要创建一个按钮的外观的信息。 尽管使用纯色画笔来描述应如何绘制按钮，但纯色画笔实际上不会进行绘制。 图形系统将生成用于按钮和画笔，快速、 低级别对象并且在屏幕实际显示这些对象。

如果您打算修改画笔，这些低级别对象需要重新生成。 Freezable 类是什么使画笔能够以查找其相应的生成的低级别对象，并且它发生更改时更新它们。 画笔时启用此功能，则称其"未冻结。"

Freezable 的[Freeze](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.freeze)方法使您能够禁用此自我更新功能。 此方法可用于使画笔变为"冻结"或变为不可修改。

> 不是每个 Freezable 对象可以被冻结。 若要避免引发[InvalidOperationException](https://docs.microsoft.com/zh-cn/dotnet/api/system.invalidoperationexception)，检查 Freezable 对象的值[CanFreeze](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.canfreeze)属性来确定是否它可以冻结然后再尝试冻结它。

```csharp
if (myBrush.CanFreeze)
{
    // Makes the brush unmodifiable.
    myBrush.Freeze();
}
```

当不再需要进行修改的 freezable 时，冻结它提供性能优势。 如果要冻结的画笔在此示例中，图形系统将不再需要监视的更改。 图形系统还可以进行其他优化，因为它知道画笔不会更改。

> 为方便起见，freezable 对象保持未冻结，除非显式冻结。

### 使用的可冻结对象

使用解冻 freezable 就像使用任何其他类型的对象。 在下面的示例中，颜色[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)从黄色更改为红色后它用于绘制按钮背景。 图形系统来自动更改按钮从黄色为红色的下次刷新屏幕时在后台工作。

```csharp
Button myButton = new Button();
SolidColorBrush myBrush = new SolidColorBrush(Colors.Yellow);
myButton.Background = myBrush;  


// Changes the button's background to red.
myBrush.Color = Colors.Red;
```

#### 冻结 Freezable

若要使[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)变为不可修改，则调用其[Freeze](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.freeze)方法。 冻结包含 freezable 对象的对象，这些对象也会冻结起来。例如，如果冻结[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)，数字和其包含的段会被冻结。

Freezable**不能**被冻结，如果以下任何条件成立：

- 它具有经过动画处理或数据绑定属性。
- 它具有由动态资源设置的属性。 (请参阅[XAML 资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-resources)动态资源有关的详细信息。)
- 它包含[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)不能冻结的子对象。

如果这些条件都为 false，并且不打算修改[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)，则应冻结其获得前面所述的性能优势。

一旦调用 freezable 的[Freeze](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.freeze)方法，它无法再进行修改。 尝试修改的冻结对象会导致[InvalidOperationException](https://docs.microsoft.com/zh-cn/dotnet/api/system.invalidoperationexception)引发。 下面的代码引发异常，因为我们试图修改画笔后已被冻结。

```csharp
Button myButton = new Button();
SolidColorBrush myBrush = new SolidColorBrush(Colors.Yellow);          

if (myBrush.CanFreeze)
{
    // Makes the brush unmodifiable.
    myBrush.Freeze();
}

myButton.Background = myBrush;  

try {

    // Throws an InvalidOperationException, because the brush is frozen.
    myBrush.Color = Colors.Red;
}catch(InvalidOperationException ex)
{
    MessageBox.Show("Invalid operation: " + ex.ToString());
}
```

若要避免此异常，可以使用[IsFrozen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.isfrozen)方法，以确定是否[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)处于冻结状态。

```csharp
Button myButton = new Button();
SolidColorBrush myBrush = new SolidColorBrush(Colors.Yellow);

if (myBrush.CanFreeze)
{
    // Makes the brush unmodifiable.
    myBrush.Freeze();
}            

myButton.Background = myBrush;


if (myBrush.IsFrozen) // Evaluates to true.
{
    // If the brush is frozen, create a clone and
    // modify the clone.
    SolidColorBrush myBrushClone = myBrush.Clone();
    myBrushClone.Color = Colors.Red;
    myButton.Background = myBrushClone;
}
else
{
    // If the brush is not frozen,
    // it can be modified directly.
    myBrush.Color = Colors.Red;
}
```

在前面的代码示例中，可修改副本已冻结的对象使用的[Clone](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.clone)方法。 下一节讨论了更详细地克隆。

**请注意**因为冻结 freezable 不能进行动画处理时，动画系统将自动创建的可修改克隆冻结[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)对象时尝试与它们进行动画处理[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)。 若要消除开销引起的克隆的性能，请将解冻如果你想要对其进行动画处理的对象。有关使用演示图板进行动画处理的详细信息，请参阅[情节提要概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/storyboards-overview)。

#### 从标记冻结

若要冻结[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)对象声明在标记中，您使用`PresentationOptions:Freeze`属性。 在以下示例中，[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)声明为页面资源和冻结。 然后使用来设置按钮的背景。

```xaml
<Page 
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  xmlns:PresentationOptions="http://schemas.microsoft.com/winfx/2006/xaml/presentation/options" 
  xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
  mc:Ignorable="PresentationOptions">

  <Page.Resources>

    <!-- This resource is frozen. -->
    <SolidColorBrush 
      x:Key="MyBrush"
      PresentationOptions:Freeze="True" 
      Color="Red" />
  </Page.Resources>


  <StackPanel>

    <Button Content="A Button" 
      Background="{StaticResource MyBrush}">
    </Button>

  </StackPanel>
</Page>
```

若要使用`Freeze`属性，则必须映射到演示文稿选项命名空间： `http://schemas.microsoft.com/winfx/2006/xaml/presentation/options`。 `PresentationOptions` 是映射此命名空间的建议的前缀：

```
xmlns:PresentationOptions="http://schemas.microsoft.com/winfx/2006/xaml/presentation/options"   
```

因为并非所有 XAML 读取器都识别此特性，建议你使用[mc: Ignorable 特性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/mc-ignorable-attribute)标记`Presentation:Freeze`为可忽略属性：

```
xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"  
mc:Ignorable="PresentationOptions"  
```

有关详细信息，请参阅[mc: Ignorable 特性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/mc-ignorable-attribute)页。

#### "解冻"Freezable

一次冻结[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)永远不会修改或解冻; 但是，可以创建使用一个未冻结的克隆[Clone](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.clone)或[CloneCurrentValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.clonecurrentvalue)方法。

在以下示例中，使用一个画笔设置按钮的背景，然后冻结该画笔。 冻结的副本组成画笔使用[Clone](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.clone)方法。 克隆是修改并用于将按钮的背景由黄色更改为红色。

```csharp
Button myButton = new Button();
SolidColorBrush myBrush = new SolidColorBrush(Colors.Yellow);

// Freezing a Freezable before it provides
// performance improvements if you don't
// intend on modifying it. 
if (myBrush.CanFreeze)
{
    // Makes the brush unmodifiable.
    myBrush.Freeze();
}
            

myButton.Background = myBrush;  

// If you need to modify a frozen brush,
// the Clone method can be used to
// create a modifiable copy.
SolidColorBrush myBrushClone = myBrush.Clone();

// Changing myBrushClone does not change
// the color of myButton, because its
// background is still set by myBrush.
myBrushClone.Color = Colors.Red;

// Replacing myBrush with myBrushClone
// makes the button change to red.
myButton.Background = myBrushClone;
```

> 无论使用哪种克隆方法，动画不会被复制到新[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)。

[Clone](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.clone)和[CloneCurrentValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.clonecurrentvalue)方法会生成可冻结的深层副本。 如果 freezable 包含其他冻结 freezable 对象，它们是克隆，并且进行可修改的。 例如，如果你克隆的冻结[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)使可供修改，数字和其包含的段也复制并进行修改。

### 创建您自己的 Freezable 类

从派生的类[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)可以获得以下功能。

- 特殊状态： 只读 （冻结） 和可写状态。
- 线程安全： 的冻结[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)可以在线程之间共享。
- 详细的更改通知：与其他不同[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)s，对子属性值更改时 Freezable 对象提供更改通知。
- 简单克隆： Freezable 类已经实现生成深层克隆的几种方法。

一个[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)是一种[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)，因此使用依赖项属性系统。 类属性不一定要依赖项属性，但使用依赖项属性可以减少需要编写，因为代码量[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)类的设计中考虑的依赖属性了。 有关依赖属性系统的详细信息，请参阅[依赖属性概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-properties-overview)。

每个[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)子类必须重写[CreateInstanceCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.createinstancecore)方法。 如果您的类的所有数据使用依赖项属性时，您已完成。

如果您的类包含非依赖项属性数据成员，还必须重写以下方法：

- [CloneCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.clonecore)
- [CloneCurrentValueCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.clonecurrentvaluecore)
- [GetAsFrozenCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.getasfrozencore)
- [GetCurrentValueAsFrozenCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.getcurrentvalueasfrozencore)
- [FreezeCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.freezecore)

此外必须遵守以下规则用于访问和写入不属于依赖项属性的数据成员：

- 在任何开头API读取非依赖项属性数据成员，请调用[ReadPreamble](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.readpreamble)方法。
- 在开始任何 API，它将写入非依赖项属性数据成员时，调用[WritePreamble](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.writepreamble)方法。 (调用后[WritePreamble](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.writepreamble)中API，不需要进行额外调用[ReadPreamble](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.readpreamble)如果还读取非依赖项属性数据成员。)
- 调用[WritePostscript](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.writepostscript)方法，然后再退出写入非依赖项属性数据成员的方法。

如果您的类包含的非依赖项属性数据成员[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)对象，还必须调用[OnFreezablePropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.onfreezablepropertychanged)方法每次你更改其中一个其值，即使将该成员设置为`null`。

> 务必在开始各个[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)方法通过调用基实现重写。

有关自定义的示例[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)类，请参阅[自定义动画示例](https://go.microsoft.com/fwlink/?LinkID=159981)。

## [Alignment, Margins, and Padding Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/alignment-margins-and-padding-overview)

[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)类公开多个用于精确定位子元素的属性。 本主题讨论了 4 个最重要的属性：[HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.horizontalalignment)， [Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)， [Padding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border.padding)，和[VerticalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.verticalalignment)。 了解这些属性的作用非常重要，因为这些属性是控制元素在 Windows Presentation Foundation (WPF) 应用程序中的位置的基础。

### 元素定位简介

可使用 WPF 通过多种方式来定位元素。 但是，获得理想的布局远不止仅选择右侧[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)元素。 精确的定位控制，需要了解[HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.horizontalalignment)， [Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)， [Padding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border.padding)，和[VerticalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.verticalalignment)属性。

下图显示了一个采用若干定位属性的布局方案。

![WPF 定位属性示例](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/layout-margins-padding-alignment-graphic1.png)

第一次看到[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)似乎随意放置在此图中的元素。 但是，其位置实际上是通过使用边距、对齐和填充加以精确控制的。

下面的示例描述如何创建上图中的布局。 一个[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)元素封装了父[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)，使用[Padding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border.padding)15 与设备无关的像素的值。 此帐户为窄[LightBlue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brushes.lightblue)环绕子外[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)。 子元素的[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)用于说明每个本主题中详述的各个定位属性。 三个[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)元素用于演示了这两[Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)和[HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.horizontalalignment)属性。

```csharp
// Create the application's main Window.
mainWindow = new Window ();
mainWindow.Title = "Margins, Padding and Alignment Sample";

// Add a Border
myBorder = new Border();
myBorder.Background = Brushes.LightBlue;
myBorder.BorderBrush = Brushes.Black;
myBorder.Padding = new Thickness(15);
myBorder.BorderThickness = new Thickness(2);

myStackPanel = new StackPanel();
myStackPanel.Background = Brushes.White;
myStackPanel.HorizontalAlignment = HorizontalAlignment.Center;
myStackPanel.VerticalAlignment = VerticalAlignment.Top;

TextBlock myTextBlock = new TextBlock();
myTextBlock.Margin = new Thickness(5, 0, 5, 0);
myTextBlock.FontSize = 18;
myTextBlock.HorizontalAlignment = HorizontalAlignment.Center;
myTextBlock.Text = "Alignment, Margin and Padding Sample";
Button myButton1 = new Button();
myButton1.HorizontalAlignment = HorizontalAlignment.Left;
myButton1.Margin = new Thickness(20);
myButton1.Content = "Button 1";
Button myButton2 = new Button();
myButton2.HorizontalAlignment = HorizontalAlignment.Right;
myButton2.Margin = new Thickness(10);
myButton2.Content = "Button 2";
Button myButton3 = new Button();
myButton3.HorizontalAlignment = HorizontalAlignment.Stretch;
myButton3.Margin = new Thickness(0);
myButton3.Content = "Button 3";

// Add child elements to the parent StackPanel.
myStackPanel.Children.Add(myTextBlock);
myStackPanel.Children.Add(myButton1);
myStackPanel.Children.Add(myButton2);
myStackPanel.Children.Add(myButton3);

// Add the StackPanel as the lone Child of the Border.
myBorder.Child = myStackPanel;

// Add the Border as the Content of the Parent Window Object.
mainWindow.Content = myBorder;
mainWindow.Show ();
```

通过下图可以仔细查看上例中使用的各个定位属性。 本主题的后面各节更详细地介绍了如何使用各个定位属性。

![具有屏幕标注的定位属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/layout-margins-padding-alignment-graphic2.png)



### 了解 Alignment 属性

[HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.horizontalalignment)和[VerticalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.verticalalignment)属性描述应如何在父元素的已分配的布局空间内定位子元素。 结合使用这些属性可精确定位子元素。 例如，子元素的[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)可以指定四个不同的水平对齐方式： [Left](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.horizontalalignment#System_Windows_HorizontalAlignment_Left)， [Right](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.horizontalalignment#System_Windows_HorizontalAlignment_Right)，或[Center](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.horizontalalignment#System_Windows_HorizontalAlignment_Center)，或设置为[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.horizontalalignment#System_Windows_HorizontalAlignment_Stretch)以填充可用空间。 类似的值可用于垂直定位。

> 显式设置[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)并[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)上一个元素的属性优先于[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.horizontalalignment#System_Windows_HorizontalAlignment_Stretch)属性值。 尝试设置[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)， [Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)，和一个[HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.horizontalalignment)的值`Stretch`导致`Stretch`请求被忽略。

#### HorizontalAlignment 属性

[HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.horizontalalignment)属性声明要应用于子元素的水平对齐特性。 下表显示了每个可能的值的[HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.horizontalalignment)属性。

| 成员                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [Left](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.horizontalalignment#System_Windows_HorizontalAlignment_Left) | 子元素与父元素的已分配布局空间的左端对齐。                   |
| [Center](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.horizontalalignment#System_Windows_HorizontalAlignment_Center) | 子元素与父元素的已分配布局空间的中心对齐。                   |
| [Right](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.horizontalalignment#System_Windows_HorizontalAlignment_Right) | 子元素与父元素的已分配布局空间的右端对齐。                   |
| [Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.horizontalalignment#System_Windows_HorizontalAlignment_Stretch) （默认值） | 拉伸子元素以填充父元素的已分配布局空间。 显式[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)和[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)值优先。 |

下面的示例演示如何应用[HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.horizontalalignment)属性设置为[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)元素。 显示每个特性值，以便更好地阐释各种呈现行为。

```csharp
Button myButton1 = new Button();
myButton1.HorizontalAlignment = HorizontalAlignment.Left;
myButton1.Content = "Button 1 (Left)";
Button myButton2 = new Button();
myButton2.HorizontalAlignment = HorizontalAlignment.Right;
myButton2.Content = "Button 2 (Right)";
Button myButton3 = new Button();
myButton3.HorizontalAlignment = HorizontalAlignment.Center;
myButton3.Content = "Button 3 (Center)";
Button myButton4 = new Button();
myButton4.HorizontalAlignment = HorizontalAlignment.Stretch;
myButton4.Content = "Button 4 (Stretch)";
```

以上代码将产生与下图类似的布局。 每个的定位效果[HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.horizontalalignment)值是在图中可见。

![HorizontalAlignment 示例](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/layout-horizontal-alignment-graphic.png)



#### VerticalAlignment 属性

[VerticalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.verticalalignment)属性描述要应用于子元素的垂直对齐特性。 下表显示了每个可能的值为[VerticalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.verticalalignment)属性。

| 成员                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [Top](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.verticalalignment#System_Windows_VerticalAlignment_Top) | 子元素与父元素的已分配布局空间的顶端对齐。                   |
| [Center](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.verticalalignment#System_Windows_VerticalAlignment_Center) | 子元素与父元素的已分配布局空间的中心对齐。                   |
| [Bottom](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.verticalalignment#System_Windows_VerticalAlignment_Bottom) | 子元素与父元素的已分配布局空间的底端对齐。                   |
| [Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.verticalalignment#System_Windows_VerticalAlignment_Stretch) （默认值） | 拉伸子元素以填充父元素的已分配布局空间。 显式[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)和[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)值优先。 |

下面的示例演示如何应用[VerticalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.verticalalignment)属性设置为[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)元素。 显示每个特性值，以便更好地阐释各种呈现行为。 对于此示例中，[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)带有可见网格线的元素用作父项，以更好地说明每个属性值的布局行为。

```csharp
TextBlock myTextBlock = new TextBlock();
myTextBlock.FontSize = 18;
myTextBlock.HorizontalAlignment = HorizontalAlignment.Center;
myTextBlock.Text = "VerticalAlignment Sample";
Grid.SetRow(myTextBlock, 0);
Button myButton1 = new Button();
myButton1.VerticalAlignment = VerticalAlignment.Top;
myButton1.Content = "Button 1 (Top)";
Grid.SetRow(myButton1, 1);
Button myButton2 = new Button();
myButton2.VerticalAlignment = VerticalAlignment.Bottom;
myButton2.Content = "Button 2 (Bottom)";
Grid.SetRow(myButton2, 2);
Button myButton3 = new Button();
myButton3.VerticalAlignment = VerticalAlignment.Center;
myButton3.Content = "Button 3 (Center)";
Grid.SetRow(myButton3, 3);
Button myButton4 = new Button();
myButton4.VerticalAlignment = VerticalAlignment.Stretch;
myButton4.Content = "Button 4 (Stretch)";
Grid.SetRow(myButton4, 4);
```

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      WindowTitle="VerticalAlignment Sample">
  <Border Background="LightBlue" BorderBrush="Black" BorderThickness="2" Padding="15">
    <Grid Background="White" ShowGridLines="True">
      <Grid.RowDefinitions>
        <RowDefinition Height="25"/>
        <RowDefinition Height="50"/>
        <RowDefinition Height="50"/>
        <RowDefinition Height="50"/>
        <RowDefinition Height="50"/>
      </Grid.RowDefinitions>
            <TextBlock Grid.Row="0" Grid.Column="0" FontSize="18" HorizontalAlignment="Center">VerticalAlignment Sample</TextBlock>
            <Button Grid.Row="1" Grid.Column="0" VerticalAlignment="Top">Button 1 (Top)</Button>
            <Button Grid.Row="2" Grid.Column="0" VerticalAlignment="Bottom">Button 2 (Bottom)</Button>    
            <Button Grid.Row="3" Grid.Column="0" VerticalAlignment="Center">Button 3 (Center)</Button>
            <Button Grid.Row="4" Grid.Column="0" VerticalAlignment="Stretch">Button 4 (Stretch)</Button>          
    </Grid>
  </Border>    
</Page>
```

以上代码将产生与下图类似的布局。 每个的定位效果[VerticalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.verticalalignment)值是在图中可见。

![VerticalAlignment 属性示例](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/layout-vertical-alignment-graphic.png)



### 了解 Margin 属性

[Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)属性描述元素与其子级或同级之间的距离。 [Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin) 通过使用类似的语法的值可以是统一的`Margin="20"`。使用以下语法，一个统一的[Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)的 20 设备无关的像素将应用于元素。 [Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin) 值也可采用四个非重复值的形式每个值，描述要应用于左侧、 顶部、 右侧和底端 （按此顺序） 的不同边距等`Margin="0,10,5,25"`。 正确使用[Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)属性使非常精确地控制元素的呈现位置，以及其邻近元素和子项的呈现位置。

> 非零的边距适用空间的元素之外[ActualWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.actualwidth)和[ActualHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.actualheight)。

以下示例演示如何以一组周围应用统一边距[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)元素。 [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)元素的间距都带有 10 像素的边距缓冲区中每个方向。

```csharp
Button myButton7 = new Button();
myButton7.Margin = new Thickness(10);
myButton7.Content = "Button 7";
Button myButton8 = new Button();
myButton8.Margin = new Thickness(10);
myButton8.Content = "Button 8";
Button myButton9 = new Button();
myButton9.Margin = new Thickness(10);
myButton9.Content = "Button 9";
```

```xaml
<Button Margin="10">Button 7</Button>
<Button Margin="10">Button 8</Button>
<Button Margin="10">Button 9</Button>
```

在许多情况下，不适合使用统一边距。 对于这些情况，可应用非统一间距。 下面的示例演示如何将非统一边距间距应用于子元素。 按此顺序描述边距：左端、顶端、右端和底端。

```csharp
Button myButton1 = new Button();
myButton1.Margin = new Thickness(0, 10, 0, 10);
myButton1.Content = "Button 1";
Button myButton2 = new Button();
myButton2.Margin = new Thickness(0, 10, 0, 10);
myButton2.Content = "Button 2";
Button myButton3 = new Button();
myButton3.Margin = new Thickness(0, 10, 0, 10);
```

```xaml
<Button Margin="0,10,0,10">Button 1</Button>
<Button Margin="0,10,0,10">Button 2</Button>
<Button Margin="0,10,0,10">Button 3</Button>
```

### 了解 Padding 属性

填充状态是类似于[Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)在大多数方面。 Padding 属性上公开仅在少数类，主要是为方便起见： [Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block)， [Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)， [Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)，和[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)是公开 Padding 属性的类的示例。 [Padding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border.padding)属性将子元素的有效大小放大指定[Thickness](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.thickness)值。

下面的示例演示如何应用[Padding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border.padding)为父[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)元素。

```csharp
myBorder = new Border();
myBorder.Background = Brushes.LightBlue;
myBorder.BorderBrush = Brushes.Black;
myBorder.BorderThickness = new Thickness(2);
myBorder.CornerRadius = new CornerRadius(45);
myBorder.Padding = new Thickness(25);
```

```xaml
<Border Background="LightBlue" 
        BorderBrush="Black" 
        BorderThickness="2" 
        CornerRadius="45" 
        Padding="25">
```



### 在应用程序中使用 Alignment、Margins 和 Padding

[HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.horizontalalignment)[Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)， [Padding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border.padding)，并[VerticalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.verticalalignment)提供所需创建复杂的定位控制用户界面 (UI)。 可利用每个属性的作用来更改子元素定位，以便能够灵活地创建动态应用程序和用户体验。

下面的示例演示本主题中详述的各个概念。 在本主题中的第一个示例中找到的基础结构上构建，此示例将添加[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)的子元素[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)在第一个示例。 [Padding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border.padding) 应用于父[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)元素。 [Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)用于三个子之间的空间分区[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)元素。 [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) 再次使用元素显示的不同效果[Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)和[HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.horizontalalignment)。 [TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock) 元素添加到每个[ColumnDefinition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.columndefinition)若要更好地定义应用于的各种属性[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)中每个列的元素。

```csharp
mainWindow = new Window();

myBorder = new Border();
myBorder.Background = Brushes.LightBlue;
myBorder.BorderBrush = Brushes.Black;
myBorder.BorderThickness = new Thickness(2);
myBorder.CornerRadius = new CornerRadius(45);
myBorder.Padding = new Thickness(25);

// Define the Grid.
myGrid = new Grid();
myGrid.Background = Brushes.White;
myGrid.ShowGridLines = true;

// Define the Columns.
ColumnDefinition myColDef1 = new ColumnDefinition();
myColDef1.Width = new GridLength(1, GridUnitType.Auto);
ColumnDefinition myColDef2 = new ColumnDefinition();
myColDef2.Width = new GridLength(1, GridUnitType.Star);
ColumnDefinition myColDef3 = new ColumnDefinition();
myColDef3.Width = new GridLength(1, GridUnitType.Auto);

// Add the ColumnDefinitions to the Grid.
myGrid.ColumnDefinitions.Add(myColDef1);
myGrid.ColumnDefinitions.Add(myColDef2);
myGrid.ColumnDefinitions.Add(myColDef3);

// Add the first child StackPanel.
StackPanel myStackPanel = new StackPanel();
myStackPanel.HorizontalAlignment = HorizontalAlignment.Left;
myStackPanel.VerticalAlignment = VerticalAlignment.Top;
Grid.SetColumn(myStackPanel, 0);
Grid.SetRow(myStackPanel, 0);
TextBlock myTextBlock1 = new TextBlock();
myTextBlock1.FontSize = 18;
myTextBlock1.HorizontalAlignment = HorizontalAlignment.Center;
myTextBlock1.Margin = new Thickness(0, 0, 0, 15);
myTextBlock1.Text = "StackPanel 1";
Button myButton1 = new Button();
myButton1.Margin = new Thickness(0, 10, 0, 10);
myButton1.Content = "Button 1";
Button myButton2 = new Button();
myButton2.Margin = new Thickness(0, 10, 0, 10);
myButton2.Content = "Button 2";
Button myButton3 = new Button();
myButton3.Margin = new Thickness(0, 10, 0, 10);
TextBlock myTextBlock2 = new TextBlock();
myTextBlock2.Text = @"ColumnDefinition.Width = ""Auto""";
TextBlock myTextBlock3 = new TextBlock();
myTextBlock3.Text = @"StackPanel.HorizontalAlignment = ""Left""";
TextBlock myTextBlock4 = new TextBlock();
myTextBlock4.Text = @"StackPanel.VerticalAlignment = ""Top""";
TextBlock myTextBlock5 = new TextBlock();
myTextBlock5.Text = @"StackPanel.Orientation = ""Vertical""";
TextBlock myTextBlock6 = new TextBlock();
myTextBlock6.Text = @"Button.Margin = ""1,10,0,10""";
myStackPanel.Children.Add(myTextBlock1);
myStackPanel.Children.Add(myButton1);
myStackPanel.Children.Add(myButton2);
myStackPanel.Children.Add(myButton3);
myStackPanel.Children.Add(myTextBlock2);
myStackPanel.Children.Add(myTextBlock3);
myStackPanel.Children.Add(myTextBlock4);
myStackPanel.Children.Add(myTextBlock5);
myStackPanel.Children.Add(myTextBlock6);

// Add the second child StackPanel.
StackPanel myStackPanel2 = new StackPanel();
myStackPanel2.HorizontalAlignment = HorizontalAlignment.Stretch;
myStackPanel2.VerticalAlignment = VerticalAlignment.Top;
myStackPanel2.Orientation = Orientation.Vertical;
Grid.SetColumn(myStackPanel2, 1);
Grid.SetRow(myStackPanel2, 0);
TextBlock myTextBlock7 = new TextBlock();
myTextBlock7.FontSize = 18;
myTextBlock7.HorizontalAlignment = HorizontalAlignment.Center;
myTextBlock7.Margin = new Thickness(0, 0, 0, 15);
myTextBlock7.Text = "StackPanel 2";
Button myButton4 = new Button();
myButton4.Margin = new Thickness(10, 0, 10, 0);
myButton4.Content = "Button 4";
Button myButton5 = new Button();
myButton5.Margin = new Thickness(10, 0, 10, 0);
myButton5.Content = "Button 5";
Button myButton6 = new Button();
myButton6.Margin = new Thickness(10, 0, 10, 0);
myButton6.Content = "Button 6";
TextBlock myTextBlock8 = new TextBlock();
myTextBlock8.HorizontalAlignment = HorizontalAlignment.Center;
myTextBlock8.Text = @"ColumnDefinition.Width = ""*""";
TextBlock myTextBlock9 = new TextBlock();
myTextBlock9.HorizontalAlignment = HorizontalAlignment.Center;
myTextBlock9.Text = @"StackPanel.HorizontalAlignment = ""Stretch""";
TextBlock myTextBlock10 = new TextBlock();
myTextBlock10.HorizontalAlignment = HorizontalAlignment.Center;
myTextBlock10.Text = @"StackPanel.VerticalAlignment = ""Top""";
TextBlock myTextBlock11 = new TextBlock();
myTextBlock11.HorizontalAlignment = HorizontalAlignment.Center;
myTextBlock11.Text = @"StackPanel.Orientation = ""Horizontal""";
TextBlock myTextBlock12 = new TextBlock();
myTextBlock12.HorizontalAlignment = HorizontalAlignment.Center;
myTextBlock12.Text = @"Button.Margin = ""10,0,10,0""";
myStackPanel2.Children.Add(myTextBlock7);
myStackPanel2.Children.Add(myButton4);
myStackPanel2.Children.Add(myButton5);
myStackPanel2.Children.Add(myButton6);
myStackPanel2.Children.Add(myTextBlock8);
myStackPanel2.Children.Add(myTextBlock9);
myStackPanel2.Children.Add(myTextBlock10);
myStackPanel2.Children.Add(myTextBlock11);
myStackPanel2.Children.Add(myTextBlock12);

// Add the final child StackPanel.
StackPanel myStackPanel3 = new StackPanel();
myStackPanel3.HorizontalAlignment = HorizontalAlignment.Left;
myStackPanel3.VerticalAlignment = VerticalAlignment.Top;
Grid.SetColumn(myStackPanel3, 2);
Grid.SetRow(myStackPanel3, 0);
TextBlock myTextBlock13 = new TextBlock();
myTextBlock13.FontSize = 18;
myTextBlock13.HorizontalAlignment = HorizontalAlignment.Center;
myTextBlock13.Margin = new Thickness(0, 0, 0, 15);
myTextBlock13.Text = "StackPanel 3";
Button myButton7 = new Button();
myButton7.Margin = new Thickness(10);
myButton7.Content = "Button 7";
Button myButton8 = new Button();
myButton8.Margin = new Thickness(10);
myButton8.Content = "Button 8";
Button myButton9 = new Button();
myButton9.Margin = new Thickness(10);
myButton9.Content = "Button 9";
TextBlock myTextBlock14 = new TextBlock();
myTextBlock14.Text = @"ColumnDefinition.Width = ""Auto""";
TextBlock myTextBlock15 = new TextBlock();
myTextBlock15.Text = @"StackPanel.HorizontalAlignment = ""Left""";
TextBlock myTextBlock16 = new TextBlock();
myTextBlock16.Text = @"StackPanel.VerticalAlignment = ""Top""";
TextBlock myTextBlock17 = new TextBlock();
myTextBlock17.Text = @"StackPanel.Orientation = ""Vertical""";
TextBlock myTextBlock18 = new TextBlock();
myTextBlock18.Text = @"Button.Margin = ""10""";
myStackPanel3.Children.Add(myTextBlock13);
myStackPanel3.Children.Add(myButton7);
myStackPanel3.Children.Add(myButton8);
myStackPanel3.Children.Add(myButton9);
myStackPanel3.Children.Add(myTextBlock14);
myStackPanel3.Children.Add(myTextBlock15);
myStackPanel3.Children.Add(myTextBlock16);
myStackPanel3.Children.Add(myTextBlock17);
myStackPanel3.Children.Add(myTextBlock18);

// Add child content to the parent Grid.
myGrid.Children.Add(myStackPanel);
myGrid.Children.Add(myStackPanel2);
myGrid.Children.Add(myStackPanel3);

// Add the Grid as the lone child of the Border.
myBorder.Child = myGrid;

// Add the Border to the Window as Content and show the Window.
mainWindow.Content = myBorder;
mainWindow.Title = "Margin, Padding, and Alignment Sample";
mainWindow.Show();
```

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation" WindowTitle="Margins, Padding and Alignment Sample">
  <Border Background="LightBlue" 
          BorderBrush="Black" 
          BorderThickness="2" 
          CornerRadius="45" 
          Padding="25">
    <Grid Background="White" ShowGridLines="True">
      <Grid.ColumnDefinitions>
        <ColumnDefinition Width="Auto"/>
        <ColumnDefinition Width="*"/>
        <ColumnDefinition Width="Auto"/>
      </Grid.ColumnDefinitions>
        
    <StackPanel Grid.Column="0" Grid.Row="0" HorizontalAlignment="Left" Name="StackPanel1" VerticalAlignment="Top">
        <TextBlock FontSize="18" HorizontalAlignment="Center" Margin="0,0,0,15">StackPanel1</TextBlock>
        <Button Margin="0,10,0,10">Button 1</Button>
        <Button Margin="0,10,0,10">Button 2</Button>
        <Button Margin="0,10,0,10">Button 3</Button>
        <TextBlock>ColumnDefinition.Width="Auto"</TextBlock>
        <TextBlock>StackPanel.HorizontalAlignment="Left"</TextBlock>
        <TextBlock>StackPanel.VerticalAlignment="Top"</TextBlock>
        <TextBlock>StackPanel.Orientation="Vertical"</TextBlock>
        <TextBlock>Button.Margin="0,10,0,10"</TextBlock>
    </StackPanel>
    
    <StackPanel Grid.Column="1" Grid.Row="0" HorizontalAlignment="Stretch" Name="StackPanel2" VerticalAlignment="Top" Orientation="Vertical">
        <TextBlock FontSize="18" HorizontalAlignment="Center" Margin="0,0,0,15">StackPanel2</TextBlock>
        <Button Margin="10,0,10,0">Button 4</Button>
        <Button Margin="10,0,10,0">Button 5</Button>
        <Button Margin="10,0,10,0">Button 6</Button>
        <TextBlock HorizontalAlignment="Center">ColumnDefinition.Width="*"</TextBlock>
        <TextBlock HorizontalAlignment="Center">StackPanel.HorizontalAlignment="Stretch"</TextBlock>
        <TextBlock HorizontalAlignment="Center">StackPanel.VerticalAlignment="Top"</TextBlock>
        <TextBlock HorizontalAlignment="Center">StackPanel.Orientation="Horizontal"</TextBlock>
        <TextBlock HorizontalAlignment="Center">Button.Margin="10,0,10,0"</TextBlock>
    </StackPanel>        
        
    <StackPanel Grid.Column="2" Grid.Row="0" HorizontalAlignment="Left" Name="StackPanel3" VerticalAlignment="Top">
        <TextBlock FontSize="18" HorizontalAlignment="Center" Margin="0,0,0,15">StackPanel3</TextBlock>
        <Button Margin="10">Button 7</Button>
        <Button Margin="10">Button 8</Button>
        <Button Margin="10">Button 9</Button>
        <TextBlock>ColumnDefinition.Width="Auto"</TextBlock>
        <TextBlock>StackPanel.HorizontalAlignment="Left"</TextBlock>
        <TextBlock>StackPanel.VerticalAlignment="Top"</TextBlock>
        <TextBlock>StackPanel.Orientation="Vertical"</TextBlock>
        <TextBlock>Button.Margin="10"</TextBlock>      
    </StackPanel>
  </Grid>
  </Border>    
</Page>
```

编译后，前面的应用程序生成类似于下图的 UI。 不同的属性值的效果元素之间的间距中并且显示在每个列中的元素的重要属性值内[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素。

![一个应用程序中的多个定位属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/layout-margins-padding-aligment-graphic3.png)



### 下一步

定义的位置属性[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)类可以精确地控制中的元素布局WPF应用程序。 至此你已了解多种方法，可使用这些方法更好地通过 WPF 来定位元素。

我们还提供了一些附加资源，这些资源更详细地介绍 WPF 布局。 [面板概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/panels-overview)主题包含有关的各种详细信息[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)元素。 本主题[演练：我第一个 WPF 桌面应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/getting-started/walkthrough-my-first-wpf-desktop-application)引入了使用布局元素来定位组件并将其操作绑定到数据源的高级的技术。

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/base-elements-how-to-topics)

本部分中的主题介绍如何使用四个 WPF 基元素： [UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)， [ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement)， [FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)，和[FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement)。

### 本节内容

[将 UIElement 设为透明或半透明](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-make-a-uielement-transparent-or-semi-transparent)
[为 FrameworkElement 大小设置动画效果](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-animate-the-size-of-a-frameworkelement)
[确定 Freezable 对象是否已冻结](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-determine-whether-a-freezable-is-frozen)
[处理 Loaded 事件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-handle-a-loaded-event)
[设置元素和控件的边距](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-set-margins-of-elements-and-controls)
[将 Freezable 对象设为只读](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-make-a-freezable-read-only)
[获取只读 Freezable 对象的可写副本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-obtain-a-writable-copy-of-a-read-only-freezable)
[水平或垂直翻转 UIElement](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-flip-a-uielement-horizontally-or-vertically)
[使用 ThicknessConverter 对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-use-a-thicknessconverter-object)
[处理 ContextMenuOpening 事件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-handle-the-contextmenuopening-event)

### [Make a UIElement Transparent or Semi-Transparent](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-make-a-uielement-transparent-or-semi-transparent)

此示例演示如何使[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)透明或不完全透明。 若要使元素透明或不完全透明，你将设置其[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)属性。 值为`0.0`使元素完全透明，而值`1.0`使元素完全不透明。 值为`0.5`使元素 50%不透明，依次类推。 元素的[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)设置为`1.0`默认情况下。

#### 示例

下面的示例设置[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)到按钮的`0.25`，使它和其内容 （在这种情况下，该按钮的文本） 25%不透明。

```xaml
<!-- Both the button and its text are made 25% opaque. -->
<Button Opacity="0.25">A Button</Button>
```

```csharp
//
// Both the button and its text are made 25% opaque.
//
Button myTwentyFivePercentOpaqueButton = new Button();
myTwentyFivePercentOpaqueButton.Opacity = new Double();
myTwentyFivePercentOpaqueButton.Opacity = 0.25;
myTwentyFivePercentOpaqueButton.Content = "A Button";
```

如果元素的内容有其自己[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)设置，这些值乘以包含元素[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)。

下面的示例设置按钮的[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)到`0.25`，和[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)的[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)控件中的按钮为与包含`0.5`。 因此，图像将显示 12.5%不透明： 0.25 * 0.5 = 0.125。

```xaml
<!-- The image contained within this button has an effective
     opacity of 0.125 (0.25 * 0.5 = 0.125). -->
<Button Opacity="0.25">
  <StackPanel Orientation="Horizontal">
    <TextBlock VerticalAlignment="Center" Margin="10">A Button</TextBlock>
    <Image Source="sampleImages\berries.jpg" Width="50" Height="50"
      Opacity="0.5"/>
  </StackPanel>
</Button>
```

```csharp
//
// The image contained within this button has an 
// effective opacity of 0.125 (0.25*0.5 = 0.125);
//
Button myImageButton = new Button();
myImageButton.Opacity = new Double();
myImageButton.Opacity = 0.25;

StackPanel myImageStackPanel = new StackPanel();
myImageStackPanel.Orientation = Orientation.Horizontal;


TextBlock myTextBlock = new TextBlock();
myTextBlock.VerticalAlignment = VerticalAlignment.Center;
myTextBlock.Margin = new Thickness(10);
myTextBlock.Text = "A Button";
myImageStackPanel.Children.Add(myTextBlock);

Image myImage = new Image();
BitmapImage myBitmapImage = new BitmapImage();
myBitmapImage.BeginInit();
myBitmapImage.UriSource = new Uri("sampleImages/berries.jpg",UriKind.Relative);
myBitmapImage.EndInit();
myImage.Source = myBitmapImage;
ImageBrush myImageBrush = new ImageBrush(myBitmapImage);
myImage.Width = 50;
myImage.Height = 50;
myImage.Opacity = 0.5;
myImageStackPanel.Children.Add(myImage);
myImageButton.Content = myImageStackPanel;       
```

若要控制元素的不透明度的另一个方法是设置的不透明度[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)绘制元素。 这种方法，您可以有选择性地修改元素，某些部分的不透明度，并通过使用元素的提供性能优势[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)属性。 下面的示例设置[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.opacity)的[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)用于绘制按钮的[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)设置为`0.25`。 因此，画笔的背景为 25%不透明的但其内容 （该按钮的文本） 仍保留 100%不透明。

```xaml
<!-- This button's background is made 25% opaque, but its
     text remains 100% opaque. -->
<Button>
  <Button.Background>
    <SolidColorBrush Color="Gray" Opacity="0.25" />
  </Button.Background>
  A Button
</Button>
```

```csharp
//
//  This button's background is made 25% opaque, 
// but its text remains 100% opaque.
//
Button myOpaqueTextButton = new Button();
SolidColorBrush mySolidColorBrush = new SolidColorBrush(Colors.Gray);
mySolidColorBrush.Opacity = 0.25;
myOpaqueTextButton.Background = mySolidColorBrush;
myOpaqueTextButton.Content = "A Button";
```

您也可以控制单个画笔颜色的不透明度。 有关颜色和画笔的详细信息，请参阅[使用纯色和渐变概述绘制](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-solid-colors-and-gradients-overview)。 有关展示如何进行动画处理的元素的不透明度的示例，请参阅[动画元素或画笔的不透明度](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-animate-the-opacity-of-an-element-or-brush)。

### [Animate the Size of a FrameworkElement](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-animate-the-size-of-a-frameworkelement)

要进行动画处理的大小[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)，你可以对其[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)和[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)属性或使用经过动画处理的[ScaleTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform)。

在下面的示例以进行动画处理使用这两种方法的两个按钮的大小。 通过对进行动画处理调整一个按钮的大小及其[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)通过进行动画处理调整大小属性，另一个[ScaleTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform)应用于其[RenderTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransform)属性。 每个按钮包含一些文本。 最初，则将显示文本中两个按钮相同，但按钮是调整大小时，在第二个按钮的文本会显得失真。

#### 示例

```xaml
<!-- AnimatingSizeExample.xaml
     This example shows two ways of animating the size
     of a framework element. -->
<Page 
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  x:Class="Microsoft.Samples.Animation.AnimatingSizeExample" 
  WindowTitle="Animating Size Example">    
  <Canvas Width="650" Height="400">
    
    <Button Name="AnimatedWidthButton"
      Canvas.Left="20" Canvas.Top="20"      
      Width="200" Height="150"
      BorderBrush="Red" BorderThickness="5">
        Click Me
      <Button.Triggers>
      
        <!-- Animate the button's Width property. -->
        <EventTrigger RoutedEvent="Button.Loaded">
          <BeginStoryboard>
            <Storyboard>
              <DoubleAnimation
                Storyboard.TargetName="AnimatedWidthButton"
                Storyboard.TargetProperty="(Button.Width)"
                To="500" Duration="0:0:10" AutoReverse="True" 
                RepeatBehavior="Forever" />
            </Storyboard>
          </BeginStoryboard>
        </EventTrigger>
      </Button.Triggers>
    </Button>
    
    <Button 
      Canvas.Left="20" Canvas.Top="200"
      Width="200" Height="150"
      BorderBrush="Black" BorderThickness="3"> 
        Click Me
      <Button.RenderTransform>
         <ScaleTransform x:Name="MyAnimatedScaleTransform" 
          ScaleX="1" ScaleY="1"  />
      </Button.RenderTransform>
      <Button.Triggers>
      
        <!-- Animate the ScaleX property of a ScaleTransform
             applied to the button. -->
        <EventTrigger RoutedEvent="Button.Loaded">
          <BeginStoryboard>
            <Storyboard>
              <DoubleAnimation
                Storyboard.TargetName="MyAnimatedScaleTransform"
                Storyboard.TargetProperty="(ScaleTransform.ScaleX)"
                To="3.0" Duration="0:0:10" AutoReverse="True"
                RepeatBehavior="Forever" />
            </Storyboard>
          </BeginStoryboard>
        </EventTrigger>
      </Button.Triggers>      
    </Button>
  </Canvas> 
</Page>
```

当你转换元素时, 转换整个元素和其内容。 当您直接改变元素，如下所示的第一个按钮，这种情况的大小除非其大小和位置取决于其父元素的大小无法调整大小的元素的内容。

通过应用到动画的转换对元素的大小进行动画处理其[RenderTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransform)属性提供更好的性能不是动画处理其[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)和[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)直接，因为[RenderTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransform)属性不会触发了布局过程。

有关对属性进行动画处理的详细信息，请参阅[动画概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/animation-overview)。 有关转换的详细信息，请参阅[转换概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/transforms-overview)。

### [Determine Whether a Freezable Is Frozen](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-determine-whether-a-freezable-is-frozen)

此示例演示如何确定是否[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)对象已被冻结。 如果你尝试修改的冻结[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)对象，它会引发[InvalidOperationException](https://docs.microsoft.com/zh-cn/dotnet/api/system.invalidoperationexception)。 若要避免此异常，请使用[IsFrozen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.isfrozen)属性的[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)对象，以确定是否已被冻结。

#### 示例

下面的示例冻结[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)并测试使用[IsFrozen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.isfrozen)属性来确定是否已被冻结。

```csharp
Button myButton = new Button();
SolidColorBrush myBrush = new SolidColorBrush(Colors.Yellow);

if (myBrush.CanFreeze)
{
    // Makes the brush unmodifiable.
    myBrush.Freeze();
}            

myButton.Background = myBrush;


if (myBrush.IsFrozen) // Evaluates to true.
{
    // If the brush is frozen, create a clone and
    // modify the clone.
    SolidColorBrush myBrushClone = myBrush.Clone();
    myBrushClone.Color = Colors.Red;
    myButton.Background = myBrushClone;
}
else
{
    // If the brush is not frozen,
    // it can be modified directly.
    myBrush.Color = Colors.Red;
}
```

有关详细信息[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)对象，请参阅[Freezable 对象概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/freezable-objects-overview)。

### [Handle a Loaded Event](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-handle-a-loaded-event)

此示例演示如何处理[FrameworkElement.Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)事件，并处理该事件的适当的方案。 该处理程序创建[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)加载页面时。

#### 示例

下面的示例使用可扩展应用程序标记语言 (XAML)以及代码隐藏文件。

```xaml
<StackPanel
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  x:Class="SDKSample.FELoaded"
  Loaded="OnLoad"
  Name="root"
>
</StackPanel>
```

```csharp
void OnLoad(object sender, RoutedEventArgs e)
{
    Button b1 = new Button();
    b1.Content = "New Button";
    root.Children.Add(b1);
    b1.Height = 25;
    b1.Width = 200;
    b1.HorizontalAlignment = HorizontalAlignment.Left;
}
```

### [Set Margins of Elements and Controls](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-set-margins-of-elements-and-controls)

本示例介绍了如何设置[Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)属性，通过更改的代码隐藏文件中的边距任何现有属性值。 [Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)属性是属性的[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)基元素，并因此由各种控件和其他元素继承。

此示例用编写可扩展应用程序标记语言 (XAML)，与隐藏代码文件XAML引用。 代码隐藏所示的 C# 和 Microsoft Visual Basic 版本。

#### 示例

```xaml
<Button Click="OnClick" Margin="10" Name="btn1">
Click To See Change!!</Button>
```

```csharp
void OnClick(object sender, RoutedEventArgs e)
{
    // Get the current value of the property.
    Thickness marginThickness = btn1.Margin;
    // If the current leftlength value of margin is set to 10 then change it to a new value.
    // Otherwise change it back to 10.
    if(marginThickness.Left == 10)
    {
         btn1.Margin = new Thickness(60);
    } else {
         btn1.Margin = new Thickness(10);
    }
}
```

### [Make a Freezable Read-Only](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-make-a-freezable-read-only)

此示例演示如何使[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)只读通过调用其[Freeze](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.freeze)方法。

不能冻结[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)对象是否满足以下条件之一`true`有关对象：

- 它具有经过动画处理或数据绑定属性。
- 它具有由动态资源设置的属性。 有关动态资源的详细信息，请参阅[XAML 资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-resources)。
- 它包含[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)不能冻结的子对象。

如果这些条件`false`为你[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)对象，并且您不想要对其进行修改，请考虑冻结它来获得性能优势。

#### 示例

下面的示例冻结[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)，这是一种类型的[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)对象。

```csharp
Button myButton = new Button();
SolidColorBrush myBrush = new SolidColorBrush(Colors.Yellow);          

if (myBrush.CanFreeze)
{
    // Makes the brush unmodifiable.
    myBrush.Freeze();
}

myButton.Background = myBrush;  
```

有关详细信息[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)对象，请参阅[Freezable 对象概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/freezable-objects-overview)。

### [Obtain a Writable Copy of a Read-Only Freezable](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-obtain-a-writable-copy-of-a-read-only-freezable)

此示例演示如何使用[Clone](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.clone)方法来创建一个只读的可写副本[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)。

之后[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)对象标记为只读的 （"冻结"），您不能修改它。 但是，可以使用[Clone](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.clone)方法来创建冻结对象的可修改复本。

#### 示例

下面的示例创建的冻结的可修改复本[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)对象。

```csharp
Button myButton = new Button();
SolidColorBrush myBrush = new SolidColorBrush(Colors.Yellow);

// Freezing a Freezable before it provides
// performance improvements if you don't
// intend on modifying it. 
if (myBrush.CanFreeze)
{
    // Makes the brush unmodifiable.
    myBrush.Freeze();
}
            

myButton.Background = myBrush;  

// If you need to modify a frozen brush,
// the Clone method can be used to
// create a modifiable copy.
SolidColorBrush myBrushClone = myBrush.Clone();

// Changing myBrushClone does not change
// the color of myButton, because its
// background is still set by myBrush.
myBrushClone.Color = Colors.Red;

// Replacing myBrush with myBrushClone
// makes the button change to red.
myButton.Background = myBrushClone;
```

有关详细信息[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)对象，请参阅[Freezable 对象概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/freezable-objects-overview)。

### [Flip a UIElement Horizontally or Vertically](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-flip-a-uielement-horizontally-or-vertically)

此示例演示如何使用[ScaleTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform)翻转[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)水平或垂直。 在此示例中，[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)控件 (一种[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)) 通过应用翻转[ScaleTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform)到其[RenderTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransform)属性。

#### 示例

下图显示了要翻转的按钮。

![无转换的按钮](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/graphicsmm-buttonflipbeforeflip.gif)
若要翻转 UIElement

以下显示了创建按钮的代码。

```xaml
<Button Content="Flip me!" Padding="5">
</Button>
```

#### 示例

若要水平翻转的按钮，创建[ScaleTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform)并设置其[ScaleX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform.scalex)属性设置为-1。 将应用[ScaleTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform)到按钮的[RenderTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransform)属性。

```xaml
<Button Content="Flip me!" Padding="5">
  <Button.RenderTransform>
    <ScaleTransform ScaleX="-1" />
  </Button.RenderTransform>
</Button>
```

![有关水平翻转的按钮(0，0)](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/graphicsmm-buttonfliphorizontalflip-displaced.gif)
在应用 ScaleTransform 后按钮

#### 示例

您可以看到从上图中，已翻转的按钮，但同时也移动了。 这是因为已从其左上角翻转的按钮。 若要就地翻转的按钮，你想要应用[ScaleTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform)到的中心，而不是角。 应用的简单办法[ScaleTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform)center 是设置按钮的按钮为[RenderTransformOrigin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransformorigin)属性设置为 0.5，0.5。

```xaml
<Button Content="Flip me!" Padding="5"
  RenderTransformOrigin="0.5,0.5">
  <Button.RenderTransform>
    <ScaleTransform ScaleX="-1" />
  </Button.RenderTransform>
</Button>
```

![围绕中心水平翻转的按钮](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/graphicsmm-buttonfliphorizontalflip-inplace.gif)
将按钮与为 0.5，RenderTransformOrigin 0.5

#### 示例

若要垂直翻转的按钮，设置[ScaleTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform)对象的[ScaleY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform.scaley)属性，而不是其[ScaleX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform.scalex)属性。

```xaml
<Button Content="Flip me!" Padding="5"
  RenderTransformOrigin="0.5,0.5">
  <Button.RenderTransform>
    <ScaleTransform ScaleY="-1" />
  </Button.RenderTransform>
</Button>
```

![围绕中心垂直翻转的按钮](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/graphicsmm-buttonflipverticalflip-inplace.gif)
垂直翻转的按钮

### [Use a ThicknessConverter Object](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-use-a-thicknessconverter-object)

#### 示例

此示例演示如何创建的实例[ThicknessConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.thicknessconverter)并使用它来更改边框的粗细。

该示例定义一个名为的自定义方法`changeThickness`; 此方法首先将转换的内容[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)在单独的定义，可扩展应用程序标记语言 (XAML)文件的实例[Thickness](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.thickness)，和更高版本将转换到的内容[String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)。 此方法将传递[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)到[ThicknessConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.thicknessconverter)对象，它将转换[Content](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.content)的[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)的实例[Thickness](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.thickness)。 然后将此值传递的值为[BorderThickness](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border.borderthickness)属性的[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)。

此示例不运行。

```csharp
private void changeThickness(object sender, SelectionChangedEventArgs args)
{
    ListBoxItem li = ((sender as ListBox).SelectedItem as ListBoxItem);
    ThicknessConverter myThicknessConverter = new ThicknessConverter();
    Thickness th1 = (Thickness)myThicknessConverter.ConvertFromString(li.Content.ToString());
    border1.BorderThickness = th1;
    bThickness.Text = "Border.BorderThickness =" + li.Content.ToString();
}
```

### [Handle the ContextMenuOpening Event](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-handle-the-contextmenuopening-event)

[ContextMenuOpening](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.contextmenuopening)应用程序可以调整现有的上下文菜单之前来显示或禁止显示本应通过设置中显示的菜单中，可以处理事件[Handled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedeventargs.handled)属性设置为`true`事件数据中。 设置的典型原因[Handled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedeventargs.handled)到`true`在事件数据将替换为菜单完全新[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)对象，这有时需要取消该操作并启动新打开的。 如果您编写的处理程序[ContextMenuOpening](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.contextmenuopening)事件，您应注意的计时问题之间[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)控件和服务，它负责打开和一般情况下定位控件的上下文菜单。 本主题演示了其中一些各种上下文菜单打开方案的代码技术，并说明了计时问题派上用场的事例。

有几种方案用于处理[ContextMenuOpening](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.contextmenuopening)事件：

- 调整之前显示的菜单项。
- 替换为在显示之前的整个菜单。
- 完全禁止显示任何现有的上下文菜单，并不显示任何上下文菜单。

#### 示例

#### 调整之前显示的菜单项

调整现有的菜单项是相当简单，可能是最常见的方案。 您可以这样做才能添加或减少以响应在应用程序中的当前状态信息或可用作其中请求的上下文菜单的对象的属性的特定状态信息的上下文菜单选项。

一般的方法是获取事件的来源，这是我们右键单击特定控件，并获取[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.contextmenu)从它的属性。 你通常想要检查[Items](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.items)集合，以查看哪些上下文菜单项已存在在菜单中，然后添加或删除相应的新[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)到或从集合中的项。

```csharp
void AddItemToCM(object sender, ContextMenuEventArgs e)
{
    //check if Item4 is already there, this will probably run more than once
    FrameworkElement fe = e.Source as FrameworkElement;
    ContextMenu cm = fe.ContextMenu;
    foreach (MenuItem mi in cm.Items)
    {
        if ((String)mi.Header == "Item4") return;
    }
    MenuItem mi4 = new MenuItem();
    mi4.Header = "Item4";
    fe.ContextMenu.Items.Add(mi4);
}
```

#### 替换为在显示之前的整个菜单

另一种方案是如果你想要替换整个上下文菜单。 您无法当然也使用上述代码中，一种变体删除每个现有的上下文菜单项并添加新的从零项开始。 但更直观的方法，用于更换的上下文菜单中的所有项是创建一个新[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)，其中填充项，并将[FrameworkElement.ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.contextmenu)为这个新的控件属性[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)。

以下是用于替换的简单的处理程序代码[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)。 该代码引用自定义`BuildMenu`方法，它分隔出这是因为多个示例处理程序之一。

```csharp
void HandlerForCMO(object sender, ContextMenuEventArgs e)
{
    FrameworkElement fe = e.Source as FrameworkElement;
    fe.ContextMenu = BuildMenu();
}
```

```csharp
ContextMenu BuildMenu()
{
    ContextMenu theMenu = new ContextMenu();
    MenuItem mia = new MenuItem();
    mia.Header = "Item1";
    MenuItem mib = new MenuItem();
    mib.Header = "Item2";
    MenuItem mic = new MenuItem();
    mic.Header = "Item3";
    theMenu.Items.Add(mia);
    theMenu.Items.Add(mib);
    theMenu.Items.Add(mic);
    return theMenu;
}
```

但是，如果使用的处理程序的此样式[ContextMenuOpening](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.contextmenuopening)，您可能可以公开计时问题，如果您设置的对象[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)没有预先存在的上下文菜单。 在用户右键单击一个控件，当[ContextMenuOpening](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.contextmenuopening)引发即使现有[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)为空或 null。 但在这种情况下，任何新[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)对源设置元素太晚到达要显示。 此外，如果用户要用鼠标右键单击第二次，这一次新[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)出现，则该值为非 null 和您的处理程序将正确替换和第二次运行该处理程序时显示菜单。 这表明两个可能的解决方法：

1. 确保[ContextMenuOpening](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.contextmenuopening)处理程序对具有至少一个占位符控件始终运行[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)可用，其中你想要替换为处理程序代码。 在这种情况下，仍可以使用上一示例所示的处理程序，但你通常想要分配一个占位符[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)初始标记中：

   ```xaml
   <StackPanel>
     <Rectangle Fill="Yellow" Width="200" Height="100" ContextMenuOpening="HandlerForCMO">
       <Rectangle.ContextMenu>
         <ContextMenu>
           <MenuItem>Initial menu; this will be replaced ...</MenuItem>
         </ContextMenu>
       </Rectangle.ContextMenu>
     </Rectangle>
     <TextBlock>Right-click the rectangle above, context menu gets replaced</TextBlock>
   </StackPanel>
   ```

2. 假设初始[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)值可能为 null，根据一些初步的逻辑。 你可以选中复选[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)为 null 或使用代码以检查是否已被您的处理程序中的标志至少运行一次。 因为你假设[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)有关是要显示，您的处理程序，然后设置[Handled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedeventargs.handled)到`true`事件数据中。 向[ContextMenuService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenuservice)，它负责显示上下文菜单中，`true`值[Handled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedeventargs.handled)数据在事件表示取消的显示上下文菜单 / 控件组合，用于引发事件的请求。

现在，你已阻止的潜在可疑的上下文菜单下, 一步是提供一个新的活动，然后将其显示。 设置新的其中一个是基本上与上一个处理程序相同： 生成一个新[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)，然后设置控制源[FrameworkElement.ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.contextmenu)与它的属性。 其他步骤是您现在必须强制显示的上下文菜单中，因为禁止显示第一次尝试。 若要强制显示，则设置[Popup.IsOpen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.isopen)属性设置为`true`处理程序中。 谨慎执行此操作，因为在处理程序中打开上下文菜单引发[ContextMenuOpening](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.contextmenuopening)再次事件。 如果你重新输入您的处理程序，它将无限递归。 这就是原因，始终需要检查`null`或使用一个标志，如果在打开一个上下文菜单[ContextMenuOpening](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.contextmenuopening)事件处理程序。

#### 禁止显示任何现有的上下文菜单，不显示任何上下文菜单

最后一种情况下，编写完全，禁止显示菜单处理程序并不常见。 如果给定的控件不应显示上下文菜单，有可能更合适的方法，以确保这比只是当用户请求其禁止显示菜单。 但如果你想要使用的处理程序来取消上下文菜单，并不显示任何内容，则只需将您的处理程序应设置[Handled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedeventargs.handled)到`true`事件数据中。 [ContextMenuService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenuservice) ，负责显示上下文菜单将检查它在控件引发的事件的事件数据。 如果事件被标记为[Handled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedeventargs.handled)任意位置路由，然后启动了事件的上下文菜单打开操作被取消。

```csharp
    void HandlerForCMO2(object sender, ContextMenuEventArgs e)
    {
        if (!FlagForCustomContextMenu)
        {
            e.Handled = true; //need to suppress empty menu
            FrameworkElement fe = e.Source as FrameworkElement;
            fe.ContextMenu = BuildMenu();
            FlagForCustomContextMenu = true;
            fe.ContextMenu.IsOpen = true;
        }
    }
}
```

