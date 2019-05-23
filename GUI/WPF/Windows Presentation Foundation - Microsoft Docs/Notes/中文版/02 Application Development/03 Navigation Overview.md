# [Navigation Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/navigation-overview)

Windows Presentation Foundation (WPF) 支持两种类型的应用程序可以使用的浏览器样式导航： 独立应用程序和XAML 浏览器应用程序 (XBAP)。 对包内容的导航窗格中，WPF提供了[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)类。 可以从一个导航[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)到另一个以声明方式，通过使用[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)，或以编程方式使用[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)。 WPF 使用日志记住从其导航和导航回它们的页。

[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)， [NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)，和日志组成的核心部分提供的导航支持WPF。 本概述探讨这些功能的详细信息，然后介绍高级的导航支持，包括导航到松散可扩展应用程序标记语言 (XAML)文件，HTML文件和对象。

 备注

在本主题中，术语"浏览器"仅指可以托管的浏览器WPF应用程序，当前包括Microsoft Internet Explorer和 Firefox。 在特定WPF功能仅受特定浏览器，浏览器版本引用。

## WPF 应用程序中的导航

本主题概述中的键导航功能WPF。 这些功能可供这两个独立应用程序和XBAP，但本主题介绍了它们的上下文中XBAP。

> 备注本主题不讨论如何生成和部署XBAP。 有关详细信息XBAP，请参阅[WPF XAML 浏览器应用程序概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/wpf-xaml-browser-applications-overview)。

本节解释并演示导航的以下方面：

- [实现页](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-overview#CreatingAXAMLPage)
- [配置起始页](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-overview#Configuring_a_Start_Page)
- [配置主机窗口的标题、宽度和高度](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-overview#ConfiguringAXAMLPage)
- [超链接导航](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-overview#NavigatingBetweenXAMLPages)
- [片段导航](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-overview#FragmentNavigation)
- [导航服务](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-overview#NavigationService)
- [使用导航服务以编程方式导航](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-overview#Programmatic_Navigation_with_the_Navigation_Service)
- [导航生存期](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-overview#Navigation_Lifetime)
- [使用日志记住导航](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-overview#NavigationHistory)
- [页生存期和日志](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-overview#PageLifetime)
- [保留导航历史记录的内容状态](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-overview#RetainingContentStateWithNavigationHistory)
- [Cookie](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-overview#Cookies)
- [结构化导航](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-overview#Structured_Navigation)

### 实现页

在中WPF，可以导航到多个内容类型，包括.NET Framework 对象、 自定义对象、 枚举值、 用户控件XAML文件，和HTML文件。 但是，你会发现打包内容最常见和最简便方法是使用[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)。 此外，[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)实现特定于导航的功能来增强外观并简化开发。

使用[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)，你可以以声明方式实现的导航页XAML通过使用如下所示的标记内容。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation" />
```

一个[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)中实现XAML标记已`Page`作为其根元素和需要WPFXML命名空间声明。 `Page`元素包含你想要导航到并显示的内容。 通过设置添加内容`Page.Content`属性元素，如以下标记所示。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation">
  <Page.Content>
    <!-- Page Content -->
    Hello, Page!
  </Page.Content>
</Page>
```

`Page.Content` 只能包含一个子元素，在前面的实例中，内容是一个单独的字符串“Hello, Page!”。 在实践中，您通常将使用布局控件作为子元素 (请参阅[布局](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/layout)) 来包含并创建你的内容。

子元素`Page`元素的内容被视为[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)，因此，您不必使用显式`Page.Content`声明。 以下标记和前面的示例在声明上是等效的。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation">
  <!-- Page Content -->
  Hello, Page!
</Page>
```

在这种情况下，`Page.Content`会自动设置的子元素的`Page`元素。 有关详细信息，请参阅 [WPF 内容模型](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/wpf-content-model)。

仅标记[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)对显示内容很有用。 但是，[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)还可以显示允许用户与页面进行交互的控件，它可以通过处理事件和调用应用程序逻辑来响应用户交互。 交互式[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)如下面的示例中所示，通过使用标记和代码隐藏的组合实现。

```xaml
<Page
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.HomePage">
  Hello, from the XBAP HomePage!
</Page>
```

```csharp
using System.Windows.Controls;

namespace SDKSample
{
    public partial class HomePage : Page
    {
        public HomePage()
        {
            InitializeComponent();
        }
    }
}
```

要允许标记文件和代码隐藏文件协同工作，需要进行以下配置：

- 在标记中，`Page`元素必须包括`x:Class`属性。 应用程序生成时，是否存在`x:Class`在标记文件会导致Microsoft Build Engine (MSBuild)来创建`partial`派生的类[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)并且具有指定的名称`x:Class`属性。 这需要添加XML命名空间声明XAML架构 ( `xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"` )。 生成`partial`类实现`InitializeComponent`，调用它来注册事件并设置属性的标记中实现。
- 在代码隐藏中，类必须是`partial`具有相同名称指定的类`x:Class`属性在标记中，并且它必须派生自[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)。这允许要与之关联的代码隐藏文件`partial`生成应用程序时，为标记文件生成的类 (请参阅[构建 WPF 应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/building-a-wpf-application-wpf))。
- 在代码隐藏[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)类必须实现构造函数调用`InitializeComponent`方法。 `InitializeComponent` 实现由标记文件中生成的`partial`类，以注册事件和设置在标记中定义的属性。

> 添加一个新[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)到你的项目使用Microsoft Visual Studio，则[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)使用标记和代码隐藏实现，它包括必要的配置来创建作为标记和代码隐藏文件之间的关联此处所述。

一旦您有[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)，可以导航到它。 若要指定第一个[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)应用程序导航到，您需要配置开始[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)。

### 配置起始页

XBAP 需要一定数量的应用程序结构以在浏览器中托管。 在中WPF，则[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)类是建立所需应用程序基础结构应用程序定义的一部分 (请参阅[应用程序管理概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/application-management-overview))。

应用程序定义通常与标记文件配置为使用标记和代码隐藏实现MSBuild`ApplicationDefinition`项。 以下是有关应用程序定义XBAP。

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

XBAP可以使用其应用程序定义指定起始[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)，即[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)时，自动加载XBAP启动。 执行此操作通过设置[StartupUri](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.startupuri)具有属性统一资源标识符 (URI)的所需[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)。

> 在大多数情况下，[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)被编译到或使用应用程序部署。 在这些情况下， URI ，用于标识[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)是一个包URI，即URI符合*pack*方案。 包URI讨论了中进一步[WPF 中的 Pack Uri](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/pack-uris-in-wpf)。 也可使用 http 方案导航到内容，这将在以下内容中讨论。

可以设置[StartupUri](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.startupuri)以声明方式在标记中，如下面的示例中所示。

```xaml
<Application
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.App"
    StartupUri="PageWithHyperlink.xaml" />
```

在此示例中，`StartupUri`属性设置的相对 packURI标识 HomePage.xaml。 当XBAP是启动，HomePage.xaml 自动导航到并显示。 下图显示了这一点XBAP从 Web 服务器中启动。

![XBAP page](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/navigationoverviewfigure9.png)

> 有关开发和部署的详细信息XBAP，请参阅[WPF XAML 浏览器应用程序概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/wpf-xaml-browser-applications-overview)并[部署 WPF 应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/deploying-a-wpf-application-wpf)。



### 配置主机窗口的标题、宽度和高度

您可能已经注意到从上图中的一件事是浏览器和选项卡面板的标题是URI为XBAP。 除了长，标题既没什么吸引力也没什么帮助。 出于此原因，[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)提供了一种方法，以便通过设置来更改标题[WindowTitle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page.windowtitle)属性。 此外，可以通过设置配置的宽度和高度的浏览器窗口[WindowWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page.windowwidth)和[WindowHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page.windowheight)分别。

[WindowTitle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page.windowtitle)[WindowWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page.windowwidth)，和[WindowHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page.windowheight)可设置，以声明方式在标记中，如以下示例所示。

```xaml
<Page
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.HomePage"
    WindowTitle="Page Title"
    WindowWidth="500"
    WindowHeight="200">
  Hello, from the XBAP HomePage!
</Page>
```

结果如下图所示。

![窗口标题、高度、宽度](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/navigationoverviewfigure2.png)



### 超链接导航

典型XBAP包含多页。 导航到另一个页面中的最简单方法是使用[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)。 您可以以声明方式添加[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)到[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)通过使用`Hyperlink`元素，以下标记所示。

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

一个`Hyperlink`元素具有以下要求：

- 包URI的[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)以导航到，所指定的`NavigateUri`属性。
- 内容，用户可以单击初始化导航，如文本和图像 (内容的`Hyperlink`元素可以包含，请参阅[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink))。

下图显示XBAP与[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)具有[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)。

![具有超链接的页](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/navigationoverviewfigure3.png)

如您所料，单击[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)会导致XBAP以导航到[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)由标识`NavigateUri`属性。 此外，XBAP前添加一个条目[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)到中的最新页列表Internet Explorer。 如下图所示。

![“后退”和“前进”按钮](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/navigationoverviewfigure4.png)

除了支持从一个导航[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)到另一个，[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)还支持片段导航。

### 片段导航

*片段导航*是当前的内容片段中导航[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)或另一个[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)。 在WPF，内容片段是命名元素所包含的内容。 命名的元素是具有的元素，其`Name`属性设置。 以下标记显示了名为`TextBlock`元素，其中包含内容片段。

```xaml
<Page
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    WindowTitle="Page With Fragments" >
```

```xaml
<!-- Content Fragment called "Fragment1" -->
<TextBlock Name="Fragment1">
  Ea vel dignissim te aliquam facilisis ...
</TextBlock>
```

```xaml
</Page>
```

有关[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)导航到内容片段`NavigateUri`属性必须包括以下：

- URI的[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)以导航到的内容片段。
- “#”字符。
- 在元素的名称[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)，其中包含内容片段。

片段URI采用以下格式。

*PageURI* `#` *ElementName*

以下举例说明了`Hyperlink`，它配置为导航到内容片段。

```xaml
<Page
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  WindowTitle="Page That Navigates To Fragment" >
```

```xaml
<Hyperlink NavigateUri="PageWithFragments.xaml#Fragment1">
  Navigate To pack Fragment
</Hyperlink>
```

```xaml
</Page>
```

> 本部分介绍中的默认片段导航实现WPF。 WPF 此外允许您实现您自己的片段导航方案的一部分，需要处理[NavigationService.FragmentNavigation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice.fragmentnavigation)事件。

> 您可以导航到片段中松散XAML页 (仅标记XAML文件的工具`Page`作为根元素) 才可以通过浏览页面HTTP。

但是，松散XAML页可以导航到自己的片段。

### 导航服务

虽然[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)允许用户导航初始化到特定[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)，查找并下载该页的工作由执行[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)类。 从根本上来说，[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)提供的功能处理导航请求代表客户端代码，如[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)。 此外，[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)实现更高级别的支持来跟踪并影响导航需求。

当[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)单击时，WPF调用[NavigationService.Navigate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice.navigate)查找和下载[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)指定的包在URI。 下载[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)转换为其根对象是已下载的实例的对象树[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)。 对根目录的引用[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)对象存储在[NavigationService.Content](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice.content)属性。 包URI导航到的内容存储在[NavigationService.Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice.source)属性，而[NavigationService.CurrentSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice.currentsource)存储 packURI导航到的最后一页。

> 很可能WPF应用程序有多个当前处于活动状态[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)。 有关详细信息，请参阅[导航主机](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-overview#Navigation_Hosts)本主题中更高版本。

### 使用导航服务以编程方式导航

无需了解的有关[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)如果在标记中使用以声明方式实现导航[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)，因为[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)使用[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)代表你。 这意味着，只要的直接或间接父级[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)是导航主机 (请参阅[导航主机](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-overview#Navigation_Hosts))，[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)将能够查找并使用导航主机导航服务来处理导航请求。

但是，有些情况需要使用[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)直接，其中包括：

- 当需要进行实例化[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)使用非默认构造函数。
- 当需要进行设置的属性[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)导航到它之前。
- 当[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)，需要以导航到只能确定在运行时。

在这些情况下，您需要编写代码来以编程方式通过调用启动导航[Navigate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice.navigate)方法的[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)对象。 这就需要获取对引用[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)。

#### 获取对 NavigationService 的引用

中介绍的原因[导航宿主](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-overview#Navigation_Hosts)部分中，WPF应用程序可以有多个[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)。 这意味着你的代码需要一种方法，以查找[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)，这通常是[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)，导航到当前[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)。 可以获取对的引用[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)通过调用`static`[NavigationService.GetNavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice.getnavigationservice)方法。 若要获取[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)，导航到特定[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)，可传递到引用[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)作为参数的[GetNavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice.getnavigationservice)方法。 下面的代码演示如何获取[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)当前[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)。

```csharp
using System.Windows.Navigation;
```

```csharp
// Get a reference to the NavigationService that navigated to this Page
NavigationService ns = NavigationService.GetNavigationService(this);
```

作为查找的快捷方式[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)有关[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)，[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)实现[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page.navigationservice)属性。 这在下面的示例中显示。

```csharp
using System.Windows.Navigation;
```

```csharp
// Get a reference to the NavigationService that navigated to this Page
NavigationService ns = this.NavigationService;
```

> 一个[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)只能获取对其[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)时[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)引发[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)事件。

#### 以编程方式导航到页对象

下面的示例演示如何使用[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)若要以编程方式导航到[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)。 以编程方式导航是必需的因为[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)，它是要导航到可以仅使用实例化一个单一的非默认构造函数。 [Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)具有非默认构造函数所示的以下标记和代码。

```xaml
<Page
    x:Class="SDKSample.PageWithNonDefaultConstructor"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    Title="PageWithNonDefaultConstructor">
  
  <!-- Content goes here -->
  
</Page>
```

```csharp
using System.Windows.Controls;

namespace SDKSample
{
    public partial class PageWithNonDefaultConstructor : Page
    {
        public PageWithNonDefaultConstructor(string message)
        {
            InitializeComponent();

            this.Content = message;
        }
    }
}
```

[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)导航到[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)具有非默认构造函数所示的以下标记和代码。

```xaml
<Page
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.NSNavigationPage">

  <Hyperlink Click="hyperlink_Click">
    Navigate to Page with Non-Default Constructor
  </Hyperlink>

</Page>
```

```csharp
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;

namespace SDKSample
{
    public partial class NSNavigationPage : Page
    {
        public NSNavigationPage()
        {
            InitializeComponent();
        }

        void hyperlink_Click(object sender, RoutedEventArgs e)
        {
            // Instantiate the page to navigate to
            PageWithNonDefaultConstructor page = new PageWithNonDefaultConstructor("Hello!");

            // Navigate to the page, using the NavigationService
            this.NavigationService.Navigate(page);
        }
    }
}
```

当[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)对此[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)是单击，启动了导航是通过实例化[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)导航到使用非默认构造函数和调用[NavigationService.Navigate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice.navigate)方法。 [Navigate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice.navigate) 接受对对象的引用的[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)将导航到，而不是一个包URI。

#### 使用 Pack URI 以编程方式导航

如果你需要构建 packURI以编程方式 (当只能确定 packURI在运行时，例如)，可以使用[NavigationService.Navigate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice.navigate)方法。 这在下面的示例中显示。

```xaml
<Page
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.NSUriNavigationPage">
  <Hyperlink Click="hyperlink_Click">Navigate to Page by Pack URI</Hyperlink>
</Page>
```

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;

namespace SDKSample
{
    public partial class NSUriNavigationPage : Page
    {
        public NSUriNavigationPage()
        {
            InitializeComponent();
        }

        void hyperlink_Click(object sender, RoutedEventArgs e)
        {
            // Create a pack URI
            Uri uri = new Uri("AnotherPage.xaml", UriKind.Relative);

            // Get the navigation service that was used to 
            // navigate to this page, and navigate to 
            // AnotherPage.xaml
            this.NavigationService.Navigate(uri);
        }
    }
}
```

#### 刷新当前页

一个[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)不会下载它，如果它具有相同的包URI的包URI存储在[NavigationService.Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice.source)属性。 若要强制WPF若要再次下载当前页，可以调用[NavigationService.Refresh](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice.refresh)方法，如以下示例所示。

```xaml
<Page
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.NSRefreshNavigationPage">
 <Hyperlink Click="hyperlink_Click">Refresh this page</Hyperlink>
</Page>
```

```csharp
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;

namespace SDKSample
{
    public partial class NSRefreshNavigationPage : Page
    {
```

```csharp
        void hyperlink_Click(object sender, RoutedEventArgs e)
        {
            // Force WPF to download this page again
            this.NavigationService.Refresh();
        }
    }
}
```

### 导航生存期

如你所见，有很多方法初始化导航。 发起导航，并导航时，可以跟踪并影响导航使用由实现的以下事件时[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice):

- [Navigating](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice.navigating)。 请求新导航时发生。 可用于取消导航。
- [NavigationProgress](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice.navigationprogress)。 在下载过程中定期发生，用于提供定位进度信息。
- [Navigated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice.navigated)。 已定位并下载页时发生。
- [NavigationStopped](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice.navigationstopped)。 停止导航时发生 (通过调用[StopLoading](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice.stoploading))，或当前导航正在进行时在请求新导航。
- [NavigationFailed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice.navigationfailed)。 在导航到所需内容的同时遇到错误时发生。
- [LoadCompleted](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice.loadcompleted)。 导航到的内容已加载和分析，并开始呈现时发生。
- [FragmentNavigation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice.fragmentnavigation)。 导航到内容片段开始时发生，具体如何发生如下所述：
  - 立即，如果所需片段位于当前内容中。
  - 源内容加载之后，如果所需片段在不同内容中。

引发导航事件的顺序如下图所示。

![页导航流程图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/navigationoverviewfigure11.png)

一般情况下，[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)不关心这些事件。 很有可能，应用程序而言，与之和，出于此原因，会引发这些事件还通过[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)类：

- [Application.Navigating](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.navigating)
- [Application.NavigationProgress](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.navigationprogress)
- [Application.Navigated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.navigated)
- [Application.NavigationFailed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.navigationfailed)
- [Application.NavigationStopped](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.navigationstopped)
- [Application.LoadCompleted](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.loadcompleted)
- [Application.FragmentNavigation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.fragmentnavigation)

每次[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)引发事件时，[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)类引发相应事件。 [Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame) 和[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)提供相同的事件来检测其各自的范围内的导航。

在某些情况下，[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)可能会对这些事件感兴趣。 例如，[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)可能会处理[NavigationService.Navigating](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice.navigating)事件以确定是否取消导航从其自身。 这在下面的示例中显示。

```xaml
<Page
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.CancelNavigationPage">
  <Button Click="button_Click">Navigate to Another Page</Button>
</Page>
```

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;

namespace SDKSample
{
    public partial class CancelNavigationPage : Page
    {
        public CancelNavigationPage()
        {
            InitializeComponent();

            // Can only access the NavigationService when the page has been loaded
            this.Loaded += new RoutedEventHandler(CancelNavigationPage_Loaded);
            this.Unloaded += new RoutedEventHandler(CancelNavigationPage_Unloaded);
        }

        void button_Click(object sender, RoutedEventArgs e)
        {
            // Force WPF to download this page again
            this.NavigationService.Navigate(new Uri("AnotherPage.xaml", UriKind.Relative));
        }

        void CancelNavigationPage_Loaded(object sender, RoutedEventArgs e)
        {
            this.NavigationService.Navigating += new NavigatingCancelEventHandler(NavigationService_Navigating);
        }

        void CancelNavigationPage_Unloaded(object sender, RoutedEventArgs e)
        {
            this.NavigationService.Navigating -= new NavigatingCancelEventHandler(NavigationService_Navigating);
        }

        void NavigationService_Navigating(object sender, NavigatingCancelEventArgs e)
        {
            // Does the user really want to navigate to another page?
            MessageBoxResult result;
            result = MessageBox.Show("Do you want to leave this page?", "Navigation Request", MessageBoxButton.YesNo);

            // If the user doesn't want to navigate away, cancel the navigation
            if (result == MessageBoxResult.No) e.Cancel = true;
        }
    }
}
```

如果您使用中的导航事件注册一个处理程序[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)，如前面的示例，必须同时取消注册事件处理程序。 如果不这样做，可能与如何相关的副作用WPF记住[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)使用日志导航。

### 使用日志记住导航

WPF 使用两个堆栈来记住导航过的页：后退堆栈和前进堆栈。 当您导航从当前[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)到新[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)或前进到现有[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)，当前[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)添加到*back 堆栈*。 当您导航从当前[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)于前一[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)，当前[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)添加到*前进堆栈*。 后退堆栈、前进堆栈和管理它们的功能统称为日志。 后退堆栈和前进堆栈中的每一项是的一个实例[JournalEntry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.journalentry)类，并被称为*日记条目*。

#### 从 Internet Explorer 导航日志

从概念上讲，日志的操作相同的方式**回**并**向前**中的按钮Internet Explorer执行操作。 这些在下图中显示。

![“后退”和“前进”按钮](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/navigationoverviewfigure4.png)

有关XBAP由承载Internet Explorer，WPF将日志集成到导航UI的Internet Explorer。 这使用户能够导航中的页面XBAP通过使用**回**，**转发**，和**最新页**中的按钮Internet Explorer。 日志未集成到Microsoft Internet Explorer 6同样适用于Internet Explorer 7或 Internet Explorer 8。 相反，WPF呈现一个替代导航UI。

 重要

在中Internet Explorer中，当用户导航离开并返回到XBAP，只有不保持活动状态的页的日记条目保留在日志。有关使页保持活动状态的讨论，请参阅[页生存期和日志](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-overview#PageLifetime)本主题中更高版本。

默认情况下，每个文本[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)中显示**最新网页**系列Internet Explorer是URI为[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)。 很多情况下这对用户并没有什么特殊的意义。 幸运的是，可以使用以下选项更改文本：

1. 附加`JournalEntry.Name`属性值。
2. `Page.Title`属性值。
3. `Page.WindowTitle`属性值和URI当前[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)。
4. 当前 URI 的 [Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)。 (默认)

选项列出的顺序和查找文本的优先级顺序一致。 例如，如果`JournalEntry.Name`，则将忽略其他值。

下面的示例使用`Page.Title`特性来更改日志条目显示的文本。

```xaml
<Page
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.PageWithTitle"
    Title="This is the title of the journal entry for this page.">
</Page>
```
```csharp
using System.Windows.Controls;

namespace SDKSample
{
    public partial class PageWithTitle : Page
    {
    }
}
```
#### 使用 WPF 导航日志

用户可以通过使用导航日记**回**，**向前**，和**最新页**中Internet Explorer，还可导航同时使用日志提供的声明性和编程机制WPF。 若要执行此操作的原因之一是提供自定义导航UI在页面中。

您可以使用公开的导航命令以声明方式添加日志导航支持[NavigationCommands](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.navigationcommands)。 下面的示例演示如何使用`BrowseBack`导航命令。

```xaml
<Page
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.NavigationCommandsPage">
    <Hyperlink Command="NavigationCommands.BrowseBack">Back</Hyperlink>
    <Hyperlink Command="NavigationCommands.BrowseForward">Forward</Hyperlink>
</Page>
```
您可以使用的以下成员之一以编程方式导航日志[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)类：

- [GoBack](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice.goback)
- [GoForward](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice.goforward)
- [CanGoBack](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice.cangoback)
- [CanGoForward](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice.cangoforward)

此外可以以编程方式，如中所述操作日记[保留导航历史记录的内容状态](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-overview#RetainingContentStateWithNavigationHistory)本主题中更高版本。

### 页生存期和日志

请考虑XBAP利用包含丰富内容的多个页面，其中包括图形、 动画和媒体。 这类页的内存占用量可能相当大，尤其是使用视频和音频媒体的时候。 考虑到日志"记住"导航到，此类的页面XBAP会快速消耗的内存量较大且明显。

出于此原因，日志的默认行为是存储[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)中每个日志条目而不是对引用的元数据[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)对象。 导航日记条目后，其[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)元数据用于创建指定的新实例[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)。 因此，每个[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)的导航已由下图所示的生存期。

![页生存期](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/navigationoverviewfigure10.png)

尽管使用默认的日志记录行为可以减少内存消耗，每个页面呈现性能可能会降低;呈现[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)可以很耗时，尤其当它有很多内容。 如果需要保留[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)实例在日志中，您可以绘制两种技术来执行此操作。 首先，您可以以编程方式导航到[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)对象通过调用[NavigationService.Navigate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice.navigate)方法。

其次，您可以指定WPF保留的实例[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)中通过设置日志[KeepAlive](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page.keepalive)属性设置为`true`(默认值是`false`)。 下面的示例中所示，可以设置[KeepAlive](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page.keepalive)以声明方式在标记中。

```xaml
<Page
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.KeepAlivePage"
    KeepAlive="True">
  
  An instance of this page is stored in the journal.
  
</Page>
```

生存期[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)，它是保持活动状态，是从一个不是略有不同。 第一次[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)保持导航到处于活动状态，就像实例化[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)不保持为活动状态。 但是，因为实例[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)保留在日志中，它永远不会再次实例化，只要它保留在日志中。 因此，如果[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)具有需要每次调用的初始化逻辑[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)导航时，您应将其从移动构造函数的处理程序到[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)事件。下图中所示[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)并[Unloaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.unloaded)仍会每次都引发事件[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)分别导航到和从。

![引发 Loaded 和 Unloaded 事件时](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/navigationoverviewfigure17.png)

当[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)不是保持活动状态，不应执行下列操作之一：

- 存储对它或它的任何部分的引用。
- 将事件处理程序注册到并非由其实现的事件。

执行以下任一操作将创建引用，强制[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)要保留在内存中，即使已从日志中删除它。

一般情况下，您应优先使用默认值[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)行为，即不使[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)保持活动状态。 但是，这会存在将在下一节中讨论的状态影响。

### 保留导航历史记录的内容状态

如果[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)不保持活动状态，并且具有从用户，如果用户导航离开并返回到，数据会发生什么情况收集数据的控件[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)？ 从用户体验角度，用户应该会希望看到他们以前输入的数据。 遗憾的是，因为的新实例[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)创建与每个导航栏中，数据都会收集，并且会丢失数据的控件。

幸运的是，该日志提供支持以记住跨数据[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)导航，包括控件的数据。 具体而言，每个日志条目[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)充当关联的临时容器[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)状态。 以下步骤概述了如何使用这种支持时[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)从导航到：

1. 当前的条目[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)添加到日志。
2. 状态[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)存储该页面，添加到后退堆栈的日志条目。
3. 新[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)导航到。

当页面[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)是向后导航，使用日志，发生以下步骤：

1. [Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)实例化 （back 堆栈上的最顶部日志条目）。
2. [Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)是使用保存在一起的日记条目的状态刷新[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)。
3. [Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)向后导航。

WPF 在中使用以下控件时将自动使用这种支持[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page):

- [CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)
- [ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)
- [Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)
- [Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)
- [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)
- [ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)
- [MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)
- [ProgressBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.progressbar)
- [RadioButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.radiobutton)
- [Slider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider)
- [TabControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tabcontrol)
- [TabItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tabitem)
- [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)

如果[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)使用这些控件，输入的数据会记住跨[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)导航，如所示**喜爱的颜色**[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)下图中。

![具有记住状态控件的页](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/navigationoverviewfigure13.png)

当[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)具有未列出的在上述列表中，控件或当状态存储在自定义对象，您需要自己编写代码，从而使日志来记住跨状态[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)导航。

如果您需要记住小段状态跨[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)导航，您可以使用依赖关系属性 (请参阅[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)) 配置了[FrameworkPropertyMetadata.Journal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata.journal)元数据的标志。

如果状态，你[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)需要跨导航记住包含多个数据段，您可能会发现它更少的代码密集型将状态封装在一个类并实现[IProvideCustomContentState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.iprovidecustomcontentstate)接口。

如果需要不同状态中的单个导航[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)，而无需从导航[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)本身，可以使用[IProvideCustomContentState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.iprovidecustomcontentstate)和[NavigationService.AddBackEntry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice.addbackentry)。

### Cookie

另一个的方式WPF应用程序可以将数据存储是使用 cookie，创建、 更新和删除通过[SetCookie](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.setcookie)和[GetCookie](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.getcookie)方法。可以在中创建的 cookie WPF cookie 一样，其他类型的 Web 应用程序使用; cookie 是任意客户端计算机上应用程序期间或在不同的应用程序会话存储的数据片段。 Cookie 数据通常采用以下格式的名称/值对的形式。

*Name* `=` *Value*

当将数据传递给[SetCookie](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.setcookie)，连同[Uri](https://docs.microsoft.com/zh-cn/dotnet/api/system.uri)cookie 在内存中，创建的应为其设置 cookie 的位置，并且仅可为当前应用程序会话的持续时间。 此类 cookie 称为*会话 cookie*。

要跨应用程序会话存储 cookie，必须使用以下格式将到期日期添加到 cookie。

*NAME* `=` *VALUE* `; expires=DAY, DD-MMM-YYYY HH:MM:SS GMT`

到期日期使用 cookie 存储在当前Windows在 cookie 过期之前安装的 Temporary Internet Files 文件夹。 此类 cookie 称为*持久性 cookie*因为它在应用程序会话之间保留。

通过调用检索会话和持久性 cookie[GetCookie](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.getcookie)方法，传递[Uri](https://docs.microsoft.com/zh-cn/dotnet/api/system.uri)其中与设置 cookie 的位置的[SetCookie](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.setcookie)方法。

以下是一些在支持 cookie 的方式WPF:

- WPF 独立应用程序和XBAP都可以创建和管理 cookie。
- 创建的 cookieXBAP可以从浏览器访问。
- 来自相同域的 XBAP 可以创建和共享 cookie。
- XBAP 和HTML同一个域中的页面可以创建和共享 cookie。
- 调度 cookie 时XBAP和宽松XAML页发出 Web 请求。
- 顶级XBAP和XBAP托管在 IFRAME 可以访问 cookie。
- 中的 cookie 支持WPF是相同的所有支持的浏览器。
- 在中Internet Explorer，于 cookie 的 P3P 策略遵循WPF，特别是涉及第一方和第三方XBAP。

### 结构化导航

如果你需要将数据从一个传递[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)到另一个，您可以将数据作为参数传递给非默认构造函数的[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)。 请注意，是否使用此方法，则必须保持[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)处于活动状态; 如果不是，下次导航到[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)，WPF重新实例化[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)使用默认构造函数。

或者，你[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)可以实现需要传递的数据设置的属性。 事情就变得复杂，但是，当[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)需要将数据传回给[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)，导航到它。 问题是导航本身并不保证的支持机制[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)后从导航将返回到。 实质上，导航不支持调用/返回语义。 若要解决此问题，请WPF提供了[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)类，该类可以用于确保[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)以可预测和结构化方式返回到。 有关详细信息，请参阅[结构化导航概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/structured-navigation-overview)。

## NavigationWindow 类

到目前为止，你已全面了解最有可能用可导航内容生成应用程序的导航服务。 这些服务所述的上下文XBAP，但它们并不局限于XBAP。 现代操作系统和 Windows 应用程序充分利用现代用户将浏览器样式导航并入独立应用程序的浏览器体验。 常见示例包括：

- **Word 同义词库**:导航字选择。
- **文件资源管理器**:文件和文件夹导航。
- **向导**:细分复杂的任务分为多页，可以在它们之间导航。 例如，Windows 组件向导处理添加和删除 Windows 功能。

若要将浏览器样式导航并入独立应用程序，可以使用[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)类。 [NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow) 派生自[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)并将其扩展具有相同支持进行导航的XBAP提供。 可以使用[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)作为独立应用程序中任一的主窗口或对话框之类的次窗口。

若要实现[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)，如同处理中的大多数顶级类WPF([Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)， [Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)，依此类推)，使用标记和代码隐藏的组合。 这在下面的示例中显示。

```xaml
<NavigationWindow
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.MainWindow" 
    Source="HomePage.xaml"/>
```

```csharp
using System.Windows.Navigation;

namespace SDKSample
{
    public partial class MainWindow : NavigationWindow
    {
        public MainWindow()
        {
            InitializeComponent();
        }
    }
}
```

此代码将创建[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)自动导航到[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)(HomePage.xaml) 时[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)打开。 如果[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)是主应用程序窗口中，可以使用`StartupUri`属性启动。 这在以下标记中显示。

```xaml
<Application
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    StartupUri="MainWindow.xaml" />
```

下图显示[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)作为独立的应用程序的主窗口。

![主窗口](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/navigationoverviewfigure18.png)

从图中，可以看到[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)具有标题，即使它不设置[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)前面的示例中的实现代码。 相反，使用设置标题[WindowTitle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page.windowtitle)属性，以下代码所示。
```xaml
<Page 
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    Title="Home Page"
    WindowTitle="NavigationWindow">
</Page>
```
设置[WindowWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page.windowwidth)并[WindowHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page.windowheight)属性还会影响[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)。

通常情况下，您实现您自己[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)当需要进行自定义其行为或外观。 如果没有执行上述操作，则可以使用快捷方式。 如果指定的包URI的[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)作为[StartupUri](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.startupuri)独立的应用程序，在[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)会自动创建[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)主机到[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)。 以下标记显示如何实现此功能。

```xaml
<Application
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    StartupUri="HomePage.xaml" />
```

如果希望类似对话框是一个辅助应用程序窗口[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)，可以在下面的示例中使用代码以将其打开。

```csharp
// Open a navigation window as a dialog box
NavigationWindowDialogBox dlg = new NavigationWindowDialogBox();
dlg.Source = new Uri("HomePage.xaml", UriKind.Relative);
dlg.Owner = this;
dlg.ShowDialog();
```

下图显示结果。

![对话框](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/navigationoverviewfigure19.png)

正如您所看到的[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)将显示Internet Explorer-样式**回**并**向前**按钮，允许用户导航日志。 这些按钮提供相同的用户体验，如下图所示。

![导航窗口中的“后退”和“前进”按钮](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/navigationoverviewfigure20.png)

如果您的页面提供自己的日志导航支持和 UI，则可以隐藏**回**和**向前**情况下显示的按钮[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)的值设置[ShowsNavigationUI](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow.showsnavigationui)属性设置为`false`.

或者，可以使用自定义项中的支持WPF来替换UI的[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)本身。

## 框架类

这两个浏览器和[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)是该主机可导航内容的窗口。 在某些情况下，应用程序具有无需整个窗口托管的内容。 相反，此类内容在其他内容中托管。 您可以通过使用可导航内容插入到其他内容[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)类。 [Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame) 提供了相同的支持[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)和XBAP。

下面的示例演示如何添加[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)到[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)以声明方式使用`Frame`元素。

```xaml
<Page 
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  WindowTitle="Page that Hosts a Frame"
  WindowWidth="250"
  WindowHeight="250">
	<Frame Source="FramePage1.xaml" />
</Page>
```
此标记将设置`Source`的属性`Frame`元素的 packURI有关[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)的[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)最初应导航到。 下图显示XBAP与[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)具有[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)的具有多页间导航。

![已在多页之间导航的框架](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/navigationoverviewfigure5.png)

不只需使用[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)的内容中[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)。 它也是很常见承载[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)的内容中[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)。

默认情况下，[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)仅在缺少其他日志中使用它自己的日志。 如果[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)是内部承载的内容的一部分[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)或XBAP，[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)使用属于日志[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)或XBAP。 有时，不过，[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)可能需要负责它自己的日志。 若要执行此操作的原因之一是允许通过托管的页内的日志导航[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)。 这由下图说明。

![框架和页关系图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/navigationoverviewfigure7.png)

在这种情况下，你可以配置[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)通过设置使用自己的日记[JournalOwnership](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame.journalownership)的属性[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)到[OwnsJournal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.journalownership#System_Windows_Navigation_JournalOwnership_OwnsJournal)。 这在以下标记中显示。

```xaml
<Page 
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  WindowTitle="Page that Hosts a Frame"
  WindowWidth="250"
  WindowHeight="250">
  <Frame Source="FramePage1.xaml" JournalOwnership="OwnsJournal" />
</Page>
```
下图说明了中导航的效果[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)使用它自己的日志。

![使用自己日志的框架](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/navigationoverviewfigure8.png)

请注意，日志条目显示此导航UI中[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)，而不是通过Internet Explorer。

> 如果[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)是在托管的内容的一部分[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)，[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)使用它自己的日志，并继而显示自己的导航UI。

如果你的用户体验需要[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)而不显示在导航窗格中提供自己的日记UI，可以隐藏导航UI通过设置[NavigationUIVisibility](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame.navigationuivisibility)到[Hidden](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visibility#System_Windows_Visibility_Hidden)。 这在以下标记中显示。

```xaml
<Page 
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  WindowTitle="Page that Hosts a Frame"
  WindowWidth="250"
  WindowHeight="250">
  <Frame 
  	Source="FramePage1.xaml" 
  	JournalOwnership="OwnsJournal" 
  	NavigationUIVisibility="Hidden" />
</Page>
```
## 导航主机

[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame) 和[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)是称为导航主机的类。 一个*导航主机*是一个类，可以导航到并显示内容。 若要实现此目的，每个导航主机都使用其自己[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)和日志。 导航主机的基本构造在下图中显示。

![导航器关系图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/navigationoverviewfigure15.png)

实际上，这允许[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)和[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)若要提供同一导航支持的XBAP托管在浏览器中时。

除了使用以外[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)和一个日志，导航主机实现相同的成员的[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)实现。 这由下图说明。

![框架中和导航窗口中的日志](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/naivgationoverviewfigure24.png)

这就允许直接对它们进行导航支持编程。 如果你需要提供自定义导航，可以考虑这UI有关[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)托管在[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)。此外，这两种类型实现附加的与导航相关的成员，包括`BackStack`([NavigationWindow.BackStack](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow.backstack)， [Frame.BackStack](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame.backstack)) 和`ForwardStack`([NavigationWindow.ForwardStack](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow.forwardstack)， [Frame.ForwardStack](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame.forwardstack))，这样便可以枚举中后的日志条目堆栈和前进堆栈，分别。

如之前提及，应用程序中可以存在不止一个日志。 下图提供何时可能发生这种情况的示例。

![一个应用程序内的多个日志](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/naivgationoverviewfigure25.png)



## 导航到非 XAML 页内容

在本主题中，整个[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)和 packXBAP已用于演示的各种导航功能WPF。 但是， [Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page) ，它是编译到应用程序不是唯一的可导航到，内容和包类型XBAP不识别的内容的唯一方法。

如本部分中所示，您可以导航到松散XAML文件，HTML文件和对象。

### 导航到松散 XAML 文件

松散XAML文件是具有以下特征的文件：

- 仅包含XAML（即无代码）。
- 具有适当的命名空间声明。
- 具有 .xaml 文件扩展名。

例如，考虑以下内容存储为松散XAML文件 Person.xaml。

```xaml
<!-- Person.xaml -->
<TextBlock xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation">
  <TextBlock FontWeight="Bold">Name:</TextBlock>
  <TextBlock>Nancy Davolio</TextBlock>
  <LineBreak />
  <TextBlock FontWeight="Bold">Favorite Color:</TextBlock>
  <TextBlock>Yellow</TextBlock>
</TextBlock>
```

双击该文件时，浏览器打开、导航到并显示内容。 如下图所示。

![显示 Person.XAML 文件的内容](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/navigationoverviewfigure21.png)

您可以显示松散XAML从以下文件：

- 本地计算机上的网站、Intranet 或 Internet。
- 一个通用命名约定 (UNC)文件共享。
- 本地磁盘。

松散XAML可以将文件添加到浏览器的收藏夹，也是浏览器的主页。

> 有关发布和启动松散XAML页，请参阅[部署 WPF 应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/deploying-a-wpf-application-wpf)。

松散的一个限制XAML是，只能托管可安全地在部分信任环境中运行的内容。 例如，`Window`不能为松散的根元素XAML文件。 有关详细信息，请参阅 [WPF 部分信任安全性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/wpf-partial-trust-security)。

### 通过使用框架导航到 HTML 文件

正如您所料，也可以导航到HTML。 您只需提供URI使用 http 方案。 例如，以下XAML显示了[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)导航到HTML页。

```xaml
<Frame Source="http://www.microsoft.com/default.aspx" />
```

导航到HTML需要特殊权限。 例如，您不能从导航XBAPInternet 区域部分信任安全沙箱中运行。 有关详细信息，请参阅 [WPF 部分信任安全性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/wpf-partial-trust-security)。

### 通过使用 WebBrowser 控件导航到 HTML 文件

[WebBrowser](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.webbrowser)控件支持HTML文档托管、 导航和脚本/托管代码互操作性。 有关详细信息有关[WebBrowser](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.webbrowser)控件，请参阅[WebBrowser](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.webbrowser)。

像[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)，导航到HTML使用[WebBrowser](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.webbrowser)需要特殊权限。 例如，从部分信任应用程序，您只能导航到HTML位于源站点。 有关详细信息，请参阅 [WPF 部分信任安全性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/wpf-partial-trust-security)。

### 导航到自定义对象

如果必须存储为自定义对象的数据，以显示该数据的一种方法是创建[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)绑定到这些对象的内容 (请参阅[数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview))。 如果无需创建整个页面而只要显示对象，则可以直接导航到它们。

请考虑`Person`在下面的代码中实现的类。

```csharp
using System.Windows.Media;

namespace SDKSample
{
    public class Person
    {
        string name;
        Color favoriteColor;

        public Person() { }
        public Person(string name, Color favoriteColor)
        {
            this.name = name;
            this.favoriteColor = favoriteColor;
        }

        public string Name
        {
            get { return this.name; }
            set { this.name = value; }
        }

        public Color FavoriteColor
        {
            get { return this.favoriteColor; }
            set { this.favoriteColor = value; }
        }
    }
}
```

若要导航到它，请调用[NavigationWindow.Navigate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow.navigate)方法，如以下代码所示。

```xaml
<Page 
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  x:Class="SDKSample.HomePage"
  WindowTitle="Page that Navigates to an Object">
  <Hyperlink Name="hyperlink" Click="hyperlink_Click">
  Navigate to Nancy Davolio
  </Hyperlink>
</Page>
```
```csharp
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;

namespace SDKSample
{
    public partial class HomePage : Page
    {
        public HomePage()
        {
            InitializeComponent();
        }

        void hyperlink_Click(object sender, RoutedEventArgs e)
        {
            Person person = new Person("Nancy Davolio", Colors.Yellow);
            this.NavigationService.Navigate(person);
        }
    }
}
```

下图显示结果。

![导航到类的页](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/navigationoverviewfigure22.png)

从此图可以看出，没有显示任何有用信息。 事实上，显示的值是返回值`ToString`方法**Person**对象; 默认情况下，这是唯一值的WPF可以使用来表示您的对象。 可以重写`ToString`方法以返回更有意义的信息，尽管它仍将只能是一个字符串值。 可以使用的一种利用演示功能的WPF是使用数据模板。 您可以实现一个数据模板的WPF可以将与特定类型的对象相关联。 下面的代码演示的数据模板`Person`对象。

```xaml
<Application
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    xmlns:local="clr-namespace:SDKSample" 
    x:Class="SDKSample.App"
    StartupUri="HomePage.xaml">

  <Application.Resources>

    <!-- Data Template for the Person Class -->
    <DataTemplate DataType="{x:Type local:Person}">
      <TextBlock xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation">
        <TextBlock FontWeight="Bold">Name:</TextBlock>
        <TextBlock Text="{Binding Path=Name}" />
        <LineBreak />
        <TextBlock FontWeight="Bold">Favorite Color:</TextBlock>
        <TextBlock Text="{Binding Path=FavoriteColor}" />
      </TextBlock>
    </DataTemplate>
    
  </Application.Resources>

</Application>
```

在这里，数据模板相关联`Person`通过使用类型`x:Type`中的标记扩展`DataType`属性。 数据模板然后将绑定`TextBlock`元素 (请参阅[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)) 的属性`Person`类。 下图显示了更新后的外观`Person`对象。

![导航到具有数据模板的类](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/navigationoverviewfigure23.png)

此技术的优势之一在于能够通过重复使用数据模板以在应用程序任意位置一致地显示对象而获得一致性。

有关数据模板的详细信息，请参阅[数据模板化概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-templating-overview)。

## 安全性

WPF 导航支持允许XBAP以导航到跨 Internet，而且它允许应用程序来承载第三方内容。 若要从有害行为影响，保护应用程序和用户WPF提供了各种中讨论的安全功能[安全](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/security-wpf)和[WPF 部分信任安全性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/wpf-partial-trust-security)。

## [Structured Navigation Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/structured-navigation-overview)

可以通过承载的内容XAML 浏览器应用程序 (XBAP)、 一个[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)，或[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)组成可以标识包的页面统一资源标识符 (URI)和导航到超链接的。 页面的结构以及导航页面的方式（通过超链接来定义）称为导航拓扑。 此类拓扑适合各种应用程序类型，尤其适合在文档之间导航的应用程序类型。 对于此类应用程序，用户可以从一个页面导航到另一个页面，并且其中任一页面都无需了解另一页面的任何信息。

但是，对于其他类型的应用程序，在其页面之间导航时，确实需要了解这些页面信息。 例如，假设一个人力资源应用程序，它具有一个列出组织中所有员工的页面，即“员工列表”页。 此页还允许用户通过单击超链接添加新员工。 单击超链接后，页面会导航到“添加员工”页以收集新员工的详细信息，并将其返回到“员工列表”页以创建新员工并更新列表。 这种样式的导航与调用方法来执行某些处理并返回值（称为结构化编程）类似。 同样，这种样式的导航称为*结构化导航*。

[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)类未实现对结构化导航的支持。 相反，[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)类派生自[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)并将其扩展具有所需的结构化导航的基本构造。 本主题演示如何建立结构化的导航使用[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)。

### 结构化导航

在结构化导航中，当一个页面调用另一个页面时需要以下部分或全部行为：

- 调用页导航到被调用页，并且可以选择性地传递被调用页所需的参数。
- 当用户已使用完调用页时，被调用页将专门返回到调用页，并且可以：
  - 返回描述调用页是如何完成（例如，用户按的是“确定”按钮还是“取消”按钮）的状态信息。
  - 返回从用户那里收集的数据（例如，新员工的详细信息）。
- 当调用页返回到被调用页时，被调用页会从导航历史记录中删除，以便将被调用页的一个实例与另一个实例隔离开。

下图阐释了这些行为。

![调用页与被调用页之间的流](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/structurednavigationoverviewfigure1.png)

您可以通过使用实现这些行为[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)作为被调用页。



### 使用 PageFunction 进行结构化导航

本主题演示如何实现包含一个结构化导航的基本机制[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)。 在此示例中，[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)调用[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)若要获取[String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)用户值，并将其返回。

#### 创建调用页

调用页[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)可以是[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)或[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)。 在此示例中，它是[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)，如下面的代码中所示。

```xaml
<Page 
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="StructuredNavigationSample.CallingPage"
    WindowTitle="Calling Page" 
    WindowWidth="250" WindowHeight="150">
</Page>
```
```csharp
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;

namespace StructuredNavigationSample
{
    public partial class CallingPage : Page
    {
        public CallingPage()
        {
            InitializeComponent();
        }
    }
}
```
#### 创建要调用的页函数

因为调用页可以使用被调用的页收集并返回从用户数据[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)作为其类型参数指定的被调用的页将返回的值类型的泛型类实现。 下面的代码演示实现被调用页上，使用[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)，它将返回[String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)。

```xaml
<PageFunction
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    xmlns:sys="clr-namespace:System;assembly=mscorlib" 
    x:Class="StructuredNavigationSample.CalledPageFunction"
    x:TypeArguments="sys:String"
    Title="Page Function" 
    WindowWidth="250" WindowHeight="150">

  <Grid Margin="10">

    <Grid.ColumnDefinitions>
      <ColumnDefinition Width="Auto" />
      <ColumnDefinition />
    </Grid.ColumnDefinitions>
    <Grid.RowDefinitions>
      <RowDefinition Height="Auto" />
      <RowDefinition />
    </Grid.RowDefinitions>

    <!-- Data -->
    <Label Grid.Column="0" Grid.Row="0">DataItem1:</Label>
    <TextBox Grid.Column="1" Grid.Row="0" Name="dataItem1TextBox"></TextBox>

    <!-- Accept/Cancel buttons -->
    <TextBlock Grid.Column="1" Grid.Row="1" HorizontalAlignment="Right">
      <Button Name="okButton" IsDefault="True" MinWidth="50">OK</Button>
      <Button Name="cancelButton" IsCancel="True" MinWidth="50">Cancel</Button>
    </TextBlock>

  </Grid>

</PageFunction>
```

```csharp
using System;
using System.Windows;
using System.Windows.Navigation;

namespace StructuredNavigationSample
{
    public partial class CalledPageFunction : PageFunction<String>
    {
        public CalledPageFunction()
        {
            InitializeComponent();
        }
    }
}
```

声明[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)类似于声明[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)添加了类型自变量。 从代码示语例中可以看出，在 XAML 标记和代码隐藏中均指定了类型自变量，前者使用 `x:TypeArguments` 属性，后者使用标准的泛型类型参数语法。

不必仅使用 .NET Framework 类作为类型自变量。 一个[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)无法调用以收集抽象化为自定义类型的特定于域的数据。 下面的代码演示如何使用自定义类型的类型参数作为[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)。

```csharp
namespace SDKSample
{
    public class CustomType
    {
    }
}
```
```xaml
<PageFunction
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    xmlns:local="clr-namespace:SDKSample" 
    x:Class="SDKSample.CustomTypePageFunction"
    x:TypeArguments="local:CustomType">
</PageFunction>
```
```csharp
using System.Windows.Navigation;

namespace SDKSample
{
    public partial class CustomTypePageFunction : PageFunction<CustomType>
    {
    }
}
```

类型参数[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)为以下各节所述调用页与被调用的页之间的通信奠定了基础。

正如您将看到的使用的声明标识的类型[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)发挥着重要作用中返回数据从[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)向调用页。

#### 调用 PageFunction 和传递参数

若要调用一个页面，调用页必须实例化被调用的页并导航到该使用[Navigate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice.navigate)方法。 这使得调用页可以将初始数据传递给被调用页，例如，被调用页收集的数据的默认值。

下面的代码演示使用非默认构造函数从调用页接受参数的被调用页。

```csharp
using System;
using System.Windows;
using System.Windows.Navigation;

namespace StructuredNavigationSample
{
    public partial class CalledPageFunction : PageFunction<String>
    {
	
		public CalledPageFunction(string initialDataItem1Value)
		{
    		InitializeComponent();
    		// Set initial value
    		this.dataItem1TextBox.Text = initialDataItem1Value;
		}
    }
}
```

下面的代码演示调用页处理[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink.click)事件的[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)实例化被调用的页，并将其传递初始字符串值。

```xaml
<Hyperlink Name="pageFunctionHyperlink">Call Page Function</Hyperlink>
```

```csharp
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;

namespace StructuredNavigationSample
{
    public partial class CallingPage : Page
    {
        public CallingPage()
        {
            InitializeComponent();
            this.pageFunctionHyperlink.Click += new RoutedEventHandler(pageFunctionHyperlink_Click);
        }
        void pageFunctionHyperlink_Click(object sender, RoutedEventArgs e)
        {
            
            // Instantiate and navigate to page function
            CalledPageFunction CalledPageFunction = new CalledPageFunction("Initial Data Item Value");
		}
    }
}
```
不必向被调用页传递参数。 可以执行以下操作：

- 从调用页：
  1. 实例化被调用[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)使用默认构造函数。
  2. 存储中的参数[Properties](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.properties)。
  3. 导航到被调用[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)。
- 从被调用[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1):
  - 检索和使用存储在参数[Properties](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.properties)。

但是，你不久就会看到，你仍然需要使用代码来实例化并导航到被调用页，以收集被调用页返回的数据。 出于此原因，[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)需求保持活动状态; 否则为下次导航到[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)，WPF实例化[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)使用默认构造函数。

但是，在被调用页返回前，需要返回可以由调用页检索的数据。

#### 将任务的任务结果和任务数据返回到调用页

在用户使用完被调用页后（在本示例中通过按“确定”或“取消”按钮来表示），被调用页需要返回。 因为调用页已使用被调用页来从用户那里收集数据，所以调用页需要两种类型的信息：

1. 用户是否取消了被调用页（在此示例中通过按“确定”或“取消”按钮）。 这使得调用页可以确定是否处理调用页从用户那里收集的数据。
2. 用户提供的数据。

若要返回的信息，[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)实现[OnReturn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1.onreturn)方法。 下面的代码演示如何调用它。

```csharp
using System;
using System.Windows;
using System.Windows.Navigation;

namespace StructuredNavigationSample
{
    public partial class CalledPageFunction : PageFunction<String>
    {
        void okButton_Click(object sender, RoutedEventArgs e)
        {
            // Accept when Ok button is clicked
            OnReturn(new ReturnEventArgs<string>(this.dataItem1TextBox.Text));
        }

        void cancelButton_Click(object sender, RoutedEventArgs e)
        {
            // Cancel 
            OnReturn(null);
        }
    }
}
```

在此示例中，如果用户按“取消”按钮，则会向调用页返回 `null` 值。 如果按“确定”按钮，则返回用户提供的字符串值。 [OnReturn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1.onreturn) 是`protected virtual`调用以向调用页返回数据的方法。 你的数据需要打包的泛型实例中[ReturnEventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.returneventargs-1)类型，其类型参数指定的类型值[Result](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.returneventargs-1.result)返回。 这样一来，在声明时[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)使用特定类型自变量，即指明[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)将返回指定的类型参数的类型的实例。 在此示例中，类型参数和返回值，因此，属于类型[String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)。

当[OnReturn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1.onreturn)调用时，调用页需要某种方法来接收的返回值[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)。 出于此原因，[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)实现[Return](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1.return)调用页来处理的事件。 当[OnReturn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1.onreturn)调用时，[Return](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1.return)引发，以便调用页可以向注册[Return](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1.return)来接收通知。

C#复制

```csharp
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;

namespace StructuredNavigationSample
{
    public partial class CallingPage : Page
    {
```

C#复制

```csharp
        void pageFunctionHyperlink_Click(object sender, RoutedEventArgs e)
        {
            
            // Instantiate and navigate to page function
            CalledPageFunction CalledPageFunction = new CalledPageFunction("Initial Data Item Value");
            CalledPageFunction.Return += pageFunction_Return;
            this.NavigationService.Navigate(CalledPageFunction);
        }
        void pageFunction_Return(object sender, ReturnEventArgs<string> e)
        {
            this.pageFunctionResultsTextBlock.Visibility = Visibility.Visible;

            // Display result
            this.pageFunctionResultsTextBlock.Text = (e != null ? "Accepted" : "Canceled");

            // If page function returned, display result and data
            if (e != null)
            {
                this.pageFunctionResultsTextBlock.Text += "\n" + e.Result;
            }
        }
    }
}
```

#### 当任务完成时删除任务页

当被调用页返回，并且用户未取消被调用页时，调用页将处理由用户提供并且从被调用页返回的数据。 这种方式的数据采集通常是独立的活动；当被调用页返回时，调用页需要创建并导航到新的调用页来捕获更多数据。

不过，除非已从日志中删除被调用页，否则用户将能够向后导航到调用页的上一个实例。 是否[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)保留在日志由[RemoveFromJournal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunctionbase.removefromjournal)属性。 默认情况下，页函数会自动删除何时[OnReturn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1.onreturn)称为，因为[RemoveFromJournal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunctionbase.removefromjournal)设置为`true`。 若要导航历史记录中后保留页函数[OnReturn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1.onreturn)调用时，设置[RemoveFromJournal](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunctionbase.removefromjournal)到`false`。

### 其他类型的结构化导航

本主题说明了最基本的用法[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)以支持调用/返回结构化导航。 这一基础使你能够创建更复杂的结构化导航类型。

例如，有时调用页需要多个页面来从用户那里收集足够的数据或者执行任务。 多个页面的使用称为“向导”。

在其他情况下，应用程序可能具有依赖于结构化导航来有效操作的复杂导航拓扑。 有关详细信息，请参阅[导航拓扑概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-topologies-overview)。

## [Navigation Topologies Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/navigation-topologies-overview)

此概述中的导航拓扑介绍了WPF。 三个常见导航拓扑及示例将在随后讨论。

> 阅读本主题之前，您应该熟悉的概念中的结构化导航WPF使用页函数。 这两个主题的详细信息，请参阅[结构化导航概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/structured-navigation-overview)。

本主题包含以下各节：

- [导航拓扑](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-topologies-overview#Navigation_Topologies)
- [结构化导航拓扑](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-topologies-overview#Structured_Navigation_Topologies)
- [在固定线性拓扑中导航](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-topologies-overview#Navigation_over_a_Fixed_Linear_Topology)
- [在固定分层拓扑中动态导航](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-topologies-overview#Dynamic_Navigation_over_a_Fixed_Hierarchical_Topology)
- [在动态生成的拓扑中导航](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-topologies-overview#Navigation_over_a_Dynamically_Generated_Topology)

### 导航拓扑

在中WPF，导航通常由页 ([Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)) 包含超链接 ([Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink))，导航至其他页面时单击。 导航到的页由标识统一资源标识符 (URI)(请参阅[WPF 中的 Pack Uri](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/pack-uris-in-wpf))。 请考虑下面的简单示例，显示了页面、 超链接和统一资源标识符 (URI):

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation" WindowTitle="Page1">
  <Hyperlink NavigateUri="Page2.xaml">Navigate to Page2</Hyperlink>
</Page>
```

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation" WindowTitle="Page2">
  <Hyperlink NavigateUri="Page1.xaml">Navigate to Page1</Hyperlink>
</Page>
```

这些页面中排列*导航拓扑*其结构由页面间导航的方式。 此特定导航拓扑适用于简单的应用场景，尽管导航可以要求更复杂的拓扑（其中的一些只能在应用程序运行时定义）。

本主题介绍三个常见导航拓扑：*固定线性*，*固定分层*，并*动态生成*。 每个导航拓扑演示了一个示例，具有UI类似下图中所示：

![具有数据项的任务页](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/navigationtopologyfigure6.png)



### 结构化导航拓扑

有两种广义类型的导航拓扑：

- **固定拓扑**：在编译时定义，在运行时不能更改。 按线性或层次顺序在固定序列的页面之间导航时，固定拓扑将很有用。
- **动态拓扑**：在运行时基于从用户、应用程序或系统收集的输入进行定义。 当页面可以按不同序列进行导航时，动态拓扑将很有用。

虽然使用页可以创建导航拓扑，但是这些示例使用页函数，因为它们提供附加支持，从而通过拓扑页简化对传递和返回数据的支持。



### 在固定线性拓扑中导航

固定线性拓扑类似于向导的结构，即在固定序列中导航一个或多个向导页。 下图显示具有固定线性拓扑的向导的高级结构和流。

![导航拓扑关系图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/navigationtopologyfigure1.png)

在固定线性拓扑中导航的典型行为包括以下内容：

- 从调用页导航到启动程序页，启动程序页初始化向导并导航到第一个向导页。 启动程序页 ( UI-较少[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)) 不是必需的因为调用页可以直接调用第一个向导页。 但是，使用启动程序页可以简化向导初始化，特别是初始化较复杂时。
- 用户可以使用“后退”和“前进”按钮（或超链接）在不同的页面之间导航。
- 用户可以使用日志在不同的页面之间导航。
- 用户可以通过按下“取消”按钮从任何向导页取消向导。
- 用户可以在最后一个向导页上通过按下“完成”按钮来接受向导。
- 如果向导已取消，该向导会返回相应结果，但不返回任何数据。
- 如果用户接受向导，该向导会返回相应结果并返回所收集的数据。
- 向导完成（接受或取消）后，向导所包含的页便会从日志中删除。 这使得每个向导实例都保持独立，从而避免潜在的数据反常或状态异常。



### 在固定分层拓扑中动态导航

在某些应用程序中，页允许导航到两个或更多其他页，如下图所示。

![一个可以导航到多个页的页面](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/navigationtopologyfigure2.png)

此结构称为固定分层拓扑，分层的遍历序列通常在运行时由应用程序或用户确定。 运行时，对于允许导航到两个或更多其他页的分层中的每个页面，会收集确定导航到的页所需的数据。 下图基于上图说明了其中一种可能的导航序列。

![导航拓扑关系图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/navigationtopologyfigure3.png)

即使固定分层结构中的页导航序列在运行时确定，用户体验仍会与固定线性拓扑的用户体验相同：

- 从调用页导航到启动程序页，启动程序页初始化向导并导航到第一个向导页。 启动程序页 ( UI-较少[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)) 不是必需的因为调用页可以直接调用第一个向导页。 但是，使用启动程序页可以简化向导初始化，特别是初始化较复杂时。
- 用户可以使用“后退”和“前进”按钮（或超链接）在不同的页面之间导航。
- 用户可以使用日志在不同的页面之间导航。
- 如果用户通过日志向后导航，他们可以更改导航序列。
- 用户可以通过按下“取消”按钮从任何向导页取消向导。
- 用户可以在最后一个向导页上通过按下“完成”按钮来接受向导。
- 如果向导已取消，该向导会返回相应结果，但不返回任何数据。
- 如果用户接受向导，该向导会返回相应结果并返回所收集的数据。
- 向导完成（接受或取消）后，向导所包含的页便会从日志中删除。 这使得每个向导实例都保持独立，从而避免潜在的数据反常或状态异常。



### 在动态生成的拓扑中导航

在某些应用程序中，两个或更多页的导航序列只能在运行时由用户、应用程序或外部数据确定。 下图说明了一组导航序列未定的页面。

![导航拓扑关系图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/navigationtopologyfigure4.png)

下图说明了在运行时用户所选的导航序列。

![导航关系图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/media/navigationtopologyfigure5.png)

该导航序列称为动态生成的拓扑。 对于用户而言，与其他导航拓扑一样，用户体验与以前拓扑的用户体验相同：

- 从调用页导航到启动程序页，启动程序页初始化向导并导航到第一个向导页。 启动程序页 ( UI-较少[PageFunction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1)) 不是必需的因为调用页可以直接调用第一个向导页。 但是，使用启动程序页可以简化向导初始化，特别是初始化较复杂时。
- 用户可以使用“后退”和“前进”按钮（或超链接）在不同的页面之间导航。
- 用户可以使用日志在不同的页面之间导航。
- 用户可以通过按下“取消”按钮从任何向导页取消向导。
- 用户可以在最后一个向导页上通过按下“完成”按钮来接受向导。
- 如果向导已取消，该向导会返回相应结果，但不返回任何数据。
- 如果用户接受向导，该向导会返回相应结果并返回所收集的数据。
- 向导完成（接受或取消）后，向导所包含的页便会从日志中删除。 这使得每个向导实例都保持独立，从而避免潜在的数据反常或状态异常。

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/navigation-how-to-topics)

以下主题演示如何使用Windows Presentation Foundation (WPF)导航。

### 本节内容

[调用页函数](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/how-to-call-a-page-function)
[获取页函数的返回值](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/how-to-get-the-return-value-of-a-page-function)
[通过导航历史记录前进或后退](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/how-to-navigate-forward-or-back-through-navigation-history)
[通过页函数返回](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/how-to-return-from-a-page-function)

### [Call a Page Function](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/how-to-call-a-page-function)

此示例演示如何调用页函数从可扩展应用程序标记语言 (XAML)页。

- 示例

您可以导航到页函数使用统一资源标识符 (URI)，就像可以导航到页面时。 这在下面的示例中显示。

```csharp
// Navigate to a page function like a page
Uri pageFunctionUri = new Uri("GetStringPageFunction.xaml", UriKind.Relative);
this.NavigationService.Navigate(pageFunctionUri);
```

如果需要将数据传递到页函数，可以创建它的实例并通过设置属性来传递数据。 也可以使用非默认构造函数传递数据，如以下示例所示。

```xaml
<Page x:Class="UsingPageFunctionsSample.CallingPage"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    Title="CallingPage"
    >
    <Hyperlink Name="callPageFunctionHyperlink" Click="callPageFunctionHyperlink_Click">Call Page Function</Hyperlink>
</Page>
```

```csharp
void callPageFunctionHyperlink_Click(object sender, RoutedEventArgs e)
{
    // Call a page function
    GetStringPageFunction pageFunction = new GetStringPageFunction("initialValue");
    this.NavigationService.Navigate(pageFunction);
```

### [Navigate to a Page](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/how-to-navigate-to-a-page)

此示例演示了几种方法在其中一个页面可以导航到从[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)。

- 示例

很可能[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)以导航到页面使用以下值之一：

- [Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow.source) 属性。
- [Navigate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow.navigate) 方法。

```csharp
// Navigate to URI using the Source property
this.Source = new Uri("HomePage.xaml", UriKind.Relative);           

// Navigate to URI using the Navigate method
this.Navigate(new Uri("HomePage.xaml", UriKind.Relative));

// Navigate to object using the Navigate method
this.Navigate(new HomePage());
```

> 统一资源标识符 (URI) 可以是相对值还是绝对值。 有关详细信息，请参阅 [WPF 中的 Pack URI](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/pack-uris-in-wpf)。

### [Refresh a Page](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/how-to-refresh-a-page)

此示例演示如何调用[Refresh](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow.refresh)方法来刷新中的当前内容[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)。

- 示例

[Refresh](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow.refresh) 刷新中的当前内容[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)若要从其源重新加载。

```csharp
void navigateRefreshButton_Click(object sender, RoutedEventArgs e)
{
    this.Refresh();
}
```

### [Stop a Page from Loading](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/how-to-stop-a-page-from-loading)

此示例演示如何调用[StopLoading](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow.stoploading)方法来完成下载之前停止对内容的导航。

- 示例

[StopLoading](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow.stoploading) 停止下载请求的内容，并导致[NavigationStopped](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow.navigationstopped)引发事件。

```csharp
void navigateStopButton_Click(object sender, RoutedEventArgs e)
{
    this.StopLoading();
}
```

### [Navigate Back Through Navigation History](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/how-to-navigate-back-through-navigation-history)

此示例说明如何导航到条目后退导航历史记录。

- 示例

正在从中承载的内容的代码[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)，[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)使用[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)，或Windows Internet Explorer可以在向后导航导航历史记录，一次一个条目。

导航回一项需要首先检查是否存在条目后退导航历史记录中，通过检查**CanGoBack**属性，在导航回一个条目，通过调用之前**GoBack**方法。 以下示例所示：

```csharp
void navigateBackButton_Click(object sender, RoutedEventArgs e)
{
    // Navigate back one page from this page, if there is an entry
    // in back navigation history
    if (this.NavigationService.CanGoBack)
    {
        this.NavigationService.GoBack();
    }
    else
    {
        MessageBox.Show("No entries in back navigation history.");
    }
}
```

**CanGoBack**并**GoBack**由实现[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)， [Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)，并[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)。

> 如果您调用**GoBack**，和后退导航历史记录中没有任何条目[InvalidOperationException](https://docs.microsoft.com/zh-cn/dotnet/api/system.invalidoperationexception)引发。

### [Return from a Page Function](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/how-to-return-from-a-page-function)

本示例显示如何从页函数返回结果。

- 示例

若要从页函数返回，需要调用[OnReturn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1.onreturn)的实例传递和[ReturnEventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.returneventargs-1)。

```xaml
<PageFunction
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    xmlns:sys="clr-namespace:System;assembly=mscorlib" 
    x:Class="UsingPageFunctionsSample.GetStringPageFunction"
    x:TypeArguments="sys:String"
    Title="GetStringPageFunction">
</PageFunction>
```
```csharp
public partial class GetStringPageFunction : PageFunction<String>
{
    public GetStringPageFunction()
    {
        InitializeComponent();
    }

    public GetStringPageFunction(string initialValue) : this()
    {
        this.stringTextBox.Text = initialValue;
    }

    void okButton_Click(object sender, RoutedEventArgs e)
    {
        // Page function is accepted, so return a result
        OnReturn(new ReturnEventArgs<string>(this.stringTextBox.Text));
    }

    void cancelButton_Click(object sender, RoutedEventArgs e)
    {
        // Page function is cancelled, so don't return a result
        OnReturn(new ReturnEventArgs<string>(null));
    }
}
```

### [Get the Return Value of a Page Function](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/how-to-get-the-return-value-of-a-page-function)

本示例显示如何获取页函数的返回值。

- 示例

若要获取从页函数返回的结果，您需要处理[Return](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.pagefunction-1.return)的要调用的页函数。

```xaml
<Page x:Class="UsingPageFunctionsSample.CallingPage"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    Title="CallingPage"
    >
    <Hyperlink Name="callPageFunctionHyperlink" Click="callPageFunctionHyperlink_Click">Call Page Function</Hyperlink>
</Page>
```

```csharp
void callPageFunctionAndReturnHyperlink_Click(object sender, RoutedEventArgs e)
{
    // Call a page function and hook up page function's return event to get result
    GetStringPageFunction pageFunction = new GetStringPageFunction();
    pageFunction.Return += new ReturnEventHandler<String>(GetStringPageFunction_Returned);
    this.NavigationService.Navigate(pageFunction);
}
void GetStringPageFunction_Returned(object sender, ReturnEventArgs<String> e)
{
    // Get the result, if a result was passed.
    if (e.Result != null)
    {
        Console.WriteLine(e.Result);
    }
}
```

### [Navigate Forward or Back Through Navigation History](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/how-to-navigate-forward-or-back-through-navigation-history)

此示例说明如何导航到导航历史记录中的项的向前或向后。

- 示例

从内容中的以下主机运行的代码可以导航向前或向后导航历史记录，一次的一个条目。

- [NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow) 使用 [NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)
- [Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame) 使用 [NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)
- Windows Internet Explorer

您可以导航向前一项之前，你必须首先检查是否有条目前进导航历史记录中通过检查**CanGoForward**属性。 若要导航向前一个条目，请调用**GoForward**方法。 以下示例所示：

```csharp
void navigateForwardButton_Click(object sender, RoutedEventArgs e)
{
    // Navigate forward one page from this page, if there is an entry
    // in forward navigation history
    if (this.NavigationService.CanGoForward)
    {
        this.NavigationService.GoForward();
    }
    else
    {
        MessageBox.Show("No entries in forward navigation history.");
    }
}
```

您可以导航之前备份一个条目，你必须首先检查是否有条目后退导航历史记录中通过检查**CanGoBack**属性。 若要导航回一个条目，请调用**GoBack**方法。 以下示例所示：

```csharp
void navigateBackButton_Click(object sender, RoutedEventArgs e)
{
    // Navigate back one page from this page, if there is an entry
    // in back navigation history
    if (this.NavigationService.CanGoBack)
    {
        this.NavigationService.GoBack();
    }
    else
    {
        MessageBox.Show("No entries in back navigation history.");
    }
}
```

**CanGoForward**， **GoForward**， **CanGoBack**，和**GoBack**由实现[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)， [Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)，和[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)。

> 如果调用**GoForward**，而前进导航历史记录中没有任何条目或如果调用**GoBack**，而后退导航历史记录中没有任何条目[InvalidOperationException](https://docs.microsoft.com/zh-cn/dotnet/api/system.invalidoperationexception)引发。

### [Determine If a Page is Browser Hosted](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/how-to-determine-if-a-page-is-browser-hosted)

此示例演示如何确定如果[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)托管浏览器中。

- 示例

一个[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)可以是主机不可知的因此，可以将加载到多个不同类型的主机，包括[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)、 [NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)，或浏览器。 发生此情况有一个库程序集，其中包含一个或多个页面，以及哪一个是引用由多个独立的和可浏览 (XAML 浏览器应用程序 (XBAP)) 托管应用程序。

下面的示例演示如何使用[BrowserInteropHelper.IsBrowserHosted](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.browserinterophelper.isbrowserhosted)来确定如果[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)托管浏览器中。

```csharp
// Detect if browser hosted
if (BrowserInteropHelper.IsBrowserHosted) 
{
    // Note: can only inspect BrowserInteropHelper.Source property if page is browser-hosted.
    this.dataTextBlock.Text = "Is Browser Hosted: " + BrowserInteropHelper.Source.ToString();
}
else 
{
    this.dataTextBlock.Text = "Is not browser hosted";
}
```

### [Use mailto: to Send Mail From a Page](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/how-to-use-mailto-to-send-mail-from-a-page)

此示例演示如何使用[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)结合**mailto:**统一资源标识符 (URI)。

- 示例

下面的代码演示如何使用**mailto:** 统一资源标识符 (URI)打开新邮件窗口包含电子邮件地址和电子邮件地址和主题和电子邮件地址、 主题、 和正文。

```xaml
<Hyperlink NavigateUri="mailto:username@domainname">mailto: With Email Address</Hyperlink>
<Hyperlink NavigateUri="mailto:username@domainname?subject=SubjectText">mailto: With Email Address and Subject</Hyperlink>
<Hyperlink NavigateUri="mailto:username@domainname?subject=SubjectText&amp;body=BodyText">mailto: With Email Address, Subject, and Body</Hyperlink>
```

### [Set the Title of a Window from a Page](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/how-to-set-the-title-of-a-window-from-a-page)

此示例演示如何在其中设置窗口的标题[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)承载。

- 示例

页面可以更改将通过设置其承载窗口的标题[WindowTitle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page.windowtitle)属性，如下所示：

```xaml
<Page
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    Title="Page Title"
    WindowTitle="Window Title"
    >
</Page>
```

> 设置[Title](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page.title)页属性不会更改窗口标题的值。 相反，[Title](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page.title)导航历史记录中指定的页面条目的名称。

### [Set the Width of a Window from a Page](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/how-to-set-the-width-of-a-window-from-a-page)

此示例演示如何设置从窗口的宽度[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)。

- 示例

A [Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)通过设置可以设置及其主机窗口的宽度[WindowWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page.windowwidth)。 此属性允许[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)没有显式知道承载它的窗口的类型。

> 若要设置的窗口中使用的宽度[WindowWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page.windowwidth)、[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)必须是一个窗口的子级。

```xaml
<Page
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    Title="SetWindowWidthPage"
    WindowWidth="500"
    >
</Page>
```

### [Set the Height of a Window from a Page](https://docs.microsoft.com/en-us/dotnet/framework/wpf/app-development/how-to-set-the-height-of-a-window-from-a-page)

此示例演示如何设置从窗口的高度[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)。

- 示例

A [Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)可以通过设置来设置及其主机窗口的高度[WindowHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page.windowheight)。 此属性允许[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)没有显式知道承载它的窗口的类型。

> 若要设置的窗口中使用的高度[WindowHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page.windowheight)、[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)必须是一个窗口的子级。

```xaml
<Page
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    Title="SetWindowHeightPage"
    WindowHeight="500"
    >
</Page>
```