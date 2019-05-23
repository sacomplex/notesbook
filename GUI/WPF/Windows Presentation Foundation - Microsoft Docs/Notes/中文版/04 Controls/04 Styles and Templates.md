# [Styles and Templates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/styles-and-templates)

Windows Presentation Foundation (WPF) 样式和模板化指套件的允许的应用程序、 文档或用户界面 (UI) 设计器来创建视觉效果更佳的应用程序的功能 （样式、 模板、 触发器和情节提要） 和标准化尤其是查找其产品。

[样式设置和模板化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/styling-and-templating)
[如何：查找由 ControlTemplate 生成的元素](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-find-controltemplate-generated-elements)

## [Styling and Templating](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/styling-and-templating)

Windows Presentation Foundation (WPF) 样式设置和模板化是指一套功能（样式、模板、触发器和情节提要），可使开发者和设计者创建极具视觉表现力的效果，并为其产品创建一致的外观。 尽管开发者和/或设计者可以逐个应用程序地广泛自定义外观，但为了实现应用程序内部和之间的外观维护和共享，需要一个强大的样式设置和模板化模型。 Windows Presentation Foundation (WPF) 提供该模型。

WPF 样式设置模型的另一项功能是将演示与逻辑分离。 这意味着，设计者可以仅使用 XAML 处理应用程序外观，与此同时开发者使用 C# 或 Visual Basic 处理编程逻辑。

本概述侧重于应用程序的样式设置和模板化方面，不讨论任何数据绑定概念。 有关数据绑定的信息，请参阅[数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview)。

此外，了解资源很重要，正是这些资源使样式和模板能够重复使用。 有关资源的详细信息，请参阅 [XAML 资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-resources)。

### 样式设置和模板化示例

本概述中使用的代码示例基于下图中所示的简单照片示例：

![Styled ListView](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/stylingintro-triggers.png)

此简单照片示例使用样式设置和模板化创建极具视觉表现力的用户体验。 此示例具有两个[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素和一个[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)控件绑定到映像的列表。 有关完整示例，请参阅[样式设置和模板化示例简介](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。



### 样式基础知识

您可以将[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)作为方便地将一组属性值应用于多个元素。 例如，请考虑以下[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素和它们的默认外观：

```xaml
<TextBlock>My Pictures</TextBlock>
<TextBlock>Check out my new pictures!</TextBlock>
```

![样式设置示例屏幕截图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/stylingintro-textblocksbefore.png)

您可以通过设置属性，如更改默认外观[FontSize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontsize)并[FontFamily](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontfamily)，在每个[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)直接元素。 但是，如果你想你[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素共享某些属性，可以创建[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)中`Resources`一部分您XAML文件，如下所示：

```xaml
<Window.Resources>
```

```xaml
<!--A Style that affects all TextBlocks-->
<Style TargetType="TextBlock">
  <Setter Property="HorizontalAlignment" Value="Center" />
  <Setter Property="FontFamily" Value="Comic Sans MS"/>
  <Setter Property="FontSize" Value="14"/>
</Style>
```

```xaml
</Window.Resources>
```

当您将设置[TargetType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style.targettype)的到您的风格[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)类型，该样式应用于所有[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)窗口中的元素。

现在[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素出现，如下所示：

![Styling sample screen shot](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/stylingintro-textblocksbasestyle.png)

#### 扩展样式

您可能需要两个[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素共享某些属性值，如[FontFamily](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontfamily)和居中[HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.horizontalalignment)，但也希望文本"My Pictures"具有某些其他属性。 可以通过创建基于第一个样式的新样式来实现该目标，如下所示：

```xaml
<Window.Resources>
```

```xaml
<!--A Style that extends the previous TextBlock Style-->
<!--This is a "named style" with an x:Key of TitleText-->
<Style BasedOn="{StaticResource {x:Type TextBlock}}"
       TargetType="TextBlock"
       x:Key="TitleText">
  <Setter Property="FontSize" Value="26"/>
  <Setter Property="Foreground">
  <Setter.Value>
      <LinearGradientBrush StartPoint="0.5,0" EndPoint="0.5,1">
        <LinearGradientBrush.GradientStops>
          <GradientStop Offset="0.0" Color="#90DDDD" />
          <GradientStop Offset="1.0" Color="#5BFFFF" />
        </LinearGradientBrush.GradientStops>
      </LinearGradientBrush>
    </Setter.Value>
  </Setter>
</Style>
```

```xaml
</Window.Resources>
```

请注意，上面的样式提供 `x:Key`。 若要应用该样式，您设置[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.style)属性上的你[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)到`x:Key`值，如下所示：

```xaml
<TextBlock Style="{StaticResource TitleText}" Name="textblock1">My Pictures</TextBlock>
<TextBlock>Check out my new pictures!</TextBlock>
```

这[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)样式现在具有[HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.horizontalalignment)的值[Center](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.horizontalalignment#System_Windows_HorizontalAlignment_Center)、 一个[FontFamily](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.fontfamily)的值`Comic Sans MS`、 一个[FontSize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.fontsize)值为 26，和一个[Foreground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.foreground)值设置为[LinearGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush)示例所示。 请注意，它将替代[FontSize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontsize)的基本样式的值。 如果有多个[Setter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.setter)中设置同一属性[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)，则[Setter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.setter)，它是声明最后一个优先。

下面显示了什么[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素现在看起来像：

![带样式的 TextBlocks](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/stylingintro-textblocks.png)

这`TitleText`样式扩展已为创建的样式[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)类型。 还可以使用 `x:Key` 值扩展具有 `x:Key` 的样式。 有关示例，请参阅为提供的示例[BasedOn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style.basedon)属性。

#### TargetType 属性和 x:Key 属性之间的关系

第一个示例中所示，设置[TargetType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style.targettype)属性设置为`TextBlock`而无需为样式分配`x:Key`会导致该样式应用于所有[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素。 在此情况下，`x:Key` 隐式设置为 `{x:Type TextBlock}`。 这意味着，如果显式设置`x:Key`值到的任何内容，而`{x:Type TextBlock}`，则[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)不应用于所有[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素自动。 相反，必须应用样式 (通过使用`x:Key`值) 到[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素显式。 如果您的方式是在资源部分中，并且未设置[TargetType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style.targettype)属性上应用样式，则你必须提供`x:Key`。

除了提供的默认值之外`x:Key`，则[TargetType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style.targettype)属性指定 setter 属性应用的类型。 如果未指定[TargetType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style.targettype)，必须限定的属性中您[Setter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.setter)对象使用的语法的类名称与`Property="ClassName.Property"`。 例如，而不是设置`Property="FontSize"`，则必须设置[Property](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.setter.property)到`"TextBlock.FontSize"`或`"Control.FontSize"`。

另请注意，许多 WPF 控件由其他 WPF 控件的组合构成。 如果创建应用于某个类型的所有控件的样式，可能会产生意外结果。 例如，如果创建一种样式面向[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)中键入[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)，该样式应用到所有[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)控件在窗口中，即使[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)属于另一个控件，如[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)。

#### 样式和资源

可以从派生的任何元素上使用样式[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)或[FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement)。 声明样式的最常见方法是在 XAML 文件的 `Resources` 部分中声明为样式，如前面的示例所示。 由于样式是资源，因此它们遵循应用于所有资源的相同范围规则；声明样式的位置影响可应用样式的位置。 例如，如果在应用程序定义 XAML 文件的根元素中声明样式，则该样式可以在应用程序中的任何位置使用。 如果创建一个导航应用程序，并在应用程序 XAML文件之一中声明样式，则该样式只能在该 XAML 文件中使用。 有关资源的范围规则的详细信息，请参阅 [XAML 资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-resources)。

此外，可以在本概述后面部分的[共享资源和主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/styling-and-templating#styling_themes)中找到有关样式和资源的详细信息。

#### 以编程方式设置样式

若要以编程方式将已命名的样式分配到的元素，请从资源集合中获取样式并将其分配给元素的[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.style)属性。 请注意，资源集合中的项类型的[Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object)。 因此，您必须强制转换为检索到的样式[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)之前将其分配给[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.style)属性。 例如，若要设置已定义`TitleText`上设置样式[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)名为`textblock1`，执行以下操作：

```csharp
textblock1.Style = (Style)(this.Resources["TitleText"]);
```

请注意，一旦应用样式，它将被密封，并且不能更改。 如果要动态更改已应用的样式，必须创建新的样式来替换现有样式。 有关更多信息，请参见 [IsSealed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style.issealed) 属性。

可以创建一个根据自定义逻辑选择要应用的样式的对象。 有关示例，请参阅为提供的示例[StyleSelector](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.styleselector)类。

#### 绑定、动态资源和事件处理程序

请注意，可以使用 `Setter.Value` 属性指定[绑定标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/binding-markup-extension)或 [DynamicResource 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dynamicresource-markup-extension)。 有关详细信息，请参阅为提供的示例[Setter.Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.setter.value)属性。

到目前为止，本概述仅讨论使用资源库设置属性值。 还可以在样式中指定事件处理程序。 有关详细信息，请参阅 [EventSetter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventsetter)。

### 数据模板

在此示例应用程序中，没有[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)绑定到的照片列表控件：

```xaml
<ListBox ItemsSource="{Binding Source={StaticResource MyPhotos}}"
         Background="Silver" Width="600" Margin="10" SelectedIndex="0"/>
```

这[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)目前看起来如下所示：

![应用模板之前的 ListBox](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/stylingintro-listboxbefore.png)

大多数控件都具有某些类型的内容，并且该内容通常来自要绑定到的数据。 在此示例中，数据是照片列表。 在中WPF，则使用[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)来定义数据的可视化表示形式。 基本上，什么放入[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)确定数据在呈现的应用程序中的样子。

在示例应用程序中，每个自定义 `Photo` 对象都有一个字符串类型的 `Source` 属性，用于指定图像的文件路径。当前，照片对象显示为文件路径。

若要显示为图像使照片，您创建[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)作为资源：

XAML复制

```xaml
<Window.Resources>
```

XAML复制

```xaml
<!--DataTemplate to display Photos as images
    instead of text strings of Paths-->
<DataTemplate DataType="{x:Type local:Photo}">
  <Border Margin="3">
    <Image Source="{Binding Source}"/>
  </Border>
</DataTemplate>
```

XAML复制

```xaml
</Window.Resources>
```

请注意，[DataType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate.datatype)属性是非常类似于[TargetType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style.targettype)属性的[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)。 如果你[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)时，可以在资源部分中，指定[DataType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate.datatype)属性设置为一种类型并不将其分配`x:Key`，则[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)只要该类型将显示应用。 您始终可以选择要将分配[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)与`x:Key`，然后将其设置为`StaticResource`采用[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)类型，如[ItemTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemtemplate)属性或[ContentTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.contenttemplate)属性。

从根本上来说，[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)在上面的示例定义每当存在`Photo`对象，它应显示为[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)内[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)。 与此[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)，我们的应用程序现在如下所示：

![照片图像](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/stylingintro-photosasimages.png)

数据模板化模型提供其他功能。 例如，如果您要显示包含使用其他集合的集合数据[HeaderedItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headereditemscontrol)键入类似于[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)或[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)，没有[HierarchicalDataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.hierarchicaldatatemplate)。 另一个数据模板化功能是[DataTemplateSelector](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datatemplateselector)，可用于选择[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)使用根据自定义逻辑。 有关详细信息，请参阅[数据模板化概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-templating-overview)，该概述提供不同数据模板化功能的更多深入讨论。

### 控件模板

在中WPF，则[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)控件的定义控件的外观。 可以通过定义一个新更改的结构和控件的外观[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)控件。 在许多情况下，这提供了足够的灵活性，从而无需自行编写自定义控件。 有关详细信息，请参阅[通过创建 ControlTemplate 自定义现有控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)。

### Triggers

触发器在属性值发生更改或引发事件时设置属性或启动操作，例如动画。 [Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)，并[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)所有具有`Triggers`包含一组触发器的属性。 触发器有各种类型。

#### 属性触发器

一个[Trigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.trigger)设置属性值或启动基于属性的值的操作称为属性触发器。

若要演示如何使用属性触发器，可以将每个[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)部分透明，除非它被选中。 下面的样式集[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)的值[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)到`0.5`。 当[IsSelected](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem.isselected)属性是`true`，但[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)设置为`1.0`:

```xaml
<Style TargetType="ListBoxItem">
  <Setter Property="Opacity" Value="0.5" />
  <Setter Property="MaxHeight" Value="75" />
  <Style.Triggers>
    <Trigger Property="IsSelected" Value="True">
        <Setter Property="Opacity" Value="1.0" />
    </Trigger>
```

```xaml
  </Style.Triggers>
</Style>
```

此示例使用[Trigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.trigger)若要设置的属性值，但请注意[Trigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.trigger)类还具有[EnterActions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.triggerbase.enteractions)和[ExitActions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.triggerbase.exitactions)启用触发器执行的操作的属性。

请注意，[MaxHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.maxheight)的属性[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)设置为`75`。 在下图中，第三项是选中的项：

![Styled ListView](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/stylingintro-triggers.png)

#### EventTrigger 和情节提要

另一种触发器是[EventTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventtrigger)，从而启动一组基于事件的匹配项的操作。 例如，以下[EventTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventtrigger)对象指定当鼠标指针进入[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)，则[MaxHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.maxheight)属性的值进行动画处理`90`转移`0.2`第二个句点。 当鼠标离开该项时，属性在 `1` 秒的时间内返回到原始值。 请注意如何不需要指定[To](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation.to)值[MouseLeave](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement.mouseleave)动画。 这是因为动画能够跟踪原始值。

```xaml
<EventTrigger RoutedEvent="Mouse.MouseEnter">
  <EventTrigger.Actions>
    <BeginStoryboard>
      <Storyboard>
        <DoubleAnimation
          Duration="0:0:0.2"
          Storyboard.TargetProperty="MaxHeight"
          To="90"  />
      </Storyboard>
    </BeginStoryboard>
  </EventTrigger.Actions>
</EventTrigger>
<EventTrigger RoutedEvent="Mouse.MouseLeave">
  <EventTrigger.Actions>
    <BeginStoryboard>
      <Storyboard>
        <DoubleAnimation
          Duration="0:0:1"
          Storyboard.TargetProperty="MaxHeight"  />
      </Storyboard>
    </BeginStoryboard>
  </EventTrigger.Actions>
</EventTrigger>
```

有关详细信息，请参阅[情节提要概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/storyboards-overview)。

在下图中，鼠标指向第三个项：

![样式设置示例屏幕截图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/stylingintro-eventtriggers.png)

#### MultiTrigger、DataTrigger 和 MultiDataTrigger

除了[Trigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.trigger)和[EventTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventtrigger)，有其他类型的触发器。 [MultiTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.multitrigger) 可以设置基于多个条件的属性值。 您使用[DataTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatrigger)和[MultiDataTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.multidatatrigger)时您的条件的属性是数据绑定。

### 共享资源和主题

典型的 Windows Presentation Foundation (WPF) 应用程序可能具有多个应用于整个应用程序的用户界面 (UI) 资源。 总体上，可以将这组资源视为应用程序的主题。 Windows Presentation Foundation (WPF) 支持打包用户界面 (UI) 资源作为主题通过提供一个资源字典，其中封装为[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)类。

Windows Presentation Foundation (WPF) 主题是使用定义的样式设置和模板化机制，Windows Presentation Foundation (WPF) 公开用于自定义视觉对象的所有元素。

Windows Presentation Foundation (WPF) 主题资源存储在嵌入的资源字典。 这些资源必须嵌入到已签名的程序集内，并且可以嵌入到与代码本身相同的程序集内或并行程序集内。 对于包含 Windows Presentation Foundation (WPF) 控件的程序集 PresentationFramework.dll 主题资源位于一系列通过并行程序集。

该主题成为在搜索元素样式时最后查看的位置。 通常，搜索先沿着元素树搜索适当的资源，然后在应用程序资源集合中查找，最后查询系统。 这样一来，应用程序开发者便有机会在到达主题之前在树或应用程序级别上为任何对象重新定义样式。

可以将资源字典定义为个别文件，这些文件支持跨多个应用程序重复使用主题。 还可以通过定义多个资源字典来创建可交换的主题，这些资源字典以不同的值提供相同类型的资源。 在应用程序级别上重新定义这些样式或其他资源是设计应用程序外观的推荐方法。

若要共享一组资源，包括跨应用程序、 样式和模板，可以创建XAML文件，并定义[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)。 例如，看一看下图，它显示[使用 ControlTemplates 设置样式示例](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)的一部分：

![控件模板示例](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/stylingintro-controltemplateexamples.png)

如果查看示例中的 XAML 文件，将注意到这些文件都具有以下内容：

```xaml
<ResourceDictionary.MergedDictionaries>
  <ResourceDictionary Source="Shared.xaml" />
</ResourceDictionary.MergedDictionaries>
```

它是共享`shared.xaml`，用于定义[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)，其中包含一组样式和画笔资源，使具有一致的外观的示例中的控件。

有关详细信息，请参阅[合并资源字典](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/merged-resource-dictionaries)。

如果要为自定义控件创建主题，请参阅[控件创作概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/control-authoring-overview)的外部控件库部分。

## [Customizing the Appearance of an Existing Control by Creating a ControlTemplate](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control)

一个[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)指定可视结构和控件的可视行为。 您可以通过提供一个新的 it 自定义控件的外观[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。 当你创建[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)，而无需更改其功能替换现有控件的外观。 例如，您可以将按钮在应用程序中圆形而不是默认的方形，但按钮仍将引发[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件。

本主题介绍的各个组成部分[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)，演示如何创建一个简单[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)，并说明如何了解控件的控件协定，使你可以自定义其外观。 因为您创建[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)在XAML，可以无需编写任何代码更改控件的外观。 还可以使用设计器（如 Microsoft Expression Blend）创建自定义控件模板。 本主题演示了在XAML的自定义的外观[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)并列出了本主题末尾的完整示例。 有关使用 Expression Blend 的详细信息，请参阅[设置支持模板的控件的样式](https://go.microsoft.com/fwlink/?LinkId=161153)。

如下图所示[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)，它使用[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)本主题中创建的。

![一个具有自定义控件模板的按钮。](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/ndp-buttonnormal.png)
使用自定义控件模板的按钮

![一个具有红色边框的按钮。](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/ndp-buttonmouseover.png)
使用自定义控件模板并将鼠标指针悬停在上方的按钮

### 系统必备

本主题假设用户了解如何创建和使用[控件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/index)中讨论的控件和样式。 本主题中讨论的概念适用于从继承元素[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)类，除[UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol)。 无法应用[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)到[UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol)。

### 何时应创建 ControlTemplate

控件具有许多属性，如[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border.background)， [Foreground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.foreground)，和[FontFamily](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontfamily)，可以设置为指定控件的外观的不同方面，但可以通过设置这些属性进行的更改受到限制。 例如，可以设置[Foreground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.foreground)属性为蓝色并[FontStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontstyle)为倾斜[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)。

而无需创建一个新的功能[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)控件中的所有控件中每个WPF-基于应用程序将具有相同的常规外观，这将限制应用程序创建具有自定义外观的功能。 默认情况下，每个[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)具有类似的特征。 例如，内容[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)始终是位于选择指示器，右侧，总是使用复选标记以指示[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)处于选中状态。

创建[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)时想要自定义控件的外观之外哪些控件上设置其他属性将执行操作。 在示例中的[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)，假设你想要选择指示器上方的复选框的内容以及你希望的 X 指示[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)处于选中状态。 指定在这些更改[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)的[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)。

如下图所示[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)使用的默认值[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。

![一个具有默认控件模板的复选框。](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/ndp-checkboxdefault.png)
一个具有默认控件模板的复选框

如下图所示[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)使用自定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)的内容放置[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)显示 X 选择指示器上方时[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)处于选中状态。

![一个具有自定义控件模板的复选框。](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/ndp-checkboxcustom.png)
一个具有自定义控件模板的复选框

[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)有关[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)在此示例是相对复杂，因此本主题使用简单的示例演示创建[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。



### 更改控件的可视结构

在中WPF，控件通常是一个复合[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)对象。 当您创建[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)，你将结合[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)对象以生成单个控件。 一个[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)必须只有一个[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)作为其根元素。根元素通常包含其他[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)对象。 对象组合构成控件的可视结构。

下面的示例创建一个自定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。 [ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)创建的可视结构[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。 在按钮上方移动鼠标指针或单击它时，此示例不会更改按钮的外观。 本主题后面部分将讨论当按钮处于其他状态时更改它的外观。

在本示例中，可视结构包括以下部分：

- 一个[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)名为`RootElement`可用作模板的根[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)。
- 一个[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)的子`RootElement`。
- 一个[ContentPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter)显示按钮的内容。 [ContentPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter)使任何类型的对象显示。

```xaml
<ControlTemplate TargetType="Button">
  <Border Name="RootElement">

    <!--Create the SolidColorBrush for the Background 
        as an object elemment and give it a name so 
        it can be referred to elsewhere in the
        control template.-->
    <Border.Background>
      <SolidColorBrush x:Name="BorderBrush" Color="Black"/>
    </Border.Background>

    <!--Create a border that has a different color
        by adding smaller grid. The background of 
        this grid is specificied by the button's 
        Background property.-->
    <Grid Margin="4" Background="{TemplateBinding Background}">

      <!--Use a ContentPresenter to display the Content of
          the Button.-->
      <ContentPresenter
        HorizontalAlignment="{TemplateBinding HorizontalContentAlignment}"
        VerticalAlignment="{TemplateBinding VerticalContentAlignment}"
        Margin="4,5,4,4" />
    </Grid>

  </Border>
</ControlTemplate>
```

### 使用 TemplateBinding 保留控件属性的功能

当您创建一个新[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)，您仍可能想要使用的公共属性来更改控件的外观。 [TemplateBinding](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/templatebinding-markup-extension)标记扩展将绑定中的元素的属性[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)到由控件定义的公共属性。 使用 [TemplateBinding](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/templatebinding-markup-extension) 时，可让控件属性用作模板参数。 换言之，设置控件属性后，该值将传递到包含 [TemplateBinding](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/templatebinding-markup-extension) 的元素。

下面的示例重复使用前面示例的一部分[TemplateBinding](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/templatebinding-markup-extension)绑定中的元素的属性的标记扩展[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)到按钮定义的公共属性。

XAML复制

```xaml
<Grid Margin="4" Background="{TemplateBinding Background}">

  <!--Use a ContentPresenter to display the Content of
      the Button.-->
  <ContentPresenter
    HorizontalAlignment="{TemplateBinding HorizontalContentAlignment}"
    VerticalAlignment="{TemplateBinding VerticalContentAlignment}"
    Margin="4,5,4,4" />
</Grid>
```

在此示例中，[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)具有其[Panel.Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.background)属性模板绑定到[Control.Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)。 因为[Panel.Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.background)是模板绑定，可以创建使用相同的多个按钮[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)并设置[Control.Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)为每个按钮上不同的值。 如果[Control.Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)未通过模板绑定到中的元素的属性[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)，并设置[Control.Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)某个按钮没有任何影响上按钮的外观。

请注意，两个属性的名称不必一样。 在前面的示例中，[Control.HorizontalContentAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.horizontalcontentalignment)的属性[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)模板绑定到[FrameworkElement.HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.horizontalalignment)属性的[ContentPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter)。 这样可以水平放置按钮的内容。[ContentPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter) 不具有名为的属性`HorizontalContentAlignment`，但[Control.HorizontalContentAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.horizontalcontentalignment)可以绑定到[FrameworkElement.HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.horizontalalignment)。 在通过模板绑定属性时，请确保目标属性和源属性属于同一类型。

[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)类定义控件模板必须用于在设置完成后会影响在控件上的多个属性。 如何将[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)属性依赖于属性的使用。 [ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)必须通过以下方式之一使用属性：

- 中的某个元素[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)模板绑定到属性。
- 中的元素[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)从父项继承属性[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)。

下表列出了由从控件继承的可视属性[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)类。 它还指示控件的默认控件模板是使用继承的属性值，还是必须通过模板绑定。

| 属性                                                         | 使用方法           |
| ------------------------------------------------------------ | ------------------ |
| [Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background) | 模板绑定           |
| [BorderThickness](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.borderthickness) | 模板绑定           |
| [BorderBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.borderbrush) | 模板绑定           |
| [FontFamily](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontfamily) | 属性继承或模板绑定 |
| [FontSize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontsize) | 属性继承或模板绑定 |
| [FontStretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontstretch) | 属性继承或模板绑定 |
| [FontWeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontweight) | 属性继承或模板绑定 |
| [Foreground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.foreground) | 属性继承或模板绑定 |
| [HorizontalContentAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.horizontalcontentalignment) | 模板绑定           |
| [Padding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.padding) | 模板绑定           |
| [VerticalContentAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.verticalcontentalignment) | 模板绑定           |

表列出了仅从继承的可视属性[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)类。 除了表中列出的属性，该控件还可能会继承[DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext)， [Language](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.language)，和[TextDecorations](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.textdecorations)从父框架元素的属性。

此外，如果[ContentPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter)处于[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)的[ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)，则[ContentPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter)将自动绑定到[ContentTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.contenttemplate)和[Content](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.content)属性。 同样，[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)所在的域[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)的[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)将自动绑定到[Items](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.items)和[ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter)属性。

下面的示例创建两个按钮，它们使用[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)中前面的示例中定义。 该示例设置[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)， [Foreground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.foreground)，和[FontSize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontsize)上每个按钮的属性。 设置[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)属性才有效，因为它是中通过模板绑定[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。 即使[Foreground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.foreground)和[FontSize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontsize)属性不是模板绑定，将它们设置起作用，因为它们的值继承。

XAML复制

```xaml
<StackPanel>
  <Button Style="{StaticResource newTemplate}" 
          Background="Navy" Foreground="White" FontSize="14"
          Content="Button1"/>

  <Button Style="{StaticResource newTemplate}" 
          Background="Purple" Foreground="White" FontSize="14"
          Content="Button2" HorizontalContentAlignment="Left"/>
</StackPanel>
```

前面的示例生成类似于下图的输出。

![两个按钮、 一个蓝色和一个紫色。](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/ndp-buttontwo.png)
背景色不同的两个按钮



### 根据控件状态更改它的外观

显示默认外观的按钮与前面示例中按钮的差异在于，默认按钮在处于不同状态时会略有变化。 例如，在按下按钮或鼠标指针悬停在它的上方时，默认按钮的外观将发生变化。 尽管[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)不更改的功能的一个控件，它会更改控件的可视行为。 可视行为描述控件处于某种状态下的外观。 若要了解控件功能和可视行为之间的差异，请考虑按钮示例。 按钮的功能是引发[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件时单击它时，但按钮的可视行为是在指向或按下时更改其外观。

您使用[VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate)对象处于特定状态时指定控件的外观。 一个[VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate)包含[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)更改中的元素的外观[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。 不需要编写任何代码即可使它发生，因为控件逻辑使用更改状态[VisualStateManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstatemanager)。 在控制进入由指定的状态[VisualState.Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate.name)属性，[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)开始。 当控件退出该状态，[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)停止。

下面的示例演示[VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate)更改的外观[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)当鼠标指针位于其上方。 [Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)通过更改的颜色更改按钮的边框颜色`BorderBrush`。 如果您参考[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)示例在本主题开始时，将会记得`BorderBrush`的名称[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)分配给[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border.background)的[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)。

```xaml
<!--Change the border of the button to red when the
    mouse is over the button.-->
<VisualState x:Name="MouseOver">
  <Storyboard>
    <ColorAnimation Storyboard.TargetName="BorderBrush"     
                    Storyboard.TargetProperty="Color"
                    To="Red" />

  </Storyboard>
</VisualState>
```

该控件负责将各种状态定义为控件协定的一部分，这将在本主题后面的[通过了解控件协定自定义其他控件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control#customizing_other_controls_by_understanding_the_control_contract)中进行详细讨论。 下表列出了为指定的状态[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。

| VisualState 名称 | VisualStateGroup 名称 | 描述                     |
| ---------------- | --------------------- | ------------------------ |
| 普通             | CommonStates          | 默认状态。               |
| MouseOver        | CommonStates          | 鼠标指针悬停在控件上方。 |
| 已按下           | CommonStates          | 已按下控件。             |
| 已禁用           | CommonStates          | 已禁用控件。             |
| 已设定焦点       | FocusStates           | 控件有焦点。             |
| 失去焦点         | FocusStates           | 控件没有焦点。           |

[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)定义两个状态组：`CommonStates`组中包含`Normal`， `MouseOver`， `Pressed`，并`Disabled`状态。 `FocusStates` 组包含 `Focused` 和 `Unfocused` 状态。 同一状态组中的状态之间相互排斥。 控件在每个组中始终处于一种状态下。 例如，[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)可以具有焦点的鼠标指针不是通过它，因此，即使[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)中`Focused`状态可以采用`MouseOver`， `Pressed`，或`Normal`状态。

您将添加[VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate)对象添加到[VisualStateGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstategroup)对象。 您将添加[VisualStateGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstategroup)对象添加到[VisualStateGroups](https://msdn.microsoft.com/library/system.windows.visualstatemanager.visualstategroups.aspx)附加属性。 下面的示例定义[VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate)对象的`Normal`， `MouseOver`，和`Pressed`状态，都在`CommonStates`组。[Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate.name)每个[VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate)与上表中的名称匹配。 省略 `Disabled` 状态和 `FocusStates` 组中的各种状态是为了使示例保持简短，但本主题末尾的完整示例将它们包括在内。

 备注

请务必设置[VisualStateGroups](https://msdn.microsoft.com/library/system.windows.visualstatemanager.visualstategroups.aspx)附加属性的根[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)的[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。

XAML复制

```xaml
<ControlTemplate TargetType="Button">
  <Border Name="RootElement">

    <VisualStateManager.VisualStateGroups>

      <!--Define the states and transitions for the common states.
          The states in the VisualStateGroup are mutually exclusive to
          each other.-->
      <VisualStateGroup x:Name="CommonStates">

        <!--The Normal state is the state the button is in
            when it is not in another state from this VisualStateGroup.-->
        <VisualState x:Name="Normal" />

        <!--Change the SolidColorBrush, BorderBrush, to red when the
            mouse is over the button.-->
        <VisualState x:Name="MouseOver">
          <Storyboard>
            <ColorAnimation Storyboard.TargetName="BorderBrush" 
                            Storyboard.TargetProperty="Color" 
                            To="Red" />
          </Storyboard>
        </VisualState>

        <!--Change the SolidColorBrush, BorderBrush, to Transparent when the
            button is pressed.-->
        <VisualState x:Name="Pressed">
          <Storyboard>
            <ColorAnimation Storyboard.TargetName="BorderBrush" 
                            Storyboard.TargetProperty="Color"
                            To="Transparent"/>
          </Storyboard>
        </VisualState>

        <!--The Disabled state is omitted for brevity.-->
      </VisualStateGroup>
    </VisualStateManager.VisualStateGroups>

    <Border.Background>
      <SolidColorBrush x:Name="BorderBrush" Color="Black"/>
    </Border.Background>

    <Grid Background="{TemplateBinding Background}" Margin="4">
      <ContentPresenter
        HorizontalAlignment="{TemplateBinding HorizontalContentAlignment}"
        VerticalAlignment="{TemplateBinding VerticalContentAlignment}"
        Margin="4,5,4,4" />
    </Grid>
  </Border>
</ControlTemplate>
```

前面的示例生成类似于下图的输出。

![一个具有自定义控件模板的按钮。](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/ndp-buttonnormal.png)
使用正常状态下的自定义控件模板的按钮

![一个具有红色边框的按钮。](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/ndp-buttonmouseover.png)
使用鼠标悬停状态下的自定义控件模板的按钮

![此边框是透明的按下的按钮。](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/ndp-buttonpressed.png)
使用按下状态下的自定义控件模板的按钮

若要查找附带在 WPF 中的控件的可视状态，请参阅 [Control 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/control-styles-and-templates)。



### 指定控件在状态之间转换时的行为

在前面的示例中，按钮的外观在用户单击它时也会发生更改，但除非按钮按下整整一秒，否则用户将看不到效果。 默认情况下，动画需要一秒才会发生。 用户是单击并释放按钮的时间少得多，因为可视反馈将不会生效，如果将[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为默认状态。

您可以指定发生平滑地通过添加转换从一个状态到另一个控制动画所需的时间量[VisualTransition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualtransition)对象添加到[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。 当你创建[VisualTransition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualtransition)，指定一个或多项操作：

- 在状态之间进行转换所需的时间。
- 在转换的同时，控件外观发生的其他更改。
- 哪些状态[VisualTransition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualtransition)应用于。

#### 指定转换的持续时间

您可以指定多长时间转换所需的设置[GeneratedDuration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualtransition.generatedduration)属性。 前面的示例包含[VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate)，它指定按钮的边框在时按下按钮时，但动画时间太长而引起注意，如果快速按下并释放按钮将变为透明。 可以使用[VisualTransition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualtransition)若要指定的时间花费在控件转换为按下状态。 以下示例指定控件需要百分之一秒进入按下状态。

```xaml
<!--Take one hundredth of a second to transition to the
    Pressed state.-->
<VisualTransition To="Pressed" 
                  GeneratedDuration="0:0:0.01" />
```

#### 指定转换时控件外观发生的更改

[VisualTransition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualtransition)包含[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)控件状态之间转换时的开始。 例如，可以指定控件从 `MouseOver` 状态转换到 `Normal` 状态时发生的某个动画。 下面的示例创建[VisualTransition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualtransition)，它指定，当用户移动鼠标指针从按钮，按钮边框更改为蓝色，则为黄色，则为黑色 1.5 秒。

```xaml
<!--Take one and a half seconds to transition from the
    MouseOver state to the Normal state. 
    Have the SolidColorBrush, BorderBrush, fade to blue, 
    then to yellow, and then to black in that time.-->
<VisualTransition From="MouseOver" To="Normal" 
                      GeneratedDuration="0:0:1.5">
  <Storyboard>
    <ColorAnimationUsingKeyFrames
      Storyboard.TargetProperty="Color"
      Storyboard.TargetName="BorderBrush"
      FillBehavior="HoldEnd" >

      <ColorAnimationUsingKeyFrames.KeyFrames>

        <LinearColorKeyFrame Value="Blue" 
          KeyTime="0:0:0.5" />
        <LinearColorKeyFrame Value="Yellow" 
          KeyTime="0:0:1" />
        <LinearColorKeyFrame Value="Black" 
          KeyTime="0:0:1.5" />

      </ColorAnimationUsingKeyFrames.KeyFrames>
    </ColorAnimationUsingKeyFrames>
  </Storyboard>
</VisualTransition>
```

#### 指定何时应用 VisualTransition

一个[VisualTransition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualtransition)可限制要应用于仅某些状态，或可以应用任何时候，只要状态之间的控制转换。 在前面的示例中，[VisualTransition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualtransition)时在控件转换从应用`MouseOver`状态变为`Normal`状态; 在该示例之前，[VisualTransition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualtransition)时在控件转换为应用`Pressed`状态。 限制何时[VisualTransition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualtransition)应用设置[To](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualtransition.to)和[From](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualtransition.from)属性。 下表描述了从最严限制到最宽松限制的限制级别。

| 限制类型                       | 起始值                                                       | 目标值                                                       |
| ------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 从一个指定状态到另一个指定状态 | 名称 [VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate) | 名称 [VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate) |
| 从任意状态到指定状态           | 未设置                                                       | 名称 [VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate) |
| 从指定状态到任意状态           | 名称 [VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate) | 未设置                                                       |
| 从任意状态到其他任意状态       | 未设置                                                       | 未设置                                                       |

可以有多个[VisualTransition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualtransition)中的对象[VisualStateGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstategroup)的引用相同的状态，但它们将使用上一个表指定的顺序。在以下示例中，有两个[VisualTransition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualtransition)对象。 该控件时从过渡`Pressed`状态变为`MouseOver`状态，[VisualTransition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualtransition)同时具有[From](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualtransition.from)和[To](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualtransition.to)使用集。 当控件从非 `Pressed` 的状态转换为 `MouseOver` 状态时，将使用另一种状态。

XAML复制

```xaml
<!--Take one half second to trasition to the MouseOver state.-->
<VisualTransition To="MouseOver" 
                  GeneratedDuration="0:0:0.5" />

<!--Take one hundredth of a second to transition from the
    Pressed state to the MouseOver state.-->
<VisualTransition From="Pressed" To="MouseOver" 
                  GeneratedDuration="0:0:0.01" />
```

[VisualStateGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstategroup)已[Transitions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstategroup.transitions)属性，其中包含[VisualTransition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualtransition)适用于对象[VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate)中的对象[VisualStateGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstategroup)。 作为[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)名作者，你可以自由地包括任何[VisualTransition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualtransition)想。 但是，如果[To](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualtransition.to)并[From](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualtransition.from)属性设置为不在的州名[VisualStateGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstategroup)，则[VisualTransition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualtransition)将被忽略。

下面的示例演示[VisualStateGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstategroup)为`CommonStates`。 该示例定义了[VisualTransition](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualtransition)为每个按钮的下列转换。

- 转换为 `Pressed` 状态。
- 转换为 `MouseOver` 状态。
- 从 `Pressed` 状态转换为 `MouseOver` 状态。
- 从 `MouseOver` 状态转换为 `Normal` 状态。

XAML复制

```xaml
<VisualStateGroup x:Name="CommonStates">

  <!--Define the VisualTransitions that
      can be used when the control transitions 
      between VisualStates that are defined in the
      VisualStatGroup.-->
  <VisualStateGroup.Transitions>

    <!--Take one hundredth of a second to 
        transition to the Pressed state.-->
    <VisualTransition To="Pressed" 
                      GeneratedDuration="0:0:0.01" />

    <!--Take one half second to trasition 
        to the MouseOver state.-->
    <VisualTransition To="MouseOver" 
                      GeneratedDuration="0:0:0.5" />

    <!--Take one hundredth of a second to transition from the
        Pressed state to the MouseOver state.-->
    <VisualTransition From="Pressed" To="MouseOver" 
                      GeneratedDuration="0:0:0.01" />

    <!--Take one and a half seconds to transition from the
        MouseOver state to the Normal state. 
        Have the SolidColorBrush, BorderBrush, fade to blue, 
        then to yellow, and then to black in that time.-->
    <VisualTransition From="MouseOver" To="Normal" 
                      GeneratedDuration="0:0:1.5">
      <Storyboard>
        <ColorAnimationUsingKeyFrames
          Storyboard.TargetProperty="Color"
          Storyboard.TargetName="BorderBrush"
          FillBehavior="HoldEnd" >

          <ColorAnimationUsingKeyFrames.KeyFrames>
            <LinearColorKeyFrame Value="Blue" 
              KeyTime="0:0:0.5" />
            <LinearColorKeyFrame Value="Yellow" 
              KeyTime="0:0:1" />
            <LinearColorKeyFrame Value="Black" 
              KeyTime="0:0:1.5" />

          </ColorAnimationUsingKeyFrames.KeyFrames>
        </ColorAnimationUsingKeyFrames>
      </Storyboard>
    </VisualTransition>
  </VisualStateGroup.Transitions>

  <!--The remainder of the VisualStateGroup is the
      same as the previous example.-->

  <VisualState x:Name="Normal" />

  <VisualState x:Name="MouseOver">
    <Storyboard>
      <ColorAnimation 
        Storyboard.TargetName="BorderBrush" 
        Storyboard.TargetProperty="Color" 
        To="Red" />

    </Storyboard>
  </VisualState>

  <VisualState x:Name="Pressed">
    <Storyboard>
      <ColorAnimation 
        Storyboard.TargetName="BorderBrush" 
        Storyboard.TargetProperty="Color" 
        To="Transparent"/>
    </Storyboard>
  </VisualState>

  <!--The Disabled state is omitted for brevity.-->

</VisualStateGroup>
```



### 通过了解控件协定自定义其他控件

使用的控件[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)来指定其可视结构 (通过使用[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)对象) 和可视行为 (通过使用[VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate)对象) 使用部件控件模型。 WPF 4 附带的许多控件均使用此模型。 部件的[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)作者需要注意的通过控件协定。 了解控件协定的各个部件后，可以自定义使用部件控件模型的任意控件的外观。

控件协定具有三个元素：

- 控件逻辑使用的可视元素。
- 控件状态和每种状态所属的组。
- 以可视方式影响控件的公共属性。

#### 控件协定中的可视元素

控件的逻辑与的交互有时[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)所在的域[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。 例如，控件可能会处理它的其中一个元素的事件。 当控件希望查找特定[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)中[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)，它必须该信息传达给[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)作者。 该控件使用[TemplatePartAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.templatepartattribute)要传达的预期，元素和元素的名称应为类型。 [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)不具有[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)部件在它的控件协定，但其他控件，如[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)，执行操作。

下面的示例演示[TemplatePartAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.templatepartattribute)指定的对象[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)类。 逻辑[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)期望找到[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)名为`PART_EditableTextBox`和一个[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)名为`PART_Popup`中其[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。

```csharp
[TemplatePartAttribute(Name = "PART_EditableTextBox", Type = typeof(TextBox))]
[TemplatePartAttribute(Name = "PART_Popup", Type = typeof(Popup))]
public class ComboBox : ItemsControl
{
}
```

下面的示例演示一个简单[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)有关[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)包含由指定的元素[TemplatePartAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.templatepartattribute)对象上[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)类。

```xaml
<ControlTemplate TargetType="ComboBox">
  <Grid>
    <ToggleButton x:Name="DropDownToggle"
      HorizontalAlignment="Stretch" VerticalAlignment="Stretch"  
      Margin="-1" HorizontalContentAlignment="Right"
      IsChecked="{Binding Path=IsDropDownOpen,Mode=TwoWay,
                  RelativeSource={RelativeSource TemplatedParent}}">
      <Path x:Name="BtnArrow" Height="4" Width="8" 
        Stretch="Uniform" Margin="0,0,6,0"  Fill="Black"
        Data="F1 M 300,-190L 310,-190L 305,-183L 301,-190 Z " />
    </ToggleButton>
    <ContentPresenter x:Name="ContentPresenter" Margin="6,2,25,2"
      Content="{TemplateBinding SelectionBoxItem}"
      ContentTemplate="{TemplateBinding SelectionBoxItemTemplate}"
      ContentTemplateSelector="{TemplateBinding ItemTemplateSelector}">
    </ContentPresenter>
    <TextBox x:Name="PART_EditableTextBox"
      Style="{x:Null}"
      Focusable="False"
      Background="{TemplateBinding Background}"
      HorizontalAlignment="Left" 
      VerticalAlignment="Center" 
      Margin="3,3,23,3"
      Visibility="Hidden"
      IsReadOnly="{TemplateBinding IsReadOnly}"/>

    <Popup x:Name="PART_Popup"
      IsOpen="{TemplateBinding IsDropDownOpen}">
      <Border x:Name="PopupBorder" 
        HorizontalAlignment="Stretch" Height="Auto" 
        MinWidth="{TemplateBinding ActualWidth}"
        MaxHeight="{TemplateBinding MaxDropDownHeight}"
        BorderThickness="{TemplateBinding BorderThickness}" 
        BorderBrush="Black" Background="White" CornerRadius="3">
        <ScrollViewer x:Name="ScrollViewer" BorderThickness="0" Padding="1">
          <ItemsPresenter/>
        </ScrollViewer>
      </Border>
    </Popup>

  </Grid>
</ControlTemplate>
```

#### 控件协定中的状态

控件状态也属于控件协定。 创建的示例[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)有关[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)演示如何指定的外观[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)具体取决于其状态。 您创建[VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate)为每个指定的状态并使所有[VisualState](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstate)对象的共享[GroupName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.templatevisualstateattribute.groupname)中[VisualStateGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.visualstategroup)，如中所述[更改其状态根据控件的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/customizing-the-appearance-of-an-existing-control#changing_the_appearance_of_a_control_depending_on_its_state)前面的这本主题。 第三方控件应使用指定状态[TemplateVisualStateAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.templatevisualstateattribute)，这样设计器工具，例如 Expression Blend，以公开控件的状态以创作控件模板。

若要查找 WPF 中随附的控件的控件协定，请参阅 [Control 样式和模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/control-styles-and-templates)。

#### 控件协定中的属性

以可视方式影响控件的公共属性也包含在控件协定中。 可以设置这些属性来更改控件的外观，而无需创建一个新[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。 此外可以使用[TemplateBinding](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/templatebinding-markup-extension)绑定中的元素的属性的标记扩展[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)到由定义的公共属性[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。

以下示例展示了按钮的控件协定。

```csharp
[TemplateVisualState(Name = "Normal", GroupName = "CommonStates")]
[TemplateVisualState(Name = "MouseOver", GroupName = "CommonStates")]
[TemplateVisualState(Name = "Pressed", GroupName = "CommonStates")]
[TemplateVisualState(Name = "Disabled", GroupName = "CommonStates")]
[TemplateVisualState(Name = "Unfocused", GroupName = "FocusStates")]
[TemplateVisualState(Name = "Focused", GroupName = "FocusStates")]
public class Button : ButtonBase
{
    public static readonly DependencyProperty BackgroundProperty;
    public static readonly DependencyProperty BorderBrushProperty;
    public static readonly DependencyProperty BorderThicknessProperty;
    public static readonly DependencyProperty ContentProperty;
    public static readonly DependencyProperty ContentTemplateProperty;
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
    public object Content { get; set; }
    public DataTemplate ContentTemplate { get; set; }
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

创建时[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)，它通常是最简单的方法开始与某个现有[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)并对其进行更改。 可以执行下列任一操作，更改现有[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate):

- 使用设计器（例如 Expression Blend），它可以提供用于创建控件模板的图形用户界面。 有关详细信息，请参阅[设置支持模板的控件的样式](https://go.microsoft.com/fwlink/?LinkId=161153)。
- 获取默认[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)和对其进行编辑。 若要查找 WPF 随附的默认控件模板，请参阅[默认 WPF 主题](https://go.microsoft.com/fwlink/?LinkID=158252)。

#### 完整的示例

下面的示例演示的完整[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)本主题中讨论。

```xaml
<StackPanel>
  <StackPanel.Resources>
    <Style TargetType="Button" x:Key="newTemplate">
      <!--Set the Background, Foreground, FontSize, Width, 
                  Height, Margin, and Template properties for
                  the Button.-->
      <Setter Property="Background" Value="Navy"/>
      <Setter Property="Foreground" Value="White"/>
      <Setter Property="FontSize" Value="14"/>
      <Setter Property="Width" Value="100"/>
      <Setter Property="Height" Value="40"/>
      <Setter Property="Margin" Value="10"/>
      <Setter Property="HorizontalContentAlignment" Value="Center"/>
      <Setter Property="VerticalContentAlignment" Value="Center"/>
      <Setter Property="Template">
        <Setter.Value>
          <ControlTemplate TargetType="Button">
            <Border x:Name="RootElement">
              <VisualStateManager.VisualStateGroups>

                <!--Define the states and transitions for the common states.
                    The states in the VisualStateGroup are mutually exclusive to
                    each other.-->
                <VisualStateGroup Name="CommonStates">

                  <!--Define the VisualTransitions that can be used when the control
                      transitions between VisualStates that are defined in the
                      VisualStatGroup.-->
                  <VisualStateGroup.Transitions>

                    <!--Take one hundredth of a second to transition to the
                        Pressed state.-->
                    <VisualTransition To="Pressed" 
                                      GeneratedDuration="0:0:0.01" />

                    <!--Take one half second to trasition to the MouseOver state.-->
                    <VisualTransition To="MouseOver" 
                                      GeneratedDuration="0:0:0.5" />

                    <!--Take one hundredth of a second to transition from the
                        Pressed state to the MouseOver state.-->
                    <VisualTransition From="Pressed" To="MouseOver" 
                                      GeneratedDuration="0:0:0.01" />

                    <!--Take one and a half seconds to transition from the
                        MouseOver state to the Normal state. 
                        Have the SolidColorBrush, BorderBrush, fade to blue, 
                        then to yellow, and then to black in that time.-->
                    <VisualTransition From="MouseOver" To="Normal" 
                                          GeneratedDuration="0:0:1.5">
                      <Storyboard>
                        <ColorAnimationUsingKeyFrames
                          Storyboard.TargetProperty="Color"
                          Storyboard.TargetName="BorderBrush"
                          FillBehavior="HoldEnd" >

                          <ColorAnimationUsingKeyFrames.KeyFrames>

                            <LinearColorKeyFrame Value="Blue" 
                              KeyTime="0:0:0.5" />
                            <LinearColorKeyFrame Value="Yellow" 
                              KeyTime="0:0:1" />
                            <LinearColorKeyFrame Value="Black" 
                              KeyTime="0:0:1.5" />

                          </ColorAnimationUsingKeyFrames.KeyFrames>
                        </ColorAnimationUsingKeyFrames>
                      </Storyboard>
                    </VisualTransition>
                  </VisualStateGroup.Transitions>

                  <!--The Normal state is the state the button is in
                      when it is not in another state from this VisualStateGroup.
                      There is no special visual behavior for this state, but
                      the VisualState must be defined in order for the button
                      to return to its initial state.-->
                  <VisualState x:Name="Normal" />

                  <!--Change the border of the button to red when the
                      mouse is over the button.-->
                  <VisualState x:Name="MouseOver">
                    <Storyboard>
                      <ColorAnimation Storyboard.TargetName="BorderBrush"     
                                      Storyboard.TargetProperty="Color"
                                      To="Red" />

                    </Storyboard>
                  </VisualState>

                  <!--Change the border of the button to Transparent when the
                      button is pressed.-->
                  <VisualState x:Name="Pressed">
                    <Storyboard >
                      <ColorAnimation Storyboard.TargetName="BorderBrush" 
                                      Storyboard.TargetProperty="Color" 
                                      To="Transparent" 
                                      />
                    </Storyboard>
                  </VisualState>

                  <!--Show the DisabledRect when the IsEnabled property on
                      the button is false.-->
                  <VisualState x:Name="Disabled">
                    <Storyboard>
                      <DoubleAnimation Storyboard.TargetName="DisabledRect" 
                                       Storyboard.TargetProperty="Opacity"
                                       To="1" Duration="0" />
                    </Storyboard>
                  </VisualState>
                </VisualStateGroup>

                <!--Define the states and transitions for the focus states.
                    The states in the VisualStateGroup are mutually exclusive to
                    each other.-->
                <VisualStateGroup x:Name="FocusStates">

                  <!--Define the VisualStates in this VistualStateGroup.-->
                  <VisualState x:Name="Focused">
                    <Storyboard>
                      <ObjectAnimationUsingKeyFrames 
                        Storyboard.TargetName="FocusVisual" 
                        Storyboard.TargetProperty="Visibility" Duration
                        ="0">
                        
                        <DiscreteObjectKeyFrame KeyTime="0">
                          <DiscreteObjectKeyFrame.Value>
                            <Visibility>Visible</Visibility>
                          </DiscreteObjectKeyFrame.Value>
                        </DiscreteObjectKeyFrame>
                      </ObjectAnimationUsingKeyFrames>
                    </Storyboard>
                  </VisualState>
                  <VisualState x:Name="Unfocused">
                    <Storyboard>
                      <ObjectAnimationUsingKeyFrames 
                        Storyboard.TargetName="FocusVisual" 
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
              </VisualStateManager.VisualStateGroups>

              <!--Create the SolidColorBrush for the Background 
                  as an object elemment and give it a name so 
                  it can be referred to elsewhere in the control template.-->
              <Border.Background>
                <SolidColorBrush x:Name="BorderBrush" Color="Black"/>
              </Border.Background>

              <!--Create a border that has a different color by adding smaller grid.
                  The background of this grid is specified by the button's Background
                  property.-->
              <Grid Background="{TemplateBinding Background}" Margin="4">

                <!--Create a Rectangle that indicates that the
                    Button has focus.-->
                <Rectangle Name="FocusVisual" 
                           Visibility="Collapsed" Margin="2" 
                           Stroke="{TemplateBinding Foreground}" 
                           StrokeThickness="1" 
                           StrokeDashArray="1.5 1.5"/>

                <!--Use a ContentPresenter to display the Content of
                    the Button.-->
                <ContentPresenter
                  HorizontalAlignment="{TemplateBinding HorizontalContentAlignment}"
                  VerticalAlignment="{TemplateBinding VerticalContentAlignment}"
                  Margin="4,5,4,4" />

                <!--Create a rectangle that causes the button to appear
                    grayed out when it is disabled.-->
                <Rectangle x:Name="DisabledRect" 
                         Fill="#A5FFFFFF"
                         Opacity="0" IsHitTestVisible="false" />
              </Grid>
            </Border>
          </ControlTemplate>
        </Setter.Value>
      </Setter>
    </Style>

  </StackPanel.Resources>

  <Button Style="{StaticResource newTemplate}" 
          Content="Button1"/>

  <Button Style="{StaticResource newTemplate}"
          Background="Purple" 
          Content="Button2" />
</StackPanel>
```

## [How to: Find ControlTemplate-Generated Elements](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-find-controltemplate-generated-elements)

此示例演示如何查找生成的元素[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。

下面的示例演示创建一个简单的样式[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)类：

```xaml
<Style TargetType="{x:Type Button}">
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type Button}">
        <Grid Margin="5" Name="grid">
          <Ellipse Stroke="DarkBlue" StrokeThickness="2">
            <Ellipse.Fill>
              <RadialGradientBrush Center="0.3,0.2" RadiusX="0.5" RadiusY="0.5">
                <GradientStop Color="Azure" Offset="0.1" />
                <GradientStop Color="CornflowerBlue" Offset="1.1" />
              </RadialGradientBrush>
            </Ellipse.Fill>
          </Ellipse>
          <ContentPresenter Name="content" Margin="10"
                            HorizontalAlignment="Center" VerticalAlignment="Center"/>
        </Grid>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

若在应用该模板后，需要查找模板内的元素，可以调用该[FindName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworktemplate.findname)的[Template](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.template)方法。 下面的示例创建一个消息框，显示控件模板中[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)的实际宽度值： 下面的示例创建一个消息框，显示的实际宽度值[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)在控件模板中：

```csharp
// Finding the grid that is generated by the ControlTemplate of the Button
Grid gridInTemplate = (Grid)myButton1.Template.FindName("grid", myButton1);

// Do something to the ControlTemplate-generated grid
MessageBox.Show("The actual width of the grid in the ControlTemplate: "
    + gridInTemplate.GetValue(Grid.ActualWidthProperty).ToString());
```