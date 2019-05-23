[C# programming guide](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/index)

# Language Sections

## [Unsafe Code and Pointers](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/unsafe-code-pointers/index)

为了保持类型安全性，默认情况下，C# 不支持指针算法。 但是，通过使用 [unsafe](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/unsafe) 关键字，可以定义可在其中使用指针的不安全上下文。 有关指针的详细信息，请参阅主题[指针类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/unsafe-code-pointers/pointer-types)。

> 在公共语言运行时 (CLR) 中，不安全代码是指无法验证的代码。 C# 中的不安全代码不一定是危险的；只是 CLR 无法验证该代码的安全性。 因此，CLR 将仅执行完全信任的程序集中的不安全代码。 如果你使用不安全代码，你应该负责确保代码不会引发安全风险或指针错误。

### 不安全代码概述

不安全代码具有以下属性：

- 可将方法、类型和代码块定义为不安全。
- 在某些情况下，通过移除数组绑定检查，不安全代码可提高应用程序的性能。
- 调用需要指针的本机函数时，需使用不安全代码。
- 使用不安全代码将引发安全风险和稳定性风险。
- 为使 C# 能够编译不安全代码，必须用 [/unsafe](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/unsafe-compiler-option) 编译应用程序。

### [Fixed Size Buffers](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/unsafe-code-pointers/fixed-size-buffers)

在 C# 中，可以使用 [fixed](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/fixed-statement) 语句来创建在数据结构中具有固定大小的数组的缓冲区。 当编写与其他语言或平台的数据源进行互操作的方法时，固定大小的缓冲区很有用。 固定的数组可以采用允许用于常规结构成员的任何属性或修饰符。 唯一的限制是数组类型必须为 `bool`、`byte`、`char`、`short`、`int`, `long`、`sbyte`、`ushort`、`uint`、`ulong`、`float` 或 `double`。

```csharp
private fixed char name[30];
```

#### 备注

在安全代码中，包含数组的 C# 结构不包含该数组元素。 而该结构包含对元素的引用。 当在[不安全的](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/unsafe)代码块中使用数组时，可以在[结构](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/struct)中嵌入该固定大小的数组。

以下 `struct` 的大小为 8 字节。 `pathName` 数组是引用：

```csharp
public struct PathArray
{
    public char[] pathName;
    private int reserved;
}
```

`struct` 可以在不安全代码中包含嵌入的数组。 在下面的示例中，`fixedBuffer` 数组具有固定的大小。 使用 `fixed` 语句建立指向第一个元素的指针。 通过此指针访问数组的元素。 `fixed` 语句将 `fixedBuffer` 实例字段固定到内存中的特定位置。

```csharp
internal unsafe struct MyBuffer
{
    public fixed char fixedBuffer[128];
}

internal unsafe class MyClass
{
    public MyBuffer myBuffer = default;
}

private static void AccessEmbeddedArray()
{
    MyClass myC = new MyClass();

    unsafe
    {
        // Pin the buffer to a fixed location in memory.
        fixed (char* charPtr = myC.myBuffer.fixedBuffer)
        {
            *charPtr = 'A';
        }
        // Access safely through the index:
        char c = myC.myBuffer.fixedBuffer[0];
        Console.WriteLine(c);
        // modify through the index:
        myC.myBuffer.fixedBuffer[0] = 'B';
        Console.WriteLine(myC.myBuffer.fixedBuffer[0]);
    }

}
```

包含 128 个元素的 `char` 数组的大小为 256 个字节。 固定大小的 [char](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/char) 缓冲区每个字符始终占用两个字节，而不考虑编码。 甚至在将 char 缓冲区封送到 API 方法或具有 `CharSet = CharSet.Auto` 或 `CharSet = CharSet.Ansi` 的结构时，这也为 true。 有关更多信息，请参见[CharSet](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.interopservices.charset)。

前面的示例演示访问未固定的 `fixed` 字段，此功能从 C# 7.3 开始提供。

另一常见的固定大小的数组是 [bool](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/bool) 数组。 `bool` 数组中的元素大小始终为一个字节。 `bool` 数组不适用于创建位数组或缓冲区。

> 除了通过使用 [stackalloc](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/stackalloc) 创建的内存外，C# 编译器和公共语言运行时 (CLR) 不执行任何安全缓冲区溢出检查。 与所有不安全代码一样，请谨慎使用。

不安全的缓冲区与常规数组的区别体现在以下方面：

- 只能在不安全的上下文中使用不安全的缓冲区。
- 不安全的缓冲区始终是矢量或一维数组。
- 数组的声明应包括计数，如 `char id[8]`。 不能使用 `char id[]`。
- 在不安全的上下文中，不安全的缓冲区只能是结构的实例字段。

### [Pointer types](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/unsafe-code-pointers/pointer-types)

在不安全的上下文中，类型可以是指针类型、值类型或引用类型。 指针类型声明采用下列形式之一：

```csharp
type* identifier;
void* identifier; //allowed but not recommended
```

在指针类型中的 `*` 之前指定的类型被称为“referent 类型”。 以下任一类型均可为 referent 类型：

- 任何整型类型：[sbyte](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/sbyte)、[byte](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/byte)、[short](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/short)、[ushort](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ushort)、[int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int)、[uint](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/uint)、[long](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/long)、[ulong](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ulong)。
- 任何浮点类型：[浮点](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/float)、[双精度](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double)。
- [字符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/char)。
- [布尔型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/bool)。
- [小数](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/decimal)。
- 任何[枚举](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/enum)类型。
- 任何指针类型。 这允许如 `void**` 的表达式。
- 任何仅包含非托管类型字段的用户定义的结构类型。

指针类型不从[对象](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/object)继承，并且指针类型与 `object` 之间不存在转换。 此外，装箱和取消装箱不支持指针。 但是，你可在不同的指针类型之间以及指针类型和整型之间进行转换。

在同一个声明中声明多个指针时，星号 (*) 仅与基础类型一起写入；而不是用作每个指针名称的前缀。 例如:

```csharp
int* p1, p2, p3;   // Ok
int *p1, *p2, *p3;   // Invalid in C#
```

指针不能指向引用或包含引用的[结构](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/struct)，因为无法对对象引用进行垃圾回收，即使有指针指向它也是如此。 垃圾回收器并不跟踪是否有任何类型的指针指向对象。

`myType*` 类型的指针变量的值为 `myType` 类型的变量的地址。 下面是指针类型声明的示例：

| 示例       | 说明                             |
| ---------- | -------------------------------- |
| `int* p`   | `p` 是指向整数的指针。           |
| `int** p`  | `p` 是指向整数的指针的指针。     |
| `int*[] p` | `p` 是指向整数的指针的一维数组。 |
| `char* p`  | `p` 是指向字符的指针。           |
| `void* p`  | `p` 是指向未知类型的指针。       |

指针间接寻址运算符 * 可用于访问位于指针变量所指向的位置的内容。 例如，请考虑以下声明：

```csharp
int* myVariable;
```

表达式 `*myVariable` 表示在 `int` 中包含的地址处找到的 `myVariable` 变量。

[fixed 语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/fixed-statement)和[指针转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/unsafe-code-pointers/pointer-conversions)主题中有几个指针示例。 下面的示例使用 `unsafe` 关键字和 `fixed` 语句，并显示如何递增内部指针。 你可将此代码粘贴到控制台应用程序的 Main 函数中来运行它。 这些示例必须使用 [-unsafe](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/unsafe-compiler-option) 编译器选项集进行编译。

```csharp
// Normal pointer to an object.
int[] a = new int[5] { 10, 20, 30, 40, 50 };
// Must be in unsafe code to use interior pointers.
unsafe
{
    // Must pin object on heap so that it doesn't move while using interior pointers.
    fixed (int* p = &a[0])
    {
        // p is pinned as well as object, so create another pointer to show incrementing it.
        int* p2 = p;
        Console.WriteLine(*p2);
        // Incrementing p2 bumps the pointer by four bytes due to its type ...
        p2 += 1;
        Console.WriteLine(*p2);
        p2 += 1;
        Console.WriteLine(*p2);
        Console.WriteLine("--------");
        Console.WriteLine(*p);
        // Dereferencing p and incrementing changes the value of a[0] ...
        *p += 1;
        Console.WriteLine(*p);
        *p += 1;
        Console.WriteLine(*p);
    }
}

Console.WriteLine("--------");
Console.WriteLine(a[0]);

/*
Output:
10
20
30
--------
10
11
12
--------
12
*/
```

你无法对 `void*` 类型的指针应用间接寻址运算符。 但是，你可以使用强制转换将 void 指针转换为任何其他指针类型，反之亦然。

指针可以为 `null`。 将间接寻址运算符应用于 null 指针将导致由实现定义的行为。

在方法之间传递指针会导致未定义的行为。 考虑这种方法，该方法通过 `in`、`out` 或 `ref` 参数或作为函数结果返回一个指向局部变量的指针。 如果已在固定块中设置指针，则它指向的变量不再是固定的。

下表列出了可在不安全的上下文中对指针执行的运算符和语句：

| 运算符/语句            | 使用                         |
| ---------------------- | ---------------------------- |
| *                      | 执行指针间接寻址。           |
| ->                     | 通过指针访问结构的成员。     |
| []                     | 为指针建立索引。             |
| `&`                    | 获取变量的地址。             |
| ++ 和 --               | 递增和递减指针。             |
| + 和 -                 | 执行指针算法。               |
| ==、!=、<、>、<= 和 >= | 比较指针。                   |
| `stackalloc`           | 在堆栈上分配内存。           |
| `fixed` 语句           | 临时固定变量以便找到其地址。 |

#### [Pointer Conversions](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/unsafe-code-pointers/pointer-conversions)

下表显示预定义隐式指针转换。 隐式转换可能会在许多情况下出现（包括方法调用和赋值语句）。

##### 隐式指针转换

| From         | 到           |
| ------------ | ------------ |
| 任何指针类型 | void*        |
| null         | 任何指针类型 |

显式指针转换用于使用强制转换对不包含隐式转换的转换执行操作。 下表显示了这些转换。

##### 显式指针转换

| From                                                 | 到                                                   |
| ---------------------------------------------------- | ---------------------------------------------------- |
| 任何指针类型                                         | 其他任何指针类型                                     |
| sbyte、byte、short、ushort、int、uint、long 或 ulong | 任何指针类型                                         |
| 任何指针类型                                         | sbyte、byte、short、ushort、int、uint、long 或 ulong |

##### 示例

在下面的示例中，`int` 的指针将转换为 `byte` 的指针。 请注意，指针指向变量的最低寻址字节。 如果结果连续递增，直到达到 `int` 的大小（4 字节），可显示变量的其余字节。

```csharp
// compile with: -unsafe
```

```csharp
class ClassConvert
{
    static void Main() 
    {
        int number = 1024;

        unsafe 
        {
            // Convert to byte:
            byte* p = (byte*)&number;

            System.Console.Write("The 4 bytes of the integer:");

            // Display the 4 bytes of the int variable:
            for (int i = 0 ; i < sizeof(int) ; ++i)
            {
                System.Console.Write(" {0:X2}", *p);
                // Increment the pointer:
                p++;
            }
            System.Console.WriteLine();
            System.Console.WriteLine("The value of the integer: {0}", number);

            // Keep the console window open in debug mode.
            System.Console.WriteLine("Press any key to exit.");
            System.Console.ReadKey();
        }
    }
}
    /* Output:
        The 4 bytes of the integer: 00 04 00 00
        The value of the integer: 1024
    */
```

#### [Pointer Expressions](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/unsafe-code-pointers/pointer-expressions)

##### [How to: Obtain the Value of a Pointer Variable](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/unsafe-code-pointers/how-to-obtain-the-value-of-a-pointer-variable)

使用指针间接寻址运算符在指针指向的位置获取变量。 表达式采用以下形式，其中 `p` 为指针类型：

```c#
*p;  
```

不能对指针类型外的任何类型的表达式使用一元间接寻址运算符。 此外，不能将其应用于 [void](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/void) 指针。

将间接寻址运算符应用于 [null](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/null) 指针时，结果具体取决于实现。

###### 示例

在下面的示例中，`char` 类型的变量可通过使用另一类型的指针进行访问。 请注意，`theChar` 地址将随着每次运行有所不同，因为分配给变量的物理地址可变。

```csharp
// compile with: -unsafe
```

```csharp
unsafe class TestClass
{
    static void Main()
    {
        char theChar = 'Z';
        char* pChar = &theChar;
        void* pVoid = pChar;
        int* pInt = (int*)pVoid;

        System.Console.WriteLine("Value of theChar = {0}", theChar);
        System.Console.WriteLine("Address of theChar = {0:X2}",(int)pChar);
        System.Console.WriteLine("Value of pChar = {0}", *pChar);
        System.Console.WriteLine("Value of pInt = {0}", *pInt);
    }
}
```

**Value of theChar = Z** **Address of theChar = 12F718** **Value of pChar = Z** **Value of pInt = 90**

##### [How to: Obtain the Address of a Variable](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/unsafe-code-pointers/how-to-obtain-the-address-of-a-variable)

若要获取计算结果为固定变量的一元表达式的地址，请使用 address-of 运算符 `&`：

```csharp
int number;  
int* p = &number; //address-of operator &  
```

address-of 运算符只适用于变量。 如果变量是可移动变量，则可以使用[固定语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/fixed-statement)临时固定变量，再获取其地址。

由你负责确保变量已初始化。 如果未初始化变量，编译器不会发出错误消息。

你也无法获取常量或值的地址。

###### 示例

在此示例中，已声明一个指向 `int` 和 `p` 的指针，并向其赋予了整型变量 `number` 的地址。 向 `*p` 赋值后导致初始化变量 `number`。 如果向此赋值语句添加注释，将删除变量 `number` 的初始化，但不会产生任何编译时错误。

>  使用 [`-unsafe`](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/unsafe-compiler-option) 编译器选项编译此示例。

```csharp
class AddressOfOperator
{
    static void Main()
    {
        int number;

        unsafe 
        {
            // Assign the address of number to a pointer:
            int* p = &number;

            // Commenting the following statement will remove the
            // initialization of number.
            *p = 0xffff;

            // Print the value of *p:
            System.Console.WriteLine("Value at the location pointed to by p: {0:X}", *p);

            // Print the address stored in p:
            System.Console.WriteLine("The address stored in p: {0}", (int)p);
        }

        // Print the value of the variable number:
        System.Console.WriteLine("Value of the variable number: {0:X}", number);

        System.Console.ReadKey();
    }
}
/* Output:
        Value at the location pointed to by p: FFFF
        The address stored in p: 2420904
        Value of the variable number: FFFF
*/
```

##### [How to: Access a Member with a Pointer](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/unsafe-code-pointers/how-to-access-a-member-with-a-pointer)

若要访问不安全上下文中声明的结构成员，可使用成员访问运算符，如以下示例所示，其中 `p` 是包含成员 `x` 的 [struct](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/struct) 的指针。

```c#
CoOrds* p = &home;  
p -> x = 25; //member access operator ->  
```

###### 示例

此示例中，对包含 `x` 和 `y` 两个坐标的 [struct](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/struct) `CoOrds` 进行了声明和实例化。 通过使用成员访问运算符 `->` 和实例 `home` 的指针，为 `x` 和 `y` 赋值。

> 请注意，表达式 `p->x` 等效于表达式 `(*p).x`，使用这两个表达式中任何一个获得的结果相同。

```csharp
// compile with: -unsafe
```

```csharp
struct CoOrds
{
    public int x;
    public int y;
}

class AccessMembers
{
    static void Main() 
    {
        CoOrds home;

        unsafe 
        {
            CoOrds* p = &home;
            p->x = 25;
            p->y = 12;

            System.Console.WriteLine("The coordinates are: x={0}, y={1}", p->x, p->y );
        }
    }
}
```

##### [How to: Access an Array Element with a Pointer](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/unsafe-code-pointers/how-to-access-an-array-element-with-a-pointer)

在不安全的上下文中，可通过指针元素访问来访问内存中的元素，如下方示例所示：

```csharp
char* charPointer = stackalloc char[123];
for (int i = 65; i < 123; i++)
{
    charPointer[i] = (char)i; //access array elements
}
```

方括号中的表达式必须可隐式转换为 `int`、`uint`、`long` 或 `ulong`。 `p[e]` 操作等效于 `*(p+e)`。 与 C 和 C++ 一样，指针元素访问不检查越界错误。

###### 示例

此示例中，向字符数组 `charPointer` 分配了 123 个内存位置。 此数组用于显示两个 [for](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/for) 循环中的小写字母和大写字母。

请注意，表达式 `charPointer[i]` 等效于表达式 `*(charPointer + i)`，使用这两个表达式中任何一个获得的结果相同。

```csharp
// compile with: -unsafe
```

```csharp
class Pointers
{
    unsafe static void Main() 
    {
        char* charPointer = stackalloc char[123];

        for (int i = 65; i < 123; i++)
        {
            charPointer[i] = (char)i;
        }

        // Print uppercase letters:
        System.Console.WriteLine("Uppercase letters:");
        for (int i = 65; i < 91; i++)
        {
            System.Console.Write(charPointer[i]);
        }
        System.Console.WriteLine();

        // Print lowercase letters:
        System.Console.WriteLine("Lowercase letters:");
        for (int i = 97; i < 123; i++)
        {
            System.Console.Write(charPointer[i]);
        }
    }
}
```

大写字母：
ABCDEFGHIJKLMNOPQRSTUVWXYZ
小写字母：
abcdefghijklmnopqrstuvwxyz

##### [Manipulating Pointers](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/unsafe-code-pointers/manipulating-pointers)

###### [How to: Increment and Decrement Pointers](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/unsafe-code-pointers/how-to-increment-and-decrement-pointers)

使用增量运算符 (`++`) 和减量运算符 (`--`)，通过 `pointer-type*` 类型指针的 `sizeof(pointer-type)` 更改指针位置。 增量和减量表达式的形式如下：

```csharp
++p;  
p++;  
--p;  
p--;  
```

增量和减量运算符可应用于除 `void*` 类型以外的任何类型的指针。

对 `pointer-type*` 类型的指针应用增量运算符的效果是向指针变量中包含的地址增加 `sizeof(pointer-type)`。

对 `pointer-type*` 类型的指针应用减量运算符的效果是从指针变量中包含的地址减去 `sizeof(pointer-type)`。

运算溢出指针范围时，不会产生异常，并且结果取决于实现。

在此示例中，通过按 `int` 大小递增指针单步调试数组。 每一步都将显示数组元素的地址和内容。

```csharp
// compile with: -unsafe
```

```csharp
class IncrDecr
{
    unsafe static void Main()
    {
        int[] numbers = {0,1,2,3,4};

        // Assign the array address to the pointer:
        fixed (int* p1 = numbers)
        {
            // Step through the array elements:
            for(int* p2=p1; p2<p1+numbers.Length; p2++)
            {
                System.Console.WriteLine("Value:{0} @ Address:{1}", *p2, (long)p2);
            }
        }
    }
}
```

**Value:0 @ Address:12860272** **Value:1 @ Address:12860276** **Value:2 @ Address:12860280** **Value:3 @ Address:12860284** **Value:4 @ Address:12860288**

###### [Arithmetic Operations on Pointers](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/unsafe-code-pointers/arithmetic-operations-on-pointers)

本主题讨论如何使用算术运算符 `+` 和 `-` 操作指针。

>  不能对 void 指针执行任何算术运算。

- 对指针执行加减数值操作

可以将类型为 [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int)、[uint](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/uint)、[long](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/long) 或 [ulong](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ulong) 的值 `n` 与指针相加。 如果 `p` 是 `pointer-type*` 类型的指针，`p+n` 结果是将 `n * sizeof(pointer-type)` 添加到 `p` 的地址所产生的指针。 同样，`p-n` 是从 `p` 的地址中减去 `n * sizeof(pointer-type)` 得到的指针。

- 指针相减

也可以对相同类型的指针进行减法运算。 计算结果的类型始终为 `long`。 例如，如果 `p1` 和 `p2` 都是类型为 `pointer-type*` 的指针，则表达式 `p1-p2` 的计算结果为：

```c#
((long)p1 - (long)p2)/sizeof(pointer-type)
```

当算术运算溢出指针范围时，不会产生异常，并且结果取决于实现。

- 示例

```csharp
// compile with: -unsafe
```

```csharp
class PointerArithmetic
{
    unsafe static void Main() 
    {
        int* memory = stackalloc int[30];
        long difference;
        int* p1 = &memory[4];
        int* p2 = &memory[10];

        difference = p2 - p1;

        System.Console.WriteLine("The difference is: {0}", difference);
    }
}
// Output:  The difference is: 6
```

###### [Pointer Comparison](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/unsafe-code-pointers/pointer-comparison)

可以应用以下运算符比较任何类型的指针：

**== != < > <= >=**

比较运算符比较两个操作数的地址，如同它们是无符号整数。

- 示例

```csharp
// compile with: -unsafe
```

```csharp
class CompareOperators
{
    unsafe static void Main() 
    {
        int x = 234;
        int y = 236;
        int* p1 = &x;
        int* p2 = &y;

        System.Console.WriteLine(p1 < p2);
        System.Console.WriteLine(p2 < p1);
    }
}
```

- 示例输出

```c#
True
False
```

#### [How to: Use Pointers to Copy an Array of Bytes](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/unsafe-code-pointers/how-to-use-pointers-to-copy-an-array-of-bytes)

下面的示例使用指针将字节从一个数组复制到另一个数组。

此示例使用 [unsafe](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/unsafe) 关键字，使你可以在 `Copy` 方法中使用指针。 [fixed](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/fixed-statement) 语句用于声明指向源数组和目标数组的指针。 `fixed` 语句将源数组和目标数组的位置固定在内存中，以便它们不会被垃圾回收所移动。 当完成 `fixed` 块后，将取消固定数组的内存块。 因为此示例中的 `Copy` 方法使用 `unsafe` 关键字，所以必须使用 [-unsafe](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/unsafe-compiler-option) 编译器选项对其进行编译。

此示例使用索引而非第二个非托管的指针访问这两个数组的元素。 `pSource` 和 `pTarget` 指针的声明固定数组。从 C# 7.3 开始可以使用此功能。

##### 示例

```csharp
static unsafe void Copy(byte[] source, int sourceOffset, byte[] target,
    int targetOffset, int count)
{
    // If either array is not instantiated, you cannot complete the copy.
    if ((source == null) || (target == null))
    {
        throw new System.ArgumentException();
    }

    // If either offset, or the number of bytes to copy, is negative, you
    // cannot complete the copy.
    if ((sourceOffset < 0) || (targetOffset < 0) || (count < 0))
    {
        throw new System.ArgumentException();
    }

    // If the number of bytes from the offset to the end of the array is 
    // less than the number of bytes you want to copy, you cannot complete
    // the copy. 
    if ((source.Length - sourceOffset < count) ||
        (target.Length - targetOffset < count))
    {
        throw new System.ArgumentException();
    }

    // The following fixed statement pins the location of the source and
    // target objects in memory so that they will not be moved by garbage
    // collection.
    fixed (byte* pSource = source, pTarget = target)
    {
        // Copy the specified number of bytes from source to target.
        for (int i = 0; i < count; i++)
        {
            pTarget[targetOffset + i] = pSource[sourceOffset + i];
        }
    }
}

static void UnsafeCopyArrays()
{
    // Create two arrays of the same length.
    int length = 100;
    byte[] byteArray1 = new byte[length];
    byte[] byteArray2 = new byte[length];

    // Fill byteArray1 with 0 - 99.
    for (int i = 0; i < length; ++i)
    {
        byteArray1[i] = (byte)i;
    }

    // Display the first 10 elements in byteArray1.
    System.Console.WriteLine("The first 10 elements of the original are:");
    for (int i = 0; i < 10; ++i)
    {
        System.Console.Write(byteArray1[i] + " ");
    }
    System.Console.WriteLine("\n");

    // Copy the contents of byteArray1 to byteArray2.
    Copy(byteArray1, 0, byteArray2, 0, length);

    // Display the first 10 elements in the copy, byteArray2.
    System.Console.WriteLine("The first 10 elements of the copy are:");
    for (int i = 0; i < 10; ++i)
    {
        System.Console.Write(byteArray2[i] + " ");
    }
    System.Console.WriteLine("\n");

    // Copy the contents of the last 10 elements of byteArray1 to the 
    // beginning of byteArray2.
    // The offset specifies where the copying begins in the source array.
    int offset = length - 10;
    Copy(byteArray1, offset, byteArray2, 0, length - offset);

    // Display the first 10 elements in the copy, byteArray2.
    System.Console.WriteLine("The first 10 elements of the copy are:");
    for (int i = 0; i < 10; ++i)
    {
        System.Console.Write(byteArray2[i] + " ");
    }
    System.Console.WriteLine("\n");
    /* Output:
        The first 10 elements of the original are:
        0 1 2 3 4 5 6 7 8 9

        The first 10 elements of the copy are:
        0 1 2 3 4 5 6 7 8 9

        The first 10 elements of the copy are:
        90 91 92 93 94 95 96 97 98 99
    */
}
```