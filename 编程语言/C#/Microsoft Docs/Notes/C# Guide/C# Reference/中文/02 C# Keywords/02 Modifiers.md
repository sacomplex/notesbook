# [Modifiers](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/modifiers)

修饰符用于修改类型和类型成员的声明。 本节介绍 C# 修饰符。

| 修饰符                                                       | 目标                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [访问修饰符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/access-modifiers)  - [public](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/public) - [private](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/private) - [internal](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/internal) - [protected](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/protected) | 指定声明的类型和类型成员的可访问性。                         |
| [abstract](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/abstract) | 指示某个类只能是其他类的基类。                               |
| [async](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/async) | 指示修改后的方法、lambda 表达式或匿名方法是异步的。          |
| [const](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/const) | 指定无法修改字段或局部变量的值。                             |
| [事件](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/event) | 声明事件。                                                   |
| [extern](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/extern) | 指示在外部实现方法。                                         |
| [new](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/new) | 显式隐藏继承自基类的成员。                                   |
| [override](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/override) | 提供从基类继承的虚拟成员的新实现。                           |
| [partial](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/partial-type) | 在同一程序集中定义分部类、结构和方法。                       |
| [readonly](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/readonly) | 声明一个字段，该字段只能赋值为该声明的一部分或者在同一个类的构造函数中。 |
| [sealed](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/sealed) | 指定无法继承类。                                             |
| [static](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/static) | 声明属于类型本身而不是特定对象的成员。                       |
| [unsafe](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/unsafe) | 声明不安全的上下文。                                         |
| [virtual](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/virtual) | 在派生类中声明其实现可由重写成员更改的方法或访问器。         |
| [volatile](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/volatile) | 指示字段可在程序中由操作系统、硬件或并发执行线程等项修改。   |

## [Access Modifiers](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/access-modifiers)

访问修饰符是关键字，用于指定成员或类型已声明的可访问性。 本部分介绍四个访问修饰符：

- `public`
- `protected`
- `internal`
- `private`

可使用访问修饰符指定以下六个可访问性级别：

- [`public`](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/public)：访问不受限制。
- [`protected`](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/protected)：访问限于包含类或派生自包含类的类型。
- [`internal`](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/internal)：访问限于当前程序集。
- [`protected internal`](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/protected-internal)：访问限于当前程序集或派生自包含类的类型。
- [`private`](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/private)：访问限于包含类。
- [`private protected`](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/private-protected)：访问限于包含类或当前程序集中派生自包含类的类型。

本部分还介绍以下内容：

- [可访问性级别](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/accessibility-levels)：使用四个访问修饰符声明六个可访问性级别。
- [可访问性域](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/accessibility-domain)：指定可以在程序段中的何处引用成员。
- [可访问性级别的使用限制](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/restrictions-on-using-accessibility-levels)：汇总了已声明可访问性级别的使用限制。

### [Accessibility Levels](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/accessibility-levels)

使用访问修饰符 `public`、`protected`、`internal` 或 `private`，为成员指定以下声明的可访问性级别之一。

| 声明的可访问性                                               | 含义                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [`public`](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/public) | 访问不受限制。                                               |
| [`protected`](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/protected) | 访问限于包含类或派生自包含类的类型。                         |
| [`internal`](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/internal) | 访问限于当前程序集。                                         |
| [`protected internal`](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/protected-internal) | 访问限于当前程序集或派生自包含类的类型。                     |
| [`private`](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/private) | 访问限于包含类。                                             |
| [`private protected`](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/private-protected) | 访问限于包含类或当前程序集中派生自包含类的类型。 自 C# 7.2 之后可用。 |

除使用 `protected internal` 或`private protected` 组合的情况外，一个成员或类型仅允许一个访问修饰符。

命名空间中不允许出现访问修饰符。 命名空间没有任何访问限制。

根据出现成员声明的上下文，仅允许某些声明的可访问性。 如果未在成员声明中指定访问修饰符，则将使用默认可访问性。

未嵌套在其他类型中的顶级类型只能具有 `internal` 或 `public` 可访问性。 这些类型的默认可访问性为 `internal`。

作为其他类型的成员的嵌套类型可以具有如下表所示的声明的可访问性。

| 成员        | 默认成员可访问性 | 允许的成员的声明的可访问性                                   |
| ----------- | ---------------- | ------------------------------------------------------------ |
| `enum`      | `public`         | 无                                                           |
| `class`     | `private`        | `public`  `protected`  `internal`  `private`  `protected internal`   `private protected` |
| `interface` | `public`         | 无                                                           |
| `struct`    | `private`        | `public`  `internal`  `private`                              |

嵌套类型的可访问性依赖于它的[可访问域](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/accessibility-domain)，该域是由已声明的成员可访问性和直接包含类型的可访问域这二者共同确定的。 但是，嵌套类型的可访问域不能超出包含类型的可访问域。

### [Accessibility Domain](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/accessibility-domain)

成员的可访问域可指定成员可以引用哪些程序分区。 如果成员嵌套于其他类型中，则该成员的可访问域是由该成员的[可访问性级别](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/accessibility-levels)和直接包含类型的可访问域这二者共同确定的。

顶级类型的可访问域至少是在其中进行声明的项目的程序文本。 也就是说，该域包含此项目的所有源文件。 嵌套类型的可访问域至少是在其中进行声明的类型的程序文本。 也就是说，域是类型的主题，其中包括所有嵌套类型。 嵌套类型的可访问域决不能超出包含类型的可访问域。 下例说明了这些概念。

#### 示例

此示例包含一个顶级类型 `T1` 和两个嵌套类 `M1` 和 `M2`。 这两个类包含的字段具有不同的已声明可访问性。在 `Main` 方法中，每条语句后跟注释以指示每个成员的可访问域。 请注意，试图引用不可访问成员的语句将被注释掉。如果想要查看通过引用不可访问成员引起的编译器错误，请一次删除一条注释。

C#复制

```csharp
namespace AccessibilityDomainNamespace
{
    public class T1
    {
        public static int publicInt;
        internal static int internalInt;
        private static int privateInt = 0;
        static T1()
        {
            // T1 can access public or internal members
            // in a public or private (or internal) nested class
            M1.publicInt = 1;
            M1.internalInt = 2;
            M2.publicInt = 3;
            M2.internalInt = 4;

            // Cannot access the private member privateInt
            // in either class:
            // M1.privateInt = 2; //CS0122
        }

        public class M1
        {
            public static int publicInt;
            internal static int internalInt;
            private static int privateInt = 0;
        }

        private class M2
        {
            public static int publicInt = 0;
            internal static int internalInt = 0;
            private static int privateInt = 0;
        }
    }

    class MainClass
    {
        static void Main()
        {
            // Access is unlimited:
            T1.publicInt = 1;

            // Accessible only in current assembly:
            T1.internalInt = 2;

            // Error CS0122: inaccessible outside T1:
            // T1.privateInt = 3;  

            // Access is unlimited:
            T1.M1.publicInt = 1;

            // Accessible only in current assembly:
            T1.M1.internalInt = 2;

            // Error CS0122: inaccessible outside M1:
            //    T1.M1.privateInt = 3; 

            // Error CS0122: inaccessible outside T1:
            //    T1.M2.publicInt = 1;

            // Error CS0122: inaccessible outside T1:
            //    T1.M2.internalInt = 2;

            // Error CS0122: inaccessible outside M2:
            //    T1.M2.privateInt = 3;

            // Keep the console open in debug mode.
            System.Console.WriteLine("Press any key to exit.");
            System.Console.ReadKey();
        }
    }
}
```

### [Restrictions on Using Accessibility Levels](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/restrictions-on-using-accessibility-levels)

在声明中指定类型时，检查类型的可访问性级别是否依赖于成员或其他类型的可访问性级别。 例如，直接基类必须至少具有与派生类相同的可访问性。 以下声明会导致编译器错误，因为基类 `BaseClass` 的可访问性低于 `MyClass`：

C#复制

```csharp
class BaseClass {...}
public class MyClass: BaseClass {...} // Error
```

下表汇总了对已声明可访问性级别的限制。

| 上下文                                                       | 备注                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [类](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/classes) | 类类型的直接基类必须至少具有与类类型本身相同的可访问性。     |
| [接口](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/interfaces/index) | 接口类型的显式基接口必须至少具有与接口类型本身相同的可访问性。 |
| [委托](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/delegates/index) | 委托类型的返回类型和参数类型必须至少具有与委托类型本身相同的可访问性。 |
| [常量](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/constants) | 常量的类型必须至少具有与常量本身相同的可访问性。             |
| [字段](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/fields) | 字段的类型必须至少具有与字段本身相同的可访问性。             |
| [方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/methods) | 方法的返回类型和参数类型必须至少具有与方法本身相同的可访问性。 |
| [属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/properties) | 属性的类型必须至少具有与属性本身相同的可访问性。             |
| [事件](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/events/index) | 事件的类型必须至少具有与事件本身相同的可访问性。             |
| [索引器](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/indexers/index) | 索引器的类型和参数类型必须至少具有与索引器本身相同的可访问性。 |
| [运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/operators) | 运算符的类型和参数类型必须至少具有与运算符本身相同的可访问性。 |
| [构造函数](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/constructors) | 构造函数的参数类型必须至少具有与构造函数本身相同的可访问性。 |

#### 示例

下面的示例包含不同类型的错误声明。 每个声明后的注释指示预期编译器错误。

C#复制

```csharp
// Restrictions on Using Accessibility Levels
// CS0052 expected as well as CS0053, CS0056, and CS0057
// To make the program work, change access level of both class B
// and MyPrivateMethod() to public.

using System;

// A delegate:
delegate int MyDelegate();

class B
{
    // A private method:
    static int MyPrivateMethod()
    {
        return 0;
    }
}

public class A
{
    // Error: The type B is less accessible than the field A.myField.
    public B myField = new B();

    // Error: The type B is less accessible
    // than the constant A.myConst.
    public readonly B myConst = new B();

    public B MyMethod()
    {
        // Error: The type B is less accessible 
        // than the method A.MyMethod.
        return new B();
    }

    // Error: The type B is less accessible than the property A.MyProp
    public B MyProp
    {
        set
        {
        }
    }

    MyDelegate d = new MyDelegate(B.MyPrivateMethod);
    // Even when B is declared public, you still get the error: 
    // "The parameter B.MyPrivateMethod is not accessible due to 
    // protection level."

    public static B operator +(A m1, B m2)
    {
        // Error: The type B is less accessible
        // than the operator A.operator +(A,B)
        return new B();
    }

    static void Main()
    {
        Console.Write("Compiled successfully");
    }
}
```

### [internal](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/internal)

`internal` 关键字是类型和类型成员的[访问修饰符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/access-modifiers)。

> 本页涵盖 `internal` 访问。 `internal` 关键字也是 [`protected internal`](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/protected-internal) 访问修饰符的一部分。

只有在同一程序集的文件中，内部类型或成员才可访问，如下例所示：

C#复制

```csharp
public class BaseClass   
{  
    // Only accessible within the same assembly  
    internal static int x = 0;  
}  
```

有关 `internal` 和其他访问修饰符的比较，请参阅[可访问性级别](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/accessibility-levels)和[访问修饰符](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/access-modifiers)。

有关程序集的详细信息，请参阅[程序集和全局程序集缓存](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/assemblies-gac/index)。

内部访问通常用于基于组件的开发，因为它可使一组组件以私有方式进行协作，而不必向应用程序代码的其余部分公开。 例如，用于生成图形用户界面的框架可以提供 `Control` 和 `Form` 类，这两个类通过使用具有内部访问权限的成员进行协作。 由于这些成员是内部的，因此不会向正在使用框架的代码公开。

从定义具有内部访问权限的类型或成员的程序集外部引用该类型或成员是错误的。

#### 示例

此示例包含两个文件，即 `Assembly1.cs` 和 `Assembly1_a.cs`。 第一个文件包含内部基类 `BaseClass`。 在第二个文件中，尝试实例化 `BaseClass` 会产生错误。

C#复制

```csharp
// Assembly1.cs  
// Compile with: /target:library  
internal class BaseClass   
{  
   public static int intM = 0;  
}  
```

C#复制

```csharp
// Assembly1_a.cs  
// Compile with: /reference:Assembly1.dll  
class TestAccess   
{  
   static void Main()   
   {  
      BaseClass myBase = new BaseClass();   // CS0122  
   }  
}  
```

#### 示例

在此示例中，使用在示例 1 中所用的相同文件，并将 `BaseClass` 的可访问性级别更改为 `public`。 另将成员 `IntM` 的可访问性级别更改为 `internal`。 在此例中，可以实例化类，但不能访问内部成员。

C#复制

```csharp
// Assembly2.cs  
// Compile with: /target:library  
public class BaseClass   
{  
   internal static int intM = 0;  
}  
```

C#复制

```csharp
// Assembly2_a.cs  
// Compile with: /reference:Assembly2.dll  
public class TestAccess   
{  
   static void Main()   
   {  
      BaseClass myBase = new BaseClass();   // Ok.  
      BaseClass.intM = 444;    // CS0117  
   }  
}  
```

### [private](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/private)

`private` 关键字是一个成员访问修饰符。

> 本页涵盖 `private` 访问。 `private` 关键字也是 [`private protected`](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/private-protected) 访问修饰符的一部分。

私有访问是允许的最低访问级别。 私有成员只有在声明它们的类和结构体中才是可访问的，如以下示例所示：

C#复制

```csharp
class Employee
{
    private int i;
    double d;   // private access by default
}
```

同一体中的嵌套类型也可以访问那些私有成员。

在声明私有成员的类或结构外引用它会导致编译时错误。

有关 `private` 和其他访问修饰符的比较，请参阅[可访问性级别](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/accessibility-levels)和[访问修饰符](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/access-modifiers)。

#### 示例

在此示例中，`Employee` 类包含两个私有数据成员 `name` 和 `salary`。 作为私有成员，它们只能通过成员方法来访问。 添加名为 `GetName` 和 `Salary` 的公共方法，以便可以对私有成员进行受控的访问。 通过公共方法访问 `name` 成员，而通过公共只读属性访问 `salary` 成员。 （有关详细信息，请参阅[属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/properties)。）

C#复制

```csharp
class Employee2
{
    private string name = "FirstName, LastName";
    private double salary = 100.0;

    public string GetName()
    {
        return name;
    }

    public double Salary
    {
        get { return salary; }
    }
}

class PrivateTest
{
    static void Main()
    {
        Employee2 e = new Employee2();

        // The data members are inaccessible (private), so
        // they can't be accessed like this:
        //    string n = e.name;
        //    double s = e.salary;

        // 'name' is indirectly accessed via method:
        string n = e.GetName();

        // 'salary' is indirectly accessed via property
        double s = e.Salary;
    }
}
```

### [protected](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/protected)

`protected` 关键字是一个成员访问修饰符。

> 本页涵盖 `protected` 访问。 `protected` 关键字也属于 [`protected internal`](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/protected-internal) 和 [`private protected`](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/private-protected) 访问修饰符。

受保护成员在其所在的类中可由派生类实例访问。

有关 `protected` 和其他访问修饰符的比较，请参阅[可访问性级别](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/accessibility-levels)。

#### 示例

只有在通过派生类类型进行访问时，基类的受保护成员在派生类中才是可访问的。 以下面的代码段为例：

C#复制

```csharp
class A
{
    protected int x = 123;
}

class B : A
{
    static void Main()
    {
        A a = new A();
        B b = new B();

        // Error CS1540, because x can only be accessed by
        // classes derived from A.
        // a.x = 10; 

        // OK, because this class derives from A.
        b.x = 10;
    }
}
```

语句 `a.x = 10` 生成错误，因为它是在静态方法 Main 中生成的，而不是类 B 的实例。

无法保护结构成员，因为无法继承结构。

#### 示例

在此示例中，`DerivedPoint` 类是从 `Point` 派生的。 因此，可以从派生类直接访问基类的受保护成员。

C#复制

```csharp
class Point 
{
    protected int x; 
    protected int y;
}

class DerivedPoint: Point 
{
    static void Main() 
    {
        DerivedPoint dpoint = new DerivedPoint();

        // Direct access to protected members:
        dpoint.x = 10;
        dpoint.y = 15;
        Console.WriteLine("x = {0}, y = {1}", dpoint.x, dpoint.y); 
    }
}
// Output: x = 10, y = 15
```

如果将 `x` 和 `y` 的访问级别更改为 [private](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/private)，编译器将发出错误消息：

```
'Point.y' is inaccessible due to its protection level.
'Point.x' is inaccessible due to its protection level.
```

### [public](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/public)

`public` 关键字是类型和类型成员的访问修饰符。 公共访问是允许的最高访问级别。 对访问公共成员没有限制，如以下示例所示：

C#复制

```csharp
class SampleClass
{
    public int x; // No access restrictions.
}
```

有关详细信息，请参阅[访问修饰符](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/access-modifiers)和[可访问性级别](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/accessibility-levels)。

#### 示例

在下面的示例中，声明了两个类：`PointTest` 和 `MainClass`。 直接从 `MainClass` 访问 `PointTest` 的公共成员 `x` 和 `y`。

C#复制

```csharp
class PointTest
{
    public int x; 
    public int y;
}

class MainClass4
{
    static void Main() 
    {
        PointTest p = new PointTest();
        // Direct access to public members:
        p.x = 10;
        p.y = 15;
        Console.WriteLine("x = {0}, y = {1}", p.x, p.y); 
    }
}
// Output: x = 10, y = 15
```

如果将 `public` 访问级别更改为 [private](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/private) 或 [protected](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/protected)，则会收到错误消息：

“PointTest.y”不可访问，因为它受保护级别限制。

### [protected internal](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/protected-internal)

`protected internal` 关键字组合是一种成员访问修饰符。 可从当前程序集或派生自包含类的类型访问受保护的内部成员。 有关 `protected internal` 和其他访问修饰符的比较，请参阅[可访问性级别](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/accessibility-levels)。

#### 示例

可从包含程序集内的任何类型访问基类的受保护的内部成员。 也可在另一程序集中的派生类中访问它，前提是通过派生类类型的变量进行访问。 以下面的代码段为例：

C#复制

```csharp
// Assembly1.cs
// Compile with: /target:library
public class BaseClass
{
   protected internal int myValue = 0;
}

class TestAccess
{
    void Access()
    {
        BaseClass baseObject = new BaseClass();
        baseObject.myValue = 5;
    }
}
```

C#复制

```csharp
// Assembly2.cs
// Compile with: /reference:Assembly1.dll
class DerivedClass : BaseClass
{
    static void Main()
    {
        BaseClass baseObject = new BaseClass();
        DerivedClass derivedObject = new DerivedClass();

        // Error CS1540, because myValue can only be accessed by
        // classes derived from BaseClass.
        // baseObject.myValue = 10;

        // OK, because this class derives from BaseClass.
        derivedObject.myValue = 10;
    }
}
```

此示例包含两个文件，即 `Assembly1.cs` 和 `Assembly2.cs`。 第一个文件包含公共基类 `BaseClass` 和另一个类 `TestAccess`。 `BaseClass` 拥有受保护的内部成员 `myValue`，由 `TestAccess` 类型访问。 在第二个文件中，如果尝试通过 `BaseClass` 的实例访问 `myValue` ，会生成错误，但如果尝试通过一个派生类的实例来访问此成员，`DerivedClass` 会成功。

结构成员不能为 `protected internal`，因为无法继承结构。

### [private protected](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/private-protected)

`private protected` 关键字组合是一种成员访问修饰符。 仅派生自包含类的类型可访问私有受保护成员，但仅能在其包含程序集中访问。 有关 `private protected` 和其他访问修饰符的比较，请参阅[可访问性级别](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/accessibility-levels)。

 备注

`private protected` 访问修饰符在 C# 版本 7.2 及更高版本中有效。

#### 示例

仅当变量的静态类型是派生类类型时，可从派生的类型访问基类的私有受保护成员（在其包含程序集中访问）。以下面的代码段为例：

C#复制

```csharp
// Assembly1.cs  
// Compile with: /target:library  
public class BaseClass
{
    private protected int myValue = 0;
}

public class DerivedClass1 : BaseClass
{
    void Access()
    {
        BaseClass baseObject = new BaseClass();

        // Error CS1540, because myValue can only be accessed by
        // classes derived from BaseClass.
        // baseObject.myValue = 5;  

        // OK, accessed through the current derived class instance
        myValue = 5;
    }
}
```

C#复制

```csharp
// Assembly2.cs  
// Compile with: /reference:Assembly1.dll  
class DerivedClass2 : BaseClass
{
    void Access()
    {
        // Error CS0122, because myValue can only be
        // accessed by types in Assembly1
        // myValue = 10;
    }
}
```

此示例包含两个文件，即 `Assembly1.cs` 和 `Assembly2.cs`。 第一个文件包含公共基类 `BaseClass` 及其派生的类型 `DerivedClass1`。 `BaseClass` 拥有私有受保护成员 `myValue`，`DerivedClass1` 尝试以两种方式访问该成员。通过 `BaseClass` 的实例第一次尝试访问 `myValue` 时会产生错误。 但是，如果尝试在 `DerivedClass1` 中将其用作继承的成员，则会成功。 在第二个文件中，如果尝试将 `myValue` 作为 `DerivedClass2` 的继承成员进行访问，会生成错误，因为仅 Assembly1 中的派生类型可以访问它。

结构成员不能为 `private protected`，因为无法继承结构。

## [abstract](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/abstract)

`abstract` 修饰符指示被修改内容的实现已丢失或不完整。 abstract 修饰符可用于类、方法、属性、索引和事件。 在类声明中使用 `abstract` 修饰符以指示某个类仅旨在作为其他类的基类。 标记为 abstract 的成员，或包含在抽象类中的成员，都必须由派生自抽象类的类来实现。

### 示例

在此示例中，类 `Square` 必须提供 `Area` 的实现，因为它派生自 `ShapesClass`：

C#复制

```csharp
abstract class ShapesClass
{
    abstract public int Area();
}

class Square : ShapesClass
{
    int side = 0;

    public Square(int n)
    {
        side = n;
    }
    // Area method is required to avoid
    // a compile-time error.
    public override int Area()
    {
        return side * side;
    }

    static void Main() 
    {
        Square sq = new Square(12);
        Console.WriteLine("Area of the square = {0}", sq.Area());
    }

    interface I
    {
        void M();
    }
    abstract class C : I
    {
        public abstract void M();
    }

}
// Output: Area of the square = 144
```

抽象类具有以下功能：

- 抽象类不能实例化。
- 抽象类可能包含抽象方法和访问器。
- 无法使用 [sealed](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/sealed) 修饰符来修改抽象类，因为两个修饰符具有相反的含义。 `sealed` 修饰符阻止类被继承，而 `abstract` 修饰符要求类被继承。
- 派生自抽象类的非抽象类，必须包含全部已继承的抽象方法和访问器的实际实现。

在方法或属性声明中使用 `abstract` 修饰符，以指示该方法或属性不包含实现。

抽象方法具有以下功能：

- 抽象方法是隐式的虚拟方法。

- 只有抽象类中才允许抽象方法声明。

- 由于抽象方法声明不提供实际的实现，因此没有方法主体；方法声明仅以分号结尾，且签名后没有大括号 ({ })。 例如:

  C#复制

  ```csharp
  public abstract void MyMethod();  
  ```

  实现由方法 [override](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/override) 提供，它是非抽象类的成员。

- 在抽象方法声明中使用 [static](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/static) 或 [virtual](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/virtual) 修饰符是错误的。

除了声明和调用语法方面不同外，抽象属性的行为与抽象方法相似。

- 在静态属性上使用 `abstract` 修饰符是错误的。
- 通过包含使用 [override](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/override) 修饰符的属性声明，可在派生类中重写抽象继承属性。

有关抽象类的详细信息，请参阅[抽象类、密封类及类成员](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/abstract-and-sealed-classes-and-class-members)。

抽象类必须为所有接口成员提供实现。

实现接口的抽象类有可能将接口方法映射到抽象方法上。 例如:

C#复制

```csharp
interface I
{
    void M();
}
abstract class C : I
{
    public abstract void M();
}
```

### 示例

在此示例中，类 `DerivedClass` 派生自抽象类 `BaseClass`。 抽象类包含抽象方法 `AbstractMethod`，以及两个抽象属性 `X` 和 `Y`。

C#复制

```csharp
abstract class BaseClass   // Abstract class
{
    protected int _x = 100;
    protected int _y = 150;
    public abstract void AbstractMethod();   // Abstract method
    public abstract int X    { get; }
    public abstract int Y    { get; }
}

class DerivedClass : BaseClass
{
    public override void AbstractMethod()
    {
        _x++;
        _y++;
    }

    public override int X   // overriding property
    {
        get
        {
            return _x + 10;
        }
    }

    public override int Y   // overriding property
    {
        get
        {
            return _y + 10;
        }
    }

    static void Main()
    {
        DerivedClass o = new DerivedClass();
        o.AbstractMethod();
        Console.WriteLine("x = {0}, y = {1}", o.X, o.Y);
    }
}
// Output: x = 111, y = 161
```

在前面的示例中，如果你尝试通过使用如下语句来实例化抽象类：

C#复制

```csharp
BaseClass bc = new BaseClass();   // Error  
```

将遇到一个错误，告知编译器无法创建抽象类“BaseClass”的实例。

## [async](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/async)

使用 `async` 修饰符可将方法、[lambda 表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/lambda-expressions)或[匿名方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/anonymous-methods)指定为异步。 如果对方法或表达式使用此修饰符，则其称为异步方法。 如下示例定义了一个名为 `ExampleMethodAsync` 的异步方法：

C#复制

```csharp
public async Task<int> ExampleMethodAsync()  
{  
    // . . . .  
}  
```

如果不熟悉异步编程，或者不了解异步方法如何在不阻止调用方线程的情况下使用 `await` 关键字完成可能需要长时间运行的工作，请阅读[使用 async 和 await 的异步编程](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/index)中的介绍。 如下代码见于一种异步方法中，且调用[HttpClient.GetStringAsync](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.http.httpclient.getstringasync) 方法：

C#复制

```csharp
string contents = await httpClient.GetStringAsync(requestUrl);  
```

异步方法同步运行，直至到达其第一个 `await` 表达式，此时会将方法挂起，直到等待的任务完成。 同时，如下节示例中所示，控件将返回到方法的调用方。

如果 `async` 关键字修改的方法不包含 `await` 表达式或语句，则该方法将同步执行。 编译器警告将通知你不包含 `await` 语句的任何异步方法，因为该情况可能表示存在错误。 请参阅[编译器警告（等级 1）CS4014](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-messages/cs4014)。

`async` 关键字是上下文关键字，原因在于只有当它修饰方法、lambda 表达式或匿名方法时，它才是关键字。 在所有其他上下文中，都会将其解释为标识符。

### 示例

下面的示例展示了异步事件处理程序 `StartButton_Click` 和异步方法 `ExampleMethodAsync` 之间的控制结构和流程。 此异步方法的结果是 Web 页面的字符数。 此代码适用于在 Visual Studio 中创建的 Windows Presentation Foundation (WPF) 应用或 Windows 应用商店应用；请参见有关设置应用的代码注释。

可以在 Visual Studio 中将此代码作为 Windows Presentation Foundation (WPF) 应用或 Windows 应用商店应用运行。 需要一个名为 `StartButton` 的按钮控件和一个名为 `ResultsTextBox` 的文本框控件。 切勿忘记设置名称和处理程序，以便获得类似于以下代码的内容：

XAML复制

```xaml
<Button Content="Button" HorizontalAlignment="Left" Margin="88,77,0,0" VerticalAlignment="Top" Width="75"  
        Click="StartButton_Click" Name="StartButton"/>  
<TextBox HorizontalAlignment="Left" Height="137" Margin="88,140,0,0" TextWrapping="Wrap"   
         Text="&lt;Enter a URL&gt;" VerticalAlignment="Top" Width="310" Name="ResultsTextBox"/>  
```

将代码作为 WPF 应用运行：

- 将此代码粘贴到 MainWindow.xaml.cs 中的 `MainWindow` 类中。
- 添加对 System.Net.Http 的引用。
- 为 System.Net.Http 添加一个 `using` 指令。

将此代码作为 Windows 应用商店应用运行：

- 将此代码粘贴到 MainPage.xaml.cs 中的 `MainPage` 类中。
- 为 System.Net.Http 和 System.Threading.Tasks 添加 using 指令。

C#复制

```csharp
private async void StartButton_Click(object sender, RoutedEventArgs e)
{
    // ExampleMethodAsync returns a Task<int>, which means that the method  
    // eventually produces an int result. However, ExampleMethodAsync returns  
    // the Task<int> value as soon as it reaches an await.  
    ResultsTextBox.Text += "\n";

    try
    {
        int length = await ExampleMethodAsync();
        // Note that you could put "await ExampleMethodAsync()" in the next line where  
        // "length" is, but due to when '+=' fetches the value of ResultsTextBox, you  
        // would not see the global side effect of ExampleMethodAsync setting the text.  
        ResultsTextBox.Text += String.Format("Length: {0:N0}\n", length);
    }
    catch (Exception)
    {
        // Process the exception if one occurs.  
    }
}

public async Task<int> ExampleMethodAsync()
{
    var httpClient = new HttpClient();
    int exampleInt = (await httpClient.GetStringAsync("http://msdn.microsoft.com")).Length;
    ResultsTextBox.Text += "Preparing to finish ExampleMethodAsync.\n";
    // After the following return statement, any method that's awaiting  
    // ExampleMethodAsync (in this case, StartButton_Click) can get the   
    // integer result.  
    return exampleInt;
}
// The example displays the following output:  
// Preparing to finish ExampleMethodAsync.  
// Length: 53292  
```

 重要

若要深入了解各项任务以及在等待任务期间所执行的代码，请参阅[使用 async 和 await 的异步编程](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/index)。 有关使用类似元素的完整 WPF 示例，请参阅[演练：使用 Async 和 Await 访问 Web](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/walkthrough-accessing-the-web-by-using-async-and-await)。

### 返回类型

异步方法可具有以下返回类型：

- [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task)
- [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1)
- [void](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/void)（应仅用于事件处理程序）。
- 从 C# 7.0 开始，任何具有可访问的 `GetAwaiter` 方法的类型。 `System.Threading.Tasks.ValueTask<TResult>` 类型属于此类实现。 它通过添加 NuGet 包 `System.Threading.Tasks.Extensions` 的方式可用。

此异步方法既不能声明任何 [in](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/in-parameter-modifier)、[ref](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ref) 或 [out](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/out-parameter-modifier) 参数，也不能具有[引用返回值](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/ref-returns)，但它可以调用具有此类参数的方法。

如果异步方法的 语句指定一个 类型的操作数，则应指定 `Task<TResult>` 作为方法的[返回](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/return)类型`TResult`。 如果当方法完成时未返回有意义的值，则应使用 `Task`。 即，对方法的调用将返回一个 `Task`，但是当 `Task` 完成时，任何等待 `await` 的所有 `Task` 表达式的计算结果都为 `void`。

你应主要使用 `void` 返回类型来定义事件处理程序，这些处理程序需要此返回类型。 `void` 返回异步方法的调用方不能等待，并且无法捕获该方法引发的异常。

从 C# 7.0 开始，返回另一个类型（通常为值类型），该类型具有 `GetAwaiter` 方法，可尽可能减少性能关键代码段中的内存分配。

有关详细信息和示例，请参阅[异步返回类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/async-return-types)。

## [const](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/const)

使用 `const` 关键字来声明某个常量字段或常量局部变量。 常量字段和常量局部变量不是变量并且不能修改。 常量可以为数字、布尔值、字符串或 null 引用。 不要创建常量来表示你需要随时更改的信息。 例如，不要使用常量字段来存储服务的价格、产品版本号或公司的品牌名称。 这些值会随着时间发生变化；因为编译器会传播常量，所以必须重新编译通过库编译的其他代码以查看更改。 另请参阅 [readonly](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/readonly) 关键字。 例如:

C#复制

```csharp
const int x = 0;
public const double gravitationalConstant = 6.673e-11;
private const string productName = "Visual C#";
```

### 备注

常数声明的类型指定声明引入的成员类型。 常量局部变量或常量字段的初始值设定项必须是一个可以隐式转换为目标类型的常量表达式。

常数表达式是在编译时可被完全计算的表达式。 因此，对于引用类型的常数，可能的值只能是 `string` 和 null 引用。

常数声明可以声明多个常数，例如：

C#复制

```csharp
public const double x = 1.0, y = 2.0, z = 3.0;
```

不允许在常数声明中使用 `static` 修饰符。

常数可以参与常数表达式，如下所示：

C#复制

```csharp
public const int c1 = 5;
public const int c2 = c1 + 100;
```

 备注

[readonly](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/readonly) 关键字与 `const` 关键字不同。 `const` 字段只能在该字段的声明中初始化。 `readonly` 字段可以在声明或构造函数中初始化。 因此，根据所使用的构造函数，`readonly` 字段可能具有不同的值。 另外，虽然 `const` 字段是编译时常量，但 `readonly` 字段可用于运行时常量，如此行所示：`public static readonly uint l1 = (uint)DateTime.Now.Ticks;`

### 示例

C#复制

```csharp
public class ConstTest 
{
    class SampleClass
    {
        public int x;
        public int y;
        public const int c1 = 5;
        public const int c2 = c1 + 5;

        public SampleClass(int p1, int p2) 
        {
            x = p1; 
            y = p2;
        }
    }

    static void Main()
    {
        SampleClass mC = new SampleClass(11, 22);
        Console.WriteLine("x = {0}, y = {1}", mC.x, mC.y);
        Console.WriteLine("c1 = {0}, c2 = {1}", 
                          SampleClass.c1, SampleClass.c2);
    }
}
/* Output
    x = 11, y = 22
    c1 = 5, c2 = 10
*/
```

### 示例

此示例说明如何将常数用作局部变量。

C#复制

```csharp
public class SealedTest
{
    static void Main()
    {
        const int c = 707;
        Console.WriteLine("My local constant = {0}", c);
    }
}
// Output: My local constant = 707
```

## [event](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/event)

`event` 关键字用于声明发布服务器类中的事件。

### 示例

下面的示例演示如何声明和引发使用 [EventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.eventhandler) 作为基础委托类型的事件。 有关展示如何使用泛型[EventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.eventhandler-1) 委托类型以及如何订阅事件并创建事件处理程序方法的完整代码示例，请参阅[操作说明：发布符合 .NET Framework 准则的事件](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/events/how-to-publish-events-that-conform-to-net-framework-guidelines)。

C#复制

```csharp
public class SampleEventArgs
{
    public SampleEventArgs(string s) { Text = s; }
    public String Text { get; } // readonly
}

public class Publisher
{
    // Declare the delegate (if using non-generic pattern).
    public delegate void SampleEventHandler(object sender, SampleEventArgs e);

    // Declare the event.
    public event SampleEventHandler SampleEvent;

    // Wrap the event in a protected virtual method
    // to enable derived classes to raise the event.
    protected virtual void RaiseSampleEvent()
    {
        // Raise the event by using the () operator.
        if (SampleEvent != null)
            SampleEvent(this, new SampleEventArgs("Hello"));
    }
}
```

事件是一种特殊的多播委托，仅可以从声明事件的类或结构（发布服务器类）中对其进行调用。 如果其他类或结构订阅该事件，则在发布服务器类引发该事件时，将调用其事件处理程序方法。 有关详细信息和代码示例，请参阅[事件](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/events/index)和[委托](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/delegates/index)。

可以将事件标记为[public](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/public)、[private](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/private)、[protected](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/protected)、[internal](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/internal)、[protected internal](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/protected-internal) 或 [private protected](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/private-protected)。 这些访问修饰符定义该类的用户访问该事件的方式。 有关详细信息，请参阅[访问修饰符](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/access-modifiers)。

### 关键字和事件

下列关键字应用于事件。

| 关键字                                                       | 说明                                                         | 更多相关信息                                                 |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| [static](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/static) | 使事件可供调用方在任何时候进行调用，即使不存在类的实例。     | [静态类和静态类成员](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/static-classes-and-static-class-members) |
| [virtual](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/virtual) | 允许派生类使用[重写](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/override)关键字重写事件行为。 | [继承](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/inheritance) |
| [sealed](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/sealed) | 指定对于派生类，它不再是虚拟的。                             |                                                              |
| [abstract](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/abstract) | 编译器不会生成 `add` 和 `remove` 事件访问器块，因此派生类必须提供其自己的实现。 |                                                              |

可以通过使用[静态](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/static)关键字将事件声明为静态事件。 这可使事件可供调用方在任何时候进行调用，即使不存在类的实例。 有关详细信息，请参阅[静态类和静态类成员](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/static-classes-and-static-class-members)。

可以通过使用[虚拟](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/virtual)关键字将事件标记为虚事件。 这可使派生类使用[重写](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/override)关键字重写事件行为。 有关详细信息，请参阅[继承](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/inheritance)。 重写虚拟事件的事件也可以为[密封](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/sealed)，指定对于派生类，它不再是虚拟的。 最后，可以声明事件为[抽象](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/abstract)，这意味着编译器将不会生成 `add` 和 `remove` 事件访问器块。 因此，派生类必须提供其自己的实现。

## [extern](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/extern)

`extern` 修饰符用于声明在外部实现的方法。 `extern` 修饰符的常见用法是在使用 Interop 服务调入非托管代码时与 `DllImport` 特性一起使用。 在这种情况下，还必须将方法声明为 `static`，如下面的示例所示：

C#复制

```csharp
[DllImport("avifil32.dll")]
private static extern void AVIFileInit();
```

`extern` 关键字还可以定义外部程序集别名，使得可以从单个程序集中引用同一组件的不同版本。 有关详细信息，请参阅[外部别名](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/extern-alias)。

将 [abstract](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/abstract) 和 `extern` 修饰符一起使用来修改同一成员是错误的做法。 使用 `extern` 修饰符意味着方法是在 C# 代码的外部实现的，而使用 `abstract` 修饰符意味着类中未提供方法实现。

extern 关键字用于 C# 中时会比用于 C++ 中时受到更多的限制。 若要比较 C# 关键字与 C++ 关键字，请参见 C++ 语言参考中的“使用 extern 指定链接”。

### 示例 1

在此示例中，程序接收来自用户的字符串并将该字符串显示在消息框中。 程序使用从 User32.dll 库导入的 `MessageBox` 方法。

C#复制

```csharp
//using System.Runtime.InteropServices;
class ExternTest
{
    [DllImport("User32.dll", CharSet=CharSet.Unicode)] 
    public static extern int MessageBox(IntPtr h, string m, string c, int type);

    static int Main()
    {
        string myString;
        Console.Write("Enter your message: ");
        myString = Console.ReadLine();
        return MessageBox((IntPtr)0, myString, "My Message Box", 0);
    }

}
```

### 示例 2

此示例阐释了调入 C 库（本机 DLL）的 C# 程序。

1. 创建以下 C 文件并将其命名为 `cmdll.c`：

c复制

```c
// cmdll.c
// Compile with: -LD
int __declspec(dllexport) SampleMethod(int i)
{
  return i*10;
}
```

1. 从 Visual Studio 安装目录打开 Visual Studio x64（或 x32）本机工具命令提示符窗口，并通过在命令提示符处键入“cl -LD cmdll.c”来编译 `cmdll.c` 文件。
2. 在相同的目录中，创建以下 C# 文件并将其命名为 `cm.cs`：

C#复制

```csharp
// cm.cs
using System;
using System.Runtime.InteropServices;
public class MainClass
{
    [DllImport("Cmdll.dll")]
      public static extern int SampleMethod(int x);

    static void Main()
    {
        Console.WriteLine("SampleMethod() returns {0}.", SampleMethod(5));
    }
}
```

1. 从 Visual Studio 安装目录打开一个 Visual Studio x64（或 x32）本机工具命令提示符窗口，并通过键入以下内容来编译 `cm.cs` 文件：

> “csc cm.cs”（针对 x64 命令提示符）或“csc -platform:x86 cm.cs”（针对 x32 命令提示符）

这将创建可执行文件 `cm.exe`。

1. 运行 `cm.exe`。 `SampleMethod` 方法将值 5 传递到 DLL 文件，这将返回该值与 10 相乘后的结果。 该程序生成以下输出：

复制

```
SampleMethod() returns 50.
```

## [in (Generic Modifier)](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/in-generic-modifier)

对于泛型类型参数，`in` 关键字可指定类型参数是逆变的。 可以在泛型接口和委托中使用 `in` 关键字。

逆变使你使用的类型可以比泛型参数指定的类型派生程度更小。 这样可以隐式转换实现协变接口的类以及隐式转换委托类型。 引用类型支持泛型类型参数中的协变和逆变，但值类型不支持它们。

仅在类型定义方法参数的类型，而不是方法返回类型时，类型可以在泛型接口或委托中声明为逆变。 `In`、`ref` 和 `out` 参数必须是固定的，这意味着它们既不为协变又不为逆变。

具有逆变类型参数的接口使其方法接受的参数的类型可以比接口类型参数指定的类型派生程度更小。 例如，在[IComparer](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.icomparer-1) 接口中，类型 T 是逆变的，可以将 `IComparer<Person>` 类型的对象分配给 `IComparer<Employee>`类型的对象，而无需使用任何特殊转换方法（如果 `Employee` 继承 `Person`）。

可以向逆变委托分配相同类型的其他委托，不过要使用派生程度更小的泛型类型参数。

有关详细信息，请参阅[协变和逆变](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/covariance-contravariance/index)。

### 逆变泛型接口

下面的示例演示如何声明、扩展和实现逆变泛型接口。 它还演示如何对实现此接口的类使用隐式转换。

C#复制

```csharp
// Contravariant interface.
interface IContravariant<in A> { }

// Extending contravariant interface.
interface IExtContravariant<in A> : IContravariant<A> { }

// Implementing contravariant interface.
class Sample<A> : IContravariant<A> { }

class Program
{
    static void Test()
    {
        IContravariant<Object> iobj = new Sample<Object>();
        IContravariant<String> istr = new Sample<String>();

        // You can assign iobj to istr because
        // the IContravariant interface is contravariant.
        istr = iobj;
    }
}
```

### 逆变泛型委托

以下示例演示如何声明、实例化和调用逆变泛型委托。 它还演示如何隐式转换委托类型。

C#复制

```csharp
// Contravariant delegate.
public delegate void DContravariant<in A>(A argument);

// Methods that match the delegate signature.
public static void SampleControl(Control control)
{ }
public static void SampleButton(Button button)
{ }

public void Test()
{

    // Instantiating the delegates with the methods.
    DContravariant<Control> dControl = SampleControl;
    DContravariant<Button> dButton = SampleButton;

    // You can assign dControl to dButton
    // because the DContravariant delegate is contravariant.
    dButton = dControl;

    // Invoke the delegate.
    dButton(new Button()); 
}
```

## [out (Generic Modifier)](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/out-generic-modifier)

对于泛型类型参数，`out` 关键字可指定类型参数是协变的。 可以在泛型接口和委托中使用 `out` 关键字。

协变使你使用的类型可以比泛型参数指定的类型派生程度更大。 这样可以隐式转换实现协变接口的类以及隐式转换委托类型。 引用类型支持协变和逆变，但值类型不支持它们。

具有协变类型参数的接口使其方法返回的类型可以比类型参数指定的类型派生程度更大。 例如，因为在 .NET Framework 4 的 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 中，类型 T 是协变的，所以可以将 `IEnumerable(Of String)` 类型的对象分配给`IEnumerable(Of Object)` 类型的对象，而无需使用任何特殊转换方法。

可以向协变委托分配相同类型的其他委托，不过要使用派生程度更大的泛型类型参数。

有关详细信息，请参阅[协变和逆变](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/covariance-contravariance/index)。

### 示例 - 协变泛型接口

下面的示例演示如何声明、扩展和实现协变泛型接口。 它还演示如何对实现协变接口的类使用隐式转换。

C#复制

```csharp
// Covariant interface.
interface ICovariant<out R> { }

// Extending covariant interface.
interface IExtCovariant<out R> : ICovariant<R> { }

// Implementing covariant interface.
class Sample<R> : ICovariant<R> { }

class Program
{
    static void Test()
    {
        ICovariant<Object> iobj = new Sample<Object>();
        ICovariant<String> istr = new Sample<String>();

        // You can assign istr to iobj because
        // the ICovariant interface is covariant.
        iobj = istr;
    }
}
```

在泛型接口中，如果类型参数满足以下条件，则可以声明为协变：

- 类型参数只用作接口方法的返回类型，而不用作方法参数的类型。

   备注

  此规则有一个例外。 如果在协变接口中将逆变泛型委托用作方法参数，则可以将协变类型用作此委托的泛型类型参数。 有关协变和逆变泛型委托的详细信息，请参阅[委托中的变体](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/covariance-contravariance/variance-in-delegates)和[对 Func 和 Action 泛型委托使用变体](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/covariance-contravariance/using-variance-for-func-and-action-generic-delegates)。

- 类型参数不用作接口方法的泛型约束。

### 示例 - 协变泛型委托

以下示例演示如何声明、实例化和调用协变泛型委托。 它还演示如何隐式转换委托类型。

C#复制

```csharp
// Covariant delegate.
public delegate R DCovariant<out R>();

// Methods that match the delegate signature.
public static Control SampleControl()
{ return new Control(); }

public static Button SampleButton()
{ return new Button(); }

public void Test()
{            
    // Instantiate the delegates with the methods.
    DCovariant<Control> dControl = SampleControl;
    DCovariant<Button> dButton = SampleButton;

    // You can assign dButton to dControl
    // because the DCovariant delegate is covariant.
    dControl = dButton;

    // Invoke the delegate.
    dControl(); 
}
```

在泛型委托中，如果类型仅用作方法返回类型，而不用于方法参数，则可以声明为协变。

## [override](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/override)

扩展或修改继承的方法、属性、索引器或事件的抽象或虚拟实现需要 `override` 修饰符。

### 示例

在此示例中，`Square` 类必须提供 `Area` 的重写实现，因为 `Area` 继承自抽象 `ShapesClass`：

C#复制

```csharp
abstract class ShapesClass
{
    abstract public int Area();
}

class Square : ShapesClass
{
    int side = 0;

    public Square(int n)
    {
        side = n;
    }
    // Area method is required to avoid
    // a compile-time error.
    public override int Area()
    {
        return side * side;
    }

    static void Main() 
    {
        Square sq = new Square(12);
        Console.WriteLine("Area of the square = {0}", sq.Area());
    }

    interface I
    {
        void M();
    }
    abstract class C : I
    {
        public abstract void M();
    }

}
// Output: Area of the square = 144
```

`override` 方法提供从基类继承的成员的新实现。 通过 `override` 声明重写的方法称为重写基方法。 重写基方法必须具有与 `override` 方法相同的签名。 有关继承的信息，请参阅[继承](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/inheritance)。

不能重写非虚方法或静态方法。 重写基方法必须是 `virtual`、`abstract` 或 `override`。

`override` 声明不能更改 `virtual` 方法的可访问性。 `override` 方法和 `virtual` 方法必须具有相同[级别访问修饰符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/access-modifiers)。

不能使用 `new`、`static` 或 `virtual` 修饰符修改 `override` 方法。

重写属性声明必须指定与继承的属性完全相同的访问修饰符、类型和名称，并且重写的属性必须是 `virtual`、`abstract` 或 `override`。

有关如何使用 `override` 关键字的详细信息，请参阅[使用 Override 和 New 关键字进行版本控制](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/versioning-with-the-override-and-new-keywords)和[了解何时使用 Override 和 New 关键字](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/knowing-when-to-use-override-and-new-keywords)。

### 示例

此示例定义一个名为 `Employee` 的基类和一个名为 `SalesEmployee` 的派生类。 `SalesEmployee` 类包含一个额外字段 `salesbonus`，并且重写方法 `CalculatePay` 以将它考虑在内。

C#复制

```csharp
class TestOverride
{
    public class Employee
    {
        public string name;

        // Basepay is defined as protected, so that it may be 
        // accessed only by this class and derived classes.
        protected decimal basepay;

        // Constructor to set the name and basepay values.
        public Employee(string name, decimal basepay)
        {
            this.name = name;
            this.basepay = basepay;
        }

        // Declared virtual so it can be overridden.
        public virtual decimal CalculatePay()
        {
            return basepay;
        }
    }

    // Derive a new class from Employee.
    public class SalesEmployee : Employee
    {
        // New field that will affect the base pay.
        private decimal salesbonus;

        // The constructor calls the base-class version, and
        // initializes the salesbonus field.
        public SalesEmployee(string name, decimal basepay, 
                  decimal salesbonus) : base(name, basepay)
        {
            this.salesbonus = salesbonus;
        }

        // Override the CalculatePay method 
        // to take bonus into account.
        public override decimal CalculatePay()
        {
            return basepay + salesbonus;
        }
    }

    static void Main()
    {
        // Create some new employees.
        SalesEmployee employee1 = new SalesEmployee("Alice", 
                      1000, 500);
        Employee employee2 = new Employee("Bob", 1200);

        Console.WriteLine("Employee4 " + employee1.name + 
                  " earned: " + employee1.CalculatePay());
        Console.WriteLine("Employee4 " + employee2.name + 
                  " earned: " + employee2.CalculatePay());
    }
}
/*
    Output:
    Employee4 Alice earned: 1500
    Employee4 Bob earned: 1200
*/
```

## [readonly](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/readonly)

`readonly` 关键字是一个可在三个上下文中使用的修饰符：

- 在[字段声明](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/readonly#readonly-field-example)中，`readonly` 指示只能在声明期间或在同一个类的构造函数中向字段赋值。
- 在 [`readonly struct` 定义](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/readonly#readonly-struct-example)中，`readonly` 指示 `struct` 是不可变的。
- 在 [`ref readonly` 方法返回](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/readonly#ref-readonly-return-example)中，`readonly` 修饰符指示该方法返回一个引用，且不允许向该引用写入内容。

C# 7.2 中添加了最后两个上下文。

### Readonly 字段示例

在此示例中，即使在类构造函数中给字段 `year` 赋了值，它的值仍无法在 `ChangeYear` 方法中更改：

C#复制

```csharp
class Age
{
    readonly int year;
    Age(int year)
    {
        this.year = year;
    }
    void ChangeYear()
    {
        //year = 1967; // Compile error if uncommented.
    }
}
```

只能在下列上下文中对 `readonly` 字段进行赋值：

- 在声明中初始化变量时，例如：

C#复制

```csharp
public readonly int y = 5;
```

- 在包含实例字段声明的类的实例构造函数中。
- 在包含静态字段声明的类的静态构造函数中。

只有在这些构造函数上下文中，将 `readonly` 字段作为 [out](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/out-parameter-modifier) 或 [ref](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ref) 参数传递才有效。

 备注

`readonly` 关键字不同于 [const](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/const) 关键字。 `const` 字段只能在该字段的声明中初始化。 可以在字段声明和任何构造函数中多次分配 `readonly` 字段。 因此，根据所使用的构造函数，`readonly` 字段可能具有不同的值。 另外，虽然 `const` 字段是编译时常量，但 `readonly` 字段可用于运行时常量，如下面的示例所示：

C#复制

```csharp
public static readonly uint timeStamp = (uint)DateTime.Now.Ticks;
```

C#复制

```csharp
class SampleClass
{
    public int x;
    // Initialize a readonly field
    public readonly int y = 25;
    public readonly int z;

    public SampleClass()
    {
        // Initialize a readonly instance field
        z = 24;
    }

    public SampleClass(int p1, int p2, int p3)
    {
        x = p1;
        y = p2;
        z = p3;
    }

    public static void Main()
    {
        SampleClass p1 = new SampleClass(11, 21, 32);   // OK
        Console.WriteLine($"p1: x={p1.x}, y={p1.y}, z={p1.z}");
        SampleClass p2 = new SampleClass();
        p2.x = 55;   // OK
        Console.WriteLine($"p2: x={p2.x}, y={p2.y}, z={p2.z}");
    }
    /*
     Output:
        p1: x=11, y=21, z=32
        p2: x=55, y=25, z=24
    */
}
```

在前面的示例中，如果使用类似以下示例的语句：

```
p2.y = 66; // Error
```

将收到编译器错误消息：

```
A readonly field cannot be assigned to (except in a constructor or a variable initializer)
```

### 只读结构示例

`struct` 定义上的 `readonly` 修饰符声明该结构是不可变的。 `struct` 的每个实例字段都必须被标记为 `readonly`，如下例所示：

C#复制

```csharp
public readonly struct Point
{
    public double X { get; }
    public double Y { get; }

    public Point(double x, double y) => (X, Y) = (x, y);

    public override string ToString() => $"({X}, {Y})";
}
```

前面的示例使用[只读自动属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/properties#read-only)来声明其存储。 该操作指示编译器为这些属性创建 `readonly` 支持字段。 还可以直接声明 `readonly` 字段：

C#复制

```csharp
public readonly struct Point
{
    public readonly double X;
    public readonly double Y;

    public Point(double x, double y) => (X, Y) = (x, y);

    public override string ToString() => $"({X}, {Y})";
}
```

添加未标记 `readonly` 的字段会生成编译器错误 `CS8340`：“只读结构的实例字段必须为只读。”

### Ref readonly 返回示例

`ref return` 上的 `readonly` 修饰符指示返回的引用无法修改。 下面的示例返回了一个对来源的引用。 它使用 `readonly` 修饰符来指示调用方无法修改来源：

C#复制

```csharp
private static readonly Point origin = new Point(0, 0);
public static ref readonly Point Origin => ref origin;
```

所返回的类型不需要为 `readonly struct`。 `ref` 能返回的任何类型都能由 `ref readonly` 返回

## [sealed](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/sealed)

应用于某个类时，`sealed` 修饰符可阻止其他类继承自该类。 在下面的示例中，类 `B` 继承自类 `A`，但没有类可以继承自类 `B`。

C#复制

```csharp
class A {}
sealed class B : A {}
```

还可以对替代基类中的虚方法或属性的方法或属性使用 `sealed` 修饰符。 这使你可以允许类派生自你的类并防止它们替代特定虚方法或属性。

### 示例

在下面的示例中，`Z` 继承自 `Y`，但 `Z` 无法替代在 `X` 中声明并在 `Y` 中密封的虚函数 `F`。

C#复制

```csharp
class X
{
    protected virtual void F() { Console.WriteLine("X.F"); }
    protected virtual void F2() { Console.WriteLine("X.F2"); }
}

class Y : X
{
    sealed protected override void F() { Console.WriteLine("Y.F"); }
    protected override void F2() { Console.WriteLine("Y.F2"); }
}

class Z : Y
{
    // Attempting to override F causes compiler error CS0239.
    // protected override void F() { Console.WriteLine("Z.F"); }

    // Overriding F2 is allowed.
    protected override void F2() { Console.WriteLine("Z.F2"); }
}
```

在类中定义新方法或属性时，可以通过不将它们声明为[虚拟](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/virtual)，来防止派生类替代它们。

将 [abstract](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/abstract) 修饰符与密封类结合使用是错误的，因为抽象类必须由提供抽象方法或属性的实现的类来继承。

应用于方法或属性时，`sealed` 修饰符必须始终与 [override](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/override) 结合使用。

因为结构是隐式密封的，所以无法继承它们。

有关详细信息，请参阅[继承](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/inheritance)。

有关更多示例，请参阅[抽象类、密封类及类成员](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/abstract-and-sealed-classes-and-class-members)。

### 示例

C#复制

```csharp
sealed class SealedClass
{
    public int x;
    public int y;
}

class SealedTest2
{
    static void Main()
    {
        SealedClass sc = new SealedClass();
        sc.x = 110;
        sc.y = 150;
        Console.WriteLine("x = {0}, y = {1}", sc.x, sc.y);
    }
}
// Output: x = 110, y = 150
```

在上面的示例中，可能会尝试使用以下语句从密封类继承：

```
class MyDerivedC: SealedClass {} // Error
```

结果是出现错误消息：

```
'MyDerivedC': cannot derive from sealed type 'SealedClass'
```

### 备注

若要确定是否密封类、方法或属性，通常应考虑以下两点：

- 派生类通过可以自定义类而可能获得的潜在好处。
- 派生类可能采用使它们无法再正常工作或按预期工作的方式来修改类的可能性。

## [static](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/static)

使用 `static` 修饰符可声明属于类型本身而不是属于特定对象的静态成员。 `static` 修饰符可用于类、字段、方法、属性、运算符、事件和构造函数，但不能用于索引器、终结器或类以外的类型。 有关详细信息，请参阅[静态类和静态类成员](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/static-classes-and-static-class-members)。

### 示例

下面的类声明为 `static` 并且只含 `static` 方法：

C#复制

```csharp
static class CompanyEmployee
{
    public static void DoSomething() { /*...*/ }
    public static void DoSomethingElse() { /*...*/  }
}
```

常量或类型声明是隐式的静态成员。

不能通过实例引用静态成员。 然而，可以通过类型名称引用它。 例如，请考虑以下类：

C#复制

```csharp
public class MyBaseC
{
    public struct MyStruct
    {
        public static int x = 100;
    }
}
```

若要引用静态成员 `x`，除非可从相同范围访问该成员，否则请使用完全限定的名称 `MyBaseC.MyStruct.x`：

C#复制

```csharp
Console.WriteLine(MyBaseC.MyStruct.x);
```

尽管类的实例包含该类的所有实例字段的单独副本，但每个静态字段只有一个副本。

不可以使用 [this](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/this) 引用静态方法或属性访问器。

如果 `static` 关键字应用于类，则类的所有成员都必须是静态的。

类和静态类可以包含静态构造函数。 在程序开始和实例化类之间的某个时刻调用静态构造函数。

 备注

`static` 关键字比用于 C++ 中时受到的限制更多。 若要与 C++ 关键字进行比较，请参阅 [Storage classes (C++)](https://docs.microsoft.com/zh-cn/cpp/cpp/storage-classes-cpp#static)（存储类 (C++)）。

若要演示静态成员，请考虑表示公司员工的类。 假定此类包含计数员工的方法和存储员工人数的字段。 方法和字段均不属于任何实例员工。 而属于公司类。 因此，它们应声明为类的静态成员。

### 示例

此示例读取新员工的姓名和 ID，员工计数器按 1 递增，并显示新员工信息和新员工人数。 为简单起见，此程序从键盘读取员工的当前人数。 在实际应用程序中，应从文件读取该信息。

C#复制

```csharp
public class Employee4
{
    public string id;
    public string name;

    public Employee4()
    {
    }

    public Employee4(string name, string id)
    {
        this.name = name;
        this.id = id;
    }

    public static int employeeCounter;

    public static int AddEmployee()
    {
        return ++employeeCounter;
    }
}

class MainClass : Employee4
{
    static void Main()
    {
        Console.Write("Enter the employee's name: ");
        string name = Console.ReadLine();
        Console.Write("Enter the employee's ID: ");
        string id = Console.ReadLine();

        // Create and configure the employee object:
        Employee4 e = new Employee4(name, id);
        Console.Write("Enter the current number of employees: ");
        string n = Console.ReadLine();
        Employee4.employeeCounter = Int32.Parse(n);
        Employee4.AddEmployee();

        // Display the new information:
        Console.WriteLine("Name: {0}", e.name);
        Console.WriteLine("ID:   {0}", e.id);
        Console.WriteLine("New Number of Employees: {0}",
                  Employee4.employeeCounter);
    }
}
/*
Input:
Matthias Berndt
AF643G
15
 * 
Sample Output:
Enter the employee's name: Matthias Berndt
Enter the employee's ID: AF643G
Enter the current number of employees: 15
Name: Matthias Berndt
ID:   AF643G
New Number of Employees: 16
*/
```

### 示例

此示例显示，尽管可以使用尚未声明的其他静态字段来初始化某个静态字段，但除非向该静态字段显式分配值，否则不会定义该结果。

C#复制

```csharp
class Test
{
    static int x = y;
    static int y = 5;

    static void Main()
    {
        Console.WriteLine(Test.x);
        Console.WriteLine(Test.y);

        Test.x = 99;
        Console.WriteLine(Test.x);
    }
}
/*
Output:
    0
    5
    99
*/
```

## [unsafe](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/unsafe)

`unsafe` 关键字表示不安全上下文，该上下文是任何涉及指针的操作所必需的。 有关详细信息，请参阅[不安全代码和指针](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/unsafe-code-pointers/index)。

可在类型或成员的声明中使用 `unsafe` 修饰符。 因此，类型或成员的整个正文范围均被视为不安全上下文。 以下面使用 `unsafe` 修饰符声明的方法为例：

C#复制

```csharp
unsafe static void FastCopy(byte[] src, byte[] dst, int count)
{
    // Unsafe context: can use pointers here.
}
```

不安全上下文的范围从参数列表扩展到方法的结尾，因此也可在以下参数列表中使用指针：

C#复制

```csharp
unsafe static void FastCopy ( byte* ps, byte* pd, int count ) {...}
```

还可以使用不安全块从而能够使用该块内的不安全代码。 例如:

C#复制

```csharp
unsafe
{
    // Unsafe context: can use pointers here.
}
```

若要编译不安全代码，必须指定 [/unsafe](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/unsafe-compiler-option) 编译器选项。 不能通过公共语言运行时验证不安全代码。

### 示例

C#复制

```csharp
// compile with: -unsafe
class UnsafeTest
{
    // Unsafe method: takes pointer to int:
    unsafe static void SquarePtrParam(int* p)
    {
        *p *= *p;
    }

    unsafe static void Main()
    {
        int i = 5;
        // Unsafe method: uses address-of operator (&):
        SquarePtrParam(&i);
        Console.WriteLine(i);
    }
}
// Output: 25
```

## [virtual](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/virtual)

`virtual` 关键字用于修改方法、属性、索引器或事件声明，并使它们可以在派生类中被重写。 例如，此方法可被任何继承它的类替代：

C#复制

```csharp
public virtual double Area() 
{
    return x * y;
}
```

虚拟成员的实现可由派生类中的[替代成员](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/override)更改。 有关如何使用 `virtual` 关键字的详细信息，请参阅[使用 Override 和 New 关键字进行版本控制](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/versioning-with-the-override-and-new-keywords)和[了解何时使用 Override 和 New 关键字](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/knowing-when-to-use-override-and-new-keywords)。

### 备注

调用虚拟方法时，将为替代的成员检查该对象的运行时类型。 将调用大部分派生类中的该替代成员，如果没有派生类替代该成员，则它可能是原始成员。

默认情况下，方法是非虚拟的。 不能替代非虚方法。

`virtual` 修饰符不能与 `static`、`abstract``private` 或 `override` 修饰符一起使用。 以下示例显示了虚拟属性：

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

除声明和调用语法不同外，虚拟属性的行为与抽象方法相似。

- 在静态属性上使用 `virtual` 修饰符是错误的。
- 通过包括使用 `override` 修饰符的属性声明，可在派生类中替代虚拟继承属性。

### 示例

在该示例中，`Shape` 类包含 `x`、`y` 两个坐标和 `Area()` 虚拟方法。 不同的形状类（如 `Circle`、`Cylinder`和 `Sphere`）继承 `Shape` 类，并为每个图形计算表面积。 每个派生类都有各自的 `Area()` 替代实现。

请注意，继承的类 `Circle``Sphere` 和 `Cylinder` 均使用初始化基类的构造函数，如下面的声明中所示。

C#复制

```csharp
public Cylinder(double r, double h): base(r, h) {}
```

根据与方法关联的对象，下面的程序通过调用 `Area()` 方法的相应实现来计算并显示每个对象的相应区域。

C#复制

```csharp
class TestClass
{
    public class Shape
    {
        public const double PI = Math.PI;
        protected double x, y;
        
        public Shape()
        {
        }
        
        public Shape(double x, double y)
        {
            this.x = x;
            this.y = y;
        }

        public virtual double Area()
        {
            return x * y;
        }
    }

    public class Circle : Shape
    {
        public Circle(double r) : base(r, 0)
        {
        }

        public override double Area()
        {
            return PI * x * x;
        }
    }

    class Sphere : Shape
    {
        public Sphere(double r) : base(r, 0)
        {
        }

        public override double Area()
        {
            return 4 * PI * x * x;
        }
    }

    class Cylinder : Shape
    {
        public Cylinder(double r, double h) : base(r, h)
        {
        }

        public override double Area()
        {
            return 2 * PI * x * x + 2 * PI * x * y;
        }
    }

    static void Main()
    {
        double r = 3.0, h = 5.0;
        Shape c = new Circle(r);
        Shape s = new Sphere(r);
        Shape l = new Cylinder(r, h);
        // Display results:
        Console.WriteLine("Area of Circle   = {0:F2}", c.Area());
        Console.WriteLine("Area of Sphere   = {0:F2}", s.Area());
        Console.WriteLine("Area of Cylinder = {0:F2}", l.Area());
    }
}
/*
Output:
Area of Circle   = 28.27
Area of Sphere   = 113.10
Area of Cylinder = 150.80
*/
```

## [volatile](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/volatile)

`volatile` 关键字指示一个字段可以由多个同时执行的线程修改。 出于性能原因，编译器，运行时系统甚至硬件都可能重新排列对存储器位置的读取和写入。 声明了 `volatile` 的字段不进行这些优化。 添加 `volatile` 修饰符可确保所有线程观察易失性写入操作（由任何其他线程执行）时的观察顺序与写入操作的执行顺序一致。 不确保从所有执行线程整体来看时所有易失性写入操作均按执行顺序排序。

`volatile` 关键字可应用于以下类型的字段：

- 引用类型。
- 指针类型（在不安全的上下文中）。 请注意，虽然指针本身可以是可变的，但是它指向的对象不能是可变的。 换句话说，不能声明“指向可变对象的指针”。
- 简单类型，如 `sbyte`、`byte`、`short`、`ushort`、`int`、`uint`、`char`、`float` 和 `bool`。
- 具有以下基本类型之一的 `enum` 类型：`byte`、`sbyte`、`short`、`ushort`、`int` 或 `uint`。
- 已知为引用类型的泛型类型参数。
- [IntPtr](https://docs.microsoft.com/zh-cn/dotnet/api/system.intptr) 和 [UIntPtr](https://docs.microsoft.com/zh-cn/dotnet/api/system.uintptr)。

其他类型（包括 `double` 和 `long`）无法标记为 `volatile`，因为对这些类型的字段的读取和写入不能保证是原子的。 若要保护对这些类型字段的多线程访问，请使用 [Interlocked](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.interlocked) 类成员或使用 [`lock`](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/lock-statement) 语句保护访问权限。

`volatile` 关键字只能应用于 `class` 或 `struct` 的字段。 不能将局部变量声明为 `volatile`。

### 示例

下面的示例说明如何将公共字段变量声明为 `volatile`。

C#复制

```csharp
class VolatileTest
{
    public volatile int sharedStorage;

    public void Test(int _i)
    {
        sharedStorage = _i;
    }
}
```

下面的示例演示如何创建辅助线程，并用它与主线程并行执行处理。 有关多线程处理的详细信息，请参阅[托管线程处理](https://docs.microsoft.com/zh-cn/dotnet/standard/threading/index)。

C#复制

```csharp
public class Worker
{
    // This method is called when the thread is started.
    public void DoWork()
    {
        while (!_shouldStop)
        {
            Console.WriteLine("Worker thread: working...");
        }
        Console.WriteLine("Worker thread: terminating gracefully.");
    }
    public void RequestStop()
    {
        _shouldStop = true;
    }
    // Keyword volatile is used as a hint to the compiler that this data
    // member is accessed by multiple threads.
    private volatile bool _shouldStop;
}

public class WorkerThreadExample
{
    public static void Main()
    {
        // Create the worker thread object. This does not start the thread.
        Worker workerObject = new Worker();
        Thread workerThread = new Thread(workerObject.DoWork);

        // Start the worker thread.
        workerThread.Start();
        Console.WriteLine("Main thread: starting worker thread...");

        // Loop until the worker thread activates.
        while (!workerThread.IsAlive)
            ;

        // Put the main thread to sleep for 1 millisecond to
        // allow the worker thread to do some work.
        Thread.Sleep(1);

        // Request that the worker thread stop itself.
        workerObject.RequestStop();

        // Use the Thread.Join method to block the current thread 
        // until the object's thread terminates.
        workerThread.Join();
        Console.WriteLine("Main thread: worker thread has terminated.");
    }
    // Sample output:
    // Main thread: starting worker thread...
    // Worker thread: working...
    // Worker thread: working...
    // Worker thread: working...
    // Worker thread: working...
    // Worker thread: working...
    // Worker thread: working...
    // Worker thread: terminating gracefully.
    // Main thread: worker thread has terminated.
}
```

将 `volatile` 修饰符添加到 `_shouldStop` 的声明后，将始终获得相同的结果（类似于前面代码中显示的片段）。但是，如果 `_shouldStop` 成员上没有该修饰符，则行为是不可预测的。 `DoWork` 方法可能会优化成员访问，从而导致读取陈旧数据。 鉴于多线程编程的性质，读取陈旧数据的次数是不可预测的。 不同的程序运行会产生一些不同的结果。