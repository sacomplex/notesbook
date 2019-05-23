# [Animation and Timing System Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/animation-and-timing-system-overview)

本主题描述计时系统如何使用动画[Timeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline)，和[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock)类属性进行动画处理。



## 系统必备

为了了解本主题，应该能够使用 WPF 动画来对属性进行动画处理，如[动画概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/animation-overview)中所述。 本主题还有助于熟悉依赖属性；有关详细信息，请参阅[依赖属性概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-properties-overview)。



## 时间线和时钟

[动画概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/animation-overview)所述方式[Timeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline)表示的时间和动画段是一种[Timeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline)产生输出值。 其本身而言， [Timeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline)，不执行任何操作而不只是介绍了一个时间段。 时间线的[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock)对象执行实际工作。 同样，动画并不实际属性进行动画处理： 动画类描述应如何计算输出值，但它是[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock)创建动画促进动画输出并将其应用到属性。

一个[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock)是一种特殊的维护与时间有关运行时的状态对象[Timeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline)。 它提供对动画和计时系统至关重要的三个信息位： [CurrentTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock.currenttime)， [CurrentProgress](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock.currentprogress)，和[CurrentState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock.currentstate)。 一个[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock)通过使用所描述的计时行为来确定其当前时间、 进度和状态及其[Timeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline): [Duration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.duration)， [RepeatBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.repeatbehavior)， [AutoReverse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.autoreverse)，依次类推。

在大多数情况下，[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock)会自动为你的时间线创建。 当您使用进行动画处理[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)或[BeginAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animatable.beginanimation)方法中，自动为时间线和动画创建时钟并应用于其目标属性。 此外可以创建[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock)通过使用显式[CreateClock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.createclock)方法在[Timeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline)。 [MediaTimeline.CreateClock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediatimeline.createclock)方法创建的相应类型的时钟[Timeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline)上调用它。 如果[Timeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline)包含子时间线，它会创建[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock)也为其对象。 得到[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock)在匹配的结构的树中排列对象[Timeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline)从中创建树对象。

不同类型的时间线具有不同类型的时钟。 下表显示[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock)对应于一些不同的类型[Timeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline)类型。

| 时间线类型                                                   | 时钟类型                                                     | 时钟用途                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 动画 (继承自[AnimationTimeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animationtimeline)) | [AnimationClock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animationclock) | 为依赖属性生成输出值。                                       |
| [MediaTimeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediatimeline) | [MediaClock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediaclock) | 处理媒体文件。                                               |
| [ParallelTimeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.paralleltimeline) | [ClockGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clockgroup) | 分组和控制其子[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock)对象 |
| [Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard) | [ClockGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clockgroup) | 分组和控制其子[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock)对象 |

您可以应用任意[AnimationClock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animationclock)对象通过创建到兼容的依赖属性[ApplyAnimationClock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.ianimatable.applyanimationclock)方法。

需要进行大量性能的情况下，例如对大量类似对象进行动画处理管理你自己[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock)使用可以提供性能优势。



## 时钟和时间管理器

当您设置中的对象有动画效果WPF，它是时间管理器，用于管理[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediaplayer.clock)为时间线创建的对象。 时间管理器是 [Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediaplayer.clock)对象树的根，并控制该树中的时间流。 将自动为每个 WPF 应用程序创建时间管理器，它对于应用程序开发人员不可见。 时间管理器每秒钟“滴答”多次；每秒发生的实际滴答次数取决于可用的系统资源。 在每个滴答，时间管理器计算的所有状态[Active](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clockstate#System_Windows_Media_Animation_ClockState_Active)[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock)计时树中的对象。

下图演示时间管理器之间的关系和[AnimationClock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animationclock)，和动画处理的依赖属性。

![计时系统组件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-clocks-1clock1prop.png)
对属性进行动画处理

当时间管理器滴答时，它会更新的时间每个[Active](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clockstate#System_Windows_Media_Animation_ClockState_Active)[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock)应用程序中。 如果[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock)是[AnimationClock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animationclock)，它使用[GetCurrentValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animationtimeline.getcurrentvalue)方法的[AnimationTimeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animationtimeline)于创建它来计算其当前输出值。 [AnimationClock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animationclock)提供[AnimationTimeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animationtimeline)当前本地时间、 输入的值，这通常是属性的基值，与默认目标值。 检索一个经过动画处理的值时通过属性使用[GetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.getvalue)方法或其 CLR 访问器，你获得的输出其[AnimationClock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animationclock)。

#### 时钟组

前面部分介绍了如何有不同类型的[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock)时间线的不同类型的对象。 下图演示时间管理器之间的关系[ClockGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clockgroup)、 [AnimationClock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animationclock)，和动画处理的依赖属性。 一个[ClockGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clockgroup)为进行分组的其他时间线，如创建[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)类，该类对动画和其他时间线。

![计时系统组件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-clocks-2clock1clockgroup2prop.png)
ClockGroup

#### 撰写

可以将多个时钟与一个属性相关联，在这种情况下，每个时钟都将上一个时钟的输出值用作其基值。 下图显示了三个[AnimationClock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animationclock)应用于相同的属性对象。 时钟1 将经过动画处理的属性的基值用作其输入，并使用该值生成输出。 时钟2 将时钟1 的输出用作其输入，并使用该值生成输出。 时钟3 将时钟2 的输出用作其输入，并使用该值生成输出。 如果多个时钟同时影响同一个属性，则认为这些时钟位于一个组合链中。

![计时系统组件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-clocks-2clock1prop.png)
组合链

请注意，虽然在输入和输出之间创建关系[AnimationClock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animationclock)中组合链中，其计时行为不会受到影响; 的对象[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock)对象 (包括[AnimationClock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animationclock)对象) 上其父级具有分层依赖性[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock)对象。

若要将多个时钟应用于同一个属性，请使用[Compose](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.handoffbehavior#System_Windows_Media_Animation_HandoffBehavior_Compose)[HandoffBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.handoffbehavior)应用时[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)，动画，或[AnimationClock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animationclock)。

#### 滴答和事件合并

除了计算输出值以外，时间管理器还会在它每滴答一次时执行其他工作：它会确定每个时钟的状态并根据需要引发事件。

尽管时钟周期频繁发生，但是不同时钟周期之间可能会很多操作。 例如，[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock)可能会停止、 启动，并再次停止，在这种情况下其[CurrentState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock.currentstate)值将更改三次。 从理论上讲，[CurrentStateInvalidated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock.currentstateinvalidated)事件可能会引发多个时间在一个时钟周期中; 但是，计时引擎会合并事件，以便[CurrentStateInvalidated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock.currentstateinvalidated)每个滴答一次引发事件。 这适用于所有的计时事件： 针对引发一个事件最多每种类型的给定[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock)对象。

当[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock)切换状态并返回到其原始状态计时周期之间 (例如从[Active](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clockstate#System_Windows_Media_Animation_ClockState_Active)到[Stopped](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clockstate#System_Windows_Media_Animation_ClockState_Stopped)并返回到[Active](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clockstate#System_Windows_Media_Animation_ClockState_Active))，仍发生关联的事件。

有关计时事件的详细信息，请参阅[计时事件概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/timing-events-overview)。



## 属性的当前值和基值

可进行动画处理的属性具有两个值：基值和当前值。 在将使用其 CLR 访问器的属性的设置或[SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue)方法，您并将其基值。 对于尚未进行动画处理的属性，基值和当前值相同。

当您对属性进行动画处理[AnimationClock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animationclock)设置的属性*当前*值。 检索通过其 CLR 访问器的属性的值或[GetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.getvalue)方法返回的输出[AnimationClock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animationclock)时[AnimationClock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animationclock)是[Active](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clockstate#System_Windows_Media_Animation_ClockState_Active)或[Filling](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clockstate#System_Windows_Media_Animation_ClockState_Filling)。 可以使用来检索属性的基值[GetAnimationBaseValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.ianimatable.getanimationbasevalue)方法。