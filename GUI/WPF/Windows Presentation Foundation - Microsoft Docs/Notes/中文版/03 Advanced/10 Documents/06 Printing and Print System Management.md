# [Printing and Print System Management](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/printing-and-print-system-management)

Windows Vista 和 Microsoft.NET Framework 引入新的打印路径 — 一种替代方法Microsoft Windows 图形设备接口 (GDI)打印 — 和大幅扩展了打印系统管理集API。

[打印概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/printing-overview)
新的打印路径的讨论和API。

[帮助主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/printing-how-to-topics)
一组文章演示如何使用新的打印路径和API。

## [Printing Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/printing-overview)

使用 Microsoft.NET Framework 中，使用 Windows Presentation Foundation (WPF) 应用程序开发人员拥有丰富的打印和打印系统管理新API。 在 Windows Vista 中，还为创建 Windows 窗体 应用程序的开发人员和使用非托管代码的开发人员提供了这些打印系统增强功能中的某些功能。 此新功能的核心是新的 XML 纸张规范 (XPS) 文件格式和 XPS 打印路径。

本主题包含以下各节：

### 关于 XPS

XPS 是电子文档格式（即后台打印文件格式），并且采用的是页面描述语言。 此格式是开放文档格式，它使用XML、开放式打包约定 (OPC) 及其他行业标准来创建跨平台的文档。 XPS 简化了创建、共享、打印、查看和存档数字文档的流程。 有关 XPS 的其他信息，请参阅 [XPS 网站](https://www.microsoft.com/xps)。

[以编程方式打印 XPS 文件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-programmatically-print-xps-files)中演示了使用 WPF 打印基于 XPS 的内容的几种方法。 在查看本主题中的内容时，参考这些示例会很有帮助。 (非托管的代码开发人员应参阅文档[MXDC_ESCAPE 函数](https://msdn.microsoft.com/library/windows/desktop/dd162739.aspx)。 Windows 窗体开发人员必须使用API中[System.Drawing.Printing](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.printing)命名空间不支持完整XPS打印路径，但支持 GDI 到 XPS 的混合打印路径。 请参阅下面的**打印路径体系结构**。）

### XPS 打印路径

XML 纸张规范 (XPS)打印路径是一种新Windows重新定义如何在 Windows 应用程序中处理打印的功能。 因为 XPS 可以替换文档表示语言（如 RTF）、打印后台处理程序格式（如 WMF）和页面描述语言（如 PCL 和 Postscript），所以在打印机驱动程序或设备中，从应用程序发布到最终处理，新的打印路径都保持 XPS 格式。

XPS 打印路径是基于 XPS 打印机驱动程序模型 (XPSDrv) 生成的，该模型为开发人员带来了多个优点，如 “所见即所得”(WYSIWYG) 打印、改进了颜色支持以及大大提高了打印性能。 （有关 XPSDrv 的详细信息，请参阅 [Windows 驱动程序开发工具包](https://msdn.microsoft.com/library/windows/hardware/ff557573.aspx)。）

有关打印后台处理程序的操作XPS文档实质上是与以前版本的 Windows 中的相同。 但是，它已得到增强，除了现有的 XPS 打印路径外，还支持 GDI 打印路径。 新的打印路径在本机使用 XPS 后台打印文件。 虽然为 Windows 的之前版本编写的用户模式打印机驱动程序将继续运行，但仍需要 XPS 打印机驱动程序 (XPSDrv)，以便使用 XPS 打印路径。

XPS 打印路径的优势巨大，其中包括：

- WYSIWYG 打印支持
- 对高级颜色配置文件的本机支持（包括 32 位/通道 (bpc)、CMYK、已命名的颜色、n 墨迹）以及对透明和渐变的本机支持。
- 改进的打印性能的同时在.NET Framework 和Win32基于应用程序。
- 行业标准 XPS 格式。

对于基本打印方案，提供了简单直观的 API只需单一入口点即可进入用户界面、完成配置和作业提交。 对于高级方案，为 用户界面 (UI) 自定义（或根本没有 UI）、同步或异步打印以及批量打印功能添加了附加支持。 这两个选项在完全或部分信任模式下都提供打印支持。

XPS 的设计充分考虑了扩展性。 使用扩展性框架，可以将特性和功能以模块化方式添加到 XPS 中。 扩展性功能包括：

- 打印架构。 公共架构将定期进行更新，并可以实现设备功能的迅速扩展。 （请参阅下面的 **PrintTicket 和 PrintCapabilities**。）
- 可扩展筛选器管道。 XPS 打印机驱动程序 (XPSDrv) 筛选器管道设计用于启用直接和可缩放的 XPS 文档打印。 (查找"XPSDrv"中的[Windows 驱动程序工具包](https://msdn.microsoft.com/library/windows/hardware/ff557573.aspx)。)

#### 打印路径体系结构

虽然两个Win32.NET Framework 应用程序都支持XPS，Win32和 Windows 窗体应用程序使用GDI到XPS转换来创建XPS格式的内容对于XPS打印机驱动程序 (XPSDrv)。 不要求这些应用程序使用 XPS 打印路径，而可以继续使用基于 增强型图元文件 (EMF) 的打印。 但是，大多数 XPS 功能和增强功能仅可用于面向 XPS 打印路径的应用程序。

若要启用使用的基于 XPSDrv 的打印机Win32和 Windows 窗体应用程序XPS打印机驱动程序 (XPSDrv) 支持的转换GDI到XPS格式。 XPSDrv 模型还提供从 XPS 到 GDI 格式的转换器，以便 Win32 应用程序能够打印 XPS 文档。 有关WPF应用程序、 转换XPS到GDI会自动完成格式[Write](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.xps.xpsdocumentwriter.write)和[WriteAsync](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.xps.xpsdocumentwriter.writeasync)方法[XpsDocumentWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.xps.xpsdocumentwriter)类只要写操作的目标打印队列没有XPSDrv 驱动程序。 (Windows 窗体应用程序不能打印XPS文档。)

下图描述了打印子系统，并定义了 Microsoft 提供的部分以及由软件和硬件供应商定义的部分。

![XPS 打印系统](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/xpsprint.png)

#### 基本 XPS 打印

WPF 定义基本和高级 API。 对于不需要各种打印自定义或对 XPS 完整功能集的访问权限的应用程序，可以提供基本打印支持。 基本打印支持通过一个打印对话框控件公开，该控件要求最低的配置，并采用熟悉的 UI。 可以通过此简化的打印模型来使用众多 XPS 功能。

##### PrintDialog

[System.Windows.Controls.PrintDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.printdialog) 控件为 UI、配置和 XPS 作业提交提供单一入口点。 若要了解如何实例化和使用该控件，请参阅[调用打印对话框](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-invoke-a-print-dialog)。

#### 高级 XPS 打印

若要访问完整的 XPS 功能集、必须使用高级打印 API。 下面更详细地介绍了几个相关的 API。 有关完整列表XPS打印路径API，请参阅[System.Windows.Xps](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.xps)和[System.Printing](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing)命名空间的引用。

##### PrintTicket 和 PrintCapabilities

[PrintTicket](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printticket)并[PrintCapabilities](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printcapabilities)类是高级基础XPS功能。 这两种类型的对象均是面向打印的功能（例如排序规则、双面打印、装订等）的 XML 格式的结构。这些结构由打印架构定义。 [PrintTicket](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printticket) 指示打印机如何处理打印作业。 [PrintCapabilities](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printcapabilities) 类定义打印机的各种功能。 通过查询打印机的功能，可以创建充分利用打印机的受支持功能的 [PrintTicket](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printticket)。 同样，可以避免不受支持的功能。

下面的示例演示如何使用代码查询打印机的 [PrintCapabilities](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printcapabilities) 和创建 [PrintTicket](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printticket)。

C#复制

```csharp
// ---------------------- GetPrintTicketFromPrinter -----------------------
/// <summary>
///   Returns a PrintTicket based on the current default printer.</summary>
/// <returns>
///   A PrintTicket for the current local default printer.</returns>
private PrintTicket GetPrintTicketFromPrinter()
{
    PrintQueue printQueue = null;

    LocalPrintServer localPrintServer = new LocalPrintServer();

    // Retrieving collection of local printer on user machine
    PrintQueueCollection localPrinterCollection =
        localPrintServer.GetPrintQueues();

    System.Collections.IEnumerator localPrinterEnumerator =
        localPrinterCollection.GetEnumerator();

    if (localPrinterEnumerator.MoveNext())
    {
        // Get PrintQueue from first available printer
        printQueue = (PrintQueue)localPrinterEnumerator.Current;
    }
    else
    {
        // No printer exist, return null PrintTicket
        return null;
    }

    // Get default PrintTicket from printer
    PrintTicket printTicket = printQueue.DefaultPrintTicket;

    PrintCapabilities printCapabilites = printQueue.GetPrintCapabilities();

    // Modify PrintTicket
    if (printCapabilites.CollationCapability.Contains(Collation.Collated))
    {
        printTicket.Collation = Collation.Collated;
    }

    if ( printCapabilites.DuplexingCapability.Contains(
            Duplexing.TwoSidedLongEdge) )
    {
        printTicket.Duplexing = Duplexing.TwoSidedLongEdge;
    }

    if (printCapabilites.StaplingCapability.Contains(Stapling.StapleDualLeft))
    {
        printTicket.Stapling = Stapling.StapleDualLeft;
    }

    return printTicket;
}// end:GetPrintTicketFromPrinter()
```

##### PrintServer 和 PrintQueue

[PrintServer](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printserver) 类表示一个网络打印服务器，而 [PrintQueue](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue) 类则表示一台打印机以及与其关联的输出作业队列。 结合使用这些 API，可以对服务器的打印作业进行高级管理。 [PrintServer](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printserver) 或其派生类之一用于管理 [PrintQueue](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue)。[AddJob](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.addjob) 方法用于将新的打印作业插入队列。

下面的示例演示如何使用代码创建 [LocalPrintServer](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.localprintserver) 和访问其默认的 [PrintQueue](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue)。

C#复制

```csharp
// -------------------- GetPrintXpsDocumentWriter() -------------------
/// <summary>
///   Returns an XpsDocumentWriter for the default print queue.</summary>
/// <returns>
///   An XpsDocumentWriter for the default print queue.</returns>
private XpsDocumentWriter GetPrintXpsDocumentWriter()
{
    // Create a local print server
    LocalPrintServer ps = new LocalPrintServer();

    // Get the default print queue
    PrintQueue pq = ps.DefaultPrintQueue;

    // Get an XpsDocumentWriter for the default print queue
    XpsDocumentWriter xpsdw = PrintQueue.CreateXpsDocumentWriter(pq);
    return xpsdw;
}// end:GetPrintXpsDocumentWriter()
```

##### XpsDocumentWriter

[XpsDocumentWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.xps.xpsdocumentwriter) 及其众多 [Write](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.xps.xpsdocumentwriter.write) 和 [WriteAsync](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.xps.xpsdocumentwriter.writeasync) 方法用于将 XPS 文档写入 [PrintQueue](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue)。 例如，[Write(FixedPage, PrintTicket)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.xps.xpsdocumentwriter.write#System_Windows_Xps_XpsDocumentWriter_Write_System_Windows_Documents_FixedPage_System_Printing_PrintTicket_) 方法用于同步输出 XPS 文档和 [PrintTicket](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printticket)。 [WriteAsync(FixedDocument, PrintTicket)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.xps.xpsdocumentwriter.writeasync#System_Windows_Xps_XpsDocumentWriter_WriteAsync_System_Windows_Documents_FixedDocument_System_Printing_PrintTicket_) 方法用于异步输出 XPS 文档和 [PrintTicket](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printticket)。

下面的示例演示如何使用代码创建 [XpsDocumentWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.xps.xpsdocumentwriter)。

```csharp
// -------------------- GetPrintXpsDocumentWriter() -------------------
/// <summary>
///   Returns an XpsDocumentWriter for the default print queue.</summary>
/// <returns>
///   An XpsDocumentWriter for the default print queue.</returns>
private XpsDocumentWriter GetPrintXpsDocumentWriter()
{
    // Create a local print server
    LocalPrintServer ps = new LocalPrintServer();

    // Get the default print queue
    PrintQueue pq = ps.DefaultPrintQueue;

    // Get an XpsDocumentWriter for the default print queue
    XpsDocumentWriter xpsdw = PrintQueue.CreateXpsDocumentWriter(pq);
    return xpsdw;
}// end:GetPrintXpsDocumentWriter()
```

[AddJob](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.addjob) 方法还提供打印方法。 请参阅[以编程方式打印 XPS 文件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-programmatically-print-xps-files)。 了解详细信息。



### GDI 打印路径

虽然WPF应用程序以本机方式支持XPS打印路径Win32和 Windows 窗体应用程序还可以充分利用一些XPS功能。XPS 打印机驱动程序 (XPSDrv) 可以将基于 GDI 的输出转换为 XPS 格式。 对于高级方案，自定义内容转换为支持使用[Microsoft XPS 文档转换器 (MXDC)](https://msdn.microsoft.com/library/windows/desktop/ff686803.aspx)。 同样，WPF应用程序也可以输出到GDI打印路径，方法是调用之一[Write](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.xps.xpsdocumentwriter.write)或[WriteAsync](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.xps.xpsdocumentwriter.writeasync)方法的[XpsDocumentWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.xps.xpsdocumentwriter)类，并将非 XpsDrv 打印机指定为目标打印队列。

对于不需要 XPS 功能或支持的应用程序，当前的 GDI 打印路径保持不变。

- 有关其他参考资料GDI打印路径和各种XPS转换选项，请参见[Microsoft XPS 文档转换器 (MXDC)](https://msdn.microsoft.com/library/windows/desktop/ff686803.aspx)和中的"XPSDrv" [Windows Driver Kit](https://msdn.microsoft.com/library/windows/hardware/ff557573.aspx).

### XPSDrv 驱动程序模型

在打印到支持 XPS 的打印机或驱动程序时，XPS 打印路径将 XPS 用作本机打印后台处理格式，从而提高打印后台处理程序的效率。 简化后的后台打印处理消除了在后台打印文档之前生成中间后台打印文件（如 EMF 数据文件）的必要。 通过减小后台打印文件的大小，XPS 打印路径可以减少网络流量并提高打印性能。

EMF 是一种封闭格式，它将应用程序输出表示为对呈现服务的 GDI 进行的一系列调用。 与 EMF 不同的是，XPS后台打印格式呈现实际的文档，而无需在输出到基于 XPS 的打印机驱动程序 (XPSDrv) 时进行进一步的转译。 这些驱动程序可以用这种格式直接对数据进行操作。 此功能消除了在使用 EMF 文件和基于 GDI 的打印驱动程序时所需的数据和颜色空间转换。

当使用面向 XPS 打印机驱动程序 (XPSDrv) 的XPS 文档时，与其 EMF 等效项相比，后台打印文件的大小通常更小；不过，也存在例外情况：

- 相当复杂、分为多层或者编写效率低下的向量图形可能比同一图形的位图图形更大。
- 出于屏幕显示的目的，XPS 文件中嵌入了设备字体以及基于计算机的字体，而 GDI 打印后台文件未嵌入设备字体。 这两种字体都划分了子集（请参见下面的内容），而且打印机驱动程序可以在将文件传输给打印机之前删除这些设备字体。

可通过几种机制来减小后台打印文件的大小：

- **字体子集划分**。 只有在实际的文档中使用的字符才存储在 XPS 文件中。
- **高级图形支持**。 对透明和渐变基元的本机支持可避免 XPS 文档中的内容光栅化。
- **公共资源的识别**。 将多次使用的资源（如表示公司徽标的图像）视为共享资源，并且只加载一次。
- **ZIP 压缩**。 所有 XPS 文档均使用 ZIP 压缩。

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/printing-how-to-topics)

在本部分中的主题演示如何使用打印和打印系统管理功能附带Windows Presentation Foundation (WPF)以及新XML 纸张规范 (XPS)打印路径。

[调用打印对话框](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-invoke-a-print-dialog)
有关 XAML 标记声明的说明Microsoft Windows打印对话框对象和使用代码来调用 Windows Presentation Foundation (WPF) 应用程序中的对话框。

[克隆打印机](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-clone-a-printer)
说明如何使用完全相同的属性的现有安装的第二个打印队列的打印队列。

[诊断有问题的打印作业](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-diagnose-problematic-print-job)
使用打印队列和打印作业的属性来诊断不打印打印作业的说明。

[确定此时能否打印打印作业](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-discover-whether-a-print-job-can-be-printed-at-this-time-of-day)
可以打印作业使用的打印队列和打印作业的属性以编程方式确定的时间的说明。

[枚举一部分打印队列](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-enumerate-a-subset-of-print-queues)
生成具有某些特征的打印机列表的说明。

[NOTINBUILD:如何：扩展的打印架构并创建新的打印系统类](https://msdn.microsoft.com/library/a3600218-1ea5-478a-9853-6560464f2885)
深入的讨论如何将托管代码编程人员可以扩展到特殊打印设备或添加新的或不常见功能的打印机的打印架构。

[在不使用反射的情况下获取打印系统对象属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-get-print-system-object-properties-without-reflection)
有关如何在运行时发现的说明打印系统对象的属性和它们的类型。

[以编程方式打印 XPS 文件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-programmatically-print-xps-files)
有关快速进行打印的说明XML 纸张规范 (XPS)文件而无需用户界面 (UI)。

[远程调查打印机的状态](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-remotely-survey-the-status-of-printers)
创建一个实用程序，将调查打印机可发现遇到纸或其他问题的说明。

[验证和合并 PrintTicket](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-validate-and-merge-printtickets)
有关签入的打印票证有效，并且，它不会不请求打印机不支持的任何内容的说明。

### [Invoke a Print Dialog](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-invoke-a-print-dialog)

若要提供从你应用程序打印的功能，可以只需创建和打开[PrintDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.printdialog)对象。

[PrintDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.printdialog) 控件为 UI、配置和 XPS 作业提交提供单一入口点。 该控件是易于使用，可以通过使用实例化可扩展应用程序标记语言 (XAML)标记或代码。 下面的示例演示如何实例化并在 code 中打开该控件以及如何从其打印。它还演示如何以确保设置特定范围的页面的选项的对话框会给用户。 此代码示例假定 c： 驱动器的根目录中的文件 FixedDocumentSequence.xps。

C#复制

```csharp
private void InvokePrint(object sender, RoutedEventArgs e)
    {
        // Create the print dialog object and set options
        PrintDialog pDialog = new PrintDialog();
        pDialog.PageRangeSelection = PageRangeSelection.AllPages;
        pDialog.UserPageRangeEnabled = true;

        // Display the dialog. This returns true if the user presses the Print button.
        Nullable<Boolean> print = pDialog.ShowDialog();
        if (print == true)
        {
            XpsDocument xpsDocument = new XpsDocument("C:\\FixedDocumentSequence.xps", FileAccess.ReadWrite);
            FixedDocumentSequence fixedDocSeq = xpsDocument.GetFixedDocumentSequence();
            pDialog.PrintDocument(fixedDocSeq.DocumentPaginator, "Test print job");
        }
    }
```

打开对话框后，用户将能够从他们的计算机上安装的打印机中选择。 此外将选择的选项[Microsoft XPS Document Writer](https://go.microsoft.com/fwlink/?LinkId=147319)若要创建XML 纸张规范 (XPS)文件而不是打印。

> [System.Windows.Controls.PrintDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.printdialog)控制WPF，本主题中对其进行讨论不应混淆与[System.Windows.Forms.PrintDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.printdialog)Windows 窗体的组件。

严格地说，您可以使用[PrintDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.printdialog.printdocument)甚至不用打开对话框的方法。 在此意义上，控件可用作不可见的打印组件。 但出于性能原因，它会更好的做法可以使用两种[AddJob](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.addjob)方法或多个[Write](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.xps.xpsdocumentwriter.write)并[WriteAsync](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.xps.xpsdocumentwriter.writeasync)方法的[XpsDocumentWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.xps.xpsdocumentwriter)。 有关详细信息，请参阅[以编程方式打印 XPS 文件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-programmatically-print-xps-files)和。

### [Clone a Printer](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-clone-a-printer)

大多数企业都在某些时候，将购买的同一模型的多台打印机。 通常情况下，这些进行所有安装使用几乎完全相同的配置设置。 安装每个打印机可能非常耗时且容易出错。 [System.Printing.IndexedProperties](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.indexedproperties)命名空间和[InstallPrintQueue](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printserver.installprintqueue)都通过 Microsoft.NET Framework 公开的类可以立即从现有的打印队列安装任意数目的克隆的其他打印队列。

在下面的示例中，第二个打印队列进行克隆现有的打印队列。 第二个与前者区别仅在其名称、 位置、 端口和共享的状态中。 执行此操作的主要步骤如下所示。

1. 创建[PrintQueue](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue)现有打印机要克隆的对象。

2. 创建[PrintPropertyDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.indexedproperties.printpropertydictionary)从[PropertiesCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printsystemobject.propertiescollection)的[PrintQueue](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue)。 [Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.dictionaryentry.value)此字典中的每个条目的属性是一个派生自的类型的一个对象[PrintProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.indexedproperties.printproperty)。 有两种方法来设置此字典中的条目的值。

   - 使用字典**删除**和[Add](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.indexedproperties.printpropertydictionary.add)方法来删除该项，然后重新将其添加具有所需的值。
   - 使用字典的[SetProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.indexedproperties.printpropertydictionary.setproperty)方法。

   下面的示例说明了这两种方式。

3. 创建[PrintBooleanProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.indexedproperties.printbooleanproperty)对象，并将其[Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.indexedproperties.printproperty.name)到"IsShared"并将其[Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.indexedproperties.printbooleanproperty.value)到`true`。

4. 使用[PrintBooleanProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.indexedproperties.printbooleanproperty)对象的值[PrintPropertyDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.indexedproperties.printpropertydictionary)的"IsShared"条目。

5. 创建[PrintStringProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.indexedproperties.printstringproperty)对象，并将其[Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.indexedproperties.printproperty.name)到"共享名"并将其[Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.indexedproperties.printstringproperty.value)对相应[String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)。

6. 使用[PrintStringProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.indexedproperties.printstringproperty)对象的值[PrintPropertyDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.indexedproperties.printpropertydictionary)的"共享名"条目。

7. 创建另一个[PrintStringProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.indexedproperties.printstringproperty)对象，并将其[Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.indexedproperties.printproperty.name)到"位置"并将其[Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.indexedproperties.printstringproperty.value)对相应[String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)。

8. 使用第二个[PrintStringProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.indexedproperties.printstringproperty)对象的值[PrintPropertyDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.indexedproperties.printpropertydictionary)的"位置"条目。

9. 创建一个数组[String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)s。 每个项是端口的在服务器上的名称。

10. 使用[InstallPrintQueue](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printserver.installprintqueue)以使用新值进行安装新的打印机。

下面是一个示例。

C#复制

```csharp
LocalPrintServer myLocalPrintServer = new LocalPrintServer(PrintSystemDesiredAccess.AdministrateServer);
PrintQueue sourcePrintQueue = myLocalPrintServer.DefaultPrintQueue;
PrintPropertyDictionary myPrintProperties = sourcePrintQueue.PropertiesCollection;

// Share the new printer using Remove/Add methods
PrintBooleanProperty shared = new PrintBooleanProperty("IsShared", true);
myPrintProperties.Remove("IsShared");
myPrintProperties.Add("IsShared", shared);

// Give the new printer its share name using SetProperty method
PrintStringProperty theShareName = new PrintStringProperty("ShareName", "\"Son of " + sourcePrintQueue.Name +"\"");
myPrintProperties.SetProperty("ShareName", theShareName);

// Specify the physical location of the new printer using Remove/Add methods
PrintStringProperty theLocation = new PrintStringProperty("Location", "the supply room");
myPrintProperties.Remove("Location");
myPrintProperties.Add("Location", theLocation);

// Specify the port for the new printer
String[] port = new String[] { "COM1:" };


// Install the new printer on the local print server
PrintQueue clonedPrinter = myLocalPrintServer.InstallPrintQueue("My clone of " + sourcePrintQueue.Name, "Xerox WCP 35 PS", port, "WinPrint", myPrintProperties);
myLocalPrintServer.Commit();

// Report outcome
Console.WriteLine("{0} in {1} has been installed and shared as {2}", clonedPrinter.Name, clonedPrinter.Location, clonedPrinter.ShareName);
Console.WriteLine("Press Return to continue ...");
Console.ReadLine();
```

### [Diagnose Problematic Print Job](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-diagnose-problematic-print-job)

网络管理员经常接收到有关打印作业无法打印或打印速度慢的用户投诉。 丰富的打印作业属性中公开API的 Microsoft.NET Framework 提供了一种方法用于执行快速的打印作业远程诊断。

以下是创建此类实用程序的主要步骤。

1. 标识用户投诉的打印作业。 用户通常无法准确完成此操作。 他们可能不知道打印服务器或打印机的名称。它们可能不是设置中使用的描述不同的术语中的打印机的位置及其[Location](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.location)属性。 这样的话，一个好办法是生成用户当前所提交作业的列表。 如果存在多个作业，则可通过用户和打印系统管理员之间的通信来查明出现问题的作业。 子步骤如下。
   1. 获取所有打印服务器的列表。
   2. 循环访问服务器以查询其打印队列。
   3. 在每一轮服务器循环访问过程中，循环访问所有服务器的队列，以查询其作业
   4. 在每一轮服务器循环访问过程中，循环访问其作业，并收集与投诉用户已提交的作业相关的标识信息。
2. 当已识别有问题的打印作业时，检查相关属性以查明可能的问题。 例如，作业是否处于错误状态，或服务于队列的打印机是否在打印该作业之前处于脱机状态？

以下代码是一系列代码示例。 第一个代码示例包含针对打印队列的循环访问操作。 （以上步骤 1c。）在变量`myPrintQueues`是[PrintQueueCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueuecollection)当前打印服务器对象。

该代码示例开始先刷新当前打印队列对象与[PrintQueue.Refresh](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.refresh)。 这可确保该对象的属性能够准确表示它所表示的物理打印机的状态。 然后，应用程序获取打印作业的集合当前打印队列中通过使用[GetPrintJobInfoCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.getprintjobinfocollection)。

接下来，应用程序会遍历[PrintSystemJobInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printsystemjobinfo)集合进行比较每个[Submitter](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printsystemjobinfo.submitter)属性与投诉用户的别名。 如果属性和别名相匹配，则应用程序会将有关该作业的标识信息添加到将呈现的字符串。 （`userName` 和 `jobList` 变量在应用程序早期进行初始化。）

C#复制

```csharp
foreach (PrintQueue pq in myPrintQueues)
{
    pq.Refresh();
    PrintJobInfoCollection jobs = pq.GetPrintJobInfoCollection();
    foreach (PrintSystemJobInfo job in jobs)
    {
        // Since the user may not be able to articulate which job is problematic,
        // present information about each job the user has submitted.
        if (job.Submitter == userName)
        {
            atLeastOne = true;
            jobList = jobList + "\nServer:" + line;
            jobList = jobList + "\n\tQueue:" + pq.Name;
            jobList = jobList + "\n\tLocation:" + pq.Location;
            jobList = jobList + "\n\t\tJob: " + job.JobName + " ID: " + job.JobIdentifier;
        }
    }// end for each print job    

}// end for each print queue
```

下一代码示例在步骤 2 提取应用程序。 （请参阅上文。）已标识有问题的作业，应用程序会提示提供用于标识该作业的信息。 此信息从它创建[PrintServer](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printserver)， [PrintQueue](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue)，和[PrintSystemJobInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printsystemjobinfo)对象。

此时，应用程序包含一个分支结构，该结构对应于检查打印作业状态的两种方法：

- 可以读取的标志[JobStatus](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printsystemjobinfo.jobstatus)属性的类型即[PrintJobStatus](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printjobstatus)。
- 你可以读取每个相关属性，如[IsBlocked](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printsystemjobinfo.isblocked)和[IsInError](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printsystemjobinfo.isinerror)。

此示例演示这两种方法，因此该用户之前进行提示要使用的方法并回复"Y"，如果他或她想要使用的标志[JobStatus](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printsystemjobinfo.jobstatus)属性。 请参阅以下有关这两种方法的详细信息。 最后，该应用程序使用一种名为 **ReportQueueAndJobAvailability** 的方法来报告是否可以在一天的此时打印该作业。 [确定此时是否可以打印一项打印作业](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-discover-whether-a-print-job-can-be-printed-at-this-time-of-day)中就此方法进行了讨论。

C#复制

```csharp
// When the problematic print job has been identified, enter information about it.
Console.Write("\nEnter the print server hosting the job (including leading slashes \\\\): " +
"\n(press Return for the current computer \\\\{0}): ", Environment.MachineName);
String pServer = Console.ReadLine();
if (pServer == "")
{
    pServer = "\\\\" +Environment.MachineName;
}
Console.Write("\nEnter the print queue hosting the job: ");
String pQueue = Console.ReadLine(); 
Console.Write("\nEnter the job ID: ");
Int16 jobID = Convert.ToInt16(Console.ReadLine());

// Create objects to represent the server, queue, and print job.
PrintServer hostingServer = new PrintServer(pServer, PrintSystemDesiredAccess.AdministrateServer);
PrintQueue hostingQueue = new PrintQueue(hostingServer, pQueue, PrintSystemDesiredAccess.AdministratePrinter);
PrintSystemJobInfo theJob = hostingQueue.GetJob(jobID);

if (useAttributesResponse == "Y")
{
    TroubleSpotter.SpotTroubleUsingJobAttributes(theJob);
    // TroubleSpotter class is defined in the complete example.
}
else
{
    TroubleSpotter.SpotTroubleUsingProperties(theJob);
}

TroubleSpotter.ReportQueueAndJobAvailability(theJob);
```

若要使用的标志检查打印作业状态[JobStatus](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printsystemjobinfo.jobstatus)属性，检查每个相关标志以查看它是否设置。 检查是否在一组位标志中设置了一个位的标准方法是执行一个逻辑 AND 运算，其中将该组标志作为一个操作数，将标志本身作为另一操作数。 由于该标志本身仅设置一个位，因此逻辑 AND 的结果至多为设置了该相同位。 若要查明事实是否如此，只需将逻辑 AND 的结果与标志本身进行比较。 有关详细信息，请参阅[PrintJobStatus](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printjobstatus)，则[& 运算符 (C#引用)](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/and-operator)，并[FlagsAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.flagsattribute)。

对于已设置了其位的每个属性，代码会将此报告给控制台屏幕，有时还会建议如何响应。 （下面讨论了作业或队列暂停时所调用的 **HandlePausedJob** 方法。）

C#复制

```csharp
// Check for possible trouble states of a print job using the flags of the JobStatus property
internal static void SpotTroubleUsingJobAttributes(PrintSystemJobInfo theJob)
{
    if ((theJob.JobStatus & PrintJobStatus.Blocked) == PrintJobStatus.Blocked)
    {
        Console.WriteLine("The job is blocked.");
    }
    if (((theJob.JobStatus & PrintJobStatus.Completed) == PrintJobStatus.Completed)
        || 
        ((theJob.JobStatus & PrintJobStatus.Printed) == PrintJobStatus.Printed))
    {
        Console.WriteLine("The job has finished. Have user recheck all output bins and be sure the correct printer is being checked.");
    }
    if (((theJob.JobStatus & PrintJobStatus.Deleted) == PrintJobStatus.Deleted)
        || 
        ((theJob.JobStatus & PrintJobStatus.Deleting) == PrintJobStatus.Deleting))
    {
        Console.WriteLine("The user or someone with administration rights to the queue has deleted the job. It must be resubmitted.");
    }
    if ((theJob.JobStatus & PrintJobStatus.Error) == PrintJobStatus.Error)
    {
        Console.WriteLine("The job has errored.");
    }
    if ((theJob.JobStatus & PrintJobStatus.Offline) == PrintJobStatus.Offline)
    {
        Console.WriteLine("The printer is offline. Have user put it online with printer front panel.");
    }
    if ((theJob.JobStatus & PrintJobStatus.PaperOut) == PrintJobStatus.PaperOut)
    {
        Console.WriteLine("The printer is out of paper of the size required by the job. Have user add paper.");
    }

    if (((theJob.JobStatus & PrintJobStatus.Paused) == PrintJobStatus.Paused)
        || 
        ((theJob.HostingPrintQueue.QueueStatus & PrintQueueStatus.Paused) == PrintQueueStatus.Paused))
    {
        HandlePausedJob(theJob);
        //HandlePausedJob is defined in the complete example.
    }

    if ((theJob.JobStatus & PrintJobStatus.Printing) == PrintJobStatus.Printing)
    {
        Console.WriteLine("The job is printing now.");
    }
    if ((theJob.JobStatus & PrintJobStatus.Spooling) == PrintJobStatus.Spooling)
    {
        Console.WriteLine("The job is spooling now.");
    }
    if ((theJob.JobStatus & PrintJobStatus.UserIntervention) == PrintJobStatus.UserIntervention)
    {
        Console.WriteLine("The printer needs human intervention.");
    }
  
}//end SpotTroubleUsingJobAttributes
```

若要使用单独的属性检查打印作业状态，只需读取每个属性，如果属性为 `true`，则报告给控制台屏幕，并建议一种可能的响应方式。 （下面讨论了作业或队列暂停时所调用的 **HandlePausedJob** 方法。）

C#复制

```csharp
       // Check for possible trouble states of a print job using its properties
       internal static void SpotTroubleUsingProperties(PrintSystemJobInfo theJob)
       {
           if (theJob.IsBlocked)
           {
               Console.WriteLine("The job is blocked.");
           }
           if (theJob.IsCompleted || theJob.IsPrinted)
           {
               Console.WriteLine("The job has finished. Have user recheck all output bins and be sure the correct printer is being checked.");
           }
           if (theJob.IsDeleted || theJob.IsDeleting)
           {
               Console.WriteLine("The user or someone with administration rights to the queue has deleted the job. It must be resubmitted.");
           }
           if (theJob.IsInError)
           {
               Console.WriteLine("The job has errored.");
           }
           if (theJob.IsOffline)
           {
               Console.WriteLine("The printer is offline. Have user put it online with printer front panel.");
           }
           if (theJob.IsPaperOut)
           {
               Console.WriteLine("The printer is out of paper of the size required by the job. Have user add paper.");
           }

           if (theJob.IsPaused || theJob.HostingPrintQueue.IsPaused)
           {
               HandlePausedJob(theJob);
               //HandlePausedJob is defined in the complete example.
           }

           if (theJob.IsPrinting)
           {
               Console.WriteLine("The job is printing now.");
           }
           if (theJob.IsSpooling)
           {
               Console.WriteLine("The job is spooling now.");
           }
           if (theJob.IsUserInterventionRequired)
           {
               Console.WriteLine("The printer needs human intervention.");
           }

       }//end SpotTroubleUsingProperties
```

使用 **HandlePausedJob** 方法，应用程序的用户能够远程恢复暂停的作业。 由于可能存在一个充分的暂停打印队列的理由，因此该方法会首先提示用户是否确实要恢复该作业。 如果回答是"Y"，则[PrintQueue.Resume](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.resume)调用方法。

接下来，系统会提示用户是否确实要继续执行作业，这么做是考虑到这个作业可能是独立于队列中的其他作业被单独暂停的。 (比较[PrintQueue.IsPaused](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.ispaused)和[PrintSystemJobInfo.IsPaused](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printsystemjobinfo.ispaused)。)如果答案为"Y"，则[PrintSystemJobInfo.Resume](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printsystemjobinfo.resume)被调用; 否则为[Cancel](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printsystemjobinfo.cancel)调用。

```csharp
internal static void HandlePausedJob(PrintSystemJobInfo theJob)
{
    // If there's no good reason for the queue to be paused, resume it and 
    // give user choice to resume or cancel the job.
    Console.WriteLine("The user or someone with administrative rights to the queue" +
         "\nhas paused the job or queue." +
         "\nResume the queue? (Has no effect if queue is not paused.)" +
         "\nEnter \"Y\" to resume, otherwise press return: ");
    String resume = Console.ReadLine();
    if (resume == "Y")
    {
        theJob.HostingPrintQueue.Resume();
        
        // It is possible the job is also paused. Find out how the user wants to handle that.
        Console.WriteLine("Does user want to resume print job or cancel it?" +
            "\nEnter \"Y\" to resume (any other key cancels the print job): ");
        String userDecision = Console.ReadLine();
        if (userDecision == "Y")
        {
            theJob.Resume();
        }
        else
        {
            theJob.Cancel();
        }
    }//end if the queue should be resumed

}//end HandlePausedJob
```

### [Discover Whether a Print Job Can Be Printed At This Time of Day](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-discover-whether-a-print-job-can-be-printed-at-this-time-of-day)

打印队列并不总是可用的一天 24 小时。 它们具有开始和结束时间属性可以设置以使其在一天中的某些时间不可用。 例如，此功能可用于保留专供特定部门的下午 5 点后的打印机。 该部门必须使用其他队列服务比其他部门的打印机。 将设置为其他部门队列以在下午 5 点后将不可用，而队列支持的部门可能被设置为始终可用。

此外，可以设置打印作业本身是可打印仅在指定的时间范围内。

[PrintQueue](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue)并[PrintSystemJobInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printsystemjobinfo)类中公开API的 Microsoft.NET Framework 提供一种远程检查是否给定的打印作业可以打印到给定队列的当前时间。

下面的示例是一个示例，可以诊断问题的打印作业。

有两个主要步骤为此类型的函数，如下所示。

1. 读取[StartTimeOfDay](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.starttimeofday)并[UntilTimeOfDay](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.untiltimeofday)的属性[PrintQueue](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue)以确定它们之间是否为当前时间。
2. 读取[StartTimeOfDay](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printsystemjobinfo.starttimeofday)并[UntilTimeOfDay](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printsystemjobinfo.untiltimeofday)的属性[PrintSystemJobInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printsystemjobinfo)以确定它们之间是否为当前时间。

但问题变复杂了这些属性不在于[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)对象。 而是[Int32](https://docs.microsoft.com/zh-cn/dotnet/api/system.int32)表示一天的时间为午夜过后的分钟数的对象。 此外，这不是午夜当前所在的时区，但午夜 UTC （协调世界时）。

第一个代码示例显示的静态方法**ReportQueueAndJobAvailability**，它会传递[PrintSystemJobInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printsystemjobinfo)和调用帮助程序方法来确定作业是否可以打印在当前时间和，如果它不是，可以打印时。 请注意，[PrintQueue](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue)不传递给方法。这是因为[PrintSystemJobInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printsystemjobinfo)包括对中的队列的引用其[HostingPrintQueue](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printsystemjobinfo.hostingprintqueue)属性。

从属方法包含重载**ReportAvailabilityAtThisTime**方法可以采用该方法[PrintQueue](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue)或[PrintSystemJobInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printsystemjobinfo)作为参数。 此外，还有**TimeConverter.ConvertToLocalHumanReadableTime**。 下面讨论了所有这些方法。

**ReportQueueAndJobAvailability**方法首先检查以查看队列或打印作业是否不可用这一次。 如果其中任一个不可用，它则会检查以查看是否不可用队列。 如果不可用，则该方法报告这一事实以及当队列将再次变得可用的时间。 然后会检查该作业，如果不可用，它报告的下一个时间跨度时它时它可以打印。 最后，该方法将报告该作业可以打印时的最早时间。 这是更高版本的以下两次。

- 打印队列接下来可用的时间。
- 打印作业下一步可用的时间。

报告一天中的时间时[ToShortTimeString](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime.toshorttimestring)也称为方法，因为此方法取消年、 月和天的输出。 打印队列或打印作业的可用性限于在特定的年、 月或天。

C#复制

```csharp
internal static void ReportQueueAndJobAvailability(PrintSystemJobInfo theJob)
{
    if (!(ReportAvailabilityAtThisTime(theJob.HostingPrintQueue) && ReportAvailabilityAtThisTime(theJob)))
    {
        if (!ReportAvailabilityAtThisTime(theJob.HostingPrintQueue))
        {
            Console.WriteLine("\nThat queue is not available at this time of day." +
                "\nJobs in the queue will start printing again at {0}",
                 TimeConverter.ConvertToLocalHumanReadableTime(theJob.HostingPrintQueue.StartTimeOfDay).ToShortTimeString());
            // TimeConverter class is defined in the complete sample
        }

        if (!ReportAvailabilityAtThisTime(theJob))
        {
            Console.WriteLine("\nThat job is set to print only between {0} and {1}",
                TimeConverter.ConvertToLocalHumanReadableTime(theJob.StartTimeOfDay).ToShortTimeString(),
                TimeConverter.ConvertToLocalHumanReadableTime(theJob.UntilTimeOfDay).ToShortTimeString());
        }
        Console.WriteLine("\nThe job will begin printing as soon as it reaches the top of the queue after:");
        if (theJob.StartTimeOfDay > theJob.HostingPrintQueue.StartTimeOfDay)
        {
            Console.WriteLine(TimeConverter.ConvertToLocalHumanReadableTime(theJob.StartTimeOfDay).ToShortTimeString());
        }
        else
        {
            Console.WriteLine(TimeConverter.ConvertToLocalHumanReadableTime(theJob.HostingPrintQueue.StartTimeOfDay).ToShortTimeString());
        }

    }//end if at least one is not available

}//end ReportQueueAndJobAvailability
```

两个重载**ReportAvailabilityAtThisTime**方法是相同类型传递给它们，因此，只有除外[PrintQueue](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue)版本如下所示。

 备注

这一事实的方法是相同类型除外引发的问题，该示例不会创建一个泛型方法的原因**ReportAvailabilityAtThisTime<T >**。 原因是此类方法需要被限制为具有的类**StartTimeOfDay**并**UntilTimeOfDay**属性，该方法调用，但泛型方法均仅受限于单一类和唯一的类共有[PrintQueue](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue)并[PrintSystemJobInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printsystemjobinfo)在继承树是[PrintSystemObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printsystemobject)其中没有任何此类属性。

**ReportAvailabilityAtThisTime**方法 （如下面的代码示例所示） 首先初始化[Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean)sentinel 变量`true`。 将重置为`false`，如果队列不可用。

接下来，该方法将检查以查看是否开始和 until 时间是否相同。 如果是，队列是始终可用，因此该方法将返回`true`。

如果队列不可用的时间，该方法将使用静态[UtcNow](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime.utcnow)属性来获取当前时间作为[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)对象。 (我们不需要本地时间，因为[StartTimeOfDay](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.starttimeofday)和[UntilTimeOfDay](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.untiltimeofday)属性本身就是以 UTC 时间。)

但是，这两个属性不是[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)对象。 它们是[Int32](https://docs.microsoft.com/zh-cn/dotnet/api/system.int32)将时间表示为分钟后 UTC 午夜的数字。 因此我们需要转换我们[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)午夜分钟后的对象。 完成后，该方法只需检查以查看是否"立即"是队列的开始之间和"截至"时间设置为 false，如果"现在"sentinel 之间两次，并不返回 sentinel。

C#复制

```csharp
private static Boolean ReportAvailabilityAtThisTime(PrintQueue pq)
{
    Boolean available = true;
    if (pq.StartTimeOfDay != pq.UntilTimeOfDay) // If the printer is not available 24 hours a day
    {
        DateTime utcNow = DateTime.UtcNow;
        Int32 utcNowAsMinutesAfterMidnight = (utcNow.TimeOfDay.Hours * 60) + utcNow.TimeOfDay.Minutes;

        // If now is not within the range of available times . . .
        if (!((pq.StartTimeOfDay < utcNowAsMinutesAfterMidnight) 
           && 
           (utcNowAsMinutesAfterMidnight < pq.UntilTimeOfDay)))
        {
            available = false;
        }
    }
    return available;
}//end ReportAvailabilityAtThisTime
```

**TimeConverter.ConvertToLocalHumanReadableTime**方法 （如下面的代码示例所示） 不使用任何方法引入了使用 Microsoft.NET Framework，因此进行简要的讨论。 该方法具有一个双精度的转换任务： 它必须采用一个整型表示午夜之后的分钟，并将其转换为人工可读的时间和它必须将其转换为本地时间。 这是通过实现通过首先创建[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)对象，它设置为午夜 UTC，然后使用[AddMinutes](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime.addminutes)方法添加到该方法传递的分钟数。 这将返回一个新[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)传递给该方法将原始时间表示。 [ToLocalTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime.tolocaltime)方法然后将此转换为本地时间。

C#复制

```csharp
class TimeConverter
{
    // Convert time as minutes past UTC midnight into human readable time in local time zone.
    internal static DateTime ConvertToLocalHumanReadableTime(Int32 timeInMinutesAfterUTCMidnight)
    {
        // Construct a UTC midnight object.
        // Must start with current date so that the local Daylight Savings system, if any, will be taken into account.
        DateTime utcNow = DateTime.UtcNow; 
        DateTime utcMidnight = new DateTime(utcNow.Year, utcNow.Month, utcNow.Day, 0, 0, 0, DateTimeKind.Utc);
        
        // Add the minutes passed into the method in order to get the intended UTC time.
        Double minutesAfterUTCMidnight = (Double)timeInMinutesAfterUTCMidnight;
        DateTime utcTime = utcMidnight.AddMinutes(minutesAfterUTCMidnight);
        
        // Convert to local time.
        DateTime localTime = utcTime.ToLocalTime();

        return localTime;

    }// end ConvertToLocalHumanReadableTime

}//end TimeConverter class
```

### [Enumerate a Subset of Print Queues](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-enumerate-a-subset-of-print-queues)

负责管理公司范围内的打印机的信息技术 (IT) 专业人员所面临的常见情况是生成具有某些特征的打印机的列表。提供此功能[GetPrintQueues](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printserver.getprintqueues)方法[PrintServer](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printserver)对象和[EnumeratedPrintQueueTypes](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.enumeratedprintqueuetypes)枚举。

在下面的示例中，代码先创建标志，用于指定我们想要列出的打印队列的特性数组。 在此示例中，我们正在寻找打印队列打印服务器上本地安装并共享。 [EnumeratedPrintQueueTypes](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.enumeratedprintqueuetypes)枚举提供了许多其他的值。

该代码随后创建[LocalPrintServer](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.localprintserver)对象，一个类派生自[PrintServer](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printserver)。 本地打印服务器是在其运行应用程序的计算机。

最后一个重要步骤是将数组传递给[GetPrintQueues](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printserver.getprintqueues)方法。

最后，会向用户显示结果。

C#复制

```csharp
// Specify that the list will contain only the print queues that are installed as local and are shared
EnumeratedPrintQueueTypes[] enumerationFlags = {EnumeratedPrintQueueTypes.Local,
                                                EnumeratedPrintQueueTypes.Shared};

LocalPrintServer printServer = new LocalPrintServer();

//Use the enumerationFlags to filter out unwanted print queues
PrintQueueCollection printQueuesOnLocalServer = printServer.GetPrintQueues(enumerationFlags);

Console.WriteLine("These are your shared, local print queues:\n\n");

foreach (PrintQueue printer in printQueuesOnLocalServer)
{
    Console.WriteLine("\tThe shared printer " + printer.Name + " is located at " + printer.Location + "\n");
}
Console.WriteLine("Press enter to continue.");
Console.ReadLine();
```

您可以扩展此示例通过让`foreach`循环通过每个打印队列的步骤执行进一步筛选。 例如，您可以筛选掉不支持通过循环调用双面打印的打印机每个打印队列的[GetPrintCapabilities](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.getprintcapabilities)方法和测试返回的值进行双面打印是否存在。

### [Get Print System Object Properties Without Reflection](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-get-print-system-object-properties-without-reflection)

使用反射对某个对象中列举的属性 （以及这些属性的类型） 可能会降低应用程序性能。[System.Printing.IndexedProperties](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.indexedproperties)命名空间提供了一种方式获取此信息与使用反射。

执行此操作的步骤如下所示。

1. 创建类型的实例。 在以下示例中，类型是[PrintQueue](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue)附带 Microsoft.NET Framework，但几乎完全相同的代码的类型应适用于从派生类型[PrintSystemObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printsystemobject)。
2. 创建[PrintPropertyDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.indexedproperties.printpropertydictionary)从该类型的[PropertiesCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printsystemobject.propertiescollection)。 [Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.dictionaryentry.value)此字典中的每个条目的属性是一个派生自的类型的一个对象[PrintProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.indexedproperties.printproperty)。
3. 枚举将字典中的成员。 为每个，执行以下操作。
4. 向上转换为每个条目的值[PrintProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.indexedproperties.printproperty)并使用它来创建[PrintProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.indexedproperties.printproperty)对象。
5. 获取类型的[Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.indexedproperties.printproperty.value)的每个[PrintProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.indexedproperties.printproperty)对象。

C#复制

```csharp
// Enumerate the properties, and their types, of a queue without using Reflection
LocalPrintServer localPrintServer = new LocalPrintServer();
PrintQueue defaultPrintQueue = LocalPrintServer.GetDefaultPrintQueue();

PrintPropertyDictionary printQueueProperties = defaultPrintQueue.PropertiesCollection;

Console.WriteLine("These are the properties, and their types, of {0}, a {1}", defaultPrintQueue.Name, defaultPrintQueue.GetType().ToString() +"\n");

foreach (DictionaryEntry entry in printQueueProperties)
{
    PrintProperty property = (PrintProperty)entry.Value;

    if (property.Value != null)
    {
        Console.WriteLine(property.Name + "\t(Type: {0})", property.Value.GetType().ToString());
    }
}
Console.WriteLine("\n\nPress Return to continue...");
Console.ReadLine();
```

### [Programmatically Print XPS Files](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-programmatically-print-xps-files)

可以使用的一个重载[AddJob](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.addjob)方法以打印XML 纸张规范 (XPS)而无需打开的文件[PrintDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.printdialog)或从原理上讲，任何用户界面 (UI)根本。

此外可以打印XML 纸张规范 (XPS)文件使用多[Write](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.xps.xpsdocumentwriter.write)并[WriteAsync](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.xps.xpsdocumentwriter.writeasync)方法的[XpsDocumentWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.xps.xpsdocumentwriter)。 有关此操作的详细信息，请参阅[打印 XPS 文档](https://docs.microsoft.com/previous-versions/dotnet/netframework-3.5/ms771525(v=vs.90))。

另一种方式打印XML 纸张规范 (XPS)是使用[PrintDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.printdialog.printdocument)或[PrintVisual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.printdialog.printvisual)方法的[PrintDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.printdialog)控件。 请参阅[调用打印对话框](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-invoke-a-print-dialog)。



使用三个参数的主要步骤[AddJob(String, String, Boolean)](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.addjob#System_Printing_PrintQueue_AddJob_System_String_System_String_System_Boolean_)方法如下所示。 以下示例提供了详细信息。

1. 确定打印机是否是 XPSDrv 打印机。 （有关 XPSDrv 的详细信息，请参阅[打印概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/printing-overview)。）
2. 如果打印机不是 XPSDrv 打印机，将线程的单元设置为单线程。
3. 实例化打印服务器并打印队列对象。
4. 调用该方法，指定作业名称，要打印的文件和一个[Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean)标志，用于指示打印机是否是 XPSDrv 打印机。

以下示例演示如何以批处理方式打印目录中的所有 XPS 文件。 尽管应用程序会提示用户指定的目录，三个参数[AddJob(String, String, Boolean)](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.addjob#System_Printing_PrintQueue_AddJob_System_String_System_String_System_Boolean_)方法不需要用户界面 (UI)。 它可用于具有 XPS 文件名的任何代码路径和可以传递到该方法的路径。

三个参数[AddJob(String, String, Boolean)](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.addjob#System_Printing_PrintQueue_AddJob_System_String_System_String_System_Boolean_)的重载[AddJob](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.addjob)必须在单线程单元中运行时[Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean)参数是`false`，它必须是正在使用非 XPSDrv 打印机时。 但是，Microsoft .NET 的默认单元状态为多线程。 由于本示例假定使用非 XPSDrv 打印机，因此此默认值必须为相反值。

有两种可用于更改此默认值的方法。 一种方法是只需添加[STAThreadAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.stathreadattribute)(即，"`[System.STAThreadAttribute()]`") 的应用程序的第一行的正上方`Main`方法 (通常"`static void Main(string[] args)`")。 但是，许多应用程序要求`Main`方法具有多线程的单元状态，因此第二种方法： put 调用[AddJob(String, String, Boolean)](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.addjob#System_Printing_PrintQueue_AddJob_System_String_System_String_System_Boolean_)在其单元状态设置为单独的线程[STA](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.apartmentstate#System_Threading_ApartmentState_STA)与[SetApartmentState](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.thread.setapartmentstate)。 以下示例使用第二种方法。

相应地，该示例先实例化[Thread](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.thread)对象并将其传递**PrintXPS**方法作为[ThreadStart](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.threadstart)参数。 （该示例的后面部分定义了 **PrintXPS** 方法。）接下来，将线程设置为单线程单元。 `Main` 方法的唯一剩余代码会启动新线程。

该示例的内容主要关于 `static`**BatchXPSPrinter.PrintXPS** 方法。 创建打印服务器和队列后，该方法会提示用户提供包含 XPS 文件的目录。 后验证目录是否存在以及是否存在*.xps 文件中，该方法将每个此类文件添加到打印队列。 该示例假定，打印机不是 XPSDrv 打印机，因此我们传递`false`的最后一个参数为[AddJob(String, String, Boolean)](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.addjob#System_Printing_PrintQueue_AddJob_System_String_System_String_System_Boolean_)方法。 出于此原因，该方法先验证文件中的 XPS 标记，然后再尝试将其转换为打印机的页面描述语言。如果验证失败，会引发异常。 该示例代码将捕获该异常，并通知用户相关信息，然后继续处理下一 XPS 文件。

C#复制

```csharp
class Program
{
    [System.MTAThreadAttribute()] // Added for clarity, but this line is redundant because MTA is the default.
    static void Main(string[] args)
    {
        // Create the secondary thread and pass the printing method for 
        // the constructor's ThreadStart delegate parameter. The BatchXPSPrinter
        // class is defined below.
        Thread printingThread = new Thread(BatchXPSPrinter.PrintXPS);

        // Set the thread that will use PrintQueue.AddJob to single threading.
        printingThread.SetApartmentState(ApartmentState.STA);

        // Start the printing thread. The method passed to the Thread 
        // constructor will execute.
        printingThread.Start();
   
    }//end Main

}//end Program class

public class BatchXPSPrinter
{
    public static void PrintXPS()
    {
        // Create print server and print queue.
        LocalPrintServer localPrintServer = new LocalPrintServer();
        PrintQueue defaultPrintQueue = LocalPrintServer.GetDefaultPrintQueue();
        
        // Prompt user to identify the directory, and then create the directory object.
        Console.Write("Enter the directory containing the XPS files: ");
        String directoryPath = Console.ReadLine();
        DirectoryInfo dir = new DirectoryInfo(directoryPath);

        // If the user mistyped, end the thread and return to the Main thread.
        if (!dir.Exists)
        {
            Console.WriteLine("There is no such directory.");
        }
        else
        {
            // If there are no XPS files in the directory, end the thread 
            // and return to the Main thread.
            if (dir.GetFiles("*.xps").Length == 0)
            {
                Console.WriteLine("There are no XPS files in the directory.");
            }
            else
            {
                Console.WriteLine("\nJobs will now be added to the print queue.");
                Console.WriteLine("If the queue is not paused and the printer is working, jobs will begin printing.");
                
                // Batch process all XPS files in the directory.
                foreach (FileInfo f in dir.GetFiles("*.xps"))
                {
                    String nextFile = directoryPath + "\\" + f.Name;
                    Console.WriteLine("Adding {0} to queue.", nextFile);

                    try
                    {
                        // Print the Xps file while providing XPS validation and progress notifications.
                        PrintSystemJobInfo xpsPrintJob = defaultPrintQueue.AddJob(f.Name, nextFile, false);
                    }
                    catch (PrintJobException e)
                    {
                        Console.WriteLine("\n\t{0} could not be added to the print queue.", f.Name);
                        if (e.InnerException.Message == "File contains corrupted data.")
                        {
                            Console.WriteLine("\tIt is not a valid XPS file. Use the isXPS Conformance Tool to debug it.");
                        }
                        Console.WriteLine("\tContinuing with next XPS file.\n");
                    }

                }// end for each XPS file
           
            }//end if there are no XPS files in the directory

        }//end if the directory does not exist

        Console.WriteLine("Press Enter to end program.");
        Console.ReadLine();

    }// end PrintXPS method

}// end BatchXPSPrinter class
```

如果使用 XPSDrv 打印机，则可将最后一个参数设置为 `true`。 在这种情况下，由于 XPS 是打印机的页面描述语言，该方法会将文件发送到打印机，而不会对其进行验证或将其转换为另一种页面描述语言。 如果您不确定在设计时是否应用程序将使用为 XPSDrv 打印机，则可以修改应用程序，使其读取[IsXpsDevice](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.isxpsdevice)属性并根据它所找到的分支。

由于最初将几台 XPSDrv 打印机提供的发布后立即Windows Vista和 Microsoft.NET Framework 中，您可能需要伪装为 XPSDrv 打印机非 XPSDrv 打印机。 为此，请将 Pipelineconfig.xml 添加到运行应用程序的计算机的注册表项中的以下文件列表：

HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Print\Environments\Windows NT x86\Drivers\Version-3\*<PseudoXPSPrinter>* \DependentFiles

其中 *<PseudoXPSPrinter>* 是任一打印队列。 然后必须重新启动计算机。

此伪装允许您传递`true`的最后一个参数作为[AddJob(String, String, Boolean)](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.addjob#System_Printing_PrintQueue_AddJob_System_String_System_String_System_Boolean_)而不会导致异常，但由于*<出现 >* 并不是真正的 XPSDrv 打印机，仅会打印垃圾。

**请注意**为简单起见，上面的示例使用的是否存在*.xps 扩展为一个文件是其测试XPS。 但是，XPS 文件不需要具有此扩展名。 [isXPS.exe（isXPS 合规性工具）](https://docs.microsoft.com/previous-versions/dotnet/netframework-4.0/aa348104(v=vs.100))是一种测试文件是否具有 XPS 有效性的方法。

### [Remotely Survey the Status of Printers](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-remotely-survey-the-status-of-printers)

在大中型公司，在任何给定时间里，都可能发生由于卡纸、纸张用完或某些其他有问题而导致多台打印机无法工作的情况。 打印机属性中公开的丰富API的 Microsoft.NET Framework 提供了一种方法用于执行快速调查打印机状态。



以下是创建此类实用程序的主要步骤。

1. 获取所有打印服务器的列表。
2. 循环访问服务器以查询其打印队列。
3. 在每一轮服务器循环访问过程中，循环访问所有服务器的队列并读取每个属性，这些属性可能指示队列当前不在工作。

以下代码是一系列代码段。 为简单起见，本示例假定存在通过 CRLF 分隔的打印服务器列表。 在变量`fileOfPrintServers`是[StreamReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.streamreader)此文件的对象。 由于每个服务器名称是在其对应行，任何调用的[ReadLine](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.streamreader.readline)获取下一步的服务器的名称，并将移动[StreamReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.streamreader)的光标移到下一行的开头。

在外部循环中，该代码会创建[PrintServer](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printserver)对象的最新的打印服务器，并指定要对服务器具有管理权限的应用程序。

 备注

如果有多个服务器，则可以提高性能，通过使用[PrintServer(String, String[\], PrintSystemDesiredAccess)](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printserver.-ctor#System_Printing_PrintServer__ctor_System_String_System_String___System_Printing_PrintSystemDesiredAccess_)仅初始化都需要具备的属性的构造函数。

该示例然后使用[GetPrintQueues](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printserver.getprintqueues)若要创建的所有服务器的集合的排队，并开始循环访问它们。 此内部循环包含一个分支结构，该结构对应于检查打印机状态的两种方法：

- 可以读取的标志[QueueStatus](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.queuestatus)属性的类型即[PrintQueueStatus](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueuestatus)。
- 你可以读取每个相关属性，如[IsOutOfPaper](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.isoutofpaper)，和[IsPaperJammed](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.ispaperjammed)。

此示例演示这两种方法，因此该用户之前进行提示要使用的方法并回复"y"，如果他或她想要使用的标志[QueueStatus](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.queuestatus)属性。 请参阅以下有关这两种方法的详细信息。

最后，会向用户显示结果。

C#复制

```csharp
// Survey queue status for every queue on every print server
String line;
String statusReport = "\n\nAny problem states are indicated below:\n\n";
while ((line = fileOfPrintServers.ReadLine()) != null)
 {
     PrintServer myPS = new PrintServer(line, PrintSystemDesiredAccess.AdministrateServer);
     PrintQueueCollection myPrintQueues = myPS.GetPrintQueues();
     statusReport = statusReport + "\n" + line;
     foreach (PrintQueue pq in myPrintQueues)
     {
         pq.Refresh();
         statusReport = statusReport + "\n\t" + pq.Name + ":";
         if (useAttributesResponse == "y")
         {
             TroubleSpotter.SpotTroubleUsingQueueAttributes(ref statusReport, pq);
             // TroubleSpotter class is defined in the complete example.
         }
         else
         {
             TroubleSpotter.SpotTroubleUsingProperties(ref statusReport, pq);
         }                 

     }// end for each print queue

 }// end while list of print servers is not yet exhausted

fileOfPrintServers.Close();
Console.WriteLine(statusReport);
Console.WriteLine("\nPress Return to continue.");
Console.ReadLine();
```

若要使用的标志检查打印机状态[QueueStatus](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.queuestatus)属性，检查每个相关标志以查看它是否设置。 检查是否在一组位标志中设置了一个位的标准方法是执行一个逻辑 AND 运算，其中将该组标志作为一个操作数，将标志本身作为另一操作数。 由于该标志本身仅设置一个位，因此逻辑 AND 的结果至多为设置了该相同位。 若要查明事实是否如此，只需将逻辑 AND 的结果与标志本身进行比较。 有关详细信息，请参阅[PrintQueueStatus](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueuestatus)，则[& 运算符 (C#引用)](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/and-operator)，并[FlagsAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.flagsattribute)。

对于已设置了其位的各个特性，代码会将一条通知添加到将向用户显示的最终报告中。 （下面会讨论代码结束时调用的 **ReportAvailabilityAtThisTime** 方法。）

C#复制

```csharp
// Check for possible trouble states of a printer using the flags of the QueueStatus property
internal static void SpotTroubleUsingQueueAttributes(ref String statusReport, PrintQueue pq)
{
    if ((pq.QueueStatus & PrintQueueStatus.PaperProblem) == PrintQueueStatus.PaperProblem)
    {
        statusReport = statusReport + "Has a paper problem. ";
    }
    if ((pq.QueueStatus & PrintQueueStatus.NoToner) == PrintQueueStatus.NoToner)
    {
        statusReport = statusReport + "Is out of toner. ";
    }
    if ((pq.QueueStatus & PrintQueueStatus.DoorOpen) == PrintQueueStatus.DoorOpen)
    {
        statusReport = statusReport + "Has an open door. ";
    }
    if ((pq.QueueStatus & PrintQueueStatus.Error) == PrintQueueStatus.Error)
    {
        statusReport = statusReport + "Is in an error state. ";
    }
    if ((pq.QueueStatus & PrintQueueStatus.NotAvailable) == PrintQueueStatus.NotAvailable)
    {
        statusReport = statusReport + "Is not available. ";
    }
    if ((pq.QueueStatus & PrintQueueStatus.Offline) == PrintQueueStatus.Offline)
    {
        statusReport = statusReport + "Is off line. ";
    }
    if ((pq.QueueStatus & PrintQueueStatus.OutOfMemory) == PrintQueueStatus.OutOfMemory)
    {
        statusReport = statusReport + "Is out of memory. ";
    }
    if ((pq.QueueStatus & PrintQueueStatus.PaperOut) == PrintQueueStatus.PaperOut)
    {
        statusReport = statusReport + "Is out of paper. ";
    }
    if ((pq.QueueStatus & PrintQueueStatus.OutputBinFull) == PrintQueueStatus.OutputBinFull)
    {
        statusReport = statusReport + "Has a full output bin. ";
    }
    if ((pq.QueueStatus & PrintQueueStatus.PaperJam) == PrintQueueStatus.PaperJam)
    {
        statusReport = statusReport + "Has a paper jam. ";
    }
    if ((pq.QueueStatus & PrintQueueStatus.Paused) == PrintQueueStatus.Paused)
    {
        statusReport = statusReport + "Is paused. ";
    }
    if ((pq.QueueStatus & PrintQueueStatus.TonerLow) == PrintQueueStatus.TonerLow)
    {
        statusReport = statusReport + "Is low on toner. ";
    }
    if ((pq.QueueStatus & PrintQueueStatus.UserIntervention) == PrintQueueStatus.UserIntervention)
    {
        statusReport = statusReport + "Needs user intervention. ";
    }

    // Check if queue is even available at this time of day
    // The method below is defined in the complete example.
    ReportAvailabilityAtThisTime(ref statusReport, pq);
}
```

若要使用各个属性检查打印机状态，只需读取各个属性，并将注释添加到最终报告，如果属性为 `true`，将向用户显示最终报告。 （下面会讨论代码结束时调用的 **ReportAvailabilityAtThisTime** 方法。）

C#复制

```csharp
// Check for possible trouble states of a printer using its properties
internal static void SpotTroubleUsingProperties(ref String statusReport, PrintQueue pq)
{
    if (pq.HasPaperProblem)
    {
        statusReport = statusReport + "Has a paper problem. ";
    }
    if (!(pq.HasToner))
    {
        statusReport = statusReport + "Is out of toner. ";
    }
    if (pq.IsDoorOpened)
    {
        statusReport = statusReport + "Has an open door. ";
    }
    if (pq.IsInError)
    {
        statusReport = statusReport + "Is in an error state. ";
    }
    if (pq.IsNotAvailable)
    {
        statusReport = statusReport + "Is not available. ";
    }
    if (pq.IsOffline)
    {
        statusReport = statusReport + "Is off line. ";
    }
    if (pq.IsOutOfMemory)
    {
        statusReport = statusReport + "Is out of memory. ";
    }
    if (pq.IsOutOfPaper)
    {
        statusReport = statusReport + "Is out of paper. ";
    }
    if (pq.IsOutputBinFull)
    {
        statusReport = statusReport + "Has a full output bin. ";
    }
    if (pq.IsPaperJammed)
    {
        statusReport = statusReport + "Has a paper jam. ";
    }
    if (pq.IsPaused)
    {
        statusReport = statusReport + "Is paused. ";
    }
    if (pq.IsTonerLow)
    {
        statusReport = statusReport + "Is low on toner. ";
    }
    if (pq.NeedUserIntervention)
    {
        statusReport = statusReport + "Needs user intervention. ";
    }

    // Check if queue is even available at this time of day
    // The following method is defined in the complete example.
    ReportAvailabilityAtThisTime(ref statusReport, pq);

}//end SpotTroubleUsingProperties
```

创建了 **ReportAvailabilityAtThisTime** 方法，以应对需要确定队列在一天的当前时间是否可用的情况。

该方法将不执行任何操作如果[StartTimeOfDay](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.starttimeofday)和[UntilTimeOfDay](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.untiltimeofday)属性相等，则因为在这种情况下打印机不可在任何时候。 如果它们不同，该方法将获取当前时间，它将拥有要转换为午夜过后的总分钟数，因为[StartTimeOfDay](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.starttimeofday)并[UntilTimeOfDay](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.untiltimeofday)属性是[Int32](https://docs.microsoft.com/zh-cn/dotnet/api/system.int32)不表示分钟后午夜[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)对象。 最后，该方法会检查当前时间是否介于开始时间和“截至”时间之间。

C#复制

```csharp
private static void ReportAvailabilityAtThisTime(ref String statusReport, PrintQueue pq)
{
    if (pq.StartTimeOfDay != pq.UntilTimeOfDay) // If the printer is not available 24 hours a day
    {
DateTime utcNow = DateTime.UtcNow;
Int32 utcNowAsMinutesAfterMidnight = (utcNow.TimeOfDay.Hours * 60) + utcNow.TimeOfDay.Minutes;
        
        // If now is not within the range of available times . . .
        if (!((pq.StartTimeOfDay < utcNowAsMinutesAfterMidnight) 
           &&
           (utcNowAsMinutesAfterMidnight < pq.UntilTimeOfDay)))
        {
            statusReport = statusReport + " Is not available at this time of day. ";
        }
    }
}
```

### [Validate and Merge PrintTickets](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-validate-and-merge-printtickets)

Microsoft Windows [打印架构](https://go.microsoft.com/fwlink/?LinkId=186397)包括灵活且可扩展[PrintCapabilities](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printcapabilities)和[PrintTicket](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printticket)元素。 前者详细列举的打印设备的功能，后者用于指定设备应如何使用这些功能来处理特定文档、 单个文档或单页的序列。

典型的应用程序支持打印的任务序列将如下所示。

1. 确定打印机的功能。
2. 配置[PrintTicket](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printticket)以使用这些功能。
3. 验证[PrintTicket](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printticket)。

本文介绍如何执行此操作

在下面的简单示例中，我们都只希望打印机是否支持双工 — 双面打印。 主要步骤如下所示。

1. 获取[PrintCapabilities](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printcapabilities)对象与[GetPrintCapabilities](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.getprintcapabilities)方法。

2. 测试存在所需的功能。 在以下示例中，我们测试[DuplexingCapability](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printcapabilities.duplexingcapability)属性的[PrintCapabilities](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printcapabilities)沿长边工作表的对象的一张纸的纸张的"翻页"的两面上的打印功能是否存在。 由于[DuplexingCapability](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printcapabilities.duplexingcapability)是一个集合，我们将使用`Contains`方法的[ReadOnlyCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.objectmodel.readonlycollection-1)。

    备注

   此步骤不是绝对必需的。 [MergeAndValidatePrintTicket](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.mergeandvalidateprintticket)使用以下方法将检查每个请求[PrintTicket](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printticket)针对打印机的功能。 如果打印机不支持请求的功能，打印机驱动程序将替换中的另一个请求[PrintTicket](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printticket)方法返回。

3. 如果打印机支持双面打印，示例代码会创建[PrintTicket](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printticket)的要求进行双面打印。 但应用程序未指定每个可能的打印机设置中提供[PrintTicket](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printticket)元素。 这将浪费的程序员和计划时间。 相反，该代码设置仅进行双面打印请求，然后将合并这[PrintTicket](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printticket)与某个现有，完全配置且经过验证， [PrintTicket](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printticket)，在这种情况下，用户的默认[PrintTicket](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printticket)。

4. 相应地，示例代码会调用[MergeAndValidatePrintTicket](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.mergeandvalidateprintticket)方法来合并将新的、 最小，[PrintTicket](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printticket)用户的默认值[PrintTicket](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printticket)。 这将返回[ValidationResult](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.validationresult)，包含新的[PrintTicket](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printticket)作为其属性之一。

5. 此示例然后测试新[PrintTicket](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printticket)请求双面打印。 如果是这样，则代码会将其用户的新的默认打印票证。 如果没有执行上述步骤 2，并且打印机不支持双工沿长边，则测试将会造成`false`。 （请参阅上面的说明。）

6. 最后一个重要步骤是将提交到更改[UserPrintTicket](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.userprintticket)的属性[PrintQueue](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue)与[Commit](https://docs.microsoft.com/zh-cn/dotnet/api/system.printing.printqueue.commit)方法。

C#复制

```csharp
/// <summary>
/// Changes the user-default PrintTicket setting of the specified print queue.
/// </summary>
/// <param name="queue">the printer whose user-default PrintTicket setting needs to be changed</param>
static private void ChangePrintTicketSetting(PrintQueue queue)
{
    //
    // Obtain the printer's PrintCapabilities so we can determine whether or not
    // duplexing printing is supported by the printer.
    //
    PrintCapabilities printcap = queue.GetPrintCapabilities();

    //
    // The printer's duplexing capability is returned as a read-only collection of duplexing options
    // that can be supported by the printer. If the collection returned contains the duplexing
    // option we want to set, it means the duplexing option we want to set is supported by the printer,
    // so we can make the user-default PrintTicket setting change.
    //
    if (printcap.DuplexingCapability.Contains(Duplexing.TwoSidedLongEdge))
    {
        //
        // To change the user-default PrintTicket, we can first create a delta PrintTicket with
        // the new duplexing setting.
        //
        PrintTicket deltaTicket = new PrintTicket();
        deltaTicket.Duplexing = Duplexing.TwoSidedLongEdge;

        //
        // Then merge the delta PrintTicket onto the printer's current user-default PrintTicket,
        // and validate the merged PrintTicket to get the new PrintTicket we want to set as the
        // printer's new user-default PrintTicket.
        //
        ValidationResult result = queue.MergeAndValidatePrintTicket(queue.UserPrintTicket, deltaTicket);

        //
        // The duplexing option we want to set could be constrained by other PrintTicket settings
        // or device settings. We can check the validated merged PrintTicket to see whether the
        // the validation process has kept the duplexing option we want to set unchanged.
        //
        if (result.ValidatedPrintTicket.Duplexing == Duplexing.TwoSidedLongEdge)
        {
            //
            // Set the printer's user-default PrintTicket and commit the set operation.
            //
            queue.UserPrintTicket = result.ValidatedPrintTicket;
            queue.Commit();
            Console.WriteLine("PrintTicket new duplexing setting is set on '{0}'.", queue.FullName);
        }
        else
        {
            //
            // The duplexing option we want to set has been changed by the validation process
            // when it was resolving setting constraints.
            //
            Console.WriteLine("PrintTicket new duplexing setting is constrained on '{0}'.", queue.FullName);
        }
    }
    else
    {
        //
        // If the printer doesn't support the duplexing option we want to set, skip it.
        //
        Console.WriteLine("PrintTicket new duplexing setting is not supported on '{0}'.", queue.FullName);
    }
}
```

以便可以快速测试此示例中，如下所示的其余部分。 创建项目和命名空间，然后将在本文中的两个代码片段粘贴到命名空间块。

C#复制

```csharp
/// <summary>
/// Displays the correct command line syntax to run this sample program.
/// </summary>
static private void DisplayUsage()
{
    Console.WriteLine();
    Console.WriteLine("Usage #1: printticket.exe -l \"<printer_name>\"");
    Console.WriteLine("      Run program on the specified local printer");
    Console.WriteLine();
    Console.WriteLine("      Quotation marks may be omitted if there are no spaces in printer_name.");
    Console.WriteLine();
    Console.WriteLine("Usage #2: printticket.exe -r \"\\\\<server_name>\\<printer_name>\"");
    Console.WriteLine("      Run program on the specified network printer");
    Console.WriteLine();
    Console.WriteLine("      Quotation marks may be omitted if there are no spaces in server_name or printer_name.");
    Console.WriteLine();
    Console.WriteLine("Usage #3: printticket.exe -a");
    Console.WriteLine("      Run program on all installed printers");
    Console.WriteLine();
}


[STAThread]
static public void Main(string[] args)
{
    try
    {
        if ((args.Length == 1) && (args[0] == "-a"))
        {
            //
            // Change PrintTicket setting for all local and network printer connections.
            //
            LocalPrintServer server = new LocalPrintServer();

            EnumeratedPrintQueueTypes[] queue_types = {EnumeratedPrintQueueTypes.Local,
                                                       EnumeratedPrintQueueTypes.Connections};

            //
            // Enumerate through all the printers.
            //
            foreach (PrintQueue queue in server.GetPrintQueues(queue_types))
            {
                //
                // Change the PrintTicket setting queue by queue.
                //
                ChangePrintTicketSetting(queue);
            }
        }//end if -a

        else if ((args.Length == 2) && (args[0] == "-l"))
        {
            //
            // Change PrintTicket setting only for the specified local printer.
            //
            LocalPrintServer server = new LocalPrintServer();
            PrintQueue queue = new PrintQueue(server, args[1]);
            ChangePrintTicketSetting(queue);
        }//end if -l
            
        else if ((args.Length == 2) && (args[0] == "-r"))
        {
            //
            // Change PrintTicket setting only for the specified remote printer.
            //
            String serverName = args[1].Remove(args[1].LastIndexOf(@"\"));
            String printerName = args[1].Remove(0, args[1].LastIndexOf(@"\")+1);
            PrintServer ps = new PrintServer(serverName);
            PrintQueue queue = new PrintQueue(ps, printerName);
            ChangePrintTicketSetting(queue);
         }//end if -r
       
        else
        {
            //
            // Unrecognized command line.
            // Show user the correct command line syntax to run this sample program.
            //
            DisplayUsage();
        }
    }
    catch (Exception e)
    {
        Console.WriteLine(e.Message);
        Console.WriteLine(e.StackTrace);

        //
        // Show inner exception information if it's provided.
        //
        if (e.InnerException != null)
        {
            Console.WriteLine("--- Inner Exception ---");
            Console.WriteLine(e.InnerException.Message);
            Console.WriteLine(e.InnerException.StackTrace);
        }
    }
    finally
    {
        Console.WriteLine("Press Return to continue...");
        Console.ReadLine();
    }
}//end Main
```