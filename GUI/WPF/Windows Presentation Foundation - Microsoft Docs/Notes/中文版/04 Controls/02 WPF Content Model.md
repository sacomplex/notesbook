# [WPF Content Model](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/wpf-content-model)

Windows Presentation Foundation (WPF) 是一个演示平台，提供了许多控件和类似控件的类型，主要用于显示不同类型的内容。 若要确定所要使用的控件或要从其派生的控件，应该了解特定控件可以最佳效果显示的对象类型。

本主题概述了适用于 WPF 控件和类似控件的类型的内容模型。 内容模型描述可在控件中使用的内容。 本主题还列出了每个内容模型的内容属性。 内容属性是一种用于存储对象内容的属性。

## 包含任意内容的类

某些控件可以包含的任何类型，如字符串、 对象[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)对象，或[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)，它是其他项的容器。 例如，[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)可以包含图像和一些文本，或[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)可以包含的值[DateTime.Now](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime.now)。

WPF 有四个可包含任意内容的类。 下表列出了继承的类[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)。

| 包含任意内容的类                                             | 内容                                       |
| ------------------------------------------------------------ | ------------------------------------------ |
| [ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol) | 一个任意对象。                             |
| [HeaderedContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headeredcontentcontrol) | 一个标头和一个项（两者都是任意对象）。     |
| [ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol) | 一个任意对象集合。                         |
| [HeaderedItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headereditemscontrol) | 一个标头和一个项集合（全部都是任意对象）。 |

继承自这些类的控件可以包含相同类型的内容，并可以采用相同方式处理该内容。 下图显示了来自每个内容模型的一个控件，该控件包含了图像和一些文本。

![Button、GroupBox、Listbax、TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/controlcontentmodelimagetextinto.png)

### 包含一个任意对象的控件

[ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)类包含一段任意内容。 它的内容属性是[Content](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.content)。 以下控件继承自[ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)并使用其内容模型：

- [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)
- [ButtonBase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase)
- [CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)
- [ComboBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.comboboxitem)
- [ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)
- [Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)
- [GridViewColumnHeader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumnheader)
- [GroupItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.groupitem)
- [Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)
- [ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)
- [ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listviewitem)
- [NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)
- [RadioButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.radiobutton)
- [RepeatButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.repeatbutton)
- [ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)
- [StatusBarItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.statusbaritem)
- [ToggleButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.togglebutton)
- [ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)
- [UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol)
- [Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)

下图显示四个按钮，其[Content](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.content)设置为字符串，[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)对象， [Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)，和一个[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)，其中包含[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)和[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)。

![四个按钮](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/controlcontentmodelbuttons.png)
具有不同类型内容的四个按钮

有关如何设置的示例[Content](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.content)属性，请参阅[ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)。

### 包含一个标头和一个任意对象的控件

[HeaderedContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headeredcontentcontrol)类继承自[ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)并显示一个标头的内容。 它将继承的 content 属性[Content](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.content)，从[ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)，并定义[Header](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headeredcontentcontrol.header)的类型的属性[Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object); 因此，都可以为任意对象。

以下控件继承自[HeaderedContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headeredcontentcontrol)并使用其内容模型：

- [Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)
- [GroupBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.groupbox)
- [TabItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tabitem)

下图显示了两个[TabItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tabitem)对象。 第一个[TabItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tabitem)已[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)对象作为[Header](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headeredcontentcontrol.header)和[Content](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.content)。 [Header](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headeredcontentcontrol.header)设置为[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)，其中包含[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)和一个[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)。 [Content](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.content)设置为[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)，其中包含[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)和一个[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)。 第二个[TabItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tabitem)具有一个字符串[Header](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headeredcontentcontrol.header)和一个[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)中[Content](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.content)。

![TabControl](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/controlcontentmodelteabitem.png)
在 Header 属性中使用不同类型的 TabControl

有关如何创建的示例[TabItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tabitem)对象，请参阅[HeaderedContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headeredcontentcontrol)。

### 包含一个任意对象集合的控件

[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)类继承自[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)，可以包含多个项，如字符串、 对象或其他元素。 其内容属性为[ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource)和[Items](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.items)。 [ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource) 通常用于填充[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)与数据收集。 如果您不想要使用集合来填充[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)，可以通过使用添加项[Items](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.items)属性。

以下控件继承自[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)并使用其内容模型：

- [Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)
- [MenuBase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.menubase)
- [ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)
- [ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)
- [ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)
- [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)
- [ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)
- [TabControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tabcontrol)
- [TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)
- [Selector](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.selector)
- [StatusBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.statusbar)

下图显示[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)，其中包含这些类型的项：

- 一个字符串。
- 一个 [DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime) 对象。
- [UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)。
- 一个[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)，其中包含[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)和一个[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)。

![具有四种类型的内容的 ListBox](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/controlcontentmodellistbox2.png)
包含多种类型对象的 ListBox

### 包含一个标头和一个任意对象集合的控件

[HeaderedItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headereditemscontrol)类继承自[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)，可以包含多个项，如字符串、 对象或其他元素和一个标头。 它将继承[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)内容属性， [ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource)，并[Items](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.items)，它定义[Header](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headereditemscontrol.header)可以是任意对象的属性。

以下控件继承自[HeaderedItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headereditemscontrol)并使用其内容模型：

- [MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)
- [ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)
- [TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)



## 包含一个 UIElement 对象集合的类

[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)类进行定位并排列子[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)对象。 它的内容属性是[Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.children)。

以下类继承自[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)类并使用其内容模型：

- [Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)
- [DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)
- [Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)
- [TabPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.tabpanel)
- [ToolBarOverflowPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.toolbaroverflowpanel)
- [ToolBarPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.toolbarpanel)
- [UniformGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.uniformgrid)
- [StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)
- [VirtualizingPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingpanel)
- [VirtualizingStackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel)
- [WrapPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.wrappanel)

有关详细信息，请参阅[面板概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/panels-overview)。



## 影响 UIElement 外观的类

[Decorator](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.decorator)类应用视觉效果上或周围单个子[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)。 它的内容属性是[Child](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.decorator.child)。 以下类继承自[Decorator](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.decorator)并使用其内容模型：

- [AdornerDecorator](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adornerdecorator)
- [Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)
- [BulletDecorator](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.bulletdecorator)
- [ButtonChrome](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.windows.themes.buttonchrome)
- [ClassicBorderDecorator](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.windows.themes.classicborderdecorator)
- [InkPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkpresenter)
- [ListBoxChrome](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.windows.themes.listboxchrome)
- [SystemDropShadowChrome](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.windows.themes.systemdropshadowchrome)
- [Viewbox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewbox)

如下图所示[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)具有 （即装饰有）[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)围绕它。

![具有黑色边框的 TextBox](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/layout-border-around-textbox.png)
具有边框的 TextBlock



## 提供 UIElement 相关视觉反馈的类

[Adorner](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adorner)类向用户提供可视化提示。 例如，使用[Adorner](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adorner)向元素添加功能句柄或提供有关控件的状态信息。[Adorner](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adorner)类提供一个框架，以便您可以创建自己的装饰器。 WPF 不会提供任何实现的装饰器。 有关详细信息，请参阅[装饰器概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/adorners-overview)。



## 可让用户输入文本的类

WPF 提供了三个可让用户输入文本的主要控件。 每个控件都以不同方式显示文本。 下表列出了这三个与文本相关的控件、显示文本时的功能以及包含控件文本的属性。

| 控件                                                         | 文本显示方式           | 内容属性                                                     |
| ------------------------------------------------------------ | ---------------------- | ------------------------------------------------------------ |
| [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) | 纯文本                 | [Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.text) |
| [RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox) | 带格式文本             | [Document](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox.document) |
| [PasswordBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.passwordbox) | 隐藏文本（字符已屏蔽） | [Password](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.passwordbox.password) |



## 显示文本的类

某些类可用于显示纯文本或带格式文本。 可以使用[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)显示少量文本。 如果你想要显示大量文本，使用[FlowDocumentReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentreader)， [FlowDocumentPageViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentpageviewer)，或[FlowDocumentScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentscrollviewer)控件。

[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)具有两个内容属性：[Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.text)和[Inlines](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.inlines)。 如果想要显示使用一致格式的文本[Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.text)属性通常是最佳选择。 如果你打算使用不同的格式设置在整个文本，使用[Inlines](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.inlines)属性。 [Inlines](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.inlines)属性是一系列[Inline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline)对象，指定如何设置文本的格式。

下表列出的内容属性[FlowDocumentReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentreader)， [FlowDocumentPageViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentpageviewer)，和[FlowDocumentScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentscrollviewer)类。

| 控件                                                         | 内容属性 | 内容属性类型                                                 |
| ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| [FlowDocumentPageViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentpageviewer) | Document | [IDocumentPaginatorSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.idocumentpaginatorsource) |
| [FlowDocumentReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentreader) | Document | [FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument) |
| [FlowDocumentScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentscrollviewer) | Document | [FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument) |

[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)实现[IDocumentPaginatorSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.idocumentpaginatorsource)接口; 因此，所有三个类，可能需要[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)作为内容。



## 设置文本格式的类

[TextElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.textelement) 和及其相关的类可用于设置文本的格式。 [TextElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.textelement) 对象包含和中的文本格式[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)和[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)对象。 两种主要类型的[TextElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.textelement)对象是[Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block)元素和[Inline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline)元素。 一个[Block](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.block)元素表示的文本，例如段落或列表的块。 [Inline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline)元素表示块中的文本的一部分。 许多[Inline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.inline)类指定应用于中文本的格式。 每个[TextElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.textelement)具有其自己的内容模型。 有关详细信息，请参阅 [TextElement 内容模型概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/textelement-content-model-overview)。