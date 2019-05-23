# [Lexical structure](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/language-specification/lexical-structure)

## Programs

C#***程序***包含一个或多个***源文件***，以前称为***编译单元***([编译单元](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/namespaces#compilation-units))。 源代码文件是 Unicode 字符的有序的序列。 源文件通常具有一对一的对应关系与文件在文件系统中，但这种对应关系不是必需的。 最大的可移植性，建议使用 utf-8 进行编码的文件系统中的文件编码。

从概念上讲，程序的编译使用三个步骤：

1. 转换，可将文件从特定的字符库和编码方案转换为 Unicode 字符序列。
2. 词法分析，Unicode 输入字符的流转换为标记流。
3. 语法分析，标记流将转换为可执行代码。

## 语法

此规范提供了 C# 编程语言使用两种语法的语法。 ***词法语法***([词法语法](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#lexical-grammar)) 定义的 Unicode 字符组合窗体行终止符、 空格、 注释、 标记和预处理指令。 ***句法语法***([句法语法](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#syntactic-grammar)) 定义如何将从词法语法生成的令牌组合以构成 C# 程序。

### 语法表示法

巴科斯-诺尔范式使用 ANTLR 语法工具表示法中显示的词法和语法的语法。

### 词法语法

C# 的词法语法所示[词法分析](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#lexical-analysis)，[令牌](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#tokens)，并[预处理指令](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#pre-processing-directives)。 词法语法的结束符号是 Unicode 字符集的字符和词法语法指定如何对窗体标记组合字符 ([令牌](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#tokens))，空白区域 ([空白](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#white-space))，注释 ([注释](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#comments))，和预处理指令 ([预处理指令](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#pre-processing-directives))。

C# 程序中的每个源文件必须符合*输入*生产词法语法 ([词法分析](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#lexical-analysis))。

### 语法的语法

C# 语法的语法所示的章节和附录遵循这一章。 语法的语法的结束符号是由词法语法，定义的令牌和语法的语法指定令牌组合以构成 C# 程序的方式。

每个源文件中的C#程序必须符合*compilation_unit*语法的语法的生产 ([编译单元](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/namespaces#compilation-units))。

## 词法分析

*输入*生产定义 C# 源文件的词法结构。 C# 程序中的每个源文件必须符合此词法语法生产。

antlr复制

```antlr
input
    : input_section?
    ;

input_section
    : input_section_part+
    ;

input_section_part
    : input_element* new_line
    | pp_directive
    ;

input_element
    : whitespace
    | comment
    | token
    ;
```

五个基本元素组成的词法结构的C#源文件：行终止符 ([行终止符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#line-terminators))，空白区域 ([空白](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#white-space))，注释 ([注释](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#comments))，令牌 ([令牌](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#tokens))，并预处理指令 ([预处理指令](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#pre-processing-directives))。 这些基本元素，只有标记非常重要，C# 程序的语法的语法 ([句法语法](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#syntactic-grammar))。

C# 源文件的词法处理包括将文件缩减成的标记序列，它将成为 syntactic 分析的输入。 行终止符，空白区域和注释可以用于分隔标记，和预处理指令可能会导致部分的源文件要跳过，但除此之外这些词法元素上的 C# 程序的语法结构没有任何影响。

如果内插的字符串文本 ([内插字符串文本](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#interpolated-string-literals)) 的单个令牌最初由词法分析，但将分解为多个输入元素的重复受制于词法分析直到所有内插的字符串文本已得到解决。 生成的令牌随后可充当句法分析的输入。

当多个词法语法生产匹配的源代码文件中的字符序列时，词法处理始终窗体的最长可能词法元素。 例如，字符序列`//`处理为单行注释的开头，因为该词法元素的长度超过单个`/`令牌。

### 行终止符

行终止符将行分成若干 C# 源文件中的字符。

antlr复制

```antlr
new_line
    : '<Carriage return character (U+000D)>'
    | '<Line feed character (U+000A)>'
    | '<Carriage return character (U+000D) followed by line feed character (U+000A)>'
    | '<Next line character (U+0085)>'
    | '<Line separator character (U+2028)>'
    | '<Paragraph separator character (U+2029)>'
    ;
```

与源的兼容性代码编辑添加的文件结束标记的工具和以启用源文件以正确地查看序列的形式结束的行，被应用以下转换，以便 C# 程序中每个源文件：

- 源代码文件的最后一个字符是否是控制 Z 字符 (`U+001A`)，删除此字符。
- 回车符 (`U+000D`) 如果该源文件为非空和源代码文件的最后一个字符不是回车符后添加到源代码文件的末尾 (`U+000D`)，换行符 (`U+000A`)，行分隔符 (`U+2028`)，或段落分隔符 (`U+2029`)。

### 注释

支持两种形式的注释： 单行注释和带分隔符的注释。 ***单行注释***以字符开头`//`并将扩展到源行的末尾。 ***带分隔符的注释***以字符开头`/*`和其中包含的字符结束`*/`。 带分隔符的注释可以跨多个行。

antlr复制

```antlr
comment
    : single_line_comment
    | delimited_comment
    ;

single_line_comment
    : '//' input_character*
    ;

input_character
    : '<Any Unicode character except a new_line_character>'
    ;

new_line_character
    : '<Carriage return character (U+000D)>'
    | '<Line feed character (U+000A)>'
    | '<Next line character (U+0085)>'
    | '<Line separator character (U+2028)>'
    | '<Paragraph separator character (U+2029)>'
    ;

delimited_comment
    : '/*' delimited_comment_section* asterisk* '/'
    ;

delimited_comment_section
    : '/'
    | asterisk* not_slash_or_asterisk
    ;

asterisk
    : '*'
    ;

not_slash_or_asterisk
    : '<Any Unicode character except / or *>'
    ;
```

注释不嵌套。 字符序列`/*`并`*/`中没有特殊含义`//`注释和字符序列`//`和`/*`分隔注释中没有特殊含义。

注释不会处理在字符和字符串文本中。

该示例

C#复制

```csharp
/* Hello, world program
   This program writes "hello, world" to the console
*/
class Hello
{
    static void Main() {
        System.Console.WriteLine("hello, world");
    }
}
```

包括带分隔符的注释。

该示例

C#复制

```csharp
// Hello, world program
// This program writes "hello, world" to the console
//
class Hello // any name will do for this class
{
    static void Main() { // this method must be named "Main"
        System.Console.WriteLine("hello, world");
    }
}
```

显示多个单行注释。

### 空格

空白被定义为与 Unicode 类 Zs （其中包括空格字符） 的任何字符，以及水平制表符、 垂直制表符和窗体换页符。

antlr复制

```antlr
whitespace
    : '<Any character with Unicode class Zs>'
    | '<Horizontal tab character (U+0009)>'
    | '<Vertical tab character (U+000B)>'
    | '<Form feed character (U+000C)>'
    ;
```

## 标记

有几个类型的标记： 标识符、 关键字、 文字、 运算符和标点符号。 空白和注释不是标记，但它们可以充当标记的分隔符。

antlr复制

```antlr
token
    : identifier
    | keyword
    | integer_literal
    | real_literal
    | character_literal
    | string_literal
    | interpolated_string_literal
    | operator_or_punctuator
    ;
```

### Unicode 字符转义序列

Unicode 字符转义序列表示 Unicode 字符。 在标识符中处理 Unicode 字符转义序列 ([标识符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#identifiers))，字符文本 ([字符文本](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#character-literals))，和规则字符串文本 ([字符串文本](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#string-literals)). 在任何其他位置 （例如，若要形成运算符、 标点符号或关键字） 不处理 Unicode 字符转义符。

antlr复制

```antlr
unicode_escape_sequence
    : '\\u' hex_digit hex_digit hex_digit hex_digit
    | '\\U' hex_digit hex_digit hex_digit hex_digit hex_digit hex_digit hex_digit hex_digit
    ;
```

Unicode 转义序列表示单个 Unicode 字符格式正确的后接十六进制数"`\u`"或"`\U`"字符。 由于 C# 使用字符和字符串值中的 Unicode 码位的 16 位编码，范围 u+10000 到 U + 10FFFF 中的 Unicode 字符的字符文本中不允许使用和文本字符串中使用 Unicode 代理项对表示。 不支持与 0x10FFFF 上面的代码点的 Unicode 字符。

不执行多个翻译。 例如，文字字符串"`\u005Cu005C`"是等效于"`\u005C`"而非"`\`"。 Unicode 值`\u005C`是字符"`\`"。

该示例

C#复制

```csharp
class Class1
{
    static void Test(bool \u0066) {
        char c = '\u0066';
        if (\u0066)
            System.Console.WriteLine(c.ToString());
    }        
}
```

显示的几种用法`\u0066`，这是字母的转义序列"`f`"。 该计划相当于

C#复制

```csharp
class Class1
{
    static void Test(bool f) {
        char c = 'f';
        if (f)
            System.Console.WriteLine(c.ToString());
    }        
}
```

### 标识符

此节中给出的标识符的规则精确对应于这些建议由 Unicode 标准附录 31，只不过下划线允许一个初始字符 （这是传统 C 编程语言中），作为 Unicode 转义序列允许在标识符中使用和"`@`"字符允许作为前缀，以使关键字用作标识符。

antlr复制

```antlr
identifier
    : available_identifier
    | '@' identifier_or_keyword
    ;

available_identifier
    : '<An identifier_or_keyword that is not a keyword>'
    ;

identifier_or_keyword
    : identifier_start_character identifier_part_character*
    ;

identifier_start_character
    : letter_character
    | '_'
    ;

identifier_part_character
    : letter_character
    | decimal_digit_character
    | connecting_character
    | combining_character
    | formatting_character
    ;

letter_character
    : '<A Unicode character of classes Lu, Ll, Lt, Lm, Lo, or Nl>'
    | '<A unicode_escape_sequence representing a character of classes Lu, Ll, Lt, Lm, Lo, or Nl>'
    ;

combining_character
    : '<A Unicode character of classes Mn or Mc>'
    | '<A unicode_escape_sequence representing a character of classes Mn or Mc>'
    ;

decimal_digit_character
    : '<A Unicode character of the class Nd>'
    | '<A unicode_escape_sequence representing a character of the class Nd>'
    ;

connecting_character
    : '<A Unicode character of the class Pc>'
    | '<A unicode_escape_sequence representing a character of the class Pc>'
    ;

formatting_character
    : '<A Unicode character of the class Cf>'
    | '<A unicode_escape_sequence representing a character of the class Cf>'
    ;
```

上面提到的 Unicode 字符类的信息，请参阅 Unicode 标准、 3.0 版、 部分 4.5。

有效标识符的示例包括"`identifier1`"，"`_identifier2`"，并"`@if`"。

由 Unicode 标准附录 15 定义一致的程序中的标识符必须由 Unicode 范式 C，定义的规范格式。 遇到不在范式 C 中的标识符时的行为是实现定义的;但是，诊断则不需要。

前缀"`@`"可以将关键字用作标识符，这与其他编程语言进行交互时非常有用。 字符`@`不是实际的标识符的一部分，因此标识符可能被视为其他语言中的常规标识符，不带前缀。 具有的标识符`@`名为前缀***逐字字符串标识符***。 使用`@`允许使用，但强烈建议不要使用作为一种样式不是关键字的标识符的前缀。

下面的示例：

C#复制

```csharp
class @class
{
    public static void @static(bool @bool) {
        if (@bool)
            System.Console.WriteLine("true");
        else
            System.Console.WriteLine("false");
    }    
}

class Class1
{
    static void M() {
        cl\u0061ss.st\u0061tic(true);
    }
}
```

定义一个名为"`class`"具有静态方法，名为"`static`"，只需一个名为参数"`bool`"。 请注意，由于 Unicode 转义不允许在关键字令牌"`cl\u0061ss`"是一个标识符，和是相同的标识符"`@class`"。

如果它们是相同的应用以下转换，按顺序后，两个标识符被视为相同：

- 前缀"`@`"，如果使用，会删除。
- 每个*unicode_escape_sequence*转换为其对应的 Unicode 字符。
- 任何*formatting_character*已移除。

标识符包含两个连续的下划线字符 (`U+005F`) 仅供使用的实现。 例如，实现可能会提供两个下划线开头的扩展的关键字。

### 关键字

一个***关键字***是一个标识符-类似于序列的字符是保留的并且不能用作标识符的开头时除外`@`字符。

antlr复制

```antlr
keyword
    : 'abstract' | 'as'       | 'base'       | 'bool'      | 'break'
    | 'byte'     | 'case'     | 'catch'      | 'char'      | 'checked'
    | 'class'    | 'const'    | 'continue'   | 'decimal'   | 'default'
    | 'delegate' | 'do'       | 'double'     | 'else'      | 'enum'
    | 'event'    | 'explicit' | 'extern'     | 'false'     | 'finally'
    | 'fixed'    | 'float'    | 'for'        | 'foreach'   | 'goto'
    | 'if'       | 'implicit' | 'in'         | 'int'       | 'interface'
    | 'internal' | 'is'       | 'lock'       | 'long'      | 'namespace'
    | 'new'      | 'null'     | 'object'     | 'operator'  | 'out'
    | 'override' | 'params'   | 'private'    | 'protected' | 'public'
    | 'readonly' | 'ref'      | 'return'     | 'sbyte'     | 'sealed'
    | 'short'    | 'sizeof'   | 'stackalloc' | 'static'    | 'string'
    | 'struct'   | 'switch'   | 'this'       | 'throw'     | 'true'
    | 'try'      | 'typeof'   | 'uint'       | 'ulong'     | 'unchecked'
    | 'unsafe'   | 'ushort'   | 'using'      | 'virtual'   | 'void'
    | 'volatile' | 'while'
    ;
```

在语法中某些地方，特定标识符具有特殊含义，但不是关键字。 此类标识符有时称为"上下文关键字"。 例如，在属性声明中，"`get`"和"`set`"标识符具有特殊含义 ([访问器](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#accessors))。 以外的其他标识符`get`或`set`永远不会允许在这些位置，因此此，请使用不与这些关键字作为标识符的使用冲突。 在其他情况下，例如为具有标识符"`var`"隐式类型本地变量声明中 ([局部变量声明](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/statements#local-variable-declarations))，上下文关键字可以与声明名称发生冲突。 在这种情况下，声明的名称将优先于使用上下文关键字作为标识符。

### 文本

一个***文字***是一个值的源的代码表示形式。

antlr复制

```antlr
literal
    : boolean_literal
    | integer_literal
    | real_literal
    | character_literal
    | string_literal
    | null_literal
    ;
```

#### 布尔文本

有两个布尔文本值：`true`和`false`。

antlr复制

```antlr
boolean_literal
    : 'true'
    | 'false'
    ;
```

类型*boolean_literal*是`bool`。

#### 整数文本

整数文本，用于编写类型的值`int`， `uint`， `long`，和`ulong`。 整数文本具有两个可能的形式： 十进制和十六进制。

antlr复制

```antlr
integer_literal
    : decimal_integer_literal
    | hexadecimal_integer_literal
    ;

decimal_integer_literal
    : decimal_digit+ integer_type_suffix?
    ;

decimal_digit
    : '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
    ;

integer_type_suffix
    : 'U' | 'u' | 'L' | 'l' | 'UL' | 'Ul' | 'uL' | 'ul' | 'LU' | 'Lu' | 'lU' | 'lu'
    ;

hexadecimal_integer_literal
    : '0x' hex_digit+ integer_type_suffix?
    | '0X' hex_digit+ integer_type_suffix?
    ;

hex_digit
    : '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
    | 'A' | 'B' | 'C' | 'D' | 'E' | 'F' | 'a' | 'b' | 'c' | 'd' | 'e' | 'f';
```

整数文本的类型确定，如下所示：

- 如果整数没有后缀，它具有第一个类型可以在其中表示其值： `int`， `uint`， `long`， `ulong`。
- 如果文本带有后缀`U`或`u`，它具有第一个类型可以在其中表示其值： `uint`， `ulong`。
- 如果文本带有后缀`L`或`l`，它具有第一个类型可以在其中表示其值： `long`， `ulong`。
- 如果文本带有后缀`UL`， `Ul`， `uL`， `ul`， `LU`， `Lu`， `lU`，或`lu`，它是类型`ulong`。

如果整数文本所表示的值位于外部的范围`ulong`类型，则发生编译时错误。

作为一种样式的但还是建议的"`L`"使用而不是"`l`"写入类型的文字时`long`，因为很容易混淆字母"`l`"与数字"`1`"。

若要允许的最小可能`int`和`long`值要写为十进制整数文本，存在以下两个规则：

- 时*decimal_integer_literal*具有值 2147483648 (2 ^31) 和无*integer_type_suffix*显示为紧跟一元负运算符令牌的令牌 ([一元负运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#unary-minus-operator))，结果是类型的常量`int`值介于-2147483648 (-2 ^31)。 在所有其他情况下，此类*decimal_integer_literal*属于类型`uint`。
- 当*decimal_integer_literal*具有值 9223372036854775808 (2 ^63) 和无*integer_type_suffix*或*integer_type_suffix*`L`或`l`显示为紧跟一元负运算符令牌的令牌 ([一元负运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#unary-minus-operator))，结果是类型的常量`long`值-9223372036854775808 (-2 ^63)。 在所有其他情况下，此类*decimal_integer_literal*属于类型`ulong`。

#### 实际的文本

实际文本可用于编写类型的值`float`， `double`，和`decimal`。

antlr复制

```antlr
real_literal
    : decimal_digit+ '.' decimal_digit+ exponent_part? real_type_suffix?
    | '.' decimal_digit+ exponent_part? real_type_suffix?
    | decimal_digit+ exponent_part real_type_suffix?
    | decimal_digit+ real_type_suffix
    ;

exponent_part
    : 'e' sign? decimal_digit+
    | 'E' sign? decimal_digit+
    ;

sign
    : '+'
    | '-'
    ;

real_type_suffix
    : 'F' | 'f' | 'D' | 'd' | 'M' | 'm'
    ;
```

如果没有*real_type_suffix*指定实数的文本的类型是`double`。 否则，实际类型后缀，如下所示确定实际的文本，类型：

- Real 文字加上后缀`F`或`f`属于类型`float`。 例如，文字`1f`， `1.5f`， `1e10f`，和`123.456F`都是类型的`float`。
- Real 文字加上后缀`D`或`d`属于类型`double`。 例如，文字`1d`， `1.5d`， `1e10d`，和`123.456D`都是类型的`double`。
- Real 文字加上后缀`M`或`m`属于类型`decimal`。 例如，文字`1m`， `1.5m`， `1e10m`，和`123.456M`都是类型的`decimal`。 此文本转换为`decimal`通过采用确切的值，并如有必要，则舍入为最接近的可表示的值使用值银行家的舍入 ([十进制类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/types#the-decimal-type))。 除非舍入值或值为零 （在后一种情况中的登录和小数位数为 0），将保留该实数任何规模。 因此，文字`2.900m`将对其进行分析，以形成以符号的十进制`0`，决定系数`2900`，和小数位数`3`。

如果指定的文本无法出现在指定的类型，发生编译时错误。

值类型的实际文字`float`或`double`由使用 IEEE"舍入为最接近"模式。

请注意，在实数，小数位数始终需要小数点后。 例如，`1.3F`是一个实数文本但`1.F`不是。

#### 字符文本

字符文本表示单个字符，一般包含的字符用引号引起来，如`'a'`。

注意:ANTLR 语法表示法实现了以下令人困惑 ！ 在 ANTLR，当你编写`\'`它代表一个单引号`'`。 当你编写和`\\`它代表单个反斜杠`\`。 因此字符文本的第一个规则意味着开头单引号，然后是字符，最后一个单引号。 和 11 个可能的简单转义序列`\'`， `\"`， `\\`， `\0`， `\a`， `\b`， `\f`， `\n`， `\r`， `\t`， `\v`.

antlr复制

```antlr
character_literal
    : '\'' character '\''
    ;

character
    : single_character
    | simple_escape_sequence
    | hexadecimal_escape_sequence
    | unicode_escape_sequence
    ;

single_character
    : '<Any character except \' (U+0027), \\ (U+005C), and new_line_character>'
    ;

simple_escape_sequence
    : '\\\'' | '\\"' | '\\\\' | '\\0' | '\\a' | '\\b' | '\\f' | '\\n' | '\\r' | '\\t' | '\\v'
    ;

hexadecimal_escape_sequence
    : '\\x' hex_digit hex_digit? hex_digit? hex_digit?;
```

反斜杠字符后面的字符 (`\`) 中*字符*必须是下列字符之一： `'`， `"`， `\`， `0`， `a`， `b`, `f`, `n`, `r`, `t`, `u`, `U`, `x`, `v`. 否则，将发生编译时错误。

十六进制转义序列表示单个 Unicode 字符，后接十六进制数的格式正确的值与"`\x`"。

如果表示的字符文本的值大于`U+FFFF`，则发生编译时错误。

Unicode 字符转义序列 ([Unicode 字符转义序列](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#unicode-character-escape-sequences)) 中的字符文本必须在范围内`U+0000`到`U+FFFF`。

简单转义序列表示 Unicode 字符编码下, 表中所述。

| **转义序列** | **字符名称** | **Unicode 编码** |
| ------------ | ------------ | ---------------- |
| `\'`         | 单引号       | `0x0027`         |
| `\"`         | 双引号       | `0x0022`         |
| `\\`         | 反斜杠       | `0x005C`         |
| `\0`         | null         | `0x0000`         |
| `\a`         | 警报         | `0x0007`         |
| `\b`         | Backspace    | `0x0008`         |
| `\f`         | 换页         | `0x000C`         |
| `\n`         | 换行         | `0x000A`         |
| `\r`         | 回车         | `0x000D`         |
| `\t`         | 水平制表符   | `0x0009`         |
| `\v`         | 垂直制表符   | `0x000B`         |

类型*character_literal*是`char`。

#### 字符串文本

C# 支持两种形式的字符串文本：***规则字符串文本***并***逐字字符串文本***。

常规字符串括在双引号内，作为中的零个或多个字符组成`"hello"`，并且可能包括这两个简单的转义序列 (如`\t`选项卡上的字符)，十六进制转义序列和 Unicode 转义序列。

原义字符串组成`@`字符后跟双引号字符、 零个或多个字符和右双引号字符。 一个简单示例是`@"hello"`。 在逐字字符串文本中，分隔符之间的字符逐字解释，唯一的异常所*quote_escape_sequence*。 具体而言，简单的转义序列和十六进制和 Unicode 转义序列不处理逐字字符串文本中。 逐字字符串文本可能跨多个行。

antlr复制

```antlr
string_literal
    : regular_string_literal
    | verbatim_string_literal
    ;

regular_string_literal
    : '"' regular_string_literal_character* '"'
    ;

regular_string_literal_character
    : single_regular_string_literal_character
    | simple_escape_sequence
    | hexadecimal_escape_sequence
    | unicode_escape_sequence
    ;

single_regular_string_literal_character
    : '<Any character except " (U+0022), \\ (U+005C), and new_line_character>'
    ;

verbatim_string_literal
    : '@"' verbatim_string_literal_character* '"'
    ;

verbatim_string_literal_character
    : single_verbatim_string_literal_character
    | quote_escape_sequence
    ;

single_verbatim_string_literal_character
    : '<any character except ">'
    ;

quote_escape_sequence
    : '""'
    ;
```

反斜杠字符后面的字符 (`\`) 中*regular_string_literal_character*必须是下列字符之一： `'`， `"`， `\`， `0`， `a`, `b`, `f`, `n`, `r`, `t`, `u`, `U`, `x`, `v`. 否则，将发生编译时错误。

该示例

C#复制

```csharp
string a = "hello, world";                   // hello, world
string b = @"hello, world";                  // hello, world

string c = "hello \t world";                 // hello      world
string d = @"hello \t world";                // hello \t world

string e = "Joe said \"Hello\" to me";       // Joe said "Hello" to me
string f = @"Joe said ""Hello"" to me";      // Joe said "Hello" to me

string g = "\\\\server\\share\\file.txt";    // \\server\share\file.txt
string h = @"\\server\share\file.txt";       // \\server\share\file.txt

string i = "one\r\ntwo\r\nthree";
string j = @"one
two
three";
```

显示了各种不同的字符串。 最后一个字符串文字， `j`，是原义字符串文字跨多个行。 将保留原义之间引号，包括新行字符，如空格字符。

由于十六进制转义序列可以具有可变数量的十六进制数字，字符串文字`"\x123"`包含单个字符具有十六进制值 123。 若要创建包含具有十六进制值后跟字符 3 12 的字符的字符串，其中一个可以编写`"\x00123"`或`"\x12" + "3"`相反。

类型*string_literal*是`string`。

每个字符串文字不一定产生新的字符串实例。 两个或多个字符串的相等时根据字符串的相等运算符 ([字符串是否相等运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#string-equality-operators)) 出现在同一个程序，这些字符串文字引用相同的字符串实例。 例如，生成的输出

C#复制

```csharp
class Test
{
    static void Main() {
        object a = "hello";
        object b = "hello";
        System.Console.WriteLine(a == b);
    }
}
```

是`True`因为两个字符串引用相同的字符串实例。

#### 内插的字符串文本

内插的字符串类似于字符串文本，但包含洞分隔`{`和`}`，其中表达式可以出现。 在运行时，使它们代入漏洞的出现位置的位置处的字符串的文本形式计算这些表达式。 部分中描述的语法和语义字符串内插 ([内插字符串](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#interpolated-strings))。

字符串文本，如内插的字符串文字可以定期或原义。 内插规则字符串文本分隔`$"`并`"`，并由分隔内插逐字字符串文本`$@"`和`"`。

像其他文本内, 插字符串文字的词法分析最初导致单个令牌，根据下面的语法。 但是之前句法分析, 内, 插字符串文字的单个令牌分解为多个令牌封闭漏洞，该字符串的各部分和的孔内发生的输入的元素从词法上再次分析。 反过来，这可能会产生更内插的字符串文本，以便得到处理，但是，如果从词法上更正，最终导致一系列的语法分析，以处理令牌。

antlr复制

```antlr
interpolated_string_literal
    : '$' interpolated_regular_string_literal
    | '$' interpolated_verbatim_string_literal
    ;

interpolated_regular_string_literal
    : interpolated_regular_string_whole
    | interpolated_regular_string_start  interpolated_regular_string_literal_body interpolated_regular_string_end
    ;

interpolated_regular_string_literal_body
    : regular_balanced_text
    | interpolated_regular_string_literal_body interpolated_regular_string_mid regular_balanced_text
    ;

interpolated_regular_string_whole
    : '"' interpolated_regular_string_character* '"'
    ;

interpolated_regular_string_start
    : '"' interpolated_regular_string_character* '{'
    ;

interpolated_regular_string_mid
    : interpolation_format? '}' interpolated_regular_string_characters_after_brace? '{'
    ;

interpolated_regular_string_end
    : interpolation_format? '}' interpolated_regular_string_characters_after_brace? '"'
    ;

interpolated_regular_string_characters_after_brace
    : interpolated_regular_string_character_no_brace
    | interpolated_regular_string_characters_after_brace interpolated_regular_string_character
    ;

interpolated_regular_string_character
    : single_interpolated_regular_string_character
    | simple_escape_sequence
    | hexadecimal_escape_sequence
    | unicode_escape_sequence
    | open_brace_escape_sequence
    | close_brace_escape_sequence
    ;

interpolated_regular_string_character_no_brace
    : '<Any interpolated_regular_string_character except close_brace_escape_sequence and any hexadecimal_escape_sequence or unicode_escape_sequence designating } (U+007D)>'
    ;

single_interpolated_regular_string_character
    : '<Any character except \" (U+0022), \\ (U+005C), { (U+007B), } (U+007D), and new_line_character>'
    ;

open_brace_escape_sequence
    : '{{'
    ;

    close_brace_escape_sequence
    : '}}'
    ;
    
regular_balanced_text
    : regular_balanced_text_part+
    ;

regular_balanced_text_part
    : single_regular_balanced_text_character
    | delimited_comment
    | '@' identifier_or_keyword
    | string_literal
    | interpolated_string_literal
    | '(' regular_balanced_text ')'
    | '[' regular_balanced_text ']'
    | '{' regular_balanced_text '}'
    ;
    
single_regular_balanced_text_character
    : '<Any character except / (U+002F), @ (U+0040), \" (U+0022), $ (U+0024), ( (U+0028), ) (U+0029), [ (U+005B), ] (U+005D), { (U+007B), } (U+007D) and new_line_character>'
    | '</ (U+002F), if not directly followed by / (U+002F) or * (U+002A)>'
    ;
    
interpolation_format
    : interpolation_format_character+
    ;
    
interpolation_format_character
    : '<Any character except \" (U+0022), : (U+003A), { (U+007B) and } (U+007D)>'
    ;
    
interpolated_verbatim_string_literal
    : interpolated_verbatim_string_whole
    | interpolated_verbatim_string_start interpolated_verbatim_string_literal_body interpolated_verbatim_string_end
    ;

interpolated_verbatim_string_literal_body
    : verbatim_balanced_text
    | interpolated_verbatim_string_literal_body interpolated_verbatim_string_mid verbatim_balanced_text
    ;
    
interpolated_verbatim_string_whole
    : '@"' interpolated_verbatim_string_character* '"'
    ;
    
interpolated_verbatim_string_start
    : '@"' interpolated_verbatim_string_character* '{'
    ;
    
interpolated_verbatim_string_mid
    : interpolation_format? '}' interpolated_verbatim_string_characters_after_brace? '{'
    ;
    
interpolated_verbatim_string_end
    : interpolation_format? '}' interpolated_verbatim_string_characters_after_brace? '"'
    ;
    
interpolated_verbatim_string_characters_after_brace
    : interpolated_verbatim_string_character_no_brace
    | interpolated_verbatim_string_characters_after_brace interpolated_verbatim_string_character
    ;
    
interpolated_verbatim_string_character
    : single_interpolated_verbatim_string_character
    | quote_escape_sequence
    | open_brace_escape_sequence
    | close_brace_escape_sequence
    ;
    
interpolated_verbatim_string_character_no_brace
    : '<Any interpolated_verbatim_string_character except close_brace_escape_sequence>'
    ;
    
single_interpolated_verbatim_string_character
    : '<Any character except \" (U+0022), { (U+007B) and } (U+007D)>'
    ;
    
verbatim_balanced_text
    : verbatim_balanced_text_part+
    ;

verbatim_balanced_text_part
    : single_verbatim_balanced_text_character
    | comment
    | '@' identifier_or_keyword
    | string_literal
    | interpolated_string_literal
    | '(' verbatim_balanced_text ')'
    | '[' verbatim_balanced_text ']'
    | '{' verbatim_balanced_text '}'
    ;
    
single_verbatim_balanced_text_character
    : '<Any character except / (U+002F), @ (U+0040), \" (U+0022), $ (U+0024), ( (U+0028), ) (U+0029), [ (U+005B), ] (U+005D), { (U+007B) and } (U+007D)>'
    | '</ (U+002F), if not directly followed by / (U+002F) or * (U+002A)>'
    ;
```

*Interpolated_string_literal*令牌重新解释为多个令牌和其他输入元素，如下所示的中的出现顺序*interpolated_string_literal*:

- 以下的匹配项作为单独的各个标记重新解释： 前导`$`的登录， *interpolated_regular_string_whole*， *interpolated_regular_string_start*，*interpolated_regular_string_mid*， *interpolated_regular_string_end*， *interpolated_verbatim_string_whole*， *interpolated_verbatim_string_start*， *interpolated_verbatim_string_mid*并*interpolated_verbatim_string_end*。
- 出现次数*regular_balanced_text*并*verbatim_balanced_text*它们之间重新为处理*input_section* ([词法分析](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#lexical-analysis)) 和所产生的序列的输入元素为重新解释。 这些可能依次包含内插的字符串文本标记被重新解释。

句法分析将重新组合到令牌*interpolated_string_expression* ([内插字符串](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#interpolated-strings))。

示例待办事项

#### Null 文本

antlr复制

```antlr
null_literal
    : 'null'
    ;
```

*Null_literal*可以隐式转换为引用类型或可以为 null 的类型。

### 运算符和标点符号

有几种类型的运算符和标点符号。 在表达式中使用的运算符用于描述涉及一个或多个操作数的操作。 例如，表达式`a + b`使用`+`运算符将两个操作数`a`和`b`。 标点符号是用于分组和分隔。

antlr复制

```antlr
operator_or_punctuator
    : '{'  | '}'  | '['  | ']'  | '('   | ')'  | '.'  | ','  | ':'  | ';'
    | '+'  | '-'  | '*'  | '/'  | '%'   | '&'  | '|'  | '^'  | '!'  | '~'
    | '='  | '<'  | '>'  | '?'  | '??'  | '::' | '++' | '--' | '&&' | '||'
    | '->' | '==' | '!=' | '<=' | '>='  | '+=' | '-=' | '*=' | '/=' | '%='
    | '&=' | '|=' | '^=' | '<<' | '<<=' | '=>'
    ;

right_shift
    : '>>'
    ;

right_shift_assignment
    : '>>='
    ;
```

中的竖线*right_shift*并*right_shift_assignment*生产用于与不同的语法的语法中，任何类型的任何字符中的其他生产中 （甚至不指示，空格） 允许标记之间。 这些生产处理以便正确处理特殊*type_parameter_list*s ([类型参数](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#type-parameters))。

## 预处理指令

预处理指令提供有条件地跳过的源代码文件，报告错误和警告条件节以及描绘不同区域的源代码的能力。 术语"预处理指令"仅用于与 C 和 c + + 编程语言的一致性。 在 C# 中，没有任何单独的预处理步骤;预处理指令处理作为词法分析阶段的一部分。

antlr复制

```antlr
pp_directive
    : pp_declaration
    | pp_conditional
    | pp_line
    | pp_diagnostic
    | pp_region
    | pp_pragma
    ;
```

提供了以下预处理指令：

- `#define` 并`#undef`，用于定义和未定义，分别条件编译符号 ([声明指令](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#declaration-directives))。
- `#if``#elif`， `#else`，并`#endif`，用于有条件地跳过的源代码节 ([条件编译指令](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#conditional-compilation-directives))。
- `#line`用于控制发出错误和警告的行号 ([行指令](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#line-directives))。
- `#error` 并`#warning`，用于分别发出错误和警告 ([诊断指令](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#diagnostic-directives))。
- `#region` 并`#endregion`，用于将源代码部分显式标记 ([Region 指令](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#region-directives))。
- `#pragma`用于指定到编译器的可选上下文信息 ([杂注指令](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#pragma-directives))。

预处理指令总是占用单独的行的源代码，并且始终开头`#`字符和预处理指令名称。 空白区域可能会发生之前`#`字符和介于`#`字符和指令的名称。

源行包含`#define`， `#undef`， `#if`， `#elif`， `#else`， `#endif`， `#line`，或`#endregion`指令可以其结尾的单行注释。 带分隔符的注释 (`/* */`样式的注释) 包含预处理指令的源行上不允许。

预处理指令既不是标记，也不是语法的 C# 语法的一部分。 但是，预处理指令可用于包含或排除的令牌的序列，可以通过这种方式影响 C# 程序的含义。 例如，当编译该程序：

C#复制

```csharp
#define A
#undef B

class C
{
#if A
    void F() {}
#else
    void G() {}
#endif

#if B
    void H() {}
#else
    void I() {}
#endif
}
```

完全相同的序列中的令牌作为该程序的结果：

C#复制

```csharp
class C
{
    void F() {}
    void I() {}
}
```

因此，从词法上，两个程序大不相同，语法上，而它们相同。

### 条件编译符号

提供的条件编译功能`#if`， `#elif`， `#else`，和`#endif`预处理表达式可以通过控制的指令 ([预处理表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#pre-processing-expressions))和条件编译符号。

antlr复制

```antlr
conditional_symbol
    : '<Any identifier_or_keyword except true or false>'
    ;
```

条件编译符号有两个可能的状态：***定义***或***未定义***。 在源文件的词法处理开始时，条件编译符号未定义，除非已由外部机制 （如命令行编译器选项） 显式定义。 当`#define`处理指令，在该指令中指定的条件编译符号成为已在该源文件中定义。 符号一直保持定义到`#undef`指令处理该相同的符号时，或直到到达源文件的末尾。 这是`#define`和`#undef`一个源文件中的指令不会影响在同一程序中的其他源文件。

定义条件编译符号在预处理表达式中引用时, 具有的布尔值`true`，并且未定义的条件编译符号的布尔值`false`。没有任何要求，条件编译符号之前显式声明中预处理表达式引用它们。 相反，未声明的符号只是未定义，并因此具有值`false`。

条件编译符号在命名空间是不同，独立于 C# 程序中的所有其他命名实体。 条件编译符号只能引用在`#define`和`#undef`指令和预处理表达式中。

### 预处理表达式

预处理表达式中可能会发生`#if`和`#elif`指令。 运算符`!`， `==`， `!=`，`&&`和`||`允许在预处理表达式，并且可能会使用括号进行分组。

antlr复制

```antlr
pp_expression
    : whitespace? pp_or_expression whitespace?
    ;

pp_or_expression
    : pp_and_expression
    | pp_or_expression whitespace? '||' whitespace? pp_and_expression
    ;

pp_and_expression
    : pp_equality_expression
    | pp_and_expression whitespace? '&&' whitespace? pp_equality_expression
    ;

pp_equality_expression
    : pp_unary_expression
    | pp_equality_expression whitespace? '==' whitespace? pp_unary_expression
    | pp_equality_expression whitespace? '!=' whitespace? pp_unary_expression
    ;

pp_unary_expression
    : pp_primary_expression
    | '!' whitespace? pp_unary_expression
    ;

pp_primary_expression
    : 'true'
    | 'false'
    | conditional_symbol
    | '(' whitespace? pp_expression whitespace? ')'
    ;
```

定义条件编译符号在预处理表达式中引用时, 具有的布尔值`true`，并且未定义的条件编译符号的布尔值`false`。

始终预处理表达式的计算结果将生成一个布尔值。 预处理表达式的求值的规则是相同的常量表达式 ([常量表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#constant-expressions))，不过，只有用户定义的实体可以引用的是条件编译符号.

### 声明指令

声明指令用于定义或取消定义条件编译符号。

antlr复制

```antlr
pp_declaration
    : whitespace? '#' whitespace? 'define' whitespace conditional_symbol pp_new_line
    | whitespace? '#' whitespace? 'undef' whitespace conditional_symbol pp_new_line
    ;

pp_new_line
    : whitespace? single_line_comment? new_line
    ;
```

在处理`#define`指令会导致给定的条件编译符号成为已定义，跟在指令后面的源代码行开始。 同样，在处理`#undef`指令会导致给定的条件编译符号变成未定义，跟在指令后面的源代码行开始。

任何`#define`并`#undef`指令在源文件中的必须出现在第一个之前*令牌*([令牌](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#tokens)) 在源代码文件中; 否则将编译时出现错误。 直观地讲，在`#define`和`#undef`指令必须位于任何"实际代码"中的源代码文件之前。

下面的示例：

C#复制

```csharp
#define Enterprise

#if Professional || Enterprise
    #define Advanced
#endif

namespace Megacorp.Data
{
    #if Advanced
    class PivotTable {...}
    #endif
}
```

无效，因为`#define`指令前加上第一个标记 (`namespace`关键字) 中的源文件。

下面的示例导致在编译时错误，因为`#define`遵循真实代码：

C#复制

```csharp
#define A
namespace N
{
    #define B
    #if B
    class Class1 {}
    #endif
}
```

一个`#define`可以定义条件编译符号已定义的而无需任何中间那里`#undef`该符号的。 下面的示例中定义的条件编译符号`A`，然后定义它。

C#复制

```csharp
#define A
#define A
```

一个`#undef`可能"取消"未定义的条件编译符号。 下面的示例中定义的条件编译符号`A`，然后取消定义它两次; 尽管第二个`#undef`不起作用，它是否仍然有效。

C#复制

```csharp
#define A
#undef A
#undef A
```

### 条件编译指令

条件编译指令用于有条件地包括或排除的源文件部分。

antlr复制

```antlr
pp_conditional
    : pp_if_section pp_elif_section* pp_else_section? pp_endif
    ;

pp_if_section
    : whitespace? '#' whitespace? 'if' whitespace pp_expression pp_new_line conditional_section?
    ;

pp_elif_section
    : whitespace? '#' whitespace? 'elif' whitespace pp_expression pp_new_line conditional_section?
    ;

pp_else_section:
    | whitespace? '#' whitespace? 'else' pp_new_line conditional_section?
    ;

pp_endif
    : whitespace? '#' whitespace? 'endif' pp_new_line
    ;

conditional_section
    : input_section
    | skipped_section
    ;

skipped_section
    : skipped_section_part+
    ;

skipped_section_part
    : skipped_characters? new_line
    | pp_directive
    ;

skipped_characters
    : whitespace? not_number_sign input_character*
    ;

not_number_sign
    : '<Any input_character except #>'
    ;
```

条件编译指令的语法所示，必须编写为集组成，按顺序`#if`指令，零个或多个`#elif`指令、 零个或一个`#else`指令，和一个`#endif`指令。 这些指令之间是源代码的条件部分。 每个部分由前面紧邻的指令控制。 有条件节本身可能包含嵌套的条件编译指令提供这些指令形成完整集。

一个*pp_conditional*选择最多包含一个*conditional_section*s 表示正常的词法处理：

- *Pp_expression*的 s`#if`并`#elif`指令按顺序进行计算一个生成为止`true`。 如果表达式的结果`true`，则*conditional_section*选择相应的指令。
- 如果所有*pp_expression*s yield `false`，并且如果`#else`存在，则指令*conditional_section*的`#else`指令处于选中状态。
- 否则为为否*conditional_section*处于选中状态。

所选*conditional_section*，如果有的话被处理为普通*input_section*： 词法语法必须遵循的部分中包含的源代码; 从源生成令牌部分; 中的代码预处理指令的部分中具有规定的影响。

剩余*conditional_section*s，如果有，作为处理*skipped_section*s： 除预处理指令外的，部分中的源代码不需要符合词法语法; 否从部分; 中的源代码生成令牌和部分中的预处理指令必须在词法上正确但不是否则处理。 内*conditional_section* ，为其进行处理作为*skipped_section*、 任何嵌套*conditional_section*s (包含在嵌套`#if`...`#endif`和`#region`...`#endregion`构造) 也作为处理*skipped_section*s。

下面的示例演示了如何条件编译指令可以嵌套：

C#复制

```csharp
#define Debug       // Debugging on
#undef Trace        // Tracing off

class PurchaseTransaction
{
    void Commit() {
        #if Debug
            CheckConsistency();
            #if Trace
                WriteToLog(this.ToString());
            #endif
        #endif
        CommitHelper();
    }
}
```

除了预处理指令，跳过的源代码不遵从语法分析。 例如，以下是有效的尽管未终止的注释中`#else`部分：

C#复制

```csharp
#define Debug        // Debugging on

class PurchaseTransaction
{
    void Commit() {
        #if Debug
            CheckConsistency();
        #else
            /* Do something else
        #endif
    }
}
```

但是，请注意，预处理指令所需的源代码的已跳过部分中，甚至在词法上正确。

预处理指令不会处理时出现在多行输入元素的内部。 例如，该计划：

C#复制

```csharp
class Hello
{
    static void Main() {
        System.Console.WriteLine(@"hello, 
#if Debug
        world
#else
        Nebraska
#endif
        ");
    }
}
```

在输出中的结果：

复制

```
hello,
#if Debug
        world
#else
        Nebraska
#endif
```

在特殊情况下，处理的预处理指令集可能依赖于计算*pp_expression*。 下面的示例：

C#复制

```csharp
#if X
    /*
#else
    /* */ class Q { }
#endif
```

始终生成相同的令牌流 (`class` `Q` `{` `}`)，无论是否`X`定义。 如果`X`是定义，仅处理的指令是`#if`和`#endif`，因为多行注释。 如果`X`是未定义，然后三个指令 (`#if`， `#else`， `#endif`) 是指令集的一部分。

### 诊断指令

诊断指令用于显式生成错误和警告消息中一样其他编译时错误和警告报告。

antlr复制

```antlr
pp_diagnostic
    : whitespace? '#' whitespace? 'error' pp_message
    | whitespace? '#' whitespace? 'warning' pp_message
    ;

pp_message
    : new_line
    | whitespace input_character* new_line
    ;
```

下面的示例：

C#复制

```csharp
#warning Code review needed before check-in

#if Debug && Retail
    #error A build can't be both debug and retail
#endif

class Test {...}
```

始终会生成警告 （"代码评审需要在签入前"），并会生成编译时错误 （"生成不能为调试和发布"） 如果条件符号`Debug`和`Retail`进行定义。 请注意， *pp_message*可以包含任意文本; 具体而言，它需要包含格式正确的令牌，如所示在 word 中的单引号`can't`。

### 区域指令

区域指令用于显式标记的源代码区域。

antlr复制

```antlr
pp_region
    : pp_start_region conditional_section? pp_end_region
    ;

pp_start_region
    : whitespace? '#' whitespace? 'region' pp_message
    ;

pp_end_region
    : whitespace? '#' whitespace? 'endregion' pp_message
    ;
```

附加的区域; 没有语义含义区域适用于使用由程序员或通过自动工具将源代码节标记。 在指定的消息`#region`或`#endregion`指令同样的语义含义; 它只是用来识别该区域。 匹配`#region`并`#endregion`指令可能具有不同*pp_message*s。

区域的词法正在处理：

C#复制

```csharp
#region
...
#endregion
```

完全对应窗体的条件编译指令的词法处理：

C#复制

```csharp
#if true
...
#endif
```

### 行指令

行指令可能用于更改的行号和源文件名的编译器中输出，例如警告和错误，报告的和由调用方信息特性 ([调用方信息特性](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/attributes#caller-info-attributes))。

从指定的其他文本输入生成 C# 源代码的元编程工具中最常使用行指令。

antlr复制

```antlr
pp_line
    : whitespace? '#' whitespace? 'line' whitespace line_indicator pp_new_line
    ;

line_indicator
    : decimal_digit+ whitespace file_name
    | decimal_digit+
    | 'default'
    | 'hidden'
    ;

file_name
    : '"' file_name_character+ '"'
    ;

file_name_character
    : '<Any input_character except ">'
    ;
```

如果未`#line`指令是否存在后，编译器会报告真实的行号和源文件名称在其输出中的。 处理时`#line`包含的指令*line_indicator*不`default`，编译器将为具有给定的行号 （和文件名称，如果指定） 执行该指令之后的行。

一个`#line default`指令反转所有上述 #line 指令的效果。 编译器报告后续行的真实行信息就像没有`#line`处理指令一样。

一个`#line hidden`指令不起作用的文件和行号错误地报告消息，但会影响源级别的调试。 在调试时，所有行之间`#line hidden`指令和后续`#line`指令 (这不是`#line hidden`) 有无行号信息。 当逐句通过代码在调试器中，将完全跳过这些行。

请注意， *file_name*不同于常规字符串，不会处理转义符;"`\`"字符只需指定一个普通的反斜杠字符内*file_name*.

### 杂注指令

`#pragma`预处理指令用于指定到编译器的可选上下文信息。 中提供的信息`#pragma`指令将永远不会更改程序语义。

antlr复制

```antlr
pp_pragma
    : whitespace? '#' whitespace? 'pragma' whitespace pragma_body pp_new_line
    ;

pragma_body
    : pragma_warning_body
    ;
```

C# 提供`#pragma`指令来控制编译器警告。 该语言的未来版本可能包括其他`#pragma`指令。 若要确保与其他 C# 编译器互操作性，Microsoft C# 编译器不会发出未知的编译错误`#pragma`指令; 但是生成警告此类指令执行操作。

#### 杂注警告

`#pragma warning`指令用于禁用或还原所有或一组特定的警告消息的后续程序文本编译期间。

antlr复制

```antlr
pragma_warning_body
    : 'warning' whitespace warning_action
    | 'warning' whitespace warning_action whitespace warning_list
    ;

warning_action
    : 'disable'
    | 'restore'
    ;

warning_list
    : decimal_digit+ (whitespace? ',' whitespace? decimal_digit+)*
    ;
```

一个`#pragma warning`忽略该警告列表的指令会影响所有警告。 一个`#pragma warning`指令包含警告列表会影响仅在列表中指定这些警告。

一个`#pragma warning disable`指令禁用所有或给定的警告集。

一个`#pragma warning restore`指令还原所有或将警告记录到有效的编译单元起始处的状态的给定的集。 请注意，如果已从外部禁用特定警告， `#pragma warning restore` (是否为所有或特定警告) 不会重新启用该警告。

下面的示例演示使用`#pragma warning`暂时禁用该警告时，报告已过时成员被引用时，使用来自 Microsoft C# 编译器的警告编号。

C#复制

```csharp
using System;

class Program
{
    [Obsolete]
    static void Foo() {}

    static void Main() {
#pragma warning disable 612
    Foo();
#pragma warning restore 612
    }
}
```