# [Interoperability](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/interop/)

借助互操作性，可以保留和利用对非托管代码的现有投资工作。 在公共语言运行时 (CLR) 控制下运行的代码称为*托管代码*，不在 CLR 控制下运行的代码称为*非托管代码*。 例如，COM、COM+、C++ 组件、ActiveX 组件和 Microsoft Win32 API 都是非托管代码。

使用 .NET Framework，可以通过平台调用服务、[System.Runtime.InteropServices](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.interopservices) 命名空间、C++ 互操作性和 COM 互操作性（COM 互操作），实现与非托管代码的互操作性。

## 本节内容

[互操作性概述](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/interop/interoperability-overview)
介绍了实现 C# 托管代码和非托管代码的互操作性的方法。

[如何：通过使用 Visual C# 功能访问 Office 互操作对象](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/interop/how-to-access-office-onterop-objects)
介绍了 Visual C# 为了推动 Office 编程而引入的功能 。

[如何：在 COM 互操作编程中使用已编制索引的属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/interop/how-to-use-indexed-properties-in-com-interop-rogramming)
介绍了如何使用已编入索引的属性来访问包含参数的 COM 属性。

[如何：使用平台调用播放波形文件](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/interop/how-to-use-platform-invoke-to-play-a-wave-file)
介绍了如何使用平台调用服务在 Windows 操作系统中播放 .wav 声音文件。

[演练：Office 编程](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/interop/walkthrough-office-programming)
展示了如何创建 Excel 工作簿和包含指向此工作簿的链接的 Word 文档。

[COM 类示例](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/interop/example-com-class)
展示了如何将 C# 类公开为 COM 对象。

## [Interoperability Overview](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/interop/interoperability-overview)

本主题描述在 C# 托管代码和非托管代码之间实现互操作性的方法。

### 平台调用

平台调用是一项服务，它使托管代码能够调用动态链接库 (DLL) 中实现的非托管函数，例如 Microsoft Win32 API 中的非托管函数。 此服务定位并调用导出的函数，并根据需要跨交互操作边界封送其自变量（整数、字符串、数组、结构等）。

有关详细信息，请参阅[使用非托管 DLL 函数](https://docs.microsoft.com/zh-cn/dotnet/framework/interop/consuming-unmanaged-dll-functions)和[操作说明：使用平台调用播放波形文件](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/interop/how-to-use-platform-invoke-to-play-a-wave-file)。

> [公共语言运行时](https://docs.microsoft.com/zh-cn/dotnet/standard/clr) (CLR) 管理对系统资源的访问。 调用 CLR 外部的非托管代码将避开这种安全机制，因此会带来安全风险。 例如，非托管代码可能直接调用非托管代码中的资源，从而避开 CLR 安全机制。 有关详细信息，请参阅 [.NET 中的安全性](https://docs.microsoft.com/zh-cn/dotnet/standard/security/index)。

### C++ 互操作

可使用 C++ interop（又称为 It Just Works (IJW)）包装本机 C++ 类，以便用 C# 或其他 .NET Framework 语言编写的代码可以使用此类。 为此，请编写 C++ 代码来包装本机 DLL 或 COM 组件。 与其他 .NET Framework 语言不同，Visual C++ 具有互操作性支持，可使托管和非托管代码放置在同一个应用程序（甚至同一个文件）中。 然后使用 **/clr** 编译器开关生成托管程序集，以便生成 C++ 代码。 最后，在 C# 项目中添加一个对该程序集的引用，并像使用其他托管类那样使用被包装对象。

### 向 C# 公开 COM 组件

可以使用 C# 项目中的 COM 组件。 常规步骤如下所示：

1. 找到要使用的 COM 组件并注册。 使用 regsvr32.exe 注册或注销 COM DLL。

2. 向项目添加对 COM 组件或类型库的引用。

   添加引用时，Visual Studio 使用 [Tlbimp.exe（类型库导入程序）](https://docs.microsoft.com/zh-cn/dotnet/framework/tools/tlbimp-exe-type-library-importer)。此程序需要使用类型库作为输入，以输出 .NET Framework 互操作程序集。 该程序集又称为运行时可调用包装器 (RCW)，其中包含包装类型库中的 COM 类和接口的托管类和接口。 Visual Studio 向项目添加对生成程序集的引用。

3. 创建在 RCW 中定义的类的实例。 这会创建 COM 对象的实例。

4. 像使用其他托管对象那样使用该对象。 当垃圾回收对该对象进行回收后，COM 对象的实例也会从内存中释放出来。

有关详细信息，请参阅[向 .NET Framework 公开 COM 组件](https://docs.microsoft.com/zh-cn/dotnet/framework/interop/exposing-com-components)。

### 向 COM 公开 C#

COM 客户端可以使用已经正确公开的 C# 类型。 公开 C# 类型的基本步骤如下所示：

1. 在 C# 项目中添加互操作特性。

   可通过修改 Visual C# 项目属性使程序集 COM 可见。 有关详细信息，请参阅[“程序集信息”对话框](https://docs.microsoft.com/zh-cn/visualstudio/ide/reference/assembly-information-dialog-box)。

2. 生成 COM 类型库并对它进行注册以供 COM 使用。

   可修改 Visual C# 项目属性以自动注册 COM 互操作的 C# 程序集。 Visual Studio 通过 `/tlb` 命令行开关使用 [Regasm.exe（程序集注册工具）](https://docs.microsoft.com/zh-cn/dotnet/framework/tools/regasm-exe-assembly-registration-tool)。此工具使用托管组件作为输入，以生成类型库。 此类型库描述程序集中的 `public` 类型并添加注册表项，以便 COM 客户端可以创建托管类。

有关详细信息，请参阅[向 COM 公开 .NET Framework 组件](https://docs.microsoft.com/zh-cn/dotnet/framework/interop/exposing-dotnet-components-to-com)和 [COM 类示例](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/interop/example-com-class)。

## [How to: Access Office Interop Objects by Using Visual C# Features](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/interop/how-to-access-office-onterop-objects)

Visual C# 具有一些功能，可简化对 Office API 对象的访问。 这些新功能包括命名实参和可选实参、名为 `dynamic`的新类型，以及在 COM 方法中将实参传递为引用形参（就像它们是值形参）的功能。

在本主题中，你将利用这些新功能来编写创建并显示 Microsoft Office Excel 工作表的代码。 然后，你将编写添加包含链接到 Excel 工作表的图标的 Office Word 文档的代码。

若要完成本演练，你的计算机上必须安装 Microsoft Office Excel 2007 和 Microsoft Office Word 2007 或更高版本。

如果你使用的操作系统早于 Windows Vista，请确保安装 .NET Framework 2.0。

> 以下说明中的某些 Visual Studio 用户界面元素在计算机上出现的名称或位置可能会不同。 这些元素取决于你所使用的 Visual Studio 版本和你所使用的设置。 有关详细信息，请参阅[个性化设置 IDE](https://docs.microsoft.com/zh-cn/visualstudio/ide/personalizing-the-visual-studio-ide)。

### 创建新的控制台应用程序

1. 启动 Visual Studio。

2. 在 **“文件”** 菜单上，指向 **“新建”**，然后单击 **“项目”**。 此时将出现“新建项目”对话框。

3. 在“已安装的模板”窗格中，展开“Visual C#”，然后单击“Windows”。

4. 查看“新建项目”对话框的顶部，确保“.NET Framework 4”（或更高版本）选为目标框架。

5. 在“模板”窗格中，单击“控制台应用程序”。

6. 在“名称”字段中键入项目的名称。

7. 单击 **“确定”**。

   新项目将出现在“解决方案资源管理器”中。

### 添加引用

1. 在“解决方案资源管理器”中，右键单击你的项目名称，然后单击“添加引用”。 此时会显示“添加引用”对话框。
2. 在“程序集”页上，在“组件名称”列表中选择“Microsoft.Office.Interop.Word”，然后按住 Ctrl 键并选择“Microsoft.Office.Interop.Excel”。 如果看不到程序集，可能需要确保它们已安装并显示（请参阅[操作说明：安装 Office 主互操作程序集](https://docs.microsoft.com/zh-cn/visualstudio/vsto/how-to-install-office-primary-interop-assemblies)）
3. 单击 **“确定”**。

### 添加必要的 using 指令

1. 在“解决方案资源管理器”中，右键单击“Program.cs”文件，然后单击“查看代码”。

2. 将以下 `using` 指令添加到代码文件的顶部。

   ```csharp
   using Excel = Microsoft.Office.Interop.Excel;
   using Word = Microsoft.Office.Interop.Word;
   ```

### 创建银行帐户列表

1. 将以下类定义粘贴到“Program.cs”中的 `Program` 类下。

   ```csharp
   public class Account
   {
       public int ID { get; set; }
       public double Balance { get; set; }
   }
   ```

2. 将以下代码添加到 `Main` 方法，以创建包含两个帐户的 `bankAccounts` 列表。

   ```csharp
   // Create a list of accounts.
   var bankAccounts = new List<Account> {
       new Account { 
                     ID = 345678,
                     Balance = 541.27
                   },
       new Account {
                     ID = 1230221,
                     Balance = -127.44
                   }
   };
   ```

### 声明将帐户信息导出到 Excel 的方法

1. 将以下方法添加到 `Program` 类以设置 Excel 工作表。

   方法 [Microsoft.Office.Interop.Excel.Workbooks.Add*](https://msdn.microsoft.com/library/microsoft.office.interop.excel.workbooks.add(v=office.15).aspx) 有一个可选参数，用于指定特定的模板。 如果希望使用形参的默认值，你可以借助可选形参（C# 4 中新增）忽略该形参的实参。 由于以下代码中未发送任何参数，`Add` 将使用默认模板并创建新的工作簿。 C# 早期版本中的等效语句要求提供一个占位符参数：`ExcelApp.Workbooks.Add(Type.Missing)`。

   ```csharp
   static void DisplayInExcel(IEnumerable<Account> accounts)
   {
       var excelApp = new Excel.Application();
       // Make the object visible.
       excelApp.Visible = true;
   
       // Create a new, empty workbook and add it to the collection returned 
       // by property Workbooks. The new workbook becomes the active workbook.
       // Add has an optional parameter for specifying a praticular template. 
       // Because no argument is sent in this example, Add creates a new workbook. 
       excelApp.Workbooks.Add();
   
       // This example uses a single workSheet. The explicit type casting is
       // removed in a later procedure.
       Excel._Worksheet workSheet = (Excel.Worksheet)excelApp.ActiveSheet;
   }
   ```

2. 在 `DisplayInExcel` 的末尾添加以下代码。 代码将值插入工作表第一行的前两列。

   ```csharp
   // Establish column headings in cells A1 and B1.
   workSheet.Cells[1, "A"] = "ID Number";
   workSheet.Cells[1, "B"] = "Current Balance";
   ```

3. 在 `DisplayInExcel` 的末尾添加以下代码。 `foreach` 循环将帐户列表中的信息放入工作表连续行的前两列。

   ```csharp
   var row = 1;
   foreach (var acct in accounts)
   {
       row++;
       workSheet.Cells[row, "A"] = acct.ID;
       workSheet.Cells[row, "B"] = acct.Balance;
   }
   ```

4. 在 `DisplayInExcel` 的末尾添加以下代码以将列宽调整为适合内容。

   ```csharp
   workSheet.Columns[1].AutoFit();
   workSheet.Columns[2].AutoFit();
   ```

   早期版本的 C# 要求显式强制转换这些操作，因为 `ExcelApp.Columns[1]` 返回 `Object` 且 `AutoFit` 为 Excel [Range](https://msdn.microsoft.com/library/microsoft.office.interop.excel.range.aspx) 方法。 以下各行显示强制转换。

   ```csharp
   ((Excel.Range)workSheet.Columns[1]).AutoFit();
   ((Excel.Range)workSheet.Columns[2]).AutoFit();
   ```

   如果程序集由 [/link](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/link-compiler-option) 编译器选项引用或者如果 Excel 的“嵌入互操作类型”属性设置为 true，则 C# 4 及更高版本会自动将返回的 `Object` 转换为 `dynamic`。 True 是此属性的默认值。

### 运行项目

1. 在 `Main` 的末尾添加以下行。

   ```csharp
   // Display the list in an Excel spreadsheet.
   DisplayInExcel(bankAccounts);
   ```

2. 按 Ctrl+F5。

   出现包含两个帐户数据的 Excel 工作表。

### 添加 Word 文档

1. 若要说明 C# 4 以及更高版本在其他哪些方面增强了 Office 编程，可以使用以下代码打开 Word 应用程序并创建链接到 Excel 工作表的图标。

   将方法 `CreateIconInWordDoc`（在此步骤后面提供）粘贴到 `Program` 类中。 `CreateIconInWordDoc` 使用命名参数和可选参数来降低对 [Microsoft.Office.Interop.Word.Documents.Add*](https://msdn.microsoft.com/library/microsoft.office.interop.word.documents.add(v=office.15).aspx) 和 [PasteSpecial](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.office.interop.word.selection.pastespecial) 方法调用的复杂性。 这些调用合并了其他两项新功能，这两项新功能在简化对具有引用参数的 COM 方法的调用的 C# 4 中引入。 首先，你可以将实参发送到引用形参，就像它们是值形参一样。 即，你可以直接发送值，而无需为每个引用参数创建变量。 编译器会生成临时变量以保存参数值，并将在你从调用返回时丢弃变量。 其次，你可以忽略参数列表中的 `ref` 关键字。

   `Add` 方法有四个引用参数，所有引用参数都是可选的。 在 C# 4 或更高版本中，如果希望使用其默认值，可以忽略任何或所有形参的实参。 在 Visual C# 2008 以及更早版本中，由于形参是引用形参，因此必须为每个形参提供实参且实参必须是变量。

   `PasteSpecial` 方法可插入剪贴板的内容。 该方法有七个引用参数，所有引用参数都是可选的。 以下代码为其中两个形参指定实参：`Link` 用于创建指向剪贴板内容源的链接，`DisplayAsIcon` 用于将链接显示为图标。 在 C# 4 中，你可以对其中两个形参使用命名实参而忽略其他形参。 尽管这些是引用形参，你也不必使用 `ref` 关键字，或者创建变量以实参形式发送。 你可以直接发送值。 在 Visual C# 2008 以及早期版本中，你必须为每个引用形参发送变量实参。

   ```csharp
   static void CreateIconInWordDoc()
   {
       var wordApp = new Word.Application();
       wordApp.Visible = true;
   
       // The Add method has four reference parameters, all of which are 
       // optional. Visual C# allows you to omit arguments for them if
       // the default values are what you want.
       wordApp.Documents.Add();
   
       // PasteSpecial has seven reference parameters, all of which are 
       // optional. This example uses named arguments to specify values 
       // for two of the parameters. Although these are reference 
       // parameters, you do not need to use the ref keyword, or to create 
       // variables to send in as arguments. You can send the values directly.
       wordApp.Selection.PasteSpecial( Link: true, DisplayAsIcon: true);
   }
   ```

   在 Visual C# 2008 或早期版本的语言中，需要以下更复杂的代码。

   ```csharp
   static void CreateIconInWordDoc2008()
   {
       var wordApp = new Word.Application();
       wordApp.Visible = true;
   
       // The Add method has four parameters, all of which are optional. 
       // In Visual C# 2008 and earlier versions, an argument has to be sent 
       // for every parameter. Because the parameters are reference  
       // parameters of type object, you have to create an object variable
       // for the arguments that represents 'no value'. 
   
       object useDefaultValue = Type.Missing;
   
       wordApp.Documents.Add(ref useDefaultValue, ref useDefaultValue,
           ref useDefaultValue, ref useDefaultValue);
   
       // PasteSpecial has seven reference parameters, all of which are
       // optional. In this example, only two of the parameters require
       // specified values, but in Visual C# 2008 an argument must be sent
       // for each parameter. Because the parameters are reference parameters,
       // you have to contruct variables for the arguments.
       object link = true;
       object displayAsIcon = true;
   
       wordApp.Selection.PasteSpecial( ref useDefaultValue,
                                       ref link,
                                       ref useDefaultValue,
                                       ref displayAsIcon,
                                       ref useDefaultValue,
                                       ref useDefaultValue,
                                       ref useDefaultValue);
   }
   ```

2. 在 `Main` 的末尾添加以下语句。

   ```csharp
   // Create a Word document that contains an icon that links to
   // the spreadsheet.
   CreateIconInWordDoc();
   ```

3. 在 `DisplayInExcel` 的末尾添加以下语句。 `Copy` 方法可将工作表添加到剪贴板。

   ```csharp
   // Put the spreadsheet contents on the clipboard. The Copy method has one
   // optional parameter for specifying a destination. Because no argument  
   // is sent, the destination is the Clipboard.
   workSheet.Range["A1:B3"].Copy();
   ```

4. 按 Ctrl+F5。

   将出现包含图标的 Word 文档。 双击该图标以将工作表置于前台。

### 设置嵌入互操作类型属性

1. 当调用运行时不需要主互操作程序集 (PIA) 的 COM 类型时，可能实现其他增强。 删除 PIA 的依赖项可实现版本独立性并且更易于部署。 若要详细了解不使用 PIA 编程的优势，请参阅[演练：嵌入托管程序集中的类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/assemblies-gac/walkthrough-embedding-types-from-managed-assemblies-in-visual-studio)。

   此外，由于可以通过使用类型 `dynamic`（而非 `Object`）表示 COM 方法必需并返回的类型，因此更易于编程。 具有类型 `dynamic` 的变量在运行时以前均不会计算，从而消除了显式强制转换的需要。 有关更多信息，请参见[使用类型 dynamic](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/types/using-type-dynamic)。

   在 C# 4 中，默认行为是嵌入类型信息，而不是使用 PIA。 由于该默认行为，因此不需要显式强制转换，之前的几个示例也得到简化。 例如，`worksheet` 中 `DisplayInExcel` 的声明会写为 `Excel._Worksheet workSheet = excelApp.ActiveSheet` 而非 `Excel._Worksheet workSheet = (Excel.Worksheet)excelApp.ActiveSheet`。 在相同方法中对 `AutoFit` 的调用还将要求在不进行默认行为的情况下显式强制转换，因为 `ExcelApp.Columns[1]` 返回 `Object`，并且 `AutoFit`为 Excel 方法。 以下代码显示强制转换。

   ```csharp
   ((Excel.Range)workSheet.Columns[1]).AutoFit();
   ((Excel.Range)workSheet.Columns[2]).AutoFit();
   ```

2. 若要更改默认行为并使用 PIA 代替嵌入类型信息，请展开“解决方案资源管理器”中的“引用”节点，然后选择“Microsoft.Office.Interop.Excel”或“Microsoft.Office.Interop.Word”。

3. 如果看不到“属性”窗口，请按“F4”。

4. 在属性列表中找到“嵌入互操作类型”，将其值更改为“False”。 同样地，你还可以通过在命令提示符下使用 [/reference](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/reference-compiler-option) 编译器选项代替 [/link](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/link-compiler-option) 进行编译。

### 将其他格式添加到表格

1. 将在 `AutoFit` 中对 `DisplayInExcel` 的两个调用替换为以下语句。

   ```csharp
   // Call to AutoFormat in Visual C# 2010.
   workSheet.Range["A1", "B3"].AutoFormat(
       Excel.XlRangeAutoFormat.xlRangeAutoFormatClassic2);
   ```

   [AutoFormat](https://docs.microsoft.com/dotnet/api/microsoft.office.interop.excel.range.autoformat) 方法有七个值参数，所有引用参数都是可选的。 使用命名自变量和可选自变量，你可以为这些自变量中的所有或部分提供自变量，也可以不为它们中的任何一个提供。 在上一条语句中，仅为其中一个形参 `Format` 提供实参。 由于 `Format` 是参数列表中的第一个参数，因此无需提供参数名称。 但是，如果包含参数名称，语句则可能更易于理解，如以下代码所示。

   ```csharp
   // Call to AutoFormat in Visual C# 2010.
   workSheet.Range["A1", "B3"].AutoFormat(Format:
       Excel.XlRangeAutoFormat.xlRangeAutoFormatClassic2);
   ```

2. 按 Ctrl+F5 查看结果。 其他格式在 [XlRangeAutoFormat](https://docs.microsoft.com/dotnet/api/microsoft.office.interop.excel.xlrangeautoformat) 枚举中列出。

3. 将步骤 1 中的语句与以下代码比较（以下代码显示 Visual C# 2008 或早期版本中要求的参数）。

   ```csharp
   // The AutoFormat method has seven optional value parameters. The
   // following call specifies a value for the first parameter, and uses 
   // the default values for the other six. 
   
   // Call to AutoFormat in Visual C# 2008. This code is not part of the
   // current solution.
   excelApp.get_Range("A1", "B4").AutoFormat(Excel.XlRangeAutoFormat.xlRangeAutoFormatTable3, 
       Type.Missing, Type.Missing, Type.Missing, Type.Missing, Type.Missing, 
       Type.Missing);
   ```

### 示例

以下代码显示完整示例。

```csharp
using System;
using System.Collections.Generic;
using System.Linq;
using Excel = Microsoft.Office.Interop.Excel;
using Word = Microsoft.Office.Interop.Word;


namespace OfficeProgramminWalkthruComplete
{
    class Walkthrough
    {
        static void Main(string[] args)
        {
            // Create a list of accounts.
            var bankAccounts = new List<Account> 
            {
                new Account { 
                              ID = 345678,
                              Balance = 541.27
                            },
                new Account {
                              ID = 1230221,
                              Balance = -127.44
                            }
            };

            // Display the list in an Excel spreadsheet.
            DisplayInExcel(bankAccounts);

            // Create a Word document that contains an icon that links to
            // the spreadsheet.
            CreateIconInWordDoc();
        }

        static void DisplayInExcel(IEnumerable<Account> accounts)
        {
            var excelApp = new Excel.Application();
            // Make the object visible.
            excelApp.Visible = true;

            // Create a new, empty workbook and add it to the collection returned 
            // by property Workbooks. The new workbook becomes the active workbook.
            // Add has an optional parameter for specifying a praticular template. 
            // Because no argument is sent in this example, Add creates a new workbook. 
            excelApp.Workbooks.Add();

            // This example uses a single workSheet. 
            Excel._Worksheet workSheet = excelApp.ActiveSheet;

            // Earlier versions of C# require explicit casting.
            //Excel._Worksheet workSheet = (Excel.Worksheet)excelApp.ActiveSheet;

            // Establish column headings in cells A1 and B1.
            workSheet.Cells[1, "A"] = "ID Number";
            workSheet.Cells[1, "B"] = "Current Balance";

            var row = 1;
            foreach (var acct in accounts)
            {
                row++;
                workSheet.Cells[row, "A"] = acct.ID;
                workSheet.Cells[row, "B"] = acct.Balance;
            }

            workSheet.Columns[1].AutoFit();
            workSheet.Columns[2].AutoFit();

            // Call to AutoFormat in Visual C#. This statement replaces the 
            // two calls to AutoFit.
            workSheet.Range["A1", "B3"].AutoFormat(
                Excel.XlRangeAutoFormat.xlRangeAutoFormatClassic2);

            // Put the spreadsheet contents on the clipboard. The Copy method has one
            // optional parameter for specifying a destination. Because no argument  
            // is sent, the destination is the Clipboard.
            workSheet.Range["A1:B3"].Copy();
        }

        static void CreateIconInWordDoc()
        {
            var wordApp = new Word.Application();
            wordApp.Visible = true;

            // The Add method has four reference parameters, all of which are 
            // optional. Visual C# allows you to omit arguments for them if
            // the default values are what you want.
            wordApp.Documents.Add();

            // PasteSpecial has seven reference parameters, all of which are 
            // optional. This example uses named arguments to specify values 
            // for two of the parameters. Although these are reference 
            // parameters, you do not need to use the ref keyword, or to create 
            // variables to send in as arguments. You can send the values directly.
            wordApp.Selection.PasteSpecial(Link: true, DisplayAsIcon: true);
        }
    }

    public class Account
    {
        public int ID { get; set; }
        public double Balance { get; set; }
    }
}
```

## [How to: Use Indexed Properties in COM Interop Programming](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/interop/how-to-use-indexed-properties-in-com-interop-rogramming)

索引属性改进了在 C# 编程中使用具有参数的 COM 属性的方式。 结合使用索引属性与 Visual C# 中的其他功能（如[命名实参和可选实参](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/named-and-optional-arguments)、一种新类型（[动态](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/dynamic)）以及[嵌入类型信息](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/assemblies-gac/walkthrough-embedding-types-from-managed-assemblies-in-visual-studio)）可以增强 Microsoft Office 编程。

在早期版本的 C# 中，仅当 `get` 方法没有参数且 `set` 方法有且只有一个值参数时，方法才能作为属性访问。 但是，并非所有 COM 属性都符合上述限制。 例如，Excel [Range](https://docs.microsoft.com/dotnet/api/microsoft.office.interop.excel.range.range) 属性具有一个 `get` 访问器，它需要该范围名称的一个参数。 过去，由于无法直接访问 `Range` 属性，因此必须使用 `get_Range` 方法，如以下示例所示。

```csharp
// Visual C# 2008 and earlier.
var excelApp = new Excel.Application();
// . . .
Excel.Range targetRange = excelApp.get_Range("A1", Type.Missing);
```

利用索引属性，你可以改为编写以下代码：

```csharp
// Visual C# 2010.
var excelApp = new Excel.Application();
// . . .
Excel.Range targetRange = excelApp.Range["A1"];
```

> 上一示例还使用了[可选实参](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/named-and-optional-arguments)功能，以便忽略 `Type.Missing`。

与在 Visual C# 2008 及更早版本中设置 [Range](https://msdn.microsoft.com/library/microsoft.office.interop.excel.range.aspx) 对象的 `Value` 属性的值类似，需要两个参数。 一个为指定范围值类型的可选参数提供实参。 另一个提供 `Value` 属性的值。 下面的示例说明了这些方法。 两者都将 A1 单元格的值设置为 `Name`。

```csharp
// Visual C# 2008.
targetRange.set_Value(Type.Missing, "Name");
// Or
targetRange.Value2 = "Name";
```

利用索引属性，你可以改为编写以下代码。

```csharp
// Visual C# 2010.
targetRange.Value = "Name";
```

你不能创建自己的索引属性。 该功能仅支持使用现有索引属性。

### 示例

以下代码显示完整示例。 若要详细了解如何设置访问 Office API 的项目，请参阅[操作说明：使用 Visual C# 功能访问 Office 互操作对象](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/interop/how-to-access-office-onterop-objects)。

```csharp
// You must add a reference to Microsoft.Office.Interop.Excel to run 
// this example.
using System;
using Excel = Microsoft.Office.Interop.Excel;

namespace IndexedProperties
{
    class Program
    {
        static void Main(string[] args)
        {
            CSharp2010();
            //CSharp2008();
        }

        static void CSharp2010()
        {
            var excelApp = new Excel.Application();
            excelApp.Workbooks.Add();
            excelApp.Visible = true;

            Excel.Range targetRange = excelApp.Range["A1"];
            targetRange.Value = "Name";
        }

        static void CSharp2008()
        {
            var excelApp = new Excel.Application();
            excelApp.Workbooks.Add(Type.Missing);
            excelApp.Visible = true;

            Excel.Range targetRange = excelApp.get_Range("A1", Type.Missing);
            targetRange.set_Value(Type.Missing, "Name");
            // Or
            //targetRange.Value2 = "Name";

        }
    }
}
```

## [How to: Use Platform Invoke to Play a Wave File](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/interop/how-to-use-platform-invoke-to-play-a-wave-file)

下面的 C# 代码示例说明了如何使用平台调用服务在 Windows 操作系统中播放波形声音文件。

### 示例

此示例代码使用 `DllImport` 将 `winmm.dll` 的 `PlaySound` 方法入口点导入为 `Form1 PlaySound()`。 本示例具有一个带按钮的简单 Windows 窗体。 单击该按钮将打开一个标准的 Windows [OpenFileDialog](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.openfiledialog) 对话框，以便你可以打开要播放的文件。 选中波形文件时，将使用 `winmm.dll` 库的 `PlaySound()` 方法进行播放。 有关此方法的详细信息，请参阅[使用 PlaySound 功能处理波形音频文件](https://docs.microsoft.com/windows/desktop/multimedia/using-playsound-to-play-waveform-audio-files)。 浏览并选择具有 .wav 扩展名的文件，然后单击“打开”以使用平台调用播放波形文件。 文本框中显示所选文件的完整路径。

通过筛选器设置对“打开文件”对话框进行筛选，以仅显示扩展名为 .wav 的文件：

```csharp
dialog1.Filter = "Wav Files (*.wav)|*.wav";
```

```csharp
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace WinSound
{
    public partial class Form1 : Form
    {
        private TextBox textBox1;
        private Button button1;

        public Form1()  //constructor
        {
            InitializeComponent();
        }

        [System.Runtime.InteropServices.DllImport("winmm.DLL", EntryPoint = "PlaySound", SetLastError = true, CharSet = CharSet.Unicode, ThrowOnUnmappableChar = true)]
        private static extern bool PlaySound(string szSound, System.IntPtr hMod, PlaySoundFlags flags);

        [System.Flags] 
        public enum PlaySoundFlags : int
        {
            SND_SYNC = 0x0000,
            SND_ASYNC = 0x0001, 
            SND_NODEFAULT = 0x0002, 
            SND_LOOP = 0x0008, 
            SND_NOSTOP = 0x0010,
            SND_NOWAIT = 0x00002000, 
            SND_FILENAME = 0x00020000, 
            SND_RESOURCE = 0x00040004 
        }

        private void button1_Click (object sender, System.EventArgs e)
        {
            OpenFileDialog dialog1 = new OpenFileDialog(); 

            dialog1.Title = "Browse to find sound file to play";
            dialog1.InitialDirectory = @"c:\";
            dialog1.Filter = "Wav Files (*.wav)|*.wav";
            dialog1.FilterIndex = 2;
            dialog1.RestoreDirectory = true;

            if(dialog1.ShowDialog() == DialogResult.OK) 
            { 
                textBox1.Text = dialog1.FileName;
                PlaySound (dialog1.FileName, new System.IntPtr(), PlaySoundFlags.SND_SYNC);
            } 
        }
    }
}
```

### 编译代码

1. 在 Visual Studio 中创建新的 C# Windows 应用程序项目，然后将其命名为“WinSound”。

2. 复制上面的代码，然后将其粘贴到 `Form1.cs` 文件的内容上。

3. 复制以下代码，然后用 `InitializeComponent()` 方法将其粘贴到 `Form1.Designer.cs` 文件中任何现有代码之后。

   ```csharp
   this.button1 = new System.Windows.Forms.Button();
   this.textBox1 = new System.Windows.Forms.TextBox();
   this.SuspendLayout();
   // 
   // button1
   // 
   this.button1.Location = new System.Drawing.Point(192, 40);
   this.button1.Name = "button1";
   this.button1.Size = new System.Drawing.Size(88, 24);
   this.button1.TabIndex = 0;
   this.button1.Text = "Browse";
   this.button1.Click += new System.EventHandler(this.button1_Click);
   // 
   // textBox1
   // 
   this.textBox1.Location = new System.Drawing.Point(8, 40);
   this.textBox1.Name = "textBox1";
   this.textBox1.Size = new System.Drawing.Size(168, 20);
   this.textBox1.TabIndex = 1;
   this.textBox1.Text = "FIle path";
   // 
   // Form1
   // 
   this.AutoScaleDimensions = new System.Drawing.SizeF(5, 13);
   this.ClientSize = new System.Drawing.Size(292, 266);
   this.Controls.Add(this.textBox1);
   this.Controls.Add(this.button1);
   this.Name = "Form1";
   this.Text = "Platform Invoke WinSound C#";
   this.ResumeLayout(false);
   this.PerformLayout();
   ```

4. 编译并运行该代码。

### .NET Framework 安全性

有关详细信息，请参阅 [.NET 中的安全性](https://docs.microsoft.com/zh-cn/dotnet/standard/security/index)。

## [Walkthrough: Office Programming (C# and Visual Basic)](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/interop/walkthrough-office-programming)

Visual Studio 在 C# 和 Visual Basic 中提供了改进 Microsoft Office 编程的功能。 有用的 C# 功能包括命名参数和可选参数以及类型为 `dynamic` 的返回值。 在 COM 编程中，可以省略 `ref` 关键字并获得索引属性的访问权限。Visual Basic 中的功能包括自动实现的属性、Lambda 表达式语句和集合初始值设定项。

两种语言都支持嵌入类型信息，从而允许在不向用户的计算机部署主互操作程序集 (PIA) 的情况下部署与 COM 组件交互的程序集。 有关详细信息，请参见[演练：嵌入托管程序集中的类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/assemblies-gac/walkthrough-embedding-types-from-managed-assemblies-in-visual-studio)。

本演练演示 Office 编程上下文中的这些功能，但其中许多功能在常规编程中也极为有用。 本演练将使用 Excel 外接应用程序创建 Excel 工作簿。 然后，将创建包含工作簿链接的 Word 文档。 最后，将介绍如何启用和禁用 PIA 依赖项。

### 系统必备

若要完成本演练，计算机上必须安装 Microsoft Office Excel 和 Microsoft Office Word。

如果你使用的操作系统早于 Windows Vista，请确保安装 .NET Framework 2.0。

 备注

以下说明中的某些 Visual Studio 用户界面元素在计算机上出现的名称或位置可能会不同。 这些元素取决于你所使用的 Visual Studio 版本和你所使用的设置。 有关详细信息，请参阅[个性化设置 IDE](https://docs.microsoft.com/zh-cn/visualstudio/ide/personalizing-the-visual-studio-ide)。

#### 设置 Excel 外接应用程序

1. 启动 Visual Studio。
2. 在 **“文件”** 菜单上，指向 **“新建”**，然后单击 **“项目”**。
3. 在“安装的模板”窗格中，展开“Visual Basic”或“Visual C#”，再展开“Office”，然后单击 Office 产品的版本年份。
4. 在“模板”窗格中，单击“Excel<版本>外接程序”。
5. 查看“模板”窗格的顶部，确保“.NET Framework 4”或更高版本出现在“目标框架”框中。
6. 如果需要，在“名称”框中键入项目的名称。
7. 单击 **“确定”**。
8. 新项目将出现在“解决方案资源管理器”中。

#### 添加引用

1. 在“解决方案资源管理器”中，右键单击你的项目名称，然后单击“添加引用”。 此时会显示“添加引用”对话框。
2. 在“程序集”选项卡上，在“组件名称”列表中选择“Microsoft.Office.Interop.Excel”版本 `<version>.0.0.0`（有关 Office 产品版本号的键，请参阅 [Microsoft 版本](https://en.wikipedia.org/wiki/Microsoft_Office#Versions)），然后按住 Ctrl 键并选择“Microsoft.Office.Interop.Word”，`version <version>.0.0.0`。 如果看不到程序集，可能需要确保它们已安装并显示（请参阅[操作说明：安装 Office 主互操作程序集](https://docs.microsoft.com/zh-cn/visualstudio/vsto/how-to-install-office-primary-interop-assemblies)）。
3. 单击 **“确定”**。

#### 添加必要的 Imports 语句或 using 指令

1. 在“解决方案资源管理器”中，右键单击“ThisAddIn.vb”或“ThisAddIn.cs”文件，然后单击“查看代码”。

2. 将以下 `Imports` 语句 (Visual Basic) 或 `using` 指令 (C#) 添加到代码文件的顶部（如果不存在）。

   ```csharp
   using System.Collections.Generic;
   using Excel = Microsoft.Office.Interop.Excel;
   using Word = Microsoft.Office.Interop.Word;
   ```

#### 创建银行帐户列表

1. 在“解决方案资源管理器”中，右键单击你的项目名称，单击“添加”，然后单击“类”。 如果使用的是 Visual Basic，则将类命名为 Account.vb；如果使用的是 C#，则将类命名为 Account.cs。 单击 **添加**。

2. 将 `Account` 类的定义替换为以下代码。 类定义使用自动实现的属性。 有关详细信息，请参阅[自动实现的属性](https://docs.microsoft.com/zh-cn/dotnet/visual-basic/programming-guide/language-features/procedures/auto-implemented-properties)。

   ```csharp
   class Account
   {
       public int ID { get; set; }
       public double Balance { get; set; }
   }
   ```

3. 若要创建包含两个帐户的 `bankAccounts` 列表，请将以下代码添加到 ThisAddIn.vb 或 ThisAddIn.cs 中的 `ThisAddIn_Startup` 方法。 列表声明使用集合初始值设定项。 有关详细信息，请参阅[集合初始值设定项](https://docs.microsoft.com/zh-cn/dotnet/visual-basic/programming-guide/language-features/collection-initializers/index)。

   ```csharp
   var bankAccounts = new List<Account> 
   {
       new Account 
       {
           ID = 345,
           Balance = 541.27
       },
       new Account 
       {
           ID = 123,
           Balance = -127.44
       }
   };
   ```

#### 将数据导出到 Excel

1. 在相同的文件中，将以下方法添加到 `ThisAddIn` 类。 该方法设置 Excel 工作薄并将数据导出到工作簿。

   ```csharp
   void DisplayInExcel(IEnumerable<Account> accounts,
              Action<Account, Excel.Range> DisplayFunc)
   {
       var excelApp = this.Application;
       // Add a new Excel workbook.
       excelApp.Workbooks.Add();
       excelApp.Visible = true;
       excelApp.Range["A1"].Value = "ID";
       excelApp.Range["B1"].Value = "Balance";
       excelApp.Range["A2"].Select();
   
       foreach (var ac in accounts)
       {
           DisplayFunc(ac, excelApp.ActiveCell);
           excelApp.ActiveCell.Offset[1, 0].Select();
       }
       // Copy the results to the Clipboard.
       excelApp.Range["A1:B3"].Copy();
   }
   ```

   此方法使用 C# 的两项新功能。 Visual Basic 中已存在这两项功能。

   - 方法 [Add](https://msdn.microsoft.com/library/microsoft.office.interop.excel.workbooks.add(v=office.15).aspx) 有一个*可选参数*，用于指定特定的模板。 如果希望使用形参的默认值，你可以借助可选形参（C# 4 中新增）忽略该形参的实参。 由于上一个示例中未发送任何参数，`Add` 将使用默认模板并创建新的工作簿。 C# 早期版本中的等效语句要求提供一个占位符参数：`excelApp.Workbooks.Add(Type.Missing)`。

     有关详细信息，请参阅[命名参数和可选参数](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/named-and-optional-arguments)。

   - [Range](https://msdn.microsoft.com/library/microsoft.office.interop.excel.range.aspx) 对象的 `Range` 和 `Offset` 属性使用“索引属性”功能。 此功能允许你通过以下典型 C# 语法从 COM 类型使用这些属性。 索引属性还允许你使用 `Value` 对象的 `Range` 属性，因此不必使用 `Value2`属性。 `Value` 属性已编入索引，但索引是可选的。 在以下示例中，可选自变量和索引属性配合使用。

     ```csharp
     // Visual C# 2010 provides indexed properties for COM programming.
     excelApp.Range["A1"].Value = "ID";
     excelApp.ActiveCell.Offset[1, 0].Select();
     ```

     在早期版本的语言中，需要以下特殊语法。

     ```csharp
     // In Visual C# 2008, you cannot access the Range, Offset, and Value
     // properties directly.
     excelApp.get_Range("A1").Value2 = "ID";
     excelApp.ActiveCell.get_Offset(1, 0).Select();
     ```

     你不能创建自己的索引属性。 该功能仅支持使用现有索引属性。

     有关详细信息，请参阅[如何：在 COM 互操作编程中使用已编制索引的属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/interop/how-to-use-indexed-properties-in-com-interop-rogramming)。

2. 在 `DisplayInExcel` 的末尾添加以下代码以将列宽调整为适合内容。

   ```csharp
   excelApp.Columns[1].AutoFit();
   excelApp.Columns[2].AutoFit();
   ```

   这些新增内容介绍了 C# 中的另一功能：处理从 COM 主机返回的 `Object` 值（如 Office），就像它们具有 [dynamic](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/dynamic) 类型一样。 当“嵌入互操作类型”设置为其默认值 `True` 时，或者由 [/link](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/link-compiler-option) 编译器选项引用程序集时，自动发生这种情况。 键入 `dynamic` 允许后期绑定（Visual Basic 已提供该功能）并可避免 Visual C# 2008 和早期版本的语言中要求的显式强制转换。

   例如，`excelApp.Columns[1]` 返回`Object`，并且 `AutoFit` 是 Excel [Range](https://msdn.microsoft.com/library/microsoft.office.interop.excel.range.aspx) 方法。 如果没有 `dynamic`，你必须将 `excelApp.Columns[1]` 返回的对象强制转换为 `Range` 的实例，然后才能调用 `AutoFit` 方法。

   ```csharp
   // Casting is required in Visual C# 2008.
   ((Excel.Range)excelApp.Columns[1]).AutoFit();
   
   // Casting is not required in Visual C# 2010.
   excelApp.Columns[1].AutoFit();
   ```

   有关嵌入互操作类型的详细信息，请参阅本主题后面部分的“查找 PIA 引用”和“还原 PIA 依赖项”程序。 有关 `dynamic` 的详细信息，请参阅 [dynamic](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/dynamic) 或[使用类型 dynamic](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/types/using-type-dynamic)。

#### 调用 DisplayInExcel

1. 在 `ThisAddIn_StartUp` 方法的末尾添加以下代码。 对 `DisplayInExcel` 的调用包含两个参数。 第一个参数是要处理的帐户列表的名称。 第二个参数是定义如何处理数据的多行 lambda 表达式。 每个帐户的 `ID` 和 `balance` 值都显示在相邻的单元格中，如果余额小于零，则相应的行显示为红色。 有关详细信息，请参阅 [Lambda 表达式](https://docs.microsoft.com/zh-cn/dotnet/visual-basic/programming-guide/language-features/procedures/lambda-expressions)。

   ```csharp
   DisplayInExcel(bankAccounts, (account, cell) =>
   // This multiline lambda expression sets custom processing rules  
   // for the bankAccounts.
   {
       cell.Value = account.ID;
       cell.Offset[0, 1].Value = account.Balance;
       if (account.Balance < 0)
       {
           cell.Interior.Color = 255;
           cell.Offset[0, 1].Interior.Color = 255;
       }
   });
   ```

2. 若要运行程序，请按 F5。 出现包含帐户数据的 Excel 工作表。

#### 添加 Word 文档

1. 在 `ThisAddIn_StartUp` 方法末尾添加以下代码，以创建包含指向 Excel 工作簿的链接的 Word 文档。

   ```csharp
   var wordApp = new Word.Application();
   wordApp.Visible = true;
   wordApp.Documents.Add();
   wordApp.Selection.PasteSpecial(Link: true, DisplayAsIcon: true);
   ```

   此代码展示 C# 中的几项新功能：省略 COM 编程中的 `ref` 关键字、命名参数以及可选参数的能力。 Visual Basic 中已存在这些功能。 [PasteSpecial](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.office.interop.word.selection.pastespecial) 方法有七个参数，所有参数都定义为可选引用参数。 通过命名实参和可选实参，你可以指定希望按名称访问的形参并仅将实参发送到这些形参。 在本示例中，发送实参以指示应创建指向剪贴板上工作簿的链接（形参 `Link`）并指示该链接应在 Word 文档中显示为图标（形参 `DisplayAsIcon`）。 Visual C# 还允许忽略这些参数的 `ref` 关键字。

#### 要运行应用程序

1. 按 F5 运行该应用程序。 Excel 启动并显示包含 `bankAccounts` 中两个帐户的信息的表。 然后，出现包含指向 Excel 表的 Word 文档。

#### 清理已完成的项目

1. 在 Visual Studio 中，单击“生成”菜单上的“清理解决方案”。 否则，每次在计算机上打开 Excel 时都会运行外接应用程序。

#### 查找 PIA 引用

1. 再次运行应用程序，但不单击“清理解决方案”。

2. 选择“开始”。 找到“Microsoft Visual Studio<版本>”，然后打开开发人员命令提示。

3. 在“Visual Studio 的开发人员命令提示”窗口中键入 `ildasm`，然后按 Enter。 此时将出现 IL DASM 窗口。

4. 在 IL DASM 窗口的“文件”菜单上，选择“文件” > “打开”。 双击“Visual Studio <版本>”，然后双击“项目”。 打开项目的文件夹，在 bin/Debug 文件夹中查找*项目名称*.dll。 双击 *项目名称*.dll。 新窗口将显示项目的属性以及对其他模块和程序集的引用。 注意，命名空间 `Microsoft.Office.Interop.Excel` 和 `Microsoft.Office.Interop.Word` 包含在程序集中。 在 Visual Studio 中，编译器默认将所需的类型从引用的 PIA 导入程序集。

   有关详细信息，请参阅[如何：查看程序集内容](https://docs.microsoft.com/zh-cn/dotnet/framework/app-domains/how-to-view-assembly-contents)。

5. 双击“清单”图标。 此时将出现包含程序集列表的窗口，这些程序集包含项目所引用的项。 `Microsoft.Office.Interop.Excel` 和 `Microsoft.Office.Interop.Word` 未包含在列表中。 由于项目需要的类型已导入程序集中，因此不需要引用 PIA。 这使得部署变得更加容易。 用户的计算机上不必存在 PIA，因为应用程序不需要部署特定版本的 PIA，应用程序可设计为与多个版本的 Office 配合使用，前提是所有版本中都存在必要的 API。

   由于不再需要部署 PIA，你可以提前创建可与多个版本的 Office（包括之前的版本）配合使用的应用程序。但是，仅当你的代码不使用你当前所使用 Office 版本中不可用的任何 API 时，此情况才适用。 特殊 API 在早期版本中是否可用并不始终明确，因此不建议使用早期版本的 Office。

    备注

   在 Office 2003 以前，Office 并不发布 PIA。 因此，生成适用于 Office 2002 或早期版本的互操作程序集的唯一方法是导入 COM 引用。

6. 关闭清单窗口和程序集窗口。

#### 还原 PIA 依赖项

1. 在“解决方案资源管理器”中，单击“显示所有文件”按钮。 展开“引用”文件夹并选择“Microsoft.Office.Interop.Excel”。 按 F4 以显示“属性”窗口。
2. 在“属性”窗口中，将“嵌入互操作类型”属性从“True”更改为“False”。
3. 对 `Microsoft.Office.Interop.Word` 重复此程序中的步骤 1 和 2。
4. 在 C# 中，在 `Autofit` 方法的末尾注释掉对 `DisplayInExcel` 的两次调用。
5. 按 F5 以验证项目是否仍正确运行。
6. 重复上一个程序的步骤 1-3 以打开程序集窗口。 注意，`Microsoft.Office.Interop.Word` 和 `Microsoft.Office.Interop.Excel` 不再位于嵌入程序集列表中。
7. 双击“清单”图标并滚动引用程序集的列表。 `Microsoft.Office.Interop.Word` 和 `Microsoft.Office.Interop.Excel` 均位于列表中。 由于应用程序引用 Excel 和 Word PIA 并且“嵌入互操作类型”属性设置为“False”，因此最终用户的计算机上必须存在两个程序集。
8. 在 Visual Studio 中，单击“生成”菜单上的“清理解决方案”以清理完成的项目。

## [Example COM Class](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/interop/example-com-class)

下面是将公开为 COM 对象的类的示例。 在将此代码放置在 .cs 文件中并添加到项目后，将“注册 COM 互操作”属性设置为“True”。 有关详细信息，请参阅[如何：注册 COM 互操作组件](https://docs.microsoft.com/previous-versions/visualstudio/visual-studio-2010/w29wacsy(v=vs.100))。

对 COM 公开 Visual C# 对象需要声明类接口、事件接口（如有必要）和类本身。 类成员必须遵循这些规则才能显示在 COM 中：

- 类必须是公开的。
- 属性、方法和事件必须是公开的。
- 必须在类接口上声明属性和方法。
- 必须在事件接口中声明事件。

该类中未在这些接口中声明的其他公共成员将对 COM 不可见，但它们对其他 .NET Framework 对象可见。

若要对 COM 公开属性和方法，则必须在类接口上声明这些属性和方法，将它们标记为 `DispId` 属性，并在类中实现它们。 在接口中声明成员的顺序是用于 COM vtable 的顺序。

若要从类中公开事件，则必须在事件接口上声明这些事件并将其标记为 `DispId` 属性。 此类不应实现此接口。

此类实现此类接口；它可以实现多个接口，但第一个实现将为默认类接口。 在此处实现向 COM 公开的方法和属性。 它们必须标记为公共，并且必须匹配类接口中的声明。 此外，在此处声明此类引发的事件。 它们必须标记为公共，并且必须匹配事件接口中的声明。

### 示例

```csharp
using System.Runtime.InteropServices;

namespace project_name
{
    [Guid("EAA4976A-45C3-4BC5-BC0B-E474F4C3C83F")]
    public interface ComClass1Interface
    {
    }

    [Guid("7BD20046-DF8C-44A6-8F6B-687FAA26FA71"), 
        InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
    public interface ComClass1Events 
    {
    }

    [Guid("0D53A3E8-E51A-49C7-944E-E72A2064F938"),
        ClassInterface(ClassInterfaceType.None),
        ComSourceInterfaces(typeof(ComClass1Events))]
    public class ComClass1 : ComClass1Interface
    {
    }
}
```

