# [ToolTip](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/tooltip)

工具提示是当用户将鼠标指针暂停元素，如过度时显示一个小型弹出窗口[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。

下图显示了鼠标指针指向**关闭**[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)，后者随后会显示其标识[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)。

具有显示其工具提示的关闭按钮

![工具提示的屏幕快照](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/ss-ctl-tooltip.png)

## [ToolTip Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/tooltip-overview)

工具提示，则用户将鼠标指针悬停在元素，通过上时，将显示一个小型弹出窗口[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。 本主题介绍工具提示，并讨论如何创建和自定义工具提示内容。

### 什么是工具提示？

当用户将鼠标指针移动到具有工具提示的元素上时，将在一段指定的时间内显示一个包含工具提示内容（例如，介绍控件功能的文本内容）的窗口。 如果用户将鼠标指针从控件上移开，该窗口将消失，因为工具提示内容无法接收焦点。

工具提示的内容可以包含一行或多行文本、图像、形状或其他可视内容。 通过将以下属性之一设置为工具提示内容来定义控件的工具提示。

- [FrameworkContentElement.ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement.tooltip)
- [FrameworkElement.ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.tooltip)

所使用的属性取决于是否定义了工具提示控件继承自[FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement)或[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)类。



### 创建工具提示

下面的示例演示如何通过设置创建简单的工具提示[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.tooltip)属性[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)为文本字符串的控件。

```xaml
<Button ToolTip="Click to submit your information" 
        Click="SubmitCode" Height="20" Width="50">Submit</Button>
```

您还可以定义为工具提示[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)对象。 下面的示例使用XAML来指定[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)对象的工具提示[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)元素。 请注意，该示例指定[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)通过设置[FrameworkElement.ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.tooltip)属性。

```xaml
<TextBox HorizontalAlignment="Left">ToolTip with non-text content
  <TextBox.ToolTip>
    <ToolTip>
      <DockPanel Width="50" Height="70">
        <Image Source="data\flower.jpg"/>
        <TextBlock>Useful information goes here.</TextBlock>
      </DockPanel>
    </ToolTip>
  </TextBox.ToolTip>
</TextBox>
```

以下示例使用代码来生成[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)对象。 此示例将创建[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)(`tt`) 并将其与[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。

```csharp
button = new Button();
button.Content = "Hover over me.";
tt = new ToolTip();
tt.Content = "Created with C#";
button.ToolTip = tt;
cv2.Children.Add(button);
```

此外可以创建未定义为工具提示内容[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)括起的工具提示内容的布局元素，如对象[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)。 下面的示例演示如何设置[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.tooltip)的属性[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)括在内容[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)控件。

```xaml
<TextBox>
  ToolTip with image and text
  <TextBox.ToolTip>
       <StackPanel>
        <Image Source="data\flower.jpg"/>
        <TextBlock>Useful information goes here.</TextBlock>
      </StackPanel>
  </TextBox.ToolTip>
```



### 使用 ToolTipd 和 ToolTipService 类的属性

可以通过设置视觉属性和应用样式来自定义工具提示内容。 如果定义的工具提示内容作为[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)对象，可以设置的视觉属性[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)对象。 否则，必须上设置等效的附加的属性[ToolTipService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltipservice)类。

有关如何设置属性，以便使用指定的工具提示内容位置的示例[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)并[ToolTipService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltipservice)属性，请参阅[定位 ToolTip](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-position-a-tooltip)。

### 设置工具提示样式

你可以设置样式[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)通过定义一个自定义[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)。 下面的示例定义[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)称为`Simple`，演示如何偏移量的位置[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)并通过设置更改其外观[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)， [Foreground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.foreground)， [FontSize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontsize)，和[FontWeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontweight)。

```xaml
<Style TargetType="ToolTip">
  <Setter Property = "HorizontalOffset" Value="10"/>
  <Setter Property = "VerticalOffset" Value="10"/>
  <Setter Property = "Background" Value="LightBlue"/>
  <Setter Property = "Foreground" Value="Purple"/>
  <Setter Property = "FontSize" Value="14"/>
  <Setter Property = "FontWeight" Value="Bold"/>
</Style>
```

### 使用 ToolTipService 的 Time Interval 属性

[ToolTipService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltipservice)类提供了以下属性用于设置工具提示显示时间： [InitialShowDelay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltipservice.initialshowdelay)， [BetweenShowDelay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltipservice.betweenshowdelay)，和[ShowDuration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltipservice.showduration)。

使用[InitialShowDelay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltipservice.initialshowdelay)并[ShowDuration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltipservice.showduration)属性指定的延迟通常很短，之前[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)将显示，还指定的时间[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)保持可见。 有关详细信息，请参阅[如何：延迟的工具提示显示](https://msdn.microsoft.com/library/618e05ef-f2bf-4a53-a0f4-aacb49918bd7)。

[BetweenShowDelay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltipservice.betweenshowdelay)属性确定了快速移动时鼠标指针它们之间不同控件的工具提示是否显示没有初始延迟。 有关详细信息[BetweenShowDelay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltipservice.betweenshowdelay)属性，请参阅[使用 BetweenShowDelay 属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-use-the-betweenshowdelay-property)。

以下示例演示如何为工具提示设置这些属性。

```xaml
<Ellipse Height="25" Width="50" 
         Fill="Gray" 
         HorizontalAlignment="Left"
         ToolTipService.InitialShowDelay="1000"
         ToolTipService.ShowDuration="7000"
         ToolTipService.BetweenShowDelay="2000">
  <Ellipse.ToolTip>
    <ToolTip Placement="Right" 
             PlacementRectangle="50,0,0,0"
             HorizontalOffset="10" 
             VerticalOffset="20"
             HasDropShadow="false"
             Opened="whenToolTipOpens"
             Closed="whenToolTipCloses"
             >
      <BulletDecorator>
        <BulletDecorator.Bullet>
          <Ellipse Height="10" Width="20" Fill="Blue"/>
        </BulletDecorator.Bullet>
        <TextBlock>Uses the ToolTip Class</TextBlock>
      </BulletDecorator>
    </ToolTip>
  </Ellipse.ToolTip>
</Ellipse>
```

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/tooltip-how-to-topics)

[确定 ToolTip 的位置](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-position-a-tooltip)
[使用 BetweenShowDelay 属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-use-the-betweenshowdelay-property)

### [Position a ToolTip](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-position-a-tooltip)

此示例演示如何在屏幕上指定的工具提示的位置。

可以使用一组中都定义的五个属性来定位 tooltip[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)和[ToolTipService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltipservice)类。 下表显示了这两个五个属性集，并提供指向其根据类的参考文档。

#### 类根据相应的工具提示属性

| [System.Windows.Controls.ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip) 类属性 | [System.Windows.Controls.ToolTipService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltipservice) 类属性 |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [ToolTip.Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip.placement) | [ToolTipService.Placement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltipservice.placement) |
| [ToolTip.PlacementTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip.placementtarget) | [ToolTipService.PlacementTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltipservice.placementtarget) |
| [ToolTip.PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip.placementrectangle) | [ToolTipService.PlacementRectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltipservice.placementrectangle) |
| [ToolTip.HorizontalOffset](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip.horizontaloffset) | [ToolTipService.HorizontalOffset](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltipservice.horizontaloffset) |
| [ToolTip.VerticalOffset](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip.verticaloffset) | [ToolTipService.VerticalOffset](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltipservice.verticaloffset) |

如果您通过使用定义的工具提示内容[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)对象，可以使用其中一个类的属性; 但是，[ToolTipService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltipservice)属性优先。使用[ToolTipService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltipservice)属性未定义为的工具提示[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)对象。

下图显示如何使用这些属性来定位 tooltip。 虽然，则可扩展应用程序标记语言 (XAML)在这些说明中的示例演示如何设置所定义的属性[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)类的相应属性[ToolTipService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltipservice)类遵循相同的布局规则。 有关位置属性的可能值的详细信息，请参阅[Popup 放置行为](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/popup-placement-behavior)。

![工具提示放置](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/tooltipplacement.png)
通过使用放置属性的工具提示放置

![通过使用放置矩形 tooltip](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/tooltipplacementrectangle.png)
通过使用放置和 PlacementRectangle 属性的工具提示放置

![ToolTip 定位示意图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/tooltipplacementprhv.png)
通过使用放置、 PlacementRectangle 和偏移量属性的工具提示放置

下面的示例演示如何使用[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)属性来指定其内容的工具提示的位置[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)对象。

```xaml
<Ellipse Height="25" Width="50" 
         Fill="Gray" 
         HorizontalAlignment="Left"
         ToolTipService.InitialShowDelay="1000"
         ToolTipService.ShowDuration="7000"
         ToolTipService.BetweenShowDelay="2000">
  <Ellipse.ToolTip>
    <ToolTip Placement="Right" 
             PlacementRectangle="50,0,0,0"
             HorizontalOffset="10" 
             VerticalOffset="20"
             HasDropShadow="false"
             Opened="whenToolTipOpens"
             Closed="whenToolTipCloses"
             >
      <BulletDecorator>
        <BulletDecorator.Bullet>
          <Ellipse Height="10" Width="20" Fill="Blue"/>
        </BulletDecorator.Bullet>
        <TextBlock>Uses the ToolTip Class</TextBlock>
      </BulletDecorator>
    </ToolTip>
  </Ellipse.ToolTip>
</Ellipse>
```

```csharp
//Create an ellipse that will have a 
//ToolTip control. 
Ellipse ellipse1 = new Ellipse();
ellipse1.Height = 25;
ellipse1.Width = 50;
ellipse1.Fill = Brushes.Gray;
ellipse1.HorizontalAlignment = HorizontalAlignment.Left;

//Create a tooltip and set its position.
ToolTip tooltip = new ToolTip();
tooltip.Placement = PlacementMode.Right;
tooltip.PlacementRectangle = new Rect(50, 0, 0, 0);
tooltip.HorizontalOffset = 10;
tooltip.VerticalOffset = 20;

//Create BulletDecorator and set it
//as the tooltip content.
BulletDecorator bdec = new BulletDecorator();
Ellipse littleEllipse = new Ellipse();
littleEllipse.Height = 10;
littleEllipse.Width = 20;
littleEllipse.Fill = Brushes.Blue;
bdec.Bullet = littleEllipse;
TextBlock tipText = new TextBlock();
tipText.Text = "Uses the ToolTip class";
bdec.Child = tipText;
tooltip.Content = bdec;

//set tooltip on ellipse
ellipse1.ToolTip = tooltip;
```

下面的示例演示如何使用[ToolTipService](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltipservice)属性来指定其内容不是一个工具提示的位置[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)对象。

```xaml
<Ellipse Height="25" Width="50" 
      Fill="Gray" 
      HorizontalAlignment="Left"
      ToolTipService.InitialShowDelay="1000"
      ToolTipService.ShowDuration="7000"
      ToolTipService.BetweenShowDelay="2000"
      ToolTipService.Placement="Right" 
      ToolTipService.PlacementRectangle="50,0,0,0"
      ToolTipService.HorizontalOffset="10" 
      ToolTipService.VerticalOffset="20"
      ToolTipService.HasDropShadow="false"
      ToolTipService.ShowOnDisabled="true" 
      ToolTipService.IsEnabled="true"
      ToolTipOpening="whenToolTipOpens"
      ToolTipClosing="whenToolTipCloses"
      >
  <Ellipse.ToolTip>
    <BulletDecorator>
      <BulletDecorator.Bullet>
        <Ellipse Height="10" Width="20" Fill="Blue"/>
      </BulletDecorator.Bullet>
      <TextBlock>Uses the ToolTipService class</TextBlock>
    </BulletDecorator>
  </Ellipse.ToolTip>
</Ellipse>
```

```csharp
//Create and Ellipse with the BulletDecorator as 
//the tooltip 
Ellipse ellipse2 = new Ellipse();
ellipse2.Name = "ellipse2";
this.RegisterName(ellipse2.Name, ellipse2);
ellipse2.Height = 25;
ellipse2.Width = 50;
ellipse2.Fill = Brushes.Gray;
ellipse2.HorizontalAlignment = HorizontalAlignment.Left;

//set tooltip timing
ToolTipService.SetInitialShowDelay(ellipse2, 1000);
ToolTipService.SetBetweenShowDelay(ellipse2, 2000);
ToolTipService.SetShowDuration(ellipse2, 7000);

//set tooltip placement

ToolTipService.SetPlacement(ellipse2, PlacementMode.Right);

ToolTipService.SetPlacementRectangle(ellipse2,
    new Rect(50, 0, 0, 0));

ToolTipService.SetHorizontalOffset(ellipse2, 10.0);

ToolTipService.SetVerticalOffset(ellipse2, 20.0);


ToolTipService.SetHasDropShadow(ellipse2, false);

ToolTipService.SetIsEnabled(ellipse2, true);

ToolTipService.SetShowOnDisabled(ellipse2, true);

ellipse2.AddHandler(ToolTipService.ToolTipOpeningEvent,
    new RoutedEventHandler(whenToolTipOpens));
ellipse2.AddHandler(ToolTipService.ToolTipClosingEvent,
    new RoutedEventHandler(whenToolTipCloses));

//define tooltip content
BulletDecorator bdec2 = new BulletDecorator();
Ellipse littleEllipse2 = new Ellipse();
littleEllipse2.Height = 10;
littleEllipse2.Width = 20;
littleEllipse2.Fill = Brushes.Blue;
bdec2.Bullet = littleEllipse2;
TextBlock tipText2 = new TextBlock();
tipText2.Text = "Uses the ToolTipService class";
bdec2.Child = tipText2;
ToolTipService.SetToolTip(ellipse2, bdec2);
stackPanel_1_2.Children.Add(ellipse2);
```

### [Use the BetweenShowDelay Property](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-use-the-betweenshowdelay-property)

此示例演示如何使用[BetweenShowDelay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltipservice.betweenshowdelay)时间属性，以便快速显示工具提示，且很少或没有延迟 — 当用户移动鼠标指针从一个工具提示直接到另一个。

在以下示例中，[InitialShowDelay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltipservice.initialshowdelay)属性设置为 1 秒 （1000年毫秒为单位） 和[BetweenShowDelay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltipservice.betweenshowdelay)设置为这两者的工具提示为两秒 （2000年毫秒）[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)控件。 如果显示一个省略号的工具提示，然后将鼠标指针移动到另一个椭圆两秒和暂停它的第二个椭圆的工具提示将立即显示。

在以下情况下，任一[InitialShowDelay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltipservice.initialshowdelay)适用，这将导致要等待一秒才会出现的第二个椭圆的工具提示：

- 如果所用时间将移到第二个按钮是超过两秒的时间。
- 如果工具提示的第一个椭圆的时间间隔开始时不可见。

```xaml
<Ellipse Height="25" Width="50" 
         Fill="Gray" 
         HorizontalAlignment="Left"
         ToolTipService.InitialShowDelay="1000"
         ToolTipService.ShowDuration="7000"
         ToolTipService.BetweenShowDelay="2000">
  <Ellipse.ToolTip>
    <ToolTip Placement="Right" 
             PlacementRectangle="50,0,0,0"
             HorizontalOffset="10" 
             VerticalOffset="20"
             HasDropShadow="false"
             Opened="whenToolTipOpens"
             Closed="whenToolTipCloses"
             >
      <BulletDecorator>
        <BulletDecorator.Bullet>
          <Ellipse Height="10" Width="20" Fill="Blue"/>
        </BulletDecorator.Bullet>
        <TextBlock>Uses the ToolTip Class</TextBlock>
      </BulletDecorator>
    </ToolTip>
  </Ellipse.ToolTip>
</Ellipse>
```

```xaml
<Ellipse Height="25" Width="50" 
      Fill="Gray" 
      HorizontalAlignment="Left"
      ToolTipService.InitialShowDelay="1000"
      ToolTipService.ShowDuration="7000"
      ToolTipService.BetweenShowDelay="2000"
      ToolTipService.Placement="Right" 
      ToolTipService.PlacementRectangle="50,0,0,0"
      ToolTipService.HorizontalOffset="10" 
      ToolTipService.VerticalOffset="20"
      ToolTipService.HasDropShadow="false"
      ToolTipService.ShowOnDisabled="true" 
      ToolTipService.IsEnabled="true"
      ToolTipOpening="whenToolTipOpens"
      ToolTipClosing="whenToolTipCloses"
      >
  <Ellipse.ToolTip>
    <BulletDecorator>
      <BulletDecorator.Bullet>
        <Ellipse Height="10" Width="20" Fill="Blue"/>
      </BulletDecorator.Bullet>
      <TextBlock>Uses the ToolTipService class</TextBlock>
    </BulletDecorator>
  </Ellipse.ToolTip>
</Ellipse>
```