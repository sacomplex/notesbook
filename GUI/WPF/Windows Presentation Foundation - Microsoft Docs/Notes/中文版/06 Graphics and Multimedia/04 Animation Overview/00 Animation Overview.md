# [Animation Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/animation-overview)

Windows Presentation Foundation (WPF) 提供了一组强大的图形和布局功能，使您能够创建极具吸引力的用户界面和有吸引力的文档。 动画不仅可以使引起注意的用户界面更加引人注目，还可以使其更加便于使用。 只需对背景色进行动画处理或应用动画的[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transform)，可以创建出生动的屏幕转换，也可以提供有帮助的视觉提示。

本概述介绍了WPF动画和计时系统。 它主要关注的动画WPF使用演示图板的对象。

## 动画简介

动画是快速循环播放一系列图像（其中每个图像与下一个图像略微不同）给人造成的一种幻觉。 大脑感觉这组图像是一个变化的场景。 在电影中，摄像机每秒钟拍摄许多照片（帧），便可使人形成这种幻觉。 用投影仪播放这些帧时，观众便可以看电影了。

计算机上的动画与此类似。 例如，使一个矩形图形逐渐从视野中消失的程序可能按以下方式工作。

- 程序创建一个计时器。
- 程序按照设定的时间间隔检查计时器以查看经历了多长时间。
- 程序每次检查计时器时，它将根据经历的时间来计算矩形的当前不透明度值。
- 然后，程序用新值更新矩形并重画此矩形。

早于WPF，Microsoft Windows开发人员必须创建和管理其自己的计时系统或使用特殊的自定义库。 WPF 包括通过托管代码公开的高效计时系统和可扩展应用程序标记语言 (XAML)和的紧密地集成到WPF框架。 通过使用 WPF动画，可以轻松地对控件和其他图形对象进行动画处理。

WPF 可以高效地处理管理计时系统和重绘屏幕的所有后台任务。 它提供了计时类，使用户能够重点关注要创造的效果，而非实现这些效果的机制。 此外，WPF 通过公开动画基类（你使用的类可以继承这些类）可以轻松创建自己的动画，这样便可以制作自定义动画。 这些自定义动画获得了标准动画类的许多性能优点。

## WPF 属性动画系统

如果您了解关于计时系统的一些重要概念WPF动画可以是易于使用。 最重要是，在WPF，通过将动画应用于其各个属性动态显示对象。 例如，若要使框架元素增大，进行动画处理其[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)和[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)属性。 若要使从视图淡入的对象，动画处理其[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)属性。

若要使属性具有动画功能，属性必须满足以下三个要求：

- 它必须是依赖属性。
- 它必须属于继承的类[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)并实现[IAnimatable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.ianimatable)接口。
- 必须存在可用的兼容动画类型。 (如果WPF未提供，可以创建你自己。 请参阅[自定义动画概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/custom-animations-overview)。)

WPF 包含具有的许多对象[IAnimatable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.ianimatable)属性。 控件，如[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)并[TabControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tabcontrol)，以及[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)并[Shape](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape)对象继承自[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)。 其中大多数属性都是依赖属性。

几乎可以在任何地方使用动画，包括在样式和控件模板中使用。 动画未必可见；如果不属于用户界面的对象满足本部分中所述的条件，则可以对其进行动画处理。

## 示例：使元素逐渐进入视野并从视野中逐渐消失

此示例演示如何使用WPF动画进行动画处理的依赖项属性的值。 它使用[DoubleAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation)，这是一种生成的动画[Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double)值进行动画处理[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)属性的[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)。 因此，[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)淡入淡出视图。

该示例的第一部分创建[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)元素。 遵循的步骤说明如何创建动画，并将其应用于矩形的[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)属性。

以下示例演示如何创建[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)中的元素[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)在 XAML 中。

```xaml
<StackPanel Margin="10">
    <Rectangle
        Name="MyRectangle"
        Width="100" 
        Height="100"
        Fill="Blue">
    </Rectangle>
</StackPanel>
```

以下示例演示如何创建[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)中的元素[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)在代码中。

```csharp
StackPanel myPanel = new StackPanel();
myPanel.Margin = new Thickness(10);

Rectangle myRectangle = new Rectangle();
myRectangle.Name = "myRectangle";
this.RegisterName(myRectangle.Name, myRectangle);
myRectangle.Width = 100;
myRectangle.Height = 100;
myRectangle.Fill = Brushes.Blue;
myPanel.Children.Add(myRectangle);
this.Content = myPanel;
```



### 第 1 部分：创建 DoubleAnimation

若要使淡入和移出视图元素的一种方法是要进行动画处理其[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)属性。 因为[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)属性属于类型[Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double)，需要生成双精度值的动画。 一个[DoubleAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation)是这样的一个动画。 一个[DoubleAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation)创建两个双精度值之间的转换。 若要指定其起始值，请设置其[From](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation.from)属性。 若要指定其终止值，请设置其[To](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation.to)属性。

1. 不透明度值`1.0`使对象完全不透明，且不透明度值为`0.0`使完全不可见。 可以从动画过渡`1.0`到`0.0`将其[From](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation.from)属性设置为`1.0`并将其[To](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation.to)属性设置为`0.0`。 以下示例演示如何创建[DoubleAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation)在 XAML 中。

   ```xaml
   <DoubleAnimation From="1.0" To="0.0" />
   ```

   以下示例演示如何创建[DoubleAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation)在代码中。

   ```csharp
   DoubleAnimation myDoubleAnimation = new DoubleAnimation();
   myDoubleAnimation.From = 1.0;
   myDoubleAnimation.To = 0.0;
   ```

2. 接下来，必须指定[Duration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.duration)。 [Duration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.duration)动画的指定从其起始值转到其目标值所需的时间长度。 以下示例演示如何设置[Duration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.duration)为 XAML 中的五秒。

   ```xaml
   <DoubleAnimation From="1.0" To="0.0" Duration="0:0:5" />
   ```

   以下示例演示如何设置[Duration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.duration)到代码中的五秒。

   ```csharp
   myDoubleAnimation.Duration = new Duration(TimeSpan.FromSeconds(5));
   ```

3. 上面的代码显示从转换的动画`1.0`到`0.0`，这将导致目标元素从完全不透明逐渐转变为完全不可见。 若要使元素后再逐渐回到视野，设置[AutoReverse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.autoreverse)到动画属性`true`。 若要使动画无限期地重复，设置其[RepeatBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.repeatbehavior)属性设置为[Forever](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.repeatbehavior.forever)。以下示例演示如何设置[AutoReverse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.autoreverse)和[RepeatBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.repeatbehavior)XAML 中的属性。

   ```xaml
   <DoubleAnimation From="1.0" To="0.0" Duration="0:0:5" AutoReverse="True" RepeatBehavior="Forever"/>
   ```

   以下示例演示如何设置[AutoReverse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.autoreverse)和[RepeatBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.repeatbehavior)代码中的属性。

   ```csharp
   myDoubleAnimation.AutoReverse = true;
   myDoubleAnimation.RepeatBehavior = RepeatBehavior.Forever;
   ```

### 第 2 部分：创建演示图板

若要向对象应用动画，您创建[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)并用[TargetName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard.targetname)和[TargetProperty](https://msdn.microsoft.com/library/system.windows.media.animation.storyboard.targetproperty.aspx)附加属性指定的对象和属性进行动画处理。

1. 创建[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)和将动画添加为子项。 以下示例演示如何创建[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)在 XAML 中。

   ```xaml
   <Storyboard>
       <DoubleAnimation
           From="1.0" To="0.0" Duration="0:0:1" 
           AutoReverse="True" RepeatBehavior="Forever" />
   </Storyboard>
   ```

   若要创建[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)在代码中，声明[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)在类级别变量。

   ```csharp
   public partial class MainWindow : Window
   {
       private Storyboard myStoryboard;
   ```

   然后初始化[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)和将动画添加为子项。

   ```csharp
   myStoryboard = new Storyboard();
   myStoryboard.Children.Add(myDoubleAnimation);
   ```

2. [Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)必须知道应用动画的位置。 使用[Storyboard.TargetName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard.targetname)附加属性指定要进行动画处理的对象。以下示例演示如何设置的目标名称[DoubleAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation)到`MyRectangle`在 XAML 中。

   ```xaml
   <Storyboard>
       <DoubleAnimation
           Storyboard.TargetName="MyRectangle" 
           From="1.0" To="0.0" Duration="0:0:1" 
           AutoReverse="True" RepeatBehavior="Forever" />
   </Storyboard>
   ```

   以下示例演示如何设置的目标名称[DoubleAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation)到`MyRectangle`在代码中。

   ```csharp
   Storyboard.SetTargetName(myDoubleAnimation, myRectangle.Name);
   ```

3. 使用[TargetProperty](https://msdn.microsoft.com/library/system.windows.media.animation.storyboard.targetproperty.aspx)附加属性指定要进行动画处理的属性。 下面演示了如何将动画配置为目标[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)属性的[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)在 XAML 中。

   ```xaml
   <Storyboard>
       <DoubleAnimation
           Storyboard.TargetName="MyRectangle" 
           Storyboard.TargetProperty="Opacity"
           From="1.0" To="0.0" Duration="0:0:5" 
           AutoReverse="True" RepeatBehavior="Forever" />
   </Storyboard>
   ```

   下面演示了如何将动画配置为目标[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)属性的[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)在代码中。

   ```csharp
   Storyboard.SetTargetProperty(myDoubleAnimation, new PropertyPath(Rectangle.OpacityProperty));
   ```

有关详细信息[TargetProperty](https://msdn.microsoft.com/library/system.windows.media.animation.storyboard.targetproperty.aspx)语法和其他示例，请参阅[演示图板概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/storyboards-overview)。

### 第 3 部分 (XAML)：将演示图板与触发器关联

应用和启动的最简单办法[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)在XAML是使用事件触发器。 本部分演示如何将相关联[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)与 XAML 中的触发器。

1. 创建[BeginStoryboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.beginstoryboard)对象，并将你的情节提要与它相关联。 一个[BeginStoryboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.beginstoryboard)是一种[TriggerAction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.triggeraction)应用和启动[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)。

   ```xaml
   <BeginStoryboard>
     <Storyboard>
       <DoubleAnimation
         Storyboard.TargetName="MyRectangle" 
         Storyboard.TargetProperty="Opacity"
         From="1.0" To="0.0" Duration="0:0:5" 
         AutoReverse="True" RepeatBehavior="Forever" />
     </Storyboard>
   </BeginStoryboard>
   ```

2. 创建[EventTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventtrigger)并添加[BeginStoryboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.beginstoryboard)到其[Actions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventtrigger.actions)集合。 设置[RoutedEvent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventtrigger.routedevent)的属性[EventTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventtrigger)到想要启动的路由事件[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)。 (有关路由事件的详细信息，请参阅[路由事件概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/routed-events-overview)。)

   ```xaml
   <!-- Animates the rectangle's opacity. -->
   <EventTrigger RoutedEvent="Rectangle.Loaded">
     <BeginStoryboard>
       <Storyboard>
         <DoubleAnimation
           Storyboard.TargetName="MyRectangle" 
           Storyboard.TargetProperty="Opacity"
           From="1.0" To="0.0" Duration="0:0:5" 
           AutoReverse="True" RepeatBehavior="Forever" />
       </Storyboard>
     </BeginStoryboard>
   </EventTrigger>
   ```

3. 添加[EventTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventtrigger)到[Triggers](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.triggers)矩形的集合。

   ```xaml
   <Rectangle
     Name="MyRectangle"
     Width="100" 
     Height="100"
     Fill="Blue">
     <Rectangle.Triggers>
       <!-- Animates the rectangle's opacity. -->
       <EventTrigger RoutedEvent="Rectangle.Loaded">
         <BeginStoryboard>
           <Storyboard>
             <DoubleAnimation
               Storyboard.TargetName="MyRectangle" 
               Storyboard.TargetProperty="Opacity"
               From="1.0" To="0.0" Duration="0:0:5" 
               AutoReverse="True" RepeatBehavior="Forever" />
           </Storyboard>
         </BeginStoryboard>
       </EventTrigger>
     </Rectangle.Triggers>
   </Rectangle>
   ```

### 第 3 部分（代码）：将演示图板与事件处理程序关联

应用和启动的最简单办法[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)在代码中是使用事件处理程序。 本部分演示如何将相关联[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)与代码中的事件处理程序。

1. 注册[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)矩形的事件。

   ```csharp
   myRectangle.Loaded += new RoutedEventHandler(myRectangleLoaded);
   ```

2. 声明事件处理程序。 在事件处理程序，使用[Begin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard.begin)方法来应用演示图板。

   ```csharp
   private void myRectangleLoaded(object sender, RoutedEventArgs e)
   {
       myStoryboard.Begin(this);
   }
   ```

### 完整的示例

下面演示了如何创建逐渐进入视野并从 XAML 中逐渐消失的矩形。

```xaml
<Window x:Class="WpfApplication1.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        Title="MainWindow" Height="350" Width="525">
    <Grid>
        <StackPanel Margin="10">
            <Rectangle
                Name="MyRectangle"
                Width="100" 
                Height="100"
                Fill="Blue">
                <Rectangle.Triggers>
                    <!-- Animates the rectangle's opacity. -->
                    <EventTrigger RoutedEvent="Rectangle.Loaded">
                        <BeginStoryboard>
                            <Storyboard>
                                <DoubleAnimation
                                    Storyboard.TargetName="MyRectangle" 
                                    Storyboard.TargetProperty="Opacity"
                                    From="1.0" To="0.0" Duration="0:0:5" 
                                    AutoReverse="True" RepeatBehavior="Forever" />
                            </Storyboard>
                        </BeginStoryboard>
                    </EventTrigger>
                </Rectangle.Triggers>
            </Rectangle>
        </StackPanel>
    </Grid>
</Window>
```

下面演示了如何在代码中创建逐渐进入视野并从视野中逐渐消失的矩形。

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Shapes;
using System.Windows.Media.Animation;

namespace WpfApplication1
{
    public partial class MainWindow : Window
    {
        private Storyboard myStoryboard;

        public MainWindow()
        {
            InitializeComponent();

            StackPanel myPanel = new StackPanel();
            myPanel.Margin = new Thickness(10);

            Rectangle myRectangle = new Rectangle();
            myRectangle.Name = "myRectangle";
            this.RegisterName(myRectangle.Name, myRectangle);
            myRectangle.Width = 100;
            myRectangle.Height = 100;
            myRectangle.Fill = Brushes.Blue;

            DoubleAnimation myDoubleAnimation = new DoubleAnimation();
            myDoubleAnimation.From = 1.0;
            myDoubleAnimation.To = 0.0;
            myDoubleAnimation.Duration = new Duration(TimeSpan.FromSeconds(5));
            myDoubleAnimation.AutoReverse = true;
            myDoubleAnimation.RepeatBehavior = RepeatBehavior.Forever;

            myStoryboard = new Storyboard();
            myStoryboard.Children.Add(myDoubleAnimation);
            Storyboard.SetTargetName(myDoubleAnimation, myRectangle.Name);
            Storyboard.SetTargetProperty(myDoubleAnimation, new PropertyPath(Rectangle.OpacityProperty));

            // Use the Loaded event to start the Storyboard.
            myRectangle.Loaded += new RoutedEventHandler(myRectangleLoaded);
            myPanel.Children.Add(myRectangle);
            this.Content = myPanel;
        }

        private void myRectangleLoaded(object sender, RoutedEventArgs e)
        {
            myStoryboard.Begin(this);
        }
    }
}
```

## 动画类型

由于动画生成属性值，因此不同的属性类型具有不同的动画类型。 若要对采用的属性进行动画处理[Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double)，如[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)属性的元素，使用生成的动画，[Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double)值。 若要对采用的属性进行动画处理[Point](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.point)，使用生成的动画，[Point](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.point)值，等等。 由于存在许多不同的属性类型，有一些动画类中的[System.Windows.Media.Animation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation)命名空间。 幸运的是，它们都遵循严格的命名约定，因此可以轻松地区分它们：

- <*类型*> 动画

  这些动画称为“From/To/By”或“基本”动画，它们在起始值和目标值之间进行动画处理，或者通过将偏移量值与其起始值相加来进行动画处理。

  - 若要指定起始值，请设置动画的“From”属性。
  - 若要指定终止值，请设置动画的“To”属性。
  - 若要指定偏移量值，请设置动画的“By”属性。

  此概述中的示例使用这些动画，因为这些动画使用起来最简单。 From/To/By 动画 From/To/By 动画概述中详细介绍。

- <*类型*> AnimationUsingKeyFrames

  关键帧动画的功能比“From/To/By”动画的功能更强大，因为可以指定任意多个目标值，甚至可以控制它们的插值方法。 某些类型只能用关键帧动画进行动画处理。 中详细描述了关键帧动画[关键帧动画概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/key-frame-animations-overview)。

- <*类型*> AnimationUsingPath

  路径动画支持使用几何路径来生成动画值。

- <*类型*> AnimationBase

  抽象类在实现时进行动画处理<*类型*> 值。 此类用作类的基类<*类型*> 动画并<*类型*> AnimationUsingKeyFrames 类。 只有在想要创建自己的自定义动画时，才需要直接处理这些类。 否则，请使用<*类型*> 动画或关键帧<*类型*> 动画。

在大多数情况下，你将想要使用<*类型*> 动画类，如[DoubleAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation)和[ColorAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.coloranimation)。

下表显示了一些常用动画类型以及一些与这些类型一起使用的属性。

| 属性类型                                                     | 对应的基本 (From/To/By) 动画                                 | 对应的关键帧动画                                             | 对应的路径动画                                               | 用法示例                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| [Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.color) | [ColorAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.coloranimation) | [ColorAnimationUsingKeyFrames](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.coloranimationusingkeyframes) | 无                                                           | 进行动画处理[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush.color)的[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)或[GradientStop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientstop)。 |
| [Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double) | [DoubleAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation) | [DoubleAnimationUsingKeyFrames](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimationusingkeyframes) | [DoubleAnimationUsingPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimationusingpath) | 进行动画处理[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)的[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)或[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)的[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。 |
| [Point](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.point) | [PointAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.pointanimation) | [PointAnimationUsingKeyFrames](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.pointanimationusingkeyframes) | [PointAnimationUsingPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.pointanimationusingpath) | 进行动画处理[Center](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.ellipsegeometry.center)位置[EllipseGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.ellipsegeometry)。 |
| [String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string) | 无                                                           | [StringAnimationUsingKeyFrames](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.stringanimationusingkeyframes) | 无                                                           | 进行动画处理[Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.text)的[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)或[Content](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.content)的[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。 |

### 动画是时间线

所有动画类型均都继承自[Timeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline)类; 因此，所有动画都是专用的类型的时间线。 一个[Timeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline)定义一个时间段。您可以指定*计时行为*的时间线： 其[Duration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.duration)，它是重复，甚至快时间走得多少次。

因为动画是[Timeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline)，它还表示时间段。 动画还会计算输出值变为运行其指定的时间段 (或[Duration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.duration))。 在运行或“播放”动画时，动画将更新与其关联的属性。

这三个常用的计时属性[Duration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.duration)， [AutoReverse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.autoreverse)，和[RepeatBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.repeatbehavior)。

#### Duration 属性

如前文所述，时间线表示时间段。 该时间段的长度由[Duration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.duration)时间线，通常通过使用指定的[TimeSpan](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.duration.timespan)值。 当时间线达到其持续时间的终点时，表示时间线完成了一次迭代。

动画使用其[Duration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.duration)属性来确定其当前值。 如果未指定[Duration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.duration)值的动画，它使用 1 秒，这是默认值。

下面的语法演示的简化的版本可扩展应用程序标记语言 (XAML)特性语法[Duration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.duration)属性。

*小时* `:` *分钟* `:` *秒*

下表显示了几个[Duration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.duration)设置及其所得的值。

| 设置     | 所得值                |
| -------- | --------------------- |
| 0:0:5.5  | 5.5 秒。              |
| 0:30:5.5 | 30 分 5.5 秒。        |
| 1:30:5.5 | 1 小时 30 分 5.5 秒。 |

指定的一种方法[Duration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.duration)代码中是使用[FromSeconds](https://docs.microsoft.com/zh-cn/dotnet/api/system.timespan.fromseconds)方法来创建[TimeSpan](https://docs.microsoft.com/zh-cn/dotnet/api/system.timespan)，然后，声明一个新[Duration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.duration)结构在使用该[TimeSpan](https://docs.microsoft.com/zh-cn/dotnet/api/system.timespan)。

有关详细信息[Duration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.duration)值和完整可扩展应用程序标记语言 (XAML)语法，请参阅[Duration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.duration)结构。

#### AutoReverse

[AutoReverse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.autoreverse)属性指定时间线的向后播放到达结束后其[Duration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.duration)。 如果此动画属性设置为`true`，动画反转到达结束后其[Duration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.duration)、 播放从其终止值回其起始值。 默认情况下，此属性是`false`。

#### RepeatBehavior

[RepeatBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.repeatbehavior)属性指定时间线播放的次数。 默认情况下，时间线具有的迭代次数为`1.0`，即播放一次，根本不进行重复。

有关这些属性和其他工具的详细信息，请参阅[计时行为概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/timing-behaviors-overview)。

## 对属性应用动画

前面部分介绍了动画的不同类型及其计时属性。 本部分演示如何对要进行动画处理的属性应用动画。 [Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)对象提供对属性应用动画的一种方法。 一个[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)是*容器时间线*，提供它所包含的动画的目标信息。

### 以对象和属性为目标

[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)类提供了[TargetName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard.targetname)和[TargetProperty](https://msdn.microsoft.com/library/system.windows.media.animation.storyboard.targetproperty.aspx)附加属性。 通过在动画上设置这些属性，告诉动画对哪些内容进行动画处理。 但是，通常必须为对象提供一个名称，动画才能以该对象作为目标。

分配将名称传递给[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)不同于分配将名称传递给[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)对象。 大多数控件和面板是框架元素；而大多数纯图形对象（如画笔、转换和几何图形）是 Freezable 对象。 如果您不确定某个类型是[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)或[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)，请参阅**继承层次结构**参考文档的部分。

- 若要使[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)成为动画目标，您为其提供一个名称通过设置其[Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.name)属性。 在代码中，您必须使用[RegisterName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.registername)方法以向其所属的页面注册的元素名称。
- 若要使[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)对象中的动画目标XAML，则使用[X:name 指令](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-name-directive)以将其分配一个名称。 在代码中，您只需使用[RegisterName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.registername)方法以向其所属的页面注册该对象。

以下各节提供的命名中的元素示例XAML和代码。 有关命名和设定目标的更多详细信息，请参阅[情节提要概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/storyboards-overview)。

### 应用和启动演示图板

若要在启动情节提要XAML，将其与[EventTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventtrigger)。 [EventTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventtrigger)是一个对象，描述当发生指定的事件时要执行的操作。 其中一个操作可以是[BeginStoryboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.beginstoryboard)操作，你用于启动你的情节提要。 事件触发器与事件处理程序的概念类似，因为通过它们可以指定应用程序响应特定事件的方式。 事件触发器可以与不同的事件处理程序中详细介绍了XAML; 不不需要任何其他代码。

若要启动[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)在代码中，可以使用[EventTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventtrigger)或使用[Begin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard.begin)方法的[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)类。

## 以交互方式控制演示图板

前面的示例介绍了如何启动[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)事件的发生时间。 您可以采用交互方式控制[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)启动后对它： 可以暂停、 恢复、 停止、 转到其填充期、 搜索和删除[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)。 有关详细信息和示例，演示如何以交互方式控制[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)，请参阅[演示图板概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/storyboards-overview)。

## 动画结束后，会发生什么情况？

[FillBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.fillbehavior)属性指定时间线结束时的行为方式。 默认情况下，时间线开始[Filling](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clockstate#System_Windows_Media_Animation_ClockState_Filling)结束的时候。 是的动画[Filling](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clockstate#System_Windows_Media_Animation_ClockState_Filling)保持其最终输出值。

[DoubleAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation)上一示例中不会终止，因为其[RepeatBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.repeatbehavior)属性设置为[Forever](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.repeatbehavior.forever)。 下面的示例使用类似的动画对矩形进行动画处理。 与上述示例中，不同[RepeatBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.repeatbehavior)和[AutoReverse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.autoreverse)此动画的属性保留为其默认值。 因此，动画运行五秒钟使其不透明度值从 1 转变成 0，然后停止。

```xaml
<Rectangle
  Name="MyRectangle"
  Width="100" 
  Height="100"
  Fill="Blue">
  <Rectangle.Triggers>

    <!-- Animates the rectangle's opacity. -->
    <EventTrigger RoutedEvent="Rectangle.Loaded">
      <BeginStoryboard>
        <Storyboard>
          <DoubleAnimation
            Storyboard.TargetName="MyRectangle" 
            Storyboard.TargetProperty="Opacity"
            From="1.0" To="0" Duration="0:0:5" />
        </Storyboard>
      </BeginStoryboard>
    </EventTrigger>
  </Rectangle.Triggers>
</Rectangle>
```

```csharp
DoubleAnimation myDoubleAnimation = new DoubleAnimation();
myDoubleAnimation.From = 1.0;
myDoubleAnimation.To = 0.0;
myDoubleAnimation.Duration = new Duration(TimeSpan.FromSeconds(5));
```

因为其[FillBehavior](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.fillbehavior)未发生变化，其默认值，即[HoldEnd](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.fillbehavior#System_Windows_Media_Animation_FillBehavior_HoldEnd)，动画将保持最终值为 0，结束时。 因此，[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)矩形仍然为动画之后的 0 的结束。 如果您设置[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)的矩形与另一个值，你的代码似乎不起作用，因为动画仍将影响[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)属性。

若要重新获得的代码中的动画属性控制权的一种方法是使用[BeginAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animatable.beginanimation)方法并指定为 null[AnimationTimeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.animationtimeline)参数。 有关详细信息和示例，请参阅[后设置该属性进行动画处理使用演示图板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-set-a-property-after-animating-it-with-a-storyboard)。

请注意，虽然设置属性值不起[Active](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clockstate#System_Windows_Media_Animation_ClockState_Active)或[Filling](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clockstate#System_Windows_Media_Animation_ClockState_Filling)动画似乎不起作用，属性值确实更改。 有关详细信息，请参阅[动画和计时系统概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/animation-and-timing-system-overview)。

## 对动画进行数据绑定和动画处理

大多数动画属性可以是数据绑定或动画处理;例如，您可以进行动画处理[Duration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.duration)属性的[DoubleAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation)。 但是，由于计时系统工作方式的缘故，进行了数据绑定和动画处理的动画的行为与其他进行了数据绑定和动画处理的对象不同。 若要了解它们的行为，请了解对属性应用动画的意义，这将十分有用。

介绍了如何进行动画处理的上一节中的示例，请参阅[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)的矩形。 加载上一示例中的矩形时，它的事件触发器适用[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)。 计时系统会创建一份[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)及其动画。 这些副本均已冻结 （使只读的） 和[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock)根据它们来创建对象。 这些时钟将执行对目标属性进行动画处理的实际工作。

计时系统创建时钟[DoubleAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation)并将其应用到的对象和由指定的属性[TargetName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard.targetname)并[TargetProperty](https://msdn.microsoft.com/library/system.windows.media.animation.storyboard.targetproperty.aspx)的[DoubleAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation)。 在这种情况下，计时系统应用到时钟[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)名为"MyRectangle。"的对象属性

尽管还为创建一个时钟[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)，时钟不应用于任何属性。 其目的是控制其子时钟，为创建的时钟[DoubleAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation)。

若要使动画反映数据绑定或动画更改，必须重新生成时钟。 时钟不会自动重新生成。 若要使动画反映更改，重新通过应用其情节提要[BeginStoryboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.beginstoryboard)或[Begin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard.begin)方法。 当使用其中一种方法时，动画将重新启动。 在代码中，可以使用[Seek](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard.seek)方法将演示图板移回其之前的位置。

有关数据的示例绑定动画，请参见[密钥样条动画示例](https://go.microsoft.com/fwlink/?LinkID=160011)。 有关动画和计时系统的工作原理的详细信息，请参阅[动画和计时系统概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/animation-and-timing-system-overview)。

## 其他动画处理方式

此概述中的示例演示如何使用演示图板进行动画处理。 如果使用代码，可以采用一些其他方法进行动画处理。 有关详细信息，请参阅[属性动画技术概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/property-animation-techniques-overview)。

## 动画示例

以下示例有助于开始向应用程序添加动画。

- [From、To 和 By 动画目标值示例](https://go.microsoft.com/fwlink/?LinkID=159988)

  演示不同的 From/To/By 设置。

- [动画计时行为示例](https://go.microsoft.com/fwlink/?LinkID=159970)

  演示可控制动画计时行为的不同方法。 此示例还演示如何对动画的目标值进行数据绑定。

## 相关主题

| 标题                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [动画和计时系统概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/animation-and-timing-system-overview) | 描述计时系统如何使用[Timeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline)和[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock)类，允许你创建动画。 |
| [动画提示和技巧](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/animation-tips-and-tricks) | 列出用于解决与动画有关的问题（如性能）的有用提示。           |
| [自定义动画概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/custom-animations-overview) | 描述如何使用关键帧、动画类或逐帧回叫来扩展动画系统。         |
| From/To/By 动画概述                                          | 描述如何创建在两个值之间转换的动画。                         |
| [关键帧动画概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/key-frame-animations-overview) | 描述如何使用多个目标值创建动画（包括控制内插方法的功能）。   |
| [缓动函数](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/easing-functions) | 说明如何将数学公式应用于动画以获得真实行为（如反弹）。       |
| [路径动画概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/path-animations-overview) | 描述如何沿复杂路径移动或旋转对象。                           |
| [属性动画技术概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/property-animation-techniques-overview) | 描述使用演示图板、本地动画、时钟以及逐帧动画的属性动画。     |
| [演示图板概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/storyboards-overview) | 描述如何将演示图板与多个时间线一起使用，以创建复杂动画。     |
| [计时行为概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/timing-behaviors-overview) | 介绍[Timeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline)类型和动画中使用的属性。 |
| [计时事件概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/timing-events-overview) | 介绍可在上找到的事件[Timeline](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline)和[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock)对象的点上执行代码中在时间线，如开始、 暂停、 继续、 跳过，或停止。 |
| [帮助主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/animation-and-timing-how-to-topics) | 包含演示在应用程序中使用动画和时间线的代码示例。             |
| [时钟操作说明主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/clocks-how-to-topics) | 包含代码示例使用[Clock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.clock)在应用程序中的对象。 |
| [关键帧操作说明主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/key-frame-animation-how-to-topics) | 包含在应用程序中使用关键帧动画的代码示例。                   |
| [路径动画操作说明主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/path-animation-how-to-topics) | 包含在应用程序中使用路径动画的代码示例。                     |