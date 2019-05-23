# [C# Compiler Options](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/)

编译器生成可执行 (.exe) 文件、动态链接库 (.dll) 或者代码模块 (.netmodule)。

每个编译器选项均有两种形式：**-option** 和 **/option**。 此文档仅介绍 **-option** 形式。

在 Visual Studio 中，可在 Web.config 文件中设置编译器选项。 有关详细信息，请参阅 [ 元素](https://docs.microsoft.com/zh-cn/dotnet/framework/configure-apps/file-schema/compiler/compiler-element)。

[在命令行上使用 csc.exe 生成](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/command-line-building-with-csc-exe)
介绍了如何通过命令行生成 Visual C# 应用程序。

[如何：为 Visual Studio 命令行设置环境变量](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/how-to-set-environment-variables-for-the-visual-studio-command-line)
介绍了运行 vsvars32.bat 启用命令行生成的步骤。

[按类别列出的 C# 编译器选项](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/listed-by-category)
分类列出了编译器选项。

[按字母顺序列出的 C# 编译器选项](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/listed-alphabetically)
按字母顺序列出了编译器选项。

## [Command-line Building With csc.exe](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/command-line-building-with-csc-exe)

通过在命令提示符处键入 C# 编译器的可执行文件名称 (csc.exe)，可调用该编译器。

如果使用“Visual Studio 开发人员命令提示”窗口，系统将设置所有必需的环境变量。 有关如何访问此工具的信息，请参阅 [Visual Studio 开发人员命令提示](https://docs.microsoft.com/zh-cn/dotnet/framework/tools/developer-command-prompt-for-vs)主题。

如果使用标准命令提示符窗口，则必须调整路径，然后才能从计算机的任意子目录调用 csc.exe。 还必须运行 vsvars32.bat 来设置适当的环境变量以支持命令行生成操作。 有关 vsvars32.bat 的详细信息，包括它的查找和运行说明，请参阅[如何：设置 Visual Studio 命令行的环境变量](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/how-to-set-environment-variables-for-the-visual-studio-command-line)。

如果你使用的计算机只安装有 Windows 软件开发包 (SDK)，则可以在 **“SDK 命令提示符”** 处使用 C# 编译器，该窗口可通过 **“Microsoft .NET Framework SDK”** 菜单选项打开。

也可以使用 MSBuild 以编程方式生成 C# 程序。 有关详细信息，请参阅 [MSBuild](https://docs.microsoft.com/zh-cn/visualstudio/msbuild/msbuild)。

csc.exe 可执行文件通常位于 Windows 目录下的 Microsoft.NET\Framework\<Version> 文件夹中。 根据每台计算机上的具体配置，此位置可能有所不同。 如果计算机上安装了不止一个版本的 .NET Framework，您将发现此文件的多个版本。 有关此类安装的详细信息，请参阅[如何：确定安装的 .NET Framework 版本](https://docs.microsoft.com/zh-cn/dotnet/framework/migration-guide/how-to-determine-which-versions-are-installed)。

> 使用 Visual Studio IDE 生成项目时，可以在 **“输出”** 窗口显示 **“csc”** 命令以及与之关联的编译器选项。 若要显示此信息，请按照[如何：查看、保存和配置生成日志文件](https://docs.microsoft.com/zh-cn/visualstudio/ide/how-to-view-save-and-configure-build-log-files#to-change-the-amount-of-information-included-in-the-build-log)中的说明将日志数据的详细级别更改为“常规”或“详细”。 重新生成项目之后，在 **“输出”** 窗口中搜索 **“csc”** 即可找到所调用的 C# 编译器。

**在本主题中**

- [命令行语法规则](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/command-line-building-with-csc-exe#rules-for-command-line-syntax-for-the-c-compiler)
- [示例命令行](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/command-line-building-with-csc-exe#sample-command-lines-for-the-c-compiler)
- [C# 编译器和 C++ 编译器输出之间的差异](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/command-line-building-with-csc-exe#differences-between-c-compiler-and-c-compiler-output)

### C# 编译器的命令行语法规则

在解释操作系统命令行上给出的参数时，C# 编译器使用下列规则：

- 参数用空白分隔，空白可以是一个空格或制表符。
- 插入符号 (^) 未被识别为转义符或者分隔符。 在传递给程序中的 `argv` 数组之前，该字符由操作系统中的命令行分析器处理。
- 无论其中有无空白，包含在双引号 ("string") 中的字符串均被解释为单个参数。 带引号的字符串可以嵌入在自变量内。
- 前面有反斜杠的双引号 (\") 被解释为原义双引号字符 (")。
- 反斜杠按其原义解释，除非它们紧位于双引号之前。
- 如果偶数个反斜杠后跟双引号，则每对反斜杠中有一个反斜杠被置于 `argv` 数组中，而双引号被解释为字符串分隔符。
- 如果奇数个反斜杠后跟双引号，则每对反斜杠中有一个反斜杠被置于 `argv` 数组中，而双引号由剩余反斜杠进行“转义”。 这将在 `argv` 中添加一个原义双引号 (")。

### C# 编译器的示例命令行

- 编译生成 File.exe 的 File.cs：

```console
csc File.cs 
```

- 编译生成 File.dll 的 File.cs：

```console
csc -target:library File.cs
```

- 编译 File.cs 并创建 My.exe：

```console
csc -out:My.exe File.cs
```

- 编译当前目录中的所有 C# 文件，对其进行优化并定义 DEBUG 符号。 输出为 File2.exe：

```console
csc -define:DEBUG -optimize -out:File2.exe *.cs
```

- 编译当前目录中的所有 C# 文件，生成 File2.dll 的调试版本。 不显示徽标和警告：

```console
csc -target:library -out:File2.dll -warn:0 -nologo -debug *.cs
```

- 将当前目录中的所有 C# 文件编译为 Something.xyz (DLL)：

```console
csc -target:library -out:Something.xyz *.cs
```

### C# 编译器和 C++ 编译器输出之间的差异

调用 C# 编译器时，不会创建任何对象 (.obj) 文件，而是直接创建输出文件。 因此，C# 编译器不需要链接器。

## [How to: Set Environment Variables for the Visual Studio Command Line](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/how-to-set-environment-variables-for-the-visual-studio-command-line)

VsDevCmd.bat 文件设置适当的环境变量来生成命令行。

> VsDevCmd.bat 文件是一种通过 Visual Studio 2017 交付的新文件。 Visual Studio 2015 及更早版本基于相同目的使用 VSVARS32.bat。 此文件保存在 \Program Files\Microsoft Visual Studio\Version\Common7\Tools 或 Program Files (x86)\Microsoft Visual Studio\Version\Common7\Tools。

如果安装了 Visual Studio 当前版本的计算机上还安装有 Visual Studio 的早期版本，则不可在同一命令提示符窗口中运行不同版本的 VsDevCmd.bat 和 VSVARS32.BAT。 转而应在其自身的窗口中运行各版本的命令。

### 若要运行 VsDevCmd.BAT

1. 从“开始”菜单，打开“VS 2017 开发人员命令提示”。 该提示位于“Visual Studio 2017”文件夹中。

2. 更改为安装目录的 \Program Files\Microsoft Visual Studio\Version\Offering\Common7\Tools 或 \Program Files (x86)\Microsoft Visual Studio\Version\Offering\Common7\Tools 子目录。 （Version 为 2017，即当前版本。 Offering 是 Enterprise、Professional 或 Community。）

3. 通过键入“VsDevCmd”运行 VsDevCmd.bat。

   > VsDevCmd.bat 可能因计算机而异。 请勿使用其他计算机上的 VsDevCmd.bat 替换缺失或损坏的 VsDevCmd.bat 文件。 而是应重新运行安装程序以替换丢失的文件。

### 适用于 VsDevCmd.BAT 的选项

若要查看适用于 VsDevCmd.BAT 的选项，请运行以下包含 `-help` 选项的命令：

```console
VsDevCmd.bat -help
```

## [C# Compiler Options Listed by Category](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/listed-by-category)

下列编译器选项按类别排序。 关于按字母顺序排列的列表，请参阅[按字母顺序列出的 C# 编译器选项](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/listed-alphabetically)。

### 优化

| 选项                                                         | 目标                       |
| ------------------------------------------------------------ | -------------------------- |
| [-filealign](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/filealign-compiler-option) | 指定输出文件中各节的大小。 |
| [-optimize](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/optimize-compiler-option) | 启用/禁用优化。            |

### 输出文件

| 选项                                                         | 目标                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [-deterministic](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/deterministic-compiler-option) | 如果输入相同，则会导致编译器输出的程序集其二进制内容在整个编译中相同。 |
| [-doc](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/doc-compiler-option) | 指定要将已处理的文档注释写入到的 XML 文件。                  |
| [-out](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/out-compiler-option) | 指定输出文件。                                               |
| [-pathmap](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/pathmap-compiler-option) | 指定编译器输出的源路径名的映射                               |
| [/pdb](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/pdb-compiler-option) | 指定 .pdb 文件的文件名和位置。                               |
| [-platform](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/platform-compiler-option) | 指定输出平台。                                               |
| [/preferreduilang](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/preferreduilang-compiler-option) | 指定编译器输出的语言。                                       |
| [/refout](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/refout-compiler-option) | 除主程序集之外，还生成引用程序集。                           |
| [/refonly](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/refonly-compiler-option) | 生成引用程序集，而不生成主程序集。                           |
| [-target](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-compiler-option) | 使用下列五个选项之一指定输出文件的格式：[-target:appcontainerexe](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-appcontainerexe-compiler-option)、[-target:exe](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-exe-compiler-option)、[-target:library](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-library-compiler-option)、[-target:module](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-module-compiler-option)、[-target:winexe](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-winexe-compiler-option) 或 [-target:winmdobj](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-winmdobj-compiler-option)。 |
| -modulename:<string>                                         | 指定源模块的名称                                             |

### .NET Framework 程序集

| 选项                                                         | 目标                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [-addmodule](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/addmodule-compiler-option) | 指定一个或多个模块作为此程序集的一部分。                     |
| [-delaysign](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/delaysign-compiler-option) | 指示编译器添加公钥，但将此程序集保留为未签名状态。           |
| [-keycontainer](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/keycontainer-compiler-option) | 指定加密密钥容器的名称。                                     |
| [-keyfile](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/keyfile-compiler-option) | 指定包含加密密钥的文件名。                                   |
| [/lib](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/lib-compiler-option) | 指定通过 [-reference](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/reference-compiler-option) 的方式引用的程序集的位置。 |
| [-nostdlib](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/nostdlib-compiler-option) | 指示编译器不导入标准库 (mscorlib.dll)。                      |
| [-publicsign](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/publicsign-compiler-option) | 应用公钥而不签名程序集，但在程序集中设置位，来表示程序集已签名。 |
| [-reference](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/reference-compiler-option) | 从包含程序集的文件导入元数据。                               |
| -analyzer                                                    | 从此程序集（缩写形式：/a）运行分析器                         |
| -additionalfile                                              | 命名其他文件，这些文件不会直接影响代码生成，但可能由分析器用于生成错误或警告。 |

### 调试/错误检查

| 选项                                                         | 目标                                                 |
| ------------------------------------------------------------ | ---------------------------------------------------- |
| [-bugreport](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/bugreport-compiler-option) | 创建一个文件，其中包含可以轻松报告 bug 的信息。      |
| [/checked](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/checked-compiler-option) | 指定溢出数据类型边界的整数算法是否将导致运行时异常。 |
| [-debug](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/debug-compiler-option) | 指示编译器发出调试信息。                             |
| [-errorreport](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/errorreport-compiler-option) | 设置错误报告行为。                                   |
| [/fullpaths](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/fullpaths-compiler-option) | 指定编译器输出中文件的绝对路径。                     |
| [-nowarn](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/nowarn-compiler-option) | 取消编译器对指定警告的生成。                         |
| [/warn](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/warn-compiler-option) | 设置警告等级。                                       |
| [-warnaserror](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/warnaserror-compiler-option) | 将警告提升为错误。                                   |
| -ruleset:<file>                                              | 指定可禁用特定诊断的规则集文件。                     |

### 预处理器

| 选项                                                         | 目标               |
| ------------------------------------------------------------ | ------------------ |
| [-define](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/define-compiler-option) | 定义预处理器符号。 |

### 资源

| 选项                                                         | 目标                                      |
| ------------------------------------------------------------ | ----------------------------------------- |
| [-link](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/link-compiler-option) | 使指定程序集中的 COM 类型信息对项目可用。 |
| [-linkresource](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/linkresource-compiler-option) | 创建指向托管资源的链接。                  |
| [-resource](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/resource-compiler-option) | 将 .NET Framework 资源嵌入到输出文件。    |
| [-win32icon](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/win32icon-compiler-option) | 指定要插入到输出文件的 .ico 文件。        |
| [/win32res:](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/win32res-compiler-option) | 指定要插入到输出文件的 Win32 资源。       |

### 杂项

| 选项                                                         | 目标                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [@](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/response-file-compiler-option) | 指定响应文件。                                               |
| [-?](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/help-compiler-option) | 列出到 stdout 的编译器选项。                                 |
| [-baseaddress](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/baseaddress-compiler-option) | 指定要加载 DLL 的首选基址。                                  |
| [-codepage](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/codepage-compiler-option) | 指定要用于编译中所有源代码文件的代码页。                     |
| [-help](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/help-compiler-option) | 列出到 stdout 的编译器选项。                                 |
| [-highentropyva](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/highentropyva-compiler-option) | 指定可执行文件支持地址空间布局随机化 (ASLR)。                |
| [-langversion](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/langversion-compiler-option) | 指定语言版本：默认、ISO-1、ISO-2、3、4、5、6、7、7.1、7.2、7.3 或最新版本 |
| [-main](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/main-compiler-option) | 指定 Main 方法的位置。                                       |
| [-noconfig](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/noconfig-compiler-option) | 指示编译器不使用 csc.rsp 进行编译。                          |
| [-nologo](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/nologo-compiler-option) | 禁止显示编译器横幅信息。                                     |
| [-recurse](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/recurse-compiler-option) | 搜索要编译的源文件的子目录。                                 |
| [-subsystemversion](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/subsystemversion-compiler-option) | 指定可执行文件可以使用的子系统的最低版本。                   |
| [不安全](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/unsafe-compiler-option) | 启用使用 [unsafe](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/unsafe) 关键字的代码编译。 |
| [-utf8output](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/utf8output-compiler-option) | 显示使用 UTF-8 编码的编译器输出。                            |
| -parallel[+\|-]                                              | 指定是否使用并发生成 (+)。                                   |
| -checksumalgorithm:<alg>                                     | 指定用于计算 PDB 中存储的源文件校验和的算法。 受支持的值为:SHA1（默认值）或 SHA256。 |

### 已过时的选项

| 选项         | 目标           |
| ------------ | -------------- |
| -incremental | 启用增量编译。 |

## [C# Compiler Options Listed Alphabetically](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/listed-alphabetically)

下列编译器选项按字母顺序排序。 有关按类别排序的列表，请参 [按类别列出的 C# 编译器选项](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/listed-by-category)。

| 选项                                                         | 目标                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [@](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/response-file-compiler-option) | 有关更多选项，请阅读响应文件。                               |
| [-?](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/help-compiler-option) | 向 stdout 显示用法消息。                                     |
| -additionalfile                                              | 命名其他文件，这些文件不会直接影响代码生成，但可能由分析器用于生成错误或警告。 |
| [-addmodule](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/addmodule-compiler-option) | 将指定的模块链接到此程序集中                                 |
| -analyzer                                                    | 从此程序集（缩写形式：-a）运行分析器                         |
| [/appconfig](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/appconfig-compiler-option) | 在程序集绑定时指定 app.config 的位置。                       |
| [-baseaddress](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/baseaddress-compiler-option) | 指定要生成的库的基址。                                       |
| [-bugreport](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/bugreport-compiler-option) | 创建“Bug 报告”文件。 如果与 -errorreport:prompt 或 -errorreport:send 一起使用，则发送任何崩溃信息时都将随附此文件。 |
| [/checked](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/checked-compiler-option) | 使编译器生成溢出检查。                                       |
| -checksumalgorithm:<alg>                                     | 指定用于计算 PDB 中存储的源文件校验和的算法。 受支持的值为:SHA1（默认值）或 SHA256。 |
| [-codepage](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/codepage-compiler-option) | 指定在打开源文件时使用的代码页。                             |
| [-debug](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/debug-compiler-option) | 发出调试信息。                                               |
| [-define](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/define-compiler-option) | 定义条件编译符号。                                           |
| [-delaysign](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/delaysign-compiler-option) | 仅使用强名称密钥公共部分对程序集进行延迟签名。               |
| [-deterministic](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/deterministic-compiler-option) | 如果输入相同，则会导致编译器输出的程序集其二进制内容在整个编译中相同。 |
| [-doc](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/doc-compiler-option) | 指定要生成的 XML 文档文件。                                  |
| [-errorreport](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/errorreport-compiler-option) | 指定如何处理内部编译器错误；prompt、send 或 none。 默认值为 none。 |
| [-filealign](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/filealign-compiler-option) | 指定用于输出文件节的对齐方式。                               |
| [/fullpaths](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/fullpaths-compiler-option) | 使编译器生成完全限定的路径。                                 |
| [-help](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/help-compiler-option) | 向 stdout 显示用法消息。                                     |
| [-highentropyva](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/highentropyva-compiler-option) | 指定支持高熵 ASLR。                                          |
| -incremental                                                 | 启用增量编译 [已过时]。                                      |
| [-keycontainer](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/keycontainer-compiler-option) | 指定强名称密钥容器。                                         |
| [-keyfile](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/keyfile-compiler-option) | 指定强名称密钥文件。                                         |
| [-langversion:](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/langversion-compiler-option) | 指定语言版本：默认、ISO-1、ISO-2、3、4、5、6、7、7.1、7.2、7.3 或最新版本 |
| [/lib](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/lib-compiler-option) | 指定要在其中搜索引用的附加目录。                             |
| [-link](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/link-compiler-option) | 使指定程序集中的 COM 类型信息对项目可用。                    |
| [-linkresource](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/linkresource-compiler-option) | 将指定的资源链接到此程序集。                                 |
| [-main](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/main-compiler-option) | 指定包含入口点的类型（忽略所有其他可能的入口点）。           |
| [-moduleassemblyname](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/moduleassemblyname-compiler-option) | 指定一个程序集，.netmodule 可以访问其非公共类型。            |
| -modulename:<string>                                         | 指定源模块的名称                                             |
| [-noconfig](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/noconfig-compiler-option) | 指示编译器不自动包含 CSC.RSP 文件。                          |
| [-nologo](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/nologo-compiler-option) | 取消编译器版权消息。                                         |
| [-nostdlib](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/nostdlib-compiler-option) | 指示编译器不引用标准库 (mscorlib.dll)。                      |
| [-nowarn](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/nowarn-compiler-option) | 禁用特定的警告消息                                           |
| [-nowin32manifest](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/nowin32manifest-compiler-option) | 指示编译器不在可执行文件中嵌入应用程序清单。                 |
| [-optimize](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/optimize-compiler-option) | 启用/禁用优化。                                              |
| [-out](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/out-compiler-option) | 指定输出文件名（默认值：包含主类的文件或第一个文件的基名称）。 |
| -parallel[+\|-]                                              | 指定是否使用并发生成 (+)。                                   |
| [-pathmap](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/pathmap-compiler-option) | 指定编译器输出的源路径名的映射。                             |
| [/pdb](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/pdb-compiler-option) | 指定 .pdb 文件的文件名和位置。                               |
| [-platform](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/platform-compiler-option) | 限定此代码可以在其上运行的平台：x86、Itanium、x64 、anycpu 或 anycpu32bitpreferred。默认值为 anycpu。 |
| [/preferreduilang](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/preferreduilang-compiler-option) | 指定要用于编译器输出的语言。                                 |
| [-publicsign](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/publicsign-compiler-option) | 应用公钥而不签名程序集，但在程序集中设置位，来表示程序集已签名。 |
| [-recurse](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/recurse-compiler-option) | 根据通配符规范，包括当前目录及子目录下的所有文件。           |
| [-reference](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/reference-compiler-option) | 从指定的程序集文件引用元数据。                               |
| [/refout](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/refout-compiler-option) | 除主程序集之外，还生成引用程序集。                           |
| [/refonly](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/refonly-compiler-option) | 生成引用程序集，而不生成主程序集。                           |
| [-resource](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/resource-compiler-option) | 嵌入指定的资源。                                             |
| -ruleset:<file>                                              | 指定可禁用特定诊断的规则集文件。                             |
| [-subsystemversion](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/subsystemversion-compiler-option) | 指定可执行文件可以使用的子系统的最低版本。                   |
| [-target](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-compiler-option) | 使用下列四个选项之一指定输出文件的格式：[-target:appcontainerexe](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-appcontainerexe-compiler-option)、[-target:exe](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-exe-compiler-option)、[-target:library](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-library-compiler-option)、[-target:module](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-module-compiler-option)、[-target:winexe](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-winexe-compiler-option)、[-target:winmdobj](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-winmdobj-compiler-option)。 |
| [不安全](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/unsafe-compiler-option) | 允许[不安全](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/unsafe)代码。 |
| [-utf8output](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/utf8output-compiler-option) | 以 UTF-8 编码格式输出编译器消息。                            |
| [/warn](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/warn-compiler-option) | 设置警告等级 (0-4)。                                         |
| [-warnaserror](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/warnaserror-compiler-option) | 将特定警告报告为错误。                                       |
| [-win32icon](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/win32icon-compiler-option) | 对输出使用此图标。                                           |
| [-win32manifest](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/win32manifest-compiler-option) | 指定自定义 win32 清单文件。                                  |
| [/win32res:](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/win32res-compiler-option) | 指定 win32 资源文件 (.res)。                                 |

### [@](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/response-file-compiler-option)

通过 @ 选项，可以指定包含编译器选项和要编译的源代码文件的文件。

#### 语法

```
@response_file  
```

#### 自变量

`response_file`
列出了编译器选项或要编译的源代码文件的文件。

#### 备注

编译器选项和源代码文件将由编译器处理，如同在命令行被指定一样。

若要在一次编译中指定多个响应文件，请指定多个响应文件选项。 例如:

```
@file1.rsp @file2.rsp  
```

在响应文件中，多个编译器选项和源代码文件可以出现在同一行中。 单个编译器选项的指定必须出现在同一行中（不能跨行）。 响应文件的注释可以 # 符号开始。

从响应文件内指定编译器选项就如同在命令行发出这些命令。 有关详细信息，请参阅[从命令行生成](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/how-to-set-environment-variables-for-the-visual-studio-command-line)。

编译器在遇到命令选项时会进行处理。 因此，命令行参数可以重写先前在响应文件中列出的选项。 反之，响应文件中的选项也将重写先前在命令行或其他响应文件中列出的选项。

C# 提供 csc.rsp 文件，该文件与 csc.exe 文件位于同一目录。 有关 csc.rsp 的详细信息，请参阅 [-noconfig](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/noconfig-compiler-option)。

不能在 Visual Studio 开发环境中设置此编译器选项，也不能以编程方式对其进行更改。

#### 示例

以下几行来自示例响应文件：

```console
# build the first output file  
-target:exe -out:MyExe.exe source1.cs source2.cs  
```

### [-addmodule](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/addmodule-compiler-option)

此选项将添加一个模块，该模块通过将 target: module 切换到当前编译进行创建。

#### 语法

```console
-addmodule:file[;file2]  
```

#### 自变量

`file`， `file2`
包含元数据的输出文件。 该文件不能包含程序集清单。 若要导入多个文件，请用逗号或分号将文件名隔开。

#### 备注

通过 -addmodule 添加的所有模块在运行时必须位于与输出文件相同的目录中。 也就是说，在编译时可在任何目录中指定模块，但在运行时该模块必须位于应用程序目录中。 如果在运行时该模块不位于应用程序目录中，则将出现 [TypeLoadException](https://docs.microsoft.com/zh-cn/dotnet/api/system.typeloadexception)。

`file` 不能包含程序集。 例如，如果输出文件使用 [-target:module](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-module-compiler-option) 创建，其元数据可通过 -addmodule 导入。

如果输出文件通过使用 -target 选项而不是 -target:module 创建，则其元数据不能通过 -addmodule 导入，但可以通过 [-reference](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/reference-compiler-option) 导入。

此编译器选项在 Visual Studio 中不可用；项目不能引用模块。 此外，不能以编程方式更改此编译器选项。

#### 示例

编译源文件 `input.cs`，并从 `metad1.netmodule` 和 `metad2.netmodule` 添加元数据以生成 `out.exe`：

```console
csc -addmodule:metad1.netmodule;metad2.netmodule -out:out.exe input.cs  
```

### [-appconfig](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/appconfig-compiler-option)

-appconfig 编译器选项让 C# 应用程序能够在程序集绑定时将程序集的应用程序配置 (app.config) 文件的位置指定为公共语言运行时 (CLR)。

#### 语法

```console
-appconfig:file  
```

#### 自变量

`file`
必需。 包含程序集绑定设置的应用程序配置文件。

#### 备注

-appconfig 的一种用途是处理高级情形；在该情形中，程序集必须同时引用特定引用程序集的 .NET Framework 版本和 .NET Framework for Silverlight 版本。 例如，在 Windows Presentation Foundation (WPF) 中编写的 XAML 设计器可能需要为设计器用户界面引用 WPF 桌面以及随附于 Silverlight 的 WPF 子集。 同一设计器程序集必须访问这两个程序集。 默认情况下，单独引用会导致编译器错误，因为程序集绑定将这两个程序集视为等效。

通过使用 -appconfig 编译器选项，可通过使用 `<supportPortability>` 标记指定某个 app.config 文件的位置，该文件会禁用默认行为，如以下示例所示。

```
<supportPortability PKT="7cec85d7bea7798e" enable="false"/>
```

编译器将文件的位置传递给 CLR 的程序集绑定逻辑。

> 如果使用 Microsoft 生成引擎 (MSBuild) 生成应用程序，则可以通过将属性标记添加到 .csproj 文件来设置 -appconfig 编译器选项。 若要使用已在项目中设置的 app.config 文件，请将属性标记 `<UseAppConfigForCompiler>` 添加到 .csproj 文件，并将其值设置为 `true`。 若要指定不同的 app.config 文件，请添加属性标记 `<AppConfigForCompiler>` 并将其值设置为该文件的位置。

#### 示例

以下示例展示一个 app.config 文件，通过使用该文件，应用程序能够同时引用任何 .NET Framework 程序集（同时存在于后述两个实现中）的 .NET Framework 实现和 .NET Framework for Silverlight 实现。 -appconfig 编译器选项指定此 app.config 文件的位置。

```xml
<configuration>  
      <runtime>  
      <assemblyBinding>  
            <supportPortability PKT="7cec85d7bea7798e" enable="false"/>  
            <supportPortability PKT="31bf3856ad364e35" enable="false"/>  
      </assemblyBinding>  
      </runtime>  
</configuration>  
```

### [-baseaddress](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/baseaddress-compiler-option)

通过 -baseaddress 选项可指定加载 DLL 的首选基址。 若要深入了解何时且为何要使用此选项，请参阅 [Larry Osterman 的网络日志](https://blogs.msdn.microsoft.com/larryosterman/2004/07/06/why-should-i-even-bother-to-use-dlls-in-my-system/)。

#### 语法

```console
-baseaddress:address  
```

#### 自变量

`address`
DLL 的基址。 可将此地址指定为十进制数、十六进制数或八进制数。

#### 备注

DLL 的默认基址由 .NET Framework 公共语言运行时设置。

请注意，此地址中的低序字将被舍入取整。 例如，如果指定 0x11110001，它将被舍入为 0x11110000。

要完成 DLL 的签名过程，请使用具有 -R 选项的 SN.EXE。

#### 在 Visual Studio 开发环境中设置此编译器选项

1. 打开项目的“属性”页。

2. 单击“生成”属性页。

3. 单击“高级”按钮。

4. 修改“DLL 基址”属性。

   若要以编程方式设置此编译器选项，请参阅 [BaseAddress](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj80.csharpprojectconfigurationproperties3.baseaddress)。

### [-bugreport](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/bugreport-compiler-option)

指定应使调试信息置于文件中供以后分析。

#### 语法

```console
-bugreport:file  
```

#### 自变量

`file`
要包含 Bug 报告的文件的名称。

#### 备注

-bugreport 选项指定以下信息应置于 `file` 中：

- 编译中所有源代码文件副本。
- 编译中使用的编译器选项列表。
- 有关编译器、运行时和操作系统的版本信息。
- 引用的程序集和模块（保存为十六进制数字），.NET Framework 和 SDK 随附的程序集除外。
- 编译器输出（如有）。
- 问题说明（系统会提示你提供此信息）。
- 有关你认为应如何修复问题的说明（系统会提示你提供此信息）。

如果此选项与 -errorreport: prompt 或 -errorreport:send 一起使用，文件中的信息将发送到 Microsoft Corporation。

所有源代码文件的副本将放入 `file`，因此你可能希望在尽可能短小的程序中重现可疑代码缺陷。

此编译器选项在 Visual Studio 中不可用，并且无法以编程方式更改。

请注意，生成文件的内容会公开源代码，这可能会导致意外信息泄露。

### [-checked](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/checked-compiler-option)

-checked 选项指定，不在 [checked](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/checked) 或 [unchecked](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/unchecked) 关键字的范围内、并且产生的值超出数据类型范围的整数算法语句是否将导致运行时异常。

#### 语法

```console
-checked[+ | -]  
```

#### 备注

`checked` 或 `unchecked` 关键字范围内的整数算法语句不受 -checked 选项的影响。

如果不在 `checked` 或 `unchecked` 关键字范围内的整数算法语句产生的值超出数据类型范围，并且编译中使用了 -checked+（或 -checked），则该语句将在运行时导致异常。 如果编译中使用的是 -checked-，则该语句在运行时不会导致异常。

此选项的默认值为“-checked-”；溢出检查已禁用。

有时，用于生成大型应用程序的自动化工具将 -checked 设置为 +。 使用 -checked- 的一种方案：通过指定 -checked- 来替代工具的全局默认值。

#### 在 Visual Studio 开发环境中设置此编译器选项

1. 打开项目的“属性”页。 有关详细信息，请参阅 [“项目设计器”->“生成”页 (C#)](https://docs.microsoft.com/zh-cn/visualstudio/ide/reference/build-page-project-designer-csharp)。
2. 单击“生成”属性页。
3. 单击“高级”按钮。
4. 修改“检查算术溢出/下溢”属性。

要以编程方式访问此编译器选项，请参阅 [CheckForOverflowUnderflow](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj80.csharpprojectconfigurationproperties3.checkforoverflowunderflow)。

#### 示例

以下命令编译 `t2.cs`。 命令中 `-checked` 的使用指定，任何不在 `checked` 或 `unchecked` 关键字范围内以及导致数据类型以外值的结果的文件中的整数算术语句，会在运行时引发异常。

```console
csc t2.cs -checked  
```

### [-codepage](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/codepage-compiler-option)

如果所需页不是系统的当前默认代码页，则此选项指定编译期间要使用的代码页。

#### 语法

```console
-codepage:id  
```

#### 自变量

`id`
要用于编译中所有源代码文件的代码页 ID。

#### 备注

如果编译一个或多个并非是为使用计算机上默认代码页而创建的源代码文件，可使用 -codepage 选项指定应使用的代码页。 -codepage 适用于编译中的所有源代码文件。

如果源代码文件是使用计算机上采用的相同代码页创建的，或者如果是通过 UNICODE 或 UTF-8 创建的，则无需使用 -codepage。

有关如何查找系统上支持哪些代码页的信息，请参阅 [GetCPInfo](https://docs.microsoft.com/zh-cn/windows/desktop/api/winnls/nf-winnls-getcpinfo)。

此编译器选项在 Visual Studio 中不可用，并且无法以编程方式更改。

### [-debug](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/debug-compiler-option)

-debug 选项将使编译器生成调试信息，并将此信息放置在输出文件或文件中。

#### 语法

```console
-debug[+ | -]  
-debug:{full | pdbonly}  
```

#### 自变量

`+` | `-`
指定 `+` 或仅 -debug 将导致编译器生成调试信息并将此信息放在程序数据库（.pdb 文件）中。 指定 `-`（在不指定 -debug 时生效）将导致不创建任何调试信息。

`full` | `pdbonly`
指定编译器生成的调试信息的类型。 完整参数（在不指定 -debug:pdbonly 时生效）允许将调试器附加到正在运行的程序。 指定 pdbonly 允许在调试器中启动程序时进行源代码调试，但仅在正在运行的程序附加到调试器时才显示汇编程序。

#### 备注

使用此选项创建调试版本。 如果未指定 -debug、-debug+ 或 -debug:full，则无法调试程序的输出文件。

如果使用 -debug:full，请注意，对经过优化的 JIT 代码的速度和大小会存在一定影响，且对包含 -debug:full 的代码质量也有一定影响。 建议使用 -debug:pdbonly 或不使用 PDB 生成发布代码。

> -debug:pdbonly 和 -debug:full 之间的一个区别在于，使用 -debug:full，编译器将发出[DebuggableAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.diagnostics.debuggableattribute)，用于告知 JIT 编译器有可用调试信息。 因此，在使用 -debug:full 时，如果代码包含设置为 false 的 [DebuggableAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.diagnostics.debuggableattribute)，则将出现错误。

有关如何配置应用程序的调试性能的详细信息，请参阅[令映像更易于调试](https://docs.microsoft.com/zh-cn/dotnet/framework/debug-trace-profile/making-an-image-easier-to-debug)。

若要更改 .pdb 文件的位置，请参阅 [-pdb（C# 编译器选项）](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/pdb-compiler-option)。

#### 在 Visual Studio 开发环境中设置此编译器选项

1. 打开项目的“属性”页。
2. 单击“生成”属性页。
3. 单击“高级”按钮。
4. 修改“调试信息”属性。

有关如何以编程方式设置此编译器选项的信息，请参阅 [DebugSymbols](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj80.csharpprojectconfigurationproperties3.debugsymbols)。

#### 示例

将调试信息放在输出文件 `app.pdb`：

```console
csc -debug -pdb:app.pdb test.cs  
```

### [-define](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/define-compiler-option)

-define 选项将 `name` 定义为程序中所有源代码文件的符号。

#### 语法

```console
-define:name[;name2]  
```

#### 自变量

`name`， `name2`
一个或多个要定义的符号的名称。

#### 备注

-define 选项具有与使用 [#define](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-define) 预处理器指令相同的效果，但编译器选项对项目中的所有文件都有效。 符号在源文件中保持已定义状态，直到源文件中的 [#undef](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-undef) 指令删除该定义。 使用 -define 选项时，一个文件中的 `#undef` 指令不影响项目中其他的源代码文件。

可以将由此选项创建的符号同 [#if](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-if)、[#else](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-else)、[#elif](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-elif) 和 [#endif](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-endif) 一起使用，对源文件进行条件编译。

-d 是 -define 的缩写形式。

通过使用分号或逗号分隔符号名称，可用 -define 定义多个符号。 例如:

```console
-define:DEBUG;TUESDAY  
```

C# 编译器本身不定义源代码中使用的符号或宏；所有符号定义必须都是用户定义的。

> 同 C++ 等语言一样，C# `#define` 不允许为符号赋值。 例如，`#define` 不能用于创建宏或定义常数。 如果需要定义一个常数，请使用 `enum` 变量。 若要创建 C++ 风格的宏，请考虑泛型等替代项。 由于宏非常容易出错，所以 C# 不允许使用宏，但提供了更安全的替代项。

#### 在 Visual Studio 开发环境中设置此编译器选项

1. 打开项目的“属性”页。
2. 在“生成”选项卡上，键入要在“条件编译符号”框中定义的符号。 例如，如果使用以下代码示例，只需在文本框中键入 `xx`。

有关如何以编程方式设置此编译器选项的信息，请参阅 [DefineConstants](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj80.csharpprojectconfigurationproperties3.defineconstants)。

#### 示例

```csharp
// preprocessor_define.cs  
// compile with: -define:xx  
// or uncomment the next line  
// #define xx  
using System;  
public class Test   
{  
    public static void Main()   
    {  
        #if (xx)   
            Console.WriteLine("xx defined");  
        #else  
            Console.WriteLine("xx not defined");  
        #endif  
    }  
}  
```

### [-delaysign](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/delaysign-compiler-option)

此选项会使编译器在输出文件中保留空间，以便以后添加数字签名。

#### 语法

```console
-delaysign[ + | - ]
```

#### 自变量

```
+` | `-
```

如果需要完全签名的程序集，请使用 -delaysign-。 如果仅需要将公钥置于程序集中，则使用 -delaysign+。 默认值为 -delaysign-。

#### 备注

除非与 [-keyfile](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/keyfile-compiler-option) 或 [-keycontainer](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/keycontainer-compiler-option) 一同使用，否则 -delaysign 选项将不起作用。

-Delaysign 和 -publicsign 选项互斥。

在请求完全签名的程序集时，编译器会对包含清单（程序集元数据）的文件进行哈希处理，并使用私钥对哈希进行签名。 该操作创建存储在包含清单的文件中的数字签名。 在对程序集延迟签名时，编译器不会计算和存储签名，而只是在文件中保留空间以便稍后可添加签名。

例如，使用 -delaysign+ 可允许测试人员将程序集放入全局缓存中。 测试完成后，可使用[程序集链接器](https://docs.microsoft.com/zh-cn/dotnet/framework/tools/al-exe-assembly-linker)实用工具将私钥置于程序集中，对程序集进行完全签名。

有关详细信息，请参阅[创建和使用具有强名称的程序集](https://docs.microsoft.com/zh-cn/dotnet/framework/app-domains/create-and-use-strong-named-assemblies)和[延迟为程序集签名](https://docs.microsoft.com/zh-cn/dotnet/framework/app-domains/delay-sign-assembly)。

#### 在 Visual Studio 开发环境中设置此编译器选项

1. 打开项目的“属性” 页。
2. 修改“仅延迟签名”属性。

有关如何以编程方式设置此编译器选项的信息，请参阅 [DelaySign](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj80.projectproperties3.delaysign)。

### [-deterministic](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/deterministic-compiler-option)

如果输入相同，则会导致编译器生成的程序集其逐字节输出在整个编译期间中相同。

#### 语法

```
-deterministic
```

#### 备注

默认情况下，一组给定输入的编译器输出是唯一的，因为编译器会添加时间戳和随意数字生成的 GUID。 使用 `-deterministic` 选项生成确定性的程序集，只要输入保持不变，该程序集的二进制内容在整个编译中都是相同的。

出于确定性目的，编译器会考虑以下输入：

- 命令行参数序列。
- 编译器 .rsp 响应文件的内容。
- 所用编译器的精确版本及其引用的程序集。
- 当前目录路径。
- 直接或间接地显式传递到编译器的所有文件的二进制内容，包括：
  - 源文件
  - 引用的程序集
  - 引用的模块
  - 资源
  - 强名称密钥文件
  - @ 响应文件
  - 分析器
  - 规则集
  - 分析器可能使用的其他文件
- 当前区域性（针对生成诊断和异常消息的语言）。
- 在未指定编码情况下使用的默认编码（或当前代码页）。
- 编译器搜索路径（例如，由`/lib` 或 `/recurse` 指定）上文件是否存在及其内容。
- 运行编译器的 CLR 平台。
- `%LIBPATH%` 的值，该值会影响分析器的依赖项加载。

当源公开可用时，可使用确定性编译来确定是否从可信源编译二进制内容。 它还可有效用于连续生成系统，确定是否需要执行依赖于二进制内容更改的生成步骤。

### [-doc](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/doc-compiler-option)

-doc 选项可让你在 XML 文件中放置文档注释。

#### 语法

```console
-doc:file  
```

#### 自变量

`file`
XML 的输出文件（由编译的源代码文件中的注释填充）。

#### 备注

在源代码文件中，可以处理以下内容之前的文档注释，并将其添加到 XML 文件中：

- 作为[类](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/class)、[委托](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/delegate)或[接口](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/interface)的用户定义类型
- 作为字段、[事件](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/event)、[属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/using-properties)或方法的成员

包含 Main 的源代码文件首先输出到 XML 中。

若要将生成的 xml 文件与 [IntelliSense](https://docs.microsoft.com/zh-cn/visualstudio/ide/using-intellisense) 功能配合使用，请将 .xml 文件的文件名设为与要支持的程序集相同的名称，然后确保 .xml 文件与程序集位于同一目录中。 这样，在 Visual Studio 项目中引用程序集时，也会找到 .xml 文件。 有关详细信息，请参阅[提供代码注释](https://docs.microsoft.com/zh-cn/visualstudio/ide/supplying-xml-code-comments)。

除非用 [-target:module](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-module-compiler-option) 进行编译，否则 `file` 将包含 <assembly></assembly> 标记，以指定包含编译输出文件的程序集清单的文件名。

> -doc 选项适用于所有输入文件；或者，如果在项目设置中进行设置，则适用于项目中的所有文件。 若要禁用与特定文件或一段代码的文档注释相关的警告，请使用 [#pragma 警告](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-pragma-warning)。

有关从代码中的注释生成文档的方法，请参阅[建议的文档注释标记](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/recommended-tags-for-documentation-comments)。

##### 在 Visual Studio 开发环境中设置此编译器选项

1. 打开项目的“属性”页。
2. 单击“生成”选项卡。
3. 修改“XML 文档文件”属性。

有关如何以编程方式设置此编译器选项的信息，请参阅 [DocumentationFile](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj80.csharpprojectconfigurationproperties3.documentationfile)。

### [-errorreport](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/errorreport-compiler-option)

此选项提供向 Microsoft 报告 C# 内部编译错误的简便方法。

> 在 Windows Vista 和 Windows Server 2008 上，为 Visual Studio 制定的错误报告设置不会替代通过 Windows 错误报告 (WER) 制定的设置。 WER 设置始终优先于 Visual Studio 错误报告设置。

#### 语法

```console
-errorreport:{ none | prompt | queue | send }  
```

#### 自变量

**none**
不收集有关内部编译器错误的报告，或不向 Microsoft 发送报告。

**提示**
当您收到内部编译器错误时，提示您发送报告。 **提示**是在开发环境中编译应用程序时的默认值。

**queue**
将错误报告排入队列。 使用管理凭据登录时，可以报告自上次登录以来的任何故障。 系统最多每 3 天 1 次提醒你发送故障报告。 **排队**是在命令行编译应用程序时的默认值。

**发送**
自动向 Microsoft 发送内部编译器错误报告。 若要启用此选项，必须首先同意 Microsoft 数据收集策略。 首次在计算机上指定 -errorreport:send 时，编译器消息将引导你访问包含 Microsoft 数据收集策略的网站。

#### 备注

当编译器无法处理源代码文件时，会导致内部编译器错误 (ICE)。 出现 ICE 时，编译器不会生成可用于修复代码的输出文件或任何有用的诊断。

在早期版本中，收到 ICE 时，我们欢迎你与 Microsoft 产品支持服务联系以报告问题。 通过使用 -errorreport，可向 Visual C# 团队提供 ICE 信息。 你的错误报告可以帮助改进未来的编译器版本。

用户能否发送报告取决于计算机和用户策略权限。

有关错误调试器的详细信息，请参阅 [Description of the Dr.Watson for Windows (Drwtsn32.exe) Tool](https://support.microsoft.com/help/308538/description-of-the-dr--watson-for-windows-drwtsn32-exe-tool)（Windows Dr. Watson (Drwtsn32.exe) 工具的说明）。

##### 在 Visual Studio 开发环境中设置此编译器选项

1. 打开项目的“属性”页。 有关详细信息，请参阅 [“项目设计器”->“生成”页 (C#)](https://docs.microsoft.com/zh-cn/visualstudio/ide/reference/build-page-project-designer-csharp)。
2. 单击“生成”属性页。
3. 单击 **“高级”** 按钮。
4. 修改“内部编译器错误报告”属性。

有关如何以编程方式设置此编译器选项的信息，请参阅 [ErrorReport](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj80.csharpprojectconfigurationproperties3.errorreport)。

### [-filealign](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/filealign-compiler-option)

-filealign 选项用于指定输出文件中各节的大小。

#### 语法

```console
-filealign:number  
```

#### 自变量

`number`
一个值，用于指定输出文件中各节的大小。 有效值为 512、1024、2048、4096 和 8192。 这些值以字节为单位。

#### 备注

每一节都在是 -filealign 值的倍数的边界上对齐。 没有固定的默认值。 如果未指定 -filealign，则公共语言运行时在编译时会选取一个默认值。

通过指定节的大小，可以影响输出文件的大小。 修改节的大小可能对将在较小设备上运行的程序有用。

使用 [DUMPBIN](https://docs.microsoft.com/zh-cn/cpp/build/reference/dumpbin-options) 可查看有关输出文件中各节的信息。

##### 在 Visual Studio 开发环境中设置此编译器选项

1. 打开项目的“属性”页。
2. 单击“生成”属性页。
3. 单击“高级”按钮。
4. 修改“文件对齐”属性。

有关如何以编程方式设置此编译器选项的信息，请参阅 [FileAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj80.csharpprojectconfigurationproperties3.filealignment)。

### [-fullpaths](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/fullpaths-compiler-option)

-fullpaths 选项导致编译器在列出编译错误和警告时指定文件的完整路径。

#### 语法

```console
-fullpaths  
```

#### 备注

默认情况下，由编译所产生的错误和警告指定其中发现错误的文件的名称。 -fullpaths 选项导致编译器指定文件的完整路径。

此编译器选项在 Visual Studio 中不可用，并且无法以编程方式更改。

### [-help, -?](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/help-compiler-option)

此选项将一列编译器选项和每个选项的简短说明发送到 StdOut。

#### 语法

```console
-help  
-?  
```

#### 备注

如果编译中包含此选项，则不会创建任何输出文件，且不会发生任何编译。

此编译器选项在 Visual Studio 中不可用，并且无法以编程方式更改。

### [-highentropyva](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/highentropyva-compiler-option)

-highentropyva 编译器选项可向 Windows 内核提供下列信息：特定的可执行文件是否支持高熵地址空间布局随机化 (ASLR)。

#### 语法

```console
-highentropyva[+ | -]  
```

#### 自变量

`+` | `-`
此选项指定 64 位可执行文件或由 [-platform:anycpu](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/platform-compiler-option) 编译器选项标记的可执行文件支持高熵虚拟地址空间。 默认情况下，此选项处于禁用状态。 通过 -highentropyva+ 或 -highentropyva 启用它。

#### 备注

当随机化进程的地址空间布局包含在 ASLR 中时，-highentropyva 选项允许 Windows 内核的兼容版本使用更高程度的熵。 使用更高程度的熵意味着，可向内存区域（例如堆栈或堆）分配更多的地址。 因此，猜测特定内存区域的位置会更加困难。

指定 -highentropyva 编译器选项时，目标可执行文件及其依赖的任何模块在作为 64 位进程运行时，必须能够处理大于 4 GB 的指针值。

### [-keycontainer](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/keycontainer-compiler-option)

指定加密密钥容器的名称。

#### 语法

```console
-keycontainer:string  
```

#### 自变量

`string`
强名称密钥容器的名称。

#### 备注

当使用“-keycontainer”选项时，编译器将创建一个可共享的组件。 编译器在程序集清单中插入指定容器的公钥，然后使用私钥对最终的程序集进行签名。 若要生成密钥文件，请在命令行键入 `sn -k file`。 `sn -i` 将密钥对安装到容器中。 编译器在 CoreCLR 上运行时，不支持此选项。 在生成 CoreCLR 时对程序集进行签名，请使用 [-keyfile](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/keyfile-compiler-option) 选项。

如果使用 [-target:module](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-module-compiler-option) 进行编译，当使用 [-addmodule](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/addmodule-compiler-option) 将此模块编译到程序集时，密钥文件的名称将保存在模块中，且会并入程序集。

还可以将此选项指定为任何 Microsoft 中间语言 (MSIL) 模块的源代码中的自定义特性 ([System.Reflection.AssemblyKeyNameAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.assemblykeynameattribute))。

此外，可使用 [-keyfile](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/keyfile-compiler-option) 将加密信息传递给编译器。 如果希望将公钥添加到程序集清单，但希望测试完程序集后再对其签名，请使用 [-delaysign](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/delaysign-compiler-option)。

有关详细信息，请参阅[创建和使用具有强名称的程序集](https://docs.microsoft.com/zh-cn/dotnet/framework/app-domains/create-and-use-strong-named-assemblies)和[延迟为程序集签名](https://docs.microsoft.com/zh-cn/dotnet/framework/app-domains/delay-sign-assembly)。

##### 在 Visual Studio 开发环境中设置此编译器选项

1. Visual Studio 开发环境中尚未提供此编译器选项。

可通过 [AssemblyKeyContainerName](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj.projectproperties.assemblykeycontainername) 以编程方式访问此编译器选项。

### [-keyfile](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/keyfile-compiler-option)

指定包含加密密钥的文件名。

#### 语法

```console
-keyfile:file  
```

#### 自变量

| 术语   | 定义                         |
| ------ | ---------------------------- |
| `file` | 含有强名称密钥的文件的名称。 |

#### 备注

使用此选项时，编译器在程序集清单中插入指定字段的公钥，然后使用私钥对最终的程序集进行签名。 若要生成密钥文件，请在命令行键入 sn-k `file`。

如果使用 -target:module 进行编译，密钥文件的名称将保存在模块中，并在使用 [-addmodule](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/addmodule-compiler-option) 编译程序集时包含到创建的程序集中。

也可以使用 [-keycontainer](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/keycontainer-compiler-option) 将加密信息传递给编译器。 如果需要部分签名的程序集，请使用 [-delaysign](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/delaysign-compiler-option)。

如果在同一编译中同时指定 -keyfile 和 -keycontainer（通过命令行选项或通过自定义特性），则 Al.exe 将首先尝试用密钥容器。 如果成功，则使用密钥容器中的信息对程序集签名。 如果编译器没有找到密钥容器，它将尝试用 -keyfile 指定的文件。 如果成功，则使用密钥文件中的信息对程序集签名，并且将密钥信息安装到密钥容器中（类似于 sn -i），以便在下一次编译中，密钥容器选项将生效。

请注意，密钥文件可能仅包含公钥。

有关详细信息，请参阅[创建和使用具有强名称的程序集](https://docs.microsoft.com/zh-cn/dotnet/framework/app-domains/create-and-use-strong-named-assemblies)和[延迟为程序集签名](https://docs.microsoft.com/zh-cn/dotnet/framework/app-domains/delay-sign-assembly)。

##### 在 Visual Studio 开发环境中设置此编译器选项

1. 打开项目的“属性” 页。
2. 单击“签名”属性页。
3. 修改“选择强名称密钥文件”属性。

可通过 [AssemblyOriginatorKeyFile](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj.projectproperties.assemblyoriginatorkeyfile) 以编程方式访问此编译器选项。

### [-langversion](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/langversion-compiler-option)

使编译器仅接受包含在所选 C# 语言规范中的语法。

#### 语法

```console
-langversion:option  
```

#### 自变量

`option`
以下为有效值：

| 选项    | 含义                                                         |
| ------- | ------------------------------------------------------------ |
| default | 编译器接受它可支持的最新主版本中的所有有效语言语法。         |
| ISO-1   | 编译器只接受 ISO/IEC 23270:2003 C# (1.0/1.2) 中所含的语法 [ISO1](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/langversion-compiler-option#FISO1) |
| ISO-2   | 编译器只接受 ISO/IEC 23270:2006 C# (2.0) 中所含的语法 [ISO2](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/langversion-compiler-option#FISO2) |
| 3       | 编译器只接受 C# 3.0 或更低版本中所含的语法 [CS3](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/langversion-compiler-option#FCS3) |
| 4       | 编译器只接受 C# 4.0 或更低版本中所含的语法 [CS4](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/langversion-compiler-option#FCS4) |
| 5       | 编译器只接受 C# 5.0 或更低版本中所含的语法 [CS5](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/langversion-compiler-option#FCS5) |
| 6       | 编译器只接受 C# 6.0 或更低版本中所含的语法 [CS6](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/langversion-compiler-option#FCS6) |
| 7       | 编译器只接受 C# 7.0 或更低版本中所含的语法 [CS7](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/langversion-compiler-option#FCS7) |
| 7.1     | 编译器只接受 C# 7.1 或更低版本中所含的语法 [CS71](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/langversion-compiler-option#FCS71) |
| 7.2     | 编译器只接受 C# 7.2 或更低版本中所含的语法 [CS72](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/langversion-compiler-option#FCS72) |
| 7.3     | 编译器只接受 C# 7.3 或更低版本中所含的语法 [CS73](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/langversion-compiler-option#FCS73) |
| 最新    | 编译器接受它可支持的所有有效语言语法。                       |

#### 备注

C# 应用程序引用的元数据不受 -langversion 编译器选项约束。

每个版本的 C# 编译器都包含语言规范的扩展，因此 -langversion 不提供早期版本编译器的同等功能。

此外，虽然 C# 版本更新通常与主要的 .NET Framework 版本一致，但新的语法和功能不一定绑定到该特定的 Framework 版本。 虽然新功能肯定需要与 C# 修订版一起发布的新编译器更新，但每项具体功能都有自己的最小 .NET API 或公共语言运行时要求，这些要求通过包括 NuGet 包或其他库允许功能在下层框架上运行。

无论使用哪一项 -langversion 设置，都将使用当前版本的公共语言运行时来创建 .exe 或 .dll。 友元程序集和 [-moduleassemblyname（C# 编译器选项）](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/moduleassemblyname-compiler-option)是一个例外，它们在 -langversion:ISO-1 下工作。

若要了解指定 C# 语言版本的其他方式，请参阅[选择 C# 语言版本](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/configure-language-version)主题。

有关如何以编程方式设置此编译器选项的信息，请参阅 [LanguageVersion](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj80.csharpprojectconfigurationproperties3.languageversion)。

### [-lib](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/lib-compiler-option)

-lib 选项指定通过 [-reference（C# 编译器选项）](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/reference-compiler-option)选项引用的程序集的位置。

#### 语法

```console
-lib:dir1[,dir2]  
```

#### 自变量

`dir1`
在当前工作目录（调用编译器的目录）或公共语言运行时的系统目录中未找到引用的程序集时，编译器将在其中进行查找的目录。

`dir2`
要在其中搜索程序集引用的一个或多个附加目录。 用逗号分隔每个附加目录的名称，中间不要有空格。

#### 备注

编译器按以下顺序搜索未完全限定的程序集引用：

1. 当前工作目录。 该目录为从其调用编译器的目录。
2. 公共语言运行时系统目录。
3. 由 -lib 指定的目录。
4. 由 LIB 环境变量指定的目录。

使用 -reference 指定程序集引用。

-lib 是累加的；每一次指定的值都追加到以前的值中。

另一种使用 -lib 的方法是，将任何所需的程序集复制到工作目录中；这样可以仅将程序集名称传递给 -reference。 然后可以从工作目录中删除这些程序集。 由于程序集清单中未指定依赖程序集的路径，因此应用程序可以在目标计算机上启动，然后查找并使用全局程序集缓存中的程序集。

编译器可以引用程序集并不表示公共语言运行时可以在运行时找到并加载程序集。 有关运行时如何搜索引用的程序集的详细信息，请参阅[运行时如何定位程序集](https://docs.microsoft.com/zh-cn/dotnet/framework/deployment/how-the-runtime-locates-assemblies)。

##### 在 Visual Studio 开发环境中设置此编译器选项

1. 打开项目的“属性页” 对话框。
2. 单击“引用路径”属性页。
3. 修改列表框的内容。

有关如何以编程方式设置此编译器选项的信息，请参阅 [ReferencePath](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj80.projectproperties3.referencepath)。

#### 示例

编译 t2.cs 以创建 .exe 文件。 编译器将在工作目录和 C 驱动器的根目录中查找程序集引用。

```console
csc -lib:c:\ -reference:t2.dll t2.cs  
```

### [-link](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/link-compiler-option)

使编译器让指定程序集中的 COM 类型信息可供当前正在编译的项目使用。

#### 语法

```console
-link:fileList  
// -or-  
-l:fileList  
```

#### 自变量

`fileList`
必需。 程序集文件名的逗号分隔列表。 如果文件名包含空格，则将名称括在引号内。

#### 备注

`-link` 选项使你可以部署具有嵌入类型信息的应用程序。 应用程序随后可以使用运行时程序集中实现嵌入类型信息的类型，而无需引用运行时程序集。 如果发布了各种版本的运行时程序集，则包含嵌入类型信息的应用程序可以使用各种版本，而无需重新编译。 有关示例，请参阅[演练：嵌入托管程序集中的类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/assemblies-gac/walkthrough-embedding-types-from-managed-assemblies-in-visual-studio)。

在使用 COM 互操作时，使用 `-link` 选项会尤其有用。 可以嵌入 COM 类型，以便应用程序在目标计算机上不再需要主互操作程序集 (PIA)。 `-link` 选项指示编译器将引用的互操作程序集中的 COM 类型信息嵌入到生成的已编译代码中。 COM 类型由 CLSID (GUID) 值进行标识。 因此，应用程序可以在安装了具有相同 CLSID 值的相同 COM 类型的目标计算机上运行。 自动执行 Microsoft Office 的应用程序是一个很好的示例。 由于 Office 等应用程序通常在不同版本间保持相同的 CLSID 值，因此只要在目标计算机上安装了 .NET Framework 4 或更高版本，并且应用程序使用引用的 COM 类型中包含的方法、属性或事件，应用程序便可以使用引用的 COM 类型。

`-link` 选项只嵌入接口、结构和委托。 不支持嵌入 COM 类。

> 在代码中创建嵌入 COM 类型的实例时，必须使用适当的接口创建该实例。 尝试使用组件类创建嵌入 COM 类型的实例会导致错误。

若要在 Visual Studio 中设置 `-link` 选项，请添加程序集引用并将 `Embed Interop Types` 属性设置为“true”。 `Embed Interop Types` 属性的默认值为 **false**。

如果链接到本身引用了其他 COM 程序集（程序集 B）的 COM 程序集（程序集 A），则在满足以下任一条件时，还必须链接到程序集 B：

- 程序集 A 中的类型继承自程序集 B 中的类型或实现程序集 B 中的接口。
- 调用具有程序集 B 中的返回类型或参数类型的字段、属性、事件或方法。

与 [-reference](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/reference-compiler-option) 编译器选项一样，`-link` 编译器选项使用 Csc.rsp 响应文件，该文件引用常用的 .NET Framework程序集。 如果不希望编译器使用 Csc.rsp 文件，则使用 [-noconfig](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/noconfig-compiler-option) 编译器选项。

`-link` 的缩写形式是 `-l`。

#### 泛型类型和嵌入类型

以下各部分介绍对在嵌入互操作类型的应用程序中使用泛型类型的限制。

##### 泛型接口

不能使用从互操作程序集中嵌入的泛型接口。 这在下面的示例中显示。

```csharp
// The following code causes an error if ISampleInterface is an embedded interop type.
ISampleInterface<SampleType> sample;
```

##### 具有泛型参数的类型

对于具有类型是从互操作程序集嵌入的泛型参数的类型，如果该类型来自外部程序集，则无法使用这种类型。 此限制不适用于接口。 例如，考虑在 [Microsoft.Office.Interop.Excel](https://msdn.microsoft.com/library/microsoft.office.interop.excel.aspx) 程序集中定义的 [Range](https://msdn.microsoft.com/library/microsoft.office.interop.excel.range.aspx) 接口。 如果某个库从 [Microsoft.Office.Interop.Excel](https://msdn.microsoft.com/library/microsoft.office.interop.excel.aspx) 程序集嵌入互操作类型，并且公开的一个方法返回具有类型是 [Range](https://msdn.microsoft.com/library/microsoft.office.interop.excel.range.aspx) 接口的参数的泛型类型，则该方法必须返回泛型接口，如下面的代码示例所示。

```csharp
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Office.Interop.Excel;

public class Utility
{
    // The following code causes an error when called by a client assembly.
    public List<Range> GetRange1() {
```

```csharp
}

// The following code is valid for calls from a client assembly.
public IList<Range> GetRange2() {
```

```csharp
    }
}
```

在下面的示例中，客户端代码可以调用返回 [IList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ilist) 泛型接口的方法而不会出现错误。

```csharp
public class Client
{
    public void Main()
    {
        Utility util = new Utility();

        // The following code causes an error.
        List<Range> rangeList1 = util.GetRange1();

        // The following code is valid.
        List<Range> rangeList2 = (List<Range>)util.GetRange2();
    }
}
```

#### 示例

下面的代码编译源文件 `OfficeApp.cs` 并引用来自 `COMData1.dll` 和 `COMData2.dll` 的程序集以生成 `OfficeApp.exe`。

```csharp
csc -link:COMData1.dll,COMData2.dll -out:OfficeApp.exe OfficeApp.cs  
```

### [-linkresource](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/linkresource-compiler-option)

在输出文件中创建指向 .NET Framework 资源的链接。 不会在输出文件中添加资源文件。 这不同于会在输出文件中嵌入资源文件的 [-resource](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/resource-compiler-option) 选项。

#### 语法

```console
-linkresource:filename[,identifier[,accessibility-modifier]]  
```

#### 自变量

`filename`
希望从程序集链接到的 .NET Framework 资源文件。

`identifier` （可选）
资源的逻辑名称；用于加载资源的名称。 默认值是文件的名称。

`accessibility-modifier` （可选）
资源的可访问性：public 或 private。 默认值为 public。

#### 备注

默认情况下，如果使用 C# 编译器创建链接资源，则这些资源在程序集中是公有的。 若要使资源变为私有，请将 `private` 指定为可访问性修饰符。 不允许使用 `public` 或 `private` 以外的任何其他修饰符。

-linkresource 需要某个 [-target](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-compiler-option) 选项（-target:module 除外）。

例如，如果 `filename` 是由 [Resgen.exe](https://docs.microsoft.com/zh-cn/dotnet/framework/tools/resgen-exe-resource-file-generator) 创建的或在开发环境中创建的 .NET Framework 资源文件，则可使用 [System.Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.resources) 命名空间中的成员来访问它。 有关更多信息，请参见[System.Resources.ResourceManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.resources.resourcemanager)。对于所有其他资源，请使用 [Assembly](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.assembly) 类中的 `GetManifestResource` 方法在运行时访问资源。

`filename` 中指定的文件可为任何格式。 例如，你可能希望生成程序集的本机 DLL 部分，从而可将它安装到全局程序集缓存中，并且可从该程序集中的托管代码访问它。 以下示例中的第二个示例演示了如何执行此操作。 可在程序集链接器中执行相同的操作。 以下示例中的第三个示例演示了如何执行此操作。 有关详细信息，请参阅 [Al.exe（程序集链接器）](https://docs.microsoft.com/zh-cn/dotnet/framework/tools/al-exe-assembly-linker)和[使用程序集和全局程序集缓存](https://docs.microsoft.com/zh-cn/dotnet/framework/app-domains/working-with-assemblies-and-the-gac)。

-linkres 是 -linkresource 的缩写形式。

此编译器选项在 Visual Studio 中不可用，并且无法以编程方式更改。

#### 示例

编译 `in.cs` 并链接到资源文件 `rf.resource`：

```console
csc -linkresource:rf.resource in.cs  
```

#### 示例

将 `A.cs` 编译为 DLL，链接到本机 DLL N.dll，并将输出文件放在全局程序集缓存 (GAC) 中。 在此示例中，A.dll 和 N.dll 都存在于 GAC 中。

```console
csc -linkresource:N.dll -t:library A.cs  
gacutil -i A.dll  
```

#### 示例

此示例执行的操作与上一示例相同，但使用程序集链接器选项执行。

```console
csc -t:module A.cs  
al -out:A.dll A.netmodule -link:N.dll   
gacutil -i A.dll  
```

### [-main](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/main-compiler-option)

如果多个类包含 **Main** 方法，此选项将指定包含程序入口点的类。

#### 语法

```console
-main:class  
```

#### 自变量

`class`
此类型包含 **Main** 方法。
提供的类名必须是完全限定类名；它必须包括完整命名空间（包含类），后跟类名。 例如，当 `Main` 方法位于 `MyApplication.Core` 命名空间中的 `Program` 类中时，编译器选项必须为 `-main:MyApplication.Core.Program`。

#### 备注

如果编译包含具有 [Main](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/main-and-command-args/index) 方法的多个类型，则可以指定哪个类型包含你想用作程序入口点的 **Main** 方法。

此选项用于编译 .exe 文件。

##### 在 Visual Studio 开发环境中设置此编译器选项

1. 打开项目的“属性”页。

2. 单击“应用程序”属性页。

3. 修改“启动对象”属性。

   若要以编程方式设置此编译器选项，请参阅 [StartupObject](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj80.projectproperties3.startupobject)。

#### 示例

编译 `t2.cs` 和 `t3.cs`，指出 **Main** 方法可在 `Test2` 中找到：

```console
csc t2.cs t3.cs -main:Test2  
```

### [-moduleassemblyname](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/moduleassemblyname-compiler-option)

指定一个程序集，.netmodule 可以访问其非公共类型。

#### 语法

```console
-moduleassemblyname:assembly_name  
```

#### 自变量

`assembly_name`
.netmodule 可以访问其非公共类型的程序集的名称。

#### 备注

生成 .netmodule 时，应使用 -moduleassemblyname 并满足以下条件：

- .netmodule 需要具有访问现有程序集中非公共类型的权限。
- 知道生成后的 .netmodule 所在程序集的名称。
- 现有程序集已经获得有元程序集访问权限，可访问生成后的 .netmodule 所在的程序集。

有关生成 .netmodule 的详细信息，请参阅 [-target: module（C# 编译器选项）](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-module-compiler-option)。

有关友元程序集的详细信息，请参阅[友元程序集](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/assemblies-gac/friend-assemblies)。

此选项不适用于开发环境内，仅当从命令行编译时可用。

此编译器选项在 Visual Studio 中不可用，并且无法以编程方式更改。

#### 示例

此示例将生成包含私有类型的程序集，并且授予名为 csman_an_assembly 的程序集友元程序集访问权限。

```csharp
// moduleassemblyname_1.cs  
// compile with: -target:library  
using System;  
using System.Runtime.CompilerServices;  
  
[assembly:InternalsVisibleTo ("csman_an_assembly")]  
  
class An_Internal_Class   
{  
    public void Test()   
    {   
        Console.WriteLine("An_Internal_Class.Test called");   
    }  
}  
```

#### 示例

该例生成一个可访问程序集 moduleassemblyname_1.dll 中非公共类型的 .netmodule。 通过了解此 .netmodule 在生成后所在的程序集（名为 csman_an_assembly），可以指定 -moduleassemblyname，以便 .netmodule 在已经获得 csman_an_assembly 的友元程序集访问权限的程序集中访问非公共类型。

```csharp
// moduleassemblyname_2.cs  
// compile with: -moduleassemblyname:csman_an_assembly -target:module -reference:moduleassemblyname_1.dll  
class B {  
    public void Test() {  
        An_Internal_Class x = new An_Internal_Class();  
        x.Test();  
    }  
}  
```

#### 示例

此代码示例通过引用之前生成的程序集和 .netmodule 来生成程序集 csman_an_assembly。

```csharp
// csman_an_assembly.cs  
// compile with: -addmodule:moduleassemblyname_2.netmodule -reference:moduleassemblyname_1.dll  
class A {  
    public static void Main() {  
        B bb = new B();  
        bb.Test();  
    }  
}  
```

已调用 An_Internal_Class.Test

### [-noconfig](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/noconfig-compiler-option)

-noconfig 选项告知编译器不要在 csc.rsp 文件中编译，该文件的位置和加载位置是与 csc.exe 文件相同的目录。

#### 语法

```console
-noconfig  
```

#### 备注

csc.rsp 文件引用 .NET Framework 随附的所有程序集。 Visual Studio .NET 开发环境包括的实际引用取决于项目类型。

可以修改 csc.rsp 文件并使用 csc.exe 的命令行指定每个编译中应包含的其他编译器选项（-noconfig 选项外）。

编译器将处理最后传递给 csc 命令的选项。 因此，命令行中的任何选项都将替代 csc.rsp 文件中相同选项的设置。

如果不希望编译器查询和使用 csc.rsp 文件中的设置，请指定 -noconfig。

此编译器选项在 Visual Studio 中不可用，并且无法以编程方式更改。

### [-nologo](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/nologo-compiler-option)

-nologo 选项可在编译器启动时取消显式登录版权标志并在编译期间取消显示信息性消息。

#### 语法

```console
-nologo  
```

#### 备注

此选项不适用于开发环境内，仅当从命令行编译时可用。

此编译器选项在 Visual Studio 中不可用，并且无法以编程方式更改。

### [-nostdlib](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/nostdlib-compiler-option)

-nostdlib 可防止导入 mscorlib.dll，后者定义了整个 System 命名空间。

#### 语法

```console
-nostdlib[+ | -]
```

#### 备注

如果你想要定义或创建自己的 System 命名空间和对象，请使用此选项。

如果未指定 -nostdlib，则 mscorlib.dll 将被导入到程序中（与指定 -nostdlib- 相同）。 指定 -nostdlib 与指定 -nostdlib+ 相同。

##### 在 Visual Studio 中设置此编译器选项

> 以下说明仅适用于 Visual Studio 2015（及更早版本）。 Visual Studio 2017 中不存在“不引用 mscorlib.dll”生成属性。

1. 打开项目的“属性” 页。
2. 单击“生成” 属性页。
3. 单击 **“高级”** 按钮。
4. 修改“不引用 mscorlib.dll” 属性。

##### 以编程方式设置此编译器选项

有关如何以编程方式设置此编译器选项的信息，请参阅 [NoStdLib](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj80.csharpprojectconfigurationproperties3.nostdlib)。

### [-nowarn](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/nowarn-compiler-option)

使用 -nowarn 选项可以禁止编译器显示一个或多个警告。 使用逗号分隔多个警告编号。

#### 语法

```console
-nowarn:number1[,number2,...]  
```

#### 自变量

`number1`， `number2`
希望编译器禁止显示的警告编号。

#### 备注

只应指定警告标识符的数值部分。 例如，如果要禁止显示 CS0028，则可以指定 `-nowarn:28`。

编译器会以无提示方式忽略传递给 `-nowarn` 的警告编号，这些编号在早期版本中有效，但已从编译器中移除。例如，CS0679 在 Visual Studio .NET 2002 的编译器中有效，但是在后来已移除。

无法通过 `-nowarn` 选项禁止显示以下警告：

- 编译器警告（等级 1）CS2002
- 编译器警告（等级 1）CS2023
- 编译器警告（等级 1）CS2029

##### 在 Visual Studio 开发环境中设置此编译器选项

1. 打开项目的“属性” 页。 有关详细信息，请参阅[“项目设计器”->“生成”页 (C#)](https://docs.microsoft.com/zh-cn/visualstudio/ide/reference/build-page-project-designer-csharp)。
2. 单击“生成”属性页。
3. 修改“禁止显示警告”属性。

有关如何以编程方式设置此编译器选项的信息，请参阅 [DelaySign](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj80.projectproperties3.delaysign)。

### [-nowin32manifest](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/nowin32manifest-compiler-option)

使用 -nowin32manifest 选项可指示编译器不将任何应用程序清单嵌入到可执行文件中。

#### 语法

```console
-nowin32manifest  
```

#### 备注

使用此选项时，除非在 Win32 资源文件或以后的生成步骤中提供应用程序清单，否则应用程序会受到 Windows Vista 上虚拟化的影响。

在 Visual Studio 的“应用程序属性”页中，通过在“清单”下拉列表中选择“创建不带清单的应用程序”选项来设置此选项。 有关详细信息，请参阅[“项目设计器”->“应用程序”页 (C#)](https://docs.microsoft.com/zh-cn/visualstudio/ide/reference/application-page-project-designer-csharp)。

有关创建清单的详细信息，请参阅 [-win32manifest（C# 编译器选项）](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/win32manifest-compiler-option)。

### [-optimize](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/optimize-compiler-option)

-optimize 选项启用或禁用编译器执行的优化，使输出文件更小、更快、更有效。

#### 语法

```console
-optimize[+ | -]  
```

#### 备注

-optimize 还指示公共语言运行时在运行时优化代码。

默认情况下，禁用优化。 指定 -optimize+ 可启用优化。

生成程序集使用的模块时，请使用与程序集相同的 -optimize 设置。

-o 是 -optimize 的缩写形式。

可以将 -optimize 和 [-debug](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/debug-compiler-option) 选项组合使用。

##### 在 Visual Studio 开发环境中设置此编译器选项

1. 打开项目的“属性”页。
2. 单击“生成”属性页。
3. 修改“优化代码”属性。

有关如何以编程方式设置此编译器选项的信息，请参阅 [Optimize](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj80.csharpprojectconfigurationproperties3.optimize)。

#### 示例

编译 `t2.cs` 并启用编译器优化：

```console
csc t2.cs -optimize  
```

### [-out](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/out-compiler-option)

-out 选项指定输出文件的名称。

#### 语法

```console
-out:filename  
```

#### 自变量

`filename`
编译器创建的输出文件的名称。

#### 备注

在命令行中，可以为编译指定多个输出文件。 编译器应在 -out 选项下查找一个或多个源代码文件。 然后，所有源代码文件都将编译为 -out 选项指定的输出文件。

指定想要创建的文件的完整名称和扩展名。

如果不指定输出文件的名称：

- .exe 将采用包含 Main 方法的源代码文件中的名称。
- .dll 或者 .netmodule 将从第一个源代码文件中获取其名称。

用于编译一个输出文件的源代码文件不能同样用于编译另一输出文件。

如果在命令行编译中生成多个输出文件，请记住，仅其中一个输出文件可以是程序集，且只有（使用 -out 隐式或显式）指定的第一个输出文件可以是程序集。

在编译时生成的任何模块都将成为与编译时生成的程序集关联的文件。 使用 [ildasm.exe](https://docs.microsoft.com/zh-cn/dotnet/framework/tools/ildasm-exe-il-disassembler) 查看程序集清单，了解关联文件。

为使 exe 成为友元程序集的目标，-out 编译器选项是必需的。 有关详细信息，请参阅[友元程序集](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/assemblies-gac/friend-assemblies)。

##### 在 Visual Studio 开发环境中设置此编译器选项

1. 打开项目的“属性”页。

2. 单击“应用程序”属性页。

3. 修改程序集名称属性。

   以编程方式设置此编译器选项：[OutputFileName](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj80.projectproperties3.outputfilename) 是只读属性，由项目类型（exe、库等）和程序集名称的组合决定。 设置输出文件名称必须修改一个或两个属性。

#### 示例

编译 `t.cs` 并创建输出文件 `t.exe`以及生成 `t2.cs` 并创建模块输出文件 `mymodule.netmodule`：

```console
csc t.cs -out:mymodule.netmodule -target:module t2.cs  
```

### [-pathmap](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/pathmap-compiler-option)

-pathmap 编译器选项指定如何将物理路径映射到编译器输出的源路径名称。

#### 语法

```console
-pathmap:path1=sourcePath1,path2=sourcePath2
```

#### 自变量

`path1` 当前环境中源文件的完整路径

`sourcePath1` 在任何输出文件中将源路径替换为 `path1`。

要指定多个映射的源路径，请用逗号分隔每个路径。

#### 备注

编译器将源路径写入其输出，原因如下：

1. 将 [CallerFilePathAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.compilerservices.callerfilepathattribute) 应用于可选参数时，会将源路径替换为参数。
2. PDB 文件中嵌入的源路径。
3. PDB 文件的路径嵌入到 PE（可移植的可执行文件）文件中。

此选项将编译器在其上运行的计算机上的每个物理路径映射到应写入输出文件的相应路径。

#### 示例

在目录 C:\work\tests 中编译 `t.cs` 并将该目录映射到输出中的 \publish：

```console
csc -pathmap:C:\work\tests=\publish t.cs
```

### [-pdb](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/pdb-compiler-option)

-pdb 编译器选项指定调试符号文件的名称和位置。

#### 语法

```console
-pdb:filename  
```

#### 自变量

`filename`
调试符号文件的名称和位置。

#### 备注

指定 [-debug（C# 编译器选项）](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/debug-compiler-option)后，编译器将在创建输出文件（.exe 或 .dll）的目录中创建 .pdb 文件，且名称与输出文件的名称相同。

-pdb 允许为 .pdb 文件指定非默认的文件名和位置。

不能在 Visual Studio 开发环境中设置此编译器选项，也不能以编程方式对其进行更改。

#### 示例

编译 `t.cs` 并创建名为 tt.pdb 的 .pdb 文件：

```console
csc -debug -pdb:tt t.cs  
```

### [-platform](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/platform-compiler-option)

指定公共语言运行时 (CLR) 的哪个版本可以运行程序集。

#### 语法

console复制

```console
-platform:string  
```

##### 参数

`string`
anycpu（默认值）、anycpu32bitpreferred、ARM、x64、x86 或 Itanium。

#### 备注

- anycpu（默认值）将程序集编译成可在任意平台上运行。 您的应用程序将尽可能作为 64 位进程运行；当只有 32 位模式可用时，才会回退到 32 位。
- anycpu32bitpreferred 将程序集编译成可在任意平台上运行。 在同时支持 64 位和 32 位应用程序的系统上，您的应用程序将以32 位模式运行。 可以仅为针对 .NET Framework 4.5 的项目指定此选项。
- ARM 将程序集编译成可以在具有高级 RISC 计算机 (ARM) 处理器的计算机上运行。
- x64 将程序集编译成可由支持 AMD64 或 EM64T 指令集的计算机上的 64 位 CLR 运行。
- x86 将程序集编译成可由 32 位、x86 可兼容 CLR 运行。
- Itanium 将程序集编译成可由配有 Itanium 处理器的计算机上的 64 位 CLR 运行。

在 64 位 Windows 操作系统上：

- 用 -platform:x86 编译的程序集将在 WOW64 下运行的 32 位 CLR 上执行。
- 用 -platform:anycpu 编译的 DLL 将在加载它的进程所在的同一 CLR 上执行。
- 用 -platform:anycpu 编译的可执行文件将在 64 位 CLR 上执行。
- 用 -platform:anycpu32bitpreferred 编译的可执行文件将在 32 位 CLR 上执行。

anycpu32bitpreferred 设置只对可执行 (.exe) 文件有效，并且需要 .NET Framework 4.5。

有关开发 Windows 64 位操作系统上运行的应用程序的详细信息，请参阅 [64 位应用程序](https://docs.microsoft.com/zh-cn/dotnet/framework/64-bit-apps)。

##### 在 Visual Studio 开发环境中设置此编译器选项

1. 打开项目的“属性” 页。
2. 单击“生成”属性页。
3. 修改“目标平台”属性，对于针对 .NET Framework 4.5 的项目，选择或清除“首选 32 位”复选框。

请注意，-platform 在 Visual C# Express 的开发环境中不可用。

有关如何以编程方式设置此编译器选项的信息，请参阅 [PlatformTarget](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj80.csharpprojectconfigurationproperties3.platformtarget)。

#### 示例

下面的示例演示如何使用 -platform 选项来指定只有 64 位 Windows 操作系统上的 64 位 CLR 才能运行应用程序。

```console
csc -platform:anycpu filename.cs  
```

### [-preferreduilang](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/preferreduilang-compiler-option)

通过使用 `-preferreduilang` 编译器选项，可指定 C# 编译器显示输出的语言，如错误消息。

#### 语法

```console
-preferreduilang: language  
```

#### 自变量

`language`
用于编译器输出的语言的[语言名称](https://docs.microsoft.com/zh-cn/windows/desktop/Intl/language-names)。

#### 备注

可以使用 `-preferreduilang` 编译器选项指定 C# 编译器用于错误消息和其他命令行输出的语言。 如果未安装针对该语言的语言包，将改用操作系统的语言设置，而不会报告错误。

```csharp
csc.exe -preferreduilang:ja-JP  
```

### [-publicsign](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/publicsign-compiler-option)

此选项会导致编译器应用公钥，但不会实际对程序集签名。 -publicsign 选项还会在程序集中设置位，以告知运行时该文件实际已签名。

#### 语法

```console
-publicsign
```

#### 自变量

无。

#### 备注

-publicsign 选项需要使用 [-keyfile](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/keyfile-compiler-option) 或 [-keycontainer](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/keycontainer-compiler-option)。 keyfile 或 keycontainer 选项指定公钥。

-publicsign 和 -delaysign 选项互斥。

公共签名有时称为“假签名”或“OSS 签名”，它包括输出程序集中的公钥并设置“已签名”标记，但实际上并未使用私钥对程序集进行签名。 这对开放源代码项目非常有用，人们希望生成与已发布的“完全签名”程序集兼容的程序集，但无权访问用于对程序集进行签名的私钥。 由于几乎没有使用者实际需要检查程序集是否完全签名，因此这些公开生成的程序集几乎适用于每个使用完全签名程序集的方案。

##### 在 Visual Studio 开发环境中设置此编译器选项

1. 打开项目的“属性” 页。
2. 修改“仅延迟签名”属性。

### [-recurse](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/recurse-compiler-option)

通过 -recurse 选项，可在指定目录 (dir) 的所有子目录中，或项目目录的所有子目录中编译源代码文件。

#### 语法

```console
-recurse:[dir\]file  
```

#### 自变量

`dir` （可选）
希望从中开始搜索的目录。 如未指定目录，搜索将从项目目录开始。

`file`
要搜索的文件。 允许通配符。

#### 备注

通过 -recurse 选项，可在指定目录 (`dir`) 的所有子目录中，或项目目录的所有子目录中编译源代码文件。

可在文件名中使用通配符，对项目目录中的所有匹配文件进行编译，而无需使用 -recurse。

此编译器选项在 Visual Studio 中不可用，并且无法以编程方式更改。

#### 示例

在当前目录中编译所有 C# 文件：

```console
csc *.cs  
```

编译 dir1\dir2 目录及其下的任何目录中的所有 C# 文件，并生成 dir2.dll：

```console
csc -target:library -out:dir2.dll -recurse:dir1\dir2\*.cs  
```

### [-reference](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/reference-compiler-option)

-reference 选项使编译器将指定文件中的[公共](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/public)类型信息导入当前项目，从而使你可从指定的程序集文件中引用元数据。

#### 语法

```console
-reference:[alias=]filename  
-reference:filename  
```

#### 自变量

`filename`
包含程序集清单的文件的名称。 若要导入多个文件，请为每个文件包括一个单独的 -reference 选项。

`alias`
一个有效的 C# 标识符，表示将包含程序集中所有命名空间的根命名空间。

#### 备注

若要从多个文件导入，请为每个文件包括一个 -reference 选项。

导入的文件必须包含一个清单；输出文件必须已使用[-target:module](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-module-compiler-option) 以外的一个 [-target](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-compiler-option) 选项进行了编译。

-r 是 -reference 的缩写形式。

使用 [-addmodule](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/addmodule-compiler-option) 从不包含程序集清单的输出文件中导入元数据。

如果引用的程序集（程序集 A）引用了另一个程序集（程序集 B），那么在下列情况下需要引用程序集 B：

- 使用程序集 A 中的类型，该类型继承自程序集 B 中的类型或实现程序集 B 中的接口。
- 调用具有程序集 B 中的返回类型或参数类型的字段、属性、事件或方法。

使用 [-lib](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/lib-compiler-option) 指定一个或多个程序集引用所在的目录。 -Lib 主题还讨论了编译器在哪些目录中搜索程序集。

为使编译器可以识别程序集（而不是模块）中的某个类型，需要强制解析此类型，这可以通过定义此类型的实例来完成。 还可通过其他方法为编译器解析程序集中的类型名称：例如，如果从程序集中继承类型，编译器就能识别类型名称。

有时，需要在一个程序集内引用同一组件的两个不同版本。 为此，请在每个文件的 -reference 开关上使用别名子选项，以区分两个文件。 此别名将用作组件名的限定符，并解析为其中一个文件中的组件。

默认情况下使用 csc 响应 (.rsp) 文件，该文件引用常用的 .NET Framework 程序集。 如果希望编译器不要使用 csc.rsp，请使用 [-noconfig](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/noconfig-compiler-option)。

> 在 Visual Studio 中，请使用“添加引用”对话框。 有关详细信息，请参阅[如何：使用引用管理器添加或删除引用](https://docs.microsoft.com/zh-cn/visualstudio/ide/how-to-add-or-remove-references-by-using-the-reference-manager)。 若要确保通过使用 `-reference` 添加引用与通过使用“添加引用”对话框添加引用之间的行为等效，请将要添加的程序集的“嵌入互操作类型”属性设置为“False”。 “True”是该属性的默认值。

#### 示例

本示例演示如何使用[外部别名](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/extern-alias)功能。

编译源文件，并从先前已编译的 `grid.dll` 和 `grid20.dll` 中导入元数据。 这两个 DLL 包含同一组件的不同版本，将使用两个带有别名选项的 -reference 编译源文件。 这两个选项如下所示：

```console
-reference:GridV1=grid.dll -reference:GridV2=grid20.dll  
```

这将设置外部别名 `GridV1` 和 `GridV2`，将通过 `extern` 语句在程序中使用它们：

```csharp
extern alias GridV1;  
extern alias GridV2;  
// Using statements go here.  
```

完成此操作后，可以通过在控件名称前添加 `GridV1` 前缀来引用 `grid.dll` 中的网格控件，如下所示：

```csharp
GridV1::Grid  
```

此外，可以通过在控件名称前添加 `GridV2` 前缀来引用 `grid20.dll` 中的网格控件，如下所示：

```csharp
GridV2::Grid   
```

### [-refout](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/refout-compiler-option)

-refout 选项指定应输出引用程序集的文件路径。 这在 Emit API 中转换为 `metadataPeStream`。

#### 语法

```console
-refout:filepath
```

#### 自变量

`filepath` - 引用程序集的文件路径。 通常情况下，应与主程序集的路径匹配。 推荐约定（MSBuild 采用）是，将引用程序集放入与主程序集相关的“ref/”子文件夹中。

#### 备注

仅包含元数据的程序集会将方法主体替换为一个 `throw null` 主体，但包括除匿名类型以外的所有成员。 使用 `throw null` 主体（而非不使用主体）的原因在于，这样做可以运行和传递 PEVerify（从而验证元数据的完整性）。

引用程序集包括程序集级 `ReferenceAssembly` 属性。 可以在源中指定此属性（之后编译器就不需要进行合成）。由于有此属性，运行时会拒绝加载用于执行的引用程序集（但仍可在仅限反射的模式下加载）。 在程序集上反射的工具需要确保仅将引用程序集加载为反射模式，否则将生成运行时 typeload 错误。

引用程序集进一步从仅包含元数据的程序集中删除元数据（私有成员）：

- 引用程序集只包含在 API 外围应用中所需的引用。 实际程序集可能包含与特定实现相关的其他引用。 例如，`class C { private void M() { dynamic d = 1; ... } }` 的引用程序集不引用 `dynamic` 所需的任何类型。
- 删除私有函数成员（方法、属性和事件），前提是这不会对编译造成显著影响。 如果没有 `InternalsVisibleTo` 属性，也请删除内部函数成员。
- 但保留引用程序集中的所有类型（包括私有或嵌套类型）。 保留所有属性（甚至是内部属性）。
- 保留所有虚拟方法。 保留显式接口实现。 保留显式实现的属性和事件，因为它们的访问器是虚拟的（因此予以保留）。
- 保留结构的所有字段。 （这是 post-C#-7.1 优化候选项）

`-refout` 和 [`-refonly`](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/refonly-compiler-option) 选项互斥。

### [-refonly](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/refonly-compiler-option)

-refonly 选项表示应输出引用程序集（而不是实现程序集）作为主输出。 `-refonly` 参数以无提示方式禁用输出 PDB，因为无法执行引用程序集。

#### 语法

```console
-refonly
```

#### 备注

仅包含元数据的程序集会将方法主体替换为一个 `throw null` 主体，但包括除匿名类型以外的所有成员。 使用 `throw null` 主体（而非不使用主体）的原因在于，这样做可以运行和传递 PEVerify（从而验证元数据的完整性）。

引用程序集包括程序集级 `ReferenceAssembly` 属性。 可以在源中指定此属性（之后编译器就不需要进行合成）。由于有此属性，运行时会拒绝加载用于执行的引用程序集（但仍可在仅限反射的模式下加载）。 在程序集上反射的工具需要确保仅将引用程序集加载为反射模式，否则将生成运行时 typeload 错误。

引用程序集进一步从仅包含元数据的程序集中删除元数据（私有成员）：

- 引用程序集只包含在 API 外围应用中所需的引用。 实际程序集可能包含与特定实现相关的其他引用。 例如，`class C { private void M() { dynamic d = 1; ... } }` 的引用程序集不引用 `dynamic` 所需的任何类型。
- 删除私有函数成员（方法、属性和事件），前提是这不会对编译造成显著影响。 如果没有 `InternalsVisibleTo` 属性，也请删除内部函数成员。
- 但保留引用程序集中的所有类型（包括私有或嵌套类型）。 保留所有属性（甚至是内部属性）。
- 保留所有虚拟方法。 保留显式接口实现。 保留显式实现的属性和事件，因为它们的访问器是虚拟的（因此予以保留）。
- 保留结构的所有字段。 （这是 post-C#-7.1 优化候选项）

`-refonly` 和 [`-refout`](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/refout-compiler-option) 选项互斥。

### [-resource](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/resource-compiler-option)

将指定资源嵌入输出文件。

#### 语法

```console
-resource:filename[,identifier[,accessibility-modifier]]  
```

#### 自变量

`filename`
要嵌入到输出文件的 .NET Framework 资源文件。

`identifier` （可选）
资源的逻辑名称；用于加载资源的名称。 默认值是文件名的名称。

`accessibility-modifier` （可选）
资源的可访问性：public 或 private。 默认值为 public。

#### 备注

使用 [linkresource](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/linkresource-compiler-option) 将资源链接至程序集，不向输出文件添加资源文件。

默认情况下，如果使用 C# 编译器创建资源，则这些资源在程序集中是公有的。 若要使资源变为私有，请将 `private` 指定为可访问性修饰符。 不允许使用 `public` 或 `private` 以外的任何其他可访问性。

例如，如果 `filename` 是由 [Resgen.exe](https://docs.microsoft.com/zh-cn/dotnet/framework/tools/resgen-exe-resource-file-generator) 创建的或在开发环境中创建的 .NET Framework 资源文件，则可使用 [System.Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.resources) 命名空间中的成员来访问它。 有关更多信息，请参见[System.Resources.ResourceManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.resources.resourcemanager)。对于所有其他资源，请使用 [Assembly](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.assembly) 类中的 `GetManifestResource` 方法在运行时访问资源。

/res 是 /resource 的缩写形式。

输出文件中资源的顺序由命令行所指定的顺序决定。

##### 在 Visual Studio 开发环境中设置此编译器选项

1. 向项目添加资源文件。
2. 选择要嵌入解决方案资源管理器的文件。
3. 在“属性”窗口中为文件选择“生成操作”。
4. 将“生成操作”设置为“嵌入的资源”。

有关如何以编程方式设置此编译器选项的信息，请参阅 [BuildAction](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj80.fileproperties2.buildaction)。

#### 示例

编译 `in.cs` 并附加资源文件 `rf.resource`：

```console
csc -resource:rf.resource in.cs  
```

### [-subsystemversion](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/subsystemversion-compiler-option)

指定可以运行生成的可执行文件的子系统的最低版本，以此确定可以运行该可执行文件的 Windows 版本。 大多数情况下，此选项确保该可执行文件可以利用早期 Windows 版本中未提供的特定安全功能。

> 若要指定子系统本身，请使用 [-target](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-compiler-option) 编译器选项。

#### 语法

```console
-subsystemversion:major.minor  
```

##### 参数

`major.minor`
所需的子系统最低版本，以主版本和次要版本之间使用点标记的方式表示。 例如，如果将此选项的值设置为 6.01，则可以指定应用程序不能在低于 Windows 7 的操作系统上运行（如本主题后面的表中所述）。 必须将 `major` 和 `minor` 的值指定为整数。

`minor` 版本中的前导零不会更改版本，但尾随零会。 例如，6.1 和 6.01 表示相同的版本，但 6.10 表示另一个版本。 建议次要版本用两位数表示，以免混淆。

#### 备注

下表列出了常见的 Windows 子系统版本。

| Windows 版本        | 子系统版本 |
| ------------------- | ---------- |
| Windows 2000        | 5.00       |
| Windows XP          | 5.01       |
| Windows Server 2003 | 5.02       |
| Windows Vista       | 6.00       |
| Windows 7           | 6.01       |
| Windows Server 2008 | 6.01       |
| Windows 8           | 6.02       |

#### 默认值

-subsystemversion 编译器选项的默认值取决于以下列表中的条件：

- 只要设置了以下列表中的任意编译器选项，则默认值为 6.02：
  - [/target:appcontainerexe](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-appcontainerexe-compiler-option)
  - [/target:winmdobj](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-winmdobj-compiler-option)
  - [-platform:arm](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/platform-compiler-option)
- 如果使用 MSBuild，面向 .NET Framework 4.5，并且未设置先前在此列表中指定的任何编译器选项，则默认值为 6.00。
- 如果前面的条件均不符合，则默认值为 4.00。

#### 设置此选项

若要在 Visual Studio 中设置 -subsystemversion 编译器选项，必须打开 .csproj 文件，并在 MSBuild XML 中为 `SubsystemVersion` 属性指定一个值。 不能在 Visual Studio IDE 中设置此选项。 有关详细信息，请参阅本主题前面的“默认值”或[常用的 MSBuild 项目属性](https://docs.microsoft.com/zh-cn/visualstudio/msbuild/common-msbuild-project-properties)。

### [-target](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/target-compiler-option)

-target 编译器选项可指定为以下四种形式之一：

[/target:appcontainerexe](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-appcontainerexe-compiler-option)
创建 Windows 8.x 应用商店应用的 .exe 文件。

[/target:exe](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-exe-compiler-option)
创建 .exe 文件。

[/target:library](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-library-compiler-option)
创建代码库。

[/target:module](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-module-compiler-option)
创建模块。

[/target:winexe](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-winexe-compiler-option)
创建 Windows 程序。

[/target:winmdobj](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-winmdobj-compiler-option)
创建一个 .winmdobj 中间文件。

如果不指定 -target:module，-target 会将 .NET Framework 程序集清单放入输出文件中。 有关详细信息，请参阅[公共语言运行时中的程序集](https://docs.microsoft.com/zh-cn/dotnet/framework/app-domains/assemblies-in-the-common-language-runtime)和[公共特性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/attributes/common-attributes)。

程序集清单放置在编译中的第一个 .exe 输出文件中，如果没有 .exe 输出文件，会放置在第一个 DLL 中。 例如，在以下的命令行中，清单将放置在 `1.exe` 中：

```console
csc -out:1.exe t1.cs -out:2.netmodule t2.cs  
```

编译器每次编译只创建一个程序集清单。 关于编译中所有文件的信息都放在程序集清单中。 除用 -target:module 创建的文件之外，所有输出文件都可包含程序集清单。 在命令行生成多个输出文件时，只能创建一个程序集清单，且该清单必须放置在命令行上指定的第一个输出文件中。 无论第一个输出文件是什么（-target:exe、-target:winexe、-target:library 或 -target:module），在同一编译中生成的任何其他输出文件都必须是模块 (-target:module)。

如果创建了一个程序集，则可以用 [CLSCompliantAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.clscompliantattribute) 属性指示全部或部分代码是符合 CLS 的。

```csharp
// target_clscompliant.cs  
[assembly:System.CLSCompliant(true)]   // specify assembly compliance  
  
[System.CLSCompliant(false)]   // specify compliance for an element  
public class TestClass  
{  
    public static void Main() {}  
}  
```

有关如何以编程方式设置此编译器选项的详细信息，请参阅 [OutputType](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj80.projectproperties3.outputtype)。

#### [-target:appcontainerexe](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/target-appcontainerexe-compiler-option)

如果使用 -target:appcontainerexe 编译器选项，则编译器会创建一个 Windows 可执行 (.exe) 文件，该文件必须在应用容器中运行。 此选项与 [-target:winexe](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-winexe-compiler-option) 等效，但专门用于 Windows 8.x 应用商店 应用。

#### 语法

```console
-target:appcontainerexe  
```

#### 备注

为了要求应用在应用容器中运行，此选项在[可移植可执行](https://docs.microsoft.com/zh-cn/windows/desktop/Debug/pe-format) (PE) 文件中设置了一个位。 设置该位时，如果 CreateProcess 方法尝试在应用容器外启动该可执行文件，就会发生错误。

除非使用 [-out](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/out-compiler-option) 选项，否则输出文件名采用包含 [Main](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/main-and-command-args/index) 方法的输入文件的名称。

如果在命令提示符处指定此选项，则在下一个 -out 或 -target 选项之前，会使用所有文件来创建可执行文件。

##### 在 IDE 中设置此编译器选项

1. 在“解决方案资源管理器”中，打开项目的快捷菜单，然后选择“属性”。

2. 在“应用程序”选项卡上，在“输出类型”列表中选择“Windows 应用商店应用”。

   此选项仅可用于 Windows 8.x 应用商店 应用模板。

有关如何以编程方式设置此编译器选项的信息，请参阅 [OutputType](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj80.projectproperties3.outputtype)。

#### 示例

以下命令将 `filename.cs` 编译为一个只能在应用容器中运行的 Windows 可执行文件。

```console
csc -target:appcontainerexe filename.cs  
```

#### [-target:exe](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/target-exe-compiler-option)

-target:exe 选项将使编译器创建可执行文件 (EXE) 和控制台应用程序。

#### 语法

```console
-target:exe  
```

#### 备注

默认情况下，-target:exe 选项有效。 将创建扩展名为 .exe 的可执行文件。

使用 [-target:winexe](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-winexe-compiler-option) 创建 Windows 程序可执行文件。

除非使用 [-out](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/out-compiler-option) 选项进行指定，否则输出文件名采用包含 [Main](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/main-and-command-args/index) 方法的输入文件的名称。

在命令行中进行指定时，-out 或 -target:module 选项上所有文件都用于创建 .exe 文件

编译为 .exe 文件的源代码文件中只需要一个 **Main** 方法。 如果代码具有多个附带 Main 方法的类，则可使用 [-main](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/main-compiler-option) 编译器选项指定包含 Main 方法的类。

##### 在 Visual Studio 开发环境中设置此编译器选项

1. 打开项目的“属性”页。
2. 单击“应用程序”属性页。
3. 修改“输出类型”属性。

有关如何以编程方式设置此编译器选项的信息，请参阅 [OutputType](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj80.projectproperties3.outputtype)。

#### 示例

以下每个命令行都将编译 `in.cs` 并创建 `in.exe`：

```console
csc -target:exe in.cs  
csc in.cs  
```

#### [-target:library](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/target-library-compiler-option)

-target:library 选项导致编译器创建动态链接库 (DLL) 而不是可执行文件 (EXE)。

#### 语法

```console
-target:library  
```

#### 备注

将创建具有 .dll 扩展名的 DLL。

除非使用 [-out](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/out-compiler-option) 选项指定，否则输出文件的名称采用第一个输入文件的名称。

在命令行中进行指定时，-out 或 -target:module 选项上所有文件都用于创建 .dll 文件。

生成 .dll 文件时，不需要 [Main ](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/main-and-command-args/index)方法。

##### 在 Visual Studio 开发环境中设置此编译器选项

1. 打开项目的“属性”页。
2. 单击“应用程序”属性页。
3. 修改“输出类型”属性。

有关如何以编程方式设置此编译器选项的信息，请参阅 [OutputType](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj80.projectproperties3.outputtype)。

#### 示例

通过创建 `in.dll` 编译 `in.cs`：

```console
csc -target:library in.cs  
```

#### [-target:module](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/target-module-compiler-option)

此选项会导致编译器不生成程序集清单。

#### 语法

```console
-target:module  
```

#### 备注

默认情况下，使用此选项编译时所创建的输出文件具有扩展名 .netmodule。

.NET Framework 公共语言运行时无法加载不含程序集清单的文件。 但是，此类文件可以通过 [-addmodule](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/addmodule-compiler-option) 合并到程序集的程序集清单中。

如果在一次编译中创建了多个模块，某个模块中的[内部](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/internal)类型将适用于编译中的其他模块。 如果一个模块中的代码引用另一模块中的 `internal` 类型，则两个模块必须通过 -addmodule 合并到一个程序集清单中。

Visual Studio 开发环境中不支持创建模块。

有关如何以编程方式设置此编译器选项的信息，请参阅 [OutputType](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj80.projectproperties3.outputtype)。

#### 示例

通过创建 `in.netmodule` 编译 `in.cs`：

```console
csc -target:module in.cs  
```

#### [-target:winexe](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/target-winexe-compiler-option)

-target:winexe 选项使编译器创建可执行文件 (EXE) 和 Windows 程序。

#### 语法

```console
-target:winexe  
```

#### 备注

将创建扩展名为 .exe 的可执行文件。 Windows 程序从 .NET Framework 库或使用 Win32 API 提供用户界面。

使用 [-target:exe](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-exe-compiler-option) 创建控制台应用程序。

除非使用 [-out](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/out-compiler-option) 选项进行指定，否则输出文件名采用包含 [Main](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/main-and-command-args/index) 方法的输入文件的名称。

在命令行中进行指定时，直到下一个 -out 或 [-target](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-compiler-option) 选项为止的所有文件均用于创建 Windows 程序。

编译为 .exe 文件的源代码文件中只需要一个 **Main** 方法。 如果代码具有多个附带 Main 方法的类，则可使用 [-main](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/main-compiler-option) 选项指定包含 Main 方法的类。

##### 在 Visual Studio 开发环境中设置此编译器选项

1. 打开项目的“属性”页。
2. 单击“应用程序”属性页。
3. 修改“输出类型”属性。

有关如何以编程方式设置此编译器选项的信息，请参阅 [OutputType](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj80.projectproperties3.outputtype)。

#### 示例

将 `in.cs` 编译为 Windows 程序：

```console
csc -target:winexe in.cs  
```

#### [-target:winmdobj](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/target-winmdobj-compiler-option)

如果使用 -target:winmdobj 编译器选项，则编译器会创建一个中间 .winmdobj 文件，你可以将这个文件转换为 Windows 运行时二进制 (.winmd) 文件。 之后，除了托管语言程序外，JavaScript 和 C++ 程序也可以使用该 .winmd 文件。

#### 语法

```console
-target:winmdobj  
```

#### 备注

**winmdobj** 设置会向编译器发出信号，表示需要中间模块。 作为响应，Visual Studio 会将 C# 类库编译为 .winmdobj 文件。 随后，.winmdobj 文件可作为可作为 [WinMDExp](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.build.tasks.winmdexp) 导出工具的输入，生成 Windows 元数据 (.winmd) 文件。 .winmd 文件既包含原始库的代码，也包括 JavaScript（或 C++）以及 Windows 运行时使用的 WinMD 元数据的代码。

使用 -target:winmdobj 编译器选项所编译的文件，只能用作 WimMDExp 导出工具的输入；不能直接引用 .winmdobj 文件自身。

除非使用 [-out](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/out-compiler-option) 选项，否则输出文件的名称采用第一个输入文件的名称。 不需要使用 [Main](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/main-and-command-args/index) 方法。

如果在命令提示符处指定 -target:winmdobj 选项，则在指定下一个 -out 或 [-target:module](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-module-compiler-option) 选项之前，会使用所有文件来创建 Windows 程序。

##### 在 Visual Studio IDE 中为 Windows 应用商店应用程序设置此编译器选项

1. 在“解决方案资源管理器”中，打开项目的快捷菜单，然后选择“属性”。

2. 选择“应用程序”选项卡。

3. 在“输出类型”列表中，选择“WinMD 文件”。

   “WinMD 文件”选项只能用于 Windows 8.x 应用商店 应用模板。

有关如何以编程方式设置此编译器选项的信息，请参阅 [OutputType](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj80.projectproperties3.outputtype)。

#### 示例

以下命令将 `filename.cs` 编译为一个中间 .winmdobj 文件。

```console
csc -target:winmdobj filename.cs  
```

### [-unsafe](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/unsafe-compiler-option)

-unsafe 编译器选项允许使用[不安全](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/unsafe)关键字进行编译的代码。

#### 语法

```console
-unsafe  
```

#### 备注

有关不安全代码的详细信息，请参阅[不安全代码和指针](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/unsafe-code-pointers/index)。

##### 在 Visual Studio 开发环境中设置此编译器选项

1. 打开项目的“属性”页。
2. 单击“生成”属性页。
3. 选中“允许不安全代码”复选框。

##### 向 csproj 文件添加此选项

打开项目的 csproj 文件，并添加以下元素：

```xml
  <PropertyGroup>
    <AllowUnsafeBlocks>true</AllowUnsafeBlocks>
  </PropertyGroup>
```

有关如何以编程方式设置此编译器选项的信息，请参阅 [AllowUnsafeBlocks](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj80.csharpprojectconfigurationproperties3.allowunsafeblocks)。

#### 示例

针对不安全模式编译 `in.cs`：

```console
csc -unsafe in.cs  
```

### [-utf8output](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/utf8output-compiler-option)

-utf8output 选项使用 UTF-8 编码来显示编译器输出。

#### 语法

```console
-utf8output  
```

#### 备注

在某些国际配置中，编译器输出无法在控制台上正确显示。 在这些配置中，请使用 -utf8output 并将编译器输出重定向到文件。

此编译器选项在 Visual Studio 中不可用，并且无法以编程方式更改。

### [-warn](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/warn-compiler-option)

-warn 选项指定编译器显示的警告等级。

#### 语法

```console
-warn:option  
```

#### 自变量

`option`
要为编译显示的警告等级：较低的数字仅显示高严重性警告；较高的数字显示更多警告。 有效值为 0-4：

| 警告级别    | 含义                                                         |
| ----------- | ------------------------------------------------------------ |
| 0           | 关闭发出所有警告消息。                                       |
| 1           | 显示严重警告消息。                                           |
| 2           | 显示等级 1 警告以及某些不太严重的警告，如有关隐藏类成员的警告。 |
| 3           | 显示等级 2 警告以及某些不太严重的警告，如有关经常计算为 `true` 或 `false` 的表达式的警告。 |
| 4（默认值） | 显示所有等级 3 警告以及信息性警告。                          |

#### 备注

若要获取有关错误或警告的信息，可以在帮助索引中查找错误代码。 有关获取错误或警告信息的其他方法，请参阅 [C# 编译器错误](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-messages/index)。

使用 [-warnaserror](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/warnaserror-compiler-option) 将所有警告视为错误。 使用 [-nowarn](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/nowarn-compiler-option) 禁用某些警告。

-w 是 -warn 的缩写形式。

#### 在 Visual Studio 开发环境中设置此编译器选项

1. 打开项目的“属性”页。
2. 单击“生成”属性页。
3. 修改警告等级属性。

有关如何以编程方式设置此编译器选项的信息，请参阅 [WarningLevel](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj80.csharpprojectconfigurationproperties3.warninglevel)。

#### 示例

编译 `in.cs` 并使编译器仅显示等级 1 警告：

```console
csc -warn:1 in.cs  
```

### [-warnaserror](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/warnaserror-compiler-option)

-warnaserror+ 选项将所有警告视为错误

#### 语法

```console
-warnaserror[+ | -][:warning-list]  
```

#### 备注

通常报告为警告的消息被报告为错误，生成过程暂停（不生成任何输出文件）。

默认情况下，-warnaserror- 将生效，导致警告不会阻止生成输出文件。 -warnaserror 与 -warnaserror+ 相同，会导致将警告视为错误。

（可选）如果希望仅将一些特定警告视为错误，则可以指定视为错误的警告编号的逗号分隔列表。

使用 [-warn](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/warn-compiler-option) 指定想要编译器显示的警告等级。 使用 [-nowarn](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/nowarn-compiler-option) 禁用某些警告。

#### 在 Visual Studio 开发环境中设置此编译器选项

1. 打开项目的“属性”页。
2. 单击“生成”属性页。
3. 修改“将警告视为错误”属性。

若要以编程方式设置此编译器选项，请参阅 [TreatWarningsAsErrors](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj80.csharpprojectconfigurationproperties3.treatwarningsaserrors#VSLangProj80_CSharpProjectConfigurationProperties3_TreatWarningsAsErrors)。

#### 示例

编译 `in.cs` 并使编译器不显示警告：

```console
csc -warnaserror in.cs  
csc -warnaserror:642,649,652 in.cs  
```

### [-win32icon](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/win32icon-compiler-option)

-win32icon 选项在输出文件中插入 .ico 文件，为输出文件赋予其在文件资源管理器中所需的外观。

#### 语法

```console
-win32icon:filename  
```

#### 自变量

`filename`
想向输出文件添加的 .ico 文件。

#### 备注

可以使用[资源编译器](https://docs.microsoft.com/zh-cn/windows/desktop/menurc/resource-compiler)创建的 .ico 文件。 在编译 Visual C++ 程序时会调用资源编译器；.ico 文件是从 .rc 文件创建的。

请参阅 [-linkresource](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/linkresource-compiler-option)（引用）或 [-resource](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/resource-compiler-option)（附加）.NET Framework 资源文件。 请参阅 [-win32res](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/win32res-compiler-option) 导入 .res 文件。

#### 在 Visual Studio 开发环境中设置此编译器选项

1. 打开项目的“属性”页。
2. 单击“应用程序”属性页。
3. 修改“应用程序图标”属性。

有关如何以编程方式设置此编译器选项的信息，请参阅 [ApplicationIcon](https://docs.microsoft.com/zh-cn/dotnet/api/vslangproj80.projectproperties3.applicationicon)。

#### 示例

编译 `in.cs` 并附加 .ico 文件 `rf.ico` 以生成 `in.exe`：

```console
csc -win32icon:rf.ico in.cs  
```

### [-win32manifest](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/win32manifest-compiler-option)

使用 -win32manifest 选项可以指定要嵌入到项目的可迁移可执行 (PE) 文件中的用户定义的 Win32 应用程序清单文件。

#### 语法

```console
-win32manifest: filename  
```

#### 自变量

`filename`
自定义清单文件的名称和位置。

#### 备注

默认情况下，Visual C# 编译器嵌入指定“asInvoker”的请求执行级别的应用程序清单。 它在生成该可执行文件的同一文件夹中创建清单，如果使用 Visual Studio，该文件夹通常为 bin\Debug 或 bin\Release。 如果要提供自定义清单（例如，指定“highestAvailable”或“requireAdministrator”的请求执行级别的清单），请使用此选项指定文件名。

> 此选项和 [-win32res（C# 编译器选项）](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/win32res-compiler-option)选项是互斥的。 如果尝试在同一命令行中同时使用这两个选项，将收到一个生成错误。

如果应用程序没有用于指定请求执行级别的应用程序清单，将受到 Windows 用户帐户控制功能下的文件/注册表虚拟化的影响。 有关详细信息，请参阅[用户帐户控制](https://docs.microsoft.com/zh-cn/windows/access-protection/user-account-control/user-account-control-overview)。

如果满足下列任一条件，则应用程序会受到虚拟化的影响：

- 使用 -nowin32manifest 选项，并且在随后的生成步骤中未提供清单，或者没有通过使用 -win32res 选项将其包含在 Windows 资源 (.res) 文件中。
- 提供的自定义清单未指定请求执行级别。

Visual Studio 创建默认 .manifest 文件，并将它与可执行文件一起存储在“调试”和“发布”目录中。 可以用任意文本编辑器创建一个清单，然后将该文件添加到项目中，从而添加自定义清单。 或者，也可以右键单击“解决方案资源管理器”中的“项目”图标，单击“添加新项”，然后单击“应用程序清单文件”。 添加完新的或现有清单文件后，该文件将显示在“清单”下拉列表中。 有关详细信息，请参阅[“项目设计器”->“应用程序”页 (C#)](https://docs.microsoft.com/zh-cn/visualstudio/ide/reference/application-page-project-designer-csharp)。

提供应用程序清单的操作，可以作为自定义后期生成步骤，也可以通过使用 [-nowin32manifest（C# 编译器选项）](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/nowin32manifest-compiler-option)选项作为 Win32 资源文件的组成部分。 如果希望应用程序受到 Windows Vista 的文件或注册表虚拟化的影响，请使用该选项。 这将阻止编译器在可迁移可执行 (PE) 文件中创建和嵌入默认清单。

#### 示例

下例演示了 Visual C# 编译器插入到 PE 中的默认清单。

> 编译器将一个标准应用程序名称“MyApplication.app”插入到 xml 中。 这是一种使应用程序可以在 Windows Server 2003 Service Pack 3 上运行的解决方法。

```xml
<?xml version="1.0" encoding="utf-8" standalone="yes"?>  
<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0">  
  <assemblyIdentity version="1.0.0.0" name="MyApplication.app"/>  
  <trustInfo xmlns="urn:schemas-microsoft-com:asm.v2">  
    <security>  
      <requestedPrivileges xmlns="urn:schemas-microsoft-com:asm.v3">  
        <requestedExecutionLevel level="asInvoker"/>  
      </requestedPrivileges>  
    </security>  
  </trustInfo>  
</assembly>  
```

### [-win32res](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/win32res-compiler-option)

-win32res 选项会在输出文件中插入 Win32 资源。

#### 语法

```console
-win32res:filename  
```

#### 自变量

`filename`
想向输出文件添加的资源文件。

#### 备注

Win32 资源文件可以用[资源编译器](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/resource-compiler-option)创建。 在编译 Visual C++ 程序时会调用资源编译器；.res 文件是从 .rc 文件创建的。

Win32 资源可以包含版本或位图（图标）信息，这些信息有助于在文件资源管理器中标识您的应用程序。 如果不指定 -win32res，编译器将根据程序集版本生成版本信息。

请参阅 [-linkresource](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/linkresource-compiler-option)（引用）或 [-resource](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/resource-compiler-option)（附加）.NET Framework 资源文件。

#### 在 Visual Studio 开发环境中设置此编译器选项

1. 打开项目的“属性”页。
2. 单击“应用程序”属性页。
3. 单击“资源文件”按钮，然后使用组合框选择一个文件。

#### 示例

编译 `in.cs` 并附加 Win32 资源文件 `rf.res` 以生成 `in.exe`：

```console
csc -win32res:rf.res in.cs  
```