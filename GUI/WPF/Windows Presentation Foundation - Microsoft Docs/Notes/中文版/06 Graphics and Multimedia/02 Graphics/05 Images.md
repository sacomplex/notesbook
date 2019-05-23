# [Images](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/images)

Windows Presentation Foundation (WPF) 提供对多种图像格式、高保真图像呈现以及编解码器扩展性的内置支持。

## 本节内容

[图像处理概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/imaging-overview)
[帮助主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/imaging-how-to-topics)


## [Imaging Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/imaging-overview)

本主题介绍 Microsoft Windows Presentation Foundation 图像处理组件。 借助 WPF 图像处理，开发人员可以显示、转换图像和设置图像的格式。

### WPF 图像处理组件

WPF 图像处理 使得 Microsoft Windows 内的图像处理功能得到了极大改进。 以前，图像处理功能（例如在公共控件上显示位图或使用图像）依赖于 Microsoft Windows 图形设备接口 (GDI) 或 Microsoft Windows GDI+ 库。 这些 API 提供了基线图像处理功能，但缺乏诸如编解码器扩展性支持和高保真图像支持之类的功能。 WPF 图像处理 旨在克服 GDI 和 GDI+ 的缺点，并提供一组新的 API，以在应用程序内显示和使用图像。

有两种方式可以访问 WPF 图像处理 API：托管组件和非托管组件。 非托管组件提供以下功能。

- 适用于新的或专用图像格式的扩展性模型。
- 对包括 位图 (BMP)、联合图像专家组 (JPEG)、可移植网络图形 (PNG)、标记图像文件格式 (TIFF)、Microsoft Windows Media 照片、图形交换格式 (GIF) 和图标 (.ico) 在内的本机图像格式增强了性能和安全性。
- 高位深图像数据最多保留 8 位/通道（32 位/像素）。
- 非破坏性图像缩放、剪切和旋转。
- 简化的颜色管理。
- 对文件内的专用元数据的支持。
- 托管组件利用非托管基础结构提供图像与其他 WPF 功能（如 用户界面 (UI)、动画和图形）的无缝集成。 托管的组件还可以利用 Windows Presentation Foundation (WPF) 图像处理编解码器扩展性模型可以自动识别中的新图像格式的WPF应用程序。

大多数托管WPF 图像处理API驻留在[System.Windows.Media.Imaging](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging)命名空间，但一些重要类型，如[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)并[ImageDrawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagedrawing)驻留在[System.Windows.Media](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media)命名空间和[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)驻留在[System.Windows.Controls](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls)命名空间。

本主题提供有关托管组件的其他信息。 有关非托管 API 的详细信息，请参阅[非托管 WPF 图像处理组件](https://docs.microsoft.com/zh-cn/windows/desktop/wic/-wic-lh)文档。

### WPF 图像格式

编解码器用于对特定媒体格式进行解码或编码。 WPF 图像处理 包括一个适用于 BMP、JPEG、PNG、TIFF、Windows Media 照片、GIF 和 ICON 图像格式的编解码器。 利用上述每个编解码器，应用程序可以对其各自的图像格式进行解码（ICON 除外）和编码。

[BitmapSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapsource) 一个重要的类用于解码和编码的图像。 它是 WPF 图像处理 管道的基本构建基块，表示具有特定大小和分辨率的单个不变的像素集。 一个[BitmapSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapsource)可以是单个帧的多个帧图像，也可以是上执行转换的结果[BitmapSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapsource)。 它是许多中使用的主类的父级WPF如映像[BitmapFrame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapframe)。

一个[BitmapFrame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapframe)用于存储的图像格式的实际位图数据。 许多图像格式仅支持一个[BitmapFrame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapframe)，尽管等格式GIF和TIFF支持每个图像的多个帧。 帧由解码器用作输入数据，并传递到编码器以创建图像文件。

下面的示例演示如何[BitmapFrame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapframe)创建从[BitmapSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapsource)，然后添加到TIFF映像。

```csharp
BitmapSource image5 = BitmapSource.Create(
    width,
    height,
    96,
    96,
    PixelFormats.Indexed1,
    BitmapPalettes.WebPalette,
    pixels,
    stride);

FileStream stream5 = new FileStream("palette.tif", FileMode.Create);
TiffBitmapEncoder encoder5 = new TiffBitmapEncoder();
encoder5.Frames.Add(BitmapFrame.Create(image5));
encoder5.Save(stream5);
```

#### 图像格式解码

图像解码是指将某种图像格式转换为可以由系统使用的图像数据。 然后，此图像数据可以用于显示、处理或编码为其他格式。 根据图像格式选择解码器。 自动选择编解码器，除非指定了特定解码器。 [在 WPF 中显示图像](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/imaging-overview#_displayingimages)一节中的示例演示了自动解码。 使用非托管 WPF 图像处理 界面开发并向系统注册的自定义格式解码器会自动加入到解码器选择队列。 这将使得自定义格式可以自动显示在 WPF 应用程序中。

以下示例演示使用位图解码器对 BMP 格式图像进行解码。

```csharp
// Open a Uri and decode a BMP image
Uri myUri = new Uri("tulipfarm.bmp", UriKind.RelativeOrAbsolute);
BmpBitmapDecoder decoder2 = new BmpBitmapDecoder(myUri, BitmapCreateOptions.PreservePixelFormat, BitmapCacheOption.Default);
BitmapSource bitmapSource2 = decoder2.Frames[0];

// Draw the Image
Image myImage2 = new Image();
myImage2.Source = bitmapSource2;
myImage2.Stretch = Stretch.None;
myImage2.Margin = new Thickness(20);
```

#### 图像格式编码

图像编码是指将图像数据转换为特定的图像格式。 然后，已编码的图像数据可以用于创建新的图像文件。 WPF 图像处理 为上面介绍的每种图像格式提供编码器。

以下示例演示使用编码器保存一个新创建的位图图像。

```csharp
FileStream stream = new FileStream("new.bmp", FileMode.Create);
BmpBitmapEncoder encoder = new BmpBitmapEncoder();
TextBlock myTextBlock = new TextBlock();
myTextBlock.Text = "Codec Author is: " + encoder.CodecInfo.Author.ToString();
encoder.Frames.Add(BitmapFrame.Create(image));
encoder.Save(stream);
```

### 在 WPF 中显示图像

有几种方法可在 Windows Presentation Foundation (WPF) 应用程序中显示图像。 可以使用显示图像[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)控件，visual 使用绘制[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)，或使用绘制[ImageDrawing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagedrawing)。

#### 使用 Image 控件

[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image) 是一个框架元素，在应用程序中显示图像的主要方法。 在中XAML，[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)可以采用两种方法; 特性语法或属性语法。 以下示例演示如何使用特性语法或属性标记语法来呈现宽度为 200 像素的图像。 有关特性语法和属性语法的详细信息，请参阅[依赖属性概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-properties-overview)。

```xaml
<!-- Simple image rendering. However, rendering an image this way may not
     result in the best use of application memory. See markup below which
     creates the same end result but using less memory. -->
<Image Width="200" 
Source="C:\Documents and Settings\All Users\Documents\My Pictures\Sample Pictures\Water Lilies.jpg"/>

<Image Width="200">
  <Image.Source>
    <!-- To save significant application memory, set the DecodePixelWidth or  
     DecodePixelHeight of the BitmapImage value of the image source to the desired 
     height and width of the rendered image. If you don't do this, the application will 
     cache the image as though it were rendered as its normal size rather then just 
     the size that is displayed. -->
    <!-- Note: In order to preserve aspect ratio, only set either DecodePixelWidth
         or DecodePixelHeight but not both. -->
    <BitmapImage DecodePixelWidth="200"  
     UriSource="C:\Documents and Settings\All Users\Documents\My Pictures\Sample Pictures\Water Lilies.jpg" />
  </Image.Source>
</Image>
```

许多示例使用[BitmapImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage)对象，以引用的图像文件。 [BitmapImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage) 是一个专用[BitmapSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapsource)适用于可扩展应用程序标记语言 (XAML)加载和是显示为图像的简单办法[Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image.source)的[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)控件。

以下示例演示如何使用代码呈现宽度为 200 像素的图像。

> [BitmapImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage) 实现[ISupportInitialize](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.isupportinitialize)接口来优化对多个属性的初始化。 只能在对象初始化过程中进行属性更改。 调用[BeginInit](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage.begininit)发出信号的初始化已开始和[EndInit](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage.endinit)发出信号的初始化已完成。 初始化后，将忽略所做的属性更改。

```csharp
 // Create Image Element
 Image myImage = new Image();
 myImage.Width = 200;

 // Create source
 BitmapImage myBitmapImage = new BitmapImage();

 // BitmapImage.UriSource must be in a BeginInit/EndInit block
 myBitmapImage.BeginInit();
 myBitmapImage.UriSource = new Uri(@"C:\Documents and Settings\All Users\Documents\My Pictures\Sample Pictures\Water Lilies.jpg");

 // To save significant application memory, set the DecodePixelWidth or  
 // DecodePixelHeight of the BitmapImage value of the image source to the desired 
 // height or width of the rendered image. If you don't do this, the application will 
 // cache the image as though it were rendered as its normal size rather then just 
 // the size that is displayed.
 // Note: In order to preserve aspect ratio, set DecodePixelWidth
 // or DecodePixelHeight but not both.
 myBitmapImage.DecodePixelWidth = 200;
 myBitmapImage.EndInit();
 //set image source
 myImage.Source = myBitmapImage;
```

##### 旋转、转换和剪切图像

WPF 使用户能够使用的属性转换图像[BitmapImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage)或使用其他[BitmapSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapsource)对象如[CroppedBitmap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.croppedbitmap)或[FormatConvertedBitmap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.formatconvertedbitmap)。 上述图像转换可以缩放或旋转图像、更改图像的像素格式或剪切图像。

使用执行图像旋转[Rotation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage.rotation)属性的[BitmapImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage)。 只能以 90 度为增量进行旋转。 在以下示例中，图像旋转了 90 度。

```xaml
<Image Width="150" Margin="5" Grid.Column="0" Grid.Row="1">
  <Image.Source>
    <TransformedBitmap Source="/sampleImages/watermelon.jpg" >
      <TransformedBitmap.Transform>
        <RotateTransform Angle="90"/>
      </TransformedBitmap.Transform>
    </TransformedBitmap>
  </Image.Source>
</Image>
```

```csharp
// Create Image element.
Image rotated90 = new Image();
rotated90.Width = 150;

// Create the TransformedBitmap to use as the Image source.
TransformedBitmap tb = new TransformedBitmap();

// Create the source to use as the tb source.
BitmapImage bi = new BitmapImage();
bi.BeginInit();
bi.UriSource = new Uri(@"sampleImages/watermelon.jpg", UriKind.RelativeOrAbsolute);
bi.EndInit();

// Properties must be set between BeginInit and EndInit calls.
tb.BeginInit();
tb.Source = bi;
// Set image rotation.
RotateTransform transform = new RotateTransform(90);
tb.Transform = transform;
tb.EndInit();
// Set the Image source.
rotated90.Source = tb;
```

将图像转换为不同的像素格式，如灰度使用[FormatConvertedBitmap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.formatconvertedbitmap)。 在以下示例中，图像转换为[Gray4](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pixelformats.gray4)。

```xaml
<!-- Grayscale XAML Image -->
<Image Width="200" Grid.Column="0" Grid.Row="1">
   <Image.Source>
      <FormatConvertedBitmap Source="/sampleImages/rocks.jpg"  DestinationFormat="Gray4" />
   </Image.Source>
</Image>
```

```csharp
//Create Image Element
Image grayImage = new Image();
grayImage.Width = 200;
grayImage.Margin = new Thickness(5);

//Create source using xaml defined resource.
FormatConvertedBitmap fcb = new FormatConvertedBitmap(
   (BitmapImage)this.Resources["masterImage"],PixelFormats.Gray4,null,0);
//set image source
grayImage.Source = fcb;
```

若要裁剪图像，或者[Clip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.clip)的属性[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)或[CroppedBitmap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.croppedbitmap)可用。 通常情况下，如果只是想要显示的图像的一部分[Clip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.clip)应使用。 如果需要编码和保存剪切后的图像，[CroppedBitmap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.croppedbitmap)应使用。 在以下示例中，使用剪辑属性使用剪切图像[EllipseGeometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.ellipsegeometry)。

```xaml
<!-- Cropping an Image using Clip -->
<Image Width="200" Grid.Column="0" Grid.Row="5" Margin="5"
   Source="/sampleImages/gecko.jpg">
  <Image.Clip>
    <EllipseGeometry Center="75,50" RadiusX="50" RadiusY="25" />
  </Image.Clip>
</Image>
```

```csharp
           //Create the image for clipping
           Image clipImage = new Image();
           clipImage.Width = 200;
           clipImage.Margin = new Thickness(5);

           //Create & Set source
           BitmapImage bi = new BitmapImage();
           //BitmapImage.UriSource must be in a BeginInit/EndInit block
           bi.BeginInit();
           bi.UriSource = new Uri("pack://application:,,/sampleImages/gecko.jpg");
           bi.EndInit();
           clipImage.Source = bi;

           //Clip the using an EllipseGeometry
           EllipseGeometry clipGeometry = new EllipseGeometry(new Point(75, 50), 50, 25);
           clipImage.Clip = clipGeometry;
```

##### 拉伸图像

[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image.stretch)属性控制如何拉伸图像以填充其容器。 [Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image.stretch)属性接受以下值，通过定义[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch)枚举：

- [None](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_None)：不拉伸图像以填充输出区域。 如果图像比输出区域大，将图像绘制到输出区域，剪裁掉无法容纳的内容。
- [Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_Fill)：缩放图像以适应输出区域。 由于图像的高度和宽度独立进行缩放，因此图像的原始纵横比可能不会保留。 也就是说，为了完全填充输出容器，图像可能会扭曲。
- [Uniform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_Uniform)：缩放图像，使其完全适应输出区域。 图像的纵横比会保留。
- [UniformToFill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch#System_Windows_Media_Stretch_UniformToFill)：缩放图像，使其在保留图像的原始纵横比的同时完全填充输出区域。

下面的示例应用每个可用[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch)到枚举[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)。

下图显示了示例的输出，并演示了不同[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image.stretch)时必须设置应用到图像。

![Different TileBrush Stretch settings](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/img-mmgraphics-stretchenum.jpg)
不同的拉伸设置

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml" >
  <DockPanel>

    <Border DockPanel.Dock="Top" Background="Black">
      <TextBlock Foreground="White" HorizontalAlignment="Stretch" FontSize="20">
        Stretching an Image
      </TextBlock>
    </Border>

    <Grid Name="simpleGrid" Background="{StaticResource CheckeredBrushResource}" 
       Margin="10" 
       ShowGridLines="True"
       VerticalAlignment="Center"
       HorizontalAlignment="Center">
      <Grid.ColumnDefinitions>
        <ColumnDefinition Width="175" />
        <ColumnDefinition Width="175" />
        <ColumnDefinition Width="175" />
        <ColumnDefinition Width="175" />
      </Grid.ColumnDefinitions>
      <Grid.RowDefinitions>
        <RowDefinition />
        <RowDefinition Height="200"/>
      </Grid.RowDefinitions>
      <!-- Labels -->
      <TextBlock Style="{StaticResource Header1}" 
        Grid.Column="0" Grid.Row="0">None</TextBlock>
      <TextBlock Style="{StaticResource Header1}" 
        Grid.Column="1" Grid.Row="0">Uniform</TextBlock>
      <TextBlock Style="{StaticResource Header1}" 
        Grid.Column="2" Grid.Row="0">UniformToFill</TextBlock>
      <TextBlock Style="{StaticResource Header1}"
        Grid.Column="3" Grid.Row="0">Fill</TextBlock>
      <Border Grid.Column="0" Grid.Row="1" BorderThickness="1" BorderBrush="Black">
        <!-- None: Image is not scaled. If image is larger than the
             output area, the image will be cropped to the size of the output area.-->
        <Image
          Source="sampleImages/gecko.jpg" 
          Stretch="None" />
      </Border>
      <Border Grid.Column="1" Grid.Row="1" BorderThickness="1" BorderBrush="Black">
        <!-- Uniform: Scale to fit output area.
             Aspect ratio is preserved.-->
        <Image
          Source="sampleImages/gecko.jpg" 
          Stretch="Uniform" />
      </Border>
      <Border Grid.Column="2" Grid.Row="1" BorderThickness="1" BorderBrush="Black">
        <!-- UniformToFill: Scale to completely fill output area.
             Aspect ratio is preserved. Cropping may occur.-->
        <Image  
          Source="sampleImages/gecko.jpg" 
        Stretch="UniformToFill" />
      </Border>
      <Border Grid.Column="3" Grid.Row="1" BorderThickness="1" BorderBrush="Black">
      <!-- Fill: Scale to completely fill output area.
             Aspect ratio may not be preserved.-->
      <Image 
        Source="sampleImages/gecko.jpg" 
        Stretch="Fill" />
      </Border>
    </Grid>
  </DockPanel>
</Page>
```

#### 使用图像进行绘制

映像还在应用程序与进行绘制，从而显示[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)。 借助画笔，可以利用任意内容（从简单的纯色到复杂的图案和图像集）绘制 UI 对象。 若要绘制图像，请使用[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)。 [ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)是一种[TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush)其内容定义为位图图像。[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)显示由指定的单个映像及其[ImageSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush.imagesource)属性。 可以控制图像的拉伸、对齐和平铺方式，从而防止失真并生成图案和其他效果。 下图显示了可以使用实现某些效果[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)。

![ImageBrush 输出示例](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/wcpsdk-mmgraphics-imagebrushexamples.gif)
图像画笔可以填充形状、控件、文本等

下面的示例演示了如何绘制一个具有映像使用的按钮的背景[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)。

```xaml
<!-- Sets the button's Background property with an ImageBrush. The resulting
     button has an image as its background. -->
<Button Grid.Row="3" Grid.Column="2" 
 Height="75" Width="100" Foreground="White" FontWeight="Bold"
 HorizontalAlignment="Left">
  A Button
  <Button.Background>
    <ImageBrush ImageSource="sampleImages\blueberries.jpg" />
  </Button.Background>
</Button>
```

有关其他信息[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)，并绘制图像查看[使用图像、 绘图和视觉对象进行绘制](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-images-drawings-and-visuals)。

### 图像元数据

某些图像文件包含用于描述文件的内容或特征的元数据。 例如，大多数数数字相机创建的图像中包含用于捕获该图像的照相机品牌和型号的元数据。 每种图像格式处理元数据的方式不同，但 WPF 图像处理 为存储和检索每种受支持图像格式的元数据提供了一种统一方式。

通过提供对元数据的访问[Metadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapsource.metadata)属性的[BitmapSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapsource)对象。 [Metadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapsource.metadata) 返回[BitmapMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapmetadata)包括所有所包含的图像的元数据的对象。 此数据可以位于一个元数据架构中或位于不同架构的组合中。 WPF 图像处理 支持以下图像元数据架构：可交换图像文件 (Exif)、tEXt（PNG 文本数据）、图像文件目录 (IFD)、国际新闻通信委员会 (IPTC)和 eXtensible Metadata Platform (XMP)。

为了简化读取元数据的过程[BitmapMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapmetadata)提供了可以如轻松访问的多个命名的属性[Author](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapmetadata.author)， [Title](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapmetadata.title)，和[CameraModel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapmetadata.cameramodel)。 许多命名属性还可以用于编写元数据。 元数据查询读取器提供对读取元数据的其他支持。[GetQuery](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapmetadata.getquery)方法用于检索元数据查询读取器通过提供字符串查询，如 *"/ app1/exif /"*。 在以下示例中，[GetQuery](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapmetadata.getquery)用于获取存储在文本 *"/text/description"* 位置。

```csharp
// Add the metadata of the bitmap image to the text block.
TextBlock myTextBlock = new TextBlock();
myTextBlock.Text = "The Description metadata of this image is: " + pngInplace.GetQuery("/Text/Description").ToString();
```

若要编写元数据，请使用元数据查询编写器。 [SetQuery](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapmetadata.setquery) 获取查询编写器并设置所需的值。 在以下示例中，[SetQuery](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapmetadata.setquery)用于写入中存储的文本 *"/text/description"* 位置。

```csharp
Stream pngStream = new System.IO.FileStream("smiley.png", FileMode.Open, FileAccess.ReadWrite, FileShare.ReadWrite);
PngBitmapDecoder pngDecoder = new PngBitmapDecoder(pngStream, BitmapCreateOptions.PreservePixelFormat, BitmapCacheOption.Default);
BitmapFrame pngFrame = pngDecoder.Frames[0];
InPlaceBitmapMetadataWriter pngInplace = pngFrame.CreateInPlaceBitmapMetadataWriter();
if (pngInplace.TrySave() == true)
{ pngInplace.SetQuery("/Text/Description", "Have a nice day."); }
pngStream.Close();
```

### 编解码器扩展性

WPF 图像处理 的核心功能是用于新图像编解码器的扩展性模型。 通过这些非托管的接口，编解码器开发人员可以将编解码器与 WPF 集成，这样 WPF 应用程序就可以自动使用新的图像格式。

有关扩展性 API 的示例，请参阅 [Win32 示例编解码器](https://go.microsoft.com/fwlink/?LinkID=160052)。 此示例演示如何为自定义图像格式创建解码器和编码器。

> 编解码器必须进行数字签名，系统才能够识别它。

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/imaging-how-to-topics)

在本部分中的主题演示如何使用Windows Presentation Foundation (WPF)来显示或改变位图图像。

### 本节内容

[在 XAML 中使用 BitmapImage](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-use-a-bitmapimage)
[将图像作为缩略图加载](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-load-an-image-as-a-thumbnail)
[向位图图像应用转换](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-apply-a-transform-to-a-bitmapimage)
[通过视觉对象创建位图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-bitmap-from-a-visual)
[将视觉对象编码为图像文件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-encode-a-visual-to-an-image-file)
[新建 BitmapSource](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-new-bitmapsource)
[将多个 BitmapSource 对象链在一起](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-chain-bitmapsource-objects-together)
[将 BitmapSource 转换成另一种 PixelFormat](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-convert-a-bitmapsource-to-a-different-pixelformat)
[将 BitmapSource 转换成索引的像素格式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-convert-a-bitmapsource-to-an-indexed-pixel-format)
[编码和解码 JPEG 图像](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-encode-and-decode-a-jpeg-image)
[编码和解码 BMP 图像](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-encode-and-decode-a-bmp-image)
[编码和解码 PNG 图像](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-encode-and-decode-a-png-image)
[编码和解码 WDP 图像](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-encode-and-decode-a-wdp-image)
[编码和解码 GIF 图像](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-encode-and-decode-a-gif-image)
[编码和解码 TIFF 图像](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-encode-and-decode-a-tiff-image)
[在位图中写入元数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-write-metadata-to-a-bitmap)
[从位图读取元数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-read-metadata-from-a-bitmap)

### [Use a BitmapImage in XAML](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-use-a-bitmapimage)

此示例演示如何使用[BitmapImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage)作为源[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)控制中可扩展应用程序标记语言 (XAML)。

#### 示例

```xaml
<!-- Simple image rendering. However, rendering an image this way may not
     result in the best use of application memory. See markup below which
     creates the same end result but using less memory. -->
<Image Width="200" 
Source="C:\Documents and Settings\All Users\Documents\My Pictures\Sample Pictures\Water Lilies.jpg"/>

<Image Width="200">
  <Image.Source>
    <!-- To save significant application memory, set the DecodePixelWidth or  
     DecodePixelHeight of the BitmapImage value of the image source to the desired 
     height and width of the rendered image. If you don't do this, the application will 
     cache the image as though it were rendered as its normal size rather then just 
     the size that is displayed. -->
    <!-- Note: In order to preserve aspect ratio, only set either DecodePixelWidth
         or DecodePixelHeight but not both. -->
    <BitmapImage DecodePixelWidth="200"  
     UriSource="C:\Documents and Settings\All Users\Documents\My Pictures\Sample Pictures\Water Lilies.jpg" />
  </Image.Source>
</Image>
 // Create Image Element
 Image myImage = new Image();
 myImage.Width = 200;

 // Create source
 BitmapImage myBitmapImage = new BitmapImage();

 // BitmapImage.UriSource must be in a BeginInit/EndInit block
 myBitmapImage.BeginInit();
 myBitmapImage.UriSource = new Uri(@"C:\Documents and Settings\All Users\Documents\My Pictures\Sample Pictures\Water Lilies.jpg");

 // To save significant application memory, set the DecodePixelWidth or  
 // DecodePixelHeight of the BitmapImage value of the image source to the desired 
 // height or width of the rendered image. If you don't do this, the application will 
 // cache the image as though it were rendered as its normal size rather then just 
 // the size that is displayed.
 // Note: In order to preserve aspect ratio, set DecodePixelWidth
 // or DecodePixelHeight but not both.
 myBitmapImage.DecodePixelWidth = 200;
 myBitmapImage.EndInit();
 //set image source
 myImage.Source = myBitmapImage;
```

### [Load an Image as a Thumbnail](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-load-an-image-as-a-thumbnail)

下面的示例显示如何加载[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)作为缩略图以节省应用程序内存。

#### 示例

下面的示例设置[DecodePixelWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage.decodepixelwidth)的属性[BitmapImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage)中可扩展应用程序标记语言 (XAML)以减少加载图像所需的内存。

```xaml
<!-- Simple image rendering. However, rendering an image this way may not
     result in the best use of application memory. See markup below which
     creates the same end result but using less memory. -->
<Image Width="200" 
Source="C:\Documents and Settings\All Users\Documents\My Pictures\Sample Pictures\Water Lilies.jpg"/>

<Image Width="200">
  <Image.Source>
    <!-- To save significant application memory, set the DecodePixelWidth or  
     DecodePixelHeight of the BitmapImage value of the image source to the desired 
     height and width of the rendered image. If you don't do this, the application will 
     cache the image as though it were rendered as its normal size rather then just 
     the size that is displayed. -->
    <!-- Note: In order to preserve aspect ratio, only set either DecodePixelWidth
         or DecodePixelHeight but not both. -->
    <BitmapImage DecodePixelWidth="200"  
     UriSource="C:\Documents and Settings\All Users\Documents\My Pictures\Sample Pictures\Water Lilies.jpg" />
  </Image.Source>
</Image>
```

#### 示例

下面的示例设置[DecodePixelWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage.decodepixelwidth)属性的[BitmapImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage)代码，以减少加载图像所需的内存中。

```csharp
 // Create Image Element
 Image myImage = new Image();
 myImage.Width = 200;

 // Create source
 BitmapImage myBitmapImage = new BitmapImage();

 // BitmapImage.UriSource must be in a BeginInit/EndInit block
 myBitmapImage.BeginInit();
 myBitmapImage.UriSource = new Uri(@"C:\Documents and Settings\All Users\Documents\My Pictures\Sample Pictures\Water Lilies.jpg");

 // To save significant application memory, set the DecodePixelWidth or  
 // DecodePixelHeight of the BitmapImage value of the image source to the desired 
 // height or width of the rendered image. If you don't do this, the application will 
 // cache the image as though it were rendered as its normal size rather then just 
 // the size that is displayed.
 // Note: In order to preserve aspect ratio, set DecodePixelWidth
 // or DecodePixelHeight but not both.
 myBitmapImage.DecodePixelWidth = 200;
 myBitmapImage.EndInit();
 //set image source
 myImage.Source = myBitmapImage;
```

### [Apply a Transform to a Bitmap Image](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-apply-a-transform-to-a-bitmapimage)

此示例演示如何将应用[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transform)到[BitmapImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage)。

#### 示例

```csharp
///// Create a BitmapImage and set it's DecodePixelWidth to 200. Use  /////
///// this BitmapImage as a source for other BitmapSource objects.    /////

BitmapImage myBitmapImage = new BitmapImage();

// BitmapSource objects like BitmapImage can only have their properties
// changed within a BeginInit/EndInit block.
myBitmapImage.BeginInit();
myBitmapImage.UriSource = new Uri(@"C:\Documents and Settings\All Users\Documents\My Pictures\Sample Pictures\Water Lilies.jpg");

// To save significant application memory, set the DecodePixelWidth or  
// DecodePixelHeight of the BitmapImage value of the image source to the desired 
// height or width of the rendered image. If you don't do this, the application will 
// cache the image as though it were rendered as its normal size rather then just 
// the size that is displayed.
// Note: In order to preserve aspect ratio, set DecodePixelWidth
// or DecodePixelHeight but not both.
myBitmapImage.DecodePixelWidth = 200;
myBitmapImage.EndInit();

/////////////////// Create a BitmapSource that Rotates the image //////////////////////
// Use the BitmapImage created above as the source for a new BitmapSource object
// that will be scaled to a different size. Create a new BitmapSource by   
// scaling the original one.                                               
// Note: New BitmapSource does not cache. It is always pulled when required.

// Create the new BitmapSource that will be used to scale the size of the source.
TransformedBitmap myRotatedBitmapSource = new TransformedBitmap();

// BitmapSource objects like TransformedBitmap can only have their properties
// changed within a BeginInit/EndInit block.
myRotatedBitmapSource.BeginInit();

// Use the BitmapSource object defined above as the source for this BitmapSource.
// This creates a "chain" of BitmapSource objects which essentially inherit from each other.
myRotatedBitmapSource.Source = myBitmapImage;

// Flip the source 90 degrees.
myRotatedBitmapSource.Transform = new RotateTransform(90);
myRotatedBitmapSource.EndInit();
```

### [Create a Bitmap from a Visual](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-bitmap-from-a-visual)

此示例演示如何创建从位图[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)。 一个[DrawingVisual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingvisual)呈现与[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext)。 [Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)将呈现到[RenderTargetBitmap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.rendertargetbitmap)创建给定文本的位图。

#### 示例

```csharp
Image myImage = new Image();
FormattedText text = new FormattedText("ABC",
        new CultureInfo("en-us"),
        FlowDirection.LeftToRight,
        new Typeface(this.FontFamily, FontStyles.Normal, FontWeights.Normal, new FontStretch()),
        this.FontSize,
        this.Foreground);

DrawingVisual drawingVisual = new DrawingVisual();
DrawingContext drawingContext = drawingVisual.RenderOpen();
drawingContext.DrawText(text, new Point(2, 2));
drawingContext.Close();

RenderTargetBitmap bmp = new RenderTargetBitmap(180, 180, 120, 96, PixelFormats.Pbgra32);
bmp.Render(drawingVisual);
myImage.Source = bmp;
```

### [Encode a Visual to an Image File](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-encode-a-visual-to-an-image-file)

此示例演示如何进行编码[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)为图像文件，并使用对象[RenderTargetBitmap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.rendertargetbitmap)和一个[PngBitmapEncoder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.pngbitmapencoder)。

#### 示例

[DrawingVisual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingvisual)使用创建[BitmapImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage)并[FormattedText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.formattedtext)呈现到[RenderTargetBitmap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.rendertargetbitmap)。 呈现的位图随后用于创建[BitmapFrame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapframe)添加到[PngBitmapEncoder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.pngbitmapencoder)若要创建一个新可移植网络图形 (PNG)文件。

```csharp
// Base Image
BitmapImage bi = new BitmapImage();
bi.BeginInit();
bi.UriSource = new Uri("sampleImages/waterlilies.jpg",UriKind.Relative);
bi.DecodePixelWidth = 200;
bi.EndInit();

// Text to render on the image.
FormattedText text = new FormattedText("Waterlilies",
        new CultureInfo("en-us"),
        FlowDirection.LeftToRight,
        new Typeface(this.FontFamily, FontStyles.Normal, FontWeights.Normal, new FontStretch()),
        this.FontSize,
        Brushes.White);

// The Visual to use as the source of the RenderTargetBitmap.
DrawingVisual drawingVisual = new DrawingVisual();
DrawingContext drawingContext = drawingVisual.RenderOpen();
drawingContext.DrawImage(bi,new Rect(0,0,bi.Width,bi.Height)); 
drawingContext.DrawText(text, new Point(bi.Height/2, 0));
drawingContext.Close();

// The BitmapSource that is rendered with a Visual.
RenderTargetBitmap rtb = new RenderTargetBitmap(bi.PixelWidth, bi.PixelHeight, 96, 96, PixelFormats.Pbgra32);
rtb.Render(drawingVisual);

// Encoding the RenderBitmapTarget as a PNG file.
PngBitmapEncoder png = new PngBitmapEncoder();
png.Frames.Add(BitmapFrame.Create(rtb));
using (Stream stm = File.Create("new.png"))
{
   png.Save(stm);
}
```

一个[PngBitmapEncoder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.pngbitmapencoder)使用在此示例中，但任何派生[BitmapEncoder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapencoder)对象可能已用来创建图像文件。

### [Create a new BitmapSource](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-new-bitmapsource)

此示例演示如何使用[Create](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapsource.create)方法[BitmapSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapsource)若要创建一个新[BitmapSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapsource)对象。

#### 示例

```csharp
// Define parameters used to create the BitmapSource.
PixelFormat pf = PixelFormats.Bgr32;
int width = 200;
int height = 200;
int rawStride = (width * pf.BitsPerPixel + 7) / 8;
byte[] rawImage = new byte[rawStride * height];

// Initialize the image with data.
Random value = new Random();
value.NextBytes(rawImage);

// Create a BitmapSource.
BitmapSource bitmap = BitmapSource.Create(width, height,
    96, 96, pf, null,
    rawImage, rawStride);

// Create an image element;
Image myImage = new Image();
myImage.Width = 200;
// Set image source.
myImage.Source = bitmap;
```

### [Chain BitmapSource Objects Together](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-chain-bitmapsource-objects-together)

此示例演示如何通过链接，图像源到应用各种效果多个[BitmapSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapsource)一起派生的对象。

以下示例使用链接来翻转和更改图像源的像素格式。

#### 示例

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">

  <Page.Resources>

    <!-- This resource defines a BitmapImage with a source and a
         DecodePixelWidth of 200. This property is set to the same value 
         as the desired width of the image to save on memory use. This 
         BitmapImage is used as the base for the other BitmapSource resources. -->
    <BitmapImage x:Key="masterImage" DecodePixelWidth="200" 
     UriSource="C:\Documents and Settings\All Users\Documents\My Pictures\Sample Pictures\Forest.jpg"/>

    <!-- This TransformedBitmap uses the BitmapImage defined above and flips
         it 90 degrees. -->
    <TransformedBitmap x:Key="rotatedImage" Source="{StaticResource masterImage}">
      <TransformedBitmap.Transform>
        <RotateTransform Angle="90" />
      </TransformedBitmap.Transform>
    </TransformedBitmap>

    <!-- This FormatConvertedBitmap uses the TransformedBitmap defined above and
         changes the format to Gray32Float (grayscale). -->
    <FormatConvertedBitmap x:Key="convertFormatImage" 
                           Source="{StaticResource rotatedImage}"
                           DestinationFormat="Gray32Float" />
      
  </Page.Resources>
  
  <StackPanel>
    
    <!-- Apply the "convertFormatImage" resource defined above to this image. 
         The resource is  a combination of all three BitmapSource objects which
         renders this image with DecodePixelWidth set to 200, fliped 90 degrees 
         and converted to grayscale. -->
    <Image Width="200" Source="{StaticResource convertFormatImage}" />
  </StackPanel>
</Page>
```

```csharp
//This is a list of commonly used namespaces for a pane.
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;


namespace SDKSample
{
    public partial class ChainedBitmapSourcesExample : Page
    {
        public ChainedBitmapSourcesExample()
        {
            ///// Create a BitmapImage and set it's DecodePixelWidth to 200. Use  /////
            ///// this BitmapImage as a source for other BitmapSource objects.    /////

            BitmapImage myBitmapImage = new BitmapImage();

            // BitmapSource objects like BitmapImage can only have their properties
            // changed within a BeginInit/EndInit block.
            myBitmapImage.BeginInit();
            myBitmapImage.UriSource = new Uri("sampleImages/WaterLilies.jpg",UriKind.Relative);

            // To save significant application memory, set the DecodePixelWidth or  
            // DecodePixelHeight of the BitmapImage value of the image source to the desired 
            // height or width of the rendered image. If you don't do this, the application will 
            // cache the image as though it were rendered as its normal size rather then just 
            // the size that is displayed.
            // Note: In order to preserve aspect ratio, set DecodePixelWidth
            // or DecodePixelHeight but not both.
            myBitmapImage.DecodePixelWidth = 200;
            myBitmapImage.EndInit();

            /////////////////// Create a BitmapSource that Rotates the image //////////////////////
            // Use the BitmapImage created above as the source for a new BitmapSource object
            // that will be scaled to a different size. Create a new BitmapSource by   
            // scaling the original one.                                               
            // Note: New BitmapSource does not cache. It is always pulled when required.

            // Create the new BitmapSource that will be used to scale the size of the source.
            TransformedBitmap myRotatedBitmapSource = new TransformedBitmap();

            // BitmapSource objects like TransformedBitmap can only have their properties
            // changed within a BeginInit/EndInit block.
            myRotatedBitmapSource.BeginInit();

            // Use the BitmapSource object defined above as the source for this BitmapSource.
            // This creates a "chain" of BitmapSource objects which essentially inherit from each other.
            myRotatedBitmapSource.Source = myBitmapImage;
            // Multiply the size of the X and Y axis of the source by 3.
            myRotatedBitmapSource.Transform = new RotateTransform(90);
            myRotatedBitmapSource.EndInit();

            // Create a new BitmapSource using a different format than the original one.
            FormatConvertedBitmap newFormatedBitmapSource = new FormatConvertedBitmap();

            // BitmapSource objects like FormatConvertedBitmap can only have their properties
            // changed within a BeginInit/EndInit block.
            newFormatedBitmapSource.BeginInit();
            newFormatedBitmapSource.Source = myRotatedBitmapSource;
            newFormatedBitmapSource.DestinationFormat = PixelFormats.Gray32Float;
            newFormatedBitmapSource.EndInit();

            // Create Image Element
            Image myImage = new Image();
            myImage.Width = 200;
            //set image source
            myImage.Source = newFormatedBitmapSource;

            // Add Image to the UI
            StackPanel myStackPanel = new StackPanel();
            myStackPanel.Children.Add(myImage);
            this.Content = myStackPanel;
        }

        public void PageLoaded(object sender, RoutedEventArgs args)
        {


        }

    }
}
```

### [Convert a BitmapSource to a Different PixelFormat](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-convert-a-bitmapsource-to-a-different-pixelformat)

此示例演示如何将转换[BitmapSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapsource)对象 ([BitmapImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage)) 为另一种[PixelFormat](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.pixelformat)使用[FormatConvertedBitmap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.formatconvertedbitmap)。

#### 示例

```csharp
///// Create a BitmapImage and set it's DecodePixelWidth to 200. Use  /////
///// this BitmapImage as a source for other BitmapSource objects.    /////

BitmapImage myBitmapImage = new BitmapImage();

// BitmapSource objects like BitmapImage can only have their properties
// changed within a BeginInit/EndInit block.
myBitmapImage.BeginInit();
myBitmapImage.UriSource = new Uri("sampleImages/WaterLilies.jpg",UriKind.Relative);

// To save significant application memory, set the DecodePixelWidth or  
// DecodePixelHeight of the BitmapImage value of the image source to the desired 
// height or width of the rendered image. If you don't do this, the application will 
// cache the image as though it were rendered as its normal size rather then just 
// the size that is displayed.
// Note: In order to preserve aspect ratio, set DecodePixelWidth
// or DecodePixelHeight but not both.
myBitmapImage.DecodePixelWidth = 200;
myBitmapImage.EndInit();

////////// Convert the BitmapSource to a new format ////////////
// Use the BitmapImage created above as the source for a new BitmapSource object
// which is set to a gray scale format using the FormatConvertedBitmap BitmapSource.                                               
// Note: New BitmapSource does not cache. It is always pulled when required.

FormatConvertedBitmap newFormatedBitmapSource = new FormatConvertedBitmap();

// BitmapSource objects like FormatConvertedBitmap can only have their properties
// changed within a BeginInit/EndInit block.
newFormatedBitmapSource.BeginInit();

// Use the BitmapSource object defined above as the source for this new 
// BitmapSource (chain the BitmapSource objects together).
newFormatedBitmapSource.Source = myBitmapImage;


// Set the new format to Gray32Float (grayscale).
newFormatedBitmapSource.DestinationFormat = createPixelFormat();
newFormatedBitmapSource.EndInit();
```

### [Convert a BitmapSource to an Indexed Pixel Format](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-convert-a-bitmapsource-to-an-indexed-pixel-format)

此示例演示如何将转换[BitmapSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapsource)到索引的像素格式。

#### 示例

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Collections.Generic;
namespace SDKSample
{
    public partial class FormatConvertedBitmapExample2 : Page
    {
        public FormatConvertedBitmapExample2()
        {

            ///// Create a BitmapImage and set it's DecodePixelWidth to 200. Use  /////
            ///// this BitmapImage as a source for other BitmapSource objects.    /////

            BitmapImage myBitmapImage = new BitmapImage();

            // BitmapSource objects like BitmapImage can only have their properties
            // changed within a BeginInit/EndInit block.
            myBitmapImage.BeginInit();
            myBitmapImage.UriSource = new Uri(@"sampleImages/WaterLilies.jpg",UriKind.Relative);

            // To save significant application memory, set the DecodePixelWidth or  
            // DecodePixelHeight of the BitmapImage value of the image source to the desired 
            // height or width of the rendered image. If you don't do this, the application will 
            // cache the image as though it were rendered as its normal size rather then just 
            // the size that is displayed.
            // Note: In order to preserve aspect ratio, set DecodePixelWidth
            // or DecodePixelHeight but not both.
            myBitmapImage.DecodePixelWidth = 200;
            myBitmapImage.EndInit();

            ////////// Convert the BitmapSource to a new format ////////////
            // Use the BitmapImage created above as the source for a new BitmapSource object
            // which is set to a two color pixel format using the FormatConvertedBitmap BitmapSource.                                               
            // Note: New BitmapSource does not cache. It is always pulled when required.

            FormatConvertedBitmap newFormatedBitmapSource = new FormatConvertedBitmap();

            // BitmapSource objects like FormatConvertedBitmap can only have their properties
            // changed within a BeginInit/EndInit block.
            newFormatedBitmapSource.BeginInit();

            // Use the BitmapSource object defined above as the source for this new 
            // BitmapSource (chain the BitmapSource objects together).
            newFormatedBitmapSource.Source = myBitmapImage;

            // Because the DestinationFormat for the FormatConvertedBitmap will be an
            // indexed pixel format (Indexed1),a DestinationPalette also needs to be specified.
            // Below, create a custom two color palette to be used for the DestinationPalette.
            List<System.Windows.Media.Color> colors = new List<System.Windows.Media.Color>();
            colors.Add(System.Windows.Media.Colors.Red);
            colors.Add(System.Windows.Media.Colors.Blue);
            BitmapPalette myPalette = new BitmapPalette(colors);

            // Set the DestinationPalette property to the custom palette created above.
            newFormatedBitmapSource.DestinationPalette = myPalette;

            // Set the DestinationFormat to the palletized pixel format of Indexed1.
            newFormatedBitmapSource.DestinationFormat = PixelFormats.Indexed1;
            newFormatedBitmapSource.EndInit();

            // Create Image Element
            Image myImage = new Image();
            myImage.Width = 200;
            //set image source
            myImage.Source = newFormatedBitmapSource;

            // Add Image to the UI
            StackPanel myStackPanel = new StackPanel();
            myStackPanel.Children.Add(myImage);
            this.Content = myStackPanel;
        }
    }
}
```

### [Encode and Decode a JPEG Image](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-encode-and-decode-a-jpeg-image)

以下示例演示如何解码和编码使用特定的 JPEG 图像[JpegBitmapDecoder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.jpegbitmapdecoder)和[JpegBitmapEncoder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.jpegbitmapencoder)对象。

#### 示例-解码 JPEG 图像

此示例演示如何进行解码 JPEG 图像使用[JpegBitmapDecoder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.jpegbitmapdecoder)从[FileStream](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.filestream)。

```csharp
// Open a Stream and decode a JPEG image
Stream imageStreamSource = new FileStream("tulipfarm.jpg", FileMode.Open, FileAccess.Read, FileShare.Read);
JpegBitmapDecoder decoder = new JpegBitmapDecoder(imageStreamSource, BitmapCreateOptions.PreservePixelFormat, BitmapCacheOption.Default);
BitmapSource bitmapSource = decoder.Frames[0];

// Draw the Image
Image myImage = new Image();
myImage.Source = bitmapSource;
myImage.Stretch = Stretch.None;
myImage.Margin = new Thickness(20);
```

#### 示例-编码的 JPEG 图像

此示例演示如何进行编码[BitmapSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapsource)到 JPEG 图像使用[JpegBitmapEncoder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.jpegbitmapencoder)。

```csharp
int width = 128;
int height = width;
int stride = width / 8;
byte[] pixels = new byte[height * stride];

// Define the image palette
BitmapPalette myPalette = BitmapPalettes.Halftone256;

// Creates a new empty image with the pre-defined palette
BitmapSource image = BitmapSource.Create(
    width,
    height,
    96,
    96,
    PixelFormats.Indexed1,
    myPalette,
    pixels,
    stride);

FileStream stream = new FileStream("new.jpg", FileMode.Create);
JpegBitmapEncoder encoder = new JpegBitmapEncoder();
TextBlock myTextBlock = new TextBlock();
myTextBlock.Text = "Codec Author is: " + encoder.CodecInfo.Author.ToString();
encoder.FlipHorizontal = true;
encoder.FlipVertical = false;
encoder.QualityLevel = 30;
encoder.Rotation = Rotation.Rotate90;
encoder.Frames.Add(BitmapFrame.Create(image));
encoder.Save(stream);
```

### [Encode and Decode a BMP Image](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-encode-and-decode-a-bmp-image)

以下示例演示如何解码和编码位图 (BMP)映像使用特定于[BmpBitmapDecoder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bmpbitmapdecoder)和[BmpBitmapEncoder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bmpbitmapencoder)对象。

#### 示例

此示例演示如何进行解码BMP映像使用[BmpBitmapDecoder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bmpbitmapdecoder)从[Uri](https://docs.microsoft.com/zh-cn/dotnet/api/system.uri)。

```csharp
// Open a Uri and decode a BMP image
Uri myUri = new Uri("tulipfarm.bmp", UriKind.RelativeOrAbsolute);
BmpBitmapDecoder decoder2 = new BmpBitmapDecoder(myUri, BitmapCreateOptions.PreservePixelFormat, BitmapCacheOption.Default);
BitmapSource bitmapSource2 = decoder2.Frames[0];

// Draw the Image
Image myImage2 = new Image();
myImage2.Source = bitmapSource2;
myImage2.Stretch = Stretch.None;
myImage2.Margin = new Thickness(20);
```

#### 示例

此示例演示如何进行编码[BitmapSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapsource)成BMP图像使用[BmpBitmapEncoder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bmpbitmapencoder)。

```csharp
int width = 128;
int height = width;
int stride = width / 8;
byte[] pixels = new byte[height * stride];

// Try creating a new image with a custom palette.
List<System.Windows.Media.Color> colors = new List<System.Windows.Media.Color>();
colors.Add(System.Windows.Media.Colors.Red);
colors.Add(System.Windows.Media.Colors.Blue);
colors.Add(System.Windows.Media.Colors.Green);
BitmapPalette myPalette = new BitmapPalette(colors);

// Creates a new empty image with the pre-defined palette
BitmapSource image = BitmapSource.Create(
    width,
    height,
    96,
    96,
    PixelFormats.Indexed1,
    myPalette,
    pixels,
    stride);

FileStream stream = new FileStream("new.bmp", FileMode.Create);
BmpBitmapEncoder encoder = new BmpBitmapEncoder();
TextBlock myTextBlock = new TextBlock();
myTextBlock.Text = "Codec Author is: " + encoder.CodecInfo.Author.ToString();
encoder.Frames.Add(BitmapFrame.Create(image));
encoder.Save(stream);
```

### [Encode and Decode a PNG Image](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-encode-and-decode-a-png-image)

以下示例演示如何解码和编码可移植网络图形 (PNG)映像使用特定于[PngBitmapDecoder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.pngbitmapdecoder)和[PngBitmapEncoder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.pngbitmapencoder)对象。

#### 示例

此示例演示如何进行解码PNG映像使用[PngBitmapDecoder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.pngbitmapdecoder)从[FileStream](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.filestream)。

```csharp
// Open a Stream and decode a PNG image
Stream imageStreamSource = new FileStream("smiley.png", FileMode.Open, FileAccess.Read, FileShare.Read);
PngBitmapDecoder decoder = new PngBitmapDecoder(imageStreamSource, BitmapCreateOptions.PreservePixelFormat, BitmapCacheOption.Default);
BitmapSource bitmapSource = decoder.Frames[0];

// Draw the Image
Image myImage = new Image();
myImage.Source = bitmapSource;
myImage.Stretch = Stretch.None;
myImage.Margin = new Thickness(20);
```

#### 示例

此示例演示如何进行编码[BitmapSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapsource)成PNG图像使用[PngBitmapEncoder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.pngbitmapencoder)。

```csharp
int width = 128;
int height = 128;
int stride = width;
byte[] pixels = new byte[height * stride];

// Define the image palette
BitmapPalette myPalette = BitmapPalettes.Halftone256;

// Creates a new empty image with the pre-defined palette

BitmapSource image = BitmapSource.Create(
    width,
    height,
    96,
    96,
    PixelFormats.Indexed8,
    myPalette,
    pixels,
    stride);

FileStream stream = new FileStream("new.png", FileMode.Create);
PngBitmapEncoder encoder = new PngBitmapEncoder();
TextBlock myTextBlock = new TextBlock();
myTextBlock.Text = "Codec Author is: " + encoder.CodecInfo.Author.ToString();
encoder.Interlace = PngInterlaceOption.On;
encoder.Frames.Add(BitmapFrame.Create(image));
encoder.Save(stream);
```

### [Encode and Decode a WDP Image](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-encode-and-decode-a-wdp-image)

以下示例演示如何解码和编码Microsoft Windows Media 照片映像使用特定于[WmpBitmapDecoder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.wmpbitmapdecoder)和[WmpBitmapEncoder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.wmpbitmapencoder)对象。

#### 示例

此示例演示如何进行解码Windows Media 照片映像使用[WmpBitmapDecoder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.wmpbitmapdecoder)从[Uri](https://docs.microsoft.com/zh-cn/dotnet/api/system.uri)。

```csharp
// Open a Stream and decode a WDP image
Stream imageStreamSource = new FileStream("tulipfarm.wdp", FileMode.Open, FileAccess.Read, FileShare.Read);
WmpBitmapDecoder decoder = new WmpBitmapDecoder(imageStreamSource, BitmapCreateOptions.PreservePixelFormat, BitmapCacheOption.Default);
BitmapSource bitmapSource = decoder.Frames[0];

// Draw the Image
Image myImage = new Image();
myImage.Source = bitmapSource;
myImage.Stretch = Stretch.None;
myImage.Margin = new Thickness(20);
```

#### 示例

此示例演示如何进行编码[BitmapSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapsource)成Windows Media 照片图像使用[WmpBitmapEncoder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.wmpbitmapencoder)。

```csharp
int width = 128;
int height = width;
int stride = width / 8;
byte[] pixels = new byte[height * stride];

// Define the image palette
BitmapPalette myPalette = BitmapPalettes.WebPalette;

// Creates a new empty image with the pre-defined palette

BitmapSource image = BitmapSource.Create(
    width,
    height,
    96,
    96,
    PixelFormats.Indexed1,
    myPalette,
    pixels,
    stride);

FileStream stream = new FileStream("new.wdp", FileMode.Create);
WmpBitmapEncoder encoder = new WmpBitmapEncoder();
TextBlock myTextBlock = new TextBlock();
myTextBlock.Text = "Codec Author is: " + encoder.CodecInfo.Author.ToString();
encoder.Frames.Add(BitmapFrame.Create(image));
encoder.Save(stream);
```

### [Encode and Decode a GIF Image](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-encode-and-decode-a-gif-image)

以下示例演示如何解码和编码图形交换格式 (GIF)映像使用特定于[GifBitmapDecoder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.gifbitmapdecoder)和[GifBitmapEncoder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.gifbitmapencoder)对象。

#### 示例

此示例演示如何进行解码GIF映像使用[GifBitmapDecoder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.gifbitmapdecoder)从[FileStream](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.filestream)。

```csharp
// Open a Stream and decode a GIF image
Stream imageStreamSource = new FileStream("tulipfarm.gif", FileMode.Open, FileAccess.Read, FileShare.Read);
GifBitmapDecoder decoder = new GifBitmapDecoder(imageStreamSource, BitmapCreateOptions.PreservePixelFormat, BitmapCacheOption.Default);
BitmapSource bitmapSource = decoder.Frames[0];

// Draw the Image
Image myImage = new Image();
myImage.Source = bitmapSource;
myImage.Stretch = Stretch.None;
myImage.Margin = new Thickness(20);
```

#### 示例

此示例演示如何进行编码[BitmapSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapsource)成GIF图像使用[GifBitmapEncoder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.gifbitmapencoder)。

```csharp
int width = 128;
int height = width;
int stride = width / 8;
byte[] pixels = new byte[height * stride];

// Define the image palette
BitmapPalette myPalette = BitmapPalettes.WebPalette;

// Creates a new empty image with the pre-defined palette

BitmapSource image = BitmapSource.Create(
    width,
    height,
    96,
    96,
    PixelFormats.Indexed1,
    myPalette,
    pixels,
    stride);

FileStream stream = new FileStream("new.gif", FileMode.Create);
GifBitmapEncoder encoder = new GifBitmapEncoder();
TextBlock myTextBlock = new TextBlock();
myTextBlock.Text = "Codec Author is: " + encoder.CodecInfo.Author.ToString();
encoder.Frames.Add(BitmapFrame.Create(image));
encoder.Save(stream);
```

### [Encode and Decode a TIFF Image](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-encode-and-decode-a-tiff-image)

以下示例演示如何解码和编码标记图像文件格式 (TIFF)映像使用特定于[TiffBitmapDecoder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.tiffbitmapdecoder)和[TiffBitmapEncoder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.tiffbitmapencoder)对象。

#### 示例

此示例演示如何进行解码TIFF映像使用[TiffBitmapDecoder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.tiffbitmapdecoder)从[Uri](https://docs.microsoft.com/zh-cn/dotnet/api/system.uri)。

```csharp
// Open a Stream and decode a TIFF image
Stream imageStreamSource = new FileStream("tulipfarm.tif", FileMode.Open, FileAccess.Read, FileShare.Read);
TiffBitmapDecoder decoder = new TiffBitmapDecoder(imageStreamSource, BitmapCreateOptions.PreservePixelFormat, BitmapCacheOption.Default);
BitmapSource bitmapSource = decoder.Frames[0];

// Draw the Image
Image myImage = new Image();
myImage.Source = bitmapSource;
myImage.Stretch = Stretch.None;
myImage.Margin = new Thickness(20);
```

#### 示例

此示例演示如何进行编码[BitmapSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapsource)成TIFF图像使用[TiffBitmapEncoder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.tiffbitmapencoder)。

```csharp
int width = 128;
int height = width;
int stride = width / 8;
byte[] pixels = new byte[height * stride];

// Define the image palette
BitmapPalette myPalette = BitmapPalettes.WebPalette;

// Creates a new empty image with the pre-defined palette

BitmapSource image = BitmapSource.Create(
    width,
    height,
    96,
    96,
    PixelFormats.Indexed1,
    myPalette,
    pixels,
    stride);

FileStream stream = new FileStream("new.tif", FileMode.Create);
TiffBitmapEncoder encoder = new TiffBitmapEncoder();
TextBlock myTextBlock = new TextBlock();
myTextBlock.Text = "Codec Author is: " + encoder.CodecInfo.Author.ToString();
encoder.Compression = TiffCompressOption.Zip;
encoder.Frames.Add(BitmapFrame.Create(image));
encoder.Save(stream);
```

### [Write Metadata to a Bitmap](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-write-metadata-to-a-bitmap)

此示例演示如何将元数据写入到使用元数据的查询语言的位图。

#### 示例

```csharp
Stream pngStream = new System.IO.FileStream("smiley.png", FileMode.Open, FileAccess.ReadWrite, FileShare.ReadWrite);
PngBitmapDecoder pngDecoder = new PngBitmapDecoder(pngStream, BitmapCreateOptions.PreservePixelFormat, BitmapCacheOption.Default);
BitmapFrame pngFrame = pngDecoder.Frames[0];
InPlaceBitmapMetadataWriter pngInplace = pngFrame.CreateInPlaceBitmapMetadataWriter();
if (pngInplace.TrySave() == true)
{ pngInplace.SetQuery("/Text/Description", "Have a nice day."); }
pngStream.Close();
```

### [Read Metadata from a Bitmap](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-read-metadata-from-a-bitmap)

此示例演示如何读取位图元数据中使用的元数据查询语言。

#### 示例

```csharp
// Add the metadata of the bitmap image to the text block.
TextBlock myTextBlock = new TextBlock();
myTextBlock.Text = "The Description metadata of this image is: " + pngInplace.GetQuery("/Text/Description").ToString();
```

