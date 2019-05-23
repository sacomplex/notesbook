## [Panel](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/panel)

[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel) 是支持应用程序中的布局的所有元素的基类Windows Presentation Foundation (WPF)。

### [Panels Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/panels-overview)

[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel) 元素是控制呈现元素的组件，其大小和维度，其位置和子内容的排列方式。 Windows Presentation Foundation (WPF)提供了许多预定义[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)元素，以及构造自定义的功能[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)元素。

本主题包含以下各节：

- [Panel 类](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/panels-overview#Panels_view_from_10000_feet)
- [Panel 元素公共成员](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/panels-overview#Panels_declared_members)
- [派生 Panel 元素](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/panels-overview#Panels_derived_elements)
- [用户界面 Panel](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/panels-overview#Panels_main_UI_elements)
- [嵌套 Panel 元素](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/panels-overview#Panels_nested_panel_elements)
- [自定义 Panel 元素](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/panels-overview#Panels_custom_panel_elements)
- [本地化/全球化支持](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/panels-overview#Panels_global_localization)

#### Panel 类

[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel) 是类的基类，用于支持中的所有元素提供布局Windows Presentation Foundation (WPF)。 派生[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)元素用于放置和排列中的元素可扩展应用程序标记语言 (XAML)和代码。

WPF 包含一套全面的派生面板实现，可支持许多复杂的布局。 这些派生类公开可实现大部分标准 用户界面 (UI)方案的属性和方法。 开发人员找不到满足其需求的子排列行为可以通过重写创建新的布局[ArrangeOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.arrangeoverride)和[MeasureOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.measureoverride)方法。 有关自定义布局行为的详细信息，请参阅[自定义 Panel 元素](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/panels-overview#Panels_custom_panel_elements)。

#### Panel 公共成员

所有[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)元素支持大小和位置定义的属性的基[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)，其中包括[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)， [Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)，[HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.horizontalalignment)， [VerticalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.verticalalignment)， [Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)，和[LayoutTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.layouttransform)。 有关定义的位置属性的更多信息[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)，请参阅[Alignment、 Margin 和 Padding 概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/alignment-margins-and-padding-overview)。

[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel) 公开至关重要的一点是了解和使用布局中的其他的属性。 [Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.background)属性用于填充派生的面板元素使用的边界之间的区域[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)。 [Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.children) 表示元素的子集合的[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)组成。 [InternalChildren](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.internalchildren) 表示内容的[Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.children)集合以及通过数据绑定生成的成员。 同时组成[UIElementCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.uielementcollection)承载父项中的子元素[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)。

面板还公开[Panel.ZIndex](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.zindex)附加属性可用于实现在派生的分层的顺序[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)。 面板的成员[Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.children)集合具有较高[Panel.ZIndex](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.zindex)值显示在具有较低[Panel.ZIndex](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.zindex)值。 这是特别适合面板如[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)和[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)这使子级共享相同的坐标空间。

[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel) 此外定义了[OnRender](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.onrender)方法，可用于重写的默认呈现行为的[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)。

##### 附加属性

派生面板元素广泛使用附加属性。 附加属性是没有常规 公共语言运行时 (CLR) 属性“包装器”的依赖属性的特殊化形式。 附加属性在 可扩展应用程序标记语言 (XAML) 中具有特殊化的语法，可在后面的几个示例中看到。

附加属性的一个用途是允许子元素存储实际上由父元素定义的属性的唯一值。 此功能的一项应用是让子元素通知父级它们希望如何在 用户界面 (UI) 中呈现，这对应用程序布局非常有用。 有关详细信息，请参阅[附加属性概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/attached-properties-overview)。

#### 派生 Panel 元素

许多对象派生[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)，但不是所有这些旨在使用作为根布局提供程序。 有六个定义的面板类 ([Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)， [DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)， [Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)， [StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)， [VirtualizingStackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel)，并且[WrapPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.wrappanel))，专为创建应用程序UI。

每个面板元素都封装自己的特殊功能，如下表所示。

| 元素名称                                                     | 是否为 UI 面板？ | 描述                                                         |
| ------------------------------------------------------------ | ---------------- | ------------------------------------------------------------ |
| [Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas) | 是               | 定义一个区域，在其中可以显式定位子元素的坐标相对于[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)区域。 |
| [DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel) | 是               | 定义一个区域，可在其中使子元素相互水平或垂直排列。           |
| [Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid) | 是               | 定义一个由列和行组成的灵活网格区域。 子元素[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)可以精确地使用定位[Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)属性。 |
| [StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel) | 是               | 将子元素排列成水平或垂直的一行。                             |
| [TabPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.tabpanel) | 否               | 处理中的选项卡按钮的布局[TabControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tabcontrol)。 |
| [ToolBarOverflowPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.toolbaroverflowpanel) | 否               | 排列中的内容[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)控件。 |
| [UniformGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.uniformgrid) | 否               | [UniformGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.uniformgrid) 用于与所有相等的单元格大小排列在网格中的子级。 |
| [VirtualizingPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingpanel) | 否               | 为可以“虚拟化”其子级集合的面板提供基类。                     |
| [VirtualizingStackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel) | 是               | 在水平或垂直方向上将内容排列为一行并使其虚拟化。             |
| [WrapPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.wrappanel) | 是               | [WrapPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.wrappanel) 从顺序位置定位子元素的从左到右，将内容切换到下一行上包含框的边缘。 后续排序按照按顺序从上到下还是从右到左，具体取决于值[Orientation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.wrappanel.orientation)属性。 |



#### 用户界面 Panel

中提供了六个面板类WPF进行了优化以支持UI方案： [Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)， [DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)， [Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)， [StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)， [VirtualizingStackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel)，和[WrapPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.wrappanel)。 这些面板元素易于使用、功能齐全并且可扩展，足以适用于大多数应用程序。

每个派生[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)元素以不同方式处理大小调整约束。 了解如何[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)中水平或垂直方向的句柄约束可以使布局更可预测。

| **Panel 名称**                                               | **x 维度** | **y 维度**                                                   |
| ------------------------------------------------------------ | ---------- | ------------------------------------------------------------ |
| [Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas) | 按内容约束 | 按内容约束                                                   |
| [DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel) | 约束       | 约束                                                         |
| [StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel) （垂直方向） | 约束       | 按内容约束                                                   |
| [StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel) （水平方向） | 按内容约束 | 约束                                                         |
| [Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid) | 约束       | 在情况下的约束，除非其中[Auto](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.gridunittype#System_Windows_GridUnitType_Auto)适用于行和列 |
| [WrapPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.wrappanel) | 按内容约束 | 按内容约束                                                   |

可在下方找到其中每种元素的更多详细说明和使用示例。

##### Canvas

[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)元素允许的内容根据绝对定位*x 轴*并*y-* 坐标。 元素可以在唯一位置绘制；或者，如果元素占用了相同坐标，则这些元素在标记中显示的顺序决定它们的绘制顺序。

[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas) 提供最灵活布局支持的任何[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)。 Height 和 Width 属性用于定义在画布的区域和内部的元素分配相对于父区域的绝对坐标[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)。 四个附加的属性， [Canvas.Left](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas.left)， [Canvas.Top](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas.top)，[Canvas.Right](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas.right)并[Canvas.Bottom](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas.bottom)，允许内的对象放置进行精细控制[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)，允许开发人员放置和排列在屏幕上精确的元素。

###### Canvas 内 ClipToBounds

[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas) 可在屏幕上，即使在坐标位于其自己定义之外的任何位置定位子元素[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)和[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)。 此外，[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)不受其子级的大小。 因此，很可能要过度绘制父级的边框之外的其他元素的子元素[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)。 默认行为[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)是允许的父边界外绘制子级[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)。 如果不需要，此行为[ClipToBounds](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.cliptobounds)属性可以设置为`true`。 这将导致[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)向剪辑到其自身的大小。 [Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas) 是唯一的布局元素，允许其边界外绘制子级。

[宽度属性比较示例](https://go.microsoft.com/fwlink/?LinkID=160050)中以图形方式展示了此行为。

###### 定义和使用 Canvas

一个[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)可以只需通过使用实例化可扩展应用程序标记语言 (XAML)或代码。 下面的示例演示如何使用[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)以绝对方式定位内容。 此代码生成三个 100 像素正方形。 第一个正方形为红色，其左上角的 (*x, y*) 位置指定为 (0, 0)。 第二个正方形为绿色，其左上角位置为 (100, 100)，在第一个正方形的右下方。 第三个正方形为蓝色，其左上角为 (50, 50)，因此包含了第一个正方形的右下四分之一部分和第二个正方形的左上四分之一部分。 由于第三个正方形最后布置，因此它看起来在另外两个正方形上方，即，重叠部分采用第三个正方形的颜色。

```csharp
// Create the application's main window
mainWindow = new Window ();
mainWindow.Title = "Canvas Sample";

// Create the Canvas
myParentCanvas = new Canvas();
myParentCanvas.Width = 400;
myParentCanvas.Height = 400;

// Define child Canvas elements
myCanvas1 = new Canvas();
myCanvas1.Background = Brushes.Red;
myCanvas1.Height = 100;
myCanvas1.Width = 100;
Canvas.SetTop(myCanvas1, 0);
Canvas.SetLeft(myCanvas1, 0);

myCanvas2 = new Canvas();
myCanvas2.Background = Brushes.Green;
myCanvas2.Height = 100;
myCanvas2.Width = 100;
Canvas.SetTop(myCanvas2, 100);
Canvas.SetLeft(myCanvas2, 100);

myCanvas3 = new Canvas();
myCanvas3.Background = Brushes.Blue;
myCanvas3.Height = 100;
myCanvas3.Width = 100;
Canvas.SetTop(myCanvas3, 50);
Canvas.SetLeft(myCanvas3, 50);

// Add child elements to the Canvas' Children collection
myParentCanvas.Children.Add(myCanvas1);
myParentCanvas.Children.Add(myCanvas2);
myParentCanvas.Children.Add(myCanvas3);
           
// Add the parent Canvas as the Content of the Window Object
mainWindow.Content = myParentCanvas;
mainWindow.Show ();
```

XAML复制

```xaml
<Page WindowTitle="Canvas Sample" xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation">
  <Canvas Height="400" Width="400">
    <Canvas Height="100" Width="100" Top="0" Left="0" Background="Red"/>
    <Canvas Height="100" Width="100" Top="100" Left="100" Background="Green"/>
    <Canvas Height="100" Width="100" Top="50" Left="50" Background="Blue"/>
  </Canvas>
</Page>
```

经编译的应用程序产生新的 UI，外观如下。

![典型的 Canvas 元素。](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/panel-intro-canvas.png)



##### DockPanel

[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)元素使用[DockPanel.Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.dock)子内容元素来定位内容沿容器的边缘中设置附加属性。 当[DockPanel.Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.dock)设置为[Top](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dock#System_Windows_Controls_Dock_Top)或[Bottom](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dock#System_Windows_Controls_Dock_Bottom)，它将子元素的上方或下方相互定位。 当[DockPanel.Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.dock)设置为[Left](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dock#System_Windows_Controls_Dock_Left)或[Right](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dock#System_Windows_Controls_Dock_Right)，它将定位到左侧或右侧的每个其他子元素。 [LastChildFill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.lastchildfill)属性确定作为子级添加的最后一个元素的位置[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)。

可以使用[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)定位一组相关控件，如一组按钮。 或者，可以使用它创建“平移”的 UI，类似于 Microsoft Outlook 中的 UI。

###### 按内容调整大小

如果其[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)并[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)未指定属性，[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)其内容的大小。 大小可以增大或减小以容纳其子元素的大小。 但是，当已指定这些属性，并且不再为下一步指定的子元素，留出空间[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)不显示该子元素或后续子元素，且不测量后续子元素。

###### LastChildFill

默认情况下的最后一个子级[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)元素将"填充"剩余的未分配空间。 如果不需要此行为，请设置[LastChildFill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.lastchildfill)属性设置为`false`。

###### 定义和使用 DockPanel

下面的示例演示如何进行分区的空间使用[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)。 五[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)元素添加为父级的子级[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)。 每个使用不同的位置属性来[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)对空间进行分区。 最后一个元素"填充"剩余的未分配空间。

```csharp
// Create the application's main window
mainWindow = new Window ();
mainWindow.Title = "DockPanel Sample";

// Create the DockPanel
DockPanel myDockPanel = new DockPanel();
myDockPanel.LastChildFill = true;

// Define the child content
Border myBorder1 = new Border();
myBorder1.Height = 25;
myBorder1.Background = Brushes.SkyBlue;
myBorder1.BorderBrush = Brushes.Black;
myBorder1.BorderThickness = new Thickness(1);
DockPanel.SetDock(myBorder1, Dock.Top);
TextBlock myTextBlock1 = new TextBlock();
myTextBlock1.Foreground = Brushes.Black;
myTextBlock1.Text = "Dock = Top";
myBorder1.Child = myTextBlock1;

Border myBorder2 = new Border();
myBorder2.Height = 25;
myBorder2.Background = Brushes.SkyBlue;
myBorder2.BorderBrush = Brushes.Black;
myBorder2.BorderThickness = new Thickness(1);
DockPanel.SetDock(myBorder2, Dock.Top);
TextBlock myTextBlock2 = new TextBlock();
myTextBlock2.Foreground = Brushes.Black;
myTextBlock2.Text = "Dock = Top";
myBorder2.Child = myTextBlock2;

Border myBorder3 = new Border();
myBorder3.Height = 25;
myBorder3.Background = Brushes.LemonChiffon;
myBorder3.BorderBrush = Brushes.Black;
myBorder3.BorderThickness = new Thickness(1);
DockPanel.SetDock(myBorder3, Dock.Bottom);
TextBlock myTextBlock3 = new TextBlock();
myTextBlock3.Foreground = Brushes.Black;
myTextBlock3.Text = "Dock = Bottom";
myBorder3.Child = myTextBlock3;

Border myBorder4 = new Border();
myBorder4.Width = 200;
myBorder4.Background = Brushes.PaleGreen;
myBorder4.BorderBrush = Brushes.Black;
myBorder4.BorderThickness = new Thickness(1);
DockPanel.SetDock(myBorder4, Dock.Left);
TextBlock myTextBlock4 = new TextBlock();
myTextBlock4.Foreground = Brushes.Black;
myTextBlock4.Text = "Dock = Left";
myBorder4.Child = myTextBlock4;

Border myBorder5 = new Border();
myBorder5.Background = Brushes.White;
myBorder5.BorderBrush = Brushes.Black;
myBorder5.BorderThickness = new Thickness(1);
TextBlock myTextBlock5 = new TextBlock();
myTextBlock5.Foreground = Brushes.Black;
myTextBlock5.Text = "This content will Fill the remaining space";
myBorder5.Child = myTextBlock5;


// Add child elements to the DockPanel Children collection
myDockPanel.Children.Add(myBorder1);
myDockPanel.Children.Add(myBorder2);
myDockPanel.Children.Add(myBorder3);
myDockPanel.Children.Add(myBorder4);
myDockPanel.Children.Add(myBorder5);
           
// Add the parent Canvas as the Content of the Window Object
mainWindow.Content = myDockPanel;
mainWindow.Show ();
```

XAML复制

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation" WindowTitle="DockPanel Sample">
  <DockPanel LastChildFill="True">
    <Border Height="25" Background="SkyBlue" BorderBrush="Black" BorderThickness="1" DockPanel.Dock="Top">
      <TextBlock Foreground="Black">Dock = "Top"</TextBlock>
    </Border>
    <Border Height="25" Background="SkyBlue" BorderBrush="Black" BorderThickness="1" DockPanel.Dock="Top">
      <TextBlock Foreground="Black">Dock = "Top"</TextBlock>
    </Border>
    <Border Height="25" Background="LemonChiffon" BorderBrush="Black" BorderThickness="1" DockPanel.Dock="Bottom">
      <TextBlock Foreground="Black">Dock = "Bottom"</TextBlock>
    </Border>
    <Border Width="200" Background="PaleGreen" BorderBrush="Black" BorderThickness="1" DockPanel.Dock="Left">
      <TextBlock Foreground="Black">Dock = "Left"</TextBlock>
    </Border>
    <Border Background="White" BorderBrush="Black" BorderThickness="1">
      <TextBlock Foreground="Black">This content will "Fill" the remaining space</TextBlock>
    </Border>
  </DockPanel>
</Page>
```

经编译的应用程序产生新的 UI，外观如下。

![典型的 DockPanel 方案。](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/panel-intro-dockpanel.png)



##### Grid

[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素合并绝对定位和表格数据控件的功能。 一个[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)使你能够轻松地位置和样式元素。 [Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid) 允许你定义灵活的行和列分组，并甚至还提供了一种机制来共享大小调整信息之间多[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素。

###### 网格与表格有何不同？

[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table) 和[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)共享某些通用功能，但每个都是最适用于不同的方案。 一个[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)专为流内容内使用 (请参阅[流文档概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/flow-document-overview)有关流内容的详细信息)。 网格最适合在表单内（主要在流内容以外的任意位置）使用。 内[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)，[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)支持流内容行为，如分页、 列重排和内容时选择[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)却没有。 一个[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)另一方面最好使用之外[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)包括的原因有很多[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)根据行和列索引添加元素[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)却没有。 [Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素可对子内容，从而允许多个元素共存于单个"单元格。"内进行分层 [Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table) 不支持分层。 子元素的[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)相对于其"单元格"边界区域进行绝对定位。 [Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table) 不支持此功能。 最后，[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)比更轻[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)。

###### 列和行的大小调整行为

列和行中定义[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)可以充分利用[Star](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.gridunittype#System_Windows_GridUnitType_Star)为了按比例分配剩余空间大小调整。 当[Star](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.gridunittype#System_Windows_GridUnitType_Star)被选为的高度或宽度的行或列，该列或行将收到剩余的可用空间的加权的比例。 这是与[Auto](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.gridunittype#System_Windows_GridUnitType_Auto)，这会将分发均匀地根据中的列或行的内容的大小的空间。 在使用 可扩展应用程序标记语言 (XAML) 时，此值以 `*` 或 `2*` 的形式表示。 在第一种情况下，行或列将得到一倍的可用空间，在第二种情况下，将得到两倍的可用空间，依此类推。 通过将此技术来按比例分配空间的组合[HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.horizontalalignment)并[VerticalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.verticalalignment)的值`Stretch`是可能的布局空间分区的屏幕空间的百分比。 [Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid) 是唯一的布局面板，可以将分发在这种方式中的空间。

###### 定义和使用 Grid

以下示例演示如何生成 UI，该 UI 类似于 Windows“开始”菜单上提供的“运行”对话框上的 UI。

```csharp
// Create the Grid.
grid1 = new Grid ();
grid1.Background = Brushes.Gainsboro;
grid1.HorizontalAlignment = HorizontalAlignment.Left;
grid1.VerticalAlignment = VerticalAlignment.Top;
grid1.ShowGridLines = true;
grid1.Width = 425;
grid1.Height = 165;

// Define the Columns.
colDef1 = new ColumnDefinition();
colDef1.Width = new GridLength(1, GridUnitType.Auto);
colDef2 = new ColumnDefinition();
colDef2.Width = new GridLength(1, GridUnitType.Star);
colDef3 = new ColumnDefinition();
colDef3.Width = new GridLength(1, GridUnitType.Star);
colDef4 = new ColumnDefinition();
colDef4.Width = new GridLength(1, GridUnitType.Star);
colDef5 = new ColumnDefinition();
colDef5.Width = new GridLength(1, GridUnitType.Star);
grid1.ColumnDefinitions.Add(colDef1);
grid1.ColumnDefinitions.Add(colDef2);
grid1.ColumnDefinitions.Add(colDef3);
grid1.ColumnDefinitions.Add(colDef4);
grid1.ColumnDefinitions.Add(colDef5);

// Define the Rows.
rowDef1 = new RowDefinition();
rowDef1.Height = new GridLength(1, GridUnitType.Auto);
rowDef2 = new RowDefinition();
rowDef2.Height = new GridLength(1, GridUnitType.Auto);
rowDef3 = new RowDefinition();
rowDef3.Height = new GridLength(1, GridUnitType.Star);
rowDef4 = new RowDefinition();
rowDef4.Height = new GridLength(1, GridUnitType.Auto);
grid1.RowDefinitions.Add(rowDef1);
grid1.RowDefinitions.Add(rowDef2);
grid1.RowDefinitions.Add(rowDef3);
grid1.RowDefinitions.Add(rowDef4);

// Add the Image.
img1 = new Image();
img1.Source = new System.Windows.Media.Imaging.BitmapImage(new Uri("runicon.png", UriKind.Relative));
Grid.SetRow(img1, 0);
Grid.SetColumn(img1, 0);

// Add the main application dialog.
txt1 = new TextBlock();
txt1.Text = "Type the name of a program, folder, document, or Internet resource, and Windows will open it for you.";
txt1.TextWrapping = TextWrapping.Wrap;
Grid.SetColumnSpan(txt1, 4);
Grid.SetRow(txt1, 0);
Grid.SetColumn(txt1, 1);

// Add the second text cell to the Grid.
txt2 = new TextBlock();
txt2.Text = "Open:";
Grid.SetRow(txt2, 1);
Grid.SetColumn(txt2, 0);

// Add the TextBox control.
tb1 = new TextBox();
Grid.SetRow(tb1, 1);
Grid.SetColumn(tb1, 1);
Grid.SetColumnSpan(tb1, 5);

// Add the buttons.
button1 = new Button();
button2 = new Button();
button3 = new Button();
button1.Content = "OK";
button2.Content = "Cancel";
button3.Content = "Browse ...";
Grid.SetRow(button1, 3);
Grid.SetColumn(button1, 2);
button1.Margin = new Thickness(10, 0, 10, 15);
button2.Margin = new Thickness(10, 0, 10, 15);
button3.Margin = new Thickness(10, 0, 10, 15);
Grid.SetRow(button2, 3);
Grid.SetColumn(button2, 3);
Grid.SetRow(button3, 3);
Grid.SetColumn(button3, 4);

grid1.Children.Add(img1);
grid1.Children.Add(txt1);
grid1.Children.Add(txt2);
grid1.Children.Add(tb1);
grid1.Children.Add(button1);
grid1.Children.Add(button2);
grid1.Children.Add(button3);

mainWindow.Content = grid1;
```

经编译的应用程序产生新的 UI，外观如下。

![典型的 Grid 元素。](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/avalon-run-dialog.png)



##### StackPanel

一个[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)可以"堆叠"在指定方向的元素。 默认堆叠方向为垂直方向。 [Orientation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel.orientation)属性可用于控制内容流。

###### StackPanel 与 DockPanel

尽管[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)也可以"堆叠"子元素[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)和[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)不产生一些应用场景中的类似结果。 例如，子元素的顺序可能会影响在其大小[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)但不能在[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)。 这是因为[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)度量值中的堆叠在方向[PositiveInfinity](https://docs.microsoft.com/zh-cn/dotnet/api/system.double.positiveinfinity)，而[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)测量仅的可用大小。

以下示例演示此主要区别。

```csharp
// Create the application's main window
mainWindow = new Window ();
mainWindow.Title = "StackPanel vs. DockPanel";

// Add root Grid
myGrid = new Grid();
myGrid.Width = 175;
myGrid.Height = 150;
RowDefinition myRowDef1 = new RowDefinition();
RowDefinition myRowDef2 = new RowDefinition();
myGrid.RowDefinitions.Add(myRowDef1);
myGrid.RowDefinitions.Add(myRowDef2);

// Define the DockPanel
myDockPanel = new DockPanel();
Grid.SetRow(myDockPanel, 0);

//Define an Image and Source
Image myImage = new Image();
BitmapImage bi = new BitmapImage();
bi.BeginInit();
bi.UriSource = new Uri("smiley_stackpanel.png", UriKind.Relative);
bi.EndInit();
myImage.Source = bi;

Image myImage2 = new Image();
BitmapImage bi2 = new BitmapImage();
bi2.BeginInit();
bi2.UriSource = new Uri("smiley_stackpanel.png", UriKind.Relative);
bi2.EndInit();
myImage2.Source = bi2;

Image myImage3 = new Image();
BitmapImage bi3 = new BitmapImage();
bi3.BeginInit();
bi3.UriSource = new Uri("smiley_stackpanel.PNG", UriKind.Relative);
bi3.EndInit();
myImage3.Stretch = Stretch.Fill;
myImage3.Source = bi3;

// Add the images to the parent DockPanel
myDockPanel.Children.Add(myImage);
myDockPanel.Children.Add(myImage2);
myDockPanel.Children.Add(myImage3);

//Define a StackPanel
myStackPanel = new StackPanel();
myStackPanel.Orientation = Orientation.Horizontal;
Grid.SetRow(myStackPanel, 1);

Image myImage4 = new Image();
BitmapImage bi4 = new BitmapImage();
bi4.BeginInit();
bi4.UriSource = new Uri("smiley_stackpanel.png", UriKind.Relative);
bi4.EndInit();
myImage4.Source = bi4;

Image myImage5 = new Image();
BitmapImage bi5 = new BitmapImage();
bi5.BeginInit();
bi5.UriSource = new Uri("smiley_stackpanel.png", UriKind.Relative);
bi5.EndInit();
myImage5.Source = bi5;

Image myImage6 = new Image();
BitmapImage bi6 = new BitmapImage();
bi6.BeginInit();
bi6.UriSource = new Uri("smiley_stackpanel.PNG", UriKind.Relative);
bi6.EndInit();
myImage6.Stretch = Stretch.Fill;
myImage6.Source = bi6;

// Add the images to the parent StackPanel
myStackPanel.Children.Add(myImage4);
myStackPanel.Children.Add(myImage5);
myStackPanel.Children.Add(myImage6);

// Add the layout panels as children of the Grid
myGrid.Children.Add(myDockPanel);
myGrid.Children.Add(myStackPanel);

// Add the Grid as the Content of the Parent Window Object
mainWindow.Content = myGrid;
mainWindow.Show ();
```

XAML复制

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      WindowTitle="StackPanel vs. DockPanel">
  <Grid Width="175" Height="150">
    <Grid.ColumnDefinitions>
      <ColumnDefinition />
    </Grid.ColumnDefinitions>
    <Grid.RowDefinitions>
      <RowDefinition />
      <RowDefinition />
    </Grid.RowDefinitions>
    
    <DockPanel Grid.Column="0" Grid.Row="0">
      <Image Source="smiley_stackpanel.png" />
      <Image Source="smiley_stackpanel.png" />
      <Image Source="smiley_stackpanel.png" Stretch="Fill"/>
    </DockPanel>

    <StackPanel Grid.Column="0" Grid.Row="1"  Orientation="Horizontal">
      <Image Source="smiley_stackpanel.png" />
      <Image Source="smiley_stackpanel.png" />
      <Image Source="smiley_stackpanel.png" Stretch="Fill"/>
    </StackPanel>
    </Grid>
</Page>
```

通过此图像可以看到呈现行为的区别。

![屏幕快照：StackPanel 与 DockPanel 屏幕截图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/layout-smiley-stackpanel.png)

###### 定义和使用 StackPanel

下面的示例演示如何使用[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)创建一组垂直定位的按钮。 对于水平定位，设置[Orientation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel.orientation)属性设置为[Horizontal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.orientation#System_Windows_Controls_Orientation_Horizontal)。

```csharp
  // Create the application's main window
  mainWindow = new Window ();
  mainWindow.Title = "StackPanel Sample";

  // Define the StackPanel
  myStackPanel = new StackPanel();
  myStackPanel.HorizontalAlignment = HorizontalAlignment.Left;
  myStackPanel.VerticalAlignment = VerticalAlignment.Top;

  // Define child content
  Button myButton1 = new Button();
  myButton1.Content = "Button 1";
  Button myButton2 = new Button();
  myButton2.Content = "Button 2";
  Button myButton3 = new Button();
  myButton3.Content = "Button 3";

  // Add child elements to the parent StackPanel
  myStackPanel.Children.Add(myButton1);
  myStackPanel.Children.Add(myButton2);
  myStackPanel.Children.Add(myButton3);           

  // Add the StackPanel as the Content of the Parent Window Object
  mainWindow.Content = myStackPanel;
  mainWindow.Show ();
```

经编译的应用程序产生新的 UI，外观如下。

![典型的 StackPanel 元素。](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/panel-intro-stackpanel.png)

###### VirtualizingStackPanel

WPF 此外提供了一种变体的[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)自动"虚拟化"数据绑定子级内容的元素。 在此上下文中，“虚拟化”一词指的是一种技术：通过此技术根据屏幕上哪些项可见，从较多的数据项中生成一个元素子集。 如果在指定时刻只有少量 UI 元素位于屏幕上，则此时生成大量 UI 元素需要占用大量内存和处理器。 [VirtualizingStackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel) (通过提供的功能[VirtualizingPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingpanel)) 计算可见项，并处理[ItemContainerGenerator](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemcontainergenerator)从[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)(如[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)或[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)) 仅创建为可见项的元素。

[VirtualizingStackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel)元素会自动设置为承载的项控件如[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)。 当承载数据绑定集合时，内容自动虚拟化，只要内容的边界内[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)。 在承载许多子项时，这将大幅提高性能。

以下标记演示如何使用[VirtualizingStackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel)作为项宿主。 [VirtualizingStackPanel.IsVirtualizingProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel.isvirtualizingproperty)附加的属性必须设置为`true`（默认值） 才能进行虚拟化。

```xaml
<StackPanel DataContext="{Binding Source={StaticResource Leagues}}">
    <TextBlock Text="{Binding XPath=@name}" FontFamily="Arial" FontSize="18" Foreground="Black"/>
        <ListBox VirtualizingStackPanel.IsVirtualizing="True" 
                 ItemsSource="{Binding XPath=Team}" 
                 ItemTemplate="{DynamicResource NameDataStyle}"/>      
</StackPanel>
```

##### WrapPanel

[WrapPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.wrappanel) 用于从左到右，将内容切换到下一步的行时到达其父容器边缘的顺序位置定位子元素。 内容可以设置为水平或垂直方向。 [WrapPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.wrappanel) 可用于简单流用户界面 (UI)方案。 它还可以用来将统一大小调整应用于其所有子元素。

下面的示例演示如何创建[WrapPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.wrappanel)以显示[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)当到达容器边缘时换行的控件。

```csharp
// Create the application's main window
mainWindow = new System.Windows.Window();
mainWindow.Title = "WrapPanel Sample";


// Instantiate a new WrapPanel and set properties
myWrapPanel = new WrapPanel();
myWrapPanel.Background = System.Windows.Media.Brushes.Azure;
myWrapPanel.Orientation = Orientation.Horizontal;
myWrapPanel.Width = 200;
myWrapPanel.HorizontalAlignment = HorizontalAlignment.Left;
myWrapPanel.VerticalAlignment = VerticalAlignment.Top;

// Define 3 button elements. The last three buttons are sized at width 
// of 75, so the forth button wraps to the next line.
btn1 = new Button();
btn1.Content = "Button 1";
btn1.Width = 200;
btn2 = new Button();
btn2.Content = "Button 2";
btn2.Width = 75;
btn3 = new Button();
btn3.Content = "Button 3";
btn3.Width = 75;
btn4 = new Button();
btn4.Content = "Button 4";
btn4.Width = 75;

// Add the buttons to the parent WrapPanel using the Children.Add method.
myWrapPanel.Children.Add(btn1);
myWrapPanel.Children.Add(btn2);
myWrapPanel.Children.Add(btn3);
myWrapPanel.Children.Add(btn4);

// Add the WrapPanel to the MainWindow as Content
mainWindow.Content = myWrapPanel;
mainWindow.Show();
```

XAML复制

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation" WindowTitle="WrapPanel Sample">
  <Border HorizontalAlignment="Left" VerticalAlignment="Top" BorderBrush="Black" BorderThickness="2">
        <WrapPanel Background="LightBlue" Width="200" Height="100">
            <Button Width="200">Button 1</Button>
            <Button>Button 2</Button>
            <Button>Button 3</Button>
            <Button>Button 4</Button>
        </WrapPanel>
  </Border>    
</Page>
```

经编译的应用程序产生新的 UI，外观如下。

![典型 WrapPanel 元素。](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/wrappanel-element.png)



#### 嵌套 Panel 元素

[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel) 若要生成复杂的布局，可以相互嵌套元素。 这可以证明非常有用的一个[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)非常适合的一部分UI，但不是满足的其他部分需求UI。

对于应用程序可以支持的嵌套数量，并没有实际限制，但通常最好限制应用程序仅使用预期布局实际所需的面板。 在许多情况下，[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素可用来代替嵌套面板，因为它用作布局容器的灵活性。 这可以通过将不必要的元素排除在树以外来提高应用程序的性能。

下面的示例演示如何创建UI充分利用嵌套[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)元素，以实现特定的布局。 在此特定情况下[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)元素用于提供UI结构，而嵌套[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)元素， [Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)，和一个[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)用来定位子元素精确地在父级内的[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)。

```csharp
// Define the DockPanel.
myDockPanel = new DockPanel();

// Add the Left Docked StackPanel
Border myBorder2 = new Border();
myBorder2.BorderThickness = new Thickness(1);
myBorder2.BorderBrush = Brushes.Black;
DockPanel.SetDock(myBorder2, Dock.Left);
StackPanel myStackPanel = new StackPanel();
Button myButton1 = new Button();
myButton1.Content = "Left Docked";
myButton1.Margin = new Thickness(5);
Button myButton2 = new Button();
myButton2.Content = "StackPanel";
myButton2.Margin = new Thickness(5);
myStackPanel.Children.Add(myButton1);
myStackPanel.Children.Add(myButton2);
myBorder2.Child = myStackPanel;

// Add the Top Docked Grid.
Border myBorder3 = new Border();
myBorder3.BorderThickness = new Thickness(1);
myBorder3.BorderBrush = Brushes.Black;
DockPanel.SetDock(myBorder3, Dock.Top);
Grid myGrid = new Grid();
myGrid.ShowGridLines = true;
RowDefinition myRowDef1 = new RowDefinition();
RowDefinition myRowDef2 = new RowDefinition();
ColumnDefinition myColDef1 = new ColumnDefinition();
ColumnDefinition myColDef2 = new ColumnDefinition();
ColumnDefinition myColDef3 = new ColumnDefinition();
myGrid.ColumnDefinitions.Add(myColDef1);
myGrid.ColumnDefinitions.Add(myColDef2);
myGrid.ColumnDefinitions.Add(myColDef3);
myGrid.RowDefinitions.Add(myRowDef1);
myGrid.RowDefinitions.Add(myRowDef2);
TextBlock myTextBlock1 = new TextBlock();
myTextBlock1.FontSize = 20;
myTextBlock1.Margin = new Thickness(10);
myTextBlock1.Text = "Grid Element Docked at the Top";
Grid.SetRow(myTextBlock1, 0);
Grid.SetColumnSpan(myTextBlock1, 3);
Button myButton3 = new Button();
myButton3.Margin = new Thickness(5);
myButton3.Content = "A Row";
Grid.SetColumn(myButton3, 0);
Grid.SetRow(myButton3, 1);
Button myButton4 = new Button();
myButton4.Margin = new Thickness(5);
myButton4.Content = "of Button";
Grid.SetColumn(myButton4, 1);
Grid.SetRow(myButton4, 1);
Button myButton5 = new Button();
myButton5.Margin = new Thickness(5);
myButton5.Content = "Elements";
Grid.SetColumn(myButton5, 2);
Grid.SetRow(myButton5, 1);
myGrid.Children.Add(myTextBlock1);
myGrid.Children.Add(myButton3);
myGrid.Children.Add(myButton4);
myGrid.Children.Add(myButton5);
myBorder3.Child = myGrid;

// Add the Bottom Docked StackPanel.
Border myBorder4 = new Border();
myBorder4.BorderBrush = Brushes.Black;
myBorder4.BorderThickness = new Thickness(1);
DockPanel.SetDock(myBorder4, Dock.Bottom);
StackPanel myStackPanel2 = new StackPanel();
myStackPanel2.Orientation = Orientation.Horizontal;
TextBlock myTextBlock2 = new TextBlock();
myTextBlock2.Text = "This StackPanel is Docked to the Bottom";
myTextBlock2.Margin = new Thickness(5);
myStackPanel2.Children.Add(myTextBlock2);
myBorder4.Child = myStackPanel2;

// Add the Canvas, that fills remaining space.
Border myBorder5 = new Border();
myBorder4.BorderBrush = Brushes.Black;
myBorder5.BorderThickness = new Thickness(1);
Canvas myCanvas = new Canvas();
myCanvas.ClipToBounds = true;
TextBlock myTextBlock3 = new TextBlock();
myTextBlock3.Text = "Content in the Canvas will Fill the remaining space.";
Canvas.SetTop(myTextBlock3, 50);
Canvas.SetLeft(myTextBlock3, 50);
Ellipse myEllipse = new Ellipse();
myEllipse.Height = 100;
myEllipse.Width = 125;
myEllipse.Fill = Brushes.CornflowerBlue;
myEllipse.Stroke = Brushes.Aqua;
Canvas.SetTop(myEllipse, 100);
Canvas.SetLeft(myEllipse, 150);
myCanvas.Children.Add(myTextBlock3);
myCanvas.Children.Add(myEllipse);
myBorder5.Child = myCanvas;

// Add child elements to the parent DockPanel.
myDockPanel.Children.Add(myBorder2);
myDockPanel.Children.Add(myBorder3);
myDockPanel.Children.Add(myBorder4);
myDockPanel.Children.Add(myBorder5);
```

经编译的应用程序产生新的 UI，外观如下。

![充分利用嵌套面板的 UI。](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/nested-panels.png)



#### 自定义 Panel 元素

虽然WPF提供了一系列灵活的布局控件，也可以通过重写实现行为的自定义布局[ArrangeOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.arrangeoverride)和[MeasureOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.measureoverride)方法。 可以通过在这些重写方法内定义新的位置行为来实现自定义大小调整和位置。

同样，自定义布局行为基于派生类 (如[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)或[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)) 可以定义通过重写其[ArrangeOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.arrangeoverride)和[MeasureOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.measureoverride)方法。

以下标记演示如何创建自定义[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)元素。 这一新[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)，其定义如下`PlotPanel`，支持通过使用硬编码的子元素定位*x 轴*并*y-* 坐标。 在此示例中，[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)元素 （未显示） 都位于绘图点 50 (*x*)，到 50 个 (*y*)。

```csharp
public class PlotPanel : Panel
{
    // Default public constructor
    public PlotPanel()
        : base()
    {
    }

    // Override the default Measure method of Panel
    protected override Size MeasureOverride(Size availableSize)
    {
        Size panelDesiredSize = new Size();

        // In our example, we just have one child. 
        // Report that our panel requires just the size of its only child.
        foreach (UIElement child in InternalChildren)
        {
            child.Measure(availableSize);
            panelDesiredSize = child.DesiredSize;
        }

        return panelDesiredSize ;
    }
    protected override Size ArrangeOverride(Size finalSize)
    {
        foreach (UIElement child in InternalChildren)
        {
            double x = 50;
            double y = 50;

            child.Arrange(new Rect(new Point(x, y), child.DesiredSize));
        }
        return finalSize; // Returns the final Arranged size
    }
}
```

若要查看更复杂的自定义面板实现，请参阅[创建自定义内容换行面板示例](https://go.microsoft.com/fwlink/?LinkID=159979)。

#### 本地化/全球化支持

WPF 支持多种有助于创建可本地化的 UI 的功能。

所有面板元素本身都支持[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)属性，可用于动态地重排内容基于用户的区域设置或语言设置。 有关详细信息，请参阅 [FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)。

[SizeToContent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.sizetocontent)属性提供了一种机制，使应用程序开发人员要预测的需求本地化UI。 使用[WidthAndHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.sizetocontent#System_Windows_SizeToContent_WidthAndHeight)此属性，父值[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)始终动态调整大小以适应内容和不受人为的高度或宽度限制。

[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)，并[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)所有选择适合的可本地化UI。 [Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas) 但是，是不是一个不错的选择，因为其内容以绝对方式定位，使其难以本地化。

有关创建带有可本地化 用户界面 (UI) 的 WPF 应用程序的其他信息，请参阅[使用自动布局概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/use-automatic-layout-overview)。

### [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/panel-how-to-topics)

在本部分中的主题介绍如何使用[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)元素和相关API。

#### 本节内容

[如何： 向元素应用 LayoutTransform](https://msdn.microsoft.com/library/8221db67-d99f-4783-b65e-a6c5a52c03ab)
[创建自定义 Panel 元素](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-create-a-custom-panel-element)
[重写面板的 OnRender 方法](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-override-the-panel-onrender-method)
[设置元素的高度属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-set-the-height-properties-of-an-element)
[设置元素的宽度属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-set-the-width-properties-of-an-element)

#### [Create a Custom Panel Element](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-create-a-custom-panel-element)

此示例演示如何重写的默认布局行为[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)元素，并创建自定义布局元素派生自[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)。

该示例定义了一个简单的自定义[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)元素称为`PlotPanel`，其中定位子元素根据两个硬编码 x 坐标和 y 坐标。在此示例中，`x`并`y`都设置为`50`; 因此，所有子元素都放置在该位置上的 x 和 y 轴。

若要实现自定义[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)行为，该示例使用[MeasureOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.measureoverride)和[ArrangeOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.arrangeoverride)方法。 每个方法返回[Size](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.size)需要定位和呈现子元素的数据。

```csharp
public class PlotPanel : Panel
{
    // Default public constructor
    public PlotPanel()
        : base()
    {
    }

    // Override the default Measure method of Panel
    protected override Size MeasureOverride(Size availableSize)
    {
        Size panelDesiredSize = new Size();

        // In our example, we just have one child. 
        // Report that our panel requires just the size of its only child.
        foreach (UIElement child in InternalChildren)
        {
            child.Measure(availableSize);
            panelDesiredSize = child.DesiredSize;
        }

        return panelDesiredSize ;
    }
    protected override Size ArrangeOverride(Size finalSize)
    {
        foreach (UIElement child in InternalChildren)
        {
            double x = 50;
            double y = 50;

            child.Arrange(new Rect(new Point(x, y), child.DesiredSize));
        }
        return finalSize; // Returns the final Arranged size
    }
}
```

#### [Override the Panel OnRender Method](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-override-the-panel-onrender-method)

此示例演示如何重写[OnRender](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.onrender)方法的[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)以便将自定义图形效果添加到布局元素。

##### 示例

使用[OnRender](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.onrender)方法，以将图形效果添加到呈现的面板元素。 例如，可以使用此方法添加自定义边框或背景效果。 一个[DrawingContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingcontext)对象作为参数，它提供用于绘制形状、 文本、 图像或视频的方法传递。 因此，此方法很有用的面板对象自定义项。

```csharp
// Override the OnRender call to add a Background and Border to the OffSetPanel
protected override void OnRender(DrawingContext dc)
{
    SolidColorBrush mySolidColorBrush  = new SolidColorBrush();
    mySolidColorBrush.Color = Colors.LimeGreen;
    Pen myPen = new Pen(Brushes.Blue, 10);
    Rect myRect = new Rect(0, 0, 500, 500);
    dc.DrawRectangle(mySolidColorBrush, myPen, myRect);
}
```

#### [Set the Height Properties of an Element](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-set-the-height-properties-of-an-element)

此示例中直观地显示之间的四个高度相关的属性中的呈现行为差异Windows Presentation Foundation (WPF)。

[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)类公开描述的元素的高度特征的四个属性。 这四个属性可能会发生冲突，并且当他们这样做，将优先的值确定，如下所示：[MinHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.minheight)值将优先于[MaxHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.maxheight)值，后者又优先于[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)值。 第四个属性，[ActualHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.actualheight)，是只读的并将报告由与布局过程的交互的实际高度。

以下可扩展应用程序标记语言 (XAML)示例绘制[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)元素 (`rect1`) 的子级作为[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)。 可以更改的高度属性[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)通过使用一系列[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)表示的属性值的元素[MinHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.minheight)， [MaxHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.maxheight)，和[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)。 以这种方式，以可视化方式显示每个属性的优先级。

```xaml
<Canvas Height="200" MinWidth="200" Background="#b0c4de" VerticalAlignment="Top"  HorizontalAlignment="Center" Name="myCanvas" Margin="0,0,0,50">
    <Rectangle HorizontalAlignment="Center" Canvas.Top="50" Canvas.Left="50"  Name="rect1" Fill="#4682b4" Height="100" Width="100"/>
</Canvas>
```

```xaml
  <TextBlock Grid.Row="1" Grid.Column="0" Margin="10,0,0,0" TextWrapping="Wrap">Set the Rectangle Height:</TextBlock>
  <ListBox Grid.Column="1" Grid.Row="1" Margin="10,0,0,0" Height="50" Width="50" SelectionChanged="changeHeight">
    <ListBoxItem>25</ListBoxItem>
    <ListBoxItem>50</ListBoxItem>
    <ListBoxItem>75</ListBoxItem>
    <ListBoxItem>100</ListBoxItem>
    <ListBoxItem>125</ListBoxItem>
    <ListBoxItem>150</ListBoxItem>
    <ListBoxItem>175</ListBoxItem>
    <ListBoxItem>200</ListBoxItem>
  </ListBox>

  <TextBlock Grid.Row="1" Grid.Column="2" Margin="10,0,0,0" TextWrapping="Wrap">Set the Rectangle MinHeight:</TextBlock>
  <ListBox Grid.Column="3" Grid.Row="1" Margin="10,0,0,0" Height="50" Width="50" SelectionChanged="changeMinHeight">
    <ListBoxItem>25</ListBoxItem>
    <ListBoxItem>50</ListBoxItem>
    <ListBoxItem>75</ListBoxItem>
    <ListBoxItem>100</ListBoxItem>
    <ListBoxItem>125</ListBoxItem>
    <ListBoxItem>150</ListBoxItem>
    <ListBoxItem>175</ListBoxItem>
    <ListBoxItem>200</ListBoxItem>
</ListBox>      
   
  <TextBlock Grid.Row="1" Grid.Column="4" Margin="10,0,0,0" TextWrapping="Wrap">Set the Rectangle MaxHeight:</TextBlock>
  <ListBox Grid.Column="5" Grid.Row="1" Margin="10,0,0,0" Height="50" Width="50" SelectionChanged="changeMaxHeight">
    <ListBoxItem>25</ListBoxItem>
    <ListBoxItem>50</ListBoxItem>
    <ListBoxItem>75</ListBoxItem>
    <ListBoxItem>100</ListBoxItem>
    <ListBoxItem>125</ListBoxItem>
    <ListBoxItem>150</ListBoxItem>
    <ListBoxItem>175</ListBoxItem>
    <ListBoxItem>200</ListBoxItem> 
  </ListBox>
```

下面的代码隐藏示例处理事件的[SelectionChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.selector.selectionchanged)事件引发。 每个处理程序接受从输入[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)，将值作为分析[Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double)，并将值应用于指定高度相关的属性。 高度值也转换为字符串和写入到各种[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素 （这些元素的定义不在所选的 XAML 所示）。

```csharp
private void changeHeight(object sender, SelectionChangedEventArgs args)
{
    ListBoxItem li = ((sender as ListBox).SelectedItem as ListBoxItem);
    Double sz1 = Double.Parse(li.Content.ToString());
    rect1.Height = sz1;
    rect1.UpdateLayout();
    txt1.Text= "ActualHeight is set to " + rect1.ActualHeight;
    txt2.Text= "Height is set to " + rect1.Height;
    txt3.Text= "MinHeight is set to " + rect1.MinHeight;
    txt4.Text= "MaxHeight is set to " + rect1.MaxHeight;
}
private void changeMinHeight(object sender, SelectionChangedEventArgs args)
{
    ListBoxItem li = ((sender as ListBox).SelectedItem as ListBoxItem);
    Double sz1 = Double.Parse(li.Content.ToString());
    rect1.MinHeight = sz1;
    rect1.UpdateLayout();
    txt1.Text= "ActualHeight is set to " + rect1.ActualHeight;
    txt2.Text= "Height is set to " + rect1.Height;
    txt3.Text= "MinHeight is set to " + rect1.MinHeight;
    txt4.Text= "MaxHeight is set to " + rect1.MaxHeight;
}
private void changeMaxHeight(object sender, SelectionChangedEventArgs args)
{
    ListBoxItem li = ((sender as ListBox).SelectedItem as ListBoxItem);
    Double sz1 = Double.Parse(li.Content.ToString());
    rect1.MaxHeight = sz1;
    rect1.UpdateLayout();
    txt1.Text= "ActualHeight is set to " + rect1.ActualHeight;
    txt2.Text= "Height is set to " + rect1.Height;
    txt3.Text= "MinHeight is set to " + rect1.MinHeight;
    txt4.Text= "MaxHeight is set to " + rect1.MaxHeight;
}
```

#### [Set the Width Properties of an Element](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-set-the-width-properties-of-an-element)

此示例中直观地显示差异中的四个宽度相关属性之间的呈现行为Windows Presentation Foundation (WPF)。

[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)类公开描述的元素的宽度特征的四个属性。 这四个属性可能会发生冲突，并且当他们这样做，将优先的值确定，如下所示：[MinWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.minwidth)值将优先于[MaxWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.maxwidth)值，后者又优先于[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)值。 第四个属性，[ActualWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.actualwidth)，是只读的并将报告由与布局过程的交互的实际宽度。

以下可扩展应用程序标记语言 (XAML)示例绘制[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)元素 (`rect1`) 的子级作为[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)。 可以更改的宽度属性[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)通过使用一系列[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)表示的属性值的元素[MinWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.minwidth)， [MaxWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.maxwidth)，和[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)。 以这种方式，以可视化方式显示每个属性的优先级。

```xaml
<Canvas Height="200" MinWidth="200" Background="#b0c4de" VerticalAlignment="Top"  HorizontalAlignment="Center" Name="myCanvas">
    <Rectangle HorizontalAlignment="Center" Canvas.Top="50" Canvas.Left="50"  Name="rect1" Fill="#4682b4" Width="100" Height="100"/>
</Canvas>
```

```xaml
  <TextBlock Grid.Row="1" Grid.Column="0" Margin="10,0,0,0" TextWrapping="Wrap">Set the Rectangle Width:</TextBlock>
  <ListBox Grid.Column="1" Grid.Row="1" Margin="10,0,0,0" Width="50" Height="50" SelectionChanged="changeWidth">
    <ListBoxItem>25</ListBoxItem>
    <ListBoxItem>50</ListBoxItem>
    <ListBoxItem>75</ListBoxItem>
    <ListBoxItem>100</ListBoxItem>
    <ListBoxItem>125</ListBoxItem>
    <ListBoxItem>150</ListBoxItem>
    <ListBoxItem>175</ListBoxItem>
    <ListBoxItem>200</ListBoxItem>
    <ListBoxItem>225</ListBoxItem>
    <ListBoxItem>250</ListBoxItem>
  </ListBox>

  <TextBlock Grid.Row="1" Grid.Column="2" Margin="10,0,0,0" TextWrapping="Wrap">Set the Rectangle MinWidth:</TextBlock>
  <ListBox Grid.Column="3" Grid.Row="1" Margin="10,0,0,0" Width="50" Height="50" SelectionChanged="changeMinWidth">
    <ListBoxItem>25</ListBoxItem>
    <ListBoxItem>50</ListBoxItem>
    <ListBoxItem>75</ListBoxItem>
    <ListBoxItem>100</ListBoxItem>
    <ListBoxItem>125</ListBoxItem>
    <ListBoxItem>150</ListBoxItem>
    <ListBoxItem>175</ListBoxItem>
    <ListBoxItem>200</ListBoxItem>
    <ListBoxItem>225</ListBoxItem>
    <ListBoxItem>250</ListBoxItem>
</ListBox>      
   
  <TextBlock Grid.Row="1" Grid.Column="4" Margin="10,0,0,0" TextWrapping="Wrap">Set the Rectangle MaxWidth:</TextBlock>
  <ListBox Grid.Column="5" Grid.Row="1" Margin="10,0,0,0" Width="50" Height="50" SelectionChanged="changeMaxWidth">
    <ListBoxItem>25</ListBoxItem>
    <ListBoxItem>50</ListBoxItem>
    <ListBoxItem>75</ListBoxItem>
    <ListBoxItem>100</ListBoxItem>
    <ListBoxItem>125</ListBoxItem>
    <ListBoxItem>150</ListBoxItem>
    <ListBoxItem>175</ListBoxItem>
    <ListBoxItem>200</ListBoxItem>
    <ListBoxItem>225</ListBoxItem>
    <ListBoxItem>250</ListBoxItem>  
  </ListBox>
```

下面的代码隐藏示例处理事件的[SelectionChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.selector.selectionchanged)事件引发。 每个自定义方法将来自输入[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)，将值作为分析[Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double)，并将值应用于指定的宽度与相关属性。 宽度值也转换为字符串和写入到各种[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素 （这些元素的定义不在所选的 XAML 所示）。

```csharp
private void changeWidth(object sender, SelectionChangedEventArgs args)
{
    ListBoxItem li = ((sender as ListBox).SelectedItem as ListBoxItem);
    Double sz1 = Double.Parse(li.Content.ToString());
    rect1.Width = sz1;
    rect1.UpdateLayout();
    txt1.Text = "ActualWidth is set to " + rect1.ActualWidth;
    txt2.Text = "Width is set to " + rect1.Width;
    txt3.Text = "MinWidth is set to " + rect1.MinWidth;
    txt4.Text = "MaxWidth is set to " + rect1.MaxWidth;
}
private void changeMinWidth(object sender, SelectionChangedEventArgs args)
{
    ListBoxItem li = ((sender as ListBox).SelectedItem as ListBoxItem);
    Double sz1 = Double.Parse(li.Content.ToString());
    rect1.MinWidth = sz1;
    rect1.UpdateLayout();
    txt1.Text = "ActualWidth is set to " + rect1.ActualWidth;
    txt2.Text = "Width is set to " + rect1.Width;
    txt3.Text = "MinWidth is set to " + rect1.MinWidth;
    txt4.Text = "MaxWidth is set to " + rect1.MaxWidth;
}
private void changeMaxWidth(object sender, SelectionChangedEventArgs args)
{
    ListBoxItem li = ((sender as ListBox).SelectedItem as ListBoxItem);
    Double sz1 = Double.Parse(li.Content.ToString());
    rect1.MaxWidth = sz1;
    rect1.UpdateLayout();
    txt1.Text = "ActualWidth is set to " + rect1.ActualWidth;
    txt2.Text = "Width is set to " + rect1.Width;
    txt3.Text = "MinWidth is set to " + rect1.MinWidth;
    txt4.Text = "MaxWidth is set to " + rect1.MaxWidth;
}
```

有关完整示例，请参阅[宽度属性比较示例](https://go.microsoft.com/fwlink/?LinkID=160050)。