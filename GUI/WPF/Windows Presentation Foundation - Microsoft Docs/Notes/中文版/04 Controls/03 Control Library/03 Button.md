## [Button](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/button)

A[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)控件响应用户输入从鼠标、 键盘、 触笔或其他输入的设备和引发[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件。 A[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)是一个基本用户界面 (UI)组件，它可以包含简单内容，例如文本，并还可以包含复杂内容，如图像和[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)控件。

![按钮状态](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/ss-ctl-buttons.bmp)

### 本节内容

[创建包含图像的按钮](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-create-a-button-that-has-an-image)

### [Create a Button That Has an Image](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-create-a-button-that-has-an-image)

此示例演示如何上包含一个图像[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。

#### 示例

下面的示例创建两个[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)控件。 一个[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)包含文本，另一个包含图像。 映像是在一个名为数据，这是该示例的项目文件夹的子文件夹中。 当用户单击[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)具有图像、 背景和其他文本[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)更改。

此示例将创建[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)通过使用标记控制，但使用代码来编写[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件处理程序。

```xaml
<Button Name="btn5" Width="50" Height="30" Click="OnClick5">
  <Image Source="data\flower.jpg"></Image>
</Button>
<Button Name="btn6" BorderBrush="Black">Click the picture.</Button>
```

```csharp
void OnClick5(object sender, RoutedEventArgs e)
{
    btn6.FontSize = 16;
    btn6.Content = "This is my favorite photo.";
    btn6.Background = Brushes.Red;
}
```