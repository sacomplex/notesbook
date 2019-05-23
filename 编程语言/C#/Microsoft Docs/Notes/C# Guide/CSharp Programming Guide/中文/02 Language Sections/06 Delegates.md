[C# programming guide](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/index)

# Language Sections

## [Delegates](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/delegates/index)

[委托](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/delegate)是一种引用类型，表示对具有特定参数列表和返回类型的方法的引用。 在实例化委托时，你可以将其实例与任何具有兼容签名和返回类型的方法相关联。 你可以通过委托实例调用方法。

委托用于将方法作为参数传递给其他方法。 事件处理程序就是通过委托调用的方法。 你可以创建一个自定义方法，当发生特定事件时，某个类（如 Windows 控件）就可以调用你的方法。 下面的示例演示了一个委托声明：

```csharp
public delegate int PerformCalculation(int x, int y);
```

可将任何可访问类或结构中与委托类型匹配的任何方法分配给委托。 该方法可以是静态方法，也可以是实例方法。 这样便能通过编程方式来更改方法调用，还可以向现有类中插入新代码。

> 在方法重载的上下文中，方法的签名不包括返回值。 但在委托的上下文中，签名包括返回值。 换句话说，方法和委托必须具有相同的返回类型。

将方法作为参数进行引用的能力使委托成为定义回调方法的理想选择。 例如，对比较两个对象的方法的引用可以作为参数传递到排序算法中。 由于比较代码在一个单独的过程中，因此可通过更常见的方式编写排序算法。

### 委托概述

委托具有以下属性：

- 委托类似于 C++ 函数指针，但委托完全面向对象，不像 C++ 指针会记住函数，委托会同时封装对象实例和方法。
- 委托允许将方法作为参数进行传递。
- 委托可用于定义回调方法。
- 委托可以链接在一起；例如，可以对一个事件调用多个方法。
- 方法不必与委托类型完全匹配。 有关详细信息，请参阅[使用委托中的变体](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/covariance-contravariance/using-variance-in-delegates)。
- C# 2.0 版引入了[匿名方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/anonymous-methods)的概念，可以将代码块作为参数（而不是单独定义的方法）进行传递。 C# 3.0 引入了 Lambda 表达式，利用它们可以更简练地编写内联代码块。 匿名方法和 Lambda 表达式（在某些上下文中）都可编译为委托类型。 这些功能现在统称为匿名函数。 有关 lambda 表达式的详细信息，请参阅[匿名函数](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/anonymous-functions)。

### 本节内容

- [使用委托](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/delegates/using-delegates)
- [何时使用委托，而不是接口（C# 编程指南）](https://docs.microsoft.com/previous-versions/visualstudio/visual-studio-2010/ms173173(v=vs.100))
- [带有命名方法的委托与带有匿名方法的委托](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/delegates/delegates-with-named-vs-anonymous-methods)
- [匿名方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/anonymous-methods)
- [使用委托中的变体](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/covariance-contravariance/using-variance-in-delegates)
- [如何：合并委托（多播委托）](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/delegates/how-to-combine-delegates-multicast-delegates)
- [如何：声明、实例化和使用委托](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/delegates/how-to-declare-instantiate-and-use-a-delegate)

### [Using Delegates](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/delegates/using-delegates)

[委托](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/delegate)是安全封装方法的类型，类似于 C 和 C++ 中的函数指针。 与 C 函数指针不同的是，委托是面向对象的、类型安全的和可靠的。 委托的类型由委托的名称确定。 以下示例声明名为 `Del` 的委托，该委托可以封装采用[字符串](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/string)作为参数并返回 [void](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/void) 的方法：

```csharp
public delegate void Del(string message);
```

委托对象通常通过提供委托将封装的方法的名称或使用[匿名方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/anonymous-methods)构造。 对委托进行实例化后，委托会将对其进行的方法调用传递到该方法。 调用方传递到委托的参数将传递到该方法，并且委托会将方法的返回值（如果有）返回到调用方。 这被称为调用委托。 实例化的委托可以按封装的方法本身进行调用。 例如:

```csharp
// Create a method for a delegate.
public static void DelegateMethod(string message)
{
    System.Console.WriteLine(message);
}
```

```csharp
// Instantiate the delegate.
Del handler = DelegateMethod;

// Call the delegate.
handler("Hello World");
```

委托类型派生自 .NET Framework 中的 [Delegate](https://docs.microsoft.com/zh-cn/dotnet/api/system.delegate) 类。 委托类型是[封装的](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/sealed)，它们不能派生自 [Delegate](https://docs.microsoft.com/zh-cn/dotnet/api/system.delegate)，也不能从其派生出自定义类。 由于实例化的委托是一个对象，因此可以作为参数传递或分配给一个属性。 这允许方法作为参数接受委托并在稍后调用委托。 这被称为异步回调，是在长进程完成时通知调用方的常用方法。 当以这种方式使用委托时，使用委托的代码不需要知道要使用的实现方法。 功能类似于封装接口提供的功能。

回调的另一个常见用途是定义自定义比较方法并将该委托传递到短方法。 它允许调用方的代码成为排序算法的一部分。 以下示例方法使用 `Del` 类型作为参数：

```csharp
public void MethodWithCallback(int param1, int param2, Del callback)
{
    callback("The number is: " + (param1 + param2).ToString());
}
```

然后，你可以将上面创建的委托传递到该方法：

```csharp
MethodWithCallback(1, 2, handler);
```

并将以下输出接收到控制台：

```
The number is: 3
```

以抽象方式使用委托时，`MethodWithCallback` 不需要直接调用控制台，记住，其不必设计为具有控制台。 `MethodWithCallback` 的作用是简单准备字符串并将字符串传递到其他方法。 由于委托的方法可以使用任意数量的参数，此功能特别强大。

当委托构造为封装实例方法时，委托将同时引用实例和方法。 委托不知道除其所封装方法以外的实例类型，因此委托可以引用任何类型的对象，只要该对象上有与委托签名匹配的方法。 当委托构造为封装静态方法时，委托仅引用方法。 请考虑以下声明：

```csharp
public class MethodClass
{
    public void Method1(string message) { }
    public void Method2(string message) { }
}
```

加上之前显示的静态 `DelegateMethod`，我们现在已有三个 `Del` 实例可以封装的方法。

调用时，委托可以调用多个方法。 这被称为多播。 若要向委托的方法列表（调用列表）添加其他方法，只需使用加法运算符或加法赋值运算符（“+”或“+=”）添加两个委托。 例如:

```csharp
MethodClass obj = new MethodClass();
Del d1 = obj.Method1;
Del d2 = obj.Method2;
Del d3 = DelegateMethod;

//Both types of assignment are valid.
Del allMethodsDelegate = d1 + d2;
allMethodsDelegate += d3;
```

此时，`allMethodsDelegate` 的调用列表中包含三个方法，分别为 `Method1`、`Method2` 和 `DelegateMethod`。 原有的三个委托（`d1`、`d2` 和 `d3`）保持不变。 调用 `allMethodsDelegate` 时，将按顺序调用所有三个方法。 如果委托使用引用参数，引用将按相反的顺序传递到所有这三个方法，并且一种方法进行的任何更改都将在另一种方法上见到。 当方法引发未在方法内捕获到的异常时，该异常将传递到委托的调用方，并且不会调用调用列表中的后续方法。 如果委托具有返回值和/或输出参数，它将返回上次调用方法的返回值和参数。 若要删除调用列表中的方法，请使用减法运算符或减法赋值运算符（“+”或“+=”）。 

例如:

```csharp
//remove Method1
allMethodsDelegate -= d1;

// copy AllMethodsDelegate while removing d2
Del oneMethodDelegate = allMethodsDelegate - d2;
```

由于委托类型派生自 `System.Delegate`，因此可以在委托上调用该类定义的方法和属性。 例如，若要查询委托调用列表中方法的数量，你可以编写：

```csharp
int invocationCount = d1.GetInvocationList().GetLength(0);
```

调用列表中具有多个方法的委托派生自 [MulticastDelegate](https://docs.microsoft.com/zh-cn/dotnet/api/system.multicastdelegate)，该类属于 `System.Delegate` 的子类。 由于这两个类都支持 `GetInvocationList`，因此在其他情况下，上述代码也将产生作用。

多播委托广泛用于事件处理中。 事件源对象将事件通知发送到已注册接收该事件的接收方对象。 若要注册一个事件，接收方需要创建用于处理该事件的方法，然后为该方法创建委托并将委托传递到事件源。 事件发生时，源调用委托。 然后，委托将对接收方调用事件处理方法，从而提供事件数据。 给定事件的委托类型由事件源确定。 有关详细信息，请参阅[事件](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/events/index)。

在编译时比较分配的两个不同类型的委托将导致编译错误。 如果委托实例是静态的 `System.Delegate` 类型，则允许比较，但在运行时将返回 false。 例如:

```csharp
delegate void Delegate1();
delegate void Delegate2();

static void method(Delegate1 d, Delegate2 e, System.Delegate f)
{
    // Compile-time error.
    //Console.WriteLine(d == e);

    // OK at compile-time. False if the run-time type of f 
    // is not the same as that of d.
    System.Console.WriteLine(d == f);
}
```

### [Delegates with Named vs. Anonymous Methods](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/delegates/delegates-with-named-vs-anonymous-methods)

[委托](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/delegate)可以与命名方法相关联。 使用命名方法实例化委托时，该方法作为参数传递，例如：

```csharp
// Declare a delegate:
delegate void Del(int x);

// Define a named method:
void DoWork(int k) { /* ... */ }

// Instantiate the delegate using the method as a parameter:
Del d = obj.DoWork;
```

这称为使用命名方法。 使用命名方法构造的委托可以封装[静态](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/static)方法或实例方法。 命名方法是在早期版本的 C# 中实例化委托的唯一方式。 但是，如果创建新方法会造成多余开销，C# 允许你实例化委托并立即指定调用委托时委托将处理的代码块。 代码块可包含 Lambda 表达式或匿名方法。 有关详细信息，请参阅[匿名函数](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/anonymous-functions)。

#### 备注

作为委托参数传递的方法必须具有与委托声明相同的签名。

委托实例可以封装静态方法或实例方法。

尽管委托可以使用 [out](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/out-parameter-modifier) 参数，但不建议将该委托与多播事件委托配合使用，因为你无法知道将调用哪个委托。

#### 示例 1

以下是声明和使用委托的简单示例。 请注意，委托 `Del` 与关联的方法 `MultiplyNumbers` 具有相同的签名

```csharp
// Declare a delegate
delegate void Del(int i, double j);

class MathClass
{
    static void Main()
    {
        MathClass m = new MathClass();

        // Delegate instantiation using "MultiplyNumbers"
        Del d = m.MultiplyNumbers;

        // Invoke the delegate object.
        System.Console.WriteLine("Invoking the delegate using 'MultiplyNumbers':");
        for (int i = 1; i <= 5; i++)
        {
            d(i, 2);
        }

        // Keep the console window open in debug mode.
        System.Console.WriteLine("Press any key to exit.");
        System.Console.ReadKey();
    }

    // Declare the associated method.
    void MultiplyNumbers(int m, double n)
    {
        System.Console.Write(m * n + " ");
    }
}
/* Output:
    Invoking the delegate using 'MultiplyNumbers':
    2 4 6 8 10
*/
```

#### 示例 2

在下面的示例中，一个委托映射到静态方法和实例方法，并返回来自两种方法的具体信息。

```csharp
// Declare a delegate
delegate void Del();

class SampleClass
{
    public void InstanceMethod()
    {
        System.Console.WriteLine("A message from the instance method.");
    }

    static public void StaticMethod()
    {
        System.Console.WriteLine("A message from the static method.");
    }
}

class TestSampleClass
{
    static void Main()
    {
        SampleClass sc = new SampleClass();

        // Map the delegate to the instance method:
        Del d = sc.InstanceMethod;
        d();

        // Map to the static method:
        d = SampleClass.StaticMethod;
        d();
    }
}
/* Output:
    A message from the instance method.
    A message from the static method.
*/
```

### [How to: Combine Delegates (Multicast Delegates)(C# Programming Guide)](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/delegates/how-to-combine-delegates-multicast-delegates)

此示例演示如何创建多播委托。 [委托](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/delegate)对象的一个有用属性在于可通过使用 `+` 运算符将多个对象分配到一个委托实例。 多播委托包含已分配委托列表。 此多播委托被调用时会依次调用列表中的委托。 仅可合并类型相同的委托。

- 运算符可用于从多播委托中删除组件委托。

#### 示例

```csharp
using System;

// Define a custom delegate that has a string parameter and returns void.
delegate void CustomDel(string s);

class TestClass
{
    // Define two methods that have the same signature as CustomDel.
    static void Hello(string s)
    {
        System.Console.WriteLine("  Hello, {0}!", s);
    }

    static void Goodbye(string s)
    {
        System.Console.WriteLine("  Goodbye, {0}!", s);
    }

    static void Main()
    {
        // Declare instances of the custom delegate.
        CustomDel hiDel, byeDel, multiDel, multiMinusHiDel;

        // In this example, you can omit the custom delegate if you 
        // want to and use Action<string> instead.
        //Action<string> hiDel, byeDel, multiDel, multiMinusHiDel;

        // Create the delegate object hiDel that references the
        // method Hello.
        hiDel = Hello;

        // Create the delegate object byeDel that references the
        // method Goodbye.
        byeDel = Goodbye;

        // The two delegates, hiDel and byeDel, are combined to 
        // form multiDel. 
        multiDel = hiDel + byeDel;

        // Remove hiDel from the multicast delegate, leaving byeDel,
        // which calls only the method Goodbye.
        multiMinusHiDel = multiDel - hiDel;

        Console.WriteLine("Invoking delegate hiDel:");
        hiDel("A");
        Console.WriteLine("Invoking delegate byeDel:");
        byeDel("B");
        Console.WriteLine("Invoking delegate multiDel:");
        multiDel("C");
        Console.WriteLine("Invoking delegate multiMinusHiDel:");
        multiMinusHiDel("D");
    }
}
/* Output:
Invoking delegate hiDel:
  Hello, A!
Invoking delegate byeDel:
  Goodbye, B!
Invoking delegate multiDel:
  Hello, C!
  Goodbye, C!
Invoking delegate multiMinusHiDel:
  Goodbye, D!
*/
```

### [How to: Declare, Instantiate, and Use a Delegate](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/delegates/how-to-declare-instantiate-and-use-a-delegate)

在 C# 1.0 和更高版本中，可以如下面的示例所示声明委托。

C#复制

```csharp
// Declare a delegate.
delegate void Del(string str);

// Declare a method with the same signature as the delegate.
static void Notify(string name)
{
    Console.WriteLine("Notification received for: {0}", name);
}
```

C#复制

```csharp
// Create an instance of the delegate.
Del del1 = new Del(Notify);
```

C# 2.0 提供了更简单的方法来编写前面的声明，如下面的示例所示。

C#复制

```csharp
// C# 2.0 provides a simpler way to declare an instance of Del.
Del del2 = Notify;
```

在 C# 2.0 和更高版本中，还可以使用匿名方法来声明和初始化[委托](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/delegate)，如下面的示例所示。

C#复制

```csharp
// Instantiate Del by using an anonymous method.
Del del3 = delegate(string name)
    { Console.WriteLine("Notification received for: {0}", name); };
```

在 C# 3.0 和更高版本中，还可以通过使用 lambda 表达式声明和实例化委托，如下面的示例所示。

C#复制

```csharp
// Instantiate Del by using a lambda expression.
Del del4 = name =>  { Console.WriteLine("Notification received for: {0}", name); };
```

有关详细信息，请参阅 [Lambda 表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/lambda-expressions)。

下面的示例演示如何声明、实例化和使用委托。 `BookDB` 类封装用来维护书籍数据库的书店数据库。 它公开一个方法 `ProcessPaperbackBooks`，用于在数据库中查找所有平装书并为每本书调用委托。 使用的 `delegate` 类型名为 `ProcessBookDelegate`。 `Test` 类使用此类打印平装书的书名和平均价格。

使用委托提升书店数据库和客户端代码之间的良好分隔功能。 客户端代码程序不知道如何存储书籍或书店代码如何查找平装书。 书店代码不知道它在找到平装书之后对其执行什么处理。

#### 示例

```csharp
// A set of classes for handling a bookstore:
namespace Bookstore
{
    using System.Collections;

    // Describes a book in the book list:
    public struct Book
    {
        public string Title;        // Title of the book.
        public string Author;       // Author of the book.
        public decimal Price;       // Price of the book.
        public bool Paperback;      // Is it paperback?

        public Book(string title, string author, decimal price, bool paperBack)
        {
            Title = title;
            Author = author;
            Price = price;
            Paperback = paperBack;
        }
    }

    // Declare a delegate type for processing a book:
    public delegate void ProcessBookDelegate(Book book);

    // Maintains a book database.
    public class BookDB
    {
        // List of all books in the database:
        ArrayList list = new ArrayList();

        // Add a book to the database:
        public void AddBook(string title, string author, decimal price, bool paperBack)
        {
            list.Add(new Book(title, author, price, paperBack));
        }

        // Call a passed-in delegate on each paperback book to process it: 
        public void ProcessPaperbackBooks(ProcessBookDelegate processBook)
        {
            foreach (Book b in list)
            {
                if (b.Paperback)
                    // Calling the delegate:
                    processBook(b);
            }
        }
    }
}


// Using the Bookstore classes:
namespace BookTestClient
{
    using Bookstore;

    // Class to total and average prices of books:
    class PriceTotaller
    {
        int countBooks = 0;
        decimal priceBooks = 0.0m;

        internal void AddBookToTotal(Book book)
        {
            countBooks += 1;
            priceBooks += book.Price;
        }

        internal decimal AveragePrice()
        {
            return priceBooks / countBooks;
        }
    }

    // Class to test the book database:
    class Test
    {
        // Print the title of the book.
        static void PrintTitle(Book b)
        {
            System.Console.WriteLine("   {0}", b.Title);
        }

        // Execution starts here.
        static void Main()
        {
            BookDB bookDB = new BookDB();

            // Initialize the database with some books:
            AddBooks(bookDB);

            // Print all the titles of paperbacks:
            System.Console.WriteLine("Paperback Book Titles:");

            // Create a new delegate object associated with the static 
            // method Test.PrintTitle:
            bookDB.ProcessPaperbackBooks(PrintTitle);

            // Get the average price of a paperback by using
            // a PriceTotaller object:
            PriceTotaller totaller = new PriceTotaller();

            // Create a new delegate object associated with the nonstatic 
            // method AddBookToTotal on the object totaller:
            bookDB.ProcessPaperbackBooks(totaller.AddBookToTotal);

            System.Console.WriteLine("Average Paperback Book Price: ${0:#.##}",
                    totaller.AveragePrice());
        }

        // Initialize the book database with some test books:
        static void AddBooks(BookDB bookDB)
        {
            bookDB.AddBook("The C Programming Language", "Brian W. Kernighan and Dennis M. Ritchie", 19.95m, true);
            bookDB.AddBook("The Unicode Standard 2.0", "The Unicode Consortium", 39.95m, true);
            bookDB.AddBook("The MS-DOS Encyclopedia", "Ray Duncan", 129.95m, false);
            bookDB.AddBook("Dogbert's Clues for the Clueless", "Scott Adams", 12.00m, true);
        }
    }
}
/* Output:
Paperback Book Titles:
   The C Programming Language
   The Unicode Standard 2.0
   Dogbert's Clues for the Clueless
Average Paperback Book Price: $23.97
*/
```

#### 可靠编程

- 声明委托。

  以下语句声明新的委托类型。

  ```csharp
  public delegate void ProcessBookDelegate(Book book);
  ```

  每个委托类型描述自变量的数量和类型，以及它可以封装的方法的返回值类型。 每当需要一组新的自变量类型或返回值类型，则必须声明一个新的委托类型。

- 实例化委托。

  声明委托类型后，则必须创建委托对象并将其与特定的方法相关联。 在上例中，你通过将 `PrintTitle` 方法传递给 `ProcessPaperbackBooks` 方法执行此操作，如下面的示例所示：

  ```csharp
  bookDB.ProcessPaperbackBooks(PrintTitle);
  ```

  这将创建一个新的与[静态](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/static)方法 `Test.PrintTitle` 关联的委托对象。 同样，如下面的示例所示，传递对象 `totaller` 中的非静态方法 `AddBookToTotal`：

  ```csharp
  bookDB.ProcessPaperbackBooks(totaller.AddBookToTotal);
  ```

  在这两种情况下，都将新的委托对象传递给 `ProcessPaperbackBooks` 方法。

  创建委托后，它与之关联的方法就永远不会更改；委托对象是不可变的。

- 调用委托。

  创建委托对象后，通常会将委托对象传递给将调用该委托的其他代码。 委托对象是通过使用委托对象的名称调用的，后跟用圆括号括起来的将传递给委托的自变量。 下面是一个委托调用示例：

  ```csharp
  processBook(b);
  ```

  委托可以同步调用（如在本例中）或通过使用 `BeginInvoke` 和 `EndInvoke` 方法异步调用。