# [Popup](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/popup)

[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)控件通过当前的应用程序窗口浮动的单独窗口中显示内容。

下图显示[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)相对于定位的控件[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)，它是其父级。

![Popup 图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/popuppicture.jpg)

## 本节内容

[Popup 概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/popup-overview)
[Popup 放置行为](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/popup-placement-behavior)
[帮助主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/popup-how-to-topics)

## [Popup Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/popup-overview)

[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)控件提供了一种方法来相对于指定元素或屏幕坐标在当前应用程序窗口上浮动的单独窗口中显示内容。 本主题介绍[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)控件并提供有关其用法的信息。

### 什么是 Popup？

一个[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)控件相对于元素或屏幕上的点的单独窗口中显示内容。 当[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)可见，请[IsOpen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.isopen)属性设置为`true`。

> 一个[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)不会自动打开当鼠标指针移动到其父对象。 如果你想[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)若要自动打开，请使用[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)或[ToolTipService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltipservice)类。 有关详细信息，请参阅 [ToolTip 概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/tooltip-overview)。

### 创建弹出项。

下面的示例演示如何定义[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)控件的子元素[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)控件。 因为[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)可以具有只有一个子元素，此示例中的文本放[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)并[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)中的控件[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)。 内容[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)将出现在[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)控件，用于靠近相关的应用程序窗口上浮动的单独窗口中显示其文本[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)控件。

```xaml
<Button HorizontalAlignment="Left" Click="DisplayPopup" 
        Width="150" Margin="20,10,0,0">
  <StackPanel>
    <TextBlock>Display Your Popup Text</TextBlock>
    <Popup Name="myPopup">
      <TextBlock Name="myPopupText" 
                 Background="LightBlue" 
                 Foreground="Blue">
        Popup Text
      </TextBlock>
    </Popup>
  </StackPanel>
</Button>
```

XAML复制

```xaml
<Button Name="ButtonForPopup" HorizontalAlignment="Left" 
        Click="CreatePopup"  
        Width="150" Margin="20,10,0,0">
  <StackPanel Name="aStackPanel">
    <TextBlock>Create Popup</TextBlock>
  </StackPanel>
</Button>
```



### 实现 Popup 的控件

您可以构建[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)控件添加到其他控件。 以下控件实现[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)特定用途的控件：

- [ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)。 如果你想要创建一个元素的工具提示，使用[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)和[ToolTipService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltipservice)类。 有关详细信息，请参阅 [ToolTip 概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/tooltip-overview)。
- [ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)。 如果你想要创建的元素的上下文菜单，使用[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)控件。 有关详细信息，请参阅 [ContextMenu 概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/contextmenu-overview)。
- [ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)。 如果你想要创建具有可显示或隐藏，使用下拉列表框的选择控件[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)控件。
- [Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)。 如果你想要创建用于显示具有可折叠区域的标头控件的显示内容，请使用[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)控件。 有关详细信息，请参阅 [Expander 概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/expander-overview)。

### Popup 行为和外观

[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)控件提供的功能，允许你自定义其行为和外观。 例如，可以设置打开和关闭行为、 动画、 不透明度和位图效果和[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)大小和位置。

#### 打开和关闭行为

一个[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)控件显示其内容时[IsOpen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.isopen)属性设置为`true`。 默认情况下[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)保持打开状态，直到[IsOpen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.isopen)属性设置为`false`。 但是，可以通过设置更改默认行为[StaysOpen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.staysopen)属性设置为`false`。 此属性设置为`false`，则[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)内容窗口具有鼠标捕获。 [Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)失去鼠标捕获并且该窗口将关闭外发生鼠标事件时[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)窗口。

[Opened](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.opened)并[Closed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.closed)会引发事件时[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)内容窗口是打开还是关闭。

#### 动画

[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)控件具有通常与淡入和滑入等行为相关联的动画的内置支持。 可以通过设置来打开这些动画[PopupAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.popupanimation)属性设置为[PopupAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popupanimation)枚举值。 有关[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)动画能够正常运行，必须设置[AllowsTransparency](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.allowstransparency)属性设置为`true`。

您还可以应用之类的动画[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)到[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)控件。

#### 不透明度和位图效果

[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)属性[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)控件对其内容无效。 默认情况下，[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)内容窗口是不透明。 若要创建一个透明[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)，将[AllowsTransparency](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.allowstransparency)属性设置为`true`。

内容[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)不会继承位图效果，如[DropShadowBitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.dropshadowbitmapeffect)，直接设置上[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)控件或父窗口中的任何其他元素上。 若要显示的内容的位图效果[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)，必须设置其内容上直接的位图效果。 例如，如果的子级[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)是[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)，在设置位图效果[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)。

#### Popup 大小

默认情况下，[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)其内容自动调整大小。 因为时自动调整大小时，可能会隐藏某些位图效果为定义的屏幕区域的默认大小[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)内容不提供足够的空间要显示的位图效果。

[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup) 在设置时，还可以遮盖内容[RenderTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransform)的内容。 如果某些内容可能隐藏在此方案中，已转换的内容[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)超出原始区域[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 如果位图效果或转换需要更多的空间，则可以定义周围的边距[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)内容以便为控件提供更多的区域。

### 定义 Popup 位置

可以通过设置定位 popup [PlacementTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementtarget)， [PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)， [Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placement)， [HorizontalOffset](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.horizontaloffset)，和[VerticalOffsetProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.verticaloffsetproperty)属性。 有关详细信息，请参阅 [Popup 放置行为](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/popup-placement-behavior)。 当[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)会显示在屏幕上，它不会不会重新定位自身如果器重定位到其父级。

#### 自定义 Popup 放置

你可以自定义的位置[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)通过指定一组坐标是相对于控件[PlacementTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementtarget)想[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)才会显示。

若要自定义位置，请设置[Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placement)属性设置为[Custom](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Custom)。 然后，定义[CustomPopupPlacementCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.custompopupplacementcallback)委托中，返回一组可能的位置点和主轴 （按优先顺序） [Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 显示的最大一部分的点[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)自动选择。 有关示例，请参阅[指定自定义 Popup 位置](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-specify-a-custom-popup-position)。

### Popup 和可视化树

一个[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)控件不具有其自己的可视化树; 而是返回大小为 0 （零） 时[MeasureOverride](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.measureoverride)方法[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)调用。 但是，设置[IsOpen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.isopen)的属性[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)到`true`，创建具有其自己的可视化树的新窗口。 新窗口中包含[Child](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.child)内容的[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 新窗口的宽度和高度不能超过屏幕宽度或高度的 75%。

[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)控件将保留对引用其[Child](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.child)内容作为一个逻辑子级。 创建新窗口后的内容[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)会变成窗口中的一个可视化子级并保留的逻辑子级[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 也可反过来[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)保持的逻辑父级及其[Child](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.child)内容。

## [Popup Placement Behavior](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/popup-placement-behavior)

一个[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)控件浮动在应用程序上的单独窗口中显示内容。 您可以指定的位置[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)相对于控件、 鼠标或通过使用屏幕[PlacementTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementtarget)， [Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placement)， [PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)， [HorizontalOffset](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.horizontaloffset)，并[VerticalOffset](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.verticaloffset)属性。 这些属性协同工作，可以灵活地指定位置的[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。

> [ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)和[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)类也定义这五个属性和行为与此类似。

### 定位 Popup

位置[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)可以是相对于[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)或整个屏幕。 下面的示例创建四个[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)相对于控件[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)— 在这种情况下，映像中。 所有[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)控件具有[PlacementTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementtarget)属性设置为`image1`，但每个[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)具有不同的放置属性的值。

```xaml
<Canvas Width="200" Height="150">
  <Image Name="image1"
         Canvas.Left="75" 
         Source="Water_lilies.jpg" Height="200" Width="200"/>
  <Popup IsOpen="True" PlacementTarget="{Binding ElementName=image1}"
         Placement="Bottom">
    <TextBlock FontSize="14" Background="LightGreen">Placement=Bottom</TextBlock>

  </Popup>
  <Popup IsOpen="True" PlacementTarget="{Binding ElementName=image1}"
         Placement="Top">
    <TextBlock FontSize="14" Background="LightGreen">Placement=Top</TextBlock>

  </Popup>
  <Popup IsOpen="True" PlacementTarget="{Binding ElementName=image1}"
         Placement="Left">
    <TextBlock FontSize="14" Background="LightGreen">Placement=Left</TextBlock>

  </Popup>
  <Popup IsOpen="True" PlacementTarget="{Binding ElementName=image1}"
         Placement="Right">
    <TextBlock FontSize="14" Background="LightGreen">Placement=Right</TextBlock>

  </Popup>
</Canvas>
```

下图显示图像和[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)控件

![具有四个 popup 控件的图像](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/popupplacementintro.png)
带有四个 Popup 的图像

这个简单的示例演示如何设置[PlacementTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementtarget)和[Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placement)属性，但通过使用[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)， [HorizontalOffset](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.horizontaloffset)，并[VerticalOffset](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.verticaloffset)属性，您可以更多控制的位置[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)定位。



### 术语的定义：Popup 解析

以下术语可了解如何[PlacementTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementtarget)， [Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placement)， [PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)， [HorizontalOffset](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.horizontaloffset)，并[VerticalOffset](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.verticaloffset)互相关联起来的属性和[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup):

- 目标对象
- 目标区域
- 目标原点
- Popup 对齐点

这些条款提供的方便的方法来指代的各个方面[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)和与之关联的控件。

#### 目标对象

*目标对象*是元素的[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)与相关联。 如果[PlacementTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementtarget)属性设置，它指定目标对象。 如果[PlacementTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementtarget)未设置，和[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)具有一个父级，父级是目标对象。 如果没有任何[PlacementTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementtarget)值和父级，没有目标对象，和[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)相对于屏幕定位。

下面的示例创建[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)的子级[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)。 该示例不会设置[PlacementTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementtarget)属性上的[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 默认值为[Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placement)是[PlacementMode.Bottom](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Bottom)，因此[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)如下所示[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)。

```xaml
<Canvas Margin="5" Background="Red" Width="200" Height="150" >

  <Ellipse Canvas.Top="60" Canvas.Left="50"
           Height="85" Width="60" 
           Fill="Black"/>

  <Popup IsOpen="True" >
    <TextBlock Background="LightBlue" FontSize="18">This is a Popup</TextBlock>
  </Popup>
</Canvas>
```

下面的插图阐释[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)相对于定位[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)。

![没有 placementtarget 的 popup 控件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/popupplacementnoplacementtarget.png)
没有 PlacementTarget 的 Popup

下面的示例创建[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)的子级[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)，但这次[PlacementTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementtarget)设置为`ellipse1`，因此下面出现弹出窗口[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)。

XAML复制

```xaml
<Canvas Margin="5" Background="Red" Width="200" Height="150" >

  <Ellipse Name="ellipse1"
           Canvas.Top="60" Canvas.Left="50"
           Height="85" Width="60" 
           Fill="Black"/>

  <Popup IsOpen="True" PlacementTarget="{Binding ElementName=ellipse1}">
    <TextBlock Background="LightBlue" FontSize="18">This is a Popup</TextBlock>
  </Popup>
</Canvas>
```

下面的插图阐释[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)相对于定位[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)。

![相对于椭圆形定位的 popup](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/popupplacementwithplacementtarget.png)
具有 PlacementTarget 的 Popup

 备注

有关[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)，默认值[Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placement)是[Mouse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Mouse)。 有关[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)，默认值[Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placement)是[MousePoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_MousePoint)。 这些值将在后面的“属性如何协同工作”部分中进行说明。

#### 目标区域

*目标区域*是屏幕上的区域的[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)是相对于。 在上一示例中，[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)边界的目标对象，但在某些情况下，与对齐[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)与其他边界对齐即使[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)具有目标对象。 如果[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)属性设置，则目标区域是不同于目标对象的边界。

下面的示例创建两个[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)对象，其中包含每个[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)和一个[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 在这两种情况下，目标对象[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)是[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)。 [Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)在第一个[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)已[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)设置，使用其[X](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.rect.x)， [Y](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.rect.y)， [Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.rect.width)，和[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.rect.height)属性分别设置为 50、 50、 50 和 100。 [Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)在第二个[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)没有[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)设置。 因此，第一个[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)位于如下[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)，第二个[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)定位下面[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)。 每个[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)还包含[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)具有相同的边界[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)的第一个[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 请注意，[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)不会在应用程序; 中创建可见元素的示例创建[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)来表示[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)。

```xaml
<StackPanel Orientation="Horizontal" Margin="50,50,0,0">

  <Canvas Width="200" Height="200" Background="Red">
    <Rectangle Canvas.Top="50" Canvas.Left="50" 
               Width="50" Height="100"
               Stroke="White" StrokeThickness="3"/>
    <Popup IsOpen="True" PlacementRectangle="50,50,50,100">
      <TextBlock FontSize="14" Background="Yellow"
                 Width="140" TextWrapping="Wrap">
        This is a popup with a PlacementRectangle.
      </TextBlock>
    </Popup>
  </Canvas>
  
  <Canvas Width="200" Height="200" Background="Red" Margin="30,0,0,0">
    <Rectangle Canvas.Top="50" Canvas.Left="50" 
               Width="50" Height="100"
               Stroke="White" StrokeThickness="3"/>
    <Popup IsOpen="True">
      <TextBlock FontSize="14" Background="Yellow"
                 Width="140" TextWrapping="Wrap">
        This is a popup without a PlacementRectangle.
      </TextBlock>
    </Popup>
  </Canvas>
  
</StackPanel>
```

下图显示前面示例的结果。

![具有和没有 PlacementRectangle 的 popup](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/popupplacementplacementrectangle.png)
具有和没有 PlacementRectangle 的 Popup

#### 目标原点和目标对齐点

*目标原点*和 *Popup 对齐点*分别是目标区域和 Popup 上用于定位定位的参照点。 可以使用[HorizontalOffset](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.horizontaloffset)和[VerticalOffset](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.verticaloffset)偏移 popup 从目标区域的属性。 [HorizontalOffset](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.horizontaloffset)和[VerticalOffset](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.verticaloffset)相对于目标原点和 popup 对齐点。 值[Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placement)属性确定目标原点和 popup 对齐点的位置。

下面的示例创建[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)，并设置[HorizontalOffset](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.horizontaloffset)和[VerticalOffset](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.verticaloffset)属性设置为 20。 [Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placement)属性设置为[Bottom](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Bottom)（默认值），因此目标原点是目标区域的左下角，popup 对齐点是在左上角的[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。

```xaml
<Canvas Width="200" Height="200" Background="Yellow" Margin="20">
  <Popup IsOpen="True" Placement="Bottom"
         HorizontalOffset="20" VerticalOffset="20">
    <TextBlock FontSize="14" Background="#42F3FD">
      This is a popup.
    </TextBlock>
  </Popup>
</Canvas>
```

下图显示前面示例的结果。

![使用目标原点对齐点的 popup 放置](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/popupplacementtargetoriginalignmentpoint.png)
具有 HorizontalOffset 和 VerticalOffset 的 Popup

### 属性如何协同工作

值[PlacementTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementtarget)， [PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)，和[Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placement)需要共同考虑以找出正确的目标区域、 目标原点和 popup 对齐点。 例如，如果的值[Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placement)是[Mouse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Mouse)，没有目标对象，[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)将被忽略，并为目标区域是鼠标指针的边界。 但是，如果[Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placement)是[Bottom](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Bottom)，则[PlacementTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementtarget)或父级确定目标对象和[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)确定目标区域。

下表介绍目标对象、 目标区域、 目标原点和 popup 对齐点，并指示是否[PlacementTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementtarget)并[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)用于每种[PlacementMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode)枚举值。

| PlacementMode                                                | 目标对象                                                     | 目标区域                                                     | 目标原点                                                     | Popup 对齐点                                                 |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| [Absolute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Absolute) | 不适用。[PlacementTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementtarget)将被忽略。 | 屏幕上，或[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)如果将其设置。[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)是相对于屏幕。 | 目标区域的左上角。                                           | 在左上角的[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 |
| [AbsolutePoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_AbsolutePoint) | 不适用。[PlacementTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementtarget)将被忽略。 | 屏幕上，或[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)如果将其设置。[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)是相对于屏幕。 | 目标区域的左上角。                                           | 在左上角的[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 |
| [Bottom](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Bottom) | [PlacementTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementtarget)或父对象。 | 目标对象或[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)如果将其设置。[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)是相对于目标对象。 | 目标区域的左下角。                                           | 在左上角的[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 |
| [Center](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Center) | [PlacementTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementtarget)或父对象。 | 目标对象或[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)如果将其设置。[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)是相对于目标对象。 | 目标区域的中心。                                             | 中心[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 |
| [Custom](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Custom) | [PlacementTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementtarget)或父对象。 | 目标对象或[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)如果将其设置。[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)是相对于目标对象。 | 通过定义[CustomPopupPlacementCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.custompopupplacementcallback)。 | 通过定义[CustomPopupPlacementCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.custompopupplacementcallback)。 |
| [Left](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Left) | [PlacementTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementtarget)或父对象。 | 目标对象或[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)如果将其设置。[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)是相对于目标对象。 | 目标区域的左上角。                                           | 在右上角的[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 |
| [Mouse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Mouse) | 不适用。[PlacementTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementtarget)将被忽略。 | 鼠标指针的边界。[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle) 将被忽略。 | 目标区域的左下角。                                           | 在左上角的[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 |
| [MousePoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_MousePoint) | 不适用。[PlacementTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementtarget)将被忽略。 | 鼠标指针的边界。[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle) 将被忽略。 | 目标区域的左上角。                                           | 在左上角的[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 |
| [Relative](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Relative) | [PlacementTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementtarget)或父对象。 | 目标对象或[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)如果将其设置。[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)是相对于目标对象。 | 目标区域的左上角。                                           | 在左上角的[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 |
| [RelativePoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_RelativePoint) | [PlacementTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementtarget)或父对象。 | 目标对象或[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)如果将其设置。[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)是相对于目标对象。 | 目标区域的左上角。                                           | 在左上角的[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 |
| [Right](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Right) | [PlacementTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementtarget)或父对象。 | 目标对象或[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)如果将其设置。[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)是相对于目标对象。 | 目标区域的右上角。                                           | 在左上角的[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 |
| [Top](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Top) | [PlacementTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementtarget)或父对象。 | 目标对象或[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)如果将其设置。[PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placementrectangle)是相对于目标对象。 | 目标区域的左上角。                                           | 在左下角的[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 |

如下图所示[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)，为每个目标区域、 目标原点和 popup 对齐点[PlacementMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode)值。 在每个图中，目标区域为黄色，和[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)为蓝色。

![采用 Absolute 或 AbsolutePoint 定位的 popup](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/popupplacementabsolute.png)
Placement 为 Absolute 或 AbsolutePoint

![采用 Bottom 定位的 popup](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/popupplacementbottom.png)
Placement 为 Bottom

![采用 Center 定位的 popup](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/popupplacementcenter.png)
Placement 为 Center

![采用 Left 定位的 popup](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/popupplacementleft.png)
Placement 为 Left

![采用 Mouse 定位的 popup](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/popupplacementmouse.png)
Placement 为 Mouse

![采用 MousePoint 定位的 popup](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/popupplacementmousepoint.png)
Placement 为 MousePoint

![采用 Relative 或 RelativePoint 定位的 popup](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/popupplacementrelative.png)
Placement 为 Relative 或 RelativePoint

![采用 Right 定位的 popup](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/popupplacementright.png)
Placement 为 Right

![采用 Top 定位的 popup](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/popupplacementtop.png)
Placement 为 Top

### 当 Popup 到达屏幕边缘时

出于安全原因，[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)屏幕的边缘不能隐藏。 将发生以下三种情况之一时[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)到达屏幕边缘：

- 弹出窗口重新自行对齐沿着将遮挡屏幕边缘[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。
- Popup 使用其他 Popup 对齐点。
- Popup 使用其他目标原点和 Popup 对齐点。

将在本部分后面进一步介绍这些选项。

行为[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)遇到时屏幕边缘取决于值[Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placement)属性和它们的屏幕的边缘 popup 到达。 下表总结了行为时[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)为每个到达屏幕边缘[PlacementMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode)值。

| PlacementMode                                                | 上边缘                                                       | 下边缘                                                       | 左边缘                                                       | 右边缘                                                       |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| [Absolute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Absolute) | 与上边缘对齐。                                               | 与下边缘对齐。                                               | 与左边缘对齐。                                               | 与右边缘对齐。                                               |
| [AbsolutePoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_AbsolutePoint) | 与上边缘对齐。                                               | Popup 对齐点更改为的左下角[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 | 与左边缘对齐。                                               | Popup 对齐点更改为右上角的[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 |
| [Bottom](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Bottom) | 与上边缘对齐。                                               | 目标原点更改为目标区域的左上角，popup 对齐点更改为的左下角[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 | 与左边缘对齐。                                               | 与右边缘对齐。                                               |
| [Center](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Center) | 与上边缘对齐。                                               | 与下边缘对齐。                                               | 与左边缘对齐。                                               | 与右边缘对齐。                                               |
| [Left](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Left) | 与上边缘对齐。                                               | 与下边缘对齐。                                               | 目标原点更改为目标区域的右上角，popup 对齐点更改为左上角的[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 | 与右边缘对齐。                                               |
| [Mouse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Mouse) | 与上边缘对齐。                                               | 目标原点更改为目标区域 （鼠标指针的边界） 的左上角，popup 对齐点更改为的左下角[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 | 与左边缘对齐。                                               | 与右边缘对齐。                                               |
| [MousePoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_MousePoint) | 与上边缘对齐。                                               | Popup 对齐点更改为的左下角[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 | 与左边缘对齐。                                               | Popup 对齐点更改为 Popup 的右上角。                          |
| [Relative](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Relative) | 与上边缘对齐。                                               | 与下边缘对齐。                                               | 与左边缘对齐。                                               | 与右边缘对齐。                                               |
| [RelativePoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_RelativePoint) | 与上边缘对齐。                                               | Popup 对齐点更改为的左下角[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 | 与左边缘对齐。                                               | Popup 对齐点更改为 Popup 的右上角。                          |
| [Right](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Right) | 与上边缘对齐。                                               | 与下边缘对齐。                                               | 与左边缘对齐。                                               | 目标原点更改为目标区域的左上角，popup 对齐点更改为右上角的[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 |
| [Top](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Top) | 目标原点更改为目标区域的左下角，popup 对齐点更改为左上角的[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 实际上，这是时也是如此[Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placement)是[Bottom](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Bottom)。 | 与下边缘对齐。                                               | 与左边缘对齐。                                               | 与右边缘对齐。                                               |

#### 对屏幕边缘对齐

一个[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)可以将对齐到屏幕边缘通过重新自行定位因此整个[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)是在屏幕上可见。 此操作时，目标原点和 popup 对齐点之间的距离可能不同的值中[HorizontalOffset](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.horizontaloffset)和[VerticalOffset](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.verticaloffset)。 当[Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placement)是[Absolute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Absolute)， [Center](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Center)，或[Relative](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Relative)，则[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)与每个屏幕边缘对齐本身。 例如，假定[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)已[Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placement)设置为[Relative](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Relative)和[VerticalOffset](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.verticaloffset)设置为 100。 如果屏幕下的边缘隐藏全部或部分[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)，则[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)重新定位自身，沿屏幕和目标原点与弹出项之间的垂直距离的下边缘对齐点是小于 100。 下图演示了此情况。

![与屏幕边缘对齐的 popup](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/popupplacementrelativescreenedge.png)
Popup 与屏幕边缘对齐

#### 更改 Popup 对齐点

如果[Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placement)是[AbsolutePoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_AbsolutePoint)， [RelativePoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_RelativePoint)，或[MousePoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_MousePoint)，popup 对齐点更改时 popup 到达屏幕右边缘的底部。

下图演示当屏幕下边缘隐藏全部或部分[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)，而 popup 对齐点是的左下角[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。

![由于底部屏幕边缘而产生的新对齐点](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/popupplacementrelativepointscreenedge.png)
Popup 到达屏幕下边缘，并更改 Popup 对齐点

下图演示当[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)处于隐藏状态的屏幕右边缘，popup 对齐点是在右上角的[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。

![由于屏幕边缘而产生的新 popup 对齐点](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/popupplacementrelativepointrightscreenedge.png)
Popup 到达屏幕右边缘，并更改 Popup 对齐点

如果[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)时遇到的底部和右侧屏幕边缘，popup 对齐点是在右下角的[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。

#### 更改目标原点和 Popup 对齐点

当[Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placement)是[Bottom](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Bottom)， [Left](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Left)， [Mouse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Mouse)， [Right](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Right)，或[Top](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Top)，目标原点和 popup 对齐点更改，如果遇到某个屏幕边缘。 会导致更改的位置的屏幕边缘取决于[PlacementMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode)值。

下图演示当[Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placement)是[Bottom](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Bottom)和[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)到达屏幕下边缘，目标原点是目标区域的左上角，popup 对齐点是左下角的[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup).

![由于底部屏幕边缘而产生的新对齐点](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/popupplacementbottomscreenedge.png)
Placement 为 Bottom，并且 Popup 到达屏幕下边缘

下图演示当[Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placement)是[Left](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Left)和[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)到达左侧的屏幕边缘时，目标原点是目标区域的右上角，popup 对齐点是左上角[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup).

![由于左侧的屏幕边缘而产生的新对齐点](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/popupplacementleftscreenedge.png)
Placement 为 Left，并且 Popup 到达屏幕左边缘

下图演示当[Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placement)是[Right](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Right)和[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)到达屏幕右边缘时，目标原点是目标区域的左上角，popup 对齐点是在右上角的[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup).

![由于右侧屏幕边缘而产生的新对齐点](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/popupplacementrightscreenedge.png)
Placement 为 Right，并且 Popup 到达屏幕右边缘

下图演示当[Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placement)是[Top](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Top)和[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)到达顶部屏幕边缘时，目标原点是目标区域的左下角，popup 对齐点是在左上角的[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup).

![由于顶部屏幕边缘而产生的新对齐点](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/popupplacementtopscreenedge.png)
Placement 为 Top，并且 Popup 到达屏幕上边缘

下图演示当[Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placement)是[Mouse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Mouse)和[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)到达屏幕下边缘，目标原点是目标区域 （鼠标指针的边界） 和弹出项对齐的左上角点是左下角的[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。

![由于鼠标接近屏幕边缘而产生的新对齐点](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/popupplacementmousescreenedge.png)
Placement 为 Mouse，并且 Popup 到达屏幕下边缘

#### 自定义 Popup 放置

可以通过设置目标原点和 popup 对齐点来自定义[Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placement)属性设置为[Custom](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Custom)。 然后，定义[CustomPopupPlacementCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.custompopupplacementcallback)委托中，返回一组可能的位置点和主轴 （按优先顺序） [Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 显示的最大部分的点[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)处于选中状态。 位置[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)如果自动调整[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)屏幕的边缘隐藏。 有关示例，请参阅[指定自定义 Popup 位置](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-specify-a-custom-popup-position)。

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/popup-how-to-topics)

本部分中的主题介绍如何使用[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)控件来显示通过当前的应用程序窗口浮动的单独窗口中的内容。

### 本节内容

[为 Popup 设置动画效果](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-animate-a-popup)
[指定自定义 Popup 位置](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-specify-a-custom-popup-position)

### [Animate a Popup](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-animate-a-popup)

此示例演示两种方式进行动画处理[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)控件。

#### 示例

下面的示例设置[PopupAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popupanimation)属性的值[Slide](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popupanimation#System_Windows_Controls_Primitives_PopupAnimation_Slide)，这将导致[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)以"滑入"时出现。

才能进行旋转[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)，此示例将分配[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)到[RenderTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.rendertransform)上的属性[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)，它是子元素的[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。

对于要正常工作的转换，必须设置示例[AllowsTransparency](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.allowstransparency)属性设置为`true`。 此外，[Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)上[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)内容必须指定足够的空间用于[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)旋转。

```xaml
<Popup IsOpen="{Binding ElementName=myCheckBox,Path=IsChecked}" 
       PlacementTarget="{Binding ElementName=myCheckBox}"            
       AllowsTransparency="True"
       PopupAnimation="Slide"
       HorizontalOffset="50"
       VerticalOffset="50"
       >
  <!--The Margin set on the Canvas provides the additional 
      area around the Popup so that the Popup is visible when 
      it rotates.-->
  <Canvas Width="100" Height="100" Background="DarkBlue"
          Margin="150">
    <Canvas.RenderTransform>
      <RotateTransform x:Name="theTransform" />
    </Canvas.RenderTransform>
    <TextBlock TextWrapping="Wrap" Foreground="White">
      Rotating Popup
    </TextBlock>
  </Canvas>
</Popup>
```

下面的示例演示如何[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件，发生时[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)单击时，触发器[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)启动动画。

```xaml
<Button HorizontalAlignment="Left" Width="200" Margin="20,10,0,0">
  <Button.Triggers>
    <EventTrigger RoutedEvent="Button.Click">
      <BeginStoryboard>
        <Storyboard>
          <DoubleAnimation 
            Storyboard.TargetName="theTransform"
            Storyboard.TargetProperty="(RotateTransform.Angle)" 
            From="0" To="360" Duration="0:0:5" AutoReverse="True"/>
        </Storyboard>
      </BeginStoryboard>
    </EventTrigger>
  </Button.Triggers>
  Click to see the Popup animate
</Button>
```

### [Specify a Custom Popup Position](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-specify-a-custom-popup-position)

此示例演示如何指定的自定义位置[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)控制何时[Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placement)属性设置为[Custom](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Custom)。

#### 示例

当[Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placement)属性设置为[Custom](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Custom)，则[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)调用的定义的实例[CustomPopupPlacementCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.custompopupplacementcallback)委托。 此委托返回的可能是相对于目标区域的左上的角和的左上的角的点集[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 [Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)位置出现在提供最佳的可见性的点。

下面的示例演示如何定义的位置[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)通过设置[Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup.placement)属性设置为[Custom](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.placementmode#System_Windows_Controls_Primitives_PlacementMode_Custom)。 它还演示如何创建和分配[CustomPopupPlacementCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.custompopupplacementcallback)委托以定位[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)。 回调委托返回两个[CustomPopupPlacement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.custompopupplacement)对象。 如果[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)情况下的第一个位置，在屏幕边缘隐藏[Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup)放在第二个位置。

```xaml
 <Popup Name="popup1"  
        PlacementTarget ="{Binding ElementName=myButton}" 
        Placement="Custom">
  <TextBlock Height="60" Width="200" 
             Background="LightGray"
             TextWrapping="Wrap">Popup positioned by using
  CustomPopupPlacement callback delegate</TextBlock>
</Popup>
```

```csharp
public CustomPopupPlacement[] placePopup(Size popupSize,
                                           Size targetSize,
                                           Point offset)
{
    CustomPopupPlacement placement1 =
       new CustomPopupPlacement(new Point(-50, 100), PopupPrimaryAxis.Vertical);

    CustomPopupPlacement placement2 =
        new CustomPopupPlacement(new Point(10, 20), PopupPrimaryAxis.Horizontal);

    CustomPopupPlacement[] ttplaces =
            new CustomPopupPlacement[] { placement1, placement2 };
    return ttplaces;
}
```

```csharp
popup1.CustomPopupPlacementCallback =
    new CustomPopupPlacementCallback(placePopup);
```

有关完整示例，请参阅[Popup 放置示例](https://go.microsoft.com/fwlink/?LinkID=160032)。