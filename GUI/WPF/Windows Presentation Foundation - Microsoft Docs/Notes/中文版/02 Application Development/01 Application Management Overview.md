# [Application Management Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/application-management-overview)

所有应用程序都可能会共享一组适用于实现和管理应用程序的常见功能。 本主题概述中的功能的[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)类用于创建和管理应用程序。

## Application 类

在 WPF 中，常见的应用程序范围的功能会封装在[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)类。 [Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)类包括以下功能：

- 对应用程序的生存期进行跟踪并与之进行交互。
- 检索和处理命令行参数。
- 检测和响应未经处理的异常。
- 共享应用程序范围的属性和资源。
- 管理独立应用程序中的窗口。
- 跟踪和管理导航。



## 如何使用 Application 类执行常见任务

如果您不感兴趣的详细信息的所有[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)类下, 表列出了一些常见任务[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)以及如何完成它们。 通过查看相关的 API 和主题，可以找到详细信息和示例代码。

| 任务                                                     | 方法                                                         |
| -------------------------------------------------------- | ------------------------------------------------------------ |
| 获取表示当前应用程序的对象                               | 使用 [Application.Current](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.current) 属性。 |
| 将启动屏幕添加到应用程序中                               | 请参阅[将初始屏幕添加到 WPF 应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/how-to-add-a-splash-screen-to-a-wpf-application)。 |
| 启动应用程序                                             | 使用 [Application.Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.run) 方法。 |
| 停止应用程序                                             | 使用[Shutdown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.shutdown)方法的[Application.Current](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.current)对象。 |
| 从命令行获取参数                                         | 处理[Application.Startup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.startup)事件并使用[StartupEventArgs.Args](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.startupeventargs.args)属性。 有关示例，请参阅[Application.Startup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.startup)事件。 |
| 获取和设置应用程序退出代码                               | 设置[ExitEventArgs.ApplicationExitCode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.exiteventargs.applicationexitcode)中的属性[Application.Exit](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.exit)事件处理程序或调用[Shutdown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.shutdown)方法并传入一个整数。 |
| 检测和响应未经处理的异常                                 | 处理[DispatcherUnhandledException](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.dispatcherunhandledexception)事件。 |
| 获取和设置应用程序范围的资源                             | 使用 [Application.Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.resources) 属性。 |
| 使用应用程序范围的资源字典                               | 请参阅[使用应用程序范围的资源字典](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/how-to-use-an-application-scope-resource-dictionary)。 |
| 获取和设置应用程序范围的属性                             | 使用 [Application.Properties](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.properties) 属性。 |
| 获取和保存应用程序的状态                                 | 请参阅[保持和还原应用程序作用域属性在应用程序会话之间](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/persist-and-restore-application-scope-properties)。 |
| 管理非代码数据文件，包括资源文件、内容文件和源站点文件。 | 请参阅[WPF 应用程序资源、 内容和数据文件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/wpf-application-resource-content-and-data-files)。 |
| 管理独立应用程序中的窗口                                 | 请参阅 [WPF 窗口概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/wpf-windows-overview)。 |
| 跟踪和管理导航                                           | 请参阅[导航概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-overview)。 |

## 应用程序定义

若要利用的功能[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)类，必须实现应用程序定义。 WPF 应用程序定义是一个类，派生自[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)使用特殊的 MSBuild 设置进行配置。

#### 实现应用程序定义

使用标记和代码隐藏来实现典型的 WPF 应用程序定义。 因此，可以使用标记以声明方式设置应用程序的属性、资源和注册事件，同时还能处理事件并在代码隐藏中实现特定于应用程序的行为。

以下示例演示了如何使用标记和代码隐藏来实现应用程序定义：

```xaml
<Application 
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml" 
  x:Class="SDKSample.App" />
```

```csharp
using System.Windows;

namespace SDKSample
{
    public partial class App : Application { }
}
```

要允许标记文件和代码隐藏文件协同工作，需要进行以下配置：

- 在标记中，`Application`元素必须包括`x:Class`属性。 应用程序生成时，是否存在`x:Class`文件的标记中，MSBuild 将创建`partial`类派生自[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)并且具有指定的名称`x:Class`属性。 这需要 XAML 架构的 XML 命名空间声明添加 (`xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"`)。
- 在代码隐藏中，类必须是`partial`类指定的同名`x:Class`属性在标记中，必须派生自[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)。 这允许要与之关联的代码隐藏文件`partial`生成应用程序时，为标记文件生成的类 (请参阅[构建 WPF 应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/building-a-wpf-application-wpf))。

> 创建新的 WPF 应用程序项目或使用 Visual Studio 的 WPF 浏览器应用程序项目时，应用程序定义默认情况下包括和使用标记和代码隐藏定义。

至少要有这段代码，才能实现应用程序定义。 但是，需要对应用程序定义生成和运行应用程序之前进行其他的 MSBuild 配置。

#### 针对 MSBuild 配置应用程序定义

独立应用程序和 XAML 浏览器应用程序 (Xbap) 需要一定的基础结构的实现，才能运行。 在该基础结构中，入口点是最重要的一个部分。 当用户启动某个应用程序时，操作系统会调用入口点，这是一个为人熟知的应用程序启动函数。

通常，开发者需要自行编写其中的部分或全部代码（具体取决于所采用的技术）。 但是，WPF 将生成此代码为你的应用程序定义的标记文件配置为 MSBuild 时`ApplicationDefinition`项，如以下 MSBuild 项目文件中所示：

```xml
<Project   
  DefaultTargets="Build"  
                        xmlns="http://schemas.microsoft.com/developer/msbuild/2003">  
  ...  
  <ApplicationDefinition Include="App.xaml" />  
  <Compile Include="App.xaml.cs" />  
  ...  
</Project>  
```

代码隐藏文件包含代码，因为它被标记为 MSBuild`Compile`项，按原样正常。

这些标记和代码隐藏文件的应用程序定义的 MSBuild 配置应用程序，MSBuild 将生成如下所示的代码：

```csharp
using System;
using System.Windows;

namespace SDKSample
{
    public class App : Application
    {
        public App() { }
        [STAThread]
        public static void Main()
        {
            // Create new instance of application subclass
            App app = new App();

            // Code to register events and set properties that were
            // defined in XAML in the application definition
            app.InitializeComponent();

            // Start running the application
            app.Run();
        }

        public void InitializeComponent()
        {
            // Initialization code goes here.
        }
    }
}
```

生成的代码扩充了应用程序定义与其他基础结构代码，其中包括入口点方法`Main`。 [STAThreadAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.stathreadattribute)特性应用于`Main`方法，以指示 WPF 应用程序的主 UI 线程是 STA 线程，所需的 WPF 应用程序。 调用时，`Main`创建的新实例`App`然后才能调用`InitializeComponent`标记中实现方法来注册事件并设置属性。 因为`InitializeComponent`生成，你无需显式调用`InitializeComponent`从应用程序定义像[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)和[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)实现。 最后，[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.run)调用方法来启动该应用程序。

## 获取当前应用程序

因为的功能[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)类共享跨应用程序，可以只有一个实例[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)每个类[AppDomain](https://docs.microsoft.com/zh-cn/dotnet/api/system.appdomain)。 若要强制执行此操作，请[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)类作为一个单独的类实现 (请参阅[C# 中实现单一实例](https://go.microsoft.com/fwlink/?LinkId=100567))，它创建其自身的单个实例，并提供了共享访问与它通信`static` [Current](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.current)属性。

下面的代码演示如何获取对的引用[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)对象当前[AppDomain](https://docs.microsoft.com/zh-cn/dotnet/api/system.appdomain)。

```csharp
// Get current application
Application current = App.Current;
```

[Current](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.current) 返回到的实例的引用[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)类。 如果你想对您[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)派生的类必须强制转换的值[Current](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.current)属性，如下面的示例中所示。

```csharp
// Get strongly-typed current application
App app = (App)App.Current;
```

您可以检查的值[Current](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.current)中的生存期内随时[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)对象。 但是，检查时要小心。 之后[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)实例化类时，在此期间一段内的状态[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)对象不一致。 在此期间，[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)执行各项初始化任务所需的代码运行，包括建立应用程序基础结构、 设置属性，以及注册事件。 如果尝试使用[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)对象在此期间，您的代码可能具有意外的结果，尤其是当它依赖于各种[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)所设置的属性。

当[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)完成其初始化工作，其生存期内才真正开始。

## 应用程序生存期

WPF 应用程序的生存期标记的几个事件引发的[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)，告知你启动应用程序后，经过激活和停用，并已关闭。

#### 初始屏幕

在中启动.NET Framework 3.5 SP1，可以指定要在启动窗口中，使用的图像或*初始屏幕*。 [SplashScreen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.splashscreen)类可以轻松加载你的应用程序时显示启动窗口。 [SplashScreen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.splashscreen)窗口中将创建和显示之前[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.run)调用。 有关详细信息，请参阅[应用程序启动时间](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/application-startup-time)并[向 WPF 应用程序添加初始屏幕](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/how-to-add-a-splash-screen-to-a-wpf-application)。

#### 启动应用程序

之后[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.run)称为和初始化应用程序，该应用程序已准备好运行。 当表示此时刻[Startup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.startup)引发事件：

```csharp
using System.Windows;

namespace SDKSample
{
    public partial class App : Application
    {
        void App_Startup(object sender, StartupEventArgs e)
        {
            // Application is running
        }
    }
}
```

此时在应用程序的生命周期的最常见的做法是显示 UI。

#### 显示用户界面

大多数的独立 Windows 应用程序打开[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)开始时间运行。 [Startup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.startup)事件处理程序是一个位置可以从其执行此操作，如以下代码所示。

```xaml
<Application
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  x:Class="SDKSample.App" 
  Startup="App_Startup" />
```

```csharp
using System.Windows;

namespace SDKSample
{
    public partial class App : Application
    {
        void App_Startup(object sender, StartupEventArgs e)
        {
            // Open a window
            MainWindow window = new MainWindow();
            window.Show();
        }
    }
}
```

> 第一个[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)要实例化位于独立的应用程序将成为主应用程序窗口默认情况下。 这[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)引用的对象[Application.MainWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.mainwindow)属性。 值[MainWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.mainwindow)属性可以以编程方式更改，如果第一个不同的窗口实例化[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)应该是主窗口。

XBAP 首次启动时，它将很可能会导航到[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)。 以下代码对此进行了演示。

```xaml
<Application 
  x:Class="SDKSample.App"
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  Startup="App_Startup" />
```

```csharp
using System;
using System.Windows;
using System.Windows.Navigation;

namespace SDKSample
{
    public partial class App : Application
    {        
        void App_Startup(object sender, StartupEventArgs e)
        {
            ((NavigationWindow)this.MainWindow).Navigate(new Uri("HomePage.xaml", UriKind.Relative));
        }
    }
}
```

如果处理[Startup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.startup)仅打开[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)或导航到[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)，可以设置`StartupUri`特性标记中。

下面的示例演示如何使用[StartupUri](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.startupuri)独立应用程序以打开[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)。

```xaml
<Application
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    StartupUri="MainWindow.xaml" />
```

下面的示例演示如何使用[StartupUri](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.startupuri)XBAP 以导航到从[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)。

```xaml
<Application
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    StartupUri="HomePage.xaml" />
```

此标记的效果等同于用于打开窗口的上一段代码。

> 在导航栏的详细信息，请参阅[导航概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-overview)。

您需要处理[Startup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.startup)事件以打开[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)如果需要实例化它使用非默认构造函数，或需要设置其属性或订阅其事件之前显示它，或需要处理任何命令行参数，启动应用程序时提供。

#### 处理命令行参数

在 Windows 中，可以从命令提示符或桌面启动独立应用程序。 在这两种情况下，命令行参数都可以传递至应用程序。 以下示例展示了一个通过单个命令行参数“/StartMinimized”来启动的应用程序：

```
wpfapplication.exe /StartMinimized
```

在应用程序初始化期间 WPF 从操作系统检索命令行参数，并将它们传递到[Startup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.startup)事件处理程序通过[Args](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.startupeventargs.args)属性的[StartupEventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.startupeventargs)参数。 可以使用如下代码来检索和存储命令行参数。

```xaml
<Application
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  x:Class="SDKSample.App"
  Startup="App_Startup" />
```

```csharp
using System.Windows;

namespace SDKSample
{
    public partial class App : Application
    {
        void App_Startup(object sender, StartupEventArgs e)
        {
            // Application is running
            // Process command line args
            bool startMinimized = false;
            for (int i = 0; i != e.Args.Length; ++i)
            {
                if (e.Args[i] == "/StartMinimized")
                {
                    startMinimized = true;
                }
            }

            // Create main application window, starting minimized if specified
            MainWindow mainWindow = new MainWindow();
            if (startMinimized)
            {
                mainWindow.WindowState = WindowState.Minimized;
            }
            mainWindow.Show();
        }
    }
}
```

这段代码处理[Startup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.startup)检查是否 **/StartMinimized**提供的命令行参数; 如果是这样，它将打开主窗口中的以[WindowState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.windowstate)的[Minimized](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.windowstate#System_Windows_WindowState_Minimized)。 请注意，由于[WindowState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.windowstate)必须以编程方式设置主属性[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)必须在代码中显式打开。

Xbap 不能检索和处理命令行参数，因为程序启动时使用 ClickOnce 部署 (请参阅[部署 WPF 应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/deploying-a-wpf-application-wpf))。 但是，它们可以检索和处理来自用于启动它们的 URL 的查询字符串参数。

#### 应用程序激活和停用

Windows 允许用户应用程序之间切换。 最常见的方法是使用 ALT + TAB 键组合。 仅可应用程序切换为，如果具有可见[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)，用户可以选择。 当前所选[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)是*活动窗口*(也称为*前台窗口*) 是[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)接收用户输入。 与活动窗口的应用程序是*活动的应用程序*(或*前台应用程序*)。 应用程序会在以下情况下变为活动应用程序：

- 它将启动并显示[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)。
- 用户通过选择从另一个应用程序切换[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)应用程序中。

通过处理应用程序将变为活动状态时可以检测[Application.Activated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.activated)事件。

同样地，应用程序会在以下情况下变为非活动状态：

- 用户从当前应用程序切换到另一应用程序。
- 应用程序关闭后。

当应用程序通过处理成为非活动状态时，可以检测到[Application.Deactivated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.deactivated)事件。

下面的代码演示如何处理[Activated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.activated)和[Deactivated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.deactivated)事件，以确定应用程序是否处于活动状态。

```xaml
<Application 
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  x:Class="SDKSample.App"
  StartupUri="MainWindow.xaml"
  Activated="App_Activated" 
  Deactivated="App_Deactivated" />
```

```csharp
using System;
using System.Windows;

namespace SDKSample
{
    public partial class App : Application
    {
        bool isApplicationActive;

        void App_Activated(object sender, EventArgs e)
        {
            // Application activated
            this.isApplicationActive = true;
        }

        void App_Deactivated(object sender, EventArgs e)
        {
            // Application deactivated
            this.isApplicationActive = false;
        }
    }
}
```

一个[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)还可以激活和停用。 有关更多信息，请参见[Window.Activated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.activated)和[Window.Deactivated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.deactivated)。

> 既不[Application.Activated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.activated)也不[Application.Deactivated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.deactivated)引发的 Xbap。

#### 应用程序关闭

应用程序的生存期会在其关闭时结束，出现这一情况可能是因为：

- 用户关闭每个[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)。
- 用户关闭了主[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)。
- 用户通过注销或关闭来结束 Windows 会话。
- 满足了特定于应用程序的条件。

若要帮助你管理应用程序关闭[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)提供了[Shutdown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.shutdown)方法，[ShutdownMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.shutdownmode)属性，和[SessionEnding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.sessionending)和[Exit](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.exit)事件。

> [Shutdown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.shutdown) 仅可以从具有的应用程序调用[UIPermission](https://docs.microsoft.com/zh-cn/dotnet/api/system.security.permissions.uipermission)。 独立 WPF 应用程序始终具有此权限。 但是，Internet 区域部分信任安全沙箱中运行的 Xbap 不这样做。

##### 关闭模式

大多数应用程序会在所有窗口都关闭后或在主窗口关闭后关闭。 但是，有时，应用程序会在何时关闭取决于特定于应用程序的其他条件。 你可以指定在其下你的应用程序会自动关机设置的条件[ShutdownMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.shutdownmode)具有以下项之一[ShutdownMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shutdownmode)枚举值：

- [OnLastWindowClose](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shutdownmode#System_Windows_ShutdownMode_OnLastWindowClose)
- [OnMainWindowClose](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shutdownmode#System_Windows_ShutdownMode_OnMainWindowClose)
- [OnExplicitShutdown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shutdownmode#System_Windows_ShutdownMode_OnExplicitShutdown)

默认值[ShutdownMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.shutdownmode)是[OnLastWindowClose](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shutdownmode#System_Windows_ShutdownMode_OnLastWindowClose)，这意味着，应用程序会自动将关闭时用户关闭应用程序中的最后一个窗口。 但是，如果主窗口关闭时，应关闭你的应用程序，WPF 会自动执行，如果您设置[ShutdownMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.shutdownmode)到[OnMainWindowClose](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shutdownmode#System_Windows_ShutdownMode_OnMainWindowClose)。 这在下面的示例中显示。

```xaml
<Application
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.App"
    ShutdownMode="OnMainWindowClose" />
```

特定于应用程序的关闭条件后，您设置[ShutdownMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.shutdownmode)到[OnExplicitShutdown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shutdownmode#System_Windows_ShutdownMode_OnExplicitShutdown)。 在这种情况下，则需要负责以关闭应用程序的情况下通过显式调用[Shutdown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.shutdown)方法; 否则，你的应用程序将继续运行，即使所有窗口已都关闭。 请注意，[Shutdown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.shutdown)时隐式调用[ShutdownMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.shutdownmode)可以是[OnLastWindowClose](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shutdownmode#System_Windows_ShutdownMode_OnLastWindowClose)或[OnMainWindowClose](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shutdownmode#System_Windows_ShutdownMode_OnMainWindowClose)。

> [ShutdownMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.shutdownmode) 可以设置从 XBAP，但将被忽略;在浏览器中或已关闭承载 XBAP 的浏览器导航离开时，将始终关闭 XBAP。 有关详细信息，请参阅[导航概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-overview)。

##### 会话结束

由描述的关闭条件[ShutdownMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.shutdownmode)属性是特定于应用程序。 不过，在某些情况下，应用程序可能会因外部条件而关闭。 用户通过以下操作来结束 Windows 会话时发生的最常见的外部条件：

- 注销
- 关闭
- 重新启动
- 休眠

若要检测 Windows 会话结束时，你可以处理[SessionEnding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.sessionending)事件，如下面的示例中所示。

```xaml
<Application 
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.App"
    StartupUri="MainWindow.xaml"
    SessionEnding="App_SessionEnding" />
```

```csharp
using System.Windows;

namespace SDKSample
{
    public partial class App : Application
    {
        void App_SessionEnding(object sender, SessionEndingCancelEventArgs e)
        {
            // Ask the user if they want to allow the session to end
            string msg = string.Format("{0}. End session?", e.ReasonSessionEnding);
            MessageBoxResult result = MessageBox.Show(msg, "Session Ending", MessageBoxButton.YesNo);

            // End session, if specified
            if (result == MessageBoxResult.No)
            {
                e.Cancel = true;
            }
        }
    }
}
```

在此示例中，代码会检查[ReasonSessionEnding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.sessionendingcanceleventargs.reasonsessionending)属性来确定如何结束 Windows 会话。 它会根据该值向用户显示确认消息。 如果用户不希望会话结束，该代码将设置[Cancel](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.canceleventargs.cancel)到`true`以阻止结束 Windows 会话。

> [SessionEnding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.sessionending) 不会引发为 Xbap。

##### Exit

应用程序在关闭时可能需要执行一些最终处理，如保持应用程序状态。 对于这些情况下，您就可以处理[Exit](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.exit)事件，作为`App_Exit`事件处理程序执行在下面的示例。 它被定义为事件处理程序中*App.xaml*文件。 其实现中突出显示*App.xaml.cs*并*Application.xaml.vb*文件。

```xaml
<Application
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.App"
    StartupUri="MainWindow.xaml" 
    Startup="App_Startup" 
    Exit="App_Exit">
    <Application.Resources>
        <SolidColorBrush x:Key="ApplicationScopeResource" Color="White"></SolidColorBrush>
    </Application.Resources>
</Application>
```

```csharp
using System.Windows;
using System.IO;
using System.IO.IsolatedStorage;

namespace SDKSample
{
    public partial class App : Application
    {
        string filename = "App.txt";

        public App()
        {
            // Initialize application-scope property
            this.Properties["NumberOfAppSessions"] = 0;
        }

        private void App_Startup(object sender, StartupEventArgs e)
        {
            // Restore application-scope property from isolated storage
            IsolatedStorageFile storage = IsolatedStorageFile.GetUserStoreForDomain();
            try
            {
                using (IsolatedStorageFileStream stream = new IsolatedStorageFileStream(filename, FileMode.Open, storage))
                using (StreamReader reader = new StreamReader(stream))
                {
                    // Restore each application-scope property individually
                    while (!reader.EndOfStream)
                    {
                        string[] keyValue = reader.ReadLine().Split(new char[] {','});
                        this.Properties[keyValue[0]] = keyValue[1];
                    }
                }
            }
            catch (FileNotFoundException ex)
            {
                // Handle when file is not found in isolated storage:
                // * When the first application session
                // * When file has been deleted
            }
        }

        private void App_Exit(object sender, ExitEventArgs e)
        {
            // Persist application-scope property to isolated storage
            IsolatedStorageFile storage = IsolatedStorageFile.GetUserStoreForDomain();
            using (IsolatedStorageFileStream stream = new IsolatedStorageFileStream(filename, FileMode.Create, storage))
            using (StreamWriter writer = new StreamWriter(stream))
            {
                // Persist each application-scope property individually
                foreach (string key in this.Properties.Keys)
                {
                    writer.WriteLine("{0},{1}", key, this.Properties[key]);
                }
            }
        }
    }
}
```

有关完整示例，请参阅[保持和还原应用程序作用域属性跨应用程序会话](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/persist-and-restore-application-scope-properties)。

[Exit](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.exit) 可以处理由独立应用程序和 Xbap。 Xbap 的[Exit](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.exit)时在以下情况下引发：

- XBAP 导航离开。
- 在Internet Explorer 7，当关闭承载 XBAP 的选项卡。
- 关闭浏览器时。

##### 退出代码

在大多数情况下，应用程序由操作系统根据用户的请求来启动。 但是，应用程序也可由另一应用程序启动，以执行某项特定任务。 当被启动的应用程序关闭时，执行启动操作的应用程序可能想要了解导致被启动应用程序关闭的条件。 在这些情况下，Windows 允许应用程序在关闭会返回应用程序退出代码。 默认情况下，WPF 应用程序返回的退出代码值为 0。

> 应用程序退出代码时从 Visual Studio 进行调试时，会显示在**输出**窗口应用程序关闭时，在一条消息，如以下所示：

```
The program '[5340] AWPFApp.vshost.exe: Managed' has exited with code 0 (0x0).
```

打开**输出**通过单击窗口**输出**上**视图**菜单。

若要更改退出代码，可以调用[Shutdown(Int32)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.shutdown#System_Windows_Application_Shutdown_System_Int32_)重载，这样便可以接受整数参数作为退出代码：

```csharp
// Shutdown and return a non-default exit code
Application.Current.Shutdown(-1);
```

可以检测的退出代码值和其进行更改，通过处理[Exit](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.exit)事件。 [Exit](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.exit)事件处理程序传递[ExitEventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.exiteventargs)以便进行访问的退出代码与[ApplicationExitCode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.exiteventargs.applicationexitcode)属性。 有关详细信息，请参阅 [Exit](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.exit)。

> 可以在独立应用程序和 Xbap 设置退出代码。 但是，退出代码值被忽略的 Xbap。

#### 未经处理的异常

有时，应用程序可能会在异常条件下关闭，如引发意外异常时。 在这种情况下，应用程序可能没有可用于检测和处理异常的代码。 这类异常就是未经处理的异常；应用程序会在关闭之前显示一个与下图所示内容类似的通知。

![未经处理的异常的相关通知](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/applicationmanagementoverviewfigure2.png)

从用户体验的角度来看，应用程序最好通过执行以下部分或全部操作来避免这种默认行为：

- 显示对用户友好的信息。
- 尝试让应用程序保持运行。
- 录制详细，Windows 事件日志中的开发人员友好的异常信息。

实现此支持取决于能否检测到未经处理的异常，这是什么[DispatcherUnhandledException](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.dispatcherunhandledexception)为引发事件。

```xaml
<Application
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  x:Class="SDKSample.App"
  StartupUri="MainWindow.xaml"
  DispatcherUnhandledException="App_DispatcherUnhandledException" />
```

```csharp
using System.Windows;
using System.Windows.Threading;

namespace SDKSample
{
    public partial class App : Application
    {
        void App_DispatcherUnhandledException(object sender, DispatcherUnhandledExceptionEventArgs e)
        {
            // Process unhandled exception

            // Prevent default unhandled exception processing
            e.Handled = true;
        }
    }
}
```

[DispatcherUnhandledException](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.dispatcherunhandledexception)事件处理程序传递[DispatcherUnhandledExceptionEventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcherunhandledexceptioneventargs)参数，其中包含与未经处理的异常，包括异常本身相关的上下文信息 ([DispatcherUnhandledExceptionEventArgs.Exception](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcherunhandledexceptioneventargs.exception))。 这些信息可用来确定如何处理异常。

当处理[DispatcherUnhandledException](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.dispatcherunhandledexception)，则应将设置[DispatcherUnhandledExceptionEventArgs.Handled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcherunhandledexceptioneventargs.handled)属性设置为`true`; 否则为 WPF 仍会将异常视为未经处理，并将恢复为前面所述的默认行为。 如果引发了未经处理的异常和任一[DispatcherUnhandledException](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.dispatcherunhandledexception)不处理事件，或处理的事件和[Handled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcherunhandledexceptioneventargs.handled)设置为`false`，在应用程序立即关闭。此外，没有其他[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)引发事件。 因此，您需要处理[DispatcherUnhandledException](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.dispatcherunhandledexception)如果应用程序的应用程序关闭之前必须运行的代码。

正如下一节所述，虽然应用程序可能会因未经处理的异常而关闭，但通常都是应用户请求而关闭的。

#### 应用程序生存期事件

独立应用程序和 Xbap 不具有完全相同的生存期。 下图展示了独立应用程序生存期内的各个关键事件及其引发顺序。

![独立应用程序 - 应用程序对象事件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/applicationmodeloverview-applicationobjectevents.png)

同样，以下图生存期内的 XBAP，说明了各个关键事件及其引发它们的序列。

![XBAP - 应用程序对象事件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/applicationmodeloverview-applicationobjectevents-xbap.png)

## [WPF Application Resource, Content, and Data Files](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/wpf-application-resource-content-and-data-files)

Microsoft Windows 应用程序通常依赖包含不可执行的数据，如文件可扩展应用程序标记语言 (XAML)，图像、 视频和音频。 Windows Presentation Foundation (WPF) 提供了配置、 确定，并使用这些类型的数据文件，称为应用程序数据文件的特殊支持。 这种支持主要针对一组特定的应用程序数据文件类型，包括：

- **资源文件**:数据文件编译为可执行文件或库的WPF程序集。
- **内容文件**:与可执行文件的显式关联的独立数据文件WPF程序集。
- **源站点文件**:没有与可执行文件关联的独立数据文件WPF程序集。

这三种类型的文件之间的一个重要区别是：资源文件和内容文件在生成时即为程序集所知；程序集明确知道它们的存在。 为源站点文件，但是，程序集可能完全不了解它们，或者通过 pack统一资源标识符 (URI)引用; 的后一种情况下不能保证被引用的源站点文件实际存在。

若要引用应用程序数据文件，Windows Presentation Foundation (WPF) 可使用包统一资源标识符 (URI)方案，它在详细信息中所述[WPF 中的 Pack Uri](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/pack-uris-in-wpf))。

本主题介绍如何配置和使用应用程序数据文件。

#### 资源文件

如果应用程序数据文件必须始终可供某个应用程序使用，那么保证可用性的唯一方法是将其编译到应用程序的主可执行程序集内，或者它所引用的程序集内。 此类型的应用程序数据文件称为*资源文件*。

应在以下情况下使用资源文件：

- 将资源文件编译到程序集内之后，无需更新资源文件的内容。
- 希望通过减少文件依赖项的数量来简化应用程序分发的复杂性。
- 在应用程序数据文件必须是可本地化 (请参阅[WPF 全球化和本地化概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/wpf-globalization-and-localization-overview))。

> 在本部分中所述的资源文件是不同的资源文件中所述[XAML 资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-resources)和不同于嵌入或链接的资源中所述[管理应用程序资源 (.NET)](https://msdn.microsoft.com/library/f2582734-8ada-4baa-8a7c-e2ef943ddf7e).

##### 配置资源文件

在中WPF，资源文件是包含在一个文件Microsoft Build Engine (MSBuild)项目用作`Resource`项。

```xml
<Project xmlns="http://schemas.microsoft.com/developer/msbuild/2003" ... >  
  ...  
  <ItemGroup>  
    <Resource Include="ResourceFile.xaml" />  
  </ItemGroup>  
  ...  
</Project>  
```

> 在中Microsoft Visual Studio，通过将文件添加到项目和设置创建一个资源文件及其`Build Action`到`Resource`。

当生成项目时，MSBuild将资源编译为程序集。

##### 使用资源文件

若要加载资源文件，可以调用[GetResourceStream](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.getresourcestream)方法[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)类，并传入一个包URI标识所需的资源文件。[GetResourceStream](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.getresourcestream) 返回[StreamResourceInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resources.streamresourceinfo)对象，该资源文件作为公开[Stream](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.stream)并描述其内容类型。

例如，下面的代码演示如何使用[GetResourceStream](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.getresourcestream)加载[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)资源文件，并将其设置为的内容[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)(`pageFrame`):

```csharp
// Navigate to xaml page
Uri uri = new Uri("/PageResourceFile.xaml", UriKind.Relative);
StreamResourceInfo info = Application.GetResourceStream(uri);
System.Windows.Markup.XamlReader reader = new System.Windows.Markup.XamlReader();
Page page = (Page)reader.LoadAsync(info.Stream);
this.pageFrame.Content = page;
```

虽然通过调用[GetResourceStream](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.getresourcestream)可以让您访问[Stream](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.stream)，您需要执行额外的工作来将其转换为将要设置其属性的类型。 相反，您可以让WPF负责打开和转换[Stream](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.stream)通过加载资源文件直接到使用代码的类型的属性。

下面的示例演示如何加载[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)直接[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)(`pageFrame`) 使用的代码。

```csharp
Uri pageUri = new Uri("/PageResourceFile.xaml", UriKind.Relative);
this.pageFrame.Source = pageUri;
```

下面的示例是与上例等效的标记。

```xaml
<Frame Name="pageFrame" Source="PageResourceFile.xaml" />
```

##### 作为资源文件的应用程序代码文件

一组特殊WPF可以使用包引用应用程序代码文件URI，包括 windows、 页、 流文档和资源字典。 例如，可以设置[Application.StartupUri](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.startupuri)与包属性URI引用的窗口或你想要在应用程序启动时加载的页面。

```xaml
<Application
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    StartupUri="SOOPage.xaml" />
```

您可以执行操作时采用此XAML文件包含在Microsoft Build Engine (MSBuild)项目用作`Page`项。

```xml
<Project xmlns="http://schemas.microsoft.com/developer/msbuild/2003" ... >  
  ...  
  <ItemGroup>  
    <Page Include="MainWindow.xaml" />  
  </ItemGroup>  
  ...  
</Project>  
```

> 在中Visual Studio，添加一个新[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)， [NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)， [Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)， [FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)，或[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)到项目，`Build Action`的标记文件将默认为`Page`。

使用的项目时`Page`编译项目，XAML项转换为二进制格式，并将其编译到关联的程序集。 因此，可以像使用典型的资源文件一样使用这些文件。

> 如果XAML作为配置文件`Resource`项，并且没有代码隐藏文件，则原始XAML编译到程序集而不是原始的二进制版本XAML。

#### 内容文件

一个*的内容文件*作为松散文件与可执行程序集一起分发。 虽然它们不编译到程序集内，但编译程序集时所使用的元数据建立了与每个内容文件的关联。

如果应用程序需要一组特定的应用程序数据文件，并且你希望能够更新这些文件，而无需重新编译使用它们的程序集，应使用内容文件。

##### 配置内容文件

若要将内容文件添加到项目中，应用程序数据文件必须是作为包含`Content`项。 此外，因为内容文件不直接编译为程序集，您需要设置MSBuild`CopyToOutputDirectory`要指定内容文件复制到的位置相对于生成程序集的元数据元素。 如果所需资源复制到生成输出文件夹每次生成项目，则设置`CopyToOutputDirectory`元数据元素与`Always`值。 否则，可以确保，仅资源的最新版本复制到生成输出文件夹使用`PreserveNewest`值。

下面演示的是一个配置为内容文件的文件，此内容文件只有在将新版本的资源添加到项目时才会复制到生成输出文件夹。

```xml
<Project xmlns="http://schemas.microsoft.com/developer/msbuild/2003" ... >  
  ...  
  <ItemGroup>  
    <Content Include="ContentFile.xaml">  
      <CopyToOutputDirectory>PreserveNewest</CopyToOutputDirectory>  
    </Content>  
  </ItemGroup>  
  ...  
</Project>  
```

> 在Visual Studio，通过将文件添加到项目和设置创建一个内容文件，其`Build Action`到`Content`，并设置其`Copy to Output Directory`到`Copy always`(与相同`Always`) 和`Copy if newer`(与相同`PreserveNewest`)。

当生成项目时，[AssemblyAssociatedContentFileAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resources.assemblyassociatedcontentfileattribute)属性编译到程序集的每个内容文件的元数据。

```
[assembly: AssemblyAssociatedContentFile("ContentFile.xaml")]
```

值[AssemblyAssociatedContentFileAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resources.assemblyassociatedcontentfileattribute)意味着相对于其位置在项目中的内容文件的路径。 例如，如果内容文件位于项目子文件夹中，附加路径信息将合并到[AssemblyAssociatedContentFileAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resources.assemblyassociatedcontentfileattribute)值。

```
[assembly: AssemblyAssociatedContentFile("Resources/ContentFile.xaml")]
```

[AssemblyAssociatedContentFileAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resources.assemblyassociatedcontentfileattribute)值也是生成输出文件夹中的内容文件的路径的值。

##### 使用内容文件

若要加载的内容文件，可以调用[GetContentStream](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.getcontentstream)方法[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)类，并传入一个包URI，它标识所需的内容文件。 [GetContentStream](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.getcontentstream) 返回[StreamResourceInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resources.streamresourceinfo)对象，该文件内容作为公开[Stream](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.stream)并描述其内容类型。

例如，下面的代码演示如何使用[GetContentStream](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.getcontentstream)加载[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)内容文件，并将其设置为的内容[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)(`pageFrame`)。

```csharp
// Navigate to xaml page
Uri uri = new Uri("/PageContentFile.xaml", UriKind.Relative);
StreamResourceInfo info = Application.GetContentStream(uri);
System.Windows.Markup.XamlReader reader = new System.Windows.Markup.XamlReader();
Page page = (Page)reader.LoadAsync(info.Stream);
this.pageFrame.Content = page;
```

虽然通过调用[GetContentStream](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.getcontentstream)可以让您访问[Stream](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.stream)，您需要执行额外的工作来将其转换为将要设置其属性的类型。 相反，您可以让WPF负责打开和转换[Stream](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.stream)通过加载资源文件直接到使用代码的类型的属性。

下面的示例演示如何加载[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)直接[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)(`pageFrame`) 使用的代码。

```csharp
Uri pageUri = new Uri("/PageContentFile.xaml", UriKind.Relative);
this.pageFrame.Source = pageUri;
```

下面的示例是与上例等效的标记。

```xaml
<Frame Name="pageFrame" Source="PageContentFile.xaml" />
```

#### 源站点文件

资源文件有显式关系与它们一起分发的程序集由定义[AssemblyAssociatedContentFileAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resources.assemblyassociatedcontentfileattribute)。 但是，有些情况下可能需要在程序集和应用程序数据文件之间建立隐式关系或不存在的关系，这些情况包括：

- 在编译时不存在的文件。
- 在运行之前不知道程序集将需要哪些文件。
- 希望能够更新文件，无需重新编译与这些文件关联的程序集。
- 应用程序使用大型数据文件（如音频和视频），并且你希望仅在用户选择下载时才下载这些文件。

可以加载这些类型的文件使用的传统URI方案，如 file:/// 和 http:// 方案。

```xaml
<Image Source="file:///C:/DataFile.bmp" />
<Image Source="http://www.datafilewebsite.com/DataFile.bmp" />
```

但是，file:/// 和 http:// 方案要求应用程序具有完全信任。 如果应用程序是XAML 浏览器应用程序 (XBAP)启动从 Internet 或 intranet，并请求仅的允许从这些位置启动的应用程序的松散文件只能从原点 （应用程序的站点加载的权限集启动位置）。 此类文件称为*源站点的*文件。

虽然源站点文件并不仅限于部分信任应用程序，但这些文件是部分信任应用程序的唯一选择。 完全信任应用程序可能仍然需要加载它们在生成时所不知道的应用程序数据文件；但是完全信任应用程序可以使用 file:///，应用程序数据文件很可能将安装在该应用程序程序集所在的文件夹或其子文件夹中。 在此情况下，使用源站点引用比使用 file:/// 更加容易，因为使用 file:/// 需要找出文件的完整路径。

> 文件不会缓存使用的源站点的XAML 浏览器应用程序 (XBAP)客户端计算机，而内容文件却上。 因此，只有在专门请求下载源站点文件时，才会下载它们。 如果XAML 浏览器应用程序 (XBAP)应用程序具有大型媒体文件，因为源站点文件意味着初始应用程序启动速度更快，并且文件只会按需下载配置它们。

##### 配置源站点文件

如果在源站点文件在编译时是不存在或未知，则需要使用传统部署机制，用于确保所需的文件都可以在运行时，包括使用`XCopy`命令行程序或Microsoft Windows Installer.

如果您知道在编译时将如要放置于源站点的但仍想要避免显式依赖的文件，则可以添加到这些文件Microsoft Build Engine (MSBuild)项目用作`None`项。 因为与内容文件，您需要设置MSBuild`CopyToOutputDirectory`属性来指定源站点文件复制到的位置相对于生成的程序集，通过指定`Always`值或`PreserveNewest`值。

```xml
<Project xmlns="http://schemas.microsoft.com/developer/msbuild/2003" ... >  
  ...  
  <None Include="PageSiteOfOriginFile.xaml">  
    <CopyToOutputDirectory>Always</CopyToOutputDirectory>  
  </None>  
  ...  
</Project>  
```

> 在中Visual Studio，你创建原始文件的一个站点将文件添加到项目并设置其`Build Action`到`None`。

当生成项目时，MSBuild将指定的文件复制到生成输出文件夹。

##### 使用源站点文件

若要加载源站点文件，可以调用[GetRemoteStream](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.getremotestream)方法[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)类，并传入一个包URI标识的原始文件所需的站点。 [GetRemoteStream](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.getremotestream) 返回[StreamResourceInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resources.streamresourceinfo)对象，它提供了源站点文件作为[Stream](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.stream)并描述其内容类型。

例如，下面的代码演示如何使用[GetRemoteStream](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.getremotestream)加载[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)源站点的文件，并将其设置为的内容[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)(`pageFrame`)。

```csharp
// Navigate to xaml page
Uri uri = new Uri("/SiteOfOriginFile.xaml", UriKind.Relative);
StreamResourceInfo info = Application.GetRemoteStream(uri);
System.Windows.Markup.XamlReader reader = new System.Windows.Markup.XamlReader();
Page page = (Page)reader.LoadAsync(info.Stream);
this.pageFrame.Content = page;
```

虽然通过调用[GetRemoteStream](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.getremotestream)可以让您访问[Stream](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.stream)，您需要执行额外的工作来将其转换为将要设置其属性的类型。 相反，您可以让WPF负责打开和转换[Stream](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.stream)通过加载资源文件直接到使用代码的类型的属性。

下面的示例演示如何加载[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)直接[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)(`pageFrame`) 使用的代码。

```csharp
Uri pageUri = new Uri("pack://siteoforigin:,,,/SiteOfOriginFile.xaml", UriKind.Absolute);
this.pageFrame.Source = pageUri;
```

下面的示例是与上例等效的标记。

```xaml
<Frame Name="pageFrame" Source="pack://siteoforigin:,,,/SiteOfOriginFile.xaml" />
```

#### 更改生成类型后重新生成

在更改应用程序数据文件的生成类型后，需要重新生成整个应用程序以确保应用这些更改。 如果只生成应用程序，则不会应用更改。

## [Pack URIs in WPF](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/pack-uris-in-wpf)

在 Windows Presentation Foundation (WPF)统一资源标识符 (URI)用于标识和加载在许多方面，包括以下文件：

- 指定用户界面 (UI)以显示应用程序首次启动时。
- 加载图像。
- 导航到页。
- 加载不可执行的数据文件。

此外，URI可用于标识和加载不同的位置，包括以下文件：

- 当前程序集。
- 引用的程序集。
- 相对于程序集的某个位置。
- 应用程序的源站点。

若要标识和从这些位置加载这些类型的文件提供一致的机制WPF利用的可扩展性*pack URI 方案*。 本主题提供的方案的概述，介绍了如何构造 packURI的各种方案，讨论绝对和相对URI并URI解析，然后说明如何使用包URI从这两个标记和代码。

#### Pack URI 方案

包URI通过使用方案[开放打包约定](https://go.microsoft.com/fwlink/?LinkID=71255)(OPC) 规范，描述用于组织和标识内容的模型。 此模型的关键元素是包和部件，其中*包*是逻辑容器，一个或多个逻辑*部件*。 下图阐释了此概念。

![包和部件关系图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/wpfpackurischemefigure1.png)

为了标识部件，OPC 规范利用 RFC 2396 扩展性 (统一资源标识符 (URI):一般语法） 来定义 packURI方案。

由指定的方案URI由其前缀; 定义 http、 ftp 和 file 是众所周知的示例。 包URI方案作为其方案中，使用"包"，并包含两个组件： 授权和路径。 下面是包的格式URI。

pack://*authority*/*path*

*颁发机构*指定的类型，由包含部件的包时*路径*指定部件在包中的位置。

下图阐释了此概念：

![包、授权与路径之间的关系](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/wpfpackurischemefigure2.png)

包和部件之间的关系类似于应用程序和文件之间的关系，其中应用程序（包）可以包含一个或多个文件（部件），包括：

- 编译到本地程序集内的资源文件。
- 编译到所引用的程序集内的资源文件。
- 编译到引用程序集内的资源文件。
- 内容文件。
- 源站点文件。

若要访问这些类型的文件，WPF支持两种授权： 应用程序: / / 和 siteoforigin:///: / /。 application:/// 授权标识在编译时已知的应用程序数据文件，包括资源文件和内容文件。 siteoforigin:/// 授权标识源站点文件。 下图显示了每种授权的范围。

![Pack URI 关系图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/wpfpackurischemefigure4.png)

> 包的证书颁发机构部分URI是一个嵌入式URI的指向包并且必须符合 RFC 2396。 另外，必须用字符“,”替换字符“/”，并且必须对保留字符（如“%”和“?”）进行转义。 有关详细信息，请参阅 OPC。

以下各节说明如何构造 packURI与相应的路径结合使用这两种授权，用于标识资源、 内容和源站点文件。



#### 资源文件 Pack URI

资源文件配置为MSBuild`Resource`项并编译到程序集。 WPF 支持包构造URI可以用于标识资源文件编译到本地程序集或编译到从本地程序集引用的程序集。



##### 本地程序集资源文件

包URI资源编译到本地程序集的文件使用以下授权和路径：

- **授权**：application:///。
- **路径**:资源文件，包括其路径，相对于本地程序集项目文件夹根目录的名称。

下面的示例演示了包URI为XAML位于本地程序集的项目文件夹的根目录中的资源文件。

```
pack://application:,,,/ResourceFile.xaml
```

下面的示例演示了包URI为XAML位于本地程序集的项目文件夹的子文件夹中的资源文件。

```
pack://application:,,,/Subfolder/ResourceFile.xaml
```

##### 引用的程序集资源文件

包URI资源编译到引用的程序集中的文件使用以下授权和路径：

- **授权**：application:///。

- **路径**:资源文件编译到引用的程序集的名称。 路径必须符合以下格式：

  *AssemblyShortName*{*;Version*]{*;PublicKey*];component/*Path*

  - **程序集短名称**：所引用的程序集的短名称。
  - **;版本** [可选]：所引用的包含资源文件的程序集的版本。 此部分在加载两个或多个具有相同短名称的引用程序集时使用。
  - **;公钥** [可选]：用于对引用程序集进行签名的公钥。 此部分在加载两个或多个具有相同短名称的引用程序集时使用。
  - **;组件**：指定所引用的程序集是从本地程序集引用的。
  - **/路径**：资源文件的名称，包括其相对于所引用程序集的项目文件夹根目录的路径。

下面的示例演示了包URI为XAML位于引用程序集的项目文件夹的根目录中的资源文件。

```
pack://application:,,,/ReferencedAssembly;component/ResourceFile.xaml
```

下面的示例演示了包URI为XAML位于被引用程序集的项目文件夹的子文件夹中的资源文件。

```
pack://application:,,,/ReferencedAssembly;component/Subfolder/ResourceFile.xaml
```

下面的示例演示了包URI为XAML位于引用的、 特定于版本的程序集的项目文件夹的根文件夹中的资源文件。

```
pack://application:,,,/ReferencedAssembly;v1.0.0.1;component/ResourceFile.xaml
```

请注意，包URI引用的程序集资源文件的语法可以仅用于应用程序: / / 颁发机构。 例如，以下不支持在WPF。

```
pack://siteoforigin:,,,/SomeAssembly;component/ResourceFile.xaml
```

#### 内容文件 Pack URI

包URI内容文件使用以下授权和路径：

- **授权**：application:///。
- **路径**:内容文件，包括其相对于应用程序的主可执行程序集的文件系统位置的路径名称。

下面的示例演示了包URI为XAML位于可执行程序集所在的文件夹中的内容文件。

```
pack://application:,,,/ContentFile.xaml
```

下面的示例演示了包URI为XAML内容文件位于相对于应用程序的可执行程序集的子文件夹中。

```
pack://application:,,,/Subfolder/ContentFile.xaml
```

> 无法导航到 HTML 内容文件。 URI方案仅支持导航到HTML位于源站点的文件。

#### 源站点 Pack URI

包URI为源站点文件使用以下授权和路径：

- **授权**：siteoforigin:///。
- **路径**:源站点文件，包括其相对于从中启动可执行程序集位置的路径的名称。

下面的示例演示了包URI为XAML源站点文件，存储在从中启动可执行程序集的位置。

```
pack://siteoforigin:,,,/SiteOfOriginFile.xaml
```

下面的示例演示了包URI为XAML源站点文件，存储在相对于从中启动应用程序的可执行程序集位置的子文件夹。

```
pack://siteoforigin:,,,/Subfolder/SiteOfOriginFile.xaml
```

#### 页面文件

XAML 为配置文件MSBuild`Page`项被编译到程序集资源文件的方式相同。 因此， MSBuild `Page`可以使用包标识项URI资源文件。

类型XAML通常被配置为文件MSBuild`Page`项具有以下内容作为其根元素之一：

- [System.Windows.Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)
- [System.Windows.Controls.Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)
- [System.Windows.Navigation.PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)
- [System.Windows.ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)
- [System.Windows.Documents.FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)
- [System.Windows.Controls.UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol)

#### 绝对与相对 Pack URI

完全限定的 packURI包括方案、 授权和路径，且将其视为绝对 pack URI。 作为面向开发人员，简化XAML元素通常允许您设置相应的属性的相对 pack URI，其中仅包含路径。

例如，考虑具有以下绝对 packURI本地程序集内的资源文件。

```
pack://application:,,,/ResourceFile.xaml
```

相对 pack URI ，是指此资源文件将如下所示。

```
/ResourceFile.xaml
```

> 由于源站点文件不与程序集相关联，因此它们可以仅引用使用绝对 pack URI。

默认情况下，相对 packURI被视为相对于标记或包含引用的代码的位置。 但是，如果使用前导反斜杠，则将相对 packURI引用视为相对于应用程序的根。 例如，假设具有以下项目结构。

```
App.xaml
Page2.xaml
\SubFolder
+ Page1.xaml
+ Page2.xaml
```

如果 Page1.xaml 包含URI引用*根*\SubFolder\Page2.xaml，该引用可以使用以下相对 pack URI。

```
Page2.xaml
```

如果 Page1.xaml 包含URI引用*根*\Page2.xaml，该引用可以使用以下相对 pack URI。

```
/Page2.xaml
```

#### Pack URI 解析

包的格式URI使得包URI对于不同类型的文件看起来相同。 例如，考虑具有以下绝对 pack URI。

```
pack://application:,,,/ResourceOrContentFile.xaml
```

此绝对 packURI无法引用本地程序集内的资源文件或内容文件。 同样适用于以下相对URI。

```
/ResourceOrContentFile.xaml
```

为了确定的类型文件的 packURI指的是，WPF解析URI本地程序集和内容文件使用以下试探方法内的资源文件：

1. 探测程序集的元数据[AssemblyAssociatedContentFileAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resources.assemblyassociatedcontentfileattribute)匹配的包属性URI。
2. 如果[AssemblyAssociatedContentFileAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resources.assemblyassociatedcontentfileattribute)找到属性，包的路径URI引用的内容文件。
3. 如果[AssemblyAssociatedContentFileAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resources.assemblyassociatedcontentfileattribute)找不到属性，探测编译到本地程序集的集资源文件。
4. 如果匹配的包的路径的资源文件URI找到，则包的路径URI引用的资源文件。
5. 如果未找到资源，在内部创建[Uri](https://docs.microsoft.com/zh-cn/dotnet/api/system.uri)无效。

URI 解析不适用于URI参阅以下内容：

- 引用的程序集内的内容文件： 这些文件类型不受WPF。
- 嵌入的文件中引用的程序集：URI标识这些是唯一的因为它们包括这两个引用的程序集的名称和`;component`后缀。
- 源站点文件：URI标识这些是唯一的因为它们是由包的唯一文件URI包含 siteoforigin:/// 授权: / / 颁发机构。

包的一种简化形式URI解析使是让代码在某种程度上独立于资源和内容文件的位置。 例如，如果有本地程序集重新配置为内容文件，包中的资源文件URI的资源将保持不变，可使用包的代码一样URI。

#### 使用 Pack URI 编程

许多WPF类实现可设置与包属性的URI，其中包括：

- [Application.StartupUri](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.startupuri)
- [Frame.Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame.source)
- [NavigationWindow.Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow.source)
- [Hyperlink.NavigateUri](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink.navigateuri)
- [Window.Icon](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.icon)
- [Image.Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image.source)

可以从标记和代码中设置这些属性。 本节演示这两种设置方式的基本构造，然后演示通用方案示例。

##### 在标记中使用 Pack URI

一个包URI通过设置包具有的属性元素标记中指定URI。 例如：

```
<element attribute="pack://application:,,,/File.xaml" />
```

- 各种绝对 pack URI ，可以在标记中指定。
- 在标记中的绝对 Pack Uri

| 文件                               | 绝对 pack URI                                                |
| ---------------------------------- | ------------------------------------------------------------ |
| 资源文件 - 本地程序集              | `"pack://application:,,,/ResourceFile.xaml"`                 |
| 子文件夹中的资源文件 - 本地程序集  | `"pack://application:,,,/Subfolder/ResourceFile.xaml"`       |
| 资源文件 - 引用的程序集            | `"pack://application:,,,/ReferencedAssembly;component/ResourceFile.xaml"` |
| 所引用程序集的子文件夹中的资源文件 | `"pack://application:,,,/ReferencedAssembly;component/Subfolder/ResourceFile.xaml"` |
| 所引用版本化程序集中的资源文件     | `"pack://application:,,,/ReferencedAssembly;v1.0.0.0;component/ResourceFile.xaml"` |
| 内容文件                           | `"pack://application:,,,/ContentFile.xaml"`                  |
| 子文件夹中的内容文件               | `"pack://application:,,,/Subfolder/ContentFile.xaml"`        |
| 源站点文件                         | `"pack://siteoforigin:,,,/SOOFile.xaml"`                     |
| 子文件夹中的源站点文件             | `"pack://siteoforigin:,,,/Subfolder/SOOFile.xaml"`           |

表 2 说明了各种相对 pack URI ，可以在标记中指定。

表 2:在标记中的相对 Pack Uri

| 文件                               | 相对 pack URI                                                |
| ---------------------------------- | ------------------------------------------------------------ |
| 本地程序集内的资源文件             | `"/ResourceFile.xaml"`                                       |
| 本地程序集的子文件夹中的资源文件   | `"/Subfolder/ResourceFile.xaml"`                             |
| 所引用程序集内的资源文件           | `"/ReferencedAssembly;component/ResourceFile.xaml"`          |
| 所引用程序集的子文件夹中的资源文件 | `"/ReferencedAssembly;component/Subfolder/ResourceFile.xaml"` |
| 内容文件                           | `"/ContentFile.xaml"`                                        |
| 子文件夹中的内容文件               | `"/Subfolder/ContentFile.xaml"`                              |

##### 在代码中使用 Pack URI

指定包URI在代码中通过实例化[Uri](https://docs.microsoft.com/zh-cn/dotnet/api/system.uri)类并传递包URI作为构造函数的参数。 下面的示例说明了这一点。

```csharp
Uri uri = new Uri("pack://application:,,,/File.xaml");  
```

默认情况下[Uri](https://docs.microsoft.com/zh-cn/dotnet/api/system.uri)类将 packURI以是绝对路径。 因此，引发异常的实例时[Uri](https://docs.microsoft.com/zh-cn/dotnet/api/system.uri)类创建的相对 pack URI。

```csharp
Uri uri = new Uri("/File.xaml");  
```

幸运的是，[Uri(String, UriKind)](https://docs.microsoft.com/zh-cn/dotnet/api/system.uri.-ctor#System_Uri__ctor_System_String_System_UriKind_)的重载[Uri](https://docs.microsoft.com/zh-cn/dotnet/api/system.uri)类构造函数接受类型的参数[UriKind](https://docs.microsoft.com/zh-cn/dotnet/api/system.urikind)允许您指定是否将包URI是绝对或相对。

```csharp
// Absolute URI (default)  
Uri absoluteUri = new Uri("pack://application:,,,/File.xaml", UriKind.Absolute);  
// Relative URI  
Uri relativeUri = new Uri("/File.xaml",   
                        UriKind.Relative);  
```

应仅指定[Absolute](https://docs.microsoft.com/zh-cn/dotnet/api/system.urikind#System_UriKind_Absolute)或[Relative](https://docs.microsoft.com/zh-cn/dotnet/api/system.urikind#System_UriKind_Relative)您可以确信所提供的 packURI是一个或另一个。 如果不知道包的类型URI，使用，例如当用户输入 packURI在运行时，使用[RelativeOrAbsolute](https://docs.microsoft.com/zh-cn/dotnet/api/system.urikind#System_UriKind_RelativeOrAbsolute)相反。

```csharp
// Relative or Absolute URI provided by user via a text box  
TextBox userProvidedUriTextBox = new TextBox();  
Uri uri = new Uri(userProvidedUriTextBox.Text, UriKind.RelativeOrAbsolute);  
```

- 各种相对 pack URI ，可以使用在代码中指定[System.Uri](https://docs.microsoft.com/zh-cn/dotnet/api/system.uri)。

- 在代码中的绝对 Pack Uri

| 文件                               | 绝对 pack URI                                                |
| ---------------------------------- | ------------------------------------------------------------ |
| 资源文件 - 本地程序集              | `Uri uri = new Uri("pack://application:,,,/ResourceFile.xaml", UriKind.Absolute);` |
| 子文件夹中的资源文件 - 本地程序集  | `Uri uri = new Uri("pack://application:,,,/Subfolder/ResourceFile.xaml", UriKind.Absolute);` |
| 资源文件 - 引用的程序集            | `Uri uri = new Uri("pack://application:,,,/ReferencedAssembly;component/ResourceFile.xaml", UriKind.Absolute);` |
| 所引用程序集的子文件夹中的资源文件 | `Uri uri = new Uri("pack://application:,,,/ReferencedAssembly;component/Subfolder/ResourceFile.xaml", UriKind.Absolute);` |
| 所引用版本化程序集中的资源文件     | `Uri uri = new Uri("pack://application:,,,/ReferencedAssembly;v1.0.0.0;component/ResourceFile.xaml", UriKind.Absolute);` |
| 内容文件                           | `Uri uri = new Uri("pack://application:,,,/ContentFile.xaml", UriKind.Absolute);` |
| 子文件夹中的内容文件               | `Uri uri = new Uri("pack://application:,,,/Subfolder/ContentFile.xaml", UriKind.Absolute);` |
| 源站点文件                         | `Uri uri = new Uri("pack://siteoforigin:,,,/SOOFile.xaml", UriKind.Absolute);` |
| 子文件夹中的源站点文件             | `Uri uri = new Uri("pack://siteoforigin:,,,/Subfolder/SOOFile.xaml", UriKind.Absolute);` |

- 各种相对 packURI你可以指定在代码中使用[System.Uri](https://docs.microsoft.com/zh-cn/dotnet/api/system.uri)。

- 在代码中的相对 Pack Uri

| 文件                                | 相对 pack URI                                                |
| ----------------------------------- | ------------------------------------------------------------ |
| 资源文件 - 本地程序集               | `Uri uri = new Uri("/ResourceFile.xaml", UriKind.Relative);` |
| 子文件夹中的资源文件 - 本地程序集   | `Uri uri = new Uri("/Subfolder/ResourceFile.xaml", UriKind.Relative);` |
| 资源文件 - 引用的程序集             | `Uri uri = new Uri("/ReferencedAssembly;component/ResourceFile.xaml", UriKind.Relative);` |
| 子文件夹中的资源文件 - 引用的程序集 | `Uri uri = new Uri("/ReferencedAssembly;component/Subfolder/ResourceFile.xaml", UriKind.Relative);` |
| 内容文件                            | `Uri uri = new Uri("/ContentFile.xaml", UriKind.Relative);`  |
| 子文件夹中的内容文件                | `Uri uri = new Uri("/Subfolder/ContentFile.xaml", UriKind.Relative);` |

##### 常见 Pack URI 方案

前面几节讨论了如何构造 packURI来标识资源、 内容和源站点文件。 在WPF、 中有许多种情况下，使用这些构造和以下部分介绍了几种常见用法。

##### 指定当应用程序启动时显示的 UI

[StartupUri](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.startupuri) 指定第一个UI时显示WPF启动应用程序。 对于独立应用程序，UI可以是一个窗口，如下面的示例中所示。

```xaml
<Application
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    StartupUri="MainWindow.xaml" />
```

独立应用程序和XAML 浏览器应用程序 (XBAP)还可以指定页为初始 UI，如下面的示例中所示。

```xaml
<Application
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    StartupUri="HomePage.xaml" />
```

如果应用程序是一个独立应用程序并使用指定了一个页面[StartupUri](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.startupuri)，WPF将打开[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)以承载该页面。 有关XBAP，主机浏览器中显示了页。

##### 导航到页面

下面的示例演示如何导航到页面。

```xaml
<Page
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  WindowTitle="Page With Hyperlink"
  WindowWidth="250"
  WindowHeight="250">
```

```xaml
<Hyperlink NavigateUri="UriOfPageToNavigateTo.xaml">
  Navigate to Another Page
</Hyperlink>
```

```xaml
</Page>
```

有关详细信息中导航的各种方法WPF，请参阅[导航概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-overview)。

##### 指定窗口图标

下面的示例演示如何使用 URI 指定窗口的图标。

```xaml
<Window
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  x:Class="SDKSample.MainWindow"
    Icon="WPFIcon1.ico">
</Window>
```

有关详细信息，请参阅 [Icon](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.icon)。

##### 加载图像、音频和视频文件

WPF 允许应用程序使用各种媒体类型，所有这些都可以标识和加载与包URI，如下面的示例中所示。

```xaml
<MediaElement Stretch="Fill" LoadedBehavior="Play" Source="pack://siteoforigin:,,,/Media/bee.wmv" />
```

```xaml
<MediaElement Stretch="Fill" LoadedBehavior="Play" Source="pack://siteoforigin:,,,/Media/ringin.wav" />
```

```xaml
<Image Source="Images/Watermark.png" />
```

使用媒体内容的详细信息，请参阅[图形和多媒体](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/index)。

##### 从源站点加载资源字典

资源字典 ([ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)) 可用于支持应用程序的主题。 创建和管理主题的一种方式是将多个主题创建为位于应用程序源站点的资源字典。 这样，在添加和更新主题时将无需重新编译和重新部署应用程序。 这些资源字典可以标识和使用包加载URI，下面的示例所示。

```xaml
<Application
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    StartupUri="HomePage.xaml">
  <Application.Resources>
    <ResourceDictionary Source="pack://siteoforigin:,,,/PageTheme.xaml" />
  </Application.Resources>
</Application>
```

有关中的主题的概述WPF，请参阅[样式和模板化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/styling-and-templating)。

## [Add a Splash Screen to a WPF Application](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/how-to-add-a-splash-screen-to-a-wpf-application)

本主题演示如何将添加一个启动窗口中，或*初始屏幕*，到 Windows Presentation Foundation (WPF) 应用程序。

#### 若要将现有映像添加为初始屏幕

1. 创建或查找想要用于初始屏幕的图像。 可以使用任何支持的 Windows Imaging Component (WIC) 的图像格式。 例如，可以使用 BMP、 GIF、 JPEG、 PNG 或 TIFF 格式。

2. 将图像文件添加到 WPF 应用程序项目。

3. 在中**解决方案资源管理器**，选择的映像。

4. 在属性窗口中，单击下拉箭头**生成操作**属性。

5. 选择**初始屏幕**从下拉列表。

6. 按 F5 生成并运行该应用程序。

   初始屏幕图像显示在屏幕上，在中心，然后淡主应用程序窗口出现时。

#### 若要从生成中排除的初始屏幕

1. 在中**解决方案资源管理器**，选择初始屏幕图像。
2. 在中**属性**窗口中，将**生成操作**到**None**。

#### 若要删除从应用程序的初始屏幕

在中**解决方案资源管理器**，删除初始屏幕图像。

## [Use an Application-Scope Resource Dictionary](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/how-to-use-an-application-scope-resource-dictionary)

本示例显示如何定义和使用应用程序范围的自定义资源字典。

#### 示例

[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application) 公开共享资源的应用程序作用域存储： [Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.resources)。 默认情况下[Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.resources)属性使用的实例初始化[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)类型。 可以使用此实例时获取和设置应用程序作用域属性使用[Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.resources)。 有关详细信息，请参阅[如何：获取和设置应用程序范围资源](https://msdn.microsoft.com/library/39e0420c-c9fc-47dc-8956-fdd95b214095)。

如果必须使用设置的多个资源[Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.resources)，而是可以使用自定义资源字典来存储这些资源和设置[Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.resources)与之相反。 下面演示如何声明使用 XAML 的自定义资源字典。

```xaml
<ResourceDictionary 
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml" >
    <SolidColorBrush x:Key="StandardSolidColorBrush" Color="Blue" />
    <LinearGradientBrush x:Key="StandardLinearGradientBrush" StartPoint="0.0,0.0" EndPoint="1.0,1.0">
        <LinearGradientBrush.GradientStops>
            <GradientStop Color="White" Offset="0" />
            <GradientStop Color="Black" Offset="1" />
        </LinearGradientBrush.GradientStops>
    </LinearGradientBrush>
</ResourceDictionary>
```

交换使用整个资源字典[Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.resources)使您能够支持应用程序范围的主题，其中每个主题封装由单个资源字典。 下面的示例演示如何设置 [ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)。

```xaml
<!--Set the Application ResourceDictionary-->
<Application.Resources>
    <ResourceDictionary Source="MyResourceDictionary.xaml" />
</Application.Resources>
```

下面演示了如何从通过公开的资源字典获取应用程序范围资源[Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.resources)在 XAML 中。

```xaml
<!--Set the brush as a StaticResource from the ResourceDictionary-->
<Rectangle Name="Rect" Height="200" Width="100" Fill="{StaticResource ResourceKey=StandardSolidColorBrush}" />
```

以下内容显示如何也能获取代码中的资源。

```csharp
//Get a resource from the ResourceDictionary in code
Brush gradientBrush = (Brush)Application.Current.FindResource("StandardLinearGradientBrush");
```

有两个注意事项，以便使用[Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.resources)。 首先，字典*密钥*是一个对象，因此必须使用完全相同的对象实例时设置和获取属性值。 （请注意，使用字符串时键区分大小写。）其次，字典*值*是一个对象，因此必须将值转换为所需的类型，获取属性值时。

## [Persist and Restore Application-Scope Properties Across Application Sessions](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/persist-and-restore-application-scope-properties)

此示例演示如何保留应用程序关闭时，以及如何还原应用程序作用域属性时应用程序下一步是启动应用程序作用域属性。

#### 示例

应用程序仍然存在，应用程序作用域属性，并将其还原从独立存储。 独立的存储是由没有文件访问权限的应用程序可以安全使用的受保护的存储区域。 *App.xaml*文件定义`App_Startup`为处理程序方法[Application.Startup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.startup)事件，并且`App_Exit`为处理程序方法[Application.Exit](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.exit)事件，如突出显示的行的第一个示例中所示。 第二个示例显示了部分*App.xaml.cs*并*App.xaml.vb*突出显示的代码文件`App_Startup`方法，后者将恢复应用程序作用域属性和`App_Exit`方法，将保存应用程序范围的属性。

```xaml
<Application
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.App"
    StartupUri="MainWindow.xaml" 
    Startup="App_Startup" 
    Exit="App_Exit">
    <Application.Resources>
        <SolidColorBrush x:Key="ApplicationScopeResource" Color="White"></SolidColorBrush>
    </Application.Resources>
</Application>
```

```csharp
using System.Windows;
using System.IO;
using System.IO.IsolatedStorage;

namespace SDKSample
{
    public partial class App : Application
    {
        string filename = "App.txt";

        public App()
        {
            // Initialize application-scope property
            this.Properties["NumberOfAppSessions"] = 0;
        }

        private void App_Startup(object sender, StartupEventArgs e)
        {
            // Restore application-scope property from isolated storage
            IsolatedStorageFile storage = IsolatedStorageFile.GetUserStoreForDomain();
            try
            {
                using (IsolatedStorageFileStream stream = new IsolatedStorageFileStream(filename, FileMode.Open, storage))
                using (StreamReader reader = new StreamReader(stream))
                {
                    // Restore each application-scope property individually
                    while (!reader.EndOfStream)
                    {
                        string[] keyValue = reader.ReadLine().Split(new char[] {','});
                        this.Properties[keyValue[0]] = keyValue[1];
                    }
                }
            }
            catch (FileNotFoundException ex)
            {
                // Handle when file is not found in isolated storage:
                // * When the first application session
                // * When file has been deleted
            }
        }

        private void App_Exit(object sender, ExitEventArgs e)
        {
            // Persist application-scope property to isolated storage
            IsolatedStorageFile storage = IsolatedStorageFile.GetUserStoreForDomain();
            using (IsolatedStorageFileStream stream = new IsolatedStorageFileStream(filename, FileMode.Create, storage))
            using (StreamWriter writer = new StreamWriter(stream))
            {
                // Persist each application-scope property individually
                foreach (string key in this.Properties.Keys)
                {
                    writer.WriteLine("{0},{1}", key, this.Properties[key]);
                }
            }
        }
    }
}
```