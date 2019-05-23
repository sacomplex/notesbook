# [Hosting](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/hosting-wpf-applications)

WPF XAML 浏览器应用程序 (Xbap) 是胖客户端应用程序可以部署到 Web 服务器并在浏览器中启动。 WPF 主机 (PresentationHost.exe) 注册为 shell 和 MIME XBAP 和 XAML 文件的处理程序。 因此，Internet Explorer 知道 XBAP 启动时启动 WPF 主机。 Firefox 用户可以安装到主机 Xbap 以及启用 Firefox 的 Firefox 外接程序。 XBAP 可以通过使用 wpf 的本机浏览器托管 Api 提供托管在其他浏览器或独立的应用程序。

## 本节内容

[WPF XAML Browser Applications Overview](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/wpf-xaml-browser-applications-overview)（WPF XAML 浏览器应用程序概述）
[WPF 主机 (PresentationHost.exe)](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/wpf-host-presentationhost-exe)
[支持 .NET 应用程序部署的 Firefox 加载项](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/firefox-add-ons-to-support-net-application-deployment)
[托管支持 API 的本机 WPF 浏览器](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/native-wpf-browser-hosting-support-apis)

## [WPF XAML Browser Applications Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/wpf-xaml-browser-applications-overview)

XAML 浏览器应用程序 (XBAP) Web 应用程序和丰富的客户端应用程序的功能组合在一起。 与 Web 应用程序类似，可以将 XBAP 部署到 Web 服务器并从 Internet Explorer 或 Firefox 启动。 类似于丰富客户端应用程序，Xbap 可以充分利用 WPF 的功能。 开发 XBAP 也与开发丰富客户端类似。 本主题提供简单、高级的 XBAP 开发简介，并介绍 XBAP 开发与标准的丰富客户端开发的不同之处。

本主题包含以下各节：

- [创建新的 XAML 浏览器应用程序 (XBAP)](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/wpf-xaml-browser-applications-overview#creating_a_new_xaml_browser_application_xbap)
- [部署 XBAP](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/wpf-xaml-browser-applications-overview#deploying_a_xbap)
- [与宿主网页通信](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/wpf-xaml-browser-applications-overview#communicating_with_the_host_web_page)
- [XBAP 安全注意事项](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/wpf-xaml-browser-applications-overview#xbap_security_considerations)
- [XBAP 启动时间性能注意事项](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/wpf-xaml-browser-applications-overview#xbap_start_time_performance_considerations)

### 创建新的 XAML 浏览器应用程序 (XBAP)

创建新的 XBAP 项目的最简单方法是使用 Microsoft Visual Studio。 创建新项目时，从模板列表中选择“WPF 浏览器应用程序”。 有关详细信息，请参阅[如何：创建新的 WPF 浏览器应用程序项目](https://msdn.microsoft.com/library/72ef4d90-e163-42a1-8df0-ea7ccfd1901f)。

运行 XBAP 项目时，它将在浏览器窗口而不是在单独的窗口中打开。 当调试从 Visual Studio XBAP 时，应用程序通过 Internet 区域权限运行，并因此将引发安全异常，如果超出这些权限。 有关详细信息，请参阅[安全性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/security-wpf)和 [WPF 部分信任安全性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/wpf-partial-trust-security)。

> 如果你不开发与 Visual Studio 或想要了解有关项目文件的详细信息，请参阅[生成 WPF 应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/building-a-wpf-application-wpf)。

### 部署 XBAP

生成 XBAP 时，输出将包括以下三个文件：

| 文件                     | 描述                                                         |
| ------------------------ | ------------------------------------------------------------ |
| 可执行文件 (.exe)        | 此文件包含已编译的代码且具有 .exe 扩展名。                   |
| 应用程序清单 (.manifest) | 此文件包含与应用程序关联的元数据且具有 .manifest 扩展名。    |
| 部署清单 (.xbap)         | 此文件包含 ClickOnce 使用来部署应用程序和具有.xbap 扩展名的信息。 |

将 XBAP 部署到 Web 服务器，例如 Microsoft Internet Information Services (IIS) 5.0 或更高版本。 无需在 Web 服务器上安装.NET Framework，但需要注册WPF多用途 Internet 邮件扩展 (MIME)类型和文件扩展名。 有关详细信息，请参阅[配置 IIS 5.0 和 IIS 6.0 以部署 WPF 应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/how-to-configure-iis-5-0-and-iis-6-0-to-deploy-wpf-applications)。

若要将 XBAP 准备好进行部署，请将 .exe 和关联的清单复制到 Web 服务器。 创建包含超链接的 HTML 页以打开部署清单，即扩展名为 .xbap 的文件。 当用户单击指向.xbap 文件的链接时，ClickOnce 会自动处理下载和启动应用程序的机制。 下面的代码示例显示包含指向 XBAP 的超链接的 HTML 页面。

```html
<html>   
    <head></head>  
    <body>   
        <a href="XbapEx.xbap">Click this link to launch the application</a>  
    </body>   
</html>  
```

还可以在网页框架中承载 XBAP。 创建具有一个或多个框架的网页。 将框架的源属性设置为部署清单文件。 如果想要使用内置机制在宿主网页和 XBAP 之间进行通信，则必须在框架中承载应用程序。 下面的示例代码演示了具有两个框架的 HTML 页面，第二个框架的源设置为 XBAP。

```html
<html>   
    <head>
        <title>A page with frames</title>
    </head>  
    <frameset cols="50%,50%">   
        <frame src="introduction.htm">   
        <frame src="XbapEx.xbap">   
    </frameset>   
</html>  
```

#### 清除缓存的 XBAP

在某些情况下，重新生成并启动 XBAP 后，可能会发现打开了早期版本的 XBAP。 例如，当 XBAP 程序集版本号是静态的，并从命令行启动 XBAP 时，可能会出现此行为。 在这种情况下，由于缓存的版本（以前启动的版本）和新版本的版本号相同，因此不会下载 XBAP 的新版本。 而会加载缓存的版本。

在这些情况下，可通过删除缓存的版本**Mage**命令 （随 Visual Studio 或 Windows SDK 一起安装），在命令提示符处。 以下命令可清除应用程序缓存。

```console
Mage.exe -cc
```

此命令可保证启动最新版本的 XBAP。 当你在 Visual Studio 中的应用程序调试时，应启动最新版本的 XBAP。 一般情况下，应在每次生成时更新部署版本号。 有关 Mage 的详细信息，请参阅 [Mage.exe（清单生成和编辑工具）](https://docs.microsoft.com/zh-cn/dotnet/framework/tools/mage-exe-manifest-generation-and-editing-tool)。

### 与宿主网页通信

当在 HTML 框架中承载应用程序时，可以与包含 XBAP 的网页进行通信。 为此，可检索[HostScript](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.browserinterophelper.hostscript)属性的[BrowserInteropHelper](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.browserinterophelper)。 此属性返回一个表示 HTML 窗口的脚本对象。 然后可以通过使用常规的点语法访问 [window object](https://go.microsoft.com/fwlink/?LinkId=160274)（window 对象）上的属性、方法和事件。 还可以访问脚本方法和全局变量。 以下示例演示如何检索脚本对象和关闭浏览器。

```csharp
private void Button_Click(object sender, RoutedEventArgs e)
{
    // Retrieve the script object. The XBAP must be hosted in a frame or
    // the HostScript object will be null.
    var scriptObject = BrowserInteropHelper.HostScript;

    // Call close to close the browser window. 
    scriptObject.Close();
}
```

#### 调试使用 HostScript 的 XBAP

如果 XBAP 使用[HostScript](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.browserinterophelper.hostscript)对象与 HTML 窗口中，通信有两个设置，你必须指定用于运行和调试 Visual Studio 中的应用程序。 应用程序必须有权访问其源站点，并且必须使用包含 XBAP 的 HTML 页启动应用程序。 以下步骤介绍如何检查这两个设置：

1. 在 Visual Studio 中，打开项目属性。

2. 在“安全性”选项卡上单击“高级”。

   将显示“高级安全设置”对话框。

3. 请确保选中“授予应用程序对其源站点的访问权”复选框，然后单击“确定”。

4. 在“调试”选项卡上，选择“使用 URL 启动浏览器”选项，然后指定包含 XBAP 的 HTML 页的 URL。

5. 在 Internet Explorer 中，单击“工具”按钮，然后选择“Internet 选项”。

   将显示“Internet 选项”对话框。

6. 单击“高级”选项卡。

7. 在“安全性”下面的“设置”列表中，选中“允许活动内容在我的计算机上的文件中运行”复选框。

8. 单击 **“确定”**。

   重启 Internet Explorer 后更改才会生效。

> 在 Internet Explorer 中启用活动内容可能会给计算机带来风险。 如果您不想要更改 Internet Explorer 安全设置，可以启动从服务器 HTML 页和 Visual Studio 调试器附加到进程。

### XBAP 安全注意事项

通常在被限制到 Internet 区域权限集的部分信任的安全沙盒中执行 XBAP。 因此，您的实现必须支持 Internet 区域中支持的 WPF 元素的子集，或必须将提升您的应用程序的权限。 有关详细信息，请参阅[安全性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/security-wpf)。

当你使用[WebBrowser](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.webbrowser)中应用程序中，WPF 控件在内部实例化本机 WebBrowser ActiveX 控件。 如果应用程序是 Internet Explorer 中运行的部分信任的 XBAP，则 ActiveX 控件会在 Internet Explorer 进程的专用线程中运行。 因此，存在以下限制：

- [WebBrowser](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.webbrowser)控件应提供行为类似于主机浏览器中，包括安全限制。 可以通过 Internet Explorer 安全设置控制这些安全限制中的某些限制。 有关详细信息，请参阅[安全性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/security-wpf)。
- 在 HTML 页中跨域加载 XBAP 时，将引发异常。
- 输入位于不同的线程中 WPF [WebBrowser](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.webbrowser)，因此无法截获键盘输入，并且不会共享 IME 状态。
- 由于 ActiveX 控件在另一个线程上运行，导航的计时或顺序可能有所不同。 例如，并不总是通过启动另一个导航请求来取消到某页的导航。
- 自定义 ActiveX 控件可能会在通信方面出现问题，因为 WPF 应用程序在另一个线程上运行。
- [MessageHook](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost.messagehook) 不会引发因为[HwndHost](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.hwndhost)无法在另一个线程或进程中运行的窗口的子类。

#### 创建完全信任的 XBAP

如果 XBAP 需要完全信任，则可以更改项目以启用此权限。 以下步骤介绍如何启用完全信任：

1. 在 Visual Studio 中，打开项目属性。
2. 在“安全性”选项卡上，选择“这是完全可信的应用程序”选项。

此设置将进行以下更改：

- 在项目文件中，将 `<TargetZone>` 元素值更改为 `Custom`。

- 在应用程序清单 (app.manifest) 中，将 `Unrestricted="true"` 特性添加到 `PermissionSet` 元素。

  ```xml
  <PermissionSet class="System.Security.PermissionSet"   
                 version="1"   
                 ID="Custom"   
                 SameSite="site"   
                 Unrestricted="true" />  
  ```

#### 部署完全信任的 XBAP

部署不遵循 ClickOnce 受信任部署模型的完全信任的 XBAP 时，用户运行该应用程序时的行为将取决于安全区域。在某些情况下，用户会在尝试安装它时收到警告。 用户可以选择继续或取消安装。 下表描述每个安全区域的应用程序的行为，以及为了使应用程序接收完全信任而必须执行的操作。

| 安全区域                | 行为                     | 获取完全信任                                       |
| ----------------------- | ------------------------ | -------------------------------------------------- |
| 本地计算机              | 自动完全信任             | 无需执行任何操作。                                 |
| Intranet 和受信任的站点 | 提示完全信任             | 使用证书对 XBAP 进行签名，以便用户在提示中看到源。 |
| Internet                | 失败，并显示“未授予信任” | 使用证书对 XBAP 进行签名。                         |

> 上表中描述的行为针对的是不遵循 ClickOnce 受信任部署模型的完全信任的 XBAP。

建议使用 ClickOnce 受信任部署模型部署完全信任的 XBAP。 此模型允许自动向 XBAP 授予完全信任（与安全区域无关），这样用户便不会收到提示。 作为此模型的一部分，必须使用来自受信任发行者提供的证书来对应用程序进行签名。 有关详细信息，请参阅[受信任的应用程序部署概述](https://docs.microsoft.com/zh-cn/visualstudio/deployment/trusted-application-deployment-overview)和 [Introduction to Code Signing](https://go.microsoft.com/fwlink/?LinkId=166327)（代码签名简介）。

### XBAP 启动时间性能注意事项

XBAP 性能的一个重要方面是其启动时间。 如果 XBAP 是要加载的第一个 WPF 应用程序，则冷启动时间可能为十秒或更长。 这是因为进度页面由 WPF 呈现，且 CLR 和 WPF 都必须冷启动才能显示应用程序。

在 .NET Framework 3.5 SP1 中启动时，通过在部署周期早期显示未托管进度页可以缩短 XBAP 的冷启动时间。 启动应用程序后几乎会立即显示进度页，因为它由本机宿主代码显示，并以 HTML 格式呈现。

此外，改进了的 ClickOnce 下载序列并发最多 10%改进开始时间。 ClickOnce 下载并验证之后清单、 启动应用程序下载和进度栏将开始更新。

## [WPF Host (PresentationHost.exe)](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/wpf-host-presentationhost-exe)

Windows Presentation Foundation (WPF) 主机 (PresentationHost.exe) 是应用程序，使WPF兼容的浏览器中托管应用程序 (包括Microsoft Internet Explorer 6及更高版本)。 默认情况下，Windows Presentation Foundation (WPF) 主机注册为 shell 并MIME处理程序的浏览器承载WPF内容，其中包括：

- 松散（未编译）XAML 文件 (.xaml)。
- XAML 浏览器应用程序 (XBAP) (.xbap)。

对于这些类型，Windows Presentation Foundation (WPF) 主机的文件：

- 启动注册HTML处理程序来承载 Windows Presentation Foundation (WPF) 内容。
- 加载的所需的正确版本公共语言运行时 (CLR)和 Windows Presentation Foundation (WPF) 程序集。
- 确保部署区域具有适当的权限级别。

本主题介绍了可以与 PresentationHost.exe 一起使用的命令行参数。

### 用法

```
PresentationHost.exe [parameters] uri|filename
```

### 参数

| 参数                        | 描述                                                         |
| --------------------------- | ------------------------------------------------------------ |
| filename                    | 要激活的文件的路径。 也可以为 URI。                          |
| -debug                      | 激活应用程序时，不要从存储中提交或运行它。 此参数仅在激活本地文件时才起作用。 |
| -debugSecurityZoneURL <url> | 与 URL 值一起使用，以指示 PresentationHost.exe 有一个应用程序应调试，就像从指定的 URL对其进行部署一样。 此参数可确定部署区域和源站点。 |
| -embedding                  | OLE 的必需参数。 如果已指定 `-event` 或 `-debug` 参数，则无需指定 `-embedding` 参数，因为该参数已在内部设置。 |
| -event <eventname>          | 打开具有此名称的事件，并在 PresentationHost.exe 初始化并准备好承载 WPF 内容时向该事件发出信号。 如果打开事件时发生错误（例如该事件尚未创建），则 PresentationHost.exe 将终止。 |
| -launchApplication <url>    | 从指定的 URL 启动独立的 ClickOnce 应用程序。 会应用与 .NET 应用程序有关的 Internet Explorer 和 WinINet 安全策略。 |

### 方案

#### Shell 处理程序

```
PresentationHost.exe example.xbap
```

#### MIME 处理程序

```
PresentationHost.exe -embedding example.xbap
```

#### Visual Studio 调试

```
PresentationHost.exe -debug example.xbap
```

#### 在区域中进行 Visual Studio 调试

```
PresentationHost.exe -debug -debugSecurityZoneURL http://www.example.com c:\folderpath\example.xbap
```

## [Firefox Add-ons to Support .NET Application Deployment](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/firefox-add-ons-to-support-net-application-deployment)

Windows Presentation Foundation (WPF) 适用于 Firefox 和.NET Framework Assistant firefox 插件启用XAML 浏览器应用程序 (XBAP)、 松散XAML，和 ClickOnce 应用程序以使用 Mozilla Firefox 浏览器。

### Firefox WPF 插件

Firefox 的插件的 WPF 启用XBAP和宽松XAML要导航到并运行位于顶级或 Firefox 浏览器中 HTML IFRAME 中的文件。 XBAP是WPF可发布到 Web 服务器和在启动应用程序支持的浏览器。 松散XAML是一个仅 XAML 文件，可以导航到并显示在支持的浏览器，类似于 XML 文件。

WPF与已安装 Firefox 插件.NET Framework 3.5。 Window 7 包括.NET Framework 3.5，但不包括WPFFirefox 的插件。 不能安装WPFWindows 7 上的 Firefox 的插件。

.NET Framework 4不包括WPFFirefox 的插件。 但是，如果两个.NET Framework 3.5并.NET Framework 4是安装，随一起安装的 WPF 插件 Firefox .NET Framework 3.5。 因此.NET Framework 4应用程序仍将运行，因为 WPF 宿主将加载正确版本的 framework。 有关详细信息，请参阅[WPF 主机 (PresentationHost.exe)](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/wpf-host-presentationhost-exe)。

### .NET Framework Assistant for Firefox

.NET Framework Assistant firefox 允许独立 ClickOnce 应用程序从 Firefox 浏览器中运行。 .NET Framework Assistant Firefox 函数的相同安装之前和之后的 Firefox 浏览器。 Firefox 浏览器启动时和.NET Framework 3.5 SP1是安装，Firefox 找到并安装了适用于 Firefox 的.NET Framework Assistant。 用户可以配置的.NET Framework Assistant firefox 来执行以下操作：

- 运行 ClickOnce 应用程序之前进行提示。
- 报告所有已安装的版本的.NET Framework 或只是最新版本。

.NET Framework Assistant firefox 是附带.NET Framework 3.5 SP1。 有关删除适用于 Firefox 的.NET Framework Assistant 的信息，请参阅[如何删除适用于 Firefox 的.NET Framework Assistant](https://go.microsoft.com/fwlink/?LinkId=177944)。

## [Native WPF Browser Hosting Support APIs](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/native-wpf-browser-hosting-support-apis)

托管的WPFWeb 浏览器中的应用程序可以通过注册从 WPF 宿主的活动文档服务器 (也称为 DocObject) 加速。Internet Explorer 可以直接激活，并将与活动文档集成。 Xbap 和 Mozilla 浏览器中的松散 XAML 文档的托管WPF提供了一个 NPAPI 插件，它提供到类似的宿主环境WPF活动文档服务器作为Internet Explorerdoes。 但是，在其他浏览器中的最简单的实用方法，以承载 Xbap 和 XAML 文档，独立应用程序是通过 Internet Explorer Web 浏览器控件。 Web 浏览器控件提供复杂活动文档服务器宿主环境，但它使自己的主机以自定义和扩展该环境，并直接与当前活动文档对象进行通信。

WPF活动文档服务器实现几个常见的托管接口，包括[IOleObject](https://go.microsoft.com/fwlink/?LinkId=162049)， [IOleDocument](https://go.microsoft.com/fwlink/?LinkId=162050)， [IOleInPlaceActiveObject](https://go.microsoft.com/fwlink/?LinkId=162051)，[IPersistMoniker](https://go.microsoft.com/fwlink/?LinkId=162045)， [IOleCommandTarget](https://go.microsoft.com/fwlink/?LinkId=162047)。 Web 浏览器控件中托管时，这些接口只能从返回的对象的查询[IWebBrowser2::Document](https://go.microsoft.com/fwlink/?LinkId=162048)属性。

### 不需要此行为

WPF 活动文档服务器实现[IOleCommandTarget](https://go.microsoft.com/fwlink/?LinkId=162047)支持很多与导航相关的和特定于浏览器的命令 （具有空命令组 GUID） 的标准 OLE 命令组。 此外，它会识别了名为 CGID_PresentationHost 的自定义命令组。 目前，没有定义此组中只有一个命令。

```
DEFINE_GUID(CGID_PresentationHost, 0xd0288c55, 0xd6, 0x4f5e, 0xa8, 0x51, 0x79, 0xde, 0xc5, 0x1b, 0x10, 0xec);  
enum PresentationHostCommands {   
   PHCMDID_TABINTO = 1   
};  
```

PHCMDID_TABINTO 指示 PresentationHost 将焦点切换到在其内容，具体取决于 Shift 键的状态中的第一个或最后一个可获得焦点元素。

### [IEnumRAWINPUTDEVICE](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/ienumrawinputdevice)

此接口枚举原始输入设备，并仅供 PresentationHost.exe 使用。

> 此 API 预期仅支持在本地客户端计算机上使用

#### 成员

| 成员                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [IEnumRAWINPUTDEVIC:Next](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/ienumrawinputdevic-next) | 在枚举器列表中枚举下一个 `celt` 元素（即 RAWINPUTDEVICE 结构），将它们和 `rgelt` 中枚举元素的实际数量返回至 `pceltFetched`。 |
| [IEnumRAWINPUTDEVIC:Skip](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/ienumrawinputdevic-skip) | 指示枚举器跳过下一步`celt`枚举中的元素，以便下次调用[IEnumRAWINPUTDEVIC:Next](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/ienumrawinputdevic-next)不会返回这些元素。 |
| [IEnumRAWINPUTDEVIC:Reset](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/ienumrawinputdevic-reset) | 将枚举序列重置到开头。                                       |
| [IEnumRAWINPUTDEVIC:Clone](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/ienumrawinputdevic-clone) | 创建一个与当权枚举器相同状态的原始输入设备枚举器，以循环访问相同的列表。 |

#### [IEnumRAWINPUTDEVIC:Next](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/ienumrawinputdevic-next)

枚举下一个`celt` [RAWINPUTDEVICE](https://msdn.microsoft.com/library/default.asp?url=/library/winui/winui/windowsuserinterface/userinput/rawinput/rawinputreference/rawinputstructures/rawinputdevice.asp)在枚举器的列表中，将它们中返回的结构`rgelt`以及中枚举元素的实际数目`pceltFetched`。

##### 语法

```
HRESULT Next(  
      [in] ULONG celt,  
      [out, size_is(celt), length_is(*pceltFetched)] RAWINPUTDEVICE *rgelt,  
      [out] ULONG *pceltFetched);  
```

##### 参数

```
celt
```

[in]数[RAWINPUTDEVICE](https://msdn.microsoft.com/library/default.asp?url=/library/winui/winui/windowsuserinterface/userinput/rawinput/rawinputreference/rawinputstructures/rawinputdevice.asp)结构中返回`rgelt`。

```
rgelt
```

[out] celt 大小（或更大）的数组，用于接收枚举的 RAWINPUTDEVICE 结构。

```
pceltFetched
```

[out] 指向 `rgelt` 中实际提供的元素数量的指针。 如果 `NULL` 为一，则调用方可传入 `rgelt`。

##### 属性值/返回值

HRESULT：如果提供的元素数量为 `celt`，则值为 S_OK；否则为 S_FALSE。

#### [IEnumRAWINPUTDEVIC:Skip](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/ienumrawinputdevic-skip)

指示枚举数跳过下一步`celt`枚举中的元素，以便下一次调用到[IEnumRAWINPUTDEVIC:Next](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/ienumrawinputdevic-next)不会返回这些元素。

##### 语法

```
HRESULT Skip( [in] ULONG celt);  
```

##### 参数

```
celt
```

[in]要跳过的元素数。

##### 属性值/返回值

HRESULT：如果提供的元素数量为 `celt`，则值为 S_OK；否则为 S_FALSE。

#### [IEnumRAWINPUTDEVIC:Reset](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/ienumrawinputdevic-reset)

将枚举序列重置到开头。

##### 语法

```
HRESULT Reset();  
```

##### 属性值/返回值

HRESULT:，则为 S_OK。

#### [IEnumRAWINPUTDEVIC:Clone](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/ienumrawinputdevic-clone)

创建一个与当权枚举器相同状态的原始输入设备枚举器，以循环访问相同的列表。

##### 语法

```
HRESULT Clone( [out] IEnumRAWINPUTDEVICE **ppenum);  
```

##### 参数

```
ppenum
```

[out]接收的输出变量的地址[IEnumRAWINPUTDEVICE](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/ienumrawinputdevice)接口指针。 如果方法不成功，则此输出变量的值不确定。

##### 属性值/返回值

HRESULT： 此方法支持 E_INVALIDARG、 E_OUTOFMEMORY 和 E_UNEXPECTED 标准的返回值。

##### 备注

此方法使可以枚举序列中记录一个点，以便稍后返回到该点。 调用方必须释放此新的枚举器，单独从第一个枚举器。

### [IWpfHostSupport](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/iwpfhostsupport)

托管的应用程序Windows Presentation Foundation (WPF)内容 PresentationHost.exe 通过实现此接口可提供的主机和 PresentationHost.exe 之间的集成点。

#### 备注

Win32 应用程序，如 Web 浏览器可以托管WPF内容，包括XAML 浏览器应用程序 (XBAP)宽松 XAML。 到主机WPF内容，Win32应用程序创建的实例[WebBrowser 控件](https://go.microsoft.com/fwlink/?LinkId=97911)。 要托管WPF创建的 PresentationHost.exe，提供了托管实例WPF所在的主机中的显示内容[WebBrowser 控件](https://go.microsoft.com/fwlink/?LinkId=97911)。

通过启用集成`IWpfHostSupport`允许 PresentationHost.exe 到：

- 发现并注册与主机应用程序感兴趣的原始输入设备 （人机接口设备）。
- 接收输入的消息从已注册的原始输入的设备和适当的消息转发到主机应用程序。
- 查询进度和错误的自定义用户界面的主机应用程序。

> 此 API 预期仅支持在本地客户端计算机上使用

#### 成员

| 成员                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [GetRawInputDevices](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/getrawinputdevices) | 允许 PresentationHost.exe 发现主机应用程序感兴趣的原始输入的设备（人机接口设备）。 |
| [FilterInputMessage](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/filterinputmessage) | 除非返回 E_NOTIMP，否则每当收到一条消息时都会由 PresentationHost.exe 调用。 |
| [GetCustomUI](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/getcustomui) | 默认情况下，PresentationHost.exe 提供其自己的部署进度和部署错误会显示部署的 WPF 内容时的用户界面。 |

#### [GetRawInputDevices](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/getrawinputdevices)

允许 PresentationHost.exe 发现主机应用程序感兴趣的原始输入的设备（人机接口设备）。

##### 语法

```
HRESULT GetRawInputDevices( [out] IEnumRAWINPUTDEVICE **ppEnum );  
```

##### 参数

```
ppEnum
```

[out]一个指向[IEnumRAWINPUTDEVICE](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/ienumrawinputdevice)用于枚举原始输入的设备。

##### 属性值/返回值

HRESULT：

S_OK- [IEnumRAWINPUTDEVICE](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/ienumrawinputdevice)如果返回 S_OK，则将仅由 PresentationHost.exe 使用。

E_NOTIMPL

##### 备注

原始输入设备是一组输入设备，其中包括键盘、鼠标和非传统设备（如远程控制设备）。

一旦已检索到的原始输入设备的列表，则 PresentationHost.exe 将使用此设备进行注册，以接收 WM_INPUT 通知消息。

#### [FilterInputMessage](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/filterinputmessage)

除非返回 E_NOTIMP，否则每当收到一条消息时都会由 PresentationHost.exe 调用。

##### 语法

```
HRESULT FilterInputMessage( [in] MSG* pMsg ) ;  
```

##### 参数

```
pMsg
```

[in] 发送给正在获得原始输入的窗口的 WM_INPUT 消息。

##### 属性值/返回值

HRESULT：

S_OK - 筛选器未处理该消息，且可能执行进一步处理。

S_FALSE - 筛选器已处理此消息，且应执行进一步处理。

E_NOTIMPL – 如果返回此值，则[FilterInputMessage](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/filterinputmessage)不会再调用。 这可能会从以下主机应用程序返回：仅对向 PresentationHost.exe 提供自定义进度和错误用户界面有兴趣且对从 PresentationHost.exe 向自身转发原始输入消息不感兴趣。

##### 备注

PresentationHost.exe 是各种原始输入设备（包括键盘、鼠标和远程控件）的目标。 有时，主机应用程序中的行为取决于输入，否则将由 PresentationHost.exe 消耗。 例如，主机应用程序可能依靠接收特定输入消息来确定是否显示特定的用户界面元素。

若要允许主机应用程序接收必要的输入的消息以提供这些行为，PresentationHost.exe 相应原始输入将消息转发到承载的应用程序通过调用[FilterInputMessage](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/filterinputmessage)。

承载的应用程序注册后的原始输入设备 （人机接口设备） 返回的集接收原始输入的消息[GetRawInputDevices](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/getrawinputdevices)。

#### [GetCustomUI](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/getcustomui)

如果实现由 PresentationHost.exe 从主机获取自定义进度和错误消息调用。

##### 语法

```
HRESULT GetCustomUI( [out] BSTR* pwzProgressAssemblyName, [out] BSTR* pwzProgressClassName, [out] BSTR* pwzErrorAssemblyName, [out] BSTR* pwzErrorClassName );  
```

##### 参数

```
pwzProgressAssemblyName
```

[out]指向包含主机提供进度用户界面的程序集的指针。

```
pwzProgressClassName
```

[out]最好是为主机提供进度用户界面，类的名称XAML文件具有[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)是其顶级元素。 此类驻留在由指定的程序集`pwzProgressAssemblyName`。

```
pwzErrorAssemblyName
```

[out]指向包含主机提供的错误用户界面的程序集的指针。

```
pwzErrorClassName
```

[out]为主机提供的错误用户类的名称最好是接口具有的 XAML 文件[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)是其顶级元素。 此类驻留在由指定的程序集`pwzErrorAssemblyName`。

##### 属性值/返回值

HRESULT：已忽略。

##### 备注

主机应用程序可能具有可能不符合 PresentationHost.exe 的默认用户界面的特定主题。 如果是这样，主机应用程序可以实现[GetCustomUI](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/getcustomui)返回进度和错误的用户界面到 PresentationHost.exe。 将始终调用 PresentationHost.exe [GetCustomUI](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/getcustomui)之前使用其默认用户界面。

一次在 PresentationHost 的初始化期间调用此函数。

