# [Focus Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/focus-overview)

在 WPF 中，有两个与焦点有关的主要概念：键盘焦点和逻辑焦点。 键盘焦点指接收键盘输入的元素，而逻辑焦点指焦点范围中具有焦点的元素。 本概述详细介绍了这些概念。 对于创建具有多个可获取焦点的区域的复杂应用程序来说，理解这些概念之间的区别非常重要。

参与焦点管理的主要类是[Keyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard)类，[FocusManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusmanager)类和基元素类，如[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)和[ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement)。 有关基元素的详细信息，请参阅[基元素概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/base-elements-overview)。

[Keyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard)类而言主要与键盘焦点和[FocusManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusmanager)是主要关注逻辑焦点，但这不是一个绝对区别。 具有键盘焦点的元素也具有逻辑焦点，但具有逻辑焦点的元素不一定具有键盘焦点。 当你使用时，这是明显[Keyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard)类来设置为其具有键盘焦点的元素还在元素上设置逻辑焦点。



## 键盘焦点

键盘焦点指当前正在接收键盘输入的元素。 在整个桌面上，只能有一个具有键盘焦点的元素。 在中WPF，具有键盘焦点的元素将具有[IsKeyboardFocused](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.iinputelement.iskeyboardfocused)设置为`true`。 静态属性[FocusedElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard.focusedelement)上[Keyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard)类获取当前具有键盘焦点的元素。

为了使元素能够获取键盘焦点[Focusable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.focusable)并[IsVisible](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.isvisible)基元素上的属性必须设置为`true`。 一些类，如[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)基类，具有[Focusable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.focusable)设置为`false`默认情况下; 因此，您必须设置[Focusable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.focusable)到`true`如果希望此类元素能够获取键盘焦点。

可通过用户与 UI 交互（例如，按 Tab 键导航到某个元素或者在某些元素上单击鼠标）来获取键盘焦点。 键盘焦点还可以获取以编程方式通过使用[Focus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard.focus)方法[Keyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard)类。 [Focus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard.focus)方法尝试将指定的元素的键盘焦点给予。 返回的元素是具有键盘焦点的元素，如果旧的或新的焦点对象阻止请求，则具有键盘焦点的元素可能不是请求的元素。

下面的示例使用[Focus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard.focus)方法上设置键盘焦点[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。

C#复制

```csharp
private void OnLoaded(object sender, RoutedEventArgs e)
{
    // Sets keyboard focus on the first Button in the sample.
    Keyboard.Focus(firstButton);
}
```

[IsKeyboardFocused](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.iskeyboardfocused)基元素类上的属性获取一个值，该值指示元素是否具有键盘焦点。 [IsKeyboardFocusWithin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.iskeyboardfocuswithin)基元素类上的属性获取一个值，该值指示元素或其任何一个视觉子元素是否具有键盘焦点。

在设置初始焦点在应用程序启动时，应用程序，加载的初始窗口的可视化树中必须是要接收焦点的元素和元素必须具有[Focusable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.focusable)并[IsVisible](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.isvisible)设置为`true`。 若要设置初始焦点的建议的位置是在[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)事件处理程序。 一个[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)还可以通过调用使用回叫[Invoke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher.invoke)或[BeginInvoke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher.begininvoke)。



## 逻辑焦点

逻辑焦点指[FocusManager.FocusedElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusmanager.focusedelement)焦点范围中。 焦点范围是一个元素，用于跟踪[FocusedElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusmanager.focusedelement)其作用域内。 键盘焦点离开焦点范围时，焦点元素会失去键盘焦点，但保留逻辑焦点。 键盘焦点返回到焦点范围时，焦点元素会再次获得键盘焦点。 这使得键盘焦点可在多个焦点范围之间切换，但确保了焦点返回到焦点范围时，焦点范围中的焦点元素重新获得键盘焦点。

一个应用程序中可以有多个具有逻辑焦点的元素，但在一个特定的焦点范围中只能有一个具有逻辑焦点的元素。

具有键盘焦点的元素还具有其所属焦点范围的逻辑焦点。

元素可以转换为中的焦点范围可扩展应用程序标记语言 (XAML)通过设置[FocusManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusmanager)附加属性[IsFocusScope](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusmanager.isfocusscope)到`true`。 在代码中，元素可以打开转变为焦点范围通过调用[SetIsFocusScope](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusmanager.setisfocusscope)。

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

[GetFocusScope](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusmanager.getfocusscope) 返回指定元素的焦点范围。

中的类WPF为焦点范围的默认值是[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)， [MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)， [ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)，和[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)。

[GetFocusedElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusmanager.getfocusedelement) 获取指定的焦点范围内具有焦点的元素。 [SetFocusedElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusmanager.setfocusedelement) 在指定的焦点范围内设置具有焦点的元素。 [SetFocusedElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusmanager.setfocusedelement) 通常用于设置初始焦点的元素。

以下示例在焦点范围上设置焦点元素并获取焦点范围的焦点元素。

C#复制

```csharp
// Sets the focused element in focusScope1
// focusScope1 is a StackPanel.
FocusManager.SetFocusedElement(focusScope1, button2);

// Gets the focused element for focusScope 1
IInputElement focusedElement = FocusManager.GetFocusedElement(focusScope1);
```



## 键盘导航

[KeyboardNavigation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboardnavigation)类负责实现默认键盘焦点导航时按下导航键之一。 导航键包括：选项卡、 SHIFT + TAB、 CTRL + TAB、 CTRL + SHIFT + TAB、 向上键、 向下键、 向左键和向右键密钥。

可以通过设置附加更改导航容器的导航行为[KeyboardNavigation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboardnavigation)属性[TabNavigation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboardnavigation.tabnavigation)， [ControlTabNavigation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboardnavigation.controltabnavigation)，和[DirectionalNavigation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboardnavigation.directionalnavigation)。 这些属性属于类型[KeyboardNavigationMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboardnavigationmode)和可能的值为[Continue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboardnavigationmode#System_Windows_Input_KeyboardNavigationMode_Continue)， [Local](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboardnavigationmode#System_Windows_Input_KeyboardNavigationMode_Local)， [Contained](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboardnavigationmode#System_Windows_Input_KeyboardNavigationMode_Contained)， [Cycle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboardnavigationmode#System_Windows_Input_KeyboardNavigationMode_Cycle)， [Once](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboardnavigationmode#System_Windows_Input_KeyboardNavigationMode_Once)，和[None](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboardnavigationmode#System_Windows_Input_KeyboardNavigationMode_None)。 默认值是[Continue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboardnavigationmode#System_Windows_Input_KeyboardNavigationMode_Continue)，这意味着元素不是导航容器。

下面的示例创建[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)了大量的[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)对象。 [TabNavigation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboardnavigation.tabnavigation)附加的属性设置为[Cycle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboardnavigationmode#System_Windows_Input_KeyboardNavigationMode_Cycle)上[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)。 使用 tab 键在改变焦点时[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)，焦点将从每个元素和到达最后一个元素时，焦点将返回第一个元素。

XAML复制

```xaml
<Menu KeyboardNavigation.TabNavigation="Cycle">
  <MenuItem Header="Menu Item 1" />
  <MenuItem Header="Menu Item 2" />
  <MenuItem Header="Menu Item 3" />
  <MenuItem Header="Menu Item 4" />
</Menu>
```

C#复制

```csharp
Menu navigationMenu = new Menu();
MenuItem item1 = new MenuItem();
MenuItem item2 = new MenuItem();
MenuItem item3 = new MenuItem();
MenuItem item4 = new MenuItem();

navigationMenu.Items.Add(item1);
navigationMenu.Items.Add(item2);
navigationMenu.Items.Add(item3);
navigationMenu.Items.Add(item4);

KeyboardNavigation.SetTabNavigation(navigationMenu, 
    KeyboardNavigationMode.Cycle);
```



## 以编程方式导航焦点

其他API才能使用焦点会[MoveFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.movefocus)和[PredictFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.predictfocus)。

[MoveFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.movefocus) 将焦点移至应用程序中的下一个元素。 一个[TraversalRequest](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.traversalrequest)使用指定的方向。[FocusNavigationDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusnavigationdirection)传递给[MoveFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.movefocus)指定不同的方向焦点可以移动，例如[First](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusnavigationdirection#System_Windows_Input_FocusNavigationDirection_First)， [Last](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusnavigationdirection#System_Windows_Input_FocusNavigationDirection_Last)，[Up](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusnavigationdirection#System_Windows_Input_FocusNavigationDirection_Up)和[Down](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusnavigationdirection#System_Windows_Input_FocusNavigationDirection_Down)。

下面的示例使用[MoveFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.movefocus)若要更改具有焦点的元素。

C#复制

```csharp
// Creating a FocusNavigationDirection object and setting it to a
// local field that contains the direction selected.
FocusNavigationDirection focusDirection = _focusMoveValue;

// MoveFocus takes a TraveralReqest as its argument.
TraversalRequest request = new TraversalRequest(focusDirection);

// Gets the element with keyboard focus.
UIElement elementWithFocus = Keyboard.FocusedElement as UIElement;

// Change keyboard focus.
if (elementWithFocus != null)
{
    elementWithFocus.MoveFocus(request);
}
```

[PredictFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.predictfocus) 返回对象，将焦点更改时接收焦点。 目前，仅[Up](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusnavigationdirection#System_Windows_Input_FocusNavigationDirection_Up)， [Down](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusnavigationdirection#System_Windows_Input_FocusNavigationDirection_Down)， [Left](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusnavigationdirection#System_Windows_Input_FocusNavigationDirection_Left)，和[Right](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusnavigationdirection#System_Windows_Input_FocusNavigationDirection_Right)受[PredictFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.predictfocus)。



## 焦点事件

与键盘焦点相关的事件都[PreviewGotKeyboardFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard.previewgotkeyboardfocus)，[GotKeyboardFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard.gotkeyboardfocus)并[PreviewLostKeyboardFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard.previewlostkeyboardfocus)， [LostKeyboardFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard.lostkeyboardfocus)。 事件定义为附加事件上[Keyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard)类，但作为基元素类上的等效路由事件可更轻松地访问。有关事件的详细信息，请参阅[路由事件概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/routed-events-overview)。

[GotKeyboardFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard.gotkeyboardfocus) 该元素获取键盘焦点时引发。 [LostKeyboardFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard.lostkeyboardfocus) 元素失去键盘焦点时引发。 如果[PreviewGotKeyboardFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard.previewgotkeyboardfocus)事件或[PreviewLostKeyboardFocusEvent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keyboard.previewlostkeyboardfocusevent)处理事件并[Handled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedeventargs.handled)设置为`true`，则焦点不会更改。

下面的示例将附加[GotKeyboardFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.gotkeyboardfocus)并[LostKeyboardFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.lostkeyboardfocus)的事件处理程序[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。

XAML复制

```xaml
<Border BorderBrush="Black" BorderThickness="1"
        Width="200" Height="100" Margin="5">
  <StackPanel>
    <Label HorizontalAlignment="Center" Content="Type Text In This TextBox" />
    <TextBox Width="175"
             Height="50" 
             Margin="5"
             TextWrapping="Wrap"
             HorizontalAlignment="Center"
             VerticalScrollBarVisibility="Auto"
             GotKeyboardFocus="TextBoxGotKeyboardFocus"
             LostKeyboardFocus="TextBoxLostKeyboardFocus"
             KeyDown="SourceTextKeyDown"/>
  </StackPanel>
</Border>
```

当[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)获取键盘焦点[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)的属性[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)更改为[LightBlue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brushes.lightblue)。

C#复制

```csharp
private void TextBoxGotKeyboardFocus(object sender, KeyboardFocusChangedEventArgs e)
{
    TextBox source = e.Source as TextBox;

    if (source != null)
    {
        // Change the TextBox color when it obtains focus.
        source.Background = Brushes.LightBlue;

        // Clear the TextBox.
        source.Clear();
    }
}
```

当[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)失去键盘焦点[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)属性的[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)更改回 white。

C#复制

```csharp
private void TextBoxLostKeyboardFocus(object sender, KeyboardFocusChangedEventArgs e)
{
    TextBox source = e.Source as TextBox;

    if (source != null)
    {
        // Change the TextBox color when it loses focus.
        source.Background = Brushes.White;

        // Set the  hit counter back to zero and updates the display.
        this.ResetCounter();
    }
}
```

与逻辑焦点相关的事件都[GotFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.gotfocus)和[LostFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.lostfocus)。 这些事件定义上[FocusManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusmanager)为附加事件，但[FocusManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.focusmanager)不公开 CLR 事件包装器。 [UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement) 和[ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement)更方便地公开这些事件。