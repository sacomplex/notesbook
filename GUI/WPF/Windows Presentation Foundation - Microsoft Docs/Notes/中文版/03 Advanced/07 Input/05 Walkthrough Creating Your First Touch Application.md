# [Walkthrough: Creating Your First Touch Application](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/walkthrough-creating-your-first-touch-application)

WPF 使应用程序能够响应触摸。 例如，可以使用一个与应用程序交互或敏式设备，如本演练中创建该应用程序，用户可以移动，触摸屏上的多个手指重设大小，或使用触摸来旋转的单个对象。

## 系统必备

你需要以下组件来完成本演练：

- Visual Studio。
- 接受触控输入，如触摸屏，支持 Windows 触摸设备。

此外，应该基本了解如何创建中的应用程序的WPF，尤其是如何订阅和处理事件。 有关详细信息，请参见[演练：我第一个 WPF 桌面应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/getting-started/walkthrough-my-first-wpf-desktop-application)。

## 创建应用程序

#### 创建应用程序

1. 在 Visual Basic 或 Visual C# 中创建名为 `BasicManipulation` 的新 WPF 应用程序项目。 有关详细信息，请参阅[如何：创建新的 WPF 应用程序项目](https://msdn.microsoft.com/library/1f6aea7a-33e1-4d3f-8555-1daa42e95d82)。

2. MainWindow.xaml 的内容替换为以下 XAML。

   此标记将创建一个简单的应用程序包含一个红色[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)上[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)。 [IsManipulationEnabled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ismanipulationenabled)属性的[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)设置为 true，以便它将接收操作事件。 应用程序订阅[ManipulationStarting](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationstarting)， [ManipulationDelta](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationdelta)，和[ManipulationInertiaStarting](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationinertiastarting)事件。 这些事件包含的逻辑移动[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)用户处理。

   XAML复制

   ```xaml
   <Window x:Class="BasicManipulation.MainWindow"
           xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
           xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
           Title="Move, Size, and Rotate the Square"
           WindowState="Maximized"
           ManipulationStarting="Window_ManipulationStarting"
           ManipulationDelta="Window_ManipulationDelta"
           ManipulationInertiaStarting="Window_InertiaStarting">
     <Window.Resources>
   
       <!--The movement, rotation, and size of the Rectangle is 
           specified by its RenderTransform.-->
       <MatrixTransform x:Key="InitialMatrixTransform">
         <MatrixTransform.Matrix>
           <Matrix OffsetX="200" OffsetY="200"/>
         </MatrixTransform.Matrix>
       </MatrixTransform>
   
     </Window.Resources>
   
     <Canvas>
       <Rectangle Fill="Red" Name="manRect"
                    Width="200" Height="200" 
                    RenderTransform="{StaticResource InitialMatrixTransform}"
                    IsManipulationEnabled="true" />
     </Canvas>
   </Window>
   ```

3. 如果使用的 Visual Basic 中，在 MainWindow.xaml 的第一行中，替换`x:Class="BasicManipulation.MainWindow"`与`x:Class="MainWindow"`。

4. 在中`MainWindow`类中，添加以下[ManipulationStarting](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationstarting)事件处理程序。

   [ManipulationStarting](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationstarting)事件发生时WPF检测到触控输入开始操作对象。 该代码指定操作位置应为相对于[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)通过设置[ManipulationContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.manipulationstartingeventargs.manipulationcontainer)属性。

   C#复制

   ```csharp
   void Window_ManipulationStarting(object sender, ManipulationStartingEventArgs e)
   {
       e.ManipulationContainer = this;
       e.Handled = true;
   }
   ```

5. 在中`MainWindow`类中，添加以下[ManipulationDelta](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.manipulationdelta)事件处理程序。

   [ManipulationDelta](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.manipulationdelta)事件发生时触摸输入更改位置，并可在操作过程中出现多次。 引发一个手指后，也会发生该事件。 例如，如果用户在屏幕上拖动手指[ManipulationDelta](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.manipulationdelta)事件发生多次在手指移动时。 当用户将手指从屏幕上，[ManipulationDelta](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.manipulationdelta)事件会不断发生，以模拟惯性。

   此代码适用[DeltaManipulation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.manipulationdeltaeventargs.deltamanipulation)到[RenderTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransform)的[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)可将其移动用户在将移动触控输入。 它还会检查是否[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)的界限外[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)在惯性期间在事件发生时。 因此，在应用程序调用[ManipulationDeltaEventArgs.Complete](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.manipulationdeltaeventargs.complete)方法来结束操作。

   C#复制

   ```csharp
   void Window_ManipulationDelta(object sender, ManipulationDeltaEventArgs e)
   {
       
       // Get the Rectangle and its RenderTransform matrix.
       Rectangle rectToMove = e.OriginalSource as Rectangle;
       Matrix rectsMatrix = ((MatrixTransform)rectToMove.RenderTransform).Matrix;
   
       // Rotate the Rectangle.
       rectsMatrix.RotateAt(e.DeltaManipulation.Rotation, 
                            e.ManipulationOrigin.X, 
                            e.ManipulationOrigin.Y);
   
       // Resize the Rectangle.  Keep it square 
       // so use only the X value of Scale.
       rectsMatrix.ScaleAt(e.DeltaManipulation.Scale.X, 
                           e.DeltaManipulation.Scale.X, 
                           e.ManipulationOrigin.X,
                           e.ManipulationOrigin.Y);
   
       // Move the Rectangle.
       rectsMatrix.Translate(e.DeltaManipulation.Translation.X,
                             e.DeltaManipulation.Translation.Y);
   
       // Apply the changes to the Rectangle.
       rectToMove.RenderTransform = new MatrixTransform(rectsMatrix);
   
       Rect containingRect =
           new Rect(((FrameworkElement)e.ManipulationContainer).RenderSize);
   
       Rect shapeBounds =
           rectToMove.RenderTransform.TransformBounds(
               new Rect(rectToMove.RenderSize));
   
       // Check if the rectangle is completely in the window.
       // If it is not and intertia is occuring, stop the manipulation.
       if (e.IsInertial && !containingRect.Contains(shapeBounds))
       {
           e.Complete();
       }
   
       
       e.Handled = true;
   }
   ```

6. 在中`MainWindow`类中，添加以下[ManipulationInertiaStarting](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationinertiastarting)事件处理程序。

   [ManipulationInertiaStarting](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationinertiastarting)事件发生时用户将所有手指从屏幕。 该代码设置初始速度和为移动、 扩展和旋转矩形的减速度。

   C#复制

   ```csharp
   void Window_InertiaStarting(object sender, ManipulationInertiaStartingEventArgs e)
   {
   
       // Decrease the velocity of the Rectangle's movement by 
       // 10 inches per second every second.
       // (10 inches * 96 pixels per inch / 1000ms^2)
       e.TranslationBehavior.DesiredDeceleration = 10.0 * 96.0 / (1000.0 * 1000.0);
   
       // Decrease the velocity of the Rectangle's resizing by 
       // 0.1 inches per second every second.
       // (0.1 inches * 96 pixels per inch / (1000ms^2)
       e.ExpansionBehavior.DesiredDeceleration = 0.1 * 96 / (1000.0 * 1000.0);
   
       // Decrease the velocity of the Rectangle's rotation rate by 
       // 2 rotations per second every second.
       // (2 * 360 degrees / (1000ms^2)
       e.RotationBehavior.DesiredDeceleration = 720 / (1000.0 * 1000.0);
   
       e.Handled = true;
   }
   ```

7. 生成并运行该项目。

   应会看到窗口中显示一个红色方块。

## 测试应用程序

若要测试应用程序，请尝试以下操作。 请注意，您可以多个以下项之一在同一时间。

- 若要将移动[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)，将手指放[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)并在屏幕上移动手指。
- 若要调整大小[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)，将两根手指放[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)，并将手指，或将其彼此相差。
- 若要旋转[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)，将两根手指放[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)和旋转相对于每个其他手指。

若要导致延时，快速提升您将手指从屏幕执行上一操作。 [Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)将继续移动、 调整大小，或为几秒钟才会停止旋转。

