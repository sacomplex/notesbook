# [Input Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/input-overview)

Windows Presentation Foundation (WPF)子系统提供了一个强大API用于获取输入不同的设备，包括鼠标、 键盘、 触控和触笔。 本主题介绍了 WPF 提供的服务，并说明了输入系统的体系结构。



## 输入 API

主要的输入API找到基元素类上公开： [UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)， [ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement)， [FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)，和[FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement)。 有关基元素的详细信息，请参阅[基元素概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/base-elements-overview)。 这些类提供有关输入事件（例如按键、鼠标按钮、鼠标滚轮、鼠标移动、焦点管理和鼠标捕获等）的功能。 通过将输入 API 放置在基元素上，而不是将所有输入事件视作一项服务，该输入体系结构使输入事件可以由 UI 中的特定对象指明其出处，并支持事件路由方案，从而使得多个元素有机会处理输入事件。 许多输入事件都具有与之相关联的一对事件。 例如，键按下事件与[KeyDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard.keydown)和[PreviewKeyDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard.previewkeydown)事件。 这些事件的区别在于它们如何路由至目标元素。 预览事件将元素树从根元素到目标元素向下进行隧道操作。 冒泡事件从目标元素到根元素向上进行冒泡操作。 本概述后面部分和[路由事件概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/routed-events-overview)中更详细地讨论了 WPF 中的事件路由。

### 键盘和鼠标类

除了输入API基元素类上[Keyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard)类和[Mouse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.mouse)类提供其他API用于处理键盘和鼠标输入。

输入的示例API上[Keyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard)类[Modifiers](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard.modifiers)属性，它返回[ModifierKeys](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.modifierkeys)当前按下，和[IsKeyDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard.iskeydown)方法，这可确定是否按下某个指定的键。

下面的示例使用[GetKeyStates](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard.getkeystates)方法，以确定如果[Key](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.key)处于关闭状态。

C#复制

```csharp
// Uses the Keyboard.GetKeyStates to determine if a key is down.
// A bitwise AND operation is used in the comparison. 
// e is an instance of KeyEventArgs.
if ((Keyboard.GetKeyStates(Key.Return) & KeyStates.Down) > 0)
{
    btnNone.Background = Brushes.Red;
}
```

输入的示例API上[Mouse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.mouse)类[MiddleButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.mouse.middlebutton)，用于获取鼠标中键的状态和[DirectlyOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.mouse.directlyover)，后者将获取该元素在鼠标指针当前位于。

下面的示例确定是否[LeftButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.mouse.leftbutton)鼠标位于[Pressed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.mousebuttonstate#System_Windows_Input_MouseButtonState_Pressed)状态。

C#复制

```csharp
if (Mouse.LeftButton == MouseButtonState.Pressed)
{
    UpdateSampleResults("Left Button Pressed");
}
```

[Mouse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.mouse)和[Keyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard)中更详细地介绍本概述介绍了类。

### 触笔输入

WPF 支持集成的[Stylus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylus)。 [Stylus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylus)是变得流行的笔输入Tablet PC。 WPF 应用程序可以通过使用鼠标 API 将触笔视为鼠标，但 WPF 也公开了触笔设备抽象，其使用的模型与键盘和鼠标类似。 所有与触笔相关的 API 都包含单词“触笔”。

由于触笔可充当鼠标，因此仅支持鼠标输入的应用程序仍可以自动获得一定程度的触笔支持。 以这种方式使用触笔时，应用程序有能力处理相应的触笔事件，然后处理相应的鼠标事件。 此外，通过触笔设备抽象也可以使用墨迹输入等较高级别的服务。 有关墨迹输入的详细信息，请参阅[墨迹入门](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/getting-started-with-ink)。



## 事件路由

一个[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)可以包含其他元素，作为在其内容模型中，从而形成一个树的元素的子元素。 在 WPF中，父元素可以通过处理事件来参与定向到其子元素或其他后代的输入。 这特别适合于从较小的控件中生成控件，该过程称为“控件组合”或“合成”。 有关元素树以及元素树如何与事件路由关联的详细信息，请参阅 [WPF 中的树](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/trees-in-wpf)。

事件路由是将事件转发到多个元素的过程，以便使路由中的特定对象或元素可以选择对已由其他元素指明来源的事件提供重要响应（通过处理）。 路由事件使用三种路由机制的其中一种：直接、浮升和隧道。 在直接路由中，源元素是收到通知的唯一元素，事件不会路由至任何其他元素。 但是相对于标准 CLR 事件，直接路由事件仍然提供一些仅针对路由事件而存在的其他功能。 浮升操作在元素树中向上进行，首先通知指明了事件来源的第一个元素，然后是父元素等等。 隧道操作从元素树的根开始，然后向下进行，以原始的源元素结束。 有关路由事件的详细信息，请参阅[路由事件概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/routed-events-overview)。

WPF 输入事件通常成对出现，由一个隧道事件和一个冒泡事件组成。 隧道事件与冒泡事件的不同之处在于它有“预览”前缀。 例如，[PreviewMouseMove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.mouse.previewmousemove)是鼠标移动事件的隧道版本和[MouseMove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.mouse.mousemove)是此事件的冒泡版本。 此事件配对是在元素级别实现的一种约定，不是 WPF 事件系统的固有功能。 有关详细信息，请参阅[路由事件概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/routed-events-overview)中的 WPF 输入事件部分。



## 处理输入事件

若要在元素上接收输入，必须将事件处理程序与该特定事件关联。 在 XAML 中，这很简单：将事件的名称作为要侦听此事件的元素的特性进行引用。 然后，根据委托，将特性的值设置为所定义的事件处理程序的名称。 事件处理程序必须采用如 C# 代码，并可以包含在代码隐藏文件。

当操作系统报告发生键操作时，如果键盘焦点正处在元素上，则将发生键盘事件。 鼠标和触笔事件分别分为两类：报告指针位置相对于元素的变化的事件，和报告设备按钮状态的变化的事件。

### 键盘输入事件示例

以下示例侦听按下向左键的操作。 一个[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)将创建一个具有[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。 一个事件处理程序以侦听按向左的箭头键附加到[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)实例。

该示例的第一个部分创建[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)并[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)，并将附加的事件处理程序[KeyDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.keydown)。

XAML复制

```xaml
<StackPanel>
  <Button Background="AliceBlue"
          KeyDown="OnButtonKeyDown"
          Content="Button1"/>
</StackPanel>
```

C#复制

```csharp
// Create the UI elements.
StackPanel keyboardStackPanel = new StackPanel();
Button keyboardButton1 = new Button();

// Set properties on Buttons.
keyboardButton1.Background = Brushes.AliceBlue;
keyboardButton1.Content = "Button 1";

// Attach Buttons to StackPanel.
keyboardStackPanel.Children.Add(keyboardButton1);

// Attach event handler.
keyboardButton1.KeyDown += new KeyEventHandler(OnButtonKeyDown);
```

第二部分用代码编写，定义了事件处理程序。 向左的箭头键按下时，[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)具有键盘焦点，处理程序将运行并[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)的颜色[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)更改。 如果按下了键，但它不是向的左键[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)颜色[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)更改回其开始颜色。

C#复制

```csharp
private void OnButtonKeyDown(object sender, KeyEventArgs e)
{
    Button source = e.Source as Button;
    if (source != null)
    {
        if (e.Key == Key.Left)
        {
            source.Background = Brushes.LemonChiffon;
        }
        else
        {
            source.Background = Brushes.AliceBlue;
        }
    }
}
```

### 鼠标输入事件示例

在以下示例中，[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)色[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)当鼠标指针进入更改[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。 [Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)颜色将还原当鼠标离开[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。

该示例的第一个部分创建[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)和[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)控制，并将附加的事件处理程序[MouseEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouseenter)并[MouseLeave](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouseleave)事件到[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。

XAML复制

```xaml
<StackPanel>
  <Button Background="AliceBlue"
          MouseEnter="OnMouseExampleMouseEnter"
          MouseLeave="OnMosueExampleMouseLeave">Button
          
  </Button>
</StackPanel>
```

C#复制

```csharp
// Create the UI elements.
StackPanel mouseMoveStackPanel = new StackPanel();
Button mouseMoveButton = new Button();

// Set properties on Button.
mouseMoveButton.Background = Brushes.AliceBlue;
mouseMoveButton.Content = "Button";

// Attach Buttons to StackPanel.
mouseMoveStackPanel.Children.Add(mouseMoveButton);

// Attach event handler.
mouseMoveButton.MouseEnter += new MouseEventHandler(OnMouseExampleMouseEnter);
mouseMoveButton.MouseLeave += new MouseEventHandler(OnMosueExampleMouseLeave);
```

该示例的第二部分用代码编写，定义了事件处理程序。 当鼠标进入[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)，则[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)的颜色[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)更改为[SlateGray](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brushes.slategray)。 当鼠标离开[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)，则[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)的颜色[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)更改回[AliceBlue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brushes.aliceblue)。

C#复制

```csharp
private void OnMouseExampleMouseEnter(object sender, MouseEventArgs e)
{
    // Cast the source of the event to a Button.
    Button source = e.Source as Button;

    // If source is a Button.
    if (source != null)
    {
        source.Background = Brushes.SlateGray;
    }
}
```

C#复制

```csharp
private void OnMosueExampleMouseLeave(object sender, MouseEventArgs e)
{
    // Cast the source of the event to a Button.
    Button source = e.Source as Button;

    // If source is a Button.
    if (source != null)
    {
        source.Background = Brushes.AliceBlue;
    }
}
```



## 文本输入

[TextInput](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement.textinput)事件，可以以独立于设备的方式侦听文本输入。 键盘是文本输入的主要方式，但通过语音、手写和其他输入设备也可以生成文本输入。

对于键盘输入WPF首先发送相应[KeyDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement.keydown) / [KeyUp](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement.keyup)事件。 如果不处理这些事件，并且按键是文本而不是 （例如方向箭头的控制键） 或功能键，则[TextInput](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement.textinput)引发事件。 不会始终之间简单的一对一映射[KeyDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement.keydown) / [KeyUp](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement.keyup)和[TextInput](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement.textinput)事件因为多次击键可以生成的文本输入单个字符，并且一次击键可以生成多字符字符串。 对于中文、日文和韩文等语言尤其如此，这些语言使用 输入法编辑器 (IME) 生成由其对应的字母组成的成千上万个可能的字符。

当WPF发送[KeyUp](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement.keyup) / [KeyDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement.keydown)事件，[Key](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyeventargs.key)设置为[Key.System](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.key#System_Windows_Input_Key_System)如果击键可以成为一部分[TextInput](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement.textinput)事件 （如果为例，按 ALT + S）。 这样中的代码[KeyDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement.keydown)事件处理程序检查是否[Key.System](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.key#System_Windows_Input_Key_System)并且如果找到，保留对随后引发的处理程序处理[TextInput](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement.textinput)事件。 在这些情况下，各属性的[TextCompositionEventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.textcompositioneventargs)参数可用于确定原始击键。 同样，如果IME处于活动状态，[Key](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.key)的值为[Key.ImeProcessed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.key#System_Windows_Input_Key_ImeProcessed)，和[ImeProcessedKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyeventargs.imeprocessedkey)不提供原始击键。

下面的示例定义的处理程序[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件和处理程序[KeyDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.keydown)事件。

第一段代码或标记创建用户界面。

XAML复制

```xaml
<StackPanel KeyDown="OnTextInputKeyDown">
  <Button Click="OnTextInputButtonClick"
          Content="Open" />
  <TextBox> . . . </TextBox>
</StackPanel>
```

C#复制

```csharp
// Create the UI elements.
StackPanel textInputStackPanel = new StackPanel();
Button textInputeButton = new Button();
TextBox textInputTextBox = new TextBox();
textInputeButton.Content = "Open";

// Attach elements to StackPanel.
textInputStackPanel.Children.Add(textInputeButton);
textInputStackPanel.Children.Add(textInputTextBox);

// Attach event handlers.
textInputStackPanel.KeyDown += new KeyEventHandler(OnTextInputKeyDown);
textInputeButton.Click += new RoutedEventHandler(OnTextInputButtonClick);
```

第二段代码包含事件处理程序。

C#复制

```csharp
private void OnTextInputKeyDown(object sender, KeyEventArgs e)
{
    if (e.Key == Key.O && Keyboard.Modifiers == ModifierKeys.Control)
    {
        handle();
        e.Handled = true;
    }
}

private void OnTextInputButtonClick(object sender, RoutedEventArgs e)
{
    handle();
    e.Handled = true;
} 

public void handle()
{
    MessageBox.Show("Pretend this opens a file");
}
```

由于输入的事件的事件路由，向上冒泡[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)接收的输入不管哪个元素具有键盘焦点。 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控件首先得到通知并`OnTextInputKeyDown`仅当调用处理程序[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)未处理输入。 如果[PreviewKeyDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.previewkeydown)而不是使用事件[KeyDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.keydown)事件，`OnTextInputKeyDown`首先调用处理程序。

在此示例中，处理逻辑写入了两次，分别针对 CTRL+O和按钮的单击事件。 使用命令，而不是直接处理输入事件，可简化此过程。 本概述和[命令概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/commanding-overview)中将讨论这些命令。



## 触摸和操作

Windows 7 操作系统中的新硬件和 API 使应用程序能够同时接收来自多个触控的输入。 WPF 通过在触摸发生时引发事件，从而使应用程序能够以类似于响应其他输入（例如鼠标或键盘）的方式来检测和响应触摸设备。

发生触摸时，WPF 将公开两种类型的事件：触摸事件和操作事件。 触摸事件提供有关触摸屏上每个手指及其移动的原始数据。 操作事件将输入解释为特定操作。 本部分将讨论这两种类型的事件。

### 系统必备

需要以下组件才能开发响应触摸的应用程序。

- Visual Studio 2010。
- Windows 7。
- 支持 Windows 触控的设备，如触摸屏。

### 术语

讨论触摸时使用了以下术语。

- **触摸**是 Windows 7 可识别的一种用户输入。 通常，将手指放在触敏式屏幕上会触发触摸。 请注意，如果设备仅将手指的位置和移动转换为鼠标输入，则笔记本电脑上常用的触摸板等设备不支持触摸。
- **多点触摸**是同时发生在多个点上的触摸。 Windows 7 和 WPF 支持多点触摸。 WPF 文档中每当论及触摸时，相关概念均适用于多点触摸。
- 当触摸被解释为应用于对象的实际操作时，就发生了**操作**。 在 WPF 中，操作事件将输入解释为转换、扩展或旋转操作。
- `touch device` 表示产生触摸输入的设备，例如触摸屏上的一根手指。

### 响应触摸的控件

如果以下控件的内容延伸到视图之外，则可以通过在控件上拖动手指来滚动该控件。

- [ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)
- [ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)
- [DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)
- [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)
- [ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)
- [MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)
- [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)
- [ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)
- [TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)

[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)定义[ScrollViewer.PanningMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer.panningmode)附加属性，可用于指定是否触摸平移启用水平、 垂直、 两者，还是两者皆否。 [ScrollViewer.PanningDeceleration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer.panningdeceleration)属性指定如何快速滚动速度变慢时用户将手指从触摸屏。[ScrollViewer.PanningRatio](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer.panningratio)附加的属性指定滚动偏移与转换操作偏移的比率。

### 触摸事件

基类[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)， [UIElement3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement3d)，和[ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement)，定义您可以订阅，以便你的应用程序响应触摸的事件。 当应用程序将触摸解释为操作对象以外的其他操作时，触摸事件非常有用。 例如，使用户能够以一个或多个手指绘制的应用程序将订阅触摸事件。

所有三个类都定义了以下事件，其行为类似，而无论定义类是什么。

- [TouchDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.touchdown)
- [TouchMove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.touchmove)
- [TouchUp](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.touchup)
- [TouchEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.touchenter)
- [TouchLeave](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.touchleave)
- [PreviewTouchDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.previewtouchdown)
- [PreviewTouchMove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.previewtouchmove)
- [PreviewTouchUp](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.previewtouchup)
- [GotTouchCapture](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.gottouchcapture)
- [LostTouchCapture](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.losttouchcapture)

像键盘和鼠标事件一样，触摸事件也是路由事件。 以 `Preview` 开头的事件是隧道事件，以 `Touch` 开头的事件是冒泡事件。 有关路由事件的详细信息，请参阅[路由事件概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/routed-events-overview)。 在您处理这些事件，可以通过调用获取的输入，相对于任何元素的位置[GetTouchPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.toucheventargs.gettouchpoint)或[GetIntermediateTouchPoints](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.toucheventargs.getintermediatetouchpoints)方法。

为了理解触控事件之间的交互，请考虑以下这种情况：用户将一个手指放在元素上，在该元素中移动手指，然后将手指从该元素上移开。 下图显示了冒泡事件的执行（为简单起见，省略了隧道事件）。

![触摸事件的顺序。](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/ndp-touchevents.png)触摸事件

下列内容描述了上图中的事件顺序。

1. [TouchEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.touchenter)事件发生一次当用户将手指放在元素。
2. [TouchDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.touchdown)事件发生一次。
3. [TouchMove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.touchmove)事件发生多次，用户在将移动手指在元素中的。
4. [TouchUp](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.touchup)事件发生一次当用户将手指从该元素。
5. [TouchLeave](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.touchleave)事件发生一次。

当使用两根以上的手指时，每根手指都会发生事件。

### 操作事件

其中一个应用程序使用户能够的对象执行操作的情况下为[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)类定义了操作事件。 与只是报告触摸位置的触摸事件不同，操作事件会报告可采用何种方式解释输入。 有三种类型的操作：转换、扩展和旋转。 下列内容介绍了如何调用这三种类型的操作。

- 将一根手指放在对象上，并在触摸屏上拖动手指以调用转换操作。 此操作通常会移动对象。
- 将两根手指放在物体上，并将手指相互靠拢或分开以调用扩展操作。 此操作通常会调整对象的大小。
- 将两根手指放在对象上，并将一个手指围绕另一个手指旋转以调用旋转操作。 此操作通常会旋转对象。

多种类型的操作可以同时发生。

使对象响应操作时，可以让对象看起来具有惯性。 这样可以使对象模拟真实的世界。 例如，在桌子上推一本书时，如果你足够用力，书将在你松手后继续移动。 利用 WPF，可以通过在用户的手指松开对象后引发操作事件来模拟这种行为。

有关如何创建使用户能够移动、 调整大小和旋转对象的应用程序的信息，请参阅[演练：创建第一个触控应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/walkthrough-creating-your-first-touch-application)。

[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)定义了以下操作事件。

- [ManipulationStarting](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationstarting)
- [ManipulationStarted](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationstarted)
- [ManipulationDelta](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationdelta)
- [ManipulationInertiaStarting](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationinertiastarting)
- [ManipulationCompleted](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationcompleted)
- [ManipulationBoundaryFeedback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationboundaryfeedback)

默认情况下，[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)不会接收这些操作事件。 若要在接收操作事件[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)，将[UIElement.IsManipulationEnabled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ismanipulationenabled)到`true`。

#### 操作事件的执行路径

考虑用户“抛出”一个对象的情况。 用户将手指放在对象上，将手指在触摸屏上移动一段短距离，然后在移动的同时抬起手指。 此操作的结果是，该对象将在用户的手指下方移动，并在用户抬起手指后继续移动。

下图显示了操作事件的执行路径和每个事件的重要信息。

![操作事件的顺序。](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/ndp-manipulationevents.png)操作事件

下列内容描述了上图中的事件顺序。

1. [ManipulationStarting](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationstarting)时用户将手指放在对象上发生的事件。 此外，此事件，可设置[ManipulationContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.manipulationstartingeventargs.manipulationcontainer)属性。 在随后的事件，操作位置将相对于[ManipulationContainer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.manipulationstartingeventargs.manipulationcontainer)。 在事件以外的其他[ManipulationStarting](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationstarting)，此属性是只读的因此[ManipulationStarting](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationstarting)事件是唯一一次，您可以设置此属性。
2. [ManipulationStarted](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationstarted)接下来发生的事件。 此事件报告操作的原始位置。
3. [ManipulationDelta](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationdelta)事件发生多次作为用户的手指移动触摸屏上。 [DeltaManipulation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.manipulationdeltaeventargs.deltamanipulation)属性的[ManipulationDeltaEventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.manipulationdeltaeventargs)类报告操作被解释为移动、 扩展还是转换。 这是你执行操作对象的大部分工作的地方。
4. [ManipulationInertiaStarting](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationinertiastarting)事件发生时在用户的手指失去与对象的联系。 此事件使你可以指定操作在惯性期间的减速。 这样，选择时对象就可以模拟不同的物理空间或特性。 例如，假设应用程序有两个表示真实世界中的物品的对象，并且一个物品比另一个物品重。 你可以使较重的对象比较轻的对象减速更快。
5. [ManipulationDelta](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationdelta)在出现惯性时，事件发生多次。 请注意，当用户的手指在触摸屏上移动并且 WPF 模拟惯性时，将发生此事件。 换而言之，[ManipulationDelta](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationdelta)发生之前和之后[ManipulationInertiaStarting](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationinertiastarting)事件。[ManipulationDeltaEventArgs.IsInertial](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.manipulationdeltaeventargs.isinertial)属性的报表是否[ManipulationDelta](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationdelta)延时，期间发生的事件，因此您可以检查该属性并执行不同的操作，具体取决于它的值。
6. [ManipulationCompleted](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationcompleted)事件发生的操作和所有惯性结束时。 也就是说，毕竟[ManipulationDelta](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationdelta)发生事件，[ManipulationCompleted](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationcompleted)发生事件发出信号的操作已完成。

[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)还定义了[ManipulationBoundaryFeedback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationboundaryfeedback)事件。 此事件发生时[ReportBoundaryFeedback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.manipulationdeltaeventargs.reportboundaryfeedback)方法调用[ManipulationDelta](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationdelta)事件。 [ManipulationBoundaryFeedback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationboundaryfeedback)事件，应用程序或组件对象到达边界时提供可视反馈。 例如，[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)类将处理[ManipulationBoundaryFeedback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationboundaryfeedback)要使窗口轻微移动时遇到其边缘事件。

您可以通过调用来取消该操作[Cancel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.manipulationstartingeventargs.cancel)除外的任何操作事件中的事件自变量的方法[ManipulationBoundaryFeedback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationboundaryfeedback)事件。 当您调用[Cancel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.manipulationstartingeventargs.cancel)、 不再引发操作事件和触摸会发生鼠标事件。 下表描述了取消操作的时间与所发生的鼠标事件之间的关系。

| 在其中调用取消的事件                                         | 针对已经发生的输入发生的鼠标事件   |
| ------------------------------------------------------------ | ---------------------------------- |
| [ManipulationStarting](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationstarting) 和 [ManipulationStarted](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationstarted) | 鼠标按下事件。                     |
| [ManipulationDelta](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationdelta) | 鼠标按下和鼠标移动事件。           |
| [ManipulationInertiaStarting](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationinertiastarting) 和 [ManipulationCompleted](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationcompleted) | 鼠标按下、鼠标移动和鼠标弹起事件。 |

请注意，如果您调用[Cancel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.manipulationstartingeventargs.cancel)操作在惯性时，该方法返回`false`输入不会引发鼠标事件。

### 触摸事件和操作事件之间的关系

一个[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)始终可以接收触控事件。 当[IsManipulationEnabled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ismanipulationenabled)属性设置为`true`、[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)可以接收触摸和操作事件。 如果[TouchDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.touchdown)不处理事件 (即[Handled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedeventargs.handled)属性是`false`)，操作逻辑的元素触摸屏输入捕获和生成操作事件。 如果[Handled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedeventargs.handled)属性设置为`true`中[TouchDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.touchdown)事件，操作逻辑不会生成操作事件。 下图显示了触摸事件和操作事件之间的关系。

![触摸和操作事件之间的关系](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/ndp-touchmanipulateevents.png)触摸和操作事件

下列内容描述了上图中所示的触摸事件和操作事件之间的关系。

- 当第一个触控设备生成[TouchDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.touchdown)上的事件[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)，操作逻辑调用[CaptureTouch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.capturetouch)方法，后者生成[GotTouchCapture](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.gottouchcapture)事件。
- 当[GotTouchCapture](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.gottouchcapture)发生，操作逻辑调用[Manipulation.AddManipulator](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.manipulation.addmanipulator)方法，后者生成[ManipulationStarting](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationstarting)事件。
- 当[TouchMove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.touchmove)发生事件，操作逻辑将生成[ManipulationDelta](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationdelta)之前发生的事件[ManipulationInertiaStarting](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationinertiastarting)事件。
- 当上一次触摸设备时元素将引发[TouchUp](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.touchup)事件，操作逻辑会生成[ManipulationInertiaStarting](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.manipulationinertiastarting)事件。



## 焦点

在 WPF 中，有两个与焦点有关的主要概念：键盘焦点和逻辑焦点。

### 键盘焦点

键盘焦点指当前正在接收键盘输入的元素。 在整个桌面上，只能有一个具有键盘焦点的元素。 在中WPF，具有键盘焦点的元素将具有[IsKeyboardFocused](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.iinputelement.iskeyboardfocused)设置为`true`。 静态[Keyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard)方法[FocusedElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard.focusedelement)返回当前具有键盘焦点的元素。

通过 tab 键移到元素或如单击鼠标上的某些元素，可以获取键盘焦点[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。 键盘焦点还可以获取以编程方式通过使用[Focus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard.focus)方法[Keyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard)类。 [Focus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard.focus) 尝试将指定的元素键盘焦点给予。 返回的元素[Focus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard.focus)是当前具有键盘焦点的元素。

为了使元素能够获取键盘焦点[Focusable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.focusable)属性和[IsVisible](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.isvisible)属性必须设置为**true**。 一些类，如[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)，具有[Focusable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.focusable)设置为`false`默认情况下; 因此，您可能需要将此属性设置为`true`如果你希望该元素能够获取焦点。

下面的示例使用[Focus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard.focus)上设置键盘焦点[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。 应用程序中设置初始焦点的建议的位置是在[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)事件处理程序。

C#复制

```csharp
private void OnLoaded(object sender, RoutedEventArgs e)
{
    // Sets keyboard focus on the first Button in the sample.
    Keyboard.Focus(firstButton);
}
```

有关键盘焦点的详细信息，请参阅[焦点概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/focus-overview)。

### 逻辑焦点

逻辑焦点指[FocusManager.FocusedElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusmanager.focusedelement)焦点范围中。 一个应用程序中可以有多个具有逻辑焦点的元素，但在一个特定的焦点范围中只能有一个具有逻辑焦点的元素。

焦点范围是一个容器元素，用于跟踪[FocusedElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusmanager.focusedelement)其作用域内。 焦点离开焦点范围时，焦点元素会失去键盘焦点，但保留逻辑焦点。 焦点返回到焦点范围时，焦点元素会再次获得键盘焦点。 这使得键盘焦点可在多个焦点范围之间切换，但确保了焦点返回到焦点范围时，焦点范围中的焦点元素仍为焦点元素。

元素可以转换为中的焦点范围可扩展应用程序标记语言 (XAML)通过设置[FocusManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusmanager)附加属性[IsFocusScope](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusmanager.isfocusscope)到`true`，或在代码中设置附加的属性使用[SetIsFocusScope](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusmanager.setisfocusscope)方法。

以下示例使[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)转变为焦点范围，通过设置[IsFocusScope](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusmanager.isfocusscope)附加属性。

XAML复制

```xaml
<StackPanel Name="focusScope1" 
            FocusManager.IsFocusScope="True"
            Height="200" Width="200">
  <Button Name="button1" Height="50" Width="50"/>
  <Button Name="button2" Height="50" Width="50"/>
</StackPanel>
```

C#复制

```csharp
StackPanel focuseScope2 = new StackPanel();
FocusManager.SetIsFocusScope(focuseScope2, true);
```

中的类WPF为焦点范围的默认值是[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)， [Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)， [ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)，和[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)。

具有键盘焦点的元素，也将具有逻辑焦点; 它所属的焦点范围因此，具有的元素上设置焦点[Focus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard.focus)方法[Keyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard)类或基元素类将尝试为提供的元素键盘焦点和逻辑焦点。

若要确定焦点范围中具有焦点的元素，请使用[GetFocusedElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusmanager.getfocusedelement)。 若要更改焦点范围的焦点的元素，请使用[SetFocusedElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusmanager.setfocusedelement)。

有关逻辑焦点的详细信息，请参阅[焦点概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/focus-overview)。



## 鼠标位置

WPF 输入 API 提供了与坐标空间有关的有用信息。 例如，坐标 `(0,0)` 为左上角坐标，但该坐标是树中那一个元素的左上角坐标？ 是属于输入目标的元素？ 是在其上附加事件处理程序的元素？ 还是其他内容？ 为了避免混淆，WPF 输入 API 要求，在处理通过鼠标获取的坐标时，应指定参考框架。 [GetPosition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.mouse.getposition)方法返回鼠标指针相对于指定元素的坐标。



## 鼠标捕获

鼠标设备专门保留称为鼠标捕获的模式特征。 鼠标捕获用于在拖放操作开始时保持转换的输入状态，从而不一定发生涉及鼠标指针的标称屏幕位置的其他操作。 拖动过程中，未终止拖放时用户无法单击，这使得大多数鼠标悬停提示在拖动来源拥有鼠标捕获时是不合适的。 输入系统公开了可确定鼠标捕获状态的 API 以及可强制在特定元素上捕获鼠标或清除鼠标捕获状态的 API。 有关拖放操作的详细信息，请参阅[拖放概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/drag-and-drop-overview)。



## 命令

使用命令，输入处理可以更多地在语义级别（而不是在设备输入级别）进行。 命令是简单的指令，如 `Cut`、`Copy`、`Paste` 或 `Open`。 命令可用于集中命令逻辑。 可能从访问相同的命令[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)，然后在[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)，或通过键盘快捷方式。 命令还提供一种机制，用于在命令不可用时禁用控件。

[RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand) 是WPF的实现[ICommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommand)。 当[RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand)执行时，[PreviewExecuted](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandmanager.previewexecuted)和[Executed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandmanager.executed)的隧道和冒泡元素树与其他输入一样在命令目标上引发事件。 如果未设置命令目标，则具有键盘焦点的元素将成为命令目标。 执行此命令的逻辑附加到[CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding)。 当[Executed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandmanager.executed)事件到达[CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding)针对该特定命令[ExecutedRoutedEventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.executedroutedeventhandler)上[CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding)调用。 此处理程序执行该命令的操作。

有关命令的详细信息，请参阅[命令概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/commanding-overview)。

WPF 提供一个常用的命令组成的库[ApplicationCommands](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands)， [MediaCommands](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.mediacommands)， [ComponentCommands](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.componentcommands)， [NavigationCommands](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.navigationcommands)，和[EditingCommands](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.editingcommands)，也可以定义您自己。

下面的示例演示如何设置[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)，以便单击时它将调用[Paste](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands.paste)命令[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)，那么[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)具有键盘焦点。

XAML复制

```xaml
<StackPanel>
  <Menu>
    <MenuItem Command="ApplicationCommands.Paste" />
  </Menu>
  <TextBox />
</StackPanel>
```

C#复制

```csharp
  // Creating the UI objects
  StackPanel mainStackPanel = new StackPanel();
  TextBox pasteTextBox = new TextBox();
  Menu stackPanelMenu = new Menu();
  MenuItem pasteMenuItem = new MenuItem();
 
  // Adding objects to the panel and the menu
  stackPanelMenu.Items.Add(pasteMenuItem);
  mainStackPanel.Children.Add(stackPanelMenu);
  mainStackPanel.Children.Add(pasteTextBox);

  // Setting the command to the Paste command
  pasteMenuItem.Command = ApplicationCommands.Paste;

  // Setting the command target to the TextBox
  pasteMenuItem.CommandTarget = pasteTextBox;
```

有关 WPF 中的命令的详细信息，请参阅[命令概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/commanding-overview)。



## 输入系统和基元素

输入事件，例如由定义的附加事件[Mouse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.mouse)， [Keyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard)，和[Stylus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylus)类是由输入系统引发和注入的命中测试可视化树在运行时所基于的对象模型中的特定位置。

每个事件的[Mouse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.mouse)， [Keyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard)，并[Stylus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylus)定义为附加的事件还会重新显示由基元素类[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)和[ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement)作为新的路由事件。 基元素路由事件由处理原始附加事件并重用事件数据的类生成。

当输入事件通过其基元素输入事件实现与特定源元素相关联时，可以通过基于逻辑和可视化树对象的组合的事件路由的其余部分进行路由，并由应用程序代码进行处理。 通常情况下，它是处理使用路由的事件在这些设备相关的输入的事件更为方便[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)并[ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement)，这是因为您可以使用更直观事件处理程序中的语法这两个XAML和代码中。 你可以选择处理发起进程的附加事件，但将会面临几个问题：附加事件可能会被基元素类处理标记为已处理，并且你需要使用访问器方法（而不是真正的事件语法）才能为附加事件附加处理程序。



## 下一步

现在有多种方法来处理 WPF 中的输入。 你还应该对 WPF 使用的各种类型的输入事件和路由事件机制有进一步的了解。

也可以获取更详细说明 WPF 框架元素和事件路由的详细资源。 有关详细信息，请参阅以下概述：[命令概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/commanding-overview)、[焦点概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/focus-overview)、[基元素概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/base-elements-overview)、[WPF 中的树](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/trees-in-wpf)和[路由事件概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/routed-events-overview)。