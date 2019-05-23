# [Graphics and Multimedia](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/)

Windows Presentation Foundation (WPF) 为多媒体、 矢量图形、 动画和内容复合，便于开发人员能够生成有趣的用户界面和内容提供支持。 使用 Microsoft Visual Studio，可以创建矢量图形或复杂动画，并将媒体集成到应用程序中。

本主题介绍 WPF 的图形、动画和媒体功能，可用于向应用程序添加图形、转换效果、声音和视频。

 备注

强烈建议不要在 Windows 服务中使用 WPF 类型。 如果尝试在 Windows 服务中使用 WPF 类型，该服务可能无法按预期工作。

## WPF 4 中的图形和多媒体新增功能

进行了与图形和动画相关的多项更改。

- 布局舍入

  当对象边缘落在像素设备中间位置时，与 DPI 无关的图形系统可以创建呈现项目，如模糊或半透明边缘。WPF 的以前版本包含像素捕捉以帮助处理这种情况。 Silverlight 2 引入了布局舍入，这是移动元素以使边缘落在整个像素边界上的另一种方法。 WPF 现在支持与舍入的布局[UseLayoutRounding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.uselayoutrounding)附加属性上[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)。

- 缓存复合

  使用新的[BitmapCache](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.bitmapcache)和[BitmapCacheBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.bitmapcachebrush)类，可以缓存为位图的可视化树的复杂部分并大幅缩短呈现时间。 位图仍然能够响应用户输入（如鼠标单击），并且可以像任何画笔一样将其绘制到其他元素上。

- 像素着色器 3 支持

  WPF 4 生成的[ShaderEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.shadereffect)WPF 3.5 SP1 中引入应用程序使用像素着色器 (PS) 版本 3.0 写入效果，从而支持。PS 3.0 着色器模型比 PS 2.0 更复杂，从而允许在支持的硬件上使用更多效果。

- 缓动函数

  可以使用缓动函数增强动画，从而提供对动画行为的额外控制。 例如，可以应用[ElasticEase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.elasticease)到动画，以提供类似弹簧的行为的动画。 有关详细信息，请参阅中的缓动类型[System.Windows.Media.Animation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation)命名空间。

## 图形和呈现

WPF 引入了对高质量 2-D 图形的支持。 功能包括画笔、几何、图像、形状和转换。 有关详细信息，请参阅[图形](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/graphics)。图形元素的呈现基于[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)类。 屏幕上的视觉对象的结构由可视化树描述。 有关详细信息，请参阅 [WPF 图形呈现概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/wpf-graphics-rendering-overview)。

### 二维形状

WPF 提供常用矢量绘制的 二维 形状库，如下图中所示的矩形和椭圆形。

![椭圆和矩形](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wpfintrofigure4.png)

这些内部 WPF 形状不仅仅是形状：它们是可编程的元素，用于实现常见控件的许多预期功能，包括键盘和鼠标输入。 下面的示例演示如何处理[MouseUp](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouseup)通过单击引发事件[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)元素。

XAML复制

```xaml
<Window  
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"  
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"  
  x:Class="Window1" >  
  <Ellipse Fill="LightBlue" MouseUp="ellipseButton_MouseUp" />  
</Window>  
```

```csharp
public partial class Window1  : Window  
{  
    void ellipseButton_MouseUp(object sender, MouseButtonEventArgs e)  
    {  
        MessageBox.Show("You clicked the ellipse!");  
    }  
}  
```

下图显示前面的 XAML 标记和代码隐藏的输出。

![包含文本“你已单击省略号!”的窗口](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wpfintrofigure12.png)

有关详细信息，请参阅 [WPF 中的形状和基本绘图概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/shapes-and-basic-drawing-in-wpf-overview)。 有关介绍性示例，请参阅[形状元素示例](https://go.microsoft.com/fwlink/?LinkID=160037)。

### 二维几何图形

当 WPF 提供的 二维 形状不足时，可以使用对几何和路径的 WPF 支持来创建自己的形状。 下图显示如何使用几何创建形状作为图形画笔和剪裁其他 WPF 元素。

![Path 的各种用法](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wpfintrofigure5.png)

有关详细信息，请参阅 [Geometry 概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/geometry-overview)。 有关介绍性示例，请参阅 [Geometry 示例](https://go.microsoft.com/fwlink/?LinkID=159989)。

### 二维效果

WPF 提供了 二维 类的库，可用于创建各种效果。 借助 WPF 的 二维 呈现功能，可以绘制具有渐变、位图、绘图和视频的 UI 元素，并且可以使用旋转、缩放和倾斜来操作它们。 下图演提供了可使用 WPF 画笔实现的许多效果的示例。

![不同画笔的图示](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wpfintrofigure6.png)

有关详细信息，请参阅 [WPF 画笔概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/wpf-brushes-overview)。 有关详细信息，请参阅[画笔示例](https://go.microsoft.com/fwlink/?LinkID=159973)。

## 三维呈现

WPF 提供一组 三维 呈现功能，这些功能与 WPF 中的 二维 图形支持集成，以便创建更精彩的布局、UI 和数据可视化。 另一方面，WPF 支持将 二维 图像呈现到 三维 形状的表面，下图演示了此功能。

![Visual3D 示例屏幕快照](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wpfintrofigure13.png)

有关详细信息，请参阅 [三维图形概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/3-d-graphics-overview)。 有关介绍性示例，请参阅 [3-D 实体示例](https://go.microsoft.com/fwlink/?LinkID=159964)。

## 动画

使用动画，可以让控件和元素变大、抖动、旋转和淡出，并创建有趣的转换等。 由于 WPF 支持对大多数属性进行动画处理，因此，不仅可以对大多数 WPF 对象进行动画处理，还可以使用 WPF 对创建的自定义对象进行动画处理。

![具有动画多维数据集的图像](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wpfintrofigure7.png)

有关详细信息，请参阅 [动画概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/animation-overview)。 有关介绍性示例，请参阅[动画示例库](https://go.microsoft.com/fwlink/?LinkID=159969)。

## 媒体

图像、视频和音频是传达信息和用户体验的富媒体方法。

### 图像

图像（包括图标、背景甚至动画部分）是大部分应用程序的核心部分。 由于经常需要使用图像，因此 WPF 公开以各种方式处理它们的功能。 下图显示其中一种方法。

![样式设置示例屏幕截图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/stylingintro-eventtriggers.png)

有关详细信息，请参阅 [图像概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/imaging-overview)。

### 视频和音频

WPF 的图形功能的核心功能是为处理多媒体（包括视频和音频）提供本机支持。 以下示例介绍如何将媒体播放器插入到应用程序中。

```xaml
<MediaElement Source="media\numbers.wmv" Width="450" Height="250" />  
```

[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement) 能够播放视频和音频，并且可扩展，足以允许轻松创建自定义UI。

有关详细信息，请参阅[多媒体概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/multimedia-overview)。