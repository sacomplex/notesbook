# [ToolBar](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/toolbar)

[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)控件是一组命令或通常在功能上相关的控件的容器。

下图显示了水平和垂直[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)控件。

![水平工具栏](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/ss-ctl-horztoolbar.gif)
水平工具栏

![垂直工具栏](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/ss-ctl-verttoolbar.gif)
垂直工具栏

## [ToolBar Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/toolbar-overview)

[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar) 控件是一组命令或控件通常在功能上相关的容器。 一个[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)通常包含调用命令的按钮。

### ToolBar 控件

[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)控件采用从到单个行或列的按钮或其他控件栏类似于排列其名称。 WPF [ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar) 控件提供一种溢出机制的任意大小约束中执行操作无法自然容纳的项放[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)到特殊的溢出区域。 此外， WPF [ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)控件通常用于与相关[ToolBarTray](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbartray)提供特殊的布局行为，以及支持用于用户启动的大小和排列工具栏的控件。

### 在 ToolBarTray 中指定 ToolBar 位置

使用[Band](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar.band)并[BandIndex](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar.bandindex)属性来定位[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)中[ToolBarTray](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbartray)。 [Band](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar.band) 指示在其中的位置[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)放置在其父[ToolBarTray](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbartray)。 [BandIndex](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar.bandindex) 指示在其中顺序[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)其区段内放置。 下面的示例演示如何使用此属性将[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)控件内[ToolBarTray](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbartray)。

```xaml
<ToolBarTray Background="White">
  <ToolBar Band="1" BandIndex="1">
    <Button>
      <Image Source="toolbargraphics\cut.bmp" />
    </Button>
    <Button>
      <Image Source="toolbargraphics\copy.bmp" />
    </Button>
    <Button>
      <Image Source="toolbargraphics\paste.bmp" />
    </Button>
  </ToolBar>
  <ToolBar Band="2" BandIndex="1">
    <Button>
      <Image Source="toolbargraphics\undo.bmp" />
    </Button>
    <Button>
      <Image Source="toolbargraphics\redo.bmp" />
    </Button>
  </ToolBar>
  <ToolBar Band="2" BandIndex="2">
    <Button>
      <Image Source="toolbargraphics\paint.bmp" />
    </Button>
    <Button>
      <Image Source="toolbargraphics\spell.bmp" />
    </Button>
    <Separator/>
    <Button>
      <Image Source="toolbargraphics\save.bmp" />
    </Button>
    <Button>
      <Image Source="toolbargraphics\open.bmp" />
    </Button>
  </ToolBar>
</ToolBarTray>
```

### 带有溢出项的 ToolBar

通常[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)控件包含更多的项不是可以适合于工具栏的大小。 在此情况下，[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)显示溢出按钮。 若要查看溢出项，用户单击了溢出按钮，并且这些项将显示在下方的弹出窗口中[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)。 下图显示[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)带有溢出项。

![存在溢出的工具栏](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/toolbarwithoverflowitem.png)
带有溢出项的 ToolBar

您可以指定工具栏上的项当通过设置在溢出面板上放置[ToolBar.OverflowMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar.overflowmode)附加属性设置为[OverflowMode.Always](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.overflowmode#System_Windows_Controls_OverflowMode_Always)， [OverflowMode.Never](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.overflowmode#System_Windows_Controls_OverflowMode_Never)，或[OverflowMode.AsNeeded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.overflowmode#System_Windows_Controls_OverflowMode_AsNeeded)。 以下示例指定工具栏上的最后四个按钮应始终在溢出面板上。

```xaml
<ToolBarTray Background="White">
  <ToolBar Band="1" BandIndex="1">
    <Button>
      <Image Source="toolbargraphics\cut.bmp" />
    </Button>
    <Button>
      <Image Source="toolbargraphics\copy.bmp" />
    </Button>
    <Button>
      <Image Source="toolbargraphics\paste.bmp" />
    </Button>
    <Button>
      <Image Source="toolbargraphics\undo.bmp" />
    </Button>
    <Button>
      <Image Source="toolbargraphics\redo.bmp" />
    </Button>
    <Button>
      <Image Source="toolbargraphics\paint.bmp" />
    </Button>
    <Button>
      <Image Source="toolbargraphics\spell.bmp" />
    </Button>
    <Separator/>
    <Button ToolBar.OverflowMode="Always">
      <Image Source="toolbargraphics\save.bmp" />
    </Button>
    <Button ToolBar.OverflowMode="Always">
      <Image Source="toolbargraphics\open.bmp" />
    </Button>
    <Button ToolBar.OverflowMode="Always">
      <Image Source="toolbargraphics\print.bmp" />
    </Button>
    <Button ToolBar.OverflowMode="Always">
      <Image Source="toolbargraphics\preview.bmp" />
    </Button>
  </ToolBar>
</ToolBarTray>
```

[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)使用[ToolBarPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.toolbarpanel)和一个[ToolBarOverflowPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.toolbaroverflowpanel)中其[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。 [ToolBarPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.toolbarpanel)负责在工具栏上的项的布局。 [ToolBarOverflowPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.toolbaroverflowpanel)负责无法容纳的项的布局[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)。 有关的示例[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)，请参阅

[ToolBar 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/toolbar-styles-and-templates)。

## [Style Controls on a ToolBar](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-style-controls-on-a-toolbar)

[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)定义[ResourceKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcekey)对象来指定中的控件的样式[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)。 若要设置样式中的控件[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)，将`x:key`到样式属性[ResourceKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcekey)中定义[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)。

[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)定义了以下[ResourceKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcekey)对象：

- [ButtonStyleKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar.buttonstylekey)
- [CheckBoxStyleKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar.checkboxstylekey)
- [ComboBoxStyleKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar.comboboxstylekey)
- [MenuStyleKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar.menustylekey)
- [RadioButtonStyleKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar.radiobuttonstylekey)
- [SeparatorStyleKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar.separatorstylekey)
- [TextBoxStyleKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar.textboxstylekey)
- [ToggleButtonStyleKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar.togglebuttonstylekey)

### 示例

下面的示例定义内的控件的样式[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)。

```xaml
<Window.Resources>

  <!--Styles for controls in a toolbar.-->
  <Style x:Key="{x:Static ToolBar.SeparatorStyleKey}" TargetType="Separator">
    <Setter Property="Background" Value="DarkBlue"/>
    <Setter Property="Width" Value="2"/>
  </Style>

  <Style x:Key="{x:Static ToolBar.ButtonStyleKey}" TargetType="Button">
    <Setter Property="Foreground" Value="Blue"/>
    <Setter Property="FontSize" Value="14"/>
    <Setter Property="HorizontalAlignment" Value="Center"/>
    <Setter Property="VerticalAlignment" Value="Center"/>
  </Style>

  <Style x:Key="{x:Static ToolBar.CheckBoxStyleKey}" TargetType="CheckBox">
    <Setter Property="Foreground" Value="DarkSlateBlue"/>
    <Setter Property="FontSize" Value="14"/>
    <Setter Property="HorizontalAlignment" Value="Center"/>
    <Setter Property="VerticalAlignment" Value="Center"/>
  </Style>

  <Style x:Key="{x:Static ToolBar.MenuStyleKey}" TargetType="Menu">
    <Setter Property="FontSize" Value="14"/>
    <Setter Property="FontStyle" Value="Italic"/>
    <Setter Property="FontWeight" Value="Bold"/>
    <Setter Property="Background" Value="LightSteelBlue"/>
  </Style>

  <Style x:Key="{x:Static ToolBar.RadioButtonStyleKey}" TargetType="RadioButton">
    <Setter Property="Background" Value="LightSteelBlue"/>
    <Setter Property="FontSize" Value="14"/>
    <Setter Property="HorizontalAlignment" Value="Center"/>
    <Setter Property="VerticalAlignment" Value="Center"/>
  </Style>

  <Style x:Key="{x:Static ToolBar.TextBoxStyleKey}" TargetType="TextBox">
    <Setter Property="Background" Value="DarkBlue"/>
    <Setter Property="Foreground" Value="White"/>
    <Setter Property="FontSize" Value="14"/>
    <Setter Property="FontStyle" Value="Italic"/>
    <Setter Property="HorizontalAlignment" Value="Center"/>
    <Setter Property="VerticalAlignment" Value="Center"/>
    <Setter Property="Width" Value="75"/>
  </Style>

  <Style x:Key="{x:Static ToolBar.ComboBoxStyleKey}" TargetType="ComboBox">
    <Setter Property="Background" Value="LightSteelBlue"/>
    <Setter Property="FontSize" Value="14"/>
    <Setter Property="MinWidth" Value="60"/>
    <Setter Property="HorizontalAlignment" Value="Center"/>
    <Setter Property="VerticalAlignment" Value="Center"/>
  </Style>
  <!--*********Styles for controls that are not in a toolbar.*********-->
  <Style TargetType="Separator">
    <Setter Property="Background" Value="DarkBlue"/>
    <Setter Property="Width" Value="2"/>
  </Style>

  <Style TargetType="Button">
    <Setter Property="Foreground" Value="Blue"/>
    <Setter Property="FontSize" Value="14"/>
    <Setter Property="HorizontalAlignment" Value="Center"/>
    <Setter Property="VerticalAlignment" Value="Center"/>
  </Style>

  <Style TargetType="CheckBox">
    <Setter Property="Foreground" Value="DarkSlateBlue"/>
    <Setter Property="FontSize" Value="14"/>
    <Setter Property="HorizontalAlignment" Value="Center"/>
    <Setter Property="VerticalAlignment" Value="Center"/>
  </Style>

  <Style TargetType="Menu">
    <Setter Property="FontSize" Value="14"/>
    <Setter Property="FontStyle" Value="Italic"/>
    <Setter Property="FontWeight" Value="Bold"/>
    <Setter Property="Background" Value="LightSteelBlue"/>
  </Style>

  <Style TargetType="RadioButton">
    <Setter Property="Background" Value="LightSteelBlue"/>
    <Setter Property="FontSize" Value="14"/>
    <Setter Property="HorizontalAlignment" Value="Center"/>
    <Setter Property="VerticalAlignment" Value="Center"/>
  </Style>

  <Style TargetType="TextBox">
    <Setter Property="Background" Value="DarkBlue"/>
    <Setter Property="Foreground" Value="White"/>
    <Setter Property="FontSize" Value="14"/>
    <Setter Property="FontStyle" Value="Italic"/>
    <Setter Property="HorizontalAlignment" Value="Center"/>
    <Setter Property="VerticalAlignment" Value="Center"/>
    <Setter Property="Width" Value="75"/>
  </Style>

  <Style TargetType="ComboBox">
    <Setter Property="Background" Value="LightSteelBlue"/>
    <Setter Property="FontSize" Value="14"/>
    <Setter Property="MinWidth" Value="60"/>
    <Setter Property="HorizontalAlignment" Value="Center"/>
    <Setter Property="VerticalAlignment" Value="Center"/>
  </Style>
</Window.Resources>
```

```xaml
<ToolBarTray Margin="10,10,3,3" 
             Grid.Column="0" Grid.Row="2"
             Background="LightBlue">
  <ToolBar >
    <Button Content="Button 1"/>
    <Button Content="Button 2"/>
    <Separator/>
    <CheckBox Content="CheckBox 1"/>
    <CheckBox Content="CheckBox 2"/>
    <Separator/>
    <RadioButton>One</RadioButton>
    <RadioButton>Two</RadioButton>
    <Separator/>
    <ComboBox>
      <ComboBoxItem IsSelected="True">Item 1</ComboBoxItem>
      <ComboBoxItem>Item 2</ComboBoxItem>
      <ComboBoxItem>Item 3</ComboBoxItem>
      <ComboBoxItem>Item 4</ComboBoxItem>
    </ComboBox>
    <TextBox/>
    <Separator/>
    <Menu>
      <MenuItem Header="Menu">
        <MenuItem Header="File">
          <MenuItem Header="Copy"/>
          <MenuItem Header="Paste"/>
        </MenuItem>
      </MenuItem>
    </Menu>
  </ToolBar>
</ToolBarTray>
```