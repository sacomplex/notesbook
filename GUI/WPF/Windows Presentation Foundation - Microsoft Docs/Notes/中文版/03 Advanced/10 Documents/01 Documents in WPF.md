# [Documents in WPF](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/documents-in-wpf)

Windows Presentation Foundation (WPF) 提供丰富的文档功能，可创建旨在比前几代 Windows 更易于访问和读取的高保真内容文档。 除增强功能和质量外，WPF 还对文档显示、打包和安全性能提供集成服务。 本主题介绍WPF 文档类型和文档打包。



## 文档类型

WPF 基于文档用途将文档分成两大类别；这些文档类别分别称为“固定文档”和“流文档”。

固定文档适用于需要精确的 “所见即所得”(WYSIWYG) 表示形式的应用程序，这与使用的显示器或打印机硬件无关。 固定文档的典型用途包括桌面发布、字处理和窗体布局，在这些情况下，遵循原始页面设计非常关键。 作为其布局的一部分，固定文档独立于所使用的显示或打印设备来对内容元素进行精确地定位安放。 例如，一个固定文档页面在 96 dpi 显示器上显示的效果与在 600 dpi 激光打印机或 4800 dpi 照相排字机上输出的效果是完全一样的。 虽然文档质量会根据每台设备的功能达到最优化，但是页面布局在所有情况下都保持不变。

比较而言，流文档旨在优化查看和可读性，因此，当易读性是文档的主要使用要求时，最适合使用流文档。 流文档根据运行时变量（例如，窗口大小、设备分辨率和可选的用户首选项）来动态调整和重新排列内容，而不是设置为一个预定义的布局。 网页就是流文档的一个简单示例，网页上的页面内容会动态调整格式以适应当前窗口。流文档会基于运行时环境来优化用户的查看和阅读体验。 例如，在高分辨率的 19 英寸显示器上或小型 2x3 英寸 PDA 屏幕上，同一流文档会动态调整格式以实现最佳可读性。 此外，流文档还具有很多内置功能，包括搜索、能够优化可读性的查看模式以及更改字体大小和外观的功能。 有关流文档的演示、示例和详细信息，请参阅[流文档概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/flow-document-overview)。



## 文档控件和文本布局

.NET Framework 提供了一组预建简化使用固定的文档、 流文档和您的应用程序内常规文本的控件。 使用支持固定的文档内容的显示[DocumentViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.documentviewer)控件。 流文档内容的显示由三个不同的控件支持： [FlowDocumentReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentreader)， [FlowDocumentPageViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentpageviewer)，和[FlowDocumentScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentscrollviewer)它们分别映射到不同的用户方案 （请参阅以下各节）。 其他 WPF 控件提供简化的布局以支持常规文本使用（请参阅下面的[用户界面中的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/documents-in-wpf#text_in_the_user_interface)）。

### 固定文档控件 - DocumentViewer

[DocumentViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.documentviewer)控件旨在显示[FixedDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.fixeddocument)内容。 [DocumentViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.documentviewer)控件提供了直观的用户界面，可为常见操作包括打印输出中，将复制到剪贴板、 缩放和文本搜索功能提供内置支持。 此控件通过常见的滚动机制提供对页面内容的访问。 像所有WPF控件，[DocumentViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.documentviewer)支持完整或部分重新设计，这使得控件可以直观地集成到几乎任何应用程序或环境。

[DocumentViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.documentviewer) 用于以只读方式; 显示内容编辑或修改的内容不可用和不受支持。



### 流文档概述

**注意：** 有关更多详细流文档功能以及如何创建它们的信息，请参阅[流文档概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/flow-document-overview)。

流文档内容的显示由三个控件支持： [FlowDocumentReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentreader)， [FlowDocumentPageViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentpageviewer)，和[FlowDocumentScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentscrollviewer)。

#### FlowDocumentReader

[FlowDocumentReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentreader) 包括功能，让用户能够动态选择各种查看模式，包括单页 （页--一次） 查看模式、 两个---a-次一页 （书本阅读格式） 查看模式和连续滚动 （无界限） 查看模式。 有关这些查看模式的详细信息，请参阅[FlowDocumentReaderViewingMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentreaderviewingmode)。 如果不需要进行不同查看模式之间动态切换的功能[FlowDocumentPageViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentpageviewer)和[FlowDocumentScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentscrollviewer)提供的轻量级流内容查看器中使用特定查看模式修复。

#### FlowDocumentPageViewer 和 FlowDocumentScrollViewer

[FlowDocumentPageViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentpageviewer) 显示的内容一次一页中查看模式，尽管[FlowDocumentScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentscrollviewer)以连续滚动模式显示内容。 这两[FlowDocumentPageViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentpageviewer)和[FlowDocumentScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentscrollviewer)都固定使用特定查看模式。 相比[FlowDocumentReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentreader)，包含的功能使用户能够动态选择各种查看模式 (由提供[FlowDocumentReaderViewingMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentreaderviewingmode)枚举)，但代价是多个资源占用量比[FlowDocumentPageViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentpageviewer)或[FlowDocumentScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentscrollviewer)。

默认情况下，总是显示垂直滚动条，而水平滚动条则在需要时显示。 默认值UI有关[FlowDocumentScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentscrollviewer)不包括工具栏; 但是，[IsToolBarVisible](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentscrollviewer.istoolbarvisible)属性可以用于启用内置工具栏。



### 用户界面中的文本

除可将文本添加到文档外，文本显然还可以用于应用程序 UI（如窗体）中。 WPF 包括多个用于在屏幕中绘制文本的控件。 每个控件都面向不同的方案，并具有自己的功能和限制列表。 一般情况下，[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)有限的文本支持是必需的例如中的简短句子时，应使用元素用户界面 (UI)。 [Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label) 需要最少的文本支持时，可以使用。 有关详细信息，请参阅 [TextBlock 概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/textblock-overview)。



## 文档打包

[System.IO.Packaging](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging) API提供一种有效方式组织应用程序数据、 文档内容和相关的资源的访问权限，可移植且易于分发非常简单的单个容器中。 ZIP 文件是举例说明[Package](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging.package)类型，能够作为一个单元中包含多个对象。 打包API提供默认[ZipPackage](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging.zippackage)设计一种开放打包约定标准使用 XML 和 ZIP 文件体系结构的实现。 WPF 打包 API 使得创建包以及在包内存储和访问对象变得更为简单。 中存储的对象[Package](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging.package)称为[PackagePart](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging.packagepart)（"部件"）。 包还可包括已签名的数字证书，这些证书可用于标识部件的发信方以及验证包内容是否尚未修改。 包还包括[PackageRelationship](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging.packagerelationship)允许附加信息添加到包或与特定部分关联而无需实际修改现有部件内容的功能。 包服务还支持 Microsoft Windows 权限管理 (RM)。

WPF 包体系结构用作大量关键技术的基础：

- XPS 文档符合 XML 纸张规范 (XPS)。
- Microsoft Office“12”开放式 XML 格式文档 (.docx)。
- 用于个人应用程序设计的自定义存储格式。

基于打包 Api，[XpsDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.xps.packaging.xpsdocument)专门设计用于存储WPF固定内容文档。 [XpsDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.xps.packaging.xpsdocument)是可以在查看器，显示在中打开一个自包含的文档[DocumentViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.documentviewer)控件，路由到打印后台处理，或直接输出到XPS-兼容的打印机。

以下各节提供有关的更多信息[Package](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging.package)并[XpsDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.xps.packaging.xpsdocument)API随附WPF。



### 包组件

WPF 打包 API 允许将应用程序数据和文档组织成单个可移植单元。 ZIP 文件是最常见的包类型之一，并且是 WPF附带的默认包类型。 [Package](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging.package) 本身是一个抽象类从其[ZipPackage](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging.zippackage)使用开放标准 XML 和 ZIP 文件体系结构实现的。[Open](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging.package.open)方法使用[ZipPackage](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging.zippackage)创建，默认情况下使用 ZIP 文件。 包可以包含三种基本类型的项：

|                                                              |                                         |
| ------------------------------------------------------------ | --------------------------------------- |
| [PackagePart](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging.packagepart) | 应用程序内容、数据、文档和资源文件。    |
| [PackageDigitalSignature](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging.packagedigitalsignature) | [X.509 证书] 用于标识、身份验证和验证。 |
| [PackageRelationship](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging.packagerelationship) | 与包或特定部件相关的补充信息。          |



#### PackageParts

一个[PackagePart](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging.packagepart)（"部件"） 是引用的对象存储在一个抽象类[Package](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging.package)。 在 ZIP 文件中，包的各个部件与存储在 ZIP 文件中的各个文件相对应。 [ZipPackagePart](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging.zippackagepart) 提供存储在可序列化对象的默认实现[ZipPackage](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging.zippackage)。 与文件系统类似，包中包含的部件存储在分层目录或“文件夹样式”组织中。 使用WPF打包 Api，应用程序可以写入、 存储和读取多个[PackagePart](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging.packagepart)对象使用单个 ZIP 文件容器。



#### PackageDigitalSignatures

为了安全， [PackageDigitalSignature](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging.packagedigitalsignature) （"数字签名"） 可以与软件包中的部件相关联。 一个[PackageDigitalSignature](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging.packagedigitalsignature)融合了 [509] 提供两个功能：

1. 标识部件的发信方并对其进行身份验证。
2. 验证部件是否尚未被修改。

数字签名不会阻止修改部件，但如果该部件已经以任何方式发生改变，则对该数字签名的验证检查将失败。 然后应用程序可采取适当的操作（例如，阻止打开部件，或通知用户该部件已修改，是不安全的）。



#### PackageRelationships

一个[PackageRelationship](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging.packagerelationship)（"关系"） 提供了用于将与包或包中的部件关联的其他信息的机制。 关系是一种包级别的设备，可以在未修改实际部件内容的情况下将其他信息与部件关联。 在许多情况下，直接向部件内容中插入新数据通常是不可行的：

- 部件及其内容架构的实际类型未知。
- 即使已知，内容架构可能也不会提供添加新信息的方式。
- 部件可能已进行数字签名或加密，不能进行任何修改。

包关系提供一种可检测到的方式，用于添加其他信息并将该信息与各个部件或整个包关联。 包关系具有两种主要功能：

1. 定义一个部件与另一个部件之间的依赖关系。
2. 定义添加注释或与部件相关的其他数据的信息关系。

一个[PackageRelationship](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging.packagerelationship)提供了一种快速可发现的方式来定义依赖项并添加与包或包作为一个整体的一部分关联的其他信息。



##### 依赖关系

依赖关系用于描述一个部件对其他部件的依赖性。 例如，一个包可能包含一个 HTML 部件，该部件包括一个或多个 <img> 图像标记。 此图像标记指的是作为包的其他内部部件或外部部件（可通过 Internet 访问）定位的图像。 创建[PackageRelationship](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging.packagerelationship)与 HTML 文件可以使查找和访问从属资源快速而简单。 浏览器或查看器应用程序可以直接访问部件关系，并在无需了解架构或未分析文档的情况下立即开始汇编从属资源。



##### 信息关系

类似于注释或批注，[PackageRelationship](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging.packagerelationship)还可以用于存储其他类型的信息，而无需实际修改部件内容本身是与部件关联。



## XPS 文档

XML 纸张规范 (XPS) 文档是一个包，其中包含一个或多个固定文档以及呈现操作所需的所有资源和信息。 XPS 还是 Windows Vista 的本机后台打印文件格式。 [XpsDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.xps.packaging.xpsdocument)存储在标准 ZIP 数据集中，并且可以包括 XML 和二进制组件，如图像和字体文件的组合。 [PackageRelationships](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/documents-in-wpf#PackageRelationships) 用于定义内容和完全呈现文档所需的资源之间的依赖关系。 [XpsDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.xps.packaging.xpsdocument)设计提供单一的、 高保真文档解决方案，可支持多个用途：

- 将固定文档内容和资源读取、写入和存储为单个可移植且易于分发的文件。
- 利用 XPS 查看器应用程序显示文档。
- 以 Windows Vista 的本机打印后台输出格式输出文档。
- 将文档直接路由到与 XPS 兼容的打印机。