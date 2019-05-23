# [Programming Concepts](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/)

## [Object-Oriented Programming](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/object-oriented-programming)

C# 提供对面向对象的编程（包括封装、继承和多形性）的完整支持。

“封装”意味着将一组相关属性、方法和其他成员视为一个单元或对象。

“继承”描述基于现有类创建新类的能力。

多态性意味着可以有多个可互换使用的类，即使每个类以不同方式实现相同属性或方法。

本节介绍下列概念：

- [类和对象](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/object-oriented-programming#Classes)

  - [类成员](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/object-oriented-programming#Members)

    [属性和字段](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/object-oriented-programming#Properties)

    [方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/object-oriented-programming#Methods)

    [构造函数](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/object-oriented-programming#Constructors)

    [终结器](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/object-oriented-programming#Finalizers)

    [事件](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/object-oriented-programming#Events)

    [嵌套类](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/object-oriented-programming#NestedClasses)

  - [访问修饰符和访问级别](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/object-oriented-programming#AccessModifiers)

  - [实例化类](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/object-oriented-programming#InstantiatingClasses)

  - [静态类和成员](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/object-oriented-programming#Static)

  - [匿名类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/object-oriented-programming#AnonymousTypes)

- [继承](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/object-oriented-programming#Inheritance)

  - [重写成员](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/object-oriented-programming#Overriding)

- [接口](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/object-oriented-programming#Interfaces)

- [泛型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/object-oriented-programming#Generics)

- [委托](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/object-oriented-programming#Delegates)

### 类和对象

“类”和“对象”这两个术语有时互换使用，但实际上，类描述对象的“类型”，而对象是类的可用“实例”。 因此，创建对象的操作称为“实例化”。 如果使用蓝图类比，类是蓝图，对象就是基于该蓝图的建筑。

定义类：

```csharp
class SampleClass  
{  
}  
```

C# 还提供了类的轻量版本，称为“结构”。当需要创建大量对象但不希望因此占用太多内存时，可以使用此轻量版本。

定义结构：

```csharp
struct SampleStruct  
{  
}  
```

有关详细信息，请参见:

- [class](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/class)
- [struct](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/struct)

#### 类成员

每个类都可以具有不同的“类成员”。类成员包括属性（用于描述类数据）、方法（用于定义类行为）和事件（用于在不同的类和对象之间提供通信）。

##### 属性和字段

字段和属性表示对象包含的信息。 字段类似于变量，因为可以直接读取或设置它们。

定义字段：

```csharp
class SampleClass  
{  
    public string sampleField;  
}  
```

属性具有 get 和 set 过程，它们对如何设置或返回值提供更多的控制。

C# 允许你创建私有字段来存储属性值，或者使用常说的“自动实现的属性”，这些属性自动在后台创建此字段，并为属性过程提供基本逻辑。

定义自动实现的属性：

```csharp
class SampleClass  
{  
    public int SampleProperty { get; set; }  
}  
```

如果你需要执行一些其他操作来读取和写入属性值，请定义一个用于存储属性值的字段，并提供用于存储和检索该字段的基本逻辑：

```csharp
class SampleClass  
{  
    private int _sample;  
    public int Sample  
    {  
        // Return the value stored in a field.  
        get { return _sample; }  
        // Store the value in the field.  
        set { _sample = value; }  
    }  
}  
```

大多数属性的方法或过程都是既可以设置也可以获取属性值。 但你可以创建只读或只写属性来限制对它们的修改或读取。 在 C# 中，可以忽略 `get` 或 `set` 属性方法。 但是，自动实现的属性不能为只读或只写。

有关详细信息，请参见:

- [get](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/get)
- [set](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/set)

##### 方法

“方法”是对象可以执行的操作。

定义类的方法：

```csharp
class SampleClass  
{  
    public int sampleMethod(string sampleParam)  
    {  
        // Insert code here  
    }  
}  
```

对于同一方法，一个类可以有多个实现，也叫“重载”，这些实现的区别在于参数个数或参数类型的不同。

重载方法：

```csharp
public int sampleMethod(string sampleParam) {};  
public int sampleMethod(int sampleParam) {}  
```

大多数情况下，方法是在类定义中声明的。 但是，C# 还支持“扩展方法”，这种方法允许你将方法添加到实际类定义之外的现有类中。

有关详细信息，请参见:

- [方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/methods)
- [扩展方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/extension-methods)

##### 构造函数

构造函数一种类方法，它们在创建给定类型的对象时自动执行。 构造函数通常用于初始化新对象的数据成员。 构造函数只能在创建类时运行一次。 此外，构造函数中的代码始终在类中所有其他代码之前运行。 但是，你可以按照为任何其他方法创建重载的方式，创建多个构造函数重载。

定义类的构造函数：

```csharp
public class SampleClass  
{  
    public SampleClass()  
    {  
        // Add code here  
    }  
}  
```

有关详细信息，请参见:

[构造函数](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/constructors)。

##### 终结器

终结器用于析构类的实例。 在 .NET Framework 中，垃圾回收器自动管理应用程序中托管对象的内存分配和释放。但是，你可能仍会需要终结器来清理应用程序创建的所有非托管资源。 一个类只能有一个终结器。

有关终结器和 .NET Framework 垃圾回收的详细信息，请参阅[垃圾回收](https://docs.microsoft.com/zh-cn/dotnet/standard/garbage-collection/index)。

##### 事件

类或对象可以通过事件向其他类或对象通知发生的相关事情。 发送（或引发）事件的类称为“发行者”，接收（或处理）事件的类称为“订户”。 有关事件以及如何引发和处理事件的详细信息，请参阅[事件](https://docs.microsoft.com/zh-cn/dotnet/standard/events/index)。

- 若要在类中声明事件，请使用 [event](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/event) 关键字。
- 若要引发事件，请调用事件委托。
- 若要订阅事件，请使用 `+=` 运算符；若要取消订阅事件，请使用 `-=` 运算符。

#### 嵌套类

在另一个类中定义的类称为“嵌套”。 默认情况下，嵌套类是私有类。

```csharp
class Container  
{  
    class Nested  
    {  
        // Add code here.  
    }  
}  
```

若要创建嵌套类的实例，请使用容器类的名称，后接一个点，再接嵌套类的名称：

```csharp
Container.Nested nestedInstance = new Container.Nested()  
```

#### 访问修饰符和访问级别

所有类和类方法都可以使用“访问修饰符”指定自己为其他类提供的访问级别。

可用的访问修饰符有以下这些：

| C# 修饰符                                                    | 定义                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [public](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/public) | 同一程序集中的任何其他代码或引用该程序集的其他程序集都可以访问该类型或成员。 |
| [private](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/private) | 只有同一类中的代码可以访问该类型或成员。                     |
| [protected](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/protected) | 只有同一类或派生类中的代码可以访问该类型或成员。             |
| [internal](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/internal) | 同一程序集中的任何代码都可以访问该类型或成员，但其他程序集中的代码不可以。 |
| [protected internal](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/protected-internal) | 同一程序集中的任何代码或其他程序集中的任何派生类都可以访问该类型或成员。 |
| [private protected](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/private-protected) | 同一类或基类程序集内派生类中的代码可以访问该类型或成员。     |

有关详细信息，请参阅[访问修饰符](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/access-modifiers)。

#### 实例化类

若要创建对象，你需要实例化类，即创建类实例。

```csharp
SampleClass sampleObject = new SampleClass();  
```

实例化类之后，可以为该实例的属性和字段赋值，还可以调用类方法。

```csharp
// Set a property value.  
sampleObject.sampleProperty = "Sample String";  
// Call a method.  
sampleObject.sampleMethod();  
```

若要在类的实例化过程中为属性赋值，请使用对象初始值设定项：

```csharp
// Set a property value.  
SampleClass sampleObject = new SampleClass   
    { FirstProperty = "A", SecondProperty = "B" };  
```

有关详细信息，请参见:

- [new 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/new-operator)
- [对象和集合初始值设定项](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/object-and-collection-initializers)

#### 静态类和成员

类的静态成员是指由该类的所有实例共享的属性、过程或字段。

定义静态成员：

```csharp
static class SampleClass  
{  
    public static string SampleString = "Sample String";  
}  
```

若要访问静态成员，请使用类的名称，但不要创建此类的对象：

```csharp
Console.WriteLine(SampleClass.SampleString);  
```

C# 中的静态类只有静态成员，无法进行实例化。 静态成员也无法访问非静态属性、字段或方法

有关详细信息，请参阅：[static](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/static)。

#### 匿名类型

匿名类型使你无需为数据类型编写类定义即可创建对象。 此时，编译器将为你生成类。 该类没有可使用的名称，且包含在声明对象时指定的属性。

创建匿名类型的实例：

```csharp
// sampleObject is an instance of a simple anonymous type.  
var sampleObject =   
    new { FirstProperty = "A", SecondProperty = "B" };  
```

有关详细信息，请参见:[匿名类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/anonymous-types)。

### 继承

通过继承，可以创建一个新类，它重用、扩展和修改另一个类中定义的行为。 其成员被继承的类称为“基类”，继承这些成员的类称为“派生类”。 但是，C# 中的所有类都隐式继承自 [Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object) 类，该类支持 .NET 类层次结构，并为所有类提供低级别服务。

> C# 不支持多重继承。 即，只能为一个派生类指定一个基类。

从基类继承：

```csharp
class DerivedClass:BaseClass {}  
```

默认情况下，可以继承所有类。 但你可以指定不得将某个类用作基类，也可以创建只能用作基类的类。

指定不得将某个类用作基类：

```csharp
public sealed class A { }  
```

指定只能用作基类且无法实例化的类：

```csharp
public abstract class B { }  
```

有关详细信息，请参见:

- [sealed](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/sealed)
- [abstract](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/abstract)

### 重写成员

默认情况下，派生类继承其基类的所有成员。 若希望更改继承成员的行为，则需要重写该成员。 即，可以在派生类中定义方法、属性或事件的新实现。

下列修饰符用于控制如何重写属性和方法：

| C# 修饰符                                                    | 定义                                 |
| ------------------------------------------------------------ | ------------------------------------ |
| [virtual](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/virtual) | 允许在派生类中重写类成员。           |
| [override](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/override) | 重写基类中定义的虚拟（可重写）成员。 |
| [abstract](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/abstract) | 要求在派生类中重写类成员。           |
| [new 修饰符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/new-modifier) | 隐藏继承自基类的成员                 |

### 接口

和类一样，接口也定义了一系列属性、方法和事件。 但与类不同的是，接口并不提供实现。 它们由类来实现，并从类中被定义为单独的实体。 接口表示一种约定，实现接口的类必须严格按其定义来实现接口的每个方面。

定义接口：

```csharp
interface ISampleInterface  
{  
    void doSomething();  
}  
```

在类中实现接口：

```csharp
class SampleClass : ISampleInterface  
{  
    void ISampleInterface.doSomething()  
    {  
        // Method implementation.  
    }  
}  
```

有关详细信息，请参见:

[接口](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/interfaces/index)

[interface](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/interface)

### 泛型

.NET Framework 中的类、结构、接口和方法可以包括“类型参数”，类型参数定义它们可以存储或使用的对象的类型。 最常见的泛型示例是集合，从中可以指定要存储在集合中的对象的类型。

定义泛型类：

```csharp
public class SampleGeneric<T>   
{  
    public T Field;  
}  
```

创建泛型类的实例：

```csharp
SampleGeneric<string> sampleObject = new SampleGeneric<string>();  
sampleObject.Field = "Sample string";  
```

有关详细信息，请参见:

- [泛型](https://docs.microsoft.com/zh-cn/dotnet/standard/generics/index)
- [泛型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/generics/index)

### 委托

“委托”是一种类型，它定义方法签名，可以提供对具有兼容签名的任何方法的引用。 你可以通过委托调用方法。委托用于将方法作为参数传递给其他方法。

> 事件处理程序就是通过委托调用的方法。 有关在事件处理中使用委托的详细信息，请参阅[事件](https://docs.microsoft.com/zh-cn/dotnet/standard/events/index)。

创建委托：

```csharp
public delegate void SampleDelegate(string str);  
```

创建对与委托指定的签名相匹配的方法的引用：

```csharp
class SampleClass  
{  
    // Method that matches the SampleDelegate signature.  
    public static void sampleMethod(string message)  
    {  
        // Add code here.  
    }  
    // Method that instantiates the delegate.  
    void SampleDelegate()  
    {  
        SampleDelegate sd = sampleMethod;  
        sd("Sample string");  
    }  
}  
```

有关详细信息，请参见:

- [委托](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/delegates/index)
- [delegate](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/delegate)