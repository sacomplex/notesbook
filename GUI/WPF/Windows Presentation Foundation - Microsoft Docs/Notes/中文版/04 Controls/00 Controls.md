# [Controls](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/)

Windows Presentation Foundation (WPF) 附带许多中几乎每个 Windows 应用程序中，如使用的常见 UI 组件[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)， [Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)， [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)， [Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)，和[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)。 以前，这些对象称为控件。 虽然WPFSDK 继续使用术语"控件"泛指任何代表应用程序中的可见对象的类务必要注意类不需要从继承[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)类即可具有可见外观。 继承的类[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)类包含[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)，它允许控件的使用方从根本上更改控件的外观，而无需创建新子类。 本主题讨论如何控件 (那些从继承[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)类和一些未) 中常用WPF。

## 创建控件的实例

可以向应用程序添加一个控件，通过使用可扩展应用程序标记语言 (XAML)或代码。 下面的示例演示如何创建一个向用户询问其姓名的简单应用程序。 此示例创建六个控件： 两个标签、 两个文本框及两个按钮，在XAML。 所有控件均可使用相似方式创建。

```xaml
<Grid>
  <Grid.RowDefinitions>
    <RowDefinition Height="30"/>
    <RowDefinition Height="30"/>
    <RowDefinition Height="30"/>
    <RowDefinition/>
  </Grid.RowDefinitions>
  <Grid.ColumnDefinitions>
    <ColumnDefinition/>
    <ColumnDefinition/>
  </Grid.ColumnDefinitions>

  <Label>
    Enter your first name:
  </Label>
  <TextBox Grid.Row="0" Grid.Column="1" 
           Name="firstName" Margin="0,5,10,5"/>

  <Label Grid.Row="1" >
    Enter your last name:
  </Label>
  <TextBox Grid.Row="1" Grid.Column="1" 
           Name="lastName" Margin="0,5,10,5"/>

  <Button Grid.Row="2" Grid.Column="0" 
          Name="submit" Margin="2">
    View message
  </Button>

  <Button Grid.Row="2" Grid.Column="1" 
          Name="Clear" Margin="2">
    Clear Name
  </Button>
</Grid>
```

以下示例在代码中创建相同的应用程序。 为简洁起见，创建[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)， `grid1`，已排除的示例。 `grid1` 具有相同的列和行定义，在前面所示XAML示例。

```csharp
Label firstNameLabel;
Label lastNameLabel;
TextBox firstName;
TextBox lastName;
Button submit;
Button clear;

void CreateControls()
{
    firstNameLabel = new Label();
    firstNameLabel.Content = "Enter your first name:";
    grid1.Children.Add(firstNameLabel);

    firstName = new TextBox();
    firstName.Margin = new Thickness(0, 5, 10, 5);
    Grid.SetColumn(firstName, 1);
    grid1.Children.Add(firstName);

    lastNameLabel = new Label();
    lastNameLabel.Content = "Enter your last name:";
    Grid.SetRow(lastNameLabel, 1);
    grid1.Children.Add(lastNameLabel);

    lastName = new TextBox();
    lastName.Margin = new Thickness(0, 5, 10, 5);
    Grid.SetColumn(lastName, 1);
    Grid.SetRow(lastName, 1);
    grid1.Children.Add(lastName);

    submit = new Button();
    submit.Content = "View message";
    Grid.SetRow(submit, 2);
    grid1.Children.Add(submit);

    clear = new Button();
    clear.Content = "Clear Name";
    Grid.SetRow(clear, 2);
    Grid.SetColumn(clear, 1);
    grid1.Children.Add(clear);

}
```

## 更改控件的外观

更改控件的外观以适应应用程序的外观，这是很常见的操作。 可以根据要达到的效果，通过执行以下操作之一来更改控件的外观：

- 更改控件的属性值。
- 创建[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)控件。
- 创建一个新[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)控件。

### 更改控件的属性值

许多控件具有属性，可用于更改控件的显示方式，如[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)的[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。 可以在这种设置的值属性XAML和代码。 下面的示例设置[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)， [FontSize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontsize)，并[FontWeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontweight)上的属性[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)中XAML。

```xaml
<Button FontSize="14" FontWeight="Bold">
  <!--Set the Background property of the Button to
    a LinearGradientBrush.-->
  <Button.Background>
    <LinearGradientBrush StartPoint="0,0.5" 
                            EndPoint="1,0.5">
      <GradientStop Color="Green" Offset="0.0" />
      <GradientStop Color="White" Offset="0.9" />
    </LinearGradientBrush>

  </Button.Background>
  View message
</Button>
```

下面的示例在代码中设置相同的属性。

```csharp
LinearGradientBrush buttonBrush = new LinearGradientBrush();
buttonBrush.StartPoint = new Point(0, 0.5);
buttonBrush.EndPoint = new Point(1, 0.5);
buttonBrush.GradientStops.Add(new GradientStop(Colors.Green, 0));
buttonBrush.GradientStops.Add(new GradientStop(Colors.White, 0.9));

submit.Background = buttonBrush;
submit.FontSize = 14;
submit.FontWeight = FontWeights.Bold;
```

### 为控件创建样式

WPF 使您能够指定控件的外观成批，而不是在应用程序中，每个实例上设置属性，通过创建[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)。 下面的示例创建[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)应用于每个[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)应用程序中。 [Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style) 定义通常在XAML中[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)，如[Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.resources)属性的[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)。

```xaml
<Style TargetType="Button">
  <Setter Property="FontSize" Value="14"/>
  <Setter Property="FontWeight" Value="Bold"/>
  <Setter Property="Background">
    <Setter.Value>
      <LinearGradientBrush StartPoint="0,0.5" 
                              EndPoint="1,0.5">
        <GradientStop Color="Green" Offset="0.0" />
        <GradientStop Color="White" Offset="0.9" />
      </LinearGradientBrush>

    </Setter.Value>
  </Setter>
</Style>
```

您可以还样式将仅应用于某些特定类型的通过将键分配给样式并指定该注册表项中的`Style`控件的属性。 有关样式的详细信息，请参阅[样式和模板化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/styling-and-templating)。

### 创建 ControlTemplate

一个[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)允许您一次，多个控件设置属性，但有时您可能想要自定义的外观[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)超出如何通过创建[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)。 继承的类[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)类具有[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)，用于定义的结构和外观[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)。 [Template](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.template)的属性[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)是公共的所以可以向[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)不同于其默认值。 通常可以指定一个新[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)有关[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)而不是从控件的外观进行自定义继承[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)。

请考虑一个很常见的控件， [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。 主要行为[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)是为了使应用程序采取某些操作，当用户单击它。 默认情况下[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)在WPF显示为一个凸出的矩形。 在开发应用程序时，你可能想要充分利用的行为[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)-即，通过处理按钮的单击事件，但可能会更改超出你可以通过更改按钮的属性执行的操作的按钮的外观。 在这种情况下，您可以创建一个新[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。

下面的示例创建[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。 [ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)创建[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)带有圆的角和渐变背景。 [ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)包含[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)其[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border.background)是[LinearGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush)具有两个[GradientStop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientstop)对象。 第一个[GradientStop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientstop)使用数据绑定来绑定[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientstop.color)属性的[GradientStop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientstop)到按钮的背景的颜色。 当您将设置[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)的属性[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)，该值的颜色将用作第一个[GradientStop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.gradientstop)。 有关数据绑定的详细信息，请参阅[数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview)。 此示例还创建[Trigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.trigger)更改的外观[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)时[IsPressed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.ispressed)是`true`。

```xaml
<!--Define a template that creates a gradient-colored button.-->
<Style TargetType="Button">
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="Button">
        <Border 
          x:Name="Border"  
          CornerRadius="20" 
          BorderThickness="1"
          BorderBrush="Black">
          <Border.Background>
            <LinearGradientBrush StartPoint="0,0.5" 
                                 EndPoint="1,0.5">
              <GradientStop Color="{Binding Background.Color, 
                    RelativeSource={RelativeSource TemplatedParent}}" 
                            Offset="0.0" />
              <GradientStop Color="White" Offset="0.9" />
            </LinearGradientBrush>
          </Border.Background>
          <ContentPresenter 
            Margin="2"
            HorizontalAlignment="Center"
            VerticalAlignment="Center"
            RecognizesAccessKey="True"/>
        </Border>
        <ControlTemplate.Triggers>
          <!--Change the appearance of
          the button when the user clicks it.-->
          <Trigger Property="IsPressed" Value="true">
            <Setter TargetName="Border" Property="Background">
              <Setter.Value>
                <LinearGradientBrush StartPoint="0,0.5" 
                                     EndPoint="1,0.5">
                  <GradientStop Color="{Binding Background.Color, 
                    RelativeSource={RelativeSource TemplatedParent}}" 
                                Offset="0.0" />
                  <GradientStop Color="DarkSlateGray" Offset="0.9" />
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

```xaml
<Button Grid.Row="2" Grid.ColumnSpan="2" Name="submitName"
        Background="Green">View message</Button>
```

> [Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)的属性[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)必须设置为[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)示例才能正常工作。



## 订阅事件

您可以通过使用订阅控件的事件XAML或代码，但您只能处理代码中的事件。 下面的示例演示如何订阅`Click`事件的[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。

```xaml
<Button Grid.Row="2" Grid.ColumnSpan="2" Name="submitName" Click="submit_Click"
  Background="Green">View message</Button>
```

```csharp
submit.Click += new RoutedEventHandler(submit_Click);
```

下面的示例处理`Click`事件的[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。

```csharp
void submit_Click(object sender, RoutedEventArgs e)
{
    MessageBox.Show("Hello, " + firstName.Text + " " + lastName.Text);
}
```

## 控件中的丰富内容

继承的大多数类[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)类具有包含丰富内容的能力。 例如，[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)可以包含任意对象，一个字符串，例如[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)，或[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)。 以下类支持丰富的内容，充当用于在控件中的大部分的基类WPF。

- [ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)-从此类继承的类的示例包括[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)， [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)，和[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)。
- [ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)-从此类继承的类的示例包括[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)， [Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)，和[StatusBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.statusbar)。
- [HeaderedContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headeredcontentcontrol)-从此类继承的类的示例包括[TabItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tabitem)， [GroupBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.groupbox)，和[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)。
- [HeaderedItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headereditemscontrol)-从此类继承的类的示例包括[MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)， [TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)，和[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)。

有关这些基类的类的详细信息，请参阅[WPF 内容模型](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/wpf-content-model)。