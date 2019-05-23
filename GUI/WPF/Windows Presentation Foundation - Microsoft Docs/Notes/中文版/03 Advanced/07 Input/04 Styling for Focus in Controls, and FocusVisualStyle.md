# [Styling for Focus in Controls, and FocusVisualStyle](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/styling-for-focus-in-controls-and-focusvisualstyle)

Windows Presentation Foundation (WPF) 提供两种用于在控件接收键盘焦点时更改其视觉外观的并行机制。 第一种机制是使用属性资源库属性如[IsKeyboardFocused](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.iskeyboardfocused)样式或模板应用于控件中。 第二种机制是提供一个单独的样式的值作为[FocusVisualStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.focusvisualstyle)属性;"焦点视觉样式"为绘制控件，而不更改控件或其他 UI 的可视化树的装饰器创建单独的可视化树通过替换的元素。 本主题讨论上述每一种机制的适用情况。



## 焦点视觉样式的用途

焦点视觉样式功能提供一种通用“对象模型”，用于基于任何 UI 元素的键盘导航来引入视觉用户反馈。 即使未向控件应用新模板，或者不知道具体的模板组合，这也是可能的。

但是，正因为焦点视觉样式功能可以在不知道控件模板的情况下工作，所以必须限制可针对使用焦点视觉样式的控件显示的视觉反馈。 此功能实际执行的操作是在控件通过模板进行呈现来创建可视化树时在其上覆盖另一可视化树（装饰器）。 定义此单独的可视化树，使用填充的样式[FocusVisualStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.focusvisualstyle)属性。



## 默认焦点视觉样式行为

焦点视觉样式仅在焦点操作由键盘启动时才起作用。 任何鼠标操作或者通过编程实现的焦点更改都会禁用焦点视觉样式模式。 有关焦点模式间区别的详细信息，请参阅[焦点概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/focus-overview)。

控件的主题包括默认焦点视觉样式行为，该焦点视觉样式成为主题中所有控件的焦点视觉样式。 此主题样式由静态键的值标识[FocusVisualStyleKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemparameters.focusvisualstylekey)。 当在应用程序级声明自己的焦点视觉样式时，将替换主题中的这一默认样式行为。 或者，如果要定义整个主题，那么应同样使用这个键来为整个主题的默认行为定义样式。

在主题中，默认焦点视觉样式通常非常简单。 下面是一个近似的焦点视觉样式：

XAML复制

```xaml
<Style x:Key="{x:Static SystemParameters.FocusVisualStyleKey}">  
  <Setter Property="Control.Template">  
    <Setter.Value>  
      <ControlTemplate>  
        <Rectangle StrokeThickness="1"  
          Stroke="Black"  
          StrokeDashArray="1 2"  
          SnapsToDevicePixels="true"/>  
      </ControlTemplate>  
    </Setter.Value>  
  </Setter>  
</Style>  
```



## 何时使用焦点视觉样式

从概念上来说，应用于控件的焦点视觉样式的外观在所有控件上应该是一致的。 确保一致性的一种方法是仅在创作整个主题时才更改焦点视觉样式，这样主题中定义的每个控件都要么获得完全相同的焦点视觉样式，要么获得在视觉上与控件具有相关性的某一样式的变体。 或者，可能使用相同的样式（或类似的样式）来设置页面或 UI 中每个可通过键盘获得焦点的元素的样式。

设置[FocusVisualStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.focusvisualstyle)不属于主题一部分的各个控件样式上是不的预期的用法的焦点视觉样式。 这是因为控件间的不一致视觉行为会使用户对键盘焦点产生混乱的感觉。 如果打算为键盘焦点的特定于控件的行为，需要有意地不连贯整个主题，更好的方法是使用触发器在样式中的个别输入的状态属性，如[IsFocused](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.isfocused)或[IsKeyboardFocused](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.iskeyboardfocused)。

焦点视觉样式专门作用于键盘焦点。 就其本身而言，焦点视觉样式是一种辅助功能。 如果希望针对任何类型的焦点来更改 UI（无论是通过鼠标、键盘还是编程方式），那么不应使用焦点视觉样式，而应在样式或模板中使用 setter 和触发器，它们根据常规焦点属性（如 [IsFocused](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.isfocused) 或 [IsKeyboardFocusWithin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.iskeyboardfocuswithin)）的值发生作用。



## 如何创建焦点视觉样式

样式创建应始终具有焦点视觉样式[TargetType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style.targettype)的[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)。 样式应主要包含[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。 未指定目标类型为其中的焦点视觉样式分配给类型[FocusVisualStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.focusvisualstyle)。

由于目标类型始终是[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)，你必须使用设置样式的所有控件共有的属性 (使用的属性[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)类和其基类)。 应创建将正确地用作 UI 元素的覆盖层、且不会隐藏控件的功能区域的模板。 通常，这意味着视觉反馈应显示在控件边距之外，或者显示为临时的或不显眼的效果（这样就不会阻止应用焦点视觉样式的控件上的命中测试）。 可以使用模板绑定中的可用于确定覆盖模板的大小和位置的属性包括[ActualHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.actualheight)， [ActualWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.actualwidth)， [Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)，和[Padding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.padding)。



## 使用焦点视觉样式的替代方法

对于不适合使用焦点视觉样式的情况（因为仅设置单个控件的样式或希望对控件模板有更多的控制），存在许多其他可用的属性和技术，可用来创建响应焦点更改的视觉行为。

[样式设置和模板化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/styling-and-templating)中对触发器、setter 以及事件 setter 进行了详细介绍。 [路由事件概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/routed-events-overview)中对路由事件处理进行了介绍。

### IsKeyboardFocused

如果您特别感兴趣键盘焦点[IsKeyboardFocused](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.iskeyboardfocused)依赖项属性可用于属性[Trigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.trigger)。 对于定义专用于单个控件且可能与其他控件的键盘焦点行为在视觉上不匹配的键盘焦点行为，一个更适合的方法是使用样式或模板中的属性触发器。

另一个类似的依赖项属性是[IsKeyboardFocusWithin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.iskeyboardfocuswithin)，可能适合使用如果你想要以可视方式调用该键盘焦点位于的某个位置或控件的功能区域内组合的情况。 例如，可能会将[IsKeyboardFocusWithin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.iskeyboardfocuswithin)触发器，以便多个控件的面板的外观会有所不同，即使键盘焦点可能更准确地说是在该面板中的某个元素上。

您还可以使用事件[GotKeyboardFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.gotkeyboardfocus)和[LostKeyboardFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.lostkeyboardfocus)（以及其 Preview 等效项）。 您可以使用这些事件为基础[EventSetter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventsetter)，也可以在代码隐藏中编写事件的处理程序。

### 其他焦点属性

如果您希望所有可能的原因更改焦点的以产生一个视觉行为，应将 setter 或触发[IsFocused](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.isfocused)依赖项属性，或者在[GotFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.gotfocus)或[LostFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.lostfocus)用于事件[EventSetter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventsetter)。