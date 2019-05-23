# [TextBlock](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/textblock)

[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)控件提供灵活的文本支持WPF应用程序。 该元素主要面向不需要多个文本段落的基本 UI 方案。

## [TextBlock Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/textblock-overview)

[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)控件提供了灵活的文本支持WPF应用程序。 该元素主要面向不需要多个文本段落的基本 UI 方案。 它支持多个属性启用精确控制呈现，例如[FontFamily](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.fontfamily)， [FontSize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.fontsize)， [FontWeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.fontweight)， [TextEffects](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.texteffects)，和[TextWrapping](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.textwrapping)。 可以使用添加文本内容[Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.text)属性。 在 XAML 中使用时，开始标记和结束标记之间的内容隐式添加为元素的文本。

一个[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)可以非常轻松地实例化元素XAML。

```xaml
<TextBlock FontSize="18" FontWeight="Bold" FontStyle="Italic">
  Hello, world!
</TextBlock>
```

同样，使用情况的[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)在代码中的元素是相对简单。

```csharp
TextBlock myTextBlock = new TextBlock();
myTextBlock.FontSize = 18;
myTextBlock.FontWeight = FontWeights.Bold;
myTextBlock.FontStyle = FontStyles.Italic;
myTextBlock.Text = "Hello, world!";
```