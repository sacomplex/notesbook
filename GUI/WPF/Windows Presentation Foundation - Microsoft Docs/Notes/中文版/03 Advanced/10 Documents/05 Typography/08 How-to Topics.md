# [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/typography-how-to-topics)

在本部分中的主题介绍如何使用Windows Presentation Foundation (WPF)丰富应用程序中的文本表示的支持。

[创建文本效果](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-create-a-text-decoration)
[指定是否为超链接添加下划线](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-specify-whether-a-hyperlink-is-underlined)
[向文本应用转换](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-apply-transforms-to-text)
[向文本应用动画](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-apply-animations-to-text)
[创建有阴影的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-create-text-with-a-shadow)
[创建空心文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-create-outlined-text)
[在控件背景上绘制文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-draw-text-to-a-control-background)
[在视觉对象中绘制文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-draw-text-to-a-visual)
[在 XAML 中使用特殊字符](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-use-special-characters-in-xaml)

## [Create a Text Decoration](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-create-a-text-decoration)

一个[TextDecoration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.textdecoration)对象是可以添加到文本的视觉装饰。 有四种类型的文本修饰： 下划线、 基线、 删除线和上划线。 下面的示例显示了文本修饰相对于文本的位置。

![文本修饰位置示意图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/textdecoration01.gif)
文本修饰类型的示例

若要将文本修饰添加到文本中，创建[TextDecoration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.textdecoration)对象，并修改其属性。 使用[Location](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.textdecoration.location)属性来指定文本修饰的显示位置，如下划线。 使用[Pen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.textdecoration.pen)属性来指定文本修饰，如纯色填充或渐变颜色的外观。 如果未指定的值[Pen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.textdecoration.pen)属性，为相同的颜色为文本修饰默认值。 定义后[TextDecoration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.textdecoration)对象，将其添加到[TextDecorations](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.textdecorations)所需的文本对象的集合。

下面的示例演示了样式使用线性渐变画笔和虚线的笔的文本修饰。

![采用线性渐变下划线的文本修饰](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/textdecoration02.png)
示例中的下划线的样式使用线性渐变画笔和虚线的钢笔

[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)对象是允许您承载流内容中的超链接的内联级流内容元素。 默认情况下[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)使用[TextDecoration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.textdecoration)对象来显示下划线。 [TextDecoration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.textdecoration) 对象可以是占用实例化，特别是当有许多[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)对象。 如果充分利用了[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)元素，您可能会考虑显示下划线，仅当触发事件，如[MouseEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement.mouseenter)事件。

在以下示例中，"我的 MSN"链接的下划线是动态的 — 它时，才显示[MouseEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement.mouseenter)触发事件。

![显示 TextDecorations 的超](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/textdecoration03.png)
定义与 TextDecorations 的超链接

有关详细信息，请参阅[指定是否为超链接添加下划线](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-specify-whether-a-hyperlink-is-underlined)。

在下面的代码示例中，下划线文本修饰使用的默认字体值。

C#复制

```csharp
// Use the default font values for the strikethrough text decoration.
private void SetDefaultStrikethrough()
{
    // Set the underline decoration directly to the text block.
    TextBlock1.TextDecorations = TextDecorations.Strikethrough;
}
```

XAML复制

```xaml
<!-- Use the default font values for the strikethrough text decoration. -->
<TextBlock
  TextDecorations="Strikethrough"
  FontSize="36" >
  The quick red fox
</TextBlock>
```

下面的代码示例，笔纯色画笔创建下划线文本修饰。

C#复制

```csharp
// Use a Red pen for the underline text decoration.
private void SetRedUnderline()
{
    // Create an underline text decoration. Default is underline.
    TextDecoration myUnderline = new TextDecoration();

    // Create a solid color brush pen for the text decoration.
    myUnderline.Pen = new Pen(Brushes.Red, 1);
    myUnderline.PenThicknessUnit = TextDecorationUnit.FontRecommended;

    // Set the underline decoration to a TextDecorationCollection and add it to the text block.
    TextDecorationCollection myCollection = new TextDecorationCollection();
    myCollection.Add(myUnderline);
    TextBlock2.TextDecorations = myCollection;
}
```

XAML复制

```xaml
<!-- Use a Red pen for the underline text decoration -->
<TextBlock
  FontSize="36" >
  jumps over
  <TextBlock.TextDecorations>
    <TextDecorationCollection>
      <TextDecoration 
        PenThicknessUnit="FontRecommended">
        <TextDecoration.Pen>
          <Pen Brush="Red" Thickness="1" />
        </TextDecoration.Pen>
      </TextDecoration>
    </TextDecorationCollection>
  </TextBlock.TextDecorations>
</TextBlock>
```

以下代码示例中，虚线笔线性渐变画笔创建下划线文本修饰。

C#复制

```csharp
// Use a linear gradient pen for the underline text decoration.
private void SetLinearGradientUnderline()
{
    // Create an underline text decoration. Default is underline.
    TextDecoration myUnderline = new TextDecoration();

    // Create a linear gradient pen for the text decoration.
    Pen myPen = new Pen();
    myPen.Brush = new LinearGradientBrush(Colors.Yellow, Colors.Red, new Point(0, 0.5), new Point(1, 0.5));
    myPen.Brush.Opacity = 0.5;
    myPen.Thickness = 1.5;
    myPen.DashStyle = DashStyles.Dash;
    myUnderline.Pen = myPen;
    myUnderline.PenThicknessUnit = TextDecorationUnit.FontRecommended;

    // Set the underline decoration to a TextDecorationCollection and add it to the text block.
    TextDecorationCollection myCollection = new TextDecorationCollection();
    myCollection.Add(myUnderline);
    TextBlock3.TextDecorations = myCollection;
}
```

XAML复制

```xaml
<!-- Use a linear gradient pen for the underline text decoration. -->
<TextBlock FontSize="36">the lazy brown dog.
  <TextBlock.TextDecorations>
    <TextDecorationCollection>
      <TextDecoration  
        PenThicknessUnit="FontRecommended">
        <TextDecoration.Pen>
          <Pen Thickness="1.5">
            <Pen.Brush>
              <LinearGradientBrush Opacity="0.5"
                StartPoint="0,0.5"  EndPoint="1,0.5">
                <LinearGradientBrush.GradientStops>
                  <GradientStop Color="Yellow" Offset="0" />
                  <GradientStop Color="Red" Offset="1" />
                </LinearGradientBrush.GradientStops>
              </LinearGradientBrush>
            </Pen.Brush>
            <Pen.DashStyle>
              <DashStyle Dashes="2"/>
            </Pen.DashStyle>
          </Pen>
        </TextDecoration.Pen>
      </TextDecoration>
    </TextDecorationCollection>
  </TextBlock.TextDecorations>
</TextBlock>
```

## [Specify Whether a Hyperlink is Underlined](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-specify-whether-a-hyperlink-is-underlined)

[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)对象是允许您承载流内容中的超链接的内联级流内容元素。 默认情况下[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)使用[TextDecoration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.textdecoration)对象来显示下划线。 [TextDecoration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.textdecoration) 对象可以是占用实例化，特别是当有许多[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)对象。 如果充分利用了[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)元素，您可能会考虑显示下划线，仅当触发事件，如[MouseEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement.mouseenter)事件。

在以下示例中，"我的 MSN"链接的下划线是动态的 — 它时，才显示[MouseEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement.mouseenter)触发事件。

![显示 TextDecorations 的超](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/textdecoration03.png)
定义与 TextDecorations 的超链接

以下标记示例演示[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)使用和不使用下划线定义：

XAML复制

```xaml
<!-- Hyperlink with default underline. -->
<Hyperlink NavigateUri="http://www.msn.com">
  MSN Home
</Hyperlink>

<Run Text=" | " />

<!-- Hyperlink with no underline. -->
<Hyperlink Name="myHyperlink" TextDecorations="None"
           MouseEnter="OnMouseEnter"
           MouseLeave="OnMouseLeave"
           NavigateUri="http://www.msn.com">
  My MSN
</Hyperlink>
```

下面的代码示例演示如何创建为下划线[Hyperlink](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.hyperlink)上[MouseEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement.mouseenter)事件，并将其上删除[MouseLeave](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement.mouseleave)事件。

C#复制

```csharp
// Display the underline on only the MouseEnter event.
private void OnMouseEnter(object sender, EventArgs e)
{
    myHyperlink.TextDecorations = TextDecorations.Underline;
}

// Remove the underline on the MouseLeave event.
private void OnMouseLeave(object sender, EventArgs e)
{
    myHyperlink.TextDecorations = null;
}
```

## [Apply Transforms to Text](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-apply-transforms-to-text)

应用变换可以改变应用程序中文本的显示。 下面的示例使用不同类型的呈现变换来影响中文本的显示[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)控件。

下面的示例演示了在 x-y 二维平面中文本围绕一个特定点进行旋转。

![使用 RotateTransform 旋转的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/transformedtext01.jpg)
文本旋转 90 度的示例

下面的代码示例使用[RotateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform)来旋转文本。 [Angle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.rotatetransform.angle)值为 90，则元素会顺时针旋转 90 度。

XAML复制

```xaml
<!-- Rotate the text 90 degrees using a RotateTransform. -->
<TextBlock FontFamily="Arial Black" FontSize="64" Foreground="Moccasin" Margin ="80, 10, 0, 0">
  Text Transforms
  <TextBlock.RenderTransform>
    <RotateTransform Angle="90" />
  </TextBlock.RenderTransform>
</TextBlock>
```

下面的示例演示沿 X 轴放大 150% 得到第二行文本，沿 Y 轴放大 150% 得到第三行文本。

![使用 ScaleTransform 缩放的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/transformedtext02.jpg)
缩放文本的示例

下面的代码示例使用[ScaleTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform)对文本从其原始大小进行缩放。

XAML复制

```xaml
<!-- Scale the text using a ScaleTransform. -->
<TextBlock
  Name="textblockScaleMaster" 
  FontSize="32"
  Foreground="SteelBlue"
  Text="Scaled Text"
  Margin="100, 0, 0, 0"
  Grid.Column="0" Grid.Row="0">
</TextBlock>
<TextBlock
  FontSize="32"
  FontWeight="Bold" 
  Foreground="SteelBlue"
  Text="{Binding Path=Text, ElementName=textblockScaleMaster}"
  Margin="100, 0, 0, 0"
  Grid.Column="0" Grid.Row="1">
  <TextBlock.RenderTransform>
    <ScaleTransform ScaleX="1.5" ScaleY="1.0" />
  </TextBlock.RenderTransform>
</TextBlock>
<TextBlock
  FontSize="32"
  FontWeight="Bold" 
  Foreground="SteelBlue"
  Text="{Binding Path=Text, ElementName=textblockScaleMaster}"
  Margin="100, 0, 0, 0"
  Grid.Column="0" Grid.Row="2">
  <TextBlock.RenderTransform>
    <ScaleTransform ScaleX="1.0" ScaleY="1.5" />
  </TextBlock.RenderTransform>
</TextBlock>
```

 备注

放大文本不同于增大文本字号。 字号的计算相互独立，以便针对不同字号提供最佳分辨率。 而缩放后的文本将按比例保持原始的文本大小。

以下示例演示沿 X 轴倾斜的文本。

![使用 SkewTransform 倾斜的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/transformedtext03.jpg)
扭曲文本的示例

下面的代码示例使用[SkewTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.skewtransform)来扭曲文本。 扭曲（也称为倾斜）是一种以非均匀方式拉伸坐标空间的变换。 在本示例中，两个文本字符串沿 x 坐标扭曲了 -30° 和 30°。

XAML复制

```xaml
<!-- Skew the text using a SkewTransform. -->
<TextBlock
  Name="textblockSkewMaster" 
  FontSize="32"
  FontWeight="Bold" 
  Foreground="Maroon"
  Text="Skewed Text"
  Margin="125, 0, 0, 0"
  Grid.Column="0" Grid.Row="0">
  <TextBlock.RenderTransform>
    <SkewTransform AngleX="-30" AngleY="0" />
  </TextBlock.RenderTransform>
</TextBlock>
<TextBlock
  FontSize="32"
  FontWeight="Bold" 
  Foreground="Maroon"
  Text="{Binding Path=Text, ElementName=textblockSkewMaster}"
  Margin="100, 0, 0, 0"
  Grid.Column="0" Grid.Row="1">
  <TextBlock.RenderTransform>
    <SkewTransform AngleX="30" AngleY="0" />
  </TextBlock.RenderTransform>
</TextBlock>
```

下面的示例演示沿 x 轴和 y 轴平移或移动的文本。

![使用 TranslateTransform 偏移的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/transformedtext04.jpg)
平移文本的示例

下面的代码示例使用[TranslateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform)来偏移文本。 在本示例中，主要文本下方略微偏移的文本副本营造出了阴影效果。

XAML复制

```xaml
<!-- Skew the text using a TranslateTransform. -->
<TextBlock
  FontSize="32"
  FontWeight="Bold" 
  Foreground="Black"
  Text="{Binding Path=Text, ElementName=textblockTranslateMaster}"
  Margin="100, 0, 0, 0"
  Grid.Column="0" Grid.Row="0">
  <TextBlock.RenderTransform>
    <TranslateTransform X="2" Y="2" />
  </TextBlock.RenderTransform>
</TextBlock>
<TextBlock
  Name="textblockTranslateMaster" 
  FontSize="32"
  FontWeight="Bold" 
  Foreground="Coral"
  Text="Translated Text"
  Margin="100, 0, 0, 0"
  Grid.Column="0" Grid.Row="0"/>
```

> [DropShadowBitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.dropshadowbitmapeffect)提供丰富的功能来产生阴影效果。 有关详细信息，请参阅[创建具有阴影的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-create-text-with-a-shadow)。

## [Apply Animations to Text](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-apply-animations-to-text)

动画可以更改应用程序中文本的显示和外观。 以下示例使用不同类型的动画来影响中文本的显示[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)控件。

下面的示例使用[DoubleAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation)进行动画处理的文本块宽度。 宽度值从文本块的宽度更改为 0，持续时间为 10 秒，然后再改回其宽度值并继续。 这种动画会创建一个擦除效果。

XAML复制

```xaml
<TextBlock
  Name="MyWipedText"
  Margin="20" 
  Width="480" Height="100" FontSize="48" FontWeight="Bold" Foreground="Maroon">
  This is wiped text

  <!-- Animates the text block's width. -->
  <TextBlock.Triggers>
    <EventTrigger RoutedEvent="TextBlock.Loaded">
      <BeginStoryboard>
        <Storyboard>
          <DoubleAnimation
            Storyboard.TargetName="MyWipedText" 
            Storyboard.TargetProperty="(TextBlock.Width)"
            To="0.0" Duration="0:0:10" 
            AutoReverse="True" RepeatBehavior="Forever" />
        </Storyboard>
      </BeginStoryboard>
    </EventTrigger>
  </TextBlock.Triggers>
</TextBlock>
```

下面的示例使用[DoubleAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation)来对文本块的不透明度进行动画处理。 不透明度值从 1.0 更改为 0，持续时间为 5 秒，然后再改回其不透明度值并继续。

XAML复制

```xaml
<TextBlock
  Name="MyFadingText"
  Margin="20" 
  Width="640" Height="100" FontSize="48" FontWeight="Bold" Foreground="Maroon">
  This is fading text

  <!-- Animates the text block's opacity. -->
  <TextBlock.Triggers>
    <EventTrigger RoutedEvent="TextBlock.Loaded">
      <BeginStoryboard>
        <Storyboard>
          <DoubleAnimation
            Storyboard.TargetName="MyFadingText" 
            Storyboard.TargetProperty="(TextBlock.Opacity)"
            From="1.0" To="0.0" Duration="0:0:5" 
            AutoReverse="True" RepeatBehavior="Forever" />
        </Storyboard>
      </BeginStoryboard>
    </EventTrigger>
  </TextBlock.Triggers>
</TextBlock>
```

下图显示的效果[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)控件从其不透明度改`1.00`到`0.00`定义的 5 秒间隔期间[Duration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.duration)。

![文本不透明度从 1.00 改为 0.00](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/fadedtext01.png)
文本不透明度从 1.00 改为 0.00

下面的示例使用[ColorAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.coloranimation)进行动画处理的文本块的前景色。 前景色值从一种颜色更改为另一种颜色，持续时间为 5 秒，然后返回到原来的颜色值并继续。

XAML复制

```xaml
<TextBlock
  Name="MyChangingColorText"
  Margin="20" 
  Width="640" Height="100" FontSize="48" FontWeight="Bold">
  This is changing color text
  <TextBlock.Foreground>
    <SolidColorBrush x:Name="MySolidColorBrush" Color="Maroon" />
  </TextBlock.Foreground>

  <!-- Animates the text block's color. -->
  <TextBlock.Triggers>
    <EventTrigger RoutedEvent="TextBlock.Loaded">
      <BeginStoryboard>
        <Storyboard>
          <ColorAnimation 
            Storyboard.TargetName="MySolidColorBrush"
            Storyboard.TargetProperty="Color"
            From="DarkOrange" To="SteelBlue" Duration="0:0:5"
            AutoReverse="True" RepeatBehavior="Forever" />
        </Storyboard>
      </BeginStoryboard>
    </EventTrigger>
  </TextBlock.Triggers>
</TextBlock>
```

下面的示例使用[DoubleAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation)旋转文本块。 文本块旋转一圈，持续时间为 20 秒，然后继续重复该旋转。

XAML复制

```xaml
<TextBlock
  Name="MyRotatingText"
  Margin="20" 
  Width="640" Height="100" FontSize="48" FontWeight="Bold" Foreground="Teal" 
  >
  This is rotating text
  <TextBlock.RenderTransform>
    <RotateTransform x:Name="MyRotateTransform" Angle="0" CenterX="230" CenterY="25"/>
  </TextBlock.RenderTransform>

  <!-- Animates the text block's rotation. -->
  <TextBlock.Triggers>
    <EventTrigger RoutedEvent="TextBlock.Loaded">
      <BeginStoryboard>
        <Storyboard>
          <DoubleAnimation
            Storyboard.TargetName="MyRotateTransform" 
            Storyboard.TargetProperty="(RotateTransform.Angle)"
            From="0.0" To="360" Duration="0:0:10" 
            RepeatBehavior="Forever" />
        </Storyboard>
      </BeginStoryboard>
    </EventTrigger>
  </TextBlock.Triggers>
</TextBlock>
```

## [Create Text with a Shadow](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-create-text-with-a-shadow)

本节中的示例演示如何为所显示的文本创建阴影效果。

[DropShadowEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.dropshadoweffect)对象允许你创建的卷影效果的各种放Windows Presentation Foundation (WPF)对象。 以下示例显示了应用于文本的投影效果。 在本例中，阴影是柔和阴影，这意味着阴影颜色模糊化。

![Softness 的文本阴影=0.25](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/shadowtext01.jpg)
具有柔和阴影的文本的示例

你可以通过设置控制的卷影宽度[ShadowDepth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.dropshadoweffect.shadowdepth)属性。 值为`4.0`指示阴影的宽度为 4 个像素。 你可以控制柔和度，或模糊的阴影通过修改[BlurRadius](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.dropshadoweffect.blurradius)属性。 值为`0.0`指示无模糊。 以下代码示例演示如何创建柔和阴影。

XAML复制

```xaml
<!-- Soft single shadow. -->
<TextBlock
  Text="Shadow Text"
  Foreground="Teal">
  <TextBlock.Effect>
    <DropShadowEffect
      ShadowDepth="4"
      Direction="330"
      Color="Black"
      Opacity="0.5"
     BlurRadius="4"/>
  </TextBlock.Effect>
</TextBlock>
```

 备注

这些卷影效果不会Windows Presentation Foundation (WPF)文本呈现管线。 因此，在使用这些效果时，将禁用 ClearType。

以下示例显示了应用于文本的硬投影效果。 在此例中，阴影不模糊。

![Softness 的文本阴影=0](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/shadowtext02.jpg)
具有硬阴影的文本的示例

你可以通过设置创建硬阴影[BlurRadius](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.dropshadoweffect.blurradius)属性`0.0`，指示是否使用的不模糊。 你可以通过修改控制的阴影方向[Direction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.dropshadoweffect.direction)属性。 将此属性的方向的值设置为之间的度数`0`和`360`。 下图显示的方向值[Direction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.dropshadoweffect.direction)属性设置。

![阴影的 DropShadow 程度设置](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/shadowtext08.png)
DropShadow 方向示意图

以下代码示例演示如何创建硬阴影。

XAML复制

```xaml
<!-- Hard single shadow. -->
<TextBlock
  Text="Shadow Text"
  Foreground="Maroon">
  <TextBlock.Effect>
    <DropShadowEffect
      ShadowDepth="6"
      Direction="135"
      Color="Maroon"
      Opacity="0.35"
      BlurRadius="0.0" />
  </TextBlock.Effect>
</TextBlock>
```

### 使用模糊效果

A[BlurBitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.blurbitmapeffect)可以用于创建可以放置在文本对象后面的卷影类似的效果。 应用于文本的模糊位图效果在各个方向上均匀地对文本进行模糊化。

以下示例显示了应用于文本的模糊效果。

![使用 BlurBitmapEffect 的文本阴影](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/shadowtext06.jpg)
具有模糊效果的文本的示例

以下代码示例演示如何创建模糊效果。

XAML复制

```xaml
<!-- Shadow effect by creating a blur. -->
<TextBlock
  Text="Shadow Text"
  Foreground="Green"
  Grid.Column="0" Grid.Row="0" >
  <TextBlock.Effect>
    <BlurEffect
      Radius="8.0"
      KernelType="Box"/>
  </TextBlock.Effect>
</TextBlock>
<TextBlock
  Text="Shadow Text"
  Foreground="Maroon"
  Grid.Column="0" Grid.Row="0" />
```

### 使用转换变换

A[TranslateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform)可以用于创建可以放置在文本对象后面的卷影类似的效果。

下面的代码示例使用[TranslateTransform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.translatetransform)来偏移文本。 在本示例中，主要文本下方略微偏移的文本副本营造出了阴影效果。

![使用 TranslateTransform 的文本阴影](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/shadowtext07.jpg)
使用转换功能实现阴影效果的文本的示例

以下代码示例演示如何创建转换以实现阴影效果。

XAML复制

```xaml
<!-- Shadow effect by creating a transform. -->
<TextBlock
  Foreground="Black"
  Text="Shadow Text"
  Grid.Column="0" Grid.Row="0">
  <TextBlock.RenderTransform>
    <TranslateTransform X="3" Y="3" />
  </TextBlock.RenderTransform>
</TextBlock>
<TextBlock
  Foreground="Coral"
  Text="Shadow Text"
  Grid.Column="0" Grid.Row="0">
</TextBlock>
```

## [Create Outlined Text](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-create-outlined-text)

在大多数情况下，当要将装饰添加到中的文本字符串时您Windows Presentation Foundation (WPF)应用程序中，使用的根据一系列离散的字符或字形的文本。 例如，您可以创建线性渐变画笔，并将其应用于[Foreground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.foreground)属性的[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)对象。 当显示或编辑文本框中时，线性渐变画笔是自动应用于当前集的文本字符串中的字符。

![使用线性渐变画笔显示的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/outlinedtext01.jpg)
线性渐变画笔应用于文本框中的示例

但是，您还可以将转换到的文本[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)对象，它允许您创建其他类型的可视化多格式文本。 例如，可以创建[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)基于对象的轮廓上的文本字符串。

![使用线性渐变画笔的文本轮廓](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/outlinedtext02.jpg)
线性渐变画笔应用于文本的轮廓几何图形的示例

当文本转换为[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)对象，它不再是一系列字符，不能修改文本字符串中的字符。 但是，可修改已转换文本的笔划和填充属性，以此来影响该文本的外观。 笔划是指已转换文本的轮廓；填充是指已转换文本的轮廓的内部区域。

下面的示例演示了多种方法可以通过修改的笔划和填充的已转换的文本来创建视觉效果。

![对填充和笔画使用不同颜色的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/outlinedtext03.jpg)
将笔划和填充设置为不同颜色的示例

![笔划应用了图像画笔的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/outlinedtext04.jpg)
笔划应用了图像画笔的示例

还有可能要修改的边界框矩形或突出显示，已转换的文本。 下面的示例演示通过修改笔划和突出显示的已转换的文本的一种方法来创建视觉效果。

![笔划应用了图像画笔的文本](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/outlinedtext05.jpg)
笔划和突出显示应用了图像画笔的示例

将文本转换为密钥[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)对象是使用[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext)对象。 创建此对象后，可以使用[BuildGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.buildgeometry)并[BuildHighlightGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext.buildhighlightgeometry)方法将转换为文本[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)对象。 第一种方法将返回带格式的文本; 的几何图形第二种方法返回带格式的文本的几何图形的边界框。 下面的代码示例演示如何创建[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext)对象以及如何检索几何图形的带格式的文本和其边界框。

C#复制

```csharp
/// <summary>
/// Create the outline geometry based on the formatted text.
/// </summary>
public void CreateText()
{
    System.Windows.FontStyle fontStyle = FontStyles.Normal;
    FontWeight fontWeight = FontWeights.Medium;

    if (Bold == true) fontWeight = FontWeights.Bold;
    if (Italic == true) fontStyle = FontStyles.Italic;

    // Create the formatted text based on the properties set.
    FormattedText formattedText = new FormattedText(
        Text,
        CultureInfo.GetCultureInfo("en-us"),
        FlowDirection.LeftToRight,
        new Typeface(
            Font,
            fontStyle,
            fontWeight,
            FontStretches.Normal),
        FontSize,
        System.Windows.Media.Brushes.Black // This brush does not matter since we use the geometry of the text. 
        );

    // Build the geometry object that represents the text.
    _textGeometry = formattedText.BuildGeometry(new System.Windows.Point(0, 0));

    // Build the geometry object that represents the text highlight.
    if (Highlight == true)
    {
        _textHighLightGeometry = formattedText.BuildHighlightGeometry(new System.Windows.Point(0, 0));
    }
}
```

要显示检索[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)对象，您需要访问[DrawingContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingcontext)显示已转换的文本的对象。 在这些代码示例中，这可通过创建从支持用户定义的呈现的类派生的自定义控件对象。

若要显示[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)自定义控件中的对象提供的替代[OnRender](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.onrender)方法。 重写的方法应使用[DrawGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingcontext.drawgeometry)方法，以便绘制[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.geometry)对象。

```csharp
/// <summary>
/// OnRender override draws the geometry of the text and optional highlight.
/// </summary>
/// <param name="drawingContext">Drawing context of the OutlineText control.</param>
protected override void OnRender(DrawingContext drawingContext)
{
    // Draw the outline based on the properties that are set.
    drawingContext.DrawGeometry(Fill, new System.Windows.Media.Pen(Stroke, StrokeThickness), _textGeometry);

    // Draw the text highlight based on the properties that are set.
    if (Highlight == true)
    {
        drawingContext.DrawGeometry(null, new System.Windows.Media.Pen(Stroke, StrokeThickness), _textHighLightGeometry);
    }
}
```

示例自定义用户控件对象的源，请参阅[OutlineTextControl.cs 为C#](https://github.com/dotnet/samples/blob/master/snippets/csharp/VS_Snippets_Wpf/OutlineTextControlViewer/CSharp/OutlineTextControl.cs)并[OutlineTextControl.vb 适用于 Visual Basic](https://github.com/dotnet/samples/blob/master/snippets/visualbasic/VS_Snippets_Wpf/OutlineTextControlViewer/visualbasic/outlinetextcontrol.vb)。

## [Draw Text to a Control's Background](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-draw-text-to-a-control-background)

可以直接到控件的背景中绘制文本的文本字符串转换为[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext)对象，并在其中绘制到控件的对象[DrawingContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingcontext)。 此外可以使用此技术用于绘制到的对象的背景派生自[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)，如[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)和[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)。

![文本显示为背景的控件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/drawtext2background01.png)
具有自定义文本背景的控件的示例

若要绘制到控件的背景，请创建一个新[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)对象，并绘制到对象的已转换的文本[DrawingContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingcontext)。 然后，将分配新[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)给控件的背景属性。

下面的代码示例演示如何创建[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext)对象，并绘制到背景[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)和[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)对象。

C#复制

```csharp
// Handle the WindowLoaded event for the window.
private void WindowLoaded(object sender, EventArgs e) 
{
    // Update the background property of the label and button.
    myLabel.Background = new DrawingBrush(DrawMyText("My Custom Label"));
    myButton.Background = new DrawingBrush(DrawMyText("Display Text"));
}

// Convert the text string to a geometry and draw it to the control's DrawingContext.
private Drawing DrawMyText(string textString)
{
    // Create a new DrawingGroup of the control.
    DrawingGroup drawingGroup = new DrawingGroup();

    // Open the DrawingGroup in order to access the DrawingContext.
    using (DrawingContext drawingContext = drawingGroup.Open())
    {
        // Create the formatted text based on the properties set.
        FormattedText formattedText = new FormattedText(
            textString,
            CultureInfo.GetCultureInfo("en-us"),
            FlowDirection.LeftToRight,
            new Typeface("Comic Sans MS Bold"),
            48,
            System.Windows.Media.Brushes.Black // This brush does not matter since we use the geometry of the text. 
            );

        // Build the geometry object that represents the text.
        Geometry textGeometry = formattedText.BuildGeometry(new System.Windows.Point(20, 0));

        // Draw a rounded rectangle under the text that is slightly larger than the text.
        drawingContext.DrawRoundedRectangle(System.Windows.Media.Brushes.PapayaWhip, null, new Rect(new System.Windows.Size(formattedText.Width + 50, formattedText.Height + 5)), 5.0, 5.0);

        // Draw the outline based on the properties that are set.
        drawingContext.DrawGeometry(System.Windows.Media.Brushes.Gold, new System.Windows.Media.Pen(System.Windows.Media.Brushes.Maroon, 1.5), textGeometry);

        // Return the updated DrawingGroup content to be used by the control.
        return drawingGroup;
    }
}
```

## [Draw Text to a Visual](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-draw-text-to-a-visual)

下面的示例演示如何绘制到的文本[DrawingVisual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingvisual)使用[DrawingContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingcontext)对象。 绘图上下文返回通过调用[RenderOpen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingvisual.renderopen)方法的[DrawingVisual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingvisual)对象。 您可以绘制图形和文本到绘图上下文。

若要绘制文本到绘图上下文，请使用[DrawText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingcontext.drawtext)方法的[DrawingContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingcontext)对象。 在完成到绘图上下文绘制内容，请调用[Close](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingcontext.close)方法来关闭绘图上下文并保留的内容。

```csharp
// Create a DrawingVisual that contains text.
private DrawingVisual CreateDrawingVisualText()
{
    // Create an instance of a DrawingVisual.
    DrawingVisual drawingVisual = new DrawingVisual();

    // Retrieve the DrawingContext from the DrawingVisual.
    DrawingContext drawingContext = drawingVisual.RenderOpen();

    // Draw a formatted text string into the DrawingContext.
    drawingContext.DrawText(
       new FormattedText("Click Me!",
          CultureInfo.GetCultureInfo("en-us"),
          FlowDirection.LeftToRight,
          new Typeface("Verdana"),
          36, System.Windows.Media.Brushes.Black),
          new System.Windows.Point(200, 116));

    // Close the DrawingContext to persist changes to the DrawingVisual.
    drawingContext.Close();

    return drawingVisual;
}
```

> 有关从中提取上述代码示例的完整代码示例，请参阅[使用 DrawingVisual 的命中测试示例](https://go.microsoft.com/fwlink/?LinkID=159994)。

## [Use Special Characters in XAML](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-use-special-characters-in-xaml)

在中创建的标记文件Microsoft Visual Studio自动保存在Unicodeutf-8 文件格式，这意味着大部分特殊字符，如重音符号进行正确编码。 但是，有一组常用特殊字符的处理方式不同。 这些特殊字符遵循万维网联合会 (W3C)XML编码标准。

下表显示这组特殊字符的编码语法：

| 字符 | 语法     | 描述       |
| ---- | -------- | ---------- |
| <    | `&lt;`   | 小于符号。 |
| >    | `&gt;`   | 大于符号。 |
| &    | `&amp;`  | & 符号。   |
| "    | `&quot;` | 双引号。   |

> 如果你创建的标记文件，使用文本编辑器中，如Windows记事本，你必须保存在文件Unicode以保持任何 utf-8 文件格式编码的特殊字符。

以下示例演示创建标记时如何在文本中使用特殊字符。

```xaml
<!-- Display special characters that require special encoding: < > & " -->
<TextBlock>
  &lt;    <!-- Less than symbol -->
  &gt;    <!-- Greater than symbol -->
  &amp;   <!-- Ampersand symbol -->
  &quot;  <!-- Double quote symbol -->
</TextBlock>

<!-- Display miscellaneous special characters -->
<TextBlock>
  Cæsar   <!-- AE dipthong symbol -->
  © 2006  <!-- Copyright symbol -->
  Español <!-- Tilde symbol -->
  ¥       <!-- Yen symbol -->
</TextBlock>
```