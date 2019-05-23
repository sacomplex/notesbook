# [Security](https://docs.microsoft.com/en-us/dotnet/framework/wpf/security-wpf)

在开发 Windows Presentation Foundation (WPF) 独立应用程序和浏览器承载的应用程序时，必须考虑的安全模型。 WPF 独立应用程序执行无限制的权限 ( CAS **FullTrust**的权限集)、 是否使用 Windows Installer (.msi)、 XCopy 部署或ClickOnce。 不支持使用 ClickOnce 部署部分信任的独立 WPF 应用程序。 但是，完全信任的主机应用程序可以创建部分信任[AppDomain](https://docs.microsoft.com/zh-cn/dotnet/api/system.appdomain)使用.NET Framework 外接程序模型。 有关详细信息，请参阅[WPF 外接程序概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/wpf-add-ins-overview)。

WPF 通过托管浏览器承载的应用程序Windows Internet Explorer或 Firefox，可以是XAML 浏览器应用程序 (XBAP)或松散可扩展应用程序标记语言 (XAML)文档中的详细信息，请参阅[WPF XAML 浏览器应用程序概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/wpf-xaml-browser-applications-overview)。

WPF 浏览器承载的应用程序在部分信任的安全沙盒内执行默认情况下限制为默认值CAS **Internet**区域权限集。 这可以有效地将WPF浏览器托管应用程序与客户端计算机与您期望典型的 Web 应用程序隔离的方式相同。 XBAP 最高可以将权限提升到“完全信任”，具体取决于部署 URL 的安全区域和客户端的安全配置。 有关详细信息，请参阅 [WPF 部分信任安全性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/wpf-partial-trust-security)。

本主题讨论 Windows Presentation Foundation (WPF) 独立应用程序和浏览器承载的应用程序的安全模型。

本主题包含以下各节：

- [安全导航](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/security-wpf#SafeTopLevelNavigation)
- [Web 浏览软件安全设置](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/security-wpf#InternetExplorerSecuritySettings)
- [WebBrowser 控件和功能控件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/security-wpf#webbrowser_control_and_feature_controls)
- [对部分受信任的客户端应用程序禁用 APTCA 程序集](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/security-wpf#APTCA)
- [宽松 XAML 文件的沙盒行为](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/security-wpf#LooseContentSandboxing)
- [用于开发可提高安全性的 WPF 应用程序的资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/security-wpf#BestPractices)

## 安全导航

有关XBAP，WPF区分两种类型的导航： 应用程序和浏览器。

应用程序导航是指在浏览器托管的应用程序内的内容项之间进行导航。 浏览器导航是指可更改浏览器自身的内容和位置 URL 的导航。 应用程序导航 (通常为 XAML) 与浏览器导航 (通常为 HTML) 之间的关系是在下图中所示：

![导航示意图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/media/safetoplevelnavigationfigure.png)

被视为安全的内容类型XBAP以导航到主要取决于是否使用应用程序导航还是浏览器导航。



### 应用程序导航安全性

应用程序导航被视为安全，如果它可以使用打包的标识URI，它支持四种类型的内容：

| 内容类型     | 描述                                                         | URI 示例                                          |
| ------------ | ------------------------------------------------------------ | ------------------------------------------------- |
| 资源         | 添加到项目的生成类型的文件**资源**。                         | `pack://application:,,,/MyResourceFile.xaml`      |
| 内容         | 添加到项目的生成类型的文件**内容**。                         | `pack://application:,,,/MyContentFile.xaml`       |
| 源站点       | 添加到项目的生成类型的文件**None**。                         | `pack://siteoforigin:,,,/MySiteOfOriginFile.xaml` |
| 应用程序代码 | 具有已编译代码隐藏的 XAML 资源。  或  XAML 文件添加到项目的生成类型为**页**。 | `pack://application:,,,/MyResourceFile` `.xaml`   |

 备注

有关应用程序数据文件和包的详细信息URI，请参阅[WPF 应用程序资源、 内容和数据文件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/wpf-application-resource-content-and-data-files)。

可以由用户导航到这些内容类型的文件，也可以通过编程方式导航到这些内容类型的文件：

- **用户导航**。 用户通过单击导航[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)元素。
- **编程导航**。 应用程序导航不涉及用户，例如，通过设置[NavigationWindow.Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow.source)属性。



### 浏览器导航安全性

浏览器导航仅在以下条件下被视为安全：

- **用户导航**。 用户通过单击导航[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)元素内主[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)，不能在嵌套[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)。
- **区域**。 要导航到的内容位于 Internet 或本地 Intranet 上。
- **协议**。 正在使用的协议可以是**http**， **https**，**文件**，或者**mailto**。

如果XBAP尝试导航到内容不符合这些条件的方式[SecurityException](https://docs.microsoft.com/zh-cn/dotnet/api/system.security.securityexception)引发。

## Web 浏览软件安全设置

计算机上的安全设置决定了任何 Web 浏览软件被授予的访问权限。 Web 浏览软件包括任何应用程序或组件，它使用[WinINet](https://go.microsoft.com/fwlink/?LinkId=179379)或[UrlMon](https://go.microsoft.com/fwlink/?LinkId=179383) Api，包括 Internet Explorer 和 PresentationHost.exe。

Internet Explorer 提供一种机制，可以配置允许或从要执行的功能Internet Explorer，其中包括：

- .NET framework 相关组件
- ActiveX 控件和插件
- 下载
- 脚本
- 用户身份验证

可以在这种方式保护的功能的集合配置为按每个区域**Internet**， **Intranet**，**受信任的站点**，和**受限站点**区域。 以下步骤描述如何配置安全设置：

1. 打开“控制面板” 。

2. 单击**网络和 Internet** ，然后单击**Internet 选项**。

   将显示“Internet 选项”对话框。

3. 上**安全**选项卡上，选择要配置的安全设置的区域。

4. 单击**自定义级别**按钮。

   **安全设置**对话框随即出现，并且可以配置为所选区域的安全设置。

   ![“安全设置”对话框](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/media/wpfsecurityfigure1.png)

 备注

也可以从 Internet Explorer 中进入“Internet 选项”对话框。 单击**工具**，然后单击**Internet 选项**。

从开始Windows Internet Explorer 7，专门为.NET Framework 的以下安全设置将包括：

- **宽松 XAML**。 控件是否Internet Explorer可以导航到并松散XAML文件。 （“启用”、“禁用”和“提示”选项）。
- **XAML 浏览器应用程序**。 控件是否Internet Explorer可以导航到并运行XBAP。 （“启用”、“禁用”和“提示”选项）。

默认情况下启用这些设置所有用于**Internet**，**本地 intranet**，并**受信任的站点**区域，并禁用**受限站点**区域。



### 与安全相关的 WPF 注册表设置

除了可通过“Internet 选项”设置的安全设置之外，还可以通过设置以下注册表值有选择地阻止许多安全敏感 WPF 功能。 这些值在以下注册表项下定义：

```
HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\.NETFramework\Windows Presentation Foundation\Features
```

下表列出了可以设置的值。

| 值名称                | 值类型    | 值数据               |
| --------------------- | --------- | -------------------- |
| XBAPDisallow          | REG_DWORD | 1 为禁止；0 为允许。 |
| LooseXamlDisallow     | REG_DWORD | 1 为禁止；0 为允许。 |
| WebBrowserDisallow    | REG_DWORD | 1 为禁止；0 为允许。 |
| MediaAudioDisallow    | REG_DWORD | 1 为禁止；0 为允许。 |
| MediaImageDisallow    | REG_DWORD | 1 为禁止；0 为允许。 |
| MediaVideoDisallow    | REG_DWORD | 1 为禁止；0 为允许。 |
| ScriptInteropDisallow | REG_DWORD | 1 为禁止；0 为允许。 |

## WebBrowser 控件和功能控件

WPF[WebBrowser](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.webbrowser)控件可用于承载 Web 内容。 WPF[WebBrowser](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.webbrowser)控件包装基础 WebBrowser ActiveX 控件。 WPF 提供了一些支持，用于保护你的应用程序时使用 WPF[WebBrowser](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.webbrowser)控件来承载不受信任的 Web 内容。 但是，必须使用的应用程序由直接应用某些安全功能[WebBrowser](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.webbrowser)控件。 有关 WebBrowser ActiveX 控件的详细信息，请参阅[WebBrowser 控件概述和教程](https://go.microsoft.com/fwlink/?LinkId=179388)。

 备注

本部分还适用于[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)控制，因为它使用[WebBrowser](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.webbrowser)导航到 HTML 内容。

如果 WPF[WebBrowser](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.webbrowser)控件用于承载不受信任的 Web 内容、 应用程序应使用部分信任[AppDomain](https://docs.microsoft.com/zh-cn/dotnet/api/system.appdomain)来帮助隔离应用程序代码中潜在的恶意 HTML 脚本代码。 这是特别是当你的应用程序进行交互与承载的脚本通过使用[InvokeScript](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.webbrowser.invokescript)方法和[ObjectForScripting](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.webbrowser.objectforscripting)属性。 有关详细信息，请参阅[WPF 外接程序概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/wpf-add-ins-overview)。

如果应用程序使用 WPF[WebBrowser](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.webbrowser)控件，以提高安全性和减轻攻击的另一种方法是启用 Internet Explorer 功能控件。 功能控件是允许管理员和开发人员配置的 Internet Explorer 和承载 WebBrowser ActiveX 控件的应用程序的功能与 Internet 资源管理器的附加功能的 WPF[WebBrowser](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.webbrowser)控制包装。 可以使用配置功能控件[CoInternetSetFeatureEnabled](https://go.microsoft.com/fwlink/?LinkId=179394)函数或通过更改注册表中的值。 有关功能控件的详细信息，请参阅[功能控件简介](https://go.microsoft.com/fwlink/?LinkId=179390)并[Internet 功能控件](https://go.microsoft.com/fwlink/?LinkId=179392)。

如果你正在开发的独立 WPF 应用程序使用 WPF[WebBrowser](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.webbrowser)控件，WPF 会自动启用你的应用程序的以下功能控件。

| 功能控件                               |
| -------------------------------------- |
| FEATURE_MIME_HANDLING                  |
| FEATURE_MIME_SNIFFING                  |
| FEATURE_OBJECT_CACHING                 |
| FEATURE_SAFE_BINDTOOBJECT              |
| FEATURE_WINDOW_RESTRICTIONS            |
| FEATURE_ZONE_ELEVATION                 |
| FEATURE_RESTRICT_FILEDOWNLOAD          |
| FEATURE_RESTRICT_ACTIVEXINSTALL        |
| FEATURE_ADDON_MANAGEMENT               |
| FEATURE_HTTP_USERNAME_PASSWORD_DISABLE |
| FEATURE_SECURITYBAND                   |
| FEATURE_UNC_SAVEDFILECHECK             |
| FEATURE_VALIDATE_NAVIGATE_URL          |
| FEATURE_DISABLE_TELNET_PROTOCOL        |
| FEATURE_WEBOC_POPUPMANAGEMENT          |
| FEATURE_DISABLE_LEGACY_COMPRESSION     |
| FEATURE_SSLUX                          |

由于这些功能控件是无条件启用的，因此它们可能会对完全信任的应用程序造成损害。 在这种情况下，如果特定应用程序及其承载的内容没有安全风险，则可以禁用相应的功能控件。

功能控件所应用的实例化 WebBrowser ActiveX 对象的过程。 因此，如果要创建可导航到不受信任的内容的独立应用程序，则应该认真考虑启用附加功能控件。

 备注

此建议是根据 MSHTML 和 SHDOCVW 主机安全性的一般性建议提出的。 有关详细信息，请参阅[MSHTML 主机安全性常见问题：第一部分的 II](https://go.microsoft.com/fwlink/?LinkId=179396)和[MSHTML 主机安全性常见问题：第二部分，共 ii 部分](https://go.microsoft.com/fwlink/?LinkId=179415)。

对于可执行文件，请考虑通过将注册表值设置为 1 来启用以下功能控件。

| 功能控件                                    |
| ------------------------------------------- |
| FEATURE_ACTIVEX_REPURPOSEDETECTION          |
| FEATURE_BLOCK_LMZ_IMG                       |
| FEATURE_BLOCK_LMZ_OBJECT                    |
| FEATURE_BLOCK_LMZ_SCRIPT                    |
| FEATURE_RESTRICT_RES_TO_LMZ                 |
| FEATURE_RESTRICT_ABOUT_PROTOCOL_IE7         |
| FEATURE_SHOW_APP_PROTOCOL_WARN_DIALOG       |
| FEATURE_LOCALMACHINE_LOCKDOWN               |
| FEATURE_FORCE_ADDR_AND_STATUS               |
| FEATURE_RESTRICTED_ZONE_WHEN_FILE_NOT_FOUND |

对于可执行文件，请考虑通过将注册表值设置为 0 来禁用以下功能控件。

| 功能控件                                        |
| ----------------------------------------------- |
| FEATURE_ENABLE_SCRIPT_PASTE_URLACTION_IF_PROMPT |

如果运行部分信任XAML 浏览器应用程序 (XBAP)包括 WPF[WebBrowser](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.webbrowser)控制中Windows Internet Explorer，WPF 承载 WebBrowser ActiveX 控件在 Internet Explorer 进程的地址空间中。 由于 WebBrowser ActiveX 控件承载于Internet Explorer进程中，所有 Internet Explorer 功能控件也已启用了 WebBrowser ActiveX 控件。

与普通的独立应用程序相比，运行于 Internet Explorer 中的 XBAP 还将另外获得一层安全保护。 此附加的安全性是因为 Internet Explorer 和 WebBrowser ActiveX 控件，因此在运行受保护模式在默认情况下Windows Vista和Windows 7。 有关受保护模式的详细信息，请参阅[了解和使用受保护模式 Internet Explorer 中](https://go.microsoft.com/fwlink/?LinkId=179393)。

> 如果你尝试运行包括 WPF XBAP[WebBrowser](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.webbrowser)在 Firefox 中，在 Internet 区域中的控件[SecurityException](https://docs.microsoft.com/zh-cn/dotnet/api/system.security.securityexception)将引发。 这是由于 WPF 安全策略造成的。

## 对部分受信任的客户端应用程序禁用 APTCA 程序集

当托管程序集安装到全局程序集缓存 (GAC)，它们变为完全受信任的因为用户必须提供安装它们的显式权限。 因为这些程序集是完全受信任的，所以只有完全受信任的托管客户端应用程序才可以使用它们。 若要允许部分受信任应用程序使用它们，它们必须标记有[AllowPartiallyTrustedCallersAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.security.allowpartiallytrustedcallersattribute)(APTCA)。 仅当程序集经过测试，可在部分信任的情况下安全执行时，才应该为其标记此特性。

但是，有可能 APTCA 程序集安装到后出现安全漏洞GAC。 一旦发现安全漏洞，程序集发布者可以生成安全更新来修复现有安装上的问题，还可以阻止问题发现后进行的安装操作。 其中一个更新选项是卸载程序集，即使这可能中断使用该程序集的其他完全受信任的客户端应用程序。

WPF 提供了对部分受信任 APTCA 程序集可以禁用所依据的机制XBAP而无需卸载 APTCA 程序集。

若要禁用 APTCA 程序集，必须创建一个特殊的注册表项：

```
HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\.NETFramework\policy\APTCA\<AssemblyFullName>, FileVersion=<AssemblyFileVersion>
```

示例如下：

```
HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\.NETFramework\policy\APTCA\aptcagac, Version=1.0.0.0, Culture=neutral, PublicKeyToken=215e3ac809a0fea7, FileVersion=1.0.0.0
```

此项建立 APTCA 程序集的条目。 还必须在此项中创建值来启用或禁用程序集。 下面是该值的详细信息：

- 值名称：**APTCA_FLAG**。
- 值类型：**REG_DWORD**。
- 值数据：**1**为禁用;**0**启用。

如果必须为部分受信任的客户端应用程序禁用某程序集，可以编写一个用于创建注册表项和值的更新。

> 核心.NET Framework 程序集不受这种方式禁用它们，因为它们所需的托管应用程序运行。 对禁用 APTCA 程序集的支持主要面向第三方应用程序。

## 宽松 XAML 文件的沙盒行为

松散XAML文件是仅标记 XAML 文件，不依赖于任何代码隐藏、 事件处理程序或特定于应用程序的程序集。 当松散XAML直接从浏览器导航到文件，它们是在基于默认 Internet 区域权限集的安全沙盒中加载。

但是，安全行为是不同时松散XAML文件从导航到[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)或[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)独立应用程序中。

在这两种情况下，松散XAML导航到的文件将继承其主机应用程序的权限。 但是，此行为可能不需要从安全角度看，尤其是当松散XAML文件通过不受信任或未知的实体生成。 此类型的内容被称为*外部内容*，并且两个[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)和[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)可以配置为将导航到它时隔离。 通过设置实现隔离**SandboxExternalContent**属性设置为 true，对于下面的示例中所示[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)和[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow):

```xaml
<Frame 
  Source="ExternalContentPage.xaml" 
  SandboxExternalContent="True">
</Frame>
```

```xaml
<!-- Sandboxing external content using NavigationWindow-->
<NavigationWindow 
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
  Source="ExternalContentPage.xaml" 
  SandboxExternalContent="True">
</NavigationWindow>
```

使用此设置，外部内容将加载到不同于承载应用程序的进程的进程中。 此进程被限制在默认 Internet 区域权限集中，从而有效地将其与承载应用程序和客户端计算机隔离。

> 即使导航到松散XAML文件从[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)或[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)在独立实现应用程序是基于 WPF 浏览器承载基础结构，涉及 PresentationHost 进程的安全级别略小于加载内容时直接在 Internet Explorer 中上Windows Vista和Windows 7（这仍会通过 PresentationHost）。 这是因为使用 Web 浏览器的独立 WPF 应用程序不提供 Internet Explorer 的额外“保护模式”安全功能。

## 用于开发可提高安全性的 WPF 应用程序的资源

以下是一些其他资源，以帮助开发WPF提高安全性的应用程序：

| 区域      | 资源                                                         |
| --------- | ------------------------------------------------------------ |
| 托管代码  | [应用程序的模式和实践安全指南](https://go.microsoft.com/fwlink/?LinkId=117426) |
| CAS       | [代码访问安全性](https://docs.microsoft.com/zh-cn/dotnet/framework/misc/code-access-security) |
| ClickOnce | [ClickOnce 安全和部署](https://docs.microsoft.com/zh-cn/visualstudio/deployment/clickonce-security-and-deployment) |
| WPF       | [WPF 部分信任安全](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/wpf-partial-trust-security) |

## [WPF Partial Trust Security](https://docs.microsoft.com/en-us/dotnet/framework/wpf/wpf-partial-trust-security)

一般情况下，应该限制 Internet 应用程序直接访问关键系统资源，防止恶意损坏。 默认情况下， HTML ，客户端脚本编写语言也不能访问关键系统资源。 因为 Windows Presentation Foundation (WPF) 可从浏览器启动浏览器承载的应用程序，它们应该符合一组类似的限制。 若要强制实施这些限制WPF同时依赖于代码访问安全性 (CAS)并ClickOnce(请参阅[WPF 安全策略-平台安全性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/wpf-security-strategy-platform-security))。 默认情况下，浏览器承载的应用程序请求 Internet 区域CAS组的权限，而不考虑是否从 Internet、 本地 intranet 或本地计算机启动。 如果应用程序的运行权限小于完整权限集，则说明该应用程序正在部分信任环境下运行。

WPF 提供各种支持，以确保在部分信任，并连同，，可以安全地使用尽可能多的功能CAS，为部分信任编程提供额外支持。

本主题包含以下各节：

- [WPF 功能部分信任支持](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/wpf-partial-trust-security#WPF_Feature_Partial_Trust_Support)
- [部分信任编程](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/wpf-partial-trust-security#Partial_Trust_Programming)
- [管理权限](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/wpf-partial-trust-security#Managing_Permissions)

### WPF 功能部分信任支持

下表列出了安全的 Internet 区域权限集的限制范围内使用的高级功能的 Windows Presentation Foundation (WPF)。

表 1:在部分信任环境中的安全的 WPF 功能

| 功能区域 | 功能                                                         |
| -------- | ------------------------------------------------------------ |
| 常规     | 浏览器窗口  源站点访问  IsolatedStorage（512KB 限制）  UIAutomation 提供程序  命令  输入法编辑器 (IME)  触笔和墨迹  使用鼠标捕获和移动事件模拟的拖/放  OpenFileDialog  XAML 反序列化（通过 XamlReader.Load） |
| Web 集成 | 浏览器下载对话框  顶级用户启动的导航  mailto:links  统一资源标识符参数  HTTPWebRequest  IFRAME 中托管的 WPF 内容  使用框架托管同一站点 HTML 页  使用 WebBrowser 托管同一站点 HTML 页  Web 服务 (ASMX)  Web 服务（使用 Windows Communication Foundation）  “脚本”  文档对象模型 |
| 视觉对象 | 2D 和 3D  动画  媒体（源站点和跨域）  图像处理/音频/视频     |
| 阅读     | 流文档  XPS 文档  嵌入式字体与系统字体  CFF 字体与 TrueType 字体 |
| 编辑     | 拼写检查  RichTextBox  纯文本和墨迹剪贴板支持  用户启动的粘贴  复制选定内容 |
| Controls | 常规控件                                                     |

此表涵盖了WPF在高级别的功能。 有关更多详细信息，Windows 软件开发包 (SDK)文档中的每个成员所需的权限WPF。 此外，以下功能含有部分信任执行的相关详细信息，其中包括特殊注意事项。

- XAML (请参阅[XAML 概述 (WPF)](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-overview-wpf))。
- 弹出窗口 (请参阅[System.Windows.Controls.Primitives.Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup))。
- 拖放到 (请参阅[拖放概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/drag-and-drop-overview))。
- 剪贴板 (请参阅[System.Windows.Clipboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.clipboard))。
- 映像 (请参阅[System.Windows.Controls.Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image))。
- 序列化 (请参阅[XamlReader.Load](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.xamlreader.load)， [XamlWriter.Save](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.xamlwriter.save))。
- 打开文件对话框 (请参阅[Microsoft.Win32.OpenFileDialog](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.win32.openfiledialog))。

下表概括了WPF不安全的 Internet 的限制范围内运行的功能区域权限集。

表 2:在部分信任环境中不安全的 WPF 功能

| 功能区域 | 功能                                                         |
| -------- | ------------------------------------------------------------ |
| 常规     | 窗口（应用程序定义的窗口和对话框）  SaveFileDialog  文件系统  注册表访问  拖放  XAML 序列化（通过 XamlWriter.Save）  UIAutomation 客户端  源窗口访问 (HwndHost)  完全语音支持  Windows 窗体互操作性 |
| 视觉对象 | 位图效果  图像编码                                           |
| 编辑     | RTF 格式剪贴板  完全 XAML 支持                               |

###部分信任编程

有关XBAP应用程序，超出默认权限集的代码将具有不同的行为依赖于安全区域。 在某些情况下，用户会在尝试安装它时收到警告。 用户可以选择继续或取消安装。 下表描述每个安全区域的应用程序的行为，以及为了使应用程序接收完全信任而必须执行的操作。

| 安全区域                | 行为                     | 获取完全信任                                       |
| ----------------------- | ------------------------ | -------------------------------------------------- |
| 本地计算机              | 自动完全信任             | 无需执行任何操作。                                 |
| Intranet 和受信任的站点 | 提示完全信任             | 使用证书对 XBAP 进行签名，以便用户在提示中看到源。 |
| Internet                | 失败，并显示“未授予信任” | 使用证书对 XBAP 进行签名。                         |

> 上表中描述的行为针对不遵循 ClickOnce 受信任部署模型的完全信任 XBAP。

通常，超出允许权限的代码可能是在独立应用程序和浏览器托管的应用程序之间共享的公用代码。 CAS 和WPF提供用于管理此方案中的几种方法。

#### 使用 CAS 检测权限

在某些情况下，很可能共享中的代码库程序集以供这两个独立应用程序和XBAP。 这时，代码执行的功能所需要的权限可能超出应用程序的授权权限集允许的权限。 你的应用程序可以检测有特定的权限的使用 Microsoft.NET Framework 安全性。 具体而言，它可以测试它是否有特定的权限通过调用[Demand](https://docs.microsoft.com/zh-cn/dotnet/api/system.security.codeaccesspermission.demand)所需权限的实例上的方法。 以下示例对此进行了演示，示例中的代码查询其是否能够将文件保存到本地磁盘：

```csharp
using System.IO;
using System.IO.IsolatedStorage;
using System.Security;
using System.Security.Permissions;
using System.Windows;

namespace SDKSample
{
    public class FileHandling
    {
        public void Save()
        {
            if (IsPermissionGranted(new FileIOPermission(FileIOPermissionAccess.Write, @"c:\newfile.txt")))
            {
                // Write to local disk
                using (FileStream stream = File.Create(@"c:\newfile.txt"))
                using (StreamWriter writer = new StreamWriter(stream))
                {
                    writer.WriteLine("I can write to local disk.");
                }
            }
            else
            {
                MessageBox.Show("I can't write to local disk.");
            }
        }

        // Detect whether or not this application has the requested permission
        bool IsPermissionGranted(CodeAccessPermission requestedPermission)
        {
            try
            {
                // Try and get this permission
                requestedPermission.Demand();
                return true;
            }
            catch
            {
                return false;
            }
        }
    }
}
```

如果应用程序没有所需的权限，对调用[Demand](https://docs.microsoft.com/zh-cn/dotnet/api/system.security.codeaccesspermission.demand)将引发安全异常。 如果没有引发异常，则表示已授予该权限。 `IsPermissionGranted` 封装此行为，并返回`true`或`false`根据需要。

#### 功能下降

对可从不同区域执行的代码而言，能够检测代码是否具有完成所需操作的权限是很有意义的。 能够检测区域固然不错，但如果能够为用户提供替代方法，则要好得多。 例如，完全信任应用程序通常使用户能够在所需的任何位置创建文件，而部分信任应用程序只能在独立存储中创建文件。 如果用于创建文件的代码存在于完全信任（独立）应用程序和部分信任（浏览器托管的）应用程序共享的程序集中，并且这两个应用程序都希望用户能够创建文件，则共享代码应首先检测其是在部分信任环境还是完全信任环境中运行，然后才能在适当的位置创建文件。 下面的代码对这两种情况进行了演示。

```csharp
using System.IO;
using System.IO.IsolatedStorage;
using System.Security;
using System.Security.Permissions;
using System.Windows;

namespace SDKSample
{
    public class FileHandlingGraceful
    {
        public void Save()
        {
            if (IsPermissionGranted(new FileIOPermission(FileIOPermissionAccess.Write, @"c:\newfile.txt")))
            {
                // Write to local disk
                using (FileStream stream = File.Create(@"c:\newfile.txt"))
                using (StreamWriter writer = new StreamWriter(stream))
                {
                    writer.WriteLine("I can write to local disk.");
                }
            }
            else
            {
                // Persist application-scope property to 
                // isolated storage
                IsolatedStorageFile storage = IsolatedStorageFile.GetUserStoreForApplication();
                using (IsolatedStorageFileStream stream = 
                    new IsolatedStorageFileStream("newfile.txt", FileMode.Create, storage))
                using (StreamWriter writer = new StreamWriter(stream))
                {
                    writer.WriteLine("I can write to Isolated Storage");
                }
            }
        }

        // Detect whether or not this application has the requested permission
        bool IsPermissionGranted(CodeAccessPermission requestedPermission)
        {
            try
            {
                // Try and get this permission
                requestedPermission.Demand();
                return true;
            }
            catch
            {
                return false;
            }
        }
    }
}
```

在很多情况下，应该能够找到部分信任替代方法。

在受控环境中，如 intranet，自定义托管的框架可以安装整个客户端群到全局程序集缓存 (GAC)。 这些库可以执行需要完全信任的代码，只允许使用部分信任的应用程序从引用[AllowPartiallyTrustedCallersAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.security.allowpartiallytrustedcallersattribute)(有关详细信息，请参阅[安全](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/security-wpf)和[WPF 安全性策略-平台安全性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/wpf-security-strategy-platform-security))。

#### 浏览器主机检测

使用CAS以检查是否有权限是恰当的方法时您需要根据每个权限检查。 然而，这一技巧依赖于在正常处理过程中捕获异常（通常不鼓励这样做），并且可能导致性能问题。 相反，如果你XAML 浏览器应用程序 (XBAP)只在 Internet 区域沙箱内的运行，可以使用[BrowserInteropHelper.IsBrowserHosted](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.browserinterophelper.isbrowserhosted)属性，返回 true XAML 浏览器应用程序 (XBAP)。

> [IsBrowserHosted](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.browserinterophelper.isbrowserhosted) 是否在浏览器中，没有哪个应用程序的权限集运行与运行应用程序仅将区分开来。

### 管理权限

默认情况下，XBAP以部分信任级别 （默认 Internet 区域权限集） 运行。 但是，根据应用程序的要求，可以更改默认的权限集。 例如，如果XBAP启动时从本地 intranet，它可以充分利用增强的权限集下, 表中所示。

表 3:LocalIntranet 和 Internet 权限

| 权限       | 特性                  | LocalIntranet | Internet |
| ---------- | --------------------- | ------------- | -------- |
| DNS        | 访问 DNS 服务器       | 是            | 否       |
| 环境变量   | 读取                  | 是            | 否       |
| 文件对话框 | 打开                  | 是            | 是       |
| 文件对话框 | 不受限制              | 是            | 否       |
| 独立存储   | 按用户隔离程序集      | 是            | 否       |
| 独立存储   | 未知隔离              | 是            | 是       |
| 独立存储   | 无限制用户配额        | 是            | 否       |
| 媒体       | 安全音频、视频和图像  | 是            | 是       |
| 打印       | 默认打印              | 是            | 否       |
| 打印       | 安全打印              | 是            | 是       |
| 映像       | 发出                  | 是            | 否       |
| 安全性     | 托管代码执行          | 是            | 是       |
| 安全性     | 声明授予的权限        | 是            | 否       |
| 用户界面   | 不受限制              | 是            | 否       |
| 用户界面   | 安全顶级窗口          | 是            | 是       |
| 用户界面   | 自己的剪贴板          | 是            | 是       |
| Web 浏览器 | HTML 中的安全框架导航 | 是            | 是       |

> 如果由用户启动，则剪切和粘贴只允许以部分信任方式执行。

如果需要增加权限，则需要更改项目设置和 ClickOnce 应用程序清单。 有关详细信息，请参阅 [WPF XAML 浏览器应用程序概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/wpf-xaml-browser-applications-overview)。 以下各个文档可能也会有帮助。

- [Mage.exe（清单生成和编辑工具）](https://docs.microsoft.com/zh-cn/dotnet/framework/tools/mage-exe-manifest-generation-and-editing-tool)。
- [MageUI.exe（图形化客户端中的清单生成和编辑工具）](https://docs.microsoft.com/zh-cn/dotnet/framework/tools/mageui-exe-manifest-generation-and-editing-tool-graphical-client)。
- [保护 ClickOnce 应用程序](https://docs.microsoft.com/zh-cn/visualstudio/deployment/securing-clickonce-applications)。

如果你XBAP需要完全信任，可以使用相同的工具来提高所请求的权限。 尽管XBAP将仅接收完全信任，如果它是安装并启动从本地计算机上，在 intranet 或从受信任或允许的站点在浏览器中列出的 URL。 如果从 Intranet 或受信任站点安装应用程序，则用户会收到标准 ClickOnce 提示，通知用户提升了权限。 用户可以选择继续或取消安装。

或者，可以使用 ClickOnce 受信任部署模型从任何安全区域中进行完全信任部署。 有关详细信息，请参阅[Trusted Application Deployment Overview](https://docs.microsoft.com/zh-cn/visualstudio/deployment/trusted-application-deployment-overview)并[安全](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/security-wpf)。

## [WPF Security Strategy - Platform Security](https://docs.microsoft.com/en-us/dotnet/framework/wpf/wpf-security-strategy-platform-security)

虽然 Windows Presentation Foundation (WPF) 提供了各种安全服务，它还利用基础平台 （包括操作系统） 的安全功能CLR，和Internet Explorer。 这些层组合在一起旨在提供 WPF 强大且深层防御的安全模型，尝试避免任何单点故障，如下图所示：

![WPF 安全性图示](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/media/windowplatformsecurity.png)

本主题的其余部分主要讨论与 WPF 相关的各个层。

### 操作系统安全

WPF 要求的操作系统最低级别是 Windows XP SP2。 核心Windows XP SP2提供了多个安全功能，构成所有 Windows 应用程序，包括那些使用生成的安全基础WPF。 Windows Vista 包含 WPF 的安全功能并对其进行了进一步扩展。 本主题详细介绍了对 WPF 至关重要的这些安全功能，以及 WPF 如何与这些功能集成从而提供深层防御方面的知识。

#### Microsoft Windows XP Service Pack 2 (SP2)

除了常规的评审和增强的 Windows，有三个主要功能Windows XP SP2，我们将讨论此主题中：

- /GS 编译
- Microsoft Windows 更新。

##### /GS 编译

Windows XP SP2 通过对众多核心系统库进行重新编译提供保护，这些核心系统库包括所有 WPF 依赖项（如 CLR以帮助缓解缓冲区溢出。 通过使用/GS 形参和 C/C++ 命令行编译器可实现这一点。 虽然应显式避免缓冲区溢出，但 /GS 编译针对由它们无意或恶意创建的潜在漏洞提供了深层防御示例。

以前，缓冲区溢出已导致出现了许多影响较大的安全漏洞。 当攻击者利用代码漏洞时就会发生缓冲区溢出，代码漏洞可让注入的恶意代码通过缓冲区边界写入。 从而让攻击者可以通过重写导致执行攻击者代码的函数返回地址执行代码进程。 结果，恶意代码可以执行具有截获进程相同特权的任意代码。

在较高级别，/GS 编译器标志通过注入特殊安全 cookie 保护部分潜在缓冲区溢出，从而保护具有本地字符串缓冲区的函数返回地址。 函数返回后，安全 cookie 将与其上一个值进行比较。 如果值已更改，可能已发生缓冲区溢出，并且该进程已停止并显示错误条件。 停止的进程将阻止执行潜在的恶意代码。 请参阅[/GS （缓冲区安全检查）](https://msdn.microsoft.com/library/8dbf701c.aspx)的更多详细信息。

WPF 已使用/GS 标志进行编译，旨在对 WPF 应用程序增加另一层防御。

##### Microsoft Windows Update 增强功能

Microsoft Windows 更新 也对 Windows XP SP2 进行了改进，以简化用于下载和安装更新的过程。 这些更改通过帮助确保其系统（尤其是设计到安全更新）处于最新状态，显著地增强了 WPF 客户的安全。

#### Windows Vista

Windows Vista 上的 WPF 用户将从操作系统其他的安全增强功能中受益，这些功能包括“Least-Privilege User Access(最小特权用户访问)”、代码完整性检查以及特权隔离。

##### 用户帐户控制 (UAC)

目前，Windows 用户往往会因为许多应用程序需要它们的安装和/或执行，使用管理员特权运行。 其中一个示例就是，可以将默认应用程序设置写入到注册表。

使用管理员特权运行实际上就是指应用程序从授予管理员特权的进程执行。 此方法的安全影响在于，可截获使用管理员特权运行的进程的任何恶意代码都将自动继承这些特权，包括对关键系统资源的访问权限。

保护计算机免受此安全威胁的一种方法就是使用所需的最少特权数运行应用程序。 这就是通常所说的最低特权原则，也是 Windows Vista 操作系统的核心功能。 此功能称为用户帐户控制 (UAC)，被 Windows Vista UAC 使用，主要有两种使用方式：

- 若要在默认情况下使用 UAC 特权运行大多数应用程序，即使用户是管理员，也只有需要使用管理员特权的应用程序才会使用管理员特权运行。 要使用管理特权运行，必须以应用程序清单形式或作为安全策略中的一个条目显式标记应用程序。
- 提供兼容性解决方案(如虚拟化)。 例如，许多应用程序尝试写入受限位置，例如 C:\Program Files。 对于在 UAC 中执行的应用程序，存在基于用户的可选位置无需管理员特权就能写入。 对于在 UAC 中运行的应用程序，UAC 可虚拟化 C:\Program Files，这样认为其写入到其中的应用程序实际上是写入到基于用户的可选位置。 这种兼容性工作可使操作系统来运行许多以前无法在 UAC 中运行的应用程序。

##### 代码完整性检查

Windows Vista 集成了更深入的代码完整性检查，有助于防止恶意代码在负载/运行时注入到系统文件或内核。 这超出了系统文件保护。

#### 浏览器承载的应用程序的受限权限进程

浏览器承载的 WPF 应用程序在 Internet 区域沙箱内执行。 WPF 与 Microsoft Internet Explorer 集成扩展了此保护，可提供其他支持。

##### Internet Explorer 6 Service Pack 2 和适用于 XP 的 Internet Explorer 7

WPF 通过限制 XAML 浏览器应用程序 (XBAP) 的进程特权利用操作系统安全提供进一步的保护。 在启动浏览器承载的 WPF 应用程序之前，操作系统会创建一个宿主进程，用于删除进程令牌中不必要的特权。 删除的特权的部分示例包括：关闭用户的计算机、加载驱动程序以及读取计算机上所有文件的访问权限的能力。

##### 适用于 Vista 的 Internet Explorer 7

在 Windows Internet Explorer 7 中，WPF 应用程序以受保护模式运行。 具体而言，XAML 浏览器应用程序 (XBAP)以中等级别的完整性运行。

##### 深层防御层

由于 XAML 浏览器应用程序 (XBAP) 通常都是通过 Internet 区域权限集设置的沙盒，因此，删除这些权限不会损害 XAML 浏览器应用程序 (XBAP) 的兼容性。 反而会创建一个附加的深层防御层；如果经过沙箱处理的应用程序能够利用其他层截获此进程，该进程将仍然只有有限特权。

请参阅[使用最低权限用户帐户](https://docs.microsoft.com/previous-versions/tn-archive/cc700846%28v=technet.10%29)。

### 公共语言运行时的安全性

公共语言运行时 (CLR) 提供了多个主要安全优势，包括确认和验证、代码访问安全性 (CAS) 和安全关键方法。

#### 确认和验证

为了提供程序集隔离和完整性，CLR 将使用验证过程。 CLR 验证可确保程序集通过以下方式进行隔离：即通过验证其指向程序集外部地址的可移植可执行 (PE) 文件的格式。 CLR 验证还可以验证内嵌在程序集中的元数据的完整性。

若要确保类型安全，有助于防止常见安全问题 （例如缓冲区溢出） 和通过子进程隔离启用沙盒机制CLR安全使用了验证概念。

托管应用程序被编译为 Microsoft 中间语言 (MSIL)。 当执行托管应用程序中的方法时，将采用实时 (JIT) 编译方式把 MSIL 编译为本机代码。 JIT 编译包括的验证过程将应用许多众多安全和可靠规则，从而确保代码不会：

- 违反类型合约
- 引入缓冲区溢出
- 随意访问内存。

不允许不符合验证规则的托管代码执行，除非它被视为受信任代码。

可验证代码的优点是关键原因为何WPF基于.NET Framework。 从使用验证代码而言，利用潜在漏洞的可能性明显降低。

#### 代码访问安全性

客户端计算机公开了托管应用程序可以访问的各种资源，包括文件系统、注册表、打印服务、用户界面、反射和环境变量。 托管应用程序可以访问任何客户端计算机上的资源之前，它必须具有.NET Framework 权限来执行此操作。 CAS 中的权限是 [CodeAccessPermission](https://docs.microsoft.com/zh-cn/dotnet/api/system.security.codeaccesspermission) 的子类；CAS 可实现托管应用程序可以访问的各个资源的其中一个子类。

CAS 开始执行时授予托管应用程序的权限集称为一个权限集，由应用程序提供的证据确定。 对于 WPF 应用程序，提供的证据为从中启动应用程序的位置或区域。 CAS 可以标识以下区域：

- **我的电脑**。 从客户端计算机（完全受信任）上启动的应用程序。
- **本地 Intranet**。 从 Intranet 启动的应用程序。 （某种程度上受信任）。
- **Internet**。 从 Intranet 启动的应用程序。 （最不受信任）。
- **受信任的站点**。 由受信任用户标识的应用程序。 （最不受信任）。
- **不受信任的站点**。 由不受信任的用户标识的应用程序。 （不受信任）。

对于这些区域中的任一一个，CAS 都会提供一个预定义的权限集，包括可匹配与之关联的信任级别的权限。 这些问题包括：

- **FullTrust**。 对于从启动应用程序**我的电脑**区域。 将授予全部可能的权限。
- **LocalIntranet**。 对于从启动应用程序**本地 Intranet**区域。 将授予权限的子集，以提供对客户端计算机资源适度的访问权限，包括隔离存储、用户界面的无限制访问、无限制使用文件对话框、有限的反射和有限访问环境变量。 不提供对关键资源（如注册表）的权限。
- **Internet**。 对于从启动应用程序**Internet**或**受信任的站点**区域。 将授予权限的子集，以提供对客户端计算机资源有限的访问权限，包括隔离存储、仅限打开文件和有限的用户界面。 从根本上来说，此权限集将隔离客户端计算机中的应用程序。

应用程序标识为来自**不受信任的站点**区域会授予任何权限通过CAS根本。 因此，对它们而言，就不存在预定义的权限集。

下图说明了区域、权限集、权限和资源之间的关系。

![CAS 权限集](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/media/caspermissionsets.png)

Internet 区域安全沙盒的限制条件同样适用于 XBAP 从系统库导入的任何代码，包括 WPF。 这可确保代码的每一位都是锁定的，即便 WPF 也是如此。 遗憾的是，为了能够执行，XBAP 需要执行要求更多权限的功能，所需的权限比通过 Internet 区域安全沙盒启用的那些功能的权限还要多。

假设 XBAP 应用程序包括以下页面：

```csharp
FileIOPermission fp = new FileIOPermission(PermissionState.Unrestricted);
fp.Assert();

// Perform operation that uses the assert

// Revert the assert when operation is completed
CodeAccessPermission.RevertAssert();
```

要执行此 XBAPWPF 基础代码必须执行更多可用功能，而不止是调用 XBAP包括：

- 创建用于呈现的窗口句柄 (hWnd)
- 调度消息
- 加载 Tahoma 字体

从安全角度而言，允许从沙盒应用程序直接访问上述任何操作将会导致灾难性后果。

而 WPF 通过允许代表沙盒应用程序使用提升的特权来执行这些操作可解决这种情况。 虽然会根据 WPF 的应用程序域中的有限 Internet 区域安全权限检查所有 XBAP 操作，但 WPF（就像其他系统库一样）将获得包括所有可能权限的权限集

这就要求 WPF 接收提升的特权，同时阻止这些特权由宿主应用程序域的 Internet 区域权限集管理。

WPF 通过使用实现这**Assert**权限的方法。 以下代码演示了这种方法。

```csharp
FileIOPermission fp = new FileIOPermission(PermissionState.Unrestricted);
fp.Assert();

// Perform operation that uses the assert

// Revert the assert when operation is completed
CodeAccessPermission.RevertAssert();
```

**Assert**实质上是阻止所需的不受限制的权限WPF不会限制通过 Internet 区域权限XBAP。

从平台角度看，WPF负责使用**Assert**正确; 错误使用**Assert**可能启用恶意代码提升特权。 因此，很重要，应仅调用**Assert**需要时，可确保沙盒限制保持不变。 例如，禁止沙盒代码打开任意文件，但允许其使用字体。 WPF 允许沙盒应用程序使用字体功能，通过调用**Assert**，并为WPF读取已知包含这些字体代表沙盒应用程序文件。

#### ClickOnce 部署

ClickOnce 是一种全面的部署技术，包含在.NET Framework 中，并与集成Microsoft Visual Studio(请参阅[ClickOnce 部署概述](https://msdn.microsoft.com/library/142dbbz4.aspx)的详细信息)。 独立的 WPF 应用程序可以使用 ClickOnce 进行部署，但浏览器承载的应用程序必须使用 ClickOnce 进行部署。

使用 ClickOnce 部署的应用程序具有高于 代码访问安全性 (CAS) 的额外安全层；实质上，ClickOnce 部署的应用程序会请求所需的权限。 如果它们不超过在其中部署应用程序的区域的权限集，几乎仅授予它们这些权限。 通过将权限集减少至仅限于所需的权限集，即使它们小于通过启动区域权限集提供的那些权限集，应用程序可以访问的资源数也会减少至最低限度。 因此，如果截获到应用程序，将可以降低对客户端计算机的潜在损坏几率。

#### 安全-关键方法

WPF 代码可以使用权限启动 XBAP 应用程序的 Internet 区域沙盒，因此，必须将该代码保留到安全程度最高的审计和控制中。 若要实现此要求，.NET Framework 可提升特权的托管代码提供新的支持。 具体而言，CLR使您能够识别提升特权的代码并将其与标记[SecurityCriticalAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.security.securitycriticalattribute); 的任何代码未标有[SecurityCriticalAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.security.securitycriticalattribute)变得*透明*使用此方法。 反之，禁止未标有 [SecurityCriticalAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.security.securitycriticalattribute) 的托管代码提升特权。

安全关键方法允许的组织WPF提升到特权的代码*安全-关键核心*，使剩余部分透明。 隔离安全关键代码可使WPF工程团队关注高于标准安全实践的安全关键内核上的其他安全分析和源控件 (请参阅[WPF 安全策略-安全工程](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/wpf-security-strategy-security-engineering))。

请注意.NET Framework 允许受信任的代码来扩展XBAPInternet 区域沙盒： 允许开发人员编写标记为的托管程序集[AllowPartiallyTrustedCallersAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.security.allowpartiallytrustedcallersattribute)(APTCA) 并部署到用户的全局程序集缓存 (GAC)。 将程序集标记为 APTCA 是高度敏感的安全操作，因为它允许任何代码调用该程序集，包括来自 Internet 的恶意代码。 执行此操作时，要特别注意并且必须采用最佳做法，用户必须选择信任该软件才能完成安装。

### Microsoft Internet Explorer 安全

除减少安全问题和简化安全配置外，Microsoft Internet Explorer 6 (SP2) 还包含好几个增强安全的功能，从而提高了 XAML 浏览器应用程序 (XBAP) 用户的安全。 这些功能的主旨是尝试允许用户更好地控制它们的浏览体验。

在 IE6 SP2 之前，用户可能会受限于以下任一项：

- 随机弹出窗口。
- 混淆的脚本重定向。
- 某些网站上出现大量安全对话框。

在某些情况下，不受信任的网站将尝试通过诱导 用户界面 (UI) 安装或反复显示 Microsoft ActiveX 安装对话框（即使用户可能已取消）攻击用户。 使用这些技术，有可能会有相当多的用户上当受骗，从而导致安装间谍软件应用程序。

IE6 SP2 包括用于缓解围绕用户启动这些问题类型的多个功能。 IE6 SP2 当用户单击链接或页面元素之前的操作，这被称为上检测到*用户启动*，并将其与上一个页面的脚本在其他情况下触发类似操作时以不同方式。 例如，IE6 SP2合并**弹出窗口阻止程序**，用于检测在用户单击按钮之前页面创建弹出窗口时。 此程序可使 IE6 SP2 允许大多数没有威胁的弹出窗口，同时阻止用户既没有要求也不需要的弹出窗口。 阻止的弹出窗口被截获放在新**信息栏**，它允许用户在手动重写块和查看弹出窗口。

相同的用户启动逻辑也适用于**开放**/**保存**安全提示。 ActiveX 安装对话框始终显示在“信息栏”中，除非它们表示从以前安装的控件进行升级。 这些度量值组合在一起，可提供用户更安全、更可控的用户体验，因为诱导他们安装不需要的软件或恶意软件的站点受到了保护。

这些功能还可以对使用 IE6 SP2 浏览网站（允许他们下载和安装 WPF 应用程序）的用户提供保护。 特别是，这是因为 IE6 SP2 提供的用户体验更好，降低了安装恶意或“狡猾”的应用程序的几率，而不考虑用于构建它的技术类型，包括 WPF。 WPF 通过使用 ClickOnce 进一步增强这些保护，以便通过 Internet 下载其应用程序。 由于 XAML 浏览器应用程序 (XBAP) 是在 Internet 区域安全沙盒内执行，因此可以无缝地启动它们。 另一方面，独立的 WPF应用程序需要完全信任才能执行。 对于这些应用程序，ClickOnce 将在启动过程示安全对话框，以通知使用应用程序的其他安全要求。 但是，必须由用户启动，必须由用户启动的逻辑进行管理并且可以取消。

Internet Explorer 7包含并扩展了作为持续提供安全承诺一部分的 IE6 SP2 的安全功能。

## [WPF Security Strategy - Security Engineering](https://docs.microsoft.com/en-us/dotnet/framework/wpf/wpf-security-strategy-security-engineering)

可信计算是 Microsoft 为确保生成安全代码而首创的一项技术。 可信计算技术的一个关键元素是 Microsoft 安全开发生命周期 (SDL)。 SDL 是与标准工程过程一同用于简化提交安全代码的工程实践。 SDL 包含十个阶段，将规范化、可度量性和附加结构的最佳实践结合在一起，包括：

- 安全设计分析
- 基于工具的质量检查
- 渗透测试
- 最终安全评审
- 发布后产品安全管理

### WPF 详细信息

WPF 工程团队可以应用和扩展 SDL，该产品组合包括以下主要方面：

[威胁建模](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/wpf-security-strategy-security-engineering#threat_modeling)

[安全分析和编辑工具](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/wpf-security-strategy-security-engineering#tools)

[测试技术](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/wpf-security-strategy-security-engineering#techniques)

[关键代码管理](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/wpf-security-strategy-security-engineering#critical_code)

### 威胁建模

威胁建模是 SDL的核心组件，用于分析系统，以确定潜在的安全漏洞。 一旦确定漏洞，威胁模型还可以确保采取适当的缓解措施。

我们以一个杂货店为例，说明威胁模型在高级别上所涉及的以下关键步骤：

1. **确定资产**。 杂货店的资产可能包括员工、保险箱、收银机和库存。
2. **枚举入口点**。 杂货店的入口点可能包括前门和后门、窗户、装货区和空调设备。
3. **使用入口点调查针对资产的攻击**。 可能进行的攻击包括通过空调入口点来对杂货店的保险箱资产进行攻击；有人可能会将空调设备拆掉，将保险箱通过空调处拉出杂货店。

威胁建模应用于整个 WPF，包含以下各项：

- XAML 分析器读取文件、将文本映射到相应的对象模型类并创建实际代码的方式。
- 创建窗口句柄 (hWnd) 并通过其发送消息和呈现窗口内容的方式。
- 数据绑定获取资源以及与系统交互的方式。

这些威胁模型对于在开发过程中确定安全设计需求以及缓解威胁非常重要。

### 源分析和编辑工具

除 SDL 的手动安全代码评审元素外，WPF 团队使用多个工具进行源分析和关联编辑，目的是减少安全漏洞。 使用了多种源工具，包括以下各项：

- **FXCop**:在托管代码中包括继承规则、 代码访问安全的使用情况以及安全地与非托管代码交互操作的方式查找常见安全问题。 请参阅[FXCop](https://docs.microsoft.com/previous-versions/dotnet/netframework-3.0/bb429476%28v=vs.80%29)。
- **Prefix/Prefast**:例如缓冲区溢出、 格式字符串问题以及错误检查的非托管代码中查找安全漏洞和常见安全问题。
- **已禁止的 Api**:搜索源代码，以识别的函数的众所周知的而引发安全问题，如意外使用`strcpy`。 一旦识别出这些函数，将用更安全的替代函数来取代它们。

### 测试技术

WPF 使用多种安全测试技术，包括：

- **白盒测试**:测试人员查看源代码，，然后生成攻击测试
- **黑盒测试**:测试人员尝试查找通过检查 API 和功能，安全，然后尝试对产品进行攻击。
- **从其他产品问题进行回归安全**:相关，来自相关产品的安全问题进行测试。 例如，对于 Internet Explorer，已确定出大约六十个安全问题的相关变体，并已对它们在 WPF 上的适用性进行了测试。
- **借助文件模糊化执行基于工具的渗透测试**:文件模糊化执行是指利用文件读取器的输入范围的不同输入。 在 WPF 中的一个示例，使用此技术的一个示例就是检查图像解码代码的错误。

### 关键代码管理

有关XAML 浏览器应用程序 (XBAP)，WPF利用.NET Framework 支持标记和跟踪可提升特权的安全关键代码生成安全沙盒 (请参阅**安全关键方法**中[WPF安全策略-平台安全性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/wpf-security-strategy-platform-security))。 考虑到对安全关键代码有较高的安全质量要求，因此需要对此类代码进行其他级别的源管理控制和安全审核。 大约有 5% 到 10% 的 WPF 由安全关键代码组成，这些代码由专门的审核团队进行审核。 通过跟踪安全关键代码和将每个关键实体（即，包含关键代码的方法）映射到其签署状态来对源代码和签入过程进行管理。 签署状态包括一个或多个审阅者的姓名。 WPF 的每个日常版本都将关键代码与前一版本中的该代码进行比较，以检查未经审批的更改。 如果工程师未经审核团队的批准而自行修改关键代码，则将识别并立即修复该代码。 通过这一过程，可以对 WPF 沙盒代码应用级别特高的审核并加以维护。