[C# programming guide](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/index)

# Language Sections

## [Interfaces](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/interfaces/index)

接口包含[类](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/class)或[结构](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/struct)可以实现的一组相关功能的定义。

例如，使用接口可以在类中包括来自多个源的行为。 该功能在 C# 中十分重要，因为该语言不支持类的多重继承。 此外，如果要模拟结构的继承，也必须使用接口，因为它们无法实际从另一个结构或类继承。

可使用 [interface](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/interface) 关键字定义接口。 如以下示例所示。

```csharp
interface IEquatable<T>
{
    bool Equals(T obj);
}
```

结构名称必须是有效的 C# [标识符名称](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/inside-a-program/identifier-names)。 按照约定，接口名称以大写字母 `I` 开头。

实现 [IEquatable](https://docs.microsoft.com/zh-cn/dotnet/api/system.iequatable-1) 接口的任何类或结构都必须包含与该接口指定的签名匹配的 [Equals](https://docs.microsoft.com/zh-cn/dotnet/api/system.iequatable-1.equals) 方法的定义。 因此，可以依靠实现 `IEquatable<T>` 的类来包含 `Equals` 方法，类的实例可以通过该方法确定它是否等于相同类的另一个实例。

`IEquatable<T>` 的定义不为 `Equals` 提供实现。 该接口仅定义签名。 这样，C# 中的接口便类似于其中所有方法都是抽象方法的抽象类。 但是，类或结构可以实现多个接口，但是类只能继承单个类（抽象或不抽象）。 因此，使用接口可以在类中包括来自多个源的行为。

有关抽象类的详细信息，请参阅[抽象类、密封类及类成员](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/abstract-and-sealed-classes-and-class-members)。

接口可以包含方法、属性、事件、索引器或这四种成员类型的任意组合。 有关示例的链接，请参阅[相关部分](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/interfaces/index#BKMK_RelatedSections)。 接口不能包含常量、字段、运算符、实例构造函数、终结器或类型。 接口成员会自动成为公共成员，不能包含任何访问修饰符。 成员也不能是[静态](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/static)成员。

若要实现接口成员，实现类的对应成员必须是公共、非静态，并且具有与接口成员相同的名称和签名。

当类或结构实现接口时，类或结构必须为该接口定义的所有成员提供实现。 接口本身不提供类或结构可以通过继承基类功能的方式来继承的任何功能。 但是，如果基类实现接口，则从基类派生的任何类都会继承该实现。

下面的示例演示 [IEquatable](https://docs.microsoft.com/zh-cn/dotnet/api/system.iequatable-1) 接口的实现。 实现类 `Car` 必须提供 [Equals](https://docs.microsoft.com/zh-cn/dotnet/api/system.iequatable-1.equals) 方法的实现。

```csharp
public class Car : IEquatable<Car>
{
    public string Make {get; set;}
    public string Model { get; set; }
    public string Year { get; set; }

    // Implementation of IEquatable<T> interface
    public bool Equals(Car car)
    {
        return this.Make == car.Make &&
               this.Model == car.Model &&
               this.Year == car.Year;
    }
}
```

类的属性和索引器可以为接口中定义的属性或索引器定义额外的访问器。 例如，接口可能会声明包含 [get](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/get) 取值函数的属性。 实现此接口的类可以声明包含 `get` 和 [set](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/set) 取值函数的同一属性。 但是，如果属性或索引器使用显式实现，则访问器必须匹配。 有关显式实现的详细信息，请参阅[显式接口实现](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/interfaces/explicit-interface-implementation)和[接口属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/interface-properties)。

接口可以从其他接口继承。 类可能通过它继承的基类或通过其他接口继承的接口来多次包含某个接口。 但是，类只能提供接口的实现一次，并且仅当类将接口作为类定义的一部分 (`class ClassName : InterfaceName`) 进行声明时才能提供。 如果由于继承实现接口的基类而继承了接口，则基类会提供接口的成员的实现。 但是，派生类可以重新实现任何虚拟接口成员，而不是使用继承的实现。

基类还可以使用虚拟成员实现接口成员。 在这种情况下，派生类可以通过重写虚拟成员来更改接口行为。 有关虚拟成员的详细信息，请参阅[多态性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/polymorphism)。

### 接口摘要

接口具有以下属性：

- 接口类似于抽象基类。 实现接口的任何类或结构都必须实现其所有成员。
- 接口无法直接进行实例化。 其成员由实现接口的任何类或结构来实现。
- 接口可以包含事件、索引器、方法和属性。
- 接口不包含方法的实现。
- 一个类或结构可以实现多个接口。 一个类可以继承一个基类，还可实现一个或多个接口。

### 本节内容

[显式接口实现](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/interfaces/explicit-interface-implementation)
说明如何创建特定于接口的类成员。

[如何：显式实现接口成员](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/interfaces/how-to-explicitly-implement-interface-members)
提供有关如何显式实现接口的成员的示例。

[如何：显式实现两个接口的成员](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/interfaces/how-to-explicitly-implement-members-of-two-interfaces)
提供有关如何使用继承显式实现接口的成员的示例。

### [Explicit Interface Implementation](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/interfaces/explicit-interface-implementation)

如果一个[类](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/class)实现的两个接口包含签名相同的成员，则在该类上实现此成员会导致这两个接口将此成员用作其实现。如下示例中，所有对 `Paint` 的调用皆调用同一方法。

```csharp
class Test 
{
    static void Main()
    {
        SampleClass sc = new SampleClass();
        IControl ctrl = sc;
        ISurface srfc = sc;

        // The following lines all call the same method.
        sc.Paint();
        ctrl.Paint();
        srfc.Paint();
    }
}


interface IControl
{
    void Paint();
}
interface ISurface
{
    void Paint();
}
class SampleClass : IControl, ISurface
{
    // Both ISurface.Paint and IControl.Paint call this method. 
    public void Paint()
    {
        Console.WriteLine("Paint method in SampleClass");
    }
}

// Output:
// Paint method in SampleClass
// Paint method in SampleClass
// Paint method in SampleClass
```

但是，如果两个[接口](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/interface)成员不执行同一功能，则会导致其中一个接口或两个接口的实现不正确。 创建仅通过接口调用且特定于该接口的类成员，则有可能显式实现接口成员。 这可通过使用接口名称和句点命名类成员来完成。 例如:

```csharp
public class SampleClass : IControl, ISurface
{
    void IControl.Paint()
    {
        System.Console.WriteLine("IControl.Paint");
    }
    void ISurface.Paint()
    {
        System.Console.WriteLine("ISurface.Paint");
    }
}
```

类成员 `IControl.Paint` 仅通过 `IControl` 接口可用，`ISurface.Paint` 仅通过 `ISurface` 可用。 这两个方法实现相互独立，两者均不可直接在类上使用。 例如:

```csharp
// Call the Paint methods from Main.

SampleClass obj = new SampleClass();
//obj.Paint();  // Compiler error.

IControl c = obj;
c.Paint();  // Calls IControl.Paint on SampleClass.

ISurface s = obj;
s.Paint(); // Calls ISurface.Paint on SampleClass.

// Output:
// IControl.Paint
// ISurface.Paint
```

显式实现还用于处理两个接口分别声明名称相同的不同成员（例如属性和方法）的情况：

```csharp
interface ILeft
{
    int P { get;}
}
interface IRight
{
    int P();
}
```

若要实现两个接口，类必须对属性 P 或方法 P 使用显式实现，或对二者同时使用，从而避免编译器错误。 例如:

```csharp
class Middle : ILeft, IRight
{
    public int P() { return 0; }
    int ILeft.P { get { return 0; } }
}
```

### [How to: Explicitly Implement Interface Members](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/interfaces/how-to-explicitly-implement-interface-members)

本示例声明一个[接口](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/interface) `IDimensions` 和一个类 `Box`，显式实现了接口成员 `getLength` 和 `getWidth`。 通过接口实例 `dimensions` 访问这些成员。

#### 示例

```csharp
interface IDimensions
{
    float getLength();
    float getWidth();
}

class Box : IDimensions
{
    float lengthInches;
    float widthInches;

    Box(float length, float width)
    {
        lengthInches = length;
        widthInches = width;
    }
    // Explicit interface member implementation: 
    float IDimensions.getLength()
    {
        return lengthInches;
    }
    // Explicit interface member implementation:
    float IDimensions.getWidth()
    {
        return widthInches;
    }

    static void Main()
    {
        // Declare a class instance box1:
        Box box1 = new Box(30.0f, 20.0f);

        // Declare an interface instance dimensions:
        IDimensions dimensions = box1;

        // The following commented lines would produce compilation 
        // errors because they try to access an explicitly implemented
        // interface member from a class instance:                   
        //System.Console.WriteLine("Length: {0}", box1.getLength());
        //System.Console.WriteLine("Width: {0}", box1.getWidth());

        // Print out the dimensions of the box by calling the methods 
        // from an instance of the interface:
        System.Console.WriteLine("Length: {0}", dimensions.getLength());
        System.Console.WriteLine("Width: {0}", dimensions.getWidth());
    }
}
/* Output:
    Length: 30
    Width: 20
*/
```

#### 可靠编程

- 请注意，注释掉了 `Main` 方法中以下行，因为它们将产生编译错误。 显式实现的接口成员不能从[类](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/class)实例访问：

  ```csharp
  //System.Console.WriteLine("Length: {0}", box1.getLength());
  //System.Console.WriteLine("Width: {0}", box1.getWidth());
  ```

- 另请注意 `Main` 方法中的以下行成功输出了框的尺寸，因为这些方法是从接口实例调用的：

  ```csharp
  System.Console.WriteLine("Length: {0}", dimensions.getLength());
  System.Console.WriteLine("Width: {0}", dimensions.getWidth());
  ```

### [How to: Explicitly Implement Members of Two Interfaces](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/interfaces/how-to-explicitly-implement-members-of-two-interfaces)

显式[接口](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/interface)实现还允许程序员实现具有相同成员名称的两个接口，并为每个接口成员各提供一个单独的实现。 本示例同时以公制单位和英制单位显示框的尺寸。 Box [类](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/class)实现 IEnglishDimensions 和 IMetricDimensions 两个接口，它们表示不同的度量系统。 两个接口有相同的成员名称 Length 和 Width。

#### 示例

```csharp
// Declare the English units interface:
interface IEnglishDimensions
{
    float Length();
    float Width();
}

// Declare the metric units interface:
interface IMetricDimensions
{
    float Length();
    float Width();
}

// Declare the Box class that implements the two interfaces:
// IEnglishDimensions and IMetricDimensions:
class Box : IEnglishDimensions, IMetricDimensions
{
    float lengthInches;
    float widthInches;

    public Box(float lengthInches, float widthInches)
    {
        this.lengthInches = lengthInches;
        this.widthInches = widthInches;
    }

    // Explicitly implement the members of IEnglishDimensions:
    float IEnglishDimensions.Length() => lengthInches;

    float IEnglishDimensions.Width() => widthInches;

    // Explicitly implement the members of IMetricDimensions:
    float IMetricDimensions.Length() => lengthInches * 2.54f;

    float IMetricDimensions.Width() => widthInches * 2.54f;

    static void Main()
    {
        // Declare a class instance box1:
        Box box1 = new Box(30.0f, 20.0f);

        // Declare an instance of the English units interface:
        IEnglishDimensions eDimensions = box1;

        // Declare an instance of the metric units interface:
        IMetricDimensions mDimensions = box1;

        // Print dimensions in English units:
        System.Console.WriteLine("Length(in): {0}", eDimensions.Length());
        System.Console.WriteLine("Width (in): {0}", eDimensions.Width());

        // Print dimensions in metric units:
        System.Console.WriteLine("Length(cm): {0}", mDimensions.Length());
        System.Console.WriteLine("Width (cm): {0}", mDimensions.Width());
    }
}
/* Output:
    Length(in): 30
    Width (in): 20
    Length(cm): 76.2
    Width (cm): 50.8
*/
```

#### 可靠编程

如果希望默认度量采用英制单位，请正常实现 Length 和 Width 方法，并从 IMetricDimensions 接口显式实现 Length 和 Width 方法：

```csharp
// Normal implementation:
public float Length() => lengthInches;
public float Width() => widthInches;

// Explicit implementation:
float IMetricDimensions.Length() => lengthInches * 2.54f;
float IMetricDimensions.Width() => widthInches * 2.54f;
```

这种情况下，可以从类实例访问英制单位，从接口实例访问公制单位：

```csharp
public static void Test()
{
    Box box1 = new Box(30.0f, 20.0f);
    IMetricDimensions mDimensions = box1;

    System.Console.WriteLine("Length(in): {0}", box1.Length());
    System.Console.WriteLine("Width (in): {0}", box1.Width());
    System.Console.WriteLine("Length(cm): {0}", mDimensions.Length());
    System.Console.WriteLine("Width (cm): {0}", mDimensions.Width());
}
```