# [Visual Layer Programming](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/visual-layer-programming)

[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)对象是一项核心WPF对象，它的主要角色是提供呈现支持。 用户界面控件，如[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)并[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)，派生自[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)类，并使用该类来保持其呈现数据。

## 本节内容

[可视化层中的命中测试](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/hit-testing-in-the-visual-layer)
[使用 DrawingVisual 对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/using-drawingvisual-objects)
[教程：在 Win32 应用程序中承载视觉对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/tutorial-hosting-visual-objects-in-a-win32-application)
[帮助主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/visual-layer-programming-how-to-topics)

## [Hit Testing in the Visual Layer](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/hit-testing-in-the-visual-layer)

本主题概述可视化层提供的命中测试功能。 命中测试支持，您可以确定几何或点值是否落在所呈现内容的[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)，从而可以实现用户界面行为，例如选择矩形来选择多个对象。

### 命中测试方案

[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)类提供了[InputHitTest](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.inputhittest)方法，它允许你针对使用给定的坐标值对元素进行命中测试。 在许多情况下，[InputHitTest](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.inputhittest)方法提供实现命中测试的元素的所需的功能。 但是，有多种方案可能需要在可视化层上实现命中测试。

- 命中测试所针对非[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)对象：如果要执行命中测试不是如此[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)对象，如[DrawingVisual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingvisual)或图形对象。
- 命中测试几何图形的使用：如果你需要将 geometry 对象而不是一个点的坐标值的命中测试是如此。
- 命中测试所针对多个对象：这适用于需要针对多个对象，如重叠的对象进行命中测试。 可以获取与几何或点相交的所有视觉对象的结果，而不仅仅是第一个视觉对象的结果。
- 忽略[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)命中测试策略：适用于需要忽略[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)命中测试策略，将考虑这些因素，如元素是否已被禁用或不可见。

> 有关演示在可视化层上进行命中测试的完整代码示例，请参阅[使用 DrawingVisuals 进行命中测试示例](https://go.microsoft.com/fwlink/?LinkID=159994)和[使用 Win32 互操作进行命中测试示例](https://go.microsoft.com/fwlink/?LinkID=159995)。

### 命中测试支持

目的[HitTest](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualtreehelper.hittest)中的方法[VisualTreeHelper](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualtreehelper)类是确定几何或点坐标值是否为给定的对象，如控件或图形元素的呈现内容内。 例如，可以使用命中测试确定对象边框内的鼠标单击是否落在圆形的几何内。 还可以选择重写命中测试的默认实现，以执行自己的自定义命中测试计算。

下图显示非矩形对象的区域与其边框之间的关系。

![有效命中的测试区域示意图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wcpsdk-mmgraphics-visuals-hittest-1.png)
有效命中测试区域示意图

### 命中测试和 Z 顺序

Windows Presentation Foundation (WPF) 可视化层支持针对点或几何下的所有对象（而不仅仅是最顶层对象）进行命中测试。 结果按 z 顺序返回。 但是，作为参数传递的视觉对象[HitTest](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualtreehelper.hittest)方法确定哪个部分将被命中的可视化树的测试。 可以针对整个可视化树或它的任意部分进行命中测试。

在下图中，圆形对象在正方形和三角形对象之上。 如果只对感兴趣的命中测试其 z 顺序值为最顶层的视觉对象，可以设置可视化命中的测试枚举返回[Stop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.hittestresultbehavior#System_Windows_Media_HitTestResultBehavior_Stop)从[HitTestResultCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.hittestresultcallback)的第一项后停止命中的测试遍历。

![关系图的 z-的可视化树的顺序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wcpsdk-mmgraphics-visuals-hittest-2.png)
可视化树的 z 顺序示意图

如果你想要枚举特定点或几何下的所有视觉对象，则返回[Continue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.hittestresultbehavior#System_Windows_Media_HitTestResultBehavior_Continue)从[HitTestResultCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.hittestresultcallback)。 这意味着可以为其他对象之下的视觉对象进行命中测试，即使它们被完全遮挡也是如此。 有关详细信息，请参阅“使用命中测试结果回叫”部分中的示例代码。

> 还可以对透明的视觉对象进行命中测试。

### 使用默认命中测试

您可以确定一个点是否位于视觉对象的几何内使用[HitTest](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualtreehelper.hittest)方法，以指定的视觉对象和一个点坐标值要对其测试。视觉对象参数为命中测试搜索确定可视化树中的起始点。 如果其几何包含该坐标对可视化树中找到的视觉对象，则它设置为[VisualHit](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.hittestresult.visualhit)属性的[HitTestResult](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.hittestresult)对象。 [HitTestResult](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.hittestresult)则返回从[HitTest](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualtreehelper.hittest)方法。 如果该点不包含要执行命中测试的可视化子树[HitTest](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualtreehelper.hittest)返回`null`。

> 默认命中测试始终返回 z 顺序中最顶层的对象。 为了标识所有视觉对象（甚至是被部分或完全遮挡的视觉对象），请使用命中测试结果回叫。

将作为的点参数传递的坐标值[HitTest](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualtreehelper.hittest)方法必须是相对于命中测试所针对的视觉对象的坐标空间。 例如，如果在父级坐标空间的 (100, 100) 处定义了嵌套可视化对象，则对位于 (0, 0) 的子视觉对象进行命中测试等效于对父级坐标空间的 (100, 100) 处的子视觉对象进行命中测试。

下面的代码演示如何设置鼠标事件处理程序为[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)用于捕获用于事件的对象进行命中测试。

```csharp
// Respond to the left mouse button down event by initiating the hit test.
private void OnMouseLeftButtonDown(object sender, MouseButtonEventArgs e)
{
    // Retrieve the coordinate of the mouse position.
    Point pt = e.GetPosition((UIElement)sender);

    // Perform the hit test against a given portion of the visual object tree.
    HitTestResult result = VisualTreeHelper.HitTest(myCanvas, pt);

    if (result != null)
    {
        // Perform action on hit visual object.
    }
}
```

### 可视化树如何影响命中测试

可视化树中的起始点确定在对象的命中测试枚举期间返回哪些对象。 如果要对多个对象进行命中测试，在可视化树中用作起始点的视觉对象必须是所有相关对象的公共上级。 例如，如果希望对以下关系图中的按钮元素和绘图视觉对象进行命中测试，必须将可视化树中的起始点设置为两者的公共上级。 在这种情况下，画布元素是按钮元素和绘图视觉对象的公共上级。

![可视化树层次结构关系图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wcpsdk-mmgraphics-visuals-overview-01.gif)
可视化树的层次结构示意图

 备注

[IsHitTestVisible](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ishittestvisible)属性获取或设置一个值，声明是否[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)-派生的对象从其呈现内容的某些部分可能是返回作为命中的测试结果。 这使用户可以选择性地更改可视化树，以确定命中测试涉及哪些视觉对象。

### 使用命中测试结果回叫

可以在可视化树中枚举其几何包含特定坐标值的所有视觉对象。 这使用户可以标识所有视觉对象（甚至是被其他视觉对象部分或完全遮挡的视觉对象）。 若要枚举可视化树使用的视觉对象[HitTest](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualtreehelper.hittest)方法与命中的测试回叫函数。当指定的坐标值包含在视觉对象中时，系统会调用命中测试回叫函数。

在命中测试结果枚举期间，不应执行任何修改可视化树的操作。 在遍历可视化树的过程中，在可视化树中添加或删除对象可能会导致不可预知的行为。 您可以安全地修改后的可视化树[HitTest](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualtreehelper.hittest)方法返回。 您可能想要提供的数据结构，例如[ArrayList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.arraylist)、 命中的测试结果枚举期间存储值。

```csharp
// Respond to the right mouse button down event by setting up a hit test results callback.
private void OnMouseRightButtonDown(object sender, MouseButtonEventArgs e)
{
    // Retrieve the coordinate of the mouse position.
    Point pt = e.GetPosition((UIElement)sender);

    // Clear the contents of the list used for hit test results.
    hitResultsList.Clear();

    // Set up a callback to receive the hit test result enumeration.
    VisualTreeHelper.HitTest(myCanvas, null,
        new HitTestResultCallback(MyHitTestResult),
        new PointHitTestParameters(pt));

    // Perform actions on the hit test results list.
    if (hitResultsList.Count > 0)
    {
        Console.WriteLine("Number of Visuals Hit: " + hitResultsList.Count);
    }
}
```

命中测试回叫方法定义在可视化树中的特定视觉对象上标识命中测试时要执行的操作。 执行操作后，返回[HitTestResultBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.hittestresultbehavior)值，该值确定是否要继续或不进行任何其他视觉对象的枚举。

```csharp
// Return the result of the hit test to the callback.
public HitTestResultBehavior MyHitTestResult(HitTestResult result)
{
    // Add the hit test result to the list that will be processed after the enumeration.
    hitResultsList.Add(result.VisualHit);

    // Set the behavior to return visuals at all z-order levels.
    return HitTestResultBehavior.Continue;
}
```

> 命中视觉对象的枚举顺序为 z 顺序。 位于最顶层 z 顺序级别上的视觉对象是第一个枚举的对象。 所有其他视觉对象按递减的 z 顺序级别进行枚举。 此枚举顺序对应于视觉对象的呈现顺序。

可以通过返回停止命中的测试回叫函数中的任何时候视觉对象的枚举[Stop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.hittestresultbehavior#System_Windows_Media_HitTestResultBehavior_Stop)。

```csharp
// Set the behavior to stop enumerating visuals.
return HitTestResultBehavior.Stop;
```

### 使用命中测试筛选器回叫

可使用可选的命中测试筛选器来限制传递给命中测试结果的对象。 这样一来，你便可以在处理命中测试结果时忽略可视化树中的无关部分。 若要实现命中的测试筛选器，定义命中的测试筛选回调函数，并将其作为参数值传递，在调用时[HitTest](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualtreehelper.hittest)方法。

```csharp
// Respond to the mouse wheel event by setting up a hit test filter and results enumeration.
private void OnMouseWheel(object sender, MouseWheelEventArgs e)
{
    // Retrieve the coordinate of the mouse position.
    Point pt = e.GetPosition((UIElement)sender);

    // Clear the contents of the list used for hit test results.
    hitResultsList.Clear();

    // Set up a callback to receive the hit test result enumeration.
    VisualTreeHelper.HitTest(myCanvas,
                      new HitTestFilterCallback(MyHitTestFilter),
                      new HitTestResultCallback(MyHitTestResult),
                      new PointHitTestParameters(pt));

    // Perform actions on the hit test results list.
    if (hitResultsList.Count > 0)
    {
        ProcessHitTestResultsList();
    }
}
```

如果不希望提供可选的命中的测试筛选器回叫函数，传递`null`作为其参数的值[HitTest](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualtreehelper.hittest)方法。

```csharp
// Set up a callback to receive the hit test result enumeration,
// but no hit test filter enumeration.
VisualTreeHelper.HitTest(myCanvas,
                  null,  // No hit test filtering.
                  new HitTestResultCallback(MyHitTestResult),
                  new PointHitTestParameters(pt));
```

![修剪可视化树使用命中的测试筛选器](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/filteredvisualtree-01.png)
修剪可视化树

借助命中测试筛选器回叫函数，可以允许枚举呈现内容包含指定坐标的所有视觉对象。 但是，你可能要忽略不希望在命中测试结果回调叫函数中处理的可视化树的某些分支。 命中测试筛选器回叫函数的返回值确定视觉对象的枚举应采用的操作类型。 例如，如果返回值， [ContinueSkipSelfAndChildren](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.hittestfilterbehavior#System_Windows_Media_HitTestFilterBehavior_ContinueSkipSelfAndChildren)，可以从命中的测试结果枚举中删除当前的视觉对象及其子项。 这意味着，命中测试结果回叫函数不会在其枚举中看到这些对象。 修剪对象的可视化树会减少命中测试结果枚举传递期间的处理量。 在以下代码示例中，筛选器会跳过标签及其后代，并对其他所有内容进行命中测试。

```csharp
// Filter the hit test values for each object in the enumeration.
public HitTestFilterBehavior MyHitTestFilter(DependencyObject o)
{
    // Test for the object value you want to filter.
    if (o.GetType() == typeof(Label))
    {
        // Visual object and descendants are NOT part of hit test results enumeration.
        return HitTestFilterBehavior.ContinueSkipSelfAndChildren;
    }
    else
    {
        // Visual object is part of hit test results enumeration.
        return HitTestFilterBehavior.Continue;
    }
}
```

> 在未调用命中测试结果回叫的情况下，有时会调用命中测试筛选器回叫。

### 重写默认命中测试

可以重写视觉对象的默认命中测试支持通过重写[HitTestCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual.hittestcore)方法。 这意味着，当您调用[HitTest](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualtreehelper.hittest)方法中，您重写的实现[HitTestCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual.hittestcore)调用。 当命中测试落在视觉对象的边框内时，将调用重写的方法，即使坐标落在视觉对象呈现内容之外也是如此。

```csharp
// Override default hit test support in visual object.
protected override HitTestResult HitTestCore(PointHitTestParameters hitTestParameters)
{
    Point pt = hitTestParameters.HitPoint;

    // Perform custom actions during the hit test processing,
    // which may include verifying that the point actually
    // falls within the rendered content of the visual.

    // Return hit on bounding rectangle of visual object.
    return new PointHitTestResult(this, pt);
}
```

有时你可能希望针对视觉对象的边框和呈现内容进行命中测试。 通过使用`PointHitTestParameters`参数值中被重写[HitTestCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual.hittestcore)作为基方法的参数的方法[HitTestCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual.hittestcore)，可以根据命中的视觉对象的边界矩形执行操作，然后执行针对第二个命中的测试呈现的视觉对象的内容。

```csharp
// Override default hit test support in visual object.
protected override HitTestResult HitTestCore(PointHitTestParameters hitTestParameters)
{
    // Perform actions based on hit test of bounding rectangle.
    // ...

    // Return results of base class hit testing,
    // which only returns hit on the geometry of visual objects.
    return base.HitTestCore(hitTestParameters);
}
```

## [Using DrawingVisual Objects](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/using-drawingvisual-objects)

本主题概述了如何使用[DrawingVisual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingvisual)中的对象WPF可视化层。

### DrawingVisual 对象

[DrawingVisual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingvisual)是一个轻量绘图类，用于呈现形状、 图像或文本。 此类之所以为轻量类是因为它不提供布局或事件处理，从而性能得以提升。 因此，绘图非常适用于背景和剪贴画。

### DrawingVisual 宿主容器

若要使用[DrawingVisual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingvisual)对象，您需要创建宿主容器对象。 宿主容器对象必须派生自[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)类，该类提供的布局和事件处理支持[DrawingVisual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingvisual)类缺少。 宿主容器对象不显示任何可视属性，因为它的主要用途是包含子对象。 但是，[Visibility](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.visibility)宿主容器的属性必须设置为[Visible](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visibility#System_Windows_Visibility_Visible); 否则为 none 及其子元素将可见。

在创建视觉对象宿主容器对象时，您必须将存储中的视觉对象引用[VisualCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualcollection)。 使用[Add](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualcollection.add)方法将视觉对象添加到宿主容器。 以下示例中，在创建宿主容器对象，并且三个视觉对象添加到其[VisualCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualcollection)。

```csharp
// Create a host visual derived from the FrameworkElement class.
// This class provides layout, event handling, and container support for
// the child visual objects.
public class MyVisualHost : FrameworkElement
{
    // Create a collection of child visual objects.
    private VisualCollection _children;

    public MyVisualHost()
    {
        _children = new VisualCollection(this);
        _children.Add(CreateDrawingVisualRectangle());
        _children.Add(CreateDrawingVisualText());
        _children.Add(CreateDrawingVisualEllipses());

        // Add the event handler for MouseLeftButtonUp.
        this.MouseLeftButtonUp += new System.Windows.Input.MouseButtonEventHandler(MyVisualHost_MouseLeftButtonUp);
    }
```

 备注

有关从中提取上述代码示例的完整代码示例，请参阅[使用 DrawingVisual 的命中测试示例](https://go.microsoft.com/fwlink/?LinkID=159994)。



### 创建 DrawingVisual 对象

当你创建[DrawingVisual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingvisual)对象，它不包含任何绘图内容。 可以通过检索对象的添加文本、 图形或图像内容[DrawingContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingcontext)和在其中进行绘制。 一个[DrawingContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingcontext)返回通过调用[RenderOpen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingvisual.renderopen)方法的[DrawingVisual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingvisual)对象。

若要绘制到一个矩形[DrawingContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingcontext)，使用[DrawRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingcontext.drawrectangle)方法的[DrawingContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingcontext)对象。 对于绘制其他类型的内容，存在类似的方法。 完成内容绘制到时[DrawingContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingcontext)，调用[Close](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingcontext.close)方法关闭[DrawingContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingcontext)并保存内容。

在以下示例中，[DrawingVisual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingvisual)创建对象，和一个矩形绘制到其[DrawingContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingcontext)。

```csharp
// Create a DrawingVisual that contains a rectangle.
private DrawingVisual CreateDrawingVisualRectangle()
{
    DrawingVisual drawingVisual = new DrawingVisual();

    // Retrieve the DrawingContext in order to create new drawing content.
    DrawingContext drawingContext = drawingVisual.RenderOpen();

    // Create a rectangle and draw it in the DrawingContext.
    Rect rect = new Rect(new System.Windows.Point(160, 100), new System.Windows.Size(320, 80));
    drawingContext.DrawRectangle(System.Windows.Media.Brushes.LightBlue, (System.Windows.Media.Pen)null, rect);

    // Persist the drawing content.
    drawingContext.Close();

    return drawingVisual;
}
```



### 为 FrameworkElement 成员创建重写

宿主容器对象负责管理其视觉对象的集合。 这要求宿主容器实现为派生的成员重写[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)类。

下表介绍了必须重写的两个成员：

- [GetVisualChild](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.getvisualchild)：返回子元素的集合中的指定索引处的子级。
- [VisualChildrenCount](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.visualchildrencount)：获取此元素内可视子元素的数目。

在以下示例中，重写为两个[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)成员实现。

```csharp
// Provide a required override for the VisualChildrenCount property.
protected override int VisualChildrenCount
{
    get { return _children.Count; }
}

// Provide a required override for the GetVisualChild method.
protected override Visual GetVisualChild(int index)
{
    if (index < 0 || index >= _children.Count)
    {
        throw new ArgumentOutOfRangeException();
    }

    return _children[index];
}
```



### 提供命中测试支持

宿主容器对象可以提供事件处理，即使它不显示任何可视属性，但是，其[Visibility](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.visibility)属性必须设置为[Visible](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visibility#System_Windows_Visibility_Visible)。 这样便可以为宿主容器创建事件处理例程，此例程可以捕获鼠标事件，如松开鼠标左键。 然后，事件处理例程可以实现命中测试通过调用[HitTest](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualtreehelper.hittest)方法。 该方法的[HitTestResultCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.hittestresultcallback)参数是指可用于确定生成的命中测试操作的用户定义的过程。

在下面的示例中，为宿主容器对象及其子级实现命中测试支持。

```csharp
// Capture the mouse event and hit test the coordinate point value against
// the child visual objects.
void MyVisualHost_MouseLeftButtonUp(object sender, System.Windows.Input.MouseButtonEventArgs e)
{
    // Retreive the coordinates of the mouse button event.
    System.Windows.Point pt = e.GetPosition((UIElement)sender);

    // Initiate the hit test by setting up a hit test result callback method.
    VisualTreeHelper.HitTest(this, null, new HitTestResultCallback(myCallback), new PointHitTestParameters(pt));
}

// If a child visual object is hit, toggle its opacity to visually indicate a hit.
public HitTestResultBehavior myCallback(HitTestResult result)
{
    if (result.VisualHit.GetType() == typeof(DrawingVisual))
    {
        if (((DrawingVisual)result.VisualHit).Opacity == 1.0)
        {
            ((DrawingVisual)result.VisualHit).Opacity = 0.4;
        }
        else
        {
            ((DrawingVisual)result.VisualHit).Opacity = 1.0;
        }
    }

    // Stop the hit test enumeration of objects in the visual tree.
    return HitTestResultBehavior.Stop;
}
```

## [Tutorial: Hosting Visual Objects in a Win32 Application](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/tutorial-hosting-visual-objects-in-a-win32-application)

Windows Presentation Foundation (WPF) 提供了用于创建应用程序的丰富环境。 但是，当您有大量投入时Win32代码中，可能会更有效地添加WPF功能提供给你的应用程序而不是重写代码。 为提供支持Win32和WPF在应用程序，以并发方式使用的图形子系统WPF提供了用于托管中的对象的机制Win32窗口。

本教程介绍如何编写示例应用程序，[使用 Win32 互操作示例命中测试](https://go.microsoft.com/fwlink/?LinkID=159995)，则该主机WPF视觉对象中Win32窗口。

### 要求

本教程假定你已基本熟悉 WPF 和 Win32 编程。 有关的基本介绍WPF编程，请参见[演练：我第一个 WPF 桌面应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/getting-started/walkthrough-my-first-wpf-desktop-application)。 以大致Win32编程，请参见的众多书籍的任何主题，具体而言*编程 Windows* Charles Petzold 的。

> 本教程包括来自相关示例的一些代码示例。 但是，出于可读性考虑，不包括完整的示例代码。 有关完整的示例代码，请参阅[使用 Win32 互操作示例命中测试](https://go.microsoft.com/fwlink/?LinkID=159995)。

### 创建宿主 Win32 窗口

托管的关键WPF中的对象Win32窗口是[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)类。 此类将包装WPF中的对象Win32窗口中，从而允许它们合并到您用户界面 (UI)用作子窗口。

下面的示例演示用于创建的代码[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)对象作为Win32视觉对象的容器窗口。 若要设置窗口样式、 位置和其他参数Win32窗口中，使用[HwndSourceParameters](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsourceparameters)对象。

```csharp
// Constant values from the "winuser.h" header file.
internal const int WS_CHILD = 0x40000000,
                   WS_VISIBLE = 0x10000000;

internal static void CreateHostHwnd(IntPtr parentHwnd)
{
    // Set up the parameters for the host hwnd.
    HwndSourceParameters parameters = new HwndSourceParameters("Visual Hit Test", _width, _height);
    parameters.WindowStyle = WS_VISIBLE | WS_CHILD;
    parameters.SetPosition(0, 24);
    parameters.ParentWindow = parentHwnd;
    parameters.HwndSourceHook = new HwndSourceHook(ApplicationMessageFilter);

    // Create the host hwnd for the visuals.
    myHwndSource = new HwndSource(parameters);

    // Set the hwnd background color to the form's background color.
    myHwndSource.CompositionTarget.BackgroundColor = System.Windows.Media.Brushes.OldLace.Color;
}
```

 备注

值[ExtendedWindowStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsourceparameters.extendedwindowstyle)属性不能设置为 WS_EX_TRANSPARENT。 这意味着，宿主Win32窗口不能为透明。出于此原因，主机的背景色Win32窗口设置为作为其父窗口相同的背景色。



### 将视觉对象添加到宿主 Win32 窗口

当创建了主机后Win32容器窗口中的视觉对象，可以向其添加视觉对象。 你将想要确保诸如动画等视觉对象的任何转换不会超出边界的主机Win32窗口的边框。

下面的示例演示用于创建代码[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)对象，并向其添加视觉对象。

> [RootVisual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource.rootvisual)的属性[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)对象设置为第一个视觉对象添加到主机Win32窗口。 根视觉对象定义视觉对象树最顶层的节点。 任何后续的视觉对象添加到主机Win32窗口添加为子对象。

```csharp
public static void CreateShape(IntPtr parentHwnd)
{
    // Create an instance of the shape.
    MyShape myShape = new MyShape();

    // Determine whether the host container window has been created.
    if (myHwndSource == null)
    {
        // Create the host container window for the visual objects.
        CreateHostHwnd(parentHwnd);

        // Associate the shape with the host container window.
        myHwndSource.RootVisual = myShape;
    }
    else
    {
        // Assign the shape as a child of the root visual.
        ((ContainerVisual)myHwndSource.RootVisual).Children.Add(myShape);
    }
}
```

## 实现 Win32 消息筛选器

主机Win32视觉对象的窗口需要窗口消息筛选器过程，以处理从应用程序队列发送到窗口的消息。 窗口过程接收来自消息Win32系统。 这些消息可以是输入消息，也可以是窗口管理消息。 可以选择在窗口过程中处理一条消息，或将消息传递到系统以供默认处理。

[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)定义为视觉对象的父级必须引用你提供的窗口消息筛选器过程的对象。 当您创建[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)对象，设置[HwndSourceHook](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsourceparameters.hwndsourcehook)属性来引用窗口过程。

```csharp
parameters.HwndSourceHook = new HwndSourceHook(ApplicationMessageFilter);
```

下面的示例演示用于处理释放鼠标左键和右键消息的代码。 鼠标的坐标值点击位置中的值包含`lParam`参数。

```csharp
// Constant values from the "winuser.h" header file.
internal const int WM_LBUTTONUP = 0x0202,
                   WM_RBUTTONUP = 0x0205;

internal static IntPtr ApplicationMessageFilter(
    IntPtr hwnd, int message, IntPtr wParam, IntPtr lParam, ref bool handled)
{
    // Handle messages passed to the visual.
    switch (message)
    {
        // Handle the left and right mouse button up messages.
        case WM_LBUTTONUP:
        case WM_RBUTTONUP:
            System.Windows.Point pt = new System.Windows.Point();
            pt.X = (uint)lParam & (uint)0x0000ffff;  // LOWORD = x
            pt.Y = (uint)lParam >> 16;               // HIWORD = y
            MyShape.OnHitTest(pt, message);
            break;
    }

    return IntPtr.Zero;
}
```

### 处理 Win32 消息

在下面的示例代码演示如何对主机中包含的视觉对象的层次结构执行命中的测试Win32窗口。 您可以确定一个点是否位于视觉对象的几何内使用[HitTest](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualtreehelper.hittest)方法，以指定的根可视化对象和针对进行命中测试的坐标值。 在这种情况下，根视觉对象是值[RootVisual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource.rootvisual)属性的[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)对象。

```csharp
// Constant values from the "winuser.h" header file.
public const int WM_LBUTTONUP = 0x0202,
                 WM_RBUTTONUP = 0x0205;

// Respond to WM_LBUTTONUP or WM_RBUTTONUP messages by determining which visual object was clicked.
public static void OnHitTest(System.Windows.Point pt, int msg)
{
    // Clear the contents of the list used for hit test results.
    hitResultsList.Clear();

    // Determine whether to change the color of the circle or to delete the shape.
    if (msg == WM_LBUTTONUP)
    {
        MyWindow.changeColor = true;
    }
    if (msg == WM_RBUTTONUP)
    {
        MyWindow.changeColor = false;
    }

    // Set up a callback to receive the hit test results enumeration.
    VisualTreeHelper.HitTest(MyWindow.myHwndSource.RootVisual,
                             null,
                             new HitTestResultCallback(CircleHitTestResult),
                             new PointHitTestParameters(pt));

    // Perform actions on the hit test results list.
    if (hitResultsList.Count > 0)
    {
        ProcessHitTestResultsList();
    }
}
```

有关对视觉对象进行命中测试的详细信息，请参阅[可视化层中的命中测试](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/hit-testing-in-the-visual-layer)。

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/visual-layer-programming-how-to-topics)

在本部分中的主题演示如何使用可视化层进行命中测试和低级别的组合。

### 本节内容

[获取视觉对象偏移](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-get-the-offset-of-a-visual)
[枚举视觉对象的绘图内容](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-enumerate-drawing-content-of-a-visual)
[对视觉对象中的几何图形进行命中测试](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-hit-test-geometry-in-a-visual)
[将几何图形用作参数的命中测试](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-hit-test-using-geometry-as-a-parameter)
[使用 Win32 宿主容器进行命中测试](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-hit-test-using-a-win32-host-container)
[使用 CompositionTarget 按每帧间隔呈现](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-render-on-a-per-frame-interval-using-compositiontarget)

### [Get the Offset of a Visual](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-get-the-offset-of-a-visual)

这些示例显示如何检索相对于其父级或任何祖先或后代的可视对象的偏移量的值。

#### 示例

以下标记示例演示[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)定义与[Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)值为 4。

```xaml
<TextBlock Name="myTextBlock" Margin="4" Text="Hello, world" />
```

下面的代码示例演示如何使用[GetOffset](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualtreehelper.getoffset)方法来检索其中的偏移量[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)。 偏移量的值包含在返回[Vector](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.vector)值。

```csharp
// Return the offset vector for the TextBlock object.
Vector vector = VisualTreeHelper.GetOffset(myTextBlock);

// Convert the vector to a point value.
Point currentPoint = new Point(vector.X, vector.Y);
```

偏移量将考虑[Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)值。 在这种情况下，[X](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.vector.x)为 4，和[Y](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.vector.y)为 4。

返回的偏移量的值是相对于父级的[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)。 如果你想要返回的不是相对于父级的偏移量的值[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)，使用[TransformToAncestor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual.transformtoancestor)方法。

#### 获取偏移量相对于上级

以下标记示例演示[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)嵌套在两个[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)对象。

```xaml
<Window xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml" >
  <StackPanel Margin="16">
    <StackPanel Margin="8">
      <TextBlock Name="myTextBlock" Margin="4" Text="Hello, world" />
    </StackPanel>
  </StackPanel>
</Window>
```

下图显示标记的结果。

![对象的偏移量值](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/visualoffset-01.png)
嵌套在两个面板的 TextBlock

下面的代码示例演示如何使用[TransformToAncestor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual.transformtoancestor)方法来检索其中的偏移量[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)相对于包含[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)。 偏移量的值包含在返回[GeneralTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.generaltransform)值。

```csharp
// Return the general transform for the specified visual object.
GeneralTransform generalTransform1 = myTextBlock.TransformToAncestor(this);

// Retrieve the point value relative to the parent.
Point currentPoint = generalTransform1.Transform(new Point(0, 0));
```

偏移量会考虑[Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)值中包含的所有对象[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)。 在这种情况下，[X](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.vector.x)为 28 (16 + 8 + 4) 和[Y](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.vector.y)为 28。

返回的偏移量的值是相对于相对的祖先[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)。 如果你想要返回的偏移量的值是相对于的后代[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)，使用[TransformToDescendant](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual.transformtodescendant)方法。

#### 获取偏移量相对于后代

以下标记示例演示[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)包含在[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)对象。

```xaml
<StackPanel Name="myStackPanel" Margin="8">
  <TextBlock Name="myTextBlock" Margin="4" Text="Hello, world" />
</StackPanel>
```

下面的代码示例演示如何使用[TransformToDescendant](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual.transformtodescendant)方法来检索其中的偏移量[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)相对于其子[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)。偏移量的值包含在返回[GeneralTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.generaltransform)值。

```csharp
// Return the general transform for the specified visual object.
GeneralTransform generalTransform1 = myStackPanel.TransformToDescendant(myTextBlock);

// Retrieve the point value relative to the child.
Point currentPoint = generalTransform1.Transform(new Point(0, 0));
```

偏移量将考虑[Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)的所有对象的值。 在这种情况下，[X](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.vector.x)为-4，和[Y](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.vector.y)-4。 偏移量的值是负值，因为父对象产生负面偏移量相对于其子对象。

### [Enumerate Drawing Content of a Visual](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-enumerate-drawing-content-of-a-visual)

[Drawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawing)对象提供用于枚举的内容的对象模型[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)。

#### 示例

下面的示例使用[GetDrawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualtreehelper.getdrawing)方法来检索[DrawingGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawinggroup)的值[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)并枚举该值。

> 当枚举视觉对象的内容时，就在检索[Drawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawing)对象和表示形式呈现数据作为矢量图形指令列表不基础。 有关详细信息，请参阅 [WPF 图形呈现概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/wpf-graphics-rendering-overview)。

```csharp
public void RetrieveDrawing(Visual v)
{
    DrawingGroup drawingGroup = VisualTreeHelper.GetDrawing(v);
    EnumDrawingGroup(drawingGroup);
}

// Enumerate the drawings in the DrawingGroup.
public void EnumDrawingGroup(DrawingGroup drawingGroup)
{
    DrawingCollection dc = drawingGroup.Children;

    // Enumerate the drawings in the DrawingCollection.
    foreach (Drawing drawing in dc)
    {
        // If the drawing is a DrawingGroup, call the function recursively.
        if (drawing is DrawingGroup group)
        {
            EnumDrawingGroup(group);
        }
        else if (drawing is GeometryDrawing)
        {
            // Perform action based on drawing type.  
        }
        else if (drawing is ImageDrawing)
        {
            // Perform action based on drawing type.
        }
        else if (drawing is GlyphRunDrawing)
        {
            // Perform action based on drawing type.
        }
        else if (drawing is VideoDrawing)
        {
            // Perform action based on drawing type.
        }
    }
}
```

### [Hit Test Geometry in a Visual](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-hit-test-geometry-in-a-visual)

此示例演示如何以组成一个或多针对视觉对象执行命中的测试[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)对象。

#### 示例

下面的示例演示如何检索[DrawingGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawinggroup)使用的视觉对象从[GetDrawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualtreehelper.getdrawing)方法。 然后，每个绘图的呈现内容执行命中的测试[DrawingGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawinggroup)以确定命中了哪个几何图形。

> 在大多数情况下，您将使用[HitTest](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualtreehelper.hittest)方法，以确定是否在点相交的任何视觉对象呈现内容。

```csharp
// Determine if a geometry within the visual was hit.
static public void HitTestGeometryInVisual(Visual visual, Point pt)
{
    // Retrieve the group of drawings for the visual.
    DrawingGroup drawingGroup = VisualTreeHelper.GetDrawing(visual);
    EnumDrawingGroup(drawingGroup, pt);
}

// Enumerate the drawings in the DrawingGroup.
static public void EnumDrawingGroup(DrawingGroup drawingGroup, Point pt)
{
    DrawingCollection drawingCollection = drawingGroup.Children;

    // Enumerate the drawings in the DrawingCollection.
    foreach (Drawing drawing in drawingCollection)
    {
        // If the drawing is a DrawingGroup, call the function recursively.
        if (drawing.GetType() == typeof(DrawingGroup))
        {
            EnumDrawingGroup((DrawingGroup)drawing, pt);
        }
        else if (drawing.GetType() == typeof(GeometryDrawing))
        {
            // Determine whether the hit test point falls within the geometry.
            if (((GeometryDrawing)drawing).Geometry.FillContains(pt))
            {
                // Perform action based on hit test on geometry.
            }
        }

    }
}
```

[FillContains](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry.fillcontains)方法是重载的方法，您可以使用指定的命中测试[Point](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.point)或[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)。 绘制几何图形时，笔画可以延伸到填充边界之外。 在这种情况下，可能想要调用[StrokeContains](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry.strokecontains)除了[FillContains](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry.fillcontains)。

此外可以提供[ToleranceType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tolerancetype)用于贝塞尔拉平操作目的。

> 此示例并未考虑可能应用到几何图形中的任何变形或剪裁。 此外，此示例不会使用已设置样式的控件，因为这种控件没有与它直接关联的绘图。

### [Hit Test Using Geometry as a Parameter](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-hit-test-using-geometry-as-a-parameter)

此示例演示如何对视觉对象使用执行命中的测试[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)作为命中测试参数。

#### 示例

下面的示例演示如何设置命中的测试使用[GeometryHitTestParameters](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometryhittestparameters)为[HitTest](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualtreehelper.hittest)方法。 [Point](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.point)值传递给`OnMouseDown`方法用于创建[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)对象以扩展命中测试的范围。

```csharp
// Respond to the mouse button down event by setting up a hit test results callback.
private void OnMouseDown(object sender, MouseButtonEventArgs e)
{
    // Retrieve the coordinate of the mouse position.
    Point pt = e.GetPosition((UIElement)sender);

    // Expand the hit test area by creating a geometry centered on the hit test point.
    EllipseGeometry expandedHitTestArea = new EllipseGeometry(pt, 10.0, 10.0);

    // Clear the contents of the list used for hit test results.
    hitResultsList.Clear();

    // Set up a callback to receive the hit test result enumeration.
    VisualTreeHelper.HitTest(myControl, null,
        new HitTestResultCallback(MyHitTestResultCallback),
        new GeometryHitTestParameters(expandedHitTestArea));

    // Perform actions on the hit test results list.
    if (hitResultsList.Count > 0)
    {
        ProcessHitTestResultsList();
    }
}
```

[IntersectionDetail](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometryhittestresult.intersectiondetail)的属性[GeometryHitTestResult](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometryhittestresult)提供了有关使用的命中测试结果信息[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)作为命中测试参数。 下图演示了命中测试几何图形（蓝色圆圈）与目标视觉对象（红色正方形）的呈现内容之间的关系。

![中使用的 IntersectionDetail 的关系图进行命中测试](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/intersectiondetail01.png)
命中测试几何图形与目标视觉对象之间的交集

下面的示例演示如何实现命中的测试回叫时[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)用作命中的测试参数。 `result`参数强制转换为[GeometryHitTestResult](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometryhittestresult)以便检索的值[IntersectionDetail](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometryhittestresult.intersectiondetail)属性。 属性值可以确定如果[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)命中的测试参数完全或部分包含在命中的测试目标的呈现内容。 在本示例中，示例代码仅将命中测试结果添加到完全包含在目标边界中的视觉对象的列表中。

```csharp
// Return the result of the hit test to the callback.
public HitTestResultBehavior MyHitTestResultCallback(HitTestResult result)
{
    // Retrieve the results of the hit test.
    IntersectionDetail intersectionDetail = ((GeometryHitTestResult)result).IntersectionDetail;

    switch (intersectionDetail)
    {
        case IntersectionDetail.FullyContains:

            // Add the hit test result to the list that will be processed after the enumeration.
            hitResultsList.Add(result.VisualHit);

            return HitTestResultBehavior.Continue;

        case IntersectionDetail.Intersects:

            // Set the behavior to return visuals at all z-order levels.
            return HitTestResultBehavior.Continue;

        case IntersectionDetail.FullyInside:

            // Set the behavior to return visuals at all z-order levels.
            return HitTestResultBehavior.Continue;

        default:
            return HitTestResultBehavior.Stop;
    }
}
```

> [HitTestResult](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.hittestresult)交集详细信息时，不应调用回调[Empty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.intersectiondetail#System_Windows_Media_IntersectionDetail_Empty)。

### [Hit Test Using a Win32 Host Container](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-hit-test-using-a-win32-host-container)

可以创建视觉对象中的Win32通过视觉对象提供宿主窗口容器的窗口。 若要为包含的视觉对象提供事件处理，需要处理传递到宿主窗口容器的消息筛选器循环的消息。 请参阅[教程：承载在 Win32 应用程序中的视觉对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/tutorial-hosting-visual-objects-in-a-win32-application)有关详细信息如何托管中的可视化对象Win32窗口。

#### 示例

下面的代码演示如何设置鼠标事件处理程序为Win32用作视觉对象的宿主容器的窗口。

```csharp
// Constant values from the "winuser.h" header file.
internal const int WM_LBUTTONUP = 0x0202,
                   WM_RBUTTONUP = 0x0205;

internal static IntPtr ApplicationMessageFilter(
    IntPtr hwnd, int message, IntPtr wParam, IntPtr lParam, ref bool handled)
{
    // Handle messages passed to the visual.
    switch (message)
    {
        // Handle the left and right mouse button up messages.
        case WM_LBUTTONUP:
        case WM_RBUTTONUP:
            System.Windows.Point pt = new System.Windows.Point();
            pt.X = (uint)lParam & (uint)0x0000ffff;  // LOWORD = x
            pt.Y = (uint)lParam >> 16;               // HIWORD = y
            MyShape.OnHitTest(pt, message);
            break;
    }

    return IntPtr.Zero;
}
```

下面的示例演示如何设置命中测试来响应捕获特定的鼠标事件。

```csharp
// Constant values from the "winuser.h" header file.
public const int WM_LBUTTONUP = 0x0202,
                 WM_RBUTTONUP = 0x0205;

// Respond to WM_LBUTTONUP or WM_RBUTTONUP messages by determining which visual object was clicked.
public static void OnHitTest(System.Windows.Point pt, int msg)
{
    // Clear the contents of the list used for hit test results.
    hitResultsList.Clear();

    // Determine whether to change the color of the circle or to delete the shape.
    if (msg == WM_LBUTTONUP)
    {
        MyWindow.changeColor = true;
    }
    if (msg == WM_RBUTTONUP)
    {
        MyWindow.changeColor = false;
    }

    // Set up a callback to receive the hit test results enumeration.
    VisualTreeHelper.HitTest(MyWindow.myHwndSource.RootVisual,
                             null,
                             new HitTestResultCallback(CircleHitTestResult),
                             new PointHitTestParameters(pt));

    // Perform actions on the hit test results list.
    if (hitResultsList.Count > 0)
    {
        ProcessHitTestResultsList();
    }
}
```

[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)对象表示Windows Presentation Foundation (WPF)中的内容Win32窗口。 值[RootVisual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource.rootvisual)属性的[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)对象都表示可视化树层次结构中的最顶层节点。

有关使用 Win32 宿主容器对象时进行命中测试的完整示例，请参阅[使用 Win32 互操作示例命中测试](https://go.microsoft.com/fwlink/?LinkID=159995)。

### [Render on a Per Frame Interval Using CompositionTarget](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-render-on-a-per-frame-interval-using-compositiontarget)

WPF 动画引擎提供了许多用于创建基于帧的动画的功能。 但是，在某些应用程序方案中，需要基于每个帧以更细的粒度控制呈现。 [CompositionTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.compositiontarget)对象提供了创建基于每帧回调的自定义动画的功能。

[CompositionTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.compositiontarget) 是一个静态类，表示其绘制你的应用程序的显示图面。 [Rendering](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.compositiontarget.rendering)绘制应用程序的场景每次都会引发事件。 呈现帧速率是指每秒绘制场景的次数。

> 有关完整的代码示例使用[CompositionTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.compositiontarget)，请参阅[使用 CompositionTarget 示例](https://go.microsoft.com/fwlink/?LinkID=160045)。

#### 示例

[Rendering](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.compositiontarget.rendering)事件中，会激发WPF渲染过程。 下面的示例演示如何注册[EventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.eventhandler)委托给静态[Rendering](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.compositiontarget.rendering)方法[CompositionTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.compositiontarget)。

```csharp
// Add an event handler to update canvas background color just before it is rendered.
CompositionTarget.Rendering += UpdateColor;
```

可以使用呈现事件处理程序方法来创建自定义绘图内容。 每帧调用一次此事件处理程序方法。 每次 WPF 将可视化树中的持久呈现数据封送到组合场景图中时，都会调用事件处理程序方法。 另外，如果对可视化树的更改强制更新组合场景图，也会调用事件处理程序方法。 请注意，计算布局后会调用事件处理程序方法。 但是，可以修改事件处理程序方法中的布局，这意味着在呈现之前将再计算一次布局。

下面的示例演示如何提供自定义绘图[CompositionTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.compositiontarget)事件处理程序方法。 在此情况下，背景色的[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)使用颜色值基于鼠标的坐标位置绘制。 如果在将鼠标移动[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)，将其背景颜色更改。 另外，将基于当前的运行时间和所呈现的帧总数来计算平均帧速率。

```csharp
// Called just before frame is rendered to allow custom drawing.
protected void UpdateColor(object sender, EventArgs e)
{
    if (_frameCounter++ == 0)
    {
        // Starting timing.
        _stopwatch.Start();
    }

    // Determine frame rate in fps (frames per second).
    long frameRate = (long)(_frameCounter / this._stopwatch.Elapsed.TotalSeconds);
    if (frameRate > 0)
    {
        // Update elapsed time, number of frames, and frame rate.
        myStopwatchLabel.Content = _stopwatch.Elapsed.ToString();
        myFrameCounterLabel.Content = _frameCounter.ToString();
        myFrameRateLabel.Content = frameRate.ToString();
    }

    // Update the background of the canvas by converting MouseMove info to RGB info.
    byte redColor = (byte)(_pt.X / 3.0);
    byte blueColor = (byte)(_pt.Y / 2.0);
    myCanvas.Background = new SolidColorBrush(Color.FromRgb(redColor, 0x0, blueColor));
}
```

可能会发现自定义绘图在不同计算机上以不同的速度运行。 这是由于自定义绘图与帧速率有关。 具体取决于您运行的系统和该系统的工作负荷[Rendering](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.compositiontarget.rendering)事件不能调用不同数量的每秒的时间。 有关为运行 WPF 应用程序的设备确定图形硬件功能和性能的信息，请参阅[图形呈现层](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/graphics-rendering-tiers)。

添加或删除呈现[EventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.eventhandler)委托引发事件时将会延迟，直至完成事件后激发。 这是如何与一致[MulticastDelegate](https://docs.microsoft.com/zh-cn/dotnet/api/system.multicastdelegate)-基于的事件的处理在公共语言运行时 (CLR)。 另请注意，无法保证按照任何特定顺序来调用呈现事件。 如果有多个[EventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.eventhandler)委托依赖特定的顺序，则应注册一个[Rendering](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.compositiontarget.rendering)委托按正确顺序自己的事件和多路复用。