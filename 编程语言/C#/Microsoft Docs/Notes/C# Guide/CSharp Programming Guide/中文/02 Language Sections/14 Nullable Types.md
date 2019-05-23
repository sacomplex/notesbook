[C# programming guide](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/index)

# Language Sections

## [Nullable Types](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/nullable-types/index)

可以为 null 的类型是 [System.Nullable](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullable-1) 结构的实例。 可以为 null 的类型可表示一个基础类型的所有值 `T`，还可以再表示一个 [null](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/null) 值。 基础类型 `T` 可以是任何不可为 null 的[值类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/value-types)。 `T` 不能是引用类型。

例如，可以将 `null` 或任何整数值（从 [Int32.MinValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.int32.minvalue) 到 [Int32.MaxValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.int32.maxvalue)）赋给 `Nullable<int>`，并可将 [true](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/true-literal)[false](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/false-literal) 或 `null` 赋给`Nullable<bool>`。

需要表示基础类型的未定义的值时，请使用可以为 null 的类型。 布尔变量只能有两个值：true 和 false。 没有“未定义”的值。 在许多编程应用程序中，尤其是数据库交互中，变量值可能未定义或缺失。 例如，数据库中的字段可能包含值 true 或 false，但它也可能根本不包含任何值。 这种情况下要使用 `Nullable<bool>` 类型。

可以为 null 的类型具有以下特征：

- 可以为 null 的类型表示可以向其赋与 `null` 值的值类型变量。 不能根据引用类型创建可以为 null 的类型（引用类型已支持 `null` 值）。
- 语法 `T?` 是 `Nullable<T>` 的简写。 这两种形式是可互换的。
- 向可以为 null 的类型赋值的方法与向基础值类型赋值的方法相同：`int? x = 10;` 或 `double? d = 4.108;`。还可赋予 `null` 值：`int? x = null;`。
- 使用 [Nullable.HasValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullable-1.hasvalue) 和 [Nullable.Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullable-1.value) 只读属性可测试是否存在 null 值并检索值，如以下示例所示：`if (x.HasValue) y = x.Value;`
  - 如果变量包含值，则 [HasValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullable-1.hasvalue) 属性返回 `true`；如果值为 `null`，则返回 `false`。
  - 如果 [HasValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullable-1.hasvalue) 返回 `true`，则 [Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullable-1.value) 属性返回值。 否则会引发 [InvalidOperationException](https://docs.microsoft.com/zh-cn/dotnet/api/system.invalidoperationexception)。
- 还可将 `==` 和 `!=` 运算符用于可以为 null 的类型，如以下示例所示：`if (x != null) y = x.Value;` 如果 `a` 和 `b` 均为 null，则 `a == b` 的计算结果为 `true`。
- 从 C# 7.0 开始，可以使用[模式匹配](https://docs.microsoft.com/zh-cn/dotnet/csharp/pattern-matching#the-is-type-pattern-expression)来检查和获取可以为 null 的类型的值：`if (x is int valueOfX) y = valueOfX;`。
- `T?` 的默认值是一个实例，其 [HasValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullable-1.hasvalue) 属性返回 `false`。
- 使用 [GetValueOrDefault()](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullable-1.getvalueordefault#System_Nullable_1_GetValueOrDefault) 方法可返回赋予的值，如果可以为 null 的类型的值为 `null`，它还可返回基础值类型的[默认](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/default-values-table)值。
- 使用 [GetValueOrDefault(T)](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullable-1.getvalueordefault#System_Nullable_1_GetValueOrDefault__0_) 方法可返回赋予的值，如果可以为 null 的类型的值为 `null`，它还可返回提供的默认值。
- 使用 [null 合并运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/null-coalescing-operator) `??`，基于可以为 null 的类型的值向基础类型赋值：`int? x = null; int y = x ?? -1;`。 在示例中，由于 `x` 为 null，所以 `y` 的结果值为 `-1`。
- 如果定义了（用户定义的）两种数据类型之间的转换，还可将同一转换用于这些数据类型的可为 null 的版本。
- 不得嵌套可以为 null 的类型。 不会编译下面的一行代码：`Nullable<Nullable<int>> n;`

有关详细信息，请参阅[使用可以为 null 的类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/nullable-types/using-nullable-types)，以及[如何：标识可以为 null 的类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/nullable-types/how-to-identify-a-nullable-type)主题。

### [Using nullable types](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/nullable-types/using-nullable-types)

可以为 null 的类型是表示基础值类型 `T` 的所有值的类型，还可表示一个 [NULL](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/null) 值。 有关详细信息，请参阅[可以为 null 的类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/nullable-types/index)主题。

可使用以下任何一种形式引用可以为 null 的类型：`Nullable<T>` 或 `T?`。 这两种形式是可互换的。

#### 声明和赋值

由于值类型可隐式转换为相应的可以为 null 的类型，因此可像为其基础值类型赋值一样，为可以为 null 的类型赋值。 还可分配 `null` 值。 例如:

```csharp
double? pi = 3.14;
char? letter = 'a';

int m2 = 10;
int? m = m2;

bool? flag = null;

// Array of nullable type:
int?[] arr = new int?[10];
```

#### 检查可以为 null 的类型的值

使用以下只读属性检查可以为 null 的类型的实例是否为 null，并检索基础类型的值：

- [Nullable.HasValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullable-1.hasvalue) 指示可以为 null 的类型的实例是否具有其基础类型的值。
- 如果 [HasValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullable-1.hasvalue) 为 `true`，则 [Nullable.Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullable-1.value) 获取基础类型的值。 如果 [HasValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullable-1.hasvalue) 为 `false`，则 [Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullable-1.value) 属性将引发 [InvalidOperationException](https://docs.microsoft.com/zh-cn/dotnet/api/system.invalidoperationexception)。

以下示例中的代码使用 `HasValue` 属性在显示值之前测试变量是否包含该值：

```csharp
int? x = 10;
if (x.HasValue)
{
    Console.WriteLine($"x is {x.Value}");
}
else
{
    Console.WriteLine("x does not have a value");
}
```

还可将可以为 null 的类型的变量与 `null` 进行比较，而不是使用 `HasValue` 属性，如以下示例所示：

```csharp
int? y = 7;
if (y != null)
{
    Console.WriteLine($"y is {y.Value}");
}
else
{
    Console.WriteLine("y does not have a value");
}
```

从 C# 7.0 开始，可以使用[模式匹配](https://docs.microsoft.com/zh-cn/dotnet/csharp/pattern-matching)来检查和获取可以为 null 的类型的值：

```csharp
int? z = 42;
if (z is int valueOfZ)
{
    Console.WriteLine($"z is {valueOfZ}");
}
else
{
    Console.WriteLine("z does not have a value");
}
```

#### 从可以为 null 的类型转换为基础类型

如果需要将可以为 null 的类型的值分配给不可以为 null 的类型，请使用 [null-coalescing 运算符`??`](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/null-coalescing-operator)指定可以为 null 的类型的值为 null 时要分配的值（也可使用 [Nullable.GetValueOrDefault(T)](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullable-1.getvalueordefault#System_Nullable_1_GetValueOrDefault__0_) 方法来执行此操作）：

```csharp
int? c = null;

// d = c, if c is not null, d = -1 if c is null.
int d = c ?? -1;
Console.WriteLine($"d is {d}");
```

如果可以为 null 的类型的值为 null 时要使用的值应为基础值类型的默认值，请使用 [Nullable.GetValueOrDefault()](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullable-1.getvalueordefault#System_Nullable_1_GetValueOrDefault) 方法。

可显式地将可以为 null 的类型强制转换为不可以为 null 的类型。 例如:

```csharp
int? n = null;

//int m1 = n;    // Doesn't compile.
int n2 = (int)n; // Compiles, but throws an exception if n is null.
```

在运行时，如果可以为 null 的类型的值为 null，则显式强制转换将引发 [InvalidOperationException](https://docs.microsoft.com/zh-cn/dotnet/api/system.invalidoperationexception)。

不可以为 null 的值类型隐式转换为相应的可以为 null 的类型。

#### 运算符

可为 null 的类型还可使用预定义的一元运算符和二元运算符以及任何用于值类型的用户定义的运算符。 如果一个或两个操作数为 null，则这些运算符将生成一个 null 值；否则，运算符使用所包含的值来计算结果。 例如:

```csharp
int? a = 10;
int? b = null;
int? c = 10;

a++;        // a is 11.
a = a * c;  // a is 110.
a = a + b;  // a is null.
```

对于关系运算符（`<`、`>`、`<=`、`>=`），如果一个或两个操作数为 null，则结果为 `false`。 请勿作出如下假定：由于某个特定的比较（例如 `<=`）返回 `false`，则相反的比较 (`>`) 返回 `true`。 以下示例显示 10

- 既不大于等于 null，
- 也不小于 null。

```csharp
int? num1 = 10;
int? num2 = null;
if (num1 >= num2)
{
    Console.WriteLine("num1 is greater than or equal to num2");
}
else
{
    Console.WriteLine("num1 >= num2 is false (but num1 < num2 also is false)");
}

if (num1 < num2)
{
    Console.WriteLine("num1 is less than num2");
}
else
{
    Console.WriteLine("num1 < num2 is false (but num1 >= num2 also is false)");
}

if (num1 != num2)
{
    Console.WriteLine("num1 != num2 is true!");
}

num1 = null;
if (num1 == num2)
{
    Console.WriteLine("num1 == num2 is true if the value of each is null");
}
// Output:
// num1 >= num2 is false (but num1 < num2 also is false)
// num1 < num2 is false (but num1 >= num2 also is false)
// num1 != num2 is true!
// num1 == num2 is true if the value of each is null
```

以上示例还表明，对两个均为 null 的可以为 null 的类型进行相等比较，其计算结果为 `true`。

#### 装箱和取消装箱

可通过以下规则将可以为 null 的值类型[装箱](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/types/boxing-and-unboxing)：

- 如果 [HasValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullable-1.hasvalue) 返回 `false`，则生成空引用。
- 如果 [HasValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullable-1.hasvalue) 返回 `true`，则基础值类型 `T` 的值将装箱，而不对 [Nullable](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullable-1) 的实例进行装箱。

可将已装箱的值类型取消装箱到相应的可以为 null 的类型，如以下示例所示：

```csharp
int a = 41;
object aBoxed = a;
int? aNullable = (int?)aBoxed;
Console.WriteLine($"Value of aNullable: {aNullable}");

object aNullableBoxed = aNullable;
if (aNullableBoxed is int valueOfA)
{
    Console.WriteLine($"aNullableBoxed is boxed int: {valueOfA}");
}
// Output:
// Value of aNullable: 41
// aNullableBoxed is boxed int: 41
```

#### bool? 类型

可以为空的类型 `bool?` 可包含三个不同的值：[true](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/true-literal)、[false](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/false-literal) 和 [null](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/null)。 `bool?` 类型类似于在 SQL 中使用的布尔变量类型。 为确保 `&` 和 `|` 运算符产生的结果与 SQL 中具有三个值的布尔值类型一致，在此提供以下预定义运算符：

- `bool? operator &(bool? x, bool? y)`
- `bool? operator |(bool? x, bool? y)`

由下表定义这些运算符的语义：

| x     | y     | x 和 y | x\|y  |
| ----- | ----- | ------ | ----- |
| true  | true  | true   | true  |
| true  | False | false  | true  |
| true  | null  | null   | true  |
| False | true  | False  | true  |
| False | False | False  | False |
| False | null  | False  | null  |
| null  | true  | null   | true  |
| null  | False | False  | null  |
| null  | null  | null   | null  |

请注意，这两个运算符不遵循[运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/nullable-types/using-nullable-types#operators)部分中描述的规则：即使其中一个操作数为 null，运算符求值的结果也可以为非 null。

### [How to: Identify a nullable type](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/nullable-types/how-to-identify-a-nullable-type)

下面的示例演示如何确定 [System.Type](https://docs.microsoft.com/zh-cn/dotnet/api/system.type) 实例是否表示可以为 null 的封闭式泛型类型，即，具有指定类型参数 `T`的 [System.Nullable](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullable-1) 类型：

```csharp
Console.WriteLine($"int? is {(IsNullable(typeof(int?)) ? "nullable" : "non nullable")} type");
Console.WriteLine($"int is {(IsNullable(typeof(int)) ? "nullable" : "non nullable")} type");

bool IsNullable(Type type) => Nullable.GetUnderlyingType(type) != null;

// Output:
// int? is nullable type
// int is non nullable type
```

如示例所示，使用 [typeof](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/typeof) 运算符来创建 [System.Type](https://docs.microsoft.com/zh-cn/dotnet/api/system.type) 对象。

如果要确定实例是否是可以为 null 的类型，请不要使用 [Object.GetType](https://docs.microsoft.com/zh-cn/dotnet/api/system.object.gettype) 方法获取要通过前面的代码测试的 [Type](https://docs.microsoft.com/zh-cn/dotnet/api/system.type)实例。 如果对可以为 null 的类型的实例调用 [Object.GetType](https://docs.microsoft.com/zh-cn/dotnet/api/system.object.gettype) 方法，该实例将[装箱](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/nullable-types/using-nullable-types#boxing-and-unboxing)到 [Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object)。 由于对可以为 null 的类型的非 NULL 实例的装箱等效于对基础类型的值的装箱，因此 [GetType](https://docs.microsoft.com/zh-cn/dotnet/api/system.object.gettype) 返回表示可以为 null 的类型的基础类型的 [Type](https://docs.microsoft.com/zh-cn/dotnet/api/system.type) 对象：

```csharp
int? a = 17;
Type typeOfA = a.GetType();
Console.WriteLine(typeOfA.FullName);
// Output:
// System.Int32
```

请勿使用 [is](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/is) 运算符来确定实例是否是可以为 null 的类型。 如以下示例所示，无法使用 `is` 运算符区分可以为 null 的类型的实例类型和其基础类型：

```csharp
int? a = 14;
if (a is int)
{
    Console.WriteLine("int? instance is compatible with int");
}

int b = 17;
if (b is int?)
{
    Console.WriteLine("int instance is compatible with int?");
}
// Output:
// int? instance is compatible with int
// int instance is compatible with int?
```

可使用以下示例中提供的代码来确定实例是否是可以为 null 的类型：

```csharp
int? a = 14;
int b = 17;
if (IsOfNullableType(a) && !IsOfNullableType(b))
{
    Console.WriteLine("int? a is of a nullable type, while int b -- not");
}

bool IsOfNullableType<T>(T o)
{
    var type = typeof(T);
    return Nullable.GetUnderlyingType(type) != null;
}

// Output:
// int? a is of a nullable type, while int b -- not
```