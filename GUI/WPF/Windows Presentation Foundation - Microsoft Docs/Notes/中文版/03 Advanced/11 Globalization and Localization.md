# [Globalization and Localization](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/globalization-and-localization)

Windows Presentation Foundation (WPF) 世界通用的应用程序的开发提供广泛支持。

[WPF 全球化和本地化概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/wpf-globalization-and-localization-overview)
[WPF 全球化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/globalization-for-wpf)
[使用自动布局概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/use-automatic-layout-overview)
[本地化特性和注释](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/localization-attributes-and-comments)
[WPF 中的双向功能概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/bidirectional-features-in-wpf-overview)
[帮助主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/globalization-and-localization-how-to-topics)

## [WPF Globalization and Localization Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/wpf-globalization-and-localization-overview)

当你将自己的产品限制为只能通过一种语言使用时，便将潜在的客户群限制为全球 65 亿人口中的一小部分。 如果想让自己的应用程序被全球用户所接受，那么对产品进行经济而有效的本地化将是赢得更多客户的最好、最经济的方法。

本文概述了全球化和本地化Windows Presentation Foundation (WPF)。 全球化是指设计和开发在多个地点执行的应用程序。 例如，全球化支持适用于不同区域性用户的本地化用户界面和区域数据。 WPF 提供了全球化的设计功能，包括自动布局、 附属程序集和本地化的特性和注释。

本地化是针对应用程序所支持的特定区域性将应用程序资源转换为本地化版本的过程。 当中进行本地化WPF，使用中的 Api[System.Windows.Markup.Localizer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.localizer)命名空间。 这些 Api 支持[LocBaml 工具示例](https://go.microsoft.com/fwlink/?LinkID=160016)命令行工具。 有关如何生成和使用 LocBaml 的信息，请参阅[本地化应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-localize-an-application)。

### 在 WPF 中进行全球化和本地化的最佳做法

充分利用内置于的全球化和本地化功能WPF按照 UI 设计和本部分提供的本地化相关的技巧。

#### WPF UI 设计的最佳做法

设计时WPF– 基于UI，请考虑实施这些最佳做法：

- 编写你UI中XAML; 避免创建UI在代码中。 在创建时你UI通过使用XAML，通过内置的本地化 Api 公开。
- 避免使用绝对位置和固定的大小进行布局的内容;相反，使用相对或自动大小调整。
  - 使用[SizeToContent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.sizetocontent)并将宽度和高度设置为`Auto`。
  - 避免使用[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)布置UIs。
  - 使用[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)及其大小共享功能。
- 在边距中提供额外的空间，因为本地化文本通常需要更多空间。 额外空间为可能会延伸的字符预留了余地。
- 启用[TextWrapping](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.textwrapping)上[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)以避免剪裁。
- 设置 `xml:lang` 特性。 此属性描述特定元素及其子元素的区域性。 此属性的值更改中的许多功能的行为WPF。 例如，它可以更改断字、拼写检查、数字替换、复杂脚本成型和字体回退的行为。 请参阅[WPF 的全球化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/globalization-for-wpf)有关设置的详细信息[xml: lang 处理在 XAML 中](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/xml-lang-handling-in-xaml)。
- 创建自定义复合字体，以获取更好地控制用于不同语言的字体。 默认情况下，WPF使用 windows\fonts 目录中的 GlobalUserInterface.composite 字体。
- 当创建导航应用程序可能本地化区域性中的显示的文本从右到左格式时，显式设置[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)的每个页，以确保页面不会继承[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)从[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)。
- 创建托管浏览器之外的独立导航应用程序时，设置[StartupUri](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.startupuri)将初始应用程序[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)而不是到页面 (例如， `<Application StartupUri="NavigationWindow.xaml">`)。 此设计使您可以更改[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)窗口和导航栏。 有关详细信息和示例，请参阅[全球化主页示例](https://go.microsoft.com/fwlink/?LinkID=159990)。

#### WPF 本地化的最佳做法

进行本地化时WPF– 基于应用程序，请考虑实施下列最佳做法：

- 使用本地化注释为本地化人员提供额外的上下文。

- 使用本地化特性控制本地化，而不是选择性地省略[Uid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.localizer.bamllocalizableresourcekey.uid)元素上的属性。 请参阅[本地化特性和注释](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/localization-attributes-and-comments)有关详细信息。

- 使用`msbuild -t:updateuid`并`-t:checkuid`若要添加并检查[Uid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.localizer.bamllocalizableresourcekey.uid)中的属性在XAML。 使用[Uid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.localizer.bamllocalizableresourcekey.uid)属性，用于开发和本地化之间跟踪更改。 [Uid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.localizer.bamllocalizableresourcekey.uid) 属性可帮助您对新的开发更改进行本地化。 如果你手动添加[Uid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.localizer.bamllocalizableresourcekey.uid)属性设置为UI，该任务是通常会比较繁重并且准确性较低。

  - 请勿编辑或更改[Uid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.localizer.bamllocalizableresourcekey.uid)后开始进行本地化的属性。

  - 不要使用重复[Uid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.localizer.bamllocalizableresourcekey.uid)属性 （使用复制和粘贴命令时，请记住此提示）。

  - 设置`UltimateResourceFallback`assemblyinfo.* 若要指定合适的回退语言中的位置 (例如， `[assembly: NeutralResourcesLanguage("en-US", UltimateResourceFallbackLocation.Satellite)]`)。

    如果您决定通过省略主程序集中添加源语言`<UICulture>`在项目文件中标记中，设置`UltimateResourceFallback`与主程序集而不是附属项的位置 (例如， `[assembly: NeutralResourcesLanguage("en-US", UltimateResourceFallbackLocation.MainAssembly)]`)。

### 对 WPF 应用程序进行本地化

进行本地化时WPF应用程序中，有几个选项。 例如，将可本地化资源绑定到应用程序中XML文件，在 resx 表中存储可本地化的文本，或者让本地化人员使用可扩展应用程序标记语言 (XAML)文件。 本部分介绍使用 XAML，可提供的好处的 BAML 形式的本地化工作流：

- 可以本地化您的生成后。
- 可以从较旧版本 XAML 的 BAML 形式更新到本地化的较新版本 XAML 的 BAML 形式，以便在开发的同时进行本地化。
- 你可以验证原始源元素和语义在编译时由于 XAML 的 BAML 形式的已编译的形式XAML。

#### 本地化生成过程

开发时WPF应用程序中，本地化的生成过程如下所示：

- 开发人员创建，并将其全球化WPF应用程序。 在项目文件中，开发人员设置`<UICulture>en-US</UICulture>`，以便编译应用程序时，会生成非特定于语言的主程序集。 此程序集具有一个附属 .resources.dll 文件，其中包含所有可本地化的资源。 （可选） 在主程序集中保留源语言，因为我们本地化API支持从主程序集进行提取。
- 该文件编译为在生成时XAML转换为 XAML 的 BAML 形式。 区域性非特定`MyDialog.exe`和区域性相关 （英语）`MyDialog.resources.dll`向说英语的客户发布文件。

#### 本地化工作流

本地化过程开始后未本地化`MyDialog.resources.dll`生成文件。 UI元素和属性在原始XAML通过使用从键-值对 XAML 的 BAML 形式提取API下[System.Windows.Markup.Localizer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.localizer)。 本地化人员使用键/值对来对应用程序进行本地化。 在本地化完成之后，可以从新值生成一个新的 .resource.dll。

键 / 值对的键是`x:Uid`位于由开发人员在原始值XAML。 这些`x:Uid`值启用API来跟踪和合并在本地化过程发生在开发人员和本地化人员之间的更改。 例如，如果开发人员更改UI本地化人员开始进行本地化之后，可以合并将开发更改与已完成的本地化工作，以便使最小的翻译工作将丢失。

下图显示了一个基于 XAML 的 BAML 形式的典型本地化工作流。 此关系图假设开发人员以英语编写应用程序。开发人员创建 WPF 应用程序并将其全球化。 在项目文件中，开发人员设置`<UICulture>en-US</UICulture>`，以便在生成，语言的非特定语言主程序集获取生成的附属项。 包含所有可本地化资源的 resources.dll。 或者，因为 WPF 本地化 API 支持从主程序集进行提取，所以还可以保留主程序集中的源语言。 生成过程结束之后，XAML 会编译为 BAML。 将向说英语的客户提供非特定区域性的 MyDialog.exe.resources.dll。

![本地化工作流](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/localizationworkflow.png)

![未本地化的工作流](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/localizationworkflow2.png)

### WPF 本地化示例

本部分包含本地化的应用程序，以帮助你了解如何生成和本地化示例WPF应用程序。

#### “运行”对话框示例

下图显示的输出**运行**对话框示例。

**英语：**

![“运行”对话框](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/rundialogenglish.png)

**德语：**

![德语“运行”对话框](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/rundialoggerman.png)

**设计全球化“运行”对话框**

此示例将生成**运行**通过使用对话框WPF和XAML。 此对话框等效于**运行**对话框中，可从Microsoft Windows开始菜单。

生成全球化对话框的一些要点包括：

**自动布局**

*在 Window1.xaml 中：*

```
<Window SizeToContent="WidthAndHeight">
```

以前的 Window 属性会根据内容大小自动调整窗口大小。 此属性可以防止窗口切断在本地化之后大小增加的内容；它还可以在内容由于本地化而大小减小时删除不必要的空格。

```
<Grid x:Uid="Grid_1">
```

[Uid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.localizer.bamllocalizableresourcekey.uid) 为了使所需属性WPF本地化API才能正常工作。

它们由WPF本地化API之间的开发和本地化的跟踪更改用户界面 (UI)。 [Uid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.localizer.bamllocalizableresourcekey.uid) 属性，你可以合并的较新版本UI与较早本地化UI。 您将添加[Uid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.localizer.bamllocalizableresourcekey.uid)属性通过运行`msbuild -t:updateuid RunDialog.csproj`命令行界面中。 这是添加的建议的方法[Uid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.localizer.bamllocalizableresourcekey.uid)属性因为手动添加它们是通常比较费时并且准确性较低。 你可以检查是否[Uid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.localizer.bamllocalizableresourcekey.uid)属性正确设置通过运行`msbuild -t:checkuid RunDialog.csproj`。

UI通过使用结构化[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)控件，它是针对如何利用自动布局非常有用的控件中WPF。 请注意，对话框拆分成三行五列。 没有一种行和列定义具有固定的大小;因此，UI定位每个单元中的元素可以适应增加和减少的大小在本地化过程。

XAML复制

```xaml
<Grid.ColumnDefinitions>
  <ColumnDefinition x:Uid="ColumnDefinition_1" />
  <ColumnDefinition x:Uid="ColumnDefinition_2" />
```

前两列位置**打开：** 标签并[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)放置的 10%UI总宽度。

XAML复制

```xaml
  <ColumnDefinition x:Uid="ColumnDefinition_3" SharedSizeGroup="Buttons" />
  <ColumnDefinition x:Uid="ColumnDefinition_4" SharedSizeGroup="Buttons" />
  <ColumnDefinition x:Uid="ColumnDefinition_5" SharedSizeGroup="Buttons" />
</Grid.ColumnDefinitions>
```

请注意，该示例使用的共享大小调整功能[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)。 最后三列通过将自身放置在同一个充分利用这[SharedSizeGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.definitionbase.sharedsizegroup)。 正如属性名称所示，此属性允许不同的列采用相同大小。 因此如果"浏览..."获取已本地化为较长的字符串"Durchsuchen..."，所有按钮都增加而不是让小型的"确定"按钮和一个极大的"Durchsuchen..."按钮的宽度。

**Xml:lang**

```
Xml:lang="en-US"
```

请注意[xml: lang 处理在 XAML 中](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/xml-lang-handling-in-xaml)放置在根元素处UI。 此属性描述给定元素及其子元素的区域性。 此值由多个功能WPF，应在本地化过程相应地更改。 此值会更改在断字以及对字词进行拼写检查时所使用的字典。 它还会影响数字的显示以及字体回退系统选择所用字体的方式。 最后，该属性会影响数值的显示方式，形成在复杂脚本中编写文本的方式。 默认值为“en-US”。

**生成附属资源程序集**

*在 .csproj 中：*

编辑`.csproj`文件，并将以下标记添加到无条件`<PropertyGroup>`:

```
<UICulture>en-US</UICulture>
```

请注意，增加的`UICulture`值。 当此项设置为有效[CultureInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.globalization.cultureinfo)值，如 EN-US，生成项目将在其中生成具有所有可本地化资源的附属程序集。

```
<Resource Include="RunIcon.JPG">
<Localizable>False</Localizable>
</Resource>
```

`RunIcon.JPG`不需要进行本地化，因为它应显示相同的所有区域性。 `Localizable` 设置为`false`，以便它将保留在语言非特定语言主程序集而不是附属程序集。 所有不可编译资源的默认值是`Localizable`设置为`true`。

**本地化“运行”对话框**

**分析**

生成应用程序之后，对其进行本地化的第一步是将可本地化的资源从附属程序集中分析出来。 对于本主题的目的，使用的示例 LocBaml 工具，可以在中找到[LocBaml 工具示例](https://go.microsoft.com/fwlink/?LinkID=160016)。 请注意，LocBaml 只是一个示例工具，用于帮助你了解有关如何生成适合你的本地化过程的本地化工具的入门知识。 使用 LocBaml 可以运行以下命令以分析： **LocBaml/rundialog.resources.dll /out:** 生成"RunDialog.resources.dll.CSV"文件。

**本地化**

使用你喜欢的支持 Unicode 的 CSV 编辑器来编辑此文件。 筛选掉本地化类别为“None”的所有项。 应看到下面的项：

| 资源键                                                 | 本地化类别 | “值”                                                         |
| ------------------------------------------------------ | ---------- | ------------------------------------------------------------ |
| Button_1:System.Windows.Controls.Button.$Content       | Button     | 确定                                                         |
| Button_2:System.Windows.Controls.Button.$Content       | Button     | 取消                                                         |
| Button_3:System.Windows.Controls.Button.$Content       | Button     | 浏览...                                                      |
| ComboBox_1:System.Windows.Controls.ComboBox.$Content   | 组合框     |                                                              |
| TextBlock_1:System.Windows.Controls.TextBlock.$Content | Text       | Windows 将根据您所输入的名称，为您打开相应的程序、文件夹、文档或 Internet 资源。 |
| TextBlock_2:System.Windows.Controls.TextBlock.$Content | Text       | 打开:                                                        |
| Window_1:System.Windows.Window.Title                   | 标题       | 运行                                                         |

将该应用程序本地化为德语版本需要进行下面的翻译：

| 资源键                                                 | 本地化类别 | “值”                                                         |
| ------------------------------------------------------ | ---------- | ------------------------------------------------------------ |
| Button_1:System.Windows.Controls.Button.$Content       | Button     | 确定                                                         |
| Button_2:System.Windows.Controls.Button.$Content       | Button     | Abbrechen                                                    |
| Button_3:System.Windows.Controls.Button.$Content       | Button     | Durchsuchen…                                                 |
| ComboBox_1:System.Windows.Controls.ComboBox.$Content   | 组合框     |                                                              |
| TextBlock_1:System.Windows.Controls.TextBlock.$Content | Text       | Geben Sie den Namen eines Programms, Ordners, Dokuments oder einer Internetresource an. |
| TextBlock_2:System.Windows.Controls.TextBlock.$Content | Text       | Öffnen:                                                      |
| Window_1:System.Windows.Window.Title                   | 标题       | 运行                                                         |

**生成**

本地化的最后一步涉及创建新进行本地化的附属程序集。 可以使用下面的 LocBaml 命令完成此操作：

**LocBaml.exe /generate RunDialog.resources.dll /trans:RunDialog.resources.dll.CSV /out: . /cul:de-DE**

在德语Windows，如果此 resources.dll 放置在主程序集旁边的 DE-DE 文件夹中，此资源会自动加载而不是 EN-US 文件夹中的一个。 如果没有德语版本的Windows若要测试这一点，请将区域性设置的任何区域性Windows使用 (例如， `en-US`)，并替换原始资源 DLL。

**附属资源加载**

| MyDialog.exe     | en-US\MyDialog.resources.dll | de-DE\MyDialog.resources.dll |
| ---------------- | ---------------------------- | ---------------------------- |
| 代码             | 原始英语版 BAML              | 本地化的 BAML                |
| 非特定区域性资源 | 其他英语资源                 | 已本地化为德语的其他资源     |

.NET framework 会自动选择要加载根据应用程序的哪些附属资源程序集`Thread.CurrentThread.CurrentUICulture`。此值默认为的区域性将WindowsOS。 因此，如果您使用的德语Windows，则会加载 de-DE\MyDialog.resources.dll，如果您使用的英语Windows，则会加载 en-US\MyDialog.resources.dll。 通过在项目的 AssemblyInfo.* 中指定 NeutralResourcesLanguage，可以设置应用程序的最终回退资源。 例如，如果指定：

```
[assembly: NeutralResourcesLanguage("en-US", UltimateResourceFallbackLocation.Satellite)]
```

如果 de-DE\MyDialog.resources.dll 和 de\MyDialog.resources.dll 都不可用，则德语版 Windows 将使用 en-US\MyDialog.resources.dll。

#### Microsoft 沙特阿拉伯主页

下图显示了英语和阿拉伯语主页。 有关完整的示例生成这些图形，请参阅[全球化主页示例](https://go.microsoft.com/fwlink/?LinkID=159990)。

**英语：**

![英语页面](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/englishhomepage.jpg)

**阿拉伯语：**

![阿拉伯语页面](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/arabichomepage.jpg)

#### 设计全球 Microsoft 主页

Microsoft 沙特阿拉伯网站的这个实体模型说明了针对从右向左布局语言提供的全球化功能。 希伯来语和阿拉伯语等语言具有从右到左阅读顺序，因此布局的UI通常必须布局不是将英语等从左到右语言中，运行方式完全不同。 从从左到右布局语言本地化到从右到左布局语言可能相当困难，反之亦然。 WPF 可使此类本地化工作变得更容易。

**FlowDirection**

*Homepage.xaml:*

XAML复制

```xaml
<Page x:Uid="Page_1" x:Class="MicrosoftSaudiArabiaHomepage.Homepage"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"   
    FlowDirection="LeftToRight" 
    Localization.Comments="FlowDirection(This FlowDirection controls the actual content of the homepage)"
    xml:lang="en-US">
```

请注意[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)属性上的[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)。 更改此属性设置为[RightToLeft](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection#System_Windows_FlowDirection_RightToLeft)将更改[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)的[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)及其子元素，以便此布局UI翻转成为从右到左，如所料，阿拉伯语用户。 一个可通过指定显式替代继承行为[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)任何元素上。 [FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)属性是出现在任何[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)或文档相关的元素并且具有隐式值[LeftToRight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection#System_Windows_FlowDirection_LeftToRight)。

观察，甚至背景渐变画笔了正确的翻转当根[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)更改：

**FlowDirection="LeftToRight"**

![从左到右显示](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/lefttoright.png)

**FlowDirection="RightToLeft"**

![从右到左显示](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/righttoleft.png)

**避免对面板和控件使用固定维度**

请浏览 Homepage.xaml，注意，除了固定的宽度和高度指定的整个UI在顶部[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)，有其他固定的维度。 请勿使用固定尺寸，以防裁剪可能比源文本长的本地化文本。 WPF 面板和控件将根据其所包含的内容自动调整大小。 大多数控件还具有最小值和最大维度，可以为更多的控制设置 (例如 MinWidth ="20")。 与[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)，你还可以通过设置相对宽度和高度*(例如， `Width="0.25*"`) 或使用其单元格大小共享功能。

**本地化注释**

在很多情况下，内容可能不太明确，难以翻译。 开发人员或设计人员可通过本地化注释为本地化人员提供额外的上下文和注释。 例如，下面的 Localization.Comments 阐明了字符“|”的用法。

XAML复制

```xaml
<TextBlock 
  x:Uid="TextBlock_2" 
  DockPanel.Dock="Right" 
  Foreground="White" 
  Margin="5,0,5,0"
  Localization.Comments="$Content(This character is used as a decorative rule.)">
  |
</TextBlock>
```

此注释将成为与 TextBlock_1 的内容以及在使用 LocBaml 工具的情况下关联 (请参阅[本地化应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-localize-an-application))，可在输出.csv 文件的 TextBlock_1 行的第六列：

| 资源键                                                 | 类别 | 可读性 | 可修改性 | 注释                   | “值” |
| ------------------------------------------------------ | ---- | ------ | -------- | ---------------------- | ---- |
| TextBlock_1:System.Windows.Controls.TextBlock.$Content | Text | true   | true     | 此字符用作装饰性规则。 | \|   |

使用下面的语法可以将注释放置在任何元素的内容或属性上：

XAML复制

```xaml
<TextBlock 
  x:Uid="TextBlock_1" 
  DockPanel.Dock="Right" 
  Foreground="White" 
  Margin="5,0,5,0"
  Localization.Comments="$Content(This is a comment on the TextBlock's content.)
     Margin(This is a comment on the TextBlock's Margin property.)">
  |
 </TextBlock>
```

**本地化特性**

通常，开发人员或本地化经理需要控制本地化人员能够阅读和修改的内容。 例如，可能不希望本地化人员翻译你公司的名称或法律用语。 WPF 提供了一些特性，使用这些特性可以设置元素的内容或属性（本地化工具可以使用这些内容或属性锁定、隐藏元素或对元素进行排序）的可读性、可修改性和类别。 有关详细信息，请参阅 [Attributes](https://msdn.microsoft.com/library/system.windows.localization.attributes.aspx) 。 此示例中 LocBaml 工具仅输出这些特性的值。 WPF 控件对这些特性都使用默认值，但可以替代这些默认值。 例如，下面的示例重写的默认本地化特性`TextBlock_1`和为本地化人员设置的内容可读，但不可修改。

XAML复制

```xaml
<TextBlock
x:Uid="TextBlock_1"
Localization.Attributes=
"$Content(Readable Unmodifiable)">
  Microsoft Corporation
</TextBlock>
```

除了可读性和可修改性特性之外WPF提供了常见 UI 类别的枚举 ([LocalizationCategory](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.localizationcategory)) 可用于为本地化人员提供更多上下文。 WPF中，可以重写平台控件的默认类别XAML以及：

XAML复制

```xaml
<TextBlock x:Uid="TextBlock_2">
<TextBlock.ToolTip>
<TextBlock
x:Uid="TextBlock_3"
Localization.Attributes=
"$Content(ToolTip Readable Unmodifiable)">
Microsoft Corporation
</TextBlock>
</TextBlock.ToolTip>
Windows Vista
</TextBlock>
```

默认本地化特性WPF提供可以还通过代码进行替代，以便可以正确设置自定义控件的合适的默认值。 例如：

C#复制

```csharp
[Localizability(Readability = Readability.Readable, Modifiability=Modifiability.Unmodifiable, LocalizationCategory.None)] 
public class CorporateLogo : TextBlock
{
    // ...
}
```

实例中设置特定特性XAML将优先于自定义控件上的代码中设置的值。 有关特性和注释的详细信息，请参阅[本地化特性和注释](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/localization-attributes-and-comments)。

**字体回退和复合字体**

如果指定不支持给定的码位范围的字体WPF会自动回退到一个通过使用位于 windows\fonts 目录中的 Global User Interface.compositefont 来实现。 复合字体工作原理与任何其他字体，以及可以通过设置元素的显式使用`FontFamily`(例如， `FontFamily="Global User Interface"`)。 通过创建你自己的复合字体并指定针对特定代码点范围和语言所使用的字体，可以指定你自己的字体回退首选项。

有关复合字体的详细信息请参阅[FontFamily](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.fontfamily)。

**本地化 Microsoft 主页**

可以按照“运行”对话框示例中的相同步骤对此应用程序进行本地化。 阿拉伯语的本地化的.csv 文件，供你在[全球化主页示例](https://go.microsoft.com/fwlink/?LinkID=159990)。

## [Globalization for WPF](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/globalization-for-wpf)

本主题介绍你应注意的编写时的问题Windows Presentation Foundation (WPF)全球市场的应用程序。 全球化编程元素中定义Microsoft .NET在`System.Globalization`。

### XAML 全球化

可扩展应用程序标记语言 (XAML) 基于XML并充分利用中定义的全球化支持XML规范。 以下部分介绍一些XAML应注意的功能。

#### 字符引用

字符引用提供了特定的 UTF16 代码单元Unicode字符其表示时，以十进制或十六进制。 下面的示例演示十进制字符引用科普特语大写字母 HORI 或 Ϩ:

复制

```
&#1000;
```

下面的示例演示十六进制字符引用。 请注意，它具有**x**十六进制数字的前面。

复制

```
&#x3E8;
```

#### 编码

支持的编码XAML都ASCII， Unicode UTF-16 和 UTF-8。 编码语句位于开头XAML文档。 如果不存在编码特性，并且没有任何字节顺序，则分析器默认为 UTF-8。 UTF-8 和 UTF-16 都是首选编码。 不支持 UTF-7。 下面的示例演示如何指定 utf-8 编码中XAML文件。

复制

```
?xml encoding="UTF-8"?
```



#### 语言特性

XAML 使用[xml: lang](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/xml-lang-handling-in-xaml)来表示一个元素的 language 特性。 若要充分利用[CultureInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.globalization.cultureinfo)类，语言特性值需要是一个预定义的区域性名称的[CultureInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.globalization.cultureinfo)。 [xml:lang](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/xml-lang-handling-in-xaml) 在元素树中可继承（可按 XML 规则继承，但并不一定这样继承，因为存在依赖属性继承）；在未明确赋值的情况下，其默认值为空字符串。

语言特性对指定方言非常有用。 例如，法语在法国、魁北克、比利时和瑞士的拼写、词汇和发音各不相同。 中文、 日语和朝鲜语还共享中的代码点Unicode，但表意文字字形不同，并且它们使用完全不同的字体。

以下可扩展应用程序标记语言 (XAML)的示例使用`fr-CA`语言特性指定加拿大法语。

XML复制

```xml
<TextBlock xml:lang="fr-CA">Découvrir la France</TextBlock>
```



#### Unicode

XAML 支持所有Unicode功能，包括代理项。 只要将字符集可以映射到Unicode，它受支持。 例如，GB18030 中引入了某些可映射到中文、日语和朝鲜语 (CFK) 扩展 A 和 B 以及代理项对的字符，因此完全受支持。 一个WPF应用程序可以使用[StringInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.globalization.stringinfo)操作而无需知道其是否具有代理项对或组合字符的字符串。



### 使用 XAML 设计国际用户界面

本部分介绍用户界面 (UI)编写的应用程序时应考虑的功能。

#### 国际化文本

WPF 提供了有关所有受支持的 Microsoft.NET Framework 书写系统的内置处理。

目前支持以下脚本：

- 阿拉伯语
- 孟加拉语
- 梵文
- 西里尔文
- 希腊语
- 古吉拉特语
- 果鲁穆奇语
- 希伯来语
- 表意文字脚本
- 卡纳达语
- 老挝语
- 拉丁语
- 马拉雅拉姆语
- 蒙古语
- 奥里亚语
- 叙利亚语
- 泰米尔语
- 泰卢固语
- 塔安那文
- 泰语*
- 藏语

*此版本支持显示和编辑泰语文本，但不支持断词。

目前不支持以下脚本：

- 高棉语
- 古朝鲜语
- 缅甸语
- 僧伽罗语

所有书写系统都引擎都支持OpenType字体。 OpenType 字体可包括OpenType布局表格，字体创建者来设计更好地国际化的高端版式字体。 OpenType字体布局表格包含有关字形替换、 字形位置、 对齐和定位基线，信息使文本处理应用程序改进文本布局。

OpenType 字体，可使用处理大型字形集Unicode编码。 这种编码享有广泛的国际支持，并支持版式字形变体。

WPF 文本呈现Microsoft ClearType子像素技术，它支持分辨率独立性。 这极大地提高了可读性，并为所有脚本提供了支持高质量杂志样式文档的功能。



#### 国际化布局

WPF 提供一种支持水平、双向和垂直布局的简便方式。 在演示框架[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)属性可以用于定义布局。 流方向模式包括：

- *LeftToRight* - 适用于拉丁语和东亚语等语言的水平布局。
- *RightToLeft* - 适用于阿拉伯语和希伯来语等语言的双向布局。

### 开发可本地化的应用程序

编写供全球使用的应用程序时，应牢记应用程序必须可本地化。 以下主题指出了若干注意事项。

#### 多语言用户界面

多语言用户界面 (MUI) 是Microsoft支持用于切换UI从到另一种语言。 一个WPF应用程序使用程序集的模型来支持 MUI。 一个应用程序包含非特定语言程序集和与语言相关的附属资源程序集。 入口点是主程序集中的托管 .EXE。WPF 资源加载程序利用框架的资源管理器以支持资源查找和回退。 多个语言附属程序集使用同一个主程序集。加载资源程序集依赖于[CurrentUICulture](https://docs.microsoft.com/zh-cn/dotnet/api/system.globalization.cultureinfo.currentuiculture)当前线程。

#### 可本地化的用户界面

WPF 应用程序使用XAML来定义其UI。 通过 XAML，开发人员可使用一组属性和逻辑指定对象的层次结构。 主要用途XAML是开发WPF应用程序，但它可用于指定层次结构的任何公共语言运行时 (CLR)对象。 大多数开发人员使用XAML以指定其应用程序的UI和使用 C# 等编程语言，以响应用户交互。

从资源角度来看，XAML文件以描述依赖于语言的UI属于资源元素，因此其最终分发格式必须可本地化，以支持国际语言。 因为XAML无法处理事件许多XAML应用程序包含要执行此操作的代码块。 有关详细信息，请参阅[XAML 概述 (WPF)](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-overview-wpf)。 剥除代码并将其编译到不同的二进制文件时XAML文件标记为 XAML 的 BAML 形式。 BAML 形式的 XAML 文件、图像以及其他类型的托管资源对象将嵌入附属资源程序集中，该程序集可本地化为其他语言，如果不需要进行本地化，以上各项就会嵌入主程序集中。

 备注

WPF 应用程序支持所有框架CLR资源包括字符串表、 图像和等。



#### 生成可本地化的应用程序

本地化是指以适应UI不同的区域性。 若要使WPF应用程序可本地化，开发人员需要生成一个资源程序集的所有可本地化的资源。 资源程序集本地化为不同语言和代码隐藏功能使用资源管理API加载。 所需的文件之一WPF应用程序是项目文件 (.proj)。 应用程序中使用的所有资源都应包括在项目文件中。 以下 .csproj 文件示例演示如何执行此操作。

```xml
<Resource Include="data\picture1.jpg"/>
<EmbeddedResource Include="data\stringtable.en-US.restext"/>
```

若要使用你的应用程序中的资源实例化[ResourceManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.resources.resourcemanager)并加载你想要使用的资源。 下面的示例演示如何执行此操作。

```csharp
void OnClick(object sender, RoutedEventArgs e)
{
  ResourceManager rm = new ResourceManager ("MySampleApp.data.stringtable",
       Assembly.GetExecutingAssembly());
  Text1.Text = rm.GetString("Message");
}
```

### 在本地化的应用程序中使用 ClickOnce

ClickOnce 是将随 Visual Studio 2005 的新 Windows 窗体部署技术。 通过该技术可安装应用程序和升级 Web 应用程序。 对使用 ClickOnce 部署的应用程序进行本地化后，只能在本地化的区域性中查看该应用程序。 例如，如果部署的应用程序本地化为日语它只能查看在日语Microsoft Windows不在英文 Windows 上。 这带来问题，因为它是日语用户经常运行英语版本的 Windows 的常见方案。

此问题的解决方案是设置非特定语言回退特性。 应用程序开发人员可选择从主程序集中删除资源，并指定可在特定区域性对应的附属程序集中找到该资源。 若要控制此过程，请使用[NeutralResourcesLanguageAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.resources.neutralresourceslanguageattribute)。 构造函数[NeutralResourcesLanguageAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.resources.neutralresourceslanguageattribute)类具有两个签名，另一个采用[UltimateResourceFallbackLocation](https://docs.microsoft.com/zh-cn/dotnet/api/system.resources.ultimateresourcefallbacklocation)参数指定的位置，[ResourceManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.resources.resourcemanager)应提取回退资源： 主程序集或附属程序集。 下面的示例演示如何使用此特性。 对于最终回退位置，代码会导致[ResourceManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.resources.resourcemanager)查找当前正在执行的程序集的目录的"de"子目录中的资源。

复制

```
[assembly: NeutralResourcesLanguageAttribute(
    "de" , UltimateResourceFallbackLocation.Satellite)]
```

## [Use Automatic Layout Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/use-automatic-layout-overview)

本主题介绍如何编写上面向开发人员的指导原则Windows Presentation Foundation (WPF)具有可本地化的应用程序用户界面 (UI)。 在过去，UI 的本地化是一个耗时的过程。 UI 适用于每种语言需要按像素逐一调整。 使用适当的设计和编码标准，今天UI可以构建，这样本地化人员较少的调整大小和重新定位的工作量。 种编写可以更轻松地重设大小和重新定位应用程序的方法称为自动布局，可以通过使用WPF应用程序设计。

### 使用自动布局的优点

因为WPF的演示系统，是功能强大且灵活，它提供到可以进行调整以适应不同语言的要求的应用程序中的布局元素的功能。 下面列出自动布局的部分优点。

- UI 会显示在任何语言中。
- 减少了文本转换完后重新调整控件位置和大小的需要。
- 减少了重新调整窗口大小的需要。
- UI 布局中的任何语言正确呈现。
- 本地化过程可缩减为与进行字符串转换差不多。

### 自动布局和控件

利用自动布局，应用程序可以自动调整控件大小。 例如，控件可按字符串长度相应改变。 利用此功能，本地化人员可转换字符串，而无需再调整控件大小以适应转换后的文本。 下面的示例创建一个带有英文内容的按钮。

```xaml
<Window
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="ButtonLoc.Pane1"
    Name="myWindow"
    SizeToContent="WidthAndHeight"
    >

<DockPanel> 
    <Button FontSize="28" Height="50">My name is Hope.</Button>
</DockPanel>
</Window>
```

在此示例中，只需更改文本即可生成一个西班牙文按钮。 例如，应用于对象的

XAML复制

```xaml
<Window
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="ButtonLoc.Pane1"
    Name="myWindow"
    SizeToContent="WidthAndHeight"
    >

 <DockPanel> 
    <Button FontSize="28" Height="50">Me llamo Esperanza.</Button>
  </DockPanel>
</Window>
```

下图显示代码示例的输出。

![具有不同语言的文本的同一按钮](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/globalizationbutton.png)
自动调整大小的按钮



### 自动布局和编码标准

使用自动布局方法需要一组编码和设计标准和规则以生成可完全本地化的 UI。 下列准则可帮助完成自动布局编码。

**不要使用绝对位置**

- 不要使用[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)因为它会以绝对方式定位元素。
- 使用[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)， [StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)，和[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)来定位控件。

有关各种面板类型的讨论，请参阅[面板概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/panels-overview)。

**未设置固定的大小的窗口**

- 请使用 [Window.SizeToContent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.sizetocontent)。 例如：

  XAML复制

  ```xaml
  <StackPanel
      xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      x:Class="GridLoc.Pane1"
  >
  ```

**添加 FlowDirection**

- 添加[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)到你的应用程序的根元素。

  WPF 提供了方便地支持水平、 双向和垂直布局。 在演示框架[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)属性可以用于定义布局。 流方向模式包括：

  - [FlowDirection.LeftToRight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection#System_Windows_FlowDirection_LeftToRight) (LrTb) — 拉丁语、 东亚语言等的水平布局。
  - [FlowDirection.RightToLeft](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection#System_Windows_FlowDirection_RightToLeft) (RlTb) — 有关阿拉伯语、 希伯来语等双向。

**使用复合字体而不是物理字体**

- 使用复合字体[FontFamily](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontfamily)属性不需要进行本地化。
- 开发人员可以使用以下字体之一，也可以创建自己的字体。
  - Global User Interface
  - Global San Serif
  - Global Serif

**添加 xml: lang**

- 添加`xml:lang`特性中的根元素的 UI，如`xml:lang="en-US"`英文应用程序。
- 因为复合字体使用`xml:lang`若要确定要使用的字体，请设置此属性以支持多语言方案。



### 自动布局和网格

[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素，是对于自动布局很有用，因为它使开发人员来定位元素。 一个[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)控件是支持的分发在其子元素，使用列和行排列方式的可用空间。 UI 元素可以跨多个单元格，并且可能具有在网格内的网格。 网格非常有用，因为它们使您能够创建和定位复杂的 UI。 下面的示例演示使用网格来定位某些按钮和文本。 请注意，高度和宽度的单元格设置为[Auto](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.gridunittype#System_Windows_GridUnitType_Auto); 因此，包含带图像按钮的单元格调整以适合图像。

```xaml
<Grid Name="grid" ShowGridLines ="false">
<Grid.ColumnDefinitions>
<ColumnDefinition Width="Auto"/>
<ColumnDefinition Width="*"/>
</Grid.ColumnDefinitions>
<Grid.RowDefinitions>
<RowDefinition Height="Auto"/>
<RowDefinition Height="Auto"/>
<RowDefinition Height="Auto"/>
<RowDefinition Height="Auto"/>
<RowDefinition Height="Auto"/>
</Grid.RowDefinitions>

<TextBlock Margin="10, 10, 5, 5" Grid.Column="0" Grid.Row="0" FontSize="24">Grid
</TextBlock>
<TextBlock Margin="10, 10, 5, 5" Grid.Column="0" Grid.Row="1" FontSize="12"  
    Grid.ColumnSpan="2">The following buttons and text are positioned using a Grid.
</TextBlock>  
<Button Margin="10, 10, 5, 5" Grid.Column="0" Grid.Row="2" Background="Pink" 
    BorderBrush="Black" BorderThickness="10">Button 1
</Button>
<TextBlock Margin="10, 10, 5, 5" Grid.Column="1" Grid.Row="2" FontSize="12" 
   VerticalAlignment="Center" TextWrapping="WrapWithOverflow">Sets the background 
   color.
</TextBlock>  
<Button Margin="10, 10, 5, 5" Grid.Column="0" Grid.Row="3" Foreground="Red">
   Button 2
</Button>
<TextBlock Margin="10, 10, 5, 5" Grid.Column="1" Grid.Row="3" FontSize="12" 
   VerticalAlignment="Center" TextWrapping="WrapWithOverflow">Sets the foreground 
   color.
</TextBlock>  
<Button Margin="10, 10, 5, 5" Grid.Column="0" Grid.Row="4">
   <Image Source="data\flower.jpg"></Image>
</Button>
<TextBlock Margin="10, 10, 5, 5" Grid.Column="1" Grid.Row="4" FontSize="12" 
   VerticalAlignment="Center" TextWrapping="WrapWithOverflow">Adds an image as 
   the button's content.
</TextBlock>
</Grid>
```

下图显示了以上代码生成的网格。

![网格示例](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/glob-grid.png)
Grid



### 使用 IsSharedSizeScope 属性的自动布局和网格

一个[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素是可本地化的应用程序创建进行调整以适应内容的控件中很有用。 不过，有时可能希望控件无论包含什么内容都可以保持特定大小。 例如，对于“确定”、“取消”和“浏览”按钮，可能不希望按钮根据内容调整大小。 在这种情况下[Grid.IsSharedSizeScope](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid.issharedsizescope)附加的属性可用于共享多个网格元素之间同样的大小。 下面的示例演示如何共享列和行的大小之间多个数据[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素。

```xaml
   <StackPanel Orientation="Horizontal" DockPanel.Dock="Top">  
       <Button Click="setTrue" Margin="0,0,10,10">Set IsSharedSizeScope="True"</Button>
       <Button Click="setFalse" Margin="0,0,10,10">Set IsSharedSizeScope="False"</Button>
   </StackPanel> 

   <StackPanel Orientation="Horizontal" DockPanel.Dock="Top">

   <Grid ShowGridLines="True" Margin="0,0,10,0">
     <Grid.ColumnDefinitions>
       <ColumnDefinition SharedSizeGroup="FirstColumn"/>
       <ColumnDefinition SharedSizeGroup="SecondColumn"/>
     </Grid.ColumnDefinitions>
     <Grid.RowDefinitions>
       <RowDefinition Height="Auto" SharedSizeGroup="FirstRow"/>
     </Grid.RowDefinitions>

       <Rectangle Fill="Silver" Grid.Column="0" Grid.Row="0" Width="200" Height="100"/>
       <Rectangle Fill="Blue" Grid.Column="1" Grid.Row="0" Width="150" Height="100"/>

       <TextBlock Grid.Column="0" Grid.Row="0" FontWeight="Bold">First Column</TextBlock>
       <TextBlock Grid.Column="1" Grid.Row="0" FontWeight="Bold">Second Column</TextBlock>
   </Grid>

   <Grid ShowGridLines="True">
     <Grid.ColumnDefinitions>
       <ColumnDefinition SharedSizeGroup="FirstColumn"/>
       <ColumnDefinition SharedSizeGroup="SecondColumn"/>
     </Grid.ColumnDefinitions>
     <Grid.RowDefinitions>        
       <RowDefinition Height="Auto" SharedSizeGroup="FirstRow"/>
     </Grid.RowDefinitions>

       <Rectangle Fill="Silver" Grid.Column="0" Grid.Row="0"/>
       <Rectangle Fill="Blue" Grid.Column="1" Grid.Row="0"/>

       <TextBlock Grid.Column="0" Grid.Row="0" FontWeight="Bold">First Column</TextBlock>
       <TextBlock Grid.Column="1" Grid.Row="0" FontWeight="Bold">Second Column</TextBlock>
   </Grid>
   
   </StackPanel>

   <TextBlock Margin="10" DockPanel.Dock="Top" Name="txt1"/>
```

**请注意**完整的代码示例，请参阅[共享大小调整属性网格之间](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-share-sizing-properties-between-grids)

## [Localization Attributes and Comments](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/localization-attributes-and-comments)

Windows Presentation Foundation (WPF) 本地化注释是由开发人员提供的 XAML 源代码中的属性，用于提供本地化规则和提示。 Windows Presentation Foundation (WPF) 本地化注释包含两组信息：可本地化特性和任意形式的本地化注释。 可本地化特性由 WPF 本地化 API 用于指示哪些资源要进行本地化。 任意形式的注释是应用程序作者希望包含的任何信息。

### 本地化注释

如果标记应用程序作者对 XAML 中的特定元素具有一定的要求（如对文本长度、字体系列或字号进行约束），则他们可以借助于 XAML 代码中的注释将此信息传达给本地化人员。 下面是用来向源代码中添加注释的过程：

1. 应用程序开发人员向 XAML 源代码中添加本地化注释。

2. 在生成过程中，可以在 .proj 文件中指定是将任意形式的本地化注释留在程序集内、去掉部分注释还是去掉所有注释。 去掉的注释放在一个单独的文件中。 可以使用 `LocalizationDirectivesToLocFile` 标记指定你的选项，例如：

   `<LocalizationDirectivesToLocFile>` 值 `</LocalizationDirectivesToLocFile>`

3. 可以分配的值包括：

   - **None** - 注释和特性都保留在程序集中，不会生成单独的文件。
   - **CommentsOnly** - 仅从程序集中去掉注释，并将它们放在单独的 LocFile 中。
   - **All** - 从程序集中去掉注释和特性，并将它们两者都放在单独的 LocFile 中。

4. 从 BAML 中提取可本地化资源时，可本地化性特性将由 BAML 本地化 API 保留。

5. 以后可以将仅包含任意形式的注释的本地化注释文件合并到本地化过程中。

以下示例演示如何将本地化注释添加到 XAML 文件中。

```
<TextBlock x:Id = "text01"
FontFamily = "Microsoft Sans Serif"
FontSize = "12"
Localization.Attributes = "$Content (Unmodifiable Readable Text)
FontFamily (Unmodifiable Readable)"
Localization.Comments = "$Content (Trademark)
FontSize (Trademark font size)" >
Microsoft
</TextBlock>
```

在上一示例中，Localization.Attributes 部分包含本地化特性，Localization.Comments 部分包含任意形式的注释。下表显示了特性和注释及其对于本地化人员的含义。

| 本地化特性                     | 含义                                                         |
| ------------------------------ | ------------------------------------------------------------ |
| $Content（不可修改的可读文本） | 无法修改 TextBlock 元素的内容。 本地化人员不能更改单词“Microsoft”。 内容对本地化人员可见（可读）。 内容为文本类别。 |
| FontFamily（不可修改但可读）   | 无法更改 TextBlock 元素的字体系列属性，但该属性对本地化人员可见。 |

| 本地化任意形式的注释 | 含义                                                      |
| -------------------- | --------------------------------------------------------- |
| $Content（商标）     | 应用程序作者告知本地化人员 TextBlock 元素中的内容是商标。 |
| FontSize（商标字号） | 应用程序作者指示字号属性应遵循标准商标大小。              |

### 可本地化特性

Localization.Attributes 中的信息包含对的列表：目标值名称和关联的可本地化值。 目标名称可以是属性名称或特殊 $Content 名称。 如果是属性名称，则目标值为属性的值。 如果是 $Content，则目标值为元素的内容。

有三种类型的特性：

- **Category**。 它指定是否可以从本地化工具修改值。 请参阅 [Category](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.localizabilityattribute.category)。
- **Readability**。 它指定本地化工具是否可读取（和显示）值。 请参阅 [Readability](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.localizabilityattribute.readability)。
- **Modifiability**。 它指定本地化工具是否允许修改值。 请参阅 [Modifiability](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.localizabilityattribute.modifiability)。

这些特性可以按照由空格分开的任何顺序进行指定。 如果指定了重复特性，则最后一个特性将替代前面的特性。例如，Localization.Attributes = "Unmodifiable Modifiable" 会将 Modifiability 设置为 Modifiable，因为最后一个值是 Modifiable。

Modifiability 和 Readability 的名称已经揭示了自身的含义。 “Category”特性提供的预定义类别可帮助本地化人员翻译文本。 类别（如 Text、Label 和 Title）为本地化人员提供了有关如何翻译文本的信息。 也有一些特殊类别：无、 继承、 忽略，和 NeverLocalize。

下表显示了这些特殊类别的含义。

| 类别          | 含义                                                         |
| ------------- | ------------------------------------------------------------ |
| 无            | 没有为目标值定义类别。                                       |
| 继承          | 目标值从其父级继承其类别。                                   |
| 忽略          | 在本地化过程中将忽略目标值。 Ignore 仅影响当前值。 它不会影响子节点。 |
| NeverLocalize | 无法对当前值进行本地化。 此类别由元素的子级继承。            |

### 本地化注释

Localization.Comments 包含与目标值有关的任意形式的字符串。 应用程序开发人员可以添加一些信息，以便为本地化人员提供有关如何翻译应用程序文本的提示。 注释格式可以是由“()”括起来的任何字符串。 可以使用“\”对字符进行转义。

## [Bidirectional Features in WPF Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/bidirectional-features-in-wpf-overview)

与其他任何开发平台不同WPF具有支持的双向内容快速开发的许多功能，例如，混合从左到右和从右到左同一文档中的数据。 同时，在WPF创建需要双向功能，如阿拉伯语和希伯来语用户的用户的卓越的体验。

以下各节结合一些示例阐释了如何获得双向内容的最佳显示效果，并对许多双向功能进行了说明。 大多数示例使用XAML，但可以轻松地将应用到的概念C#或 Microsoft Visual Basic 代码。

### FlowDirection

基本属性，用于定义中的内容流动方向WPF应用程序是[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)。 此属性可以设置为两个枚举值之一[LeftToRight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection#System_Windows_FlowDirection_LeftToRight)或[RightToLeft](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection#System_Windows_FlowDirection_RightToLeft)。 该属性可供所有WPF继承元素[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)。

下面的示例设置的流方向[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)元素。

**从左向右的流方向**

```xaml
<TextBlock Background="DarkBlue" Foreground="LightBlue" 
   FontSize="20" FlowDirection="LeftToRight">
        This is a left-to-right TextBlock
</TextBlock>
```

**从右向左的流方向**

```xaml
<TextBlock Background="LightBlue" Foreground="DarkBlue"
   FontSize="20" FlowDirection="RightToLeft">
        This is a right-to-left TextBlock
</TextBlock>
```

下图显示了前面代码的呈现方式。

**阐释 FlowDirection 的图形**

![TextBlock 对齐](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/lefttorightrighttoleft.png)

中的某个元素用户界面 (UI)树将继承[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)从其容器。 在以下示例中，[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)位于[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)，后者位于[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)。 设置[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)有关[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)意味着将为其设置[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)和[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)也。

下面的示例演示了如何设置[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)。

XAML复制

```xaml
<Window
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="FlowDirectionApp.Window1"
    Title="BidiFeatures" Height="200" Width="700" 
    FlowDirection="RightToLeft">
     
    <Grid>
      <Grid.ColumnDefinitions>
        <ColumnDefinition/>
        <ColumnDefinition/>
      </Grid.ColumnDefinitions>
      <TextBlock Grid.Column="0" >
          This is a right-to-left TextBlock
      </TextBlock>

      <TextBlock Grid.Column="1" FlowDirection="LeftToRight">
          This is a left-to-right TextBlock
      </TextBlock>
    </Grid>
</Window>
```

最高级别[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)已[RightToLeft](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection#System_Windows_FlowDirection_RightToLeft) [FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)，因此它所包含的所有元素也都继承同一[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)。 若要重写指定的元素[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)，必须添加显式方向更改的第二个[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)在前面的示例，这会更改为[LeftToRight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection#System_Windows_FlowDirection_LeftToRight)。 如果未[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)定义，则默认值[LeftToRight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection#System_Windows_FlowDirection_LeftToRight)适用。

下图显示了上一个示例的输出。

**阐释显式分配的 FlowDirection 的图形**

![流方向图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/flowdir.png)

### FlowDocument

许多开发平台，如HTML，Win32和 Java 对双向内容开发提供特殊支持。 标记语言，如HTML为内容编写器提供在任何所需的方向，例如显示文本时必需的标记HTML4.0 标记、 采用"rtl"或"ltr"作为值的"dir"。 此标记是类似于[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)属性，但[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.flowdirection)属性来布局文本内容的更高级的方式工作，并且可以用于文本以外的内容。

在中WPF、 一个[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)是一种多功能UI元素，可承载文本、 表、 图像和其他元素的组合。 以下各节中的示例均使用此元素。

将文本添加到[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)可以用多种方式。 若要执行此操作的简单方法是通过[Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph)这是用于对文本等内容进行分组的块级元素。 若要将文本添加到内联级元素的示例使用[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)和[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run)。 [Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span) 是用于对其他内联元素进行分组的内联级流内容元素时[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run)是内联级别流内容元素应包含一系列无格式文本。 一个[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)可以包含多个[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run)元素。

第一个文档示例包含具有多个网络共享名称; 的文档例如`\\server1\folder\file.ext`。 无论此网络链接是包含在阿拉伯语文档还是英语文档中，建议始终以相同的方式显示它。 下图显示了该链接在阿拉伯语[RightToLeft](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection#System_Windows_FlowDirection_RightToLeft)文档。

**阐释如何使用 Span 元素的图形**

![从右向左显示的文档](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/flowdocument.png)

由于文本是[RightToLeft](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection#System_Windows_FlowDirection_RightToLeft)，因此所有特殊字符，如"\"，将文本从右到左的顺序分隔。 那样会导致不正确的顺序显示的链接，因此若要解决此问题，必须嵌入文本以保留一个单独[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run)流动[LeftToRight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection#System_Windows_FlowDirection_LeftToRight)。 而不是单独[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run)为每种语言更好的方法来解决此问题是将不常使用英语文本嵌入到较大的阿拉伯语[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)。

下图阐释了这一点。

**阐释在 Span 元素中使用嵌入的 Run 元素的图形**

![XamlPad 屏幕截图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/runspan.png)

下面的示例演示了如何使用[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run)和[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)文档中的元素。

XAML复制

```xaml
<Page
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    FlowDirection="RightToLeft">

  <FlowDocument>
    <Paragraph>
      <Span FlowDirection="RightToLeft" >
        ستجد الملف هنا:
        <Run FlowDirection="LeftToRight">
           \\server1\filename\filename1.txt</Run>
        ثم باقى النص!
      </Span>
    </Paragraph>
  </FlowDocument>
</Page>
```



### Span 元素

[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)元素充当具有不同流方向的文本之间的边界分隔符。 甚至[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)具有相同的流方向的元素将被视为具有不同的双向范围，这意味着[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)元素的容器中的排序[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)中的内容[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)元素遵循[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)的[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)。

下图显示了多个流方向[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素。

**阐释多个 TextBlock 中的 FlowDirection 的图形**

![具有不同流方向的文本块](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/span.png)

下面的示例演示如何使用[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)和[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run)元素生成上图中显示的结果。

XAML复制

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation">
  <StackPanel >

    <TextBlock FontSize="20" FlowDirection="RightToLeft">
      <Run FlowDirection="LeftToRight">العالم</Run>
      <Run FlowDirection="LeftToRight" Foreground="Red" >فى سلام</Run>
    </TextBlock>

    <TextBlock FontSize="20" FlowDirection="LeftToRight">
      <Run FlowDirection="RightToLeft">العالم</Run>
      <Run FlowDirection="RightToLeft" Foreground="Red" >فى سلام</Run>
    </TextBlock>

    <TextBlock FontSize="20" Foreground="Blue">العالم فى سلام</TextBlock>

    <Separator/>

    <TextBlock FontSize="20" FlowDirection="RightToLeft">
      <Span Foreground="Red" FlowDirection="LeftToRight">Hello</Span>
      <Span FlowDirection="LeftToRight">World</Span>
    </TextBlock>

    <TextBlock FontSize="20" FlowDirection="LeftToRight">
      <Span Foreground="Red" FlowDirection="RightToLeft">Hello</Span>
      <Span FlowDirection="RightToLeft">World</Span>
    </TextBlock>

    <TextBlock FontSize="20" Foreground="Blue">Hello World</TextBlock>

  </StackPanel>

</Page>
```

在中[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)在示例中，元素[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)元素进行布局根据[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)其父项，但在每个文本[Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.span)元素根据其自己的流[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)。 这适用于拉丁语和阿拉伯语，也适用于任何其他语言。

#### 添加 xml:lang

下图显示了另一个示例，使用数字和算术表达式，如`"200.0+21.4=221.4"`。 请注意，只有[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)设置。

**仅通过 FlowDirection 显示数字的图形**

![从右向左流动的数字](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/langattribute.png)

此应用程序的用户将输出感到失望，即使[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)正确数字形状不是阿拉伯语数字应有的形状。

XAML 元素可以包括XML属性 (`xml:lang`)，用于定义每个元素的语言。 XAML 还支持XML语言原则，由此`xml:lang`值应用于树中的父元素由子元素。 在上一示例中，因为没有为定义一种语言[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run)元素或其上的任何级别的元素，默认值`xml:lang`时使用的这是`en-US`的 XAML。 内部数字整理算法Windows Presentation Foundation (WPF)选择数字中的相应语言 – 在这种情况下为英语。 若要使阿拉伯语数字呈现正确`xml:lang`需要设置。

下图显示了使用示例`xml:lang`添加。

**阐释如何使用 xml:lang 属性的图形**

![从右向左流动的阿拉伯语数字](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/langattribute2.png)

下面的示例添加`xml:lang`到应用程序。

XAML复制

```xaml
<Page
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    FlowDirection="RightToLeft">
      <FlowDocument>
         <Paragraph>
            <Span FlowDirection="RightToLeft" Language="ar-SA">
              العملية الحسابية: "200.0+21.4=221.4"
            </Span>
         </Paragraph>
      </FlowDocument>
</Page>
```

请注意，许多语言具有不同`xml:lang`具体取决于目标区域，例如，值`"ar-SA"`和`"ar-EG"`表示阿拉伯语的两种变体。 前面的示例演示了需要同时定义`xml:lang`和[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)值。

### 非文本元素的 FlowDirection

[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection) 定义不仅文本流动方式中的文本元素，但也几乎所有其他的流方向UI元素。 下图演示[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)使用水平[LinearGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush)绘制其背景。

**演示从左向右渐变的工具栏的图形**

![渐变屏幕截图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/gradient.png)

设置后[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)到[RightToLeft](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection#System_Windows_FlowDirection_RightToLeft)、 不仅[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)从右到左，但即使排列按钮[LinearGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush)将沿其偏移量，从右到左流动。

下图演示重新调整[LinearGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush)。

**演示工具栏从右到左渐变的图形**

![从右到左流动的渐变](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/gradient2-wpf.png)

下面的示例绘制[RightToLeft](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection#System_Windows_FlowDirection_RightToLeft) [ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)。 (若要绘制它从左到右，删除[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)特性，可以在[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)。

XAML复制

```xaml
<Page
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
  
  <ToolBar FlowDirection="RightToLeft" Height="50" DockPanel.Dock="Top">
    <ToolBar.Background>
      <LinearGradientBrush StartPoint="0,0.5" EndPoint="1,1">
        <LinearGradientBrush.GradientStops>
          <GradientStop Color="DarkRed" Offset="0" />
          <GradientStop Color="DarkBlue" Offset="0.3" />
          <GradientStop Color="LightBlue" Offset="0.6" />
          <GradientStop Color="White" Offset="1" />
        </LinearGradientBrush.GradientStops>
      </LinearGradientBrush>
    </ToolBar.Background>

    <Button FontSize="12" Foreground="White">Button1</Button>
    <Rectangle Width="20"/>
    <Button FontSize="12" Foreground="White">Button2</Button>
    <Rectangle Width="20"/>
    <Button FontSize="12" Foreground="White">Button3</Button>
    <Rectangle Width="20"/>
    <Button FontSize="12" Foreground="White">Button4</Button>
    <Rectangle Width="20"/>
  </ToolBar>
</Page>
```

#### FlowDirection 异常

有少数情况下，[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)与预期不符。 本部分介绍其中两种异常。

**Image**

[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)表示显示图像的控件。 在中XAML可与[Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image.source)属性，用于定义统一资源标识符 (URI)的[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)显示。

与其他不同UI元素，[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)不会继承[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)从容器。 但是，如果[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)显式设置为[RightToLeft](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection#System_Windows_FlowDirection_RightToLeft)、[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)水平翻转方式显示。 这可作为一种便捷功能提供给双向内容的开发人员，因为在某些情况下，水平翻转图像会达到所需的效果。

下图显示了一个翻转[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)。

**阐释翻转后的图像的图形**

![XamlPad 屏幕截图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/image.png)

下面的示例演示[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)无法继承[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)从[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)包含它。 **请注意**必须具有名为的文件**ms_logo.jpg**若要运行此示例在 C:\ 驱动器上。

XAML复制

```xaml
<StackPanel 
  xmlns='http://schemas.microsoft.com/winfx/2006/xaml/presentation' 
  FlowDirection="RightToLeft">

  <Image Source="file://c:/ms_logo.jpg" 
         Width="147" Height="50"/>
  <Separator Height="10"/>
  <Image Source="file://c:/ms_logo.jpg" 
         Width="147" Height="50" FlowDirection="LeftToRight" />
  <Separator Height="10"/>
  <Image Source="file://c:/ms_logo.jpg" 
         Width="147" Height="50" FlowDirection="RightToLeft"/>
</StackPanel>
```

**请注意**包含在下载文件中的是**ms_logo.jpg**文件。 该代码假定 .jpg 文件不在项目中，而是位于 C:\ 驱动器中的某个位置。 必须将 .jpg 从项目文件复制到 C:\ 驱动器或更改代码才能在项目内查找该文件。 若要执行此更改`Source="file://c:/ms_logo.jpg"`到`Source="ms_logo.jpg"`。

**Path**

除了[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)，另一个值得关注的元素[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)。 Path 是可用于绘制一系列连接的直线和曲线的对象。 它的行为方式类似于[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)有关其[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)，例如其[RightToLeft](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection#System_Windows_FlowDirection_RightToLeft)[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)是的水平镜像其[LeftToRight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection#System_Windows_FlowDirection_LeftToRight)之一。 但是，与不同[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)，[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)继承其[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)从该容器，一个不需要显式指定。

下面的示例使用 3 条线绘制简单的箭头。 第一个箭头继承[RightToLeft](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection#System_Windows_FlowDirection_RightToLeft)流方向从[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)，以便从右侧的根测量其起点和终点。 第二个箭头具有显式[RightToLeft](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection#System_Windows_FlowDirection_RightToLeft)[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)右侧还会启动。 但第三个箭头的起始根位于左侧。 有关详细信息，请参阅绘制[LineGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.linegeometry)和[GeometryGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometrygroup)。

XAML复制

```xaml
<StackPanel 
  xmlns='http://schemas.microsoft.com/winfx/2006/xaml/presentation' 
  FlowDirection="RightToLeft">

  <Path Stroke="Blue" StrokeThickness="4">
    <Path.Data>
      <GeometryGroup >
        <LineGeometry StartPoint="300,10" EndPoint="350,30" />
        <LineGeometry StartPoint="10,30" EndPoint="352,30" />
        <LineGeometry StartPoint="300,50" EndPoint="350,30" />
      </GeometryGroup>
    </Path.Data>
  </Path>

  <Path Stroke="Red" StrokeThickness="4" FlowDirection="RightToLeft">
    <Path.Data>
      <GeometryGroup >
        <LineGeometry StartPoint="300,10" EndPoint="350,30" />
        <LineGeometry StartPoint="10,30" EndPoint="352,30" />
        <LineGeometry StartPoint="300,50" EndPoint="350,30" />
      </GeometryGroup>
    </Path.Data>
  </Path>
 
  <Path Stroke="Green" StrokeThickness="4" FlowDirection="LeftToRight">
    <Path.Data>
      <GeometryGroup >
        <LineGeometry StartPoint="300,10" EndPoint="350,30" />
        <LineGeometry StartPoint="10,30" EndPoint="352,30" />
        <LineGeometry StartPoint="300,50" EndPoint="350,30" />
      </GeometryGroup>
    </Path.Data>
  </Path>
</StackPanel>
```

下图显示了上一个示例的输出。

**阐释使用 Path 元素绘制的箭头的图形**

![路径](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/paths.png)

[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)并[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)两个示例说明了如何Windows Presentation Foundation (WPF)使用[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)。 旁边布置UI容器内特定方向中的元素[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)可用于元素如[InkPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkpresenter)它将呈现图面上的墨迹[LinearGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush)， [RadialGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.radialgradientbrush)。 每当模拟从左到右行为对内容需要右到左行为反过来也一样，Windows Presentation Foundation (WPF)提供该功能。

#### 数字替换

从历史上看，Windows支持数字替换： 允许同时在不同的区域设置之间统一这些数字的内部存储，例如，数字将存储在相同数字使用不同区域性形状的表示形式其常见的十六进制值，如 0x40、 0x41，但却根据所选语言显示。

这样，应用程序来处理而无需将它们从一种语言转换为另一个数值，例如，用户可以打开Microsoft Excel电子表格在本地化的阿拉伯语Windows，看到阿拉伯文形状在阿拉伯语中的数字，但中将其打开欧洲版本Windows看到相同数字的欧洲表示形式。 这对其他符号（如逗号分隔符和百分比符号）来说也是必需的，因为在同一文档中它们通常随数字一起出现。

Windows Presentation Foundation (WPF) 沿承了这一传统，并为此功能提供了进一步支持，以允许更多的用户对使用替换的时间和方式进行控制。 虽然此功能适用于任何语言，但它对双向内容尤其有用；由于应用程序可能会在各种区域性下运行，因此针对特定语言来设置数字形状通常是应用程序开发人员所面临的难题。

在中工作的核心属性控制如何执行数字替换Windows Presentation Foundation (WPF)是[Substitution](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.numbersubstitution.substitution)依赖项属性。[NumberSubstitution](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.numbersubstitution)类指定文本中的数字的显示方式。 它有三个定义其行为的公共属性。 下面概括了其中的每个属性。

**CultureSource：**

此属性指定如何确定数字的区域性。 它采用三个之一[NumberCultureSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.numberculturesource)枚举值。

- 重写： 数字区域性是[CultureOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.numbersubstitution.cultureoverride)属性。
- Text：数字区域性是文本运行的区域性。 在标记中，这将是`xml:lang`，或其别名`Language`属性 ([Language](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.language)或[Language](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement.language))。 此外，它是派生自的类的默认值[FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement)。 此类类包括[System.Windows.Documents.Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph)， [System.Windows.Documents.Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)， [System.Windows.Documents.TableCell](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.tablecell) ，依此类推。
- User：数字区域性是当前线程的区域性。 此属性是默认值的所有子类[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)如[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)，[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)和[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)。

**CultureOverride**：

[CultureOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.numbersubstitution.cultureoverride)属性时才使用[CultureSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.numbersubstitution.culturesource)属性设置为[Override](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.numberculturesource#System_Windows_Media_NumberCultureSource_Override)否则将忽略。 该属性指定数字区域性。 值为`null`，默认值解释为 EN-US。

**Substitution**：

此属性指定要执行的数字替换类型。 它采用以下之一[NumberSubstitutionMethod](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.numbersubstitutionmethod)枚举值。

- [AsCulture](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.numbersubstitutionmethod#System_Windows_Media_NumberSubstitutionMethod_AsCulture)： 替换方法根据数字区域性确定[NumberFormatInfo.DigitSubstitution](https://docs.microsoft.com/zh-cn/dotnet/api/system.globalization.numberformatinfo.digitsubstitution)属性。 这是默认设置。
- [Context](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.numbersubstitutionmethod#System_Windows_Media_NumberSubstitutionMethod_Context)： 如果数字区域性为阿拉伯语或波斯语区域性，它指定数字取决于上下文。
- [European](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.numbersubstitutionmethod#System_Windows_Media_NumberSubstitutionMethod_European)： 数字始终呈现为欧洲数字。
- [NativeNational](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.numbersubstitutionmethod#System_Windows_Media_NumberSubstitutionMethod_NativeNational)： 使用指定的区域性的数字区域性民族数字呈现数字[NumberFormat](https://docs.microsoft.com/zh-cn/dotnet/api/system.globalization.cultureinfo.numberformat)。
- [Traditional](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.numbersubstitutionmethod#System_Windows_Media_NumberSubstitutionMethod_Traditional)： 使用数字区域性的传统数字呈现数字。 对于大多数区域性，这是与相同[NativeNational](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.numbersubstitutionmethod#System_Windows_Media_NumberSubstitutionMethod_NativeNational)。 但是，[NativeNational](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.numbersubstitutionmethod#System_Windows_Media_NumberSubstitutionMethod_NativeNational)而此值产生阿拉伯数字让所有阿拉伯语区域性产生拉丁数字让某些阿拉伯语区域性。

这些值对双向内容开发人员意味着什么？ 在大多数情况下，可能需要开发人员只需定义[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)以及每个文本的语言UI元素，例如`Language="ar-SA"`并且[NumberSubstitution](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.numbersubstitution)逻辑负责根据正确的数字显示UI。 下面的示例演示了如何使用中的阿拉伯数字和英文数字Windows Presentation Foundation (WPF)应用程序运行在阿拉伯语版的Windows。

```xaml
<Page 
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml" >
  <StackPanel>
   <TextBlock Background="LightGreen" FontSize="32" 
      Language="ar-SA" FlowDirection="RightToLeft">1+2=3</TextBlock>
   <TextBox Background="LightGreen" FontSize="32" 
      Language="ar-SA" FlowDirection="RightToLeft">1+2=3</TextBox>
   <TextBlock Background="LightBlue" FontSize="32">1+2=3</TextBlock>
   <TextBox Background="LightBlue" FontSize="32">1+2=3</TextBox>
 </StackPanel>
</Page>
```

下图显示了上一示例的输出，如果您正在阿拉伯语版的Windows。

**演示显示的阿拉伯数字和英文数字**

![具有数字的 XamlPad 屏幕截图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/numbers.png)

[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)因重要这种情况下设置[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)到[LeftToRight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection#System_Windows_FlowDirection_LeftToRight)改为时会产生欧洲数字。 以下各节介绍如何在整个文档内统一显示数字。 如果未在阿拉伯语版 Windows 上运行此示例，所有数字都将显示为欧洲数字。

**定义替换规则**

在实际的应用程序中，可能需要以编程方式设置语言。 例如，想要设置`xml:lang`要使用的系统的相同属性UI，或可能更改的语言，具体取决于应用程序状态。

如果你想要更改根据应用程序的状态，请提供其他功能的使用Windows Presentation Foundation (WPF)。

首先，将设置应用程序组件的`NumberSubstitution.CultureSource="Text"`。 使用此设置可确保设置不是来自UI的文本元素，具有"用户"为默认值，如[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)。

例如：

XAML复制

```xaml
<TextBlock
   Name="text1" NumberSubstitution.CultureSource="Text">
   1234+5679=6913
</TextBlock>
```

在相应C#代码中，设置`Language`属性，例如，若`"ar-SA"`。

C#复制

```csharp
text1.Language = System.Windows.Markup.XmlLanguage.GetLanguage("ar-SA");
```

如果您需要设置`Language`属性设置为当前用户的 UI 语言使用下面的代码。

C#复制

```csharp
text1.Language = System.Windows.Markup.XmlLanguage.GetLanguage(System.Globalization.CultureInfo.CurrentUICulture.IetfLanguageTag);
```

[CultureInfo.CurrentCulture](https://docs.microsoft.com/zh-cn/dotnet/api/system.globalization.cultureinfo.currentculture) 表示在运行时使用当前线程的当前区域性。

最终XAML示例应类似于下面的示例。

XAML复制

```xaml
<Page x:Class="WindowsApplication.Window1"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    Title="Code Sample" Height="300" Width="300"
>
    <StackPanel>
      <TextBlock Language="ar-SA" 
         FlowDirection="RightToLeft">عربى: 1+2=3
      </TextBlock>
      <TextBlock Language="ar-SA" 
         FlowDirection="RightToLeft" 
         NumberSubstitution.Substitution="European">عربى: 1+2=3 
      </TextBlock>
    </StackPanel>
</Page>
```

最终C#应类似于以下示例。

C#复制

```csharp
namespace BidiTest
{
    public partial class Window1 : Window
    {

        public Window1()
        {
            InitializeComponent();

            string currentLanguage = 
                System.Globalization.CultureInfo.CurrentCulture.IetfLanguageTag;

            text1.Language = System.Windows.Markup.XmlLanguage.GetLanguage(currentLanguage);

            if (currentLanguage.ToLower().StartsWith("ar"))
            {
                text1.FlowDirection = FlowDirection.RightToLeft;
            }
            else
            {
                text1.FlowDirection = FlowDirection.LeftToRight;
            }
        }
    }
}
```

下图演示用于任一编程语言的窗口的外观。

**显示阿拉伯数字的图形**

![阿拉伯数字](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/numbers2.png)

**使用 Substitution 属性**

的数字替换方式Windows Presentation Foundation (WPF)取决于语言的文本元素并将其[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)。 如果[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)从左到右，则会呈现欧洲数字。 但是如果前面为阿拉伯语文本或语言设置为"ar"和[FlowDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection)是[RightToLeft](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.flowdirection#System_Windows_FlowDirection_RightToLeft)，会改为呈现阿拉伯数字。

但在某些情况下，建议创建统一的应用程序，例如适用于所有用户的欧洲数字。 或格中呈现阿拉伯数字[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)具有特定的单元格[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)。 一个简单的方法是使用[Substitution](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.numbersubstitution.substitution)属性。

在以下示例中，第一个[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)不具有[Substitution](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.numbersubstitution.substitution)设置属性，因此该算法会按预期方式显示阿拉伯数字。 但是在第二个[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)，替换设置为了欧洲，重写默认值替换为阿拉伯语数字，并将显示欧洲数字。

XAML复制

```xaml
<Page x:Class="WindowsApplication.Window1"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    Title="Code Sample" Height="300" Width="300"
>
    <StackPanel>
      <TextBlock Language="ar-SA" 
         FlowDirection="RightToLeft">عربى: 1+2=3
      </TextBlock>
      <TextBlock Language="ar-SA" 
         FlowDirection="RightToLeft" 
         NumberSubstitution.Substitution="European">عربى: 1+2=3 
      </TextBlock>
    </StackPanel>
</Page>
```

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/globalization-and-localization-how-to-topics)

本部分中的主题介绍如何开发全球通用应用程序。

[对应用程序进行本地化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-localize-an-application)
[使用自动布局创建按钮](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-use-automatic-layout-to-create-a-button)
[使用网格进行自动布局](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-use-a-grid-for-automatic-layout)
[使用 ResourceDictionary 管理可本地化的字符串资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-use-a-resourcedictionary-to-manage-localizable-string-resources)
[在可本地化的应用程序中使用资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-use-resources-in-localizable-applications)

### [Localize an Application](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-localize-an-application)

本教程介绍如何通过使用 LocBaml 工具创建本地化应用程序。

> LocBaml 工具不是可直接用于生产的应用程序。 它表示为一个示例，该示例使用某些本地化 API 并演示编写一个本地化工具的方法。

#### 概述

本讨论提供逐步实现本地化应用程序的方法。 首先，你要准备应用程序，以便可以提取将被翻译的文本。 相关文本翻译后，你要将翻译的文本合并到原始应用程序的新副本中。

#### 要求

在此讨论过程中，你将使用 Microsoft Build Engine (MSBuild)，这是一个从命令行运行的编译器。

此外，还会指导你使用项目文件。 有关说明如何使用MSBuild和项目文件，请参阅[生成并部署](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/building-and-deploying-wpf-applications)。

在此讨论中的所有示例都使用 zh-CN（中文-中国）作为区域设置。 这使你能够而无需安装另一种语言就能完成这些示例的步骤。

#### 创建一个简单的应用程序

在此步骤中，你将准备要用于本地化的应用程序。 Windows Presentation Foundation (WPF) 示例提供了 HelloApp 示例，将用于本讨论中的代码示例。 如果想要使用此示例中，下载可扩展应用程序标记语言 (XAML)文件从[LocBaml 工具示例](https://go.microsoft.com/fwlink/?LinkID=160016)。

1. 将应用程序开发到想要开始进行本地化的位置。

2. 在项目文件中指定开发语言，以便 MSBuild 生成主程序集和附属程序集（具有 .resources.dll 扩展的文件）以包含非特定语言资源。 HelloApp 示例中的项目文件是 HelloApp.csproj。 在该文件中，你将找到标识如下的开发语言：

   `<UICulture>en-US</UICulture>`

3. 将 Uid 添加到你的 XAML 文件。 Uid 用于跟踪对文件的更改并标识必须翻译的项。 若要将 Uid 添加到你的文件，请运行**updateuid**上你的项目文件：

   **msbuild -t:updateuid helloapp.csproj**

   若要验证没有缺少或重复的 Uid，请运行**checkuid**:

   **msbuild -t:checkuid helloapp.csproj**

   运行之后**updateuid**，你的文件应包含 Uid。 例如，在 HelloApp 的 Pane1.xaml 文件中，你应能找到下列内容：

   `<StackPanel x:Uid="StackPanel_1">`

   `<TextBlock x:Uid="TextBlock_1">Hello World</TextBlock>`

   `<TextBlock x:Uid="TextBlock_2">Goodbye World</TextBlock>`

   `</StackPanel>`



#### 创建非特定语言资源附属程序集

将应用程序配置为生成非特定语言资源附属程序集后，则可生成应用程序。 这会生成主应用程序程序集，以及 LocBaml 本地化所需的非特定语言资源附属程序集。 若要生成应用程序：

1. 编译 HelloApp 以创建一个 动态链接库 (DLL)：

   **msbuild helloapp.csproj**

2. 新创建的主应用程序程序集 HelloApp.exe 创建在下列文件夹中：

   `C:\HelloApp\Bin\Debug\`

3. 新创建的非特定语言资源附属程序集 HelloApp.resources.dll 创建在下列文件夹中：

   `C:\HelloApp\Bin\Debug\en-US\`

#### 生成 LocBaml 工具

1. 生成 LocBaml 所需的所有文件都位于 WPF 示例中。 下载 C# 文件从[LocBaml 工具示例](https://go.microsoft.com/fwlink/?LinkID=160016)。

2. 从命令行运行项目文件 (locbaml.csproj) 来生成该工具：

   **msbuild locbaml.csproj**

3. 转到 Bin\Release 目录以查找新创建的可执行文件 (locbaml.exe)。 示例：C:\LocBaml\Bin\Release\locbaml.exe。

4. 运行 LocBaml 时可指定下列选项：

   - **分析**或 **-p:** 分析 Baml、 资源或DLL文件以生成.csv 或.txt 文件。
   - **生成**或 **-g:** 通过使用翻译的文件生成本地化的二进制文件。
   - **out**或 **-o** {*filedirectory*] **:** 输出文件的名称。
   - **区域性**或 **-cul** {*区域性*] **:** 输出程序集的区域设置。
   - **translation** or **-trans** {*translation.csv*] **:** 已翻译或本地化文件。
   - **asmpath**或 **-asmpath:** {*filedirectory*] **:** 如果你XAML代码包含自定义控件，必须提供**asmpath**对自定义控件程序集。
   - **nologo:** 显示没有徽标或版权信息。
   - **verbose:** 显示详细模式信息。

   > 如果要在运行该工具时需要的选项的列表，请键入**LocBaml.exe**然后按 ENTER。

#### 使用 LocBaml 分析文件

由于已创建 LocBaml 工具，就可使用它来分析 HelloApp.resources.dll，从而提取将进行本地化的文本内容。

1. 将 LocBaml.exe 复制到应用程序的 bin\debug 文件夹，这也是创建主应用程序程序集的位置。

2. 若要分析附属程序集文件并将输出存储为 .csv 文件，请使用下列命令：

   **LocBaml.exe /parse HelloApp.resources.dll /out:Hello.csv**

    备注

   如果输入文件 HelloApp.resources.dll 不在 LocBaml.exe 所在的同一目录中，请移动其中一个文件以使两个文件都位于同一目录中。

3. 当运行 LocBaml 来分析文件时，输出包含由逗号（.csv 文件）或制表符（.txt 文件）分隔的七个字段。 下面显示了 HelloApp.resources.dll 的已分析的 .csv 文件：

|                                                              |
| ------------------------------------------------------------ |
| HelloApp.g.en-US.resources:window1.baml,Stack1:System.Windows.Controls.StackPanel.$Content,Ignore,FALSE, FALSE,,#Text1;#Text2; |
| HelloApp.g.en-US.resources:window1.baml,Text1:System.Windows.Controls.TextBlock.$Content,None,TRUE, TRUE,,Hello World |
| HelloApp.g.en-US.resources:window1.baml,Text2:System.Windows.Controls.TextBlock.$Content,None,TRUE, TRUE,,Goodbye World |

这七个字段是：

1. **BAML 名称**。 与源语言附属程序集相关的 BAML 资源的名称。
2. **资源键**。 本地化的资源标识符。
3. **Category**。 值类型。 请参阅[本地化特性和注释](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/localization-attributes-and-comments)。
4. **Readability**。 值是否可以由本地化人员读取。 请参阅[本地化特性和注释](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/localization-attributes-and-comments)。
5. **Modifiability**。 值是否可以由本地化人员修改。 请参阅[本地化特性和注释](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/localization-attributes-and-comments)。
6. **注释**。 值的附加说明，用于确定值被本地化的方式。 请参阅[本地化特性和注释](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/localization-attributes-and-comments)。
7. **值**。 要翻译为所需区域性设置的文本值。

下表显示了这些字段映射到 .csv 文件的分隔值的方式：

| BAML 名称                               | 资源键                                             | 类别 | 可读性 | 可修改性 | 注释 | 值            |
| --------------------------------------- | -------------------------------------------------- | ---- | ------ | -------- | ---- | ------------- |
| HelloApp.g.en-US.resources:window1.baml | Stack1:System.Windows.Controls.StackPanel.$Content | 忽略 | FALSE  | FALSE    |      | #Text1;#Text2 |
| HelloApp.g.en-US.resources:window1.baml | Text1:System.Windows.Controls.TextBlock.$Content   | 无   | TRUE   | TRUE     |      | Hello World   |
| HelloApp.g.en-US.resources:window1.baml | Text2:System.Windows.Controls.TextBlock.$Content   | 无   | TRUE   | TRUE     |      | Goodbye World |

请注意，所有值**注释**字段不包含任何值; 如果字段没有值，则为空。 此外请注意第一行中的项既不可读也不可修改，并且拥有"Ignore"作为其**类别**值，这些都指示该值不可本地化。

1. 为了便于发现已分析的文件，特别是在大型文件中可本地化的项目可以进行排序或筛选的项**类别**，**可读性**，和**可修改性**. 例如，你可以筛选出不可读且不可修改的值。

#### 翻译可本地化的内容

使用任何你可用的工具翻译提取的内容。 执行此操作的一个好办法是将这些资源写入 .csv 文件，并在 Microsoft Excel 中查看它们，对最后一列（值）作出翻译更改。

#### 使用 LocBaml 生成新的 .resources.dll 文件

通过使用 LocBaml 分析 HelloApp.resources.dll 而标识的内容已被翻译，且必须合并回原始应用程序。 使用**生成**或 **-g**生成一个新的选项.resources.dll 文件。

1. 使用下列语法来生成新的 HelloApp.resources.dll 文件。 将区域性标记为 zh-CN (/cul:zh-CN)。

   **LocBaml.exe /generate HelloApp.resources.dll /trans:Hello.csv /out:c:\ /cul:en-US**

   > 如果输入文件 Hello.csv 与可执行文件 LocBaml.exe 不在的同一目录中，请移动其中一个文件以使两个文件都位于同一目录中。

2. 使用新创建的 HelloApp.resources.dll 文件替换 C:\HelloApp\Bin\Debug\en-US\HelloApp.resources.dll 目录中的旧 HelloApp.resources.dll 文件。

3. 应在你的应用程序中将“Hello World”和“Goodbye World”翻译过来。

4. 若要翻译到不同的区域性设置，请使用目标语言的区域设置。 下列示例演示了如何翻译为加拿大法语：

   **LocBaml.exe /generate HelloApp.resources.dll /trans:Hellofr-CA.csv /out:c:\ /cul:fr-CA**

5. 在主应用程序程序集所在的程序集，创建一个新的特定于区域性的文件夹，以容纳新的附属程序集。 对于加拿大法语，该文件夹将为 fr-CA。

6. 将生成的附属程序集复制到新建文件夹。

7. 若要测试新的附属程序集，你需要更改应用程序将在其下运行的区域性设置。 可以通过两种方法执行此操作：

   - 更改操作系统的区域设置 (**启动** | **控制面板** | **区域和语言选项**)。
   - 在你的应用程序中，将下列代码添加到 App.xaml.cs 中：

XAML复制

```xaml
<Application
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="SDKSample.App"
    x:Uid="Application_1"
    StartupUri="Window1.xaml">
</Application>
```

C#复制

```csharp
using System.Windows;
using System.Globalization;
using System.Threading;

namespace SDKSample
{
    public partial class App : Application
    {
        public App()
        {
            // Change culture under which this application runs
            CultureInfo ci = new CultureInfo("fr-CA");
            Thread.CurrentThread.CurrentCulture = ci;
            Thread.CurrentThread.CurrentUICulture = ci;
        }
    }
}
```

#### 使用 LocBaml 的一些提示

- 所有定义自定义控件的依赖程序集必须复制到 LocBaml 的本地目录，或安装到 GAC。 这是必要的，因为本地化 API 在读取 二进制 XAML (BAML) 时必须具有对依赖程序集的访问权限。
- 如果主程序集已签名，则生成的资源 DLL 也必须签名以进行加载。
- 本地化的资源 DLL 的版本需与主程序集进行同步。

#### 下一步

现在，你应该对如何使用 LocBaml 工具有了一个基本的了解。 你应该能够制作包含 Uid 的文件。 通过使用 LocBaml 工具，你应该能够分析文件以提取可本地化的内容，并且在内容翻译后，你应该能够生成一个合并已翻译内容的 resources.dll 文件。 本主题不包括每个可能的细节，但现在你已经掌握了使用 LocBaml 对应用程序进行本地化的必要知识。

### [Use Automatic Layout to Create a Button](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-use-automatic-layout-to-create-a-button)

本示例介绍如何使用自动布局方法在可本地化的应用程序中创建按钮。

本地化用户界面 (UI)是一个耗时的过程。 通常，本地化人员除翻译文本外，还需要重新调整元素大小并重新定位元素。 在过去每种语言的UI改编需要进行调整。 现在使用的功能Windows Presentation Foundation (WPF)可以设计减少必需的调整的元素。 种编写可以更轻松地重设大小和重新定位应用程序的方法称为`automatic layout`。

以下两个可扩展应用程序标记语言 (XAML)示例创建的应用程序实例化按钮; 一个使用英文文本，另一个使用西班牙文本。 请注意，除文本之外，代码都一样；按钮会配合文字进行调整。

#### 示例

```xaml
<Window
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="ButtonLoc.Pane1"
    Name="myWindow"
    SizeToContent="WidthAndHeight"
    >

<DockPanel> 
    <Button FontSize="28" Height="50">My name is Hope.</Button>
</DockPanel>
</Window>
```

```xaml
<Window
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="ButtonLoc.Pane1"
    Name="myWindow"
    SizeToContent="WidthAndHeight"
    >

 <DockPanel> 
    <Button FontSize="28" Height="50">Me llamo Esperanza.</Button>
  </DockPanel>
</Window>
```

下图显示代码示例的输出。

![具有不同语言的文本的同一按钮](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/globalizationbutton.png)
自动调整大小的按钮

### [Use a Grid for Automatic Layout](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-use-a-grid-for-automatic-layout)

本示例介绍如何通过自动布局方法使用网格来创建可本地化的应用程序。

本地化用户界面 (UI)是一个耗时的过程。 通常，本地化人员除翻译文本外，还需要重新调整元素大小并重新定位元素。 在过去每种语言的UI改编需要进行调整。 现在使用的功能Windows Presentation Foundation (WPF)可以设计减少必需的调整的元素。 种编写可以更方便地重设大小和重新定位的应用程序的方法称为`auto layout`。

以下可扩展应用程序标记语言 (XAML)示例演示如何使用网格来定位某些按钮和文本。 请注意，高度和宽度的单元格设置为`Auto`; 因此包含带图像按钮的单元格调整以适合图像。 因为[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素可以适应其内容时设计可本地化的应用程序采用自动布局方法非常有用。

下面的示例演示如何使用网格。

XAML复制

```xaml
<Grid Name="grid" ShowGridLines ="false">
<Grid.ColumnDefinitions>
<ColumnDefinition Width="Auto"/>
<ColumnDefinition Width="*"/>
</Grid.ColumnDefinitions>
<Grid.RowDefinitions>
<RowDefinition Height="Auto"/>
<RowDefinition Height="Auto"/>
<RowDefinition Height="Auto"/>
<RowDefinition Height="Auto"/>
<RowDefinition Height="Auto"/>
</Grid.RowDefinitions>

<TextBlock Margin="10, 10, 5, 5" Grid.Column="0" Grid.Row="0" FontSize="24">Grid
</TextBlock>
<TextBlock Margin="10, 10, 5, 5" Grid.Column="0" Grid.Row="1" FontSize="12"  
    Grid.ColumnSpan="2">The following buttons and text are positioned using a Grid.
</TextBlock>  
<Button Margin="10, 10, 5, 5" Grid.Column="0" Grid.Row="2" Background="Pink" 
    BorderBrush="Black" BorderThickness="10">Button 1
</Button>
<TextBlock Margin="10, 10, 5, 5" Grid.Column="1" Grid.Row="2" FontSize="12" 
   VerticalAlignment="Center" TextWrapping="WrapWithOverflow">Sets the background 
   color.
</TextBlock>  
<Button Margin="10, 10, 5, 5" Grid.Column="0" Grid.Row="3" Foreground="Red">
   Button 2
</Button>
<TextBlock Margin="10, 10, 5, 5" Grid.Column="1" Grid.Row="3" FontSize="12" 
   VerticalAlignment="Center" TextWrapping="WrapWithOverflow">Sets the foreground 
   color.
</TextBlock>  
<Button Margin="10, 10, 5, 5" Grid.Column="0" Grid.Row="4">
   <Image Source="data\flower.jpg"></Image>
</Button>
<TextBlock Margin="10, 10, 5, 5" Grid.Column="1" Grid.Row="4" FontSize="12" 
   VerticalAlignment="Center" TextWrapping="WrapWithOverflow">Adds an image as 
   the button's content.
</TextBlock>
</Grid>
```

下图显示了代码示例的输出。

![网格示例](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/glob-grid.png)
Grid

### [Use a ResourceDictionary to Manage Localizable String Resources](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-use-a-resourcedictionary-to-manage-localizable-string-resources)

此示例演示如何使用[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)到 Windows Presentation Foundation (WPF) 应用程序的包可本地化的字符串资源。

#### 使用 ResourceDictionary 来管理可本地化的字符串资源

1. 创建[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)，其中包含你想要本地化的字符串。 以下代码显示一个示例。

   ```xaml
   <ResourceDictionary 
     xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
     xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
     xmlns:system="clr-namespace:System;assembly=mscorlib">
     
     <!-- String resource that can be localized -->
     <system:String x:Key="localizedMessage">en-US Message</system:String>
     
   </ResourceDictionary>
   ```

   此代码定义字符串资源， `localizedMessage`，类型的[String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)，从[System](https://docs.microsoft.com/zh-cn/dotnet/api/system)mscorlib.dll 中的命名空间。

2. 添加[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)到你的应用程序，使用下面的代码。

   ```xaml
   <Application.Resources>
     <ResourceDictionary>
       <ResourceDictionary.MergedDictionaries>
         <ResourceDictionary Source="StringResources.xaml" />
       </ResourceDictionary.MergedDictionaries>
     </ResourceDictionary>
   </Application.Resources>
   ```

3. 使用字符串资源标记，使用可扩展应用程序标记语言 (XAML)类似于以下。

   ```xaml
   <!-- Declarative use of string resource from StringResources.xaml resource dictionary -->
   <TextBox DockPanel.Dock="Top" Text="{StaticResource localizedMessage}" />
   ```

4. 通过如下所示的代码来使用代码隐藏文件中的字符串资源。

   ```csharp
   // Programmatic use of string resource from StringResources.xaml resource dictionary
   string localizedMessage = (string)Application.Current.FindResource("localizedMessage");
   MessageBox.Show(localizedMessage);
   ```

5. 对应用程序进行本地化。 有关详细信息，请参阅[本地化应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-localize-an-application)。

### [Use Resources in Localizable Applications](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-use-resources-in-localizable-applications)

本地化即以适应UI到不同的区域性。 为此，必须翻译诸如标题、描述、列表框项等文本。 为简化翻译过程，要翻译的项需收集到资源文件中。 请参阅[本地化应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-localize-an-application)有关如何创建本地化的资源文件的信息。 若要使WPF应用程序可本地化，开发人员需要将内置资源程序集的所有可本地化的资源。 资源程序集已本地化为不同的语言，并隐藏代码使用资源管理API加载。 所需的文件之一WPF应用程序是项目文件 (.proj)。 应用程序中使用的所有资源都应包括在项目文件中。 下面的代码示例演示了此过程。

XAML

```
<Resource Include="data\picture1.jpg"/>
<EmbeddedResource Include="data\stringtable.en-US.restext"/>
```

若要在你的应用程序中使用的资源，实例化[ResourceManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.resources.resourcemanager)并加载你想要使用的资源。 下面的示例演示如何执行此操作。

C#复制

```csharp
void OnClick(object sender, RoutedEventArgs e)
{
  ResourceManager rm = new ResourceManager ("MySampleApp.data.stringtable",
       Assembly.GetExecutingAssembly());
  Text1.Text = rm.GetString("Message");
}
```

