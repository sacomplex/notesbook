# [Performance](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/performance)

实现最佳应用程序性能需要在应用程序设计和了解的最佳做法更具前瞻性Windows Presentation Foundation (WPF)应用程序开发。 在本部分中的主题提供有关构建高性能的其他信息WPF应用程序。

[图形呈现层](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/graphics-rendering-tiers)
[优化 WPF 应用程序性能](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/optimizing-wpf-application-performance)
[演练：缓存在 WPF 应用程序的应用程序数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/walkthrough-caching-application-data-in-a-wpf-application)

## [Graphics Rendering Tiers](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/graphics-rendering-tiers)

呈现层为运行 WPF 应用程序的设备定义图形硬件功能和性能级别。

### 图形硬件

对呈现层级别影响最大的图形硬件功能包括：

- **视频 RAM** - 图形硬件中的视频内存量决定了可用于合成图形的缓冲区大小和数量。
- **像素着色器** - 像素着色器是基于像素计算效果的图形处理功能。 每个显示帧可能有数百万像素需要处理，具体取决于显示图形的分辨率。
- **顶点着色器** - 顶点着色器是对对象的顶点数据执行数学运算的图形处理功能。
- **多纹理支持** - 多纹理支持是指对 3D 图形对象执行混合操作期间应用两个或更多个不同纹理的功能。 多纹理支持的程度取决于图形硬件中的多纹理单元数。

### 呈现层定义

图形硬件的功能决定了 WPF 应用程序的呈现功能。 WPF 系统定义了 3 个呈现层：

- **呈现层 0** - 无图形硬件加速。 所有图形功能都使用软件加速。 DirectX 版本级别低于 9.0。
- **呈现层 1** - 某些图形功能使用图形硬件加速。 DirectX 版本级别高于或等于 9.0。
- **呈现层 2** - 大多数图形功能都使用图形硬件加速。 DirectX 版本级别高于或等于 9.0。

[RenderCapability.Tier](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rendercapability.tier)属性允许您检索在应用程序运行时的呈现层。 使用呈现层可确定设备是否支持某些硬件加速图形功能。 然后，应用程序就可以在运行时根据设备支持的呈现层采用不同的代码路径。

#### 呈现层 0

呈现层的值为 0 意味着设备上的应用程序没有图形硬件加速可用。 在这一层次级别，应假设所有图形都由软件呈现，未采用硬件加速。 该层的功能对应于低于 9.0 的 DirectX 版本。

#### 呈现层 1 与呈现层 2

> 从 .NET Framework 4 开始，呈现层 1 进行了重新定义，只包含支持 DirectX 9.0 或更高版本的图形硬件。 支持 DirectX 7 或 8 的图形硬件现定义为呈现层 0。

呈现层的值为 1 或 2 意味着，如果必要的系统资源可用并且尚未耗尽，则 WPF 的大部分图形功能会使用硬件加速。 这对应于高于或等于 9.0 的 DirectX 版本。

下表显示呈现层 1 和呈现层 2 的图形硬件需求差异：

| 功能         | 层 1                         | 层 2                         |
| ------------ | ---------------------------- | ---------------------------- |
| DirectX 版本 | 必须高于或等于 9.0。         | 必须高于或等于 9.0。         |
| 视频 RAM     | 必须大于或等于 60 MB。       | 必须大于或等于 120 MB。      |
| 像素着色器   | 版本级别必须高于或等于 2.0。 | 版本级别必须高于或等于 2.0。 |
| 顶点着色器   | 没有要求。                   | 版本级别必须高于或等于 2.0。 |
| 多纹理单元   | 没有要求。                   | 单元数必须大于或等于 4。     |

以下功能对呈现层 1 和呈现层 2 采用硬件加速：

| 功能            | 说明                                                         |
| --------------- | ------------------------------------------------------------ |
| 2D 呈现         | 支持大多数 2D 呈现。                                         |
| 3D 光栅化       | 支持大多数 3D 光栅化。                                       |
| 3D 各向异性筛选 | WPF 在呈现 3D 内容时尝试使用各向异性筛选。 各向异性筛选是指改善离相机较远且与相机角度较大的图面上纹理的图像质量。 |
| 3D MIP 映射     | WPF 在呈现 3D 内容时尝试使用 MIP 映射。 MIP 映射可改进纹理呈现的质量，当纹理占用较小的视野[Viewport3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewport3d)。 |
| 径向渐变        | 虽然支持，但应避免使用[RadialGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.radialgradientbrush)大型对象。 |
| 3D 光照计算     | WPF 执行每个顶点的光照，这意味着必须在应用于网格的每个材料的每个顶点计算光照强度。 |
| 文本呈现        | 子像素字体呈现使用图形硬件上可用的像素着色器。               |

以下功能仅对呈现层 2 采用硬件加速：

| 功能      | 说明                                                         |
| --------- | ------------------------------------------------------------ |
| 3D 抗锯齿 | 只有支持 Windows 显示驱动程序模型 (WDDM) 的操作系统（如 Windows Vista 和 Windows 7）才支持 3D 抗锯齿。 |

以下功能**未**采用硬件加速：

| 功能                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| 打印内容                                                     | 所有打印内容都使用 WPF 软件管道呈现。                        |
| 使用的光栅化内容 [RenderTargetBitmap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.rendertargetbitmap) | 通过使用呈现任何内容[Render](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.rendertargetbitmap.render)方法的[RenderTargetBitmap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.rendertargetbitmap)。 |
| 使用的平铺的内容 [TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush) | 在其中的内容的任何平铺[TileMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.tilemode)的属性[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)设置为[Tile](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilemode#System_Windows_Media_TileMode_Tile)。 |
| 超过图形硬件最大纹理大小的图面                               | 对大多数图形硬件而言，大型图面是指达到 2048x2048 或 4096x4096 像素大小的图面。 |
| 视频 RAM 要求超过图形硬件内存的任何操作                      | 可使用 Windows SDK 中的 [WPF 性能套件](https://msdn.microsoft.com/library/67cafaad-57ad-4ecb-9c08-57fac144393e)包含的分析器工具来监视应用程序视频 RAM 的使用情况。 |
| 分层窗口                                                     | 分层窗口允许 WPF 应用程序将内容呈现到非矩形窗口中的屏幕。 在支持 Windows 显示驱动程序模型 (WDDM) 的操作系统（如 Windows Vista 和 Windows 7）上，分层窗口采用硬件加速。 在 Windows XP 等其他系统上，分层窗口是通过软件来呈现的，未采用硬件加速。  可以启用分层的窗口中WPF通过设置以下[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)属性：  - [WindowStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.windowstyle) = [None](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.windowstyle#System_Windows_WindowStyle_None) - [AllowsTransparency](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.allowstransparency) = `true` - [Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background) = [Transparent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brushes.transparent) |

### 其他资源

以下资源可帮助你分析 WPF 应用程序的性能特征。

#### 图形呈现注册表设置

WPF 提供了 4 个注册表设置来控制 WPF 呈现：

| 设置                           | 描述                                                         |
| ------------------------------ | ------------------------------------------------------------ |
| **禁用硬件加速选项**           | 指定是否应启用硬件加速。                                     |
| **最大多重采样值**             | 指定用于消除 三维 内容锯齿的多重采样级别。                   |
| **必需的视频驱动程序日期设置** | 指定系统是否对 2004 年 11 月之前发布的驱动程序禁用硬件加速。 |
| **使用参考光栅器选项**         | 指定 WPF 是否应使用参考光栅器。                              |

知道如何引用 WPF 注册表设置的任何外部配置实用工具都可以访问这些设置。 还可以直接使用 Windows 注册表编辑器来访问这些值，从而创建或修改这些设置。 有关详细信息，请参阅[图形呈现注册表设置](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/graphics-rendering-registry-settings)。

#### WPF 性能分析工具

WPF 提供了一套性能分析工具，此工具可帮助分析应用程序的运行时行为，并确定可应用的性能优化类型。 下表列出了 Windows SDK 工具中包括的性能分析工具，WPF 性能套件：

| 工具         | 描述                                                         |
| ------------ | ------------------------------------------------------------ |
| 分析器       | 用于分析呈现行为。                                           |
| 可视化探查器 | 用于按可视化树中的元素分析 WPF 服务（如布局和事件处理）的使用。 |

WPF 性能套件提供丰富的性能数据的图形视图。 有关 WPF 性能工具的详细信息，请参阅 [WPF 性能套件](https://msdn.microsoft.com/library/67cafaad-57ad-4ecb-9c08-57fac144393e)。

#### DirectX 诊断工具

DirectX 诊断工具 Dxdiag.exe 旨在帮助你解决与 DirectX 有关的问题。 DirectX 诊断工具的默认安装文件夹是：

```
~\Windows\System32
```

运行 DirectX 诊断工具时，主窗口中包含一组可用于显示和诊断 DirectX 相关信息的选项卡。 例如，“系统”选项卡提供有关计算机的系统信息，并指定安装在计算机上的 DirectX 版本。

![屏幕快照：DirectX 诊断工具](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/directxdiagnostictool-01.png)
“DirectX 诊断工具”主窗口

## [Optimizing WPF Application Performance](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/optimizing-wpf-application-performance)

本部分旨在作为参考Windows Presentation Foundation (WPF)应用程序开发人员正在寻找方法来提高他们的应用程序的性能。 如果你是开发人员是 Microsoft.NET Framework 中新增和WPF，您应该首先熟悉这两个平台。 本部分假定这两种知识并专为编程人员已经知道足以让他们的应用程序启动并运行。

> 在本部分中提供的性能数据基于WPFRAM 和 ATI Radeon 9700，2.8 GHz PC 上使用 512 运行的应用程序的图形卡。

[规划应用程序性能](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/planning-for-application-performance)

[利用硬件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/optimizing-performance-taking-advantage-of-hardware)

[布局和示例](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/optimizing-performance-layout-and-design)

[2D 图形和图像处理](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/optimizing-performance-2d-graphics-and-imaging)

[对象行为](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/optimizing-performance-object-behavior)

[应用程序资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/optimizing-performance-application-resources)

[文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/optimizing-performance-text)

[数据绑定](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/optimizing-performance-data-binding)

[控件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/optimizing-performance-controls)

[其他性能建议](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/optimizing-performance-other-recommendations)

[应用程序启动时间](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/application-startup-time)

### [Planning for Application Performance](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/planning-for-application-performance)

实现性能目标的成功取决于如何开发您性能的策略。 规划是在开发的任何产品的第一个阶段。 本主题介绍一些非常简单规则可用于开发良好的性能策略。

#### 方案会想到

方案可帮助你专注于你的应用程序的关键组件。 方案通常派生自你的客户，以及竞争对手的产品。 始终研究你的客户，并找出真正让他们高兴您的产品和竞争对手的产品。 客户的反馈可以帮助您确定应用程序的主要方案。例如，如果您要设计一个组件，将使用在启动时，很可能，在应用程序启动时只有一次调用该组件。 启动时间将成为你的密钥方案。 关键方案的其他示例可能是所需的帧速率对于动画序列，或最大工作集允许的应用程序。

#### 定义目标

目标可帮助您确定应用程序的性能加快或减慢。 应为每个方案定义目标。 您定义的所有性能目标应都基于客户的预期。 它可能很难制定性能在早期目标应用程序开发周期，仍有很多未解决的问题。 但是，最好设置一个初始目标和更高版本而不是将一个目标根本修改。

#### 了解你的平台

始终保持度量、 调查、 在应用程序开发周期中简化/更正的周期。 从开始到开发周期结束时，需要可靠、 稳定的环境中的应用程序的性能进行测量。 应避免通过外部因素造成的变化。 例如，测试性能时，应禁用防病毒软件或任何自动更新功能 （如 SMS)，顺序不会对性能造成影响的测试结果。 你已经度量出应用程序的性能，需要标识将导致最大的改进的更改。 一次修改了你的应用程序，再次启动该周期。

#### 进行性能优化一个迭代过程

您应该知道将使用每个功能的相对成本。 例如，Microsoft.NET Framework 中对反射的使用通常是占用大量的计算资源，因此要明智地使用它。 这并不意味着若要避免使用反射，仅，你应该注意平衡应用程序的性能要求，你使用的功能的性能要求。

#### 生成大量图形的内容

创建对实现可缩放方法的一项关键技术WPF应用程序的性能是构建出图形的丰富性和复杂性。 始终使用最少的性能密集型资源来实现您的方案的目标开始。 后实现这些目标，请使用更多性能密集型功能，始终记住你方案的目标构建出图形丰富功能。 请记住，WPF是一个非常丰富的平台，提供了非常丰富的图形功能。 使用无需多想性能密集型功能可以对应用程序总体性能产生负面影响。

WPF 控件是本质上是可扩展的从而对广泛自定义其外观，而不修改其控件行为。 通过利用样式、 数据模板和控件模板，可以创建并以增量方式发展可自定义用户界面 (UI)的适应你的性能要求。

### [Taking Advantage of Hardware](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/optimizing-performance-taking-advantage-of-hardware)

内部体系结构WPF具有两个呈现管道、 硬件和软件。 本主题提供有关这些呈现管道，以帮助你做出有关您的应用程序的性能优化的信息。

#### 硬件呈现管道

在确定的最重要因素之一WPF性能是它是呈现绑定 — 必须要呈现，成本更高性能的像素越多。 但是，呈现的详细信息可以卸载到图形处理单元 (GPU)，可以获得更多的性能优势。 WPF应用程序的硬件呈现管道采用充分利用Microsoft DirectX功能支持的最少的硬件上Microsoft DirectX版本 7.0。 支持的硬件可以获得更多优化Microsoft DirectX版本 7.0 和 PixelShader 2.0 + 功能。

#### 软件呈现管道

WPF软件呈现管道是完全受 CPU 限制。 WPF 充分利用 SSE 和 SSE2 指令的设置在 CPU 中来实现优化、 功能完备的软件光栅器。 回退到软件是无缝应用程序功能不能使用硬件呈现管道呈现任何时间。

您会遇到的最大的性能问题时在软件模式下呈现相关填充率，定义为呈现的像素数。 如果担心软件呈现模式中的性能，尝试尽量减少重新绘制像素的次数。 例如，如果您的应用程序包含一个蓝色背景，然后通过它呈现略有透明图像，您将呈现所有两次，应用程序中的像素。 因此，它将需要两次长呈现具有比有仅蓝色背景图像的应用程序。

##### 图形呈现层

它可能很难预测你的应用程序将在运行的硬件配置。 但是，你可能想要考虑使用允许无缝切换功能在不同的硬件上运行时，以便它可以充分利用每个不同的硬件配置的应用程序的设计。

若要实现此目的，WPF提供功能，以确定在运行时中的系统的图形功能。 分类为一个三个呈现功能层的视频卡取决于图形功能。 WPF 公开API允许应用程序在查询的呈现功能层。 然后，你的应用程序可以在运行的时间，具体取决于硬件支持的呈现层采用不同的代码路径。

对呈现层级别影响最大的图形硬件功能包括：

- **视频 RAM** - 图形硬件中的视频内存量决定了可用于合成图形的缓冲区大小和数量。
- **像素着色器** - 像素着色器是基于像素计算效果的图形处理功能。 每个显示帧可能有数百万像素需要处理，具体取决于显示图形的分辨率。
- **顶点着色器** - 顶点着色器是对对象的顶点数据执行数学运算的图形处理功能。
- **多纹理支持** - 多纹理支持是指对 3D 图形对象执行混合操作期间应用两个或更多个不同纹理的功能。 多纹理支持的程度取决于图形硬件中的多纹理单元数。

像素着色器、 顶点着色器和多纹理功能用于定义特定DirectX版本级别，这反过来，用于定义中的不同的呈现层WPF。

图形硬件的功能决定了 WPF 应用程序的呈现功能。 WPF 系统定义了 3 个呈现层：

- **呈现层 0** - 无图形硬件加速。 DirectX版本级别低于 7.0 版。
- **呈现层 1**部分的图形硬件加速。 DirectX版本级别为大于或等于版本 7.0，并**较小**比 9.0 版。
- **呈现层 2** - 大多数图形功能都使用图形硬件加速。 DirectX 版本级别高于或等于 9.0。

有关详细信息WPF呈现层，请参阅[图形呈现层](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/graphics-rendering-tiers)。

### [Layout and Design](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/optimizing-performance-layout-and-design)

WPF 应用程序的设计在计算布局和验证对象引用时会产生不必要的开销，从而影响性能。 对象的构造会影响应用程序的性能特征，在运行时更是如此。

本主题提供这些方面的性能改进建议。

#### 布局

"布局处理过程"一词描述测量和排列的成员的过程[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)-派生的子级，并在其中绘制它们在屏幕上的对象的集合。 布局处理过程是一个数学密集型过程，即：集合中的子级数目越多，所需的计算量就越大。 例如，每次子[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)集合中的对象改变其位置，它可能触发一个新的布局系统传递。 由于对象特征与布局行为之间的关系非常紧密，因此有必要了解可以调用布局系统的事件类型。 应用程序将尽可能减少不必要的布局处理过程调用，从而改善性能。

布局系统对集合中的每个子成员都完成两个处理过程：测量处理过程和排列处理过程。 每个子对象提供了自己的重写的实现[Measure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.measure)和[Arrange](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.arrange)方法中，以便提供其自己特定的布局行为。 简单地说，布局是一个递归系统，实现在屏幕上对元素进行大小调整、定位和绘制。

- 子[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)对象通过首先测量其核心属性来开始布局过程。
- 对象的[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)属性与大小，如[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)， [Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)，和[Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)，进行计算。
- [Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)-应用特定的逻辑，如[Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.dock)的属性[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)，或[Orientation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel.orientation)属性的[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)。
- 在测量所有的子对象后，将排列或定位内容。
- 将子对象集合绘制到屏幕上。

如果发生下列任一操作，将再次调用布局处理过程：

- 向集合中添加了一个子对象。
- 一个[LayoutTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.layouttransform)应用到子对象。
- [UpdateLayout](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.updatelayout)为子对象调用方法。
- 使用影响测量或排列过程的元数据进行标记的依赖属性的值发生更改时。

##### 尽可能使用最高效的面板

布局过程的复杂性直接取决于的布局行为[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)-派生您使用的元素。 例如，[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)或[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)控件提供了更多的功能比[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)控件。 功能大幅度改进的代价是性能成本的大幅度提高。 但是，如果您不需要的功能，[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)控件提供了应使用成本较低的替代方法，如[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)或自定义面板。

有关详细信息，请参阅[面板概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/panels-overview)。

##### 更新而不替换 RenderTransform

您可能无法在更新[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transform)而不是替换的值作为[RenderTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransform)属性。 在涉及动画的方案中，尤其是这样。 通过更新现有[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transform)，可以避免启动不需要的布局计算。

##### 从上到下生成树

在逻辑树中添加或删除节点时，会在该节点的父级及其所有子级上引起属性失效。 因此，应始终遵循从上到下的构造模式，以避免由于在经过验证的节点中出现不必要的失效而付出代价。 下表显示了执行速度之间构建树自上而下与自下而上，其中树有 150 级深与单个差异[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)和[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)每个级别。

| **操作** | **构建树（以毫秒为单位）** | **呈现 - 包括生成树（以毫秒为单位）** |
| -------- | -------------------------- | ------------------------------------- |
| 从下到上 | 366                        | 454                                   |
| 从上到下 | 11                         | 96                                    |

以下代码示例演示如何从上到下创建树。

```csharp
private void OnBuildTreeTopDown(object sender, RoutedEventArgs e)
{
    TextBlock textBlock = new TextBlock();
    textBlock.Text = "Default";

    DockPanel parentPanel = new DockPanel();
    DockPanel childPanel;

    myCanvas.Children.Add(parentPanel);
    myCanvas.Children.Add(textBlock);

    for (int i = 0; i < 150; i++)
    {
        textBlock = new TextBlock();
        textBlock.Text = "Default";
        parentPanel.Children.Add(textBlock);

        childPanel = new DockPanel();
        parentPanel.Children.Add(childPanel);
        parentPanel = childPanel;
    }
}
```

有关逻辑树的详细信息，请参阅 [WPF 中的树](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/trees-in-wpf)。

### [2D Graphics and Imaging](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/optimizing-performance-2d-graphics-and-imaging)

WPF 提供了多种可按应用程序要求进行优化的二维图形和图像处理功能。 本主题提供有关这些方面性能优化的信息。

#### 绘图和形状

WPF 提供了[Drawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawing)和[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)对象来表示图形绘制内容。 但是，[Drawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawing)对象是相比更为简单的构造[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)对象，并提供更好的性能特征。

一个[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)，可将图形形状绘制到屏幕。 因为派生自[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)类，[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)对象可以用在面板和多数控件。

WPF 为图形和绘制服务提供多层访问。 在顶层，[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)对象是易于使用和提供许多有用的功能，如布局和事件处理。 WPF 提供了许多现成可用的形状对象。 所有形状对象都继承自[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)类。 可用形状对象包括[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)，[Line](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.line)， [Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)， [Polygon](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.polygon)， [Polyline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.polyline)，并[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)。

[Drawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawing) 对象，但是，并非派生[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)类，并提供用于呈现形状、 图像和文本的轻量实现。

有四种类型的[Drawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawing)对象：

- [GeometryDrawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometrydrawing) 绘制形状。
- [ImageDrawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagedrawing) 绘制图像。
- [GlyphRunDrawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.glyphrundrawing) 绘制文本。
- [DrawingGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawinggroup) 绘制其他绘图。 使用图形组将其他图形合并到单个复合图形。

[GeometryDrawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometrydrawing)对象用于绘制几何内容。 [Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)类和具体类派生，如[CombinedGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.combinedgeometry)， [EllipseGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.ellipsegeometry)，和[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)、 用于呈现二维图形提供一种方式，以及提供命中测试和剪裁支持。 几何对象可用于定义控件的区域或定义应用于图像的剪裁区域等。 几何对象可以是简单区域（例如矩形和圆形），或者是由两个或多个几何对象创建的复合区域。 可以通过组合创建更复杂的几何区域[PathSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathsegment)的派生的对象，如[ArcSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.arcsegment)， [BezierSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.beziersegment)，和[QuadraticBezierSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.quadraticbeziersegment)。

表面上看，[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)类和[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)类是非常相似。 二者都用于绘制 2D 图形和都具有相似的具体类派生，例如，[EllipseGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.ellipsegeometry)和[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)。 但是，这两个类集之间存在重大区别。 对于其中一个，[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)类所缺少的功能的一些[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)类，例如绘制自身的功能。 若要绘制几何对象，必须使用另一个类（例如 DrawingContext、Drawing 或 Path（值得注意的是 Path 是一个 Shape））来执行绘制操作。 填充、笔划和笔划粗细等绘制属性位于绘制几何对象的类上，而形状对象中包含这些属性。 可以这样来理解这种差别：几何对象定义区域（例如圆形），而形状对象定义区域、定义如何填充区域和设置区域边框并参与布局系统。

由于[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)对象派生自[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)类，使用它们可以在你的应用程序中添加内存消耗显著增加。 如果您确实不需要[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)功能对于图形内容，请考虑使用轻量[Drawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawing)对象。

有关详细信息[Drawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawing)对象，请参阅[Drawing 对象概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/drawing-objects-overview)。

#### StreamGeometry 对象

[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)对象是的轻型替代方法[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)对于创建几何形状。 使用[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)何时需要描述复杂几何。 [StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry) 用于处理多个优化[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)对象，并执行更好地与使用多个独立相比[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)对象。

下面的示例使用特性语法创建一个三角形[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)在XAML。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
  <StackPanel>
  
    <Path Data="F0 M10,100 L100,100 100,50Z" 
      StrokeThickness="1" Stroke="Black"/>

  </StackPanel>
</Page>
```

有关详细信息[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)对象，请参阅[形状使用 StreamGeometry 创建](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-shape-using-a-streamgeometry)。

#### DrawingVisual 对象

[DrawingVisual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingvisual)对象是一个轻量绘图类，用于呈现形状、 图像或文本。 此类之所以为轻量类是因为它不提供布局或事件处理，从而性能得以提升。 因此，绘图非常适用于背景和剪贴画。 有关详细信息，请参阅[使用 DrawingVisual 对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/using-drawingvisual-objects)。

#### 图像

WPF 图像处理对 Windows 先前版本的图像处理功能进行了极大改进。 显示位图或在公共控件上使用图像等图像处理功能以前主要由 Microsoft Windows 图形设备接口 (GDI) 或Microsoft Windows GDI+ 应用程序编程接口 (API) 处理。 这些 API 提供基线图像处理功能，但缺少编解码器扩展性支持和高保真图像支持等功能。 WPF 图像处理 API 已经过重新设计，克服了 GDI 和 GDI+ 的缺点，提供新的 API 集以在应用程序内显示和使用图像。

使用图像时，为使性能更佳，请考虑以下建议：

- 如果应用程序要求显示缩略图，请考虑创建一个缩略版图像。 默认情况下，WPF 会加载图像并将其解码到最大尺寸。 如果仅需要缩略版本图像，WPF 会先将图像解码为完整尺寸，然后将其缩放为缩略图大小，这个过程是多余的。 若要避免此多余的过程，可请求 WPF 将图像解码到缩略图大小，或者请求 WPF 加载缩略图大小的图像。
- 请务必将图像解码到所需大小而不是默认大小。 如上所述，请求 WPF 将图像解码为所需大小而不是默认的最大尺寸。 这样不仅会减小应用程序的工作集，还会减慢其执行速度。
- 如果可能，请将多个图像合并到单个图像中，例如由多个图像构成的胶卷条。
- 有关详细信息，请参阅 [图像概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/imaging-overview)。

##### BitmapScalingMode

对任何位图缩放进行动画处理时，默认高质量图像重采样算法有时可能由于消耗过多系统资源导致帧速率下降，从而导致动画明显变慢。 通过设置[BitmapScalingMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.renderoptions.bitmapscalingmode)的属性[RenderOptions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.renderoptions)对象传递给[LowQuality](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.bitmapscalingmode#System_Windows_Media_BitmapScalingMode_LowQuality)缩放位图时，可以创建更为流畅的动画。 [LowQuality](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.bitmapscalingmode#System_Windows_Media_BitmapScalingMode_LowQuality) 模式告知WPF呈现引擎处理图像时从质量优化算法切换到速度优化算法。

下面的示例演示如何设置[BitmapScalingMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.bitmapscalingmode)图像对象。

```csharp
// Set the bitmap scaling mode for the image to render faster.
RenderOptions.SetBitmapScalingMode(MyImage, BitmapScalingMode.LowQuality);
```

##### CachingHint

默认情况下WPF不会缓存的已呈现的内容[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)对象，如[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)和[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)。 在静态方案中的内容和使用都不[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)中更改场景中，这是有意义，因为这可节省视频内存。 如得意义时不会使[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)中的非静态方法使用具有静态内容-例如，当一个静态[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)或[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)映射到旋转 3D 对象的图面。 默认行为WPF重新呈现内容的整个[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)或[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)对于每个框架，即使内容是不变。

通过设置[CachingHint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.renderoptions.cachinghint)的属性[RenderOptions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.renderoptions)对象传递给[Cache](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.cachinghint#System_Windows_Media_CachingHint_Cache)可以通过使用缓存的版平铺的画笔对象提高性能。

[CacheInvalidationThresholdMinimum](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.renderoptions.cacheinvalidationthresholdminimum)并[CacheInvalidationThresholdMaximum](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.renderoptions.cacheinvalidationthresholdmaximum)属性值是相对大小值，确定何时[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)应更改而重新生成对象。 例如，通过设置[CacheInvalidationThresholdMaximum](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.renderoptions.cacheinvalidationthresholdmaximum)属性设置为 2.0 中，为缓存[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)仅需要其大小超过当前缓存的大小的两倍时重新生成。

下面的示例演示如何使用缓存提示选项用于[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)。

```csharp
DrawingBrush drawingBrush = new DrawingBrush();
            
// Set the caching hint option for the brush.
RenderOptions.SetCachingHint(drawingBrush, CachingHint.Cache);

// Set the minimum and maximum relative sizes for regenerating the tiled brush.
// The tiled brush will be regenerated and re-cached when its size is
// 0.5x or 2x of the current cached size.
RenderOptions.SetCacheInvalidationThresholdMinimum(drawingBrush, 0.5);
RenderOptions.SetCacheInvalidationThresholdMaximum(drawingBrush, 2.0);
```

### [Object Behavior](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/optimizing-performance-object-behavior)

了解 WPF 对象的内部行为，有助于在功能和性能之间做出适当的取舍。

#### 不删除对象的事件处理程序可能会使对象保持活动状态

对象传递给其事件的委托是对该对象的有效引用。 因此，事件处理程序可以使对象保持活动状态的时间超过预期时间。 当对已注册为侦听对象事件的对象执行清理时，在释放对象前删除委托是非常必要的。 将不需要的对象保持为活动状态会增加应用程序的内存使用量。 在对象为逻辑树或可视化树的根时更是如此。

WPF 为事件引入了弱事件侦听器模式，在很难跟踪源和侦听器之间的对象生存期关系时，这种模式特别有用。某些现有 WPF 事件使用此模式。 如果要实现具有自定义事件的对象，此模式可能会有用。 有关详细信息，请参阅[弱事件模式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/weak-event-patterns)。

有若干工具（如 CLR 探查器和工作集查看器）可以提供有关指定进程的内存使用量的信息。 CLR 探查器包括分配配置文件的许多非常有用的视图，其中包括已分配类型的直方图、分配和调用关系图、显示各代垃圾回收及上述回收之后托管堆的生成状态的时间线，以及显示每个方法分配和程序集加载的调用树。 有关详细信息，请参阅[.NET Framework 开发人员中心](https://go.microsoft.com/fwlink/?LinkId=117435)。

#### 依赖属性和对象

一般情况下，访问的依赖属性[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)不是比访问速度较慢CLR属性。 虽然设置属性值会产生一些小的性能开销，但是获取值与从 CLR 属性获取值的速度一样快。 抵销一些小的性能开销是因为依赖属性支持可靠的功能，如数据绑定、动画、继承和样式设置。 有关详细信息，请参阅[依赖项属性概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-properties-overview)。

##### DependencyProperty 优化

在应用程序中定义依赖属性时请务必谨慎。 如果你[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)仅影响呈现类型元数据选项，而不是其他元数据选项如[AffectsMeasure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata.affectsmeasure)，您应将其标记这种情况下通过重写其元数据。 有关替代或获取属性元数据的详细信息，请参阅[依赖属性元数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-metadata)。

如果并非所有属性更改都会影响测量、排列和呈现，则通过属性更改处理程序手动使测量、排列和呈现阶段无效的做法可能会更高效。 例如，你可能决定仅在值大于设置限制时才重新呈现背景。 在这种情况下，值超过设置限制时，属性更改处理程序仅会使呈现无效。

##### 将 DependencyProperty 设置为可继承会影响性能

默认情况下，注册的依赖属性是不可继承的。 但可以显式地将所有属性设置为可继承。 尽管这是一个有用的功能，但是将属性转换为可继承会影响性能，因为会增加属性无效的时长。

##### 谨慎使用 RegisterClassHandler

虽然通过调用[RegisterClassHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventmanager.registerclasshandler)允许您保存实例状态，它是必须要注意，每个实例，这可能导致性能问题上调用该处理程序。 只能使用[RegisterClassHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventmanager.registerclasshandler)应用程序要求保存实例状态。

##### 在注册过程中为 DependencyProperty 设置默认值

创建时[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)要求默认值，将使用作为参数传递的默认元数据值设置[Register](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.register)方法的[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)。 请使用此技术，而不要在构造函数中或在元素的每个实例上设置属性值。

##### 使用 Register 设置 PropertyMetadata 值

创建时[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)，您可以设置[PropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata)使用[Register](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.register)或[OverrideMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.overridemetadata)方法。 尽管对象可能有一个静态构造函数来调用[OverrideMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.overridemetadata)，这不是最佳解决方案，将会影响性能。 为了获得最佳性能，设置[PropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertymetadata)在调用[Register](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.register)。

#### Freezable 对象

一个[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)是一种特殊的对象，它有两种状态： 解冻和冻结。 尽可能冻结对象会改进应用程序性能，并缩小其工作集。 有关详细信息，请参阅 [Freezable 对象概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/freezable-objects-overview)。

每个[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)具有[Changed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.changed)发生更改时引发的事件。 不过，更改通知会降低应用程序的性能。

请考虑下面的示例，其中，每个[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)使用相同[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)对象：

```csharp
rectangle_1.Fill = myBrush;
rectangle_2.Fill = myBrush;
rectangle_3.Fill = myBrush;
// ...
rectangle_10.Fill = myBrush;
```

默认情况下WPF提供的事件处理程序[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)对象的[Changed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.changed)事件，以使之无效[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)对象的[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)属性。 在这种情况下，每次[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)不得不引发其[Changed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.changed)事件时，必须为每个调用的回调函数[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)— 这些回叫函数调用的累积会施加对显著的性能产生负面影响。 此外，此时添加和删除处理程序将会严重影响性能，这是因为应用程序将不得不遍历整个列表才能执行此操作。 如果你的应用程序方案从未更改[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)，您将付款的维护成本[Changed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.changed)事件处理程序不必要地。

冻结[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)可以提高其性能，因为它不再需要付出因维护更改通知的资源。 下表显示了一个简单的大小[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)时其[IsFrozen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.isfrozen)属性设置为`true`、 相对于它不是。 这将假定应用一个画笔应用于[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)10 个属性[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)对象。

| **状态**                                                     | **Size** |
| ------------------------------------------------------------ | -------- |
| 冻结 [SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush) | 212 字节 |
| 非冻结 [SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush) | 972 字节 |

以下代码示例演示了此概念：

C#复制

```csharp
Brush frozenBrush = new SolidColorBrush(Colors.Blue);
frozenBrush.Freeze();
Brush nonFrozenBrush = new SolidColorBrush(Colors.Blue);

for (int i = 0; i < 10; i++)
{
    // Create a Rectangle using a non-frozed Brush.
    Rectangle rectangleNonFrozen = new Rectangle();
    rectangleNonFrozen.Fill = nonFrozenBrush;

    // Create a Rectangle using a frozed Brush.
    Rectangle rectangleFrozen = new Rectangle();
    rectangleFrozen.Fill = frozenBrush;
}
```

##### 解冻的可冻结对象的已更改处理程序可以使对象保持活动状态

委托对象传递到[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)对象的[Changed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.changed)事件实际上是对该对象的引用。 因此，[Changed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.changed)事件处理程序可以使对象保持活动状态时间超过预期时间。 当正在执行清除的对象的已注册为侦听[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)对象的[Changed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.changed)事件，很重要释放对象前删除该委托。

WPF 挂接[Changed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.changed)事件在内部。 例如，所有依赖属性[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)为一个值，将侦听到[Changed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.changed)事件自动。 [Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)属性，它采用[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)，说明了此概念。

```csharp
Brush myBrush = new SolidColorBrush(Colors.Red);
Rectangle myRectangle = new Rectangle();
myRectangle.Fill = myBrush;
```

赋值`myBrush`到`myRectangle.Fill`、 重新指向委托[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)对象将添加到[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)对象的[Changed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.changed)事件。 这意味着以下代码实际上不会使 `myRect` 可以进行垃圾回收：

```csharp
myRectangle = null;
```

在这种情况下`myBrush`仍保持`myRectangle`处于活动状态并将对其进行调用时它将引发其[Changed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.changed)事件。 请注意，分配`myBrush`到[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)属性的新[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)只需添加到另一个事件处理程序`myBrush`。

清理这些类型的对象的建议的方法是删除[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)从[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)属性，这将进而删除[Changed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.changed)事件处理程序。

```csharp
myRectangle.Fill = null;
myRectangle = null;
```

#### 用户界面虚拟化

WPF 此外提供了一种变体的[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)自动"虚拟化"数据绑定子级内容的元素。 在此上下文中，“虚拟化”一词指的是以下技术：通过此技术，从较多的数据项中生成一个对象子集，具体取决于屏幕上哪些项可见。 如果在指定时刻只有少量 UI 元素位于屏幕上，则此时生成大量 UI 元素需要占用大量内存和处理器。 [VirtualizingStackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel)(通过提供的功能[VirtualizingPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingpanel)) 计算可见项，并处理[ItemContainerGenerator](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemcontainergenerator)从[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)(如[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)或[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)) 仅创建为可见项的元素。

作为性能优化的结果，将仅生成这些项的视觉对象，或如果它们在屏幕上是可见的，则保持活动状态。 这些视觉对象不再位于控件的可视区域时，则可能已被删除。 请勿将此与数据虚拟化发生混淆，数据虚拟化中的数据对象不会全部出现在本地集合中 - 而是根据需要进行流式处理。

下表显示了经过的时间中添加和呈现 5000[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素与[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)和一个[VirtualizingStackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel)。 在此方案中，度量值表示附加到一个文本字符串之间的时间[ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource)属性的[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)panel 元素时显示的文本字符串的时间的对象。

| **主机面板**                                                 | **呈现时间 (ms)** |
| ------------------------------------------------------------ | ----------------- |
| [StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel) | 3210              |
| [VirtualizingStackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel) | 46                |

### [Application Resources](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/optimizing-performance-application-resources)

WPF 可以共享应用程序资源，以便可以跨类似类型的元素支持一致的外观或行为。 本主题提供了一些建议在此区域中可帮助你改进应用程序的性能。

有关资源的详细信息，请参阅 [XAML 资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-resources)。

#### 共享资源

如果你的应用程序使用自定义控件和定义中的资源[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)（或 XAML 资源节点），建议，您可以定义在资源[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)或[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)对象级别，或定义中的默认主题自定义控件。 定义一个自定义控件中的资源[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)施加了该控件的每个实例的性能造成影响。 例如，如果有需要进行大量性能的画笔操作定义为资源定义的自定义控件的部件和自定义控件的多个实例，则应用程序的工作集将显著增加。

若要演示这一点，请考虑以下。 假设你正在开发卡游戏 using WPF。 对于大多数纸牌游戏，需要 52 张牌，52 不同的人脸。 还可以实施一种卡片自定义控件和卡自定义控件的资源中定义 52 画笔 （每个元素表示一种纸牌外观）。 在主应用程序，最初创建此卡自定义控件 52 个的实例。 卡自定义控件的每个实例生成的 52 个实例[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)对象，这将使您总共 52 * 52[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)你的应用程序中的对象。 通过将移动到的卡自定义控件资源超出画笔[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)或[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)对象级别，或在自定义控件的默认主题中定义它们你降低该应用程序的工作集，因为现在正在共享 52 画笔52 个实例的卡片控件。

#### 不进行复制而共享画笔

如果您有多个元素使用的相同[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)对象，定义为资源的画笔并引用它，而不是定义中的画笔内联XAML。 此方法将创建一个实例，并重复使用它，而定义画笔中的以内联方式XAML创建的每个元素的新实例。

以下标记示例阐释了这一点：

```xaml
<StackPanel.Resources>
  <LinearGradientBrush x:Key="myBrush" StartPoint="0,0.5" EndPoint="1,0.5" Opacity="0.5">
    <LinearGradientBrush.GradientStops>
      <GradientStopCollection>
        <GradientStop Color="GoldenRod" Offset="0" />
        <GradientStop Color="White" Offset="1" />
      </GradientStopCollection>
    </LinearGradientBrush.GradientStops>
  </LinearGradientBrush>
</StackPanel.Resources>

<!-- Non-shared Brush object. -->
<Label>
  Label 1
  <Label.Background>
    <LinearGradientBrush StartPoint="0,0.5" EndPoint="1,0.5" Opacity="0.5">
      <LinearGradientBrush.GradientStops>
        <GradientStopCollection>
          <GradientStop Color="GoldenRod" Offset="0" />
          <GradientStop Color="White" Offset="1" />
        </GradientStopCollection>
      </LinearGradientBrush.GradientStops>
    </LinearGradientBrush>
  </Label.Background>
</Label>

<!-- Shared Brush object. -->
<Label Background="{StaticResource myBrush}">Label 2</Label>
<Label Background="{StaticResource myBrush}">Label 3</Label>
```

#### 使用静态资源在可能的情况

静态资源通过查找对已定义资源的引用，为任何 XAML 属性提供值。 类似于编译时查找该资源的查找行为。

动态资源，但是，将创建初始编译期间的临时表达式，并因此延迟的资源查找，直到实际需要来构造对象请求的资源值为止。 该资源的查找行为是类似于运行时查找，它会影响性能。 使用静态资源应尽可能使用动态资源仅在必要时你应用程序中。

以下标记示例演示如何使用这两种类型的资源：

```xaml
<StackPanel.Resources>
  <SolidColorBrush x:Key="myBrush" Color="Teal"/>
</StackPanel.Resources>

<!-- StaticResource reference -->
<Label Foreground="{StaticResource myBrush}">Label 1</Label>

<!-- DynamicResource reference -->
<Label Foreground="{DynamicResource {x:Static SystemColors.ControlBrushKey}}">Label 2</Label>
```

### [Text](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/optimizing-performance-text)

WPF 支持通过使用功能丰富的 用户界面 (UI) 控件实现的文本内容演示。 通常可以将文本呈现分为三层：

1. 使用[Glyphs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.glyphs)和[GlyphRun](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.glyphrun)直接对象。
2. 使用[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext)对象。
3. 使用高级别控件，如[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)和[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)对象。

本主题提供文本呈现性能方面的建议。

#### 字形级别的呈现文本

Windows Presentation Foundation (WPF) 提供高级的文本支持，包括直接访问的字形级标记[Glyphs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.glyphs)的客户想要拦截和保留格式化后的文本。 这些功能为以下每种方案中不同的文本呈现要求提供关键支持。

- 固定格式文档的屏幕显示。
- 打印方案。
  - 可扩展应用程序标记语言 (XAML) 作为设备打印机语言。
  - Microsoft XPS 文档编写器。
  - 以前的打印机驱动程序，从 Win32 应用程序输出为固定格式。
  - 打印后台处理格式。
- 固定格式的文档演示，包括以前版本的 Windows 客户端和其他计算设备。

> [Glyphs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.glyphs) 和[GlyphRun](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.glyphrun)专为固定格式文档演示和打印方案。 Windows Presentation Foundation (WPF) 为常规布局提供若干元素和用户界面 (UI)如下方案[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)和[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)。 有关布局和 UI 方案的详细信息，请参阅 [WPF 中的版式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/typography-in-wpf)。

以下示例演示如何定义的属性[Glyphs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.glyphs)对象中可扩展应用程序标记语言 (XAML)。 [Glyphs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.glyphs)对象表示的输出[GlyphRun](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.glyphrun)中XAML。 示例假定本地计算机上的 **C:\WINDOWS\Fonts** 文件夹中安装了 Arial、Courier New 和 Times New Roman 字体。

XAML复制

```xaml
<!-- The example shows how to use a Glyphs object. -->
<Page
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  >

   <StackPanel Background="PowderBlue">

      <Glyphs
         FontUri             = "C:\WINDOWS\Fonts\TIMES.TTF"
         FontRenderingEmSize = "100"
         StyleSimulations    = "BoldSimulation"
         UnicodeString       = "Hello World!"
         Fill                = "Black"
         OriginX             = "100"
         OriginY             = "200"
      />

   </StackPanel>
</Page>
```

##### 使用 DrawGlyphRun

如果具有自定义控件，并且你想要呈现字形，请使用[DrawGlyphRun](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingcontext.drawglyphrun)方法。

WPF 此外提供了用于自定义设置文本格式使用较低级别服务[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext)对象。 在呈现文本的最有效方法Windows Presentation Foundation (WPF)是通过生成字形级别使用的文本内容[Glyphs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.glyphs)和[GlyphRun](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.glyphrun)。 但是，高效的代价是丢失了易于使用丰富文本格式设置，它们是内置功能的Windows Presentation Foundation (WPF)控件，如[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)和[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)。

#### FormattedText 对象

[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext)对象可绘制多行文本，在其中的文本中的每个字符可以单独设置格式。 有关详细信息，请参阅[绘制格式化文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/drawing-formatted-text)。

若要创建带格式的文本，请调用[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.-ctor)构造函数创建[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext)对象。 创建初始格式化文本字符串后，便可应用某一范围的格式样式。 如果你的应用程序想要实现其自身的布局，则[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext)对象是比使用一个控件，例如更好的选择[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)。 有关详细信息[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext)对象，请参阅[绘制格式化文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/drawing-formatted-text)。

[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext)对象提供低级别的文本格式设置功能。 可向一个或多个字符应用多种格式样式。 例如，您可以调用[SetFontSize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.setfontsize)和[SetForegroundBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.setforegroundbrush)方法来更改格式设置的文本中的前五个字符。

下面的代码示例创建[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext)对象，并将其呈现。

```csharp
protected override void OnRender(DrawingContext drawingContext)
{
    string testString = "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor";

    // Create the initial formatted text string.
    FormattedText formattedText = new FormattedText(
        testString,
        CultureInfo.GetCultureInfo("en-us"),
        FlowDirection.LeftToRight,
        new Typeface("Verdana"),
        32,
        Brushes.Black);

    // Set a maximum width and height. If the text overflows these values, an ellipsis "..." appears.
    formattedText.MaxTextWidth = 300;
    formattedText.MaxTextHeight = 240;

    // Use a larger font size beginning at the first (zero-based) character and continuing for 5 characters.
    // The font size is calculated in terms of points -- not as device-independent pixels.
    formattedText.SetFontSize(36 * (96.0 / 72.0), 0, 5);

    // Use a Bold font weight beginning at the 6th character and continuing for 11 characters.
    formattedText.SetFontWeight(FontWeights.Bold, 6, 11);

    // Use a linear gradient brush beginning at the 6th character and continuing for 11 characters.
    formattedText.SetForegroundBrush(
                            new LinearGradientBrush(
                            Colors.Orange,
                            Colors.Teal,
                            90.0),
                            6, 11);

    // Use an Italic font style beginning at the 28th character and continuing for 28 characters.
    formattedText.SetFontStyle(FontStyles.Italic, 28, 28);

    // Draw the formatted text string to the DrawingContext of the control.
    drawingContext.DrawText(formattedText, new Point(10, 0));
}
```



#### FlowDocument、TextBlock 和 Label 控件

WPF 包括多个用于在屏幕中绘制文本的控件。 每个控件都面向不同的方案，并具有自己的功能和限制列表。

##### FlowDocument 对性能的影响比 TextBlock 或 Label 大

一般情况下，[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)有限的文本支持是必需的例如中的简短句子时，应使用元素用户界面 (UI)。 [Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label) 需要最少的文本支持时，可以使用。 [FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)元素是支持丰富的内容，演示的可重流动文档的容器，因此，具有比使用较好的性能效果[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)或[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)控件。

有关详细信息[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)，请参阅[流文档概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/flow-document-overview)。

##### 避免在 FlowDocument 中使用 TextBlock

[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素派生自[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)。 [Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run)元素派生自[TextElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.textelement)，这是比使用成本较低[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)-派生的对象。 如果可能，请使用[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run)而非[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)用于显示文本内容中[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)。

以下标记示例演示了两种方法中设置文本内容[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument):

```xaml
<FlowDocument>

  <!-- Text content within a Run (more efficient). -->
  <Paragraph>
    <Run>Line one</Run>
  </Paragraph>

  <!-- Text content within a TextBlock (less efficient). -->
  <Paragraph>
    <TextBlock>Line two</TextBlock>
  </Paragraph>

</FlowDocument>
```

##### 避免使用 Run 来设置文本属性

一般情况下，使用[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run)内[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)是更高的性能密集型比不使用显式[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run)根本对象。 如果使用的[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run)来设置文本属性，在上直接设置这些属性[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)相反。

以下标记示例阐释了这两种方式设置文本属性，在这种情况下的[FontWeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.fontweight)属性：

```xaml
<!-- Run is used to set text properties. -->
<TextBlock>
  <Run FontWeight="Bold">Hello, world</Run>
</TextBlock>

<!-- TextBlock is used to set text properties, which is more efficient. -->
<TextBlock FontWeight="Bold">
  Hello, world
</TextBlock>
```

下表演示显示 1000 个成本[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)对象，无需显式[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.run)。

| **TextBlock 类型**     | **创建时间 (ms)** | **呈现时间 (ms)** |
| ---------------------- | ----------------- | ----------------- |
| 运行设置文本属性       | 146               | 540               |
| TextBlock 设置文本属性 | 43                | 453               |

##### 避免对 Label.Content 属性进行数据绑定

假设其中有[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)从经常更新的对象[String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)源。 当数据绑定[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)元素的[Content](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.content)属性设置为[String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)源对象时，可能会遇到性能不佳。 每次源[String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)更新时，旧[String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)对象是放弃，并且一个新[String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)重新创建，因为[String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)对象是不可变的不能修改。 此操作，又会导致[ContentPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter)的[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)对象来丢弃其旧的内容，并重新生成新的内容，以显示新[String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)。

此问题的解决方法很简单。 如果[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)未设置为自定义[ContentTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.contenttemplate)值，替换[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)与[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)和数据绑定其[Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.text)属性设置为源字符串。

| **数据绑定属性** | **更新时间 (ms)** |
| ---------------- | ----------------- |
| Label.Content    | 835               |
| TextBlock.Text   | 242               |

#### 超链接

[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)对象是允许您承载流内容中的超链接的内联级流内容元素。

##### 在一个 TextBlock 对象中合并超链接

您可以优化使用多个[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)通过在同一个组合元素[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)。 这有助于最小化在应用程序中创建的对象的数量。 例如，可显示多个超链接，如下所示：

MSN 主页 | 我的 MSN

以下标记示例演示多个[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素用来显示超链接：

```xaml
<!-- Hyperlinks in separate TextBlocks. -->
<TextBlock>
  <Hyperlink TextDecorations="None" NavigateUri="http://www.msn.com">MSN Home</Hyperlink>
</TextBlock>

<TextBlock Text=" | "/>

<TextBlock>
  <Hyperlink TextDecorations="None" NavigateUri="http://my.msn.com">My MSN</Hyperlink>
</TextBlock>
```

以下标记示例演示更有效地显示的超链接，这一次，使用单个[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock):

XAML复制

```xaml
<!-- Hyperlinks combined in the same TextBlock. -->
<TextBlock>
  <Hyperlink TextDecorations="None" NavigateUri="http://www.msn.com">MSN Home</Hyperlink>
  
  <Run Text=" | " />
  
  <Hyperlink TextDecorations="None" NavigateUri="http://my.msn.com">My MSN</Hyperlink>
</TextBlock>
```

##### 仅在 MouseEnter 事件的超链接中显示下划线

一个[TextDecoration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.textdecoration)对象是可以添加到文本的视觉装饰; 但是，它可能会占用实例化。 如果充分利用了[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)元素，请考虑仅在触发事件，如时显示下划线[MouseEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement.mouseenter)事件。 有关详细信息，请参阅[指定是否为超链接添加下划线](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-specify-whether-a-hyperlink-is-underlined)。

![显示 TextDecorations 的超](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/textdecoration03.png)
MouseEnter 上显示的超链接

以下标记示例演示[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)使用和不使用下划线定义：

```xaml
<!-- Hyperlink with default underline. -->
<Hyperlink NavigateUri="http://www.msn.com">
  MSN Home
</Hyperlink>

<Run Text=" | " />

<!-- Hyperlink with no underline. -->
<Hyperlink Name="myHyperlink" TextDecorations="None"
           MouseEnter="OnMouseEnter"
           MouseLeave="OnMouseLeave"
           NavigateUri="http://www.msn.com">
  My MSN
</Hyperlink>
```

下表演示显示 1000 个的性能成本[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)元素使用和不使用下划线。

| **超链接**   | **创建时间 (ms)** | **呈现时间 (ms)** |
| ------------ | ----------------- | ----------------- |
| 使用下划线   | 289               | 1130              |
| 不使用下划线 | 299               | 776               |



#### 文本格式设置功能

WPF 提供丰富的文本格式设置服务，如自动断字。 这些服务可能会影响应用程序性能，应仅在需要时使用。

##### 避免不必要地使用断字

自动断字功能查找连字符断点的行文本，并允许添加中断位置中线条[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)和[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)对象。 默认禁用这些对象中的自动断字功能。 通过将该对象的 IsHyphenationEnabled 属性设置为 `true`，可以启用此功能。 但是，启用此功能会导致 WPF 启动 组件对象模型 (COM) 互操作性，这可能会影响应用程序的性能。 除非需要，否则不建议使用自动断字功能。

##### 谨慎使用图形

一个[Figure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.figure)元素表示可以是绝对定位在某页内容的流内容的一部分。 在某些情况下，[Figure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.figure)可能会导致整个页后，可以自动重新格式化如果其位置与已布局的内容有冲突。可以通过组合在一起不需要重新格式化的可能性降至[Figure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.figure)旁边，也可以声明它们中固定的页大小的情况下内容的顶部附近的元素。

##### 最佳段落

最佳段落功能[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)对象对段落进行布局，以便尽可能均匀地分布空白区域。 默认禁用最佳段落功能。可以通过设置对象的启用此功能[IsOptimalParagraphEnabled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument.isoptimalparagraphenabled)属性设置为`true`。 但是，启用此功能会影响应用程序的性能。 除非需要，否则不建议使用最佳段落功能。

### [Data Binding](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/optimizing-performance-data-binding)

Windows Presentation Foundation (WPF) 数据绑定为应用程序呈现数据并与数据交互提供了一种简单且一致的方式。 元素能够以 CLR 对象和 XML 形式绑定到来自各种数据源的数据。

本主题提供数据绑定性能方面的建议。

#### 如何解析数据绑定引用

讨论数据绑定性能问题前，有必要了解 Windows Presentation Foundation (WPF) 数据绑定引擎如何解析用于绑定的对象引用。

Windows Presentation Foundation (WPF) 数据绑定的源可以是任何 CLR 对象。 可绑定到 CLR 对象的属性、子属性或索引器。 通过使用任一 Microsoft.NET Framework 反射解析绑定引用或[ICustomTypeDescriptor](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.icustomtypedescriptor)。 以下为解析用于绑定的对象引用的三种方法。

第一种方法涉及到使用反射。 在这种情况下，[PropertyInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.propertyinfo)对象用于发现的属性特性，并提供对属性元数据的访问。 当使用[ICustomTypeDescriptor](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.icustomtypedescriptor)接口，数据绑定引擎使用此接口访问的属性值。 [ICustomTypeDescriptor](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.icustomtypedescriptor)接口是在该对象不具有一组静态属性的情况下特别有用。

属性更改通知可提供通过实现[INotifyPropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.inotifypropertychanged)接口或通过使用与关联的更改通知[TypeDescriptor](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typedescriptor)。 但是，实现属性更改通知的首选的策略是使用[INotifyPropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.inotifypropertychanged)。

如果源对象是CLR对象和源属性是CLR属性，Windows Presentation Foundation (WPF)数据绑定引擎必须首先使用在源对象上反射来获取[TypeDescriptor](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typedescriptor)，然后查询[PropertyDescriptor](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.propertydescriptor)。 从性能角度看，此反射操作序列可能非常耗时。

解析对象引用第二种方法涉及CLR源对象，它实现[INotifyPropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.inotifypropertychanged)接口，并且是一个源属性CLR属性。 这种情况下，数据绑定引擎直接在源类型上使用反射，并获取所需的属性。 这依然不是最佳方法，但相较于第一种方法，这种方法在工作集要求方面的成本低。

解析对象引用的第三个方法涉及到的源对象[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)是一个源属性和[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)。 这种情况下，数据绑定引擎无需使用反射。 属性引擎和数据绑定引擎共同独立地解析属性引用。 这是解析用于数据绑定的对象引用的最佳方法。

下表比较了数据绑定的速度[Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.text)一千属性[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素使用这三种方法。

| **绑定 TextBlock 的文本属性**                                | **绑定时间 (ms)** | **呈现时间 -- 包括绑定 (ms)** |
| ------------------------------------------------------------ | ----------------- | ----------------------------- |
| 绑定到 CLR 对象的属性                                        | 115               | 314                           |
| 到的属性CLR实现的对象 [INotifyPropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.inotifypropertychanged) | 115               | 305                           |
| 向[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)的[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)。 | 90                | 263                           |

#### 绑定到大型 CLR 对象

数据绑定到具有数千个属性的单个 CLR 对象时具有明显性能影响。 通过将单个对象分成具有较少属性的多个 CLR对象可降低对性能的影响。 下表显示将数据绑定到单个大型 CLR 对象和多个较小对象的绑定时间和呈现时间。

| **数据绑定 1000 个 TextBlock 对象**    | **绑定时间 (ms)** | **呈现时间 -- 包括绑定 (ms)** |
| -------------------------------------- | ----------------- | ----------------------------- |
| 绑定到具有 1000 个属性的 CLR 对象      | 950               | 1200                          |
| 绑定到 1000 个具有 1 个属性的 CLR 对象 | 115               | 314                           |

#### 绑定到 ItemsSource

在其中可以假设CLR[List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1)对象，它保存一组你想要在中显示的员工[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)。 若要创建这两个对象之间的对应关系，应绑定到员工列表[ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource)属性的[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)。 不妨再假设有一个加入组的新员工。 可能会认为，若要将此新人员插入到绑定的[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)值，将只需将此人添加到员工列表并通过数据绑定引擎会自动识别此更改。 这种假设将被证明是错误;在现实中，将不会更改反映在[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)自动。 这是因为CLR[List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1)对象不会自动引发集合更改事件。 为了获得[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)选取所做的更改，必须重新创建员工列表，并重新将其附加到[ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource)属性的[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)。此解决方案尽管起作用，但是会随之产生很大的性能影响。 每当你重新分配[ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource)的[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)到新的对象，[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)首先抛弃先前的项，并重新生成整个列表。 性能影响更大时，如果你[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)映射到复杂[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)。

此问题非常高效的解决方案是使员工列表[ObservableCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.objectmodel.observablecollection-1)。 [ObservableCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.objectmodel.observablecollection-1)对象会引发数据绑定引擎可接收的更改通知。 该事件将添加或移除的项从[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)而无需重新生成整个列表。

下表显示了所要更新的时间[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)（其中 UI 虚拟化处于关闭状态） 时添加一个项。 第一行中的数字表示的运行时间时CLR[List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1)对象绑定到[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)元素的[ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource)。 第二行中的数字表示的运行时间时[ObservableCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.objectmodel.observablecollection-1)绑定到[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)元素的[ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource)。 请注意大量的时间节省使用[ObservableCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.objectmodel.observablecollection-1)数据绑定策略。

| **数据绑定 ItemsSource**                                     | **1 个项的更新时间 (ms)** |
| ------------------------------------------------------------ | ------------------------- |
| 向CLR[List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1)对象 | 1656                      |
| 到 [ObservableCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.objectmodel.observablecollection-1) | 20                        |

#### 将 IList 绑定到 ItemsControl 而非 IEnumerable

如果必须绑定之间进行选择[IList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ilist-1)或[IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable)到[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)对象，请选择[IList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ilist-1)对象。 绑定[IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable)到[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)强制WPF创建包装器[IList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ilist-1)对象，这意味着您的性能受第二个对象的不必要的开销。

#### 请勿仅为数据绑定而将 CLR 对象转换为 XML。

通过 WPF 可数据绑定到 XML 内容；但是，数据绑定到 XML 内容与数据绑定到 CLR 对象相比速度更慢。 如果目的仅在于数据绑定，请勿将 CLR 对象数据转换为 XML。

### [Controls](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/optimizing-performance-controls)

Windows Presentation Foundation (WPF) 包含许多使用的常见用户界面 (UI) 组件在大多数 Windows 应用程序。本主题包含提高 UI 性能的技术。

#### 显示大型数据集

WPF 控件，如[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)和[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)用于应用程序中显示的项列表。 如果要显示的列表较大，则应用程序性能可能受到影响。 这是因为标准布局系统会为每个与列表控件关联的项创建布局容器，并计算其布局大小和位置。通常，无需同时显示所有项，而是显示子集，然后用户滚动浏览列表。 这种情况下，使用 UI 虚拟化具有意义，这意味着生成项容器，且项的关联布局计算会推迟，直到项可见时。

UI 虚拟化是列表控件的一个重要方面。 不应混淆 UI 虚拟化和数据虚拟化。 UI 虚拟化在内存中仅存储可见项，但在数据绑定方案中会存储内存中的整个数据结构。 相反，数据虚拟化仅存储内存中屏幕上可见的数据项。

默认情况下，为启用 UI 虚拟化[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)和[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)控制其列表项绑定到数据时。 [TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview) 可以通过设置启用虚拟化[VirtualizingStackPanel.IsVirtualizing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel.isvirtualizing)附加属性设置为`true`。 如果你想要启用 UI 虚拟化的自定义控件派生自[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)或现有项控件使用[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)类，如[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)，可以设置[ItemsPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemspanel)到[VirtualizingStackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel)并设置[IsVirtualizing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingpanel.isvirtualizing)到`true`. 遗憾的是，可对没有实现虚拟化的控件禁用 UI 虚拟化。 以下为禁用 UI 虚拟化的条件列表。

- 项容器直接添加到[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)。 例如，如果应用程序显式添加[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)对象添加到[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)，则[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)不会虚拟[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)对象。
- 中的项容器[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)类型不同。 例如， [Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu) ，它使用[Separator](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.separator)对象无法实现项回收，因为[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)包含类型的对象[Separator](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.separator)和[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)。
- 设置[CanContentScroll](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer.cancontentscroll)到`false`。
- 设置[IsVirtualizing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel.isvirtualizing)到`false`。

虚拟化项容器时需要考虑到一个重要因素，即是否具有与属于项的项容器相关联的其他状态信息。 这种情况下，必须保存其他状态。 例如，可能有中包含的项[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)控件和[IsExpanded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander.isexpanded)状态绑定到项的容器，而不是项目本身。 容器的新项目的当前值的重用时间[IsExpanded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander.isexpanded)用于新项。 此外，旧项会丢失正确[IsExpanded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander.isexpanded)值。

当前，无任何 WPF 控件提供对数据虚拟化的内置支持。

#### 容器回收

一种优化方式 UI 虚拟化在.NET Framework 3.5 SP1 的继承的控件添加到[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)是*容器回收，* 这样还可提高滚动性能。 当[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)填充使用 UI 虚拟化，它会创建每个项，滚动到视图中，并销毁滚动出视野之外的每个项的项容器的项容器。 *容器回收*使得控件可以重用不同的数据项，将现有项容器，以便无需经常创建和销毁当用户滚动项容器[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)。 您可以选择启用项回收通过设置[VirtualizationMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingpanel.virtualizationmode)附加属性设置为[Recycling](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizationmode#System_Windows_Controls_VirtualizationMode_Recycling)。

任何[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)支持虚拟化可以使用容器回收。 有关如何启用容器回收上的示例[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)，请参阅[提高 ListBox 的滚动性能](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-improve-the-scrolling-performance-of-a-listbox)。

#### 支持双向虚拟化

[VirtualizingStackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel) 提供对在一个方向的 UI 虚拟化的内置支持水平或垂直。 如果你想要使用双向虚拟化您的控件，则必须实现扩展的自定义面板[VirtualizingStackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel)类。 [VirtualizingStackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel)类公开的虚拟方法，如[OnViewportSizeChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel.onviewportsizechanged)， [LineUp](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel.lineup)， [PageUp](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel.pageup)，和[MouseWheelUp](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel.mousewheelup)。这些虚拟方法，可检测列表可见部分中的更改并相应地处理。

#### 优化模板

可视化树包含应用程序中所有可视元素。 除直接创建的对象外，它还包括由于模板扩展而产生的对象。 例如，创建[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)，您还可以获得[ClassicBorderDecorator](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.windows.themes.classicborderdecorator)和[ContentPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter)可视化树中的对象。 如果尚未优化模板控件，则要在可视化树中创建大量不必要的额外对象。 有关可视化树的详细信息，请参见 [WPF 图形呈现概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/wpf-graphics-rendering-overview)。

#### 延迟滚动

默认情况下，用户拖动滚动条上的滚动块时，内容视图会不断更新。 如果控件中滚动较慢，请考虑使用延迟滚动。 在延迟滚动中，仅在用户释放滚动块时才会更新内容。

若要实现延迟滚动，设置[IsDeferredScrollingEnabled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer.isdeferredscrollingenabled)属性设置为`true`。 [IsDeferredScrollingEnabled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer.isdeferredscrollingenabled) 是一个附加的属性和可以设置[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)并具有任何控件[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)其控件模板中。

#### 控件可实现性能功能

下表列出了显示数据的常见控件及其性能功能支持。 有关如何启用这些功能的信息，请参阅先前章节。

| 控件                                                         | 虚拟化 | 容器回收 | 延迟滚动 |
| ------------------------------------------------------------ | ------ | -------- | -------- |
| [ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox) | 可启用 | 可启用   | 可启用   |
| [ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu) | 可启用 | 可启用   | 可启用   |
| [DocumentViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.documentviewer) | 不可用 | 不可用   | 可启用   |
| [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) | 默认   | 可启用   | 可启用   |
| [ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview) | 默认   | 可启用   | 可启用   |
| [TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview) | 可启用 | 可启用   | 可启用   |
| [ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar) | 不可用 | 不可用   | 可启用   |

> 有关如何启用虚拟化和容器上回收的示例[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)，请参阅[提高 TreeView 的性能](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-improve-the-performance-of-a-treeview)。

### [Other Performance Recommendations](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/optimizing-performance-other-recommendations)

本主题提供[优化 WPF 应用程序性能](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/optimizing-wpf-application-performance)这一节中各主题内容之外的性能改进建议。

本主题包含以下各节：

- [画笔的不透明度与元素的不透明度](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/optimizing-performance-other-recommendations#Opacity)
- [导航到对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/optimizing-performance-other-recommendations#Navigation_Objects)
- [对大型 3D 图面进行命中测试](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/optimizing-performance-other-recommendations#Hit_Testing)
- [CompositionTarget.Rendering 事件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/optimizing-performance-other-recommendations#CompositionTarget_Rendering_Event)
- [避免使用 ScrollBarVisibility=Auto](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/optimizing-performance-other-recommendations#Avoid_Using_ScrollBarVisibility)
- [配置字体缓存服务以缩短启动时间](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/optimizing-performance-other-recommendations#FontCache)

#### 画笔的不透明度与元素的不透明度

当你使用[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)若要设置[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)或[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.stroke)的元素，则最好设置[Brush.Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.opacity)值比设置元素的[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)属性。 修改元素的[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)属性可能会导致WPF创建临时图面。

#### 导航到对象

[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)对象派生[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)并将其扩展并用内容导航支持，主要是通过聚合[NavigationService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationservice)和日志。您可以更新的工作区[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)通过指定统一资源标识符 (URI)或对象。 以下示例演示了这两种方法：

```csharp
private void buttonGoToUri(object sender, RoutedEventArgs args)
{
    navWindow.Source = new Uri("NewPage.xaml", UriKind.RelativeOrAbsolute);
}

private void buttonGoNewObject(object sender, RoutedEventArgs args)
{
    NewPage nextPage = new NewPage();
    nextPage.InitializeComponent();
    navWindow.Content = nextPage;
}
```

每个[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)对象都有一个日志记录在该窗口中的用户的导航历史记录。 日志的作用之一是允许用户回溯他们执行的步骤。

使用 统一资源标识符 (URI) 导航时，日志只存储统一资源标识符 (URI) 引用。 这意味着，每次重新访问该页时都会动态地重新构造该页，根据页面的复杂程度，此过程可能会非常耗时。 在这种情况下，虽然占用的日志存储较少，但用于重建该页的时间可能会较长。

使用对象进行导航时，日志会存储对象的整个可视化树。 这意味着，每次重新访问该页时，无需重新构造即可立即呈现该页。 在这种情况下，虽然占用的日志存储较多，但重建页面所用的时间较短。

当你使用[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)对象，将需要记住日志支持是如何影响应用程序的性能。 有关详细信息，请参阅[导航概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-overview)。



#### 对大型 3D 图面进行命中测试

就 CPU 消耗而言，对大型 3D 图面进行命中测试是一项非常占用资源的操作。 3D 图面显示动画效果时更是如此。 如果不需要对这些图面进行命中测试，请禁用命中测试。 派生自的对象[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)可以禁用命中测试通过设置[IsHitTestVisible](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ishittestvisible)属性设置为`false`。

#### CompositionTarget.Rendering 事件

[CompositionTarget.Rendering](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.compositiontarget.rendering)事件会导致WPF连续显示动画效果。 使用此事件时，应尽可能将其分离。

#### 避免使用 ScrollBarVisibility=Auto

只要有可能，避免使用[ScrollBarVisibility.Auto](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollbarvisibility#System_Windows_Controls_ScrollBarVisibility_Auto)值`HorizontalScrollBarVisibility`和`VerticalScrollBarVisibility`属性。 这些属性定义为[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)， [ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)，并[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)对象，并作为附加属性的[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)对象。 与此相反，设置[ScrollBarVisibility](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollbarvisibility)到[Disabled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollbarvisibility#System_Windows_Controls_ScrollBarVisibility_Disabled)， [Hidden](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollbarvisibility#System_Windows_Controls_ScrollBarVisibility_Hidden)，或[Visible](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollbarvisibility#System_Windows_Controls_ScrollBarVisibility_Visible)。

[Auto](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollbarvisibility#System_Windows_Controls_ScrollBarVisibility_Auto)空间有限制，并在必要时，应仅显示滚动条时，将值适用于用例。 例如，可能会使用此选项很有用[ScrollBarVisibility](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollbarvisibility)具有值[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)30 个项目而不是[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)与具有数百行文本。

#### 配置字体缓存服务以缩短启动时间

WPF 字体缓存服务会在 WPF 应用程序之间共享字体数据。 如果该服务尚未运行，则首个运行的 WPF 应用程序将启动此服务。 如果使用的Windows Vista，可以设置从"手动"（默认值）"Windows Presentation Foundation (WPF) 字体缓存 3.0.0.0"服务为"自动 （延迟启动）"，以减少的初始启动时间WPF应用程序。

### [Application Startup Time](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/application-startup-time)

启动 WPF 应用程序所需的时间可能存在极大差异。 本主题介绍用于减少 Windows Presentation Foundation (WPF) 应用程序假设启动时间和实际启动时间的各种技巧。

#### 了解冷启动和热启动

冷启动发生在系统重启后第一次启动应用程序时，或启动应用程序、将其关闭，然后在很长一段时间后再次启动应用程序时。 应用程序启动时，如果所需的页面（代码、静态数据、注册表等）不在 Windows 内存管理器的待机列表中，会发生页面错误。 需要磁盘访问权限，以便将这些页面加载到内存中。

当已将主要公共语言运行时 (CLR) 组件的大多数页面加载到内存中时，则发生热启动，这样可节省宝贵的磁盘访问时间。 这就是为什么再次运行托管的应用程序时，该程序的启动速度更快的原因。

#### 实现初始屏幕

为应对在启动应用程序后到显示第一个 UI 期间出现重大的、不可避免的延迟的情况，请使用“初始屏幕”优化假设的启动时间。 通过此方法，在用户启动应用程序后，几乎可以立即显示图像。 当应用程序准备好显示其第一个 UI 时，初始屏幕将淡化。 在中启动.NET Framework 3.5 SP1，可以使用[SplashScreen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.splashscreen)类，以实现初始屏幕。 有关详细信息，请参阅[将初始屏幕添加到 WPF 应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/how-to-add-a-splash-screen-to-a-wpf-application)。

还可以通过使用本机 Win32 图形来实现自己的初始屏幕。 显示之前实现[Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.run)调用方法。

#### 分析启动代码

确定冷启动慢的原因。 可能与磁盘 I/O 有关，但这并非唯一的原因。 一般情况下，应将外部资源（例如网络、Web 服务或磁盘）的使用率最小化。

在测试之前，验证没有其他正在运行的应用程序或服务会使用托管代码或 WPF 代码。

重新启动后，立即启动 WPF 应用程序，并决定用于显示的时间。 如果应用程序的所有后续启动（热启动）相较之下快很多，则冷启动问题很可能是 I/O 所致。

如果应用程序的冷启动问题与 I/O 无关，则冷启动慢的原因很可能是应用程序在启动时会执行一些耗时较长的初始化进程或计算、等待某些事件完成或需要大量的 JIT 编译。 以下章节对其中某些情况进行了详细介绍。

#### 优化模块加载

使用工具（例如进程资源管理器 (Procexp.exe) 和 Tlist.exe）来确定应用程序加载的模块。 命令 `Tlist <pid>` 显示由某一进程加载的所有模块。

例如，如果没有连接到 Web，并且发现已加载 System.Web.dll，则应用程序中存在引用此程序集的模块。 检查以确定该引用是必要的。

如果应用程序具有多个模块，则请将其合并为单个模块。 此方法要求较少的 CLR 程序集加载开销。 较少的程序集还意味着 CLR 维护较少的状态。

#### 延迟初始化操作

请考虑将初始化代码延迟至主应用程序窗口呈现之后。

请注意，可能会在类构造函数内执行初始化，如果初始化代码引用其他类，则可能会导致级联效应（执行许多类构造函数）。

#### 避免应用程序配置

请考虑避免应用程序配置。 例如，如果某一应用程序具有简单的配置要求，并且具有严格的启动时间目标，则注册表项或简单的 INI 文件可能是更快的启动替代方法。

#### 利用 GAC

如果未在全局程序集缓存 (GAC) 中安装程序集，则将出现由强命名程序集的哈希验证和 Ngen 映像验证（如果计算机上该程序集的本机映像可用）导致的延迟。 对于安装到 GAC 中的所有程序集，会跳过强命名验证。 有关详细信息，请参阅 [Gacutil.exe（全局程序集缓存工具）](https://docs.microsoft.com/zh-cn/dotnet/framework/tools/gacutil-exe-gac-tool)。

#### 使用 Ngen.exe

请考虑在应用程序上使用本机映像生成器 (Ngen.exe)。 使用 Ngen.exe 意味着通过减少 CPU 消耗来实现更多的磁盘访问，因为由 Ngen.exe 生成的本机映像可能会比 MSIL 映像要大。

若要减少热启动时间，则应在应用程序上始终使用 Ngen.exe，因为这可以避免应用程序代码的 JIT 编译的 CPU 成本。

在某些冷启动方案中，使用 Ngen.exe 也会有所帮助。 这是因为不需要加载 JIT 编译器 (mscorjit.dll)。

同时具有 Ngen 和 JIT 模块可能会导致最差的效果。 这是因为必须加载 mscorjit.dll，且当 JIT 编译器处理代码时，当编译器读取程序集的元数据时，必须访问 Ngen 映像中的许多页面。

##### Ngen 和 ClickOnce

计划用于部署应用程序的方法在加载期间也会造成影响。 ClickOnce 应用程序部署不支持 Ngen。 如果决定对应用程序使用 Ngen.exe，则需要使用其他部署机制，如 Windows Installer。

有关详细信息，请参阅 [Ngen.exe（本机映像生成器）](https://docs.microsoft.com/zh-cn/dotnet/framework/tools/ngen-exe-native-image-generator)。

##### 基址重置和 DLL 地址冲突

如果使用 Ngen.exe，请注意，本机映像加载到内存中时可能会发生基址重置。 如果未在 DLL 首选基址加载该 DLL（由于已分配该地址范围），则 Windows 加载程序将在另一地址加载该 DLL，这可能是一个耗时的操作。

可以使用虚拟地址转储 (Vadump.exe) 工具来检查是否存在其中所有页面都为私有的模块。 如果是这种情况，则可能已将该模块的基址重置到另一地址。 因此，不能共享其页面。

有关如何设置基址的详细信息，请参阅 [Ngen.exe（本机映像生成器）](https://docs.microsoft.com/zh-cn/dotnet/framework/tools/ngen-exe-native-image-generator)。

#### 优化验证码

验证码验证会增加启动时间。 验证码签名的程序集必须通过证书颁发机构 (CA) 验证。 此验证可能需要较长时间，因为它可能会要求多次连接到网络，以便下载当前证书吊销列表。 它还确保受信任的根路径上存在完整的有效证书链。 在加载程序集时，这可能会导致几秒钟的延迟。

请考虑在客户端计算机上安装 CA 证书，或尽可能避免使用验证码。 如果知道应用程序不需要发布服务器证据，则无需支付签名验证的费用。

从 .NET Framework 3.5 开始，存在一个允许绕过验证码验证的配置选项。 为执行此操作，将以下设置添加到 app.exe.config 文件：

```xml
<configuration>  
    <runtime>  
        <generatePublisherEvidence enabled="false"/>   
    </runtime>  
</configuration>  
```

有关详细信息，请参阅 [ 元素](https://docs.microsoft.com/zh-cn/dotnet/framework/configure-apps/file-schema/runtime/generatepublisherevidence-element)。

#### 在 Windows Vista 上比较性能

Windows Vista 中的内存管理器具有一种名为 SuperFetch 的技术。 SuperFetch 可随时间推移分析内存使用情况模式，从而确定特定用户的最优内存内容。 它会持续工作，不间断地维护此内容。

这种方法不同于 Windows XP 中使用的预提取技术，后者将数据预先加载到内存，而不分析使用情况模式。 随着时间的推移，如果用户在 Windows Vista 上频繁使用 WPF 应用程序，则可能改善应用程序的冷启动时间。

#### 有效使用 AppDomains

如果可能，将程序集加载到非特定于域的代码区域，以确保本机映像（如果存在）会在应用程序中创建的所有 AppDomain 中使用。

为获得最佳性能，通过减少跨域调用强制实施高效跨域通信。 如果可能，请使用不带参数或具有基元类型参数的调用。

#### 使用 NeutralResourcesLanguage 特性

使用[NeutralResourcesLanguageAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.resources.neutralresourceslanguageattribute)指定的非特定区域性[ResourceManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.resources.resourcemanager)。 此方法可避免程序集查找失败。

#### 将 BinaryFormatter 类用于序列化

如果必须使用序列化，使用[BinaryFormatter](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.serialization.formatters.binary.binaryformatter)类而不是[XmlSerializer](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.serialization.xmlserializer)类。 [BinaryFormatter](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.serialization.formatters.binary.binaryformatter)类实现中基类库 (BCL) 中的 mscorlib.dll 程序集。 [XmlSerializer](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.serialization.xmlserializer)在 System.Xml.dll 程序集中，这可能是其他 DLL 加载中实现。

如果必须使用[XmlSerializer](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.serialization.xmlserializer)类，您可以获得更好的性能预生成序列化程序集。

#### 将 ClickOnce 配置为在启动后检查更新

如果应用程序使用 ClickOnce，请通过将 ClickOnce 配置为在应用程序启动后检查部署站点是否有更新，从而避免在启动时访问网络。

如果使用 XAML 浏览器应用程序 (XBAP) 模型，请记住，即使 XBAP 已存在于 ClickOnce 缓存中，ClickOnce 也会检查部署站点是否存在更新。 有关详细信息，请参阅 [ClickOnce Security and Deployment](https://docs.microsoft.com/zh-cn/visualstudio/deployment/clickonce-security-and-deployment)。

#### 将 PresentationFontCache 服务配置为自动启动

在重新启动后，要运行的第一个 WPF 应用程序是 PresentationFontCache 服务。 该服务会缓存系统字体、改进字体访问，并提高整体性能。 在启动服务时会产生开销，某些受控环境中也存在开销，请考虑将服务配置为在系统重启时自动启动。

#### 以编程方式设置数据绑定

而不是使用 XAML 来设置[DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext)以声明方式对于主窗口中，请考虑在以编程方式设置[OnActivated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.onactivated)方法。

## [Walkthrough: Caching Application Data in a WPF Application](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/walkthrough-caching-application-data-in-a-wpf-application)

缓存可以将数据存储在内存中以便快速访问。 再次访问数据时，应用程序可以从缓存获取数据，而不是从原始源检索数据。 这可改善性能和可伸缩性。 此外，数据源暂时不可用时，缓存可提供数据。

.NET Framework提供了使你能够使用缓存中的类.NET Framework应用程序。 这些类都位于[System.Runtime.Caching](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.caching)命名空间。

> [System.Runtime.Caching](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.caching)命名空间是中的新增功能.NET Framework 4。 此命名空间使缓存可供所有.NET Framework应用程序。 .NET Framework 以前的版本中，缓存仅在 [System.Web](https://docs.microsoft.com/zh-cn/dotnet/api/system.web) 命名空间可用，因此，需要 ASP.NET 类上的一个依赖项。

本演练演示如何使用缓存功能，现已推出.NET Framework作为的一部分Windows Presentation Foundation (WPF)应用程序。 在本演练中，你将缓存的文本文件的内容。

本演练演示以下任务：

- 创建 WPF 应用程序项目。
- 添加对引用.NET Framework 4。
- 正在初始化缓存。
- 正在添加的缓存项的包含文本文件的内容。
- 提供的缓存项的逐出策略。
- 监视缓存的文件的路径和通知的缓存实例更改为受监视的项目。

### 系统必备

若要完成本演练，你将需要：

- Microsoft Visual Studio 2010。

- 包含少量的文本的文本文件。 （您将显示文本文件的内容在消息框中。）在本演练中所示的代码假定正在使用以下文件：

  `c:\cache\cacheText.txt`

  但是，可以使用任何文本文件，并为本演练中的代码进行微小的更改。

### 创建 WPF 应用程序项目

您将首先创建一个 WPF 应用程序项目。

#### 创建 WPF 应用程序

1. 启动 Visual Studio。

2. 在中**文件**菜单上，单击**新建**，然后单击**新项目**。

   随即显示“新建项目”对话框。

3. 下**已安装的模板**，选择你想要使用的编程语言 (**Visual Basic**或**Visual C#**)。

4. 在中**新的项目**对话框中，选择**WPF 应用程序**。

    备注

   如果没有看到**WPF 应用程序**模板，请确保您的目标版本的.NET Framework支持 WPF。 在中**新的项目**对话框中，选择.NET Framework 4从列表中。

5. 在中**名称**文字框中，输入你的项目的名称。 例如，可以输入**WPFCaching**。

6. 选择“为解决方案创建目录”复选框。

7. 单击 **“确定”**。

   WPF 设计器中打开**设计**查看，并显示 MainWindow.xaml 文件。 Visual Studio 将创建**我的项目**文件夹、 Application.xaml 文件和 MainWindow.xaml 文件。

### 面向.NET Framework 并添加对缓存程序集的引用

默认情况下，WPF 应用程序目标.NET Framework 4 Client Profile。 若要使用[System.Runtime.Caching](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.caching)WPF 应用程序中的命名空间，该应用程序必须面向.NET Framework 4(不.NET Framework 4 Client Profile)，并且必须包括对命名空间的引用。

因此下, 一步将更改.NET Framework 目标，并添加对引用[System.Runtime.Caching](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.caching)命名空间。

> .NET Framework 目标更改的过程是不同的 Visual Basic 项目中并在 Visual C# 项目中。

#### 若要更改的目标在 Visual Basic 中的.NET Framework

1. 在中**解决方案资源管理器**，右键单击项目名称，然后单击**属性**。

   显示应用程序的属性窗口。

2. 单击“编译”选项卡。

3. 在窗口的底部，单击**高级编译选项...**.

   **高级编译器设置**显示对话框。

4. 在中**目标框架 （所有配置）** 列表中，选择.NET Framework 4。 (不要选择.NET Framework 4 Client Profile。)

5. 单击 **“确定”**。

   随即显示“目标框架更改”对话框。

6. 在中**目标 Framework 更改**对话框中，单击**是**。

   项目已关闭，然后重新打开它。

7. 通过执行以下步骤添加对缓存程序集的引用：

   1. 在中**解决方案资源管理器**，右键单击项目的名称，然后单击**添加引用**。
   2. 选择 **.NET**选项卡上，选择`System.Runtime.Caching`，然后单击**确定**。

#### 若要更改 Visual C# 项目中的目标.NET Framework

1. 在中**解决方案资源管理器**，右键单击项目名称，然后单击**属性**。

   显示应用程序的属性窗口。

2. 单击“应用程序” 选项卡。

3. 在中**目标框架**列表中，选择.NET Framework 4。 (不要选择 **.NET Framework 4 Client Profile**。)

4. 通过执行以下步骤添加对缓存程序集的引用：

   1. 右键单击**引用**文件夹，然后单击**添加引用**。
   2. 选择 **.NET**选项卡上，选择`System.Runtime.Caching`，然后单击**确定**。

### 将按钮添加到 WPF 窗口

接下来，您将添加一个按钮控件，并创建为按钮的事件处理程序`Click`事件。 更高版本将添加代码，以便当单击按钮时，缓存并显示文本文件的内容。

#### 若要添加一个按钮控件

1. 在中**解决方案资源管理器**，双击 MainWindow.xaml 文件以将其打开。
2. 从**工具箱**下**常用 WPF 控件**，将`Button`控制对`MainWindow`窗口。
3. 在中**属性**窗口中，将`Content`的属性`Button`控制对**获取缓存**。

### 正在初始化缓存和缓存条目

接下来，将添加代码以执行以下任务：

- 创建缓存类的实例 — 也就是说，您将实例化一个新[MemoryCache](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.caching.memorycache)对象。
- 指定缓存使用[HostFileChangeMonitor](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.caching.hostfilechangemonitor)对象来监视在文本文件中的更改。
- 读取该文本文件并缓存其内容作为缓存项。
- 显示缓存的文本文件的内容。

#### 若要创建缓存对象

1. 双击您只是为了在 MainWindow.xaml.cs 或 MainWindow.Xaml.vb 文件创建一个事件处理程序添加的按钮。

2. （在类声明中） 的文件的顶部添加以下`Imports`(Visual Basic) 或`using`(C#) 语句：

   C#复制

   ```csharp
   using System.Runtime.Caching;
   using System.IO;
   ```

3. 事件处理程序中，添加以下代码以实例化的缓存对象：

   C#复制

   ```csharp
   ObjectCache cache = MemoryCache.Default;
   ```

   [ObjectCache](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.caching.objectcache)类是一个内置的类，提供内存中对象缓存。

4. 添加以下代码以读取内容的名为某个缓存项`filecontents`:

   C#复制

   ```csharp
   string fileContents = cache["filecontents"] as string;
   ```

5. 添加以下代码以检查是否为命名的缓存项`filecontents`存在：

   C#复制

   ```csharp
   if (fileContents == null)
   {
   
   }
   ```

   如果指定的缓存条目不存在，必须读取该文本文件并将其作为某个缓存项添加到缓存。

6. 在中`if/then`块中，添加以下代码以创建一个新[CacheItemPolicy](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.caching.cacheitempolicy)对象，它指定缓存项将在 10 秒后过期。

   C#复制

   ```csharp
   CacheItemPolicy policy = new CacheItemPolicy();
   policy.AbsoluteExpiration = DateTimeOffset.Now.AddSeconds(10.0);
   ```

   如果未不提供任何逐出或过期的信息，默认值是[InfiniteAbsoluteExpiration](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.caching.objectcache.infiniteabsoluteexpiration)，这意味着缓存项永远不会过期时间取决于只有一个绝对时间。 相反，缓存条目过期仅当内存压力时。 作为最佳做法，应始终显式提供绝对或可调到期。

7. 内部`if/then`阻止和上一步中添加的代码，添加以下代码以创建你想要监视，并将文本文件的路径添加到集合的文件路径的集合：

   C#复制

   ```csharp
   List<string> filePaths = new List<string>();
   filePaths.Add("c:\\cache\\cacheText.txt");
   ```

    备注

   如果不是你想要使用的文本文件`c:\cache\cacheText.txt`，指定的文本文件是你想要使用的路径。

8. 在上一步骤中，添加的代码后面添加以下代码以添加新[HostFileChangeMonitor](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.caching.hostfilechangemonitor)到更改的集合对象监视缓存项：

   C#复制

   ```csharp
   policy.ChangeMonitors.Add(new HostFileChangeMonitor(filePaths));
   ```

   [HostFileChangeMonitor](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.caching.hostfilechangemonitor)对象可监视文本文件的路径并通知缓存，如果在发生更改。 在此示例中，如果文件的内容发生更改，将过期的缓存项。

9. 在上一步中添加该代码之后添加以下代码以读取文本文件的内容：

   C#复制

   ```csharp
   fileContents = File.ReadAllText("c:\\cache\\cacheText.txt") + "\n" + DateTime.Now;
   ```

   以便你将能够看到该缓存项过期时添加的日期和时间的时间戳。

10. 在上一步骤中，添加的代码后面添加以下代码以将该文件的内容插入到缓存对象作为[CacheItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.caching.cacheitem)实例：

    C#复制

    ```csharp
    cache.Set("filecontents", fileContents, policy);
    ```

    指定有关如何通过将传递逐出缓存项的信息[CacheItemPolicy](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.caching.cacheitempolicy)作为参数前面创建的对象。

11. 之后`if/then`块中，添加以下代码以在消息框中显示缓存的文件内容：

    C#复制

    ```csharp
    MessageBox.Show(fileContents);
    ```

12. 在中**构建**菜单上，单击**生成 WPFCaching**生成项目。

### 测试在缓存中的 WPF 应用程序

现在可以测试应用程序。

#### 若要测试的 WPF 应用程序中的缓存

1. 按 Ctrl+F5 运行应用程序。

   `MainWindow`显示窗口。

2. 单击**中获取缓存**。

   在消息框中显示文本文件中缓存的内容。 请注意，该文件上的时间戳。

3. 关闭消息框，然后单击**获取缓存**试。

   时间戳保持不变。 这将指示显示缓存的内容。

4. 等待 10 秒或更长，然后单击**获取缓存**试。

   此时将显示新时间戳。 这表示该策略允许缓存项过期，并且将显示新缓存的内容。

5. 在文本编辑器中，打开您创建的文本文件。 不进行任何更改。

6. 关闭消息框，然后单击**获取缓存**试。

   请再次注意时间戳。

7. 对文本文件进行更改，然后保存该文件。

8. 关闭消息框，然后单击**获取缓存**试。

   此消息框包含中的文本文件和新的时间戳的已更新的内容。 这指示主文件的更改监视器逐出缓存项后更改该文件，将立即即使绝对超时时间尚未过期。

    备注

   可以增加到 20 秒或更多用于允许更多时间，以便在文件中进行更改的逐出时间。

### 代码示例

完成本演练后，你创建的项目的代码将类似于下面的示例。

```csharp
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Runtime.Caching;
using System.IO;


namespace WPFCaching
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {

            ObjectCache cache = MemoryCache.Default;
            string fileContents = cache["filecontents"] as string;

            if (fileContents == null)
            {
                CacheItemPolicy policy = new CacheItemPolicy();
                policy.AbsoluteExpiration =
                    DateTimeOffset.Now.AddSeconds(10.0);

                List<string> filePaths = new List<string>();
                filePaths.Add("c:\\cache\\cacheText.txt");

                policy.ChangeMonitors.Add(new
                    HostFileChangeMonitor(filePaths));

                // Fetch the file contents.
                fileContents = File.ReadAllText("c:\\cache\\cacheText.txt") + "\n" + DateTime.Now.ToString();

                cache.Set("filecontents", fileContents, policy);

            }
            MessageBox.Show(fileContents);


        }
    }
}
```