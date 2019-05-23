# [Animation Tips and Tricks](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/animation-tips-and-tricks)

使用中的动画时WPF，有一些提示和技巧，可使动画更好地执行，并避免挫折。



## 一般问题

### 对滚动条或滑块的位置进行动画处理将冻结它

如果滚动条或滑块使用的动画位置进行动画处理[FillBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.fillbehavior)的[HoldEnd](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.fillbehavior#System_Windows_Media_Animation_FillBehavior_HoldEnd)（默认值），用户将不再能够移动滚动条或滑块。 这是因为，即使动画已结束，它仍然在重写目标属性的基值。 若要停止动画不再重写属性的当前值，将其删除，或为其赋予[FillBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.fillbehavior)的[Stop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.fillbehavior#System_Windows_Media_Animation_FillBehavior_Stop)。 有关详细信息和示例，请参阅[后设置该属性进行动画处理使用演示图板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-set-a-property-after-animating-it-with-a-storyboard)。

### 对动画的输出进行动画处理没有效果

如果某个对象是另一个动画的输出，则无法对该对象进行动画处理。 例如，如果您使用[ObjectAnimationUsingKeyFrames](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.objectanimationusingkeyframes)进行动画处理[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)的[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)从[RadialGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.radialgradientbrush)到[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)，不能进行动画处理的任何属性[RadialGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.radialgradientbrush)或[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)。

### 在对属性进行动画处理后无法更改该属性的值

在某些情况下，在对属性进行动画处理后，即使在动画结束后，看起来仍无法更改该属性的值。 这是因为即使动画已结束，它仍然在重写该属性的基值。 若要停止动画不再重写属性的当前值，将其删除，或为其赋予[FillBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.fillbehavior)的[Stop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.fillbehavior#System_Windows_Media_Animation_FillBehavior_Stop)。 有关详细信息和示例，请参阅[后设置该属性进行动画处理使用演示图板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-set-a-property-after-animating-it-with-a-storyboard)。

### 更改时间线没有效果

尽管大多数[Timeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline)属性可进行动画处理，并且可数据绑定，更改活动的属性值[Timeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline)似乎不起作用。 这是因为，当[Timeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline)是开始，计时系统生成的副本[Timeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline)并使用它来创建[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock)对象。 修改原件对系统的副本没有影响。

有关[Timeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline)以反映更改，它的时钟必须重新生成并用于替换以前创建的时钟。 时钟不会自动重新生成。 以下是应用时间线更改的几种方法：

- 如果时间线是或属于[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)，你可以使其通过重新应用其情节提要使用反映更改[BeginStoryboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.beginstoryboard)或[Begin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard.begin)方法。 这还会产生重新启动动画的附带影响。 在代码中，可以使用[Seek](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard.seek)方法将情节提要回其之前的位置。
- 如果您将动画应用于属性使用直接[BeginAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animatable.beginanimation)方法中，调用[BeginAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animatable.beginanimation)再次方法并将其传递已修改的动画。
- 如果要直接在时钟级别上工作，请创建并应用一组新的时钟，然后用它们替换之前生成的一组时钟。

有关时间线和时钟的详细信息，请参阅[动画和计时系统概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/animation-and-timing-system-overview)。

### FillBehavior.Stop 不按预期方式工作

有些时候设置时[FillBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.fillbehavior)属性设置为[Stop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.fillbehavior#System_Windows_Media_Animation_FillBehavior_Stop)似乎不起作用，例如当一个动画"切换"到另一个因为它具有[HandoffBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.beginstoryboard.handoffbehavior)设置为[SnapshotAndReplace](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.handoffbehavior#System_Windows_Media_Animation_HandoffBehavior_SnapshotAndReplace)。

下面的示例创建[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)、 一个[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)和一个[TranslateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform)。 [TranslateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform)将对其进行动画处理，以移动[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)围绕[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)。

XAML复制

```xaml
<Canvas Width="600" Height="200">
  <Rectangle 
    Canvas.Top="50" Canvas.Left="0" 
    Width="50" Height="50" Fill="Red">
    <Rectangle.RenderTransform>
      <TranslateTransform 
        x:Name="MyTranslateTransform" 
        X="0" Y="0" />
    </Rectangle.RenderTransform>
  </Rectangle>
</Canvas>
```

在本部分中的示例使用上述对象演示几种情况其中[FillBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.fillbehavior)属性可能预期的行为不符合。

#### 针对多个动画的 FillBehavior="Stop" 和 HandoffBehavior

有时，似乎动画会忽略其[FillBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.fillbehavior)时它替换为第二个动画的属性。 执行下面的示例创建两个[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)对象，并使用它们来进行动画处理相同[TranslateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform)在前面的示例所示。

第一个[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)， `B1`，进行动画处理[X](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform.x)属性的[TranslateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform)从 0 到 350，该矩形 350 像素向右移动。 当动画到达其持续时间的末尾并停止播放，[X](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform.x)属性会恢复为其原始值为 0。 因此，矩形向右移动 350 像素，然后跳回其原始位置。

XAML复制

```xaml
<Button Content="Start Storyboard B1">
  <Button.Triggers>
    <EventTrigger RoutedEvent="Button.Click">
      <BeginStoryboard>
        <Storyboard x:Name="B1">
          <DoubleAnimation 
            Storyboard.TargetName="MyTranslateTransform"
            Storyboard.TargetProperty="X"
            From="0" To="350" Duration="0:0:5"
            FillBehavior="Stop"
            />
        </Storyboard>
      </BeginStoryboard>
    </EventTrigger>
  </Button.Triggers>
</Button>
```

第二个[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)， `B2`，还进行动画处理[X](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform.x)属性的相同[TranslateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform)。 因为仅[To](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation.to)在此动画属性[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)，则动画使用它进行动画处理的属性的当前值作为其起始值。

XAML复制

```xaml
<!-- Animates the same object and property as the preceding
     Storyboard. -->
<Button Content="Start Storyboard B2">
  <Button.Triggers>
    <EventTrigger RoutedEvent="Button.Click">
      <BeginStoryboard>
        <Storyboard x:Name="B2">
          <DoubleAnimation 
            Storyboard.TargetName="MyTranslateTransform"
            Storyboard.TargetProperty="X"
            To="500" Duration="0:0:5" 
            FillBehavior="Stop" />
        </Storyboard>
      </BeginStoryboard>
    </EventTrigger>
  </Button.Triggers>
</Button>
```

如果单击第二个按钮时第一个[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)是播放，可能会出现以下行为：

1. 第一个情节提要结束，并将矩形送回其原始位置，因为该动画[FillBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.fillbehavior)的[Stop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.fillbehavior#System_Windows_Media_Animation_FillBehavior_Stop)。
2. 第二个情节提要生效，从当前位置（现在为 0）播放动画到 500。

**但情况并非如此。** 矩形没有跳回，而是继续向右移动。 这是因为第二个动画使用第一个动画的当前值作为其起始值，并从该值开始播放动画到 500。 当第二个动画替换第一个，因为[SnapshotAndReplace](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.handoffbehavior#System_Windows_Media_Animation_HandoffBehavior_SnapshotAndReplace)[HandoffBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.handoffbehavior)使用，则[FillBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.fillbehavior)第一个动画并不重要。

#### FillBehavior 和 Completed 事件

下一步的示例演示了另一个方案，其中[Stop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.fillbehavior#System_Windows_Media_Animation_FillBehavior_Stop)[FillBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.fillbehavior)似乎不起作用。 同样，该示例使用演示图板进行动画处理[X](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform.x)属性的[TranslateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform)从 0 到 350。 但是，这一次该示例会注册[Completed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.completed)事件。

XAML复制

```xaml
<Button Content="Start Storyboard C">
  <Button.Triggers>
    <EventTrigger RoutedEvent="Button.Click">
      <BeginStoryboard>
        <Storyboard Completed="StoryboardC_Completed">
          <DoubleAnimation 
            Storyboard.TargetName="MyTranslateTransform"
            Storyboard.TargetProperty="X"
            From="0" To="350" Duration="0:0:5"
            FillBehavior="Stop" />
        </Storyboard>
      </BeginStoryboard>
    </EventTrigger>
  </Button.Triggers>
</Button>
```

[Completed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.completed)事件处理程序将启动另一个[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)从其当前值为 500 的同一属性进行动画处理。

C#复制

```csharp
private void StoryboardC_Completed(object sender, EventArgs e)
{

    Storyboard translationAnimationStoryboard =
        (Storyboard)this.Resources["TranslationAnimationStoryboardResource"];
    translationAnimationStoryboard.Begin(this);
}
```

下面是定义第二个标记[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)作为资源。

XAML复制

```xaml
<Page.Resources>
  <Storyboard x:Key="TranslationAnimationStoryboardResource">
    <DoubleAnimation 
      Storyboard.TargetName="MyTranslateTransform"
      Storyboard.TargetProperty="X"
      To="500" Duration="0:0:5" />
  </Storyboard>
</Page.Resources>
```

运行时[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)，您所料[X](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform.x)的属性[TranslateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform)进行动画处理从 0 到 350，然后还原成 0 它完成后 (因为它具有[FillBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.fillbehavior)设置的[Stop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.fillbehavior#System_Windows_Media_Animation_FillBehavior_Stop))，并动态变化从 0 到 500。 相反，[TranslateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform)之间进行动画处理从 0 到 350 再到 500。

这是因为依据的顺序WPF引发事件，而且除非该属性失效属性值已缓存，不是重新计算。 [Completed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.completed)因为它由根时间线触发的第一次处理事件 (第一个[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard))。 在此期间，[X](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform.x)属性仍然返回其经过动画处理的值，因为它尚未失效。 第二个[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)使用缓存的值作为其起始值并开始播放动画。



## 性能

### 在导航离开页面后动画继续运行

导航离开[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)，其中包含正在运行的动画，这些动画将继续播放，直到[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)进行垃圾回收。 根据正在使用的导航系统，导航离开的页面可能无限期地保留在内存中，在此期间始终通过动画消耗资源。 当页面包含不断运行的（“氛围”）动画时，这一点最明显。

出于此原因，它是一个好办法使用[Unloaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.unloaded)事件删除动画时导航离开页面。

删除动画有多种不同的方法。 可以使用以下方法删除属于的动画[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)。

- 若要删除[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)开始使用事件触发器，请参阅[如何：删除情节提要](https://docs.microsoft.com/previous-versions/dotnet/netframework-3.5/ms749412(v=vs.90))。
- 若要使用代码来删除[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)，请参阅[Remove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard.remove)方法。

无论动画如何启动，都可以使用下一个技术。

- 若要从特定的属性中删除动画，请使用[BeginAnimation(DependencyProperty, AnimationTimeline)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animatable.beginanimation#System_Windows_Media_Animation_Animatable_BeginAnimation_System_Windows_DependencyProperty_System_Windows_Media_Animation_AnimationTimeline_)方法。 指定要进行动画处理的第一个参数的属性和`null`为第二个。 这将从该属性中删除所有动画时钟。

有关属性进行动画处理的不同方式的详细信息，请参阅[属性动画技术概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/property-animation-techniques-overview)。

### 使用组合 HandoffBehavior 会消耗系统资源

当应用[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)， [AnimationTimeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animationtimeline)，或[AnimationClock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animationclock)属性使用[Compose](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.handoffbehavior#System_Windows_Media_Animation_HandoffBehavior_Compose) [HandoffBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.handoffbehavior)，则所有[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock)之前与该属性相关联的对象继续消耗系统资源时，计时系统将不会自动删除这些时钟。

若要避免出现性能问题时应用大量时钟使用[Compose](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.handoffbehavior#System_Windows_Media_Animation_HandoffBehavior_Compose)，它们完成后，您应该从属性的基值删除组合时钟。 删除时钟有多种方法。

- 若要从属性中删除所有时钟，请使用[ApplyAnimationClock(DependencyProperty, AnimationClock)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animatable.applyanimationclock#System_Windows_Media_Animation_Animatable_ApplyAnimationClock_System_Windows_DependencyProperty_System_Windows_Media_Animation_AnimationClock_)或[BeginAnimation(DependencyProperty, AnimationTimeline)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animatable.beginanimation#System_Windows_Media_Animation_Animatable_BeginAnimation_System_Windows_DependencyProperty_System_Windows_Media_Animation_AnimationTimeline_)经过动画处理的对象的方法。 指定要进行动画处理的第一个参数的属性和`null`为第二个。 这将从该属性中删除所有动画时钟。
- 若要删除特定[AnimationClock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animationclock)从列表中的时钟，使用[Controller](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock.controller)属性[AnimationClock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animationclock)检索[ClockController](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clockcontroller)，然后调用[Remove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clockcontroller.remove)方法[ClockController](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clockcontroller)。 这通常是[Completed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock.completed)时钟的事件处理程序。 请注意，只有根时钟可以受[ClockController](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clockcontroller);[Controller](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock.controller)子时钟的属性将返回`null`。 另请注意，[Completed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock.completed)如果时钟的有效持续时间将永远不会调用事件。 在这种情况下，用户将需要确定何时调用[Remove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clockcontroller.remove)。

此动画问题主要出现在生存期较长的对象上。 当对某个对象进行垃圾回收时，它的时钟也会断开连接并进行垃圾回收。

有关时钟对象的详细信息，请参阅[动画和计时系统概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/animation-and-timing-system-overview)。