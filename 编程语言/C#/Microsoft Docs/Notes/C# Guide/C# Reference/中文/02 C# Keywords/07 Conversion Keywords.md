# [Conversion Keywords](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/conversion-keywords)

本部分介绍类型转换中使用的关键字：

- [explicit](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/explicit)
- [implicit](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/implicit)
- [operator](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator)

## [explicit](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/explicit)

`explicit` 关键字声明必须通过转换来调用的用户定义的类型转换运算符。

以下示例定义从 `Fahrenheit` 类转换为 `Celsius` 类的运算符。 必须在 `Fahrenheit` 类或 `Celsius` 类中定义运算符：

C#复制

```csharp
public static explicit operator Celsius(Fahrenheit fahr)
{
    return new Celsius((5.0f / 9.0f) * (fahr.Degrees - 32));
}
```

如以下示例所示，使用强制转换调用定义的转换运算符：

C#复制

```csharp
Fahrenheit fahr = new Fahrenheit(100.0f);
Console.Write($"{fahr.Degrees} Fahrenheit");
Celsius c = (Celsius)fahr;
```

此转换运算符从源类型转换为目标类型。 源类型提供转换运算符。 不同于隐式转换，显式转换运算符必须通过转换的方式来调用。 如果转换操作会导致异常或丢失信息，则应将其标记为 `explicit`。 这可阻止编译器静默调用可能产生意外后果的转换操作。

省略转换将导致编译时错误 CS0266。

有关详细信息，请参阅[使用转换运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/using-conversion-operators)。

### 示例

下面的示例提供了 `Fahrenheit` 和 `Celsius` 类，其中每个类均提供转换为其他类的显式转换运算符。

```csharp
class Celsius
{
    public Celsius(float temp)
    {
        Degrees = temp;
    }
    
    public float Degrees { get; }
    
    public static explicit operator Fahrenheit(Celsius c)
    {
        return new Fahrenheit((9.0f / 5.0f) * c.Degrees + 32);
    }
}

class Fahrenheit
{
    public Fahrenheit(float temp)
    {
        Degrees = temp;
    }
    
    public float Degrees { get; }
    
    public static explicit operator Celsius(Fahrenheit fahr)
    {
        return new Celsius((5.0f / 9.0f) * (fahr.Degrees - 32));
    }
}

class MainClass
{
    static void Main()
    {
        Fahrenheit fahr = new Fahrenheit(100.0f);
        Console.Write($"{fahr.Degrees} Fahrenheit");
        Celsius c = (Celsius)fahr;

        Console.Write($" = {c.Degrees} Celsius");
        Fahrenheit fahr2 = (Fahrenheit)c;
        Console.WriteLine($" = {fahr2.Degrees} Fahrenheit");
    }
}
// Output:
// 100 Fahrenheit = 37.77778 Celsius = 100 Fahrenheit
```

### 示例

下面的示例定义结构 `Digit`，它表示单个的十进制数字。 将运算符定义为从 `byte` 到 `Digit` 的转换，但由于并非所有字节都可转换为 `Digit`，因此该转换为显式。

```csharp
struct Digit
{
    byte value;
    public Digit(byte value)
    {
        if (value > 9)
        {
            throw new ArgumentException();
        }
        this.value = value;
    }

    // Define explicit byte-to-Digit conversion operator:
    public static explicit operator Digit(byte b)
    {
        Digit d = new Digit(b);
        Console.WriteLine("conversion occurred");
        return d;
    }
}

class ExplicitTest
{
    static void Main()
    {
        try
        {
            byte b = 3;
            Digit d = (Digit)b; // explicit conversion
        }
        catch (Exception e)
        {
            Console.WriteLine("{0} Exception caught.", e);
        }
    }
}
/*
Output:
conversion occurred
*/
```

## [implicit](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/implicit)

`implicit` 关键字用于声明隐式的用户定义类型转换运算符。 如果可以确保转换过程不会造成数据丢失，则可使用该关键字在用户定义类型和其他类型之间进行隐式转换。

### 示例

```csharp
class Digit
{
    public Digit(double d) { val = d; }
    public double val;
    // ...other members

    // User-defined conversion from Digit to double
    public static implicit operator double(Digit d)
    {
        return d.val;
    }
    //  User-defined conversion from double to Digit
    public static implicit operator Digit(double d)
    {
        return new Digit(d);
    }
}

class Program
{
    static void Main(string[] args)
    {
        Digit dig = new Digit(7);
        //This call invokes the implicit "double" operator
        double num = dig;
        //This call invokes the implicit "Digit" operator
        Digit dig2 = 12;
        Console.WriteLine("num = {0} dig2 = {1}", num, dig2.val);
        Console.ReadLine();
    }
}
```

隐式转换可以通过消除不必要的强制转换来提高源代码的可读性。 但是，因为隐式转换不需要程序员将一种类型显式强制转换为另一种类型，所以使用隐式转换时必须格外小心，以免出现意外结果。 一般情况下，隐式转换运算符应当从不引发异常并且从不丢失信息，以便可以在程序员不知晓的情况下安全使用它们。 如果转换运算符不能满足那些条件，则应将其标记为 `explicit`。 有关详细信息，请参阅[使用转换运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/using-conversion-operators)。

## [operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/operator)

使用 `operator` 关键字重载内置运算符，或在类或结构声明中提供用户定义的转换。

若要在自定义类或结构上重载运算符，可以在相应的类型中创建运算符声明。 重载内置 C# 运算符的运算符声明必须满足以下规则：

- 同时包含 `public` 和 `static` 修饰符。
- 包含 `operator X`，其中 `X` 是被重载运算符的名称或符号。
- 一元运算符具有一个参数，二元运算符具有两个参数。 在每种情况下，都必须至少有一个参数与声明运算符的类或结构的类型相同。

有关如何定义转换运算符的信息，请参阅[显式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/explicit)和[隐式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/implicit)关键字文章。

有关可重载 C# 运算符的概述，请参阅[可重载运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/overloadable-operators)一文。

### 示例

以下示例定义了表示小数的 `Fraction` 类型。 此类重载 `+` 和 `*` 运算符以执行分数加法和乘法，并提供转换运算符将 `Fraction` 类型转换为 `double` 类型。

```csharp
class Fraction
{
    int num, den;
    public Fraction(int num, int den)
    {
        this.num = num;
        this.den = den;
    }

    // overload operator +
    public static Fraction operator +(Fraction a, Fraction b)
    {
        return new Fraction(a.num * b.den + b.num * a.den,
           a.den * b.den);
    }

    // overload operator *
    public static Fraction operator *(Fraction a, Fraction b)
    {
        return new Fraction(a.num * b.num, a.den * b.den);
    }

    // user-defined conversion from Fraction to double
    public static implicit operator double(Fraction f)
    {
        return (double)f.num / f.den;
    }
}

class Test
{
    static void Main()
    {
        Fraction a = new Fraction(1, 2);
        Fraction b = new Fraction(3, 7);
        Fraction c = new Fraction(2, 3);
        Console.WriteLine((double)(a * b + c));
    }
}
/*
Output
0.880952380952381
*/
```