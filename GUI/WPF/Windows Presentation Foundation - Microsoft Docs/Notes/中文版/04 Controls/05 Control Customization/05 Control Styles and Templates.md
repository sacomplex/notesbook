# [Control Styles and Templates]https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/control-styles-and-templates)

Windows Presentation Foundation (WPF) 中的控件具有[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)，其中包含该控件的可视化树。 可以通过修改更改结构和控件的外观[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)该控件。 无法替换可视化树的控件，则只有部分若要更改必须设置一个控件的可视化树[Template](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.template)为新的完整控件属性[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。

桌面主题确定使用的资源字典。 若要为桌面主题获取资源字典，请参阅[默认的 WPF 主题](https://go.microsoft.com/fwlink/?LinkID=158252)。

下表描述了资源字典文件名及其相应的桌面主题。

| 主题文件                | 桌面主题                                                     |
| ----------------------- | ------------------------------------------------------------ |
| Classic.xaml            | Windows XP 操作系统上的经典 Windows 外观（Windows 95、Windows 98 和 Windows 2000）。 |
| Luna.NormalColor.xaml   | Windows XP 上的默认蓝色主题。                                |
| Luna.Homestead.xaml     | Windows XP 上的橄榄色主题。                                  |
| Luna.Metallic.xaml      | Windows XP 上的银色主题。                                    |
| Royale.NormalColor.xaml | Windows XP Media Center Edition 操作系统上的默认主题。       |
| Aero.NormalColor.xaml   | Windows Vista 操作系统上的默认主题。                         |

[Button 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/button-styles-and-templates)
[Calendar 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/calendar-styles-and-templates)
[CheckBox 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/checkbox-styles-and-templates)
[ComboBox 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/combobox-styles-and-templates)
[ContextMenu 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/contextmenu-styles-and-templates)
[DataGrid 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/datagrid-styles-and-templates)
[DatePicker 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/datepicker-styles-and-templates)
[DocumentViewer 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/documentviewer-styles-and-templates)
[Expander 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/expander-styles-and-templates)
[Frame 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/frame-styles-and-templates)
[GroupBox 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/groupbox-styles-and-templates)
[Label 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/label-styles-and-templates)
[ListBox 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/listbox-styles-and-templates)
[ListView 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/listview-styles-and-templates)
[Menu 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/menu-styles-and-templates)
[NavigationWindow 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/navigationwindow-styles-and-templates)
[PasswordBox 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/passwordbox-syles-and-templates)
[ProgressBar 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/progressbar-styles-and-templates)
[RadioButton 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/radiobutton-styles-and-templates)
[RepeatButton 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/repeatbutton-syles-and-templates)
[ScrollBar 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/scrollbar-styles-and-templates)
[ScrollViewer 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/scrollviewer-styles-and-templates)
[Slider 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/slider-styles-and-templates)
[StatusBar 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/statusbar-styles-and-templates)
[TabControl 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/tabcontrol-styles-and-templates)
[TextBox 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/textbox-styles-and-templates)
[Thumb 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/thumb-syles-and-templates)
[ToggleButton 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/togglebutton-syles-and-templates)
[ToolBar 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/toolbar-styles-and-templates)
[ToolTip 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/tooltip-styles-and-templates)
[TreeView 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/treeview-styles-and-templates)
[Window 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/window-styles-and-templates)

## [Button Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/button-styles-and-templates)

本主题介绍的样式和模板的[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### 按钮部件

[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)控件没有任何命名的部件。

### 按钮状态

下表列出了的可视状态[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 普通             | CommonStates          | 默认状态。                                                   |
| MouseOver        | CommonStates          | 鼠标指针悬停在控件上方。                                     |
| 已按下           | CommonStates          | 已按下控件。                                                 |
| 已禁用           | CommonStates          | 已禁用控件。                                                 |
| 已设定焦点       | FocusStates           | 控件有焦点。                                                 |
| 失去焦点         | FocusStates           | 控件没有焦点。                                               |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`和控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`和控件没有焦点。 |

### 按钮 ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)控件。

```xaml
<!-- FocusVisual -->

<Style x:Key="ButtonFocusVisual">
  <Setter Property="Control.Template">
    <Setter.Value>
      <ControlTemplate>
        <Border>
          <Rectangle Margin="2"
                     StrokeThickness="1"
                     Stroke="#60000000"
                     StrokeDashArray="1 2" />
        </Border>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<!-- Button -->
<Style TargetType="Button">
  <Setter Property="SnapsToDevicePixels"
          Value="true" />
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="FocusVisualStyle"
          Value="{StaticResource ButtonFocusVisual}" />
  <Setter Property="MinHeight"
          Value="23" />
  <Setter Property="MinWidth"
          Value="75" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="Button">
        <Border TextBlock.Foreground="{TemplateBinding Foreground}"
                x:Name="Border"
                CornerRadius="2"
                BorderThickness="1">
          <Border.BorderBrush>
            <LinearGradientBrush StartPoint="0,0"
                                 EndPoint="0,1">
              <LinearGradientBrush.GradientStops>
                <GradientStopCollection>
                  <GradientStop Color="{DynamicResource BorderLightColor}"
                                Offset="0.0" />
                  <GradientStop Color="{DynamicResource BorderDarkColor}"
                                Offset="1.0" />
                </GradientStopCollection>
              </LinearGradientBrush.GradientStops>
            </LinearGradientBrush>

          </Border.BorderBrush>
          <Border.Background>
            <LinearGradientBrush EndPoint="0.5,1"
                                 StartPoint="0.5,0">
              <GradientStop Color="{DynamicResource ControlLightColor}"
                            Offset="0" />
              <GradientStop Color="{DynamicResource ControlMediumColor}"
                            Offset="1" />
            </LinearGradientBrush>
          </Border.Background>
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="CommonStates">
              <VisualStateGroup.Transitions>
                <VisualTransition GeneratedDuration="0:0:0.5" />
                <VisualTransition GeneratedDuration="0"
                                  To="Pressed" />
              </VisualStateGroup.Transitions>
              <VisualState x:Name="Normal" />
              <VisualState x:Name="MouseOver">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetProperty="(Panel.Background).
                      (GradientBrush.GradientStops)[1].(GradientStop.Color)"
                                                Storyboard.TargetName="Border">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlMouseOverColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Pressed">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetProperty="(Panel.Background).
                      (GradientBrush.GradientStops)[1].(GradientStop.Color)"
                                                Storyboard.TargetName="Border">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlPressedColor}" />
                  </ColorAnimationUsingKeyFrames>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetProperty="(Border.BorderBrush).
                      (GradientBrush.GradientStops)[0].(GradientStop.Color)"
                                                Storyboard.TargetName="Border">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource PressedBorderDarkColor}" />
                  </ColorAnimationUsingKeyFrames>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetProperty="(Border.BorderBrush).
                      (GradientBrush.GradientStops)[1].(GradientStop.Color)"
                                                Storyboard.TargetName="Border">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource PressedBorderLightColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Disabled">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetProperty="(Panel.Background).
                      (GradientBrush.GradientStops)[1].(GradientStop.Color)"
                                                Storyboard.TargetName="Border">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource DisabledControlDarkColor}" />
                  </ColorAnimationUsingKeyFrames>
                  <ColorAnimationUsingKeyFrames
                      Storyboard.TargetProperty="(TextBlock.Foreground).(SolidColorBrush.Color)"
                                                Storyboard.TargetName="Border">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource DisabledForegroundColor}" />
                  </ColorAnimationUsingKeyFrames>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetProperty="(Border.BorderBrush).
                      (GradientBrush.GradientStops)[1].(GradientStop.Color)"
                                                Storyboard.TargetName="Border">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource DisabledBorderDarkColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <ContentPresenter Margin="2"
                            HorizontalAlignment="Center"
                            VerticalAlignment="Center"
                            RecognizesAccessKey="True" />
        </Border>
        <ControlTemplate.Triggers>
          <Trigger Property="IsDefault"
                   Value="true">

            <Setter TargetName="Border"
                    Property="BorderBrush">
              <Setter.Value>
                <LinearGradientBrush StartPoint="0,0"
                                     EndPoint="0,1">
                  <GradientBrush.GradientStops>
                    <GradientStopCollection>
                      <GradientStop Color="{DynamicResource DefaultBorderBrushLightBrush}"
                                    Offset="0.0" />
                      <GradientStop Color="{DynamicResource DefaultBorderBrushDarkColor}"
                                    Offset="1.0" />
                    </GradientStopCollection>
                  </GradientBrush.GradientStops>
                </LinearGradientBrush>

              </Setter.Value>
            </Setter>
          </Trigger>
        </ControlTemplate.Triggers>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

上一示例使用了一个或多个以下资源。

```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [Calendar Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/calendar-styles-and-templates)

本主题介绍的样式和模板的[Calendar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.calendar)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### 日历部件

下表列出了用于命名的部件[Calendar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.calendar)控件。

| 部件              | 类型                                                         | 描述                                                         |
| ----------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| PART_CalendarItem | [CalendarItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.calendaritem) | 当前显示的月份或年份上的[Calendar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.calendar)。 |
| PART_Root         | [Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel) | 面板，其中包含[CalendarItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.calendaritem)。 |

### 日历状态

下表列出了的可视状态[Calendar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.calendar)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### 日历项目部分

下表列出了用于命名的部件[CalendarItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.calendaritem)控件。

| 部件                | 类型                                                         | 描述                                                         |
| ------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| PART_Root           | [FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement) | 控件的根。                                                   |
| PART_PreviousButton | [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) | 单击它时，显示日历的前一页按钮。                             |
| PART_NextButton     | [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) | 该按钮将显示日历的下一页面时单击它。                         |
| PART_HeaderButton   | [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) | 允许在月模式、 年模式和十年模式之间切换按钮。                |
| PART_MonthView      | [Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid) | 承载在月模式下的内容。                                       |
| PART_YearView       | [Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid) | 承载在年或十年中的模式下的内容。                             |
| PART_DisabledVisual | [FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement) | 在覆盖区上为禁用状态的。                                     |
| DayTitleTemplate    | [DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate) | [DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)描述可视结构。 |

### 日历项目状态

下表列出了的可视状态[CalendarItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.calendaritem)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 正常状态         | CommonStates          | 默认状态。                                                   |
| 已禁用状态       | CommonStates          | 日历的状态时[IsEnabled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.isenabled)属性是`false`。 |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### CalendarDayButton 部件

[CalendarDayButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.calendardaybutton)控件没有任何命名的部件。

### CalendarDayButton 状态

下表列出了的可视状态[CalendarDayButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.calendardaybutton)控件。

| VisualState 名称        | VisualStateGroup 名称     | 描述                                                         |
| ----------------------- | ------------------------- | ------------------------------------------------------------ |
| 普通                    | CommonStates              | 默认状态。                                                   |
| 已禁用                  | CommonStates              | [CalendarDayButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.calendardaybutton)被禁用。 |
| MouseOver               | CommonStates              | 鼠标指针置于[CalendarDayButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.calendardaybutton)。 |
| 已按下                  | CommonStates              | [CalendarDayButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.calendardaybutton)按下。 |
| 已选定                  | SelectionStates           | 按钮处于选中状态。                                           |
| 未选定                  | SelectionStates           | 未选择该按钮。                                               |
| CalendarButtonFocused   | CalendarButtonFocusStates | 该按钮具有焦点。                                             |
| CalendarButtonUnfocused | CalendarButtonFocusStates | 该按钮不具有焦点。                                           |
| 已设定焦点              | FocusStates               | 该按钮具有焦点。                                             |
| 失去焦点                | FocusStates               | 该按钮不具有焦点。                                           |
| 活动的                  | ActiveStates              | 该按钮处于活动状态。                                         |
| 非活动状态              | ActiveStates              | 该按钮处于非活动状态。                                       |
| RegularDay              | DayStates                 | 该按钮不表示[DateTime.Today](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime.today)。 |
| 今天                    | DayStates                 | 此按钮表示[DateTime.Today](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime.today)。 |
| NormalDay               | BlackoutDayStates         | 此按钮表示可以选择一天。                                     |
| BlackoutDay             | BlackoutDayStates         | 此按钮表示不能选择一天。                                     |
| 有效                    | ValidationStates          | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused          | ValidationStates          | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused        | ValidationStates          | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### CalendarButton 部件

[CalendarButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.calendarbutton)控件没有任何命名的部件。

### CalendarButton 状态

下表列出了的可视状态[CalendarButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.calendarbutton)控件。

| VisualState 名称        | VisualStateGroup 名称     | 描述                                                         |
| ----------------------- | ------------------------- | ------------------------------------------------------------ |
| 普通                    | CommonStates              | 默认状态。                                                   |
| 已禁用                  | CommonStates              | [CalendarButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.calendarbutton)被禁用。 |
| MouseOver               | CommonStates              | 鼠标指针置于[CalendarButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.calendarbutton)。 |
| 已按下                  | CommonStates              | [CalendarButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.calendarbutton)按下。 |
| 已选定                  | SelectionStates           | 按钮处于选中状态。                                           |
| 未选定                  | SelectionStates           | 未选择该按钮。                                               |
| CalendarButtonFocused   | CalendarButtonFocusStates | 该按钮具有焦点。                                             |
| CalendarButtonUnfocused | CalendarButtonFocusStates | 该按钮不具有焦点。                                           |
| 已设定焦点              | FocusStates               | 该按钮具有焦点。                                             |
| 失去焦点                | FocusStates               | 该按钮不具有焦点。                                           |
| 活动的                  | ActiveStates              | 该按钮处于活动状态。                                         |
| 非活动状态              | ActiveStates              | 该按钮处于非活动状态。                                       |
| 有效                    | ValidationStates          | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused          | ValidationStates          | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused        | ValidationStates          | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### 日历 ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[Calendar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.calendar)控件和关联的类型。

```xaml
<!--Style for the days of a month.-->
<Style TargetType="CalendarDayButton"
       x:Key="CalendarDayButtonStyle">
  <Setter Property="MinWidth"
          Value="5" />
  <Setter Property="MinHeight"
          Value="5" />
  <Setter Property="FontSize"
          Value="10" />
  <Setter Property="HorizontalContentAlignment"
          Value="Center" />
  <Setter Property="VerticalContentAlignment"
          Value="Center" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="CalendarDayButton">
        <Grid>
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup Name="CommonStates">
              <VisualStateGroup.Transitions>
                <VisualTransition GeneratedDuration="0:0:0.1" />
              </VisualStateGroup.Transitions>
              <VisualState Name="Normal" />
              <VisualState Name="MouseOver">
                <Storyboard>
                  <DoubleAnimation Storyboard.TargetName="HighlightBackground"
                                   Storyboard.TargetProperty="Opacity"
                                   To="0.5"
                                   Duration="0" />
                </Storyboard>
              </VisualState>
              <VisualState Name="Pressed">
                <Storyboard>
                  <DoubleAnimation Storyboard.TargetName="HighlightBackground"
                                   Storyboard.TargetProperty="Opacity"
                                   To="0.5"
                                   Duration="0" />
                </Storyboard>
              </VisualState>
              <VisualState Name="Disabled">
                <Storyboard>
                  <DoubleAnimation Storyboard.TargetName="HighlightBackground"
                                   Storyboard.TargetProperty="Opacity"
                                   To="0"
                                   Duration="0" />
                  <DoubleAnimation Storyboard.TargetName="NormalText"
                                   Storyboard.TargetProperty="Opacity"
                                   To=".35"
                                   Duration="0" />
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
            <VisualStateGroup Name="SelectionStates">
              <VisualStateGroup.Transitions>
                <VisualTransition GeneratedDuration="0" />
              </VisualStateGroup.Transitions>
              <VisualState Name="Unselected" />
              <VisualState Name="Selected">
                <Storyboard>
                  <DoubleAnimation Storyboard.TargetName="SelectedBackground"
                                   Storyboard.TargetProperty="Opacity"
                                   To=".75"
                                   Duration="0" />
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
            <VisualStateGroup Name="CalendarButtonFocusStates">
              <VisualStateGroup.Transitions>
                <VisualTransition GeneratedDuration="0" />
              </VisualStateGroup.Transitions>
              <VisualState Name="CalendarButtonFocused">
                <Storyboard>
                  <ObjectAnimationUsingKeyFrames Storyboard.TargetName="DayButtonFocusVisual"
                                                 Storyboard.TargetProperty="Visibility"
                                                 Duration="0">
                    <DiscreteObjectKeyFrame KeyTime="0">
                      <DiscreteObjectKeyFrame.Value>
                        <Visibility>Visible</Visibility>
                      </DiscreteObjectKeyFrame.Value>
                    </DiscreteObjectKeyFrame>
                  </ObjectAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState Name="CalendarButtonUnfocused">
                <Storyboard>
                  <ObjectAnimationUsingKeyFrames Storyboard.TargetName="DayButtonFocusVisual"
                                                 Storyboard.TargetProperty="Visibility"
                                                 Duration="0">
                    <DiscreteObjectKeyFrame KeyTime="0">
                      <DiscreteObjectKeyFrame.Value>
                        <Visibility>Collapsed</Visibility>
                      </DiscreteObjectKeyFrame.Value>
                    </DiscreteObjectKeyFrame>
                  </ObjectAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
            <VisualStateGroup Name="ActiveStates">
              <VisualStateGroup.Transitions>
                <VisualTransition GeneratedDuration="0" />
              </VisualStateGroup.Transitions>
              <VisualState Name="Active" />
              <VisualState Name="Inactive">
                <Storyboard>
                  <ColorAnimation Duration="0"
                                  Storyboard.TargetName="NormalText"
                                  Storyboard.TargetProperty="(TextElement.Foreground).
                      (SolidColorBrush.Color)"
                                  To="#FF777777" />
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
            <VisualStateGroup Name="DayStates">
              <VisualStateGroup.Transitions>
                <VisualTransition GeneratedDuration="0" />
              </VisualStateGroup.Transitions>
              <VisualState Name="RegularDay" />
              <VisualState Name="Today">
                <Storyboard>
                  <DoubleAnimation Storyboard.TargetName="TodayBackground"
                                   Storyboard.TargetProperty="Opacity"
                                   To="1"
                                   Duration="0" />
                  <ColorAnimation Duration="0"
                                  Storyboard.TargetName="NormalText"
                                  Storyboard.TargetProperty="(TextElement.Foreground).
                      (SolidColorBrush.Color)"
                                  To="#FFFFFFFF" />
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
            <VisualStateGroup Name="BlackoutDayStates">
              <VisualStateGroup.Transitions>
                <VisualTransition GeneratedDuration="0" />
              </VisualStateGroup.Transitions>
              <VisualState Name="NormalDay" />
              <VisualState Name="BlackoutDay">
                <Storyboard>
                  <DoubleAnimation Duration="0"
                                   Storyboard.TargetName="Blackout"
                                   Storyboard.TargetProperty="Opacity"
                                   To=".2" />
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <Rectangle x:Name="TodayBackground"
                     RadiusX="1"
                     RadiusY="1"
                     Opacity="0">
            <Rectangle.Fill>
              <SolidColorBrush Color="{DynamicResource SelectedBackgroundColor}" />
            </Rectangle.Fill>
          </Rectangle>
          <Rectangle x:Name="SelectedBackground"
                     RadiusX="1"
                     RadiusY="1"
                     Opacity="0">
            <Rectangle.Fill>
              <SolidColorBrush Color="{DynamicResource SelectedBackgroundColor}" />
            </Rectangle.Fill>
          </Rectangle>
          <Border Background="{TemplateBinding Background}"
                  BorderThickness="{TemplateBinding BorderThickness}"
                  BorderBrush="{TemplateBinding BorderBrush}" />
          <Rectangle x:Name="HighlightBackground"
                     RadiusX="1"
                     RadiusY="1"
                     Opacity="0">
            <Rectangle.Fill>
              <SolidColorBrush Color="{DynamicResource ControlMouseOverColor}" />
            </Rectangle.Fill>
          </Rectangle>
          <ContentPresenter x:Name="NormalText"
                            HorizontalAlignment="{TemplateBinding HorizontalContentAlignment}"
                            VerticalAlignment="{TemplateBinding VerticalContentAlignment}"
                            Margin="5,1,5,1">
            <TextElement.Foreground>
              <SolidColorBrush Color="#FF333333" />
            </TextElement.Foreground>
          </ContentPresenter>
          <Path x:Name="Blackout"
                Opacity="0"
                Margin="3"
                HorizontalAlignment="Stretch"
                VerticalAlignment="Stretch"
                RenderTransformOrigin="0.5,0.5"
                Fill="#FF000000"
                Stretch="Fill"
                Data="M8.1772461,11.029181 L10.433105,
                  11.029181 L11.700684,12.801641 L12.973633,
                  11.029181 L15.191895,11.029181 L12.844727,
                  13.999395 L15.21875,17.060919 L12.962891,
                  17.060919 L11.673828,15.256231 L10.352539,
                  17.060919 L8.1396484,17.060919 L10.519043,
                  14.042364 z" />
          <Rectangle x:Name="DayButtonFocusVisual"
                     Visibility="Collapsed"
                     IsHitTestVisible="false"
                     RadiusX="1"
                     RadiusY="1">
            <Rectangle.Stroke>
              <SolidColorBrush Color="{DynamicResource SelectedBackgroundColor}" />
            </Rectangle.Stroke>
          </Rectangle>
        </Grid>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<!--Style for the months of a year and years of a decade.-->
<Style TargetType="CalendarButton"
       x:Key="CalendarButtonStyle">
  <Setter Property="MinWidth"
          Value="40" />
  <Setter Property="MinHeight"
          Value="42" />
  <Setter Property="FontSize"
          Value="10" />
  <Setter Property="HorizontalContentAlignment"
          Value="Center" />
  <Setter Property="VerticalContentAlignment"
          Value="Center" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="CalendarButton">
        <Grid>
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup Name="CommonStates">
              <VisualStateGroup.Transitions>
                <VisualTransition GeneratedDuration="0:0:0.1" />
              </VisualStateGroup.Transitions>
              <VisualState Name="Normal" />
              <VisualState Name="MouseOver">
                <Storyboard>
                  <DoubleAnimation Storyboard.TargetName="Background"
                                   Storyboard.TargetProperty="Opacity"
                                   To=".5"
                                   Duration="0" />
                </Storyboard>
              </VisualState>
              <VisualState Name="Pressed">
                <Storyboard>
                  <DoubleAnimation Storyboard.TargetName="Background"
                                   Storyboard.TargetProperty="Opacity"
                                   To=".5"
                                   Duration="0" />
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
            <VisualStateGroup Name="SelectionStates">
              <VisualStateGroup.Transitions>
                <VisualTransition GeneratedDuration="0" />
              </VisualStateGroup.Transitions>
              <VisualState Name="Unselected" />
              <VisualState Name="Selected">
                <Storyboard>
                  <DoubleAnimation Storyboard.TargetName="SelectedBackground"
                                   Storyboard.TargetProperty="Opacity"
                                   To=".75"
                                   Duration="0" />
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
            <VisualStateGroup Name="ActiveStates">
              <VisualStateGroup.Transitions>
                <VisualTransition GeneratedDuration="0" />
              </VisualStateGroup.Transitions>
              <VisualState Name="Active" />
              <VisualState Name="Inactive">
                <Storyboard>
                  <ColorAnimation Duration="0"
                                  Storyboard.TargetName="NormalText"
                                  Storyboard.TargetProperty="(TextElement.Foreground).
                      (SolidColorBrush.Color)"
                                  To="#FF777777" />
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
            <VisualStateGroup Name="CalendarButtonFocusStates">
              <VisualStateGroup.Transitions>
                <VisualTransition GeneratedDuration="0" />
              </VisualStateGroup.Transitions>
              <VisualState Name="CalendarButtonFocused">
                <Storyboard>
                  <ObjectAnimationUsingKeyFrames Duration="0"
                                                 Storyboard.TargetName="CalendarButtonFocusVisual"
                                                 Storyboard.TargetProperty="Visibility">
                    <DiscreteObjectKeyFrame KeyTime="0">
                      <DiscreteObjectKeyFrame.Value>
                        <Visibility>Visible</Visibility>
                      </DiscreteObjectKeyFrame.Value>
                    </DiscreteObjectKeyFrame>
                  </ObjectAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState Name="CalendarButtonUnfocused" />
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <Rectangle x:Name="SelectedBackground"
                     RadiusX="1"
                     RadiusY="1"
                     Opacity="0">
            <Rectangle.Fill>
              <SolidColorBrush Color="{DynamicResource SelectedBackgroundColor}" />
            </Rectangle.Fill>
          </Rectangle>
          <Rectangle x:Name="Background"
                     RadiusX="1"
                     RadiusY="1"
                     Opacity="0">
            <Rectangle.Fill>
              <SolidColorBrush Color="{DynamicResource SelectedBackgroundColor}" />
            </Rectangle.Fill>
          </Rectangle>
          <ContentPresenter x:Name="NormalText"
                            HorizontalAlignment="{TemplateBinding HorizontalContentAlignment}"
                            VerticalAlignment="{TemplateBinding VerticalContentAlignment}"
                            Margin="1,0,1,1">
            <TextElement.Foreground>
              <SolidColorBrush Color="#FF333333" />
            </TextElement.Foreground>
          </ContentPresenter>
          <Rectangle x:Name="CalendarButtonFocusVisual"
                     Visibility="Collapsed"
                     IsHitTestVisible="false"
                     RadiusX="1"
                     RadiusY="1">
            <Rectangle.Stroke>
              <SolidColorBrush Color="{DynamicResource SelectedBackgroundColor}" />
            </Rectangle.Stroke>
          </Rectangle>
        </Grid>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
  <Setter Property="Background">
    <Setter.Value>
      <SolidColorBrush Color="{DynamicResource ControlMediumColor}" />
    </Setter.Value>
  </Setter>
</Style>

<!--Button to go to the previous month or year.-->
<ControlTemplate x:Key="PreviousButtonTemplate"
                 TargetType="{x:Type Button}">
  <Grid Cursor="Hand">
    <VisualStateManager.VisualStateGroups>
      <VisualStateGroup x:Name="CommonStates">
        <VisualState x:Name="Normal" />
        <VisualState x:Name="MouseOver">
          <Storyboard>
            <ColorAnimation Duration="0"
                            Storyboard.TargetName="path"
                            Storyboard.TargetProperty="(Shape.Fill).(SolidColorBrush.Color)"
                            To="{DynamicResource GlyphMouseOver}" />
          </Storyboard>
        </VisualState>
        <VisualState x:Name="Disabled">
          <Storyboard>
            <DoubleAnimation Duration="0"
                             To=".5"
                             Storyboard.TargetProperty="(Shape.Fill).(Brush.Opacity)"
                             Storyboard.TargetName="path" />
          </Storyboard>
        </VisualState>
      </VisualStateGroup>
    </VisualStateManager.VisualStateGroups>
    <!--<Rectangle Fill="Transparent" Opacity="1" Stretch="Fill"/>-->
    <Grid  Background="Transparent">
      <Path x:Name="path"
            Margin="14,-6,0,0"
            Stretch="Fill"
            HorizontalAlignment="Left"
            Height="10"
            VerticalAlignment="Center"
            Width="6"
            Data="M288.75,232.25 L288.75,240.625 L283,236.625 z">
        <Path.Fill>
          <SolidColorBrush Color="{DynamicResource GlyphColor}" />
        </Path.Fill>
      </Path>
    </Grid>
  </Grid>
</ControlTemplate>

<!--Button to go to the next month or year.-->
<ControlTemplate x:Key="NextButtonTemplate"
                 TargetType="{x:Type Button}">
  <Grid Cursor="Hand">
    <VisualStateManager.VisualStateGroups>
      <VisualStateGroup x:Name="CommonStates">
        <VisualState x:Name="Normal" />
        <VisualState x:Name="MouseOver">
          <Storyboard>
            <ColorAnimation Duration="0"
                            To="{StaticResource GlyphMouseOver}"
                            Storyboard.TargetProperty="(Shape.Fill).(SolidColorBrush.Color)"
                            Storyboard.TargetName="path" />
          </Storyboard>
        </VisualState>
        <VisualState x:Name="Disabled">
          <Storyboard>
            <DoubleAnimation Duration="0"
                             To=".5"
                             Storyboard.TargetProperty="(Shape.Fill).(Brush.Opacity)"
                             Storyboard.TargetName="path" />
          </Storyboard>
        </VisualState>
      </VisualStateGroup>
    </VisualStateManager.VisualStateGroups>
    <!--<Rectangle Fill="#11E5EBF1" Opacity="1" Stretch="Fill"/>-->
    <Grid Background="Transparent">
      <Path x:Name="path"
            Data="M282.875,231.875 L282.875,240.375 L288.625,236 z"
            HorizontalAlignment="Right"
            Height="10"
            Margin="0,-6,14,0"
            Stretch="Fill"
            VerticalAlignment="Center"
            Width="6">
        <Path.Fill>
          <SolidColorBrush Color="{DynamicResource GlyphColor}" />
        </Path.Fill>
      </Path>
    </Grid>
  </Grid>
</ControlTemplate>

<!--Button to go up a level to the year or decade.-->
<ControlTemplate x:Key="HeaderButtonTemplate"
                 TargetType="{x:Type Button}">
  <Grid Cursor="Hand">
    <VisualStateManager.VisualStateGroups>
      <VisualStateGroup x:Name="CommonStates">
        <VisualState x:Name="Normal" />
        <VisualState x:Name="MouseOver">
          <Storyboard>
            <ColorAnimation Duration="0"
                            To="{DynamicResource GlyphMouseOver}"
                            Storyboard.TargetProperty="(TextElement.Foreground).
                (SolidColorBrush.Color)"
                            Storyboard.TargetName="buttonContent" />
          </Storyboard>
        </VisualState>
        <VisualState x:Name="Disabled">
          <Storyboard>
            <DoubleAnimation Duration="0"
                             To=".5"
                             Storyboard.TargetProperty="Opacity"
                             Storyboard.TargetName="buttonContent" />
          </Storyboard>
        </VisualState>
      </VisualStateGroup>
    </VisualStateManager.VisualStateGroups>
    <ContentPresenter x:Name="buttonContent"
                      Margin="1,4,1,9"
                      ContentTemplate="{TemplateBinding ContentTemplate}"
                      Content="{TemplateBinding Content}"
                      TextElement.Foreground="#FF333333"
                      HorizontalAlignment="{TemplateBinding HorizontalContentAlignment}"
                      VerticalAlignment="{TemplateBinding VerticalContentAlignment}" />
  </Grid>
</ControlTemplate>

<Style x:Key="CalendarItemStyle" TargetType="{x:Type CalendarItem}">
  <Setter Property="Margin"
          Value="0,3,0,3" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type CalendarItem}">
        <ControlTemplate.Resources>
          <DataTemplate x:Key="{x:Static CalendarItem.DayTitleTemplateResourceKey}">
            <TextBlock Foreground="#FF333333"
                       FontWeight="Bold"
                       FontSize="9.5"
                       FontFamily="Verdana"
                       Margin="0,6,0,6"
                       Text="{Binding}"
                       HorizontalAlignment="Center"
                       VerticalAlignment="Center" />
          </DataTemplate>
        </ControlTemplate.Resources>
        <Grid x:Name="PART_Root">
          <Grid.Resources>
            <SolidColorBrush x:Key="DisabledColor"
                             Color="#A5FFFFFF" />
          </Grid.Resources>
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="CommonStates">
              <VisualState x:Name="Normal" />
              <VisualState x:Name="Disabled">
                <Storyboard>
                  <DoubleAnimation Duration="0"
                                   To="1"
                                   Storyboard.TargetProperty="Opacity"
                                   Storyboard.TargetName="PART_DisabledVisual" />
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <Border BorderBrush="{TemplateBinding BorderBrush}"
                  BorderThickness="{TemplateBinding BorderThickness}"
                  Background="{TemplateBinding Background}"
                  CornerRadius="1">
            <Border BorderBrush="#FFFFFFFF"
                    BorderThickness="2"
                    CornerRadius="1">
              <Grid>
                <Grid.Resources>
                </Grid.Resources>
                <Grid.ColumnDefinitions>
                  <ColumnDefinition Width="Auto" />
                  <ColumnDefinition Width="Auto" />
                  <ColumnDefinition Width="Auto" />
                </Grid.ColumnDefinitions>
                <Grid.RowDefinitions>
                  <RowDefinition Height="Auto" />
                  <RowDefinition Height="*" />
                </Grid.RowDefinitions>
                <Button x:Name="PART_PreviousButton"
                        Template="{StaticResource PreviousButtonTemplate}"
                        Focusable="False"
                        HorizontalAlignment="Left"
                        Grid.Column="0"
                        Grid.Row="0"
                        Height="20"
                        Width="28" />
                <Button x:Name="PART_HeaderButton"
                        FontWeight="Bold"
                        Focusable="False"
                        FontSize="10.5"
                        HorizontalAlignment="Center"
                        VerticalAlignment="Center"
                        Grid.Column="1"
                        Grid.Row="0"
                        Template="{StaticResource HeaderButtonTemplate}" />
                <Button x:Name="PART_NextButton"
                        Focusable="False"
                        HorizontalAlignment="Right"
                        Grid.Column="2"
                        Grid.Row="0"
                        Template="{StaticResource NextButtonTemplate}"
                        Height="20"
                        Width="28" />
                <Grid x:Name="PART_MonthView"
                      Visibility="Visible"
                      Grid.ColumnSpan="3"
                      Grid.Row="1"
                      Margin="6,-1,6,6"
                      HorizontalAlignment="Center">
                  <Grid.ColumnDefinitions>
                    <ColumnDefinition Width="Auto" />
                    <ColumnDefinition Width="Auto" />
                    <ColumnDefinition Width="Auto" />
                    <ColumnDefinition Width="Auto" />
                    <ColumnDefinition Width="Auto" />
                    <ColumnDefinition Width="Auto" />
                    <ColumnDefinition Width="Auto" />
                  </Grid.ColumnDefinitions>
                  <Grid.RowDefinitions>
                    <RowDefinition Height="Auto" />
                    <RowDefinition Height="Auto" />
                    <RowDefinition Height="Auto" />
                    <RowDefinition Height="Auto" />
                    <RowDefinition Height="Auto" />
                    <RowDefinition Height="Auto" />
                    <RowDefinition Height="Auto" />
                  </Grid.RowDefinitions>
                </Grid>
                <Grid x:Name="PART_YearView"
                      Visibility="Hidden"
                      Grid.ColumnSpan="3"
                      Grid.Row="1"
                      HorizontalAlignment="Center"
                      Margin="6,-3,7,6">
                  <Grid.ColumnDefinitions>
                    <ColumnDefinition Width="Auto" />
                    <ColumnDefinition Width="Auto" />
                    <ColumnDefinition Width="Auto" />
                    <ColumnDefinition Width="Auto" />
                  </Grid.ColumnDefinitions>
                  <Grid.RowDefinitions>
                    <RowDefinition Height="Auto" />
                    <RowDefinition Height="Auto" />
                    <RowDefinition Height="Auto" />
                  </Grid.RowDefinitions>
                </Grid>
              </Grid>
            </Border>
          </Border>
          <Rectangle x:Name="PART_DisabledVisual"
                     Fill="{StaticResource DisabledColor}"
                     Opacity="0"
                     RadiusY="2"
                     RadiusX="2"
                     Stretch="Fill"
                     Stroke="{StaticResource DisabledColor}"
                     StrokeThickness="1"
                     Visibility="Collapsed" />
        </Grid>
        <ControlTemplate.Triggers>
          <Trigger Property="IsEnabled"
                   Value="False">
            <Setter Property="Visibility"
                    TargetName="PART_DisabledVisual"
                    Value="Visible" />
          </Trigger>
          <DataTrigger Binding="{Binding DisplayMode, 
              RelativeSource={RelativeSource FindAncestor, 
              AncestorType={x:Type Calendar}}}"
                       Value="Year">
            <Setter Property="Visibility"
                    TargetName="PART_MonthView"
                    Value="Hidden" />
            <Setter Property="Visibility"
                    TargetName="PART_YearView"
                    Value="Visible" />
          </DataTrigger>
          <DataTrigger Binding="{Binding DisplayMode, 
              RelativeSource={RelativeSource FindAncestor, 
              AncestorType={x:Type Calendar}}}"
                       Value="Decade">
            <Setter Property="Visibility"
                    TargetName="PART_MonthView"
                    Value="Hidden" />
            <Setter Property="Visibility"
                    TargetName="PART_YearView"
                    Value="Visible" />
          </DataTrigger>
        </ControlTemplate.Triggers>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<Style TargetType="{x:Type Calendar}">
  <Setter Property="CalendarButtonStyle"
          Value="{StaticResource CalendarButtonStyle}" />
  <Setter Property="CalendarDayButtonStyle"
          Value="{StaticResource CalendarDayButtonStyle}" />
  <Setter Property="CalendarItemStyle"
          Value="{StaticResource CalendarItemStyle}" />
  <Setter Property="Foreground"
          Value="#FF333333" />
  <Setter Property="Background">
    <Setter.Value>
      <LinearGradientBrush EndPoint="0.5,1"
                           StartPoint="0.5,0">

        <!--The first two gradient stops specifies the background for 
            the calendar's heading and navigation buttons.-->
        <GradientStop Color="{DynamicResource HeaderTopColor}"
                      Offset="0" />
        <GradientStop Color="{DynamicResource ControlMediumColor}"
                      Offset="0.16" />

        <!--The next gradient stop specifies the background for 
            the calendar area.-->
        <GradientStop Color="{DynamicResource ControlLightColor}"
                      Offset="0.16" />
      </LinearGradientBrush>
    </Setter.Value>
  </Setter>
  <Setter Property="BorderBrush">
    <Setter.Value>
      <LinearGradientBrush EndPoint="0,1"
                           StartPoint="0,0">
        <GradientStop Color="{DynamicResource BorderLightColor}"
                      Offset="0" />
        <GradientStop Color="{DynamicResource BorderDarkColor}"
                      Offset="1" />
      </LinearGradientBrush>
    </Setter.Value>
  </Setter>
  <Setter Property="BorderThickness"
          Value="1" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type Calendar}">
        <StackPanel x:Name="PART_Root"
                    HorizontalAlignment="Center">
          <CalendarItem x:Name="PART_CalendarItem"
                        BorderBrush="{TemplateBinding BorderBrush}"
                        BorderThickness="{TemplateBinding BorderThickness}"
                        Background="{TemplateBinding Background}"
                        Style="{TemplateBinding CalendarItemStyle}" />
        </StackPanel>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

上一示例使用了一个或多个以下资源。

```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [CheckBox Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/checkbox-styles-and-templates)

本主题介绍的样式和模板的[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### 复选框部分

[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)控件没有任何命名的部件。

### 复选框状态

下表列出了的可视状态[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 普通             | CommonStates          | 默认状态。                                                   |
| MouseOver        | CommonStates          | 鼠标指针悬停在控件上方。                                     |
| 已按下           | CommonStates          | 已按下控件。                                                 |
| 已禁用           | CommonStates          | 已禁用控件。                                                 |
| 已设定焦点       | FocusStates           | 控件有焦点。                                                 |
| 失去焦点         | FocusStates           | 控件没有焦点。                                               |
| 已选中           | CheckStates           | [IsChecked](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.togglebutton.ischecked) 为 `true`。 |
| 未选中状态       | CheckStates           | [IsChecked](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.togglebutton.ischecked) 为 `false`。 |
| 不确定           | CheckStates           | [IsThreeState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.togglebutton.isthreestate) 是`true`，并[IsChecked](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.togglebutton.ischecked)是`null`。 |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### 复选框 ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)控件。

```xaml
<Style x:Key="{x:Type CheckBox}"
       TargetType="{x:Type CheckBox}">
  <Setter Property="SnapsToDevicePixels"
          Value="true" />
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="FocusVisualStyle"
          Value="{DynamicResource CheckBoxFocusVisual}" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type CheckBox}">
        <BulletDecorator Background="Transparent">
          <BulletDecorator.Bullet>
            <Border x:Name="Border"
                    Width="13"
                    Height="13"
                    CornerRadius="0"
                    BorderThickness="1">
              <Border.BorderBrush>
                <LinearGradientBrush StartPoint="0,0"
                                     EndPoint="0,1">
                  <LinearGradientBrush.GradientStops>
                    <GradientStopCollection>
                      <GradientStop Color="{DynamicResource BorderLightColor}"
                                    Offset="0.0" />
                      <GradientStop Color="{DynamicResource BorderDarkColor}"
                                    Offset="1.0" />
                    </GradientStopCollection>
                  </LinearGradientBrush.GradientStops>
                </LinearGradientBrush>
              </Border.BorderBrush>
              <Border.Background>
                <LinearGradientBrush StartPoint="0,0"
                                     EndPoint="0,1">
                  <LinearGradientBrush.GradientStops>
                    <GradientStopCollection>
                      <GradientStop Color="{DynamicResource ControlLightColor}" />
                      <GradientStop Color="{DynamicResource ControlMediumColor}"
                                    Offset="1.0" />
                    </GradientStopCollection>
                  </LinearGradientBrush.GradientStops>
                </LinearGradientBrush>

              </Border.Background>
              <Grid>
                <Path Visibility="Collapsed"
                      Width="7"
                      Height="7"
                      x:Name="CheckMark"
                      SnapsToDevicePixels="False"
                      StrokeThickness="2"
                      Data="M 0 0 L 7 7 M 0 7 L 7 0">
                  <Path.Stroke>
                    <SolidColorBrush Color="{DynamicResource GlyphColor}" />
                  </Path.Stroke>
                </Path>
                <Path Visibility="Collapsed"
                      Width="7"
                      Height="7"
                      x:Name="InderminateMark"
                      SnapsToDevicePixels="False"
                      StrokeThickness="2"
                      Data="M 0 7 L 7 0">
                  <Path.Stroke>
                    <SolidColorBrush Color="{DynamicResource GlyphColor}" />
                  </Path.Stroke>
                </Path>
              </Grid>
            </Border>
          </BulletDecorator.Bullet>
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="CommonStates">
              <VisualState x:Name="Normal" />
              <VisualState x:Name="MouseOver">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                      (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlMouseOverColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Pressed">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                      (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlPressedColor}" />
                  </ColorAnimationUsingKeyFrames>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Border.BorderBrush).
                      (GradientBrush.GradientStops)[0].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource PressedBorderDarkColor}" />
                  </ColorAnimationUsingKeyFrames>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Border.BorderBrush).
                      (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource PressedBorderLightColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Disabled" />
            </VisualStateGroup>
            <VisualStateGroup x:Name="CheckStates">
              <VisualState x:Name="Checked">
                <Storyboard>
                  <ObjectAnimationUsingKeyFrames Storyboard.TargetProperty="(UIElement.Visibility)"
                                                 Storyboard.TargetName="CheckMark">
                    <DiscreteObjectKeyFrame KeyTime="0"
                                            Value="{x:Static Visibility.Visible}" />
                  </ObjectAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Unchecked" />
              <VisualState x:Name="Indeterminate">
                <Storyboard>
                  <ObjectAnimationUsingKeyFrames Storyboard.TargetProperty="(UIElement.Visibility)"
                                                 Storyboard.TargetName="InderminateMark">
                    <DiscreteObjectKeyFrame KeyTime="0"
                                            Value="{x:Static Visibility.Visible}" />
                  </ObjectAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <ContentPresenter Margin="4,0,0,0"
                            VerticalAlignment="Center"
                            HorizontalAlignment="Left"
                            RecognizesAccessKey="True" />
        </BulletDecorator>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

上一示例使用了一个或多个以下资源。

```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [ComboBox Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/combobox-styles-and-templates)

本主题介绍的样式和模板的[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### 组合框部分

下表列出了用于命名的部件[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)控件。

| 部件                 | 类型                                                         | 描述                                                         |
| -------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| PART_EditableTextBox | [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) | 包含文本的[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)。 |
| PART_Popup           | [Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup) | 下拉列表包含组合框中的项。                                   |

当您创建[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)有关[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)，模板可能包含[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)内[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)。 ([ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)显示在每个项[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox);[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)控件内实现滚动)。 如果[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)不是直接子级[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)，必须授予[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)名称， `ItemsPresenter`。

### 组合框的状态

下表列出了用于状态[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 普通             | CommonStates          | 默认状态。                                                   |
| 已禁用           | CommonStates          | 已禁用控件。                                                 |
| MouseOver        | CommonStates          | 鼠标指针位于[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)控件。 |
| 已设定焦点       | FocusStates           | 控件有焦点。                                                 |
| 失去焦点         | FocusStates           | 控件没有焦点。                                               |
| FocusedDropDown  | FocusStates           | 下拉列表[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)具有焦点。 |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |
| 可编辑           | EditStates            | [IsEditable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox.iseditable) 属性为 `true`。 |
| 无法编辑         | EditStates            | [IsEditable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox.iseditable) 属性为 `false`。 |

### ComboBoxItem 部件

[ComboBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.comboboxitem)控件没有任何命名的部件。

### ComboBoxItem 状态

下表列出了用于状态[ComboBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.comboboxitem)控件。

| VisualState 名称  | VisualStateGroup 名称 | 描述                                                         |
| ----------------- | --------------------- | ------------------------------------------------------------ |
| 普通              | CommonStates          | 默认状态。                                                   |
| 已禁用            | CommonStates          | 已禁用控件。                                                 |
| MouseOver         | CommonStates          | 鼠标指针位于[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)控件。 |
| 已设定焦点        | FocusStates           | 控件有焦点。                                                 |
| 失去焦点          | FocusStates           | 控件没有焦点。                                               |
| 已选定            | SelectionStates       | 当前选定项。                                                 |
| 未选定            | SelectionStates       | 未选定该项。                                                 |
| SelectedUnfocused | SelectionStates       | 该项已选定，但没有焦点。                                     |
| 有效              | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused    | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused  | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### 组合框的 ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)控件和关联的类型。

```xaml
<ControlTemplate x:Key="ComboBoxToggleButton"
                 TargetType="{x:Type ToggleButton}">
  <Grid>
    <Grid.ColumnDefinitions>
      <ColumnDefinition />
      <ColumnDefinition Width="20" />
    </Grid.ColumnDefinitions>
    <VisualStateManager.VisualStateGroups>
      <VisualStateGroup x:Name="CommonStates">
        <VisualState x:Name="Normal" />
        <VisualState x:Name="MouseOver">
          <Storyboard>
            <ColorAnimationUsingKeyFrames Storyboard.TargetProperty="(Panel.Background).
                (GradientBrush.GradientStops)[1].(GradientStop.Color)"
                                          Storyboard.TargetName="Border">
              <EasingColorKeyFrame KeyTime="0"
                                   Value="{StaticResource ControlMouseOverColor}" />
            </ColorAnimationUsingKeyFrames>
          </Storyboard>
        </VisualState>
        <VisualState x:Name="Pressed" />
        <VisualState x:Name="Disabled">
          <Storyboard>
            <ColorAnimationUsingKeyFrames Storyboard.TargetProperty="(Panel.Background).
                (GradientBrush.GradientStops)[1].(GradientStop.Color)"
                                          Storyboard.TargetName="Border">
              <EasingColorKeyFrame KeyTime="0"
                                   Value="{StaticResource DisabledControlDarkColor}" />
            </ColorAnimationUsingKeyFrames>
            <ColorAnimationUsingKeyFrames Storyboard.TargetProperty="(Shape.Fill).
                (SolidColorBrush.Color)"
                                          Storyboard.TargetName="Arrow">
              <EasingColorKeyFrame KeyTime="0"
                                   Value="{StaticResource DisabledForegroundColor}" />
            </ColorAnimationUsingKeyFrames>
            <ColorAnimationUsingKeyFrames Storyboard.TargetProperty="(Border.BorderBrush).
                (GradientBrush.GradientStops)[1].(GradientStop.Color)"
                                          Storyboard.TargetName="Border">
              <EasingColorKeyFrame KeyTime="0"
                                   Value="{StaticResource DisabledBorderDarkColor}" />
            </ColorAnimationUsingKeyFrames>
          </Storyboard>
        </VisualState>
      </VisualStateGroup>
      <VisualStateGroup x:Name="CheckStates">
        <VisualState x:Name="Checked">
          <Storyboard>
            <ColorAnimationUsingKeyFrames Storyboard.TargetProperty="(Panel.Background).
                (GradientBrush.GradientStops)[1].(GradientStop.Color)"
                                          Storyboard.TargetName="Border">
              <EasingColorKeyFrame KeyTime="0"
                                   Value="{StaticResource ControlPressedColor}" />
            </ColorAnimationUsingKeyFrames>
          </Storyboard>
        </VisualState>
        <VisualState x:Name="Unchecked" />
        <VisualState x:Name="Indeterminate" />
      </VisualStateGroup>
    </VisualStateManager.VisualStateGroups>
    <Border x:Name="Border"
            Grid.ColumnSpan="2"
            CornerRadius="2"
            BorderThickness="1">
      <Border.BorderBrush>
        <LinearGradientBrush EndPoint="0,1"
                             StartPoint="0,0">
          <GradientStop Color="{DynamicResource BorderLightColor}"
                        Offset="0" />
          <GradientStop Color="{DynamicResource BorderDarkColor}"
                        Offset="1" />
        </LinearGradientBrush>
      </Border.BorderBrush>
      <Border.Background>

        <LinearGradientBrush StartPoint="0,0"
                             EndPoint="0,1">
          <LinearGradientBrush.GradientStops>
            <GradientStopCollection>
              <GradientStop Color="{DynamicResource ControlLightColor}" />
              <GradientStop Color="{DynamicResource ControlMediumColor}"
                            Offset="1.0" />
            </GradientStopCollection>
          </LinearGradientBrush.GradientStops>
        </LinearGradientBrush>

      </Border.Background>
    </Border>
    <Border Grid.Column="0"
            CornerRadius="2,0,0,2"
            Margin="1" >
      <Border.Background>
          <SolidColorBrush Color="{DynamicResource ControlLightColor}"/>
      </Border.Background>
    </Border>
    <Path x:Name="Arrow"
          Grid.Column="1"
          HorizontalAlignment="Center"
          VerticalAlignment="Center"
          Data="M 0 0 L 4 4 L 8 0 Z" >
      <Path.Fill>
          <SolidColorBrush Color="{DynamicResource GlyphColor}"/>
      </Path.Fill>
    </Path>
  </Grid>
</ControlTemplate>

<ControlTemplate x:Key="ComboBoxTextBox"
                 TargetType="{x:Type TextBox}">
  <Border x:Name="PART_ContentHost"
          Focusable="False"
          Background="{TemplateBinding Background}" />
</ControlTemplate>

<Style x:Key="{x:Type ComboBox}"
       TargetType="{x:Type ComboBox}">
  <Setter Property="SnapsToDevicePixels"
          Value="true" />
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="ScrollViewer.HorizontalScrollBarVisibility"
          Value="Auto" />
  <Setter Property="ScrollViewer.VerticalScrollBarVisibility"
          Value="Auto" />
  <Setter Property="ScrollViewer.CanContentScroll"
          Value="true" />
  <Setter Property="MinWidth"
          Value="120" />
  <Setter Property="MinHeight"
          Value="20" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type ComboBox}">
        <Grid>
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="CommonStates">
              <VisualState x:Name="Normal" />
              <VisualState x:Name="MouseOver" />
              <VisualState x:Name="Disabled">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="PART_EditableTextBox"
                                                Storyboard.TargetProperty="(TextElement.Foreground).
                      (SolidColorBrush.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource DisabledForegroundColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
            <VisualStateGroup x:Name="EditStates">
              <VisualState x:Name="Editable">
                <Storyboard>
                  <ObjectAnimationUsingKeyFrames Storyboard.TargetProperty="(UIElement.Visibility)"
                                                 Storyboard.TargetName="PART_EditableTextBox">
                    <DiscreteObjectKeyFrame KeyTime="0"
                                            Value="{x:Static Visibility.Visible}" />
                  </ObjectAnimationUsingKeyFrames>
                  <ObjectAnimationUsingKeyFrames
                      Storyboard.TargetProperty="(UIElement.Visibility)"
                                                 Storyboard.TargetName="ContentSite">
                    <DiscreteObjectKeyFrame KeyTime="0"
                                            Value="{x:Static Visibility.Hidden}" />
                  </ObjectAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Uneditable" />
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <ToggleButton x:Name="ToggleButton"
                        Template="{StaticResource ComboBoxToggleButton}"
                        Grid.Column="2"
                        Focusable="false"
                        ClickMode="Press"
                        IsChecked="{Binding IsDropDownOpen, Mode=TwoWay, 
              RelativeSource={RelativeSource TemplatedParent}}"/>
          <ContentPresenter x:Name="ContentSite"
                            IsHitTestVisible="False"
                            Content="{TemplateBinding SelectionBoxItem}"
                            ContentTemplate="{TemplateBinding SelectionBoxItemTemplate}"
                            ContentTemplateSelector="{TemplateBinding ItemTemplateSelector}"
                            Margin="3,3,23,3"
                            VerticalAlignment="Stretch"
                            HorizontalAlignment="Left">
          </ContentPresenter>
          <TextBox x:Name="PART_EditableTextBox"
                   Style="{x:Null}"
                   Template="{StaticResource ComboBoxTextBox}"
                   HorizontalAlignment="Left"
                   VerticalAlignment="Bottom"
                   Margin="3,3,23,3"
                   Focusable="True"
                   Background="Transparent"
                   Visibility="Hidden"
                   IsReadOnly="{TemplateBinding IsReadOnly}" />
          <Popup x:Name="Popup"
                 Placement="Bottom"
                 IsOpen="{TemplateBinding IsDropDownOpen}"
                 AllowsTransparency="True"
                 Focusable="False"
                 PopupAnimation="Slide">
            <Grid x:Name="DropDown"
                  SnapsToDevicePixels="True"
                  MinWidth="{TemplateBinding ActualWidth}"
                  MaxHeight="{TemplateBinding MaxDropDownHeight}">
              <Border x:Name="DropDownBorder"
                      BorderThickness="1">
                <Border.BorderBrush>
                  <SolidColorBrush Color="{DynamicResource BorderMediumColor}" />
                </Border.BorderBrush>
                <Border.Background>
                  <SolidColorBrush Color="{DynamicResource ControlLightColor}" />
                </Border.Background>
              </Border>
              <ScrollViewer Margin="4,6,4,6"
                            SnapsToDevicePixels="True">
                <StackPanel IsItemsHost="True"
                            KeyboardNavigation.DirectionalNavigation="Contained" />
              </ScrollViewer>
            </Grid>
          </Popup>
        </Grid>
        <ControlTemplate.Triggers>
          <Trigger Property="HasItems"
                   Value="false">
            <Setter TargetName="DropDownBorder"
                    Property="MinHeight"
                    Value="95" />
          </Trigger>
          <Trigger Property="IsGrouping"
                   Value="true">
            <Setter Property="ScrollViewer.CanContentScroll"
                    Value="false" />
          </Trigger>
          <Trigger SourceName="Popup"
                   Property="AllowsTransparency"
                   Value="true">
            <Setter TargetName="DropDownBorder"
                    Property="CornerRadius"
                    Value="4" />
            <Setter TargetName="DropDownBorder"
                    Property="Margin"
                    Value="0,2,0,0" />
          </Trigger>
        </ControlTemplate.Triggers>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<Style x:Key="{x:Type ComboBoxItem}"
       TargetType="{x:Type ComboBoxItem}">
  <Setter Property="SnapsToDevicePixels"
          Value="true" />
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type ComboBoxItem}">
        <Border x:Name="Border"
                Padding="2"
                SnapsToDevicePixels="true"
                Background="Transparent">
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="SelectionStates">
              <VisualState x:Name="Unselected" />
              <VisualState x:Name="Selected">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                    (SolidColorBrush.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource SelectedBackgroundColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="SelectedUnfocused">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                    (SolidColorBrush.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource SelectedUnfocusedColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <ContentPresenter />
        </Border>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

上一示例使用了一个或多个以下资源。

```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [ContextMenu Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/contextmenu-styles-and-templates)

本主题介绍的样式和模板的[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### ContextMenu 部件

[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)控件没有任何命名的部件。

当您创建[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)有关[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)，模板可能包含[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)内[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)。 ([ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)显示在每个项[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu);[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)控件内实现滚动)。 如果[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)不是直接子级[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)，必须授予[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)名称， `ItemsPresenter`。

### ContextMenu 状态

下表列出了的可视状态[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### ContextMenu ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)控件。

```xaml
<Style TargetType="{x:Type ContextMenu}">
  <Setter Property="SnapsToDevicePixels"
          Value="True" />
  <Setter Property="OverridesDefaultStyle"
          Value="True" />
  <Setter Property="Grid.IsSharedSizeScope"
          Value="true" />
  <Setter Property="HasDropShadow"
          Value="True" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type ContextMenu}">
        <Border x:Name="Border"
                Background="{StaticResource MenuPopupBrush}"
                BorderThickness="1">
          <Border.BorderBrush>
            <SolidColorBrush Color="{StaticResource BorderMediumColor}" />
          </Border.BorderBrush>
          <StackPanel IsItemsHost="True"
                      KeyboardNavigation.DirectionalNavigation="Cycle" />
        </Border>
        <ControlTemplate.Triggers>
          <Trigger Property="HasDropShadow"
                   Value="true">
            <Setter TargetName="Border"
                    Property="Padding"
                    Value="0,3,0,3" />
            <Setter TargetName="Border"
                    Property="CornerRadius"
                    Value="4" />
          </Trigger>
        </ControlTemplate.Triggers>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)使用以下资源。

```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [DataGrid Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/datagrid-styles-and-templates)

本主题介绍的样式和模板的[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### DataGrid 部件

下表列出了用于命名的部件[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)控件。

| 部件                        | 类型                                                         | 描述             |
| --------------------------- | ------------------------------------------------------------ | ---------------- |
| PART_ColumnHeadersPresenter | [DataGridColumnHeadersPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.datagridcolumnheaderspresenter) | 包含列标题的行。 |

当您创建[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)有关[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)，模板可能包含[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)内[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)。 ([ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)显示在每个项[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid);[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)控件内实现滚动)。 如果[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)不是直接子级[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)，必须授予[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)名称， `ItemsPresenter`。

默认模板[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)包含[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)控件。 有关定义的部件的详细信息[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)，请参阅[ScrollViewer 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/scrollviewer-styles-and-templates)。

### 数据网格状态

下表列出了的可视状态[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                     |
| ---------------- | --------------------- | ------------------------ |
| 普通             | CommonStates          | 默认状态。               |
| 已禁用           | CommonStates          | 已禁用控件。             |
| InvalidFocused   | ValidationStates      | 控件无效，但具有焦点。   |
| InvalidUnfocused | ValidationStates      | 控件无效，并且没有焦点。 |
| 有效             | ValidationStates      | 控件有效。               |

### DataGridCell 部件

[DataGridCell](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridcell)元素不具有任何命名的部件。

### DataGridCell 状态

下表列出了的可视状态[DataGridCell](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridcell)元素。

| VisualState 名称 | VisualStateGroup 名称 | 描述                       |
| ---------------- | --------------------- | -------------------------- |
| 普通             | CommonStates          | 默认状态。                 |
| MouseOver        | CommonStates          | 鼠标指针置于单元格。       |
| 已设定焦点       | FocusStates           | 该单元格有焦点。           |
| 失去焦点         | FocusStates           | 该单元格不具有焦点         |
| 当前             | CurrentStates         | 该单元格是当前单元格。     |
| 规则             | CurrentStates         | 该单元格不是当前单元格。   |
| 显示             | InteractionStates     | 该单元格位于显示模式。     |
| 编辑             | InteractionStates     | 该单元格处于编辑模式。     |
| 已选定           | SelectionStates       | 选定该单元格。             |
| 未选定           | SelectionStates       | 未选择该单元格。           |
| InvalidFocused   | ValidationStates      | 该单元格无效，且具有焦点。 |
| InvalidUnfocused | ValidationStates      | 该单元格无效，不具有焦点。 |
| 有效             | ValidationStates      | 该单元格是有效的。         |

### DataGridRow 部件

[DataGridRow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridrow)元素不具有任何命名的部件。

### DataGridRow 状态

下表列出了的可视状态[DataGridRow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridrow)元素。

| VisualState 名称             | VisualStateGroup 名称 | 描述                                              |
| ---------------------------- | --------------------- | ------------------------------------------------- |
| 普通                         | CommonStates          | 默认状态。                                        |
| MouseOver                    | CommonStates          | 鼠标指针置于行。                                  |
| MouseOver_Editing            | CommonStates          | 鼠标指针置于行和行处于编辑模式。                  |
| MouseOver_Selected           | CommonStates          | 鼠标指针置于该行并选择的行。                      |
| MouseOver_Unfocused_Editing  | CommonStates          | 鼠标指针置于行、 行处于编辑模式，并且不具有焦点。 |
| MouseOver_Unfocused_Selected | CommonStates          | 鼠标指针置于行，行选择，则并不具有焦点。          |
| Normal_AlternatingRow        | CommonStates          | 行是交替行。                                      |
| Normal_Editing               | CommonStates          | 行处于编辑模式。                                  |
| Normal_Selected              | CommonStates          | 选择的行。                                        |
| Unfocused_Editing            | CommonStates          | 行处于编辑模式并不具有焦点。                      |
| Unfocused_Selected           | CommonStates          | 行处于选中状态，并且不具有焦点。                  |
| InvalidFocused               | ValidationStates      | 控件无效，但具有焦点。                            |
| InvalidUnfocused             | ValidationStates      | 控件无效，并且没有焦点。                          |
| 有效                         | ValidationStates      | 控件有效。                                        |

### DataGridRowHeader 部件

下表列出了用于命名的部件[DataGridRowHeader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.datagridrowheader)元素。

| 部件                     | 类型                                                         | 描述                             |
| ------------------------ | ------------------------------------------------------------ | -------------------------------- |
| PART_TopHeaderGripper    | [Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb) | 用于调整行标题顶部的元素。       |
| PART_BottomHeaderGripper | [Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb) | 用于调整大小从底部的行标头元素。 |

### DataGridRowHeader 状态

下表列出了的可视状态[DataGridRowHeader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.datagridrowheader)元素。

| VisualState 名称                        | VisualStateGroup 名称 | 描述                                              |
| --------------------------------------- | --------------------- | ------------------------------------------------- |
| 普通                                    | CommonStates          | 默认状态。                                        |
| MouseOver                               | CommonStates          | 鼠标指针置于行。                                  |
| MouseOver_CurrentRow                    | CommonStates          | 鼠标指针定位的行，该行是当前行。                  |
| MouseOver_CurrentRow_Selected           | CommonStates          | 鼠标指针置于行，并且行是当前和所选。              |
| MouseOver_EditingRow                    | CommonStates          | 鼠标指针置于行和行处于编辑模式。                  |
| MouseOver_Selected                      | CommonStates          | 鼠标指针置于该行并选择的行。                      |
| MouseOver_Unfocused_CurrentRow_Selected | CommonStates          | 鼠标指针置于一行，该行当前和选择，并不具有焦点。  |
| MouseOver_Unfocused_EditingRow          | CommonStates          | 鼠标指针置于行、 行处于编辑模式，并且不具有焦点。 |
| MouseOver_Unfocused_Selected            | CommonStates          | 鼠标指针置于行，行选择，则并不具有焦点。          |
| Normal_CurrentRow                       | CommonStates          | 行是当前行。                                      |
| Normal_CurrentRow_Selected              | CommonStates          | 行是当前行，并且处于选中状态。                    |
| Normal_EditingRow                       | CommonStates          | 行处于编辑模式。                                  |
| Normal_Selected                         | CommonStates          | 选择的行。                                        |
| Unfocused_CurrentRow_Selected           | CommonStates          | 行是当前行，被选定，并且不具有焦点。              |
| Unfocused_EditingRow                    | CommonStates          | 行处于编辑模式并不具有焦点。                      |
| Unfocused_Selected                      | CommonStates          | 行处于选中状态，并且不具有焦点。                  |
| InvalidFocused                          | ValidationStates      | 控件无效，但具有焦点。                            |
| InvalidUnfocused                        | ValidationStates      | 控件无效，并且没有焦点。                          |
| 有效                                    | ValidationStates      | 控件有效。                                        |

### DataGridColumnHeadersPresenter 部件

下表列出了用于命名的部件[DataGridColumnHeadersPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.datagridcolumnheaderspresenter)元素。

| 部件                    | 类型                                                         | 描述             |
| ----------------------- | ------------------------------------------------------------ | ---------------- |
| PART_FillerColumnHeader | [DataGridColumnHeader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.datagridcolumnheader) | 列标题的占位符。 |

### DataGridColumnHeadersPresenter States

下表列出了的可视状态[DataGridColumnHeadersPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.datagridcolumnheaderspresenter)元素。

| VisualState 名称 | VisualStateGroup 名称 | 描述                       |
| ---------------- | --------------------- | -------------------------- |
| InvalidFocused   | ValidationStates      | 该单元格无效，且具有焦点。 |
| InvalidUnfocused | ValidationStates      | 该单元格无效，不具有焦点。 |
| 有效             | ValidationStates      | 该单元格是有效的。         |

### DataGridColumnHeader 部件

下表列出了用于命名的部件[DataGridColumnHeader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.datagridcolumnheader)元素。

| 部件                    | 类型                                                         | 描述                             |
| ----------------------- | ------------------------------------------------------------ | -------------------------------- |
| PART_LeftHeaderGripper  | [Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb) | 用于调整大小从左侧的列标题元素。 |
| PART_RightHeaderGripper | [Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb) | 用于调整大小从右侧的列标题元素。 |

### DataGridColumnHeader 状态

下表列出了的可视状态[DataGridColumnHeader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.datagridcolumnheader)元素。

| VisualState 名称 | VisualStateGroup 名称 | 描述                     |
| ---------------- | --------------------- | ------------------------ |
| 普通             | CommonStates          | 默认状态。               |
| MouseOver        | CommonStates          | 鼠标指针悬停在控件上方。 |
| 已按下           | CommonStates          | 已按下控件。             |
| SortAscending    | SortStates            | 对列按升序进行排序。     |
| SortDescending   | SortStates            | 对列进行降序排序。       |
| 未排序           | SortStates            | 未对列进行排序。         |
| InvalidFocused   | ValidationStates      | 控件无效，但具有焦点。   |
| InvalidUnfocused | ValidationStates      | 控件无效，并且没有焦点。 |
| 有效             | ValidationStates      | 控件有效。               |

### DataGrid ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)控件和其关联的类型。

```xaml
<BooleanToVisibilityConverter x:Key="bool2VisibilityConverter" />

<!--Style and template for the button in the upper left corner of the DataGrid.-->
<Style TargetType="{x:Type Button}"
       x:Key="{ComponentResourceKey ResourceId=DataGridSelectAllButtonStyle, 
  TypeInTargetAssembly={x:Type DataGrid}}">
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type Button}">
        <Grid>
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="CommonStates">
              <VisualState x:Name="Normal" />
              <VisualState x:Name="MouseOver">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Shape.Fill).
                      (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlMouseOverColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Pressed">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Shape.Fill).
                      (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlPressedColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Disabled">
                <Storyboard>
                  <ObjectAnimationUsingKeyFrames Storyboard.TargetProperty="(UIElement.Visibility)"
                                                 Storyboard.TargetName="Arrow">
                    <DiscreteObjectKeyFrame KeyTime="0"
                                            Value="{x:Static Visibility.Collapsed}" />
                  </ObjectAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <Rectangle x:Name="Border"
                     SnapsToDevicePixels="True">
            <Rectangle.Stroke>
              <LinearGradientBrush EndPoint="0.5,1"
                                   StartPoint="0.5,0">
                <GradientStop Color="{DynamicResource BorderLightColor}"
                              Offset="0" />
                <GradientStop Color="{DynamicResource BorderMediumColor}"
                              Offset="1" />
              </LinearGradientBrush>
            </Rectangle.Stroke>
            <Rectangle.Fill>
              <LinearGradientBrush EndPoint="0.5,1"
                                   StartPoint="0.5,0">
                <GradientStop Color="{DynamicResource ControlLightColor}"
                              Offset="0" />
                <GradientStop Color="{DynamicResource ControlMediumColor}"
                              Offset="1" />
              </LinearGradientBrush>
            </Rectangle.Fill>
          </Rectangle>
          <Polygon x:Name="Arrow"
                   HorizontalAlignment="Right"
                   Margin="8,8,3,3"
                   Opacity="0.15"
                   Points="0,10 10,10 10,0"
                   Stretch="Uniform"
                   VerticalAlignment="Bottom">
            <Polygon.Fill>
              <SolidColorBrush Color="{DynamicResource GlyphColor}" />
            </Polygon.Fill>
          </Polygon>
        </Grid>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<!--Style and template for the DataGrid.-->
<Style TargetType="{x:Type DataGrid}">
  <Setter Property="Foreground"
          Value="{DynamicResource {x:Static SystemColors.ControlTextBrushKey}}" />
  <Setter Property="BorderBrush">
    <Setter.Value>
      <LinearGradientBrush EndPoint="0.5,1"
                           StartPoint="0.5,0">
        <GradientStop Color="{DynamicResource BorderLightColor}"
                      Offset="0" />
        <GradientStop Color="{DynamicResource BorderDarkColor}"
                      Offset="1" />
      </LinearGradientBrush>
    </Setter.Value>
  </Setter>
  <Setter Property="BorderThickness"
          Value="1" />
  <Setter Property="RowDetailsVisibilityMode"
          Value="VisibleWhenSelected" />
  <Setter Property="ScrollViewer.CanContentScroll"
          Value="true" />
  <Setter Property="ScrollViewer.PanningMode"
          Value="Both" />
  <Setter Property="Stylus.IsFlicksEnabled"
          Value="False" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type DataGrid}">
        <Border x:Name="border"
                SnapsToDevicePixels="True"
                BorderBrush="{TemplateBinding BorderBrush}"
                BorderThickness="{TemplateBinding BorderThickness}"
                Padding="{TemplateBinding Padding}">
          <Border.Background>
            <SolidColorBrush Color="{DynamicResource ControlLightColor}" />
          </Border.Background>
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="CommonStates">
              <VisualState x:Name="Disabled">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="border"
                                                Storyboard.TargetProperty="(Panel.Background).
                      (SolidColorBrush.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{DynamicResource ControlLightColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Normal" />
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <ScrollViewer x:Name="DG_ScrollViewer"
                        Focusable="false"
                        Background="Black">
            <ScrollViewer.Template>
              <ControlTemplate TargetType="{x:Type ScrollViewer}">
                <Grid>
                  <Grid.ColumnDefinitions>
                    <ColumnDefinition Width="Auto" />
                    <ColumnDefinition Width="*" />
                    <ColumnDefinition Width="Auto" />
                  </Grid.ColumnDefinitions>
                  <Grid.RowDefinitions>
                    <RowDefinition Height="Auto" />
                    <RowDefinition Height="*" />
                    <RowDefinition Height="Auto" />
                  </Grid.RowDefinitions>

                  <Button Focusable="false"
                          Command="{x:Static DataGrid.SelectAllCommand}"
                          Style="{DynamicResource {ComponentResourceKey 
                      ResourceId=DataGridSelectAllButtonStyle, 
                      TypeInTargetAssembly={x:Type DataGrid}}}"
                          Visibility="{Binding HeadersVisibility, 
                      ConverterParameter={x:Static DataGridHeadersVisibility.All}, 
                      Converter={x:Static DataGrid.HeadersVisibilityConverter}, 
                      RelativeSource={RelativeSource AncestorType={x:Type DataGrid}}}"
                          Width="{Binding CellsPanelHorizontalOffset, 
                      RelativeSource={RelativeSource AncestorType={x:Type DataGrid}}}" />

                  <DataGridColumnHeadersPresenter x:Name="PART_ColumnHeadersPresenter"
                                                  Grid.Column="1"
                                                  Visibility="{Binding HeadersVisibility, 
                      ConverterParameter={x:Static DataGridHeadersVisibility.Column}, 
                      Converter={x:Static DataGrid.HeadersVisibilityConverter}, 
                      RelativeSource={RelativeSource AncestorType={x:Type DataGrid}}}" />

                  <ScrollContentPresenter x:Name="PART_ScrollContentPresenter"
                                          Grid.ColumnSpan="2"
                                          Grid.Row="1"
                                          CanContentScroll="{TemplateBinding CanContentScroll}" />

                  <ScrollBar x:Name="PART_VerticalScrollBar"
                             Grid.Column="2"
                             Grid.Row="1"
                             Orientation="Vertical"
                             ViewportSize="{TemplateBinding ViewportHeight}"
                             Maximum="{TemplateBinding ScrollableHeight}"
                             Visibility="{TemplateBinding ComputedVerticalScrollBarVisibility}"
                             Value="{Binding VerticalOffset, Mode=OneWay, 
                      RelativeSource={RelativeSource TemplatedParent}}"/>

                  <Grid Grid.Column="1"
                        Grid.Row="2">
                    <Grid.ColumnDefinitions>
                      <ColumnDefinition Width="{Binding NonFrozenColumnsViewportHorizontalOffset, 
                          RelativeSource={RelativeSource AncestorType={x:Type DataGrid}}}" />
                      <ColumnDefinition Width="*" />
                    </Grid.ColumnDefinitions>

                    <ScrollBar x:Name="PART_HorizontalScrollBar"
                               Grid.Column="1"
                               Orientation="Horizontal"
                               ViewportSize="{TemplateBinding ViewportWidth}"
                               Maximum="{TemplateBinding ScrollableWidth}"
                               Visibility="{TemplateBinding ComputedHorizontalScrollBarVisibility}"
                               Value="{Binding HorizontalOffset, Mode=OneWay, 
                        RelativeSource={RelativeSource TemplatedParent}}"/>
                  </Grid>
                </Grid>
              </ControlTemplate>
            </ScrollViewer.Template>
            <ItemsPresenter SnapsToDevicePixels="{TemplateBinding SnapsToDevicePixels}" />
          </ScrollViewer>
        </Border>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
  <Style.Triggers>
    <Trigger Property="IsGrouping"
             Value="true">
      <Setter Property="ScrollViewer.CanContentScroll"
              Value="false" />
    </Trigger>
  </Style.Triggers>
</Style>

<!--Style and template for the DataGridCell.-->
<Style TargetType="{x:Type DataGridCell}">
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type DataGridCell}">
        <Border x:Name="border"
                BorderBrush="Transparent"
                BorderThickness="1"
                Background="Transparent"
                SnapsToDevicePixels="True">
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="FocusStates">
              <VisualState x:Name="Unfocused" />
              <VisualState x:Name="Focused" />
            </VisualStateGroup>
            <VisualStateGroup x:Name="CurrentStates">
              <VisualState x:Name="Regular" />
              <VisualState x:Name="Current">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="border"
                                                Storyboard.TargetProperty="(Border.BorderBrush).
                      (SolidColorBrush.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource DatagridCurrentCellBorderColor}" />
                  </ColorAnimationUsingKeyFrames
                                                >
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <ContentPresenter SnapsToDevicePixels="{TemplateBinding SnapsToDevicePixels}" />
        </Border>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<!--Style and template for the DataGridRow.-->
<Style TargetType="{x:Type DataGridRow}">
  <Setter Property="Background">
    <Setter.Value>
      <SolidColorBrush Color="{DynamicResource ControlLightColor}" />
    </Setter.Value>
  </Setter>
  <Setter Property="SnapsToDevicePixels"
          Value="true" />
  <Setter Property="Validation.ErrorTemplate"
          Value="{x:Null}" />
  <Setter Property="ValidationErrorTemplate">
    <Setter.Value>
      <ControlTemplate>
        <TextBlock Foreground="Red"
                   Margin="2,0,0,0"
                   Text="!"
                   VerticalAlignment="Center" />
      </ControlTemplate>
    </Setter.Value>
  </Setter>
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type DataGridRow}">
        <Border x:Name="DGR_Border"
                BorderBrush="{TemplateBinding BorderBrush}"
                BorderThickness="{TemplateBinding BorderThickness}"
                SnapsToDevicePixels="True">
          <Border.Background>
            <LinearGradientBrush EndPoint="0.5,1"
                                 StartPoint="0.5,0">
              <GradientStop Color="Transparent"
                            Offset="0" />
              <GradientStop Color="{DynamicResource ControlLightColor}"
                            Offset="1" />
            </LinearGradientBrush>
          </Border.Background>
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="CommonStates">
              <VisualState x:Name="Normal" />

              <!--Provide a different appearance for every other row.-->
              <VisualState x:Name="Normal_AlternatingRow">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="DGR_Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                      (GradientBrush.GradientStops)[0].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ContentAreaColorLight}" />
                  </ColorAnimationUsingKeyFrames>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="DGR_Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                      (GradientBrush.GradientStops)[1].(GradientStop.Color)">

                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ContentAreaColorDark}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>

              <!--In this example, a row in Editing or selected mode has an
              identical appearances. In other words, the states 
              Normal_Selected, Unfocused_Selected, Normal_Editing, 
              MouseOver_Editing, MouseOver_Unfocused_Editing,
              and Unfocused_Editing are identical.-->
              <VisualState x:Name="Normal_Selected">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="DGR_Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                      (GradientBrush.GradientStops)[0].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlMediumColor}" />
                  </ColorAnimationUsingKeyFrames>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="DGR_Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                      (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlDarkColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>

              <VisualState x:Name="Unfocused_Selected">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="DGR_Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                      (GradientBrush.GradientStops)[0].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlMediumColor}" />
                  </ColorAnimationUsingKeyFrames>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="DGR_Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                      (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlDarkColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>

              <VisualState x:Name="Normal_Editing">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="DGR_Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                      (GradientBrush.GradientStops)[0].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlMediumColor}" />
                  </ColorAnimationUsingKeyFrames>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="DGR_Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                      (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlDarkColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>

              <VisualState x:Name="MouseOver_Editing">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="DGR_Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                      (GradientBrush.GradientStops)[0].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlMediumColor}" />
                  </ColorAnimationUsingKeyFrames>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="DGR_Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                      (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlDarkColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>

              <VisualState x:Name="MouseOver_Unfocused_Editing">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="DGR_Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                      (GradientBrush.GradientStops)[0].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlMediumColor}" />
                  </ColorAnimationUsingKeyFrames>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="DGR_Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                      (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlDarkColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>

              <VisualState x:Name="Unfocused_Editing">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="DGR_Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                      (GradientBrush.GradientStops)[0].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlMediumColor}" />
                  </ColorAnimationUsingKeyFrames>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="DGR_Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                      (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlDarkColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>

              <VisualState x:Name="MouseOver">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="DGR_Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                      (GradientBrush.GradientStops)[0].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlMediumColor}" />
                  </ColorAnimationUsingKeyFrames>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="DGR_Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                      (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlMouseOverColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>

              <!--In this example, the appearance of a selected row 
              that has the mouse over it is the same regardless of
              whether the row is selected.  In other words, the states 
              MouseOver_Editing and MouseOver_Unfocused_Editing are identical.-->
              <VisualState x:Name="MouseOver_Selected">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="DGR_Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                      (GradientBrush.GradientStops)[0].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlMouseOverColor}" />
                  </ColorAnimationUsingKeyFrames>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="DGR_Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                      (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlMouseOverColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>

              <VisualState x:Name="MouseOver_Unfocused_Selected">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="DGR_Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                      (GradientBrush.GradientStops)[0].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlMouseOverColor}" />
                  </ColorAnimationUsingKeyFrames>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="DGR_Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                      (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlMouseOverColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>

          <SelectiveScrollingGrid>
            <SelectiveScrollingGrid.ColumnDefinitions>
              <ColumnDefinition Width="Auto" />
              <ColumnDefinition Width="*" />
            </SelectiveScrollingGrid.ColumnDefinitions>
            <SelectiveScrollingGrid.RowDefinitions>
              <RowDefinition Height="*" />
              <RowDefinition Height="Auto" />
            </SelectiveScrollingGrid.RowDefinitions>
            <DataGridCellsPresenter Grid.Column="1"
                                    ItemsPanel="{TemplateBinding ItemsPanel}"
                                    SnapsToDevicePixels="{TemplateBinding SnapsToDevicePixels}" />
            <DataGridDetailsPresenter Grid.Column="1"
                                      Grid.Row="1"
                                      Visibility="{TemplateBinding DetailsVisibility}"
                                      SelectiveScrollingGrid.SelectiveScrollingOrientation=
                "{Binding AreRowDetailsFrozen, 
                ConverterParameter={x:Static SelectiveScrollingOrientation.Vertical},
                Converter={x:Static DataGrid.RowDetailsScrollingConverter}, 
                RelativeSource={RelativeSource AncestorType={x:Type DataGrid}}}"/>
            <DataGridRowHeader Grid.RowSpan="2"
                               SelectiveScrollingGrid.SelectiveScrollingOrientation="Vertical"
                               Visibility="{Binding HeadersVisibility, 
                ConverterParameter={x:Static DataGridHeadersVisibility.Row}, 
                Converter={x:Static DataGrid.HeadersVisibilityConverter}, 
                RelativeSource={RelativeSource AncestorType={x:Type DataGrid}}}" />
          </SelectiveScrollingGrid>
        </Border>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<!--Style and template for the resize control on the DataGridRowHeader.-->
<Style x:Key="RowHeaderGripperStyle"
       TargetType="{x:Type Thumb}">
  <Setter Property="Height"
          Value="8" />
  <Setter Property="Background"
          Value="Transparent" />
  <Setter Property="Cursor"
          Value="SizeNS" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type Thumb}">
        <Border Background="{TemplateBinding Background}"
                Padding="{TemplateBinding Padding}" />
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<!--Style and template for the DataGridRowHeader.-->
<Style TargetType="{x:Type DataGridRowHeader}">
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type DataGridRowHeader}">
        <Grid>
          <VisualStateManager.VisualStateGroups>
            <!--This example does not specify an appearance for every
                state.  You can add storyboard to the states that are listed
                to change the appearance of the DataGridRowHeader when it is
                in a specific state.-->
            <VisualStateGroup x:Name="CommonStates">
              <VisualState x:Name="Normal" />
              <VisualState x:Name="Normal_CurrentRow" />
              <VisualState x:Name="Unfocused_EditingRow" />
              <VisualState x:Name="Normal_EditingRow" />
              <VisualState x:Name="MouseOver">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="rowHeaderBorder"
                                                Storyboard.TargetProperty="(Panel.Background).
                      (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlMouseOverColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="MouseOver_CurrentRow" />
              <VisualState x:Name="MouseOver_Unfocused_EditingRow" />
              <VisualState x:Name="MouseOver_EditingRow" />
              <VisualState x:Name="MouseOver_Unfocused_Selected" />
              <VisualState x:Name="MouseOver_Selected" />
              <VisualState x:Name="MouseOver_Unfocused_CurrentRow_Selected" />
              <VisualState x:Name="MouseOver_CurrentRow_Selected" />
              <VisualState x:Name="Unfocused_Selected" />
              <VisualState x:Name="Unfocused_CurrentRow_Selected" />
              <VisualState x:Name="Normal_CurrentRow_Selected" />
              <VisualState x:Name="Normal_Selected" />
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <Border x:Name="rowHeaderBorder"
                  Width="10"
                  BorderThickness="1">
            <Border.BorderBrush>
              <LinearGradientBrush EndPoint="0.5,1"
                                   StartPoint="0.5,0">
                <GradientStop Color="{DynamicResource BorderLightColor}"
                              Offset="0" />
                <GradientStop Color="{DynamicResource BorderDarkColor}"
                              Offset="1" />
              </LinearGradientBrush>
            </Border.BorderBrush>
            <Border.Background>
              <LinearGradientBrush EndPoint="0.5,1"
                                   StartPoint="0.5,0">
                <GradientStop Color="{DynamicResource ControlLightColor}"
                              Offset="0" />
                <GradientStop Color="{DynamicResource ControlMediumColor}"
                              Offset="1" />
              </LinearGradientBrush>
            </Border.Background>
            <StackPanel Orientation="Horizontal">
              <ContentPresenter VerticalAlignment="Center"
                                SnapsToDevicePixels="{TemplateBinding SnapsToDevicePixels}" />
              <Control SnapsToDevicePixels="false"
                       Template="{Binding ValidationErrorTemplate, 
                  RelativeSource={RelativeSource AncestorType={x:Type DataGridRow}}}"
                       Visibility="{Binding (Validation.HasError), 
                  Converter={StaticResource bool2VisibilityConverter}, 
                  RelativeSource={RelativeSource AncestorType={x:Type DataGridRow}}}" />
            </StackPanel>
          </Border>

          <Thumb x:Name="PART_TopHeaderGripper"
                 Style="{StaticResource RowHeaderGripperStyle}"
                 VerticalAlignment="Top" />
          <Thumb x:Name="PART_BottomHeaderGripper"
                 Style="{StaticResource RowHeaderGripperStyle}"
                 VerticalAlignment="Bottom" />
        </Grid>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<!--Style and template for the resize control on the DataGridColumnHeader.-->
<Style x:Key="ColumnHeaderGripperStyle"
       TargetType="{x:Type Thumb}">
  <Setter Property="Width"
          Value="8" />
  <Setter Property="Background"
          Value="Transparent" />
  <Setter Property="Cursor"
          Value="SizeWE" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type Thumb}">
        <Border Background="{TemplateBinding Background}"
                Padding="{TemplateBinding Padding}" />
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<!--Style and template for the DataGridColumnHeader.-->
<Style TargetType="{x:Type DataGridColumnHeader}">
  <Setter Property="VerticalContentAlignment"
          Value="Center" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type DataGridColumnHeader}">
        <Grid>
          <Border x:Name="columnHeaderBorder"
                  BorderThickness="1"
                  Padding="3,0,3,0">
            <Border.BorderBrush>
              <LinearGradientBrush EndPoint="0.5,1"
                                   StartPoint="0.5,0">
                <GradientStop Color="{DynamicResource BorderLightColor}"
                              Offset="0" />
                <GradientStop Color="{DynamicResource BorderDarkColor}"
                              Offset="1" />
              </LinearGradientBrush>
            </Border.BorderBrush>
            <Border.Background>
              <LinearGradientBrush EndPoint="0.5,1"
                                   StartPoint="0.5,0">
                <GradientStop Color="{DynamicResource ControlLightColor}"
                              Offset="0" />
                <GradientStop Color="{DynamicResource ControlMediumColor}"
                              Offset="1" />
              </LinearGradientBrush>
            </Border.Background>
            <ContentPresenter HorizontalAlignment="{TemplateBinding HorizontalContentAlignment}"
                              SnapsToDevicePixels="{TemplateBinding SnapsToDevicePixels}"
                              VerticalAlignment="{TemplateBinding VerticalContentAlignment}" />
          </Border>

          <Thumb x:Name="PART_LeftHeaderGripper"
                 HorizontalAlignment="Left"
                 Style="{StaticResource ColumnHeaderGripperStyle}" />
          <Thumb x:Name="PART_RightHeaderGripper"
                 HorizontalAlignment="Right"
                 Style="{StaticResource ColumnHeaderGripperStyle}" />
        </Grid>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
  <Setter Property="Background">
    <Setter.Value>
      <LinearGradientBrush EndPoint="0.5,1"
                           StartPoint="0.5,0">
        <GradientStop Color="{DynamicResource ControlLightColor}"
                      Offset="0" />
        <GradientStop Color="{DynamicResource ControlMediumColor}"
                      Offset="1" />
      </LinearGradientBrush>
    </Setter.Value>
  </Setter>
</Style>

<!--Style and template for the DataGridColumnHeadersPresenter.-->
<Style TargetType="{x:Type DataGridColumnHeadersPresenter}">
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type DataGridColumnHeadersPresenter}">
        <Grid>
          <DataGridColumnHeader x:Name="PART_FillerColumnHeader"
                                IsHitTestVisible="False" />
          <ItemsPresenter />
        </Grid>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

上一示例使用了一个或多个以下资源。



```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [DatePicker Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/datepicker-styles-and-templates)

本主题介绍的样式和模板的[DatePicker](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datepicker)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### DatePicker 部件

下表列出了用于命名的部件[DatePicker](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datepicker)控件。

| 部件         | 类型                                                         | 描述                                                         |
| ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| PART_Root    | [Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid) | 控件的根。                                                   |
| PART_Button  | [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) | 打开和关闭按钮[Calendar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.calendar)。 |
| PART_TextBox | [DatePickerTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.datepickertextbox) | 使您能够输入日期的文本框。                                   |
| PART_Popup   | [Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup) | 为 popup[DatePicker](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datepicker)控件。 |

### DatePicker 状态

下表列出了的可视状态[DatePicker](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datepicker)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 普通             | CommonStates          | 默认状态。                                                   |
| 已禁用           | CommonStates          | [DatePicker](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datepicker)被禁用。 |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### DatePickerTextBox 部件

下表列出了用于命名的部件[DatePickerTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.datepickertextbox)控件。

| 部件                | 类型                                                         | 描述                                                         |
| ------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| PART_Watermark      | [ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol) | 包含中的初始文本的元素[DatePicker](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datepicker)。 |
| PART_ContentElement | [FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement) | 可以包含一个可见元素[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)。 文本[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)显示在此元素。 |

### DatePickerTextBox 状态

下表列出了的可视状态[DatePickerTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.datepickertextbox)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 普通             | CommonStates          | 默认状态。                                                   |
| 已禁用           | CommonStates          | [DatePickerTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.datepickertextbox)被禁用。 |
| MouseOver        | CommonStates          | 鼠标指针置于[DatePickerTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.datepickertextbox)。 |
| ReadOnly         | CommonStates          | 用户不能更改中的文本[DatePickerTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.datepickertextbox)。 |
| 已设定焦点       | FocusStates           | 控件有焦点。                                                 |
| 失去焦点         | FocusStates           | 控件没有焦点。                                               |
| 打               | WatermarkStates       | 该控件显示其初始文本。 [DatePickerTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.datepickertextbox)处于状态，当用户不具有输入文本或选择了日期。 |
| Unwatermarked    | WatermarkStates       | 用户输入文本[DatePickerTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.datepickertextbox)中选择了日期或[DatePicker](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datepicker)。 |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### DatePicker ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[DatePicker](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datepicker)控件。

```xaml
<!--In this example, an implecit style for Calendar is defined elsewhere 
  in the application.  DatePickerCalendarStyle is based on the implicit 
  style so that the DatePicker will use the application's calendar style.-->
<Style x:Key="DatePickerCalendarStyle"
       TargetType="{x:Type Calendar}"
       BasedOn="{StaticResource {x:Type Calendar}}" />

<!--The template for the button that displays the calendar.-->
<Style x:Key="DropDownButtonStyle"
       TargetType="Button">
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type Button}">
        <Grid>
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="CommonStates">
              <VisualStateGroup.Transitions>
                <VisualTransition GeneratedDuration="0" />
                <VisualTransition GeneratedDuration="0:0:0.1"
                                  To="MouseOver" />
                <VisualTransition GeneratedDuration="0:0:0.1"
                                  To="Pressed" />
              </VisualStateGroup.Transitions>
              <VisualState x:Name="Normal" />
              <VisualState x:Name="MouseOver">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames BeginTime="0"
                                                Duration="00:00:00.001"
                                                Storyboard.TargetName="BackgroundGradient"
                                                Storyboard.TargetProperty="(Border.Background).
                    (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <SplineColorKeyFrame KeyTime="0"
                                         Value="#F2FFFFFF" />
                  </ColorAnimationUsingKeyFrames>
                  <ColorAnimationUsingKeyFrames BeginTime="0"
                                                Duration="00:00:00.001"
                                                Storyboard.TargetName="BackgroundGradient"
                                                Storyboard.TargetProperty="(Border.Background).
                    (GradientBrush.GradientStops)[2].(GradientStop.Color)">
                    <SplineColorKeyFrame KeyTime="0"
                                         Value="#CCFFFFFF" />
                  </ColorAnimationUsingKeyFrames>
                  <ColorAnimation Duration="0"
                                  To="#FF448DCA"
                                  Storyboard.TargetProperty="(Border.Background).
                            (SolidColorBrush.Color)"
                                  Storyboard.TargetName="Background" />
                  <ColorAnimationUsingKeyFrames BeginTime="0"
                                                Duration="00:00:00.001"
                                                Storyboard.TargetName="BackgroundGradient"
                                                Storyboard.TargetProperty="(Border.Background).
                    (GradientBrush.GradientStops)[3].(GradientStop.Color)">
                    <SplineColorKeyFrame KeyTime="0"
                                         Value="#7FFFFFFF" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Pressed">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames BeginTime="0"
                                                Duration="00:00:00.001"
                                                Storyboard.TargetName="Background"
                                                Storyboard.TargetProperty="(Border.Background).
                      (SolidColorBrush.Color)">
                    <SplineColorKeyFrame KeyTime="0"
                                         Value="#FF448DCA" />
                  </ColorAnimationUsingKeyFrames>
                  <DoubleAnimationUsingKeyFrames BeginTime="0"
                                                 Duration="00:00:00.001"
                                                 Storyboard.TargetProperty="(UIElement.Opacity)"
                                                 Storyboard.TargetName="Highlight">
                    <SplineDoubleKeyFrame KeyTime="0"
                                          Value="1" />
                  </DoubleAnimationUsingKeyFrames>
                  <ColorAnimationUsingKeyFrames BeginTime="0"
                                                Duration="00:00:00.001"
                                                Storyboard.TargetName="BackgroundGradient"
                                                Storyboard.TargetProperty="(Border.Background).
                    (GradientBrush.GradientStops)[0].(GradientStop.Color)">
                    <SplineColorKeyFrame KeyTime="0"
                                         Value="#F4FFFFFF" />
                  </ColorAnimationUsingKeyFrames>
                  <ColorAnimationUsingKeyFrames BeginTime="0"
                                                Duration="00:00:00.001"
                                                Storyboard.TargetName="BackgroundGradient"
                                                Storyboard.TargetProperty="(Border.Background).
                    (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <SplineColorKeyFrame KeyTime="0"
                                         Value="#EAFFFFFF" />
                  </ColorAnimationUsingKeyFrames>
                  <ColorAnimationUsingKeyFrames BeginTime="0"
                                                Duration="00:00:00.001"
                                                Storyboard.TargetName="BackgroundGradient"
                                                Storyboard.TargetProperty="(Border.Background).
                    (GradientBrush.GradientStops)[2].(GradientStop.Color)">
                    <SplineColorKeyFrame KeyTime="0"
                                         Value="#C6FFFFFF" />
                  </ColorAnimationUsingKeyFrames>
                  <ColorAnimationUsingKeyFrames BeginTime="0"
                                                Duration="00:00:00.001"
                                                Storyboard.TargetName="BackgroundGradient"
                                                Storyboard.TargetProperty="(Border.Background).
                    (GradientBrush.GradientStops)[3].(GradientStop.Color)">
                    <SplineColorKeyFrame KeyTime="0"
                                         Value="#6BFFFFFF" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Disabled" />
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <Grid Background="#11FFFFFF"
                FlowDirection="LeftToRight"
                HorizontalAlignment="Center"
                Height="18"
                Margin="0"
                VerticalAlignment="Center"
                Width="19">
            <Grid.ColumnDefinitions>
              <ColumnDefinition Width="20*" />
              <ColumnDefinition Width="20*" />
              <ColumnDefinition Width="20*" />
              <ColumnDefinition Width="20*" />
            </Grid.ColumnDefinitions>
            <Grid.RowDefinitions>
              <RowDefinition Height="23*" />
              <RowDefinition Height="19*" />
              <RowDefinition Height="19*" />
              <RowDefinition Height="19*" />
            </Grid.RowDefinitions>
            <Border x:Name="Highlight"
                    BorderThickness="1"
                    Grid.ColumnSpan="4"
                    CornerRadius="0,0,1,1"
                    Margin="-1"
                    Opacity="1"
                    Grid.Row="0"
                    Grid.RowSpan="4">
              <Border.BorderBrush>
                <SolidColorBrush Color="{DynamicResource ControlPressedColor}" />
              </Border.BorderBrush>
            </Border>
            <Border x:Name="Background"
                    BorderBrush="#FFFFFFFF"
                    BorderThickness="1"
                    Grid.ColumnSpan="4"
                    CornerRadius=".5"
                    Margin="0,-1,0,0"
                    Opacity="1"
                    Grid.Row="1"
                    Grid.RowSpan="3">
              <Border.Background>
                <SolidColorBrush Color="{DynamicResource ControlDarkColor}" />
              </Border.Background>
            </Border>
            <Border x:Name="BackgroundGradient"
                    BorderBrush="#BF000000"
                    BorderThickness="1"
                    Grid.ColumnSpan="4"
                    CornerRadius=".5"
                    Margin="0,-1,0,0"
                    Opacity="1"
                    Grid.Row="1"
                    Grid.RowSpan="3">
              <Border.Background>
                <LinearGradientBrush EndPoint=".7,1"
                                     StartPoint=".7,0">
                  <GradientStop Color="#FFFFFFFF"
                                Offset="0" />
                  <GradientStop Color="#F9FFFFFF"
                                Offset="0.375" />
                  <GradientStop Color="#E5FFFFFF"
                                Offset="0.625" />
                  <GradientStop Color="#C6FFFFFF"
                                Offset="1" />
                </LinearGradientBrush>
              </Border.Background>
            </Border>
            <Rectangle Grid.ColumnSpan="4"
                       Grid.RowSpan="1"
                       StrokeThickness="1">
              <Rectangle.Fill>
                <LinearGradientBrush EndPoint="0,1"
                                     StartPoint="0,0">
                  <GradientStop Color="{DynamicResource HeaderTopColor}" />
                  <GradientStop Color="{DynamicResource ControlMediumColor}"
                                Offset="1" />
                </LinearGradientBrush>
              </Rectangle.Fill>
              <Rectangle.Stroke>
                <LinearGradientBrush EndPoint="0.48,-1"
                                     StartPoint="0.48,1.25">
                  <GradientStop Color="#FF494949" />
                  <GradientStop Color="#FF9F9F9F"
                                Offset="1" />
                </LinearGradientBrush>
              </Rectangle.Stroke>
            </Rectangle>
            <Path Fill="#FF2F2F2F"
                  Grid.Row="1"
                  Grid.Column="0"
                  Grid.RowSpan="3"
                  Grid.ColumnSpan="4"
                  HorizontalAlignment="Center"
                  VerticalAlignment="Center"
                  RenderTransformOrigin="0.5,0.5"
                  Margin="4,3,4,3"
                  Stretch="Fill"
                  Data="M11.426758,8.4305077 L11.749023,8.4305077 
                    L11.749023,16.331387 L10.674805,16.331387 
                    L10.674805,10.299648 L9.0742188,11.298672
                    L9.0742188,10.294277 C9.4788408,10.090176 
                    9.9094238,9.8090878 10.365967,9.4510155 
                    C10.82251,9.0929432 11.176106,8.7527733 
                    11.426758,8.4305077 z M14.65086,8.4305077 
                    L18.566387,8.4305077 L18.566387,9.3435936 
                    L15.671368,9.3435936 L15.671368,11.255703 
                    C15.936341,11.058764 16.27293,10.960293 
                    16.681133,10.960293 C17.411602,10.960293 
                    17.969301,11.178717 18.354229,11.615566 
                    C18.739157,12.052416 18.931622,12.673672
                    18.931622,13.479336 C18.931622,15.452317 
                    18.052553,16.438808 16.294415,16.438808
                    C15.560365,16.438808 14.951641,16.234707 
                    14.468243,15.826504 L14.881817,14.929531
                    C15.368796,15.326992 15.837872,15.525723 
                    16.289043,15.525723 C17.298809,15.525723 
                    17.803692,14.895514 17.803692,13.635098 
                    C17.803692,12.460618 17.305971,11.873379 
                    16.310528,11.873379 C15.83071,11.873379 
                    15.399232,12.079271 15.016094,12.491055
                    L14.65086,12.238613 z" />
            <Ellipse Grid.ColumnSpan="4"
                     Fill="#FFFFFFFF"
                     HorizontalAlignment="Center"
                     Height="3"
                     StrokeThickness="0"
                     VerticalAlignment="Center"
                     Width="3" />
            <Border x:Name="DisabledVisual"
                    BorderBrush="#B2FFFFFF"
                    BorderThickness="1"
                    Grid.ColumnSpan="4"
                    CornerRadius="0,0,.5,.5"
                    Opacity="0"
                    Grid.Row="0"
                    Grid.RowSpan="4" />
          </Grid>
        </Grid>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<Style TargetType="{x:Type DatePicker}">
  <Setter Property="Foreground"
          Value="#FF333333" />
  <Setter Property="IsTodayHighlighted"
          Value="True" />
  <Setter Property="SelectedDateFormat"
          Value="Short" />
  <Setter Property="Padding"
          Value="2" />
  <Setter Property="BorderThickness"
          Value="1" />
  <Setter Property="HorizontalContentAlignment"
          Value="Stretch" />
  <!--Set CalendarStyle to DatePickerCalendarStyle.-->
  <Setter Property="CalendarStyle"
          Value="{DynamicResource DatePickerCalendarStyle}" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type DatePicker}">
        <Border BorderThickness="{TemplateBinding BorderThickness}"
                Padding="{TemplateBinding Padding}">
          <Border.BorderBrush>
            <LinearGradientBrush EndPoint="0.5,1"
                                 StartPoint="0.5,0">
              <GradientStop Color="{DynamicResource BorderLightColor}"
                            Offset="0" />
              <GradientStop Color="{DynamicResource BorderDarkColor}"
                            Offset="1" />
            </LinearGradientBrush>
          </Border.BorderBrush>
          <Border.Background>
            <LinearGradientBrush EndPoint="0.5,1"
                                 StartPoint="0.5,0">
              <GradientStop Color="{DynamicResource HeaderTopColor}"
                            Offset="0" />
              <GradientStop Color="{DynamicResource ControlMediumColor}"
                            Offset="1" />
            </LinearGradientBrush>
          </Border.Background>
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="CommonStates">
              <VisualState x:Name="Normal" />
              <VisualState x:Name="Disabled">
                <Storyboard>
                  <DoubleAnimation Duration="0"
                                   To="1"
                                   Storyboard.TargetProperty="Opacity"
                                   Storyboard.TargetName="PART_DisabledVisual" />
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <Grid x:Name="PART_Root"
                HorizontalAlignment="{TemplateBinding HorizontalContentAlignment}"
                VerticalAlignment="{TemplateBinding VerticalContentAlignment}">
            <Grid.ColumnDefinitions>
              <ColumnDefinition Width="*" />
              <ColumnDefinition Width="Auto" />
            </Grid.ColumnDefinitions>
            <Button x:Name="PART_Button"
                    Grid.Column="1"
                    Foreground="{TemplateBinding Foreground}"
                    Focusable="False"
                    HorizontalAlignment="Left"
                    Margin="3,0,3,0"
                    Grid.Row="0"
                    Style="{StaticResource DropDownButtonStyle}"
                    VerticalAlignment="Top" />
            <DatePickerTextBox x:Name="PART_TextBox"
                               Grid.Column="0"
                               Foreground="{TemplateBinding Foreground}"
                               Focusable="{TemplateBinding Focusable}"
                               HorizontalContentAlignment="Stretch"
                               Grid.Row="0"
                               VerticalContentAlignment="Stretch" />
            <Grid x:Name="PART_DisabledVisual"
                  Grid.ColumnSpan="2"
                  Grid.Column="0"
                  IsHitTestVisible="False"
                  Opacity="0"
                  Grid.Row="0">
              <Grid.ColumnDefinitions>
                <ColumnDefinition Width="*" />
                <ColumnDefinition Width="Auto" />
              </Grid.ColumnDefinitions>
              <Rectangle Grid.Column="0"
                         Fill="#A5FFFFFF"
                         RadiusY="1"
                         Grid.Row="0"
                         RadiusX="1" />
              <Rectangle Grid.Column="1"
                         Fill="#A5FFFFFF"
                         Height="18"
                         Margin="3,0,3,0"
                         RadiusY="1"
                         Grid.Row="0"
                         RadiusX="1"
                         Width="19" />
              <Popup x:Name="PART_Popup"
                     AllowsTransparency="True"
                     Placement="Bottom"
                     PlacementTarget="{Binding ElementName=PART_TextBox}"
                     StaysOpen="False" />
            </Grid>
          </Grid>
        </Border>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

上一示例使用了一个或多个以下资源。

```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [DocumentViewer Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/documentviewer-styles-and-templates)

本主题介绍的样式和模板的[DocumentViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.documentviewer)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### DocumentViewer 部件

下表列出了用于命名的部件[DocumentViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.documentviewer)控件。

| 部件                 | 类型                                                         | 描述                           |
| -------------------- | ------------------------------------------------------------ | ------------------------------ |
| PART_ContentHost     | [ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer) | 内容和滚动区域。               |
| PART_FindToolBarHost | [ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol) | 搜索框中，在默认情况下的底部。 |

### DocumentViewer 状态

下表列出了的可视状态[DocumentViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.documentviewer)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### DocumentViewer ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[DocumentViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.documentviewer)控件。

```xaml
<Style x:Key="{x:Type DocumentViewer}"
       TargetType="{x:Type DocumentViewer}">
  <Setter Property="Foreground"
          Value="{DynamicResource {x:Static SystemColors.WindowTextBrushKey}}" />
  <Setter Property="Background"
          Value="{DynamicResource {x:Static SystemColors.ControlBrushKey}}" />
  <Setter Property="FocusVisualStyle"
          Value="{x:Null}" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type DocumentViewer}">
        <Border BorderThickness="{TemplateBinding BorderThickness}"
                BorderBrush="{TemplateBinding BorderBrush}"
                Focusable="False">
          <Grid KeyboardNavigation.TabNavigation="Local">
            <Grid.Background>
              <SolidColorBrush Color="{DynamicResource ControlLightColor}" />
            </Grid.Background>
            <Grid.RowDefinitions>
              <RowDefinition Height="Auto" />
              <RowDefinition Height="*" />
              <RowDefinition Height="Auto" />
            </Grid.RowDefinitions>
            <ToolBar ToolBarTray.IsLocked="True"
                     KeyboardNavigation.TabNavigation="Continue">
              <Button Command="ApplicationCommands.Print"
                      CommandTarget="{Binding RelativeSource={RelativeSource TemplatedParent}}"
                      Content="Print" />
              <Button Command="ApplicationCommands.Copy"
                      CommandTarget="{Binding RelativeSource={RelativeSource TemplatedParent}}"
                      Content="Copy" />
              <Separator />
              <Button Command="NavigationCommands.IncreaseZoom"
                      CommandTarget="{Binding RelativeSource={RelativeSource TemplatedParent}}"
                      Content="Zoom In" />
              <Button Command="NavigationCommands.DecreaseZoom"
                      CommandTarget="{Binding RelativeSource={RelativeSource TemplatedParent}}"
                      Content="Zoom Out" />
              <Separator />
              <Button Command="NavigationCommands.Zoom"
                      CommandTarget="{Binding RelativeSource={RelativeSource TemplatedParent}}"
                      CommandParameter="100.0"
                      Content="Actual Size" />
              <Button Command="DocumentViewer.FitToWidthCommand"
                      CommandTarget="{Binding RelativeSource={RelativeSource TemplatedParent}}"
                      Content="Fit to Width" />
              <Button Command="DocumentViewer.FitToMaxPagesAcrossCommand"
                      CommandTarget="{Binding RelativeSource={RelativeSource TemplatedParent}}"
                      CommandParameter="1"
                      Content="Whole Page" />
              <Button Command="DocumentViewer.FitToMaxPagesAcrossCommand"
                      CommandTarget="{Binding RelativeSource={RelativeSource TemplatedParent}}"
                      CommandParameter="2"
                      Content="Two Pages" />
            </ToolBar>

            <ScrollViewer Grid.Row="1"
                          CanContentScroll="true"
                          HorizontalScrollBarVisibility="Auto"
                          x:Name="PART_ContentHost"
                          IsTabStop="true">
              <ScrollViewer.Background>
                <LinearGradientBrush EndPoint="0.5,1"
                                     StartPoint="0.5,0">
                  <GradientStop Color="{DynamicResource ControlLightColor}"
                                Offset="0" />
                  <GradientStop Color="{DynamicResource ControlMediumColor}"
                                Offset="1" />
                </LinearGradientBrush>
              </ScrollViewer.Background>
            </ScrollViewer>

            <ContentControl Grid.Row="2"
                            x:Name="PART_FindToolBarHost"/>
          </Grid>
        </Border>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

上一示例使用了一个或多个以下资源。

```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [Expander Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/expander-styles-and-templates)

本主题介绍的样式和模板的[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### 扩展器部分

[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)控件没有任何命名的部件。

***###*** 扩展器状态

下表列出了的可视状态[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 普通             | CommonStates          | 默认状态。                                                   |
| MouseOver        | CommonStates          | 鼠标指针悬停在控件上。                                       |
| 已禁用           | CommonStates          | 已禁用控件。                                                 |
| 已设定焦点       | FocusStates           | 控件有焦点。                                                 |
| 失去焦点         | FocusStates           | 控件没有焦点。                                               |
| 已展开           | ExpansionStates       | 展开控件。                                                   |
| Collapsed        | ExpansionStates       | 不展开控件。                                                 |
| ExpandDown       | ExpandDirectionStates | 控件向下展开。                                               |
| ExpandUp         | ExpandDirectionStates | 控件向上扩展。                                               |
| ExpandLeft       | ExpandDirectionStates | 控件向左展开。                                               |
| ExpandRight      | ExpandDirectionStates | 控件向右展开。                                               |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

***###*** 扩展器 ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)控件。

```xaml
<ControlTemplate x:Key="ExpanderToggleButton"
                 TargetType="{x:Type ToggleButton}">
  <Border x:Name="Border"
          CornerRadius="2,0,0,0"
          BorderThickness="0,0,1,0">
    <Border.Background>
      <LinearGradientBrush EndPoint="0.5,1"
                           StartPoint="0.5,0">
        <GradientStop Color="{DynamicResource ControlLightColor}" />
        <GradientStop Color="{DynamicResource ControlMediumColor}"
                      Offset="1" />
      </LinearGradientBrush>
    </Border.Background>
    <Border.BorderBrush>
      <LinearGradientBrush StartPoint="0,0"
                           EndPoint="0,1">
        <LinearGradientBrush.GradientStops>
          <GradientStopCollection>
            <GradientStop Color="{DynamicResource BorderLightColor}"
                          Offset="0.0" />
            <GradientStop Color="{DynamicResource BorderDarkColor}"
                          Offset="1.0" />
          </GradientStopCollection>
        </LinearGradientBrush.GradientStops>
      </LinearGradientBrush>

    </Border.BorderBrush>
    <VisualStateManager.VisualStateGroups>
      <VisualStateGroup x:Name="CommonStates">
        <VisualState x:Name="Normal" />
        <VisualState x:Name="MouseOver">
          <Storyboard>
            <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                          Storyboard.TargetProperty="(Panel.Background).
                (GradientBrush.GradientStops)[1].(GradientStop.Color)">
              <EasingColorKeyFrame KeyTime="0"
                                   Value="{StaticResource ControlMouseOverColor}" />
            </ColorAnimationUsingKeyFrames>
          </Storyboard>
        </VisualState>
        <VisualState x:Name="Pressed">
          <Storyboard>
            <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                          Storyboard.TargetProperty="(Panel.Background).
                (GradientBrush.GradientStops)[1].(GradientStop.Color)">
              <EasingColorKeyFrame KeyTime="0"
                                   Value="{StaticResource ControlPressedColor}" />
            </ColorAnimationUsingKeyFrames>
          </Storyboard>
        </VisualState>
        <VisualState x:Name="Disabled">
          <Storyboard>
            <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                          Storyboard.TargetProperty="(Panel.Background).
                (GradientBrush.GradientStops)[1].(GradientStop.Color)">
              <EasingColorKeyFrame KeyTime="0"
                                   Value="{StaticResource DisabledControlDarkColor}" />
            </ColorAnimationUsingKeyFrames>
            <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                          Storyboard.TargetProperty="(Border.BorderBrush).
                (GradientBrush.GradientStops)[1].(GradientStop.Color)">
              <EasingColorKeyFrame KeyTime="0"
                                   Value="{StaticResource DisabledBorderLightColor}" />
            </ColorAnimationUsingKeyFrames>
          </Storyboard>
        </VisualState>
      </VisualStateGroup>
      <VisualStateGroup x:Name="CheckStates">
        <VisualState x:Name="Checked">
          <Storyboard>
            <ObjectAnimationUsingKeyFrames Storyboard.TargetProperty="(UIElement.Visibility)"
                                           Storyboard.TargetName="CollapsedArrow">
              <DiscreteObjectKeyFrame KeyTime="0"
                                      Value="{x:Static Visibility.Hidden}" />
            </ObjectAnimationUsingKeyFrames>
            <ObjectAnimationUsingKeyFrames Storyboard.TargetProperty="(UIElement.Visibility)"
                                           Storyboard.TargetName="ExpandededArrow">
              <DiscreteObjectKeyFrame KeyTime="0"
                                      Value="{x:Static Visibility.Visible}" />
            </ObjectAnimationUsingKeyFrames>
          </Storyboard>
        </VisualState>
        <VisualState x:Name="Unchecked" />
        <VisualState x:Name="Indeterminate" />
      </VisualStateGroup>
    </VisualStateManager.VisualStateGroups>
    <Grid>
      <Path x:Name="CollapsedArrow"
            HorizontalAlignment="Center"
            VerticalAlignment="Center"
            Data="M 0 0 L 4 4 L 8 0 Z">
        <Path.Fill>
          <SolidColorBrush Color="{DynamicResource GlyphColor}" />
        </Path.Fill>
      </Path>
      <Path x:Name="ExpandededArrow"
            HorizontalAlignment="Center"
            VerticalAlignment="Center"
            Visibility="Collapsed"
            Data="M 0 4 L 4 0 L 8 4 Z">
        <Path.Fill>
          <SolidColorBrush Color="{DynamicResource GlyphColor}" />
        </Path.Fill>
      </Path>
    </Grid>
  </Border>
</ControlTemplate>

<Style TargetType="{x:Type Expander}">
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type Expander}">
        <Grid>
          <Grid.RowDefinitions>
            <RowDefinition Height="Auto" />
            <RowDefinition x:Name="ContentRow"
                           Height="0" />
          </Grid.RowDefinitions>
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="CommonStates">
              <VisualState x:Name="Normal" />
              <VisualState x:Name="MouseOver" />
              <VisualState x:Name="Disabled">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                      (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource DisabledControlDarkColor}" />
                  </ColorAnimationUsingKeyFrames>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Border.BorderBrush).
                      (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource DisabledBorderLightColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <Border x:Name="Border"
                  Grid.Row="0"
                  BorderThickness="1"
                  CornerRadius="2,2,0,0">
            <Border.BorderBrush>
              <LinearGradientBrush EndPoint="0,1"
                                   StartPoint="0,0">
                <GradientStop Color="{DynamicResource BorderLightColor}"
                              Offset="0" />
                <GradientStop Color="{DynamicResource BorderDarkColor}"
                              Offset="1" />
              </LinearGradientBrush>

            </Border.BorderBrush>
            <Border.Background>

              <LinearGradientBrush StartPoint="0,0"
                                   EndPoint="0,1">
                <LinearGradientBrush.GradientStops>
                  <GradientStopCollection>
                    <GradientStop Color="{DynamicResource ControlLightColor}"
                                  Offset="0.0" />
                    <GradientStop Color="{DynamicResource ControlMediumColor}"
                                  Offset="1.0" />
                  </GradientStopCollection>
                </LinearGradientBrush.GradientStops>
              </LinearGradientBrush>

            </Border.Background>
            <Grid>
              <Grid.ColumnDefinitions>
                <ColumnDefinition Width="20" />
                <ColumnDefinition Width="*" />
              </Grid.ColumnDefinitions>
              <ToggleButton OverridesDefaultStyle="True"
                            Template="{StaticResource ExpanderToggleButton}"
                            IsChecked="{Binding IsExpanded, Mode=TwoWay, 
                  RelativeSource={RelativeSource TemplatedParent}}">
                <ToggleButton.Background>
                  <LinearGradientBrush EndPoint="0.5,1"
                                       StartPoint="0.5,0">
                    <GradientStop Color="{DynamicResource ControlLightColor}"
                                  Offset="0" />
                    <GradientStop Color="{DynamicResource ControlMediumColor}"
                                  Offset="1" />
                  </LinearGradientBrush>
                </ToggleButton.Background>
              </ToggleButton>
              <ContentPresenter Grid.Column="1"
                                Margin="4"
                                ContentSource="Header"
                                RecognizesAccessKey="True" />
            </Grid>
          </Border>
          <Border x:Name="Content"
                  Grid.Row="1"
                  BorderThickness="1,0,1,1"
                  CornerRadius="0,0,2,2">
            <Border.BorderBrush>
              <SolidColorBrush Color="{DynamicResource BorderMediumColor}" />
            </Border.BorderBrush>
            <Border.Background>
              <SolidColorBrush Color="{DynamicResource ContentAreaColorDark}" />
            </Border.Background>
            <ContentPresenter Margin="4" />
          </Border>
        </Grid>
        <ControlTemplate.Triggers>
          <Trigger Property="IsExpanded"
                   Value="True">
            <Setter TargetName="ContentRow"
                    Property="Height"
                    Value="{Binding DesiredHeight, ElementName=Content}" />
          </Trigger>
        </ControlTemplate.Triggers>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

上一示例使用了一个或多个以下资源。

```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [Frame Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/frame-styles-and-templates)

本主题介绍的样式和模板的[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### 帧部件

下表列出了用于命名的部件[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)控件。

| 部件         | 类型                                                         | 描述       |
| ------------ | ------------------------------------------------------------ | ---------- |
| PART_FrameCP | [ContentPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter) | 内容区域。 |

### 帧状态

下表列出了的可视状态[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### 帧 ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)控件。

```xaml
<!-- Back/Forward Button Style -->

<Style x:Key="FrameButtonStyle"
       TargetType="{x:Type Button}">
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="Command"
          Value="NavigationCommands.BrowseBack" />
  <Setter Property="Focusable"
          Value="false" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type Button}">
        <Grid>
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="CommonStates">
              <VisualState x:Name="Normal" />
              <VisualState x:Name="MouseOver">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Ellipse"
                                                Storyboard.TargetProperty="(Shape.Fill).
                      (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlMouseOverColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Pressed">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Ellipse"
                                                Storyboard.TargetProperty="(Shape.Fill).
                      (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlPressedColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Disabled">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Ellipse"
                                                Storyboard.TargetProperty="(Shape.Fill).
                      (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource DisabledControlDarkColor}" />
                  </ColorAnimationUsingKeyFrames>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Arrow"
                                                Storyboard.TargetProperty="(Shape.Fill).
                      (SolidColorBrush.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource DisabledForegroundColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <Ellipse x:Name="Ellipse"
                   StrokeThickness="1"
                   Width="16"
                   Height="16">
            <Ellipse.Stroke>
              <SolidColorBrush Color="{DynamicResource NavButtonFrameColor}" />
            </Ellipse.Stroke>
            <Ellipse.Fill>
              <LinearGradientBrush StartPoint="0,0"
                                   EndPoint="0,1">
                <LinearGradientBrush.GradientStops>
                  <GradientStopCollection>
                    <GradientStop Color="{DynamicResource ControlLightColor}" />
                    <GradientStop Color="{DynamicResource ControlMediumColor}"
                                  Offset="1.0" />
                  </GradientStopCollection>
                </LinearGradientBrush.GradientStops>
              </LinearGradientBrush>
            </Ellipse.Fill>
          </Ellipse>

          <Path x:Name="Arrow"
                Margin="0,0,2,0"
                HorizontalAlignment="Center"
                VerticalAlignment="Center"
                Data="M 4 0 L 0 4 L 4 8 Z" >
              <Path.Fill>
                  <SolidColorBrush Color="{DynamicResource GlyphColor}"/>
              </Path.Fill>
          </Path>
        </Grid>
        <ControlTemplate.Triggers>
          <Trigger Property="Command"
                   Value="{x:Static NavigationCommands.BrowseForward}">
            <Setter TargetName="Arrow"
                    Property="Data"
                    Value="M 0 0 L 4 4 L 0 8 z" />
            <Setter TargetName="Arrow"
                    Property="Margin"
                    Value="2,0,0,0" />
          </Trigger>
        </ControlTemplate.Triggers>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<!-- Frame Menu Style -->

<Style x:Key="FrameMenu"
       TargetType="{x:Type Menu}">
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="KeyboardNavigation.TabNavigation"
          Value="None" />
  <Setter Property="IsMainMenu"
          Value="false" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type Menu}">
        <DockPanel IsItemsHost="true" />
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<!-- Frame Menu Header Style -->

<Style x:Key="FrameHeaderMenuItem"
       TargetType="{x:Type MenuItem}">
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type MenuItem}">
        <Grid>
          <Popup x:Name="PART_Popup"
                 Placement="Bottom"
                 VerticalOffset="2"
                 IsOpen="{TemplateBinding IsSubmenuOpen}"
                 AllowsTransparency="True"
                 Focusable="False"
                 PopupAnimation="Fade">
            <Border x:Name="SubMenuBorder"
                    BorderThickness="1"
                    Background="{DynamicResource MenuPopupBrush}">
              <Border.BorderBrush>
                <SolidColorBrush Color="{StaticResource BorderMediumColor}" />
              </Border.BorderBrush>
              <StackPanel IsItemsHost="true"
                          Margin="2"
                          KeyboardNavigation.TabNavigation="Cycle"
                          KeyboardNavigation.DirectionalNavigation="Cycle" />
            </Border>
          </Popup>

          <Grid x:Name="Panel"
                Width="24"
                Background="Transparent"
                HorizontalAlignment="Right">

            <Border Visibility="Hidden"
                    x:Name="HighlightBorder"
                    BorderThickness="1"
                    CornerRadius="2">
              <Border.BorderBrush>
                <LinearGradientBrush StartPoint="0,0"
                                     EndPoint="0,1">
                  <LinearGradientBrush.GradientStops>
                    <GradientStopCollection>
                      <GradientStop Color="{DynamicResource BorderLightColor}"
                                    Offset="0.0" />
                      <GradientStop Color="{DynamicResource BorderDarkColor}"
                                    Offset="1.0" />
                    </GradientStopCollection>
                  </LinearGradientBrush.GradientStops>
                </LinearGradientBrush>

              </Border.BorderBrush>
              <Border.Background>
                <LinearGradientBrush StartPoint="0,0"
                                     EndPoint="0,1">
                  <LinearGradientBrush.GradientStops>
                    <GradientStopCollection>
                      <GradientStop Color="{DynamicResource ControlLightColor}" />
                      <GradientStop Color="{DynamicResource ControlMouseOverColor}"
                                    Offset="1.0" />
                    </GradientStopCollection>
                  </LinearGradientBrush.GradientStops>
                </LinearGradientBrush>

              </Border.Background>
            </Border>
            <Path x:Name="Arrow"
                  SnapsToDevicePixels="false"
                  HorizontalAlignment="Right"
                  VerticalAlignment="Center"
                  Margin="0,2,4,0"
                  StrokeLineJoin="Round"
                  Data="M 0 0 L 4 4 L 8 0 Z">
              <Path.Stroke>
                <SolidColorBrush Color="{DynamicResource GlyphColor}" />
              </Path.Stroke>
            </Path>
          </Grid>
        </Grid>
        <ControlTemplate.Triggers>
          <Trigger Property="IsHighlighted"
                   Value="true">
            <Setter TargetName="HighlightBorder"
                    Property="Visibility"
                    Value="Visible" />
          </Trigger>
          <Trigger Property="IsSubmenuOpen"
                   Value="true">
            <Setter TargetName="HighlightBorder"
                    Property="BorderBrush">
              <Setter.Value>
                <LinearGradientBrush StartPoint="0,0"
                                     EndPoint="0,1">
                  <GradientBrush.GradientStops>
                    <GradientStopCollection>
                      <GradientStop Color="{DynamicResource BorderDarkColor}"
                                    Offset="0.0" />
                      <GradientStop Color="{DynamicResource BorderMediumColor}"
                                    Offset="1.0" />
                    </GradientStopCollection>
                  </GradientBrush.GradientStops>
                </LinearGradientBrush>
              </Setter.Value>
            </Setter>
            <Setter Property="Background"
                    TargetName="HighlightBorder">
              <Setter.Value>

                <LinearGradientBrush EndPoint="0,1"
                                     StartPoint="0,0">
                  <GradientStop Color="{DynamicResource ControlLightColor}"
                                Offset="0" />
                  <GradientStop Color="{DynamicResource ControlPressedColor}"
                                Offset="0.984" />
                </LinearGradientBrush>
              </Setter.Value>
            </Setter>
          </Trigger>
          <Trigger Property="IsEnabled"
                   Value="false">
            <Setter TargetName="Arrow"
                    Property="Fill">
              <Setter.Value>
                <SolidColorBrush Color="{DynamicResource DisabledForegroundColor}" />
              </Setter.Value>
            </Setter>
          </Trigger>
        </ControlTemplate.Triggers>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<!-- Frame Menu Item Style -->

<Style x:Key="FrameSubmenuItem"
       TargetType="{x:Type MenuItem}">
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="Header"
          Value="{Binding (JournalEntry.Name)}" />
  <Setter Property="Command"
          Value="NavigationCommands.NavigateJournal" />
  <Setter Property="CommandTarget"
          Value="{Binding TemplatedParent, 
    RelativeSource={RelativeSource AncestorType={x:Type Menu}}}" />
  <Setter Property="CommandParameter"
          Value="{Binding RelativeSource={RelativeSource Self}}" />
  <Setter Property="JournalEntryUnifiedViewConverter.JournalEntryPosition"
          Value="{Binding (JournalEntryUnifiedViewConverter.JournalEntryPosition)}" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type MenuItem}">
        <Border BorderThickness="1"
                Name="Border">
          <Grid x:Name="Panel"
                Background="Transparent"
                SnapsToDevicePixels="true"
                Height="35"
                Width="250">
            <Path x:Name="Glyph"
                  SnapsToDevicePixels="false"
                  Margin="7,5"
                  Width="10"
                  Height="10"
                  HorizontalAlignment="Left"
                  StrokeStartLineCap="Triangle"
                  StrokeEndLineCap="Triangle"
                  StrokeThickness="2">
              <Path.Stroke>
                <SolidColorBrush Color="{DynamicResource GlyphColor}" />
              </Path.Stroke>
            </Path>

            <ContentPresenter ContentSource="Header"
                              Margin="24,5,50,5" />
          </Grid>
        </Border>
        <ControlTemplate.Triggers>
          <Trigger Property="JournalEntryUnifiedViewConverter.JournalEntryPosition"
                   Value="Current">
            <Setter TargetName="Glyph"
                    Property="Data"
                    Value="M 0,5 L 2.5,8 L 7,3 " />
          </Trigger>
          <Trigger Property="IsHighlighted"
                   Value="true">
            <Setter Property="Background"
                    TargetName="Border">
              <Setter.Value>
                <LinearGradientBrush EndPoint="0.5,1"
                                     StartPoint="0.5,0">
                  <GradientStop Color="Transparent"
                                Offset="0" />
                  <GradientStop Color="{DynamicResource ControlMouseOverColor}"
                                Offset="1" />
                </LinearGradientBrush>
              </Setter.Value>
            </Setter>
            <Setter Property="BorderBrush"
                    TargetName="Border">
              <Setter.Value>
                <LinearGradientBrush EndPoint="0.5,1"
                                     StartPoint="0.5,0">
                  <GradientStop Color="{DynamicResource BorderMediumColor}"
                                Offset="0" />
                  <GradientStop Color="Transparent"
                                Offset="1" />
                </LinearGradientBrush>
              </Setter.Value>
            </Setter>
          </Trigger>
          <MultiTrigger>
            <MultiTrigger.Conditions>
              <Condition Property="IsHighlighted"
                         Value="true" />
              <Condition Property="JournalEntryUnifiedViewConverter.JournalEntryPosition"
                         Value="Forward" />
            </MultiTrigger.Conditions>
            <Setter TargetName="Glyph"
                    Property="Data"
                    Value="M 3 1 L 7 5 L 3 9 z" />
            <Setter TargetName="Glyph"
                    Property="Stroke"
                    Value="{x:Null}" />
            <Setter TargetName="Glyph"
                    Property="Fill">
              <Setter.Value>
                <SolidColorBrush Color="{StaticResource GlyphColor}" />
              </Setter.Value>
            </Setter>
          </MultiTrigger>
          <MultiTrigger>
            <MultiTrigger.Conditions>
              <Condition Property="IsHighlighted"
                         Value="true" />
              <Condition Property="JournalEntryUnifiedViewConverter.JournalEntryPosition"
                         Value="Back" />
            </MultiTrigger.Conditions>
            <Setter TargetName="Glyph"
                    Property="Data"
                    Value="M 7 1 L 3 5 L 7 9 z" />
            <Setter TargetName="Glyph"
                    Property="Stroke"
                    Value="{x:Null}" />
            <Setter TargetName="Glyph"
                    Property="Fill">
              <Setter.Value>
                <SolidColorBrush Color="{StaticResource GlyphColor}" />
              </Setter.Value>
            </Setter>
          </MultiTrigger>
        </ControlTemplate.Triggers>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<!-- Merges Back and Forward Navigation Stacks -->

<JournalEntryUnifiedViewConverter x:Key="JournalEntryUnifiedViewConverter" />

<!-- SimpleStyles: Frame -->

<Style x:Key="{x:Type Frame}"
       TargetType="{x:Type Frame}">
  <Setter Property="SnapsToDevicePixels"
          Value="true" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type Frame}">
        <DockPanel>
          <Border DockPanel.Dock="Top"
                  Height="22"
                  BorderThickness="1">
            <Border.BorderBrush>
              <LinearGradientBrush EndPoint="0.5,1"
                                   StartPoint="0.5,0">
                <GradientStop Color="{DynamicResource BorderLightColor}"
                              Offset="0" />
                <GradientStop Color="{DynamicResource BorderDarkColor}"
                              Offset="1" />
              </LinearGradientBrush>
            </Border.BorderBrush>
            <Grid>
              <Grid.Background>

                <LinearGradientBrush StartPoint="0,0"
                                     EndPoint="0,1">
                  <LinearGradientBrush.GradientStops>
                    <GradientStopCollection>
                      <GradientStop Color="{DynamicResource ControlLightColor}"
                                    Offset="0.0" />
                      <GradientStop Color="{DynamicResource ControlMediumColor}"
                                    Offset="1.0" />
                    </GradientStopCollection>
                  </LinearGradientBrush.GradientStops>
                </LinearGradientBrush>

              </Grid.Background>
              <Grid.ColumnDefinitions>
                <ColumnDefinition Width="Auto" />
                <ColumnDefinition Width="Auto" />
                <ColumnDefinition Width="16" />
                <ColumnDefinition Width="*" />
              </Grid.ColumnDefinitions>

              <Menu x:Name="NavMenu"
                    Grid.ColumnSpan="3"
                    Height="16"
                    Margin="1,0,0,0"
                    VerticalAlignment="Center"
                    Style="{StaticResource FrameMenu}">
                <MenuItem Style="{StaticResource FrameHeaderMenuItem}"
                          ItemContainerStyle="{StaticResource FrameSubmenuItem}"
                          IsSubmenuOpen="{Binding (MenuItem.IsSubmenuOpen), 
                  Mode=TwoWay, RelativeSource={RelativeSource TemplatedParent}}">
                  <MenuItem.ItemsSource>
                    <MultiBinding Converter="{StaticResource JournalEntryUnifiedViewConverter}">
                      <Binding RelativeSource="{RelativeSource TemplatedParent}"
                               Path="BackStack" />
                      <Binding RelativeSource="{RelativeSource TemplatedParent}"
                               Path="ForwardStack" />
                    </MultiBinding>
                  </MenuItem.ItemsSource>
                </MenuItem>
              </Menu>

              <Path Grid.Column="0"
                    SnapsToDevicePixels="false"
                    IsHitTestVisible="false"
                    Margin="2,1.5,0,1.5"
                    Grid.ColumnSpan="3"
                    StrokeThickness="1"
                    HorizontalAlignment="Left"
                    VerticalAlignment="Center"
                    Data="M15,14 Q18,12.9 20.9,14 A8.3,8.3,0,0,0,35.7,8.7 A8.3,8.3,0,0,0,
                    25.2,0.6 Q18, 3.3 10.8,0.6 A8.3,8.3,0,0,0,0.3,8.7 A8.3,8.3,0,0,0,15,14 z"
                    Stroke="{x:Null}">
                <Path.Fill>
                  <LinearGradientBrush EndPoint="0.5,1"
                                       StartPoint="0.5,0">
                    <GradientStop Color="{DynamicResource ControlMediumColor}"
                                  Offset="0" />
                    <GradientStop Color="{DynamicResource ControlDarkColor}"
                                  Offset="1" />
                  </LinearGradientBrush>
                </Path.Fill>
              </Path>
              <Button Style="{StaticResource FrameButtonStyle}"
                      Command="NavigationCommands.BrowseBack"
                      Content="M 4 0 L 0 4 L 4 8 Z"
                      Margin="2.7,1.5,1.3,1.5"
                      Grid.Column="0" />
              <Button Style="{StaticResource FrameButtonStyle}"
                      Command="NavigationCommands.BrowseForward"
                      Content="M 4 0 L 0 4 L 4 8 Z"
                      Margin="1.3,1.5,0,1.5"
                      Grid.Column="1" />
            </Grid>
          </Border>
          <Border BorderThickness="1">
            <Border.BorderBrush>
              <SolidColorBrush Color="{DynamicResource BorderMediumColor}" />
            </Border.BorderBrush>
            <ContentPresenter x:Name="PART_FrameCP"
                              Height="458"
                              Width="640" />
          </Border>
        </DockPanel>
        <ControlTemplate.Triggers>
          <MultiTrigger>
            <MultiTrigger.Conditions>
              <Condition Property="CanGoForward"
                         Value="false" />
              <Condition Property="CanGoBack"
                         Value="false" />
            </MultiTrigger.Conditions>
            <Setter TargetName="NavMenu"
                    Property="IsEnabled"
                    Value="false" />
          </MultiTrigger>
        </ControlTemplate.Triggers>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

上一示例使用了一个或多个以下资源。

```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [GroupBox Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/groupbox-styles-and-templates)

本主题介绍的样式和模板的[GroupBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.groupbox)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### GroupBox 部件

[GroupBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.groupbox)控件没有任何命名的部件。

### GroupBox 状态

下表列出了的可视状态[GroupBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.groupbox)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### GroupBox ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[GroupBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.groupbox)控件。

```xaml
<Style TargetType="GroupBox">
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="GroupBox">
        <Grid>
          <Grid.RowDefinitions>
            <RowDefinition Height="Auto" />
            <RowDefinition Height="*" />
          </Grid.RowDefinitions>
          <Border Grid.Row="0"
                  BorderThickness="1"
                  CornerRadius="2,2,0,0">
            <Border.BorderBrush>
              <LinearGradientBrush StartPoint="0,0"
                                   EndPoint="0,1">
                <LinearGradientBrush.GradientStops>
                  <GradientStopCollection>
                    <GradientStop Color="{DynamicResource BorderLightColor}"
                                  Offset="0.0" />
                    <GradientStop Color="{DynamicResource BorderDarkColor}"
                                  Offset="1.0" />
                  </GradientStopCollection>
                </LinearGradientBrush.GradientStops>
              </LinearGradientBrush>
            </Border.BorderBrush>

            <Border.Background>
              <LinearGradientBrush StartPoint="0,0"
                                   EndPoint="0,1">
                <LinearGradientBrush.GradientStops>
                  <GradientStopCollection>
                    <GradientStop Color="{DynamicResource ControlLightColor}"
                                  Offset="0.0" />
                    <GradientStop Color="{DynamicResource ControlMediumColor}"
                                  Offset="1.0" />
                  </GradientStopCollection>
                </LinearGradientBrush.GradientStops>
              </LinearGradientBrush>
            </Border.Background>

            <ContentPresenter Margin="4"
                              ContentSource="Header"
                              RecognizesAccessKey="True" />
          </Border>

          <Border Grid.Row="1"
                  BorderThickness="1,0,1,1"
                  CornerRadius="0,0,2,2">
            <Border.BorderBrush>
              <SolidColorBrush Color="{StaticResource BorderMediumColor}" />
            </Border.BorderBrush>
            <Border.Background>
              <LinearGradientBrush EndPoint="0.5,1"
                                   MappingMode="RelativeToBoundingBox"
                                   StartPoint="0.5,0">
                <GradientStop Color="{DynamicResource ContentAreaColorLight}"
                              Offset="0" />
                <GradientStop Color="{DynamicResource ContentAreaColorDark}"
                              Offset="1" />
              </LinearGradientBrush>
            </Border.Background>
            <ContentPresenter Margin="4" />
          </Border>
        </Grid>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)使用一个或多个以下资源。

```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [Label Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/label-styles-and-templates)

本主题介绍的样式和模板的[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### 标签部分

[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)控件没有任何命名的部件。

### 标签状态

下表列出了的可视状态[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### 标签 ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)控件。

```xaml
<Style x:Key="{x:Type Label}"
       TargetType="Label">
  <Setter Property="HorizontalContentAlignment"
          Value="Left" />
  <Setter Property="VerticalContentAlignment"
          Value="Top" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="Label">
        <Border>
          <ContentPresenter HorizontalAlignment="{TemplateBinding HorizontalContentAlignment}"
                            VerticalAlignment="{TemplateBinding VerticalContentAlignment}"
                            RecognizesAccessKey="True" />
        </Border>
        <ControlTemplate.Triggers>
          <Trigger Property="IsEnabled"
                   Value="false">
            <Setter Property="Foreground">
              <Setter.Value>
                <SolidColorBrush Color="{DynamicResource DisabledForegroundColor}" />
              </Setter.Value>
            </Setter>
          </Trigger>
        </ControlTemplate.Triggers>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)使用一个或多个以下资源。

```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [ListBox Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/listbox-styles-and-templates)

本主题介绍的样式和模板的[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### ListBox 部件

[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)控件没有任何命名的部件。

当您创建[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)有关[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)，模板可能包含[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)内[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)。 ([ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)显示在每个项[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox);[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)控件内实现滚动)。 如果[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)不是直接子级[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)，必须授予[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)名称， `ItemsPresenter`。

### ListBox 状态

下表列出了的可视状态[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                     |
| ---------------- | --------------------- | ------------------------ |
| 有效             | ValidationStates      | 控件有效。               |
| InvalidFocused   | ValidationStates      | 控件无效，但具有焦点。   |
| InvalidUnfocused | ValidationStates      | 控件无效，并且没有焦点。 |

### ListBoxItem 部件

[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)控件没有任何命名的部件。

### ListBoxItem 状态

下表列出了的可视状态[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)控件。

| VisualState 名称  | VisualStateGroup 名称 | 描述                                                         |
| ----------------- | --------------------- | ------------------------------------------------------------ |
| 普通              | CommonStates          | 默认状态。                                                   |
| MouseOver         | CommonStates          | 鼠标指针悬停在控件上。                                       |
| 已禁用            | CommonStates          | 该项已禁用。                                                 |
| 已设定焦点        | FocusStates           | 该项有焦点。                                                 |
| 失去焦点          | FocusStates           | 该项没有焦点。                                               |
| 未选定            | SelectionStates       | 未选定该项。                                                 |
| 已选定            | SelectionStates       | 该项当前已选定。                                             |
| SelectedUnfocused | SelectionStates       | 该项已选定，但没有焦点。                                     |
| 有效              | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused    | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused  | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### ListBox ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)有关[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)和[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)控件。

```xaml
<Style x:Key="{x:Type ListBox}"
       TargetType="ListBox">
  <Setter Property="SnapsToDevicePixels"
          Value="true" />
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="ScrollViewer.HorizontalScrollBarVisibility"
          Value="Auto" />
  <Setter Property="ScrollViewer.VerticalScrollBarVisibility"
          Value="Auto" />
  <Setter Property="ScrollViewer.CanContentScroll"
          Value="true" />
  <Setter Property="MinWidth"
          Value="120" />
  <Setter Property="MinHeight"
          Value="95" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="ListBox">
        <Border Name="Border"
                BorderThickness="1"
                CornerRadius="2">
          <Border.Background>
            <SolidColorBrush Color="{StaticResource ControlLightColor}" />
          </Border.Background>
          <Border.BorderBrush>
            <SolidColorBrush Color="{StaticResource BorderMediumColor}" />
          </Border.BorderBrush>
          <ScrollViewer Margin="0"
                        Focusable="false">
            <StackPanel Margin="2"
                        IsItemsHost="True" />
          </ScrollViewer>
        </Border>
        <ControlTemplate.Triggers>
          <Trigger Property="IsEnabled"
                   Value="false">
            <Setter TargetName="Border"
                    Property="Background">
              <Setter.Value>
                <SolidColorBrush Color="{StaticResource DisabledControlLightColor}" />
              </Setter.Value>
            </Setter>
            <Setter TargetName="Border"
                    Property="BorderBrush">
              <Setter.Value>
                <SolidColorBrush Color="{DynamicResource DisabledBorderLightColor}" />
              </Setter.Value>

            </Setter>
          </Trigger>
          <Trigger Property="IsGrouping"
                   Value="true">
            <Setter Property="ScrollViewer.CanContentScroll"
                    Value="false" />
          </Trigger>
        </ControlTemplate.Triggers>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<Style x:Key="{x:Type ListBoxItem}"
       TargetType="ListBoxItem">
  <Setter Property="SnapsToDevicePixels"
          Value="true" />
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="ListBoxItem">
        <Border x:Name="Border"
                Padding="2"
                SnapsToDevicePixels="true">
          <Border.Background>
            <SolidColorBrush Color="Transparent" />
          </Border.Background>
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="SelectionStates">
              <VisualState x:Name="Unselected" />
              <VisualState x:Name="Selected">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                    (SolidColorBrush.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource SelectedBackgroundColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="SelectedUnfocused">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                    (SolidColorBrush.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource SelectedUnfocusedColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <ContentPresenter />
        </Border>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

上一示例使用了一个或多个以下资源。



```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [ListView Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/listview-styles-and-templates)

本主题介绍的样式和模板的[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### ListView 部件

[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控件没有任何命名的部件。

当您创建[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)有关[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)，模板可能包含[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)内[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)。 ([ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)显示在每个项[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview);[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)控件内实现滚动)。 如果[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)不是直接子级[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)，必须授予[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)名称， `ItemsPresenter`。

### ListView 状态

下表列出了的可视状态[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### 列表视图项部分

[ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listviewitem)控件没有任何命名的部件。

### 列表视图项状态

下表列出了用于状态[ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listviewitem)控件。

| VisualState 名称  | VisualStateGroup 名称 | 描述                                                         |
| ----------------- | --------------------- | ------------------------------------------------------------ |
| 普通              | CommonStates          | 默认状态。                                                   |
| 已禁用            | CommonStates          | 已禁用控件。                                                 |
| MouseOver         | CommonStates          | 鼠标指针位于[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)控件。 |
| 已设定焦点        | FocusStates           | 控件有焦点。                                                 |
| 失去焦点          | FocusStates           | 控件没有焦点。                                               |
| 已选定            | SelectionStates       | 当前选定项。                                                 |
| 未选定            | SelectionStates       | 未选定该项。                                                 |
| SelectedUnfocused | SelectionStates       | 该项已选定，但没有焦点。                                     |
| 有效              | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused    | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused  | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### ListView ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控件和其关联的类型。

```xaml
<Style x:Key="{x:Static GridView.GridViewScrollViewerStyleKey}"
       TargetType="ScrollViewer">
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="ScrollViewer">
        <Grid Background="{TemplateBinding Background}">
          <Grid.ColumnDefinitions>
            <ColumnDefinition Width="*" />
            <ColumnDefinition Width="Auto" />
          </Grid.ColumnDefinitions>
          <Grid.RowDefinitions>
            <RowDefinition Height="*" />
            <RowDefinition Height="Auto" />
          </Grid.RowDefinitions>

          <DockPanel Margin="{TemplateBinding Padding}">
            <ScrollViewer DockPanel.Dock="Top"
                          HorizontalScrollBarVisibility="Hidden"
                          VerticalScrollBarVisibility="Hidden"
                          Focusable="false">
              <GridViewHeaderRowPresenter Margin="2,0,2,0"
                                          Columns="{Binding Path=TemplatedParent.View.Columns,
                RelativeSource={RelativeSource TemplatedParent}}"
                                          ColumnHeaderContainerStyle="{Binding
                Path=TemplatedParent.View.ColumnHeaderContainerStyle,
                RelativeSource={RelativeSource TemplatedParent}}"
                                          ColumnHeaderTemplate="{Binding
                Path=TemplatedParent.View.ColumnHeaderTemplate,
                RelativeSource={RelativeSource TemplatedParent}}"
                                          ColumnHeaderTemplateSelector="{Binding 
                Path=TemplatedParent.View.ColumnHeaderTemplateSelector,
                RelativeSource={RelativeSource TemplatedParent}}"
                                          AllowsColumnReorder="{Binding
                Path=TemplatedParent.View.AllowsColumnReorder,
                RelativeSource={RelativeSource TemplatedParent}}"
                                          ColumnHeaderContextMenu="{Binding
                Path=TemplatedParent.View.ColumnHeaderContextMenu,
                RelativeSource={RelativeSource TemplatedParent}}"
                                          ColumnHeaderToolTip="{Binding
                Path=TemplatedParent.View.ColumnHeaderToolTip,
                RelativeSource={RelativeSource TemplatedParent}}"
                                          SnapsToDevicePixels="{TemplateBinding
                SnapsToDevicePixels}" />
            </ScrollViewer>

            <ScrollContentPresenter Name="PART_ScrollContentPresenter"
                                    KeyboardNavigation.DirectionalNavigation="Local"
                                    CanContentScroll="True"
                                    CanHorizontallyScroll="False"
                                    CanVerticallyScroll="False" />
          </DockPanel>

          <ScrollBar Name="PART_HorizontalScrollBar"
                     Orientation="Horizontal"
                     Grid.Row="1"
                     Maximum="{TemplateBinding ScrollableWidth}"
                     ViewportSize="{TemplateBinding ViewportWidth}"
                     Value="{TemplateBinding HorizontalOffset}"
                     Visibility="{TemplateBinding ComputedHorizontalScrollBarVisibility}" />

          <ScrollBar Name="PART_VerticalScrollBar"
                     Grid.Column="1"
                     Maximum="{TemplateBinding ScrollableHeight}"
                     ViewportSize="{TemplateBinding ViewportHeight}"
                     Value="{TemplateBinding VerticalOffset}"
                     Visibility="{TemplateBinding ComputedVerticalScrollBarVisibility}" />

        </Grid>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<Style x:Key="GridViewColumnHeaderGripper"
       TargetType="Thumb">
  <Setter Property="Width"
          Value="18" />
  <Setter Property="Background">
    <Setter.Value>
      <LinearGradientBrush StartPoint="0,0"
                           EndPoint="0,1">
        <LinearGradientBrush.GradientStops>
          <GradientStopCollection>
            <GradientStop Color="{DynamicResource BorderLightColor}"
                          Offset="0.0" />
            <GradientStop Color="{DynamicResource BorderDarkColor}"
                          Offset="1.0" />
          </GradientStopCollection>
        </LinearGradientBrush.GradientStops>
      </LinearGradientBrush>
    </Setter.Value>
  </Setter>
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type Thumb}">
        <Border Padding="{TemplateBinding Padding}"
                Background="Transparent">
          <Rectangle HorizontalAlignment="Center"
                     Width="1"
                     Fill="{TemplateBinding Background}" />
        </Border>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
  <Setter Property="BorderBrush">
    <Setter.Value>
      <LinearGradientBrush EndPoint="0.5,1"
                           StartPoint="0.5,0">
        <GradientStop Color="Black"
                      Offset="0" />
        <GradientStop Color="White"
                      Offset="1" />
      </LinearGradientBrush>
    </Setter.Value>
  </Setter>
</Style>

<Style x:Key="{x:Type GridViewColumnHeader}"
       TargetType="GridViewColumnHeader">
  <Setter Property="HorizontalContentAlignment"
          Value="Center" />
  <Setter Property="VerticalContentAlignment"
          Value="Center" />
  <Setter Property="Foreground"
          Value="{DynamicResource {x:Static SystemColors.ControlTextBrushKey}}" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="GridViewColumnHeader">
        <Grid>
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="CommonStates">
              <VisualState x:Name="Normal" />
              <VisualState x:Name="MouseOver">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetProperty="(Panel.Background).
                    (GradientBrush.GradientStops)[1].(GradientStop.Color)"
                                                Storyboard.TargetName="HeaderBorder">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlMouseOverColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Pressed" />
              <VisualState x:Name="Disabled" />
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <Border x:Name="HeaderBorder"
                  BorderThickness="0,1,0,1"
                  Padding="2,0,2,0">
            <Border.BorderBrush>
              <LinearGradientBrush StartPoint="0,0"
                                   EndPoint="0,1">
                <LinearGradientBrush.GradientStops>
                  <GradientStopCollection>
                    <GradientStop Color="{DynamicResource BorderLightColor}"
                                  Offset="0.0" />
                    <GradientStop Color="{DynamicResource BorderDarkColor}"
                                  Offset="1.0" />
                  </GradientStopCollection>
                </LinearGradientBrush.GradientStops>
              </LinearGradientBrush>

            </Border.BorderBrush>
            <Border.Background>

              <LinearGradientBrush StartPoint="0,0"
                                   EndPoint="0,1">
                <LinearGradientBrush.GradientStops>
                  <GradientStopCollection>
                    <GradientStop Color="{DynamicResource ControlLightColor}"
                                  Offset="0.0" />
                    <GradientStop Color="{DynamicResource ControlMediumColor}"
                                  Offset="1.0" />
                  </GradientStopCollection>
                </LinearGradientBrush.GradientStops>
              </LinearGradientBrush>

            </Border.Background>
            <ContentPresenter x:Name="HeaderContent"
                              Margin="0,0,0,1"
                              RecognizesAccessKey="True"
                              VerticalAlignment="{TemplateBinding VerticalContentAlignment}"
                              HorizontalAlignment="{TemplateBinding HorizontalContentAlignment}"
                              SnapsToDevicePixels="{TemplateBinding SnapsToDevicePixels}"/>
          </Border>
          <Thumb x:Name="PART_HeaderGripper"
                 HorizontalAlignment="Right"
                 Margin="0,0,-9,0"
                 Style="{StaticResource GridViewColumnHeaderGripper}" />
        </Grid>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
  <Style.Triggers>
    <Trigger Property="Role"
             Value="Floating">
      <Setter Property="Opacity"
              Value="0.7" />
      <Setter Property="Template">
        <Setter.Value>
          <ControlTemplate TargetType="GridViewColumnHeader">
            <Canvas Name="PART_FloatingHeaderCanvas">
              <Rectangle Fill="#60000000"
                         Width="{TemplateBinding ActualWidth}"
                         Height="{TemplateBinding ActualHeight}" />
            </Canvas>
          </ControlTemplate>
        </Setter.Value>
      </Setter>
    </Trigger>
    <Trigger Property="Role"
             Value="Padding">
      <Setter Property="Template">
        <Setter.Value>
          <ControlTemplate TargetType="GridViewColumnHeader">
            <Border Name="HeaderBorder"
                    BorderThickness="0,1,0,1">
              <Border.Background>
                <SolidColorBrush Color="{DynamicResource ControlLightColor}" />
              </Border.Background>
              <Border.BorderBrush>
                <LinearGradientBrush StartPoint="0,0"
                                     EndPoint="0,1">
                  <LinearGradientBrush.GradientStops>
                    <GradientStopCollection>
                      <GradientStop Color="{DynamicResource BorderLightColor}"
                                    Offset="0.0" />
                      <GradientStop Color="{DynamicResource BorderDarkColor}"
                                    Offset="1.0" />
                    </GradientStopCollection>
                  </LinearGradientBrush.GradientStops>
                </LinearGradientBrush>
              </Border.BorderBrush>
            </Border>
          </ControlTemplate>
        </Setter.Value>
      </Setter>
    </Trigger>
  </Style.Triggers>
</Style>

<Style x:Key="{x:Type ListView}"
       TargetType="ListView">
  <Setter Property="SnapsToDevicePixels"
          Value="true" />
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="ScrollViewer.HorizontalScrollBarVisibility"
          Value="Auto" />
  <Setter Property="ScrollViewer.VerticalScrollBarVisibility"
          Value="Auto" />
  <Setter Property="ScrollViewer.CanContentScroll"
          Value="true" />
  <Setter Property="VerticalContentAlignment"
          Value="Center" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="ListView">
        <Border Name="Border"
                BorderThickness="1">
          <Border.Background>
            <SolidColorBrush Color="{StaticResource ControlLightColor}" />
          </Border.Background>
          <Border.BorderBrush>
            <SolidColorBrush Color="{StaticResource BorderMediumColor}" />
          </Border.BorderBrush>
          <ScrollViewer Style="{DynamicResource
                        {x:Static GridView.GridViewScrollViewerStyleKey}}">
            <ItemsPresenter />
          </ScrollViewer>
        </Border>
        <ControlTemplate.Triggers>
          <Trigger Property="IsGrouping"
                   Value="true">
            <Setter Property="ScrollViewer.CanContentScroll"
                    Value="false" />
          </Trigger>
          <Trigger Property="IsEnabled"
                   Value="false">
            <Setter TargetName="Border"
                    Property="Background">
              <Setter.Value>
                <SolidColorBrush Color="{DynamicResource DisabledBorderLightColor}" />
              </Setter.Value>
            </Setter>
          </Trigger>
        </ControlTemplate.Triggers>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<Style x:Key="{x:Type ListViewItem}"
       TargetType="ListViewItem">
  <Setter Property="SnapsToDevicePixels"
          Value="true" />
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="ListBoxItem">
        <Border x:Name="Border"
                Padding="2"
                SnapsToDevicePixels="true"
                Background="Transparent">
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="CommonStates">
              <VisualState x:Name="Normal" />
              <VisualState x:Name="MouseOver" />
              <VisualState x:Name="Disabled" />
            </VisualStateGroup>
            <VisualStateGroup x:Name="SelectionStates">
              <VisualState x:Name="Unselected" />
              <VisualState x:Name="Selected">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                    (SolidColorBrush.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource SelectedBackgroundColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="SelectedUnfocused">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                    (SolidColorBrush.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource SelectedUnfocusedColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <GridViewRowPresenter VerticalAlignment="{TemplateBinding VerticalContentAlignment}" />
        </Border>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)示例使用一个或多个以下资源。

```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [Menu Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/menu-styles-and-templates)

本主题介绍的样式和模板的[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### 菜单部分

[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)控件没有任何命名的部件。

当您创建[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)有关[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)，模板可能包含[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)内[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)。 ([ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)显示在每个项[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu);[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)控件内实现滚动)。 如果[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)不是直接子级[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)，必须授予[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)名称， `ItemsPresenter`。

### 菜单状态

下表列出了的可视状态[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### 菜单项部分

下表列出了用于命名的部件[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)控件。

| 部件       | 类型                                                         | 描述               |
| ---------- | ------------------------------------------------------------ | ------------------ |
| PART_Popup | [Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup) | 用于子菜单的区域。 |

当您创建[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)有关[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)，模板可能包含[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)内[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)。 ([ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)显示在每个项[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem);[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)控件内实现滚动)。 如果[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)不是直接子级[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)，必须授予[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)名称， `ItemsPresenter`。

### 菜单项状态

下表列出了的可视状态[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### 菜单和菜单项 ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)控件。

```xaml
<Style x:Key="{x:Type Menu}"
       TargetType="{x:Type Menu}">
  <Setter Property="OverridesDefaultStyle"
          Value="True" />
  <Setter Property="SnapsToDevicePixels"
          Value="True" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type Menu}">
        <Border BorderThickness="1">
          <Border.BorderBrush>
            <LinearGradientBrush StartPoint="0,0"
                                 EndPoint="0,1">
              <LinearGradientBrush.GradientStops>
                <GradientStopCollection>
                  <GradientStop Color="{DynamicResource BorderLightColor}"
                                Offset="0.0" />
                  <GradientStop Color="{DynamicResource BorderDarkColor}"
                                Offset="1.0" />
                </GradientStopCollection>
              </LinearGradientBrush.GradientStops>
            </LinearGradientBrush>

          </Border.BorderBrush>
          <Border.Background>
            <LinearGradientBrush EndPoint="0.5,1"
                                 StartPoint="0.5,0">
              <GradientStop Color="{DynamicResource ControlLightColor}"
                            Offset="0" />
              <GradientStop Color="{DynamicResource ControlMediumColor}"
                            Offset="1" />
            </LinearGradientBrush>
          </Border.Background>
          <StackPanel ClipToBounds="True"
                      Orientation="Horizontal"
                      IsItemsHost="True" />
        </Border>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)控件。



```xaml
<Style x:Key="{x:Static MenuItem.SeparatorStyleKey}"
       TargetType="{x:Type Separator}">
  <Setter Property="Height"
          Value="1" />
  <Setter Property="Margin"
          Value="0,4,0,4" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type Separator}">
        <Border BorderThickness="1">
          <Border.BorderBrush>
            <SolidColorBrush Color="{DynamicResource BorderMediumColor}" />
          </Border.BorderBrush>
        </Border>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<!-- TopLevelHeader -->
<ControlTemplate x:Key="{x:Static MenuItem.TopLevelHeaderTemplateKey}"
                 TargetType="{x:Type MenuItem}">
  <Border x:Name="Border">
    <Grid>
      <ContentPresenter Margin="6,3,6,3"
                        ContentSource="Header"
                        RecognizesAccessKey="True" />
      <Popup x:Name="Popup"
             Placement="Bottom"
             IsOpen="{TemplateBinding IsSubmenuOpen}"
             AllowsTransparency="True"
             Focusable="False"
             PopupAnimation="Fade">
        <Border x:Name="SubmenuBorder"
                SnapsToDevicePixels="True"
                BorderThickness="1"
                Background="{DynamicResource MenuPopupBrush}">
          <Border.BorderBrush>
            <SolidColorBrush Color="{DynamicResource BorderMediumColor}" />
          </Border.BorderBrush>
          <ScrollViewer CanContentScroll="True"
                        Style="{StaticResource MenuScrollViewer}">
            <StackPanel IsItemsHost="True"
                        KeyboardNavigation.DirectionalNavigation="Cycle" />
          </ScrollViewer>
        </Border>
      </Popup>
    </Grid>
  </Border>
  <ControlTemplate.Triggers>
    <Trigger Property="IsSuspendingPopupAnimation"
             Value="true">
      <Setter TargetName="Popup"
              Property="PopupAnimation"
              Value="None" />
    </Trigger>
    <Trigger Property="IsHighlighted"
             Value="true">
      <Setter TargetName="Border"
              Property="BorderBrush"
              Value="Transparent" />
      <Setter Property="Background"
              TargetName="Border">
        <Setter.Value>
          <LinearGradientBrush StartPoint="0,0"
                               EndPoint="0,1">
            <LinearGradientBrush.GradientStops>
              <GradientStopCollection>
                <GradientStop Color="{StaticResource ControlLightColor}" />
                <GradientStop Color="{StaticResource ControlMouseOverColor}"
                              Offset="1.0" />
              </GradientStopCollection>
            </LinearGradientBrush.GradientStops>
          </LinearGradientBrush>

        </Setter.Value>
      </Setter>
    </Trigger>
    <Trigger SourceName="Popup"
             Property="AllowsTransparency"
             Value="True">
      <Setter TargetName="SubmenuBorder"
              Property="CornerRadius"
              Value="0,0,4,4" />
      <Setter TargetName="SubmenuBorder"
              Property="Padding"
              Value="0,0,0,3" />
    </Trigger>
    <Trigger Property="IsEnabled"
             Value="False">
      <Setter Property="Foreground">
        <Setter.Value>
          <SolidColorBrush Color="{StaticResource DisabledForegroundColor}" />
        </Setter.Value>
      </Setter>
    </Trigger>
  </ControlTemplate.Triggers>
</ControlTemplate>

<!-- TopLevelItem -->
<ControlTemplate x:Key="{x:Static MenuItem.TopLevelItemTemplateKey}"
                 TargetType="{x:Type MenuItem}">
  <Border x:Name="Border">
    <Grid>
      <ContentPresenter Margin="6,3,6,3"
                        ContentSource="Header"
                        RecognizesAccessKey="True" />
    </Grid>
  </Border>
  <ControlTemplate.Triggers>
    <Trigger Property="IsHighlighted"
             Value="true">
      <Setter Property="Background"
              TargetName="Border">
        <Setter.Value>
          <LinearGradientBrush StartPoint="0,0"
                               EndPoint="0,1">
            <LinearGradientBrush.GradientStops>
              <GradientStopCollection>
                <GradientStop Color="{StaticResource ControlLightColor}" />
                <GradientStop Color="{StaticResource ControlMouseOverColor}"
                              Offset="1.0" />
              </GradientStopCollection>
            </LinearGradientBrush.GradientStops>
          </LinearGradientBrush>

        </Setter.Value>
      </Setter>
    </Trigger>
    <Trigger Property="IsEnabled"
             Value="False">
      <Setter Property="Foreground">
        <Setter.Value>
          <SolidColorBrush Color="{StaticResource DisabledForegroundColor}" />
        </Setter.Value>
      </Setter>
    </Trigger>
  </ControlTemplate.Triggers>
</ControlTemplate>

<!-- SubmenuItem -->
<ControlTemplate x:Key="{x:Static MenuItem.SubmenuItemTemplateKey}"
                 TargetType="{x:Type MenuItem}">
  <Border x:Name="Border"
          BorderThickness="1">
    <Grid>
      <Grid.ColumnDefinitions>
        <ColumnDefinition Width="Auto"
                          SharedSizeGroup="Icon" />
        <ColumnDefinition Width="*" />
        <ColumnDefinition Width="Auto"
                          SharedSizeGroup="Shortcut" />
        <ColumnDefinition Width="13" />
      </Grid.ColumnDefinitions>
      <ContentPresenter x:Name="Icon"
                        Margin="6,0,6,0"
                        VerticalAlignment="Center"
                        ContentSource="Icon" />
      <Border x:Name="Check"
              Width="13"
              Height="13"
              Visibility="Collapsed"
              Margin="6,0,6,0"
              BorderThickness="1">
        <Border.BorderBrush>
          <LinearGradientBrush StartPoint="0,0"
                               EndPoint="0,1">
            <LinearGradientBrush.GradientStops>
              <GradientStopCollection>
                <GradientStop Color="{DynamicResource BorderLightColor}"
                              Offset="0.0" />
                <GradientStop Color="{DynamicResource BorderDarkColor}"
                              Offset="1.0" />
              </GradientStopCollection>
            </LinearGradientBrush.GradientStops>
          </LinearGradientBrush>

        </Border.BorderBrush>
        <Border.Background>
          <LinearGradientBrush StartPoint="0,0"
                               EndPoint="0,1">
            <LinearGradientBrush.GradientStops>
              <GradientStopCollection>
                <GradientStop Color="{DynamicResource ControlLightColor}" />
                <GradientStop Color="{DynamicResource ControlMediumColor}"
                              Offset="1.0" />
              </GradientStopCollection>
            </LinearGradientBrush.GradientStops>
          </LinearGradientBrush>
        </Border.Background>
        <Path x:Name="CheckMark"
              Width="7"
              Height="7"
              Visibility="Hidden"
              SnapsToDevicePixels="False"
              StrokeThickness="2"
              Data="M 0 0 L 7 7 M 0 7 L 7 0">
          <Path.Stroke>
            <SolidColorBrush Color="{DynamicResource GlyphColor}" />
          </Path.Stroke>
        </Path>
      </Border>
      <ContentPresenter x:Name="HeaderHost"
                        Grid.Column="1"
                        ContentSource="Header"
                        RecognizesAccessKey="True" />
      <TextBlock x:Name="InputGestureText"
                 Grid.Column="2"
                 Text="{TemplateBinding InputGestureText}"
                 Margin="5,2,0,2"
                 DockPanel.Dock="Right" />
    </Grid>
  </Border>
  <ControlTemplate.Triggers>
    <Trigger Property="ButtonBase.Command"
             Value="{x:Null}" />
    <Trigger Property="Icon"
             Value="{x:Null}">
      <Setter TargetName="Icon"
              Property="Visibility"
              Value="Hidden" />
    </Trigger>
    <Trigger Property="IsChecked"
             Value="true">
      <Setter TargetName="CheckMark"
              Property="Visibility"
              Value="Visible" />
    </Trigger>
    <Trigger Property="IsCheckable"
             Value="true">
      <Setter TargetName="Check"
              Property="Visibility"
              Value="Visible" />
      <Setter TargetName="Icon"
              Property="Visibility"
              Value="Hidden" />
    </Trigger>
    <Trigger Property="IsHighlighted"
             Value="true">
      <Setter Property="Background"
              TargetName="Border">
        <Setter.Value>
          <LinearGradientBrush EndPoint="0.5,1"
                               StartPoint="0.5,0">
            <GradientStop Color="Transparent"
                          Offset="0" />
            <GradientStop Color="{DynamicResource ControlMouseOverColor}"
                          Offset="1" />
          </LinearGradientBrush>
        </Setter.Value>
      </Setter>
      <Setter Property="BorderBrush"
              TargetName="Border">
        <Setter.Value>
          <LinearGradientBrush EndPoint="0.5,1"
                               StartPoint="0.5,0">
            <GradientStop Color="{DynamicResource BorderMediumColor}"
                          Offset="0" />
            <GradientStop Color="Transparent"
                          Offset="1" />
          </LinearGradientBrush>
        </Setter.Value>
      </Setter>
    </Trigger>
    <Trigger Property="IsEnabled"
             Value="false">
      <Setter Property="Foreground">
        <Setter.Value>
          <SolidColorBrush Color="{StaticResource DisabledForegroundColor}" />
        </Setter.Value>
      </Setter>
    </Trigger>
  </ControlTemplate.Triggers>
</ControlTemplate>

<ControlTemplate x:Key="{x:Static MenuItem.SubmenuHeaderTemplateKey}"
                 TargetType="{x:Type MenuItem}">
  <Border x:Name="Border"
          BorderThickness="1">
    <Grid>
      <Grid.ColumnDefinitions>
        <ColumnDefinition Width="Auto"
                          SharedSizeGroup="Icon" />
        <ColumnDefinition Width="*" />
        <ColumnDefinition Width="Auto"
                          SharedSizeGroup="Shortcut" />
        <ColumnDefinition Width="13" />
      </Grid.ColumnDefinitions>
      <ContentPresenter x:Name="Icon"
                        Margin="6,0,6,0"
                        VerticalAlignment="Center"
                        ContentSource="Icon" />
      <ContentPresenter x:Name="HeaderHost"
                        Grid.Column="1"
                        ContentSource="Header"
                        RecognizesAccessKey="True" />
      <TextBlock x:Name="InputGestureText"
                 Grid.Column="2"
                 Text="{TemplateBinding InputGestureText}"
                 Margin="5,2,2,2"
                 DockPanel.Dock="Right" />
      <Path Grid.Column="3"
            HorizontalAlignment="Center"
            VerticalAlignment="Center"
            Data="M 0 0 L 0 7 L 4 3.5 Z">
        <Path.Fill>
          <SolidColorBrush Color="{DynamicResource GlyphColor}" />
        </Path.Fill>
      </Path>
      <Popup x:Name="Popup"
             Placement="Right"
             HorizontalOffset="-4"
             IsOpen="{TemplateBinding IsSubmenuOpen}"
             AllowsTransparency="True"
             Focusable="False"
             PopupAnimation="Fade">
        <Border x:Name="SubmenuBorder"
                SnapsToDevicePixels="True"
                Background="{DynamicResource MenuPopupBrush}"
                BorderThickness="1">
          <Border.BorderBrush>
            <SolidColorBrush Color="{DynamicResource BorderMediumColor}" />
          </Border.BorderBrush>
          <ScrollViewer CanContentScroll="True"
                        Style="{StaticResource MenuScrollViewer}">
            <StackPanel IsItemsHost="True"
                        KeyboardNavigation.DirectionalNavigation="Cycle" />
          </ScrollViewer>
        </Border>
      </Popup>
    </Grid>
  </Border>
  <ControlTemplate.Triggers>
    <Trigger Property="Icon"
             Value="{x:Null}">
      <Setter TargetName="Icon"
              Property="Visibility"
              Value="Collapsed" />
    </Trigger>
    <Trigger Property="IsHighlighted"
             Value="true">
      <Setter Property="Background"
              TargetName="Border">
        <Setter.Value>
          <LinearGradientBrush EndPoint="0.5,1"
                               StartPoint="0.5,0">
            <GradientStop Color="Transparent"
                          Offset="0" />
            <GradientStop Color="{DynamicResource ControlMouseOverColor}"
                          Offset="1" />
          </LinearGradientBrush>
        </Setter.Value>
      </Setter>
      <Setter Property="BorderBrush"
              TargetName="Border">
        <Setter.Value>
          <LinearGradientBrush EndPoint="0.5,1"
                               StartPoint="0.5,0">
            <GradientStop Color="{DynamicResource BorderMediumColor}"
                          Offset="0" />
            <GradientStop Color="Transparent"
                          Offset="1" />
          </LinearGradientBrush>
        </Setter.Value>
      </Setter>
    </Trigger>
    <Trigger SourceName="Popup"
             Property="AllowsTransparency"
             Value="True">
      <Setter TargetName="SubmenuBorder"
              Property="CornerRadius"
              Value="4" />
      <Setter TargetName="SubmenuBorder"
              Property="Padding"
              Value="0,3,0,3" />
    </Trigger>
    <Trigger Property="IsEnabled"
             Value="false">
      <Setter Property="Foreground">
        <Setter.Value>
          <SolidColorBrush Color="{StaticResource DisabledForegroundColor}" />
        </Setter.Value>
      </Setter>
    </Trigger>
  </ControlTemplate.Triggers>
</ControlTemplate>

<!-- MenuItem Style -->
<Style x:Key="{x:Type MenuItem}"
       TargetType="{x:Type MenuItem}">
  <Setter Property="OverridesDefaultStyle"
          Value="True" />
  <Style.Triggers>
    <Trigger Property="Role"
             Value="TopLevelHeader">
      <Setter Property="Template"
              Value="{StaticResource {x:Static MenuItem.TopLevelHeaderTemplateKey}}" />
      <Setter Property="Grid.IsSharedSizeScope"
              Value="true" />
    </Trigger>
    <Trigger Property="Role"
             Value="TopLevelItem">
      <Setter Property="Template"
              Value="{StaticResource {x:Static MenuItem.TopLevelItemTemplateKey}}" />
    </Trigger>
    <Trigger Property="Role"
             Value="SubmenuHeader">
      <Setter Property="Template"
              Value="{StaticResource {x:Static MenuItem.SubmenuHeaderTemplateKey}}" />
    </Trigger>
    <Trigger Property="Role"
             Value="SubmenuItem">
      <Setter Property="Template"
              Value="{StaticResource {x:Static MenuItem.SubmenuItemTemplateKey}}" />
    </Trigger>
  </Style.Triggers>
</Style>
```

下面的示例定义`MenuScrollViewer`，会在上一示例中使用。



```xaml
<!--ScrollViewer for a MenuItem-->
<MenuScrollingVisibilityConverter x:Key="MenuScrollingVisibilityConverter" />

<Style x:Key="MenuScrollViewer"
       TargetType="{x:Type ScrollViewer}"
       BasedOn="{x:Null}">
  <Setter Property="HorizontalScrollBarVisibility"
          Value="Hidden" />
  <Setter Property="VerticalScrollBarVisibility"
          Value="Auto" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type ScrollViewer}">
        <Grid SnapsToDevicePixels="True">
          <Grid.ColumnDefinitions>
            <ColumnDefinition Width="*" />
          </Grid.ColumnDefinitions>
          <Grid.RowDefinitions>
            <RowDefinition Height="Auto" />
            <RowDefinition Height="*" />
            <RowDefinition Height="Auto" />
          </Grid.RowDefinitions>
          <Border Grid.Row="1"
                  Grid.Column="0">
            <ScrollContentPresenter Margin="{TemplateBinding Padding}" />
          </Border>
          <RepeatButton Style="{StaticResource MenuScrollButton}"
                        Grid.Row="0"
                        Grid.Column="0"
                        Command="{x:Static ScrollBar.LineUpCommand}"
                        CommandTarget="{Binding RelativeSource={RelativeSource TemplatedParent}}"
                        Focusable="False">
            <RepeatButton.Visibility>
              <MultiBinding FallbackValue="Visibility.Collapsed"
                            Converter="{StaticResource MenuScrollingVisibilityConverter}"
                            ConverterParameter="0">
                <Binding RelativeSource="{RelativeSource TemplatedParent}"
                         Path="ComputedVerticalScrollBarVisibility" />
                <Binding RelativeSource="{RelativeSource TemplatedParent}"
                         Path="VerticalOffset" />
                <Binding RelativeSource="{RelativeSource TemplatedParent}"
                         Path="ExtentHeight" />
                <Binding RelativeSource="{RelativeSource TemplatedParent}"
                         Path="ViewportHeight" />
              </MultiBinding>
            </RepeatButton.Visibility>
            <Path Fill="{DynamicResource {x:Static SystemColors.MenuTextBrushKey}}"
                  Data="{StaticResource UpArrow}" />
          </RepeatButton>
          <RepeatButton Style="{StaticResource MenuScrollButton}"
                        Grid.Row="2"
                        Grid.Column="0"
                        Command="{x:Static ScrollBar.LineDownCommand}"
                        CommandTarget="{Binding RelativeSource={RelativeSource TemplatedParent}}"
                        Focusable="False">
            <RepeatButton.Visibility>
              <MultiBinding FallbackValue="Visibility.Collapsed"
                            Converter="{StaticResource MenuScrollingVisibilityConverter}"
                            ConverterParameter="100">
                <Binding RelativeSource="{RelativeSource TemplatedParent}"
                         Path="ComputedVerticalScrollBarVisibility" />
                <Binding RelativeSource="{RelativeSource TemplatedParent}"
                         Path="VerticalOffset" />
                <Binding RelativeSource="{RelativeSource TemplatedParent}"
                         Path="ExtentHeight" />
                <Binding RelativeSource="{RelativeSource TemplatedParent}"
                         Path="ViewportHeight" />
              </MultiBinding>
            </RepeatButton.Visibility>
            <Path Fill="{DynamicResource {x:Static SystemColors.MenuTextBrushKey}}"
                  Data="{StaticResource DownArrow}" />
          </RepeatButton>
        </Grid>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)示例使用一个或多个以下资源。



```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [NavigationWindow Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/navigationwindow-styles-and-templates)

本主题介绍的样式和模板的[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### NavigationWindow 部件

下表列出了用于命名的部件[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)控件。

| 部件          | 类型                                                         | 描述             |
| ------------- | ------------------------------------------------------------ | ---------------- |
| PART_NavWinCP | [ContentPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter) | 用于内容的区域。 |

### NavigationWindow 状态

下表列出了的可视状态[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### NavigationWindow ControlTemplate 示例

尽管此示例中包含的所有元素中定义的[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)的[NavigationWindow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.navigation.navigationwindow)默认情况下，特定的值应被视为示例。

```xaml
<Style x:Key="NavWinButtonStyle"
       TargetType="{x:Type Button}">
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="Command"
          Value="NavigationCommands.BrowseBack" />
  <Setter Property="Focusable"
          Value="false" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type Button}">
        <Grid>
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="CommonStates">
              <VisualState x:Name="Normal" />
              <VisualState x:Name="MouseOver">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Ellipse"
                                                Storyboard.TargetProperty="(Shape.Fill).
                    (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlMouseOverColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Pressed">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Ellipse"
                                                Storyboard.TargetProperty="(Shape.Fill).
                    (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlPressedColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Disabled">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Ellipse"
                                                Storyboard.TargetProperty="(Shape.Fill).
                    (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource DisabledControlDarkColor}" />
                  </ColorAnimationUsingKeyFrames>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Arrow"
                                                Storyboard.TargetProperty="(Shape.Fill).
                    (SolidColorBrush.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource DisabledForegroundColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>

              </VisualState>
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <Ellipse x:Name="Ellipse"
                   StrokeThickness="1"
                   Width="24"
                   Height="24">
            <Ellipse.Stroke>
              <SolidColorBrush Color="{DynamicResource NavButtonFrameColor}" />
            </Ellipse.Stroke>
            <Ellipse.Fill>
              <LinearGradientBrush StartPoint="0,0"
                                   EndPoint="0,1">
                <LinearGradientBrush.GradientStops>
                  <GradientStopCollection>
                    <GradientStop Color="{DynamicResource ControlLightColor}" />
                    <GradientStop Color="{DynamicResource ControlMediumColor}"
                                  Offset="1.0" />
                  </GradientStopCollection>
                </LinearGradientBrush.GradientStops>
              </LinearGradientBrush>

            </Ellipse.Fill>
          </Ellipse>
          <Path x:Name="Arrow"
                Margin="0,0,3,0"
                HorizontalAlignment="Center"
                VerticalAlignment="Center"
                Data="M 6 0 L 0 6 L 6 12 Z">
            <Path.Fill>
              <SolidColorBrush Color="{DynamicResource GlyphColor}" />
            </Path.Fill>
          </Path>
        </Grid>
        <ControlTemplate.Triggers>
          <Trigger Property="Command"
                   Value="{x:Static NavigationCommands.BrowseForward}">
            <Setter TargetName="Arrow"
                    Property="Data"
                    Value="M 0 0 L 6 6 L 0 12 z" />
            <Setter TargetName="Arrow"
                    Property="Margin"
                    Value="3,0,0,0" />
          </Trigger>
        </ControlTemplate.Triggers>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<!-- NavWin Menu Style -->
<Style x:Key="NavWinMenu"
       TargetType="{x:Type Menu}">
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="KeyboardNavigation.TabNavigation"
          Value="None" />
  <Setter Property="IsMainMenu"
          Value="false" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type Menu}">
        <DockPanel IsItemsHost="true" />
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<!-- NavWin Menu Header Style -->
<Style x:Key="NavWinHeaderMenuItem"
       TargetType="{x:Type MenuItem}">
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type MenuItem}">
        <Grid>
          <Popup x:Name="PART_Popup"
                 Placement="Bottom"
                 VerticalOffset="2"
                 IsOpen="{TemplateBinding IsSubmenuOpen}"
                 AllowsTransparency="True"
                 Focusable="False"
                 PopupAnimation="Fade">
            <Border x:Name="SubMenuBorder"
                    Background="{DynamicResource MenuPopupBrush}"
                    BorderThickness="1">
              <Border.BorderBrush>
                <SolidColorBrush Color="{DynamicResource BorderMediumColor}" />
              </Border.BorderBrush>
              <StackPanel IsItemsHost="true"
                          Margin="2"
                          KeyboardNavigation.TabNavigation="Cycle"
                          KeyboardNavigation.DirectionalNavigation="Cycle" />
            </Border>
          </Popup>

          <Grid x:Name="Panel"
                Width="24"
                Background="Transparent"
                HorizontalAlignment="Right"
                VerticalAlignment="Stretch"
                d:IsHidden="True">

            <Border Visibility="Hidden"
                    x:Name="HighlightBorder"
                    BorderThickness="1"
                    CornerRadius="2">
              <Border.BorderBrush>
                <LinearGradientBrush StartPoint="0,0"
                                     EndPoint="0,1">
                  <LinearGradientBrush.GradientStops>
                    <GradientStopCollection>
                      <GradientStop Color="{DynamicResource BorderLightColor}"
                                    Offset="0.0" />
                      <GradientStop Color="{DynamicResource BorderDarkColor}"
                                    Offset="1.0" />
                    </GradientStopCollection>
                  </LinearGradientBrush.GradientStops>
                </LinearGradientBrush>

              </Border.BorderBrush>
              <Border.Background>
                <LinearGradientBrush StartPoint="0,0"
                                     EndPoint="0,1">
                  <LinearGradientBrush.GradientStops>
                    <GradientStopCollection>
                      <GradientStop Color="{DynamicResource ControlLightColor}" />
                      <GradientStop Color="{DynamicResource ControlMouseOverColor}"
                                    Offset="1.0" />
                    </GradientStopCollection>
                  </LinearGradientBrush.GradientStops>
                </LinearGradientBrush>

              </Border.Background>
            </Border>
            <Path x:Name="Arrow"
                  SnapsToDevicePixels="false"
                  HorizontalAlignment="Right"
                  VerticalAlignment="Center"
                  Margin="0,2,4,0"
                  StrokeLineJoin="Round"
                  Data="M 0 0 L 4 4 L 8 0 Z">
              <Path.Fill>
                <SolidColorBrush Color="{DynamicResource GlyphColor}" />
              </Path.Fill>
            </Path>
          </Grid>
        </Grid>
        <ControlTemplate.Triggers>
          <Trigger Property="IsHighlighted"
                   Value="true">
            <Setter TargetName="HighlightBorder"
                    Property="Visibility"
                    Value="Visible" />
          </Trigger>
          <Trigger Property="IsSubmenuOpen"
                   Value="true">
            <Setter TargetName="HighlightBorder"
                    Property="BorderBrush">
              <Setter.Value>
                <LinearGradientBrush StartPoint="0,0"
                                     EndPoint="0,1">
                  <GradientBrush.GradientStops>
                    <GradientStopCollection>
                      <GradientStop Color="{DynamicResource BorderDarkColor}"
                                    Offset="0.0" />
                      <GradientStop Color="{DynamicResource BorderMediumColor}"
                                    Offset="1.0" />
                    </GradientStopCollection>
                  </GradientBrush.GradientStops>
                </LinearGradientBrush>

              </Setter.Value>
            </Setter>
            <Setter Property="Background"
                    TargetName="HighlightBorder">
              <Setter.Value>

                <LinearGradientBrush EndPoint="0,1"
                                     StartPoint="0,0">
                  <GradientStop Color="{DynamicResource ControlLightColor}"
                                Offset="0" />
                  <GradientStop Color="{DynamicResource ControlPressedColor}"
                                Offset="0.984" />
                </LinearGradientBrush>
              </Setter.Value>
            </Setter>
          </Trigger>
        </ControlTemplate.Triggers>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<!-- NavWin Menu Item Style -->

<Style x:Key="NavWinSubmenuItem"
       TargetType="{x:Type MenuItem}">
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="Header"
          Value="{Binding (JournalEntry.Name)}" />
  <Setter Property="Command"
          Value="NavigationCommands.NavigateJournal" />
  <Setter Property="CommandTarget"
          Value="{Binding TemplatedParent, RelativeSource={RelativeSource AncestorType={x:Type Menu}}}" />
  <Setter Property="CommandParameter"
          Value="{Binding RelativeSource={RelativeSource Self}}" />
  <Setter Property="JournalEntryUnifiedViewConverter.JournalEntryPosition"
          Value="{Binding (JournalEntryUnifiedViewConverter.JournalEntryPosition)}" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type MenuItem}">
        <Border Name="Border"
                BorderThickness="1">
          <Grid x:Name="Panel"
                Background="Transparent"
                SnapsToDevicePixels="true"
                Height="35"
                Width="250">
            <Path x:Name="Glyph"
                  SnapsToDevicePixels="false"
                  Margin="7,5"
                  Width="10"
                  Height="10"
                  HorizontalAlignment="Left"
                  StrokeStartLineCap="Triangle"
                  StrokeEndLineCap="Triangle"
                  StrokeThickness="2">
              <Path.Stroke>
                <SolidColorBrush Color="{DynamicResource GlyphColor}" />
              </Path.Stroke>
            </Path>
            <ContentPresenter ContentSource="Header"
                              Margin="24,5,50,5" />
          </Grid>
        </Border>
        <ControlTemplate.Triggers>
          <Trigger Value="Current"
                   Property="JournalEntryUnifiedViewConverter.JournalEntryPosition">
            <Setter TargetName="Glyph"
                    Property="Data"
                    Value="M 0,5 L 2.5,8 L 7,3 " />
          </Trigger>
          <Trigger Property="IsHighlighted"
                   Value="true">
            <Setter Property="Background"
                    TargetName="Border">
              <Setter.Value>
                <LinearGradientBrush EndPoint="0.5,1"
                                     StartPoint="0.5,0">
                  <GradientStop Color="Transparent"
                                Offset="0" />
                  <GradientStop Color="{DynamicResource ControlMouseOverColor}"
                                Offset="1" />
                </LinearGradientBrush>
              </Setter.Value>
            </Setter>
            <Setter Property="BorderBrush"
                    TargetName="Border">
              <Setter.Value>
                <LinearGradientBrush EndPoint="0.5,1"
                                     StartPoint="0.5,0">
                  <GradientStop Color="{DynamicResource BorderMediumColor}"
                                Offset="0" />
                  <GradientStop Color="Transparent"
                                Offset="1" />
                </LinearGradientBrush>
              </Setter.Value>
            </Setter>
          </Trigger>
          <MultiTrigger>
            <MultiTrigger.Conditions>
              <Condition Property="IsHighlighted"
                         Value="true" />
              <Condition Value="Forward"
                         Property="JournalEntryUnifiedViewConverter.JournalEntryPosition" />
            </MultiTrigger.Conditions>
            <Setter TargetName="Glyph"
                    Property="Data"
                    Value="M 3 1 L 7 5 L 3 9 z" />
            <Setter TargetName="Glyph"
                    Property="Fill">
              <Setter.Value>
                <SolidColorBrush Color="{StaticResource GlyphColor}" />
              </Setter.Value>
            </Setter>
            <Setter TargetName="Glyph"
                    Property="Stroke"
                    Value="{x:Null}" />
          </MultiTrigger>
          <MultiTrigger>
            <MultiTrigger.Conditions>
              <Condition Property="IsHighlighted"
                         Value="true" />
              <Condition Value="Back"
                         Property="JournalEntryUnifiedViewConverter.JournalEntryPosition" />
            </MultiTrigger.Conditions>
            <Setter TargetName="Glyph"
                    Property="Data"
                    Value="M 7 1 L 3 5 L 7 9 z" />
            <Setter TargetName="Glyph"
                    Property="Fill">
              <Setter.Value>
                <SolidColorBrush Color="{StaticResource GlyphColor}" />
              </Setter.Value>
            </Setter>
            <Setter TargetName="Glyph"
                    Property="Stroke"
                    Value="{x:Null}" />
          </MultiTrigger>
        </ControlTemplate.Triggers>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<!-- Merges Back and Forward Navigation Stacks -->

<JournalEntryUnifiedViewConverter x:Key="JournalEntryUnifiedViewConverter" />

<!-- SimpleStyles: NavigationWindow -->

<Style x:Key="{x:Type NavigationWindow}"
       TargetType="{x:Type NavigationWindow}">
  <Setter Property="SnapsToDevicePixels"
          Value="true" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type NavigationWindow}">
        <DockPanel>
          <DockPanel.Background>
            <SolidColorBrush Color="{DynamicResource WindowColor}" />
          </DockPanel.Background>
          <Border DockPanel.Dock="Top"
                  Height="30"
                  BorderThickness="1">
            <Border.BorderBrush>
              <SolidColorBrush Color="{DynamicResource BorderMediumColor}" />
            </Border.BorderBrush>
            <Grid>
              <Grid.Background>

                <LinearGradientBrush StartPoint="0,0"
                                     EndPoint="0,1">
                  <LinearGradientBrush.GradientStops>
                    <GradientStopCollection>
                      <GradientStop Color="{DynamicResource ControlLightColor}"
                                    Offset="0.0" />
                      <GradientStop Color="{DynamicResource ControlMediumColor}"
                                    Offset="1.0" />
                    </GradientStopCollection>
                  </LinearGradientBrush.GradientStops>
                </LinearGradientBrush>

              </Grid.Background>
              <Grid.ColumnDefinitions>
                <ColumnDefinition Width="Auto" />
                <ColumnDefinition Width="Auto" />
                <ColumnDefinition Width="16" />
                <ColumnDefinition Width="*" />
              </Grid.ColumnDefinitions>

              <Menu x:Name="NavMenu"
                    Grid.ColumnSpan="3"
                    Height="20"
                    Margin="1,0,0,0"
                    VerticalAlignment="Center"
                    Style="{StaticResource NavWinMenu}">
                <MenuItem Style="{StaticResource NavWinHeaderMenuItem}"
                          ItemContainerStyle="{StaticResource NavWinSubmenuItem}"
                          IsSubmenuOpen="{Binding (MenuItem.IsSubmenuOpen), 
                  Mode=TwoWay, RelativeSource={RelativeSource TemplatedParent}}">
                  <MenuItem.ItemsSource>
                    <MultiBinding Converter="{StaticResource JournalEntryUnifiedViewConverter}">
                      <Binding RelativeSource="{RelativeSource TemplatedParent}"
                               Path="BackStack" />
                      <Binding RelativeSource="{RelativeSource TemplatedParent}"
                               Path="ForwardStack" />
                    </MultiBinding>
                  </MenuItem.ItemsSource>
                </MenuItem>
              </Menu>

              <Path Grid.Column="0"
                    SnapsToDevicePixels="false"
                    IsHitTestVisible="false"
                    Margin="2,1.5,0,1.5"
                    Grid.ColumnSpan="3"
                    StrokeThickness="1"
                    HorizontalAlignment="Left"
                    VerticalAlignment="Center"
                    Data="M22.5767,21.035 Q27,19.37 
                      31.424,21.035 A12.5,12.5,0,0,0,53.5,13
                      A12.5,12.5,0,0,0,37.765,0.926
                      Q27,4.93 16.235,0.926
                      A12.5,12.5,0,0,0,0.5,13 
                      A12.5,12.5,0,0,0,22.5767,21.035 z">
                <Path.Stroke>
                  <SolidColorBrush Color="{DynamicResource BorderMediumColor}" />
                </Path.Stroke>
                <Path.Fill>

                  <LinearGradientBrush EndPoint="0,1"
                                       StartPoint="0,0">
                    <GradientStop Color="{DynamicResource ControlMediumColor}"
                                  Offset="0" />

                    <GradientStop Color="{DynamicResource ControlDarkColor}"
                                  Offset="0.984" />
                  </LinearGradientBrush>
                </Path.Fill>
              </Path>
              <Button Style="{StaticResource NavWinButtonStyle}"
                      Command="NavigationCommands.BrowseBack"
                      Content="M 4 0 L 0 4 L 4 8 Z"
                      Margin="3,1.5,2,1.5"
                      Grid.Column="0" />
              <Button Style="{StaticResource NavWinButtonStyle}"
                      Command="NavigationCommands.BrowseForward"
                      Content="M 4 0 L 0 4 L 4 8 Z"
                      Margin="2,1.5,0,1.5"
                      Grid.Column="1" />
            </Grid>
          </Border>
          <Grid>
            <AdornerDecorator>
              <Border BorderThickness="1">
                <Border.BorderBrush>
                  <SolidColorBrush Color="{DynamicResource BorderMediumColor}" />
                </Border.BorderBrush>
                <ContentPresenter x:Name="PART_NavWinCP"
                                  ClipToBounds="true" />
              </Border>
            </AdornerDecorator>

            <ResizeGrip x:Name="WindowResizeGrip"
                        HorizontalAlignment="Right"
                        VerticalAlignment="Bottom"
                        Visibility="Collapsed"
                        IsTabStop="false" />
          </Grid>
        </DockPanel>
        <ControlTemplate.Triggers>
          <Trigger Property="ResizeMode"
                   Value="CanResizeWithGrip">
            <Setter TargetName="WindowResizeGrip"
                    Property="Visibility"
                    Value="Visible" />
          </Trigger>
        </ControlTemplate.Triggers>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

上一示例使用了一个或多个以下资源。

```xaml
<Style x:Key="{x:Type ResizeGrip}"
       TargetType="{x:Type ResizeGrip}">
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type ResizeGrip}">
        <Border Background="Transparent"
                SnapsToDevicePixels="True"
                Width="16"
                Height="16">
          <Rectangle Margin="2">
            <Rectangle.Fill>
              <DrawingBrush Viewport="0,0,4,4"
                            ViewportUnits="Absolute"
                            Viewbox="0,0,8,8"
                            ViewboxUnits="Absolute"
                            TileMode="Tile">
                <DrawingBrush.Drawing>
                  <DrawingGroup>
                    <DrawingGroup.Children>
                      <GeometryDrawing Brush="#FFE8EDF9"
                                       Geometry="M 4 4 L 4 8 L 
                                                 8 8 L 8 4 z" />
                    </DrawingGroup.Children>
                  </DrawingGroup>
                </DrawingBrush.Drawing>
              </DrawingBrush>
            </Rectangle.Fill>
          </Rectangle>
        </Border>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [PasswordBox Syles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/passwordbox-syles-and-templates)

本主题介绍的样式和模板的[PasswordBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.passwordbox)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### PasswordBox 部件

下表列出了用于命名的部件[PasswordBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.passwordbox)控件。

| 部件             | 类型                                                         | 描述                                                         |
| ---------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| PART_ContentHost | [FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement) | 可以包含一个可见元素[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)。 文本[PasswordBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.passwordbox)显示在此元素。 |

### PasswordBox 状态

下表列出了的可视状态[PasswordBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.passwordbox)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 普通             | CommonStates          | 默认状态。                                                   |
| MouseOver        | CommonStates          | 鼠标指针悬停在控件上。                                       |
| 已禁用           | CommonStates          | 已禁用控件。                                                 |
| 已设定焦点       | FocusStates           | 控件有焦点。                                                 |
| 失去焦点         | FocusStates           | 控件没有焦点。                                               |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### PasswordBox ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[PasswordBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.passwordbox)控件。

```xaml
<Style x:Key="{x:Type PasswordBox}"
       TargetType="{x:Type PasswordBox}">
  <Setter Property="SnapsToDevicePixels"
          Value="true" />
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="KeyboardNavigation.TabNavigation"
          Value="None" />
  <Setter Property="FocusVisualStyle"
          Value="{x:Null}" />
  <Setter Property="FontFamily"
          Value="Verdana" />
  <Setter Property="PasswordChar"
          Value="*" />
  <Setter Property="MinWidth"
          Value="120" />
  <Setter Property="MinHeight"
          Value="20" />
  <Setter Property="AllowDrop"
          Value="true" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type PasswordBox}">
        <Border x:Name="Border"
                CornerRadius="2"
                Padding="2"
                BorderThickness="1">
          <Border.Background>
            <SolidColorBrush Color="{DynamicResource ControlLightColor}" />
          </Border.Background>
          <Border.BorderBrush>
            <SolidColorBrush Color="{DynamicResource BorderMediumColor}" />
          </Border.BorderBrush>
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="CommonStates">
              <VisualState x:Name="Normal" />
              <VisualState x:Name="Disabled" />
              <VisualState x:Name="MouseOver" />
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <ScrollViewer x:Name="PART_ContentHost" />
        </Border>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

上一示例使用了一个或多个以下资源。



```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [ProgressBar Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/progressbar-styles-and-templates)

本主题介绍的样式和模板的[ProgressBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.progressbar)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### ProgressBar 部件

下表列出了用于命名的部件[ProgressBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.progressbar)控件。

| 部件           | 类型                                                         | 描述                         |
| -------------- | ------------------------------------------------------------ | ---------------------------- |
| PART_Indicator | [FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement) | 一个对象，它指示进度。       |
| PART_Track     | [FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement) | 定义进度指示器的路径的对象。 |
| PART_GlowRect  | [FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement) | 一个对象，修饰进度栏。       |

### 进度栏状态

下表列出了的可视状态[ProgressBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.progressbar)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 确定             | CommonStates          | [ProgressBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.progressbar) 报告进度基于[Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.rangebase.value)属性。 |
| 不确定           | CommonStates          | [ProgressBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.progressbar) 报告由重复图案泛型进度。 |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### ProgressBar ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[ProgressBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.progressbar)控件。

```xaml
<Style x:Key="{x:Type ProgressBar}"
       TargetType="{x:Type ProgressBar}">
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type ProgressBar}">
        <Grid MinHeight="14"
              MinWidth="200"
              Background="{TemplateBinding Background}">
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="CommonStates">
              <VisualState x:Name="Determinate" />
              <VisualState x:Name="Indeterminate">
                <Storyboard>
                  <ObjectAnimationUsingKeyFrames Duration="00:00:00"
                                                 Storyboard.TargetName="PART_Indicator"
                                                 Storyboard.TargetProperty="Background">
                    <DiscreteObjectKeyFrame KeyTime="00:00:00">
                      <DiscreteObjectKeyFrame.Value>
                        <SolidColorBrush>Transparent</SolidColorBrush>
                      </DiscreteObjectKeyFrame.Value>
                    </DiscreteObjectKeyFrame>
                  </ObjectAnimationUsingKeyFrames>

                </Storyboard>
              </VisualState>
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <Border x:Name="PART_Track"
                  CornerRadius="2"
                  BorderThickness="1">
            <Border.BorderBrush>
              <SolidColorBrush Color="{DynamicResource BorderMediumColor}" />
            </Border.BorderBrush>
          </Border>
          <Border x:Name="PART_Indicator"
                  CornerRadius="2"
                  BorderThickness="1"
                  HorizontalAlignment="Left"
                  Background="{TemplateBinding Foreground}"
                  Margin="0,-1,0,1">
            <Border.BorderBrush>
              <LinearGradientBrush StartPoint="0,0"
                                   EndPoint="0,1">
                <GradientBrush.GradientStops>
                  <GradientStopCollection>
                    <GradientStop Color="{DynamicResource BorderLightColor}"
                                  Offset="0.0" />
                    <GradientStop Color="{DynamicResource BorderMediumColor}"
                                  Offset="1.0" />
                  </GradientStopCollection>
                </GradientBrush.GradientStops>
              </LinearGradientBrush>

            </Border.BorderBrush>
            <Grid ClipToBounds="True"
                  x:Name="Animation">
              <Rectangle x:Name="PART_GlowRect"
                         Width="100"
                         HorizontalAlignment="Left"
                         Fill="{StaticResource ProgressBarIndicatorAnimatedFill}"
                         Margin="-100,0,0,0" />
            </Grid>
          </Border>
        </Grid>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
  <Setter Property="Background">
    <Setter.Value>
      <LinearGradientBrush EndPoint="0,1"
                           StartPoint="0,0">
        <GradientStop Color="{DynamicResource ControlLightColor}"
                      Offset="0" />
        <GradientStop Color="{DynamicResource ControlMediumColor}"
                      Offset="1" />
      </LinearGradientBrush>
    </Setter.Value>
  </Setter>
  <Setter Property="Foreground">
    <Setter.Value>
      <LinearGradientBrush EndPoint="0.5,1"
                           StartPoint="0.5,0">
        <GradientStop Color="{DynamicResource ControlMediumColor}"
                      Offset="0" />
        <GradientStop Color="{DynamicResource ControlDarkColor}"
                      Offset="1" />
      </LinearGradientBrush>
    </Setter.Value>
  </Setter>
</Style>
```

上一示例使用了一个或多个以下资源。



```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [RadioButton Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/radiobutton-styles-and-templates)

本主题介绍的样式和模板的[RadioButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.radiobutton)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### 单选按钮部件

[RadioButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.radiobutton)控件没有任何命名的部件。

### 单选按钮状态

下表列出了的可视状态[RadioButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.radiobutton)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 普通             | CommonStates          | 默认状态。                                                   |
| MouseOver        | CommonStates          | 鼠标指针悬停在控件上方。                                     |
| 已按下           | CommonStates          | 已按下控件。                                                 |
| 已禁用           | CommonStates          | 已禁用控件。                                                 |
| 已设定焦点       | FocusStates           | 控件有焦点。                                                 |
| 失去焦点         | FocusStates           | 控件没有焦点。                                               |
| 已选中           | CheckStates           | [IsChecked](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.togglebutton.ischecked) 为 `true`。 |
| 未选中状态       | CheckStates           | [IsChecked](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.togglebutton.ischecked) 为 `false`。 |
| 不确定           | CheckStates           | [IsThreeState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.togglebutton.isthreestate) 是`true`，并[IsChecked](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.togglebutton.ischecked)是`null`。 |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### 单选按钮 ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[RadioButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.radiobutton)控件。

```xaml
<Style x:Key="{x:Type RadioButton}"
       TargetType="{x:Type RadioButton}">
  <Setter Property="SnapsToDevicePixels"
          Value="true" />
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="FocusVisualStyle"
          Value="{DynamicResource RadioButtonFocusVisual}" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type RadioButton}">
        <BulletDecorator Background="Transparent">
          <BulletDecorator.Bullet>
            <Grid Width="13"
                  Height="13">
              <Ellipse x:Name="Border"
                       StrokeThickness="1">
                <Ellipse.Stroke>
                  <LinearGradientBrush EndPoint="0.5,1"
                                       StartPoint="0.5,0">
                    <GradientStop Color="{DynamicResource BorderLightColor}"
                                  Offset="0" />
                    <GradientStop Color="{DynamicResource BorderDarkColor}"
                                  Offset="1" />
                  </LinearGradientBrush>
                </Ellipse.Stroke>
                <Ellipse.Fill>
                  <LinearGradientBrush StartPoint="0,0"
                                       EndPoint="0,1">
                    <LinearGradientBrush.GradientStops>
                      <GradientStopCollection>
                        <GradientStop Color="{DynamicResource ControlLightColor}" />
                        <GradientStop Color="{DynamicResource ControlMediumColor}"
                                      Offset="1.0" />
                      </GradientStopCollection>
                    </LinearGradientBrush.GradientStops>
                  </LinearGradientBrush>
                </Ellipse.Fill>
              </Ellipse>
              <Ellipse x:Name="CheckMark"
                       Margin="4"
                       Visibility="Collapsed">
                <Ellipse.Fill>
                  <SolidColorBrush Color="{DynamicResource GlyphColor}" />
                </Ellipse.Fill>
              </Ellipse>
            </Grid>
          </BulletDecorator.Bullet>
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="CommonStates">
              <VisualState x:Name="Normal" />
              <VisualState x:Name="MouseOver">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Shape.Fill).
                    (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlMouseOverColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Pressed">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Shape.Fill).
                    (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlPressedColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Disabled">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Shape.Fill).
                    (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlLightColor}" />
                  </ColorAnimationUsingKeyFrames>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Shape.Stroke).
                    (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="#40000000" />
                  </ColorAnimationUsingKeyFrames>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Shape.Stroke).
                    (GradientBrush.GradientStops)[0].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="#40000000" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
            <VisualStateGroup x:Name="CheckStates">
              <VisualState x:Name="Checked">
                <Storyboard>
                  <ObjectAnimationUsingKeyFrames Storyboard.TargetProperty="(UIElement.Visibility)"
                                                 Storyboard.TargetName="CheckMark">
                    <DiscreteObjectKeyFrame KeyTime="0"
                                            Value="{x:Static Visibility.Visible}" />
                  </ObjectAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Unchecked" />
              <VisualState x:Name="Indeterminate" />
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <ContentPresenter Margin="4,0,0,0"
                            VerticalAlignment="Center"
                            HorizontalAlignment="Left"
                            RecognizesAccessKey="True" />
        </BulletDecorator>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

上一示例使用了一个或多个以下资源。



```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [RepeatButton Syles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/repeatbutton-syles-and-templates)

本主题介绍的样式和模板的[RepeatButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.repeatbutton)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### RepeatButton 部件

[RepeatButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.repeatbutton)控件没有任何命名的部件。

### RepeatButton 状态

下表列出了的可视状态[RepeatButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.repeatbutton)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 普通             | CommonStates          | 默认状态。                                                   |
| MouseOver        | CommonStates          | 鼠标指针悬停在控件上方。                                     |
| 已按下           | CommonStates          | 已按下控件。                                                 |
| 已禁用           | CommonStates          | 已禁用控件。                                                 |
| 已设定焦点       | FocusStates           | 控件有焦点。                                                 |
| 失去焦点         | FocusStates           | 控件没有焦点。                                               |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### RepeatButton ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[RepeatButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.repeatbutton)控件。



```xaml
<Style x:Key="ScrollBarLineButton"
       TargetType="{x:Type RepeatButton}">
  <Setter Property="SnapsToDevicePixels"
          Value="True" />
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="Focusable"
          Value="false" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type RepeatButton}">
        <Border x:Name="Border"
                Margin="1"
                CornerRadius="2"
                BorderThickness="1">
          <Border.BorderBrush>
            <LinearGradientBrush StartPoint="0,0"
                                 EndPoint="0,1">
              <LinearGradientBrush.GradientStops>
                <GradientStopCollection>
                  <GradientStop Color="{DynamicResource BorderMediumColor}"
                                Offset="0.0" />
                  <GradientStop Color="{DynamicResource BorderDarkColor}"
                                Offset="1.0" />
                </GradientStopCollection>
              </LinearGradientBrush.GradientStops>
            </LinearGradientBrush>
          </Border.BorderBrush>
          <Border.Background>
            <LinearGradientBrush StartPoint="0,0"
                                 EndPoint="0,1">
              <LinearGradientBrush.GradientStops>
                <GradientStopCollection>
                  <GradientStop Color="{DynamicResource ControlLightColor}"/>
                  <GradientStop Color="{DynamicResource ControlMediumColor}"
                                Offset="1.0" />
                </GradientStopCollection>
              </LinearGradientBrush.GradientStops>
            </LinearGradientBrush>
          </Border.Background>
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="CommonStates">
              <VisualState x:Name="Normal" />
              <VisualState x:Name="MouseOver" />
              <VisualState x:Name="Pressed">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                    (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlPressedColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Disabled">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Arrow"
                                                Storyboard.TargetProperty="(Shape.Fill).
                    (SolidColorBrush.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource DisabledForegroundColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <Path x:Name="Arrow"
                HorizontalAlignment="Center"
                VerticalAlignment="Center"
                Data="{Binding Content, 
            RelativeSource={RelativeSource TemplatedParent}}" >
              <Path.Fill>
                  <SolidColorBrush Color="{DynamicResource GlyphColor}"/>
              </Path.Fill>
          </Path>
        </Border>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

上一示例使用了一个或多个以下资源。



```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [ScrollBar Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/scrollbar-styles-and-templates)

本主题介绍的样式和模板的[ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### 滚动条部分

下表列出了用于命名的部件[ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar)控件。

| 部件       | 类型                                                         | 描述                                                         |
| ---------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| PART_Track | [Track](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.track) | 指示的位置的元素的容器[ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar)。 |

### 滚动条状态

下表列出了的可视状态[ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 普通             | CommonStates          | 默认状态。                                                   |
| MouseOver        | CommonStates          | 鼠标指针悬停在控件上。                                       |
| 已禁用           | CommonStates          | 已禁用控件。                                                 |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### 滚动条 ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar)控件。



```xaml
<Style x:Key="ScrollBarLineButton"
       TargetType="{x:Type RepeatButton}">
  <Setter Property="SnapsToDevicePixels"
          Value="True" />
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="Focusable"
          Value="false" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type RepeatButton}">
        <Border x:Name="Border"
                Margin="1"
                CornerRadius="2"
                BorderThickness="1">
          <Border.BorderBrush>
            <LinearGradientBrush StartPoint="0,0"
                                 EndPoint="0,1">
              <LinearGradientBrush.GradientStops>
                <GradientStopCollection>
                  <GradientStop Color="{DynamicResource BorderMediumColor}"
                                Offset="0.0" />
                  <GradientStop Color="{DynamicResource BorderDarkColor}"
                                Offset="1.0" />
                </GradientStopCollection>
              </LinearGradientBrush.GradientStops>
            </LinearGradientBrush>
          </Border.BorderBrush>
          <Border.Background>
            <LinearGradientBrush StartPoint="0,0"
                                 EndPoint="0,1">
              <LinearGradientBrush.GradientStops>
                <GradientStopCollection>
                  <GradientStop Color="{DynamicResource ControlLightColor}"/>
                  <GradientStop Color="{DynamicResource ControlMediumColor}"
                                Offset="1.0" />
                </GradientStopCollection>
              </LinearGradientBrush.GradientStops>
            </LinearGradientBrush>
          </Border.Background>
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="CommonStates">
              <VisualState x:Name="Normal" />
              <VisualState x:Name="MouseOver" />
              <VisualState x:Name="Pressed">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                    (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlPressedColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Disabled">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Arrow"
                                                Storyboard.TargetProperty="(Shape.Fill).
                    (SolidColorBrush.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource DisabledForegroundColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <Path x:Name="Arrow"
                HorizontalAlignment="Center"
                VerticalAlignment="Center"
                Data="{Binding Content, 
            RelativeSource={RelativeSource TemplatedParent}}" >
              <Path.Fill>
                  <SolidColorBrush Color="{DynamicResource GlyphColor}"/>
              </Path.Fill>
          </Path>
        </Border>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<Style x:Key="ScrollBarPageButton"
       TargetType="{x:Type RepeatButton}">
  <Setter Property="SnapsToDevicePixels"
          Value="True" />
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="IsTabStop"
          Value="false" />
  <Setter Property="Focusable"
          Value="false" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type RepeatButton}">
        <Border Background="Transparent" />
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<Style x:Key="ScrollBarThumb"
       TargetType="{x:Type Thumb}">
  <Setter Property="SnapsToDevicePixels"
          Value="True" />
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="IsTabStop"
          Value="false" />
  <Setter Property="Focusable"
          Value="false" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type Thumb}">
        <Border CornerRadius="2"
                Background="{TemplateBinding Background}"
                BorderBrush="{TemplateBinding BorderBrush}"
                BorderThickness="1" />
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<ControlTemplate x:Key="VerticalScrollBar"
                 TargetType="{x:Type ScrollBar}">
  <Grid>
    <Grid.RowDefinitions>
      <RowDefinition MaxHeight="18" />
      <RowDefinition Height="0.00001*" />
      <RowDefinition MaxHeight="18" />
    </Grid.RowDefinitions>
    <Border Grid.RowSpan="3"
            CornerRadius="2"
            Background="#F0F0F0" />
    <RepeatButton Grid.Row="0"
                  Style="{StaticResource ScrollBarLineButton}"
                  Height="18"
                  Command="ScrollBar.LineUpCommand"
                  Content="M 0 4 L 8 4 L 4 0 Z" />
    <Track x:Name="PART_Track"
           Grid.Row="1"
           IsDirectionReversed="true">
      <Track.DecreaseRepeatButton>
        <RepeatButton Style="{StaticResource ScrollBarPageButton}"
                      Command="ScrollBar.PageUpCommand" />
      </Track.DecreaseRepeatButton>
      <Track.Thumb>
        <Thumb Style="{StaticResource ScrollBarThumb}"
               Margin="1,0,1,0">
          <Thumb.BorderBrush>

            <LinearGradientBrush StartPoint="0,0"
                                 EndPoint="1,0">
              <LinearGradientBrush.GradientStops>
                <GradientStopCollection>
                  <GradientStop Color="{DynamicResource BorderLightColor}"
                                Offset="0.0" />
                  <GradientStop Color="{DynamicResource BorderDarkColor}"
                                Offset="1.0" />
                </GradientStopCollection>
              </LinearGradientBrush.GradientStops>
            </LinearGradientBrush>

          </Thumb.BorderBrush>
          <Thumb.Background>

            <LinearGradientBrush StartPoint="0,0"
                                 EndPoint="1,0">
              <LinearGradientBrush.GradientStops>
                <GradientStopCollection>
                  <GradientStop Color="{DynamicResource ControlLightColor}"
                                Offset="0.0" />
                  <GradientStop Color="{DynamicResource ControlMediumColor}"
                                Offset="1.0" />
                </GradientStopCollection>
              </LinearGradientBrush.GradientStops>
            </LinearGradientBrush>

          </Thumb.Background>
        </Thumb>
      </Track.Thumb>
      <Track.IncreaseRepeatButton>
        <RepeatButton Style="{StaticResource ScrollBarPageButton}"
                      Command="ScrollBar.PageDownCommand" />
      </Track.IncreaseRepeatButton>
    </Track>
    <RepeatButton Grid.Row="3"
                  Style="{StaticResource ScrollBarLineButton}"
                  Height="18"
                  Command="ScrollBar.LineDownCommand"
                  Content="M 0 0 L 4 4 L 8 0 Z" />
  </Grid>
</ControlTemplate>

<ControlTemplate x:Key="HorizontalScrollBar"
                 TargetType="{x:Type ScrollBar}">
  <Grid>
    <Grid.ColumnDefinitions>
      <ColumnDefinition MaxWidth="18" />
      <ColumnDefinition Width="0.00001*" />
      <ColumnDefinition MaxWidth="18" />
    </Grid.ColumnDefinitions>
    <Border Grid.ColumnSpan="3"
            CornerRadius="2"
            Background="#F0F0F0" />
    <RepeatButton Grid.Column="0"
                  Style="{StaticResource ScrollBarLineButton}"
                  Width="18"
                  Command="ScrollBar.LineLeftCommand"
                  Content="M 4 0 L 4 8 L 0 4 Z" />
    <Track x:Name="PART_Track"
           Grid.Column="1"
           IsDirectionReversed="False">
      <Track.DecreaseRepeatButton>
        <RepeatButton Style="{StaticResource ScrollBarPageButton}"
                      Command="ScrollBar.PageLeftCommand" />
      </Track.DecreaseRepeatButton>
      <Track.Thumb>
        <Thumb Style="{StaticResource ScrollBarThumb}"
               Margin="0,1,0,1">

          <Thumb.BorderBrush>

            <LinearGradientBrush StartPoint="0,0"
                                 EndPoint="1,0">
              <LinearGradientBrush.GradientStops>
                <GradientStopCollection>
                  <GradientStop Color="{DynamicResource BorderLightColor}"
                                Offset="0.0" />
                  <GradientStop Color="{DynamicResource BorderDarkColor}"
                                Offset="1.0" />
                </GradientStopCollection>
              </LinearGradientBrush.GradientStops>
            </LinearGradientBrush>

          </Thumb.BorderBrush>
          <Thumb.Background>

            <LinearGradientBrush StartPoint="0,0"
                                 EndPoint="0,1">
              <LinearGradientBrush.GradientStops>
                <GradientStopCollection>
                  <GradientStop Color="{DynamicResource ControlLightColor}"
                                Offset="0.0" />
                  <GradientStop Color="{DynamicResource ControlMediumColor}"
                                Offset="1.0" />
                </GradientStopCollection>
              </LinearGradientBrush.GradientStops>
            </LinearGradientBrush>

          </Thumb.Background>
        </Thumb>
      </Track.Thumb>
      <Track.IncreaseRepeatButton>
        <RepeatButton Style="{StaticResource ScrollBarPageButton}"
                      Command="ScrollBar.PageRightCommand" />
      </Track.IncreaseRepeatButton>
    </Track>
    <RepeatButton Grid.Column="3"
                  Style="{StaticResource ScrollBarLineButton}"
                  Width="18"
                  Command="ScrollBar.LineRightCommand"
                  Content="M 0 0 L 4 4 L 0 8 Z" />
  </Grid>
</ControlTemplate>

<Style x:Key="{x:Type ScrollBar}"
       TargetType="{x:Type ScrollBar}">
  <Setter Property="SnapsToDevicePixels"
          Value="True" />
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Style.Triggers>
    <Trigger Property="Orientation"
             Value="Horizontal">
      <Setter Property="Width"
              Value="Auto" />
      <Setter Property="Height"
              Value="18" />
      <Setter Property="Template"
              Value="{StaticResource HorizontalScrollBar}" />
    </Trigger>
    <Trigger Property="Orientation"
             Value="Vertical">
      <Setter Property="Width"
              Value="18" />
      <Setter Property="Height"
              Value="Auto" />
      <Setter Property="Template"
              Value="{StaticResource VerticalScrollBar}" />
    </Trigger>
  </Style.Triggers>
</Style>
```

上一示例使用了一个或多个以下资源。



```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [ScrollViewer Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/scrollviewer-styles-and-templates)

本主题介绍的样式和模板的[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### ScrollViewer 部件

下表列出了用于命名的部件[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)控件。

| 部件                        | 类型                                                         | 描述                                                         |
| --------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| PART_ScrollContentPresenter | [ScrollContentPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollcontentpresenter) | 中的内容占位符[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)。 |
| PART_HorizontalScrollBar    | [ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar) | [ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar)用于水平滚动内容。 |
| PART_VerticalScrollBar      | [ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar) | [ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar)使用垂直滚动内容。 |

### ScrollViewer 状态

下表列出了的可视状态[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### ScrollViewer ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)控件。



```xaml
<Style x:Key="LeftScrollViewer"
       TargetType="{x:Type ScrollViewer}">
  <Setter Property="OverridesDefaultStyle"
          Value="True" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type ScrollViewer}">
        <Grid>
          <Grid.ColumnDefinitions>
            <ColumnDefinition Width="Auto" />
            <ColumnDefinition />
          </Grid.ColumnDefinitions>
          <Grid.RowDefinitions>
            <RowDefinition />
            <RowDefinition Height="Auto" />
          </Grid.RowDefinitions>
          <Border Grid.Column="1"
                  BorderThickness="0,1,1,1">
            <Border.BorderBrush>
              <SolidColorBrush Color="{DynamicResource BorderMediumColor}" />
            </Border.BorderBrush>
            <ScrollContentPresenter />
          </Border>
          <ScrollBar x:Name="PART_VerticalScrollBar"
                     Value="{TemplateBinding VerticalOffset}"
                     Maximum="{TemplateBinding ScrollableHeight}"
                     ViewportSize="{TemplateBinding ViewportHeight}"
                     Visibility="{TemplateBinding ComputedVerticalScrollBarVisibility}"/>
          <ScrollBar x:Name="PART_HorizontalScrollBar"
                     Orientation="Horizontal"
                     Grid.Row="1"
                     Grid.Column="1"
                     Value="{TemplateBinding HorizontalOffset}"
                     Maximum="{TemplateBinding ScrollableWidth}"
                     ViewportSize="{TemplateBinding ViewportWidth}"
                     Visibility="{TemplateBinding ComputedHorizontalScrollBarVisibility}"/>

        </Grid>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

上一示例使用了一个或多个以下资源。



```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [Slider Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/slider-styles-and-templates)

本主题介绍的样式和模板的[Slider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### 滑块部分

下表列出了用于命名的部件[Slider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider)控件。

| 部件                | 类型                                                         | 描述                                                         |
| ------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| PART_Track          | [Track](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.track) | 指示的位置的元素的容器[Slider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider)。 |
| PART_SelectionRange | [FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement) | 显示选择范围沿元素[Slider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider)。 选择范围，可见才[IsSelectionRangeEnabled](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider.isselectionrangeenabled)属性是`true`。 |

### 滑块状态

下表列出了的可视状态[Slider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 普通             | CommonStates          | 默认状态。                                                   |
| MouseOver        | CommonStates          | 鼠标指针悬停在控件上。                                       |
| 已禁用           | CommonStates          | 已禁用控件。                                                 |
| 已设定焦点       | FocusStates           | 控件有焦点。                                                 |
| 失去焦点         | FocusStates           | 控件没有焦点。                                               |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### 滑块 ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[Slider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider)控件。



```xaml
<Style x:Key="SliderButtonStyle"
       TargetType="{x:Type RepeatButton}">
  <Setter Property="SnapsToDevicePixels"
          Value="true" />
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="IsTabStop"
          Value="false" />
  <Setter Property="Focusable"
          Value="false" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type RepeatButton}">
        <Border Background="Transparent" />
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<Style x:Key="SliderThumbStyle"
       TargetType="{x:Type Thumb}">
  <Setter Property="SnapsToDevicePixels"
          Value="true" />
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="Height"
          Value="14" />
  <Setter Property="Width"
          Value="14" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type Thumb}">
        <Ellipse x:Name="Ellipse"
                 StrokeThickness="1">
          <Ellipse.Stroke>
            <LinearGradientBrush StartPoint="0,0"
                                 EndPoint="0,1">
              <LinearGradientBrush.GradientStops>
                <GradientStopCollection>
                  <GradientStop Color="{DynamicResource BorderLightColor}"
                                Offset="0.0" />
                  <GradientStop Color="{DynamicResource BorderDarkColor}"
                                Offset="1.0" />
                </GradientStopCollection>
              </LinearGradientBrush.GradientStops>
            </LinearGradientBrush>
          </Ellipse.Stroke>
          <Ellipse.Fill>
            <LinearGradientBrush EndPoint="0.5,1"
                                 StartPoint="0.5,0">
              <GradientStop Color="{DynamicResource ControlMediumColor}"
                            Offset="1" />
              <GradientStop Color="{DynamicResource ControlLightColor}" />
            </LinearGradientBrush>
          </Ellipse.Fill>
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="CommonStates">
              <VisualState x:Name="Normal" />
              <VisualState x:Name="MouseOver">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetProperty="(Shape.Fill).
                    (GradientBrush.GradientStops)[0].(GradientStop.Color)"
                                                Storyboard.TargetName="Ellipse">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlMouseOverColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Pressed">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetProperty="(Shape.Fill).
                    (GradientBrush.GradientStops)[0].(GradientStop.Color)"
                                                Storyboard.TargetName="Ellipse">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlPressedColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Disabled">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetProperty="(Shape.Fill).
                    (GradientBrush.GradientStops)[0].(GradientStop.Color)"
                                                Storyboard.TargetName="Ellipse">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource DisabledControlDarkColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
        </Ellipse>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<!--Template when the orientation of the Slider is Horizontal.-->
<ControlTemplate x:Key="HorizontalSlider"
                 TargetType="{x:Type Slider}">
  <Grid>
    <Grid.RowDefinitions>
      <RowDefinition Height="Auto" />
      <RowDefinition Height="Auto"
                     MinHeight="{TemplateBinding MinHeight}" />
      <RowDefinition Height="Auto" />
    </Grid.RowDefinitions>
    <TickBar x:Name="TopTick"
             SnapsToDevicePixels="True"
             Placement="Top"
             Height="4"
             Visibility="Collapsed">
      <TickBar.Fill>
        <SolidColorBrush Color="{DynamicResource GlyphColor}" />
      </TickBar.Fill>
    </TickBar>
    <Border x:Name="TrackBackground"
            Margin="0"
            CornerRadius="2"
            Height="4"
            Grid.Row="1"
            BorderThickness="1">
      <Border.BorderBrush>
        <LinearGradientBrush StartPoint="0,0"
                             EndPoint="0,1">
          <LinearGradientBrush.GradientStops>
            <GradientStopCollection>
              <GradientStop Color="{DynamicResource BorderLightColor}"
                            Offset="0.0" />
              <GradientStop Color="{DynamicResource BorderDarkColor}"
                            Offset="1.0" />
            </GradientStopCollection>
          </LinearGradientBrush.GradientStops>
        </LinearGradientBrush>
      </Border.BorderBrush>
      <Border.Background>
        <LinearGradientBrush StartPoint="0,0"
                             EndPoint="0,1">
          <LinearGradientBrush.GradientStops>
            <GradientStopCollection>
              <GradientStop Color="{DynamicResource ControlLightColor}"
                            Offset="0.0" />
              <GradientStop Color="{DynamicResource SliderTrackDarkColor}"
                            Offset="1.0" />
            </GradientStopCollection>
          </LinearGradientBrush.GradientStops>
        </LinearGradientBrush>
      </Border.Background>
    </Border>
    <Track Grid.Row="1"
           x:Name="PART_Track">
      <Track.DecreaseRepeatButton>
        <RepeatButton Style="{StaticResource SliderButtonStyle}"
                      Command="Slider.DecreaseLarge" />
      </Track.DecreaseRepeatButton>
      <Track.Thumb>
        <Thumb Style="{StaticResource SliderThumbStyle}" />
      </Track.Thumb>
      <Track.IncreaseRepeatButton>
        <RepeatButton Style="{StaticResource SliderButtonStyle}"
                      Command="Slider.IncreaseLarge" />
      </Track.IncreaseRepeatButton>
    </Track>
    <TickBar x:Name="BottomTick"
             SnapsToDevicePixels="True"
             Grid.Row="2"
             Fill="{TemplateBinding Foreground}"
             Placement="Bottom"
             Height="4"
             Visibility="Collapsed" />
  </Grid>
  <ControlTemplate.Triggers>
    <Trigger Property="TickPlacement"
             Value="TopLeft">
      <Setter TargetName="TopTick"
              Property="Visibility"
              Value="Visible" />
    </Trigger>
    <Trigger Property="TickPlacement"
             Value="BottomRight">
      <Setter TargetName="BottomTick"
              Property="Visibility"
              Value="Visible" />
    </Trigger>
    <Trigger Property="TickPlacement"
             Value="Both">
      <Setter TargetName="TopTick"
              Property="Visibility"
              Value="Visible" />
      <Setter TargetName="BottomTick"
              Property="Visibility"
              Value="Visible" />
    </Trigger>
  </ControlTemplate.Triggers>
</ControlTemplate>

<!--Template when the orientation of the Slider is Vertical.-->
<ControlTemplate x:Key="VerticalSlider"
                 TargetType="{x:Type Slider}">
  <Grid>
    <Grid.ColumnDefinitions>
      <ColumnDefinition Width="Auto" />
      <ColumnDefinition Width="Auto"
                        MinWidth="{TemplateBinding MinWidth}" />
      <ColumnDefinition Width="Auto" />
    </Grid.ColumnDefinitions>
    <TickBar x:Name="TopTick"
             SnapsToDevicePixels="True"
             Placement="Left"
             Width="4"
             Visibility="Collapsed">
      <TickBar.Fill>
        <SolidColorBrush Color="{DynamicResource GlyphColor}" />
      </TickBar.Fill>
    </TickBar>

    <Border x:Name="TrackBackground"
            Margin="0"
            CornerRadius="2"
            Width="4"
            Grid.Column="1"
            BorderThickness="1">
      <Border.BorderBrush>
        <LinearGradientBrush StartPoint="0,0"
                             EndPoint="1,0">
          <LinearGradientBrush.GradientStops>
            <GradientStopCollection>
              <GradientStop Color="{DynamicResource BorderLightColor}"
                            Offset="0.0" />
              <GradientStop Color="{DynamicResource BorderDarkColor}"
                            Offset="1.0" />
            </GradientStopCollection>
          </LinearGradientBrush.GradientStops>
        </LinearGradientBrush>

      </Border.BorderBrush>
      <Border.Background>
        <LinearGradientBrush EndPoint="1,0"
                             StartPoint="0.25,0">
          <GradientStop Color="{DynamicResource ControlLightColor}"
                        Offset="0" />
          <GradientStop Color="{DynamicResource SliderTrackDarkColor}"
                        Offset="1" />
        </LinearGradientBrush>
      </Border.Background>
    </Border>
    <Track Grid.Column="1"
           x:Name="PART_Track">
      <Track.DecreaseRepeatButton>
        <RepeatButton Style="{StaticResource SliderButtonStyle}"
                      Command="Slider.DecreaseLarge" />
      </Track.DecreaseRepeatButton>
      <Track.Thumb>
        <Thumb Style="{StaticResource SliderThumbStyle}" />
      </Track.Thumb>
      <Track.IncreaseRepeatButton>
        <RepeatButton Style="{StaticResource SliderButtonStyle}"
                      Command="Slider.IncreaseLarge" />
      </Track.IncreaseRepeatButton>
    </Track>
    <TickBar x:Name="BottomTick"
             SnapsToDevicePixels="True"
             Grid.Column="2"
             Fill="{TemplateBinding Foreground}"
             Placement="Right"
             Width="4"
             Visibility="Collapsed" />
  </Grid>
  <ControlTemplate.Triggers>
    <Trigger Property="TickPlacement"
             Value="TopLeft">
      <Setter TargetName="TopTick"
              Property="Visibility"
              Value="Visible" />
    </Trigger>
    <Trigger Property="TickPlacement"
             Value="BottomRight">
      <Setter TargetName="BottomTick"
              Property="Visibility"
              Value="Visible" />
    </Trigger>
    <Trigger Property="TickPlacement"
             Value="Both">
      <Setter TargetName="TopTick"
              Property="Visibility"
              Value="Visible" />
      <Setter TargetName="BottomTick"
              Property="Visibility"
              Value="Visible" />
    </Trigger>
  </ControlTemplate.Triggers>
</ControlTemplate>

<Style TargetType="{x:Type Slider}">
  <Setter Property="SnapsToDevicePixels"
          Value="true" />
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Style.Triggers>
    <Trigger Property="Orientation"
             Value="Horizontal">
      <Setter Property="MinWidth"
              Value="104" />
      <Setter Property="MinHeight"
              Value="21" />
      <Setter Property="Template"
              Value="{StaticResource HorizontalSlider}" />
    </Trigger>
    <Trigger Property="Orientation"
             Value="Vertical">
      <Setter Property="MinWidth"
              Value="21" />
      <Setter Property="MinHeight"
              Value="104" />
      <Setter Property="Template"
              Value="{StaticResource VerticalSlider}" />
    </Trigger>
  </Style.Triggers>
</Style>
```

上一示例使用了一个或多个以下资源。



```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [StatusBar Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/statusbar-styles-and-templates)

本主题介绍的样式和模板的[StatusBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.statusbar)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### StatusBar 部件

[StatusBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.statusbar)控件没有任何命名的部件。

### StatusBar 状态

下表列出了的可视状态[StatusBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.statusbar)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### StatusBarItem 部件

[StatusBarItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.statusbaritem)控件没有任何命名的部件。

### StatusBar 状态

下表列出了的可视状态[StatusBarItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.statusbaritem)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### StatusBar ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[StatusBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.statusbar)控件。



```xaml
<Style x:Key="{x:Type StatusBar}"
       TargetType="{x:Type StatusBar}">
  <Setter Property="SnapsToDevicePixels"
          Value="True" />
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type StatusBar}">
        <Border Padding="1">
          <Border.BorderBrush>
            <LinearGradientBrush StartPoint="0,0"
                                 EndPoint="0,1">
              <LinearGradientBrush.GradientStops>
                <GradientStopCollection>
                  <GradientStop Color="{DynamicResource BorderLightColor}"
                                Offset="0.0" />
                  <GradientStop Color="{DynamicResource BorderDarkColor}"
                                Offset="1.0" />
                </GradientStopCollection>
              </LinearGradientBrush.GradientStops>
            </LinearGradientBrush>
          </Border.BorderBrush>
          <Border.Background>
            <LinearGradientBrush StartPoint="0,0"
                                 EndPoint="0,1">
              <LinearGradientBrush.GradientStops>
                <GradientStopCollection>
                  <GradientStop Color="{DynamicResource ControlLightColor}"
                                Offset="0.0" />
                  <GradientStop Color="{DynamicResource ControlMediumColor}"
                                Offset="1.0" />
                </GradientStopCollection>
              </LinearGradientBrush.GradientStops>
            </LinearGradientBrush>

          </Border.Background>
          <ItemsPresenter />
        </Border>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<Style x:Key="{x:Static StatusBar.SeparatorStyleKey}"
       TargetType="{x:Type Separator}">
  <Setter Property="OverridesDefaultStyle"
          Value="True" />
  <Setter Property="SnapsToDevicePixels"
          Value="True" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type Separator}">
        <Rectangle Width="1"
                   Margin="3">
          <Rectangle.Fill>
            <SolidColorBrush Color="{DynamicResource BorderMediumColor}" />
          </Rectangle.Fill>
        </Rectangle>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<Style x:Key="{x:Type StatusBarItem}"
       TargetType="{x:Type StatusBarItem}">
  <Setter Property="OverridesDefaultStyle"
          Value="True" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type StatusBarItem}">
        <ContentPresenter Margin="3"
                          Name="ContentSite" />
        <ControlTemplate.Triggers>
          <Trigger Property="IsEnabled"
                   Value="false">
            <Setter Property="Foreground">
              <Setter.Value>
                <SolidColorBrush Color="{StaticResource DisabledForegroundColor}" />
              </Setter.Value>
            </Setter>
          </Trigger>
        </ControlTemplate.Triggers>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)使用一个或多个以下资源。



```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [TabControl Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/tabcontrol-styles-and-templates)

本主题介绍的样式和模板的[TabControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tabcontrol)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### Tabcontrol 控件部件

下表列出了用于命名的部件[TabControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tabcontrol)控件。

| 部件                     | 类型                                                         | 描述                                                         |
| ------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| PART_SelectedContentHost | [ContentPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter) | 显示当前所选内容的对象[TabItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tabitem)。 |

当您创建[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)有关[TabControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tabcontrol)，模板可能包含[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)内[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)。 ([ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)显示在每个项[TabControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tabcontrol);[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)控件内实现滚动)。 如果[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)不是直接子级[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)，必须授予[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)名称， `ItemsPresenter`。

### Tabcontrol 控件状态

下表列出了的可视状态[TabControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tabcontrol)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 普通             | CommonStates          | 默认状态。                                                   |
| 已禁用           | CommonStates          | 已禁用控件。                                                 |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### TabItem 部件

[TabItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tabitem)控件没有任何命名的部件。

### TabItem 状态

下表列出了的可视状态[TabItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tabitem)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 普通             | CommonStates          | 默认状态。                                                   |
| MouseOver        | CommonStates          | 鼠标指针悬停在控件上。                                       |
| 已禁用           | CommonStates          | 已禁用控件。                                                 |
| 已设定焦点       | FocusStates           | 控件有焦点。                                                 |
| 失去焦点         | FocusStates           | 控件没有焦点。                                               |
| 已选定           | SelectionStates       | 控件被选定。                                                 |
| 未选定           | SelectionStates       | 未选择控件。                                                 |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### TabControl ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)有关[TabControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tabcontrol)和[TabItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tabitem)控件。



```xaml
<Style  TargetType="{x:Type TabControl}">
  <Setter Property="OverridesDefaultStyle"
          Value="True" />
  <Setter Property="SnapsToDevicePixels"
          Value="True" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type TabControl}">
        <Grid KeyboardNavigation.TabNavigation="Local">
          <Grid.RowDefinitions>
            <RowDefinition Height="Auto" />
            <RowDefinition Height="*" />
          </Grid.RowDefinitions>
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="CommonStates">
              <VisualState x:Name="Disabled">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Border.BorderBrush).
                    (SolidColorBrush.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="#FFAAAAAA" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <TabPanel x:Name="HeaderPanel"
                    Grid.Row="0"
                    Panel.ZIndex="1"
                    Margin="0,0,4,-1"
                    IsItemsHost="True"
                    KeyboardNavigation.TabIndex="1"
                    Background="Transparent" />
          <Border x:Name="Border"
                  Grid.Row="1"
                  BorderThickness="1"
                  CornerRadius="2"
                  KeyboardNavigation.TabNavigation="Local"
                  KeyboardNavigation.DirectionalNavigation="Contained"
                  KeyboardNavigation.TabIndex="2">
            <Border.Background>
              <LinearGradientBrush EndPoint="0.5,1"
                                   StartPoint="0.5,0">
                <GradientStop Color="{DynamicResource ContentAreaColorLight}"
                              Offset="0" />
                <GradientStop Color="{DynamicResource ContentAreaColorDark}"
                              Offset="1" />
              </LinearGradientBrush>
            </Border.Background>
            <Border.BorderBrush>
              <SolidColorBrush Color="{DynamicResource BorderMediumColor}"/>
            </Border.BorderBrush>
            <ContentPresenter x:Name="PART_SelectedContentHost"
                              Margin="4"
                              ContentSource="SelectedContent" />
          </Border>
        </Grid>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<Style TargetType="{x:Type TabItem}">
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type TabItem}">
        <Grid x:Name="Root">
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="SelectionStates">
              <VisualState x:Name="Unselected" />
              <VisualState x:Name="Selected">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                    (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlPressedColor}" />
                  </ColorAnimationUsingKeyFrames>
                  <ThicknessAnimationUsingKeyFrames Storyboard.TargetProperty="(Border.BorderThickness)"
                                                    Storyboard.TargetName="Border">
                    <EasingThicknessKeyFrame KeyTime="0"
                                             Value="1,1,1,0" />
                  </ThicknessAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
            <VisualStateGroup x:Name="CommonStates">
              <VisualState x:Name="Normal" />
              <VisualState x:Name="MouseOver" />
              <VisualState x:Name="Disabled">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                    (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource DisabledControlDarkColor}" />
                  </ColorAnimationUsingKeyFrames>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Border.BorderBrush).
                    (SolidColorBrush.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource DisabledBorderLightColor}"/>
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <Border x:Name="Border"
                  Margin="0,0,-4,0"
                  BorderThickness="1,1,1,1"
                  CornerRadius="2,12,0,0">
            <Border.BorderBrush>
              <SolidColorBrush Color="{DynamicResource BorderMediumColor}" />
            </Border.BorderBrush>
            <Border.Background>

              <LinearGradientBrush StartPoint="0,0"
                                   EndPoint="0,1">
                <LinearGradientBrush.GradientStops>
                  <GradientStopCollection>
                    <GradientStop Color="{DynamicResource ControlLightColor}"
                                  Offset="0.0" />
                    <GradientStop Color="{DynamicResource ControlMediumColor}"
                                  Offset="1.0" />
                  </GradientStopCollection>
                </LinearGradientBrush.GradientStops>
              </LinearGradientBrush>

            </Border.Background>
            <ContentPresenter x:Name="ContentSite"
                              VerticalAlignment="Center"
                              HorizontalAlignment="Center"
                              ContentSource="Header"
                              Margin="12,2,12,2"
                              RecognizesAccessKey="True" />
          </Border>
        </Grid>
        <ControlTemplate.Triggers>
          <Trigger Property="IsSelected"
                   Value="True">
            <Setter Property="Panel.ZIndex"
                    Value="100" />
          </Trigger>
        </ControlTemplate.Triggers>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

上一示例使用了一个或多个以下资源。



```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [TextBox Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/textbox-styles-and-templates)

本主题介绍的样式和模板的[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### 文本框部件

下表列出了用于命名的部件[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控件。

| 部件             | 类型                                                         | 描述                                                         |
| ---------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| PART_ContentHost | [FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement) | 可以包含一个可见元素[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)。 文本[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)显示在此元素。 |

### 文本框状态

下表列出了的可视状态[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 普通             | CommonStates          | 默认状态。                                                   |
| MouseOver        | CommonStates          | 鼠标指针悬停在控件上。                                       |
| 已禁用           | CommonStates          | 已禁用控件。                                                 |
| ReadOnly         | CommonStates          | 用户不能更改中的文本[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。 |
| 已设定焦点       | FocusStates           | 控件有焦点。                                                 |
| 失去焦点         | FocusStates           | 控件没有焦点。                                               |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### 文本框 ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)控件。



```xaml
<Style TargetType="{x:Type TextBox}">
  <Setter Property="SnapsToDevicePixels"
          Value="True" />
  <Setter Property="OverridesDefaultStyle"
          Value="True" />
  <Setter Property="KeyboardNavigation.TabNavigation"
          Value="None" />
  <Setter Property="FocusVisualStyle"
          Value="{x:Null}" />
  <Setter Property="MinWidth"
          Value="120" />
  <Setter Property="MinHeight"
          Value="20" />
  <Setter Property="AllowDrop"
          Value="true" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type TextBoxBase}">
        <Border Name="Border"
                CornerRadius="2"
                Padding="2"
                BorderThickness="1">
          <Border.Background>
            <SolidColorBrush Color="{DynamicResource ControlLightColor}" />
          </Border.Background>
          <Border.BorderBrush>
            <SolidColorBrush Color="{DynamicResource BorderMediumColor}" />
          </Border.BorderBrush>
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="CommonStates">
              <VisualState x:Name="Normal" />
              <VisualState x:Name="Disabled">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                    (SolidColorBrush.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource DisabledControlLightColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="ReadOnly">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                    (SolidColorBrush.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource DisabledControlDarkColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="MouseOver" />
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <ScrollViewer Margin="0"
                        x:Name="PART_ContentHost" />
        </Border>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

上一示例使用了一个或多个以下资源。



```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [Thumb Syles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/thumb-syles-and-templates)

本主题介绍的样式和模板的[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### Thumb 部件

[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)控件没有任何命名的部件。

### Thumb 状态

下表列出了的可视状态[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 普通             | CommonStates          | 默认状态。                                                   |
| MouseOver        | CommonStates          | 鼠标指针悬停在控件上方。                                     |
| 已按下           | CommonStates          | 已按下控件。                                                 |
| 已禁用           | CommonStates          | 已禁用控件。                                                 |
| 已设定焦点       | FocusStates           | 控件有焦点。                                                 |
| 失去焦点         | FocusStates           | 控件没有焦点。                                               |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### Thumb 的 ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)控件。



```xaml
<Style x:Key="SliderThumbStyle"
       TargetType="{x:Type Thumb}">
  <Setter Property="SnapsToDevicePixels"
          Value="true" />
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="Height"
          Value="14" />
  <Setter Property="Width"
          Value="14" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type Thumb}">
        <Ellipse x:Name="Ellipse"
                 StrokeThickness="1">
          <Ellipse.Stroke>
            <LinearGradientBrush StartPoint="0,0"
                                 EndPoint="0,1">
              <LinearGradientBrush.GradientStops>
                <GradientStopCollection>
                  <GradientStop Color="{DynamicResource BorderLightColor}"
                                Offset="0.0" />
                  <GradientStop Color="{DynamicResource BorderDarkColor}"
                                Offset="1.0" />
                </GradientStopCollection>
              </LinearGradientBrush.GradientStops>
            </LinearGradientBrush>
          </Ellipse.Stroke>
          <Ellipse.Fill>
            <LinearGradientBrush EndPoint="0.5,1"
                                 StartPoint="0.5,0">
              <GradientStop Color="{DynamicResource ControlMediumColor}"
                            Offset="1" />
              <GradientStop Color="{DynamicResource ControlLightColor}" />
            </LinearGradientBrush>
          </Ellipse.Fill>
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="CommonStates">
              <VisualState x:Name="Normal" />
              <VisualState x:Name="MouseOver">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetProperty="(Shape.Fill).
                    (GradientBrush.GradientStops)[0].(GradientStop.Color)"
                                                Storyboard.TargetName="Ellipse">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlMouseOverColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Pressed">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetProperty="(Shape.Fill).
                    (GradientBrush.GradientStops)[0].(GradientStop.Color)"
                                                Storyboard.TargetName="Ellipse">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlPressedColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Disabled">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetProperty="(Shape.Fill).
                    (GradientBrush.GradientStops)[0].(GradientStop.Color)"
                                                Storyboard.TargetName="Ellipse">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource DisabledControlDarkColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
        </Ellipse>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

上一示例使用了一个或多个以下资源。



```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [ToggleButton Syles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/togglebutton-syles-and-templates)

本主题介绍的样式和模板的[ToggleButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.togglebutton)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### 切换按钮部件

[ToggleButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.togglebutton)控件没有任何命名的部件。

### 切换按钮状态

下表列出了的可视状态[ToggleButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.togglebutton)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 普通             | CommonStates          | 默认状态。                                                   |
| MouseOver        | CommonStates          | 鼠标指针悬停在控件上方。                                     |
| 已按下           | CommonStates          | 已按下控件。                                                 |
| 已禁用           | CommonStates          | 已禁用控件。                                                 |
| 已设定焦点       | FocusStates           | 控件有焦点。                                                 |
| 失去焦点         | FocusStates           | 控件没有焦点。                                               |
| 已选中           | CheckStates           | [IsChecked](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.togglebutton.ischecked) 为 `true`。 |
| 未选中状态       | CheckStates           | [IsChecked](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.togglebutton.ischecked) 为 `false`。 |
| 不确定           | CheckStates           | [IsThreeState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.togglebutton.isthreestate) 是`true`，并[IsChecked](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.togglebutton.ischecked)是`null`。 |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

> 如果您的控件模板中不存在的不确定的可视状态，未选中状态的可视状态将用作默认可视状态。

### 切换按钮 ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[ToggleButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.togglebutton)控件。



```xaml
<ControlTemplate x:Key="ComboBoxToggleButton"
                 TargetType="{x:Type ToggleButton}">
  <Grid>
    <Grid.ColumnDefinitions>
      <ColumnDefinition />
      <ColumnDefinition Width="20" />
    </Grid.ColumnDefinitions>
    <VisualStateManager.VisualStateGroups>
      <VisualStateGroup x:Name="CommonStates">
        <VisualState x:Name="Normal" />
        <VisualState x:Name="MouseOver">
          <Storyboard>
            <ColorAnimationUsingKeyFrames Storyboard.TargetProperty="(Panel.Background).
                (GradientBrush.GradientStops)[1].(GradientStop.Color)"
                                          Storyboard.TargetName="Border">
              <EasingColorKeyFrame KeyTime="0"
                                   Value="{StaticResource ControlMouseOverColor}" />
            </ColorAnimationUsingKeyFrames>
          </Storyboard>
        </VisualState>
        <VisualState x:Name="Pressed" />
        <VisualState x:Name="Disabled">
          <Storyboard>
            <ColorAnimationUsingKeyFrames Storyboard.TargetProperty="(Panel.Background).
                (GradientBrush.GradientStops)[1].(GradientStop.Color)"
                                          Storyboard.TargetName="Border">
              <EasingColorKeyFrame KeyTime="0"
                                   Value="{StaticResource DisabledControlDarkColor}" />
            </ColorAnimationUsingKeyFrames>
            <ColorAnimationUsingKeyFrames Storyboard.TargetProperty="(Shape.Fill).
                (SolidColorBrush.Color)"
                                          Storyboard.TargetName="Arrow">
              <EasingColorKeyFrame KeyTime="0"
                                   Value="{StaticResource DisabledForegroundColor}" />
            </ColorAnimationUsingKeyFrames>
            <ColorAnimationUsingKeyFrames Storyboard.TargetProperty="(Border.BorderBrush).
                (GradientBrush.GradientStops)[1].(GradientStop.Color)"
                                          Storyboard.TargetName="Border">
              <EasingColorKeyFrame KeyTime="0"
                                   Value="{StaticResource DisabledBorderDarkColor}" />
            </ColorAnimationUsingKeyFrames>
          </Storyboard>
        </VisualState>
      </VisualStateGroup>
      <VisualStateGroup x:Name="CheckStates">
        <VisualState x:Name="Checked">
          <Storyboard>
            <ColorAnimationUsingKeyFrames Storyboard.TargetProperty="(Panel.Background).
                (GradientBrush.GradientStops)[1].(GradientStop.Color)"
                                          Storyboard.TargetName="Border">
              <EasingColorKeyFrame KeyTime="0"
                                   Value="{StaticResource ControlPressedColor}" />
            </ColorAnimationUsingKeyFrames>
          </Storyboard>
        </VisualState>
        <VisualState x:Name="Unchecked" />
        <VisualState x:Name="Indeterminate" />
      </VisualStateGroup>
    </VisualStateManager.VisualStateGroups>
    <Border x:Name="Border"
            Grid.ColumnSpan="2"
            CornerRadius="2"
            BorderThickness="1">
      <Border.BorderBrush>
        <LinearGradientBrush EndPoint="0,1"
                             StartPoint="0,0">
          <GradientStop Color="{DynamicResource BorderLightColor}"
                        Offset="0" />
          <GradientStop Color="{DynamicResource BorderDarkColor}"
                        Offset="1" />
        </LinearGradientBrush>
      </Border.BorderBrush>
      <Border.Background>

        <LinearGradientBrush StartPoint="0,0"
                             EndPoint="0,1">
          <LinearGradientBrush.GradientStops>
            <GradientStopCollection>
              <GradientStop Color="{DynamicResource ControlLightColor}" />
              <GradientStop Color="{DynamicResource ControlMediumColor}"
                            Offset="1.0" />
            </GradientStopCollection>
          </LinearGradientBrush.GradientStops>
        </LinearGradientBrush>

      </Border.Background>
    </Border>
    <Border Grid.Column="0"
            CornerRadius="2,0,0,2"
            Margin="1" >
      <Border.Background>
          <SolidColorBrush Color="{DynamicResource ControlLightColor}"/>
      </Border.Background>
    </Border>
    <Path x:Name="Arrow"
          Grid.Column="1"
          HorizontalAlignment="Center"
          VerticalAlignment="Center"
          Data="M 0 0 L 4 4 L 8 0 Z" >
      <Path.Fill>
          <SolidColorBrush Color="{DynamicResource GlyphColor}"/>
      </Path.Fill>
    </Path>
  </Grid>
</ControlTemplate>
```

上一示例使用了一个或多个以下资源。



```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [ToolBar Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/toolbar-styles-and-templates)

本主题介绍的样式和模板的[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### 工具栏部件

下表列出了用于命名的部件[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)控件。

| 部件                      | 类型                                                         | 描述                                                         |
| ------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| PART_ToolBarPanel         | [ToolBarPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.toolbarpanel) | 包含的控件的对象[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)。 |
| PART_ToolBarOverflowPanel | [ToolBarOverflowPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.toolbaroverflowpanel) | 对象，包含控件中的溢出区域的[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)。 |

当您创建[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)有关[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)，模板可能包含[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)内[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)。 ([ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)显示在每个项[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar);[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)控件内实现滚动)。 如果[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)不是直接子级[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)，必须授予[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)名称， `ItemsPresenter`。

### 工具栏状态

下表列出了的可视状态[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### 工具栏 ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)控件。



```xaml
<Style x:Key="ToolBarButtonBaseStyle"
       TargetType="{x:Type ButtonBase}">
  <Setter Property="SnapsToDevicePixels"
          Value="true" />
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type ButtonBase}">
        <Border x:Name="Border"
                BorderThickness="1">
          <Border.BorderBrush>
            <LinearGradientBrush EndPoint="0.5,1"
                                 StartPoint="0.5,0">
              <GradientStop Color="{DynamicResource BorderLightColor}"
                            Offset="0" />
              <GradientStop Color="{DynamicResource BorderMediumColor}"
                            Offset="1" />
            </LinearGradientBrush>
          </Border.BorderBrush>
          <Border.Background>
            <LinearGradientBrush EndPoint="0.5,1"
                                 StartPoint="0.5,0">
              <GradientStop Color="{DynamicResource ControlLightColor}"
                            Offset="0" />
              <GradientStop Color="{DynamicResource ControlMediumColor}"
                            Offset="1" />
            </LinearGradientBrush>
          </Border.Background>
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="CommonStates">
              <VisualState x:Name="Normal" />
              <VisualState x:Name="Pressed">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                    (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlPressedColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="MouseOver">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                    (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlMouseOverColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Disabled">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Panel.Background). 
                    (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource DisabledControlDarkColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
            <VisualStateGroup x:Name="CheckStates">
              <VisualState x:Name="Checked">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Panel.Background).
                    (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlPressedColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Unchecked" />
              <VisualState x:Name="Indeterminate" />
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <ContentPresenter Margin="2"
                            HorizontalAlignment="Center"
                            VerticalAlignment="Center"
                            RecognizesAccessKey="True" />
        </Border>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<Style x:Key="{x:Static ToolBar.ButtonStyleKey}"
       BasedOn="{StaticResource ToolBarButtonBaseStyle}"
       TargetType="{x:Type Button}" />
<Style x:Key="{x:Static ToolBar.ToggleButtonStyleKey}"
       BasedOn="{StaticResource ToolBarButtonBaseStyle}"
       TargetType="{x:Type ToggleButton}" />
<Style x:Key="{x:Static ToolBar.CheckBoxStyleKey}"
       BasedOn="{StaticResource ToolBarButtonBaseStyle}"
       TargetType="{x:Type CheckBox}" />
<Style x:Key="{x:Static ToolBar.RadioButtonStyleKey}"
       BasedOn="{StaticResource ToolBarButtonBaseStyle}"
       TargetType="{x:Type RadioButton}" />

<Style x:Key="{x:Static ToolBar.TextBoxStyleKey}"
       TargetType="{x:Type TextBox}">
  <Setter Property="SnapsToDevicePixels"
          Value="True" />
  <Setter Property="OverridesDefaultStyle"
          Value="True" />
  <Setter Property="KeyboardNavigation.TabNavigation"
          Value="None" />
  <Setter Property="FocusVisualStyle"
          Value="{x:Null}" />
  <Setter Property="AllowDrop"
          Value="true" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type TextBox}">
        <Border x:Name="Border"
                Padding="2"
                BorderThickness="1">
          <Border.Background>
            <SolidColorBrush Color="{DynamicResource ControlLightColor}" />
          </Border.Background>
          <Border.BorderBrush>
            <SolidColorBrush Color="{StaticResource BorderMediumColor}" />
          </Border.BorderBrush>
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="CommonStates">
              <VisualState x:Name="Normal" />
              <VisualState x:Name="Disabled">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Panel.Background).  
                    (SolidColorBrush.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource DisabledControlDarkColor}" />
                  </ColorAnimationUsingKeyFrames>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Border.BorderBrush).  
                    (SolidColorBrush.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource DisabledBorderLightColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="ReadOnly" />
              <VisualState x:Name="MouseOver" />
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <ScrollViewer Margin="0"
                        x:Name="PART_ContentHost" />
        </Border>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<Style x:Key="ToolBarThumbStyle"
       TargetType="{x:Type Thumb}">
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="Cursor"
          Value="SizeAll" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type Thumb}">
        <Border Background="Transparent"
                SnapsToDevicePixels="True">
          <Rectangle Margin="0,2">
            <Rectangle.Fill>
              <DrawingBrush Viewport="0,0,4,4"
                            ViewportUnits="Absolute"
                            Viewbox="0,0,8,8"
                            ViewboxUnits="Absolute"
                            TileMode="Tile">
                <DrawingBrush.Drawing>
                  <DrawingGroup>
                    <GeometryDrawing Brush="#AAA"
                                     Geometry="M 4 4 L 4 8 L 8 8 L 8 4 z" />
                  </DrawingGroup>
                </DrawingBrush.Drawing>
              </DrawingBrush>
            </Rectangle.Fill>
          </Rectangle>
        </Border>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<Style x:Key="ToolBarOverflowButtonStyle"
       TargetType="{x:Type ToggleButton}">
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type ToggleButton}">
        <Border x:Name="Border"
                CornerRadius="0,3,3,0"
                SnapsToDevicePixels="true">
          <Border.Background>
            <LinearGradientBrush EndPoint="0.5,1"
                                 StartPoint="0.5,0">
              <GradientStop Color="#00000000"
                            Offset="0" />
              <GradientStop Offset="1" />
            </LinearGradientBrush>
          </Border.Background>
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="CommonStates">
              <VisualState x:Name="Normal" />
              <VisualState x:Name="Pressed">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Panel.Background).    
                    (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlPressedColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="MouseOver">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Panel.Background).     
                    (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource ControlMouseOverColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Disabled">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Border"
                                                Storyboard.TargetProperty="(Panel.Background).   
                    (GradientBrush.GradientStops)[1].(GradientStop.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource DisabledBorderLightColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <Grid>
            <Path x:Name="Arrow"
                  Fill="Black"
                  VerticalAlignment="Bottom"
                  Margin="2,3"
                  Data="M -0.5 3 L 5.5 3 L 2.5 6 Z" />
            <ContentPresenter />
          </Grid>
        </Border>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<Style x:Key="{x:Type ToolBar}"
       TargetType="{x:Type ToolBar}">
  <Setter Property="SnapsToDevicePixels"
          Value="true" />
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type ToolBar}">
        <Border x:Name="Border"
                CornerRadius="2"
                BorderThickness="1">
          <Border.BorderBrush>
            <LinearGradientBrush StartPoint="0,0"
                                 EndPoint="0,1">
              <LinearGradientBrush.GradientStops>
                <GradientStopCollection>
                  <GradientStop Color="{DynamicResource BorderMediumColor}"
                                Offset="0.0" />
                  <GradientStop Color="{DynamicResource BorderDarkColor}"
                                Offset="1.0" />
                </GradientStopCollection>
              </LinearGradientBrush.GradientStops>
            </LinearGradientBrush>
          </Border.BorderBrush>

          <Border.Background>
            <LinearGradientBrush StartPoint="0,0"
                                 EndPoint="0,1">
              <LinearGradientBrush.GradientStops>
                <GradientStopCollection>
                  <GradientStop Color="#FFF"
                                Offset="0.0" />
                  <GradientStop Color="{DynamicResource ControlMediumColor}"
                                Offset="1.0" />
                </GradientStopCollection>
              </LinearGradientBrush.GradientStops>
            </LinearGradientBrush>
          </Border.Background>
          <DockPanel>
            <ToggleButton DockPanel.Dock="Right"
                          IsEnabled="{TemplateBinding HasOverflowItems}"
                          Style="{StaticResource ToolBarOverflowButtonStyle}"
                          ClickMode="Press"
                          IsChecked="{Binding IsOverflowOpen, Mode=TwoWay, 
              RelativeSource={RelativeSource TemplatedParent}}">
              <Popup x:Name="OverflowPopup"
                     AllowsTransparency="true"
                     Placement="Bottom"
                     StaysOpen="false"
                     Focusable="false"
                     PopupAnimation="Slide"
                     IsOpen="{Binding IsOverflowOpen, 
                RelativeSource={RelativeSource TemplatedParent}}">
                <Border x:Name="DropDownBorder"
                        BorderThickness="1">
                  <Border.BorderBrush>
                    <SolidColorBrush Color="{DynamicResource BorderMediumColor}" />
                  </Border.BorderBrush>
                  <Border.Background>
                    <LinearGradientBrush EndPoint="0.5,1"
                                         StartPoint="0.5,0">
                      <GradientStop Color="{DynamicResource ControlLightColor}" />
                      <GradientStop Color="{DynamicResource ControlMediumColor}"
                                    Offset="1" />
                    </LinearGradientBrush>
                  </Border.Background>
                  <ToolBarOverflowPanel x:Name="PART_ToolBarOverflowPanel"
                                        Margin="2"
                                        WrapWidth="200"
                                        Focusable="true"
                                        FocusVisualStyle="{x:Null}"
                                        KeyboardNavigation.TabNavigation="Cycle"
                                        KeyboardNavigation.DirectionalNavigation="Cycle" />
                </Border>
              </Popup>
            </ToggleButton>

            <Thumb x:Name="ToolBarThumb"
                   Style="{StaticResource ToolBarThumbStyle}"
                   Width="10" />
            <ToolBarPanel x:Name="PART_ToolBarPanel"
                          IsItemsHost="true"
                          Margin="0,1,2,2" />
          </DockPanel>
        </Border>
        <ControlTemplate.Triggers>
          <Trigger Property="IsOverflowOpen"
                   Value="true">
            <Setter TargetName="ToolBarThumb"
                    Property="IsEnabled"
                    Value="false" />
          </Trigger>
          <Trigger Property="ToolBarTray.IsLocked"
                   Value="true">
            <Setter TargetName="ToolBarThumb"
                    Property="Visibility"
                    Value="Collapsed" />
          </Trigger>
        </ControlTemplate.Triggers>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<Style x:Key="{x:Type ToolBarTray}"
       TargetType="{x:Type ToolBarTray}">
  <Setter Property="Background">
    <Setter.Value>
      <LinearGradientBrush StartPoint="0,0"
                           EndPoint="1,0">
        <LinearGradientBrush.GradientStops>
          <GradientStopCollection>
            <GradientStop Color="#FFF"
                          Offset="0.0" />
            <GradientStop Color="{DynamicResource WindowColor}"
                          Offset="1.0" />
          </GradientStopCollection>
        </LinearGradientBrush.GradientStops>
      </LinearGradientBrush>
    </Setter.Value>
  </Setter>
</Style>
```

上一示例使用了一个或多个以下资源。



```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [ToolTip Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/tooltip-styles-and-templates)

本主题介绍的样式和模板的[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### 工具提示部分

[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)控件没有任何命名的部件。

### 工具提示的状态

下表列出了的可视状态[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| Closed           | OpenStates            | 默认状态。                                                   |
| 打开             | OpenStates            | [ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)可见。 |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### 工具提示的 ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)控件。



```xaml
<Style x:Key="{x:Type ToolTip}"
       TargetType="ToolTip">
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="HasDropShadow"
          Value="True" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="ToolTip">
        <Border Name="Border"
                BorderThickness="1"
                Width="{TemplateBinding Width}"
                Height="{TemplateBinding Height}">
          <Border.Background>
            <LinearGradientBrush StartPoint="0,0"
                                 EndPoint="0,1">
              <LinearGradientBrush.GradientStops>
                <GradientStopCollection>
                  <GradientStop Color="{DynamicResource ControlLightColor}"
                                Offset="0.0" />
                  <GradientStop Color="{DynamicResource ControlMediumColor}"
                                Offset="1.0" />
                </GradientStopCollection>
              </LinearGradientBrush.GradientStops>
            </LinearGradientBrush>

          </Border.Background>
          <Border.BorderBrush>
            <SolidColorBrush Color="{DynamicResource BorderMediumColor}" />
          </Border.BorderBrush>
          <ContentPresenter Margin="4"
                            HorizontalAlignment="Left"
                            VerticalAlignment="Top" />
        </Border>
        <ControlTemplate.Triggers>
          <Trigger Property="HasDropShadow"
                   Value="true">
            <Setter TargetName="Border"
                    Property="CornerRadius"
                    Value="4" />
            <Setter TargetName="Border"
                    Property="SnapsToDevicePixels"
                    Value="true" />
          </Trigger>
        </ControlTemplate.Triggers>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

上一示例使用了一个或多个以下资源。



```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [TreeView Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/treeview-styles-and-templates)

本主题介绍的样式和模板的[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### 树视图部分

[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)控件没有任何命名的部件。

当您创建[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)有关[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)，模板可能包含[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)内[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)。 ([ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)显示在每个项[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview);[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)控件内实现滚动)。 如果[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)不是直接子级[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)，必须授予[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)名称， `ItemsPresenter`。

### 树视图状态

下表列出了的可视状态[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### TreeViewItem 部件

下表列出了用于命名的部件[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)控件。

| 部件        | 类型                                                         | 描述                                                         |
| ----------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| PART_Header | [FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement) | 一个可包含的标头内容的可见元素[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)控件。 |

### TreeViewItem 状态

下表列出了的可视状态[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 普通             | CommonStates          | 默认状态。                                                   |
| MouseOver        | CommonStates          | 鼠标指针置于[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)。 |
| 已禁用           | CommonStates          | [TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)被禁用。 |
| 已设定焦点       | FocusStates           | [TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)具有焦点。 |
| 失去焦点         | FocusStates           | [TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)不具有焦点。 |
| 已展开           | ExpansionStates       | [TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)是否展开控件。 |
| Collapsed        | ExpansionStates       | [TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)控件处于折叠状态。 |
| HasItems         | HasItemsStates        | [TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)具有项。 |
| NoItems          | HasItemsStates        | [TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)没有项。 |
| 已选定           | SelectionStates       | [TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)处于选中状态。 |
| SelectedInactive | SelectionStates       | [TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)是已选定但未处于活动状态。 |
| 未选定           | SelectionStates       | [TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)未选中。 |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### TreeView ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)控件和其关联的类型。



```xaml
<Style x:Key="{x:Type TreeView}"
       TargetType="TreeView">
  <Setter Property="OverridesDefaultStyle"
          Value="True" />
  <Setter Property="SnapsToDevicePixels"
          Value="True" />
  <Setter Property="ScrollViewer.HorizontalScrollBarVisibility"
          Value="Auto" />
  <Setter Property="ScrollViewer.VerticalScrollBarVisibility"
          Value="Auto" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="TreeView">
        <Border Name="Border"
                CornerRadius="1"
                BorderThickness="1">
          <Border.BorderBrush>
            <SolidColorBrush Color="{DynamicResource BorderMediumColor}" />
          </Border.BorderBrush>
          <Border.Background>
            <SolidColorBrush Color="{DynamicResource ControlLightColor}" />
          </Border.Background>
          <ScrollViewer Focusable="False"
                        CanContentScroll="False"
                        Padding="4">
            <ItemsPresenter />
          </ScrollViewer>
        </Border>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>

<Style x:Key="ExpandCollapseToggleStyle"
       TargetType="ToggleButton">
  <Setter Property="Focusable"
          Value="False" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="ToggleButton">
        <Grid Width="15"
              Height="13"
              Background="Transparent">
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="CheckStates">
              <VisualState x:Name="Checked">
                <Storyboard>
                  <ObjectAnimationUsingKeyFrames Storyboard.TargetProperty="(UIElement.Visibility)"
                                                 Storyboard.TargetName="Collapsed">
                    <DiscreteObjectKeyFrame KeyTime="0"
                                            Value="{x:Static Visibility.Hidden}" />
                  </ObjectAnimationUsingKeyFrames>
                  <ObjectAnimationUsingKeyFrames Storyboard.TargetProperty="(UIElement.Visibility)"
                                                 Storyboard.TargetName="Expanded">
                    <DiscreteObjectKeyFrame KeyTime="0"
                                            Value="{x:Static Visibility.Visible}" />
                  </ObjectAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Unchecked" />
              <VisualState x:Name="Indeterminate" />
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <Path x:Name="Collapsed"
                HorizontalAlignment="Left"
                VerticalAlignment="Center"
                Margin="1,1,1,1"
                Data="M 4 0 L 8 4 L 4 8 Z">
            <Path.Fill>
              <SolidColorBrush Color="{DynamicResource GlyphColor}" />
            </Path.Fill>
          </Path>
          <Path x:Name="Expanded"
                HorizontalAlignment="Left"
                VerticalAlignment="Center"
                Margin="1,1,1,1"
                Data="M 0 4 L 8 4 L 4 8 Z"
                Visibility="Hidden">
            <Path.Fill>
              <SolidColorBrush Color="{DynamicResource GlyphColor}" />
            </Path.Fill>
          </Path>
        </Grid>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
<Style x:Key="TreeViewItemFocusVisual">
  <Setter Property="Control.Template">
    <Setter.Value>
      <ControlTemplate>
        <Border>
          <Rectangle Margin="0,0,0,0"
                     StrokeThickness="5"
                     Stroke="Black"
                     StrokeDashArray="1 2"
                     Opacity="0" />
        </Border>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
<Style x:Key="{x:Type TreeViewItem}"
       TargetType="{x:Type TreeViewItem}">
  <Setter Property="Background"
          Value="Transparent" />
  <Setter Property="HorizontalContentAlignment"
          Value="{Binding Path=HorizontalContentAlignment,
    RelativeSource={RelativeSource AncestorType={x:Type ItemsControl}}}" />
  <Setter Property="VerticalContentAlignment"
          Value="{Binding Path=VerticalContentAlignment,
    RelativeSource={RelativeSource AncestorType={x:Type ItemsControl}}}" />
  <Setter Property="Padding"
          Value="1,0,0,0" />
  <Setter Property="Foreground"
          Value="{DynamicResource {x:Static SystemColors.ControlTextBrushKey}}" />
  <Setter Property="FocusVisualStyle"
          Value="{StaticResource TreeViewItemFocusVisual}" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type TreeViewItem}">
        <Grid>
          <Grid.ColumnDefinitions>
            <ColumnDefinition MinWidth="19"
                              Width="Auto" />
            <ColumnDefinition Width="Auto" />
            <ColumnDefinition Width="*" />
          </Grid.ColumnDefinitions>
          <Grid.RowDefinitions>
            <RowDefinition Height="Auto" />
            <RowDefinition />
          </Grid.RowDefinitions>
          <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="SelectionStates">
              <VisualState x:Name="Selected">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Bd"
                                                Storyboard.TargetProperty="(Panel.Background).
                    (SolidColorBrush.Color)"
                                                >
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource SelectedBackgroundColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Unselected" />
              <VisualState x:Name="SelectedInactive">
                <Storyboard>
                  <ColorAnimationUsingKeyFrames Storyboard.TargetName="Bd"
                                                Storyboard.TargetProperty="(Panel.Background).
                    (SolidColorBrush.Color)">
                    <EasingColorKeyFrame KeyTime="0"
                                         Value="{StaticResource SelectedUnfocusedColor}" />
                  </ColorAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
            </VisualStateGroup>
            <VisualStateGroup x:Name="ExpansionStates">
              <VisualState x:Name="Expanded">
                <Storyboard>
                  <ObjectAnimationUsingKeyFrames Storyboard.TargetProperty="(UIElement.Visibility)"
                                                 Storyboard.TargetName="ItemsHost">
                    <DiscreteObjectKeyFrame KeyTime="0"
                                            Value="{x:Static Visibility.Visible}" />
                  </ObjectAnimationUsingKeyFrames>
                </Storyboard>
              </VisualState>
              <VisualState x:Name="Collapsed" />
            </VisualStateGroup>
          </VisualStateManager.VisualStateGroups>
          <ToggleButton x:Name="Expander"
                        Style="{StaticResource ExpandCollapseToggleStyle}"
                        ClickMode="Press"
                        IsChecked="{Binding IsExpanded, 
            RelativeSource={RelativeSource TemplatedParent}}"/>
          <Border x:Name="Bd"
                  Grid.Column="1"
                  Background="{TemplateBinding Background}"
                  BorderBrush="{TemplateBinding BorderBrush}"
                  BorderThickness="{TemplateBinding BorderThickness}"
                  Padding="{TemplateBinding Padding}">
            <ContentPresenter x:Name="PART_Header"
                              ContentSource="Header"
                              HorizontalAlignment="{TemplateBinding HorizontalContentAlignment}"/>
          </Border>
          <ItemsPresenter x:Name="ItemsHost"
                          Grid.Row="1"
                          Grid.Column="1"
                          Grid.ColumnSpan="2"
                          Visibility="Collapsed" />
        </Grid>
        <ControlTemplate.Triggers>
          <Trigger Property="HasItems"
                   Value="false">
            <Setter TargetName="Expander"
                    Property="Visibility"
                    Value="Hidden" />
          </Trigger>
          <MultiTrigger>
            <MultiTrigger.Conditions>
              <Condition Property="HasHeader"
                         Value="false" />
              <Condition Property="Width"
                         Value="Auto" />
            </MultiTrigger.Conditions>
            <Setter TargetName="PART_Header"
                    Property="MinWidth"
                    Value="75" />
          </MultiTrigger>
          <MultiTrigger>
            <MultiTrigger.Conditions>
              <Condition Property="HasHeader"
                         Value="false" />
              <Condition Property="Height"
                         Value="Auto" />
            </MultiTrigger.Conditions>
            <Setter TargetName="PART_Header"
                    Property="MinHeight"
                    Value="19" />
          </MultiTrigger>
        </ControlTemplate.Triggers>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

上一示例使用了一个或多个以下资源。



```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

## [Window Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/window-styles-and-templates)

本主题介绍的样式和模板的[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)控件。 可以修改默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为控件提供唯一外观。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### 窗口部分

[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)控件没有任何命名的部件。

### 窗口状态

下表列出了的可视状态[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)控件。

| VisualState 名称 | VisualStateGroup 名称 | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ |
| 有效             | ValidationStates      | 该控件使用[Validation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation)类和[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`false`。 |
| InvalidFocused   | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`已在控件有焦点。 |
| InvalidUnfocused | ValidationStates      | [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)附加的属性是`true`具有该控件没有焦点。 |

### 窗口 ControlTemplate 示例

下面的示例演示如何定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)控件。

```xaml
<Style x:Key="{x:Type Window}"
       TargetType="{x:Type Window}">
  <Setter Property="SnapsToDevicePixels"
          Value="true" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type Window}">
        <Grid>
          <Grid.Background>
            <SolidColorBrush Color="{DynamicResource WindowColor}"/>
          </Grid.Background>
          <AdornerDecorator>
            <ContentPresenter />
          </AdornerDecorator>
          <ResizeGrip x:Name="WindowResizeGrip"
                      HorizontalAlignment="Right"
                      VerticalAlignment="Bottom"
                      Visibility="Collapsed"
                      IsTabStop="false" />
        </Grid>
        <ControlTemplate.Triggers>
          <Trigger Property="ResizeMode"
                   Value="CanResizeWithGrip">
            <Setter TargetName="WindowResizeGrip"
                    Property="Visibility"
                    Value="Visible" />
          </Trigger>
        </ControlTemplate.Triggers>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)使用一个或多个以下资源。



```xaml
<Style x:Key="{x:Type ResizeGrip}"
       TargetType="{x:Type ResizeGrip}">
  <Setter Property="OverridesDefaultStyle"
          Value="true" />
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type ResizeGrip}">
        <Border Background="Transparent"
                SnapsToDevicePixels="True"
                Width="16"
                Height="16">
          <Rectangle Margin="2">
            <Rectangle.Fill>
              <DrawingBrush Viewport="0,0,4,4"
                            ViewportUnits="Absolute"
                            Viewbox="0,0,8,8"
                            ViewboxUnits="Absolute"
                            TileMode="Tile">
                <DrawingBrush.Drawing>
                  <DrawingGroup>
                    <DrawingGroup.Children>
                      <GeometryDrawing Brush="#FFE8EDF9"
                                       Geometry="M 4 4 L 4 8 L 
                                                 8 8 L 8 4 z" />
                    </DrawingGroup.Children>
                  </DrawingGroup>
                </DrawingBrush.Drawing>
              </DrawingBrush>
            </Rectangle.Fill>
          </Rectangle>
        </Border>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```



```xaml
<!--Control colors.-->
<Color x:Key="WindowColor">#FFE8EDF9</Color>
<Color x:Key="ContentAreaColorLight">#FFC5CBF9</Color>
<Color x:Key="ContentAreaColorDark">#FF7381F9</Color>

<Color x:Key="DisabledControlLightColor">#FFE8EDF9</Color>
<Color x:Key="DisabledControlDarkColor">#FFC5CBF9</Color>
<Color x:Key="DisabledForegroundColor">#FF888888</Color>

<Color x:Key="SelectedBackgroundColor">#FFC5CBF9</Color>
<Color x:Key="SelectedUnfocusedColor">#FFDDDDDD</Color>

<Color x:Key="ControlLightColor">White</Color>
<Color x:Key="ControlMediumColor">#FF7381F9</Color>
<Color x:Key="ControlDarkColor">#FF211AA9</Color>

<Color x:Key="ControlMouseOverColor">#FF3843C4</Color>
<Color x:Key="ControlPressedColor">#FF211AA9</Color>


<Color x:Key="GlyphColor">#FF444444</Color>
<Color x:Key="GlyphMouseOver">sc#1, 0.004391443, 0.002428215, 0.242281124</Color>

<!--Border colors-->
<Color x:Key="BorderLightColor">#FFCCCCCC</Color>
<Color x:Key="BorderMediumColor">#FF888888</Color>
<Color x:Key="BorderDarkColor">#FF444444</Color>

<Color x:Key="PressedBorderLightColor">#FF888888</Color>
<Color x:Key="PressedBorderDarkColor">#FF444444</Color>

<Color x:Key="DisabledBorderLightColor">#FFAAAAAA</Color>
<Color x:Key="DisabledBorderDarkColor">#FF888888</Color>

<Color x:Key="DefaultBorderBrushDarkColor">Black</Color>

<!--Control-specific resources.-->
<Color x:Key="HeaderTopColor">#FFC5CBF9</Color>
<Color x:Key="DatagridCurrentCellBorderColor">Black</Color>
<Color x:Key="SliderTrackDarkColor">#FFC5CBF9</Color>

<Color x:Key="NavButtonFrameColor">#FF3843C4</Color>

<LinearGradientBrush x:Key="MenuPopupBrush"
                     EndPoint="0.5,1"
                     StartPoint="0.5,0">
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="0" />
  <GradientStop Color="{DynamicResource ControlMediumColor}"
                Offset="0.5" />
  <GradientStop Color="{DynamicResource ControlLightColor}"
                Offset="1" />
</LinearGradientBrush>

<LinearGradientBrush x:Key="ProgressBarIndicatorAnimatedFill"
                     StartPoint="0,0"
                     EndPoint="1,0">
  <LinearGradientBrush.GradientStops>
    <GradientStopCollection>
      <GradientStop Color="#000000FF"
                    Offset="0" />
      <GradientStop Color="#600000FF"
                    Offset="0.4" />
      <GradientStop Color="#600000FF"
                    Offset="0.6" />
      <GradientStop Color="#000000FF"
                    Offset="1" />
    </GradientStopCollection>
  </LinearGradientBrush.GradientStops>
</LinearGradientBrush>
```

有关完整示例，请参阅[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。