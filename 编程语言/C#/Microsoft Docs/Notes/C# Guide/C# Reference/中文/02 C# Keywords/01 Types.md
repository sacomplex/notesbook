# [Types](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/types)

C# 类型化系统包含以下类别：

- [值类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/value-types)
- [引用类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/reference-types)
- [指针类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/unsafe-code-pointers/pointer-types)

值类型的变量可存储数据，引用类型的变量可存储对实际数据的引用。 引用类型的实例也被称作对象。 仅在[不安全](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/unsafe)模式下才可使用指针类型。

可将值类型转换为引用类型，并通过[装箱和取消装箱](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/types/boxing-and-unboxing)再次转换回值类型。 除已装箱值类型外，不可将引用类型转换为值类型。

本部分还介绍了 [void](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/void)。

## [Value Types](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/value-types)

有两种值类型：

- [结构](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/struct)
- [枚举](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/enum)

### 值类型的主要功能

值类型的变量包含类型的值。 例如，`int` 类型的变量可以包含值 `42`。 它不同于引用类型的变量，后者（也称为对象）包含对类型实例的引用。 将新的值分配到值类型的变量时，会复制该值。 将新的值分配到引用类型的变量时，会复制引用，而不复制对象本身。

所有值类型都隐式派生自 [System.ValueType](https://docs.microsoft.com/zh-cn/dotnet/api/system.valuetype)。

与引用类型不同，不能从值类型派生新类型。 但是，与引用类型一样，结构可以实现接口。

值类型变量不能默认为 `null`。 但相应的[可以为空的类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/nullable-types/index)的变量可以为 `null`。

每个值类型都具有一个初始化该类型的默认值的隐式默认构造函数。 有关值类型的默认值的信息，请参阅[默认值表](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/default-values-table)。

### 简单类型

简单类型是 C# 提供的一组预定义的结构类型，其中包括以下类型：

- [整型类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/integral-types-table)：整数类型和 [字符型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/char)类型
- [浮点类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/floating-point-types-table)
- [bool](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/bool)

简单类型通过关键字标识，但这些关键字只是 [System](https://docs.microsoft.com/zh-cn/dotnet/api/system) 命名空间中的预定义结构类型的别名。 例如， [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int) 是 [System.Int32](https://docs.microsoft.com/zh-cn/dotnet/api/system.int32) 的别名。 有关别名的完整列表，请参阅[内置类型表](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/built-in-types-table)。

简单类型不同于其他结构类型，简单类型允许某些附加操作：

- 可以使用文本初始化简单类型。 例如，`'A'` 是类型 `char` 的文本，`2001` 是类型 `int` 的文本。
- 可以使用 [const](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/const) 关键字声明简单类型的常数。 无法包含其他结构类型的常数。
- 其操作数都是简单类型常数的常量表达式在编译时进行评估。

有关详细信息，请参阅 [C# 语言规范](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/index)中的[简单类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/types#simple-types)部分。

### 初始化值类型

在使用 C# 中的本地变量之前，必须对其进行初始化。 例如，可以声明未初始化的本地变量，如以下示例所示：

C#复制

```csharp
int myInt;
```

在未初始化之前，无法使用。 可以使用以下语句将其初始化：

C#复制

```csharp
myInt = new int();  // Invoke default constructor for int type.
```

此语句等效于以下语句：

C#复制

```csharp
myInt = 0;         // Assign an initial value, 0 in this example.
```

当然，可以在同一语句中进行声明和初始化，如以下示例所示：

C#复制

```csharp
int myInt = new int();
```

\- 或 -

C#复制

```csharp
int myInt = 0;
```

使用 [new](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/new) 运算符将调用特定类型的默认构造函数，并向变量赋予默认值。 在前面的示例中，默认构造函数将值 `0` 赋予了 `myInt`。 有关通过调用默认构造函数所赋予的值的详细信息，请参阅[默认值表](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/default-values-table)。

对于用户定义类型，请使用 [new](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/new) 调用默认构造函数。 例如，以下语句调用 `Point` 结构的默认构造函数：

C#复制

```csharp
Point p = new Point(); // Invoke default constructor for the struct.
```

进行此调用后，该结构被视为已明确赋值；即，它的所有成员都被初始化为其默认值。

有关 `new` 运算符的详细信息，请参阅 [new](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/new)。

有关设置数值类型的输出格式的信息，请参阅[设置数值结果表的格式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/formatting-numeric-results-table)。

### [bool](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/bool)

`bool` 关键字是 [System.Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) 的别名。 它用于声明变量来存储布尔值：[true](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/true-literal) 和 [false](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/false-literal)。

> 如果需要一个也可以有 `null` 值的布尔型变量，请使用 `bool?`。 有关详细信息，请参阅[使用可以为空的类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/nullable-types/using-nullable-types)一文的 [bool? 类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/nullable-types/using-nullable-types#the-bool-type)部分。

#### 文本

可将布尔值赋给 `bool` 变量。 也可以将计算结果为 `bool` 类型的表达式赋给 `bool` 变量。

```csharp
public class BoolTest
{
    static void Main()
    {
        bool b = true;

        // WriteLine automatically converts the value of b to text.
        Console.WriteLine(b);

        int days = DateTime.Now.DayOfYear;


        // Assign the result of a boolean expression to b.
        b = (days % 2 == 0);

        // Branch depending on whether b is true or false.
        if (b)
        {
            Console.WriteLine("days is an even number");
        }
        else
        {
            Console.WriteLine("days is an odd number");
        }   
    }
}
/* Output:
  True
  days is an <even/odd> number
*/
```

`bool` 变量的默认值为 `false`。 `bool?` 变量的默认值为 `null`。

#### 转换

在 C++ 中，`bool` 类型的值可转换为 `int` 类型的值；也就是说，`false` 等效于零值，而 `true` 等效于非零值。 在 C# 中，不存在 `bool` 类型与其他类型之间的相互转换。 例如，下面的 `if` 语句在 C# 中无效：

```csharp
int x = 123;

// if (x)   // Error: "Cannot implicitly convert type 'int' to 'bool'"
{
    Console.Write("The value of x is nonzero.");
}
```

若要测试 `int` 类型的变量，必须将该变量与一个值（例如零）进行显式比较，如下所示：

```csharp
if (x != 0)   // The C# way
{
    Console.Write("The value of x is nonzero.");
}
```

#### 示例

在此例中，你通过键盘输入一个字符，然后程序检查输入的字符是否是一个字母。 如果字符是一个字母，则程序检查它是大写还是小写。 执行这些检查使用的是 [IsLetter](https://docs.microsoft.com/zh-cn/dotnet/api/system.char.isletter) 和 [IsLower](https://docs.microsoft.com/zh-cn/dotnet/api/system.char.islower)，二者均返回 `bool` 类型：

```csharp
public class BoolKeyTest
{
    static void Main()
    {
        Console.Write("Enter a character: ");
        char c = (char)Console.Read();
        if (Char.IsLetter(c))
        {
            if (Char.IsLower(c))
            {
                Console.WriteLine("The character is lowercase.");
            }
            else
            {
                Console.WriteLine("The character is uppercase.");
            }
        }
        else
        {
            Console.WriteLine("Not an alphabetic character.");
        }
    }
}
/* Sample Output:
    Enter a character: X
    The character is uppercase.
 
    Enter a character: x
    The character is lowercase.

    Enter a character: 2
    The character is not an alphabetic character.
 */
```

### [byte](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/byte)

`byte` 表示存储下表所示值的整型类型。

| 类型   | 范围     | 大小              | .NET 类型                                                    |
| ------ | -------- | ----------------- | ------------------------------------------------------------ |
| `byte` | 0 到 255 | 无符号的 8 位整数 | [System.Byte](https://docs.microsoft.com/zh-cn/dotnet/api/system.byte) |

#### 文本

可以通过为其分配十进制文本、十六进制文本或（从 C# 7.0 开始）二进制文本来声明和初始化 `byte` 变量。 如果整数文本在 `byte` 范围之外（即，如果它小于 [Byte.MinValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.byte.minvalue) 或大于 [Byte.MaxValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.byte.maxvalue)），会发生编译错误。

在以下示例中，等于 201、表示为十进制、十六进制和二进制文本的整数从 [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int) 隐式转换为 `byte` 值。

C#复制

```csharp
byte byteValue1 = 201;
Console.WriteLine(byteValue1);

byte byteValue2 = 0x00C9;
Console.WriteLine(byteValue2);

byte byteValue3 = 0b1100_1001;
Console.WriteLine(byteValue3);
// The example displays the following output:
//          201
//          201
//          201
```

 备注

使用前缀 `0x` 或 `0X` 表示十六进制文本，使用前缀 `0b` 或 `0B` 表示二进制文本。 十进制文本没有前缀。

从 C# 7.0 开始，添加了一些功能以增强可读性。

- C# 7.0 允许将下划线字符 (`_`) 用作数字分隔符。
- C# 7.2 允许将 `_` 用作二进制或十六进制文本的数字分隔符，位于前缀之后。 十进制文本不能够有前导下划线。

下面是一些示例。

C#复制

```csharp
byte byteValue4 = 0b1100_1001;
Console.WriteLine(byteValue4);

byte byteValue5 = 0b_1100_1001;
Console.WriteLine(byteValue5);       // C# 7.2 onwards
// The example displays the following output:
//          201
//          201
```

#### 转换

存在从 `byte` 到 [short](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/short)、[ushort](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ushort)、[int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int)、[uint](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/uint)、[long](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/long)、[ulong](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ulong)、[float](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/float)、[double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double) 或 [decimal](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/decimal) 的预定义隐式转换。

不可将大存储大小的非文本数字类型隐式转换为 `byte`。 有关整型类型存储大小的详细信息，请参阅[整型类型表](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/integral-types-table)。 以下面两个 `byte` 变量 `x` 和 `y` 为例：

C#复制

```csharp
byte x = 10, y = 20;  
```

以下赋值语句将产生一个编译器错误，原因是赋值运算符右侧的算术表达式在默认情况下的计算结果为 `int` 类型。

C#复制

```csharp
// Error: conversion from int to byte:  
byte z = x + y;  
```

若要解决此问题，请使用强制转换：

C#复制

```csharp
// OK: explicit conversion:  
byte z = (byte)(x + y);  
```

但是，在目标变量具有相同或更大的存储大小时，也可以使用下列语句：

C#复制

```csharp
int x = 10, y = 20;  
int m = x + y;  
long n = x + y;  
```

此外，不存在从浮点类型到 `byte` 类型的隐式转换。 例如，除非使用显式强制转换，否则以下语句将生成编译器错误：

C#复制

```csharp
// Error: no implicit conversion from double:  
byte x = 3.0;   
// OK: explicit conversion:  
byte y = (byte)3.0;  
```

在调用重载方法时，必须使用转换。 以下面使用 `byte` 和 [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int) 参数的重载方法为例：

C#复制

```csharp
public static void SampleMethod(int i) {}  
public static void SampleMethod(byte b) {}  
```

使用 `byte` 强制转换可保证调用正确的类型，例如：

C#复制

```csharp
// Calling the method with the int parameter:  
SampleMethod(5);  
// Calling the method with the byte parameter:  
SampleMethod((byte)5);  
```

有关兼用浮点类型和整型类型的算术表达式的信息，请参阅 [float](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/float) 和 [double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double)。

有关隐式数值转换规则的详细信息，请参阅[隐式数值转换表](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/implicit-numeric-conversions-table)。

### [char](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/char)

`char` 关键字用于声明 [System.Char](https://docs.microsoft.com/zh-cn/dotnet/api/system.char) 结构的实例，.NET Framework 使用该结构来表示 Unicode 字符。 `Char` 对象的值为 16 位的数字（序号）值。

Unicode 字符用于表示世界各地大多数的书面语言。

| 类型   | 范围             | 大小              | .NET 类型                                                    |
| ------ | ---------------- | ----------------- | ------------------------------------------------------------ |
| `char` | U+0000 到 U+FFFF | Unicode 16 位字符 | [System.Char](https://docs.microsoft.com/zh-cn/dotnet/api/system.char) |

#### 文本

`char` 类型的常量可以编写为字符文本、十六进制转义序列或 Unicode 表示形式。 还可转换整型字符代码。 在下面的示例中，使用相同的字符 `X` 对四个 `char` 变量进行初始化：

```csharp
char[] chars = new char[4];

chars[0] = 'X';        // Character literal
chars[1] = '\x0058';   // Hexadecimal
chars[2] = (char)88;   // Cast from integral type
chars[3] = '\u0058';   // Unicode

foreach (char c in chars)
{
    Console.Write(c + " ");
}
// Output: X X X X
```

#### 转换

`char` 可隐式转换为 [ushort](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ushort)、[int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int)、[uint](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/uint)、[long](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/long)、[ulong](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ulong)、[float](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/float)、[double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double) 或 [decimal](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/decimal)。 但是无法将其他类型隐式转换为 `char` 类型。

[System.Char](https://docs.microsoft.com/zh-cn/dotnet/api/system.char) 类型提供多种适用于 `char` 值的静态方法。

### [decimal](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/decimal)

`decimal` 关键字指示 128 位数据类型。 与其他浮点型相比，`decimal` 类型具有更高的精度和更小的范围，这使它适合于财务和货币计算。 `decimal` 类型的大致范围和精度如下表所示。

| 类型      | 大致范围                       | 精度           | .NET 类型                                                    |
| --------- | ------------------------------ | -------------- | ------------------------------------------------------------ |
| `decimal` | ±1.0 x 10-28 至 ±7.9228 x 1028 | 28-29 个有效位 | [System.Decimal](https://docs.microsoft.com/zh-cn/dotnet/api/system.decimal) |

`decimal` 的默认值为 0m。

#### 文本

如果希望实数被视为 `decimal` 类型，请使用后缀 m 或 M，例如：

C#复制

```csharp
decimal myMoney = 300.5m;
```

如果没有后缀 m，则数字将被视为 [double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double) 类型并会生成编译器错误。

#### 转换

整型将被隐式转换为 `decimal` 类型，其计算结果为 `decimal`。 因此，你可以用整数字面量初始化 decimal 变量而不使用后缀，如下所示：

C#复制

```csharp
decimal myMoney = 300;
```

其他浮点类型和 `decimal` 类型之间不存在隐式转换；因此，必须使用强制转换来转换这两个类型。 例如:

C#复制

```csharp
decimal myMoney = 99.9m;
double x = (double)myMoney;
myMoney = (decimal)x;
```

你还可以在同一表达式中混合使用 `decimal` 和数值整型。 但是，不进行强制转换就混合使用 `decimal` 和其他浮点型将导致编译错误。

有关隐式数值转换的详细信息，请参阅[隐式数值转换表](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/implicit-numeric-conversions-table)。

有关显式数值转换的详细信息，请参阅[显式数值转换表](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/explicit-numeric-conversions-table)。

#### 设置十进制输出的格式

你可以通过使用 `String.Format` 方法或 [Console.Write](https://docs.microsoft.com/zh-cn/dotnet/api/system.console.write) 方法（其调用 `String.Format()`）来设置结果的格式。 货币格式是使用标准货币格式字符串“C”或“c”指定的，如本文后面的第二个示例所示。 有关 `String.Format` 方法的更多信息，请参见 [String.Format](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.format)。

#### 示例

下面的示例尝试添加 [double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double) 和 `decimal` 变量，这会导致编译器错误。

C#复制

```csharp
decimal dec = 0m;
double dub = 9;
// The following line causes an error that reads "Operator '+' cannot be applied to
// operands of type 'double' and 'decimal'"
Console.WriteLine(dec + dub);

// You can fix the error by using explicit casting of either operand.
Console.WriteLine(dec + (decimal)dub);
Console.WriteLine((double)dec + dub);
```

其结果为以下错误：

```
Operator '+' cannot be applied to operands of type 'double' and 'decimal'
```

在此示例中，同一个表达式中混合使用了 `decimal` 和 [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int)。 计算结果为 `decimal` 类型。

C#复制

```csharp
public class TestDecimal
{
    static void Main()
    {
        decimal d = 9.1m;
        int y = 3;
        Console.WriteLine(d + y);   // Result converted to decimal
    }
}
// Output: 12.1
```

#### 示例

在此示例中，通过使用货币格式字符串来设置输出的格式。 请注意，`x` 被舍入，因为其小数位数超出了 $0.99。 表示最大精确位数的变量 `y` 严格按照正确的格式显示。

C#复制

```csharp
public class TestDecimalFormat
{
    static void Main()
    {
        decimal x = 0.999m;
        decimal y = 9999999999999999999999999999m;
        Console.WriteLine("My amount = {0:C}", x);
        Console.WriteLine("Your amount = {0:C}", y);
    }
}
/* Output:
    My amount = $1.00
    Your amount = $9,999,999,999,999,999,999,999,999,999.00
*/
```

### [double](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/double)

`double` 关键字表示存储 64 位浮点值的简单类型。 下表显示了 `double` 类型的精度和大致范围。

| 类型     | 大致范围                      | 精度              | .NET 类型                                                    |
| -------- | ----------------------------- | ----------------- | ------------------------------------------------------------ |
| `double` | ±5.0 × 10−324 到 ±1.7 × 10308 | 大约 15-17 位数字 | [System.Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double) |

#### 文本

默认情况下，赋值运算符右侧的实数被视为 `double`。 但是，如果希望整数被视为 `double`，可使用后缀 d 或 D，例如：

C#复制

```csharp
double x = 3D;
```

#### 转换

可以在表达式中混合使用数值整型和浮点类型。 在这种情况下，整数类型将转换为浮点类型。 根据以下规则对表达式求值：

- 如果其中一个浮点类型是 `double`，该表达式在关系比较和相等比较中求值类型为 `double` 或 [bool](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/bool)。
- 如果表达式中没有 `double` 类型，则表达式在关系比较和相等比较中求值类型为[float](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/float) 或 [bool](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/bool)。

浮点表达式可以包含下列值集：

- 正零和负零。
- 正无穷大和负无穷大。
- 非数字值 (NaN)。
- 一组有限的非零值。

有关这些值的详细信息，请参阅 [IEEE](https://www.ieee.org/) 网站中提供的二进制浮点算术的 IEEE 标准。

#### 示例

在下面的示例中，将 [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int)、[short](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/short)、[float](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/float) 和 `double` 相加可得出 `double` 结果。

C#复制

```csharp
// Mixing types in expressions
class MixedTypes
{
    static void Main()
    {
        int x = 3;
        float y = 4.5f;
        short z = 5;
        double w = 1.7E+3;
        // Result of the 2nd argument is a double:
        Console.WriteLine("The sum is {0}", x + y + z + w);
    }
}
// Output: The sum is 1712.5
```

### [enum](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/enum)

`enum` 关键字用于声明枚举，一种包含一组被称为枚举数列表的已命名常数的不同类型。

通常最好是直接在命名空间内定义枚举，以便命名空间中的所有类都可以同样方便地访问它。 但是，也可能会在类或结构中嵌套枚举。

默认情况下，第一个枚举数具有值 0，并且每个连续枚举数的值将增加 1。 例如，在以下枚举中， `Sat` 的值为 `0`， `Sun` 的值为 `1`， `Mon` 的值为 `2`，依次类推。

C#复制

```csharp
enum Day {Sat, Sun, Mon, Tue, Wed, Thu, Fri};
```

枚举数可以使用初始值设定项来替代默认值，如下面的示例中所示。

C#复制

```csharp
enum Day {Sat=1, Sun, Mon, Tue, Wed, Thu, Fri};
```

在此枚举中，强制元素的序列从 `1` 开始，而不是 `0`。 但建议包括一个值为 0 的常量。 有关详细信息，请参阅[枚举类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/enumeration-types)。

每个枚举类型都有一个基础类型，该基础类型可以是除 [char](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/char) 外的任何整型类型。 枚举元素的默认基础类型是 [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int)。若要声明另一整型的枚举（如 [byte](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/byte)），则请在后跟该类型的标识符后使用冒号，如以下示例所示。

C#复制

```csharp
enum Day : byte {Sat=1, Sun, Mon, Tue, Wed, Thu, Fri};
```

已批准的枚举类型有 [byte](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/byte)、[sbyte](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/sbyte)、[short](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/short)、[ushort](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ushort)、[int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int)、[uint](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/uint), [long](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/long) 或 [ulong](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ulong)。

枚举类型的变量可在基本类型范围内分配到任何值；这些值不限于已命名常数。

`enum E` 的默认值是由表达式 `(E)0`生成的值。

> 枚举数名称中不能含有空格。

基础类型指定为每个枚举数分配多少存储空间。 但要将 `enum` 类型转换为整型，则必须使用显示转换。 例如，以下语句通过使用转换将 `Sun` 转换为 [，从而将枚举数](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int) 赋值为 `enum` int `int`类型的变量。

C#复制

```csharp
int x = (int)Day.Sun;
```

当你将 [System.FlagsAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.flagsattribute) 应用到包含可与按位 `OR` 运算组合的元素的枚举中时，该特性与某些工具一起使用时会影响 `enum` 的行为。 当你使用工具（如 [Console](https://docs.microsoft.com/zh-cn/dotnet/api/system.console) 类方法和表达式计算器）时，你可以注意到这些更改。（请参阅第三个示例。）

#### 可靠编程

正如任何常量一样，对枚举的各项值的所有引用在编译时都会转换为数字参数。 这可能会造成如[常量](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/constants)中所述的潜在版本问题。

将其他值分配到枚举的新版本，或者在新版本中更改枚举成员的值，会导致出现相关源代码问题。 通常在 [switch](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/switch)语句中使用枚举值。 如果已将其他元素添加到 `enum` 类型，则 switch 语句的默认部分可被意外地选中。

如果其他开发人员使用你的代码，则在将新元素添加到任何 `enum` 类型时应提供有关他们的代码应该如何响应的准则。

#### 示例

在下面的示例中，已声明枚举 `Day`。 已将两个枚举数显式转换为整数，并赋值为整数变量。

C#复制

```csharp
public class EnumTest
{
    enum Day { Sun, Mon, Tue, Wed, Thu, Fri, Sat };

    static void Main()
    {
        int x = (int)Day.Sun;
        int y = (int)Day.Fri;
        Console.WriteLine("Sun = {0}", x);
        Console.WriteLine("Fri = {0}", y);
    }
}
/* Output:
   Sun = 0
   Fri = 5
*/
```

#### 示例

以下示例中，使用基类型选项来声明其成员是 `enum` 类型的 `long`。 请注意，即使该枚举的基础类型是 `long`，仍然需通过使用转换将枚举成员显式转换为类型 `long` 。

C#复制

```csharp
public class EnumTest2
{
    enum Range : long { Max = 2147483648L, Min = 255L };
    static void Main()
    {
        long x = (long)Range.Max;
        long y = (long)Range.Min;
        Console.WriteLine("Max = {0}", x);
        Console.WriteLine("Min = {0}", y);
    }
}
/* Output:
   Max = 2147483648
   Min = 255
*/
```

#### 示例

下面的代码示例说明了 [System.FlagsAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.flagsattribute) 声明中 `enum` 特性的使用和作用。

C#复制

```csharp
// Add the attribute Flags or FlagsAttribute.
[Flags]
public enum CarOptions
{
    // The flag for SunRoof is 0001.
    SunRoof = 0x01,
    // The flag for Spoiler is 0010.
    Spoiler = 0x02,
    // The flag for FogLights is 0100.
    FogLights = 0x04,
    // The flag for TintedWindows is 1000.
    TintedWindows = 0x08,
}

class FlagTest
{
    static void Main()
    {
        // The bitwise OR of 0001 and 0100 is 0101.
        CarOptions options = CarOptions.SunRoof | CarOptions.FogLights;

        // Because the Flags attribute is specified, Console.WriteLine displays
        // the name of each enum element that corresponds to a flag that has
        // the value 1 in variable options.
        Console.WriteLine(options);
        // The integer value of 0101 is 5.
        Console.WriteLine((int)options);
    }
}
/* Output:
   SunRoof, FogLights
   5
*/
```

#### 注释

如果删除 `Flags`，则示例将显示以下值：

```
5
5
```

### [float](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/float)

`float` 关键字表示存储 32 位浮点值的简单类型。 下表显示了 `float` 类型的精度和大致范围。

| 类型    | 大致范围                    | 精度            | .NET 类型                                                    |
| ------- | --------------------------- | --------------- | ------------------------------------------------------------ |
| `float` | ±1.5 x 10−45 至 ±3.4 x 1038 | 大约 6-9 位数字 | [System.Single](https://docs.microsoft.com/zh-cn/dotnet/api/system.single) |

#### 文本

默认情况下，赋值运算符右侧的实数被视为 [double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double)。 因此，若要初始化浮点型变量，请使用后缀 `f` 或 `F`，如以下示例中所示：

C#复制

```csharp
float x = 3.5F;
```

如果不在前面的声明中使用后缀，则会收到编译错误，因为你正尝试将 [double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double) 值存储到 `float` 变量。

#### 转换

可以在表达式中混合使用数值整型和浮点类型。 在这种情况下，整数类型将转换为浮点类型。 根据以下规则对表达式求值：

- 如果其中一个浮点类型是 [double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double)，该表达式在关系比较或相等比较中求值类型为 [double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double) 或 [bool](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/bool)。
- 如果表达式中没有 [double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double) 类型，则表达式在关系比较或相等比较中求值类型为 `float` 或 [bool](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/bool)。

浮点表达式可以包含下列值集：

- 正和负零
- 正和负无穷大
- 非数字值 (NaN)
- 一组有限的非零值

有关这些值的详细信息，请参阅 [IEEE](https://www.ieee.org/) 网站中提供的二进制浮点算术的 IEEE 标准。

#### 示例

在下面的示例中，提供 `float` 结果的数学表达式中包含 [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int)、[short](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/short) 和 `float`。 （请记住，`float` 是 [System.Single](https://docs.microsoft.com/zh-cn/dotnet/api/system.single) 类型的别名。）请注意，表达式中没有任何 [double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double)。

C#复制

```csharp
class FloatTest 
{
    static void Main() 
    {
        int x = 3;
        float y = 4.5f;
        short z = 5;
        var result = x * y / z;
        Console.WriteLine("The result is {0}", result);
        Type type = result.GetType();
        Console.WriteLine("result is of type {0}", type.ToString());
    }
}
/* Output: 
  The result is 2.7
  result is of type System.Single //'float' is alias for 'Single'
 */
```

### [int](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/int)

`int` 表示一种整型类型，该类型根据下表显示的大小和范围存储值。

| 类型  | 范围                            | 大小               | .NET 类型                                                    |
| ----- | ------------------------------- | ------------------ | ------------------------------------------------------------ |
| `int` | -2,147,483,648 到 2,147,483,647 | 带符号的 32 位整数 | [System.Int32](https://docs.microsoft.com/zh-cn/dotnet/api/system.int32) |

#### 文本

可以通过为其分配十进制文本、十六进制文本或（从 C# 7.0 开始）二进制文本来声明和初始化 `int` 变量。 如果整数文本在 `int` 范围之外（即，如果它小于 [Int32.MinValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.int32.minvalue) 或大于 [Int32.MaxValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.int32.maxvalue)），会发生编译错误。

在以下示例中，表示为十进制、十六进制和二进制文本且等于 90,946 的整数被分配给 `int` 值。

C#复制

```csharp
int intValue1 = 90946;
Console.WriteLine(intValue1);
int intValue2 = 0x16342;
Console.WriteLine(intValue2);

int intValue3 = 0b0001_0110_0011_0100_0010;
Console.WriteLine(intValue3);
// The example displays the following output:
//          90946
//          90946
//          90946
```

 备注

使用前缀 `0x` 或 `0X` 表示十六进制文本，使用前缀 `0b` 或 `0B` 表示二进制文本。 十进制文本没有前缀。

从 C# 7.0 开始，添加了一些功能以增强可读性。

- C# 7.0 允许将下划线字符 (`_`) 用作数字分隔符。
- C# 7.2 允许将 `_` 用作二进制或十六进制文本的数字分隔符，位于前缀之后。 十进制文本不能够有前导下划线。

下面是一些示例。

C#复制

```csharp
int intValue1 = 90_946;
Console.WriteLine(intValue1);

int intValue2 = 0x0001_6342;
Console.WriteLine(intValue2);

int intValue3 = 0b0001_0110_0011_0100_0010;
Console.WriteLine(intValue3);

int intValue4 = 0x_0001_6342;       // C# 7.2 onwards
Console.WriteLine(intValue4);

int intValue5 = 0b_0001_0110_0011_0100_0010;       // C# 7.2 onwards
Console.WriteLine(intValue5);
// The example displays the following output:
//          90946
//          90946
//          90946
//          90946
//          90946
```

整数文本还可以包括一个表示类型的后缀，尽管没有表示 `int` 类型的后缀。 如果整数文本没有后缀，则其类型为以下类型中可表示其值的第一个类型：

1. `int`
2. [uint](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/uint)
3. [long](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/long)
4. [ulong](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ulong)

在这些示例中，文本 90946 属于类型 `int`。

#### 转换

存在从 `int` 到 [long](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/long)、[float](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/float)、[double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double) 或 [decimal](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/decimal) 的预定义隐式转换。 例如:

C#复制

```csharp
// '123' is an int, so an implicit conversion takes place here:  
float f = 123;  
```

存在从 [sbyte](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/sbyte)、[byte](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/byte)、[short](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/short)、[ushort](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ushort) 或 [char](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/char) 到 `int` 的预定义隐式转换。 例如，如果不使用转换，以下赋值语句会生成编译错误：

C#复制

```csharp
long aLong = 22;  
int i1 = aLong;       // Error: no implicit conversion from long.  
int i2 = (int)aLong;  // OK: explicit conversion.  
```

另请注意，不存在从浮点类型到 `int` 类型的隐式转换。 例如，除非使用显式强制转换，否则以下语句将生成编译器错误：

C#复制

```csharp
int x = 3.0;         // Error: no implicit conversion from double.  
int y = (int)3.0;    // OK: explicit conversion.  
```

有关兼用浮点类型和整型类型的算术表达式的详细信息，请参阅 [float](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/float) 和 [double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double)。

### [long](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/long)

`long` 表示一种整型类型，该类型根据下表显示的大小和范围存储值。

| 类型   | 范围                                                    | 大小            | .NET 类型                                                    |
| ------ | ------------------------------------------------------- | --------------- | ------------------------------------------------------------ |
| `long` | -9,223,372,036,854,775,808 到 9,223,372,036,854,775,807 | 64 位带符号整数 | [System.Int64](https://docs.microsoft.com/zh-cn/dotnet/api/system.int64) |

#### 文本

可以通过为其分配十进制文本、十六进制文本或（从 C# 7.0 开始）二进制文本来声明和初始化 `long` 变量。

在以下示例中，表示为十进制、十六进制和二进制文本的等于 4,294,967,296 的整数被分配给 `long` 值。

C#复制

```csharp
long longValue1 = 4294967296;
Console.WriteLine(longValue1);

long longValue2 = 0x100000000;
Console.WriteLine(longValue2);

long longValue3 = 0b1_0000_0000_0000_0000_0000_0000_0000_0000;
Console.WriteLine(longValue3);
// The example displays the following output:
//          4294967296
//          4294967296
//          4294967296
```

 备注

使用前缀 `0x` 或 `0X` 表示十六进制文本，使用前缀 `0b` 或 `0B` 表示二进制文本。 十进制文本没有前缀。

从 C# 7.0 开始，添加了一些功能以增强可读性。

- C# 7.0 允许将下划线字符 (`_`) 用作数字分隔符。
- C# 7.2 允许将 `_` 用作二进制或十六进制文本的数字分隔符，位于前缀之后。 十进制文本不能够有前导下划线。

下面是一些示例。

C#复制

```csharp
long longValue1 = 4_294_967_296;
Console.WriteLine(longValue1);

long longValue2 = 0x1_0000_0000;
Console.WriteLine(longValue2);

long longValue3 = 0b1_0000_0000_0000_0000_0000_0000_0000_0000;
Console.WriteLine(longValue3);

long longValue4 = 0x_1_0000_0000;       // C# 7.2 onwards
Console.WriteLine(longValue4);

long longValue5 = 0b_1_0000_0000_0000_0000_0000_0000_0000_0000;       // C# 7.2 onwards
Console.WriteLine(longValue5);
// The example displays the following output:
//          4294967296
//          4294967296
//          4294967296
//          4294967296
//          4294967296
```

整数文本还可包含表示类型的后缀。 后缀 `L` 表示 `long`。 以下示例使用 `L` 后缀来表示长整型：

C#复制

```csharp
long value = 4294967296L;  
```

 备注

也可用小写字母“l”作后缀。 但是，字母“l”容易与数字“1”混淆，因此会生成编译器警告。 为清楚起见，请使用“L”。

使用后缀 `L` 时，将根据整数的大小确定它的类型是 `long` 还是 [ulong](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ulong)。 在此例中，它是 `long`，因为它小于 [ulong](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ulong) 的范围的下限。

此后缀常用于调用重载方法。 例如，以下重载方法具有 `long` 和 [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int) 类型的参数：

C#复制

```csharp
public static void SampleMethod(int i) {}  
public static void SampleMethod(long l) {}  
```

`L` 后缀可确保调用正确的重载：

C#复制

```csharp
SampleMethod(5);    // Calls the method with the int parameter  
SampleMethod(5L);   // Calls the method with the long parameter  
```

如果整数文本没有后缀，则其类型为以下类型中可表示其值的第一个类型：

1. [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int)
2. [uint](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/uint)
3. `long`
4. [ulong](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ulong)

上例中的文本 4294967296 是 `long` 类型，因为它超出了 [uint](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/uint) 的范围（有关整型类型的存储大小，请参阅[整型类型表](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/integral-types-table)）。

如果在同一个表达式中同时使用 `long` 类型和其他整型类型，表达式的计算结果为 `long`（在关系表达式或布尔表达式中为 [bool](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/bool)）类型。 例如，下列表达式计算为 `long`：

C#复制

```csharp
898L + 88  
```

有关兼用浮点类型和整型类型的算术表达式的信息，请参阅 [float](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/float) 和 [double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double)。

#### 转换

存在从 `long` 到 [float](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/float)、[double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double) 或 [decimal](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/decimal) 的预定义隐式转换。 其他情况下必须使用强制转换。 例如，如果不使用显式强制转换，以下语句会生成编译错误：

C#复制

```csharp
int x = 8L;        // Error: no implicit conversion from long to int  
int y = (int)8L;   // OK: explicit conversion to int  
```

存在从 [sbyte](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/sbyte)、[byte](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/byte)、[short](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/short)、[ushort](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ushort)、[int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int)、[uint](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/uint) 或 [char](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/char) 到 `long` 的预定义隐式转换。

另请注意，不存在从浮点类型到 `long` 类型的隐式转换。 例如，除非使用显式强制转换，否则以下语句将生成编译器错误：

C#复制

```csharp
long x = 3.0;         // Error: no implicit conversion from double  
long y = (long)3.0;   // OK: explicit conversion  
```

### [sbyte](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/sbyte)

`sbyte` 表示一种整型类型，该类型根据下表显示的大小和范围存储值。

| 类型    | 范围        | 大小           | .NET 类型                                                    |
| ------- | ----------- | -------------- | ------------------------------------------------------------ |
| `sbyte` | -128 到 127 | 8 位带符号整数 | [System.SByte](https://docs.microsoft.com/zh-cn/dotnet/api/system.sbyte) |

#### 文本

可以通过为其分配十进制文本、十六进制文本或（从 C# 7.0 开始）二进制文本来声明和初始化 `sbyte` 变量。

在以下示例中，等于 -102、表示为十进制、十六进制和二进制文本的整数从 [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int) 转换为 `sbyte` 值。

C#复制

```csharp
sbyte sbyteValue1 = -102;
Console.WriteLine(sbyteValue1);

unchecked {
   sbyte sbyteValue2 = (sbyte)0x9A;
   Console.WriteLine(sbyteValue2);

   sbyte sbyteValue3 = (sbyte)0b1001_1010;
   Console.WriteLine(sbyteValue3);
}
// The example displays the following output:
//          -102
//          -102
//          -102
```

 备注

使用前缀 `0x` 或 `0X` 表示十六进制文本，使用前缀 `0b` 或 `0B` 表示二进制文本。 十进制文本没有前缀。

从 C# 7.0 开始，添加了一些功能以增强可读性。

- C# 7.0 允许将下划线字符 (`_`) 用作数字分隔符。
- C# 7.2 允许将 `_` 用作二进制或十六进制文本的数字分隔符，位于前缀之后。 十进制文本不能够有前导下划线。

下面是一些示例。

C#复制

```csharp
unchecked {
   sbyte sbyteValue4 = (sbyte)0b1001_1010;
   Console.WriteLine(sbyteValue4);

   sbyte sbyteValue5 = (sbyte)0b_1001_1010;       // C# 7.2 onwards
   Console.WriteLine(sbyteValue5);
}
// The example displays the following output:
//          -102
//          -102
```

如果整数文本在 `sbyte` 范围之外（即，如果它小于 [SByte.MinValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.sbyte.minvalue) 或大于 [SByte.MaxValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.sbyte.maxvalue)），会发生编译错误。 如果整数文本没有后缀，则其类型为以下类型中可表示其值的第一个类型：[int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int)、[uint](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/uint)、[long](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/long)、[ulong](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ulong)。 这意味着，在此示例中，数字文本 `0x9A` 和 `0b10011010` 被解释为值为 156 的 32 位带符号整数，该值超过了 [SByte.MaxValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.sbyte.maxvalue)。 因此，需要使用强制转换运算符，并且赋值必须在[取消选中](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/unchecked)的上下文中发生。

#### 编译器重载解析

调用重载方法时必须使用强制转换。 以下面使用 `sbyte` 和 [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int) 参数的重载方法为例：

C#复制

```csharp
public static void SampleMethod(int i) {}  
public static void SampleMethod(sbyte b) {}  
```

使用 `sbyte` 强制转换可保证调用正确的类型，例如：

C#复制

```csharp
// Calling the method with the int parameter:  
SampleMethod(5);  
// Calling the method with the sbyte parameter:  
SampleMethod((sbyte)5);  
```

#### 转换

存在从 `sbyte` 到 [short](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/short)、[int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int)、[long](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/long)、[float](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/float)、[double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double) 或 [decimal](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/decimal) 的预定义隐式转换。

不能将存储大小更大的非文本数值类型隐式转换为 `sbyte` 类型（有关整型类型的存储大小的信息，请参阅[整型类型表](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/integral-types-table)）。 以下面两个 `sbyte` 变量 `x` 和 `y` 为例：

C#复制

```csharp
sbyte x = 10, y = 20;  
```

以下赋值语句会生成一个编译错误，原因是赋值运算符右侧的算术表达式在默认情况下的计算结果为 [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int)。

C#复制

```csharp
sbyte z = x + y;   // Error: conversion from int to sbyte  
```

若要更正此问题，请对该表达式执行强制转换，如以下示例所示：

C#复制

```csharp
sbyte z = (sbyte)(x + y);   // OK: explicit conversion  
```

但是，在目标变量具有相同或更大的存储大小时，可以使用下列语句：

C#复制

```csharp
sbyte x = 10, y = 20;  
int m = x + y;  
long n = x + y;  
```

另请注意，不存在从浮点类型到 `sbyte` 类型的隐式转换。 例如，除非使用显式强制转换，否则以下语句将生成编译器错误：

C#复制

```csharp
sbyte x = 3.0;         // Error: no implicit conversion from double  
sbyte y = (sbyte)3.0;  // OK: explicit conversion  
```

有关兼用浮点类型和整型类型的算术表达式的信息，请参阅 [float](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/float) 和 [double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double)。

有关隐式数值转换规则的详细信息，请参阅[隐式数值转换表](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/implicit-numeric-conversions-table)。

### [short](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/short)

`short` 表示一种整数数据类型，该类型根据下表显示的大小和范围存储值。

| 类型    | 范围              | 大小             | .NET 类型                                                    |
| ------- | ----------------- | ---------------- | ------------------------------------------------------------ |
| `short` | -32,768 到 32,767 | 有符号 16 位整数 | [System.Int16](https://docs.microsoft.com/zh-cn/dotnet/api/system.int16) |

#### 文本

可以通过为其分配十进制文本、十六进制文本或（从 C# 7.0 开始）二进制文本来声明和初始化 `short` 变量。 如果整数文本在 `short` 范围之外（即，如果它小于 [Int16.MinValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.int16.minvalue) 或大于 [Int16.MaxValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.int16.maxvalue)），会发生编译错误。

在以下示例中，等于 1,034、表示为十进制、十六进制和二进制文本的整数从 [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int) 隐式转换为 `short` 值。

C#复制

```csharp
short shortValue1 = 1034;
Console.WriteLine(shortValue1);

short shortValue2 = 0x040A;
Console.WriteLine(shortValue2);

short shortValue3 = 0b0100_00001010;
Console.WriteLine(shortValue3);
// The example displays the following output:
//          1034
//          1034
//          1034
```

 备注

使用前缀 `0x` 或 `0X` 表示十六进制文本，使用前缀 `0b` 或 `0B` 表示二进制文本。 十进制文本没有前缀。

从 C# 7.0 开始，添加了一些功能以增强可读性。

- C# 7.0 允许将下划线字符 (`_`) 用作数字分隔符。
- C# 7.2 允许将 `_` 用作二进制或十六进制文本的数字分隔符，位于前缀之后。 十进制文本不能够有前导下划线。

下面是一些示例。

C#复制

```csharp
short shortValue1 = 1_034;
Console.WriteLine(shortValue1);

short shortValue2 = 0b00000100_00001010;
Console.WriteLine(shortValue2);

short shortValue3 = 0b_00000100_00001010;       // C# 7.2 onwards
Console.WriteLine(shortValue3);
// The example displays the following output:
//          1034
//          1034
//          1034
```

#### 编译器重载解析

调用重载方法时必须使用强制转换。 以下面使用 `short` 和 [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int) 参数的重载方法为例：

C#复制

```csharp
public static void SampleMethod(int i) {}
public static void SampleMethod(short s) {}
```

使用 `short` 强制转换可保证调用正确的类型，例如：

C#复制

```csharp
SampleMethod(5);         // Calling the method with the int parameter
SampleMethod((short)5);  // Calling the method with the short parameter
```

#### 转换

存在从 `short` 到 [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int)、[long](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/long)、[float](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/float)、[double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double) 或 [decimal](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/decimal) 的预定义隐式转换。

不能将存储大小更大的非文本数值类型隐式转换为 `short` 类型（有关整型类型的存储大小的信息，请参阅[整型类型表](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/integral-types-table)）。 以下面两个 `short` 变量 `x` 和 `y` 为例：

C#复制

```csharp
short x = 5, y = 12;
```

以下赋值语句将产生一个编译器错误，原因是赋值运算符右侧的算术表达式的计算结果默认为 [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int) 类型。

C#复制

```csharp
short z  = x + y;        // Compiler error CS0266: no conversion from int to short
```

若要解决此问题，请使用强制转换：

C#复制

```csharp
short z  = (short)(x + y);   // Explicit conversion
```

在目标变量具有相同或更大的存储大小时，还可以使用下列语句：

C#复制

```csharp
int m = x + y;
long n = x + y;
```

不存在从浮点型到 `short` 类型的隐式转换。 例如，除非使用显式强制转换，否则以下语句将生成编译器错误：

C#复制

```csharp
short x = 3.0;          // Error: no implicit conversion from double
short y = (short)3.0;   // OK: explicit conversion
```

有关兼用浮点类型和整型类型的算术表达式的信息，请参阅 [float](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/float) 和 [double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double)。

有关隐式数值转换规则的详细信息，请参阅[隐式数值转换表](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/implicit-numeric-conversions-table)。

### [struct](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/struct)

`struct` 类型是一种值类型，通常用来封装小型相关变量组，例如，矩形的坐标或库存商品的特征。 下面的示例显示了一个简单的结构声明：

C#复制

```csharp
public struct Book
{
    public decimal price;
    public string title;
    public string author;
}
```

#### 备注

结构还可以包含[构造函数](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/constructors)、[常量](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/constants)、[字段](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/fields)、[方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/methods)、[属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/properties)、[索引器](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/indexers/index)、[运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/operators)、[事件](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/events/index)和[嵌套类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/nested-types)，但如果同时需要上述几种成员，则应当考虑改为使用类作为类型。

有关示例，请参阅[使用结构](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/using-structs)。

结构可以实现接口，但它们无法继承另一个结构。 因此，结构成员无法声明为 `protected`。

有关详细信息，请参阅[结构](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/structs)。

#### 示例

有关示例和详细信息，请参阅[使用结构](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/using-structs)。

### [uint](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/uint)

`uint` 关键字表示一种整型类型，该类型根据下表显示的大小和范围存储值。

| 类型   | 范围               | 大小               | .NET 类型                                                    |
| ------ | ------------------ | ------------------ | ------------------------------------------------------------ |
| `uint` | 0 到 4,294,967,295 | 无符号的 32 位整数 | [System.UInt32](https://docs.microsoft.com/zh-cn/dotnet/api/system.uint32) |

**请注意**：`uint` 类型不符合 CLS。 请尽可能使用 `int`。

#### 文本

可以通过为其分配十进制文本、十六进制文本或（从 C# 7.0 开始）二进制文本来声明和初始化 `uint` 变量。 如果整数文本在 `uint` 范围之外（即，如果它小于 [UInt32.MinValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.uint32.minvalue) 或大于 [UInt32.MaxValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.uint32.maxvalue)），会发生编译错误。

在以下示例中，表示为十进制、十六进制和二进制文本且等于 3,000,000,000 的整数被分配给 `uint` 值。

C#复制

```csharp
uint uintValue1 = 3000000000;
Console.WriteLine(uintValue1);

uint uintValue2 = 0xB2D05E00;
Console.WriteLine(uintValue2);

uint uintValue3 = 0b1011_0010_1101_0000_0101_1110_0000_0000;
Console.WriteLine(uintValue3);
// The example displays the following output:
//          3000000000
//          3000000000
//          3000000000
```

 备注

使用前缀 `0x` 或 `0X` 表示十六进制文本，使用前缀 `0b` 或 `0B` 表示二进制文本。 十进制文本没有前缀。

从 C# 7.0 开始，添加了一些功能以增强可读性：

- C# 7.0 允许将下划线字符 (`_`) 用作数字分隔符。
- C# 7.2 允许将 `_` 用作二进制或十六进制文本的数字分隔符，位于前缀之后。 十进制文本不能够有前导下划线。

下面是一些示例。

C#复制

```csharp
uint uintValue1 = 3_000_000_000;
Console.WriteLine(uintValue1);

uint uintValue2 = 0xB2D0_5E00;
Console.WriteLine(uintValue2);

uint uintValue3 = 0b1011_0010_1101_0000_0101_1110_0000_0000;
Console.WriteLine(uintValue3);

uint uintValue4 = 0x_B2D0_5E00;       // C# 7.2 onwards
Console.WriteLine(uintValue4);

uint uintValue5 = 0b_1011_0010_1101_0000_0101_1110_0000_0000;       // C# 7.2 onwards
Console.WriteLine(uintValue5);
// The example displays the following output:
//          3000000000
//          3000000000
//          3000000000
//          3000000000
//          3000000000
```

整数文本还可包含表示类型的后缀。 后缀 `U` 或“u”表示 `uint` 或 `ulong`，具体取决于文本的数字值。 以下示例使用 `u` 后缀来表示这两种类型的无符号整数。 请注意第一个文本为 `uint`，因为其值小于 [UInt32.MaxValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.uint32.maxvalue)，而第二个文本为 `ulong`，因为其值大于 [UInt32.MaxValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.uint32.maxvalue)。

C#复制

```csharp
object value1 = 4000000000u;
Console.WriteLine($"{value1} ({4000000000u.GetType().Name})");
object value2 = 6000000000u;
Console.WriteLine($"{value2} ({6000000000u.GetType().Name})");
```

如果整数文本没有后缀，则其类型为以下类型中可表示其值的第一个类型：

1. [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int)
2. `uint`
3. [long](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/long)
4. [ulong](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ulong)

#### 转换

存在从 `uint` 到 [long](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/long)、[ulong](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ulong)、[float](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/float)、[double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double) 或 [decimal](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/decimal) 的预定义隐式转换。 例如:

C#复制

```csharp
float myFloat = 4294967290;   // OK: implicit conversion to float
```

存在从 [byte](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/byte)、[ushort](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ushort) 或 [char](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/char) 到 `uint` 的预定义隐式转换。 否则必须使用转换。 例如，如果不使用转换，以下赋值语句会生成编译错误：

C#复制

```csharp
long aLong = 22;
// Error -- no implicit conversion from long:
uint uInt1 = aLong;
// OK -- explicit conversion:
uint uInt2 = (uint)aLong;
```

另请注意，不存在从浮点类型到 `uint` 类型的隐式转换。 例如，除非使用显式强制转换，否则以下语句将生成编译器错误：

C#复制

```csharp
// Error -- no implicit conversion from double:
uint x = 3.0;
// OK -- explicit conversion:
uint y = (uint)3.0;
```

有关兼用浮点类型和整型类型的算术表达式的信息，请参阅 [float](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/float) 和 [double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double)。

有关隐式数值转换规则的详细信息，请参阅[隐式数值转换表](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/implicit-numeric-conversions-table)。

### [ulong](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/ulong)

`ulong` 关键字表示一种整型类型，该类型根据下表显示的大小和范围存储值。

| 类型    | 范围                            | 大小             | .NET 类型                                                    |
| ------- | ------------------------------- | ---------------- | ------------------------------------------------------------ |
| `ulong` | 0 到 18,446,744,073,709,551,615 | 无符号 64 位整数 | [System.UInt64](https://docs.microsoft.com/zh-cn/dotnet/api/system.uint64) |

#### 文本

可以通过为其分配十进制文本、十六进制文本或（从 C# 7.0 开始）二进制文本来声明和初始化 `ulong` 变量。 如果整数文本在 `ulong` 范围之外（即，如果它小于 [UInt64.MinValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.uint64.minvalue) 或大于 [UInt64.MaxValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.uint64.maxvalue)），会发生编译错误。

在以下示例中，表示为十进制、十六进制和二进制文本且等于 7,934,076,125 的整数被分配给 `ulong` 值。

C#复制

```csharp
ulong ulongValue1 = 7934076125;
Console.WriteLine(ulongValue1);

ulong ulongValue2 = 0x0001D8e864DD;
Console.WriteLine(ulongValue2);

ulong ulongValue3 = 0b0001_1101_1000_1110_1000_0110_0100_1101_1101;
Console.WriteLine(ulongValue3);
// The example displays the following output:
//          7934076125
//          7934076125
//          7934076125
```

> 使用前缀 `0x` 或 `0X` 表示十六进制文本，使用前缀 `0b` 或 `0B` 表示二进制文本。 十进制文本没有前缀。

从 C# 7.0 开始，添加了一些功能以增强可读性：

- C# 7.0 允许将下划线字符 (`_`) 用作数字分隔符。
- C# 7.2 允许将 `_` 用作二进制或十六进制文本的数字分隔符，位于前缀之后。 十进制文本不能够有前导下划线。

下面是一些示例。

C#复制

```csharp
long longValue1 = 4_294_967_296;
Console.WriteLine(longValue1);

long longValue2 = 0x1_0000_0000;
Console.WriteLine(longValue2);

long longValue3 = 0b1_0000_0000_0000_0000_0000_0000_0000_0000;
Console.WriteLine(longValue3);

long longValue4 = 0x_1_0000_0000;       // C# 7.2 onwards
Console.WriteLine(longValue4);

long longValue5 = 0b_1_0000_0000_0000_0000_0000_0000_0000_0000;       // C# 7.2 onwards
Console.WriteLine(longValue5);
// The example displays the following output:
//          4294967296
//          4294967296
//          4294967296
//          4294967296
//          4294967296
```

整数文本还可包含表示类型的后缀。 后缀 `UL` 或 `ul` 将数字文本明确标识为 `ulong` 值。 如果文本值超过 [Int64.MaxValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.int64.maxvalue)，则 `L` 后缀表示 `ulong`。 如果文本值超过 [UInt32.MaxValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.uint32.maxvalue)，则 `U` 或 `u` 后缀表示 `ulong`。 以下示例使用 `ul` 后缀来表示长整型：

C#复制

```csharp
object value1 = 700000000000ul;
Console.WriteLine($"{value1} ({700000000000ul.GetType().Name})");
```

如果整数文本没有后缀，则其类型为以下类型中可表示其值的第一个类型：

1. [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int)
2. [uint](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/uint)
3. [long](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/long)
4. `ulong`

#### 编译器重载解析

此后缀常用于调用重载方法。 以下面使用 `ulong` 和 [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int) 参数的重载方法为例：

C#复制

```csharp
public static void SampleMethod(int i) {}
public static void SampleMethod(ulong l) {}
```

在 `ulong` 参数后加上后缀可保证调用正确的类型，例如：

C#复制

```csharp
SampleMethod(5);    // Calling the method with the int parameter
SampleMethod(5UL);  // Calling the method with the ulong parameter
```

#### 转换

存在从 `ulong` 到 [float](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/float)、[double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double) 或 [decimal](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/decimal) 的预定义隐式转换。

不存在从 `ulong` 到任何整型的隐式转换。 例如，如果不使用显式强制转换，以下语句会生成编译错误：

C#复制

```csharp
long long1 = 8UL;   // Error: no implicit conversion from ulong
```

存在从 [byte](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/byte)、[ushort](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ushort)、[uint](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/uint) 或 [char](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/char) 到 `ulong` 的预定义隐式转换。

此外，不存在从浮点类型到 `ulong` 类型的隐式转换。 例如，除非使用显式强制转换，否则以下语句将生成编译器错误：

C#复制

```csharp
// Error -- no implicit conversion from double:
ulong x = 3.0;
// OK -- explicit conversion:
ulong y = (ulong)3.0;
```

有关兼用浮点类型和整型类型的算术表达式的信息，请参阅 [float](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/float) 和 [double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double)。

有关隐式数值转换规则的详细信息，请参阅[隐式数值转换表](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/implicit-numeric-conversions-table)。

### [ushort](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/ushort)

`ushort` 关键字表示一种整型数据类型，该类型根据下表显示的大小和范围存储值。

| 类型     | 范围        | 大小             | .NET 类型                                                    |
| -------- | ----------- | ---------------- | ------------------------------------------------------------ |
| `ushort` | 0 到 65,535 | 无符号 16 位整数 | [System.UInt16](https://docs.microsoft.com/zh-cn/dotnet/api/system.uint16) |

#### 文本

可以通过为其分配十进制文本、十六进制文本或（从 C# 7.0 开始）二进制文本来声明和初始化 `ushort` 变量。如果整数文本在 `ushort` 范围之外（即，如果它小于 [UInt16.MinValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.uint16.minvalue) 或大于 [UInt16.MaxValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.uint16.maxvalue)），会发生编译错误。

在以下示例中，等于 65,034、表示为十进制、十六进制和二进制文本的整数从 [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int) 隐式转换为 `ushort` 值。

C#复制

```csharp
ushort ushortValue1 = 65034;
Console.WriteLine(ushortValue1);

ushort ushortValue2 = 0xFE0A;
Console.WriteLine(ushortValue2);

ushort ushortValue3 = 0b1111_1110_0000_1010;
Console.WriteLine(ushortValue3);
// The example displays the following output:
//          65034
//          65034
//          65034
```

 备注

使用前缀 `0x` 或 `0X` 表示十六进制文本，使用前缀 `0b` 或 `0B` 表示二进制文本。 十进制文本没有前缀。

从 C# 7.0 开始，添加了一些功能以增强可读性：

- C# 7.0 允许将下划线字符 (`_`) 用作数字分隔符。
- C# 7.2 允许将 `_` 用作二进制或十六进制文本的数字分隔符，位于前缀之后。 十进制文本不能够有前导下划线。

下面是一些示例。

C#复制

```csharp
ushort ushortValue1 = 65_034;
Console.WriteLine(ushortValue1);

ushort ushortValue2 = 0b11111110_00001010;
Console.WriteLine(ushortValue2);

ushort ushortValue3 = 0b_11111110_00001010;     // C# 7.2 onwards
Console.WriteLine(ushortValue3);
// The example displays the following output:
//          65034
//          65034
//          65034
```

#### 编译器重载解析

调用重载方法时必须使用强制转换。 以下面使用 `ushort` 和 [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int) 参数的重载方法为例：

C#复制

```csharp
public static void SampleMethod(int i) {}
public static void SampleMethod(ushort s) {}
```

使用 `ushort` 强制转换可保证调用正确的类型，例如：

C#复制

```csharp
// Calls the method with the int parameter:
SampleMethod(5);
// Calls the method with the ushort parameter:
SampleMethod((ushort)5);
```

#### 转换

存在从 `ushort` 到 [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int)、[uint](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/uint)、[long](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/long)、[ulong](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ulong)、[float](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/float)、[double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double) 或 [decimal](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/decimal) 的预定义隐式转换。

存在从 [byte](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/byte) 或 [char](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/char) 到 `ushort` 的预定义隐式转换。 其他情况下必须使用强制转换来执行显式转换。 以下面两个 `ushort` 变量 `x` 和 `y` 为例：

C#复制

```csharp
ushort x = 5, y = 12;
```

以下赋值语句会生成一个编译错误，原因是赋值运算符右侧的算术表达式在默认情况下的计算结果为 `int`。

C#复制

```csharp
ushort z = x + y;   // Error: conversion from int to ushort
```

若要解决此问题，请使用强制转换：

C#复制

```csharp
ushort z = (ushort)(x + y);   // OK: explicit conversion
```

但是，在目标变量具有相同或更大的存储大小时，可以使用下列语句：

C#复制

```csharp
int m = x + y;
long n = x + y;
```

另请注意，不存在从浮点类型到 `ushort` 类型的隐式转换。 例如，除非使用显式强制转换，否则以下语句将生成编译器错误：

C#复制

```csharp
// Error -- no implicit conversion from double:
ushort x = 3.0;
// OK -- explicit conversion:
ushort y = (ushort)3.0;
```

有关兼用浮点类型和整型类型的算术表达式的信息，请参阅 [float](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/float) 和 [double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double)。

有关隐式数值转换规则的详细信息，请参阅[隐式数值转换表](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/implicit-numeric-conversions-table)。

## [Reference Types](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/reference-types)

C# 中有两种类型：引用类型和值类型。 引用类型的变量存储对其数据（对象）的引用，而值类型的变量直接包含其数据。 对于引用类型，两种变量可引用同一对象；因此，对一个变量执行的操作会影响另一个变量所引用的对象。 对于值类型，每个变量都具有其自己的数据副本，对一个变量执行的操作不会影响另一个变量（in、ref 和 out 参数变量除外；请参阅 [in](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/in-parameter-modifier)、[ref](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ref) 和 [out](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/out-parameter-modifier) 参数修饰符）。

下列关键字用于声明引用类型：

- [class](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/class)
- [interface](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/interface)
- [delegate](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/delegate)

C# 也提供了下列内置引用类型：

- [dynamic](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/dynamic)
- [object](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/object)
- [string](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/string)

### [class](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/class)

使用 `class` 关键字声明类，如下例中所示：

C#复制

```csharp
class TestClass
{
    // Methods, properties, fields, events, delegates
    // and nested classes go here.
}
```

#### 备注

在 C# 中仅允许单一继承。 也就是说，一个类仅能从一个基类继承实现。 但是，一个类可实现多个接口。 下表显示类继承和接口实现的一些示例：

| 继承               | 示例                                            |
| ------------------ | ----------------------------------------------- |
| 无                 | `class ClassA { }`                              |
| Single             | `class DerivedClass: BaseClass { }`             |
| 无，实现两个接口   | `class ImplClass: IFace1, IFace2 { }`           |
| 单一，实现一个接口 | `class ImplDerivedClass: BaseClass, IFace1 { }` |

直接在命名空间中声明的、未嵌套在其它类中的类，可以是[公共](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/public)或[内部](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/internal)。 默认情况下类为 `internal`。

类成员（包括嵌套的类）可以是 [public](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/public)、[protected internal](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/protected-internal)、[protected](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/protected)、[internal](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/internal)、[private](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/private) 或 [private protected](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/private-protected)。 默认情况下成员为 `private`。

有关详细信息，请参阅[访问修饰符](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/access-modifiers)。

可以声明具有类型参数的泛型类。 有关更多信息，请参见[泛型类](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/generics/generic-classes)。

一个类可包含下列成员的声明：

- [构造函数](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/constructors)
- [常量](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/constants)
- [字段](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/fields)
- [终结器](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/destructors)
- [方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/methods)
- [属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/properties)
- [索引器](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/indexers/index)
- [运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/operators)
- [事件](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/events/index)
- [委托](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/delegates/index)
- [类](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/classes)
- [接口](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/interfaces/index)
- [结构](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/structs)
- [枚举](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/enumeration-types)

#### 示例

下面的示例说明如何声明类字段、构造函数和方法。 该示例还说明如何实例化对象及如何打印实例数据。 本例声明了两个类。 第一个类 `Child` 包含两个私有字段（`name` 和 `age`）、两个公共构造函数和一个公共方法。第二个类 `StringTest` 用于包含 `Main`。

C#复制

```csharp
class Child
{
    private int age;
    private string name;

    // Default constructor:
    public Child()
    {
        name = "N/A";
    }

    // Constructor:
    public Child(string name, int age)
    {
        this.name = name;
        this.age = age;
    }

    // Printing method:
    public void PrintChild()
    {
        Console.WriteLine("{0}, {1} years old.", name, age);
    }
}

class StringTest
{
    static void Main()
    {
        // Create objects by using the new operator:
        Child child1 = new Child("Craig", 11);
        Child child2 = new Child("Sally", 10);

        // Create an object using the default constructor:
        Child child3 = new Child();

        // Display results:
        Console.Write("Child #1: ");
        child1.PrintChild();
        Console.Write("Child #2: ");
        child2.PrintChild();
        Console.Write("Child #3: ");
        child3.PrintChild();
    }
}
/* Output:
    Child #1: Craig, 11 years old.
    Child #2: Sally, 10 years old.
    Child #3: N/A, 0 years old.
*/
```

#### 注释

注意：在上例中，私有字段（`name` 和 `age`）只能通过 `Child` 类的公共方法访问。 例如，不能在 `Main` 方法中使用如下语句打印 Child 的名称：

C#复制

```csharp
Console.Write(child1.name);   // Error
```

只有当 `Main` 是类的成员时，才能从 `Main` 访问 `Child` 的私有成员。

类中不具有访问修饰符的已声明类型默认为 `private`，因此如果已删除关键字，则此示例中的数据成员将仍为 `private`。

最后要注意的是，默认情况下，对于使用默认构造函数 (`child3`) 创建的对象，`age` 字段初始化为零。

### [delegate](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/delegate)

委托类型的声明与方法签名相似。 它有一个返回值和任意数目任意类型的参数：

C#复制

```csharp
public delegate void TestDelegate(string message);
public delegate int TestDelegate(MyType m, long num);
```

`delegate` 是一种可用于封装命名方法或匿名方法的引用类型。 委托类似于 C++ 中的函数指针；但是，委托是类型安全和可靠的。 有关委托的应用，请参阅[委托](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/delegates/index)和[泛型委托](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/generics/generic-delegates)。

#### 备注

委托是[事件](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/events/index)的基础。

通过将委托与命名方法或匿名方法关联，可以实例化委托。 有关详细信息，请参阅[命名方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/delegates/delegates-with-named-vs-anonymous-methods)和[匿名方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/anonymous-methods)。

必须使用具有兼容返回类型和输入参数的方法或 lambda 表达式实例化委托。 有关方法签名中允许的差异程度的详细信息，请参阅[委托中的变体](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/covariance-contravariance/using-variance-in-delegates)。 为了与匿名方法一起使用，委托和与之关联的代码必须一起声明。 本节讨论这两种实例化委托的方法。

#### 示例

C#复制

```csharp
// Declare delegate -- defines required signature:
delegate double MathAction(double num);

class DelegateTest
{
    // Regular method that matches signature:
    static double DoubleAmount(double input)
    {
        return input * 2;
    }

    static void Main()
    {
        // Instantiate delegate with named method:
        MathAction ma = DoubleAmount;

        // Invoke delegate ma:
        double multByTwo = ma(4.5);
        Console.WriteLine("multByTwo: {0}", multByTwo);

        // Instantiate delegate with anonymous method:
        MathAction ma2 = delegate(double input)
        {
            return input * input;
        };

        double square = ma2(5);
        Console.WriteLine("square: {0}", square);

        // Instantiate delegate with lambda expression
        MathAction ma3 = s => s * s * s;
        double cube = ma3(4.375);

        Console.WriteLine("cube: {0}", cube);
    }
    // Output:
    // multByTwo: 9
    // square: 25
    // cube: 83.740234375
}
```

### [dynamic](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/dynamic)

在通过 `dynamic` 类型实现的操作中，该类型的作用是绕过编译时类型检查。 改为在运行时解析这些操作。 `dynamic` 类型简化了对 COM API（例如 Office Automation API）、动态 API（例如 IronPython 库）和 HTML 文档对象模型 (DOM) 的访问。

在大多数情况下，`dynamic` 类型与 `object` 类型的行为类似。 但是，如果操作包含 `dynamic` 类型的表达式，那么不会通过编译器对该操作进行解析或类型检查。 编译器将有关该操作信息打包在一起，之后这些信息会用于在运行时评估操作。 在此过程中，`dynamic` 类型的变量会编译为 `object` 类型的变量。 因此，`dynamic` 类型只在编译时存在，在运行时则不存在。

下面的示例将 `dynamic` 类型的变量与 `object` 类型的变量进行对比。 若要在编译时验证每个变量的类型，请将鼠标指针放在 `WriteLine` 语句中的 `dyn` 或 `obj` 上。 IntelliSense 对 `dyn` 显示“dynamic”，对 `obj` 显示“object”。

C#复制

```csharp
class Program
{
    static void Main(string[] args)
    {
        dynamic dyn = 1;
        object obj = 1;

        // Rest the mouse pointer over dyn and obj to see their
        // types at compile time.
        System.Console.WriteLine(dyn.GetType());
        System.Console.WriteLine(obj.GetType());
    }
}
```

`WriteLine` 语句显示 `dyn` 和 `obj` 的运行时类型。 此时，两者的类型均为整数。 将生成以下输出：

```
System.Int32
System.Int32
```

若要查看编译时 `dyn` 与 `obj` 之间的区别，请在前面示例的声明和 `WriteLine` 语句之间添加下列两行。

C#复制

```csharp
dyn = dyn + 3;
obj = obj + 3;
```

尝试在表达式 `obj + 3` 中添加整数和对象时，将报告编译器错误。 但是，对于 `dyn + 3`，不会报告任何错误。在编译时不会检查包含 `dyn` 的表达式，原因是 `dyn` 的类型为 `dynamic`。

#### 上下文

`dynamic` 关键字可以直接出现，也可以作为构造类型的组件在下列情况中出现：

- 在声明中，作为属性、字段、索引器、参数、返回值、本地变量或类型约束的类型。 下面的类定义在多个不同的声明中使用 `dynamic`。

  C#复制

  ```csharp
  class ExampleClass
  {
      // A dynamic field.
      static dynamic field;
  
      // A dynamic property.
      dynamic prop { get; set; }
  
      // A dynamic return type and a dynamic parameter type.
      public dynamic exampleMethod(dynamic d)
      {
          // A dynamic local variable.
          dynamic local = "Local variable";
          int two = 2;
  
          if (d is int)
          {
              return local;
          }
          else
          {
              return two;
          }
      }
  }
  ```

- 在显式类型转换中，作为转换的目标类型。

  C#复制

  ```csharp
  static void convertToDynamic()
  {
      dynamic d;
      int i = 20;
      d = (dynamic)i;
      Console.WriteLine(d);
  
      string s = "Example string.";
      d = (dynamic)s;
      Console.WriteLine(d);
  
      DateTime dt = DateTime.Today;
      d = (dynamic)dt;
      Console.WriteLine(d);
  
  }
  // Results:
  // 20
  // Example string.
  // 7/25/2018 12:00:00 AM
  ```

- 在以下任何情况下：类型用作值（如 `is` 运算符或 `as` 运算符右侧），或者用作构造类型中 `typeof` 的参数。 例如，可以在下列表达式中使用 `dynamic`。

  C#复制

  ```csharp
  int i = 8;
  dynamic d;
  // With the is operator.
  // The dynamic type behaves like object. The following
  // expression returns true unless someVar has the value null.
  if (someVar is dynamic) { }
  
  // With the as operator.
  d = i as dynamic;
  
  // With typeof, as part of a constructed type.
  Console.WriteLine(typeof(List<dynamic>));
  
  // The following statement causes a compiler error.
  //Console.WriteLine(typeof(dynamic));
  ```

#### 示例

下面的示例在多个声明中使用 `dynamic`。 `Main` 方法也将编译时类型检查与运行时类型检查进行了对比。

C#复制

```csharp
using System;

namespace DynamicExamples
{
    class Program
    {
        static void Main(string[] args)
        {
            ExampleClass ec = new ExampleClass();
            Console.WriteLine(ec.exampleMethod(10));
            Console.WriteLine(ec.exampleMethod("value"));

            // The following line causes a compiler error because exampleMethod
            // takes only one argument.
            //Console.WriteLine(ec.exampleMethod(10, 4));

            dynamic dynamic_ec = new ExampleClass();
            Console.WriteLine(dynamic_ec.exampleMethod(10));

            // Because dynamic_ec is dynamic, the following call to exampleMethod
            // with two arguments does not produce an error at compile time.
            // However, itdoes cause a run-time error. 
            //Console.WriteLine(dynamic_ec.exampleMethod(10, 4));
        }
    }

    class ExampleClass
    {
        static dynamic field;
        dynamic prop { get; set; }

        public dynamic exampleMethod(dynamic d)
        {
            dynamic local = "Local variable";
            int two = 2;

            if (d is int)
            {
                return local;
            }
            else
            {
                return two;
            }
        }
    }
}
// Results:
// Local variable
// 2
// Local variable
```

有关详细信息和示例，请参阅[使用类型 dynamic](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/types/using-type-dynamic)。

### [interface](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/interface)

接口只包含[方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/methods)、[属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/properties)、[事件](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/events/index)或[索引器](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/indexers/index)的签名。 实现接口的类或结构必须实现接口定义中指定的接口成员。 在以下示例中，类 `ImplementationClass` 必须实现一个不含参数但返回 `void` 的名为 `SampleMethod` 的方法。

有关详细信息和示例，请参阅[接口](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/interfaces/index)。

#### 示例

C#复制

```csharp
interface ISampleInterface
{
    void SampleMethod();
}

class ImplementationClass : ISampleInterface
{
    // Explicit interface member implementation: 
    void ISampleInterface.SampleMethod()
    {
        // Method implementation.
    }

    static void Main()
    {
        // Declare an interface instance.
        ISampleInterface obj = new ImplementationClass();

        // Call the member.
        obj.SampleMethod();
    }
}
```

接口可以是命名空间或类的成员，并且可以包含下列成员的签名：

- [方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/methods)
- [属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/using-properties)
- [索引器](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/indexers/using-indexers)
- [事件](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/event)

一个接口可从一个或多个基接口继承。

基类型列表包含基类和接口时，基类必须是列表中的第 1 项。

实现接口的类可以显式实现该接口的成员。 显式实现的成员不能通过类实例访问，而只能通过接口实例访问。

有关显式接口实现的更多详细信息和代码示例，请参阅[显式接口实现](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/interfaces/explicit-interface-implementation)。

#### 示例

下例演示了接口实现。 在此示例中，接口包含属性声明，类包含实现。 实现 `IPoint` 的类的任何实例都具有整数属性 `x` 和 `y`。

C#复制

```csharp
interface IPoint
{
   // Property signatures:
   int x
   {
      get;
      set;
   }

   int y
   {
      get;
      set;
   }
}

class Point : IPoint
{
   // Fields:
   private int _x;
   private int _y;

   // Constructor:
   public Point(int x, int y)
   {
      _x = x;
      _y = y;
   }

   // Property implementation:
   public int x
   {
      get
      {
         return _x;
      }

      set
      {
         _x = value;
      }
   }

   public int y
   {
      get
      {
         return _y;
      }
      set
      {
         _y = value;
      }
   }
}

class MainClass
{
   static void PrintPoint(IPoint p)
   {
      Console.WriteLine("x={0}, y={1}", p.x, p.y);
   }

   static void Main()
   {
      IPoint p = new Point(2, 3);
      Console.Write("My Point: ");
      PrintPoint(p);
   }
}
// Output: My Point: x=2, y=3
```

### [object](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/object)

`object` 类型是 [Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object) 在 .NET 中的别名。 在 C# 的统一类型系统中，所有类型（预定义类型、用户定义类型、引用类型和值类型）都是直接或间接从 [Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object) 继承的。 可以将任何类型的值赋给 `object` 类型的变量。 将值类型的变量转换为对象的过程称为*装箱*。 将对象类型的变量转换为值类型的过程称为*取消装箱*。 有关详细信息，请参阅[装箱和取消装箱](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/types/boxing-and-unboxing)。

#### 示例

下面的示例演示 `object` 类型的变量如何接受任何数据类型的值，以及 `object` 类型的变量如何在 .NET Framework 中使用 [Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object) 的方法。

```csharp
class ObjectTest
{
   public int i = 10;
}

class MainClass2
{
   static void Main()
   {
      object a;
      a = 1;   // an example of boxing
      Console.WriteLine(a);
      Console.WriteLine(a.GetType());
      Console.WriteLine(a.ToString());

      a = new ObjectTest();
      ObjectTest classRef;
      classRef = (ObjectTest)a;
      Console.WriteLine(classRef.i);
   }
}
/* Output
    1
    System.Int32
    1
 * 10
*/
```

### [string](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/string)

`string` 类型表示零个或多个 Unicode 字符的序列。 `string` 是 [String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string) 在 .NET 中的别名。

尽管 `string` 为引用类型，定义相等运算符（`==` 和 `!=`）是为了比较 `string` 对象（而不是引用）的值。 这使得对字符串相等性的测试更为直观。 例如:

C#复制

```csharp
string a = "hello";
string b = "h";
// Append to contents of 'b'
b += "ello";
Console.WriteLine(a == b);
Console.WriteLine((object)a == (object)b);
```

此时将显示“True”，然后显示“False”，因为字符串的内容是相等的，但 `a` 和 `b` 并不指代同一字符串实例。

\+ 运算符可连接字符串：

C#复制

```csharp
string a = "good " + "morning";
```

这将创建包含“good morning”的字符串对象。

字符串是不可变的，即：字符串对象在创建后，尽管从语法上看似乎可以更改其内容，但事实上并不可行。 例如，编写此代码时，编译器实际上会创建一个新的字符串对象来保存新的字符序列，且该新对象将赋给 b。 然后，字符串“h”便可进行垃圾回收。

C#复制

```csharp
string b = "h";
b += "ello";
```

[] 运算符可用于只读访问 `string` 的个别字符：

C#复制

```csharp
string str = "test";
char x = str[2];  // x = 's';
```

同样，[] 运算符也可用于循环访问 `string` 中的每个字符：

C#复制

```csharp
string str = "test";

for (int i = 0; i < str.Length; i++)
{
  Console.Write(str[i] + " ");
}
// Output: t e s t
```

字符串文本属于类型 `string` 且可编写为两种形式，带引号和 @-quoted。 带引号字符串括在双引号 (") 内。

C#复制

```csharp
"good morning"  // a string literal
```

字符串文本可包含任何字符文本。 包括转义序列。 下面的示例使用转义序列 `\\` 表示反斜杠，使用 `\u0066` 表示字母 f，以及使用 `\n` 表示换行符。

C#复制

```csharp
string a = "\\\u0066\n";
Console.WriteLine(a);
```

 备注

转义码 `\udddd`（其中 `dddd` 是一个四位数字）表示 Unicode 字符 U+`dddd`。 另外，还可识别八位 Unicode 转义码：`\Udddddddd`。

逐字字符串文本以 `@` 开头，并且也括在双引号内。 例如:

C#复制

```csharp
@"good morning"  // a string literal
```

逐字字符串的优点是不处理转义序列，这样就可轻松编写完全限定的文件名等：

C#复制

```csharp
@"c:\Docs\Source\a.txt"  // rather than "c:\\Docs\\Source\\a.txt"
```

若要在 @-quoted 字符串中包含双引号，双倍添加即可：

C#复制

```csharp
@"""Ahoy!"" cried the captain." // "Ahoy!" cried the captain.
```

有关 `@` 特殊字符的其他用法，请参阅 [@ - 逐字字符串](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/tokens/verbatim)。

有关 C# 中的字符串的详细信息，请参阅[字符串](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/strings/index)。

#### 示例

C#复制

```csharp
class SimpleStringTest 
{
   static void Main()
   {
      string a = "\u0068ello ";
      string b = "world";
      Console.WriteLine( a + b );
      Console.WriteLine( a + b == "Hello World" ); // == performs a case-sensitive comparison
   }
}
/* Output:
    hello world
    False
 */
```

## [void](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/void)

当用作一种方法的返回类型时，`void` 将指定该方法不返回值。

方法的参数列表中不允许有 `void`。 无参数且不返回值的方法的声明方式如下：

C#复制

```csharp
public void SampleMethod()
{
    // Body of the method.
}
```

`void` 还可用于在不安全的上下文中将指针声明为未知类型。 有关详细信息，请参阅[指针类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/unsafe-code-pointers/pointer-types)。

`void` 是 .NET Framework [System.Void](https://docs.microsoft.com/zh-cn/dotnet/api/system.void) 类型的别名。

## [var](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/var)

从 Visual C# 3.0 开始，在方法范围内声明的变量可以具有隐式“类型”`var`。 隐式类型本地变量为强类型，就像用户已经自行声明该类型，但编译器决定类型一样。 `i` 的以下两个声明在功能上是等效的：

```csharp
var i = 10; // Implicitly typed.
int i = 10; // Explicitly typed.
```

有关详细信息，请参阅[隐式类型的局部变量](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/implicitly-typed-local-variables)和 [LINQ 查询操作中的类型关系](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/type-relationships-in-linq-query-operations)。

#### 示例

下面的示例演示两个查询表达式。 在第一个表达式中，`var` 的使用是允许的，但不是必需的，因为查询结果的类型可以明确表述为 `IEnumerable<string>`。 不过，在第二个表达式中，`var` 允许结果是一系列匿名类型，且相应类型的名称只可供编译器本身访问。 如果使用 `var`，便无法为结果新建类。 请注意，在示例 #2 中，`foreach` 迭代变量 `item` 必须也为隐式类型。

C#复制

```csharp
// Example #1: var is optional when
// the select clause specifies a string
string[] words = { "apple", "strawberry", "grape", "peach", "banana" };
var wordQuery = from word in words
                where word[0] == 'g'
                select word;

// Because each element in the sequence is a string, 
// not an anonymous type, var is optional here also.
foreach (string s in wordQuery)
{
    Console.WriteLine(s);
}

// Example #2: var is required because
// the select clause specifies an anonymous type
var custQuery = from cust in customers
                where cust.City == "Phoenix"
                select new { cust.Name, cust.Phone };

// var must be used because each item 
// in the sequence is an anonymous type
foreach (var item in custQuery)
{
    Console.WriteLine("Name={0}, Phone={1}", item.Name, item.Phone);
}
```

## [Reference tables for types](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/reference-tables-for-types)

以下参考表概括了 C# 类型：

| 表                                                           | 说明                                     |
| ------------------------------------------------------------ | ---------------------------------------- |
| [内置类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/built-in-types-table) | 列出了内置的 C# 类型和相应的 .NET 类型。 |
| [整型类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/integral-types-table) | 提供整型类型的概述。                     |
| [浮点类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/floating-point-types-table) | 提供浮点类型的概述。                     |
| [值类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/value-types-table) | 列出了 C# 值类型。                       |
| [默认值](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/default-values-table) | 列出了 C# 值类型的默认值。               |
| [隐式数值转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/implicit-numeric-conversions-table) | 概述了 C# 数值类型之间受支持的隐式转换。 |
| [显式数值转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/explicit-numeric-conversions-table) | 概述了 C# 数值类型之间受支持的显式转换。 |
| [设置数值结果的格式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/formatting-numeric-results-table) | 概述了标准数值格式字符串。               |

### [Built-in types table](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/built-in-types-table)

下表显示内置 C# 类型的关键字，即 [System](https://docs.microsoft.com/zh-cn/dotnet/api/system) 命名空间中预定义类型的别名。

| C# 类型                                                      | .NET 类型                                                    |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [bool](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/bool) | [System.Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) |
| [byte](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/byte) | [System.Byte](https://docs.microsoft.com/zh-cn/dotnet/api/system.byte) |
| [sbyte](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/sbyte) | [System.SByte](https://docs.microsoft.com/zh-cn/dotnet/api/system.sbyte) |
| [char](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/char) | [System.Char](https://docs.microsoft.com/zh-cn/dotnet/api/system.char) |
| [decimal](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/decimal) | [System.Decimal](https://docs.microsoft.com/zh-cn/dotnet/api/system.decimal) |
| [double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double) | [System.Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double) |
| [float](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/float) | [System.Single](https://docs.microsoft.com/zh-cn/dotnet/api/system.single) |
| [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int) | [System.Int32](https://docs.microsoft.com/zh-cn/dotnet/api/system.int32) |
| [uint](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/uint) | [System.UInt32](https://docs.microsoft.com/zh-cn/dotnet/api/system.uint32) |
| [long](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/long) | [System.Int64](https://docs.microsoft.com/zh-cn/dotnet/api/system.int64) |
| [ulong](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ulong) | [System.UInt64](https://docs.microsoft.com/zh-cn/dotnet/api/system.uint64) |
| [object](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/object) | [System.Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object) |
| [short](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/short) | [System.Int16](https://docs.microsoft.com/zh-cn/dotnet/api/system.int16) |
| [ushort](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ushort) | [System.UInt16](https://docs.microsoft.com/zh-cn/dotnet/api/system.uint16) |
| [string](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/string) | [System.String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string) |

#### 备注

此表中的所有类型，除 `object` 和 `string` 外，皆被称为简单类型。

C# 类型关键字及其别名可互换。 例如，可通过使用以下任意一个声明来声明整型变量：

```csharp
int x = 123;
System.Int32 y = 123;
```

使用 [typeof](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/typeof) 运算符以获取表示指定类型的 [System.Type](https://docs.microsoft.com/zh-cn/dotnet/api/system.type) 实例：

```csharp
Type stringType = typeof(string);
Console.WriteLine(stringType.FullName);

Type doubleType = typeof(System.Double);
Console.WriteLine(doubleType.FullName);

// Output:
// System.String
// System.Double
```

### [Integral types table](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/integral-types-table)

下表显示整型类型的大小和范围，它们构成简单类型的子集。

| 类型                                                         | 范围                                                    | 大小               |
| ------------------------------------------------------------ | ------------------------------------------------------- | ------------------ |
| [sbyte](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/sbyte) | -128 到 127                                             | 8 位带符号整数     |
| [byte](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/byte) | 0 到 255                                                | 无符号的 8 位整数  |
| [char](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/char) | U+0000 到 U+ffff                                        | Unicode 16 位字符  |
| [short](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/short) | -32,768 到 32,767                                       | 有符号 16 位整数   |
| [ushort](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ushort) | 0 到 65,535                                             | 无符号 16 位整数   |
| [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int) | -2,147,483,648 到 2,147,483,647                         | 带符号的 32 位整数 |
| [uint](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/uint) | 0 到 4,294,967,295                                      | 无符号的 32 位整数 |
| [long](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/long) | -9,223,372,036,854,775,808 到 9,223,372,036,854,775,807 | 64 位带符号整数    |
| [ulong](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ulong) | 0 到 18,446,744,073,709,551,615                         | 无符号 64 位整数   |

#### 备注

如果由整数字面量所表示的值超出了 [UInt64.MaxValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.uint64.maxvalue)，则将出现编译器错误 [CS1021](https://docs.microsoft.com/zh-cn/dotnet/csharp/misc/cs1021)。

使用 [System.Numerics.BigInteger](https://docs.microsoft.com/zh-cn/dotnet/api/system.numerics.biginteger) 结构来表示任意大的带符号整数。

### [Floating-point types table](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/floating-point-types-table)

下表显示了浮点类型的精度和大致范围。

| 类型                                                         | 大致范围                       | 精度              |
| ------------------------------------------------------------ | ------------------------------ | ----------------- |
| [float](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/float) | ±1.5 x 10−45 至 ±3.4 x 1038    | 大约 6-9 位数字   |
| [double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double) | ±5.0 × 10−324 到 ±1.7 × 10308  | 大约 15-17 位数字 |
| [decimal](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/decimal) | ±1.0 x 10-28 至 ±7.9228 x 1028 | 28-29 位          |

### [Value types table](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/value-types-table)

下表显示[值类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/value-types)的默认值。

| 值类型                                                       | 默认值                                                       |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [bool](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/bool) | `false`                                                      |
| [byte](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/byte) | 0                                                            |
| [char](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/char) | '\0'                                                         |
| [decimal](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/decimal) | 0M                                                           |
| [double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double) | 0.0D                                                         |
| [enum](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/enum) | 表达式 `(E)0` 生成的值，其中 `E` 是枚举标识符。              |
| [float](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/float) | 0.0F                                                         |
| [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int) | 0                                                            |
| [long](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/long) | 0L                                                           |
| [sbyte](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/sbyte) | 0                                                            |
| [short](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/short) | 0                                                            |
| [struct](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/struct) | 通过如下设置生成的值：将所有值类型的字段设置为其默认值，将所有引用类型的字段设置为 `null`。 |
| [uint](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/uint) | 0                                                            |
| [ulong](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ulong) | 0                                                            |
| [ushort](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ushort) | 0                                                            |

#### 备注

无法在 C# 中使用未初始化的变量。 可以使用变量类型的默认值对变量进行初始化。 还可使用类型的默认值来指定方法的[可选参数](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/named-and-optional-arguments#optional-arguments)的默认值。

使用[默认值表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/default-value-expressions)生成类型的默认值，如以下示例所示：

C#复制

```csharp
int a = default(int);
```

从 C# 7.1 开始，可使用[`default`文本](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/default-value-expressions#default-literal-and-type-inference)来初始化变量，使其具有其类型的默认值：

C#复制

```csharp
int a = default;
```

还可使用默认构造函数或隐式默认构造函数来生成值类型的默认值，如以下示例所示。 有关构造函数的详细信息，请参阅[构造函数](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/constructors)一文。

C#复制

```csharp
int a = new int();
```

任何[引用类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/reference-types)的默认值为 `null`。 [可以为 null 的类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/nullable-types/index)的默认值是 [HasValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullable-1.hasvalue) 属性为 `false` 且未定义 [Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullable-1.value) 属性的实例。

### [Default values table](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/default-values-table)

下表显示 C# 值类型：

| 值类型                                                       | 类别                                                         | 类型后缀                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ | -------------------------------- |
| [bool](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/bool) | Boolean                                                      |                                  |
| [byte](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/byte) | 无符号、数字、[整型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/integral-types-table) |                                  |
| [char](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/char) | 无符号、数字、[整型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/integral-types-table) |                                  |
| [decimal](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/decimal) | 数字、[浮点](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/floating-point-types-table) | M 或 m                           |
| [double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double) | 数字、[浮点](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/floating-point-types-table) | D 或 d                           |
| [enum](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/enum) | 枚举                                                         |                                  |
| [float](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/float) | 数字、[浮点](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/floating-point-types-table) | F 或 f                           |
| [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int) | 带符号、数字、[整型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/integral-types-table) |                                  |
| [long](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/long) | 带符号、数字、[整型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/integral-types-table) | L 或 l                           |
| [sbyte](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/sbyte) | 带符号、数字、[整型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/integral-types-table) |                                  |
| [short](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/short) | 带符号、数字、[整型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/integral-types-table) |                                  |
| [struct](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/struct) | 用户定义的结构                                               |                                  |
| [uint](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/uint) | 无符号、数字、[整型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/integral-types-table) | U 或 u                           |
| [ulong](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ulong) | 无符号、数字、[整型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/integral-types-table) | UL、Ul、uL、ul、LU、Lu、lU 或 lu |
| [ushort](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ushort) | 无符号、数字、[整型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/integral-types-table) |                                  |

#### 备注

使用类型后缀指定数字文字的类型。 例如:

C#复制

```csharp
decimal a = 0.1M;
```

如果[整数数值型字面量](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#integer-literals)没有后缀，则它具有以下类型中的第一个类型，其值可以通过这种类型表示：`int`、`uint`、`long`、`ulong`。

如果[实际数值字面量](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#real-literals)没有后缀，则其类型为 `double`。

### [Implicit numeric conversions table](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/implicit-numeric-conversions-table)

下表显示 .NET 数值类型之间的预定义隐式转换。

| From                                                         | 到                                                           |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [sbyte](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/sbyte) | `short`、`int`、`long`、`float`、`double` 或 `decimal`       |
| [byte](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/byte) | `short`、`ushort`、`int`、`uint`、`long`、`ulong`、`float`、`double` 或 `decimal` |
| [char](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/char) | `ushort`、`int`、`uint`、`long`、`ulong`、`float`、`double` 或 `decimal` |
| [short](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/short) | `int`、`long`、`float`、`double` 或 `decimal`                |
| [ushort](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ushort) | `int`、`uint`、`long`、`ulong`、`float`、`double` 或 `decimal`。 |
| [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int) | `long`、`float`、`double` 或 `decimal`                       |
| [uint](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/uint) | `long`、`ulong`、`float`、`double` 或 `decimal`              |
| [long](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/long) | `float`、`double` 或 `decimal`                               |
| [ulong](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ulong) | `float`、`double` 或 `decimal`                               |
| [float](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/float) | `double`                                                     |

#### 备注

- 任何[整型类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/integral-types-table)都可以隐式转换为任何[浮点类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/floating-point-types-table)。

- 在从 `int`、`uint`、`long` 或 `ulong` 转换为 `float`，以及从 `long` 或 `ulong` 转换为 `double` 时，可能会丢失精度，但不会丢失量值。

- 不存在针对 `char`、`byte` 和 `sbyte` 类型的隐式转换。

- 不存在从 `char`、`double` 和 `decimal` 类型的隐式转换。

- `decimal` 类型和 `float` 或 `double` 类型之间不存在隐式转换。

- 类型 `int` 的常量表达式的值（例如，由整数型字面量表示的值）可以转换为 `sbyte`、`byte`、`short`、`ushort`、`uint` 或 `ulong`，前提是它在目标类型的范围内：

  C#复制

  ```csharp
  byte a = 13;    // Compiles
  byte b = 300;   // CS0031: Constant value '300' cannot be converted to a 'byte'
  ```

有关隐式转换的详细信息，请参阅 [C# 语言规范](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/index)的[隐式转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#implicit-conversions)章节。

### [Explicit numeric conversions table](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/explicit-numeric-conversions-table)

下表显示没有[隐式转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/implicit-numeric-conversions-table)的 .NET 数值类型之间的预定义显式转换。

| From                                                         | 到                                                           |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [sbyte](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/sbyte) | `byte`、`ushort`、`uint`、`ulong` 或 `char`                  |
| [byte](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/byte) | `sbyte` 或 `char`                                            |
| [short](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/short) | `sbyte`、`byte`、`ushort`、`uint`、`ulong` 或 `char`         |
| [ushort](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ushort) | `sbyte`、`byte`、`short` 或 `char`                           |
| [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int) | `sbyte`、`byte`、`short`、`ushort`、`uint`、`ulong` 或 `char` |
| [uint](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/uint) | `sbyte`、`byte`、`short`、`ushort`、`int` 或 `char`          |
| [long](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/long) | `sbyte`、`byte`、`short`、`ushort`、`int`、`uint`、`ulong` 或 `char` |
| [ulong](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ulong) | `sbyte`、`byte`、`short`、`ushort`、`int`、`uint`、`long` 或 `char` |
| [char](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/char) | `sbyte`、`byte` 或 `short`                                   |
| [float](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/float) | `sbyte`、`byte`、`short`、`ushort`、`int`、`uint`、`long`、`ulong`、`char` 或 `decimal` |
| [double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double) | `sbyte`、`byte`、`short`、`ushort`、`int`、`uint`、`long`、`ulong`、`char`、`float` 或 `decimal` |
| [decimal](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/decimal) | `sbyte`、`byte`、`short`、`ushort`、`int`、`uint`、`long`、`ulong`、`char`、`float` 或 `double` |

#### 备注

- 显式数值转换可能会导致精度降低或导致引发异常，通常为 [OverflowException](https://docs.microsoft.com/zh-cn/dotnet/api/system.overflowexception)。
- 将整数类型的值转换为另一个整数类型时，结果取决于溢出[检查上下文](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/checked-and-unchecked)。 在已检查的上下文中，如果源值在目标类型的范围内，则转换成功。 否则会引发 [OverflowException](https://docs.microsoft.com/zh-cn/dotnet/api/system.overflowexception)。 在未检查的上下文中，转换始终成功，并按如下方式进行：
  - 如果源类型大于目标类型，则通过放弃其“额外”最高有效位来截断源值。 结果会被视为目标类型的值。
  - 如果源类型小于目标类型，则源值是符号扩展或零扩展，以使其与目标类型的大小相同。 如果源类型带符号，则是符号扩展；如果源类型是无符号的，则是零扩展。 结果会被视为目标类型的值。
  - 如果源类型与目标类型的大小相同，则源值将被视为目标类型的值。
- 将 `decimal` 值转换为整型类型时，此值会向零舍入到最接近的整数值。 如果生成的整数值处于目标类型的范围之外，则会引发 [OverflowException](https://docs.microsoft.com/zh-cn/dotnet/api/system.overflowexception)。
- 将 `double` 或 `float` 值转换为整型类型时，此值会向零舍入到最接近的整数值。 如果生成的整数值处于目标类型范围之外，则结果会取决于溢出[上下文](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/checked-and-unchecked)。 在已检查的上下文中，引发 [OverflowException](https://docs.microsoft.com/zh-cn/dotnet/api/system.overflowexception)；而在未检查的上下文中，结果是目标类型的未指定值。
- 将 `double` 转换为 `float` 时，`double` 值舍入为最接近的 `float` 值。 如果 `double` 值太小或太大，无法匹配目标类型，结果将为零或无穷大。
- 将 `float` 或 `double` 转换为 `decimal` 时，源值转换为 `decimal` 表示形式，并并五入到第 28 位小数后最接近的数（如果需要）。 根据源值的值，可能出现以下结果之一：
  - 如果源值太小，无法表示为 `decimal`，结果则为零。
  - 如果源值为 NaN（非数值）、无穷大或太大而无法表示为 `decimal`，则引发 [OverflowException](https://docs.microsoft.com/zh-cn/dotnet/api/system.overflowexception)。
- 将 `decimal` 转换为 `float` 或 `double` 时，`decimal` 值舍入到最接近的 `double` 或 `float` 值。

有关显式转换的详细信息，请参阅 [C# 语言规范](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/index)的[显式转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#explicit-conversions)章节。

### [Formatting numeric results table](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/formatting-numeric-results-table)

下表显示了设置数值结果格式的受支持格式说明符。 最后一列中的格式化结果对应于“en-US”[CultureInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.globalization.cultureinfo)。

| 格式说明符 | 说明     | 示例                                                  | 结果           |
| ---------- | -------- | ----------------------------------------------------- | -------------- |
| C 或 c     | 货币     | `string s = $"{2.5:C}";`  `string s = $"{-2.5:C}";`   | $2.50  ($2.50) |
| D 或 d     | 十进制   | `string s = $"{25:D5}";`                              | 00025          |
| E 或 e     | 指数     | `string s = $"{250000:E2}";`                          | 2.50E+005      |
| F 或 f     | 定点     | `string s = $"{2.5:F2}";`  `string s = $"{2.5:F0}";`  | 2.50  3        |
| G 或 g     | 常规     | `string s = $"{2.5:G}";`                              | 2.5            |
| N 或 n     | Numeric  | `string s = $"{2500000:N}";`                          | 2,500,000.00   |
| P 或 p     | 百分比   | `string s = $"{0.25:P}";`                             | 25.00%         |
| R 或 r     | 往返过程 | `string s = $"{2.5:R}";`                              | 2.5            |
| X 或 x     | 十六进制 | `string s = $"{250:X}";`  `string s = $"{0xffff:X}";` | FA  FFFF       |

#### 备注

使用格式说明符可以创建格式字符串。 格式字符串的格式如下：`Axx`，其中

- `A` 是格式说明符，控制应用于数值的格式设置类型。
- `xx` 是精度说明符，影响格式化输出中的位数。 精度说明符值的范围为 0 到 99。

十进制（“D”或“d”）和十六进制（“X”或“x”）格式说明符仅支持用于整型类型。 往返（“R”或“r”）格式说明符仅支持用于 [Single](https://docs.microsoft.com/zh-cn/dotnet/api/system.single)、[Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double) 和 [BigInteger](https://docs.microsoft.com/zh-cn/dotnet/api/system.numerics.biginteger) 类型。

下列支持标准数字格式字符串：

- 所有数字类型的一些 `ToString` 方法重载。 例如，可以向 [Int32.ToString(String)](https://docs.microsoft.com/zh-cn/dotnet/api/system.int32.tostring#System_Int32_ToString_System_String_) 和 [Int32.ToString(String, IFormatProvider)](https://docs.microsoft.com/zh-cn/dotnet/api/system.int32.tostring#System_Int32_ToString_System_String_System_IFormatProvider_) 方法提供数字格式字符串。
- 例如，由 [String.Format](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.format) 方法提供支持的 .NET [复合格式设置功能](https://docs.microsoft.com/zh-cn/dotnet/standard/base-types/composite-formatting)。
- [内插字符串](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/tokens/interpolated).

有关详细信息，请参阅[标准数值格式字符串](https://docs.microsoft.com/zh-cn/dotnet/standard/base-types/standard-numeric-format-strings)。