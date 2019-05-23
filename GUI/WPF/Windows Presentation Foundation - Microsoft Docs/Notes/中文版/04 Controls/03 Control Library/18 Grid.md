## [Grid](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/grid)

[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素用来精确定位行和列中的内容。

### 本节内容

[帮助主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/grid-how-to-topics)

### [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/grid-how-to-topics)

本部分中的主题介绍如何定位元素使用[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素。

#### 本节内容

[使用 Grid 生成标准 UI 对话框](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-build-a-standard-ui-dialog-box-by-using-grid)
[创建复杂网格](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-create-a-complex-grid)
[创建 Grid 元素](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-create-a-grid-element)
[创建和使用 GridLengthConverter 对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-create-and-use-a-gridlengthconverter-object)
[使用 ColumnDefinitionsCollection 和 RowDefinitionsCollection 控制列和行](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/manipulate-columns-and-rows-by-using-columndefinitionscollections)
[确定 Grid 子元素的位置](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-position-the-child-elements-of-a-grid)
[在 Grid 之间共用重设大小属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-share-sizing-properties-between-grids)

#### [Build a Standard UI Dialog Box by Using Grid](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-build-a-standard-ui-dialog-box-by-using-grid)

此示例演示如何创建标准用户界面 (UI)对话框中，通过使用[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素。

##### 示例

下面的示例创建像那样的对话框**运行**中的对话框Windows操作系统。

此示例将创建[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)，并使用[ColumnDefinition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.columndefinition)和[RowDefinition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.rowdefinition)类来定义五个列和四个行。

该示例然后添加并将置于[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)， `RunIcon.png`，用于表示在对话框中找到的映像。 图像被置于中第一列和行的[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)（左上角）。

接下来，该示例将添加[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)跨越第一行的剩余列的第一列的元素。 它将添加另一个[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素来表示第一列中的第二个行**打开**文本框。 一个[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)如下所示，它表示数据输入区域。

最后，该示例将添加三个[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)针对最后一行的元素，后者表示**确定**，**取消**，并且**浏览**事件。

```csharp
// Create the Grid.
grid1 = new Grid ();
grid1.Background = Brushes.Gainsboro;
grid1.HorizontalAlignment = HorizontalAlignment.Left;
grid1.VerticalAlignment = VerticalAlignment.Top;
grid1.ShowGridLines = true;
grid1.Width = 425;
grid1.Height = 165;

// Define the Columns.
colDef1 = new ColumnDefinition();
colDef1.Width = new GridLength(1, GridUnitType.Auto);
colDef2 = new ColumnDefinition();
colDef2.Width = new GridLength(1, GridUnitType.Star);
colDef3 = new ColumnDefinition();
colDef3.Width = new GridLength(1, GridUnitType.Star);
colDef4 = new ColumnDefinition();
colDef4.Width = new GridLength(1, GridUnitType.Star);
colDef5 = new ColumnDefinition();
colDef5.Width = new GridLength(1, GridUnitType.Star);
grid1.ColumnDefinitions.Add(colDef1);
grid1.ColumnDefinitions.Add(colDef2);
grid1.ColumnDefinitions.Add(colDef3);
grid1.ColumnDefinitions.Add(colDef4);
grid1.ColumnDefinitions.Add(colDef5);

// Define the Rows.
rowDef1 = new RowDefinition();
rowDef1.Height = new GridLength(1, GridUnitType.Auto);
rowDef2 = new RowDefinition();
rowDef2.Height = new GridLength(1, GridUnitType.Auto);
rowDef3 = new RowDefinition();
rowDef3.Height = new GridLength(1, GridUnitType.Star);
rowDef4 = new RowDefinition();
rowDef4.Height = new GridLength(1, GridUnitType.Auto);
grid1.RowDefinitions.Add(rowDef1);
grid1.RowDefinitions.Add(rowDef2);
grid1.RowDefinitions.Add(rowDef3);
grid1.RowDefinitions.Add(rowDef4);

// Add the Image.
img1 = new Image();
img1.Source = new System.Windows.Media.Imaging.BitmapImage(new Uri("runicon.png", UriKind.Relative));
Grid.SetRow(img1, 0);
Grid.SetColumn(img1, 0);

// Add the main application dialog.
txt1 = new TextBlock();
txt1.Text = "Type the name of a program, folder, document, or Internet resource, and Windows will open it for you.";
txt1.TextWrapping = TextWrapping.Wrap;
Grid.SetColumnSpan(txt1, 4);
Grid.SetRow(txt1, 0);
Grid.SetColumn(txt1, 1);

// Add the second text cell to the Grid.
txt2 = new TextBlock();
txt2.Text = "Open:";
Grid.SetRow(txt2, 1);
Grid.SetColumn(txt2, 0);

// Add the TextBox control.
tb1 = new TextBox();
Grid.SetRow(tb1, 1);
Grid.SetColumn(tb1, 1);
Grid.SetColumnSpan(tb1, 5);

// Add the buttons.
button1 = new Button();
button2 = new Button();
button3 = new Button();
button1.Content = "OK";
button2.Content = "Cancel";
button3.Content = "Browse ...";
Grid.SetRow(button1, 3);
Grid.SetColumn(button1, 2);
button1.Margin = new Thickness(10, 0, 10, 15);
button2.Margin = new Thickness(10, 0, 10, 15);
button3.Margin = new Thickness(10, 0, 10, 15);
Grid.SetRow(button2, 3);
Grid.SetColumn(button2, 3);
Grid.SetRow(button3, 3);
Grid.SetColumn(button3, 4);

grid1.Children.Add(img1);
grid1.Children.Add(txt1);
grid1.Children.Add(txt2);
grid1.Children.Add(tb1);
grid1.Children.Add(button1);
grid1.Children.Add(button2);
grid1.Children.Add(button3);

mainWindow.Content = grid1;
```

#### [Create a Complex Grid](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-create-a-complex-grid)

此示例演示如何使用[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)控件来创建布局看起来像每月的日历。

##### 示例

下面的示例通过定义八个行和八个列[RowDefinition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.rowdefinition)和[ColumnDefinition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.columndefinition)类。 它使用[Grid.ColumnSpan](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid.columnspan)并[Grid.RowSpan](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid.rowspan)一起使用的附加属性，[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)填充各种列和行的背景的元素。 这种设计是可能的因为多个元素可以存在于每个单元格中[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)的主要区别[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)和[Table](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.table)。

该示例使用垂直渐变来[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)列和行，以改进的可视化展示和日历的可读性。 样式[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素表示的日期和星期数。 [TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock) 元素绝对定位在其单元格内使用[Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)属性和应用程序的样式中定义的对齐方式属性。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      WindowTitle="Complex Grid Example">
  <Border BorderBrush="Black">

    <Grid ShowGridLines="false" Background="White">
      <Grid.Resources>
        <Style TargetType="{x:Type ColumnDefinition}">
          <Setter Property="Width" Value="30"/>
        </Style>
        <Style TargetType="{x:Type Rectangle}">
          <Setter Property="RadiusX" Value="6"/>
          <Setter Property="RadiusY" Value="6"/>
        </Style>
        <Style x:Key="DayOfWeek">
          <Setter Property="Grid.Row" Value="1"></Setter>
          <Setter Property="TextBlock.Margin" Value="5"></Setter>
        </Style>
        <Style x:Key="OneDate">
          <Setter Property="TextBlock.Margin" Value="5"></Setter>
        </Style>
      </Grid.Resources>
      <Grid.ColumnDefinitions>
          <ColumnDefinition/>
          <ColumnDefinition/>
          <ColumnDefinition/>
          <ColumnDefinition/>
          <ColumnDefinition/>
          <ColumnDefinition/>
          <ColumnDefinition/>
          <!-- This column will receive all remaining width -->
          <ColumnDefinition Width="*"/>
      </Grid.ColumnDefinitions>
          <Grid.RowDefinitions>
          <RowDefinition Height="Auto"/>
          <RowDefinition Height="Auto"/>
          <RowDefinition Height="Auto"/>
          <RowDefinition Height="Auto"/>
          <RowDefinition Height="Auto"/>
          <RowDefinition Height="Auto"/>
          <RowDefinition Height="Auto"/>
          <!-- This row will receive all remaining Height -->
          <RowDefinition/>
      </Grid.RowDefinitions>


      <!-- These Rectangles constitute the backgrounds of the various Rows and Columns -->

      <Rectangle Grid.ColumnSpan="7" Fill="#73B2F5"/>
      <Rectangle Grid.Row="1" Grid.RowSpan="6"  Fill="#73B2F5"/>
      <Rectangle Grid.Column="6" Grid.Row="1" Grid.RowSpan="6" Fill="#73B2F5"/>
      <Rectangle Grid.Column="1" Grid.Row="1" Grid.ColumnSpan="5" Grid.RowSpan="6"
      Fill="#efefef"/>

      <!-- Month row -->
      <TextBlock Grid.ColumnSpan="7" Margin="0,5,0,5" HorizontalAlignment="Center">
        January 2004
      </TextBlock>

      <!-- Draws a separator under the days-of-the-week row -->

      <Rectangle Grid.Row="1" Grid.ColumnSpan="7" 
      Fill="Black" RadiusX="1" RadiusY="1" Height="2" Margin="0,20,0,0"/>

      <!-- Day-of-the-week row -->
      <TextBlock Grid.Column="0" Style="{StaticResource DayOfWeek}">Sun</TextBlock>
      <TextBlock Grid.Column="1" Style="{StaticResource DayOfWeek}">Mon</TextBlock>
      <TextBlock Grid.Column="2" Style="{StaticResource DayOfWeek}">Tue</TextBlock>
      <TextBlock Grid.Column="3" Style="{StaticResource DayOfWeek}">Wed</TextBlock>
      <TextBlock Grid.Column="4" Style="{StaticResource DayOfWeek}">Thu</TextBlock>
      <TextBlock Grid.Column="5" Style="{StaticResource DayOfWeek}">Fri</TextBlock>
      <TextBlock Grid.Column="6" Style="{StaticResource DayOfWeek}">Sat</TextBlock>

      <!-- Dates go here -->
      <TextBlock Grid.Column="4" Grid.Row="2" Style="{StaticResource OneDate}">1</TextBlock>
      <TextBlock Grid.Column="5" Grid.Row="2" Style="{StaticResource OneDate}">2</TextBlock>
      <TextBlock Grid.Column="6" Grid.Row="2" Style="{StaticResource OneDate}">3</TextBlock>
      <TextBlock Grid.Column="0" Grid.Row="3" Style="{StaticResource OneDate}">4</TextBlock>
      <TextBlock Grid.Column="1" Grid.Row="3" Style="{StaticResource OneDate}">5</TextBlock>
      <TextBlock Grid.Column="2" Grid.Row="3" Style="{StaticResource OneDate}">6</TextBlock>
      <TextBlock Grid.Column="3" Grid.Row="3" Style="{StaticResource OneDate}">7</TextBlock>
      <TextBlock Grid.Column="4" Grid.Row="3" Style="{StaticResource OneDate}">8</TextBlock>
      <TextBlock Grid.Column="5" Grid.Row="3" Style="{StaticResource OneDate}">9</TextBlock>
      <TextBlock Grid.Column="6" Grid.Row="3" Style="{StaticResource OneDate}">10</TextBlock>
      <TextBlock Grid.Column="0" Grid.Row="4" Style="{StaticResource OneDate}">11</TextBlock>
      <TextBlock Grid.Column="1" Grid.Row="4" Style="{StaticResource OneDate}">12</TextBlock>
      <TextBlock Grid.Column="2" Grid.Row="4" Style="{StaticResource OneDate}">13</TextBlock>
      <TextBlock Grid.Column="3" Grid.Row="4" Style="{StaticResource OneDate}">14</TextBlock>
      <TextBlock Grid.Column="4" Grid.Row="4" Style="{StaticResource OneDate}">15</TextBlock>
      <TextBlock Grid.Column="5" Grid.Row="4" Style="{StaticResource OneDate}">16</TextBlock>
      <TextBlock Grid.Column="6" Grid.Row="4" Style="{StaticResource OneDate}">17</TextBlock>
      <TextBlock Grid.Column="0" Grid.Row="5" Style="{StaticResource OneDate}">18</TextBlock>
      <TextBlock Grid.Column="1" Grid.Row="5" Style="{StaticResource OneDate}">19</TextBlock>
      <TextBlock Grid.Column="2" Grid.Row="5" Style="{StaticResource OneDate}">20</TextBlock>
      <TextBlock Grid.Column="3" Grid.Row="5" Style="{StaticResource OneDate}">21</TextBlock>
      <TextBlock Grid.Column="4" Grid.Row="5" Style="{StaticResource OneDate}">22</TextBlock>
      <TextBlock Grid.Column="5" Grid.Row="5" Style="{StaticResource OneDate}">23</TextBlock>
      <TextBlock Grid.Column="6" Grid.Row="5" Style="{StaticResource OneDate}">24</TextBlock>
      <TextBlock Grid.Column="0" Grid.Row="6" Style="{StaticResource OneDate}">25</TextBlock>
      <TextBlock Grid.Column="1" Grid.Row="6" Style="{StaticResource OneDate}">26</TextBlock>
      <TextBlock Grid.Column="2" Grid.Row="6" Style="{StaticResource OneDate}">27</TextBlock>
      <TextBlock Grid.Column="3" Grid.Row="6" Style="{StaticResource OneDate}">28</TextBlock>
      <TextBlock Grid.Column="4" Grid.Row="6" Style="{StaticResource OneDate}">29</TextBlock>
      <TextBlock Grid.Column="5" Grid.Row="6" Style="{StaticResource OneDate}">30</TextBlock>
      <TextBlock Grid.Column="6" Grid.Row="6" Style="{StaticResource OneDate}">31</TextBlock>
    </Grid>
  </Border>
</Page>
```

下图显示了生成的控件，可自定义日历：

![生成的控件的屏幕截图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/how-to-create-a-complex-grid/wpf-manual-calendar.png)

#### [Create a Grid Element](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-create-a-grid-element)

##### 示例

下面的示例演示如何创建和使用的实例[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)通过使用可扩展应用程序标记语言 (XAML)或代码。 此示例使用三种[ColumnDefinition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.columndefinition)对象和三个[RowDefinition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.rowdefinition)对象创建一个网格，其中具有九个单元格，例如工作表。 每个单元都包含[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)表示数据，而顶部行的元素包含[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)与[ColumnSpan](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid.columnspan)应用属性。 若要显示的每个单元格边界[ShowGridLines](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid.showgridlines)启用属性。

```csharp
// Create the application's main window
mainWindow = new Window();
mainWindow.Title = "Grid Sample";

// Create the Grid
Grid myGrid = new Grid();
myGrid.Width = 250;
myGrid.Height = 100;
myGrid.HorizontalAlignment = HorizontalAlignment.Left;
myGrid.VerticalAlignment = VerticalAlignment.Top;
myGrid.ShowGridLines = true;

// Define the Columns
ColumnDefinition colDef1 = new ColumnDefinition();
ColumnDefinition colDef2 = new ColumnDefinition();
ColumnDefinition colDef3 = new ColumnDefinition();
myGrid.ColumnDefinitions.Add(colDef1);
myGrid.ColumnDefinitions.Add(colDef2);
myGrid.ColumnDefinitions.Add(colDef3);

// Define the Rows
RowDefinition rowDef1 = new RowDefinition();
RowDefinition rowDef2 = new RowDefinition();
RowDefinition rowDef3 = new RowDefinition();
RowDefinition rowDef4 = new RowDefinition();
myGrid.RowDefinitions.Add(rowDef1);
myGrid.RowDefinitions.Add(rowDef2);
myGrid.RowDefinitions.Add(rowDef3);
myGrid.RowDefinitions.Add(rowDef4);

// Add the first text cell to the Grid
TextBlock txt1 = new TextBlock();
txt1.Text = "2005 Products Shipped";
txt1.FontSize = 20; 
txt1.FontWeight = FontWeights.Bold;
Grid.SetColumnSpan(txt1, 3);
Grid.SetRow(txt1, 0);

// Add the second text cell to the Grid
TextBlock txt2 = new TextBlock();
txt2.Text = "Quarter 1";
txt2.FontSize = 12;
txt2.FontWeight = FontWeights.Bold;
Grid.SetRow(txt2, 1);
Grid.SetColumn(txt2, 0);

// Add the third text cell to the Grid
TextBlock txt3 = new TextBlock();
txt3.Text = "Quarter 2";
txt3.FontSize = 12;
txt3.FontWeight = FontWeights.Bold;
Grid.SetRow(txt3, 1);
Grid.SetColumn(txt3, 1);

// Add the fourth text cell to the Grid
TextBlock txt4 = new TextBlock();
txt4.Text = "Quarter 3";
txt4.FontSize = 12;
txt4.FontWeight = FontWeights.Bold;
Grid.SetRow(txt4, 1);
Grid.SetColumn(txt4, 2);

// Add the sixth text cell to the Grid
TextBlock txt5 = new TextBlock();
Double db1 = new Double();
db1 = 50000;
txt5.Text = db1.ToString();
Grid.SetRow(txt5, 2);
Grid.SetColumn(txt5, 0);

// Add the seventh text cell to the Grid
TextBlock txt6 = new TextBlock();
Double db2 = new Double();
db2 = 100000;
txt6.Text = db2.ToString();
Grid.SetRow(txt6, 2);
Grid.SetColumn(txt6, 1);

// Add the final text cell to the Grid
TextBlock txt7 = new TextBlock();
Double db3 = new Double();
db3 = 150000;
txt7.Text = db3.ToString();
Grid.SetRow(txt7, 2);
Grid.SetColumn(txt7, 2);

// Total all Data and Span Three Columns
TextBlock txt8 = new TextBlock();
txt8.FontSize = 16;
txt8.FontWeight = FontWeights.Bold;
txt8.Text = "Total Units: " + (db1 + db2 + db3).ToString();
Grid.SetRow(txt8, 3);
Grid.SetColumnSpan(txt8, 3);

// Add the TextBlock elements to the Grid Children collection
myGrid.Children.Add(txt1);
myGrid.Children.Add(txt2);
myGrid.Children.Add(txt3);
myGrid.Children.Add(txt4);
myGrid.Children.Add(txt5);
myGrid.Children.Add(txt6);
myGrid.Children.Add(txt7);
myGrid.Children.Add(txt8);

// Add the Grid as the Content of the Parent Window Object
mainWindow.Content = myGrid;
mainWindow.Show ();
```

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation" WindowTitle="Grid Sample">
    <Grid VerticalAlignment="Top" HorizontalAlignment="Left" ShowGridLines="True" Width="250" Height="100">
      <Grid.ColumnDefinitions>
        <ColumnDefinition />
        <ColumnDefinition />
        <ColumnDefinition />
      </Grid.ColumnDefinitions>
      <Grid.RowDefinitions>
        <RowDefinition />
        <RowDefinition />
        <RowDefinition />
        <RowDefinition />
      </Grid.RowDefinitions>

      <TextBlock FontSize="20" FontWeight="Bold" Grid.ColumnSpan="3" Grid.Row="0">2005 Products Shipped</TextBlock>
      <TextBlock FontSize="12" FontWeight="Bold" Grid.Row="1" Grid.Column="0">Quarter 1</TextBlock>
      <TextBlock FontSize="12" FontWeight="Bold" Grid.Row="1" Grid.Column="1">Quarter 2</TextBlock>
      <TextBlock FontSize="12" FontWeight="Bold" Grid.Row="1" Grid.Column="2">Quarter 3</TextBlock>
      <TextBlock Grid.Row="2" Grid.Column="0">50000</TextBlock>
      <TextBlock Grid.Row="2" Grid.Column="1">100000</TextBlock>
      <TextBlock Grid.Row="2" Grid.Column="2">150000</TextBlock>
      <TextBlock FontSize="16" FontWeight="Bold" Grid.ColumnSpan="3" Grid.Row="3">Total Units: 300000</TextBlock>
    </Grid>
</Page>
```

这两种方法将生成一个用户界面，看起来都非常相同的如下所示。

![屏幕截图描绘了一个 WPF 用户界面，其中包含一个网格，分成三个列。](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/how-to-create-a-grid-element/how-to-create-a-grid-element.png)

#### [Create and Use a GridLengthConverter Object](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-create-and-use-a-gridlengthconverter-object)

##### 示例

下面的示例演示如何创建和使用的实例[GridLengthConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.gridlengthconverter)。 该示例定义一个名为的自定义方法`changeCol`，哪些阶段[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)到[GridLengthConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.gridlengthconverter)用于将转换[Content](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.content)的[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)的实例[GridLength](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.gridlength)。 转换后的值然后返回作为值传递[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.columndefinition.width)属性的[ColumnDefinition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.columndefinition)元素。

该示例还定义第二个自定义方法，称为`changeColVal`。 此自定义方法将转换[Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.rangebase.value)的[Slider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider)到[String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)，然后将值改回[ColumnDefinition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.columndefinition)作为[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.columndefinition.width)的元素。

请注意，单独可扩展应用程序标记语言 (XAML)文件定义的内容[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)。

```csharp
private void changeColVal(object sender, RoutedEventArgs e) 
{
    txt1.Text = "Current Grid Column is " + hs1.Value.ToString();
}

private void changeCol(object sender, SelectionChangedEventArgs args)
{
    ListBoxItem li = ((sender as ListBox).SelectedItem as ListBoxItem);
    GridLengthConverter myGridLengthConverter = new GridLengthConverter();
    if (hs1.Value == 0)
    {
        GridLength gl1 = (GridLength)myGridLengthConverter.ConvertFromString(li.Content.ToString());
        col1.Width = gl1;
    }
    else if (hs1.Value == 1)
    {
        GridLength gl2 = (GridLength)myGridLengthConverter.ConvertFromString(li.Content.ToString());
        col2.Width = gl2;
    }
    else if (hs1.Value == 2)
    {
        GridLength gl3 = (GridLength)myGridLengthConverter.ConvertFromString(li.Content.ToString());
        col3.Width = gl3;
    }
}
```

#### [Manipulate Columns and Rows by Using ColumnDefinitionsCollections and RowDefinitionsCollections](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/manipulate-columns-and-rows-by-using-columndefinitionscollections)

此示例演示如何使用中的方法[ColumnDefinitionCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.columndefinitioncollection)和[RowDefinitionCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.rowdefinitioncollection)类执行的操作，例如添加、 清除或计数的行或列的内容。 例如，可以[Add](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.columndefinitioncollection.add)， [Clear](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.columndefinitioncollection.clear)，或[Count](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.columndefinitioncollection.count)中包含的项[ColumnDefinition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.columndefinition)或[RowDefinition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.rowdefinition)。

##### 示例

下面的示例创建[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)具有元素[Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.name)的`grid1`。 [Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)包含[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)，它持有[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)元素，每个受不同的集合方法。 当您单击[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)，则会激活的代码隐藏文件中的方法调用。

```xaml
<Grid DockPanel.Dock="Top" HorizontalAlignment="Left" Name="grid1" ShowGridLines="true" Width="625" Height="400" Background="#b0e0e6">
  <Grid.ColumnDefinitions>
    <ColumnDefinition/>
    <ColumnDefinition/>
    <ColumnDefinition/>
  </Grid.ColumnDefinitions>
  <Grid.RowDefinitions>
  <RowDefinition/>
    <RowDefinition/>
    <RowDefinition/>
  </Grid.RowDefinitions>
</Grid>

<StackPanel HorizontalAlignment="Left" Orientation="Horizontal" Width="625" DockPanel.Dock="Top">
    <Button Width="125" Click="addCol">Add Column</Button>
    <Button Width="125" Click="addRow">Add Row</Button>
    <Button Width="125" Click="clearCol">Clear All Columns</Button>
    <Button Width="125" Click="clearRow">Clear All Rows</Button>
    <Button Width="125" Click="removeCol">Remove One Column</Button>
</StackPanel>
<StackPanel HorizontalAlignment="Left" Orientation="Horizontal" Width="625" DockPanel.Dock="Top">
    <Button Width="125" Click="removeRow">Remove One Row</Button>
    <Button Width="125" Click="colCount">How Many Columns?</Button>
    <Button Width="125" Click="rowCount">How Many Rows?</Button>
    <Button Width="125" Click="rem5Col">Remove 5 Columns</Button>
    <Button Width="125" Click="rem5Row">Remove 5 Rows</Button>			
    </StackPanel>
<StackPanel HorizontalAlignment="Left" Orientation="Horizontal" Width="625" DockPanel.Dock="Top">
    <Button Width="125" Click="containsRow">Contains Row?</Button>
    <Button Width="125" Click="containsCol">Contains Column?</Button>
    <Button Width="125" Click="insertRowAt">Insert Row</Button>
    <Button Width="125" Click="insertColAt">Insert Column</Button>
    <Button Width="125" Click="colReadOnly">IsReadOnly?</Button>
</StackPanel>    
```

此示例中定义的自定义方法，每个对应于一系列[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)中的事件可扩展应用程序标记语言 (XAML)文件。 可以更改的列和中的行数[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)中有多种，其中包括添加或删除行和列; 以及计算行和列的总数。 若要防止[ArgumentOutOfRangeException](https://docs.microsoft.com/zh-cn/dotnet/api/system.argumentoutofrangeexception)和[ArgumentException](https://docs.microsoft.com/zh-cn/dotnet/api/system.argumentexception)异常，您可以使用错误检查功能的[RemoveRange](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.columndefinitioncollection.removerange)方法提供。

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;

namespace columndefinitions_grid
{
    public partial class Window1 : Window
    {
        RowDefinition rowDef1;
        ColumnDefinition colDef1;

        private void addCol(object sender, RoutedEventArgs e) 
        {
            colDef1 = new ColumnDefinition();
            grid1.ColumnDefinitions.Add(colDef1);
        }

        private void addRow(object sender, RoutedEventArgs e)
        {
            rowDef1 = new RowDefinition();
            grid1.RowDefinitions.Add(rowDef1);
        }

        private void clearCol(object sender, RoutedEventArgs e)
        {
            grid1.ColumnDefinitions.Clear();
        }

        private void clearRow(object sender, RoutedEventArgs e)
        {
            grid1.RowDefinitions.Clear();
        }

        private void removeCol(object sender, RoutedEventArgs e)
        {
            if (grid1.ColumnDefinitions.Count <= 0)
            {
                tp1.Text = "No More Columns to Remove!";
            }
            else
            {
                grid1.ColumnDefinitions.RemoveAt(0);
            }
        }

        private void removeRow(object sender, RoutedEventArgs e)
        {
            if (grid1.RowDefinitions.Count <= 0)
            {
                tp1.Text = "No More Rows to Remove!";
            }
            else
            {
                grid1.RowDefinitions.RemoveAt(0);
            }
        }

        private void colCount(object sender, RoutedEventArgs e)
        {
            tp2.Text = "The current number of Columns is: " + grid1.ColumnDefinitions.Count;
        }

        private void rowCount(object sender, RoutedEventArgs e)
        {
            tp2.Text = "The current number of Rows is: " + grid1.RowDefinitions.Count;
        }

        private void rem5Col(object sender, RoutedEventArgs e)
        {
            if (grid1.ColumnDefinitions.Count < 5)
            {
                tp1.Text = "There aren't five Columns to Remove!";
            }
            else
            {
                grid1.ColumnDefinitions.RemoveRange(0,5);
            }
        }

        private void rem5Row(object sender, RoutedEventArgs e)
        {
            if (grid1.RowDefinitions.Count < 5)
            {
                tp1.Text = "There aren't five Rows to Remove!";
            }
            else
            {
                grid1.RowDefinitions.RemoveRange(0, 5);
            }
        }

        private void containsRow(object sender, RoutedEventArgs e)
        {
            if (grid1.RowDefinitions.Contains(rowDef1))
            {
                tp2.Text = "Grid Contains RowDefinition rowDef1";
            }
            else
            {
                tp2.Text = "Grid Does Not Contain RowDefinition rowDef1";
            }
        }

        private void containsCol(object sender, RoutedEventArgs e)
        {
            if (grid1.ColumnDefinitions.Contains(colDef1))
            {
                tp3.Text = "Grid Contains ColumnDefinition colDef1";
            }
            else
            {
                tp3.Text = "Grid Does Not Contain ColumnDefinition colDef1";
            }
        }

        private void colReadOnly(object sender, RoutedEventArgs e)
        {
            tp4.Text = "RowDefinitionsCollection IsReadOnly?: " + grid1.RowDefinitions.IsReadOnly.ToString();
            tp5.Text = "ColumnDefinitionsCollection IsReadOnly?: " + grid1.ColumnDefinitions.IsReadOnly.ToString();
        }

        private void insertRowAt(object sender, RoutedEventArgs e)
        {
            rowDef1 = new RowDefinition();
            grid1.RowDefinitions.Insert(grid1.RowDefinitions.Count, rowDef1);
            tp1.Text = "RowDefinition added at index position " + grid1.RowDefinitions.IndexOf(rowDef1).ToString();
        }

        private void insertColAt(object sender, RoutedEventArgs e)
        {
            colDef1 = new ColumnDefinition();
            grid1.ColumnDefinitions.Insert(grid1.ColumnDefinitions.Count, colDef1);
            tp2.Text = "ColumnDefinition added at index position " + grid1.ColumnDefinitions.IndexOf(colDef1).ToString();
        }
    }
}
```

#### [Position the Child Elements of a Grid](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-position-the-child-elements-of-a-grid)

此示例演示如何使用 get 和 set 方法上定义的[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)来定位子元素。

##### 示例

下面的示例定义一个父级[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素 (`grid1`)，有三个列和三个行。 子[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)元素 (`rect1`) 添加到[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)中的列位置零，行位置零。 [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) 元素表示方法可以调用以进行重新定位[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)元素内的[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)。 当用户单击按钮时，激活相关的方法。

```xaml
<Window  
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    x:Class="grid_getset_methods.Window1"
    Title="Grid Methods Sample">
    <Border BorderBrush="Black" Background="White" BorderThickness="2">
    <DockPanel VerticalAlignment="Top" HorizontalAlignment="Left" Margin="10">
      <TextBlock FontSize="20" FontWeight="Bold" DockPanel.Dock="Top">Grid Methods Sample</TextBlock>
      <TextBlock DockPanel.Dock="Top">Click the buttons on the left to reposition the Rectangle below using methods defined on Grid.</TextBlock>
        <Grid Margin="0,10,15,0" DockPanel.Dock="Left">
          <Grid.ColumnDefinitions>
            <ColumnDefinition/>
            <ColumnDefinition/>
          </Grid.ColumnDefinitions>
          <Grid.RowDefinitions>
            <RowDefinition/>
          </Grid.RowDefinitions>
        <!-- <Snippet1> -->
          <StackPanel Grid.Column="0" Grid.Row="0" HorizontalAlignment="Left" Orientation="Vertical">
            <Button Click="setCol0">Move Rectangle to Column 0</Button>
            <Button Click="setCol1">Move Rectangle to Column 1</Button>
            <Button Click="setCol2" Margin="0,0,0,10">Move Rectangle to Column 2</Button>
            <Button Click="setRow0">Move Rectangle to Row 0</Button>
            <Button Click="setRow1">Move Rectangle to Row 1</Button>
            <Button Click="setRow2" Margin="0,0,0,10">Move Rectangle to Row 2</Button>
            <Button Click="setColspan">Span All Columns</Button>
            <Button Click="setRowspan">Span All Rows</Button>
            <Button Click="clearAll">Clear All</Button>
          </StackPanel>
        </Grid>
      <Grid DockPanel.Dock="Top" Margin="0,10,15,0" HorizontalAlignment="Left" Name="grid1" ShowGridLines="True" Width="400" Height="400" Background="LightSteelBlue">
        <Grid.ColumnDefinitions>
        <ColumnDefinition/>
        <ColumnDefinition/>
        <ColumnDefinition/>
      </Grid.ColumnDefinitions>
      <Grid.RowDefinitions>
        <RowDefinition/>
        <RowDefinition/>
        <RowDefinition/>
      </Grid.RowDefinitions>
        
        <Rectangle Name="rect1" Fill="Silver" Grid.Column="0" Grid.Row="0"/>
        <TextBlock FontSize="15" HorizontalAlignment="Right" VerticalAlignment="Bottom" Grid.Column="0" Grid.Row="0" Margin="5">Column 0, Row 0</TextBlock>
        <TextBlock FontSize="15" HorizontalAlignment="Right" VerticalAlignment="Bottom" Grid.Column="1" Grid.Row="0" Margin="5">Column 1, Row 0</TextBlock>
        <TextBlock FontSize="15" HorizontalAlignment="Right" VerticalAlignment="Bottom" Grid.Column="2" Grid.Row="0" Margin="5">Column 2, Row 0</TextBlock>
        <TextBlock FontSize="15" HorizontalAlignment="Right" VerticalAlignment="Bottom" Grid.Column="0" Grid.Row="1" Margin="5">Column 0, Row 1</TextBlock>
        <TextBlock FontSize="15" HorizontalAlignment="Right" VerticalAlignment="Bottom" Grid.Column="1" Grid.Row="1" Margin="5">Column 1, Row 1</TextBlock>
        <TextBlock FontSize="15" HorizontalAlignment="Right" VerticalAlignment="Bottom" Grid.Column="2" Grid.Row="1" Margin="5">Column 2, Row 1</TextBlock>
        <TextBlock FontSize="15" HorizontalAlignment="Right" VerticalAlignment="Bottom" Grid.Column="0" Grid.Row="2" Margin="5">Column 0, Row 2</TextBlock>
        <TextBlock FontSize="15" HorizontalAlignment="Right" VerticalAlignment="Bottom" Grid.Column="1" Grid.Row="2" Margin="5">Column 1, Row 2</TextBlock>
        <TextBlock FontSize="15" HorizontalAlignment="Right" VerticalAlignment="Bottom" Grid.Column="2" Grid.Row="2" Margin="5">Column 2, Row 2</TextBlock>
      </Grid>
        <!-- </Snippet1> -->

      <TextBlock DockPanel.Dock="Top" Name="txt1"/>
      <TextBlock DockPanel.Dock="Top" Name="txt2"/>
      <TextBlock DockPanel.Dock="Top" Name="txt3"/>
      <TextBlock DockPanel.Dock="Top" Name="txt4"/>
    </DockPanel>
    </Border>	
</Window>
```

下面的代码隐藏示例处理方法，该按钮[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件引发。 该示例将写入到这些方法调用[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素使用相关的 get 方法以输出新属性值作为字符串。

```csharp
private void setCol0(object sender, RoutedEventArgs e) 
{
    Grid.SetColumn(rect1, 0);
    txt1.Text = "Rectangle is in Column " + Grid.GetColumn(rect1).ToString();

}
private void setCol1(object sender, RoutedEventArgs e)
{
    Grid.SetColumn(rect1, 1);
    txt1.Text = "Rectangle is in Column " + Grid.GetColumn(rect1).ToString();
}
private void setCol2(object sender, RoutedEventArgs e)
{
    Grid.SetColumn(rect1, 2);
    txt1.Text = "Rectangle is in Column " + Grid.GetColumn(rect1).ToString();
}
private void setRow0(object sender, RoutedEventArgs e)
{
    Grid.SetRow(rect1, 0);
    txt2.Text = "Rectangle is in Row " + Grid.GetRow(rect1).ToString();
}
private void setRow1(object sender, RoutedEventArgs e)
{
    Grid.SetRow(rect1, 1);
    txt2.Text = "Rectangle is in Row " + Grid.GetRow(rect1).ToString();
}
private void setRow2(object sender, RoutedEventArgs e)
{
    Grid.SetRow(rect1, 2);
    txt2.Text = "Rectangle is in Row " + Grid.GetRow(rect1).ToString();
}
private void setColspan(object sender, RoutedEventArgs e)
{
    Grid.SetColumnSpan(rect1, 3);
    txt3.Text = "ColumnSpan is set to " + Grid.GetColumnSpan(rect1).ToString();
}
private void setRowspan(object sender, RoutedEventArgs e)
{
    Grid.SetRowSpan(rect1, 3);
    txt4.Text = "RowSpan is set to " + Grid.GetRowSpan(rect1).ToString();
}
```

下面是最终的结果 ！

![屏幕快照描述了具有两个列的 WPF 用户界面、 右侧有一个 3x3 网格和左侧具有按钮的网格行和列之间移动一个有色的矩形](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/grid-methods-sample.png)

#### [Share Sizing Properties Between Grids](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-share-sizing-properties-between-grids)

此示例演示如何共享列的大小调整数据和行之间[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素，以使大小调整保持一致。

##### 示例

下面的示例引入了两处[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素作为父级的子元素[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)。 [IsSharedSizeScope](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid.issharedsizescope)附加属性的[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)的父级上定义[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)。

该示例通过使用两个操作的属性值[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)元素; 每个元素表示一个布尔属性值。 当[IsSharedSizeScope](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid.issharedsizescope)属性值设置为`true`，每个列或行成员[SharedSizeGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.definitionbase.sharedsizegroup)共享大小调整信息，无论行或列的内容。

```xaml
<DockPanel Name="dp1" Grid.IsSharedSizeScope="False" VerticalAlignment="Top" HorizontalAlignment="Left" Margin="10">
```

...

```xaml
   <StackPanel Orientation="Horizontal" DockPanel.Dock="Top">  
       <Button Click="setTrue" Margin="0,0,10,10">Set IsSharedSizeScope="True"</Button>
       <Button Click="setFalse" Margin="0,0,10,10">Set IsSharedSizeScope="False"</Button>
   </StackPanel> 

   <StackPanel Orientation="Horizontal" DockPanel.Dock="Top">

   <Grid ShowGridLines="True" Margin="0,0,10,0">
     <Grid.ColumnDefinitions>
       <ColumnDefinition SharedSizeGroup="FirstColumn"/>
       <ColumnDefinition SharedSizeGroup="SecondColumn"/>
     </Grid.ColumnDefinitions>
     <Grid.RowDefinitions>
       <RowDefinition Height="Auto" SharedSizeGroup="FirstRow"/>
     </Grid.RowDefinitions>

       <Rectangle Fill="Silver" Grid.Column="0" Grid.Row="0" Width="200" Height="100"/>
       <Rectangle Fill="Blue" Grid.Column="1" Grid.Row="0" Width="150" Height="100"/>

       <TextBlock Grid.Column="0" Grid.Row="0" FontWeight="Bold">First Column</TextBlock>
       <TextBlock Grid.Column="1" Grid.Row="0" FontWeight="Bold">Second Column</TextBlock>
   </Grid>

   <Grid ShowGridLines="True">
     <Grid.ColumnDefinitions>
       <ColumnDefinition SharedSizeGroup="FirstColumn"/>
       <ColumnDefinition SharedSizeGroup="SecondColumn"/>
     </Grid.ColumnDefinitions>
     <Grid.RowDefinitions>        
       <RowDefinition Height="Auto" SharedSizeGroup="FirstRow"/>
     </Grid.RowDefinitions>

       <Rectangle Fill="Silver" Grid.Column="0" Grid.Row="0"/>
       <Rectangle Fill="Blue" Grid.Column="1" Grid.Row="0"/>

       <TextBlock Grid.Column="0" Grid.Row="0" FontWeight="Bold">First Column</TextBlock>
       <TextBlock Grid.Column="1" Grid.Row="0" FontWeight="Bold">Second Column</TextBlock>
   </Grid>
   
   </StackPanel>

   <TextBlock Margin="10" DockPanel.Dock="Top" Name="txt1"/>
```

下面的代码隐藏示例处理方法，该按钮[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件引发。 该示例将写入到这些方法调用的结果[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素使用相关的 get 方法以输出新属性值作为字符串。

```csharp
private void setTrue(object sender, System.Windows.RoutedEventArgs e)
{
    Grid.SetIsSharedSizeScope(dp1, true);
    txt1.Text = "IsSharedSizeScope Property is set to " + Grid.GetIsSharedSizeScope(dp1).ToString();
}

private void setFalse(object sender, System.Windows.RoutedEventArgs e)
{
    Grid.SetIsSharedSizeScope(dp1, false);
    txt1.Text = "IsSharedSizeScope Property is set to " + Grid.GetIsSharedSizeScope(dp1).ToString();
}
```