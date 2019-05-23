# [Windows Presentation Foundation](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/index)

Visual Studio 中的 Windows Presentation Foundation (WPF) 为开发人员提供了一个统一的编程模型构建在 Windows 上的业务线桌面应用程序。

[使用 Windows Presentation Foundation 创建桌面应用程序](https://docs.microsoft.com/zh-cn/visualstudio/designers/create-modern-desktop-applications-with-windows-presentation-foundation)

[在 Visual Studio 和 Blend for Visual Studio 中设计 XAML](https://docs.microsoft.com/zh-cn/visualstudio/designers/designing-xaml-in-visual-studio)

[获取 Visual Studio](https://aka.ms/vsdownload?utm_source=mscom&utm_campaign=msdocs)

## Getting Started

Windows Presentation Foundation (WPF) 是一个可创建桌面客户端应用程序的 UI 框架。 

- WPF 开发平台支持广泛的应用程序开发功能，包括应用程序模型、资源、控件、图形、布局、数据绑定、文档和安全性。 
- 它是 .NET Framework 的子集，因此，如果你曾经使用 ASP.NET 或 Windows 窗体通过 .NET Framework 构建应用程序，应该会熟悉此编程体验。 
- WPF 使用可扩展应用程序标记语言 (XAML) 为应用程序编程提供声明性模型。 本节包含 WPF 简介及入门帮助等主题。

从何处开始？

| 我希望直接开始使用…           | [演练：我的第一个 WPF 桌面应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/getting-started/walkthrough-my-first-wpf-desktop-application) |
| ----------------------------- | ------------------------------------------------------------ |
| 如何设计应用程序 UI？         | [在 Visual Studio 中设计 XAML](https://docs.microsoft.com/zh-cn/visualstudio/designers/designing-xaml-in-visual-studio) |
| 是否是初次使用 .NET？         | [.NET Framework 概述](https://msdn.microsoft.com/library/zw4w595w(v=vs.140).aspx)  [.NET Framework 应用程序要点](https://docs.microsoft.com/zh-cn/dotnet/standard/application-essentials)  [Visual C# 和 Visual Basic 入门](https://docs.microsoft.com/zh-cn/visualstudio/ide/getting-started-with-visual-csharp-and-visual-basic) |
| 有关 WPF 的详细信息...        | [Visual Studio 中的 WPF 简介](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/getting-started/introduction-to-wpf-in-vs)  [XAML 概述 (WPF)](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-overview-wpf)  [控件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/index)  [数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview) |
| 是否是 Windows 窗体开发人员？ | [Windows 窗体控件和等效的 WPF 控件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/windows-forms-controls-and-equivalent-wpf-controls)  [WPF 和 Windows 窗体互操作](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/wpf-and-windows-forms-interoperation) |

### Introduction to WPF in Visual Studio

Visual Studio 中的 Windows Presentation Foundation (WPF) 为开发人员提供了一个统一的编程模型构建在 Windows 上的业务线桌面应用程序。

[使用 Windows Presentation Foundation 创建桌面应用程序](https://docs.microsoft.com/zh-cn/visualstudio/designers/create-modern-desktop-applications-with-windows-presentation-foundation)

[在 Visual Studio 和 Blend for Visual Studio 中设计 XAML](https://docs.microsoft.com/zh-cn/visualstudio/designers/designing-xaml-in-visual-studio)

[WPF 介绍](https://docs.microsoft.com/zh-cn/visualstudio/designers/introduction-to-wpf)

[.NET Framework 中的 WPF](https://msdn.microsoft.com/library/ms754130(v=vs.100).aspx)

[获取 Visual Studio](https://aka.ms/vsdownload?utm_source=mscom&utm_campaign=msdocs)

### What's New in WPF Version 4.5

> - [.NET Framework 中的新增功能](https://docs.microsoft.com/zh-cn/dotnet/framework/whats-new/index)

#### 功能区控件

WPF 4.5 附带[Ribbon](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.ribbon.ribbon)承载快速访问工具栏、 应用程序菜单和选项卡的控件。 有关详细信息，请参阅[功能区概述](https://docs.microsoft.com/zh-cn/visualstudio/vsto/ribbon-overview)。

#### 显示大型分组数据集时增强的性能

当根据哪些项在屏幕上可见来从大量数据项中生成用户界面 (UI) 元素的子集时，将发生 UI 虚拟化。[VirtualizingPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingpanel)定义[IsVirtualizingWhenGrouping](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingpanel.isvirtualizingwhengrouping)附加启用 UI 虚拟化分组数据的属性。 有关对数据进行分组的详细信息，请参阅如何：排序和分组数据在 XAML 中使用视图。 有关虚拟化的详细信息分组数据，请参阅[IsVirtualizingWhenGrouping](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingpanel.isvirtualizingwhengrouping)附加属性。

#### VirtualizingPanel 的新增功能

- 您可以指定是否[VirtualizingPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingpanel)，如[VirtualizingStackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel)，通过使用显示部分项[ScrollUnit](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingpanel.scrollunit)附加属性。 如果[ScrollUnit](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingpanel.scrollunit)设置为[Item](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollunit#System_Windows_Controls_ScrollUnit_Item)，则[VirtualizingPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingpanel)将仅显示完全可见的项。 如果[ScrollUnit](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingpanel.scrollunit)设置为[Pixel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollunit#System_Windows_Controls_ScrollUnit_Pixel)，则[VirtualizingPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingpanel)可以显示部分可见的项。
- 您可以指定缓存的大小，视区前后时[VirtualizingPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingpanel)通过使用虚拟化[CacheLength](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingpanel.cachelength)附加属性。 缓存是视区（其中的项未虚拟化）上方或下方的空间量。 使用缓存避免生成 UI 元素（因为系统会将它们滚动到视图中）可以提高性能。 在较低优先级填充缓存，以便应用程序在操作期间能够响应。[VirtualizingPanel.CacheLengthUnit](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingpanel.cachelengthunit)属性确定使用的度量单位[VirtualizingPanel.CacheLength](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingpanel.cachelength)。

#### 绑定到静态属性

可以将静态属性用作数据绑定的源。 如果属性值更改时引发了静态事件，数据绑定引擎将会识别。 例如，如果类 `SomeClass` 定义了名为 `MyProperty` 的静态属性，则 `SomeClass` 可以定义 `MyProperty` 的值发生更改时所引发的静态事件。 静态事件可以使用以下签名之一。

- `public static event EventHandler MyPropertyChanged;`
- `public static event EventHandler<PropertyChangedEventArgs> StaticPropertyChanged;`

请注意，在第一种情况下，类将公开名为的静态事件*PropertyName* `Changed`通过[EventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.eventargs)到事件处理程序。 在第二种情况下，该类会公开名为的静态事件`StaticPropertyChanged`通过[PropertyChangedEventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.propertychangedeventargs)到事件处理程序。 实现静态属性的类可以选择使用任一方法引发属性更改通知。

#### 访问非 UI 线程上的集合

WPF 允许访问和修改线程上的数据集合，创建该集合的线程除外。 这可允许使用后台线程接收来自外部源（例如数据库）的数据，并在 UI 线程上显示该数据。 通过使用另一线程来修改该集合，用户界面将仍可继续响应用户交互。

#### 同步和异步验证数据

[INotifyDataErrorInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.inotifydataerrorinfo)接口使数据实体类能够实现自定义验证规则并以异步方式公开验证结果。 此接口还支持自定义错误对象、每个属性具有多个错误、跨属性错误和实体级别的错误。 有关详细信息，请参阅 [INotifyDataErrorInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.inotifydataerrorinfo)。

#### 自动更新数据绑定源

如果使用数据绑定来更新数据源，则可以使用[Delay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingbase.delay)属性来指定要更新源之前对目标属性发生更改后经过的时间量。 例如，假设您有[Slider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider)具有其[Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.rangebase.value)属性数据双向绑定到数据对象的属性和[UpdateSourceTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.updatesourcetrigger)属性设置为[PropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.updatesourcetrigger#System_Windows_Data_UpdateSourceTrigger_PropertyChanged)。 在此示例中，当用户移动[Slider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider)，每个像素的源更新的[Slider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider)移动。 源对象通常需要滑块的值时，才滑块的[Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.rangebase.value)停止更改。 若要防止对源进行过于频繁更新，请使用[Delay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingbase.delay)指定直到一定的时间结束后在缩略图停止移动不应更新源。

#### 绑定到实现 ICustomTypeProvider 的类型

WPF 支持数据绑定到实现的对象[ICustomTypeProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.icustomtypeprovider)，也称为自定义类型。 在以下情况下，可以使用自定义类型。

- 作为[PropertyPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertypath)在数据绑定。 例如，[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.path)属性的[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)可以引用自定义类型的属性。
- 值作为[DataType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate.datatype)属性。
- 确定自动生成的列中的类型为[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)。

#### 从绑定表达式中检索数据绑定信息

在某些情况下，可能会收到[BindingExpression](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingexpression)的[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)并且需要有关绑定的源和目标对象的信息。 使用已添加新的 API 可获取源或目标对象或关联的属性。 当你具有[BindingExpression](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingexpression)，使用以下 Api 来获取有关目标和源的信息。

| 查找绑定的值                                                 | 使用此 API                                                   |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| 目标对象                                                     | [BindingExpressionBase.Target](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingexpressionbase.target) |
| 目标属性                                                     | [BindingExpressionBase.TargetProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingexpressionbase.targetproperty) |
| 源对象                                                       | [BindingExpression.ResolvedSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingexpression.resolvedsource) |
| 源属性                                                       | [BindingExpression.ResolvedSourcePropertyName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingexpression.resolvedsourcepropertyname) |
| 是否[BindingExpression](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingexpression)属于 [BindingGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindinggroup) | [BindingExpressionBase.BindingGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingexpressionbase.bindinggroup) |
| 所有者 [BindingGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindinggroup) | [Owner](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindinggroup.owner) |

#### 检查有效的 DataContext 对象

某些情况下，[DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext)中的项容器的[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)断开连接。 项容器是显示中的项的 UI 元素[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)。 当[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)是数据绑定到集合时，项容器为每个项生成。 在某些情况下，会从可视化树中删除项容器。 其中删除一个项容器的两种典型情况是从基础集合删除项的时间和当在上启用虚拟化[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)。 在这些情况下，[DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext)项容器的属性将设置为返回的 sentinel 对象[BindingOperations.DisconnectedSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingoperations.disconnectedsource)静态属性。 应检查是否[DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext)等同于[DisconnectedSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingoperations.disconnectedsource)然后才能访问对象[DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext)的项容器。

#### 在数据值发生更改时重新定位数据（实时数据整理）

可以对数据集合进行分组、排序或筛选。 WPF 4.5 允许在修改数据时重新排列数据。 例如，假设应用程序使用[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)列出股票市场中的股票和股票按股票值。 如果在股票的上启用实时排序[CollectionView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionview)中的股票的位置[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)移动时的股票值将成为更高版本或小于另一个股票的值。 有关详细信息，请参阅[ICollectionViewLiveShaping](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.icollectionviewliveshaping)接口。

#### 对建立事件的弱引用的增强支持

现在实现弱事件模式更加容易，因为可以借助事件的订阅服务器并且无需实现附加接口。 泛型[WeakEventManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.weakeventmanager)类还可使订阅服务器参与弱事件模式，如果专用[WeakEventManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.weakeventmanager)不存在特定事件。 有关详细信息，请参阅[弱事件模式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/weak-event-patterns)。

#### 用于调度程序类的新方法

调度程序类定义同步和异步操作的新方法。 同步[Invoke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher.invoke)方法定义采用重载[Action](https://docs.microsoft.com/zh-cn/dotnet/api/system.action)或[Func](https://docs.microsoft.com/zh-cn/dotnet/api/system.func-1)参数。 新的异步方法， [InvokeAsync](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher.invokeasync)，还会[Action](https://docs.microsoft.com/zh-cn/dotnet/api/system.action)或[Func](https://docs.microsoft.com/zh-cn/dotnet/api/system.func-1)作为回调参数并返回[DispatcherOperation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcheroperation)或[DispatcherOperation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcheroperation-1)。 [DispatcherOperation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcheroperation)并[DispatcherOperation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcheroperation-1)类定义[Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task)属性。 当您调用[InvokeAsync](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher.invokeasync)，可以使用`await`使用的关键字[DispatcherOperation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcheroperation)或关联[Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task)。 如果你需要同步等待[Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task)返回的[DispatcherOperation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcheroperation)或[DispatcherOperation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcheroperation-1)，调用[DispatcherOperationWait](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.taskextensions.dispatcheroperationwait)扩展方法。 调用[Task.Wait](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task.wait)在调用线程上排队操作将导致死锁。 有关使用详细信息[Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task)若要执行异步操作，请参阅[任务并行 （任务并行库）](https://docs.microsoft.com/zh-cn/dotnet/standard/parallel-programming/task-based-asynchronous-programming)。

#### 事件的标记扩展

WPF 4.5 支持事件的标记扩展。 虽然 WPF 未定义用于事件的标记扩展，但第三方能够创建可与事件配合使用的标记扩展。

### Walkthrough: My first WPF desktop application

#### 系统必备

- Visual Studio 2017 或更高版本

#### 创建应用程序项目

第一步是创建应用程序基础结构，其中包括应用程序定义，两个页面和一个图像。

- 在 Visual Basic 或 Visual C# 名为创建新的 WPF 应用程序项目

![](01 Getting Started/images/01.png)

Visual Studio 创建项目并打开名为的默认应用程序窗口的设计器**MainWindow.xaml**。

> 本演练使用[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)在.NET Framework 4 和更高版本的控件。 为确保你的项目面向.NET Framework 4 或更高版本。 有关更多信息，请参见[如何：面向.NET Framework 的版本](https://docs.microsoft.com/zh-cn/visualstudio/ide/how-to-target-a-version-of-the-dotnet-framework)。

- 打开*Application.xaml* (Visual Basic) 或*App.xaml* (C#)

C#中

```xaml
<Application x:Class="_03_Walkthrough_My_first_WPF_desktop_application.App"
             xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
             xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
             xmlns:local="clr-namespace:_03_Walkthrough_My_first_WPF_desktop_application"
             StartupUri="MainWindow.xaml">
    <Application.Resources>
         
    </Application.Resources>
</Application>
```

- 打开*MainWindow.xaml*

![](01 Getting Started/images/02.png)

此 XAML 文件是你的应用程序的主窗口，并显示在页面中创建的内容。 [Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)类定义的属性窗口中，例如其标题、 大小或图标，并处理事件，例如关闭或隐藏。

- 更改[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)元素[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)，如以下 XAML 所示：

![](01 Getting Started/images/03.png)

此应用程序中导航到不同的内容，具体取决于用户输入。 这就是为什么主要[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)需要更改为[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)。 [NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow) 继承的所有属性[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)。 [NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow) XAML 文件中的元素创建的实例[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)类。 有关详细信息，请参阅[导航概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/navigation-overview)。

- 更改以下属性上[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)元素
  - 设置[Title](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window.title)属性设置为"`ExpenseIt`"。
  - 设置[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)属性设置为 500 像素。
  - 设置[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)属性设置为 350 像素。
  - 删除[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)之间的元素[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)标记。

```xaml
<NavigationWindow x:Class="_03_Walkthrough_My_first_WPF_desktop_application.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
        xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
        xmlns:local="clr-namespace:_03_Walkthrough_My_first_WPF_desktop_application"
        mc:Ignorable="d"
        Title="ExpenseIt" Height="500" Width="350">
</NavigationWindow>
```

- 打开*MainWindow.xaml.vb*或*MainWindow.xaml.cs*。
  - 此文件是包含代码来处理中声明的事件的代码隐藏文件*MainWindow.xaml*。 此文件包含在 XAML 中定义的窗口的分部类。

```c#
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace _03_Walkthrough_My_first_WPF_desktop_application
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : NavigationWindow
    {
        public MainWindow()
        {
            InitializeComponent();
        }
    }
}
```

#### 将文件添加到应用程序
本部分将向应用程序添加两个页面和一个图像。
- 将新的 WPF 页添加到项目中，并将其命名 *ExpenseItHome.xaml*

![](01 Getting Started/images/04.png)
- 打开 *ExpenseItHome.xaml*
- 设置[Title](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page.title)到"`ExpenseIt - Home`"
```c#
<Page x:Class="_03_Walkthrough_My_first_WPF_desktop_application.ExpenseItHome"
      xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006" 
      xmlns:d="http://schemas.microsoft.com/expression/blend/2008" 
      xmlns:local="clr-namespace:_03_Walkthrough_My_first_WPF_desktop_application"
      mc:Ignorable="d" 
      d:DesignHeight="450" d:DesignWidth="800"
      Title="ExpenseItHome">

    <Grid>
        
    </Grid>
</Page>

```
- 打开*MainWindow.xaml*。
- 设置[Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow.source)上的属性[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)到"`ExpenseItHome.xaml`"。

![](01 Getting Started/images/05.png)
```xaml
<NavigationWindow x:Class="_03_Walkthrough_My_first_WPF_desktop_application.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
        xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
        xmlns:local="clr-namespace:_03_Walkthrough_My_first_WPF_desktop_application"
        mc:Ignorable="d"
        Title="ExpenseIt" Height="350" Width="500" Source="ExpenseItHome.xaml">
</NavigationWindow>
```
- 将另一个新的 WPF 页添加到项目中，并将其命名*ExpenseReportPage.xaml*::
  - 此页会显示费用报表上选择的人员 **ExpenseItHome** 页
- 打开 *ExpenseReportPage.xaml*。
- 设置[Title](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page.title)到"`ExpenseIt - View Expense`"。
```xaml
<Page x:Class="_03_Walkthrough_My_first_WPF_desktop_application.ExpenseReportPage"
      xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006" 
      xmlns:d="http://schemas.microsoft.com/expression/blend/2008" 
      xmlns:local="clr-namespace:_03_Walkthrough_My_first_WPF_desktop_application"
      mc:Ignorable="d" 
      d:DesignHeight="450" d:DesignWidth="800"
      Title="ExpenseIt - View Expense">

    <Grid>
        
    </Grid>
</Page>

```

- 打开``ExpenseItHome.xaml.cs`和`ExpenseReportPage.xaml.cs`.

```c#
// ExpenseItHome.xaml.cs
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace _03_Walkthrough_My_first_WPF_desktop_application
{
    /// <summary>
    /// Interaction logic for ExpenseItHome.xaml
    /// </summary>
    public partial class ExpenseItHome : Page
    {
        public ExpenseItHome()
        {
            InitializeComponent();
        }
    }
}
```

```c#
// ExpenseReportPage.xaml.cs
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace _03_Walkthrough_My_first_WPF_desktop_application
{
    /// <summary>
    /// Interaction logic for ExpenseReportPage.xaml
    /// </summary>
    public partial class ExpenseReportPage : Page
    {
        public ExpenseReportPage()
        {
            InitializeComponent();
        }
    }
}
```

- 添加名为图像*watermark.png*到项目。 可以创建自己的映像、 将文件从示例代码中，或获取它[此处](https://github.com/dotnet/docs/blob/master/docs/framework/wpf/getting-started/media/watermark.png)

#### 编译和运行应用程序
- 若要生成并运行应用程序，按**F5**或选择**开始调试**从**调试**菜单
![](01 Getting Started/images/06.png)

#### 创建布局
布局提供有序的方式来放置 UI 元素，并调整 UI 时还管理的大小和这些元素的位置。 
通常使用以下布局控件之一来创建布局：

- [Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)
- [DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)
- [Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)
- [StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)
- [VirtualizingStackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel)
- [WrapPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.wrappanel)

每个布局控件都为子元素支持特殊类型的布局。 `ExpenseIt` 页面可进行调整，但每个页面不水平或垂直排列以及其他元素的元素。 因此，[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)是应用程序的理想布局元素。

> 有关详细信息[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)元素，请参阅[面板概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/panels-overview)。 有关布局的详细信息，请参阅[布局](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/layout)。

在部分中，您创建的单列表包含三个行和 10 像素边距添加到的列和行定义[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)中 *ExpenseItHome.xaml* 。

- 打开 *ExpenseItHome.xaml* 。
- 设置[Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)属性上的[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)"10,0,10,10"，对应于左侧、 顶部、 右侧和底部边距的元素：

```xaml
<Page x:Class="_03_Walkthrough_My_first_WPF_desktop_application.ExpenseItHome"
      xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006" 
      xmlns:d="http://schemas.microsoft.com/expression/blend/2008" 
      xmlns:local="clr-namespace:_03_Walkthrough_My_first_WPF_desktop_application"
      mc:Ignorable="d" 
      d:DesignHeight="450" d:DesignWidth="800"
      Title="ExpenseItHome">

    <Grid Margin="10,0,10,10">
        
    </Grid>
</Page>
```

![](01 Getting Started/images/07.png)

- 添加以下 XAML 之间[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)标记以创建行和列定义：
  - Height的两个行设置为Auto，这意味着行大小将调整根据行中的内容。 
  - 默认值Height是Star大小调整，这意味着行的高度可用空间的加权的比例。 
  - 例如，如果两个行具有Height的"*"，它们都有高度将会是可用空间的一半。

你Grid现在应如以下 XAML 所示：
```xaml
    <Grid Margin="10,0,10,10">
        <Grid.ColumnDefinitions>
            <ColumnDefinition>
            </ColumnDefinition>
        </Grid.ColumnDefinitions>
        <Grid.RowDefinitions>
            <RowDefinition Height="Auto">
            </RowDefinition>
            <RowDefinition>
            </RowDefinition>
            <RowDefinition Height="Auto">
            </RowDefinition>
        </Grid.RowDefinitions>
    </Grid>
```

#### 添加控件

在本部分中，将更新主页 UI 以显示一个用户可以选择从以显示费用报表的人员列表。 控件是允许用户与应用程序交互的 UI 对象。 有关详细信息，请参阅 [控件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/index)。

若要创建此 UI，将添加到以下元素 *ExpenseItHome.xaml* :

- [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) （用于人员列表）。
- [Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label) （用于列表标题）。
- [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) （若要单击以查看费用报表的列表中选择的人员）。

每个控件的某一行中放置[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)通过设置[Grid.Row](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid.row)附加属性。 有关附加属性的详细信息，请参阅[附加属性概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/attached-properties-overview)。

- 打开 *ExpenseItHome.xaml*
- 添加以下 XAML 某处之间[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)标记：

```xaml
<!-- People list -->
  <Border Grid.Column="0" Grid.Row="0" Height="35" Padding="5" Background="#4E87D4">
      <Label VerticalAlignment="Center" Foreground="White">Names</Label>
  </Border>
  <ListBox Name="peopleListBox" Grid.Column="0" Grid.Row="1">
      <ListBoxItem>Mike</ListBoxItem>
      <ListBoxItem>Lisa</ListBoxItem>
      <ListBoxItem>John</ListBoxItem>
      <ListBoxItem>Mary</ListBoxItem>
  </ListBox>

  <!-- View report button -->
  <Button Grid.Column="0" Grid.Row="2" Margin="0,10,0,0" Width="125"
Height="25" HorizontalAlignment="Right">View</Button>
```

> 此外可以通过将其从拖动来创建控件**工具箱**窗口拖到设计窗口中，然后设置其属性**属性**窗口。

