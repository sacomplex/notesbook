# [Viewbox](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/viewbox)

[Viewbox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewbox)控件用来拉伸或缩放的子元素。

## [Apply Stretch Properties to the Contents of a Viewbox](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-apply-stretch-properties-to-the-contents-of-a-viewbox)

此示例演示如何更改的值[StretchDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewbox.stretchdirection)并[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewbox.stretch)的属性[Viewbox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewbox)。

第一个示例使用可扩展应用程序标记语言 (XAML)来定义[Viewbox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewbox)元素。 它将分配[MaxWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.maxwidth)和[MaxHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.maxheight)为 400。 示例嵌套[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)元素内的[Viewbox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewbox)。 [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) 有关的属性值相对应的元素[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewbox.stretch)并[StretchDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stretchdirection)枚举操作的嵌套的拉伸行为[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)。

```xaml
<StackPanel Margin="0,0,0,10" HorizontalAlignment="Center" Orientation="Horizontal" DockPanel.Dock="Top">
    <Button Name="btn1" Click="stretchNone">Stretch="None"</Button>
    <Button Name="btn2" Click="stretchFill">Stretch="Fill"</Button>
    <Button Name="btn3" Click="stretchUni">Stretch="Uniform"</Button>
    <Button Name="btn4" Click="stretchUniFill">Stretch="UniformToFill"</Button>
</StackPanel>

<StackPanel Margin="0,0,0,10" HorizontalAlignment="Center" Orientation="Horizontal" DockPanel.Dock="Top">
    <Button Name="btn5" Click="sdUpOnly">StretchDirection="UpOnly"</Button>
    <Button Name="btn6" Click="sdDownOnly">StretchDirection="DownOnly"</Button>
    <Button Name="btn7" Click="sdBoth">StretchDirection="Both"</Button>
 </StackPanel>        

<TextBlock DockPanel.Dock="Top" Name="txt1" />
<TextBlock DockPanel.Dock="Top" Name="txt2" />

<StackPanel HorizontalAlignment="Center" VerticalAlignment="Center">
    <Viewbox MaxWidth="500" MaxHeight="500" Name="vb1">
        <Image Source="tulip_farm.jpg"/>
    </Viewbox>    
</StackPanel>
```

下面的代码隐藏文件句柄[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件的上一个XAML的示例定义。

```csharp
private void stretchNone(object sender, RoutedEventArgs e)
{
    vb1.Stretch = System.Windows.Media.Stretch.None;
    txt1.Text = "Stretch is now set to None.";
}

private void stretchFill(object sender, RoutedEventArgs e)
{
    vb1.Stretch = System.Windows.Media.Stretch.Fill;
    txt1.Text = "Stretch is now set to Fill.";
}

private void stretchUni(object sender, RoutedEventArgs e)
{
    vb1.Stretch = System.Windows.Media.Stretch.Uniform;
    txt1.Text = "Stretch is now set to Uniform.";
}

private void stretchUniFill(object sender, RoutedEventArgs e)
{
    vb1.Stretch = System.Windows.Media.Stretch.UniformToFill;
    txt1.Text = "Stretch is now set to UniformToFill.";
}

private void sdUpOnly(object sender, RoutedEventArgs e)
{
    vb1.StretchDirection = System.Windows.Controls.StretchDirection.UpOnly;
    txt2.Text = "StretchDirection is now UpOnly.";
}

private void sdDownOnly(object sender, RoutedEventArgs e)
{
    vb1.StretchDirection = System.Windows.Controls.StretchDirection.DownOnly;
    txt2.Text = "StretchDirection is now DownOnly.";
}

private void sdBoth(object sender, RoutedEventArgs e)
{
    vb1.StretchDirection = System.Windows.Controls.StretchDirection.Both;
    txt2.Text = "StretchDirection is now Both.";
}
```