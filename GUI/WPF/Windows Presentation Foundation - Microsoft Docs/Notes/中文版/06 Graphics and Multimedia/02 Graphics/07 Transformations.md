# [Transformations](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/transformations)

使用转换来旋转、 缩放、 转换或倾斜[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)对象。

## 本节内容

[转换概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/transforms-overview)
[帮助主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/transformations-how-to-topics)

## [Transforms Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/transforms-overview)

本主题介绍如何使用二维[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transform)类来旋转、 缩放、 移动 （转换） 和倾斜[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)对象。

### 什么是 Transform？

一个[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transform)定义映射或转换到另一个坐标空间从一个坐标空间点的方式。 此映射由转换描述[Matrix](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.matrix)，它是三列的三个行集合[Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double)值。

> Windows Presentation Foundation (WPF) 使用行主序矩阵。 矢量表示为行矢量，而非列矢量。

下表显示了 WPF 矩阵的结构。

#### 2-D 转换矩阵

|                                                              |                                                              |      |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ---- |
| [M11](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.matrix.m11)  默认：1.0 | [M12](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.matrix.m12)  默认：0.0 | 0.0  |
| [M21](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.matrix.m21)  默认：0.0 | [M22](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.matrix.m22)  默认：1.0 | 0.0  |
| [OffsetX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.matrix.offsetx)  默认：0.0 | [OffsetY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.matrix.offsety)  默认：0.0 | 1.0  |

通过操作矩阵值，可以旋转、缩放、倾斜和移动（转换）对象。 例如，如果更改第三行的第一列中的值 ([OffsetX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.matrix.offsetx)值) 为 100，可用它来将移动沿 x 轴对象 100 单位。 如果将第二行第二列中的值更改为 3，可使用它来将对象的当前高度拉伸三倍。 如果同时更改这两个值，将使对象沿 x 轴移动 100 个单位，并将其高度拉伸 3 倍。 因为 Windows Presentation Foundation (WPF) 仅支持仿射转换，右侧的列中的值始终是 0，0，1。

尽管 Windows Presentation Foundation (WPF) 使你能够直接操作矩阵值，但它还提供了许多[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transform)使你无需知道基础矩阵结构的配置方式转换对象的类。 例如，[ScaleTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform)类，您可以通过设置缩放对象及其[ScaleX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform.scalex)和[ScaleY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform.scaley)属性，而不是操作转换矩阵。 同样，[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)类使您能够只需设置旋转对象及其[Angle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform.angle)属性。

### 转换类

Windows Presentation Foundation (WPF) 提供了以下二维[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transform)用于常见转换操作的类：

| 类                                                           | 描述                                                         | 示例                                                         | 图示                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| [RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform) | 通过指定旋转元素[Angle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform.angle)。 | [旋转对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-rotate-an-object) | ![旋转图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-thumbnails-rotate.png) |
| [ScaleTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform) | 通过指定缩放元素[ScaleX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform.scalex)和[ScaleY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform.scaley)金额。 | [缩放元素](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-scale-an-element) | ![缩放图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-thumbnails-scale.png) |
| [SkewTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.skewtransform) | 通过指定扭曲元素[AngleX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.skewtransform.anglex)和[AngleY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.skewtransform.angley)金额。 | [倾斜元素](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-skew-an-element) | ![倾斜图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-thumbnails-skew.png) |
| [TranslateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform) | 将移动 （转换） 由指定的元素[X](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform.x)和[Y](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform.y)金额。 | [转换元素](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-translate-an-element) | ![转换图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-thumbnails-translate.png) |

有关如何创建更复杂的转换，Windows Presentation Foundation (WPF) 提供了以下两个类：

| 类                                                           | 描述                                                         | 示例                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| [TransformGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transformgroup) | 分组多个[TransformGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transformgroup)到单个对象[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transform)，你可以然后应用它来转换属性。 | [将多个转换应用到对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-apply-multiple-transforms-to-an-object) |
| [MatrixTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.matrixtransform) | 创建自定义的转换不提供由其他的[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transform)类。 当你使用[MatrixTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.matrixtransform)，直接操作矩阵。 | [使用 MatrixTransform 创建自定义转换](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-use-a-matrixtransform-to-create-custom-transforms) |

Windows Presentation Foundation (WPF) 还提供了三维转换。 有关更多信息，请参见 [Transform3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.transform3d) 类。

### 常见转换属性

转换对象的一种方法是声明相应[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transform)类型并将其应用到该对象的转换属性。 对象类型不同，转换属性的类型也会不同。 下表列出了几种常用的 Windows Presentation Foundation (WPF) 类型及其转换属性。

| 类型                                                         | 转换属性                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush) | [Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.transform)， [RelativeTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.relativetransform) |
| [ContainerVisual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.containervisual) | [Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.containervisual.transform) |
| [DrawingGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawinggroup) | [Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawinggroup.transform) |
| [FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement) | [RenderTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransform)， [LayoutTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.layouttransform) |
| [Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry) | [Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry.transform) |
| [TextEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.texteffect) | [Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.texteffect.transform) |
| [UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement) | [RenderTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransform) |

### 转换和坐标系

转换对象时，不只是转换对象，还会转换该对象所在的坐标空间。 默认情况下，转换以在目标对象的坐标系统的原点为中心：(0,0). 唯一的例外是[TranslateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform);[TranslateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform)没有中心属性可供设置，因为转换效果无论是相同的居中位置。

下面的示例使用[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)旋转[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)元素中，一种类型的[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)，旋转 45 度围绕默认中心 （0，0）。 下图显示了旋转效果。

![FrameworkElement 旋转 45 度的有关(0，0)](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-fe-rotated-about-upperleft-corner.png)
围绕点 (0,0) 旋转 45 度的矩形元素

```xaml
<Canvas Width="200" Height="200">
  <Rectangle 
    Canvas.Left="100" Canvas.Top="100"
    Width="50" Height="50" 
    Fill="RoyalBlue" Opacity="1.0">
    <Rectangle.RenderTransform>
      <RotateTransform Angle="45" />
    </Rectangle.RenderTransform>
  </Rectangle>
</Canvas>
```

默认情况下，元素会围绕其左上角 (0, 0) 旋转。 [RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)， [ScaleTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform)，和[SkewTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.skewtransform)类提供 CenterX 和 CenterY 属性，您可以指定在其中应用转换的点。

下面的示例也使用[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)旋转[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)元素旋转 45 度; 但是，这一次[CenterX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform.centerx)并[CenterY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform.centery)属性设置，以便[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)为中心 （25，25）。 下图显示了旋转效果。

![有关旋转 45 度的几何图形(25，25)](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-fe-rotated-about-center.png)
围绕点 (25, 25) 旋转 45 度矩形元素

```xaml
<Canvas Width="200" Height="200">
  <Rectangle 
    Canvas.Left="100" Canvas.Top="100"
    Width="50" Height="50" 
    Fill="RoyalBlue" Opacity="1.0">
    <Rectangle.RenderTransform>
      <RotateTransform Angle="45" CenterX="25" CenterY="25" />
    </Rectangle.RenderTransform>
  </Rectangle>
</Canvas>
```

### 转换 FrameworkElement

若要将变换应用于[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)，创建[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transform)并将其应用到两个属性之一的[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)类提供了：

- [LayoutTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.layouttransform) – 一个转换，该布局处理过程前应用了。 转换应用后，布局系统处理元素转换后的大小和位置。
- [RenderTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransform) – 一个转换，修改元素的外观，但在布局处理过程完成后应用。 通过使用[RenderTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransform)属性，而不是[LayoutTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.layouttransform)属性，可获得性能优势。

应使用哪个属性？ 因为它提供性能优势，使用[RenderTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransform)属性可能的尤其是当您使用动画时[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transform)对象。 使用[LayoutTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.layouttransform)属性时缩放、 旋转或扭曲，并且需要对转换后的元素大小调整元素的父级。 请注意，当一起使用时[LayoutTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.layouttransform)属性，[TranslateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform)对象显示为具有对元素没有影响。 这是因为布局系统将转换后的元素返回到其原始位置作为其处理的一部分。

有关 Windows Presentation Foundation (WPF) 中布局的其他信息，请参阅[布局](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/layout)概述。

### 示例:将 FrameworkElement 旋转 45 度

下面的示例使用[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)若要将按钮顺时针旋转 45 度。 按钮包含在[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)，有两个其他按钮。

默认情况下，[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)将围绕点 （0，0） 旋转。 由于示例未指定中心点值，按钮将围绕点 (0, 0) 旋转，即其左上角。 [RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)应用于[RenderTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransform)属性。 下图显示转换的结果。

![使用 RenderTransform 转换的按钮](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-rendertransformwithdefaultcenter.png)
从左上角顺时针旋转 45 度

```xaml
<Border Margin="30" 
  HorizontalAlignment="Left" VerticalAlignment="Top"
  BorderBrush="Black" BorderThickness="1" >
  <StackPanel Orientation="Vertical">
    <Button Content="A Button" Opacity="1" />
    <Button Content="Rotated Button">
      <Button.RenderTransform>
        <RotateTransform Angle="45" />
      </Button.RenderTransform>
    </Button>
    <Button Content="A Button" Opacity="1" />
  </StackPanel>
</Border>
```

下面的示例也使用[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)旋转 45 度顺时针旋转，一个按钮，但它还设置[RenderTransformOrigin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransformorigin)到按钮的 （0.5，0.5）。 值[RenderTransformOrigin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransformorigin)属性是相对于按钮的大小。 因此，该旋转应用到按钮的中心，而非左上角。 下图显示转换的结果。

![围绕中心转换后的按钮](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-rendertransformrelativecenter.png)
围绕中心顺时针旋转 45 度

```xaml
<Border Margin="30"   
  HorizontalAlignment="Left" VerticalAlignment="Top"
  BorderBrush="Black" BorderThickness="1">
  <StackPanel Orientation="Vertical">
    <Button Content="A Button" Opacity="1" />
    <Button Content="Rotated Button"
      RenderTransformOrigin="0.5,0.5">
      <Button.RenderTransform>
        <RotateTransform Angle="45" />
      </Button.RenderTransform>
    </Button>
    <Button Content="A Button" Opacity="1" />
  </StackPanel>
</Border>
```

下面的示例使用[LayoutTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.layouttransform)属性，而不是[RenderTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransform)属性来旋转按钮。 这将导致转换影响按钮的布局，从而触发布局系统的整个处理过程。 因此，按钮在旋转后重新定位，因为它的大小已更改。 下图显示转换的结果。

![使用 LayoutTransform 转换的按钮](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-layouttransform.png)
用于旋转按钮的 LayoutTransform

```xaml
<Border Margin="30"   
 HorizontalAlignment="Left" VerticalAlignment="Top"
 BorderBrush="Black" BorderThickness="1">
  <StackPanel Orientation="Vertical">

    <Button Content="A Button" Opacity="1" />   
    <Button Content="Rotated Button">
      <Button.LayoutTransform>
        <RotateTransform Angle="45"  />
      </Button.LayoutTransform>
    </Button>   
    <Button Content="A Button" Opacity="1" />
  </StackPanel>
</Border>
```

### 对转换进行动画处理

由于它们继承自[Animatable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animatable)类，[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transform)类可进行动画处理。 若要进行动画处理[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transform)，为兼容类型的动画应用于要进行动画处理的属性。

下面的示例使用[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)和一个[DoubleAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation)与[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)使[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)数值调节钮中单击它时就位。

```xaml
<Page 
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  Title="Button Animated RotateTransform Example"
  Background="White" Margin="50">
  <StackPanel>
    
    

    <Button Content="A Button"
      RenderTransformOrigin="0.5,0.5">
      <Button.RenderTransform>
        <RotateTransform x:Name="AnimatedRotateTransform" Angle="0" />
      </Button.RenderTransform>
      <Button.Triggers>
        <EventTrigger RoutedEvent="Button.Click">
          <BeginStoryboard>
            <Storyboard>
              <DoubleAnimation 
                Storyboard.TargetName="AnimatedRotateTransform"
                Storyboard.TargetProperty="Angle" 
                To="360" Duration="0:0:1" FillBehavior="Stop" />
            </Storyboard>
          </BeginStoryboard>
        </EventTrigger>
      </Button.Triggers>
    </Button>

  </StackPanel>
</Page>
```

有关完整示例，请参阅 [2D 转换示例](https://go.microsoft.com/fwlink/?LinkID=158252)。 有关动画的详细信息，请参阅[动画概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/animation-overview)。

### Freezable 功能

因为它继承自[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)类，[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transform)类提供多种特殊功能：[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transform)对象可声明为[资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-resources)、 在多个对象，变为只读以提高共享性能、 克隆以及变为线程安全。 有关由提供的不同功能的详细信息[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)对象，请参阅[Freezable 对象概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/freezable-objects-overview)。

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/transformations-how-to-topics)

在本部分中的主题介绍如何将不同的转换应用于对象。

### 本节内容

[在事件发生时向元素应用转换](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-apply-a-transform-to-an-element-when-an-event-occurs)
[将多个转换应用到对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-apply-multiple-transforms-to-an-object)
[让元素原地旋转](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-make-an-element-spin-in-place)
[旋转对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-rotate-an-object)
[缩放元素](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-scale-an-element)
[倾斜元素](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-skew-an-element)
[使用相对值指定转换原点](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-specify-the-origin-of-a-transform-by-using-relative-values)
[转换元素](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-translate-an-element)
[使用 MatrixTransform 创建自定义转换](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-use-a-matrixtransform-to-create-custom-transforms)

### [Apply a Transform to an Element When an Event Occurs](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-apply-a-transform-to-an-element-when-an-event-occurs)

此示例演示如何将应用[ScaleTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform)事件的发生时间。 此处说明的概念与用于应用其他类型的转换的概念相同。有关可用类型的转换的详细信息，请参阅[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transform)类或[转换概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/transforms-overview)。

可以通过以下两种方式之一向元素应用转换：

- 如果这样做*不*希望转换影响布局，请使用[RenderTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransform)元素的属性。
- 如果您希望转换影响布局，使用[LayoutTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.layouttransform)元素的属性。

下面的示例应用[ScaleTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform)到[RenderTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransform)按钮的属性。 当鼠标在按钮上移[ScaleX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform.scalex)和[ScaleY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform.scaley)的属性[ScaleTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform)设置为`2`，这会导致该按钮会变得更大。 当鼠标离开按钮时，[ScaleX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform.scalex)并[ScaleY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform.scaley)设置为`1`，这会导致按钮返回到其原始大小。

#### 示例

```xaml
<Page  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  x:Class="WCSample.TransformExample"
  WindowTitle="Transform on Mouse Enter Example">
  <Canvas Width="400" Height="400">

    <Button Name="Button1" MouseEnter="Enter" MouseLeave="Leave">
      <Button.RenderTransform>
        <ScaleTransform x:Name="myScaleTransform" ScaleX="1" ScaleY="1" />
      </Button.RenderTransform>
      Button
    </Button>


  </Canvas>
</Page>
```

```csharp
public partial class TransformExample : Page {
  private void Enter(object sender, MouseEventArgs args) {
      myScaleTransform.ScaleX = 2;
      myScaleTransform.ScaleY = 2;
  }

  private void Leave(object sender, MouseEventArgs args) {
      myScaleTransform.ScaleX = 1;
      myScaleTransform.ScaleY = 1;
  }
}
```

### [Apply Multiple Transforms to an Object](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-apply-multiple-transforms-to-an-object)

此示例演示如何使用[TransformGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transformgroup)到两个或多个组[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transform)合并为一个复合对象[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transform)。

#### 示例

下面的示例使用[TransformGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transformgroup)以应用[ScaleTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform)和一个[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)到[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。

```xaml
<Page 
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml" >
  <StackPanel Margin="50">

      <Button 
        RenderTransformOrigin="0.5,0.5"
        HorizontalAlignment="Center">Click
        <Button.RenderTransform>

          <!-- TransformGroup enables you to apply multiple transforms. In 
               this example, the button is scaled and rotated. -->
          <TransformGroup>

            <!-- Triple the size (scale) of the button in the Y direction. -->
            <ScaleTransform ScaleY="3" />

            <!-- Rotate the button by 45 degrees. -->
            <RotateTransform Angle="45" />
            
          </TransformGroup>
        </Button.RenderTransform>
      </Button>
    
  </StackPanel>
</Page>
```

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;

namespace SDKSample
{
    public partial class MultipleTransformsExample : Page
    {
        public MultipleTransformsExample()
        {
            // Create a Button that will have two transforms applied to it.
            Button myButton = new Button();
            myButton.Content = "Click";
            
            // Set the center point of the transforms.
            myButton.RenderTransformOrigin = new Point(0.5,0.5);

            // Create a transform to scale the size of the button.
            ScaleTransform myScaleTransform = new ScaleTransform();

            // Set the transform to triple the scale in the Y direction.
            myScaleTransform.ScaleY = 3;

            // Create a transform to rotate the button
            RotateTransform myRotateTransform = new RotateTransform();

            // Set the rotation of the transform to 45 degrees.
            myRotateTransform.Angle = 45;

            // Create a TransformGroup to contain the transforms
            // and add the transforms to it.
            TransformGroup myTransformGroup = new TransformGroup();
            myTransformGroup.Children.Add(myScaleTransform);
            myTransformGroup.Children.Add(myRotateTransform);

            // Associate the transforms to the button.
            myButton.RenderTransform = myTransformGroup;

            // Create a StackPanel which will contain the Button.
            StackPanel myStackPanel = new StackPanel();
            myStackPanel.Margin = new Thickness(50);
            myStackPanel.Children.Add(myButton);
            this.Content = myStackPanel;

        }
    }
}
```

### [Make an Element Spin in Place](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-make-an-element-spin-in-place)

此示例演示如何使某个元素通过使用旋转[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)和一个[DoubleAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation)。

下面的示例应用[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)到[RenderTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransform)元素的属性。 该示例使用[DoubleAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation)进行动画处理[Angle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform.angle)的[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)。 若要使元素就地旋转，该示例设置[RenderTransformOrigin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransformorigin)到点 （0.5，0.5） 元素的属性。

#### 示例

```xaml
<!-- RotateAboutCenterExample.xaml
     This example shows how to make an element spin
     about its center. -->
<Page 
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  x:Class="Microsoft.Samples.Animation.RotateAboutCenterExample" 
  WindowTitle="Rotate About Center Example">    
  <StackPanel Margin="50">
    
    <Button
      RenderTransformOrigin="0.5,0.5"
      HorizontalAlignment="Left">
        Hello,World
      <Button.RenderTransform>
        <RotateTransform x:Name="MyAnimatedTransform" Angle="0" />
      </Button.RenderTransform>
      <Button.Triggers>
        <EventTrigger RoutedEvent="Button.Click">
          <BeginStoryboard>
            <Storyboard>
              <DoubleAnimation
                Storyboard.TargetName="MyAnimatedTransform"
                Storyboard.TargetProperty="(RotateTransform.Angle)"
                From="0.0" To="360" Duration="0:0:1" />
            </Storyboard>
          </BeginStoryboard>
        </EventTrigger>
      </Button.Triggers>
    </Button> 
  </StackPanel> 
</Page>
```

有关完整示例，其中包括转换的更多示例，请参阅[2d 转换示例](https://go.microsoft.com/fwlink/?LinkID=158252)。

### [Rotate an Object](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-rotate-an-object)

此示例演示如何旋转对象。 该示例首先创建[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)，然后指定其[Angle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform.angle)以度为单位。

下面的示例将旋转[Polyline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.polyline)对象围绕其左上角的 45 度。

#### 示例

```xaml
<Canvas Height="200" Width="200">

  <!-- Rotates the Polyline 45 degrees about the point (0,0). -->
  <Polyline Points="25,25 0,50 25,75 50,50 25,25 25,0" 
    Stroke="Blue" StrokeThickness="10"
    Canvas.Left="75" Canvas.Top="50">
    <Polyline.RenderTransform>
      <RotateTransform CenterX="0" CenterY="0" Angle="45" />
    </Polyline.RenderTransform>
  </Polyline>
</Canvas>
```

```csharp
// Create a Polyline.
Polyline polyline1 = new Polyline();
polyline1.Points.Add(new Point(25, 25));
polyline1.Points.Add(new Point(0, 50));
polyline1.Points.Add(new Point(25, 75));
polyline1.Points.Add(new Point(50, 50));
polyline1.Points.Add(new Point(25, 25));
polyline1.Points.Add(new Point(25, 0));
polyline1.Stroke = Brushes.Blue;
polyline1.StrokeThickness = 10;

// Create a RotateTransform to rotate
// the Polyline 45 degrees about its
// top-left corner.
RotateTransform rotateTransform1 =
    new RotateTransform(45);
polyline1.RenderTransform = rotateTransform1;

// Create a Canvas to contain the Polyline.
Canvas canvas1 = new Canvas();
canvas1.Width = 200;
canvas1.Height = 200;
Canvas.SetLeft(polyline1, 75);
Canvas.SetTop(polyline1, 50);
canvas1.Children.Add(polyline1);
```

[CenterX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform.centerx)并[CenterY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform.centery)的属性[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)指定哪些对象的旋转的点。 此中心点以要转换的元素的坐标空间表示。默认情况下，将围绕着要转换的对象的左上角 (0,0) 进行旋转。

下一个示例旋转[Polyline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.polyline)对象围绕点 (25，50) 顺时针旋转 45 度。

```xaml
<Canvas Height="200" Width="200">

  <!-- Rotates the Polyline 45 degrees about the point (25,50). -->
  <Polyline Points="25,25 0,50 25,75 50,50 25,25 25,0" 
    Stroke="Blue" StrokeThickness="10"
    Canvas.Left="75" Canvas.Top="50">
    <Polyline.RenderTransform>
      <RotateTransform CenterX="25" CenterY="50" Angle="45" />
    </Polyline.RenderTransform>
  </Polyline>
</Canvas>
```

```csharp
// Create a Polyline.
Polyline polyline2 = new Polyline();
polyline2.Points = polyline1.Points;
polyline2.Stroke = Brushes.Blue;
polyline2.StrokeThickness = 10;

// Create a RotateTransform to rotate
// the Polyline 45 degrees about the
// point (25,50).
RotateTransform rotateTransform2 =
    new RotateTransform(45);
rotateTransform2.CenterX = 25;
rotateTransform2.CenterY = 50;
polyline2.RenderTransform = rotateTransform2;

// Create a Canvas to contain the Polyline.
Canvas canvas2 = new Canvas();
canvas2.Width = 200;
canvas2.Height = 200;
Canvas.SetLeft(polyline2, 75);
Canvas.SetTop(polyline2, 50);
canvas2.Children.Add(polyline2);
```

下图显示了应用的结果[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transform)到两个对象。

![围绕不同中心点旋转 45 度](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wcpsdk-graphicsmm-rotatetransform45degrees.gif)
两个对象以不同的旋转中心旋转 45 度

[Polyline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.polyline)前面的示例中是[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)。 当应用[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transform)到[RenderTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransform)的属性[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)，可以使用[RenderTransformOrigin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransformorigin)属性指定的 origin 每个[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transform)适用于元素。 因为[RenderTransformOrigin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransformorigin)属性使用相对坐标，你可以将转换应用到元素的中心，即使您不知道其大小。 有关详细信息和示例，请参阅[指定使用相对值转换原点](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-specify-the-origin-of-a-transform-by-using-relative-values)。

有关完整示例，请参阅 [2D 转换示例](https://go.microsoft.com/fwlink/?LinkID=158252)。

### [Scale an Element](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-scale-an-element)

此示例演示如何使用[ScaleTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform)缩放元素。

使用[ScaleX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform.scalex)和[ScaleY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform.scaley)属性以调整元素大小由指定的系数。 例如，[ScaleX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform.scalex)值为 1.5 会拉伸到其原始宽度的 150%的元素。 一个[ScaleY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform.scaley)值为 0.5 会元素的高度缩小 50%。

使用[CenterX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform.centerx)和[CenterY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform.centery)属性来指定缩放操作的中心点。 默认情况下，[ScaleTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform)对应于矩形的左上角的点 (0，0) 的中心。 此操作将移动元素的以及使其看上去更大，因为当应用[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transform)，更改该对象所驻留的坐标空间。

下面的示例使用[ScaleTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform)翻倍，大小为 50 的 50 [Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)。 [ScaleTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform)两个具有值为 0 （默认值）[CenterX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform.centerx)和[CenterY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform.centery)。

#### 示例

```xaml
<!-- Scales a rectangle by 200% from a center of (0,0).-->
<Rectangle Height="50" Width="50" Fill="#CCCCCCFF" 
  Stroke="Blue" StrokeThickness="2"
  Canvas.Left="100" Canvas.Top="100">
  <Rectangle.RenderTransform>
    <ScaleTransform CenterX="0" CenterY="0" ScaleX="2" ScaleY="2" />
  </Rectangle.RenderTransform>
</Rectangle>
```

通常情况下，设置[CenterX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform.centerx)并[CenterY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform.centery)到中心进行缩放的对象: ([Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)/2， [Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height) /2)。

下面的示例演示了另一个[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)的一倍大小; 但是，这[ScaleTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform)两个具有值为 25[CenterX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform.centerx)和[CenterY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform.centery)，这对应于矩形的中心。

```xaml
<!-- Scales a rectangle by 200% from a center of (25,25).-->
<Rectangle Height="50" Width="50" Fill="#CCCCCCFF"
  Canvas.Left="100" Canvas.Top="100" Stroke="Blue" StrokeThickness="2">
  <Rectangle.RenderTransform>
    <ScaleTransform CenterX="25" CenterY="25" ScaleX="2" ScaleY="2" />
  </Rectangle.RenderTransform>
</Rectangle>
```

下图显示了两者之间的差异[ScaleTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform)操作。 虚线显示的是矩形在缩放之前的大小和位置。

![以不同中心点的 2 倍缩放](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wcpsdk-graphicsmm-scalecenter.gif)
两个具有相同 ScaleX 和 ScaleY 值但中心不同的 ScaleTransform 操作

有关完整示例，请参阅 [2D 转换示例](https://go.microsoft.com/fwlink/?LinkID=158252)。

### [Skew an Element](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-skew-an-element)

此示例演示如何使用[SkewTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.skewtransform)使元素扭曲。 扭曲（也称为修剪）是一种以非均匀方式拉伸坐标空间的转换。一个典型用法[SkewTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.skewtransform)是用于模拟三维中的深度二维对象。

使用[CenterX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.skewtransform.centerx)并[CenterY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.skewtransform.centery)属性来指定中心点的[SkewTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.skewtransform)。

使用[AngleX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.skewtransform.anglex)和[AngleY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.skewtransform.angley)属性指定的 x 轴和 y 轴的扭曲角度，使当前坐标系统沿着这些轴扭曲。

若要预测扭曲转换的效果，请考虑的[AngleX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.skewtransform.anglex)沿 x 轴的值相对于原始坐标系统扭曲。 因此，对于[AngleX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.skewtransform.anglex)为 30，y 轴旋转 30 度原点和，则会在 x-通过从该原点 30 度的值。 同样，[AngleY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.skewtransform.angley)为 30，则该形状的 y 值会从原点 30 度。请注意，在 x 或 y 轴中将坐标系统转换（移动）30 度的效果并不相同。

下面的示例应用到的 45 度水平扭曲[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)自中心点为 (0，0)。

#### 示例

```xaml
<Rectangle 
  Height="50" Width="50" Fill="#CCCCCCFF" 
  Stroke="Blue" StrokeThickness="2"
  Canvas.Left="100" Canvas.Top="100">
  <Rectangle.RenderTransform>

     <!-- Applies a horizontal skew of 45 degrees 
          from a center point of (0,0). -->             
    <SkewTransform CenterX="0" CenterY="0" AngleX="45" AngleY="0" />
  </Rectangle.RenderTransform>
</Rectangle>
```

下面的示例应用到的 45 度水平扭曲[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)自中心点 (25，25)。

```xaml
<Rectangle Height="50" Width="50" Fill="#CCCCCCFF"
  Canvas.Left="100" Canvas.Top="100" 
  Stroke="Blue" StrokeThickness="2">
  <Rectangle.RenderTransform>
  
     <!-- Applies a horizontal skew of 45 degrees 
          from a center point of (25,25). -->  
    <SkewTransform CenterX="25" CenterY="25" AngleX="45" AngleY="0" />
  </Rectangle.RenderTransform>
</Rectangle>
```

下面的示例应用的到 45 度垂直扭曲[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)自中心点 (25，25)。

```xaml
<Rectangle Height="50" Width="50" Fill="#CCCCCCFF" 
  Stroke="Blue" StrokeThickness="2"
  Canvas.Left="100" Canvas.Top="100">
  <Rectangle.RenderTransform>
  
     <!-- Applies a vertical skew of 45 degrees 
          from a center point of (25,25). -->             
    <SkewTransform CenterX="25" CenterY="25" AngleX="0" AngleY="45" />
  </Rectangle.RenderTransform>
</Rectangle> 
```

下图演示了此示例中使用的不同扭曲。

![SkewTransform 示例](images/img-wcpsdk-graphicsmm-skewtransformexample.gif)
三个 SkewTransform 示例的图示

有关完整示例，请参阅 [2D 转换示例](https://go.microsoft.com/fwlink/?LinkID=158252)。

### [Specify the Origin of a Transform by Using Relative Values](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-specify-the-origin-of-a-transform-by-using-relative-values)

此示例演示如何使用相对值来指定原点[RenderTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransform)应用于[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)。

当旋转、 缩放或扭曲[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)通过使用[RenderTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransform)属性，默认设置适用于元素的左上角的转换。如果要从元素中心进行旋转、缩放或扭曲，则可以通过将转换中心设置为元素中心来进行补偿。 但是，该解决方案要求你知道元素的大小。 将转换应用于元素的中心的更简单的方法是设置其[RenderTransformOrigin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransformorigin)属性设置为 （0.5，0.5），而不是对转换本身设置中心值。

#### 示例

下面的示例使用[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)旋转[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)顺时针旋转 45 度。 由于该示例未指定中心，按钮将围绕点 (0, 0)（即按钮的左上角）旋转。 [RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)应用于[RenderTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransform)属性。

下图显示了以下示例的转换结果。

![使用 RenderTransform 转换的按钮](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-rendertransformwithdefaultcenter.png)
使用 RenderTransform 属性顺时针旋转 45 度

```xaml
<Border Margin="30" 
  HorizontalAlignment="Left" VerticalAlignment="Top"
  BorderBrush="Black" BorderThickness="1" >
  <StackPanel Orientation="Vertical">
    <Button Content="A Button" Opacity="1" />
    <Button Content="Rotated Button">
      <Button.RenderTransform>
        <RotateTransform Angle="45" />
      </Button.RenderTransform>
    </Button>
    <Button Content="A Button" Opacity="1" />
  </StackPanel>
</Border>
```

下面的示例也使用[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)旋转[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)45 度顺时针旋转; 但是，此示例设置[RenderTransformOrigin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransformorigin)到按钮的 （0.5，0.5）。 因此，将在按钮的中心（而不是其左上角）应用旋转。

下图显示了以下示例的转换结果。

![围绕中心转换后的按钮](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-rendertransformrelativecenter.png)
将 RenderTransform 属性与值为 (0.5, 0.5) 的 RenderTransformOrigin 结合使用以旋转 45 度

```xaml
<Border Margin="30"   
  HorizontalAlignment="Left" VerticalAlignment="Top"
  BorderBrush="Black" BorderThickness="1">
  <StackPanel Orientation="Vertical">
    <Button Content="A Button" Opacity="1" />
    <Button Content="Rotated Button"
      RenderTransformOrigin="0.5,0.5">
      <Button.RenderTransform>
        <RotateTransform Angle="45" />
      </Button.RenderTransform>
    </Button>
    <Button Content="A Button" Opacity="1" />
  </StackPanel>
</Border>
```

有关转换的详细信息[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)对象，请参阅[转换概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/transforms-overview)。

### [Translate an Element](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-translate-an-element)

以下示例显示如何平移 （移动） 元素来使用[TranslateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform)。

[TranslateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform)类是对于不支持绝对定位的面板内移动元素特别有用。 例如，通过应用[TranslateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform)到[RenderTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransform)元素的属性，可以移动中的某个元素[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)或[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)。

使用[X](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform.x)属性的[TranslateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform)指定量，以像素为单位，若要沿 x 轴移动元素。 使用[Y](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform.y)属性来指定量，以像素为单位，若要沿 y 轴移动元素。 最后，将应用[TranslateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform)到[RenderTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransform)元素的属性。

下面的示例使用[TranslateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform)可以向下移动到右和 50 个像素的元素 50 像素。

#### 示例

```xaml
<Rectangle Height="50" Width="50" 
  Fill="#CCCCCCFF" Stroke="Blue" StrokeThickness="2"
  Canvas.Left="100" Canvas.Top="100">
  <Rectangle.RenderTransform>
    <TranslateTransform X="50" Y="50" />
  </Rectangle.RenderTransform>
</Rectangle>
```

有关完整示例，请参阅 [2D 转换示例](https://go.microsoft.com/fwlink/?LinkID=158252)。

### [Use a MatrixTransform to Create Custom Transforms](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-use-a-matrixtransform-to-create-custom-transforms)

此示例演示如何使用[MatrixTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.matrixtransform)平移 （移动） 位置，拉伸和扭曲的[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。

 备注

使用[MatrixTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.matrixtransform)类，以创建不由提供的自定义转换[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)， [SkewTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.skewtransform)，[ScaleTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform)，或[TranslateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform)类。

#### 示例

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml" >
  <StackPanel Margin="20">
    <Canvas HorizontalAlignment="Left" Width="340" Height="240" >

      <Button MinWidth="100">Click
        <Button.RenderTransform>
          <MatrixTransform x:Name="myMatrixTransform">
            <MatrixTransform.Matrix >
              
              <!-- OffsetX and OffsetY specify the position of the button,
              M11 stretches it, and M12 skews it. -->
              <Matrix OffsetX="10" OffsetY="100" M11="3" M12="2"/>
            </MatrixTransform.Matrix>
          </MatrixTransform>
        </Button.RenderTransform>
      </Button>
    </Canvas>
  </StackPanel>
</Page>
```

   