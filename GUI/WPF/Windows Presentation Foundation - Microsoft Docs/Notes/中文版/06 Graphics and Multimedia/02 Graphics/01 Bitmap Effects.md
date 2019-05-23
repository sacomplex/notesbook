# [Bitmap Effects](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/bitmap-effects)

本部分中的主题介绍如何将可视化效果应用于位图图像使用Windows Presentation Foundation (WPF)。

> 在.NET Framework 4或更高版本，[BitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.bitmapeffect)类已过时。 如果你尝试使用[BitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.bitmapeffect)类，则您将收到已过时。 未过时的替代项为[BitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.bitmapeffect)类是[Effect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.effect)类。 在大多数情况下，[Effect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.effect)类是快得多。

## 本节内容

[位图效果概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/bitmap-effects-overview)

位图效果，设计人员和开发人员应用到视觉效果呈现 Windows Presentation Foundation (WPF) 内容。 例如，位图效果，您可以轻松地将应用[DropShadowBitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.dropshadowbitmapeffect)效果或模糊效果到图像或按钮。

> 在中.NET Framework 4或更高版本，[BitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.bitmapeffect)类已过时。 如果尝试使用[BitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.bitmapeffect)类，您将收到已过时异常。 非过时替代项为[BitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.bitmapeffect)类是[Effect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.effect)类。 在大多数情况下，[Effect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.effect)类是快得多。

## [Bitmap Effects Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/bitmap-effects-overview)

#### WPF 位图效果

位图效果 ([BitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.bitmapeffect)对象) 是简单的像素处理操作。 位图效果采用[BitmapSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapsource)作为输入并生成一个新[BitmapSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapsource)后应用效果，如模糊或投影。 每个位图效果公开用于控制筛选的属性，如[Radius](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.blurbitmapeffect.radius)的[BlurBitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.blurbitmapeffect)。

作为一种特殊情况，在WPF，可以将效果设置为属性上实时[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)对象，如[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)或[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。 像素处理在运行时应用并呈现。 在这种情况下，在呈现时[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)自动转换为其[BitmapSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapsource)等效和作为输入发送给[BitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.bitmapeffect)。 输出将替换[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)对象的默认呈现行为。 这就是为什么[BitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.bitmapeffect)对象强制视觉对象在软件中呈现仅即视觉对象上的没有硬件加速，应用效果时。

- [BlurBitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.blurbitmapeffect) 模拟显示聚焦不准的对象。
- [OuterGlowBitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.outerglowbitmapeffect) 创建一个对象周围的颜色的。
- [DropShadowBitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.dropshadowbitmapeffect) 创建对象后的阴影。
- [BevelBitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.bevelbitmapeffect) 创建凹凸效果，根据指定的曲线图像表面。
- [EmbossBitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.embossbitmapeffect) 创建的凹凸贴图[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)以便从人工光源的深度和纹理效果。

> WPF 位图效果在软件模式下呈现。 应用效果的任何对象也都将以软件形式呈现。 在大型视觉对象上使用位图效果或对位图效果的属性进行动画处理时，性能的下降幅度最大。 这并不表示完全不应该以这种方式使用位图效果，而是应谨慎使用，并进行全面测试以确保用户得到预期的体验。

> WPF 位图效果不支持部分信任执行。 应用程序必须具有完全信任权限才能使用位图效果。

#### 如何应用效果

[BitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.bitmapeffect) 一个属性[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)。 因此将效果应用于视觉对象，如[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)， [Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)， [DrawingVisual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingvisual)，或[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)，就像设置属性一样简单。 [BitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.bitmapeffect) 可以将设置为单个[BitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.bitmapeffect)可以通过使用链接对象或多个效果[BitmapEffectGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.bitmapeffectgroup)对象。

下面的示例演示如何将应用[BitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.bitmapeffect)在可扩展应用程序标记语言 (XAML)。

```xaml
<Button  Width="200">You Can't Read This!
  <Button.BitmapEffect>

  <!-- <BitmapEffectGroup> would go here if you wanted to apply more 
         then one effect to the Button. However, in this example only  
         one effect is being applied so BitmapEffectGroup does not need  
         to be included. -->

    <!-- The larger the Radius, the more blurring. The default range is 20.
         In addition, the KernelType is set to a box kernel. A box kernel
         creates less disruption (less blur) then the default Gaussian kernel. -->
    <BlurBitmapEffect Radius="10" KernelType="Box" />

  </Button.BitmapEffect>
</Button>
```

下面的示例演示如何将应用[BitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.bitmapeffect)在代码中。

```csharp
// Get a reference to the Button.
Button myButton = (Button)sender;

// Initialize a new BlurBitmapEffect that will be applied
// to the Button.
BlurBitmapEffect myBlurEffect = new BlurBitmapEffect();

// Set the Radius property of the blur. This determines how 
// blurry the effect will be. The larger the radius, the more
// blurring. 
myBlurEffect.Radius = 10;

// Set the KernelType property of the blur. A KernalType of "Box"
// creates less blur than the Gaussian kernal type.
myBlurEffect.KernelType = KernelType.Box;

// Apply the bitmap effect to the Button.
myButton.BitmapEffect = myBlurEffect;
```

> 当[BitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.bitmapeffect)应用到布局容器，如[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)或[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)，效果应用到元素或视觉对象，包括其所有子元素的可视化树。

#### 创建自定义效果

WPF 还提供非托管接口，用于创建可在托管 WPF 应用程序中使用的自定义效果。 有关创建自定义位图效果的其他参考资料，请参阅[非托管 WPF 位图效果](https://docs.microsoft.com/previous-versions/windows/desktop/wibe/-wibe-lh)文档。