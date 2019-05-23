## [Border](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/border)

下面的示例演示如何动态更改的属性[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)元素。

### 本节内容

[对 BorderThickness 值进行动画处理](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-animate-a-borderthickness-value)

### [Animate a BorderThickness Value](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-animate-a-borderthickness-value)

此示例演示如何使用更改对边框的粗细进行动画处理[ThicknessAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.thicknessanimation)类。

#### 示例

下面的示例通过使用进行动画处理对边框的粗细[ThicknessAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.thicknessanimation)。 该示例使用[BorderThickness](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border.borderthickness)属性的[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)。

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Shapes;
using System.Windows.Media.Animation;
using System.Windows.Media;

namespace SDKSamples
{
    public class ThicknessAnimationExample : Page
    {
        public ThicknessAnimationExample()
        {

            // Create a NameScope for this page so that
            // Storyboards can be used.
            NameScope.SetNameScope(this, new NameScope());

            // Create a Border which will be the target of the animation.
            Border myBorder = new Border();
            myBorder.Background = Brushes.Gray;
            myBorder.BorderBrush = Brushes.Black;
            myBorder.BorderThickness = new Thickness(1);
            myBorder.Margin = new Thickness(0, 60, 0, 20);
            myBorder.Padding = new Thickness(20);


            // Assign the border a name so that
            // it can be targeted by a Storyboard.
            this.RegisterName(
                "myAnimatedBorder", myBorder);

            ThicknessAnimation myThicknessAnimation = new ThicknessAnimation();
            myThicknessAnimation.Duration = TimeSpan.FromSeconds(1.5);
            myThicknessAnimation.FillBehavior = FillBehavior.HoldEnd;

            // Set the From and To properties of the animation.
            // BorderThickness animates from left=1, right=1, top=1, and bottom=1 
            // to left=28, right=28, top=14, and bottom=14 over one and a half seconds.
            myThicknessAnimation.From = new Thickness(1, 1, 1, 1);
            myThicknessAnimation.To = new Thickness(28, 14, 28, 14);

            // Set the animation to target the Size property
            // of the object named "myArcSegment."
            Storyboard.SetTargetName(myThicknessAnimation, "myAnimatedBorder");
            Storyboard.SetTargetProperty(
                myThicknessAnimation, new PropertyPath(Border.BorderThicknessProperty));

            // Create a storyboard to apply the animation.
            Storyboard ellipseStoryboard = new Storyboard();
            ellipseStoryboard.Children.Add(myThicknessAnimation);

            // Start the storyboard when the Path loads.
            myBorder.Loaded += delegate(object sender, RoutedEventArgs e)
            {
                ellipseStoryboard.Begin(this);
            };

            StackPanel myStackPanel = new StackPanel();
            myStackPanel.HorizontalAlignment = HorizontalAlignment.Center;
            myStackPanel.Children.Add(myBorder);

            Content = myStackPanel;
        }
    }
}
```

有关完整示例，请参阅[动画示例库](https://go.microsoft.com/fwlink/?LinkID=159969)。

