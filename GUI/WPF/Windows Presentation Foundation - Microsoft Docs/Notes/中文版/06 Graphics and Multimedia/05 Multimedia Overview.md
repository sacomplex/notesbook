# [Multimedia Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/multimedia-overview)

Windows Presentation Foundation (WPF) 中的多媒体功能能够使音频和视频集成到应用程序，增强用户体验。 本主题介绍了 WPF 的多媒体功能。



## 媒体 API

[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)和[MediaPlayer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediaplayer)类用于提供音频或视频内容。 可以以交互方式或时钟控制这些类。 这些类可以用在Microsoft Windows Media Player 10 控件上进行媒体播放。 要使用哪个类取决于方案。

[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement) 是[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)受[布局](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/layout)并且可用作许多控件的内容。 它也可用在 可扩展应用程序标记语言 (XAML) 与代码中。 [MediaPlayer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediaplayer)但是，专为[Drawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawing)对象，因而缺少布局支持。 加载使用介质[MediaPlayer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediaplayer)仅可以使用呈现[VideoDrawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.videodrawing)或通过直接与交互[DrawingContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingcontext)。 [MediaPlayer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediaplayer) 不能在 XAML 中使用。

有关绘图对象和绘图上下文的详细信息，请参阅 [Drawing 对象概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/drawing-objects-overview)。

 备注

使用应用程序分发媒体时，不可将媒体文件用作项目资源。 在项目文件中，必须改为将媒体类型设置为 `Content` 并将 `CopyToOutputDirectory` 设置为 `PreserveNewest` 或 `Always`。



## 媒体播放模式

 备注

这两[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)和[MediaPlayer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediaplayer)拥有相似的成员。 在本部分链接是指[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)类成员。 除非特别注明，否则成员链接到在[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)类还可在[MediaPlayer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediaplayer)类。

要了解 Windows Presentation Foundation (WPF) 中的媒体播放，需要了解可以播放媒体的不同模式。 这两[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)和[MediaPlayer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediaplayer)可在两个不同的媒体模式，独立模式和时钟模式。 媒体模式由[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.clock)属性。 当[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.clock)是`null`，媒体对象处于独立模式。 当[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.clock)为非 null，媒体对象处于时钟模式。 默认情况下，媒体对象处于独立模式。

### 独立模式

在独立模式下，媒体内容驱动媒体播放。 独立模式可实现下列选项：

- 媒体的[Uri](https://docs.microsoft.com/zh-cn/dotnet/api/system.uri)可以直接指定。
- 可以直接控制媒体播放。
- 媒体的[Position](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.position)和[SpeedRatio](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.speedratio)可以修改属性。

通过这两个设置加载媒体[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)对象的[Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.source)属性或通过调用[MediaPlayer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediaplayer)对象的[Open](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediaplayer.open)方法。

要在独立模式下控制媒体播放，可使用媒体对象的控制方法。 可用的控制方法都[Play](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.play)， [Pause](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.pause)， [Close](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.close)，和[Stop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.stop)。有关[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)，使用这些方法的交互式控件才可用[LoadedBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.loadedbehavior)设置为[Manual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediastate#System_Windows_Controls_MediaState_Manual)。 这些方法在媒体对象处于时钟模式时不可用。

请参阅[控制 MediaElement（Play、Pause、Stop、Volume 和 Speed）](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-control-a-mediaelement-play-pause-stop-volume-and-speed)了解独立模式的示例。

### 时钟模式

在时钟模式下，[MediaTimeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediatimeline)驱动器媒体的播放。 时钟模式具有以下特征：

- 媒体的[Uri](https://docs.microsoft.com/zh-cn/dotnet/api/system.uri)间接设置通过[MediaTimeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediatimeline)。
- 可由时钟控制媒体播放。 不可使用媒体对象的控制方法。
- 通过设置加载介质[MediaTimeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediatimeline)对象的[Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediatimeline.source)属性，从时间线创建时钟并将时钟分配至媒体对象。 这种方法还加载媒体时[MediaTimeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediatimeline)内[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)目标[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)。

在时钟模式下控制媒体播放[ClockController](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clockcontroller)必须使用控制方法。 一个[ClockController](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clockcontroller)取自[ClockController](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clockcontroller)属性的[MediaClock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediaclock)。 如果尝试使用的控制方法[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)或[MediaPlayer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediaplayer)对象在时钟模式下，[InvalidOperationException](https://docs.microsoft.com/zh-cn/dotnet/api/system.invalidoperationexception)将引发。

请参阅[动画概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/animation-overview)了解有关时钟和时间线的更多信息。

请参阅[使用情节提要控制 MediaElement](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-control-a-mediaelement-by-using-a-storyboard) 了解时钟模式的示例。



## MediaElement 类

将媒体添加到应用程序非常简单，添加[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)控制对用户界面 (UI)的应用程序，并提供[Uri](https://docs.microsoft.com/zh-cn/dotnet/api/system.uri)到你想要包括的媒体。 所有 Microsoft Windows Media Player 10 支持的媒体类型都受到 Windows Presentation Foundation (WPF)的支持。 下面的示例演示的简单用法[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)在可扩展应用程序标记语言 (XAML)。

XAML复制

```xaml
<!-- This page shows a simple usage of MediaElement -->
<Page x:Class="MediaElementExample.SimpleUsage"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    Title="SimpleUsage"
    >
  <StackPanel Margin="20">
    <MediaElement Source="media/numbers-aud.wmv" />
  </StackPanel>
</Page>
```

在此示例中，媒体一旦加载会自动播放。 媒体完成播放后会关闭并且所有媒体资源已发布（包括视频内存）。 这是默认行为[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)对象，并由控制[LoadedBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.loadedbehavior)和[UnloadedBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.unloadedbehavior)属性。

### 控制 MediaElement

[LoadedBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.loadedbehavior)并[UnloadedBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.unloadedbehavior)属性控制的行为[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)时[IsLoaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.isloaded)是`true`或`false`分别。[MediaState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediastate)的属性设置为影响媒体播放行为。 例如，默认值[LoadedBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.loadedbehavior)是[Play](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediastate#System_Windows_Controls_MediaState_Play)和默认[UnloadedBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.unloadedbehavior)是[Close](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediastate#System_Windows_Controls_MediaState_Close)。 这意味着，只要[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)加载和预滚完成，媒体开始播放。 一旦播放完毕，媒体就会关闭并且发布所有媒体资源。

[LoadedBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.loadedbehavior)和[UnloadedBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.unloadedbehavior)属性不是控制媒体播放的唯一方法。 在时钟模式下，可以控制时钟[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)和交互式控制方法具有控制何时[LoadedBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.loadedbehavior)是[Manual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediastate#System_Windows_Controls_MediaState_Manual)。 [MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement) 通过评估以下属性来处理这种控制争用。

1. [UnloadedBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.unloadedbehavior)。 卸载媒体时就位。 这可确保默认情况下，会释放所有的媒体资源，即使[MediaClock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediaclock)与关联[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)。
2. [MediaClock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediaclock)。 在媒体具有时就位[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.clock)。 如果媒体已卸载，[MediaClock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediaclock)将会生效，只要[UnloadedBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.unloadedbehavior)是[Manual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediastate#System_Windows_Controls_MediaState_Manual)。 时钟模式下将始终覆盖的加载的行为[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)。
3. [LoadedBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.loadedbehavior)。 加载媒体时就位。
4. 交互式控制方法。 在发生[LoadedBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.loadedbehavior)是[Manual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediastate#System_Windows_Controls_MediaState_Manual)。 可用的控制方法都[Play](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.play)， [Pause](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.pause)， [Close](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.close)，和[Stop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.stop)。

### 显示 MediaElement

若要显示[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)它必须具有要呈现的内容，其中包含其[ActualWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.actualwidth)和[ActualHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.actualheight)属性设置为零，直到加载内容。 对于仅包含音频的内容，这些属性将始终为零。 有关视频内容，一次[MediaOpened](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.mediaopened)引发事件[ActualWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.actualwidth)和[ActualHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.actualheight)将报表加载媒体的大小。 这意味着，媒体已加载，直到[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)不会占用任何物理空间用户界面 (UI)除非[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)或[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)设置属性。

将两者都设置[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)并[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)属性会导致媒体拉伸以填充为提供的区域[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)。 若要保留媒体的原始纵横比，或者[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)或[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)属性应设置好，但不可同时使用两者。 将两者都设置[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)和[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)属性会导致媒体以固定的元素大小，您可能希望呈现。

要避免出现固定大小元素，Windows Presentation Foundation (WPF) 可以预滚媒体。 这是通过设置[LoadedBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.loadedbehavior)至任一[Play](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediastate#System_Windows_Controls_MediaState_Play)或[Pause](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediastate#System_Windows_Controls_MediaState_Pause)。 在[Pause](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediastate#System_Windows_Controls_MediaState_Pause)状态下，媒体会预播放，将显示第一个帧。 在[Play](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediastate#System_Windows_Controls_MediaState_Play)状态时，媒体将预滚并开始播放。



## MediaPlayer 类

作为 where[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)类是框架元素，其[MediaPlayer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediaplayer)类旨在用于[Drawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawing)对象。 当可以牺牲框架级别功能来获得性能优势，或在需要时使用 drawing 对象[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)功能。 [MediaPlayer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediaplayer) 可以充分利用这些功能，同时提供你的应用程序中的媒体内容。 像[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)，[MediaPlayer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediaplayer)可在独立或时钟模式，但不是会不具有[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)对象的卸载和加载状态。 这会减少播放控件的复杂程度[MediaPlayer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediaplayer)。

### 控制 MediaPlayer

因为[MediaPlayer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediaplayer)是无状态的有只有两个方法控制媒体的播放。

1. 交互式控制方法。 在处于独立模式下时的位置 (`null` [Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediaplayer.clock)属性)。
2. [MediaClock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediaclock)。 在媒体具有时就位[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediaplayer.clock)。

### 显示 MediaPlayer

从技术上讲，[MediaPlayer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediaplayer)无法显示，因为它必须没有物理表示形式。 但是，使用它来显示在媒体[Drawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawing)使用[VideoDrawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.videodrawing)类。 下面的示例演示如何将[VideoDrawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.videodrawing)显示媒体。

C#复制

```csharp
//
// Create a VideoDrawing.
//      
MediaPlayer player = new MediaPlayer();

player.Open(new Uri(@"sampleMedia\xbox.wmv", UriKind.Relative));

VideoDrawing aVideoDrawing = new VideoDrawing();

aVideoDrawing.Rect = new Rect(0, 0, 100, 100);

aVideoDrawing.Player = player;

// Play the video once.
player.Play();        
```

请参阅[Drawing 对象概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/drawing-objects-overview)有关详细信息[Drawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawing)对象。

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/audio-and-video-how-to-topics)

以下主题演示如何使用[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)集成应用程序中的音频和视频内容。

### 本节内容

[如何： 动态添加元素](https://msdn.microsoft.com/library/d00f258a-7973-4de7-bc54-a3fc1f638419)
[控制 MediaElement（播放、暂停、停止、音量和速度）](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-control-a-mediaelement-play-pause-stop-volume-and-speed)
[使用情节提要控制 MediaElement](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-control-a-mediaelement-by-using-a-storyboard)
[使用用户事件触发媒体播放](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-trigger-media-playback-with-a-user-event)
[重复媒体播放](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-repeat-media-playback)
[播放带有动画的媒体](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-play-media-with-animations)
[对 MediaElement 使用转换](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-use-transforms-on-a-mediaelement)

### [Control a MediaElement (Play, Pause, Stop, Volume, and Speed)](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-control-a-mediaelement-play-pause-stop-volume-and-speed)

下面的示例演示如何控制播放的媒体使用[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)。 该示例创建简单的媒体播放器，可用于播放、 暂停、 停止，请跳过在媒体中的往返，以及调整音量和速度比。

#### 示例

以下代码创建 UI。

[LoadedBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.loadedbehavior)的属性[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)必须设置为`Manual`以便能够以交互方式停止、 暂停和播放媒体。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  x:Class="SDKSample.MediaElementExample" >

  <StackPanel Background="Black">

    <!-- To interactively stop, pause, and play the media, the LoadedBehavior 
           property of the MediaElement must be set to "Manual". -->
    <MediaElement Source="media\numbers.wmv" Name="myMediaElement" 
     Width="450" Height="250" LoadedBehavior="Manual" UnloadedBehavior="Stop" Stretch="Fill" 
     MediaOpened="Element_MediaOpened" MediaEnded="Element_MediaEnded"/>
    
    <StackPanel HorizontalAlignment="Center" Width="450" Orientation="Horizontal">

      <!-- Play button. -->
      <Image Source="images\UI_play.gif" MouseDown="OnMouseDownPlayMedia" Margin="5" />

      <!-- Pause button. -->
      <Image Source="images\UI_pause.gif" MouseDown="OnMouseDownPauseMedia" Margin="5" />

      <!-- Stop button. -->
      <Image Source="images\UI_stop.gif" MouseDown="OnMouseDownStopMedia" Margin="5" />

      <!-- Volume slider. This slider allows a Volume range between 0 and 1. -->
      <TextBlock Foreground="White" VerticalAlignment="Center" Margin="5"  >Volume</TextBlock>
      <Slider Name="volumeSlider" VerticalAlignment="Center" ValueChanged="ChangeMediaVolume" 
       Minimum="0" Maximum="1" Value="0.5" Width="70"/>

      <!-- Volume slider. This slider allows you to change the speed of the media playback. -->
      <TextBlock Foreground="White" Margin="5"  VerticalAlignment="Center">Speed</TextBlock>
      <Slider Name="speedRatioSlider" VerticalAlignment="Center" ValueChanged="ChangeMediaSpeedRatio" 
       Value="1" Width="70" />
      
      <!-- Seek to slider. Ths slider allows you to jump to different parts of the media playback. -->
      <TextBlock Foreground="White" Margin="5"  VerticalAlignment="Center">Seek To</TextBlock>
      <Slider Name="timelineSlider" Margin="5" ValueChanged="SeekToMediaPosition" Width="70"/>

    </StackPanel>
  </StackPanel>
</Page>
```

#### 示例

下面的代码实现的示例 UI 控件的功能。 [Play](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.play)， [Pause](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.pause)，和[Stop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.stop)方法用于分别播放、 暂停和停止该媒体。 更改[Position](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.position)属性的[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)可以跳过在媒体中。 最后，[Volume](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.volume)和[SpeedRatio](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.speedratio)属性用来调整媒体的音量和播放速度。

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Data;
using System.Windows.Media;
using System.Windows.Input;

namespace SDKSample
{

   public partial class MediaElementExample : Page
   {

      // Play the media.
      void OnMouseDownPlayMedia(object sender, MouseButtonEventArgs args)
      {

         // The Play method will begin the media if it is not currently active or 
         // resume media if it is paused. This has no effect if the media is
         // already running.
         myMediaElement.Play();

         // Initialize the MediaElement property values.
         InitializePropertyValues();

      }

      // Pause the media.
      void OnMouseDownPauseMedia(object sender, MouseButtonEventArgs args)
      {

         // The Pause method pauses the media if it is currently running.
         // The Play method can be used to resume.
         myMediaElement.Pause();

      }

      // Stop the media.
      void OnMouseDownStopMedia(object sender, MouseButtonEventArgs args)
      {

         // The Stop method stops and resets the media to be played from
         // the beginning.
         myMediaElement.Stop();

      }

      // Change the volume of the media.
      private void ChangeMediaVolume(object sender, RoutedPropertyChangedEventArgs<double> args)
      {
         myMediaElement.Volume = (double)volumeSlider.Value;
      }

      // Change the speed of the media.
      private void ChangeMediaSpeedRatio(object sender, RoutedPropertyChangedEventArgs<double> args)
      {
         myMediaElement.SpeedRatio = (double)speedRatioSlider.Value;
      }

      // When the media opens, initialize the "Seek To" slider maximum value
      // to the total number of miliseconds in the length of the media clip.
      private void Element_MediaOpened(object sender, EventArgs e)
      {
         timelineSlider.Maximum = myMediaElement.NaturalDuration.TimeSpan.TotalMilliseconds;
      }

      // When the media playback is finished. Stop() the media to seek to media start.
      private void Element_MediaEnded(object sender, EventArgs e)
      {
         myMediaElement.Stop();
      }

      // Jump to different parts of the media (seek to). 
      private void SeekToMediaPosition(object sender, RoutedPropertyChangedEventArgs<double> args)
      {
         int SliderValue = (int)timelineSlider.Value;

         // Overloaded constructor takes the arguments days, hours, minutes, seconds, miniseconds.
         // Create a TimeSpan with miliseconds equal to the slider value.
         TimeSpan ts = new TimeSpan(0, 0, 0, 0, SliderValue);
         myMediaElement.Position = ts;
      }

      void InitializePropertyValues()
      {
         // Set the media's starting Volume and SpeedRatio to the current value of the
         // their respective slider controls.
         myMediaElement.Volume = (double)volumeSlider.Value;
         myMediaElement.SpeedRatio = (double)speedRatioSlider.Value;
      }

   }
}
```

### [Control a MediaElement by Using a Storyboard](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-control-a-mediaelement-by-using-a-storyboard)

此示例演示如何控制[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)通过使用[MediaTimeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediatimeline)中[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)。

#### 示例

当你使用[MediaTimeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediatimeline)中[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)控制的计时[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)，功能是相同的功能的其他[Timeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline)对象，例如动画。 例如，[MediaTimeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediatimeline)使用[Timeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline)属性，如[BeginTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.begintime)属性来指定何时开始[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)（启动媒体的播放）。 它还使用[Duration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.duration)属性来指定多长时间[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)处于活动状态 （的媒体的播放持续时间）。 有关使用详细信息[Timeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline)对象与[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)，请参阅[情节提要概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/storyboards-overview)。

此示例演示如何创建简单的媒体播放器使用[MediaTimeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediatimeline)来控制播放。 Media player 还包括播放、 暂停、 继续和停止按钮。 播放机也有[Slider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider)充当一个进度栏控件。

下面的示例创建用户界面 (UI)媒体播放器。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml" 
  x:Class="SDKSample.MediaTimelineExample" >

  <StackPanel Background="Black">

    <MediaElement Name="myMediaElement" MediaOpened="Element_MediaOpened"
     Width="260" Height="150" Stretch="Fill" />

    <!-- Button controls for play, pause, resume, and stop. -->
  <StackPanel HorizontalAlignment="Center" Width="260" Orientation="Horizontal">
    <Image Name="PlayButton" Source="images\UI_play.gif" Margin="30,10,10,10" />
    <Image Name="PauseButton" Source="images\UI_pause.gif" Margin="10" />
    <Image Name="ResumeButton" Source="images\UI_resume.gif" Margin="10" />
    <Image Name="StopButton" Source="images\UI_stop.gif" Margin="10" />
  </StackPanel>

  <!-- Ths slider shows the progress of the media. -->
  <Slider Name="timelineSlider" Margin="5" Width="250" HorizontalAlignment="Center"/>

  <StackPanel.Triggers>
    <EventTrigger RoutedEvent="Image.MouseDown" SourceName="PlayButton">
      <EventTrigger.Actions>
        <BeginStoryboard Name= "myBegin">
          
          <Storyboard SlipBehavior="Slip">

            <!-- The MediaTimeline controls the timing of the video and acts like other Timeline objects.  
                 For example, although the video clip (numbers.wmv) lasts longer, playback ends after six  
                 seconds because that is the duration of the MediaTimeline (Duration="0:0:6"). -->
            <MediaTimeline Source="media\numbers.wmv" Storyboard.TargetName="myMediaElement"  
             BeginTime="0:0:0" Duration="0:0:6" CurrentTimeInvalidated="MediaTimeChanged" />
            
          </Storyboard>
        </BeginStoryboard>
      </EventTrigger.Actions>
    </EventTrigger>

    <!-- These triggers impliment the functionality of the Pause, Resume
         and Stop buttons.-->
    <EventTrigger RoutedEvent="Image.MouseDown" SourceName="PauseButton">
      <EventTrigger.Actions>
        <PauseStoryboard BeginStoryboardName="myBegin" />
      </EventTrigger.Actions>
    </EventTrigger>
    <EventTrigger RoutedEvent="Image.MouseDown" SourceName="ResumeButton">
      <EventTrigger.Actions>
        <ResumeStoryboard BeginStoryboardName="myBegin" />
      </EventTrigger.Actions>
    </EventTrigger>
    <EventTrigger RoutedEvent="Image.MouseDown" SourceName="StopButton">
      <EventTrigger.Actions>
        <StopStoryboard BeginStoryboardName="myBegin" />
      </EventTrigger.Actions>
    </EventTrigger>
  </StackPanel.Triggers>
  
</StackPanel>
</Page>
```

以下示例创建进度栏的功能。

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;

namespace SDKSample
{

    public partial class MediaTimelineExample : Page
    {
        // When the media opens, initialize the "Seek To" slider maximum value
        // to the total number of miliseconds in the length of the media clip.
        private void Element_MediaOpened(object sender, EventArgs e)
        {
            timelineSlider.Maximum = myMediaElement.NaturalDuration.TimeSpan.TotalMilliseconds;
        }

        private void MediaTimeChanged(object sender, EventArgs e)
        {
            timelineSlider.Value = myMediaElement.Position.TotalMilliseconds;
        }

    }
}
```

### [Trigger Media Playback with a User Event](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-trigger-media-playback-with-a-user-event)

此示例演示如何将媒体播放与事件同步。

#### 示例

下面的示例使用[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)控件和[MediaTimeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediatimeline)类，以播放声音，当用户单击时发生[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml" >
  <StackPanel>

    <!-- The MediaElement control plays the sound. -->
    <MediaElement Name="myMediaElement" />

    <Button>Click to Hear a Sound!
      <Button.Triggers>
        <EventTrigger RoutedEvent="Button.Click">
          <EventTrigger.Actions>
            <BeginStoryboard>
              <Storyboard>

                <!-- Sound wave from this source is played when the button is clicked.-->
                <MediaTimeline Source="C:\WINDOWS\Media\ringin.wav" Storyboard.TargetName="myMediaElement"  />

              </Storyboard>
            </BeginStoryboard>
          </EventTrigger.Actions>
        </EventTrigger>
      </Button.Triggers>
    </Button>

  </StackPanel>
</Page>
```

### [Repeat Media Playback](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-repeat-media-playback)

此示例演示如何无限期播放媒体，即设置媒体使其以无限循环方式播放。

#### 示例

下面的示例使用[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)并[MediaTimeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediatimeline)中[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)以无限循环方式播放媒体剪辑。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml" >
  <StackPanel>

    <!-- The MediaElement control plays the sound. -->
    <MediaElement Name="myMediaElement" >
      <MediaElement.Triggers>
        <EventTrigger RoutedEvent="MediaElement.Loaded">
          <EventTrigger.Actions>
            <BeginStoryboard>
              <Storyboard>

                <!-- The MediaTimeline has a RepeatBehavior="Forever" which makes the media play
                     over and over indefinitely.-->
                <MediaTimeline Source="media\tada.wav" Storyboard.TargetName="myMediaElement"  
                 RepeatBehavior="Forever" />

              </Storyboard>
            </BeginStoryboard>
          </EventTrigger.Actions>
        </EventTrigger>
      </MediaElement.Triggers>
    </MediaElement>

  </StackPanel>
</Page>
```

### [Play Media with Animations](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-play-media-with-animations)

此示例演示如何通过使用在同一时间播放媒体和动画[MediaTimeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediatimeline)并[DoubleAnimationUsingKeyFrames](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimationusingkeyframes)中相同的类[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)。

#### 示例

可以使用一个或多个[MediaTimeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.mediatimeline)中的对象[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)与其他[Timeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline)对象，例如动画。

下面的示例设置[SlipBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.paralleltimeline.slipbehavior)的属性[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)的值为`Slip`，它指定动画不播放之前在媒体 （在此示例中为视频） 进行。 如果媒体播放因加载时间而延迟，可能需要此功能。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml" >
  <Canvas>

    <!-- Upper right hand Canvas contains the animations. -->
    <Border BorderBrush="Black" BorderThickness="1"  Canvas.Left="250">
      <Canvas Width="250" Height="250" Background="White" >

        <!-- The two Path elements below create the purple and gold rings
             which are animated while the media is played. -->
        <Path Stroke="Purple" StrokeThickness="5">
          <Path.Data>
            <EllipseGeometry x:Name="MyEllipseGeometry" 
            Center="125,125" RadiusX="15" RadiusY="10" />
          </Path.Data>
        </Path>
        <Path Stroke="Gold" StrokeThickness="5">
          <Path.Data>
            <EllipseGeometry x:Name="MyEllipseGeometry2" 
            Center="125,125" RadiusX="10" RadiusY="15" />
          </Path.Data>
        </Path>
      </Canvas>
    </Border>

    <!-- Upper left hand Canvas contains the video. -->
    <Canvas Width="250" Height="250" Background="Green">
      <MediaElement Name="myvideo" Width="250" Height="250" 
       Canvas.Left="0" Canvas.Top="0">
        <MediaElement.Triggers>
          <EventTrigger RoutedEvent="MediaElement.Loaded">
            <EventTrigger.Actions>
              <BeginStoryboard>

                <!-- This Storyboard contains both media (video in this example) and animations. Note 
               the SlipBehavior value of "Slip" specifies that the animation does not progress
               until the media progresses. This might be desirable if media playback is delayed
               because of loading time. -->
                <Storyboard SlipBehavior="Slip">

                  <!-- The MediaTimeline controls the timing of the video and acts like other Timeline objects.  
                 For example, although the video clip (numbers.wmv) lasts longer, playback ends after six  
                 seconds because that is the duration of the MediaTimeline (Duration="0:0:6"). -->
                  <MediaTimeline Source="media\numbers.wmv" BeginTime="0:0:0" Duration="0:0:10"/>

                  <!-- The animations below animate the ellipses in the right hand pane. These animations are 
                 timed to correspond to the counting in the video. -->

                  <!-- Animate the RadiusY property of the purple ellipse. -->
                  <DoubleAnimationUsingKeyFrames
                    Storyboard.TargetName="MyEllipseGeometry"
                    Storyboard.TargetProperty="RadiusY"
                    RepeatBehavior="10x">
                    <DoubleAnimationUsingKeyFrames.KeyFrames>
                      <LinearDoubleKeyFrame Value="80" KeyTime="0:0:0.4" />
                      <SplineDoubleKeyFrame KeySpline="0.6,0.0 0.9,0.00" Value="0" KeyTime="0:0:1" />
                    </DoubleAnimationUsingKeyFrames.KeyFrames>
                  </DoubleAnimationUsingKeyFrames>

                  <!-- Animate the RadiusX property of the gold ellipse. -->
                  <DoubleAnimationUsingKeyFrames
                    Storyboard.TargetName="MyEllipseGeometry2"
                    Storyboard.TargetProperty="RadiusX"
                    RepeatBehavior="10x">
                    <DoubleAnimationUsingKeyFrames.KeyFrames>
                      <LinearDoubleKeyFrame Value="80" KeyTime="0:0:0.4" />
                      <SplineDoubleKeyFrame KeySpline="0.6,0.0 0.9,0.00" Value="0" KeyTime="0:0:1" />
                    </DoubleAnimationUsingKeyFrames.KeyFrames>
                  </DoubleAnimationUsingKeyFrames>

                </Storyboard>
              </BeginStoryboard>
            </EventTrigger.Actions>
          </EventTrigger>
        </MediaElement.Triggers>
      </MediaElement>
    </Canvas>
    
  </Canvas>
</Page>
```

### [Use Transforms on a MediaElement](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-use-transforms-on-a-mediaelement)

此示例演示如何使用[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)上[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)。

#### 示例

在下列标记中，[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)使用转动[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)。

```xaml
<MediaElement Source="media/numbers-aud.wmv">
  <MediaElement.LayoutTransform>
    <TransformGroup>
      <RotateTransform Angle="305" />
    </TransformGroup>
  </MediaElement.LayoutTransform>
</MediaElement>
```