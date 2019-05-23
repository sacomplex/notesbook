# [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/input-and-commands-how-to-topics)

本部分中的主题介绍如何使用 Windows Presentation Foundation (WPF) 中的输入和命令的基础结构。

[启用命令](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-enable-a-command)
[更改光标类型](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-change-the-cursor-type)
[使用焦点事件更改元素的颜色](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-change-the-color-of-an-element-using-focus-events)
[向控件应用 FocusVisualStyle](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-apply-a-focusvisualstyle-to-a-control)
[检测何时按下 Enter 键](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-detect-when-the-enter-key-pressed)
[使用事件创建变换效果](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-create-a-rollover-effect-using-events)
[让对象跟随鼠标指针移动](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-make-an-object-follow-the-mouse-pointer)
[创建 RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-create-a-routedcommand)
[实现 ICommandSource](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-implement-icommandsource)
[将命令挂钩到不支持命令的控件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-hook-up-a-command-to-a-control-with-no-command-support)
[将命令挂钩到支持命令的控件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-hook-up-a-command-to-a-control-with-command-support)

## [Enable a Command](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-enable-a-command)

下面的示例演示如何使用命令在Windows Presentation Foundation (WPF)。 该示例演示如何将相关联[RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand)到[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)，创建[CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding)，并创建事件处理程序实现[RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand)。 有关命令的详细信息，请参阅[命令概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/commanding-overview)。

代码的第一个部分创建用户界面 (UI)，其中包括[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)和一个[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)，并创建[CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding)，将使用的命令处理程序相关联[RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand)。

[Command](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource.command)的属性[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)与关联[Close](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands.close)命令。

[CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding)添加到[CommandBindingCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbindingcollection)根的[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)。 [Executed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding.executed)并[CanExecute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding.canexecute)事件处理程序将附加到此绑定并使用相关联[Close](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands.close)命令。

无需[CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding)没有命令逻辑，只有一种机制来调用命令。 当[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)单击时， [PreviewExecuted](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandmanager.previewexecuted)[RoutedEvent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedevent)跟在命令目标上引发[Executed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandmanager.executed) [RoutedEvent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedevent)。 这些事件会遍历元素树，以查找[CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding)针对该特定命令。 值得注意的是，因为[RoutedEvent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedevent)隧道和冒泡元素树，必须格外小心 where[CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding)放。如果[CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding)上的命令目标或不在的路由的另一个节点同级[RoutedEvent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedevent)，则[CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding)也不能访问。

XAML复制

```xaml
<Window x:Class="WCSamples.Window1"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    Title="CloseCommand"
    Name="RootWindow"
    >
  <Window.CommandBindings>
    <CommandBinding Command="ApplicationCommands.Close"
                    Executed="CloseCommandHandler"
                    CanExecute="CanExecuteHandler"
                    />
  </Window.CommandBindings>
  <StackPanel Name="MainStackPanel">
    <Button Command="ApplicationCommands.Close" 
            Content="Close File" />
  </StackPanel>
</Window>
```

C#复制

```csharp
// Create ui elements.
StackPanel CloseCmdStackPanel = new StackPanel();
Button CloseCmdButton = new Button();
CloseCmdStackPanel.Children.Add(CloseCmdButton);

// Set Button's properties.
CloseCmdButton.Content = "Close File";
CloseCmdButton.Command = ApplicationCommands.Close;

// Create the CommandBinding.
CommandBinding CloseCommandBinding = new CommandBinding(
    ApplicationCommands.Close, CloseCommandHandler, CanExecuteHandler);

// Add the CommandBinding to the root Window.
RootWindow.CommandBindings.Add(CloseCommandBinding);
```

代码实现的下一节[Executed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandmanager.executed)和[CanExecute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding.canexecute)事件处理程序。

[Executed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandmanager.executed)处理程序调用一个方法以关闭打开的文件。 [CanExecute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding.canexecute)处理程序调用的方法来确定文件是否处于打开状态。 如果文件处于打开状态，[CanExecute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.canexecuteroutedeventargs.canexecute)设置为`true`; 否则为设置为`false`。

C#复制

```csharp
// Executed event handler.
private void CloseCommandHandler(object sender, ExecutedRoutedEventArgs e)
{
    // Calls a method to close the file and release resources.
    CloseFile();
}

// CanExecute event handler.
private void CanExecuteHandler(object sender, CanExecuteRoutedEventArgs e)
{
    // Call a method to determine if there is a file open.
    // If there is a file open, then set CanExecute to true.
    if (IsFileOpened())
    {
        e.CanExecute = true;
    }
    // if there is not a file open, then set CanExecute to false.
    else
    {
        e.CanExecute = false;
    }
}
```

## [Change the Cursor Type](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-change-the-cursor-type)

此示例演示如何更改[Cursor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.cursor)的鼠标指针的特定元素和应用程序。

此示例中包含的可扩展应用程序标记语言 (XAML)文件和代码隐藏文件。

创建的用户界面，其中包含[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)以选择所需[Cursor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.cursor)，一对[RadioButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.radiobutton)对象来确定游标更改是否适用于单个元素或适用于整个应用程序，和一个[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)这是新光标应用于的元素。

XAML复制

```xaml
<StackPanel>
  <Border Width="300">
    <StackPanel Orientation="Horizontal"
                HorizontalAlignment="Center">
      <StackPanel Margin="10">
        <Label HorizontalAlignment="Left">Cursor Type</Label>
        <ComboBox Width="100"
                  SelectionChanged="CursorTypeChanged"
                  HorizontalAlignment="Left"
                  Name="CursorSelector">
          <ComboBoxItem Content="AppStarting" />
          <ComboBoxItem Content="ArrowCD" />
          <ComboBoxItem Content="Arrow" />
          <ComboBoxItem Content="Cross" />
          <ComboBoxItem Content="HandCursor" />
          <ComboBoxItem Content="Help" />
          <ComboBoxItem Content="IBeam" />
          <ComboBoxItem Content="No" />
          <ComboBoxItem Content="None" />
          <ComboBoxItem Content="Pen" />
          <ComboBoxItem Content="ScrollSE" />
          <ComboBoxItem Content="ScrollWE" />
          <ComboBoxItem Content="SizeAll" />
          <ComboBoxItem Content="SizeNESW" />
          <ComboBoxItem Content="SizeNS" />
          <ComboBoxItem Content="SizeNWSE" />
          <ComboBoxItem Content="SizeWE" />
          <ComboBoxItem Content="UpArrow" />
          <ComboBoxItem Content="WaitCursor" />
          <ComboBoxItem Content="Custom" />
        </ComboBox>
      </StackPanel>
      <!-- The user can select different cursor types using this ComboBox -->
      <StackPanel Margin="10">
        <Label HorizontalAlignment="Left">Scope of Cursor</Label>
        <StackPanel>
          <RadioButton Name="rbScopeElement" IsChecked="True"
                       Checked="CursorScopeSelected">Display Area Only</RadioButton>
          <RadioButton Name="rbScopeApplication"
                       Checked="CursorScopeSelected">Entire Appliation</RadioButton>
        </StackPanel>
      </StackPanel>
    </StackPanel>
  </Border>
  <!-- When the mouse pointer is over this Border -->
  <!-- the selected cursor type is shown -->
  <Border Name="DisplayArea" Height="250" Width="400"
          Margin="20" Background="AliceBlue">
    <Label HorizontalAlignment="Center">
      Move Mouse Pointer Over This Area
    </Label>
  </Border>
</StackPanel>
```

下面的代码隐藏创建[SelectionChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.selector.selectionchanged)中更改的游标类型时调用的事件处理程序[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)。 Switch 语句的游标名称和集上进行筛选[Cursor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.cursor)上的属性[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)其名为*DisplayArea*。

如果光标更改设置为"整个应用程序"，[OverrideCursor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.mouse.overridecursor)属性设置为[Cursor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.cursor)属性的[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)控件。 这会强制更改对整个应用程序的光标。

C#复制

```csharp
private void CursorTypeChanged(object sender, SelectionChangedEventArgs e)
{
    ComboBox source = e.Source as ComboBox;

    if (source != null)
    {
        ComboBoxItem selectedCursor = source.SelectedItem as ComboBoxItem;

        // Changing the cursor of the Border control 
        // by setting the Cursor property
        switch (selectedCursor.Content.ToString())
        {
            case "AppStarting":
                DisplayArea.Cursor = Cursors.AppStarting;
                break;
            case "ArrowCD":                        
                DisplayArea.Cursor = Cursors.ArrowCD;
                break;
            case "Arrow":
                DisplayArea.Cursor = Cursors.Arrow;
                break;
            case "Cross":
                DisplayArea.Cursor = Cursors.Cross;
                break;
            case "HandCursor":
                DisplayArea.Cursor = Cursors.Hand;
                break;
            case "Help":
                DisplayArea.Cursor = Cursors.Help;
                break;
            case "IBeam":
                DisplayArea.Cursor = Cursors.IBeam;
                break;
            case "No":
                DisplayArea.Cursor = Cursors.No;
                break;
            case "None":
                DisplayArea.Cursor = Cursors.None;
                break;
            case "Pen":
                DisplayArea.Cursor = Cursors.Pen;
                break;
            case "ScrollSE":
                DisplayArea.Cursor = Cursors.ScrollSE;
                break;
            case "ScrollWE":
                DisplayArea.Cursor = Cursors.ScrollWE;
                break;
            case "SizeAll":
                DisplayArea.Cursor = Cursors.SizeAll;
                break;
            case "SizeNESW":
                DisplayArea.Cursor = Cursors.SizeNESW;
                break;
            case "SizeNS":
                DisplayArea.Cursor = Cursors.SizeNS;
                break;
            case "SizeNWSE":
                DisplayArea.Cursor = Cursors.SizeNWSE;
                break;
            case "SizeWE":
                DisplayArea.Cursor = Cursors.SizeWE;
                break;
            case "UpArrow":
                DisplayArea.Cursor = Cursors.UpArrow;
                break;
            case "WaitCursor":
                DisplayArea.Cursor = Cursors.Wait;
                break;
            case "Custom":
                DisplayArea.Cursor = CustomCursor;
                break;
            default:
                break;
        }

        // If the cursor scope is set to the entire application
        // Use OverrideCursor to force the cursor for all elements
        if (cursorScopeElementOnly == false)
        {
            Mouse.OverrideCursor = DisplayArea.Cursor;
        }
    }
}
```

## [Change the Color of an Element Using Focus Events](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-change-the-color-of-an-element-using-focus-events)

此示例演示如何获取和使用失去焦点时更改元素的颜色[GotFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.gotfocus)和[LostFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.lostfocus)事件。

此示例中包含的可扩展应用程序标记语言 (XAML)文件和代码隐藏文件。

以下XAML创建用户界面，它包含两个[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)对象，并将事件处理程序附加[GotFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.gotfocus)并[LostFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.lostfocus)事件到[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)对象。

XAML复制

```xaml
<StackPanel>
  <StackPanel.Resources>
    <Style TargetType="{x:Type Button}">
      <Setter Property="Height" Value="20"/>
      <Setter Property="Width" Value="250"/>
      <Setter Property="HorizontalAlignment" Value="Left"/>
    </Style>
  </StackPanel.Resources>
  <Button
      GotFocus="OnGotFocusHandler"
      LostFocus="OnLostFocusHandler">Click Or Tab To Give Keyboard Focus</Button>
  <Button
      GotFocus="OnGotFocusHandler"
      LostFocus="OnLostFocusHandler">Click Or Tab To Give Keyborad Focus</Button>
</StackPanel>
```

下面的代码隐藏创建[GotFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.gotfocus)和[LostFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.lostfocus)事件处理程序。 当[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)提升键盘焦点[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)的[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)更改为红色。 当[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)失去键盘焦点[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)的[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)更改回 white。

C#复制

```csharp
public partial class Window1 : Window
{
    public Window1()
    {
        InitializeComponent();
    }

    // Raised when Button gains focus.
    // Changes the color of the Button to Red.
    private void OnGotFocusHandler(object sender, RoutedEventArgs e)
    {
        Button tb = e.Source as Button;
        tb.Background = Brushes.Red;
    }
    // Raised when Button losses focus. 
    // Changes the color of the Button back to white.
    private void OnLostFocusHandler(object sender, RoutedEventArgs e)
    {
        Button tb = e.Source as Button;
        tb.Background = Brushes.White;
    }
}
```

## [Apply a FocusVisualStyle to a Control](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-apply-a-focusvisualstyle-to-a-control)

此示例演示如何在资源中创建焦点视觉样式并将样式应用到控件时，使用[FocusVisualStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.focusvisualstyle)属性。

下面的示例定义的样式，将创建仅在该控件是中的键盘焦点时应用的其他控件组合用户界面 (UI)。 这通过定义样式与实现[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)，然后在设置时，为资源引用该样式[FocusVisualStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.focusvisualstyle)属性。

类似于边框外部矩形放置之外的矩形区域。 除非修改，否则使用的样式的大小调整[ActualHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.actualheight)和[ActualWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.actualwidth)焦点视觉样式应用的位置的矩形控件。 此示例设置值为负值[Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)以使显示稍有外部具有焦点的控件的边框。

XAML复制

```xaml
<Page
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
>
  <Page.Resources>
    <Style x:Key="MyFocusVisual">
      <Setter Property="Control.Template">
        <Setter.Value>
          <ControlTemplate>
            <Rectangle Margin="-2" StrokeThickness="1" Stroke="Red" StrokeDashArray="1 2"/>
          </ControlTemplate>
        </Setter.Value>
      </Setter>
    </Style>
  </Page.Resources>
  <StackPanel Background="Ivory" Orientation="Horizontal">
    <Canvas Width="10"/>
    <Button Width="100" Height="30" FocusVisualStyle="{DynamicResource MyFocusVisual}">
      Focus Here</Button>
    <Canvas Width="100"/>
    <Button Width="100" Height="30" FocusVisualStyle="{DynamicResource MyFocusVisual}">
      Focus Here</Button>
  </StackPanel>
</Page>
```

一个[FocusVisualStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.focusvisualstyle)是附加到提供任何控件模板样式从显式样式或主题样式; 主样式的控件仍可创建使用[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)并将该样式设置为[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.style)属性。

焦点视觉样式应始终在主题或 UI，而不是使用另一个用于每个可获得焦点的元素。 有关详细信息，请参阅[的控件和 FocusVisualStyle 焦点设置样式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/styling-for-focus-in-controls-and-focusvisualstyle)。

## [Detect When the Enter Key is Pressed](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-detect-when-the-enter-key-pressed)

此示例演示如何检测何时[Enter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.key#System_Windows_Input_Key_Enter)键盘上按下键。

此示例中包含的可扩展应用程序标记语言 (XAML)文件和代码隐藏文件。

当用户按[Enter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.key#System_Windows_Input_Key_Enter)中的键[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)，在文本框中输入将出现在另一个区域的用户界面 (UI)。

以下XAML创建用户界面，其中包括[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)即[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)，和一个[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。

XAML复制

```xaml
<StackPanel>
  <TextBlock Width="300" Height="20">
    Type some text into the TextBox and press the Enter key.
  </TextBlock>
  <TextBox Width="300" Height="30" Name="textBox1"
           KeyDown="OnKeyDownHandler"/>
  <TextBlock Width="300" Height="100" Name="textBlock1"/>
</StackPanel>
```

下面的代码隐藏创建[KeyDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.keydown)事件处理程序。 如果按下的键是[Enter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.key#System_Windows_Input_Key_Enter)键，显示一条消息是在[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)。

C#复制

```csharp
private void OnKeyDownHandler(object sender, KeyEventArgs e)
{
    if (e.Key == Key.Return)
    {
        textBlock1.Text = "You Entered: " + textBox1.Text;
    }
}
```

## [Create a Rollover Effect Using Events](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-create-a-rollover-effect-using-events)

此示例演示如何根据鼠标指针进入和离开元素占用的区域更改元素的颜色。

此示例组成可扩展应用程序标记语言 (XAML)文件和代码隐藏文件。

 备注

此示例演示如何使用事件，但获得相同的效果的推荐的方式是使用[Trigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.trigger)样式。 有关详细信息，请参阅[样式设置和模板化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/styling-and-templating)。

以下XAML创建用户界面，其中包括[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)围绕[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)，并将其附加[MouseEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.mouse.mouseenter)和[MouseLeave](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouseleave)到事件处理程序[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)。

XAML复制

```xaml
<StackPanel>
  <Border MouseEnter="OnMouseEnterHandler"
          MouseLeave="OnMouseLeaveHandler"
          Name="border1" Margin="10"
          BorderThickness="1"
          BorderBrush="Black"
          VerticalAlignment="Center"
          Width="300" Height="100">
    <Label Margin="10" FontSize="14"
           HorizontalAlignment="Center">Move Cursor Over Me</Label>
  </Border>
</StackPanel>
```

下面的代码隐藏创建[MouseEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouseenter)和[MouseLeave](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouseleave)事件处理程序。 当鼠标指针进入[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)，背景的[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)将变为红色。 当鼠标指针离开[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)，背景的[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)将变回为空白。

C#复制

```csharp
public partial class Window1 : Window
{
    public Window1()
    {
        InitializeComponent();
    }

    // raised when mouse cursor enters the area occupied by the element
    void OnMouseEnterHandler(object sender, MouseEventArgs e)
    {
        border1.Background = Brushes.Red;
    }

    // raised when mouse cursor leaves the area occupied by the element
    void OnMouseLeaveHandler(object sender, MouseEventArgs e)
    {
        border1.Background = Brushes.White;
    }
}
```

## [Make an Object Follow the Mouse Pointer](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-make-an-object-follow-the-mouse-pointer)

此示例演示如何在屏幕上移动鼠标指针时更改对象的维度。

该示例包含可扩展应用程序标记语言 (XAML)创建的文件用户界面 (UI)和创建事件处理程序的代码隐藏文件。

以下XAML创建UI，其中包括[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)内[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)，并将附加的事件处理程序[MouseMove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mousemove)事件。

XAML复制

```xaml
<Window x:Class="WCSamples.Window1"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    Title="mouseMoveWithPointer"
    Height="400"
    Width="500"
    >
  <Canvas MouseMove="MouseMoveHandler"
          Background="LemonChiffon">
    <Ellipse Name="ellipse" Fill="LightBlue" 
             Width="100" Height="100"/>
  </Canvas>
</Window>
```

下面的代码隐藏创建[MouseMove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mousemove)事件处理程序。 当鼠标指针移动，高度和宽度[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)增加和减少。

C#复制

```csharp
// raised when the mouse pointer moves.
// Expands the dimensions of an Ellipse when the mouse moves.
private void MouseMoveHandler(object sender, MouseEventArgs e)
{
    // Get the x and y coordinates of the mouse pointer.
    System.Windows.Point position = e.GetPosition(this);
    double pX = position.X;
    double pY = position.Y;

    // Sets the Height/Width of the circle to the mouse coordinates.
    ellipse.Width = pX;
    ellipse.Height = pY;
}
```

## [Create a RoutedCommand](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-create-a-routedcommand)

此示例演示如何创建自定义[RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand)以及如何通过创建实现自定义命令[ExecutedRoutedEventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.executedroutedeventhandler)和一个[CanExecuteRoutedEventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.canexecuteroutedeventhandler)并将其到附加[CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding)。 有关命令的详细信息，请参阅[命令概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/commanding-overview)。

创建的第一步[RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand)定义命令和其实例化。

C#复制

```csharp
public static RoutedCommand CustomRoutedCommand = new RoutedCommand();
```

为了在应用程序中使用该命令，必须创建用于定义该命令的执行事件处理程序

C#复制

```csharp
private void ExecutedCustomCommand(object sender,
    ExecutedRoutedEventArgs e)
{
    MessageBox.Show("Custom Command Executed");
}
```

C#复制

```csharp
// CanExecuteRoutedEventHandler that only returns true if
// the source is a control.
private void CanExecuteCustomCommand(object sender, 
    CanExecuteRoutedEventArgs e)
{
    Control target = e.Source as Control;
    
    if(target != null)
    {
        e.CanExecute = true;
    }
    else
    {
        e.CanExecute = false;
    }
}
```

下一步，[CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding)创建其将命令与事件处理程序相关联。 [CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding)特定对象上创建。 此对象定义的范围[CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding)元素树中

XAML复制

```xaml
<Window x:Class="SDKSamples.Window1"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    xmlns:custom="clr-namespace:SDKSamples"
    Height="600" Width="800"
    >
  <Window.CommandBindings>
    <CommandBinding Command="{x:Static custom:Window1.CustomRoutedCommand}"
                    Executed="ExecutedCustomCommand"
                    CanExecute="CanExecuteCustomCommand" />
  </Window.CommandBindings>
```

C#复制

```csharp
CommandBinding customCommandBinding = new CommandBinding(
    CustomRoutedCommand, ExecutedCustomCommand, CanExecuteCustomCommand);

// attach CommandBinding to root window
this.CommandBindings.Add(customCommandBinding);
```

最后一步调用该命令。 一种方法来调用命令是将其与相关联[ICommandSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource)，如[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。

XAML复制

```xaml
<StackPanel>
  <Button Command="{x:Static custom:Window1.CustomRoutedCommand}"
          Content="CustomRoutedCommand"/>
</StackPanel>
```

C#复制

```csharp
// create the ui
StackPanel CustomCommandStackPanel = new StackPanel();
Button CustomCommandButton = new Button();
CustomCommandStackPanel.Children.Add(CustomCommandButton);

CustomCommandButton.Command = CustomRoutedCommand;
```

单击按钮时，[Execute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand.execute)方法对自定义[RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand)调用。 [RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand)将引发[PreviewExecuted](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandmanager.previewexecuted)和[Executed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandmanager.executed)路由事件。 这些事件会遍历元素树，以查找[CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding)针对此特定的命令。 如果[CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding)找到，则[ExecutedRoutedEventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.executedroutedeventhandler)与关联[CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding)调用。

## [Implement ICommandSource](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-implement-icommandsource)

此示例演示如何通过实现来创建命令源[ICommandSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource)。 命令源是一个知道如何调用命令的对象。[ICommandSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource)接口公开三个成员： [Command](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource.command)， [CommandParameter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource.commandparameter)，和[CommandTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource.commandtarget)。 [Command](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource.command) 是将调用该命令。 [CommandParameter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource.commandparameter)是用户定义数据类型从命令源传递到处理该命令的方法。 [CommandTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource.commandtarget)是在其执行该命令的对象。

在此示例中，创建类的子类[Slider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider)控件并实现[ICommandSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource)。

WPF 提供了多个类实现[ICommandSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource)，如[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)， [MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)，和[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)。 命令源定义如何调用命令。 [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) 和[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)在被单击时调用命令。 一个[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)double 单击时调用命令。 这些类仅会变得命令源时其[Command](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource.command)属性设置。

此示例中我们将调用该命令，当移动滑块时，或者更准确地说，当[Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.rangebase.value)属性更改。

下面是在类定义。

C#复制

```csharp
public class CommandSlider : Slider, ICommandSource
{
    public CommandSlider() : base()
    {

    }
```

下一步是实现[ICommandSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource)成员。 在此示例中，属性实现为[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)对象。 这样，要使用数据绑定的属性。 有关详细信息[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)类，请参阅[依赖项属性概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-properties-overview)。 有关数据绑定的详细信息，请参阅[数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview)。

仅[Command](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource.command)属性如下所示。

C#复制

```csharp
// Make Command a dependency property so it can use databinding.
public static readonly DependencyProperty CommandProperty =
    DependencyProperty.Register(
        "Command",
        typeof(ICommand),
        typeof(CommandSlider),
        new PropertyMetadata((ICommand)null,
        new PropertyChangedCallback(CommandChanged)));

public ICommand Command
{
    get 
    {
        return (ICommand)GetValue(CommandProperty);
    }
    set 
    {
        SetValue(CommandProperty, value);
    }
}
```

下面是[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)更改回调。

C#复制

```csharp
// Command dependency property change callback.
private static void CommandChanged(DependencyObject d,
    DependencyPropertyChangedEventArgs e)
{
    CommandSlider cs = (CommandSlider)d;
    cs.HookUpCommand((ICommand)e.OldValue,(ICommand)e.NewValue);
}
```

下一步是添加和删除命令与命令源相关联。 [Command](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource.command)属性不能只是被覆盖时添加新的命令，因为与前一个命令中，关联的事件处理程序必须首先删除如果有的话。

C#复制

```csharp
// Add a new command to the Command Property.
private void HookUpCommand(ICommand oldCommand, ICommand newCommand)
{
    // If oldCommand is not null, then we need to remove the handlers.
    if (oldCommand != null)
    {
        RemoveCommand(oldCommand, newCommand);
    }
    AddCommand(oldCommand, newCommand);
}

// Remove an old command from the Command Property.
private void RemoveCommand(ICommand oldCommand, ICommand newCommand)
{
    EventHandler handler = CanExecuteChanged;
    oldCommand.CanExecuteChanged -= handler;
}

// Add the command.
private void AddCommand(ICommand oldCommand, ICommand newCommand)
{
    EventHandler handler = new EventHandler(CanExecuteChanged);
    canExecuteChangedHandler = handler;
    if (newCommand != null)
    {
        newCommand.CanExecuteChanged += canExecuteChangedHandler;
    }
}
```

最后一步是创建逻辑[CanExecuteChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommand.canexecutechanged)处理程序和[Execute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommand.execute)方法。

[CanExecuteChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommand.canexecutechanged)事件通知命令源的当前命令目标上执行的命令的能力可能已更改。 当命令源收到此事件时，它通常会调用[CanExecute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommand.canexecute)命令的方法。 如果该命令不能在当前命令目标上执行，命令源通常会禁用自身。 如果该命令可以在当前命令目标上执行，命令源通常会启用自身。

C#复制

```csharp
private void CanExecuteChanged(object sender, EventArgs e)
{

    if (this.Command != null)
    {
        RoutedCommand command = this.Command as RoutedCommand;

        // If a RoutedCommand.
        if (command != null)
        {
            if (command.CanExecute(CommandParameter, CommandTarget))
            {
                this.IsEnabled = true;
            }
            else
            {
                this.IsEnabled = false;
            }
        }
        // If a not RoutedCommand.
        else
        {
            if (Command.CanExecute(CommandParameter))
            {
                this.IsEnabled = true;
            }
            else
            {
                this.IsEnabled = false;
            }
        }
    }
}
```

最后一步是[Execute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommand.execute)方法。 如果该命令是[RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand)，则[RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand)[Execute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand.execute)方法是调用; 否则为[ICommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommand)[Execute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommand.execute)调用方法。

C#复制

```csharp
// If Command is defined, moving the slider will invoke the command;
// Otherwise, the slider will behave normally.
protected override void OnValueChanged(double oldValue, double newValue)
{
    base.OnValueChanged(oldValue, newValue);

    if (this.Command != null)
    {
        RoutedCommand command = Command as RoutedCommand;

        if (command != null)
        {
            command.Execute(CommandParameter, CommandTarget);
        }
        else
        {
            ((ICommand)Command).Execute(CommandParameter);
        }
    }
}
```

## [Hook Up a Command to a Control with No Command Support](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-hook-up-a-command-to-a-control-with-no-command-support)

以下示例演示如何将 [RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand) 挂钩到不含对该命令的内置支持的 [Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)。 有关将命令挂钩到多个源的完整示例，请参阅[创建自定义 RoutedCommand 示例](https://github.com/Microsoft/WPF-Samples/tree/master/Input%20and%20Commands/CustomRoutedCommand)示例。

Windows Presentation Foundation (WPF) 提供了应用程序程序员经常遇到的常见命令库。 构成命令库的类为：[ApplicationCommands](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands)、[ComponentCommands](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.componentcommands)、[NavigationCommands](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.navigationcommands)、[MediaCommands](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.mediacommands) 和[EditingCommands](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.editingcommands)。

构成这些类的静态 [RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand) 对象不提供命令逻辑。 命令的逻辑通过 [CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding) 与命令相关联。WPF 中的许多控件都为命令库中的某些命令提供内置支持。 例如，[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 支持许多应用程序编辑命令，例如 [Paste](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands.paste)、[Copy](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands.copy)、[Cut](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands.cut)、[Redo](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands.redo) 和 [Undo](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands.undo)。 应用程序开发人员不必执行任何特殊操作即可使命令适用于这些控件。 如果命令执行时，[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 是命令目标，它将使用内置于控件中的 [CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding) 处理该命令。

下面演示了如何将 [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) 用作 [Open](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands.open) 命令的命令源。 创建一个将指定的 [CanExecuteRoutedEventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.canexecuteroutedeventhandler) 和[CanExecuteRoutedEventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.canexecuteroutedeventhandler) 与 [RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand) 相关联的 [CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding)。

首先，创建命令源。 将 [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) 用作命令源。

XAML复制

```xaml
<Button Command="ApplicationCommands.Open" Name="MyButton"
        Height="50" Width="200">
  Open (KeyBindings: Ctrl+R, Ctrl+0)
</Button>
```

C#复制

```csharp
// Button used to invoke the command
Button CommandButton = new Button();
CommandButton.Command = ApplicationCommands.Open;
CommandButton.Content = "Open (KeyBindings: Ctrl-R, Ctrl-0)";
MainStackPanel.Children.Add(CommandButton);
```

接下来，创建 [ExecutedRoutedEventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.executedroutedeventhandler) 和 [CanExecuteRoutedEventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.canexecuteroutedeventhandler)。 [ExecutedRoutedEventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.executedroutedeventhandler)只需打开 [MessageBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.messagebox) 即可表示已执行该命令。 [CanExecuteRoutedEventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.canexecuteroutedeventhandler) 将 [CanExecute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.canexecuteroutedeventargs.canexecute) 属性设置为 `true`。 通常，can execute 处理程序将执行更可靠的检查，确定是否可以在当前命令目标上执行该命令。

C#复制

```csharp
void OpenCmdExecuted(object target, ExecutedRoutedEventArgs e)
{
    String command, targetobj;
    command = ((RoutedCommand)e.Command).Name;
    targetobj = ((FrameworkElement)target).Name;
    MessageBox.Show("The " + command +  " command has been invoked on target object " + targetobj);
}
void OpenCmdCanExecute(object sender, CanExecuteRoutedEventArgs e)
{
    e.CanExecute = true;
}
```

最后，在将路由事件处理程序与 [Open](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands.open) 命令相关联的应用程序的根 [Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window) 上创建 [CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding)。

XAML复制

```xaml
<Window.CommandBindings>
  <CommandBinding Command="ApplicationCommands.Open"
                  Executed="OpenCmdExecuted"
                  CanExecute="OpenCmdCanExecute"/>
</Window.CommandBindings>
```

C#复制

```csharp
// Creating CommandBinding and attaching an Executed and CanExecute handler
CommandBinding OpenCmdBinding = new CommandBinding(
    ApplicationCommands.Open,
    OpenCmdExecuted,
    OpenCmdCanExecute);

this.CommandBindings.Add(OpenCmdBinding);
```

## [Hook Up a Command to a Control with Command Support](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-hook-up-a-command-to-a-control-with-command-support)

以下示例显示如何将 [RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand) 挂钩到含对该命令的内置支持的 [Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)。 有关将命令挂钩到多个源的完整示例，请参阅[创建自定义 RoutedCommand 示例](https://github.com/Microsoft/WPF-Samples/tree/master/Input%20and%20Commands/CustomRoutedCommand)示例。

Windows Presentation Foundation (WPF) 提供了应用程序程序员经常遇到的常见命令库。 构成命令库的类为：[ApplicationCommands](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands)、[ComponentCommands](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.componentcommands)、[NavigationCommands](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.navigationcommands)、[MediaCommands](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.mediacommands) 和[EditingCommands](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.editingcommands)。

构成这些类的静态 [RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand) 对象不提供命令逻辑。 命令的逻辑通过 [CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding) 与命令相关联。某些控件的部分命令具有内置的 CommandBindings。 这种机制可使命令的语义保持不变，而实际实现可以更改。 例如，[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 对 [Paste](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands.paste) 命令的处理方式与专门支持图像的控件对其的处理方式不同，后者的基本思路是通过粘贴让内容保持不变。 命令无法提供命令逻辑，但是控件或应用程序必须提供命令逻辑。

WPF 中的许多控件都为命令库中的某些命令提供内置支持。 例如，[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 支持许多应用程序编辑命令，例如 [Paste](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands.paste)、[Copy](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands.copy)、[Cut](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands.cut)、[Redo](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands.redo) 和 [Undo](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands.undo)。 应用程序开发人员不必执行任何特殊操作即可使命令适用于这些控件。 如果命令执行时，[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 是命令目标，它将使用内置于控件中的 [CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding) 处理该命令。

以下说明如何将 [MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem) 用作 [Paste](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands.paste) 命令的命令源，其中 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 是命令的目标。 定义 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 如何执行粘贴的所有逻辑都已内置到 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 控件中。

已创建 [MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)，并将其 [Command](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem.command) 属性设置为 [Paste](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands.paste) 命令。 [CommandTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem.commandtarget) 未显式设置为 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 对象。 未设置 [CommandTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem.commandtarget) 时，该命令的目标是具有键盘焦点的元素。 如果具有键盘焦点的元素不支持 [Paste](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands.paste) 命令，或当前无法执行粘贴命令（例如，剪贴板为空），则 [MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem) 为灰显。

XAML复制

```xaml
<Window x:Class="SDKSamples.Window1"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    Title="MenuItemCommandTask"
    >
    <DockPanel>
      <Menu DockPanel.Dock="Top">
        <MenuItem Command="ApplicationCommands.Paste" Width="75" />
      </Menu>
      <TextBox BorderBrush="Black" BorderThickness="2" Margin="25"
               TextWrapping="Wrap">
        The MenuItem will not be enabled until
        this TextBox gets keyboard focus  
      </TextBox>
    </DockPanel>
</Window>
```

C#复制

```csharp
       // Window1 constructor
       public Window1()
       {
           InitializeComponent();

           // Instantiating UIElements.
           DockPanel mainPanel = new DockPanel();
           Menu mainMenu = new Menu();
           MenuItem pasteMenuItem = new MenuItem();
           TextBox mainTextBox = new TextBox();

           // Associating the MenuItem with the Paste command.
           pasteMenuItem.Command = ApplicationCommands.Paste;

           // Setting properties on the TextBox.
           mainTextBox.Text =
               "The MenuItem will not be enabled until this TextBox receives keyboard focus.";
           mainTextBox.Margin = new Thickness(25);
           mainTextBox.BorderBrush = Brushes.Black;
           mainTextBox.BorderThickness = new Thickness(2);
           mainTextBox.TextWrapping = TextWrapping.Wrap;

           // Attaching UIElements to the Window.
           this.AddChild(mainPanel);
           mainMenu.Items.Add(pasteMenuItem);
           mainPanel.Children.Add(mainMenu);
           mainPanel.Children.Add(mainTextBox);

           // Defining DockPanel layout.
           DockPanel.SetDock(mainMenu, Dock.Top);
           DockPanel.SetDock(mainTextBox, Dock.Bottom);
       }
```