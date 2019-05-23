[C# programming guide](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/index)

# Language Sections

## [Strings](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/strings/index)

字符串是值为文本的 [String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string) 类型对象。 文本在内部存储为 [Char](https://docs.microsoft.com/zh-cn/dotnet/api/system.char) 对象的依序只读集合。 在 C# 字符串末尾没有 null 终止字符；因此，一个 C# 字符串可以包含任何数量的嵌入的 null 字符 ('\0')。 字符串的 [Length](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.length) 属性表示其包含的 `Char` 对象数量，而非 Unicode 字符数。 若要访问字符串中的各个 Unicode 码位，请使用 [StringInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.globalization.stringinfo) 对象。

### string 与System.String

在 C# 中，`string` 关键字是 [String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string) 的别名。 因此，`String` 和 `string` 是等效的，你可以使用你所喜欢的任何一种命名约定。 `String` 类提供了安全创建、操作和比较字符串的多种方法。 此外，C# 语言重载了部分运算符，以简化常见字符串操作。 有关关键字的详细信息，请参阅 [string](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/string)。 有关类型及其方法的详细信息，请参阅 [String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)。

### 声明和初始化字符串

可以使用各种方法声明和初始化字符串，如以下示例中所示：

```csharp
// Declare without initializing.
string message1;

// Initialize to null.
string message2 = null;

// Initialize as an empty string.
// Use the Empty constant instead of the literal "".
string message3 = System.String.Empty;

//Initialize with a regular string literal.
string oldPath = "c:\\Program Files\\Microsoft Visual Studio 8.0";

// Initialize with a verbatim string literal.
string newPath = @"c:\Program Files\Microsoft Visual Studio 9.0";

// Use System.String if you prefer.
System.String greeting = "Hello World!";

// In local variables (i.e. within a method body)
// you can use implicit typing.
var temp = "I'm still a strongly-typed System.String!";

// Use a const string to prevent 'message4' from
// being used to store another string value.
const string message4 = "You can't get rid of me!";

// Use the String constructor only when creating
// a string from a char*, char[], or sbyte*. See
// System.String documentation for details.
char[] letters = { 'A', 'B', 'C' };
string alphabet = new string(letters);
```

请注意，不要使用 [new](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/new-operator) 运算符创建字符串对象，除非使用字符数组初始化字符串。

使用 [Empty](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.empty) 常量值初始化字符串，以新建字符串长度为零的 [String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string) 对象。 长度为零的字符串文本表示法是“”。 通过使用 [Empty](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.empty) 值（而不是 [null](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/null)）初始化字符串，可以减少 [NullReferenceException](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullreferenceexception) 发生的可能性。 尝试访问字符串前，先使用静态 [IsNullOrEmpty(String)](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.isnullorempty#System_String_IsNullOrEmpty_System_String_) 方法验证字符串的值。

### 字符串对象的不可变性

字符串对象是“不可变的”：它们在创建后无法更改。 看起来是在修改字符串的所有 [String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string) 方法和 C# 运算符实际上都是在新的字符串对象中返回结果。 在下面的示例中，当 `s1` 和 `s2` 的内容被串联在一起以形成单个字符串时，两个原始字符串没有被修改。 `+=` 运算符创建一个新的字符串，其中包含组合的内容。 这个新对象被分配给变量 `s1`，而分配给 `s1` 的原始对象被释放，以供垃圾回收，因为没有任何其他变量包含对它的引用。

```csharp
string s1 = "A string is more ";
string s2 = "than the sum of its chars.";

// Concatenate s1 and s2. This actually creates a new
// string object and stores it in s1, releasing the
// reference to the original object.
s1 += s2;

System.Console.WriteLine(s1);
// Output: A string is more than the sum of its chars.
```

由于字符串“modification”实际上是一个新创建的字符串，因此，必须在创建对字符串的引用时使用警告。 如果创建了字符串的引用，然后“修改”了原始字符串，则该引用将继续指向原始对象，而非指向修改字符串时所创建的新对象。 以下代码阐释了此行为：

```csharp
string s1 = "Hello ";
string s2 = s1;
s1 += "World";

System.Console.WriteLine(s2);
//Output: Hello
```

若要详细了解如何新建基于修改（如对原始字符串执行的搜索和替换操作）的字符串，请参阅[如何：修改字符串内容](https://docs.microsoft.com/zh-cn/dotnet/csharp/how-to/modify-string-contents)。

### 常规和逐字字符串文本

在必须嵌入 C# 提供的转义字符时，使用常规字符串文本，如以下示例所示：

```csharp
string columns = "Column 1\tColumn 2\tColumn 3";
//Output: Column 1        Column 2        Column 3

string rows = "Row 1\r\nRow 2\r\nRow 3";
/* Output:
  Row 1
  Row 2
  Row 3
*/

string title = "\"The \u00C6olean Harp\", by Samuel Taylor Coleridge";
//Output: "The Æolean Harp", by Samuel Taylor Coleridge
```

当字符串文本包含反斜杠字符（例如在文件路径中）时，出于便捷性和更强的可读性的考虑，使用逐字字符串。由于逐字字符串将新的行字符作为字符串文本的一部分保留，因此可将其用于初始化多行字符串。 使用双引号在逐字字符串内部嵌入引号。 下面的示例演示逐字字符串的一些常见用法：

```csharp
string filePath = @"C:\Users\scoleridge\Documents\";
//Output: C:\Users\scoleridge\Documents\

string text = @"My pensive SARA ! thy soft cheek reclined
    Thus on mine arm, most soothing sweet it is
    To sit beside our Cot,...";
/* Output:
My pensive SARA ! thy soft cheek reclined
   Thus on mine arm, most soothing sweet it is
   To sit beside our Cot,... 
*/

string quote = @"Her name was ""Sara.""";
//Output: Her name was "Sara."
```

### 字符串转义序列

| 转义序列 | 字符名称                                   | Unicode 编码         |
| -------- | ------------------------------------------ | -------------------- |
| \'       | 单引号                                     | 0x0027               |
| \"       | 双引号                                     | 0x0022               |
| \\       | 反斜杠                                     | 0x005C               |
| \0       | null                                       | 0x0000               |
| \a       | 警报                                       | 0x0007               |
| \b       | Backspace                                  | 0x0008               |
| \f       | 换页                                       | 0x000C               |
| \n       | 换行                                       | 0x000A               |
| \r       | 回车                                       | 0x000D               |
| \t       | 水平制表符                                 | 0x0009               |
| \U       | 代理项对的 Unicode 转义序列。              | \Unnnnnnnn           |
| \u       | Unicode 转义序列                           | \u0041 = "A"         |
| \v       | 垂直制表符                                 | 0x000B               |
| \x       | 除长度可变外，Unicode 转义序列与“\u”类似。 | \x0041 或 \x41 = "A" |

> 在编译时，逐字字符串被转换为普通字符串，并具有所有相同的转义序列。 因此，如果在调试器监视窗口中查看逐字字符串，将看到由编译器添加的转义字符，而不是来自你的源代码的逐字字符串版本。 例如，原义字符串 @"C:\files.txt" 在监视窗口中显示为“C:\\files.txt”。

### 格式字符串

格式字符串是在运行时以动态方式确定其内容的字符串。 格式字符串是通过将内插表达式或占位符嵌入字符串大括号内创建的。 大括号 (`{...}`) 中的所有内容都将解析为一个值，并在运行时以格式化字符串的形式输出。 有两种方法创建格式字符串：字符串内插和复合格式。

#### 字符串内插

在 C# 6.0 及更高版本中提供，[内插字符串](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/tokens/interpolated)由 `$` 特殊字符标识，并在大括号中包含内插表达式。 如果不熟悉字符串内插，请参阅[字符串内插 - C# 交互式教程](https://docs.microsoft.com/zh-cn/dotnet/csharp/tutorials/intro-to-csharp/interpolated-strings)快速概览。

使用字符串内插来改善代码的可读性和可维护性。 字符串内插可实现与 `String.Format` 方法相同的结果，但提高了易用性和内联清晰度。

```csharp
var jh = (firstName: "Jupiter", lastName: "Hammon", born: 1711, published: 1761);
Console.WriteLine($"{jh.firstName} {jh.lastName} was an African American poet born in {jh.born}.");
Console.WriteLine($"He was first published in {jh.published} at the age of {jh.published - jh.born}.");
Console.WriteLine($"He'd be over {Math.Round((2018d - jh.born) / 100d) * 100d} years old today.");

// Output:
// Jupiter Hammon was an African American poet born in 1711.
// He was first published in 1761 at the age of 50.
// He'd be over 300 years old today. 
```

#### 复合格式设置

[String.Format](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.format) 利用大括号中的占位符创建格式字符串。 此示例生成与上面使用的字符串内插方法类似的输出。

```csharp
var pw = (firstName: "Phillis", lastName: "Wheatley", born: 1753, published: 1773);
Console.WriteLine("{0} {1} was an African American poet born in {2}.", pw.firstName, pw.lastName, pw.born);
Console.WriteLine("She was first published in {0} at the age of {1}.", pw.published, pw.published - pw.born);
Console.WriteLine("She'd be over {0} years old today.", Math.Round((2018d - pw.born) / 100d) * 100d);

// Output:
// Phillis Wheatley was an African American poet born in 1753.
// She was first published in 1773 at the age of 20.
// She'd be over 300 years old today.
```

有关设置 .NET 类型格式的详细信息，请参阅 [.NET 中的格式设置类型](https://docs.microsoft.com/zh-cn/dotnet/standard/base-types/formatting-types)。

### 子字符串

子字符串是包含在字符串中的任何字符序列。 使用 [Substring](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.substring) 方法可以通过原始字符串的一部分新建字符串。 可以使用 [IndexOf](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.indexof) 方法搜索一次或多次出现的子字符串。 使用 [Replace](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.replace) 方法可以将出现的所有指定子字符串替换为新字符串。 与 [Substring](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.substring) 方法一样，[Replace](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.replace) 实际返回的是新字符串，且不修改原始字符串。 有关详细信息，请参阅[如何：搜索字符串](https://docs.microsoft.com/zh-cn/dotnet/csharp/how-to/search-strings)和[如何：修改字符串内容](https://docs.microsoft.com/zh-cn/dotnet/csharp/how-to/modify-string-contents)。

```csharp
string s3 = "Visual C# Express";
System.Console.WriteLine(s3.Substring(7, 2));
// Output: "C#"

System.Console.WriteLine(s3.Replace("C#", "Basic"));
// Output: "Visual Basic Express"

// Index values are zero-based
int index = s3.IndexOf("C");
// index = 7
```

### 访问单个字符

可以使用包含索引值的数组表示法来获取对单个字符的只读访问权限，如下面的示例中所示：

```csharp
string s5 = "Printing backwards";

for (int i = 0; i < s5.Length; i++)
{
    System.Console.Write(s5[s5.Length - i - 1]);
}
// Output: "sdrawkcab gnitnirP"
```

如果 [String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string) 方法不提供修改字符串中的各个字符所需的功能，可以使用 [StringBuilder](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.stringbuilder) 对象“就地”修改各个字符，再新建字符串来使用 [StringBuilder](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.stringbuilder) 方法存储结果。 在下面的示例中，假定必须以特定方式修改原始字符串，然后存储结果以供未来使用：

```csharp
string question = "hOW DOES mICROSOFT wORD DEAL WITH THE cAPS lOCK KEY?";
System.Text.StringBuilder sb = new System.Text.StringBuilder(question);

for (int j = 0; j < sb.Length; j++)
{
    if (System.Char.IsLower(sb[j]) == true)
        sb[j] = System.Char.ToUpper(sb[j]);
    else if (System.Char.IsUpper(sb[j]) == true)
        sb[j] = System.Char.ToLower(sb[j]);
}
// Store the new string.
string corrected = sb.ToString();
System.Console.WriteLine(corrected);
// Output: How does Microsoft Word deal with the Caps Lock key?            
```

### Null 字符串和空字符串

空字符串是包含零个字符的 [System.String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string) 对象实例。 空字符串常用在各种编程方案中，表示空文本字段。 可以对空字符串调用方法，因为它们是有效的 [System.String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string) 对象。 对空字符串进行了初始化，如下所示：

复制

```
string s = String.Empty;  
```

相比较而言，null 字符串并不指 [System.String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string) 对象实例，只要尝试对 null 字符串调用方法，都会引发 [NullReferenceException](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullreferenceexception)。 但是，可以在串联和与其他字符串的比较操作中使用 null 字符串。 以下示例说明了对 null 字符串的引用会引发和不会引发意外的某些情况：

```csharp
static void Main()
{
    string str = "hello";
    string nullStr = null;
    string emptyStr = String.Empty;

    string tempStr = str + nullStr;
    // Output of the following line: hello
    Console.WriteLine(tempStr);

    bool b = (emptyStr == nullStr);
    // Output of the following line: False
    Console.WriteLine(b);

    // The following line creates a new empty string.
    string newStr = emptyStr + nullStr;

    // Null strings and empty strings behave differently. The following
    // two lines display 0.
    Console.WriteLine(emptyStr.Length);
    Console.WriteLine(newStr.Length);
    // The following line raises a NullReferenceException.
    //Console.WriteLine(nullStr.Length);

    // The null character can be displayed and counted, like other chars.
    string s1 = "\x0" + "abc";
    string s2 = "abc" + "\x0";
    // Output of the following line: * abc*
    Console.WriteLine("*" + s1 + "*");
    // Output of the following line: *abc *
    Console.WriteLine("*" + s2 + "*");
    // Output of the following line: 4
    Console.WriteLine(s2.Length);
}
```

### 使用 StringBuilder 快速创建字符串

.NET 中的字符串操作进行了高度的优化，在大多数情况下不会显著影响性能。 但是，在某些情况下（例如，执行数百次或数千次的紧密循环），字符串操作可能影响性能。 [StringBuilder](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.stringbuilder) 类创建字符串缓冲区，用于在程序执行多个字符串操控时提升性能。 使用 [StringBuilder](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.stringbuilder) 字符串，还可以重新分配各个字符，而内置字符串数据类型则不支持这样做。 例如，此代码更改字符串的内容，而无需创建新的字符串：

```csharp
System.Text.StringBuilder sb = new System.Text.StringBuilder("Rat: the ideal pet");
sb[0] = 'C';
System.Console.WriteLine(sb.ToString());
System.Console.ReadLine();

//Outputs Cat: the ideal pet
```

在以下示例中，[StringBuilder](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.stringbuilder) 对象用于通过一组数字类型创建字符串：

```csharp
class TestStringBuilder
{
    static void Main()
    {
        System.Text.StringBuilder sb = new System.Text.StringBuilder();

        // Create a string composed of numbers 0 - 9
        for (int i = 0; i < 10; i++)
        {
            sb.Append(i.ToString());
        }
        System.Console.WriteLine(sb);  // displays 0123456789

        // Copy one character of the string (not possible with a System.String)
        sb[0] = sb[9];

        System.Console.WriteLine(sb);  // displays 9123456789
    }
}
```

### 字符串、扩展方法和 LINQ

由于 [String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string) 类型实现 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1)，因此可以对字符串使用 [Enumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable) 类中定义的扩展方法。 为了避免视觉干扰，这些方法已从 [String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string) 类型的 IntelliSense 中排除，但它们仍然可用。 此外，还可以使用字符串上的 LINQ 查询表达式。 有关详细信息，请参阅 [LINQ 和字符串](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/linq-and-strings)。

### 相关主题

| 主题                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [如何：修改字符串内容](https://docs.microsoft.com/zh-cn/dotnet/csharp/how-to/modify-string-contents) | 阐明转换字符串并修改字符串内容的方法。                       |
| [如何：比较字符串](https://docs.microsoft.com/zh-cn/dotnet/csharp/how-to/compare-strings) | 演示如何对字符串执行序号和特定于区域性的比较。               |
| [如何：连接多个字符串](https://docs.microsoft.com/zh-cn/dotnet/csharp/how-to/concatenate-multiple-strings) | 演示将多个字符串联接成一个字符串的多种方式。                 |
| [如何：使用 String.Split 分析字符串](https://docs.microsoft.com/zh-cn/dotnet/csharp/how-to/parse-strings-using-split) | 包含代码示例，演示了如何使用 `String.Split` 方法来分析字符串。 |
| [如何：搜索字符串](https://docs.microsoft.com/zh-cn/dotnet/csharp/how-to/search-strings) | 说明如何在字符串中使用搜索来搜索特定的文本或模式。           |
| [如何：确定字符串是否表示数值](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/strings/how-to-determine-whether-a-string-represents-a-numeric-value) | 演示如何安全地分析一个字符串，以查看其是否具有有效的数值。   |
| [字符串内插](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/tokens/interpolated) | 介绍字符串内插功能，它提供了一种方便的语法来格式化字符串。   |
| [基本字符串操作](https://docs.microsoft.com/zh-cn/dotnet/standard/base-types/basic-string-operations) | 收录了介绍如何使用 [System.String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string) 和 [System.Text.StringBuilder](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.stringbuilder) 方法执行基本字符串操作的主题链接。 |
| [分析字符串](https://docs.microsoft.com/zh-cn/dotnet/standard/base-types/parsing-strings) | 介绍如何将 .NET 基类型的字符串表示形式转换为相应类型的实例。 |
| [分析 .NET 中的日期和时间字符串](https://docs.microsoft.com/zh-cn/dotnet/standard/base-types/parsing-datetime) | 展示了如何将字符串（如“01/24/2008”）转换为 [System.DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime) 对象。 |
| [比较字符串](https://docs.microsoft.com/zh-cn/dotnet/standard/base-types/comparing) | 包括有关如何比较字符串的信息，并提供 C# 和 Visual Basic 中的示例。 |
| [使用 StringBuilder 类](https://docs.microsoft.com/zh-cn/dotnet/standard/base-types/stringbuilder) | 介绍了如何使用 [StringBuilder](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.stringbuilder) 类创建和修改动态字符串对象。 |
| [LINQ 和字符串](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/linq-and-strings) | 提供有关如何使用 LINQ 查询来执行各种字符串操作的信息。       |
| [C# 编程指南](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/index) | 提供介绍在 C# 中编程构造的主题的链接。                       |

### [How to: Determine Whether a String Represents a Numeric Value](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/strings/how-to-determine-whether-a-string-represents-a-numeric-value)

若要确定字符串是否是指定数值类型的有效表示形式，请使用由所有基元数值类型以及如 [DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime) 和 [IPAddress](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.ipaddress)等类型实现的静态 `TryParse` 方法。 以下示例演示如何确定“108”是否为有效的 [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int)。

```
int i = 0;   
string s = "108";  
bool result = int.TryParse(s, out i); //i now = 108  
```

如果该字符串包含非数字字符，或者数值对于指定的特定类型而言太大或太小，则 `TryParse` 将返回 false 并将 out 参数设置为零。 否则，它将返回 true 并将 out 参数设置为字符串的数值。

> 字符串可能仅包含数字字符，但对于你使用的 `TryParse` 方法的类型仍然无效。 例如，“256”不是 `byte` 的有效值，但对 `int` 有效。 “98.6”不是 `int` 的有效值，但它是有效的 `decimal`。

#### 示例

以下示例演示如何对 `long`、`byte` 和 `decimal` 值的字符串表示形式使用 `TryParse`。

```csharp
   string numString = "1287543"; //"1287543.0" will return false for a long
   long number1 = 0;
   bool canConvert = long.TryParse(numString, out number1);
   if (canConvert == true)
     Console.WriteLine("number1 now = {0}", number1);
   else
     Console.WriteLine("numString is not a valid long");

   byte number2 = 0;
   numString = "255"; // A value of 256 will return false
   canConvert = byte.TryParse(numString, out number2);
   if (canConvert == true)
     Console.WriteLine("number2 now = {0}", number2);
   else
     Console.WriteLine("numString is not a valid byte");

   decimal number3 = 0;
   numString = "27.3"; //"27" is also a valid decimal
   canConvert = decimal.TryParse(numString, out number3);
   if (canConvert == true)
     Console.WriteLine("number3 now = {0}", number3);
   else
     Console.WriteLine("number3 is not a valid decimal");            
```

#### 可靠编程

基元数值类型还实现 `Parse` 静态方法，如果字符串不是有效数字，该方法将引发异常。 `TryParse` 通常更高效，因为如果数值无效，它仅返回 false。

#### .NET Framework 安全性

请务必使用 `TryParse` 或 `Parse` 方法验证控件（如文本框和组合框）中的用户输入。

