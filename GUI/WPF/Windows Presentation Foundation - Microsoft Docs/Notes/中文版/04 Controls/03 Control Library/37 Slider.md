# [Slider](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/slider)

[Slider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider)允许您从一系列的值选择通过移动[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)沿[Track](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.track)。

下图显示的水平示例[Slider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider)控件。

![具有刻度线标记的水平滑块](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/ss-ctl-hslider-ticks.png)

## [Customize the Ticks on a Slider](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-customize-the-ticks-on-a-slider)

此示例演示如何创建[Slider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider)带有刻度的控件。

[TickBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.tickbar)设置时将显示[TickPlacement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider.tickplacement)属性的值以外的其他[None](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.tickplacement#System_Windows_Controls_Primitives_TickPlacement_None)，这是默认值。

下面的示例演示如何创建[Slider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider)与[TickBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.tickbar)显示刻度。 [TickPlacement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider.tickplacement)和[TickFrequency](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider.tickfrequency)属性定义刻度线和它们之间的间隔的位置。 当您移动[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)，工具提示显示的值[Slider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider)。 [AutoToolTipPlacement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider.autotooltipplacement)属性定义工具提示的出现。[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)移动对应于刻度线的位置，因为[IsSnapToTickEnabled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider.issnaptotickenabled)设置为`true`。

下面的示例演示如何使用[Ticks](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider.ticks)属性来创建刻度线沿[Slider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider)不规则间隔。

```xaml
 <Slider Width="100" Value="50" Orientation="Horizontal" HorizontalAlignment="Left" 
IsSnapToTickEnabled="True" Maximum="3" TickPlacement="BottomRight" 
AutoToolTipPlacement="BottomRight" AutoToolTipPrecision="2" 
Ticks="0, 1.1, 2.5, 3"/>
```