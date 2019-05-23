# [Creating a Control That Has a Customizable Appearance](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/creating-a-control-that-has-a-customizable-appearance)

Windows Presentation Foundation (WPF) 使您能够创建可自定义其外观的控件。 例如，可以更改的外观[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)超越设置属性即可通过创建一个新[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。 如下图所示[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)使用的默认值[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)和一个[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)使用自定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。

![一个具有默认控件模板的复选框。](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/ndp-checkboxdefault.png)
一个具有默认控件模板的复选框

![一个具有自定义控件模板的复选框。](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/ndp-checkboxcustom.png)
一个具有自定义控件模板的复选框

如果您遵循部件和状态模型时创建的控件，，将可自定义控件的外观。 如 Microsoft Expression Blend 设计器工具支持的部件和状态的模型，因此您的控件时请遵循此模型将是可自定义这些类型的应用程序中。 本主题讨论的部件和状态的模型以及如何创建自己的控件时遵循它。 本主题使用的自定义控件示例`NumericUpDown`，来说明此模型的基本原理。 `NumericUpDown`控件中显示数字值，用户可以增加或减少，方法是单击该控件的按钮上显示。 下图显示`NumericUpDown`本主题中讨论的控件。

![NumericUpDown 自定义控件。](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/ndp-numericupdown.png)
自定义的 NumericUpDown 控件

本主题包含以下各节：

- [系统必备](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/creating-a-control-that-has-a-customizable-appearance#prerequisites)
- [部件和状态模型](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/creating-a-control-that-has-a-customizable-appearance#parts_and_states_model)
- [在 ControlTemplate 中定义的可视结构和控件的可视行为](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/creating-a-control-that-has-a-customizable-appearance#defining_the_visual_structure_and_visual_behavior_of_a_control_in_a_controltemplate)
- [使用在代码中的 ControlTemplate 部件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/creating-a-control-that-has-a-customizable-appearance#using_parts_of_the_controltemplate_in_code)
- [提供控件协定](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/creating-a-control-that-has-a-customizable-appearance#providing_the_control_contract)
- [完整示例](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/creating-a-control-that-has-a-customizable-appearance#complete_example)



## 系统必备

本主题假定你知道如何创建一个新[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为现有控件，使用者熟悉控件协定上的元素是什么，并了解中讨论的概念[自定义现有控件的外观创建 ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

 备注

若要创建可以具有自定义其外观的控件，必须创建继承的控件[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)类或它的某个子类以外的其他[UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol)。 继承的控件[UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol)是一个控件，可以快速创建，但它不使用[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)和不能自定义其外观。



## 部件和状态模型

部件和状态模型指定如何定义可视结构和控件的可视行为。 若要遵循的部件和状态的模型，应执行以下操作：

- 定义可视结构和可视行为[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)的控件。
- 控件的逻辑与控件模板部件的交互时，请遵循一些最佳实践方法。
- 提供用于指定中应包含的内容的控件协定[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。

当定义可视结构和可视行为[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)控件的应用程序作者可以更改的可视结构和控件的可视行为通过创建一个新[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)而不是编写代码。 必须提供控件协定，以告知应用程序作者这[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)应中定义的对象和状态[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。 中的部件进行交互时，应遵循一些最佳实践[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)，以便您的控件正确处理不完整[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。 如果您遵循这三个原则，将能够创建应用程序作者[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)控件只是因为它们轻松可以控件的附带WPF。 以下部分介绍每个这些建议详细信息。



## 在 ControlTemplate 中定义的可视结构和控件的可视行为

当使用部件和状态模型创建自定义控件时，您定义控件的可视结构和可视行为及其[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)而不是其逻辑中。 控件的可视结构是复合形式[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)构成控件的对象。 可视行为是处于特定状态时显示该控件的方法。 有关创建的详细信息[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)，用于指定可视结构和控件的可视行为，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

在示例中的`NumericUpDown`控件的可视结构包含两个[RepeatButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.repeatbutton)控件和一个[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)。 如果您的代码中添加这些控件`NumericUpDown`管理-在其构造函数，例如，这些控件的位置将无法更改。 而不是在其代码中定义控件的可视结构和可视行为，应将其定义中[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。 然后应用程序开发人员自定义按钮的位置和[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)并指定所发生的行为时`Value`为负因为[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)可替换。

下面的示例演示的可视结构`NumericUpDown`控件，其中包括[RepeatButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.repeatbutton)增加`Value`、 一个[RepeatButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.repeatbutton)减少`Value`，和一个[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)以显示`Value`。

XAML复制

```xaml
<ControlTemplate TargetType="src:NumericUpDown">
  <Grid  Margin="3" 
         Background="{TemplateBinding Background}">
    <Grid>
      <Grid.RowDefinitions>
        <RowDefinition/>
        <RowDefinition/>
      </Grid.RowDefinitions>
      <Grid.ColumnDefinitions>
        <ColumnDefinition/>
        <ColumnDefinition/>
      </Grid.ColumnDefinitions>

      <Border BorderThickness="1" BorderBrush="Gray" 
              Margin="7,2,2,2" Grid.RowSpan="2" 
              Background="#E0FFFFFF"
              VerticalAlignment="Center" 
              HorizontalAlignment="Stretch">

        <!--Bind the TextBlock to the Value property-->
        <TextBlock Name="TextBlock"
                   Width="60" TextAlignment="Right" Padding="5"
                   Text="{Binding RelativeSource={RelativeSource FindAncestor, 
                     AncestorType={x:Type src:NumericUpDown}}, 
                     Path=Value}"/>
      </Border>

      <RepeatButton Content="Up" Margin="2,5,5,0"
        Name="UpButton"
        Grid.Column="1" Grid.Row="0"/>
      <RepeatButton Content="Down" Margin="2,0,5,5"
        Name="DownButton"
        Grid.Column="1" Grid.Row="1"/>

      <Rectangle Name="FocusVisual" Grid.ColumnSpan="2" Grid.RowSpan="2" 
        Stroke="Black" StrokeThickness="1"  
        Visibility="Collapsed"/>
    </Grid>

  </Grid>
</ControlTemplate>
```

可视行为`NumericUpDown`控件是如果它为负的值是以红色字体。 如果您更改[Foreground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.foreground)的[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)时在代码中`Value`为负，`NumericUpDown`将始终显示为红色的负值。 指定在控件的可视行为[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)加上[VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate)对象添加到[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。 下面的示例演示[VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate)对象的`Positive`和`Negative`状态。 `Positive` 并`Negative`是互斥的 （控件将始终处于其中的两个），因此示例将放[VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate)成了一个对象[VisualStateGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstategroup)。在控件转换为`Negative`状态，[Foreground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.foreground)的[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)将变为红色。 当控件处于`Positive`状态，[Foreground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.foreground)返回到其原始值。 定义[VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate)中的对象[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)中进一步讨论[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

 备注

请务必设置[VisualStateGroups](https://msdn.microsoft.com/library/system.windows.visualstatemanager.visualstategroups.aspx)附加属性的根[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)的[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。

XAML复制

```xaml
<ControlTemplate TargetType="local:NumericUpDown">
  <Grid  Margin="3" 
         Background="{TemplateBinding Background}">

    <VisualStateManager.VisualStateGroups>
      <VisualStateGroup Name="ValueStates">

        <!--Make the Value property red when it is negative.-->
        <VisualState Name="Negative">
          <Storyboard>
            <ColorAnimation To="Red"
              Storyboard.TargetName="TextBlock" 
              Storyboard.TargetProperty="(Foreground).(Color)"/>
          </Storyboard>

        </VisualState>

        <!--Return the TextBlock's Foreground to its 
            original color.-->
        <VisualState Name="Positive"/>
      </VisualStateGroup>
    </VisualStateManager.VisualStateGroups>
  </Grid>
</ControlTemplate>
```



## 使用在代码中的 ControlTemplate 部件

一个[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)作者可能会省略[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)或[VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate)对象，有意或意外，但控件的逻辑可能需要这些部件能够正常工作。 部件和状态模型指定控件应该能够应对[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)缺少[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)或[VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate)对象。 您的控件不应引发异常或报表错误如果[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)， [VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate)，或[VisualStateGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstategroup)缺少[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。 本部分介绍用于与进行交互的建议的做法[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)对象，并管理状态。

### 预计缺少 FrameworkElement 对象

在定义[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)中的对象[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)，控件的逻辑可能需要与其中一些交互。 例如，`NumericUpDown`按钮的控件订阅[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件来增加或减少`Value`，并设置[Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.text)属性[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)到`Value`。 如果自定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)省略[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)或者按钮，它是可接受在控件失去其部分功能，但您应确保您的控件不会导致错误。 例如，如果[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)不包含要更改的按钮`Value`，则`NumericUpDown`，该功能，但使用的应用程序将失去[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)将继续运行。

以下做法可确保控件正确响应与缺少[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)对象：

1. 设置`x:Name`为每个属性[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)，您需要在代码中引用。
2. 为每个定义私有属性[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)需要与之交互。
3. 订阅和取消订阅您的控件以处理任何事件[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)属性的 set 访问器。
4. 设置[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)中定义的属性中的步骤 2[OnApplyTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.onapplytemplate)方法。 这是最早的[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)在[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)可供该控件。 使用`x:Name`的[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)若要从中获取此[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。
5. 检查[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)不是`null`之前访问其成员。 如果它是`null`，不报告错误。

下面的示例演示如何`NumericUpDown`控件与交互[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)根据前面的列表中建议的对象。

在以下示例中定义的可视结构`NumericUpDown`控制[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)，则[RepeatButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.repeatbutton)增加`Value`具有其`x:Name`属性设置为`UpButton`。 下面的示例声明一个名为属性`UpButtonElement`，表示[RepeatButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.repeatbutton)中声明的[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。 `set`访问器首先取消到按钮的[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件如果`UpDownElement`不是`null`，然后设置该属性，然后它订阅[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件。 此外，还有属性定义，但不是能为另，如下所示[RepeatButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.repeatbutton)，称为`DownButtonElement`。

C#复制

```csharp
private RepeatButton upButtonElement;

private RepeatButton UpButtonElement
{
    get
    {
        return upButtonElement;
    }

    set
    {
        if (upButtonElement != null)
        {
            upButtonElement.Click -=
                new RoutedEventHandler(upButtonElement_Click);
        }
        upButtonElement = value;

        if (upButtonElement != null)
        {
            upButtonElement.Click +=
                new RoutedEventHandler(upButtonElement_Click);
        }
    }
}
```

下面的示例演示[OnApplyTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.onapplytemplate)为`NumericUpDown`控件。 该示例使用[GetTemplateChild](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.gettemplatechild)方法以获取[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)对象从[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。 请注意，此示例可防止针对事例[GetTemplateChild](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.gettemplatechild)查找[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)具有指定名称，并且不属于预期类型。 它也是一种最佳的做法，忽略具有指定的元素`x:Name`但属于错误的类型。

C#复制

```csharp
public override void OnApplyTemplate()
{
    UpButtonElement = GetTemplateChild("UpButton") as RepeatButton;
    DownButtonElement = GetTemplateChild("DownButton") as RepeatButton;
    //TextElement = GetTemplateChild("TextBlock") as TextBlock;

    UpdateStates(false);
}
```

按照前面的示例中所示的做法，确保您的控件将继续运行时[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)缺少[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)。

### 使用 VisualStateManager 来管理状态

[VisualStateManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstatemanager)跟踪控件状态以及执行状态间转换所需的逻辑。 当您将添加[VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate)对象添加到[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)，你将其添加到[VisualStateGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstategroup)并添加[VisualStateGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstategroup)到[VisualStateGroups](https://msdn.microsoft.com/library/system.windows.visualstatemanager.visualstategroups.aspx)附加属性，以便[VisualStateManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstatemanager)有权访问它们。

下面的示例重复前面的示例表明[VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate)对应于对象`Positive`和`Negative`控件的状态。 [Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)中`Negative`[VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate)变为[Foreground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.foreground)的[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)红色。 当`NumericUpDown`控件处于`Negative`状态，则在情节提要`Negative`状态开始。 然后[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)中`Negative`当控件返回到状态停止`Positive`状态。 `Positive`[VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate)不需要包含[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)因为时[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)有关`Negative`停止，[Foreground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.foreground)返回到其原始的颜色。

XAML复制

```xaml
<ControlTemplate TargetType="local:NumericUpDown">
  <Grid  Margin="3" 
         Background="{TemplateBinding Background}">

    <VisualStateManager.VisualStateGroups>
      <VisualStateGroup Name="ValueStates">

        <!--Make the Value property red when it is negative.-->
        <VisualState Name="Negative">
          <Storyboard>
            <ColorAnimation To="Red"
              Storyboard.TargetName="TextBlock" 
              Storyboard.TargetProperty="(Foreground).(Color)"/>
          </Storyboard>

        </VisualState>

        <!--Return the TextBlock's Foreground to its 
            original color.-->
        <VisualState Name="Positive"/>
      </VisualStateGroup>
    </VisualStateManager.VisualStateGroups>
  </Grid>
</ControlTemplate>
```

请注意，[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)被赋予一个名称，但[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)中的控件协定不是`NumericUpDown`因为永远不会引用控件的逻辑[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)。 在中引用的元素[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)具有的名称，但不是需要将其控件协定的一部分，因为新[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)对于控件可能不需要引用该元素。 例如，创建一个新的人[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)有关`NumericUpDown`可能会决定不指示`Value`通过更改为负[Foreground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.foreground)。 在这种情况下，都不在代码中也不[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)引用[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)按名称。

控件的逻辑负责更改控件的状态。 下面的示例演示`NumericUpDown`控制调用[GoToState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstatemanager.gotostate)方法进入`Positive`状态时`Value`0 或更高版本，并且`Negative`状态时`Value`小于 0。

C#复制

```csharp
if (Value >= 0)
{
    VisualStateManager.GoToState(this, "Positive", useTransitions);
}
else
{
    VisualStateManager.GoToState(this, "Negative", useTransitions);
}
```

[GoToState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstatemanager.gotostate)方法执行所需启动和停止情节提要适当的逻辑。 当控件调用[GoToState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstatemanager.gotostate)以更改其状态，[VisualStateManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstatemanager)执行以下操作：

- 如果[VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate)控件转到具有[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)，情节提要开始。 然后，如果[VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate)来自该控件具有[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)，情节提要结束。
- 如果控件已指定，则州[GoToState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstatemanager.gotostate)不执行任何操作，并返回`true`。
- 如果指定的状态中不存在[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)的`control`，[GoToState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstatemanager.gotostate)不执行任何操作，并返回`false`。

#### 使用 VisualStateManager 的最佳实践

建议以下操作来维护控件的状态：

- 使用属性来跟踪其状态。
- 创建一个帮助器方法用于状态之间转换。

`NumericUpDown`控件使用其`Value`属性以跟踪是否正在`Positive`或`Negative`状态。 `NumericUpDown`还定义了控件`Focused`并`UnFocused`指出，哪些跟踪[IsFocused](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.isfocused)属性。 如果使用不自然地对应于控件的属性的状态，可以定义一个私有属性来跟踪状态。

更新所有状态的单一方法可集中管理对调用[VisualStateManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstatemanager)并使代码更易于管理。 下面的示例演示`NumericUpDown`控件的帮助器方法， `UpdateStates`。 当`Value`大于或等于 0，[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)处于`Positive`状态。 当`Value`是小于 0，该控件处于`Negative`状态。 当[IsFocused](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.isfocused)是`true`，在控件处于`Focused`状态，否则为它是在`Unfocused`状态。 该控件可以调用`UpdateStates`每当需要更改其状态，而不考虑所处的状态更改。

C#复制

```csharp
private void UpdateStates(bool useTransitions)
{
    if (Value >= 0)
    {
        VisualStateManager.GoToState(this, "Positive", useTransitions);
    }
    else
    {
        VisualStateManager.GoToState(this, "Negative", useTransitions);
    }

    if (IsFocused)
    {
        VisualStateManager.GoToState(this, "Focused", useTransitions);
    }
    else
    {
        VisualStateManager.GoToState(this, "Unfocused", useTransitions);
    }
}
```

如果通过将状态名称传递给[GoToState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstatemanager.gotostate)时该控件已处于该状态[GoToState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstatemanager.gotostate)不执行任何操作，因此无需检查的控件的当前状态。 例如，如果`Value`从一个负号更改为另一个负数的情节提要`Negative`不中断状态，用户不会在控件中的发生更改。

[VisualStateManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstatemanager)使用[VisualStateGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstategroup)对象，以确定哪种状态时调用退出[GoToState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstatemanager.gotostate)。 控件将始终处于一个状态为每个[VisualStateGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstategroup)中定义其[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)，才离开前一种状态时将它放入另一种状态从同一个[VisualStateGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstategroup)。 例如，[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)的`NumericUpDown`控件定义`Positive`和`Negative`[VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate)中其中一个对象[VisualStateGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstategroup)并`Focused`并`Unfocused`[VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate)中另一个对象。 (您所见`Focused`并`Unfocused`[VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate)中定义[完整示例](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/creating-a-control-that-has-a-customizable-appearance#complete_example)当控件从本主题中的部分`Positive`状态变为`Negative`状态，反过来也一样，控件将保留在任一`Focused`或`Unfocused`状态。

有以下三个控件的状态可能会更改其中的典型位置：

- 当[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)应用于[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)。
- 当属性更改。
- 在事件发生时。

以下示例演示了更新的状态`NumericUpDown`在这些情况下的控件。

应更新中的控件的状态[OnApplyTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.onapplytemplate)方法，以便正确显示该控件运行时[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)应用。 下面的示例调用`UpdateStates`在[OnApplyTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.onapplytemplate)可确保在控件处于相应状态。 例如，假设您创建`NumericUpDown`控件，并将其[Foreground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.foreground)为绿色和`Value`-5。 如果不调用`UpdateStates`时[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)应用于`NumericUpDown`控件，该控件不在`Negative`状态，并且值为绿色而不是红色。 必须调用`UpdateStates`若要将控件放入`Negative`状态。

C#复制

```csharp
public override void OnApplyTemplate()
{
    UpButtonElement = GetTemplateChild("UpButton") as RepeatButton;
    DownButtonElement = GetTemplateChild("DownButton") as RepeatButton;
    //TextElement = GetTemplateChild("TextBlock") as TextBlock;

    UpdateStates(false);
}
```

通常需要更新控件属性发生更改时的状态。 下面的示例显示了完整`ValueChangedCallback`方法。 因为`ValueChangedCallback`时，将调用`Value`发生更改，方法调用`UpdateStates`以防`Value`更改从正为负，反之亦然。 它是可接受要调用`UpdateStates`时`Value`更改，但仍保持正数或负数，因为在这种情况下，该控件将不会更改状态。

C#复制

```csharp
private static void ValueChangedCallback(DependencyObject obj, 
    DependencyPropertyChangedEventArgs args)
{
    NumericUpDown ctl = (NumericUpDown)obj;
    int newValue = (int)args.NewValue;

    // Call UpdateStates because the Value might have caused the
    // control to change ValueStates.
    ctl.UpdateStates(true);

    // Call OnValueChanged to raise the ValueChanged event.
    ctl.OnValueChanged(
        new ValueChangedEventArgs(NumericUpDown.ValueChangedEvent, 
            newValue));
}
```

您可能还需要更新状态事件发生时。 下面的示例演示`NumericUpDown`调用`UpdateStates`上[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)来处理[GotFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.gotfocus)事件。

C#复制

```csharp
protected override void OnGotFocus(RoutedEventArgs e)
{
    base.OnGotFocus(e);
    UpdateStates(true);
}
```

[VisualStateManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstatemanager)可帮助您管理您的控件的状态。 通过使用[VisualStateManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstatemanager)，确保控件正确状态之间转换。 如果您遵循有关使用此部分中所述的建议[VisualStateManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstatemanager)，控件的代码将保持可读性和可维护性。



## 提供控件协定

提供控件协定，以便[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)作者会知道要放置在模板中的内容。 控件协定具有三个元素：

- 控件逻辑使用的可视元素。
- 控件状态和每种状态所属的组。
- 以可视方式影响控件的公共属性。

创建一个新的某人[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)需要知道什么[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)控件的逻辑使用的对象类型的每个对象是和它的名称是。 一个[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)作者还需要了解的控件可以在中，每个可能的状态和名称[VisualStateGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstategroup)状态为。

返回到`NumericUpDown`示例中，控件应当[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)具有以下[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)对象：

- 一个[RepeatButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.repeatbutton)调用`UpButton`。
- 一个[RepeatButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.repeatbutton)调用 `DownButton.`

该控件可处于以下状态：

- 在 `ValueStates`[VisualStateGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstategroup)
  - `Positive`
  - `Negative`
- 在 `FocusStates`[VisualStateGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstategroup)
  - `Focused`
  - `Unfocused`

若要指定的内容[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)对象控件预期，则使用[TemplatePartAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.templatepartattribute)，它指定的名称和预期元素的类型。 若要指定一个控件的可能状态，请使用[TemplateVisualStateAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.templatevisualstateattribute)，它指定该状态的名称和其中[VisualStateGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstategroup)它属于。 将放[TemplatePartAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.templatepartattribute)和[TemplateVisualStateAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.templatevisualstateattribute)的类定义中的控件。

在控件的外观会影响任何公共属性也是控件协定的一部分。

下面的示例指定[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)对象和状态`NumericUpDown`控件。

C#复制

```csharp
[TemplatePart(Name = "UpButtonElement", Type = typeof(RepeatButton))]
[TemplatePart(Name = "DownButtonElement", Type = typeof(RepeatButton))]
[TemplateVisualState(Name = "Positive", GroupName = "ValueStates")]
[TemplateVisualState(Name = "Negative", GroupName = "ValueStates")]
[TemplateVisualState(Name = "Focused", GroupName = "FocusedStates")]
[TemplateVisualState(Name = "Unfocused", GroupName = "FocusedStates")]
public class NumericUpDown : Control
{
    public static readonly DependencyProperty BackgroundProperty;
    public static readonly DependencyProperty BorderBrushProperty;
    public static readonly DependencyProperty BorderThicknessProperty;
    public static readonly DependencyProperty FontFamilyProperty;
    public static readonly DependencyProperty FontSizeProperty;
    public static readonly DependencyProperty FontStretchProperty;
    public static readonly DependencyProperty FontStyleProperty;
    public static readonly DependencyProperty FontWeightProperty;
    public static readonly DependencyProperty ForegroundProperty;
    public static readonly DependencyProperty HorizontalContentAlignmentProperty;
    public static readonly DependencyProperty PaddingProperty;
    public static readonly DependencyProperty TextAlignmentProperty;
    public static readonly DependencyProperty TextDecorationsProperty;
    public static readonly DependencyProperty TextWrappingProperty;
    public static readonly DependencyProperty VerticalContentAlignmentProperty;

    public Brush Background { get; set; }
    public Brush BorderBrush { get; set; }
    public Thickness BorderThickness { get; set; }
    public FontFamily FontFamily { get; set; }
    public double FontSize { get; set; }
    public FontStretch FontStretch { get; set; }
    public FontStyle FontStyle { get; set; }
    public FontWeight FontWeight { get; set; }
    public Brush Foreground { get; set; }
    public HorizontalAlignment HorizontalContentAlignment { get; set; }
    public Thickness Padding { get; set; }
    public TextAlignment TextAlignment { get; set; }
    public TextDecorationCollection TextDecorations { get; set; }
    public TextWrapping TextWrapping { get; set; }
    public VerticalAlignment VerticalContentAlignment { get; set; }
}
```



## 完整的示例

下面的示例是整个[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为`NumericUpDown`控件。

XAML复制

```xaml
<!--This is the contents of the themes/generic.xaml file.-->
<ResourceDictionary
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    xmlns:local="clr-namespace:VSMCustomControl">


  <Style TargetType="{x:Type local:NumericUpDown}">
    <Setter Property="Template">
      <Setter.Value>
        <ControlTemplate TargetType="local:NumericUpDown">
          <Grid  Margin="3" 
                Background="{TemplateBinding Background}">


            <VisualStateManager.VisualStateGroups>

              <VisualStateGroup Name="ValueStates">

                <!--Make the Value property red when it is negative.-->
                <VisualState Name="Negative">
                  <Storyboard>
                    <ColorAnimation To="Red"
                      Storyboard.TargetName="TextBlock" 
                      Storyboard.TargetProperty="(Foreground).(Color)"/>
                  </Storyboard>

                </VisualState>

                <!--Return the control to its initial state by
                    return the TextBlock's Foreground to its 
                    original color.-->
                <VisualState Name="Positive"/>
              </VisualStateGroup>

              <VisualStateGroup Name="FocusStates">

                <!--Add a focus rectangle to highlight the entire control
                    when it has focus.-->
                <VisualState Name="Focused">
                  <Storyboard>
                    <ObjectAnimationUsingKeyFrames Storyboard.TargetName="FocusVisual" 
                                                   Storyboard.TargetProperty="Visibility" Duration="0">
                      <DiscreteObjectKeyFrame KeyTime="0">
                        <DiscreteObjectKeyFrame.Value>
                          <Visibility>Visible</Visibility>
                        </DiscreteObjectKeyFrame.Value>
                      </DiscreteObjectKeyFrame>
                    </ObjectAnimationUsingKeyFrames>
                  </Storyboard>
                </VisualState>

                <!--Return the control to its initial state by
                    hiding the focus rectangle.-->
                <VisualState Name="Unfocused"/>
              </VisualStateGroup>

            </VisualStateManager.VisualStateGroups>

            <Grid>
              <Grid.RowDefinitions>
                <RowDefinition/>
                <RowDefinition/>
              </Grid.RowDefinitions>
              <Grid.ColumnDefinitions>
                <ColumnDefinition/>
                <ColumnDefinition/>
              </Grid.ColumnDefinitions>

              <Border BorderThickness="1" BorderBrush="Gray" 
                Margin="7,2,2,2" Grid.RowSpan="2" 
                Background="#E0FFFFFF"
                VerticalAlignment="Center" 
                HorizontalAlignment="Stretch">
                <!--Bind the TextBlock to the Value property-->
                <TextBlock Name="TextBlock"
                  Width="60" TextAlignment="Right" Padding="5"
                  Text="{Binding RelativeSource={RelativeSource FindAncestor, 
                                 AncestorType={x:Type local:NumericUpDown}}, 
                                 Path=Value}"/>
              </Border>

              <RepeatButton Content="Up" Margin="2,5,5,0"
                Name="UpButton"
                Grid.Column="1" Grid.Row="0"/>
              <RepeatButton Content="Down" Margin="2,0,5,5"
                Name="DownButton"
                Grid.Column="1" Grid.Row="1"/>

              <Rectangle Name="FocusVisual" Grid.ColumnSpan="2" Grid.RowSpan="2" 
                Stroke="Black" StrokeThickness="1"  
                Visibility="Collapsed"/>
            </Grid>

          </Grid>
        </ControlTemplate>
      </Setter.Value>
    </Setter>
  </Style>
</ResourceDictionary>
```

下面的示例演示的逻辑`NumericUpDown`。

C#复制

```csharp
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Input;
using System.Windows.Media;

namespace VSMCustomControl
{
    [TemplatePart(Name = "UpButtonElement", Type = typeof(RepeatButton))]
    [TemplatePart(Name = "DownButtonElement", Type = typeof(RepeatButton))]
    [TemplateVisualState(Name = "Positive", GroupName = "ValueStates")]
    [TemplateVisualState(Name = "Negative", GroupName = "ValueStates")]
    [TemplateVisualState(Name = "Focused", GroupName = "FocusedStates")]
    [TemplateVisualState(Name = "Unfocused", GroupName = "FocusedStates")]
    public class NumericUpDown : Control
    {
        public NumericUpDown()
        {
            DefaultStyleKey = typeof(NumericUpDown);
            this.IsTabStop = true;
        }

        public static readonly DependencyProperty ValueProperty =
            DependencyProperty.Register(
                "Value", typeof(int), typeof(NumericUpDown),
                new PropertyMetadata(
                    new PropertyChangedCallback(ValueChangedCallback)));

        public int Value
        {
            get
            {
                return (int)GetValue(ValueProperty);
            }

            set
            {
                SetValue(ValueProperty, value);

            }
        }

        private static void ValueChangedCallback(DependencyObject obj, 
            DependencyPropertyChangedEventArgs args)
        {
            NumericUpDown ctl = (NumericUpDown)obj;
            int newValue = (int)args.NewValue;

            // Call UpdateStates because the Value might have caused the
            // control to change ValueStates.
            ctl.UpdateStates(true);

            // Call OnValueChanged to raise the ValueChanged event.
            ctl.OnValueChanged(
                new ValueChangedEventArgs(NumericUpDown.ValueChangedEvent, 
                    newValue));
        }

        public static readonly RoutedEvent ValueChangedEvent =
            EventManager.RegisterRoutedEvent("ValueChanged", RoutingStrategy.Direct,
                          typeof(ValueChangedEventHandler), typeof(NumericUpDown));

        public event ValueChangedEventHandler ValueChanged
        {
            add { AddHandler(ValueChangedEvent, value); }
            remove { RemoveHandler(ValueChangedEvent, value); }
        }


        protected virtual void OnValueChanged(ValueChangedEventArgs e)
        {
            // Raise the ValueChanged event so applications can be alerted
            // when Value changes.
            RaiseEvent(e);
        }


        private void UpdateStates(bool useTransitions)
        {
            if (Value >= 0)
            {
                VisualStateManager.GoToState(this, "Positive", useTransitions);
            }
            else
            {
                VisualStateManager.GoToState(this, "Negative", useTransitions);
            }

            if (IsFocused)
            {
                VisualStateManager.GoToState(this, "Focused", useTransitions);
            }
            else
            {
                VisualStateManager.GoToState(this, "Unfocused", useTransitions);
            }
        }

        public override void OnApplyTemplate()
        {
            UpButtonElement = GetTemplateChild("UpButton") as RepeatButton;
            DownButtonElement = GetTemplateChild("DownButton") as RepeatButton;
            //TextElement = GetTemplateChild("TextBlock") as TextBlock;

            UpdateStates(false);
        }

        private RepeatButton downButtonElement;

        private RepeatButton DownButtonElement
        {
            get
            {
                return downButtonElement;
            }

            set
            {
                if (downButtonElement != null)
                {
                    downButtonElement.Click -=
                        new RoutedEventHandler(downButtonElement_Click);
                }
                downButtonElement = value;

                if (downButtonElement != null)
                {
                    downButtonElement.Click +=
                        new RoutedEventHandler(downButtonElement_Click);
                }
            }
        }

        void downButtonElement_Click(object sender, RoutedEventArgs e)
        {
            Value--;
        }

        private RepeatButton upButtonElement;

        private RepeatButton UpButtonElement
        {
            get
            {
                return upButtonElement;
            }

            set
            {
                if (upButtonElement != null)
                {
                    upButtonElement.Click -=
                        new RoutedEventHandler(upButtonElement_Click);
                }
                upButtonElement = value;

                if (upButtonElement != null)
                {
                    upButtonElement.Click +=
                        new RoutedEventHandler(upButtonElement_Click);
                }
            }
        }

        void upButtonElement_Click(object sender, RoutedEventArgs e)
        {
            Value++;
        }

        protected override void OnMouseLeftButtonDown(MouseButtonEventArgs e)
        {
            base.OnMouseLeftButtonDown(e);
            Focus();
        }


        protected override void OnGotFocus(RoutedEventArgs e)
        {
            base.OnGotFocus(e);
            UpdateStates(true);
        }

        protected override void OnLostFocus(RoutedEventArgs e)
        {
            base.OnLostFocus(e);
            UpdateStates(true);
        }
    }


    public delegate void ValueChangedEventHandler(object sender, ValueChangedEventArgs e);

    public class ValueChangedEventArgs : RoutedEventArgs
    {
        private int _value;

        public ValueChangedEventArgs(RoutedEvent id, int num)
        {
            _value = num;
            RoutedEvent = id;
        }

        public int Value
        {
            get { return _value; }
        }
    }
}
```