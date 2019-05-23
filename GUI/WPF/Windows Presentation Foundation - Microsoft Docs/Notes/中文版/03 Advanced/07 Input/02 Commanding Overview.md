# [Commanding Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/commanding-overview)

命令是 Windows Presentation Foundation (WPF) 中的一种输出机制，与设备输出相比，其提供的输出处理更侧重于语义级别。 示例命令如许多应用程序均具有的“复制”、“剪切”和“粘贴”操作。

本概述定义 WPF 中有哪些命令、哪些类属于命令模型以及如何在应用程序中使用和创建命令。

本主题包含以下各节：

- [什么是命令？](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/commanding-overview#commands_at_10000_feet)
- [WPF 中的简单命令示例](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/commanding-overview#simple_command)
- [WPF 命令中的四个主要概念](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/commanding-overview#Four_main_Concepts)
- [命令库](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/commanding-overview#Command_Library)
- [创建自定义命令](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/commanding-overview#creating_commands)



## 什么是命令？

命令具有多个用途。 第一个用途是分隔语义和从执行命令的逻辑调用命令的对象。 这可使多个不同的源调用同一命令逻辑，并且可针对不同目标自定义命令逻辑。 例如，许多应用程序中均有的编辑操作“复制”、“剪切”和“粘贴”若通过使用命令来实现，那么可通过使用不同的用户操作来调用它们。 应用程序可允许用户通过单击按钮、选择菜单中的项或使用组合键（例如 Ctrl+X）来剪切所选对象或文本。 通过使用命令，可将每种类型的用户操作绑定到相同逻辑。

命令的另一用途是指示操作是否可用。 继续以剪切对象或文本为例，此操作只有在选择了内容时才会发生作用。如果用户在未选择任何内容的情况下尝试剪切对象或文本，则不会发生任何操作。 为了向用户指示这一点，许多应用程序通过禁用按钮和菜单项来告知用户是否可以执行某操作。 命令可以通过实现 [CanExecute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommand.canexecute) 方法来指示操作是否可行。 按钮可以订阅 [CanExecuteChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommand.canexecutechanged) 事件，如果 [CanExecute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommand.canexecute) 返回 `false` 则禁用，如果 [CanExecute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommand.canexecute) 返回 `true` 则启用。

虽然命令的语义在应用程序和类之间可保持一致，但操作的逻辑特定于操作所针对的特定对象。 组合键 Ctrl+X 调用文本类、图像类和 Web 浏览器中的“剪切”命令，但执行“剪切”操作的实际逻辑由执行剪切的应用程序定义。[RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand) 使客户端实现逻辑。 文本对象可将所选文本剪切到剪贴板，而图像对象则剪切所选图像。 应用程序处理 [Executed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandmanager.executed) 事件时可访问命令的目标，并根据目标的类型采取相应操作。



## WPF 中的简单命令示例

使用 WPF 中命令的最简单方式是使用其中一个命令库类中预定义的 [RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand)；使用具有命令处理本机支持的控件；使用具有命令调用本机支持的控件。 [Paste](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands.paste) 命令是 [ApplicationCommands](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands) 类中的预定义命令之一。[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 控件含有用于处理 [Paste](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands.paste) 命令的内置逻辑。 [MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem) 类具有调用命令的本机支持。

以下示例显示了如何设置 [MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)，以便在单击时它将调用 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 上的 [Paste](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands.paste) 命令，假定 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 具有键盘焦点。

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



## WPF 命令中的四个主要概念

WPF 中的路由命令模型可分解为四个主要概念：命令、命令源、命令目标和命令绑定：

- *命令*是要执行的操作。
- *命令源*是调用命令的对象。
- *命令目标*是在其上执行命令的对象。
- *命令绑定*是将命令逻辑映射到命令的对象。

在前面的示例中，[Paste](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands.paste) 命令是命令，[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem) 是命令源，[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 是命令目标，命令绑定由 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 控件提供。 值得注意的是，[CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding) 并不总是由作为命令目标类的控件提供。 通常，[CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding) 必须由应用程序开发者创建，否则 [CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding) 可能会附加到命令目标的上级元素。



### 命令

WPF 中的命令是通过实现 [ICommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommand) 接口创建的。 [ICommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommand) 公开了两种方法 [Execute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommand.execute) 和 [CanExecute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommand.canexecute)，以及一个事件 [CanExecuteChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommand.canexecutechanged)。 [Execute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommand.execute) 执行与该命令关联的操作。 [CanExecute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommand.canexecute) 确定是否可以在当前命令目标上执行该命令。 如果集中管理命令操作的命令管理器检测到命令源中存在一个可能使已引发命令无效但尚未由命令绑定执行的更改，则会引发 [CanExecuteChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommand.canexecutechanged)。 [ICommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommand) 的 WPF 实现是 [RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand) 类，并且是本概述的重点。

WPF 中输入的主要源是鼠标、键盘、墨迹和路由命令。 面向设备程度更高的输入使用 [RoutedEvent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedevent) 通知应用程序页中的对象输入事件已发生。 [RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand) 也不例外。 [RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand) 的 [Execute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand.execute) 和 [CanExecute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand.canexecute) 方法不包含该命令的应用程序逻辑，而是引发通过元素树通行和浮升的路由事件，直到遇到具有 [CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding) 的对象。 [CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding) 包含这些事件的处理程序，命令正是由这些处理程序执行。 有关 WPF 中事件路由的详细信息，请参阅[路由事件概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/routed-events-overview)。

[RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand) 上的 [Execute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand.execute) 方法引发命令目标上的 [PreviewExecuted](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandmanager.previewexecuted) 和 [Executed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandmanager.executed) 事件。 [RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand) 上的 [CanExecute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand.canexecute) 方法引发命令目标上的 [CanExecute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandmanager.canexecute) 和 [PreviewCanExecute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandmanager.previewcanexecute) 事件。 这些事件通过元素树通行和浮升，直到遇到一个具有针对该特定命令的 [CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding) 的对象。

WPF 提供了分布在几个类中的一组常用路由命令：[MediaCommands](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.mediacommands)、[ApplicationCommands](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands)、[NavigationCommands](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.navigationcommands)、[ComponentCommands](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.componentcommands) 和 [EditingCommands](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.editingcommands)。 这些类仅由 [RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand) 对象构成，而不包含命令的实现逻辑。 实现逻辑由在其上执行命令的对象负责。



### 命令源

命令源是调用命令的对象。 命令源的示例有 [MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)、[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) 和 [KeyGesture](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keygesture)。

WPF 中的命令源通常实现 [ICommandSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource) 接口。

[ICommandSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource) 公开三个属性：[Command](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource.command)、[CommandTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource.commandtarget) 和 [CommandParameter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource.commandparameter)：

- [Command](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource.command) 是在调用命令源时执行的命令。
- [CommandTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource.commandtarget) 是要执行命令的对象。 值得注意的是，在 WPF 中，仅当 [ICommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommand) 为 [RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand)时，[ICommandSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource) 上的 [CommandTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource.commandtarget) 属性才适用。 如果在 [ICommandSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource) 上设置 [CommandTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource.commandtarget) 并且相应的命令不是 [RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand)，则忽略命令目标。 如果未设置 [CommandTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource.commandtarget)，则具有键盘焦点的元素将成为命令目标。
- [CommandParameter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource.commandparameter) 是用于将信息传递给实现命令的处理程序的用户定义数据类型。

实现 [ICommandSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource) 的 WPF 类是 [ButtonBase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase)、[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)、[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink) 和 [InputBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.inputbinding)。 单击 [ButtonBase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase)、[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem) 和 [Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink) 时，调用一个命令，当执行与其关联的 [InputGesture](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.inputgesture) 时，[InputBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.inputbinding) 调用命令。

以下示例显示如何将 [ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu) 中的 [MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem) 用作 [Properties](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands.properties) 命令的命令源。

XAML复制

```xaml
<StackPanel>
  <StackPanel.ContextMenu>
    <ContextMenu>
      <MenuItem Command="ApplicationCommands.Properties" />
    </ContextMenu>
  </StackPanel.ContextMenu>
</StackPanel>
```

C#复制

```csharp
StackPanel cmdSourcePanel = new StackPanel();
ContextMenu cmdSourceContextMenu = new ContextMenu();
MenuItem cmdSourceMenuItem = new MenuItem();

// Add ContextMenu to the StackPanel.
cmdSourcePanel.ContextMenu = cmdSourceContextMenu;
cmdSourcePanel.ContextMenu.Items.Add(cmdSourceMenuItem);

// Associate Command with MenuItem.
cmdSourceMenuItem.Command = ApplicationCommands.Properties;
```

通常，命令源将侦听 [CanExecuteChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand.canexecutechanged) 事件。 此事件通知命令源在当前命令目标上执行命令的能力可能已发生更改。 命令源可以使用 [CanExecute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand.canexecute) 方法查询 [RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand) 的当前状态。 如果命令无法执行，命令源可禁用自身。 此情况的一个示例是 [MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)，在命令无法执行时，它自身将灰显。

[InputGesture](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.inputgesture) 可以用作命令源。 WPF 中的两种输入笔势是 [KeyGesture](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keygesture) 和 [MouseGesture](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.mousegesture)。 可以将 [KeyGesture](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keygesture) 视为键盘快捷方式，例如 Ctrl+C。 [KeyGesture](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keygesture) 由一个 [Key](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.key) 和一组 [ModifierKeys](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.modifierkeys) 组成。 [MouseGesture](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.mousegesture) 由 [MouseAction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.mouseaction) 和一组可选的 [ModifierKeys](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.modifierkeys) 组成。

为了将 [InputGesture](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.inputgesture) 用作命令源，它必须与一个命令相关联。 可通过几种方式来实现此目的。 其中一种方法是使用 [InputBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.inputbinding)。

以下示例演示如何在 [KeyGesture](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keygesture) 和 [RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand) 之间创建 [KeyBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keybinding)。

XAML复制

```xaml
<Window.InputBindings>
  <KeyBinding Key="B"
              Modifiers="Control" 
              Command="ApplicationCommands.Open" />
</Window.InputBindings>
```

C#复制

```csharp
KeyGesture OpenKeyGesture = new KeyGesture(
    Key.B,
    ModifierKeys.Control);

KeyBinding OpenCmdKeybinding = new KeyBinding(
    ApplicationCommands.Open,
    OpenKeyGesture);

this.InputBindings.Add(OpenCmdKeybinding);
```

将 [InputGesture](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.inputgesture) 关联到 [RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand) 的另一种方法是将 [InputGesture](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.inputgesture) 添加到 [RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand) 上的 [InputGestureCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.inputgesturecollection)。

以下示例演示如何将 [KeyGesture](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.keygesture) 添加到 [RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand) 的 [InputGestureCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.inputgesturecollection) 中。

C#复制

```csharp
KeyGesture OpenCmdKeyGesture = new KeyGesture(
    Key.B,
    ModifierKeys.Control);

ApplicationCommands.Open.InputGestures.Add(OpenCmdKeyGesture);
```



### CommandBinding

[CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding) 将命令与实现该命令的事件处理程序相关联。

[CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding) 类包含 [Command](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding.command) 属性，及 [PreviewExecuted](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding.previewexecuted)、[Executed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding.executed)、[PreviewCanExecute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding.previewcanexecute) 和 [CanExecute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding.canexecute)事件。

[Command](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding.command) 是与 [CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding) 关联的命令。 附加到 [PreviewExecuted](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding.previewexecuted) 和 [Executed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding.executed) 事件的事件处理程序实现命令逻辑。 附加到 [PreviewCanExecute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding.previewcanexecute) 和 [CanExecute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding.canexecute) 事件的事件处理程序确定是否可以在当前命令目标上执行该命令。

以下示例演示如何在应用程序的根 [Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window) 上创建 [CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding)。 [CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding) 将 [Open](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands.open) 命令与 [Executed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandmanager.executed) 和 [CanExecute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding.canexecute) 处理程序关联。

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

接下来，创建了 [ExecutedRoutedEventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.executedroutedeventhandler) 和 [CanExecuteRoutedEventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.canexecuteroutedeventhandler)。[ExecutedRoutedEventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.executedroutedeventhandler) 打开了显示字符串的 [MessageBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.messagebox)，该字符串表示已执行此命令。[CanExecuteRoutedEventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.canexecuteroutedeventhandler) 将 [CanExecute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.canexecuteroutedeventargs.canexecute) 属性设置为 `true`。

C#复制

```csharp
void OpenCmdExecuted(object target, ExecutedRoutedEventArgs e)
{
    String command, targetobj;
    command = ((RoutedCommand)e.Command).Name;
    targetobj = ((FrameworkElement)target).Name;
    MessageBox.Show("The " + command +  " command has been invoked on target object " + targetobj);
}
```

C#复制

```csharp
void OpenCmdCanExecute(object sender, CanExecuteRoutedEventArgs e)
{
    e.CanExecute = true;
}
```

将 [CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding) 附加到特定对象，例如应用程序或控件的根 [Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)。 [CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding) 附加到的对象定义了绑定的范围。 例如，附加到命令目标的上级元素的 [CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding) 可以通过 [Executed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding.executed) 事件到达，但无法到达附加到命令目标的下级元素的 [CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding)。 其直接原因在于 [RoutedEvent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedevent) 从引发事件的对象通行和浮升的方式。

在某些情况下，[CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding) 会附加到命令目标本身，例如 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 类及 [Cut](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands.cut)、[Copy](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands.copy) 和 [Paste](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands.paste) 命令。 然而，很多时候将 [CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding) 附加到命令目标的上级元素（例如主要 [Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window) 或应用程序对象）会更加方便，尤其是在同一 [CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding) 可用于多个命令目标时。 这是在创建命令基础结构时需要考虑的设计决策。



### 命令目标

命令目标是在其上执行命令的元素。 关于 [RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand)，命令目标是 [Executed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandmanager.executed) 和 [CanExecute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandmanager.canexecute) 的路由开始的元素。 如前所述，在 WPF 中，仅当 [ICommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommand) 为 [RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand) 时，[ICommandSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource) 上的 [CommandTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource.commandtarget) 属性才适用。 如果在 [ICommandSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource) 上设置 [CommandTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommandsource.commandtarget) 并且相应的命令不是 [RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand)，则忽略命令目标。

命令源可以显式设置命令目标。 如果未定义命令目标，则具有键盘焦点的元素将用作命令目标。 将具有键盘焦点的元素用作命令目标的一个好处在于，这样可使应用程序开发者能够使用同一命令源在多个目标上调用命令，而无需跟踪命令目标。 例如，如果 [MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem) 在具有 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 控件和 [PasswordBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.passwordbox) 控件的应用程序中调用“Paste”命令，则目标可以是 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 或 [PasswordBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.passwordbox)，具体取决于哪个控件具有键盘焦点。

以下示例演示如何在标记和代码隐藏中显式设置命令目标。

XAML复制

```xaml
<StackPanel>
  <Menu>
    <MenuItem Command="ApplicationCommands.Paste"
              CommandTarget="{Binding ElementName=mainTextBox}" />
  </Menu>
  <TextBox Name="mainTextBox"/>
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



### CommandManager

[CommandManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandmanager) 提供许多与命令相关的函数。 它提供了一组静态方法，用于在特定元素中添加和删除 [PreviewExecuted](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandmanager.previewexecuted)、[Executed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandmanager.executed)、[PreviewCanExecute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandmanager.previewcanexecute) 和 [CanExecute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandmanager.canexecute) 事件处理程序。 它提供了将 [CommandBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandbinding)和 [InputBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.inputbinding) 对象注册到特定类的方法。 [CommandManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandmanager) 还通过 [RequerySuggested](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandmanager.requerysuggested) 事件提供了一种方法，用于在应引发 [CanExecuteChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommand.canexecutechanged) 事件时通知命令。

[InvalidateRequerySuggested](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandmanager.invalidaterequerysuggested) 方法强制 [CommandManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandmanager) 引发 [RequerySuggested](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandmanager.requerysuggested) 事件。 这在应禁用/启用命令的情况下非常有用，但对于 [CommandManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.commandmanager) 可识别的情况，则不太有用。



## 命令库

WPF 提供一组预定义命令。 命令库包括以下类：[ApplicationCommands](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands)、[NavigationCommands](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.navigationcommands)、[MediaCommands](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.mediacommands)、[EditingCommands](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.editingcommands) 和 [ComponentCommands](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.componentcommands)。 这些类提供诸如 [Cut](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.applicationcommands.cut)、[BrowseBack](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.navigationcommands.browseback)、[BrowseForward](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.navigationcommands.browseforward)、[Play](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.mediacommands.play)、[Stop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.mediacommands.stop) 和 [Pause](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.mediacommands.pause) 的命令。

许多这些命令都包含一组默认输入绑定。 例如，如果指定应用程序处理复制命令，则可自动获取键盘绑定“CTRL+C”。此外，还可获得其他输入设备的绑定，例如 Tablet PC 笔势和语音信息。

使用 XAML 引用各个命令库中的命令时，通常可省略公开静态命令属性的库类的类名。 一般来说，命令名称是明确作为字符串的，且存在所属类型来提供命令的逻辑分组，不过对于消除二义性这并不必要。 例如，可指定 `Command="Cut"` 而不是更为冗长的 `Command="ApplicationCommands.Cut"`。 这是针对命令内置于 WPF XAML 处理器中的便捷机制（更准确地说，它是 WPF XAML 处理器在加载时所引用的 [ICommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommand) 的类型转换器行为）。



## 创建自定义命令

如果命令库类中的命令不能满足需要，你可以创建自己的命令。 可通过两种方式创建自定义命令。 第一种方式是从头开始并实现 [ICommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.icommand) 接口。 另一种更常见的方法是创建 [RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand) 或 [RoutedUICommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routeduicommand)。

有关创建自定义 [RoutedCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.routedcommand) 的示例，请参阅[创建自定义 RoutedCommand 示例](https://github.com/Microsoft/WPF-Samples/tree/master/Input%20and%20Commands/CustomRoutedCommand)。