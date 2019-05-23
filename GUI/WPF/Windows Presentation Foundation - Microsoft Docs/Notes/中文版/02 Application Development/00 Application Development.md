# [Application Development](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/)

Windows Presentation Foundation (WPF) 是一个演示框架，可用于开发以下类型的应用程序：

- 独立应用程序（传统风格的 Windows 应用程序，这些应用程序作为要安装到客户端计算机并从客户端计算机运行的可执行程序集来生成）。
- XAML 浏览器应用程序 (XBAP)（由导航页组成的应用程序，这些应用程序作为可执行程序集生成并由 Web 浏览器（如 Microsoft Internet Explorer 或 Mozilla Firefox）承载）。
- 自定义控件库（包含可重用控件的非可执行程序集）。
- 类库（包含可重用类的非可执行程序集）。

> 强烈建议不要在 Windows 服务中使用 WPF 类型。 如果尝试在 Windows 服务中使用这些功能，这些功能可能无法按预期工作。

为了生成这样一组应用程序，WPF 要实现众多服务。 本主题对这些服务以及在何处可以找到更多相关信息进行了概述。

## 应用程序管理

可执行的 WPF 应用程序通常需要实现一组核心功能，其中包括：

- 创建和管理常见的应用程序基础结构（包括创建入口点方法和 Windows 消息循环，以接收系统和输入消息）。
- 对应用程序的生存期进行跟踪并与之进行交互。
- 检索和处理命令行参数。
- 共享应用程序范围的属性和 UI 资源。
- 检测和处理未经处理的异常。
- 返回退出代码。
- 管理独立应用程序中的窗口。
- 跟踪 XAML 浏览器应用程序 (XBAP) 以及使用导航窗口和框架的独立应用程序中的导航。

以上功能由通过*应用程序定义*添加到应用程序的 [Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application) 类来实现。

有关详细信息，请参阅[应用程序管理概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/application-management-overview)。

## WPF 应用程序资源、内容和数据文件

WPF 扩展支持三种类型的非可执行文件数据文件中嵌入的资源 Microsoft.NET Framework 的核心支持： 资源、 内容和数据。 有关详细信息，请参阅 [WPF 应用程序资源、内容和数据文件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/wpf-application-resource-content-and-data-files)。

在对于 WPF 非可执行数据文件的众多支持中，其中的一项重要支持就是能够通过唯一的 URI 来识别和加载这些文件。 有关详细信息，请参阅 [WPF 中的 Pack URI](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/pack-uris-in-wpf)。

## 窗口和对话框

用户通过窗口与 WPF 独立应用程序交互。 窗口旨在托管应用程序内容并提供通常允许用户与内容交互的应用程序功能。 在 WPF 中，通过 [Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window) 类封装窗口，该类支持：

- 创建和显示窗口。
- 建立所有者/所拥有窗口关系。
- 配置窗口外观（例如，大小、位置、图标、标题栏文本、边框）。
- 对窗口的生存期进行跟踪并与之进行交互。

有关详细信息，请参阅 [WPF 窗口概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/wpf-windows-overview)。

[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window) 支持用于创建被称为对话框的特殊窗口类型的功能。 可以创建两种类型的对话框，即模式和无模式对话框。

为方便起见和可重用性和跨应用程序、 一致的用户体验的优点WPF会公开三个常见的 Windows 对话框：[OpenFileDialog](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.win32.openfiledialog)， [SaveFileDialog](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.win32.savefiledialog)，和[PrintDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.printdialog)。

消息框是一种特殊类型的对话框，用于向用户显示重要的文本信息并询问简单的“是/否/确定/取消”问题。 使用 [MessageBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.messagebox) 类创建并显示消息框。

有关详细信息，请参阅[对话框概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/dialog-boxes-overview)。

## 导航

WPF 支持使用页面 ([Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)) 和超链接 ([Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)) 进行Web 式导航。 导航可以通过多种方式来实现，其中包括：

- 在 Web 浏览器中承载的独立页面。
- 被编译到 XBAP 中并在 Web 浏览器中承载的页面。
- 被编译到独立应用程序中并由导航窗口 ([NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)) 承载的页面。
- 由框架 ([Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)) 承载的页面（可能在独立页面中承载），或是被编译到 XBAP 或独立应用程序中的页面。

为了便于导航，WPF 实现了：

- [NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)，供 [Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)、[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow) 和 XBAP 用于处理导航请求以支持应用程序内导航的共享导航引擎。
- 用于启动导航的导航方法。
- 各种导航事件，用于对导航的生存期进行跟踪并与之进行交互。
- 记住通过日志实现的后向和前向导航，还可以检查和操控这些导航。

有关信息，请参阅[导航概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-overview)。

WPF 还支持一种被称为结构化导航的特殊导航类型。 结构化导航可用于调用一个或多个页面，这些页面能以结构化的可预测方式返回与调用函数一致的数据。 此功能将取决于 [PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1) 类；有关该类的进一步描述，请参阅[结构化导航概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/structured-navigation-overview)。 [PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1) 还可用于简化[导航拓扑概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-topologies-overview)中所述的复杂导航拓扑的创建。

## 宿主

XBAP 可以在 Microsoft Internet Explorer 或 Firefox 中承载。 每个承载模型都有各自的一些注意事项和约束，这些内容在[承载](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/hosting-wpf-applications)中均有涵盖。

## 生成和部署

尽管简单的 WPF 应用程序可以在命令提示符下使用命令行编译器来生成，但 WPF 仍与 Microsoft Visual Studio 实现了集成以提供简化了开发和生成过程的额外支持。 有关详细信息，请参阅[生成 WPF 应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/building-a-wpf-application-wpf)。

根据所生成的应用程序类型，会有一个或多个部署选项可供选择。 有关详细信息，请参阅[部署 WPF 应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/deploying-a-wpf-application-wpf)。