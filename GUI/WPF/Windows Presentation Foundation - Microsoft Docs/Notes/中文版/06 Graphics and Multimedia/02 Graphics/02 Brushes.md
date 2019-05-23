# [Brushes](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/brushes)

以下主题介绍如何使用Windows Presentation Foundation (WPF)画笔"绘制"到屏幕的内容

## 本节内容

[WPF 画笔概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/wpf-brushes-overview)
[画笔转换概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/brush-transformation-overview)
[不透明蒙板概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/opacity-masks-overview)
[使用纯色和渐变进行绘制概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-solid-colors-and-gradients-overview)
[使用图像、绘图和视觉对象进行绘制](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-images-drawings-and-visuals)
[TileBrush 概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/tilebrush-overview)
[帮助主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/brushes-how-to-topics)

## [WPF Brushes Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/wpf-brushes-overview)

在屏幕上可见的所有内容是可见的因为它通过画笔绘制。 例如，画笔用于描述背景的按钮、 文本、 前的景色和形状的填充。 本主题介绍的概念与绘制Windows Presentation Foundation (WPF)画笔，并提供示例。 借助画笔，可以利用任意内容（从简单的纯色到复杂的图案和图像集）绘制 用户界面 (UI) 对象。

#### 使用画笔进行绘制

一个[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)"绘制"其输出区域。 不同画笔具有不同类型的输出。 某些画笔绘制用纯色，其他人使用渐变、 模式、 图像或绘图区域。 下图显示了每个不同的示例[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)类型。

![画笔类型](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-brushtypes.jpg)
画笔示例

大多数的视觉对象，可以指定绘制方式。 下表列出了一些常见对象和属性可以使用[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)。

| 类                                                           | 画笔属性                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border) | [BorderBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border.borderbrush)， [Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border.background) |
| [Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control) | [Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background), [Foreground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.foreground) |
| [Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel) | [Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.background) |
| [Pen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pen) | [Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pen.brush) |
| [Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape) | [Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)， [Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.stroke) |
| [TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock) | [Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.background) |

以下各节介绍了不同[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)类型，并提供每个示例。

#### 使用纯色进行绘制

一个[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)使用纯色绘制区域[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.color)。 有多种方式来指定[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush.color)的[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)： 例如，您可以指定其 alpha、 红色、 蓝色和绿色通道或使用提供的预定义的颜色之一[Colors](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.colors)类。

下面的示例使用[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)绘制[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)的[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)。 下图显示绘制的矩形。

![使用 SolidColorBrush 绘制的矩形](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-brush-ovw-solidcolorbrush.png)
使用 SolidColorBrush 绘制的矩形

```csharp
Rectangle exampleRectangle = new Rectangle();
exampleRectangle.Width = 75;
exampleRectangle.Height = 75;

// Create a SolidColorBrush and use it to
// paint the rectangle.
SolidColorBrush myBrush = new SolidColorBrush(Colors.Red);
exampleRectangle.Fill = myBrush;
```

```xaml
<Rectangle Width="75" Height="75">
  <Rectangle.Fill>
    <SolidColorBrush Color="Red" />
  </Rectangle.Fill>
</Rectangle>
```

有关详细信息[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)类，请参阅[使用纯色和渐变概述进行绘制](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-solid-colors-and-gradients-overview)。

#### 使用线性渐变进行绘制

一个[LinearGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush)绘制带有线性渐变的区域。 线性渐变混合行，渐变轴跨两个或多个颜色。 您使用[GradientStop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientstop)对象渐变和它们的位置中指定的颜色。

下面的示例使用[LinearGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush)绘制[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)的[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)。 下图显示绘制的矩形。

![使用 LinearGradientBrush 绘制的矩形](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-brush-ovw-lineargradientbrush.jpg)
使用 LinearGradientBrush 绘制的矩形

```csharp
Rectangle exampleRectangle = new Rectangle();
exampleRectangle.Width = 75;
exampleRectangle.Height = 75;

// Create a LinearGradientBrush and use it to
// paint the rectangle.
LinearGradientBrush myBrush = new LinearGradientBrush();
myBrush.GradientStops.Add(new GradientStop(Colors.Yellow, 0.0));
myBrush.GradientStops.Add(new GradientStop(Colors.Orange, 0.5));
myBrush.GradientStops.Add(new GradientStop(Colors.Red, 1.0));

exampleRectangle.Fill = myBrush;
```

```xaml
<Rectangle Width="75" Height="75">
  <Rectangle.Fill>
    <LinearGradientBrush>
      <GradientStop Color="Yellow" Offset="0.0" />
      <GradientStop Color="Orange" Offset="0.5" />
      <GradientStop Color="Red" Offset="1.0" />
    </LinearGradientBrush>
  </Rectangle.Fill>
</Rectangle>
```

有关详细信息[LinearGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush)类，请参阅[使用纯色和渐变概述进行绘制](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-solid-colors-and-gradients-overview)。

#### 使用径向渐变进行绘制

一个[RadialGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.radialgradientbrush)使用径向渐变绘制区域。 径向渐变混合跨一个圆圈的两个或多个颜色。 如同[LinearGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush)类，使用[GradientStop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientstop)对象渐变和它们的位置中指定的颜色。

下面的示例使用[RadialGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.radialgradientbrush)绘制[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)的[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)。 下图显示绘制的矩形。

![使用 RadialGradientBrush 绘制的矩形](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-brush-ovw-radialgradientbrush.jpg)
使用 RadialGradientBrush 绘制的矩形

```csharp
Rectangle exampleRectangle = new Rectangle();
exampleRectangle.Width = 75;
exampleRectangle.Height = 75;

// Create a RadialGradientBrush and use it to
// paint the rectangle.
RadialGradientBrush myBrush = new RadialGradientBrush();
myBrush.GradientOrigin = new Point(0.75, 0.25);
myBrush.GradientStops.Add(new GradientStop(Colors.Yellow, 0.0));
myBrush.GradientStops.Add(new GradientStop(Colors.Orange, 0.5));
myBrush.GradientStops.Add(new GradientStop(Colors.Red, 1.0));

exampleRectangle.Fill = myBrush;
```

```xaml
<Rectangle Width="75" Height="75">
  <Rectangle.Fill>
    <RadialGradientBrush GradientOrigin="0.75,0.25">
      <GradientStop Color="Yellow" Offset="0.0" />
      <GradientStop Color="Orange" Offset="0.5" />
      <GradientStop Color="Red" Offset="1.0" />
    </RadialGradientBrush>
  </Rectangle.Fill>
</Rectangle>
```

有关详细信息[RadialGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.radialgradientbrush)类，请参阅[使用纯色和渐变概述进行绘制](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-solid-colors-and-gradients-overview)。

#### 使用图像进行绘制

[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)使用绘制区域[ImageSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagesource)。

下面的示例使用[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)绘制[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)的[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)。 下图显示绘制的矩形。

![使用 imagebrush 绘制的矩形](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-brush-ovw-imagebrush.jpg)
使用图像绘制的矩形

```csharp
Rectangle exampleRectangle = new Rectangle();
exampleRectangle.Width = 75;
exampleRectangle.Height = 75;

// Create an ImageBrush and use it to
// paint the rectangle.
ImageBrush myBrush = new ImageBrush();
myBrush.ImageSource = 
    new BitmapImage(new Uri(@"sampleImages\pinkcherries.jpg", UriKind.Relative));

exampleRectangle.Fill = myBrush;
```

```xaml
<Rectangle Width="75" Height="75">
  <Rectangle.Fill>
    <ImageBrush ImageSource="sampleImages\pinkcherries.jpg"  />
  </Rectangle.Fill>
</Rectangle>
```

有关详细信息[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)类，请参阅[使用图像、 绘图和视觉对象进行绘制](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-images-drawings-and-visuals)。

#### 使用绘图进行绘制

一个[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)使用绘制区域[Drawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawing)。 一个[Drawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawing)可以包含形状、 图像、 文本和媒体。

下面的示例使用[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)绘制[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)的[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)。 下图显示绘制的矩形。

![使用 DrawingBrush 绘制的矩形](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-brush-ovw-drawingbrush.jpg)
使用 DrawingBrush 绘制的矩形

```csharp
Rectangle exampleRectangle = new Rectangle();
exampleRectangle.Width = 75;
exampleRectangle.Height = 75;

// Create a DrawingBrush and use it to
// paint the rectangle.
DrawingBrush myBrush = new DrawingBrush();

GeometryDrawing backgroundSquare =
    new GeometryDrawing(
        Brushes.White,
        null,
        new RectangleGeometry(new Rect(0, 0, 100, 100)));

GeometryGroup aGeometryGroup = new GeometryGroup();
aGeometryGroup.Children.Add(new RectangleGeometry(new Rect(0, 0, 50, 50)));
aGeometryGroup.Children.Add(new RectangleGeometry(new Rect(50, 50, 50, 50)));

LinearGradientBrush checkerBrush = new LinearGradientBrush();
checkerBrush.GradientStops.Add(new GradientStop(Colors.Black, 0.0));
checkerBrush.GradientStops.Add(new GradientStop(Colors.Gray, 1.0));

GeometryDrawing checkers = new GeometryDrawing(checkerBrush, null, aGeometryGroup);

DrawingGroup checkersDrawingGroup = new DrawingGroup();
checkersDrawingGroup.Children.Add(backgroundSquare);
checkersDrawingGroup.Children.Add(checkers);

myBrush.Drawing = checkersDrawingGroup;
myBrush.Viewport = new Rect(0, 0, 0.25, 0.25);
myBrush.TileMode = TileMode.Tile;

exampleRectangle.Fill = myBrush;
```

```xaml
<Rectangle Width="75" Height="75">
  <Rectangle.Fill>
    <DrawingBrush Viewport="0,0,0.25,0.25" TileMode="Tile">
      <DrawingBrush.Drawing>
        <DrawingGroup>
          <GeometryDrawing Brush="White">
            <GeometryDrawing.Geometry>
              <RectangleGeometry Rect="0,0,100,100" />
            </GeometryDrawing.Geometry>
          </GeometryDrawing>

          <GeometryDrawing>
            <GeometryDrawing.Geometry>
              <GeometryGroup>
                <RectangleGeometry Rect="0,0,50,50" />
                <RectangleGeometry Rect="50,50,50,50" />
              </GeometryGroup>
            </GeometryDrawing.Geometry>
            <GeometryDrawing.Brush>
              <LinearGradientBrush>
                <GradientStop Offset="0.0" Color="Black" />
                <GradientStop Offset="1.0" Color="Gray" />
              </LinearGradientBrush>
            </GeometryDrawing.Brush>
          </GeometryDrawing>
        </DrawingGroup>
      </DrawingBrush.Drawing>
    </DrawingBrush>
  </Rectangle.Fill>
</Rectangle>
```

有关详细信息[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)类，请参阅[使用图像、 绘图和视觉对象进行绘制](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-images-drawings-and-visuals)。

#### 使用视觉对象进行绘制

一个[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)使用绘制区域[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)对象。 视觉对象的示例包括[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)， [Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)，和[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)。 一个[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)，还可以将内容从一部分到另一个区域，则应用程序是用于创建反射效果和放大屏幕的部分非常有用。

下面的示例使用[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)绘制[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)的[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)。 下图显示绘制的矩形。

![使用 VisualBrush 绘制的矩形](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-brush-ovw-visualbrush.jpg)
使用 VisualBrush 绘制的矩形

```csharp
Rectangle exampleRectangle = new Rectangle();
exampleRectangle.Width = 75;
exampleRectangle.Height = 75;

// Create a VisualBrush and use it
// to paint the rectangle.
VisualBrush myBrush = new VisualBrush();

//
// Create the brush's contents.
//
StackPanel aPanel = new StackPanel();

// Create a DrawingBrush and use it to
// paint the panel.
DrawingBrush myDrawingBrushBrush = new DrawingBrush();
GeometryGroup aGeometryGroup = new GeometryGroup();
aGeometryGroup.Children.Add(new RectangleGeometry(new Rect(0, 0, 50, 50)));
aGeometryGroup.Children.Add(new RectangleGeometry(new Rect(50, 50, 50, 50)));
RadialGradientBrush checkerBrush = new RadialGradientBrush();
checkerBrush.GradientStops.Add(new GradientStop(Colors.MediumBlue, 0.0));
checkerBrush.GradientStops.Add(new GradientStop(Colors.White, 1.0));
GeometryDrawing checkers = new GeometryDrawing(checkerBrush, null, aGeometryGroup);
myDrawingBrushBrush.Drawing = checkers;
aPanel.Background = myDrawingBrushBrush;

// Create some text.
TextBlock someText = new TextBlock();
someText.Text = "Hello, World";
FontSizeConverter fSizeConverter = new FontSizeConverter();
someText.FontSize = (double)fSizeConverter.ConvertFromString("10pt");
someText.Margin = new Thickness(10);

aPanel.Children.Add(someText);

myBrush.Visual = aPanel;
exampleRectangle.Fill = myBrush;
```

```xaml
<Rectangle Width="75" Height="75">
  <Rectangle.Fill>
    <VisualBrush TileMode="Tile">
      <VisualBrush.Visual>
        <StackPanel>
          <StackPanel.Background>
            <DrawingBrush>
              <DrawingBrush.Drawing>
                <GeometryDrawing>
                  <GeometryDrawing.Brush>
                    <RadialGradientBrush>
                      <GradientStop Color="MediumBlue" Offset="0.0" />
                      <GradientStop Color="White" Offset="1.0" />
                    </RadialGradientBrush>
                  </GeometryDrawing.Brush>
                  <GeometryDrawing.Geometry>
                    <GeometryGroup>
                      <RectangleGeometry Rect="0,0,50,50" />
                      <RectangleGeometry Rect="50,50,50,50" />
                    </GeometryGroup>
                  </GeometryDrawing.Geometry>
                </GeometryDrawing>
              </DrawingBrush.Drawing>
            </DrawingBrush>
          </StackPanel.Background>
          <TextBlock FontSize="10pt" Margin="10">Hello, World!</TextBlock>
        </StackPanel>
      </VisualBrush.Visual>
    </VisualBrush>
  </Rectangle.Fill>
</Rectangle>
```

有关详细信息[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)类，请参阅[使用图像、 绘图和视觉对象进行绘制](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-images-drawings-and-visuals)。

#### 使用预定义画笔和系统画笔进行绘制

为方便起见，Windows Presentation Foundation (WPF) 提供了一组预定义的系统画笔用于绘制对象。

- 有关可用的预定义画笔的列表，请参阅[Brushes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brushes)类。 有关演示如何使用预定义的画笔的示例，请参阅[使用纯色绘制区域](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-paint-an-area-with-a-solid-color)。
- 有关可用的系统画笔的列表，请参阅[SystemColors](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemcolors)类。 有关示例，请参阅[使用系统画笔绘制区域](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-paint-an-area-with-a-system-brush)。

#### 常见的画笔功能

[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush) 对象提供[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.opacity)属性，可用于使画笔显示为透明或部分透明。 [Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.opacity)值为 0，则画笔完全透明，而[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.opacity)值为 1，则画笔完全不透明。 下面的示例使用[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.opacity)属性以使[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)25%不透明。

```xaml
<Rectangle Width="100" Height="100">
  <Rectangle.Fill>
    <SolidColorBrush Color="Blue" Opacity="0.25" />
  </Rectangle.Fill>
</Rectangle>
```

```csharp
Rectangle myRectangle = new Rectangle();
myRectangle.Width = 100;
myRectangle.Height = 100;
SolidColorBrush partiallyTransparentSolidColorBrush
    = new SolidColorBrush(Colors.Blue);
partiallyTransparentSolidColorBrush.Opacity = 0.25;
myRectangle.Fill = partiallyTransparentSolidColorBrush;
```

如果画笔包含部分透明的颜色，颜色的不透明度值通过画笔的不透明度值相乘相结合。 例如，如果画笔的不透明度值 0.5 和画笔中使用的颜色还具有 0.5 的不透明度值，输出颜色具有 0.25 的不透明度值。

> 若要更改一个画笔的不透明度值更改整个元素使用的不透明度比效率更高其[UIElement.Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)属性。

可以旋转、 缩放、 倾斜和转换画笔的内容通过使用其[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.transform)或[RelativeTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.relativetransform)属性。 有关详细信息，请参阅[画笔转换概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/brush-transformation-overview)。

因为它们[Animatable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animatable)对象，[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)对象可进行动画处理。 有关详细信息，请参阅 [动画概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/animation-overview)。

#### Freezable 功能

因为它继承自[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)类，[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)类提供多种特殊功能：[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)对象可声明为[资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-resources)、 在多个对象之间共享和克隆。此外，所有[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)除类型[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)可以变为只读以提高性能并变为线程安全。

有关所提供的不同功能的详细信息[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)对象，请参阅[Freezable 对象概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/freezable-objects-overview)。

有关原因的详细信息[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)对象不能为冻结，请参阅[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)类型页。

## [Brush Transformation Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/brush-transformation-overview)

Brush 类提供两个转换属性：[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.transform)和[RelativeTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.relativetransform)。 使用这些属性，可以旋转、缩放、倾斜和转换画笔的内容。 本主题介绍这两个属性之间的区别，并提供有关它们的用法示例。

#### 系统必备

若要了解本主题，应了解要转换的画笔的功能。 有关[LinearGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush)并[RadialGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.radialgradientbrush)，请参阅[绘制使用纯色和渐变概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-solid-colors-and-gradients-overview)。 有关[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)， [DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)，或[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)，请参阅[使用图像、 绘图和视觉对象进行绘制](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-images-drawings-and-visuals)。 还应当熟悉[转换概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/transforms-overview)中所述的 2D 转换。

#### Transform 和 RelativeTransform 属性之间的区别

当转换应用到画笔的[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.transform)属性，则需要知道绘制区域的大小，如果你想要转换画笔内容围绕其中心。 假设已绘制区域的宽度为 200 个与设备无关的像素，高度为 150。 如果您使用了[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)旋转画笔的输出围绕其中心的 45 度，您将为[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)[CenterX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform.centerx)为 100 和[CenterY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform.centery)的 75。

当转换应用到画笔的[RelativeTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.relativetransform)属性，该转换应用到画笔输出映射到已绘制区域之前。 以下列表介绍处理和转换画笔内容的顺序。

1. 处理画笔的内容。 有关[GradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientbrush)，这意味着确定渐变区域。 有关[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)，则[Viewbox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewbox)映射到[Viewport](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewport)。 这成为画笔的输出。
2. 将画笔的输出投影到 1 x 1 的转换矩形上。
3. 应用画笔的[RelativeTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.relativetransform)，如果有的话。
4. 将转换后的输出投影到要绘制的区域上。
5. 应用画笔的[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transform)，如果有的话。

因为[RelativeTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.relativetransform)画笔的输出映射到 1 x 1 的矩形，转换中心和偏移的值看起来是相对时应用。 例如，如果您使用[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)旋转画笔的输出围绕其中心的 45 度，您将为[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)[CenterX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform.centerx)为 0.5 和[CenterY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform.centery)为 0.5。

下图显示了旋转 45 度为单位使用的几个画笔的输出[RelativeTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.relativetransform)和[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.transform)属性。

![RelativeTransform 和 Transform 属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-brushrelativetransform-transform-small.png)

#### 将 RelativeTransform 用于 TileBrush

由于平铺画笔比其他画笔更复杂，将应用[RelativeTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.relativetransform)到其中一个可能会产生意外的结果。 例如以下图像。

![源图像](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-reltransform-1-original-image.jpg)

下面的示例使用[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)绘制带有上述图像的矩形区域。 它适用[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)到[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)对象的[RelativeTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.relativetransform)属性，并设置其[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.stretch)属性设置为[UniformToFill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_UniformToFill)，这应在拉伸以完全填充矩形时保留图像的纵横比。

```xaml
<Rectangle Width="200" Height="100" Stroke="Black" StrokeThickness="1">
  <Rectangle.Fill>
    <ImageBrush Stretch="UniformToFill">
      <ImageBrush.ImageSource>
        <BitmapImage UriSource="sampleImages\square.jpg" />
      </ImageBrush.ImageSource>
      <ImageBrush.RelativeTransform>
        <RotateTransform CenterX="0.5" CenterY="0.5" Angle="90" />
      </ImageBrush.RelativeTransform>
    </ImageBrush>
  </Rectangle.Fill>
</Rectangle>
```

该示例产生下面的输出：

![转换后的输出](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-reltransform-6-output.png)

请注意，图像会扭曲，即使画笔[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.stretch)已设置为[UniformToFill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_UniformToFill)。 这是因为后的画笔应用相对转换[Viewbox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewbox)映射到其[Viewport](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewport)。 以下列表介绍该过程的每个步骤：

1. 项目将画笔的内容 ([Viewbox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewbox)) 到其基本磁贴上 ([Viewport](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewport)) 使用画笔的[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.stretch)设置。

   ![拉伸 Viewbox 以适合于视区](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-reltransform-2-viewbox-to-viewport.png)

2. 将基本图块投影到 1 x 1 的转换矩形上。

   ![将 Viewport 映射到转换矩形](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-reltransform-3-output-to-transform.png)

3. 将应用[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)。

   ![应用相对转换 ](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-reltransform-4-transform-rotate.png)

4. 将转换后的基本图块投影到要绘制的区域上。

   ![将转换后的画笔投影到输出区域上](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-reltransform-5-transform-to-output.png)



#### 示例:将 ImageBrush 旋转 45 度

下面的示例应用[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)到[RelativeTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.relativetransform)属性的[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)。 [RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)对象的[CenterX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform.centerx)和[CenterY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform.centery)属性均设置为 0.5，此内容的中心相对坐标点。 因此，画笔的内容围绕其中心旋转。

```csharp
//
// Create an ImageBrush with a relative transform and
// use it to paint a rectangle.
//
ImageBrush relativeTransformImageBrush = new ImageBrush();
relativeTransformImageBrush.ImageSource =
    new BitmapImage(new Uri(@"sampleImages\pinkcherries.jpg", UriKind.Relative));

// Create a 45 rotate transform about the brush's center
// and apply it to the brush's RelativeTransform property.
RotateTransform aRotateTransform = new RotateTransform();
aRotateTransform.CenterX = 0.5; 
aRotateTransform.CenterY = 0.5;
aRotateTransform.Angle = 45;
relativeTransformImageBrush.RelativeTransform = aRotateTransform;

// Use the brush to paint a rectangle.
Rectangle relativeTransformImageBrushRectangle = new Rectangle();
relativeTransformImageBrushRectangle.Width = 175;
relativeTransformImageBrushRectangle.Height = 90;
relativeTransformImageBrushRectangle.Stroke = Brushes.Black;
relativeTransformImageBrushRectangle.Fill = relativeTransformImageBrush;
```

```xaml
<Rectangle Width="175" Height="90" Stroke="Black">
  <Rectangle.Fill>
    <ImageBrush ImageSource="sampleImages\pinkcherries.jpg">
      <ImageBrush.RelativeTransform>
        <RotateTransform CenterX="0.5" CenterY="0.5" Angle="45" />
      </ImageBrush.RelativeTransform>
    </ImageBrush>
  </Rectangle.Fill>
</Rectangle>
```

下一个示例也适用[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)到[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)，但使用[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.transform)属性，而不是[RelativeTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.relativetransform)属性。 若要使画笔围绕其中心旋转[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)对象的[CenterX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform.centerx)和[CenterY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform.centery)必须设置为绝对坐标。 由于画笔要绘制的矩形为 175 x 90 像素，因此它的中心点为 (87.5, 45)。

```csharp
//
// Create an ImageBrush with a transform and
// use it to paint a rectangle.
//
ImageBrush transformImageBrush = new ImageBrush();
transformImageBrush.ImageSource =
    new BitmapImage(new Uri(@"sampleImages\pinkcherries.jpg", UriKind.Relative));

// Create a 45 rotate transform about the brush's center
// and apply it to the brush's Transform property.
RotateTransform anotherRotateTransform = new RotateTransform();
anotherRotateTransform.CenterX = 87.5;
anotherRotateTransform.CenterY = 45;
anotherRotateTransform.Angle = 45;
transformImageBrush.Transform = anotherRotateTransform;

// Use the brush to paint a rectangle.
Rectangle transformImageBrushRectangle = new Rectangle();
transformImageBrushRectangle.Width = 175;
transformImageBrushRectangle.Height = 90;
transformImageBrushRectangle.Stroke = Brushes.Black;
transformImageBrushRectangle.Fill = transformImageBrush;
```

```xaml
<Rectangle Width="175" Height="90" Stroke="Black">
  <Rectangle.Fill>
    <ImageBrush ImageSource="sampleImages\pinkcherries.jpg">
      <ImageBrush.Transform>
        <RotateTransform CenterX="87.5" CenterY="45" Angle="45" />
      </ImageBrush.Transform>
    </ImageBrush>
  </Rectangle.Fill>
</Rectangle>
```

下图显示没有转换，将转换应用到画笔[RelativeTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.relativetransform)属性，并将转换应用到[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.transform)属性。

![画笔 RelativeTransform 和 Transform 设置](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wcpsdk-graphicsmm-transformandrelativetransform.png)

此示例摘自一个更大的示例。 有关完整示例，请参阅[画笔示例](https://go.microsoft.com/fwlink/?LinkID=159973)。 有关画笔的详细信息，请参阅 [WPF 画笔概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/wpf-brushes-overview)。

## [Opacity Masks Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/opacity-masks-overview)

不透明蒙板能够使部分元素或视觉对象透明或部分透明。 若要创建不透明蒙板，则应用[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)到[OpacityMask](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacitymask)元素的属性或[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)。 画笔映射到元素或视觉对象，并且画笔的每个像素的不透明度值用于确定生成的元素或视觉对象的每个相应像素的不透明度。

#### 系统必备

本概述假定您熟悉[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)对象。 有关使用画笔的介绍，请参阅[使用纯色和渐变进行绘制概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-solid-colors-and-gradients-overview)。 璝惠[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)并[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)，请参阅[使用图像、 绘图和视觉对象进行绘制](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-images-drawings-and-visuals)。

#### 使用不透明蒙板创建视觉效果

不透明蒙板的工作原理是将其内容映射到元素或视觉对象。 画笔像素的 alpha 通道则用于确定生成的元素或视觉对象相应像素的不透明度；将忽略画笔的实际颜色。 如果画笔的指定部分是透明的，则元素或视觉对象的相应部分将变为透明。 如果画笔的指定部分是不透明的，则元素或视觉对象的相应部分未改变。 不透明蒙板指定的不透明度与元素或视觉对象呈现的任何不透明度设置相结合。 例如：如果某个元素的不透明度是 25% 并且从完全不透明过渡完全透明时应用不透明蒙板，结果是元素从 25% 的不透明过渡到完全透明。

> 虽然此概述中的示例演示如何在图像元素上的不透明蒙板，但不透明蒙板可以应用于任何元素或[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)，包括面板和控件。

不透明蒙板用于创建有趣的视觉效果，如创建从视图淡入淡出的图像或按钮、向元素添加纹理或结合渐变产生玻璃般的图面。 以下图示演示了不透明蒙板的使用。 棋盘格的背景用于显示蒙板的透明部分。

![具有 LinearGradientBrush 不透明蒙版的对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wcpsdk-graphicsmm-opacitymask-imageexample.png)
不透明蒙板示例

#### 创建不透明蒙板

若要创建不透明蒙板，你可以创建[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)并将其应用于[OpacityMask](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacitymask)元素或视觉对象的属性。 可以使用任何类型的[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)作为不透明蒙板。

- [LinearGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush), [RadialGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.radialgradientbrush):用于使元素或从视图 visual 淡入淡出。

  下图显示了[LinearGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush)用作不透明蒙板。

  ![具有 LinearGradientBrush 不透明蒙版的对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wcpsdk-graphicsmm-brushes-lineagradientopacitymasksingle.jpg)
  LinearGradientBrush 不透明蒙板示例

- [ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)：用于创建纹理和软或撕裂边缘效果。

  下图显示了[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)用作不透明蒙板。

  ![具有 ImageBrush 不透明蒙版的对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wcpsdk-graphicsmm-brushes-imageasopacitymasksingle.jpg)
  LinearGradientBrush 不透明蒙板示例

- [DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)：用于从形状、 图像和渐变的模式创建复杂的不透明蒙板。

  下图显示了[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)用作不透明蒙板。

  ![具有 DrawingBrush 不透明蒙版的对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wcpsdk-drawingbrushasopacitymask-single.jpg)
  DrawingBrush 不透明蒙板示例

渐变画笔 ([LinearGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush)和[RadialGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.radialgradientbrush)) 非常适合用作不透明蒙板。 因为[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)将区域用统一颜色填充，它们使不佳的不透明度屏蔽; 使用[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)等效于设置元素或视觉对象的[OpacityMask](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacitymask)属性。

#### 将渐变用作不透明蒙板

要创建渐变填充，请指定两个或多个梯度停止点。 每个渐变停止点包含描述一种颜色和位置（请参阅[使用纯色和渐变进行绘制概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-solid-colors-and-gradients-overview)了解关于创建和使用渐变的更多信息）。 将渐变用作不透明蒙板时，除非不使用混合颜色，由不透明蒙板渐变混合 alpha 通道值，否则过程相同。 因此，渐变内容的实际颜色并不重要；只有 alpha 通道或每种颜色的不透明度很重要。 下面是一个示例。

```xaml
<!--With the opacity mask:--> 
<Image
  Width="200" Height="150"
  Source="sampleImages\Waterlilies.jpg"
  Margin="10"
  HorizontalAlignment="Left"
  Grid.Column="2" Grid.Row="3">
  <Image.OpacityMask>
    <LinearGradientBrush StartPoint="0.1,0.1" EndPoint="0.75,0.75">
      <LinearGradientBrush.GradientStops>
        <GradientStop Offset="0" Color="Black"/>
        <GradientStop Offset="1" Color="Transparent"/>
      </LinearGradientBrush.GradientStops>
    </LinearGradientBrush>
  </Image.OpacityMask>
</Image>
```

#### 为不透明蒙板指定梯度停止点

在上一示例中，系统定义颜色[Black](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.colors.black)用作渐变的开始颜色。 因为所有中的颜色[Colors](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.colors)类，除[Transparent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.colors.transparent)，是完全不透明，它们可以用于只需定义渐变不透明蒙板的起始颜色。

附加控制 alpha 值定义不透明蒙板时，可以指定使用的颜色的 alpha 通道ARGB标记中或使用十六进制表示法[Color.FromScRgb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.color.fromscrgb)方法。

##### 在“XAML”中指定颜色不透明度

在 可扩展应用程序标记语言 (XAML) 中，使用 ARGB 十六进制表示法指定个别颜色的不透明度。 ARGB 十六进制表示法使用下面语法：

`#` **aa** *rrggbb*

上一行中的 *aa* 表示用于指定颜色不透明度的两位十六进制值。 *rr*、*gg* 和 *bb* 分别表示用于指定颜色中的红色、绿色和蓝色量的两位十六进制值。 每个十六进制数字介于 0-9 或 A-F 之间。 0 是最小值，F 是最大值。 00 的 alpha 值指定完全透明的颜色，而 FF 的 alpha 值创建完全不透明的颜色。 在下面的示例中，十六进制 ARGB 表示法用于指定两种颜色。 第一种为完全不透明色，第二种为完全透明色。

```xaml
<Canvas.OpacityMask>
  <RadialGradientBrush>
    <RadialGradientBrush.GradientStops>
      <GradientStop Offset="0" Color="#FF000000"/>
      <GradientStop Offset="1" Color="#00000000"/>
  </RadialGradientBrush.GradientStops>
</RadialGradientBrush>
</Canvas.OpacityMask>
```

#### 将图像用作不透明蒙板

图像也可以用作不透明蒙板。 下面的图像显示了一个示例。 棋盘格的背景用于显示蒙板的透明部分。

![具有 ImageBrush 不透明蒙版的对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wcpsdk-graphicsmm-imageasopacitymask.png)
不透明蒙板示例

若要将图像用作不透明蒙板，请使用[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)包含图像。 创建要用作不透明蒙板的图像时，以支持多级别不透明度的格式保存图像，例如 可移植网络图形 (PNG)。 下面的示例显示了用于创建上图的代码。

```xaml
<!-- With the Opacity Mask-->
<Image
  Height="150"
  Width="200"
  Source="sampleImages/Waterlilies.jpg"
  HorizontalAlignment="Left"
  Margin="10"
  Grid.Column="2" Grid.Row="1">
  <Image.OpacityMask>
    <ImageBrush ImageSource="sampleImages/tornedges.png"/>
  </Image.OpacityMask>
</Image>
```

##### 将平铺图像用作不透明蒙板

在以下示例中，使用相同的映像与另一个[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)，但画笔的平铺功能用于生成的图像为 50 像素正方形磁贴。

```xaml
<!-- With the Opacity Mask -->
<Image
  Height="150"
  Width="200"
  Source="sampleImages/Waterlilies.jpg"
  HorizontalAlignment="Left"
  Margin="10"
  Grid.Column="2" Grid.Row="2">

  <Image.OpacityMask>
    <ImageBrush
      Viewport="0,0,50,50"
      ViewportUnits="Absolute"
      TileMode="Tile" 
      ImageSource="sampleImages/tornedges.png"/>
  </Image.OpacityMask>
</Image>
```

#### 通过图形创建不透明蒙板

图形可用作不透明蒙板。 图形中包含的形状可使用渐变、纯色、图像或甚至其他图形来填充它们自己。 下面的图像显示了图形用作不透明蒙板的示例。 棋盘格的背景用于显示蒙板的透明部分。

![具有 DrawingBrush 不透明蒙版的对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wcpsdk-drawingbrushasopacitymask.png)
DrawingBrush 不透明蒙板示例

若要将绘图用作不透明蒙板，请使用[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)包含图形。 下面的示例显示了用于创建上图的代码：

XAML复制

```xaml
<!-- With the Opacity Mask-->
<Image 
      Grid.Row="4" Grid.Column="5"
      Height="150"
      Width="200"
      Source="sampleImages/Waterlilies.jpg">
  <Image.OpacityMask>
    <DrawingBrush>
      <DrawingBrush.Drawing>
        <GeometryDrawing>
          <GeometryDrawing.Brush>
            <RadialGradientBrush>
              <RadialGradientBrush.GradientStops>
                <GradientStop Offset="0" Color="Black" />
                <GradientStop Offset="1" Color="Transparent" />
              </RadialGradientBrush.GradientStops>
            </RadialGradientBrush>
          </GeometryDrawing.Brush>
          <GeometryDrawing.Geometry>
            <RectangleGeometry Rect="0.05,0.05 0.9,0.9" />
          </GeometryDrawing.Geometry>
          <GeometryDrawing.Pen>
            <Pen Thickness="0.1" Brush="Black" />
          </GeometryDrawing.Pen>
        </GeometryDrawing>
      </DrawingBrush.Drawing>
    </DrawingBrush>
  </Image.OpacityMask>
</Image>
```

##### 将平铺图形用作不透明蒙板

像[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)，则[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)可用于平铺其图形。 在下面的示例中，图形画笔用于创建平铺的不透明蒙板。

```xaml
<!-- With the Opacity Mask-->
<Button
   Grid.Row="8" Grid.Column="5"
  Height="100"
  Width="200"
  FontFamily="MS Gothic"
  FontSize="16">
  A Button
  <Button.OpacityMask>
    <DrawingBrush Viewport="0,0,0.25,0.25" TileMode="Tile">
      <DrawingBrush.Drawing>
        <GeometryDrawing>
          <GeometryDrawing.Brush>
            <RadialGradientBrush>
              <RadialGradientBrush.GradientStops>
                <GradientStop Offset="0" Color="Black" />
                <GradientStop Offset="1" Color="Transparent" />
              </RadialGradientBrush.GradientStops>
            </RadialGradientBrush>
          </GeometryDrawing.Brush>
          <GeometryDrawing.Geometry>
            <RectangleGeometry Rect="0.05,0.05 0.9,0.9" />
          </GeometryDrawing.Geometry>
          <GeometryDrawing.Pen>
            <Pen Thickness="0.1" Brush="Black" />
          </GeometryDrawing.Pen>
        </GeometryDrawing>
      </DrawingBrush.Drawing>
    </DrawingBrush>
  </Button.OpacityMask>
</Button>
```

## [Painting with Solid Colors and Gradients Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/painting-with-solid-colors-and-gradients-overview)

本主题介绍如何使用[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)， [LinearGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush)，和[RadialGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.radialgradientbrush)对象用纯色、 线性渐变和径向渐变进行绘制。

#### 使用纯色绘制区域

在任何平台中最常见的操作之一是使用纯色绘制区域[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.color)。 若要完成此任务中，Windows Presentation Foundation (WPF)提供了[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)类。 以下部分介绍的不同方法来绘制与[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)。

##### 在“XAML”中使用 SolidColorBrush

若要在 XAML 中使用纯色绘制某个区域，请使用以下选项之一。

- 按照名称选择预定义的纯色画笔。 例如，可以设置按钮的[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)为"红色"或"中度蓝色"。 另一系列预定义的纯色画笔，请参阅的静态属性[Brushes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brushes)类。 下面是一个示例。

  ```xaml
  <!-- This button's background is painted with a red SolidColorBrush,
       described using a named color. -->
  <Button Background="Red">A Button</Button>
  ```

- 通过指定红色、绿色和蓝色的分量从 32 位调色板中选择一种颜色，以合并为单个纯色。 从 32 位调色板指定一种颜色的格式为“*#rrggbb*”，其中 *rr* 为两位十六进制数，用于指定红色的相对量，*gg* 指定绿色的相对量，*bb* 指定蓝色的相对量。 此外，该颜色可指定为“#*aarrggbb*”，其中，*aa* 指定该颜色的 *alpha* 值或透明度。 使用此方法能够创建部分透明的颜色。 在以下示例中，[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)的[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)设置为完全不透明红色使用十六进制表示法。

  ```xaml
  <!-- This button's background is painted with a red SolidColorBrush,
       described using hexadecimal notation. -->
  <Button Background="#FFFF0000">A Button</Button>
  ```

- 使用属性标记语法来描述[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)。 此语法更详细，并且能够指定其他设置，例如画笔的不透明度。在以下示例中，[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)的两个属性[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)元素设置为完全不透明红色。 第一个画笔的颜色使用预定义的颜色名称描述。 第二个画笔的颜色使用十六进制表示法描述。

  XAML复制

  ```xaml
  <!-- Both of these buttons' backgrounds are painted with red 
       SolidColorBrush objects, described using object element
       syntax. -->
  <Button>A Button
  
    <Button.Background>
      <SolidColorBrush Color="Red" />
    </Button.Background>
  </Button>
  
  <Button>A Button
  
    <Button.Background>
      <SolidColorBrush Color="#FFFF0000" />
    </Button.Background>
  </Button>  
  ```



##### 在代码中使用 SolidColorBrush 进行绘制

若要在代码中使用纯色绘制某个区域，请使用下列选项之一。

- 使用提供的预定义画笔之一[Brushes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brushes)类。 在以下示例中，[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)的[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)设置为[Red](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brushes.red)。

  ```csharp
  Button myButton = new Button();
  myButton.Content = "A Button";
  myButton.Background = Brushes.Red;  
  ```

- 创建[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)并设置其[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush.color)属性使用[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.color)结构。 可以使用从预定义的颜色[Colors](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.colors)类也可以创建[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.color)使用静态[FromArgb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.color.fromargb)方法。

  下面的示例演示如何设置[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush.color)属性的[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)使用预定义的颜色。

  ```csharp
  Button myButton = new Button();
  myButton.Content = "A Button";
  
  SolidColorBrush mySolidColorBrush = new SolidColorBrush();
  mySolidColorBrush.Color = Colors.Red;
  myButton.Background = mySolidColorBrush;
  ```

静态[FromArgb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.color.fromargb)可用于指定颜色的 alpha、 红色、 绿色和蓝色值。 每个值的常规范围介于 0 与 255 之间。 例如：alpha 值为 0 表示某种颜色完全透明，而值为 255 则表示该颜色完全不透明。 同样地，红色值为 0 表示某种颜色里没有红色，而值为 255 则表示某种颜色里红色最多。 在下面的示例中，画笔的颜色通过指定 alpha、红色、绿色和蓝色值描述。

```csharp
Button myButton = new Button();
myButton.Content = "A Button";

SolidColorBrush mySolidColorBrush = new SolidColorBrush();
mySolidColorBrush.Color = 
    Color.FromArgb(
        255, // Specifies the transparency of the color.
        255, // Specifies the amount of red.
        0, // specifies the amount of green.
        0); // Specifies the amount of blue.
        
myButton.Background = mySolidColorBrush;
```

有关其他方法指定颜色，请参阅[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.color)参考主题。

#### 使用渐变绘制区域

渐变画笔使用沿轴相互混合的多种颜色绘制区域。 可以使用它们创建光和影的效果，使控件具有三维外观。 还可以使用它们来模拟玻璃、镶边、水和其他光滑表面。 WPF 提供了两种类型的渐变画笔：[LinearGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush)和[RadialGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.radialgradientbrush)。

#### 线性渐变

一个[LinearGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush)沿着一条线，定义的渐变绘制区域*渐变轴*。 指定渐变颜色和它们的位置沿渐变轴使用[GradientStop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientstop)对象。 还可以修改渐变轴，从而能够创建水平和垂直渐变以及反转渐变方向。 渐变轴将在下一节中介绍。 默认情况下，将创建对角渐变。

下面的示例显示了使用四种颜色创建线性渐变的代码。

```xaml
<!-- This rectangle is painted with a diagonal linear gradient. -->
<Rectangle Width="200" Height="100">
  <Rectangle.Fill>
    <LinearGradientBrush StartPoint="0,0" EndPoint="1,1">
      <GradientStop Color="Yellow" Offset="0.0" />
      <GradientStop Color="Red" Offset="0.25" />
      <GradientStop Color="Blue" Offset="0.75" />
      <GradientStop Color="LimeGreen" Offset="1.0" />
    </LinearGradientBrush>
  </Rectangle.Fill>
</Rectangle>
```

```csharp
Rectangle diagonalFillRectangle = new Rectangle();
diagonalFillRectangle.Width = 200;
diagonalFillRectangle.Height = 100;

// Create a diagonal linear gradient with four stops.   
LinearGradientBrush myLinearGradientBrush =
    new LinearGradientBrush();
myLinearGradientBrush.StartPoint = new Point(0,0);
myLinearGradientBrush.EndPoint = new Point(1,1);
myLinearGradientBrush.GradientStops.Add(
    new GradientStop(Colors.Yellow, 0.0));
myLinearGradientBrush.GradientStops.Add(
    new GradientStop(Colors.Red, 0.25));                
myLinearGradientBrush.GradientStops.Add(
    new GradientStop(Colors.Blue, 0.75));        
myLinearGradientBrush.GradientStops.Add(
    new GradientStop(Colors.LimeGreen, 1.0));
    
// Use the brush to paint the rectangle.
diagonalFillRectangle.Fill = myLinearGradientBrush;
```

此代码生成以下渐变：

![A diagonal linear gradient](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wcpsdk-graphicsmm-diaglgradient-nolabel.jpg)

**注意：** 本主题中的渐变示例使用默认坐标系统的设置起点和终点。 默认坐标系与边界框是：0 指示边界框和 1 的 0%指示边界框的 100%。 您可以通过设置更改此坐标系[MappingMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientbrush.mappingmode)属性的值[Absolute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brushmappingmode#System_Windows_Media_BrushMappingMode_Absolute)。 绝对坐标系与范围框无关。 值直接在本地空间中解释。

[GradientStop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientstop)是渐变画笔的基本构造块。 梯度停止点指定[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientstop.color)在[Offset](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientstop.offset)沿渐变轴。

- 渐变停止点的[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientstop.color)属性指定梯度停止点的颜色。 您可以通过使用预定义的颜色设置颜色 (由[Colors](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.colors)类) 或通过指定 ScRGB 或 ARGB 值。 在 XAML 中，还可以使用十六进制表示法描述一种颜色。 有关详细信息，请参阅[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.color)结构。
- 渐变停止点的[Offset](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientstop.offset)属性指定的位置的渐变停止点的颜色渐变轴上。 偏移量是[Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double)范围从 0 到 1。 梯度停止点的偏移值越接近 0，颜色就越接近渐变的起点。 梯度停止点的偏移值越接近 1，颜色就越接近渐变的终点。

梯度停止点之间每个点的颜色按两个边界梯度停止点指定的颜色组合执行线性内插。 下图突出显示了上一示例中的梯度停止点。 圆圈标记梯度停止点的位置，虚线显示渐变轴。

![Gradient stops in a linear gradient](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wcpsdk-graphicsmm-4gradientstops.png)

第一个梯度停止点指定偏移量 `0.0` 处的颜色为黄色。 第二个梯度停止点指定偏移量 `0.25` 处的颜色为红色。 这两个点之间的点在沿渐变轴由左向右移动时，颜色渐渐由黄色变为红色。 第三个梯度停止点指定偏移量 `0.75` 处的颜色为蓝色。 第二个和第三个梯度停止点之间的点渐渐由红色变为蓝色。 第四个梯度停止点指定偏移量 `1.0`处的颜色为浅绿色。 第三个和第四个梯度停止点之间的点渐渐由蓝色变为浅绿色。



##### 渐变轴

如前文中提到，线性渐变画笔的梯度停止点位于一条线上，即渐变轴上。 您可能会更改方向和使用画笔的线的大小[StartPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush.startpoint)和[EndPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush.endpoint)属性。 通过操作画笔[StartPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush.startpoint)和[EndPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush.endpoint)，可以创建水平和垂直渐变、 反转渐变方向、 压缩渐变范围等。

默认情况下，线性渐变画笔的[StartPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush.startpoint)和[EndPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush.endpoint)相对于所绘制的区域。 点 (0,0) 表示正在绘制的区域的左上角，点 (1,1) 表示绘制区域的右下角。 默认值[StartPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush.startpoint)的[LinearGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush)为 (0，0) 和其默认[EndPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush.endpoint)(1，1)，这将创建从左上角处开始，并将扩展到当前所绘制的区域的右下角的对角线渐变。 下图显示了默认值的线性渐变画笔的渐变轴[StartPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush.startpoint)和[EndPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush.endpoint)。

![Gradient axis for a diagonal linear gradient](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wcpsdk-graphicsmm-diagonalgradientaxis.png)

下面的示例演示如何创建水平渐变通过指定画笔[StartPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush.startpoint)和[EndPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush.endpoint)。 请注意，梯度停止点是与前面的示例; 相同只需更改[StartPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush.startpoint)和[EndPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush.endpoint)，渐变已从对角线更改为水平。

```xaml
<!-- This rectangle is painted with a horizontal linear gradient. -->
<Rectangle Width="200" Height="100">
  <Rectangle.Fill>
    <LinearGradientBrush StartPoint="0,0.5" EndPoint="1,0.5">
      <GradientStop Color="Yellow" Offset="0.0" />
      <GradientStop Color="Red" Offset="0.25" />
      <GradientStop Color="Blue" Offset="0.75" />
      <GradientStop Color="LimeGreen" Offset="1.0" />
    </LinearGradientBrush>
  </Rectangle.Fill>
</Rectangle>
```

C#复制

```csharp
Rectangle horizontalFillRectangle = new Rectangle();
horizontalFillRectangle.Width = 200;
horizontalFillRectangle.Height = 100;

// Create a horizontal linear gradient with four stops.   
LinearGradientBrush myHorizontalGradient =
    new LinearGradientBrush();
myHorizontalGradient.StartPoint = new Point(0,0.5);
myHorizontalGradient.EndPoint = new Point(1,0.5);
myHorizontalGradient.GradientStops.Add(
    new GradientStop(Colors.Yellow, 0.0));
myHorizontalGradient.GradientStops.Add(
    new GradientStop(Colors.Red, 0.25));                
myHorizontalGradient.GradientStops.Add(
    new GradientStop(Colors.Blue, 0.75));        
myHorizontalGradient.GradientStops.Add(
    new GradientStop(Colors.LimeGreen, 1.0));
    
// Use the brush to paint the rectangle.
horizontalFillRectangle.Fill = myHorizontalGradient; 
```

下图显示了创建的渐变。 渐变轴用虚线标记，梯度停止点用圆圈标记。

![Gradient axis for a horizontal linear gradient](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wcpsdk-graphicsmm-horizontalgradient.jpg)

下一个示例演示如何创建垂直渐变。

XAML复制

```xaml
<!-- This rectangle is painted with a vertical gradient. -->
<Rectangle Width="200" Height="100">
  <Rectangle.Fill>
    <LinearGradientBrush StartPoint="0.5,0" EndPoint="0.5,1">
      <GradientStop Color="Yellow" Offset="0.0" />
      <GradientStop Color="Red" Offset="0.25" />
      <GradientStop Color="Blue" Offset="0.75" />
      <GradientStop Color="LimeGreen" Offset="1.0" />
    </LinearGradientBrush>
  </Rectangle.Fill>
</Rectangle>
```

C#复制

```csharp
Rectangle verticalFillRectangle = new Rectangle();
verticalFillRectangle.Width = 200;
verticalFillRectangle.Height = 100;

// Create a vertical linear gradient with four stops.   
LinearGradientBrush myVerticalGradient =
    new LinearGradientBrush();
myVerticalGradient.StartPoint = new Point(0.5,0);
myVerticalGradient.EndPoint = new Point(0.5,1);
myVerticalGradient.GradientStops.Add(
    new GradientStop(Colors.Yellow, 0.0));
myVerticalGradient.GradientStops.Add(
    new GradientStop(Colors.Red, 0.25));                
myVerticalGradient.GradientStops.Add(
    new GradientStop(Colors.Blue, 0.75));        
myVerticalGradient.GradientStops.Add(
    new GradientStop(Colors.LimeGreen, 1.0));
    
// Use the brush to paint the rectangle.
verticalFillRectangle.Fill = myVerticalGradient;  
```

下图显示了创建的渐变。 渐变轴用虚线标记，梯度停止点用圆圈标记。

![Gradient axis for a vertical gradient](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wcpsdk-graphicsmm-verticalgradient.jpg)

#### 径向渐变

像[LinearGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush)、[RadialGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.radialgradientbrush)使用沿轴混合在一起的颜色绘制区域。 前面的示例演示线性渐变画笔的轴是一条直线。 径向渐变画笔的轴由圆圈定义；它的颜色从原点开始向外“辐射”。

在下面的示例中，用径向渐变画笔绘制矩形内部。

```xaml
<!-- This rectangle is painted with a diagonal linear gradient. -->
<Rectangle Width="200" Height="100">
  <Rectangle.Fill>
    <RadialGradientBrush 
      GradientOrigin="0.5,0.5" Center="0.5,0.5" 
      RadiusX="0.5" RadiusY="0.5">
      <GradientStop Color="Yellow" Offset="0" />
      <GradientStop Color="Red" Offset="0.25" />
      <GradientStop Color="Blue" Offset="0.75" />
      <GradientStop Color="LimeGreen" Offset="1" />
    </RadialGradientBrush>
  </Rectangle.Fill>
</Rectangle>
```

```csharp
RadialGradientBrush myRadialGradientBrush = new RadialGradientBrush();
myRadialGradientBrush.GradientOrigin = new Point(0.5,0.5);
myRadialGradientBrush.Center = new Point(0.5,0.5);
myRadialGradientBrush.RadiusX = 0.5;
myRadialGradientBrush.RadiusY = 0.5;
myRadialGradientBrush.GradientStops.Add(
    new GradientStop(Colors.Yellow, 0.0));
myRadialGradientBrush.GradientStops.Add(
    new GradientStop(Colors.Red, 0.25));
myRadialGradientBrush.GradientStops.Add(
    new GradientStop(Colors.Blue, 0.75));
myRadialGradientBrush.GradientStops.Add(
    new GradientStop(Colors.LimeGreen, 1.0));

Rectangle myRectangle = new Rectangle();
myRectangle.Width = 200;
myRectangle.Height = 100;
myRectangle.Fill = myRadialGradientBrush;
```

下图显示了上一示例中创建的渐变。 画笔的梯度停止点得到突出显示。 请注意，虽然结果不同，但该示例中梯度停止点与前面几个线性渐变画笔示例中的梯度停止点相同。

![径向渐变中的梯度停止点](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wcpsdk-graphicsmm-4gradientstops-rg.png)

[GradientOrigin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.radialgradientbrush.gradientorigin)指定径向渐变画笔的渐变轴起点。 渐变轴从渐变原点向渐变圆辐射开来。 画笔的渐变圆圈由其[Center](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.radialgradientbrush.center)， [RadiusX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.radialgradientbrush.radiusx)，和[RadiusY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.radialgradientbrush.radiusy)属性。

下图显示了具有不同的多个径向渐变[GradientOrigin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.radialgradientbrush.gradientorigin)， [Center](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.radialgradientbrush.center)， [RadiusX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.radialgradientbrush.radiusx)，和[RadiusY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.radialgradientbrush.radiusy)设置。

![RadialGradientBrush 设置](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wcpsdk-graphicsmm-originscirclesandradii.gif)
具有不同 GradientOrigin、Center、RadiusX 和 RadiusY 设置的 RadialGradientBrush。

#### 指定透明或部分透明的梯度停止点

由于梯度停止点不提供 opacity 属性，因此必须指定使用的颜色的 alpha 通道ARGB标记或使用十六进制表示法[Color.FromScRgb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.color.fromscrgb)方法创建透明或部分透明的梯度停止点。 下面的几节介绍如何在 XAML 和代码中创建部分透明的梯度停止点。

##### 在“XAML”中指定颜色不透明度

在 XAML 中，使用 ARGB 十六进制表示法指定个别颜色的不透明度。 ARGB 十六进制表示法使用下面语法：

`#` **aa** *rrggbb*

上一行中的 *aa* 表示用于指定颜色不透明度的两位十六进制值。 *rr*、*gg* 和 *bb* 分别表示用于指定颜色中的红色、绿色和蓝色量的两位十六进制值。 每个十六进制数字介于 0-9 或 A-F 之间。 0 是最小值，F 是最大值。 00 的 alpha 值指定完全透明的颜色，而 FF 的 alpha 值创建完全不透明的颜色。 在下面的示例中，十六进制 ARGB 表示法用于指定两种颜色。 第一种为部分透明（alpha 值为 x20），而第二种为完全不透明。

```xaml
<Rectangle Width="100" Height="100">
  <Rectangle.Fill>
    <LinearGradientBrush StartPoint="0,0">

      <!-- This gradient stop is partially transparent. -->
      <GradientStop Color="#200000FF" Offset="0.0" />

      <!-- This gradient stop is fully opaque. -->
      <GradientStop Color="#FF0000FF" Offset="1.0" />
    </LinearGradientBrush>
  </Rectangle.Fill>
</Rectangle>
```



##### 在代码中指定颜色的不透明度

使用代码时，静态[FromArgb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.color.fromargb)方法可用于创建一种颜色时指定的 alpha 值。 该方法采用四个参数的类型[Byte](https://docs.microsoft.com/zh-cn/dotnet/api/system.byte)。 第一个参数指定颜色的 alpha 通道；其他三个参数指定颜色的红色值、绿色值和蓝色值。 每个值应介于 0 与 255 之间（含 0 和 255）。 alpha 值为 0 表示颜色完全透明，alpha 值为 255 表示颜色完全不透明。 在以下示例中，[FromArgb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.color.fromargb)方法用于生成两种颜色。 第一种颜色为部分透明（alpha 值为 32），而第二种颜色为完全不透明。

```csharp
LinearGradientBrush myLinearGradientBrush = new LinearGradientBrush();

// This gradient stop is partially transparent.
myLinearGradientBrush.GradientStops.Add(
    new GradientStop(Color.FromArgb(32, 0, 0, 255), 0.0));

// This gradient stop is fully opaque. 
myLinearGradientBrush.GradientStops.Add(
    new GradientStop(Color.FromArgb(255, 0, 0, 255), 1.0));

Rectangle myRectangle = new Rectangle();
myRectangle.Width = 100;
myRectangle.Height = 100;
myRectangle.Fill = myLinearGradientBrush;
```

或者，可能会使用[FromScRgb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.color.fromscrgb)方法，使您可以使用 ScRGB 值创建一种颜色。

#### 使用图像、绘图、Visual 和模式进行绘制

[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)，和[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)类使您可以使用图像、 绘图或视觉对象绘制区域。 有关使用图像、绘图和模式进行绘制的详细信息，请参阅[使用图像、绘图和 Visual 进行绘制](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-images-drawings-and-visuals)。

## [Painting with Images, Drawings, and Visuals](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/painting-with-images-drawings-and-visuals)

本主题介绍如何使用[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)， [DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)，并[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)对象，若要使用图像绘制区域[Drawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawing)，或[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)。

#### 系统必备

要了解本主题，应熟悉 Windows Presentation Foundation (WPF) 提供的不同画笔类型及其基本功能。 有关介绍，请参阅 [WPF 画笔概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/wpf-brushes-overview)。

#### 使用图像绘制区域

[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)使用绘制区域[ImageSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagesource)。 最常见的类型[ImageSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagesource)要用于[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)是[BitmapImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage)，它描述了位图图形。 可以使用[DrawingImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingimage)进行绘制[Drawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawing)对象，但它是使用简单得多[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)相反。 有关详细信息[ImageSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagesource)对象，请参阅[图像概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/imaging-overview)。

若要用绘图[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)，创建[BitmapImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage)并将其加载位图内容。 然后，使用[BitmapImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage)若要设置[ImageSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush.imagesource)属性的[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)。 最后，将应用[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)到想要绘制的对象。 在中可扩展应用程序标记语言 (XAML)，可以只设置[ImageSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush.imagesource)属性的[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)要加载的图像的路径。

像所有[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)对象，[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)可用于绘制形状、 面板、 控件和文本框之类的对象。 下图显示了可以使用实现某些效果[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)。

![ImageBrush 输出示例](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wcpsdk-mmgraphics-imagebrushexamples.gif)
使用 ImageBrush 绘制的对象

默认情况下，[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)拉伸其图像以完全填充的区域正在绘制，很可能会扭曲图像绘制的区域是否与映像不同的纵横比。 可以通过更改来更改此行为[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.stretch)属性从其默认值[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_Fill)到[None](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_None)， [Uniform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_Uniform)，或[UniformToFill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_UniformToFill)。 因为[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)是一种[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)，可以指定正好如何了图像画笔填充输出区域，甚至创建图案。 有关高级详细信息[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)功能，请参阅[TileBrush 概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/tilebrush-overview)。



#### 示例:使用位图图像绘制对象

下面的示例使用[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)绘制[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.background)的[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)。

```xaml
<Page
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  x:Class="Microsoft.Samples.BrushExamples.ImageBrushExample"
  WindowTitle="ImageBrush Example"
  Background="White">

  <StackPanel>

    <Canvas
      Height="200" Width="300">
      <Canvas.Background>
        <ImageBrush ImageSource="sampleImages\Waterlilies.jpg" />
      </Canvas.Background>
    </Canvas>

    
  </StackPanel>
</Page
```

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace Microsoft.Samples.BrushExamples
{

    public class ImageBrushExample : Page
    {
    
        public ImageBrushExample()
        {
        
            StackPanel mainPanel = new StackPanel();
            canvasBackgroundExample(mainPanel);
            this.Content = mainPanel;
        
        }
                 

        private void canvasBackgroundExample(Panel mainPanel)
        {
            
            BitmapImage theImage = new BitmapImage
                (new Uri("sampleImages\\Waterlilies.jpg", UriKind.Relative));
            
            ImageBrush myImageBrush = new ImageBrush(theImage);
            
            Canvas myCanvas = new Canvas();
            myCanvas.Width = 300;
            myCanvas.Height = 200;
            myCanvas.Background = myImageBrush;
            
            mainPanel.Children.Add(myCanvas);
    
    
        }
    
    }

}
```



#### 使用图形绘制区域

一个[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)使您能够使用形状、 文本、 图像和视频绘制区域。 图形画笔内部的形状可能会自行绘制使用纯色、 渐变、 图像，或甚至另一个[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)。 下图演示的一些用途[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)。

![DrawingBrush 输出示例](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wcpsdk-mmgraphics-drawingbrushexamples.png)
使用 DrawingBrush 绘制的对象

一个[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)使用绘制区域[Drawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawing)对象。 一个[Drawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawing)对象描述可见内容，如形状、 位图、 视频或文本行。 不同类型的图形描述不同类型的内容。 下面是不同类型图形对象的列表。

- [GeometryDrawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometrydrawing) – 绘制形状。
- [ImageDrawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagedrawing) – 绘制图像。
- [GlyphRunDrawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.glyphrundrawing) – 绘制文本。
- [VideoDrawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.videodrawing) – 播放音频或视频文件。
- [DrawingGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawinggroup) – 绘制其他绘图。 使用图形组将其他图形合并到单个复合图形。

有关详细信息[Drawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawing)对象，请参阅[Drawing 对象概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/drawing-objects-overview)。

像[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)、 一个[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)拉伸其[Drawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush.drawing)以填充输出区域。 可以通过更改重写此行为[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.stretch)属性从其默认设置为[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_Fill)。 有关更多信息，请参见 [Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.stretch) 属性。

#### 示例:使用 Drawing 绘制对象

下面的示例显示如何使用三个椭圆形的图形绘制对象。 一个[GeometryDrawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometrydrawing)用于描述椭圆形。

```xaml
<Button Content="A Button">
  <Button.Background>
    <DrawingBrush>
      <DrawingBrush.Drawing>
        <GeometryDrawing Brush="LightBlue">
          <GeometryDrawing.Geometry>
            <GeometryGroup>
              <EllipseGeometry RadiusX="12.5" RadiusY="25" Center="25,50" />
              <EllipseGeometry RadiusX="12.5" RadiusY="25" Center="50,50" />
              <EllipseGeometry RadiusX="12.5" RadiusY="25" Center="75,50" />
            </GeometryGroup>
          </GeometryDrawing.Geometry>
          <GeometryDrawing.Pen>
            <Pen Thickness="1" Brush="Gray" />
          </GeometryDrawing.Pen>
        </GeometryDrawing>
      </DrawingBrush.Drawing>
    </DrawingBrush>
  </Button.Background>
</Button>
```

```csharp
// Create a DrawingBrush.
DrawingBrush myDrawingBrush = new DrawingBrush();

// Create a drawing.
GeometryDrawing myGeometryDrawing = new GeometryDrawing();
myGeometryDrawing.Brush = Brushes.LightBlue;
myGeometryDrawing.Pen = new Pen(Brushes.Gray, 1);
GeometryGroup ellipses = new GeometryGroup();
ellipses.Children.Add(new EllipseGeometry(new Point(25,50), 12.5, 25));
ellipses.Children.Add(new EllipseGeometry(new Point(50,50), 12.5, 25));
ellipses.Children.Add(new EllipseGeometry(new Point(75,50), 12.5, 25));

myGeometryDrawing.Geometry = ellipses;
myDrawingBrush.Drawing = myGeometryDrawing;

Button myButton = new Button();
myButton.Content = "A Button";

// Use the DrawingBrush to paint the button's background.
myButton.Background = myDrawingBrush;
```

#### 使用视觉对象绘制区域

最灵活、 最强大的所有画笔[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)使用绘制区域[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)。 一个[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)是用作许多有用图形组件的上级的低级别图形类型。 例如， [Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)， [FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)，并[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)类是所有类型的[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)对象。 使用[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)，可以绘制区域使用几乎所有Windows Presentation Foundation (WPF)图形对象。

> 尽管[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)是一种[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)对象，它不能冻结 （使其只读的） 时其[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush.visual)属性设置为值`null`。

有两种方法来指定[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush.visual)内容的[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)。

- 创建一个新[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)并使用它来设置[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush.visual)属性的[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)。 有关示例，请参阅[示例：使用视觉对象绘制对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-images-drawings-and-visuals#examplevisualbrush1)下一节。
- 使用现有[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)，这将创建目标的重复图像[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)。 然后，可以使用[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)创建有趣的效果，例如反射和放大效果。 有关示例，请参阅[示例：创建反射](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-images-drawings-and-visuals#examplevisualbrush2)部分。

定义一个新[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush.visual)有关[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)并且[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)是[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)布局系统 （如面板或控件） 上运行[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)及其子元素时[AutoLayoutContent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush.autolayoutcontent)属性设置为`true`。 但是，根[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)实质上独立于系统的其余部分： 样式和外部布局不能渗透此边界。 因此，应显式指定根的大小[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)，因为其唯一父级是[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)，因此它不能自动调整自身大小到当前所绘制的区域。 有关 Windows Presentation Foundation (WPF) 中的布局的更多信息，请参阅[布局](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/layout)。

像[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)并[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)、[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)拉伸其内容以填充输出区域。 可以通过更改重写此行为[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.stretch)属性从其默认设置为[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_Fill)。 有关更多信息，请参见 [Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.stretch) 属性。

#### 示例:使用视觉对象绘制对象

在下面的示例中，许多控件和面板用于绘制矩形。

```xaml
<Rectangle Width="150" Height="150" Stroke="Black" Margin="5,0,5,0">
  <Rectangle.Fill>
    <VisualBrush>
      <VisualBrush.Visual>
        <StackPanel Background="White">
          <Rectangle Width="25" Height="25" Fill="Red" Margin="2" />
          <TextBlock FontSize="10pt" Margin="2">Hello, World!</TextBlock>
          <Button Margin="2">A Button</Button>
        </StackPanel>
      </VisualBrush.Visual>
    </VisualBrush>
  </Rectangle.Fill>
</Rectangle>
```

```csharp
VisualBrush myVisualBrush = new VisualBrush();

// Create the visual brush's contents.
StackPanel myStackPanel = new StackPanel();
myStackPanel.Background = Brushes.White;

Rectangle redRectangle = new Rectangle();
redRectangle.Width = 25;
redRectangle.Height =25; 
redRectangle.Fill = Brushes.Red;
redRectangle.Margin = new Thickness(2);
myStackPanel.Children.Add(redRectangle);

TextBlock someText = new TextBlock();
FontSizeConverter myFontSizeConverter = new FontSizeConverter();
someText.FontSize = (double)myFontSizeConverter.ConvertFrom("10pt");
someText.Text = "Hello, World!";
someText.Margin = new Thickness(2);
myStackPanel.Children.Add(someText);

Button aButton = new Button();
aButton.Content = "A Button";
aButton.Margin = new Thickness(2);
myStackPanel.Children.Add(aButton);

// Use myStackPanel as myVisualBrush's content.
myVisualBrush.Visual = myStackPanel;

// Create a rectangle to paint.
Rectangle myRectangle = new Rectangle();
myRectangle.Width = 150;
myRectangle.Height = 150;
myRectangle.Stroke = Brushes.Black;
myRectangle.Margin = new Thickness(5,0,5,0);

// Use myVisualBrush to paint myRectangle.
myRectangle.Fill = myVisualBrush;
```

#### 示例:创建反射

前面的示例介绍了如何创建一个新[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)用作背景。 此外可以使用[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)显示现有视觉对象; 此功能使您能够生成有趣的视觉效果，例如反射和放大。 下面的示例使用[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)若要创建的反射[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)包含多个元素。 下图显示了此示例生成的输出。

![一个反映视觉对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-visualbrush-reflection-small.jpg)
反射的 Visual 对象

```csharp
using System;
using System.Windows;
using System.Windows.Data;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Effects;
using System.Windows.Media.Imaging;
using System.IO;
using System.Collections.ObjectModel;
using System.Windows.Shapes;
namespace SDKSample
{
    public partial class ReflectionExample : Page
    {
        public ReflectionExample()
        {
            // Create a name scope for the page.
            NameScope.SetNameScope(this, new NameScope());

            this.Background = Brushes.Black;
            StackPanel myStackPanel = new StackPanel();
            myStackPanel.Margin = new Thickness(50);

            Border myReflectedBorder = new Border();
            this.RegisterName("ReflectedVisual", myReflectedBorder);

            // Create a gradient background for the border.
            GradientStop firstStop = new GradientStop();
            firstStop.Offset = 0.0;
            Color firstStopColor = new Color();
            firstStopColor.R = 204;
            firstStopColor.G = 204;
            firstStopColor.B = 255;
            firstStopColor.A = 255;
            firstStop.Color = firstStopColor;
            GradientStop secondStop = new GradientStop();
            secondStop.Offset = 1.0;
            secondStop.Color = Colors.White;

            GradientStopCollection myGradientStopCollection = new GradientStopCollection();
            myGradientStopCollection.Add(firstStop);
            myGradientStopCollection.Add(secondStop);

            LinearGradientBrush myLinearGradientBrush = new LinearGradientBrush();
            myLinearGradientBrush.StartPoint = new Point(0, 0.5);
            myLinearGradientBrush.EndPoint = new Point(1, 0.5);
            myLinearGradientBrush.GradientStops = myGradientStopCollection;

            myReflectedBorder.Background = myLinearGradientBrush;

            // Add contents to the border.
            StackPanel borderStackPanel = new StackPanel();
            borderStackPanel.Orientation = Orientation.Horizontal;
            borderStackPanel.Margin = new Thickness(10);

            TextBlock myTextBlock = new TextBlock();
            myTextBlock.TextWrapping = TextWrapping.Wrap;
            myTextBlock.Width = 200;
            myTextBlock.Text = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit." +
                               " Suspendisse vel ante. Donec luctus tortor sit amet est." +
                               " Nullam pulvinar odio et wisi." +
                               " Pellentesque quis magna. Sed pellentesque." +
                               " Nulla euismod." +
                               "Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas.";

            borderStackPanel.Children.Add(myTextBlock);

            StackPanel ellipseStackPanel = new StackPanel();

            Ellipse ellipse1 = new Ellipse();
            ellipse1.Margin = new Thickness(10);
            ellipse1.Height = 50;
            ellipse1.Width = 50;
            ellipse1.Fill = Brushes.Black;
            ellipseStackPanel.Children.Add(ellipse1);
            Ellipse ellipse2 = new Ellipse();
            ellipse2.Margin = new Thickness(10);
            ellipse2.Height = 50;
            ellipse2.Width = 50;
            ellipse2.Fill = Brushes.Black;
            ellipseStackPanel.Children.Add(ellipse2);
            Ellipse ellipse3 = new Ellipse();
            ellipse3.Margin = new Thickness(10);
            ellipse3.Height = 50;
            ellipse3.Width = 50;
            ellipse3.Fill = Brushes.Black;
            ellipseStackPanel.Children.Add(ellipse3);
            borderStackPanel.Children.Add(ellipseStackPanel);

            myReflectedBorder.Child = borderStackPanel;

            // Create divider rectangle
            Rectangle dividerRectangle = new Rectangle();
            dividerRectangle.Height = 1;
            dividerRectangle.Fill = Brushes.Gray;
            dividerRectangle.HorizontalAlignment = HorizontalAlignment.Stretch;

            // Create the object to contain the reflection.
            Rectangle reflectionRectangle = new Rectangle();

            // Bind the height of the rectangle to the border height.
            Binding heightBinding = new Binding();
            heightBinding.ElementName = "ReflectedVisual";
            heightBinding.Path = new PropertyPath(Rectangle.HeightProperty);
            BindingOperations.SetBinding(reflectionRectangle, Rectangle.HeightProperty, heightBinding);

            // Bind the width of the rectangle to the border width.
            Binding widthBinding = new Binding();
            widthBinding.ElementName = "ReflectedVisual";
            widthBinding.Path = new PropertyPath(Rectangle.WidthProperty);
            BindingOperations.SetBinding(reflectionRectangle, Rectangle.WidthProperty, widthBinding);

            // Creates the reflection.
            VisualBrush myVisualBrush = new VisualBrush();
            myVisualBrush.Opacity = 0.75;
            myVisualBrush.Stretch = Stretch.None;
            Binding reflectionBinding = new Binding();
            reflectionBinding.ElementName = "ReflectedVisual";
            BindingOperations.SetBinding(myVisualBrush, VisualBrush.VisualProperty, reflectionBinding);

            ScaleTransform myScaleTransform = new ScaleTransform();
            myScaleTransform.ScaleX = 1;
            myScaleTransform.ScaleY = -1;
            TranslateTransform myTranslateTransform = new TranslateTransform();
            myTranslateTransform.Y = 1;

            TransformGroup myTransformGroup = new TransformGroup();
            myTransformGroup.Children.Add(myScaleTransform);
            myTransformGroup.Children.Add(myTranslateTransform);

            myVisualBrush.RelativeTransform = myTransformGroup;

            reflectionRectangle.Fill = myVisualBrush;

            // Create a gradient background for the border.
            GradientStop firstStop2 = new GradientStop();
            firstStop2.Offset = 0.0;
            Color c1 = new Color();
            c1.R = 0;
            c1.G = 0;
            c1.B = 0;
            c1.A = 255;
            firstStop2.Color = c1;
            GradientStop secondStop2 = new GradientStop();
            secondStop2.Offset = 0.5;
            Color c2 = new Color();
            c2.R = 0;
            c2.G = 0;
            c2.B = 0;
            c2.A = 51;
            firstStop2.Color = c2;
            GradientStop thirdStop = new GradientStop();
            thirdStop.Offset = 0.75;
            Color c3 = new Color();
            c3.R = 0;
            c3.G = 0;
            c3.B = 0;
            c3.A = 0;
            thirdStop.Color = c3;

            GradientStopCollection myGradientStopCollection2 = new GradientStopCollection();
            myGradientStopCollection2.Add(firstStop2);
            myGradientStopCollection2.Add(secondStop2);
            myGradientStopCollection2.Add(thirdStop);

            LinearGradientBrush myLinearGradientBrush2 = new LinearGradientBrush();
            myLinearGradientBrush2.StartPoint = new Point(0.5, 0);
            myLinearGradientBrush2.EndPoint = new Point(0.5, 1);
            myLinearGradientBrush2.GradientStops = myGradientStopCollection2;

            reflectionRectangle.OpacityMask = myLinearGradientBrush2;

            BlurBitmapEffect myBlurBitmapEffect = new BlurBitmapEffect();
            myBlurBitmapEffect.Radius = 1.5;

            reflectionRectangle.BitmapEffect = myBlurBitmapEffect;

            myStackPanel.Children.Add(myReflectedBorder);
            myStackPanel.Children.Add(dividerRectangle);
            myStackPanel.Children.Add(reflectionRectangle);
            this.Content = myStackPanel;

        }
        /*
    <Rectangle 
      Height="{Binding Path=ActualHeight, ElementName=ReflectedVisual}" 
      Width="{Binding Path=ActualWidth, ElementName=ReflectedVisual}">

      <Rectangle.OpacityMask>
        <LinearGradientBrush StartPoint="0.5,0" EndPoint="0.5,1">
          <GradientStop Color="#FF000000" Offset="0.0" />
          <GradientStop Color="#33000000" Offset="0.5" />
          <GradientStop Color="#00000000" Offset="0.75" />
        </LinearGradientBrush>
      </Rectangle.OpacityMask>

      <Rectangle.BitmapEffect>
        <BlurBitmapEffect Radius="1.5" />
      </Rectangle.BitmapEffect>
      
    </Rectangle>
  </StackPanel>
</Page>

*/
        
    }
}
```

```xaml
<Page  
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml" 
  Background="Black">


  <StackPanel Margin="50">

    <!-- The object to reflect. -->
    <Border Name="ReflectedVisual" Width="400">
      <Border.Background>
        <LinearGradientBrush StartPoint="0,0.5" EndPoint="1,0.5">
          <GradientStop Offset="0.0" Color="#CCCCFF" />
          <GradientStop Offset="1.0" Color="White" />
        </LinearGradientBrush>
      </Border.Background>
      <StackPanel Orientation="Horizontal" Margin="10">        
        <TextBlock TextWrapping="Wrap" Width="200" Margin="10">
          Lorem ipsum dolor sit amet, consectetuer adipiscing elit.
          Suspendisse vel ante. Donec luctus tortor sit amet est.
          Nullam pulvinar odio et wisi.
          Pellentesque quis magna. Sed pellentesque.
          Nulla euismod.
          Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas.
        </TextBlock>
        <StackPanel>
          <Ellipse Margin="10" Height="50" Width="50" Fill="Black" />
          <Ellipse Margin="10" Height="50" Width="50" Fill="Black" />
          <Ellipse Margin="10" Height="50" Width="50" Fill="Black" />
        </StackPanel>
      </StackPanel>
    </Border>

    <Rectangle Height="1" Fill="Gray" HorizontalAlignment="Stretch" />

    <!-- The object to contain the reflection.-->
    <Rectangle 
      Height="{Binding Path=ActualHeight, ElementName=ReflectedVisual}" 
      Width="{Binding Path=ActualWidth, ElementName=ReflectedVisual}">
      <Rectangle.Fill>

        <!-- Creates the reflection. -->
        <VisualBrush 
          Opacity="0.75" Stretch="None"
          Visual="{Binding ElementName=ReflectedVisual}">
          <VisualBrush.RelativeTransform>

            <!-- Flip the reflection. -->
            <TransformGroup>
              <ScaleTransform ScaleX="1" ScaleY="-1" />
              <TranslateTransform  Y="1" />
            </TransformGroup>
          </VisualBrush.RelativeTransform>
        </VisualBrush>
      </Rectangle.Fill>

      <Rectangle.OpacityMask>
        <LinearGradientBrush StartPoint="0.5,0" EndPoint="0.5,1">
          <GradientStop Color="#FF000000" Offset="0.0" />
          <GradientStop Color="#33000000" Offset="0.5" />
          <GradientStop Color="#00000000" Offset="0.75" />
        </LinearGradientBrush>
      </Rectangle.OpacityMask>

      <Rectangle.BitmapEffect>
        <BlurBitmapEffect Radius="1.5" />
      </Rectangle.BitmapEffect>
      
    </Rectangle>
  </StackPanel>
</Page>
```

有关显示如何放大屏幕部分以及如何创建反射的更多示例，请参阅 [VisualBrush 示例](https://go.microsoft.com/fwlink/?LinkID=160049)。

#### TileBrush 功能

[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)，并[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)类型的[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)对象。 [TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush) 对象提供了大量的控制如何使用图像、 绘图或 visual 绘制区域。 例如，不使用单个拉伸图像绘制区域，而是使用创建图案的一系列平铺图像绘制区域。

一个[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)有三个主要组件： 内容、 磁贴和输出区域。

![TileBrush 组件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wcpsdk-mmgraphics-defaultcontentprojection2.png)
具有单个图块的 TileBrush 的组成部分

![平铺的 TileBrush 的组成部分](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-tiledprojection.png)
使用多个平铺的 TileBrush 组件

有关平铺功能的详细信息[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)对象，请参阅[TileBrush 概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/tilebrush-overview)。

## [TileBrush Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/tilebrush-overview)

[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush) 对象提供对如何使用图像、 绘制区域的控制自如地[Drawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawing)，或[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)。 本主题介绍如何使用[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)功能来获得更好地控制如何[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)， [DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)，或[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)绘制区域。

#### 系统必备

要了解本主题，很有帮助，了解如何使用的基本功能[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)， [DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)，或[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)类。 有关这些类型的简介，请参阅[使用图像、 绘图和视觉对象进行绘制](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-images-drawings-and-visuals)。

#### 使用图块绘制区域

[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)，将[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)类型的[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)对象。 使用平铺画笔，可以非常自如地控制如何使用图像、绘图或视觉对象来绘制区域。 例如，在绘制一个区域时，可以使用一系列的图像图块创建图案，而不是仅使用拉伸的图像。

使用平铺画笔绘制区域涉及三个组成部分：内容、基本图块和输出区域。

![TileBrush 组件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wcpsdk-mmgraphics-defaultcontentprojection2.png)
具有单个图块的 TileBrush 的组成部分

![平铺的 TileBrush 的组成部分](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-tiledprojection.png)
已指定图块的 TileMode 的 TileBrush 的组成部分

输出区域是绘制区域，如[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)的[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)或[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)的[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。 接下来的部分描述的其他两个组件[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)。

#### 画笔内容

有三种不同类型的[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)和每个不同类型的内容与绘制。

- 如果画笔为[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)，此内容是一个图像[ImageSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush.imagesource)属性指定的内容[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)。
- 如果画笔为[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)，此内容为绘图。 [Drawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush.drawing)属性指定的内容[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)。
- 如果画笔为[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)，此内容为视觉对象。 [Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush.visual)属性指定的内容[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)。

可以指定的位置和尺寸[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)通过使用内容[Viewbox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewbox)属性，尽管通常会保留[Viewbox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewbox)设置为其默认值。 默认情况下，[Viewbox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewbox)配置为完全包含画笔的内容。 有关配置详细信息[Viewbox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewbox)，请参阅[Viewbox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewbox)属性页。

#### 基本图块

一个[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)其内容投射到基本图块。 [Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.stretch)属性控制如何[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)拉伸内容以填充基本图块。 [Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.stretch)属性接受以下值，通过定义[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch)枚举：

- [None](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_None)：画笔的内容未拉伸以填充磁贴。
- [Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_Fill)：画笔的内容进行缩放以适合图块。 由于内容的高度和宽度独立进行缩放，因此内容的原始纵横比可能不会保留。 也就是说，为了完全填充输出图块，画笔的内容可能会弯曲。
- [Uniform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_Uniform)：缩放画笔的内容，使其完全符合该磁贴。 内容的纵横比会保留。
- [UniformToFill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_UniformToFill)：缩放画笔的内容，使其在保留内容的原始纵横比的同时完全填充输出区域。

下图阐释了不同[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.stretch)设置。

![Different TileBrush Stretch settings](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/img-mmgraphics-stretchenum.jpg)

在下面的示例的内容[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)设置，以便它不会拉伸以填充输出区域。

```xaml
<Rectangle
  Width="125" Height="175"
  Stroke="Black"
  StrokeThickness="1"
  Margin="0,0,5,0">
  <Rectangle.Fill>
    <ImageBrush 
      Stretch="None"
      ImageSource="sampleImages\testImage.gif"/>
  </Rectangle.Fill>
</Rectangle>
```

```csharp
          // Create a rectangle.
          Rectangle myRectangle = new Rectangle();
          myRectangle.Width = 125;
          myRectangle.Height = 175;
          myRectangle.Stroke = Brushes.Black;
          myRectangle.StrokeThickness = 1;
          myRectangle.Margin = new Thickness(0,5,0,0);

          // Load the image.
          BitmapImage theImage = 
              new BitmapImage(
                  new Uri("sampleImages\\testImage.gif", UriKind.Relative));   
          ImageBrush myImageBrush = new ImageBrush(theImage);
          
          // Configure the brush so that it
          // doesn't stretch its image to fill
          // the rectangle.
          myImageBrush.Stretch = Stretch.None;

          // Use the ImageBrush to paint the rectangle's background.
          myRectangle.Fill = myImageBrush;
```

默认情况下，[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)生成单个图块 （基本图块） 并拉伸该图块以完全填充输出区域。 可以通过设置更改的大小和位置的基本图块[Viewport](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewport)和[ViewportUnits](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewportunits)属性。

##### 基本图块大小

[Viewport](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewport)属性确定的大小和位置的基本图块，并[ViewportUnits](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewportunits)属性确定是否[Viewport](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewport)使用绝对或相对坐标指定。如果坐标是相对坐标，则它们相对于输出区域的大小。 点 (0,0) 表示输出区域的左上角，(1,1) 表示输出区域的右下角。 若要指定的[Viewport](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewport)属性使用绝对坐标，设置[ViewportUnits](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewportunits)属性设置为[Absolute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brushmappingmode#System_Windows_Media_BrushMappingMode_Absolute)。

下图显示了输出之间的区别[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)使用相对和绝对[ViewportUnits](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewportunits)。 请注意每个图都显示了一种图块图案；下一节介绍如何指定图块图案。

![Absolute and Relative Viewport Units](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/absolute-and-relative-viewports.png)

在下面的示例中，使用一幅图像来创建一个宽度和高度均为 50% 的图块。 基本图块位于输出区域的 (0,0) 处。

XAML复制

```xaml
<Rectangle
 Width="50" Height="100">
  <Rectangle.Fill>

    <!-- Paints an area with 4 tiles. -->
    <ImageBrush ImageSource="sampleImages\cherries_larger.jpg"
      Viewport="0,0,0.5,0.5"
      ViewportUnits="RelativeToBoundingBox" 
      TileMode="Tile" />
  </Rectangle.Fill>
</Rectangle>
```

C#复制

```csharp
          // Create a rectangle.
          Rectangle myRectangle = new Rectangle();
          myRectangle.Width = 50;
          myRectangle.Height = 100;
          
          // Load the image.
          BitmapImage theImage = 
              new BitmapImage(
                  new Uri("sampleImages\\cherries_larger.jpg", UriKind.Relative));   
          ImageBrush myImageBrush = new ImageBrush(theImage);
          
          // Create tiles that are 1/4 the size of 
          // the output area.
          myImageBrush.Viewport = new Rect(0,0,0.25,0.25);
          myImageBrush.ViewportUnits = BrushMappingMode.RelativeToBoundingBox;
          
          // Set the tile mode to Tile.
          myImageBrush.TileMode = TileMode.Tile;

          // Use the ImageBrush to paint the rectangle's background.
          myRectangle.Fill = myImageBrush;
```

下一个示例设置的磁贴[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)到 25 x 25 设备独立像素。 因为[ViewportUnits](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewportunits)是绝对的[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)图块始终是 25 x 25 像素，而不考虑所绘制的区域的大小。

XAML复制

```xaml
<Rectangle
 Width="50" Height="100">
  <Rectangle.Fill>

    <!-- Paints an area with 25 x 25 tiles. -->
    <ImageBrush ImageSource="sampleImages\cherries_larger.jpg"
      Viewport="0,0,25,25"
      ViewportUnits="Absolute" 
      TileMode="Tile" />
  </Rectangle.Fill>
</Rectangle>
```

C#复制

```csharp
// Create a rectangle.
Rectangle myRectangle = new Rectangle();
myRectangle.Width = 50;
myRectangle.Height = 100;

// Load the image.       
BitmapImage theImage =
    new BitmapImage(
        new Uri("sampleImages\\cherries_larger.jpg", UriKind.Relative));
ImageBrush myImageBrush = new ImageBrush(theImage);

// Create tiles that are 25 x 25, regardless of the size
// of the output area.
myImageBrush.Viewport = new Rect(0, 0, 25, 25);
myImageBrush.ViewportUnits = BrushMappingMode.Absolute;

// Set the tile mode to Tile.
myImageBrush.TileMode = TileMode.Tile;

// Use the ImageBrush to paint the rectangle's background.
myRectangle.Fill = myImageBrush;
```



##### 平铺行为

一个[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)其基本图块未完全填充输出区域和其他然后平铺模式时生成的平铺的模式[None](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilemode#System_Windows_Media_TileMode_None)指定。 当平铺画笔的图块未完全填充输出区域，其[TileMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.tilemode)属性指定是否应复制基本图块，以填充输出区域，指定如果是这样，都应复制基本图块的方式。 [TileMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.tilemode)属性接受以下值，通过定义[TileMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilemode)枚举：

- [None](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilemode#System_Windows_Media_TileMode_None)：仅在基本图块绘制。
- [Tile](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilemode#System_Windows_Media_TileMode_Tile)：绘制基本图块，并通过重复基本磁贴，这样，一个磁贴的右边缘旁边的左边缘的下一步，并同样边缘和上填充剩余的区域。
- [FlipX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilemode#System_Windows_Media_TileMode_FlipX)：与相同[Tile](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilemode#System_Windows_Media_TileMode_Tile)，只不过磁贴的交替列水平翻转。
- [FlipY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilemode#System_Windows_Media_TileMode_FlipY)：与相同[Tile](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilemode#System_Windows_Media_TileMode_Tile)，只不过磁贴的交替行垂直翻转。
- [FlipXY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilemode#System_Windows_Media_TileMode_FlipXY)：[FlipX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilemode#System_Windows_Media_TileMode_FlipX) 和 [FlipY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilemode#System_Windows_Media_TileMode_FlipY) 的组合。

下图阐释了不同的平铺模式。

![Different TileBrush TileMode settings](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/img-mmgraphics-tilemodes.gif)

在下面的示例中，使用一个图像来绘制宽度为 100 像素并且高度为 100 像素的矩形。 通过设置画笔的[Viewport](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewport)已设置到 0,0,0.25,0.25，画笔的基本图块由为 1/4 占输出区域。 画笔[TileMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.tilemode)设置为[FlipXY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilemode#System_Windows_Media_TileMode_FlipXY)。 这样它便可以用图块行来填充矩形。

XAML复制

```xaml
<Rectangle
 Width="100" Height="100" >
  <Rectangle.Fill>
    <ImageBrush ImageSource="sampleImages\triangle.jpg"
      Viewport="0,0,0.25,0.25" 
      TileMode="FlipXY"
      />
  </Rectangle.Fill>    
</Rectangle>
```

C#复制

```csharp
          // Create a rectangle.
          Rectangle myRectangle = new Rectangle();
          myRectangle.Width = 100;
          myRectangle.Height = 100;
          
          // Load the image.
          BitmapImage theImage = 
              new BitmapImage(
                  new Uri("sampleImages\\triangle.jpg", UriKind.Relative));   
          ImageBrush myImageBrush = new ImageBrush(theImage);
          
          // Create tiles that are 1/4 the size of 
          // the output area.
          myImageBrush.Viewport = new Rect(0,0,0.25,0.25);
          
          // Set the tile mode to FlipXY.
          myImageBrush.TileMode = TileMode.FlipXY;

          // Use the ImageBrush to paint the rectangle's background.
          myRectangle.Fill = myImageBrush;
```

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/brushes-how-to-topics)

以下主题演示如何使用Windows Presentation Foundation (WPF)才能绘制到屏幕的内容的画笔。

#### 本节内容

[为 SolidColorBrush 的颜色或不透明度设置动画效果](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-animate-the-color-or-opacity-of-a-solidcolorbrush)
[为梯度停止点的位置或颜色设置动画效果](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-animate-the-position-or-color-of-a-gradient-stop)
[创建反射](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-reflection)
[使用 TileBrush 创建不同的平铺图案](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-create-different-tile-patterns-with-a-tilebrush)
[定义笔](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-define-a-pen)
[在区域内画上绘图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-paint-an-area-with-a-drawing)
[在区域内画上图像](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-paint-an-area-with-an-image)
[在区域内画上线性渐变](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-paint-an-area-with-a-linear-gradient)
[在区域内画上径向渐变](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-paint-an-area-with-a-radial-gradient)
[在区域内画上纯色](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-paint-an-area-with-a-solid-color)
[使用系统画笔绘制区域](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-paint-an-area-with-a-system-brush)
[在区域内画上视频](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-paint-an-area-with-a-video)
[在区域内画上视觉对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-paint-an-area-with-a-visual)
[保持背景图像的纵横比](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-preserve-the-aspect-ratio-of-an-image-used-as-a-background)
[设置 TileBrush 的水平和垂直对齐方式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-set-the-horizontal-and-vertical-alignment-of-a-tilebrush)
[设置 TileBrush 的平铺大小](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-set-the-tile-size-for-a-tilebrush)
[转换画笔](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-transform-a-brush)
[在渐变中使用系统颜色](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-use-system-colors-in-a-gradient)

#### [Animate the Color or Opacity of a SolidColorBrush](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-animate-the-color-or-opacity-of-a-solidcolorbrush)

此示例演示如何进行动画处理[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush.color)并[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.opacity)的[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)。

##### 示例

下面的示例使用三个动画进行动画处理[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush.color)并[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.opacity)的[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)。

- 第一个动画[ColorAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.coloranimation)，会将画笔的颜色改[Gray](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.colors.gray)当鼠标进入矩形。
- 下一步的动画，另一个[ColorAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.coloranimation)，会将画笔的颜色改[Orange](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.colors.orange)当鼠标离开矩形。
- 最后一个动画， [DoubleAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation)，当按下鼠标左键时更改画笔的不透明度为 0.0。

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Shapes;
using System.Windows.Input;

namespace Microsoft.Samples.Animation
{
    /// <summary>
    /// This example shows how to animate the Opacity and Color 
    /// properties of a SolidColorBrush.
    /// </summary>
    public class SolidColorBrushExample : Page
    {

        public SolidColorBrushExample()
        {
            Title = "SolidColorBrush Animation Example";
            Background = Brushes.White;

            // Create a NameScope for the page so
            // that Storyboards can be used.
            NameScope.SetNameScope(this, new NameScope());

            // Create a Rectangle.
            Rectangle aRectangle = new Rectangle();
            aRectangle.Width = 100;
            aRectangle.Height = 100;

            // Create a SolidColorBrush to paint
            // the rectangle's fill. The Opacity
            // and Color properties of the brush
            // will be animated.
            SolidColorBrush myAnimatedBrush = new SolidColorBrush();
            myAnimatedBrush.Color = Colors.Orange;
            aRectangle.Fill = myAnimatedBrush;

            // Register the brush's name with the page
            // so that it can be targeted by storyboards.
            this.RegisterName("MyAnimatedBrush", myAnimatedBrush);

            //
            // Animate the brush's color to gray when
            // the mouse enters the rectangle.
            //
            ColorAnimation mouseEnterColorAnimation = new ColorAnimation();
            mouseEnterColorAnimation.To = Colors.Gray;
            mouseEnterColorAnimation.Duration = TimeSpan.FromSeconds(1);
            Storyboard.SetTargetName(mouseEnterColorAnimation, "MyAnimatedBrush");
            Storyboard.SetTargetProperty(
                mouseEnterColorAnimation, new PropertyPath(SolidColorBrush.ColorProperty));
            Storyboard mouseEnterStoryboard = new Storyboard();
            mouseEnterStoryboard.Children.Add(mouseEnterColorAnimation);
            aRectangle.MouseEnter += delegate(object sender, MouseEventArgs e)
            {
                mouseEnterStoryboard.Begin(this);
            };

            //
            // Animate the brush's color to orange when
            // the mouse leaves the rectangle.
            //
            ColorAnimation mouseLeaveColorAnimation = new ColorAnimation();
            mouseLeaveColorAnimation.To = Colors.Orange;
            mouseLeaveColorAnimation.Duration = TimeSpan.FromSeconds(1);
            Storyboard.SetTargetName(mouseLeaveColorAnimation, "MyAnimatedBrush");
            Storyboard.SetTargetProperty(
                mouseLeaveColorAnimation, new PropertyPath(SolidColorBrush.ColorProperty));
            Storyboard mouseLeaveStoryboard = new Storyboard();
            mouseLeaveStoryboard.Children.Add(mouseLeaveColorAnimation);
            aRectangle.MouseLeave += delegate(object sender, MouseEventArgs e)
            {
                mouseLeaveStoryboard.Begin(this);
            };

            //
            // Animate the brush's opacity to 0 and back when
            // the left mouse button is pressed over the rectangle.
            //
            DoubleAnimation opacityAnimation = new DoubleAnimation();
            opacityAnimation.To = 0.0;
            opacityAnimation.Duration = TimeSpan.FromSeconds(0.5);
            opacityAnimation.AutoReverse = true;
            Storyboard.SetTargetName(opacityAnimation, "MyAnimatedBrush");
            Storyboard.SetTargetProperty(
                opacityAnimation, new PropertyPath(SolidColorBrush.OpacityProperty));
            Storyboard mouseLeftButtonDownStoryboard = new Storyboard();
            mouseLeftButtonDownStoryboard.Children.Add(opacityAnimation);
            aRectangle.MouseLeftButtonDown += delegate(object sender, MouseButtonEventArgs e)
            {
                mouseLeftButtonDownStoryboard.Begin(this);
            };

            StackPanel mainPanel = new StackPanel();
            mainPanel.Margin = new Thickness(20);
            mainPanel.Children.Add(aRectangle);
            Content = mainPanel;
        }

    }
}
```

有关更完整示例，其中说明了如何对不同类型的画笔进行动画处理，请参阅[画笔示例](https://go.microsoft.com/fwlink/?LinkID=159973)。 有关动画的详细信息，请参阅[动画概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/animation-overview)。

与其他动画示例保持一致，对于此示例中的代码版本使用[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)对象来应用它们的动画。 但是，当应用单个动画在代码中的，它是使用更加简便[BeginAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animatable.beginanimation)方法而不是使用[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)。 有关示例，请参阅[在不使用情节提要的情况下对属性进行动画处理](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-animate-a-property-without-using-a-storyboard)。

#### [Animate the Position or Color of a Gradient Stop](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-animate-the-position-or-color-of-a-gradient-stop)

此示例演示如何进行动画处理[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientstop.color)并[Offset](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientstop.offset)的[GradientStop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientstop)对象。

##### 示例

下面的示例进行动画处理中的三个梯度停止点[LinearGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush)。 该示例使用三个动画，其中每个进行动画处理不同的渐变停止点：

- 第一个动画[DoubleAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation)，进行动画处理对第一个梯度停止点的[Offset](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientstop.offset)从 0.0 到 1.0，然后再为 0.0。 因此，第一个颜色在渐变左侧会移至该矩形的右侧，然后再返回到左侧和右侧。
- 第二个动画[ColorAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.coloranimation)，进行第二个梯度停止点的动画处理[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientstop.color)从[Purple](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.colors.purple)到[Yellow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.colors.yellow)，然后返回[Purple](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.colors.purple)。因此，为黄色，并返回到紫色，从紫色将更改渐变中的中间颜色。
- 第三个动画，另一个[ColorAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.coloranimation)，对第三个梯度停止点的不透明度进行动画处理[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientstop.color)乘以-1，然后返回。 结果是，渐变中的第三个颜色淡出，然后再次变得不透明。

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Shapes;

namespace BrushesIntroduction
{
    public class GradientStopAnimationExample : Page
    {
        public GradientStopAnimationExample()
        {
            Title = "GradientStop Animation Example";
            Background = Brushes.White;

            // Create a NameScope for the page so that
            // Storyboards can be used.
            NameScope.SetNameScope(this, new NameScope());

            // Create a rectangle. This rectangle will
            // be painted with a gradient.
            Rectangle aRectangle = new Rectangle();
            aRectangle.Width = 200;
            aRectangle.Height = 100;
            aRectangle.Stroke = Brushes.Black;
            aRectangle.StrokeThickness = 1;

            // Create a LinearGradientBrush to paint
            // the rectangle's fill.
            LinearGradientBrush gradientBrush = new LinearGradientBrush();

            // Create gradient stops for the brush.
            GradientStop stop1 = new GradientStop(Colors.MediumBlue, 0.0);
            GradientStop stop2 = new GradientStop(Colors.Purple, 0.5);
            GradientStop stop3 = new GradientStop(Colors.Red, 1.0);

            // Register a name for each gradient stop with the
            // page so that they can be animated by a storyboard.
            this.RegisterName("GradientStop1", stop1);
            this.RegisterName("GradientStop2", stop2);
            this.RegisterName("GradientStop3", stop3);

            // Add the stops to the brush.
            gradientBrush.GradientStops.Add(stop1);
            gradientBrush.GradientStops.Add(stop2);
            gradientBrush.GradientStops.Add(stop3);

            // Apply the brush to the rectangle.
            aRectangle.Fill = gradientBrush;

            //
            // Animate the first gradient stop's offset from
            // 0.0 to 1.0 and then back to 0.0.
            //
            DoubleAnimation offsetAnimation = new DoubleAnimation();
            offsetAnimation.From = 0.0;
            offsetAnimation.To = 1.0;
            offsetAnimation.Duration = TimeSpan.FromSeconds(1.5);
            offsetAnimation.AutoReverse = true;
            Storyboard.SetTargetName(offsetAnimation, "GradientStop1");
            Storyboard.SetTargetProperty(offsetAnimation, 
                new PropertyPath(GradientStop.OffsetProperty));

            //
            // Animate the second gradient stop's color from
            // Purple to Yellow and then back to Purple.
            //
            ColorAnimation gradientStopColorAnimation = new ColorAnimation();
            gradientStopColorAnimation.From = Colors.Purple;
            gradientStopColorAnimation.To = Colors.Yellow;
            gradientStopColorAnimation.Duration = TimeSpan.FromSeconds(1.5);
            gradientStopColorAnimation.AutoReverse = true;
            Storyboard.SetTargetName(gradientStopColorAnimation, "GradientStop2");
            Storyboard.SetTargetProperty(gradientStopColorAnimation,
                new PropertyPath(GradientStop.ColorProperty));

            // Set the animation to begin after the first animation
            // ends.
            gradientStopColorAnimation.BeginTime = TimeSpan.FromSeconds(3);

            //
            // Animate the third gradient stop's color so
            // that it becomes transparent.
            //
            ColorAnimation opacityAnimation = new ColorAnimation();

            // Reduces the target color's alpha value by 1, 
            // making the color transparent.
            opacityAnimation.By = Color.FromScRgb(-1.0F, 0F, 0F, 0F);
            opacityAnimation.Duration = TimeSpan.FromSeconds(1.5);
            opacityAnimation.AutoReverse = true;
            Storyboard.SetTargetName(opacityAnimation, "GradientStop3");
            Storyboard.SetTargetProperty(opacityAnimation,
                new PropertyPath(GradientStop.ColorProperty));

            // Set the animation to begin after the first two
            // animations have ended. 
            opacityAnimation.BeginTime = TimeSpan.FromSeconds(6);

            // Create a Storyboard to apply the animations.
            Storyboard gradientStopAnimationStoryboard = new Storyboard();
            gradientStopAnimationStoryboard.Children.Add(offsetAnimation);
            gradientStopAnimationStoryboard.Children.Add(gradientStopColorAnimation);
            gradientStopAnimationStoryboard.Children.Add(opacityAnimation);

            // Begin the storyboard when the left mouse button is
            // pressed over the rectangle.
            aRectangle.MouseLeftButtonDown += delegate(object sender, MouseButtonEventArgs e)
            {
                gradientStopAnimationStoryboard.Begin(this);
            };

            StackPanel mainPanel = new StackPanel();
            mainPanel.Margin = new Thickness(10);
            mainPanel.Children.Add(aRectangle);
            Content = mainPanel;
        }
    }

```

```xaml
<Page  
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  Title="GradientStop Animation Example"
  Background="White">
  <StackPanel Margin="10">

    <Rectangle
      Width="200" 
      Height="100" 
      Stroke="Black" StrokeThickness="1">
      <Rectangle.Fill>
        <LinearGradientBrush>
          <GradientStop x:Name="GradientStop1" Color="MediumBlue" Offset="0.0" />
          <GradientStop x:Name="GradientStop2" Color="Purple" Offset="0.5" />
          <GradientStop x:Name="GradientStop3" Color="Red" Offset="1.0" />
        </LinearGradientBrush>
      </Rectangle.Fill>
      <Rectangle.Triggers>
        <EventTrigger RoutedEvent="Rectangle.MouseLeftButtonDown">
          <BeginStoryboard>
            <Storyboard>
              <DoubleAnimation 
                Storyboard.TargetName="GradientStop1"
                Storyboard.TargetProperty="Offset"
                From="0.0" To="1.0" Duration="0:0:1.5"
                AutoReverse="True" />
              <ColorAnimation 
                Storyboard.TargetName="GradientStop2"
                Storyboard.TargetProperty="Color"
                From="Purple" To="Yellow" 
                Duration="0:0:1.5"
                AutoReverse="True"
                BeginTime="0:0:3" />
              <ColorAnimation 
                Storyboard.TargetName="GradientStop3"
                Storyboard.TargetProperty="Color" 
                Duration="0:0:1.5" 
                AutoReverse="True"
                BeginTime="0:0:6">
                <ColorAnimation.By>
                  <Color ScA="-1" ScR="0" ScB="0" ScG="0" />
                </ColorAnimation.By>
              </ColorAnimation>
            </Storyboard>
          </BeginStoryboard>
        </EventTrigger>
      </Rectangle.Triggers>
    </Rectangle>
    
  </StackPanel>
</Page>
```

虽然此示例使用[LinearGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush)，过程是相同的进行动画处理[GradientStop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientstop)对象内[RadialGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.radialgradientbrush)。

有关其他示例，请参阅[画笔示例](https://go.microsoft.com/fwlink/?LinkID=159973)。

#### [Create a Reflection](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-reflection)

此示例演示如何使用[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)创建反射。 因为[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)可以显示现有视觉对象，可以使用此功能来生成有趣的视觉效果，例如反射和放大。

##### 示例

下面的示例使用[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)若要创建的反射[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)包含多个元素。 下图显示了此示例生成的输出。

![一个反映视觉对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-visualbrush-reflection-small.jpg)
反射的 Visual 对象

```csharp
using System;
using System.Windows;
using System.Windows.Data;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Effects;
using System.Windows.Media.Imaging;
using System.IO;
using System.Collections.ObjectModel;
using System.Windows.Shapes;
namespace SDKSample
{
    public partial class ReflectionExample : Page
    {
        public ReflectionExample()
        {
            // Create a name scope for the page.
            NameScope.SetNameScope(this, new NameScope());

            this.Background = Brushes.Black;
            StackPanel myStackPanel = new StackPanel();
            myStackPanel.Margin = new Thickness(50);

            Border myReflectedBorder = new Border();
            this.RegisterName("ReflectedVisual", myReflectedBorder);

            // Create a gradient background for the border.
            GradientStop firstStop = new GradientStop();
            firstStop.Offset = 0.0;
            Color firstStopColor = new Color();
            firstStopColor.R = 204;
            firstStopColor.G = 204;
            firstStopColor.B = 255;
            firstStopColor.A = 255;
            firstStop.Color = firstStopColor;
            GradientStop secondStop = new GradientStop();
            secondStop.Offset = 1.0;
            secondStop.Color = Colors.White;

            GradientStopCollection myGradientStopCollection = new GradientStopCollection();
            myGradientStopCollection.Add(firstStop);
            myGradientStopCollection.Add(secondStop);

            LinearGradientBrush myLinearGradientBrush = new LinearGradientBrush();
            myLinearGradientBrush.StartPoint = new Point(0, 0.5);
            myLinearGradientBrush.EndPoint = new Point(1, 0.5);
            myLinearGradientBrush.GradientStops = myGradientStopCollection;

            myReflectedBorder.Background = myLinearGradientBrush;

            // Add contents to the border.
            StackPanel borderStackPanel = new StackPanel();
            borderStackPanel.Orientation = Orientation.Horizontal;
            borderStackPanel.Margin = new Thickness(10);

            TextBlock myTextBlock = new TextBlock();
            myTextBlock.TextWrapping = TextWrapping.Wrap;
            myTextBlock.Width = 200;
            myTextBlock.Text = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit." +
                               " Suspendisse vel ante. Donec luctus tortor sit amet est." +
                               " Nullam pulvinar odio et wisi." +
                               " Pellentesque quis magna. Sed pellentesque." +
                               " Nulla euismod." +
                               "Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas.";

            borderStackPanel.Children.Add(myTextBlock);

            StackPanel ellipseStackPanel = new StackPanel();

            Ellipse ellipse1 = new Ellipse();
            ellipse1.Margin = new Thickness(10);
            ellipse1.Height = 50;
            ellipse1.Width = 50;
            ellipse1.Fill = Brushes.Black;
            ellipseStackPanel.Children.Add(ellipse1);
            Ellipse ellipse2 = new Ellipse();
            ellipse2.Margin = new Thickness(10);
            ellipse2.Height = 50;
            ellipse2.Width = 50;
            ellipse2.Fill = Brushes.Black;
            ellipseStackPanel.Children.Add(ellipse2);
            Ellipse ellipse3 = new Ellipse();
            ellipse3.Margin = new Thickness(10);
            ellipse3.Height = 50;
            ellipse3.Width = 50;
            ellipse3.Fill = Brushes.Black;
            ellipseStackPanel.Children.Add(ellipse3);
            borderStackPanel.Children.Add(ellipseStackPanel);

            myReflectedBorder.Child = borderStackPanel;

            // Create divider rectangle
            Rectangle dividerRectangle = new Rectangle();
            dividerRectangle.Height = 1;
            dividerRectangle.Fill = Brushes.Gray;
            dividerRectangle.HorizontalAlignment = HorizontalAlignment.Stretch;

            // Create the object to contain the reflection.
            Rectangle reflectionRectangle = new Rectangle();

            // Bind the height of the rectangle to the border height.
            Binding heightBinding = new Binding();
            heightBinding.ElementName = "ReflectedVisual";
            heightBinding.Path = new PropertyPath(Rectangle.HeightProperty);
            BindingOperations.SetBinding(reflectionRectangle, Rectangle.HeightProperty, heightBinding);

            // Bind the width of the rectangle to the border width.
            Binding widthBinding = new Binding();
            widthBinding.ElementName = "ReflectedVisual";
            widthBinding.Path = new PropertyPath(Rectangle.WidthProperty);
            BindingOperations.SetBinding(reflectionRectangle, Rectangle.WidthProperty, widthBinding);

            // Creates the reflection.
            VisualBrush myVisualBrush = new VisualBrush();
            myVisualBrush.Opacity = 0.75;
            myVisualBrush.Stretch = Stretch.None;
            Binding reflectionBinding = new Binding();
            reflectionBinding.ElementName = "ReflectedVisual";
            BindingOperations.SetBinding(myVisualBrush, VisualBrush.VisualProperty, reflectionBinding);

            ScaleTransform myScaleTransform = new ScaleTransform();
            myScaleTransform.ScaleX = 1;
            myScaleTransform.ScaleY = -1;
            TranslateTransform myTranslateTransform = new TranslateTransform();
            myTranslateTransform.Y = 1;

            TransformGroup myTransformGroup = new TransformGroup();
            myTransformGroup.Children.Add(myScaleTransform);
            myTransformGroup.Children.Add(myTranslateTransform);

            myVisualBrush.RelativeTransform = myTransformGroup;

            reflectionRectangle.Fill = myVisualBrush;

            // Create a gradient background for the border.
            GradientStop firstStop2 = new GradientStop();
            firstStop2.Offset = 0.0;
            Color c1 = new Color();
            c1.R = 0;
            c1.G = 0;
            c1.B = 0;
            c1.A = 255;
            firstStop2.Color = c1;
            GradientStop secondStop2 = new GradientStop();
            secondStop2.Offset = 0.5;
            Color c2 = new Color();
            c2.R = 0;
            c2.G = 0;
            c2.B = 0;
            c2.A = 51;
            firstStop2.Color = c2;
            GradientStop thirdStop = new GradientStop();
            thirdStop.Offset = 0.75;
            Color c3 = new Color();
            c3.R = 0;
            c3.G = 0;
            c3.B = 0;
            c3.A = 0;
            thirdStop.Color = c3;

            GradientStopCollection myGradientStopCollection2 = new GradientStopCollection();
            myGradientStopCollection2.Add(firstStop2);
            myGradientStopCollection2.Add(secondStop2);
            myGradientStopCollection2.Add(thirdStop);

            LinearGradientBrush myLinearGradientBrush2 = new LinearGradientBrush();
            myLinearGradientBrush2.StartPoint = new Point(0.5, 0);
            myLinearGradientBrush2.EndPoint = new Point(0.5, 1);
            myLinearGradientBrush2.GradientStops = myGradientStopCollection2;

            reflectionRectangle.OpacityMask = myLinearGradientBrush2;

            BlurBitmapEffect myBlurBitmapEffect = new BlurBitmapEffect();
            myBlurBitmapEffect.Radius = 1.5;

            reflectionRectangle.BitmapEffect = myBlurBitmapEffect;

            myStackPanel.Children.Add(myReflectedBorder);
            myStackPanel.Children.Add(dividerRectangle);
            myStackPanel.Children.Add(reflectionRectangle);
            this.Content = myStackPanel;

        }
        /*
    <Rectangle 
      Height="{Binding Path=ActualHeight, ElementName=ReflectedVisual}" 
      Width="{Binding Path=ActualWidth, ElementName=ReflectedVisual}">

      <Rectangle.OpacityMask>
        <LinearGradientBrush StartPoint="0.5,0" EndPoint="0.5,1">
          <GradientStop Color="#FF000000" Offset="0.0" />
          <GradientStop Color="#33000000" Offset="0.5" />
          <GradientStop Color="#00000000" Offset="0.75" />
        </LinearGradientBrush>
      </Rectangle.OpacityMask>

      <Rectangle.BitmapEffect>
        <BlurBitmapEffect Radius="1.5" />
      </Rectangle.BitmapEffect>
      
    </Rectangle>
  </StackPanel>
</Page>

*/
        
    }
}
```

```xaml
<Page  
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml" 
  Background="Black">


  <StackPanel Margin="50">

    <!-- The object to reflect. -->
    <Border Name="ReflectedVisual" Width="400">
      <Border.Background>
        <LinearGradientBrush StartPoint="0,0.5" EndPoint="1,0.5">
          <GradientStop Offset="0.0" Color="#CCCCFF" />
          <GradientStop Offset="1.0" Color="White" />
        </LinearGradientBrush>
      </Border.Background>
      <StackPanel Orientation="Horizontal" Margin="10">        
        <TextBlock TextWrapping="Wrap" Width="200" Margin="10">
          Lorem ipsum dolor sit amet, consectetuer adipiscing elit.
          Suspendisse vel ante. Donec luctus tortor sit amet est.
          Nullam pulvinar odio et wisi.
          Pellentesque quis magna. Sed pellentesque.
          Nulla euismod.
          Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas.
        </TextBlock>
        <StackPanel>
          <Ellipse Margin="10" Height="50" Width="50" Fill="Black" />
          <Ellipse Margin="10" Height="50" Width="50" Fill="Black" />
          <Ellipse Margin="10" Height="50" Width="50" Fill="Black" />
        </StackPanel>
      </StackPanel>
    </Border>

    <Rectangle Height="1" Fill="Gray" HorizontalAlignment="Stretch" />

    <!-- The object to contain the reflection.-->
    <Rectangle 
      Height="{Binding Path=ActualHeight, ElementName=ReflectedVisual}" 
      Width="{Binding Path=ActualWidth, ElementName=ReflectedVisual}">
      <Rectangle.Fill>

        <!-- Creates the reflection. -->
        <VisualBrush 
          Opacity="0.75" Stretch="None"
          Visual="{Binding ElementName=ReflectedVisual}">
          <VisualBrush.RelativeTransform>

            <!-- Flip the reflection. -->
            <TransformGroup>
              <ScaleTransform ScaleX="1" ScaleY="-1" />
              <TranslateTransform  Y="1" />
            </TransformGroup>
          </VisualBrush.RelativeTransform>
        </VisualBrush>
      </Rectangle.Fill>

      <Rectangle.OpacityMask>
        <LinearGradientBrush StartPoint="0.5,0" EndPoint="0.5,1">
          <GradientStop Color="#FF000000" Offset="0.0" />
          <GradientStop Color="#33000000" Offset="0.5" />
          <GradientStop Color="#00000000" Offset="0.75" />
        </LinearGradientBrush>
      </Rectangle.OpacityMask>

      <Rectangle.BitmapEffect>
        <BlurBitmapEffect Radius="1.5" />
      </Rectangle.BitmapEffect>
      
    </Rectangle>
  </StackPanel>
</Page>
```

有关完整示例，其中包括显示如何放大屏幕的部分以及如何创建反射的示例，请参阅[VisualBrush 示例](https://go.microsoft.com/fwlink/?LinkID=160049)。

#### [Create Different Tile Patterns with a TileBrush](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-create-different-tile-patterns-with-a-tilebrush)

此示例演示如何使用[TileMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.tilemode)属性的[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)创建模式。

[TileMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.tilemode)属性可用于指定如何将内容的[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)重复，也就是说，平铺来填充输出区域。 若要创建一种模式，您可以设置[TileMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.tilemode)到[Tile](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilemode#System_Windows_Media_TileMode_Tile)， [FlipX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilemode#System_Windows_Media_TileMode_FlipX)， [FlipY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilemode#System_Windows_Media_TileMode_FlipY)，或[FlipXY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilemode#System_Windows_Media_TileMode_FlipXY)。 您还必须设置[Viewport](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewport)的[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)以便小于区域要绘制; 否则，单个磁贴是生成，而不考虑其[TileMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.tilemode)您使用的设置。

##### 示例

下面的示例创建五个[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)对象，每个不同[TileMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.tilemode)设置，并使用它们来绘制五个矩形。 虽然此示例使用[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)类，以演示[TileMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.tilemode)行为，[TileMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.tilemode)属性的工作方式完全相同的所有[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)对象，也就是说，对于[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)， [VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)，和[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)。

下图显示了此示例生成的输出。

![TileBrush 平铺示例输出](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-drawingbrushtilemodeexample.png)
使用 TileMode 属性创建平铺模式

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Shapes;

namespace BrushesIntroduction
{
    public class TileModeExample : Page
    {

        public TileModeExample()
        {
            Background = Brushes.White;
            Margin = new Thickness(20);
            StackPanel mainPanel = new StackPanel();
            mainPanel.HorizontalAlignment = HorizontalAlignment.Left;

            //
            // Create a Drawing. This will be the DrawingBrushes' content.
            //
            PolyLineSegment triangleLinesSegment = new PolyLineSegment();
            triangleLinesSegment.Points.Add(new Point(50, 0));
            triangleLinesSegment.Points.Add(new Point(0, 50));
            PathFigure triangleFigure = new PathFigure();
            triangleFigure.IsClosed = true;
            triangleFigure.StartPoint = new Point(0, 0);
            triangleFigure.Segments.Add(triangleLinesSegment);
            PathGeometry triangleGeometry = new PathGeometry();
            triangleGeometry.Figures.Add(triangleFigure);

            GeometryDrawing triangleDrawing = new GeometryDrawing();
            triangleDrawing.Geometry = triangleGeometry;
            triangleDrawing.Brush = new SolidColorBrush(Color.FromArgb(255, 204, 204, 255));
            Pen trianglePen = new Pen(Brushes.Black, 2);
            triangleDrawing.Pen = trianglePen;
            trianglePen.MiterLimit = 0;
            triangleDrawing.Freeze();

            //
            // Create the first TileBrush. Its content is not tiled.
            //
            DrawingBrush tileBrushWithoutTiling = new DrawingBrush();
            tileBrushWithoutTiling.Drawing = triangleDrawing;
            tileBrushWithoutTiling.TileMode = TileMode.None;
            
            // Create a rectangle and paint it with the DrawingBrush.
            Rectangle noTileExampleRectangle = createExampleRectangle();
            noTileExampleRectangle.Fill = tileBrushWithoutTiling;

            // Add a header and the rectangle to the main panel.
            mainPanel.Children.Add(createExampleHeader("None"));
            mainPanel.Children.Add(noTileExampleRectangle);

            //
            // Create another TileBrush, this time with tiling.
            //
            DrawingBrush tileBrushWithTiling = new DrawingBrush();
            tileBrushWithTiling.Drawing = triangleDrawing;
            tileBrushWithTiling.TileMode = TileMode.Tile;

            // Specify the brush's Viewport. Otherwise,
            // a single tile will be produced that fills
            // the entire output area and its TileMode will
            // have no effect.
            // This setting uses realtive values to
            // creates four tiles. 
            tileBrushWithTiling.Viewport = new Rect(0, 0, 0.5, 0.5);

            // Create a rectangle and paint it with the DrawingBrush.
            Rectangle tilingExampleRectangle = createExampleRectangle();
            tilingExampleRectangle.Fill = tileBrushWithTiling;
            mainPanel.Children.Add(createExampleHeader("Tile"));
            mainPanel.Children.Add(tilingExampleRectangle);

            //
            // Create a TileBrush with FlipX tiling.
            // The brush's content is flipped horizontally as it is
            // tiled in this example
            //
            DrawingBrush tileBrushWithFlipXTiling = new DrawingBrush();
            tileBrushWithFlipXTiling.Drawing = triangleDrawing;
            tileBrushWithFlipXTiling.TileMode = TileMode.FlipX;

            // Specify the brush's Viewport.
            tileBrushWithFlipXTiling.Viewport = new Rect(0, 0, 0.5, 0.5);

            // Create a rectangle and paint it with the DrawingBrush.
            Rectangle flipXTilingExampleRectangle = createExampleRectangle();
            flipXTilingExampleRectangle.Fill = tileBrushWithFlipXTiling;
            mainPanel.Children.Add(createExampleHeader("FlipX"));
            mainPanel.Children.Add(flipXTilingExampleRectangle);

            //
            // Create a TileBrush with FlipY tiling.
            // The brush's content is flipped vertically as it is
            // tiled in this example
            //
            DrawingBrush tileBrushWithFlipYTiling = new DrawingBrush();
            tileBrushWithFlipYTiling.Drawing = triangleDrawing;
            tileBrushWithFlipYTiling.TileMode = TileMode.FlipY;

            // Specify the brush's Viewport.
            tileBrushWithFlipYTiling.Viewport = new Rect(0, 0, 0.5, 0.5);

            // Create a rectangle and paint it with the DrawingBrush.
            Rectangle flipYTilingExampleRectangle = createExampleRectangle();
            flipYTilingExampleRectangle.Fill = tileBrushWithFlipYTiling;
            mainPanel.Children.Add(createExampleHeader("FlipY"));
            mainPanel.Children.Add(flipYTilingExampleRectangle);

            //
            // Create a TileBrush with FlipXY tiling.
            // The brush's content is flipped vertically as it is
            // tiled in this example
            //
            DrawingBrush tileBrushWithFlipXYTiling = new DrawingBrush();
            tileBrushWithFlipXYTiling.Drawing = triangleDrawing;
            tileBrushWithFlipXYTiling.TileMode = TileMode.FlipXY;

            // Specify the brush's Viewport.
            tileBrushWithFlipXYTiling.Viewport = new Rect(0, 0, 0.5, 0.5);

            // Create a rectangle and paint it with the DrawingBrush.
            Rectangle flipXYTilingExampleRectangle = createExampleRectangle();
            flipXYTilingExampleRectangle.Fill = tileBrushWithFlipXYTiling;
            mainPanel.Children.Add(createExampleHeader("FlipXY"));
            mainPanel.Children.Add(flipXYTilingExampleRectangle);

            Content = mainPanel;
        }

        //
        // Helper method that creates rectangle elements.
        //
        private static Rectangle createExampleRectangle()
        {
            Rectangle exampleRectangle = new Rectangle();
            exampleRectangle.Width = 50;
            exampleRectangle.Height = 50;
            exampleRectangle.Stroke = Brushes.Black;
            exampleRectangle.StrokeThickness = 1;
            return exampleRectangle;
        }

        //
        // Helper method that creates headers for the examples. 
        //
        private static TextBlock createExampleHeader(String text)
        {
            TextBlock header = new TextBlock();
            header.Margin = new Thickness(0, 10, 0, 0);
            header.Text = text;
            return header;
        }
    }
}
```

```xaml
<!-- Demonstrates TileMode values. -->
<Page  
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  xmlns:PresentationOptions="http://schemas.microsoft.com/winfx/2006/xaml/presentation/options" 
  xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
  mc:Ignorable="PresentationOptions"
  Background="White" Margin="20">
  <Page.Resources>

    <!-- Define a Drawing as a resource that it can be easily used
         as content for all the DrawingBrush objects in this example. -->
    <GeometryDrawing x:Key="TriangleDrawing"
      Geometry="M0,0 L50,0 0,50Z" Brush="#CCCCFF"
      PresentationOptions:Freeze="True" >
      <GeometryDrawing.Pen>
        <Pen Thickness="2" Brush="Black" MiterLimit="0" />
      </GeometryDrawing.Pen>
    </GeometryDrawing>
  </Page.Resources>

  <StackPanel HorizontalAlignment="Left">
    <TextBlock Margin="0,10,0,0">None</TextBlock>
    <Rectangle Width="50" Height="50" Stroke="Black" StrokeThickness="1">
      <Rectangle.Fill>

        <!-- The DrawingBrush's content is not tiled in this example. -->
        <DrawingBrush TileMode="None" 
          Drawing="{StaticResource TriangleDrawing}" />
      </Rectangle.Fill>
    </Rectangle>

    <TextBlock Margin="0,10,0,0">Tile</TextBlock>
    <Rectangle Width="50" Height="50" Stroke="Black" StrokeThickness="1">
      <Rectangle.Fill>

        <!-- The DrawingBrush's content is tiled in this example. 
             The Viewport property is set to create four tiles. -->
        <DrawingBrush TileMode="Tile" Viewport="0,0,0.5,0.5" 
          Drawing="{StaticResource TriangleDrawing}"/>
      </Rectangle.Fill>
    </Rectangle>

    <TextBlock Margin="0,10,0,0">FlipX</TextBlock>
    <Rectangle Width="50" Height="50" Stroke="Black" StrokeThickness="1">
      <Rectangle.Fill>

        <!-- The DrawingBrush's content is flipped horizontally as it is
             tiled in this example. -->
        <DrawingBrush 
          TileMode="FlipX" Viewport="0,0,0.5,0.5"
          Drawing="{StaticResource TriangleDrawing}" />
      </Rectangle.Fill>
    </Rectangle>

    <TextBlock Margin="0,10,0,0">FlipY</TextBlock>
    <Rectangle Width="50" Height="50" Stroke="Black" StrokeThickness="1">
      <Rectangle.Fill>

        <!-- The DrawingBrush's content is flipped vertically as it is
             tiled in this example. -->
        <DrawingBrush TileMode="FlipY" Viewport="0,0,0.5,0.5" 
          Drawing="{StaticResource TriangleDrawing}" />
      </Rectangle.Fill>
    </Rectangle>

    <TextBlock Margin="0,10,0,0">FlipXY</TextBlock>
    <Rectangle Width="50" Height="50" Stroke="Black" StrokeThickness="1">
      <Rectangle.Fill>

        <!-- The DrawingBrush's content is flipped horizontally
             and vertically as it is tiled in this example. -->
        <DrawingBrush TileMode="FlipXY" Viewport="0,0,0.5,0.5" 
          Drawing="{StaticResource TriangleDrawing}" />
      </Rectangle.Fill>
    </Rectangle>

  </StackPanel>
</Page>
```

#### [Define a Pen](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-define-a-pen)

此示例演示如何使用[Pen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pen)概述一种形状。 若要创建一个简单[Pen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pen)，只需指定其[Thickness](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pen.thickness)和[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pen.brush)。 你可以通过指定创建更复杂的钢笔[DashStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pen.dashstyle)， [DashCap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pen.dashcap)， [LineJoin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pen.linejoin)， [StartLineCap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pen.startlinecap)，和[EndLineCap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pen.endlinecap)。

##### 示例

下面的示例使用[Pen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pen)概述一个形状定义[GeometryDrawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometrydrawing)。

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
namespace SDKSample
{
    public partial class PenExample : Page
    {
        public PenExample()
        {
            // Create several geometries.
            RectangleGeometry myRectangleGeometry = new RectangleGeometry();
            myRectangleGeometry.Rect = new Rect(0, 0, 50, 50);
            EllipseGeometry myEllipseGeometry = new EllipseGeometry();
            myEllipseGeometry.Center = new Point(75, 75);
            myEllipseGeometry.RadiusX = 50;
            myEllipseGeometry.RadiusY = 50;
            LineGeometry myLineGeometry = new LineGeometry();
            myLineGeometry.StartPoint = new Point(75, 75);
            myLineGeometry.EndPoint = new Point(75, 0);

            // Create a GeometryGroup and add the geometries to it.
            GeometryGroup myGeometryGroup = new GeometryGroup();
            myGeometryGroup.Children.Add(myRectangleGeometry);
            myGeometryGroup.Children.Add(myEllipseGeometry);
            myGeometryGroup.Children.Add(myLineGeometry);

            // Create a GeometryDrawing and use the GeometryGroup to specify
            // its geometry.
            GeometryDrawing myGeometryDrawing = new GeometryDrawing();
            myGeometryDrawing.Geometry = myGeometryGroup;

            // Add the GeometryDrawing to a DrawingGroup.
            DrawingGroup myDrawingGroup = new DrawingGroup();
            myDrawingGroup.Children.Add(myGeometryDrawing);

            // Create a Pen to add to the GeometryDrawing created above.
            Pen myPen = new Pen();
            myPen.Thickness = 10;
            myPen.LineJoin = PenLineJoin.Round;
            myPen.EndLineCap = PenLineCap.Round;

            // Create a gradient to use as a value for the Pen's Brush property.
            GradientStop firstStop = new GradientStop();
            firstStop.Offset = 0.0;
            Color c1 = new Color();
            c1.A = 255;
            c1.R = 204;
            c1.G = 204;
            c1.B = 255;
            firstStop.Color = c1;
            GradientStop secondStop = new GradientStop();
            secondStop.Offset = 1.0;
            secondStop.Color = Colors.Purple;
            
            LinearGradientBrush myLinearGradientBrush = new LinearGradientBrush();
            myLinearGradientBrush.GradientStops.Add(firstStop);
            myLinearGradientBrush.GradientStops.Add(secondStop);

            myPen.Brush = myLinearGradientBrush;
            myGeometryDrawing.Pen = myPen;

            // Create an Image and set its DrawingImage to the Geometry created above.
            Image myImage = new Image();
            myImage.Stretch = Stretch.None;
            myImage.Margin = new Thickness(10);

            DrawingImage myDrawingImage = new DrawingImage();
            myDrawingImage.Drawing = myDrawingGroup;
            myImage.Source = myDrawingImage;

            this.Content = myImage;

        }      
    }
}
```

![概述了通过 Pen 产生的](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-simple-pen.jpg)
一个 GeometryDrawing

#### [Paint an Area with a Drawing](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-paint-an-area-with-a-drawing)

本示例演示如何使用 Drawing 绘制一个区域。 若要绘制带有绘制的区域，请使用[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)和一个或多个[Drawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawing)对象。 下面的示例使用[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)来绘制具有两个椭圆的绘图的对象。

##### 示例

```xaml
<!-- Demonstrates the use of DrawingBrush. -->
<Page  
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  Background="White">
  <StackPanel Margin="20">

    <Rectangle Width="150" Height="150" Stroke="Black" StrokeThickness="1">
      <Rectangle.Fill>
        <DrawingBrush>
          <DrawingBrush.Drawing>
            <GeometryDrawing Brush="MediumBlue">
              <GeometryDrawing.Geometry>
                <GeometryGroup>
                  <EllipseGeometry RadiusX="20" RadiusY="45" Center="50,50" />
                  <EllipseGeometry RadiusX="45" RadiusY="20" Center="50,50" />
                </GeometryGroup>
              </GeometryDrawing.Geometry>
              <GeometryDrawing.Pen>
                <Pen Thickness="10">
                  <Pen.Brush>
                    <LinearGradientBrush>
                      <GradientStop Offset="0.0" Color="Black" />
                      <GradientStop Offset="1.0" Color="Gray" />
                    </LinearGradientBrush>
                  </Pen.Brush>
                </Pen>
              </GeometryDrawing.Pen>
            </GeometryDrawing>
          </DrawingBrush.Drawing>
        </DrawingBrush>
      </Rectangle.Fill>
    </Rectangle>
  </StackPanel>
</Page>
```

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;


namespace Microsoft.Samples.DrawingBrushExamples
{
    /// <summary>
    /// Paints a Rectangle element with a DrawingBrush.
    /// </summary>
    public class DrawingBrushExample : Page
    {
        public DrawingBrushExample()
        {
            Background = Brushes.White;
            StackPanel mainPanel = new StackPanel();

            // Create a drawing of two ellipses.
            GeometryDrawing aDrawing = new GeometryDrawing();

            // Use geometries to describe two overlapping ellipses.
            EllipseGeometry ellipse1 = new EllipseGeometry();
            ellipse1.RadiusX = 20;
            ellipse1.RadiusY = 45;
            ellipse1.Center = new Point(50, 50);
            EllipseGeometry ellipse2 = new EllipseGeometry();
            ellipse2.RadiusX = 45;
            ellipse2.RadiusY = 20;
            ellipse2.Center = new Point(50, 50);
            GeometryGroup ellipses = new GeometryGroup();
            ellipses.Children.Add(ellipse1);
            ellipses.Children.Add(ellipse2);

            // Add the geometry to the drawing.
            aDrawing.Geometry = ellipses;

            // Specify the drawing's fill.
            aDrawing.Brush = Brushes.Blue;

            // Specify the drawing's stroke.
            Pen stroke = new Pen();
            stroke.Thickness = 10.0;
            stroke.Brush = new LinearGradientBrush(
                Colors.Black, Colors.Gray, new Point(0, 0), new Point(1, 1));
            aDrawing.Pen = stroke;

            // Create a DrawingBrush
            DrawingBrush myDrawingBrush = new DrawingBrush();
            myDrawingBrush.Drawing = aDrawing;

            // Create a Rectangle element.
            Rectangle aRectangle = new Rectangle();
            aRectangle.Width = 150;
            aRectangle.Height = 150;
            aRectangle.Stroke = Brushes.Black;
            aRectangle.StrokeThickness = 1.0;

            // Use the DrawingBrush to paint the rectangle's
            // background.
            aRectangle.Fill = myDrawingBrush;

            mainPanel.Children.Add(aRectangle);

            this.Content = mainPanel;

        }
    }
}
```

下图显示该示例的输出。

![DrawingBrush 的输出](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-drawingbrush-simple.png)

(有关中所述的原因，形状的中心为白色[控制复合形状的填充](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-control-the-fill-of-a-composite-shape)。)

通过设置[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)对象的[Viewport](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewport)和[TileMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.tilemode)属性，你可以创建重复的模式。 以下示例使用基于由两个椭圆组成的 Drawing 创建的图案绘制一个对象。

```xaml
<!-- Demonstrates the use of DrawingBrush. -->
<Page  
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  Background="White">
  <StackPanel Margin="20">

    <Rectangle Width="150" Height="150" Stroke="Black" StrokeThickness="1">
      <Rectangle.Fill>
        <DrawingBrush Viewport="0,0,0.25,0.25" TileMode="Tile">
          <DrawingBrush.Drawing>
            <GeometryDrawing Brush="MediumBlue">
              <GeometryDrawing.Geometry>
                <GeometryGroup>
                  <EllipseGeometry RadiusX="20" RadiusY="45" Center="50,50" />
                  <EllipseGeometry RadiusX="45" RadiusY="20" Center="50,50" />
                </GeometryGroup>
              </GeometryDrawing.Geometry>
              <GeometryDrawing.Pen>
                <Pen Thickness="10">
                  <Pen.Brush>
                    <LinearGradientBrush>
                      <GradientStop Offset="0.0" Color="Black" />
                      <GradientStop Offset="1.0" Color="Gray" />
                    </LinearGradientBrush>
                  </Pen.Brush>
                </Pen>
              </GeometryDrawing.Pen>
            </GeometryDrawing>
          </DrawingBrush.Drawing>
        </DrawingBrush>
      </Rectangle.Fill>
    </Rectangle>
  </StackPanel>
</Page>
```

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;


namespace Microsoft.Samples.DrawingBrushExamples
{

    /// <summary>
    /// Paints a Rectangle element with a tiled DrawingBrush.
    /// </summary>
    public class TiledDrawingBrushExample : Page
    {

        public TiledDrawingBrushExample()
        {
            Background = Brushes.White;
            StackPanel mainPanel = new StackPanel();

            // Create a drawing of two ellipses.
            GeometryDrawing aDrawing = new GeometryDrawing();

            // Use geometries to describe two overlapping ellipses.
            EllipseGeometry ellipse1 = new EllipseGeometry();
            ellipse1.RadiusX = 20;
            ellipse1.RadiusY = 45;
            ellipse1.Center = new Point(50, 50);
            EllipseGeometry ellipse2 = new EllipseGeometry();
            ellipse2.RadiusX = 45;
            ellipse2.RadiusY = 20;
            ellipse2.Center = new Point(50, 50);
            GeometryGroup ellipses = new GeometryGroup();
            ellipses.Children.Add(ellipse1);
            ellipses.Children.Add(ellipse2);

            // Add the geometry to the drawing.
            aDrawing.Geometry = ellipses;

            // Specify the drawing's fill.
            aDrawing.Brush = Brushes.Blue;

            // Specify the drawing's stroke.
            Pen stroke = new Pen();
            stroke.Thickness = 10.0;
            stroke.Brush = new LinearGradientBrush(
                Colors.Black, Colors.Gray, new Point(0, 0), new Point(1, 1));
            aDrawing.Pen = stroke;

            // Create a DrawingBrush
            DrawingBrush myDrawingBrush = new DrawingBrush();
            myDrawingBrush.Drawing = aDrawing;

            // Set the DrawingBrush's Viewport and TileMode
            // properties so that it generates a pattern.
            myDrawingBrush.Viewport = new Rect(0, 0, 0.25, 0.25);
            myDrawingBrush.TileMode = TileMode.Tile;

            // Create a Rectangle element.
            Rectangle aRectangle = new Rectangle();
            aRectangle.Width = 150;
            aRectangle.Height = 150;
            aRectangle.Stroke = Brushes.Black;
            aRectangle.StrokeThickness = 1.0;

            // Use the DrawingBrush to paint the rectangle's
            // background.
            aRectangle.Fill = myDrawingBrush;

            mainPanel.Children.Add(aRectangle);

            this.Content = mainPanel;

        }

    }
}
```

下图显示了平铺[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)输出。

![DrawingBrush 的平铺输出](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-drawingbrush-tiled.png)

有关图形画笔的详细信息，请参阅[使用图像、 图形和视觉对象进行绘制](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-images-drawings-and-visuals)。 有关详细信息[Drawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawing)对象，请参阅[绘制对象概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/drawing-objects-overview)。

#### [Paint an Area with an Image](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-paint-an-area-with-an-image)

此示例演示如何使用[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)类，以使用图像绘制区域。 [ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)显示由指定的单个映像及其[ImageSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush.imagesource)属性。

##### 示例

以下示例绘制[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)通过使用一个按钮[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)。

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media.Imaging;
using System.Windows.Media;

namespace Microsoft.Samples.Graphics.UsingImageBrush
{

    public class PaintingWithImagesExample : Page
    {

        public PaintingWithImagesExample()
        {
            Background = Brushes.White;
            StackPanel mainPanel = new StackPanel();
            mainPanel.Margin = new Thickness(20.0);

            // Create a button.
            Button berriesButton = new Button();
            berriesButton.Foreground = Brushes.White;
            berriesButton.FontWeight = FontWeights.Bold;
            FontSizeConverter sizeConverter = new FontSizeConverter();
            berriesButton.FontSize = (Double)sizeConverter.ConvertFromString("16pt");
            berriesButton.FontFamily = new FontFamily("Verdana");
            berriesButton.Content = "Berries";
            berriesButton.Padding = new Thickness(20.0);
            berriesButton.HorizontalAlignment = HorizontalAlignment.Left;

            // Create an ImageBrush.
            ImageBrush berriesBrush = new ImageBrush();
            berriesBrush.ImageSource =
                new BitmapImage(
                    new Uri(@"sampleImages\berries.jpg", UriKind.Relative)
                );

            // Use the brush to paint the button's background.
            berriesButton.Background = berriesBrush;

            mainPanel.Children.Add(berriesButton);
            this.Content = mainPanel;
        }
    }
}
```

默认情况下，[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)拉伸其图像以完全填充要绘制的区域。 在以上示例中，拉伸图像以填充按钮，可能会使图像失真。 可以通过设置控制此行为[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.stretch)的属性[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)到[Uniform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_Uniform)或[UniformToFill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_UniformToFill)，这将导致要保持图像的纵横比的画笔。

如果您设置[Viewport](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewport)并[TileMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.tilemode)的属性[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)，可以创建一个重复图案。 以下示例通过使用从图像创建的图案来绘制按钮。

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media.Imaging;
using System.Windows.Media;

namespace Microsoft.Samples.Graphics.UsingImageBrush
{

    public class TiledImageBrushExample : Page
    {

        public TiledImageBrushExample()
        {
            Background = Brushes.White;
            StackPanel mainPanel = new StackPanel();
            mainPanel.Margin = new Thickness(20.0);

            // Create a button.
            Button berriesButton = new Button();
            berriesButton.Foreground = Brushes.White;
            berriesButton.FontWeight = FontWeights.Bold;
            FontSizeConverter sizeConverter = new FontSizeConverter();
            berriesButton.FontSize = (Double)sizeConverter.ConvertFromString("16pt");
            berriesButton.FontFamily = new FontFamily("Verdana");
            berriesButton.Content = "Berries";
            berriesButton.Padding = new Thickness(20.0);
            berriesButton.HorizontalAlignment = HorizontalAlignment.Left;

            // Create an ImageBrush.
            ImageBrush berriesBrush = new ImageBrush();
            berriesBrush.ImageSource =
                new BitmapImage(
                    new Uri(@"sampleImages\berries.jpg", UriKind.Relative)
                );
                
            // Set the ImageBrush's Viewport and TileMode
            // so that it produces a pattern from
            // the image.
            berriesBrush.Viewport = new Rect(0,0,0.5,0.5);
            berriesBrush.TileMode = TileMode.FlipXY;

            // Use the brush to paint the button's background.
            berriesButton.Background = berriesBrush;

            mainPanel.Children.Add(berriesButton);
            this.Content = mainPanel;
        }
    }
}
```

有关详细信息[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)类，请参阅[使用图像、 绘图和视觉对象进行绘制](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-images-drawings-and-visuals)。

此代码示例是为提供一个更大示例的一部分[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)类。 有关完整示例，请参阅[ImageBrush 示例](https://go.microsoft.com/fwlink/?LinkID=160005)。

#### [Paint an Area with a Linear Gradient](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-paint-an-area-with-a-linear-gradient)

此示例演示如何使用[LinearGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush)类来绘制带有线性渐变的区域。 在以下示例中，[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)的[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)用黄色从过渡到红色变为蓝色变为浅绿色对角线方向线性渐变绘制。

##### 示例

```xaml
<!-- This rectangle is painted with a diagonal linear gradient. -->
<Rectangle Width="200" Height="100">
  <Rectangle.Fill>
    <LinearGradientBrush StartPoint="0,0" EndPoint="1,1">
      <GradientStop Color="Yellow" Offset="0.0" />
      <GradientStop Color="Red" Offset="0.25" />
      <GradientStop Color="Blue" Offset="0.75" />
      <GradientStop Color="LimeGreen" Offset="1.0" />
    </LinearGradientBrush>
  </Rectangle.Fill>
</Rectangle>
```

```csharp
Rectangle diagonalFillRectangle = new Rectangle();
diagonalFillRectangle.Width = 200;
diagonalFillRectangle.Height = 100;

// Create a diagonal linear gradient with four stops.   
LinearGradientBrush myLinearGradientBrush =
    new LinearGradientBrush();
myLinearGradientBrush.StartPoint = new Point(0,0);
myLinearGradientBrush.EndPoint = new Point(1,1);
myLinearGradientBrush.GradientStops.Add(
    new GradientStop(Colors.Yellow, 0.0));
myLinearGradientBrush.GradientStops.Add(
    new GradientStop(Colors.Red, 0.25));                
myLinearGradientBrush.GradientStops.Add(
    new GradientStop(Colors.Blue, 0.75));        
myLinearGradientBrush.GradientStops.Add(
    new GradientStop(Colors.LimeGreen, 1.0));
    
// Use the brush to paint the rectangle.
diagonalFillRectangle.Fill = myLinearGradientBrush;
```

下图显示上一示例所创建的渐变。

![对角线方向线性渐变](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-diagonallgb.jpg)

若要创建水平方向线性渐变，更改[StartPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush.startpoint)并[EndPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush.endpoint)的[LinearGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush)到 (0,0.5) 和 (1,0.5)。 在以下示例中，[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)使用水平线性渐变绘制。

```xaml
<!-- This rectangle is painted with a horizontal linear gradient. -->
<Rectangle Width="200" Height="100">
  <Rectangle.Fill>
    <LinearGradientBrush StartPoint="0,0.5" EndPoint="1,0.5">
      <GradientStop Color="Yellow" Offset="0.0" />
      <GradientStop Color="Red" Offset="0.25" />
      <GradientStop Color="Blue" Offset="0.75" />
      <GradientStop Color="LimeGreen" Offset="1.0" />
    </LinearGradientBrush>
  </Rectangle.Fill>
</Rectangle>
```

```csharp
Rectangle horizontalFillRectangle = new Rectangle();
horizontalFillRectangle.Width = 200;
horizontalFillRectangle.Height = 100;

// Create a horizontal linear gradient with four stops.   
LinearGradientBrush myHorizontalGradient =
    new LinearGradientBrush();
myHorizontalGradient.StartPoint = new Point(0,0.5);
myHorizontalGradient.EndPoint = new Point(1,0.5);
myHorizontalGradient.GradientStops.Add(
    new GradientStop(Colors.Yellow, 0.0));
myHorizontalGradient.GradientStops.Add(
    new GradientStop(Colors.Red, 0.25));                
myHorizontalGradient.GradientStops.Add(
    new GradientStop(Colors.Blue, 0.75));        
myHorizontalGradient.GradientStops.Add(
    new GradientStop(Colors.LimeGreen, 1.0));
    
// Use the brush to paint the rectangle.
horizontalFillRectangle.Fill = myHorizontalGradient; 
```

下图显示上一示例所创建的渐变。

![水平方向线性渐变](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-horizontallgb.jpg)

若要创建一个垂直线性渐变，更改[StartPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush.startpoint)并[EndPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush.endpoint)的[LinearGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush)为 (0.5，0) 和 (0.5，1)。 在以下示例中，[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)使用一个垂直线性渐变绘制。

```xaml
<!-- This rectangle is painted with a vertical gradient. -->
<Rectangle Width="200" Height="100">
  <Rectangle.Fill>
    <LinearGradientBrush StartPoint="0.5,0" EndPoint="0.5,1">
      <GradientStop Color="Yellow" Offset="0.0" />
      <GradientStop Color="Red" Offset="0.25" />
      <GradientStop Color="Blue" Offset="0.75" />
      <GradientStop Color="LimeGreen" Offset="1.0" />
    </LinearGradientBrush>
  </Rectangle.Fill>
</Rectangle>
```

```csharp
Rectangle verticalFillRectangle = new Rectangle();
verticalFillRectangle.Width = 200;
verticalFillRectangle.Height = 100;

// Create a vertical linear gradient with four stops.   
LinearGradientBrush myVerticalGradient =
    new LinearGradientBrush();
myVerticalGradient.StartPoint = new Point(0.5,0);
myVerticalGradient.EndPoint = new Point(0.5,1);
myVerticalGradient.GradientStops.Add(
    new GradientStop(Colors.Yellow, 0.0));
myVerticalGradient.GradientStops.Add(
    new GradientStop(Colors.Red, 0.25));                
myVerticalGradient.GradientStops.Add(
    new GradientStop(Colors.Blue, 0.75));        
myVerticalGradient.GradientStops.Add(
    new GradientStop(Colors.LimeGreen, 1.0));
    
// Use the brush to paint the rectangle.
verticalFillRectangle.Fill = myVerticalGradient;  
```

下图显示上一示例所创建的渐变。

![垂直线性渐变](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-verticallgb.jpg)

> 本主题中的示例设置起始点和终结点使用默认坐标系统。 默认坐标系与边界框是： 0 指示边界框的 0 %1 指示边界框的 100%。 您可以通过设置更改此坐标系[MappingMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientbrush.mappingmode)属性的值[BrushMappingMode.Absolute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brushmappingmode#System_Windows_Media_BrushMappingMode_Absolute)。绝对坐标系与范围框无关。 值直接在本地空间中解释。

有关其他示例，请参阅[画笔示例](https://go.microsoft.com/fwlink/?LinkID=159973)。 渐变和画笔的其他类型的详细信息，请参阅[使用纯色和渐变概述进行绘制](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-solid-colors-and-gradients-overview)。

#### [Paint an Area with a Radial Gradient](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-paint-an-area-with-a-radial-gradient)

此示例演示如何使用[RadialGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.radialgradientbrush)类，以使用径向渐变绘制区域。

##### 示例

下面的示例使用[RadialGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.radialgradientbrush)绘制一个矩形使用径向渐变的黄色从过渡到红色变为蓝色变为浅绿色。

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Shapes;

namespace BrushesIntroduction
{
    public class RadialGradientBrushSnippet : Page
    {
        public RadialGradientBrushSnippet()
        {
            Title = "RadialGradientBrush Example";
            Background = Brushes.White;
            Margin = new Thickness(20);

            //
            // Create a RadialGradientBrush with four gradient stops.
            //
            RadialGradientBrush radialGradient = new RadialGradientBrush();

            // Set the GradientOrigin to the center of the area being painted.
            radialGradient.GradientOrigin = new Point(0.5, 0.5);
            
            // Set the gradient center to the center of the area being painted.
            radialGradient.Center = new Point(0.5, 0.5);

            // Set the radius of the gradient circle so that it extends to
            // the edges of the area being painted.
            radialGradient.RadiusX = 0.5; 
            radialGradient.RadiusY = 0.5;

            // Create four gradient stops.
            radialGradient.GradientStops.Add(new GradientStop(Colors.Yellow, 0.0));
            radialGradient.GradientStops.Add(new GradientStop(Colors.Red, 0.25));
            radialGradient.GradientStops.Add(new GradientStop(Colors.Blue, 0.75));
            radialGradient.GradientStops.Add(new GradientStop(Colors.LimeGreen, 1.0));

            // Freeze the brush (make it unmodifiable) for performance benefits.
            radialGradient.Freeze();

            // Create a rectangle and paint it with the 
            // RadialGradientBrush.
            Rectangle aRectangle = new Rectangle();
            aRectangle.Width = 200;
            aRectangle.Height = 100;
            aRectangle.Fill = radialGradient;

            StackPanel mainPanel = new StackPanel();
            mainPanel.Children.Add(aRectangle);
            Content = mainPanel;

        }

    }
}
```

```xaml
<Page 
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  Title="RadialGradientBrush Example"
  Background="White" Margin="20">
  <StackPanel>

    <!-- This rectangle is painted with a radial gradient. -->
    <Rectangle Width="200" Height="100">
      <Rectangle.Fill>
        <RadialGradientBrush 
          GradientOrigin="0.5,0.5" 
          Center="0.5,0.5" RadiusX="0.5" RadiusY="0.5">
          <RadialGradientBrush.GradientStops>
            <GradientStop Color="Yellow" Offset="0" />
            <GradientStop Color="Red" Offset="0.25" />
            <GradientStop Color="Blue" Offset="0.75" />
            <GradientStop Color="LimeGreen" Offset="1" />
          </RadialGradientBrush.GradientStops>
        </RadialGradientBrush>
      </Rectangle.Fill>
    </Rectangle>
  </StackPanel>
</Page>
```

下图显示了前面的示例中的渐变。 其中突出显示的渐变停止点。

![径向渐变中的梯度停止点](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wcpsdk-graphicsmm-4gradientstops-rg.png)

> 本主题中的示例使用默认坐标系来设置控制点。 默认坐标系与边界框是： 0 指示边界框的 0 %1 指示边界框的 100%。 您可以通过设置更改此坐标系[MappingMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientbrush.mappingmode)属性的值[Absolute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brushmappingmode#System_Windows_Media_BrushMappingMode_Absolute)。 绝对坐标系与范围框无关。 值直接在本地空间中解释。

有关更多[RadialGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.radialgradientbrush)示例，请参阅[画笔示例](https://go.microsoft.com/fwlink/?LinkID=159973)。 渐变和画笔的其他类型的详细信息，请参阅[使用纯色和渐变概述进行绘制](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-solid-colors-and-gradients-overview)。

#### [Paint an Area with a Solid Color](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-paint-an-area-with-a-solid-color)

若要绘制使用纯色区域，可以使用预定义的系统画笔，如[Red](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brushes.red)或[Blue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brushes.blue)，也可以创建一个新[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)并描述其[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush.color)使用 alpha、 红色、 绿色和蓝色值。 在 XAML 中，还可以使用十六进制表示法来利用纯色绘制区域。

下面的示例使用上述每种方法来绘制[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)蓝色。

##### 示例

**使用预定义画笔**

在下面的示例使用预定义的画笔[Blue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brushes.blue)来绘制一个蓝色矩形。

```xaml
<Rectangle Width="50" Height="50" Fill="Blue" />
```

```csharp
// Create a rectangle and paint it with
// a predefined brush.
Rectangle myPredefinedBrushRectangle = new Rectangle();
myPredefinedBrushRectangle.Width = 50;
myPredefinedBrushRectangle.Height = 50;
myPredefinedBrushRectangle.Fill = Brushes.Blue;
```

**使用十六进制表示法**

下一个示例使用 8 位十六进制表示法绘制一个蓝色矩形。

```xaml
<!-- Note that the first two characters "FF" of the 8-digit
     value is the alpha which controls the transparency of 
     the color. Therefore, to make a completely transparent
     color (invisible), use "00" for those digits (e.g. #000000FF). -->
<Rectangle Width="50" Height="50" Fill="#FF0000FF" />
```

**使用 ARGB 值**

下一个示例创建[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)并介绍了其[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush.color)使用 ARGB 值为蓝色。

```xaml
<Rectangle Width="50" Height="50">
  <Rectangle.Fill>
    <SolidColorBrush>
     <SolidColorBrush.Color>

        <!-- Describes the brush's color using
             RGB values. Each value has a range of 0-255.  
             R is for red, G is for green, and B is for blue.
             A is for alpha which controls transparency of the
             color. Therefore, to make a completely transparent
             color (invisible), use a value of 0 for Alpha. -->
        <Color A="255" R="0" G="0" B="255" />
     </SolidColorBrush.Color>
    </SolidColorBrush>
  </Rectangle.Fill>
</Rectangle>
```

```csharp
Rectangle myRgbRectangle = new Rectangle();
myRgbRectangle.Width = 50;
myRgbRectangle.Height = 50;
SolidColorBrush mySolidColorBrush = new SolidColorBrush();

// Describes the brush's color using RGB values. 
// Each value has a range of 0-255.
mySolidColorBrush.Color = Color.FromArgb(255, 0, 0, 255);
myRgbRectangle.Fill = mySolidColorBrush;           
```

有关描述颜色的其他方法，请参阅[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.color)结构。

**相关主题**

有关详细信息[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)和其他示例，请参阅[使用纯色和渐变概述进行绘制](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-solid-colors-and-gradients-overview)概述。

此代码示例是为提供一个更大示例的一部分[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)类。 有关完整示例，请参阅[画笔示例](https://go.microsoft.com/fwlink/?LinkID=159973)。

#### [Paint an Area with a System Brush](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-paint-an-area-with-a-system-brush)

[SystemColors](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemcolors)类提供了访问系统画笔和颜色，如[ControlBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemcolors.controlbrush)， [ControlBrushKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemcolors.controlbrushkey)，和[DesktopBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemcolors.desktopbrush)。 系统画笔是[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)对象，它使用指定的系统颜色绘制区域。 系统画笔总是生成纯色填充，它不能用于创建渐变。

可以将系统画笔用作静态资源，也可以用作动态资源。 如果希望在应用程序运行期间画笔自动进行更新（当用户更改系统画笔时），请使用动态资源；否则请使用静态资源。 SystemColors 类包含大量静态属性，这些属性严格遵循命名约定：

- *<SystemColor>* Brush

  获取对的静态引用[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)指定的系统颜色。

- *<SystemColor>* BrushKey

  获取到的动态引用[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)指定的系统颜色。

- *<SystemColor>* Color

  获取对的静态引用[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.color)指定的系统颜色的结构。

- *<SystemColor>* ColorKey

  获取到的动态引用[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.color)指定的系统颜色的结构。

系统颜色是[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.color)结构，它可用于配置画笔。 例如，可以创建通过设置使用系统颜色的渐变[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientstop.color)的属性[LinearGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush)对象的使用系统颜色的渐变停止点。 有关示例，请参阅[渐变中使用系统颜色](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-use-system-colors-in-a-gradient)。

##### 示例

以下示例使用动态系统画笔引用来设置按钮的背景。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  WindowTitle="SystemColors Example" Background="White">  
  <StackPanel Margin="20">
 
    <!-- Uses a dynamic resource to set the 
         background of a button. 
         If the desktop brush changes while this application
         is running, this button will be updated. -->
    <Button 
      Background="{DynamicResource {x:Static SystemColors.DesktopBrushKey}}" 
      Content="Hello, World!" />

  </StackPanel>
</Page>
```

下一个示例使用静态系统画笔引用来设置按钮的背景。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  WindowTitle="SystemColors Example" Background="White">  
  <StackPanel Margin="20">
 
    <!-- Uses a static brush to set the
         background of a button. 
         If the desktop brush changes while this application
         is running, this button will not be updated until
         the page is loaded again. -->
    <Button 
      Background="{x:Static SystemColors.DesktopBrush}" 
      Content="Hello, World!"  /> 

  </StackPanel>
</Page>
```

有关演示如何在渐变中使用系统颜色的示例，请参阅[渐变中使用系统颜色](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-use-system-colors-in-a-gradient)。

#### [Paint an Area with a Video](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-paint-an-area-with-a-video)

此示例演示如何使用媒体绘制区域。 使用媒体绘制区域的一种方法是使用[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)一起使用[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)。 使用[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)若要加载和播放媒体，并使用它来设置[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush.visual)属性的[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)。 然后，可以使用[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)要加载的介质使用绘制区域。

##### 示例

下面的示例使用[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)和一个[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)绘制[Foreground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.foreground)的[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)控件使用的视频。 此示例设置[IsMuted](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement.ismuted)的属性[MediaElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.mediaelement)到`true`，以便它不发出声音。

```csharp
MediaElement myMediaElement = new MediaElement();
myMediaElement.Source = new Uri("sampleMedia\\xbox.wmv", UriKind.Relative);
myMediaElement.IsMuted = true;

VisualBrush myVisualBrush = new VisualBrush();
myVisualBrush.Visual = myMediaElement;

TextBlock myTextBlock = new TextBlock();
myTextBlock.FontSize = 150;
myTextBlock.Text = "Some Text";
myTextBlock.FontWeight = FontWeights.Bold;

myTextBlock.Foreground = myVisualBrush;
```

```xaml
<TextBlock FontSize="100pt" Text="Some Text" FontWeight="Bold">
  <TextBlock.Foreground>
    <VisualBrush>
      <VisualBrush.Visual>
        <MediaElement Source="sampleMedia\xbox.wmv" IsMuted="True" />
      </VisualBrush.Visual>
    </VisualBrush>
  </TextBlock.Foreground>
</TextBlock>
```

##### 示例

因为[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)继承[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)类，它提供了几个平铺模式。 通过设置[TileMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.tilemode)的属性[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)到[Tile](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilemode#System_Windows_Media_TileMode_Tile)并设置其[Viewport](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewport)属性的值小于要绘制的区域，可以创建一个平铺的图案。

下面的示例等同于上一示例中，不同之处在于[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)来自视频将生成一种模式。

```csharp
MediaElement myMediaElement = new MediaElement();
myMediaElement.Source = new Uri("sampleMedia\\xbox.wmv", UriKind.Relative);
myMediaElement.IsMuted = true;

VisualBrush myVisualBrush = new VisualBrush();
myVisualBrush.Viewport = new Rect(0, 0, 0.5, 0.5);
myVisualBrush.TileMode = TileMode.Tile;
myVisualBrush.Visual = myMediaElement;

TextBlock myTextBlock = new TextBlock();
myTextBlock.FontSize = 150;
myTextBlock.Text = "Some Text";
myTextBlock.FontWeight = FontWeights.Bold;

myTextBlock.Foreground = myVisualBrush;
```

```xaml
<TextBlock FontSize="100pt" Text="Some Text" FontWeight="Bold">
  <TextBlock.Foreground>
    <VisualBrush Viewport="0,0,0.5,0.5" TileMode="Tile">
      <VisualBrush.Visual>
        
        <MediaElement Source="sampleMedia\xbox.wmv" IsMuted="True" /> 
      </VisualBrush.Visual>
    </VisualBrush>
  </TextBlock.Foreground>
</TextBlock>
```

了解如何将内容文件，例如媒体文件添加到您的应用程序，请参阅[WPF 应用程序资源、 内容和数据文件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/wpf-application-resource-content-and-data-files)。 当添加媒体文件时，必须将其添加，作为内容文件，而不是资源文件。

#### [Paint an Area with a Visual](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-paint-an-area-with-a-visual)

此示例演示如何使用[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)类，以使用绘制区域[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)。

在以下示例中，许多控件和一个面板，用作一个矩形的背景。

##### 示例

```xaml
<Rectangle Width="150" Height="150" Stroke="Black" Margin="5,0,5,0">
  <Rectangle.Fill>
    <VisualBrush>
      <VisualBrush.Visual>
        <StackPanel Background="White">
          <Rectangle Width="25" Height="25" Fill="Red" Margin="2" />
          <TextBlock FontSize="10pt" Margin="2">Hello, World!</TextBlock>
          <Button Margin="2">A Button</Button>
        </StackPanel>
      </VisualBrush.Visual>
    </VisualBrush>
  </Rectangle.Fill>
</Rectangle>
```

```csharp
VisualBrush myVisualBrush = new VisualBrush();

// Create the visual brush's contents.
StackPanel myStackPanel = new StackPanel();
myStackPanel.Background = Brushes.White;

Rectangle redRectangle = new Rectangle();
redRectangle.Width = 25;
redRectangle.Height =25; 
redRectangle.Fill = Brushes.Red;
redRectangle.Margin = new Thickness(2);
myStackPanel.Children.Add(redRectangle);

TextBlock someText = new TextBlock();
FontSizeConverter myFontSizeConverter = new FontSizeConverter();
someText.FontSize = (double)myFontSizeConverter.ConvertFrom("10pt");
someText.Text = "Hello, World!";
someText.Margin = new Thickness(2);
myStackPanel.Children.Add(someText);

Button aButton = new Button();
aButton.Content = "A Button";
aButton.Margin = new Thickness(2);
myStackPanel.Children.Add(aButton);

// Use myStackPanel as myVisualBrush's content.
myVisualBrush.Visual = myStackPanel;

// Create a rectangle to paint.
Rectangle myRectangle = new Rectangle();
myRectangle.Width = 150;
myRectangle.Height = 150;
myRectangle.Stroke = Brushes.Black;
myRectangle.Margin = new Thickness(5,0,5,0);

// Use myVisualBrush to paint myRectangle.
myRectangle.Fill = myVisualBrush;
```

有关详细信息[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)和其他示例，请参阅[使用图像、 绘图和视觉对象进行绘制](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-images-drawings-and-visuals)概述。

此代码示例是为提供一个更大示例的一部分[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)类。 有关完整示例，请参阅[VisualBrush 示例](https://go.microsoft.com/fwlink/?LinkID=160049)。

#### [Preserve the Aspect Ratio of an Image Used as a Background](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-preserve-the-aspect-ratio-of-an-image-used-as-a-background)

此示例演示如何使用[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.stretch)属性的[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)为了保持图像的纵横比。

默认情况下，当您使用[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)绘制区域，其内容将进行拉伸以完全填充输出区域。 当输出区域和图像的纵横比不同时，图像就会因拉伸而失真。

若要使[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)保持其图像的纵横比，设置[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.stretch)属性设置为[Uniform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_Uniform)或[UniformToFill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_UniformToFill)。

##### 示例

下面的示例使用两个[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)对象来绘制两个矩形。 每个矩形都为 300x150 像素，每个矩形都包含一个像素为 300x300 的图像。 [Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.stretch)的第一个画笔属性设置为[Uniform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_Uniform)，并[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.stretch)第二个画笔的属性设置为[UniformToFill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_UniformToFill)。

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media.Imaging;
using System.Windows.Media;
using System.Windows.Shapes;

namespace Microsoft.Samples.Graphics.UsingImageBrush
{
    /// <summary>
    /// Demonstrates different ImageBrush Stretch settings.
    /// </summary>
    public class StretchModes : Page
    {
        public StretchModes()
        {

            // Create an ImageBrush with its Stretch
            // property set to Uniform. The image it
            // contains will be expanded as much as possible
            // to fill the output area while still
            // preserving its aspect ratio.
            ImageBrush uniformBrush = new ImageBrush();
            uniformBrush.ImageSource = 
                new BitmapImage(new Uri("sampleImages\\square.jpg", UriKind.Relative));
            uniformBrush.Stretch = Stretch.Uniform;

            // Freeze the brush (make it unmodifiable) for performance benefits.
            uniformBrush.Freeze();

            // Create a rectangle and paint it with the ImageBrush.
            Rectangle rectangle1 = new Rectangle();
            rectangle1.Width = 300;
            rectangle1.Height = 150;
            rectangle1.Stroke = Brushes.MediumBlue;
            rectangle1.StrokeThickness = 1.0;
            rectangle1.Fill = uniformBrush;

            // Create an ImageBrush with its Stretch
            // property set to UniformToFill. The image it
            // contains will be expanded to completely fill
            // the rectangle, but its aspect ratio is preserved.
            ImageBrush uniformToFillBrush = new ImageBrush();
            uniformToFillBrush.ImageSource =
                new BitmapImage(new Uri("sampleImages\\square.jpg", UriKind.Relative));
            uniformToFillBrush.Stretch = Stretch.UniformToFill;

            // Freeze the brush (make it unmodifiable) for performance benefits.
            uniformToFillBrush.Freeze();

            // Create a rectangle and paint it with the ImageBrush.
            Rectangle rectangle2 = new Rectangle();
            rectangle2.Width = 300;
            rectangle2.Height = 150;
            rectangle2.Stroke = Brushes.MediumBlue;
            rectangle2.StrokeThickness = 1.0;
            rectangle2.Margin = new Thickness(0, 10, 0, 0);
            rectangle2.Fill = uniformToFillBrush;

            StackPanel mainPanel = new StackPanel();
            mainPanel.Children.Add(rectangle1);
            mainPanel.Children.Add(rectangle2);

            Content = mainPanel;
            Background = Brushes.White;
            Margin = new Thickness(20);
            Title = "ImageBrush Stretch Modes";


        }
    }
}
```

下图显示了具有第一个画笔的输出[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.stretch)设置的[Uniform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_Uniform)。

![ImageBrush with Uniform stretching](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-imagebrushuniformstretch.jpg)

下图显示具有第二个画笔的输出[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.stretch)设置的[UniformToFill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_UniformToFill)。

![具有 UniformToFill 拉伸的 ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-imagebrushuniformtofillstretch.jpg)

请注意，[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.stretch)属性适用于其他的行为相同[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)对象，也就是说，对于[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)和[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)。 有关详细信息[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)和其他[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)对象，请参阅[使用图像、 绘图和视觉对象进行绘制](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-images-drawings-and-visuals)。

另请注意，尽管[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.stretch)属性将显示以指定如何[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)内容将进行拉伸以适合其输出区域，实际上指定了[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)内容拉伸以填充其基本磁贴。 有关详细信息，请参阅 [TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)。

此代码示例是为提供一个更大示例的一部分[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)类。 有关完整示例，请参阅[ImageBrush 示例](https://go.microsoft.com/fwlink/?LinkID=160005)。

#### [Set the Horizontal and Vertical Alignment of a TileBrush](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-set-the-horizontal-and-vertical-alignment-of-a-tilebrush)

本示例演示如何控制平铺内容的水平对齐方式和垂直对齐方式。 若要控制的水平和垂直对齐方式[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)，使用其[AlignmentX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.alignmentx)和[AlignmentY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.alignmenty)属性。

[AlignmentX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.alignmentx)并[AlignmentY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.alignmenty)的属性[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)使用以下条件之一为 true:

- [Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.stretch)属性是[Uniform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_Uniform)或[UniformToFill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_UniformToFill)并且[Viewbox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewbox)和[Viewport](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewport)的纵横比。
- [Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.stretch)属性是[None](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_None)并[Viewbox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewbox)和[Viewport](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewport)大小并不相同。

##### 示例

下面的示例的内容对齐[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)，这是一种类型的[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)，其磁贴的左上角。 为了对齐内容，该示例设置[AlignmentX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.alignmentx)的属性[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)到[Left](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.alignmentx#System_Windows_Media_AlignmentX_Left)并且[AlignmentY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.alignmenty)属性设置为[Top](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.alignmenty#System_Windows_Media_AlignmentY_Top)。 本示例生成以下输出。

![顶部的 TileBrush-左对齐方式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-tilebrushalignmentexampletopleft.png)
内容与左上角对齐的 TileBrush

```csharp
//
// Create a TileBrush and align its
// content to the top-left of its tile.
//
DrawingBrush topLeftAlignedTileBrush = new DrawingBrush();
topLeftAlignedTileBrush.AlignmentX = AlignmentX.Left;
topLeftAlignedTileBrush.AlignmentY = AlignmentY.Top;

// Set Stretch to None so that the brush's
// content doesn't automatically expand to
// fill the entire tile. 
topLeftAlignedTileBrush.Stretch = Stretch.None;

// Define the brush's content.
GeometryGroup ellipses = new GeometryGroup();
ellipses.Children.Add(new EllipseGeometry(new Point(50, 50), 20, 45));
ellipses.Children.Add(new EllipseGeometry(new Point(50, 50), 45, 20));
Pen drawingPen = new Pen(Brushes.Gray, 10);
GeometryDrawing ellipseDrawing = new GeometryDrawing(Brushes.Blue, drawingPen, ellipses);
topLeftAlignedTileBrush.Drawing = ellipseDrawing;

// Use the brush to paint a rectangle.
Rectangle rectangle1 = new Rectangle();
rectangle1.Width = 150;
rectangle1.Height = 150;
rectangle1.Stroke = Brushes.Red;
rectangle1.StrokeThickness = 2;
rectangle1.Margin = new Thickness(20);
rectangle1.Fill = topLeftAlignedTileBrush;
```

```xaml
<Rectangle
  Width="150" Height="150"
  Stroke="Red" StrokeThickness="2"
  Margin="20">
  <Rectangle.Fill>

    <!-- This brush's content is aligned to the top-left
         of its tile. -->
    <DrawingBrush  
      Stretch="None"
      AlignmentX="Left"
      AlignmentY="Top">
      <DrawingBrush.Drawing>
        <GeometryDrawing Brush="MediumBlue">
          <GeometryDrawing.Geometry>
            <GeometryGroup>
              <EllipseGeometry RadiusX="20" RadiusY="45" Center="50,50" />
              <EllipseGeometry RadiusX="45" RadiusY="20" Center="50,50" />
            </GeometryGroup>
          </GeometryDrawing.Geometry>
          <GeometryDrawing.Pen>
            <Pen Brush="Gray" Thickness="10" />
          </GeometryDrawing.Pen>
        </GeometryDrawing>
      </DrawingBrush.Drawing>
    </DrawingBrush>
  </Rectangle.Fill>
</Rectangle>
```

##### 示例

下一个示例的内容对齐[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)通过设置其磁贴右下角[AlignmentX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.alignmentx)属性设置为[Right](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.alignmentx#System_Windows_Media_AlignmentX_Right)并且[AlignmentY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.alignmenty)属性设置为[Bottom](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.alignmenty#System_Windows_Media_AlignmentY_Bottom)。 该示例生成以下输出。

![底部的 TileBrush-右对齐](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-tilebrushalignmentexamplebottomright.png)
内容与右下角对齐的 TileBrush

```csharp
//
// Create a TileBrush and align its
// content to the bottom-right of its tile.
//
DrawingBrush bottomRightAlignedTileBrush = new DrawingBrush();
bottomRightAlignedTileBrush.AlignmentX = AlignmentX.Right;
bottomRightAlignedTileBrush.AlignmentY = AlignmentY.Bottom;
bottomRightAlignedTileBrush.Stretch = Stretch.None;

// Define the brush's content.
bottomRightAlignedTileBrush.Drawing = ellipseDrawing;

// Use the brush to paint a rectangle.
Rectangle rectangle2 = new Rectangle();
rectangle2.Width = 150;
rectangle2.Height = 150;
rectangle2.Stroke = Brushes.Red;
rectangle2.StrokeThickness = 2;
rectangle2.Margin = new Thickness(20);
rectangle2.Fill = bottomRightAlignedTileBrush;
```

```xaml
<Rectangle
  Width="150" Height="150"
  Stroke="Red" StrokeThickness="2"
  Margin="20">
  <Rectangle.Fill>

    <!-- This brush's content is aligned to the bottom right
         of its tile. -->
    <DrawingBrush 
      Stretch="None"
      AlignmentX="Right"
      AlignmentY="Bottom">
      <DrawingBrush.Drawing>
        <GeometryDrawing Brush="MediumBlue">
          <GeometryDrawing.Geometry>
            <GeometryGroup>
              <EllipseGeometry RadiusX="20" RadiusY="45" Center="50,50" />
              <EllipseGeometry RadiusX="45" RadiusY="20" Center="50,50" />
            </GeometryGroup>
          </GeometryDrawing.Geometry>
          <GeometryDrawing.Pen>
            <Pen Brush="Gray" Thickness="10" />
          </GeometryDrawing.Pen>
        </GeometryDrawing>
      </DrawingBrush.Drawing>
    </DrawingBrush>
  </Rectangle.Fill>
</Rectangle>
```

##### 示例

下一个示例的内容对齐[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)通过设置其磁贴的左上角[AlignmentX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.alignmentx)属性设置为[Left](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.alignmentx#System_Windows_Media_AlignmentX_Left)并且[AlignmentY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.alignmenty)属性设置为[Top](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.alignmenty#System_Windows_Media_AlignmentY_Top)。 它还设置[Viewport](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewport)并[TileMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.tilemode)的[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)以生成平铺图案。 该示例生成以下输出。

![与顶端对齐的平铺的 TileBrush-左对齐方式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-tilebrushalignmentexampletoplefttiled.png)
内容与基本平铺图案的左上角对齐的平铺图案

上图突出显示了基本平铺图案，以便显示其内容的对齐方式。 请注意，[AlignmentX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.alignmentx)设置没有任何影响，因为内容的[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)完全水平填充基本图块。

```csharp
//
// Create a TileBrush that generates a 
// tiled pattern and align its
// content to the top-left of its tile.
//
DrawingBrush tiledTopLeftAlignedTileBrush = new DrawingBrush();
tiledTopLeftAlignedTileBrush.AlignmentX = AlignmentX.Left;
tiledTopLeftAlignedTileBrush.AlignmentY = AlignmentY.Top;
tiledTopLeftAlignedTileBrush.Stretch = Stretch.Uniform;

// Set the brush's Viewport and TileMode to produce a 
// tiled pattern.
tiledTopLeftAlignedTileBrush.Viewport = new Rect(0, 0, 0.25, 0.5);
tiledTopLeftAlignedTileBrush.TileMode = TileMode.Tile;

// Define the brush's content.
tiledTopLeftAlignedTileBrush.Drawing = ellipseDrawing;

// Use the brush to paint a rectangle.
Rectangle rectangle3 = new Rectangle();
rectangle3.Width = 150;
rectangle3.Height = 150;
rectangle3.Stroke = Brushes.Black;
rectangle3.StrokeThickness = 2;
rectangle3.Margin = new Thickness(20);
rectangle3.Fill = tiledTopLeftAlignedTileBrush;
```

```xaml
<Rectangle
 Width="150" Height="150"
 Stroke="Black" StrokeThickness="2"
 Margin="20">
  <Rectangle.Fill>

    <!-- This brush's content is aligned to the top left
         of its tile.  -->
    <DrawingBrush 
      Stretch="Uniform"
      Viewport="0,0,0.25,0.5"
      TileMode="Tile" 
      AlignmentX="Left"
      AlignmentY="Top">
      <DrawingBrush.Drawing>
        <GeometryDrawing Brush="MediumBlue">
          <GeometryDrawing.Geometry>
            <GeometryGroup>
              <EllipseGeometry RadiusX="20" RadiusY="45" Center="50,50" />
              <EllipseGeometry RadiusX="45" RadiusY="20" Center="50,50" />
            </GeometryGroup>
          </GeometryDrawing.Geometry>
          <GeometryDrawing.Pen>
            <Pen Brush="Gray" Thickness="10" />
          </GeometryDrawing.Pen>
        </GeometryDrawing>
      </DrawingBrush.Drawing>
    </DrawingBrush>
  </Rectangle.Fill>
</Rectangle>
```

##### 示例

最后一个示例将对齐的平铺内容[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)到通过设置其基本磁贴右下角[AlignmentX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.alignmentx)属性设置为[Right](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.alignmentx#System_Windows_Media_AlignmentX_Right)并且[AlignmentY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.alignmenty)属性设置为[Bottom](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.alignmenty#System_Windows_Media_AlignmentY_Bottom)。 该示例生成以下输出。

![与底端平铺 TileBrush-右对齐](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-tilebrushalignmentexamplebottomrighttiled.png)
内容与基本平铺图案的右下角对齐的平铺图案

同样，[AlignmentX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.alignmentx)设置没有任何影响，因为内容的[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)完全水平填充基本图块。

```csharp
//
// Create a TileBrush and align its
// content to the bottom-right of its tile.
//
DrawingBrush bottomRightAlignedTileBrush = new DrawingBrush();
bottomRightAlignedTileBrush.AlignmentX = AlignmentX.Right;
bottomRightAlignedTileBrush.AlignmentY = AlignmentY.Bottom;
bottomRightAlignedTileBrush.Stretch = Stretch.None;

// Define the brush's content.
bottomRightAlignedTileBrush.Drawing = ellipseDrawing;

// Use the brush to paint a rectangle.
Rectangle rectangle2 = new Rectangle();
rectangle2.Width = 150;
rectangle2.Height = 150;
rectangle2.Stroke = Brushes.Red;
rectangle2.StrokeThickness = 2;
rectangle2.Margin = new Thickness(20);
rectangle2.Fill = bottomRightAlignedTileBrush;
```

```xaml
<Rectangle
  Width="150" Height="150"
  Stroke="Red" StrokeThickness="2"
  Margin="20">
  <Rectangle.Fill>

    <!-- This brush's content is aligned to the bottom right
         of its tile. -->
    <DrawingBrush 
      Stretch="None"
      AlignmentX="Right"
      AlignmentY="Bottom">
      <DrawingBrush.Drawing>
        <GeometryDrawing Brush="MediumBlue">
          <GeometryDrawing.Geometry>
            <GeometryGroup>
              <EllipseGeometry RadiusX="20" RadiusY="45" Center="50,50" />
              <EllipseGeometry RadiusX="45" RadiusY="20" Center="50,50" />
            </GeometryGroup>
          </GeometryDrawing.Geometry>
          <GeometryDrawing.Pen>
            <Pen Brush="Gray" Thickness="10" />
          </GeometryDrawing.Pen>
        </GeometryDrawing>
      </DrawingBrush.Drawing>
    </DrawingBrush>
  </Rectangle.Fill>
</Rectangle>
```

这些示例使用[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)对象来演示如何[AlignmentX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.alignmentx)和[AlignmentY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.alignmenty)使用属性。 这些属性具有相同行为对于所有平铺画笔： [DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)， [ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)，和[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)。 有关平铺画笔的详细信息，请参阅[使用图像、绘图和视觉对象进行绘制](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-images-drawings-and-visuals)。

#### [Set the Tile Size for a TileBrush](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-set-the-tile-size-for-a-tilebrush)

此示例演示如何设置平铺大小[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)。 默认情况下，[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)生成完全填充要绘制区域的单个磁贴。 可以通过设置替代此行为[Viewport](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewport)和[ViewportUnits](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewportunits)属性。

[Viewport](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewport)属性指定的磁贴大小[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)。 默认情况下的值[Viewport](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewport)属性是相对于所绘制的区域的大小。 若要使[Viewport](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewport)属性指定绝对平铺大小，设置[ViewportUnits](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewportunits)属性设置为[Absolute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brushmappingmode#System_Windows_Media_BrushMappingMode_Absolute)。

##### 示例

下面的示例使用[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)，一种类型的[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)、 绘制一个矩形与磁贴。 此示例将每个平铺设置为在长宽方向上分别占输出区域（矩形）的 50%。 因此，将用四个投影图像绘制该矩形。

下图显示该示例生成的输出。

![使用图像画笔平铺的示例](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/0.png)

```csharp
//
// Create an ImageBrush and set the size of each
// tile to 50% by 50% of the area being painted. 
// 
ImageBrush relativeTileSizeImageBrush = new ImageBrush();
relativeTileSizeImageBrush.ImageSource =
    new BitmapImage(new Uri(@"sampleImages\cherries_larger.jpg", UriKind.Relative));
relativeTileSizeImageBrush.TileMode = TileMode.Tile;

// Specify the size of the base tile. 
// By default, the size of the Viewport is
// relative to the area being painted,
// so a value of 0.5 indicates 50% of the output
// area.
relativeTileSizeImageBrush.Viewport = new Rect(0, 0, 0.5, 0.5);

// Create a rectangle and paint it with the ImageBrush.
Rectangle relativeTileSizeExampleRectangle = new Rectangle();
relativeTileSizeExampleRectangle.Width = 200;
relativeTileSizeExampleRectangle.Height = 150;
relativeTileSizeExampleRectangle.Stroke = Brushes.LimeGreen;
relativeTileSizeExampleRectangle.StrokeThickness = 1;
relativeTileSizeExampleRectangle.Fill = relativeTileSizeImageBrush;
```

下一个示例创建[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)，设置其[Viewport](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewport)到`0,0,25,25`并将其[ViewportUnits](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewportunits)到[Absolute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brushmappingmode#System_Windows_Media_BrushMappingMode_Absolute)，并使用它来绘制另一个矩形。 因此，画笔会生成一个宽度为 25 像素、高度为 25 像素的平铺。

下图显示该示例生成的输出。

![视区为 0,0,0.25,0.25 的平铺 TileBrush](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/25x25viewport.png)

```csharp
//
// Create an ImageBrush and set the size of each
// tile to 25 by 25 pixels. 
// 
ImageBrush absoluteTileSizeImageBrush = new ImageBrush();
absoluteTileSizeImageBrush.ImageSource =
     new BitmapImage(new Uri(@"sampleImages\cherries_larger.jpg", UriKind.Relative));
absoluteTileSizeImageBrush.TileMode = TileMode.Tile;

// Specify that the Viewport is to be interpreted as
// an absolute value. 
absoluteTileSizeImageBrush.ViewportUnits = BrushMappingMode.Absolute;

// Set the size of the base tile. Had we left ViewportUnits set
// to RelativeToBoundingBox (the default value), 
// each tile would be 25 times the size of the area being
// painted. Because ViewportUnits is set to Absolute,
// the following line creates tiles that are 25 by 25 pixels.
absoluteTileSizeImageBrush.Viewport = new Rect(0, 0, 25, 25);

// Create a rectangle and paint it with the ImageBrush.
Rectangle absoluteTileSizeExampleRectangle = new Rectangle();
absoluteTileSizeExampleRectangle.Width = 200;
absoluteTileSizeExampleRectangle.Height = 150;
absoluteTileSizeExampleRectangle.Stroke = Brushes.LimeGreen;
absoluteTileSizeExampleRectangle.StrokeThickness = 1;
absoluteTileSizeExampleRectangle.Fill = absoluteTileSizeImageBrush;
```

以上几个示例摘自一个更大的示例。 有关完整示例，请参阅[ImageBrush 示例](https://go.microsoft.com/fwlink/?LinkID=160005)。

虽然此示例使用[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)类，[Viewport](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewport)和[ViewportUnits](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush.viewportunits)属性的行为方式相同其他[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)对象，即，对于[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)和[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)。 有关详细信息[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)和其他[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)对象，请参阅[使用图像、 绘图和视觉对象进行绘制](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-images-drawings-and-visuals)。

#### [Transform a Brush](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-transform-a-brush)

此示例演示如何转换[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)通过使用其两个转换属性对象：[RelativeTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.relativetransform)和[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.transform)。

下面的示例使用[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)旋转的内容[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)旋转 45 度。

如下图所示[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)而无需[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)，使用[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)应用于[RelativeTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.relativetransform)属性，并使用[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)应用于[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.transform)属性。

![画笔 RelativeTransform 和 Transform 设置](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wcpsdk-graphicsmm-transformandrelativetransform.png)

##### 示例

第一个示例应用[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)到[RelativeTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.relativetransform)属性的[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)。 [CenterX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform.centerx)并[CenterY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform.centery)的属性[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)对象均设置为 0.5，这是此内容的中心点的相对坐标。 因此，[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)内容围绕其中心旋转。

```csharp
//
// Create an ImageBrush with a relative transform and
// use it to paint a rectangle.
//
ImageBrush relativeTransformImageBrush = new ImageBrush();
relativeTransformImageBrush.ImageSource =
    new BitmapImage(new Uri(@"sampleImages\pinkcherries.jpg", UriKind.Relative));

// Create a 45 rotate transform about the brush's center
// and apply it to the brush's RelativeTransform property.
RotateTransform aRotateTransform = new RotateTransform();
aRotateTransform.CenterX = 0.5; 
aRotateTransform.CenterY = 0.5;
aRotateTransform.Angle = 45;
relativeTransformImageBrush.RelativeTransform = aRotateTransform;

// Use the brush to paint a rectangle.
Rectangle relativeTransformImageBrushRectangle = new Rectangle();
relativeTransformImageBrushRectangle.Width = 175;
relativeTransformImageBrushRectangle.Height = 90;
relativeTransformImageBrushRectangle.Stroke = Brushes.Black;
relativeTransformImageBrushRectangle.Fill = relativeTransformImageBrush;
```

```xaml
<Rectangle Width="175" Height="90" Stroke="Black">
  <Rectangle.Fill>
    <ImageBrush ImageSource="sampleImages\pinkcherries.jpg">
      <ImageBrush.RelativeTransform>
        <RotateTransform CenterX="0.5" CenterY="0.5" Angle="45" />
      </ImageBrush.RelativeTransform>
    </ImageBrush>
  </Rectangle.Fill>
</Rectangle>
```

第二个示例也适用[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)到[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush); 但是，此示例使用[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.transform)属性，而不是[RelativeTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.relativetransform)属性。

若要旋转画笔围绕其中心，该示例设置[CenterX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform.centerx)并[CenterY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform.centery)的属性[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)为绝对坐标的对象。 因为画笔绘制了一个 175x90 像素的矩形，所以该矩形的中心点为 (87.5, 45)。

```csharp
//
// Create an ImageBrush with a transform and
// use it to paint a rectangle.
//
ImageBrush transformImageBrush = new ImageBrush();
transformImageBrush.ImageSource =
    new BitmapImage(new Uri(@"sampleImages\pinkcherries.jpg", UriKind.Relative));

// Create a 45 rotate transform about the brush's center
// and apply it to the brush's Transform property.
RotateTransform anotherRotateTransform = new RotateTransform();
anotherRotateTransform.CenterX = 87.5;
anotherRotateTransform.CenterY = 45;
anotherRotateTransform.Angle = 45;
transformImageBrush.Transform = anotherRotateTransform;

// Use the brush to paint a rectangle.
Rectangle transformImageBrushRectangle = new Rectangle();
transformImageBrushRectangle.Width = 175;
transformImageBrushRectangle.Height = 90;
transformImageBrushRectangle.Stroke = Brushes.Black;
transformImageBrushRectangle.Fill = transformImageBrush;
```

```xaml
<Rectangle Width="175" Height="90" Stroke="Black">
  <Rectangle.Fill>
    <ImageBrush ImageSource="sampleImages\pinkcherries.jpg">
      <ImageBrush.Transform>
        <RotateTransform CenterX="87.5" CenterY="45" Angle="45" />
      </ImageBrush.Transform>
    </ImageBrush>
  </Rectangle.Fill>
</Rectangle>
```

有关如何将说明[RelativeTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.relativetransform)并[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.transform)属性起作用，请参阅[画笔转换概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/brush-transformation-overview)。

有关完整示例，请参阅[画笔示例](https://go.microsoft.com/fwlink/?LinkID=159973)。 有关画笔的详细信息，请参阅[使用纯色和渐变进行绘制概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-solid-colors-and-gradients-overview)。

#### [Use System Colors in a Gradient](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-use-system-colors-in-a-gradient)

若要在渐变中使用系统颜色，请使用 *<SystemColor >* 颜色和 *<SystemColor >* ColorKey 静态属性[SystemColors](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemcolors)类来获取对颜色，引用其中 *<SystemColor >* 是所需的系统颜色的名称。 使用 *<SystemColor >* ColorKey 属性时想要创建的动态引用，随着系统主题变化而自动更新。 否则，请使用 *<SystemColor >* Color 属性。

##### 示例

以下示例使用动态系统颜色资源创建渐变。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  WindowTitle="Dynamic System Colors Example" Background="White">  
  <StackPanel Margin="20">
 
    <!-- Uses dynamic references to system colors to set
         the colors of gradient stops. 
         If these system colors change while this application
         is running, the gradient will be updated
         automatically.  -->
    <Button Content="Hello, World!">
      <Button.Background>
        <LinearGradientBrush>
          <LinearGradientBrush.GradientStops>
            <GradientStop Offset="0.0" 
              Color="{DynamicResource {x:Static SystemColors.DesktopColorKey}}" />
            <GradientStop Offset="1.0" 
              Color="{DynamicResource {x:Static SystemColors.ControlLightLightColorKey}}" />
          </LinearGradientBrush.GradientStops>
        </LinearGradientBrush>
      </Button.Background>
    </Button>

  </StackPanel>
</Page>
```

下一个示例使用静态系统颜色资源创建渐变。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  WindowTitle="Static System Colors Example" Background="White">  
  <StackPanel Margin="20">
 
    <!-- Uses static references to system colors to set
         the colors of gradient stops. 
         If these system colors change while this application
         is running, this button will not be updated until
         the page is loaded again. -->
    <Button Content="Hello, World!">
      <Button.Background>
        <LinearGradientBrush>
          <LinearGradientBrush.GradientStops>
            <GradientStop Offset="0.0" 
              Color="{x:Static SystemColors.DesktopColor}" />
            <GradientStop Offset="1.0" 
              Color="{x:Static SystemColors.ControlLightLightColor}" />
          </LinearGradientBrush.GradientStops>
        </LinearGradientBrush>
      </Button.Background>
    </Button>

  </StackPanel>
</Page>
```
