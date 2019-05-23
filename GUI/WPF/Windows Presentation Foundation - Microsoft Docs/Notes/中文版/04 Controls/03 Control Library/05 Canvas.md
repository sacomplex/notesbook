## [Canvas](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/canvas)

[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas) 是一种布局控件，使绝对定位子元素。

### 本节内容

[帮助主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/canvas-how-to-topics)

### [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/canvas-how-to-topics)

本部分中的主题介绍如何使用[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)要子元素进行绝对定位元素。

#### 本节内容

[用边框围住画布内容](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-wrap-a-border-around-the-content-of-a-canvas)
[获取或设置画布位置属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-get-or-set-canvas-positioning-properties)
[创建和使用画布](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-create-and-use-a-canvas)
[使用画布的附加属性确定子元素的位置](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-use-the-attached-properties-of-canvas-to-position-child-elements)
[使用 Thumb 重设画布大小](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-resize-a-canvas-by-using-a-thumb)

#### [Wrap a Border Around the Content of a Canvas](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-wrap-a-border-around-the-content-of-a-canvas)

此示例演示如何包装[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)具有元素[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)。

##### 示例

下面的示例演示如何显示`Hello World!`内[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)元素。 [Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)由包装元素[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)元素，以便边框概述了该元素。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation">
  <Border
    BorderThickness="2"
    BorderBrush="Black"
    Background="LightGray"
    HorizontalAlignment="Left"
    VerticalAlignment="Top"
    Width="100"
    Height="100">
    <Canvas>
      <TextBlock Canvas.Top="10" Canvas.Left="20">Hello World!</TextBlock>
    </Canvas>
  </Border>
</Page>    
```

#### [Get or Set Canvas Positioning Properties](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-get-or-set-canvas-positioning-properties)

此示例演示如何使用的定位方法[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)元素来定位子内容。 此示例使用中的内容[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)来表示定位值，并将值转换到的实例[Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double)，这是必需的参数进行定位。 然后重新转换为字符串和文本的形式显示值[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素中的使用[GetLeft](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas.getleft)方法。

##### 示例

下面的示例创建[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)具有十一个可选的元素[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)元素。 [SelectionChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.selector.selectionchanged)事件触发器`ChangeLeft`后面的代码块定义的自定义方法。

每个[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)表示[Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double)值，该值是一个参数的[SetLeft](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas.setleft)方法的[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)接受。 若要使用[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)来表示的实例[Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double)，您必须首先将[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)到正确的数据类型。

```xaml
<ListBox Grid.Column="1" Grid.Row="1" VerticalAlignment="Top" Width="60" Margin="10,0,0,0" SelectionChanged="ChangeLeft">
  <ListBoxItem>Auto</ListBoxItem>      
  <ListBoxItem>10</ListBoxItem>
  <ListBoxItem>20</ListBoxItem>
  <ListBoxItem>30</ListBoxItem>
  <ListBoxItem>40</ListBoxItem>
  <ListBoxItem>50</ListBoxItem>
  <ListBoxItem>60</ListBoxItem>
  <ListBoxItem>70</ListBoxItem>
  <ListBoxItem>80</ListBoxItem>
  <ListBoxItem>90</ListBoxItem>
  <ListBoxItem>100</ListBoxItem>      
</ListBox>
```

当用户更改[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)选择时，它调用`ChangeLeft`自定义方法。 此方法将传递[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)到[LengthConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.lengthconverter)对象，它将转换[Content](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.content)的[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)的实例[Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double)(请注意，此值已转换为[String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)使用[ToString](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.tostring)方法）。 然后将此值传递回[SetLeft](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas.setleft)并[GetLeft](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas.getleft)方法的[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)若要更改的位置`text1`对象。

```csharp
private void ChangeLeft(object sender, SelectionChangedEventArgs args)
{
    ListBoxItem li = ((sender as ListBox).SelectedItem as ListBoxItem);
    LengthConverter myLengthConverter = new LengthConverter();
    Double db1 = (Double)myLengthConverter.ConvertFromString(li.Content.ToString());
    Canvas.SetLeft(text1, db1);
    String st1 = (String)myLengthConverter.ConvertToString(Canvas.GetLeft(text1));
    canvasLeft.Text = "Canvas.Left = " + st1;
}
```

#### [Create and Use a Canvas](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-create-and-use-a-canvas)

此示例演示如何创建和使用的实例[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)。

##### 示例

下面的示例显式定位两[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)通过使用元素[SetTop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas.settop)并[SetLeft](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas.setleft)方法的[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)。 该示例还将分配[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)色`LightSteelBlue`到[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)。

> 当你使用可扩展应用程序标记语言 (XAML)到位置[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素，使用[Top](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas.top)和[Left](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas.left)属性。

```csharp
    private void CreateAndShowMainWindow()
    {
        // Create the application's main window
        mainWindow = new Window();
        
        // Create a canvas sized to fill the window
        Canvas myCanvas = new Canvas();
        myCanvas.Background = Brushes.LightSteelBlue;
        
        // Add a "Hello World!" text element to the Canvas
        TextBlock txt1 = new TextBlock();
        txt1.FontSize = 14;
        txt1.Text = "Hello World!";
        Canvas.SetTop(txt1, 100);
        Canvas.SetLeft(txt1, 10);
        myCanvas.Children.Add(txt1);
        
        // Add a second text element to show how absolute positioning works in a Canvas
        TextBlock txt2 = new TextBlock();
        txt2.FontSize = 22;
        txt2.Text = "Isn't absolute positioning handy?";
        Canvas.SetTop(txt2, 200);
        Canvas.SetLeft(txt2, 75);
        myCanvas.Children.Add(txt2);
        mainWindow.Content = myCanvas;
        mainWindow.Title = "Canvas Sample";
        mainWindow.Show();
    }
}
```

#### [Use the Attached Properties of Canvas to Position Child Elements](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-use-the-attached-properties-of-canvas-to-position-child-elements)

此示例演示如何使用附加的属性[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)来定位子元素。

##### 示例

下面的示例添加四个[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)元素作为父级的子元素[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)。 每个元素表示由[Bottom](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas.bottom)， [Left](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas.left)， [Right](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas.right)，和[Top](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas.top)。 每个[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)位于相对于父[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)并根据其分配的属性值。

```csharp
// Create the application's main window
mainWindow = new Window ();
mainWindow.Title = "Canvas Attached Properties Sample";

// Add a Border
Border myBorder = new Border();
myBorder.HorizontalAlignment = HorizontalAlignment.Left;
myBorder.VerticalAlignment = VerticalAlignment.Top;
myBorder.BorderBrush = Brushes.Black;
myBorder.BorderThickness = new Thickness(2);

// Create the Canvas
Canvas myCanvas = new Canvas();
myCanvas.Background = Brushes.LightBlue;
myCanvas.Width = 400;
myCanvas.Height = 400;

// Create the child Button elements
Button myButton1 = new Button();
Button myButton2 = new Button();
Button myButton3 = new Button();
Button myButton4 = new Button();

// Set Positioning attached properties on Button elements
Canvas.SetTop(myButton1, 50);
myButton1.Content = "Canvas.Top=50";
Canvas.SetBottom(myButton2, 50);
myButton2.Content = "Canvas.Bottom=50";
Canvas.SetLeft(myButton3, 50);
myButton3.Content = "Canvas.Left=50";
Canvas.SetRight(myButton4, 50);
myButton4.Content = "Canvas.Right=50";

// Add Buttons to the Canvas' Children collection
myCanvas.Children.Add(myButton1);
myCanvas.Children.Add(myButton2);
myCanvas.Children.Add(myButton3);
myCanvas.Children.Add(myButton4);

// Add the Canvas as the lone Child of the Border
myBorder.Child = myCanvas;

// Add the Border as the Content of the Parent Window Object
mainWindow.Content = myBorder;
mainWindow.Show ();
```

#### [Resize a Canvas by Using a Thumb](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-resize-a-canvas-by-using-a-thumb)

此示例演示如何使用[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)控件来调整大小[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)控件。

##### 示例

[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)控件提供的拖放功能，可用于移动或调整控件大小通过监视[DragStarted](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb.dragstarted)，[DragDelta](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb.dragdelta)并[DragCompleted](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb.dragcompleted)的事件[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)。

用户开始拖动操作通过鼠标指针暂停在时按鼠标左键[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)控件。 只要保持按下鼠标左键，将继续拖动操作。 在拖动操作期间[DragDelta](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb.dragdelta)可以多次出现。 每次它出现时，[DragDeltaEventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.dragdeltaeventargs)类提供的对应的鼠标位置更改的位置更改。 当用户释放鼠标左键时，已完成拖动操作。 拖动操作仅提供了新的坐标，;它不会自动重新[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)。

下面的示例演示[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)控件的子元素[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)控件。 事件处理程序及其[DragDelta](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb.dragdelta)事件提供逻辑来移动[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)并调整其大小[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)。 事件处理程序[DragStarted](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb.dragstarted)并[DragCompleted](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb.dragcompleted)事件更改的颜色[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)拖动操作过程。 下面的示例定义[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)。

```xaml
<Thumb Name="myThumb" Canvas.Left="80" Canvas.Top="80" Background="Blue" 
      Width="20" Height="20" DragDelta="onDragDelta" 
      DragStarted="onDragStarted" DragCompleted="onDragCompleted"
      />
```

下面的示例演示[DragDelta](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb.dragdelta)事件处理程序移入[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)并调整其大小[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)以响应鼠标移动。

```csharp
void onDragDelta(object sender, DragDeltaEventArgs e)
{
    //Move the Thumb to the mouse position during the drag operation
    double yadjust = myCanvasStretch.Height + e.VerticalChange;
    double xadjust = myCanvasStretch.Width + e.HorizontalChange;
    if ((xadjust >= 0) && (yadjust >= 0))
    {
        myCanvasStretch.Width = xadjust;
        myCanvasStretch.Height = yadjust;
        Canvas.SetLeft(myThumb, Canvas.GetLeft(myThumb) +
                                e.HorizontalChange);
        Canvas.SetTop(myThumb, Canvas.GetTop(myThumb) +
                                e.VerticalChange);
        changes.Text = "Size: " +
                        myCanvasStretch.Width.ToString() +
                         ", " +
                        myCanvasStretch.Height.ToString();
    }
}
```

下面的示例演示[DragStarted](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb.dragstarted)事件处理程序。

```csharp
void onDragStarted(object sender, DragStartedEventArgs e)
{
    myThumb.Background = Brushes.Orange;
}
```

下面的示例演示[DragCompleted](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb.dragcompleted)事件处理程序。

```csharp
void onDragCompleted(object sender, DragCompletedEventArgs e)
{
    myThumb.Background = Brushes.Blue;
}
```

有关完整示例，请参阅[Thumb 拖放功能示例](https://go.microsoft.com/fwlink/?LinkID=160042)。