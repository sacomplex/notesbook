# [Digital Ink](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/digital-ink)

此部分讨论了中的数字墨迹使用WPF。 传统上只能在 Tablet PC SDK 中找到，数字墨迹现已在核心 Windows Presentation Foundation。 这意味着你现在可以通过使用 Windows Presentation Foundation 的强大开发完备 Tablet PC 应用程序。

[概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/digital-ink-overviews)
[帮助主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/digital-ink-how-to-topics)

## [Overviews](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/digital-ink-overviews)

[墨迹入门](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/getting-started-with-ink)
[收集墨迹](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/collecting-ink)
[手写识别](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/handwriting-recognition)
[存储墨迹](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/storing-ink)
[墨迹对象模型：Windows 窗体和 COM 与 WPF](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/the-ink-object-model-windows-forms-and-com-versus-wpf)
[高级墨迹处理](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/advanced-ink-handling)

## [Getting Started with Ink](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/getting-started-with-ink)

Windows Presentation Foundation (WPF) 具有墨迹功能，可以轻松地将数字墨迹合并到您的应用程序功能。

### 系统必备

若要使用以下示例中，首先[安装 Microsoft Visual Studio](https://visualstudio.microsoft.com/downloads/?utm_medium=microsoft&utm_source=docs.microsoft.com&utm_campaign=button+cta&utm_content=download+vs2017)。 它还有助于了解如何编写基本的 WPF 应用程序。 WPF 入门的帮助，请参阅[演练：我第一个 WPF 桌面应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/getting-started/walkthrough-my-first-wpf-desktop-application)。

### 快速入门

本部分可帮助您编写的简单的 WPF 应用程序收集墨迹。

#### 如何获取墨迹

若要创建一个 WPF 应用程序的支持手写内容：

1. 打开 Visual Studio。

2. 创建一个新**WPF 应用**。

   在中**新的项目**对话框中，展开**已安装** > **Visual C#** 或**Visual Basic** > **Windows 桌面**类别。 然后，选择**WPF 应用 (.NET Framework)** 应用模板。 输入一个名称，并选择**确定**。

   Visual Studio 创建项目，并*MainWindow.xaml*设计器中打开。

3. 类型`<InkCanvas/>`之间`<Grid>`标记。

   ![使用 InkCanvas 标记的 XAML 设计器](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/getting-started-with-ink/inkcanvas-xaml.png)

4. 按**F5**若要在调试器中启动应用程序。

5. 使用触笔或鼠标，编写**你好世界**在窗口中。

您已编写具有仅 12 击键的"你好 world"应用程序的手写内容等效项 ！

#### 您的应用程序的情趣

让我们来充分利用 WPF 的一些功能。 替换的所有内容的开始和结束之间<窗口 > 使用以下标记的标记：

XAML复制

```xaml
<Page>
  <InkCanvas Name="myInkCanvas" MouseRightButtonUp="RightMouseUpHandler">
    <InkCanvas.Background>
      <LinearGradientBrush>
        <GradientStop Color="Yellow" Offset="0.0" />
          <GradientStop Color="Blue" Offset="0.5" />
            <GradientStop Color="HotPink" Offset="1.0" />
              </LinearGradientBrush>
    </InkCanvas.Background>
  </InkCanvas>
</Page>
```

此 XAML 创建渐变画笔背景墨迹书写表面上。

![墨迹书写在 WPF 应用中的图面上的渐变颜色](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/getting-started-with-ink/gradient-colors.png)

#### 添加一些代码隐藏 XAML

尽管 XAML 可以非常轻松地设计用户界面，任何实际的应用程序将需要添加代码以处理事件。 下面是一个简单示例，放大以响应来自鼠标右键单击的墨迹。

1. 设置`MouseRightButtonUp`在 XAML 中的处理程序：

   XAML复制

   ```xaml
   <InkCanvas Name="myInkCanvas" MouseRightButtonUp="RightMouseUpHandler">
   ```

2. 在中**解决方案资源管理器**，展开 MainWindow.xaml 并打开代码隐藏文件 （MainWindow.xaml.cs 或 MainWindow.xaml.vb）。 添加以下事件处理程序代码：

   C#复制

   ```csharp
   private void RightMouseUpHandler(object sender, 
                                    System.Windows.Input.MouseButtonEventArgs e)
   {
       Matrix m = new Matrix();
       m.Scale(1.1d, 1.1d);
       ((InkCanvas)sender).Strokes.Transform(m, true);
   }
   ```

3. 运行该应用程序。 添加一些墨迹，然后用鼠标右键单击或执行与触笔按下保持等效。

   用鼠标右键单击每个时间会放大显示。

#### 使用程序代码而不是 XAML

可以从程序代码来访问所有 WPF 功能。 请按照下列步骤为根本不使用任何 XAML 的 WPF 创建"Hello 墨迹 World"应用程序。

1. 在 Visual Studio 中创建新的控制台应用程序项目。

   在中**新的项目**对话框中，展开**已安装** > **Visual C#** 或**Visual Basic** > **Windows 桌面**类别。 然后，选择**控制台应用 (.NET Framework)** 应用模板。 输入一个名称，并选择**确定**。

2. 将以下代码粘贴到 Program.cs 或 Program.vb 文件：

   C#复制

   ```csharp
   using System;
   using System.Windows;
   using System.Windows.Controls;
   class Program : Application
   {
       Window win;
       InkCanvas ic;
   
       protected override void OnStartup(StartupEventArgs args)
       {
           base.OnStartup(args);
           win = new Window();
           ic = new InkCanvas();
           win.Content = ic;
           win.Show();
       }
   
       [STAThread]
       static void Main(string[] args)
       {
           new Program().Run();
       }
   }
   ```

3. 通过右键单击添加对 PresentationCore、 PresentationFramework、 和 WindowsBase 程序集的引用**引用**中**解决方案资源管理器**，然后选择**添加引用**.

   ![引用管理器显示 PresentationCore 和 PresentationFramework](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/getting-started-with-ink/references.png)

4. 生成应用程序通过按**F5**。

## [Collecting Ink](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/collecting-ink)

[Windows Presentation Foundation](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/index) 平台会收集数字墨迹，这是其功能中的核心部分之一。 本主题讨论用于收集墨迹 Windows Presentation Foundation (WPF) 中的方法。

### 系统必备

若要使用下面的示例，必须首先安装 Visual Studio 和Windows SDK。 您还应了解如何编写 WPF 应用程序。 有关如何开始使用 WPF 的详细信息，请参阅[演练：我第一个 WPF 桌面应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/getting-started/walkthrough-my-first-wpf-desktop-application)。

### 使用 InkCanvas 元素

[System.Windows.Controls.InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)元素提供 WPF 中收集墨迹的最简单方法。 使用[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)元素可接收和显示墨迹输入。 通常使用触笔（与数字化仪交互产生墨迹笔画）输入墨迹。 此外，还可以使用鼠标代替触笔。 创建的笔画表示为[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke)对象，并且它们可以操作以编程方式和用户输入。 [InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)使用户能够选择、 修改或删除现有[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke)。

通过使用 XAML，您可以设置墨迹收集与添加轻松**InkCanvas**到树的元素。 下面的示例添加[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)到 Visual Studio 中创建一个默认 WPF 项目：

XAML复制

```xaml
<Grid>
  <InkCanvas/>
</Grid>
```

**InkCanvas**元素还可以包含子元素，这样便可以将墨迹批注功能添加到几乎任何类型的 XAML 元素。 例如，若要将墨迹功能添加到文本元素，只需使其成为子的[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas):

XAML复制

```xaml
<InkCanvas>
  <TextBlock>Show text here.</TextBlock>
</InkCanvas>
```

添加图像墨迹标记支持操作同样非常简单：

XAML复制

```xaml
<InkCanvas>
  <Image Source="myPicture.jpg"/>
</InkCanvas>
```

#### InkCollection 模式

[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)提供支持，对各种输入模式通过其[EditingMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas.editingmode)属性。

#### 操作墨迹

[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)对多种墨迹编辑操作提供支持。 例如，[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)支持笔后清除图像以及任何其他代码需要将该功能添加到元素。

##### 选择

设置选择模式非常简单，只设置[InkCanvasEditingMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvaseditingmode)属性设置为**选择**。

下面的代码设置值的基础的编辑模式[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.checkbox):

C#复制

```csharp
// Set the selection mode based on a checkbox
if ((bool)cbSelectionMode.IsChecked)
{
    theInkCanvas.EditingMode = InkCanvasEditingMode.Select;
}
else
{
    theInkCanvas.EditingMode = InkCanvasEditingMode.Ink;
}
```

##### DrawingAttributes

使用[DrawingAttributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke.drawingattributes)要更改墨迹笔画的外观属性。 例如，[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.drawingattributes.color)的成员[DrawingAttributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.drawingattributes)设置的颜色呈现的[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke)。

下面的示例更改选定笔画的颜色为红色：

C#复制

```csharp
// Get the selected strokes from the InkCanvas
StrokeCollection selection = theInkCanvas.GetSelectedStrokes();

// Check to see if any strokes are actually selected
if (selection.Count > 0)
{
    // Change the color of each stroke in the collection to red
    foreach (System.Windows.Ink.Stroke stroke in selection)
    {
        stroke.DrawingAttributes.Color = System.Windows.Media.Colors.Red;
    }
}
```

#### DefaultDrawingAttributes

[DefaultDrawingAttributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas.defaultdrawingattributes)属性提供访问权限属性，例如高度、 宽度和要在其中创建的笔画的颜色[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)。 一旦更改[DefaultDrawingAttributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas.defaultdrawingattributes)，所有将来的笔画输入到[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)呈现使用新的属性值。

还可以修改[DefaultDrawingAttributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas.defaultdrawingattributes)在代码隐藏文件中，可用于 XAML 语法指定[DefaultDrawingAttributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas.defaultdrawingattributes)属性。

下面的示例演示如何设置[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.drawingattributes.color)属性。 若要使用此代码，创建新的 WPF 项目在 Visual Studio 中名为"HelloInkCanvas"。 中的代码替换*MainWindow.xaml*文件使用以下代码：

XAML复制

```xaml
<Window x:Class="HelloInkCanvas.Window1"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    xmlns:Ink="clr-namespace:System.Windows.Ink;assembly=PresentationCore"
    Title="Hello, InkCanvas!" Height="300" Width="300"
    >
  <Grid>
    <InkCanvas Name="inkCanvas1" Background="Ivory">
      <InkCanvas.DefaultDrawingAttributes>
        <Ink:DrawingAttributes xmlns:ink="system-windows-ink" Color="Red" Width="5" />
      </InkCanvas.DefaultDrawingAttributes>
    </InkCanvas>

    <!-- This stack panel of buttons is a sibling to InkCanvas (not a child) but overlapping it, 
         higher in z-order, so that ink is collected and rendered behind -->
    <StackPanel Name="buttonBar" VerticalAlignment="Top" Height="26" Orientation="Horizontal" Margin="5">
      <Button Click="Ink">Ink</Button>
      <Button Click="Highlight">Highlight</Button>
      <Button Click="EraseStroke">EraseStroke</Button>
      <Button Click="Select">Select</Button>
    </StackPanel>
  </Grid>
</Window>
```

接下来，将以下按钮事件处理程序添加到代码隐藏文件，在 MainWindow 类中：

C#复制

```csharp
// Set the EditingMode to ink input.
private void Ink(object sender, RoutedEventArgs e)
{
    inkCanvas1.EditingMode = InkCanvasEditingMode.Ink;

    // Set the DefaultDrawingAttributes for a red pen.
    inkCanvas1.DefaultDrawingAttributes.Color = Colors.Red;
    inkCanvas1.DefaultDrawingAttributes.IsHighlighter = false;
    inkCanvas1.DefaultDrawingAttributes.Height = 2;
}

// Set the EditingMode to highlighter input.
private void Highlight(object sender, RoutedEventArgs e)
{
    inkCanvas1.EditingMode = InkCanvasEditingMode.Ink;

    // Set the DefaultDrawingAttributes for a highlighter pen.
    inkCanvas1.DefaultDrawingAttributes.Color = Colors.Yellow;
    inkCanvas1.DefaultDrawingAttributes.IsHighlighter = true;
    inkCanvas1.DefaultDrawingAttributes.Height = 25;
}

// Set the EditingMode to erase by stroke.
private void EraseStroke(object sender, RoutedEventArgs e)
{
    inkCanvas1.EditingMode = InkCanvasEditingMode.EraseByStroke;
}

// Set the EditingMode to selection.
private void Select(object sender, RoutedEventArgs e)
{
    inkCanvas1.EditingMode = InkCanvasEditingMode.Select;
}
```

复制此代码后, 按**F5** Visual Studio 调试器中运行程序中。

请注意如何[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)的顶部将按钮置于[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)。 如果您尝试对墨迹上方的按钮，[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)收集和按钮后面呈现墨迹。 这是因为这些按钮是同级的[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)而不是子级。 此外，这些按钮的 Z 顺序较高，所以墨迹呈现在其后面。

## [Handwriting Recognition](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/handwriting-recognition)

本节介绍了识别基础知识，因为这与 WPF 平台中数字墨迹有关。

### 识别解决方案

以下示例演示如何使用 [Microsoft.Ink.InkCollector](https://msdn.microsoft.com/library/microsoft.ink.inkcollector(v=vs.90).aspx) 类识别墨迹。

 备注

此示例要求在系统上安装手写识别器。

在 Visual Studio 中创建一个名为 **InkRecognition** 的新 WPF 应用程序项目。 用下列 XAML 代码替换 Window1.xaml 文件的内容。 此代码呈现应用程序的用户界面。

XAML复制

```xaml
<Window x:Class="InkRecognition.Window1"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    Title="InkRecognition" 
    >
  <Canvas Name="theRootCanvas">
    <Border
      Background="White"
      BorderBrush="Black"
      BorderThickness="2"
      Height="300"
      Width="300"
      Canvas.Top="10"
      Canvas.Left="10">
      <InkCanvas Name="theInkCanvas"></InkCanvas>
    </Border>
    <TextBox Name="textBox1"
      Height="25"
      Width="225"
      Canvas.Top="325"
      Canvas.Left="10"></TextBox>
    <Button
      Height="25"
      Width="75"
      Canvas.Top="325"
      Canvas.Left="235"
      Click="buttonClick">Recognize</Button>
        <Button x:Name="btnClear" Content="Clear Canvas" Canvas.Left="10" Canvas.Top="367" Width="75" Click="btnClear_Click"/>
    </Canvas>
</Window>
```

添加对 Microsoft 墨迹程序集和 Microsoft.Ink.dll 的引用，可在 \Program Files\Common Files\Microsoft Shared\Ink 中找到这些内容。 用下列代码替换代码隐藏文件的内容。

C#复制

```csharp
using System.Windows;
using Microsoft.Ink;
using System.IO;

namespace InkRecognition
{
    /// <summary>
    /// Interaction logic for Window1.xaml
    /// </summary>

    public partial class Window1 : Window
    {

        public Window1()
        {
            InitializeComponent();
        }

        // Recognizes handwriting by using RecognizerContext
        private void buttonClick(object sender, RoutedEventArgs e)
        {
            using (MemoryStream ms = new MemoryStream())
            {
                theInkCanvas.Strokes.Save(ms);
                var myInkCollector = new InkCollector();
                var ink = new Ink();
                ink.Load(ms.ToArray());

                using (RecognizerContext context = new RecognizerContext())
                {
                    if (ink.Strokes.Count > 0)
                    {
                        context.Strokes = ink.Strokes;
                        RecognitionStatus status;

                        var result = context.Recognize(out status);

                        if (status == RecognitionStatus.NoError)
                            textBox1.Text = result.TopString;
                        else
                            MessageBox.Show("Recognition failed");

                    }
                    else
                        MessageBox.Show("No stroke detected");
                }
            }
        }

        private void btnClear_Click(object sender, RoutedEventArgs e) {
            theInkCanvas.Strokes.Clear();
        }
    }
}
```

## [Storing Ink](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/storing-ink)

[Save](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.strokecollection.save)方法来存储墨迹作为墨迹序列化格式 (ISF) 提供支持。 构造函数[StrokeCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.strokecollection)类用于读取墨迹数据提供支持。

### 手写内容存储和检索

本部分讨论如何存储和检索中的墨迹WPF平台。

下面的示例实现一个按钮单击事件处理程序，向用户呈现一个保存文件对话框，并将从手写内容保存[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)扩展到一个文件。

C#复制

```csharp
private void buttonSaveAsClick(object sender, RoutedEventArgs e)
{
    SaveFileDialog saveFileDialog1 = new SaveFileDialog();
    saveFileDialog1.Filter = "isf files (*.isf)|*.isf";

    if (saveFileDialog1.ShowDialog() == true)
    {
        FileStream fs = new FileStream(saveFileDialog1.FileName,
                                       FileMode.Create);
        theInkCanvas.Strokes.Save(fs);
        fs.Close();
    }
}
```

下面的示例实现一个按钮单击事件处理程序，向用户呈现一个文件打开对话框并从到的文件中读取墨迹[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)元素。

C#复制

```csharp
private void buttonLoadClick(object sender, RoutedEventArgs e)
{
    OpenFileDialog openFileDialog1 = new OpenFileDialog();
    openFileDialog1.Filter = "isf files (*.isf)|*.isf";

    if (openFileDialog1.ShowDialog() == true)
    {
        FileStream fs = new FileStream(openFileDialog1.FileName,
                                       FileMode.Open);
        theInkCanvas.Strokes = new StrokeCollection(fs);
        fs.Close();
    }
}
```

## [The Ink Object Model: Windows Forms and COM versus WPF](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/the-ink-object-model-windows-forms-and-com-versus-wpf)

有实质上是支持数字墨迹的三个平台： Tablet PC Windows 窗体平台、 Tablet PC COM 平台和 Windows Presentation Foundation (WPF) 平台。 类似的对象模型，但该对象的模型的 Windows 窗体和 COM 平台共享WPF平台具有显著差异。 本主题讨论了在高级别的差异，以便使用了一个对象模型的开发人员可以更好地了解其他。

### 在应用程序中启用墨迹

所有三个平台都附带了对象和使应用程序以接收来自 tablet 笔输入控件。 Windows 窗体和 COM 平台附带[Microsoft.Ink.InkPicture](https://msdn.microsoft.com/library/aa514604.aspx)， [Microsoft.Ink.InkEdit](https://msdn.microsoft.com/library/ms835842.aspx)， [Microsoft.Ink.InkOverlay](https://msdn.microsoft.com/library/ms833057.aspx)和[Microsoft.Ink.InkCollector](https://msdn.microsoft.com/library/ms836493.aspx)类。[Microsoft.Ink.InkPicture](https://msdn.microsoft.com/library/aa514604.aspx)并[Microsoft.Ink.InkEdit](https://msdn.microsoft.com/library/ms835842.aspx)是可以添加的控件的应用程序来收集墨迹。 [Microsoft.Ink.InkOverlay](https://msdn.microsoft.com/library/ms833057.aspx)并[Microsoft.Ink.InkCollector](https://msdn.microsoft.com/library/ms836493.aspx)可以附加到现有的窗口墨迹启用 windows 和自定义控件。

WPF 平台包括[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)控件。 您可以添加[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)到你的应用程序并立即开始收集墨迹。 使用[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)，用户可以复制、 选择和重设大小墨迹。 你可以添加到其他控件[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)，用户可以通过这些控件中、 太手写和。 可以通过添加创建手写功能的自定义控件[InkPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkpresenter)和收集其触笔接触点。

下表列出了在何处了解有关启用应用程序中的手写内容的详细信息：

| 若要执行此操作...              | 在 WPF 平台上...                                             | 在 Windows 窗体/COM 平台上...                                |
| ------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 向应用程序添加的手写功能的控件 | 请参阅[墨迹入门](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/getting-started-with-ink)。 | 请参阅[自动声明窗体示例](https://docs.microsoft.com/zh-cn/windows/desktop/tablet/auto-claims-form-sample) |
| 启用自定义控件上的墨迹         | 请参阅[创建墨迹输入控件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/creating-an-ink-input-control)。 | 请参阅[墨迹剪贴板示例](https://docs.microsoft.com/zh-cn/windows/desktop/tablet/ink-clipboard-sample)。 |

### 墨迹数据

Windows 窗体和 COM 平台上[Microsoft.Ink.InkCollector](https://msdn.microsoft.com/library/ms836493.aspx)， [Microsoft.Ink.InkOverlay](https://msdn.microsoft.com/library/ms833057.aspx)， [Microsoft.Ink.InkEdit](https://msdn.microsoft.com/library/ms835842.aspx)，和[Microsoft.Ink.InkPicture](https://msdn.microsoft.com/library/aa514604.aspx)每个公开[Microsoft.Ink.Ink](https://msdn.microsoft.com/library/aa515768.aspx?displayProperty=nameWithType)对象。 [Microsoft.Ink.Ink](https://msdn.microsoft.com/library/aa515768.aspx)对象的一个或多个包含的数据[Microsoft.Ink.Stroke](https://msdn.microsoft.com/library/ms827842.aspx?displayProperty=nameWithType)对象，并公开公共方法和属性来管理和处理这些笔画。 [Microsoft.Ink.Ink](https://msdn.microsoft.com/library/aa515768.aspx)对象管理包含; 的笔画的生存期[Microsoft.Ink.Ink](https://msdn.microsoft.com/library/aa515768.aspx)对象用于创建和删除它所拥有的笔画。 每个[Microsoft.Ink.Stroke](https://msdn.microsoft.com/library/ms827842.aspx)已在其父级中是唯一的标识符[Microsoft.Ink.Ink](https://msdn.microsoft.com/library/aa515768.aspx)对象。

在 WPF 平台上，[System.Windows.Ink.Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke)类拥有并管理自己的生存期。 一组[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke)中可以一起收集对象[StrokeCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.strokecollection)，其中提供常见的手写内容的方法的数据管理操作如命中测试、 擦除、 转换和序列化手写内容。 一个[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke)可以属于零、 一个或多个[StrokeCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.strokecollection)上任何对象提供时间。 而不是让[Microsoft.Ink.Ink](https://msdn.microsoft.com/library/aa515768.aspx?displayProperty=nameWithType)对象，[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)并[InkPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkpresenter)包含[System.Windows.Ink.StrokeCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.strokecollection)。

以下两个插图将墨迹数据对象模型进行比较。 Windows 窗体和 COM 平台上[Microsoft.Ink.Ink](https://msdn.microsoft.com/library/aa515768.aspx?displayProperty=nameWithType)对象约束的生存期[Microsoft.Ink.Stroke](https://msdn.microsoft.com/library/ms827842.aspx?displayProperty=nameWithType)对象以及属于各个笔画的笔针数据包。 两个或多个笔画可以引用相同[Microsoft.Ink.DrawingAttributes](https://msdn.microsoft.com/library/ms837931.aspx?displayProperty=nameWithType)对象，如以下插图所示。

![COM 的墨迹对象模型关系图/Winforms。](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/ink-inkownsstrokes.png)

上WPF，则每个[System.Windows.Ink.Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke)是公共语言运行时对象存在，只要必须对它的引用。 每个[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke)引用[StylusPointCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspointcollection)和[System.Windows.Ink.DrawingAttributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.drawingattributes)对象，也是公共语言运行时对象。

![WPF 墨迹对象模型示意图。](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/ink-wpfinkobjectmodel.png)

下表比较了如何完成一些常见的任务上WPF平台和 Windows 窗体和 COM 的平台。

| 任务                       | Windows Presentation Foundation                              | Windows 窗体和 COM                                           |
| -------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 将手写内容保存             | [Save](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.strokecollection.save) | [Microsoft.Ink.Ink.Save](https://technet.microsoft.com/library/security/microsoft.ink.ink.save(v=vs.90)) |
| 加载手写内容               | 创建[StrokeCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.strokecollection)与[StrokeCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.strokecollection.-ctor)构造函数。 | [Microsoft.Ink.Ink.Load](https://msdn.microsoft.com/library/microsoft.ink.ink.load(v=vs.90).aspx) |
| 命中的测试                 | [HitTest](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.strokecollection.hittest) | [Microsoft.Ink.Ink.HitTest](https://msdn.microsoft.com/library/aa515934.aspx) |
| 复制墨迹                   | [CopySelection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas.copyselection) | [Microsoft.Ink.Ink.ClipboardCopy](https://msdn.microsoft.com/library/microsoft.ink.ink.clipboardcopy(v=vs.100).aspx) |
| 粘贴墨迹                   | [Paste](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas.paste) | [Microsoft.Ink.Ink.ClipboardPaste](https://msdn.microsoft.com/library/microsoft.ink.ink.clipboardpaste(v=vs.100).aspx) |
| 访问自定义属性上的笔画集合 | [AddPropertyData](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.strokecollection.addpropertydata) (在内部存储和访问通过属性[AddPropertyData](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.strokecollection.addpropertydata)， [RemovePropertyData](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.strokecollection.removepropertydata)，和[ContainsPropertyData](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.strokecollection.containspropertydata)) | 使用[Microsoft.Ink.Ink.ExtendedProperties](https://msdn.microsoft.com/library/microsoft.ink.ink.extendedproperties(v=vs.100).aspx) |

#### 平台之间共享墨迹

尽管平台墨迹数据的不同的对象模型，但共享平台之间的数据是非常简单。 下面的示例将手写内容保存从 Windows 窗体应用程序，并将手写内容加载到 Windows Presentation Foundation 应用程序。

C#复制

```csharp
using Microsoft.Ink;
using System.Drawing;
```

C#复制

```csharp
/// <summary>
/// Saves the digital ink from a Windows Forms application.
/// </summary>
/// <param name="inkToSave">An Ink object that contains the 
/// digital ink.</param>
/// <returns>A MemoryStream containing the digital ink.</returns>
MemoryStream SaveInkInWinforms(Ink inkToSave)
{
    byte[] savedInk = inkToSave.Save();

    return (new MemoryStream(savedInk));

}
```

C#复制

```csharp
using System.Windows.Ink;
```

C#复制

```csharp
/// <summary>
/// Loads digital ink into a StrokeCollection, which can be 
/// used by a WPF application.
/// </summary>
/// <param name="savedInk">A MemoryStream containing the digital ink.</param>
public void LoadInkInWPF(MemoryStream inkStream)
{
    strokes = new StrokeCollection(inkStream);
}
```

下面的示例将手写内容保存从 Windows Presentation Foundation 应用程序，并将手写内容加载到 Windows 窗体应用程序。

C#复制

```csharp
using System.Windows.Ink;
```

C#复制

```csharp
/// <summary>
/// Saves the digital ink from a WPF application.
/// </summary>
/// <param name="inkToSave">A StrokeCollection that contains the 
/// digital ink.</param>
/// <returns>A MemoryStream containing the digital ink.</returns>
MemoryStream SaveInkInWPF(StrokeCollection strokesToSave)
{
    MemoryStream savedInk = new MemoryStream();

    strokesToSave.Save(savedInk);

    return savedInk;
}
```

C#复制

```csharp
using Microsoft.Ink;
using System.Drawing;
```

C#复制

```csharp
/// <summary>
/// Loads digital ink into a Windows Forms application.
/// </summary>
/// <param name="savedInk">A MemoryStream containing the digital ink.</param>
public void LoadInkInWinforms(MemoryStream savedInk)
{
    theInk = new Ink();
    theInk.Load(savedInk.ToArray());
}
```

### 从 Tablet 笔事件

[Microsoft.Ink.InkOverlay](https://msdn.microsoft.com/library/ms833057.aspx)， [Microsoft.Ink.InkCollector](https://msdn.microsoft.com/library/ms836493.aspx)，并[Microsoft.Ink.InkPicture](https://msdn.microsoft.com/library/aa514604.aspx)平台上的 Windows 窗体和 COM 接收事件时用户输入笔数据。 [Microsoft.Ink.InkOverlay](https://msdn.microsoft.com/library/ms833057.aspx)或[Microsoft.Ink.InkCollector](https://msdn.microsoft.com/library/ms836493.aspx)附加到一个窗口或控件，并可以订阅由 tablet 输入数据引发的事件。 这些事件发生时的线程取决于是否使用笔、 鼠标，引发的事件或以编程方式。 关于线程处理与这些事件相关的详细信息，请参阅[线程处理的一般注意事项](https://docs.microsoft.com/zh-cn/windows/desktop/tablet/general-threading-considerations)并[线程上激发事件可以](https://docs.microsoft.com/zh-cn/windows/desktop/tablet/threads-on-which-an-event-can-fire)。

在 Windows Presentation Foundation 平台上，[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)类具有笔输入的事件。 这意味着每个控件都公开完整的触笔事件集。 在触笔事件具有隧道/浮升事件对，并始终发生在应用程序线程。 有关详细信息，请参阅[路由事件概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/routed-events-overview)。

下图显示了将引发触笔事件的类的对象模型进行比较。 Windows Presentation Foundation 对象模型仅显示浮升事件，不隧道事件对应项。

![在 WPF 与 Winforms 中的触笔事件的关系图。](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/ink-stylusevents.png)

### 笔数据

所有三个平台为您提供截获和处理来自 tablet 笔的数据的方法。 在 Windows 窗体和 COM 的平台上，这通过创建[Microsoft.StylusInput.RealTimeStylus](https://msdn.microsoft.com/library/microsoft.stylusinput.realtimestylus(v=vs.100).aspx)、 将窗口或控件附加到它，以及创建实现的类[Microsoft.StylusInput.IStylusSyncPlugin](https://msdn.microsoft.com/library/microsoft.stylusinput.istylussyncplugin(v=vs.100).aspx)或[Microsoft.StylusInput.IStylusAsyncPlugin](https://msdn.microsoft.com/library/microsoft.stylusinput.istylusasyncplugin(v=vs.100).aspx)接口。 随后将自定义插件添加到插件的集合[Microsoft.StylusInput.RealTimeStylus](https://msdn.microsoft.com/library/microsoft.stylusinput.realtimestylus(v=vs.100).aspx)。 有关此对象模型的详细信息，请参阅[StylusInput Api 的体系结构](https://docs.microsoft.com/zh-cn/windows/desktop/tablet/architecture-of-the-stylusinput-apis)。

上WPF平台[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)类公开一系列插件，在设计上与类似[Microsoft.StylusInput.RealTimeStylus](https://msdn.microsoft.com/library/microsoft.stylusinput.realtimestylus(v=vs.100).aspx)。 若要截获笔数据，创建继承自类[StylusPlugIn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugin)并向其中添加对象[StylusPlugIns](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.stylusplugins)的集合[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)。 有关这种交互的详细信息，请参阅[截获触笔输入](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/intercepting-input-from-the-stylus)。

在所有平台上，线程池接收墨迹数据通过触笔事件，并将其发送到应用程序线程。 关于线程处理 COM 和 Windows 平台上的详细信息，请参阅[线程处理注意事项 StylusInput Api](https://docs.microsoft.com/zh-cn/windows/desktop/tablet/threading-considerations-for-the-stylusinput-apis)。 有关在 Windows 演示文稿软件线程处理的详细信息，请参阅[墨迹线程模型](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/the-ink-threading-model)。

下图比较了接收在笔线程池上的笔数据的类的对象模型。

![StylusPlugin 模型 WPF 与 Winforms 的关系图。](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/ink-stylusplugins.png)

## [Advanced Ink Handling](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/advanced-ink-handling)

WPF附带[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)，，是您可以将其放在应用程序以立即开始收集和显示墨迹元素。 但是，如果[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)控件不提供足够精细的控制级别，你可以通过自定义你自己的墨迹集合和墨迹呈现类使用保留在较高级别控制[System.Windows.Input.StylusPlugIns](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins)。

[System.Windows.Input.StylusPlugIns](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins)类提供用于通过实现低级别的控制的机制[Stylus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylus)输入和动态呈现墨迹。[StylusPlugIn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugin)类提供机制来实现自定义行为，并将其应用到来自触笔设备以获得最佳性能的数据的流。[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)，一个专用[StylusPlugIn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugin)，允许你自定义动态呈现墨迹数据进行实时这意味着，[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)绘制数字墨迹立即作为[StylusPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspoint)生成数据，因此它显示为"流"从触笔设备。

[自定义呈现墨迹](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/custom-rendering-ink)
[截获触笔输入](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/intercepting-input-from-the-stylus)
[创建墨迹输入控件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/creating-an-ink-input-control)
[墨迹线程模型](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/the-ink-threading-model)

### [Custom Rendering Ink](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/custom-rendering-ink)

[DrawingAttributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke.drawingattributes)笔划的属性，可指定笔划，其大小、 颜色和形状，如的外观，但可能有些时候你想要自定义外观更[DrawingAttributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke.drawingattributes)允许。 建议通过使用喷笔、油画和多种其他效果呈现外观，从而自定义墨迹的外观。Windows Presentation Foundation (WPF) 允许您为自定义通过实现自定义呈现墨迹[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)和[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke)对象。

本主题包含以下小节：

- [体系结构](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/custom-rendering-ink#Architecture)
- [实现动态呈现器](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/custom-rendering-ink#ImplementingADynamicRenderer)
- [实现自定义笔划](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/custom-rendering-ink#ImplementingCustomStrokes)
- [实现自定义 InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/custom-rendering-ink#ImplementingACustomInkCanvas)
- [结束语](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/custom-rendering-ink#Conclusion)

#### 体系结构

墨迹呈现会出现两次：用户将墨迹写入墨迹书写表面时，以及将笔划添加到启用了墨迹的表面之后。[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)当用户移动触笔数字化仪上, 呈现墨迹和[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke)添加到元素后呈现自身。

动态呈现墨迹时需要实现三个类。

1. **DynamicRenderer**:实现从 [DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer) 派生的类。 此类是一个专用[StylusPlugIn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugin)的形式对其绘制呈现笔划。 [DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)上执行呈现一个单独的线程，因此墨迹书写表面显示为收集手写内容，即使应用程序用户界面 (UI) 线程被阻止。 有关线程模型的详细信息，请参阅[墨迹线程模型](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/the-ink-threading-model)。 若要自定义动态呈现笔划，请重写[OnDraw](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer.ondraw)方法。
2. **笔划**:实现从 [Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke) 派生的类。 此类负责的静态呈现[StylusPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspoint)数据转换为后[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke)对象。 重写[DrawCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke.drawcore)方法，以确保静态呈现笔划的是与动态呈现一致。
3. **在 InkCanvas:** 实现从 [InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas) 派生的类。 分配的自定义[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)到[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas.dynamicrenderer)属性。 重写[OnStrokeCollected](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas.onstrokecollected)方法并添加到自定义笔划[Strokes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas.strokes)属性。 这样可以确保墨迹外观一致。



#### 实现动态呈现器

尽管[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)类是标准的一部分WPF，若要执行更专业的呈现，则必须创建派生的自定义动态呈现器[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)并重写[OnDraw](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer.ondraw)方法。

下面的示例演示自定义[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)绘制带有线性渐变画笔效果的墨迹。

C#复制

```csharp
using System;
using System.Windows.Media;
using System.Windows;
using System.Windows.Input.StylusPlugIns;
using System.Windows.Input;
using System.Windows.Ink;
```

C#复制

```csharp
// A StylusPlugin that renders ink with a linear gradient brush effect.
class CustomDynamicRenderer : DynamicRenderer
{
    [ThreadStatic]
    static private Brush brush = null;

    [ThreadStatic]
    static private Pen pen = null;

    private Point prevPoint;

    protected override void OnStylusDown(RawStylusInput rawStylusInput)
    {
        // Allocate memory to store the previous point to draw from.
        prevPoint = new Point(double.NegativeInfinity, double.NegativeInfinity);
        base.OnStylusDown(rawStylusInput);
    }

    protected override void OnDraw(DrawingContext drawingContext,
                                   StylusPointCollection stylusPoints,
                                   Geometry geometry, Brush fillBrush)
    {
        // Create a new Brush, if necessary.
        if (brush == null)
        {
            brush = new LinearGradientBrush(Colors.Red, Colors.Blue, 20d);
        }

        // Create a new Pen, if necessary.
        if (pen == null)
        {
            pen = new Pen(brush, 2d);
        }

        // Draw linear gradient ellipses between 
        // all the StylusPoints that have come in.
        for (int i = 0; i < stylusPoints.Count; i++)
        {
            Point pt = (Point)stylusPoints[i];
            Vector v = Point.Subtract(prevPoint, pt);

            // Only draw if we are at least 4 units away 
            // from the end of the last ellipse. Otherwise, 
            // we're just redrawing and wasting cycles.
            if (v.Length > 4)
            {
                // Set the thickness of the stroke based 
                // on how hard the user pressed.
                double radius = stylusPoints[i].PressureFactor * 10d;
                drawingContext.DrawEllipse(brush, pen, pt, radius, radius);
                prevPoint = pt;
            }
        }
    }
}
```



#### 实现自定义笔划

实现从 [Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke) 派生的类。 此类负责呈现[StylusPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspoint)数据转换为后[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke)对象。 重写[DrawCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke.drawcore)类来进行实际绘制。

笔划类还可以通过使用存储自定义数据[AddPropertyData](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke.addpropertydata)方法。 此数据持续存在时会与笔划数据一起存储。

[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke)类还可以执行命中测试。 您还可以实现你自己的命中测试算法通过重写[HitTest](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke.hittest)中当前类的方法。

以下C#的代码演示了一个自定义[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke)呈现类的[StylusPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspoint)为三维笔划的数据。

C#复制

```csharp
using System;
using System.Windows.Media;
using System.Windows;
using System.Windows.Input.StylusPlugIns;
using System.Windows.Input;
using System.Windows.Ink;
```

C#复制

```csharp
// A class for rendering custom strokes
class CustomStroke : Stroke
{
    Brush brush;
    Pen pen;

    public CustomStroke(StylusPointCollection stylusPoints)
        : base(stylusPoints)
    {
        // Create the Brush and Pen used for drawing.
        brush = new LinearGradientBrush(Colors.Red, Colors.Blue, 20d);
        pen = new Pen(brush, 2d);
    }

    protected override void DrawCore(DrawingContext drawingContext, 
                                     DrawingAttributes drawingAttributes)
    {
        // Allocate memory to store the previous point to draw from.
        Point prevPoint = new Point(double.NegativeInfinity, 
                                    double.NegativeInfinity);

        // Draw linear gradient ellipses between 
        // all the StylusPoints in the Stroke.
        for (int i = 0; i < this.StylusPoints.Count; i++)
        {
            Point pt = (Point)this.StylusPoints[i];
            Vector v = Point.Subtract(prevPoint, pt);

            // Only draw if we are at least 4 units away 
            // from the end of the last ellipse. Otherwise, 
            // we're just redrawing and wasting cycles.
            if (v.Length > 4)
            {
                // Set the thickness of the stroke 
                // based on how hard the user pressed.
                double radius = this.StylusPoints[i].PressureFactor * 10d;
                drawingContext.DrawEllipse(brush, pen, pt, radius, radius);
                prevPoint = pt;
            }
        }
    }
}
```



#### 实现自定义 InkCanvas

使用你的自定义的最简单办法[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)笔划是实现派生自的类和[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)并使用这些类。 [InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)具有[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas.dynamicrenderer)指定当用户绘制笔划的呈现方式的属性。

自定义上呈现笔画[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)执行以下操作：

- 创建派生一个类[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)。
- 分配你的自定义[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)到[InkCanvas.DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas.dynamicrenderer)属性。
- 重写 [OnStrokeCollected](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas.onstrokecollected) 方法。 使用此方法时，请删除之前添加到 InkCanvas 的原始笔划。 然后创建一个自定义笔划，将其添加到[Strokes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas.strokes)属性，并调用具有一个新的基本类[InkCanvasStrokeCollectedEventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvasstrokecollectedeventargs)，其中包含自定义笔划。

以下C#的代码演示了一个自定义[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)类，该类使用自定义[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)，并收集自定义笔划。

C#复制

```csharp
public class CustomRenderingInkCanvas : InkCanvas
{
    CustomDynamicRenderer customRenderer = new CustomDynamicRenderer();

    public CustomRenderingInkCanvas() : base()
    {
        // Use the custom dynamic renderer on the
        // custom InkCanvas.
        this.DynamicRenderer = customRenderer;
    }

    protected override void OnStrokeCollected(InkCanvasStrokeCollectedEventArgs e)
    {
        // Remove the original stroke and add a custom stroke.
        this.Strokes.Remove(e.Stroke);
        CustomStroke customStroke = new CustomStroke(e.Stroke.StylusPoints);
        this.Strokes.Add(customStroke);

        // Pass the custom stroke to base class' OnStrokeCollected method.
        InkCanvasStrokeCollectedEventArgs args = 
            new InkCanvasStrokeCollectedEventArgs(customStroke);
        base.OnStrokeCollected(args);

    }

}
```

[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)可以有多个[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)。 可以添加多个[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)对象添加到[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)通过将它们添加到[StylusPlugIns](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.stylusplugins)属性。



#### 结束语

您可以通过派生您自己自定义墨迹的外观[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)， [Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke)，和[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)类。 将这些类结合使用可以确保用户绘制笔划时和笔划被收集后的笔划外观保持一致。

### [Intercepting Input from the Stylus](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/intercepting-input-from-the-stylus)

[System.Windows.Input.StylusPlugIns](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins)体系结构提供了用于通过实现低级别控制的机制[Stylus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylus)输入和数字墨迹创建[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke)对象。 [StylusPlugIn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugin)类提供了一种机制，以实现自定义行为，并将其应用到从触笔设备以获得最佳性能的数据的流。

本主题包含以下小节：

- [体系结构](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/intercepting-input-from-the-stylus#Architecture)
- [实现触笔插件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/intercepting-input-from-the-stylus#ImplementingStylusPlugins)
- [将插件添加到 InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/intercepting-input-from-the-stylus#AddingYourPluginToAnInkCanvas)
- [结束语](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/intercepting-input-from-the-stylus#Conclusion)

#### 体系结构

[StylusPlugIn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugin)的演进[StylusInput](https://go.microsoft.com/fwlink/?LinkId=50753&clcid=0x409)中所述的 Api[访问和操作笔输入](https://go.microsoft.com/fwlink/?LinkId=50752&clcid=0x409)中[Microsoft Windows XP Tablet PC Edition 软件Kit 1.7](https://go.microsoft.com/fwlink/?linkid=11782&clcid=0x409)。

每个[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)已[StylusPlugIns](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.stylusplugins)是属性[StylusPlugInCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugincollection)。 您可以添加[StylusPlugIn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugin)的元素[StylusPlugIns](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.stylusplugins)属性来操作[StylusPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspoint)生成作为它的数据。 [StylusPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspoint) 数据包含的所有系统数字化器，包括支持的属性[X](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspoint.x)并[Y](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspoint.y)点数据，以及[PressureFactor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspoint.pressurefactor)数据。

你[StylusPlugIn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugin)对象插入到流中的数据来自直接[Stylus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylus)设备添加时[StylusPlugIn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugin)到[StylusPlugIns](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.stylusplugins)属性。 管理单元添加到中的顺序[StylusPlugIns](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.stylusplugins)集合的顺序指定将收到[StylusPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspoint)数据。 例如，如果您添加筛选器插件，将输入限制为特定的区域，以及如何将写入时识别的笔势的插件，识别的笔势插件将接收已筛选[StylusPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspoint)数据。

#### 实现触笔插件

若要将插件实现，派生的类从[StylusPlugIn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugin)。 此类是应用的 o 数据的流，因为它来自[Stylus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylus)。 在此类可以通过修改的值[StylusPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspoint)数据。

 注意

如果[StylusPlugIn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugin)引发或导致异常，应用程序将关闭。 您应该全面测试使用的控件[StylusPlugIn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugin)并且只使用一个控件，如果您确信[StylusPlugIn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugin)不会引发异常。

下面的示例演示一个插件，通过修改限制触笔输入[X](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspoint.x)并[Y](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspoint.y)中的值[StylusPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspoint)作为它的数据来自[Stylus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylus)设备。

C#复制

```csharp
using System;
using System.Windows.Media;
using System.Windows;
using System.Windows.Input.StylusPlugIns;
using System.Windows.Input;
using System.Windows.Ink;
```

C#复制

```csharp
// A StylusPlugin that restricts the input area.
class FilterPlugin : StylusPlugIn
{
    protected override void OnStylusDown(RawStylusInput rawStylusInput)
    {
        // Call the base class before modifying the data.
        base.OnStylusDown(rawStylusInput);

        // Restrict the stylus input.
        Filter(rawStylusInput);
    }

    protected override void OnStylusMove(RawStylusInput rawStylusInput)
    {
        // Call the base class before modifying the data.
        base.OnStylusMove(rawStylusInput);

        // Restrict the stylus input.
        Filter(rawStylusInput);
    }

    protected override void OnStylusUp(RawStylusInput rawStylusInput)
    {
        // Call the base class before modifying the data.
        base.OnStylusUp(rawStylusInput);

        // Restrict the stylus input
        Filter(rawStylusInput);
    }

    private void Filter(RawStylusInput rawStylusInput)
    {
        // Get the StylusPoints that have come in.
        StylusPointCollection stylusPoints = rawStylusInput.GetStylusPoints();

        // Modify the (X,Y) data to move the points 
        // inside the acceptable input area, if necessary.
        for (int i = 0; i < stylusPoints.Count; i++)
        {
            StylusPoint sp = stylusPoints[i];
            if (sp.X < 50) sp.X = 50;
            if (sp.X > 250) sp.X = 250;
            if (sp.Y < 50) sp.Y = 50;
            if (sp.Y > 250) sp.Y = 250;
            stylusPoints[i] = sp;
        }

        // Copy the modified StylusPoints back to the RawStylusInput.
        rawStylusInput.SetStylusPoints(stylusPoints);
    }
}
```

#### 将插件添加到 InkCanvas

若要使用自定义插件的最简单方法是实现从 InkCanvas 派生而来的类并将其添加到[StylusPlugIns](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.stylusplugins)属性。

下面的示例演示自定义[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)对墨迹进行筛选。

C#复制

```csharp
public class FilterInkCanvas : InkCanvas
{
    FilterPlugin filter = new FilterPlugin();

    public FilterInkCanvas()
        : base()
    {
        this.StylusPlugIns.Add(filter);
    }
}
```

如果添加`FilterInkCanvas`到应用程序并运行它，你会注意到在用户完成一个笔画后手写内容并不局限于之前的区域。 这是因为[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)已[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas.dynamicrenderer)属性，即[StylusPlugIn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugin)已经是成员的和[StylusPlugIns](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.stylusplugins)集合。 自定义[StylusPlugIn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugin)你添加到[StylusPlugIns](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.stylusplugins)集合接收[StylusPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspoint)之后，数据[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)接收数据。 因此，[StylusPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspoint)数据在用户抬起笔结束笔画后不会直到筛选。 若要筛选用户将其绘制手写内容，必须插入`FilterPlugin`之前[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)。

下面的 C# 代码演示一个自定义[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)是绘制筛选手写内容。

C#复制

```csharp
public class DynamicallyFilteredInkCanvas : InkCanvas
{
    FilterPlugin filter = new FilterPlugin();

    public DynamicallyFilteredInkCanvas()
        : base()
    {
        int dynamicRenderIndex = 
            this.StylusPlugIns.IndexOf(this.DynamicRenderer);
        
        this.StylusPlugIns.Insert(dynamicRenderIndex, filter);

    }

}
```

#### 结束语

通过派生您自己[StylusPlugIn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugin)类并将它们到插入[StylusPlugInCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugincollection)集合，可以极大地提高你数字墨迹的行为。你有权[StylusPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspoint)生成数据时，您可以自定义[Stylus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylus)输入。 因为此类低级别访问[StylusPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspoint)数据，可以为你的应用程序实现墨迹收集和呈现具有优化性能。

### [Creating an Ink Input Control](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/creating-an-ink-input-control)

您可以创建自定义控件的动态和静态呈现墨迹。 这就是，根据用户绘制笔划，从而导致出现"流"从 tablet 笔，并在其后显示墨迹添加到该控件，通过触笔从剪贴板粘贴数据或从文件加载的手写内容呈现墨迹。 若要动态呈现墨迹，控件必须使用[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)。 若要以静态方式呈现墨迹，您必须重写触笔事件方法 ([OnStylusDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.onstylusdown)，[OnStylusMove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.onstylusmove)，并[OnStylusUp](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.onstylusup)) 来收集[StylusPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspoint)数据，创建的笔画，并将其添加到[InkPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkpresenter)（它将呈现在控件上的墨迹）。

本主题包含以下小节：

- [如何：收集触笔接触点数据并创建墨迹笔画](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/creating-an-ink-input-control#CollectingStylusPointDataAndCreatingInkStrokes)
- [如何：使控件能够接受从鼠标输入](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/creating-an-ink-input-control#EnablingYourControlToAcceptInputTromTheMouse)
- [将它放在一起](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/creating-an-ink-input-control#PuttingItTogether)
- [使用其他插件和 DynamicRenderers](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/creating-an-ink-input-control#UsingAdditionalPluginsAndDynamicRenderers)
- [结束语](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/creating-an-ink-input-control#AdvancedInkHandling_Conclusion)

#### 如何：收集触笔接触点数据并创建墨迹笔画

若要创建的控件，可收集和管理墨迹笔画执行以下步骤：

1. 从派生类[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)或其中一个类派生自[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)，如[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)。

   C#复制

   ```csharp
   using System;
   using System.Windows.Ink;
   using System.Windows.Input;
   using System.Windows.Input.StylusPlugIns;
   using System.Windows.Controls;
   using System.Windows;
   ```

   C#复制

   ```csharp
   class InkControl : Label
   {
   ```

   C#复制

   ```csharp
   }
   ```

2. 添加[InkPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkpresenter)向类和组[Content](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.content)属性设置为新[InkPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkpresenter)。

   C#复制

   ```csharp
   InkPresenter ip;
   
   public InkControl()
   {
       // Add an InkPresenter for drawing.
       ip = new InkPresenter();
       this.Content = ip;
   }
   ```

3. 附加[RootVisual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer.rootvisual)的[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)到[InkPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkpresenter)通过调用[AttachVisuals](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkpresenter.attachvisuals)方法，并添加[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)到[StylusPlugIns](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.stylusplugins)集合。 这允许[InkPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkpresenter)触笔接触点数据收集由控件显示墨迹。

   C#复制

   ```csharp
   public InkControl()
   {
   ```

   C#复制

   ```csharp
       // Add a dynamic renderer that 
       // draws ink as it "flows" from the stylus.
       dr = new DynamicRenderer();
       ip.AttachVisuals(dr.RootVisual, dr.DrawingAttributes);
       this.StylusPlugIns.Add(dr);
   
   }
   ```

4. 重写 [OnStylusDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.onstylusdown) 方法。 在此方法，来获取调用触笔[Capture](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylus.capture)。 通过捕获触笔，控件将继续接收[StylusMove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.stylusmove)和[StylusUp](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.stylusup)事件，即使在触笔离开控件的边界。 这不是严格必需的但几乎总是需要进行很好的用户体验。 创建一个新[StylusPointCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspointcollection)收集[StylusPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspoint)数据。 最后，添加一组初始[StylusPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspoint)数据到[StylusPointCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspointcollection)。

   C#复制

   ```csharp
   protected override void OnStylusDown(StylusDownEventArgs e)
   {
       // Capture the stylus so all stylus input is routed to this control.
       Stylus.Capture(this);
   
       // Allocate memory for the StylusPointsCollection and
       // add the StylusPoints that have come in so far.
       stylusPoints = new StylusPointCollection();
       StylusPointCollection eventPoints = 
           e.GetStylusPoints(this, stylusPoints.Description);
   
       stylusPoints.Add(eventPoints);
   
   }
   ```

5. 重写[OnStylusMove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.onstylusmove)方法并添加[StylusPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspoint)数据到[StylusPointCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspointcollection)前面创建的对象。

   C#复制

   ```csharp
   protected override void OnStylusMove(StylusEventArgs e)
   {
       if (stylusPoints == null)
       {
           return;
       }
   
       // Add the StylusPoints that have come in since the 
       // last call to OnStylusMove.
       StylusPointCollection newStylusPoints = 
           e.GetStylusPoints(this, stylusPoints.Description);
       stylusPoints.Add(newStylusPoints);
   }
   ```

6. 重写[OnStylusUp](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.onstylusup)方法创建一个新[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke)与[StylusPointCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspointcollection)数据。 添加新[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke)创建到[Strokes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkpresenter.strokes)的集合[InkPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkpresenter)并释放触笔捕获。

   C#复制

   ```csharp
   protected override void OnStylusUp(StylusEventArgs e)
   {
       if (stylusPoints == null)
       {
           return;
       }
   
       // Add the StylusPoints that have come in since the 
       // last call to OnStylusMove.
       StylusPointCollection newStylusPoints = 
           e.GetStylusPoints(this, stylusPoints.Description);
       stylusPoints.Add(newStylusPoints);
   
       // Create a new stroke from all the StylusPoints since OnStylusDown.
       Stroke stroke = new Stroke(stylusPoints);
   
       // Add the new stroke to the Strokes collection of the InkPresenter.
       ip.Strokes.Add(stroke);
   
       // Clear the StylusPointsCollection.
       stylusPoints = null;
   
       // Release stylus capture.
       Stylus.Capture(null);
   }
   ```

#### 如何：使控件能够接受从鼠标输入

如果将前面的控件添加到你的应用程序、 运行它，并使用鼠标输入设备，你会注意到笔画不会保留。 若要持久保存的笔画鼠标用作输入的设备时执行以下步骤：

1. 重写[OnMouseLeftButtonDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.onmouseleftbuttondown)并创建一个新[StylusPointCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspointcollection)在事件发生时获取鼠标的位置，并创建[StylusPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspoint)使用点数据，并添加[StylusPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspoint)到[StylusPointCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspointcollection)。

   C#复制

   ```csharp
   protected override void OnMouseLeftButtonDown(MouseButtonEventArgs e)
   {
   
       base.OnMouseLeftButtonDown(e);
   
       // If a stylus generated this event, return.
       if (e.StylusDevice != null)
       {
           return;
       }
   
       // Start collecting the points.
       stylusPoints = new StylusPointCollection();
       Point pt = e.GetPosition(this);
       stylusPoints.Add(new StylusPoint(pt.X, pt.Y));
   
   }
   ```

2. 重写 [OnMouseMove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.onmousemove) 方法。 在事件发生时获取鼠标的位置，并创建[StylusPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspoint)使用点数据。 添加[StylusPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspoint)到[StylusPointCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspointcollection)前面创建的对象。

   C#复制

   ```csharp
   protected override void OnMouseMove(MouseEventArgs e)
   {
   
       base.OnMouseMove(e);
   
       // If a stylus generated this event, return.
       if (e.StylusDevice != null)
       {
           return;
       }
   
       // Don't collect points unless the left mouse button
       // is down.
       if (e.LeftButton == MouseButtonState.Released || 
           stylusPoints == null)
       {
           return;
       }
   
       Point pt = e.GetPosition(this);
       stylusPoints.Add(new StylusPoint(pt.X, pt.Y));
   }
   ```

3. 重写 [OnMouseLeftButtonUp](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.onmouseleftbuttonup) 方法。 创建一个新[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke)与[StylusPointCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspointcollection)数据，并添加新[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke)您创建到[Strokes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkpresenter.strokes)的集合[InkPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkpresenter)。

   C#复制

   ```csharp
   protected override void OnMouseLeftButtonUp(MouseButtonEventArgs e)
   {
   
       base.OnMouseLeftButtonUp(e);
   
       // If a stylus generated this event, return.
       if (e.StylusDevice != null)
       {
           return;
       }
   
       if (stylusPoints == null)
       {
           return;
       }
   
       Point pt = e.GetPosition(this);
       stylusPoints.Add(new StylusPoint(pt.X, pt.Y));
   
       // Create a stroke and add it to the InkPresenter.
       Stroke stroke = new Stroke(stylusPoints);
       stroke.DrawingAttributes = dr.DrawingAttributes;
       ip.Strokes.Add(stroke);
   
       stylusPoints = null;
   
   }
   ```

#### 将它放在一起

下面的示例是当用户使用鼠标或触笔收集墨迹的自定义控件。

C#复制

```csharp
using System;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Input.StylusPlugIns;
using System.Windows.Controls;
using System.Windows;
```

C#复制

```csharp
// A control for managing ink input
class InkControl : Label
{
    InkPresenter ip;
    DynamicRenderer dr;

    // The StylusPointsCollection that gathers points 
    // before Stroke from is created.
    StylusPointCollection stylusPoints = null;
    
    public InkControl()
    {
        // Add an InkPresenter for drawing.
        ip = new InkPresenter();
        this.Content = ip;

        // Add a dynamic renderer that 
        // draws ink as it "flows" from the stylus.
        dr = new DynamicRenderer();
        ip.AttachVisuals(dr.RootVisual, dr.DrawingAttributes);
        this.StylusPlugIns.Add(dr);

    }

    static InkControl()
    {
        // Allow ink to be drawn only within the bounds of the control.
        Type owner = typeof(InkControl);
        ClipToBoundsProperty.OverrideMetadata(owner,
            new FrameworkPropertyMetadata(true));
    }

    protected override void OnStylusDown(StylusDownEventArgs e)
    {
        // Capture the stylus so all stylus input is routed to this control.
        Stylus.Capture(this);

        // Allocate memory for the StylusPointsCollection and
        // add the StylusPoints that have come in so far.
        stylusPoints = new StylusPointCollection();
        StylusPointCollection eventPoints = 
            e.GetStylusPoints(this, stylusPoints.Description);

        stylusPoints.Add(eventPoints);

    }

    protected override void OnStylusMove(StylusEventArgs e)
    {
        if (stylusPoints == null)
        {
            return;
        }

        // Add the StylusPoints that have come in since the 
        // last call to OnStylusMove.
        StylusPointCollection newStylusPoints = 
            e.GetStylusPoints(this, stylusPoints.Description);
        stylusPoints.Add(newStylusPoints);
    }

    protected override void OnStylusUp(StylusEventArgs e)
    {
        if (stylusPoints == null)
        {
            return;
        }

        // Add the StylusPoints that have come in since the 
        // last call to OnStylusMove.
        StylusPointCollection newStylusPoints = 
            e.GetStylusPoints(this, stylusPoints.Description);
        stylusPoints.Add(newStylusPoints);

        // Create a new stroke from all the StylusPoints since OnStylusDown.
        Stroke stroke = new Stroke(stylusPoints);

        // Add the new stroke to the Strokes collection of the InkPresenter.
        ip.Strokes.Add(stroke);

        // Clear the StylusPointsCollection.
        stylusPoints = null;

        // Release stylus capture.
        Stylus.Capture(null);
    }

    protected override void OnMouseLeftButtonDown(MouseButtonEventArgs e)
    {

        base.OnMouseLeftButtonDown(e);

        // If a stylus generated this event, return.
        if (e.StylusDevice != null)
        {
            return;
        }

        // Start collecting the points.
        stylusPoints = new StylusPointCollection();
        Point pt = e.GetPosition(this);
        stylusPoints.Add(new StylusPoint(pt.X, pt.Y));

    }

    protected override void OnMouseMove(MouseEventArgs e)
    {

        base.OnMouseMove(e);

        // If a stylus generated this event, return.
        if (e.StylusDevice != null)
        {
            return;
        }

        // Don't collect points unless the left mouse button
        // is down.
        if (e.LeftButton == MouseButtonState.Released || 
            stylusPoints == null)
        {
            return;
        }

        Point pt = e.GetPosition(this);
        stylusPoints.Add(new StylusPoint(pt.X, pt.Y));
    }

    protected override void OnMouseLeftButtonUp(MouseButtonEventArgs e)
    {

        base.OnMouseLeftButtonUp(e);

        // If a stylus generated this event, return.
        if (e.StylusDevice != null)
        {
            return;
        }

        if (stylusPoints == null)
        {
            return;
        }

        Point pt = e.GetPosition(this);
        stylusPoints.Add(new StylusPoint(pt.X, pt.Y));

        // Create a stroke and add it to the InkPresenter.
        Stroke stroke = new Stroke(stylusPoints);
        stroke.DrawingAttributes = dr.DrawingAttributes;
        ip.Strokes.Add(stroke);

        stylusPoints = null;

    }
}
```

#### 使用其他插件和 DynamicRenderers

在 InkCanvas，如自定义控件可以具有自定义[StylusPlugIn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugin)和其他[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)对象。 将它们添加到[StylusPlugIns](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.stylusplugins)集合。 顺序[StylusPlugIn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugin)中的对象[StylusPlugInCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugincollection)呈现时，会影响墨迹的外观。 假设您有[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)称为`dynamicRenderer`和自定义[StylusPlugIn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugin)调用`translatePlugin`的偏移量从 tablet 笔墨迹。如果`translatePlugin`是第一个[StylusPlugIn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugin)中[StylusPlugInCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugincollection)，和`dynamicRenderer`是第二，当用户移动笔将偏移"流"的墨迹。 如果`dynamicRenderer`第一次，和`translatePlugin`是第二个，墨迹将不会在用户提起笔之前偏移。

#### 结束语

可以创建一个控件，可收集和通过重写的触笔事件方法呈现墨迹。 通过创建自己的控件，派生您自己[StylusPlugIn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugin)类，并将它们插入到[StylusPlugInCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugincollection)，可以实现与数字墨迹想象几乎任何行为。 你有权[StylusPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspoint)生成数据时，您可以自定义[Stylus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylus)输入，并根据你的应用程序在屏幕上呈现它。 因为此类低级别访问[StylusPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.styluspoint)数据，可以实现墨迹收集，并使其具有优化性能的应用程序。

### [The Ink Threading Model](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/the-ink-threading-model)

墨迹在 Tablet PC 上的优势之一是，其外观很像编写使用普通的笔和纸。 若要实现此目的，触笔收集以高得多的速度比鼠标将墨迹呈现为用户写入的输入的数据。 应用程序的用户界面 (UI) 线程不收集钢笔数据和呈现墨迹满足需求，因为它可能被阻止。 为了解决此问题，问题WPF应用程序时用户会编写墨迹使用两个其他线程。

以下列表描述参与收集和呈现数字墨迹线程：

- 笔线程-将触笔输入的线程。 （事实上，这是一个线程池，但本主题将其称为笔线程。）
- 应用程序用户界面线程的控制应用程序的用户界面的线程。
- 动态呈现线程-呈现时用户墨迹线程绘制笔画。 窗口 Presentation Foundation 中所述，动态呈现线程是不同于呈现应用程序的其他 UI 元素的线程[线程处理模型](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/threading-model)。

墨迹模型都是相同是否应用程序使用[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)或自定义控件类似于中的一个[创建墨迹输入控件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/creating-an-ink-input-control)。 虽然本主题讨论方面的线程处理[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)，创建自定义控件时，将应用相同的概念。

#### 线程处理概述

下图阐释了线程处理模型，当用户绘制笔画时：

![绘制笔画时的线程处理模型。] (../../../../docs/framework/wpf/advanced/media/inkthreading-drawingink.png "InkThreading_DrawingInk")

1. 用户绘制笔画时发生的操作
   1. 当用户绘制笔画时，触笔接触点参与笔线程。 触笔插件，包括[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)，接受笔线程上的触笔点并有机会修改在之前将其[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)接收它们。
   2. [DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)呈现动态呈现线程上的触笔点。 在上一步在同一时间发生此异常。
   3. [InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)接收 UI 线程上的触笔点。
2. 用户结束笔画后发生的操作
   1. 当用户完成绘制笔画，[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)创建[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke)对象，并将其添加到[InkPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkpresenter)，这样可以静态呈现。
   2. UI 线程警报[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)静态呈现描边，因此[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)中移除的笔划的其可视表示形式。

#### 墨迹集合和触笔插件

每个[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)具有[StylusPlugInCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugincollection)。 [StylusPlugIn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugin)中的对象[StylusPlugInCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugincollection)接收并且可以修改笔线程上的触笔点。 [StylusPlugIn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugin)对象接收根据它们在中顺序的触笔点[StylusPlugInCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugincollection)。

下图演示了一个假想的场景其中[StylusPlugIns](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.stylusplugins)集合[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)包含`stylusPlugin1`、 [DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)，和`stylusPlugin2`按顺序。

![顺序触笔插件影响输出。] (../../../../docs/framework/wpf/advanced/media/inkthreading-pluginorder.png "InkThreading_PluginOrder")

在上图中，以下行为将发生：

1. `StylusPlugin1` 修改的 x 值和 y。
2. [DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer) 接收的已修改的触笔点并将它们呈现在动态呈现线程。
3. `StylusPlugin2` 接收的已修改的触笔点并进一步修改的 x 值和 y。
4. 应用程序收集触笔接触点，以及当用户完成描边，静态呈现笔画。

假设`stylusPlugin1`将触笔接触点限制为矩形和`stylusPlugin2`将转换到右的触笔点。 在前面的方案中，[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)接收的受限制的触笔点，而非已翻译的触笔点。 当用户书写笔画时，描边呈现的矩形的边界内，但是不会对笔画用户提起笔之前要转换。

##### 使用触笔插件在 UI 线程上执行操作

由于无法对笔线程执行准确的命中测试，某些元素偶尔可能会收到适用于其他元素的触笔输入。 如果你需要确保在执行操作之前已正确路由输入，订阅并执行中的操作[OnStylusDownProcessed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugin.onstylusdownprocessed)， [OnStylusMoveProcessed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugin.onstylusmoveprocessed)，或[OnStylusUpProcessed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugin.onstylusupprocessed)方法。 在执行准确的命中测试后，将通过应用程序线程中调用这些方法。 若要订阅对这些方法，调用[NotifyWhenProcessed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.rawstylusinput.notifywhenprocessed)的方法中，在钢笔线程上发生的方法。

下图说明了笔线程和 UI 线程方面的触笔事件之间的关系[StylusPlugIn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.stylusplugin)。

![墨迹线程处理模型(UI 和 Pen)](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/inkthreading-plugincallbacks.png)

#### 呈现墨迹

用户绘制笔画，如[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)因此墨迹显示为"流"从笔即使 UI 线程忙碌呈现在单独线程上的墨迹。[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)动态呈现线程上生成可视化树，因为它收集触笔接触点。 当用户完成描边，[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)要求应用程序执行下一次呈现时收到通知。 应用程序完成下一步的呈现处理过程后,[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)清理其可视化树。 下图说明了此过程。

![墨迹线程处理关系图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/inkthreading-visualtree.png)

1. 用户开始描边。
   1. [DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)创建的可视化树。
2. 用户绘制笔画。
   1. [DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)生成的可视化树。
3. 用户结束描边。
   1. [InkPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkpresenter)笔画添加到其可视化树。
   2. 媒体集成层 (MIL) 静态呈现笔画。
   3. [DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)清理视觉对象。

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/digital-ink-how-to-topics)

[从自定义控件选择墨迹](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-select-ink-from-a-custom-control)
[向墨迹数据添加自定义数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-add-custom-data-to-ink-data)
[清除自定义控件上的墨迹](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-erase-ink-on-a-custom-control)
[识别应用程序笔势](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-recognize-application-gestures)
[拖放墨迹](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-drag-and-drop-ink)
[将数据绑定到 InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-data-bind-to-an-inkcanvas)
[通过分析提示来分析墨迹](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-analyze-ink-with-analysis-hints)
[旋转墨迹](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-rotate-ink)
[禁用用于 WPF 应用程序的 RealTimeStylus](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/disable-the-realtimestylus-for-wpf-applications)

### [Select Ink from a Custom Control](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-select-ink-from-a-custom-control)

通过添加[IncrementalLassoHitTester](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.incrementallassohittester)到自定义控件，您可以使控件，以便用户可以选择使用套索工具，方式类似于墨迹[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)选择使用套索墨迹。

此示例假定你熟悉创建手写功能的自定义控件。 若要创建接受墨迹输入的自定义控件，请参阅[创建墨迹输入控件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/creating-an-ink-input-control)。

#### 示例

当用户绘制套索[IncrementalLassoHitTester](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.incrementallassohittester)预测哪些笔画将套索路径边界内，在用户完成套索后。 确定要套索路径边界内的笔画可以选中认为。 选定的笔画也可能会变为未选定。 例如，如果用户将反转方向绘制套索时[IncrementalLassoHitTester](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.incrementallassohittester)可能会取消选择一些笔划。

[IncrementalLassoHitTester](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.incrementallassohittester)引发[SelectionChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.incrementallassohittester.selectionchanged)事件，它使自定义控件以响应用户在绘制套索时。 例如，可以更改笔画的外观，当用户选择和取消选择它们。

#### 管理墨迹模式

如果套索出现方式不同于您的控件上的墨迹，它是对用户有所帮助。 若要完成此操作，自定义控件必须跟踪的用户是写入还是选择墨迹。 若要执行此操作的最简单方法是声明一个枚举，其中两个值： 一个用于指示用户正在编写墨迹，另一个用于指示用户正在选择墨迹。

C#复制

```csharp
// Enum that keeps track of whether StrokeCollectionDemo is in ink mode 
// or select mode.
public enum InkMode
{
    Ink, Select
}
```

接下来，添加两个[DrawingAttributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.drawingattributes)到类： 一个用于当用户将墨迹，一个用于当用户选择的墨迹。 在构造函数初始化[DrawingAttributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.drawingattributes)，并将同时附加[AttributeChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.drawingattributes.attributechanged)到同一个事件处理程序的事件。 然后设置[DrawingAttributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer.drawingattributes)的属性[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)墨迹[DrawingAttributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.drawingattributes)。

C#复制

```csharp
DrawingAttributes inkDA;
DrawingAttributes selectDA;
```

C#复制

```csharp
// In the constructor.
// Selection drawing attributes use dark gray ink.
selectDA = new DrawingAttributes();
selectDA.Color = Colors.DarkGray;

// ink drawing attributes use default attributes
inkDA = new DrawingAttributes();
inkDA.Width = 5;
inkDA.Height = 5;

inkDA.AttributeChanged += new PropertyDataChangedEventHandler(DrawingAttributesChanged);
selectDA.AttributeChanged += new PropertyDataChangedEventHandler(DrawingAttributesChanged);
```

添加一个属性，它公开的选择模式。 当用户更改选择模式时，设置[DrawingAttributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer.drawingattributes)的属性[DynamicRenderer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer)到适当[DrawingAttributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.drawingattributes)对象，然后再重新附加[RootVisual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer.rootvisual)属性设置为[InkPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkpresenter)。

C#复制

```csharp
// Property to indicate whether the user is inputting or
// selecting ink.  
public InkMode Mode
{
    get
    {
        return mode;
    }

    set
    {
        mode = value;

        // Set the DrawingAttributes of the DynamicRenderer
        if (mode == InkMode.Ink)
        {
            renderer.DrawingAttributes = inkDA;
        }
        else
        {
            renderer.DrawingAttributes = selectDA;
        }

        // Reattach the visual of the DynamicRenderer to the InkPresenter.
        presenter.DetachVisuals(renderer.RootVisual);
        presenter.AttachVisuals(renderer.RootVisual, renderer.DrawingAttributes);
    }
}
```

公开[DrawingAttributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.drawingattributes)作为属性，以便应用程序可以确定墨迹笔画和选择笔画的外观。

C#复制

```csharp
// Property to allow the user to change the pen's DrawingAttributes.
public DrawingAttributes InkDrawingAttributes
{
    get
    {
        return inkDA;
    }
}

// Property to allow the user to change the Selector'newStroke DrawingAttributes.
public DrawingAttributes SelectDrawingAttributes
{
    get
    {
        return selectDA;
    }
}
```

属性时[DrawingAttributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.drawingattributes)对象的更改，[RootVisual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer.rootvisual)必须重新附加到[InkPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkpresenter)。 中的事件处理程序[AttributeChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.drawingattributes.attributechanged)事件，重新附加[RootVisual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.stylusplugins.dynamicrenderer.rootvisual)到[InkPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkpresenter)。

C#复制

```csharp
void DrawingAttributesChanged(object sender, PropertyDataChangedEventArgs e)
{
    // Reattach the visual of the DynamicRenderer to the InkPresenter 
    // whenever the DrawingAttributes change.
    presenter.DetachVisuals(renderer.RootVisual);
    presenter.AttachVisuals(renderer.RootVisual, renderer.DrawingAttributes);

}
```

#### 使用 IncrementalLassoHitTester

创建和初始化[StrokeCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.strokecollection)，其中包含选定的笔画。

C#复制

```csharp
// StylusPointCollection that collects the stylus points from the stylus events.
StylusPointCollection stylusPoints;
```

当用户开始绘制笔画时，手写内容或套索，请取消选择任何选定的笔画。 然后，如果用户要绘制套索，创建[IncrementalLassoHitTester](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.incrementallassohittester)通过调用[GetIncrementalLassoHitTester](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.strokecollection.getincrementallassohittester)，订阅[SelectionChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.incrementallassohittester.selectionchanged)事件，并调用[AddPoints](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.incrementalhittester.addpoints)。 此代码可以是一个单独的方法，并从调用[OnStylusDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.onstylusdown)和[OnMouseDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.onmousedown)方法。

C#复制

```csharp
private void InitializeHitTester(StylusPointCollection collectedPoints)
{
    // Deselect any selected strokes.
    foreach (Stroke selectedStroke in selectedStrokes)
    {
        selectedStroke.DrawingAttributes.Color = inkDA.Color;
    }
    selectedStrokes.Clear();

    if (mode == InkMode.Select)
    {
        // Remove the previously drawn lasso, if it exists.
        if (lassoPath != null)
        {
            presenter.Strokes.Remove(lassoPath);
            lassoPath = null;
        }

        selectionTester =
            presenter.Strokes.GetIncrementalLassoHitTester(80);
        selectionTester.SelectionChanged += 
            new LassoSelectionChangedEventHandler(selectionTester_SelectionChanged);
        selectionTester.AddPoints(collectedPoints);
    }
}
```

添加到触笔接触点[IncrementalLassoHitTester](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.incrementallassohittester)时用户绘制套索。 调用以下方法从[OnStylusMove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.onstylusmove)， [OnStylusUp](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.onstylusup)， [OnMouseMove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.onmousemove)，和[OnMouseLeftButtonUp](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.onmouseleftbuttonup)方法。

C#复制

```csharp
private void AddPointsToHitTester(StylusPointCollection collectedPoints)
{

    if (mode == InkMode.Select &&
        selectionTester != null && 
        selectionTester.IsValid)
    {
        // When the control is selecting strokes, add the
        // stylus packetList to selectionTester.
        selectionTester.AddPoints(collectedPoints);

    }
}
```

处理[IncrementalLassoHitTester.SelectionChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.incrementallassohittester.selectionchanged)事件，当用户选择和取消选择笔画时进行响应。[LassoSelectionChangedEventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.lassoselectionchangedeventargs)类具有[SelectedStrokes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.lassoselectionchangedeventargs.selectedstrokes)和[DeselectedStrokes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.lassoselectionchangedeventargs.deselectedstrokes)已选中和未选定的分别获取笔画的属性。

C#复制

```csharp
void selectionTester_SelectionChanged(object sender,
    LassoSelectionChangedEventArgs args)
{
    // Change the color of all selected strokes to red.
    foreach (Stroke selectedStroke in args.SelectedStrokes)
    {
        selectedStroke.DrawingAttributes.Color = Colors.Red;
        selectedStrokes.Add(selectedStroke);

    }

    // Change the color of all unselected strokes to 
    // their original color.
    foreach (Stroke unselectedStroke in args.DeselectedStrokes)
    {
        unselectedStroke.DrawingAttributes.Color = inkDA.Color;
        selectedStrokes.Remove(unselectedStroke);
    }
}
```

在用户完成绘制套索，取消订阅[SelectionChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.incrementallassohittester.selectionchanged)事件，并调用[EndHitTesting](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.incrementalhittester.endhittesting)。

C#复制

```csharp
if (mode == InkMode.Select && lassoPath == null)
{
    // Add the lasso to the InkPresenter and add the packetList
    // to selectionTester.
    lassoPath = newStroke;
    lassoPath.DrawingAttributes = selectDA.Clone();
    presenter.Strokes.Add(lassoPath);
    selectionTester.SelectionChanged -= new LassoSelectionChangedEventHandler
                    (selectionTester_SelectionChanged);
    selectionTester.EndHitTesting();
}
```

#### 将其所有组合在一起。

下面的示例是，用户可以选择使用套索墨迹的自定义控件。

C#复制

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Input;
using System.Windows.Input.StylusPlugIns;
using System.Windows.Ink;

// Enum that keeps track of whether StrokeCollectionDemo is in ink mode 
// or select mode.
public enum InkMode
{
    Ink, Select
}

// This control allows the user to input and select ink.  When the
// user selects ink, the lasso remains visible until they erase, or clip
// the selected strokes, or clear the selection.  When the control is
// in selection mode, strokes that are selected turn red.
public class InkSelector : Label
{
    InkMode mode;

    DrawingAttributes inkDA;
    DrawingAttributes selectDA;

    InkPresenter presenter;
    IncrementalLassoHitTester selectionTester;
    StrokeCollection selectedStrokes = new StrokeCollection();

    // StylusPointCollection that collects the stylus points from the stylus events.
    StylusPointCollection stylusPoints;
    // Stroke that represents the lasso.
    Stroke lassoPath;

    DynamicRenderer renderer;

    public InkSelector()
    {
        mode = InkMode.Ink;

        // Use an InkPresenter to display the strokes on the custom control.
        presenter = new InkPresenter();
        this.Content = presenter;

        // In the constructor.
        // Selection drawing attributes use dark gray ink.
        selectDA = new DrawingAttributes();
        selectDA.Color = Colors.DarkGray;

        // ink drawing attributes use default attributes
        inkDA = new DrawingAttributes();
        inkDA.Width = 5;
        inkDA.Height = 5;

        inkDA.AttributeChanged += new PropertyDataChangedEventHandler(DrawingAttributesChanged);
        selectDA.AttributeChanged += new PropertyDataChangedEventHandler(DrawingAttributesChanged);

        // Add a DynmaicRenderer to the control so ink appears
        // to "flow" from the tablet pen.
        renderer = new DynamicRenderer();
        renderer.DrawingAttributes = inkDA;
        this.StylusPlugIns.Add(renderer);
        presenter.AttachVisuals(renderer.RootVisual,
            renderer.DrawingAttributes);
    }

    static InkSelector()
    {
        // Allow ink to be drawn only within the bounds of the control.
        Type owner = typeof(InkSelector);
        ClipToBoundsProperty.OverrideMetadata(owner,
            new FrameworkPropertyMetadata(true));
    }


    // Prepare to collect stylus packets. If Mode is set to Select,  
    // get the IncrementalHitTester from the InkPresenter'newStroke 
    // StrokeCollection and subscribe to its StrokeHitChanged event.
    protected override void OnStylusDown(StylusDownEventArgs e)
    {
        base.OnStylusDown(e);

        Stylus.Capture(this);

        // Create a new StylusPointCollection using the StylusPointDescription
        // from the stylus points in the StylusDownEventArgs.
        stylusPoints = new StylusPointCollection();
        StylusPointCollection eventPoints = e.GetStylusPoints(this, stylusPoints.Description);

        stylusPoints.Add(eventPoints);

        InitializeHitTester(eventPoints);

    }

    protected override void OnMouseLeftButtonDown(MouseButtonEventArgs e)
    {
        base.OnMouseLeftButtonDown(e);
        
        Mouse.Capture(this);
        
        if (e.StylusDevice != null)
        {
            return;
        }

        Point pt = e.GetPosition(this);

        StylusPointCollection collectedPoints = new StylusPointCollection(new Point[] { pt });

        stylusPoints = new StylusPointCollection();

        stylusPoints.Add(collectedPoints);

        InitializeHitTester(collectedPoints);


    }
    private void InitializeHitTester(StylusPointCollection collectedPoints)
    {
        // Deselect any selected strokes.
        foreach (Stroke selectedStroke in selectedStrokes)
        {
            selectedStroke.DrawingAttributes.Color = inkDA.Color;
        }
        selectedStrokes.Clear();

        if (mode == InkMode.Select)
        {
            // Remove the previously drawn lasso, if it exists.
            if (lassoPath != null)
            {
                presenter.Strokes.Remove(lassoPath);
                lassoPath = null;
            }

            selectionTester =
                presenter.Strokes.GetIncrementalLassoHitTester(80);
            selectionTester.SelectionChanged += 
                new LassoSelectionChangedEventHandler(selectionTester_SelectionChanged);
            selectionTester.AddPoints(collectedPoints);
        }
    }

    // Collect the stylus packets as the stylus moves.
    protected override void OnStylusMove(StylusEventArgs e)
    {
        if (stylusPoints == null)
        {
            return;
        }

        StylusPointCollection collectedPoints = e.GetStylusPoints(this, stylusPoints.Description);
        stylusPoints.Add(collectedPoints);
        AddPointsToHitTester(collectedPoints);

    }

    protected override void OnMouseMove(MouseEventArgs e)
    {

        base.OnMouseMove(e);

        if (e.StylusDevice != null)
        {
            return;
        }

        if (e.LeftButton == MouseButtonState.Released)
        {
            return;
        }

        if (stylusPoints == null)
        {
            stylusPoints = new StylusPointCollection();
        }

        Point pt = e.GetPosition(this);

        StylusPointCollection collectedPoints = new StylusPointCollection(new Point[] { pt });

        stylusPoints.Add(collectedPoints);

        AddPointsToHitTester(collectedPoints);

    }

    private void AddPointsToHitTester(StylusPointCollection collectedPoints)
    {

        if (mode == InkMode.Select &&
            selectionTester != null && 
            selectionTester.IsValid)
        {
            // When the control is selecting strokes, add the
            // stylus packetList to selectionTester.
            selectionTester.AddPoints(collectedPoints);

        }
    }

    // When the user lifts the stylus, create a Stroke from the
    // collected stylus points and add it to the InkPresenter.
    // When the control is selecting strokes, add the
    // point data to the IncrementalHitTester.
    protected override void OnStylusUp(StylusEventArgs e)
    {
        if (stylusPoints == null)
        {
            stylusPoints = new StylusPointCollection();
        }
        StylusPointCollection collectedPoints = 
            e.GetStylusPoints(this, stylusPoints.Description);

        stylusPoints.Add(collectedPoints);
        AddPointsToHitTester(collectedPoints);
        AddStrokeToPresenter();
        stylusPoints = null;

        Stylus.Capture(null);
    }

    protected override void OnMouseLeftButtonUp(MouseButtonEventArgs e)
    {

        base.OnMouseLeftButtonUp(e);

        if (e.StylusDevice != null) return;

        if (stylusPoints == null) stylusPoints = new StylusPointCollection();

        Point pt = e.GetPosition(this);

        StylusPointCollection collectedPoints = new StylusPointCollection(new Point[] { pt });

        stylusPoints.Add(collectedPoints);
        AddPointsToHitTester(collectedPoints);
        AddStrokeToPresenter();
        
        stylusPoints = null;

        Mouse.Capture(null);

    }

    private void AddStrokeToPresenter()
    {
        Stroke newStroke = new Stroke(stylusPoints);

        if (mode == InkMode.Ink)
        {
            // Add the stroke to the InkPresenter.
            newStroke.DrawingAttributes = inkDA.Clone();
            presenter.Strokes.Add(newStroke);
        }

        if (mode == InkMode.Select && lassoPath == null)
        {
            // Add the lasso to the InkPresenter and add the packetList
            // to selectionTester.
            lassoPath = newStroke;
            lassoPath.DrawingAttributes = selectDA.Clone();
            presenter.Strokes.Add(lassoPath);
            selectionTester.SelectionChanged -= new LassoSelectionChangedEventHandler
                            (selectionTester_SelectionChanged);
            selectionTester.EndHitTesting();
        }
    }

    void selectionTester_SelectionChanged(object sender,
        LassoSelectionChangedEventArgs args)
    {
        // Change the color of all selected strokes to red.
        foreach (Stroke selectedStroke in args.SelectedStrokes)
        {
            selectedStroke.DrawingAttributes.Color = Colors.Red;
            selectedStrokes.Add(selectedStroke);

        }

        // Change the color of all unselected strokes to 
        // their original color.
        foreach (Stroke unselectedStroke in args.DeselectedStrokes)
        {
            unselectedStroke.DrawingAttributes.Color = inkDA.Color;
            selectedStrokes.Remove(unselectedStroke);
        }
    }

    // Property to indicate whether the user is inputting or
    // selecting ink.  
    public InkMode Mode
    {
        get
        {
            return mode;
        }

        set
        {
            mode = value;

            // Set the DrawingAttributes of the DynamicRenderer
            if (mode == InkMode.Ink)
            {
                renderer.DrawingAttributes = inkDA;
            }
            else
            {
                renderer.DrawingAttributes = selectDA;
            }

            // Reattach the visual of the DynamicRenderer to the InkPresenter.
            presenter.DetachVisuals(renderer.RootVisual);
            presenter.AttachVisuals(renderer.RootVisual, renderer.DrawingAttributes);
        }
    }
    void DrawingAttributesChanged(object sender, PropertyDataChangedEventArgs e)
    {
        // Reattach the visual of the DynamicRenderer to the InkPresenter 
        // whenever the DrawingAttributes change.
        presenter.DetachVisuals(renderer.RootVisual);
        presenter.AttachVisuals(renderer.RootVisual, renderer.DrawingAttributes);

    }

    // Property to allow the user to change the pen's DrawingAttributes.
    public DrawingAttributes InkDrawingAttributes
    {
        get
        {
            return inkDA;
        }
    }

    // Property to allow the user to change the Selector'newStroke DrawingAttributes.
    public DrawingAttributes SelectDrawingAttributes
    {
        get
        {
            return selectDA;
        }
    }

}
```

### [Add Custom Data to Ink Data](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-add-custom-data-to-ink-data)

可以将自定义数据添加到墨迹保存为墨迹序列化格式 (ISF) 时将保存的墨迹。 你可以自定义将数据保存到[DrawingAttributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.drawingattributes)、 [StrokeCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.strokecollection)，或[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke)。 能够将自定义数据保存在三个对象上使你能够决定最佳的位置来保存的数据。 所有三个类使用类似的方法来存储和访问自定义数据。

只能使用以下类型可以另存为自定义数据：

- [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean)
- [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean)[]
- [Byte](https://docs.microsoft.com/zh-cn/dotnet/api/system.byte)
- [Byte](https://docs.microsoft.com/zh-cn/dotnet/api/system.byte)[]
- [Char](https://docs.microsoft.com/zh-cn/dotnet/api/system.char)
- [Char](https://docs.microsoft.com/zh-cn/dotnet/api/system.char)[]
- [DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)
- [DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)[]
- [Decimal](https://docs.microsoft.com/zh-cn/dotnet/api/system.decimal)
- [Decimal](https://docs.microsoft.com/zh-cn/dotnet/api/system.decimal)[]
- [Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double)
- [Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double)[]
- [Int16](https://docs.microsoft.com/zh-cn/dotnet/api/system.int16)
- [Int16](https://docs.microsoft.com/zh-cn/dotnet/api/system.int16)[]
- [Int32](https://docs.microsoft.com/zh-cn/dotnet/api/system.int32)
- [Int32](https://docs.microsoft.com/zh-cn/dotnet/api/system.int32)[]
- [Int64](https://docs.microsoft.com/zh-cn/dotnet/api/system.int64)
- [Int64](https://docs.microsoft.com/zh-cn/dotnet/api/system.int64)[]
- [Single](https://docs.microsoft.com/zh-cn/dotnet/api/system.single)
- [Single](https://docs.microsoft.com/zh-cn/dotnet/api/system.single)[]
- [String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)
- [UInt16](https://docs.microsoft.com/zh-cn/dotnet/api/system.uint16)
- [UInt16](https://docs.microsoft.com/zh-cn/dotnet/api/system.uint16)[]
- [UInt32](https://docs.microsoft.com/zh-cn/dotnet/api/system.uint32)
- [UInt32](https://docs.microsoft.com/zh-cn/dotnet/api/system.uint32)[]
- [UInt64](https://docs.microsoft.com/zh-cn/dotnet/api/system.uint64)
- [UInt64](https://docs.microsoft.com/zh-cn/dotnet/api/system.uint64)[]

#### 示例

下面的示例演示如何添加和检索自定义数据从[StrokeCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.strokecollection)。

```csharp
Guid timestamp = new Guid("12345678-9012-3456-7890-123456789012");

// Add a timestamp to the StrokeCollection.
private void AddTimestamp()
{

    inkCanvas1.Strokes.AddPropertyData(timestamp, DateTime.Now);
}

// Get the timestamp of the StrokeCollection.
private void GetTimestamp()
{

    if (inkCanvas1.Strokes.ContainsPropertyData(timestamp))
    {
        object date = inkCanvas1.Strokes.GetPropertyData(timestamp);

        if (date is DateTime)
        {
            MessageBox.Show("This StrokeCollection's timestamp is " +
                ((DateTime)date).ToString());
        }
    }
    else
    {
        MessageBox.Show(
            "The StrokeCollection does not have a timestamp.");
    }
}
```

下面的示例创建的应用程序显示[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)和两个按钮。 此按钮时， `switchAuthor`，使两个钢笔用于两个不同的作者。 按钮`changePenColors`上的更改每个笔画颜色[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)根据作者。 应用程序定义了两个[DrawingAttributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.drawingattributes)对象，并将自定义属性添加到指示哪个作者绘制每个[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.stroke)。 当用户单击`changePenColors`，应用程序更改根据自定义属性的值的笔划的外观。

```xaml
<Window x:Class="Window1"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    Title="Adding Custom Data to Ink" Height="500" Width="700"
    >
  <DockPanel Name="root">

    <StackPanel  Background="DarkSlateBlue">
      <Button Name="switchAuthor" Click="switchAuthor_click" >
        Switch to student's pen 
      </Button>
      <Button Name="changePenColors" Click="changeColor_click" >
        Change the color of the pen ink
      </Button>
    </StackPanel>
    <InkCanvas Name="inkCanvas1">
    </InkCanvas>
  </DockPanel>
</Window>
```

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using System.Windows.Ink;

/// <summary>
/// Interaction logic for Window1.xaml
/// </summary>

public partial class Window1 : Window
{
    Guid authorGuid = new Guid("12345678-9012-3456-7890-123456789012");
    DrawingAttributes teachersDA = new DrawingAttributes();
    DrawingAttributes studentsDA = new DrawingAttributes();
    string teacher = "teacher";
    string student = "student";
    bool useStudentPen = false;

    public Window1()
    {
        InitializeComponent();

        teachersDA.Color = Colors.Red;
        teachersDA.Width = 5;
        teachersDA.Height = 5;
        teachersDA.AddPropertyData(authorGuid, teacher);

        studentsDA.Color = Colors.Blue;
        studentsDA.Width = 5;
        studentsDA.Height = 5;
        studentsDA.AddPropertyData(authorGuid, student);

        inkCanvas1.DefaultDrawingAttributes = teachersDA;
    }

    // Switch between using the 'pen' DrawingAttributes and the 
    // 'highlighter' DrawingAttributes.
    void switchAuthor_click(Object sender, RoutedEventArgs e)
    {
        useStudentPen = !useStudentPen;

        if (useStudentPen)
        {
            switchAuthor.Content = "Use teacher's pen";
            inkCanvas1.DefaultDrawingAttributes = studentsDA;
        }
        else
        {
            switchAuthor.Content = "Use student's pen";
            inkCanvas1.DefaultDrawingAttributes = teachersDA;

        }
    }

    // Change the color of the ink that on the InkCanvas that used the pen.
    void changeColor_click(Object sender, RoutedEventArgs e)
    {
        foreach (Stroke s in inkCanvas1.Strokes)
        {
            if (s.DrawingAttributes.ContainsPropertyData(authorGuid))
            {
                object data = s.DrawingAttributes.GetPropertyData(authorGuid);

                if ((data is string) && ((string)data == teacher))
                {
                    s.DrawingAttributes.Color = Colors.Black;
                }
                if ((data is string) && ((string)data == student))
                {
                    s.DrawingAttributes.Color = Colors.Green;
                }
            }
        }
    }
}
```

### [Erase Ink on a Custom Control](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-erase-ink-on-a-custom-control)

[IncrementalStrokeHitTester](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.incrementalstrokehittester)确定当前绘制的笔画是否与另一个笔画相交。 这是有用的用于创建控件，使用户能够清除笔画部分、 方式用户可以在[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)时[EditingMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas.editingmode)设置为[EraseByPoint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvaseditingmode#System_Windows_Controls_InkCanvasEditingMode_EraseByPoint)。

下面的示例创建使用户能够清除部分笔画的自定义控件。 此示例创建包含墨迹在初始化的控件。 若要创建收集墨迹的控件，请参阅[创建墨迹输入控件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/creating-an-ink-input-control)。

C#复制

```csharp
using System.Windows;
using System.Windows.Controls;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Media;
using System.IO;

// This control initializes with ink already on it and allows the
// user to erase the ink with the tablet pen or mouse.
public class InkEraser : Label
{
    IncrementalStrokeHitTester eraseTester;

    InkPresenter presenter;

    string strokesString =
        @"ALwHAxdIEETLgIgERYQBGwIAJAFGhAEbAgAkAQUBOBkgMgkA9P8CAekiOkUzCQD4n"
        + "wIBWiA6RTgIAP4DAAAAgH8RAACAPx8JEQAAAAAAAPA/CiUHh/A6N4HR0AivFX8Vs"
        + "IfsiuyLSaIeDSLwabiHm0GgUDi+KZkACjsQh/A9t4IC5VJpfLhaIxyxXIh7Dncnh"
        + "+6e7qODwoERlPAw8EpGoJAgh61IKjCYXBYDA4DAIHF67KIHAAojB4fwMteBn+RKB"
        + "lziaIfwWTeCwePqbM8WgIeeQCDQOFRvcIAKNA+H8B8XgQHkUbjQTTnGuaZns3l4h"
        + "/DWt4a0YKBBOA94D6HRCAiGnp5CS8LExMLB1tOgYIAKUBOH8KnXhU7lMold+tcbi"
        + "kChkqu2EtPYxp9bmYCH8HDHg4ZhMIwRyMHH+4Jt8nleX8c0/D/AkYwxJGiHkkQgM"
        + "Ch9CqcFhMDQCBwWAwuR2eAACmgdh/EpF4lA6XMUfhMXgMHgVDxBFpRKpZII5EINA"
        + "OA64M+J4Lw1CIoAh/B2x4PS4bQodAopEI5IJBki4waEx2Qy+dy+ayHgleEmmHH8c"
        + "e3MZOCGw5TWd3CwsHAwMCgRAEAgElKwOHZKBApaGIfxezeL0uN02N8IzwaGEpNIJ"
        + "ZxHnELyOj0GfyuU6FgmhplIgIfwYgeDHeaI1vjOtZgcHgHAYb9hUCgEFgsPm1xnM"
        + "ZkYhsnYJgZeZh4uAgCgnSBIOJv4OAgwCmkgh/GrR41X4dGoRJL9EKra5HKY7IZ3C"
        + "4fj/M06olSoU8kkehUbh8jkMdCH8IJXhAXhMCk8JuNlmNyh0YiEumUwn2wMRxyHw"
        + "2TzWmzeb02OzGKxMITwIhnrjzbb44zRhGEKRhCM4zrr6sQKXRWH8kuXkmPj0DiXC"
        + "gcJbC9HZZgkKgUG4bLh3YrwJHAYw2CAh/CiN4Tq7DOZr4BB/AFtdOWW5P2h1Wkzv"
        + "l4+YwqXf8d5fZ7ih51QKbB4LQrLAYDBIDABA4BO4nAICApvIIfy4BeXA2DRSrQlL"
        + "oHHsYQ/KMXlsvl8rn8Xkcdg+G9NVaUWimUDYk9Ah/BoF4M0YBCqZPYqk8dwLf7hD"
        + "YNBJFLKBNqZTqNubWshl9VoM1reFYZYQEBGUsDAwKEjYuDQKBgICBgCAgIOAg4nI"
        + "8OACloSh/BFl4Gf/IOt6FXfF8F4ToPCZzlPwP4+B+DHmQO847rfDeCcG8eKh/EZV"
        + "4i9eZt8A9nUF8VzxaUe5grl7YrPaHfpRKJNx4yHmUuj1vicwmMBEAjUVgKB61A=";
    
    public InkEraser()
    {
        presenter = new InkPresenter();
        this.Content = presenter;

        // Create a StrokeCollection the string and add it to
        StrokeCollectionConverter converter =
            new StrokeCollectionConverter();

        if (converter.CanConvertFrom(typeof(string)))
        {
            StrokeCollection newStrokes =
                converter.ConvertFrom(strokesString) as StrokeCollection;
            presenter.Strokes.Clear();
            presenter.Strokes.Add(newStrokes);
        }

    }


    protected override void OnStylusDown(StylusDownEventArgs e)
    {
        base.OnStylusDown(e);
        StylusPointCollection points = e.GetStylusPoints(this);

        InitializeEraserHitTester(points);

    }

    protected override void OnMouseLeftButtonDown(MouseButtonEventArgs e)
    {
        base.OnMouseLeftButtonDown(e);

        if (e.StylusDevice != null)
        {
            return;
        }

        Point pt = e.GetPosition(this);

        StylusPointCollection collectedPoints = new StylusPointCollection(new Point[] { pt });

        InitializeEraserHitTester(collectedPoints);
    }

    // Prepare to collect stylus packets. Get the 
    // IncrementalHitTester from the InkPresenter's 
    // StrokeCollection and subscribe to its StrokeHitChanged event.
    private void InitializeEraserHitTester(StylusPointCollection points)
    {
        EllipseStylusShape eraserTip = new EllipseStylusShape(3, 3, 0);
        eraseTester =
            presenter.Strokes.GetIncrementalStrokeHitTester(eraserTip);
        eraseTester.StrokeHit += new StrokeHitEventHandler(eraseTester_StrokeHit);
        eraseTester.AddPoints(points);
    }

    protected override void OnStylusMove(StylusEventArgs e)
    {
        StylusPointCollection points = e.GetStylusPoints(this);

        AddPointsToEraserHitTester(points);
    }

    protected override void OnMouseMove(MouseEventArgs e)
    {
        base.OnMouseMove(e);

        if (e.StylusDevice != null)
        {
            return;
        }

        if (e.LeftButton == MouseButtonState.Released)
        {
            return;
        }

        Point pt = e.GetPosition(this);

        StylusPointCollection collectedPoints = new StylusPointCollection(new Point[] { pt });

        AddPointsToEraserHitTester(collectedPoints);
    }

    // Collect the StylusPackets as the stylus moves.
    private void AddPointsToEraserHitTester(StylusPointCollection points)
    {
        if (eraseTester.IsValid)
        {
            eraseTester.AddPoints(points);
        }
    }

    // Unsubscribe from the StrokeHitChanged event when the
    // user lifts the stylus.
    protected override void OnStylusUp(StylusEventArgs e)
    {
        StylusPointCollection points = e.GetStylusPoints(this);

        StopEraseHitTesting(points);
    }

    protected override void OnMouseLeftButtonUp(MouseButtonEventArgs e)
    {
        base.OnMouseLeftButtonUp(e);

        if (e.StylusDevice != null)
        {
            return;
        }

        Point pt = e.GetPosition(this);

        StylusPointCollection collectedPoints = new StylusPointCollection(new Point[] { pt });

        StopEraseHitTesting(collectedPoints);
    }

    private void StopEraseHitTesting(StylusPointCollection points)
    {
        eraseTester.AddPoints(points);
        eraseTester.StrokeHit -= new
            StrokeHitEventHandler(eraseTester_StrokeHit);
        eraseTester.EndHitTesting();
    }


    // When the stylus intersects a stroke, erase that part of
    // the stroke.  When the stylus dissects a stoke, the 
    // Stroke.Erase method returns a StrokeCollection that contains
    // the two new strokes.
    void eraseTester_StrokeHit(object sender,
        StrokeHitEventArgs args)
    {
        StrokeCollection eraseResult =
            args.GetPointEraseResults();
        StrokeCollection strokesToReplace = new StrokeCollection();
        strokesToReplace.Add(args.HitStroke);

        // Replace the old stroke with the new one.
        if (eraseResult.Count > 0)
        {
            presenter.Strokes.Replace(strokesToReplace, eraseResult);
        }
        else
        {
            presenter.Strokes.Remove(strokesToReplace);
        }
    }
}
```

### [Recognize Application Gestures](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-recognize-application-gestures)

下面的示例演示如何当用户进行清除的墨迹[ScratchOut](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.ink.applicationgesture#System_Windows_Ink_ApplicationGesture_ScratchOut)手势上[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)。 此示例假定[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)，称为`inkCanvas1`，XAML 文件中声明。

C#复制

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Ink;
using System.Collections.ObjectModel;

public partial class Window1 : Window
{
    public Window1()
    {
        InitializeComponent();

        if (inkCanvas1.IsGestureRecognizerAvailable)
        {
            inkCanvas1.EditingMode = InkCanvasEditingMode.InkAndGesture;
            inkCanvas1.Gesture += new InkCanvasGestureEventHandler(inkCanvas1_Gesture);
            inkCanvas1.SetEnabledGestures(
                new ApplicationGesture[] { ApplicationGesture.ScratchOut });
        }
    }

    void inkCanvas1_Gesture(object sender, InkCanvasGestureEventArgs e)
    {
        ReadOnlyCollection<GestureRecognitionResult> gestureResults =
            e.GetGestureRecognitionResults();

        // Check the first recognition result for a gesture.
        if ((gestureResults[0].RecognitionConfidence ==
            RecognitionConfidence.Strong) &&
           (gestureResults[0].ApplicationGesture ==
            ApplicationGesture.ScratchOut))
        {
            StrokeCollection hitStrokes = inkCanvas1.Strokes.HitTest(
                                            e.Strokes.GetBounds(), 10);

            if (hitStrokes.Count > 0)
            {
                inkCanvas1.Strokes.Remove(hitStrokes);
            }
        }
    }
}
```

### [Drag and Drop Ink](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-drag-and-drop-ink)

下面的示例创建的应用程序使用户能够从一个拖动所选的笔画[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)相互。

XAML复制

```xaml
<Window x:Class="Window1"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    Title="InkDragDropSample" Height="500" Width="700"
    >
  <Grid>
    <Grid.RowDefinitions>
      <RowDefinition Height="Auto"/>
      <RowDefinition Height="*"/>
    </Grid.RowDefinitions>
    <Grid.ColumnDefinitions>
      <ColumnDefinition/>
      <ColumnDefinition/>
    </Grid.ColumnDefinitions>
    
    <InkCanvas Name="ic1" AllowDrop="True" 
               Grid.Column="0" Grid.Row="0" 
               Margin="10,10,10,10" Background="AliceBlue" 
               PreviewMouseDown="InkCanvas_PreviewMouseDown" 
               Drop="InkCanvas_Drop"/>

    <InkCanvas Name="ic2" AllowDrop="True" 
               Grid.Column="1" Grid.Row="0" 
               Margin="10,10,10,10" Background="Beige" 
               PreviewMouseDown="InkCanvas_PreviewMouseDown" 
               Drop="InkCanvas_Drop"/>

    <CheckBox Grid.Row="1" 
              Checked="switchToSelect" Unchecked="switchToInk">
      Select Mode
    </CheckBox>
  </Grid>
</Window>
```

C#复制

```csharp
using System;
using System.IO;
using System.Windows;
using System.Windows.Ink;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Input;
using System.Windows.Media;

public partial class Window1 : Window
{

    public Window1()
    {
        InitializeComponent();
    }

    void InkCanvas_PreviewMouseDown(object sender, MouseEventArgs e)
    {
        InkCanvas ic = (InkCanvas)sender;
        
        Point pt = e.GetPosition(ic);

        // If the user is moving selected strokes, prepare the strokes to be
        // moved to another InkCanvas.
        if (ic.HitTestSelection(pt) == 
            InkCanvasSelectionHitResult.Selection)
        {
            StrokeCollection selectedStrokes = ic.GetSelectedStrokes();
            StrokeCollection strokesToMove = selectedStrokes.Clone();
        
            // Remove the offset of the selected strokes so they
            // are positioned when the strokes are dropped.
            Rect inkBounds = strokesToMove.GetBounds();
            TranslateStrokes(strokesToMove, -inkBounds.X, -inkBounds.Y);
            
            // Perform drag and drop.
            MemoryStream ms = new MemoryStream();
            strokesToMove.Save(ms);
            DataObject dataObject = new DataObject(
                StrokeCollection.InkSerializedFormat, ms);
            
            DragDropEffects effects = 
                DragDrop.DoDragDrop(ic, dataObject, 
                                    DragDropEffects.Move);

            if ((effects & DragDropEffects.Move) == 
                 DragDropEffects.Move)
            {
                // Remove the selected strokes 
                // from the current InkCanvas.
                ic.Strokes.Remove(selectedStrokes);
            }
        }
    }

    void InkCanvas_Drop(object sender, DragEventArgs e)
    {
        // Get the strokes that were moved.
        InkCanvas ic = (InkCanvas)sender;
        MemoryStream ms = (MemoryStream)e.Data.GetData(
                           StrokeCollection.InkSerializedFormat);
        ms.Position = 0;
        StrokeCollection strokes = new StrokeCollection(ms);

        // Translate the strokes to the position at which
        // they were dropped.
        Point pt = e.GetPosition(ic);
        TranslateStrokes(strokes, pt.X, pt.Y);

        // Add the strokes to the InkCanvas and keep them selected.
        ic.Strokes.Add(strokes);
        ic.Select(strokes);
    }

    // Helper method that transletes the specified strokes.
    void TranslateStrokes(StrokeCollection strokes, 
                          double x, double y)
    {
        Matrix mat = new Matrix();
        mat.Translate(x, y);
        strokes.Transform(mat, false);
    }

    void switchToSelect(object sender, RoutedEventArgs e)
    {
        ic1.EditingMode = InkCanvasEditingMode.Select;
        ic2.EditingMode = InkCanvasEditingMode.Select;
    }

    void switchToInk(object sender, RoutedEventArgs e)
    {
        ic1.EditingMode = InkCanvasEditingMode.Ink;
        ic2.EditingMode = InkCanvasEditingMode.Ink;
    }
}
```

### [Data Bind to an InkCanvas](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-data-bind-to-an-inkcanvas)

下面的示例演示如何将绑定[Strokes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas.strokes)属性[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)到另一个[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)。

XAML复制

```xaml
<InkCanvas Background="LightGray" 
           Canvas.Top="0" Canvas.Left="0" 
           Height="400" Width="200" Name="ic"/>

<!-- Bind the Strokes of the second InkCavas to the first InkCanvas
     and mirror the strokes along the Y axis.-->
<InkCanvas Background="LightBlue"  
           Canvas.Top="0" Canvas.Left="200" 
           Height="400" Width="200" 
           Strokes="{Binding ElementName=ic, Path=Strokes}">
  <InkCanvas.LayoutTransform>
    <ScaleTransform ScaleX="-1" ScaleY="1" />
  </InkCanvas.LayoutTransform>
</InkCanvas>
```

下面的示例演示如何将绑定[DefaultDrawingAttributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas.defaultdrawingattributes)到数据源的属性。

XAML复制

```xaml
<Canvas.Resources>
  <!--Define an array containing some DrawingAttributes.-->
  <x:Array x:Key="MyDrawingAttributes" x:Type="{x:Type DrawingAttributes}">
    <DrawingAttributes Color="Black" FitToCurve="true" Width="3" Height="3"/>
    <DrawingAttributes Color="Blue"  FitToCurve="false" Width="5" Height="5"/>
    <DrawingAttributes Color="Red"   FitToCurve="true" Width="7" Height="7"/>
  </x:Array>

  <!--Create a DataTemplate to display the DrawingAttributes shown above-->
  <DataTemplate DataType="{x:Type DrawingAttributes}" >
    <Border Width="80" Height="{Binding Path=Height}">
      <Border.Background >
        <SolidColorBrush Color="{Binding Path=Color}"/>
      </Border.Background>
    </Border>
  </DataTemplate>
</Canvas.Resources>
```

XAML复制

```xaml
<!--Bind the InkCavas' DefaultDrawingAtributes to
    a Listbox, called lbDrawingAttributes.-->
<InkCanvas Name="inkCanvas1" Background="LightGreen" 
           Canvas.Top="400" Canvas.Left="0" 
           Height="400" Width="400"
           DefaultDrawingAttributes="{Binding 
                ElementName=lbDrawingAttributes, Path=SelectedItem}"
           >
</InkCanvas>

<!--Use the array, MyDrawingAttributes, to populate a ListBox-->
<ListBox Name="lbDrawingAttributes" 
         Canvas.Top="400" Canvas.Left="450" 
         Height="100" Width="100"
         ItemsSource="{StaticResource MyDrawingAttributes}" />
```

下面的示例声明了两个[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)XAML 中的对象，并建立它们和其他数据源之间的数据绑定。 第一个[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)、 调用`ic`，绑定到两个数据源。 [EditingMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas.editingmode)和[DefaultDrawingAttributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas.defaultdrawingattributes)属性`ic`绑定到[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)又绑定到在 XAML 中定义的数组的对象。 [EditingMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas.editingmode)， [DefaultDrawingAttributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas.defaultdrawingattributes)，和[Strokes](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas.strokes)第二个属性[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)绑定到第一个[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)， `ic`。

XAML复制

```xaml
<Canvas>
  <Canvas.Resources>
    <!--Define an array containing the InkEditingMode Values.-->
    <x:Array x:Key="MyEditingModes" x:Type="{x:Type InkCanvasEditingMode}">
      <x:Static Member="InkCanvasEditingMode.Ink"/>
      <x:Static Member="InkCanvasEditingMode.Select"/>
      <x:Static Member="InkCanvasEditingMode.EraseByPoint"/>
      <x:Static Member="InkCanvasEditingMode.EraseByStroke"/>
    </x:Array>

    <!--Define an array containing some DrawingAttributes.-->
    <x:Array x:Key="MyDrawingAttributes" 
             x:Type="{x:Type DrawingAttributes}">
      <DrawingAttributes Color="Black" FitToCurve="true" 
                         Width="3" Height="3"/>
      <DrawingAttributes Color="Blue" FitToCurve="false" 
                         Width="5" Height="5"/>
      <DrawingAttributes Color="Red" FitToCurve="true" 
                         Width="7" Height="7"/>
    </x:Array>

    <!--Create a DataTemplate to display the 
        DrawingAttributes shown above-->
    <DataTemplate DataType="{x:Type DrawingAttributes}" >
      <Border Width="80" Height="{Binding Path=Height}">
        <Border.Background >
          <SolidColorBrush Color="{Binding Path=Color}"/>
        </Border.Background>
      </Border>
    </DataTemplate>
  </Canvas.Resources>

  <!--Bind the first InkCavas' DefaultDrawingAtributes to a 
      Listbox, called lbDrawingAttributes, and its EditingMode to 
      a ListBox called lbEditingMode.-->
  <InkCanvas Name="ic" Background="LightGray" 
             Canvas.Top="0" Canvas.Left="0" 
             Height="400" Width="200"
             DefaultDrawingAttributes="{Binding 
                  ElementName=lbDrawingAttributes, Path=SelectedItem}"
             EditingMode=
                  "{Binding ElementName=lbEditingMode, Path=SelectedItem}"
             >
  </InkCanvas>

  <!--Bind the Strokes, DefaultDrawingAtributes, and, EditingMode properties of
      the second InkCavas the first InkCanvas.-->
  <InkCanvas Background="LightBlue"  
             Canvas.Top="0" Canvas.Left="200" 
             Height="400" Width="200" 
             Strokes="{Binding ElementName=ic, Path=Strokes}" 
             DefaultDrawingAttributes="{Binding 
                  ElementName=ic, Path=DefaultDrawingAttributes}" 
             EditingMode="{Binding ElementName=ic, Path=EditingMode}">
    
    <InkCanvas.LayoutTransform>
      <ScaleTransform ScaleX="-1" ScaleY="1" />
    </InkCanvas.LayoutTransform>
  
  </InkCanvas>

  <!--Use the array, MyEditingModes, to populate a ListBox-->
  <ListBox Name="lbEditingMode" 
           Canvas.Top="0" Canvas.Left="450" 
           Height="100" Width="100"
           ItemsSource="{StaticResource MyEditingModes}" />

  <!--Use the array, MyDrawingAttributes, to populate a ListBox-->
  <ListBox Name="lbDrawingAttributes" 
           Canvas.Top="150" Canvas.Left="450" 
           Height="100" Width="100"
           ItemsSource="{StaticResource MyDrawingAttributes}" />

</Canvas>
```

### [Analyze Ink with Analysis Hints](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-analyze-ink-with-analysis-hints)

[System.Windows.Ink.AnalysisHintNode](https://msdn.microsoft.com/library/system.windows.ink.analysishintnode(v=vs.100).aspx)提供提示[System.Windows.Ink.InkAnalyzer](https://msdn.microsoft.com/library/system.windows.ink.inkanalyzer(v=vs.100).aspx)它所附加到。 提示适用于指定的区域[System.Windows.Ink.ContextNode.Location%2A](https://msdn.microsoft.com/library/system.windows.ink.contextnode.location(v=vs.100).aspx)属性[System.Windows.Ink.AnalysisHintNode](https://msdn.microsoft.com/library/system.windows.ink.analysishintnode(v=vs.100).aspx)并提供到墨迹分析器的额外上下文提高识别的准确性。 [System.Windows.Ink.InkAnalyzer](https://msdn.microsoft.com/library/system.windows.ink.inkanalyzer(v=vs.100).aspx)提示的区域内，从分析墨迹获得时应用此上下文信息。

下面的示例是使用多个应用程序[System.Windows.Ink.AnalysisHintNode](https://msdn.microsoft.com/library/system.windows.ink.analysishintnode(v=vs.100).aspx)接受墨迹输入的窗体上的对象。 应用程序使用[System.Windows.Ink.AnalysisHintNode.Factoid%2A](https://msdn.microsoft.com/library/system.windows.ink.analysishintnode.factoid(v=vs.100))属性，以提供窗体上的每个条目的上下文信息。 应用程序使用背景分析来分析墨迹并清除所有墨迹形式 5 秒后用户停止添加墨迹。

XAML复制

```xaml
<Window x:Class="FormAnalyzer"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    Title="FormAnalyzer"
      SizeToContent="WidthAndHeight"
    >
    <StackPanel Orientation="Vertical">
    <InkCanvas Name="xaml_writingCanvas" Height="500" Width="840" 
               StrokeCollected="RestartAnalysis" >
            <Grid>
                <Grid.Resources>
                    <Style TargetType="{x:Type Label}">
                        <Setter Property="FontSize" Value="20"/>
                        <Setter Property="FontFamily" Value="Arial"/>
                    </Style>

                    <Style TargetType="{x:Type TextBlock}">
                        <Setter Property="FontSize" Value="18"/>
                        <Setter Property="VerticalAlignment" Value="Center"/>
                    </Style>
                </Grid.Resources>
                
                <Grid.ColumnDefinitions>
                    <ColumnDefinition Width="100"></ColumnDefinition>
                    <ColumnDefinition Width="160"></ColumnDefinition>
                    <ColumnDefinition Width="160"></ColumnDefinition>
                    <ColumnDefinition Width="100"></ColumnDefinition>
                    <ColumnDefinition Width="160"></ColumnDefinition>
                    <ColumnDefinition Width="160"></ColumnDefinition>
                </Grid.ColumnDefinitions>

                <Grid.RowDefinitions>
                    <RowDefinition Height="100"></RowDefinition>
                    <RowDefinition Height="100"></RowDefinition>
                    <RowDefinition Height="100"></RowDefinition>
                    <RowDefinition Height="100"></RowDefinition>
                    <RowDefinition Height="100"></RowDefinition>
                </Grid.RowDefinitions>

                <Label Grid.Row="0" Grid.Column="0">Title</Label>
                <Label Grid.Row="1" Grid.Column="0">Director</Label>
                <Label Grid.Row="2" Grid.Column="0">Starring</Label>
                <Label Grid.Row="3" Grid.Column="0">Rating</Label>
                <Label Grid.Row="3" Grid.Column="3">Year</Label>
                <Label Grid.Row="4" Grid.Column="0">Genre</Label>

                <TextBlock Name="xaml_blockTitle" 
                   Grid.Row="0" Grid.Column="1" 
                   Grid.ColumnSpan="5"/>
        <TextBlock Name="xaml_blockDirector"
                   Grid.Row="1" Grid.Column="1" 
                   Grid.ColumnSpan="5"/>
                <TextBlock Name="xaml_blockStarring"
                   Grid.Row="2" Grid.Column="1" 
                   Grid.ColumnSpan="5"/>
                <TextBlock Name="xaml_blockRating" 
                   Grid.Row="3" Grid.Column="1" 
                   Grid.ColumnSpan="2"/>
                <TextBlock Name="xaml_blockYear" 
                   Grid.Row="3" Grid.Column="4" 
                   Grid.ColumnSpan="2"/>
                <TextBlock Name="xaml_blockGenre" 
                   Grid.Row="4" Grid.Column="1" 
                   Grid.ColumnSpan="5"/>

                <Line Grid.Row="0" Grid.Column="0" Grid.ColumnSpan="6" 
              StrokeThickness="2" Stroke="Black" 
              X1="0" Y1="100" X2="840" Y2="100" />
                <Line Grid.Row="1" Grid.Column="0" Grid.ColumnSpan="6" 
              StrokeThickness="2" Stroke="Black" 
              X1="0" Y1="100" X2="840" Y2="100" />
                <Line Grid.Row="2" Grid.Column="0" Grid.ColumnSpan="6" 
              StrokeThickness="2" Stroke="Black" 
              X1="0" Y1="100" X2="840" Y2="100" />
                <Line Grid.Row="3" Grid.Column="0" Grid.ColumnSpan="6" 
              StrokeThickness="2" Stroke="Black" 
              X1="0" Y1="100" X2="840" Y2="100" />
                <Line Grid.Row="3" Grid.Column="0" Grid.ColumnSpan="6" 
              StrokeThickness="2" Stroke="Black" 
              X1="420" Y1="0" X2="420" Y2="100" />
            </Grid>
        </InkCanvas>
    </StackPanel>
</Window>
```

C#复制

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Ink;
using System.Windows.Threading;

public partial class FormAnalyzer : Window
{
    private InkAnalyzer analyzer;

    private AnalysisHintNode hintNodeTitle;
    private AnalysisHintNode hintNodeDirector;
    private AnalysisHintNode hintNodeStarring;
    private AnalysisHintNode hintNodeRating;
    private AnalysisHintNode hintNodeYear;
    private AnalysisHintNode hintNodeGenre;

    // Timer that raises an event to
    // clear the InkCanvas.
    private DispatcherTimer strokeRemovalTimer;

    private const int CLEAR_STROKES_DELAY = 5;

    public FormAnalyzer()
    {
        InitializeComponent();
    }

    protected override void OnContentRendered(EventArgs e)
    {
        base.OnContentRendered(e);

        // Initialize the Analyzer.
        analyzer = new InkAnalyzer();
        analyzer.ResultsUpdated += 
            new ResultsUpdatedEventHandler(analyzer_ResultsUpdated);

        // Add analysis hints for each form area.
        // Use the absolute Width and Height of the Grid's
        // RowDefinition and ColumnDefinition properties defined in XAML, 
        // to calculate the bounds of the AnalysisHintNode objects.
        hintNodeTitle = analyzer.CreateAnalysisHint(
                                    new Rect(100, 0, 740, 100));
        hintNodeDirector = analyzer.CreateAnalysisHint(
                                    new Rect(100, 100, 740, 100));
        hintNodeStarring = analyzer.CreateAnalysisHint(
                                    new Rect(100, 200, 740, 100));
        hintNodeRating = analyzer.CreateAnalysisHint(
                                    new Rect(100, 300, 320, 100));
        hintNodeYear = analyzer.CreateAnalysisHint(
                                    new Rect(520, 300, 320, 100));
        hintNodeGenre = analyzer.CreateAnalysisHint(
                                    new Rect(100, 400, 740, 100));

        //Set the factoids on the hints.
        hintNodeTitle.Factoid = "(!IS_DEFAULT)";
        hintNodeDirector.Factoid = "(!IS_PERSONALNAME_FULLNAME)";
        hintNodeStarring.Factoid = "(!IS_PERSONALNAME_FULLNAME)";
        hintNodeRating.Factoid = "(!IS_DEFAULT)";
        hintNodeYear.Factoid = "(!IS_DATE_YEAR)";
        hintNodeGenre.Factoid = "(!IS_DEFAULT)";
    }

    /// <summary>
    /// InkCanvas.StrokeCollected event handler.  Begins 
    /// ink analysis and starts the timer to clear the strokes.
    /// If five seconds pass without a Stroke being added,
    /// the strokes on the InkCanvas will be cleared.
    /// </summary>
    /// <par    am name="sender">InkCanvas that raises the
    /// StrokeCollected event.</param>
    /// <param name="args">Contains the event data.</param>
    private void RestartAnalysis(object sender,
                    InkCanvasStrokeCollectedEventArgs args)
    {

        // If strokeRemovalTimer is enabled, stop it.
        if (strokeRemovalTimer != null && strokeRemovalTimer.IsEnabled)
        {
            strokeRemovalTimer.Stop();
        }

        // Restart the timer to clear the strokes in five seconds
        strokeRemovalTimer = new DispatcherTimer(
                             TimeSpan.FromSeconds(CLEAR_STROKES_DELAY),
                             DispatcherPriority.Normal,
                             ClearCanvas,
                             Dispatcher.CurrentDispatcher);

        // Add the new stroke to the InkAnalyzer and
        // begin background analysis.
        analyzer.AddStroke(args.Stroke);
        analyzer.BackgroundAnalyze();
    }

    /// <summary>
    /// Analyzer.ResultsUpdated event handler.
    /// </summary>
    /// <param name="sender">InkAnalyzer that raises the
    /// event.</param>
    /// <param name="e">Event data</param>
    /// <remarks>This method checks each AnalysisHint for 
    /// analyzed ink and then populated the TextBlock that 
    /// corresponds to the area on the form.</remarks>
    void analyzer_ResultsUpdated(object sender, ResultsUpdatedEventArgs e)
    {
        string recoText;

        recoText = hintNodeTitle.GetRecognizedString();
        if (recoText != "") xaml_blockTitle.Text = recoText;

        recoText = hintNodeDirector.GetRecognizedString();
        if (recoText != "") xaml_blockDirector.Text = recoText;

        recoText = hintNodeStarring.GetRecognizedString();
        if (recoText != "") xaml_blockStarring.Text = recoText;

        recoText = hintNodeRating.GetRecognizedString();
        if (recoText != "") xaml_blockRating.Text = recoText;

        recoText = hintNodeYear.GetRecognizedString();
        if (recoText != "") xaml_blockYear.Text = recoText;

        recoText = hintNodeGenre.GetRecognizedString();
        if (recoText != "") xaml_blockGenre.Text = recoText;
    }

    //Clear the canvas, but leave the current strokes in the analyzer.
    private void ClearCanvas(object sender, EventArgs args)
    {
        strokeRemovalTimer.Stop();

        xaml_writingCanvas.Strokes.Clear();
    }
}
```

### [Rotate Ink](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-rotate-ink)

下面的示例将复制从墨迹[InkCanvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkcanvas)到[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)包含[InkPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkpresenter)。 当应用程序复制墨迹时，它还会将墨迹顺时针旋转 90 度。

XAML复制

```xaml
<Canvas>
   <InkCanvas Name="inkCanvas1" Background="LightBlue"
              Height="200" Width="200" 
              Canvas.Top="20" Canvas.Left="20" />
     
   <Border Name="canvas1" Background="LightGreen"  
           Height="200" Width="200" ClipToBounds="True"
           Canvas.Top="20" Canvas.Left="240" >
     <InkPresenter Name="inkPresenter1"/>
   </Border>
   <Button Click="button_Click" 
           Canvas.Top="240" Canvas.Left="170">
     Copy and Rotate Strokes
   </Button>
 </Canvas>
```

C#复制

```csharp
// Button.Click event handler that rotates the strokes
// and copies them to a Canvas.
private void button_Click(object sender, RoutedEventArgs e)
{
    StrokeCollection copiedStrokes = inkCanvas1.Strokes.Clone();
    Matrix rotatingMatrix = new Matrix();
    double canvasLeft = Canvas.GetLeft(inkCanvas1);
    double canvasTop = Canvas.GetTop(inkCanvas1);
    Point rotatePoint = new Point(canvas1.Width / 2, canvas1.Height / 2);

    rotatingMatrix.RotateAt(90, rotatePoint.X, rotatePoint.Y);
    copiedStrokes.Transform(rotatingMatrix, false);
    inkPresenter1.Strokes = copiedStrokes;

}
```

下面的示例是一个自定义[Adorner](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.adorner)上旋转描边[InkPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkpresenter)。

C#复制

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Shapes;
using System.Windows.Ink;

public class RotatingStrokesAdorner : Adorner
{
    // The Thumb to drag to rotate the strokes.
    Thumb rotateHandle;

    // The surrounding boarder.
    Path outline;

    VisualCollection visualChildren;

    // The center of the strokes.
    Point center;
    double lastAngle;

    RotateTransform rotation;

    const int HANDLEMARGIN = 10;

    // The bounds of the Strokes;
    Rect strokeBounds = Rect.Empty;

    public RotatingStrokesAdorner(UIElement adornedElement)
        : base(adornedElement)
    {

        visualChildren = new VisualCollection(this);
        rotateHandle = new Thumb();
        rotateHandle.Cursor = Cursors.SizeNWSE;
        rotateHandle.Width = 20;
        rotateHandle.Height = 20;
        rotateHandle.Background = Brushes.Blue;

        rotateHandle.DragDelta += new DragDeltaEventHandler(rotateHandle_DragDelta);
        rotateHandle.DragCompleted += new DragCompletedEventHandler(rotateHandle_DragCompleted);

        outline = new Path();
        outline.Stroke = Brushes.Blue;
        outline.StrokeThickness = 1;

        visualChildren.Add(outline);
        visualChildren.Add(rotateHandle);

        strokeBounds = AdornedStrokes.GetBounds();
    }

    /// <summary>
    /// Draw the rotation handle and the outline of
    /// the element.
    /// </summary>
    /// <param name="finalSize">The final area within the 
    /// parent that this element should use to arrange 
    /// itself and its children.</param>
    /// <returns>The actual size used. </returns>
    protected override Size ArrangeOverride(Size finalSize)
    {
        if (strokeBounds.IsEmpty)
        {
            return finalSize;
        }

        center = new Point(strokeBounds.X + strokeBounds.Width / 2,
                           strokeBounds.Y + strokeBounds.Height / 2);

        // The rectangle that determines the position of the Thumb.
        Rect handleRect = new Rect(strokeBounds.X,
                              strokeBounds.Y - (strokeBounds.Height / 2 +
                                                HANDLEMARGIN),
                              strokeBounds.Width, strokeBounds.Height);

        if (rotation != null)
        {
            handleRect.Transform(rotation.Value);
        }

        // Draws the thumb and the rectangle around the strokes.
        rotateHandle.Arrange(handleRect);
        outline.Data = new RectangleGeometry(strokeBounds);
        outline.Arrange(new Rect(finalSize));
        return finalSize;
    }

    /// <summary>
    /// Rotates the rectangle representing the
    /// strokes' bounds as the user drags the
    /// Thumb.
    /// </summary>
    void rotateHandle_DragDelta(object sender, DragDeltaEventArgs e)
    {
        // Find the angle of which to rotate the shape.  Use the right
        // triangle that uses the center and the mouse's position 
        // as vertices for the hypotenuse.

        Point pos = Mouse.GetPosition(this);

        double deltaX = pos.X - center.X;
        double deltaY = pos.Y - center.Y;

        if (deltaY.Equals(0))
        {

            return;
        }

        double tan = deltaX / deltaY;
        double angle = Math.Atan(tan);

        // Convert to degrees.
        angle = angle * 180 / Math.PI;

        // If the mouse crosses the vertical center, 
        // find the complementary angle.
        if (deltaY > 0)
        {
            angle = 180 - Math.Abs(angle);
        }

        // Rotate left if the mouse moves left and right
        // if the mouse moves right.
        if (deltaX < 0)
        {
            angle = -Math.Abs(angle);
        }
        else
        {
            angle = Math.Abs(angle);
        }

        if (Double.IsNaN(angle))
        {
            return;
        }

        // Apply the rotation to the strokes' outline.
        rotation = new RotateTransform(angle, center.X, center.Y);
        outline.RenderTransform = rotation;
    }

    /// <summary>
    /// Rotates the strokes to the same angle as outline.
    /// </summary>
    void rotateHandle_DragCompleted(object sender,
                                    DragCompletedEventArgs e)
    {
        if (rotation == null)
        {
            return;
        }

        // Rotate the strokes to match the new angle.
        Matrix mat = new Matrix();
        mat.RotateAt(rotation.Angle - lastAngle, center.X, center.Y);
        AdornedStrokes.Transform(mat, true);

        // Save the angle of the last rotation.
        lastAngle = rotation.Angle;

        // Redraw rotateHandle.
        this.InvalidateArrange();
    }

    /// <summary>
    /// Gets the strokes of the adorned element 
    /// (in this case, an InkPresenter).
    /// </summary>
    private StrokeCollection AdornedStrokes
    {
        get
        {
            return ((InkPresenter)AdornedElement).Strokes;
        }
    }

    // Override the VisualChildrenCount and 
    // GetVisualChild properties to interface with 
    // the adorner's visual collection.
    protected override int VisualChildrenCount
    {
        get { return visualChildren.Count; }
    }

    protected override Visual GetVisualChild(int index)
    {
        return visualChildren[index];
    }
}
```

下面的示例是可扩展应用程序标记语言 (XAML)定义文件[InkPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkpresenter)墨迹并用其填充它。 `Window_Loaded`事件处理程序会添加到自定义的装饰器[InkPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.inkpresenter)。

XAML复制

```xaml
<Window x:Class="Window1"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    Title="Rotating Strokes Adorner" Height="500" Width="500"
    Loaded="Window_Loaded"
    >
  <InkPresenter Name="inkPresenter1" >
    <InkPresenter.Strokes>
      ALMDAwRIEEU1BQE4GSAyCQD0/wIB6SI6RTMJAPifAgFaIDpFOAgA/gMAAACAfxEAAIA/
      HwkRAAAAAAAA8D8KlwE1h/CPd4SB4NA4OicCjcGjcClcDj8Lh8DgUSkUmmU6nUmoUuk
      0ukUCQKVyehz+rzuly+bzORx+BReRQ+RTaRCH8JyXhPbgcPicPh8Pg8Oh0qk1SoVGrV
      Oo0mi0Xi8rm9Xr9Dqc/p87pc/k8XicHicOj1CoVKtVmv1GqUaiUHlYg8el4akXK7m7T
      cSJgQgghEyym5zx6+PACk4dhPwg/fhCbxY8dp4p2tqnqxyvbPO85z1X1aswhvCd94Tq
      55DRUGi4+Tk6OLn4KLkoOejo6ig5KTioOPCD9LlHmrzNxMRCCc3ec8+fe4AKQBmE/Cw
      9+FkPNvlOdkrYsWa+acp3Z8erOIT8JaX4S6+FbFilbHNvvPXNJbFqluxghKc5DkwrVF
      GEEIJ1w5eLKYAKShuF+Dnr4Oa8HVHXNPFFFFho8VFkqsMRYuuvJxiF+F9r4Xx8HFiqs
      FNcirnweDw9+LvvvixdV0+GhONmlj3wjNOcSCEYTnfLy4oA
    </InkPresenter.Strokes>
    </InkPresenter>
</Window>
```

C#复制

```csharp
void Window_Loaded(object sender, RoutedEventArgs e)
{
    // Add the rotating strokes adorner to the InkPresenter.
    adornerLayer = AdornerLayer.GetAdornerLayer(inkPresenter1);
    adorner = new RotatingStrokesAdorner(inkPresenter1);

    adornerLayer.Add(adorner);
}
```

### [Disable the RealTimeStylus for WPF Applications](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/disable-the-realtimestylus-for-wpf-applications)

Windows Presentation Foundation (WPF) 提供了内置支持来处理 Windows 7 触控输入。这种支持是通过为 tablet 平台的实时触笔输入[OnStylusDown](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.onstylusdown)， [OnStylusUp](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.onstylusup)，和[OnStylusMove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.onstylusmove)事件。 Windows 7 还提供了作为 Win32 WM_TOUCH 窗口消息的多点触控输入。 这两个 Api 上的同一个 HWND 互相排斥。 启用触控输入通过 tablet 平台 （WPF 应用程序的默认值） 禁用 WM_TOUCH 消息。 因此，若要使用 WM_TOUCH 从 WPF 窗口接收触控消息，则必须禁用在 WPF 中的内置触笔支持。 此选项适用于使用 WM_TOUCH 组件宿主的 WPF 窗口类似的情况。

若要禁用 WPF 笔针输入到侦听，删除了由 WPF 窗口添加任何平板电脑支持。

下面的示例代码演示如何使用反射删除默认 tablet 平台支持。

复制

```
public static void DisableWPFTabletSupport()  
{  
    // Get a collection of the tablet devices for this window.    
    TabletDeviceCollection devices = System.Windows.Input.Tablet.TabletDevices;  
  
    if (devices.Count > 0)  
    {     
        // Get the Type of InputManager.  
        Type inputManagerType = typeof(System.Windows.Input.InputManager);  
  
        // Call the StylusLogic method on the InputManager.Current instance.  
        object stylusLogic = inputManagerType.InvokeMember("StylusLogic",  
                    BindingFlags.GetProperty | BindingFlags.Instance | BindingFlags.NonPublic,  
                    null, InputManager.Current, null);  
  
        if (stylusLogic != null)  
        {  
            //  Get the type of the stylusLogic returned from the call to StylusLogic.  
            Type stylusLogicType = stylusLogic.GetType();  
  
            // Loop until there are no more devices to remove.  
            while (devices.Count > 0)  
            {  
                // Remove the first tablet device in the devices collection.  
                stylusLogicType.InvokeMember("OnTabletRemoved",  
                        BindingFlags.InvokeMethod | BindingFlags.Instance | BindingFlags.NonPublic,  
                        null, stylusLogic, new object[] { (uint)0 });  
            }                  
        }  
  
    }  
}  
```