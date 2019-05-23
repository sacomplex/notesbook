## [ContextMenu](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/contextmenu)

[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)允许控件显示[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)特定于控件的上下文。 通常情况下，[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)中公开用户界面 (UI)通过鼠标右键按钮或键盘的菜单按钮。

下图说明了[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)中两个不同状态: 打开状态和的默认状态。 在默认状态下，该控件处于折叠状态。 通过菜单的父按下鼠标右键按钮时，控件将展开，并显示的菜单项。

![ContextMenu 状态](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/ss-ctl-contextmenu.png)
ContextMenu 处于其他状态

### 本节内容

[ContextMenu 概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/contextmenu-overview)

### [ContextMenu Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/contextmenu-overview)

[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)类表示使用特定于上下文的公开功能的元素[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)。 通常情况下，用户公开[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)在用户界面 (UI)通过右键单击鼠标按钮。 本主题介绍[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)元素，并提供有关如何使用中的示例可扩展应用程序标记语言 (XAML)和代码。

#### ContextMenu 控件

一个[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)附加到特定控件。 [ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)元素使您能够为用户提供的项的指定命令或关联的选项与特定控件，例如，列表[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。 用户通过右键单击控件来显示菜单。 通常情况下，单击[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)打开子菜单或导致应用程序执行某个命令。

#### 创建 ContextMenus

以下示例演示如何创建[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)具有子菜单。 [ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)控件附加到按钮控件。

```xaml
<Button Name="cmButton" Height="30">
  Button with Context Menu
  <Button.ContextMenu>
    <ContextMenu Name="cm" Opened="OnOpened" Closed="OnClosed" StaysOpen="true">
      <MenuItem Header="File"/>
      <MenuItem Header="Save"/>
      <MenuItem Header="SaveAs"/>
      <MenuItem Header="Recent Files">
        <MenuItem Header="ReadMe.txt"/>
        <MenuItem Header="Schedule.xls"/>
      </MenuItem>
    </ContextMenu>
  </Button.ContextMenu>
</Button>
```

```csharp
btn = new Button();
btn.Content = "Created with C#";
contextmenu = new ContextMenu();
btn.ContextMenu = contextmenu;
mi = new MenuItem();
mi.Header = "File";
mia = new MenuItem();
mia.Header = "New";
mi.Items.Add(mia);
mib = new MenuItem();
mib.Header = "Open";
mi.Items.Add(mib);
mib1 = new MenuItem();
mib1.Header = "Recently Opened";
mib.Items.Add(mib1);
mib1a = new MenuItem();
mib1a.Header = "Text.xaml";
mib1.Items.Add(mib1a);
contextmenu.Items.Add(mi);
cv2.Children.Add(btn);
```

#### 将样式应用于 ContextMenu

通过使用控件[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)，可以显著改变外观和行为[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)而无需编写自定义控件。 除了设置可视化属性以外，还可以将样式应用于控件的各个部分。 例如，可以使用属性，来更改控件的部件的行为或可添加其他部分，或更改其布局[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)。 下面的示例演示几种方法添加到样式[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)控件。

第一个示例定义一个名为 `SimpleSysResources` 的样式，它演示如何在样式中使用当前的系统设置。 该示例将分配[MenuHighlightBrushKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemcolors.menuhighlightbrushkey)作为[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)颜色和[MenuTextBrushKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemcolors.menutextbrushkey)作为[Foreground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.foreground)的颜色[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)。

```xaml
<Style x:Key="SimpleSysResources" TargetType="{x:Type MenuItem}">  
  <Setter Property = "Background" Value=   
    "{DynamicResource {x:Static SystemColors.MenuHighlightBrushKey}}"/>  
  <Setter Property = "Foreground" Value=   
    "{DynamicResource {x:Static SystemColors.MenuTextBrushKey}}"/>  
</Style>  
```

下面的示例使用[Trigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.trigger)要更改的外观元素[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)响应，则将引发的事件[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)。 当用户将鼠标移到菜单的外观[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)项更改。

```xaml
<Style x:Key="Triggers" TargetType="{x:Type MenuItem}">  
  <Style.Triggers>  
    <Trigger Property="MenuItem.IsMouseOver" Value="true">  
      <Setter Property = "FontSize" Value="16"/>  
      <Setter Property = "FontStyle" Value="Italic"/>  
      <Setter Property = "Foreground" Value="Red"/>  
    </Trigger>  
  </Style.Triggers>  
</Style> 
```