# [Method Parameters](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/method-parameters)

为不具有 [in](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/in-parameter-modifier)、[ref](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ref) 或 [out](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/out-parameter-modifier) 的方法声明的参数会按值传递给调用的方法。 可以在方法中更改该值，但当控制传递回调用过程时，不会保留更改后的值。 可以通过使用方法参数关键字更改此行为。

本部分介绍声明方法参数时可以使用的关键字：

- [params](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/params) 指定此参数采用可变数量的参数。
- [in](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/in-parameter-modifier) 指定此参数由引用传递，但只由调用方法读取。
- [ref](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ref) 指定此参数由引用传递，可能由调用方法读取或写入。
- [out](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/out-parameter-modifier) 指定此参数由引用传递，由调用方法写入。

## [params](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/params)

使用 `params` 关键字可以指定采用数目可变的参数的[方法参数](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/method-parameters)。

可以发送参数声明中所指定类型的逗号分隔的参数列表或指定类型的参数数组。 还可以不发送参数。 如果未发送任何参数，则 `params` 列表的长度为零。

在方法声明中的 `params` 关键字之后不允许有任何其他参数，并且在方法声明中只允许有一个 `params` 关键字。

声明的 `params` 参数类型必须是一维数组，如以下示例所示。 否则，发生编译器错误 [CS0225](https://docs.microsoft.com/zh-cn/dotnet/csharp/misc/cs0225)。

#### 示例

下面的示例演示可向 `params` 形参发送实参的各种方法。

```csharp
public class MyClass
{
    public static void UseParams(params int[] list)
    {
        for (int i = 0; i < list.Length; i++)
        {
            Console.Write(list[i] + " ");
        }
        Console.WriteLine();
    }

    public static void UseParams2(params object[] list)
    {
        for (int i = 0; i < list.Length; i++)
        {
            Console.Write(list[i] + " ");
        }
        Console.WriteLine();
    }

    static void Main()
    {
        // You can send a comma-separated list of arguments of the 
        // specified type.
        UseParams(1, 2, 3, 4);
        UseParams2(1, 'a', "test");

        // A params parameter accepts zero or more arguments.
        // The following calling statement displays only a blank line.
        UseParams2();

        // An array argument can be passed, as long as the array
        // type matches the parameter type of the method being called.
        int[] myIntArray = { 5, 6, 7, 8, 9 };
        UseParams(myIntArray);

        object[] myObjArray = { 2, 'b', "test", "again" };
        UseParams2(myObjArray);

        // The following call causes a compiler error because the object
        // array cannot be converted into an integer array.
        //UseParams(myObjArray);

        // The following call does not cause an error, but the entire 
        // integer array becomes the first element of the params array.
        UseParams2(myIntArray);
    }
}
/*
Output:
    1 2 3 4
    1 a test
           
    5 6 7 8 9
    2 b test again
    System.Int32[]
*/
```

## [in (Parameter Modifier)](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/in-parameter-modifier)

`in` 关键字通过引用传递参数。 它类似于 [ref](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ref) 或 [out](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/out-parameter-modifier) 关键字，不同之处在于 `in` 参数无法通过调用的方法进行修改。 而 `ref` 参数是可以修改的，`out` 参数必须由调用方方法修改，且这些修改可以在调用上下文中看到。

```csharp
int readonlyArgument = 44;
InArgExample(readonlyArgument);
Console.WriteLine(readonlyArgument);     // value is still 44

void InArgExample(in int number)
{
    // Uncomment the following line to see error CS8331
    //number = 19;
}
```

前面的示例说明调用站点处通常不需要 `in` 修饰符。 仅在方法声明中需要它。

> `in` 关键字还作为 `foreach` 语句的一部分，或作为 LINQ 查询中 `join` 子句的一部分，与泛型类型参数一起使用来指定该类型参数为逆变。 有关在这些上下文使用 `in` 关键字的详细信息，请参阅 [in](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/in)，其中提供了所有这些用法的链接。

作为 `in` 参数传递的变量在方法调用中传递之前必须进行初始化。 但是，所调用的方法可能不会分配值或修改参数。

尽管 `in`、`ref` 和 `out` 关键字会导致不同的运行时行为，它们并不被视为编译时方法签名的一部分。 因此，如果唯一的不同是一个方法采用 `ref` 或 `in` 参数，而另一个方法采用 `out` 参数，则无法重载这两个方法。 例如，以下代码将不会编译：

```csharp
class CS0663_Example
{
    // Compiler error CS0663: "Cannot define overloaded 
    // methods that differ only on in, ref and out".
    public void SampleMethod(in int i) { }
    public void SampleMethod(ref int i) { }
}
```

存在 `in` 时可以重载：

```csharp
class InOverloads
{
    public void SampleMethod(in int i) { }
    public void SampleMethod(int i) { }
}
```

#### 重载决策规则

通过理解使用 `in` 参数的动机，可以理解使用按值方法和使用 `in` 参数方法的重载决策规则。 定义使用 `in`参数的方法是一项潜在的性能优化。 某些 `struct` 类型参数可能很大，在紧凑的循环或关键代码路径中调用方法时，复制这些结构的成本就很高。 方法声明 `in` 参数以指定参数可能按引用安全传递，因为所调用的方法不修改该参数的状态。 按引用传递这些参数可以避免（可能产生的）高昂的复制成本。

为调用站点上的参数指定 `in` 通常为可选。 按值传递参数和使用 `in` 修饰符按引用传递参数这两种方法并没有语义差异。 可以在调用站点选择 `in` 修饰符，因为你不需要指出参数值可能会改变。 在调用站点显式添加 `in`修饰符以确保参数是按引用传递，而不是按值传递。 显式使用 `in` 有以下两个效果：

首先，在调用站点指定 `in` 会强制编译器选择使用匹配的 `in` 参数定义的方法。 否则，如果两种方法唯一的区别在于是否存在 `in`，则按值重载的匹配度会更高。

第二点，指定 `in` 会声明你想按引用传递参数。 结合 `in` 使用的参数必须代表一个可以直接引用的位置。 `out` 和 `ref` 参数的相同常规规则适用：不得使用常量、普通属性或其他生成值的表达式。 否则，在调用站点省略 `in` 就会通知编译器你将允许它创建临时变量，并按只读引用传递至方法。 编译器创建临时变量以克服一些 `in` 参数的限制：

- 临时变量允许将编译时常数作为 `in` 参数。
- 临时变量允许使用属性或 `in` 参数的其他表达式。
- 存在从实参类型到形参类型的隐式转换时，临时变量允许使用实参。

在前面的所有实例中，编译器创建了临时变量，用于存储常数、属性或其他表达式的值。

以下代码阐释了这些规则：

```csharp
static void Method(in int argument)
{
    // implementation removed
}

Method(5); // OK, temporary variable created.
Method(5L); // CS1503: no implicit conversion from long to int
short s = 0;
Method(s); // OK, temporary int created with the value 0
Method(in s); // CS1503: cannot convert from in short to in int
int i = 42;
Method(i); // passed by readonly reference
Method(in i); // passed by readonly reference, explicitly using `in`
```

现在，假设可以使用另一种使用按值参数的方法。 结果的变化如以下代码所示：

```csharp
static void Method(int argument)
{
    // implementation removed
}

static void Method(in int argument)
{
    // implementation removed
}

Method(5); // Calls overload passed by value
Method(5L); // CS1503: no implicit conversion from long to int
short s = 0;
Method(s); // Calls overload passed by value.
Method(in s); // CS1503: cannot convert from in short to in int
int i = 42;
Method(i); // Calls overload passed by value
Method(in i); // passed by readonly reference, explicitly using `in`
```

最后一个是按引用传递参数的唯一方法调用。

> 为了简化操作，前面的代码将 `int` 用作参数类型。 因为大多数新式计算机中的引用都比 `int` 大，所以将单个 `int` 作为只读引用传递没有任何好处。

####  `in` 参数的限制

不能将 `in`、`ref` 和 `out` 关键字用于以下几种方法：

- 异步方法，通过使用 [async](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/async) 修饰符定义。
- 迭代器方法，包括 [yield return](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/yield) 或 `yield break` 语句。

## [ref](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/ref)

`ref` 关键字指示按引用传递的值。 它用在四种不同的上下文中：

- 在方法签名和方法调用中，按引用将参数传递给方法。 有关详细信息，请参阅[按引用传递参数](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ref#passing-an-argument-by-reference)。
- 在方法签名中，按引用将值返回给调用方。 有关详细信息，请参阅[引用返回值](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ref#reference-return-values)。
- 在成员正文中，指示引用返回值是否作为调用方欲修改的引用被存储在本地，或在一般情况下，局部变量按引用访问另一个值。 有关详细信息，请参阅 [Ref 局部变量](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ref#ref-locals)。
- 在 `struct` 声明中声明 `ref struct` 或 `ref readonly struct`。 有关详细信息，请参阅 [ref 结构类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ref#ref-struct-types)。

#### 按引用传递参数

在方法的参数列表中使用 `ref` 关键字时，它指示参数按引用传递，而非按值传递。 按引用传递的效果是，对所调用方法中参数进行的任何更改都反映在调用方法中。 例如，如果调用方传递本地变量表达式或数组元素访问表达式，所调用方法会替换 ref 参数引用的对象，然后，当该方法返回时，调用方的本地变量或数组元素将开始引用新对象。

> 不要混淆通过引用传递的概念与引用类型的概念。 这两种概念是不同的。 无论方法参数是值类型还是引用类型，均可由 `ref` 修改。 当通过引用传递时，不会对值类型装箱。

若要使用 `ref` 参数，方法定义和调用方法均必须显式使用 `ref` 关键字，如下面的示例所示。

```csharp
void Method(ref int refArgument)
{
    refArgument = refArgument + 44;
}

int number = 1;
Method(ref number);
Console.WriteLine(number);
// Output: 45
```

传递到 `ref` 或 `in` 形参的实参必须先经过初始化，然后才能传递。 这与 [out](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/out-parameter-modifier) 形参不同，在传递之前，不需要显式初始化该形参的实参。

类的成员不能具有仅在 `ref`、`in` 或 `out` 方面不同的签名。 如果类型的两个成员之间的唯一区别在于其中一个具有 `ref` 参数，而另一个具有 `out` 或 `in` 参数，则会发生编译器错误。 例如，以下代码将不会编译。

```csharp
class CS0663_Example
{
    // Compiler error CS0663: "Cannot define overloaded 
    // methods that differ only on ref and out".
    public void SampleMethod(out int i) { }
    public void SampleMethod(ref int i) { }
}
```

但是，当一个方法具有 `ref`、`in` 或 `out` 参数，另一个方法具有值参数时，则可以重载方法，如下面的示例所示。

```csharp
class RefOverloadExample
{
    public void SampleMethod(int i) { }
    public void SampleMethod(ref int i) { }
}
```

在其他要求签名匹配的情况下（如隐藏或重写），`in`、`ref` 和 `out` 是签名的一部分，相互之间不匹配。

属性不是变量。 它们是方法，不能传递到 `ref` 参数。

不能将 `ref`、`in` 和 `out` 关键字用于以下几种方法：

- 异步方法，通过使用 [async](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/async) 修饰符定义。
- 迭代器方法，包括 [yield return](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/yield) 或 `yield break` 语句。

#### 按引用传递参数：示例

前面的示例按引用传递值类型。 还可使用 `ref` 关键字按引用传递引用类型。 按引用传递引用类型使所调用方能够替换调用方中引用参数引用的对象。 对象的存储位置按引用参数的值传递到方法。 如果更改参数存储位置中的值（以指向新对象），你还可以将存储位置更改为调用方所引用的位置。 下面的示例将引用类型的实例作为 `ref` 参数传递。

```csharp
class Product
{
    public Product(string name, int newID)
    {
        ItemName = name;
        ItemID = newID;
    }

    public string ItemName { get; set; }
    public int ItemID { get; set; }
}

private static void ChangeByReference(ref Product itemRef)
{
    // Change the address that is stored in the itemRef parameter.   
    itemRef = new Product("Stapler", 99999);

    // You can change the value of one of the properties of
    // itemRef. The change happens to item in Main as well.
    itemRef.ItemID = 12345;
}

private static void ModifyProductsByReference()
{
    // Declare an instance of Product and display its initial values.
    Product item = new Product("Fasteners", 54321);
    System.Console.WriteLine("Original values in Main.  Name: {0}, ID: {1}\n",
        item.ItemName, item.ItemID);

    // Pass the product instance to ChangeByReference.
    ChangeByReference(ref item);
    System.Console.WriteLine("Back in Main.  Name: {0}, ID: {1}\n",
        item.ItemName, item.ItemID);
}

// This method displays the following output:
// Original values in Main.  Name: Fasteners, ID: 54321
// Back in Main.  Name: Stapler, ID: 12345        
```

有关如何通过值和引用传递引用类型的详细信息，请参阅[传递引用类型参数](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/passing-reference-type-parameters)。

#### 引用返回值

引用返回值（或 ref 返回值）是由方法按引用向调用方返回的值。 即是说，调用方可以修改方法所返回的值，此更改反映在包含方法的对象的状态中。

使用 `ref` 关键字来定义引用返回值：

- 在方法签名中。 例如，下列方法签名指示 `GetCurrentPrice` 方法按引用返回了 [Decimal](https://docs.microsoft.com/zh-cn/dotnet/api/system.decimal) 值。

```csharp
public ref decimal GetCurrentPrice()
```

- 在 `return` 标记和方法的 `return` 语句中返回的变量之间。 例如:

```csharp
return ref DecimalArray[0];
```

为方便调用方修改对象的状态，引用返回值必须存储在被显式定义为 [ref 局部变量](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ref#ref-locals)的变量中。

所调用方法还可能会将返回值声明为 `ref readonly` 以按引用返回值，并坚持调用代码无法修改返回的值。 调用方法可以通过将返回的值存储在本地 [ref readonly](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ref#ref-readonly-locals) 变量中来避免复制该值。

有关示例，请参阅 [ref 返回值和 ref 局部变量示例](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ref#a-ref-returns-and-ref-locals-example)。

#### ref 局部变量

ref 局部变量用于指代使用 `return ref` 返回的值。 无法将 ref 局部变量初始化为非 ref 返回值。 也就是说，初始化的右侧必须为引用。 任何对 ref 本地变量值的修改都将反映在对象的状态中，该对象的方法按引用返回值。

在变量声明前或在方法（该方法将按引用返回值）调用前使用 `ref` 关键字定义 ref 局部变量。

例如，下列语句定义名为 `GetEstimatedValue` 的方法返回的 ref 局部变量值：

```csharp
ref decimal estValue = ref Building.GetEstimatedValue();
```

可通过相同方式按引用访问值。 在某些情况下，按引用访问值可避免潜在的高开销复制操作，从而提高性能。例如，以下语句显示用户可如何定义一个用于引用值的 ref 局部变量值。

```csharp
ref VeryLargeStruct reflocal = ref veryLargeStruct;
```

请注意，在这两个示例中，必须在两个位置同时使用 `ref` 关键字，否则编译器将生成错误 CS8172：“无法使用值对按引用变量进行初始化”。

从 C# 7.3 开始，`foreach` 语句的迭代变量可以是 ref local 变量，也可以是 ref readonly local 变量。 有关详细信息，请参阅 [foreach 语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/foreach-in)一文。

#### Ref readonly 局部变量

Ref readonly 局部变量用于指代在其签名中具有 `ref readonly` 并使用 `return ref` 的方法或属性返回的值。 `ref readonly` 变量将 `ref` 本地变量的属性与 `readonly` 变量结合使用：它是所分配到的存储的别名，且无法修改。

#### ref 返回值和 ref 局部变量示例

下列示例定义一个具有两个 [String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string) 字段（`Title` 和 `Author`）的 `Book` 类。 还定义包含 `Book` 对象的专用数组的 `BookCollection` 类。 通过调用 `GetBookByTitle` 方法，可按引用返回个别 book 对象。

```csharp
public class Book
{
    public string Author;
    public string Title;
}

public class BookCollection
{
    private Book[] books = { new Book { Title = "Call of the Wild, The", Author = "Jack London" },
                        new Book { Title = "Tale of Two Cities, A", Author = "Charles Dickens" }
                       };
    private Book nobook = null;

    public ref Book GetBookByTitle(string title)
    {
        for (int ctr = 0; ctr < books.Length; ctr++)
        {
            if (title == books[ctr].Title)
                return ref books[ctr];
        }
        return ref nobook;
    }

    public void ListBooks()
    {
        foreach (var book in books)
        {
            Console.WriteLine($"{book.Title}, by {book.Author}");
        }
        Console.WriteLine();
    }
}
```

调用方将 `GetBookByTitle` 方法所返回的值存储为 ref 局部变量时，调用方对返回值所做的更改将反映在 `BookCollection` 对象中，如下例所示。

C#复制

```csharp
var bc = new BookCollection();
bc.ListBooks();

ref var book = ref bc.GetBookByTitle("Call of the Wild, The");
if (book != null)
    book = new Book { Title = "Republic, The", Author = "Plato" };
bc.ListBooks();
// The example displays the following output:
//       Call of the Wild, The, by Jack London
//       Tale of Two Cities, A, by Charles Dickens
//       
//       Republic, The, by Plato
//       Tale of Two Cities, A, by Charles Dickens
```

#### Ref 结构类型

将 `ref` 修饰符添加到 `struct` 声明定义了该类型的实例必须为堆栈分配。 换言之，永远不能在作为另一类的成员的堆上创建这些类型的实例。 此功能的主要动机是 [Span](https://docs.microsoft.com/zh-cn/dotnet/api/system.span-1) 和相关结构。

保持 `ref struct` 类型作为堆栈分配的变量的目标引入了几条编译器针对所有 `ref struct` 类型强制执行的规则。

- 不能对 `ref struct` 装箱。 无法向属于 `object`、`dynamic` 或任何接口类型的变量分配 `ref struct` 类型。
- `ref struct` 类型不能实现接口。
- 不能将 `ref struct` 声明为类或常规结构的成员。
- 不能声明异步方法中属于 `ref struct` 类型的本地变量。 不能在返回类似 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task)、[Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1) 或 `Task`类型的同步方法中声明它们。
- 无法在迭代器中声明 `ref struct` 本地变量。
- 无法捕获 Lambda 表达式或本地函数中的 `ref struct` 变量。

这些限制可确保不会以可提升至托管堆的方式意外地使用 `ref struct`。

可以组合修饰符以将结构声明为 `readonly ref`。 `readonly ref struct` 兼具 `ref struct` 和 `readonly struct`声明的优点和限制。

## [out (Parameter Modifier)](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/out-parameter-modifier)

`out` 关键字通过引用传递参数。 它与 [ref](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ref) 关键字相似，只不过 `ref` 要求在传递之前初始化变量。 它也类似于[in](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/in-parameter-modifier) 关键字，只不过 `in` 不允许通过调用方法来修改参数值。 若要使用 `out` 参数，方法定义和调用方法均必须显式使用 `out` 关键字。 例如:

```csharp
int initializeInMethod;
OutArgExample(out initializeInMethod);
Console.WriteLine(initializeInMethod);     // value is now 44

void OutArgExample(out int number)
{
    number = 44;
}
```

> `out` 关键字也可与泛型类型参数结合使用，以指定该类型参数是协变参数。 有关在此上下文中使用 `out`关键字的详细信息，请参阅 [out（泛型修饰符）](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/out-generic-modifier)。

作为 `out` 参数传递的变量在方法调用中传递之前不必进行初始化。 但是，被调用的方法需要在返回之前赋一个值。

尽管 `in`、`ref` 和 `out` 关键字会导致不同的运行时行为，它们并不被视为编译时方法签名的一部分。 因此，如果唯一的不同是一个方法采用 `ref` 或 `in` 参数，而另一个方法采用 `out` 参数，则无法重载这两个方法。 例如，以下代码将不会编译：

```csharp
class CS0663_Example
{
    // Compiler error CS0663: "Cannot define overloaded 
    // methods that differ only on ref and out".
    public void SampleMethod(out int i) { }
    public void SampleMethod(ref int i) { }
}
```

但是，如果一个方法采用 `ref`、`in` 或 `out` 参数，而另一个方法采用其他参数，则可以完成重载，如：

```csharp
class OutOverloadExample
{
    public void SampleMethod(int i) { }
    public void SampleMethod(out int i) => i = 5;
}
```

编译器通过将调用站点上的参数修饰符与方法调用中使用的参数修饰符进行匹配，从而选择最佳重载。

属性不是变量，因此不能作为 `out` 参数传递。

不能将 `in`、`ref` 和 `out` 关键字用于以下几种方法：

- 异步方法，通过使用 [async](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/async) 修饰符定义。
- 迭代器方法，包括 [yield return](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/yield) 或 `yield break` 语句。

#### 声明 `out` 参数

如果希望方法返回多个值，可以声明具有多个 `out` 参数的方法。 下面的示例使用 `out` 返回具有单个方法调用的三个变量。 注意，第三个参数赋 null 值。 这使得方法可以有选择地返回值。

```csharp
void Method(out int answer, out string message, out string stillNull)
{
    answer = 44;
    message = "I've been returned";
    stillNull = null;
}

int argNumber;
string argMessage, argDefault;
Method(out argNumber, out argMessage, out argDefault);
Console.WriteLine(argNumber);
Console.WriteLine(argMessage);
Console.WriteLine(argDefault == null);

// The example displays the following output:
//      44
//      I've been returned
//      True
```

[重试模式](https://docs.microsoft.com/zh-cn/visualstudio/code-quality/ca1021-avoid-out-parameters#try-pattern-methods)会返回一个 `bool`，指示某个操作是成功还是失败，并在 `out` 参数中返回该操作生成的值。 许多分析方法（如 [DateTime.TryParse](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime.tryparse#System_DateTime_TryParse_System_String_System_DateTime__) 方法）都采用此模式。

#### 调用具有 `out` 参数的方法

在 C# 6 及更早版本中，必须先在单独的语句中声明变量，然后才能将其作为 `out` 参数传递。 下面的示例先声明了变量 `number`，然后再将它传递给将字符串转换为数字的 [Int32.TryParse](https://docs.microsoft.com/zh-cn/dotnet/api/system.int32.tryparse#System_Int32_TryParse_System_String_System_Int32__) 方法。

```csharp
string numberAsString = "1640";

int number;
if (Int32.TryParse(numberAsString, out number))
    Console.WriteLine($"Converted '{numberAsString}' to {number}");
else
    Console.WriteLine($"Unable to convert '{numberAsString}'");
// The example displays the following output:
//       Converted '1640' to 1640
```

从 C# 7.0 开始，可以在方法调用的参数列表而不是单独的变量声明中声明 `out` 变量。 这使得代码更简洁可读，还能防止在方法调用之前无意中向该变量赋值。 下面的示例与上一个示例基本相同，不同之处在于它在对 [Int32.TryParse](https://docs.microsoft.com/zh-cn/dotnet/api/system.int32.tryparse#System_Int32_TryParse_System_String_System_Int32__) 方法的调用中定义了 `number` 变量。

```csharp
string numberAsString = "1640";

if (Int32.TryParse(numberAsString, out int number))
    Console.WriteLine($"Converted '{numberAsString}' to {number}");
else
    Console.WriteLine($"Unable to convert '{numberAsString}'");
// The example displays the following output:
//       Converted '1640' to 1640
```

在上一个示例中，`number` 变量被强类型化为 `int`。 你也可以声明一个隐式类型本地变量，如以下示例所示。

```csharp
string numberAsString = "1640";

if (Int32.TryParse(numberAsString, out var number))
    Console.WriteLine($"Converted '{numberAsString}' to {number}");
else
    Console.WriteLine($"Unable to convert '{numberAsString}'");
// The example displays the following output:
//       Converted '1640' to 1640
```