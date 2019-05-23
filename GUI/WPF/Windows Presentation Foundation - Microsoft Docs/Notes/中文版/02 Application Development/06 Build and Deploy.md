# [Build and Deploy](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/building-and-deploying-wpf-applications)

生成和部署模型提供的功能生成和部署应用程序，本地或远程管理，其中包括：

- MSBuild:.NET 构建位于 Microsoft.Build.Tasks.Windows 命名空间中的系统。
- 资源： 处理用户界面资源。
- ClickOnce 部署：.NET 发布和部署系统。

## 本节内容

[生成 WPF 应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/building-a-wpf-application-wpf)
[部署 WPF 应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/deploying-a-wpf-application-wpf)

## [Building a WPF Application](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/building-a-wpf-application-wpf)

Windows Presentation Foundation (WPF) 应用程序可以生成为.NET Framework可执行文件 (.exe)、 库 (.dll) 或这两种类型的程序集的组合。 本主题将介绍如何生成 WPF 应用程序，并对生成过程中的各个关键步骤进行说明。

### 生成 WPF 应用程序

WPF 应用程序可通过以下方式编译：

- 命令行。 应用程序必须只包含代码（并非 XAML）和一个应用程序定义文件。 有关详细信息，请参阅[在命令行上使用 csc.exe 生成](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/command-line-building-with-csc-exe)或[从命令行生成 (Visual Basic)](https://docs.microsoft.com/zh-cn/dotnet/visual-basic/reference/command-line-compiler/building-from-the-command-line)。
- Microsoft 生成引擎 (MSBuild)。 除了代码和 XAML 文件之外，应用程序还必须包含一个 MSBuild 项目文件。有关详细信息，请参阅“MSBuild”。
- Visual Studio。 Visual Studio 是一个集成式开发环境，可编译使用 MSBuild 生成的 WPF 应用程序，并包含可用于创建 UI 的可视化设计器。 有关详细信息，请参阅[Visual Studio 中的应用程序开发](https://msdn.microsoft.com/library/97490c1b-a247-41fb-8f2c-bc4c201eff68)并[在 Visual Studio 中设计 XAML](https://docs.microsoft.com/zh-cn/visualstudio/designers/designing-xaml-in-visual-studio)。

### WPF 生成管道

在生成 WPF 项目时，会组合调用特定于语言的目标和特定于 WPF 的目标。 执行这些目标的进程被称为生成管道，相关的关键步骤已显示在下图中。

![WPF 生成过程](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/wpfbuildsystem-figure1.png)



### 预生成初始化

在生成之前，MSBuild 会先确定重要工具和库的相应位置，其中包括：

- .NET Framework 中。
- Windows SDK 目录。
- WPF 引用程序集的位置。
- 程序集搜索路径的属性。

MSBuild 首先会在引用程序集目录 (%ProgramFiles%\Reference Assemblies\Microsoft\Framework\v3.0\) 中搜索程序集。 在执行这个步骤时，生成进程还会初始化各种属性和项组，并执行所有必要的清理工作。



### 解析引用

生成进程会查找并绑定生成应用程序项目所需的程序集。 这个逻辑包含在 `ResolveAssemblyReference` 任务中。 在项目文件中声明为 `Reference` 的所有程序集会连同有关搜索路径的信息以及系统上已安装的程序集的元数据一并提供给任务。 该任务会查找程序集，并使用已安装的程序集的元数据来筛选出那些无需显示在输出清单中的核心 WPF 程序集。 这么做可以避免 ClickOnce 清单中出现冗余信息。 例如，由于 PresentationFramework.dll 可以被视为代表应用程序生成和有关WPF而且以来所有WPF程序集位于.NET Framework 的每台计算机上的相同位置安装，没有无需在清单中包含所有.NET Framework 引用程序集上的所有信息。



### 标记编译 - 第 1 次传递

这个步骤会分析并编译 XAML 文件，这样运行时便无需再花时间来分析 XML 并验证属性值。 编译型 XAML 文件会进行预标记，因此其在运行时的加载速度应该要远高于 XAML 文件的加载速度。

这个步骤会针对属于 `Page` 生成项的每一个 XAML 文件完成以下活动：

1. 由标记编译器对 XAML 文件进行分析。
2. 创建编译型 XAML 并将其复制到 obj\Release 文件夹。
3. 创建 CodeDOM 型新分部类并将其复制到 obj\Release 文件夹。

另外，还会针对每一个 XAML 文件生成特定于语言的代码文件。 例如，对于 Visual Basic 项目中的 Page1.xaml 页面，Page1.g.vb 生成;对于 C# 项目中的 Page1.xaml 页面，会生成 Page1.g.cs。 文件名中的“.g”表明文件包含的是生成的代码，这些代码针对标记文件的顶级元素（如 `Page` 或 `Window`）进行了分部类声明。 使用声明该类`partial`C# 中的修饰符 (`Extends`在 Visual Basic 中) 以指示该类在其他位置的另一个声明，通常在代码隐藏文件 page1.xaml.cs。

分部类扩展自相应的基类 (如[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)页面)，并实现[System.Windows.Markup.IComponentConnector](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.icomponentconnector)接口。[IComponentConnector](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.icomponentconnector)接口具有用于初始化组件和连接的名称和其内容中的元素上的事件的方法。 因此，生成的代码文件中都包含如下所示的方法实现：

C#复制

```csharp
public void InitializeComponent() {  
    if (_contentLoaded) {  
        return;  
    }  
    _contentLoaded = true;  
    System.Uri resourceLocater =   
        new System.Uri(  
            "window1.xaml",   
            System.UriKind.RelativeOrAbsolute);  
    System.Windows.Application.LoadComponent(this, resourceLocater);  
}  
```

默认情况下，运行在同一个标记编译[AppDomain](https://docs.microsoft.com/zh-cn/dotnet/api/system.appdomain)作为MSBuild引擎。 这可以显著提高性能。 此行为可通过 `AlwaysCompileMarkupFilesInSeparateDomain` 属性来切换。 这一优点是： 通过卸载单独卸载所有引用程序集[AppDomain](https://docs.microsoft.com/zh-cn/dotnet/api/system.appdomain)。



### 标记编译 - 第 2 次传递

并非所有 XAML 页面都会在标记编译的第 1 次传递过程中完成编译。 包含本地定义类型引用（引用同一项目中其他位置的代码所定义的类型）的 XAML 文件就不会在此期间进行编译。 这是因为这些本地定义的类型仅存在于源中，并且尚未编译。 分析器会采用试探法来确定文件是否已编译，而这一操作会涉及在标记文件中查找 `x:Name`之类的项。 如果找到此类实例，标记文件的编译将会推迟，直至代码文件完成编译；在代码文件完成编译后，标记文件会在第二次标记编译传递期间得到处理。



### 文件分类

生成进程会根据输出文件将被置于哪个应用程序集中，将输出文件放入不同的资源组。 在典型的非本地化应用程序中，所有被标记为 `Resource` 的数据文件都会置于主程序集（可执行文件或库）中。 如果在项目中设置了 `UICulture`，则所有编译型 XAML 文件以及那些专门标记为特定于语言的资源会置于附属资源程序集中。 此外，所有中性语言资源都会置于主程序集中。 生成进程会在执行这个步骤时确定放置位置。

项目文件中的 `ApplicationDefinition`、`Page` 和 `Resource` 生成操作可以使用 `Localizable` 元数据（可接受的值为 `true` 和 `false`）来扩充，该元数据会指明文件是特定于语言的文件还是中性语言文件。



### 内核编译

内核编译步骤涉及代码文件的编译。 这要由特定于语言的目标文件 Microsoft.CSharp.targets 和 Microsoft.VisualBasic.targets 中的逻辑来协调。 如果试探法确定标记编译器只需要进行一次传递，则会生成主程序集。 但是，如果项目中的一个或多个 XAML 文件引用了本地定义的类型，则会生成一个临时的.dll 文件，最终的应用程序集则可能会在标记编译的第二次传递完成后再创建。



### 清单生成

生成进程的最后一步是：在所有应用程序集和内容文件都准备就绪后，为应用程序生成 ClickOnce 清单。

部署清单文件可描述部署模型：当前版本、更新行为、发布服务器标识以及数字签名。 该清单应由负责处理部署的管理员来编写。 对于 XAML 浏览器应用程序 (XBAP)，这个文件的扩展名为 .xbap；对于已安装的应用程序，扩展名则为 .application。 前者受 `HostInBrowser` 项目属性支配，因此清单会将应用程序标识为由浏览器承载。

应用程序清单（一个 .exe.manifest 文件）可描述应用程序集和依赖库，并列出应用程序所需的权限。 该文件应由应用程序开发者编写。 为了启动 ClickOnce 应用程序，用户会打开该应用程序的部署清单文件。

对于 XBAP，始终会创建这些清单文件。 对于已安装的应用程序，这些文件不会创建，除非在项目文件中为 `GenerateManifests` 属性指定值 `true`。

XBAP 获取这些权限分配给典型 Internet 区域应用程序之上的两个额外权限：[WebBrowserPermission](https://docs.microsoft.com/zh-cn/dotnet/api/system.security.permissions.webbrowserpermission)和[MediaPermission](https://docs.microsoft.com/zh-cn/dotnet/api/system.security.permissions.mediapermission)。 WPF 生成系统会在应用程序清单中声明这些权限。

### 增量生成支持

WPF 生成系统可以为增量生成提供支持。 该系统能以非常智能化的方式来检测对标记或代码所做的各种更改，而且只会编译那些受到更改操作影响的项目。 增量生成机制会使用以下文件：

- $(*AssemblyName*)_MarkupCompiler.Cache 文件，用于维护当前的编译器状态。
- $(*AssemblyName*)_MarkupCompiler.lref 文件，用于缓存引用了本地定义类型的 XAML 文件。

下面显示了一组用于控制增量生成的规则：

- 文件是生成系统检测更改时的最小单位。 因此，对于代码文件，生成系统无法判断类型是否已更改或者是否添加了代码。 对于项目文件也是如此。
- 增量生成机制必须确定 XAML 页面是定义了一个类，还是使用了其他类。
- 如果 `Reference` 条目发生变化，则会重新编译所有页面。
- 如果代码文件发生变化，则会重新编译引用了本地定义类型的所有页面。
- 如果 XAML 文件发生变化：
  - 如果 XAML 在项目中被声明为 `Page`：如果 XAML 没有引用本地定义的类型，则会重新编译 XAML 以及包含本地引用的所有 XAML 页面；如果 XAML 包含本地引用，则会重新编译包含本地引用的所有 XAML页面。
  - 如果XAML被声明为`ApplicationDefinition`项目中： 重新编译所有XAML页面 (原因： 每个XAML具有对引用[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)可能已更改的类型)。
- 如果项目文件将代码文件声明为应用程序定义，而不是 XAML 文件：
  - 检查项目文件中的 `ApplicationClassName` 值是不是发生了变化（是不是有新的应用程序类型？）。 如果是，则重新编译整个应用程序。
  - 否则，重新编译包含本地引用的所有 XAML 页面。
- 如果项目文件发生变化：应用前面的所有规则，并确认哪些内容需要重新编译。 以下属性发生变化会触发全面的重新编译：`AssemblyName`、`IntermediateOutputPath`、`RootNamespace` 和 `HostInBrowser`。

可能会出现以下重新编译情形：

- 重新编译整个应用程序。
- 仅重新编译那些引用了本地定义类型的 XAML 文件。
- 不会重新编译任何内容（如果项目未发生任何变化）。

## [Deploying a WPF Application](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/deploying-a-wpf-application-wpf)

Windows Presentation Foundation (WPF) 应用程序构建后，它们需要部署。 Windows 和.NET Framework 包括多项部署技术。 用于部署 WPF 应用程序的部署技术取决于应用程序的类型。 本主题将简要概述各项部署技术，以及如何使用这些技术来满足各类 WPF 应用程序的部署要求。

### 部署技术

Windows 和.NET Framework 包括多项部署技术，包括：

- XCopy 部署。
- Windows Installer 部署。
- ClickOnce 部署。

#### XCopy 部署

XCopy 部署是指使用 XCopy 命令行程序将文件从一个位置复制到另一个位置。 XCopy 部署适用于下列情况：

- 应用程序是自包含的。 无需更新客户端，即可运行。
- 应用程序文件必须从一个位置移到另一个位置，如从生成位置（本地磁盘、UNC 文件共享等）移到发布位置（网站、UNC 文件共享等）。
- 应用程序无需进行 Shell 集成（“开始”菜单快捷方式、桌面图标等）。

XCopy 适用于简单的部署方案；如果需要更为复杂的部署功能，则会限制使用 XCopy。 具体而言就是，使用 XCopy 往往会导致创建、执行并维护能以可靠方式管理部署的脚本，并进而产生相应的开销。 此外，XCopy 不支持版本控制、卸载或回滚。

#### Windows Installer

Windows Installer 允许应用程序打包为可轻松分发到客户端并运行的自包含可执行文件。 此外，Windows Installer 会随 Windows 一起安装，并能与桌面、“开始”菜单及“程序”控制面板集成。

Windows Installer 简化了应用程序的安装和卸载，但它不会提供相应工具以确保已安装的应用程序始终为最新版本。

有关 Windows Installer 的详细信息，请参阅 [Windows Installer 部署](https://msdn.microsoft.com/library/121be21b-b916-43e2-8f10-8b080516d2a0)。

#### ClickOnce 部署

ClickOnce 能够针对非 Web 应用程序进行 Web 样式应用程序部署。 应用程序会发布到 Web 或文件服务器，也会从 Web 或文件服务器进行部署。 尽管 ClickOnce 不支持 Windows Installer 安装的应用程序所支持的所有客户端功能，但它支持其中的部分功能，包括：

- 与“开始”菜单及“程序”控制面板集成。
- 版本控制、回滚和卸载。
- 联机安装模式，该模式始终会从部署位置启动应用程序。
- 当有新版本发布时自动更新。
- 注册文件扩展名。

有关 ClickOnce 的详细信息，请参阅 [ClickOnce 安全和部署](https://docs.microsoft.com/zh-cn/visualstudio/deployment/clickonce-security-and-deployment)。

### 部署 WPF 应用程序

适用于 WPF 应用程序的部署选项取决于应用程序的类型。 从部署的角度来看，WPF 共有三种重要的应用程序类型：

- 独立应用程序。
- 仅标记 XAML 应用程序。
- XAML 浏览器应用程序 (XBAP)。

#### 部署独立应用程序

独立应用程序使用 ClickOnce 或 Windows Installer 来部署。 无论使用哪一项，独立应用程序都要在完全信任的状态下才能运行。 使用 Windows Installer 部署的独立应用程序会被自动授予完全信任状态。 使用 ClickOnce 部署的独立应用程序不会被自动授予完全信任状态。 ClickOnce 会转而显示安全警告对话框，用户必须先执行接受操作，然后独立应用程序才会安装。 如果接受，独立应用程序就会安装并被授予完全信任状态。 如果不接受，则独立应用程序不会安装。

#### 部署仅标记 XAML 应用程序

仅标记 XAML 页面通常会发布到 Web 服务器（如 HTML 页面），并可以使用 Internet Explorer 来查看。 仅标记 XAML 页面会按照 Internet 区域权限集定义的限制，在部分信任的安全沙箱内运行。 这样即可提供一个与基于 HTML 的 Web 应用程序一样安全的沙箱。

有关 WPF 应用程序安全性的详细信息，请参阅[安全性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/security-wpf)。

仅标记 XAML 页面可以利用 XCopy 或 Windows Installer 安装到本地文件系统。 可以使用查看这些页面Internet Explorer或 Windows 资源管理器。

有关 XAML 的详细信息，请参阅 [XAML 概述 (WPF)](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-overview-wpf)。

### 部署 XAML 浏览器应用程序

XBAP 是需要部署以下三个文件的编译型应用程序：

- *ApplicationName*.exe:可执行程序集应用程序文件。
- *ApplicationName*.xbap:部署清单。
- *ApplicationName*.exe.manifest 的清单：应用程序清单。

> 有关部署和应用程序清单的详细信息，请参阅[生成 WPF 应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/building-a-wpf-application-wpf)。

这些文件在 XBAP 生成时产生。 有关详细信息，请参阅[如何：创建新的 WPF 浏览器应用程序项目](https://msdn.microsoft.com/library/72ef4d90-e163-42a1-8df0-ea7ccfd1901f)。 和仅标记XAML 页面一样，XBAP 通常会发布到 Web 服务器并使用 Internet Explorer 来查看。

XBAP 可以使用任意部署技术部署到客户端。 但是，建议使用 ClickOnce，因为它提供以下功能：

1. 当有新版本发布时自动更新。
2. 适用于在完全信任状态下运行的 XBAP 的提升权限。

默认情况下，ClickOnce 会使用.deploy 扩展名来发布应用程序文件。 这可能会引发问题，但可被禁用。 有关详细信息，请参阅 [ClickOnce 部署中的服务器和客户端配置问题](https://docs.microsoft.com/zh-cn/visualstudio/deployment/server-and-client-configuration-issues-in-clickonce-deployments)。

有关部署 XAML 浏览器应用程序 (XBAP) 的详细信息，请参阅 [WPF XAML 浏览器应用程序概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/wpf-xaml-browser-applications-overview)。

### 安装 .NET Framework

若要运行WPF应用程序，必须在客户端上安装 Microsoft.NET Framework。 Internet Explorer 使用.NET Framework 是否安装了客户端将自动检测时WPF查看浏览器承载的应用程序。 如果未安装.NET Framework，Internet Explorer会提示用户安装它。

若要检测是否安装了.NET Framework，Internet Explorer包括一个引导程序应用程序注册为回退多用途 Internet 邮件扩展 (MIME)具有以下扩展名的内容文件的处理程序：.xaml、.xps、.xbap 和.application。 如果你导航到这些文件类型，并且在客户端上未安装.NET Framework，引导程序应用程序请求权限以完成安装。 如果未提供权限，.NET Framework 和应用程序都不会安装。

如果授予权限，Internet Explorer下载并安装.NET Framework 使用Microsoft 后台智能传输服务 (BITS)。 安装成功后的.NET framework，最初请求的文件是在新的浏览器窗口中打开。

.NET framework 自动检测已接入Windows Vista， Microsoft Windows XP Service Pack 2 (SP2)，并Microsoft Windows Server 2003 (SP1)具有的客户端Internet Explorer 7或更高版本。

有关详细信息，请参阅[部署 .NET Framework 和应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/deployment/index)。

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/build-and-deploy-how-to-topics)

以下主题说明如何创建针对各种项目文件WPF应用程序类型。

### 本节内容

[将 IIS 5.0 和 IIS 6.0 配置为部署 WPF 应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/how-to-configure-iis-5-0-and-iis-6-0-to-deploy-wpf-applications)
[将 Visual Studio 配置为通过调试 XAML 浏览器应用程序来调用 Web 服务](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/configure-vs-to-debug-a-xaml-browser-to-call-a-web-service)
[确定已安装的 WPF 版本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/how-to-determine-the-installed-version-of-wpf)
[检测是否安装了 .NET Framework 3.0](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/how-to-detect-whether-the-net-framework-3-0-is-installed)
[检测是否安装了 .NET Framework 3.5](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/how-to-detect-whether-the-net-framework-3-5-is-installed)
[检测是否安装了适用于 Firefox 的 WPF 插件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/how-to-detect-whether-the-wpf-plug-in-for-firefox-is-installed)

### [Configure IIS 5.0 and IIS 6.0 to Deploy WPF Applications](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/how-to-configure-iis-5-0-and-iis-6-0-to-deploy-wpf-applications)

可以从大多数 Web 服务器部署 Windows Presentation Foundation (WPF) 应用程序，前提是这些服务器配置了相应的 多用途 Internet 邮件扩展 (MIME) 类型。 默认情况下，Microsoft Internet 信息服务 (IIS) 7.0 配置有这些MIME 类型，但 Microsoft Internet Information Services (IIS) 5.0 和 Microsoft Internet Information Services (IIS) 6.0 未配置。

本主题介绍如何配置 Microsoft Internet Information Services (IIS) 5.0 和 Microsoft Internet Information Services (IIS) 6.0 以部署 WPF 应用程序。

> 你可以检查*UserAgent*注册表项以确定系统是否具有安装的.NET Framework 中的字符串。 有关详细信息和检查的脚本*UserAgent*字符串以确定是否在系统上安装.NET Framework，请参阅[检测是否安装.NET Framework 3.0 是](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/how-to-detect-whether-the-net-framework-3-0-is-installed)。

#### 调整内容过期设置

应将内容过期设置调整为 1 分钟。 以下过程概述了如何通过 IIS 执行此操作。

1. 单击“开始”菜单，指向“管理工具”，然后单击“Internet Information Services (IIS) 管理器”。 还可以使用“%systemroot%\system32\inetsrv\iis.msc”从命令行启动此应用程序。
2. 展开 IIS 树，直到找到“默认网站”节点。
3. 右键单击“默认网站”，然后从上下文菜单中选择“属性”。
4. 选择“HTTP 头”选项卡，然后单击“启用内容过期”。
5. 将内容设置为在 1 分钟后过期。

#### 注册 MIME 类型和文件扩展名

必须注册几种 MIME 类型和文件扩展名，以便客户端系统上的浏览器才能加载正确的处理程序。 需要添加以下类型：

| 扩展名       | MIME 类型                      |
| ------------ | ------------------------------ |
| .manifest    | application/manifest           |
| .xaml        | application/xaml+xml           |
| .application | application/x-ms-application   |
| .xbap        | application/x-ms-xbap          |
| .deploy      | application/octet-stream       |
| .xps         | application/vnd.ms-xpsdocument |

> 不需要在客户端系统上注册 MIME 类型或文件扩展名。 当你安装 Microsoft.NET Framework 时，它们会自动注册。

下面的 Microsoft Visual Basic Scripting Edition (VBScript) 示例会自动将添加所需MIME类型IIS。 若要使用该脚本，请将代码复制到服务器上的 .vbs 文件。 然后，通过从命令行运行该文件或在 Microsoft Windows 资源管理器中双击该文件来运行脚本。

```
' This script adds the necessary Windows Presentation Foundation MIME types   
' to an IIS Server.  
' To use this script, just double-click or execute it from a command line.  
' Running this script multiple times results in multiple entries in the IIS MimeMap.  
  
Dim MimeMapObj, MimeMapArray, MimeTypesToAddArray, WshShell, oExec  
Const ADS_PROPERTY_UPDATE = 2   
  
' Set the MIME types to be added  
MimeTypesToAddArray = Array(".manifest", "application/manifest", ".xaml", _  
    "application/xaml+xml", ".application", "application/x-ms-application", _  
    ".deploy", "application/octet-stream", ".xbap", "application/x-ms-xbap", _  
    ".xps", "application/vnd.ms-xpsdocument")   
  
' Get the mimemap object   
Set MimeMapObj = GetObject("IIS://LocalHost/MimeMap")  
  
' Call AddMimeType for every pair of extension/MIME type  
For counter = 0 to UBound(MimeTypesToAddArray) Step 2  
    AddMimeType MimeTypesToAddArray(counter), MimeTypesToAddArray(counter+1)  
Next  
  
' Create a Shell object  
Set WshShell = CreateObject("WScript.Shell")  
  
' Stop and Start the IIS Service  
Set oExec = WshShell.Exec("net stop w3svc")  
Do While oExec.Status = 0  
    WScript.Sleep 100  
Loop  
  
Set oExec = WshShell.Exec("net start w3svc")  
Do While oExec.Status = 0  
    WScript.Sleep 100  
Loop  
  
Set oExec = Nothing  
  
' Report status to user  
WScript.Echo "Windows Presentation Foundation MIME types have been registered."  
  
' AddMimeType Sub  
Sub AddMimeType (Ext, MType)  
  
    ' Get the mappings from the MimeMap property.   
    MimeMapArray = MimeMapObj.GetEx("MimeMap")   
  
    ' Add a new mapping.   
    i = UBound(MimeMapArray) + 1   
    Redim Preserve MimeMapArray(i)   
    Set MimeMapArray(i) = CreateObject("MimeMap")   
    MimeMapArray(i).Extension = Ext   
    MimeMapArray(i).MimeType = MType   
    MimeMapObj.PutEx ADS_PROPERTY_UPDATE, "MimeMap", MimeMapArray  
    MimeMapObj.SetInfo  
  
End Sub  
```

> 多次运行该脚本会在 Microsoft Internet Information Services (IIS) 5.0 或 Microsoft Internet Information Services (IIS) 6.0 元数据库中创建多个 MIME 映射项。

运行该脚本后，可能不会从 Microsoft Internet Information Services (IIS) 5.0 或 Microsoft Internet Information Services (IIS) 6.0 Microsoft 管理控制台 (MMC) 中看到其他 MIME 类型。 但是，这些 MIME 类型已添加到Microsoft Internet Information Services (IIS) 5.0 或 Microsoft Internet Information Services (IIS) 6.0 元数据库。 以下脚本将显示 Microsoft Internet Information Services (IIS) 5.0 或 Microsoft Internet Information Services (IIS) 6.0元数据库中的所有 MIME 类型。

```
' This script lists the MIME types for an IIS Server.  
' To use this script, just double-click or execute it from a command line   
' by calling cscript.exe  
  
dim mimeMapEntry, allMimeMaps  
  
' Get the mimemap object.  
Set mimeMapEntry = GetObject("IIS://localhost/MimeMap")  
allMimeMaps = mimeMapEntry.GetEx("MimeMap")  
  
' Display the mappings in the table.  
For Each mimeMap In allMimeMaps  
    WScript.Echo(mimeMap.MimeType & " (" & mimeMap.Extension + ")")  
Next  
```

将脚本另存为 `.vbs` 文件（例如，`DiscoverIISMimeTypes.vbs`），并使用以下命令从命令提示符运行它：

```
cscript DiscoverIISMimeTypes.vbs
```

### [Configure Visual Studio to Debug a XAML Browser Application to Call a Web Service](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/configure-vs-to-debug-a-xaml-browser-to-call-a-web-service)

XAML 浏览器应用程序 (XBAP) 在 Internet 区域权限集仅限于部分信任安全沙箱中运行。 此权限集将限制仅 Web 服务位于 Web 服务调用XBAP应用程序的源站点。 当XBAP调试从 Visual Studio 2005 中，不过，它不被视为具有相同的源站点的 Web 服务它的引用。 这会导致安全异常时引发XBAP尝试调用 Web 服务。 但是，Visual Studio 2005XAML 浏览器应用程序 (WPF)项目可以配置为模拟有与它进行调试时将调用 Web 服务相同的源站点。 这允许XBAP来安全地调用 Web 服务，而不会导致安全异常。

#### 配置 Visual Studio

若要配置 Visual Studio 2005 来调试XBAP调用 Web 服务：

1. 在“解决方案资源管理器” 中选择了项目的情况下，在“项目” 菜单上单击“属性” 。

2. 在中**项目设计器**，单击**调试**选项卡。

3. 在中**启动操作**部分中，选择**启动外部程序**并输入以下命令：

   `C:\WINDOWS\System32\PresentationHost.exe`

4. 在中**启动选项**部分中，输入到以下**命令行参数**文本框中：

   `-debug` *filename*

   *文件名*值 **-调试**参数是.xbap 文件名; 例如：

   `-debug c:\example.xbap`

> 这是使用 Visual Studio 2005 创建的解决方案的默认配置XAML 浏览器应用程序 (WPF)项目模板。

1. 在“解决方案资源管理器” 中选择了项目的情况下，在“项目” 菜单上单击“属性” 。

2. 在中**项目设计器**，单击**调试**选项卡。

3. 在中**启动选项**部分中，添加以下命令行参数**命令行参数**文本框中：

   `-debugSecurityZoneURL` URL

   *URL*值 **-debugSecurityZoneURL**参数是URL你想要模拟不会成为您的应用程序源站点的位置。

例如，考虑XAML 浏览器应用程序 (XBAP)Web 服务使用以下URL:

```
http://services.msdn.microsoft.com/ContentServices/ContentService.asmx
```

源站点的URL为此 Web 服务是：

```
http://services.msdn.microsoft.com
```

因此，完整 **-debugSecurityZoneURL**命令行参数和值是：

```
-debugSecurityZoneURL http://services.msdn.microsoft.com
```

### [Determine the Installed Version of WPF](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/how-to-determine-the-installed-version-of-wpf)

当前安装的版本的版本号Windows Presentation Foundation (WPF)位于**注册表**。

若要查找的版本号：

1. 在“开始” 菜单上，单击“运行” 。
2. 在**打开**，类型**regedit.exe**。
3. 打开以下项：

```
HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\NET Framework Setup\NDP\v3.0\Setup\Windows Presentation Foundation
```

WPF版本号存储在**版本**值。

### [Detect Whether the .NET Framework 3.0 Is Installed](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/how-to-detect-whether-the-net-framework-3-0-is-installed)

管理员可部署的系统上的 Microsoft.NET Framework 应用程序之前，他们必须首先确认存在的.NET Framework 运行时。 本主题提供了 HTML/JavaScript 中编写的脚本管理员可用来确定.NET Framework 是否存在的系统上。

> 有关详细安装信息，部署和检测 Microsoft.NET Framework，请参阅中的讨论[部署 Microsoft.NET Framework 版本 3.0](https://go.microsoft.com/fwlink/?LinkId=96739)。



#### 检测到".NET CLR"用户代理字符串

安装.NET Framework，MSI 将".NET CLR"和版本号添加到用户代理字符串。 下面的示例演示一个简单的 HTML 页面中嵌入的脚本。 该脚本将搜索用户代理字符串以确定是否安装.NET Framework，并在搜索结果中显示的状态消息。

```
<HTML>  
  <HEAD>  
    <TITLE>Test for the .NET Framework 3.0</TITLE>  
    <META HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=utf-8" />  
    <SCRIPT LANGUAGE="JavaScript">  
    <!--  
    var dotNETRuntimeVersion = "3.0.04425.00";  
  
    function window::onload()  
    {  
      if (HasRuntimeVersion(dotNETRuntimeVersion))  
      {  
        result.innerText =   
          "This machine has the correct version of the .NET Framework 3.0: "   
          + dotNETRuntimeVersion  
      }   
      else  
      {  
        result.innerText =   
          "This machine does not have the correct version of the .NET Framework 3.0."  
      }  
      result.innerText += "\n\nThis machine's userAgent string is: " +   
        navigator.userAgent + ".";  
    }  
  
    //  
    // Retrieve the version from the user agent string and   
    // compare with the specified version.  
    //  
    function HasRuntimeVersion(versionToCheck)  
    {  
      var userAgentString =   
        navigator.userAgent.match(/.NET CLR [0-9.]+/g);  
  
      if (userAgentString != null)  
      {  
        var i;  
  
        for (i = 0; i < userAgentString.length; ++i)  
        {  
          if (CompareVersions(GetVersion(versionToCheck),   
            GetVersion(userAgentString[i])) <= 0)  
            return true;  
        }  
      }  
  
      return false;  
    }  
  
    //  
    // Extract the numeric part of the version string.  
    //  
    function GetVersion(versionString)  
    {  
      var numericString =   
        versionString.match(/([0-9]+)\.([0-9]+)\.([0-9]+)/i);  
      return numericString.slice(1);  
    }  
  
    //  
    // Compare the 2 version strings by converting them to numeric format.  
    //  
    function CompareVersions(version1, version2)  
    {  
      for (i = 0; i < version1.length; ++i)  
      {  
        var number1 = new Number(version1[i]);  
        var number2 = new Number(version2[i]);  
  
        if (number1 < number2)  
          return -1;  
  
        if (number1 > number2)  
          return 1;  
      }  
  
      return 0;  
    }  
  
    -->  
    </SCRIPT>  
  </HEAD>  
  
  <BODY>  
    <div id="result" />  
  </BODY>  
</HTML>  
```

如果为".NET CLR"版本搜索成功，将显示以下类型的状态消息：

```
This machine has the correct version of the .NET Framework 3.0: 3.0.04425.00
This machine's userAgent string is: Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 5.1; .NET CLR 1.1.4322; InfoPath.1; .NET CLR 2.0.50727; .NET CLR 3.0.04425.00).
```

否则，将显示以下类型的状态消息：

```
This machine does not have correct version of the .NET Framework 3.0.
This machine's userAgent string is: Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 5.1; .NET CLR 1.1.4322; InfoPath.1; .NET CLR 2.0.50727).
```

### [Detect Whether the .NET Framework 3.5 Is Installed](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/how-to-detect-whether-the-net-framework-3-5-is-installed)

管理员可部署的系统上的 Windows Presentation Foundation (WPF) 应用程序之前.NET Framework 3.5，它们必须先确认.NET Framework 3.5运行时已存在。 本主题提供了编写的脚本在 HTML/JavaScript，管理员可以用于确定是否.NET Framework 3.5系统上存在。

> 有关更多详细信息上安装、 部署和检测.NET Framework，请参阅[安装面向开发人员的.NET Framework](https://docs.microsoft.com/zh-cn/dotnet/framework/install/guide-for-developers)。

#### 示例

当.NET Framework 3.5是安装，MSI 向".NET CLR"和版本号的 UserAgent 字符串。 下面的示例演示一个简单的 HTML 页面中嵌入的脚本。 脚本搜索用户代理字符串以确定是否.NET Framework 3.5安装，并在搜索结果中显示的状态消息。

> 此脚本旨在为 Internet 资源管理器。 其他浏览器可能不包括用户代理字符串中的.NET CLR 的信息。

```
<HTML>  
  <HEAD>  
    <TITLE>Test for the .NET Framework 3.5</TITLE>  
    <META HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=utf-8" />  
    <SCRIPT LANGUAGE="JavaScript">  
    <!--  
    var dotNETRuntimeVersion = "3.5.0.0";  
  
    function window::onload()  
    {  
      if (HasRuntimeVersion(dotNETRuntimeVersion))  
      {  
        result.innerText =   
          "This machine has the correct version of the .NET Framework 3.5."  
      }   
      else  
      {  
        result.innerText =   
          "This machine does not have the correct version of the .NET Framework 3.5." +  
          " The required version is v" + dotNETRuntimeVersion + ".";  
      }  
      result.innerText += "\n\nThis machine's userAgent string is: " +   
        navigator.userAgent + ".";  
    }  
  
    //  
    // Retrieve the version from the user agent string and   
    // compare with the specified version.  
    //  
    function HasRuntimeVersion(versionToCheck)  
    {  
      var userAgentString =   
        navigator.userAgent.match(/.NET CLR [0-9.]+/g);  
  
      if (userAgentString != null)  
      {  
        var i;  
  
        for (i = 0; i < userAgentString.length; ++i)  
        {  
          if (CompareVersions(GetVersion(versionToCheck),   
            GetVersion(userAgentString[i])) <= 0)  
            return true;  
        }  
      }  
  
      return false;  
    }  
  
    //  
    // Extract the numeric part of the version string.  
    //  
    function GetVersion(versionString)  
    {  
      var numericString =   
        versionString.match(/([0-9]+)\.([0-9]+)\.([0-9]+)/i);  
      return numericString.slice(1);  
    }  
  
    //  
    // Compare the 2 version strings by converting them to numeric format.  
    //  
    function CompareVersions(version1, version2)  
    {  
      for (i = 0; i < version1.length; ++i)  
      {  
        var number1 = new Number(version1[i]);  
        var number2 = new Number(version2[i]);  
  
        if (number1 < number2)  
          return -1;  
  
        if (number1 > number2)  
          return 1;  
      }  
  
      return 0;  
    }  
  
    -->  
    </SCRIPT>  
  </HEAD>  
  
  <BODY>  
    <div id="result" />  
  </BODY>  
</HTML>  
```

如果为".NET CLR"版本搜索成功，将显示以下类型的状态消息：

```
This machine has the correct version of the .NET Framework 3.5.
This machine's userAgent string is: Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 6.0; SLCC1; .NET CLR 2.0.50727; .NET CLR 1.1.4322; InfoPath.2; .NET CLR 3.0.590; .NET CLR 3.5.20726; MS-RTC LM 8).
```

否则，将显示以下类型的状态消息：

```
This machine does not have the correct version of the .NET Framework 3.5. The required version is v3.5.0.0.
This machine's userAgent string is: Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 6.0; SLCC1; .NET CLR 2.0.50727; .NET CLR 1.1.4322; InfoPath.2; .NET CLR 3.0.590; MS-RTC LM 8).
```

### [Detect Whether the WPF Plug-In for Firefox Is Installed](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/how-to-detect-whether-the-wpf-plug-in-for-firefox-is-installed)

Windows Presentation Foundation (WPF) Firefox 的插件使XAML 浏览器应用程序 (XBAP)和松散 XAML 文件 Mozilla Firefox 浏览器中运行。 本主题提供了用 HTML 和 JavaScript，管理员可以用于确定是否已安装 Firefox 的插件的 WPF 编写的脚本。

> 有关安装、 部署和检测的详细信息.NET Framework，请参阅[安装面向开发人员的.NET Framework](https://docs.microsoft.com/zh-cn/dotnet/framework/install/guide-for-developers)。

#### 示例

当.NET Framework 3.5是安装，客户端计算机配置与 WPF 插件为 Firefox。 以下示例脚本检查 firefox 的 WPF 插件，然后显示相应的状态消息。

```
<HTML>  
  
  <HEAD>  
    <TITLE>Test for the WPF plug-in for Firefox</TITLE>  
    <META HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=utf-8" />  
    <SCRIPT type="text/javascript">  
    <!--  
    function OnLoad()  
    {  
  
       // Check for the WPF plug-in for Firefox and report  
       var msg = "The WPF plug-in for Firefox is ";  
       var wpfPlugin = navigator.plugins["Windows Presentation Foundation"];  
       if( wpfPlugin != null ) {  
          document.writeln(msg + " installed.");  
       }  
       else {  
          document.writeln(msg + " not installed. Please install or reinstall the .NET Framework 3.5.");  
       }  
    }  
    -->  
    </SCRIPT>  
  </HEAD>  
  
  <BODY onload="OnLoad()" />  
  
</HTML>  
```

如果 Firefox 的 wpf 插件检查成功，显示以下状态消息：

```
The WPF plug-in for Firefox is installed.
```

否则，会显示以下状态消息：

```
The WPF plug-in for Firefox is not installed. Please install or reinstall the .NET Framework 3.5.
```