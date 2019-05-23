# [C# Operators](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/)

C# 提供了许多运算符，这些运算符是指定要在表达式中执行哪些操作（数学、索引、函数调用等等）的符号。可以[重载](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/overloadable-operators)许多应用于用户定义类型的运算符，从而更改其含义。

对整数类型执行的运算（如 `==`、`!=`、`<`、`>`、`&`、`|`）通常也可对枚举 (`enum`) 类型执行。

以下章节按最高优先级到最低优先级的顺序列示 C# 运算符。 各章节内运算符的优先级相同。

## 主要运算符

以下是具有最高优先级的运算符。

[x.y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/member-access-operator)：成员访问。

[x?.y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/null-conditional-operators)：null 条件成员访问。 如果左操作数计算结果为 `null`，则返回 `null`。

[`x?[y]`](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/null-conditional-operators)：null 条件索引访问。 如果左操作数计算结果为 `null`，则返回 `null`。

[f(x)](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/invocation-operator)：函数调用。

[a[x\]](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/index-operator)：聚合对象索引。

[x++](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/increment-operator)：后缀递增。 先返回 x 值，然后用加 1（通常加整数 1）后的 x 值更新存储位置。

[x--](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/decrement-operator)：后缀递减。 先返回 x 值，然后用减 1（通常减整数 1）后的 x 值更新存储位置。

[new](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/new-operator)：类型实例化。

[typeof](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/typeof) - 返回表示操作数的 [Type](https://docs.microsoft.com/zh-cn/dotnet/api/system.type) 对象。

[checked](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/checked)：对整数运算启用溢出检查。

[unchecked](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/unchecked)：对整数运算禁用溢出检查。 这是默认的编译器行为。

[default(T)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/default-value-expressions) - 生成类型 T 的默认值。

[delegate](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/anonymous-methods)：声明并返回委托实例。

[sizeof](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/sizeof)：返回类型操作数的大小（以字节为单位）。

[->](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/dereference-operator)：指针取消引用与成员访问相结合。

## 一元运算符

这些运算符的优先级比下一章节高，比上一章节低。

[+x](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/addition-operator)：返回 x 的值。

[-x](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/subtraction-operator)：数值取反。

[!x](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/logical-negation-operator)：逻辑取反。

[~x](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/bitwise-complement-operator)：按位求补。

[++x](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/increment-operator)：前缀递增。 先用加 1（通常加整数 1）后的 x 值更新存储位置，然后返回 x 值。

[--x](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/decrement-operator)：前缀递减。 先用减 1（通常减整数 1）后的 x 值更新存储位置，然后返回 x 值。

[(T)x](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/invocation-operator)：类型显式转换。

[await](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/await)：等待 `Task`。

[&x](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/and-operator)：地址。

[*x](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/multiplication-operator)：取消引用。

## 乘法运算符

这些运算符的优先级比下一章节高，比上一章节低。

[x * y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/multiplication-operator)：乘法。

[x / y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/division-operator)：除法。 如果操作数均为整数，则结果为整数，舍去小数（例如，`-7 / 2 is -3`）。

[x % y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/remainder-operator)：余数。 如果操作数均为整数，则返回 x 除以 y 后的余数。 如果 `q = x / y` 且 `r = x % y`，则 `x = q * y + r`。

## 相加运算符

这些运算符的优先级比下一章节高，比上一章节低。

[x + y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/addition-operator)：加法。

[x - y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/subtraction-operator)：减法。

## 移位运算符

这些运算符的优先级比下一章节高，比上一章节低。

[x << y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/left-shift-operator)：左移位，右侧用 0 填充。

[x >> y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/right-shift-operator)：右移位。 如果左操作数是 `int` 或 `long`，则左位数补符号位。 如果左操作数是 `uint` 或 `ulong`，则左位数补零。

## 关系和类型测试运算符

这些运算符的优先级比下一章节高，比上一章节低。

[x < y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/less-than-operator)：小于（如果 x 小于 y，则为 true）。

[x > y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/greater-than-operator)：大于（如果 x 大于 y，则为 true）。

[x <= y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/less-than-equal-operator)：小于或等于。

[x >= y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/greater-than-equal-operator)：大于或等于。

[is](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/is)：类型兼容性。 如果求值后的左操作数可以转换为右操作数中指定的类型（静态类型），则返回 true。

[as](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/as)：类型转换。 返回左操作数并转换为右操作数中指定的类型（静态类型），但 `as` 返回 `null`，其中 `(T)x`会引发异常。

## 相等运算符

这些运算符的优先级比下一章节高，比上一章节低。

[x == y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/equality-comparison-operator)：相等。 默认情况下，对于 `string` 以外的引用类型，此运算符返回引用相等（标识测试）。 但是，类型可以重载 `==`，因此，如果你想测试标识，最好对 `object` 使用 `ReferenceEquals` 方法。

[x != y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/not-equal-operator)：不相等。 请参阅有关 `==` 的注释。 如果某个类型重载 `==`，则它必须重载 `!=`。

## 逻辑 AND 运算符

此运算符的优先级比下一章节高，比上一章节低。

[x & y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/and-operator)：逻辑或位 AND。 通常可以将此运算符与整数类型和 `enum` 类型一起使用。

## 辑 XOR 运算

此运算符的优先级比下一章节高，比上一章节低。

[x ^ y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/xor-operator)：逻辑或位 XOR。 通常可以将此运算符与整数类型和 `enum` 类型一起使用。

## 逻辑 OR 运算符

此运算符的优先级比下一章节高，比上一章节低。

[x | y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/or-operator)：逻辑或位 OR。 通常可以将此运算符与整数类型和 `enum` 类型一起使用。

## 条件 AND 运算符

此运算符的优先级比下一章节高，比上一章节低。

[x && y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/conditional-and-operator)：逻辑 AND。 如果第一个操作数计算结果为 false，则 C# 不对第二个操作数求值。

## 条件 OR 运算符

此运算符的优先级比下一章节高，比上一章节低。

[x || y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/conditional-or-operator)：逻辑 OR。 如果第一个操作数计算结果为 true，则 C# 不对第二个操作数求值。

## Null 合并运算符

此运算符的优先级比下一章节高，比上一章节低。

[x ?? y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/null-coalescing-operator)：如果不为 `null`，则返回 `x`；否则返回 `y`。

## 条件运算符

此运算符的优先级比下一章节高，比上一章节低。

[t ? x : y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/conditional-operator) - 如果测试 `t` 计算结果为 true，则计算并返回 `x`；否则，计算并返回 `y`。

## 赋值和 Lambda 运算符

这些运算符的优先级比下一章节高，比上一章节低。

[x = y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/assignment-operator)：赋值。

[x += y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/addition-assignment-operator)：递增。 `x` 值加 `y` 值，结果存储在 `x` 中，并返回新值。 如果 `x` 指定 `event`，则 `y` 必须是 C# 作为事件处理程序添加的相应函数。

[x -= y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/subtraction-assignment-operator)：递减。 `x` 值减 `y` 值，结果存储在 `x` 中，并返回新值。 如果 `x` 指定 `event`，则 `y` 必须是 C# 作为事件处理程序删除的相应函数

[x *= y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/multiplication-assignment-operator)：乘法赋值。 `x` 值乘以 `y` 值，结果存储在 `x` 中，并返回新值。

[x /= y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/division-assignment-operator)：除法赋值。 `x` 值除以 `y` 值，结果存储在 `x` 中，并返回新值。

[x %= y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/remainder-assignment-operator)：余数赋值。 `x` 值除以 `y` 值，余数存储在 `x` 中，并返回新值。

[x &= y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/and-assignment-operator)：AND 赋值。 `y` 值和 `x` 值相与，结果存储在 `x` 中，并返回新值。

[x |= y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/or-assignment-operator)：OR 赋值。 `y` 值和 `x` 值相或，结果存储在 `x` 中，并返回新值。

[x ^= y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/xor-assignment-operator)：XOR 赋值。 `y` 值和 `x` 值相异或，结果存储在 `x` 中，并返回新值。

[x <<= y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/left-shift-assignment-operator)：左移赋值。 将 `x` 值向左移动 `y` 位，结果存储在 `x` 中，并返回新值。

[x >>= y](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/right-shift-assignment-operator)：右移赋值。 将 `x` 值向右移动 `y` 位，结果存储在 `x` 中，并返回新值。

[=>](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/lambda-operator)：lambda 声明。

## 算术溢出

算术运算符（[+](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/addition-operator)、[-](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/subtraction-operator)、[*](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/multiplication-operator)、[/](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/division-operator)）的计算结果可能会超出所涉数值类型的可取值范围。 详细信息应参考特定运算符的相关章节，而一般情况下：

- 整数算术溢出或者引发 [OverflowException](https://docs.microsoft.com/zh-cn/dotnet/api/system.overflowexception)，或者放弃结果的最高有效位。 整数被零除总是引发 [DivideByZeroException](https://docs.microsoft.com/zh-cn/dotnet/api/system.dividebyzeroexception)。

  发生整数溢出时，具体影响视执行上下文而定，上下文可为 [checked 或 unchecked](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/checked-and-unchecked)。 在 checked 上下文中引发 [OverflowException](https://docs.microsoft.com/zh-cn/dotnet/api/system.overflowexception)。 在 unchecked 上下文中，放弃结果的最高有效位并继续执行。 因此，C# 让你有机会选择处理或忽略溢出。 默认情况下，算术运算发生在 *unchecked* 上下文中。

  除算术运算以外，整型类型之间的显式转换也会导致溢出（例如，将 [long](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/long) 显式转换成 [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int)），并受到 checked 或 unchecked 执行的约束。 但是，位运算符和移位运算符永远不会导致溢出。

- 浮点算术溢出或被零除从不引发异常，因为浮点类型基于 IEEE 754，因此可以表示无穷大和 NaN（非数值）。

- [小数](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/decimal)算术溢出总是引发 [OverflowException](https://docs.microsoft.com/zh-cn/dotnet/api/system.overflowexception)。 小数被零除总是引发 [DivideByZeroException](https://docs.microsoft.com/zh-cn/dotnet/api/system.dividebyzeroexception)。

## [[] Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/index-operator)

方括号 `[]` 通常用于数组、索引器或指针元素访问。

有关指针元素访问的详细信息，请参阅[如何：通过指针访问数组元素](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/unsafe-code-pointers/how-to-access-an-array-element-with-a-pointer)。

方括号还用于指定[属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/attributes/index)：

```csharp
[System.Diagnostics.Conditional("DEBUG")]
void TraceMethod() {}
```

### 数组访问

下面的示例演示如何访问数组元素：

```csharp
int[] fib = new int[10];
fib[0] = fib[1] = 1;
for (int i = 2; i < fib.Length; i++)
{
    fib[i] = fib[i - 1] + fib[i - 2];
}
Console.WriteLine(fib[fib.Length - 1]);  // output: 55

double[,] matrix = new double[2,2];
matrix[0,0] = 1.0;
matrix[0,1] = 2.0;
matrix[1,0] = matrix[1,1] = 3.0;
var determinant = matrix[0,0] * matrix[1,1] - matrix[1,0] * matrix[0,1];
Console.WriteLine(determinant);  // output: -3
```

如果数组索引超出数组相应维度的边界，将引发 [IndexOutOfRangeException](https://docs.microsoft.com/zh-cn/dotnet/api/system.indexoutofrangeexception)。

如前面的示例所示，还可以在声明数组类型和实例化数组实例时使用方括号。

有关数组的详细信息，请参阅[数组](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/arrays/index)。

### 索引器访问

下面的示例使用 .NET [Dictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.dictionary-2)类型来演示索引器访问：

```csharp
var dict = new Dictionary<string, double>();
dict["one"] = 1;
dict["pi"] = Math.PI;
Console.WriteLine(dict["one"] + dict["pi"]);
```

使用索引器，可通过类似于编制数组索引的方式对用户定义类型的实例编制索引。 与必须是整数的数组索引不同，可以将索引器参数声明为任何类型。

有关索引器的详细信息，请参阅[索引器](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/indexers/index)。

### 运算符可重载性

元素访问 `[]` 不被视为可重载运算符。 使用[索引器](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/indexers/index)以支持对用户定义的类型编制索引。

## [() Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/invocation-operator)

括号 `()` 通常用于方法或委托调用或用于强制转换表达式。

此外可以使用括号来指定表达式中计算操作的顺序。 有关详细信息，请参阅[运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/operators)一文中的[添加括号](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/operators#adding-parentheses)部分。 对于按优先级排序的运算符列表，请参阅 [C# 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/index)。

### 方法调用

下面的示例演示如何调用方法（带或不带参数）和委托：

```csharp
Action<int> display = s => Console.WriteLine(s);

var numbers = new List<int>();
numbers.Add(10);
numbers.Add(17);
display(numbers.Count);   // output: 2

numbers.Clear();
display(numbers.Count);   // output: 0
```

在调用带 [`new`](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/new-operator) 运算符的[构造函数](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/constructors)时，还可以使用括号。

有关这些方法的详细信息，请参阅[方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/methods)。 有关委托的详细信息，请参阅[委托](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/delegates/index)。

### 强制转换表达式

`(T)E` 形式的强制转换表达式调用转换运算符以将表达式 `E` 的值转换为类型 `T`。 如果不存在从类型 `E` 到类型 `T` 的显式转换，则发生编译时错误。 有关如何定义转换运算符的信息，请参阅[显式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/explicit)和[隐式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/implicit)关键字文章。

下面的示例演示了数值类型之间的类型转换：

```csharp
double x = 1234.7;
int a = (int)x;
Console.WriteLine(a);   // output: 1234
```

若要详细了解数值类型之间的预定义显式转换，请参阅[显式数值转换表](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/explicit-numeric-conversions-table)。

有关详细信息，请参阅[强制转换和类型转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/types/casting-and-type-conversions)以及[转换运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/conversion-operators)。

### 运算符可重载性

不能重载 `()` 运算符。

## [. Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/member-access-operator)

点运算符 (`.`) 用于成员访问。 点运算符指定类型或命名空间的成员。 例如，点运算符用于访问 .NET Framework 类库中的特定方法：

C#复制

```csharp
// The class Console in namespace System:
System.Console.WriteLine("hello");
```

例如，请考虑以下类：

C#复制

```csharp
class Simple
{
    public int a;
    public void b()
    {
    }
}
```

C#复制

```csharp
Simple s = new Simple();
```

变量 `s` 具有两个成员（`a` 和 `b`）；若要对其进行访问，请使用点运算符：

C#复制

```csharp
s.a = 6;   // assign to field a;
s.b();     // invoke member function b;
```

点还用于构成限定名称，即为指定它们所属的命名空间或接口等的名称。

C#复制

```csharp
// The class Console in namespace System:
System.Console.WriteLine("hello");
```

using 指令使某些名称限定变成可选：

C#复制

```csharp
namespace ExampleNS
{
    using System;
    class C
    {
        void M()
        {
            System.Console.WriteLine("hello");
            Console.WriteLine("hello");   // Same as previous line.
        }
    }
}
```

但如果标识符不明确，则必须对其进行限定：

C#复制

```csharp
namespace Example2
{
    class Console
    {
        public static void WriteLine(string s){}
    }
}
namespace Example1
{
    using System;
    using Example2;
    class C
    {
        void M()
        {                
            // Console.WriteLine("hello");   // Compiler error. Ambiguous reference.
            System.Console.WriteLine("hello"); //OK
            Example2.Console.WriteLine("hello"); //OK
        }
    }
}
```

## [?. and ?[] Operators](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/null-conditional-operators)

执行成员访问 (`?.`) 或索引 (`?[]`) 操作之前，测试左侧操作数的值为 null，如果左侧操作数计算结果为 `null`，则返回 `null`。

这些运算符可帮助编写更少的代码来处理 null 检查，尤其是对于下降到数据结构。

C#复制

```csharp
int? length = customers?.Length; // null if customers is null
Customer first = customers?[0];  // null if customers is null
int? count = customers?[0]?.Orders?.Count();  // null if customers, the first customer, or Orders is null
```

NULL 条件运算符采用最小化求值策略。 如果条件成员访问和索引操作链中的某个操作返回 NULL，则该链其余部分的执行将停止。 在下面的示例中，如果 `A`、`B` 或 `C` 的计算结果为 NULL，就不会执行 `E`。

C#复制

```csharp
A?.B?.C?.Do(E);
A?.B?.C?[E];
```

NULL 条件成员访问的另一个用途是使用非常少的代码以线程安全的方式调用委托。 旧方法需要如下所示的代码：

C#复制

```csharp
var handler = this.PropertyChanged;
if (handler != null)
    handler(…);
```

新的方法是要简单得多：

C#复制

```csharp
PropertyChanged?.Invoke(…)
```

新方法是线程安全的，因为编译器生成的代码仅评估 `PropertyChanged` 一次，从而使结果保持在临时变量中。 你需要显式调用 `Invoke` 方法，因为不存在 NULL 条件委托调用语法 `PropertyChanged?(e)`。

## [:: Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/namespace-alias-qualifer)

命名空间别名限定符（`::`）用于查找标识符。 它始终位于两个标识符之间，如本示例所示：

C#复制

```csharp
global::System.Console.WriteLine("Hello World");
```

`::` 运算符也可以用于 using alias 指令：

C#复制

```csharp
// using Col=System.Collections.Generic;
var numbers = new Col::List<int> { 1, 2, 3 };
```

命名空间别名限定符可以为 `global`。 这将调用全局命名空间（而不是别名命名空间）中的查找。

有关如何使用 `::` 运算符的示例，请参阅以下部分：

- [如何：使用全局命名空间别名](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/namespaces/how-to-use-the-global-namespace-alias)

## [+ Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/addition-operator)

以下两种形式支持 `+` 运算符：一元加运算符或二元加运算符。

### 一元加运算符

一元 `+` 运算符返回其操作数的值。 它受所有数值类型支持。

### 数值加

对于数字类型，`+` 运算符计算其操作数的和：

```csharp
Console.WriteLine(5 + 4);       // output: 9
Console.WriteLine(5 + 4.3);     // output: 9.3
Console.WriteLine(5.1m + 4.2m); // output: 9.3
```

### 字符串串联

当其中的一个操作数是[字符串](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/string)类型或两个操作数都是字符串类型时，`+` 运算符将其操作数的字符串表示形式串联在一起：

```csharp
Console.WriteLine("Forgot " + " white space");
Console.WriteLine("Probably the oldest constant: " + Math.PI);
// Output:
// Forgot white space
// Probably the oldest constant: 3.14159265358979
```

从 C# 6 开始，[字符串内插](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/tokens/interpolated)提供了格式化字符串的更便捷方式：

```csharp
Console.WriteLine($"Probably the oldest constant: {Math.PI:F2}");
// Output:
// Probably the oldest constant: 3.14
```

### 委托组合

对于[委托](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/delegate)类型，`+` 运算符在调用时返回新的委托实例，调用第一个操作数，然后调用第二个操作数。 如果任何操作数均为 `null`，则 `+` 运算符将返回另一个操作数（也可能是 `null`）的值。 下面的示例演示如何组合使用委托和 `+` 运算符：

```csharp
Action<int> printDouble = (int s) => Console.WriteLine(2 * s);
Action<int> printTriple = (int s) => Console.WriteLine(3 * s);
Action<int> combined = printDouble + printTriple;
combined(5);
// Output:
// 10
// 15
```

有关委托类型的详细信息，请参阅[委托](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/delegates/index)。

### 运算符可重载性

用户定义的类型可以[重载](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator)一元和二元 `+` 运算符。 重载二元 `+` 运算符后，也会隐式重载[加法赋值运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/addition-assignment-operator) `+=`。

## [- Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/subtraction-operator)

`-` 运算符既可作为一元运算符也可作为二元运算符。

为所有数值类型预定义了一元 `-` 运算符。 对数值类型进行一元 `-` 运算的结果是操作数的数值求反运算。

针对所有数值和枚举类型预定义二元 `-` 运算符，从第一个操作数中减去第一个操作数。

委托类型也提供二元 `-` 运算符，该运算符执行委托移除。

用户定义的类型可重载一元 `-` 运算符和二元 `-` 运算符。 有关详细信息，请参阅[运算符关键字](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator)。

```csharp
class MinusLinus
{
    static void Main()
    {
        int a = 5;
        Console.WriteLine(-a);
        Console.WriteLine(a - 1);
        Console.WriteLine(a - .5);
    }
}
/*
Output:
-5
4
4.5
*/
```

## [* Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/multiplication-operator)

乘法运算符 (`*`) 计算操作数的乘积。 所有数值类型都具有预定义的乘法运算符。

`*` 还用作取消引用运算符，用于对指针执行读取和写入操作。

### 备注

`*` 运算符还用于声明指针类型和取消引用指针。 此运算符仅可用于不安全的上下文，通过使用 [unsafe](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/unsafe) 关键字表示，且需要 [/unsafe](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/unsafe-compiler-option) 编译器选项。 取消引用运算符也称为间接寻址运算符。

用户定义的类型可以重载二元 `*` 运算符（请参阅[运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator)）。 重载二元运算符时，也会隐式重载相应的赋值运算符（若有）。

### 示例

```csharp
class Multiply
{
    static void Main() 
    {
        Console.WriteLine(5 * 2);
        Console.WriteLine(-.5 * .2);
        Console.WriteLine(-.5m * .2m); // decimal type
    }
}
    /*
Output
    10
    -0.1
    -0.10
*/
```

### 示例

```csharp
public class Pointer
{
    unsafe static void Main()
    {
        int i = 5;
        int* j = &i;
        System.Console.WriteLine(*j);
    }
}
/*
Output:
5
*/
```

## [/ Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/division-operator)

除法运算符 `/` 用它的第一个操作数除以第二个操作数。 所有数值类型都支持除法运算符。

### 整数除法

对于整数类型的操作数，`/` 运算符的结果为整数类型，并且等于两个操作数之商向零舍入后的结果：

```csharp
Console.WriteLine(13 / 5);    // output: 2
Console.WriteLine(-13 / 5);   // output: -2
Console.WriteLine(13 / -5);   // output: -2
Console.WriteLine(-13 / -5);  // output: 2
```

若要获取浮点数形式的两个操作数之商，请使用 `float`、`double` 或 `decimal` 类型：

```csharp
Console.WriteLine(13 / 5.0);       // output: 2.6

int a = 13;
int b = 5;
Console.WriteLine((double)a / b);  // output: 2.6
```

### 浮点除法

对于 `float`、`double` 和 `decimal` 类型，`/` 运算符的结果为两个操作数之商：

```csharp
Console.WriteLine(16.8f / 4.1f);
Console.WriteLine(16.8d / 4.1d);
Console.WriteLine(16.8m / 4.1m);
// Output:
// 4.097561
// 4.09756097560976
// 4.0975609756097560975609756098
```

如果操作数之一为 `decimal`，那么另一个操作数不得为 `float` 和 `double`，因为 `float` 和 `double` 都无法隐式转换为 `decimal`。 必须将 `float` 或 `double` 操作数显式转换为 `decimal` 类型。 若要详细了解数值类型之间的隐式转换，请参阅[隐式数值转换表](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/implicit-numeric-conversions-table)。

### 运算符可重载性

用户定义的类型可以[重载](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator) `/` 运算符。 在 `/` 运算符重载后，[除法赋值运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/division-assignment-operator) `/=` 也会隐式重载。

## [% Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/modulus-operator)

余数运算符 `%` 计算第一个操作数除以第二个操作数后的余数。

用户定义的类型可以[重载](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator) `%` 运算符。 当 `%` 重载时，[余数赋值运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/remainder-assignment-operator) `%=` 也会隐式重载。

所有数值类型都支持余数运算符。

### 整数余数

对于整数操作数，`a % b` 的结果是由 `a - (a / b) * b` 生成的值。 非零余数的符号与第一个操作数的符号相同，如下例所示：

```csharp
Console.WriteLine(5 % 4);   // output: 1
Console.WriteLine(5 % -4);  // output: 1
Console.WriteLine(-5 % 4);  // output: -1
Console.WriteLine(-5 % -4); // output: -1
```

### 浮点余数

对于[浮点](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/float)和[双精度型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double)操作数，有限的 `x` 和 `y` 的 `x % y` 的结果是值 `z`，使得

- 如果不是零，则 `z` 的符号与 `x` 的符号相同；
- `z` 的绝对值是 `|x| - n * |y|` 生成的值，其中 `n` 是小于或等于 `|x| / |y|` 的最大可能整数，`|x|`和 `|y|` 分别是 `x` 和 `y` 的绝对值。

有关非限定操作数的 `%` 运算符行为的信息，请参阅 [C# 语言规范](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/index)的[余数运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#remainder-operator)章节。

> 计算余数的此方法类似于用于整数操作数的方法，但与 IEEE 754 不同。 如果需要符合 IEEE 754 的余数运算，使用 [Math.IEEERemainder](https://docs.microsoft.com/zh-cn/dotnet/api/system.math.ieeeremainder) 方法。

下面的示例演示 `float` 和 `double` 操作数的余数运算符的行为：

```csharp
Console.WriteLine(-5.2f % 2.0f); // output: -1.2
Console.WriteLine(5.0 % 2.2);    // output: 0.6
Console.WriteLine(.41 % .2);     // output: 0.00999999999999995
```

请注意与浮点类型相关联的舍入错误。

有关[十进制](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/decimal)操作数，余数运算符 `%` 等效于 [System.Decimal](https://docs.microsoft.com/zh-cn/dotnet/api/system.decimal) 类型的[余数运算符](https://docs.microsoft.com/zh-cn/dotnet/api/system.decimal.op_modulus#System_Decimal_op_Modulus_System_Decimal_System_Decimal_)。

## [& Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/and-operator)

以下两种形式支持 `&` 运算符：一元 address-of 运算符或二元逻辑运算符。

### 一元 address-of 运算符

一元 `&` 运算符返回其操作数的地址。 有关详细信息，请参阅[如何：获取变量的地址](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/unsafe-code-pointers/how-to-obtain-the-address-of-a-variable)。

Address-of 运算符 `&` 需要 [不安全](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/unsafe)上下文。

### 整型逻辑按位 AND 运算符

对于整数类型，`&` 运算符对其操作数执行逻辑按位 AND 运算：

```csharp
uint a = 0b_1111_1000;
uint b = 0b_1001_1111;
uint c = a & b;
Console.WriteLine(Convert.ToString(c, toBase: 2));
// Output:
// 10011000
```

> 之前的示例使用[在 C# 7.0 中引入](https://docs.microsoft.com/zh-cn/dotnet/csharp/whats-new/csharp-7#numeric-literal-syntax-improvements)并[在 C# 7.2 中增强](https://docs.microsoft.com/zh-cn/dotnet/csharp/whats-new/csharp-7-2#leading-underscores-in-numeric-literals)的二进制文本。

由于针对整数类型的运算通常也允许针对枚举类型进行，因此 `&` 运算符也支持[枚举](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/enum)操作数。

### 布尔逻辑 AND 运算符

对于 [bool](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/bool) 操作数，`&` 运算符对其操作数执行逻辑 AND 运算。 如果 `x` 和 `y` 都为 `true`，则 `x & y` 的结果为 `true`。 否则，结果为 `false`。

即使第一个操作数计算结果为 `false`，`&` 运算符也会计算这两个操作数，而在这种情况下，无论第二个操作数的值为何，结果都肯定为 `false`。 以下示例演示了该行为：

```csharp
bool SecondOperand() 
{
    Console.WriteLine("Second operand is evaluated.");
    return true;
}

bool test = false & SecondOperand();
Console.WriteLine(test);
// Output:
// Second operand is evaluated.
// False
```

[条件 AND 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/conditional-and-operator) `&&` 也会计算其操作数的逻辑 AND，但只有在第一个操作数的计算结果为 `true` 时，才会计算第二个操作数。

对于可为 null 的 bool 操作数，`&` 操作数的行为与 SQL 的三值逻辑一致。 有关详细信息，请参阅[使用可以为 null 的类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/nullable-types/using-nullable-types)一文的 [bool? 类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/nullable-types/using-nullable-types#the-bool-type)部分。

### 运算符可重载性

用户定义类型可以[重载](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator)二元 `&` 运算符。 重载二元 `&` 运算符后，也会隐式重载 [AND 赋值运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/and-assignment-operator) `&=`。

## [| Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/or-operator)

针对整型类型和 `bool` 预定义了二元 `|` 运算符。 对于整型类型，`|` 会计算其操作数的按位 OR。 对于 `bool`操作数，`|` 会计算其操作数的逻辑 OR；即，当且仅当其两个操作数皆为 `false` 时，结果才为 `false`。

### 备注

二元 `|` 运算符计算两个操作数，无论第一个操作数的值是什么。这与[条件 OR 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/conditional-or-operator) `||` 相反。

用户定义的类型可以重载 `|` 运算符（请参阅[运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator)）。

### 示例

```csharp
class OR
{
    static void Main()
    {
        Console.WriteLine(true | false);  // logical or
        Console.WriteLine(false | false); // logical or
        Console.WriteLine("0x{0:x}", 0xf8 | 0x3f);   // bitwise or
    }
}
/*
Output:
True
False
0xff
*/
```

## [^ Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/xor-operator)

针对整型类型和 `bool` 预定义了二元 `^` 运算符。 对于整型类型，`^` 会计算其操作数的按位异或。 对于 `bool` 操作数，`^` 计算其操作数的逻辑异或；即，当且仅当其一个操作数为 `true` 时，结果才为 `true`。

### 备注

用户定义的类型可以重载 `^` 运算符（请参阅[运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator)）。 对整数类型的操作通常可用于枚举。

### 示例

```csharp
class XOR
{
    static void Main()
    {
        // Logical exclusive-OR

        // When one operand is true and the other is false, exclusive-OR 
        // returns True.
        Console.WriteLine(true ^ false);
        // When both operands are false, exclusive-OR returns False.
        Console.WriteLine(false ^ false);
        // When both operands are true, exclusive-OR returns False.
        Console.WriteLine(true ^ true);


        // Bitwise exclusive-OR

        // Bitwise exclusive-OR of 0 and 1 returns 1.
        Console.WriteLine("Bitwise result: {0}", Convert.ToString(0x0 ^ 0x1, 2));
        // Bitwise exclusive-OR of 0 and 0 returns 0.
        Console.WriteLine("Bitwise result: {0}", Convert.ToString(0x0 ^ 0x0, 2));
        // Bitwise exclusive-OR of 1 and 1 returns 0.
        Console.WriteLine("Bitwise result: {0}", Convert.ToString(0x1 ^ 0x1, 2));

        // With more than one digit, perform the exclusive-OR column by column.
        //    10
        //    11
        //    --
        //    01
        // Bitwise exclusive-OR of 10 (2) and 11 (3) returns 01 (1).
        Console.WriteLine("Bitwise result: {0}", Convert.ToString(0x2 ^ 0x3, 2));

        // Bitwise exclusive-OR of 101 (5) and 011 (3) returns 110 (6).
        Console.WriteLine("Bitwise result: {0}", Convert.ToString(0x5 ^ 0x3, 2));

        // Bitwise exclusive-OR of 1111 (decimal 15, hexadecimal F) and 0101 (5)
        // returns 1010 (decimal 10, hexadecimal A).
        Console.WriteLine("Bitwise result: {0}", Convert.ToString(0xf ^ 0x5, 2));

        // Finally, bitwise exclusive-OR of 11111000 (decimal 248, hexadecimal F8)
        // and 00111111 (decimal 63, hexadecimal 3F) returns 11000111, which is 
        // 199 in decimal, C7 in hexadecimal.
        Console.WriteLine("Bitwise result: {0}", Convert.ToString(0xf8 ^ 0x3f, 2));
    }
}
/*
Output:
True
False
False
Bitwise result: 1
Bitwise result: 0
Bitwise result: 0
Bitwise result: 1
Bitwise result: 110
Bitwise result: 1010
Bitwise result: 11000111
*/
```

上一示例中的 `0xf8 ^ 0x3f` 计算执行了以下两个二进制值的按位异或，这与十六进制值 F8 和 3F 对应：

```
1111 1000
0011 1111
```

异或的结果是 `1100 0111`，即十六进制中的 C7。

## [! Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/logical-negation-operator)

逻辑非运算符 (`!`) 是一种否定其操作数的一元运算符。 它针对 `bool` 定义，当且仅当其操作数为 `false` 时返回 `true`。

### 备注

用户定义的类型可以重载 `!` 运算符（请参阅[运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator)）。

### 示例

```csharp
class MainClass4
{
    static void Main()
    {
        Console.WriteLine(!true);
        Console.WriteLine(!false);
    }
}
/*
Output:
False
True
*/
```

## [~ Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/bitwise-complement-operator)

按位求补运算符 `~` 是一元运算符，通过反转每个位生成其操作数的按位求补。 所有整数类型都支持 `~` 运算符。

> `~` 符号还用于声明终结器。 有关详细信息，请参阅[终结器](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/destructors)。

下面的示例演示 `~` 运算符的用法：

```csharp
uint a = 0b_0000_1111_0000_1111_0000_1111_0000_1100;
uint b = ~a;
Console.WriteLine(Convert.ToString(b, toBase: 2));
// Output:
// 11110000111100001111000011110011
```

> 之前的示例使用[在 C# 7.0 中引入](https://docs.microsoft.com/zh-cn/dotnet/csharp/whats-new/csharp-7#numeric-literal-syntax-improvements)并[在 C# 7.2 中增强](https://docs.microsoft.com/zh-cn/dotnet/csharp/whats-new/csharp-7-2#leading-underscores-in-numeric-literals)的二进制文本。

### 运算符可重载性

用户定义的类型可以[重载](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator) `~` 运算符。

## [= Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/assignment-operator)

赋值运算符 `=` 将其右操作数的值赋给变量、[属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/properties)或由其左操作数给出的[索引器](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/indexers/index)元素。 赋值表达式的结果是分配给左操作数的值。 右操作数类型必须与左操作数类型相同，或可隐式转换为左操作数的类型。

赋值运算符为右联运算符，即形式的表达式

```csharp
a = b = c
```

计算结果为

```csharp
a = (b = c)
```

以下示例演示赋值运算符将值分配给局部变量、属性和索引器元素的用法：

```csharp
var numbers = new List<double>() { 1.0, 2.0, 3.0 };

Console.WriteLine(numbers.Capacity);
numbers.Capacity = 100;
Console.WriteLine(numbers.Capacity);
// Output:
// 4
// 100

int newFirstElement;
double originalFirstElement = numbers[0];
newFirstElement = 5;
numbers[0] = newFirstElement;
Console.WriteLine(originalFirstElement);
Console.WriteLine(numbers[0]);
// Output:
// 1
// 5
```

### ref 赋值运算符

从 C# 7.3 开始，可以使用 ref 赋值运算符 `= ref` 重新分配 [ref local](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ref#ref-locals) 或 [ref readonly local](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ref#ref-readonly-locals) 变量。 下面的示例演示 ref 赋值运算符的用法：

```csharp
void Display(double[] s) => Console.WriteLine(string.Join(" ", s));

double[] arr = { 0.0, 0.0, 0.0 };
Display(arr);

ref double arrayElement = ref arr[0];
arrayElement = 3.0;
Display(arr);

arrayElement = ref arr[arr.Length - 1];
arrayElement = 5.0;
Display(arr);
// Output:
// 0 0 0
// 3 0 0
// 3 0 5
```

对于 ref 赋值运算符，左操作数和右操作数的类型必须相同。

有关详细信息，请参阅[功能建议说明](https://github.com/dotnet/csharplang/blob/master/proposals/csharp-7.3/ref-local-reassignment.md)。

### 运算符可重载性

用户定义类型不能重载赋值运算符。 但是，用户定义类型可以定义到其他类型的隐式转换。 这样，可以将用户定义类型的值分配给其他类型的变量、属性或索引器元素。 有关详细信息，请参阅[隐式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/implicit)关键字一文。

## [< Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/less-than-operator)

如果第一操作数小于第二操作数，“小于”关系运算符 `<` 返回 `true`，否则返回 `false`。 所有数值和枚举类型都支持 `<` 运算符。 对于相同[枚举](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/enum)类型的操作数，基础整数类型的相应值会进行比较。

> 对于关系运算符 `==`、`>`、`<`、`>=` 和 `<=`，如果任何操作数不是数字 ([Double.NaN](https://docs.microsoft.com/zh-cn/dotnet/api/system.double.nan) 或 [Single.NaN](https://docs.microsoft.com/zh-cn/dotnet/api/system.single.nan))，操作数的结果为 `false`。 这意味着 `NaN` 值不大于、小于或等于任何其他 `double` （或 `float`）值。 有关更多信息和示例，请参阅 [Double.NaN](https://docs.microsoft.com/zh-cn/dotnet/api/system.double.nan) 或 [Single.NaN](https://docs.microsoft.com/zh-cn/dotnet/api/system.single.nan) 参考文章。

下面的示例演示 `<` 运算符的用法：

```csharp
Console.WriteLine(7.0 < 5.1);   // output: False
Console.WriteLine(5.1 < 5.1);   // output: False
Console.WriteLine(0.0 < 5.1);   // output: True

Console.WriteLine(double.NaN < 5.1);   // output: False
Console.WriteLine(double.NaN >= 5.1);  // output: False
```

### 运算符可重载性

用户定义的类型可以[重载](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator) `<` 运算符。 如果类型重载“小于”运算符 `<`，它必须也重载[“大于”运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/greater-than-operator) `>`。

## [> Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/greater-than-operator)

如果第一操作数大于第二操作数，“大于”关系运算符 `>` 返回 `true`，否则返回 `false`。 所有数值和枚举类型都支持 `>` 运算符。 对于相同[枚举](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/enum)类型的操作数，基础整数类型的相应值会进行比较。

> 对于关系运算符 `==`、`>`、`<`、`>=` 和 `<=`，如果任何操作数不是数字 ([Double.NaN](https://docs.microsoft.com/zh-cn/dotnet/api/system.double.nan) 或 [Single.NaN](https://docs.microsoft.com/zh-cn/dotnet/api/system.single.nan))，操作数的结果为 `false`。 这意味着 `NaN` 值不大于、小于或等于任何其他 `double` （或 `float`）值。 有关更多信息和示例，请参阅 [Double.NaN](https://docs.microsoft.com/zh-cn/dotnet/api/system.double.nan) 或 [Single.NaN](https://docs.microsoft.com/zh-cn/dotnet/api/system.single.nan) 参考文章。

下面的示例演示 `>` 运算符的用法：

```csharp
Console.WriteLine(7.0 > 5.1);   // output: True
Console.WriteLine(5.1 > 5.1);   // output: False
Console.WriteLine(0.0 > 5.1);   // output: False

Console.WriteLine(double.NaN > 5.1);   // output: False
Console.WriteLine(double.NaN <= 5.1);  // output: False
```

### 运算符可重载性

用户定义的类型可以[重载](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator) `>` 运算符。 如果类型重载“大于”运算符 `>`，它必须也重载[“小于”运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/less-than-operator) `<`。

## [?: Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/conditional-operator)

条件运算符 (`?:`) 通常被称为三元条件运算符，用于计算 Boolean 表达式，并根据 Boolean 表达式的计算结果为`true` 还是 `false` 来返回计算两个表达式其中之一的结果。 从 C# 7.2 开始，[ref 条件表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/conditional-operator#conditional-ref-expression)将返回对两个表示式之一的结果的引用。

条件运算符的语法如下所示：

C#复制

```csharp
condition ? consequence : alternative
```

`condition` 表达式的计算结果必须为 `true` 或 `false`。 若 `condition` 的计算结果为 `true`，将计算 `consequence`，其结果成为运算结果。 若 `condition` 的计算结果为 `false`，将计算 `alternative`，其结果成为运算结果。 只会计算 `consequence` 或 `alternative`。

`consequence` 和 `alternative` 的类型必须相同，或者必须存在从一种类型到另一种类型的隐式转换。

条件运算符为右联运算符，即形式的表达式

C#复制

```csharp
a ? b : c ? d : e
```

计算结果为

C#复制

```csharp
a ? b : (c ? d : e)
```

下面的示例演示条件运算符的用法：

C#复制

```csharp
double sinc(double x) => x != 0.0 ? Math.Sin(x) / x : 1;

Console.WriteLine(sinc(0.1));
Console.WriteLine(sinc(0.0));
// Output:
// 0.998334166468282
// 1
```

### ref 条件表达式

从 C# 7.2 开始，可以使用 ref 条件表达式返回对两个表示式之一的结果的引用。 可以将该引用分配到 [ref local](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ref#ref-locals) 或[ref readonly local](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ref#ref-readonly-locals) 变量，或将它用作[引用返回值](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ref#reference-return-values)或 [`ref` 方法参数](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ref#passing-an-argument-by-reference)。

ref 条件表达式的语法如下所示：

C#复制

```csharp
condition ? ref consequence : ref alternative
```

ref 条件表达式与原始的条件运算符相似，仅计算两个表达式其中之一：`consequence` 或 `alternative`。

在 ref 条件表达式中，`consequence` 和 `alternative` 的类型必须相同。

下面的示例演示 ref 条件表达式的用法：

C#复制

```csharp
var smallArray = new int[] { 1, 2, 3, 4, 5 };
var largeArray = new int[] { 10, 20, 30, 40, 50 };

int index = 7;
ref int refValue = ref ((index < 5) ? ref smallArray[index] : ref largeArray[index - 5]);
refValue = 0;

index = 2;
((index < 5) ? ref smallArray[index] : ref largeArray[index - 5]) = 100;

Console.WriteLine(string.Join(" ", smallArray));
Console.WriteLine(string.Join(" ", largeArray));
// Output:
// 1 2 100 4 5
// 10 20 0 40 50
```

有关详细信息，请参阅[功能建议说明](https://github.com/dotnet/csharplang/blob/master/proposals/csharp-7.2/conditional-ref.md)。

### 条件运算符和 `if..else` 语句

需要根据条件计算值时，在 [if-else](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/if-else) 语句中使用条件运算符可以使代码更简洁。 下面的示例演示了将整数归类为负数或非负数的两种方法：

C#复制

```csharp
int input = new Random().Next(-5, 5);

string classify;
if (input >= 0)
{
    classify = "nonnegative";
}
else
{
    classify = "negative";
}

classify = (input >= 0) ? "nonnegative" : "negative";
```

### 运算符可重载性

无法重载条件运算符。

## [++ Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/increment-operator)

一元增量运算符 `++` 按 1 递增其操作数。 它以两种形式进行支持：后缀增量运算符`x++` 和前缀增量运算符 `++x`。

### 后缀递增运算符

`x++` 的结果是此操作前的 `x` 的值，如以下示例所示：

```csharp
int i = 3;
Console.WriteLine(i);   // output: 3
Console.WriteLine(i++); // output: 3
Console.WriteLine(i);   // output: 4
```

### 前缀增量运算符

`++x` 的结果是此操作后的 `x` 的值，如以下示例所示：

```csharp
double a = 1.5;
Console.WriteLine(a);   // output: 1.5
Console.WriteLine(++a); // output: 2.5
Console.WriteLine(a);   // output: 2.5
```

### 备注

增量运算符是为所有[整型类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/integral-types-table)（包括[字符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/char)型）、[浮点型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/floating-point-types-table)和任何[枚举](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/enum)类型预定义的。

增量运算符的操作数必须是变量、[属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/properties)访问或[索引器](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/indexers/index)访问。

### 运算符可重载性

用户定义的类型可以[重载](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator) `++` 运算符。

## [-- Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/decrement-operator)

一元减量运算符 `--` 按 1 递减其操作数。 它以两种形式进行支持：后缀减量运算符`x--` 和前缀减量运算符 `--x`。

### 后缀递减运算符

`x--` 的结果是此操作前的 `x` 的值，如以下示例所示：

```csharp
int i = 3;
Console.WriteLine(i);   // output: 3
Console.WriteLine(i--); // output: 3
Console.WriteLine(i);   // output: 2
```

### 前缀减量运算符

`--x` 的结果是此操作后的 `x` 的值，如以下示例所示：

```csharp
double a = 1.5;
Console.WriteLine(a);   // output: 1.5
Console.WriteLine(--a); // output: 0.5
Console.WriteLine(a);   // output: 0.5
```

### 备注

减量运算符是为所有[整型类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/integral-types-table)（包括[字符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/char)类型）、[浮点型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/floating-point-types-table)和任何[枚举](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/enum)类型预定义的。

减量运算符的操作数必须是变量、[属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/properties)访问或[索引器](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/indexers/index)访问。

### 运算符可重载性

用户定义的类型可以[重载](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator) `--` 运算符。

## [&& Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/conditional-and-operator)

条件逻辑 AND 运算符 `&&`（也称为“短路”逻辑 AND 运算符）计算其 [bool](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/bool) 操作数的逻辑 AND。 如果 `x` 和 `y`的计算结果都为 `true`，则 `x && y` 的结果为 `true`。 否则，结果为 `false`。 如果第一个操作数的计算结果为`false`，则不会计算第二个操作数且运算结果为 `false`。 以下示例演示了该行为：

```csharp
bool SecondOperand()
{
    Console.WriteLine("Second operand is evaluated.");
    return true;
}

bool a = false && SecondOperand();
Console.WriteLine(a);
// Output:
// False

bool b = true && SecondOperand();
Console.WriteLine(b);
// Output:
// Second operand is evaluated.
// True
```

[逻辑 AND 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/and-operator) `&` 也会计算其 `bool` 操作数的逻辑 AND，但始终会计算两个操作数。

### 运算符可重载性

用户定义类型不能重载条件逻辑 AND 运算符。 不过，如果用户定义类型以某种方式重载[逻辑 AND](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/and-operator) 以及 [true 和 false 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/true-false-operators)，可以对相应类型的操作数执行 `&&` 运算。 有关详细信息，请参阅 [C# 语言规范](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/index)的[用户定义条件逻辑运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#user-defined-conditional-logical-operators)部分。

## [|| Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/conditional-or-operator)

条件逻辑 OR 运算符 `||`（也称为“短路”逻辑 OR 运算符）计算其 [bool](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/bool) 操作数的逻辑 OR。 如果 `x` 或 `y` 的计算结果为 `true`，则 `x || y` 的结果为 `true`。 否则，结果为 `false`。 如果第一个操作数的计算结果为 `true`，则不会计算第二个操作数且运算结果为 `true`。 以下示例演示了该行为：

```csharp
bool SecondOperand()
{
    Console.WriteLine("Second operand is evaluated.");
    return true;
}

bool a = true || SecondOperand();
Console.WriteLine(a);
// Output:
// True

bool b = false || SecondOperand();
Console.WriteLine(b);
// Output:
// Second operand is evaluated.
// True
```

[逻辑 OR 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/or-operator) `|` 也会计算其 `bool` 操作数的逻辑 OR，但始终会计算两个操作数。

### 运算符可重载性

用户定义类型不能重载条件逻辑 OR 运算符。 不过，如果用户定义类型以某种方式重载[逻辑 OR](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/or-operator) 以及 [true 和 false 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/true-false-operators)，可以对相应类型的操作数执行 `||` 运算。 有关详细信息，请参阅 [C# 语言规范](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/index)的[用户定义条件逻辑运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#user-defined-conditional-logical-operators)部分。

## [<< Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/left-shift-operator)

左移运算符 (`<<`) 将第一个操作数向左移动第二个操作数指定的位数。 第二个操作数的类型必须为 [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int) 或预定义隐式数值转换为 `int` 的类型。

### 备注

如果第一个操作数是 [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int) 或 [uint](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/uint)（32 位数），则移位计数由第二个操作数的低序五位给定。 也就是说，实际的移位计数为 0 到 31 位。

如果第一个操作数是 [long](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/long) 或 [ulong](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ulong)（64 位数），则移位计数由第二个操作数的低序六位给定。 也就是说，实际的移位计数为 0 到 63 位。

将丢弃移位后不在第一个操作数类型范围内的任何高序位，低序空位补零。 移位操作从不导致溢位。

用户定义的类型可以重载 `<<` 运算符（参阅[运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator)）；第一个操作数的类型必须是用户定义的类型，第二个操作数的类型必须是 `int`。 重载二元运算符时，也会隐式重载相应的赋值运算符（若有）。

### 示例

```csharp
class MainClass11
{
    static void Main()
    {
        int i = 1;
        long lg = 1;
        // Shift i one bit to the left. The result is 2.
        Console.WriteLine("0x{0:x}", i << 1);
        // In binary, 33 is 100001. Because the value of the five low-order
        // bits is 1, the result of the shift is again 2. 
        Console.WriteLine("0x{0:x}", i << 33);
        // Because the type of lg is long, the shift is the value of the six
        // low-order bits. In this example, the shift is 33, and the value of
        // lg is shifted 33 bits to the left.
        //     In binary:     10 0000 0000 0000 0000 0000 0000 0000 0000 
        //     In hexadecimal: 2    0    0    0    0    0    0    0    0
        Console.WriteLine("0x{0:x}", lg << 33);
    }
}
/*
Output:
0x2
0x2
0x200000000
*/
```

### 注释

请注意，`i<<1` 和 `i<<33` 的结果相同，因为 1 和 33 的低序五位相同。

## [>> Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/right-shift-operator)

右移运算符 (`>>`) 将第一个操作数向右移动第二个操作数指定的位数。

### 备注

如果第一个操作数是 [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int) 或 [uint](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/uint)（32 位数），则移位计数由第二个操作数的低序五位给定（第二个操作数 & 0x1f）。

如果第一个操作数是 [long](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/long) 或 [ulong](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ulong)（64 位数），则移位计数由第二个操作数的低序六位给定（第二个操作数 & 0x3f）。

如果第一个操作数是 [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int) 或 [long](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/long)，则右移是一种算术移位（高阶空位设置为符号位）。 如果第一个操作数的类型为 [uint](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/uint) 或 [ulong](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ulong)，则右移是一种逻辑移位（高序位补零）。

用户定义的类型可以重载 `>>` 运算符；第一个操作数的类型必须是用户定义的类型，第二个操作数的类型必须是[int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int)。有关详细信息，请参阅[运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator)。 重载二元运算符时，也会隐式重载相应的赋值运算符（若有）。

### 示例

```csharp
class RightShift
{
    static void Main()
    {
        int i = -1000;
        Console.WriteLine(i >> 3);
    }
}
/*
Output:
-125
*/
```

## [== Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/equality-comparison-operator)

如果操作数相等，等于运算符 `==` 返回 `true`，否则返回 `false`。

### 值类型的相等性

如果[内置值类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/value-types-table)的值相等，则其操作数相等：

```csharp
int a = 1 + 2 + 3;
int b = 6;
Console.WriteLine(a == b);  // output: True

char c1 = 'a';
char c2 = 'A';
Console.WriteLine(c1 == c2);  // output: False
Console.WriteLine(c1 == char.ToLower(c2));  // output: True
```

> 对于关系运算符 `==`、`>`、`<`、`>=` 和 `<=`，如果任何操作数不是数字 ([Double.NaN](https://docs.microsoft.com/zh-cn/dotnet/api/system.double.nan) 或 [Single.NaN](https://docs.microsoft.com/zh-cn/dotnet/api/system.single.nan))，操作数的结果为 `false`。 这意味着 `NaN` 值不大于、小于或等于任何其他 `double` （或 `float`）值。 有关更多信息和示例，请参阅 [Double.NaN](https://docs.microsoft.com/zh-cn/dotnet/api/system.double.nan) 或 [Single.NaN](https://docs.microsoft.com/zh-cn/dotnet/api/system.single.nan) 参考文章。

如果基本整数类型的相应值相等，则相同[枚举](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/enum)类型的两个操作数相等。

默认情况下，没有为用户定义的[结构](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/struct)类型定义 `==` 运算符。 用户定义的类型可以[重载](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/equality-comparison-operator#operator-overloadability) `==` 运算符。

从 C# 7.3 开始，`==` 和 [`!=`](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/not-equal-operator) 运算符由 C# [元组](https://docs.microsoft.com/zh-cn/dotnet/csharp/tuples)支持。 有关详细信息，请参阅 [C# 元组类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/tuples)一文的[相等性和元组](https://docs.microsoft.com/zh-cn/dotnet/csharp/tuples#equality-and-tuples)部分。

### 字符串相等性

如果两个字符串均为 `null` 或者两个字符串实例具有相等长度且在每个字符位置有相同字符，则这两个[字符串](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/string)操作数相等：

```csharp
string s1 = "hello!";
string s2 = "HeLLo!";
Console.WriteLine(s1 == s2.ToLower());  // output: True

string s3 = "Hello!";
Console.WriteLine(s1 == s3);  // output: False
```

这就是区分大小写的序号比较。 有关如何比较字符串的详细信息，请参阅[如何在 C# 中比较字符串](https://docs.microsoft.com/zh-cn/dotnet/csharp/how-to/compare-strings)。

### 引用类型的相等性

当两个非 `string` 引用类型引用同一对象时，其操作数相等：

```csharp
public class ReferenceTypesEquality
{
    public class MyClass
    {
        private int id;

        public MyClass(int id) => this.id = id;
    }

    public static void Main()
    {
        var a = new MyClass(1);
        var b = new MyClass(1);
        var c = a;
        Console.WriteLine(a == b);  // output: False
        Console.WriteLine(a == c);  // output: True
    }
}
```

该示例表明，`==` 运算符由用户定义的引用类型支持。 但是，用户定义的引用类型可以重载 `==` 运算符。 如果引用类型重载 `==` 运算符，使用 [Object.ReferenceEquals](https://docs.microsoft.com/zh-cn/dotnet/api/system.object.referenceequals) 方法来检查该类型的两个引用是否引用同一对象。

### 运算符可重载性

用户定义的类型可以[重载](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator) `==` 运算符。 如果类型重载等于运算符 `==`，它也必须重载[不等于运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/not-equal-operator) `!=`。

## [!= Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/not-equal-operator)

如果操作数不相等，不等于运算符 `!=` 返回 `true`，否则返回 `false`。 对于[内置类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/built-in-types-table)的操作数，表达式 `x != y` 生成与表达式 `!(x == y)` 相同的结果。 有关详细信息，请参阅 [== 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/equality-comparison-operator)一文。

下面的示例演示 `!=` 运算符的用法：

```csharp
int a = 1 + 1 + 2 + 3;
int b = 6;
Console.WriteLine(a != b);  // output: True

string s1 = "Hello";
string s2 = "Hello";
Console.WriteLine(s1 != s2);  // output: False

object o1 = 1;
object o2 = 1;
Console.WriteLine(o1 != o2);  // output: True
```

### 运算符可重载性

用户定义的类型可以[重载](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator) `!=` 运算符。 如果类型重载不等于运算符 `!=`，它也必须重载[等于运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/equality-comparison-operator) `==`

## [<= Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/less-than-equal-operator)

如果第一操作数小于或等于第二操作数，“小于或等于”关系运算符 `<=` 将返回 `true`，否则返回 `false`。 所有数值和枚举类型都支持 `<=` 运算符。 对于相同[枚举](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/enum)类型的操作数，基础整数类型的相应值会进行比较。

> 对于关系运算符 `==`、`>`、`<`、`>=` 和 `<=`，如果任何操作数不是数字 ([Double.NaN](https://docs.microsoft.com/zh-cn/dotnet/api/system.double.nan) 或 [Single.NaN](https://docs.microsoft.com/zh-cn/dotnet/api/system.single.nan))，操作数的结果为 `false`。 这意味着 `NaN` 值不大于、小于或等于任何其他 `double` （或 `float`）值。 有关更多信息和示例，请参阅 [Double.NaN](https://docs.microsoft.com/zh-cn/dotnet/api/system.double.nan) 或 [Single.NaN](https://docs.microsoft.com/zh-cn/dotnet/api/system.single.nan) 参考文章。

下面的示例演示 `<=` 运算符的用法：

```csharp
Console.WriteLine(7.0 <= 5.1);   // output: False
Console.WriteLine(5.1 <= 5.1);   // output: True
Console.WriteLine(0.0 <= 5.1);   // output: True

Console.WriteLine(double.NaN > 5.1);   // output: False
Console.WriteLine(double.NaN <= 5.1);  // output: False
```

### 运算符可重载性

用户定义的类型可以[重载](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator) `<=` 运算符。 如果类型重载“小于或等于”运算符 `<=`，它必须也重载[“大于或等于”运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/greater-than-equal-operator) `>=`。

## [>= Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/greater-than-equal-operator)

如果第一操作数大于或等于第二操作数，“大于或等于”关系运算符 `>=` 将返回 `true`，否则返回 `false`。 所有数值和枚举类型都支持 `>=` 运算符。 对于相同[枚举](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/enum)类型的操作数，基础整数类型的相应值会进行比较。

> 对于关系运算符 `==`、`>`、`<`、`>=` 和 `<=`，如果任何操作数不是数字 ([Double.NaN](https://docs.microsoft.com/zh-cn/dotnet/api/system.double.nan) 或 [Single.NaN](https://docs.microsoft.com/zh-cn/dotnet/api/system.single.nan))，操作数的结果为 `false`。 这意味着 `NaN` 值不大于、小于或等于任何其他 `double` （或 `float`）值。 有关更多信息和示例，请参阅 [Double.NaN](https://docs.microsoft.com/zh-cn/dotnet/api/system.double.nan) 或 [Single.NaN](https://docs.microsoft.com/zh-cn/dotnet/api/system.single.nan) 参考文章。

下面的示例演示 `>=` 运算符的用法：

```csharp
Console.WriteLine(7.0 >= 5.1);   // output: True
Console.WriteLine(5.1 >= 5.1);   // output: True
Console.WriteLine(0.0 >= 5.1);   // output: False

Console.WriteLine(double.NaN < 5.1);   // output: False
Console.WriteLine(double.NaN >= 5.1);  // output: False
```

### 运算符可重载性

用户定义的类型可以[重载](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator) `>=` 运算符。 如果类型重载“大于或等于”运算符 `>=`，它必须也重载[“小于或等于”运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/less-than-equal-operator) `<=`。

## [+= Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/addition-assignment-operator)

加法赋值运算符。

使用 `+=` 运算符的表达式，例如

```csharp
x += y
```

等效于

```csharp
x = x + y
```

不同的是 `x` 只计算一次。

对于数字类型，[加法运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/addition-operator) `+`计算其操作数的和。 如果其中的一个操作数是 [string](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/string) 类型或两个操作数都是该类型，它会将操作数的字符串表示形式串联在一起。 对于委托类型，`+` 运算符返回一个新的委托实例，该实例是其操作数的组合。

在订阅[事件](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/event)时，还可以使用 `+=` 运算符来指定事件处理程序方法。 有关更多信息，请参见[如何：订阅和取消订阅事件](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/events/how-to-subscribe-to-and-unsubscribe-from-events)。

下面的示例演示 `+=` 运算符的用法：

```csharp
int a = 5;
a += 9;
Console.WriteLine(a);
// Output: 14

string story = "Start. ";
story += "End.";
Console.WriteLine(story);
// Output: Start. End.

Action<int> printer = (int s) => Console.WriteLine(s);
printer += (int s) => Console.WriteLine(2 * s);
printer(3);
// Output:
// 3
// 6
```

### 运算符可重载性

如果用户定义类型[重载](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator)[加法运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/addition-operator) `+`，则加法赋值运算符 `+=` 为隐式重载。 用户定义类型不能显式重载加法赋值运算符。

## [-= Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/subtraction-assignment-operator)

减法赋值运算符。

### 备注

使用 `-=` 赋值运算符的表达式，如

```csharp
x -= y
```

等效于

```csharp
x = x - y
```

不同的是 `x` 只计算一次。 [- 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/subtraction-operator)的含义取决于 `x` 和 `y` 的类型（例如，对于数值操作数，其含义为相减；对于委托操作数，其含义为移除委托）。

不能直接重载 `-=` 运算符，但用户定义的类型可重载 [- 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/subtraction-operator)（请参阅[运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator)）。

C# 中也使用 -= 运算符来取消订阅事件。 有关详细信息，请参阅[如何：订阅和取消订阅事件](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/events/how-to-subscribe-to-and-unsubscribe-from-events)。

### 示例

```csharp
class MainClass3
{
    static void Main()
    {
        int a = 5;
        a -= 6;
        Console.WriteLine(a);
    }
}
/*
Output:
-1
*/
```

## [*= Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/multiplication-assignment-operator)

二进制乘法赋值运算符。

### 备注

使用 `*=` 赋值运算符的表达式，如

```csharp
x *= y
```

等效于

```csharp
x = x * y
```

不同的是 `x` 只计算一次。 针对数值类型预定义了 [* 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/multiplication-operator)以进行乘法运算。

不能直接重载 `*=` 运算符，但用户定义的类型可重载 [* 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/multiplication-operator)（参阅[运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator)）。

### 示例

```csharp
class MainClass10
{
    static void Main()
    {
        int a = 5;
        a *= 6;
        Console.WriteLine(a);
    }
}
/*
Output:
30
*/
```

## [/= Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/division-assignment-operator)

除法赋值运算符。

使用 `/=` 运算符的表达式，例如

```csharp
x /= y
```

等效于

```csharp
x = x / y
```

不同的是 `x` 只计算一次。

[除法运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/division-operator) `/` 用它的第一个操作数除以第二个操作数。 它受所有数值类型支持。

下面的示例演示 `/=` 运算符的用法：

```csharp
int a = 4;
int b = 5;
a /= b;
Console.WriteLine(a);   // output: 0

double x = 4;
double y = 5;
x /= y;
Console.WriteLine(x);   // output: 0.8
```

### 运算符可重载性

如果用户定义类型[重载](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator)[除法运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/division-operator) `/`，除法赋值运算符 `/=` 会隐式重载。 用户定义类型不得显式重载除法赋值运算符。

## [%= Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/modulus-assignment-operator)

余数赋值运算符。

使用 `%=` 运算符的表达式，例如

```csharp
x %= y
```

等效于

```csharp
x = x % y
```

不同的是 `x` 只计算一次。

[余数运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/remainder-operator) `%` 其计算操作数相除后的余数。 它受所有数值类型支持。

如果用户定义类型[重载](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator)[余数运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/remainder-operator) `%`，余数赋值运算符 `%=` 为隐式重载。

下面的示例演示 `%=` 运算符的用法：

```csharp
int a = 5;
a %= 3;
Console.WriteLine(a);  // output: 2
```

## [&= Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/and-assignment-operator)

AND 赋值运算符。

使用 `&=` 运算符的表达式，例如

```csharp
x &= y
```

等效于

```csharp
x = x & y
```

不同的是 `x` 只计算一次。

对于整数操作数，[`&` 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/and-operator)对其操作数执行按位逻辑 AND 运算；而对于 [bool](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/bool) 操作数，该运算符对其操作数执行逻辑 AND 运算。

下面的示例演示 `&=` 运算符的用法：

```csharp
byte a = 0b_1111_1000;
a &= 0b_1001_1111;
Console.WriteLine(Convert.ToString(a, toBase: 2));
// Output:
// 10011000

bool b = true;
b &= false;
Console.WriteLine(b);
// Output:
// False
```

### 运算符可重载性

如果用户定义类型[重载](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator) [`&` 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/and-operator)，则 AND 赋值运算符 `&=` 为隐式重载。 用户定义类型不能显式重载 AND 赋值运算符。

## [|= Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/or-assignment-operator)

OR 赋值运算符。

### 备注

使用 `|=` 赋值运算符的表达式，如

```csharp
x |= y
```

等效于

```csharp
x = x | y
```

不同的是 `x` 只计算一次。 [| 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/or-operator) 对整型操作数执行按位逻辑 OR 运算，对 bool 操作数执行逻辑 OR 运算。

不能直接重载 `|=` 运算符，但用户定义的类型可重载 [| 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/or-operator)（请参阅[运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator)）。

### 示例

```csharp
class MainClass7
{
    static void Main()
    {
        int a = 0x0c;
        a |= 0x06;
        Console.WriteLine("0x{0:x8}", a);
        bool b = true;
        b |= false;
        Console.WriteLine(b);
    }
}
/*
Output:
0x0000000e
True
*/
```

## [^= Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/xor-assignment-operator)

异或赋值运算符。

### 备注

形式如下的表达式

```csharp
x ^= y
```

计算结果为

```csharp
x = x ^ y
```

不同的是 `x` 只计算一次。 [^ 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/xor-operator) 对整型操作数执行按位异或运算，对 [bool](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/bool) 操作数执行逻辑异或运算。

不能直接重载 ^= 运算符，但用户定义的类型可重载 [^ 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/xor-operator)（请参阅[运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator)）。

### 示例

```csharp
class XORAssignment
{
    static void Main()
    {
        int a = 0x0c;
        a ^= 0x06;
        Console.WriteLine("0x{0:x8}", a);
        bool b = true;
        b ^= false;
        Console.WriteLine(b);
    }
}
/*
Output:
0x0000000a
True
*/
```

## [<<= Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/left-shift-assignment-operator)

左移赋值运算符。

### 备注

形式如下的表达式

```csharp
x <<= y
```

计算结果为

```csharp
x = x << y
```

不同的是 `x` 只计算一次。 [<< 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/left-shift-operator) 将 `x` 向左移动 `y` 指定的位数。

不能直接重载 `<<=` 运算符，但用户定义的类型可重载 [<< 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/left-shift-operator)（参阅[运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator)）。

### 示例

```csharp
class MainClass9
{
    static void Main()
    {
        int a = 1000;
        a <<= 4;
        Console.WriteLine(a);
    }
}
/*
Output:
16000
*/
```

## [>>= Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/right-shift-assignment-operator)

右移赋值运算符。

### 备注

形式如下的表达式

```csharp
x >>= y
```

计算结果为

```csharp
x = x >> y
```

不同的是 `x` 只计算一次。 [>> 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/right-shift-operator) 将 `x` 右移 `y` 指定的量。

不能直接重载 >>= 运算符，但用户定义的类型可重载 [>> 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/right-shift-operator)（参阅[运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator)）。

### 示例

```csharp
class MainClass8
{
    static void Main()
    {
        int a = 1000;
        a >>= 4;
        Console.WriteLine(a);
    }
}
/*
Output:
62
*/
```

## [-> Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/dereference-operator)

指针成员访问运算符 `->` 结合了指针间接和成员访问。

如果 `x` 是类型为 `T*` 的指针而 `y` 是 `T` 的可访问成员，则这种形式的表达式

```csharp
x->y
```

等效于

```csharp
(*x).y
```

`->` 运算符需要[不安全](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/unsafe)上下文。

有关详细信息，请参阅[如何：使用指针访问成员](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/unsafe-code-pointers/how-to-access-a-member-with-a-pointer)。

### 运算符可重载性

不能重载 `->` 运算符。

## [?? Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/null-coalescing-operator)

`??` 运算符称作 null 合并运算符。 如果此运算符的左操作数不为 null，则此运算符将返回左操作数；否则返回右操作数。

### 备注

可以为 null 的类型可以表示类型的域中的值，或者值可以是未定义的（在这种情况下，值为 null）。 如果左操作数具有一个值为 null 的可以为 null 的类型，则可使用 `??` 运算符的语法表现力来返回适当的值（右操作数）。如果在尝试将可以为 null 值的类型分配给不可以为 null 值的类型时没有使用 `??` 运算符，则会生成编译时错误。 如果使用强制转换，且当前未定义可以为 null 值的类型，则会引发 `InvalidOperationException` 异常。

有关详细信息，请参阅[可以为 null 的类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/nullable-types/index)。

?? 的结果 不能将运算符视为常量，即使其两个参数都是常量。

### 示例

```csharp
class NullCoalesce
{
    static int? GetNullableInt()
    {
        return null;
    }

    static string GetStringValue()
    {
        return null;
    }

    static void Main()
    {
        int? x = null;

        // Set y to the value of x if x is NOT null; otherwise,
        // if x == null, set y to -1.
        int y = x ?? -1;

        // Assign i to return value of the method if the method's result
        // is NOT null; otherwise, if the result is null, set i to the
        // default value of int.
        int i = GetNullableInt() ?? default(int);

        string s = GetStringValue();
        // Display the value of s if s is NOT null; otherwise, 
        // display the string "Unspecified".
        Console.WriteLine(s ?? "Unspecified");
    }
}
```

## [=> Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/lambda-operator)

`=>` 令牌支持两种形式：作为 lambda 运算符、作为成员名称的分隔符和表达式主体定义中的成员实现。

### lambda 运算符

在 [lambda 表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/lambda-expressions)中，lambda 运算符`=>`将左侧的输入变量与右侧的 lambda 主体分开。

以下示例使用带有方法语法的 [LINQ](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/index) 功能来演示 lambda 表达式的用法：

```csharp
string[] words = { "bot", "apple", "apricot" };
int minimalLength = words
  .Where(w => w.StartsWith("a"))
  .Min(w => w.Length);
Console.WriteLine(minimalLength);   // output: 5

int[] numbers = { 1, 4, 7, 10 };
int product = numbers.Aggregate(1, (interim, next) => interim * next);
Console.WriteLine(product);   // output: 280
```

lambda 表达式的输入变量在编译时是强类型。 当编译器可以推断输入变量的类型时，如前面的示例所示，可以省略类型声明。 如果需要指定输入变量的类型，则必须对每个变量执行此操作，如以下示例所示：

```csharp
int[] numbers = { 1, 4, 7, 10 };
int product = numbers.Aggregate(1, (int interim, int next) => interim * next);
Console.WriteLine(product);   // output: 280
```

以下示例显示如何在没有输入变量的情况下定义 lambda 表达式：

```csharp
Func<string> greet = () => "Hello, World!";
Console.WriteLine(greet());
```

有关详细信息，请参阅 [Lambda 表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/lambda-expressions)。

### 表达式主体定义

表达式主体定义具有下列常规语法：

```csharp
member => expression;
```

其中“expression”是有效的表达式。 请注意，仅当成员的返回类型是 `void` 时，或者成员是构造函数、终结器或属性 `set` 访问器时，表达式才可能是语句表达式。

以下示例演示了用于 `Person.ToString` 方法的表达式主体定义：

```csharp
public override string ToString() => $"{fname} {lname}".Trim();
```

它是以下方法定义的简写版：

```csharp
public override string ToString()
{
   return $"{fname} {lname}".Trim();
}
```

自 C#6 起支持方法和只读属性的表达式主体定义。 自 C# 7.0 起支持构造函数、终结器、属性访问器和索引器的表达式主体定义。

有关详细信息，请参阅 [Expression-bodied members](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/expression-bodied-members)（Expression-bodied 成员）。

### 运算符可重载性

不能重载 `=>` 运算符。