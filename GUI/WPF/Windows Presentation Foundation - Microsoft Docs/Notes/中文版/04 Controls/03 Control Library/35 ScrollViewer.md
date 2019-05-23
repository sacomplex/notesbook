# [ScrollViewer](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/scrollviewer)

[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)控件创建其中可以水平或垂直滚动内容的可滚动区域。

## [ScrollViewer Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/scrollviewer-overview)

用户界面中的内容通常比计算机屏幕的显示区域大。 [ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)控件提供了方便地启用中的内容滚动Windows Presentation Foundation (WPF)应用程序。 本主题介绍[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)元素，并提供了几个用法示例。

### ScrollViewer 控件

有两个预定义的元素启用滚动WPF应用程序：[ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar)和[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)。 [ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)控件封装水平滚动条和垂直[ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar)元素和内容的容器 (如[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)元素) 以便在可滚动区域中显示其他可见元素。 若要使用必须生成自定义对象[ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar)元素实现内容滚动。 但是，可以使用[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)元素本身，因为它是一个复合控件封装[ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar)功能。

[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)控件响应鼠标和键盘命令，并定义用于按预设的增量滚动内容的许多方法。 可以使用[ScrollChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer.scrollchanged)事件来检测更改[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)状态。

一个[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)只能有一个子级，通常[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)元素，可承载[Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.children)元素的集合。 [Content](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter.content)属性定义的唯一子级[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)。

### 物理滚动与逻辑滚动

物理滚动用于按预设的物理增量（通常按以像素为单位声明的值）滚动内容。 逻辑滚动用于滚动到逻辑树中的下一项。 物理滚动是大多数的默认滚动行为[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)元素。 WPF 同时支持这两种类型的滚动。

#### IScrollInfo 接口

[IScrollInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.iscrollinfo)接口表示的主滚动区域内[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)或派生的控件。 该接口定义的滚动属性和方法，可由实现[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)需要按逻辑单元，而不按物理增量滚动元素。 实例转换[IScrollInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.iscrollinfo)到派生[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)，然后使用其滚动方法提供了一种滚动到下一个逻辑单位子集合，而不是按像素增量有效方式。 默认情况下，[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)控件支持按物理单位滚动。

[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel) 并[VirtualizingStackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel)都可实现[IScrollInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.iscrollinfo)和本身支持逻辑滚动。 对于布局控件，本身支持逻辑滚动，您仍可以完成通过包装主机物理滚动[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)中的元素[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)并设置[CanContentScroll](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer.cancontentscroll)属性设置为`false`。

下面的代码示例演示如何强制转换的实例[IScrollInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.iscrollinfo)到[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)，并使用内容滚动方法 ([LineUp](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.iscrollinfo.lineup)和[LineDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.iscrollinfo.linedown)) 的接口定义。

C#复制

```csharp
private void spLineUp(object sender, RoutedEventArgs e)
{
    ((IScrollInfo)sp1).LineUp();
}
private void spLineDown(object sender, RoutedEventArgs e)
{
    ((IScrollInfo)sp1).LineDown();
}
```



### 定义和使用 ScrollViewer 元素

下面的示例创建[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)包含一些文本和一个矩形的窗口中。 [ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar) 元素出现仅当它们是必需的。 当调整窗口大小时[ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar)元素将出现然后消失的值已更新由于[ComputedHorizontalScrollBarVisibility](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer.computedhorizontalscrollbarvisibility)和[ComputedVerticalScrollBarVisibility](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer.computedverticalscrollbarvisibility)属性。

```csharp
// Create the application's main window
mainWindow = new Window ();
mainWindow.Title = "ScrollViewer Sample";

// Define a ScrollViewer
myScrollViewer = new ScrollViewer();
myScrollViewer.HorizontalScrollBarVisibility = ScrollBarVisibility.Auto;

// Add Layout control
myStackPanel = new StackPanel();
myStackPanel.HorizontalAlignment = HorizontalAlignment.Left;
myStackPanel.VerticalAlignment = VerticalAlignment.Top;

TextBlock myTextBlock = new TextBlock();
myTextBlock.TextWrapping = TextWrapping.Wrap;
myTextBlock.Margin = new Thickness(0, 0, 0, 20);
myTextBlock.Text = "Scrolling is enabled when it is necessary. Resize the Window, making it larger and smaller.";

Rectangle myRectangle = new Rectangle();
myRectangle.Fill = Brushes.Red;
myRectangle.Width = 500;
myRectangle.Height = 500;

// Add child elements to the parent StackPanel
myStackPanel.Children.Add(myTextBlock);
myStackPanel.Children.Add(myRectangle);
            
// Add the StackPanel as the lone Child of the Border
myScrollViewer.Content = myStackPanel;

// Add the Border as the Content of the Parent Window Object
mainWindow.Content = myScrollViewer;
mainWindow.Show ();
```

XAML复制

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      WindowTitle="ScrollViewer Sample">
  <ScrollViewer HorizontalScrollBarVisibility="Auto">
    <StackPanel VerticalAlignment="Top" HorizontalAlignment="Left">
      <TextBlock TextWrapping="Wrap" Margin="0,0,0,20">Scrolling is enabled when it is necessary. 
      Resize the window, making it larger and smaller.</TextBlock>
      <Rectangle Fill="Red" Width="500" Height="500"></Rectangle>
    </StackPanel>
  </ScrollViewer>
</Page>
```

### 设置 ScrollViewer 的样式

Windows Presentation foundation 中的所有控件都一样[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)可以设置要更改默认呈现行为的控件的样式。 有关控件样式设置的其他信息，请参阅[样式设置和模板化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/styling-and-templating)。

### 对文档进行分页

对于文档内容，一种替代滚动的方法是选择支持分页的文档容器。 [FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument) 对于旨在中查看控件，如托管的文档是[FlowDocumentPageViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentpageviewer)，内容分页支持跨多个页面，从而无需进行滚动。 [DocumentViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.documentviewer) 提供一种解决方案，用于查看[FixedDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.fixeddocument)的内容，它使用传统的滚动来显示超出显示区域的领域。

有关文档格式和演示选项的其他信息，请参阅 [WPF 中的文档](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/documents-in-wpf)。

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/scrollviewer-how-to-topics)

在本部分中的主题演示如何使用[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)元素来创建应用程序中的可滚动区域。

### 本节内容

[处理 ScrollChanged 事件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-handle-the-scrollchanged-event)
[使用 IScrollInfo 接口滚动内容](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-scroll-content-by-using-the-iscrollinfo-interface)
[使用 ScrollViewer 的内容滚动方法](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-use-the-content-scrolling-methods-of-scrollviewer)

### [Handle the ScrollChanged Event](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-handle-the-scrollchanged-event)

此示例演示如何处理[ScrollChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer.scrollchanged)事件的[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)。

一个[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)具有元素[Paragraph](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.paragraph)中定义部分XAML。 当[ScrollChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer.scrollchanged)由于用户交互而发生的事件，调用处理程序，并且文本写入到[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)，该值指示事件已发生。

```xaml
<ScrollViewer Name="svrContent" CanContentScroll="False" ScrollChanged="sChanged">

  <FlowDocument FontFamily="Arial" PageWidth="400">
    <Paragraph>
      Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut
      laoreet dolore magna aliquam erat volutpat.  Ut wisi enim ad minim veniam, quis nostrud exerci tation
      ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure.
      Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut
      laoreet dolore magna aliquam erat volutpat.  Ut wisi enim ad minim veniam, quis nostrud exerci tation
      ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure.
      Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut
      laoreet dolore magna aliquam erat volutpat.  Ut wisi enim ad minim veniam, quis nostrud exerci tation
      ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure.
    </Paragraph>
```

```xaml
    <Paragraph>
      Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut
      laoreet dolore magna aliquam erat volutpat.  Ut wisi enim ad minim veniam, quis nostrud exerci tation
      ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure.
      Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut
      laoreet dolore magna aliquam erat volutpat.  Ut wisi enim ad minim veniam, quis nostrud exerci tation
      ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure.
      Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut
      laoreet dolore magna aliquam erat volutpat.  Ut wisi enim ad minim veniam, quis nostrud exerci tation
      ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure.
    </Paragraph>

  </FlowDocument>
</ScrollViewer>
```

```csharp
private void sChanged(object sender, ScrollChangedEventArgs e)
{
    if (svrContent.CanContentScroll == true)
    {
        tBlock1.Foreground = System.Windows.Media.Brushes.Red;
        tBlock1.Text = "ScrollChangedEvent just Occurred";
        tBlock2.Text = "ExtentHeight is now " + e.ExtentHeight.ToString();
        tBlock3.Text = "ExtentWidth is now " + e.ExtentWidth.ToString();
        tBlock4.Text = "ExtentHeightChange was " + e.ExtentHeightChange.ToString();
        tBlock5.Text = "ExtentWidthChange was " + e.ExtentWidthChange.ToString();
        tBlock6.Text = "HorizontalOffset is now " + e.HorizontalOffset.ToString();
        tBlock7.Text = "VerticalOffset is now " + e.VerticalOffset.ToString();
        tBlock8.Text = "HorizontalChange was " + e.HorizontalChange.ToString();
        tBlock9.Text = "VerticalChange was " + e.VerticalChange.ToString();
        tBlock10.Text = "ViewportHeight is now " + e.ViewportHeight.ToString();
        tBlock11.Text = "ViewportWidth is now " + e.ViewportWidth.ToString();
        tBlock12.Text = "ViewportHeightChange was " + e.ViewportHeightChange.ToString();
        tBlock13.Text = "ViewportWidthChange was " + e.ViewportWidthChange.ToString();
    }
    else
    {
        tBlock1.Text = "";
    }
```

### [Scroll Content by Using the IScrollInfo Interface](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-scroll-content-by-using-the-iscrollinfo-interface)

此示例演示如何通过使用滚动内容[IScrollInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.iscrollinfo)接口。

下面的示例演示的功能[IScrollInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.iscrollinfo)接口。 此示例将创建[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)中的元素可扩展应用程序标记语言 (XAML)嵌套在父[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)。 子元素[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)可以通过使用定义的方法以逻辑方式滚动[IScrollInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.iscrollinfo)界面和强制转换为的实例[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)(`sp1`) 在代码中。

```xaml
<Border BorderBrush="Black" Background="White" BorderThickness="2" Width="500" Height="500">
    <ScrollViewer Name="sv1" CanContentScroll="True" VerticalScrollBarVisibility="Visible" HorizontalScrollBarVisibility="Visible">
        <StackPanel Name="sp1">
            <Button>Button 1</Button>
            <Button>Button 2</Button>
            <Button>Button 3</Button>
            <Button>Button 4</Button>
            <Button>Button 5</Button>
            <Rectangle Width="700" Height="500" Fill="Purple"/>
            <TextBlock>Rectangle 1</TextBlock>
            <Rectangle Width="700" Height="500" Fill="Red"/>
            <TextBlock>Rectangle 2</TextBlock>
            <Rectangle Width="700" Height="500" Fill="Green"/>
            <TextBlock>Rectangle 3</TextBlock>
        </StackPanel> 
    </ScrollViewer>
</Border>
```

每个[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)中XAML文件触发控制滚动行为中的关联自定义方法[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)。 下面的示例演示如何使用[LineUp](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.iscrollinfo.lineup)并[LineDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.iscrollinfo.linedown)方法; 它还以一般方式演示如何使用所有定位方法的[IScrollInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.iscrollinfo)类定义。

```csharp
private void spLineUp(object sender, RoutedEventArgs e)
{
    ((IScrollInfo)sp1).LineUp();
}
private void spLineDown(object sender, RoutedEventArgs e)
{
    ((IScrollInfo)sp1).LineDown();
}
```

### [Use the Content-Scrolling Methods of ScrollViewer](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-use-the-content-scrolling-methods-of-scrollviewer)

此示例演示如何使用的滚动方法[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)元素。 这些方法提供增量滚动内容的行或页上，在[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)。

下面的示例创建[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)名为`sv1`，它承载子[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素。 因为[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)大于父级[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)，以便滚动显示滚动条。 [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) 在单独左侧停靠，其元素表示的各种滚动方法[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)。 每个[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)中XAML文件调用相关的自定义方法，用于控制中的滚动行为[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)。

```xaml
<StackPanel DockPanel.Dock="Left" Width="150">
  <Button Margin="3,0,0,2" Background="White" Click="svLineUp">Adjust Line Up</Button>
  <Button Margin="3,0,0,2" Background="White" Click="svLineDown">Adjust Line Down</Button>
  <Button Margin="3,0,0,2" Background="White" Click="svLineRight">Adjust Line Right</Button>
  <Button Margin="3,0,0,2" Background="White" Click="svLineLeft">Adjust Line Left</Button>
  <Button Margin="3,0,0,2" Background="White" Click="svPageUp">Adjust Page Up</Button>
  <Button Margin="3,0,0,2" Background="White" Click="svPageDown">Adjust Page Down</Button>
  <Button Margin="3,0,0,2" Background="White" Click="svPageRight">Adjust Page Right</Button>
  <Button Margin="3,0,0,2" Background="White" Click="svPageLeft">Adjust Page Left</Button>
  <TextBlock Name="txt2" TextWrapping="Wrap"/>
</StackPanel>

<Border BorderBrush="Black" Background="White" BorderThickness="2" Height="520" Width="520" VerticalAlignment="Top">
  <ScrollViewer VerticalScrollBarVisibility="Visible" HorizontalScrollBarVisibility="Auto" Name="sv1">
    <TextBlock TextWrapping="Wrap" Width="800" Height="1000" Name="txt1"/> 
  </ScrollViewer>
</Border>
```

下面的示例使用[LineUp](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer.lineup)和[LineDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer.linedown)方法。

```csharp
private void svLineUp(object sender, RoutedEventArgs e)
{
    sv1.LineUp();
}
private void svLineDown(object sender, RoutedEventArgs e)
{
    sv1.LineDown();
}
```