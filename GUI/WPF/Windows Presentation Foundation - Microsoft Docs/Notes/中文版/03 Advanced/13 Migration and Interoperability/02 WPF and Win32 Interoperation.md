# [WPF and Win32 Interoperation](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/wpf-and-win32-interoperation)

本主题概述如何互操作 WPF 和 Win32 代码。 Windows Presentation Foundation (WPF) 提供了用于创建应用程序的丰富环境。 但是，如果对 Win32 代码投入很大，重复使用部分此代码可能更有效。



## WPF 和 Win32 互操作基础知识

WPF 和 Win32 代码间的互操作存在两种基本方法。

- 在 WPF 窗口中承载 Win32 内容。 通过此方法，可在标准 Win32 窗口和应用程序的框架内使用 WPF 的高级图形功能。
- 在 WPF 内容中承载 Win32 窗口。 通过此方法，可在其他 WPF 内容的上下文中使用现有自定义 Win32 控件，并可跨边界传递数据。

本主题中对上述每种方法进行了概念性介绍。 托管的更加面向代码演示WPF中Win32，请参阅[演练：Win32 中承载 WPF 内容](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/walkthrough-hosting-wpf-content-in-win32)。 托管的更加面向代码演示Win32中WPF，请参阅[演练：中承载 Win32 控件在 WPF 中的](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/walkthrough-hosting-a-win32-control-in-wpf)。



## WPF 互操作项目

虽然 WPF API 为托管代码，但大多数现有 Win32 程序是以非托管 C++ 编写而成。 无法从真正的非托管程序调用 WPF API。 但是，通过使用 Microsoft Visual C++ 编译器的 `/clr` 选项，可创建托管与非托管混合的程序，在此程序中可无缝混合托管和非托管 API 调用。

存在的一个项目级问题是无法将 可扩展应用程序标记语言 (XAML) 文件编译到 C++ 项目中。 可通过一些项目分离技术对此进行弥补。

- 创建包含所有的 C# DLL 你XAML页为已编译的程序集，然后让你C++可执行文件包含DLL作为参考。
- 创建一个 C# 可执行文件WPF内容，并将其引用C++ DLL ，其中包含Win32内容。
- 使用[Load](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.xamlreader.load)加载任何XAML在运行时，而不是编译您XAML。
- 不要使用XAML，并写入所有你WPF在代码中，构建元素树从[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)。

请使用最适合你的方法。

 备注

如果之前未使用过 C++/CLI，在互操作代码示例中你可能会看到 `gcnew` 和 `nullptr` 等一些“新”关键字。 这些关键字取代旧版双下划线语法 (`__gc`)，为 C++ 中的托管代码提供了更加自然的语法。 若要详细了解 C++/CLI 托管功能，请参阅[适用于运行时平台的组件扩展](https://docs.microsoft.com/zh-cn/cpp/windows/component-extensions-for-runtime-platforms)和[了解 C++/CLI](https://go.microsoft.com/fwlink/?LinkId=98739)。



## WPF 如何使用 Hwnd

若要充分利用 WPF“HWND 互操作”，需要了解 WPF 如何使用 HWND。 对于任何 HWND，无法将 WPF 绘制与 DirectX 绘制或 GDI / GDI+ 绘制混合。 这具有许多影响。 首先，若要混合这些绘制模型，必须创建互操作解决方案，并对选择使用的每个绘制模型使用互操作的指定段。 此外，绘制行为会为互操作解决方案可实现的操作创建一个“空域”限制。 有关“空域”概念的详细信息，请参见[技术区概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/technology-regions-overview)主题。

屏幕上的所有 WPF 元素最终受 HWND 支持。 当您创建WPF [Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)，WPF创建一个顶层 HWND，并使用[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)放置[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)并将其WPFHWND 内的内容。 应用程序中的其余 WPF 内容共享单个 HWND。 菜单、组合框下拉列表和其他弹出窗口例外。 这些元素会创建自己的顶层窗口，因此 WPF 菜单可能超出所在窗口 HWND 的边缘。 当你使用[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)将 HWND 内的放置WPF，WPF通知Win32如何定位到的新子 HWND 相对WPF [Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window) HWND。

与之相关的 HWND 概念是每个 HWND 内及其之间的透明度。 [技术区概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/technology-regions-overview)主题中对此也有相关介绍。



## 在 Microsoft Win32 窗口中承载 WPF 内容

托管的关键WPF上Win32窗口是[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)类。 此类在 Win32 窗口中包装 WPF 内容，以便 WPF 内容可作为子窗口并入 用户界面 (UI)。 以下方法在单个应用程序中合并 Win32 和 WPF。

1. 将 WPF 内容（内容根元素）作为托管类实现。 通常情况下，该类继承的一个类可以包含多个子元素和/或使用作为根元素，如[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)或[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)。 后续步骤中，此类被称为 WPF 内容类，此类的实例被称为 WPF 内容对象。
2. 使用 Win32 实现 C++/CLI 应用程序。 若要以现有非托管 C++ 应用程序开始，可更改项目设置将 `/clr` 编译器标志包括在内，以此来允许应用程序调用托管代码（本主题中未介绍支持 `/clr` 编译可能所需内容的完整范围）。
3. 将线程处理模型设置为单线程单元 (STA)。 WPF 使用此线程模型。
4. 处理窗口过程中的 WM_CREATE 通知。
5. 在处理程序（或处理程序调用的函数）中，执行以下操作：
   1. 创建一个新[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)对象，将父窗口 HWND 作为其`parent`参数。
   2. 创建 WPF 内容类的一个实例。
   3. 将分配到的引用WPF内容对象[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)对象[RootVisual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource.rootvisual)属性。
   4. [HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)对象[Handle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource.handle)属性包含窗口句柄 (HWND)。 要获取可在应用程序的非托管部分中使用的 HWND，需将 `Handle.ToPointer()` 强制装换为 HWND。
6. 实现一个托管类，该类包含一个用于保存对 WPF 内容对象的引用的静态字段。 此类可以获取对引用WPF内容对象从你Win32的代码，但重要的是，它会阻止的详细信息在[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)无意中进行垃圾回收。
7. 通过将处理程序附加到一个或多个 WPF 内容对象事件，接收 WPF 内容对象的通知。
8. 通过使用存储在静态字段中的引用设置属性、调用方法等，与 WPF 内容对象进行通信。

 备注

如果生成一个单独的程序集然后对其进行引用，对于步骤 1，可使用内容类的默认分部类在 XAML 中完成部分或全部 WPF 内容类定义。 虽然通常包括[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)对象作为编译的一部分XAML程序集，您不的最终使用该[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)作为互操作的一部分，您只需使用一个或多个用于根类XAML文件引用为应用程序和引用其分部类。 该过程的其余部分基本与上述相似。

每个步骤执行本主题中的代码所示[演练：Win32 中承载 WPF 内容](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/walkthrough-hosting-wpf-content-in-win32)。



## 在 WPF 中承载 Microsoft Win32 窗口

托管的关键Win32内其他窗口WPF内容是[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)类。 该类在可添加到 WPF 元素树的 WPF 元素中包装窗口。[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost) 此外支持API，让你执行进程所承载的窗口消息之类的任务。 基本过程：

1. 为 WPF 应用程序创建一个元素树（可通过代码或标记）。 在元素树中查找相应的许可点其中[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)实现可添加为子元素。 剩余步骤中，此元素称为保留元素。
2. 派生自[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)若要创建一个对象，保存你Win32内容。
3. 在此主机类，重写[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)方法[BuildWindowCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost.buildwindowcore)。 返回承载窗口的 HWND。 可能需要将实际控件包装为返回窗口的子窗口；在承载窗口中包装控件为 WPF 内容从控件接收通知提供了一种简单的方式。 此方法有助于更正一些有关主机控件边界处消息处理的 Win32 问题。
4. 重写[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)方法[DestroyWindowCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost.destroywindowcore)和[WndProc](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost.wndproc)。 这样做的目的是处理清除和删除对承载内容的引用，尤其是在已创建对非托管对象的引用的情况下。
5. 在代码隐藏文件中，创建控件承载类的一个实例，并使其成为保留元素的子元素。 通常会使用事件处理程序如[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)，或使用分部类构造函数。 但也可通过运行时行为添加互操作内容。
6. 处理选择的窗口消息，例如控件通知。 方法有两种。 两种方法提供对消息流的相同访问权限，因此你的选择很大程度上取决于编程简便性。
   - 实现消息处理的所有消息 （而不仅仅是关闭消息） 中的重写[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)方法[WndProc](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost.wndproc)。
   - 使承载WPF元素处理的消息，处理[MessageHook](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost.messagehook)事件。 对发送到承载窗口的主窗口过程的每个消息都会引发该事件。
   - 无法处理超出进程使用的 windows 中的消息[WndProc](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost.wndproc)。
7. 通过使用平台调用来调用非托管 `SendMessage` 函数，与承载窗口通信。

按照这些步骤，创建一个处理鼠标输入的应用程序。 可以通过实现为承载窗口添加 tab 键支持[IKeyboardInputSink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.ikeyboardinputsink)接口。

每个步骤执行本主题中的代码所示[演练：中承载 Win32 控件在 WPF 中的](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/walkthrough-hosting-a-win32-control-in-wpf)。

### WPF 内部的 Hwnd

您可以将[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)视为一个特殊控件。 (从技术上讲，[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)是[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)派生的类，不[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)派生的类，但它可被视为用于互操作的目的的控件。)[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)抽象化基础Win32性质所承载的内容以便的其余部分WPF考虑所承载的内容是另一个类似于控件的对象，其中应呈现和处理输入。 [HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost) 行为通常类似于任何其他WPF [FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)，尽管有一些重要差异围绕输出 （绘图和图形） 和基于基础 Hwnd 的限制的输入 （鼠标和键盘） 可以支持。

#### 输出行为的显著差异

- [FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)它是[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)基类、 具有很多属性，表示对 UI 的更改。 这些包括属性如下所述[FrameworkElement.FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)，这将更改该元素作为父级内的元素的布局。 但是，这些属性大多数未映射到可能的 Win32 等效项（即使这类等效项可能存在）。 过多这些属性及其含义具有过高的绘制技术针对性，这使得映射并不可行。 因此，如设置属性[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)上[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)不起作用。
- [HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost) 不能旋转、 缩放、 倾斜，或其他受 Transform 影响。
- [HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost) 不支持[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)属性 （alpha 值混合处理）。 如果中的内容[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)执行[System.Drawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing)操作包含 alpha 信息，本身不是冲突，但[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)作为一个整体仅支持不透明度 = 1.0 （100%)。
- [HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost) 将显示在其他之上WPF相同的顶级窗口中的元素。 但是，[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)或[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)生成的菜单是一个单独的顶级窗口，并因此就能正常工作与[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)。
- [HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost) 不遵从其父级的剪辑区域[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)。 这可能是一个问题，如果你尝试将放[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)滚动区域内的类或[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)。

#### 输入行为的显著差异

- 通常，虽然输入的设备作用域内[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)托管Win32区域中，输入的事件直接转到Win32。
- 尽管鼠标位于[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)，你的应用程序不会收到WPF鼠标事件和的值WPF属性[IsMouseOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ismouseover)将`false`。
- 虽然[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)具有键盘焦点，你的应用程序将不会收到WPF键盘事件和的值WPF属性[IsKeyboardFocusWithin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.iskeyboardfocuswithin)将`false`。
- 当焦点位于[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)并更改到另一个控件内[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)，你的应用程序将不会收到WPF事件[GotFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.gotfocus)或[LostFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.lostfocus)。
- 相关触笔属性和事件相似，且并不报告信息，而在触笔位于[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)。



## Tab 键、助记键和加速键

[IKeyboardInputSink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.ikeyboardinputsink)并[IKeyboardInputSite](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.ikeyboardinputsite)接口允许你创建的无缝键盘体验，为混合WPF和Win32应用程序：

- Win32 和 WPF 组件之间的 Tab 键
- 焦点位于 Win32 组件内和 WPF 组件内时皆起作用的助记键和加速键。

[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)并[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)这两个类提供的实现[IKeyboardInputSink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.ikeyboardinputsink)，但它们不会处理更高级的方案所需的所有输入的消息。 替换为适当方法，获取所需的键盘行为。

接口仅对 WPF 和 Win32 区域间的转换过程中发生的事件提供支持。 在 Win32 区域内，Tab 键行为完全受 Tab 键的 Win32 实现逻辑（若有）控制。

## [Technology Regions Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/technology-regions-overview)

如果在应用程序中使用多种呈现技术（例如 WPF、Win32 或 DirectX），则这些呈现技术必须共享公共顶级窗口中的呈现区域。 本主题介绍可能会对 WPF 互操作应用程序的呈现和输入造成影响的问题。

### 区域

在顶级窗口内，可以这么想：每个包含互操作应用程序某个技术的 HWND 都具有自己的区域（也称为“空域”）。窗口内的每个像素都只属于一个特定 HWND，这构成了该 HWND 的区域。 （严格地说，如果有多个 WPFHWND，便会有多个 WPF 区域，但为了便于讨论，可以假定只有一个区域。） 区域暗含了这样一层含义：应用程序生存期内尝试在该像素之上呈现的所有层或其他窗口都必须是同一呈现级技术的一部分。 尝试在 Win32 上方呈现 WPF 像素会导致意外结果，应尽量通过互操作 API 禁止这种尝试。

#### 区域示例

下图显示一个混合使用 Win32、DirectX 和 WPF 的应用程序。 每种技术都使用属于自己的且互不重叠的一组像素，因此不存在区域问题。

![不存在空域问题的窗口](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/migrationinteroparchitectarticle01.png)

假设此应用程序使用鼠标指针位置来创建想要在这三个区域中任一区域上方呈现的动画。 无论动画本身采用哪一种技术，该技术都会与其他两种技术的区域发生冲突。 下图演示在一个 Win32 区域上呈现 WPF 圆形的尝试。

![互操作示意图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/migrationinteroparchitectarticle02.png)

如果尝试在不同技术间使用透明度/Alpha 混合，也会发生冲突。 在下图中，WPF 框与 Win32 和 DirectX 区域存在冲突。 因为该 WPF 框中的像素是半透明的，所以它们必须由 DirectX 和 WPF 共同拥有，但这是不可能的。 因此，这是另一种冲突情况，且不可生成。

![互操作示意图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/migrationinteroparchitectarticle03.png)

前面三个示例使用矩形区域，但也可以使用其他形状。 例如，区域可以具有一个孔。 下图显示了一个带有矩形孔的 Win32 区域，其大小为 WPF 和 DirectX 区域的总大小。

![互操作示意图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/migrationinteroparchitectarticle04.png)

区域也可以完全不是矩形，或可以是可由 Win32 HRGN（区域）描述的任何形状。

![互操作示意图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/migrationinteroparchitectarticle05.png)

### 透明度和顶级窗口

Windows 中的窗口管理器实际上仅处理 Win32 HWND。 因此，每个WPF[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)都是 HWND。 [Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window) HWND 必须遵守适用于任何 HWND 的一般规则。 在该 HWND 内，WPF 代码可以执行整个 WPF API 支持的任何操作。但是，为实现与桌面上其他 HWND 的交互，WPF 必须遵循 Win32 处理和呈现规则。 WPF 通过使用 Win32 API来支持非矩形窗口，HRGN 用于非矩形窗口，分层窗口用于每像素 Alpha。

不支持常量 Alpha 和颜色键。 Win32 分层窗口的功能因平台而异。

分层窗口可通过指定要应用于窗口中每个像素的 Alpha 值来使整个窗口呈现为半透明状。 （Win32 实际上支持每像素 Alpha，但这在实际的程序中很难应用，因为在此模式下需要自行绘制任何子 HWND，包括对话框和下拉列表）。

WPF 支持 HRGN；但是，对于此功能，没有相应的托管 API。 您可以使用平台调用和[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)来调用相关Win32 API。 有关详细信息，请参阅[从托管代码调用本机函数](https://docs.microsoft.com/zh-cn/cpp/dotnet/calling-native-functions-from-managed-code)。

WPF 分层窗口在不同操作系统上具有不同的功能。 这是因为 WPF 使用 DirectX 进行呈现，而分层窗口主要用于GDI 呈现，而非 DirectX 呈现。

- WPF 支持 Windows Vista 及更高版本上的硬件加速分层窗口。 Microsoft Windows XP 上的硬件加速分层窗口需要 Microsoft DirectX 的支持，所以该功能将取决于计算机上的 Microsoft DirectX 的版本。
- WPF 不支持透明度颜色键，因为 WPF 无法保证准确呈现所请求的颜色，尤其当呈现采用了硬件加速时更是如此。
- 如果应用程序在 Microsoft Windows XP 上运行，则 DirectX 图面之上的分层窗口会在 DirectX 应用程序呈现时闪烁。 （实际的呈现顺序是：Microsoft Windows 图形设备接口 (GDI) 隐藏分层窗口，然后 DirectX 进行绘制，之后 Microsoft Windows 图形设备接口 (GDI) 重新显示分层窗口。） 非 WPF 分层窗口也有此限制。

## [Sharing Message Loops Between Win32 and WPF](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/sharing-message-loops-between-win32-and-wpf)

本主题介绍如何实现与互操作的消息循环Windows Presentation Foundation (WPF)，通过使用现有的消息循环中的进行展示[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)或通过创建单独的消息循环上Win32端的互操作代码。

### ComponentDispatcher 和消息循环

正常情况下，互操作和键盘事件支持的是实现[IKeyboardInputSink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.ikeyboardinputsink)，或从已实现的类的子类[IKeyboardInputSink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.ikeyboardinputsink)，如[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)或[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)。 但是，键盘接收器支持不能解决时发送和接收跨互操作边界的消息可能遇到的所有可能的消息循环需求。 若要帮助形式化应用程序消息循环体系结构，Windows Presentation Foundation (WPF)提供了[ComponentDispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher)类，该类定义的消息循环，以按照一个简单的协议。

[ComponentDispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher) 是一个静态类，公开多个成员。 每个方法的作用域是隐式绑定到调用线程。 消息循环必须调用其中一些API（如在下一节中定义） 的关键时刻。

[ComponentDispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher) 提供的其他组件 （例如键盘接收器中） 可以侦听的事件。 [Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)类将调用所有相应[ComponentDispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher)相应序列中的方法。 如果要实现您自己的消息循环，你的代码负责调用[ComponentDispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher)中类似的方式的方法。

调用[ComponentDispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher)线程上的方法将只会调用该线程注册的事件处理程序。

### 编写消息循环

下面是清单[ComponentDispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher)如果编写您自己的消息循环，则将使用的成员：

- [PushModal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher.pushmodal)： 您的消息循环应调用此函数以指示该线程是模式。
- [PopModal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher.popmodal)： 您的消息循环应调用此函数以指示该线程已恢复为非模式线程。
- [RaiseIdle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher.raiseidle)： 您的消息循环应调用此函数以指示[ComponentDispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher)应引发[ThreadIdle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher.threadidle)事件。[ComponentDispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher) 将不会引发[ThreadIdle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher.threadidle)如果[IsThreadModal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher.isthreadmodal)是`true`，但也可以选择调用消息循环[RaiseIdle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher.raiseidle)即使[ComponentDispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher)不能对其在模式状态做出响应。
- [RaiseThreadMessage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher.raisethreadmessage)： 您的消息循环应调用此函数以指示有可用的新消息。 返回值指示是否为侦听器[ComponentDispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher)事件处理该消息。 如果[RaiseThreadMessage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher.raisethreadmessage)返回`true`（处理），调度程序不执行任何操作进一步并显示消息。 如果返回值是`false`，则调度程序应调用Win32函数`TranslateMessage`，然后调用`DispatchMessage`。

### 使用 ComponentDispatcher 和现有消息处理

以下是的清单[ComponentDispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher)成员将使用如果依赖于固有WPF消息循环。

- [IsThreadModal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher.isthreadmodal)： 返回应用程序是否已进入模式状态 （例如，已推送模式消息循环）。[ComponentDispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher) 可以跟踪此状态，因为此类维护的计数[PushModal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher.pushmodal)和[PopModal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher.popmodal)消息循环中的调用。
- [ThreadFilterMessage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher.threadfiltermessage) 和[ThreadPreprocessMessage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher.threadpreprocessmessage)事件遵循委托调用的标准规则。 委托调用中未指定的顺序，并且所有委托都调用即使第一个会将消息标记为已处理。
- [ThreadIdle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher.threadidle)： 表示适当和有效时间执行空闲处理 （没有其他挂起消息的线程）。 [ThreadIdle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher.threadidle) 将不会引发如果线程是模式。
- [ThreadFilterMessage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher.threadfiltermessage)： 引发的消息泵处理所有消息。
- [ThreadPreprocessMessage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher.threadpreprocessmessage)： 期间尚未处理的所有消息引发[ThreadFilterMessage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher.threadfiltermessage)。

则认为该消息已处理后的，如果[ThreadFilterMessage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher.threadfiltermessage)事件或[ThreadPreprocessMessage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher.threadpreprocessmessage)事件，`handled`中的事件数据的引用传递参数是`true`。 事件处理程序应忽略该消息，如果`handled`是`true`，因为这意味着不同的处理程序首先处理该消息。 这两个事件的事件处理程序可能会修改消息。 修改后的消息并不是原始的未更改的消息应调度调度程序。 [ThreadPreprocessMessage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher.threadpreprocessmessage) 传递到所有侦听器，但体系结构的意图是仅包含目标的消息应在其中调用响应消息中的代码的 HWND 的顶级窗口。

### HwndSource ComponentDispatcher 事件的处理方式

如果[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)是一个顶级窗口 （没有父项 HWND），它将向注册[ComponentDispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher)。 如果[ThreadPreprocessMessage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher.threadpreprocessmessage)引发时，如果消息适用于[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)或子窗口[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)调用其[IKeyboardInputSink.TranslateAccelerator](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource.system-windows-interop-ikeyboardinputsink-translateaccelerator)， [TranslateChar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.ikeyboardinputsink.translatechar)，[OnMnemonic](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.ikeyboardinputsink.onmnemonic)键盘接收器序列。

如果[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)不是一个顶级窗口 （具有一个父级 HWND），会有任何处理。 只有顶级窗口执行处理，并且存在预期可具有键盘接收器支持的最高级别窗口作为任何互操作方案的一部分。

如果[WndProc](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost.wndproc)上[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)称为没有首先调用相应的键盘接收器方法，你的应用程序都将收到更高的级别的键盘事件如[KeyDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.keydown)。 但是，没有键盘接收器将调用方法，从而避开了所需的键盘输入的模型功能，例如访问密钥支持。 这可能是因为消息循环未正确在通知相关线程[ComponentDispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher)，或者是因为父 HWND 未调用相应的键盘接收器响应。

转到键盘接收器的可能不将消息发送到 HWND 如果挂钩，该消息添加了使用[AddHook](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource.addhook)方法。 该消息可能具有已处理，在直接和未提交到消息泵级别`DispatchMessage`函数。

## [Hosting Win32 Content in WPF](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/hosting-win32-content-in-wpf)

### 系统必备

请参阅[WPF 和 Win32 互操作](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/wpf-and-win32-interoperation)。

### Win32 Windows Presentation Framework (HwndHost) 中的演练

若要重用Win32内的内容WPF应用程序，使用[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)，这就是使看起来像 Hwnd 控件WPF内容。 像[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)，[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)简单易用： 派生自[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)并实现`BuildWindowCore`和`DestroyWindowCore`方法，然后实例化您[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)派生的类并将其放入你WPF应用程序。

如果你Win32逻辑已打包为一个控件，然后在`BuildWindowCore`实现是比调用更多`CreateWindow`。 例如，若要创建Win32LISTBOX 控件中的C++:

```
virtual HandleRef BuildWindowCore(HandleRef hwndParent) override {  
    HWND handle = CreateWindowEx(0, L"LISTBOX",   
    L"this is a Win32 listbox",  
    WS_CHILD | WS_VISIBLE | LBS_NOTIFY  
    | WS_VSCROLL | WS_BORDER,  
    0, 0, // x, y  
    30, 70, // height, width  
    (HWND) hwndParent.Handle.ToPointer(), // parent hwnd  
    0, // hmenu  
    0, // hinstance  
    0); // lparam  
  
    return HandleRef(this, IntPtr(handle));  
}  
  
virtual void DestroyWindowCore(HandleRef hwnd) override {  
    // HwndHost will dispose the hwnd for us  
}  
```

但是，假设Win32代码不是那么自包含？ 如果这样，您可以创建Win32对话框框，并将其内容嵌入到更大WPF应用程序。 此示例演示了这Microsoft Visual Studio和C++，但还有可能以不同的语言或在命令行执行此操作。

开始编译为一个简单对话框C++DLL项目。

接下来，将对话框中引入到较大WPF应用程序：

- 编译DLL为托管 (`/clr`)
- 将转换为一个控件的对话框
- 定义的派生的类[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)与`BuildWindowCore`和`DestroyWindowCore`方法
- 重写`TranslateAccelerator`方法以处理对话框键
- 重写`TabInto`方法，以支持按 tab 键
- 重写`OnMnemonic`方法，以支持助记键
- 实例化[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)子类并将其放在右侧WPF元素

### 将变成一个控件的对话框

到子 HWND 使用 WS_CHILD 和 DS_CONTROL 样式可以打开一个对话框。 转到资源文件 (.rc)，其中定义对话框，并找到对话框中定义的开头：

复制

```
IDD_DIALOG1 DIALOGEX 0, 0, 303, 121  
STYLE DS_SETFONT | DS_MODALFRAME | DS_FIXEDSYS | WS_POPUP | WS_CAPTION | WS_SYSMENU  
```

更改第二个代码行：

复制

```
STYLE DS_SETFONT | WS_CHILD | WS_BORDER | DS_CONTROL  
```

此操作不会不完全其打包到一个自包含的控件;您仍然需要调用`IsDialogMessage()`因此Win32可以处理特定消息，但控件更改提供了将放在另一个 HWND 内的这些控件的简单方法。

### 子类 HwndHost

导入下列命名空间：

```
namespace ManagedCpp  
{  
    using namespace System;  
    using namespace System::Windows;  
    using namespace System::Windows::Interop;  
    using namespace System::Windows::Input;  
    using namespace System::Windows::Media;  
    using namespace System::Runtime::InteropServices;  
```

然后创建一个派生的类[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)并重写`BuildWindowCore`和`DestroyWindowCore`方法：

```
public ref class MyHwndHost : public HwndHost, IKeyboardInputSink {  
    private:  
        HWND dialog;  
  
    protected:   
        virtual HandleRef BuildWindowCore(HandleRef hwndParent) override {  
            InitializeGlobals();   
            dialog = CreateDialog(hInstance,   
                MAKEINTRESOURCE(IDD_DIALOG1),   
                (HWND) hwndParent.Handle.ToPointer(),  
                (DLGPROC) About);   
            return HandleRef(this, IntPtr(dialog));  
        }  
  
        virtual void DestroyWindowCore(HandleRef hwnd) override {  
            // hwnd will be disposed for us  
        }  
```

在本例中使用`CreateDialog`创建实际上是一个控件的对话框。 由于这是一个内部调用的第一个方法DLL，你还应执行一些标准Win32通过调用更高版本，您将定义的函数的初始化调用`InitializeGlobals()`:

复制

```
bool initialized = false;  
    void InitializeGlobals() {  
        if (initialized) return;  
        initialized = true;  
  
        // TODO: Place code here.  
        MSG msg;  
        HACCEL hAccelTable;  
  
        // Initialize global strings  
        LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);  
        LoadString(hInstance, IDC_TYPICALWIN32DIALOG, szWindowClass, MAX_LOADSTRING);  
        MyRegisterClass(hInstance);  
```

#### 重写 TranslateAccelerator 方法以处理对话框键

如果运行此示例现在，你会收到一个对话框控件的显示，但它会忽略所有键盘处理，这样可以对话框功能的对话框。 现在应重写`TranslateAccelerator`实现 (这来自`IKeyboardInputSink`，一个接口，[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)实现)。 当应用程序收到 WM_KEYDOWN 和 WM_SYSKEYDOWN 时调用此方法。

复制

```
#undef TranslateAccelerator  
        virtual bool TranslateAccelerator(System::Windows::Interop::MSG% msg,   
            ModifierKeys modifiers) override   
        {  
            ::MSG m = ConvertMessage(msg);  
  
            // Win32's IsDialogMessage() will handle most of our tabbing, but doesn't know   
            // what to do when it reaches the last tab stop  
            if (m.message == WM_KEYDOWN && m.wParam == VK_TAB) {  
                HWND firstTabStop = GetDlgItem(dialog, IDC_EDIT1);  
                HWND lastTabStop = GetDlgItem(dialog, IDCANCEL);  
                TraversalRequest^ request = nullptr;  
  
                if (GetKeyState(VK_SHIFT) && GetFocus() == firstTabStop) {  
                    // this code should work, but there’s a bug with interop shift-tab in current builds                      
                    request = gcnew TraversalRequest(FocusNavigationDirection::Last);  
                }  
                else if (!GetKeyState(VK_SHIFT) && GetFocus() == lastTabStop) {  
                    request = gcnew TraversalRequest(FocusNavigationDirection::Next);  
                }  
  
                if (request != nullptr)  
                    return ((IKeyboardInputSink^) this)->KeyboardInputSite->OnNoMoreTabStops(request);  
  
            }  
  
            // Only call IsDialogMessage for keys it will do something with.  
            if (msg.message == WM_SYSKEYDOWN || msg.message == WM_KEYDOWN) {  
                switch (m.wParam) {  
                    case VK_TAB:  
                    case VK_LEFT:  
                    case VK_UP:  
                    case VK_RIGHT:  
                    case VK_DOWN:  
                    case VK_EXECUTE:  
                    case VK_RETURN:  
                    case VK_ESCAPE:  
                    case VK_CANCEL:  
                        IsDialogMessage(dialog, &m);  
                        // IsDialogMessage should be called ProcessDialogMessage --  
                        // it processes messages without ever really telling you  
                        // if it handled a specific message or not  
                        return true;  
                }  
            }  
  
            return false; // not a key we handled  
        }  
```

这是代码的很多以单个片段，因此它可以使用一些更详细的解释。 首先，代码使用C++并C++宏; 您需要了解已存在一个名为宏`TranslateAccelerator`，定义在 winuser.h 中：

复制

```
#define TranslateAccelerator  TranslateAcceleratorW  
```

因此请务必定义`TranslateAccelerator`方法，而不`TranslateAcceleratorW`方法。

同样，还有非托管的 winuser.h MSG 和托管`Microsoft::Win32::MSG`结构。 你可以使用这两者之间区分C++`::`运算符。

复制

```
virtual bool TranslateAccelerator(System::Windows::Interop::MSG% msg,   
    ModifierKeys modifiers) override   
{  
    ::MSG m = ConvertMessage(msg);  
```

两个消息具有相同的数据，但是有时更轻松地使用非托管的定义，因此在此示例中，您可以定义明显转换例程：

复制

```
::MSG ConvertMessage(System::Windows::Interop::MSG% msg) {  
    ::MSG m;  
    m.hwnd = (HWND) msg.hwnd.ToPointer();  
    m.lParam = (LPARAM) msg.lParam.ToPointer();  
    m.message = msg.message;  
    m.wParam = (WPARAM) msg.wParam.ToPointer();  
  
    m.time = msg.time;  
  
    POINT pt;  
    pt.x = msg.pt_x;  
    pt.y = msg.pt_y;  
    m.pt = pt;  
  
    return m;  
}  
```

返回到`TranslateAccelerator`。 基本原则是调用Win32函数`IsDialogMessage`执行尽可能多工作，但`IsDialogMessage`不能访问该对话框之外的任何内容。 在对话框中，按 tab 键周围的用户选项卡运行过去的对话框中的最后一个控件时，需要将焦点设置到WPF通过调用部分`IKeyboardInputSite::OnNoMoreStops`。

复制

```
// Win32's IsDialogMessage() will handle most of the tabbing, but doesn't know   
// what to do when it reaches the last tab stop  
if (m.message == WM_KEYDOWN && m.wParam == VK_TAB) {  
    HWND firstTabStop = GetDlgItem(dialog, IDC_EDIT1);  
    HWND lastTabStop = GetDlgItem(dialog, IDCANCEL);  
    TraversalRequest^ request = nullptr;  
  
    if (GetKeyState(VK_SHIFT) && GetFocus() == firstTabStop) {  
        request = gcnew TraversalRequest(FocusNavigationDirection::Last);  
    }  
    else if (!GetKeyState(VK_SHIFT) && GetFocus() ==  lastTabStop) { {  
        request = gcnew TraversalRequest(FocusNavigationDirection::Next);  
    }  
  
    if (request != nullptr)  
        return ((IKeyboardInputSink^) this)->KeyboardInputSite->OnNoMoreTabStops(request);  
}  
```

最后，调用 `IsDialogMessage`。 但的职责之一`TranslateAccelerator`方法的告诉WPF是否处理击键。 如果未处理，输入的事件可以向下和向上遍历应用程序的其余部分。 在这里，您将公开的键盘消息处理是意料之中的事和中的输入体系结构的性质Win32。 遗憾的是，`IsDialogMessage`不返回任何方式是否它处理特定击键。 更糟糕的是，它将调用`DispatchMessage()`上不应处理的键击 ！ 因此你必须进行反向工程到`IsDialogMessage`，并仅为您知道的密钥将处理调用它：

复制

```
// Only call IsDialogMessage for keys it will do something with.  
if (msg.message == WM_SYSKEYDOWN || msg.message == WM_KEYDOWN) {  
    switch (m.wParam) {  
        case VK_TAB:  
        case VK_LEFT:  
        case VK_UP:  
        case VK_RIGHT:  
        case VK_DOWN:  
        case VK_EXECUTE:  
        case VK_RETURN:  
        case VK_ESCAPE:  
        case VK_CANCEL:  
            IsDialogMessage(dialog, &m);  
            // IsDialogMessage should be called ProcessDialogMessage --  
            // it processes messages without ever really telling you  
            // if it handled a specific message or not  
            return true;  
    }  
```

#### 重写到支持按 tab 键的 TabInto 方法

现在，已实现`TranslateAccelerator`，围绕选项卡的用户可以在对话框内框和 tab 键跳出这个到更大WPF应用程序。 但用户不能返回到对话框的选项卡上。 若要解决此问题，重写`TabInto`:

复制

```
public:   
    virtual bool TabInto(TraversalRequest^ request) override {  
        if (request->FocusNavigationDirection == FocusNavigationDirection::Last) {  
            HWND lastTabStop = GetDlgItem(dialog, IDCANCEL);  
            SetFocus(lastTabStop);  
        }  
        else {  
            HWND firstTabStop = GetDlgItem(dialog, IDC_EDIT1);  
            SetFocus(firstTabStop);  
        }  
        return true;  
    }  
```

`TraversalRequest`参数指示选项卡操作是一个选项卡或 shift 选项卡。

#### 重写 OnMnemonic 方法以支持助记键

键盘处理的方法是几乎已完成，但还有一个缺 – 助记键不起作用。 如果用户按下 alt-F，焦点 doe 不跳转到"第一个名称:"编辑框。 因此，重写`OnMnemonic`方法：

复制

```
virtual bool OnMnemonic(System::Windows::Interop::MSG% msg, ModifierKeys modifiers) override {  
    ::MSG m = ConvertMessage(msg);  
  
    // If it's one of our mnemonics, set focus to the appropriate hwnd  
    if (msg.message == WM_SYSCHAR && GetKeyState(VK_MENU /*alt*/)) {  
        int dialogitem = 9999;  
        switch (m.wParam) {  
            case 's': dialogitem = IDOK; break;  
            case 'c': dialogitem = IDCANCEL; break;  
            case 'f': dialogitem = IDC_EDIT1; break;  
            case 'l': dialogitem = IDC_EDIT2; break;  
            case 'p': dialogitem = IDC_EDIT3; break;  
            case 'a': dialogitem = IDC_EDIT4; break;  
            case 'i': dialogitem = IDC_EDIT5; break;  
            case 't': dialogitem = IDC_EDIT6; break;  
            case 'z': dialogitem = IDC_EDIT7; break;  
        }  
        if (dialogitem != 9999) {  
            HWND hwnd = GetDlgItem(dialog, dialogitem);  
            SetFocus(hwnd);  
            return true;  
        }  
    }  
    return false; // key unhandled  
};  
```

为什么不调用`IsDialogMessage`此处？ 根据需要之前-若要能够通知具有同样的问题WPF代码是否在代码或不是，处理击键和`IsDialogMessage`无法做到这一点。 还有第二个问题，因为`IsDialogMessage`拒绝处理助记键，如果已设定焦点的 HWND 内对话框的不是。

#### 实例化 HwndHost 派生类

最后，现在，所有键和选项卡支持都后，您可以将你[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)组成较大WPF应用程序。 如果主应用程序以XAML，将其放在正确的位置的最简单方法是将一个空[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)想要放置的元素[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)。 此处创建[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)名为`insertHwndHostHere`:

复制

```
<Window x:Class="WPFApplication1.Window1"  
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"  
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"  
    Title="Windows Presentation Framework Application"  
    Loaded="Window1_Loaded"  
    >  
    <StackPanel>  
        <Button Content="WPF button"/>  
        <Border Name="insertHwndHostHere" Height="200" Width="500"/>  
        <Button Content="WPF button"/>  
    </StackPanel>  
</Window>  
```

然后剩下的就是在实例化的代码序列中查找，一个好[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)并将其连接到[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)。 在此示例中，你会将它放在构造函数内[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)派生的类：

复制

```
public partial class Window1 : Window {  
    public Window1() {  
    }  
  
    void Window1_Loaded(object sender, RoutedEventArgs e) {  
        HwndHost host = new ManagedCpp.MyHwndHost();  
        insertHwndHostHere.Child = host;  
    }  
}  
```

后者可提供：

![WPF 应用程序屏幕截图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/interoparch09.png)

## [Walkthrough: Hosting a Win32 Control in WPF](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/walkthrough-hosting-a-win32-control-in-wpf)

Windows Presentation Foundation (WPF) 提供了用于创建应用程序的丰富环境。 但是，当您在 Win32 代码中有大量投入时，可能会重复使用至少某些更有效的在 WPF 应用程序中的代码而不是完全重写。 WPF 提供了一个简单的机制，用于承载 Win32 窗口中，在 WPF 页上。

本主题将指导你通过应用程序[中承载 Win32 ListBox 控件在 WPF 示例中](https://github.com/Microsoft/WPF-Samples/tree/master/Migration%20and%20Interoperability/WPFHostingWin32Control)，主机 Win32 列表框控件。 此常规步骤可扩展到承载任何 Win32 窗口中。

### 要求

本主题假定你基本熟悉 WPF 和 Win32 编程。 WPF 编程的基本简介，请参阅[Getting Started](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/getting-started/index)。 有关 Win32 编程的简介，可参考有关该主题的众多书籍特别*Programming Windows* Charles Petzold 的。

因为本主题附带的示例中实现C#，它将使用的平台调用服务 (PInvoke) 访问 Win32 API。 熟悉 PInvoke 是有所帮助，但不是必需的。

> 本主题包括来自相关示例的一些代码示例。 但是，出于可读性考虑，不包括完整的示例代码。 获取或查看完整的代码[中承载 Win32 ListBox 控件在 WPF 示例中](https://github.com/Microsoft/WPF-Samples/tree/master/Migration%20and%20Interoperability/WPFHostingWin32Control)。

### 基本过程

本部分概述了在 WPF 页上支持 Win32 窗口的基本过程。 其余各节介绍了每个步骤的详细内容。

基本的承载步骤如下：

1. 实现 WPF 页以承载窗口。 一种方法是创建[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)元素保留的页所承载的窗口的部分。
2. 实现一个类以承载继承的控件[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)。
3. 在此类中重写[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)类成员[BuildWindowCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost.buildwindowcore)。
4. 作为子窗口，其中包含 WPF 页中创建所承载的窗口。 尽管传统的 WPF 编程不需要显式地将它的使用、 在宿主页面是一个带有句柄 (HWND) 窗口。 接收页面 HWND 通过`hwndParent`参数的[BuildWindowCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost.buildwindowcore)方法。 应将所承载的窗口创建为此 HWND 的子窗口。
5. 在创建宿主窗口之后，返回所承载的窗口的 HWND。 如果你想要承载一个或多个 Win32 控件，您通常为该 HWND 的子级创建宿主窗口并使该宿主窗口的控件子级。 将控件包装在宿主窗口提供有关 WPF 页从控件接收通知的处理跨 HWND 边界的一些特定的 Win32 问题通知的简单方法。
6. 处理发送到宿主窗口的选定消息，例如，来自子控件的通知。 有两种方法可以实现此目的。
   - 如果想要在承载类中处理消息，重写[WndProc](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost.wndproc)方法的[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)类。
   - 如果您愿意让 WPF 处理消息，请处理[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)类[MessageHook](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost.messagehook)代码隐藏中的事件。 对于所承载的窗口收到的每条消息，都将发生此事件。 如果选择此选项，仍必须重写[WndProc](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost.wndproc)，但只需要最小实现。
7. 重写[DestroyWindowCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost.destroywindowcore)并[WndProc](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost.wndproc)方法的[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)。 必须重写这些方法才能履行[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)协定，但你可能只需提供的最小实现。
8. 在代码隐藏文件中，创建控件承载类的实例，并使其成为子的[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)旨在承载窗口的元素。
9. 通过将其发送与所承载的窗口进行通信Microsoft Windows消息和处理来自其子窗口，如控件发送的通知消息。

### 实现页面布局

承载 ListBox 控件的 WPF 页的布局由两个区域组成。 左侧和右侧的页上承载多个提供的 WPF 控件用户界面 (UI)，允许您处理 Win32 控件。 页面右上角具有一个正方形区域，用于放置所承载的 ListBox 控件。

若要实现此布局的代码是非常简单。 根元素是[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)有两个子元素。 第一个是[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)承载 ListBox 控件的元素。 它在该页的右上角占据了一个大小为 200x200 的正方形。 第二个是[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)元素，其中包含一套 WPF 控件来显示信息以及使您可以通过设置操作 ListBox 控件公开互操作属性。 对于每个元素的子级的[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)，请参阅有关什么是这些元素或其功能的详细信息使用的各种元素的参考资料，这些列在下面的示例代码，但不是会此处所述 (basic互操作模型不需要其中任何一个，它们可用于为示例增加一些交互性）。

```xaml
<Window
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  x:Class="WPF_Hosting_Win32_Control.HostWindow"
  Name="mainWindow"
  Loaded="On_UIReady">

  <DockPanel Background="LightGreen">
    <Border Name="ControlHostElement"
    Width="200"
    Height="200"
    HorizontalAlignment="Right"
    VerticalAlignment="Top"
    BorderBrush="LightGray"
    BorderThickness="3"
    DockPanel.Dock="Right"/>
    <StackPanel>
      <Label HorizontalAlignment="Center"
        Margin="0,10,0,0"
        FontSize="14"
        FontWeight="Bold">Control the Control</Label>
      <TextBlock Margin="10,10,10,10" >Selected Text: <TextBlock  Name="selectedText"/></TextBlock>
      <TextBlock Margin="10,10,10,10" >Number of Items: <TextBlock  Name="numItems"/></TextBlock>
  
      <Line X1="0" X2="200"
        Stroke="LightYellow"
        StrokeThickness="2"
        HorizontalAlignment="Center"
        Margin="0,20,0,0"/>
  
      <Label HorizontalAlignment="Center"
        Margin="10,10,10,10">Append an Item to the List</Label>
      <StackPanel Orientation="Horizontal">
        <Label HorizontalAlignment="Left"
          Margin="10,10,10,10">Item Text</Label>
        <TextBox HorizontalAlignment="Left"
          Name="txtAppend"
          Width="200"
          Margin="10,10,10,10"></TextBox>
      </StackPanel>
  
      <Button HorizontalAlignment="Left"
        Click="AppendText"
        Width="75"
        Margin="10,10,10,10">Append</Button>

      <Line X1="0" X2="200"
        Stroke="LightYellow"
        StrokeThickness="2"
        HorizontalAlignment="Center"
        Margin="0,20,0,0"/>
  
      <Label HorizontalAlignment="Center"
        Margin="10,10,10,10">Delete the Selected Item</Label>
  
      <Button Click="DeleteText"
        Width="125"
        Margin="10,10,10,10"
        HorizontalAlignment="Left">Delete</Button>
    </StackPanel>
  </DockPanel>
</Window>  
```

### 实现类以承载 Microsoft Win32 控件

此示例的核心是实际承载控件的类，即 ControlHost.cs。 它继承自[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)。 构造函数采用两个参数、 高度和宽度，它们分别对应于的高度和宽度[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)承载 ListBox 控件的元素。 这些值用于更高版本，请确保控制匹配项的大小[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)元素。

```csharp
public class ControlHost : HwndHost
{
  IntPtr hwndControl;
  IntPtr hwndHost;
  int hostHeight, hostWidth;

  public ControlHost(double height, double width)
  {
    hostHeight = (int)height;
    hostWidth = (int)width;
  }
```

还有一组常量。 这些常量主要取自 Winuser.h，并允许您调用 Win32 函数时使用约定俗成的名称。

```csharp
internal const int
  WS_CHILD = 0x40000000,
  WS_VISIBLE = 0x10000000,
  LBS_NOTIFY = 0x00000001,
  HOST_ID = 0x00000002,
  LISTBOX_ID = 0x00000001,
  WS_VSCROLL = 0x00200000,
  WS_BORDER = 0x00800000;
```

### 替代 BuildWindowCore 以创建 Microsoft Win32 窗口

重写此方法以创建将托管的页上，并使该窗口与页面之间的连接的 Win32 窗口。 由于此示例涉及承载 ListBox 控件，因此将创建两个窗口。 第一个是由 WPF 页面实际承载的窗口。 ListBox 控件被创建为该窗口的子窗口。

采用此方法的原因是为了简化接收来自控件的通知的过程。 [HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)类可用于处理发送到它所托管的窗口的消息。 如果主机 Win32 直接控制，您将收到发送到控件的内部消息循环的消息。 你可以显示控件并向其发送消息，但不会收到该控件发送到其父窗口的通知。 这意味你没有办法检测用户何时与该控件进行交互，以及其他更多方面。 可改为创建一个宿主窗口，并使控件成为该窗口的子窗口。 这样，你便能够处理宿主窗口的消息，包括由该控件发送给它的通知。 由于宿主窗口只是控件的一个简单包装器而已，为了方便起见，以后将把该包称为 ListBox 控件。

#### 创建宿主窗口和 ListBox 控件

您可以使用 PInvoke 通过创建和注册窗口类，创建控件的宿主窗口等。 但是，更简单的一种方法是使用预定义的“静态”窗口类创建窗口。 这将为你提供所需窗口步骤，以接收来自控件的通知，但需要完成最少的编码工作。

控件的 HWND 通过一个只读属性公开，以便宿主页面可使用它向控件发送消息。

```csharp
public IntPtr hwndListBox
{
  get { return hwndControl; }
}
```

ListBox 控件被创建为宿主窗口的子窗口。 两个窗口的高度和宽度被设置为传递给构造函数的值（前面已讨论）。 这可确保宿主窗口和控件的大小与页面上的保留区域相同。 在创建后，该示例将返回[HandleRef](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.interopservices.handleref)对象，其中包含宿主窗口的 HWND。

```csharp
protected override HandleRef BuildWindowCore(HandleRef hwndParent)
{
  hwndControl = IntPtr.Zero;
  hwndHost = IntPtr.Zero;

  hwndHost = CreateWindowEx(0, "static", "",
                            WS_CHILD | WS_VISIBLE,
                            0, 0,
                            hostWidth, hostHeight, 
                            hwndParent.Handle,
                            (IntPtr)HOST_ID,
                            IntPtr.Zero,
                            0);

  hwndControl = CreateWindowEx(0, "listbox", "",
                                WS_CHILD | WS_VISIBLE | LBS_NOTIFY
                                  | WS_VSCROLL | WS_BORDER,
                                0, 0,
                                hostWidth, hostHeight, 
                                hwndHost,
                                (IntPtr) LISTBOX_ID,
                                IntPtr.Zero,
                                0);

  return new HandleRef(this, hwndHost);
}
```

```csharp
//PInvoke declarations
[DllImport("user32.dll", EntryPoint = "CreateWindowEx", CharSet = CharSet.Unicode)]
internal static extern IntPtr CreateWindowEx(int dwExStyle,
                                              string lpszClassName,
                                              string lpszWindowName,
                                              int style,
                                              int x, int y,
                                              int width, int height,
                                              IntPtr hwndParent,
                                              IntPtr hMenu,
                                              IntPtr hInst,
                                              [MarshalAs(UnmanagedType.AsAny)] object pvParam);
```

### 实现 DestroyWindow 和 WndProc

除了[BuildWindowCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost.buildwindowcore)，还必须重写[WndProc](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost.wndproc)并[DestroyWindowCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost.destroywindowcore)方法的[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)。 在此示例中，该控件的消息由处理[MessageHook](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost.messagehook)处理程序，从而实现[WndProc](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost.wndproc)和[DestroyWindowCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost.destroywindowcore)很小。 情况下[WndProc](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost.wndproc)，将`handled`到`false`以指示未处理该消息并返回 0。 有关[DestroyWindowCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost.destroywindowcore)，只需销毁窗口。

```csharp
protected override IntPtr WndProc(IntPtr hwnd, int msg, IntPtr wParam, IntPtr lParam, ref bool handled)
{
  handled = false;
  return IntPtr.Zero;
}

protected override void DestroyWindowCore(HandleRef hwnd)
{
  DestroyWindow(hwnd.Handle);
}
```

```csharp
[DllImport("user32.dll", EntryPoint = "DestroyWindow", CharSet = CharSet.Unicode)]
internal static extern bool DestroyWindow(IntPtr hwnd);
```

### 在页面上承载控件

若要承载的控件的页上，您首先创建的新实例`ControlHost`类。 传递的高度和宽度的包含该控件的边框元素 (`ControlHostElement`) 到`ControlHost`构造函数。 这可确保 ListBox 具有正确的大小。 然后通过将分配托管页上的控件`ControlHost`对象传递给[Child](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.decorator.child)宿主属性[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)。

此示例附加到一个处理程序[MessageHook](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost.messagehook)事件的`ControlHost`从控件接收消息。 对于每条发送到宿主窗口的消息，都将引发此事件。 在这种情况下，这些消息是发送到包装实际 ListBox 控件的窗口的消息，其中包括来自控件的通知。 此示例将调用 SendMessage 以从控件获取信息并修改其内容。 下一节将详细介绍页面如何与控件通信。

> 请注意有两个平台调用声明 sendmessage。 这是必需的因为其中一个使用`wParam`要传递一个字符串和其他参数使用它来传递一个整数。 对于每个签名，都需要一个单独的声明，以确保正确封送数据。

```csharp
public partial class HostWindow : Window
{
int selectedItem;
IntPtr hwndListBox;
ControlHost listControl;
Application app;
Window myWindow;
int itemCount;

private void On_UIReady(object sender, EventArgs e)
{
  app = System.Windows.Application.Current;
  myWindow = app.MainWindow;
  myWindow.SizeToContent = SizeToContent.WidthAndHeight;
  listControl = new ControlHost(ControlHostElement.ActualHeight, ControlHostElement.ActualWidth);
  ControlHostElement.Child = listControl;
  listControl.MessageHook += new HwndSourceHook(ControlMsgFilter);
  hwndListBox = listControl.hwndListBox;
  for (int i = 0; i < 15; i++) //populate listbox
  {
    string itemText = "Item" + i.ToString();
    SendMessage(hwndListBox, LB_ADDSTRING, IntPtr.Zero, itemText);
  }
  itemCount = SendMessage(hwndListBox, LB_GETCOUNT, IntPtr.Zero, IntPtr.Zero);
  numItems.Text = "" +  itemCount.ToString();
}
```

C#复制

```csharp
private IntPtr ControlMsgFilter(IntPtr hwnd, int msg, IntPtr wParam, IntPtr lParam, ref bool handled)
{
  int textLength;

  handled = false;
  if (msg == WM_COMMAND)
  {
    switch ((uint)wParam.ToInt32() >> 16 & 0xFFFF) //extract the HIWORD
    {
      case LBN_SELCHANGE : //Get the item text and display it
        selectedItem = SendMessage(listControl.hwndListBox, LB_GETCURSEL, IntPtr.Zero, IntPtr.Zero);
        textLength = SendMessage(listControl.hwndListBox, LB_GETTEXTLEN, IntPtr.Zero, IntPtr.Zero);
        StringBuilder itemText = new StringBuilder();
        SendMessage(hwndListBox, LB_GETTEXT, selectedItem, itemText);
        selectedText.Text = itemText.ToString();
        handled = true;
        break;
    }
  }
  return IntPtr.Zero;
}
internal const int
  LBN_SELCHANGE = 0x00000001,
  WM_COMMAND = 0x00000111,
  LB_GETCURSEL = 0x00000188,
  LB_GETTEXTLEN = 0x0000018A,
  LB_ADDSTRING = 0x00000180, 
  LB_GETTEXT = 0x00000189,
  LB_DELETESTRING = 0x00000182,
  LB_GETCOUNT = 0x0000018B;

[DllImport("user32.dll", EntryPoint = "SendMessage", CharSet = CharSet.Unicode)]
internal static extern int SendMessage(IntPtr hwnd,
                                       int msg,
                                       IntPtr wParam,
                                       IntPtr lParam);

[DllImport("user32.dll", EntryPoint = "SendMessage", CharSet = CharSet.Unicode)]
internal static extern int SendMessage(IntPtr hwnd,
                                       int msg,
                                       int wParam, 
                                       [MarshalAs(UnmanagedType.LPWStr)] StringBuilder lParam);

[DllImport("user32.dll", EntryPoint = "SendMessage", CharSet = CharSet.Unicode)]
internal static extern IntPtr SendMessage(IntPtr hwnd,
                                          int msg,
                                          IntPtr wParam,
                                          String lParam);
```

### 在控件和页面之间的实现通信

通过将其发送 Windows 消息操作控件。 当用户与控件交互时，控件会通过向其宿主窗口发送通知来通知你。 [中承载 Win32 ListBox 控件在 WPF 中](https://github.com/Microsoft/WPF-Samples/tree/master/Migration%20and%20Interoperability/WPFHostingWin32Control)示例包含一个用户界面，提供了几个示例的工作方式：

- 向列表中追加项。
- 从列表中删除选定项
- 显示当前选定项的文本。
- 显示列表中的项数。

用户还可以选择某个项的列表框中单击它，就像传统的 Win32 应用程序。 每当用户通过选择、添加或追加项来更改列表框的状态时，都将更新所显示的数据。

若要追加项，将发送列表框[`LB_ADDSTRING`消息](https://msdn.microsoft.com/library/windows/desktop/bb775181(v=vs.85).aspx)。 若要删除项，请发送[ `LB_GETCURSEL` ](https://msdn.microsoft.com/library/windows/desktop/bb775197(v=vs.85).aspx)若要获取当前所选内容的索引，然后[ `LB_DELETESTRING` ](https://msdn.microsoft.com/library/windows/desktop/bb775183(v=vs.85).aspx)删除的项。 该示例还会发送[ `LB_GETCOUNT` ](https://msdn.microsoft.com/library/windows/desktop/bb775195(v=vs.85).aspx)，并使用返回的值来更新显示的项数的显示。 这两个实例的[ `SendMessage` ](https://msdn.microsoft.com/library/windows/desktop/ms644950(v=vs.85).aspx)使用上一节所述的 PInvoke 声明之一。

```csharp
private void AppendText(object sender, EventArgs args)
{
  if (!string.IsNullOrEmpty(txtAppend.Text))
  {
    SendMessage(hwndListBox, LB_ADDSTRING, IntPtr.Zero, txtAppend.Text);
  }
  itemCount = SendMessage(hwndListBox, LB_GETCOUNT, IntPtr.Zero, IntPtr.Zero);
  numItems.Text = "" + itemCount.ToString();
}
private void DeleteText(object sender, EventArgs args)
{
  selectedItem = SendMessage(listControl.hwndListBox, LB_GETCURSEL, IntPtr.Zero, IntPtr.Zero);
  if (selectedItem != -1) //check for selected item
  {
    SendMessage(hwndListBox, LB_DELETESTRING, (IntPtr)selectedItem, IntPtr.Zero);
  }
  itemCount = SendMessage(hwndListBox, LB_GETCOUNT, IntPtr.Zero, IntPtr.Zero);
  numItems.Text = "" + itemCount.ToString();
}
```

当用户选择一项或更改其选择时，控件通过将其发送通知宿主窗口[`WM_COMMAND`消息](https://msdn.microsoft.com/library/windows/desktop/ms647591(v=vs.85).aspx)，这会引发[MessageHook](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost.messagehook)事件页。 处理程序将接收到与宿主窗口的主窗口过程相同的信息。 它还将为布尔值的引用`handled`。 您设置`handled`到`true`指示已经处理该消息，且不进行其他处理需要。

[`WM_COMMAND`](https://msdn.microsoft.com/library/windows/desktop/ms647591(v=vs.85).aspx) 将发送的原因，有多种，因此必须检查通知 ID 以确定它是否是你想要处理的事件。 高位字中包含的 ID`wParam`参数。 该示例使用按位运算符提取该 id。 如果用户已选择或更改其选择，该 ID 将是[ `LBN_SELCHANGE`](https://msdn.microsoft.com/library/windows/desktop/bb775161(v=vs.85).aspx)。

当[ `LBN_SELCHANGE` ](https://msdn.microsoft.com/library/windows/desktop/bb775161(v=vs.85).aspx)是收到，该示例通过向控件发送中获取选定项的索引[`LB_GETCURSEL`消息](https://msdn.microsoft.com/library/windows/desktop/bb775197(v=vs.85).aspx)。 若要获取文本，请先创建[StringBuilder](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.stringbuilder)。 然后发送该控件[`LB_GETTEXT`消息](https://msdn.microsoft.com/library/windows/desktop/bb761313(v=vs.85).aspx)。 传递空[StringBuilder](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.stringbuilder)对象作为`wParam`参数。 当[ `SendMessage` ](https://msdn.microsoft.com/library/windows/desktop/ms644950(v=vs.85).aspx)返回，[StringBuilder](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.stringbuilder)将包含所选的项的文本。 这种用法[ `SendMessage` ](https://msdn.microsoft.com/library/windows/desktop/ms644950(v=vs.85).aspx)需要另一种 PInvoke 声明。

最后，设置`handled`到`true`以指示消息已得到处理。

## [Walkthrough: Hosting WPF Content in Win32](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/walkthrough-hosting-wpf-content-in-win32)

Windows Presentation Foundation (WPF) 提供了用于创建应用程序的丰富环境。 但是，当你对 Win32 代码有大量投入时，向应用程序添加 WPF 功能（而不是重写原始代码）可能更有效。 WPF 提供了一个简单的机制，用于托管WPF中的内容Win32窗口。

本教程介绍如何编写示例应用程序，[在 Win32 窗口示例中承载 WPF 内容](https://go.microsoft.com/fwlink/?LinkID=160004)，则该主机WPF中的内容Win32窗口。你可以扩展此示例，使其可托管任何 Win32 窗口。 由于涉及混合托管代码和非托管代码，应用程序是在C++/CLI 中编写的。



### 要求

本教程假定你已基本熟悉 WPF 和 Win32 编程。 有关的基本介绍WPF编程，请参见[Getting Started](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/getting-started/index)。 以大致Win32进行编程，可参考有关该主题的众多书籍特别*编程 Windows* Charles Petzold 的。

由于此教程中随附的示例实现中，因此C++/CLI，本教程假定你熟悉使用C++编程Win32API并且了解托管的代码编程。 熟悉 C++/CLI 将有所帮助，但并非必备条件。

> 本教程包括来自相关示例的一些代码示例。 但是，出于可读性考虑，不包括完整的示例代码。 有关完整的示例代码，请参阅[承载 WPF 内容在 Win32 窗口示例中](https://go.microsoft.com/fwlink/?LinkID=160004)。

### 基本过程

本部分概述了使用到的基本过程主机WPF中的内容Win32窗口。 其余章节说明每个步骤的详细内容。

托管的关键WPF上的内容Win32窗口是[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)类。 此类将包装WPF中的内容Win32窗口中，使其能够合并到您用户界面 (UI)用作子窗口。 以下方法在单个应用程序中合并 Win32 和 WPF。

1. 实现你WPF内容作为托管类。
2. 使用 Win32 实现 C++/CLI 应用程序。 如果从现有应用程序和非托管 C++ 代码开始，你通常可以通过更改项目设置以包括 `/clr` 编译器标志来使其可以调用托管代码。
3. 将线程处理模型设置为单线程单元 (STA)。
4. 处理[WM_CREATE](https://docs.microsoft.com/zh-cn/windows/desktop/winmsg/wm-create)中窗口过程并执行以下通知：
   1. 创建一个新的 [HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource) 对象，将父窗口用作其 `parent` 参数。
   2. 创建 WPF 内容类的一个实例。
   3. 将分配到的引用WPF内容对象[RootVisual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource.rootvisual)属性的[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)。
   4. 获取该内容的 HWND。 [Handle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource.handle) 对象的 [HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource) 属性包含窗口句柄 (HWND)。 要获取可在应用程序的非托管部分中使用的 HWND，需将 `Handle.ToPointer()` 强制装换为 HWND。
5. 实现一个托管类，该类包含一个用于保存对 WPF 内容的引用的静态字段。 该类使你可以从 WPF 代码获取对 Win32 内容的引用。
6. 向静态字段分配 WPF 内容。
7. 接收来自通知WPF通过将一个处理程序附加到一个或多个内容WPF事件。
8. 通过使用存储在静态字段中用于设置属性等的引用来与 WPF 内容通信。

 备注

此外可以使用可扩展应用程序标记语言 (XAML)来实现您WPF内容。 但是，你必须将其作为 动态链接库 (DLL) 单独编译并从 DLL 应用程序引用 Win32。 该过程的其余部分与上述相似。



#### 实现主机应用程序

本部分介绍如何对主机WPF内容在基本Win32应用程序。 该内容本身是在 C++/CLI 中作为托管类实现的。 大多数情况下，它是简单的 WPF 编程。 对内容实现的关键方面中讨论[实现 WPF 内容](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/walkthrough-hosting-wpf-content-in-win32#implementing_the_wpf_page)。



- [基本应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/walkthrough-hosting-wpf-content-in-win32#the_basic_application)
- [承载 WPF 内容](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/walkthrough-hosting-wpf-content-in-win32#hosting_the_wpf_page)
- [保存对 WPF 内容的引用](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/walkthrough-hosting-wpf-content-in-win32#holding_a_reference)
- [与 WPF 内容通信](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/walkthrough-hosting-wpf-content-in-win32#communicating_with_the_page)

#### 基本应用程序

主机应用程序的起点是创建 Visual Studio 2005 模板。

1. 打开 Visual Studio 2005 中，并选择**新的项目**从**文件**菜单。
2. 选择**Win32**从列表中的Visual C++项目类型。 如果默认语言不是C++，你会发现这些项目类型下的**其他语言**。
3. 选择**Win32 项目**模板，为项目分配一个名称，然后单击**确定**以启动**Win32 应用程序向导**。
4. 接受向导的默认设置，然后单击**完成**以启动项目。

该模板将创建一个基本的 Win32 应用程序，包括：

- 应用程序的入口点。
- 一个窗口和关联的窗口过程 (WndProc)。
- 使用菜单**文件**并**帮助**标题。 **文件**菜单还拥有**退出**关闭应用程序的项。 **帮助**菜单还拥有**有关**启动简单的对话框中的项。

在开始编写代码以承载之前WPF内容，您需要做两项修改对基本模板。

第一项是将项目作为托管代码进行编译。 默认情况下，项目将作为非托管代码进行编译。 但是，由于 WPF 是在托管代码中实现的，因此必须将项目进行相应编译。

1. 右键单击项目名称在**解决方案资源管理器**，然后选择**属性**从上下文菜单以启动**属性页**对话框。
2. 选择**配置属性**从左窗格中的树视图。
3. 选择**公共语言运行时**支持从**项目默认值**右窗格中的列表。
4. 选择**公共语言运行时支持 (/ clr)** 从下拉列表框。

 备注

此编译器标志使你能够在应用程序中使用托管代码，但非托管代码将仍将像以前一样进行编译。

WPF 使用单线程单元 (STA) 线程处理模型。 为了正常使用WPF内容代码，您必须在应用程序的线程模型设置为 STA 通过将属性应用于入口点。

C++复制

```cpp
[System::STAThreadAttribute] //Needs to be an STA thread to play nicely with WPF
int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
```



#### 承载 WPF 内容

WPF内容是简单的地址条目应用程序。 它包含若干个 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 控件，这些控件用于获得用户名称、地址等。 还有两个[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)控件，**确定**并**取消**。 当用户单击**确定**，该按钮的[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件处理程序收集的数据从[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控件，将其分配给相应的属性，并引发自定义事件， `OnButtonClicked`。 当用户单击**取消**，该处理程序只需引发`OnButtonClicked`。 `OnButtonClicked` 的事件参数对象包含布尔型字段，用于指示被单击的按钮。

到主机的代码WPF内容的处理程序中实现[WM_CREATE](https://docs.microsoft.com/zh-cn/windows/desktop/winmsg/wm-create)主机窗口上的通知。

```cpp
case WM_CREATE :
  GetClientRect(hWnd, &rect);
  wpfHwnd = GetHwnd(hWnd, rect.right-375, 0, 375, 250);
  CreateDataDisplay(hWnd, 275, rect.right-375, 375);
  CreateRadioButtons(hWnd);
break;
```

`GetHwnd`方法使用大小和位置信息以及父窗口句柄并返回所承载的窗口句柄WPF内容。

> 无法对 `#using` 命名空间使用 `System::Windows::Interop` 指令。 如果进行此操作，将造成该命名空间中的 [MSG](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.msg) 结构和在 winuser.h 中声明的 MSG 结构之间的名称冲突。 必须使用完全限定名来访问该命名空间的内容。

```cpp
HWND GetHwnd(HWND parent, int x, int y, int width, int height)
{
    System::Windows::Interop::HwndSourceParameters^ sourceParams = gcnew System::Windows::Interop::HwndSourceParameters(
    "hi" // NAME
    );
    sourceParams->PositionX = x;
    sourceParams->PositionY = y;
    sourceParams->Height = height;
    sourceParams->Width = width;
    sourceParams->ParentWindow = IntPtr(parent);
    sourceParams->WindowStyle = WS_VISIBLE | WS_CHILD; // style
    System::Windows::Interop::HwndSource^ source = gcnew System::Windows::Interop::HwndSource(*sourceParams);
    WPFPage ^myPage = gcnew WPFPage(width, height);
    //Assign a reference to the WPF page and a set of UI properties to a set of static properties in a class
    //that is designed for that purpose.
    WPFPageHost::hostedPage = myPage;
    WPFPageHost::initBackBrush = myPage->Background;
    WPFPageHost::initFontFamily = myPage->DefaultFontFamily;
    WPFPageHost::initFontSize = myPage->DefaultFontSize;
    WPFPageHost::initFontStyle = myPage->DefaultFontStyle;
    WPFPageHost::initFontWeight = myPage->DefaultFontWeight;
    WPFPageHost::initForeBrush = myPage->DefaultForeBrush;
    myPage->OnButtonClicked += gcnew WPFPage::ButtonClickHandler(WPFButtonClicked);
    source->RootVisual = myPage;
    return (HWND) source->Handle.ToPointer();
}
```

不能承载WPF内容直接在应用程序窗口中。 从而，首先创建 [HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource) 对象以包装 WPF 内容。 此对象基本上是一个窗口，专门用于托管WPF内容。 托管[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)通过创建作为子级的父窗口中的对象Win32属于你的应用程序的窗口。 [HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource) 构造函数参数所包含的信息与创建 Win32 子窗口时要传递给 CreateWindow 的信息基本相同。

下一步创建的实例WPF内容对象。 在此情况下，通过使用 WPF，将 `WPFPage` 内容作为单独的类 C++/CLI 实现。还可以使用 WPF 实现 XAML 内容。 但是，若要执行此操作需要设置一个单独的项目并生成WPF内容作为DLL。可以向项目添加对 DLL 的引用，并使用该引用创建 WPF 内容的实例。

显示WPF中通过的引用分配给在子窗口的内容WPF内容[RootVisual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource.rootvisual)属性的[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)。

代码的下一行将一个事件处理程序 `WPFButtonClicked` 附加到 WPF 内容 `OnButtonClicked` 事件。 当用户单击时调用此处理程序**确定**或**取消**按钮。 请参阅[wpf 内容通信](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/walkthrough-hosting-wpf-content-in-win32#communicating_with_the_page)有关此事件处理程序的进一步讨论。

代码显示的最后一行返回与 [HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource) 对象关联的窗口句柄 (HWND)。 可以从 Win32 代码使用此句柄，将消息发送到托管窗口，尽管该示例并未执行这一操作。 每当 [HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource) 对象收到一条消息时就会引发一个事件。若要处理消息，请调用 [AddHook](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource.addhook) 方法来附加消息处理程序，然后在此处理程序中处理消息。

#### 保存对 WPF 内容的引用

对于许多应用程序，你将需要稍后与 WPF 内容进行通信。 例如，可能需要修改 WPF 内容属性，或可能让 [HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource) 对象托管不同的 WPF 内容。 执行此操作需要对 [HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource) 对象或 WPF 内容的引用。[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource) 对象及其关联 WPF 内容保留在内存中，直到销毁窗口句柄。 但是，一旦从窗口过程返回，分配给 [HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource) 对象的变量就将超出范围。 用来处理 Win32 应用程序的这一问题的惯用方法是使用静态或全局变量。 遗憾的是，你无法向这些类型的变量分配托管对象。 可以向全局或静态变量分配与 [HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource) 对象关联的窗口句柄，但这一操作不会提供对对象本身的访问。

针对这一问题最简单的解决方案是实现一个托管类，该类包含一组静态字段，这些字段保存对需要访问的任何托管对象的引用。 此示例使用 `WPFPageHost` 类来保存对 WPF 内容的引用，以及对该内容某些属性的初始值的引用（用户以后可能会对这些属性进行更改）。 这在标头中进行定义。

```cpp
public ref class WPFPageHost
{
public:
  WPFPageHost();
  static WPFPage^ hostedPage;
  //initial property settings
  static System::Windows::Media::Brush^ initBackBrush;
  static System::Windows::Media::Brush^ initForeBrush;
  static System::Windows::Media::FontFamily^ initFontFamily;
  static System::Windows::FontStyle initFontStyle;
  static System::Windows::FontWeight initFontWeight;
  static double initFontSize;
};
```

`GetHwnd` 函数的后半部分将值分配给这些字段以供以后使用（在 `myPage` 仍处于范围内时）。

#### 与 WPF 内容通信

与 WPF 内容的通信有两种类型。 应用程序收到来自信息WPF内容在用户单击时**确定**或**取消**按钮。 该应用程序还具有 UI，使用户可以更改各种 WPF 内容属性，例如背景色或默认字体大小。

如上所述，用户单击任一按钮时，WPF 内容将引发 `OnButtonClicked` 事件。 该应用程序将一个处理程序附加到此事件以接收这些通知。 如果**确定**所单击的按钮，该处理程序将获取用户信息从WPF内容，并在一组静态控件中显示它。

```cpp
void WPFButtonClicked(Object ^sender, MyPageEventArgs ^args)
{
    if(args->IsOK) //display data if OK button was clicked
    {
        WPFPage ^myPage = WPFPageHost::hostedPage;
        LPCWSTR userName = (LPCWSTR) InteropServices::Marshal::StringToHGlobalAuto("Name: " + myPage->EnteredName).ToPointer();
        SetWindowText(nameLabel, userName);
        LPCWSTR userAddress = (LPCWSTR) InteropServices::Marshal::StringToHGlobalAuto("Address: " + myPage->EnteredAddress).ToPointer();
        SetWindowText(addressLabel, userAddress);
        LPCWSTR userCity = (LPCWSTR) InteropServices::Marshal::StringToHGlobalAuto("City: " + myPage->EnteredCity).ToPointer();
        SetWindowText(cityLabel, userCity);
        LPCWSTR userState = (LPCWSTR) InteropServices::Marshal::StringToHGlobalAuto("State: " + myPage->EnteredState).ToPointer();
        SetWindowText(stateLabel, userState);
        LPCWSTR userZip = (LPCWSTR) InteropServices::Marshal::StringToHGlobalAuto("Zip: " + myPage->EnteredZip).ToPointer();
        SetWindowText(zipLabel, userZip);
    }
    else
    {
        SetWindowText(nameLabel, L"Name: ");
        SetWindowText(addressLabel, L"Address: ");
        SetWindowText(cityLabel, L"City: ");
        SetWindowText(stateLabel, L"State: ");
        SetWindowText(zipLabel, L"Zip: ");
    }
}
```

该处理程序从 WPF 内容接收到一个自定义事件参数对象 `MyPageEventArgs`。 对象的`IsOK`属性设置为`true`如果**确定**所单击的按钮和`false`如果**取消**所单击的按钮。

如果**确定**所单击的按钮，该处理程序将获取对引用WPFcontainer 类中的内容。 然后它会收集由关联的 WPF 内容属性保存的用户信息，并使用静态控件在父窗口上显示该信息。 由于 WPF 内容数据的形式为托管字符串，因此必须对其进行封送处理以供 Win32 控件使用。 如果**取消**所单击的按钮，该处理程序将清除静态控件中的数据。

应用程序 UI 提供一组单选按钮，允许用户修改 WPF 内容的背景色和若干与字体相关的属性。 下面的示例是应用程序的窗口过程 (WndProc) 的一段摘录及其消息处理功能，通过该功能可设置不同消息上的各种属性，包括背景色。 其他内容与此类似，将不进行展示。 请查看完整示例了解详细信息和上下文。

C++复制

```cpp
case WM_COMMAND:
  wmId    = LOWORD(wParam);
  wmEvent = HIWORD(wParam);

  switch (wmId)
  {
  //Menu selections
    case IDM_ABOUT:
      DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
    break;
    case IDM_EXIT:
      DestroyWindow(hWnd);
    break;
    //RadioButtons
    case IDC_ORIGINALBACKGROUND :
      WPFPageHost::hostedPage->Background = WPFPageHost::initBackBrush;
    break;
    case IDC_LIGHTGREENBACKGROUND :
      WPFPageHost::hostedPage->Background = gcnew SolidColorBrush(Colors::LightGreen);
    break;
    case IDC_LIGHTSALMONBACKGROUND :
      WPFPageHost::hostedPage->Background = gcnew SolidColorBrush(Colors::LightSalmon);
    break;
```

若要设置背景色，请从 WPF 获取对 `hostedPage` 内容 (`WPFPageHost`) 的引用并将背景色属性设置为适当的颜色。此示例使用三种颜色选项：原始颜色、浅绿色或浅橙红色。 原始背景色作为静态字段存储在 `WPFPageHost` 类中。 若要设置其他两种颜色，请创建一个新的 [SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush) 对象，并从 [Colors](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.colors) 对象向构造函数传递一个静态颜色值。



### 实现 WPF 页

可以托管和使用WPF内容而无需任何有关实际实现的知识。 如果WPF内容已打包在一个单独DLL，它可以将其内置于任何公共语言运行时 (CLR)语言。 以下是在该示例中使用的 C++/CLI 实现的简短演练。 本节包含下列子节。

- [布局](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/walkthrough-hosting-wpf-content-in-win32#page_layout)
- [将数据返回到主机窗口](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/walkthrough-hosting-wpf-content-in-win32#returning_data_to_window)
- [设置 WPF 属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/walkthrough-hosting-wpf-content-in-win32#set_page_properties)

#### 布局

UI中的元素WPF内容包含的五个[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控制，与关联[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)控件：名称、 地址、 城市、 州和 Zip。 还有两个[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)控件，**确定**和**取消**

WPF 内容在 `WPFPage` 类中实现。 布局通过 [Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid) 布局元素进行处理。 该类继承自实际使其成为 [Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid) 内容根元素的 WPF。

WPF内容的构造函数采用所需的宽度和高度和大小[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)相应地。 然后，它定义基本布局通过创建一套[ColumnDefinition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.columndefinition)并[RowDefinition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.rowdefinition)对象并将它们添加到[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)基对象[ColumnDefinitions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid.columndefinitions)和[RowDefinitions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid.rowdefinitions)集合，分别。 这将定义具有 5 行和 7 列的网格，该网格具有单元内容定义的维度。

```cpp
WPFPage::WPFPage(int allottedWidth, int allotedHeight)
{
  array<ColumnDefinition ^> ^ columnDef = gcnew array<ColumnDefinition ^> (4);
  array<RowDefinition ^> ^ rowDef = gcnew array<RowDefinition ^> (6);

  this->Height = allotedHeight;
  this->Width = allottedWidth;
  this->Background = gcnew SolidColorBrush(Colors::LightGray);
  
  //Set up the Grid's row and column definitions
  for(int i=0; i<4; i++)
  {
    columnDef[i] = gcnew ColumnDefinition();
    columnDef[i]->Width = GridLength(1, GridUnitType::Auto);
    this->ColumnDefinitions->Add(columnDef[i]);
  }
  for(int i=0; i<6; i++)
  {
    rowDef[i] = gcnew RowDefinition();
    rowDef[i]->Height = GridLength(1, GridUnitType::Auto);
    this->RowDefinitions->Add(rowDef[i]);
  }
```

接下来，此构造函数将 UI 元素添加到 [Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)。 第一个元素是标题文本，这是一个在网格首行居中的 [Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label) 控件。

C++复制

```cpp
//Add the title
titleText = gcnew Label();
titleText->Content = "Simple WPF Control";
titleText->HorizontalAlignment = System::Windows::HorizontalAlignment::Center;
titleText->Margin = Thickness(10, 5, 10, 0);
titleText->FontWeight = FontWeights::Bold;
titleText->FontSize = 14;
Grid::SetColumn(titleText, 0);
Grid::SetRow(titleText, 0);
Grid::SetColumnSpan(titleText, 4);
this->Children->Add(titleText);
```

下一行包含名称 [Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label) 控制及其关联的 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 控件。 由于对每个标签/文本框对使用同一代码，因而该代码被置于一对专用方法内并用于所有五个标签/文本框对。 该方法创建相应的控件，并调用 [Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid) 类静态 [SetColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid.setcolumn) 和 [SetRow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid.setrow) 方法，以将控件置于相应单元格内。 创建控件后，该示例对 [Add](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.uielementcollection.add) 的 [Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.children) 属性调用 [Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid) 方法，以便将控件添加到网格。 用于添加剩余标签/文本框对的代码相似。 请参阅示例代码了解详细信息。

C++复制

```cpp
//Add the Name Label and TextBox
nameLabel = CreateLabel(0, 1, "Name");
this->Children->Add(nameLabel);
nameTextBox = CreateTextBox(1, 1, 3);
this->Children->Add(nameTextBox);
```

这两种方法的实现如下所示：

C++复制

```cpp
Label ^WPFPage::CreateLabel(int column, int row, String ^ text)
{
  Label ^ newLabel = gcnew Label();
  newLabel->Content = text;
  newLabel->Margin = Thickness(10, 5, 10, 0);
  newLabel->FontWeight = FontWeights::Normal;
  newLabel->FontSize = 12;
  Grid::SetColumn(newLabel, column);
  Grid::SetRow(newLabel, row);
  return newLabel;
}
TextBox ^WPFPage::CreateTextBox(int column, int row, int span)
{
  TextBox ^newTextBox = gcnew TextBox();
  newTextBox->Margin = Thickness(10, 5, 10, 0);
  Grid::SetColumn(newTextBox, column);
  Grid::SetRow(newTextBox, row);
  Grid::SetColumnSpan(newTextBox, span);
  return newTextBox;
}
```

最后，该示例添加**确定**并**取消**按钮，并将附加到事件处理程序及其[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件。

```cpp
//Add the Buttons and atttach event handlers
okButton = CreateButton(0, 5, "OK");
cancelButton = CreateButton(1, 5, "Cancel");
this->Children->Add(okButton);
this->Children->Add(cancelButton);
okButton->Click += gcnew RoutedEventHandler(this, &WPFPage::ButtonClicked);
cancelButton->Click += gcnew RoutedEventHandler(this, &WPFPage::ButtonClicked);
```

#### 将数据返回到主机窗口

单击任一按钮后，将引发其 [Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click) 事件。 主机窗口只需将处理程序附加到这些事件，然后直接从 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 控件获取数据。 此示例使用的是不太直接的方法。 它处理[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)内WPF内容，，然后引发自定义事件`OnButtonClicked`，以通知WPF内容。 这允许WPF内容，以执行通知主机之前某些参数验证。 该处理程序从 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 控件获取文本，然后将其分配给公共属性（主机可从其中检索信息）。

WPFPage.h 中的事件声明：

```cpp
public:
  delegate void ButtonClickHandler(Object ^, MyPageEventArgs ^);
  WPFPage();
  WPFPage(int height, int width);
  event ButtonClickHandler ^OnButtonClicked;
```

WPFPage.cpp 中的 [Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click) 事件处理程序：

```cpp
void WPFPage::ButtonClicked(Object ^sender, RoutedEventArgs ^args)
{

  //TODO: validate input data
  bool okClicked = true;
  if(sender == cancelButton)
    okClicked = false;
  EnteredName = nameTextBox->Text;
  EnteredAddress = addressTextBox->Text;
  EnteredCity = cityTextBox->Text;
  EnteredState = stateTextBox->Text;
  EnteredZip = zipTextBox->Text;
  OnButtonClicked(this, gcnew MyPageEventArgs(okClicked));
}
```

### 设置 WPF 属性

Win32主机使用户可以更改若干WPF内容属性。 就 Win32 端而言，这只是更改属性的问题。 WPF 内容类中的实现从某种意义上来说更加复杂，因为不存在控制所有控件的字体的单个全局属性。 相反，每个控件的相应属性均是在属性的 set 访问器中进行更改的。 下面的示例演示的代码`DefaultFontFamily`属性。 设置属性将调用专用方法，该方法依次又将为各控件设置 [FontFamily](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontfamily) 属性。

从 WPFPage.h：

```cpp
property FontFamily^ DefaultFontFamily
{
  FontFamily^ get() {return _defaultFontFamily;}
  void set(FontFamily^ value) {SetFontFamily(value);}
};
```

从 WPFPage.cpp：

```cpp
void WPFPage::SetFontFamily(FontFamily^ newFontFamily)
{
  _defaultFontFamily = newFontFamily;
  titleText->FontFamily = newFontFamily;
  nameLabel->FontFamily = newFontFamily;
  addressLabel->FontFamily = newFontFamily;
  cityLabel->FontFamily = newFontFamily;
  stateLabel->FontFamily = newFontFamily;
  zipLabel->FontFamily = newFontFamily;
}
```

## [Walkthrough: Hosting a WPF Clock in Win32](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/walkthrough-hosting-a-wpf-clock-in-win32)

若要将放WPF内Win32应用程序，使用[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)，其中提供了包含的 HWND 你WPF内容。 首先创建[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)，为其赋予类似于 CreateWindow 的参数。 然后，通知[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)有关WPF您要在其中包含内容。最后，获取共 HWND [HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)。 本演练演示如何创建混合WPF内Win32重新实现操作系统的应用程序**日期和时间属性**对话框。

### 系统必备

请参阅[WPF 和 Win32 互操作](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/wpf-and-win32-interoperation)。

### 如何使用本教程

本教程重点介绍生成互操作应用程序的重要步骤。 本教程采用一个示例中， [Win32 时钟互操作示例](https://go.microsoft.com/fwlink/?LinkID=160051)，但该示例是反映的最终产品。 本教程中介绍的步骤，因为如果您正在开始与某个现有Win32你自己的项目，可能是一个预先存在的项目，添加一个承载WPF到你的应用程序。 您可以比较将最终产品与[Win32 时钟互操作示例](https://go.microsoft.com/fwlink/?LinkID=160051)。

### Win32 中的 Windows Presentation Framework 的演练 (HwndSource)

下图显示了本教程的预期最终产品：

![“日期和时间属性”对话框](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/interoparch06.png)

可以通过创建 c + + 重新创建此对话框Win32项目中Microsoft Visual Studio，并使用对话框编辑器创建以下：

![“日期和时间属性”对话框](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/interoparch07.png)

(不需要使用Microsoft Visual Studio若要使用[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)，并且不需要使用 c + + 编写Win32程序，但这是相当典型的方法来执行此操作，并且非常适合用于分布教程说明)。

您需要完成五个特定的子步骤才能将放置WPF时钟在对话框：

1. 启用您Win32项目，以调用托管的代码 (**/clr**) 通过更改项目设置中的Microsoft Visual Studio。
2. 创建WPF[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)在单独的 DLL 中。
3. 将它放WPF[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)内[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)。
4. 为此，获取 HWND[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)使用[Handle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource.handle)属性。
5. 使用Win32若要决定在何处放置 HWND 内较大Win32应用程序

###  /clr

第一步是将此非托管Win32项目转换成了一可调用托管代码。 使用 /clr 编译器选项，它将链接到你想要使用，并调整与一起使用的 Main 方法所需的 Dll WPF。

若要启用 c + + 项目内的托管代码使用：右键单击 win32clock 项目，然后选择**属性**。 上**常规**属性页 （默认值），更改到的公共语言运行时支持`/clr`。

接下来，添加对所需的 Dll 的引用WPF:PresentationCore.dll、 PresentationFramework.dll、 System.dll、 WindowsBase.dll、 UIAutomationProvider.dll 和 UIAutomationTypes.dll。 （以下说明假定操作系统安装在 C: 驱动器上。）

1. 右键单击 win32clock 项目，然后选择**引用...**，并在该对话框：
2. 右键单击 win32clock 项目，然后选择**引用...**.
3. 单击**添加新引用**、 单击浏览选项卡中，输入 C:\Program Files\Reference Assemblies\Microsoft\Framework\v3.0\PresentationCore.dll，并单击确定。
4. 对 PresentationFramework.dll 重复：C:\Program Files\Reference Assemblies\Microsoft\Framework\v3.0\PresentationFramework.dll.
5. 对 WindowsBase.dll 重复：C:\Program Files\Reference Assemblies\Microsoft\Framework\v3.0\WindowsBase.dll。
6. 对 UIAutomationTypes.dll 重复：C:\Program Files\Reference Assemblies\Microsoft\Framework\v3.0\UIAutomationTypes.dll.
7. 对 UIAutomationProvider.dll 重复：C:\Program Files\Reference Assemblies\Microsoft\Framework\v3.0\UIAutomationProvider.dll.
8. 单击**添加新引用**，选择 System.dll，然后单击**确定**。
9. 单击**确定**退出用于添加引用的 win32clock 属性页。

最后，添加`STAThreadAttribute`到`_tWinMain`方法用于WPF:

复制

```
[System::STAThreadAttribute]  
int APIENTRY _tWinMain(HINSTANCE hInstance,  
                     HINSTANCE hPrevInstance,  
                     LPTSTR    lpCmdLine,  
                     int       nCmdShow)  
```

此属性告知公共语言运行时 (CLR)，当它初始化组件对象模型 (COM)，它应使用单线程的单元模式 (STA) 所必需WPF (和Windows 窗体)。

### 创建 Windows Presentation Framework 页

接下来，创建一个 DLL，它定义WPF [Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)。 它通常是最简单的方法创建WPF[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)作为独立的应用程序，并编写和调试WPF部分通过这种方式。 完成后，该项目可以转换为 DLL，请右键单击项目，单击**属性**，转至该应用程序，并将输出类型更改为 Windows 类库。

WPF Dll 项目然后与组合Win32项目 （一个解决方案包含两个项目），右键单击解决方案，选择**添加 \ 现有项目**。

若要使用该WPFdllWin32项目中，您需要添加的引用：

1. 右键单击 win32clock 项目，然后选择**引用...**.
2. 单击**添加新引用**。
3. 单击“项目”选项卡。选择 WPFClock，单击“确定”。
4. 单击**确定**退出用于添加引用的 win32clock 属性页。

###  HwndSource

接下来，使用[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)以使WPF[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)看起来像 HWND。 将此代码块添加到 C++ 文件中：

复制

```
namespace ManagedCode  
{  
    using namespace System;  
    using namespace System::Windows;  
    using namespace System::Windows::Interop;  
    using namespace System::Windows::Media;  
  
    HWND GetHwnd(HWND parent, int x, int y, int width, int height) {  
        HwndSource^ source = gcnew HwndSource(  
            0, // class style  
            WS_VISIBLE | WS_CHILD, // style  
            0, // exstyle  
            x, y, width, height,  
            "hi", // NAME  
            IntPtr(parent)        // parent window   
            );  
  
        UIElement^ page = gcnew WPFClock::Clock();  
        source->RootVisual = page;  
        return (HWND) source->Handle.ToPointer();  
    }  
}  
}  
```

这是一长段代码，可以作一些解释。 第一部分是各种子句，无需完全限定所有调用：

复制

```
namespace ManagedCode  
{  
    using namespace System;  
    using namespace System::Windows;  
    using namespace System::Windows::Interop;  
    using namespace System::Windows::Media;  
```

然后，定义一个函数来创建WPF内容，put[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)围绕它，并返回 HWND:

复制

```
HWND GetHwnd(HWND parent, int x, int y, int width, int height) {  
```

首先创建[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)，其参数位于类似于 CreateWindow:

复制

```
HwndSource^ source = gcnew HwndSource(  
    0, // class style  
    WS_VISIBLE | WS_CHILD, // style  
    0, // exstyle  
    x, y, width, height,  
    "hi", // NAME  
    IntPtr(parent) // parent window   
    );  
```

然后创建WPF内容类通过调用其构造函数：

复制

```
UIElement^ page = gcnew WPFClock::Clock();  
```

然后连接到页[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource):

复制

```
source->RootVisual = page;  
```

最后一行中返回的 HWND 和[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource):

复制

```
return (HWND) source->Handle.ToPointer();  
```

### 放置 Hwnd

现在，已有包含 HWNDWPF时钟，你需要将该 HWNDWin32对话框。 如果你知道在何处放置 HWND，将只需传递该大小和位置到`GetHwnd`前面定义的函数。 但是，由于已使用资源文件来定义对话框，因此你不完全确定任何 HWND 的放置位置。 可以使用Microsoft Visual Studio对话框编辑器将放Win32静态控制想时钟 （"此处插入时钟"），并使用它来定位WPF时钟。

只要在处理 WM_INITDIALOG，就使用`GetDlgItem`检索占位符 STATIC 的 HWND:

复制

```
HWND placeholder = GetDlgItem(hDlg, IDC_CLOCK);  
```

然后，计算的大小和位置的该占位符 STATIC，以便可以将WPF时钟在该位置：

RECT 矩形；

复制

```
GetWindowRect(placeholder, &rectangle);  
int width = rectangle.right - rectangle.left;  
int height = rectangle.bottom - rectangle.top;  
POINT point;  
point.x = rectangle.left;  
point.y = rectangle.top;  
result = MapWindowPoints(NULL, hDlg, &point, 1);  
```

然后，你隐藏占位符 STATIC：

复制

```
ShowWindow(placeholder, SW_HIDE);  
```

并创建WPF时钟在该位置的 HWND:

复制

```
HWND clock = ManagedCode::GetHwnd(hDlg, point.x, point.y, width, height);  
```

为了使教程变得有趣，并生成真正WPF时钟，你将需要创建WPF此时时钟控件。 你可以在标记中执行大部分操作，代码隐藏中只有几个事件处理程序。 由于本教程是关于互操作而不是关于控件设计，完成代码WPF时钟提供作为代码块，而无需另外说明如何构建或每个部分的含义。 随意尝试此代码来更改控件的外观或功能。

此处为标记：

XAML复制

```xaml
<Page x:Class="WPFClock.Clock"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    >
    <Grid>
        <Grid.Background>
            <LinearGradientBrush StartPoint="0,0" EndPoint="0,1">
              <GradientStop Color="#fcfcfe" Offset="0" />
              <GradientStop Color="#f6f4f0" Offset="1.0" />
            </LinearGradientBrush>
        </Grid.Background>

        <Grid Name="PodClock" HorizontalAlignment="Center" VerticalAlignment="Center">
            <Grid.Resources>
                <Storyboard x:Key="sb">
                    <DoubleAnimation From="0" To="360" Duration="12:00:00" RepeatBehavior="Forever"
                        Storyboard.TargetName="HourHand"
                        Storyboard.TargetProperty="(Rectangle.RenderTransform).(RotateTransform.Angle)" 
                        />
                    <DoubleAnimation From="0" To="360" Duration="01:00:00" RepeatBehavior="Forever"
                        Storyboard.TargetName="MinuteHand"  
                        Storyboard.TargetProperty="(Rectangle.RenderTransform).(RotateTransform.Angle)"
                        />
                    <DoubleAnimation From="0" To="360" Duration="0:1:00" RepeatBehavior="Forever"
                        Storyboard.TargetName="SecondHand"  
                        Storyboard.TargetProperty="(Rectangle.RenderTransform).(RotateTransform.Angle)"
                        />
                </Storyboard>
            </Grid.Resources>

          <Ellipse Width="108" Height="108" StrokeThickness="3">
            <Ellipse.Stroke>
              <LinearGradientBrush>
                <GradientStop Color="LightBlue" Offset="0" />
                <GradientStop Color="DarkBlue" Offset="1" />
              </LinearGradientBrush>
            </Ellipse.Stroke>
          </Ellipse>
          <Ellipse VerticalAlignment="Center" HorizontalAlignment="Center" Width="104" Height="104" Fill="LightBlue" StrokeThickness="3">
            <Ellipse.Stroke>
              <LinearGradientBrush>
                <GradientStop Color="DarkBlue" Offset="0" />
                <GradientStop Color="LightBlue" Offset="1" />
              </LinearGradientBrush>
            </Ellipse.Stroke>          
          </Ellipse>
            <Border BorderThickness="1" BorderBrush="Black" Background="White" Margin="20" HorizontalAlignment="Right" VerticalAlignment="Center">
                <TextBlock Name="MonthDay" Text="{Binding}"/>
            </Border>
            <Canvas Width="102" Height="102">
                <Ellipse Width="8" Height="8" Fill="Black" Canvas.Top="46" Canvas.Left="46" />
                <Rectangle Canvas.Top="5" Canvas.Left="48" Fill="Black" Width="4" Height="8">
                    <Rectangle.RenderTransform>
                        <RotateTransform CenterX="2" CenterY="46" Angle="0" />
                    </Rectangle.RenderTransform>
                </Rectangle>
                <Rectangle Canvas.Top="5" Canvas.Left="49" Fill="Black" Width="2" Height="6">
                    <Rectangle.RenderTransform>
                        <RotateTransform CenterX="2" CenterY="46" Angle="30" />
                    </Rectangle.RenderTransform>
                </Rectangle>
                <Rectangle Canvas.Top="5" Canvas.Left="49" Fill="Black" Width="2" Height="6">
                    <Rectangle.RenderTransform>
                        <RotateTransform CenterX="2" CenterY="46" Angle="60" />
                    </Rectangle.RenderTransform>
                </Rectangle>
                <Rectangle Canvas.Top="5" Canvas.Left="48" Fill="Black" Width="4" Height="8">
                    <Rectangle.RenderTransform>
                        <RotateTransform CenterX="2" CenterY="46" Angle="90" />
                    </Rectangle.RenderTransform>
                </Rectangle>
                <Rectangle Canvas.Top="5" Canvas.Left="49" Fill="Black" Width="2" Height="6">
                    <Rectangle.RenderTransform>
                        <RotateTransform CenterX="2" CenterY="46" Angle="120" />
                    </Rectangle.RenderTransform>
                </Rectangle>
                <Rectangle Canvas.Top="5" Canvas.Left="49" Fill="Black" Width="2" Height="6">
                    <Rectangle.RenderTransform>
                        <RotateTransform CenterX="2" CenterY="46" Angle="150" />
                      </Rectangle.RenderTransform>
                    </Rectangle>
                    <Rectangle Canvas.Top="5" Canvas.Left="48" Fill="Black" Width="4" Height="8">
                      <Rectangle.RenderTransform>
                        <RotateTransform CenterX="2" CenterY="46" Angle="180" />
                    </Rectangle.RenderTransform>
                </Rectangle>
                <Rectangle Canvas.Top="5" Canvas.Left="49" Fill="Black" Width="2" Height="6">
                    <Rectangle.RenderTransform>
                        <RotateTransform CenterX="2" CenterY="46" Angle="210" />
                    </Rectangle.RenderTransform>
                </Rectangle>
                <Rectangle Canvas.Top="5" Canvas.Left="49" Fill="Black" Width="2" Height="6">
                    <Rectangle.RenderTransform>
                        <RotateTransform CenterX="2" CenterY="46" Angle="240" />
                    </Rectangle.RenderTransform>
                </Rectangle>
                <Rectangle Canvas.Top="5" Canvas.Left="48" Fill="Black" Width="4" Height="8">
                    <Rectangle.RenderTransform>
                        <RotateTransform CenterX="2" CenterY="46" Angle="270" />
                      </Rectangle.RenderTransform>
                    </Rectangle>
                    <Rectangle Canvas.Top="5" Canvas.Left="49" Fill="Black" Width="2" Height="6">
                      <Rectangle.RenderTransform>
                        <RotateTransform CenterX="2" CenterY="46" Angle="300" />
                    </Rectangle.RenderTransform>
                </Rectangle>
                <Rectangle Canvas.Top="5" Canvas.Left="49" Fill="Black" Width="2" Height="6">
                    <Rectangle.RenderTransform>
                        <RotateTransform CenterX="2" CenterY="46" Angle="330" />
                    </Rectangle.RenderTransform>
                </Rectangle>


                <Rectangle x:Name="HourHand" Canvas.Top="21" Canvas.Left="48" 
                            Fill="Black" Width="4" Height="30">
                    <Rectangle.RenderTransform>
                        <RotateTransform x:Name="HourHand2" CenterX="2" CenterY="30" />
                    </Rectangle.RenderTransform>
                </Rectangle>
                <Rectangle x:Name="MinuteHand" Canvas.Top="6" Canvas.Left="49" 
                        Fill="Black" Width="2" Height="45">
                    <Rectangle.RenderTransform>
                        <RotateTransform CenterX="1" CenterY="45" />
                    </Rectangle.RenderTransform>
                </Rectangle>
                <Rectangle x:Name="SecondHand" Canvas.Top="4" Canvas.Left="49" 
                        Fill="Red" Width="1" Height="47">
                    <Rectangle.RenderTransform>
                        <RotateTransform CenterX="0.5" CenterY="47" />
                    </Rectangle.RenderTransform>
                </Rectangle>
            </Canvas>
        </Grid>
    </Grid>
</Page>
```

以下是附带的代码隐藏：

C#复制

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Shapes;
using System.Windows.Threading;

namespace WPFClock
{
    /// <summary>
    /// Interaction logic for Clock.xaml
    /// </summary>
    public partial class Clock : Page
    {
        private DispatcherTimer _dayTimer;

        public Clock()
        {
            InitializeComponent();
            this.Loaded += new RoutedEventHandler(Clock_Loaded);

        }

        void Clock_Loaded(object sender, RoutedEventArgs e) {
            // set the datacontext to be today's date
            DateTime now = DateTime.Now;
            DataContext = now.Day.ToString();

            // then set up a timer to fire at the start of tomorrow, so that we can update
            // the datacontext
            _dayTimer = new DispatcherTimer();
            _dayTimer.Interval = new TimeSpan(1, 0, 0, 0) - now.TimeOfDay;
            _dayTimer.Tick += new EventHandler(OnDayChange);
            _dayTimer.Start();

            // finally, seek the timeline, which assumes a beginning at midnight, to the appropriate
            // offset
            Storyboard sb = (Storyboard)PodClock.FindResource("sb");
            sb.Begin(PodClock, HandoffBehavior.SnapshotAndReplace, true);
            sb.Seek(PodClock, now.TimeOfDay, TimeSeekOrigin.BeginTime);
        }

        private void OnDayChange(object sender, EventArgs e)
        {
            // date has changed, update the datacontext to reflect today's date
            DateTime now = DateTime.Now;
            DataContext = now.Day.ToString();
            _dayTimer.Interval = new TimeSpan(1, 0, 0, 0);
        }
    }
}
```

最终结果如下所示：

![“日期和时间属性”对话框](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/interoparch08.png)

若要进行比较将最终结果与生成此屏幕截图中的代码，请参阅[Win32 时钟互操作示例](https://go.microsoft.com/fwlink/?LinkID=160051)。