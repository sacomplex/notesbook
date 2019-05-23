# [Geometries](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/geometries)

[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry) 是一个通用类，用于呈现二维图形，命中测试对象，并定义剪辑区域

## 本节内容

[路径标记语法](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/path-markup-syntax)
[Geometry 概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/geometry-overview)
[帮助主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/geometries-how-to-topics)

## [Path Markup Syntax](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/path-markup-syntax)

路径中讨论[形状和基本绘图中 WPF 概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/shapes-and-basic-drawing-in-wpf-overview)和[几何概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/geometry-overview)，但是，本主题详细介绍了功能强大且复杂的微型语言，可用于指定路径使用更简洁的几何图形可扩展应用程序标记语言 (XAML)。

### 系统必备

若要了解本主题，您应该熟悉的基本功能的[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)对象。 有关详细信息，请参阅[几何概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/geometry-overview)。

### StreamGeometry and PathFigureCollection Mini-Languages

WPF 提供用于描述几何路径提供微型语言的两个类：[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)和[PathFigureCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathfigurecollection)。

- 您使用[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)微型语言设置类型的属性时[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)，如[Clip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.clip)的属性[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)或[Data](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path.data)属性[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)元素。 下面的示例使用属性语法创建[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)。

  ```xaml
  <Path Stroke="Black" Fill="Gray"
        Data="M 10,100 C 10,300 300,-200 300,100" />
  ```

- 您使用[PathFigureCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathfigurecollection)微型语言设置时[Figures](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry.figures)属性的[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)。 下面的示例使用特性语法来创建[PathFigureCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathfigurecollection)为[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)。

  ```xaml
  <Path Stroke="Black" Fill="Gray">
    <Path.Data>
      <PathGeometry Figures="M 10,100 C 10,300 300,-200 300,100" />
    </Path.Data>
  </Path>
  ```

从前面的示例中可以看出，两种微型语言非常相似。 它始终是可以使用[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)在任何情况下，可以使用[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry); 因此，您应使用哪一个？ 使用[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)不需要创建它; 后修改的路径时使用[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)如果需要修改的路径。

有关详细信息之间的差异[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)并[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)对象，请参阅[几何概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/geometry-overview)。

#### 有关空格的注意事项

为简洁起见，随后的语法部分中显示一个空格，但在显示一个空格的地方，多个空格也可以接受。

两个数字实际上无需分隔逗号或空格，但这仅可以生成的字符串不明确时。 例如，`2..3`是实际的两个数字："2."和“.3”。 同样，`2-3`是"2"和"-3"。 命令前面或后面也无需加空格。

#### 语法

可扩展应用程序标记语言 (XAML)属性使用语法[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)组成的可选[FillRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.fillrule)值和一个或多个图说明。

| StreamGeometry XAML 属性用法                                 |
| ------------------------------------------------------------ |
| `<` *object* *property* `="`[ `fillRule`] `figureDescription`[ `figureDescription`]* `" ... />` |

可扩展应用程序标记语言 (XAML)属性使用语法[PathFigureCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathfigurecollection)由一个或多个图形说明组成。

| PathFigureCollection XAML Attribute Usage                    |
| ------------------------------------------------------------ |
| `<` *object* *property* `="` `figureDescription`[ `figureDescription`]* `" ... />` |

| 术语                | 描述                                                         |
| ------------------- | ------------------------------------------------------------ |
| *fillRule*          | [System.Windows.Media.FillRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.fillrule)  指定是否[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)使用[EvenOdd](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.fillrule#System_Windows_Media_FillRule_EvenOdd)或[Nonzero](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.fillrule#System_Windows_Media_FillRule_Nonzero) [FillRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry.fillrule)。  - `F0` 指定[EvenOdd](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.fillrule#System_Windows_Media_FillRule_EvenOdd)填充规则。 - `F1` 指定[Nonzero](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.fillrule#System_Windows_Media_FillRule_Nonzero)填充规则。  如果省略此命令时，子路径将使用默认行为，即[EvenOdd](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.fillrule#System_Windows_Media_FillRule_EvenOdd)。 如果指定该命令，须先设置命令。 |
| *figureDescription* | 图形由一个移动命令，绘制命令和一个可选的关闭命令组成。  `moveCommand` `drawCommands` `[` `closeCommand` `]` |
| *moveCommand*       | 用于指定图形起点的移动命令。 请参阅[移动命令](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/path-markup-syntax#themovecommand)部分。 |
| *drawCommands*      | 用于描述图形内容的一个或多个绘图命令。 请参阅[绘制命令](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/path-markup-syntax#drawcommands)部分。 |
| *closeCommand*      | 用于关闭图形的可选关闭命令。 请参阅[关闭命令](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/path-markup-syntax#closecommand)部分。 |

### 移动命令

指定新图形的起点。

| 语法                                       |
| ------------------------------------------ |
| `M` *startPoint*  - 或 -  `m` *startPoint* |

| 术语         | 描述                                                         |
| ------------ | ------------------------------------------------------------ |
| *startPoint* | [System.Windows.Point](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.point)  新图形的起点。 |

大写`M`指示`startPoint`是一个绝对值; 小写字母`m`指示`startPoint`是对前一点的偏移量或 (0，0) 如果不存在。如果在移动命令之后列出多个点，可以绘制一条连接到这些点的直线，尽管已指定了直线命令。

### 绘制命令

绘制命令可以由几个形状命令组成。 以下形状命令可用：直线、水平线、竖线、三次贝塞尔曲线、二次贝塞尔曲线、平滑三次贝塞尔曲线、平滑二次贝塞尔曲线和椭圆弧。

可以使用大写或小写字母输入每个命令：大写字母表示绝对值，小写字母表示相对值：该线段的控制点相对于前面示例的终点。 当按顺序输入多个相同类型的命令，则可以省略重复的命令输入;例如，`L 100,200 300,400`等效于`L 100,200 L 300,400`。 下表描述了**移动**并**绘制**命令。

#### 直线命令

在当前点和指定的终点之间创建一条直线。 `l 20 30` 并`L 20,30`是有效的示例**行**命令。

| 语法                                   |
| -------------------------------------- |
| `L` *endPoint*  - 或 -  `l` *endPoint* |

| 术语       | 描述                                                         |
| ---------- | ------------------------------------------------------------ |
| *endPoint* | [System.Windows.Point](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.point)  线条的终点。 |

大写`L`指示`endPoint`是一个绝对值; 小写字母`l`指示`endPoint`是对前一点的偏移量或 (0，0) 如果不存在。

#### 水平线命令

在当前点和指定的 x 坐标之间创建一条水平线。 `H 90` 是有效水平线命令的示例。

| 语法                     |
| ------------------------ |
| `H` *x*  - 或 -  `h` *x* |

| 术语 | 描述                                                         |
| ---- | ------------------------------------------------------------ |
| *x*  | [System.Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double)  线条终点的 x 坐标。 |

大写`H`指示`x`是一个绝对值; 小写字母`h`指示`x`是对前一点的偏移量或 (0，0) 如果不存在。

#### 竖线命令

在当前点和指定的 y 坐标之间创建一条竖线。 `v 90` 是有效竖线命令的示例。

| 语法                     |
| ------------------------ |
| `V` *y*  - 或 -  `v` *y* |

| 术语 | 描述                                                         |
| ---- | ------------------------------------------------------------ |
| *y*  | [System.Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double)  直线终点的 y 坐标。 |

大写`V`指示`y`是一个绝对值; 小写字母`v`指示`y`是对前一点的偏移量或 (0，0) 如果不存在。

#### 三次贝塞尔曲线命令

通过使用两个指定的控制点创建当前点和指定的终结点之间的三次方贝塞尔曲线 (`controlPoint`1 和`controlPoint`2)。 `C 100,200 200,400 300,200` 是有效曲线命令的示例。

| 语法                                                         |
| ------------------------------------------------------------ |
| `C` `controlPoint`1`controlPoint`2`endPoint`  - 或 -  `c` `controlPoint`1`controlPoint`2`endPoint` |

| 术语            | 描述                                                         |
| --------------- | ------------------------------------------------------------ |
| `controlPoint`1 | [System.Windows.Point](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.point)  曲线的第一个控制点，它决定曲线的起始切线。 |
| `controlPoint`2 | [System.Windows.Point](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.point)  曲线的第二个控制点，它决定曲线的结束切线。 |
| `endPoint`      | [System.Windows.Point](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.point)  绘制曲线将通过的点。 |

#### 二次贝塞尔曲线命令

创建二次贝塞尔曲线的当前点和指定的终结点之间使用指定的控制点 (`controlPoint`)。 `q 100,200 300,200` 为有效二次贝塞尔曲线命令的示例。

| 语法                                                         |
| ------------------------------------------------------------ |
| `Q` `controlPoint` `endPoint`  - 或 -  `q` `controlPoint` `endPoint` |

| 术语           | 描述                                                         |
| -------------- | ------------------------------------------------------------ |
| `controlPoint` | [System.Windows.Point](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.point)  曲线的控制点，它决定曲线的开始和结束切线。 |
| `endPoint`     | [System.Windows.Point](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.point)  绘制曲线将通过的点。 |

#### 平滑三次贝塞尔曲线命令

在当前点和指定的终点之间创建三次贝塞尔曲线。 假设第一控制点为相对当前点前一命令的第二控制点的反射。如果没有前一命令或如果前一命令不是三次贝塞尔曲线命令或平滑三次贝塞尔曲线命令，则假设第一个控制点与当前点重合。 第二个控制点，由指定的曲线末尾的控制点`controlPoint`2。 例如，`S 100,200 200,300`是一个有效的平滑三次方贝塞尔曲线命令。

| 语法                                                         |
| ------------------------------------------------------------ |
| `S` `controlPoint`2`endPoint`  - 或 -  `s` `controlPoint`2`endPoint` |

| 术语            | 描述                                                         |
| --------------- | ------------------------------------------------------------ |
| `controlPoint`2 | [System.Windows.Point](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.point)  曲线的控制点，它决定曲线的结束切线。 |
| `endPoint`      | [System.Windows.Point](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.point)  绘制曲线将通过的点。 |

#### 平滑二次贝塞尔曲线命令

在当前点和指定的终点之间创建二次贝塞尔曲线。 假设控制点为相对于当前点前一命令的控制点的反射。 如果没有前一命令或如果前一命令不是二次贝塞尔曲线命令或平滑二次贝塞尔曲线命令，则控制点与当前点重合。

| 语法                                                         |
| ------------------------------------------------------------ |
| `T` `controlPoint` `endPoint`  - 或 -  `t` `controlPoint` `endPoint` |

| 术语           | 描述                                                         |
| -------------- | ------------------------------------------------------------ |
| `controlPoint` | [System.Windows.Point](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.point)  曲线的控制点，决定曲线的起点和曲线的切线。 |
| `endPoint`     | [System.Windows.Point](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.point)  绘制曲线将通过的点。 |

#### 椭圆弧命令

在当前点和指定的终点之间创建一个椭圆弧。

| 语法                                                         |
| ------------------------------------------------------------ |
| `A` `size` `rotationAngle` `isLargeArcFlag` `sweepDirectionFlag` `endPoint`  - 或 -  `a` `size` `rotationAngle` `isLargeArcFlag` `sweepDirectionFlag` `endPoint` |

| 术语                 | 描述                                                         |
| -------------------- | ------------------------------------------------------------ |
| `size`               | [System.Windows.Size](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.size)  圆弧的 x 轴和 y 轴半径。 |
| `rotationAngle`      | [System.Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double)  椭圆的旋转，以度为单位。 |
| `isLargeArcFlag`     | 如果圆弧角度应为 180 度或更大，请设置为 1，否则设置为 0。    |
| `sweepDirectionFlag` | 如果以正角方向绘制圆弧，请设置为 1；否则设置为 0。           |
| `endPoint`           | [System.Windows.Point](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.point)  绘制弧将通过的点。 |

###关闭命令

结束当前图形，并创建一条将当前点连接到图形起点的直线。 此命令可以在图形最后一段与第一段之间创建一条连接线（角）。

| 语法             |
| ---------------- |
| `Z`  - 或 -  `z` |

###点语法

描述一个点 x 和 y 坐标位置 (0，0) 是左上的角。

| 语法                         |
| ---------------------------- |
| `x` `,` `y`  - 或 -  `x` `y` |

| 术语 | 描述                                                         |
| ---- | ------------------------------------------------------------ |
| `x`  | [System.Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double)  该点的 x 坐标。 |
| `y`  | [System.Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double)  该点的 y 坐标。 |

### 特殊值

除了标准数值外，还可使用以下特殊值。 这些数值区分大小写。

无限
表示[Double.PositiveInfinity](https://docs.microsoft.com/zh-cn/dotnet/api/system.double.positiveinfinity)。

-Infinity
表示[Double.NegativeInfinity](https://docs.microsoft.com/zh-cn/dotnet/api/system.double.negativeinfinity)。

NaN
表示[Double.NaN](https://docs.microsoft.com/zh-cn/dotnet/api/system.double.nan)。

也可使用科学计数法。 例如，`+1.e17`是有效的值。

## [Geometry Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/geometry-overview)

本概述介绍如何使用Windows Presentation Foundation (WPF)[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)类描述形状。 本主题还对照了之间的差异[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)对象和[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)元素。

### 什么是 Geometry？

[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)类和类派生，如[EllipseGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.ellipsegeometry)， [PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)，和[CombinedGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.combinedgeometry)，使你可以描述 2-d 形状的几何图形。 这些几何描述具有许多用途，例如定义要绘制到屏幕的形状或定义命中测试和剪裁区域。 甚至可以使用几何定义动画路径。

[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry) 对象可以很简单，如矩形和圆形，也组合键，由两个或多个几何对象创建。 可以通过创建更复杂的几何[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)和[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)类，可用于描述弧线和曲线。

因为[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)是一种[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)，[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)对象提供多种特殊功能： 它们可以声明为[资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-resources)、 在多个对象，变为只读以提高性能，克隆，共享和变为线程安全。 有关所提供的不同功能的详细信息[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)对象，请参阅[Freezable 对象概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/freezable-objects-overview)。

### 几何与形状

[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)和[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)类的相似，因为它们均描述 2-d 形状 (比较[EllipseGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.ellipsegeometry)和[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)例如)，但有重要区别。

对于其中一个，[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)类继承自[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)类，而[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)类继承自[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)。 由于它们是元素，[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)对象可以自行呈现并参与布局系统，而[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)对象则不能。

尽管[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)对象是相比更易于使用[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)对象，[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)对象是更灵活。 虽然[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)对象用于呈现二维图形[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)对象可以用于定义 2-d 图形的几何区域、 定义剪裁的区域或定义命中测试的区域，例如。

#### Path 形状

一个[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)，则[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)类，实际使用[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)描述其内容。 通过设置[Data](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path.data)的属性[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)与[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)并设置其[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)并[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.stroke)属性，您可以呈现[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)。

### 采用 Geometry 的常见属性

上述部分提到了可将 Geometry 对象与其他对象结合用于各种目的，如绘制形状、动画处理和剪裁。 下表列出了几个类具有采用属性[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)对象。

| 类型                                                         | 属性                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [DoubleAnimationUsingPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimationusingpath) | [PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimationusingpath.pathgeometry) |
| [DrawingGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawinggroup) | [ClipGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawinggroup.clipgeometry) |
| [GeometryDrawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometrydrawing) | [Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometrydrawing.geometry) |
| [Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path) | [Data](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path.data) |
| [UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement) | [Clip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.clip) |

### 简单几何类型

针对所有几何的基类是抽象类[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)。 派生类[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)类可大致分为三个类别： 简单几何、 路径几何和复合几何。

简单的几何类包括[LineGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.linegeometry)， [RectangleGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rectanglegeometry)，和[EllipseGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.ellipsegeometry)和用于创建基本几何形状，例如线条、 矩形和圆形。

- 一个[LineGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.linegeometry)定义通过指定行和终结点的起始点。
- 一个[RectangleGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rectanglegeometry)定义与[Rect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.rect)结构指定其相对位置以及高度和宽度。 可以通过设置创建一个圆角的矩形[RadiusX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rectanglegeometry.radiusx)和[RadiusY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rectanglegeometry.radiusy)属性。
- [EllipseGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.ellipsegeometry)由中心点、 x 半径和 y 半径定义。 以下示例介绍如何创建简单几何来进行呈现和剪裁。

这些相同的形状以及更复杂的形状，可以使用创建[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)或通过合并几何对象组合在一起，但这些类用于生成这些基本几何形状提供更简单的方法。

下面的示例演示如何创建和呈现[LineGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.linegeometry)。 如前所述，[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)对象是无法自我绘制，因此该示例使用[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)形状呈现直线。 由于直线没有面积，设置[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)的属性[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)会产生任何影响; 相反，仅[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.stroke)和[StrokeThickness](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.strokethickness)指定属性。 下图显示该示例的输出。

![一个 LineGeometry](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-line.gif)
从 (10,20) 绘制到 (100,130) 的 LineGeometry

XAML复制

```xaml
<Path Stroke="Black" StrokeThickness="1" >
  <Path.Data>
    <LineGeometry StartPoint="10,20" EndPoint="100,130" />
  </Path.Data>
</Path>
```

C#复制

```csharp
LineGeometry myLineGeometry = new LineGeometry();
myLineGeometry.StartPoint = new Point(10,20);
myLineGeometry.EndPoint = new Point(100,130);

Path myPath = new Path();
myPath.Stroke = Brushes.Black;
myPath.StrokeThickness = 1;
myPath.Data = myLineGeometry;
```

下面的示例演示如何创建和呈现[EllipseGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.ellipsegeometry)。 示例集[Center](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.ellipsegeometry.center)的[EllipseGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.ellipsegeometry)设置为点`50,50`和 x 轴半径和 y 半径均设置为`50`，这将创建一个圆圈直径为 100。 通过这种情况下向 Path 元素的 Fill 属性分配值绘制椭圆的内部[Gold](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brushes.gold)。 下图显示该示例的输出。

![一个 EllipseGeometry](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-ellipse.gif)
在 (50,50) 处绘制的一个 EllipseGeometry

XAML复制

```xaml
<Path Fill="Gold" Stroke="Black" StrokeThickness="1">
  <Path.Data>
    <EllipseGeometry Center="50,50" RadiusX="50" RadiusY="50" />
  </Path.Data>
</Path>
```

C#复制

```csharp
EllipseGeometry myEllipseGeometry = new EllipseGeometry();
myEllipseGeometry.Center = new Point(50, 50);
myEllipseGeometry.RadiusX = 50;
myEllipseGeometry.RadiusY = 50;

Path myPath = new Path();
myPath.Fill = Brushes.Gold;
myPath.Stroke = Brushes.Black;
myPath.StrokeThickness = 1;
myPath.Data = myEllipseGeometry;
```

下面的示例演示如何创建和呈现[RectangleGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rectanglegeometry)。 由定义的位置和矩形的尺寸[Rect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.rect)结构。 位置为 `50,50`，高度和宽度均为 `25`，这将创建一个正方形。 下图显示该示例的输出。

![一个 RectangleGeometry](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-rectangle.gif)
在 50,50 处绘制的一个 RectangleGeometry

XAML复制

```xaml
<Path Fill="LemonChiffon" Stroke="Black" StrokeThickness="1">
  <Path.Data>
    <RectangleGeometry Rect="50,50,25,25" />
  </Path.Data>
</Path>
```

C#复制

```csharp
RectangleGeometry myRectangleGeometry = new RectangleGeometry();    
myRectangleGeometry.Rect = new Rect(50,50,25,25);

Path myPath = new Path();
myPath.Fill = Brushes.LemonChiffon;
myPath.Stroke = Brushes.Black;
myPath.StrokeThickness = 1;
myPath.Data = myRectangleGeometry;
```

下面的示例演示如何使用[EllipseGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.ellipsegeometry)作为图像的剪裁区域。 [Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)对象定义与[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)为 200 和[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)的 150。[EllipseGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.ellipsegeometry)与[RadiusX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.ellipsegeometry.radiusx)值为 100，[RadiusY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.ellipsegeometry.radiusy)值为 75，和一个[Center](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.ellipsegeometry.center)100,75 的值设置为[Clip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.clip)图像属性。 将仅显示处于椭圆形区域内的图像部分。 下图显示该示例的输出。

![具有和没有剪辑的图像](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-clipexample.png)
用于剪裁 Image 控件的 EllipseGeometry

XAML复制

```xaml
<Image
  Source="sampleImages\Waterlilies.jpg"
  Width="200" Height="150" HorizontalAlignment="Left">
  <Image.Clip>
    <EllipseGeometry
      RadiusX="100"
      RadiusY="75"
      Center="100,75"/>
  </Image.Clip>
</Image>
```

C#复制

```csharp
// Create the image to clip.
Image myImage = new Image();
Uri imageUri = 
    new Uri(@"C:\\Documents and Settings\\All Users\\Documents\My Pictures\\Sample Pictures\\Water lilies.jpg", UriKind.Relative);
myImage.Source = new BitmapImage(imageUri);
myImage.Width = 200;
myImage.Height = 150;
myImage.HorizontalAlignment = HorizontalAlignment.Left;    

// Use an EllipseGeometry to define the clip region. 
EllipseGeometry myEllipseGeometry = new EllipseGeometry();
myEllipseGeometry.Center = new Point(100, 75);
myEllipseGeometry.RadiusX = 100;
myEllipseGeometry.RadiusY = 75;
myImage.Clip = myEllipseGeometry;
```



### 路径几何

[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)类，其轻型等效项，[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)类中，提供方法来描述多个复杂图形组成弧线、 曲线和直线。

核心[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)是一系列[PathFigure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathfigure)对象，如此命名是因为每个图形都描述中的一个离散形状[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)。每个[PathFigure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathfigure)本身包含一个或多个[PathSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathsegment)对象，其中每个描述该图的段。

有多种类型的线段。

| 线段类型                                                     | 描述                               | 示例                                                         |
| ------------------------------------------------------------ | ---------------------------------- | ------------------------------------------------------------ |
| [ArcSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.arcsegment) | 创建两个点之间的椭圆弧。           | [创建椭圆弧](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-create-an-elliptical-arc)。 |
| [BezierSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.beziersegment) | 创建两个点之间的三次方贝塞尔曲线。 | [创建三次方贝塞尔曲线](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-cubic-bezier-curve)。 |
| [LineSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.linesegment) | 创建两个点之间的直线。             | [在 PathGeometry 中创建 LineSegment](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-linesegment-in-a-pathgeometry) |
| [PolyBezierSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.polybeziersegment) | 创建一系列三次方贝塞尔曲线。       | 请参阅[PolyBezierSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.polybeziersegment)类型页。 |
| [PolyLineSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.polylinesegment) | 创建一系列直线。                   | 请参阅[PolyLineSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.polylinesegment)类型页。 |
| [PolyQuadraticBezierSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.polyquadraticbeziersegment) | 创建一系列的二次贝塞尔曲线。       | 请参阅[PolyQuadraticBezierSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.polyquadraticbeziersegment)页。 |
| [QuadraticBezierSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.quadraticbeziersegment) | 创建一条二次贝塞尔曲线。           | [创建二次贝塞尔曲线](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-quadratic-bezier-curve)。 |

内部的分段[PathFigure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathfigure)合并为一个几何形状，每一段的下一段的起始点的终结点。 [StartPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathfigure.startpoint)属性的[PathFigure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathfigure)指定从中绘制第一条线段的点。 每个后续线段都从上一线段的终点开始。 例如，从竖线`10,50`到`10,150`可以通过设置定义[StartPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathfigure.startpoint)属性设置为`10,50`和创建[LineSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.linesegment)与[Point](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.linesegment.point)属性设置`10,150`。

下面的示例创建一个简单[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)组成单个[PathFigure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathfigure)与[LineSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.linesegment)，并显示其使用[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)元素。 [PathFigure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathfigure)对象的[StartPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathfigure.startpoint)设置为`10,20`和一个[LineSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.linesegment)使用的终结点定义`100,130`。 下图显示[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)创建此示例。

![一个 LineGeometry](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-line.gif)
包含单个 LineSegment 的 PathGeometry

XAML复制

```xaml
<Path Stroke="Black" StrokeThickness="1">
  <Path.Data>
    <PathGeometry>
      <PathGeometry.Figures>
        <PathFigure StartPoint="10,20">
          <PathFigure.Segments>
            <LineSegment Point="100,130"/>
          </PathFigure.Segments>
        </PathFigure>
      </PathGeometry.Figures>
    </PathGeometry>
  </Path.Data>
</Path>
```

C#复制

```csharp
// Create a figure that describes a 
// line from (10,20) to (100,130).
PathFigure myPathFigure = new PathFigure();
myPathFigure.StartPoint = new Point(10,20);
myPathFigure.Segments.Add(
    new LineSegment(new Point(100,130),
    true /* IsStroked */ ));

/// Create a PathGeometry to contain the figure.
PathGeometry myPathGeometry = new PathGeometry();
myPathGeometry.Figures.Add(myPathFigure);

// Display the PathGeometry. 
Path myPath = new Path();
myPath.Stroke = Brushes.Black;
myPath.StrokeThickness = 1;
myPath.Data = myPathGeometry;
```

必要将此示例与前面[LineGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.linegeometry)示例。 使用的语法[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)比用于简单的更详细[LineGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.linegeometry)，并且它可能会更合理使用[LineGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.linegeometry)类，在这种情况下，但使用的详细语法[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)允许极其错综复杂几何区域。

可以使用的组合创建更复杂的几何[PathSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathsegment)对象。

下面的示例使用[BezierSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.beziersegment)、 一个[LineSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.linesegment)，和一个[ArcSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.arcsegment)若要创建形状。 该示例首先创建三次方贝塞尔曲线是通过定义四个点： 一个开始点，这是前一条线段，终结点的结束点 ([Point3](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.beziersegment.point3))，以及两个控制点 ([Point1](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.beziersegment.point1)和[Point2](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.beziersegment.point2))。 三次方贝赛尔曲线的两个控制点行为像磁铁一样，朝着自身方向吸引本应为直线的部分，从而形成一条曲线。 第一个控制点[Point1](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.beziersegment.point1)，会影响开头曲线部分; 第二个控制点， [Point2](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.beziersegment.point2)，影响曲线的结束部分。

然后该示例添加[LineSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.linesegment)，其中前面的终结点之间绘制[BezierSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.beziersegment)由指定的点到其[LineSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.linesegment)属性。

然后该示例添加[ArcSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.arcsegment)，其中从前面的终点绘制[LineSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.linesegment)由指定的点到其[Point](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.arcsegment.point)属性。 该示例还指定弧线的 x 轴半径和 y 的半径 ([Size](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.arcsegment.size))，旋转角度 ([RotationAngle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.arcsegment.rotationangle))、 一个标志，指示生成的弧线角度应为多大 ([IsLargeArc](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.arcsegment.islargearc))，以及指示哪个方向绘制弧线的值 ([SweepDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.arcsegment.sweepdirection)). 下图显示此示例所创建的形状。

![A PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-path2.gif)
一个 PathGeometry

XAML复制

```xaml
<Path Stroke="Black" StrokeThickness="1" >
  <Path.Data>
    <PathGeometry>
      <PathGeometry.Figures>
        <PathFigure StartPoint="10,50">
          <PathFigure.Segments>
            <BezierSegment
              Point1="100,0"
              Point2="200,200"
              Point3="300,100"/>
            <LineSegment Point="400,100" />
            <ArcSegment
              Size="50,50" RotationAngle="45"
              IsLargeArc="True" SweepDirection="Clockwise"
              Point="200,100"/>
          </PathFigure.Segments>
        </PathFigure>
      </PathGeometry.Figures>
    </PathGeometry>
  </Path.Data>
</Path>
```

C#复制

```csharp
// Create a figure.
PathFigure myPathFigure = new PathFigure();
myPathFigure.StartPoint = new Point(10,50);
myPathFigure.Segments.Add(
    new BezierSegment(
        new Point(100,0),
        new Point(200,200),
        new Point(300,100),
        true /* IsStroked */  )); 
myPathFigure.Segments.Add(
    new LineSegment(
        new Point(400,100),
        true /* IsStroked */ ));
myPathFigure.Segments.Add(
    new ArcSegment(
        new Point(200,100),
        new Size(50,50),
        45,
        true, /* IsLargeArc */ 
        SweepDirection.Clockwise, 
        true /* IsStroked */ ));                       

/// Create a PathGeometry to contain the figure.
PathGeometry myPathGeometry = new PathGeometry();
myPathGeometry.Figures.Add(myPathFigure);

// Display the PathGeometry. 
Path myPath = new Path();
myPath.Stroke = Brushes.Black;
myPath.StrokeThickness = 1;
myPath.Data = myPathGeometry;
```

可以通过使用多个创建变得更加复杂的几何[PathFigure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathfigure)中的对象[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)。

下面的示例创建[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)具有两个[PathFigure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathfigure)对象，其中每个包含多个[PathSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathsegment)对象。 [PathFigure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathfigure)从上面的示例和一个[PathFigure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathfigure)与[PolyLineSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.polylinesegment)和一个[QuadraticBezierSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.quadraticbeziersegment)使用。 一个[PolyLineSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.polylinesegment)使用的点数组定义和[QuadraticBezierSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.quadraticbeziersegment)使用控点和终结点定义。 下图显示此示例所创建的形状。

![PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-path.gif)
带有多个图形的 PathGeometry

XAML复制

```xaml
<Path Stroke="Black" StrokeThickness="1" >
  <Path.Data>
    <PathGeometry>
      <PathGeometry.Figures>
        <PathFigure StartPoint="10,50">
          <PathFigure.Segments>
            <BezierSegment
              Point1="100,0"
              Point2="200,200"
              Point3="300,100"/>
            <LineSegment Point="400,100" />
            <ArcSegment
              Size="50,50" RotationAngle="45"
              IsLargeArc="True" SweepDirection="Clockwise"
              Point="200,100"/>
          </PathFigure.Segments>
        </PathFigure>
        
        <PathFigure StartPoint="10,100">
          <PathFigure.Segments>
            <PolyLineSegment Points="50,100 50,150" />
            <QuadraticBezierSegment Point1="200,200" Point2="300,100"/>
          </PathFigure.Segments>
        </PathFigure>                
      </PathGeometry.Figures>
    </PathGeometry>
  </Path.Data>
</Path>
```

C#复制

```csharp
PathGeometry myPathGeometry = new PathGeometry();            

// Create a figure.
PathFigure pathFigure1 = new PathFigure();
pathFigure1.StartPoint = new Point(10,50);
pathFigure1.Segments.Add(
    new BezierSegment(
        new Point(100,0),
        new Point(200,200),
        new Point(300,100),
        true /* IsStroked */ )); 
pathFigure1.Segments.Add(
    new LineSegment(
        new Point(400,100),
        true /* IsStroked */ ));
pathFigure1.Segments.Add(
    new ArcSegment(
        new Point(200,100),
        new Size(50,50),
        45,
        true, /* IsLargeArc */
        SweepDirection.Clockwise, 
        true /* IsStroked */ ));
myPathGeometry.Figures.Add(pathFigure1);    

// Create another figure.
PathFigure pathFigure2 = new PathFigure();
pathFigure2.StartPoint = new Point(10,100);
Point[] polyLinePointArray = 
    new Point[]{ new Point(50, 100), new Point(50, 150)};
PolyLineSegment myPolyLineSegment = new PolyLineSegment();
myPolyLineSegment.Points = 
    new PointCollection(polyLinePointArray);
pathFigure2.Segments.Add(myPolyLineSegment);
pathFigure2.Segments.Add(
    new QuadraticBezierSegment(
        new Point(200,200),
        new Point(300,100),
        true /* IsStroked */ ));
myPathGeometry.Figures.Add(pathFigure2);

// Display the PathGeometry. 
Path myPath = new Path();
myPath.Stroke = Brushes.Black;
myPath.StrokeThickness = 1;
myPath.Data = myPathGeometry;
```

#### StreamGeometry

像[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)类，[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)定义可能包含曲线、 弧线和直线的复杂几何形状。 与不同[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)的内容[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)不支持数据绑定、 动画或修改。 使用[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)何时需要描述复杂几何，但不是希望支持数据绑定、 动画或修改的开销。 由于其效率[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)类是描述装饰器的一个不错选择。

有关示例，请参阅[使用 StreamGeometry 创建形状](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-shape-using-a-streamgeometry)。

#### 路径标记语法

[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)并[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)类型支持的可扩展应用程序标记语言 (XAML)特性语法使用一系列特殊的移动和绘制命令。 有关详细信息，请参阅[路径标记语法](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/path-markup-syntax)。

### 复合几何

可以使用创建复合几何对象[GeometryGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometrygroup)、 一个[CombinedGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.combinedgeometry)，或通过调用静态[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)方法[Combine](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry.combine)。

- [CombinedGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.combinedgeometry)对象和[Combine](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry.combine)方法执行布尔操作以合并由两个几何定义的区域。 [Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry) 将放弃没有面积的对象。 只有两个[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)（尽管这两个几何也可能是复合几何），可以组合对象。
- [GeometryGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometrygroup)类创建的合并，[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)对象包含而合并其面积。 任意数量的[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)可以将对象添加到[GeometryGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometrygroup)。 有关示例，请参阅[创建复合形状](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-composite-shape)。

因为它们不会执行合并操作，使用[GeometryGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometrygroup)对象通过使用提供性能优势[CombinedGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.combinedgeometry)对象或[Combine](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry.combine)方法。

### 合并几何

上一节所述[CombinedGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.combinedgeometry)对象和[Combine](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry.combine)方法合并它们所包含的几何所定义的区域。[GeometryCombineMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometrycombinemode)枚举指定如何合并几何。 可能的值[GeometryCombineMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.combinedgeometry.geometrycombinemode)属性是： [Union](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometrycombinemode#System_Windows_Media_GeometryCombineMode_Union)， [Intersect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometrycombinemode#System_Windows_Media_GeometryCombineMode_Intersect)， [Exclude](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometrycombinemode#System_Windows_Media_GeometryCombineMode_Exclude)，和[Xor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometrycombinemode#System_Windows_Media_GeometryCombineMode_Xor)。

在以下示例中，[CombinedGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.combinedgeometry)使用 Union 的合并模式定义。 这两[Geometry1](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.combinedgeometry.geometry1)和[Geometry2](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.combinedgeometry.geometry2)定义为圆的半径相同，但中心偏移 50。

```xaml
<Path Stroke="Black" StrokeThickness="1" Fill="#CCCCFF">
  <Path.Data>
    
    <!-- Combines two geometries using the union combine mode. -->
    <CombinedGeometry GeometryCombineMode="Union">
      <CombinedGeometry.Geometry1>
        <EllipseGeometry RadiusX="50" RadiusY="50" Center="75,75" />
      </CombinedGeometry.Geometry1>
      <CombinedGeometry.Geometry2>
        <EllipseGeometry RadiusX="50" RadiusY="50" Center="125,75" />
      </CombinedGeometry.Geometry2>
    </CombinedGeometry>
  </Path.Data>
</Path>
```

![Results of the Union combine mode](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/mil-task-combined-geometry-union.png)

在以下示例中，[CombinedGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.combinedgeometry)使用的合并模式定义[Xor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometrycombinemode#System_Windows_Media_GeometryCombineMode_Xor)。 这两[Geometry1](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.combinedgeometry.geometry1)和[Geometry2](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.combinedgeometry.geometry2)定义为圆的半径相同，但中心偏移 50。

```xaml
<Path Stroke="Black" StrokeThickness="1" Fill="#CCCCFF">
  <Path.Data>
    
    <!-- Combines two geometries using the XOR combine mode. -->
    <CombinedGeometry GeometryCombineMode="Xor">
      <CombinedGeometry.Geometry1>
        <EllipseGeometry RadiusX="50" RadiusY="50" Center="75,75" />
      </CombinedGeometry.Geometry1>
      <CombinedGeometry.Geometry2>
        <EllipseGeometry RadiusX="50" RadiusY="50" Center="125,75" />
      </CombinedGeometry.Geometry2>
    </CombinedGeometry>
  </Path.Data>
</Path>
```

![Results of the Xor combine mode](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/mil-task-combined-geometry-xor.png)

有关其他示例，请参阅[创建复合形状](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-composite-shape)和[创建合并的几何](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-combined-geometry)。

### Freezable 功能

因为它继承自[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)类，[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)类提供多种特殊功能：[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)对象可声明为[XAML 资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-resources)、 在多个对象，变为只读以提高共享性能、 克隆以及变为线程安全。 有关所提供的不同功能的详细信息[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)对象，请参阅[Freezable 对象概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/freezable-objects-overview)。

### 其他几何功能

[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)类还提供了有用的实用工具方法，如下所示：

- [GetArea](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry.getarea) -获取的区域[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)。
- [FillContains](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry.fillcontains) -确定 Geometry 是否包含另一个[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)。
- [StrokeContains](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry.strokecontains) -确定是否的笔划[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)包含指定的点。

请参阅[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)类及其方法的完整列表。

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/geometries-how-to-topics)

在本部分中的主题演示如何使用[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)您的应用程序中的对象。

### 本节内容

[为 EllipseGeometry 设置动画效果](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-animate-an-ellipsegeometry)
[为 ArcSegment 的大小设置动画效果](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-animate-the-size-of-an-arcsegment)
[控制复合形状的填充](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-control-the-fill-of-a-composite-shape)
[创建组合的几何图形](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-combined-geometry)
[创建复合形状](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-composite-shape)
[创建三次方贝塞尔曲线](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-cubic-bezier-curve)
[使用 LineGeometry 创建直线](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-line-using-a-linegeometry)
[在 PathGeometry 中创建 LineSegment](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-linesegment-in-a-pathgeometry)
[使用 PathGeometry 创建形状](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-shape-by-using-a-pathgeometry)
[使用 StreamGeometry 创建形状](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-shape-using-a-streamgeometry)
[创建二次贝塞尔曲线](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-quadratic-bezier-curve)
[创建椭圆弧](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-create-an-elliptical-arc)
[在 PathGeometry 内创建多个子路径](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-create-multiple-subpaths-within-a-pathgeometry)
[使用 RectangleGeometry 定义矩形](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-define-a-rectangle-using-a-rectanglegeometry)
[让 RectangleGeometry 采用圆角](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-round-the-corners-of-a-rectanglegeometry)

### [Animate an EllipseGeometry](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-animate-an-ellipsegeometry)

此示例演示如何进行动画处理[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)内[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)元素。 在以下示例中，[PointAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.pointanimation)用于进行动画处理[Center](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.ellipsegeometry.center)的[EllipseGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.ellipsegeometry)。

#### 示例

```xaml
<!-- EllipseGeometryExample.xaml
     This example shows how to animate an EllipseGeometry. -->
<Page 
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  WindowTitle="EllipseGeometry Animation Example">
  <Canvas Height="400" Width="400" Margin="20">
 
    <Path Name="myPathShape"
      Fill="Blue" Stroke="Black" StrokeThickness="5">
      <Path.Data>
        <EllipseGeometry x:Name="MyEllipseGeometry" 
          Center="200,200" RadiusX="25" RadiusY="50" />
      </Path.Data>
      <Path.Triggers>
      
        <!-- Animates the Center position of the
             EllipseGeometry. -->
        <EventTrigger RoutedEvent="Path.Loaded">
          <BeginStoryboard>
            <Storyboard>
              <PointAnimation 
                Storyboard.TargetName="MyEllipseGeometry" 
                Storyboard.TargetProperty="Center"
                From="200,200" To="50,50" Duration="0:0:5" 
                AutoReverse="true" RepeatBehavior="Forever"/>
            </Storyboard>
          </BeginStoryboard>
        </EventTrigger>
      </Path.Triggers>
    </Path>
  </Canvas>
</Page>
```

```csharp
// EllipseGeometryExample.cs
//
// This sample demonstrates how to animate the center 
// position of an EllipseGeometry using a PointAnimation.

using System;
using System.Windows;
using System.Windows.Navigation;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Shapes;
using System.Windows.Controls;

namespace Microsoft.Samples.Animation.AnimatePathShapeSample
{

    public class EllipseGeometryExample : Page {
        
        public EllipseGeometryExample()
        {
        
            NameScope.SetNameScope(this, new NameScope());
            
            WindowTitle = "EllipseGeometry Animation Example";
            
            Canvas myCanvas = new Canvas();
            myCanvas.Width = 400;
            myCanvas.Height = 400;
            myCanvas.Margin = new Thickness(20);
            
            // Create a Path object to contain the geometry.
            System.Windows.Shapes.Path myPath =
                new System.Windows.Shapes.Path();           
            myPath.Fill = System.Windows.Media.Brushes.Blue;
            myPath.Stroke = System.Windows.Media.Brushes.Black;
            myPath.StrokeThickness = 5;
            
            // Create an EllipseGeometry.
            System.Windows.Media.EllipseGeometry myEllipseGeometry =
                new System.Windows.Media.EllipseGeometry();
            myEllipseGeometry.Center = new System.Windows.Point(200, 200);
            myEllipseGeometry.RadiusX = 25;
            myEllipseGeometry.RadiusY = 50;
            
            // Register a name for the geometry so that it can
            // be targeted by animations.
            this.RegisterName("MyEllipseGeometry", myEllipseGeometry);            
            
            // Add the geometry to the Path.
            myPath.Data = myEllipseGeometry;
            myCanvas.Children.Add(myPath);
            this.Content = myCanvas;
            
            // Create a PointAnimation to animate the center of the ellipse.
            PointAnimation myPointAnimation = new PointAnimation();
            myPointAnimation.From = new System.Windows.Point(200, 200);
            myPointAnimation.To = new System.Windows.Point(50, 50);
            myPointAnimation.Duration = 
                new Duration(TimeSpan.FromMilliseconds(5000));
            myPointAnimation.AutoReverse = true;
            myPointAnimation.RepeatBehavior = RepeatBehavior.Forever;
            
            Storyboard.SetTargetName(myPointAnimation, "MyEllipseGeometry");       
            Storyboard.SetTargetProperty(myPointAnimation, 
                new PropertyPath(EllipseGeometry.CenterProperty));
            Storyboard myStoryboard = new Storyboard();
            myStoryboard.Children.Add(myPointAnimation);
            
            // Use an anonymous event handler to begin the animation
            // when the path is loaded.
            myPath.Loaded +=  delegate(object sender, RoutedEventArgs args)
                {
                    myStoryboard.Begin(myPath);
                
                };
        }
    }
}
```

### [Animate the Size of an ArcSegment](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-animate-the-size-of-an-arcsegment)

此示例演示如何进行动画处理[Size](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.arcsegment.size)属性的[ArcSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.arcsegment)。

#### 示例

下面的示例创建[ArcSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.arcsegment)进行动画处理其[Size](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.arcsegment.size)在屏幕上的加载时。

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Shapes;
using System.Windows.Media.Animation;
using System.Windows.Media;

namespace SDKSamples
{
    public class SizeAnimationExample : Page
    {
        public SizeAnimationExample()
        {

            // Create a NameScope for this page so that
            // Storyboards can be used.
            NameScope.SetNameScope(this, new NameScope());

            // Create an ArcSegment to define the geometry of the path.
            // The Size property of this segment is animated.
            ArcSegment myArcSegment = new ArcSegment();
            myArcSegment.Size = new Size(90, 80);
            myArcSegment.SweepDirection = SweepDirection.Clockwise;
            myArcSegment.Point = new Point(500, 200);

            // Assign the segment a name so that
            // it can be targeted by a Storyboard.
            this.RegisterName(
                "myArcSegment", myArcSegment);

            PathSegmentCollection myPathSegmentCollection = new PathSegmentCollection();
            myPathSegmentCollection.Add(myArcSegment);

            // Create a PathFigure to be used for the PathGeometry of myPath.
            PathFigure myPathFigure = new PathFigure();

            // Set the starting point for the PathFigure specifying that the
            // geometry starts at point 100,200.
            myPathFigure.StartPoint = new Point(100, 200);

            myPathFigure.Segments = myPathSegmentCollection;

            PathFigureCollection myPathFigureCollection = new PathFigureCollection();
            myPathFigureCollection.Add(myPathFigure);

            PathGeometry myPathGeometry = new PathGeometry();
            myPathGeometry.Figures = myPathFigureCollection;

            // Create a path to draw a geometry with.
            Path myPath = new Path();
            myPath.Stroke = Brushes.Black;
            myPath.StrokeThickness = 1;

            // specify the shape of the path using the path geometry.
            myPath.Data = myPathGeometry;

            SizeAnimation mySizeAnimation = new SizeAnimation();
            mySizeAnimation.Duration = TimeSpan.FromSeconds(2);

            // Set the animation to repeat forever. 
            mySizeAnimation.RepeatBehavior = RepeatBehavior.Forever;

            // Set the From and To properties of the animation.
            mySizeAnimation.From = new Size(90, 80);
            mySizeAnimation.To = new Size(200, 200);

            // Set the animation to target the Size property
            // of the object named "myArcSegment."
            Storyboard.SetTargetName(mySizeAnimation, "myArcSegment");
            Storyboard.SetTargetProperty(
                mySizeAnimation, new PropertyPath(ArcSegment.SizeProperty));

            // Create a storyboard to apply the animation.
            Storyboard ellipseStoryboard = new Storyboard();
            ellipseStoryboard.Children.Add(mySizeAnimation);

            // Start the storyboard when the Path loads.
            myPath.Loaded += delegate(object sender, RoutedEventArgs e)
            {
                ellipseStoryboard.Begin(this);
            };

            Canvas containerCanvas = new Canvas();
            containerCanvas.Children.Add(myPath);

            Content = containerCanvas;
        }
    }
}
```

有关其他几何图形和动画示例，请参阅[几何图形示例](https://go.microsoft.com/fwlink/?LinkID=159989)。

### [Control the Fill of a Composite Shape](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-control-the-fill-of-a-composite-shape)

[FillRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometrygroup.fillrule)的属性[GeometryGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometrygroup)或[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)，指定用于确定给定的点是否是几何图形的一部分复合形状的"规则"。 有两个可能值[FillRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.fillrule):[EvenOdd](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.fillrule#System_Windows_Media_FillRule_EvenOdd)和[Nonzero](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.fillrule#System_Windows_Media_FillRule_Nonzero)。 以下各节将介绍如何使用这两个规则。

#### 示例

**EvenOdd:** 此规则确定是否填充区域从该点沿任意方向绘制一条射线，然后计算给定射线相交的形状中的路径段数目。 如果此数目为奇数，那么该点则在内部；如果为偶数，则该点在外部。

例如，以下 XAML 创建的一系列同心环 （目标） 组成的复合形状[FillRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometrygroup.fillrule)设置为[EvenOdd](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.fillrule#System_Windows_Media_FillRule_EvenOdd)。

```xaml
<Path Stroke="Black" StrokeThickness="1" Fill="#CCCCFF">
  <Path.Data>
    <GeometryGroup FillRule="EvenOdd">
      <EllipseGeometry RadiusX="50" RadiusY="50" Center="75,75" />
      <EllipseGeometry RadiusX="70" RadiusY="70" Center="75,75" />
      <EllipseGeometry RadiusX="100" RadiusY="100" Center="75,75" />
      <EllipseGeometry RadiusX="120" RadiusY="120" Center="75,75" />
    </GeometryGroup>
  </Path.Data>
</Path>
```

下图显示在上一个示例中创建的形状。

![屏幕快照：Fillrule evenodd](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/fillruleevenoddfirstone.png)

在上图中，请注意，中心和第三个环并未填充。 这是因为射线是从穿过偶数段的这两个环中的点绘制的。 请参阅下图：

![关系图：EvenOdd 的 FillRule 属性值](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/fillruleevenodd2.png)

**非零值：** 此规则确定是否在路径的填充区域从该点沿任意方向绘制一条射线，并检查段形状与射线相交的位置的位置。 从零计数开始，从左到右每次添加与射线相交的一个段，然后从右到左每次减去与射线相交的一个路径段。 在对交叉点进行计数后，如果结果为零，那么该点则位于路径外。 否则，该点则在路径内。

XAML复制

```xaml
<Path Stroke="Black" StrokeThickness="1" Fill="#CCCCFF">
  <Path.Data>
    <GeometryGroup FillRule="NonZero">
      <EllipseGeometry RadiusX="50" RadiusY="50" Center="75,75" />
      <EllipseGeometry RadiusX="70" RadiusY="70" Center="75,75" />
      <EllipseGeometry RadiusX="100" RadiusY="100" Center="75,75" />
      <EllipseGeometry RadiusX="120" RadiusY="120" Center="75,75" />
    </GeometryGroup>
  </Path.Data>
</Path>
```

使用以下示例中，值为[Nonzero](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.fillrule#System_Windows_Media_FillRule_Nonzero)为[FillRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometrygroup.fillrule)因此了以下图示：

![屏幕快照：FillRule 值 nonzero](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/fillrulenonzero1.png)

如图所示，所有环都已填充。 这是因为所有段按同一方向运行，因此从任一点绘制的射线将与一个或多个段相交，并且交点总数不会等于零。 例如，在下图中，红色箭头表示段的绘制方向，白色箭头表示从最内部环中的某一个点运行的任意一条射线。 从零值开始，对于该射线相交的每个段，会加值“1”，因为从左到右该段与该射线相交。

![关系图：FillRule 属性值等于 NonZero](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/fillrulenonzero2.png)

若要更好地演示行为的[Nonzero](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.fillrule#System_Windows_Media_FillRule_Nonzero)是必需的规则与段以不同方向运行更复杂的形状。 下面的 XAML 代码与前面的示例创建字形相似，只不过它使用创建[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)而不是[EllipseGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.ellipsegeometry)这将创建四个同心弧而不是完全闭合的同心环。

```xaml
<Path Stroke="Black" StrokeThickness="1" Fill="#CCCCFF">
  <Path.Data>
    <GeometryGroup FillRule="NonZero">
      <PathGeometry>
        <PathGeometry.Figures>

          <!-- Inner Ring -->
          <PathFigure StartPoint="10,120">
            <PathFigure.Segments>
              <PathSegmentCollection>
                <ArcSegment Size="50,50" IsLargeArc="True" SweepDirection="CounterClockwise" Point="25,120" />
              </PathSegmentCollection>
            </PathFigure.Segments>
          </PathFigure>

          <!-- Second Ring -->
          <PathFigure StartPoint="10,100">
            <PathFigure.Segments>
              <PathSegmentCollection>
                <ArcSegment Size="70,70" IsLargeArc="True" SweepDirection="CounterClockwise" Point="25,100" />
              </PathSegmentCollection>
            </PathFigure.Segments>
          </PathFigure>

          <!-- Third Ring (Not part of path) -->
          <PathFigure StartPoint="10,70">
            <PathFigure.Segments>
              <PathSegmentCollection>
                <ArcSegment Size="100,100" IsLargeArc="True" SweepDirection="CounterClockwise" Point="25,70" />
              </PathSegmentCollection>
            </PathFigure.Segments>
          </PathFigure>

          <!-- Outer Ring -->
          <PathFigure StartPoint="10,300">
            <PathFigure.Segments>
              <ArcSegment Size="130,130" IsLargeArc="True" SweepDirection="Clockwise" Point="25,300" />
            </PathFigure.Segments>
          </PathFigure>
        </PathGeometry.Figures>
      </PathGeometry>
    </GeometryGroup>
  </Path.Data>
</Path>
```

下图显示在上一个示例中创建的形状。

![屏幕快照：NonZero 的 FillRule 属性值](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/fillrulenonzero3.png)

请注意，自中心数起的第三条弧未填充。 下图说明了出现这种情况的原因。 在图中，红色箭头表示绘制段的方向。 两个白色箭头表示以“未填充”区域中的某个点为起点绘制的任意两条射线。 如图所示，与给定射线路径中的段相交的该射线值的总和为零。 如上文所定义，总和为零意味着该点不是几何图形的一部分（也不是填充的一部分），而总和*不*为零（包括负值）意味着该点是几何图形的一部分。

![关系图：NonZero 的 FillRule 属性值](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/fillrulenonzero4.png)

**注意：** 出于[FillRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.fillrule)，所有形状都视为已关闭。 如果段中存在间隙，请绘制用于闭合该段的假想线。 在以上示例中，环中存在多个较小间隙。 考虑到这一点，人们可能希望穿过间隙的射线产生不同的结果，然后射线在另一个方向上运行。 下面是放大的举例说明了一种存在的这些障碍和的"假想段"(用于应用的目的绘制的段[FillRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.fillrule))，将其关闭。

![关系图：对于 FillRule，线段总是封闭](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/fillruleclosedshapes.png)

### [Create a Combined Geometry](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-combined-geometry)

此示例演示如何组合几何图形。 若要合并两个几何图形，使用[CombinedGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.combinedgeometry)对象。 设置其[Geometry1](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.combinedgeometry.geometry1)和[Geometry2](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.combinedgeometry.geometry2)具有两个几何图形合并，并设置属性[GeometryCombineMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.combinedgeometry.geometrycombinemode)属性，确定如何几何图形将组合在一起，到`Union`， `Intersect`， `Exclude`，或`Xor`.

若要从两个或多个几何图形中创建的复合几何图形，使用[GeometryGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometrygroup)。

#### 示例

在下面的示例中，[CombinedGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.combinedgeometry)几何图形组合模式的定义`Exclude`。 同时[Geometry1](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.combinedgeometry.geometry1)和[Geometry2](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.combinedgeometry.geometry2)定义圆的半径相同，但是中心偏移量为 50。

```xaml
<Path Stroke="Black" StrokeThickness="1" Fill="#CCCCFF">
  <Path.Data>
    
    <!-- Combines two geometries using the exclude combine mode. -->
    <CombinedGeometry GeometryCombineMode="Exclude">
      <CombinedGeometry.Geometry1>
        <EllipseGeometry RadiusX="50" RadiusY="50" Center="75,75" />
      </CombinedGeometry.Geometry1>
      <CombinedGeometry.Geometry2>
        <EllipseGeometry RadiusX="50" RadiusY="50" Center="125,75" />
      </CombinedGeometry.Geometry2>
    </CombinedGeometry>
  </Path.Data>
</Path>
```

![组合模式的排除结果](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/mil-task-combined-geometry-exclude.png)
合并后的几何图形排除

在下列标记中，[CombinedGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.combinedgeometry)组合模式的定义`Intersect`。 同时[Geometry1](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.combinedgeometry.geometry1)和[Geometry2](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.combinedgeometry.geometry2)定义圆的半径相同，但是中心偏移量为 50。

```xaml
<Path Stroke="Black" StrokeThickness="1" Fill="#CCCCFF">
  <Path.Data>
    
    <!-- Combines two geometries using the intersect combine mode. -->
    <CombinedGeometry GeometryCombineMode="Intersect">
      <CombinedGeometry.Geometry1>
        <EllipseGeometry RadiusX="50" RadiusY="50" Center="75,75" />
      </CombinedGeometry.Geometry1>
      <CombinedGeometry.Geometry2>
        <EllipseGeometry RadiusX="50" RadiusY="50" Center="125,75" />
      </CombinedGeometry.Geometry2>
    </CombinedGeometry>
  </Path.Data>
</Path>
```

![组合模式的 Intersect 结果](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/mil-task-combined-geometry-intersect.png)
合并后的几何图形相交

在下列标记中，[CombinedGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.combinedgeometry)组合模式的定义`Union`。 同时[Geometry1](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.combinedgeometry.geometry1)和[Geometry2](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.combinedgeometry.geometry2)定义圆的半径相同，但是中心偏移量为 50。

```xaml
<Path Stroke="Black" StrokeThickness="1" Fill="#CCCCFF">
  <Path.Data>
    
    <!-- Combines two geometries using the union combine mode. -->
    <CombinedGeometry GeometryCombineMode="Union">
      <CombinedGeometry.Geometry1>
        <EllipseGeometry RadiusX="50" RadiusY="50" Center="75,75" />
      </CombinedGeometry.Geometry1>
      <CombinedGeometry.Geometry2>
        <EllipseGeometry RadiusX="50" RadiusY="50" Center="125,75" />
      </CombinedGeometry.Geometry2>
    </CombinedGeometry>
  </Path.Data>
</Path>
```

![Results of the Union combine mode](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/mil-task-combined-geometry-union.png)
合并后的几何图形联合

在下列标记中，[CombinedGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.combinedgeometry)组合模式的定义`Xor`。 同时[Geometry1](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.combinedgeometry.geometry1)和[Geometry2](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.combinedgeometry.geometry2)定义圆的半径相同，但是中心偏移量为 50。

```xaml
<Path Stroke="Black" StrokeThickness="1" Fill="#CCCCFF">
  <Path.Data>
    
    <!-- Combines two geometries using the XOR combine mode. -->
    <CombinedGeometry GeometryCombineMode="Xor">
      <CombinedGeometry.Geometry1>
        <EllipseGeometry RadiusX="50" RadiusY="50" Center="75,75" />
      </CombinedGeometry.Geometry1>
      <CombinedGeometry.Geometry2>
        <EllipseGeometry RadiusX="50" RadiusY="50" Center="125,75" />
      </CombinedGeometry.Geometry2>
    </CombinedGeometry>
  </Path.Data>
</Path>
```

![Results of the Xor combine mode](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/mil-task-combined-geometry-xor.png)
合并后的几何图形 Xor

### [Create a Composite Shape](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-composite-shape)

此示例演示如何创建使用复合形状[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)对象并将其显示使用[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)元素。 在以下示例中， [LineGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.linegeometry)，[EllipseGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.ellipsegeometry)，和一个[RectangleGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rectanglegeometry)与一起使用[GeometryGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometrygroup)创建复合形状。 然后使用绘制几何图形的[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)元素。

#### 示例

```xaml
<!-- Displays the geometry. --> 
<Path Stroke="Black" StrokeThickness="1" Fill="#CCCCFF">
  <Path.Data>
  
    <!-- Creates a composite shape from three geometries. -->
    <GeometryGroup FillRule="EvenOdd">
      <LineGeometry StartPoint="10,10" EndPoint="50,30" />
      <EllipseGeometry Center="40,70" RadiusX="30" RadiusY="30" />              
      <RectangleGeometry Rect="30,55 100 30" />
    </GeometryGroup>
  </Path.Data>
</Path>
```

```csharp
// Create a Path to be drawn to the screen.
Path myPath = new Path();
myPath.Stroke = Brushes.Black;
myPath.StrokeThickness = 1;
SolidColorBrush mySolidColorBrush = new SolidColorBrush();
mySolidColorBrush.Color = Color.FromArgb(255, 204, 204, 255);
myPath.Fill = mySolidColorBrush;

// Create the line geometry to add to the Path
LineGeometry myLineGeometry = new LineGeometry();
myLineGeometry.StartPoint = new Point(10, 10);
myLineGeometry.EndPoint = new Point(50, 30);

// Create the ellipse geometry to add to the Path
EllipseGeometry myEllipseGeometry = new EllipseGeometry();
myEllipseGeometry.Center = new Point(40, 70);
myEllipseGeometry.RadiusX = 30;
myEllipseGeometry.RadiusY = 30;

// Create a rectangle geometry to add to the Path
RectangleGeometry myRectGeometry = new RectangleGeometry();
myRectGeometry.Rect = new Rect(30, 55, 100, 30);

// Add all the geometries to a GeometryGroup.
GeometryGroup myGeometryGroup = new GeometryGroup();
myGeometryGroup.Children.Add(myLineGeometry);
myGeometryGroup.Children.Add(myEllipseGeometry);
myGeometryGroup.Children.Add(myRectGeometry);

myPath.Data = myGeometryGroup;

// Add path shape to the UI.
StackPanel mainPanel = new StackPanel();
mainPanel.Children.Add(myPath);
this.Content = mainPanel;
```

下图显示在上一个示例中创建的形状。

![使用 GeometryGroup 创建的复合几何图形](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wcpsdk-graphicsmm-compositegeometryexample1.jpg)
复合几何图形

可以使用创建更复杂的形状的多边形和形状使用曲线段，如[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)。 有关示例显示了如何使用创建形状[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)，请参阅[使用 PathGeometry 创建形状](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-shape-by-using-a-pathgeometry)。 虽然此示例的呈现到屏幕使用形状[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)元素中，[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)也可能会使用对象来描述的内容[GeometryDrawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometrydrawing)或[DrawingContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingcontext)。 此外可用于剪辑和命中测试它们。

此示例是更大示例的组成部分；有关完整示例，请参阅[几何图形示例](https://go.microsoft.com/fwlink/?LinkID=159989)。

### [Create a Cubic Bezier Curve](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-cubic-bezier-curve)

此示例演示如何创建三次方贝塞尔曲线。 若要创建三次方贝塞尔曲线，使用[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)， [PathFigure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathfigure)，和[BezierSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.beziersegment)类。 若要显示所生成的几何图形，请使用[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)元素，或将其用于[GeometryDrawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometrydrawing)或[DrawingContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingcontext)。 在以下示例中，三次方贝塞尔曲线绘制从 （10，100） 到 （300，100）。 曲线的控制点为 （100，0） 和 （200，200）。

#### 示例

在可扩展应用程序标记语言 (XAML)，可以使用缩写的标记语法来描述路径。

```xaml
<Path Stroke="Black" StrokeThickness="1"  
  Data="M 10,100 C 100,0 200,200 300,100" />
```

在XAML，还可以绘制使用对象标记的三次方贝塞尔曲线。 以下内容等效于之前的 XAML 示例。

```xaml
<Path Stroke="Black" StrokeThickness="1">
  <Path.Data>
    <PathGeometry>
      <PathGeometry.Figures>
        <PathFigureCollection>
          <PathFigure StartPoint="10,100">
            <PathFigure.Segments>
              <PathSegmentCollection>
                <BezierSegment Point1="100,0" Point2="200,200" Point3="300,100" />
              </PathSegmentCollection>
            </PathFigure.Segments>
          </PathFigure>
        </PathFigureCollection>
      </PathGeometry.Figures>
    </PathGeometry>
  </Path.Data>
</Path>
```

此示例是更大示例的组成部分；有关完整示例，请参阅[几何图形示例](https://go.microsoft.com/fwlink/?LinkID=159989)。

### [Create a Line Using a LineGeometry](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-line-using-a-linegeometry)

此示例演示如何使用[LineGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.linegeometry)类，用于描述一个行。 一个[LineGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.linegeometry)由其起点和终点定义。

#### 示例

下面的示例演示如何创建和呈现[LineGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.linegeometry)。 一个[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)使用元素来呈现直线。 行不包含区域，因为[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)对象的[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)未指定; 而是[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.stroke)和[StrokeThickness](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.strokethickness)使用属性。

```xaml
<Path Stroke="Black" StrokeThickness="1" >
  <Path.Data>
    <LineGeometry StartPoint="10,20" EndPoint="100,130" />
  </Path.Data>
</Path>
```

```csharp
LineGeometry myLineGeometry = new LineGeometry();
myLineGeometry.StartPoint = new Point(10,20);
myLineGeometry.EndPoint = new Point(100,130);

Path myPath = new Path();
myPath.Stroke = Brushes.Black;
myPath.StrokeThickness = 1;
myPath.Data = myLineGeometry;
```

![一个 LineGeometry](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-line.gif)
从 (10,20) 绘制到 (100,130) 的 LineGeometry

其他简单的几何类包括[LineGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.linegeometry)和[EllipseGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.ellipsegeometry)。 这些几何形状，以及更复杂的也可以创建使用[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)或[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)。 有关详细信息，请参阅[几何概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/geometry-overview)。

### [Create a LineSegment in a PathGeometry](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-linesegment-in-a-pathgeometry)

此示例演示如何创建一条线段。 若要创建一条线段，请使用[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)， [PathFigure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathfigure)，和[LineSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.linesegment)类。

#### 示例

下面的示例绘制[LineSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.linesegment)从 （10，50） 到 （200，70）。 下图显示了生成[LineSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.linesegment); 已添加网格背景以显示坐标系统。

![PathFigure 中的一个 LineSegment](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-pathgeometrylinesegment.png)
从 (10,50) 绘制到 (200,70) 的 LineSegment

在 可扩展应用程序标记语言 (XAML) 中，可以使用属性语法来描述路径。

```xaml
<Path Stroke="Black" StrokeThickness="1"    
  Data="M 10,50 L 200,70" />  
```

(请注意，此属性语法实际上创建了[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)的轻量版本[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)。 有关详细信息，请参阅[路径标记语法](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/path-markup-syntax)页。）

在 XAML 中，还可以使用对象元素语法来绘制线段。 以下内容等效于之前的 XAML 示例。

```xaml
<Path Stroke="Black" StrokeThickness="1">  
  <Path.Data>  
    <PathGeometry>  
      <PathFigure StartPoint="10,50">  
        <LineSegment Point="200,70" />  
      </PathFigure>  
    </PathGeometry>  
  </Path.Data>  
</Path>  
```

```csharp
PathFigure myPathFigure = new PathFigure();  
myPathFigure.StartPoint = new Point(10, 50);  
  
LineSegment myLineSegment = new LineSegment();  
myLineSegment.Point = new Point(200, 70);  
  
PathSegmentCollection myPathSegmentCollection = new PathSegmentCollection();  
myPathSegmentCollection.Add(myLineSegment);  
  
myPathFigure.Segments = myPathSegmentCollection;  
  
PathFigureCollection myPathFigureCollection = new PathFigureCollection();  
myPathFigureCollection.Add(myPathFigure);  
  
PathGeometry myPathGeometry = new PathGeometry();  
myPathGeometry.Figures = myPathFigureCollection;  
  
Path myPath = new Path();  
myPath.Stroke = Brushes.Black;  
myPath.StrokeThickness = 1;  
myPath.Data = myPathGeometry;  
```

此示例是更大示例的组成部分；有关完整示例，请参阅[几何图形示例](https://go.microsoft.com/fwlink/?LinkID=159989)。

### [Create a Shape by Using a PathGeometry](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-shape-by-using-a-pathgeometry)

此示例演示如何使用创建形状[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)类。 [PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry) 对象组成的一个或多个[PathFigure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathfigure)对象; 每个[PathFigure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathfigure)表示不同"图"或形状。 每个[PathFigure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathfigure)本身由一个或多个[PathSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathsegment)对象，每个资源表示图或形状的一个连接的部分。 线段的类型包括[LineSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.linesegment)， [ArcSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.arcsegment)，和[BezierSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.beziersegment)。

#### 示例

下面的示例使用[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)进而形成一个三角形。 [PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)将显示使用[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)元素。

```xaml
<Path Stroke="Black" StrokeThickness="1">
  <Path.Data>
    <PathGeometry>
      <PathGeometry.Figures>
        <PathFigureCollection>
          <PathFigure IsClosed="True" StartPoint="10,100">
            <PathFigure.Segments>
              <PathSegmentCollection>
                <LineSegment Point="100,100" />
                <LineSegment Point="100,50" />
              </PathSegmentCollection>
            </PathFigure.Segments>
          </PathFigure>
        </PathFigureCollection>
      </PathGeometry.Figures>
    </PathGeometry>
  </Path.Data>
</Path>
```

下图显示在上一个示例中创建的形状。

![PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wcpsdk-graphicsmm-pathgeometry-triangle.gif)
使用 PathGeometry 创建一个三角形

前面的示例介绍了如何创建一个相对简单的形状，一个三角形。 一个[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)还可用于创建更复杂的形状，包括弧线和曲线。 有关示例，请参阅[创建椭圆弧](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-create-an-elliptical-arc)，[创建三次方贝塞尔曲线](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-cubic-bezier-curve)，并[创建二次贝塞尔曲线](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-quadratic-bezier-curve)。

此示例是更大示例的组成部分；有关完整示例，请参阅[几何图形示例](https://go.microsoft.com/fwlink/?LinkID=159989)。

### [Create a Shape Using a StreamGeometry](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-shape-using-a-streamgeometry)

[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry) 是轻量替代[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)对于创建几何形状。 使用[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)何时需要描述复杂几何，但不是希望支持数据绑定、 动画或修改的开销。 例如，由于其效率[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)类是描述装饰器的一个不错选择。

#### 示例

下面的示例使用特性语法创建一个三角形[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)在XAML。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
  <StackPanel>
  
    <Path Data="F0 M10,100 L100,100 100,50Z" 
      StrokeThickness="1" Stroke="Black"/>

  </StackPanel>
</Page>
```

有关详细信息[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)属性的语法，请参阅[路径标记语法](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/path-markup-syntax)页。

#### 示例

下面的示例使用[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)若要在代码中定义一个三角形。 首先，该示例将创建[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)，然后获取[StreamGeometryContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometrycontext)并使用它来描述三角形。

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Shapes;

namespace SDKSample
{
    // Use StreamGeometry with StreamGeometryContext to define a triangle shape.
    public partial class StreamGeometryTriangleExample : Page
    {
        public StreamGeometryTriangleExample()
        {
            // Create a path to draw a geometry with.
            Path myPath = new Path();
            myPath.Stroke = Brushes.Black;
            myPath.StrokeThickness = 1;

            // Create a StreamGeometry to use to specify myPath.
            StreamGeometry geometry = new StreamGeometry();
            geometry.FillRule = FillRule.EvenOdd;

            // Open a StreamGeometryContext that can be used to describe this StreamGeometry 
            // object's contents.
            using (StreamGeometryContext ctx = geometry.Open())
            {
                
                // Begin the triangle at the point specified. Notice that the shape is set to 
                // be closed so only two lines need to be specified below to make the triangle.
                ctx.BeginFigure(new Point(10, 100), true /* is filled */, true /* is closed */);

                // Draw a line to the next specified point.
                ctx.LineTo(new Point(100, 100), true /* is stroked */, false /* is smooth join */);

                // Draw another line to the next specified point.
                ctx.LineTo(new Point(100, 50), true /* is stroked */, false /* is smooth join */);
            }

            // Freeze the geometry (make it unmodifiable)
            // for additional performance benefits.
            geometry.Freeze();

            // Specify the shape (triangle) of the Path using the StreamGeometry.
            myPath.Data = geometry;

            // Add path shape to the UI.
            StackPanel mainPanel = new StackPanel();
            mainPanel.Children.Add(myPath);
            this.Content = mainPanel;
        }
    }
}
```

#### 示例

下一个示例创建一个方法，使用[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)和[StreamGeometryContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometrycontext)定义几何形状基于指定的参数。

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Shapes;

namespace SDKSample
{
    public partial class StreamGeometryExample : Page
    {
        public StreamGeometryExample()
        {
            // Create a path to draw a geometry with.
            Path myPath = new Path();
            myPath.Stroke = Brushes.Black;
            myPath.StrokeThickness = 1;

            // Create a StreamGeometry to use to specify myPath.
            StreamGeometry theGeometry = BuildRegularPolygon(new Point(200, 200), 200, 8, 0);
            theGeometry.FillRule = FillRule.EvenOdd;

            // Freeze the geometry (make it unmodifiable)
            // for additional performance benefits.
            theGeometry.Freeze();

            // Use the StreamGeometry returned by the BuildRegularPolygon to 
            // specify the shape of the path.
            myPath.Data = theGeometry;

            // Add path shape to the UI.
            StackPanel mainPanel = new StackPanel();
            mainPanel.Children.Add(myPath);
            this.Content = mainPanel;
        }

        StreamGeometry BuildRegularPolygon(Point c, double r, int numSides, double offsetDegree)
        {
            // c is the center, r is the radius,
            // numSides the number of sides, offsetDegree the offset in Degrees.
            // Do not add the last point.

            StreamGeometry geometry = new StreamGeometry();

            using (StreamGeometryContext ctx = geometry.Open())
            {
                ctx.BeginFigure(new Point(), true /* is filled */, true /* is closed */);

                double step = 2 * Math.PI / Math.Max(numSides, 3);
                Point cur = c;

                double a = Math.PI * offsetDegree / 180.0;
                for (int i = 0; i < numSides; i++, a += step)
                {
                    cur.X = c.X + r * Math.Cos(a);
                    cur.Y = c.Y + r * Math.Sin(a);
                    ctx.LineTo(cur, true /* is stroked */, false /* is smooth join */);
                }
            }

            return geometry;
        }
    }
}
```

### [Create a Quadratic Bezier Curve](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-quadratic-bezier-curve)

此示例演示如何创建二次贝塞尔曲线。 若要创建二次贝塞尔曲线，使用[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)， [PathFigure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathfigure)，和[QuadraticBezierSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.quadraticbeziersegment)类。

#### 示例

在以下示例中，从 (10100) 到 (300100) 绘制二次贝塞尔曲线。 该曲线的控制点为 (200200)。

在可扩展应用程序标记语言 (XAML)，可以使用特性语法来描述路径。

```xaml
<Path Stroke="Black" StrokeThickness="1" 
  Data="M 10,100 Q 200,200 300,100" />
```

(请注意，此属性语法实际上创建了[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)的轻量版本[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)。 有关详细信息，请参阅[路径标记语法](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/path-markup-syntax)页。）

在XAML，还可以绘制二次贝塞尔曲线使用对象元素语法。 以下内容等效于之前的 XAML 示例。

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

此示例是更大示例的组成部分；有关完整示例，请参阅[几何图形示例](https://go.microsoft.com/fwlink/?LinkID=159989)。

### [Create an Elliptical Arc](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-create-an-elliptical-arc)

此示例显示了如何绘制椭圆弧。若要创建椭圆弧，使用[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)， [PathFigure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathfigure)，和[ArcSegment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.arcsegment)类。

#### 示例

在以下示例中，从 (10100) 到 (200100) 绘制椭圆弧。 该弧[Size](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.arcsegment.size)100 通过 50 独立于设备的像素为单位的[RotationAngle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.arcsegment.rotationangle)的 45 度[IsLargeArc](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.arcsegment.islargearc)的设置`true`，和一个[SweepDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.arcsegment.sweepdirection)的[Counterclockwise](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.sweepdirection#System_Windows_Media_SweepDirection_Counterclockwise)。

在可扩展应用程序标记语言 (XAML)，可以使用特性语法来描述路径。

```xaml
<Path Stroke="Black" StrokeThickness="1"  
  Data="M 10,100 A 100,50 45 1 0 200,100" />
```

(请注意，此属性语法实际上创建了[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)的轻量版本[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)。 有关详细信息，请参阅[路径标记语法](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/path-markup-syntax)页。）

在XAML，还可以通过显式使用对象标记绘制椭圆弧。 以下是等效于上述XAML标记。

```xaml
<Path Stroke="Black" StrokeThickness="1">
  <Path.Data>
    <PathGeometry>
      <PathGeometry.Figures>
        <PathFigureCollection>
          <PathFigure StartPoint="10,100">
            <PathFigure.Segments>
              <PathSegmentCollection>
                <ArcSegment Size="100,50" RotationAngle="45" IsLargeArc="True" SweepDirection="CounterClockwise" Point="200,100" />
              </PathSegmentCollection>
            </PathFigure.Segments>
          </PathFigure>
        </PathFigureCollection>
      </PathGeometry.Figures>
    </PathGeometry>
  </Path.Data>
</Path>
```

此示例摘自一个更大的示例。 有关完整示例，请参阅[几何图形示例](https://go.microsoft.com/fwlink/?LinkID=159989)。

### [Create Multiple Subpaths Within a PathGeometry](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-create-multiple-subpaths-within-a-pathgeometry)

此示例演示如何创建在多个子路径[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)。 若要创建多个子路径，您创建[PathFigure](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathfigure)每一子路径。

#### 示例

以下示例创建两个子路径，每个三角形。

```xaml
<Path Stroke="Black" StrokeThickness="1">
  <Path.Data>
    <PathGeometry>
      <PathGeometry.Figures>
        <PathFigureCollection>
          <PathFigure IsClosed="True" StartPoint="10,100">
            <PathFigure.Segments>
              <PathSegmentCollection>
                <LineSegment Point="100,100" />
                <LineSegment Point="100,50" />
              </PathSegmentCollection>
            </PathFigure.Segments>
          </PathFigure>
          <PathFigure IsClosed="True" StartPoint="10,10">
            <PathFigure.Segments>
              <PathSegmentCollection>
                <LineSegment Point="100,10" />
                <LineSegment Point="100,40" />
              </PathSegmentCollection>
            </PathFigure.Segments>
          </PathFigure>                    
        </PathFigureCollection>
      </PathGeometry.Figures>
    </PathGeometry>
  </Path.Data>
</Path>
```

下面的示例演示如何使用创建多个子路径[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)和XAML特性语法。 每个`M`，以便此示例将创建一个三角形的两个子路径创建一个新的子路径。

```xaml
<Path Stroke="Black" StrokeThickness="1" 
  Data="M 10,100 L 100,100 100,50 Z M 10,10 100,10 100,40 Z" />
```

(请注意，此属性语法实际上创建了[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)的轻量版本[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)。 有关详细信息，请参阅[路径标记语法](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/path-markup-syntax)页。）

### [Define a Rectangle Using a RectangleGeometry](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-define-a-rectangle-using-a-rectanglegeometry)

此示例介绍了如何使用[RectangleGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rectanglegeometry)类，用于描述一个矩形。

#### 示例

下面的示例演示如何创建和呈现[RectangleGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rectanglegeometry)。 通过定义相对位置和矩形的尺寸[Rect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.rect)结构。 相对位置是`50,50`和高度和宽度均`25`创建一个正方形。 与绘制矩形的内部[LemonChiffon](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brushes.lemonchiffon)用来绘制画笔，它的轮廓[Black](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brushes.black)笔画粗细为`1`。

```xaml
<Path Fill="LemonChiffon" Stroke="Black" StrokeThickness="1">
  <Path.Data>
    <RectangleGeometry Rect="50,50,25,25" />
  </Path.Data>
</Path>
```

```csharp
RectangleGeometry myRectangleGeometry = new RectangleGeometry();    
myRectangleGeometry.Rect = new Rect(50,50,25,25);

Path myPath = new Path();
myPath.Fill = Brushes.LemonChiffon;
myPath.Stroke = Brushes.Black;
myPath.StrokeThickness = 1;
myPath.Data = myRectangleGeometry;
```

![一个 RectangleGeometry](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-rectangle.gif)
RectangleGeometry

虽然此示例使用了[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)元素来呈现[RectangleGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rectanglegeometry)，有许多其他方法来使用[RectangleGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rectanglegeometry)对象。 例如，[RectangleGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rectanglegeometry)可用于指定[Clip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.clip)的[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)或[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometrydrawing.geometry)的[GeometryDrawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometrydrawing)。

其他简单的几何类包括[LineGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.linegeometry)和[EllipseGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.ellipsegeometry)。 这些几何形状，以及更复杂的也可以创建使用[PathGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pathgeometry)或[StreamGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.streamgeometry)。

### [Round the Corners of a RectangleGeometry](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-round-the-corners-of-a-rectanglegeometry)

要舍入的边角[RectangleGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rectanglegeometry)，请将其[RadiusX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rectanglegeometry.radiusx)和[RadiusY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rectanglegeometry.radiusy)属性设置为大于零的值。 值越大，1 之间的矩形的角。

#### 示例

下面的示例显示了一些[RectangleGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rectanglegeometry)具有不同的对象[RadiusX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rectanglegeometry.radiusx)和[RadiusY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rectanglegeometry.radiusy)设置。 [RectangleGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rectanglegeometry)对象会显示使用[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.path)元素。

```xaml
<Page
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  x:Class="GeoOvwSample.RectangleGeometryRoundedCornerExample">

  <Page.Resources>
  
    <!-- Create a grid background to highlight the
         coordinate system. -->
    <DrawingBrush x:Key="GridDrawingBrushResource" 
      Viewport="0,0,10,10" 
      ViewportUnits="Absolute" TileMode="Tile">
      <DrawingBrush.Drawing>
        <DrawingGroup>
          <DrawingGroup.Children>
            <GeometryDrawing Brush="White">
              <GeometryDrawing.Geometry>
                <RectangleGeometry Rect="0,0,1,1" />
              </GeometryDrawing.Geometry>
            </GeometryDrawing>
            <GeometryDrawing Geometry="M0,0 L1,0 1,0.1, 0,0.1Z" Brush="#CCCCFF" />
            <GeometryDrawing Geometry="M0,0 L0,1 0.1,1, 0.1,0Z" Brush="#CCCCFF" />
          </DrawingGroup.Children>
        </DrawingGroup>
      </DrawingBrush.Drawing>
    </DrawingBrush>

    <!-- Create a graph paper style border to frame the rectangles. -->
    <Style x:Key="GraphPaperBorderStyle" TargetType="{x:Type Border}">
      <Setter Property="HorizontalAlignment" Value="Left" />
      <Setter Property="Background" 
        Value="{StaticResource GridDrawingBrushResource}" />
      <Setter Property="BorderBrush" Value="Black" />
      <Setter Property="BorderThickness" Value="1" />
      <Setter Property="Margin" Value="10" />
      <Setter Property="Width" Value="190" />
      <Setter Property="Height" Value="90" />
    </Style>
  </Page.Resources>

  <StackPanel Name="MainStackPanel">

    <Border Style="{StaticResource GraphPaperBorderStyle}">
      <Path Stroke="Black" 
        StrokeThickness="1"
        Fill="#99CCCCFF">
        <Path.Data>

          <!-- Create a rectangle without rounded corners.  -->
          <RectangleGeometry
            Rect="20,20,150,50"  />
        </Path.Data>
      </Path>
    </Border>

    <Border Style="{StaticResource GraphPaperBorderStyle}">
      <Path Stroke="Black" 
        StrokeThickness="1"
        Fill="#99CCCCFF">
        <Path.Data>

          <!-- Create a rectangle with rounded corners
             by giving the RectangleGeometry a RadiusX
             and a RadiusY of 10.  -->
          <RectangleGeometry
            Rect="20,20,150,50" RadiusX="10" RadiusY="10" />
        </Path.Data>
      </Path>
    </Border>

    <Border Style="{StaticResource GraphPaperBorderStyle}" >
      <Path Stroke="Black" 
        StrokeThickness="1"
        Fill="#99CCCCFF">
        <Path.Data>

          <!-- Set RadiusX and RadiusY to their maximum values 
             (half the rectangle's width and 
              half the rectangle's height).  -->
          <RectangleGeometry
            Rect="20,20,150,50" RadiusX="75" RadiusY="25"  />
        </Path.Data>
      </Path>
    </Border>

  </StackPanel>
</Page>
```

![使用不同的 RadiusX 矩形/RadiusY 设置](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/graphicsmm-rounded.png)
圆角矩形