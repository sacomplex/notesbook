# [Windows Presentation Foundation (WPF)](https://docs.microsoft.com/en-us/visualstudio/designers/getting-started-with-wpf?view=vs-2019)

Windows Presentation Foundation (WPF) 是一个可创建桌面客户端应用程序的 UI 框架。 WPF 开发平台支持广泛的应用程序开发功能，包括应用程序模型、资源、控件、图形、布局、数据绑定、文档和安全性。 它是 .NET Framework 的子集，因此，如果你曾经使用 ASP.NET 或 Windows 窗体通过 .NET Framework 构建应用程序，应该会熟悉此编程体验。 WPF 使用可扩展应用程序标记语言 (XAML) 为应用程序编程提供声明性模型。 本节包含 WPF 简介及入门帮助等主题。

## 我应从何处着手？

| Subject                       | 文章                                                         |
| ----------------------------- | ------------------------------------------------------------ |
| 我希望直接开始使用...         | [演练：我的第一个 WPF 桌面应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/getting-started/walkthrough-my-first-wpf-desktop-application) |
| 我想比较 XAML 设计工具...     | [在 Visual Studio 和 Blend for Visual Studio 中设计 XAML](https://docs.microsoft.com/zh-cn/visualstudio/designers/designing-xaml-in-visual-studio?view=vs-2019) |
| 是否是初次使用 .NET？         | [.NET Framework 概述](https://docs.microsoft.com/zh-cn/dotnet/framework/get-started/overview)  [应用程序要点](https://docs.microsoft.com/zh-cn/dotnet/standard/application-essentials)  [Visual C# 和 Visual Basic 入门](https://docs.microsoft.com/zh-cn/visualstudio/ide/quickstart-visual-basic-console?view=vs-2019) |
| 有关 WPF 的详细信息...        | [WPF 概述](https://docs.microsoft.com/zh-cn/visualstudio/designers/introduction-to-wpf?view=vs-2019)  [XAML 概述 (WPF)](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-overview-wpf)  [控件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/)  [数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview)  [使用 LINQ to XML 进行 WPF 数据绑定](https://docs.microsoft.com/zh-cn/visualstudio/designers/wpf-data-binding-with-linq-to-xml-overview?view=vs-2019) |
| 是否是 Windows 窗体开发人员？ | [Windows 窗体控件和等效的 WPF 控件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/windows-forms-controls-and-equivalent-wpf-controls)  [WPF 和 Windows 窗体互操作中受支持的方案](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/wpf-and-windows-forms-interoperation) |

## [WPF overview](https://docs.microsoft.com/en-us/visualstudio/designers/introduction-to-wpf?view=vs-2019)

使用 Windows Presentation Foundation (WPF)，你可以创建适用于 Windows 且具有非凡视觉效果的桌面客户端应用程序。

![Contoso Healthcare UI 示例](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/wpfintrofigure24.png?view=vs-2019)

WPF 的核心是一个与分辨率无关且基于矢量的呈现引擎，旨在充分利用现代图形硬件。 WPF 通过一套完善的应用程序开发功能对该核心进行了扩展，这些功能包括可扩展应用程序标记语言 (XAML)、控件、数据绑定、布局、二维和三维图形、动画、样式、模板、文档、媒体、文本和版式。 WPF 包含在 .NET Framework 中，因此你可以生成整合其他 .NET Framework 类库元素的应用程序。

本概述适用于新用户，介绍了 WPF 的主要功能和概念。

### 使用 WPF 进行编程

WPF 作为大部分位于 [System.Windows](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows) 命名空间中的 .NET Framework 类型的一个子集存在。 如果你之前使用托管技术（如 ASP.NET 和 Windows 窗体）通过 .NET Framework 生成过应用程序，则不会对基本的 WPF 编程体验感到陌生；你可以使用最喜欢的 .NET 编程语言（如 C# 或 Visual Basic）来完成实例化类、设置属性、调用方法以及处理事件等所有操作。

WPF 还包括增强属性和事件的其他编程构造： [依赖项属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-properties-overview) 和 [路由事件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/routed-events-overview)。

### 标记和代码隐藏

通过 WPF，可以使用标记和代码隐藏开发应用程序，这是 ASP.NET 开发人员已经熟悉的体验。 通常使用 XAML 标记实现应用程序的外观，同时使用托管编程语言（代码隐藏）来实现其行为。 这种外观和行为的分离具有以下优点：

- 降低了开发和维护成本，因为特定于外观的标记与特定于行为的代码不紧密耦合。
- 开发效率更高，因为设计人员在实现应用程序外观的同时，开发人员可以实现应用程序的行为。
- WPF 应用程序的[全球化和本地化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/wpf-globalization-and-localization-overview) 得以简化。

#### 标记

XAML 是一种基于 XML 的标记语言，以声明形式实现应用程序的外观。 通常用它创建窗口、对话框、页和用户控件，并填充控件、形状和图形。

下面的示例使用 XAML 来实现包含一个按钮的窗口的外观。

XAML复制

```xaml
<Window
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    Title="Window with Button"
    Width="250" Height="100">

  <!-- Add button to window -->
  <Button Name="button">Click Me!</Button>

</Window>
```

具体而言，此 XAML 通过分别使用 `Window` 和 `Button` 元素来定义窗口和按钮。 每个元素均配置了特性（如 `Window` 元素的 `Title` 特性）来指定窗口的标题栏文本。 在运行时，WPF 会将标记中定义的元素和特性转换为 WPF 类的实例。 例如， `Window` 元素被转换为 [Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window) 类的实例，该类的 [Title](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.title) 属性是 `Title` 特性的值。

下图显示上一个示例中的 XAML 定义的用户界面 (UI)。

![包含按钮的窗口](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/wpfintrofigure10.png?view=vs-2019)

由于 XAML 是基于 XML 的，因此使用它编写的 UI 汇集在嵌套元素的层次结构中，称为 [元素树](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/trees-in-wpf)。 元素树提供了一种直观的逻辑方式来创建和管理 UI。

#### 代码隐藏

应用程序的主要行为是实现响应用户交互的功能，包括处理事件（例如，单击菜单、工具栏或按钮）以及相应地调用业务逻辑和数据访问逻辑。 在 WPF 中，在与标记相关联的代码中实现此行为。 此类代码称为代码隐藏。 下面的示例演示上一个示例的更新标记和代码隐藏。

XAML复制

```xaml
<Window
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.AWindow"
    Title="Window with Button"
    Width="250" Height="100">

  <!-- Add button to window -->
  <Button Name="button" Click="button_Click">Click Me!</Button>

</Window>
```

C#复制

```csharp
using System.Windows; // Window, RoutedEventArgs, MessageBox 

namespace SDKSample
{
    public partial class AWindow : Window
    {
        public AWindow()
        {
            // InitializeComponent call is required to merge the UI 
            // that is defined in markup with this class, including  
            // setting properties and registering event handlers
            InitializeComponent();
        }

        void button_Click(object sender, RoutedEventArgs e)
        {
            // Show message box when button is clicked
            MessageBox.Show("Hello, Windows Presentation Foundation!");
        }
    }
}
```

在此示例中，代码隐藏实现派生自 [Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window) 类的类。 `x:Class` 特性用于将标记与代码隐藏类相关联。 从代码隐藏类的构造函数调用 `InitializeComponent`，以将标记中定义的 UI 与代码隐藏类合并在一起。 （生成应用程序时将为你生成 `InitializeComponent`，因此你无需手动实现它。）`x:Class` 和 `InitializeComponent` 的组合可确保你的实现无论在何时创建都会得到正确初始化。 代码隐藏类还可实现按钮的 [Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click) 事件的事件处理程序。 单击该按钮后，事件处理程序会通过调用 [System.Windows.MessageBox.Show](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.messagebox.show) 方法显示一个消息框。

下图显示单击该按钮后的结果。

![消息框](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/wpfintrofigure25.png?view=vs-2019)

### 控件

应用程序模型带来的用户体验是构造的控件。 在 WPF 中，控件是适用于 WPF 类这一类别的总括术语，这些类托管在窗口或页中、具有用户界面并实现一些行为。

有关详细信息，请参阅 [控件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/index)。

#### 按功能分类的 WPF 控件

下面列出了内置的 WPF 控件。

- **按钮**： [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) 和 [RepeatButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.repeatbutton)。
- **数据显示**： [DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)、 [ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)和 [TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)。
- **日期显示和选项**： [Calendar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.calendar) 和 [DatePicker](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datepicker)。
- **对话框**： [OpenFileDialog](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.win32.openfiledialog)、 [PrintDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.printdialog)和 [SaveFileDialog](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.win32.savefiledialog)。
- **数字墨迹**： [InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas) 和 [InkPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkpresenter)。
- **文档**： [DocumentViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.documentviewer)、 [FlowDocumentPageViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentpageviewer)、 [FlowDocumentReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentreader)、 [FlowDocumentScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentscrollviewer)和 [StickyNoteControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stickynotecontrol)。
- **输入**： [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)、 [RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)和 [PasswordBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.passwordbox)。
- **布局**： [Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)、 [BulletDecorator](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.bulletdecorator)、 [Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)、 [DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)、 [Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)、 [Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)、 [GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)、 [GridSplitter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridsplitter)、 [GroupBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.groupbox)、 [Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)、 [ResizeGrip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.resizegrip)、 [Separator](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.separator)、 [ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar)、 [ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)、 [StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)、 [Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)、 [Viewbox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewbox)、 [VirtualizingStackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel)、 [Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)和 [WrapPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.wrappanel)。
- **媒体**： [Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)、 [MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)和 [SoundPlayerAction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.soundplayeraction)。
- **菜单**： [ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)、 [Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)和 [ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)。
- **导航**： [Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)、 [Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)、 [Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)、 [NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)和 [TabControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tabcontrol)。
- **选项**： [CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)、 [ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)、 [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)、 [RadioButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.radiobutton)和 [Slider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider)。
- **用户信息**： [AccessText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.accesstext)、 [Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)、 [Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)、 [ProgressBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.progressbar)、 [StatusBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.statusbar)、 [TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)和 [ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)。

### 输入和命令

最常检测和响应用户输入的控件。 [WPF 输入系统](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/input-overview) 使用直接事件和路由事件来支持文本输入、焦点管理和鼠标定位。

应用程序通常具有复杂的输入要求。 WPF 提供了[命令系统](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/commanding-overview)，用于将用户输入操作与对这些操作做出响应的代码分隔开来。

### 布局

创建用户界面时，按照位置和大小排列控件以形成布局。 任何布局的一项关键要求都是适应窗口大小和显示设置的变化。 WPF 为你提供一流的可扩展布局系统，而不强制你编写代码以适应这些情况下的布局。

布局系统的基础是相对定位，这提高了适应不断变化的窗口和显示条件的能力。 此外，该布局系统还可管理控件之间的协商以确定布局。 协商是一个两步过程：首先，控件将需要的位置和大小告知父级；其次，父级将控件可以有的空间告知控件。

该布局系统通过基 WPF 类公开给子控件。 对于通用的布局（如网格、堆叠和停靠），WPF 包括若干布局控件：

- [Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)：子控件提供其自己的布局。
- [DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)：子控件与面板的边缘对齐。
- [Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)：子控件按行和列放置。
- [StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)：子控件垂直或水平堆叠。
- [VirtualizingStackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel)：子控件在水平或垂直的行上进行虚拟化和排列。
- [WrapPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.wrappanel)：子控件按从左到右的顺序放置，在当前行上的控件超出允许的空间时，换行到下一行。

下面的示例使用 [DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel) 布置几个 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 控件。

XAML复制

```xaml
<Window
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.LayoutWindow"
    Title="Layout with the DockPanel" Height="143" Width="319">
  
  <!--DockPanel to layout four text boxes--> 
  <DockPanel>
    <TextBox DockPanel.Dock="Top">Dock = "Top"</TextBox>
    <TextBox DockPanel.Dock="Bottom">Dock = "Bottom"</TextBox>
    <TextBox DockPanel.Dock="Left">Dock = "Left"</TextBox>
    <TextBox Background="White">This TextBox "fills" the remaining space.</TextBox>
  </DockPanel>

</Window>
```

[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel) 允许子 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 控件，以告诉它如何排列这些控件。 为了完成此操作，[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel) 实现 `Dock` 附加了属性，该属性公开给子控件，以允许每个子控件指定停靠样式。

 备注

由父控件实现以便子控件使用的属性是 WPF 构造，称为[附加属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/attached-properties-overview)。

下图显示上一个示例中的 XAML 标记的结果。

![DockPanel 页](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/wpfintrofigure11.png?view=vs-2019)

### 数据绑定

大多数应用程序旨在为用户提供查看和编辑数据的方法。 对于 WPF 应用程序，已对存储和访问数据的工作提供技术（如 SQL Server 和 ADO.NET）。 访问数据并将数据加载到应用程序的托管对象后，WPF 应用程序的复杂工作开始。 从根本上来说，这涉及到两件事：

1. 将数据从托管对象复制到控件，在控件中可以显示和编辑数据。
2. 确保使用控件对数据所做的更改将复制回托管对象。

为了简化应用程序开发，WPF 提供了一个数据绑定引擎来自动执行这些步骤。 数据绑定引擎的核心单元是 [Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding) 类，其工作是将控件（绑定目标）绑定到数据对象（绑定源）。 下图阐释了这种关系：

![基本数据绑定示意图](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/databindingmostbasic.png?view=vs-2019)

下一示例演示如何将 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 绑定到自定义 `Person` 对象的实例。 下面的代码演示了 `Person` 实现：

C#复制

```csharp
namespace SDKSample
{
    class Person
    {
        string name = "No Name";

        public string Name
        {
            get { return name; }
            set { name = value; }
        }
    }
}
```

下面的标记将 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 绑定到自定义 `Person` 对象的实例。

XAML复制

```xaml
<Window
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.DataBindingWindow">

  <!-- Bind the TextBox to the data source (TextBox.Text to Person.Name) -->
  <TextBox Name="personNameTextBox" Text="{Binding Path=Name}" />

</Window>
```

C#复制

```csharp
using System.Windows; // Window

namespace SDKSample
{
    public partial class DataBindingWindow : Window
    {
        public DataBindingWindow()
        {
            InitializeComponent();

            // Create Person data source
            Person person = new Person();

            // Make data source available for binding
            this.DataContext = person;
        }
    }
}
```

在此示例中， `Person` 类在代码隐藏中实例化并被设置为 `DataBindingWindow`的数据上下文。 在标记中， [Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.text) 的 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 属性被绑定至 `Person.Name` 属性（使用“`{Binding ... }`”XAML 语法）。 此 XAML 告知 WPF 将 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控件绑定至窗口的 `Person` 属性中存储的 [DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext) 对象。

WPF 数据绑定引擎提供了额外支持，包括验证、排序、筛选和分组。 此外，数据绑定支持在标准 WPF 控件显示的用户界面不恰当时，使用数据模板来为数据绑定创建自定义的用户界面。

有关详细信息，请参阅[数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview)。

### 图形

WPF 引入了一组广泛、可伸缩的灵活图形功能，具有以下优点：

- **图形与分辨率和设备均无关**。 WPF 图形系统中的基本度量单位是与设备无关的像素（即 1/96 英寸），且不考虑实际屏幕分辨率，并为实现与分辨率和设备无关的呈现提供了基础。 每个与设备无关的像素都会自动缩放，以匹配呈现它的系统的每英寸点数 (dpi) 设置。
- **精度更高**。 WPF 坐标系统使用双精度浮点数字度量，而不是单精度数字。 转换和不透明度值也表示为双精度数字。 WPF 还支持广泛的颜色域 (scRGB)，并集成了对管理来自不同颜色空间的输入的支持。
- **高级图形和动画支持**。 WPF 通过为你管理动画场景简化了图形编程，你无需担心场景处理、呈现循环和双线性内插。 此外，WPF 还提供了点击测试支持和全面的 alpha 合成支持。
- **硬件加速**。 WPF 图形系统充分利用图形硬件来尽量降低 CPU 使用率。

#### 二维形状

WPF 提供一个常用矢量绘制的二维形状库，如下图中所示的矩形和椭圆：

![椭圆和矩形](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/wpfintrofigure4.png?view=vs-2019)

形状的一个有趣功能是它们不只是用于显示；形状实现许多你期望的控件功能，包括键盘和鼠标输入。 下面的示例演示要处理的 [MouseUp](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouseup) 的 [Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse) 事件。

XAML复制

```xaml
<Window 
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.EllipseEventHandlingWindow"
    Title="Click the Ellipse">
    <Ellipse Name="clickableEllipse" Fill="Blue" MouseUp="clickableEllipse_MouseUp" />
</Window>
```

C#复制

```csharp
using System.Windows; // Window, MessageBox
using System.Windows.Input; // MouseButtonEventHandler

namespace SDKSample
{
    public partial class EllipseEventHandlingWindow : Window
    {
        public EllipseEventHandlingWindow()
        {
            InitializeComponent();
        }

        void clickableEllipse_MouseUp(object sender, MouseButtonEventArgs e)
        {
            // Display a message
            MessageBox.Show("You clicked the ellipse!");
        }
    }
}
```

下图显示了前面的代码生成的内容。

![包含文本“单击该椭圆！”的窗口](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/wpfintrofigure12.png?view=vs-2019)

有关详细信息，请参阅 [WPF 中的形状和基本绘图概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview)。

#### 二维几何图形

WPF 提供的二维形状包含基本形状的标准集。 但是，你可能需要创建自定义形状以帮助改进自定义用户界面的设计。 为此，WPF 提供了几何图形。 下图演示了使用几何图形来创建可直接绘制、用作画笔或用于剪辑其他形状和控件的自定义形状。

[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path) 对象可用于绘制封闭式或开放式形状、多个形状，甚至曲线形状。

[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry) 对象可用于剪辑、命中测试以及呈现二维图形数据。

![Path 的各种用法](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/wpfintrofigure5.png?view=vs-2019)

有关详细信息，请参阅[几何图形概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/geometry-overview)。

#### 二维效果

WPF 二维功能的子集包括视觉效果，如渐变、位图、绘图、用视频绘画、旋转、缩放和倾斜。 这些效果都可以使用画笔实现；下图演示了一些示例。

![不同画笔的图示](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/wpfintrofigure6.png?view=vs-2019)

有关详细信息，请参阅 [WPF 画笔概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/wpf-brushes-overview)。

#### 三维呈现

WPF 还包括三维呈现功能，这些功能与二维图形集成，以创建更精彩、更有趣的用户界面。 例如，下图显示呈现在三维形状上的二维图像。

![Visual3D 示例屏幕快照](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/wpfintrofigure13.png?view=vs-2019)

有关详细信息，请参阅[三维图形概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/3-d-graphics-overview)。

### 动画

WPF 动画支持可以使控件变大、抖动、旋转和淡出，以形成有趣的页面过渡等。 你可以对大多数 WPF 类，甚至自定义类进行动画处理。 下图显示了运行中的一个简单动画。

![具有动画效果的立方体图](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/wpfintrofigure7.png?view=vs-2019)

有关详细信息，请参阅[动画概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/animation-overview)。

### 媒体

传达丰富内容的一种方法是使用视听媒体。 WPF 为图像、视频和音频提供特殊支持。

#### 图像

图像对大多数应用程序很常见，WPF 提供多种方式来使用它们。 下图显示一个用户界面，该用户界面中的列表框中包含缩略图图像。 选中一个缩略图后，将显示该图像的原尺寸。

![缩略图图像和完整尺寸图像](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/wpfintrofigure8.png?view=vs-2019)

有关详细信息，请参阅[图像概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/imaging-overview)。

#### 视频和音频

[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement) 控件能够播放视频和音频，并且其足够灵活，可以用作其他自定义媒体播放器的基础。 下面的 XAML 标记实现一个媒体播放器。

XAML复制

```xaml
<MediaElement 
  Name="myMediaElement" 
  Source="media/wpf.wmv" 
  LoadedBehavior="Manual" 
  Width="350" Height="250" />
```

下图中的窗口显示了运行中的 [MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement) 控件。

![具有音频和视频的 MediaElement 控件](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/wpfintrofigure1.png?view=vs-2019)

有关详细信息，请参阅[图形和多媒体](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia)。

### 文本和版式

为了促进高质量的文本呈现，WPF 提供以下功能：

- OpenType 字体支持。
- ClearType 增强功能。
- 利用硬件加速的高性能。
- 文本与媒体、图形和动画的集成。
- 国际字体支持和回退机制。

作为文本与图形集成的演示，下图显示了文本修饰的应用程序。

![具有各种文本修饰的文本](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/wpfintrofigure23.png?view=vs-2019)

有关详细信息，请参阅 [Windows Presentation Foundation 中的版式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/typography-in-wpf)。

### 自定义 WPF 应用

到目前为止，你已经了解用于开发应用程序的核心 WPF 构建块。 你可以使用该应用程序模型来托管和交付应用程序内容，它主要由控件组成。 若要简化用户界面中控件的排列，并确保保持该排列能够应对窗口大小和显示设置的更改，你可以使用 WPF 布局系统。 由于大多数应用程序允许用户与数据交互，因此你可以使用数据绑定来减少将用户界面与数据集成的工作。 若要增强你应用程序的可视化外观，可以使用 WPF 提供的综合图形、动画和媒体支持。

不过，在创建和管理真正独特且视觉效果非凡的用户体验时，基础知识通常是不够的。 标准的 WPF 控件可能无法与你所需的应用程序外观集成。 数据可能不会以最有效的方式显示。 你应用程序的整体用户体验可能不适合 Windows 主题的默认外观和感觉。 在许多方面，演示技术需要视觉扩展性，需要的程度与任何其他类型的扩展性一样。

为此，WPF 提供了多种机制用于创建独特的用户体验，包括控件、触发器、控件和数据模板、样式、用户界面资源以及主题和皮肤的丰富内容模型。

#### 内容模型

大多数 WPF 控件的主要用途是显示内容。 在 WPF 中，可以构成控件内容的项的类型和数目称为控件的 *内容模型*。 某些控件可以包含一种内容类型的一个项；例如， [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 的内容是分配给 [Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.text) 属性的一个字符串值。 下面的示例设置 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)的内容。

XAML复制

```xaml
<Window
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.TextBoxContentWindow"
    Title="TextBox Content">

    <TextBox Text="This is the content of a TextBox." />
</Window>
```

下图显示结果。

![包含文本的 TextBox 控件](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/wpfintrofigure21.png?view=vs-2019)

但是，其他控件可以包含不同内容类型的多个项； [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)的内容（由 [Content](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.content) 属性指定）可以包含各种项（包括布局控件、文本、图像和形状）。 下面的示例演示了 [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) ，其内容包括 [DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)、 [Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)、 [Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)和 [MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)。

XAML复制

```xaml
<Window
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.ButtonContentWindow"
    Title="Button Content">

  <Button Margin="20">
    <!-- Button Content -->
    <DockPanel Width="200" Height="180">
      <Label DockPanel.Dock="Top" HorizontalAlignment="Center">Click Me!</Label>
      <Border Background="Black" BorderBrush="Yellow" BorderThickness="2"
        CornerRadius="2" Margin="5">
        <MediaElement Source="media/wpf.wmv" Stretch="Fill" />
      </Border>
    </DockPanel>
  </Button>
</Window>
```

下图显示此按钮的内容。

![包含多种类型的内容的按钮](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/wpfintrofigure22.png?view=vs-2019)

有关各种控件支持的内容类型的详细信息，请参阅 [WPF 内容模型](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/wpf-content-model)。

#### 触发器

尽管 XAML 标记的主要用途是实现应用程序的外观，你也可以使用 XAML 来实现应用程序行为的某些方面。 其中一个示例是使用触发器来基于用户交互更改应用程序的外观。 有关详细信息，请参阅[样式设置和模板化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/styling-and-templating)。

#### 控件模板

WPF 控件的默认用户界面通常是从其他控件和形状构造的。 例如， [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) 由 [ButtonChrome](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.windows.themes.buttonchrome) 和 [ContentPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter) 控件组成。 [ButtonChrome](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.windows.themes.buttonchrome) 提供了标准按钮外观，而 [ContentPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter) 显示按钮的内容，正如 [Content](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.content) 属性所指定。

有时，某个控件的默认外观可能与应用程序的整体外观不一致。 在这种情况下，可以使用 [ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate) 更改控件的用户界面的外观，而不更改其内容和行为。

例如，下面的示例演示如何使用 [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) 更改 [ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)的外观。

XAML复制

```xaml
<Window 
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  x:Class="SDKSample.ControlTemplateButtonWindow"
  Title="Button with Control Template" Height="158" Width="290">

  <!-- Button using an ellipse -->
  <Button Content="Click Me!" Click="button_Click">
    <Button.Template>
      <ControlTemplate TargetType="{x:Type Button}">
        <Grid Margin="5">
          <Ellipse Stroke="DarkBlue" StrokeThickness="2">
            <Ellipse.Fill>
              <RadialGradientBrush Center="0.3,0.2" RadiusX="0.5" RadiusY="0.5">
                <GradientStop Color="Azure" Offset="0.1" />
                <GradientStop Color="CornflowerBlue" Offset="1.1" />
              </RadialGradientBrush>
            </Ellipse.Fill>
          </Ellipse>
          <ContentPresenter Name="content" HorizontalAlignment="Center" 
            VerticalAlignment="Center"/>
        </Grid>
      </ControlTemplate>
    </Button.Template>

  </Button>

</Window>
```

C#复制

```csharp
using System.Windows; // Window, RoutedEventArgs, MessageBox

namespace SDKSample
{
    public partial class ControlTemplateButtonWindow : Window
    {
        public ControlTemplateButtonWindow()
        {
            InitializeComponent();
        }

        void button_Click(object sender, RoutedEventArgs e)
        {
            // Show message box when button is clicked
            MessageBox.Show("Hello, Windows Presentation Foundation!");
        }
    }
}
```

在此示例中，默认按钮用户界面已被替换为 [Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse) ，它具有深蓝色边框并使用 [RadialGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.radialgradientbrush)进行填充。[ContentPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter) 控件显示 [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)的内容，“单击我!” 单击 [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) 后，在 [Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click) 控件的默认行为中，仍将引发 [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) 事件。 结果如下图所示：

![省略号按钮和第二个窗口](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/wpfintrofigure2.png?view=vs-2019)

#### 数据模板

使用控件模板可以指定控件的外观，而使用数据模板则可以指定控件内容的外观。 数据模板经常用于改进绑定数据的显示方式。 下图显示 [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 的默认外观，它绑定到 `Task` 对象的集合，其中每个任务都具有名称、描述和优先级。

![具有默认外观的列表框](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/wpfintrofigure18.png?view=vs-2019)

默认外观是你对 [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)的期望。 但是，每个任务的默认外观仅包含任务名称。 若要显示任务名称、描述和优先级，必须使用 [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 更改 [DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)控件绑定列表项的默认外观。 下面的 XAML 定义了此类 [DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)，它通过使用 [ItemTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemtemplate) 特性应用于每个任务。

XAML复制

```xaml
<Window
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  x:Class="SDKSample.DataTemplateWindow"
  Title="With a Data Template">
  <Window.Resources>
    <!-- Data Template (applied to each bound task item in the task collection) -->
    <DataTemplate x:Key="myTaskTemplate">
      <Border Name="border" BorderBrush="DarkSlateBlue" BorderThickness="2"
        CornerRadius="2" Padding="5" Margin="5">
        <Grid>
          <Grid.RowDefinitions>
            <RowDefinition/>
            <RowDefinition/>
            <RowDefinition/>
          </Grid.RowDefinitions>
          <Grid.ColumnDefinitions>
            <ColumnDefinition Width="Auto" />
            <ColumnDefinition />
          </Grid.ColumnDefinitions>
          <TextBlock Grid.Row="0" Grid.Column="0" Padding="0,0,5,0" Text="Task Name:"/>
          <TextBlock Grid.Row="0" Grid.Column="1" Text="{Binding Path=TaskName}"/>
          <TextBlock Grid.Row="1" Grid.Column="0" Padding="0,0,5,0" Text="Description:"/>
          <TextBlock Grid.Row="1" Grid.Column="1" Text="{Binding Path=Description}"/>
          <TextBlock Grid.Row="2" Grid.Column="0" Padding="0,0,5,0" Text="Priority:"/>
          <TextBlock Grid.Row="2" Grid.Column="1" Text="{Binding Path=Priority}"/>
        </Grid>
      </Border>
    </DataTemplate>
  </Window.Resources>

  <!-- UI -->
  <DockPanel>
    <!-- Title -->
    <Label DockPanel.Dock="Top" FontSize="18" Margin="5" Content="My Task List:"/>

    <!-- Data template is specified by the ItemTemplate attribute -->
    <ListBox
      ItemsSource="{Binding}"
      ItemTemplate="{StaticResource myTaskTemplate}"
      HorizontalContentAlignment="Stretch"
      IsSynchronizedWithCurrentItem="True"
      Margin="5,0,5,5" />

 </DockPanel>
</Window>
```

下图显示了此代码的作用。

![使用数据模板的列表框](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/wpfintrofigure19.png?view=vs-2019)

注意， [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 已保留其行为和整体外观；仅列表框显示的内容外观已更改。

有关详细信息，请参阅[数据模板化概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-templating-overview)。

#### 样式

通过样式功能，开发人员和设计人员能够对其产品的特定外观进行标准化。 WPF 提供了一个强样式模型，其基础是 [Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style) 元素。 下面的示例创建一个样式，该样式将窗口上的每个 [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) 的背景色设置为 `Orange`。

XAML复制

```xaml
<Window
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.StyleWindow"
    Title="Styles">
  <!-- Style that will be applied to all buttons -->
  <Style TargetType="{x:Type Button}">
    <Setter Property="Background" Value="Orange" />
    <Setter Property="BorderBrush" Value="Crimson" />
    <Setter Property="FontSize" Value="20" />
    <Setter Property="FontWeight" Value="Bold" />
    <Setter Property="Margin" Value="5" />
  </Style>
  <!-- This button will have the style applied to it -->
  <Button>Click Me!</Button>

  <!-- This label will not have the style applied to it -->
  <Label>Don't Click Me!</Label>

  <!-- This button will have the style applied to it -->
  <Button>Click Me!</Button>
</Window>
```

由于此样式针对所有 [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) 控件，因此将自动应用于窗口中的所有按钮，如下图所示：

![两个橙色按钮](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/wpfintrofigure20.png?view=vs-2019)

有关详细信息，请参阅[样式设置和模板化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/styling-and-templating)。

#### 资源

应用程序中的控件应共享相同的外观，它可以包括从字体和背景色到控件模板、数据模板和样式的所有内容。 你可以对用户界面资源使用 WPF 支持，以将这些资源封装在一个位置以便重复使用。

下面的示例定义 [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) 和 [Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)共享的通用背景色。

XAML复制

```xaml
<Window
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.ResourcesWindow"
    Title="Resources Window">

  <!-- Define window-scoped background color resource -->
  <Window.Resources>
    <SolidColorBrush x:Key="defaultBackground" Color="Red" />
  </Window.Resources>

  <!-- Button background is defined by window-scoped resource -->
  <Button Background="{StaticResource defaultBackground}">One Button</Button>

  <!-- Label background is defined by window-scoped resource -->
  <Label Background="{StaticResource defaultBackground}">One Label</Label>
</Window>
```

此示例通过使用 `Window.Resources` 属性元素实现背景色资源。 此资源可供 [Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)的所有子级使用。 有各种资源作用域，具体如下（按解析顺序列出）：

1. 单个控件（使用继承的 [System.Windows.FrameworkElement.Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.resources) 属性）。
2. [Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window) 或 [Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page) （也使用继承的 [System.Windows.FrameworkElement.Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.resources) 属性）。
3. [Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application) （使用 [System.Windows.Application.Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.resources) 属性）。

这些不同种类的作用域在定义和共享资源的方式方面为你提供了灵活性。

作为直接将你的资源与特定作用域关联的替代方法，可以通过使用单独的 [ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary) （可以在应用程序的其他部分引用）打包一个或多个资源。 例如，下面的示例定义资源字典中的默认背景色。

XAML复制

```xaml
<ResourceDictionary
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">

  <!-- Define background color resource -->
  <SolidColorBrush x:Key="defaultBackground" Color="Red" />

  <!-- Define other resources -->
</ResourceDictionary>
```

下面的示例引用上一个示例中定义的资源字典，以便在应用程序中共享它。

XAML复制

```xaml
<Application
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.App">

  <Application.Resources>
    <ResourceDictionary>
      <ResourceDictionary.MergedDictionaries>
        <ResourceDictionary Source="BackgroundColorResources.xaml"/>
      </ResourceDictionary.MergedDictionaries>
    </ResourceDictionary>
  </Application.Resources>
</Application>
```

资源和资源字典是 WPF 主题和皮肤支持的基础。

有关详细信息，请参阅[资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-resources)。

#### 自定义控件

尽管 WPF 提供了大量自定义支持，但你仍可能会遇到现有 WPF 控件不满足你的应用程序或其用户的需求的情况。 出现这种情况的原因有：

- 不能通过自定义现有 WPF 实现的外观和感觉创建所需的用户界面。
- 现有 WPF 实现不支持（或很难支持）所需的行为。

但是，此时，你可以充分利用三个 WPF 模型中的一个来创建新的控件。 每个模型都针对一个特定的方案并要求你的自定义控件派生自特定 WPF 基类。 下面列出了这三个模型：

- **用户控件模型**。 自定义控件派生自 [UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol) 并由一个或多个其他控件组成。
- **控件模型**。 自定义控件派生自 [Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control) ，并用于生成使用模板将其行为与其外观分隔开来的实现，非常类似大多数 WPF 控件。 派生自 [Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control) 使得你可以更自由地创建自定义用户界面（相较用户控件），但它可能需要花费更多精力。
- **框架元素模型**。 当其外观由自定义呈现逻辑（而不是模板）定义时，自定义控件派生自 [FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)。

下面的示例演示一个派生自 [UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol)的自定义数值加/减控件。

XAML复制

```xaml
<UserControl
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  x:Class="SDKSample.NumericUpDown">

  <Grid>

    <Grid.RowDefinitions>
      <RowDefinition/>
      <RowDefinition/>
    </Grid.RowDefinitions>
    <Grid.ColumnDefinitions>
      <ColumnDefinition/>
      <ColumnDefinition/>
    </Grid.ColumnDefinitions>

    <!-- Value text box -->
    <Border BorderThickness="1" BorderBrush="Gray" Margin="2" Grid.RowSpan="2" 
      VerticalAlignment="Center" HorizontalAlignment="Stretch">
      <TextBlock Name="valueText" Width="60" TextAlignment="Right" Padding="5"/>
    </Border>

    <!-- Up/Down buttons -->
    <RepeatButton Name="upButton" Click="upButton_Click" Grid.Column="1" 
      Grid.Row="0">Up</RepeatButton>
    <RepeatButton Name="downButton" Click="downButton_Click" Grid.Column="1" 
      Grid.Row="1">Down</RepeatButton>

  </Grid>

</UserControl>
```

C#复制

```csharp
using System; // EventArgs
using System.Windows; // DependencyObject, DependencyPropertyChangedEventArgs,
                      // FrameworkPropertyMetadata, PropertyChangedCallback, 
                      // RoutedPropertyChangedEventArgs
using System.Windows.Controls; // UserControl

namespace SDKSample
{
    public partial class NumericUpDown : UserControl
    {
        // NumericUpDown user control implementation
    }
}
```

下一个示例说明了将用户控件合并到 [Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)所需的 XAML。

XAML复制

```xaml
<Window
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.UserControlWindow"
    xmlns:local="clr-namespace:SDKSample" 
    Title="User Control Window">

  <!-- Numeric Up/Down user control -->
  <local:NumericUpDown />

</Window>
```

下图显示了 `NumericUpDown` 中托管的 [Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)控件。

![自定义 UserControl](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/wpfintrofigure3.png?view=vs-2019)

有关自定义控件的详细信息，请参阅[控件创作概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/control-authoring-overview)。

### WPF 最佳做法

与任何开发平台一样，可以采用多种方式使用 WPF 以实现所需的结果。 为确保你的 WPF 应用程序提供所需的用户体验并满足一般用户的需求，针对辅助功能、全球化和本地化以及性能提供了一些建议的最佳做法。 有关详细信息，请参见:

- [辅助功能](https://docs.microsoft.com/zh-cn/dotnet/framework/ui-automation/accessibility-best-practices)
- [WPF 全球化和本地化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/wpf-globalization-and-localization-overview)
- [WPF 应用性能](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/optimizing-wpf-application-performance)
- [WPF 安全性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/security-wpf)

### 后续步骤

我们已经了解了 WPF 的主要功能。 现在可以生成你的第一个 WPF 应用。

[演练：我的第一个 WPF 桌面应用](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/getting-started/walkthrough-my-first-wpf-desktop-application)

## [WPF data binding with LINQ to XML](https://docs.microsoft.com/en-us/visualstudio/designers/wpf-data-binding-with-linq-to-xml-overview?view=vs-2019)

本主题介绍 [System.Xml.Linq](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq) 命名空间中的动态数据绑定功能。 这些功能可用作 Windows Presentation Foundation (WPF) 应用中用户界面 (UI) 元素的数据源。 此方案依赖于 [System.Xml.Linq.XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 和 [System.Xml.Linq.XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 的特殊动态属性。

### XAML 和 LINQ to XML

可扩展应用程序标记语言 (XAML) 是由 Microsoft 创建的 XML 方言，支持 .NET Framework 3.0 技术。 它在 WPF 中用于表示用户界面元素和相关功能，如事件和数据绑定。 在 Windows Workflow Foundation 中，XAML 用于表示程序结构，如程序控制（工作流）。 XAML 使技术的声明性方面与相关的过程性代码分离，从而可定义更具个性化的程序行为。

XAML 和 LINQ to XML 的交互有两种主要方式：

- 由于 XAML 文件是格式良好的 XML，因此可以通过 XML 技术（如 LINQ to XML）查询和操作。
- 由于 LINQ to XML 查询表示数据的源，因此这些查询可用作 WPF UI 元素数据绑定的数据源。

本文档说明第二种情况。

### Windows Presentation Foundation 中的数据绑定

WPF 数据绑定可使 UI 元素将其一个属性与一个数据源相关联。 这种情况的一个简单示例是 [Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)，其文本表示用户定义对象中一个公共属性的值。 WPF 数据绑定依赖于下列组件：

| **组件** | 说明                                                         |
| -------- | ------------------------------------------------------------ |
| 绑定目标 | 要与数据源关联的 UI 元素。 WPF 中的可视元素是从 [UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement) 类派生的。 |
| 目标属性 | 绑定目标的依赖项属性，反映数据绑定源的值。 从中派生 [DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject) 的 [UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement) 类直接支持依赖项属性。 |
| 绑定源   | 提供给 UI 元素以便进行显示的一个或多个值的源对象。 WPF 自动支持以下类型作为绑定源：CLR 对象、ADO.NET 数据对象、XML 数据（来自 XPath 或 LINQ to XML 查询）或其他 [DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)。 |
| 源路径   | 绑定源的属性，可解析为要绑定的一个或一组值。                 |

依赖项属性是特定于 WPF 的概念，它表示 UI 元素的动态计算的属性。 例如，依赖项属性通常具有默认值或具有由父元素提供的值。 [DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty) 类的实例（而不是支持标准属性的字段）支持这些特殊属性。 有关详细信息，请参阅[依赖项属性概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-properties-overview)。

#### WPF 中的动态数据绑定

默认情况下，仅在初始化目标 UI 元素时，才会发生数据绑定。 这称为“一次性”绑定。 这不能满足多数用途的需要；通常，数据绑定解决方案要求使用以下方式之一在运行时动态传播更改：

- 单向绑定，这种方式会自动传播对一侧所做的更改。 最常见的情况是对源所做的更改会反映在目标中，但有时需要相反的情况。
- 双向绑定，在这种方式中，对源所做的更改会自动传播到目标，而且对目标的更改也会自动传播到源。

为了进行单向或双向绑定，源必须实现一种更改通知机制，例如通过实现 [INotifyPropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.inotifypropertychanged) 接口或通过对支持的每个属性使用 PropertyNameChanged 模式。

有关 WPF 中数据绑定的详细信息，请参阅[数据绑定 (WPF)](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-wpf)。

### LINQ to XML 类中的动态属性

大多数 LINQ to XML 类都不适合作为适当的 WPF 动态数据源。 一些最有用的信息只能通过方法（而不是属性）提供，并且这些类中的属性不实现更改通知。 为了支持 WPF 数据绑定，LINQ to XML 公开了一组动态属性。

这些动态属性是特殊的运行时属性，它们重复 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 和 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 类中现有方法和属性的功能。 将这些属性添加到这些类中只是为了使这些类能够充当 WPF 的动态数据源。 为了满足这一要求，所有这些动态属性都要实现更改通知。 下一节 [LINQ to XML 动态属性](https://docs.microsoft.com/zh-cn/visualstudio/designers/linq-to-xml-dynamic-properties?view=vs-2019)中提供有关这些动态属性的详细参考。

> [System.Xml.Linq](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq) 命名空间的各个类中的很多标准公共属性都可用于一次性数据绑定。 但请记住，在这种方案下，源和目标都不会动态更新。

#### 访问动态属性

不能像访问标准属性那样访问 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 和 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 类中的动态属性。 例如，在符合 CLR 的语言（如 C#）中，动态属性不能：

- 在编译时直接访问。 动态属性对于编译器和 Visual Studio IntelliSense 是不可见的。
- 在运行时使用 .NET 反射来发现或访问。 即使在运行时，它们也不是基本 CLR 意义上的属性。

在 C# 中，动态属性只能在运行时通过 [System.ComponentModel](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel) 命名空间提供的功能进行访问。

但相比之下，在 XML 源中，可以通过下面形式的简洁表示法访问动态属性：

```xml
<object>.<dynamic-property>
```

这两个类的动态属性或者解析为可以直接使用的值，或者解析为必须与索引一起提供的索引器，以便获取结果值或值的集合。 后一种语法采用的格式为：

```xml
<object>.<dynamic-property>[<index-value>]
```

有关详细信息，请参阅 [LINQ to XML 动态属性](https://docs.microsoft.com/zh-cn/visualstudio/designers/linq-to-xml-dynamic-properties?view=vs-2019)。

为了实现 WPF 动态绑定，需要与 [System.Windows.Data](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data) 命名空间提供的功能（特别是 [Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding) 类）一起使用动态属性。

### [LINQ to XML dynamic properties](https://docs.microsoft.com/en-us/visualstudio/designers/linq-to-xml-dynamic-properties?view=vs-2019)

本节提供有关 LINQ to XML 中动态属性的参考信息。 具体地说，这些属性由 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 命名空间中的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)和 [System.Xml.Linq](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq) 类公开。

如 [使用 LINQ to XML 进行 WPF 数据绑定概述](https://docs.microsoft.com/zh-cn/visualstudio/designers/wpf-data-binding-with-linq-to-xml-overview?view=vs-2019) 主题中所述，每个动态属性都等效于同一类中的标准公共属性或方法。 多数情况下应使用这些标准成员；动态属性是专门为 LINQ to XML 数据绑定方案提供的。 有关这些类的标准成员的更多信息，请参见 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 和 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 参考主题。

就其解析值而论，本节中的动态属性可分为两类：

- 解析为单个值的简单动态属性，如 `Value` 和 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 类中的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 属性。
- 解析为索引器类型的索引值，如 [Elements](https://docs.microsoft.com/zh-cn/visualstudio/designers/elements-xelement-dynamic-property?view=vs-2019) 和 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 的 [Descendants](https://docs.microsoft.com/zh-cn/visualstudio/designers/descendants-xelement-dynamic-property?view=vs-2019) 属性。 对于要解析为所需值或集合的索引器类型，必须为其传递展开名称参数。

返回 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 类型索引值的所有动态属性都使用延迟执行。 有关延迟执行的详细信息，请参阅 [LINQ 查询简介 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/introduction-to-linq-queries)。

#### [XAttribute class dynamic properties](https://docs.microsoft.com/en-us/visualstudio/designers/xattribute-class-dynamic-properties?view=vs-2019)

本节说明 [System.Xml.Linq.XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 的动态属性。

| 主题                                                         | 说明                      |
| ------------------------------------------------------------ | ------------------------- |
| [值](https://docs.microsoft.com/zh-cn/visualstudio/designers/value-xattribute-dynamic-property?view=vs-2019) | 获取或设置 XML 属性的值。 |

##### [Value (XAttribute dynamic property)](https://docs.microsoft.com/en-us/visualstudio/designers/value-xattribute-dynamic-property?view=vs-2019)

获取或设置 XML 属性的值。

**语法**

```xaml
attrib.Value
```

**属性值/返回值**

包含此属性的值的 [String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)。

**异常**

| 异常类型                                                     | 条件                        |
| ------------------------------------------------------------ | --------------------------- |
| [ArgumentNullException](https://docs.microsoft.com/zh-cn/dotnet/api/system.argumentnullexception) | 设置时，`value` 为 `null`。 |

**备注**

此属性等效于 [Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute.value) 类的 [System.Xml.Linq.XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute) 属性，但此动态属性还支持更改通知。

#### [XElement class dynamic properties](https://docs.microsoft.com/en-us/visualstudio/designers/xelement-class-dynamic-properties?view=vs-2019)

本部分介绍 [System.Xml.Linq.XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 类的动态属性。

| 主题                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [特性](https://docs.microsoft.com/zh-cn/visualstudio/designers/attribute-xelement-dynamic-property?view=vs-2019) | 获取一个索引器，用于检索与指定扩展名对应的属性。             |
| [元素](https://docs.microsoft.com/zh-cn/visualstudio/designers/element-xelement-dynamic-property?view=vs-2019) | 获取一个索引器，用于检索与指定扩展名对应的子元素。           |
| [元素](https://docs.microsoft.com/zh-cn/visualstudio/designers/elements-xelement-dynamic-property?view=vs-2019) | 获取一个索引器，用于检索与指定扩展名匹配的当前元素的子元素。 |
| [子代](https://docs.microsoft.com/zh-cn/visualstudio/designers/descendants-xelement-dynamic-property?view=vs-2019) | 获取一个索引器，用于检索与指定扩展名匹配的当前元素的所有子代元素。 |
| [值](https://docs.microsoft.com/zh-cn/visualstudio/designers/value-xelement-dynamic-property?view=vs-2019) | 获取或设置一个元素的内容。                                   |
| [Xml](https://docs.microsoft.com/zh-cn/visualstudio/designers/xml-xelement-dynamic-property?view=vs-2019) | 获取元素的未格式化的 XML 表示形式。                          |

##### [Attribute (XElement dynamic property)](https://docs.microsoft.com/en-us/visualstudio/designers/attribute-xelement-dynamic-property?view=vs-2019)

获取一个索引器，该索引器用于检索与指定扩展名对应的属性实例。

**语法**

```xaml
elem.Attribute[{namespaceName}attribName]
```

**属性值/返回值**

一个类型为 `XAttribute Item(String expandedName)` 的索引器。 此索引器获取指定属性的扩展名，然后返回相应的 [XAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xattribute)，如果没有具有指定名称的属性，则返回 `null`。

**备注**

此属性等效于 [Attribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.attribute) 类的 [System.Xml.Linq.XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 方法。

##### [Element (XElement dynamic property)](https://docs.microsoft.com/en-us/visualstudio/designers/element-xelement-dynamic-property?view=vs-2019)

获取一个索引器，用于检索与指定扩展名对应的子元素实例。

**语法**

```xaml
elem.Element[{namespaceName}localName]
```

**属性值/返回值**

一个类型为 `XElement Item(String expandedName)` 的索引器。 此索引器获取扩展名参数并返回相应的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)，或者如果没有具有指定名称的元素，则返回 `null`。

**备注**

此属性等效于 [Element](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.element) 类的 [System.Xml.Linq.XContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer) 方法。

##### [Elements (XElement dynamic property)](https://docs.microsoft.com/en-us/visualstudio/designers/elements-xelement-dynamic-property?view=vs-2019)

获取一个索引器，用于检索与指定扩展名匹配的当前元素的子元素。

**语法**

```xaml
elem.Elements[{namespaceName}localName]
```

**属性值/返回值**

一个类型为 `IEnumerable<XElement> Item(String expandedName)` 的索引器。 此索引器获取所需子元素的扩展名，并返回 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable)`<`[XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)`>` 集合中的匹配子元素。

**备注**

此属性等效于 [System.Xml.Linq.XContainer.Elements(XName)](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.elements#System_Xml_Linq_XContainer_Elements_System_Xml_Linq_XName_) 类的 [XContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer) 方法。

返回集合中的元素按 XML 源文档顺序排列。

此属性使用延迟执行。

##### [Descendants (XElement dynamic property)](https://docs.microsoft.com/en-us/visualstudio/designers/descendants-xelement-dynamic-property?view=vs-2019)

获取一个索引器，用于检索与指定扩展名匹配的当前元素的所有子代元素。

**语法**

```xaml
elem.Descendants[{namespaceName}localName]
```

**属性值/返回值**

一个类型为 `IEnumerable<XElement> Item(String expandedName)` 的索引器。 此索引器获取指定子代元素的扩展名，并返回 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable)`<`[XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)`>` 集合中的匹配子元素。

**备注**

此属性等效于 [System.Xml.Linq.XContainer.Descendants(XName)](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.descendants#System_Xml_Linq_XContainer_Descendants_System_Xml_Linq_XName_) 类的 [XContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer) 方法。

返回集合中的元素按 XML 源文档顺序排列。

此属性使用延迟执行。

##### [Value (XElement dynamic property)](https://docs.microsoft.com/en-us/visualstudio/designers/value-xelement-dynamic-property?view=vs-2019)

获取或设置元素的内容。

**语法**

```xaml
elem.Value
```

**属性值/返回值**

一个 [String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)，表示元素的串联内容。

**备注**

此属性等效于 [Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.value) 类的 [System.Xml.Linq.XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 属性，但此动态属性还支持更改通知。

##### [Xml (XElement dynamic property)](https://docs.microsoft.com/en-us/visualstudio/designers/xml-xelement-dynamic-property?view=vs-2019)

获取元素的非格式化 XML 内容。

**语法**

```xaml
elem.Xml
```

**属性值/返回值**

表示元素的非格式化 XML 内容的 [String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)。

**备注**

此属性等效于 [ToString(SaveOptions)](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode.tostring#System_Xml_Linq_XNode_ToString_System_Xml_Linq_SaveOptions_) 类的 [System.Xml.Linq.XNode](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xnode) 方法，其 `SaveOptions` 参数设置为 [SaveOptions](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.saveoptions)。

#### [Example](https://docs.microsoft.com/en-us/visualstudio/designers/wpf-data-binding-using-linq-to-xml-example?view=vs-2019)

本节提供一个 Windows Presentation Foundation (WPF) 示例，该示例将用户界面组件绑定到嵌入式 XML 数据源。 此示例（以及包含此示例的 Visual Studio 项目）的名称是 *LinqToXmlDataBinding*。

| 主题                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [如何：生成并运行 LinqToXmlDataBinding 示例](https://docs.microsoft.com/zh-cn/visualstudio/designers/how-to-build-and-run-the-linqtoxmldatabinding-example?view=vs-2019) | 以分步说明的形式，介绍如何创建、填充和生成此示例的 Visual Studio 项目。 |
| [演练：LinqToXmlDataBinding 示例](https://docs.microsoft.com/zh-cn/visualstudio/designers/walkthrough-linqtoxmldatabinding-example?view=vs-2019) | 介绍该项目的主要源文件，并对在代码中将 LINQ to XML 用于数据绑定的方式进行说明。 |

##### [Build and run the LinqToXmlDataBinding example](https://docs.microsoft.com/en-us/visualstudio/designers/how-to-build-and-run-the-linqtoxmldatabinding-example?view=vs-2019)

本主题演示如何创建和生成 LinqToXmlDataBinding Visual Studio 项目以及如何运行生成的 LinqToXmlDataBinding Windows Presentation Foundation (WPF) 示例程序。

有关 Visual Studio 的详细信息，请参阅 [Visual Studio IDE 概述](https://docs.microsoft.com/zh-cn/visualstudio/get-started/visual-studio-ide?view=vs-2019)。

###### 创建和填充项目

**创建起始项目**

1. 启动 Visual Studio 并创建一个名为 LinqToXmlDataBinding 的 C# WPF 应用程序。 该项目必须使用 .NET Framework 3.5（或更高版本）。
2. 为以下 .NET 程序集添加项目引用（如果尚不存在）：
   - System.Data
   - System.Data.DataSetExtensions
   - System.Xml
   - System.Xml.Linq
3. 按 Ctrl+Shift+B 生成解决方案，然后按 F5 运行该解决方案。 该项目应正确编译而不出错，并作为一般 WPF 应用程序运行。

**对项目添加自定义代码**

1. 在解决方案资源管理器中，将源文件 Window1.xaml 重命名为 L2XDBForm.xaml。 依赖源文件 Window1.xaml.cs 应该会自动重命名为 L2XDBForm.xaml.cs。
2. 用 [L2DBForm.xaml 源代码](https://docs.microsoft.com/zh-cn/visualstudio/designers/l2dbform-xaml-source-code?view=vs-2019)主题中的代码节替换 L2XDBForm.xaml 文件中的源代码。 使用 XAML 源视图来处理此文件。
3. 同样，用 [L2DBForm.xaml.cs 源代码](https://docs.microsoft.com/zh-cn/visualstudio/designers/l2dbform-xaml-cs-source-code?view=vs-2019)中的代码替换 L2XDBForm.xaml.cs 中的源代码。
4. 在 App.xaml 文件中，用 `L2XDBForm.xaml` 替换 `Window1.xaml` 字符串的所有匹配项。
5. 按 Ctrl+Shift+B 生成解决方案。

###### 运行程序

LinqToXmlDataBinding 程序可以让用户查看和操作以嵌入式 XML 元素形式存储的书籍的列表。

**运行程序并查看书籍列表**

- 按 F5（开始调试）或 Ctrl+F5（启动而不调试）运行 LinqToXmlDataBinding。

  显示标题为“使用 LINQ to XML 的 WPF 数据绑定”的程序窗口。

- 请注意，UI 的顶部区域将显示表示书籍列表的原始 **XML**。 它使用 WPF [TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock) 控件来显示，该控件不启用通过鼠标或键盘交互。

- 标记为“书籍列表”的第二个垂直区域以排序的纯文本列表形式显示书籍。 它使用启用通过鼠标或键盘进行选择的 [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 控件。

**在列表中添加和删除书籍**

- 若要向列表中添加新书籍，请向最后一个区域”添加新书籍“的“ID”和“值” [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 控件中输入值，然后单击“添加书籍”按钮。 请注意，这会向书籍列表和 XML 列表中追加该书籍。 此程序不验证输入值。
- 若要从列表中删除现有书籍，请在“书籍列表”区域选择该书籍，然后单击“移除所选书籍”按钮。 请注意，这会从书籍列表和原始 XML 源列表中移除该书籍条目。

**编辑现有书籍条目**

1. 在第二个“书籍列表”区域中选择书籍条目。 其当前值应该显示在第三个区域“编辑所选书籍”中。
2. 使用键盘编辑值。 只要任一 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 控件失去焦点，更改就会自动传播到 XML 源和书籍列表。

##### [Walkthrough: LINQ to XML data binding](https://docs.microsoft.com/en-us/visualstudio/designers/walkthrough-linqtoxmldatabinding-example?view=vs-2019)

本演练介绍 LinqToXmlDataBinding 示例，解释它的两个主要源文件 L2DBForm.xaml 和 L2DBForm.xaml.cs 的一些更值得关注的内容。

###### 系统必备

在阅读本演练之前，强烈建议按照[如何：生成并运行 LinqToXmlDataBinding 示例](https://docs.microsoft.com/zh-cn/visualstudio/designers/how-to-build-and-run-the-linqtoxmldatabinding-example?view=vs-2019)中所述生成并运行 LinqToXmlDataBinding 程序。

###### 备注

LinqToXmlDataBinding 程序是一个 Windows Presentation Foundation (WPF) 应用程序，由 C# 和 XAML 源文件组成。 它包含定义书籍列表的嵌入式 XML 文档，允许用户查看、添加、删除和编辑这些项。 它由以下两个主要源文件组成：

- L2DBForm.xaml 包含主窗口的用户界面 (UI) 的 XAML 声明代码。 还包含为书籍列表定义数据提供程序和嵌入式 XML 文档的窗口资源部分。

- L2DBForm.xaml.cs 包含与用户界面关联的初始化和事件处理方法。

  主窗口分为以下四个垂直用户界面部分：

- “XML”显示嵌入式书籍列表的原始 XML 源。

- “Book List”（书籍列表）以标准文本形式显示书籍项，允许用户选择和删除各项。

- “Edit Selected Book”（编辑所选书籍）允许用户编辑与当前所选书籍项关联的值。

- “Add New Book”（添加新书籍）允许根据用户输入的值创建新书。

###### 本节内容

| 主题                                                         | 说明                                                   |
| ------------------------------------------------------------ | ------------------------------------------------------ |
| [L2DBForm.xaml 源代码](https://docs.microsoft.com/zh-cn/visualstudio/designers/l2dbform-xaml-source-code?view=vs-2019) | 包含文件 L2DBForm.xaml 中的 XAML 代码的内容和描述。    |
| [L2DBForm.xaml.cs 源代码](https://docs.microsoft.com/zh-cn/visualstudio/designers/l2dbform-xaml-cs-source-code?view=vs-2019) | 包含文件 L2DBForm.xaml.cs 中的 C# 源代码的内容和描述。 |

###### [L2DBForm.xaml source code](https://docs.microsoft.com/en-us/visualstudio/designers/l2dbform-xaml-source-code?view=vs-2019)

本主题包含并说明[使用 LINQ to XML 的 WPF 数据绑定示例](https://docs.microsoft.com/zh-cn/visualstudio/designers/wpf-data-binding-using-linq-to-xml-example?view=vs-2019)的 XAML 源文件 L2DBForm.xaml。

**总体 UI 结构**

和典型的 WPF 项目一样，此文件包含一个父元素，该元素是一个与 [Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window) 命名空间中的派生类 `L2XDBFrom` 相关联的 `LinqToXmlDataBinding` XML 元素。

客户端区域包含在具有浅蓝色背景的 [StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel) 中。 此面板包含四个 [DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel) UI 区域，由 [Separator](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.separator) 条分隔。**上一个主题** 的 [备注](https://docs.microsoft.com/zh-cn/visualstudio/designers/walkthrough-linqtoxmldatabinding-example?view=vs-2019)中说明了这些区域的用途。

每个区域都包含一个标识该区域的标签。 在前两个区域中，此标签通过使用 [LayoutTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.layouttransform)旋转 90 度。 该区域的其余部分包含对应于该区域用途的 UI 元素：文本块、文本框、按钮等。 有时使用子 [StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel) 来对齐这些子控件。

**窗口资源区域**

在第 9 行上的 `<Window.Resources>` 开始标记指示窗口资源区域的开始。 它在第 35 行上以结束标记结束。

`<ObjectDataProvider>` 标记跨越第 11 至第 25 行，声明一个名为 [ObjectDataProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.objectdataprovider)的 `LoadedBooks`，它使用 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 作为源。 此 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 是通过分析嵌入的 XML 文档（一个 `CDATA` 元素）来初始化的。 请注意，在声明嵌入的 XML 文档以及分析该文档时将保留空格。 之所以保留空格是因为用于显示原始 XML 的 [TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock) 控件没有专门的 XML 格式化功能。

最后，第 28 行至第 34 行定义一个名为 [DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate) 的 `BookTemplate` 。 此模板将用于显示“Book List”（书籍列表）UI 区域中的条目。 它使用数据绑定和 LINQ to XML 动态属性通过下面的赋值来检索书籍 ID 和书名：

```xaml
Text="{Binding Path=Attribute[id].Value}"Text="{Binding Path=Value}"
```

**数据绑定代码**

除 [DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate) 元素外，本文件中的许多其他位置也使用数据绑定。

在第 38 行的 `<StackPanel>` 开始标记中，此面板的 [DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext) 属性设置为 `LoadedBooks` 数据提供程序。

```xaml
DataContext="{Binding Source={StaticResource LoadedBooks}}
```

设置数据上下文使名为 `tbRawXml` 的 [TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)（第 46 行）能够通过绑定到此数据提供程序的 `Xml` 属性来显示原始 XML：

```xaml
Text="{Binding Path=Xml}"
```

从第 58 行至第 62 行，“Book List”（书籍列表） [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)**UI 区域中的** 将其显示项的模板设置为在窗口资源区域中定义的 `BookTemplate` ：

```xaml
ItemTemplate ="{StaticResource BookTemplate}"
```

然后，第 59 行至第 62 行将书籍的实际值绑定到此列表框：

```xaml
<ListBox.ItemsSource>
    <Binding Path="Elements[{http://www.mybooks.com}book]"/>
</ListBox.ItemsSource>
```

在第三个 UI 区域 **“Edit Selected Book”（编辑所选书籍）** 中，首先将父 [DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext) 的 [StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel) 绑定到 **“Book List”（书籍列表）** UI 区域中的当前所选项（第 82 行）：

```xaml
DataContext="{Binding ElementName=lbBooks, Path=SelectedItem}"
```

然后使用双向数据绑定，使书籍元素的当前值显示在此面板的两个文本框中并从中进行更新。 数据绑定到动态属性类似于在 `BookTemplate` 数据模板中使用数据绑定：

```xaml
Text="{Binding Path=Attribute[id].Value}"...Text="{Binding Path=Value}"
```

最后一个 UI 区域“Add New Book”（新增书籍）不在其 XAML 代码中使用数据绑定。 数据绑定在 L2DBForm.xaml.cs 文件的事件处理代码中。

**示例**

**说明**

建议您将下面的代码复制到代码编辑器（如 Visual Studio 中的 C# 源代码编辑器）中，以便更易于跟踪行号。

**代码**

```xml
<Window x:Class="LinqToXmlDataBinding.L2XDBForm"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    xmlns:system="clr-namespace:System;assembly=mscorlib"
    xmlns:xlinq="clr-namespace:System.Xml.Linq;assembly=System.Xml.Linq"
    xmlns:local="clr-namespace:LinqToXmlDataBinding"
    Title="WPF Data Binding using LINQ-to-XML" Height="665" Width="500" ResizeMode="NoResize">

    <Window.Resources>
        <!-- Books provider and inline data -->
        <ObjectDataProvider x:Key="LoadedBooks" ObjectType="{x:Type xlinq:XElement}" MethodName="Parse">
            <ObjectDataProvider.MethodParameters>
                <system:String xml:space="preserve">
<![CDATA[
<books xmlns="http://www.mybooks.com">
  <book id="0">book zero</book>
  <book id="1">book one</book>
  <book id="2">book two</book>
  <book id="3">book three</book>
</books>
]]>
                </system:String>
                <xlinq:LoadOptions>PreserveWhitespace</xlinq:LoadOptions>
            </ObjectDataProvider.MethodParameters>
        </ObjectDataProvider>

        <!-- Template for use in Books List listbox. -->
        <DataTemplate x:Key="BookTemplate">
            <StackPanel Orientation="Horizontal">
                <TextBlock Margin="3" Text="{Binding Path=Attribute[id].Value}"/>
                <TextBlock Margin="3" Text="-"/>
                <TextBlock Margin="3" Text="{Binding Path=Value}"/>
            </StackPanel>
        </DataTemplate>
    </Window.Resources>

    <!-- Main visual content container -->
    <StackPanel Background="lightblue" DataContext="{Binding Source={StaticResource LoadedBooks}}">
        <!-- Raw XML display section -->
        <DockPanel Margin="5">
            <Label  Background="Gray" FontSize="12" BorderBrush="Black" BorderThickness="1" FontWeight="Bold">XML
            <Label.LayoutTransform>
                <RotateTransform Angle="90"/>
            </Label.LayoutTransform>
            </Label>
            <TextBlock Name="tbRawXml" Height="200" Background="LightGray" Text="{Binding Path=Xml}" TextTrimming="CharacterEllipsis" />
        </DockPanel>

        <Separator Height="4" Margin="5" />

        <!-- List box to display all books section -->
        <DockPanel Margin="5">
            <Label  Background="Gray" FontSize="12" BorderBrush="Black" BorderThickness="1" FontWeight="Bold">Book List
                <Label.LayoutTransform>
                    <RotateTransform Angle="90"/>
                </Label.LayoutTransform>
            </Label>
            <ListBox Name="lbBooks" Height="200" Width="415" ItemTemplate ="{StaticResource BookTemplate}">
                <ListBox.ItemsSource>
                    <Binding Path="Elements[{http://www.mybooks.com}book]"/>
                </ListBox.ItemsSource>
            </ListBox>
            <Button Margin="5" DockPanel.Dock="Right" Height="30" Width ="130" Content="Remove Selected Book" Click="OnRemoveBook">
            <Button.LayoutTransform>
                <RotateTransform Angle="90"/>
            </Button.LayoutTransform>
            </Button>
        </DockPanel>

        <Separator Height="4" Margin="5" />

        <!-- Edit current selection section -->
        <DockPanel Margin="5">
            <TextBlock Margin="5" Height="30" Width="65" DockPanel.Dock="Right" Background="LightGray" TextWrapping="Wrap" TextAlignment="Center">
                    Changes are live!
                <TextBlock.LayoutTransform>
                    <RotateTransform Angle="90"/>
                </TextBlock.LayoutTransform>
            </TextBlock>
            <StackPanel>
                <Label Width="450" Background="Gray" FontSize="12" BorderBrush="Black" BorderThickness="1" HorizontalAlignment="Left" FontWeight="Bold">Edit Selected Book</Label>
                <StackPanel Margin="1" DataContext="{Binding ElementName=lbBooks, Path=SelectedItem}">
                    <StackPanel Orientation="Horizontal">
                        <Label Width="40">ID:</Label>
                        <TextBox Name="editAttributeTextBox" Width="410" Text="{Binding Path=Attribute[id].Value}">
                            <TextBox.ToolTip>
                                <TextBlock FontWeight="Bold" TextAlignment="Center">
                                    <Label>Edit the selected book ID and see it changed.</Label>
                                </TextBlock>
                            </TextBox.ToolTip>
                        </TextBox>
                    </StackPanel>
                    <StackPanel Orientation="Horizontal">
                        <Label Width="40">Value:</Label>
                        <TextBox Name="editValueTextBox" Width="410" Text="{Binding Path=Value}" Height="25">
                            <TextBox.ToolTip>
                                <TextBlock FontWeight="Bold" TextAlignment="Center">
                                    <Label>Edit the selected book Value and see it changed.</Label>
                                </TextBlock>
                            </TextBox.ToolTip>
                        </TextBox>
                    </StackPanel>
                </StackPanel>
            </StackPanel>
        </DockPanel>

        <Separator Height="4" Margin="5" />

        <!-- Add new book section -->
        <DockPanel Margin="5">
            <Button Margin="5" Height="30" DockPanel.Dock="Right" Click ="OnAddBook">Add Book
                <Button.LayoutTransform>
                    <RotateTransform Angle="90"/>
                </Button.LayoutTransform>
            </Button>
            <StackPanel>
                <Label Width="450" Background="Gray" FontSize="12" BorderBrush="Black" BorderThickness="1" HorizontalAlignment="Left" FontWeight="Bold">Add New Book</Label>
                <StackPanel Margin="1">
                    <StackPanel Orientation="Horizontal">
                        <Label Width="40">ID:</Label>
                        <TextBox Name="tbAddID" Width="410">
                            <TextBox.ToolTip>
                                <TextBlock FontWeight="Bold" TextAlignment="Center">
                                    <Label>Enter a book ID and Value pair, then click Add Book.</Label>
                                </TextBlock>
                            </TextBox.ToolTip>
                        </TextBox>
                    </StackPanel>
                    <StackPanel Orientation="Horizontal">
                        <Label Width="40">Value:</Label>
                        <TextBox Name="tbAddValue" Width="410" Height="25">
                            <TextBox.ToolTip>
                                <TextBlock FontWeight="UltraBold" TextAlignment="Center">
                                    <Label>Enter a book ID and Value pair, then click Add Book.</Label>
                                </TextBlock>
                            </TextBox.ToolTip>
                        </TextBox>
                    </StackPanel>
                </StackPanel>
            </StackPanel>
        </DockPanel>
    </StackPanel>
</Window>
```

**注释**

有关与 WPF UI 元素相关联的事件处理程序的 C# 源代码，请参阅 [L2DBForm.xaml.cs 源代码](https://docs.microsoft.com/zh-cn/visualstudio/designers/l2dbform-xaml-cs-source-code?view=vs-2019)。

###### [L2DBForm.xaml.cs source code](https://docs.microsoft.com/en-us/visualstudio/designers/l2dbform-xaml-cs-source-code?view=vs-2019)

本主题包含文件 L2DBForm.xaml.cs 中 C# 源代码的内容和说明。 本文件中包含的 L2XDBForm 分部类可分为三个逻辑区域：数据成员、`OnRemove` 和 `OnAddBook` 按钮单击事件处理程序。

**数据成员**

使用两个私有数据成员将此类与 L2DBForm.xaml 中使用的窗口资源相关联。

- 命名空间变量 `myBooks` 初始化为 `"http://www.mybooks.com"`。

- 用下面的行将构造函数中的成员 `bookList` 初始化为 L2DBForm.xaml 中的 CDATA 字符串：

  ```csharp
  bookList = (XElement)((ObjectDataProvider)Resources["LoadedBooks"]).Data;
  ```

**OnAddBook 事件处理程序**

此方法包含下面三个语句：

- 第一个条件语句用于输入验证。
- 第二个语句根据用户在“添加新书籍”用户界面 (UI) 区域中输入的字符串值新建 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)。
- 最后一个语句将此新书籍元素添加到 L2DBForm.xaml 中的数据提供程序。 因此，动态数据绑定将用此新项自动更新 UI；不需要用户提供额外的代码。

**OnRemove 事件处理程序**

由于两个原因，`OnRemove` 处理程序比 `OnAddBook` 处理程序更复杂。 首先，由于原始 XML 包含保留的空白，因此还必须与书籍条目一起移除匹配的换行符。 其次，出于方便，对所选项进行的选择会重置为列表中以前的选择。

但是，移除所选书籍项的核心工作仅通过两个语句完成：

- 首先，检索与列表框中当前所选项相关联的书籍元素：

  ```csharp
  XElement selBook = (XElement)lbBooks.SelectedItem;
  ```

- 然后，从数据提供程序中删除此元素：

  ```csharp
  selBook.Remove();
  ```

此外，动态数据绑定将确保自动更新程序的 UI。

**示例**

**代码**

```csharp
using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Input;
using System.Xml;
using System.Xml.Linq;

namespace LinqToXmlDataBinding {
    /// <summary>
    /// Interaction logic for L2XDBForm.xaml
    /// </summary>

    public partial class L2XDBForm : System.Windows.Window
    {
        XNamespace mybooks = "http://www.mybooks.com";
        XElement bookList;

        public L2XDBForm()
        {
            InitializeComponent();
            bookList = (XElement)((ObjectDataProvider)Resources["LoadedBooks"]).Data;
        }

        void OnRemoveBook(object sender, EventArgs e)
        {
            int index = lbBooks.SelectedIndex;
            if (index < 0) return;

            XElement selBook = (XElement)lbBooks.SelectedItem;
            //Get next node before removing element.
            XNode nextNode = selBook.NextNode;
            selBook.Remove();

            //Remove any matching newline node.
            if (nextNode != null && nextNode.ToString().Trim().Equals(""))
            { nextNode.Remove(); }

            //Set selected item.
            if (lbBooks.Items.Count > 0)
            {  lbBooks.SelectedItem = lbBooks.Items[index > 0 ? index - 1 : 0]; }
        }

        void OnAddBook(object sender, EventArgs e)
        {
            if (String.IsNullOrEmpty(tbAddID.Text) ||
                String.IsNullOrEmpty(tbAddValue.Text))
            {
                MessageBox.Show("Please supply both a Book ID and a Value!", "Entry Error!");
                return;
            }
            XElement newBook = new XElement(
                                mybooks + "book",
                                new XAttribute("id", tbAddID.Text),
                                tbAddValue.Text);
            bookList.Add("  ", newBook, "\r\n");
        }
    }
}
```

**注释**

有关这些处理程序的关联 XAML 源，请参阅 [L2DBForm.xaml 源代码](https://docs.microsoft.com/zh-cn/visualstudio/designers/l2dbform-xaml-source-code?view=vs-2019)。