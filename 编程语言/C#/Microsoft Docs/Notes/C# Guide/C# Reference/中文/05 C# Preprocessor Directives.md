# [C# Preprocessor Directives](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/preprocessor-directives/)

本节介绍了以下 C# 预处理器指令：

- [#if](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-if)
- [#else](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-else)
- [#elif](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-elif)
- [#endif](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-endif)
- [#define](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-define)
- [#undef](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-undef)
- [#warning](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-warning)
- [#error](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-error)
- [#line](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-line)
- [#region](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-region)
- [#endregion](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-endregion)
- [#pragma](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-pragma)
- [#pragma warning](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-pragma-warning)
- [#pragma checksum](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-pragma-checksum)

## [#if](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-if)

如果 C# 编译器遇到 `#if` 指令，最终是 [#endif](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-endif) 指令，则仅当定义指定的符号时，它才编译这些指令之间的代码。 与 C 和 C++ 不同，你不能为符号分配数字值。 C# 中的 #if 语句是布尔值，且仅测试是否已定义该符号。例如:

```csharp
#if DEBUG
    Console.WriteLine("Debug version");
#endif
```

仅可以使用运算符 [==](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/equality-comparison-operator)（相等）和 [!=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/not-equal-operator)（不相等）测试 [true](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/true) 或 [false](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/false)。 True 表示定义该符号。 语句 `#if DEBUG` 具有与 `#if (DEBUG == true)` 相同的含义。 可以使用运算符 [&&](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/conditional-and-operator) (and)、[||](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/conditional-or-operator) (or) 和 [!](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/logical-negation-operator) (not) 评估是否已经定义了多个符号。 还可以用括号对符号和运算符进行分组。

### 备注

`#if` 以及 [#else](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-else)、[#elif](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-elif)、[#endif](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-endif)、[#define](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-define) 和 [#undef](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-undef) 指令，允许基于是否存在一个或多个符号包括或排除代码。这在编译调试版本的代码或编译特定配置的代码时会很有用。

以 `#if` 指令开头的条件指令必须以 `#endif` 指令显式终止。

`#define` 允许你定义一个符号。 然后通过将该符号用作传递给 `#if` 指令的表达式，该表达式的计算结果为 `true`。

还可以通过 [-define](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/define-compiler-option) 编译器选项来定义符号。 可以通过 [#undef](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-undef) 取消定义符号。

使用 `-define` 或 `#define` 定义的符号与具有相同名称的变量不冲突。 也就是说，变量名称不应传递给预处理器指令，且符号仅能由预处理器指令评估。

使用 `#define` 创建的符号的作用域是在其中定义它的文件。

此外，生成系统还会感知表示不同[目标框架](https://docs.microsoft.com/zh-cn/dotnet/standard/frameworks)的预定义预处理器符号。 在创建可以面向多个.NET 实现或版本的应用程序时，这些符号会很有用。

| 目标框架       | 符号                                                         |
| -------------- | ------------------------------------------------------------ |
| .NET Framework | `NET20`, `NET35`, `NET40`, `NET45`, `NET451`, `NET452`, `NET46`, `NET461`, `NET462`, `NET47`, `NET471`, `NET472` |
| .NET Standard  | `NETSTANDARD1_0`, `NETSTANDARD1_1`, `NETSTANDARD1_2`, `NETSTANDARD1_3`, `NETSTANDARD1_4`, `NETSTANDARD1_5`, `NETSTANDARD1_6`, `NETSTANDARD2_0` |
| .NET Core      | `NETCOREAPP1_0`, `NETCOREAPP1_1`, `NETCOREAPP2_0`, `NETCOREAPP2_1`, `NETCOREAPP2_2` |

其他预定义符号包括 DEBUG 和 TRACE 常量。 你可以使用 `#define` 替代项目的值集。 例如，会根据生成配置属性（“调试”或者“发布”模式）自动设置 DEBUG 符号。

### 示例

下例显示如何在文件上定义 MYTEST 符号，然后测试 MYTEST 和 DEBUG 符号的值。 此示例的输出取决于是在“调试”还是“发布”配置模式下生成项目。

```csharp
#define MYTEST
using System;
public class MyClass
{
    static void Main()
    {
#if (DEBUG && !MYTEST)
        Console.WriteLine("DEBUG is defined");
#elif (!DEBUG && MYTEST)
        Console.WriteLine("MYTEST is defined");
#elif (DEBUG && MYTEST)
        Console.WriteLine("DEBUG and MYTEST are defined");  
#else
        Console.WriteLine("DEBUG and MYTEST are not defined");
#endif
    }
}
```

下例显示如何针对不同的目标框架进行测试，以便在可能时使用较新的 API：

```csharp
public class MyClass
{
    static void Main()
    {
#if NET40
        WebClient _client = new WebClient();
#else
        HttpClient _client = new HttpClient();
#endif
    }
    //...
}
```

## [#else](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-else)

`#else` 允许创建复合条件指令，因此，如果先前 [#if](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-if) 或（可选）[#elif](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-elif) 指令中的任何表达式的计算结果都不是 `true`，则编译器将对介于 `#else` 和后续 `#endif` 之间的所有代码进行求值。

### 备注

[#endif](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-endif) 必须是 `#else` 之后的下一个预处理器指令。 有关如何使用 `#else` 的示例，请参阅 [#if](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-if)。

## [#elif](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-elif)

`#elif` 可以创建复合条件指令。 如果之前的 [#if](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-if) 和任何之前的可选 `#elif` 指令表达式的值为 `true`，则计算 `#elif` 表达式。 如果 `#elif` 表达式计算结果为 `true`，编译器将计算 `#elif` 和下一条件指令间的所有代码。例如:

```csharp
#define VC7  
//...  
#if debug  
    Console.WriteLine("Debug build");  
#elif VC7  
    Console.WriteLine("Visual Studio 7");  
#endif  
```

可以使用运算符 `==`（相等）、`!=`（不相等）、`&&`（和）以及`||`（或）计算多个符号。 还可以用括号对符号和运算符进行分组。

### 备注

`#elif` 等效于使用：

```csharp
#else  
#if  
```

使用 `#elif` 更简单，因为每个 `#if` 均需要 [#endif](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-endif)，但 `#elif` 可在没有匹配的 `#endif` 的情况下使用。

有关如何使用 `#elif` 的示例，请参阅 [#if](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-if)。

## [#endif](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-endif)

`#endif` 指定条件指令的末尾，以 [#if](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-if) 指令开头。 例如，应用于对象的

```csharp
#define DEBUG  
// ...  
#if DEBUG  
    Console.WriteLine("Debug version");  
#endif  
```

### 备注

以 `#if` 指令开头的条件指令必须以 `#endif` 指令显式终止。 有关如何使用 `#endif` 的示例，请参阅 [#if](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-if)。

## [#define](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-define)

使用 `#define` 来定义符号。 将符号用作传递给 [#if](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-if) 指令的表达式时，该表达式的计算结果为 `true`，如以下示例所示：

```csharp
#define DEBUG
```

### 备注

> `#define` 指令不能用于声明常量值，这与 C 和 C++ 中的通常做法一样。 C# 中的常量最好定义为类或结构的静态成员。 如果具有多个此类常量，请考虑创建一个单独的“常量”类来容纳它们。

符号可用于指定编译的条件。 可通过 [#if](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-if) 或 [#elif](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-elif) 测试符号。 还可以使用 [ConditionalAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.diagnostics.conditionalattribute) 来执行条件编译。

可以定义一个符号，但不能向符号分配值。 文件中必须先出现 `#define` 指令，才能使用并非同时也是预处理器指令的任何指示。

还可以通过 [-define](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/define-compiler-option) 编译器选项来定义符号。 可以通过 [#undef](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-undef) 取消定义符号。

使用 `-define` 或 `#define` 定义的符号与具有相同名称的变量不冲突。 也就是说，变量名称不应传递给预处理器指令，且符号仅能由预处理器指令评估。

使用 `#define` 创建的符号的作用域是在其中定义该符号的文件。

如以下示例所示，必须将 `#define` 指令放在文件顶部。

```csharp
#define DEBUG  
//#define TRACE  
#undef TRACE  
  
using System;  
  
public class TestDefine  
{  
    static void Main()  
    {  
#if (DEBUG)  
        Console.WriteLine("Debugging is enabled.");  
#endif  
  
#if (TRACE)  
     Console.WriteLine("Tracing is enabled.");  
#endif  
    }  
}  
// Output:  
// Debugging is enabled.  
```

有关如何取消对符号进行定义的示例，请参阅 [#undef](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-undef)。

## [#undef](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-undef)

`#undef` 允许你定义一个符号，这样一来，通过将该符号用作 [#if](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-if) 指令中的表达式，表达式将计算为 `false`。

可使用 [#define](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-define) 指令或 [-define](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/define-compiler-option) 编译器选项来定义符号。 文件中必须先出现 `#undef` 指令，才能使用任何非指令的语句。

### 示例

```csharp
// preprocessor_undef.cs  
// compile with: /d:DEBUG  
#undef DEBUG  
using System;  
class MyClass
{  
    static void Main()
    {  
#if DEBUG  
        Console.WriteLine("DEBUG is defined");  
#else  
        Console.WriteLine("DEBUG is not defined");  
#endif  
    }  
}  
```

未定义 DEBUG

## [#warning](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-warning)

`#warning` 允许你从代码中的特定位置生成 [CS1030](https://docs.microsoft.com/zh-cn/dotnet/csharp/misc/cs1030) 第一级编译器警告。 例如:

```csharp
#warning Deprecated code in this method.  
```

### 备注

`#warning` 常用于条件指令中。 还可使用 [#error](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-error) 生成用户定义错误。

### 示例

```csharp
// preprocessor_warning.cs  
// CS1030 expected  
#define DEBUG  
class MainClass
{  
    static void Main()
    {  
#if DEBUG  
#warning DEBUG is defined  
#endif  
    }  
}  
```

## [#error](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-error)

`#error` 可从代码中的特定位置生成 [CS1029](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-messages/cs1029) 用户定义的错误。 例如:

```csharp
#error Deprecated code in this method.  
```

### 备注

`#error` 常用于条件指令中。

还可使用 [#warning](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-warning) 生成用户定义警告。

### 示例

```csharp
// preprocessor_error.cs  
// CS1029 expected  
#define DEBUG  
class MainClass   
{  
    static void Main()   
    {  
#if DEBUG  
#error DEBUG is defined  
#endif  
    }  
}  
```

## [#line](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-line)

借助 `#line`，可修改编译器的行号及（可选）用于错误和警告的文件名输出。

以下示例演示如何报告与行号相关联的两个警告。 `#line 200` 指令将下一行号强制设为 200（尽管默认值为 #6），直到下一个 #line 指令前，文件名都将报告为“特殊”。 #line 默认指令将行号返回至其默认行号，默认行号对由上个指令重新编号的行进行计数。

```csharp
class MainClass  
{  
    static void Main()  
    {  
#line 200 "Special"  
        int i;
        int j;
#line default  
        char c;
        float f;
#line hidden // numbering not affected  
        string s;   
        double d;
    }  
}  
```

编译产生以下输出：

```console
Special(200,13): warning CS0168: The variable 'i' is declared but never used
Special(201,13): warning CS0168: The variable 'j' is declared but never used
MainClass.cs(9,14): warning CS0168: The variable 'c' is declared but never used
MainClass.cs(10,15): warning CS0168: The variable 'f' is declared but never used
MainClass.cs(12,16): warning CS0168: The variable 's' is declared but never used
MainClass.cs(13,16): warning CS0168: The variable 'd' is declared but never used
```

### 备注

可在生成过程的自动、中间步骤中使用 `#line` 指令。 例如，如果已从原始源代码文件中删除行，但仍希望编译器基于文件中的原始行号生成输出，可在删除行后，使用 `#line` 来模拟原始行号。

`#line hidden` 指令能对调试程序隐藏连续行，当开发者逐行执行代码时，介于 `#line hidden` 和下一 `#line` 指令（假设它不是其他 `#line hidden` 指令）间的任何行都将被跳过。 还可通过此选项允许 ASP.NET 区分用户定义和计算机生成的代码。 虽然此功能主要用于 ASP.NET，但可能更多的源生成器会利用此功能。

`#line hidden` 指令不影响错误报告中的文件名或行号。 也就是说，如果在隐藏块中遇到错误，编译器将报告错误的当前文件名和行号。

`#line filename` 指令可指定要在编译器输出中显示的文件名。 默认情况下，将使用源代码文件的实际名称。 该文件名必须以双引号 ("") 引起来，且必须位于行号之后。

源代码文件中可包含任意数目的 `#line` 指令。

### 示例

下列示例演示调试程序如何忽略代码中的隐藏行。 运行示例时，它将显示三行文本。 但是，如果按照示例所示设置断点、并按 F10 逐行执行代码，可观察到调试程序忽略隐藏行。 另请注意，即使在隐藏行设置断点，调试程序仍将忽略它。

```csharp
// preprocessor_linehidden.cs  
using System;  
class MainClass   
{  
    static void Main()   
    {  
        Console.WriteLine("Normal line #1."); // Set break point here.  
#line hidden  
        Console.WriteLine("Hidden line.");  
#line default  
        Console.WriteLine("Normal line #2.");  
    }  
}  
```

## [#region](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-region)

利用 `#region`，可以指定在使用 Visual Studio Code 编辑器的[大纲功能](https://docs.microsoft.com/zh-cn/visualstudio/ide/outlining)时可展开或折叠的代码块。 在较长的代码文件中，能够折叠或隐藏一个或多个区域会十分便利，这样，可将精力集中于当前处理的文件部分。 下面的示例演示如何定义区域：

```csharp
#region MyClass definition  
public class MyClass   
{  
    static void Main()   
    {  
    }  
}  
#endregion  
```

### 备注

`#region` 块必须通过 [#endregion](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-endregion) 指令终止。

`#region` 块不能与 [#if](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-if) 块重叠。 但是，可以将 `#region` 块嵌套在 `#if` 块内，或将 `#if` 块嵌套在 `#region` 块内。

## [#endregion](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-endregion)

`#endregion` 标记 [#region](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-region) 块的结尾。 例如:

```csharp
#region MyClass definition  
class MyClass   
{  
    static void Main()   
    {  
    }  
}  
#endregion  
```

## [#pragma](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-pragma)

`#pragma` 为编译器给出特殊指令以编译它所在的文件。 这些指令必须受编译器支持。 即是说，不可使用 `#pragma` 创建自定义处理指令。 Microsoft C# 编译器支持以下两种 `#pragma` 指令：

[#pragma warning](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-pragma-warning)

[#pragma checksum](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-pragma-checksum)

### 语法

```csharp
#pragma pragma-name pragma-arguments  
```

#### 参数

`pragma-name`
已识别杂注的名称。

`pragma-arguments`
特定于杂注的参数。

## [#pragma warning](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-pragma-warning)

`#pragma warning` 可以启用或禁用特定警告。

### 语法

```csharp
#pragma warning disable warning-list  
#pragma warning restore warning-list  
```

#### 参数

`warning-list`
以逗号分隔的警告编号的列表。 “CS”前缀是可选的。

未指定警告编号时，`disable` 会禁用所有警告，`restore` 会启用所有警告。

> 若要在 Visual Studio 中查找警告编号，请生成项目，然后在“输出”窗口中查找警告编号。

### 示例

```csharp
// pragma_warning.cs  
using System;  
  
#pragma warning disable 414, CS3021  
[CLSCompliant(false)]  
public class C  
{  
    int i = 1;  
    static void Main()  
    {  
    }  
}  
#pragma warning restore CS3021  
[CLSCompliant(false)]  // CS3021  
public class D  
{  
    int i = 1;  
    public static void F()  
    {  
    }  
}  
```

## [#pragma checksum](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/preprocessor-directives/preprocessor-pragma-checksum)

为源文件生成校验和，以帮助调试校验 ASP.NET 页。

### 语法

```csharp
#pragma checksum "filename" "{guid}" "checksum bytes"  
```

#### 参数

`"filename"`
需要监视更改或更新的文件的名称。

`"{guid}"`
哈希算法的全局唯一标识符 (GUID)。  

`"checksum_bytes"`
表示校验和字节的十六进制数字的字符串。 必须是偶数个十六进制数字。 奇数个十六进制数字会导致编译时警告出现，且指令遭忽略。

### 备注

Visual Studio 调试器使用校验和确保它可始终找到正确的源。 编译器为源文件计算校验和，然后将输出发出到程序数据库 (PDB) 文件。 调试器随后使用 PDB 针对它为源文件计算的校验和进行比较。

此解决方案不适合 ASP.NET 项目，因为计算的校验和用于生成的源文件，而不是 .aspx 文件。 为了解决此问题，`#pragma checksum` 为 ASP.NET 页提供了校验和支持。

在 Visual C# 中创建 ASP.NET 项目时，生成的源文件包含从其生成源的 .aspx 文件的校验和。 编译器随后将此信息写入 PDB 文件中。

如果编译器在文件中未遇到 `#pragma checksum` 指令，则它会计算校验和并将值写入 PDB 文件中。

### 示例

```csharp
class TestClass  
{  
    static int Main()  
    {  
        #pragma checksum "file.cs" "{406EA660-64CF-4C82-B6F0-42D48172A799}" "ab007f1d23d9" // New checksum  
    }  
}
```