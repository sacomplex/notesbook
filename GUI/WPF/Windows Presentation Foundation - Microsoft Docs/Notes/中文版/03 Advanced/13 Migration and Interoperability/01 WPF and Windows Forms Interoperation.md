# [WPF and Windows Forms Interoperation](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/wpf-and-windows-forms-interoperation)

WPF 和 Windows 窗体 提供两种用于创建应用程序接口的不同体系结构。 [System.Windows.Forms.Integration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration)命名空间提供实现常见互操作方案的类。 实现互操作功能的两个关键类是[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)和[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)。 本主题介绍支持哪些互操作方案以及不支持哪些互操作方案。

 备注

关于*混合控件*方案，需要考虑一些特殊因素。 混合控件将一种技术中的控件嵌套于另一种技术中的控件。这也称为*嵌套互操作*。 *多级混合控件*具有多个级别的混合控件嵌套。 多级嵌套互操作的一个示例是包含WPF 控件的 Windows 窗体 控件，前者又包含另一个 Windows 窗体 控件。 不支持多级混合控件。



## 在 WPF 中承载 Windows 窗体控件

支持以下互操作方案时WPF控件承载 Windows 窗体控件：

- WPF 控件可以使用 XAML 承载一个或多个 Windows 窗体 控件。
- 它可以使用代码承载一个或多个 Windows 窗体 控件。
- 它可以承载包含其他 Windows 窗体 控件的 Windows 窗体 容器控件。
- 它可以承载具有 WPF 母版和 Windows 窗体 详细信息的母版/详细信息窗体。
- 它可以承载具有 Windows 窗体 母版和 WPF 详细信息的母版/详细信息窗体。
- 它可以承载一个或多个 ActiveX 控件。
- 它可以承载一个或多个复合控件。
- 它可以使用 可扩展应用程序标记语言 (XAML) 承载混合控件。
- 它可以使用代码承载混合控件。

### 布局支持

以下列表描述了已知的限制时[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素尝试将其承载Windows 窗体控制WPF布局系统。

- 某些情况下，不能调整 Windows 窗体 控件的大小，或者大小只能调整为特定尺寸。 例如， Windows 窗体[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.combobox)控件支持仅的单一高度由控件的字体大小定义。 在中WPF假定，元素可以垂直拉伸，托管的动态布局[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.combobox)控件不会按预期方式拉伸。
- 不能旋转或扭曲 Windows 窗体 控件。 例如，将用户界面旋转 90 度时，所承载的 Windows 窗体 控件将保持其垂直位置。
- 大多数情况下，Windows 窗体 控件不支持按比例缩放。 尽管该控件的整体尺寸将会缩放，但其子控件和组件元素可能不会按预期调整大小。 此限制取决于每个 Windows 窗体 控件支持缩放的程度。
- 在 WPF 用户界面中，可以更改元素的 z 顺序以控制重叠行为。 由于承载的 Windows 窗体 控件是在单独的 HWND 中绘制的，所以始终在 WPF 元素之上绘制它。
- Windows 窗体 控件支持基于字号的自动缩放。 在 WPF 用户界面中，更改字号不会改变整个布局的大小，但是可动态调整单个元素的大小。

### 环境属性

WPF 控件的某些环境属性具有 Windows 窗体 等效项。 这些环境属性传播到所承载Windows 窗体控件，并公开为公共属性上[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)控件。 [WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)控件将为每个WPF环境属性转换成其Windows 窗体等效。

有关详细信息，请参阅 [Windows 窗体和 WPF 属性映射](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/windows-forms-and-wpf-property-mapping)。

### 行为

下表介绍互操作行为。

| 行为                                               | 支持                                                         | 不支持                                                       |
| -------------------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 透明度                                             | Windows 窗体 控件呈现支持透明度。 父 WPF 控件的背景可以成为所承载的 Windows 窗体 控件的背景。 | 某些 Windows 窗体 控件不支持透明度。例如，[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.textbox)并[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.combobox)控件不会由托管时，透明WPF。 |
| Tab 键次序                                         | 所承载的 Windows 窗体 控件的 Tab 键顺序与这些控件承载于基于 Windows 窗体 的应用程序中时是相同的。  使用 Tab 键和 Shift+Tab 键从 WPF 控件切换到 Windows 窗体 控件将按常规方式工作。  Windows 窗体 具有的控件[TabStop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.tabstop)属性值为`false`时不会收到焦点用户使用 tab 键控件。  -每个[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)控件具有[TabIndex](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost.tabindex)值，该值确定何时的[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)控件接收焦点。 - Windows 窗体 内部包含的控件[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)容器按照指定的顺序[TabIndex](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.tabindex)属性。 从最后一个 Tab 键索引使用 Tab 键切换会将焦点置于下一个 WPF 控件上（若存在）。 如果不存在其他可聚焦的 WPF 控件，按 Tab 键将返回到 Tab 键顺序中的第一个 Windows 窗体 控件。 - [TabIndex](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost.tabindex) 控件内的值[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)相对于同级Windows 窗体中包含的控件[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)控件。 - 按 Tab 键遵循特定于控件的行为。 例如，按 TAB 键在[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.textbox)具有控件[AcceptsTab](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.textboxbase.acceptstab)属性值为`true`输入一个制表符，而不是移动焦点的文本框中。 | 不适用。                                                     |
| 使用箭头键导航                                     | 的使用箭头进行导航密钥存储在[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)控件是与普通的相同Windows 窗体容器控件：向上键和向左箭头键选择上一个控件，并向下箭头和向右箭头键选择下一个控件。 -从中包含的第一个控件的箭头和向左箭头键[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)控件执行相同的操作与 SHIFT + TAB 键盘快捷方式。 如果没有可获得焦点WPF控件，焦点会转移外部[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)控件。 此行为不同于标准[ContainerControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.containercontrol)中的行为不会包装到最后一个控件时发生。 如果不存在其他可聚焦的 WPF 控件，焦点将返回到 Tab 键顺序中的最后一个 Windows 窗体 控件。 -向下箭头和向右箭头键中包含的最后一个控件从[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)控件执行 TAB 键相同的操作。 如果没有可获得焦点WPF控件，焦点会转移外部[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)控件。 此行为不同于标准[ContainerControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.containercontrol)中的行为不会包装第一个控件时发生。 如果不存在其他可聚焦的 WPF 控件，焦点将返回到 Tab 键顺序中的第一个 Windows 窗体 控件。 | 不适用。                                                     |
| 加速键                                             | 加速键按常规方式工作，但“不支持”列中注明的情况除外。         | 跨多种技术的重复加速键与普通重复加速键的工作方式不同。 如果加速键跨多种技术复制，并且至少一个在 Windows 窗体控件上，另一个在 WPF 控件上，Windows 窗体 控件将始终收到此加速键。 当按重复加速键时，焦点不会在控件之间切换。 |
| 快捷键                                             | 快捷键按常规方式工作，但“不支持”列中注明的情况除外。         | 在预处理阶段处理的 - Windows 窗体 快捷键总是优先于 WPF 快捷键。 例如，如果你有[ToolStrip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.toolstrip)控件，其定义，CTRL + S 快捷键，并且没有WPF命令绑定到 CTRL + S、[ToolStrip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.toolstrip)始终无论焦点在何处首先，调用控件处理程序。 - Windows 窗体 通过处理键盘快捷方式[KeyDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.keydown)事件中最后处理WPF。 可以通过重写阻止此行为Windows 窗体控件的[IsInputKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.isinputkey)方法或处理[PreviewKeyDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.previewkeydown)事件。 返回`true`从[IsInputKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.isinputkey)方法，或设置值的[PreviewKeyDownEventArgs.IsInputKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.previewkeydowneventargs.isinputkey)属性设置为`true`在你[PreviewKeyDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.previewkeydown)事件处理程序。 |
| AcceptsReturn、AcceptsTab 以及其他特定于控件的行为 | 更改默认键盘行为的属性和往常一样，工作前提Windows 窗体控件重写[IsInputKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.isinputkey)方法以返回`true`。 | Windows 窗体 更改默认的控件通过处理键盘行为[KeyDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.keydown)事件在主机中最后处理WPF控件。 因为最后处理这些控件，所以它们可能产生意外行为。 |
| Enter 和 Leave 事件                                | 当焦点未转到包含[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)控件，Enter 并在单个更改焦点时，将像通常那样引发退出事件[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)控件。 | 发生以下焦点更改时，不会引发 Enter 和 Leave 事件：  -从内部更改到外部[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)控件。 -从外部更改到内部[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)控件。 -外部[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)控件。 -从Windows 窗体控件中承载[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)控制对[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)控件承载在相同[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)。 |
| 多线程                                             | 支持所有类型的多线程处理。                                   | Windows 窗体 和 WPF 技术均采用单线程并发模型。 调试期间，从其他线程调用框架对象会引发一个异常，以强制实施此要求。 |
| 安全性                                             | 所有互操作方案都需要完全信任。                               | 部分信任情况下，不允许任何互操作方案。                       |
| 可访问性                                           | 支持所有辅助功能方案。 当辅助技术产品用于同时包含 Windows 窗体 和 WPF 控件的混合应用程序时，可正常工作。 | 不适用。                                                     |
| 剪贴板                                             | 所有剪贴板操作按常规方式工作。 这包括 Windows 窗体 与 WPF 控件之间的剪切和粘贴。 | 不适用。                                                     |
| 拖放功能                                           | 所有拖放操作按常规方式工作。 这包括 Windows 窗体 和 WPF 控件之间的操作。 | 不适用。                                                     |



## 在 Windows 窗体中承载 WPF 控件

在 Windows 窗体控制主机时支持以下互操作方案WPF控件：

- 使用代码承载一个或多个 WPF 控件。
- 将属性表与一个或多个承载的 WPF 控件关联。
- 在窗体中承载一个或多个 WPF 页。
- 启动 WPF 窗口。
- 承载具有 Windows 窗体 母版和 WPF 详细信息的母版/详细信息窗体。
- 承载具有 WPF 母版和 Windows 窗体 详细信息的母版/详细信息窗体。
- 承载自定义 WPF 控件。
- 承载混合控件。

### 环境属性

Windows 窗体 控件的某些环境属性具有 WPF 等效项。 这些环境属性传播到所承载WPF控件，并公开为公共属性上[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)控件。 [ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)控件将为每个Windows 窗体环境属性设置为其WPF等效。

有关详细信息，请参阅 [Windows 窗体和 WPF 属性映射](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/windows-forms-and-wpf-property-mapping)。

### 行为

下表介绍互操作行为。

| 行为     | 支持                                                         | 不支持                                                       |
| -------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 透明度   | WPF 控件呈现支持透明度。 父 Windows 窗体 控件的背景可以成为所承载的 WPF 控件的背景。 | 不适用。                                                     |
| 多线程   | 支持所有类型的多线程处理。                                   | Windows 窗体 和 WPF 技术均采用单线程并发模型。 调试期间，从其他线程调用框架对象会引发一个异常，以强制实施此要求。 |
| 安全性   | 所有互操作方案都需要完全信任。                               | 部分信任情况下，不允许任何互操作方案。                       |
| 可访问性 | 支持所有辅助功能方案。 当辅助技术产品用于同时包含 Windows 窗体 和 WPF 控件的混合应用程序时，可正常工作。 | 不适用。                                                     |
| 剪贴板   | 所有剪贴板操作按常规方式工作。 这包括 Windows 窗体 与 WPF 控件之间的剪切和粘贴。 | 不适用。                                                     |
| 拖放功能 | 所有拖放操作按常规方式工作。 这包括 Windows 窗体 和 WPF 控件之间的操作。 | 不适用。                                                     |

## [Windows Forms and WPF Interoperability Input Architecture](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/windows-forms-and-wpf-interoperability-input-architecture)

之间的互操作WPF和Windows 窗体要求这两种技术都有相应的键盘输入的处理。 本主题介绍这些技术如何实现键盘和消息处理，以启用混合应用程序中的平滑互操作。

本主题包含以下小节：

- 无模式窗体和对话框
- WindowsFormsHost 键盘和消息处理
- ElementHost 键盘和消息处理

### 无模式窗体和对话框

调用[EnableWindowsFormsInterop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost.enablewindowsformsinterop)方法[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)以打开一个从无模式对话框窗体或对话框中的元素WPF-基于应用程序。

调用[EnableModelessKeyboardInterop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost.enablemodelesskeyboardinterop)方法[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)控制打开无模式WPF页中Windows 窗体-基于应用程序。

### WindowsFormsHost 键盘和消息处理

由托管时， WPF-基于应用程序，Windows 窗体键盘和消息处理包括下列项：

- [WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)类获取来自WPF消息循环，由实现[ComponentDispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher)类。
- [WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)类创建一个代理项Windows 窗体消息循环，以确保，普通Windows 窗体键盘处理时发生。
- [WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)类实现[IKeyboardInputSink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.ikeyboardinputsink)接口来协调与焦点管理WPF。
- [WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)控件自行注册并启动其消息循环。

以下部分介绍这些部分的更多详细信息中的过程。

#### 获取来自 WPF 消息循环的消息

[ComponentDispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher)类实现的消息循环管理器WPF。 [ComponentDispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher)类提供挂钩以启用外部客户端之前筛选消息到WPF对其进行处理。

互操作实现句柄[ComponentDispatcher.ThreadFilterMessage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher.threadfiltermessage)事件，它使Windows 窗体控件来处理消息之前WPF控件。

#### 代理项 Windows 窗体消息循环

默认情况下[System.Windows.Forms.Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.application)类包含的主消息循环Windows 窗体应用程序。 在互操作，Windows 窗体循环不处理消息的消息。 因此，必须重新生成此逻辑。 处理程序[ComponentDispatcher.ThreadFilterMessage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher.threadfiltermessage)事件执行以下步骤：

1. 消息使用筛选器[IMessageFilter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.imessagefilter)接口。
2. 调用[Control.PreProcessMessage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.preprocessmessage)方法。
3. 将转换并发送消息，如有必要。
4. 如果没有其他控件处理消息，消息传递到将托管控件。

#### IKeyboardInputSink 实现

代理项消息循环处理键盘管理。 因此，[IKeyboardInputSink.TabInto](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.ikeyboardinputsink.tabinto)方法是唯一[IKeyboardInputSink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.ikeyboardinputsink)需要中的实现的成员[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)类。

默认情况下[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)类返回`false`有关其[IKeyboardInputSink.TabInto](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost.system-windows-interop-ikeyboardinputsink-tabinto)实现。 这可以防止从 tab 键次序WPF控制对Windows 窗体控件。

[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)的实现[IKeyboardInputSink.TabInto](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.ikeyboardinputsink.tabinto)方法执行以下步骤：

1. 查找第一个或最后一个Windows 窗体包含由控件[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)控制且可以接收焦点。 控件选择取决于遍历的信息。
2. 将焦点设置到控件，并返回`true`。
3. 如果没有控件可以接收焦点，则返回`false`。

#### WindowsFormsHost 注册

当窗口的句柄[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)创建控件，[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)控件调用注册的消息循环其存在的内部静态方法。

在注册期间[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)控件将检查消息循环。 如果尚未启动消息循环，[ComponentDispatcher.ThreadFilterMessage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher.threadfiltermessage)创建事件处理程序。 消息循环运行时被视为[ComponentDispatcher.ThreadFilterMessage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.componentdispatcher.threadfiltermessage)附加事件处理程序。

当销毁窗口句柄时，[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)从注册的控件删除本身。

### ElementHost 键盘和消息处理

由托管时，Windows 窗体应用程序，WPF键盘和消息处理包括下列项：

- [HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)[IKeyboardInputSink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.ikeyboardinputsink)，和[IKeyboardInputSite](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.ikeyboardinputsite)接口实现代码。
- 按 tab 键和箭头键。
- 命令键和对话框键。
- Windows 窗体 快捷键处理。

以下各节介绍了这些部分中更多详细信息。

#### 接口实现

在Windows 窗体，键盘消息路由到具有焦点的控件的窗口句柄。 在[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)控件，这些消息路由到承载的元素。 若要完成此操作，请[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)控件提供了[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)实例。 如果[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)控件具有焦点[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)实例路由大多数键盘输入，以便可以由处理WPF[InputManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.inputmanager)类。

[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)类实现[IKeyboardInputSink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.ikeyboardinputsink)和[IKeyboardInputSite](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.ikeyboardinputsite)接口。

键盘互操作依赖于实现[OnNoMoreTabStops](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.ikeyboardinputsite.onnomoretabstops)方法句柄 TAB 键和箭头键将焦点移出承载的元素的输入。

#### Tab 键和箭头键

Windows 窗体选择逻辑映射到[IKeyboardInputSink.TabInto](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource.system-windows-interop-ikeyboardinputsink-tabinto)和[OnNoMoreTabStops](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.ikeyboardinputsite.onnomoretabstops)方法来实现选项卡和箭头键导航。 重写[Select](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost.select)方法即可实现此映射。

#### 命令键和对话框键

若要让WPF处理命令键和对话框键的第一个机会Windows 窗体预处理命令连接到[TranslateAccelerator](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.ikeyboardinputsink.translateaccelerator)方法。 重写[Control.ProcessCmdKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.processcmdkey)方法连接这两种技术。

使用[TranslateAccelerator](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.ikeyboardinputsink.translateaccelerator)方法中，承载的元素可以处理任何关键消息，如 WM_KEYDOWN、 WM_KEYUP、 WM_SYSKEYDOWN 或 WM_SYSKEYUP，包括命令键，例如选项卡、 ENTER、 ESC、 和箭头键。 如果未处理键消息，它将被发送，Windows 窗体上级层次结构进行处理。

#### 快捷键处理

若要正确处理加速器Windows 窗体快捷键处理必须连接到WPF[AccessKeyManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.accesskeymanager)类。 此外，必须将所有的 WM_CHAR 消息正确路由到承载的元素。

因为默认值[HwndSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndsource)的实现[TranslateChar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.ikeyboardinputsink.translatechar)方法将返回`false`，使用以下逻辑 WM_CHAR 消息进行处理：

- [Control.IsInputChar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.isinputchar)方法被重写以确保所有的 WM_CHAR 消息都转发至承载的元素。
- 如果按下 ALT 键时，消息为 WM_SYSCHAR。 Windows 窗体 不预处理通过此消息[IsInputChar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.isinputchar)方法。 因此，[ProcessMnemonic](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.processmnemonic)方法被重写查询WPF[AccessKeyManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.accesskeymanager)已注册的快捷键。 如果找到已注册的快捷键，则[AccessKeyManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.accesskeymanager)对其进行处理。
- 如果未按下 ALT 键， WPF [InputManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.inputmanager)类处理未处理的输入。 如果输入是快捷键，[AccessKeyManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.accesskeymanager)对其进行处理。 [PostProcessInput](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.inputmanager.postprocessinput)的未处理的 WM_CHAR 消息处理事件。

当用户按下 ALT 键时，整个窗体上显示快捷键的可视化提示。 若要支持此行为，所有[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)活动窗体上的控件接收 WM_SYSKEYDOWN 消息，无论哪个控件具有焦点。

消息将仅发送给[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)活动窗体中的控件。

## [Layout Considerations for the WindowsFormsHost Element](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/layout-considerations-for-the-windowsformshost-element)

本主题介绍如何[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)与元素交互WPF布局系统。

WPF 和Windows 窗体支持不同，但类似的逻辑大小和位置上窗体或页面的元素。 当你创建混合用户界面 (UI) 承载Windows 窗体中的控件WPF，则[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素集成这两种布局方案。

### 在布局中 WPF 和 Windows 窗体之间的差异

WPF 使用独立于分辨率的布局。 所有WPF使用指定的布局维度*设备无关的像素*。 独立于设备的像素是一个 96 英寸为单位的大小和分辨率无关的因此获得相似的结果，而不考虑呈现到 72 dpi 监视器或 19200 dpi 打印机。

WPF 也基于*动态布局*。 这意味着 UI 元素会在窗体或根据其内容，其父级的布局容器，并可用的屏幕大小的页面上排列本身。 动态布局可简化本地化过程，它们包含的字符串长度更改时自动调整大小和 UI 元素的位置。

中的布局Windows 窗体是依赖于设备的和更有可能是静态的。 通常情况下，Windows 窗体控件在窗体使用硬件以像素为单位指定的维度上采用绝对定位。 但是，Windows 窗体支持某些动态布局功能，如下表中进行了总结。

| 布局功能     | 描述                                                         |
| ------------ | ------------------------------------------------------------ |
| 自动调整大小 | 某些Windows 窗体控件调整自身大小以正确显示其内容。 有关详细信息，请参阅[AutoSize 属性概述](https://docs.microsoft.com/zh-cn/dotnet/framework/winforms/controls/autosize-property-overview)。 |
| 锚定和停靠   | Windows 窗体 控件支持调整位置和大小基于父容器。 有关详细信息，请参阅 [Control.Anchor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.anchor) 和 [Control.Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.dock)。 |
| 自动缩放     | 容器控件来调整自身及其子级的输出设备或大小，以像素为单位的默认容器字体的分辨率。 有关详细信息，请参阅[在 Windows 窗体中的自动缩放](https://docs.microsoft.com/zh-cn/dotnet/framework/winforms/automatic-scaling-in-windows-forms)。 |
| 布局容器     | [FlowLayoutPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.flowlayoutpanel)和[TableLayoutPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.tablelayoutpanel)控件排列其子控件和调整自身大小根据其内容。 |

### 布局的限制

一般情况下，Windows 窗体控件不能缩放和转换中可能的范围为WPF。 以下列表描述了已知的限制时[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素尝试将其承载Windows 窗体控制WPF布局系统。

- 某些情况下，不能调整 Windows 窗体 控件的大小，或者大小只能调整为特定尺寸。 例如， Windows 窗体[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.combobox)控件支持仅的单一高度由控件的字体大小定义。 在中WPF其中元素可以垂直拉伸，托管的动态布局[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.combobox)控件不会按预期方式拉伸。
- 不能旋转或扭曲 Windows 窗体 控件。 [WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素将引发[LayoutError](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost.layouterror)事件，如果应用倾斜或旋转转换。 如果不处理[LayoutError](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost.layouterror)事件，[InvalidOperationException](https://docs.microsoft.com/zh-cn/dotnet/api/system.invalidoperationexception)引发。
- 大多数情况下，Windows 窗体 控件不支持按比例缩放。 尽管该控件的整体尺寸将会缩放，但其子控件和组件元素可能不会按预期调整大小。 此限制取决于每个 Windows 窗体 控件支持缩放的程度。 此外，不能缩放Windows 窗体缩小到 0 像素的大小的控件。
- Windows 窗体 控件支持自动缩放，在其中窗体将自动调整大小本身和它基于字体大小的控件。 在 WPF 用户界面中，更改字号不会改变整个布局的大小，但是可动态调整单个元素的大小。

#### Z 顺序

在 WPF 用户界面中，可以更改元素的 z 顺序以控制重叠行为。 由于承载的 Windows 窗体 控件是在单独的 HWND 中绘制的，所以始终在 WPF 元素之上绘制它。

一个承载Windows 窗体还在任何之上绘制控件[Adorner](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adorner)元素。

### 布局行为

托管时，以下部分介绍的布局行为的特定方面Windows 窗体中的控件WPF。

#### 缩放、 单位换算和设备独立性

每当[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素执行操作涉及WPF和Windows 窗体涉及维度，两个坐标系统： 独立于设备的像素WPF和硬件像素Windows 窗体。 因此，你必须应用适当的单位和缩放转换，以实现一致的布局。

坐标系统之间的转换取决于当前的设备分辨率和任何布局或呈现转换应用于[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素或对其的上级。

如果输出设备为 96 dpi，无需进行扩展已应用到[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素中，一个独立于设备的像素是否等于一个硬件像素。

所有其他情况下需要缩放坐标系统。 不调整承载的控件的大小。 相反，[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素尝试缩放承载的控件及其所有子控件。 因为Windows 窗体不完全支持缩放，[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素可以扩展到由特定控件支持的程度。

重写[ScaleChild](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost.scalechild)方法以提供自定义的缩放行为的托管 Windows 窗体控件。

除了缩放以外，[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素处理舍入和溢出的情况下下, 表中所述。

| 转换问题 | 描述                                                         |
| -------- | ------------------------------------------------------------ |
| 舍入     | WPF 指定为独立于设备的像素尺寸`double`，并Windows 窗体硬件像素大小指定为`int`。 在情况下， `double`-基于的维度转换为`int`-基于维度，[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素使用标准的舍入，以便小于 0.5 的小数部分的值是向下舍入为 0。 |
| 溢出     | 当[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素将从转换`double`值到`int`值，可能会溢出。 值大于[MaxValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.int32.maxvalue)设置为[MaxValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.int32.maxvalue)。 |

#### 与布局相关的属性

控制中的布局行为的属性Windows 窗体控件和WPF相应地通过映射元素[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素。 有关详细信息，请参阅 [Windows 窗体和 WPF 属性映射](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/windows-forms-and-wpf-property-mapping)。

#### 托管控件中的布局更改

中托管的布局更改Windows 窗体控件将传播到WPF以触发布局更新。 [InvalidateMeasure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.invalidatemeasure)方法[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)可确保在承载控件的布局更改会造成WPF布局引擎来运行。

#### 持续调整 Windows 窗体控件

Windows 窗体 与支持连续缩放完全的控件进行交互WPF布局系统。 [WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素使用[MeasureOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.measureoverride)并[ArrangeOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.arrangeoverride)方法，像往常一样来调整和排列承载Windows 窗体控件。

#### 调整大小算法

[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素使用以下过程来托管的控件的大小：

1. [WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素会替代[MeasureOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.measureoverride)和[ArrangeOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.arrangeoverride)方法。
2. 若要确定所承载控件的大小[MeasureOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.measureoverride)方法调用托管的控件的[GetPreferredSize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.getpreferredsize)方法使用约束转换从传递给约束[MeasureOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.measureoverride)方法。
3. [ArrangeOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.arrangeoverride)方法会尝试将所承载的控件设置为给定的大小约束。
4. 如果托管的控件的[Size](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.size)属性进行匹配指定的约束时，所承载的控件的大小为该约束。

如果[Size](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.size)属性与指定的约束不匹配，所承载的控件不支持连续的大小调整。 例如，[MonthCalendar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.monthcalendar)控件允许连续的大小。 此控件的允许的大小包含高度和宽度的整数 （表示的月数）。 中，这种情况下[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素的行为，如下所示：

- 如果[Size](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.size)属性返回与指定的约束，更大的大小[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素剪辑所承载的控件。 高度和宽度是分别进行处理，因此可能在任一方向剪辑所承载的控件。
- 如果[Size](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.size)属性返回与指定的约束，较小的大小[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)接受此大小值并返回到值WPF布局系统。

## [Windows Forms Controls and Equivalent WPF Controls](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/windows-forms-controls-and-equivalent-wpf-controls)

许多Windows 窗体控件都有等效WPF控件，但一些Windows 窗体控件中有没有等效项WPF。 本主题将比较这两种技术所提供的控件类型。

您始终可以使用互操作来承载Windows 窗体中没有等效项的控件在WPF-基于应用程序。

下表显示了哪些Windows 窗体控件和组件都有等效项WPF控制功能。

| Windows 窗体控件                                             | 等效的 WPF 控件                                              | 备注                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| [BindingNavigator](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.bindingnavigator) | 没有等效的控件。                                             |                                                              |
| [BindingSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.bindingsource) | [CollectionViewSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource) |                                                              |
| [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.button) | [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) |                                                              |
| [CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.checkbox) | [CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox) |                                                              |
| [CheckedListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.checkedlistbox) | [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 与撰写。 |                                                              |
| [ColorDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.colordialog) | 没有等效的控件。                                             |                                                              |
| [ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.combobox) | [ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox) | [ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox) 不支持自动完成。 |
| [ContextMenuStrip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.contextmenustrip) | [ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu) |                                                              |
| [DataGridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.datagridview) | [DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid) |                                                              |
| [DateTimePicker](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.datetimepicker) | [DatePicker](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datepicker) |                                                              |
| [DomainUpDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.domainupdown) | [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 和两个[RepeatButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.repeatbutton)控件。 |                                                              |
| [ErrorProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.errorprovider) | 没有等效的控件。                                             |                                                              |
| [FlowLayoutPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.flowlayoutpanel) | [WrapPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.wrappanel) 或 [StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel) |                                                              |
| [FolderBrowserDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.folderbrowserdialog) | 没有等效的控件。                                             |                                                              |
| [FontDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.fontdialog) | 没有等效的控件。                                             |                                                              |
| [Form](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.form) | [Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window) | [Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window) 不支持子窗口。 |
| [GroupBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.groupbox) | [GroupBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.groupbox) |                                                              |
| [HelpProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.helpprovider) | 没有等效的控件。                                             | 没有 F1 帮助。 "这是什么"帮助替换为工具提示。                |
| [HScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.hscrollbar) | [ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar) | 滚动内置容器控件。                                           |
| [ImageList](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.imagelist) | 没有等效的控件。                                             |                                                              |
| [Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.label) | [Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label) |                                                              |
| [LinkLabel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.linklabel) | 没有等效的控件。                                             | 可以使用[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)承载流内容内的超链接的类。 |
| [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.listbox) | [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) |                                                              |
| [ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.listview) | [ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview) | [ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控件提供了一个只读的详细信息视图。 |
| [MaskedTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.maskedtextbox) | 没有等效的控件。                                             |                                                              |
| [MenuStrip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.menustrip) | [Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu) | [Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu) 控件样式设置类似的行为和外观[System.Windows.Forms.ToolStripProfessionalRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.toolstripprofessionalrenderer)类。 |
| [MonthCalendar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.monthcalendar) | [Calendar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.calendar) |                                                              |
| [NotifyIcon](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.notifyicon) | 没有等效的控件。                                             |                                                              |
| [NumericUpDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.numericupdown) | [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 和两个[RepeatButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.repeatbutton)控件。 |                                                              |
| [OpenFileDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.openfiledialog) | [OpenFileDialog](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.win32.openfiledialog) | [OpenFileDialog](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.win32.openfiledialog)类是WPF周围的包装器Win32控件。 |
| [PageSetupDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.pagesetupdialog) | 没有等效的控件。                                             |                                                              |
| [Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.panel) | [Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas) |                                                              |
| [PictureBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.picturebox) | [Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image) |                                                              |
| [PrintDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.printdialog) | [PrintDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.printdialog) |                                                              |
| [PrintDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.printing.printdocument) | 没有等效的控件。                                             |                                                              |
| [PrintPreviewControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.printpreviewcontrol) | [DocumentViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.documentviewer) |                                                              |
| [PrintPreviewDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.printpreviewdialog) | 没有等效的控件。                                             |                                                              |
| [ProgressBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.progressbar) | [ProgressBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.progressbar) |                                                              |
| [PropertyGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.propertygrid) | 没有等效的控件。                                             |                                                              |
| [RadioButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.radiobutton) | [RadioButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.radiobutton) |                                                              |
| [RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.richtextbox) | [RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox) |                                                              |
| [SaveFileDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.savefiledialog) | [SaveFileDialog](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.win32.savefiledialog) | [SaveFileDialog](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.win32.savefiledialog)类是WPF周围的包装器Win32控件。 |
| [ScrollableControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.scrollablecontrol) | [ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer) |                                                              |
| [SoundPlayer](https://docs.microsoft.com/zh-cn/dotnet/api/system.media.soundplayer) | [MediaPlayer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediaplayer) |                                                              |
| [SplitContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.splitcontainer) | [GridSplitter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridsplitter) |                                                              |
| [StatusStrip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.statusstrip) | [StatusBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.statusbar) |                                                              |
| [TabControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.tabcontrol) | [TabControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tabcontrol) |                                                              |
| [TableLayoutPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.tablelayoutpanel) | [Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid) |                                                              |
| [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.textbox) | [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) |                                                              |
| [Timer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.timer) | [DispatcherTimer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatchertimer) |                                                              |
| [ToolStrip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.toolstrip) | [ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar) |                                                              |
| [ToolStripContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.toolstripcontainer) | [ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar) 与撰写。 |                                                              |
| [ToolStripDropDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.toolstripdropdown) | [ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar) 与撰写。 |                                                              |
| [ToolStripDropDownMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.toolstripdropdownmenu) | [ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar) 与撰写。 |                                                              |
| [ToolStripPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.toolstrippanel) | [ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar) 与撰写。 |                                                              |
| [ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.tooltip) | [ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip) |                                                              |
| [TrackBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.trackbar) | [Slider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider) |                                                              |
| [TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.treeview) | [TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview) |                                                              |
| [UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.usercontrol) | [UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol) |                                                              |
| [VScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.vscrollbar) | [ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar) | 滚动内置容器控件。                                           |
| [WebBrowser](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.webbrowser) | [Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)， [System.Windows.Controls.WebBrowser](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.webbrowser) | [Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)控件可以承载的 HTML 页面。  在中启动.NET Framework 3.5 SP1，则[System.Windows.Controls.WebBrowser](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.webbrowser)控件可以承载的 HTML 页面，并且还支持[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)控件。 |

## [Windows Forms and WPF Property Mapping](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/windows-forms-and-wpf-property-mapping)

Windows 窗体和WPF技术有两个相似但不同属性模型。 *属性映射*支持两种体系结构之间的互操作，并提供以下功能：

- 轻松将映射到承载的控件或元素的主机环境中的相关属性更改。
- 提供了使用默认处理映射最常用的属性。
- 允许方便地删除，重写时，或扩展默认属性。
- 确保主机上的属性值更改自动检测到并转换为托管的控件或元素。

 备注

属性更改事件不会传播到宿主控件或元素层次结构。 如果本地属性的值不会由于直接设置、 样式、 继承、 数据绑定或其他机制更改属性的值的更改不会执行属性转换。

使用[PropertyMap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost.propertymap)上的属性[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素并[PropertyMap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost.propertymap)属性[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)控件，用于访问属性映射。

### 使用 WindowsFormsHost 元素的属性映射

[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素将转换的默认WPF属性设置为其Windows 窗体使用以下转换表的等效项。

| Windows Presentation Foundation 托管                         | Windows 窗体                                                 | 互操作行为                                                   |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| [Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)  ([System.Windows.Media.Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)) | [BackColor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.backcolor)  ([System.Drawing.Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.color)) | [WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素集[BackColor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.backcolor)承载控件的属性和[BackgroundImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.backgroundimage)所承载控件的属性。 通过使用以下规则执行映射：  -如果[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)是纯色，转换，并用于设置[BackColor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.backcolor)所承载控件的属性。 [BackColor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.backcolor)寄宿的控件可以继承的值，因此未对承载控件设置属性[BackColor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.backcolor)属性。 **注意：** 所承载的控件不支持透明度。 分配给任何颜色[BackColor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.backcolor)必须是完全不透明，alpha 值为 0xFF。   -如果[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)不是纯颜色[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)控件创建从位图[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)属性。 [WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)控件将分配到此位图[BackgroundImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.backgroundimage)所承载控件的属性。 这提供了类似于透明度的效果。 **注意：** 您可以重写此行为，或者可以删除[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)属性映射。 |
| [Cursor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.cursor) | [Cursor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.cursor) | 如果尚未重新分配的默认映射，[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)控件遍历其祖先层次结构，直到找到包含上级其[Cursor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.cursor)属性集。 此值将转换为最接近的对应Windows 窗体游标。  如果默认映射[ForceCursor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.forcecursor)属性不重新分配、 遍历停止上包含的第一个上级[ForceCursor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.forcecursor)设置为`true`。 |
| [FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)  ([System.Windows.FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)) | [RightToLeft](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.righttoleft)  ([System.Windows.Forms.RightToLeft](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.righttoleft)) | [LeftToRight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection#System_Windows_FlowDirection_LeftToRight) 映射到 [No](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.righttoleft#System_Windows_Forms_RightToLeft_No)。  [RightToLeft](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection#System_Windows_FlowDirection_RightToLeft) 映射到 [Yes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.righttoleft#System_Windows_Forms_RightToLeft_Yes)。  [Inherit](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.righttoleft#System_Windows_Forms_RightToLeft_Inherit) 未映射。  [FlowDirection.RightToLeft](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection#System_Windows_FlowDirection_RightToLeft) 映射到 [RightToLeft.Yes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.righttoleft#System_Windows_Forms_RightToLeft_Yes)。 |
| [FontStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontstyle) | [Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.font.style) 对承载控件 [System.Drawing.Font](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.font) | 一套WPF属性转换为相应[Font](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.font)。 当其中一个属性更改时，新[Font](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.font)创建。 有关[Normal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontstyles.normal):[Italic](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.fontstyle#System_Drawing_FontStyle_Italic)被禁用。 有关[Italic](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontstyles.italic)或[Oblique](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontstyles.oblique):[Italic](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.fontstyle#System_Drawing_FontStyle_Italic)已启用。 |
| [FontWeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontweight) | [Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.font.style) 对承载控件 [System.Drawing.Font](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.font) | 一套WPF属性转换为相应[Font](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.font)。 当其中一个属性更改时，新[Font](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.font)创建。 有关[Black](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontweights.black)， [Bold](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontweights.bold)， [DemiBold](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontweights.demibold)， [ExtraBold](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontweights.extrabold)， [Heavy](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontweights.heavy)， [Medium](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontweights.medium)， [SemiBold](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontweights.semibold)，或[UltraBold](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontweights.ultrabold):[Bold](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.fontstyle#System_Drawing_FontStyle_Bold)已启用。 有关[ExtraLight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontweights.extralight)， [Light](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontweights.light)， [Normal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontweights.normal)， [Regular](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontweights.regular)， [Thin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontweights.thin)，或[UltraLight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontweights.ultralight):[Bold](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.fontstyle#System_Drawing_FontStyle_Bold)被禁用。 |
| [FontFamily](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontfamily)  [FontSize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontsize)  [FontStretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontstretch)  [FontStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontstyle)  [FontWeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontweight) | [Font](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.font)  ([System.Drawing.Font](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.font)) | 一套WPF属性转换为相应[Font](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.font)。 当其中一个属性更改时，新[Font](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.font)创建。 承载Windows 窗体控件调整大小时基于字体大小。  中的字体大小WPF表示为 96 英寸为单位，并在Windows 窗体作为一个/72 英寸为单位。 对应的转换是：  Windows 窗体 字体大小 =WPF字体大小 * 72.0 / 96.0。 |
| [Foreground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.foreground)  ([System.Windows.Media.Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)) | [ForeColor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.forecolor)  ([System.Drawing.Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.color)) | [Foreground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.foreground)属性映射执行通过使用以下规则：  -如果[Foreground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.foreground)是[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)，使用[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush.color)为[ForeColor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.forecolor)。 -如果[Foreground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.foreground)是[GradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientbrush)，使用的颜色[GradientStop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientstop)偏移量值的最小[ForeColor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.forecolor)。 -对于任何其他[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)类型，不[ForeColor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.forecolor)不变。 这意味着使用默认值。 |
| [IsEnabled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.isenabled) | [Enabled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.enabled) | 当[IsEnabled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.isenabled)设置，则[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素集[Enabled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.enabled)对承载控件的属性。 |
| [Padding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.padding) | [Padding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.padding) | 所有四个值的[Padding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.padding)上托管的属性Windows 窗体控件设置为相同[Thickness](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.thickness)值。  值大于[MaxValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.int32.maxvalue)设置为[MaxValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.int32.maxvalue)。 的值小于[MinValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.int32.minvalue)设置为[MinValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.int32.minvalue)。 |
| [Visibility](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.visibility) | [Visible](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.visible) | - [Visible](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visibility#System_Windows_Visibility_Visible) 映射到[Visible](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.visible) = `true`。 承载Windows 窗体控件是否可见。 显式设置[Visible](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.visible)到对承载控件的属性`false`不建议。 - [Collapsed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visibility#System_Windows_Visibility_Collapsed) 映射到[Visible](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.visible) = `true`或`false`。 承载Windows 窗体不绘制控件，并且其区域处于折叠状态。 - [Hidden](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visibility#System_Windows_Visibility_Hidden) :承载Windows 窗体控件占用空间在布局中，但是不可见。 在这种情况下，[Visible](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.visible)属性设置为`true`。 显式设置[Visible](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.visible)到对承载控件的属性`false`不建议。 |

完全支持容器元素上的附加的属性[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素。

有关详细信息，请参见[演练：使用 WindowsFormsHost 元素映射属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/walkthrough-mapping-properties-using-the-windowsformshost-element)。

### 父属性的更新

对大多数父属性的更改会导致到承载的子控件的通知。 以下列表介绍它们的值更改时不会导致通知的属性。

- [Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)
- [Cursor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.cursor)
- [ForceCursor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.forcecursor)
- [Visibility](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.visibility)

例如，如果您更改的值[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)的属性[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素，[BackColor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.backcolor)所承载控件的属性不会更改。

### 使用 ElementHost 控件的属性映射

以下属性提供了内置的更改通知。 不要调用[OnPropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.onpropertychanged)方法映射这些属性时：

- AutoSize
- BackColor
- BackgroundImage
- BackgroundImageLayout
- BindingContext
- CausesValidation
- ContextMenu
- ContextMenuStrip
- Cursor
- 停靠
- 已启用
- 字体
- ForeColor
- 位置
- 边距
- 填充
- 父级
- Region
- RightToLeft
- 大小
- TabIndex
- TabStop
- Text
- 可见

[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)控件将转换的默认Windows 窗体属性设置为其WPF通过使用以下转换表的等效项。

有关详细信息，请参见[演练：使用 ElementHost 控件映射属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/walkthrough-mapping-properties-using-the-elementhost-control)。

| 承载 Windows 窗体                                            | Windows Presentation Foundation                              | 互操作行为                                                   |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| [BackColor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.backcolor)  ([System.Drawing.Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.color)) | [Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)  ([System.Windows.Media.Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)) 上承载的元素 | 将此属性设置强制重新绘制与[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)。 如果[BackColorTransparent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost.backcolortransparent)属性设置为`false`（默认值），这[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)基于的外观[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)控制，包括其[BackColor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.backcolor)， [BackgroundImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.backgroundimage)，[BackgroundImageLayout](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.backgroundimagelayout)属性和任何附加的绘图处理程序。  如果[BackColorTransparent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost.backcolortransparent)属性设置为`true`，则[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)基于的外观[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)控件的父级，包括父[BackColor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.backcolor)， [BackgroundImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.backgroundimage)，[BackgroundImageLayout](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.backgroundimagelayout)属性和任何附加的绘图处理程序。 |
| [BackgroundImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.backgroundimage)  ([System.Drawing.Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.image)) | [Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)  ([System.Windows.Media.Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)) 上承载的元素 | 设置此属性会导致所述的相同的行为[BackColor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.backcolor)映射。 |
| [BackgroundImageLayout](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.backgroundimagelayout) | [Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)  ([System.Windows.Media.Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)) 上承载的元素 | 设置此属性会导致所述的相同的行为[BackColor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.backcolor)映射。 |
| [Cursor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.cursor)  ([System.Windows.Forms.Cursor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.cursor)) | [Cursor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.cursor)  ([System.Windows.Input.Cursor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.cursor)) | Windows 窗体标准游标将转换为相应WPF标准光标。 如果Windows 窗体不是标准的游标，分配默认值。 |
| [Enabled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.enabled) | [IsEnabled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.isenabled) | 当[Enabled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.enabled)设置，则[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)控制集[IsEnabled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.isenabled)上承载的元素的属性。 |
| [Font](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.font)  ([System.Drawing.Font](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.font)) | [FontFamily](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontfamily)  [FontSize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontsize)  [FontStretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontstretch)  [FontStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontstyle)  [FontWeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontweight) | [Font](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.font)值转换为一组对应的WPF字体属性。 |
| [Bold](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.font.bold) | [FontWeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontweight) 上承载的元素 | 如果 [Bold](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.font.bold) 为 `true`，则 [FontWeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontweight) 设置为 [Bold](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontweights.bold)。  如果 [Bold](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.font.bold) 为 `false`，则 [FontWeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontweight) 设置为 [Normal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontweights.normal)。 |
| [Italic](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.font.italic) | [FontStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontstyle) 上承载的元素 | 如果 [Italic](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.font.italic) 为 `true`，则 [FontStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontstyle) 设置为 [Italic](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontstyles.italic)。  如果 [Italic](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.font.italic) 为 `false`，则 [FontStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontstyle) 设置为 [Normal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.fontstyles.normal)。 |
| [Strikeout](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.font.strikeout) | [TextDecorations](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.textdecorations) 上承载的元素 | 仅当承载时[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)控件。 |
| [Underline](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.font.underline) | [TextDecorations](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.textdecorations) 上承载的元素 | 仅当承载时[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)控件。 |
| [RightToLeft](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.righttoleft)  ([System.Windows.Forms.RightToLeft](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.righttoleft)) | [FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)  ([FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)) | [No](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.righttoleft#System_Windows_Forms_RightToLeft_No) 映射到 [LeftToRight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection#System_Windows_FlowDirection_LeftToRight)。  [Yes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.righttoleft#System_Windows_Forms_RightToLeft_Yes) 映射到 [RightToLeft](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection#System_Windows_FlowDirection_RightToLeft)。 |
| [Visible](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.visible) | [Visibility](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.visibility) | [ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)控件将设置[Visibility](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.visibility)属性上承载的元素使用以下规则：  - [Visible](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.visible) = `true` 映射到[Visible](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visibility#System_Windows_Visibility_Visible)。 - [Visible](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.visible) = `false` 映射到[Hidden](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visibility#System_Windows_Visibility_Hidden)。 |

## [Troubleshooting Hybrid Applications](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/troubleshooting-hybrid-applications)

本主题列出了在创作同时使用 WPF 和 Windows 窗体技术的混合应用程序时可能发生的一些常见问题。



### 重叠控件

控件可能不按预期的方式重叠。 Windows 窗体为每个控件使用单独的 HWND。 WPF 为一个页面上的所有内容使用一个 HWND。 这一实现差异会导致意外的重叠行为。

WPF 中承载的 Windows 窗体控件总是出现在 WPF 内容之上。

WPF 内容中托管[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)控件显示在 z 顺序[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)控件。 可以重叠[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)控件，但所承载WPF内容不会组合或交互。

### 子属性

[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)和[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)类只能承载单个子控件或元素。 若要承载多个控件或元素，则必须使用容器作为子内容。 例如，可以添加Windows 窗体按钮和复选框控件[System.Windows.Forms.Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.panel)控件，然后再将分配到面板[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)控件的[Child](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost.child)属性。 但是，您不能按钮和复选框控件将分别添加到相同[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)控件。

### 缩放

WPF 和 Windows 窗体具有不同的缩放模型。 某些 WPF 缩放变换对于 Windows 窗体控件是有意义的，但其他变换是无意义的。 例如，将 Windows 窗体控件缩放到 0 是可行的，但如果尝试将同一控件重新缩放回非零值，该控件的大小仍然为 0。 有关详细信息，请参阅 [WindowsFormsHost 元素的布局注意事项](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/layout-considerations-for-the-windowsformshost-element)。

### 适配器

处理时可能会发生混乱[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)和[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)类，因为它们包含一个隐藏的容器。 同时[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)并[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)类具有名为的隐藏的容器*适配器*，它用来托管内容。 有关[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素，该适配器派生[System.Windows.Forms.ContainerControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.containercontrol)类。 有关[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)控件，该适配器派生[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)元素。 如果你发现其他互操作主题中提到了适配器，那么所讨论的就是此容器。

### 嵌套

嵌套[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素内的[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)控件不支持。 嵌套[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)控件内部[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素也不支持。

### 焦点

焦点在 WPF 和 Windows 窗体中的工作方式是不同的，这意味着混合应用程序中可能发生焦点问题。 例如，如果内部具有焦点[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素，并且你可以最小化和还原页面或显示模式对话框，重点放在[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素可能会丢失。 [WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素仍具有焦点，但其内部的控件可能不会。

焦点还会影响数据验证。 验证适用于[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素，但它不能按你按 tab 键离开[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素，或两个不同[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素。

### 属性映射

某些属性映射需要先进行大量的转译，才能将 WPF 和 Windows 窗体技术之间不同的实现桥接起来。 属性映射可使代码对字体、颜色和其他属性的更改做出反应。 通常，属性映射的工作方式是侦听 *Property*Changed 事件或 On*Property* 调用，然后在子控件或其适配器上设置适当的属性。 有关详细信息，请参阅 [Windows 窗体和 WPF 属性映射](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/windows-forms-and-wpf-property-mapping)。

### 所承载内容上的布局相关属性

当[WindowsFormsHost.Child](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost.child)或[ElementHost.Child](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost.child)分配属性，将自动设置所承载内容上的多个布局相关属性。 更改这些内容属性可能会导致意外的布局行为。

停靠所承载的内容来填充[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)和[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)父级。 为了启用此填充行为，在设置子属性时，将设置多个属性。 下表列出了由设置内容属性[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)和[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)类。

| 宿主类                                                       | 内容属性                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost) | [Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)  [Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)  [Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)  [VerticalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.verticalalignment)  [HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.horizontalalignment) |
| [WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost) | [Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.margin)  [Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.dock)  [AutoSize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.autosize)  [Location](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.location)  [MaximumSize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.maximumsize) |

请勿在所承载的内容上直接设置这些属性。 有关详细信息，请参阅 [WindowsFormsHost 元素的布局注意事项](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/layout-considerations-for-the-windowsformshost-element)。

### 导航应用程序

导航应用程序不能保持用户状态。 [WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素导航应用程序中使用时重新创建其控件。 当用户导航操作离开承载的页面重新创建子控件时发生[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素，然后又返回到它。 用户已经键入的所有内容都将丢失。

### 消息循环互操作

在使用 Windows 窗体消息循环时，可能无法按照预期方式处理消息。 [EnableWindowsFormsInterop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost.enablewindowsformsinterop)方法由调用[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)构造函数。 此方法将向 WPF 消息循环中添加消息筛选器。 此筛选器会调用[Control.PreProcessMessage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.preprocessmessage)方法如果[System.Windows.Forms.Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control)是消息的目标和转换/调度该消息。

如果显示[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)中Windows 窗体具有消息循环[Application.Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.application.run)，您不能键入任何内容，除非调用[EnableModelessKeyboardInterop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost.enablemodelesskeyboardinterop)方法。 [EnableModelessKeyboardInterop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost.enablemodelesskeyboardinterop)方法采用[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)，并添加[System.Windows.Forms.IMessageFilter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.imessagefilter)，其中修复重新路由到与键相关的消息WPF消息循环。 有关详细信息，请参阅 [Windows 窗体和 WPF 互操作性输入体系结构](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/windows-forms-and-wpf-interoperability-input-architecture)。

### 不透明度和分层

[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)类不支持分层。 这意味着该设置[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)上的属性[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素不起作用，并且没有值混合处理会与其他WPF窗口产生[AllowsTransparency](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.allowstransparency)设置为`true`。

### 释放

未正确释放类可能会泄漏资源。 在混合应用程序，请确保[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)和[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)释放类，或可能会泄漏资源。 Windows 窗体 释放[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)控制其非模式[Form](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.form)父级关闭。 WPF 释放[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素时关闭应用程序。 可以显示[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)中的元素[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)中Windows 窗体消息循环。 在这种情况下，代码可能不会收到应用程序正在关闭的通知。

### 启用视觉样式

Windows 窗体控件上的 Microsoft Windows XP 视觉样式可能未启用。 [Application.EnableVisualStyles](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.application.enablevisualstyles)方法调用的模板中Windows 窗体应用程序。 尽管默认情况下不会调用此方法，但如果使用 Visual Studio 创建项目，并且 Comctl32.dll 版本 6.0 可用，将会获得控件的 Microsoft Windows XP 视觉样式。 必须调用[EnableVisualStyles](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.application.enablevisualstyles)方法之前在线程上创建句柄。 有关详细信息，请参阅[如何：混合应用程序中启用视觉样式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-enable-visual-styles-in-a-hybrid-application)。

### 授权控件

授权的 Windows 窗体控件会在消息框中向用户显示许可信息，对于混合应用程序，这可能会导致意外行为。 某些授权控件会显示一个对话框来响应创建句柄的操作。 例如，授权控件可能会通知用户需要许可证，或者用户还可以试用该控件三次。

[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素派生自[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)内创建类和子控件的句柄[BuildWindowCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost.buildwindowcore)方法。 [HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)类不允许在处理消息[BuildWindowCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost.buildwindowcore)方法，但显示对话框会导致消息发送。 若要启用此许可方案，请调用[Control.CreateControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.createcontrol)方法之前将其作为分配在控件上的[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素的子级。

### WPF 设计器

可以使用 适用于 Visual Studio 的 WPF 设计器 设计你的 WPF 内容。 以下部分列出了在使用 WPF 设计器 创作混合应用程序时可能发生的一些常见问题。

#### 在设计时忽略 BackColorTransparent

[BackColorTransparent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost.backcolortransparent)按预期方式在设计时属性可能无法工作。

如果 WPF 控件不可见的父级上，WPF 运行时将忽略[BackColorTransparent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost.backcolortransparent)值。 原因，[BackColorTransparent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost.backcolortransparent)可能会忽略其原因在于[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)中单独创建对象时[AppDomain](https://docs.microsoft.com/zh-cn/dotnet/api/system.appdomain)。 但是，当运行该应用程序，[BackColorTransparent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost.backcolortransparent)按预期方式工作原理。

#### 删除 obj 文件夹时出现设计时错误列表

如果删除 obj 文件夹，会出现设计时错误列表。

当您使用设计时[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)，Windows 窗体设计器使用您的项目的 obj 文件夹内 Debug 或 Release 文件夹中生成的文件。 如果删除这些文件，将出现设计时错误列表。 若要解决此问题，请重新生成项目。 有关详细信息，请参阅 [Windows 窗体设计器中的设计时错误](https://docs.microsoft.com/zh-cn/dotnet/framework/winforms/controls/design-time-errors-in-the-windows-forms-designer)。

### ElementHost 和 IME

WPF 控件中托管[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)目前不支持[ImeMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.imemode)属性。 将更改为[ImeMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.imemode)所承载的控件将被忽略。

## [Walkthrough: Hosting a Windows Forms Control in WPF](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/walkthrough-hosting-a-windows-forms-control-in-wpf)

WPF 提供了许多具有丰富功能集的控件。 但是，您可能有时想要使用Windows 窗体上的控件在WPF页。 例如，可能有大量现有投入Windows 窗体控件，或者您可能需Windows 窗体控件，用于提供的独特功能。

本演练演示如何承载Windows 窗体[System.Windows.Forms.MaskedTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.maskedtextbox)控制上WPF使用代码页。

在本演练中所示的任务的完整代码列表，请参阅[承载 Windows 窗体控件在 WPF 示例中](https://go.microsoft.com/fwlink/?LinkID=160057)。

### 系统必备

若要完成本演练，必须具有 Visual Studio。

### 承载 Windows 窗体控件

#### 承载 MaskedTextBox 控件

1. 创建一个名为的 WPF 应用程序项目`HostingWfInWpf`。

2. 添加对下列程序集的引用。

   - WindowsFormsIntegration
   - System.Windows.Forms

3. 打开 MainWindow.xaml 中的WPF 设计器。

4. 名称[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素`grid1`。

   ```xaml
   <Grid Name="grid1">
       
   </Grid>
   ```

5. 在设计视图或 XAML 视图中，选择[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)元素。

6. 在属性窗口中，单击**事件**选项卡。

7. 双击[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)事件。

8. 插入以下代码以处理[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)事件。

   ```csharp
   private void Window_Loaded(object sender, RoutedEventArgs e) 
   {
       // Create the interop host control.
       System.Windows.Forms.Integration.WindowsFormsHost host =
           new System.Windows.Forms.Integration.WindowsFormsHost();
   
       // Create the MaskedTextBox control.
       MaskedTextBox mtbDate = new MaskedTextBox("00/00/0000");
   
       // Assign the MaskedTextBox control as the host control's child.
       host.Child = mtbDate;
   
       // Add the interop host control to the Grid
       // control's collection of child controls.
       this.grid1.Children.Add(host);
   }
   ```

9. 在文件顶部，添加以下`Imports`或`using`语句。

   ```csharp
   using System.Windows.Forms;
   ```

10. 按 F5 生成并运行该应用程序。

## [Walkthrough: Hosting a Windows Forms Control in WPF by Using XAML](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/walkthrough-hosting-a-windows-forms-control-in-wpf-by-using-xaml)

WPF 提供了许多具有丰富功能集的控件。 但是，您可能有时想要使用Windows 窗体上的控件在WPF页。 例如，可能有大量现有投入Windows 窗体控件，或者您可能需Windows 窗体控件，用于提供的独特功能。

本演练演示如何承载 Windows 窗体[System.Windows.Forms.MaskedTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.maskedtextbox)对的 control 权限WPF页上通过使用XAML。

在本演练中所示的任务的完整代码列表，请参阅[承载 Windows 窗体控件在 WPF 中使用 XAML 示例](https://go.microsoft.com/fwlink/?LinkID=160000)。

### 系统必备

若要完成本演练，必须具有 Visual Studio。

### 承载 Windows 窗体控件

#### 承载 MaskedTextBox 控件

1. 创建一个名为的 WPF 应用程序项目`HostingWfInWpfWithXaml`。

2. 添加对下列程序集的引用。

   - WindowsFormsIntegration
   - System.Windows.Forms

3. 打开 MainWindow.xaml 中的WPF 设计器。

4. 在[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)元素中，添加以下命名空间映射。 `wf`命名空间映射建立对包含在 Windows 窗体控件的程序集的引用。

   ```xaml
   xmlns:wf="clr-namespace:System.Windows.Forms;assembly=System.Windows.Forms"  
   ```

5. 在[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)添加以下 XAML 元素。

   [MaskedTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.maskedtextbox)控件被创建为的子[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)控件。

   ```xaml
   <Grid>
   
       <WindowsFormsHost>
           <wf:MaskedTextBox x:Name="mtbDate" Mask="00/00/0000"/>
       </WindowsFormsHost>
   
   </Grid>
   ```

6. 按 F5 生成并运行该应用程序。

## [Walkthrough: Hosting a Windows Forms Composite Control in WPF](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/walkthrough-hosting-a-windows-forms-composite-control-in-wpf)

Windows Presentation Foundation (WPF) 提供了用于创建应用程序的丰富环境。 但是，当您有大量投入时Windows 窗体代码，它可以更有效地重复使用至少某些中的代码在WPF应用程序而不是从头开始重新编写。 最常见的方案是具有现有 Windows 窗体控件。 在某些情况下，你甚至可能无法使用这些控件的源代码。 WPF 提供一个简单的过程中的此类控件承载WPF应用程序。 例如，可以使用WPF对于大多数应用编程，同时承载专用[DataGridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.datagridview)控件。

本演练将指导你逐步承载 Windows 窗体复合控件以执行中的数据输入的应用程序WPF应用程序。 复合控件打包在一个 DLL 中。 此常规步骤可扩展到更复杂的应用程序和控件。 本演练旨在几乎完全相同的外观和功能到[演练：承载 WPF 复合控件在 Windows 窗体中的](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/walkthrough-hosting-a-wpf-composite-control-in-windows-forms)。 主要区别在于承载方案是相反的。

本演练分为两个部分。 第一部分简要介绍 Windows 窗体复合控件的实现。 第二个部分详细讨论如何托管中的复合控件WPF应用程序，接收来自控件的事件和访问的某些控件的属性。

本演练涉及以下任务：

- 实现 Windows 窗体复合控件。
- 实现 WPF 主机应用程序。

在本演练中所涉及任务的完整代码列表，请参阅[承载 Windows 窗体复合控件在 WPF 示例中](https://go.microsoft.com/fwlink/?LinkID=159999)。

### 系统必备

若要完成本演练，必须具有 Visual Studio。

### 实现 Windows 窗体复合控件

在此示例中使用的 Windows 窗体复合控件是一个简单的数据输入窗体。 此窗体需要用户名和地址，然后使用自定义事件将该信息返回到主机。 下图显示呈现的控件。

![简单 Windows 窗体控件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/wfcontrol.gif)
Windows 窗体复合控件

#### 创建项目

启动项目：

1. 启动Microsoft Visual Studio，并打开**新建项目**对话框。
2. 在窗口类别，选择**Windows 窗体控件库**模板。
3. 将新项目命名为 `MyControls`。
4. 对于位置，指定可以方便命名的顶层文件夹，如`WpfHostingWindowsFormsControl`。 随后，将主机应用程序放在此文件夹中。
5. 单击“确定”，创建项目。 默认项目包含名为的单个控件`UserControl1`。
6. 在解决方案资源管理器，重命名`UserControl1`到`MyControl1`。

项目应具有对以下系统 DLL 的引用。 如果默认不包含其中任何 DLL，则将它们添加到项目中。

- 系统
- System.Data
- System.Drawing
- System.Windows.Forms
- System.Xml

#### 将控件添加到窗体

向窗体添加控件：

- 打开`MyControl1`在设计器中。

添加五个[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.label)及其对应[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.textbox)控件，调整大小和排列方式与其在上图中，在窗体上。 在示例中，[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.textbox)控件命名为：

- `txtName`
- `txtAddress`
- `txtCity`
- `txtState`
- `txtZip`

添加两个[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.button)控件标记为**确定**并**取消**。 在此示例中，按钮名称是`btnOK`和`btnCancel`分别。

#### 实现支持代码

在代码视图中打开窗体。 控件返回到其主机通过引发自定义的收集的数据`OnButtonClick`事件。 数据包含在事件自变量对象中。 以下代码演示事件和委托声明。

向 `MyControl1` 类添加下面的代码。

```csharp
public delegate void MyControlEventHandler(object sender, MyControlEventArgs args);
public event MyControlEventHandler OnButtonClick;
```

`MyControlEventArgs`类包含要返回到主机的信息。

将以下类添加到窗体中。

```csharp
public class MyControlEventArgs : EventArgs
{
    private string _Name;
    private string _StreetAddress;
    private string _City;
    private string _State;
    private string _Zip;
    private bool _IsOK;

    public MyControlEventArgs(bool result,
                                   string name,
                                   string address,
                                   string city,
                                   string state,
                                   string zip)
    {
        _IsOK = result;
        _Name = name;
        _StreetAddress = address;
        _City = city;
        _State = state;
        _Zip = zip;
    }

    public string MyName
    {
        get { return _Name; }
        set { _Name = value; }
    }
    public string MyStreetAddress
    {
        get { return _StreetAddress; }
        set { _StreetAddress = value; }
    }
    public string MyCity
    {
        get { return _City; }
        set { _City = value; }
    }
    public string MyState
    {
        get { return _State; }
        set { _State = value; }
    }
    public string MyZip
    {
        get { return _Zip; }
        set { _Zip = value; }
    }
    public bool IsOK
    {
        get { return _IsOK; }
        set { _IsOK = value; }
    }
}
```

当用户单击**确定**或**取消**按钮，[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.click)事件处理程序创建`MyControlEventArgs`对象，其中包含数据，并引发`OnButtonClick`事件。 两个处理程序之间的唯一区别是事件自变量的`IsOK`属性。 此属性使主机可以确定单击的按钮。 设置为`true`有关**确定**按钮，并`false`有关**取消**按钮。 以下代码演示两个按钮处理程序。

向 `MyControl1` 类添加下面的代码。

C#复制

```csharp
private void btnOK_Click(object sender, System.EventArgs e)
{

    MyControlEventArgs retvals = new MyControlEventArgs(true,
                                                         txtName.Text,
                                                         txtAddress.Text,
                                                         txtCity.Text,
                                                         txtState.Text,
                                                         txtZip.Text);
    OnButtonClick(this, retvals);
}

private void btnCancel_Click(object sender, System.EventArgs e)
{
    MyControlEventArgs retvals = new MyControlEventArgs(false,
                                                         txtName.Text,
                                                         txtAddress.Text,
                                                         txtCity.Text,
                                                         txtState.Text,
                                                         txtZip.Text);
    OnButtonClick(this, retvals);
}
```

#### 赋予程序集强名称并生成程序集

此程序集引用的WPF应用程序，它必须具有强名称。 若要创建强名称，使用 Sn.exe 创建密钥文件并将其添加到你的项目。

1. 打开一个 Visual Studio 命令提示符。 若要执行此操作，请单击**启动**菜单，并选择**所有 Programs/Microsoft Visual Studio 2010/Visual Studio Tools/Visual Studio 命令提示符**。 这将启动包含自定义环境变量的控制台窗口。

2. 在命令提示符下，使用`cd`命令可以转到你的项目文件夹。

3. 通过运行以下命令生成名为 MyControls.snk 的密钥文件。

   ```
   Sn.exe -k MyControls.snk
   ```

4. 要在项目中包含的密钥文件，右键单击解决方案资源管理器中的项目名称，然后单击**属性**。 在项目设计器中，单击**签名**选项卡上，选择**程序集签名**复选框，然后浏览到你的密钥文件。

5. 生成解决方案。 生成将产生一个名为 MyControls.dll 的 DLL。

### 实现 WPF 主机应用程序

WPF宿主应用程序使用[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)控件来承载`MyControl1`。 该应用程序处理`OnButtonClick`事件以接收来自控件的数据。 它还具有一组选项按钮，您可以更改某些控件的属性从WPF应用程序。 下图显示已完成的应用程序。

![在 WPF 页中嵌入的控件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/avalonhost.gif)完整的应用程序，显示控件嵌入在 WPF 应用程序

#### 创建项目

启动项目：

1. 打开Visual Studio，然后选择**新建项目**。
2. 在窗口类别，选择**WPF 应用程序**模板。
3. 将新项目命名为 `WpfHost`。
4. 对于位置，指定包含 MyControls 项目的同一顶层文件夹。
5. 单击“确定”，创建项目。

此外需要添加对包含的 DLL 的引用`MyControl1`和其他程序集。

1. 右键单击解决方案资源管理器中的项目名称并选择**添加引用**。
2. 单击**浏览**选项卡，然后浏览到包含 MyControls.dll 的文件夹。 在本演练中，此文件夹位于 MyControls\bin\Debug。
3. 选择 MyControls.dll，然后依次**确定**。
4. 添加对 WindowsFormsIntegration 程序集，它名为 WindowsFormsIntegration.dll 的引用。

#### 实现基本布局

用户界面 (UI)的主机在 MainWindow.xaml 中实现应用程序。 此文件包含可扩展应用程序标记语言 (XAML)定义布局，并托管在 Windows 窗体控件的标记。 该应用程序分为三个区域：

- **控件属性**面板，其中包含一组可用于修改所承载控件的各种属性的选项按钮。
- **来自控件的数据**面板，其中包含几个[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)从承载控件返回显示的数据的元素。
- 所承载控件本身。

基本布局如下面的 XAML 中所示。 需要的标记到主机`MyControl1`从本示例中，省略了，但将在下文。

将 MainWindow.xaml 中的 XAML 替换为以下内容。 如果使用的 Visual Basic，更改到类`x:Class="MainWindow"`。

```xaml
<Window xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      x:Class="WpfHost.MainWindow"
      xmlns:mcl="clr-namespace:MyControls;assembly=MyControls"
      Loaded="Init">
  <DockPanel>
    <DockPanel.Resources>
      <Style x:Key="inlineText" TargetType="{x:Type Inline}">
        <Setter Property="FontWeight" Value="Normal"/>
      </Style>
      <Style x:Key="titleText" TargetType="{x:Type TextBlock}">
        <Setter Property="DockPanel.Dock" Value="Top"/>
        <Setter Property="FontWeight" Value="Bold"/>
        <Setter Property="Margin" Value="10,5,10,0"/>
      </Style>
    </DockPanel.Resources>

    <StackPanel Orientation="Vertical"
                DockPanel.Dock="Left"
                Background="Bisque"
                Width="250">

      <TextBlock  Margin="10,10,10,10"
                  FontWeight="Bold"
                  FontSize="12">Control Properties</TextBlock>
      <TextBlock Style="{StaticResource titleText}">Background Color</TextBlock>
      <StackPanel Margin="10,10,10,10">
        <RadioButton Name="rdbtnOriginalBackColor"
                    IsChecked="True"
                    Click="BackColorChanged">Original</RadioButton>
        <RadioButton Name="rdbtnBackGreen"
                    Click="BackColorChanged">LightGreen</RadioButton>
        <RadioButton Name="rdbtnBackSalmon"
                    Click="BackColorChanged">LightSalmon</RadioButton>
      </StackPanel>

      <TextBlock Style="{StaticResource titleText}">Foreground Color</TextBlock>
      <StackPanel Margin="10,10,10,10">
        <RadioButton Name="rdbtnOriginalForeColor"
                    IsChecked="True"
                    Click="ForeColorChanged">Original</RadioButton>
        <RadioButton Name="rdbtnForeRed"
                    Click="ForeColorChanged">Red</RadioButton>
        <RadioButton Name="rdbtnForeYellow"
                    Click="ForeColorChanged">Yellow</RadioButton>
      </StackPanel>

      <TextBlock Style="{StaticResource titleText}">Font Family</TextBlock>
      <StackPanel Margin="10,10,10,10">
        <RadioButton Name="rdbtnOriginalFamily"
                     IsChecked="True"
                    Click="FontChanged">Original</RadioButton>
        <RadioButton Name="rdbtnTimes"
                    Click="FontChanged">Times New Roman</RadioButton>
        <RadioButton Name="rdbtnWingdings"
                    Click="FontChanged">Wingdings</RadioButton>
      </StackPanel>

      <TextBlock Style="{StaticResource titleText}">Font Size</TextBlock>
      <StackPanel Margin="10,10,10,10">
        <RadioButton Name="rdbtnOriginalSize"
                    IsChecked="True"
                    Click="FontSizeChanged">Original</RadioButton>
        <RadioButton Name="rdbtnTen"
                    Click="FontSizeChanged">10</RadioButton>
        <RadioButton Name="rdbtnTwelve"
                    Click="FontSizeChanged">12</RadioButton>
      </StackPanel>

      <TextBlock Style="{StaticResource titleText}">Font Style</TextBlock>
      <StackPanel Margin="10,10,10,10">
        <RadioButton Name="rdbtnNormalStyle"
                     IsChecked="True"
                     Click="StyleChanged">Original</RadioButton>
        <RadioButton Name="rdbtnItalic"
                     Click="StyleChanged">Italic</RadioButton>
      </StackPanel>

      <TextBlock Style="{StaticResource titleText}">Font Weight</TextBlock>
      <StackPanel Margin="10,10,10,10">
        <RadioButton Name="rdbtnOriginalWeight"
                     IsChecked="True"
                   Click="WeightChanged">
          Original
        </RadioButton>
        <RadioButton Name="rdbtnBold"
                   Click="WeightChanged">Bold</RadioButton>
      </StackPanel>
    </StackPanel>

    <WindowsFormsHost Name="wfh"
                     DockPanel.Dock="Top"
                     Height="300">
      <mcl:MyControl1 Name="mc"/>
    </WindowsFormsHost>
    
    <StackPanel Orientation="Vertical"
                Height="Auto"
                Background="LightBlue">
      <TextBlock Margin="10,10,10,10"
            FontWeight="Bold"
            FontSize="12">Data From Control</TextBlock>
      <TextBlock Style="{StaticResource titleText}">
        Name: <Span Name="txtName" Style="{StaticResource inlineText}"/>
      </TextBlock>
      <TextBlock Style="{StaticResource titleText}">
        Street Address: <Span Name="txtAddress" Style="{StaticResource inlineText}"/>
      </TextBlock>
      <TextBlock Style="{StaticResource titleText}">
        City: <Span Name="txtCity" Style="{StaticResource inlineText}"/>
      </TextBlock>
      <TextBlock Style="{StaticResource titleText}">
        State: <Span Name="txtState" Style="{StaticResource inlineText}"/>
      </TextBlock>
      <TextBlock Style="{StaticResource titleText}">
        Zip: <Span Name="txtZip" Style="{StaticResource inlineText}"/>
      </TextBlock>
    </StackPanel>
  </DockPanel>
</Window>
```

第一个[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)元素包含多组[RadioButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.radiobutton)控件，您可以修改所承载控件的各种默认属性。 后跟[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素中，哪些主机`MyControl1`。 最终[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)元素包含多个[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素，用于显示所承载控件返回的数据。 排序的元素和[Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.dock)和[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)属性设置不存在的空白或扭曲使用嵌入到窗口中承载的控件。

#### 承载控件

上一个 XAML 的以下已编辑的版本重点介绍所需的元素到主机`MyControl1`。

XAML复制

```xaml
<Window xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      x:Class="WpfHost.MainWindow"
      xmlns:mcl="clr-namespace:MyControls;assembly=MyControls"
      Loaded="Init">
```

XAML复制

```xaml
<WindowsFormsHost Name="wfh"
                 DockPanel.Dock="Top"
                 Height="300">
  <mcl:MyControl1 Name="mc"/>
</WindowsFormsHost>
```

`xmlns`命名空间映射属性将创建对引用`MyControls`包含所承载的控件的命名空间。 此映射使你能够代表`MyControl1`中XAML作为`<mcl:MyControl1>`。

XAML 中的两个元素处理承载：

- `WindowsFormsHost` 表示[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素，可用于承载 Windows 窗体控件中的WPF应用程序。
- `mcl:MyControl1`表示`MyControl1`，添加到[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素的子集合。 因此，此 Windows 窗体控件呈现为一部分WPF窗口中，并且您可以与该控件从该应用程序进行通信。

#### 实现代码隐藏文件

代码隐藏文件，MainWindow.xaml.vb 或 MainWindow.xaml.cs 中，包含实现的功能的过程性代码UI前面部分所述。 主要任务有：

- 附加到事件处理程序`MyControl1`的`OnButtonClick`事件。
- 修改的各种属性`MyControl1`根据选项按钮集合的设置方式。
- 显示控件收集的数据。

#### 初始化应用程序

初始化代码包含在窗口的一个事件处理程序[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)事件，并将事件处理程序附加到控件的`OnButtonClick`事件。

在 MainWindow.xaml.vb 或 MainWindow.xaml.cs 中，以下代码添加到`MainWindow`类。

```csharp
private Application app;
private Window myWindow;
FontWeight initFontWeight;
Double initFontSize;
FontStyle initFontStyle;
SolidColorBrush initBackBrush;
SolidColorBrush initForeBrush;
FontFamily initFontFamily;
bool UIIsReady = false;

private void Init(object sender, EventArgs e)
{
    app = System.Windows.Application.Current;
    myWindow = (Window)app.MainWindow;
    myWindow.SizeToContent = SizeToContent.WidthAndHeight;
    wfh.TabIndex = 10;
    initFontSize = wfh.FontSize;
    initFontWeight = wfh.FontWeight;
    initFontFamily = wfh.FontFamily;
    initFontStyle = wfh.FontStyle;
    initBackBrush = (SolidColorBrush)wfh.Background;
    initForeBrush = (SolidColorBrush)wfh.Foreground;
    (wfh.Child as MyControl1).OnButtonClick += new MyControl1.MyControlEventHandler(Pane1_OnButtonClick);
    UIIsReady = true;
}
```

因为XAML讨论之前添加`MyControl1`到[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素的子元素集合，可以强制转换[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素的[Child](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost.child)若要获取对引用`MyControl1`。 然后可以使用该引用将附加到事件处理程序`OnButtonClick`。

除了提供对控件本身的引用[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)公开多个控件的属性，您可以从应用程序操作。 初始化代码将这些值分配给私有全局变量，以供稍后在应用程序中使用。

以便可以轻松地访问中的类型`MyControls`DLL，添加以下`Imports`或`using`到文件顶部的语句。

C#复制

```csharp
using MyControls;
```

#### 处理 OnButtonClick 事件

`MyControl1` 引发`OnButtonClick`事件，当用户单击任一控件的按钮。

向 `MainWindow` 类添加下面的代码。

C#复制

```csharp
//Handle button clicks on the Windows Form control
private void Pane1_OnButtonClick(object sender, MyControlEventArgs args)
{
    txtName.Inlines.Clear();
    txtAddress.Inlines.Clear();
    txtCity.Inlines.Clear();
    txtState.Inlines.Clear();
    txtZip.Inlines.Clear();

    if (args.IsOK)
    {
        txtName.Inlines.Add( " " + args.MyName );
        txtAddress.Inlines.Add( " " + args.MyStreetAddress );
        txtCity.Inlines.Add( " " + args.MyCity );
        txtState.Inlines.Add( " " + args.MyState );
        txtZip.Inlines.Add( " " + args.MyZip );
    }
}
```

在文本框中的数据打包到`MyControlEventArgs`对象。 如果用户单击**确定**按钮，事件处理程序中提取数据并将其显示下方的面板中`MyControl1`。

#### 修改控件属性

[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素公开多个托管的控件的默认属性。 因此，可以更改空间外观，以更贴合应用程序的样式。 位于左侧面板中的选项按钮组使用户能够修改多个颜色和字体属性。 按钮的每个集具有的处理程序[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件，它检测到用户的选项按钮选择和更改控件上的相应属性。

向 `MainWindow` 类添加下面的代码。

C#复制

```csharp
private void BackColorChanged(object sender, RoutedEventArgs e)
{
    if (sender == rdbtnBackGreen)
        wfh.Background = new SolidColorBrush(Colors.LightGreen);
    else if (sender == rdbtnBackSalmon)
        wfh.Background = new SolidColorBrush(Colors.LightSalmon);
    else if (UIIsReady == true)
        wfh.Background = initBackBrush;
}

private void ForeColorChanged(object sender, RoutedEventArgs e)
{
    if (sender == rdbtnForeRed)
        wfh.Foreground = new SolidColorBrush(Colors.Red);
    else if (sender == rdbtnForeYellow)
        wfh.Foreground = new SolidColorBrush(Colors.Yellow);
    else if (UIIsReady == true)
        wfh.Foreground = initForeBrush;
}

private void FontChanged(object sender, RoutedEventArgs e)
{
    if (sender == rdbtnTimes)
        wfh.FontFamily = new FontFamily("Times New Roman");
    else if (sender == rdbtnWingdings)
        wfh.FontFamily = new FontFamily("Wingdings");
    else if (UIIsReady == true)
        wfh.FontFamily = initFontFamily;
}
private void FontSizeChanged(object sender, RoutedEventArgs e)
{
    if (sender == rdbtnTen)
        wfh.FontSize = 10;
    else if (sender == rdbtnTwelve)
        wfh.FontSize = 12;
    else if (UIIsReady == true)
        wfh.FontSize = initFontSize;
}
private void StyleChanged(object sender, RoutedEventArgs e)
{
    if (sender == rdbtnItalic)
        wfh.FontStyle = FontStyles.Italic;
    else if (UIIsReady == true)
        wfh.FontStyle = initFontStyle;
}
private void WeightChanged(object sender, RoutedEventArgs e)
{
    if (sender == rdbtnBold)
        wfh.FontWeight = FontWeights.Bold;
    else if (UIIsReady == true)
        wfh.FontWeight = initFontWeight;
}
```

生成并运行应用程序。 在 Windows 窗体复合控件中添加一些文本，然后单击**确定**。 文本将显示在标签中。 单击不同的单选按钮查看在控件上的效果。

## [Walkthrough: Hosting an ActiveX Control in WPF](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/walkthrough-hosting-an-activex-control-in-wpf)

若要启用改进与浏览器交互，可以使用Microsoft ActiveX中的控件在WPF-基于应用程序。 本演练演示如何可以承载Microsoft Windows Media Player上的控件作为WPF页。

本演练涉及以下任务：

- 创建项目。
- 创建 ActiveX 控件。
- 承载 WPF 页上的 ActiveX 控件。

完成本演练后，您将了解如何使用Microsoft ActiveX中的控件在WPF-基于应用程序。

### 系统必备

你需要以下组件来完成本演练：

- Microsoft Windows Media Player 安装 Visual Studio 的计算机上安装。
- Visual Studio 2010。

### 创建项目

#### 创建并设置项目

1. 创建一个名为的 WPF 应用程序项目`HostingAxInWpf`。

2. 将 Windows 窗体控件库项目添加到解决方案，并将项目命名`WmpAxLib`。

3. 在 WmpAxLib 项目中，将添加到名为 wmp.dll 的 Windows Media Player 程序集的引用。

4. 打开**工具箱**。

5. 在中右击**工具箱**，然后单击**选择项**。

6. 单击**COM 组件**选项卡上，选择**Windows Media Player**控件，，然后单击**确定**。

   Windows Media Player 控件添加到**工具箱**。

7. 在解决方案资源管理器中右键单击**UserControl1**文件，，然后单击**重命名**。

8. 将名称更改为`WmpAxControl.vb`或`WmpAxControl.cs`，取决于语言。

9. 如果系统提示重命名所有引用，请单击**是**。

### 创建 ActiveX 控件

Microsoft Visual Studio 自动生成[AxHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.axhost)包装类Microsoft ActiveX控制时该控件添加到设计图面。 以下过程创建名为 AxInterop.WMPLib.dll 托管程序集。

#### 若要创建 ActiveX 控件

1. 在 Windows 窗体设计器中打开 WmpAxControl.vb 或 WmpAxControl.cs。
2. 从**工具箱**，将 Windows Media Player 控件添加到设计图面。
3. 在属性窗口中，将 Windows Media Player 控件的值设置[Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.dock)属性设置为[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.dockstyle#System_Windows_Forms_DockStyle_Fill)。
4. 生成 WmpAxLib 控件库项目。

### 承载 WPF 页上的 ActiveX 控件

#### 若要承载 ActiveX 控件

1. 在 HostingAxInWpf 项目中，添加到生成的引用ActiveX互操作性程序集。

   此程序集名为 AxInterop.WMPLib.dll 和时导入 Windows Media Player 控件添加到 WmpAxLib 项目的调试文件夹。

2. 添加对 WindowsFormsIntegration 程序集，它名为 WindowsFormsIntegration.dll 的引用。

3. 添加对引用Windows 窗体名为 system.windows.forms.dll 的引用的程序集。

4. 在 WPF 设计器中打开 MainWindow.xaml。

5. 名称[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素`grid1`。

   XAML复制

   ```xaml
   <Grid Name="grid1">
       
   </Grid>
   ```

6. 在设计视图或 XAML 视图中，选择[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)元素。

7. 在属性窗口中，单击**事件**选项卡。

8. 双击[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)事件。

9. 插入以下代码以处理[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)事件。

   此代码创建的实例[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)控件，添加的实例`AxWindowsMediaPlayer`作为其子级的控件。

   C#复制

   ```csharp
   private void Window_Loaded(object sender, RoutedEventArgs e) 
   {
       // Create the interop host control.
       System.Windows.Forms.Integration.WindowsFormsHost host =
           new System.Windows.Forms.Integration.WindowsFormsHost();
   
       // Create the ActiveX control.
       WmpAxLib.AxWindowsMediaPlayer axWmp = new WmpAxLib.AxWindowsMediaPlayer();
   
       // Assign the ActiveX control as the host control's child.
       host.Child = axWmp;
   
       // Add the interop host control to the Grid
       // control's collection of child controls.
       this.grid1.Children.Add(host);
   
       // Play a .wav file with the ActiveX control.
       axWmp.URL = @"C:\Windows\Media\tada.wav";
   }
   ```

10. 按 F5 生成并运行该应用程序。

## [How to: Enable Visual Styles in a Hybrid Application](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-enable-visual-styles-in-a-hybrid-application)

本主题演示如何启用Microsoft Windows XP上的视觉样式Windows 窗体控件中托管WPF-基于应用程序。

如果你的应用程序调用[EnableVisualStyles](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.application.enablevisualstyles)方法中，大部分你Windows 窗体控件将自动使用视觉样式时上运行你的应用程序Microsoft Windows XP。 有关详细信息，请参阅[以视觉样式呈现控件](https://docs.microsoft.com/zh-cn/dotnet/framework/winforms/controls/rendering-controls-with-visual-styles)。

本主题中所涉及任务的完整代码列表，请参阅[混合应用程序示例中启用视觉样式](https://go.microsoft.com/fwlink/?LinkID=159986)。

### 启用 Windows 窗体视觉样式

#### 启用 Windows 窗体视觉样式

1. 创建WPF应用程序项目中名为`HostingWfWithVisualStyles`。

2. 在解决方案资源管理器中，添加对下列程序集的引用。

   - WindowsFormsIntegration
   - System.Windows.Forms

3. 在工具箱中，双击[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)图标将[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)设计图面上的元素。

4. 在属性窗口中设置的值[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)并[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)属性设置为**自动**。

5. 在设计视图或 XAML 视图中，选择[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)。

6. 在属性窗口中，单击**事件**选项卡。

7. 双击[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)事件。

8. 在 MainWindow.xaml.vb 或 MainWindow.xaml.cs 中，插入以下代码以处理[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)事件。

   ```csharp
   private void Window_Loaded(object sender, RoutedEventArgs e)
   {
       // Comment out the following line to disable visual
       // styles for the hosted Windows Forms control.
       System.Windows.Forms.Application.EnableVisualStyles();
   
       // Create a WindowsFormsHost element to host
       // the Windows Forms control.
       System.Windows.Forms.Integration.WindowsFormsHost host = 
           new System.Windows.Forms.Integration.WindowsFormsHost();
   
       // Create a Windows Forms tab control.
       System.Windows.Forms.TabControl tc = new System.Windows.Forms.TabControl();
       tc.TabPages.Add("Tab1");
       tc.TabPages.Add("Tab2");
   
       // Assign the Windows Forms tab control as the hosted control.
       host.Child = tc;
   
       // Assign the host element to the parent Grid element.
       this.grid1.Children.Add(host);
   }
   ```

9. 按 F5 生成并运行该应用程序。

   Windows 窗体用视觉样式绘制控件。

### 禁用 Windows 窗体视觉样式

若要禁用视觉样式，只需删除对调用[EnableVisualStyles](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.application.enablevisualstyles)方法。

#### 禁用 Windows 窗体视觉样式

1. 在代码编辑器中打开 MainWindow.xaml.vb 或 MainWindow.xaml.cs。

2. 注释掉对的调用[EnableVisualStyles](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.application.enablevisualstyles)方法。

3. 按 F5 生成并运行该应用程序。

   Windows 窗体控件变为默认系统样式。

## [Walkthrough: Arranging Windows Forms Controls in WPF](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/walkthrough-arranging-windows-forms-controls-in-wpf)

本演练演示如何使用WPF布局功能来排列Windows 窗体混合应用程序中的控件。

本演练涉及以下任务：

- 创建项目。
- 使用默认布局设置。
- 根据内容调整大小。
- 使用绝对定位。
- 显式指定大小。
- 设置布局属性。
- 了解 Z 顺序限制。
- 停靠。
- 设置可见性。
- 承载不拉伸的控件。
- 缩放。
- 旋转。
- 设置填充和边距。
- 使用动态布局容器。

在本演练中所涉及任务的完整代码列表，请参阅[在 WPF 示例中排列 Windows 窗体控件](https://go.microsoft.com/fwlink/?LinkID=159971)。

完成后，必须了解Windows 窗体布局中的功能WPF-基于应用程序。

### 系统必备

若要完成本演练，必须具有 Visual Studio。

### 创建项目

#### 创建并设置项目

1. 创建一个名为的 WPF 应用程序项目`WpfLayoutHostingWf`。

2. 在解决方案资源管理器中，添加对下列程序集的引用。

   - WindowsFormsIntegration
   - System.Windows.Forms
   - System.Drawing

3. 双击 MainWindow.xaml，在 XAML 视图中将其打开。

4. 在中[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)元素中，添加以下Windows 窗体命名空间映射。

   XAML复制

   ```xaml
   xmlns:wf="clr-namespace:System.Windows.Forms;assembly=System.Windows.Forms"  
   ```

5. 在中[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素集[ShowGridLines](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid.showgridlines)属性设置为`true`并定义五行三列。

   XAML复制

   ```xaml
   <Grid ShowGridLines="true">
     <Grid.RowDefinitions>
       <RowDefinition/>
       <RowDefinition/>
       <RowDefinition/>
       <RowDefinition/>
       <RowDefinition/>
     </Grid.RowDefinitions>
   
     <Grid.ColumnDefinitions>
       <ColumnDefinition/>
       <ColumnDefinition/>
       <ColumnDefinition/>
     </Grid.ColumnDefinitions>
   ```

### 使用默认布局设置

默认情况下[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素处理承载的布局Windows 窗体控件。

#### 使用默认布局设置

1. 将复制到以下 XAML[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素。

   ```xaml
   <!-- Default layout. -->
   <Canvas Grid.Row="0" Grid.Column="0">
     <WindowsFormsHost Background="Yellow">
       <wf:Button Text="Windows Forms control" FlatStyle="Flat"/>
     </WindowsFormsHost>
   </Canvas>
   ```

2. 按 F5 生成并运行该应用程序。 Windows 窗体 [System.Windows.Forms.Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.button)控件会出现在[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)。 所承载的控件根据其内容调整大小和[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素大小以适应所承载的控件。

### 按内容调整大小

[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素可确保所承载的控件调整大小以正确显示其内容。

#### 按内容调整大小

1. 将复制到以下 XAML[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素。

   ```xaml
   <!-- Sizing to content. -->
   <Canvas Grid.Row="1" Grid.Column="0">
     <WindowsFormsHost Background="Orange">
       <wf:Button Text="Windows Forms control with more content" FlatStyle="Flat"/>
     </WindowsFormsHost>
   </Canvas>
   
   <Canvas Grid.Row="2" Grid.Column="0">
     <WindowsFormsHost FontSize="24" Background="Yellow">
       <wf:Button Text="Windows Forms control" FlatStyle="Flat"/>
     </WindowsFormsHost>
   </Canvas>
   ```

2. 按 F5 生成并运行该应用程序。 两个新按钮控件会调整大小以正确，显示较长文本字符串和较大字号和[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)调整元素大小以容纳所承载的控件。

### 使用绝对定位

可以使用绝对定位将[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)用户界面 (UI) 中的任意位置的元素。

#### 使用绝对定位

1. 将复制到以下 XAML[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素。

   ```xaml
   <!-- Absolute positioning. -->
   <Canvas Grid.Row="3" Grid.Column="0">
     <WindowsFormsHost Canvas.Top="20" Canvas.Left="20" Background="Yellow">
       <wf:Button Text="Windows Forms control with absolute positioning" FlatStyle="Flat"/>
     </WindowsFormsHost>
   </Canvas>
   ```

2. 按 F5 生成并运行该应用程序。 [WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素放在距顶部的网格单元格的 20 像素，距左侧 20 像素。

### 显式指定大小

可以指定的大小[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素使用[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)和[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)属性。

#### 显式指定大小

1. 将复制到以下 XAML[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素。

   ```xaml
   <!-- Explicit sizing. -->
   <Canvas Grid.Row="4" Grid.Column="0">
     <WindowsFormsHost Width="50" Height="70" Background="Yellow">
       <wf:Button Text="Windows Forms control" FlatStyle="Flat"/>
     </WindowsFormsHost>
   </Canvas>
   ```

2. 按 F5 生成并运行该应用程序。 [WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素设置为的大小为宽 50 像素高 70 像素，这是比默认布局设置小。 内容Windows 窗体相应重新排列控件。

### 设置布局属性

始终使用的属性对承载控件设置布局相关属性[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素。 直接对承载控件设置布局属性会产生意外结果。

在承载控件设置布局相关属性XAML不起作用。

#### 查看对承载控件设置属性的效果

1. 将复制到以下 XAML[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素。

   ```xaml
   <!-- Setting hosted control properties directly. -->
   <Canvas Grid.Row="0" Grid.Column="1">
     <WindowsFormsHost Width="160" Height="50" Background="Yellow">
       <wf:Button Name="button1" Click="button1_Click" Text="Click me" FlatStyle="Flat" BackColor="Green"/>
     </WindowsFormsHost>
   </Canvas>
   ```

2. 在“解决方案资源管理器”中，双击 MainWindow.xaml. vb 或 MainWindow.xaml.cs 在代码编辑器中将其打开。

3. 以下代码复制到`MainWindow`类定义。

   ```csharp
   private void button1_Click(object sender, EventArgs e )
   {
       System.Windows.Forms.Button b = sender as System.Windows.Forms.Button;
   
       b.Top = 20;
       b.Left = 20;
   }
   ```

4. 按 F5 生成并运行该应用程序。

5. 单击**Click me**按钮。 `button1_Click`事件处理程序集[Top](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.top)和[Left](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.left)上所承载的控件的属性。 这将导致中重新定位承载的控件[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素。 宿主保持相同的屏幕区域，但承载控件被剪裁。 相反，所承载的控件应始终填充[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素。

### 了解 Z 顺序限制

可见[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素始终绘制在其他 WPF 元素，之上，因而它们不受 z 顺序。 若要查看此 z 顺序行为，请执行以下操作：

1. 将复制到以下 XAML[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素。

   ```xaml
   <!-- Z-order demonstration. -->
   <Canvas Grid.Row="1" Grid.Column="1">
     <WindowsFormsHost Canvas.Top="20" Canvas.Left="20" Background="Yellow">
       <wf:Button Text="Windows Forms control" FlatStyle="Flat"/>
     </WindowsFormsHost>
     <Label Content="A WPF label" FontSize="24"/>
   </Canvas>
   ```

2. 按 F5 生成并运行该应用程序。 [WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素绘于标签元素上方。

### 停靠

[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost) 元素支持WPF停靠。 设置[Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.dock)附加属性以停靠中承载的控件[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)元素。

#### 停靠承载控件

1. 将复制到以下 XAML[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素。

   ```xaml
   <!-- Docking a WindowsFormsHost element. -->
   <DockPanel LastChildFill="false"  Grid.Row="2" Grid.Column="1">
     <WindowsFormsHost DockPanel.Dock="Right"  Canvas.Top="20" Canvas.Left="20" Background="Yellow">
       <wf:Button Text="Windows Forms control" FlatStyle="Flat"/>
     </WindowsFormsHost>
   </DockPanel>
   ```

2. 按 F5 生成并运行该应用程序。 [WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素的右侧停靠[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)元素。

### 设置可见性

可以让你Windows 窗体控件不可见或通过设置折叠[Visibility](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.visibility)属性上的[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素。 当控件不可见时，控件不会显示，但会占据布局空间。 当控件处于折叠状态时，控件不会显示，也不会占据布局空间。

#### 设置承载控件的可见性

1. 将复制到以下 XAML[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素。

   ```xaml
   <!-- Setting Visibility to hidden and collapsed. -->
   <StackPanel Grid.Row="3" Grid.Column="1">
     <Button Name="button2" Click="button2_Click" Content="Click to make invisible" Background="OrangeRed"/>
     <WindowsFormsHost Name="host1"  Background="Yellow">
       <wf:Button Text="Windows Forms control" FlatStyle="Flat"/>
     </WindowsFormsHost>
     <Button Name="button3" Click="button3_Click" Content="Click to collapse" Background="OrangeRed"/>
   </StackPanel>
   ```

2. 在 MainWindow.xaml.vb 或 MainWindow.xaml.cs 中，将以下代码复制到类定义。

   ```csharp
   private void button2_Click(object sender, EventArgs e)
   {
       this.host1.Visibility = Visibility.Hidden;
   }
   
   private void button3_Click(object sender, EventArgs e)
   {
       this.host1.Visibility = Visibility.Collapsed;
   }
   ```

3. 按 F5 生成并运行该应用程序。

4. 单击**单击此项可使不可见**按钮，使[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素不可见。

5. 单击**单击此项可折叠**按钮以隐藏[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素在布局完全。 当Windows 窗体控件处于折叠状态，周围的元素会重新排列以占据其空间。

### 承载不拉伸的控件

某些Windows 窗体控件具有固定的大小，不会拉伸以填充布局中的可用空间。 例如，[MonthCalendar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.monthcalendar)控件在固定的空间中显示一个月。

#### 承载不拉伸的控件

1. 将复制到以下 XAML[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素。

   ```xaml
   <!-- Hosting a control that does not stretch. -->
   <!-- The MonthCalendar has a discrete size. -->
   <StackPanel Grid.Row="4" Grid.Column="1">
     <Label Content="A WPF element" Background="OrangeRed"/>
     <WindowsFormsHost Background="Yellow">
       <wf:MonthCalendar/>
     </WindowsFormsHost>
     <Label Content="Another WPF element" Background="OrangeRed"/>
   </StackPanel>
   ```

2. 按 F5 生成并运行该应用程序。 [WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素居中在网格行中，但它不会拉伸以填充可用空间。如果窗口足够大，可能会看到显示所承载的两个或多个月[MonthCalendar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.monthcalendar)控件，但这些行中居中。 WPF布局引擎中心无法调整大小以填充可用空间的元素。

### 缩放

与 WPF 元素不同大多数 Windows 窗体控件不是连续方式缩放。 若要提供自定义缩放，重写[WindowsFormsHost.ScaleChild](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost.scalechild)方法。

#### 使用默认行为缩放承载控件

1. 将复制到以下 XAML[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素。

   ```xaml
   <!-- Scaling transformation. -->
   <StackPanel Grid.Row="0" Grid.Column="2">
     
     <StackPanel.RenderTransform>
       <ScaleTransform CenterX="0" CenterY="0" ScaleX="0.5" ScaleY="0.5" />
     </StackPanel.RenderTransform>
   
     <Label Content="A WPF UIElement" Background="OrangeRed"/>
     
     <WindowsFormsHost Background="Yellow">
       <wf:Button Text="Windows Forms control" FlatStyle="Flat"/>
     </WindowsFormsHost>
     
     <Label Content="Another WPF UIElement" Background="OrangeRed"/>
     
   </StackPanel>
   ```

2. 按 F5 生成并运行该应用程序。 承载控件及其周围元素按 0.5 的比例进行缩放。 但是，承载控件的字体不缩放。

### 旋转

与 WPF 元素不同 Windows 窗体控件不支持旋转。 [WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素不会不会旋转与其他 WPF 元素时应用旋转转换。 180 度引发以外的任何旋转值[LayoutError](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost.layouterror)事件。

#### 查看混合应用程序中的旋转效果

1. 将复制到以下 XAML[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素。

   ```xaml
   <!-- Rotation transformation. -->
   <StackPanel Grid.Row="1" Grid.Column="2">
   
     <StackPanel.RenderTransform>
       <RotateTransform CenterX="200" CenterY="50" Angle="180" />
     </StackPanel.RenderTransform>
   
     <Label Content="A WPF element" Background="OrangeRed"/>
   
     <WindowsFormsHost Background="Yellow">
       <wf:Button Text="Windows Forms control" FlatStyle="Flat"/>
     </WindowsFormsHost>
   
     <Label Content="Another WPF element" Background="OrangeRed"/>
   
   </StackPanel>
   ```

2. 按 F5 生成并运行该应用程序。 承载控件不旋转，但是它周围的元素旋转 180 度。 可能必须调整窗口大小才能看到这些元素。

### 设置填充和边距

填充和边距中的WPF布局是类似于填充和边距中的Windows 窗体。 只需将设置[Padding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.padding)并[Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)上的属性[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素。

#### 为承载控件设置填充和边距

1. 将复制到以下 XAML[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素。

   ```xaml
   <!-- Padding. -->
   <Canvas Grid.Row="2" Grid.Column="2">
     <WindowsFormsHost Padding="0, 20, 0, 0" Background="Yellow">
       <wf:Button Text="Windows Forms control with padding" FlatStyle="Flat"/>
     </WindowsFormsHost>
   </Canvas>
   ```

   ```xaml
   <!-- Margin. -->
   <Canvas Grid.Row="3" Grid.Column="2">
     <WindowsFormsHost Margin="20, 20, 0, 0" Background="Yellow">
       <wf:Button Text="Windows Forms control with margin" FlatStyle="Flat"/>
     </WindowsFormsHost>
   </Canvas>
   ```

2. 按 F5 生成并运行该应用程序。 填充和边距设置应用于承载Windows 窗体控件中的应用方式相同Windows 窗体。

### 使用动态布局容器

Windows 窗体 提供了两个动态布局容器，[FlowLayoutPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.flowlayoutpanel)和[TableLayoutPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.tablelayoutpanel)。 此外可以使用这些容器WPF布局。

#### 使用动态布局容器

1. 将复制到以下 XAML[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素。

   ```xaml
   <!-- Flow layout. -->
   <DockPanel Grid.Row="4" Grid.Column="2">
     <WindowsFormsHost Name="flowLayoutHost" Background="Yellow">
       <wf:FlowLayoutPanel/>
     </WindowsFormsHost>
   </DockPanel>
   ```

2. 在 MainWindow.xaml.vb 或 MainWindow.xaml.cs 中，将以下代码复制到类定义。

   ```csharp
   private void InitializeFlowLayoutPanel()
   {
       System.Windows.Forms.FlowLayoutPanel flp =
           this.flowLayoutHost.Child as System.Windows.Forms.FlowLayoutPanel;
   
       flp.WrapContents = true;
   
       const int numButtons = 6;
   
       for (int i = 0; i < numButtons; i++)
       {
           System.Windows.Forms.Button b = new System.Windows.Forms.Button();
           b.Text = "Button";
           b.BackColor = System.Drawing.Color.AliceBlue;
           b.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
   
           flp.Controls.Add(b);
       }
   }
   ```

3. 将调用添加到构造函数中的 `InitializeFlowLayoutPanel` 方法。

   ```csharp
   public MainWindow()
   {
       InitializeComponent();
   
       this.InitializeFlowLayoutPanel();
   }
   ```

4. 按 F5 生成并运行该应用程序。 [WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素填充[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)，并[FlowLayoutPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.flowlayoutpanel)排列其子控件在默认[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.flowlayoutpanel.flowdirection)。

## [Walkthrough: Binding to Data in Hybrid Applications](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/walkthrough-binding-to-data-in-hybrid-applications)

无论您使用数据源绑定到控件是必需的用户提供对基础数据的访问Windows 窗体或WPF。 本演练演示如何在混合应用程序中包含这两个使用数据绑定Windows 窗体和WPF控件。

本演练涉及以下任务：

- 创建项目。
- 定义数据模板。
- 指定窗体布局。
- 指定数据绑定。
- 使用互操作功能显示数据。
- 向项目添加数据源。
- 绑定到数据源。

在本演练中所涉及任务的完整代码列表，请参阅[混合应用程序示例中的数据绑定](https://go.microsoft.com/fwlink/?LinkID=159983)。

完成本演练后，你将对混合应用程序中的数据绑定功能有所了解。

### 系统必备

你需要以下组件来完成本演练：

- Visual Studio。
- 对 Microsoft SQL Server 上运行的 Northwind 示例数据库的访问。

### 创建项目

#### 创建并设置项目

1. 创建一个名为的 WPF 应用程序项目`WPFWithWFAndDatabinding`。

2. 在解决方案资源管理器中，添加对下列程序集的引用。

   - WindowsFormsIntegration
   - System.Windows.Forms

3. 打开 MainWindow.xaml 中的WPF 设计器。

4. 在中[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)元素中，添加以下Windows 窗体命名空间映射。

   XAML复制

   ```xaml
   xmlns:wf="clr-namespace:System.Windows.Forms;assembly=System.Windows.Forms"  
   ```

5. 命名为默认值[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素`mainGrid`通过将分配[Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.name)属性。

   XAML复制

   ```xaml
   <Grid x:Name="mainGrid">
   ```

### 定义数据模板

客户的主列表显示在[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)控件。 下面的代码示例定义[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)名为对象`ListItemsTemplate`控件的可视化树[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)控件。 这[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)分配给[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)控件的[ItemTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemtemplate)属性。

#### 定义数据模板

- 将复制到以下 XAML[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素的声明。

  XAML复制

  ```xaml
  <Grid.Resources>
      <DataTemplate x:Key="ListItemsTemplate">
          <TextBlock Text="{Binding Path=ContactName}"/>
      </DataTemplate>
  </Grid.Resources>
  ```

### 指定窗体布局

窗体的布局由一个三行三列的网格来定义。 [Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label) 控件旨在标识 Customers 表中的每个列。

#### 设置网格布局

- 将复制到以下 XAML[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素的声明。

  XAML复制

  ```xaml
  <Grid.RowDefinitions>
      <RowDefinition Height="Auto"/>
      <RowDefinition Height="Auto"/>
      <RowDefinition Height="Auto"/>
  </Grid.RowDefinitions>
  
  <Grid.ColumnDefinitions>
      <ColumnDefinition Width="Auto"/>
      <ColumnDefinition Width="Auto"/>
      <ColumnDefinition Width="Auto"/>
  </Grid.ColumnDefinitions>
  ```

#### 设置 Label 控件

- 将复制到以下 XAML[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素的声明。

  XAML复制

  ```xaml
  <StackPanel Orientation="Vertical" Grid.Row="0" Grid.Column="1">
      <Label Margin="20,38,5,2">First Name:</Label>
      <Label Margin="20,0,5,2">Company Name:</Label>
      <Label Margin="20,0,5,2">Phone:</Label>
      <Label Margin="20,0,5,2">Address:</Label>
      <Label Margin="20,0,5,2">City:</Label>
      <Label Margin="20,0,5,2">Region:</Label>
      <Label Margin="20,0,5,2">Postal Code:</Label>
  </StackPanel>
  ```

### 指定数据绑定

客户的主列表显示在[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)控件。 附加`ListItemsTemplate`绑定[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)控制对`ContactName`字段从该数据库。

每个客户记录的详细信息显示在多个[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控件。

#### 指定数据绑定

- 将复制到以下 XAML[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素的声明。

  [Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)类绑定[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控件添加到数据库中的相应字段。

  XAML复制

  ```xaml
  <StackPanel Orientation="Vertical" Grid.Row="0" Grid.Column="0">
      <Label Margin="20,5,5,0">List of Customers:</Label>
      <ListBox x:Name="listBox1" Height="200" Width="200" HorizontalAlignment="Left" 
         ItemTemplate="{StaticResource ListItemsTemplate}" IsSynchronizedWithCurrentItem="True" Margin="20,5,5,5"/>
  </StackPanel>
  
  <StackPanel Orientation="Vertical" Grid.Row="0" Grid.Column="2">
      <TextBox Margin="5,38,5,2" Width="200" Text="{Binding Path=ContactName}"/>
      <TextBox Margin="5,0,5,2" Width="200" Text="{Binding Path=CompanyName}"/>
      <TextBox Margin="5,0,5,2" Width="200" Text="{Binding Path=Phone}"/>
      <TextBox Margin="5,0,5,2" Width="200" Text="{Binding Path=Address}"/>
      <TextBox Margin="5,0,5,2" Width="200" Text="{Binding Path=City}"/>
      <TextBox Margin="5,0,5,2" Width="30" HorizontalAlignment="Left" Text="{Binding Path=Region}"/>
      <TextBox Margin="5,0,5,2" Width="50" HorizontalAlignment="Left" Text="{Binding Path=PostalCode}"/>
  </StackPanel>
  ```

### 使用互操作功能显示数据

对应于所选客户的订单显示在[System.Windows.Forms.DataGridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.datagridview)名为控件`dataGridView1`。 `dataGridView1`控件绑定到数据源中的代码隐藏文件。 一个[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)控件是指此父Windows 窗体控件。

#### 在 DataGridView 控件中显示数据

- 将复制到以下 XAML[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素的声明。

  XAML复制

  ```xaml
  <WindowsFormsHost Grid.Row="1" Grid.Column="0" Grid.ColumnSpan="3" Margin="20,5,5,5" Height="300">
      <wf:DataGridView x:Name="dataGridView1"/>
  </WindowsFormsHost>
  ```

### 向项目添加数据源

使用 Visual Studio 中，可以轻松向项目添加数据源。 此过程将向项目添加强类型数据集。 还添加了其他支持类，例如每个所选表适用的表适配器。

#### 添加数据源

1. 从**数据**菜单中，选择**添加新数据源**。
2. 在中**数据源配置向导**，使用数据集创建到 Northwind 数据库的连接。 有关详细信息，请参阅[如何：连接到数据库中的数据](https://msdn.microsoft.com/library/6c56e54e-8834-4297-85aa-cc1a443ba556)。
3. 当提示你**数据源配置向导**，保存连接字符串作为`NorthwindConnectionString`。
4. 时系统会提示您选择数据库对象，选择`Customers`并`Orders`表和名称生成的数据集`NorthwindDataSet`。

### 绑定到数据源

[System.Windows.Forms.BindingSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.bindingsource)组件为应用程序的数据源提供了一个统一的界面。 绑定到数据源是在代码隐藏文件中实现的。

#### 绑定到数据源

1. 打开名为 MainWindow.xaml.vb 或 MainWindow.xaml.cs 的代码隐藏文件。

2. 以下代码复制到`MainWindow`类定义。

   此代码声明了[BindingSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.bindingsource)组件和连接到数据库的相关帮助器类。

   C#复制

   ```csharp
   private System.Windows.Forms.BindingSource nwBindingSource;
   private NorthwindDataSet nwDataSet;
   private NorthwindDataSetTableAdapters.CustomersTableAdapter customersTableAdapter = 
       new NorthwindDataSetTableAdapters.CustomersTableAdapter();
   private NorthwindDataSetTableAdapters.OrdersTableAdapter ordersTableAdapter = 
       new NorthwindDataSetTableAdapters.OrdersTableAdapter();
   ```

3. 将以下代码复制到构造函数中。

   此代码将创建并初始化[BindingSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.bindingsource)组件。

   C#复制

   ```csharp
   public MainWindow()
   {
       InitializeComponent();
   
       // Create a DataSet for the Customers data.
       this.nwDataSet = new NorthwindDataSet();
       this.nwDataSet.DataSetName = "nwDataSet";
   
       // Create a BindingSource for the Customers data.
       this.nwBindingSource = new System.Windows.Forms.BindingSource();
       this.nwBindingSource.DataMember = "Customers";
       this.nwBindingSource.DataSource = this.nwDataSet;
   }
   ```

4. 打开 MainWindow.xaml。

5. 在设计视图或 XAML 视图中，选择[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)元素。

6. 在属性窗口中，单击**事件**选项卡。

7. 双击[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)事件。

8. 以下代码复制到[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)事件处理程序。

   此代码将分配[BindingSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.bindingsource)组件作为数据上下文，并填充`Customers`和`Orders`适配器对象。

   C#复制

   ```csharp
   private void Window_Loaded(object sender, RoutedEventArgs e)
   {
       // Fill the Customers table adapter with data.
       this.customersTableAdapter.ClearBeforeFill = true;
       this.customersTableAdapter.Fill(this.nwDataSet.Customers);
   
       // Fill the Orders table adapter with data.
       this.ordersTableAdapter.Fill(this.nwDataSet.Orders);
   
       // Assign the BindingSource to 
       // the data context of the main grid.
       this.mainGrid.DataContext = this.nwBindingSource;
   
       // Assign the BindingSource to 
       // the data source of the list box.
       this.listBox1.ItemsSource = this.nwBindingSource;
   
       // Because this is a master/details form, the DataGridView
       // requires the foreign key relating the tables.
       this.dataGridView1.DataSource = this.nwBindingSource;
       this.dataGridView1.DataMember = "FK_Orders_Customers";
   
       // Handle the currency management aspect of the data models.
       // Attach an event handler to detect when the current item 
       // changes via the WPF ListBox. This event handler synchronizes
       // the list collection with the BindingSource.
       //
       
       BindingListCollectionView cv = CollectionViewSource.GetDefaultView(
           this.nwBindingSource) as BindingListCollectionView;
   
       cv.CurrentChanged += new EventHandler(WPF_CurrentChanged);
   }
   ```

9. 以下代码复制到`MainWindow`类定义。

   此方法可处理[CurrentChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionview.currentchanged)事件并更新数据绑定的当前项。

   C#复制

   ```csharp
   // This event handler updates the current item 
   // of the data binding.
   void WPF_CurrentChanged(object sender, EventArgs e)
   {
       BindingListCollectionView cv = sender as BindingListCollectionView;
       this.nwBindingSource.Position = cv.CurrentPosition;
   }
   ```

10. 按 F5 生成并运行该应用程序。

## [Walkthrough: Hosting a 3-D WPF Composite Control in Windows Forms](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/walkthrough-hosting-a-3-d-wpf-composite-control-in-windows-forms)

本演练演示如何创建WPF复合控件并将其在托管Windows 窗体控件和窗体使用[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)控件。

在本演练中，您将实现WPF [UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol) ，其中包含两个子控件。 [UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol)显示三维 (3-D) 锥形区域。 呈现三维对象是变得更为简单WPF比使用Windows 窗体。 因此，对主机有意义WPF[UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol)类，以创建 3d 图形Windows 窗体。

本演练涉及以下任务：

- 创建WPF [UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol)。
- 创建 Windows 窗体宿主项目。
- 承载WPF [UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol)。

### 系统必备

你需要以下组件来完成本演练：

- Visual Studio 2017



### 创建用户控件

1. 创建**WPF 用户控件库**名为项目`HostingWpfUserControlInWf`。

2. 打开 UserControl1.xaml 在WPF 设计器。

3. 生成的代码替换为以下代码：

   XAML复制

   ```xaml
   <UserControl x:Class="HostingWpfUserControlInWf.UserControl1"
       xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
       xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
       >
     
       <Grid>
   
         <!-- Place a Label control at the top of the view. -->
         <Label 
                   HorizontalAlignment="Center" 
                   TextBlock.TextAlignment="Center" 
                   FontSize="20" 
                   Foreground="Red" 
                   Content="Model: Cone"/>
   
         <!-- Viewport3D is the rendering surface. -->
         <Viewport3D Name="myViewport" >
   
           <!-- Add a camera. -->
           <Viewport3D.Camera>
             <PerspectiveCamera 
                           FarPlaneDistance="20" 
                           LookDirection="0,0,1" 
                           UpDirection="0,1,0" 
                           NearPlaneDistance="1" 
                           Position="0,0,-3" 
                           FieldOfView="45" />
           </Viewport3D.Camera>
   
           <!-- Add models. -->
           <Viewport3D.Children>
   
             <ModelVisual3D>
               <ModelVisual3D.Content>
   
                 <Model3DGroup >
                   <Model3DGroup.Children>
   
                     <!-- Lights, MeshGeometry3D and DiffuseMaterial objects are added to the ModelVisual3D. -->
                     <DirectionalLight Color="#FFFFFFFF" Direction="3,-4,5" />
   
                     <!-- Define a red cone. -->
                     <GeometryModel3D>
   
                       <GeometryModel3D.Geometry>
                         <MeshGeometry3D 
       Positions="0.293893 -0.5 0.404509  0.475528 -0.5 0.154509  0 0.5 0  0.475528 -0.5 0.154509  0 0.5 0  0 0.5 0  0.475528 -0.5 0.154509  0.475528 -0.5 -0.154509  0 0.5 0  0.475528 -0.5 -0.154509  0 0.5 0  0 0.5 0  0.475528 -0.5 -0.154509  0.293893 -0.5 -0.404509  0 0.5 0  0.293893 -0.5 -0.404509  0 0.5 0  0 0.5 0  0.293893 -0.5 -0.404509  0 -0.5 -0.5  0 0.5 0  0 -0.5 -0.5  0 0.5 0  0 0.5 0  0 -0.5 -0.5  -0.293893 -0.5 -0.404509  0 0.5 0  -0.293893 -0.5 -0.404509  0 0.5 0  0 0.5 0  -0.293893 -0.5 -0.404509  -0.475528 -0.5 -0.154509  0 0.5 0  -0.475528 -0.5 -0.154509  0 0.5 0  0 0.5 0  -0.475528 -0.5 -0.154509  -0.475528 -0.5 0.154509  0 0.5 0  -0.475528 -0.5 0.154509  0 0.5 0  0 0.5 0  -0.475528 -0.5 0.154509  -0.293892 -0.5 0.404509  0 0.5 0  -0.293892 -0.5 0.404509  0 0.5 0  0 0.5 0  -0.293892 -0.5 0.404509  0 -0.5 0.5  0 0.5 0  0 -0.5 0.5  0 0.5 0  0 0.5 0  0 -0.5 0.5  0.293893 -0.5 0.404509  0 0.5 0  0.293893 -0.5 0.404509  0 0.5 0  0 0.5 0  " 
       Normals="0.7236065,0.4472139,0.5257313  0.2763934,0.4472138,0.8506507  0.5308242,0.4294462,0.7306172  0.2763934,0.4472138,0.8506507  0,0.4294458,0.9030925  0.5308242,0.4294462,0.7306172  0.2763934,0.4472138,0.8506507  -0.2763934,0.4472138,0.8506507  0,0.4294458,0.9030925  -0.2763934,0.4472138,0.8506507  -0.5308242,0.4294462,0.7306172  0,0.4294458,0.9030925  -0.2763934,0.4472138,0.8506507  -0.7236065,0.4472139,0.5257313  -0.5308242,0.4294462,0.7306172  -0.7236065,0.4472139,0.5257313  -0.858892,0.429446,0.279071  -0.5308242,0.4294462,0.7306172  -0.7236065,0.4472139,0.5257313  -0.8944269,0.4472139,0  -0.858892,0.429446,0.279071  -0.8944269,0.4472139,0  -0.858892,0.429446,-0.279071  -0.858892,0.429446,0.279071  -0.8944269,0.4472139,0  -0.7236065,0.4472139,-0.5257313  -0.858892,0.429446,-0.279071  -0.7236065,0.4472139,-0.5257313  -0.5308242,0.4294462,-0.7306172  -0.858892,0.429446,-0.279071  -0.7236065,0.4472139,-0.5257313  -0.2763934,0.4472138,-0.8506507  -0.5308242,0.4294462,-0.7306172  -0.2763934,0.4472138,-0.8506507  0,0.4294458,-0.9030925  -0.5308242,0.4294462,-0.7306172  -0.2763934,0.4472138,-0.8506507  0.2763934,0.4472138,-0.8506507  0,0.4294458,-0.9030925  0.2763934,0.4472138,-0.8506507  0.5308249,0.4294459,-0.7306169  0,0.4294458,-0.9030925  0.2763934,0.4472138,-0.8506507  0.7236068,0.4472141,-0.5257306  0.5308249,0.4294459,-0.7306169  0.7236068,0.4472141,-0.5257306  0.8588922,0.4294461,-0.27907  0.5308249,0.4294459,-0.7306169  0.7236068,0.4472141,-0.5257306  0.8944269,0.4472139,0  0.8588922,0.4294461,-0.27907  0.8944269,0.4472139,0  0.858892,0.429446,0.279071  0.8588922,0.4294461,-0.27907  0.8944269,0.4472139,0  0.7236065,0.4472139,0.5257313  0.858892,0.429446,0.279071  0.7236065,0.4472139,0.5257313  0.5308242,0.4294462,0.7306172  0.858892,0.429446,0.279071  "                   TriangleIndices="0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 " />
                       </GeometryModel3D.Geometry>
   
                       <GeometryModel3D.Material>
                         <DiffuseMaterial>
                           <DiffuseMaterial.Brush>
                             <SolidColorBrush 
                               Color="Red" 
                               Opacity="1.0"/>
                           </DiffuseMaterial.Brush>
                         </DiffuseMaterial>
                       </GeometryModel3D.Material>
   
                     </GeometryModel3D>
   
                   </Model3DGroup.Children>
                 </Model3DGroup>
   
               </ModelVisual3D.Content>
   
             </ModelVisual3D>
   
           </Viewport3D.Children>
   
         </Viewport3D>
       </Grid>
     
   </UserControl>
   ```

   此代码定义[System.Windows.Controls.UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol)，其中包含两个子控件。 第一个子控件是[System.Windows.Controls.Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)控制; 第二个是[Viewport3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewport3d)显示三维锥体控件。



### 创建宿主项目

1. 添加**WPF 应用 (.NET Framework)** 名为项目`WpfUserControlHost`到解决方案。 有关详细信息，请参阅[如何：创建新的 WPF 应用程序项目](https://msdn.microsoft.com/library/1f6aea7a-33e1-4d3f-8555-1daa42e95d82)。
2. 在中**解决方案资源管理器**，添加对 WindowsFormsIntegration 程序集，它名为 WindowsFormsIntegration.dll 的引用。
3. 将引用添加到以下WPF程序集：
   - PresentationCore
   - PresentationFramework
   - WindowsBase
4. 添加对引用`HostingWpfUserControlInWf`项目。
5. 在解决方案资源管理器，设置`WpfUserControlHost`项目为启动项目。



### 托管用户控件

1. 在 Windows 窗体设计器中打开 Form1。

2. 在属性窗口中，单击**事件**，然后双击[Load](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.form.load)事件创建事件处理程序。

   在代码编辑器将打开到新生成`Form1_Load`事件处理程序。

3. Form1.cs 中的代码替换为以下代码。

   `Form1_Load`事件处理程序创建的实例`UserControl1`，并将添加为[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)子控件的控件的集合。[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)控件添加到的子控件的窗体的集合。

   C#复制

   ```csharp
   using System;
   using System.Collections.Generic;
   using System.ComponentModel;
   using System.Data;
   using System.Drawing;
   using System.Text;
   using System.Windows.Forms;
   
   using System.Windows.Forms.Integration;
   
   namespace WpfUserControlHost
   {
       public partial class Form1 : Form
       {
           public Form1()
           {
               InitializeComponent();
           }
   
           private void Form1_Load(object sender, EventArgs e)
           {
               // Create the ElementHost control for hosting the
               // WPF UserControl.
               ElementHost host = new ElementHost();
               host.Dock = DockStyle.Fill;
   
               // Create the WPF UserControl.
               HostingWpfUserControlInWf.UserControl1 uc =
                   new HostingWpfUserControlInWf.UserControl1();
   
               // Assign the WPF UserControl to the ElementHost control's
               // Child property.
               host.Child = uc;
   
               // Add the ElementHost control to the form's
               // collection of child controls.
               this.Controls.Add(host);
           }
       }
   }
   ```

4. 按 F5 生成并运行该应用程序。

## [Walkthrough: Hosting a WPF Composite Control in Windows Forms](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/walkthrough-hosting-a-wpf-composite-control-in-windows-forms)

Windows Presentation Foundation (WPF) 提供了用于创建应用程序的丰富环境。 但是，当您有大量投入时Windows 窗体代码，它可以更有效地扩展现有Windows 窗体应用程序与WPF而不是从头开始重新编写。 常见情况是你想要嵌入其中一个或多个控件实现的与WPF在 Windows 窗体应用程序中。 有关自定义 WPF 控件的详细信息，请参阅[控件自定义](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/control-customization)。

本演练将引导你通过应用程序承载WPF复合控件以在 Windows 窗体应用程序中执行数据输入。 复合控件打包在一个 DLL 中。 此常规步骤可扩展到更复杂的应用程序和控件。 本演练旨在几乎完全相同的外观和功能到[演练：在 WPF 中承载 Windows 窗体复合控件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/walkthrough-hosting-a-windows-forms-composite-control-in-wpf)。 主要区别在于承载方案是相反的。

本演练分为两个部分。 第一部分简要介绍的实现WPF复合控件。 第二个部分详细讨论了如何承载 Windows 窗体应用程序中的复合控件、 接收来自控件的事件和访问的某些控件的属性。

本演练涉及以下任务：

- 实现 WPF 复合控件。
- 实现 Windows 窗体主机应用程序。

在本演练中所涉及任务的完整代码列表，请参阅[承载 WPF 复合控件在 Windows 窗体示例](https://go.microsoft.com/fwlink/?LinkID=159996)。

### 系统必备

若要完成本演练，必须具有 Visual Studio。

### 实现 WPF 复合控件

WPF此示例中使用的复合控件是一种简单的数据输入形式，采用用户的名称和地址。 当用户单击两个按钮的其中一个以指示任务已完成时，该控件会引发将该信息返回给主机的自定义事件。 下图显示呈现的控件。

![简单的 WPF 控件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/avaloncontrol.png)
WPF 复合控件

#### 创建项目

启动项目：

1. 启动Microsoft Visual Studio，并打开**新建项目**对话框。
2. 在 Visual C# 和 Windows 类别中，选择**WPF 用户控件库**模板。
3. 将新项目命名为 `MyControls`。
4. 对于位置，指定可以方便命名的顶层文件夹，如`WindowsFormsHostingWpfControl`。 随后，将主机应用程序放在此文件夹中。
5. 单击“确定”，创建项目。 默认项目包含名为的单个控件`UserControl1`。
6. 在解决方案资源管理器，重命名`UserControl1`到`MyControl1`。

项目应具有对以下系统 DLL 的引用。 如果默认未包含其中任何 DLL，请将它们添加到项目中。

- PresentationCore
- PresentationFramework
- 系统
- WindowsBase

#### 创建用户界面

用户界面 (UI)复合控件实现与可扩展应用程序标记语言 (XAML)。 复合控件UI包含五个[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)元素。 每个[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)元素都有一个关联[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)充当标签的元素。 有两个[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)在底部，元素**确定**并**取消**。 当用户单击任一按钮时，该控件会引发将信息返回给主机的自定义事件。

#### 基本布局

各种UI元素包含在[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素。 可以使用[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)要排列的复合内容控制在很大程度相同方式使用`Table`中 HTML 元素。 WPF 还有[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)元素，但[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)更轻便、 更好地适用于简单的布局任务。

以下 XAML 演示基本布局。 此 XAML 通过指定的列数定义的控件的整体结构和中的行[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素。

在 MyControl1.xaml 中，将现有 XAML 替换为以下 XAML。

XAML复制

```xaml
<Grid xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      x:Class="MyControls.MyControl1"
      Background="#DCDCDC"
      Width="375"
      Height="250"
      Name="rootElement"
      Loaded="Init">

  <Grid.ColumnDefinitions>
    <ColumnDefinition Width="Auto" />
    <ColumnDefinition Width="Auto" />
    <ColumnDefinition Width="Auto"/>
    <ColumnDefinition Width="Auto"/>
  </Grid.ColumnDefinitions>

  <Grid.RowDefinitions>
    <RowDefinition Height="Auto" />
    <RowDefinition Height="Auto" />
    <RowDefinition Height="Auto" />
    <RowDefinition Height="Auto" />
    <RowDefinition Height="Auto" />
    <RowDefinition Height="Auto" />
  </Grid.RowDefinitions>
```

XAML复制

```xaml
</Grid>
```

#### 向 Grid 添加 TextBlock 和 TextBox 元素

您将放UI通过设置元素的网格中的元素[RowProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid.rowproperty)和[ColumnProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid.columnproperty)属性到相应的行和列号。 请记住行号和列号是从零开始的。 你可以通过设置跨多个列的元素及其[ColumnSpanProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid.columnspanproperty)属性。 有关详细信息[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素，请参阅[创建网格元素](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-create-a-grid-element)。

以下 XAML 演示复合控件[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)和[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素及其[RowProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid.rowproperty)和[ColumnProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid.columnproperty)属性，它们被设置为将元素正确放置在网格中。

在 MyControl1.xaml 中，添加以下 XAML 中的[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素。

XAML复制

```xaml
  <TextBlock Grid.Column="0"
        Grid.Row="0" 
        Grid.ColumnSpan="4"
        Margin="10,5,10,0"
        HorizontalAlignment="Center"
        Style="{StaticResource titleText}">Simple WPF Control</TextBlock>

  <TextBlock Grid.Column="0"
        Grid.Row="1"
        Style="{StaticResource inlineText}"
        Name="nameLabel">Name</TextBlock>
  <TextBox Grid.Column="1"
        Grid.Row="1"
        Grid.ColumnSpan="3"
        Name="txtName"/>

  <TextBlock Grid.Column="0"
        Grid.Row="2"
        Style="{StaticResource inlineText}"
        Name="addressLabel">Street Address</TextBlock>
  <TextBox Grid.Column="1"
        Grid.Row="2"
        Grid.ColumnSpan="3"
        Name="txtAddress"/>

  <TextBlock Grid.Column="0"
        Grid.Row="3"
        Style="{StaticResource inlineText}"
        Name="cityLabel">City</TextBlock>
  <TextBox Grid.Column="1"
        Grid.Row="3"
        Width="100"
        Name="txtCity"/>

  <TextBlock Grid.Column="2"
        Grid.Row="3"
        Style="{StaticResource inlineText}"
        Name="stateLabel">State</TextBlock>
  <TextBox Grid.Column="3"
        Grid.Row="3"
        Width="50"
        Name="txtState"/>

  <TextBlock Grid.Column="0"
        Grid.Row="4"
        Style="{StaticResource inlineText}"
        Name="zipLabel">Zip</TextBlock>
  <TextBox Grid.Column="1"
        Grid.Row="4"
        Width="100"
        Name="txtZip"/>
```

#### 设置 UI 元素的样式

数据输入窗体上的许多元素外观相似，这意味着它们对于其若干属性具有相同的设置。 而不是单独设置每个元素的特性，使用上一个 XAML[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)元素可定义为类的元素的标准属性设置。 这种方法可以降低控件的复杂性，并使你能够通过单个样式特性更改多个元素的外观。

[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)元素包含在[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素的[Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.resources)属性，因此它们可以由该控件中的所有元素。 如果命名了某样式，您将其应用于元素通过添加[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)元素设置为该样式的名称。 未命名的样式将成为该元素的默认样式。 有关详细信息WPF样式，请参阅[样式和模板化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/styling-and-templating)。

下面的 XAML 演示[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)复合控件元素。 若要查看样式如何应用于元素，请参阅前一个 XAML。 例如上, 一次[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素具有`inlineText`样式和最后一个[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)元素使用的默认样式。

在 MyControl1.xaml 中，添加以下 XAML 之后[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)开始元素。

XAML复制

```xaml
<Grid.Resources>
  <Style x:Key="inlineText" TargetType="{x:Type TextBlock}">
    <Setter Property="Margin" Value="10,5,10,0"/>
    <Setter Property="FontWeight" Value="Normal"/>
    <Setter Property="FontSize" Value="12"/>
  </Style>
  <Style x:Key="titleText" TargetType="{x:Type TextBlock}">
    <Setter Property="DockPanel.Dock" Value="Top"/>
    <Setter Property="FontWeight" Value="Bold"/>
    <Setter Property="FontSize" Value="14"/>
    <Setter Property="Margin" Value="10,5,10,0"/>
  </Style>
  <Style TargetType="{x:Type Button}">
    <Setter Property="Margin" Value="10,5,10,0"/>
    <Setter Property="Width" Value="60"/>
  </Style>
  <Style TargetType="{x:Type TextBox}">
    <Setter Property="Margin" Value="10,5,10,0"/>
  </Style>
</Grid.Resources>
```

#### 添加“确定”和“取消”按钮

复合控件上的最后一个元素是**确定**并**取消**[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)元素，它们占用的最后一行的前两个列[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)。 这些元素使用常见的事件处理程序`ButtonClicked`，默认值和[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)上一个 XAML 中定义的样式。

在 MyControl1.xaml 中，最后一个后面添加以下 XAML[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)元素。 XAML复合控件的一部分现已完成。

XAML复制

```xaml
<Button Grid.Row="5"
        Grid.Column="0"
        Name="btnOK"
        Click="ButtonClicked">OK</Button>
<Button Grid.Row="5"
        Grid.Column="1"
        Name="btnCancel"
        Click="ButtonClicked">Cancel</Button>
```

#### 实现代码隐藏文件

代码隐藏文件 MyControl1.xaml.cs 实现三个基本任务：

1. 处理用户单击其中一个按钮时发生的事件。
2. 检索从数据[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)元素，并将它们打包在一个自定义事件参数对象。
3. 引发自定义`OnButtonClick`事件，通知主机用户已完成，并将数据传递回主机。

该控件还公开多个可用来更改外观的颜色和字体属性。 与不同[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)类，该类用于承载 Windows 窗体控件[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)类公开控件的[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.background)只属性。 若要维护此代码示例和讨论的示例中之间的相似性[演练：承载 Windows 窗体复合控件在 WPF 中](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/walkthrough-hosting-a-windows-forms-composite-control-in-wpf)，该控件直接公开其余属性。

#### 代码隐藏文件的基本结构

代码隐藏文件包含的单个命名空间，由`MyControls`，其中包含两个类`MyControl1`和`MyControlEventArgs`。

复制

```
namespace MyControls  
{  
  public partial class MyControl1 : Grid  
  {  
    //...  
  }  
  public class MyControlEventArgs : EventArgs  
  {  
    //...  
  }  
}  
```

第一个类`MyControl1`，是一个包含实现的功能的代码的分部类UIMyControl1.xaml 中定义。 当解析 MyControl1.xaml 中时，XAML转换为相同的分部类和两个分部类会合并形成编译的控件。 出于此原因，代码隐藏文件中的类名必须与分配给 MyControl1.xaml 的类名相匹配，并且它必须继承自控件的根元素。 第二个类， `MyControlEventArgs`，是一个事件参数类，用于将数据发送回主机。

打开 MyControl1.xaml.cs。 更改现有的类声明，以便它具有以下名称并继承[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)。

C#复制

```csharp
public partial class MyControl1 : Grid
```

#### 初始化控件

下面的代码实现几个基本任务：

- 声明一个私有事件`OnButtonClick`，和及其关联的委托`MyControlEventHandler`。
- 创建几个存储用户数据的私有全局变量。 此数据通过相应的属性公开。
- 实现一个处理程序`Init`，为控件的[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)事件。 此处理程序通过向全局变量分配 MyControl1.xaml 中定义的值来对它们进行初始化。 若要执行此操作，它使用[Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.name)分配给典型[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素， `nameLabel`，以访问该元素的属性设置。

删除现有的构造函数并将以下代码添加到你`MyControl1`类。

C#复制

```csharp
public delegate void MyControlEventHandler(object sender, MyControlEventArgs args);
public event MyControlEventHandler OnButtonClick;
private FontWeight _fontWeight;
private double _fontSize;
private FontFamily _fontFamily;
private FontStyle _fontStyle;
private SolidColorBrush _foreground;
private SolidColorBrush _background;

private void Init(object sender, EventArgs e)
{
    //They all have the same style, so use nameLabel to set initial values.
    _fontWeight = nameLabel.FontWeight;
    _fontSize = nameLabel.FontSize;
    _fontFamily = nameLabel.FontFamily;
    _fontStyle = nameLabel.FontStyle;
    _foreground = (SolidColorBrush)nameLabel.Foreground;
    _background = (SolidColorBrush)rootElement.Background;
}
```

#### 处理按钮的单击事件

用户指示数据输入任务已完成通过单击**确定**按钮或**取消**按钮。 这两个按钮都使用相同[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件处理程序`ButtonClicked`。 这两个按钮都具有名称，`btnOK`或`btnCancel`，这样，要确定通过检查的值被单击的按钮的处理程序`sender`参数。 该处理程序执行以下任务：

- 创建`MyControlEventArgs`对象，其中包含从数据[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)元素。
- 如果用户单击**取消**按钮，集`MyControlEventArgs`对象的`IsOK`属性设置为`false`。
- 引发`OnButtonClick`事件以向主机指示用户已完成，并且传回所收集的数据。

将以下代码添加到您`MyControl1`类后,`Init`方法。

C#复制

```csharp
private void ButtonClicked(object sender, RoutedEventArgs e)
{
    MyControlEventArgs retvals = new MyControlEventArgs(true,
                                                        txtName.Text,
                                                        txtAddress.Text,
                                                        txtCity.Text,
                                                        txtState.Text,
                                                        txtZip.Text);
    if (sender == btnCancel)
    {
        retvals.IsOK = false;
    }
    if (OnButtonClick != null)
        OnButtonClick(this, retvals);
}
```

#### 创建属性

类的其余部分只是公开对应于前面所述的全局变量的属性。 当属性更改时，set 访问器会通过更改对应的元素属性并更新基础全局变量来修改控件的外观。

将以下代码添加到你`MyControl1`类。

C#复制

```csharp
public FontWeight MyControl_FontWeight
{
    get { return _fontWeight; }
    set
    {
        _fontWeight = value;
        nameLabel.FontWeight = value;
        addressLabel.FontWeight = value;
        cityLabel.FontWeight = value;
        stateLabel.FontWeight = value;
        zipLabel.FontWeight = value;
    }
}
public double MyControl_FontSize
{
    get { return _fontSize; }
    set
    {
        _fontSize = value;
        nameLabel.FontSize = value;
        addressLabel.FontSize = value;
        cityLabel.FontSize = value;
        stateLabel.FontSize = value;
        zipLabel.FontSize = value;
    }
}
public FontStyle MyControl_FontStyle
{
    get { return _fontStyle; }
    set
    {
        _fontStyle = value;
        nameLabel.FontStyle = value;
        addressLabel.FontStyle = value;
        cityLabel.FontStyle = value;
        stateLabel.FontStyle = value;
        zipLabel.FontStyle = value;
    }
}
public FontFamily MyControl_FontFamily
{
    get { return _fontFamily; }
    set
    {
        _fontFamily = value;
        nameLabel.FontFamily = value;
        addressLabel.FontFamily = value;
        cityLabel.FontFamily = value;
        stateLabel.FontFamily = value;
        zipLabel.FontFamily = value;
    }
}

public SolidColorBrush MyControl_Background
{
    get { return _background; }
    set
    {
        _background = value;
        rootElement.Background = value;
    }
}
public SolidColorBrush MyControl_Foreground
{
    get { return _foreground; }
    set
    {
        _foreground = value;
        nameLabel.Foreground = value;
        addressLabel.Foreground = value;
        cityLabel.Foreground = value;
        stateLabel.Foreground = value;
        zipLabel.Foreground = value;
    }
}
```

#### 将数据发送回主机

在文件中的最后一个组件是`MyControlEventArgs`类，该类用于将收集的数据发送回主机。

将以下代码添加到你`MyControls`命名空间。 该实现非常简单明了，因而不再进一步讨论。

C#复制

```csharp
public class MyControlEventArgs : EventArgs
{
    private string _Name;
    private string _StreetAddress;
    private string _City;
    private string _State;
    private string _Zip;
    private bool _IsOK;

    public MyControlEventArgs(bool result,
                              string name,
                              string address,
                              string city,
                              string state,
                              string zip)
    {
        _IsOK = result;
        _Name = name;
        _StreetAddress = address;
        _City = city;
        _State = state;
        _Zip = zip;
    }

    public string MyName
    {
        get { return _Name; }
        set { _Name = value; }
    }
    public string MyStreetAddress
    {
        get { return _StreetAddress; }
        set { _StreetAddress = value; }
    }
    public string MyCity
    {
        get { return _City; }
        set { _City = value; }
    }
    public string MyState
    {
        get { return _State; }
        set { _State = value; }
    }
    public string MyZip
    {
        get { return _Zip; }
        set { _Zip = value; }
    }
    public bool IsOK
    {
        get { return _IsOK; }
        set { _IsOK = value; }
    }
}
```

生成解决方案。 生成将产生一个名为 MyControls.dll 的 DLL。

### 实现 Windows 窗体主机应用程序

Windows 窗体承载应用程序使用[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)对象承载WPF复合控件。 该应用程序处理`OnButtonClick`事件以接收来自复合控件的数据。 该应用程序还具有一组可用于修改控件外观的选项按钮。 下图显示应用程序。

![Windows 窗体承载 Avalon 控件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/wfhost.png)
Windows 窗体应用程序中承载的 WPF 复合控件

#### 创建项目

启动项目：

1. 启动Visual Studio，并打开**新建项目**对话框。
2. 在 Visual C# 和 Windows 类别中，选择**Windows 窗体应用程序**模板。
3. 将新项目命名为 `WFHost`。
4. 对于位置，指定包含 MyControls 项目的同一顶层文件夹。
5. 单击“确定”，创建项目。

此外需要添加对包含的 DLL 的引用`MyControl1`和其他程序集。

1. 右键单击解决方案资源管理器中的项目名称并选择**添加引用**。
2. 单击**浏览**选项卡，然后浏览到包含 MyControls.dll 的文件夹。 在本演练中，此文件夹位于 MyControls\bin\Debug。
3. 选择 MyControls.dll，然后依次**确定**。
4. 添加对下列程序集的引用。
   - PresentationCore
   - PresentationFramework
   - System.Xaml
   - WindowsBase
   - WindowsFormsIntegration

#### 实现应用程序的用户界面

Windows 窗体应用程序的 UI 包含若干个与 WPF 复合控件进行交互的控件。

1. 在 Windows 窗体设计器中打开 Form1。

2. 放大窗体以适应控件。

3. 在窗体的右上角，添加[System.Windows.Forms.Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.panel)控件以容纳WPF复合控件。

4. 以下代码添加到[System.Windows.Forms.GroupBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.groupbox)到窗体控件。

   | name      | Text           |
   | --------- | -------------- |
   | groupBox1 | 背景色         |
   | groupBox2 | 前景色         |
   | groupBox3 | 字号           |
   | groupBox4 | 字体系列       |
   | groupBox5 | 字形           |
   | groupBox6 | 字体粗细       |
   | groupBox7 | 来自控件的数据 |

5. 添加以下[System.Windows.Forms.RadioButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.radiobutton)控件添加到[System.Windows.Forms.GroupBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.groupbox)控件。

   | GroupBox  | name                       | Text                  |
   | --------- | -------------------------- | --------------------- |
   | groupBox1 | radioBackgroundOriginal    | 原始                  |
   | groupBox1 | radioBackgroundLightGreen  | LightGreen            |
   | groupBox1 | radioBackgroundLightSalmon | LightSalmon           |
   | groupBox2 | radioForegroundOriginal    | 原始                  |
   | groupBox2 | radioForegroundRed         | 红色                  |
   | groupBox2 | radioForegroundYellow      | 黄色                  |
   | groupBox3 | radioSizeOriginal          | 原始                  |
   | groupBox3 | radioSizeTen               | 10                    |
   | groupBox3 | radioSizeTwelve            | 12                    |
   | groupBox4 | radioFamilyOriginal        | 原始                  |
   | groupBox4 | radioFamilyTimes           | 宋体, Times New Roman |
   | groupBox4 | radioFamilyWingDings       | WingDings             |
   | groupBox5 | radioStyleOriginal         | 普通                  |
   | groupBox5 | radioStyleItalic           | 斜体                  |
   | groupBox6 | radioWeightOriginal        | 原始                  |
   | groupBox6 | radioWeightBold            | 粗体                  |

6. 添加以下[System.Windows.Forms.Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.label)到最后一个控制[System.Windows.Forms.GroupBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.groupbox)。 这些控件显示返回的数据WPF复合控件。

   | GroupBox  | name       | 文本              |
   | --------- | ---------- | ----------------- |
   | groupBox7 | lblName    | 姓名:             |
   | groupBox7 | lblAddress | 街道地址:         |
   | groupBox7 | lblCity    | 市/县:            |
   | groupBox7 | lblState   | 省/自治区/直辖市: |
   | groupBox7 | lblZip     | 邮政编码:         |

#### 初始化窗体

通常在窗体的实现承载代码[Load](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.form.load)事件处理程序。 下面的代码演示[Load](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.form.load)事件处理程序中，处理程序WPF复合控件的[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)事件，以及更高版本使用的几个全局变量的声明。

在 Windows 窗体设计器中，双击窗体创建[Load](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.form.load)事件处理程序。 在 Form1.cs 顶部，添加以下`using`语句。

```csharp
using System.Windows;
using System.Windows.Forms.Integration;
using System.Windows.Media;
```

现有内容替换为`Form1`用下面的代码的类。

```csharp
private ElementHost ctrlHost;
private MyControls.MyControl1 wpfAddressCtrl;
System.Windows.FontWeight initFontWeight;
double initFontSize;
System.Windows.FontStyle initFontStyle;
System.Windows.Media.SolidColorBrush initBackBrush;
System.Windows.Media.SolidColorBrush initForeBrush;
System.Windows.Media.FontFamily initFontFamily;

public Form1()
{
    InitializeComponent();
}

private void Form1_Load(object sender, EventArgs e)
{
    ctrlHost = new ElementHost();
    ctrlHost.Dock = DockStyle.Fill;
    panel1.Controls.Add(ctrlHost);
    wpfAddressCtrl = new MyControls.MyControl1();
    wpfAddressCtrl.InitializeComponent();
    ctrlHost.Child = wpfAddressCtrl;

    wpfAddressCtrl.OnButtonClick +=
        new MyControls.MyControl1.MyControlEventHandler(
        avAddressCtrl_OnButtonClick);
    wpfAddressCtrl.Loaded += new RoutedEventHandler(
        avAddressCtrl_Loaded);
}

void avAddressCtrl_Loaded(object sender, EventArgs e)
{
    initBackBrush = (SolidColorBrush)wpfAddressCtrl.MyControl_Background;
    initForeBrush = wpfAddressCtrl.MyControl_Foreground;
    initFontFamily = wpfAddressCtrl.MyControl_FontFamily;
    initFontSize = wpfAddressCtrl.MyControl_FontSize;
    initFontWeight = wpfAddressCtrl.MyControl_FontWeight;
    initFontStyle = wpfAddressCtrl.MyControl_FontStyle;
}
```

`Form1_Load`方法在前面的代码演示了托管的一般过程WPF控件：

1. 创建一个新[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)对象。
2. 设置控件的[Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.dock)属性设置为[DockStyle.Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.dockstyle#System_Windows_Forms_DockStyle_Fill)。
3. 添加[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)控制对[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.panel)控件的[Controls](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.controls)集合。
4. 创建的实例WPF控件。
5. 通过将分配到控件中承载复合控件在窗体上的[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)控件的[Child](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost.child)属性。

中的其余两行将`Form1_Load`方法附加到两个控件事件处理程序：

- `OnButtonClick` 是一个自定义事件，当用户单击由复合控件激发**确定**或**取消**按钮。 处理该事件可获取用户的响应并收集用户指定的任何数据。
- [Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded) 是一个标准事件引发的WPF控制时完全加载。 此处使用该事件是因为本示例需要使用控件中的属性初始化几个全局变量。 在窗体的时间[Load](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.form.load)事件，该控件不是完全加载，并且这些值仍设置为`null`。 你需要等到该控件[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)事件发生之前可以访问这些属性。

[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)事件处理程序在前面的代码所示。 `OnButtonClick`中下一节讨论处理程序。

#### 处理 OnButtonClick

`OnButtonClick`事件发生在用户单击时**确定**或**取消**按钮。

事件处理程序将检查事件参数`IsOK`字段，以确定被单击的按钮。 `lbl`*数据*变量对应于[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.label)前面讨论过的控件。 如果用户单击**确定**按钮，从控件的数据[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控件分配给对应[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.label)控件。 如果用户单击**取消**，则[Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.label.text)值设置为默认值的字符串。

添加下面的按钮单击事件处理程序代码与`Form1`类。

```csharp
void avAddressCtrl_OnButtonClick(
    object sender,
    MyControls.MyControl1.MyControlEventArgs args)
{
    if (args.IsOK)
    {
        lblAddress.Text = "Street Address: " + args.MyStreetAddress;
        lblCity.Text = "City: " + args.MyCity;
        lblName.Text = "Name: " + args.MyName;
        lblState.Text = "State: " + args.MyState;
        lblZip.Text = "Zip: " + args.MyZip;
    }
    else
    {
        lblAddress.Text = "Street Address: ";
        lblCity.Text = "City: ";
        lblName.Text = "Name: ";
        lblState.Text = "State: ";
        lblZip.Text = "Zip: ";
    }
}
```

生成并运行应用程序。 在 WPF 复合控件中添加一些文本，然后单击**确定**。 文本将显示在标签中。 此时，尚未添加代码来处理单选按钮。

#### 修改控件的外观

[RadioButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.radiobutton)窗体控件将使用户能够更改WPF复合控件的前景色和背景色以及若干字体属性。 背景色由[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)对象。 其余属性作为控件的自定义属性公开。

双击每个[RadioButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.radiobutton)要创建的窗体上控件[CheckedChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.radiobutton.checkedchanged)事件处理程序。 替换为[CheckedChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.radiobutton.checkedchanged)事件处理程序替换下面的代码。

```csharp
private void radioBackgroundOriginal_CheckedChanged(object sender, EventArgs e)
{
    wpfAddressCtrl.MyControl_Background = initBackBrush;
}

private void radioBackgroundLightGreen_CheckedChanged(object sender, EventArgs e)
{
    wpfAddressCtrl.MyControl_Background = new SolidColorBrush(Colors.LightGreen);
}

private void radioBackgroundLightSalmon_CheckedChanged(object sender, EventArgs e)
{
    wpfAddressCtrl.MyControl_Background = new SolidColorBrush(Colors.LightSalmon);
}

private void radioForegroundOriginal_CheckedChanged(object sender, EventArgs e)
{
    wpfAddressCtrl.MyControl_Foreground = initForeBrush;
}

private void radioForegroundRed_CheckedChanged(object sender, EventArgs e)
{
    wpfAddressCtrl.MyControl_Foreground = new System.Windows.Media.SolidColorBrush(Colors.Red);
}

private void radioForegroundYellow_CheckedChanged(object sender, EventArgs e)
{
    wpfAddressCtrl.MyControl_Foreground = new System.Windows.Media.SolidColorBrush(Colors.Yellow);
}

private void radioFamilyOriginal_CheckedChanged(object sender, EventArgs e)
{
    wpfAddressCtrl.MyControl_FontFamily = initFontFamily;
}

private void radioFamilyTimes_CheckedChanged(object sender, EventArgs e)
{
    wpfAddressCtrl.MyControl_FontFamily = new System.Windows.Media.FontFamily("Times New Roman");
}

private void radioFamilyWingDings_CheckedChanged(object sender, EventArgs e)
{
    wpfAddressCtrl.MyControl_FontFamily = new System.Windows.Media.FontFamily("WingDings");
}

private void radioSizeOriginal_CheckedChanged(object sender, EventArgs e)
{
    wpfAddressCtrl.MyControl_FontSize = initFontSize;
}

private void radioSizeTen_CheckedChanged(object sender, EventArgs e)
{
    wpfAddressCtrl.MyControl_FontSize = 10;
}

private void radioSizeTwelve_CheckedChanged(object sender, EventArgs e)
{
    wpfAddressCtrl.MyControl_FontSize = 12;
}

private void radioStyleOriginal_CheckedChanged(object sender, EventArgs e)
{
    wpfAddressCtrl.MyControl_FontStyle = initFontStyle;
}

private void radioStyleItalic_CheckedChanged(object sender, EventArgs e)
{
    wpfAddressCtrl.MyControl_FontStyle = System.Windows.FontStyles.Italic;
}

private void radioWeightOriginal_CheckedChanged(object sender, EventArgs e)
{
    wpfAddressCtrl.MyControl_FontWeight = initFontWeight;
}

private void radioWeightBold_CheckedChanged(object sender, EventArgs e)
{
    wpfAddressCtrl.MyControl_FontWeight = FontWeights.Bold;
}
```

生成并运行应用程序。 单击不同的单选按钮来查看在 WPF 复合控件上的效果。

## [Walkthrough: Mapping Properties Using the ElementHost Control](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/walkthrough-mapping-properties-using-the-elementhost-control)

本演练演示如何使用[PropertyMap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost.propertymap)属性将映射Windows 窗体属性设置为上托管的相应属性WPF元素。

本演练涉及以下任务：

- 创建项目。
- 定义新的属性映射。
- 删除默认属性映射。
- 扩展默认属性映射。

在本演练中所涉及任务的完整代码列表，请参阅[映射属性使用 ElementHost 控件示例](https://go.microsoft.com/fwlink/?LinkID=160018)。

完成后，你将能够映射Windows 窗体相对应的属性WPF上承载的元素的属性。

### 系统必备

你需要以下组件来完成本演练：

- Visual Studio 2017

### 创建项目

### 要创建项目

1. 创建**Windows 窗体应用程序**名为项目`PropertyMappingWithElementHost`。

2. 在中**解决方案资源管理器**，将引用添加到以下WPF程序集。

   - PresentationCore
   - PresentationFramework
   - WindowsBase
   - WindowsFormsIntegration

3. 将以下代码复制到顶部`Form1`代码文件。

   C#复制

   ```csharp
   using System.Windows;
   using System.Windows.Media;
   using System.Windows.Media.Imaging;
   using System.Windows.Forms.Integration;
   ```

4. 在 Windows 窗体设计器中打开 `Form1`。 双击要添加的事件处理程序的窗体[Load](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.form.load)事件。

5. 返回到 Windows 窗体设计器并添加事件处理程序的窗体的[Resize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.resize)事件。 有关详细信息，请参阅[如何：创建事件处理程序使用设计器](https://msdn.microsoft.com/library/8461e9b8-14e8-406f-936e-3726732b23d2)。

6. 声明[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)字段中`Form1`类。

   C#复制

   ```csharp
   ElementHost elemHost = null;
   ```

### 定义新的属性映射

[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)控件提供了一些默认属性映射。 通过调用添加新的属性映射[Add](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.propertymap.add)方法[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)控件的[PropertyMap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost.propertymap)。

### 若要定义新属性映射

1. 将以下代码复制到用于定义`Form1`类。

   C#复制

   ```csharp
   // The AddMarginMapping method adds a new property mapping
   // for the Margin property.
   private void AddMarginMapping()
   {
       elemHost.PropertyMap.Add(
           "Margin",
           new PropertyTranslator(OnMarginChange));
   }
   
   // The OnMarginChange method implements the mapping 
   // from the Windows Forms Margin property to the
   // Windows Presentation Foundation Margin property.
   //
   // The provided Padding value is used to construct 
   // a Thickness value for the hosted element's Margin
   // property.
   private void OnMarginChange(object h, String propertyName, object value)
   {
       ElementHost host = h as ElementHost;
       Padding p = (Padding)value;
       System.Windows.Controls.Button wpfButton = 
           host.Child as System.Windows.Controls.Button;
   
       Thickness t = new Thickness(p.Left, p.Top, p.Right, p.Bottom );
   
       wpfButton.Margin = t;
   }
   ```

   `AddMarginMapping`方法将添加的新映射[Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.margin)属性。

   `OnMarginChange`方法将转换[Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.margin)属性设置为WPF[Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)属性。

2. 将以下代码复制到用于定义`Form1`类。

   C#复制

   ```csharp
   // The AddRegionMapping method assigns a custom 
   // mapping for the Region property.
   private void AddRegionMapping()
   {
       elemHost.PropertyMap.Add(
           "Region",
           new PropertyTranslator(OnRegionChange));
   }
   
   // The OnRegionChange method assigns an EllipseGeometry to
   // the hosted element's Clip property.
   private void OnRegionChange(
       object h, 
       String propertyName, 
       object value)
   {
       ElementHost host = h as ElementHost;
       System.Windows.Controls.Button wpfButton = 
           host.Child as System.Windows.Controls.Button;
   
       wpfButton.Clip = new EllipseGeometry(new Rect(
           0, 
           0, 
           wpfButton.ActualWidth, 
           wpfButton.ActualHeight));
   }
   
   // The Form1_Resize method handles the form's Resize event.
   // It calls the OnRegionChange method explicitly to 
   // assign a new clipping geometry to the hosted element.
   private void Form1_Resize(object sender, EventArgs e)
   {
       this.OnRegionChange(elemHost, "Region", null);
   }
   ```

   `AddRegionMapping`方法将添加的新映射[Region](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.region)属性。

   `OnRegionChange`方法将转换[Region](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.region)属性设置为WPF[Clip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.clip)属性。

   `Form1_Resize`方法将处理窗体的[Resize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.resize)事件并调整其大小以适合所承载的元素的剪辑区域。

### 删除默认属性映射

通过调用来移除默认属性映射[Remove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.propertymap.remove)方法[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)控件的[PropertyMap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost.propertymap)。

- 将以下代码复制到用于定义`Form1`类。

  C#复制

  ```csharp
  // The RemoveCursorMapping method deletes the default
  // mapping for the Cursor property.
  private void RemoveCursorMapping()
  {
      elemHost.PropertyMap.Remove("Cursor");
  }
  ```

  `RemoveCursorMapping`方法删除默认映射[Cursor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.cursor)属性。

### 扩展默认属性映射

可以使用默认属性映射，并使用自己的映射对其进行扩展。

- 将以下代码复制到用于定义`Form1`类。

  C#复制

  ```csharp
  // The ExtendBackColorMapping method adds a property
  // translator if a mapping already exists.
  private void ExtendBackColorMapping()
  {
      if (elemHost.PropertyMap["BackColor"] != null)
      {
          elemHost.PropertyMap["BackColor"] += 
              new PropertyTranslator(OnBackColorChange);
      }
  }
  
  // The OnBackColorChange method assigns a specific image 
  // to the hosted element's Background property.
  private void OnBackColorChange(object h, String propertyName, object value)
  {
      ElementHost host = h as ElementHost;
      System.Windows.Controls.Button wpfButton = 
          host.Child as System.Windows.Controls.Button;
  
      ImageBrush b = new ImageBrush(new BitmapImage(
          new Uri(@"file:///C:\WINDOWS\Santa Fe Stucco.bmp")));
      wpfButton.Background = b;
  }
  ```

  `ExtendBackColorMapping`方法将自定义属性转换器添加到现有[BackColor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.backcolor)属性映射。

  `OnBackColorChange`方法将特定图像分配给托管控件的[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)属性。 `OnBackColorChange`应用默认属性映射后调用方法。

### 初始化属性映射

1. 将以下代码复制到用于定义`Form1`类。

   C#复制

   ```csharp
   private void Form1_Load(object sender, EventArgs e)
   {
       // Create the ElementHost control.
       elemHost = new ElementHost();
       elemHost.Dock = DockStyle.Fill;
       this.Controls.Add(elemHost);
   
       // Create a Windows Presentation Foundation Button element 
       // and assign it as the ElementHost control's child. 
       System.Windows.Controls.Button wpfButton = new System.Windows.Controls.Button();
       wpfButton.Content = "Windows Presentation Foundation Button";
       elemHost.Child = wpfButton;
   
       // Map the Margin property.
       this.AddMarginMapping();
   
       // Remove the mapping for the Cursor property.
       this.RemoveCursorMapping();
   
       // Add a mapping for the Region property.
       this.AddRegionMapping();
   
       // Add another mapping for the BackColor property.
       this.ExtendBackColorMapping();
   
       // Cause the OnMarginChange delegate to be called.
       elemHost.Margin = new Padding(23, 23, 23, 23);
   
       // Cause the OnRegionChange delegate to be called.
       elemHost.Region = new Region();
   
       // Cause the OnBackColorChange delegate to be called.
       elemHost.BackColor = System.Drawing.Color.AliceBlue;
   }
   ```

   `Form1_Load`方法将处理[Load](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.form.load)事件并执行以下初始化。

   - 创建WPF[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)元素。
   - 调用先前在演练中定义的方法来设置属性映射。
   - 将初始值分配给映射的属性。

2. 按 F5 生成并运行该应用程序。

## [Walkthrough: Mapping Properties Using the WindowsFormsHost Element](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/walkthrough-mapping-properties-using-the-windowsformshost-element)

本演练演示如何使用[PropertyMap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost.propertymap)属性将映射WPF属性设置为上托管的相应属性Windows 窗体控件。

本演练涉及以下任务：

- 创建项目。
- 定义应用程序布局。
- 定义新的属性映射。
- 删除默认属性映射。
- 替换默认属性映射。
- 扩展默认属性映射。

在本演练中所涉及任务的完整代码列表，请参阅[映射属性使用 WindowsFormsHost 元素示例](https://go.microsoft.com/fwlink/?LinkID=160019)。

完成后，你将能够映射WPF上托管的相应属性的属性Windows 窗体控件。

### 系统必备

你需要以下组件来完成本演练：

- Visual Studio 2017

### 创建并设置项目

1. 创建**WPF 应用程序**名为项目`PropertyMappingWithWfhSample`。
2. 在中**解决方案资源管理器**，添加对 WindowsFormsIntegration 程序集，它名为 WindowsFormsIntegration.dll 的引用。
3. 在中**解决方案资源管理器**，添加对 System.Drawing 和 System.Windows.Forms 程序集的引用。

### 定义应用程序布局

WPF-基于应用程序使用[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素来承载Windows 窗体控件。

1. 打开 Window1.xaml 中的WPF 设计器。

2. 用下面的代码替换现有代码。

   XAML复制

   ```xaml
   <Window x:Class="PropertyMappingWithWfh.Window1"
       xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
       xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
       Title="PropertyMappingWithWfh" Height="300" Width="300"
       Loaded="WindowLoaded">
     <DockPanel Name="panel1" LastChildFill="True">
       <WindowsFormsHost Name="wfHost" DockPanel.Dock="Left" SizeChanged="Window1_SizeChanged" FontSize="20" />
     </DockPanel>
   </Window>
   ```

3. 在代码编辑器中打开 Window1.xaml.cs。

4. 在该文件顶部导入以下命名空间。

   C#复制

   ```csharp
   using System.Drawing;
   using System.Drawing.Drawing2D;
   using System.Windows.Forms;
   using System.Windows.Forms.Integration;
   ```

### 定义新的属性映射

[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素提供了一些默认属性映射。 通过调用添加新的属性映射[Add](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.propertymap.add)方法[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素的[PropertyMap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost.propertymap)。

- 将以下代码复制到用于定义`Window1`类。

  C#复制

  ```csharp
  // The AddClipMapping method adds a custom 
  // mapping for the Clip property.
  private void AddClipMapping()
  {
      wfHost.PropertyMap.Add(
          "Clip",
          new PropertyTranslator(OnClipChange));
  }
  
  // The OnClipChange method assigns an elliptical clipping 
  // region to the hosted control's Region property.
  private void OnClipChange(object h, String propertyName, object value)
  {
      WindowsFormsHost host = h as WindowsFormsHost;
      System.Windows.Forms.CheckBox cb = host.Child as System.Windows.Forms.CheckBox;
  
      if (cb != null)
      {
          cb.Region = this.CreateClipRegion();
      }
  }
  
  // The Window1_SizeChanged method handles the window's 
  // SizeChanged event. It calls the OnClipChange method explicitly 
  // to assign a new clipping region to the hosted control.
  private void Window1_SizeChanged(object sender, SizeChangedEventArgs e)
  {
      this.OnClipChange(wfHost, "Clip", null);
  }
  
  // The CreateClipRegion method creates a Region from an
  // elliptical GraphicsPath.
  private Region CreateClipRegion()
  {   
      GraphicsPath path = new GraphicsPath();
  
      path.StartFigure(); 
  
      path.AddEllipse(new System.Drawing.Rectangle( 
          0, 
          0, 
          (int)wfHost.ActualWidth, 
          (int)wfHost.ActualHeight ) );
  
      path.CloseFigure(); 
  
      return( new Region(path) );
  }
  ```

  `AddClipMapping`方法将添加的新映射[Clip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.clip)属性。

  `OnClipChange`方法将转换[Clip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.clip)属性设置为Windows 窗体[Region](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.region)属性。

  `Window1_SizeChanged`方法处理窗口的[SizeChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.sizechanged)事件并调整其大小以适应应用程序窗口的剪辑区域。

### 删除默认属性映射

通过调用来移除默认属性映射[Remove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.propertymap.remove)方法[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素的[PropertyMap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost.propertymap)。

- 将以下代码复制到用于定义`Window1`类。

  C#复制

  ```csharp
  // The RemoveCursorMapping method deletes the default
  // mapping for the Cursor property.
  private void RemoveCursorMapping()
  {
      wfHost.PropertyMap.Remove("Cursor");
  }
  ```

  `RemoveCursorMapping`方法删除默认映射[Cursor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.cursor)属性。

### 替换默认属性映射

通过删除默认映射和调用来替换默认属性映射[Add](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.propertymap.add)方法[WindowsFormsHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost)元素的[PropertyMap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.windowsformshost.propertymap)。

- 将以下代码复制到用于定义`Window1`类。

  C#复制

  ```csharp
  // The ReplaceFlowDirectionMapping method replaces the  
  // default mapping for the FlowDirection property.
  private void ReplaceFlowDirectionMapping()
  {
      wfHost.PropertyMap.Remove("FlowDirection");
  
      wfHost.PropertyMap.Add(
          "FlowDirection",
          new PropertyTranslator(OnFlowDirectionChange));
  }
  
  // The OnFlowDirectionChange method translates a 
  // Windows Presentation Foundation FlowDirection value 
  // to a Windows Forms RightToLeft value and assigns
  // the result to the hosted control's RightToLeft property.
  private void OnFlowDirectionChange(object h, String propertyName, object value)
  {
      WindowsFormsHost host = h as WindowsFormsHost;
      System.Windows.FlowDirection fd = (System.Windows.FlowDirection)value;
      System.Windows.Forms.CheckBox cb = host.Child as System.Windows.Forms.CheckBox;
  
      cb.RightToLeft = (fd == System.Windows.FlowDirection.RightToLeft ) ? 
          RightToLeft.Yes : RightToLeft.No;
  }
  
  // The cb_CheckedChanged method handles the hosted control's
  // CheckedChanged event. If the Checked property is true,
  // the flow direction is set to RightToLeft, otherwise it is
  // set to LeftToRight.
  private void cb_CheckedChanged(object sender, EventArgs e)
  {
      System.Windows.Forms.CheckBox cb = sender as System.Windows.Forms.CheckBox;
  
      wfHost.FlowDirection = ( cb.CheckState == CheckState.Checked ) ? 
              System.Windows.FlowDirection.RightToLeft : 
              System.Windows.FlowDirection.LeftToRight;
  }
  ```

  `ReplaceFlowDirectionMapping`方法将替换的默认映射[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)属性。

  `OnFlowDirectionChange`方法将转换[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)属性设置为Windows 窗体[RightToLeft](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.righttoleft)属性。

  `cb_CheckedChanged`方法将处理[CheckedChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.checkbox.checkedchanged)上的事件[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.checkbox)控件。 它将分配[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)属性值的基础[CheckState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.checkbox.checkstate)属性

### 扩展默认属性映射

可以使用默认属性映射，并使用自己的映射对其进行扩展。

- 将以下代码复制到用于定义`Window1`类。

  C#复制

  ```csharp
  // The ExtendBackgroundMapping method adds a property
  // translator if a mapping already exists.
  private void ExtendBackgroundMapping()
  {
      if (wfHost.PropertyMap["Background"] != null)
      {
          wfHost.PropertyMap["Background"] += new PropertyTranslator(OnBackgroundChange);
      }
  }
  
  // The OnBackgroundChange method assigns a specific image 
  // to the hosted control's BackgroundImage property.
  private void OnBackgroundChange(object h, String propertyName, object value)
  {
      WindowsFormsHost host = h as WindowsFormsHost;
      System.Windows.Forms.CheckBox cb = host.Child as System.Windows.Forms.CheckBox;
      ImageBrush b = value as ImageBrush;
  
      if (b != null)
      {
          cb.BackgroundImage = new System.Drawing.Bitmap(@"C:\WINDOWS\Santa Fe Stucco.bmp");
      }
  }
  ```

  `ExtendBackgroundMapping`方法将自定义属性转换器添加到现有[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)属性映射。

  `OnBackgroundChange`方法将特定图像分配给托管控件的[BackgroundImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.backgroundimage)属性。 `OnBackgroundChange`应用默认属性映射后调用方法。

### 初始化属性映射

通过调用前面所述的方法中设置属性映射[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)事件处理程序。

1. 将以下代码复制到用于定义`Window1`类。

   C#复制

   ```csharp
   // The WindowLoaded method handles the Loaded event.
   // It enables Windows Forms visual styles, creates 
   // a Windows Forms checkbox control, and assigns the
   // control as the child of the WindowsFormsHost element. 
   // This method also modifies property mappings on the 
   // WindowsFormsHost element.
   private void WindowLoaded(object sender, RoutedEventArgs e)
   {
       System.Windows.Forms.Application.EnableVisualStyles();
   
       // Create a Windows Forms checkbox control and assign 
       // it as the WindowsFormsHost element's child.
       System.Windows.Forms.CheckBox cb = new System.Windows.Forms.CheckBox();
       cb.Text = "Windows Forms checkbox";
       cb.Dock = DockStyle.Fill;
       cb.TextAlign = ContentAlignment.MiddleCenter;
       cb.CheckedChanged += new EventHandler(cb_CheckedChanged);
       wfHost.Child = cb;
   
       // Replace the default mapping for the FlowDirection property.
       this.ReplaceFlowDirectionMapping();
   
       // Remove the mapping for the Cursor property.
       this.RemoveCursorMapping();
   
       // Add the mapping for the Clip property.
       this.AddClipMapping();
   
       // Add another mapping for the Background property.
       this.ExtendBackgroundMapping();
   
       // Cause the OnFlowDirectionChange delegate to be called.
       wfHost.FlowDirection = System.Windows.FlowDirection.LeftToRight;
   
       // Cause the OnClipChange delegate to be called.
       wfHost.Clip = new RectangleGeometry();
   
       // Cause the OnBackgroundChange delegate to be called.
       wfHost.Background = new ImageBrush();
   }
   ```

   `WindowLoaded`方法将处理[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)事件并执行以下初始化。

   - 创建Windows 窗体[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.checkbox)控件。
   - 调用先前在演练中定义的方法来设置属性映射。
   - 将初始值分配给映射的属性。

2. 按 F5 生成并运行该应用程序。 单击复选框可查看的效果[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)映射。 单击复选框时，布局会反转其左右方向。

## [Walkthrough: Localizing a Hybrid Application](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/walkthrough-localizing-a-hybrid-application)

本演练演示如何将本地化WPF中的元素Windows 窗体-基于混合应用程序。

本演练涉及以下任务：

- 创建Windows 窗体宿主项目。
- 添加可本地化的内容。
- 启用本地化。
- 分配资源标识符。
- 使用 LocBaml 工具生成附属程序集。

在本演练中所涉及任务的完整代码列表，请参阅[本地化混合应用程序示例](https://go.microsoft.com/fwlink/?LinkID=160015)。

完成后，你将拥有一个本地化的混合应用程序。

### 系统必备

你需要以下组件来完成本演练：

- Visual Studio 2017

### 创建 Windows 窗体宿主项目

第一步是创建Windows 窗体应用程序项目，并添加WPF包含要本地化的内容元素。

### 创建宿主项目

1. 创建**WPF 应用程序**名为项目`LocalizingWpfInWf`。 (**文件** > **新** > **项目** > **Visual C#** 或**Visual Basic** > **经典桌面**> **WPF 应用程序**)。
2. 添加WPF[UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol)元素称为`SimpleControl`到项目。
3. 使用[ElementHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.integration.elementhost)控件中放置`SimpleControl`窗体上的元素。 有关详细信息，请参见[演练：承载 3-D WPF 复合控件在 Windows 窗体中的](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/walkthrough-hosting-a-3-d-wpf-composite-control-in-windows-forms)。

### 添加可本地化的内容

接下来，您将添加Windows 窗体标签控件，并设置WPF到可本地化的字符串的元素的内容。

1. 在中**解决方案资源管理器**，双击**SimpleControl.xaml**中打开WPF 设计器。

2. 设置的内容[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)控制是通过使用下面的代码。

   XAML复制

   ```xaml
   <UserControl x:Class="LocalizingWpfInWf.SimpleControl"
       xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
       xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
       >
   
     <Canvas>
       <Button Content="Hello"/>
     </Canvas>
   </UserControl>
   ```

3. 在中**解决方案资源管理器**，双击**Form1**若要在 Windows 窗体设计器中打开它。

4. 打开**工具箱**，然后双击**标签**标签控件添加到窗体。 将其 [Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.text) 属性的值设置为 `"Hello"`。

5. 按 F5 生成并运行该应用程序。

   这两个`SimpleControl`元素和标签控件显示文本 **"Hello"**。

### 启用本地化

Windows 窗体设计器提供用于在附属程序集中启用本地化的设置。

1. 在中**解决方案资源管理器**，双击**Form1.cs**若要在 Windows 窗体设计器中打开它。

2. 在中**属性**窗口中，将窗体的值**Localizable**属性设置为`true`。

3. 在中**属性**窗口中，设置的值**语言**属性设置为**西班牙语 （西班牙）**。

4. 在 Windows 窗体设计器中，选择标签控件。

5. 在中**属性**窗口中，设置的值[Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.control.text)属性设置为`"Hola"`。

   一个名为 Form1.es-ES.resx 的新资源文件会添加到项目中。

6. 在中**解决方案资源管理器**，右键单击**Form1.cs**然后单击**查看代码**以在代码编辑器中打开它。

7. 以下代码复制到`Form1`构造函数，然后调用`InitializeComponent`。

   C#复制

   ```csharp
   public Form1()
   {
       System.Threading.Thread.CurrentThread.CurrentUICulture = new System.Globalization.CultureInfo("es-ES");
   
       InitializeComponent();
   }
   ```

8. 在中**解决方案资源管理器**，右键单击**LocalizingWpfInWf**然后单击**卸载项目**。

   项目名称将标记为 **（不可用）**。

9. 右键单击**LocalizingWpfInWf**，然后单击**编辑 LocalizingWpfInWf.csproj**。

   项目文件将在代码编辑器中打开。

10. 将以下行复制到第一个`PropertyGroup`项目文件中。

    XML复制

    ```xml
    <UICulture>en-US</UICulture>
    ```

11. 保存项目文件并将其关闭。

12. 在中**解决方案资源管理器**，右键单击**LocalizingWpfInWf**然后单击**重新加载项目**。

### 分配资源标识符

可以通过使用资源标识符将可本地化内容映射到资源程序集。 MsBuild.exe 应用程序会自动分配资源标识符，当您指定`updateuid`选项。

1. 从开始菜单中，打开 Visual Studio 开发人员命令提示。

2. 使用以下命令将资源标识符分配到可本地化内容。

   复制

   ```
   msbuild -t:updateuid LocalizingWpfInWf.csproj
   ```

3. 在中**解决方案资源管理器**，双击**SimpleControl.xaml**以在代码编辑器中打开它。 你将看到`msbuild`命令添加`Uid`所有元素的都属性。 这有助于通过分配资源标识符进行本地化。

   XAML复制

   ```xaml
   <UserControl x:Uid="UserControl_1" x:Class="LocalizingWpfInWf.SimpleControl"
       xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
       xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
       >
   
     <Canvas x:Uid="Canvas_1">
       <Button x:Uid="Button_1" Content="Hello"/>
     </Canvas>
   </UserControl>
   ```

4. 按**F6**以生成解决方案。

### 使用 LocBaml 生成附属程序集

本地化的内容存储在纯资源*附属程序集*。 使用命令行工具 LocBaml.exe 生成本地化程序集为你WPF内容。

#### 生成附属程序集

1. 将 LocBaml.exe 复制到项目的 obj\Debug 文件夹中。 有关详细信息，请参阅[本地化应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-localize-an-application)。

2. 在“命令提示符”窗口中，使用以下命令将资源字符串提取到临时文件中。

   复制

   ```
   LocBaml /parse LocalizingWpfInWf.g.en-US.resources /out:temp.csv
   ```

3. 使用 Visual Studio 或其他文本编辑器打开 temp.csv 文件。 字符串替换为`"Hello"`使用其西班牙语翻译`"Hola"`。

4. 保存 temp.csv 文件。

5. 使用以下命令生成本地化资源文件。

   复制

   ```
   LocBaml /generate /trans:temp.csv LocalizingWpfInWf.g.en-US.resources /out:. /cul:es-ES
   ```

   将在 obj\Debug 文件夹中创建 LocalizingWpfInWf.g.es-ES.resources 文件。

6. 使用以下命令生成本地化附属程序集。

   复制

   ```
   Al.exe /out:LocalizingWpfInWf.resources.dll /culture:es-ES /embed:LocalizingWpfInWf.Form1.es-ES.resources /embed:LocalizingWpfInWf.g.es-ES.resources
   ```

   将在 obj\Debug 文件夹中创建 LocalizingWpfInWf.resources.dll 文件。

7. 将 LocalizingWpfInWf.resources.dll 文件复制到项目的 bin\Debug\es-ES 文件夹中。 替换现有文件。

8. 运行 LocalizingWpfInWf.exe，它位于项目的 bin\Debug 文件夹中。 不要重新生成应用程序，否则附属程序集将被覆盖。

   应用程序显示本地化后的字符串，而不是英语字符串。