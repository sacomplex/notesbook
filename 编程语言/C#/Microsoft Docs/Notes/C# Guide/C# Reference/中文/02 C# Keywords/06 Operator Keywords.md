# [Operator Keywords](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/operator-keywords)

用于执行其他操作，例如创建对象、检查对象的运行时类型、获取类型的大小等等。 本部分介绍以下关键字：

- [as](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/as) 将对象转换为兼容类型。
- [await](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/await) 暂停 [async](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/async) 方法，直到等待的任务已完成。
- [is](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/is) 检查对象的运行时类型，或（自 C# 7.0 起）根据模式测试表达式。
- [new](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/new)
  - [new 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/new-operator) 创建对象。
  - [new 修饰符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/new-modifier) 隐藏继承的成员。
  - [new 约束](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/new-constraint) 限定类型参数。
- [nameof](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/nameof) 获取变量、类型或成员的简单（非限定）字符串名称。
- [sizeof](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/sizeof) 获取非托管类型的大小。
- [typeof](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/typeof) 获取类型的 [System.Type](https://docs.microsoft.com/zh-cn/dotnet/api/system.type) 对象。
- [true](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/true)
  - [true 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/true-false-operators)返回 [bool](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/bool) 值 `true` 以指示操作数一定为 true。
  - [true 字面常数](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/true-literal)表示 [bool](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/bool) 值 `true`。
- [false](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/false)
  - [false 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/true-false-operators)返回 [bool](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/bool) 值 `true`，以指明操作数一定为 false。
  - [false 文本](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/false-literal)表示 [bool](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/bool) 值 `false`。
- [stackalloc](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/stackalloc) 在堆栈上分配内存块。

以下关键字可以用作运算符和语句，详见[语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/statement-keywords)部分：

- [checked](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/checked) 指定已检查的上下文。
- [unchecked](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/unchecked) 指定未检查的上下文。

## [as](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/as)

可以使用 `as` 运算符在符合的引用类型或[可以为 null 的类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/nullable-types/index)之间执行某些类型的转换。 以下代码显示一个示例。

C#复制

```csharp
class csrefKeywordsOperators
{
    class Base
    {
        public override string  ToString()
        {
             return "Base";
        }
    }
    class Derived : Base 
    { }

    class Program
    {
        static void Main()
        {

            Derived d = new Derived();

            Base b = d as Base;
            if (b != null)
            {
                Console.WriteLine(b.ToString());
            }

        }
    }
}
```

如示例所示，需要比较 `as` 表达式和 `null` 的结果以检查转换是否成功。 从 C# 7.0 开始，可以使用 [is](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/is) 表达式来测试转换是否成功，并在转换成功时有条件地分配变量。 在许多情况下，它比使用 `as` 运算符更简洁。 有关详细信息，请参阅 [`is` 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/is)一文中的[类型模式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/is#type)部分。

### 备注

`as` 运算符类似于转换运算。 但是，如果无法进行转换，则 `as` 会返回 `null`，而不是引发异常。 请看下面的示例：

```csharp
expression as type  
```

该代码等效于以下表达式，但 `expression` 变量仅进行一次计算。

```csharp
expression is type ? (type)expression : (type)null  
```

请注意，`as` 运算符仅执行引用转换、可以为 null 的转换和装箱转换。 `as` 运算符无法执行其他转换，例如用户定义的转换，应使用转换表达式执行此转换。

### 示例

```csharp
class ClassA { }
class ClassB { }

class MainClass
{
    static void Main()
    {
        object[] objArray = new object[6];
        objArray[0] = new ClassA();
        objArray[1] = new ClassB();
        objArray[2] = "hello";
        objArray[3] = 123;
        objArray[4] = 123.4;
        objArray[5] = null;

        for (int i = 0; i < objArray.Length; ++i)
        {
            string s = objArray[i] as string;
            Console.Write("{0}:", i);
            if (s != null)
            {
                Console.WriteLine("'" + s + "'");
            }
            else
            {
                Console.WriteLine("not a string");
            }
        }
    }
}
/*
Output:
0:not a string
1:not a string
2:'hello'
3:not a string
4:not a string
5:not a string
*/
```

## [await](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/await)

`await` 运算符应用于异步方法中的任务，在方法的执行中插入挂起点，直到所等待的任务完成。 任务表示正在进行的工作。

`await` 仅可用于由 [async](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/async) 关键字修改的异步方法中。 使用 `async` 修饰符定义并且通常包含一个或多个 `await`表达式的这类方法称为异步方法。

 备注

`async` 和 `await` 关键字是在 C# 5 中引入的。 有关异步编程的说明，请参阅[使用 Async 和 Await 的异步编程](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/index)。

应用 `await` 运算符的任务通常由实现[基于任务的异步模式](https://docs.microsoft.com/zh-cn/dotnet/standard/asynchronous-programming-patterns/task-based-asynchronous-pattern-tap)的方法调用返回。 包括返回 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task)、[Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1) 和 `System.Threading.Tasks.ValueType<TResult>` 对象的方法。

如下示例中，[HttpClient.GetByteArrayAsync](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.http.httpclient.getbytearrayasync) 方法返回 `Task<byte[]>`。 当任务完成时，任务约定生成实际字节数组。 `await` 运算符挂起执行，直到 [GetByteArrayAsync](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.http.httpclient.getbytearrayasync) 方法完成其操作。 同时，控制权会返回给 `GetPageSizeAsync` 的调用方。 任务结束执行时，`await` 表达式的计算结果为字节数组。

C#复制

```csharp
using System;
using System.Net.Http;
using System.Threading;
using System.Threading.Tasks;

public class Example
{
   public static void Main()
   {
      string[] args = Environment.GetCommandLineArgs();
      if (args.Length > 1)
         GetPageSizeAsync(args[1]).Wait();
      else
         Console.WriteLine("Enter at least one URL on the command line.");
   }

   private static async Task GetPageSizeAsync(string url)  
   {  
       var client = new HttpClient();  
       var uri = new Uri(Uri.EscapeUriString(url));
       byte[] urlContents = await client.GetByteArrayAsync(uri);
       Console.WriteLine($"{url}: {urlContents.Length/2:N0} characters");  
   }  
}
// The following call from the command line:
//    await1 http://docs.microsoft.com
// displays output like the following: 
//   http://docs.microsoft.com: 7,967 characters
```

 重要

有关完整示例，请参阅[演练：使用 Async 和 Await 访问 Web](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/walkthrough-accessing-the-web-by-using-async-and-await)。 可以从 Microsoft 网站的[开发者代码示例](https://code.msdn.microsoft.com/Async-Sample-Accessing-the-9c10497f)中下载示例。 该示例处于 AsyncWalkthrough_HttpClient 项目中。

如前一示例所示，如果 `await` 应用于返回 `Task<TResult>` 的方法调用的结果，则 `await` 表达式的类型为 `TResult`。 如果 `await` 应用于返回 `Task` 的方法调用的结果，则 `await` 表达式的类型为 `void`。 以下示例演示了差异。

C#复制

```csharp
// await keyword used with a method that returns a Task<TResult>.  
TResult result = await AsyncMethodThatReturnsTaskTResult();  
  
// await keyword used with a method that returns a Task.  
await AsyncMethodThatReturnsTask();  

// await keyword used with a method that returns a ValueTask<TResult>.
TResult result = await AsyncMethodThatReturnsValueTaskTResult();
```

`await` 表达式不阻止正在执行它的线程。 而是使编译器将剩下的异步方法注册为等待任务的延续任务。 控制权随后会返回给异步方法的调用方。 任务完成时，它会调用其延续任务，异步方法的执行会在暂停的位置处恢复。

`await` 表达式只能在由 `async` 修饰符标记的封闭方法体、lambda 表达式或异步方法中出现。 术语 await 在该上下文中仅用作关键字。 在其他位置，它会解释为标识符。 在方法、Lambda 表达式或匿名方法中，`await` 表达式不能在同步函数体、查询表达式、[lock 语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/lock-statement)块或[不安全](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/unsafe)上下文中出现。

### 异常

大多数异步方法返回 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task) 或 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1)。 返回任务的属性携带有关其状态和历史记录的信息，如任务是否完成、异步方法是否导致异常或已取消以及最终结果是什么。 `await` 运算符通过在由 `GetAwaiter` 方法返回的对象上调用方法来访问那些属性。

如果等待的返回任务的异步方法会导致异常，则 `await` 运算符重新引发异常。

如果等待的任务返回异步方法取消，则 `await` 运算符会重新引发 [OperationCanceledException](https://docs.microsoft.com/zh-cn/dotnet/api/system.operationcanceledexception)。

处于故障状态的单个任务可以反映多个异常。 例如，任务可能是对 [Task.WhenAll](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task.whenall) 调用的结果。 等待此类任务时，等待操作仅重新引发异常之一。 但是，无法预测重新引发的异常。

有关异步方法中的错误处理的示例，请参阅 [try catch](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/try-catch)。

### 示例

下面的示例返回页面（页面 URL 作为命令行参数传递给页面）中的字符总数。 此示例调用 `GetPageLengthsAsync`方法，此方法标记有 `async` 关键字。 而 `GetPageLengthsAsync` 方法使用 `await` 关键字等待对[HttpClient.GetStringAsync](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.http.httpclient.getstringasync) 方法的调用。

```csharp
using System;
using System.Linq;
using System.Net.Http;
using System.Threading;
using System.Threading.Tasks;

class Example
{
   static async Task Main()
   {
      string[] args = Environment.GetCommandLineArgs();
      if (args.Length < 2)
         throw new ArgumentNullException("No URIs specified on the command line.");

      // Don't pass the executable file name
      var uris = args.Skip(1).ToArray();

      long characters = await GetPageLengthsAsync(uris);
      Console.WriteLine($"{uris.Length} pages, {characters:N0} characters");
   }

   private static async Task<long> GetPageLengthsAsync(string[] uris)
   {
      var client = new HttpClient();
      long pageLengths = 0;

      foreach (var uri in uris)
      {
         var escapedUri = new Uri(Uri.EscapeUriString(uri));
         string pageContents = await client.GetStringAsync(escapedUri);
         Interlocked.Add(ref pageLengths, pageContents.Length);
      }
      
      return pageLengths;
   }
}
```

前面的示例使用 C# 7.1，它支持 [`async` `Main` 方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/main-and-command-args/index)。 因为早期的 C# 版本不支持返回 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task) 或 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1) 的应用程序入口点，无法将 `async` 修饰符应用于 `Main` 方法并等待 `GetPageLengthsAsync` 方法调用。 在这种情况下，可通过检索 [Task.Result](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1.result#System_Threading_Tasks_Task_1_Result) 属性的值来确保 `Main` 方法等待异步操作完成。 对于不返回值的任务，可调用 [Task.Wait](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task.wait) 方法。 有关如何选择语言版本的信息，请参阅[选择 C# 语言版本](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/configure-language-version)。

## [is](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/is)

检查对象是否与给定类型兼容，或（从 C# 7.0 开始）针对某个模式测试表达式。

### 类型兼容性测试

`is` 关键字在运行时评估类型兼容性。 它确定对象实例或表达式结果是否可转换为指定类型。 语法如下：

C#复制

```csharp
   expr is type
```

其中 *expr* 是计算结果为某个类型的实例的表达式，而 *type* 是 *expr* 结果要转换到的类型的名称。 如果 *expr* 非空，并且通过计算表达式得出的对象可转换为 *type*，则 `is` 语句为 `true`；否则返回 `false`。

例如，以下代码确定 `obj` 是否可转换为 `Person` 类型的实例：

C#复制

```csharp
if (obj is Person) {
   // Do something if obj is a Person.
}
```

如果满足以下条件，则 `is` 语句为 true：

- *expr* 是与 *type* 具有相同类型的一个实例。
- *expr* 是派生自 *type* 的类型的一个实例。 换言之，*expr* 结果可以向上转换为 *type* 的一个实例。
- *expr* 具有属于 *type* 的一个基类的编译时类型，*expr* 还具有属于 *type* 或派生自 *type* 的运行时类型。 变量的编译时类型是其声明中定义的变量类型。 变量的运行时类型是分配给该变量的实例类型。
- *expr* 是实现 *type* 接口的类型的一个实例。

下例表明，对于所有这些转换，`is` 表达式的计算结果都为 `true`。

C#复制

```csharp
using System;

public class Class1 : IFormatProvider
{
   public object GetFormat(Type t)
   {
      if (t.Equals(this.GetType()))      
         return this;
      return null;
   }
}

public class Class2 : Class1
{
   public int Value { get; set; }
}

public class Example
{
   public static void Main()
   {
      var cl1 = new Class1();
      Console.WriteLine(cl1 is IFormatProvider);
      Console.WriteLine(cl1 is Object);
      Console.WriteLine(cl1 is Class1);
      Console.WriteLine(cl1 is Class2); 
      Console.WriteLine();
 
      var cl2 = new Class2();
      Console.WriteLine(cl2 is IFormatProvider);
      Console.WriteLine(cl2 is Class2);
      Console.WriteLine(cl2 is Class1);
      Console.WriteLine();
      
      Class1 cl = cl2;
      Console.WriteLine(cl is Class1);
      Console.WriteLine(cl is Class2);
   }
}
// The example displays the following output:
//     True
//     True
//     True
//     False
//     
//     True
//     True
//     True
//     
//     True
//     True
```

如果已知表达式始终为 `true` 或 `false`，则 `is` 关键字会生成编译时警告。 它只考虑引用转换、装箱转换和取消装箱转换；不考虑用户定义的转换或由类型的[隐式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/implicit)和[显式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/explicit)运算符定义的转换。 下例生成警告，因为转换结果在编译时就已知。 请注意，`is` 表达式从 `int` 到 `long` 和 `double` 的转换会返回 false，因为这些转换由[隐式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/implicit)运算符处理。

C#复制

```csharp
Console.WriteLine(3 is int);
Console.WriteLine();

int value = 6;
Console.WriteLine(value is long);
Console.WriteLine(value is double);
Console.WriteLine(value is object);
Console.WriteLine(value is ValueType);
Console.WriteLine(value is int);
// Compilation generates the following compiler warnings:
//   is2.cs(8,25): warning CS0183: The given expression is always of the provided ('int') type
//   is2.cs(12,25): warning CS0184: The given expression is never of the provided ('long') type
//   is2.cs(13,25): warning CS0184: The given expression is never of the provided ('double') type
//   is2.cs(14,25): warning CS0183: The given expression is always of the provided ('object') type
//   is2.cs(15,25): warning CS0183: The given expression is always of the provided ('ValueType') type
//   is2.cs(16,25): warning CS0183: The given expression is always of the provided ('int') type
```

`expr` 可以是返回值的任何表达式，匿名方法和 Lambda 表达式除外。 下例使用 `is` 来计算方法调用的返回值。

C#复制

```csharp
using System;

public class Example
{
   public static void Main()
   {
      double number1 = 12.63; 
      if (Math.Ceiling(number1) is double)
         Console.WriteLine("The expression returns a double.");
      else if (Math.Ceiling(number1) is decimal)    
         Console.WriteLine("The expression returns a decimal.");

      decimal number2 = 12.63m; 
      if (Math.Ceiling(number2) is double)
         Console.WriteLine("The expression returns a double.");
      else if (Math.Ceiling(number2) is decimal)    
         Console.WriteLine("The expression returns a decimal.");

   }
}
// The example displays the following output:
//     The expression returns a double.
//     The expression returns a decimal.
```

从 C# 7.0 开始，可以使用[类型模式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/is#type)的模式匹配来编写代码，代码使用 `is` 语句更为简洁。

### 利用 `is` 的模式匹配

从 C# 7.0 开始，`is` 和 [switch](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/switch) 语句支持模式匹配。 `is` 关键字支持以下模式：

- [类型模式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/is#type)，用于测试表达式是否可转换为指定类型，如果可以，则将其转换为该类型的一个变量。
- [常量模式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/is#constant)，用于测试表达式计算结果是否为指定的常数值。
- [var 模式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/is#var)，始终成功的匹配，可将表达式的值绑定到新局部变量。

#### 类型模式

使用类型模式执行模式匹配时，`is` 会测试表达式是否可转换为指定类型，如果可以，则将其转换为该类型的一个变量。 它是 `is` 语句的直接扩展，可执行简单的类型计算和转换。 `is` 类型模式的一般形式为：

```csharp
   expr is type varname 
```

其中 *expr* 是计算结果为某个类型的实例的表达式，*type* 是 *expr* 结果要转换到的类型的名称，*varname* 是 *expr* 结果要转换到的对象（如果 `is` 测试为 `true`）。

如果 expr 不为 `null` 且以下任意内容为 true，那么 `is` 表达式为 `true`：

- *expr* 是与 *type* 具有相同类型的一个实例。
- *expr* 是派生自 *type* 的类型的一个实例。 换言之，*expr* 结果可以向上转换为 *type* 的一个实例。
- *expr* 具有属于 *type* 的一个基类的编译时类型，*expr* 还具有属于 *type* 或派生自 *type* 的运行时类型。 变量的编译时类型是其声明中定义的变量类型。 变量的运行时类型是分配给该变量的实例类型。
- *expr* 是实现 *type* 接口的类型的一个实例。

如果 expr 为 `true`，且 `is` 与 `if` 语句一起使用，则会分配 varname，并且其仅在 `if` 语句中具有局部范围。

下列示例使用 `is` 类型模式为类型的 [IComparable.CompareTo(Object)](https://docs.microsoft.com/zh-cn/dotnet/api/system.icomparable.compareto#System_IComparable_CompareTo_System_Object_) 方法提供实现。

C#复制

```csharp
using System;

public class Employee : IComparable
{
    public String Name { get; set; }
    public int Id { get; set; }

    public int CompareTo(Object o)
    {
        if (o is Employee e)
        {
            return Name.CompareTo(e.Name);
        }
        throw new ArgumentException("o is not an Employee object.");
    }
}
```

如果没有模式匹配，则可能按以下方式编写此代码。 使用类型模式匹配无需测试转换结果是否为 `null`，从而生成更紧凑易读的代码。

C#复制

```csharp
using System;

public class Employee : IComparable
{
    public String Name { get; set; }
    public int Id { get; set; }

    public int CompareTo(Object o)
    {
        var e = o as Employee;
        if (e == null)
        {
           throw new ArgumentException("o is not an Employee object.");
        }
        return Name.CompareTo(e.Name);
    }
}
```

确定值类型的类型时，`is` 类型模式也会生成更紧凑的代码。 下例在显示相应属性的值之前使用 `is` 类型模式来确定对象是 `Person` 还是 `Dog` 实例。

C#复制

```csharp
using System;

public class Example
{
   public static void Main()
   {
      Object o = new Person("Jane");
      ShowValue(o);
      
      o = new Dog("Alaskan Malamute");
      ShowValue(o);
   }

   public static void ShowValue(object o)
   {
      if (o is Person p) {
         Console.WriteLine(p.Name);
      }   
      else if (o is Dog d) {
         Console.WriteLine(d.Breed);
      }             
   }
}

public struct Person
{  
   public string Name { get; set; }
   
   public Person(string name) : this()
   {
      Name = name;
   }
}

public struct Dog
{
   public string Breed { get; set; }

   public Dog(string breedName) : this()
   {
      Breed = breedName;
   }
}
// The example displays the following output:
//	Jane
//	Alaskan Malamute
```

对于无模式匹配的等效代码，需要为其单独分配显式转换。

C#复制

```csharp
using System;

public class Example
{
   public static void Main()
   {
      Object o = new Person("Jane");
      ShowValue(o);
      
      o = new Dog("Alaskan Malamute");
      ShowValue(o);
   }

   public static void ShowValue(object o)
   {
      if (o is Person) {
         Person p = (Person) o;
         Console.WriteLine(p.Name);
      }   
      else if (o is Dog) {
         Dog d = (Dog) o;
         Console.WriteLine(d.Breed);
      }             
   }
}

public struct Person
{  
   public string Name { get; set; }
   
   public Person(string name) : this()
   {
      Name = name;
   }
}

public struct Dog
{
   public string Breed { get; set; }

   public Dog(string breedName) : this()
   {
      Breed = breedName;
   }
}
// The example displays the following output:
//       Jane
//       Alaskan Malamute
```

#### 常量模式

使用常量模式执行模式匹配时，`is` 会测试表达式结果是否等于指定常量。 在 C# 6 和更低版本中，[switch](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/switch) 语句支持常量模式。 从 C# 7.0 开始，`is` 语句也支持常量模式。 语法为：

```csharp
   expr is constant
```

其中 *expr* 是要计算的表达式，*constant* 是要测试的值。 *constant* 可以是以下任何常数表达式：

- 一个文本值。
- 已声明 `const` 变量的名称。
- 一个枚举常量。

常数表达式的计算方式如下：

- 如果 *expr* 和 *constant* 均为整型类型，则 C# 相等运算符确定表示式是否返回 `true`（即，是否为 `expr == constant`）。
- 否则，由对静态 [Object.Equals(expr, constant)](https://docs.microsoft.com/zh-cn/dotnet/api/system.object.equals#System_Object_Equals_System_Object_System_Object_) 方法的调用来确定表达式的值。

下例同时使用了类型模式和常量模式来测试对象是否为 `Dice` 实例，如果是，则确定骰子的值是否为 6。

```csharp
using System;

public class Dice
{
    Random rnd = new Random();
    public Dice()
    {

    }
    public int Roll()
    {
        return rnd.Next(1, 7); 
    }
}

class Program
{
    static void Main(string[] args)
    {
        var d1 = new Dice();
        ShowValue(d1);
    }

    private static void ShowValue(object o)
    {
        const int HIGH_ROLL = 6;

        if (o is Dice d && d.Roll() is HIGH_ROLL)
            Console.WriteLine($"The value is {HIGH_ROLL}!");
        else
            Console.WriteLine($"The dice roll is not a {HIGH_ROLL}!");
     }
}
// The example displays output like the following:
//      The value is 6!
```

可以使用常量模式执行 `null` 检查。 `is` 语句支持 `null` 关键字。 语法为：

C#复制

```csharp
   expr is null
```

下面的示例显示 `null` 检查的比较：

C#复制

```csharp
using System;

class Program
{
    static void Main(string[] args)
    {
        object o = null;

        if (o is null)
        {
            Console.WriteLine("o does not have a value");
        }
        else
        {
            Console.WriteLine($"o is {o}");
        }
        
        int? x = 10;

        if (x is null)
        {
            Console.WriteLine("x does not have a value");
        }
        else
        {
            Console.WriteLine($"x is {x.Value}");
        }
        
        // 'null' check comparison
        Console.WriteLine($"'is' constant pattern 'null' check result : { o is null }");
        Console.WriteLine($"object.ReferenceEquals 'null' check result : { object.ReferenceEquals(o, null) }");
        Console.WriteLine($"Equality operator (==) 'null' check result : { o == null }");
    }

    // The example displays the following output:
    // o does not have a value
    // x is 10
    // 'is' constant pattern 'null' check result : True
    // object.ReferenceEquals 'null' check result : True
    // Equality operator (==) 'null' check result : True
}
```

#### var 模式

具有 var 模式的模式匹配始终成功。 语法为

```csharp
   expr is var varname
```

其中，*expr* 的值始终分配给名为 *varname* 的局部变量。 *varname* 是一个与 *expr* 具有相同类型的静态变量。 下例使用 var 模式向名为 `obj` 的变量分配表达式。 然后，显示 `obj` 的值和类型。

```csharp
using System;

class Program
{
    static void Main()
   {
      object[] items = { new Book("The Tempest"), new Person("John") };
      foreach (var item in items) {
        if (item is var obj)
          Console.WriteLine($"Type: {obj.GetType().Name}, Value: {obj}"); 
      }
   }
}

class Book
{
    public Book(string title) 
    {
       Title = title;    
    }

    public string Title { get; set; }

    public override string ToString()
    {
       return Title;
    }
}

class Person
{
   public Person(string name)
   {
      Name = name;
   }

   public string Name 
   { get; set; }

   public override string ToString()
   {
      return Name;
   }
}
// The example displays the following output:
//       Type: Book, Value: The Tempest
//       Type: Person, Value: John
```

请注意，如果 *expr* 为 `null`，则 `is` 表达式仍为 true 并向 *varname* 分配 `null`。

## [new](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/new)

在 C# 中，`new` 关键字可以用作运算符、修饰符或约束。

[new 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/new-operator)
用于创建对象和调用构造函数。

[new 修饰符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/new-modifier)
用于隐藏基类成员的继承成员。

[new 约束](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/new-constraint)
用于限制可能用作泛型声明中类型形式参数的实际参数的类型。

### [new Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/new-operator)

用于创建对象和调用构造函数。 例如:

C#复制

```csharp
Class1 obj  = new Class1();
```

它还用于创建匿名类型的实例：

C#复制

```csharp
var query = from cust in customers
            select new { Name = cust.Name, Address = cust.PrimaryAddress };
```

`new` 运算符还用于调用值类型的默认构造函数。 例如:

C#复制

```csharp
int i = new int();
```

在前面的语句中，`i` 的初始值为 `0`，这是类型 `int` 的默认值。 此语句与下面的语句的效果相同：

C#复制

```csharp
int i = 0;
```

有关默认值的完整列表，请参阅[默认值表](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/default-values-table)。

请记住，为 [struct](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/struct) 声明默认构造函数是错误的，因为每个值类型均隐式含有公共默认构造函数。 可以对结构类型声明参数化构造函数，以设置其初始值，但仅在需要除默认值以外的值时才需要这样做。

值类型对象（如结构）和引用类型对象（如类）都会自动销毁，但值类型对象是在其包含的上下文被销毁时才会销毁，而引用类型对象是在对它们的最后一个引用被删除后的未指定时间由垃圾回收器销毁。 对于包含文件句柄或网络连接等资源的类型，最好使用确定性清理来确保尽快释放其包含的资源。 有关详细信息，请参阅 [Using 语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/using-statement)。

不能重载 `new` 运算符。

如果 `new` 运算符无法分配内存，则引发异常 [OutOfMemoryException](https://docs.microsoft.com/zh-cn/dotnet/api/system.outofmemoryexception)。

#### 示例

在下面的示例中，使用 `new` 运算符创建并初始化 `struct` 对象和类对象，并向它们分配值。 显示默认值和分配的值。

```csharp
struct SampleStruct
{
   public int x;
   public int y;

   public SampleStruct(int x, int y)
   {
      this.x = x;
      this.y = y;
   }
}

class SampleClass
{
   public string name;
   public int id;

   public SampleClass() {}

   public SampleClass(int id, string name)
   {
      this.id = id;
      this.name = name;
   }
}

class ProgramClass
{
   static void Main()
   {
      // Create objects using default constructors:
      SampleStruct Location1 = new SampleStruct();
      SampleClass Employee1 = new SampleClass();

      // Display values:
      Console.WriteLine("Default values:");
      Console.WriteLine("   Struct members: {0}, {1}",
             Location1.x, Location1.y);
      Console.WriteLine("   Class members: {0}, {1}",
             Employee1.name, Employee1.id);

      // Create objects using parameterized constructors:
      SampleStruct Location2 = new SampleStruct(10, 20);
      SampleClass Employee2 = new SampleClass(1234, "Cristina Potra");

      // Display values:
      Console.WriteLine("Assigned values:");
      Console.WriteLine("   Struct members: {0}, {1}",
             Location2.x, Location2.y);
      Console.WriteLine("   Class members: {0}, {1}",
             Employee2.name, Employee2.id);
   }
}
/*
Output:
Default values:
   Struct members: 0, 0
   Class members: , 0
Assigned values:
   Struct members: 10, 20
   Class members: Cristina Potra, 1234
*/
```

请注意，本示例中字符串的默认值为 `null`。 因此，未显示此字符串。

### [new Modifier](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/new-modifier)

在用作声明修饰符时，`new` 关键字可以显式隐藏从基类继承的成员。 隐藏继承的成员时，该成员的派生版本将替换基类版本。 虽然可以不使用 `new` 修饰符来隐藏成员，但将收到编译器警告。 如果使用 `new` 来显式隐藏成员，将禁止此警告。

若要隐藏继承的成员，请使用相同名称在派生类中声明该成员，并使用 `new` 修饰符对其进行修饰。 例如:

C#复制

```csharp
public class BaseC
{
    public int x;
    public void Invoke() { }
}
public class DerivedC : BaseC
{
    new public void Invoke() { }
}
```

在此示例中，使用 `DerivedC.Invoke` 隐藏了 `BaseC.Invoke`。 字段 `x` 不受影响，因为未使用类似名称将其隐藏。

通过继承隐藏名称采用下列形式之一：

通常，在类或结构中引入的常数、字段、属性或类型会隐藏与其共享名称的所有基类成员。 有三种特殊情况。 例如，如果将名称为 `N` 的新字段声明为不可调用的类型，并且基类型将 `N` 声明为一种方法，则新字段在调用语法中不会隐藏基声明。 请参阅 [C# 5.0 语言规范](https://www.microsoft.com/download/details.aspx?id=7029)了解详细信息（参阅“表达式”一节中的“成员查找”部分）。

类或结构中引入的方法会隐藏基类中共享该名称的属性、字段和类型。 它还会隐藏具有相同签名的所有基类方法。

类或结构中引入的索引器会隐藏具有相同签名的所有基类索引器。

对同一成员同时使用 `new` 和 [override](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/override) 是错误的做法，因为这两个修饰符的含义互斥。 `new` 修饰符会用同样的名称创建一个新成员并使原始成员变为隐藏。 `override` 修饰符会扩展继承成员的实现。

在不隐藏继承成员的声明中使用 `new` 修饰符将会生成警告。

#### 示例

在此示例中，基类 `BaseC` 和派生类 `DerivedC` 使用相同的字段名 `x`，从而隐藏了继承字段的值。 此示例演示 `new` 修饰符的用法。 另外还演示了如何使用完全限定名访问基类的隐藏成员。

```csharp
public class BaseC
{
    public static int x = 55;
    public static int y = 22;
}

public class DerivedC : BaseC
{
    // Hide field 'x'.
    new public static int x = 100;

    static void Main()
    {
        // Display the new value of x:
        Console.WriteLine(x);

        // Display the hidden value of x:
        Console.WriteLine(BaseC.x);

        // Display the unhidden member y:
        Console.WriteLine(y);
    }
}
/*
Output:
100
55
22
*/
```

#### 示例

在此示例中，嵌套类隐藏了基类中同名的类。 此示例演示如何使用 `new` 修饰符来消除警告消息，以及如何使用完全限定名来访问隐藏的类成员。

```csharp
public class BaseC 
{
    public class NestedC 
    {
        public int x = 200;
        public int y;
    }
}

public class DerivedC : BaseC 
{
    // Nested type hiding the base type members.
    new public class NestedC   
    {
        public int x = 100;
        public int y; 
        public int z;
    }

    static void Main() 
    {
        // Creating an object from the overlapping class:
        NestedC c1  = new NestedC();

        // Creating an object from the hidden class:
        BaseC.NestedC c2 = new BaseC.NestedC();

        Console.WriteLine(c1.x);
        Console.WriteLine(c2.x);   
    }
}
/*
Output:
100
200
*/
```

如果移除 `new` 修饰符，程序仍将编译和运行，但你会收到以下警告：

复制

```
The keyword new is required on 'MyDerivedC.x' because it hides inherited member 'MyBaseC.x'.
```

### [new Constraint](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/new-constraint)

`new` 约束指定泛型类声明中的任何类型实参都必须有公共的无形参构造函数。 若要使用 new 约束，则该类型不能为抽象类型。

#### 示例

当泛型类创建类型的新实例时，请将 `new` 约束应用于类型参数，如下面的示例所示：

```csharp
class ItemFactory<T> where T : new()
{
    public T GetNewItem()
    {
        return new T();
    }
}
```

#### 示例

当与其他约束一起使用时，`new()` 约束必须最后指定：

```csharp
public class ItemFactory2<T>
    where T : IComparable, new()
{
}
```

有关详细信息，请参阅[类型参数的约束](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/generics/constraints-on-type-parameters)。

## [sizeof](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/sizeof)

用于获取非托管类型的大小（以字节为单位）。

非托管类型包括：

- 下表列出了简单类型：

  | 表达式            | 常量值      |
  | ----------------- | ----------- |
  | `sizeof(sbyte)`   | 1           |
  | `sizeof(byte)`    | 1           |
  | `sizeof(short)`   | 2           |
  | `sizeof(ushort)`  | 2           |
  | `sizeof(int)`     | 4           |
  | `sizeof(uint)`    | 4           |
  | `sizeof(long)`    | 8           |
  | `sizeof(ulong)`   | 8           |
  | `sizeof(char)`    | 2 (Unicode) |
  | `sizeof(float)`   | 4           |
  | `sizeof(double)`  | 8           |
  | `sizeof(decimal)` | 16          |
  | `sizeof(bool)`    | 1           |

- 枚举类型。

- 指针类型。

- 用户定义的结构，不包含任何实例字段或作为引用类型或构造类型的自动实现的实例属性。

下面的示例演示如何检索 `int` 的大小：

C#复制

```csharp
// Constant value 4:
int intSize = sizeof(int);
```

#### 备注

从 C# 2.0 版开始，将 `sizeof` 应用于简单类型或枚举类型不再需要在[不安全](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/unsafe)上下文中编译代码。

不能重载 `sizeof` 运算符。 `sizeof` 运算符的返回值是 `int` 类型。 上表列出了一些常量值，这些值对应于以某些简单类型为操作数的 `sizeof` 表达式。

对于所有其他类型（包括结构），`sizeof` 运算符只能在不安全代码块中使用。 虽然可以使用 [Marshal.SizeOf](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.interopservices.marshal.sizeof) 方法，但此方法返回的值并不总是与 `sizeof` 返回的值相同。 [Marshal.SizeOf](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.interopservices.marshal.sizeof) 在封送类型后返回大小，而 `sizeof`返回公共语言运行时分配的大小（包括所有填充）。

#### 示例

```csharp
class MainClass
{
    // unsafe not required for primitive types
    static void Main()
    {
        Console.WriteLine("The size of short is {0}.", sizeof(short));
        Console.WriteLine("The size of int is {0}.", sizeof(int));
        Console.WriteLine("The size of long is {0}.", sizeof(long));
    }
}
/*
Output:
    The size of short is 2.
    The size of int is 4.
    The size of long is 8.
*/
```

## [typeof](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/typeof)

用于为类型获取 [System.Type](https://docs.microsoft.com/zh-cn/dotnet/api/system.type) 对象。 `typeof` 表达式采用以下格式：

C#复制

```csharp
System.Type type = typeof(int);
```

#### 备注

若要获取表达式的运行时类型，可以使用 .NET Framework 方法 [GetType](https://docs.microsoft.com/zh-cn/dotnet/api/system.object.gettype)，如以下示例所示：

C#复制

```csharp
int i = 0;
System.Type type = i.GetType();
```

不能重载 `typeof` 运算符。

`typeof` 运算符也可用于开放式泛型类型。 具有多个类型参数的类型必须在规范中具有适当数量的逗号。 以下示例显示如何确定方法的返回类型是否为泛型 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1)。 如果返回类型不是 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 泛型类型，则 [Type.GetInterface](https://docs.microsoft.com/zh-cn/dotnet/api/system.type.getinterface) 将返回 `null`。

C#复制

```csharp
using System;
using System.Collections.Generic;
using System.Reflection;

class Example
{
    static void Main()
    {
        MethodInfo method = typeof(string).GetMethod("Copy");
        Type t = method.ReturnType.GetInterface(typeof(IEnumerable<>).Name);
        if (t != null)
            Console.WriteLine(t);
        else
            Console.WriteLine("The return type is not IEnumerable<T>.");
        /*
        Output:
        System.Collections.Generic.IEnumerable`1[System.Char]
        */
    }
}
```

#### 示例

C#复制

```csharp
public class ExampleClass
{
   public int sampleMember;
   public void SampleMethod() {}

   static void Main()
   {
      Type t = typeof(ExampleClass);
      // Alternatively, you could use
      // ExampleClass obj = new ExampleClass();
      // Type t = obj.GetType();

      Console.WriteLine("Methods:");
      System.Reflection.MethodInfo[] methodInfo = t.GetMethods();

      foreach (System.Reflection.MethodInfo mInfo in methodInfo)
         Console.WriteLine(mInfo.ToString());

      Console.WriteLine("Members:");
      System.Reflection.MemberInfo[] memberInfo = t.GetMembers();

      foreach (System.Reflection.MemberInfo mInfo in memberInfo)
         Console.WriteLine(mInfo.ToString());
   }
}
/*
 Output:
    Methods:
    Void SampleMethod()
    System.String ToString()
    Boolean Equals(System.Object)
    Int32 GetHashCode()
    System.Type GetType()
    Members:
    Void SampleMethod()
    System.String ToString()
    Boolean Equals(System.Object)
    Int32 GetHashCode()
    System.Type GetType()
    Void .ctor()
    Int32 sampleMember
*/
```

#### 示例

此示例使用 [GetType](https://docs.microsoft.com/zh-cn/dotnet/api/system.object.gettype) 方法来确定用于包含数值计算结果的类型。 这取决于所得数字的存储要求。

```csharp
class GetTypeTest
{
    static void Main()
    {
        int radius = 3;
        Console.WriteLine("Area = {0}", radius * radius * Math.PI);
        Console.WriteLine("The type is {0}",
                          (radius * radius * Math.PI).GetType()
        );
    }
}
/*
Output:
Area = 28.2743338823081
The type is System.Double
*/
```

## [true](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/true)

用作重载运算符或文本：

- [true 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/true-false-operators)
- [true 字面常数](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/true-literal)

### [true Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/true-false-operators)

`true` 运算符返回 [bool](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/bool) 值 `true`，以指明操作数一定为 true。 `false` 运算符返回 `bool` 值 `true`，以指明操作数一定为 false。 无法确保 `true` 和 `false` 运算符互补。 也就是说，`true` 和 `false` 运算符可能同时针对同一个操作数返回 `bool` 值 `false`。 如果某类型定义这两个运算符之一，它还必须定义另一个运算符。

如果包含已定义 `true` 和 `false` 运算符的类型以某种方式[重载](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator)[逻辑 OR 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/or-operator) `|` 或[逻辑 AND 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/and-operator) `&`，可以对相应类型的操作数分别执行[条件逻辑 OR 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/conditional-or-operator) `||` 或[条件逻辑 AND 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/conditional-and-operator) `&&` 运算。 有关详细信息，请参阅 [C# 语言规范](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/index)的[用户定义条件逻辑运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#user-defined-conditional-logical-operators)部分。

包含已定义 `true` 运算符的类型可以是 [if](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/if-else)、[do](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/do)、[while](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/while) 和 [for](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/for) 语句以及[条件运算符 `?:`](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/conditional-operator) 中控制条件表达式的结果的类型。 有关详细信息，请参阅 [C# 语言规范](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/index)中的 [Boolean 表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#boolean-expressions)部分。

> 如需支持三值逻辑（例如，在使用支持三值逻辑类型的数据库时），请使用 `bool?` 类型。 有关详细信息，请参阅[使用可以为 null 的类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/nullable-types/using-nullable-types)一文的 [bool? 类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/nullable-types/using-nullable-types#the-bool-type)部分。

下面的示例展示了定义 `true` 和 `false` 运算符的类型。 此外，它还重载了逻辑 AND 运算符 `&`，因此也可以对相应类型的操作数执行运算符 `&&` 运算。

```csharp
using System;

public struct LaunchStatus
{
    public static readonly LaunchStatus Green = new LaunchStatus(0);
    public static readonly LaunchStatus Yellow = new LaunchStatus(1);
    public static readonly LaunchStatus Red = new LaunchStatus(2);

    private int status;

    private LaunchStatus(int status)
    {
        this.status = status;
    }

    public static bool operator true(LaunchStatus x) => x == Green || x == Yellow;
    public static bool operator false(LaunchStatus x) => x == Red;

    public static LaunchStatus operator &(LaunchStatus x, LaunchStatus y)
    {
        if (x == Red || y == Red || (x == Yellow && y == Yellow))
        {
            return Red;
        }

        if (x == Yellow || y == Yellow)
        {
            return Yellow;
        }

        return Green;
    }

    public static bool operator ==(LaunchStatus x, LaunchStatus y) => x.status == y.status;
    public static bool operator !=(LaunchStatus x, LaunchStatus y) => !(x == y);

    public override bool Equals(object obj) => obj is LaunchStatus other && this == other;
    public override int GetHashCode() => status;
}

public class LaunchStatusTest
{
    public static void Main()
    {
        LaunchStatus okToLaunch = GetFuelLaunchStatus() && GetNavigationLaunchStatus();
        Console.WriteLine(okToLaunch ? "Ready to go!" : "Wait!");
    }

    static LaunchStatus GetFuelLaunchStatus()
    {
        Console.WriteLine("Getting fuel launch status...");
        return LaunchStatus.Red;
    }

    static LaunchStatus GetNavigationLaunchStatus()
    {
        Console.WriteLine("Getting navigation launch status...");
        return LaunchStatus.Yellow;
    }
}
```

请注意 `&&` 运算符的短路行为。 当 `GetFuelLaunchStatus` 方法返回 `LaunchStatus.Red` 时，不会计算 `&&` 运算符的第二个操作数。 这是因为 `LaunchStatus.Red` 一定为 false。 然后，逻辑 AND 运算符的结果不依赖第二个操作数的值。 示例输出如下所示：

```console
Getting fuel launch status...
Wait!
```

### [true Literal](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/true-literal)

表示[布尔](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/bool)值 `true`：

```csharp
bool check = true;
Console.WriteLine(check ? "Passed" : "Not passed");
// Output: 
// Passed
```

## [false](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/false)

用作重载运算符或文本：

- [false 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/true-false-operators)

### [false Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/true-false-operators)

见[true Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/true-false-operators)

### [false Literal](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/false-literal)

表示[布尔](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/bool)值 `false`：

```csharp
bool check = false;
Console.WriteLine(check ? "Passed" : "Not passed");
// Output:
// Not passed
```

## [stackalloc](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/stackalloc)

在不安全代码上下文中使用 `stackalloc` 关键字在堆栈上分配内存块。

C#复制

```csharp
int* block = stackalloc int[100];
```

### 备注

此关键字仅在局部变量初始值设定项中有效。 以下代码导致编译器错误。

```csharp
int* block;
// The following assignment statement causes compiler errors. You
// can use stackalloc only when declaring and initializing a local
// variable.
block = stackalloc int[100];
```

自 C# 7.3 起，可以对 `stackalloc` 数组使用数组初始值设定项语法。 以下所有声明都声明了一个包含三个元素的数组，这三个元素的值为整数 `1`、`2` 和 `3`：

```csharp
// Valid starting with C# 7.3
int* first = stackalloc int[3] { 1, 2, 3 };
int* second = stackalloc int[] { 1, 2, 3 };
int* third = stackalloc[] { 1, 2, 3 };
```

由于涉及指针类型，因此 `stackalloc` 需要 [unsafe](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/unsafe) 上下文。 有关详细信息，请参阅[不安全代码和指针](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/unsafe-code-pointers/index)。

`stackalloc` 就像 C 运行时库中的 [_alloca](https://docs.microsoft.com/zh-cn/cpp/c-runtime-library/reference/alloca)。

### 示例

下面的示例计算并显示 Fibonacci 序列中的前 20 个数字。 每个数字是前两个数字的总和。 在此代码中，在堆栈上分配足够大的可包含 20 个 `int` 类型元素的内存块，而不是在堆上分配。 块的地址存储在指针 `fib` 中。 此内存不受垃圾回收的限制，因此不必对其进行单边锁定（使用 [fixed](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/fixed-statement)）。 内存块的生存期受到定义此内存块的方法的生存期的限制。 在方法返回之前，无法释放内存。

```csharp
const int arraySize = 20;
int* fib = stackalloc int[arraySize];
int* p = fib;
// The sequence begins with 1, 1.
*p++ = *p++ = 1;
for (int i = 2; i < arraySize; ++i, ++p)
{
    // Sum the previous two numbers.
    *p = p[-1] + p[-2];
}
for (int i = 0; i < arraySize; ++i)
{
    Console.WriteLine(fib[i]);
}
/* Output:
   1
   1
   2
   3
   5
   8
   13
   21
   34
   55
   89
   144
   233
   377
   610
   987
   1597
   2584
   4181
   6765
 */
```

下面的示例将 `stackalloc` 整数数组初始化为位掩码，其中每个元素内都有一个位集。 下面展示了自 C# 7.3 起新增的初始值设定项语法：

```csharp
int* mask = stackalloc[] {
    0b_0000_0000_0000_0001,
    0b_0000_0000_0000_0010,
    0b_0000_0000_0000_0100,
    0b_0000_0000_0000_1000,
    0b_0000_0000_0001_0000,
    0b_0000_0000_0010_0000,
    0b_0000_0000_0100_0000,
    0b_0000_0000_1000_0000,
    0b_0000_0001_0000_0000,
    0b_0000_0010_0000_0000,
    0b_0000_0100_0000_0000,
    0b_0000_1000_0000_0000,
    0b_0001_0000_0000_0000,
    0b_0010_0000_0000_0000,
    0b_0100_0000_0000_0000,
    0b_1000_0000_0000_0000
};

for (int i = 0; i < 16; i++)
    Console.WriteLine(mask[i]);
/* Output:
   1
   2
   4
   8
   16
   32
   64
   128
   256
   512
   1024
   2048
   4096
   8192
   16384
   32768
 */
```

### 安全性

不安全代码的安全性低于安全替代项。 但是，使用 `stackalloc` 会自动启用公共语言运行时 (CLR) 中的缓冲区溢出检测功能。 如果检测到缓冲区溢出，则将尽快终止进程，以便将执行恶意代码的可能性降到最低。

## [nameof](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/nameof)

用于获取变量、类型或成员的简单（非限定）字符串名称。

在报告代码中的错误、挂接“模型-视图-控制器”(MVC) 链接、触发属性更改事件时，你通常会希望捕获方法的字符串名称。 使用 `nameof` 有助于在重命名定义时使代码始终有效。 以前必须使用字符串来引用定义，在重命名代码元素时，此方法很脆弱，因为工具不知道要检查这些字符串。

`nameof` 表达式具有此形式：

```csharp
if (x == null) throw new ArgumentNullException(nameof(x));  
WriteLine(nameof(person.Address.ZipCode)); // prints "ZipCode"  
```

### 关键用例

这些示例显示 `nameof` 的关键用例。

验证参数：

```csharp
void f(string s) {  
   if (s == null) throw new ArgumentNullException(nameof(s));  
}  
```

MVC 操作链接：

```html
<%= Html.ActionLink("Sign up",  
            @typeof(UserController),  
            @nameof(UserController.SignUp))  
%>  
```

INotifyPropertyChanged：

```csharp
int p {  
   get { return this.p; }  
   set { this.p = value; PropertyChanged(this, new PropertyChangedEventArgs(nameof(this.p)); } // nameof(p) works too  
}  
```

XAML 依赖项属性：

```csharp
public static DependencyProperty AgeProperty = DependencyProperty.Register(nameof(Age), typeof(int), typeof(C));  
```

日志记录：

C#复制

```csharp
void f(int i) {  
   Log(nameof(f), "method entry");  
}  
```

特性:

```csharp
[DebuggerDisplay("={" + nameof(GetString) + "()}")]  
class C {  
   string GetString() { }  
}  
```

### 示例

一些 C# 示例：

```csharp
using Stuff = Some.Cool.Functionality  
class C {  
    static int Method1 (string x, int y) {}  
    static int Method1 (string x, string y) {}  
    int Method2 (int z) {}  
    string f<T>() => nameof(T);  
}  
  
var c = new C()  
  
class Test {  
    static void Main (string[] args) {  
        Console.WriteLine(nameof(C)); // -> "C"  
        Console.WriteLine(nameof(C.Method1)); // -> "Method1"   
        Console.WriteLine(nameof(C.Method2)); // -> "Method2"  
        Console.WriteLine(nameof(c.Method1)); // -> "Method1"   
        Console.WriteLine(nameof(c.Method2)); // -> "Method2"  
        // Console.WriteLine(nameof(z)); -> "z" [inside of Method2 ok, inside Method1 is a compiler error]  
        Console.WriteLine(nameof(Stuff)); // -> "Stuff"  
        // Console.WriteLine(nameof(T)); -> "T" [works inside of method but not in attributes on the method]  
        Console.WriteLine(nameof(f)); // -> "f"  
        // Console.WriteLine(nameof(f<T>)); -> [syntax error]  
        // Console.WriteLine(nameof(f<>)); -> [syntax error]  
        // Console.WriteLine(nameof(Method2())); -> [error "This expression does not have a name"]  
    }
}
```

### 备注

`nameof` 的参数必须是简单名称、限定名称、成员访问、指定成员的基访问或指定成员的此类访问。 参数表达式标识代码定义，但从不进行计算。

因为在语法上参数必须为表达式，因此有很多禁用内容无需列出。 以下内容会产生错误，值得一提：预定义的类型（如 `int` 或 `void`）、可以为 null 的类型（`Point?`）、数组类型（`Customer[,]`）、指针类型 (`Buffer*`)、限定别名 (`A::B`)、未绑定的泛型类型 (`Dictionary<,>`)、预处理符号 (`DEBUG`) 和标签 (`loop:`)。

如果需要获取完全限定名，可以将 `typeof` 表达式和 `nameof`结合使用。 例如:

```csharp
class C {
    void f(int i) {  
        Log($"{typeof(C)}.{nameof(f)}", "method entry");  
    }
}
```

遗憾的是，`typeof` 不是类似于 `nameof` 的常数表达式，因此，不能在 `nameof` 的所有相同位置将 `typeof` 和 `nameof` 结合使用。 例如，以下操作会导致 CS0182 编译错误：

```csharp
[DebuggerDisplay("={" + typeof(C) + nameof(GetString) + "()}")]  
class C {  
   string GetString() { }  
}  
```

在这些示例中，显示了可使用类型名称并访问实例方法名称。 按照计算表达式的要求，无需具有类型的实例。 在某些情况下使用类型名称非常方便，因为只引用名称而不使用实例数据，因此不必构建实例变量或表达式。

你可以引用类中特性表达式的类成员。

无法获取类似于“`Method1 (str, str)`”的签名信息。 实现该操作的一种方法是使用表达式 `Expression e = () => A.B.Method1("s1", "s2")`，并从生成的表达式树中拉取 MemberInfo。