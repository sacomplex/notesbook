# [Adorners](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/adorners)

本部分提供有关装饰器的信息和Windows Presentation Foundation (WPF)装饰器框架。

## [Adorners Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/adorners-overview)

装饰器是一种特殊的[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)，可用来向用户提供可视提示。 装饰器有很多用途，可用来向元素添加功能句柄，或者提供有关某个控件的状态信息。

### 关于装饰器

[Adorner](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adorner)是一个自定义[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)绑定到[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)。 在中呈现装饰器[AdornerLayer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adornerlayer)，这是一个始终是基础装饰的元素或装饰元素的集合上的呈现图面。 呈现装饰器是独立于呈现的[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)装饰器绑定到的。 装饰器通常使用位于装饰元素左上部的标准 2D 坐标原点，相对于其绑定到的元素进行定位。

装饰器的常见应用包括：

- 添加功能句柄[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)，使用户能够操作以某种方式 （重设大小、 旋转、 重新定位等） 的元素。
- 提供视觉反馈以指示各种状态，或者响应各种事件。
- 上叠加视觉效果[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)。
- 以可视方式遮盖或替代部分或全部[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)。

Windows Presentation Foundation (WPF) 提供用于装饰视觉元素的基本框架。 下表列出了装饰对象时使用的主要类型及其用途。 下面是几个用法示例。

|                                                              |                                                  |
| ------------------------------------------------------------ | ------------------------------------------------ |
| [Adorner](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adorner) | 一个抽象基类，从中继承所有的具体装饰器实现。     |
| [AdornerLayer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adornerlayer) | 一个类，表示一个或多个装饰元素的装饰器的呈现层。 |
| [AdornerDecorator](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adornerdecorator) | 一个类，使装饰器层与元素集合相关联。             |



### 实现自定义装饰器

Windows Presentation Foundation (WPF) 提供的装饰器框架的主要用于支持创建自定义装饰器。 通过实现继承自抽象的类创建自定义装饰器[Adorner](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adorner)类。

> 父[Adorner](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adorner)是[AdornerLayer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adornerlayer)呈现[Adorner](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adorner)、 不被修饰元素。

下面的示例展示了实现简单装饰器的类。 示例装饰器简单装饰的边角[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)使用圆圈。

```csharp
// Adorners must subclass the abstract base class Adorner.
public class SimpleCircleAdorner : Adorner
{
  // Be sure to call the base class constructor.
  public SimpleCircleAdorner(UIElement adornedElement)
    : base(adornedElement) 
  { 
  }

  // A common way to implement an adorner's rendering behavior is to override the OnRender
  // method, which is called by the layout system as part of a rendering pass.
  protected override void OnRender(DrawingContext drawingContext)
  {
    Rect adornedElementRect = new Rect(this.AdornedElement.DesiredSize);

    // Some arbitrary drawing implements.
    SolidColorBrush renderBrush = new SolidColorBrush(Colors.Green);
    renderBrush.Opacity = 0.2;
    Pen renderPen = new Pen(new SolidColorBrush(Colors.Navy), 1.5);
    double renderRadius = 5.0;

    // Draw a circle at each corner.
    drawingContext.DrawEllipse(renderBrush, renderPen, adornedElementRect.TopLeft, renderRadius, renderRadius);
    drawingContext.DrawEllipse(renderBrush, renderPen, adornedElementRect.TopRight, renderRadius, renderRadius);
    drawingContext.DrawEllipse(renderBrush, renderPen, adornedElementRect.BottomLeft, renderRadius, renderRadius);
    drawingContext.DrawEllipse(renderBrush, renderPen, adornedElementRect.BottomRight, renderRadius, renderRadius);
  }
}
```

下图显示了应用于 SimpleCircleAdorner [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。

![装饰器示例：经过装饰的文本框](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/adornedtextbox.png)

### 装饰器的呈现行为

请务必注意，装饰器不包括任何继承呈现行为，确保装饰器呈现是装饰器实施者的责任。 实现呈现行为的常用方法是重写[OnRender](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.onrender)方法，并使用一个或多个[DrawingContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingcontext)对象以便呈现装饰器的视觉对象根据需要 （如上面的示例中所示）。

> 放置在装饰器层中的任何内容将呈现在设置的其他任何样式的顶部。 换言之，装饰器始终以可见的方式位于顶部，无法使用 z 顺序重写。

### 事件和命中测试

装饰器接收输入的事件就像任何其他[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)。 由于装饰器始终具有更高版本 z 顺序比它装饰的元素，该装饰器接收输入的事件 (如[Drop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.drop)或[MouseMove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mousemove)) 可能适用于基础装饰元素。 装饰器可以侦听某些输入事件，并通过重新引发这些事件将它们传递到基础装饰元素。

若要启用传递命中测试装饰器下的元素，请设置命中的测试[IsHitTestVisible](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ishittestvisible)属性设置为**false**在装饰器上。 有关命中测试的详细信息，请参阅

[可视化层中的命中测试](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/hit-testing-in-the-visual-layer)。

### 装饰单个 UIElement

若要将装饰器绑定到特定[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)，请执行以下步骤：

1. 调用静态方法[GetAdornerLayer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adornerlayer.getadornerlayer)若要获取[AdornerLayer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adornerlayer)对象[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)为要装饰。 [GetAdornerLayer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adornerlayer.getadornerlayer) 从指定的可视化树向上[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)，并返回它找到的第一个装饰器层。 （如果未发现装饰器层，该方法将返回 null。）
2. 调用[Add](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adornerlayer.add)方法以将装饰器绑定到目标[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)。

下面的示例将 SimpleCircleAdorner （如上所示） 到绑定[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)名为*myTextBox*。

```csharp
myAdornerLayer = AdornerLayer.GetAdornerLayer(myTextBox);
myAdornerLayer.Add(new SimpleCircleAdorner(myTextBox));
```

> 目前不支持使用 可扩展应用程序标记语言 (XAML) 将装饰器绑定到另一个元素。

### 装饰面板的子级

若要将装饰器绑定到的子级[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)，请执行以下步骤：

1. 调用`static`方法[GetAdornerLayer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adornerlayer.getadornerlayer)其子级是为要装饰的元素查找装饰器层。
2. 枚举的子级的父元素并调用[Add](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adornerlayer.add)方法将装饰器绑定到每个子元素。

下面的示例将 SimpleCircleAdorner （如上所示） 的子级绑定[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)名为*myStackPanel*。

```csharp
foreach (UIElement toAdorn in myStackPanel.Children)
  myAdornerLayer.Add(new SimpleCircleAdorner(toAdorn));
```

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/adorners-how-to-topics)

下面的示例演示如何完成常见任务使用Windows Presentation Foundation (WPF)装饰器框架。

[实现装饰器](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-implement-an-adorner)
[将装饰器绑定到元素](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-bind-an-adorner-to-an-element)
[装饰面板的子元素](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-adorn-the-children-of-a-panel)
[从元素中删除装饰器](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-remove-an-adorner-from-an-element)
[从元素中删除所有装饰器](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-remove-all-adorners-from-an-element)

### [Implement an Adorner](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-implement-an-adorner)

此示例显示了最小的装饰器实现。

#### 实施者的说明

请务必注意，装饰器不包括任何继承呈现行为，确保装饰器呈现是装饰器实施者的责任。 实现呈现行为的常用方法是重写[OnRender](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.onrender)方法，并使用一个或多个[DrawingContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingcontext)对象以便呈现装饰器的视觉对象根据需要 （如在此示例中所示）。

通过实现继承自抽象的类创建自定义装饰器[Adorner](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adorner)类。 示例装饰器简单装饰的边角[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)使用通过重写的圆圈[OnRender](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.onrender)方法。

```csharp
// Adorners must subclass the abstract base class Adorner.
public class SimpleCircleAdorner : Adorner
{
  // Be sure to call the base class constructor.
  public SimpleCircleAdorner(UIElement adornedElement)
    : base(adornedElement) 
  { 
  }

  // A common way to implement an adorner's rendering behavior is to override the OnRender
  // method, which is called by the layout system as part of a rendering pass.
  protected override void OnRender(DrawingContext drawingContext)
  {
    Rect adornedElementRect = new Rect(this.AdornedElement.DesiredSize);

    // Some arbitrary drawing implements.
    SolidColorBrush renderBrush = new SolidColorBrush(Colors.Green);
    renderBrush.Opacity = 0.2;
    Pen renderPen = new Pen(new SolidColorBrush(Colors.Navy), 1.5);
    double renderRadius = 5.0;

    // Draw a circle at each corner.
    drawingContext.DrawEllipse(renderBrush, renderPen, adornedElementRect.TopLeft, renderRadius, renderRadius);
    drawingContext.DrawEllipse(renderBrush, renderPen, adornedElementRect.TopRight, renderRadius, renderRadius);
    drawingContext.DrawEllipse(renderBrush, renderPen, adornedElementRect.BottomLeft, renderRadius, renderRadius);
    drawingContext.DrawEllipse(renderBrush, renderPen, adornedElementRect.BottomRight, renderRadius, renderRadius);
  }
}
```

### [Bind an Adorner to an Element](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-bind-an-adorner-to-an-element)

此示例演示如何以编程方式将装饰器绑定到指定[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)。



若要将装饰器绑定到特定[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)，请执行以下步骤：

1. 调用`static`方法[GetAdornerLayer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adornerlayer.getadornerlayer)若要获取[AdornerLayer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adornerlayer)对象[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)为要装饰。 [GetAdornerLayer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adornerlayer.getadornerlayer) 从指定的可视化树向上**UIElement**，并返回它找到的第一个装饰器层。 （如果未发现装饰器层，该方法将返回 null。）
2. 调用[Add](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adornerlayer.add)方法以将装饰器绑定到目标**UIElement**。

下面的示例将 SimpleCircleAdorner （如上所示） 到绑定[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)名为*myTextBox*。

```csharp
myAdornerLayer = AdornerLayer.GetAdornerLayer(myTextBox);
myAdornerLayer.Add(new SimpleCircleAdorner(myTextBox));
```

> 目前不支持使用 可扩展应用程序标记语言 (XAML) 将装饰器绑定到另一个元素。

### [Adorn the Children of a Panel](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-adorn-the-children-of-a-panel)

此示例演示如何以编程方式将装饰器绑定到指定的子级[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)。

若要将装饰器绑定到的子级[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)，请执行以下步骤：

1. 声明一个新[AdornerLayer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adornerlayer)对象，并调用`static`[GetAdornerLayer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adornerlayer.getadornerlayer)方法的子级为要装饰的元素查找装饰器层。
2. 枚举的子级的父元素并调用[Add](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adornerlayer.add)方法将装饰器绑定到每个子元素。

下面的示例将 SimpleCircleAdorner （如上所示） 的子级绑定[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)名为*myStackPanel*。

```csharp
foreach (UIElement toAdorn in myStackPanel.Children)
  myAdornerLayer.Add(new SimpleCircleAdorner(toAdorn));
```

> 目前不支持使用 可扩展应用程序标记语言 (XAML) 将装饰器绑定到另一个元素。

### [Remove an Adorner from an Element](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-remove-an-adorner-from-an-element)

此示例演示如何以编程方式删除特定的装饰器从指定[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)。

此详细的代码示例的装饰器返回的数组中移除第一个装饰器[GetAdorners](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adornerlayer.getadorners)。 此示例检索在装饰器恰好[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)名为*myTextBox*。 如果在调用中指定元素[GetAdorners](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adornerlayer.getadorners)有任何装饰器，`null`返回。 此代码显式检查 null 的数组，并最适合应用程序的空数组的地方是比较常见。

```csharp
Adorner[] toRemoveArray = myAdornerLayer.GetAdorners(myTextBox);
Adorner toRemove;
if (toRemoveArray != null)
{
  toRemove = toRemoveArray[0];
  myAdornerLayer.Remove(toRemove);
}
```

此简化的代码示例是功能上等效于上面所示的详细示例。 此代码不显式检查 null 数组，因此很可能，[NullReferenceException](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullreferenceexception)可能引发异常。 Null 数组的地方很少出现，此代码是最适合应用程序。

```csharp
try { myAdornerLayer.Remove((myAdornerLayer.GetAdorners(myTextBox))[0]); } catch { }
```

### [Remove all Adorners from an Element](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-remove-all-adorners-from-an-element)

此示例演示如何以编程方式移除所有装饰器从指定[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)。

此详细的代码示例中移除所有装饰器的装饰器返回的数组中[GetAdorners](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adornerlayer.getadorners)。 此示例检索在装饰器恰好[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)名为*myTextBox*。 如果在调用中指定元素[GetAdorners](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adornerlayer.getadorners)有任何装饰器，`null`返回。 此代码显式检查 null 的数组，并最适合应用程序的空数组的地方是比较常见。

```csharp
Adorner[] toRemoveArray = myAdornerLayer.GetAdorners(myTextBox);
if (toRemoveArray != null)
{
  for (int x = 0; x < toRemoveArray.Length; x++)
  {
    myAdornerLayer.Remove(toRemoveArray[x]);
  }
}
```

此简化的代码示例是功能上等效于上面所示的详细示例。 此代码不显式检查 null 数组，因此很可能，[NullReferenceException](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullreferenceexception)可能引发异常。 Null 数组的地方很少出现，此代码是最适合应用程序。

```csharp
try { foreach (Adorner toRemove in myAdornerLayer.GetAdorners(myTextBox)) myAdornerLayer.Remove(toRemove); } catch { }
```