# [StackPanel](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/stackpanel)

[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)元素用于水平或垂直堆叠子元素。

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/stackpanel-how-to-topics)

本部分中的主题介绍如何使用[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)以水平或垂直堆叠内容的元素。

### 本节内容

[在 StackPanel 和 DockPanel 之间进行选择](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-choose-between-stackpanel-and-dockpanel)
[创建 StackPanel](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-create-a-stackpanel)
[在 StackPanel 中水平或垂直对齐内容](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-horizontally-or-vertically-align-content-in-a-stackpanel)

### [Choose Between StackPanel and DockPanel](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-choose-between-stackpanel-and-dockpanel)

此示例演示如何使用之间进行选择[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)或[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)堆叠中的内容时[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)。

尽管可以使用任一[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)或[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)堆叠子元素，两个控件不始终生成相同的结果。 例如，放置子元素的顺序可能会影响中的子元素的大小[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)但不能在[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)。 出现此不同的行为的原因[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)度量值中的堆叠在方向[Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double)。[PositiveInfinity](https://docs.microsoft.com/zh-cn/dotnet/api/system.double.positiveinfinity); 但是，[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)测量仅的可用大小。

下面的示例演示此主要区别[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)和[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)。

```csharp
// Create the application's main window
mainWindow = new Window ();
mainWindow.Title = "StackPanel vs. DockPanel";

// Add root Grid
myGrid = new Grid();
myGrid.Width = 175;
myGrid.Height = 150;
RowDefinition myRowDef1 = new RowDefinition();
RowDefinition myRowDef2 = new RowDefinition();
myGrid.RowDefinitions.Add(myRowDef1);
myGrid.RowDefinitions.Add(myRowDef2);

// Define the DockPanel
myDockPanel = new DockPanel();
Grid.SetRow(myDockPanel, 0);

//Define an Image and Source
Image myImage = new Image();
BitmapImage bi = new BitmapImage();
bi.BeginInit();
bi.UriSource = new Uri("smiley_stackpanel.png", UriKind.Relative);
bi.EndInit();
myImage.Source = bi;

Image myImage2 = new Image();
BitmapImage bi2 = new BitmapImage();
bi2.BeginInit();
bi2.UriSource = new Uri("smiley_stackpanel.png", UriKind.Relative);
bi2.EndInit();
myImage2.Source = bi2;

Image myImage3 = new Image();
BitmapImage bi3 = new BitmapImage();
bi3.BeginInit();
bi3.UriSource = new Uri("smiley_stackpanel.PNG", UriKind.Relative);
bi3.EndInit();
myImage3.Stretch = Stretch.Fill;
myImage3.Source = bi3;

// Add the images to the parent DockPanel
myDockPanel.Children.Add(myImage);
myDockPanel.Children.Add(myImage2);
myDockPanel.Children.Add(myImage3);

//Define a StackPanel
myStackPanel = new StackPanel();
myStackPanel.Orientation = Orientation.Horizontal;
Grid.SetRow(myStackPanel, 1);

Image myImage4 = new Image();
BitmapImage bi4 = new BitmapImage();
bi4.BeginInit();
bi4.UriSource = new Uri("smiley_stackpanel.png", UriKind.Relative);
bi4.EndInit();
myImage4.Source = bi4;

Image myImage5 = new Image();
BitmapImage bi5 = new BitmapImage();
bi5.BeginInit();
bi5.UriSource = new Uri("smiley_stackpanel.png", UriKind.Relative);
bi5.EndInit();
myImage5.Source = bi5;

Image myImage6 = new Image();
BitmapImage bi6 = new BitmapImage();
bi6.BeginInit();
bi6.UriSource = new Uri("smiley_stackpanel.PNG", UriKind.Relative);
bi6.EndInit();
myImage6.Stretch = Stretch.Fill;
myImage6.Source = bi6;

// Add the images to the parent StackPanel
myStackPanel.Children.Add(myImage4);
myStackPanel.Children.Add(myImage5);
myStackPanel.Children.Add(myImage6);

// Add the layout panels as children of the Grid
myGrid.Children.Add(myDockPanel);
myGrid.Children.Add(myStackPanel);

// Add the Grid as the Content of the Parent Window Object
mainWindow.Content = myGrid;
mainWindow.Show ();
```

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      WindowTitle="StackPanel vs. DockPanel">
  <Grid Width="175" Height="150">
    <Grid.ColumnDefinitions>
      <ColumnDefinition />
    </Grid.ColumnDefinitions>
    <Grid.RowDefinitions>
      <RowDefinition />
      <RowDefinition />
    </Grid.RowDefinitions>
    
    <DockPanel Grid.Column="0" Grid.Row="0">
      <Image Source="smiley_stackpanel.png" />
      <Image Source="smiley_stackpanel.png" />
      <Image Source="smiley_stackpanel.png" Stretch="Fill"/>
    </DockPanel>

    <StackPanel Grid.Column="0" Grid.Row="1"  Orientation="Horizontal">
      <Image Source="smiley_stackpanel.png" />
      <Image Source="smiley_stackpanel.png" />
      <Image Source="smiley_stackpanel.png" Stretch="Fill"/>
    </StackPanel>
    </Grid>
</Page>
```

### [Create a StackPanel](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-create-a-stackpanel)

此示例演示如何创建[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)。

一个[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)，可在指定的方向堆叠元素。 通过使用属性上定义的[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)，内容可以流动竖向，这是默认设置，还是水平。

下面的示例垂直堆叠五[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)控件，每个都有一个不同[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)并[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border.background)，通过使用[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)。 没有指定的子元素[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)拉伸以填充父窗口; 但是，所具有的子元素指定[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)，在窗口中居中。

在默认的堆叠方向[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)是垂直的。 控件中内容流[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)，使用[Orientation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel.orientation)属性。 你可以通过使用控制水平对齐方式[HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.horizontalalignment)属性。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation" WindowTitle="StackPanel Sample">  
  <StackPanel>  
    <Border Background="SkyBlue" BorderBrush="Black" BorderThickness="1">  
      <TextBlock Foreground="Black" FontSize="12">Stacked Item #1</TextBlock>  
    </Border>  
    <Border Width="400" Background="CadetBlue" BorderBrush="Black" BorderThickness="1">  
      <TextBlock Foreground="Black" FontSize="14">Stacked Item #2</TextBlock>  
    </Border>  
    <Border Background="LightGoldenRodYellow" BorderBrush="Black" BorderThickness="1">  
      <TextBlock Foreground="Black" FontSize="16">Stacked Item #3</TextBlock>  
    </Border>  
    <Border Width="200" Background="PaleGreen" BorderBrush="Black" BorderThickness="1">  
      <TextBlock Foreground="Black" FontSize="18">Stacked Item #4</TextBlock>  
    </Border>  
    <Border Background="White" BorderBrush="Black" BorderThickness="1">  
      <TextBlock Foreground="Black" FontSize="20">Stacked Item #5</TextBlock>  
    </Border>  
  </StackPanel>  
</Page>  
```

### [Horizontally or Vertically Align Content in a StackPanel](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-horizontally-or-vertically-align-content-in-a-stackpanel)

此示例显示了如何调整[Orientation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel.orientation)内的内容[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)元素，以及如何调整[HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.horizontalalignment)和[VerticalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.verticalalignment)的子内容。

下面的示例创建三个[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)中的元素可扩展应用程序标记语言 (XAML)。 每个[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)表示的可能值[Orientation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel.orientation)，[HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.horizontalalignment)，和[VerticalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.verticalalignment)的属性[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)。 当用户选择的值中的任何[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)元素中，关联的属性[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)及其子[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)元素会更改。

```xaml
    <ListBox VerticalAlignment="Top" SelectionChanged="changeOrientation" Grid.Row="2" Grid.Column="1" Width="100" Height="50" Margin="0,0,0,10">
        <ListBoxItem>Horizontal</ListBoxItem>
        <ListBoxItem>Vertical</ListBoxItem>
    </ListBox>

    <ListBox VerticalAlignment="Top" SelectionChanged="changeHorAlign" Grid.Row="2" Grid.Column="3" Width="100" Height="50" Margin="0,0,0,10">
        <ListBoxItem>Left</ListBoxItem>
        <ListBoxItem>Right</ListBoxItem>
        <ListBoxItem>Center</ListBoxItem>
        <ListBoxItem>Stretch</ListBoxItem>
    </ListBox>

    <ListBox VerticalAlignment="Top" SelectionChanged="changeVertAlign" Grid.Row="2" Grid.Column="5" Width="100" Height="50" Margin="0,0,0,10">
        <ListBoxItem>Top</ListBoxItem>
        <ListBoxItem>Bottom</ListBoxItem>
        <ListBoxItem>Center</ListBoxItem>
        <ListBoxItem>Stretch</ListBoxItem>
    </ListBox>

<StackPanel Grid.ColumnSpan="6" Grid.Row="3" Name="sp1" Background="Yellow">
    <Button>Button One</Button>
    <Button>Button Two</Button>
    <Button>Button Three</Button>
    <Button>Button Four</Button>
    <Button>Button Five</Button>
    <Button>Button Six</Button>
</StackPanel>
```

下面的代码隐藏文件定义所做的更改与关联的事件[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)选择会有所变化。 [StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel) 由标识[Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.name) `sp1`。

```csharp
private void changeOrientation(object sender, SelectionChangedEventArgs args)
    {
        ListBoxItem li = ((sender as ListBox).SelectedItem as ListBoxItem);
        if (li.Content.ToString() == "Horizontal")
        {
        sp1.Orientation = System.Windows.Controls.Orientation.Horizontal;
        }
        else if (li.Content.ToString() == "Vertical")
        {
        sp1.Orientation = System.Windows.Controls.Orientation.Vertical;
        }

    }

private void changeHorAlign(object sender, SelectionChangedEventArgs args)
    {
        ListBoxItem li = ((sender as ListBox).SelectedItem as ListBoxItem);
        if (li.Content.ToString() == "Left")
        {
        sp1.HorizontalAlignment = System.Windows.HorizontalAlignment.Left;
        }
        else if (li.Content.ToString() == "Right")
        {
        sp1.HorizontalAlignment = System.Windows.HorizontalAlignment.Right;
        }
        else if (li.Content.ToString() == "Center")
        {
        sp1.HorizontalAlignment = System.Windows.HorizontalAlignment.Center;
        }
        else if (li.Content.ToString() == "Stretch")
        {
        sp1.HorizontalAlignment = System.Windows.HorizontalAlignment.Stretch;
        }
    }

private void changeVertAlign(object sender, SelectionChangedEventArgs args)
    {
        ListBoxItem li = ((sender as ListBox).SelectedItem as ListBoxItem);
        if (li.Content.ToString() == "Top")
        {
        sp1.VerticalAlignment = System.Windows.VerticalAlignment.Top;
        }
        else if (li.Content.ToString() == "Bottom")
        {
        sp1.VerticalAlignment = System.Windows.VerticalAlignment.Bottom;
        }
        else if (li.Content.ToString() == "Center")
        {
        sp1.VerticalAlignment = System.Windows.VerticalAlignment.Center;
        }
        else if (li.Content.ToString() == "Stretch")
        {
        sp1.VerticalAlignment = System.Windows.VerticalAlignment.Stretch;
        }
    }
```