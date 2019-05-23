# [Windows in WPF](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/windows-in-wpf-applications)

用户与通过 windows 应用程序进行交互。 窗口的基本目的是承载并显示内容。 内容，窗口承载取决于数据的类型，应用程序操作，其中包括媒体、 可扩展应用程序标记语言 (XAML) 页、 网页、 文档、 数据库表和记录和系统信息类型。

## 本节内容

[WPF 窗口概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/wpf-windows-overview)
[对话框概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/dialog-boxes-overview)
[帮助主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/window-management-how-to-topics)

## [WPF Windows Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/wpf-windows-overview)

用户与 Windows Presentation Foundation (WPF) 独立应用程序通过 windows 进行交互。 窗口的主要用途是托管使数据可视化并使用户能够与数据交互的内容。 独立WPF应用程序使用来提供自己的窗口[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)类。 本主题介绍[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)之前介绍的创建和管理独立应用程序中的 windows 基础知识。

> 浏览器承载WPF应用程序，包括XAML 浏览器应用程序 (XBAP)和松散可扩展应用程序标记语言 (XAML)页中，不提供它们自己的窗口。 相反，在 windows 中提供的托管Windows Internet Explorer。 请参阅[WPF XAML 浏览器应用程序概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/wpf-xaml-browser-applications-overview)。

#### 窗口类

下图展示了窗口的构成部分。

![窗口元素](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/windowoverviewfigure1.png)

窗口分为两个区域：非工作区和工作区。

*非工作区*的一个窗口由实现WPF和包含几个部分的一个窗口所共有的大多数窗口，其中包括：

- 边框。
- 标题栏。
- 图标。
- “最小化”、“最大化”和“还原”按钮。
- “关闭”按钮。
- “系统”菜单，其中包含允许用户最小化、最大化、还原、移动和关闭窗口以及重设窗口大小的菜单项。

*工作区*的一个窗口是窗口的非工作区中的区域和开发人员用于添加特定于应用程序的内容，如菜单栏、 工具栏和控件。

在中WPF，由封装窗口[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)类，用于执行以下操作：

- 显示窗口。
- 配置窗口的大小、位置和外观。
- 托管特定于应用程序的内容。
- 管理窗口的生存期。

#### 实现窗口

典型窗口的实现包括包括外观和行为，其中*外观*定义用户看到一个窗口的样子以及*行为*定义窗口函数在用户进行交互的方式使用它。 在中WPF，可以实现的外观和行为的窗口中使用代码或XAML标记。

一般情况下，但是，窗口的外观使用实现XAML标记，其行为实现和使用代码隐藏中，如下面的示例中所示。

```xaml
<Window 
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.MarkupAndCodeBehindWindow">
  
  <!-- Client area (for content) -->
  
</Window>
```

```csharp
using System.Windows;

namespace SDKSample
{
    public partial class MarkupAndCodeBehindWindow : Window
    {
        public MarkupAndCodeBehindWindow()
        {
            InitializeComponent();
        }
    }
}
```

若要启用XAML标记文件和代码隐藏文件协同工作，需要以下项：

- 在标记中，`Window`元素必须包括`x:Class`属性。 应用程序生成时，是否存在`x:Class`在标记文件会导致Microsoft Build Engine (MSBuild)来创建`partial`派生的类[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)并且具有指定的名称`x:Class`属性。 这需要添加XML命名空间声明XAML架构 ( `xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"` )。 生成`partial`类实现`InitializeComponent`方法，调用以注册事件并设置标记中实现的属性。
- 在代码隐藏中，类必须是`partial`具有相同名称指定的类`x:Class`属性在标记中，并且它必须派生自[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)。 这允许要与之关联的代码隐藏文件`partial`生成应用程序时，为标记文件生成的类 (请参阅[构建 WPF 应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/building-a-wpf-application-wpf))。
- 在代码隐藏[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)类必须实现构造函数调用`InitializeComponent`方法。 `InitializeComponent` 实现由标记文件中生成的`partial`类，以注册事件和设置在标记中定义的属性。

> 添加一个新[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)到你的项目通过使用Microsoft Visual Studio，则[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)通过使用标记和代码隐藏实现，并且包括必要的配置来创建作为标记和代码隐藏文件之间的关联此处所述。

使用此配置后，您可以集中精力定义中的窗口的外观XAML标记和在代码隐藏中实现其行为。 下面的示例演示一个按钮，在中实现的窗口XAML标记，并为按钮的事件处理程序[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件，在代码隐藏中实现。

```xaml
<Window 
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.MarkupAndCodeBehindWindow">
  <!-- Client area (for content) -->
  <Button Click="button_Click">Click This Button</Button>
</Window>
```

```csharp
using System.Windows;

namespace SDKSample
{
    public partial class MarkupAndCodeBehindWindow : Window
    {
        public MarkupAndCodeBehindWindow()
        {
            InitializeComponent();
        }

        void button_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("Button was clicked.");
        }
    }
}
```

#### 为 MSBuild 配置窗口定义

如何实现您的窗口确定如何将其配置为MSBuild。 使用同时定义窗口XAML标记和代码隐藏：

- XAML 标记文件配置为MSBuild`Page`项。
- 代码隐藏文件配置为MSBuild`Compile`项。

这如下所示MSBuild项目文件。

```xml
<Project ...  
                xmlns="http://schemas.microsoft.com/developer/msbuild/2003">  
    ...  
    <Page Include="MarkupAndCodeBehindWindow.xaml" />  
    <Compile Include=" MarkupAndCodeBehindWindow.xaml.cs" />  
    ...  
</Project>  
```

了解如何构建WPF应用程序，请参阅[构建 WPF 应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/building-a-wpf-application-wpf)。

#### 窗口生存期

与所有类一样，窗口也有生存期，开始于首次实例化窗口，在这之后将打开、激活、停用直至最终关闭窗口。

##### 打开窗口

若要打开窗口，首先要创建窗口实例，下面的示例演示此操作。

```xaml
<Application
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.App"
    Startup="app_Startup">
</Application>
```

```csharp
using System.Windows;
namespace SDKSample
{
    public partial class App : Application
    {
        void app_Startup(object sender, StartupEventArgs e)
        {
            // Create a window
            MarkupAndCodeBehindWindow window = new MarkupAndCodeBehindWindow();

            // Open a window
            window.Show();
        }
    }
}
```

在此示例中，`MarkupAndCodeBehindWindow`应用程序启动时，就会出现此实例化时[Startup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.startup)引发事件。

实例化窗口时，对它的引用自动添加到由一系列 windows[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)对象 (请参阅[Application.Windows](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.windows))。 此外，要实例化的第一个窗口，默认情况下，将由[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)作为应用程序主窗口 (请参阅[Application.MainWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.mainwindow))。

通过调用最后打开窗口[Show](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.show)方法; 在下图中显示结果。

![通过调用 Window.Show 打开的窗口](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/windowoverviewfigure8.png)

通过调用打开的窗口[Show](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.show)是无模式窗口中，这意味着在允许用户激活其他窗口在同一应用程序的模式下运行应用程序。

 备注

[ShowDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.showdialog) 调用以模式方式打开诸如对话框窗口。 请参阅[对话框概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/dialog-boxes-overview)有关详细信息。

当[Show](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.show)是调用，窗口先执行初始化工作显示它是为了建立基础结构，使其能够接收用户输入。 初始化窗口时，[SourceInitialized](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.sourceinitialized)引发事件并显示窗口。

作为快捷方式，[StartupUri](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.startupuri)可以设置以指定应用程序启动时自动打开的第一个窗口。

```xaml
<Application
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.App"
    StartupUri="PlainWindow.xaml" />
```

当应用程序启动时，指定的值的窗口[StartupUri](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.startupuri)打开无模式方式; 在内部，打开窗口时通过调用其[Show](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.show)方法。

##### 窗口所有权

通过使用打开的窗口[Show](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.show)方法不具有与创建它的窗口的隐式关系; 用户可以与这两个窗口独立于另一个，这意味着两个窗口中可以执行以下操作：

- 覆盖另 (除非其中一个窗口具有其[Topmost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.topmost)属性设置为`true`)。
- 在不影响另一个窗口的情况下最小化、最大化和还原。

某些窗口要求与打开它们的窗口保持某种关系。 例如，集成开发环境 (IDE)应用程序可能打开属性窗口和工具窗口的典型行为是覆盖创建它们的窗口。 此外，此类窗口应始终与创建它们的窗口一起关闭、最小化、最大化和还原。 这种关系可以建立一个窗口，从而*自己*另一个，并通过设置来实现[Owner](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.owner)的属性*所有者窗口*引用*所有者窗口*。 这在下面的示例中显示。

```csharp
// Create a window and make this window its owner
Window ownedWindow = new Window();
ownedWindow.Owner = this;
ownedWindow.Show();
```

建立所有权后：

- 拥有的窗口可以通过检查的值来引用它的所有者窗口及其[Owner](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.owner)属性。
- 所有者窗口可以发现它拥有通过检查的值的所有 windows 其[OwnedWindows](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.ownedwindows)属性。

##### 防止窗口激活

提供了的方案，windows 应激活时显示，例如 Internet messenger 风格应用程序的对话窗口或电子邮件应用程序的通知窗口。

如果你的应用程序具有一个窗口，其中显示时不应激活，则可以设置其[ShowActivated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.showactivated)属性设置为`false`然后才能调用[Show](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.show)第一次的方法。 结果是：

- 不会激活窗口。
- 窗口的[Activated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.activated)不会引发事件。
- 当前激活的窗口保持激活状态。

但是，只要用户通过单击工作区或非工作区激活了窗口，窗口就会变为激活状态。 这种情况下：

- 已激活窗口。
- 窗口的[Activated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.activated)引发事件。
- 停用之前激活的窗口。
- 在窗口[Deactivated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.deactivated)和[Activated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.activated)按预期方式响应用户操作，随后会引发事件。

##### 窗口激活

当首次打开一个窗口时，它将成为活动窗口 (除非它与所示[ShowActivated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.showactivated)设置为`false`)。 *活动窗口*是当前捕获用户输入，例如击键和鼠标单击的窗口。 当窗口成为活动窗口时，将引发[Activated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.activated)事件。

> 第一次打开一个窗口，当[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)并[ContentRendered](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.contentrendered)后才会引发事件[Activated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.activated)引发事件。 这一点，一个窗口，可有效地被视为时打开[ContentRendered](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.contentrendered)引发。

某个窗口成为活动窗口后，用户可以在同一应用程序内激活其他窗口，或者激活其他应用程序。 在这种情况，当前处于活动状态的窗口将变为停用并引发[Deactivated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.deactivated)事件。 同样，当用户选择当前已停用的窗口，窗口成为活动再次和[Activated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.activated)引发。

若要处理的一个常见原因[Activated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.activated)和[Deactivated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.deactivated)是启用和禁用只能运行一个窗口处于活动状态时的功能。 例如，一些窗口显示需要用户持续输入或关注的交互式内容，这些内容包括游戏和视频播放器。 下面的示例是简化的视频播放器，展示如何处理[Activated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.activated)和[Deactivated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.deactivated)来实现此行为。

```xaml
<Window
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.CustomMediaPlayerWindow"
    Activated="window_Activated"
    Deactivated="window_Deactivated">

    <!-- Media Player -->
    <MediaElement 
      Name="mediaElement" 
      Stretch="Fill" 
      LoadedBehavior="Manual" 
      Source="numbers.wmv" />

</Window>
```

```csharp
using System;
using System.Windows;

namespace SDKSample
{
    public partial class CustomMediaPlayerWindow : Window
    {
        public CustomMediaPlayerWindow()
        {
            InitializeComponent();
        }

        void window_Activated(object sender, EventArgs e)
        {
            // Recommence playing media if window is activated
            this.mediaElement.Play();
        }

        void window_Deactivated(object sender, EventArgs e)
        {
            // Pause playing if media is being played and window is deactivated
            this.mediaElement.Pause();
        }
    }
}
```

停用某个窗口后，其他类型的应用程序可能仍会在后台运行代码。 例如，在用户使用其他应用程序时，邮件客户端可能会继续轮询邮件服务器。 类似的应用程序在主窗口停用时，通常将提供不同或其他的行为。 对于邮件程序，这可能意味着将新邮件项添加到收件箱和将通知图标添加到系统任务栏。 在邮件窗口不活动状态，可以通过检查确定时，才需要显示通知图标[IsActive](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.isactive)属性。

如果后台任务完成后，窗口可能想要更迫切地通知用户，通过调用[Activate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.activate)方法。 如果在用户交互与另一个应用程序激活时[Activate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.activate)称为窗口的任务栏按钮会闪烁。 如果用户正与当前应用程序进行交互，则调用[Activate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.activate)将使窗口置于前台。

> 您可以处理应用程序作用域激活使用[Application.Activated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.activated)和[Application.Deactivated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.deactivated)事件。

##### 关闭窗口

窗口的生存期在用户关闭它时终止。 可以使用非工作区中的元素关闭窗口，这些元素包括：

- **关闭**项**系统**菜单。
- 按 ALT+F4。
- 按下**关闭**按钮。

可以向工作区提供其他关闭窗口的机制，较为常见的机制包括：

- **退出**中的项**文件**菜单通常用于主应用程序窗口。
- 一个**关闭**中的项**文件**菜单中的，通常出现在辅助应用程序窗口。
- 一个**取消**按钮，通常出现在模式对话框。
- 一个**关闭**按钮，通常出现在无模式对话框。

若要关闭窗口以响应其中一种自定义机制，您需要调用[Close](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.close)方法。 下面的示例实现的功能，通过选择关闭窗口**退出**上**文件**菜单。

```xaml
<Window 
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.WindowWithFileExit">
  
  <Menu>
    <MenuItem Header="_File">
      <MenuItem Header="E_xit" Click="fileExitMenuItem_Click" />
    </MenuItem>
  </Menu>
  
</Window>
```

```csharp
using System.Windows;

namespace SDKSample
{
    public partial class WindowWithFileExit : System.Windows.Window
    {
        public WindowWithFileExit()
        {
            InitializeComponent();
        }

        void fileExitMenuItem_Click(object sender, RoutedEventArgs e)
        {
            // Close this window
            this.Close();
        }
    }
}
```

当一个窗口关闭时，它会引发两个事件：[Closing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.closing)和[Closed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.closed)。

[Closing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.closing) 在窗口关闭，并提供了一种机制，通过哪个窗口可以阻止之前引发。 阻止窗口关闭的一个常见原因是窗口内容包含修改的数据。 在此情况下，[Closing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.closing)可以处理事件以确定是否为脏对象数据，如果是这样，询问用户是要继续关闭窗口而不保存数据还是取消关闭窗口。 下面的示例显示了处理的关键方面[Closing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.closing)。

```csharp
using System; // EventArgs
using System.ComponentModel; // CancelEventArgs
using System.Windows; // window

namespace CSharp
{
    public partial class DataWindow : Window
    {
        // Is data dirty
        bool isDataDirty = false;

        public DataWindow()
        {
            InitializeComponent();
        }

        void documentTextBox_TextChanged(object sender, EventArgs e)
        {
            this.isDataDirty = true;
        }

        void DataWindow_Closing(object sender, CancelEventArgs e)
        {
            MessageBox.Show("Closing called");

            // If data is dirty, notify user and ask for a response
            if (this.isDataDirty)
            {
                string msg = "Data is dirty. Close without saving?";
                MessageBoxResult result = 
                  MessageBox.Show(
                    msg, 
                    "Data App", 
                    MessageBoxButton.YesNo, 
                    MessageBoxImage.Warning);
                if (result == MessageBoxResult.No)
                {
                    // If user doesn't want to close, cancel closure
                    e.Cancel = true;
                }
            }
        }
    }
}
```

[Closing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.closing)事件处理程序传递[CancelEventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.canceleventargs)，它可以实现`Boolean`[Cancel](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.canceleventargs.cancel)属性设置为`true`可以阻止窗口关闭。

如果[Closing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.closing)未处理，或已处理但未取消，将关闭此窗口。 只需在窗口真正关闭之前，[Closed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.closed)引发。 此时，无法阻止窗口关闭。

> 可以将应用程序配置为关闭主应用程序窗口关闭时自动 (请参阅[MainWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.mainwindow)) 或最后一个窗口关闭。 有关详细信息，请参阅[ShutdownMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.shutdownmode)。

尽管可以通过在非客户端和客户端区域中提供的机制显式关闭窗口，窗口也可能隐式关闭应用程序的其他部分中的行为的结果或Windows，其中包括：

- 用户注销或关闭 Windows。
- 窗口的所有者关闭 (请参阅[Owner](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.owner))。
- 关闭主应用程序窗口和[ShutdownMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.shutdownmode)是[OnMainWindowClose](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shutdownmode#System_Windows_ShutdownMode_OnMainWindowClose)。
- 调用 [Shutdown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.shutdown)。

> 窗口在关闭后无法重新打开。

##### 窗口生存期事件

下图显示窗口生存期中的主体事件的顺序。

![窗口生存期](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/windowlifetimeevents.png)

下图显示一个窗口，其中会显示为未激活的生存期中的主体事件的序列 ([ShowActivated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.showactivated)设置为`false`显示窗口之前)。

![窗口生存期 (Window.ShowActivated = False)](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/windowlifetimenoact.png)



#### 窗口位置

当窗口打开时，它在相对于桌面的 x 和 y 维度中有一个位置。 可以通过检查来确定此位置[Left](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.left)和[Top](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.top)属性，分别。设置这些属性可以更改窗口的位置。

此外可以指定的初始位置[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)第一次出现时通过设置[WindowStartupLocation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.windowstartuplocation)具有以下项之一属性[WindowStartupLocation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.windowstartuplocation)枚举值：

- [CenterOwner](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.windowstartuplocation#System_Windows_WindowStartupLocation_CenterOwner)（默认值）
- [CenterScreen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.windowstartuplocation#System_Windows_WindowStartupLocation_CenterScreen)
- [Manual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.windowstartuplocation#System_Windows_WindowStartupLocation_Manual)

如果启动位置指定为[Manual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.windowstartuplocation#System_Windows_WindowStartupLocation_Manual)，并[Left](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.left)并[Top](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.top)属性未设置，[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)将要求的位置的 Windows 中显示。

##### 最顶层窗口和 Z 顺序

除了有 x 和 y 位置外，窗口还在 z 维度中有一个位置，该位置确定窗口相对于其他窗口的垂直位置。 它称为窗口的 z 顺序，并且有两种类型：正常 z 顺序和最顶层 z 顺序。 在窗口的位置*正常 z 顺序*由或不是当前处于活动状态。 默认情况下，窗口位于正常 z 顺序中。 在窗口的位置*最顶层 z 顺序*也由或不是当前处于活动状态。 此外，最顶层 z 顺序中的窗口始终位于正常 z 顺序中的窗口之上。 一个窗口位于最顶层 z 顺序通过设置其[Topmost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.topmost)属性设置为`true`。

```xaml
<Window 
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    Topmost="True">
</Window>
```

在每个 z 顺序中，当前的活动窗口显示在同一 z 顺序中所有其他窗口之上。

#### 窗口大小

除了拥有桌面位置，窗口具有由多个属性，包括各种宽度和高度属性的大小和[SizeToContent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.sizetocontent)。

[MinWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.minwidth)[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)，和[MaxWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.maxwidth)用于管理的一个窗口可以在其生存期内，并且在下面的示例所示配置的宽度范围。

```xaml
<Window 
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    MinWidth="300" Width="400" MaxWidth="500">
</Window>
```

窗口高度由[MinHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.minheight)， [Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)，和[MaxHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.maxheight)，配置方式如以下示例所示。

```xaml
<Window 
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    MinHeight="300" Height="400" MaxHeight="500">
</Window>
```

由于各种宽度值和高度值各自指定了一个范围，所以大小可调整大小的窗口的宽度和高度可以是相应维度中指定范围内的任何值。 若要检测的当前宽度和高度，检查[ActualWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.actualwidth)和[ActualHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.actualheight)分别。

如果想要的宽度和窗口的高度以适应窗口大小的大小的内容，则可以使用[SizeToContent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.sizetocontent)属性，它具有以下值：

- [Manual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.sizetocontent#System_Windows_SizeToContent_Manual)。 不起作用（默认值）。
- [Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.sizetocontent#System_Windows_SizeToContent_Width)。 适应内容宽度，具有相同的效果与设置两者[MinWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.minwidth)和[MaxWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.maxwidth)到内容的宽度。
- [Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.sizetocontent#System_Windows_SizeToContent_Height)。 适应内容高度，具有相同的效果与设置两者[MinHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.minheight)和[MaxHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.maxheight)到内容的高度。
- [WidthAndHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.sizetocontent#System_Windows_SizeToContent_WidthAndHeight)。 适应内容宽度和高度，具有相同的效果与设置这两[MinHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.minheight)并[MaxHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.maxheight)的内容和设置这两个高度[MinWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.minwidth)和[MaxWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.maxwidth)到内容的宽度。

以下示例显示了一个窗口，它在第一次显示时即自动调整垂直方向和水平方向上的大小以适应内容。

```xaml
<Window 
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
    SizeToContent="WidthAndHeight">
</Window>
```

下面的示例演示如何设置[SizeToContent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.sizetocontent)代码以指定如何调整窗口大小以适应其内容中的属性。

```csharp
// Manually alter window height and width
this.SizeToContent = SizeToContent.Manual;

// Automatically resize width relative to content
this.SizeToContent = SizeToContent.Width;

// Automatically resize height relative to content
this.SizeToContent = SizeToContent.Height;

// Automatically resize height and width relative to content
this.SizeToContent = SizeToContent.WidthAndHeight;
```

#### 大小调整属性的优先级顺序

从根本上说，窗口的各种大小属性可以结合使用，以定义可调整大小的窗口的宽度和高度范围。 若要确保保持有效的范围，[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)大小属性使用以下优先级顺序的值的计算结果。

**对于高度属性：**

1. [FrameworkElement.MinHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.minheight) >
2. [FrameworkElement.MaxHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.maxheight) >
3. [SizeToContent.Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.sizetocontent#System_Windows_SizeToContent_Height)/[SizeToContent.WidthAndHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.sizetocontent#System_Windows_SizeToContent_WidthAndHeight) >
4. [FrameworkElement.Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)

**对于宽度属性：**

1. [FrameworkElement.MinWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.minwidth) >
2. [FrameworkElement.MaxWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.maxwidth) >
3. [SizeToContent.Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.sizetocontent#System_Windows_SizeToContent_Width)/[SizeToContent.WidthAndHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.sizetocontent#System_Windows_SizeToContent_WidthAndHeight) >
4. [FrameworkElement.Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)

最大化，后者使用进行管理时，优先顺序还可以确定窗口大小[WindowState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.windowstate)属性。

#### 窗口状态

可调整大小的窗口在生存期中拥有三种状态：正常、最小化和最大化。 使用窗口*正常*状态是一个窗口的默认状态。 这种状态下的窗口允许用户使用重设大小手柄或边框移动窗口和重设其大小（前提是大小可以重设）。

使用窗口*最小化*状态折叠到其任务栏按钮，如果[ShowInTaskbar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.showintaskbar)设置为`true`; 否则为它大大减少到最小的可能大小，它可以是并将自己重新定位在桌面的左下角。 虽然不在任务栏显示的最小化窗口可以在桌面上四处拖动，但这两种类型的最小化窗口都不可以使用边框或重设大小手柄重设窗口大小。

使用窗口*最大化*状态扩展可以只能将一样大的最大大小为其[MaxWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.maxwidth)， [MaxHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.maxheight)，和[SizeToContent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.sizetocontent)属性规定。与最小化窗口一样，最大化窗口无法使用重设大小手柄或通过拖动边框来重设大小。

> 值[Top](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.top)， [Left](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.left)， [Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)，和[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)属性窗口的当前最大化或最小化窗口时，即使始终表示正常状态的值。

可以通过设置配置窗口的状态及其[WindowState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.windowstate)属性，它可以具有下列任一[WindowState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.windowstate)枚举值：

- [Normal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.windowstate#System_Windows_WindowState_Normal)（默认值）
- [Maximized](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.windowstate#System_Windows_WindowState_Maximized)
- [Minimized](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.windowstate#System_Windows_WindowState_Minimized)

以下示例显示如何创建在打开时最大化显示的窗口。

```xaml
<Window 
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    WindowState="Maximized">
</Window>
```

一般情况下，应设置[WindowState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.windowstate)配置窗口的初始状态。 显示可调整大小的窗口后，用户可以按窗口标题栏上的“最小化”、“最大化”和“还原”按钮来更改窗口状态。

#### 窗口外观

通过将特定于窗口的内容（例如按钮、标签和文本框）添加到窗口的工作区可以更改它的外观。 若要配置非工作区中，[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)提供了几个属性，其中包括[Icon](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.icon)若要设置窗口的图标和[Title](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.title)设置其标题。

还可以通过配置窗口的重设大小模式、窗口样式，以及窗口是否显示为桌面任务栏中的按钮，更改非工作区边框的外观和行为。

##### 重设大小模式

具体取决于[WindowStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.windowstyle)属性，可以控制如何 （以及是否） 用户可以调整窗口的大小。 窗口样式的选择会影响用户可以通过拖动鼠标，其边框是否调整窗口是否**最小化**，**最大化**，并**重设大小**按钮在非客户端区域中，会出现并显示时，是否启用它们。

你可以配置如何调整窗口大小通过设置其[ResizeMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.resizemode)属性，它可以是以下之一[ResizeMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resizemode)枚举值：

- [NoResize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resizemode#System_Windows_ResizeMode_NoResize)
- [CanMinimize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resizemode#System_Windows_ResizeMode_CanMinimize)
- [CanResize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resizemode#System_Windows_ResizeMode_CanResize)（默认值）
- [CanResizeWithGrip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resizemode#System_Windows_ResizeMode_CanResizeWithGrip)

如同[WindowStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.windowstyle)，窗口的大小调整模式是不太可能更改在其生存期内，这意味着，您将很可能设置从XAML标记。

```xaml
<Window 
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    ResizeMode="CanResizeWithGrip">
</Window>
```

请注意，可以检测是否已最大化窗口，最小化，或通过检查还原[WindowState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.windowstate)属性。

##### 窗口样式

从窗口非工作区公开的边框适用于大多数应用程序。 但是，有时候会需要不同类型的边框，或者根本不需要边框，具体取决于窗口类型。

若要控制窗口的边框类型获取，则设置其[WindowStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.windowstyle)属性的下列值之一[WindowStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.windowstyle)枚举：

- [None](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.windowstyle#System_Windows_WindowStyle_None)
- [SingleBorderWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.windowstyle#System_Windows_WindowStyle_SingleBorderWindow)（默认值）
- [ThreeDBorderWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.windowstyle#System_Windows_WindowStyle_ThreeDBorderWindow)
- [ToolWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.windowstyle#System_Windows_WindowStyle_ToolWindow)

下图显示了这些窗口样式的效果。

![窗口样式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/windowoverviewfigure6.png)

可以设置[WindowStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.windowstyle)使用XAML标记或代码; 因为它是不太可能更改窗口的生存期内，你将很可能将其配置使用XAML标记。

```xaml
<Window 
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    WindowStyle="ToolWindow">
</Window>
```

###### 非矩形窗口样式

还有一些情况下的边框样式的[WindowStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.windowstyle)使你能够在不足够。 例如，你可能想要创建具有非矩形边框的应用程序，如Microsoft Windows Media Player使用。

下图中显示的对话气泡框就是一个例子。

![非矩形窗口](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/nonrectangularwindowfigure.png)

可以通过设置创建此类型的窗口[WindowStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.windowstyle)属性设置为[None](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.windowstyle#System_Windows_WindowStyle_None)，并通过使用特殊支持[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)对透明度。

```xaml
<Window 
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    WindowStyle="None"
    AllowsTransparency="True"
    Background="Transparent">
</Window>
```

多个值组合起来可以指示窗口呈现完全透明的效果。 在这种状态下，无法使用窗口的非工作区修饰（“关闭”菜单，“最小化”、“最大化”和“还原”按钮等）。 因此，需要提供自己的修饰。

##### 任务栏显示

窗口的默认外观包括任务栏按钮，如下图中所示。

![包括任务栏按钮的窗口](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/windowoverviewfigure7.png)

某些类型的窗口没有任务栏按钮，如消息框和对话框 (请参阅[对话框概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/dialog-boxes-overview))。 您可以控制是否通过设置显示窗口任务栏按钮[ShowInTaskbar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.showintaskbar)属性 (`true`默认情况下)。

```xaml
<Window 
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    ShowInTaskbar="False">
</Window>
```

#### 安全注意事项

[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window) 需要`UnmanagedCode`用于实例化的安全权限。 对于从本地计算机安装并启动的应用程序，此权限在授予应用程序的权限集中。

但是，此权限授予启动从 Internet 或本地 intranet 区域中使用的应用程序的权限集外ClickOnce。 因此，用户将收到ClickOnce安全警告，需要提升的权限集为完全信任的应用程序。

此外，XBAP默认情况下不能显示窗口或对话框。 独立应用程序安全注意事项的讨论，请参阅[WPF 安全策略-平台安全性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/wpf-security-strategy-platform-security)。

#### 其他类型的窗口

[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow) 是一个旨在托管可导航内容的窗口。 有关详细信息，请参阅[导航概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-overview))。

对话框是通常用来收集用户信息以完成某项功能的窗口。 例如，当用户想要打开文件时，**打开文件**对话框通常显示应用程序以从用户获取的文件的名称。 有关详细信息，请参阅[对话框概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/dialog-boxes-overview)。

## [Dialog Boxes Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/dialog-boxes-overview)

独立应用程序通常会在主窗口中同时显示应用程序对其进行操作和公开的功能来处理通过该数据的主数据用户界面 (UI)等机制，菜单栏、 工具栏和状态栏。 重要的应用程序可能还会显示其他窗口来执行以下操作：

- 向用户显示特定信息。
- 从用户处收集信息。
- 同时显示并收集信息。

这些类型的窗口被称为*对话框*，并有两种类型： 模式和无模式。

一个*模式*函数需要来自用户继续的其他数据时，对话框将显示函数。 由于函数依赖于模式对话框收集数据，模式对话框还会在其保持打开状态时防止用户激活应用程序中的其他窗口。 在大多数情况下，模式对话框允许用户在通过按完成与模式对话框时发出信号**确定**或**取消**按钮。 按下**确定**按钮表示用户已输入数据，希望函数继续处理该数据。 按下**取消**按钮表示用户想要停止从完全执行函数。 最常见的模式对话框示例显示为可以打开、保存并打印数据。

一个*无模式*对话框中，但是，不会阻止用户激活其他窗口打开时。 例如，如果用户想要在某个文档中查找特定字的出现次数，主窗口通常会打开一个对话框，询问用户要查找的字是什么。 查找字并不会防止用户编辑文档，因此对话框无需为模式对话框。 无模式对话框至少提供**关闭**按钮以关闭对话框，并可能会提供其他按钮来执行特定的功能，如**查找下一个**按钮以查找下一个词与字搜索查找条件匹配。

Windows Presentation Foundation (WPF)，可创建多种类型的对话框，包括消息框、 通用对话框和自定义对话框。 本主题介绍了每一个，并[对话框示例](https://go.microsoft.com/fwlink/?LinkID=159984)提供匹配的示例。

### 消息框

一个*消息框*是可以用于显示文本信息并允许用户使用按钮做出决定的对话框。 下图显示的消息框显示文本信息、提出问题并向用户提供了三个按钮来回答问题。

![“字处理器”对话框](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/dialogboxesoverviewfigure1.png)

若要创建一个消息框，您可以使用[MessageBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.messagebox)类。 [MessageBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.messagebox) 您可以配置消息框文本、 标题、 图标和按钮，使用如下所示的代码。

```csharp
// Configure the message box to be displayed
string messageBoxText = "Do you want to save changes?";
string caption = "Word Processor";
MessageBoxButton button = MessageBoxButton.YesNoCancel;
MessageBoxImage icon = MessageBoxImage.Warning;
```

若要显示一个消息框，则调用`static`[Show](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.messagebox.show)方法，如下面的代码中所示。

```csharp
// Display message box
MessageBox.Show(messageBoxText, caption, button, icon);
```

当显示消息框的代码需要检测并处理用户决定（按下了哪个按钮）时，该代码可以检查消息框的结果，如以下代码中所示。

```csharp
// Display message box
MessageBoxResult result = MessageBox.Show(messageBoxText, caption, button, icon);

// Process message box results
switch (result)
{
    case MessageBoxResult.Yes:
        // User pressed Yes button
        // ...
        break;
    case MessageBoxResult.No:
        // User pressed No button
        // ...
        break;
    case MessageBoxResult.Cancel:
        // User pressed Cancel button
        // ...
        break;
}
```

使用消息框的详细信息，请参阅[MessageBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.messagebox)， [MessageBox 示例](https://go.microsoft.com/fwlink/?LinkID=160023)，和[对话框示例](https://go.microsoft.com/fwlink/?LinkID=159984)。

尽管[MessageBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.messagebox)可能会提供简单的对话框用户体验，使用的优点[MessageBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.messagebox)是唯一的部分信任安全沙箱内运行的应用程序均可显示的窗口类型 (请参阅[安全](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/security-wpf))，如XAML 浏览器应用程序 (XBAP)。

大多数对话框显示和收集比消息框结果更复杂的数据，包括文本、选项（复选框）、互斥选项（单选按钮）和列表选项（列表框、组合框、下拉列表框）。 对于这些数据，Windows Presentation Foundation (WPF) 提供了几个通用对话框，并允许您创建您自己的对话框，不过使用仅限于以完全信任级别运行的应用程序。

### 通用对话框

Windows 实现所有应用程序（包括用于打开文件、保存文件和打印的对话框）共用的各种可重用的对话框。 这些对话框由操作系统实现，因此可以在运行于该操作系统上的所有应用程序之间共享，这对用户体验的一致性很有帮助；当用户熟悉一个应用程序中操作系统所提供的对话框时，他们就无需再去了解如何在其他应用程序中使用该对话框。 因为这些对话框可供所有应用程序，因为它们可帮助提供一致的用户体验，因此它们被称为*公共对话框*。

Windows Presentation Foundation (WPF) 封装用于打开文件、 保存文件，并打印通用对话框和将其公开为托管的类以便您可以在独立应用程序中使用。 本主题提供每个通用对话框的简要概述。

##### 打开文件对话框

如下图中所示的打开文件对话框由文件打开功能用于检索要打开文件的名称。

![打开对话框](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/dialogboxesoverviewfigure2.png)

作为实现常见的打开文件对话框[OpenFileDialog](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.win32.openfiledialog)类，它位于[Microsoft.Win32](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.win32)命名空间。 以下代码显示了如何创建、配置和显示保存文件对话框以及如何处理结果。

```csharp
// Configure open file dialog box
Microsoft.Win32.OpenFileDialog dlg = new Microsoft.Win32.OpenFileDialog();
dlg.FileName = "Document"; // Default file name
dlg.DefaultExt = ".txt"; // Default file extension
dlg.Filter = "Text documents (.txt)|*.txt"; // Filter files by extension

// Show open file dialog box
Nullable<bool> result = dlg.ShowDialog();

// Process open file dialog box results
if (result == true)
{
    // Open document
    string filename = dlg.FileName;
}
```

打开文件对话框的详细信息，请参阅[Microsoft.Win32.OpenFileDialog](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.win32.openfiledialog)。

> [OpenFileDialog](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.win32.openfiledialog) 可用于安全地检索文件名的部分信任环境中运行的应用程序 (请参阅[安全](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/security-wpf))。

##### 保存文件对话框

如下图中所示的保存文件对话框由文件保存功能用以检索要保存的文件的名称。

![另存为对话框](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/dialogboxesoverviewfigure3.png)

作为实现常见的保存文件对话框[SaveFileDialog](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.win32.savefiledialog)类，并位于[Microsoft.Win32](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.win32)命名空间。 以下代码显示了如何创建、配置和显示保存文件对话框以及如何处理结果。

```csharp
// Configure save file dialog box
Microsoft.Win32.SaveFileDialog dlg = new Microsoft.Win32.SaveFileDialog();
dlg.FileName = "Document"; // Default file name
dlg.DefaultExt = ".txt"; // Default file extension
dlg.Filter = "Text documents (.txt)|*.txt"; // Filter files by extension

// Show save file dialog box
Nullable<bool> result = dlg.ShowDialog();

// Process save file dialog box results
if (result == true)
{
    // Save document
    string filename = dlg.FileName;
}
```

有关详细信息保存文件对话框中，请参阅[Microsoft.Win32.SaveFileDialog](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.win32.savefiledialog)。

#####  打印对话框

如下图中所示的打印对话框由打印功能用以选择和配置用户想要将数据打印到的打印机。

![打印对话框](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/dialogboxesoverviewfigure4.png)

作为实现通用打印对话框[PrintDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.printdialog)类，并位于[System.Windows.Controls](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls)命名空间。 以下代码显示了如何创建、配置和显示打印对话框。

```csharp
// Configure printer dialog box
System.Windows.Controls.PrintDialog dlg = new System.Windows.Controls.PrintDialog();
dlg.PageRangeSelection = PageRangeSelection.AllPages;
dlg.UserPageRangeEnabled = true;

// Show save file dialog box
Nullable<bool> result = dlg.ShowDialog();

// Process save file dialog box results
if (result == true)
{
    // Print document
}
```

打印对话框的详细信息，请参阅[System.Windows.Controls.PrintDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.printdialog)。 有关中的打印功能的详细讨论WPF，请参阅[打印概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/printing-overview)。

### 自定义对话框

尽管通用对话框很有用并应尽可能使用，但它们并不支持特定于域的对话框的要求。 在这些情况下，就需要创建自己的对话框。 如我们所见，对话框是具有特殊行为的窗口。 [Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window) 实现那些行为，因此，使用[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)创建自定义模式和无模式对话框。

##### 创建模式自定义对话框

本主题演示如何使用[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)若要创建典型模式对话框实现，使用`Margins`对话框中的作为示例 (请参阅[对话框示例](https://go.microsoft.com/fwlink/?LinkID=159984))。 `Margins`对话框显示下图中。

![边距对话框](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/dialogboxesoverviewfigure5.png)

##### 配置模式对话框

典型对话框的用户界面包括以下内容：

- 收集所需数据要求的各种控件。
- 显示**确定**按钮用户单击以关闭对话框，返回到函数，并继续处理。
- 显示**取消**按钮，用户单击关闭对话框并停止进一步处理功能。
- 显示**关闭**标题栏中的按钮。
- 显示一个图标。
- 显示**最小化**，**最大化**，并**还原**按钮。
- 显示**系统**菜单以最小化、 最大化、 还原和关闭该对话框。
- 在打开对话框的窗口上方和中心打开。
- 对话框应尽可能可以调整大小（以防对话框过小）并为用户提供合适的默认尺寸，需要分别设置默认和最小尺寸。
- 按 ESC 键应该配置导致的键盘快捷方式**取消**按钮按下。 这通过设置来实现[IsCancel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button.iscancel)的属性**取消**按钮切换为`true`。
- 按 ENTER （或 RETURN） 键应该配置导致的键盘快捷方式**确定**按钮按下。 这通过设置来实现[IsDefault](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button.isdefault)的属性**确定**按钮`true`。

以下代码演示了这种配置。

```xaml
<Window 
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.MarginsDialogBox"
    xmlns:local="clr-namespace:SDKSample"
    Title="Margins"
    Height="190"
    Width="300"
    MinHeight="10"
    MinWidth="300"
    ResizeMode="CanResizeWithGrip"
    ShowInTaskbar="False"
    WindowStartupLocation="CenterOwner" 
    FocusManager.FocusedElement="{Binding ElementName=leftMarginTextBox}">

  <Grid>
```

```xaml
    <!-- Accept or Cancel -->
    <StackPanel Grid.Column="0" Grid.ColumnSpan="2" Grid.Row="4">
      <Button Name="okButton" Click="okButton_Click" IsDefault="True">OK</Button>
      <Button Name="cancelButton" IsCancel="True">Cancel</Button>
    </StackPanel>

  </Grid >

</Window>
```

```csharp
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

namespace SDKSample
{
    public partial class MarginsDialogBox : Window
    {
        public MarginsDialogBox()
        {
            InitializeComponent();
        }
```

```csharp
    }
}
```

对话框用户体验还扩展到打开对话框的窗口菜单栏。 当菜单项运行需要用户通过对话框交互才能继续运行的函数时，函数的菜单项标题上会有一个省略号，如此处所示。

```xaml
<!--Main Window-->
```

```xaml
<MenuItem Name="formatMarginsMenuItem" Header="_Margins..." Click="formatMarginsMenuItem_Click" />
```

当菜单项运行的函数显示无需用户交互的对话框（如“关于”对话框）时，则不需要省略号。

##### 打开模式对话框

对话框通常显示为用户选择菜单项来执行特定于域的函数的结果，比如在字处理器中设置文档边距。 将窗口显示为对话框类似于显示普通窗口，只是它需要其他特定于对话框的配置。 以下代码中显示了实例化、配置和打开对话框的整个过程。

```csharp
using System;
using System.ComponentModel;
using System.Windows;
using System.Windows.Controls;
using Microsoft.Win32;

namespace SDKSample
{
    public partial class MainWindow : Window
    {
    	void formatMarginsMenuItem_Click(object sender, RoutedEventArgs e)
		{
    		// Instantiate the dialog box
    		MarginsDialogBox dlg = new MarginsDialogBox();

    		// Configure the dialog box
    		dlg.Owner = this;
    		dlg.DocumentMargin = this.documentTextBox.Margin;

    		// Open the dialog box modally 
    		dlg.ShowDialog();
    	}
    }
        
}
```
此处代码将默认信息（当前边距）传递给对话框。 它还设置[Window.Owner](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.owner)具有对显示的对话框窗口的引用的属性。 一般情况下，应始终设置对话框中的所有者才能提供窗口状态相关的行为所共有的所有对话框 (请参阅[WPF Windows 概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/wpf-windows-overview)有关详细信息)。

 备注必须提供所有者以支持用户界面 (UI)自动化对话框 (请参阅[UI 自动化概述](https://docs.microsoft.com/zh-cn/dotnet/framework/ui-automation/ui-automation-overview))。

配置对话框的后，会有模式地显示通过调用[ShowDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.showdialog)方法。

##### 验证用户提供的数据

当打开对话框并且用户提供所需数据时，对话框出于以下原因负责确保提供的数据有效：

- 从安全角度，应该验证所有输入。
- 从特定于域的角度，数据验证可以防止代码处理错误数据，这可能引发异常。
- 从用户体验角度，对话框可以帮助用户显示他们输入的哪些数据无效。
- 从性能角度，多层应用程序中的数据验证可以减少客户端和应用程序层之间的往返次数，尤其当应用程序由 Web 服务或基于服务器的数据库构成时。

若要验证中的绑定的控件WPF，您需要定义验证规则并将其与绑定相关联。 验证规则是派生的自定义类[ValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule)。 下面的示例演示的验证规则， `MarginValidationRule`，哪些会检查绑定的值是否[Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double)和指定范围内。

```csharp
using System.Globalization;
using System.Windows.Controls;

namespace SDKSample
{
    public class MarginValidationRule : ValidationRule
    {
        double minMargin;
        double maxMargin;

        public double MinMargin
        {
            get { return this.minMargin; }
            set { this.minMargin = value; }
        }

        public double MaxMargin
        {
            get { return this.maxMargin; }
            set { this.maxMargin = value; }
        }

        public override ValidationResult Validate(object value, CultureInfo cultureInfo)
        {
            double margin;

            // Is a number?
            if (!double.TryParse((string)value, out margin))
            {
                return new ValidationResult(false, "Not a number.");
            }

            // Is in range?
            if ((margin < this.minMargin) || (margin > this.maxMargin))
            {
                string msg = string.Format("Margin must be between {0} and {1}.", this.minMargin, this.maxMargin);
                return new ValidationResult(false, msg);
            }

            // Number is valid
            return new ValidationResult(true, null);
        }
    }
}
```

在此代码中，验证规则的验证逻辑实现通过重写[Validate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule.validate)方法，用于验证数据并返回相应[ValidationResult](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationresult)。

要将验证规则与绑定控件进行关联，可以使用以下标记。

```xaml
<Window 
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.MarginsDialogBox"
    xmlns:local="clr-namespace:SDKSample"
    Title="Margins"
    Height="190"
    Width="300"
    MinHeight="10"
    MinWidth="300"
    ResizeMode="CanResizeWithGrip"
    ShowInTaskbar="False"
    WindowStartupLocation="CenterOwner" 
    FocusManager.FocusedElement="{Binding ElementName=leftMarginTextBox}">

  <Grid>
    
```

```xaml
<Label Grid.Column="0" Grid.Row="0">Left Margin:</Label>
<TextBox Name="leftMarginTextBox" Grid.Column="1" Grid.Row="0">
  <TextBox.Text>
    <Binding Path="Left" UpdateSourceTrigger="PropertyChanged">
      <Binding.ValidationRules>
        <local:MarginValidationRule MinMargin="0" MaxMargin="10" />
      </Binding.ValidationRules>
    </Binding>
  </TextBox.Text>
</TextBox>
```

```xaml
</Window>
```

一旦验证规则已关联，WPF会自动将其应用时数据输入到绑定控件。 当控件包含无效数据，WPF下图中所示，将显示在无效控件四周的红色边框。

![无效左边距](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/dialogboxesoverviewfigure7.png)

WPF 不会在用户输入有效数据之前限制其对无效控件的访问。 这对于对话框来说很好，无论数据是否有效用户都应该可以自由导航到对话框中的控件。 但是，这意味着用户可以输入无效数据并按**确定**按钮。 出于此原因，代码还需要验证所有控件在对话框中，当**确定**通过处理按下按钮[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件。

```csharp
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

namespace SDKSample
{
    public partial class MarginsDialogBox : Window
    {
```

```csharp
void okButton_Click(object sender, RoutedEventArgs e)
{
    // Don't accept the dialog box if there is invalid data
    if (!IsValid(this)) return;
```

```csharp
        }

        // Validate all dependency objects in a window
        bool IsValid(DependencyObject node)
        {
            // Check if dependency object was passed
            if (node != null)
            {
                // Check if dependency object is valid.
                // NOTE: Validation.GetHasError works for controls that have validation rules attached 
                bool isValid = !Validation.GetHasError(node);
                if (!isValid)
                {
                    // If the dependency object is invalid, and it can receive the focus,
                    // set the focus
                    if (node is IInputElement) Keyboard.Focus((IInputElement)node);
                    return false;
                }
            }

            // If this dependency object is valid, check all child dependency objects
            foreach (object subnode in LogicalTreeHelper.GetChildren(node))
            {
                if (subnode is DependencyObject)
                {   
                    // If a child dependency object is invalid, return false immediately,
                    // otherwise keep checking
                    if (IsValid((DependencyObject)subnode) == false) return false;
                }
            }

            // All dependency objects are valid
            return true;
        }
    }
}
```

此代码枚举窗口上的所有依赖项对象，如果无效 (返回的[GetHasError](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation.gethaserror)，则无效控件获得焦点时，`IsValid`方法将返回`false`，和窗口被视为无效。

一旦对话框有效，就可以安全关闭并返回。 作为返回过程的一部分，需要将结果返回到调用函数。

##### 设置模式对话框结果

打开对话框框中使用[ShowDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.showdialog)基本上就像调用方法： 打开对话框框中使用的代码[ShowDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.showdialog)将等待，直至[ShowDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.showdialog)返回。 当[ShowDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.showdialog)，则返回的代码需要调用它来决定是否要继续还是停止处理，根据用户按下**确定**按钮或**取消**按钮。 若要帮助做出决定，对话框需要返回用户的选择作为[Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean)从返回的值[ShowDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.showdialog)方法。

当**确定**单击按钮时，[ShowDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.showdialog)应返回`true`。 这通过设置来实现[DialogResult](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.dialogresult)属性对话框的框何时**确定**单击按钮。

```csharp
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

namespace SDKSample
{
    public partial class MarginsDialogBox : Window
    {
```

```csharp
void okButton_Click(object sender, RoutedEventArgs e)
{
```

```csharp
    // Dialog box accepted
    this.DialogResult = true;
}
```

```csharp
    }
}
```

请注意，设置[DialogResult](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.dialogresult)属性还会导致窗口自动关闭，这减少了需要显式调用[Close](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.close)。

当**取消**单击按钮时，[ShowDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.showdialog)应返回`false`，这也要求设置[DialogResult](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.dialogresult)属性。

```csharp
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

namespace SDKSample
{
    public partial class MarginsDialogBox : Window
    {
```

```csharp
void cancelButton_Click(object sender, RoutedEventArgs e)
{
    // Dialog box canceled
    this.DialogResult = false;
}
```

```csharp
    }
}
```

当按钮的[IsCancel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button.iscancel)属性设置为`true`和用户按**取消**按钮或 ESC 键[DialogResult](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.dialogresult)会自动设置为`false`。 以下标记具有相同的效果与上面的代码，而无需处理[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件。

```xaml
<Button Name="cancelButton" IsCancel="True">Cancel</Button>
```

一个对话框将自动返回`false`当用户按下**关闭**按钮的标题栏中，也可以选择**关闭**中的菜单项**系统**菜单。

##### 处理从模式对话框返回的数据

当[DialogResult](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.dialogresult)设置对话框中，通过打开它的函数可以通过检查获取对话框结果[DialogResult](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.dialogresult)属性时[ShowDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.showdialog)返回。

```csharp
using System;
using System.ComponentModel;
using System.Windows;
using System.Windows.Controls;
using Microsoft.Win32;

namespace SDKSample
{
    public partial class MainWindow : Window
    {
```

```csharp
void formatMarginsMenuItem_Click(object sender, RoutedEventArgs e)
{
```

```csharp
    // Process data entered by user if dialog box is accepted
    if (dlg.DialogResult == true)
    {
        // Update fonts
        this.documentTextBox.Margin = dlg.DocumentMargin;
    }
}
```

```csharp
    }
}
```

如果对话框结果为`true`，该函数将其用作提示来检索和处理由用户提供的数据。

 备注

之后[ShowDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.showdialog)已返回，不能重新打开对话框。 相反，需要创建新实例。

如果对话框结果为`false`，该函数应适当结束处理。



##### 创建无模式自定义对话框

无模式对话框（如下图中所示的“查找”对话框）与模式对话框具有相同的基本外观。

![“查找”对话框](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/dialogboxesoverviewfigure6.png)

但行为稍有不同，如以下各节中所述。

##### 打开无模式对话框

通过调用打开无模式对话框[Show](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.show)方法。

```xaml
<!--Main Window-->
```

```csharp
using System;
using System.ComponentModel;
using System.Windows;
using System.Windows.Controls;
using Microsoft.Win32;

namespace SDKSample
{
    public partial class MainWindow : Window
    {
```

```csharp
void editFindMenuItem_Click(object sender, RoutedEventArgs e)
{
    // Instantiate the dialog box
    FindDialogBox dlg = new FindDialogBox(this.documentTextBox);

    // Configure the dialog box
    dlg.Owner = this;
    dlg.TextFound += new TextFoundEventHandler(dlg_TextFound);

    // Open the dialog box modally
    dlg.Show();
}
```

```csharp
    }
}
```

与不同[ShowDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.showdialog)，[Show](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.show)立即返回。 因此，调用窗口无法判断无模式对话框何时关闭，也就不知道何时检查对话框结果或从对话框获取数据进行进一步处理。 相反，对话框需要创建替代方法来将数据返回到调用窗口进行处理。

##### 处理无模式对话框返回的数据

在此示例中，`FindDialogBox`可能会返回一个或多个查找到主窗口中，具体取决于要而无需任何特定频率搜索的文本的结果。 和模式对话框一样，无模式对话框也可以使用属性返回结果。 但拥有对话框的窗口需要了解何时检查那些属性。 实现此目的的一种方法是用对话框实现事件，只要找到文本就引发它。 `FindDialogBox` 实现`TextFoundEvent`出于此目的，这首先需要委托。

```csharp
using System;
namespace SDKSample
{
    public delegate void TextFoundEventHandler(object sender, EventArgs e);
}
```

使用`TextFoundEventHandler`委派，请`FindDialogBox`实现`TextFoundEvent`。

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Text.RegularExpressions;

namespace SDKSample
{
    public partial class FindDialogBox : Window
    {
        public event TextFoundEventHandler TextFound;
        protected virtual void OnTextFound()
        {
            TextFoundEventHandler textFound = this.TextFound;
            if (textFound != null) textFound(this, EventArgs.Empty);
        }
```

```csharp
    }
}
```

因此，`Find`可以引发事件时找到搜索结果。

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Text.RegularExpressions;

namespace SDKSample
{
    public partial class FindDialogBox : Window
    {
		void findNextButton_Click(object sender, RoutedEventArgs e)
		{
			// Text found
			this.index = match.Index;
			this.length = match.Length;
			OnTextFound();
		}
    }
}
```

所有者窗口则需要注册和处理此事件。

```csharp
using System;
using System.ComponentModel;
using System.Windows;
using System.Windows.Controls;
using Microsoft.Win32;

namespace SDKSample
{
    public partial class MainWindow : Window
    {
        void dlg_TextFound(object sender, EventArgs e)
        {
            // Get the find dialog box that raised the event
            FindDialogBox dlg = (FindDialogBox)sender;

            // Get find results and select found text
            this.documentTextBox.Select(dlg.Index, dlg.Length);
            this.documentTextBox.Focus();
        }
    }
}
```

##### 关闭无模式对话框

因为[DialogResult](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.dialogresult)不需要为其设置，可以使用系统关闭无模式对话框提供机制，包括以下：

- 单击**关闭**标题栏中的按钮。
- 按 ALT+F4。
- 选择**关闭**从**系统**菜单。

或者，你的代码可以调用[Close](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.close)时**关闭**单击按钮。

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Text.RegularExpressions;

namespace SDKSample
{
    public partial class FindDialogBox : Window
    {
        void closeButton_Click(object sender, RoutedEventArgs e)
        {
            // Close dialog box
            this.Close();
        }
    }
}
```

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/window-management-how-to-topics)

下面的主题介绍如何管理Windows Presentation Foundation (WPF)windows。

### 本节内容

[自动调整窗口大小以适应其中的内容](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/how-to-automatically-size-a-window-to-fit-its-content)
[在应用程序中获取所有窗口](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/how-to-get-all-windows-in-an-application)
[获取和设置主应用程序窗口](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/how-to-get-and-set-the-main-application-window)
[打开对话框](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/how-to-open-a-dialog-box)
[打开消息框](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/how-to-open-a-message-box)
[打开窗口](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/how-to-open-a-window)
[返回对话框结果](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/how-to-return-a-dialog-box-result)

### [Automatically Size a Window to Fit Its Content](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/how-to-automatically-size-a-window-to-fit-its-content)

此示例演示如何设置[SizeToContent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.sizetocontent)属性来指定如何调整窗口大小以适应其内容。

- 示例

```csharp
// Manually alter window height and width
this.SizeToContent = SizeToContent.Manual;

// Automatically resize width relative to content
this.SizeToContent = SizeToContent.Width;

// Automatically resize height relative to content
this.SizeToContent = SizeToContent.Height;

// Automatically resize height and width relative to content
this.SizeToContent = SizeToContent.WidthAndHeight;
```

### [Get all Windows in an Application](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/how-to-get-all-windows-in-an-application)

此示例演示如何获取所有[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)应用程序中的对象。

- 示例

每个实例化[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)对象时，是否可见，会自动添加到由管理的窗口引用的集合[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)，和从公开[Windows](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.windows)。

你可以枚举[Windows](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.windows)获取使用下面的代码的所有实例化的 windows:

```csharp
foreach( Window window in Application.Current.Windows ) {
  Console.WriteLine(window.Title);
}
```

### [Get and Set the Main Application Window](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/how-to-get-and-set-the-main-application-window)

此示例演示如何获取和设置应用程序主窗口。

- 示例

第一个[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)，实例化中 Windows Presentation Foundation (WPF) 应用程序自动通过设置[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)作为主应用程序窗口。 第一个[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)要实例化的将最可能是指定为启动窗口统一资源标识符 (URI)(请参阅[StartupUri](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.startupuri))。

第一个[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)也无法使用代码来实例化。 一个示例应用程序在启动期间，如下所示打开一个窗口：

```csharp
public partial class App : Application
{
    void App_Startup(object sender, StartupEventArgs e)
    {
        MainWindow window = new MainWindow();
        window.Show();
    }
}
```

有时，第一个实例化[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)是不实际应用程序主窗口，例如初始屏幕。 在这种情况下，你可以指定主应用程序窗口使用标记，如下所示：

```xaml
<Application 
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    StartupUri="StartupWindow.xaml"
    >
  <Application.MainWindow>
    <NavigationWindow Source="MainPage.xaml" Visibility="Visible"></NavigationWindow>
  </Application.MainWindow>
</Application>
```

是否自动或手动指定主窗口，则你可以从主窗口[MainWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.mainwindow)使用下面的代码，如下所示：

```csharp
// Get the main window
Window mainWindow = this.MainWindow;
```

### [Open a Dialog Box](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/how-to-open-a-dialog-box)

此示例演示如何以打开一个对话框。

- 示例

对话框是通过实例化打开的窗口[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)并调用[ShowDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.showdialog)方法。 [ShowDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.showdialog) 将打开一个窗口和新建对话框已关闭之前不会返回。 此类型的窗口是也称为*模式*窗口中，它会限制用户输入。

```csharp
CustomDialogBox dialogBox = new CustomDialogBox();
dialogBox.ShowDialog(); // Returns when dialog box has closed
```

#### .NET Framework 安全性

调用[ShowDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.showdialog)需要有权使用所有窗口和不受限制的用户输入的事件。

### [Open a Message Box](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/how-to-open-a-message-box)

此示例演示如何以打开一个消息框。

- 示例

消息框是一种预制模式对话框用于向用户显示的信息。 一个消息框打开通过调用静态[Show](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.messagebox.show)方法的[MessageBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.messagebox)类。 当[Show](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.messagebox.show)是调用，该消息使用传递的字符串参数。 几个重载[Show](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.messagebox.show)允许你配置如何将出现一个消息框 (请参阅[MessageBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.messagebox))。

```csharp
private void ShowMessageBoxButton_Click(object sender, RoutedEventArgs e)
{
    // Configure message box
    string message = "Hello, MessageBox!";
    // Show message box
    MessageBoxResult result = MessageBox.Show(message);
}
```

### [Open a Window](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/how-to-open-a-window)

此示例演示如何打开窗口。

- 示例

通过实例化打开一个窗口[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)并调用[Show](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.show)方法。 [Show](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.show) 将打开一个窗口，并立即返回而不等待新窗口将会关闭。 这种类型的窗口是也称为*无模式*窗口中，它不会限制用户输入。

```csharp
CustomWindow window = new CustomWindow();
window.Show(); // Returns immediately
```

#### .NET Framework 安全性

实例化[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)需要有权调用不安全的本机方法 (请参阅[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.-ctor))。

### [Return a Dialog Box Result](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/how-to-return-a-dialog-box-result)

此示例演示如何检索一个窗口，通过调用打开的对话框结果[ShowDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.showdialog)。

- 示例

在对话框关闭之前，其[DialogResult](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.dialogresult)属性应设置与[Nullable](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullable-1) [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) ，该值指示用户如何关闭对话框。 此值由返回[ShowDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.showdialog)以允许客户端代码，以确定如何关闭对话框中，因此，如何处理的结果。

> [DialogResult](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.dialogresult) 当通过调用来打开窗口时才可以设置[ShowDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.showdialog)。

```csharp
DialogBoxWithResult dialogBoxWithResult = new DialogBoxWithResult();
// Open dialog box and retrieve dialog result when ShowDialog returns
bool? dialogResult = dialogBoxWithResult.ShowDialog();
switch (dialogResult)
{
    case true:
        // User accepted dialog box
        break;
    case false:
        // User canceled dialog box
        break;
    default:
        // Indeterminate
        break;
}
```

#### .NET Framework 安全性

调用[ShowDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.showdialog)需要有权使用所有窗口和不受限制的用户输入的事件。