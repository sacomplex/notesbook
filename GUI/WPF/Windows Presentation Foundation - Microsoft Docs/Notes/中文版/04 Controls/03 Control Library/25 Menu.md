## [Menu](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/menu)

A[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)是允许的命令或事件处理程序与关联的元素的分层组织的控件。 每个[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)可以包含多个[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)控件。 每个[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)可以调用命令或调用`Click`事件处理程序。 A[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)还可以有多个[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)元素作为子级，构成子菜单。

下图显示菜单控件的三个不同的状态。 没有设备如鼠标指针停留在线上时的默认状态[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)。 当鼠标指针悬停在焦点状态时发生[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)并且通过单击鼠标按钮时发生按下的状态[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)。

![菜单状态](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/ss-ctl-menu.gif)
不同状态中的菜单

### [Menu Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/menu-overview)

[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)类可用于组织与命令和事件处理程序的层次结构顺序关联的元素。 每个[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)元素包含一系列[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)元素。

#### Menu 控件

[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)控件显示的项的指定命令或应用程序的选项列表。 通常情况下，单击[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)打开子菜单或导致应用程序执行某个命令。

#### 创建菜单

下面的示例创建[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)操作中的文本[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。 [Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)包含[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)对象使用[Command](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem.command)， [IsCheckable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem.ischeckable)，并[Header](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headereditemscontrol.header)属性和[Checked](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem.checked)， [Unchecked](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem.unchecked)，和[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem.click)事件。

```xaml
<Menu>
  <MenuItem Header="_Edit">
    <MenuItem Command="ApplicationCommands.Copy"/>
    <MenuItem Command="ApplicationCommands.Cut"/>
    <MenuItem Command="ApplicationCommands.Paste"/>
  </MenuItem>
  <MenuItem Header="_Font">
    <MenuItem Header="_Bold" IsCheckable="True"
              Checked="Bold_Checked"
              Unchecked="Bold_Unchecked"/>
    <MenuItem Header="_Italic" IsCheckable="True"
              Checked="Italic_Checked"
              Unchecked="Italic_Unchecked"/>
    <Separator/>
    <MenuItem Header="I_ncrease Font Size"
              Click="IncreaseFont_Click"/>
    <MenuItem Header="_Decrease Font Size"
              Click="DecreaseFont_Click"/>
  </MenuItem>
</Menu>
<TextBox Name="textBox1" TextWrapping="Wrap"
         Margin="2">
  The quick brown fox jumps over the lazy dog.
</TextBox>
```

```csharp
private void Bold_Checked(object sender, RoutedEventArgs e)
{
    textBox1.FontWeight = FontWeights.Bold;
}

private void Bold_Unchecked(object sender, RoutedEventArgs e)
{
    textBox1.FontWeight = FontWeights.Normal;
}

private void Italic_Checked(object sender, RoutedEventArgs e)
{
    textBox1.FontStyle = FontStyles.Italic;
}

private void Italic_Unchecked(object sender, RoutedEventArgs e)
{
    textBox1.FontStyle = FontStyles.Normal;
}

private void IncreaseFont_Click(object sender, RoutedEventArgs e)
{
    if (textBox1.FontSize < 18)
    {
        textBox1.FontSize += 2;
    }
}

private void DecreaseFont_Click(object sender, RoutedEventArgs e)
{
    if (textBox1.FontSize > 10)
    {
        textBox1.FontSize -= 2;
    }
}
```

```vb
Private Sub Bold_Checked(ByVal sender As Object, ByVal e As RoutedEventArgs)
    textBox1.FontWeight = FontWeights.Bold
End Sub

Private Sub Bold_Unchecked(ByVal sender As Object, ByVal e As RoutedEventArgs)
    textBox1.FontWeight = FontWeights.Normal
End Sub

Private Sub Italic_Checked(ByVal sender As Object, ByVal e As RoutedEventArgs)
    textBox1.FontStyle = FontStyles.Italic
End Sub

Private Sub Italic_Unchecked(ByVal sender As Object, ByVal e As RoutedEventArgs)
    textBox1.FontStyle = FontStyles.Normal
End Sub

Private Sub IncreaseFont_Click(ByVal sender As Object, ByVal e As RoutedEventArgs)
    If textBox1.FontSize < 18 Then
        textBox1.FontSize += 2
    End If
End Sub

Private Sub DecreaseFont_Click(ByVal sender As Object, ByVal e As RoutedEventArgs)
    If textBox1.FontSize > 10 Then
        textBox1.FontSize -= 2
    End If
End Sub
```

#### 使用键盘快捷方式的菜单项

键盘快捷方式可通过键盘来调用输入的字符组合[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)命令。 例如，“复制”的快捷方式是 CTRL+C。 有两个属性将与键盘快捷方式和菜单项 —[InputGestureText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem.inputgesturetext)或[Command](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem.command)。

##### InputGestureText

下面的示例演示如何使用[InputGestureText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem.inputgesturetext)要分配到的键盘快捷方式文本属性[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)控件。 这仅将键盘快捷方式放置在菜单项中。 它不会将与命令关联[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)。 应用程序必须处理用户的输入才能执行操作。

```xaml
<MenuItem Header="_Cut" InputGestureText="Ctrl+X"/>
<MenuItem Header="_Find" InputGestureText="Ctrl+F"/>
```

##### 命令

下面的示例演示如何使用[Command](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem.command)要关联属性**开放**并**保存**命令[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)控件。 命令属性不仅将命令与[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)，但它还会提供输入的手势文本以用作快捷方式。

```xaml
<MenuItem Header="_Open" Command="ApplicationCommands.Open"/>
<MenuItem Header="_Save" Command="ApplicationCommands.Save"/>
```

[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)类还具有[CommandTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem.commandtarget)属性，用于指定发生命令的元素。 如果[CommandTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem.commandtarget)未设置，具有键盘焦点的元素接收命令。 有关命令的详细信息，请参阅[命令概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/commanding-overview)。

#### 菜单样式设置

使用控件样式设置，你可以显著改变外观和行为[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)而无需编写自定义控件的控件。 除了设置视觉属性，还可以应用[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)到控件的各个部分，更改通过属性，控件的部件的行为或添加其他部分，或更改控件的布局。 下面的示例演示几种方法添加[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)到[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)控件。

第一个代码示例定义了[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)调用`Simple`，演示如何在样式中使用当前系统设置。 代码将 `MenuHighlightBrush` 的颜色分配为菜单的背景色，将 `MenuTextBrush` 分配为菜单的前景色。 请注意，使用资源键分配画笔。

```xaml
<Style x:Key="Simple" TargetType="{x:Type MenuItem}">
  <Setter Property = "Background" Value= "{DynamicResource {x:Static SystemColors.MenuHighlightBrushKey}}"/>
  <Setter Property = "Foreground" Value= "{DynamicResource {x:Static SystemColors.MenuTextBrushKey}}"/>
  <Setter Property = "Height" Value= "{DynamicResource {x:Static SystemParameters.CaptionHeightKey}}"/>
</Style>
```

下面的示例使用[Trigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.trigger)元素，您可以更改的外观[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)发生的事件响应[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)。 当将鼠标移到[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)的前景色和字体特征的菜单项的更改。

```xaml
<Style x:Key="Triggers" TargetType="{x:Type MenuItem}">
  <Style.Triggers>
    <Trigger Property="MenuItem.IsMouseOver" Value="true">
      <Setter Property = "Foreground" Value="Red"/>
      <Setter Property = "FontSize" Value="16"/>
      <Setter Property = "FontStyle" Value="Italic"/>
    </Trigger>
  </Style.Triggers>
</Style>
```