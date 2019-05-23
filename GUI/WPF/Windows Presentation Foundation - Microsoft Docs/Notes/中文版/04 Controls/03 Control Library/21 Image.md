# [Image](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/image)

[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)元素用于显示中的位图图像Windows Presentation Foundation (WPF)应用程序。

## 本节内容

[帮助主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/image-how-to-topics)

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/image-how-to-topics)

在本部分中的主题介绍如何使用[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)元素。

### 本节内容

[使用 Image 元素](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-use-the-image-element)
[将图像转换成灰度图像](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-convert-an-image-to-greyscale)
[裁剪图像](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-crop-an-image)
[旋转图像](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-rotate-an-image)

### [Use the Image Element](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-use-the-image-element)

此示例演示如何通过使用应用程序中包含图像[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)元素。

##### 示例

下面的示例演示如何呈现宽为 200 像素的图像。 在此 可扩展应用程序标记语言 (XAML) 示例中，同时使用特性语法和属性标记语法来定义图像。 有关特性语法和属性语法的详细信息，请参阅[依赖属性概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-properties-overview)。 一个[BitmapImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage)用于定义图像的源数据并为属性标记语法示例显式定义。 此外，[DecodePixelWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage.decodepixelwidth)的[BitmapImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage)设置为宽度相同[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)的[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)。 这样做是为了确保呈现图像所使用的内存量最小。

> 如果你想要指定呈现图像的大小，一般情况下，仅指定[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)或[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)但不可同时使用两者。 如果仅指定一个，则会保持图像的纵横比。 否则，图像可能会出现意外的拉伸或扭曲。 若要控制图像的拉伸行为，请使用[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image.stretch)和[StretchDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image.stretchdirection)属性。

> 映像的大小指定的[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)或[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)，你还应设置[DecodePixelWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage.decodepixelwidth)或[DecodePixelHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage.decodepixelheight)的相应大小。

[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image.stretch)属性确定如何拉伸图像源来填充图像元素。 有关详细信息，请参见 [Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.stretch) 枚举。

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

##### 示例

以下示例演示如何使用代码呈现宽度为 200 像素的图像。

> 设置[BitmapImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage)属性必须在完成[BeginInit](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage.begininit)和[EndInit](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage.endinit)块。

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

### [Convert an Image to Greyscale](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-convert-an-image-to-greyscale)

此示例演示如何将图像转换为灰度使用[FormatConvertedBitmap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.formatconvertedbitmap)。

##### 示例

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

    <!-- This FormatConvertedBitmap uses the BitmapImage defined above and
         changes the format to Gray32Float (grayscale). -->
        <FormatConvertedBitmap x:Key="convertFormatImage" 
                               Source="{StaticResource masterImage}" 
                               DestinationFormat="Gray32Float" />
      
  </Page.Resources>
  
  <StackPanel>
    
    <!-- Apply the "convertFormatImage" resource defined above to this image.  -->
    <Image Width="200" Source="{StaticResource convertFormatImage}" />
  </StackPanel>
</Page>
```

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace SDKSample
{
    public partial class FormatConvertedBitmapExample : Page
    {
        public FormatConvertedBitmapExample()
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
    }
}
```

### [Crop an Image](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-crop-an-image)

此示例演示如何裁剪图像使用[CroppedBitmap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.croppedbitmap)。

[CroppedBitmap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.croppedbitmap) 主要用于裁剪后的映像版本进行编码时将查看保存到文件。 若要裁剪图像用于显示目的，请参阅[创建剪辑区域](https://msdn.microsoft.com/library/56e4bed6-78d7-4292-b917-d72d0b3e4376)主题。

##### 示例

以下可扩展应用程序标记语言 (XAML)定义下面的示例中使用的资源。

```xaml
<Page.Resources>
   <!-- Define some image resources, for use as the image element source. -->
   <BitmapImage x:Key="masterImage" UriSource="/sampleImages/gecko.jpg" />
   <CroppedBitmap x:Key="croppedImage" 
      Source="{StaticResource masterImage}" SourceRect="30 20 105 50"/>
</Page.Resources>
```

下面的示例创建映像使用[CroppedBitmap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.croppedbitmap)作为其源。

```xaml
<!-- Use the cropped image resource as the images source -->
<Image Width="200" Source="{StaticResource croppedImage}" 
   Margin="5" Grid.Column="0" Grid.Row="1" />
```

```csharp
// Create an Image element.
Image croppedImage = new Image();
croppedImage.Width = 200;
croppedImage.Margin = new Thickness(5);

// Create a CroppedBitmap based off of a xaml defined resource.
CroppedBitmap cb = new CroppedBitmap(     
   (BitmapSource)this.Resources["masterImage"],
   new Int32Rect(30, 20, 105, 50));       //select region rect
croppedImage.Source = cb;                 //set image source to cropped
```

[CroppedBitmap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.croppedbitmap)还可以用作另一个源[CroppedBitmap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.croppedbitmap)，链接裁剪。 请注意，[SourceRect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.croppedbitmap.sourcerect)使用相对于裁剪位图并不是初始的图像的源的值。

```xaml
<!-- Chain a cropped bitmap off a previosly defined cropped image -->
<Image Width="200" Grid.Column="0" Grid.Row="3" Margin="5">
   <Image.Source>
      <CroppedBitmap Source="{StaticResource croppedImage}" 
         SourceRect="30 0 75 50"/>
   </Image.Source>
</Image>
```

```csharp
// Create an Image element.
Image chainImage = new Image();
chainImage.Width = 200;
chainImage.Margin = new Thickness(5);

// Create the cropped image based on previous CroppedBitmap.
CroppedBitmap chained = new CroppedBitmap(cb,
   new Int32Rect(30, 0, (int)cb.Width-30, (int)cb.Height)); 
// Set the image's source.
chainImage.Source = chained;
```

### [Rotate an Image](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-rotate-an-image)

此示例演示如何通过将图像旋转 90 度[Rotation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage.rotation)属性[BitmapImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapimage)。

##### 示例

```xaml
<Image Width="150" Margin="5" Grid.Column="0" Grid.Row="1">
   <Image.Source>
     <BitmapImage UriSource="/sampleImages/watermelon.jpg" Rotation="Rotate90" />
   </Image.Source>
</Image>
```

```csharp
//Create Image element
Image rotated270 = new Image();
rotated270.Width = 150;

//Create source
BitmapImage bi = new BitmapImage();
//BitmapImage properties must be in a BeginInit/EndInit block
bi.BeginInit();
bi.UriSource = new Uri(@"pack://application:,,/sampleImages/watermelon.jpg");
//Set image rotation
bi.Rotation = Rotation.Rotate270;
bi.EndInit();
//set image source
rotated270.Source = bi;
```