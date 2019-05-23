# [XAML Designer](https://docs.microsoft.com/en-us/visualstudio/designers/creating-a-ui-by-using-xaml-designer-in-visual-studio?view=vs-2019)

Visual Studio 中的 XAML 设计器提供可视化界面，有助于设计基于 XAML 的 Windows 和 Web 应用。 可以通过拖动“工具箱” 中的控件，并在“属性” 窗口设置属性，为应用程序创建用户界面。 还可以直接在 XAML 视图中编辑 XAML。

有关高级 XAML 设计任务（例如动画和行为）的详细信息，请参阅 [Creating a UI by using Blend for Visual Studio](https://docs.microsoft.com/zh-cn/visualstudio/designers/creating-a-ui-by-using-blend-for-visual-studio?view=vs-2019)。 另请参阅[在 Visual Studio 和 Blend for Visual Studio 中设计 XAML](https://docs.microsoft.com/zh-cn/visualstudio/designers/designing-xaml-in-visual-studio?view=vs-2019)，查看这两种工具之间的比较。

## XML 设计器工作区

XAML 设计器中的工作区由若干可视界面元素组成。 这些元素包括美工板、XAML 编辑器、“设备”窗口、“文档大纲”窗口和“属性”窗口。 若要打开 XAML 设计器，请右键单击“解决方案资源管理器” 中的 XAML 文件，然后选择“视图设计器” 。

## 创作视图

XAML 设计器提供 XAML 视图和应用程序呈现的 XAML 标记的同步设计视图。 打开 Visual Studio 中的某个 XAML 文件后，可以通过使用“设计” 和“XAML” 选项卡，在“设计”视图和“XAML”视图之间进行切换。 可以使用“交换窗格” 按钮，切换显示于顶部的窗口：美工板或 XAML 编辑器。

在“设计”视图，包括 *“美工板”* 的窗口是活动窗口，并且可以将其用作主要工作台面。 可通过添加或绘制元素，然后对其进行修改，在应用程序中用于直观地设计页面。 有关更多信息，请参见 [Working with elements in XAML Designer](https://docs.microsoft.com/zh-cn/visualstudio/designers/working-with-elements-in-xaml-designer?view=vs-2019)。 此图显示了“设计”视图中的美工板。

![XAML 设计器的设计视图](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/xaml_editor_design_view.png?view=vs-2019)

这些功能在美工板中可用：

**对齐线**

对齐线是显示为红色虚线的 *“对齐边界”* ，在控件的边缘对齐时或文本基线对齐时进行显示。 仅当启用了“对齐线对齐” 时，才会显示对齐边界。

**网格轨道**

使用`Grid` 轨道可以管理 [网格](https://docs.microsoft.com/zh-cn/uwp/api/Windows.UI.Xaml.Controls.Grid) 面板中的行和列。 可以创建和删除行和列，并可以调整其相对宽度和高度。 显示在美工板左侧的垂直网格轨道用于行，而显示在顶部的水平线则用于列。

**网格装饰器**

网格装饰器显示为三角形，在网格轨道上它附加有垂直线或水平线。 拖动网格装饰器时，相邻的列或行的宽度或高度随鼠标的移动而改变。

网格装饰器用于控制网格的行和列的宽度和高度。 可以通过单击网格轨道，添加新列或行。 当为具有两个或多个列或行的网格面板添加新行或列时，轨道外将显示一个小型工具栏，可显式设置宽度和高度。 小型工具栏使你能够为网格行和列设置调整大小选项。

**重设句柄大小**

重设句柄大小显示在所选控件上，使你能够调整控件的大小。 当调整控件大小时，通常会出现宽度和高度值，帮助设置控件的大小。 有关在“设计”视图中操作控件的详细信息，请参阅[使用 XAML 设计器中的元素](https://docs.microsoft.com/zh-cn/visualstudio/designers/working-with-elements-in-xaml-designer?view=vs-2019)。

**边距**

边距表示控件边缘与其容器边缘之间的固定空间量。 可使用“属性”窗口中 **“布局”** 下的 [Margin](https://docs.microsoft.com/zh-cn/uwp/api/windows.ui.xaml.frameworkelement.margin) 属性来设置控件的边距。

**边距装饰器**

可使用边距装饰器更改元素相对于其布局容器的边距。 打开边距装饰器，未设置边距时，边距装饰器将显示断开的锁链。 未设置边距时，元素在运行时调整布局容器的大小时保留在原处。 边距装饰器关闭时，边距装饰器将显示完好的锁链，且在运行时调整布局容器的大小时，元素随边距一起移动（边距保持固定）。

**元素句柄**

当将指针移动到环绕某元素的蓝色方框的角落时，可以通过使用显示于美工板上的元素句柄修改元素。 利用这些句柄可以旋转、调整大小、翻转、移动或向元素添加圆角半径。 元素句柄的符号因函数而异，且更具指针的确切位置进行更改。 如果看不到元素句柄，请确保已选定该元素。

在“设计”视图中，其他美工板命令在屏幕的左下角区域可用，如下所示：

![设计视图命令](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/xaml_editor_design_controls.png?view=vs-2019)

此工具栏上的这些命令可用：

**缩放**

缩放能够确定设计图面的大小。 可以从 12.5% 缩放到 800%，或选择如“适应所选内容” 和“适合所有” 之类的选项。

**显示/隐藏对齐网格**

显示或隐藏显示网格线的对齐网格。 当启用“网格线对齐”或“对齐线对齐”时，将使用网格线。

**开启/关闭网格线对齐**

如果“网格线对齐”已启用，在美工板上拖动某个元素后，此元素会与最靠近的水平和垂直网格线对齐。

**开启/关闭对齐线对齐**

对齐线有助于控件彼此对齐。 如果已启用了“对齐线对齐” ，则当相对于其他控件拖动某个控件时，在某些控件的边缘和文本水平或垂直对齐时，将显示对齐边界。 对齐边界显示为红色虚线。

在 XAML 视图中，包含 XAML 编辑器窗口是活动窗口，且 XAML 编辑器是主要创作工具。 可扩展应用程序标记语言 (XAML) 提供基于 XML 的声明性词汇，用于指定应用程序的用户界面。 XAML 视图包括 IntelliSense、自动格式设置、语法突出显示和标记导航。 此图显示了 XAML 视图：

![XAML 视图](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/xaml_editor.png?view=vs-2019)

**拆分视图栏**

当 XAML 编辑器在下方窗口时，拆分视图栏将显示在 XAML 视图中的顶部。 拆分视图栏可控制“设计”视图和 XAML 视图的相对大小。 也可交换视图的位置（使用“交换窗格” 按钮），指定视图是水平排列或是垂直排列以及折叠任一视图。

**标记缩放**

借助标记缩放，可以调整 XAML 视图的大小。 可以从 20% 缩放到 400%。

## 设备窗口

 备注

如果 UWP 应用程序的目标平台版本 (`TargetPlatformVersion`) 是 10.0.16299.0 或更高版本，则“设备”窗口不可用。

通过 XAML 设计器中的“设备”窗口，可在设计时为项目模拟各种视图、显示屏和显示选项。 在 XAML 设计器中工作时，“设备”窗口在“设计”菜单中可用。 如下所示：

![设备窗口](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/xaml_editor_device_panel.png?view=vs-2019)

以下是“设备”窗口中可用的选项：

**显示**

为应用程序指定不同的显示大小和分辨率。

**方向**

为应用程序指定不同的方向：“横向”或“纵向”。

**边缘**

为应用程序指定不同的边缘对齐方式：“两者”、“左对齐”、“右对齐”或“无”。

**高对比度**

以选定的对比度设置预览应用程序。 如果将此设置的值不是“默认值”，则重写 App.xaml 中的 `RequestedTheme` 属性设置。

**重写缩放**

在设计图面中开启和关闭文档缩放仿真。 这使你可以按系数提高缩放百分比。 选中该复选框，以开启仿真。 例如，如果缩放百分比为 100%，则设计图面中的文档将最大纵向扩展至 140%。 如果当前缩放百分比为 180，则将禁用此选项。

**最小宽度**

指定最小宽度设置。 最小宽度可在 App.xaml 中更改。

**主题**

指定应用程序主题。 例如，可以在“深色”和“浅色”主题之间进行切换。

**显示镶边**

在“设计”视图中，开启和关闭应用程序周围的模拟平板电脑框架。 选择该复选框，以显示帧。

**剪裁以显示**

指定显示模式。 选择此复选框，以将文档大小剪裁到显示屏大小。

## “文档大纲”窗口

XAML 设计器中的“文档大纲”窗口有助于执行这些任务：

- 查看美工板上所有元素的层次结构。
- 选择元素，以便可以对其进行修改（在层次结构中移动它们、在美工板上对其进行修改以及在“属性”窗口中设置其属性等）。 有关详细信息，请参阅[使用 XAML 设计器中的元素](https://docs.microsoft.com/zh-cn/visualstudio/designers/working-with-elements-in-xaml-designer?view=vs-2019)
- 创建和修改控件元素的模板。
- 使用选定元素的右键单击菜单（关联菜单）。 同一个菜单对美工板中的所选元素也可用。

若要查看“文档大纲”窗口，请依次在菜单栏上选择“查看” > “其他窗口” > “文档大纲”。

![“文档大纲”窗口](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/xaml_editor_doc_outline.png?view=vs-2019)

以下是“文档大纲”窗口中可用的选项：

**文档大纲**

“文档大纲”窗口中的主视图采用树结构显示文档的层次结构。 可以使用文档大纲的层次结构性质检查不同级别的文档的详细信息，单个或成组地锁定和隐藏元素。

**显示/隐藏**

显示或隐藏与文档大纲中项对应的美工板元素。 使用“显示/隐藏”按钮，该按钮显示时是一个眼睛状的标志，或者按 Ctrl+H 隐藏元素，按 Shift+Ctrl+H 显示元素。

**锁定/解锁**

锁定或解锁与“文档大纲”中各项相对应的美工板元素。 不能修改已锁定的元素。 使用“锁定/解锁”按钮，该按钮锁定时是一个挂锁状的标志，或按 Ctrl+L 锁定元素，按 Shift+Ctrl+L 解锁元素。

**返回到 pageRoot 范围**

“文档大纲”窗口顶部的选项显示向上箭头符号，可将文档大纲返回到之前的范围。 仅当在样式或模板的范围中时，范围向上可用。

## “属性”窗口

通过“属性”窗口可以设置控件的属性值。 如下所示：

![“属性”窗口](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/xaml_editor_prop_window.png?view=vs-2019)

“属性”窗口顶部有多种选项。 可以通过使用“名称” 框，更改当前所选元素的名称。 在左上角，有一个表示当前所选元素的图标。 若要按类别或按字母顺序排列属性，请单击“类别” 、“名称” 或“排列方式” 列表中的“源” 。 若要查看控件的事件列表，请单击“事件” 按钮，该按钮显示为一个闪电形符号。 若要搜索属性，请开始在“搜索属性” 框中键入属性的名称。 “属性”窗口将显示与键入搜索的内容相匹配的属性。 某些属性允许通过选择向下箭头按钮设置高级属性。 有关使用属性和处理事件的详细信息，请参阅[控件和模式简介](https://docs.microsoft.com/zh-cn/windows/uwp/design/controls-and-patterns/controls-and-events-intro)

每个属性值的右侧是一个“属性标记” ，显示为一个方框符号。 属性标记的外观指示是否有数据绑定到或有资源应用于该属性。 例如，白色方框符号指示默认值，黑色方框符号通常指示已应用某个本地资源，而橙色方框通常指示已应用某个数据绑定。 单击属性标记时，可以导航到一种样式的定义、打开数据绑定生成器或打开资源选取器。

## [Work with elements](https://docs.microsoft.com/en-us/visualstudio/designers/working-with-elements-in-xaml-designer?view=vs-2019)

可以使用 XAML 代码或 XAML 设计器向你的应用程序添加控件、布局和形状等元素。 本主题介绍如何在 Visual Studio 或 Blend for Visual Studio 中使用 XAML 设计器中的元素。

### 将元素添加到布局

布局是调整元素在 UI 中的大小和位置的过程。 若要放置可视元素，必须将这些元素置于布局[面板](https://docs.microsoft.com/zh-cn/uwp/api/Windows.UI.Xaml.Controls.Panel)中。 `Panel` 具有一个子属性，该子属性是 [FrameworkElement](https://docs.microsoft.com/zh-cn/uwp/api/Windows.UI.Xaml.FrameworkElement) 类型的集合。 可使用各种 `Panel` 子元素（如 [Canvas](https://docs.microsoft.com/zh-cn/uwp/api/Windows.UI.Xaml.Controls.Canvas)[StackPanel](https://docs.microsoft.com/zh-cn/uwp/api/Windows.UI.Xaml.Controls.StackPanel)和 [Grid](https://docs.microsoft.com/zh-cn/uwp/api/Windows.UI.Xaml.Controls.Grid)）来充当布局容器以及在页面上放置和排列元素。

默认情况下，`Grid` 面板用作页面或窗体中的顶级布局容器。 可以添加布局面板、控件或顶级页面布局中的其他元素。

若要将元素添加到 XAML 设计器中的布局，请执行以下操作之一：

- 双击“工具箱”的某个元素（或选择“工具箱”中的某个元素，然后按 Enter）。
- 将元素从“工具箱”拖到美工板 。
- 在“工具箱”中，选择一种绘制工具（例如，[椭圆形](https://docs.microsoft.com/zh-cn/uwp/api/Windows.UI.Xaml.Shapes.Ellipse)或[矩形](https://docs.microsoft.com/zh-cn/uwp/api/Windows.UI.Xaml.Shapes.Rectangle)），然后在活动面板上绘制元素。

### 更改元素的分层顺序

当 XAML 设计器中的美工板上有两个元素时，其中一个元素将以分层顺序显示于另一个元素之前。 文档大纲窗口中的元素列表底部是最靠前的元素（除了在设置了元素的 ZIndex 属性时）。 当将元素插入页面、窗体或布局容器时，元素将自动放置在活动容器元素中的其他元素之前。 若要更改元素的顺序，可使用“排序”命令，或将元素拖入文档大纲窗口的对象树中。

若要更改其分层顺序，请执行以下操作之一：

- 在“文档大纲”窗口中，向上或向下拖动元素，以创建所需的分层顺序。

- 右键单击文档大纲窗口中或美工板上想要更改其分层顺序的元素，指向“顺序”，然后单击以下选项之一：

  - “置于顶层”：将元素一直移动到顺序的顶层。
  - “上移一层”，使元素在顺序中上移一层。
  - “下移一层”，使元素在顺序中下移一层。
  - “置于底层”：将元素一直移到顺序的底层。

  更改属性窗口中“布局”部分的“ZIndex”属性。 对于重叠元素，“ZIndex”属性优先于文档大纲窗口中显示的元素的顺序。 当元素重叠时，“ZIndex”值较大的元素将显示在前面。

### 更改元素的对齐方式

可以通过使用菜单命令或通过将元素拖到对齐线，对齐美工板中的元素。

对齐线是一个视觉提示，有助于将某个元素相对于应用中的其他元素进行对齐。

使用菜单命令对齐两个或多个元素的步骤：

1. 选择想要对齐的元素。 可以通过按住 Ctrl 键的同时选择元素来选择多个元素。
2. 在属性窗口中“布局”部分的“HorizontalAlignment”下，选择以下属性之一：“左对齐”、“居中对齐”、“右对齐”或“拉伸对齐”。
3. 在属性窗口中“布局”部分的“VerticalAlignment”下，选择以下属性之一：“顶部对齐”、“居中对齐”、“底部对齐”或“拉伸对齐”。

若要使用对齐线对齐两个或多个元素，在 XAML 设计器中，在至少包含有两个元素的布局中拖动元素或调整一个元素的大小，以便其边缘与另一个元素对齐。

当边缘对齐时，将显示“对齐边界”以指示对齐方式。 对齐边界是红色的虚线。 仅当启用了“对齐线对齐” 时，才会显示对齐边界。 有关显示对齐边界的美工板图示，请参阅[使用 XAML 设计器创建 UI](https://docs.microsoft.com/zh-cn/visualstudio/designers/creating-a-ui-by-using-xaml-designer-in-visual-studio?view=vs-2019)。

### 更改元素的边距

XAML 设计器中的边距决定了美工板上元素周围的空白空间量。 例如，边距指定了元素外边缘与包含该元素的 `Grid` 面板的边界之间的空间量。 边距还指定包含于 `StackPanel` 中的元素之间的空间量。

在“属性”窗口中更改元素边距的步骤：

1. 选择想要更改边距的元素。
2. 在属性窗口中的“布局”下，更改任何“边距”属性（“顶部”、“左”、“右”或“底部”）的值（以像素为单位或与设备无关的单位，大约 1/96 英寸）。

在美工板中，若要更改元素相对于其布局容器的边距，请在元素处于选中状态且位于布局容器内时，单击元素周围出现的“边距装饰器”。 有关显示边距装饰器的图示，请参阅[使用 XAML 设计器创建 UI](https://docs.microsoft.com/zh-cn/visualstudio/designers/creating-a-ui-by-using-xaml-designer-in-visual-studio?view=vs-2019)。

如果边距装饰器已打开，呈垂直或水平时，则未设置该边距。 如果边距装饰器已关闭，则已设置该边距。

打开边距装饰器但未设置相反的边距时，将根据元素在美工板中的位置将相反的边距设置为正确的值。 对于相反的边距（如“左侧”和“右侧”边距），将始终至少设置一个属性。

 重要

置于某些布局容器中的元素（如 [Windows.UI.Xaml.Controls.Canvas](https://msdn.microsoft.com/en-us/library/windows.ui.xaml.controls.canvas(v=vs.140).aspx)）没有边距装饰器。 放置于 [Windows.UI.Xaml.Controls.StackPanel](https://msdn.microsoft.com/en-us/library/windows.ui.xaml.controls.stackpanel(v=vs.140).aspx) 中的元素有用于左边距和右边距或顶部和底部边距的边距装饰器，具体取决于 `StackPanel` 的方向。

### 将元素分组和取消分组

对 XAML 设计器中的两个或多个元素进行分组，可创建新的布局容器，并将这些元素置于该容器中。 将两个或多个元素一起置于一个布局容器，让你可轻松地选择、移动和转换组，似乎该组中的元素是一个元素一样。 分组在某种程度上对于标识彼此相关的元素也很有用，如组成导航元素的按钮。 当对元素进行取消分组时，只需删除包含这些元素的布局容器。

将元素分组到一个新布局容器的步骤：

1. 选择想要分组的元素。 （若要选择多个元素，请在按住 Ctrl 键的同时单击这些元素。）

2. 右键单击选定的元素，指向“分组”，然后单击想要在其中放置该组的布局容器的类型。

    提示

   如果选择 [Windows.UI.Xaml.Controls.Viewbox](https://msdn.microsoft.com/en-us/library/windows.ui.xaml.controls.viewbox(v=vs.140).aspx)[Windows.UI.Xaml.Controls.Border](https://msdn.microsoft.com/en-us/library/windows.ui.xaml.controls.border(v=vs.140).aspx), 或 [Windows.UI.Xaml.Controls.ScrollViewer](https://msdn.microsoft.com/en-us/library/windows.ui.xaml.controls.scrollviewer(v=vs.140).aspx) 来分组元素，则元素将被放置于 [Windows.UI.Xaml.Controls.Viewbox](https://msdn.microsoft.com/en-us/library/windows.ui.xaml.controls.viewbox(v=vs.140).aspx)、[Windows.UI.Xaml.Controls.Border](https://msdn.microsoft.com/en-us/library/windows.ui.xaml.controls.border(v=vs.140).aspx) 或 [Windows.UI.Xaml.Controls.ScrollViewer](https://msdn.microsoft.com/en-us/library/windows.ui.xaml.controls.scrollviewer(v=vs.140).aspx) 内的一个新 [Windows.UI.Xaml.Controls.Grid](https://msdn.microsoft.com/en-us/library/windows.ui.xaml.controls.grid(v=vs.140).aspx) 面板中。 如果在这些布局容器的其中之一取消分组，则仅将删除 [Windows.UI.Xaml.Controls.Viewbox](https://msdn.microsoft.com/en-us/library/windows.ui.xaml.controls.viewbox(v=vs.140).aspx)[Windows.UI.Xaml.Controls.Border](https://msdn.microsoft.com/en-us/library/windows.ui.xaml.controls.border(v=vs.140).aspx) 或 [Windows.UI.Xaml.Controls.ScrollViewer](https://msdn.microsoft.com/en-us/library/windows.ui.xaml.controls.scrollviewer(v=vs.140).aspx)，而将保留 [Windows.UI.Xaml.Controls.Grid](https://msdn.microsoft.com/en-us/library/windows.ui.xaml.controls.grid(v=vs.140).aspx) 面板。 若要删除 `Grid` 面板，请再次取消分组该元素。

若要将元素取消分组并删除布局，请右键单击想要取消分组的组并单击“取消分组”。 还可以通过右键单击文档大纲窗口中选定的项，然后单击“分组”或“取消分组”，以对元素进行分组或取消分组 。

### 重置元素布局

可以通过使用“布局重置”命令还原某个元素特定布局属性的默认值。 通过使用此命令，可以单独或一起重置边距、对齐方式、宽度、高度和元素大小。

若要重置元素布局，请在文档大纲窗口或美工板中右键单击该元素，然后选择“布局” > “重置 PropertyName”，其中 PropertyName 是想要重置的属性（或者选择“布局” > “全部重置”，重置该元素的所有布局属性）。

## [Organize objects into layout containers](https://docs.microsoft.com/en-us/visualstudio/designers/organize-objects-into-layout-containers-in-xaml-designer?view=vs-2019)

本文介绍用于 XAML 设计器的版式面板和控件。

想象希望对象出现在页面上的位置；诸如图像、按钮和视频等对象。 也许你希望它们出现在行和列中、在单个行中（垂直或水平）或在固定位置中。

在考虑好页面的显示情况后，请选择布局面板。 所有页面都从一个布局面板开始，因为你需要某个容器来向其中添加对象。 默认情况下为 Grid，但可以进行更改。

布局面板可帮助你在页面上排列对象，但是它们的作用不仅于此。 它们可以帮助你针对不同屏幕大小和分辨率进行设计。 当用户运行你的应用时，布局面板中的所有对象都会调整大小以匹配用户设备的屏幕空间。 当然，如果不希望布局进行此操作，则可为一部分布局或整个布局重写该行为。 可以使用高度和宽度属性对此进行控制。

### 布局面板

通过选择这些布局面板之一来开始设计你的页面。 页面可以具有多个布局面板。 例如，可从 Grid 布局面板开始，然后将一个 StackPanel 添加到 Grid 中的某个区域，即可在该元素中垂直排列控件。

以下布局面板是最常用的，不过还有一些其他布局面板。 在 Visual Studio 的“工具箱”中或 Blend for Visual Studio 的“资产”面板中可以找到它们。

#### Grid

在行和列中排列对象。

![Grid 版式面板](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/98b234b2-ac3b-441f-9136-98375fee87b7.png?view=vs-2019)

#### UniformGrid

将对象排列到相等或统一的网格区域中。 此面板非常适用于排列图像的列表。

![UniformGrid 版式面板](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/928b9284-a7e8-4678-875a-656b80b78076.png?view=vs-2019)

（仅适用于 WPF 项目。）

#### Canvas

按任何所需方式排列对象。 当用户运行你的应用时，这些元素将在屏幕上具有固定位置。

![Canvas 版式面板](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/e1ae27f0-3a57-454e-b580-877dcea8836d.png?view=vs-2019)

#### StackPanel

在单个行中水平或垂直排列对象。

![StackPanel 版式面板](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/a85a7b57-b0a8-495e-b985-f0291e41d093.png?view=vs-2019)

#### WrapPanel

按顺序从左到右排列对象。 面板最右边空间不足时，它会将内容换行到下一行，并采用从左到右、从上到下的换行顺序。 还可以使自动换行面板的方向垂直，以便对象从上到下、从左到右排列。

（仅适用于 WPF 项目。）

![WrapPanel 版式面板](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1c415fb-9a32-4a18-aa0b-308fca994ac9.png?view=vs-2019)

#### DockPanel

排列对象，使它们停留或停靠在面板的一个边缘。

（仅适用于 WPF 项目。）

![DockPanel 版式面板](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/72d46b58-9a49-4dd5-8af7-6843c0440226.png?view=vs-2019)

**观看短片：**![“播放”按钮](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/bldadminconsoleinitialconfigicon.png?view=vs-2019) [WPF - DockPanel](https://www.youtube.com/watch?v=EBH_OIM-zPo)

### 布局控件

也可以向布局控件添加对象。 布局控件功能不如布局面板那么丰富，在某些情况中这些控件可能很有用。

以下布局控件是最常用的，不过还有一些其他布局控件。 在 Visual Studio 的“工具箱”中或 Blend for Visual Studio 的“资产”面板中可以找到它们。

#### Border

围绕创建边框、背景或两者。 只能将一个对象添加到边框。 如果要将边框或背景应用于多个对象，请将布局面板添加到边框。 然后，将对象添加到该面板或控件。

![边框布局控件](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/e761238b-99fd-43c5-bbc4-57538b8289ff.png?view=vs-2019)

#### 弹出项

在窗口中向用户显示信息或选项。 只能将一个对象添加到弹出项。 默认情况下，弹出项包含一个 Grid，但是可以更改。

#### ScrollViewer

使用户可以向下滚动页面或页面区域。 只能将一个对象添加到 ScrollViewer，因此添加 Grid 或 StackPanel 等布局面板很有必要。

![ScrollViewer 布局控件](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/06b326d4-f23d-41a6-b26b-e1aff37572a7.png?view=vs-2019)

#### Viewbox

采用与缩放控件十分类似的方式扩展对象。 只能将一个对象添加到 Viewbox。 如果要将该效果应用于多个对象，请将布局面板添加到 ViewBox，然后将控件添加到该布局面板。

（仅适用于 WPF 项目。）

![ViewBox 布局控件](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/f5b13c66-d918-4141-8a16-bd8f8628687a.png?view=vs-2019)

## [Create and apply a resource](https://docs.microsoft.com/en-us/visualstudio/designers/how-to-create-and-apply-a-resource?view=vs-2019)

XAML 设计器中元素的样式和模板存储在称作资源的可重用实体中。 样式可设置元素属性并重用这些设置以便多个元素实现一致的外观。 [ControlTemplate](https://docs.microsoft.com/zh-cn/uwp/api/Windows.UI.Xaml.Controls.ControlTemplate) 定义控件的外观，并且可作为资源应用。 有关详细信息，请参阅[快速入门：控件样式](http://go.microsoft.com/fwlink/?LinkID=248239)和[快速入门：控件模板](http://go.microsoft.com/fwlink/?LinkID=247982)。

每当从现有属性、[样式](https://docs.microsoft.com/zh-cn/uwp/api/Windows.UI.Xaml.Style)或 `ControlTemplate` 创建新资源时，可在“创建资源”对话框中将资源定义为应用程序级别、文档级别或元素级别。 这些级别决定了可使用资源的位置。 例如，如果定义元素级别的资源，则该资源只能应用于在其上创建资源的元素。 还可以选择将资源存储在资源字典中，资源字典是可在另一个项目中再次使用的单独文件。

### 创建新资源的步骤

1. 在 XAML 设计器中打开一个 XAML 文件后，创建一个元素，或在“文档大纲”窗口中选择一个元素。

2. 在“属性”窗口中，选择属性标记，该标记显示为属性值右侧的一个方框符号，然后选择“转换为新资源”。 白色方框符号指示默认值，而黑色方框符号通常指示已应用了某个本地资源。

   将出现用于创建资源的相应对话框。 当从画笔创建资源时，就会出现此对话框：

   ![“创建资源”对话框](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/xaml_create_resource.png?view=vs-2019)

3. 在“名称(关键字)”框中，输入关键字名称。 这是当希望其他元素可以引用该资源时，可以使用的名称。

4. 在“定义位置”下，选择指定想要在其中定义资源的位置的选项：

   - 若要使该资源对应用程序中的任何文档可用，则选择“应用程序”。
   - 若要使该资源仅对当前文档可用，则选择“此文档”。
   - 若要使该资源仅对从中创建了该资源的元素或其子元素可用，则选择“此文档”，然后在下拉列表中，选择 **element**: **name**。
   - 若要在可在其他项目中重用的资源字典文件中定义该资源，则单击“资源字典”，然后在下拉列表中选择一个现有的资源字典文件，如“StandardStyles.xaml”。

5. 选择“确定”按钮以创建资源并将其应用于从其中创建了该资源的元素。

### 将资源应用于某个元素或属性的步骤

1. 在“文档大纲”窗口中，选择想要向其应用资源的元素。

2. 执行下列操作之一：

   - 将资源应用于属性。 在“属性”窗口中，选择属性值旁边的属性标记，再选择“本地资源”或“系统资源”，然后从显示的列表中选择可用的资源。

     如果看不到希望看到的资源，可能是因为该资源的类型与属性的类型不匹配。

   - 将样式或控件模板资源应用于控件。 在“文档大纲”窗口中打开控件的右键单击菜单（关联菜单），选择“编辑模板”或“编辑其他模板”，选择“应用资源”，再从显示的列表中选择控件模板的名称。

      备注

     “编辑模板”应用控件模板。 “编辑其他模板”应用其他模板类型。

     可在任何兼容的位置应用资源。 例如，画笔资源可应用于 [Windows.UI.Xaml.Controls.TextBox](https://msdn.microsoft.com/en-us/library/windows.ui.xaml.controls.textbox(v=vs.140).aspx) 控件的“前景色”属性。

### 编辑资源的步骤

1. 选择美工板上或“文档大纲”窗口中的某个元素。
2. 在“属性”窗口中，选择属性右侧的“默认”或“本地”属性标记，然后选择“编辑资源”，以打开“编辑资源”对话框。
3. 修改该资源的选项。

### 请参阅

- [使用 XAML 设计器创建 UI](https://docs.microsoft.com/zh-cn/visualstudio/designers/creating-a-ui-by-using-xaml-designer-in-visual-studio?view=vs-2019)

## [Walkthrough: Bind to data in XAML Designer](https://docs.microsoft.com/en-us/visualstudio/designers/walkthrough-binding-to-data-in-xaml-designer?view=vs-2019)

在 XAML 设计器中，可以通过使用美工板和“属性”窗口设置数据绑定属性。 本演练中的示例演示如何将数据绑定到控件。 具体而言，本演练展示如何创建具有名为 `ItemCount` 的 [DependencyProperty](https://docs.microsoft.com/zh-cn/uwp/api/Windows.UI.Xaml.DependencyProperty) 的简单购物车类，然后将 `ItemCount` 属性绑定到 [TextBlock](https://docs.microsoft.com/zh-cn/uwp/api/Windows.UI.Xaml.Controls.TextBlock) 控件的 **Text** 属性。

### 创建一个类以用作数据源的步骤

1. 在“文件”菜单上，选择“新建” > “项目”。

2. 在“新建项目”对话框中，选择“Visual C#”或“Visual Basic”节点，展开“Windows 桌面”节点，然后选择“WPF 应用程序”模板。

3. 将项目命名为“BindingTest”，然后选择“确定”按钮。

4. 打开 MainWindow.xaml.cs（或 MainWindow.xaml.vb）文件并添加下面的代码。 在 C# 中，在 `BindingTest`命名空间中添加代码（文件中最后一个右括号之前）。 在 Visual Basic 中，仅添加新类。

   C#复制

   ```csharp
   public class ShoppingCart : DependencyObject
   {
       public int ItemCount
       {
           get { return (int)GetValue(ItemCountProperty); }
           set { SetValue(ItemCountProperty, value); }
       }
   
       public static readonly DependencyProperty ItemCountProperty =
            DependencyProperty.Register("ItemCount", typeof(int),
            typeof(ShoppingCart), new PropertyMetadata(0));
   }
   ```

   这段代码使用 [PropertyMetadata](https://docs.microsoft.com/zh-cn/uwp/api/Windows.UI.Xaml.PropertyMetadata) 对象，将默认项计数的值设置为 0。

5. 在“文件”菜单上，选择“生成” > “生成解决方案”。

### 将 ItemCount 属性绑定到 TextBlock 控件的步骤

1. 在解决方案资源管理器中，打开 MainWindow.xaml 的快捷菜单，然后选择“视图设计器”。

2. 在工具箱中，选择[网格](https://docs.microsoft.com/zh-cn/uwp/api/Windows.UI.Xaml.Controls.Grid)控件，并将其添加到窗体。

3. 选定 `Grid` 后，在属性窗口中，选择“DataContext”属性旁边的“新建”按钮。

4. 在“选择对象”对话框中，确保清除“显示所有程序集”复选框，选择“BindingTest”命名空间下的“ShoppingCart”，然后选择“确定”按钮。

   下图显示了“ShoppingCart”处于选中状态的“选择对象”对话框。

   ![“选择对象”对话框](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/blendselectobject.png?view=vs-2019)

5. 在“工具箱”中，选择一个 `TextBlock` 控件将其添加到窗体。

6. 选定 `TextBlock` 控件后，在“属性”窗口中，选择“文本”属性右侧的属性标记，然后选择“创建数据绑定”。（属性标记看上去像一个小框。）

7. 在“创建数据绑定”对话框的“路径”框中，选择“ItemCount: (int32)”属性，然后选择“确定”按钮。

   下图显示选定“ItemCount”属性的“创建数据绑定”对话框。

   ![“创建数据绑定”对话框](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/xaml_create_data_binding.png?view=vs-2019)

8. 按 F5 运行应用。

   `TextBlock` 控件应将默认值 0 显示为文本。

## [Keyboard shortcuts for XAML Designer](https://docs.microsoft.com/en-us/visualstudio/designers/keyboard-shortcuts-for-xaml-designer?view=vs-2019)

通过使用 XAML 设计器中的键盘快捷方式，需要多次单击鼠标按钮完成的操作只需按一次键盘快捷方式即可完成，从而可加快你的工作速度。

### 元素快捷方式

此表列出了可用于使用美工板上的元素的快捷方式。

| “执行此操作”           | 操作步骤                                                     |
| ---------------------- | ------------------------------------------------------------ |
| 创建一个元素           | 按 Ctrl+N                                                    |
| 复制元素               | 按住 Alt 并按方向键。                                        |
| 编辑控件中的文本       | 按 F2（按 Esc 退出）                                         |
| 选择单个元素           | 按 Tab，以在文档中显示的顺序选择元素。 （还可以使用方向键选择元素。） |
| 选择多个元素           | 按住 Shift 的同时选择每个元素                                |
| 选择多个非相邻元素     | 按住 Ctrl 的同时选择第一个和最后一个元素                     |
| 移动所选元素           | 按方向键（可以按住 Shift 来增加每次按键移动的距离。）        |
| 按 15 度的增量旋转元素 | 按住 Shift 的同时旋转元素                                    |
| 选择所有元素           | 按 Ctrl+A                                                    |
| 取消选择所有元素       | 按 Ctrl+Shift+A                                              |
| 显示或隐藏元素句柄     | 按 F9                                                        |
| 选择某个元素的属性     | 选定某个元素和“属性”窗口上的焦点后，按 Tab 。（使用 Ctrl+Tab 将焦点更改为“属性”窗口。）可以使用方向键从下拉列表中选择属性值。 |

### “文档大纲”窗口快捷方式

下表列出了在使“用文档大纲”窗口中的元素时可用的快捷方式。

| “执行此操作”                                 | 操作步骤     |
| -------------------------------------------- | ------------ |
| 当焦点位于“文档大纲”窗口上时，隐藏美工板对象 | Ctrl+H       |
| 当焦点位于“文档大纲”窗口上时，显示美工板对象 | Shift+Ctrl+H |
| 当焦点位于“文档大纲”窗口上时，锁定美工板对象 | Ctrl + L     |
| 当焦点位于“文档大纲”窗口上时，解锁美工板对象 | Shift+Ctrl+L |

## [Debug or disable project code](https://docs.microsoft.com/en-us/visualstudio/designers/debugging-or-disabling-project-code-in-xaml-designer?view=vs-2019)

很多情况下，造成 XAML 设计器中出现未处理异常的原因可能为：项目代码尝试访问在设计器运行应用程序时返回不同值或以不同方式运行的属性/方法。 可通过在 Visual Studio 的其他实例中调试项目代码解决这些异常，也可通过禁用设计器中的项目代码暂时阻止这些异常。

项目代码包括：

- 自定义控件和用户控件
- 类库
- 值转换器
- 针对从项目代码生成的设计时数据绑定

当禁用项目代码时，Visual Studio 会显示占位符。 例如，Visual Studio 会显示所含数据不再可用的绑定的属性名称，或显示不再运行的控件的占位符。

![未经处理的异常对话框](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/xaml_unhandledexception.png?view=vs-2019)

### 确定项目代码是否会导致异常

1. 在未处理的异常对话框中，选择“单击此处重载设计器” 链接。

2. 在菜单栏上，选择“调试” > “启动调试”以生成和运行应用程序。

   如果应用程序成功生成和运行，则设计时异常可能由设计器中运行的项目代码引起。

### 调试设计器中运行的项目代码

1. 在未处理的异常对话框中，选择“单击此处禁用正在运行的项目代码并重载设计器” 链接。

2. 在 Windows 任务管理器中，选择“结束任务” 按钮以关闭当前运行的 Visual Studio XAML 设计器的任何实例。

   ![TaskManager 中的 XAML 设计器实例](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/xaml_taskmanager.png?view=vs-2019)

3. 在 Visual Studio 中，打开 XAML 页面，其中包含要调试的代码或控件。

4. 打开 Visual Studio 的新实例，然后打开项目的第二个实例。

5. 在项目代码中设置断点。

6. 在 Visual Studio 的新实例中，选择菜单栏上的“调试” > “附加到进程”。

7. 在“附加到进程” 对话框中，从“可用进程” 列表中选择“XDesProc.exe” ，然后选择“附加” 按钮。

   ![XAML 设计器进程](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/xaml_attach.png?view=vs-2019)

   这是 Visual Studio 的第一个实例中 XAML 设计器的进程。

8. 在 Visual Studio 的第一个实例中，选择菜单栏上的“调试” > “启动调试”。

   现即可单步执行设计器中运行的代码。

### 禁用设计器中的项目代码

- 在未处理的异常对话框中，选择“单击此处禁用正在运行的项目代码并重载设计器” 链接。

- 或者，在 XAML 设计器的工具栏上，选择“禁用项目代码”按钮。

  ![“禁用项目代码”按钮](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/xaml_disablecode.png?view=vs-2019)

  你可以再次切换按钮以重新启用项目代码。

   备注

  对于面向 ARM 或 X64 处理器的项目，Visual Studio 无法在设计器中运行项目代码，因此禁用设计器中的“禁用项目代码” 按钮。

- 其中任一选项都会导致设计器重载，然后会禁用关联项目的所有代码。

   备注

  禁用项目代码可能导致设计时数据丢失。 或者调试在设计器中运行的代码。

### 控件显示选项

> “控件显示选项”仅适用于定目标到 Windows 10 Fall Creators Update（生成号 16299）或更高版本的通用 Windows 平台应用程序。 Visual Studio 2017 版本 15.9 或更高版本提供“控件显示选项”功能。

在 XAML 设计器中，可以将“控件显示选项”更改为，仅显示 Windows SDK 中的平台控件。 这可能会提升 XAML 设计器的可靠性。

若要更改“控件显示选项”，请单击设计器窗口左下角的图标，再选择“控件显示选项”下的选项：

![控件显示选项](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/control_display_options.png?view=vs-2019)

当你选中“仅显示平台控件”后，SDK 中的所有自定义控件、客户用户控件等都不会完整呈现。 相反，它们会被替换为回退控件，以展示控件的大小和位置。

## [XAML errors and warnings](https://docs.microsoft.com/en-us/visualstudio/designers/xaml-errors-warnings?view=vs-2019)

创作 XAML 时，Visual Studio 会分析键入的代码。 检测到错误时，代码行上会出现波浪线。 光标悬停在波浪线上可获取错误或警告的详细信息。 对于某些错误和警告，将显示“快速操作”灯泡，使用 Ctrl+. 键盘快捷方式可问题修复选项。

### 错误类型

多个工具后台并行分析 XAML。 XAML 错误可基于检测到错误的工具分为以下三种类型：

| **检测到错误的工具**         | **错误代码格式** |
| ---------------------------- | ---------------- |
| XAML 语言服务（XAML 编辑器） | XLSxxxx          |
| XAML 设计器                  | XDGxxxx          |
| XAML 编辑并继续              | XECxxxx          |

> 并非所有错误或警告都有相应的代码。 此类错误通常是 XAML 设计器错误。

### 取消显示 XAML 设计器错误

选择“工具”和“选项”，再选择“文本编辑器”和“XAML”>“其他”，即可打开“选项”对话框。

取消选中“显示 XAML 设计器检测到的错误”复选框。

![取消显示 XAML 设计器错误](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/suppress_xaml_designer_errors.png?view=vs-2019)