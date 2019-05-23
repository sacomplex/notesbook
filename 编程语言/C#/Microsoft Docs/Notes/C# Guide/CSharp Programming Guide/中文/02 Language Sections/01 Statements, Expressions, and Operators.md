[C# programming guide](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/index)

# Language Sections

## [Statements, Expressions, and Operators](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/index)

### Statements
程序执行的操作采用语句表达。 
- 常见操作包括声明变量、赋值、调用方法、循环访问集合，以及根据给定条件分支到一个或另一个代码块。 
- 语句在程序中的执行顺序称为“控制流”或“执行流”。 
  - 根据程序对运行时所收到的输入的响应，在程序每次运行时控制流可能有所不同。

语句可以是以分号结尾的单行代码，也可以是语句块中的一系列单行语句。 
语句块括在括号 {} 中，并且可以包含嵌套块。 
以下代码演示了两个单行语句示例和一个多行语句块：
```c#
static void Main()
    {
        // Declaration statement.
        int counter;

        // Assignment statement.
        counter = 1;

        // Error! This is an expression, not an expression statement.
        // counter + 1; 

        // Declaration statements with initializers are functionally
        // equivalent to  declaration statement followed by assignment statement:         
        int[] radii = { 15, 32, 108, 74, 9 }; // Declare and initialize an array.
        const double pi = 3.14159; // Declare and initialize  constant.          

        // foreach statement block that contains multiple statements.
        foreach (int radius in radii)
        {
            // Declaration statement with initializer.
            double circumference = pi * (2 * radius);

            // Expression statement (method invocation). A single-line
            // statement can span multiple text lines because line breaks
            // are treated as white space, which is ignored by the compiler.
            System.Console.WriteLine("Radius of circle #{0} is {1}. Circumference = {2:N2}",
                                    counter, radius, circumference);

            // Expression statement (postfix increment).
            counter++;

        } // End of foreach statement block
    } // End of Main method body.
} // End of SimpleStatements class.
/*
   Output:
    Radius of circle #1 = 15. Circumference = 94.25
    Radius of circle #2 = 32. Circumference = 201.06
    Radius of circle #3 = 108. Circumference = 678.58
    Radius of circle #4 = 74. Circumference = 464.96
    Radius of circle #5 = 9. Circumference = 56.55
*/
```
#### 语句的类型

> 有关详细信息，请参阅 [C# 语言规范](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/index)。 该语言规范是 C# 语法和用法的权威资料。

| 类别                                                         | C# 关键字/说明                                               |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [声明语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/statements#declaration-statements) | 声明语句引入新的变量或常量。 变量声明可以选择为变量赋值。 在常量声明中必须赋值。 |
| [表达式语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/expressions) | 用于计算值的表达式语句必须在变量中存储该值。 有关详细信息，请参阅[表达式语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/statements#expression-statements)。 |
| [选择语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/selection-statements) | 选择语句用于根据一个或多个指定条件分支到不同的代码段。 有关详细信息，请参阅下列主题：  [if](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/if-else)、[else](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/if-else)、[switch](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/switch)、[case](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/switch) |
| [迭代语句(循环语句)](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/iteration-statements) | 迭代语句用于遍历集合（如数组），或重复执行同一组语句直到满足指定的条件。 有关详细信息，请参阅下列主题：  [do](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/do)、[for](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/for)、[foreach](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/foreach-in)、[in](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/foreach-in)、[while](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/while) |
| [跳转语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/jump-statements) | 跳转语句将控制转移给另一代码段。 有关详细信息，请参阅下列主题：  [break](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/break)、[continue](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/continue)、[default](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/switch)、[goto](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/goto)、[return](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/return)、[yield](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/yield) |
| [异常处理语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/exception-handling-statements) | 异常处理语句用于从运行时发生的异常情况正常恢复。 有关详细信息，请参阅下列主题：  [throw](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/throw)、[try-catch](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/try-catch)、[try-finally](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/try-finally)、[try-catch-finally](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/try-catch-finally) |
| [Checked 和 unchecked](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/checked-and-unchecked) | Checked 和 unchecked 语句用于指定将结果存储在变量中、但该变量过小而不能容纳结果值时，是否允许数值运算导致溢出。 有关详细信息，请参阅 [checked](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/checked) 和 [unchecked](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/unchecked)。 |
| `await`语句                                                  | 如果用 [async](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/async) 修饰符标记方法，则可以使用该方法中的 [await](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/await) 运算符。 在控制到达异步方法的 `await` 表达式时，控制将返回到调用方，该方法中的进程将挂起，直到等待的任务完成为止。 任务完成后，可以在方法中恢复执行。  有关简单示例，请参阅[方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/methods)的“异步方法”一节。 有关详细信息，请参阅 [async 和 await 的异步编程](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/index)。 |
| `yield return`语句                                           | 迭代器对集合执行自定义迭代，如列表或数组。 迭代器使用 [yield return](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/yield) 语句返回元素，每次返回一个。 到达 `yield return` 语句时，会记住当前在代码中的位置。 下次调用迭代器时，将从该位置重新开始执行。  有关更多信息，请参见 [迭代器](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/iterators)。 |
| `fixed`语句                                                  | fixed 语句禁止垃圾回收器重定位可移动的变量。 有关详细信息，请参阅 [fixed](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/fixed-statement)。 |
| `lock` 语句                                                  | lock 语句用于限制一次仅允许一个线程访问代码块。 有关详细信息，请参阅 [lock](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/lock-statement)。 |
| 带标签的语句                                                 | 可以为语句指定一个标签，然后使用 [goto](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/goto) 关键字跳转到该带标签的语句。 （参见下一行中的示例。） |
| [空语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/statements#the-empty-statement) | 空语句只含一个分号。 不执行任何操作，可以在需要语句但不需要执行任何操作的地方使用。 |

#### 声明语句

以下代码显示了具有和不具有初始赋值的变量声明的示例，以及具有必要初始化的常量声明。

```c#
// Variable declaration statements.
double area;
double radius = 2;

// Constant declaration statement.
const double pi = 3.14159;
```

#### 表达式语句

以下代码显示了表达式语句的示例，包括赋值、使用赋值创建对象和方法调用。

```c#
// Expression statement (assignment).
area = 3.14 * (radius * radius);

// Error. Not  statement because no assignment:
//circ * 2;

// Expression statement (method invocation).
System.Console.WriteLine();

// Expression statement (new object creation).
System.Collections.Generic.List<string> strings =
    new System.Collections.Generic.List<string>();
```

#### 空语句

以下示例演示了空语句的两种用法：

```c#
void ProcessMessages()
{
    while (ProcessMessage())
        ; // Statement needed here.
}

void F()
{
    //...
    if (done) goto exit;
//...
exit:
    ; // Statement needed here.
}
```

#### 嵌入式语句

某些语句（包括 [do](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/do)、[while](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/while)、[for](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/for) 和 [foreach](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/foreach-in)）后面始终跟有一条嵌入式语句。 
- 此嵌入式语句可以是单个语句，也可以是语句块中括在括号 {} 内的多个语句。 

甚至可以在括号 {} 内包含单行嵌入式语句，如以下示例所示：
```c#
// Recommended style. Embedded statement in  block.
foreach (string s in System.IO.Directory.GetDirectories(
                        System.Environment.CurrentDirectory))
{
    System.Console.WriteLine(s);
}

// Not recommended.
foreach (string s in System.IO.Directory.GetDirectories(
                        System.Environment.CurrentDirectory))
    System.Console.WriteLine(s);
```

未括在括号 {} 内的嵌入式语句不能作为声明语句或带标签的语句。 下面的示例对此进行了演示：

```c#
if(pointB == true)
    //Error CS1023:
    int radius = 5; 
```

将该嵌入式语句放在语句块中以修复错误：

```c#
if (b == true)
{
    // OK:
    System.DateTime d = System.DateTime.Now;
    System.Console.WriteLine(d.ToLongDateString());
}
```

#### 嵌套(循环)语句块

语句块可以嵌套，如以下代码所示：

```c#
foreach (string s in System.IO.Directory.GetDirectories(
    System.Environment.CurrentDirectory))
{
    if (s.StartsWith("CSharp"))
    {
        if (s.EndsWith("TempFolder"))
        {
            return s;
        }
    }

}
return "Not found.";
```

#### 无法访问的语句

如果编译器认为在任何情况下控制流都无法到达特定语句，将生成警告 CS0162，如下例所示：

```c#
// An over-simplified example of unreachable code.
const int val = 5;
if (val < 4)
{
    System.Console.WriteLine("I'll never write anything."); //CS0162
}
```

### Expressions

表达式是由一个或多个操作数以及零个或多个运算符组成的序列，其计算结果为一个值、对象、方法或命名空间。
- 表达式可以包含文本值、方法调用、运算符及其操作数，或简单名称。 
  - 简单名称可以是变量名、类型成员名、方法参数名、命名空间名或类型名。

表达式可以使用运算符（运算符又可使用其他表达式作为参数）或方法调用（方法调用的参数又可以是其他方法调用），因此表达式可以非常简单，也可以极其复杂。 
下面是表达式的两个示例：

```c#
((x < 10) && ( x > 5)) || ((x > 20) && (x < 25));
   
System.Convert.ToInt32("35");  
```

> 只要从表达式中识别到变量、对象属性或对象索引器访问，该项的值都会用作表达式的值。 只要表达式的最终计算结果是所需的类型，表达式就可以置于 C# 中任何需要值或对象的位置。

#### 表达式值

在大部分使用表达式的上下文中（例如在语句或方法参数中），表达式的计算结果应为某个值。 如果 x 和 y 是整数，表达式 `x + y` 的计算结果为一个数值。 表达式 `new MyClass()` 的计算结果为对 `MyClass` 类的新实例的引用。 表达式 `myClass.ToString()` 的计算结果为一个字符串，因为字符串是该方法的返回类型。 然而，虽然命名空间名称归类为表达式，但它的计算结果不是一个值，因此绝不会作为任何表达式的最终结果。 命名空间名称不得传递给方法参数，不能用在新表达式中，也不能赋给变量。 命名空间名称只能用作较大表达式的子表达式。 同样如此的还有类型（与 [System.Type](https://docs.microsoft.com/zh-cn/dotnet/api/system.type) 对象不同）、方法组名称（与特定方法不同）以及事件 [add](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/add) 和 [remove](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/remove) 访问器。

每个值都有关联的类型。 例如，如果 x 和 y 都是 `int` 类型的变量，则表达式 `x + y` 的值也属于 `int` 类型。如果将该值赋给不同类型的变量，或者如果 x 和 y 是不同的类型，则应用类型转换规则。 若要详细了解如何进行这种转换，请参阅[强制转换和类型转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/types/casting-and-type-conversions)。

#### 溢出

如果值大于值类型的最大值，数值表达式可能导致溢出。 有关详细信息，请参阅 [Checked 和 Unchecked](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/checked-and-unchecked) 和[显式数值转换表](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/explicit-numeric-conversions-table)。

#### 运算符优先级和关联性

计算表达式的方式取决于关联性和运算符优先级规则。 有关详细信息，请参阅[运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/operators)。

除赋值表达式和方法调用表达式之外，大部分表达式都必须嵌在语句中。 有关详细信息，请参阅[语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/statements)。

#### 文本和简单名称
最简单的两种表达式类型是文本和简单名称。 文本是没有名称的常数值。 
例如，在以下代码示例中，`5` 和 `"Hello World"` 都是文本值：
```c#
// Expression statements.
int i = 5;
string s = "Hello World";
```
有关文本的详细信息，请参阅类型。
在前面的示例中，i 和 s 都是用于标识局部变量的简单名称。 在表达式中使用这些变量时，变量名称计算为当前在该变量的内存位置所存储的值。 下面的示例对此进行了演示：
```c#
int num = 5;
System.Console.WriteLine(num); // Output: 5
num = 6;
System.Console.WriteLine(num); // Output: 6            
```
#### 调用表达式

```c#
DoWork();  
```

方法调用需要方法的名称（如之前的示例中那样作为名称，或作为其他表达式的结果），后跟括号和任意方法参数。 
- 有关详细信息，请参阅[方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/methods)。 委托调用使用委托的名称和括号内的方法参数。 有关详细信息，请参阅[委托](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/delegates/index)。
- 如果方法返回一个值，则方法调用和委托调用的计算结果为该方法的返回值。 
- 返回 void 的方法不能替代表达式中的值。

#### 查询表达式

针对常规表达式的规则同样适用于查询表达式。 有关详细信息，请参阅 [LINQ 查询表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/linq-query-expressions/index)。

#### Lambda 表达式

Lambda 表达式表示没有名称但可以具有输入参数和多个语句的“内联方法”。 它们在 LINQ 中广泛用于向方法传递参数。 Lambda 表达式会编译为委托或表达式树，具体取决于使用它们的上下文。 有关详细信息，请参阅[Lambda 表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/lambda-expressions)。

#### 表达式树

使用表达式树可将表达式表示为数据结构。 表达式树由 LINQ 提供程序广泛使用，用来将查询表达式转换为在其他某些上下文（如 SQL 数据库）中有意义的代码。 有关详细信息，请参阅[表达式树 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/expression-trees/index)。

#### Expression-bodied members

C# 支持“Expression-Bodied 成员”，这允许为方法、构造函数、终结器、属性和索引器提供简洁的表达式主体定义。 有关详细信息，请参阅 [Expression-bodied members](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/expression-bodied-members)（Expression-bodied 成员）。

通过表达式主体定义，可采用非常简洁的可读形式提供成员的实现。 只要任何支持的成员（如方法或属性）的逻辑包含单个表达式，就可以使用表达式主体定义。 
表达式主体定义具有下列常规语法：

```c#
member => expression;
```
其中“expression”是有效的表达式。
C# 6 中引入了针对方法和属性 Get 访问器的表达式主体定义支持，并在 C# 7.0 中进行了扩展。 
表达式主体定义可用于下表列出的类型成员：

| 成员                                                         | 开始提供支持的版本 |
| ------------------------------------------------------------ | ------------------ |
| [方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/expression-bodied-members#methods) | C# 6               |
| [构造函数](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/expression-bodied-members#constructors) | C# 7.0             |
| [终结器](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/expression-bodied-members#finalizers) | C# 7.0             |
| [属性 Get](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/expression-bodied-members#property-get-statements) | C# 6               |
| [属性 Set](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/expression-bodied-members#property-set-statements) | C# 7.0             |
| [索引器](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/expression-bodied-members#indexers) | C# 7.0             |

##### 方法

`expression-bodied` 方法包含单个表达式，它返回的值的类型与方法的返回类型匹配；或者，对于返回 `void` 的方法，其表达式则执行某些操作。 例如，替代 [ToString](https://docs.microsoft.com/zh-cn/dotnet/api/system.object.tostring) 方法的类型通常包含单个表达式，该表达式返回当前对象的字符串表示形式。

下面的示例定义 `Person` 类，该类通过表达式主体定义替代 [ToString](https://docs.microsoft.com/zh-cn/dotnet/api/system.object.tostring)。 它还定义向控制台显示名称的 `DisplayName` 方法。 请注意，`ToString` 表达式主体定义中未使用 `return` 关键字。

```c#
using System;

public class Person
{
   public Person(string firstName, string lastName)
   {
      fname = firstName;
      lname = lastName;
   }

   private string fname;
   private string lname;
   
   public override string ToString() => $"{fname} {lname}".Trim();
   public void DisplayName() => Console.WriteLine(ToString());
}

class Example
{
   static void Main()
   {
      Person p = new Person("Mandy", "Dejesus");
      Console.WriteLine(p);
      p.DisplayName();
   }
}
```

> 有关详细信息，请参阅[方法（C# 编程指南）](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/methods)。

##### 构造函数

构造函数的表达式主体定义通常包含单个赋值表达式或一个方法调用，该方法调用可处理构造函数的参数，也可初始化实例状态。

以下示例定义 `Location` 类，其构造函数具有一个名为“name”的字符串参数。 表达式主体定义向 `Name` 属性分配参数。

```c#
public class Location
{
   private string locationName;
   
   public Location(string name) => Name = name;

   public string Name
   {
      get => locationName;
      set => locationName = value;
   } 
}
```

> 有关详细信息，请参阅[构造函数（C# 编程指南）](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/constructors)。

##### 终结器

终结器的表达式主体定义通常包含清理语句，例如释放非托管资源的语句。

下面的示例定义了一个终结器，该终结器使用表达式主体定义来指示已调用该终结器。

```c#
using System;

public class Destroyer
{
   public override string ToString() => GetType().Name;
   
   ~Destroyer() => Console.WriteLine($"The {ToString()} destructor is executing.");
}
```

##### 属性 Get 语句

如果选择自行实现属性 Get 访问器，可以对只返回属性值的单个表达式使用表达式主体定义。 请注意，未使用 `return` 语句。

下面的示例定义 `Location.Name` 属性，其属性 Get 访问器返回支持该属性的私有 `locationName` 字段的值。

```c#
public class Location
{
   private string locationName;
   
   public Location(string name) => Name = name;

   public string Name
   {
      get => locationName;
      set => locationName = value;
   } 
}
```

不使用显式 `set` 语句也可实现使用表达式主体定义的只读属性。 语法为：

```c#
PropertyName => returnValue;
```

下面的示例定义 `Location` 类，其只读 `Name` 属性以表达式主体定义的形式实现，该表达式主体定义返回私有 `locationName` 字段值。

```c#
public class Location
{
   private string locationName;
   
   public Location(string name) => locationName = name;

   public string Name => locationName;
}
```

> 有关详细信息，请参阅[属性（C# 编程指南）](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/properties)。

##### 属性 Set 语句

如果选择自行实现属性 `Set `访问器，可以对单行表达式使用表达式主体定义，该单行表达式用于对支持该属性的字段赋值。

下面的示例定义 `Location.Name` 属性，其属性 Set 语句将其输入参数赋给支持该属性的私有 `locationName` 字段。

```c#
public class Location
{
   private string locationName;
   
   public Location(string name) => Name = name;

   public string Name
   {
      get => locationName;
      set => locationName = value;
   } 
}
```

> 有关详细信息，请参阅[属性（C# 编程指南）](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/properties)。

##### 索引器

与属性一样，如果索引器的 Get 访问器包含单个返回值的语句或其 Set 访问器执行简单的赋值，则 Get 和 Set 访问器包含表达式主体定义。

下面的示例定义名为 `Sports` 的类，其中包含一个内部 [String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string) 数组，该数组包含大量体育运动的名称。 索引器的 Get 和 Set 访问器都以表达式主体定义的形式实现。

```c#
using System;
using System.Collections.Generic;

public class Sports
{
   private string[] types = { "Baseball", "Basketball", "Football", 
                              "Hockey", "Soccer", "Tennis", 
                              "Volleyball" }; 

   public string this[int i]
   {
      get => types[i];
      set => types[i] = value;
   }
}
```

> 有关详细信息，请参阅[索引器（C# 编程指南）](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/indexers/index)。

### Operators

在 C# 中，运算符 是应用于表达式或语句中的一个或多个操作数 的程序元素。 
- 接受一个操作数的运算符称为`++`一元 `new`运算符
  - 例如递增运算符 ( *) 或* 。 
- 接受两个操作数的运算符称为`+`二元`-`运算符
  - 例如算术运算符（`*`、`/`、 *、* ）。 
- 条件运算符`?:`接受三个操作数，是 C# 中唯一的三元运算符。

下面的 C# 语句包含一个一元运算符和一个操作数。 递增运算符 `++`修改操作数 `y`的值。

```c#
y++;
```

下面的 C# 语句包含两个二元运算符，它们分别有两个操作数。 赋值运算符 `=` 将一个整数变量 `y` 和一个表达式 `2 + 3` 作为操作数。 表达式 `2 + 3` 本身由加法运算符和两个操作数 `2` 和 `3` 组成。

```c#
y = 2 + 3;
```

> 有关详细信息，请参阅[运算符关键字](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator-keywords)和 [C# 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/index)。

#### 运算符、计算和运算符优先级

操作数可以是由任何长度的代码组成的有效表达式，且可包含任意数量的子表达式。 在包含多个运算符的表达式中，运算符的应用顺序由运算符优先级 、关联性 和括号确定。

每个运算符都具有已定义的优先级。 在包含具有不同优先级级别的多个运算符的表达式中，运算符的优先级确定运算符的计算顺序。 例如，下列语句将 3 赋给 `n1`。

```
n1 = 11 - 2 * 4;
```

因为乘法的优先级高于减法，所以首先执行乘法。

下表根据运算符执行的操作类型将它们划分到不同的类别中。 类别按优先级顺序列出。

##### 主要运算符

| 表达式                                                       | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| x[.](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/member-access-operator)y  x?.y | 成员访问  条件成员访问                                       |
| f[(x)](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/invocation-operator) | 方法和委托调用                                               |
| a[[x\]](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/index-operator)  a?[x] | 数组和索引器访问  条件数组和索引器访问                       |
| x[++](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/increment-operator) | 后递增                                                       |
| x[--](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/decrement-operator) | 后递减                                                       |
| [new](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/new-operator) T(...) | 对象和委托创建                                               |
| `new` T(...){...}                                            | 具有初始值设定项的对象创建。 请参阅[对象和集合初始值设定项](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/object-and-collection-initializers)。 |
| `new` {...}                                                  | 匿名对象初始值设定项。 请参阅[匿名类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/anonymous-types)。 |
| `new` T[...]                                                 | 数组创建。 请参阅[数组](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/arrays/index)。 |
| [typeof](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/typeof)(T) | 获取 T 的 System.Type 对象                                   |
| [checked](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/checked)(x) | 在已检查的上下文中计算表达式                                 |
| [unchecked](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/unchecked)(x) | 在未检查的上下文中计算表达式                                 |
| [default](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/default) (T) | 获取类型 T 的默认值                                          |
| [委托](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/delegate) {} | 匿名函数（匿名方法）                                         |

##### 一元运算符

| 表达式                                                       | 说明                  |
| ------------------------------------------------------------ | --------------------- |
| [+](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/addition-operator)x | 标识                  |
| [-](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/subtraction-operator)x | 求反                  |
| [!](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/logical-negation-operator)x | 逻辑求反              |
| [~](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/bitwise-complement-operator)x | 按位求反              |
| [++](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/increment-operator)x | 前递增                |
| [--](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/decrement-operator)x | 前递减                |
| [(T)](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/invocation-operator)x | 将 x 显式转换为类型 T |

##### 乘法运算符

| 表达式                                                       | 说明 |
| ------------------------------------------------------------ | ---- |
| [*](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/multiplication-operator) | 乘法 |
| [/](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/division-operator) | 除号 |
| [%](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/modulus-operator) | 余数 |

##### 相加运算符

| 表达式                                                       | 说明                       |
| ------------------------------------------------------------ | -------------------------- |
| x [+](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/addition-operator) y | 相加、字符串串联、委托组合 |
| x [-](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/subtraction-operator) y | 相减、委托移除             |

##### 移位运算符

| 表达式                                                       | 说明 |
| ------------------------------------------------------------ | ---- |
| x [<<](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/left-shift-operator) y | 左移 |
| x [>>](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/right-shift-operator) y | 右移 |

##### 关系和类型运算符

| 表达式                                                       | 说明                                          |
| ------------------------------------------------------------ | --------------------------------------------- |
| x [<](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/less-than-operator) y | 小于                                          |
| x [>](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/greater-than-operator) y | 大于                                          |
| x [<=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/less-than-equal-operator) y | 小于或等于                                    |
| x [>=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/greater-than-equal-operator) y | 大于或等于                                    |
| x [is](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/is) T | 如果 x 为 T，则返回 True；否则返回 False。    |
| x [as](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/as) T | 返回类型为 T 的 x，如果 x 不是 T，则返回 null |

##### 相等运算符

| 表达式                                                       | 说明   |
| ------------------------------------------------------------ | ------ |
| x [==](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/equality-comparison-operator) y | 等于   |
| x [!=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/not-equal-operator) y | 不等于 |

##### 逻辑、条件和 Null 运算符

| 类别      | 表达式                                                       | 说明                                                         |
| --------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 逻辑“与”  | x [&](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/and-operator) y | 整型按位“与”，布尔型逻辑“与”                                 |
| 逻辑 XOR  | x [^](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/xor-operator) y | 整数型位 XOR，布尔型逻辑 XOR                                 |
| 逻辑“或”  | x [\|](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/or-operator) y | 整数型位 OR，布尔型逻辑 OR                                   |
| 条件“与”  | x [&&](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/conditional-and-operator) y | 仅当 x 为 True 时计算 y                                      |
| 条件“或”  | x [\|\|](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/conditional-or-operator) y | 仅当 x 为 False 时计算 y                                     |
| null 合并 | x [??](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/null-coalescing-operator) y | 如果 x 为 Null，则计算结果为 y，否则计算结果为 x             |
| 条件运算  | x [?](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/conditional-operator) y : z | 如果 x 为 True，则计算结果为 y；如果 x 为 False 则计算结果为 z |

##### 赋值和匿名运算符

| 表达式                                                       | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/assignment-operator) | 赋值                                                         |
| x op= y                                                      | 复合赋值。 支持以下运算符：[+=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/addition-assignment-operator)、[-=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/subtraction-assignment-operator)、[*=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/multiplication-assignment-operator)、[/=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/division-assignment-operator)、[%=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/modulus-assignment-operator)、[&=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/and-assignment-operator)、[\|=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/or-assignment-operator)、[^=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/xor-assignment-operator)、[<<=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/left-shift-assignment-operator)、[>>=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/right-shift-assignment-operator) |
| (T x) [=>](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/lambda-operator) y | 匿名函数（lambda 表达式）                                    |

#### 结合性

当表达式中出现两个或两个以上具有相同优先级的运算符时，将根据结合性计算它们。 
- 左结合运算符按从左到右的顺序计算。 
  - 例如，`x * y / z` 将计算为 `(x * y) / z`。 
- 右结合运算符按从右到左的顺序计算。 
  - 例如，赋值运算符是右关联的。 如果不是，下面的代码将导致错误。

```c#
int a, b, c;  
c = 1;  
// The following two lines are equivalent.  
a = b = c;  
a = (b = c);  
  
// The following line, which forces left associativity, causes an error.  
//(a = b) = c;  
```

再举一个例子，三元运算符 ([?:](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/conditional-operator)) 是右结合运算符。 
- 大多数的二元运算符是左结合运算符。

无论表达式中的运算符是左结合运算符还是右结合运算符，都将先从左至右评估各表达式的操作数。 
以下示例显示运算符和操作数的计算顺序。

| 语句            | 计算顺序            |
| --------------- | ------------------- |
| `a = b`         | a、b、=             |
| `a = b + c`     | a、b、c、+、=       |
| `a = b + c * d` | a、b、c、d、*、+、= |
| `a = b * c + d` | a、b、c、*、d、+、= |
| `a = b - c + d` | a、b、c、-、d、+、= |
| `a += b -= c`   | a、b、c、-=、+=     |

#### 添加括号

可通过使用圆括号更改运算符优先级和相关性。例如，`2 + 3 * 2` 通常计算结果为 8，因为乘法运算符的优先级高于加法运算符。 但是，如果你将表达式编写为 `(2 + 3) * 2`，则先计算加法，再计算乘法，且结果为 10。 以下示例显示括号表达式中的计算顺序。 如前面的示例中所示，计算操作数之前会应用运算符。

| 语句                    | 计算顺序                  |
| ----------------------- | ------------------------- |
| `a = (b + c) * d`       | a、b、c、+、d、*、=       |
| `a = b - (c + d)`       | a、b、c、d、+、-、=       |
| `a = (b + c) * (d - e)` | a、b、c、+、d、e、-、*、= |

#### 运算符重载

对于自定义类和结构，你可以更改运算符的行为。 此过程称为“运算符重载” 。 有关详细信息，请参阅[可重载运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/overloadable-operators)和[运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator)关键字文章。

### Anonymous Functions

匿名函数是一个“内联”语句或表达式，可在需要委托类型的任何地方使用。 可以使用匿名函数来初始化命名委托，或传递命名委托（而不是命名委托类型）作为方法参数。

共有两种匿名函数，以下主题中分别讨论了这些函数：
- [Lambda 表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/lambda-expressions)。
- [匿名方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/anonymous-methods)

> Lambda 表达式可以绑定到表达式树，也可以绑定到委托。

#### The Evolution of Delegates in C#
- 在 C# 1.0 中，通过使用在代码中其他位置定义的方法显式初始化委托来创建委托的实例。 
- C# 2.0 引入了匿名方法的概念，作为一种编写可在委托调用中执行的未命名内联语句块的方式
- C# 3.0 引入了 lambda 表达式，这种表达式与匿名方法的概念类似，但更具表现力并且更简练。 这两个功能统称为*匿名函数*。 
  - 通常，面向 .NET Framework 3.5 及更高版本的应用程序应使用 lambda 表达式。

下面的示例演示从 C# 1.0 到 C# 3.0 委托创建过程的发展：
```c#
class Test
{
    delegate void TestDelegate(string s);
    static void M(string s)
    {
        Console.WriteLine(s);
    }

    static void Main(string[] args)
    {
        // Original delegate syntax required 
        // initialization with a named method.
        TestDelegate testDelA = new TestDelegate(M);

        // C# 2.0: A delegate can be initialized with
        // inline code, called an "anonymous method." This
        // method takes a string as an input parameter.
        TestDelegate testDelB = delegate(string s) { Console.WriteLine(s); };

        // C# 3.0. A delegate can be initialized with
        // a lambda expression. The lambda also takes a string
        // as an input parameter (x). The type of x is inferred by the compiler.
        TestDelegate testDelC = (x) => { Console.WriteLine(x); };

        // Invoke the delegates.
        testDelA("Hello. My name is M and I write lines.");
        testDelB("That's nothing. I'm anonymous and ");
        testDelC("I'm a famous author.");

        // Keep console window open in debug mode.
        Console.WriteLine("Press any key to exit.");
        Console.ReadKey();
    }
}
/* Output:
    Hello. My name is M and I write lines.
    That's nothing. I'm anonymous and
    I'm a famous author.
    Press any key to exit.
 */
```

> 有关详细信息，请参阅 [C# 语言规范](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/index)。 该语言规范是 C# 语法和用法的权威资料。

> C# 6.0 Cookbook 中的委托、事件和 Lambda 表达式章节

#### [Lambda expressions](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/lambda-expressions)
Lambda 表达式是一种可用于创建 [委托](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/anonymous-methods) 或 [表达式目录树](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/delegates/using-delegates) 类型的 [匿名函数](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/expression-trees/index) 。 通过使用 lambda 表达式，可以写入可作为参数传递或作为函数调用值返回的本地函数。 Lambda 表达式对于编写 LINQ 查询表达式特别有用。

若要创建 Lambda 表达式，需要在 Lambda 运算符 [=>](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/lambda-operator)左侧指定输入参数（如果有），然后在另一侧输入表达式或语句块。 例如，lambda 表达式 `x => x * x` 指定名为 `x` 的参数并返回 `x` 的平方值。 如下面的示例所示，你可以将此表达式分配给委托类型：
```c#
delegate int del(int i);  
static void Main(string[] args)  
{  
    del myDelegate = x => x * x;  
    int j = myDelegate(5); //j = 25  
}  
```

若要创建表达式目录树类型：
```c#
using System.Linq.Expressions;  
  
namespace ConsoleApplication1  
{  
    class Program  
    {  
        static void Main(string[] args)  
        {  
            Expression<del> myET = x => x * x;  
        }  
    }  
}  
```
`=>` 运算符具有与赋值运算符 (`=`) 相同的优先级并且是[右结合运算](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/operators)（参见“运算符”文章的“结合性”部分）。

Lambda 在基于方法的 LINQ 查询中用作标准查询运算符方法（如 [Where](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.where)）的参数。

使用基于方法的语法在 [Where](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.where) 类中调用 [Enumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable) 方法时（如在 LINQ to Objects 和 LINQ to XML中一样），参数是委托类型 [System.Func](https://docs.microsoft.com/zh-cn/dotnet/api/system.func-2)。 使用 Lambda 表达式创建该委托最为方便。 例如，在 [System.Linq.Queryable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable) 类中调用相同的方法时（如在 LINQ to SQL 中一样），参数类型为 [System.Linq.Expressions.Expression](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions.expression)<Func>，其中 Func 是最多具有十六个输入参数的任何一个 Func 委托。 同样，Lambda 表达式只是一种非常简洁的构造该表达式目录树的方式。 尽管事实上通过 Lambda 创建的对象具有不同的类型，但 Lambda 使得 `Where` 调用看起来类似。

在上一个示例中，请注意委托签名具有一个 `int`类型的隐式类型输入参数，并返回 `int`。 可以将 Lambda 表达式转换为该类型的委托，因为该表达式也具有一个输入参数 (`x`)，以及一个编译器可隐式转换为 `int` 类型的返回值。 （以下几节中将对类型推理进行详细讨论。）使用输入参数 5 调用委托时，它将返回结果 25。

在 [is](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/is) 或 [as](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/as) 运算符的左侧不允许使用 Lambda。

适用于匿名方法的所有限制也适用于 Lambda 表达式。 有关详细信息，请参阅[匿名方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/anonymous-methods)。

##### 表达式 lambda
表达式位于 => 运算符右侧的 Lambda 表达式称为“表达式 lambda”。 表达式 lambda 广泛用于[表达式树](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/expression-trees/index)的构造。表达式 lambda 会返回表达式的结果，并采用以下基本形式：
```c#
(input-parameters) => expression
```

仅当 lambda 只有一个输入参数时，括号才是可选的；否则括号是必需的。 括号内的两个或更多输入参数使用逗号加以分隔：
```c#
(x, y) => x == y
```

有时，编译器难以或无法推断输入类型。 如果出现这种情况，你可以按以下示例中所示方式显式指定类型：
```c#
(int x, string s) => s.Length > x
```
输入参数类型必须全部为显式或全部为隐式；否则，C# 将生成 [CS0748](https://docs.microsoft.com/zh-cn/dotnet/csharp/misc/cs0748) 编译器错误。

使用空括号指定零个输入参数：
```c#
() => SomeMethod()
```
在上一个示例中，请注意表达式 Lambda 的主体可以包含一个方法调用。 但是，如果要创建在 .NET Framework 之外计算的表达式目录树（例如，在 SQL Server 中），则不应在 lambda 表达式中使用方法调用。 在 .NET 公共语言运行时上下文之外，方法将没有任何意义。

##### 语句 lambda
语句 lambda 与表达式 lambda 表达式类似，只是语句括在大括号中：
(input-parameters) => { statement; }
语句 lambda 的主体可以包含任意数量的语句；但是，实际上通常不会多于两个或三个。
```c#
delegate void TestDelegate(string s);
```
```c#
TestDelegate del = n => { string s = n + " World"; 
                          Console.WriteLine(s); };
```
像匿名方法一样，语句 lambda 也不能用于创建表达式目录树。

##### 异步 lambda
通过使用 [async](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/async) 和 [await](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/await) 关键字，你可以轻松创建包含异步处理的 lambda 表达式和语句。 例如，下面的 Windows 窗体示例包含一个调用和等待异步方法 `ExampleMethodAsync`的事件处理程序。

```c#
public partial class Form1 : Form  
{  
    public Form1()  
    {  
        InitializeComponent();  
    }  
  
    private async void button1_Click(object sender, EventArgs e)  
    {  
        // ExampleMethodAsync returns a Task.  
        await ExampleMethodAsync();  
        textBox1.Text += "\r\nControl returned to Click event handler.\n";  
    }  
  
    async Task ExampleMethodAsync()  
    {  
        // The following line simulates a task-returning asynchronous process.  
        await Task.Delay(1000);  
    }  
}  
```

你可以使用异步 lambda 添加同一事件处理程序。 若要添加此处理程序，请在 lambda 参数列表前添加一个 `async` 修饰符，如下例所示。

```c#
public partial class Form1 : Form  
{  
    public Form1()  
    {  
        InitializeComponent();  
        button1.Click += async (sender, e) =>  
        {  
            // ExampleMethodAsync returns a Task.  
            await ExampleMethodAsync();  
            textBox1.Text += "\nControl returned to Click event handler.\n";  
        };  
    }  
  
    async Task ExampleMethodAsync()  
    {  
        // The following line simulates a task-returning asynchronous process.  
        await Task.Delay(1000);  
    }  
}  
```

> 有关如何创建和使用异步方法的详细信息，请参阅[使用 Async 和 Await 的异步编程](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/index)。

##### 含标准查询运算符的 lambda

许多标准查询运算符都具有输入参数，其类型是泛型委托系列 [Func](https://docs.microsoft.com/zh-cn/dotnet/api/system.func-2) 中的一种。 这些委托使用类型参数来定义输入参数的数量和类型，以及委托的返回类型。 `Func` 委托对于封装用户定义的表达式非常有用，这些表达式将应用于一组源数据中的每个元素。 例如，请考虑以下委托类型：

```c#
public delegate TResult Func<TArg0, TResult>(TArg0 arg0)  
```

可以将委托实例化为 `Func<int,bool> myFunc` ，其中 `int` 是输入参数， `bool` 是返回值。 返回值始终在最后一个类型参数中指定。 `Func<int, string, bool>` 定义包含两个输入参数（ `int` 和 `string`）且返回类型为 `bool`的委托。 当调用下面的 `Func` 委托时，该委托将返回 true 或 false 以指示输入参数是否等于 5：

```c#
Func<int, bool> myFunc = x => x == 5;  
bool result = myFunc(4); // returns false of course  
```

当参数类型为 `Expression<Func>`时，你也可以提供 Lambda 表达式，例如在 System.Linq.Queryable 内定义的标准查询运算符中。 如果指定 `Expression<Func>` 参数，lambda 将编译为表达式目录树。

此处显示了一个标准查询运算符， [Count](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.count) 方法：

```c#
int[] numbers = { 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };  
int oddNumbers = numbers.Count(n => n % 2 == 1);  
```

编译器可以推断输入参数的类型，或者你也可以显式指定该类型。 这个特殊 lambda 表达式将计算那些除以 2 时余数为 1 的整数的数量 (`n`)。

下面一行代码将生成一个序列，其中包含 `numbers` 数组中在 9 左侧的所有元素，因为它是序列中第一个不满足条件的数字：

```c#
var firstNumbersLessThan6 = numbers.TakeWhile(n => n < 6);  
```
此示例展示了如何通过将输入参数括在括号中来指定多个输入参数。 该方法将返回数字数组中的所有元素，直至遇到一个值小于其位置的数字为止。 不要将 lambda 运算符 (=>) 与大于等于运算符 (>=) 混淆。
```c#
var firstSmallNumbers = numbers.TakeWhile((n, index) => n >= index);  
```

##### lambda 中的类型推理

在编写 lambda 时，通常不必为输入参数指定类型，因为编译器可以根据 lambda 主体、参数的委托类型以及 C# 语言规范中描述的其他因素来推断类型。 对于大多数标准查询运算符，第一个输入是源序列中的元素类型。 因此，如果要查询 `IEnumerable<Customer>`，则输入变量将被推断为 `Customer` 对象，这意味着你可以访问其方法和属性：

```c#
customers.Where(c => c.City == "London");  
```

Lambda 的一般规则如下：

- Lambda 包含的参数数量必须与委托类型包含的参数数量相同。
- Lambda 中的每个输入参数必须都能够隐式转换为其对应的委托参数。
- Lambda 的返回值（如果有）必须能够隐式转换为委托的返回类型。

请注意，lambda 表达式本身没有类型，因为常规类型系统没有“Lambda 表达式”这一内部概念。 但是，有时以一种非正式的方式谈论 lambda 表达式的“类型”会很方便。 在这些情况下，类型是指委托类型或 lambda 表达式所转换到的 [Expression](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions.expression) 类型。

##### lambda 表达式中的变量范围

在定义 lambda 函数的方法内或包含 Lambda 表达式的类型内，Lambda 可以引用范围内的外部变量（请参阅[匿名方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/anonymous-methods)）。 以这种方式捕获的变量将进行存储以备在 lambda 表达式中使用，即使在其他情况下，这些变量将超出范围并进行垃圾回收。 必须明确地分配外部变量，然后才能在 lambda 表达式中使用该变量。 下面的示例演示这些规则：

```c#
delegate bool D();  
delegate bool D2(int i);  
  
class Test  
{  
    D del;  
    D2 del2;  
    public void TestMethod(int input)  
    {  
        int j = 0;  
        // Initialize the delegates with lambda expressions.  
        // Note access to 2 outer variables.  
        // del will be invoked within this method.  
        del = () => { j = 10;  return j > input; };  
  
        // del2 will be invoked after TestMethod goes out of scope.  
        del2 = (x) => {return x == j; };  
  
        // Demonstrate value of j:  
        // Output: j = 0   
        // The delegate has not been invoked yet.  
        Console.WriteLine("j = {0}", j);        // Invoke the delegate.  
        bool boolResult = del();  
  
        // Output: j = 10 b = True  
        Console.WriteLine("j = {0}. b = {1}", j, boolResult);  
    }  
  
    static void Main()  
    {  
        Test test = new Test();  
        test.TestMethod(5);  
  
        // Prove that del2 still has a copy of  
        // local variable j from TestMethod.  
        bool result = test.del2(10);  
  
        // Output: True  
        Console.WriteLine(result);  
  
        Console.ReadKey();  
    }  
}  
```

下列规则适用于 lambda 表达式中的变量范围：

- 捕获的变量将不会被作为垃圾回收，直至引用变量的委托符合垃圾回收的条件。
- 在外部方法中看不到 lambda 表达式内引入的变量。
- Lambda 表达式无法从封闭方法中直接捕获 `in`、`ref` 或 `out` 参数。
- Lambda 表达式中的返回语句不会导致封闭方法返回。
- 如果跳转语句的目标在块外部，则 lambda 表达式不能包含位于 lambda 函数内部的 `goto` 语句、 `break`语句或 `continue` 语句。 同样，如果目标在块内部，则在 lambda 函数块外部使用跳转语句也是错误的。

##### [How to: Use Lambda Expressions in a Query](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/how-to-use-lambda-expressions-in-a-query)

不会直接在查询语法中使用 lambda 表达式，而是在方法调用中使用它们，并且查询表达式可以包含方法调用。事实上，一些查询操作只能采用方法语法进行表示。 有关查询语法与方法语法之间的差异的详细信息，请参阅 [LINQ 中的查询语法和方法语法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/query-syntax-and-method-syntax-in-linq)。

###### 示例1

下面的示例演示如何通过 [Enumerable.Where](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.where) 标准查询运算符，在基于方法的查询中使用 lambda 表达式。 请注意，此示例中的 [Where](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.where) 方法具有一个 [Func](https://docs.microsoft.com/zh-cn/dotnet/api/system.func-1) 委托类型的输入参数，该委托采用整数作为输入并返回一个布尔值。 Lambda 表达式可以转换为该委托。 如果这是使用 [Queryable.Where](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.where) 方法的 LINQ to SQL 查询，则参数类型会是 `Expression<Func<int,bool>>`，但 lambda 表达式看起来完全相同。 有关表达式类型的详细信息，请参阅 [System.Linq.Expressions.Expression](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions.expression)。

```c#
class SimpleLambda
{
    static void Main()
    {

        // Data source.
        int[] scores = { 90, 71, 82, 93, 75, 82 };

        // The call to Count forces iteration of the source
        int highScoreCount = scores.Where(n => n > 80).Count();

        Console.WriteLine("{0} scores are greater than 80", highScoreCount);

        // Outputs: 4 scores are greater than 80            
    }
}
```

###### 示例2

下面的示例演示如何在查询表达式的方法调用中使用 lambda 表达式。 需要 lambda 的原因是无法使用查询语法调用 [Sum](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.sum) 标准查询运算符。

查询首先根据学生的年级（在 `GradeLevel` 枚举中定义）对学生进行分组。 然后为每个组添加每个学生的总分。这需要两个 `Sum` 操作。 内部 `Sum` 为每个学生计算总分，而外部 `Sum` 保留组中所有学生的正在运行的合并总分。

```c#
private static void TotalsByGradeLevel()
{
    // This query retrieves the total scores for First Year students, Second Years, and so on.
    // The outer Sum method uses a lambda in order to specify which numbers to add together.
    var categories =
    from student in students
    group student by student.Year into studentGroup
    select new { GradeLevel = studentGroup.Key, TotalScore = studentGroup.Sum(s => s.ExamScores.Sum()) };

    // Execute the query.   
    foreach (var cat in categories)
    {
        Console.WriteLine("Key = {0} Sum = {1}", cat.GradeLevel, cat.TotalScore);
    }
}
/*
     Outputs: 
     Key = SecondYear Sum = 1014
     Key = ThirdYear Sum = 964
     Key = FirstYear Sum = 1058
     Key = FourthYear Sum = 974
*/
```

##### 编译代码

若要运行此代码，请将方法复制并粘贴到[操作说明：查询对象集合](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/linq-query-expressions/how-to-query-a-collection-of-objects)中提供的 `StudentClass` 内，并通过 `Main` 方法调用它。

##### [How to: Use Lambda Expressions Outside LINQ](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/how-to-use-lambda-expressions-outside-linq)

Lambda 表达式并不只限于在 LINQ 查询中使用。 可以在需要委托值的任何地方（也就是在可以使用匿名方法的任何地方）使用这些表达式。 下面的示例演示如何在 Windows 窗体事件处理程序中使用 lambda 表达式。 请注意，输入的类型（[Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object) 和 [MouseEventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.forms.mouseeventargs)）由编译器推理，因此不必在 lambda 输入参数中显式给定。

```c#
public partial class Form1 : Form  
{  
    public Form1()  
    {  
        InitializeComponent();  
        // Use a lambda expression to define an event handler.  
       this.Click += (s, e) => { MessageBox.Show(((MouseEventArgs)e).Location.ToString());};  
    }  
}  
```

#### [Anonymous Methods](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/anonymous-methods)

在 2.0 之前的 C# 版本中，声明[委托](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/delegate)的唯一方式是使用[命名方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/delegates/delegates-with-named-vs-anonymous-methods)。 C# 2.0 引入匿名方法，在 C# 3.0 及更高版本中，Lambda 表达式取代匿名方法作为编写内联代码的首选方式。 但是，本主题中有关匿名方法的信息也适用于 Lambda 表达式。 在有一种情况下，匿名方法提供 Lambda 表达式中没有的功能。 使用匿名方法可省略参数列表。 这意味着匿名方法可转换为具有多种签名的委托。 Lambda 表达式无法实现这一点。 有关 Lambda 表达式的详细信息，请参阅 [Lambda 表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/lambda-expressions)。

创建匿名方法实际上是一种将代码块作为委托参数传递的方式。 这里是两个示例：

```c#
// Create a handler for a click event.
button1.Click += delegate(System.Object o, System.EventArgs e)
                   { System.Windows.Forms.MessageBox.Show("Click!"); };
```

```c#
// Create a delegate.
delegate void Del(int x);

// Instantiate the delegate using an anonymous method.
Del d = delegate(int k) { /* ... */ };
```

由于使用匿名方法无需创建单独的方法，因此可减少对委托进行实例化的编码开销。

例如，在因不得不创建方法而可能出现非必要开销的情况下，指定代码块（而不是委托）很有用处。 开始新线程就是一个很好的示例。 此类创建一个线程，且还包含该线程执行的代码，而无需为委托创建其他方法。

```c#
void StartThread()
{
    System.Threading.Thread t1 = new System.Threading.Thread
      (delegate()
            {
                System.Console.Write("Hello, ");
                System.Console.WriteLine("World!");
            });
    t1.Start();
}
```

##### 备注

匿名方法的参数范围为匿名方法块。

如果目标在匿名方法块之外，匿名方法块内具有 [goto](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/goto)、[break](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/break) 或 [continue](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/continue) 等跳转语句是一种错误。 如果目标在匿名方法块之内，匿名方法块外具有 `goto`、`break` 或 `continue` 等跳转语句也是一种错误。

范围包含匿名方法声明的本地变量和参数称为此匿名方法的外部变量。 例如，在如下代码段中，`n` 是一个外部变量：

```c#
int n = 0;
Del d = delegate() { System.Console.WriteLine("Copy #:{0}", ++n); };
```

创建委托时，对外部变量 `n` 的引用被视为已捕获。 不同于本地变量，已捕获的变量的生存期一直延伸至引用匿名方法的委托具有垃圾回收资格为止。

匿名方法无法访问外部范围的 [in](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/in)、[ref](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ref) 或 [out](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/out-parameter-modifier) 参数。

无法在匿名方法块内访问任何不安全代码。

不允许在 [is](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/is) 运算符左侧使用匿名方法。

##### 示例

如下示例演示实例化委托的两种方式：

- 将委托与匿名方法相关联。
- 将委托与命名方法 (`DoWork`) 相关联。

在每一种情况下，调用委托时均显示一条消息。

```c#
// Declare a delegate.
delegate void Printer(string s);

class TestClass
{
    static void Main()
    {
        // Instantiate the delegate type using an anonymous method.
        Printer p = delegate(string j)
        {
            System.Console.WriteLine(j);
        };

        // Results from the anonymous delegate call.
        p("The delegate using the anonymous method is called.");

        // The delegate instantiation using a named method "DoWork".
        p = DoWork;

        // Results from the old style delegate call.
        p("The delegate using the named method is called.");
    }

    // The method associated with the named delegate.
    static void DoWork(string k)
    {
        System.Console.WriteLine(k);
    }
}
/* Output:
    The delegate using the anonymous method is called.
    The delegate using the named method is called.
*/
```

### [Overloadable operators](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/overloadable-operators)

C# 通过使用 [operator](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator) 关键字定义静态成员函数，来允许用户定义的类型重载运算符。 不过并非所有运算符都可以进行重载，并且其他运算符具有限制，如下表所列：

| 运算符                                                       | 可重载性                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [+](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/addition-operator)、[-](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/subtraction-operator)、[!](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/logical-negation-operator)、[~](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/bitwise-complement-operator)、[++](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/increment-operator)、[--](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/decrement-operator)、[true](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/true)、[false](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/false) | 这些一元运算符可以进行重载。                                 |
| [+](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/addition-operator), [-](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/subtraction-operator), [*](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/multiplication-operator), [/](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/division-operator), [%](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/modulus-operator), [&](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/and-operator), [\|](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/or-operator), [^](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/xor-operator), [<<](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/left-shift-operator), [>>](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/right-shift-operator) | 这些二元运算符可以进行重载。                                 |
| [==](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/equality-comparison-operator), [!=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/not-equal-operator), [<](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/less-than-operator), [>](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/greater-than-operator), [<=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/less-than-equal-operator), [>=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/greater-than-equal-operator) | 比较运算符可以进行重载（但是请参阅此表后面的备注）。         |
| [&&](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/conditional-and-operator), [\|\|](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/conditional-or-operator) | 条件逻辑运算符无法进行重载，但是它们使用 `&` 和 `|`（可以进行重载）来计算。 |
| [[\]](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/index-operator) | 数组索引运算符无法进行重载，但是可以定义[索引器](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/indexers/index)。 |
| [(T)x](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/invocation-operator) | 强制转换运算符无法进行重载，但是可以定义新转换运算符（请参阅 [explicit](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/explicit) 和 [implicit](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/implicit)）。 |
| [+=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/addition-assignment-operator), [-=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/subtraction-assignment-operator), [*=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/multiplication-assignment-operator), [/=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/division-assignment-operator), [%=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/modulus-assignment-operator), [&=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/and-assignment-operator), [\|=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/or-assignment-operator), [^=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/xor-assignment-operator), [<<=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/left-shift-assignment-operator), [>>=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/right-shift-assignment-operator) | 赋值运算符不能显式重载。 但在重载二元运算符时，也会隐式重载相应的赋值运算符（若有）。 例如，使用 `+`（可以进行重载）计算 `+=`。 |
| [=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/assignment-operator)、[.](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/member-access-operator)、[?:](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/conditional-operator)、[??](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/null-coalescing-operator)、[->](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/dereference-operator)、[=>](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/lambda-operator)、[f(x)](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/invocation-operator)、[as](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/as)、[checked](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/checked)、[unchecked](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/unchecked)、[default](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/default-value-expressions)、[delegate](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/anonymous-methods)、[is](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/is)、[new](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/new)、[sizeof](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/sizeof)、[typeof](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/typeof) | 这些运算符无法进行重载。                                     |

> 如果进行重载，则比较运算符必须成对进行重载；也就是说，如果 `==` 进行重载，则 `!=` 也必须进行重载。反过来也成立，其中重载 `!=` 需要重载 `==`。 对于比较运算符 `<` 和 `>`，以及 `<=` 和 `>=`，也成立。

> 有关如何重载运算符的信息，请参阅[运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator)关键字文章。

### [Conversion operators](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/conversion-operators)

C# 允许程序员在类或结构上声明转换，以便类或结构能够与其他类或结构或者基本类型进行相互转换。 以类似于运算符的方式定义转换，并根据它们所转换为的类型命名。 要转换的参数类型或转换结果的类型必须是包含类型（但不能两者同时都是）。

```c#
class SampleClass
{
    public static explicit operator SampleClass(int i)
    {
        SampleClass temp = new SampleClass();
        // code to convert from int to SampleClass...

        return temp;
    }
}
```

#### 转换运算符概述

转换运算符具有以下属性：

- 声明为 `implicit` 的转换在需要时自动执行。
- 声明为 `explicit` 的转换需要调用强制转换。
- 所有转换都必须都声明为 `static`。

#### [Using Conversion Operators](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/using-conversion-operators)

您可以使用 `implicit` 转换运算符或者 `explicit` 转换运算符，前者更易于使用，后者能向阅读代码的每个人清楚地指示您要转换类型。 本主题演示转换运算符的两个类型。

> 若要了解简单类型转换，请参阅[操作说明：将字符串转换为数字](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/types/how-to-convert-a-string-to-a-number)、[操作说明：将字节数组转换为 int](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/types/how-to-convert-a-byte-array-to-an-int)、[操作说明：在十六进制字符串与数值类型之间转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/types/how-to-convert-between-hexadecimal-strings-and-numeric-types)或 [Convert](https://docs.microsoft.com/zh-cn/dotnet/api/system.convert)。

##### 示例1

这是显式转换运算符的示例。 此运算符从类型 [Byte](https://docs.microsoft.com/zh-cn/dotnet/api/system.byte) 转换为名为 `Digit` 的值类型。 由于不是所有字节都可转换为数字，因此该转换是显式的，意味着必须使用转换，如 `Main` 方法所示。

```c#
struct Digit
{
    byte value;

    public Digit(byte value)  //constructor
    {
        if (value > 9)
        {
            throw new System.ArgumentException();
        }
        this.value = value;
    }

    public static explicit operator Digit(byte b)  // explicit byte to digit conversion operator
    {
        Digit d = new Digit(b);  // explicit conversion

        System.Console.WriteLine("Conversion occurred.");
        return d;
    }
}

class TestExplicitConversion
{
    static void Main()
    {
        try
        {
            byte b = 3;
            Digit d = (Digit)b;  // explicit conversion
        }
        catch (System.Exception e)
        {
            System.Console.WriteLine("{0} Exception caught.", e);
        }
    }
}
// Output: Conversion occurred.
```

##### 示例2

此示例通过定义撤消前一示例所执行操作的转换运算符来演示隐式转换运算符：它将名为 `Digit` 的值类转换为整型 [Byte](https://docs.microsoft.com/zh-cn/dotnet/api/system.byte) 类型。 由于任何数字都可转换为 [Byte](https://docs.microsoft.com/zh-cn/dotnet/api/system.byte)，因此没必要非得让用户知道进行的转换。

```c#
struct Digit
{
    byte value;

    public Digit(byte value)  //constructor
    {
        if (value > 9)
        {
            throw new System.ArgumentException();
        }
        this.value = value;
    }

    public static implicit operator byte(Digit d)  // implicit digit to byte conversion operator
    {
        System.Console.WriteLine("conversion occurred");
        return d.value;  // implicit conversion
    }
}

class TestImplicitConversion
{
    static void Main()
    {
        Digit d = new Digit(3);
        byte b = d;  // implicit conversion -- no cast needed
    }
}
// Output: Conversion occurred.
```

#### [How to: Implement User-Defined Conversions Between Structs](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/how-to-implement-user-defined-conversions-between-structs)

本示例定义 `RomanNumeral` 和 `BinaryNumeral` 两个结构，并演示二者之间的转换。

```c#
struct RomanNumeral
{
    private int value;

    public RomanNumeral(int value)  //constructor
    {
        this.value = value;
    }

    static public implicit operator RomanNumeral(int value)
    {
        return new RomanNumeral(value);
    }

    static public implicit operator RomanNumeral(BinaryNumeral binary)
    {
        return new RomanNumeral((int)binary);
    }

    static public explicit operator int(RomanNumeral roman)
    {
        return roman.value;
    }

    static public implicit operator string(RomanNumeral roman)
    {
        return ("Conversion to string is not implemented");
    }
}

struct BinaryNumeral
{
    private int value;

    public BinaryNumeral(int value)  //constructor
    {
        this.value = value;
    }

    static public implicit operator BinaryNumeral(int value)
    {
        return new BinaryNumeral(value);
    }

    static public explicit operator int(BinaryNumeral binary)
    {
        return (binary.value);
    }

    static public implicit operator string(BinaryNumeral binary)
    {
        return ("Conversion to string is not implemented");
    }
}

class TestConversions
{
    static void Main()
    {
        RomanNumeral roman;
        BinaryNumeral binary;

        roman = 10;

        // Perform a conversion from a RomanNumeral to a BinaryNumeral:
        binary = (BinaryNumeral)(int)roman;

        // Perform a conversion from a BinaryNumeral to a RomanNumeral:
        // No cast is required:
        roman = binary;

        System.Console.WriteLine((int)binary);
        System.Console.WriteLine(binary);

        // Keep the console window open in debug mode.
        System.Console.WriteLine("Press any key to exit.");
        System.Console.ReadKey();
    }
}
/* Output:
    10
    Conversion to string is not implemented
*/
```

##### 可靠编程

在上述示例中，语句：

```c#
binary = (BinaryNumeral)(int)roman;
```

执行从 `RomanNumeral` 到 `BinaryNumeral` 的转换。 因为没有从 `RomanNumeral` 到 `BinaryNumeral` 的直接转换，所以使用强制转换将 `RomanNumeral` 转换为 `int`，并使用另一个强制转换将 `int` 转换为 `BinaryNumeral`。

另外，语句

```c#
roman = binary;
```

执行从 `BinaryNumeral` 到 `RomanNumeral` 的转换。 由于 `RomanNumeral` 定义了从 `BinaryNumeral` 的隐式转换，所以不需要强制转换。

### [default value expressions](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/default-value-expressions)

默认值表达式 `default(T)` 生成 `T` 类型的默认值。 下表显示为各种类型生成的值：

| 类型                                                         | 默认值                                                       |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| 任何引用类型                                                 | `null`                                                       |
| 数值类型                                                     | 零                                                           |
| [bool](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/bool) | `false`                                                      |
| [char](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/char) | `'\0'`                                                       |
| [enum](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/enum) | 表达式 `(E)0` 生成的值，其中 `E` 是枚举标识符。              |
| [struct](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/struct) | 通过如下设置生成的值：将所有值类型的字段设置为其默认值，将所有引用类型的字段设置为 `null`。 |
| 可以为 null 的类型                                           | [HasValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullable-1.hasvalue) 属性为 `false` 且 [Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullable-1.value) 属性未定义的实例。 |

默认值表达式在泛型类和泛型方法中非常有用。 使用泛型类和泛型方法时出现的一个问题是，如何在无法提前知道以下内容的情况下将默认值赋值给参数化类型 `T`：

- `T` 是引用类型还是值类型。
- 如果 `T` 是值类型，它是数值还是结构。

已知参数化类型 `T` 的变量 `t`，仅当 `T` 为引用类型时，语句 `t = null` 才有效。 赋值 `t = 0` 仅对数值类型有效，对结构无效。 若要解决此问题，请使用默认值表达式：

### Equality Comparisons

有时需要比较两个值是否相等。 
- 在某些情况下，测试的是“值相等性”，也称为“等效性”，这意味着两个变量包含的值相等。 
- 在其他情况下，必须确定两个变量是否引用内存中的同一基础对象。 
  - 此类型的相等性称为“引用相等性”或“标识”。 

本主题介绍这两种相等性，并提供指向其他主题的链接，供用户了解详细信息。

#### 引用相等性

引用相等性指两个对象引用均引用同一基础对象。 

这可以通过简单的赋值来实现，如下面的示例所示。

```c#
using System;
class Test
{
    public int Num { get; set; }
    public string Str { get; set; }

    static void Main()
    {
        Test a = new Test() { Num = 1, Str = "Hi" };
        Test b = new Test() { Num = 1, Str = "Hi" };

        bool areEqual = System.Object.ReferenceEquals(a, b);
        // False:
        System.Console.WriteLine("ReferenceEquals(a, b) = {0}", areEqual);

        // Assign b to a.
        b = a;

        // Repeat calls with different results.
        areEqual = System.Object.ReferenceEquals(a, b);
        // True:
        System.Console.WriteLine("ReferenceEquals(a, b) = {0}", areEqual);

        // Keep the console open in debug mode.
        Console.WriteLine("Press any key to exit.");
        Console.ReadKey();
    }
}
```

在此代码中，创建了两个对象，但在赋值语句后，这两个引用所引用的是同一对象。 因此，它们具有引用相等性。 使用 [ReferenceEquals](https://docs.microsoft.com/zh-cn/dotnet/api/system.object.referenceequals) 方法确定两个引用是否引用同一对象。

引用相等性的概念仅适用于引用类型。 由于在将值类型的实例赋给变量时将产生值的副本，因此值类型对象无法具有引用相等性。 因此，永远不会有两个未装箱结构引用内存中的同一位置。 此外，如果使用 [ReferenceEquals](https://docs.microsoft.com/zh-cn/dotnet/api/system.object.referenceequals)比较两个值类型，结果将始终为 `false`，即使对象中包含的值都相同也是如此。 这是因为会将每个变量装箱到单独的对象实例中。 有关详细信息，请参阅[如何：测试引用相等性（标识）](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/how-to-test-for-reference-equality-identity)。

#### 值相等性

值相等性指两个对象包含相同的一个或多个值。 对于基元值类型（例如 [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int) 或 [bool](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/bool)），针对值相等性的测试简单明了。 可以使用 [==](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/equality-comparison-operator) 运算符，如下面的示例所示。

```c#
int a = GetOriginalValue();  
int b = GetCurrentValue();  
  
// Test for value equality.   
if( b == a)   
{  
    // The two integers are equal.  
}  
```

对于大多数其他类型，针对值相等性的测试较为复杂，因为它需要用户了解类型对值相等性的定义方式。 对于具有多个字段或属性的类和结构，值相等性的定义通常指所有字段或属性都具有相同的值。 例如，如果 pointA.X 等于 pointB.X，并且 pointA.Y 等于 pointB.Y，则可以将两个 `Point` 对象定义为相等。

但是，并不要求类型中的所有字段均相等。 只需子集相等即可。 比较不具所有权的类型时，应确保明确了解相等性对于该类型是如何定义的。 若要详细了解如何在自己的类和结构中定义值相等性，请参阅[操作说明：为类型定义值相等性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/how-to-define-value-equality-for-a-type)。

##### 浮点值的值相等性

由于二进制计算机上的浮点算法不精确，因此浮点值（[double](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/double) 和 [float](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/float)）的相等比较会出现问题。 有关更多信息，请参阅 [System.Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double) 主题中的备注部分。

#### [How to: Define Value Equality for a Type](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/how-to-define-value-equality-for-a-type)

定义类或结构时，需确定为类型创建值相等性（或等效性）的自定义定义是否有意义。 通常，类型的对象预期要添加到某类集合时，或者这些对象主要用于存储一组字段或属性时，需实现值相等性。 可以基于类型中所有字段和属性的比较结果来定义值相等性，也可以基于子集进行定义。 但在任何一种情况下，类和结构中的实现均应遵循 5 个等效性保证条件：

1. `x.Equals(x)` 返回 `true`。 这称为自反属性。
2. `x.Equals(y)` 返回与 `y.Equals(x)` 相同的值。 这称为对称属性。
3. 如果 `(x.Equals(y) && y.Equals(z))` 返回 `true`，则 `x.Equals(z)` 返回 `true`。 这称为可传递属性。
4. 只要未修改 x 和 y 引用的对象，`x.Equals(y)` 的连续调用将返回相同的值。
5. `x.Equals(null)` 返回 `false`。 但是，`null.Equals(null)` 会引发异常；它未遵循上面的第二条规则。

定义的任何结构都已具有其从 [Object.Equals(Object)](https://docs.microsoft.com/zh-cn/dotnet/api/system.object.equals#System_Object_Equals_System_Object_) 方法的 [System.ValueType](https://docs.microsoft.com/zh-cn/dotnet/api/system.valuetype) 替代中继承的值相等性的默认实现。 此实现使用反射来检查类型中的所有字段和属性。 尽管此实现可生成正确的结果，但与专门为类型编写的自定义实现相比，它的速度相对较慢。

类和结构的值相等性的实现详细信息有所不同。 但是，类和结构都需要相同的基础步骤来实现相等性：

1. 替代[虚拟](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/virtual) [Object.Equals(Object)](https://docs.microsoft.com/zh-cn/dotnet/api/system.object.equals#System_Object_Equals_System_Object_) 方法。 大多数情况下，`bool Equals( object obj )` 实现应只调入作为 [System.IEquatable](https://docs.microsoft.com/zh-cn/dotnet/api/system.iequatable-1) 接口的实现的类型特定 `Equals` 方法。 （请参阅步骤 2。）
2. 通过提供类型特定的 `Equals` 方法实现 [System.IEquatable](https://docs.microsoft.com/zh-cn/dotnet/api/system.iequatable-1) 接口。 实际的等效性比较将在此接口中执行。 例如，可能决定通过仅比较类型中的一两个字段来定义相等性。 不会从 `Equals` 引发异常。 仅对于类：此方法应仅检查类中声明的字段。 它应调用 `base.Equals` 来检查基类中的字段。 （如果类型直接从 [Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object) 中继承，则不要这样做，因为 [Object.Equals(Object)](https://docs.microsoft.com/zh-cn/dotnet/api/system.object.equals#System_Object_Equals_System_Object_) 的 [Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object) 实现会执行引用相等性检查。）
3. 可选但建议这样做：重载 [==](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/equality-comparison-operator) 和 [!=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/not-equal-operator) 运算符。
4. 替代 [Object.GetHashCode](https://docs.microsoft.com/zh-cn/dotnet/api/system.object.gethashcode)，以便具有值相等性的两个对象生成相同的哈希代码。
5. 可选：若要支持“大于”或“小于”定义，请为类型实现 [IComparable](https://docs.microsoft.com/zh-cn/dotnet/api/system.icomparable-1) 接口，并同时重载 [<=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/less-than-equal-operator) 和 [>=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/greater-than-equal-operator) 运算符。

下面的第 1 个示例演示了类实现。 第 2 个示例演示了结构实现。

##### 示例 1

下面的示例演示如何在类（引用类型）中实现值相等性。

```c#
namespace ValueEquality
{
    using System;
    class TwoDPoint : IEquatable<TwoDPoint>
    {
        // Readonly auto-implemented properties.
        public int X { get; private set; }
        public int Y { get; private set; }

        // Set the properties in the constructor.
        public TwoDPoint(int x, int y)
        {
            if ((x < 1) || (x > 2000) || (y < 1) || (y > 2000))
            {
                throw new System.ArgumentException("Point must be in range 1 - 2000");
            }
            this.X = x;
            this.Y = y;
        }

        public override bool Equals(object obj)
        {
            return this.Equals(obj as TwoDPoint);
        }

        public bool Equals(TwoDPoint p)
        {
            // If parameter is null, return false.
            if (Object.ReferenceEquals(p, null))
            {
                return false;
            }

            // Optimization for a common success case.
            if (Object.ReferenceEquals(this, p))
            {
                return true;
            }

            // If run-time types are not exactly the same, return false.
            if (this.GetType() != p.GetType())
            {
                return false;
            }

            // Return true if the fields match.
            // Note that the base class is not invoked because it is
            // System.Object, which defines Equals as reference equality.
            return (X == p.X) && (Y == p.Y);
        }

        public override int GetHashCode()
        {
            return X * 0x00010000 + Y;
        }

        public static bool operator ==(TwoDPoint lhs, TwoDPoint rhs)
        {
            // Check for null on left side.
            if (Object.ReferenceEquals(lhs, null))
            {
                if (Object.ReferenceEquals(rhs, null))
                {
                    // null == null = true.
                    return true;
                }

                // Only the left side is null.
                return false;
            }
            // Equals handles case of null on right side.
            return lhs.Equals(rhs);
        }

        public static bool operator !=(TwoDPoint lhs, TwoDPoint rhs)
        {
            return !(lhs == rhs);
        }
    }

    // For the sake of simplicity, assume a ThreeDPoint IS a TwoDPoint.
    class ThreeDPoint : TwoDPoint, IEquatable<ThreeDPoint>
    {
        public int Z { get; private set; }

        public ThreeDPoint(int x, int y, int z)
            : base(x, y)
        {
            if ((z < 1) || (z > 2000))
            {
                throw new System.ArgumentException("Point must be in range 1 - 2000");
            }    
            this.Z = z;
        }

        public override bool Equals(object obj)
        {
            return this.Equals(obj as ThreeDPoint);
        }

        public bool Equals(ThreeDPoint p)
        {
            // If parameter is null, return false.
            if (Object.ReferenceEquals(p, null))
            {
                return false;
            }

            // Optimization for a common success case.
            if (Object.ReferenceEquals(this, p))
            {
                return true;
            }

            // Check properties that this class declares.
            if (Z == p.Z)
            {
                // Let base class check its own fields 
                // and do the run-time type comparison.
                return base.Equals((TwoDPoint)p);
            }
            else
            {
                return false;
            }    
        }

        public override int GetHashCode()
        {
            return (X * 0x100000) + (Y * 0x1000) + Z;
        }

        public static bool operator ==(ThreeDPoint lhs, ThreeDPoint rhs)
        {
            // Check for null.
            if (Object.ReferenceEquals(lhs, null))
            {
                if (Object.ReferenceEquals(rhs, null))
                {
                    // null == null = true.
                    return true;
                }

                // Only the left side is null.
                return false;
            }
            // Equals handles the case of null on right side.
            return lhs.Equals(rhs);
        }

        public static bool operator !=(ThreeDPoint lhs, ThreeDPoint rhs)
        {
            return !(lhs == rhs);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            ThreeDPoint pointA = new ThreeDPoint(3, 4, 5);
            ThreeDPoint pointB = new ThreeDPoint(3, 4, 5);
            ThreeDPoint pointC = null;
            int i = 5;

            Console.WriteLine("pointA.Equals(pointB) = {0}", pointA.Equals(pointB));
            Console.WriteLine("pointA == pointB = {0}", pointA == pointB);
            Console.WriteLine("null comparison = {0}", pointA.Equals(pointC));
            Console.WriteLine("Compare to some other type = {0}", pointA.Equals(i));

            TwoDPoint pointD = null;
            TwoDPoint pointE = null;



            Console.WriteLine("Two null TwoDPoints are equal: {0}", pointD == pointE);

            pointE = new TwoDPoint(3, 4);
            Console.WriteLine("(pointE == pointA) = {0}", pointE == pointA);
            Console.WriteLine("(pointA == pointE) = {0}", pointA == pointE);
            Console.WriteLine("(pointA != pointE) = {0}", pointA != pointE);

            System.Collections.ArrayList list = new System.Collections.ArrayList();
            list.Add(new ThreeDPoint(3, 4, 5));
            Console.WriteLine("pointE.Equals(list[0]): {0}", pointE.Equals(list[0]));

            // Keep the console window open in debug mode.
            System.Console.WriteLine("Press any key to exit.");
            System.Console.ReadKey();
        }
    }

    /* Output:
        pointA.Equals(pointB) = True
        pointA == pointB = True
        null comparison = False
        Compare to some other type = False
        Two null TwoDPoints are equal: True
        (pointE == pointA) = False
        (pointA == pointE) = False
        (pointA != pointE) = True
        pointE.Equals(list[0]): False
    */
}
```

在类（引用类型）上，两种 [Object.Equals(Object)](https://docs.microsoft.com/zh-cn/dotnet/api/system.object.equals#System_Object_Equals_System_Object_) 方法的默认实现均执行引用相等性比较，而不是值相等性检查。 实施者替代虚方法时，目的是为其指定值相等性语义。

即使类不重载 `==` 和 `!=` 运算符，也可将这些运算符与类一起使用。 但是，默认行为是执行引用相等性检查。在类中，如果重载 `Equals` 方法，则应重载 `==` 和 `!=` 运算符，但这并不是必需的。

##### 示例2

下面的示例演示如何在结构（值类型）中实现值相等性：

```c#
struct TwoDPoint : IEquatable<TwoDPoint>
    {
        // Read/write auto-implemented properties.
        public int X { get; private set; }
        public int Y { get; private set; }

        public TwoDPoint(int x, int y)
            : this()
        {
            X = x;
            Y = x;
        }

        public override bool Equals(object obj)
        {
            if (obj is TwoDPoint)
            {
                return this.Equals((TwoDPoint)obj);
            }
            return false;
        }

        public bool Equals(TwoDPoint p)
        {
            return (X == p.X) && (Y == p.Y);
        }

        public override int GetHashCode()
        {
            return X ^ Y;
        }

        public static bool operator ==(TwoDPoint lhs, TwoDPoint rhs)
        {
            return lhs.Equals(rhs);
        }

        public static bool operator !=(TwoDPoint lhs, TwoDPoint rhs)
        {
            return !(lhs.Equals(rhs));
        }
    }


    class Program
    {
        static void Main(string[] args)
        {
            TwoDPoint pointA = new TwoDPoint(3, 4);
            TwoDPoint pointB = new TwoDPoint(3, 4);
            int i = 5;

            // Compare using virtual Equals, static Equals, and == and != operators.
            // True:
            Console.WriteLine("pointA.Equals(pointB) = {0}", pointA.Equals(pointB));
            // True:
            Console.WriteLine("pointA == pointB = {0}", pointA == pointB);
            // True:
            Console.WriteLine("Object.Equals(pointA, pointB) = {0}", Object.Equals(pointA, pointB));
            // False:
            Console.WriteLine("pointA.Equals(null) = {0}", pointA.Equals(null));
            // False:
            Console.WriteLine("(pointA == null) = {0}", pointA == null);
            // True:
            Console.WriteLine("(pointA != null) = {0}", pointA != null);
            // False:
            Console.WriteLine("pointA.Equals(i) = {0}", pointA.Equals(i));
            // CS0019:
            // Console.WriteLine("pointA == i = {0}", pointA == i); 

            // Compare unboxed to boxed.
            System.Collections.ArrayList list = new System.Collections.ArrayList();
            list.Add(new TwoDPoint(3, 4));
            // True:
            Console.WriteLine("pointE.Equals(list[0]): {0}", pointA.Equals(list[0]));


            // Compare nullable to nullable and to non-nullable.
            TwoDPoint? pointC = null;
            TwoDPoint? pointD = null;
            // False:
            Console.WriteLine("pointA == (pointC = null) = {0}", pointA == pointC);
            // True:
            Console.WriteLine("pointC == pointD = {0}", pointC == pointD);

            TwoDPoint temp = new TwoDPoint(3, 4);
            pointC = temp;
            // True:
            Console.WriteLine("pointA == (pointC = 3,4) = {0}", pointA == pointC);

            pointD = temp;
            // True:
            Console.WriteLine("pointD == (pointC = 3,4) = {0}", pointD == pointC);

            // Keep the console window open in debug mode.
            System.Console.WriteLine("Press any key to exit.");
            System.Console.ReadKey();
        }
    }

    /* Output:
        pointA.Equals(pointB) = True
        pointA == pointB = True
        Object.Equals(pointA, pointB) = True
        pointA.Equals(null) = False
        (pointA == null) = False
        (pointA != null) = True
        pointA.Equals(i) = False
        pointE.Equals(list[0]): True
        pointA == (pointC = null) = False
        pointC == pointD = True
        pointA == (pointC = 3,4) = True
        pointD == (pointC = 3,4) = True
    */
}
```

对于结构，[Object.Equals(Object)](https://docs.microsoft.com/zh-cn/dotnet/api/system.object.equals#System_Object_Equals_System_Object_)（[System.ValueType](https://docs.microsoft.com/zh-cn/dotnet/api/system.valuetype) 中的替代版本）的默认实现通过使用反射来比较类型中每个字段的值，从而执行值相等性检查。 实施者替代结构中的 `Equals` 虚方法时，目的是提供更高效的方法来执行值相等性检查，并选择根据结构字段或属性的某个子集来进行比较。

除非结构显式重载了 [==](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/equality-comparison-operator) 和 [!=](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/not-equal-operator) 运算符，否则这些运算符无法对结构进行运算。

#### [How to: Test for Reference Equality (Identity)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/how-to-test-for-reference-equality-identity)

无需实现任何自定义逻辑，即可支持类型中的引用相等性比较。 此功能由静态 [Object.ReferenceEquals](https://docs.microsoft.com/zh-cn/dotnet/api/system.object.referenceequals) 方法向所有类型提供。

以下示例演示如何确定两个变量是否具有引用相等性，即它们引用内存中的同一对象。

该示例还演示 [Object.ReferenceEquals](https://docs.microsoft.com/zh-cn/dotnet/api/system.object.referenceequals) 为何始终为值类型返回 `false`，以及您为何不应使用 [ReferenceEquals](https://docs.microsoft.com/zh-cn/dotnet/api/system.object.referenceequals) 来确定字符串相等性。

##### 示例

```c#
namespace TestReferenceEquality
{
    struct TestStruct
    {
        public int Num { get; private set; }
        public string Name { get; private set; }

        public TestStruct(int i, string s) : this()
        {
            Num = i;
            Name = s;
        }
    }

    class TestClass
    {
        public int Num { get; set; }
        public string Name { get; set; }
    }

    class Program
    {
        static void Main()
        {
            // Demonstrate reference equality with reference types.
            #region ReferenceTypes

            // Create two reference type instances that have identical values.
            TestClass tcA = new TestClass() { Num = 1, Name = "New TestClass" };
            TestClass tcB = new TestClass() { Num = 1, Name = "New TestClass" };

            Console.WriteLine("ReferenceEquals(tcA, tcB) = {0}",
                                Object.ReferenceEquals(tcA, tcB)); // false

            // After assignment, tcB and tcA refer to the same object. 
            // They now have reference equality. 
            tcB = tcA;
            Console.WriteLine("After asignment: ReferenceEquals(tcA, tcB) = {0}",
                                Object.ReferenceEquals(tcA, tcB)); // true

            // Changes made to tcA are reflected in tcB. Therefore, objects
            // that have reference equality also have value equality.
            tcA.Num = 42;
            tcA.Name = "TestClass 42";
            Console.WriteLine("tcB.Name = {0} tcB.Num: {1}", tcB.Name, tcB.Num);
            #endregion

            // Demonstrate that two value type instances never have reference equality.
            #region ValueTypes

            TestStruct tsC = new TestStruct( 1, "TestStruct 1");

            // Value types are copied on assignment. tsD and tsC have 
            // the same values but are not the same object.
            TestStruct tsD = tsC;
            Console.WriteLine("After asignment: ReferenceEquals(tsC, tsD) = {0}",
                                Object.ReferenceEquals(tsC, tsD)); // false
            #endregion

            #region stringRefEquality
            // Constant strings within the same assembly are always interned by the runtime.
            // This means they are stored in the same location in memory. Therefore, 
            // the two strings have reference equality although no assignment takes place.
            string strA = "Hello world!";
            string strB = "Hello world!";
            Console.WriteLine("ReferenceEquals(strA, strB) = {0}",
                             Object.ReferenceEquals(strA, strB)); // true

            // After a new string is assigned to strA, strA and strB
            // are no longer interned and no longer have reference equality.
            strA = "Goodbye world!";
            Console.WriteLine("strA = \"{0}\" strB = \"{1}\"", strA, strB);
            
            Console.WriteLine("After strA changes, ReferenceEquals(strA, strB) = {0}",
                            Object.ReferenceEquals(strA, strB)); // false
            
            // A string that is created at runtime cannot be interned.
            StringBuilder sb = new StringBuilder("Hello world!");
            string stringC = sb.ToString(); 
            // False:
            Console.WriteLine("ReferenceEquals(stringC, strB) = {0}",
                            Object.ReferenceEquals(stringC, strB));

            // The string class overloads the == operator to perform an equality comparison.
            Console.WriteLine("stringC == strB = {0}", stringC == strB); // true

            #endregion

            // Keep the console open in debug mode.
            Console.WriteLine("Press any key to exit.");
            Console.ReadKey();
        }
    }
}

/* Output:
    ReferenceEquals(tcA, tcB) = False
    After asignment: ReferenceEquals(tcA, tcB) = True
    tcB.Name = TestClass 42 tcB.Num: 42
    After asignment: ReferenceEquals(tsC, tsD) = False
    ReferenceEquals(strA, strB) = True
    strA = "Goodbye world!" strB = "Hello world!"
    After strA changes, ReferenceEquals(strA, strB) = False
*/
```

在 [System.Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object) 通用基类中实现 `Equals` 也会执行引用相等性检查，但最好不要使用这种检查，因为如果恰好某个类替代了此方法，结果可能会出乎意料。 以上情况同样适用于 `==` 和 `!=` 运算符。 当它们作用于引用类型时，`==` 和 `!=` 的默认行为是执行引用相等性检查。 但是，派生类可重载运算符，执行值相等性检查。 为了尽量降低错误的可能性，当需要确定两个对象是否具有引用相等性时，最好始终使用 [ReferenceEquals](https://docs.microsoft.com/zh-cn/dotnet/api/system.object.referenceequals)。

运行时始终暂存同一程序集内的常量字符串。 也就是说，仅维护每个唯一文本字符串的一个实例。 但是，运行时不能保证会暂存在运行时创建的字符串，也不保证会暂存不同程序集中两个相等的常量字符串。