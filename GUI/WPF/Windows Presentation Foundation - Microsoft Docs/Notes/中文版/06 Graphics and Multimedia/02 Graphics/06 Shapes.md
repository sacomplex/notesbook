# [Shapes](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/shapes)

Windows Presentation Foundation (WPF) 绘制基本形状使用提供支持[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)类。 Shape 对象派生自[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)这种情况下，参与布局系统并可以只需使用绘制可扩展应用程序标记语言 (XAML)。

## 本节内容

[WPF 中的形状和基本绘图概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/shapes-and-basic-drawing-in-wpf-overview)
[帮助主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/shapes-how-to-topics)

## [Shapes and Basic Drawing in WPF Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/shapes-and-basic-drawing-in-wpf-overview)

本主题概述了如何绘制与[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)对象。 一个[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)是一种[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)，使您可以在屏幕上绘制一个形状。 由于它们是 UI 元素[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)对象可以用在[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)元素和多数控件。

Windows Presentation Foundation (WPF) 为图形和绘制服务提供多层访问。 在顶层，[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)对象是易于使用和提供许多有用的功能，例如布局和参与Windows Presentation Foundation (WPF)事件系统。

### 形状对象

WPF 提供了随时可用的大量[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)对象。 所有形状对象都继承自[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)类。 可用形状对象包括[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)， [Line](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.line)，[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)， [Polygon](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.polygon)， [Polyline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.polyline)，并[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)。 [Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape) 对象共享以下通用属性。

- [Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.stroke)：介绍了如何绘制形状的轮廓。
- [StrokeThickness](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.strokethickness)：描述形状的轮廓的粗细。
- [Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)：介绍了如何绘制形状的内部。
- 用于指定坐标和顶点的数据属性，以与设备无关的像素来度量。

由于它们源自[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)，形状对象可以用在面板和多数控件。 [Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)面板是特别适合用于创建复杂的图形，因为它支持绝对定位子对象。

[Line](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.line)类使您能够在两点之间绘制线条。 以下示例演示了指定线坐标和笔划属性的几种方法。

```xaml
<Canvas Height="300" Width="300">

  <!-- Draws a diagonal line from (10,10) to (50,50). -->
  <Line
    X1="10" Y1="10"
    X2="50" Y2="50"
    Stroke="Black"
    StrokeThickness="4" />

  <!-- Draws a diagonal line from (10,10) to (50,50)
       and moves it 100 pixels to the right. -->
  <Line
    X1="10" Y1="10"
    X2="50" Y2="50"
    StrokeThickness="4"
    Canvas.Left="100">
    <Line.Stroke>
      <RadialGradientBrush GradientOrigin="0.5,0.5" Center="0.5,0.5" RadiusX="0.5" RadiusY="0.5">
        <RadialGradientBrush.GradientStops>
          <GradientStop Color="Red" Offset="0" />
          <GradientStop Color="Blue" Offset="0.25" />
        </RadialGradientBrush.GradientStops>
      </RadialGradientBrush>
    </Line.Stroke>
  </Line>

  <!-- Draws a horizontal line from (10,60) to (150,60). -->
  <Line
     X1="10" Y1="60"
     X2="150" Y2="60"
     Stroke="Black"
     StrokeThickness="4"/>

</Canvas>
```

C#复制

```csharp
// Add a Line Element
myLine = new Line();
myLine.Stroke = System.Windows.Media.Brushes.LightSteelBlue;
myLine.X1 = 1;
myLine.X2 = 50;
myLine.Y1 = 1;
myLine.Y2 = 50;
myLine.HorizontalAlignment = HorizontalAlignment.Left;
myLine.VerticalAlignment = VerticalAlignment.Center;
myLine.StrokeThickness = 2;
myGrid.Children.Add(myLine);
```

下图显示了呈现[Line](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.line)。

![Line illustration](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/shape-ovw-line2.gif)

尽管[Line](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.line)确实提供了类[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)属性，将其设置没有任何作用，因为[Line](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.line)没有区域。

另一个常见形状是[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)。 创建[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)通过定义的形状[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)和[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)属性。 若要绘制一个圆圈，指定[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)其[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)和[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)值是否相等。

XAML复制

```xaml
<Ellipse
Fill="Yellow"
Height="100"
Width="200"
StrokeThickness="2"
Stroke="Black"/>
```

C#复制

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Shapes;

namespace SDKSample
{
    public partial class SetBackgroundColorOfShapeExample : Page
    {
        public SetBackgroundColorOfShapeExample()
        {
            // Create a StackPanel to contain the shape.
            StackPanel myStackPanel = new StackPanel();

            // Create a red Ellipse.
            Ellipse myEllipse = new Ellipse();

            // Create a SolidColorBrush with a red color to fill the 
            // Ellipse with.
            SolidColorBrush mySolidColorBrush = new SolidColorBrush();

            // Describes the brush's color using RGB values. 
            // Each value has a range of 0-255.
            mySolidColorBrush.Color = Color.FromArgb(255, 255, 255, 0);
            myEllipse.Fill = mySolidColorBrush;
            myEllipse.StrokeThickness = 2;
            myEllipse.Stroke = Brushes.Black;

            // Set the width and height of the Ellipse.
            myEllipse.Width = 200;
            myEllipse.Height = 100;

            // Add the Ellipse to the StackPanel.
            myStackPanel.Children.Add(myEllipse);

            this.Content = myStackPanel;
        }

    }
}
```

下图显示了示例的呈现[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)。

![Ellipse illustration](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/shape-ovw-ellipse2.png)



### 使用路径和几何图形

[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)类可以绘制曲线和复杂的形状。 这些曲线和形状使用描述[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)对象。 若要使用[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)，创建[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)并使用它来设置[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)对象的[Data](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path.data)属性。

有各种[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)对象可供选择。 [LineGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.linegeometry)， [RectangleGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rectanglegeometry)，和[EllipseGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.ellipsegeometry)类描述了相对简单的形状。 若要创建更复杂的形状或创建曲线，使用[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)。

#### PathGeometry and PathSegments

[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry) 对象由一个或多个组成[PathFigure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathfigure)对象; 每个[PathFigure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathfigure)表示不同"图"或形状。 每个[PathFigure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathfigure)本身包含一个或多个[PathSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathsegment)对象，每个资源表示图或形状的一个连接的部分。 段类型包括以下类型： [LineSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.linesegment)， [BezierSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.beziersegment)，和[ArcSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.arcsegment)。

在以下示例中，[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)用于绘制二次贝塞尔曲线。

```xaml
<Path Stroke="Black" StrokeThickness="1">
  <Path.Data>
    <PathGeometry>
      <PathGeometry.Figures>
        <PathFigureCollection>
          <PathFigure StartPoint="10,100">
            <PathFigure.Segments>
              <PathSegmentCollection>
                <QuadraticBezierSegment Point1="200,200" Point2="300,100" />
              </PathSegmentCollection>
            </PathFigure.Segments>
          </PathFigure>
        </PathFigureCollection>
      </PathGeometry.Figures>
    </PathGeometry>
  </Path.Data>
</Path>
```

下图显示了呈现的形状。

![Path illustration](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/shape-ovw-path2.gif)

有关详细信息[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)和其他[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)类，请参见[几何概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/geometry-overview)。



### XAML 缩写语法

在中可扩展应用程序标记语言 (XAML)，还可以使用特殊的缩写的语法来描述[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)。 以下示例中，使用了缩写语法绘制复杂的形状。

XAML复制

```xaml
      <Path Stroke="DarkGoldenRod" StrokeThickness="3"   
Data="M 100,200 C 100,25 400,350 400,175 H 280" />  
```

下图显示了呈现[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)。

![Path illustration](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/shape-ovw-path.png)

[Data](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path.data)属性字符串以"moveto"命令，用 M 表示，这建立路径的起始点的坐标系统中[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)。 [Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path) 数据参数是区分大小写。 大写字母 M 指示新的当前点的绝对位置。 小写字母 m 指示相对坐标。 第一段是一条三次贝塞尔曲线，该曲线以 (100,200) 开始，至 (400,175) 结束，使用 (100,25) 和 (400,350) 这两个控制点绘制。 此段中的 C 命令指示[Data](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path.data)属性字符串。 同样，大写的 C 指示绝对路径；小写的 c 指示相对路径。

第二段以绝对水平“lineto”命令 H 开头，它指定绘制一条从前面的子路径的终点 (400,175) 到新终点 (280,175) 的直线。 它是一个水平"lineto"命令，因为指定的值是*x*-协调。

有关完整的路径语法，请参阅[Data](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path.data)引用和[使用 PathGeometry 创建形状](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-shape-by-using-a-pathgeometry)。

### 绘制形状

[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush) 对象用于绘制的形状[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.stroke)和[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)。 在下面的示例、 笔划和填充[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)指定。 注意画笔属性的有效输入可以是关键字或十六进制颜色值。 有关可用颜色关键字的详细信息，请参阅的属性[Colors](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.colors)类中[System.Windows.Media](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media)命名空间。

```xaml
<Canvas Background="LightGray">   
   <Ellipse  
      Canvas.Top="50"  
      Canvas.Left="50"  
      Fill="#FFFFFF00"  
      Height="75"  
      Width="75"  
      StrokeThickness="5"  
      Stroke="#FF0000FF"/>  
</Canvas>  
```

下图显示了呈现[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)。

![椭圆](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/shape-ovw-ellipsefill.png)

或者，可以使用属性元素语法显式创建[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)对象绘制形状用纯色。

XAML复制

```xaml
<!-- This polygon shape uses pre-defined color values for its Stroke and  
     Fill properties.   
     The SolidColorBrush's Opacity property affects the fill color in   
     this case by making it slightly transparent (opacity of 0.4) so   
     that it blends with any underlying color. -->  
  
<Polygon  
    Points="300,200 400,125 400,275 300,200"  
    Stroke="Purple"   
    StrokeThickness="2">  
    <Polygon.Fill>  
       <SolidColorBrush Color="Blue" Opacity="0.4"/>  
    </Polygon.Fill>  
</Polygon>  
```

下图显示了呈现的形状。

![SolidColorBrush illustration](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/shape-ovw-solidcolorbrush.png)

还可以使用渐变、图像、模式等绘制形状的笔划或填充。 有关详细信息，请参阅[使用纯色和渐变概述进行绘制](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-solid-colors-and-gradients-overview)。

### 可拉伸的形状

[Line](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.line)， [Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)， [Polygon](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.polygon)， [Polyline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.polyline)，并[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)类都具有[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.stretch)属性。 此属性确定如何[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)对象的内容 （要绘制的形状） 拉伸以填充[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)对象的布局空间。 一个[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)对象的布局空间是空间量[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)分配由布局系统，是由于显式[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)并[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)设置或由于其[HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.horizontalalignment)和[VerticalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.verticalalignment)设置。 在 Windows Presentation Foundation 中的布局的其他信息，请参阅[布局](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/layout)概述。

Stretch 属性采用下列值之一：

- [None](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_None)：[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)对象的内容未拉伸。
- [Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_Fill)：[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)对象的内容被拉伸以填充布局空间。 不保留纵横比。
- [Uniform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_Uniform)：[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)对象的内容将被拉伸以尽可能以填充布局空间，同时保留原始纵横比。
- [UniformToFill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_UniformToFill)：[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)对象的内容被拉伸以完全填充布局空间，同时保留原始纵横比。

请注意，当[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)对象的内容将被拉伸，[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)在拉伸后绘制对象的轮廓。

在以下示例中，[Polygon](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.polygon)用于绘制从 (0，0) 到 (0，1) 很小的三角形到 (1，1)。 [Polygon](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.polygon)对象的[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)和[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)设置为 100，并且其拉伸属性设置为 Fill。 因此，[Polygon](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.polygon)对象的内容 （三角形） 被拉伸以填充较大的空间。

XAML复制

```xaml
<Polygon  
  Points="0,0 0,1 1,1"  
  Fill="Blue"  
  Width="100"  
  Height="100"  
  Stretch="Fill"  
  Stroke="Black"  
  StrokeThickness="2" />  
```

C#复制

```csharp
PointCollection myPointCollection = new PointCollection();  
myPointCollection.Add(new Point(0,0));  
myPointCollection.Add(new Point(0,1));  
myPointCollection.Add(new Point(1,1));  
  
Polygon myPolygon = new Polygon();  
myPolygon.Points = myPointCollection;  
myPolygon.Fill = Brushes.Blue;  
myPolygon.Width = 100;  
myPolygon.Height = 100;  
myPolygon.Stretch = Stretch.Fill;  
myPolygon.Stroke = Brushes.Black;  
myPolygon.StrokeThickness = 2;  
```

### 转换形状

[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transform)类提供了转换形状在二维平面中的方法。 不同类型的转换包括旋转 ([RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform))，小数位数 ([ScaleTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform))、 倾斜 ([SkewTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.skewtransform))，和转换 ([TranslateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform))。

应用于形状的常见转换就是旋转。 若要旋转形状，创建[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)并指定其[Angle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform.angle)。 [Angle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform.angle)的 45 将元素旋转 45 度顺时针旋转; 90 的角度将元素旋转 90 度顺时针旋转; 依此类推。 设置[CenterX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform.centerx)和[CenterY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform.centery)属性，如果你想要控制元素旋转所围绕的点。 这些属性值在被转换的元素的坐标空间中表示。 [CenterX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform.centerx) 和[CenterY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform.centery)默认值为零。 最后，将应用[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)到元素。 如果不希望转换影响布局，设置形状的[RenderTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransform)属性。

在以下示例中，[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)用于旋转形状的左上角 (0，0) 形状 45 度。

```xaml
<!-- Rotates the Polyline 45 degrees about the point (0,0). -->
<Polyline Points="25,25 0,50 25,75 50,50 25,25 25,0" 
  Stroke="Blue" StrokeThickness="10"
  Canvas.Left="75" Canvas.Top="50">
  <Polyline.RenderTransform>
    <RotateTransform CenterX="0" CenterY="0" Angle="45" />
  </Polyline.RenderTransform>
</Polyline>
```

在以下示例中，另一个形状也旋转了 45 度，但这次它围绕点 (25,50) 旋转。

```xaml
<!-- Rotates the Polyline 45 degrees about its center. -->
<Polyline 
  Points="25,25 0,50 25,75 50,50 25,25 25,0" 
  Stroke="Blue" StrokeThickness="10"
  Canvas.Left="75" Canvas.Top="50"
  RenderTransformOrigin="0.5,0.5">
  <Polyline.RenderTransform>
    <RotateTransform Angle="45" />
  </Polyline.RenderTransform>
</Polyline>
```

下图显示了应用两次转换的结果。

![围绕不同中心点旋转 45 度](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wcpsdk-graphicsmm-rotatetransform45degrees.gif)

在前面的示例中，对每一个形状对象应用了一次转换。 若要将多个转换应用到一个形状 （或任何其他 UI 元素），使用[TransformGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transformgroup)。

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/shapes-how-to-topics)

在本部分中的主题演示如何使用[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)要在屏幕上绘制基本形状的对象。

### 本节内容

[使用多边形元素绘制闭合形状](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-draw-a-closed-shape-by-using-the-polygon-element)
[绘制椭圆形或圆形](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-draw-an-ellipse-or-a-circle)
[绘制直线](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-draw-a-line)
[使用 Polyline 元素绘制折线](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-draw-a-polyline-by-using-the-polyline-element)
[绘制矩形](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-draw-a-rectangle)
[修改直线或线段末端的线帽](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-modify-the-cap-at-the-end-of-a-line-or-segment)

### [Draw a Closed Shape by Using the Polygon Element](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-draw-a-closed-shape-by-using-the-polygon-element)

此示例演示如何使用来绘制闭合的形状[Polygon](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.polygon)元素。 若要绘制闭合的形状，创建[Polygon](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.polygon)元素，并使用其[Points](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.polygon.points)属性指定形状顶点。 自动绘制连接的第一个和最后一个点行。 最后，指定[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)、 [Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.stroke)，和 / 或。

#### 示例

在可扩展应用程序标记语言 (XAML)，点的有效语法是以逗号分隔的 x 和 y 坐标对的空格分隔列表。

```xaml
    <Canvas Height="300" Width="300">

      <!-- Draws a triangle with a blue interior. -->
      <Polygon Points="10,110 60,10 110,110" 
        Fill="Blue" />

      <!-- Draws a triangle with a blue interior and a black outline. 
           The Canvas.Top setting moves the Polygon down 150 pixels. -->
      <Polygon Points="10,110 60,10 110,110"
        Fill="Blue"
        Stroke="Black" StrokeThickness="4"
        Canvas.Top="150" />
  
      <!-- Draws another triangle with a blue interior.
           The Canvas.Left setting moves the Polygon 150 pixels to the right. -->
      <Polygon Points="10,110 110,110 110,10"
        Fill="Blue"
        Canvas.Left="150" />

      <!-- Draws a triangle with a black outline. 
           The Canvas.Left and Canvas.Top settings move 
           the Polygon down 150 pixels and 150 pixels to the right.-->
      <Polygon Points="10,110 110,110 110,10"
        Stroke="Black" StrokeThickness="4"
        Canvas.Left="150" Canvas.Top="150" />  


    </Canvas>
```

尽管该示例使用[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)来包含多边形，但是您可以使用多边形元素 （和所有其他形状元素） 以及任何[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)或[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)支持非文本内容。

此示例摘自一个更大的示例;有关完整示例，请参阅[形状元素示例](https://go.microsoft.com/fwlink/?LinkID=160037)。

### [Draw an Ellipse or a Circle](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-draw-an-ellipse-or-a-circle)

此示例演示如何使用来绘制椭圆和圆[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)元素。 若要绘制一个椭圆，创建[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)元素，并指定其[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)和[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)。 使用其[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)属性来指定[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)用来绘制椭圆形的内部。 使用其[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.stroke)属性来指定[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)用于绘制椭圆的边框。 [StrokeThickness](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.strokethickness)属性指定的椭圆边框粗细。

若要绘制一个圆圈，确保[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)并[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)的[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)相等的元素。

下面的示例绘制四[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)中的元素[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)。

#### 示例

```xaml
<Canvas Height="200" Width="200">

  <!-- Draws an oval with a blue interior. -->
  <Ellipse
    Width="100"
    Height="50"
    Fill="Blue"
    Canvas.Left="10"
    Canvas.Top="25" />

  <!-- Draws an oval with a blue interior and a black outline. -->
  <Ellipse
    Width="100"
    Height="50"
    Fill="Blue"
    Stroke="Black"
    StrokeThickness="4"
    Canvas.Left="10"
    Canvas.Top="100"/>

  <!-- Draws a circle with a blue interior. -->
  <Ellipse
    Width="50"
    Height="50"
    Fill="Blue"
    Canvas.Left="135"
    Canvas.Top="25"/>

  <!-- Draws a circle with a blue interior and a black outline. -->
  <Ellipse
    Width="50"
    Height="50"
    Stroke="Black"
    StrokeThickness="4"
    Canvas.Left="135"
    Canvas.Top="100" />

</Canvas>
```

虽然此示例使用[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)来包含省略号，但是您可以使用 ellipse 元素 （和所有其他形状元素） 以及任何[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)或[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)支持非文本内容。

此示例摘自一个更大的示例;有关完整示例，请参阅[形状元素示例](https://go.microsoft.com/fwlink/?LinkID=160037)。

### [Draw a Line](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-draw-a-line)

此示例演示如何通过使用绘制线条[Line](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.line)元素。

若要绘制一条线，请创建[Line](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.line)元素。 使用其[X1](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.line.x1)并[Y1](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.line.y1)属性来设置其开始点; 并使用其[X2](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.line.x2)和[Y2](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.line.y2)要设置其终结点的属性。最后，设置其[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.stroke)和[StrokeThickness](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.strokethickness)因为没有笔画行是不可见。

设置[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)行的元素具有不起作用，由于直线没有内部区域。

下面的示例绘制内的三个行[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)元素。

#### 示例

```xaml
<Canvas Height="300" Width="300">

  <!-- Draws a diagonal line from (10,10) to (50,50). -->
  <Line
    X1="10" Y1="10"
    X2="50" Y2="50"
    Stroke="Black"
    StrokeThickness="4" />

  <!-- Draws a diagonal line from (10,10) to (50,50)
       and moves it 100 pixels to the right. -->
  <Line
    X1="10" Y1="10"
    X2="50" Y2="50"
    StrokeThickness="4"
    Canvas.Left="100">
    <Line.Stroke>
      <RadialGradientBrush GradientOrigin="0.5,0.5" Center="0.5,0.5" RadiusX="0.5" RadiusY="0.5">
        <RadialGradientBrush.GradientStops>
          <GradientStop Color="Red" Offset="0" />
          <GradientStop Color="Blue" Offset="0.25" />
        </RadialGradientBrush.GradientStops>
      </RadialGradientBrush>
    </Line.Stroke>
  </Line>

  <!-- Draws a horizontal line from (10,60) to (150,60). -->
  <Line
     X1="10" Y1="60"
     X2="150" Y2="60"
     Stroke="Black"
     StrokeThickness="4"/>

</Canvas>
```

此示例摘自一个更大的示例;有关完整示例，请参阅[形状元素示例](https://go.microsoft.com/fwlink/?LinkID=160037)。

### [Draw a Polyline by Using the Polyline Element](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-draw-a-polyline-by-using-the-polyline-element)

此示例演示如何来绘制折线，这是通过使用一系列相互连接的直线，[Polyline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.polyline)元素。

若要绘制折线，创建[Polyline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.polyline)元素，并使用其[Points](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.polyline.points)属性指定形状顶点。 最后，使用[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.stroke)和[StrokeThickness](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.strokethickness)属性来描述线的折线轮廓，因为没有笔画行是不可见。

> 因为[Polyline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.polyline)元素不是闭合的形状，[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)属性不起作用，即使你有意关闭形状轮廓。 若要创建具有一个闭合的形状[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)，使用[Polygon](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.polygon)元素。

下面的示例绘制两个[Polyline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.polyline)内的元素[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)。

#### 示例

在可扩展应用程序标记语言 (XAML)，点的有效语法是以逗号分隔的 x 和 y 坐标对的空格分隔列表。

```xaml
<Canvas Height="400" Width="400">


  <Polyline
    Points="10,110 60,10 110,110"
    Stroke="Black"
    StrokeThickness="4" />

  <Polyline
    Points="10,110 110,110 110,10"
    Stroke="Black"
    StrokeThickness="4"
    Canvas.Left="150" />


  </Canvas>
```

虽然此示例使用[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)来包含折线，但是您可以使用 polyline 元素 （和所有其他形状元素） 以及任何[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)或[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)支持非文本内容。

此示例摘自一个更大的示例;有关完整示例，请参阅[形状元素示例](https://go.microsoft.com/fwlink/?LinkID=160037)。

### [Draw a Rectangle](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-draw-a-rectangle)

此示例演示如何使用来绘制一个矩形[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)元素。

若要绘制一个矩形，创建[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)元素，并指定其[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)和[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)。 若要绘制的矩形的内部，设置其[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)。 若要为矩形轮廓，使用其[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.stroke)和[StrokeThickness](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.strokethickness)属性。

若要绘制矩形圆角中，指定可选[RadiusX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle.radiusx)和[RadiusY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle.radiusy)属性。 [RadiusX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle.radiusx)和[RadiusY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle.radiusy)属性设置用于圆角化矩形角的椭圆的 x 轴和 y 轴半径。

在以下示例中，两个[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)元素绘制[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)。 第一个矩形具有[Blue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brushes.blue)内部。 第二个矩形具有[Blue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brushes.blue)内部，[Black](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brushes.black)大纲和圆的角。

#### 示例

```xaml
  <Canvas Width="120" Height="200" >

  <!-- Draws a 100 by 50 rectangle with a solid blue fill. -->
  <Rectangle
    Width="100"
    Height="50"
    Fill="Blue"
    Canvas.Left="10"
    Canvas.Top="25" />

  <!-- Draws a 100 by 50 rectangle with a solid blue fill,
       a black outline, and rounded corners. -->
  <Rectangle
    Width="100"
    Height="50"
    Fill="Blue"
    Stroke="Black" StrokeThickness="4"
    RadiusX="20" RadiusY="20"
    Canvas.Left="10"
    Canvas.Top="100"/>

</Canvas>
```

虽然此示例使用[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)来包含矩形，但是您可以使用矩形元素 （和所有其他形状元素） 以及任何[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)或[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)支持非文本内容。 事实上，矩形是特别有用的某些部分提供背景[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)面板。 有关示例，请参阅[表概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/table-overview)。

此示例摘自一个更大的示例;有关完整示例，请参阅[形状元素示例](https://go.microsoft.com/fwlink/?LinkID=160037)。

### [Modify the Cap at the End of a Line or Segment](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-modify-the-cap-at-the-end-of-a-line-or-segment)

此示例演示如何修改处的开始或结束的一种开放的形状[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)元素。 若要更改在打开的开始处上限[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)，使用其[StrokeStartLineCap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.strokestartlinecap)属性。 若要更改末尾的一种开放上限[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)，使用其[StrokeEndLineCap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.strokeendlinecap)属性。 若要查看可用的线帽，请参阅[PenLineCap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.penlinecap)枚举。

> 此属性才影响开放式形状，如[Line](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.line)、 一个[Polyline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.polyline)，或打开[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)元素。

下面的示例绘制了四个[Polyline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.polyline)元素，并在每个端点上使用一组不同的形状。

#### 示例

```xaml
<TextBlock Grid.Column="3" Grid.Row="0" Grid.ColumnSpan="2">
  <Bold>Line Caps</Bold>
</TextBlock>
<TextBlock Grid.Column="3" Grid.Row="1">Flat</TextBlock>
<Polyline
  Points="50,50 75,30 100,100 130,40"
  Stroke="Red"
  StrokeThickness="20"
  StrokeStartLineCap="Flat"
  StrokeEndLineCap="Flat"
  Grid.Row="1" Grid.Column="4"/>

<TextBlock Grid.Column="3" Grid.Row="2">Square</TextBlock>
<Polyline
  Points="50,50 75,30 100,100 130,40"
  Stroke="Red"
  StrokeThickness="20"
  StrokeStartLineCap="Square"
  StrokeEndLineCap="Square"    
  Grid.Row="2" Grid.Column="4"/>

<TextBlock Grid.Column="3" Grid.Row="3">Round</TextBlock>
<Polyline
  Points="50,50 75,30 100,100 130,40"
  Stroke="Red"
  StrokeThickness="20"
  StrokeStartLineCap="Round"
  StrokeEndLineCap="Round"  
  Grid.Row="3" Grid.Column="4"/>

<TextBlock Grid.Column="3" Grid.Row="4">Triangle</TextBlock>
<Polyline
  Points="50,50 75,30 100,100 130,40"
  Stroke="Red"
  StrokeThickness="20"
  StrokeStartLineCap="Triangle"
  StrokeEndLineCap="Triangle"     
  Grid.Row="4" Grid.Column="4"/>
```

此示例摘自一个更大的示例;有关完整示例，请参阅[形状元素示例](https://go.microsoft.com/fwlink/?LinkID=160037)。

