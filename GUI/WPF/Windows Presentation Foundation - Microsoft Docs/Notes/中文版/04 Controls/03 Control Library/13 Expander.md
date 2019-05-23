## [Expander](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/expander)

[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)允许用户查看标头并展开该标头，以查看更多详细信息，或折叠到标头部分。

下图提供其展开位置在此控件的一个示例。

![Expander 示例](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/expanderexample.jpg)
Expander 控件

### 本节内容

[扩展器概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/expander-overview)
[帮助主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/expander-how-to-topics)

### [Expander Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/expander-overview)

[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)控件提供了一种方法来提供类似于一个窗口，并且包括一个标头的可展开区域中的内容。

#### 创建简单的 Expander

下面的示例演示如何创建一个简单[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)控件。 此示例将创建[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)看起来像前面的图示。

```xaml
<Expander Name="myExpander" Background="Tan" 
          HorizontalAlignment="Left" Header="My Expander" 
          ExpandDirection="Down" IsExpanded="True" Width="100">
  <TextBlock TextWrapping="Wrap">
    Lorem ipsum dolor sit amet, consectetur
    adipisicing elit, sed do eiusmod tempor incididunt ut
    labore et dolore magna aliqua
  </TextBlock>
</Expander>
```

[Content](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.content)并[Header](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headeredcontentcontrol.header)的[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)还可以包含复杂内容，如[RadioButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.radiobutton)和[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)对象。

#### 设置展开内容区域的方向

您可以设置的内容区域[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)控件中的四个方向一个展开 ([Down](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expanddirection#System_Windows_Controls_ExpandDirection_Down)， [Up](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expanddirection#System_Windows_Controls_ExpandDirection_Up)， [Left](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expanddirection#System_Windows_Controls_ExpandDirection_Left)，或[Right](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expanddirection#System_Windows_Controls_ExpandDirection_Right)) 使用[ExpandDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expanddirection)属性。 当内容区域处于折叠状态，仅[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)[Header](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headeredcontentcontrol.header)和及其切换按钮显示。 一个[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)显示方向箭头的控件用作一个切换按钮以展开或折叠内容区域。 展开后，[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)尝试在类似于窗口的区域中显示其所有的内容。

#### 在面板中控制 Expander 的大小

如果[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)控件是继承的布局控件内[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)，如[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)，没有指定[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)上[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)时[ExpandDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander.expanddirection)属性设置为[Down](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expanddirection#System_Windows_Controls_ExpandDirection_Down)或[Up](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expanddirection#System_Windows_Controls_ExpandDirection_Up)。 同样，不要指定[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)上[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)时[ExpandDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander.expanddirection)属性设置为[Left](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expanddirection#System_Windows_Controls_ExpandDirection_Left)或[Right](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expanddirection#System_Windows_Controls_ExpandDirection_Right)。

上设置大小维度时[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)控件，显示展开的内容，方向[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)控制内容使用和显示在其周围的边框区域。 即使内容已折叠，也会显示该边框。 若要设置展开内容区域的大小，设置大小维度上的内容[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)，或如果你想要滚动功能，请在[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)包含的内容。

当[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)控件是中的最后一个元素[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)，Windows Presentation Foundation (WPF)将自动设置[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)维度，以的其余区域相等[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)。 若要防止此默认行为，设置[LastChildFill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.lastchildfill)上的属性[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)对象传递给`false`，或请确保[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)不是中的最后一个元素[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)。

#### 创建可滚动内容

如果内容对于内容区域的大小太大，您可以封装的内容[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)在[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)为了提供可滚动内容。 [Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)控件不会自动提供滚动功能。 如下图所示[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)控件，其中包含[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)控件。

**ScrollViewer 中的 Expander**

![带有 ScrollBar 的 Expander](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/expanderwithscrollbar.jpg)

在将[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)控件中[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)，请设置[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)维度属性对应的方向[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)内容的大小会打开[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)内容区域。 例如，如果您设置[ExpandDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander.expanddirection)上的属性[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)到[Down](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expanddirection#System_Windows_Controls_ExpandDirection_Down)（内容区域向下展开），设置[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)属性上的[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)内容区域的必需高度控制。 如果在上内容本身，而是设置的高度维度[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)无法识别此设置，因此，不提供可滚动内容。

下面的示例演示如何创建[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)控件具有复杂内容并包含[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)控件。 此示例将创建[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)这是类似于本部分的开头图。

```csharp
void MakeExpander()
{
  //Create containing stack panel and assign to Grid row/col
  StackPanel sp = new StackPanel();
  Grid.SetRow(sp, 0);
  Grid.SetColumn(sp, 1);
  sp.Background = Brushes.LightSalmon;

  //Create column title
  TextBlock colTitle = new TextBlock();
  colTitle.Text = "EXPANDER CREATED FROM CODE";
  colTitle.HorizontalAlignment= HorizontalAlignment.Center;
  colTitle.Margin.Bottom.Equals(20);
  sp.Children.Add(colTitle);

  //Create Expander object
  Expander exp = new Expander();

  //Create Bullet Panel for Expander Header
  BulletDecorator bp = new BulletDecorator();
  Image i = new Image();
  BitmapImage bi= new BitmapImage(); 
  bi.UriSource = new Uri(@"pack://application:,,/images/icon.jpg");
  i.Source = bi;
  i.Width = 10;
  bp.Bullet = i;
  TextBlock tb = new TextBlock();
  tb.Text = "My Expander";
  tb.Margin = new Thickness(20,0,0,0);     
  bp.Child = tb;
  exp.Header = bp;

  //Create TextBlock with ScrollViewer for Expander Content
  StackPanel spScroll = new StackPanel();
  TextBlock tbc = new TextBlock();
  tbc.Text =
          "Lorem ipsum dolor sit amet, consectetur adipisicing elit," +
          "sed do eiusmod tempor incididunt ut labore et dolore magna" +
          "aliqua. Ut enim ad minim veniam, quis nostrud exercitation" +
          "ullamco laboris nisi ut aliquip ex ea commodo consequat." +
          "Duis aute irure dolor in reprehenderit in voluptate velit" +
          "esse cillum dolore eu fugiat nulla pariatur. Excepteur sint" +
          "occaecat cupidatat non proident, sunt in culpa qui officia" +
          "deserunt mollit anim id est laborum.";
  tbc.TextWrapping = TextWrapping.Wrap;

  spScroll.Children.Add(tbc);
  ScrollViewer scr = new ScrollViewer();
  scr.Content = spScroll;
  scr.Height = 50;
  exp.Content = scr;

  exp.Width=200;  
  exp.HorizontalContentAlignment= HorizontalAlignment.Stretch;
  //Insert Expander into the StackPanel and add it to the
  //Grid
  sp.Children.Add(exp);
  myGrid.Children.Add(sp);
}
```

```xaml
<Expander Width="200" HorizontalContentAlignment="Stretch">
   <Expander.Header>
     <BulletDecorator>
       <BulletDecorator.Bullet>
         <Image Width="10" Source="images\icon.jpg"/>
       </BulletDecorator.Bullet>
       <TextBlock Margin="20,0,0,0">My Expander</TextBlock>
     </BulletDecorator>
   </Expander.Header>
   <Expander.Content>
     <ScrollViewer Height="50">
       <TextBlock TextWrapping="Wrap">
         Lorem ipsum dolor sit amet, consectetur adipisicing elit, 
         sed do eiusmod tempor incididunt ut labore et dolore magna 
         aliqua. Ut enim ad minim veniam, quis nostrud exercitation 
         ullamco laboris nisi ut aliquip ex ea commodo consequat. 
         Duis aute irure dolor in reprehenderit in voluptate velit 
         esse cillum dolore eu fugiat nulla pariatur. Excepteur sint 
         occaecat cupidatat non proident, sunt in culpa qui officia 
         deserunt mollit anim id est laborum.
       </TextBlock>
     </ScrollViewer>
   </Expander.Content>
 </Expander>
```

#### 使用对齐属性

可以通过设置对齐内容[HorizontalContentAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.horizontalcontentalignment)并[VerticalContentAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.verticalcontentalignment)上的属性[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)控件。 当设置这些属性时，对齐将同时应用于标头和展开的内容。

### [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/expander-how-to-topics)

本部分中的主题介绍如何使用[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)控件。

#### 本节内容

[使用 ScrollViewer 创建扩展器](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-create-an-expander-with-a-scrollviewer)

#### [Create an Expander with a ScrollViewer](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-create-an-expander-with-a-scrollviewer)

此示例演示如何创建[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)包含复杂内容，例如图像和文本的控件。 该示例还包含的内容[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)在[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)控件。

##### 示例

下面的示例演示如何创建[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)。 该示例使用[BulletDecorator](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.bulletdecorator)控件，它包含图像和文本，为了定义[Header](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headeredcontentcontrol.header)。 一个[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)控件提供了用于滚动扩展的内容的方法。

请注意，该示例设置[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)属性上的[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)而不是对的内容。 如果[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)内容，设置[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)不允许用户滚动内容。 [Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)上设置属性[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)控件，此设置适用于[Header](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headeredcontentcontrol.header)和扩展的内容。

```xaml
<Expander Width="200" HorizontalContentAlignment="Stretch">
   <Expander.Header>
     <BulletDecorator>
       <BulletDecorator.Bullet>
         <Image Width="10" Source="images\icon.jpg"/>
       </BulletDecorator.Bullet>
       <TextBlock Margin="20,0,0,0">My Expander</TextBlock>
     </BulletDecorator>
   </Expander.Header>
   <Expander.Content>
     <ScrollViewer Height="50">
       <TextBlock TextWrapping="Wrap">
         Lorem ipsum dolor sit amet, consectetur adipisicing elit, 
         sed do eiusmod tempor incididunt ut labore et dolore magna 
         aliqua. Ut enim ad minim veniam, quis nostrud exercitation 
         ullamco laboris nisi ut aliquip ex ea commodo consequat. 
         Duis aute irure dolor in reprehenderit in voluptate velit 
         esse cillum dolore eu fugiat nulla pariatur. Excepteur sint 
         occaecat cupidatat non proident, sunt in culpa qui officia 
         deserunt mollit anim id est laborum.
       </TextBlock>
     </ScrollViewer>
   </Expander.Content>
 </Expander>
```

```csharp
//Create Expander object
Expander exp = new Expander();

//Create Bullet Panel for Expander Header
BulletDecorator bp = new BulletDecorator();
Image i = new Image();
BitmapImage bi= new BitmapImage(); 
bi.UriSource = new Uri(@"pack://application:,,/images/icon.jpg");
i.Source = bi;
i.Width = 10;
bp.Bullet = i;
TextBlock tb = new TextBlock();
tb.Text = "My Expander";
tb.Margin = new Thickness(20,0,0,0);     
bp.Child = tb;
exp.Header = bp;

//Create TextBlock with ScrollViewer for Expander Content
StackPanel spScroll = new StackPanel();
TextBlock tbc = new TextBlock();
tbc.Text =
        "Lorem ipsum dolor sit amet, consectetur adipisicing elit," +
        "sed do eiusmod tempor incididunt ut labore et dolore magna" +
        "aliqua. Ut enim ad minim veniam, quis nostrud exercitation" +
        "ullamco laboris nisi ut aliquip ex ea commodo consequat." +
        "Duis aute irure dolor in reprehenderit in voluptate velit" +
        "esse cillum dolore eu fugiat nulla pariatur. Excepteur sint" +
        "occaecat cupidatat non proident, sunt in culpa qui officia" +
        "deserunt mollit anim id est laborum.";
tbc.TextWrapping = TextWrapping.Wrap;

spScroll.Children.Add(tbc);
ScrollViewer scr = new ScrollViewer();
scr.Content = spScroll;
scr.Height = 50;
exp.Content = scr;

exp.Width=200;  
exp.HorizontalContentAlignment= HorizontalAlignment.Stretch;
```