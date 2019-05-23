# [Programming Concepts](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/)

## [Covariance and Contravariance](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/covariance-contravariance/)

在 C# 中，协变和逆变能够实现数组类型、委托类型和泛型类型参数的隐式引用转换。 协变保留分配兼容性，逆变则与之相反。

以下代码演示分配兼容性、协变和逆变之间的差异。

```csharp
// Assignment compatibility.   
string str = "test";  
// An object of a more derived type is assigned to an object of a less derived type.   
object obj = str;  
  
// Covariance.   
IEnumerable<string> strings = new List<string>();  
// An object that is instantiated with a more derived type argument   
// is assigned to an object instantiated with a less derived type argument.   
// Assignment compatibility is preserved.   
IEnumerable<object> objects = strings;  
  
// Contravariance.             
// Assume that the following method is in the class:   
// static void SetObject(object o) { }   
Action<object> actObject = SetObject;  
// An object that is instantiated with a less derived type argument   
// is assigned to an object instantiated with a more derived type argument.   
// Assignment compatibility is reversed.   
Action<string> actString = actObject;  
```

数组的协变使派生程度更大的类型的数组能够隐式转换为派生程度更小的类型的数组。 但是此操作不是类型安全的操作，如以下代码示例所示。

```csharp
object[] array = new String[10];  
// The following statement produces a run-time exception.  
// array[0] = 10;  
```

对方法组的协变和逆变支持允许将方法签名与委托类型相匹配。 这样，不仅可以将具有匹配签名的方法分配给委托，还可以分配与委托类型指定的派生类型相比，返回派生程度更大的类型的方法（协变）或接受具有派生程度更小的类型的参数的方法（逆变）。 有关详细信息，请参阅[委托中的变体 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/covariance-contravariance/variance-in-delegates) 和[使用委托中的变体 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/covariance-contravariance/using-variance-in-delegates)。

以下代码示例演示对方法组的协变和逆变支持。

```csharp
static object GetObject() { return null; }  
static void SetObject(object obj) { }  
  
static string GetString() { return ""; }  
static void SetString(string str) { }  
  
static void Test()  
{  
    // Covariance. A delegate specifies a return type as object,  
    // but you can assign a method that returns a string.  
    Func<object> del = GetString;  
  
    // Contravariance. A delegate specifies a parameter type as string,  
    // but you can assign a method that takes an object.  
    Action<string> del2 = SetObject;  
}  
```

在 .NET Framework 4 或较新的 C# 中，支持在泛型接口和委托中使用协变和逆变，并允许隐式转换泛型类型参数。 有关详细信息，请参阅[泛型接口中的变体 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/covariance-contravariance/variance-in-generic-interfaces) 和[委托中的变体 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/covariance-contravariance/variance-in-delegates)。

以下代码示例演示泛型接口的隐式引用转换。

```csharp
IEnumerable<String> strings = new List<String>();  
IEnumerable<Object> objects = strings;  
```

如果泛型接口或委托的泛型参数被声明为协变或逆变，该泛型接口或委托则被称为“变体”。 凭借 C#，能够创建自己的变体接口和委托。 有关详细信息，请参阅[创建变体泛型接口 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/covariance-contravariance/creating-variant-generic-interfaces) 和[委托中的变体 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/covariance-contravariance/variance-in-delegates)。

### [Variance in Generic Interfaces](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/covariance-contravariance/variance-in-generic-interfaces)

.NET Framework 4 引入了对多个现有泛型接口的变体支持。 变体支持允许实现这些接口的类进行隐式转换。 下面的接口现在是变体：

- [IEnumerable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1)（T 是协变）
- [IEnumerator<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerator-1)（T 是协变）
- [IQueryable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.iqueryable-1)（T 是协变）
- [IGrouping<TKey,TElement>](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.igrouping-2)（`TKey` 和 `TElement` 都是协变）
- [IComparer<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.icomparer-1)（T 是逆变）
- [IEqualityComparer<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.iequalitycomparer-1)（T 是逆变）
- [IComparable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.icomparable-1)（T 是逆变）

协变允许方法具有的返回类型比接口的泛型类型参数定义的返回类型的派生程度更大。 若要演示协变功能，请考虑以下泛型接口：`IEnumerable<Object>` 和 `IEnumerable<String>`。 `IEnumerable<String>` 接口不继承 `IEnumerable<Object>` 接口。 但是，`String` 类型会继承 `Object` 类型，在某些情况下，建议为这些接口互相指派彼此的对象。 下面的代码示例对此进行了演示。

```csharp
IEnumerable<String> strings = new List<String>();  
IEnumerable<Object> objects = strings;  
```

在 .NET Framework 早期版本中，在 `Option Strict On` 条件下，此代码会导致 C# 中出现编译错误。 但现在可使用 `strings` 代替 `objects`，如上例所示，因为 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 接口是协变接口。

逆变允许方法具有的实参类型比接口的泛型形参定义的类型的派生程度更小。 若要演示逆变，假设已创建了 `BaseComparer` 类来比较 `BaseClass` 类的实例。 `BaseComparer` 类实现 `IEqualityComparer<BaseClass>` 接口。 因为 [IEqualityComparer](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.iequalitycomparer-1) 接口现在是逆变接口，因此可使用 `BaseComparer` 比较继承 `BaseClass` 类的类的实例。下面的代码示例对此进行了演示。

```csharp
// Simple hierarchy of classes.  
class BaseClass { }  
class DerivedClass : BaseClass { }  
  
// Comparer class.  
class BaseComparer : IEqualityComparer<BaseClass>   
{  
    public int GetHashCode(BaseClass baseInstance)  
    {  
        return baseInstance.GetHashCode();  
    }  
    public bool Equals(BaseClass x, BaseClass y)  
    {  
        return x == y;  
    }  
}  
class Program  
{  
    static void Test()  
    {  
        IEqualityComparer<BaseClass> baseComparer = new BaseComparer();  
  
        // Implicit conversion of IEqualityComparer<BaseClass> to   
        // IEqualityComparer<DerivedClass>.  
        IEqualityComparer<DerivedClass> childComparer = baseComparer;  
    }  
}  
```

有关更多示例，请参阅[在泛型集合的接口中使用变体 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/covariance-contravariance/using-variance-in-interfaces-for-generic-collections)。

只有引用类型才支持使用泛型接口中的变体。 值类型不支持变体。 例如，无法将 `IEnumerable<int>` 隐式转换为 `IEnumerable<object>`，因为整数由值类型表示。

```csharp
IEnumerable<int> integers = new List<int>();  
// The following statement generates a compiler errror,  
// because int is a value type.  
// IEnumerable<Object> objects = integers;  
```

还需记住，实现变体接口的类仍是固定类。 例如，虽然 [List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1) 实现协变接口 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1)，但不能将 `List<Object>` 隐式转换为 `List<String>`。 以下代码示例阐释了这一点。

```csharp
// The following line generates a compiler error  
// because classes are invariant.  
// List<Object> list = new List<String>();  
  
// You can use the interface object instead.  
IEnumerable<Object> listObjects = new List<String>();  
```

#### [Creating Variant Generic Interfaces](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/covariance-contravariance/creating-variant-generic-interfaces)

接口中的泛型类型参数可以声明为协变或逆变。 协变允许接口方法具有与泛型类型参数定义的返回类型相比，派生程度更大的返回类型。 逆变允许接口方法具有与泛型形参指定的实参类型相比，派生程度更小的实参类型。 具有协变或逆变泛型类型参数的泛型接口称为“变体”。

> .NET Framework 4 引入了对多个现有泛型接口的变体支持。 有关 .NET Framework 中变体接口的列表，请参阅[泛型接口中的变体 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/covariance-contravariance/variance-in-generic-interfaces)。

##### 声明变体泛型接口

可通过对泛型类型参数使用 `in` 和 `out` 关键字来声明变体泛型接口。

> C# 中的 `ref`、`in` 和 `out` 参数不能为变体。 值类型也不支持变体。

可以使用 `out` 关键字将泛型类型参数声明为协变。 协变类型必须满足以下条件：

- 类型仅用作接口方法的返回类型，不用作方法参数的类型。 下例演示了此要求，其中类型 `R` 为声明的协变。

  ```csharp
  interface ICovariant<out R>  
  {  
      R GetSomething();  
      // The following statement generates a compiler error.  
      // void SetSometing(R sampleArg);  
  
  }  
  ```

  此规则有一个例外。 如果具有用作方法参数的逆变泛型委托，则可将类型用作该委托的泛型类型参数。 下例中的类型 `R` 演示了此情形。 有关详细信息，请参阅[委托中的变体 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/covariance-contravariance/variance-in-delegates) 和[对 Func 和 Action 泛型委托使用变体 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/covariance-contravariance/using-variance-for-func-and-action-generic-delegates)。

  ```csharp
  interface ICovariant<out R>  
  {  
      void DoSomething(Action<R> callback);  
  }  
  ```

- 类型不用作接口方法的泛型约束。 下面的代码阐释了这一点。

  ```csharp
  interface ICovariant<out R>  
  {  
      // The following statement generates a compiler error  
      // because you can use only contravariant or invariant types  
      // in generic contstraints.  
      // void DoSomething<T>() where T : R;  
  }  
  ```

可以使用 `in` 关键字将泛型类型参数声明为逆变。 逆变类型只能用作方法参数的类型，不能用作接口方法的返回类型。 逆变类型还可用于泛型约束。 以下代码演示如何声明逆变接口，以及如何将泛型约束用于其方法之一。

```csharp
interface IContravariant<in A>  
{  
    void SetSomething(A sampleArg);  
    void DoSomething<T>() where T : A;  
    // The following statement generates a compiler error.  
    // A GetSomething();              
}  
```

此外，还可以在同一接口中同时支持协变和逆变，但需应用于不同的类型参数，如以下代码示例所示。

```csharp
interface IVariant<out R, in A>  
{  
    R GetSomething();  
    void SetSomething(A sampleArg);  
    R GetSetSometings(A sampleArg);  
}  
```

##### 实现变体泛型接口

在类中实现变体泛型接口时，所用语法和用于固定接口的语法相同。 以下代码示例演示如何在泛型类中实现协变接口。

```csharp
interface ICovariant<out R>  
{  
    R GetSomething();  
}  
class SampleImplementation<R> : ICovariant<R>  
{  
    public R GetSomething()  
    {  
        // Some code.  
        return default(R);  
    }  
}  
```

实现变体接口的类是固定类。 例如，考虑下面的代码。

```csharp
// The interface is covariant.  
ICovariant<Button> ibutton = new SampleImplementation<Button>();  
ICovariant<Object> iobj = ibutton;  
  
// The class is invariant.  
SampleImplementation<Button> button = new SampleImplementation<Button>();  
// The following statement generates a compiler error  
// because classes are invariant.  
// SampleImplementation<Object> obj = button;  
```

##### 扩展变体泛型接口

扩展变体泛型接口时，必须使用 `in` 和 `out` 关键字来显式指定派生接口是否支持变体。 编译器不会根据正在扩展的接口来推断变体。 例如，考虑以下接口。

```csharp
interface ICovariant<out T> { }  
interface IInvariant<T> : ICovariant<T> { }  
interface IExtCovariant<out T> : ICovariant<T> { }  
```

尽管 `IInvariant<T>` 接口和 `IExtCovariant<out T>` 接口扩展的是同一个接口，但泛型类型参数 `T` 在前者中为固定参数，在后者中为协变参数。 此规则也适用于逆变泛型类型参数。

无论泛型类型参数 `T` 在接口中是协变还是逆变，都可以创建一个接口来扩展这两类接口，只要在扩展接口中，该 `T` 泛型类型参数为固定参数。 以下代码示例阐释了这一点。

```csharp
interface ICovariant<out T> { }  
interface IContravariant<in T> { }  
interface IInvariant<T> : ICovariant<T>, IContravariant<T> { }  
```

但是，如果泛型类型参数 `T` 在一个接口中声明为协变，则无法在扩展接口中将其声明为逆变，反之亦然。 以下代码示例阐释了这一点。

```csharp
interface ICovariant<out T> { }  
// The following statement generates a compiler error.  
// interface ICoContraVariant<in T> : ICovariant<T> { }  
```

###### 避免多义性

实现变体泛型接口时，变体有时可能会导致多义性。 应避免这种情况。

例如，如果在一个类中使用不同的泛型类型参数来显式实现同一变体泛型接口，便会产生多义性。 在这种情况下，编译器不会产生错误，但未指定将在运行时选择哪个接口实现。 这可能导致代码中出现微妙的 bug。 请考虑以下代码示例。

```csharp
// Simple class hierarchy.  
class Animal { }  
class Cat : Animal { }  
class Dog : Animal { }  
  
// This class introduces ambiguity  
// because IEnumerable<out T> is covariant.  
class Pets : IEnumerable<Cat>, IEnumerable<Dog>  
{  
    IEnumerator<Cat> IEnumerable<Cat>.GetEnumerator()  
    {  
        Console.WriteLine("Cat");  
        // Some code.  
        return null;  
    }  
  
    IEnumerator IEnumerable.GetEnumerator()  
    {  
        // Some code.  
        return null;  
    }  
  
    IEnumerator<Dog> IEnumerable<Dog>.GetEnumerator()  
    {  
        Console.WriteLine("Dog");  
        // Some code.  
        return null;  
    }  
}  
class Program  
{  
    public static void Test()  
    {  
        IEnumerable<Animal> pets = new Pets();  
        pets.GetEnumerator();  
    }  
}  
```

在此示例中，没有指定 `pets.GetEnumerator` 方法如何在 `Cat` 和 `Dog` 之间选择。 这可能导致代码中出现问题。

#### [Using Variance in Interfaces for Generic Collections](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/covariance-contravariance/using-variance-in-interfaces-for-generic-collections)

协变接口允许其方法返回的派生类型多于接口中指定的派生类型。 逆变接口允许其方法接受派生类型少于接口中指定的类型的参数。

在.NET Framework 4 中，多个现有接口已变为协变和逆变接口。 包括 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 和 [IComparable](https://docs.microsoft.com/zh-cn/dotnet/api/system.icomparable-1)。 这使你可将对基类型的泛型集合进行操作的那些方法重用于派生类型的集合。

有关 .NET Framework 中变体接口的列表，请参阅[泛型接口中的变体 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/covariance-contravariance/variance-in-generic-interfaces)。

##### 转换泛型集合

下例阐释了 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 接口中的协变支持的益处。 `PrintFullName` 方法接受 `IEnumerable<Person>` 类型的集合作为参数。 但可将该方法重用于 `IEnumerable<Employee>` 类型的集合，因为 `Employee` 继承 `Person`。

```csharp
// Simple hierarchy of classes.  
public class Person  
{  
    public string FirstName { get; set; }  
    public string LastName { get; set; }  
}  
  
public class Employee : Person { }  
  
class Program  
{  
    // The method has a parameter of the IEnumerable<Person> type.  
    public static void PrintFullName(IEnumerable<Person> persons)  
    {  
        foreach (Person person in persons)  
        {  
            Console.WriteLine("Name: {0} {1}",  
            person.FirstName, person.LastName);  
        }  
    }  
  
    public static void Test()  
    {  
        IEnumerable<Employee> employees = new List<Employee>();  
  
        // You can pass IEnumerable<Employee>,   
        // although the method expects IEnumerable<Person>.  
  
        PrintFullName(employees);  
  
    }  
}  
```

##### 比较泛型集合

下例阐释了 [IComparer](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.icomparer-1) 接口中的逆变支持的益处。 `PersonComparer` 类实现 `IComparer<Person>` 接口。 但可以重用此类来比较 `Employee` 类型的对象序列，因为 `Employee` 继承 `Person`。

```csharp
// Simple hierarchy of classes.  
public class Person  
{  
    public string FirstName { get; set; }  
    public string LastName { get; set; }  
}  
  
public class Employee : Person { }  
  
// The custom comparer for the Person type  
// with standard implementations of Equals()  
// and GetHashCode() methods.  
class PersonComparer : IEqualityComparer<Person>  
{  
    public bool Equals(Person x, Person y)  
    {              
        if (Object.ReferenceEquals(x, y)) return true;  
        if (Object.ReferenceEquals(x, null) ||  
            Object.ReferenceEquals(y, null))  
            return false;              
        return x.FirstName == y.FirstName && x.LastName == y.LastName;  
    }  
    public int GetHashCode(Person person)  
    {  
        if (Object.ReferenceEquals(person, null)) return 0;  
        int hashFirstName = person.FirstName == null  
            ? 0 : person.FirstName.GetHashCode();  
        int hashLastName = person.LastName.GetHashCode();  
        return hashFirstName ^ hashLastName;  
    }  
}  
  
class Program  
{  
  
    public static void Test()  
    {  
        List<Employee> employees = new List<Employee> {  
               new Employee() {FirstName = "Michael", LastName = "Alexander"},  
               new Employee() {FirstName = "Jeff", LastName = "Price"}  
            };  
  
        // You can pass PersonComparer,   
        // which implements IEqualityComparer<Person>,  
        // although the method expects IEqualityComparer<Employee>.  
  
        IEnumerable<Employee> noduplicates =  
            employees.Distinct<Employee>(new PersonComparer());  
  
        foreach (var employee in noduplicates)  
            Console.WriteLine(employee.FirstName + " " + employee.LastName);  
    }  
}  
```

### [Variance in Delegates](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/covariance-contravariance/variance-in-delegates)

.NET Framework 3.5 引入了变体支持，用于在 C# 中匹配所有委托的方法签名和委托类型。 这表明不仅可以将具有匹配签名的方法分配给委托，还可以将返回多个派生类型（协变）的方法分配给委托，或者将所接受参数的派生类型（逆变）数目比委托类型指定的数目少的方法分配给委托。 这包括泛型委托和非泛型委托。

例如，思考以下代码，该代码具有两个类和两个委托：泛型和非泛型。

```csharp
public class First { }  
public class Second : First { }  
public delegate First SampleDelegate(Second a);  
public delegate R SampleGenericDelegate<A, R>(A a);  
```

创建 `SampleDelegate` 或 `SampleGenericDelegate<A, R>` 类型的委托时，可以将以下任一方法分配给这些委托。

```csharp
// Matching signature.  
public static First ASecondRFirst(Second first)  
{ return new First(); }  
  
// The return type is more derived.  
public static Second ASecondRSecond(Second second)  
{ return new Second(); }  
  
// The argument type is less derived.  
public static First AFirstRFirst(First first)  
{ return new First(); }  
  
// The return type is more derived   
// and the argument type is less derived.  
public static Second AFirstRSecond(First first)  
{ return new Second(); }  
```

以下代码示例说明了方法签名与委托类型之间的隐式转换。

```csharp
// Assigning a method with a matching signature   
// to a non-generic delegate. No conversion is necessary.  
SampleDelegate dNonGeneric = ASecondRFirst;  
// Assigning a method with a more derived return type   
// and less derived argument type to a non-generic delegate.  
// The implicit conversion is used.  
SampleDelegate dNonGenericConversion = AFirstRSecond;  
  
// Assigning a method with a matching signature to a generic delegate.  
// No conversion is necessary.  
SampleGenericDelegate<Second, First> dGeneric = ASecondRFirst;  
// Assigning a method with a more derived return type   
// and less derived argument type to a generic delegate.  
// The implicit conversion is used.  
SampleGenericDelegate<Second, First> dGenericConversion = AFirstRSecond;  
```

有关更多示例，请参阅[在委托中使用变体 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/covariance-contravariance/using-variance-in-delegates) 和[对 Func 和 Action 泛型委托使用变体 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/covariance-contravariance/using-variance-for-func-and-action-generic-delegates)。

#### 泛型类型参数中的变体

在 .NET Framework 4 或更高版本中，可以启用委托之间的隐式转换，以便在具有泛型类型参数所指定的不同类型按变体的要求继承自对方时，可以将这些类型的泛型委托分配给对方。

若要启用隐式转换，必须使用 `in` 或 `out` 关键字将委托中的泛型参数显式声明为协变或逆变。

以下代码示例演示了如何创建一个具有协变泛型类型参数的委托。

```csharp
// Type T is declared covariant by using the out keyword.  
public delegate T SampleGenericDelegate <out T>();  
  
public static void Test()  
{  
    SampleGenericDelegate <String> dString = () => " ";  
  
    // You can assign delegates to each other,  
    // because the type T is declared covariant.  
    SampleGenericDelegate <Object> dObject = dString;             
}  
```

如果仅使用变体支持来匹配方法签名和委托类型，且不使用 `in` 和 `out` 关键字，则可能会发现有时可以使用相同的 lambda 表达式或方法实例化委托，但不能将一个委托分配给另一个委托。

在以下代码示例中，`SampleGenericDelegate<String>` 不能显式转换为 `SampleGenericDelegate<Object>`，尽管 `String` 继承 `Object`。 可以使用 `out` 关键字标记 泛型参数 `T` 解决此问题。

```csharp
public delegate T SampleGenericDelegate<T>();  
  
public static void Test()  
{  
    SampleGenericDelegate<String> dString = () => " ";  
  
    // You can assign the dObject delegate  
    // to the same lambda expression as dString delegate  
    // because of the variance support for   
    // matching method signatures with delegate types.  
    SampleGenericDelegate<Object> dObject = () => " ";  
  
    // The following statement generates a compiler error  
    // because the generic type T is not marked as covariant.  
    // SampleGenericDelegate <Object> dObject = dString;  
  
}  
```

##### .NET Framework 中具有变体类型参数的泛型委托

.NET Framework 4 在几个现有泛型委托中引入了泛型类型参数的变体支持：

- [System](https://docs.microsoft.com/zh-cn/dotnet/api/system) 命名空间的 `Action` 委托，例如 [Action](https://docs.microsoft.com/zh-cn/dotnet/api/system.action-1) 和 [Action](https://docs.microsoft.com/zh-cn/dotnet/api/system.action-2)
- [System](https://docs.microsoft.com/zh-cn/dotnet/api/system) 命名空间的 `Func` 委托，例如 [Func](https://docs.microsoft.com/zh-cn/dotnet/api/system.func-1) 和 [Func](https://docs.microsoft.com/zh-cn/dotnet/api/system.func-2)
- [Predicate](https://docs.microsoft.com/zh-cn/dotnet/api/system.predicate-1) 委托
- [Comparison](https://docs.microsoft.com/zh-cn/dotnet/api/system.comparison-1) 委托
- [Converter](https://docs.microsoft.com/zh-cn/dotnet/api/system.converter-2) 委托

有关详细信息和示例，请参阅[对 Func 和 Action 泛型委托使用变体 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/covariance-contravariance/using-variance-for-func-and-action-generic-delegates)。

##### 声明泛型委托中的变体类型参数

如果泛型委托具有协变或逆变泛型类型参数，则该委托可被称为“变体泛型委托”。

可以使用 `out` 关键字声明泛型委托中的泛型类型参数协变。 协变类型只能用作方法返回类型，而不能用作方法参数的类型。 以下代码示例演示了如何声明协变泛型委托。

```csharp
public delegate R DCovariant<out R>();  
```

可以使用 `in` 关键字声明泛型委托中的泛型类型参数逆变。 逆变类型只能用作方法参数的类型，而不能用作方法返回类型。 以下代码示例演示了如何声明逆变泛型委托。

```csharp
public delegate void DContravariant<in A>(A a);  
```

> C# 中的 `ref`、`in` 和 `out` 参数不能标记为变体。

可以在同一个委托中支持变体和协变，但这只适用于不同类型的参数。 这在下面的示例中显示。

```csharp
public delegate R DVariant<in A, out R>(A a);  
```

##### 实例化和调用变体泛型委托

可以像实例化和调用固定委托一样，实例化和调用变体委托。 在以下示例中，该委托通过 lambda 表达式进行实例化。

```csharp
DVariant<String, String> dvariant = (String str) => str + " ";  
dvariant("test");  
```

##### 合并变体泛型委托

不应合并变体委托。 [Combine](https://docs.microsoft.com/zh-cn/dotnet/api/system.delegate.combine) 方法不支持变体委托转换，并且要求委托的类型完全相同。 这会导致在使用 [Combine](https://docs.microsoft.com/zh-cn/dotnet/api/system.delegate.combine) 方法或使用 `+` 运算符合并委托时出现运行时异常，如以下代码示例中所示。

```csharp
Action<object> actObj = x => Console.WriteLine("object: {0}", x);  
Action<string> actStr = x => Console.WriteLine("string: {0}", x);  
// All of the following statements throw exceptions at run time.  
// Action<string> actCombine = actStr + actObj;  
// actStr += actObj;  
// Delegate.Combine(actStr, actObj);  
```

#### 泛型类型参数中用于值和引用类型的变体

泛型类型参数的变体仅支持引用类型。 例如，`DVariant<int>` 不能隐式转换为 `DVariant<Object>` 或 `DVariant<long>`，因为整数是值类型。

以下示例演示了泛型类型参数中的变体不支持值类型。

```csharp
// The type T is covariant.  
public delegate T DVariant<out T>();  
  
// The type T is invariant.  
public delegate T DInvariant<T>();  
  
public static void Test()  
{  
    int i = 0;  
    DInvariant<int> dInt = () => i;  
    DVariant<int> dVariantInt = () => i;  
  
    // All of the following statements generate a compiler error  
    // because type variance in generic parameters is not supported  
    // for value types, even if generic type parameters are declared variant.  
    // DInvariant<Object> dObject = dInt;  
    // DInvariant<long> dLong = dInt;  
    // DVariant<Object> dVariantObject = dVariantInt;  
    // DVariant<long> dVariantLong = dVariantInt;              
}  
```

#### [Using Variance in Delegates](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/covariance-contravariance/using-variance-in-delegates)

向委托分配方法时，协变和逆变为匹配委托类型和方法签名提供了灵活性。 协变允许方法具有的派生返回类型多于委托中定义的类型。 逆变允许方法具有的派生参数类型少于委托类型中的类型。

##### 示例 1：协变

- 说明

本示例演示如何将委托与具有返回类型的方法一起使用，这些返回类型派生自委托签名中的返回类型。 `DogsHandler` 返回的数据类型属于 `Dogs` 类型，它派生自委托中定义的 `Mammals` 类型。

- 代码

```csharp
class Mammals {}  
class Dogs : Mammals {}  
  
class Program  
{  
    // Define the delegate.  
    public delegate Mammals HandlerMethod();  
  
    public static Mammals MammalsHandler()  
    {  
        return null;  
    }  
  
    public static Dogs DogsHandler()  
    {  
        return null;  
    }  
  
    static void Test()  
    {  
        HandlerMethod handlerMammals = MammalsHandler;  
  
        // Covariance enables this assignment.  
        HandlerMethod handlerDogs = DogsHandler;  
    }  
}  
```

##### 示例 2：逆变

- 说明

本示例演示如何将委托与具有某个类型的参数的方法一起使用，这些返回类型是委托签名参数类型的基类型。 通过逆变可以使用一个事件处理程序而不是多个单独的处理程序。 例如，可以创建接受 `EventArgs` 输入参数的事件处理程序，并将其与将 `MouseEventArgs` 类型作为参数发送的 `Button.MouseClick` 事件一起使用，也可以将其与发送 `KeyEventArgs` 参数的 `TextBox.KeyDown` 事件一起使用。

- 代码

```csharp
// Event handler that accepts a parameter of the EventArgs type.  
private void MultiHandler(object sender, System.EventArgs e)  
{  
    label1.Text = System.DateTime.Now.ToString();  
}  
  
public Form1()  
{  
    InitializeComponent();  
  
    // You can use a method that has an EventArgs parameter,  
    // although the event expects the KeyEventArgs parameter.  
    this.button1.KeyDown += this.MultiHandler;  
  
    // You can use the same method   
    // for an event that expects the MouseEventArgs parameter.  
    this.button1.MouseClick += this.MultiHandler;  
  
}  
```

#### [Using Variance for Func and Action Generic Delegates](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/covariance-contravariance/using-variance-for-func-and-action-generic-delegates)

这些示例演示如何使用 `Func` 和 `Action` 泛型委托中的协变和逆变来启用重用方法并为代码中提供更多的灵活性。

有关协变和逆变的详细信息，请参阅[委托中的变体 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/covariance-contravariance/variance-in-delegates)。

##### 使用具有协变类型参数的委托

下例阐释了泛型 `Func` 委托中的协变支持的益处。 `FindByTitle` 方法采用 `String` 类型的一个参数，并返回 `Employee` 类型的一个对象。 但是，可将此方法分配给 `Func<String, Person>` 委托，因为 `Employee` 继承 `Person`。

```csharp
// Simple hierarchy of classes.  
public class Person { }  
public class Employee : Person { }  
class Program  
{  
    static Employee FindByTitle(String title)  
    {  
        // This is a stub for a method that returns  
        // an employee that has the specified title.  
        return new Employee();  
    }  
  
    static void Test()  
    {  
        // Create an instance of the delegate without using variance.  
        Func<String, Employee> findEmployee = FindByTitle;  
  
        // The delegate expects a method to return Person,  
        // but you can assign it a method that returns Employee.  
        Func<String, Person> findPerson = FindByTitle;  
  
        // You can also assign a delegate   
        // that returns a more derived type   
        // to a delegate that returns a less derived type.  
        findPerson = findEmployee;  
  
    }  
}  
```

##### 使用具有逆变类型参数的委托

下例阐释了泛型 `Action` 委托中的逆变支持的益处。 `AddToContacts` 方法采用 `Person` 类型的一个参数。 但是，可将此方法分配给 `Action<Employee>` 委托，因为 `Employee` 继承 `Person`。

```csharp
public class Person { }  
public class Employee : Person { }  
class Program  
{  
    static void AddToContacts(Person person)  
    {  
        // This method adds a Person object  
        // to a contact list.  
    }  
  
    static void Test()  
    {  
        // Create an instance of the delegate without using variance.  
        Action<Person> addPersonToContacts = AddToContacts;  
  
        // The Action delegate expects   
        // a method that has an Employee parameter,  
        // but you can assign it a method that has a Person parameter  
        // because Employee derives from Person.  
        Action<Employee> addEmployeeToContacts = AddToContacts;  
  
        // You can also assign a delegate   
        // that accepts a less derived parameter to a delegate   
        // that accepts a more derived parameter.  
        addEmployeeToContacts = addPersonToContacts;  
    }  
}  
```