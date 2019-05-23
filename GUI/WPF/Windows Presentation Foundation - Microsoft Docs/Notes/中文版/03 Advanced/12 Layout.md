# [Layout](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/layout)

本主题介绍 Windows Presentation Foundation (WPF) 布局系统。 了解布局计算发生的方式和时间对于在 WPF 中创建用户界面非常重要。

本主题包含以下各节：

- [元素边界框](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/layout#LayoutSystem_BoundingBox)
- [布局系统](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/layout#LayoutSystem_Overview)
- [测量和排列子元素](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/layout#LayoutSystem_Measure_Arrange)
- [面板元素和自定义布局行为](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/layout#LayoutSystem_PanelsCustom)
- [布局性能注意事项](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/layout#LayoutSystem_Performance)
- [子像素渲染和布局舍入](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/layout#LayoutSystem_LayoutRounding)
- [后续步骤](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/layout#LayoutSystem_whatsnext)



## 元素边界框

在 WPF 中构思布局时，了解环绕所有元素的边界框非常重要。 每个[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)使用由布局系统可以认为的嵌入到布局矩形。 [LayoutInformation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.layoutinformation)类返回的元素布局分配或槽的边界。 通过计算可用屏幕空间、 任何约束、 特定于布局的属性 （如边距和填充） 和父的个别行为的大小来确定矩形的大小[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)元素。 处理此数据时，布局系统是否可以计算的所有子级的特定位置[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)。 务必要记住，大小调整特性定义父元素，如[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)，会影响其子级。

下图显示了一个简单的布局。

![未添加边界框的典型网格。](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/boundingbox1.png)

可以通过使用以下 XAML 实现此布局。

XAML复制

```xaml
<Grid Name="myGrid" Background="LightSteelBlue" Height="150">
  <Grid.ColumnDefinitions>
    <ColumnDefinition Width="250"/>
  </Grid.ColumnDefinitions>
  <Grid.RowDefinitions>
    <RowDefinition />
    <RowDefinition />
    <RowDefinition />
  </Grid.RowDefinitions>
  <TextBlock Name="txt1" Margin="5" FontSize="16" FontFamily="Verdana" Grid.Column="0" Grid.Row="0">Hello World!</TextBlock>
  <Button Click="getLayoutSlot1" Width="125" Height="25" Grid.Column="0" Grid.Row="1">Show Bounding Box</Button>
  <TextBlock Name="txt2" Grid.Column="1" Grid.Row="2"/>
</Grid>
```

将单个[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)内承载元素[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)。 而文本填充第一列，为分配的空间的左上角[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)实际上远大。 边界框的任何[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)可以通过使用来检索[GetLayoutSlot](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.layoutinformation.getlayoutslot)方法。 下图显示的边界框[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素。

![TextBlock 的边界框现在可见。](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/boundingbox2.png)

黄色矩形，为分配的空间所示[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素是实际上远大于显示。 其他元素添加到[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)，这种分配可以收缩或扩展，具体取决于类型和添加的元素的大小。

布局槽[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)转换成[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)通过使用[GetLayoutSlot](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.layoutinformation.getlayoutslot)方法。 此方法可用于显示元素的边界框。

C#复制

```csharp
private void getLayoutSlot1(object sender, System.Windows.RoutedEventArgs e)
{
    RectangleGeometry myRectangleGeometry = new RectangleGeometry();
    myRectangleGeometry.Rect = LayoutInformation.GetLayoutSlot(txt1);
    Path myPath = new Path();
    myPath.Data = myRectangleGeometry;
    myPath.Stroke = Brushes.LightGoldenrodYellow;
    myPath.StrokeThickness = 5;
    Grid.SetColumn(myPath, 0);
    Grid.SetRow(myPath, 0);
    myGrid.Children.Add(myPath);
    txt2.Text = "LayoutSlot is equal to " + LayoutInformation.GetLayoutSlot(txt1).ToString();
}
```



## 布局系统

简单地说，布局是一个递归系统，实现对元素进行大小调整、定位和绘制。 具体而言，布局描述测量和排列的成员的过程[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)元素的[Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.children)集合。 布局是一个密集的过程。 较大[Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.children)集合，必须进行计算的越多。 此外可以根据定义的布局行为引入复杂性[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)拥有该集合的元素。 相对简单[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)，如[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)，可以有更复杂性能明显优于[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)，如[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)。

每次子[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)改变其位置，它有可能触发一个新的布局系统传递。 因此，了解哪些事件会调用布局系统就很重要，因为不必要的调用可能导致应用程序性能变差。 下面描述调用布局系统时发生的过程。

1. 子[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)通过首先测量其核心属性来开始布局过程。
2. 大小调整属性上定义[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)计算，如[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)， [Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)，和[Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)。
3. [Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)-应用特定的逻辑，如[Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dock)方向或堆叠[Orientation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel.orientation)。
4. 测量所有子级后排列内容。
5. [Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.children)在屏幕上绘制集合。
6. 如果其他再次调用进程[Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.children)添加到集合中，[LayoutTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.layouttransform)应用，或[UpdateLayout](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.updatelayout)调用方法。

以下各节更详细地定义了此过程及其调用方式。



## 测量和排列子元素

布局系统的每个成员完成两个传递[Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.children)集合、 一个测量过程和排列处理过程。 每个子[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)提供其自己[MeasureOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.measureoverride)和[ArrangeOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.arrangeoverride)方法来实现其自己特定的布局行为。

在度量值通过的每个成员[Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.children)来评估集合。 通过调用会开始此过程[Measure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.measure)方法。 父级的实现中调用此方法[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)元素，并不需要的布局进行显式调用。

首先，本机大小属性[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)计算，如[Clip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.clip)和[Visibility](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.visibility)。 这将生成一个名为值`constraintSize`传递给[MeasureCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.measurecore)。

其次，在定义的框架属性[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)进行处理，这将影响的值`constraintSize`。 这些属性通常描述基础的大小调整特性[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)，如其[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)， [Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)， [Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)，和[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.style)。 其中每个属性都可以更改显示元素所需的空间。 [MeasureOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.measureoverride) 然后，调用`constraintSize`作为参数。

 备注

没有的属性之间的差异[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)并[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)并[ActualHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.actualheight)和[ActualWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.actualwidth)。 例如，[ActualHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.actualheight)属性是基于其他高度输入和布局系统的计算的值。 值由布局系统本身基于实际呈现的传递，设置，因此可能稍微小于属性的设置值如[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)，是作为输入更改的基础。

因为[ActualHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.actualheight)是计算后的值，应注意可能有多次或递增的报告更改为它作为各种操作结果由布局系统。布局系统可能会计算子元素所需的测量空间、父元素的约束等。

测量处理过程的最终目标是让子确定其[DesiredSize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.desiredsize)，就会出现此期间[MeasureCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.measurecore)调用。 [DesiredSize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.desiredsize)该值存储[Measure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.measure)以便在内容排列传递期间使用。

通过调用开始的排列处理过程[Arrange](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.arrange)方法。 期间的排列处理过程，父[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)元素生成一个表示子边界的矩形。 此值传递给[ArrangeCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.arrangecore)方法进行处理。

[ArrangeCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.arrangecore)方法将评估[DesiredSize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.desiredsize)子级的计算结果可能会影响该元素的呈现的大小的任何其他边距。[ArrangeCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.arrangecore) 将生成`arrangeSize`，它会传递给[ArrangeOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.arrangeoverride)方法的[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)作为参数。 [ArrangeOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.arrangeoverride) 生成`finalSize`的子级。 最后，[ArrangeCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.arrangecore)方法执行的最终计算的偏移量属性，如边距和对齐方式，并将子元素放在其布局槽内。 子元素不需要（并且通常不）填充整个分配空间。 然后将控件返回到父[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)和布局过程已完成。



## 面板元素和自定义布局行为

WPF 包括的一组派生的元素[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)。 这些[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)元素可实现许多复杂的布局。 例如，堆叠式元素可轻松实现通过使用[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)元素，而更复杂和自由流动的布局是可能使用[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)。

下表总结了可用布局[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)元素。

| 面板名称                                                     | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas) | 定义一个区域，在其中可以显式定位子元素的坐标相对于[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)区域。 |
| [DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel) | 定义一个区域，可在其中使子元素相互水平或垂直排列。           |
| [Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid) | 定义由列和行组成的灵活的网格区域。                           |
| [StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel) | 将子元素排列成水平或垂直的一行。                             |
| [VirtualizingPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingpanel) | 提供了一个框架，用于[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)虚拟化其子数据集合的元素。 这是一个抽象类。 |
| [WrapPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.wrappanel) | 按从左到右的顺序位置定位子元素，在包含框的边缘处将内容切换到下一行。 后续排序发生按顺序从上到下还是从右到左，具体取决于值[Orientation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.wrappanel.orientation)属性。 |

需要使用任意预定义不可能的布局的应用程序[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)元素，自定义布局行为可以通过继承自[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)并重写[MeasureOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.measureoverride)和[ArrangeOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.arrangeoverride)方法。 有关示例，请参阅[自定义径向面板示例](https://go.microsoft.com/fwlink/?LinkID=159982)。



## 布局性能注意事项

布局是一个递归过程。 在每个子元素[Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.children)集合在每次调用布局系统期间得到处理。 因此，应避免在不必要时触发布局系统。 以下注意事项有助于实现更好的性能。

- 应注意哪些属性值更改会强制执行布局系统的递归更新。

  如果依赖属性的值可能导致布局系统被初始化，则会使用公共标志对该依赖属性进行标记。 [AffectsMeasure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata.affectsmeasure)和[AffectsArrange](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata.affectsarrange)提供有关哪些属性值更改会强制执行递归的有用提示更新由布局系统。 一般情况下，可能会影响元素的边界框的大小的任何属性应具有[AffectsMeasure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata.affectsmeasure)标志设置为 true。 有关详细信息，请参阅[依赖项属性概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-properties-overview)。

- 如果可能，请使用[RenderTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransform)而不是[LayoutTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.layouttransform)。

  一个[LayoutTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.layouttransform)可以是非常有用的方式来影响的内容用户界面 (UI)。 但是，如果转换的效果不必影响其他元素的位置，它是使用[RenderTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransform)相反，因为[RenderTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransform)不会调用布局系统。[LayoutTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.layouttransform) 应用其转换和强制执行递归布局更新以受影响的元素的新位置。

- 避免不必要调用[UpdateLayout](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.updatelayout)。

  [UpdateLayout](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.updatelayout)方法强制执行递归布局更新，并经常是不必要。 除非你确定需要进行完整更新，否则请依赖布局系统为你调用此方法。

- 使用具有较大时[Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.children)集合，请考虑使用[VirtualizingStackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel)而不是正则表达式[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)。

  通过虚拟化其子集合，[VirtualizingStackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel)仅在当前父级的视区中的内存中保留对象。 因此，在大多数情况下，性能得到显著提高。



## 子像素渲染和布局舍入

WPF 图形系统使用与设备无关的单元来使分辨率和设备独立。 每个与设备无关的像素都会随着系统的 每英寸点数 (dpi) 设置自动进行缩放。 这为 WPF 应用程序提供了不同 dpi 设置的适当缩放，并使应用程序自动感知 dpi。

但是，这种 dpi 无关性可能由于抗锯齿而呈现出不规则的边缘。 这些伪影通常被视为模糊或半透明边缘，当边缘的位置落在设备像素的中间而不是设备像素之间时，就可能出现。 布局系统提供了一种通过布局倒圆对此进行调整的方法。 布局舍入是布局系统在布局传递中舍入任何非整数像素值的情况。

默认情况下禁用布局舍入。 若要启用布局舍入，请设置[UseLayoutRounding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.uselayoutrounding)属性设置为`true`任何[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)。 因为它是一个依赖属性，所以该值将传播到可视化树中的所有子级。 若要启用布局舍入为整个 UI，请设置[UseLayoutRounding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.uselayoutrounding)到`true`上根容器。 有关示例，请参见 [UseLayoutRounding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.uselayoutrounding)。



## 下一步

了解元素的测量和排列方式是了解布局的第一步。 有关可用的详细信息[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)元素，请参阅[面板概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/panels-overview)。 若要更好地了解可能影响布局的各种定位属性，请参阅[对齐、边距和填充概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/alignment-margins-and-padding-overview)。 有关自定义的示例[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)元素，请参阅[自定义径向面板示例](https://go.microsoft.com/fwlink/?LinkID=159982)。 当准备好将其全部放在轻型应用程序，请参阅[演练：我第一个 WPF 桌面应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/getting-started/walkthrough-my-first-wpf-desktop-application)。