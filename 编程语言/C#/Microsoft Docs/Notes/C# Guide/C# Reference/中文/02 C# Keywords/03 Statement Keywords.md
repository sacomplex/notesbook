# [Statement Keywords](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/statement-keywords)

语句是程序指令。 除了下表中的引用主题介绍的内容外，语句都是按照顺序执行。 下表列出了 C# 语句关键字。有关不用任何关键字表示的语句的详细信息，请参阅[语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/statements)。

| 类别                                                         | C# 关键字                                                    |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [选择语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/selection-statements) | [if](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/if-else)、[else](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/if-else)、[switch](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/switch)、[case](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/switch) |
| [迭代语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/iteration-statements) | [do](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/do)、[for](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/for)、[foreach](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/foreach-in)、[in](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/foreach-in)、[while](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/while) |
| [跳转语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/jump-statements) | [break](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/break)、[continue](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/continue)、[default](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/switch)、[goto](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/goto)、[return](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/return)、[yield](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/yield) |
| [异常处理语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/exception-handling-statements) | [throw](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/throw)、[try-catch](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/try-catch)、[try-finally](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/try-finally)、[try-catch-finally](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/try-catch-finally) |
| [Checked 和 unchecked](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/checked-and-unchecked) | [checked](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/checked)、[unchecked](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/unchecked) |
| [fixed 语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/fixed-statement) | [fixed](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/fixed-statement) |
| [lock 语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/lock-statement) | [lock](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/lock-statement) |

## [Selection Statements](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/selection-statements)

选择语句会导致基于特定条件是否为 `true` 而将程序控件转移给特定的流。

选择语句中使用下列关键字：

- [if](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/if-else)
- [else](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/if-else)
- [switch](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/switch)
- [case](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/switch)
- [default](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/switch)

### [if-else](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/if-else)

`if` 语句基于布尔表达式的值来识别运行哪个语句。 在下面的示例中， `bool` 变量 `condition` 已被设置为 `true` ，然后被签入到了 `if` 语句。 输出为 `The variable is set to true.`。

C#复制

```csharp
bool condition = true;

if (condition)
{
    Console.WriteLine("The variable is set to true.");
}
else
{
    Console.WriteLine("The variable is set to false.");
}
```

你可以通过将本主题中的示例放入控制台应用的 `Main` 方法中来运行它们。

C# 中的 `if` 语句可以采用两种形式，如以下示例所示。

C#复制

```csharp
// if-else statement
if (condition)
{
    then-statement;
}
else
{
    else-statement;
}
// Next statement in the program.

// if statement without an else
if (condition)
{
    then-statement;
}
// Next statement in the program.
```

在 `if-else` 语句中，如果 `condition` 计算结果为 true，则 `then-statement` 将运行。 如果 `condition` 为 false，则 `else-statement` 将运行。 由于 `condition` 不能同时为 true 和 false，因此， `then-statement` 语句的 `else-statement` 和 `if-else` 永远不能同时运行。 `then-statement` 或 `else-statement` 运行后，控件将转移到 `if` 语句之后的下一个语句。

在不包括 `if` 语句的 `else` 语句中，如果 `condition` 为 true，则 `then-statement` 将运行。 如果 `condition`为 false，则控件将转移到 `if` 语句之后的下一个语句。

`then-statement` 和 `else-statement` 都可由单个语句或包含在括号中 (`{}`) 的多个语句组成。 对于单个语句，括号是可选的，但建议选择。

`then-statement` 和 `else-statement` 中的语句可为任何类型，包括嵌套在原始 `if` 语句中的另一个 `if` 语句。在嵌套的 `if` 语句中，每个 `else` 子句都属于上一个无相应 `if` 的 `else`。 在下面的示例中，如果 `Result1`和 `m > 10` 计算结果都为 true，则将显示 `n > 20` 。 如果 `m > 10` 为 true 但 `n > 20` 为 false，则将显示 `Result2` 。

C#复制

```csharp
// Try with m = 12 and then with m = 8.
int m = 12;
int n = 18;

if (m > 10)
    if (n > 20)
    {
        Console.WriteLine("Result1");
    }
    else
    {
        Console.WriteLine("Result2");
    }
```

相反，如果你希望在 `Result2` 为 false 的时候显示 `(m > 10)` ，则可以通过使用括号来指定此关联，以建立嵌套的 `if` 语句的开头和结尾，如以下示例所示。

C#复制

```csharp
// Try with m = 12 and then with m = 8.
if (m > 10)
{
    if (n > 20)
        Console.WriteLine("Result1");
}
else
{
    Console.WriteLine("Result2");
}
```

如果条件 `(m > 10)` 的计算结果为 false，则显示 `Result2`。

#### 示例

在下例中，当通过键盘输入字符时，该程序将使用嵌套的 `if` 语句来确定输入的字符是否为字母字符。 如果输入的字符是字母字符，则程序将检查输入的字符是大写还是小写。 每种情况都会显示一条消息。

C#复制

```csharp
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
    Console.WriteLine("The character isn't an alphabetic character.");
}

//Sample Output:

//Enter a character: 2
//The character isn't an alphabetic character.

//Enter a character: A
//The character is uppercase.

//Enter a character: h
//The character is lowercase.
```

#### 示例

你也可以将 `if` 语句嵌套到 else 块中，如以下部分代码所示。 示例将 `if` 语句嵌套在两个 else 块和一个 then 块中。 注释指定每个块中哪些条件为 true 哪些条件为 false。

C#复制

```csharp
// Change the values of these variables to test the results.
bool Condition1 = true;
bool Condition2 = true;
bool Condition3 = true;
bool Condition4 = true;

if (Condition1)
{
    // Condition1 is true.
}
else if (Condition2)
{
    // Condition1 is false and Condition2 is true.
}
else if (Condition3)
{
    if (Condition4)
    {
        // Condition1 and Condition2 are false. Condition3 and Condition4 are true.
    }
    else
    {
        // Condition1, Condition2, and Condition4 are false. Condition3 is true.
    }
}
else
{
    // Condition1, Condition2, and Condition3 are false.
}
```

#### 示例

下面的示例确定了输入的字符是一个小写字母，还是大写字母，还是一个数字。 如果所有三个条件都为 false，该字符不是字母数字字符。 此示例显示了每种情况的消息内容。

C#复制

```csharp
Console.Write("Enter a character: ");
char ch = (char)Console.Read();

if (Char.IsUpper(ch))
{
    Console.WriteLine("The character is an uppercase letter.");
}
else if (Char.IsLower(ch))
{
    Console.WriteLine("The character is a lowercase letter.");
}
else if (Char.IsDigit(ch))
{
    Console.WriteLine("The character is a number.");
}
else
{
    Console.WriteLine("The character is not alphanumeric.");
}

//Sample Input and Output:
//Enter a character: E
//The character is an uppercase letter.

//Enter a character: e
//The character is a lowercase letter.

//Enter a character: 4
//The character is a number.

//Enter a character: =
//The character is not alphanumeric.
```

正如 else 块或 then 块中的语句可以是任何有效的语句一样，你可以将任何有效的布尔表达式用于此条件。 可以使用诸如 [&&](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/conditional-and-operator)、[&](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/and-operator)、[||](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/conditional-or-operator)、[|](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/or-operator) 和 [!](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/logical-negation-operator) 之类 的逻辑运算符来创建符合条件。 下面的代码演示了示例。

C#复制

```csharp
// NOT
bool result = true;
if (!result)
{
    Console.WriteLine("The condition is true (result is false).");
}
else
{
    Console.WriteLine("The condition is false (result is true).");
}

// Short-circuit AND
int m = 9;
int n = 7;
int p = 5;
if (m >= n && m >= p)
{
    Console.WriteLine("Nothing is larger than m.");
}

// AND and NOT
if (m >= n && !(p > m))
{
    Console.WriteLine("Nothing is larger than m.");
}

// Short-circuit OR
if (m > n || m > p)
{
    Console.WriteLine("m isn't the smallest.");
}

// NOT and OR
m = 4;
if (!(m >= n || m >= p))
{
    Console.WriteLine("Now m is the smallest.");
}
// Output:
// The condition is false (result is true).
// Nothing is larger than m.
// Nothing is larger than m.
// m isn't the smallest.
// Now m is the smallest.
```

### [switch](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/switch)

`switch` 是一个选择语句，它根据与匹配表达式匹配的模式，从候选列表中选择单个开关部分进行执行。

C#复制

```csharp
using System;

public class Example
{
   public static void Main()
   {
      int caseSwitch = 1;
      
      switch (caseSwitch)
      {
          case 1:
              Console.WriteLine("Case 1");
              break;
          case 2:
              Console.WriteLine("Case 2");
              break;
          default:
              Console.WriteLine("Default case");
              break;
      }
   }
}
// The example displays the following output:
//       Case 1
```

如果针对 3 个或更多条件测试单个表达式，`switch` 语句通常用作 [if-else](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/if-else) 构造的替代项。 例如，以下 `switch`语句确定类型为 `Color` 的变量是否具有三个值之一：

C#复制

```csharp
using System;

public enum Color { Red, Green, Blue }

public class Example
{
   public static void Main()
   {
      Color c = (Color) (new Random()).Next(0, 3);
      switch (c)
      {
         case Color.Red:
            Console.WriteLine("The color is red");
            break;
         case Color.Green:
            Console.WriteLine("The color is green");
            break;
         case Color.Blue:
            Console.WriteLine("The color is blue");   
            break;
         default:
            Console.WriteLine("The color is unknown.");
            break;   
      }
   }
}
```

它等效于使用 `if`- `else` 构造的以下示例。

C#复制

```csharp
using System;

public enum Color { Red, Green, Blue }

public class Example
{
   public static void Main()
   {
      Color c = (Color) (new Random()).Next(0, 3);
      if (c == Color.Red)
         Console.WriteLine("The color is red");
      else if (c == Color.Green)
         Console.WriteLine("The color is green");
      else if (c == Color.Blue)
         Console.WriteLine("The color is blue");   
      else
         Console.WriteLine("The color is unknown.");
   }
}
// The example displays the following output:
//       The color is red
```

#### 匹配表达式

匹配表达式提供与 `case` 标签中的模式相匹配的值。 语法为：

C#复制

```csharp
   switch (expr)
```

在 C# 6 中，匹配表达式必须是返回以下类型值的表达式：

- [字符型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/char)。
- [字符串](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/string)。
- [bool](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/bool)。
- 整数值，例如 [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int) 或 [long](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/long)。
- [枚举](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/enum)值。

从 C# 7.0 开始，匹配表达式可以是任何非 null 表达式。

#### 开关部分

`switch` 语句包含一个或多个开关部分。 每个 switch 部分包含一个或多个 case 标签（case 或 default 标签），后接一个或多个语句。 `switch` 语句最多可包含一个置于任何 switch 部分中的 default 标签。 以下示例显示了一个简单的 `switch` 语句，该语句包含三个 switch 部分，每个部分包含两个语句。 第二个 switch 部分包含 `case 2:` 和 `case 3:` 标签。

`switch` 语句中可以包含任意数量的开关部分，每个开关部分可以具有一个或多个 case 标签，如以下示例所示。但是，任何两个 case 标签不可包含相同的表达式。

C#复制

```csharp
using System;

public class Example
{
   public static void Main()
   {
      Random rnd = new Random();
      int caseSwitch = rnd.Next(1,4);
      
      switch (caseSwitch)
      {
          case 1:
              Console.WriteLine("Case 1");
              break;
          case 2:
          case 3:
              Console.WriteLine($"Case {caseSwitch}");
              break;
          default:
              Console.WriteLine($"An unexpected value ({caseSwitch})");
              break;
      }
   }
}
// The example displays output like the following:
//       Case 1
```

switch 语句执行中只有一个开关部分。 C# 不允许从一个开关部分继续执行到下一个开关部分。 因此，下面的代码生成编译器错误 CS0163：“控件不能从一个 case 标签 () 贯穿到另一个 case 标签。”

C#复制

```csharp
switch (caseSwitch)
{
    // The following switch section causes an error.
    case 1:
        Console.WriteLine("Case 1...");
        // Add a break or other jump statement here.
    case 2:
        Console.WriteLine("... and/or Case 2");
        break;
}
```

通常通过使用 [break](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/break)、[goto](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/goto) 或 [return](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/return) 语句显式退出开关部分来满足此要求。 但是，以下代码也有效，因为它确保程序控件不能贯穿 `default` 开关部分。

C#复制

```csharp
switch (caseSwitch)  
{  
    // The following switch section causes an error.  
    case 1:  
        Console.WriteLine("Case 1...");  
        break;  
    case 2:  
    case 3:
        Console.WriteLine("... and/or Case 2");  
        break;
    case 4:  
        while (true)  
           Console.WriteLine("Endless looping. . . ."); 
    default:
        Console.WriteLine("Default value...");
        break;                 
}  
```

在 case 标签与匹配表达式匹配的开关部分中执行语句列表时，先执行第一个语句，再执行整个语句列表，通常执行到跳转语句（如 `break`、`goto case`、`goto label`、`return` 或 `throw`）为止。 此时，控件在 `switch` 语句之外进行传输或传输到另一个 case 标签。 如果使用 `goto` 语句，必须将控制权移交给常数标签。 此限制是必要的，因为尝试将控制权移交给非常数标签可能会产生不良的副作用，如将控制权移交给代码中的意外位置，或创建无限循环。

#### Case 标签

每个 case 标签指定一个模式与匹配表达式（前面示例中的 `caseSwitch` 变量）进行比较。 如果它们匹配，则将控件传输到包含**首次**匹配 case 标签的开关部分。 如果 case 标签模式均不与匹配表达式相匹配，控件将传输到带 `default` case 标签的部分（如有）。 如果没有 `default` case，将不会执行任何开关部分中的语句，并且会将控件传输到 `switch` 语句之外。

有关 `switch` 语句和模式匹配的信息，请参阅使用 `switch` 语句的 [模式匹配](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/switch#pattern)部分。

因为 C# 6 仅支持常量模式并且不允许重复常量值，所以 case 标签定义了互斥值，而且仅有一个模式可与匹配表达式相匹配。 因此，`case` 语句显示的顺序并不重要。

然而，在 C# 7.0 中，因为支持其他模式，所以 case 标签不需要定义互斥值，并且多个模式可以与匹配表达式相匹配。 因为仅执行包含匹配模式的首次开关部分中的语句，所以 `case` 语句显示的顺序很重要。 如果 C# 检测到开关部分的 case 语句或语句等效于或是先前语句的子集，它将生成编译错误 CS8120：“开关 case 已由先前 case 处理。”

以下示例说明了使用各种非互斥模式的 `switch` 语句。 如果移动 `case 0:` 开关部分，使其不再是 `switch` 语句中的第一部分，C# 会生成编译器错误，因为值为零的整数是所有整数的子集（由 `case int val` 语句定义的模式）。

C#复制

```csharp
using System;
using System.Collections.Generic;
using System.Linq;

public class Example
{
   public static void Main()
   {
      var values = new List<object>();
      for (int ctr = 0; ctr <= 7; ctr++) {
         if (ctr == 2) 
            values.Add(DiceLibrary.Roll2());
         else if (ctr == 4)
            values.Add(DiceLibrary.Pass());
         else   
            values.Add(DiceLibrary.Roll());
      }   

      Console.WriteLine($"The sum of { values.Count } die is { DiceLibrary.DiceSum(values) }");
   }
}

public static class DiceLibrary
{
   // Random number generator to simulate dice rolls.
   static Random rnd = new Random();

   // Roll a single die.
   public static int Roll()
   {
      return rnd.Next(1, 7);
   }

   // Roll two dice.
   public static List<object> Roll2()
   {
      var rolls = new List<object>();      
      rolls.Add(Roll());
      rolls.Add(Roll());
      return rolls;
   }

   // Calculate the sum of n dice rolls.
   public static int DiceSum(IEnumerable<object> values)
   {
      var sum = 0;
      foreach (var item in values)
      {
            switch (item)
            {
               // A single zero value.
               case 0:
                  break;
               // A single value.
               case int val:
                  sum += val;
                  break;
               // A non-empty collection.
               case IEnumerable<object> subList when subList.Any():
                  sum += DiceSum(subList);
                  break;
               // An empty collection.
               case IEnumerable<object> subList:
                  break;
               //  A null reference.
               case null:
                  break;
               // A value that is neither an integer nor a collection.
               default:
                  throw new InvalidOperationException("unknown item type");
            }
      }
      return sum;
   }

   public static object Pass()
   {
      if (rnd.Next(0, 2) == 0)
         return null;
      else
         return new List<object>();
   }
}
```

你可以通过以下两种方法之一更正此问题并消除编译器警告：

- 更改开关部分的顺序。
- 在 `case` 标签中使用 [when clause](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/switch#when) 子句。

#### `default` case

如果匹配表达式与任何其他 `case` 标签不匹配，则 `default` case 指定要执行的开关部分。 如果不存在 `default` case，并且匹配表达式与其他任何 `case` 标签都不匹配，则程序流将贯穿 `switch` 语句。

`default` case 可以在 `switch` 语句中以任何顺序显示。 无论其在源代码中的顺序如何，都将在对所有 `case` 标签进行计算之后，最后对其进行计算。

#### 使用 `switch` 语句的 模式匹配

每个 `case` 语句定义一个模式，如果它与匹配表达式相匹配，则会导致执行其包含的开关部分。 所有版本的 C# 都支持常量模式。 其余模式从 C# 7.0 开始支持。

##### 常量模式

常量模式测试匹配表达式是否等于指定常量。 语法为：

C#复制

```csharp
   case constant:
```

其中 *constant* 是要测试的值。 *constant* 可以是以下任何常数表达式：

- [bool](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/bool) 文本，为 `true` 或 `false`。
- 任何整数常量，例如 [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int)、[long](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/long) 或[字节](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/byte)。
- 已声明 `const` 变量的名称。
- 一个枚举常量。
- [字符型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/char)文本。
- [字符串](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/string)文本。

常数表达式的计算方式如下：

- 如果 *expr* 和 *constant* 均为整型类型，则 C# 相等运算符确定表示式是否返回 `true`（即，是否为 `expr == constant`）。
- 否则，由对静态 [Object.Equals(expr, constant)](https://docs.microsoft.com/zh-cn/dotnet/api/system.object.equals#System_Object_Equals_System_Object_System_Object_) 方法的调用确定表达式的值。

以下示例使用常量模式来确定特定日期是否为周末、工作周的第一天、工作周的最后一天或工作周的中间日期。它根据 [DayOfWeek](https://docs.microsoft.com/zh-cn/dotnet/api/system.dayofweek) 枚举的成员计算当前日期的 [DateTime.DayOfWeek](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime.dayofweek#System_DateTime_DayOfWeek) 属性。

C#复制

```csharp
using System;

class Program
{
    static void Main()
    {
        switch (DateTime.Now.DayOfWeek)
        {
           case DayOfWeek.Sunday:
           case DayOfWeek.Saturday:
              Console.WriteLine("The weekend");
              break;
           case DayOfWeek.Monday:
              Console.WriteLine("The first day of the work week.");
              break;
           case DayOfWeek.Friday:
              Console.WriteLine("The last day of the work week.");
              break;
           default:
              Console.WriteLine("The middle of the work week.");
              break;   
        }
    }
}
// The example displays output like the following:
//       The middle of the work week.
```

以下示例使用常量模式在模拟自动咖啡机的控制台应用程序中处理用户输入。

C#复制

```csharp
using System;

class Example
{
   static void Main()
   {
       Console.WriteLine("Coffee sizes: 1=small 2=medium 3=large");
       Console.Write("Please enter your selection: ");
       string str = Console.ReadLine();
       int cost = 0;

       // Because of the goto statements in cases 2 and 3, the base cost of 25
       // cents is added to the additional cost for the medium and large sizes.
       switch (str)
       {
          case "1":
          case "small":
              cost += 25;
              break;
          case "2":
          case "medium":
              cost += 25;
              goto case "1";
          case "3":
          case "large":
              cost += 50;
              goto case "1";
          default:
              Console.WriteLine("Invalid selection. Please select 1, 2, or 3.");
              break;
      }
      if (cost != 0)
      {
          Console.WriteLine("Please insert {0} cents.", cost);
      }
      Console.WriteLine("Thank you for your business.");
   }
}
// The example displays output like the following:
//         Coffee sizes: 1=small 2=medium 3=large
//         Please enter your selection: 2
//         Please insert 50 cents.
//         Thank you for your business.
```

##### 类型模式

类型模式可启用简洁类型计算和转换。 使用 `switch` 语句执行模式匹配时，会测试表达式是否可转换为指定类型，如果可以，则将其转换为该类型的一个变量。 语法为：

C#复制

```csharp
   case type varname
```

其中 *type* 是 *expr* 结果要转换到的类型的名称，*varname* 是 *expr* 结果要转换到的对象（如果匹配成功）。

如果以下任一条件成立，则 `case` 表达式为 `true`：

- *expr* 是与 *type* 具有相同类型的一个实例。
- *expr* 是派生自 *type* 的类型的一个实例。 换言之，*expr* 结果可以向上转换为 *type* 的一个实例。
- *expr* 具有属于 *type* 的一个基类的编译时类型，*expr* 还具有属于 *type* 或派生自 *type* 的运行时类型。 变量的编译时类型是其类型声明中定义的变量类型。 变量的运行时类型是分配给该变量的实例类型。
- *expr* 是实现 *type* 接口的类型的一个实例。

如果 case 表达式为 true，将会明确分配 *varname*，并且仅在开关部分中具有本地作用域。

请注意，`null` 与任何类型都不匹配。 若要匹配 `null`，请使用以下 `case` 标签：

C#复制

```csharp
case null:
```

以下示例使用类型模式来提供有关各种集合类型的信息。

C#复制

```csharp
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

class Example
{
    static void Main(string[] args)
    {
        int[] values = { 2, 4, 6, 8, 10 };
        ShowCollectionInformation(values);
        
        var names = new List<string>();
        names.AddRange( new string[] { "Adam", "Abigail", "Bertrand", "Bridgette" } );
        ShowCollectionInformation(names);

        List<int> numbers = null;
        ShowCollectionInformation(numbers);
    }
   
    private static void ShowCollectionInformation(object coll)
    {
        switch (coll)
        {
            case Array arr:
               Console.WriteLine($"An array with {arr.Length} elements.");
               break;
            case IEnumerable<int> ieInt:
               Console.WriteLine($"Average: {ieInt.Average(s => s)}");
               break;   
            case IList list:
               Console.WriteLine($"{list.Count} items");
               break;
            case IEnumerable ie:
               string result = "";
               foreach (var item in ie) 
                  result += "${e} ";
               Console.WriteLine(result);
               break;   
            case null:
               // Do nothing for a null.
               break;
            default:
               Console.WriteLine($"A instance of type {coll.GetType().Name}");
               break;   
        }
    }
}
// The example displays the following output:
//     An array with 5 elements.
//     4 items
```

如果没有模式匹配，则可能按以下方式编写此代码。 使用类型模式匹配可消除测试转换结果是否为 `null` 或执行重复转换的必要，从而生成更紧凑易读的代码。

C#复制

```csharp
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

class Example
{
    static void Main(string[] args)
    {
        int[] values = { 2, 4, 6, 8, 10 };
        ShowCollectionInformation(values);
        
        var names = new List<string>();
        names.AddRange( new string[] { "Adam", "Abigail", "Bertrand", "Bridgette" } );
        ShowCollectionInformation(names);
        
        List<int> numbers = null;
        ShowCollectionInformation(numbers);
    }
   
    private static void ShowCollectionInformation(object coll)
    {
        if (coll is Array) {
           Array arr = (Array) coll;
           Console.WriteLine($"An array with {arr.Length} elements.");
        }
        else if (coll is IEnumerable<int>) {
            IEnumerable<int> ieInt = (IEnumerable<int>) coll;
            Console.WriteLine($"Average: {ieInt.Average(s => s)}");
        }
        else if (coll is IList) {
            IList list = (IList) coll;
            Console.WriteLine($"{list.Count} items");
        }
        else if (coll is IEnumerable) { 
            IEnumerable ie = (IEnumerable) coll;
            string result = "";
            foreach (var item in ie) 
               result += "${e} ";
            Console.WriteLine(result);
        }
        else if (coll == null) { 
            // Do nothing. 
        }
        else {
            Console.WriteLine($"An instance of type {coll.GetType().Name}");
        }   
    }
}
// The example displays the following output:
//     An array with 5 elements.
//     4 items
```

#### `case` 语句和 `when` 子句

从 C# 7.0 开始，因为 case 语句不需要互相排斥，因此可以添加 `when` 子句来指定必须满足的附加条件使 case 语句计算为 true。 `when` 子句可以是返回布尔值的任何表达式。

下面的示例定义了 `Shape` 基类、从 `Shape` 派生的 `Rectangle` 类以及从 `Rectangle` 派生的 `Square` 类。 它使用 `when` 子句来确保 `ShowShapeInfo` 将已分配相等长度和宽度的 `Rectangle` 对象作为 `Square` 来处理（即使未实例化为 `Square` 对象）。 该方法不会尝试显示关于值为 `null` 的对象或区域为零的形状的信息。

C#复制

```csharp
using System;

public abstract class Shape
{
   public abstract double Area { get; }
   public abstract double Circumference { get; } 
}

public class Rectangle : Shape
{
   public Rectangle(double length, double width) 
   {
      Length = length;
      Width = width; 
   }

   public double Length { get; set; }
   public double Width { get; set; }
   
   public override double Area
   { 
      get { return Math.Round(Length * Width,2); } 
   } 
   
   public override double Circumference 
   {
      get { return (Length + Width) * 2; }
   }
}

public class Square : Rectangle
{
   public Square(double side) : base(side, side) 
   {
      Side = side; 
   }

   public double Side { get; set; }
}

public class Circle : Shape
{
   public Circle(double radius) 
   {
      Radius = radius;
   } 
   
   public double Radius { get; set; }

   public override double Circumference
   {
      get { return 2 * Math.PI * Radius; }
   }

   public override double Area
   {
      get { return Math.PI * Math.Pow(Radius, 2); } 
   }
}

public class Example
{
   public static void Main()
   {
      Shape sh = null;
      Shape[] shapes = { new Square(10), new Rectangle(5, 7),
                         sh, new Square(0), new Rectangle(8, 8),
                         new Circle(3) };
      foreach (var shape in shapes)
         ShowShapeInfo(shape);
   }

   private static void ShowShapeInfo(Shape sh)
   {
      switch (sh)
      {
         // Note that this code never evaluates to true.
         case Shape shape when shape == null:
            Console.WriteLine($"An uninitialized shape (shape == null)");
            break;
         case null:
            Console.WriteLine($"An uninitialized shape");
            break;
         case Shape shape when sh.Area == 0:
            Console.WriteLine($"The shape: {sh.GetType().Name} with no dimensions");
            break;
         case Square sq when sh.Area > 0:
            Console.WriteLine("Information about square:");
            Console.WriteLine($"   Length of a side: {sq.Side}");
            Console.WriteLine($"   Area: {sq.Area}");
            break;
         case Rectangle r when r.Length == r.Width && r.Area > 0:
            Console.WriteLine("Information about square rectangle:");
            Console.WriteLine($"   Length of a side: {r.Length}");
            Console.WriteLine($"   Area: {r.Area}");
            break;
         case Rectangle r when sh.Area > 0:
            Console.WriteLine("Information about rectangle:");
            Console.WriteLine($"   Dimensions: {r.Length} x {r.Width}");
            Console.WriteLine($"   Area: {r.Area}");
            break;
         case Shape shape when sh != null:
            Console.WriteLine($"A {sh.GetType().Name} shape");
            break;
         default:
            Console.WriteLine($"The {nameof(sh)} variable does not represent a Shape.");
            break;   
      }
   }
}
// The example displays the following output:
//       Information about square:
//          Length of a side: 10
//          Area: 100
//       Information about rectangle:
//          Dimensions: 5 x 7
//          Area: 35
//       An uninitialized shape
//       The shape: Square with no dimensions
//       Information about square rectangle:
//          Length of a side: 8
//          Area: 64
//       A Circle shape
```

请注意，不会执行尝试测试 `Shape` 对象是否为 `null` 的示例中的 `when` 子句。 测试是否为 `null` 的正确类型模式是 `case null:`。

## [Iteration Statements](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/iteration-statements)

可使用迭代语句创建循环。 根据循环终止条件，迭代语句可导致多次执行嵌入式语句。 除非遇到[跳转语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/jump-statements)，否则这些语句按顺序执行。

迭代语句中使用下列关键字：

- [do](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/do)
- [for](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/for)
- [foreach, in](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/foreach-in)
- [while](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/while)

### [do](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/do)

在指定的布尔表达式的计算结果为 `true` 时，`do` 语句会执行一条语句或一个语句块。 由于在每次执行循环之后都会计算此表达式，所以 `do-while` 循环会执行一次或多次。 这不同于 [while](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/while) 循环（该循环执行零次或多次）。

在 `do` 语句块中的任何点，都可使用 [break](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/break) 语句中断循环。

可通过使用 [continue](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/continue) 语句直接步入 `while` 表达式的计算部分。 如果表达式计算结果为 `true`，则继续执行循环中的第一个语句。 否则，将在循环后的第一个语句处继续执行。

还可以使用 [goto](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/goto)、[return](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/return) 或 [throw](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/throw) 语句退出 `do-while` 循环。

#### 示例

下面的示例演示 `do` 语句的用法。 选择“运行”以运行示例代码。 然后可以修改代码并再次运行它。

```csharp
int n = 0;
do 
{
    Console.WriteLine(n);
    n++;
} while (n < 5);
```

### [for](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/for)

在指定的布尔表达式的计算结果为 `true` 时，`for` 语句会执行一条语句或一个语句块。

在 `for` 语句块中的任何点上，可以使用 [break](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/break) 语句中断循环，或者可以使用 [continue](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/continue) 语句继续执行到循环中的下一次迭代。 还可以使用 [goto](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/goto)、[return](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/return) 或 [throw](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/throw) 语句退出 `for` 循环。

#### `for` 语句的结构

`for` 语句定义初始化表达式、条件和迭代器部分：

C#复制

```csharp
for (initializer; condition; iterator)
    body
```

三个部分都是可选的。 循环体是一个语句或一个语句块。

以下示例显示定义了所有部分的 `for`：

C#复制运行

```csharp
for (int i = 0; i < 5; i++)
{
    Console.WriteLine(i);
}
```

##### “初始化表达式”部分

“初始化表达式”部分的语句仅在进入循环前执行一次。 “初始化表达式”部分是下列内容之一：

- 本地循环变量的声明和初始化，不能从循环外访问。
- 以下列表中显示用逗号分隔的零个或多个语句表达式：
  - [赋值](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/assignment-operator)语句
  - 方法的调用
  - 为 [increment](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/increment-operator) 表达式添加前缀或后缀，如 `++i` 或 `i++`
  - 为 [decrement](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/decrement-operator) 表达式添加前缀或后缀，如 `--i` 或 `i--`
  - 通过使用 [new](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/new-operator) 关键字创建对象
  - [await](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/await) 表达式

上例中的“初始化表达式”部分声明和初始化本地循环变量 `i`：

C#复制

```csharp
int i = 0
```

##### “条件”部分

“条件”部分（如果存在）必须为布尔表达式。 在每次循环迭代前计算该表达式。 如果“条件”部分不存在或者布尔表达式的计算结果为 `true`，则执行下一个循环迭代；否则退出循环。

上例中的“条件”部分确定循环是否根据本地循环变量的值终止：

```csharp
i < 5
```

##### “迭代器”部分

“迭代器”部分定义循环主体的每次迭代后将执行的操作。 “迭代器”部分包含用逗号分隔的零个或多个以下语句表达式：

- [赋值](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/assignment-operator)语句
- 方法的调用
- 为 [increment](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/increment-operator) 表达式添加前缀或后缀，如 `++i` 或 `i++`
- 为 [decrement](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/decrement-operator) 表达式添加前缀或后缀，如 `--i` 或 `i--`
- 通过使用 [new](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/new-operator) 关键字创建对象
- [await](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/await) 表达式

上例中的“迭代器”部分增加本地循环变量：

C#复制

```csharp
i++
```

#### 示例

下面的示例阐释了几种不太常见的 `for` 语句部分的使用情况：为“初始化表达式”部分中的外部循环变量赋值、同时在“初始化表达式”部分和“迭代器”部分中调用一种方法，以及更改迭代器部分中的两个变量的值。 选择“运行”以运行示例代码。 然后可以修改代码并再次运行它。

```csharp
int i;
int j = 10;
for (i = 0, Console.WriteLine($"Start: i={i}, j={j}"); i < j; i++, j--, Console.WriteLine($"Step: i={i}, j={j}"))
{
    // Body of the loop.
}
```

以下示例定义无限 `for` 循环：

```csharp
for ( ; ; )
{
    // Body of the loop.
}
```

### [foreach, in](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/foreach-in)

`foreach` 语句为类型实例中实现 [System.Collections.IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable) 或 [System.Collections.Generic.IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1)接口的每个元素执行语句或语句块。 `foreach` 语句不局限于这些类型，它可应用于满足以下条件的任何类型的实例：

- 具有公共无参数 `GetEnumerator` 方法，其返回类型为类、结构或接口类型。
- `GetEnumerator` 方法的返回类型具有公共 `Current` 属性和公共无参数 `MoveNext` 方法（其返回类型为[Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean)）。

从 C# 7.3 开始，如果枚举器的 `Current` 属性返回 [引用返回值](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ref#reference-return-values)（`ref T`，其中 `T` 为集合元素类型），就可以使用 `ref` 或 `ref readonly` 修饰符来声明迭代变量。

在 `foreach` 语句块中的任何点上，可以使用 [break](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/break) 语句中断循环，或者可以使用 [continue](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/continue) 语句继续执行到循环中的下一次迭代。 还可以使用 [goto](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/goto)、[return](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/return) 或 [throw](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/throw) 语句退出 `foreach` 循环。

#### 示例

> 本文中的 C# 示例运行在 [Try.NET](https://try.dot.net/) 内联代码运行程序和演练环境中。 选择“运行”按钮以在交互窗口中运行示例。 执行代码后，可通过再次选择“运行”来修改它并运行已修改的代码。 已修改的代码要么在交互窗口中运行，要么编译失败时，交互窗口将显示所有 C# 编译器错误消息。

以下示例介绍 `foreach` 语句的使用，其中包含实现 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 接口的 [List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1) 类型的实例：

```csharp
var fibNumbers = new List<int> { 0, 1, 1, 2, 3, 5, 8, 13 };
int count = 0;
foreach (int element in fibNumbers)
{
    count++;
    Console.WriteLine($"Element #{count}: {element}");
}
Console.WriteLine($"Number of elements: {count}");
```

下一个示例使用 `foreach` 语句，其中包含 [System.Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.span-1) 类型的实例，该实例不实现任何接口：

```csharp
public class IterateSpanExample
{
    public static void Main()
    {
        Span<int> numbers = new int[] { 3, 14, 15, 92, 6 };
        foreach (int number in numbers)
        {
            Console.Write($"{number} ");
        }
        Console.WriteLine();
    }
}
```

下面的示例使用 `ref` 迭代变量来设置 stackalloc 数组中每个项的值。 `ref readonly` 版本循环访问该集合以打印所有值。 `readonly` 声明使用隐式局部变量声明。 隐式变量声明可与 `ref` 或 `ref readonly` 声明配合使用，显式类型化变量声明也一样。

```csharp
public class ForeachRefExample
{
    public static void Main()
    {
        Span<int> storage = stackalloc int[10];
        int num = 0;
        foreach (ref int item in storage)
        {
            item = num++;
        }

        foreach (ref readonly var item in storage)
        {
            Console.Write($"{item} ");
        }
        // Output:
        // 0 1 2 3 4 5 6 7 8 9
    }
}
```

### [while](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/while)

在指定的布尔表达式的计算结果为 `true` 时，`while` 语句会执行一条语句或一个语句块。 由于在每次执行循环之前都会计算此表达式，所以 `while` 循环会执行零次或多次。 这不同于 [do](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/do) 循环，该循环执行一次或多次。

在 `while` 语句块中的任何点，都可使用 [break](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/break) 语句中断循环。

可通过使用 [continue](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/continue) 语句直接步入 `while` 表达式的计算部分。 如果表达式计算结果为 `true`，则继续执行循环中的第一个语句。 否则，将在循环后的第一个语句处继续执行。

还可以使用 [goto](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/goto)、[return](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/return) 或 [throw](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/throw) 语句退出 `while` 循环。

#### 示例

下面的示例演示 `while` 语句的用法。 选择“运行”以运行示例代码。 然后可以修改代码并再次运行它。

```csharp
int n = 0;
while (n < 5)
{
    Console.WriteLine(n);
    n++;
}
```

## [Jump Statements](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/jump-statements)

使用跳转语句执行分支，这将立即转移程序控制。 跳转语句中使用下列关键字：

- [break](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/break)
- [continue](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/continue)
- [goto](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/goto)
- [return](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/return)
- [throw](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/throw)

### [break](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/break)

`break` 语句将终止其所在位置的最接近封闭循环或 [switch](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/switch) 语句。 控制权将传递给已终止语句后面的语句（若有）。

#### 示例

在此示例中，条件语句包含一个应从 1 计数到 100 的计数器；但 `break` 语句在计数器计数到 4 后终止了循环。

```csharp
class BreakTest
{
    static void Main()
    {
        for (int i = 1; i <= 100; i++)
        {
            if (i == 5)
            {
                break;
            }
            Console.WriteLine(i);
        }

        // Keep the console open in debug mode.
        Console.WriteLine("Press any key to exit.");
        Console.ReadKey();
    }
}
/* 
 Output:
    1
    2
    3
    4  
*/
```

#### 示例

在此示例中，`break` 语句用于中断内层嵌套循环，并将控制权返回给外层循环。

```csharp
class BreakInNestedLoops
{
    static void Main(string[] args)
    {

        int[] numbers = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        char[] letters = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };

        // Outer loop
        for (int x = 0; x < numbers.Length; x++)
        {
            Console.WriteLine("num = {0}", numbers[x]);

            // Inner loop
            for (int y = 0; y < letters.Length; y++)
            {
                if (y == x)
                {
                    // Return control to outer loop
                    break;
                }
                Console.Write(" {0} ", letters[y]);
            }
            Console.WriteLine();
        }

        // Keep the console open in debug mode.
        Console.WriteLine("Press any key to exit.");
        Console.ReadKey();
    }
}

/*
 * Output:
    num = 0

    num = 1
     a
    num = 2
     a  b
    num = 3
     a  b  c
    num = 4
     a  b  c  d
    num = 5
     a  b  c  d  e
    num = 6
     a  b  c  d  e  f
    num = 7
     a  b  c  d  e  f  g
    num = 8
     a  b  c  d  e  f  g  h
    num = 9
     a  b  c  d  e  f  g  h  i
 */
```

#### 示例

本示例演示 `break` 在 [switch](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/switch) 语句中的用法。

```csharp
class Switch
{
    static void Main()
    {
        Console.Write("Enter your selection (1, 2, or 3): ");
        string s = Console.ReadLine();
        int n = Int32.Parse(s);

        switch (n)
        {
            case 1:
                Console.WriteLine("Current value is {0}", 1);
                break;
            case 2:
                Console.WriteLine("Current value is {0}", 2);
                break;
            case 3:
                Console.WriteLine("Current value is {0}", 3);
                break;
            default:
                Console.WriteLine("Sorry, invalid selection.");
                break;
        }

        // Keep the console open in debug mode.
        Console.WriteLine("Press any key to exit.");
        Console.ReadKey();
    }
}
/*
Sample Input: 1
 
Sample Output:
Enter your selection (1, 2, or 3): 1
Current value is 1
*/
```

如果输入 `4`，则输出为：

console复制

```console
Enter your selection (1, 2, or 3): 4
Sorry, invalid selection.
```

### [continue](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/continue)

`continue` 语句将控制传递到其中出现的封闭 [while](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/while)、[do](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/do)、[for](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/for) 或 [foreach](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/foreach-in) 语句的下一次迭代。

#### 示例

在本示例中，计数器最初是从 1 到 10 进行计数。 通过结合使用 `continue` 语句和表达式 `(i < 9)`，跳过 `continue` 和 `for` 主体末尾之间的语句。

```csharp
class ContinueTest
{
    static void Main()
    {
        for (int i = 1; i <= 10; i++)
        {
            if (i < 9)
            {
                continue;
            }
            Console.WriteLine(i);
        }

        // Keep the console open in debug mode.
        Console.WriteLine("Press any key to exit.");
        Console.ReadKey();
    }
}
/*
Output:
9
10
*/
```

### [goto](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/goto)

`goto` 语句将程序控制直接传递给标记语句。

`goto` 的一个通常用法是将控制传递给特定的 switch-case 标签或 `switch` 语句中的默认标签。

`goto` 语句还用于跳出深嵌套循环。

#### 示例

下面的示例演示了 `goto` 在 [switch](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/switch) 语句中的使用。

```csharp
class SwitchTest
{
    static void Main()
    {
        Console.WriteLine("Coffee sizes: 1=Small 2=Medium 3=Large");
        Console.Write("Please enter your selection: ");
        string s = Console.ReadLine();
        int n = int.Parse(s);
        int cost = 0;
        switch (n)
        {
            case 1:
                cost += 25;
                break;
            case 2:
                cost += 25;
                goto case 1;
            case 3:
                cost += 50;
                goto case 1;
            default:
                Console.WriteLine("Invalid selection.");
                break;
        }
        if (cost != 0)
        {
            Console.WriteLine("Please insert {0} cents.", cost);
        }
        Console.WriteLine("Thank you for your business.");

        // Keep the console open in debug mode.
        Console.WriteLine("Press any key to exit.");
        Console.ReadKey();
    }
}
/*
Sample Input:  2
 
Sample Output:
Coffee sizes: 1=Small 2=Medium 3=Large
Please enter your selection: 2
Please insert 50 cents.
Thank you for your business.
*/
```

#### 示例

下面的示例演示了使用 `goto` 跳出嵌套循环。

```csharp
public class GotoTest1
{
    static void Main()
    {
        int x = 200, y = 4;
        int count = 0;
        string[,] array = new string[x, y];

        // Initialize the array:
        for (int i = 0; i < x; i++)

            for (int j = 0; j < y; j++)
                array[i, j] = (++count).ToString();

        // Read input:
        Console.Write("Enter the number to search for: ");

        // Input a string:
        string myNumber = Console.ReadLine();

        // Search:
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                if (array[i, j].Equals(myNumber))
                {
                    goto Found;
                }
            }
        }

        Console.WriteLine("The number {0} was not found.", myNumber);
        goto Finish;

    Found:
        Console.WriteLine("The number {0} is found.", myNumber);

    Finish:
        Console.WriteLine("End of search.");


        // Keep the console open in debug mode.
        Console.WriteLine("Press any key to exit.");
        Console.ReadKey();
    }
}
/*
Sample Input: 44
 
Sample Output
Enter the number to search for: 44
The number 44 is found.
End of search.
*/
```

### [return](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/return)

`return` 语句可终止它所在的方法的执行，并将控制权返回给调用方法。 它还可以返回可选值。 如果方法是 `void` 类型，则 `return` 语句可以省略。

如果 return 语句位于 `try` 块中，则 `finally` 块（如果存在）会在控制权返回给调用方法之前进行执行。

#### 示例

在下面的示例中，方法 `CalculateArea()` 以 [double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double) 值的形式返回本地变量 `area`。

```csharp
class ReturnTest
{
    static double CalculateArea(int r)
    {
        double area = r * r * Math.PI;
        return area;
    }

    static void Main()
    {
        int radius = 5;
        double result = CalculateArea(radius);
        Console.WriteLine("The area is {0:0.00}", result);

        // Keep the console open in debug mode.
        Console.WriteLine("Press any key to exit.");
        Console.ReadKey();
    }
}
// Output: The area is 78.54
```

## [Exception Handling Statements](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/exception-handling-statements)

C# 提供用于处理反常情况（称为异常，可能会在执行程序的过程中发生）的内置支持。 这些异常由正常控制流之外的代码进行处理。

本部分中介绍了以下异常处理主题：

- [throw](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/throw)
- [try-catch](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/try-catch)
- [try-finally](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/try-finally)
- [try-catch-finally](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/try-catch-finally)

### [throw](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/throw)

发出程序执行期间出现异常的信号。

#### 备注

`throw` 的语法为：

```csharp
throw [e]
```

`e` 是一个派生自 [System.Exception](https://docs.microsoft.com/zh-cn/dotnet/api/system.exception) 的类的实例。 下例使用 `throw` 语句在传递给名为 `GetNumber` 的方法的参数与内部数组的有效索引不对应时引发 [IndexOutOfRangeException](https://docs.microsoft.com/zh-cn/dotnet/api/system.indexoutofrangeexception) 。

```csharp
using System;

public class NumberGenerator
{
   int[] numbers = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
   
   public int GetNumber(int index)
   {
      if (index < 0 || index >= numbers.Length) {
         throw new IndexOutOfRangeException();
      }
      return numbers[index];
   }
}
```

然后方法调用方使用 `try-catch` 或 `try-catch-finally` 块来处理引发的异常。 下例处理由 `GetNumber` 方法引发的异常。

```csharp
using System;

public class Example
{
   public static void Main()
   {
      var gen = new NumberGenerator();
      int index = 10;
      try {
          int value = gen.GetNumber(index);
          Console.WriteLine($"Retrieved {value}");
      }
      catch (IndexOutOfRangeException e) 
      {
         Console.WriteLine($"{e.GetType().Name}: {index} is outside the bounds of the array");
      }
   }
}
// The example displays the following output:
//        IndexOutOfRangeException: 10 is outside the bounds of the array
```

#### 重新引发异常

`throw` 也可以用于 `catch` 块，以重新引发在 `catch` 块中处理的异常。 在这种情况下，`throw` 不采用异常操作数。 当方法将参数从调用方传递给其他库方法时，这是最有用的，库方法引发的异常必须传递给调用方。 例如，以下示例重新引发在尝试检索未初始化字符串的第一个字符时引发的 [NullReferenceException](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullreferenceexception)。

```csharp
using System;

public class Sentence
{
   public Sentence(string s)
   {
      Value = s;
   }

   public string Value { get; set; }

   public char GetFirstCharacter()
   {
      try {
         return Value[0];
        }
      catch (NullReferenceException e) {
         throw;   
      } 
   }
}

public class Example 
{
   public static void Main()
   {
      var s = new Sentence(null);
      Console.WriteLine($"The first character is {s.GetFirstCharacter()}");
   }
}
// The example displays the following output:
//    Unhandled Exception: System.NullReferenceException: Object reference not set to an instance of an object.
//       at Sentence.GetFirstCharacter()
//       at Example.Main()
```

 重要

还可以使用 `catch` 块中的 `throw e` 语法来实例化传递给调用方的新异常。 在这种情况下，将不会保留可从 [StackTrace](https://docs.microsoft.com/zh-cn/dotnet/api/system.exception.stacktrace#System_Exception_StackTrace) 属性获得的原始异常的堆栈跟踪。

#### `throw` 表达式

从 C# 7.0 开始，`throw` 可以用作表达式和语句。 这允许在以前不支持的上下文中引发异常。 这些方法包括：

- [条件运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/conditional-operator)。 下例使用 `throw` 表达式在向方法传递空字符串数组时引发 [ArgumentException](https://docs.microsoft.com/zh-cn/dotnet/api/system.argumentexception)。 在 C# 7.0 之前，此逻辑将需要显示在 `if`/`else` 语句中。

  ```csharp
  private static void DisplayFirstNumber(string[] args)
  {
     string arg = args.Length >= 1 ? args[0] : 
                                throw new ArgumentException("You must supply an argument");
     if (Int64.TryParse(arg, out var number))
        Console.WriteLine($"You entered {number:F0}");
     else
        Console.WriteLine($"{arg} is not a number.");                            
    
  }
  ```

- [null 合并运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/null-coalescing-operator)。 在以下示例中，如果分配给 `Name` 属性的字符串为 `null`，则将 `throw` 表达式与 null 合并运算符结合使用以引发异常。

  ```csharp
  public string Name
  {
      get => name;
      set => name = value ?? 
          throw new ArgumentNullException("Name cannot be null", nameof(value));
  }   
  ```

- expression-bodied [lambda](https://docs.microsoft.com/zh-cn/dotnet/csharp/lambda-expressions) 或方法。 下例说明了 expression-bodied 方法，由于不支持对 [DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime) 值的转换，该方法引发 [InvalidCastException](https://docs.microsoft.com/zh-cn/dotnet/api/system.invalidcastexception)。

  ```csharp
  DateTime ToDateTime(IFormatProvider provider) => 
           throw new InvalidCastException("Conversion to a DateTime is not supported.");
  ```

### [try-catch](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/try-catch)

Try-catch 语句包含一个后接一个或多个 `catch` 子句的 `try` 块，这些子句指定不同异常的处理程序。

#### 备注

引发异常时，公共语言运行时 (CLR) 查找处理此异常的 `catch` 语句。 如果当前正在执行的方法不包含此类 `catch` 块，则 CLR 查看调用了当前方法的方法，并以此类推遍历调用堆栈。 如果未找到任何 `catch` 块，则 CLR 向用户显示一条未处理的异常消息，并停止执行程序。

`try` 块包含可能导致异常的受保护的代码。 将执行此块，直至引发异常或其成功完成。 例如，强制转换 `null`对象的以下尝试会引发 [NullReferenceException](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullreferenceexception) 异常：

```csharp
object o2 = null;
try
{
    int i2 = (int)o2;   // Error
}
```

尽管可以不带参数使用 `catch` 子句来捕获任何类型的异常，但不推荐这种用法。 一般情况下，只应捕获你知道如何从其恢复的异常。 因此，应始终指定派生自 [System.Exception](https://docs.microsoft.com/zh-cn/dotnet/api/system.exception) 的对象参数，例如：

C#复制

```csharp
catch (InvalidCastException e)
{
}
```

可以使用同一 try-catch 语句中的多个特定 `catch` 子句。 在这种情况下，`catch` 子句的顺序很重要，因为 `catch` 子句是按顺序检查的。 在使用更笼统的子句之前获取特定性更强的异常。 如果捕获块的排序使得永不会达到之后的块，则编译器将产生错误。

筛选想要处理的异常的一种方式是使用 `catch` 参数。 也可以使用异常筛选器进一步检查该异常以决定是否要对其进行处理。 如果异常筛选器返回 false，则继续搜索处理程序。

C#复制

```csharp
catch (ArgumentException e) when (e.ParamName == "…")
{
}
```

异常筛选器要优于捕获和重新引发（如下所述），因为筛选器将保留堆栈不受损坏。 如果之后的处理程序转储堆栈，可以查看到异常的原始来源，而不只是重新引发它的最后一个位置。 异常筛选器表达式的一个常见用途是日志记录。 可以创建一个始终返回 false 并输出到日志的筛选器，能在异常通过时进行记录，且无需处理并重新引发它们。

可在 `catch` 块中使用 [throw](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/throw) 语句以重新引发已由 `catch` 语句捕获的异常。 下面的示例从 [IOException](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.ioexception) 异常提取源信息，然后向父方法引发异常。

C#复制

```csharp
catch (FileNotFoundException e)
{
    // FileNotFoundExceptions are handled here.
}
catch (IOException e)
{
    // Extract some information from this exception, and then 
    // throw it to the parent method.
    if (e.Source != null)
        Console.WriteLine("IOException source: {0}", e.Source);
    throw;
}
```

你可以捕获一个异常而引发一个不同的异常。 执行此操作时，请指定作为内部异常捕获的异常，如以下示例所示。

C#复制

```csharp
catch (InvalidCastException e) 
{
    // Perform some action here, and then throw a new exception.
    throw new YourCustomException("Put your error message here.", e);
}
```

当指定的条件为 true 时，你还可以重新引发异常，如以下示例所示。

C#复制

```csharp
catch (InvalidCastException e)
{
    if (e.Data == null)
    {
        throw;
    }
    else
    {
        // Take some action.
    }
}
```

 备注

还可以使用异常筛选器以更简洁的方式获取类似的结果（不修改堆栈，如本文档前面的部分所述）。 下面的示例中，调用方的行为类似于前面的示例。 当 `e.Data` 为 `null` 时，该函数引发 `InvalidCastException` 返回至调用方。

C#复制

```csharp
catch (InvalidCastException e) when (e.Data != null) 
{
    // Take some action.
}
```

从 `try` 块内，仅初始化在其中声明的变量。 否则，在完成执行块之前，可能会出现异常。 例如，在下面的代码示例中，变量 `n` 在 `try` 块内部初始化。 尝试在 `Write(n)` 语句的 `try` 块外部使用此变量将生成编译器错误。

C#复制

```csharp
static void Main() 
{
    int n;
    try 
    {
        // Do not initialize this variable here.
        n = 123;
    }
    catch
    {
    }
    // Error: Use of unassigned local variable 'n'.
    Console.Write(n);
}
```

有关 catch 的详细信息，请参阅 [try-catch-finally](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/try-catch-finally)。

#### 异步方法中的异常

异步方法由 [async](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/async) 修饰符标记，通常包含一个或多个 await 表达式或语句。 await 表达式将 [await](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/await) 运算符应用于 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task) 或 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1)。

当控件到达异步方法中的 `await` 时，将挂起方法中的进度，直到所等待的任务完成。 任务完成后，可以在方法中恢复执行。 有关详细信息，请参阅[使用 async 和 await 的异步编程](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/index)和[异步程序中的控制流](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/control-flow-in-async-programs)。

应用了 `await` 的完成任务可能由于返回此任务的方法中存在未处理的异常而处于错误状态。 等待该任务引发异常。 如果取消了返回任务的异步进程，此任务最后也可能为已取消状态。 等待已取消的任务引发 `OperationCanceledException`。 有关如何取消异步进程的详细信息，请参阅[微调异步应用程序](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/fine-tuning-your-async-application)。

若要捕获异常，请在 `try` 块中等待任务并在关联的 `catch` 块中捕获异常。 相关示例，请参见“示例”一节。

任务可能处于错误状态，因为等待的异步方法中发生了多个异常。 例如，任务可能是对 [Task.WhenAll](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task.whenall) 调用的结果。 当等待此类任务时，仅捕捉到其中一个异常，而且你无法预测将会捕获到哪个异常。 相关示例，请参见“示例”一节。

#### 示例

在下面的示例中，`try` 块包含对可能引发异常的 `ProcessString` 方法的调用。 `catch` 子句包含只在屏幕上显示一条消息的异常处理程序。 当从 `MyMethod` 内部调用 `throw` 语句时，系统将查找 `catch` 语句并显示消息 `Exception caught`。

```csharp
class TryFinallyTest
{
    static void ProcessString(string s)
    {
        if (s == null)
        {
            throw new ArgumentNullException();
        }
    }

    static void Main()
    {
        string s = null; // For demonstration purposes.

        try
        {               
            ProcessString(s);
        }
        catch (Exception e)
        {
            Console.WriteLine("{0} Exception caught.", e);
        }
    }
}
/*
Output:
System.ArgumentNullException: Value cannot be null.
   at TryFinallyTest.Main() Exception caught.
 * */
```

#### 示例

在下面的示例中，使用了两个 catch 块，并捕获到最先出现的最具体的异常。

若要捕获最不具体的异常，你可以将 `ProcessString` 中的 throw 语句替换为以下语句：`throw new Exception()`。

如果将最不具体的 catch 块置于示例中第一个，将显示以下错误消息：`A previous catch clause already catches all exceptions of this or a super type ('System.Exception')`。

```csharp
class ThrowTest3
{
    static void ProcessString(string s)
    {
        if (s == null)
        {
            throw new ArgumentNullException();
        }
    }

    static void Main()
    {
        try
        {
            string s = null;
            ProcessString(s);
        }
        // Most specific:
        catch (ArgumentNullException e)
        {
            Console.WriteLine("{0} First exception caught.", e);
        }
        // Least specific:
        catch (Exception e)
        {
            Console.WriteLine("{0} Second exception caught.", e);
        }
    }
}
/*
 Output:
 System.ArgumentNullException: Value cannot be null.
 at Test.ThrowTest3.ProcessString(String s) ... First exception caught.
*/
```

#### 示例

下面的示例阐释异步方法的异常处理。 若要捕获异步任务引发的异常，将 `await` 表达式置于 `try` 块中，并在 `catch` 块中捕获该异常。

在示例中取消注释 `throw new Exception` 行以演示异常处理。 任务的 `IsFaulted` 属性设置为 `True`，任务的 `Exception.InnerException` 属性设置为异常，并在 `catch` 块中捕获该异常。

取消注释 `throw new OperationCanceledException` 行以演示在取消异步进程时发生的情况。 任务的 `IsCanceled`属性设置为 `true`，并在 `catch` 块中捕获异常。 在某些不适用于此示例的情况下，任务的 `IsFaulted` 属性设置为 `true` 且 `IsCanceled` 设置为 `false`。

```csharp
public async Task DoSomethingAsync()
{
    Task<string> theTask = DelayAsync();

    try
    {
        string result = await theTask;
        Debug.WriteLine("Result: " + result);
    }
    catch (Exception ex)
    {
        Debug.WriteLine("Exception Message: " + ex.Message);
    }
    Debug.WriteLine("Task IsCanceled: " + theTask.IsCanceled);
    Debug.WriteLine("Task IsFaulted:  " + theTask.IsFaulted);
    if (theTask.Exception != null)
    {
        Debug.WriteLine("Task Exception Message: "
            + theTask.Exception.Message);
        Debug.WriteLine("Task Inner Exception Message: "
            + theTask.Exception.InnerException.Message);
    }
}

private async Task<string> DelayAsync()
{
    await Task.Delay(100);

    // Uncomment each of the following lines to
    // demonstrate exception handling.

    //throw new OperationCanceledException("canceled");
    //throw new Exception("Something happened.");
    return "Done";
}

// Output when no exception is thrown in the awaited method:
//   Result: Done
//   Task IsCanceled: False
//   Task IsFaulted:  False

// Output when an Exception is thrown in the awaited method:
//   Exception Message: Something happened.
//   Task IsCanceled: False
//   Task IsFaulted:  True
//   Task Exception Message: One or more errors occurred.
//   Task Inner Exception Message: Something happened.

// Output when a OperationCanceledException or TaskCanceledException
// is thrown in the awaited method:
//   Exception Message: canceled
//   Task IsCanceled: True
//   Task IsFaulted:  False
```

#### 示例

下面的示例阐释了在多个任务可能导致多个异常的情况中的异常处理。 `try` 块等待由 [Task.WhenAll](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task.whenall) 的调用返回的任务。 应用了 WhenAll 的三个任务完成后，该任务完成。

三个任务中的每一个都会导致异常。 `catch` 块循环访问异常，这些异常位于由 [Task.WhenAll](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task.whenall) 返回的任务的 `Exception.InnerExceptions` 属性中。

```csharp
public async Task DoMultipleAsync()
{
    Task theTask1 = ExcAsync(info: "First Task");
    Task theTask2 = ExcAsync(info: "Second Task");
    Task theTask3 = ExcAsync(info: "Third Task");

    Task allTasks = Task.WhenAll(theTask1, theTask2, theTask3);

    try
    {
        await allTasks;
    }
    catch (Exception ex)
    {
        Debug.WriteLine("Exception: " + ex.Message);
        Debug.WriteLine("Task IsFaulted: " + allTasks.IsFaulted);
        foreach (var inEx in allTasks.Exception.InnerExceptions)
        {
            Debug.WriteLine("Task Inner Exception: " + inEx.Message);
        }
    }
}

private async Task ExcAsync(string info)
{
    await Task.Delay(100);
    
    throw new Exception("Error-" + info);
}

// Output:
//   Exception: Error-First Task
//   Task IsFaulted: True
//   Task Inner Exception: Error-First Task
//   Task Inner Exception: Error-Second Task
//   Task Inner Exception: Error-Third Task
```

### [try-finally](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/try-finally)

通过使用 `finally` 块，可以清除 [try](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/try-catch) 块中分配的任何资源，即使在 `try` 块中发生异常，也可以运行代码。 通常情况下，`finally` 块的语句会在控件离开 `try` 语句时运行。 正常执行中，执行 `break`、`continue`、`goto` 或`return` 语句，或者从 `try` 语句外传播异常都可能会导致发生控件转换。

已处理的异常中会保证运行相关联的 `finally` 块。 但是，如果异常未经处理，则 `finally` 块的执行将取决于异常解除操作的触发方式。 反过来，这又取决于你计算机的设置方式。

通常情况下，当未经处理的异常终止应用程序时，`finally` 块是否运行已不重要。 但是，如果 `finally` 块中的语句必须在这种情况下运行，则可以将 `catch` 块添加到 `try`-`finally` 语句，这是其中一种解决方法。 另一种解决方法是，可以捕获可能在调用堆栈上方的 `try` -`finally` 语句的 `try` 块中引发的异常。 也就是说，可以通过以下几种方法来捕获异常：调用包含 `try`-`finally` 语句的方法、调用该方法或调用堆栈中的任何方法。如果未捕获异常，则 `finally` 块的执行取决于操作系统是否选择触发异常解除操作。

#### 示例

在以下示例中，无效的转换语句会导致 `System.InvalidCastException` 异常。 异常未经处理。

```csharp
public class ThrowTestA
{
    static void Main()
    {
        int i = 123;
        string s = "Some string";
        object obj = s;

        try
        {
            // Invalid conversion; obj contains a string, not a numeric type.
            i = (int)obj;

            // The following statement is not run.
            Console.WriteLine("WriteLine at the end of the try block.");
        }
        finally
        {
            // To run the program in Visual Studio, type CTRL+F5. Then 
            // click Cancel in the error dialog.
            Console.WriteLine("\nExecution of the finally block after an unhandled\n" +
                "error depends on how the exception unwind operation is triggered.");
            Console.WriteLine("i = {0}", i);
        }
    }
    // Output:
    // Unhandled Exception: System.InvalidCastException: Specified cast is not valid.
    //
    // Execution of the finally block after an unhandled
    // error depends on how the exception unwind operation is triggered.
    // i = 123
}
```

在以下示例中，`TryCast` 方法导致的异常会在比调用堆栈更远的方法中被捕获。

```csharp
public class ThrowTestB
{
    static void Main()
    {
        try
        {
            // TryCast produces an unhandled exception.
            TryCast();
        }
        catch (Exception ex)
        {
            // Catch the exception that is unhandled in TryCast.
            Console.WriteLine
                ("Catching the {0} exception triggers the finally block.",
                ex.GetType());

            // Restore the original unhandled exception. You might not
            // know what exception to expect, or how to handle it, so pass 
            // it on.
            throw;
        }
    }

    public static void TryCast()
    {
        int i = 123;
        string s = "Some string";
        object obj = s;

        try
        {
            // Invalid conversion; obj contains a string, not a numeric type.
            i = (int)obj;

            // The following statement is not run.
            Console.WriteLine("WriteLine at the end of the try block.");
        }
        finally
        {
            // Report that the finally block is run, and show that the value of
            // i has not been changed.
            Console.WriteLine("\nIn the finally block in TryCast, i = {0}.\n", i);
        }
    }
    // Output:
    // In the finally block in TryCast, i = 123.

    // Catching the System.InvalidCastException exception triggers the finally block.

    // Unhandled Exception: System.InvalidCastException: Specified cast is not valid.
}
```

有关 `finally` 的详细信息，请参阅 [try-catch-finally](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/try-catch-finally)。

C# 还包含 [using 语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/using-statement)，它以简便语法为 [IDisposable](https://docs.microsoft.com/zh-cn/dotnet/api/system.idisposable) 对象提供类似的功能。

### [try-catch-finally](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/try-catch-finally)

`catch` 和 `finally` 的常见用法是获得并使用 `try` 块中的资源、处理 `catch` 块中的异常情况，以及释放 `finally` 块中的资源。

有关重新引发异常的详细信息和示例，请参阅 [try-catch](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/try-catch) 和[引发异常](https://docs.microsoft.com/zh-cn/dotnet/standard/exceptions/index)。 有关 `finally` 块的详细信息，请参阅 [try-finally](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/try-finally)。

#### 示例

```csharp
public class EHClass
{
    void ReadFile(int index)
    {
        // To run this code, substitute a valid path from your local machine
        string path = @"c:\users\public\test.txt";
        System.IO.StreamReader file = new System.IO.StreamReader(path);
        char[] buffer = new char[10];
        try
        {
            file.ReadBlock(buffer, index, buffer.Length);
        }
        catch (System.IO.IOException e)
        {
            Console.WriteLine("Error reading from {0}. Message = {1}", path, e.Message);
        }
        
        finally
        {
            if (file != null)
            {
                file.Close();
            }
        }
        // Do something with buffer...
    }

}
```

## [Checked and Unchecked](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/checked-and-unchecked)

C# 语句既可以在已检查的上下文中执行，也可以在未检查的上下文中执行。 在已检查的上下文中，算法溢出引发异常。 在未选中的上下文中忽略算术溢出并将结果截断，方法是：丢弃任何不适应目标类型的高序位。

- [checked](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/checked) 指定已检查的上下文。
- [unchecked](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/unchecked) 指定未检查的上下文。

下列操作受溢出检查的影响：

- 表达式在整型上使用下列预定义运算符：

  `++`，`--`，一元 `-`，`+`，`-`，`*`，`/`

- 整型类型之间或从 `float` 或 `double` 到整型类型的显式数字转换。

如果既未指定 `checked`，也未指定 `unchecked`，则非常量表达式（在运行时计算的表达式）的默认上下文将由 [-checked](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/checked-compiler-option) 编译器选项的值定义。 默认情况下，该选项的值未设置，且算术运算在未选中的上下文中执行。

对于常量表达式（可在编译时完全计算的表达式），将始终选中默认上下文。 除非在未选中的上下文中显式放置常量表达式，否则在编译时间计算表达式过程中出现的溢出将导致编译时错误。

### [checked](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/checked)

`checked` 关键字用于对整型类型算术运算和转换显式启用溢出检查。

默认情况下，如果表达式仅包含常量值，且产生的值在目标类型范围之外，则会导致编译器错误。 如果表达式包含一个或多个非常量值，则编译器不检测溢出。 在下面的示例中，计算赋给 `i2` 的表达式不会导致编译器错误。

C#复制

```csharp
// The following example causes compiler error CS0220 because 2147483647
// is the maximum value for integers. 
//int i1 = 2147483647 + 10;

// The following example, which includes variable ten, does not cause
// a compiler error.
int ten = 10;
int i2 = 2147483647 + ten;

// By default, the overflow in the previous statement also does
// not cause a run-time exception. The following line displays 
// -2,147,483,639 as the sum of 2,147,483,647 and 10.
Console.WriteLine(i2);
```

默认情况下，在运行时也不检查这些非常量表达式是否溢出，这些表达式不引发溢出异常。 上面的示例显示 -2,147,483,639 作为两个正整数之和。

可以通过编译器选项、环境配置或使用 `checked` 关键字来启用溢出检查。 下面的示例演示如何使用 `checked`表达式或 `checked` 块，在运行时检测由前面的求和计算导致的溢出。 两个示例都引发溢出异常。

C#复制

```csharp
// If the previous sum is attempted in a checked environment, an 
// OverflowException error is raised.

// Checked expression.
Console.WriteLine(checked(2147483647 + ten));

// Checked block.
checked
{
    int i3 = 2147483647 + ten;
    Console.WriteLine(i3);
}
```

可以使用 [unchecked](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/unchecked) 关键字阻止溢出检查。

#### 示例

此示例演示如何使用 `checked` 启用运行时溢出检查。

```csharp
class OverFlowTest
{
    // Set maxIntValue to the maximum value for integers.
    static int maxIntValue = 2147483647;

    // Using a checked expression.
    static int CheckedMethod()
    {
        int z = 0;
        try
        {
            // The following line raises an exception because it is checked.
            z = checked(maxIntValue + 10);
        }
        catch (System.OverflowException e)
        {
            // The following line displays information about the error.
            Console.WriteLine("CHECKED and CAUGHT:  " + e.ToString());
        }
        // The value of z is still 0.
        return z;
    }

    // Using an unchecked expression.
    static int UncheckedMethod()
    {
        int z = 0;
        try
        {
            // The following calculation is unchecked and will not 
            // raise an exception.
            z = maxIntValue + 10;
        }
        catch (System.OverflowException e)
        {
            // The following line will not be executed.
            Console.WriteLine("UNCHECKED and CAUGHT:  " + e.ToString());
        }
        // Because of the undetected overflow, the sum of 2147483647 + 10 is 
        // returned as -2147483639.
        return z;
    }

    static void Main()
    {
        Console.WriteLine("\nCHECKED output value is: {0}",
                          CheckedMethod());
        Console.WriteLine("UNCHECKED output value is: {0}",
                          UncheckedMethod());
    }
    /*
   Output:
   CHECKED and CAUGHT:  System.OverflowException: Arithmetic operation resulted
   in an overflow.
      at ConsoleApplication1.OverFlowTest.CheckedMethod() 

   CHECKED output value is: 0
   UNCHECKED output value is: -2147483639
 */
}
```

### [unchecked](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/unchecked)

`unchecked` 关键字用于取消整型类型的算术运算和转换的溢出检查。

在未经检查的上下文中，如果表达式生成的值超出目标类型的范围，则不会标记溢出。 例如，由于以下示例中的计算在 `unchecked` 块或表达式中执行，因此将忽略计算结果对于整数而言过大的事实，并且向 `int1` 赋予值 -2,147,483,639。

C#复制

```csharp
unchecked
{
    int1 = 2147483647 + 10;
}
int1 = unchecked(ConstantMax + 10);
```

如果删除 `unchecked` 环境，会发生编译错误。 由于表达式的所有项都是常量，因此可在编译时检测到溢出。

在编译时和运行时，默认不检查包含非常数项的表达式。 请参阅[启用检查](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/checked)，获取有关使用启用了检查的环境的信息。

由于检查溢出需要时间，因此在没有溢出风险的情况下使用取消检查的代码可能会提高性能。 但是，如果存在溢出的可能，则应使用启用了检查的环境。

#### 示例

此示例演示如何使用 `unchecked`关键字。

```csharp
class UncheckedDemo
{
    static void Main(string[] args)
    {
        // int.MaxValue is 2,147,483,647.
        const int ConstantMax = int.MaxValue;
        int int1;
        int int2;
        int variableMax = 2147483647;

        // The following statements are checked by default at compile time. They do not
        // compile.
        //int1 = 2147483647 + 10;
        //int1 = ConstantMax + 10;

        // To enable the assignments to int1 to compile and run, place them inside 
        // an unchecked block or expression. The following statements compile and
        // run.
        unchecked
        {
            int1 = 2147483647 + 10;
        }
        int1 = unchecked(ConstantMax + 10);

        // The sum of 2,147,483,647 and 10 is displayed as -2,147,483,639.
        Console.WriteLine(int1);


        // The following statement is unchecked by default at compile time and run 
        // time because the expression contains the variable variableMax. It causes  
        // overflow but the overflow is not detected. The statement compiles and runs.
        int2 = variableMax + 10;

        // Again, the sum of 2,147,483,647 and 10 is displayed as -2,147,483,639.
        Console.WriteLine(int2);

        // To catch the overflow in the assignment to int2 at run time, put the
        // declaration in a checked block or expression. The following
        // statements compile but raise an overflow exception at run time.
        checked
        {
            //int2 = variableMax + 10;
        }
        //int2 = checked(variableMax + 10);

        // Unchecked sections frequently are used to break out of a checked 
        // environment in order to improve performance in a portion of code 
        // that is not expected to raise overflow exceptions.
        checked
        { 
            // Code that might cause overflow should be executed in a checked
            // environment.
            unchecked
            { 
                // This section is appropriate for code that you are confident 
                // will not result in overflow, and for which performance is 
                // a priority.
            }
            // Additional checked code here. 
        }
    }
}
```

## [fixed Statement](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/fixed-statement)

`fixed` 语句可防止垃圾回收器重新定位可移动的变量。 `fixed` 语句仅允许存在于[不安全的](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/unsafe)上下文中。 `fixed`还可用于创建[固定大小的缓冲区](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/unsafe-code-pointers/fixed-size-buffers)。

`fixed` 语句将为托管变量设置一个指针，并在该语句的执行过程中“单边锁定”该变量。 仅可在 `fixed` 上下文中使用指向可移动托管变量的指针。 如果没有 `fixed` 上下文，垃圾回收可能会不可预测地重定位变量。 C# 编译器只允许将指针分配给 `fixed` 语句中的托管变量。

C#复制

```csharp
class Point 
{ 
    public int x;
    public int y; 
}

unsafe private static void ModifyFixedStorage()
{
    // Variable pt is a managed variable, subject to garbage collection.
    Point pt = new Point();

    // Using fixed allows the address of pt members to be taken,
    // and "pins" pt so that it is not relocated.

    fixed (int* p = &pt.x)
    {
        *p = 1;
    }
}
```

可以通过使用一个数组、字符串、固定大小的缓冲区或变量的地址来初始化指针。 下面的示例说明了变量地址、数组和字符串的使用。 有关固定大小的缓冲区的详细信息，请参阅[固定大小的缓冲区](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/unsafe-code-pointers/fixed-size-buffers)。

C#复制

```csharp
Point point = new Point();
double[] arr = { 0, 1.5, 2.3, 3.4, 4.0, 5.9 };
string str = "Hello World";

// The following two assignments are equivalent. Each assigns the address
// of the first element in array arr to pointer p.

// You can initialize a pointer by using an array.
fixed (double* p = arr) { /*...*/ }

// You can initialize a pointer by using the address of a variable. 
fixed (double* p = &arr[0]) { /*...*/ }

// The following assignment initializes p by using a string.
fixed (char* p = str) { /*...*/ }

// The following assignment is not valid, because str[0] is a char, 
// which is a value, not a variable.
//fixed (char* p = &str[0]) { /*...*/ } 
```

从 C# 7.3 开始，`fixed` 语句可在数组、字符串、固定大小缓冲区或非托管变量以外的其他类型上执行。 实施名为 `GetPinnableReference` 的方法的任何类型都可以被固定。 `GetPinnableReference` 必须向非托管类型返回 `ref`变量。 请参阅有关[指针类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/unsafe-code-pointers/pointer-types)的主题以了解详细信息。 .NET Core 2.0 中引入的 .NET 类型 [System.Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.span-1) 和 [System.ReadOnlySpan](https://docs.microsoft.com/zh-cn/dotnet/api/system.readonlyspan-1) 使用此模式，并且可以固定。 下面的示例对此进行了演示：

C#复制

```csharp
unsafe private static void FixedSpanExample()
{
    int[] PascalsTriangle = {
                  1,
                1,  1,
              1,  2,  1,
            1,  3,  3,  1,
          1,  4,  6,  4,  1,
        1,  5,  10, 10, 5,  1
    };

    Span<int> RowFive = new Span<int>(PascalsTriangle, 10, 5);

    fixed (int* ptrToRow = RowFive)
    {
        // Sum the numbers 1,4,6,4,1
        var sum = 0;
        for (int i = 0; i < RowFive.Length; i++)
        {
            sum += *(ptrToRow + i);
        }
        Console.WriteLine(sum);
    }
}
```

如果正在创建应加入此模式的类型，请参阅 [Span.GetPinnableReference()](https://docs.microsoft.com/zh-cn/dotnet/api/system.span-1.getpinnablereference#System_Span_1_GetPinnableReference) 以查看有关实施此模式的示例。

如果它们都是同一类型，则可以在一个语句中初始化多个指针：

C#复制

```csharp
fixed (byte* ps = srcarray, pd = dstarray) {...}
```

若要初始化不同类型的指针，只需嵌套 `fixed` 语句，如下面的示例中所示。

C#复制

```csharp
fixed (int* p1 = &point.x)
{
    fixed (double* p2 = &arr[5])
    {
        // Do something with p1 and p2.
    }
}
```

执行该语句中的代码之后，任何固定的变量都将被解锁并受垃圾回收的约束。 因此，请勿指向 `fixed` 语句之外的那些变量。 在 `fixed` 语句中声明的变量的作用域为该语句，使此操作更容易：

C#复制

```csharp
fixed (byte* ps = srcarray, pd = dstarray)
{
   ...
}
// ps and pd are no longer in scope here.
```

在 `fixed` 语句中初始化的指针为只读变量。 如果想要修改指针值，必须声明第二个指针变量，并修改它。 不能修改在 `fixed` 语句中声明的变量：

C#复制

```csharp
fixed (byte* ps = srcarray, pd = dstarray)
{
    byte* pSourceCopy = ps;
    pSourceCopy++; // point to the next element.
    ps++; // invalid: cannot modify ps, as it is declared in the fixed statement.
}
```

在不安全模式中，可以在堆栈上分配内存，在这种情况下，内存不受垃圾回收的约束，因此不需要固定。 有关详细信息，请参阅 [stackalloc](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/stackalloc)。

C#复制

```csharp
// Unsafe method: takes a pointer to an int.
unsafe static void SquarePtrParam(int* p)
{
    *p *= *p;
}

unsafe static void SquarePointValue()
{
    Point pt = new Point
    {
        x = 5,
        y = 6
    };
    // Pin pt in place:
    fixed (int* p = &pt.x)
    {
        SquarePtrParam(p);
    }
    // pt now unpinned.
    Console.WriteLine("{0} {1}", pt.x, pt.y);
    /*
    Output:
    25 6
     */
}
```

## [lock Statement](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/lock-statement)

`lock` 语句获取给定对象的互斥 lock，执行语句块，然后释放 lock。 持有 lock 时，持有 lock 的线程可以再次获取并释放 lock。 阻止任何其他线程获取 lock 并等待释放 lock。

`lock` 语句具有以下格式

C#复制

```csharp
lock (x)
{
    // Your code...
}
```

其中 `x` 是[引用类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/reference-types)的表达式。 它完全等同于

C#复制

```csharp
object __lockObj = x;
bool __lockWasTaken = false;
try
{
    System.Threading.Monitor.Enter(__lockObj, ref __lockWasTaken);
    // Your code...
}
finally
{
    if (__lockWasTaken) System.Threading.Monitor.Exit(__lockObj);
}
```

由于该代码使用 [try...finally](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/try-finally) 块，即使在 `lock` 语句的正文中引发异常，也会释放 lock。

在 `lock` 语句的正文中不能使用 [await](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/await) 关键字。

#### 备注

当同步对共享资源的线程访问时，请锁定专用对象实例（例如，`private readonly object balanceLock = new object();`）或另一个不太可能被代码无关部分用作 lock 对象的实例。 避免对不同的共享资源使用相同的 lock 对象实例，因为这可能导致死锁或锁争用。 具体而言，避免将以下对象用作 lock 对象：

- `this`（调用方可能将其用作 lock）。
- [Type](https://docs.microsoft.com/zh-cn/dotnet/api/system.type) 实例（可以通过 [typeof](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/typeof) 运算符或反射获取）。
- 字符串实例，包括字符串文本，（这些可能是[暂存的](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.intern#remarks)）。

#### 示例

以下示例定义了一个 `Account` 类，该类通过锁定专用的 `balanceLock` 实例来同步对其专用 `balance` 字段的访问。 使用相同的实例进行锁定可确保尝试同时调用 `Debit` 或 `Credit` 方法的两个线程无法同时更新 `balance`字段。

C#复制

```csharp
using System;
using System.Threading.Tasks;

public class Account
{
    private readonly object balanceLock = new object();
    private decimal balance;

    public Account(decimal initialBalance)
    {
        balance = initialBalance;
    }

    public decimal Debit(decimal amount)
    {
        lock (balanceLock)
        {
            if (balance >= amount)
            {
                Console.WriteLine($"Balance before debit :{balance, 5}");
                Console.WriteLine($"Amount to remove     :{amount, 5}");
                balance = balance - amount;
                Console.WriteLine($"Balance after debit  :{balance, 5}");
                return amount;
            }
            else
            {
                return 0;
            }
        }
    }

    public void Credit(decimal amount)
    {
        lock (balanceLock)
        {
            Console.WriteLine($"Balance before credit:{balance, 5}");
            Console.WriteLine($"Amount to add        :{amount, 5}");
            balance = balance + amount;
            Console.WriteLine($"Balance after credit :{balance, 5}");
        }
    }
}

class AccountTest
{
    static void Main()
    {
        var account = new Account(1000);
        var tasks = new Task[100];
        for (int i = 0; i < tasks.Length; i++)
        {
            tasks[i] = Task.Run(() => RandomlyUpdate(account));
        }
        Task.WaitAll(tasks);
    }

    static void RandomlyUpdate(Account account)
    {
        var rnd = new Random();
        for (int i = 0; i < 10; i++)
        {
            var amount = rnd.Next(1, 100);
            bool doCredit = rnd.NextDouble() < 0.5;
            if (doCredit)
            {
                account.Credit(amount);
            }
            else
            {
                account.Debit(amount);
            }
        }
    }
}
```