## [DockPanel](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/dockpanel)

[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)元素用来定位边缘的布局容器的子内容。

### 本节内容

[帮助主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/dockpanel-how-to-topics)

### [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/dockpanel-how-to-topics)

本部分中的主题介绍如何使用[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)元素来定位边缘的布局容器的子元素。

#### 本节内容

[获取或设置 Dock 值](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-get-or-set-a-dock-value)
[创建 DockPanel](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-create-a-dockpanel)
[使用 DockPanel 元素对空间进行分区](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-partition-space-by-using-the-dockpanel-element)

#### [Get or Set a Dock Value](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-get-or-set-a-dock-value)

下面的示例演示如何分配[Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dock)对象值。 该示例使用[GetDock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.getdock)并[SetDock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.setdock)方法的[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)。

##### 示例

该示例创建的实例[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素中， `txt1`，并将分配[Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dock)的值`Top`通过[SetDock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.setdock)方法[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)。 然后，将的值[Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dock)属性设置为[Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.text)的[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素中的使用[GetDock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.getdock)方法。 最后，该示例将添加[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)父元素[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)， `dp1`。

```csharp
// Create the Panel DockPanel
dp1 = new DockPanel();

// Create a Text Control and then set its Dock property
txt1 = new TextBlock();
DockPanel.SetDock(txt1, System.Windows.Controls.Dock.Top);
txt1.Text = "The Dock Property is set to " + DockPanel.GetDock(txt1);
dp1.Children.Add(txt1);
mainWindow.Content = dp1;
mainWindow.Show();
```

#### [Create a DockPanel](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-create-a-dockpanel)

###### 示例

以下示例创建并使用的实例[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)使用代码。 该示例演示如何通过创建五个分区的空间[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)元素和定位 （停靠） 在父级内对其[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)。 如果保留默认设置，最终的矩形将填充所有剩余的未分配的空间。

```csharp
    private void CreateAndShowMainWindow()
    {
        // Create the application's main window
        mainWindow = new Window ();

        // Create a DockPanel
        DockPanel myDockPanel = new DockPanel();

        // Add the first rectangle to the DockPanel
        Rectangle rect1 = new Rectangle();
        rect1.Stroke = Brushes.Black;
        rect1.Fill = Brushes.SkyBlue;
        rect1.Height = 25;
        DockPanel.SetDock(rect1, Dock.Top);
        myDockPanel.Children.Add(rect1);

        // Add the second rectangle to the DockPanel
        Rectangle rect2 = new Rectangle();
        rect2.Stroke = Brushes.Black;
        rect2.Fill = Brushes.SkyBlue;
        rect2.Height = 25;
        DockPanel.SetDock(rect2, Dock.Top);
        myDockPanel.Children.Add(rect2);

        // Add the third rectangle to the DockPanel
        Rectangle rect4 = new Rectangle();
        rect4.Stroke = Brushes.Black;
        rect4.Fill = Brushes.Khaki;
        rect4.Height = 25;
        DockPanel.SetDock(rect4, Dock.Bottom);
        myDockPanel.Children.Add(rect4);

        // Add the fourth rectangle to the DockPanel
        Rectangle rect3 = new Rectangle();
        rect3.Stroke = Brushes.Black;
        rect3.Fill = Brushes.PaleGreen;
        rect3.Width = 200;
        DockPanel.SetDock(rect3, Dock.Left);
        myDockPanel.Children.Add(rect3);

        // Add the final rectangle to the DockPanel
        Rectangle rect5 = new Rectangle();
        rect5.Stroke = Brushes.Black;
        rect5.Fill = Brushes.White;
        myDockPanel.Children.Add(rect5);
        
        // Add the DockPanel to the Window as Content and show the Window
        mainWindow.Content = myDockPanel;
        mainWindow.Title = "DockPanel Sample";
        mainWindow.Show();
    }
}
```

#### [Partition Space by Using the DockPanel Element](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-partition-space-by-using-the-dockpanel-element)

下面的示例创建一个简单用户界面 (UI)框架，它使用[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)元素。 [DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)分区到其子元素可用空间。

##### 示例

此示例使用[Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.dock)属性，它是附加的属性，若要将两个相同停靠[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)元素出现在[Top](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dock#System_Windows_Controls_Dock_Top)的已分区的空间。 第三个[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)元素停靠至[Left](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dock#System_Windows_Controls_Dock_Left)，其宽度设置为 200 像素。 第四个[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)停靠到[Bottom](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dock#System_Windows_Controls_Dock_Bottom)的屏幕。 最后一个[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)元素将自动填充剩余的空间。

```csharp
// Create the application's main window
mainWindow = new Window ();
mainWindow.Title = "DockPanel Sample";

// Create the DockPanel
DockPanel myDockPanel = new DockPanel();
myDockPanel.LastChildFill = true;

// Define the child content
Border myBorder1 = new Border();
myBorder1.Height = 25;
myBorder1.Background = Brushes.SkyBlue;
myBorder1.BorderBrush = Brushes.Black;
myBorder1.BorderThickness = new Thickness(1);
DockPanel.SetDock(myBorder1, Dock.Top);
TextBlock myTextBlock1 = new TextBlock();
myTextBlock1.Foreground = Brushes.Black;
myTextBlock1.Text = "Dock = Top";
myBorder1.Child = myTextBlock1;

Border myBorder2 = new Border();
myBorder2.Height = 25;
myBorder2.Background = Brushes.SkyBlue;
myBorder2.BorderBrush = Brushes.Black;
myBorder2.BorderThickness = new Thickness(1);
DockPanel.SetDock(myBorder2, Dock.Top);
TextBlock myTextBlock2 = new TextBlock();
myTextBlock2.Foreground = Brushes.Black;
myTextBlock2.Text = "Dock = Top";
myBorder2.Child = myTextBlock2;

Border myBorder3 = new Border();
myBorder3.Height = 25;
myBorder3.Background = Brushes.LemonChiffon;
myBorder3.BorderBrush = Brushes.Black;
myBorder3.BorderThickness = new Thickness(1);
DockPanel.SetDock(myBorder3, Dock.Bottom);
TextBlock myTextBlock3 = new TextBlock();
myTextBlock3.Foreground = Brushes.Black;
myTextBlock3.Text = "Dock = Bottom";
myBorder3.Child = myTextBlock3;

Border myBorder4 = new Border();
myBorder4.Width = 200;
myBorder4.Background = Brushes.PaleGreen;
myBorder4.BorderBrush = Brushes.Black;
myBorder4.BorderThickness = new Thickness(1);
DockPanel.SetDock(myBorder4, Dock.Left);
TextBlock myTextBlock4 = new TextBlock();
myTextBlock4.Foreground = Brushes.Black;
myTextBlock4.Text = "Dock = Left";
myBorder4.Child = myTextBlock4;

Border myBorder5 = new Border();
myBorder5.Background = Brushes.White;
myBorder5.BorderBrush = Brushes.Black;
myBorder5.BorderThickness = new Thickness(1);
TextBlock myTextBlock5 = new TextBlock();
myTextBlock5.Foreground = Brushes.Black;
myTextBlock5.Text = "This content will Fill the remaining space";
myBorder5.Child = myTextBlock5;


// Add child elements to the DockPanel Children collection
myDockPanel.Children.Add(myBorder1);
myDockPanel.Children.Add(myBorder2);
myDockPanel.Children.Add(myBorder3);
myDockPanel.Children.Add(myBorder4);
myDockPanel.Children.Add(myBorder5);
           
// Add the parent Canvas as the Content of the Window Object
mainWindow.Content = myDockPanel;
mainWindow.Show ();
```

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation" WindowTitle="DockPanel Sample">
  <DockPanel LastChildFill="True">
    <Border Height="25" Background="SkyBlue" BorderBrush="Black" BorderThickness="1" DockPanel.Dock="Top">
      <TextBlock Foreground="Black">Dock = "Top"</TextBlock>
    </Border>
    <Border Height="25" Background="SkyBlue" BorderBrush="Black" BorderThickness="1" DockPanel.Dock="Top">
      <TextBlock Foreground="Black">Dock = "Top"</TextBlock>
    </Border>
    <Border Height="25" Background="LemonChiffon" BorderBrush="Black" BorderThickness="1" DockPanel.Dock="Bottom">
      <TextBlock Foreground="Black">Dock = "Bottom"</TextBlock>
    </Border>
    <Border Width="200" Background="PaleGreen" BorderBrush="Black" BorderThickness="1" DockPanel.Dock="Left">
      <TextBlock Foreground="Black">Dock = "Left"</TextBlock>
    </Border>
    <Border Background="White" BorderBrush="Black" BorderThickness="1">
      <TextBlock Foreground="Black">This content will "Fill" the remaining space</TextBlock>
    </Border>
  </DockPanel>
</Page>
```

> 默认情况下的最后一个子级[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)元素填充剩余的未分配空间。 如果不希望出现此行为，请设置 `LastChildFill="False"`。

已编译的应用程序将生成如下所示的新 UI。

![典型的 DockPanel 方案。](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/panel-intro-dockpanel.png)