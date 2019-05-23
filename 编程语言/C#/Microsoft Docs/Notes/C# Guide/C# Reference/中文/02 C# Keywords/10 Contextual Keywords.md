# [Contextual Keywords](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/contextual-keywords)

上下文关键字用于在代码中提供特定含义，但它不是 C# 中的保留字。 本部分介绍下面这些上下文关键字：

| 关键字                                                       | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [add](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/add) | 定义一个自定义事件访问器，客户端代码订阅事件时会调用该访问器。 |
| [async](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/async) | 指示修改后的方法、lambda 表达式或匿名方法是异步的。          |
| [await](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/await) | 挂起异步方法，直到等待的任务完成。                           |
| [动态](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/dynamic) | 定义一个引用类型，实现发生绕过编译时类型检查的操作。         |
| [get](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/get) | 为属性或索引器定义访问器方法。                               |
| [global](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/global) | 指定未以其他方式命名的默认全局命名空间。                     |
| [partial](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/partial-type) | 在整个同一编译单元内定义分部类、结构和接口。                 |
| [remove](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/remove) | 定义一个自定义事件访问器，客户端代码取消订阅事件时会调用该访问器。 |
| [set](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/set) | 为属性或索引器定义访问器方法。                               |
| [值](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/value) | 用于设置访问器和添加或删除事件处理程序。                     |
| [var](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/var) | 使编译器能够确定在方法作用域中声明的变量类型。               |
| [when](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/when) | 指定 `catch` 块的筛选条件或 `switch` 语句的 `case` 标签。    |
| [where](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/where-generic-type-constraint) | 将约束添加到泛型声明。 （另请参阅 [where](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/where-clause)）。 |
| [yield](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/yield) | 在迭代器块中使用，用于向枚举数对象返回值或用于表示迭代结束。 |

C# 3.0 中引入的所有查询关键字也都是上下文相关的。 有关详细信息，请参阅[查询关键字 (LINQ)](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/query-keywords)。

## [add](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/add)

`add` 上下文关键字用于定义一个在客户端代码订阅你的[事件](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/event)时调用的自定义事件访问器。 如果提供自定义 `add`访问器，还必须提供 [remove](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/remove) 访问器。

### 示例

如下示例显示一个具有自定义 `add` 和 [remove](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/remove) 访问器的事件。 有关完整示例，请参阅[操作说明：实现接口事件](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/events/how-to-implement-interface-events)。

```csharp
class Events : IDrawingObject
{
    event EventHandler PreDrawEvent;

    event EventHandler IDrawingObject.OnDraw
    {
        add
        {
            lock (PreDrawEvent)
            {
                PreDrawEvent += value;
            }
        }
        remove
        {
            lock (PreDrawEvent)
            {
                PreDrawEvent -= value;
            }
        }
    }

}
```

通常不需要提供自己的自定义事件访问器。 大多数情况下，使用声明事件时由编译器自动生成的访问器就足够了。

## [get](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/get)

`get` 关键字在属性或索引器中定义访问器方法，它将返回属性值或索引器元素。 有关详细信息，请参阅[属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/properties)、[自动实现的属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/auto-implemented-properties)和[索引器](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/indexers/index)。

以下示例为名为 `Seconds` 的属性同时定义 `get` 和 `set` 访问器。 它使用名为 `_seconds` 的私有字段备份属性值。

C#复制

```csharp
class TimePeriod
{
     private double _seconds;

     public double Seconds
     {
         get { return _seconds; }
         set { _seconds = value; }
     }
}
```

通常，`get` 访问器包含返回一个值的单个语句，如前面的示例所示。 从 C# 7.0 开始，可以将 `get` 访问器作为 expression-bodied 成员实现。 以下示例将 `get` 和 `set` 访问器都作为 expression-bodied 成员实现。

C#复制

```csharp
class TimePeriod
{
    private double _seconds;

    public double Seconds
    {
        get => _seconds;
        set => _seconds = value;
    }
}
```

对于属性的 `get` 和 `set` 访问器不执行除设置或检索私有支持字段中的值以外的任何其他操作的简单情况，可以利用 C# 编译器对自动实现的属性的支持。 以下示例将 `Hours` 作为自动实现的属性来实现。

C#复制

```csharp
class TimePeriod2
{
    public double Hours { get; set; }
}
```

## [global](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/global)

`global` 上下文关键字位于 [:: 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/namespace-alias-qualifer) 之前时引用全局命名空间（即任何 C# 程序的默认命名空间，否则其未被命名）。 有关更多信息，请参见[如何：使用全局命名空间别名](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/namespaces/how-to-use-the-global-namespace-alias)。

如下示例演示如何使用 `global` 上下文关键字来指定在全局命名空间中定义类 `TestApp`：

```csharp
class TestClass : global::TestApp { }
```

## [partial (Type)](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/partial-type)

通过分部类型可以定义要拆分到多个文件中的类、结构或接口。

在 File1.cs 中：

```csharp
namespace PC
{
    partial class A
    {
        int num = 0;
        void MethodA() { }
        partial void MethodC();
    }
}
```

在 File2.cs 中，声明：

```csharp
namespace PC
{
    partial class A
    {
        void MethodB() { }
        partial void MethodC() { }
    }
}
```

在处理大型项目或自动生成的代码（如 [Windows 窗体设计器](https://docs.microsoft.com/zh-cn/dotnet/framework/winforms/controls/developing-windows-forms-controls-at-design-time)提供的代码）时，在多个文件间拆分类、结构或接口类型可能会非常有用。 分部类型可以包含[分部方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/partial-method)。 有关详细信息，请参阅[分部类和方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/partial-classes-and-methods)。

## [partial (Method)](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/partial-method)

分部方法在分部类型的一部分中定义了签名，并在该类型的另一部分中定义了实现。 通过分部方法，类设计器可提供与事件处理程序类似的方法挂钩，以便开发者决定是否实现。 如果开发者不提供实现，则编译器在编译时删除签名。 以下条件适用于分部方法：

- 分部类型各部分中的签名必须匹配。
- 方法必须返回 void。
- 不允许使用访问修饰符。 分部方法是隐式专用的。

下列示例显示在分部类的两个部分中定义的分部方法：

```csharp
namespace PM
{
    partial class A
    {
        partial void OnSomethingHappened(string s);
    }

    // This part can be in a separate file.
    partial class A
    {
        // Comment out this method and the program
        // will still compile.
        partial void OnSomethingHappened(String s)
        {
            Console.WriteLine("Something happened: {0}", s);
        }
    }
}
```

有关详细信息，请参阅[分部类和方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/partial-classes-and-methods)。

## [remove](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/remove)

`remove` 上下文关键字用于定义自定义事件访问器，当客户端代码订阅你的[事件](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/event)时将调用该访问器。 如果提供自定义 `remove` 访问器，还必须提供 [add](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/add) 访问器。

以下示例显示具有自定义 [add](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/add) 和 `remove` 访问器的事件。 有关完整示例，请参阅[操作说明：实现接口事件](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/events/how-to-implement-interface-events)。

```csharp
class Events : IDrawingObject
{
    event EventHandler PreDrawEvent;

    event EventHandler IDrawingObject.OnDraw
    {
        add
        {
            lock (PreDrawEvent)
            {
                PreDrawEvent += value;
            }
        }
        remove
        {
            lock (PreDrawEvent)
            {
                PreDrawEvent -= value;
            }
        }
    }

}
```

通常不需要提供自己的自定义事件访问器。 大多数情况下，使用声明事件时由编译器自动生成的访问器就足够了。

## [set](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/set)

`set` 关键字在属性或索引器中定义访问器，它会向属性或索引器元素分配值。 有关详细信息和示例，请参阅[属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/properties)、[自动实现的属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/auto-implemented-properties)和[索引器](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/indexers/index)。

下面的示例为名为 `Seconds` 的属性同时定义 `get` 和 `set` 访问器。 它使用名为 `_seconds` 的私有字段备份属性值。

```csharp
class TimePeriod
{
     private double _seconds;

     public double Seconds
     {
         get { return _seconds; }
         set { _seconds = value; }
     }
}
```

通常，`set` 访问器包含分配一个值的单个语句，如前面的示例所示。 从 C# 7.0 开始，可以将 `set` 访问器作为 expression-bodied 成员实现。 下面的示例将 `get` 和 `set` 访问器都作为表达式主体成员实现。

```csharp
class TimePeriod
{
    private double _seconds;

    public double Seconds
    {
        get => _seconds;
        set => _seconds = value;
    }
}
```

对于属性的 `get` 和 `set` 访问器不执行除设置或检索私有支持字段中的值以外的任何其他操作的简单情况，可以利用 C# 编译器对自动实现的属性的支持。 以下示例将 `Hours` 作为自动实现的属性来实现。

```csharp
class TimePeriod2
{
    public double Hours { get; set; }
}
```

## [when (filter condition)](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/when)

在以下两个上下文中，可以使用上下文关键字 `when` 指定筛选条件：

- 在 [try/catch](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/try-catch) 或 [try/catch/finally](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/try-catch-finally) 块的 `catch` 语句中。
- 在 [switch](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/switch) 语句的 `case` 标签中。

### `catch` 语句中的 `when`

从 C# 6 开始，`when` 可用于 `catch` 语句中，以指定为执行特定异常处理程序而必须为 true 的条件。 语法为：

C#复制

```csharp
catch (ExceptionType [e]) when (expr)
```

其中，*expr* 是一个表达式，其计算结果为布尔值。 如果该表达式返回 `true`，则执行异常处理程序；如果返回 `false`，则不执行。

以下示例使用 `when` 关键字有条件地执行 [HttpRequestException](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.http.httprequestexception) 的处理程序，具体取决于异常消息的文本内容。

C#复制

```csharp
using System;
using System.Net.Http;
using System.Threading.Tasks;

class Program
{
   static void Main()
   {
      Console.WriteLine(MakeRequest().Result);
   }

   public static async Task<string> MakeRequest()
   { 
       var client = new System.Net.Http.HttpClient();
       var streamTask = client.GetStringAsync("https://localHost:10000");
       try {
           var responseText = await streamTask;
           return responseText;
       } 
       catch (HttpRequestException e) when (e.Message.Contains("301")) {
           return "Site Moved";
       }
       catch (HttpRequestException e) when (e.Message.Contains("404")) {
           return "Page Not Found";
       }
       catch (HttpRequestException e) {
           return e.Message;
       }
   }
}
```

### `switch` 语句中的 `when`

从 C# 7.0 开始，`case` 标签无需是互斥的，且 `case` 标签在 `switch` 语句中的显示顺序可以决定要执行的 switch 块。 `when` 关键字可指定一个筛选条件，该条件使得仅当筛选条件也为 true 时，与其相关联的 case 标签才为 true。 语法为：

C#复制

```csharp
case (expr) when (when-condition):
```

其中，*expr* 是与匹配表达式进行比较的常量模式或类型模式，而 *when-condition* 是任意布尔表达式。

以下示例使用 `when` 关键字针对具有零范围的 `Shape` 对象进行测试，同时针对各种范围大于零的 `Shape` 对象进行测试。

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

public class Example
{
   public static void Main()
   {
      Shape sh = null;
      Shape[] shapes = { new Square(10), new Rectangle(5, 7),
                         new Rectangle(10, 10), sh, new Square(0) };
      foreach (var shape in shapes)
         ShowShapeInfo(shape);
   }

   private static void ShowShapeInfo(Object obj)
   {
      switch (obj)
      {
         case Shape shape when shape.Area == 0:
            Console.WriteLine($"The shape: {shape.GetType().Name} with no dimensions");
            break;
         case Square sq when sq.Area > 0:
            Console.WriteLine("Information about the square:");
            Console.WriteLine($"   Length of a side: {sq.Side}");
            Console.WriteLine($"   Area: {sq.Area}");
            break;
         case Rectangle r when r.Area > 0:
            Console.WriteLine("Information about the rectangle:");
            Console.WriteLine($"   Dimensions: {r.Length} x {r.Width}");
            Console.WriteLine($"   Area: {r.Area}");
            break;
         case Shape shape:
            Console.WriteLine($"A {shape.GetType().Name} shape");
            break;
         case null:
            Console.WriteLine($"The {nameof(obj)} variable is uninitialized.");
            break;
         default:
            Console.WriteLine($"The {nameof(obj)} variable does not represent a Shape.");
            break;   
      }
   }
}
// The example displays the following output:
//       Information about the square:
//          Length of a side: 10
//          Area: 100
//       Information about the rectangle:
//          Dimensions: 5 x 7
//          Area: 35
//       Information about the rectangle:
//          Dimensions: 10 x 10
//          Area: 100
//       The obj variable is uninitialized.
//       The shape: Square with no dimensions
```

## [where (generic type constraint)](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/where-generic-type-constraint)

泛型定义中的 `where` 子句指定对用作泛型类型、方法、委托或本地函数中类型参数的参数类型的约束。 约束可指定接口、基类或要求泛型类型为引用、值或非托管类型。 它们声明类型参数必须具备的功能。

例如，可以声明一个泛型类 `MyGenericClass`，以使类型参数 `T` 实现 [IComparable](https://docs.microsoft.com/zh-cn/dotnet/api/system.icomparable-1) 接口：

C#复制

```csharp
public class AGenericClass<T> where T : IComparable<T> { }
```

 备注

有关查询表达式中的 where 子句的详细信息，请参阅 [where 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/where-clause)。

`where` 子句还可包括基类约束。 基类约束表明用作该泛型类型的类型参数的类型具有指定的类作为基类（或者是该基类），以用作该泛型类型的类型参数。 该基类约束一经使用，就必须出现在该类型参数的所有其他约束之前。 某些类型不允许作为基类约束：[Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object)、[Array](https://docs.microsoft.com/zh-cn/dotnet/api/system.array) 和 [ValueType](https://docs.microsoft.com/zh-cn/dotnet/api/system.valuetype)。 在 C# 7.3 之前，[Enum](https://docs.microsoft.com/zh-cn/dotnet/api/system.enum)、[Delegate](https://docs.microsoft.com/zh-cn/dotnet/api/system.delegate) 和[MulticastDelegate](https://docs.microsoft.com/zh-cn/dotnet/api/system.multicastdelegate) 也不允许作为基类约束。 以下示例显示现可指定为基类的类型：

C#复制

```csharp
public class UsingEnum<T> where T : System.Enum { }

public class UsingDelegate<T> where T : System.Delegate { }

public class Multicaster<T> where T : System.MulticastDelegate { }
```

`where` 子句可指定类型为 `class` 或 `struct`。 `struct` 约束不再需要指定 `System.ValueType` 的基类约束。 `System.ValueType` 类型可能不用作基类约束。 以下示例显示 `class` 和 `struct` 约束：

C#复制

```csharp
class MyClass<T, U>
    where T : class
    where U : struct
{ }
```

`where` 子句还可包括 `unmanaged` 约束。 `unmanaged` 约束将类型参数限制为名为“非托管类型”的类型。 “非托管类型”不是引用类型，且任何嵌套级别都不包含引用类型字段。 `unmanaged` 约束使得在 C# 中编写低级别的互操作代码变得更容易。 此约束支持跨所有非托管类型的可重用例程。 `unmanaged` 约束不能与 `class` 或 `struct`约束结合使用。 `unmanaged` 约束强制该类型必须为 `struct`：

C#复制

```csharp
class UnManagedWrapper<T>
    where T : unmanaged
{ }
```

`where` 子句也可能包括构造函数约束 `new()`。 该约束使得能够使用 `new` 运算符创建类型参数的实例。 [new() 约束](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/new-constraint)可以让编译器知道：提供的任何类型参数都必须具有可访问的无参数（或默认）构造函数。 例如:

C#复制

```csharp
public class MyGenericClass<T> where T : IComparable<T>, new()
{
    // The following line is not possible without new() constraint:
    T item = new T();
}
```

`new()` 约束出现在 `where` 子句的最后。 `new()` 约束不能与 `struct` 或 `unmanaged` 约束结合使用。 所有满足这些约束的类型必须具有可访问的无参数构造函数，这使得 `new()` 约束冗余。

对于多个类型参数，每个类型参数都使用一个 `where` 子句，例如：

C#复制

```csharp
public interface IMyInterface { }

namespace CodeExample
{
    class Dictionary<TKey, TVal>
        where TKey : IComparable<TKey>
        where TVal : IMyInterface
    {
        public void Add(TKey key, TVal val) { }
    }
}
```

还可将约束附加到泛型方法的类型参数，如以下示例所示：

C#复制

```csharp
public void MyMethod<T>(T t) where T : IMyInterface { }
```

请注意，对于委托和方法两者来说，描述类型参数约束的语法是一样的：

C#复制

```csharp
delegate T MyDelegate<T>() where T : new();
```

有关泛型委托的信息，请参阅[泛型委托](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/generics/generic-delegates)。

有关约束的语法和用法的详细信息，请参阅[类型参数的约束](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/generics/constraints-on-type-parameters)。

## [value](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/value)

上下文关键字 `value` 用在普通属性声明的 set 访问器中。 此关键字类似于方法的输入参数。 关键字 `value` 引用客户端代码尝试分配给属性的值。 在以下示例中，`MyDerivedClass` 有一个名为 `Name` 的属性，该属性使用 `value` 参数向支持字段 `name` 分配新字符串。 从客户端代码的角度来看，该操作写作一个简单的赋值语句。

C#复制

```csharp
class MyBaseClass
{
    // virtual auto-implemented property. Overrides can only
    // provide specialized behavior if they implement get and set accessors.
    public virtual string Name { get; set; }

    // ordinary virtual property with backing field
    private int num;
    public virtual int Number
    {
        get { return num; }
        set { num = value; }
    }
}

class MyDerivedClass : MyBaseClass
{
    private string name;

   // Override auto-implemented property with ordinary property
   // to provide specialized accessor behavior.
    public override string Name
    {
        get
        {
            return name;
        }
        set
        {
            if (!string.IsNullOrEmpty(value))
            {
                name = value;
            }
            else
            {
                name = "Unknown";
            }
        }
    } 
}
```

有关 `value` 用法的详细信息，请参阅[属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/properties)。

## [yield](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/yield)

如果你在语句中使用 `yield` [上下文关键字](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/index#contextual-keywords)，则意味着它在其中出现的方法、运算符或 `get` 访问器是迭代器。通过使用 `yield` 定义迭代器，可在实现自定义集合类型的 [IEnumerator](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerator-1) 和 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable) 模式时无需其他显式类（保留枚举状态的类，有关示例，请参阅 [IEnumerator](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerator)）。

下面的示例演示了 `yield` 语句的两种形式。

C#复制

```csharp
yield return <expression>;
yield break;
```

### 备注

使用 `yield return` 语句可一次返回一个元素。

通过 [foreach](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/foreach-in) 语句或 LINQ 查询来使用迭代器方法。 `foreach` 循环的每次迭代都会调用迭代器方法。 迭代器方法运行到 `yield return` 语句时，会返回一个 `expression`，并保留当前在代码中的位置。 下次调用迭代器函数时，将从该位置重新开始执行。

可以使用 `yield break` 语句来终止迭代。

有关迭代器的详细信息，请参阅[迭代器](https://docs.microsoft.com/zh-cn/dotnet/csharp/iterators)。

### 迭代器方法和 get 访问器

迭代器的声明必须满足以下要求：

- 返回类型必须为 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable)、[IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1)、[IEnumerator](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerator) 或 [IEnumerator](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerator-1)。
- 声明不能有任何 [in](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/in-parameter-modifier)、[ref](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ref) 或 [out](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/out-parameter-modifier) 参数。

返回 `yield` 或 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable) 的迭代器的 [IEnumerator](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerator) 类型为 `object`。 如果迭代器返回 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 或 [IEnumerator](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerator-1)，则必须将 `yield return` 语句中的表达式类型隐式转换为泛型类型参数。

你不能在具有以下特点的方法中包含 `yield return` 或 `yield break` 语句：

- 匿名方法。 有关详细信息，请参阅[匿名方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/anonymous-methods)。
- 包含不安全的块的方法。 有关详细信息，请参阅 [unsafe](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/unsafe)。

### 异常处理

不能将 `yield return` 语句置于 try-catch 块中。 可将 `yield return` 语句置于 try-finally 语句的 try 块中。

可将 `yield break` 语句置于 try 块或 catch 块中，但不能将其置于 finally 块中。

如果 `foreach` 主体（在迭代器方法之外）引发异常，则将执行迭代器方法中的 `finally` 块。

### 技术实现

以下代码从迭代器方法返回 `IEnumerable<string>`，然后遍历其元素。

C#复制

```csharp
IEnumerable<string> elements = MyIteratorMethod();
foreach (string element in elements)
{
   ...
}
```

调用 `MyIteratorMethod` 并不执行该方法的主体。 相反，该调用会将 `IEnumerable<string>` 返回到 `elements` 变量中。

在 `foreach` 循环迭代时，将为 [MoveNext](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerator.movenext) 调用 `elements` 方法。 此调用将执行 `MyIteratorMethod` 的主体，直至到达下一个 `yield return` 语句。 `yield return` 语句返回的表达式不仅决定了循环体使用的 `element` 变量值，还决定了 `elements` 的 [Current](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerator-1.current) 属性（它是 `IEnumerable<string>`）。

在 `foreach` 循环的每个后续迭代中，迭代器主体的执行将从它暂停的位置继续，直至到达 `yield return` 语句后才会停止。 在到达迭代器方法的结尾或 `foreach` 语句时，`yield break` 循环便已完成。

### 示例

下面的示例包含一个位于 `yield return` 循环内的 `for` 语句。 `Main` 方法中的 `foreach` 语句体的每次迭代都会创建对 `Power` 迭代器函数的调用。 对迭代器函数的每个调用将继续到 `yield return` 语句的下一次执行（在 `for` 循环的下一次迭代期间发生）。

迭代器方法的返回类型是 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable)（一种迭代器接口类型）。 当调用迭代器方法时，它将返回一个包含数字幂的可枚举对象。

C#复制

```csharp
public class PowersOf2
{
    static void Main()
    {
        // Display powers of 2 up to the exponent of 8:
        foreach (int i in Power(2, 8))
        {
            Console.Write("{0} ", i);
        }
    }

    public static System.Collections.Generic.IEnumerable<int> Power(int number, int exponent)
    {
        int result = 1;

        for (int i = 0; i < exponent; i++)
        {
            result = result * number;
            yield return result;
        }
    }

    // Output: 2 4 8 16 32 64 128 256
}
```

### 示例

下面的示例演示一个作为迭代器的 `get` 访问器。 在该示例中，每个 `yield return` 语句返回一个用户定义的类的实例。

C#复制

```csharp
public static class GalaxyClass
{
    public static void ShowGalaxies()
    {
        var theGalaxies = new Galaxies();
        foreach (Galaxy theGalaxy in theGalaxies.NextGalaxy)
        {
            Debug.WriteLine(theGalaxy.Name + " " + theGalaxy.MegaLightYears.ToString());
        }
    }

    public class Galaxies
    {

        public System.Collections.Generic.IEnumerable<Galaxy> NextGalaxy
        {
            get
            {
                yield return new Galaxy { Name = "Tadpole", MegaLightYears = 400 };
                yield return new Galaxy { Name = "Pinwheel", MegaLightYears = 25 };
                yield return new Galaxy { Name = "Milky Way", MegaLightYears = 0 };
                yield return new Galaxy { Name = "Andromeda", MegaLightYears = 3 };
            }
        }

    }

    public class Galaxy
    {
        public String Name { get; set; }
        public int MegaLightYears { get; set; }
    }
}
```