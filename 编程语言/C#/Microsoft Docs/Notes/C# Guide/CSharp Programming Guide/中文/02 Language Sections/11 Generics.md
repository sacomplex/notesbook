[C# programming guide](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/index)

# Language Sections

## [Generics](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/generics/index)

C# 语言和公共语言运行时 (CLR) 的 2.0 版本中添加了泛型。 泛型将类型参数的概念引入 .NET Framework，这样就可以设计具有以下特征的类和方法：在客户端代码声明并初始化这些类和方法之前，这些类和方法会延迟指定一个或多个类型。 例如，通过使用泛型类型参数 T，可以编写其他客户端代码能够使用的单个类，而不会产生运行时转换或装箱操作的成本或风险，如下所示：

```csharp
// Declare the generic class.
public class GenericList<T>
{
    public void Add(T input) { }
}
class TestGenericList
{
    private class ExampleClass { }
    static void Main()
    {
        // Declare a list of type int.
        GenericList<int> list1 = new GenericList<int>();
        list1.Add(1);

        // Declare a list of type string.
        GenericList<string> list2 = new GenericList<string>();
        list2.Add("");

        // Declare a list of type ExampleClass.
        GenericList<ExampleClass> list3 = new GenericList<ExampleClass>();
        list3.Add(new ExampleClass());
    }
}
```

### 泛型概述

- 使用泛型类型可以最大限度地重用代码、保护类型安全性以及提高性能。
- 泛型最常见的用途是创建集合类。
- .NET Framework 类库在 [System.Collections.Generic](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic) 命名空间中包含几个新的泛型集合类。 应尽可能使用这些类来代替某些类，如 [System.Collections](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections) 命名空间中的 [ArrayList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.arraylist)。
- 可以创建自己的泛型接口、泛型类、泛型方法、泛型事件和泛型委托。
- 可以对泛型类进行约束以访问特定数据类型的方法。
- 在泛型数据类型中所用类型的信息可在运行时通过使用反射来获取。

### [Introduction to Generics](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/generics/introduction-to-generics)

泛型类和泛型方法兼具可重用性、类型安全性和效率，这是非泛型类和非泛型方法无法实现的。 泛型通常与集合以及作用于集合的方法一起使用。 .NET Framework 2.0 版类库提供新的命名空间 [System.Collections.Generic](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic)，其中包含几个新的基于泛型的集合类。 建议所有定目标到 .NET Framework 2.0 及更高版本的应用程序都使用新增的泛型集合类，而不是旧的非泛型集合类（如 [ArrayList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.arraylist)）。 有关详细信息，请参阅 [.NET 中的泛型](https://docs.microsoft.com/zh-cn/dotnet/standard/generics/index)。

当然，也可以创建自定义泛型类型和泛型方法，以提供自己的通用解决方案，设计类型安全的高效模式。 以下代码示例演示了出于演示目的的简单泛型链接列表类。 （大多数情况下，应使用 .NET Framework 类库提供的 [List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1) 类，而不是自行创建类。）在通常使用具体类型来指示列表中所存储项的类型的情况下，可使用类型参数 `T`。 其使用方法如下：

- 在 `AddHead` 方法中作为方法参数的类型。
- 在 `Node` 嵌套类中作为 `Data` 属性的返回类型。
- 在嵌套类中作为私有成员 `data` 的类型。

请注意，T 可用于 `Node` 嵌套类。 如果使用具体类型实例化 `GenericList<T>`（例如，作为 `GenericList<int>`），则出现的所有 `T` 都将替换为 `int`。

```csharp
// type parameter T in angle brackets
public class GenericList<T> 
{
    // The nested class is also generic on T.
    private class Node
    {
        // T used in non-generic constructor.
        public Node(T t)
        {
            next = null;
            data = t;
        }

        private Node next;
        public Node Next
        {
            get { return next; }
            set { next = value; }
        }
        
        // T as private member data type.
        private T data;

        // T as return type of property.
        public T Data  
        {
            get { return data; }
            set { data = value; }
        }
    }

    private Node head;
    
    // constructor
    public GenericList() 
    {
        head = null;
    }

    // T as method parameter type:
    public void AddHead(T t) 
    {
        Node n = new Node(t);
        n.Next = head;
        head = n;
    }

    public IEnumerator<T> GetEnumerator()
    {
        Node current = head;

        while (current != null)
        {
            yield return current.Data;
            current = current.Next;
        }
    }
}
```

以下代码示例演示了客户端代码如何使用泛型 `GenericList<T>` 类来创建整数列表。 只需更改类型参数，即可轻松修改以下代码，创建字符串或任何其他自定义类型的列表：

```csharp
class TestGenericList
{
    static void Main()
    {
        // int is the type argument
        GenericList<int> list = new GenericList<int>();

        for (int x = 0; x < 10; x++)
        {
            list.AddHead(x);
        }

        foreach (int i in list)
        {
            System.Console.Write(i + " ");
        }
        System.Console.WriteLine("\nDone");
    }
}
```

### [Benefits of Generics](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/generics/benefits-of-generics)

公共语言运行时和 C# 语言早期版本中存在一个局限，其中通过将类型与通用基类型 [Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object) 相互强制完成泛化，泛型提供了此局限的解决方案。 通过创建泛型类，可在编译时创建类型安全的集合。

通过编写一个使用 .NET 类库中 [ArrayList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.arraylist) 集合类的小程序，可体现出使用非泛型集合类的局限。 [ArrayList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.arraylist) 类的实例可以存储任何引用或值类型。

```csharp
// The .NET Framework 1.1 way to create a list:
System.Collections.ArrayList list1 = new System.Collections.ArrayList();
list1.Add(3);
list1.Add(105);

System.Collections.ArrayList list2 = new System.Collections.ArrayList();
list2.Add("It is raining in Redmond.");
list2.Add("It is snowing in the mountains.");
```

但这种便利有一定代价。 添加到 [ArrayList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.arraylist) 的任何引用或值类型均隐式向上转换为 [Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object)。 如果项为值类型，将它们添加到列表时必须将其装箱，检索它们时必须取消装箱。 转换与装箱/取消装箱这两种操作都会降低性能；在必须循环访问大型集合的方案中，装箱与取消装箱的影响非常大。

另一局限是缺少编译时类型检查；由于 [ArrayList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.arraylist) 将所有内容都转换为 [Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object)，因此在编译时无法阻止客户端代码执行如下操作：

```csharp
System.Collections.ArrayList list = new System.Collections.ArrayList();
// Add an integer to the list.
list.Add(3);
// Add a string to the list. This will compile, but may cause an error later.
list.Add("It is raining in Redmond.");

int t = 0;
// This causes an InvalidCastException to be returned.
foreach (int x in list)
{
    t += x;
}
```

虽然在创建异类集合时这完全可以接受，甚至有时是有意为之，但将字符串和 `ints` 合并到单个 [ArrayList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.arraylist) 中更有可能属于编程错误，且此错误在运行时之前不会被检测出。

在 C# 语言 1.0 和 1.1 版中，仅可通过编写自己的类型特定集合来避免 .NET Framework 基类库集合类中出现泛化代码的风险。 当然，由于这样的类不能重复用于多个数据类型，因此你并不具有泛化的优势，且必须为要存储的每个类型重写类。

[ArrayList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.arraylist) 以及其他相似的类真正需要的是一种方式，这种方式使客户端代码基于每个实例指定打算使用的特定数据类型。 这会省去向上转换为 [Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object) 的必要，并且使编译器可能执行类型检查。 换而言之，[ArrayList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.arraylist) 需要一个类型参数。 那正是泛型所提供的内容。 在泛型 [List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1) 集合中，在 [System.Collections.Generic](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic) 命名空间中，向集合添加项的操作类似于如下所示：

```csharp
// The .NET Framework 2.0 way to create a list
List<int> list1 = new List<int>();

// No boxing, no casting:
list1.Add(3);

// Compile-time error:
// list1.Add("It is raining in Redmond.");
```

对于客户端代码，与 [ArrayList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.arraylist) 相比，[List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1) 添加的唯一语法是声明和实例化中的类型参数。 虽然编码略为复杂，但与 [ArrayList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.arraylist) 相比，你创建的列表不仅更加安全，而且创建速度大为提高，尤其是在列表项为值类型时。

### [Generic Type Parameters](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/generics/generic-type-parameters)

在泛型类型或方法定义中，类型参数是在其实例化泛型类型的一个变量时，客户端指定的特定类型的占位符。 泛型类（例如[泛型介绍](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/generics/introduction-to-generics)中列出的 `GenericList<T>`）无法按原样使用，因为它不是真正的类型；它更像是类型的蓝图。 若要使用 `GenericList<T>`，客户端代码必须通过指定尖括号内的类型参数来声明并实例化构造类型。 此特定类的类型参数可以是编译器可识别的任何类型。 可创建任意数量的构造类型实例，其中每个使用不同的类型参数，如下所示：

```csharp
GenericList<float> list1 = new GenericList<float>();
GenericList<ExampleClass> list2 = new GenericList<ExampleClass>();
GenericList<ExampleStruct> list3 = new GenericList<ExampleStruct>();
```

在 `GenericList<T>` 的每个实例中，类中出现的每个 `T` 在运行时均会被替换为类型参数。 通过这种替换，我们已通过使用单个类定义创建了三个单独的类型安全的有效对象。 有关 CLR 如何执行此替换的详细信息，请参阅[运行时中的泛型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/generics/generics-in-the-run-time)。

#### 类型参数命名指南

- 请使用描述性名称命名泛型类型参数，除非单个字母名称完全具有自我说明性且描述性名称不会增加任何作用。

  ```csharp
  public interface ISessionChannel<TSession> { /*...*/ }
  public delegate TOutput Converter<TInput, TOutput>(TInput from);
  public class List<T> { /*...*/ }
  ```

- 对具有单个字母类型参数的类型，考虑使用 T 作为类型参数名称。

  ```csharp
  public int IComparer<T>() { return 0; }
  public delegate bool Predicate<T>(T item);
  public struct Nullable<T> where T : struct { /*...*/ }
  ```

- 在类型参数描述性名称前添加前缀 "T"。

  ```csharp
  public interface ISessionChannel<TSession>
  {
      TSession Session { get; }
  }
  ```

- 请考虑在参数名称中指示出类型参数的约束。 例如，约束为 `ISession` 的参数可命名为 `TSession`。

### [Constraints on Type Parameters](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/generics/constraints-on-type-parameters)

约束告知编译器类型参数必须具备的功能。 在没有任何约束的情况下，类型参数可以是任何类型。 编译器只能假定 [Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object) 的成员，它是任何 .NET 类型的最终基类。 有关详细信息，请参阅[使用约束的原因](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/generics/constraints-on-type-parameters#why-use-constraints)。 如果客户端代码尝试使用约束所不允许的类型来实例化类，则会产生编译时错误。 通过使用 `where` 上下文关键字指定约束。 下表列出了七种类型的约束：

| 约束                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| `where T : struct`     | 类型参数必须是值类型。 可以指定除 [Nullable](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullable-1) 以外的任何值类型。 有关可以为 null 的类型的详细信息，请参阅[可以为 null 的类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/nullable-types/index)。 |
| `where T : class`      | 类型参数必须是引用类型。 此约束还应用于任何类、接口、委托或数组类型。 |
| `where T : unmanaged`  | 类型参数不能是引用类型，并且任何嵌套级别均不能包含任何引用类型成员。 |
| `where T : new()`      | 类型参数必须具有公共无参数构造函数。 与其他约束一起使用时，`new()` 约束必须最后指定。 |
| `where T :` <基类名>   | 类型参数必须是指定的基类或派生自指定的基类。                 |
| `where T :` <接口名称> | 类型参数必须是指定的接口或实现指定的接口。 可指定多个接口约束。 约束接口也可以是泛型。 |
| `where T : U`          | 为 T 提供的类型参数必须是为 U 提供的参数或派生自为 U 提供的参数。 |

某些约束是互斥的。 所有值类型必须具有可访问的无参数构造函数。 `struct` 约束包含 `new()` 约束，且 `new()`约束不能与 `struct` 约束结合使用。 `unmanaged` 约束包含 `struct` 约束。 `unmanaged` 约束不能与 `struct` 或 `new()` 约束结合使用。

#### 使用约束的原因

通过约束类型参数，可以增加约束类型及其继承层次结构中的所有类型所支持的允许操作和方法调用的数量。 设计泛型类或方法时，如果要对泛型成员执行除简单赋值之外的任何操作或调用 [System.Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object) 不支持的任何方法，则必须对该类型参数应用约束。 例如，基类约束告诉编译器，仅此类型的对象或派生自此类型的对象可用作类型参数。 编译器有了此保证后，就能够允许在泛型类中调用该类型的方法。 以下代码示例演示可通过应用基类约束添加到（[泛型介绍](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/generics/introduction-to-generics)中的）`GenericList<T>` 类的功能。

```csharp
public class Employee
{
    public Employee(string s, int i) => (Name, ID) = (s, i);
    public string Name { get; set; }
    public int ID { get; set; }
}

public class GenericList<T> where T : Employee
{
    private class Node
    {
        public Node(T t) => (Next, Data) = (null, t);

        public Node Next { get; set; }
        public T Data { get; set; }
    }

    private Node head;

    public void AddHead(T t)
    {
        Node n = new Node(t) { Next = head };
        head = n;
    }

    public IEnumerator<T> GetEnumerator()
    {
        Node current = head;

        while (current != null)
        {
            yield return current.Data;
            current = current.Next;
        }
    }

    public T FindFirstOccurrence(string s)
    {
        Node current = head;
        T t = null;

        while (current != null)
        {
            //The constraint enables access to the Name property.
            if (current.Data.Name == s)
            {
                t = current.Data;
                break;
            }
            else
            {
                current = current.Next;
            }
        }
        return t;
    }
}
```

约束使泛型类能够使用 `Employee.Name` 属性。 约束指定类型 `T` 的所有项都保证是 `Employee` 对象或从 `Employee` 继承的对象。

可以对同一类型参数应用多个约束，并且约束自身可以是泛型类型，如下所示：

```csharp
class EmployeeList<T> where T : Employee, IEmployee, System.IComparable<T>, new()
{
    // ...
}
```

在应用 `where T : class` 约束时，请避免对类型参数使用 `==` 和 `!=` 运算符，因为这些运算符仅测试引用标识而不测试值相等性。 即使在用作参数的类型中重载这些运算符也会发生此行为。 下面的代码说明了这一点；即使 [String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string) 类重载 `==` 运算符，输出也为 false。

```csharp
public static void OpEqualsTest<T>(T s, T t) where T : class
{
    System.Console.WriteLine(s == t);
}
private static void TestStringEquality()
{
    string s1 = "target";
    System.Text.StringBuilder sb = new System.Text.StringBuilder("target");
    string s2 = sb.ToString();
    OpEqualsTest<string>(s1, s2);
}
```

编译器只知道 T 在编译时是引用类型，并且必须使用对所有引用类型都有效的默认运算符。 如果必须测试值相等性，建议同时应用 `where T : IEquatable<T>` 或 `where T : IComparable<T>` 约束，并在用于构造泛型类的任何类中实现该接口。

#### 约束多个参数

可以对多个参数应用多个约束，对一个参数应用多个约束，如下例所示：

```csharp
class Base { }
class Test<T, U>
    where U : struct
    where T : Base, new()
{ }
```

#### 未绑定的类型参数

没有约束的类型参数（如公共类 `SampleClass<T>{}` 中的 T）称为未绑定的类型参数。 未绑定的类型参数具有以下规则：

- 不能使用 `!=` 和 `==` 运算符，因为无法保证具体的类型参数能支持这些运算符。
- 可以在它们与 `System.Object` 之间来回转换，或将它们显式转换为任何接口类型。
- 可以将它们与 [null](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/null) 进行比较。 将未绑定的参数与 `null` 进行比较时，如果类型参数为值类型，则该比较将始终返回 false。

#### 类型参数作为约束

在具有自己类型参数的成员函数必须将该参数约束为包含类型的类型参数时，将泛型类型参数用作约束非常有用，如下例所示：

```csharp
public class List<T>
{
    public void Add<U>(List<U> items) where U : T {/*...*/}
}
```

在上述示例中，`T` 在 `Add` 方法的上下文中是一个类型约束，而在 `List` 类的上下文中是一个未绑定的类型参数。

类型参数还可在泛型类定义中用作约束。 必须在尖括号中声明该类型参数以及任何其他类型参数：

```csharp
//Type parameter V is used as a type constraint.
public class SampleClass<T, U, V> where T : V { }
```

类型参数作为泛型类的约束的作用非常有限，因为编译器除了假设类型参数派生自 `System.Object` 以外，不会做其他任何假设。 如果要在两个类型参数之间强制继承关系，可以将类型参数用作泛型类的约束。

#### 非托管约束

从 C# 7.3 开始，可使用 `unmanaged` 约束来指定类型参数必须为“非托管类型”。 “非托管类型”不是引用类型，且任何嵌套级别都不包含引用类型字段。 通过 `unmanaged` 约束，用户能编写可重用例程，从而使用可作为内存块操作的类型，如以下示例所示：

```csharp
unsafe public static byte[] ToByteArray<T>(this T argument) where T : unmanaged
{
    var size = sizeof(T);
    var result = new Byte[size];
    Byte* p = (byte*)&argument;
    for (var i = 0; i < size; i++)
        result[i] = *p++;
    return result;
}
```

以上方法必须在 `unsafe` 上下文中编译，因为它并不是在已知的内置类型上使用 `sizeof` 运算符。 如果没有 `unmanaged` 约束，则 `sizeof` 运算符不可用。

#### 委托约束

同样从 C# 7.3 开始，可将 [System.Delegate](https://docs.microsoft.com/zh-cn/dotnet/api/system.delegate) 或 [System.MulticastDelegate](https://docs.microsoft.com/zh-cn/dotnet/api/system.multicastdelegate) 用作基类约束。 CLR 始终允许此约束，但 C# 语言不允许。 使用 `System.Delegate` 约束，用户能够以类型安全的方式编写使用委托的代码。 以下代码定义了合并两个同类型委托的扩展方法：

```csharp
public static TDelegate TypeSafeCombine<TDelegate>(this TDelegate source, TDelegate target)
    where TDelegate : System.Delegate
    => Delegate.Combine(source, target) as TDelegate;
```

可使用上述方法来合并相同类型的委托：

```csharp
Action first = () => Console.WriteLine("this");
Action second = () => Console.WriteLine("that");

var combined = first.TypeSafeCombine(second);
combined();

Func<bool> test = () => true;
// Combine signature ensures combined delegates must
// have the same type.
//var badCombined = first.TypeSafeCombine(test);
```

如果取消评论最后一行，它将不会编译。 `first` 和 `test` 均为委托类型，但它们是不同的委托类型。

#### 枚举约束

从 C# 7.3 开始，还可指定 [System.Enum](https://docs.microsoft.com/zh-cn/dotnet/api/system.enum) 类型作为基类约束。 CLR 始终允许此约束，但 C# 语言不允许。 使用 `System.Enum` 的泛型提供类型安全的编程，缓存使用 `System.Enum` 中静态方法的结果。 以下示例查找枚举类型的所有有效的值，然后生成将这些值映射到其字符串表示形式的字典。

```csharp
public static Dictionary<int, string> EnumNamedValues<T>() where T : System.Enum
{
    var result = new Dictionary<int, string>();
    var values = Enum.GetValues(typeof(T));

    foreach (int item in values)
        result.Add(item, Enum.GetName(typeof(T), item));
    return result;
}
```

所用方法利用反射，这会对性能产生影响。 可调用此方法来生成可缓存和重用的集合，而不是重复需要反射才能实施的调用。

如以下示例所示，可使用它来创建枚举并生成其值和名称的字典：

```csharp
enum Rainbow
{
    Red,
    Orange,
    Yellow,
    Green,
    Blue,
    Indigo,
    Violet
}
```

```csharp
var map = EnumNamedValues<Rainbow>();

foreach (var pair in map)
    Console.WriteLine($"{pair.Key}:\t{pair.Value}");
```

### [Generic Classes](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/generics/generic-classes)

泛型类封装不特定于特定数据类型的操作。 泛型类最常见用法是用于链接列表、哈希表、堆栈、队列和树等集合。 无论存储数据的类型如何，添加项和从集合删除项等操作的执行方式基本相同。

对于大多数需要集合类的方案，推荐做法是使用 .NET 类库中提供的集合类。 有关使用这些类的详细信息，请参阅 [.NET 中的泛型集合](https://docs.microsoft.com/zh-cn/dotnet/standard/generics/collections)。

通常，创建泛型类是从现有具体类开始，然后每次逐个将类型更改为类型参数，直到泛化和可用性达到最佳平衡。创建自己的泛型类时，需要考虑以下重要注意事项：

- 要将哪些类型泛化为类型参数。

  通常，可参数化的类型越多，代码就越灵活、其可重用性就越高。 但过度泛化会造成其他开发人员难以阅读或理解代码。

- 要将何种约束（如有）应用到类型参数（请参阅[类型参数的约束](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/generics/constraints-on-type-parameters)）。

  其中一个有用的规则是，应用最大程度的约束，同时仍可处理必须处理的类型。 例如，如果知道泛型类仅用于引用类型，则请应用类约束。 这可防止将类意外用于值类型，并使你可在 `T` 上使用 `as` 运算符和检查 null 值。

- 是否将泛型行为分解为基类和子类。

  因为泛型类可用作基类，所以非泛型类的相同设计注意事项在此也适用。 请参阅本主题后文有关从泛型基类继承的规则。

- 实现一个泛型接口还是多个泛型接口。

  例如，如果要设计用于在基于泛型的集合中创建项的类，则可能必须实现一个接口，例如 [IComparable](https://docs.microsoft.com/zh-cn/dotnet/api/system.icomparable-1)，其中 `T` 为类的类型。

有关简单泛型类的示例，请参阅[泛型介绍](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/generics/introduction-to-generics)。

类型参数和约束的规则对于泛型类行为具有多种含义，尤其是在继承性和成员可访问性方面。 应当了解一些术语，然后再继续。 对于泛型类 `Node<T>,`客户端代码可通过指定类型参数来引用类，创建封闭式构造类型 (`Node<int>`)。 或者，可以不指定类型参数（例如指定泛型基类时），创建开放式构造类型 (`Node<T>`)。 泛型类可继承自具体的封闭式构造或开放式构造基类：

```csharp
class BaseNode { }
class BaseNodeGeneric<T> { }

// concrete type
class NodeConcrete<T> : BaseNode { }

//closed constructed type
class NodeClosed<T> : BaseNodeGeneric<int> { }

//open constructed type 
class NodeOpen<T> : BaseNodeGeneric<T> { }
```

非泛型类（即，具体类）可继承自封闭式构造基类，但不可继承自开放式构造类或类型参数，因为运行时客户端代码无法提供实例化基类所需的类型参数。

```csharp
//No error
class Node1 : BaseNodeGeneric<int> { }

//Generates an error
//class Node2 : BaseNodeGeneric<T> {}

//Generates an error
//class Node3 : T {}
```

继承自开放式构造类型的泛型类必须对非此继承类共享的任何基类类型参数提供类型参数，如下方代码所示：

```csharp
class BaseNodeMultiple<T, U> { }

//No error
class Node4<T> : BaseNodeMultiple<T, int> { }

//No error
class Node5<T, U> : BaseNodeMultiple<T, U> { }

//Generates an error
//class Node6<T> : BaseNodeMultiple<T, U> {} 
```

继承自开放式构造类型的泛型类必须指定作为基类型上约束超集或表示这些约束的约束：

```csharp
class NodeItem<T> where T : System.IComparable<T>, new() { }
class SpecialNodeItem<T> : NodeItem<T> where T : System.IComparable<T>, new() { }
```

泛型类型可使用多个类型参数和约束，如下所示：

```csharp
class SuperKeyType<K, V, U>
    where U : System.IComparable<U>
    where V : new()
{ }
```

开放式构造和封闭式构造类型可用作方法参数：

```csharp
void Swap<T>(List<T> list1, List<T> list2)
{
    //code to swap items
}

void Swap(List<int> list1, List<int> list2)
{
    //code to swap items
}
```

如果一个泛型类实现一个接口，则该类的所有实例均可强制转换为该接口。

泛型类是不变量。 换而言之，如果一个输入参数指定 `List<BaseClass>`，且你尝试提供 `List<DerivedClass>`，则会出现编译时错误。

### [Generic Interfaces](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/generics/generic-interfaces)

为泛型集合类或表示集合中的项的泛型类定义接口通常很有用处。 为避免对值类型的装箱和取消装箱操作，泛型类的首选项使用泛型接口，例如 [IComparable](https://docs.microsoft.com/zh-cn/dotnet/api/system.icomparable-1)而不是 [IComparable](https://docs.microsoft.com/zh-cn/dotnet/api/system.icomparable)。 .NET Framework 类库定义多个泛型接口，以将其用于 [System.Collections.Generic](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic) 命名空间中的集合类。

接口被指定为类型参数上的约束时，仅可使用实现接口的类型。 如下代码示例演示一个派生自 `GenericList<T>` 类的 `SortedList<T>` 类。 有关详细信息，请参阅[泛型介绍](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/generics/introduction-to-generics)。 `SortedList<T>` 添加约束 `where T : IComparable<T>`。这可使 `SortedList<T>` 中的 `BubbleSort` 方法在列表元素上使用泛型 [CompareTo](https://docs.microsoft.com/zh-cn/dotnet/api/system.icomparable-1.compareto) 方法。 在此示例中，列表元素是一个实现 `IComparable<Person>` 的简单类 `Person`。

```csharp
//Type parameter T in angle brackets.
public class GenericList<T> : System.Collections.Generic.IEnumerable<T>
{
    protected Node head;
    protected Node current = null;

    // Nested class is also generic on T
    protected class Node
    {
        public Node next;
        private T data;  //T as private member datatype

        public Node(T t)  //T used in non-generic constructor
        {
            next = null;
            data = t;
        }

        public Node Next
        {
            get { return next; }
            set { next = value; }
        }

        public T Data  //T as return type of property
        {
            get { return data; }
            set { data = value; }
        }
    }

    public GenericList()  //constructor
    {
        head = null;
    }

    public void AddHead(T t)  //T as method parameter type
    {
        Node n = new Node(t);
        n.Next = head;
        head = n;
    }

    // Implementation of the iterator
    public System.Collections.Generic.IEnumerator<T> GetEnumerator()
    {
        Node current = head;
        while (current != null)
        {
            yield return current.Data;
            current = current.Next;
        }
    }

    // IEnumerable<T> inherits from IEnumerable, therefore this class 
    // must implement both the generic and non-generic versions of 
    // GetEnumerator. In most cases, the non-generic method can 
    // simply call the generic method.
    System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
    {
        return GetEnumerator();
    }
}

public class SortedList<T> : GenericList<T> where T : System.IComparable<T>
{
    // A simple, unoptimized sort algorithm that 
    // orders list elements from lowest to highest:

    public void BubbleSort()
    {
        if (null == head || null == head.Next)
        {
            return;
        }
        bool swapped;

        do
        {
            Node previous = null;
            Node current = head;
            swapped = false;

            while (current.next != null)
            {
                //  Because we need to call this method, the SortedList
                //  class is constrained on IEnumerable<T>
                if (current.Data.CompareTo(current.next.Data) > 0)
                {
                    Node tmp = current.next;
                    current.next = current.next.next;
                    tmp.next = current;

                    if (previous == null)
                    {
                        head = tmp;
                    }
                    else
                    {
                        previous.next = tmp;
                    }
                    previous = tmp;
                    swapped = true;
                }
                else
                {
                    previous = current;
                    current = current.next;
                }
            }
        } while (swapped);
    }
}

// A simple class that implements IComparable<T> using itself as the 
// type argument. This is a common design pattern in objects that 
// are stored in generic lists.
public class Person : System.IComparable<Person>
{
    string name;
    int age;

    public Person(string s, int i)
    {
        name = s;
        age = i;
    }

    // This will cause list elements to be sorted on age values.
    public int CompareTo(Person p)
    {
        return age - p.age;
    }

    public override string ToString()
    {
        return name + ":" + age;
    }

    // Must implement Equals.
    public bool Equals(Person p)
    {
        return (this.age == p.age);
    }
}

class Program
{
    static void Main()
    {
        //Declare and instantiate a new generic SortedList class.
        //Person is the type argument.
        SortedList<Person> list = new SortedList<Person>();

        //Create name and age values to initialize Person objects.
        string[] names = new string[] 
        { 
            "Franscoise", 
            "Bill", 
            "Li", 
            "Sandra", 
            "Gunnar", 
            "Alok", 
            "Hiroyuki", 
            "Maria", 
            "Alessandro", 
            "Raul" 
        };

        int[] ages = new int[] { 45, 19, 28, 23, 18, 9, 108, 72, 30, 35 };

        //Populate the list.
        for (int x = 0; x < 10; x++)
        {
            list.AddHead(new Person(names[x], ages[x]));
        }

        //Print out unsorted list.
        foreach (Person p in list)
        {
            System.Console.WriteLine(p.ToString());
        }
        System.Console.WriteLine("Done with unsorted list");

        //Sort the list.
        list.BubbleSort();

        //Print out sorted list.
        foreach (Person p in list)
        {
            System.Console.WriteLine(p.ToString());
        }
        System.Console.WriteLine("Done with sorted list");
    }
}
```

可将多个接口指定为单个类型上的约束，如下所示：

```csharp
class Stack<T> where T : System.IComparable<T>, IEnumerable<T>
{
}
```

一个接口可定义多个类型参数，如下所示：

```csharp
interface IDictionary<K, V>
{
}
```

适用于类的继承规则也适用于接口：

```csharp
interface IMonth<T> { }

interface IJanuary     : IMonth<int> { }  //No error
interface IFebruary<T> : IMonth<int> { }  //No error
interface IMarch<T>    : IMonth<T> { }    //No error
//interface IApril<T>  : IMonth<T, U> {}  //Error
```

泛型接口如为逆变（即，仅使用自身的类型参数作为返回值），则可继承自非泛型接口。 在 .NET Framework 类库中，[IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 继承自 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable)，因为 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 在 [GetEnumerator](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1.getenumerator) 的返回值和 [Current](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerator-1.current) 属性 Getter 中仅使用 `T`。

具体类可实现封闭式构造接口，如下所示：

```csharp
interface IBaseInterface<T> { }

class SampleClass : IBaseInterface<string> { }
```

只要类形参列表提供接口所需的所有实参，泛型类即可实现泛型接口或封闭式构造接口，如下所示：

```csharp
interface IBaseInterface1<T> { }
interface IBaseInterface2<T, U> { }

class SampleClass1<T> : IBaseInterface1<T> { }          //No error
class SampleClass2<T> : IBaseInterface2<T, string> { }  //No error
```

控制方法重载的规则对泛型类、泛型结构或泛型接口内的方法一样。 有关详细信息，请参阅[泛型方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/generics/generic-methods)。

### [Generic Methods](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/generics/generic-methods)

泛型方法是通过类型参数声明的方法，如下所示：

```csharp
static void Swap<T>(ref T lhs, ref T rhs)
{
    T temp;
    temp = lhs;
    lhs = rhs;
    rhs = temp;
}
```

如下示例演示使用类型参数的 `int` 调用方法的一种方式：

```csharp
public static void TestSwap()
{
    int a = 1;
    int b = 2;

    Swap<int>(ref a, ref b);
    System.Console.WriteLine(a + " " + b);
}
```

还可省略类型参数，编译器将推断类型参数。 如下 `Swap` 调用等效于之前的调用：

```csharp
Swap(ref a, ref b);
```

类型推理的相同规则适用于静态方法和实例方法。 编译器可基于传入的方法参数推断类型参数；而无法仅根据约束或返回值推断类型参数。 因此，类型推理不适用于不具有参数的方法。 类型推理发生在编译时，之后编译器尝试解析重载的方法签名。 编译器将类型推理逻辑应用于共用同一名称的所有泛型方法。 在重载解决方案步骤中，编译器仅包含在其上类型推理成功的泛型方法。

在泛型类中，非泛型方法可访问类级别类型参数，如下所示：

```csharp
class SampleClass<T>
{
    void Swap(ref T lhs, ref T rhs) { }
}
```

如果定义一个具有与包含类相同的类型参数的泛型方法，则编译器会生成警告 CS0693，因为在该方法范围内，向内 `T` 提供的参数会隐藏向外 `T` 提供的参数。 如果需要使用类型参数（而不是类实例化时提供的参数）调用泛型类方法所具备的灵活性，请考虑为此方法的类型参数提供另一标识符，如下方示例中 `GenericList2<T>` 所示。

```csharp
class GenericList<T>
{
    // CS0693
    void SampleMethod<T>() { }
}

class GenericList2<T>
{
    //No warning
    void SampleMethod<U>() { }
}
```

使用约束在方法中的类型参数上实现更多专用操作。 此版 `Swap<T>` 现名为 `SwapIfGreater<T>`，仅可用于实现 [IComparable](https://docs.microsoft.com/zh-cn/dotnet/api/system.icomparable-1) 的类型参数。

```csharp
void SwapIfGreater<T>(ref T lhs, ref T rhs) where T : System.IComparable<T>
{
    T temp;
    if (lhs.CompareTo(rhs) > 0)
    {
        temp = lhs;
        lhs = rhs;
        rhs = temp;
    }
}
```

泛型方法可重载在数个泛型参数上。 例如，以下方法可全部位于同一类中：

```csharp
void DoWork() { }
void DoWork<T>() { }
void DoWork<T, U>() { }
```

### [Generics and Arrays](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/generics/generics-and-arrays)

在 C# 2.0 和更高版本中，下限为零的单维数组自动实现 [IList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ilist-1)。 这可使你创建可使用相同代码循环访问数组和其他集合类型的泛型方法。 此技术的主要用处在于读取集合中的数据。 [IList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ilist-1) 接口无法用于添加元素或从数组删除元素。 如果在此上下文中尝试对数组调用 [IList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ilist-1) 方法（例如 [RemoveAt](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ilist-1.removeat)），则会引发异常。

如下代码示例演示具有 [IList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ilist-1) 输入参数的单个泛型方法如何可循环访问列表和数组（此例中为整数数组）。

```csharp
class Program
{
    static void Main()
    {
        int[] arr = { 0, 1, 2, 3, 4 };
        List<int> list = new List<int>();

        for (int x = 5; x < 10; x++)
        {
            list.Add(x);
        }

        ProcessItems<int>(arr);
        ProcessItems<int>(list);
    }

    static void ProcessItems<T>(IList<T> coll)
    {
        // IsReadOnly returns True for the array and False for the List.
        System.Console.WriteLine
            ("IsReadOnly returns {0} for this collection.",
            coll.IsReadOnly);

        // The following statement causes a run-time exception for the 
        // array, but not for the List.
        //coll.RemoveAt(4);

        foreach (T item in coll)
        {
            System.Console.Write(item.ToString() + " ");
        }
        System.Console.WriteLine();
    }
}
```

### [Generic Delegates](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/generics/generic-delegates)

[委托](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/delegate)可以定义它自己的类型参数。 引用泛型委托的代码可以指定类型参数以创建封闭式构造类型，就像实例化泛型类或调用泛型方法一样，如以下示例中所示：

```csharp
public delegate void Del<T>(T item);
public static void Notify(int i) { }

Del<int> m1 = new Del<int>(Notify);
```

C# 2.0 版具有一种称为方法组转换的新功能，适用于具体委托类型和泛型委托类型，使你能够使用此简化语法编写上一行：

```csharp
Del<int> m2 = Notify;
```

在泛型类中定义的委托可以用类方法使用的相同方式来使用泛型类类型参数。

```csharp
class Stack<T>
{
    T[] items;
    int index;

    public delegate void StackDelegate(T[] items);
}
```

引用委托的代码必须指定包含类的类型参数，如下所示：

```csharp
private static void DoWork(float[] items) { }

public static void TestStack()
{
    Stack<float> s = new Stack<float>();
    Stack<float>.StackDelegate d = DoWork;
}
```

根据典型设计模式定义事件时，泛型委托特别有用，因为发件人参数可以为强类型，无需在它和 [Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object) 之间强制转换。

```csharp
delegate void StackEventHandler<T, U>(T sender, U eventArgs);

class Stack<T>
{
    public class StackEventArgs : System.EventArgs { }
    public event StackEventHandler<Stack<T>, StackEventArgs> stackEvent;

    protected virtual void OnStackChanged(StackEventArgs a)
    {
        stackEvent(this, a);
    }
}

class SampleClass
{
    public void HandleStackChange<T>(Stack<T> stack, Stack<T>.StackEventArgs args) { }
}

public static void Test()
{
    Stack<double> s = new Stack<double>();
    SampleClass o = new SampleClass();
    s.stackEvent += o.HandleStackChange;
}
```

### [Differences Between C++ Templates and C# Generics](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/generics/differences-between-cpp-templates-and-csharp-generics)

C# 泛型和 C++ 模板均是支持参数化类型的语言功能。 但是，两者之间存在很多不同。 在语法层次，C# 泛型是参数化类型的一个更简单的方法，而不具有 C++ 模板的复杂性。 此外，C# 不试图提供 C++ 模板所具有的所有功能。 在实现层次，主要区别在于 C# 泛型类型的替换在运行时执行，从而为实例化对象保留了泛型类型信息。 有关详细信息，请参阅[运行时中的泛型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/generics/generics-in-the-run-time)。

以下是 C# 泛型和 C++ 模板之间的主要差异：

- C# 泛型的灵活性与 C++ 模板不同。 例如，虽然可以调用 C# 泛型类中的用户定义的运算符，但是无法调用算术运算符。
- C# 不允许使用非类型模板参数，如 `template C<int i> {}`。
- C# 不支持显式定制化；即特定类型模板的自定义实现。
- C# 不支持部分定制化：部分类型参数的自定义实现。
- C# 不允许将类型参数用作泛型类型的基类。
- C# 不允许类型参数具有默认类型。
- 在 C# 中，泛型类型参数本身不能是泛型，但是构造类型可以用作泛型。 C++ 允许使用模板参数。
- C++ 允许在模板中使用可能并非对所有类型参数有效的代码，随后针对用作类型参数的特定类型检查此代码。 C# 要求类中编写的代码可处理满足约束的任何类型。 例如，在 C++ 中可以编写一个函数，此函数对类型参数的对象使用算术运算符 `+` 和 `-`，在实例化具有不支持这些运算符的类型的模板时，此函数将产生错误。 C# 不允许此操作；唯一允许的语言构造是可以从约束中推断出来的构造。

### [Generics in the Run Time](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/generics/generics-in-the-run-time)

泛型类型或方法编译为 Microsoft 中间语言 (MSIL) 时，它包含将其标识为具有类型参数的元数据。 如何使用泛型类型的 MSIL 根据所提供的类型参数是值类型还是引用类型而有所不同。

使用值类型作为参数首次构造泛型类型时，运行时创建专用的泛型类型，MSIL 内的适当位置替换提供的一个或多个参数。 为每个用作参数的唯一值类型一次创建专用化泛型类型。

例如，假定程序代码声明了一个由整数构造的堆栈：

```csharp
Stack<int> stack;
```

此时，运行时生成一个专用版 [Stack](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.stack-1) 类，其中用整数相应地替换其参数。 现在，每当程序代码使用整数堆栈时，运行时都重新使用已生成的专用 [Stack](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.stack-1) 类。 在下面的示例中创建了两个整数堆栈实例，且它们共用 `Stack<int>` 代码的一个实例：

```csharp
Stack<int> stackOne = new Stack<int>();
Stack<int> stackTwo = new Stack<int>();
```

但是，假定在代码中另一点上再创建一个将不同值类型（例如 `long` 或用户定义结构）作为参数的 [Stack](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.stack-1)类。 其结果是，运行时在 MSIL 中生成另一个版本的泛型类型并在适当位置替换 `long`。 转换已不再必要，因为每个专用化泛型类本机包含值类型。

对于引用类型，泛型的作用方式略有不同。 首次使用任意引用类型构造泛型类型时，运行时创建一个专用化泛型类型，用对象引用替换 MSIL 中的参数。 之后，每次使用引用类型作为参数实例化已构造的类型时，无论何种类型，运行时皆重新使用先前创建的专用版泛型类型。 原因可能在于所有引用大小相同。

例如，假定有两个引用类型、一个 `Customer` 类和一个 `Order` 类，并假定已创建 `Customer` 类型的堆栈：

```csharp
class Customer { }
class Order { }
```

```csharp
Stack<Customer> customers;
```

此时，运行时生成一个专用版 [Stack](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.stack-1) 类，此类存储之后会被填写的引用类型，而不是存储数据。 假定下一行代码创建另一引用类型的堆栈，其名为 `Order`：

```csharp
Stack<Order> orders = new Stack<Order>();
```

不同于值类型，不会为 `Order` 类型创建 [Stack](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.stack-1) 类的另一专用版。 相反，创建专用版 [Stack](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.stack-1) 类的实例并将 `orders` 变量设置为引用此实例。 假定之后遇到一行创建 `Customer` 类型堆栈的代码：

```csharp
customers = new Stack<Customer>();
```

与之前使用通过 `Order` 类型创建的 [Stack](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.stack-1) 类一样，会创建专用 [Stack](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.stack-1) 类的另一个实例。 其中包含的指针设置为引用 `Customer` 类型大小的内存区。 由于引用类型的数量因程序不同而有较大差异，因此通过将编译器为引用类型的泛型类创建的专用类的数量减少至 1，泛型的 C# 实现可极大减少代码量。

此外，使用值类型或引用类型参数实例化泛型 C# 类时，反射可在运行时对其进行查询，且其实际类型和类型参数皆可被确定。

### [Generics and Reflection](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/generics/generics-and-reflection)

因为公共语言运行时 (CLR) 能够在运行时访问泛型类型信息，所以可以使用反射获取关于泛型类型的信息，方法与用于非泛型类型的方法相同。 有关详细信息，请参阅[运行时中的泛型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/generics/generics-in-the-run-time)。

在 .NET Framework 2.0 中，向 [Type](https://docs.microsoft.com/zh-cn/dotnet/api/system.type) 类添加了多个新成员来启用泛型类型的运行时信息。 有关如何使用这些方法和属性的详细信息，请参阅这些类的文档。 [System.Reflection.Emit](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.emit) 命名空间还包含支持泛型的新成员。 请参阅[操作说明：使用反射发出定义泛型类型](https://docs.microsoft.com/zh-cn/dotnet/framework/reflection-and-codedom/how-to-define-a-generic-type-with-reflection-emit)。

有关泛型反射中使用的术语的固定条件列表，请参阅 [IsGenericType](https://docs.microsoft.com/zh-cn/dotnet/api/system.type.isgenerictype) 属性注解。

| System.Type 成员名称                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [IsGenericType](https://docs.microsoft.com/zh-cn/dotnet/api/system.type.isgenerictype) | 如果类型是泛型，则返回 true。                                |
| [GetGenericArguments](https://docs.microsoft.com/zh-cn/dotnet/api/system.type.getgenericarguments) | 返回 `Type` 对象的数组，这些对象表示为构造类型提供的类型实参或泛型类型定义的类型形参。 |
| [GetGenericTypeDefinition](https://docs.microsoft.com/zh-cn/dotnet/api/system.type.getgenerictypedefinition) | 返回当前构造类型的基础泛型类型定义。                         |
| [GetGenericParameterConstraints](https://docs.microsoft.com/zh-cn/dotnet/api/system.type.getgenericparameterconstraints) | 返回表示当前泛型类型参数约束的 `Type` 对象的数组。           |
| [ContainsGenericParameters](https://docs.microsoft.com/zh-cn/dotnet/api/system.type.containsgenericparameters) | 如果类型或任何其封闭类型或方法包含未提供特定类型的类型参数，则返回 true。 |
| [GenericParameterAttributes](https://docs.microsoft.com/zh-cn/dotnet/api/system.type.genericparameterattributes) | 获取描述当前泛型类型参数的特殊约束的 `GenericParameterAttributes` 标志组合。 |
| [GenericParameterPosition](https://docs.microsoft.com/zh-cn/dotnet/api/system.type.genericparameterposition) | 对于表示类型参数的 `Type` 对象，获取类型参数在声明其类型参数的泛型类型定义或泛型方法定义的类型参数列表中的位置。 |
| [IsGenericParameter](https://docs.microsoft.com/zh-cn/dotnet/api/system.type.isgenericparameter) | 获取一个值，该值指示当前 `Type` 是否表示泛型类型或方法定义中的类型参数。 |
| [IsGenericTypeDefinition](https://docs.microsoft.com/zh-cn/dotnet/api/system.type.isgenerictypedefinition) | 获取一个值，该值指示当前 [Type](https://docs.microsoft.com/zh-cn/dotnet/api/system.type) 是否表示可以用来构造其他泛型类型的泛型类型定义。 如果该类型表示泛型类型的定义，则返回 true。 |
| [DeclaringMethod](https://docs.microsoft.com/zh-cn/dotnet/api/system.type.declaringmethod) | 返回定义当前泛型类型参数的泛型方法，如果类型参数未由泛型方法定义，则返回 null。 |
| [MakeGenericType](https://docs.microsoft.com/zh-cn/dotnet/api/system.type.makegenerictype) | 替代由当前泛型类型定义的类型参数组成的类型数组的元素，并返回表示结果构造类型的 [Type](https://docs.microsoft.com/zh-cn/dotnet/api/system.type) 对象。 |

此外，[MethodInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.methodinfo) 类的成员还为泛型方法启用运行时信息。 有关用于反射泛型方法的术语的固定条件列表，请参阅 [IsGenericMethod](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.methodbase.isgenericmethod) 属性注解。

| System.Reflection.MemberInfo 成员名称                        | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [IsGenericMethod](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.methodbase.isgenericmethod) | 如果方法是泛型，则返回 true。                                |
| [GetGenericArguments](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.methodinfo.getgenericarguments) | 返回类型对象的数组，这些对象表示构造泛型方法的类型实参或泛型方法定义的类型形参。 |
| [GetGenericMethodDefinition](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.methodinfo.getgenericmethoddefinition) | 返回当前构造方法的基础泛型方法定义。                         |
| [ContainsGenericParameters](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.methodbase.containsgenericparameters) | 如果方法或任何其封闭类型包含未提供特定类型的任何类型参数，则返回 true。 |
| [IsGenericMethodDefinition](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.methodbase.isgenericmethoddefinition) | 如果当前 [MethodInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.methodinfo) 表示泛型方法的定义，则返回 true。 |
| [MakeGenericMethod](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.methodinfo.makegenericmethod) | 用类型数组的元素替代当前泛型方法定义的类型参数，并返回表示结果构造方法的 [MethodInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.methodinfo) 对象。 |

### [Generics and Attributes](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/generics/generics-and-attributes)

属性可按与非泛型类型相同的方式应用到泛型类型。 有关应用特性的详细信息，请参阅[属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/attributes/index)。

仅允许自定义属性引用开放式泛型类型（即未向其提供任何类型参数的泛型类型）和封闭式构造泛型类型（即向所有类型参数提供参数的泛型类型）。

以下示例使用此自定义属性：

```csharp
class CustomAttribute : System.Attribute
{
    public System.Object info;
}
```

属性可引用开放式泛型类型：

```csharp
public class GenericClass1<T> { }

[CustomAttribute(info = typeof(GenericClass1<>))]
class ClassA { }
```

通过使用适当数量的逗号指定多个类型参数。 在此示例中，`GenericClass2` 具有两个类型参数：

```csharp
public class GenericClass2<T, U> { }

[CustomAttribute(info = typeof(GenericClass2<,>))]
class ClassB { }
```

属性可引用封闭式构造泛型类型：

```csharp
public class GenericClass3<T, U, V> { }

[CustomAttribute(info = typeof(GenericClass3<int, double, string>))]
class ClassC { }
```

引用泛型类型参数的属性会导致编译时错误：

```csharp
//[CustomAttribute(info = typeof(GenericClass3<int, T, string>))]  //Error
class ClassD<T> { }
```

不能从[Attribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.attribute)继承泛型类型：

```csharp
//public class CustomAtt<T> : System.Attribute {}  //Error
```

若要在运行时获取有关泛型类型或类型参数的信息，可使用 [System.Reflection](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection) 方法。 有关详细信息，请参阅[泛型和反射](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/generics/generics-and-reflection)