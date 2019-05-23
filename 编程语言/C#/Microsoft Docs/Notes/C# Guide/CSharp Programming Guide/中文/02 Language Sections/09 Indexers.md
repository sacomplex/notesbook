[C# programming guide](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/index)

# Language Sections

## [Indexers](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/indexers/index)

索引器允许类或结构的实例就像数组一样进行索引。 无需显式指定类型或实例成员，即可设置或检索索引值。 索引器类似于[属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/properties)，不同之处在于它们的访问器需要使用参数。

以下示例定义了一个泛型类，其中包含用于赋值和检索值的简单 [get](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/get) 和 [set](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/set) 访问器方法。 `Program` 类创建了此类的一个实例，用于存储字符串。

```csharp
using System;

class SampleCollection<T>
{
   // Declare an array to store the data elements.
   private T[] arr = new T[100];

   // Define the indexer to allow client code to use [] notation.
   public T this[int i]
   {
      get { return arr[i]; }
      set { arr[i] = value; }
   }
}

class Program
{
   static void Main()
   {
      var stringCollection = new SampleCollection<string>();
      stringCollection[0] = "Hello, World";
      Console.WriteLine(stringCollection[0]);
   }
}
// The example displays the following output:
//       Hello, World.
```

>  有关更多示例，请参阅[相关部分](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/indexers/index#BKMK_RelatedSections)。

### 表达式主体定义

索引器的 get 或 set 访问器包含一个用于返回或设置值的语句很常见。 为了支持这种情况，表达式主体成员提供了一种经过简化的语法。 自 C# 6 起，可以表达式主体成员的形式实现只读索引器，如以下示例所示。

```csharp
using System;

class SampleCollection<T>
{
   // Declare an array to store the data elements.
   private T[] arr = new T[100];
   int nextIndex = 0;
   
   // Define the indexer to allow client code to use [] notation.
   public T this[int i] => arr[i];
   
   public void Add(T value)
   {
      if (nextIndex >= arr.Length) 
         throw new IndexOutOfRangeException($"The collection can hold only {arr.Length} elements.");
      arr[nextIndex++] = value;
   }
}

class Program
{
   static void Main()
   {
      var stringCollection = new SampleCollection<string>();
      stringCollection.Add("Hello, World");
      System.Console.WriteLine(stringCollection[0]);
   }
}
// The example displays the following output:
//       Hello, World.
```

请注意，`=>` 引入了表达式主体，并未使用 `get` 关键字。

自 C# 7.0 起，get 和 set 访问器均可作为表达式主体成员实现。 在这种情况下，必须使用 `get` 和 `set` 关键字。例如:

```csharp
using System;

class SampleCollection<T>
{
   // Declare an array to store the data elements.
   private T[] arr = new T[100];

   // Define the indexer to allow client code to use [] notation.
   public T this[int i]
   {
      get => arr[i]; 
      set => arr[i] = value; 
   }
}

class Program
{
   static void Main()
   {
      var stringCollection = new SampleCollection<string>();
      stringCollection[0] = "Hello, World.";
      Console.WriteLine(stringCollection[0]);
   }
}
// The example displays the following output:
//       Hello, World.
```

### 索引器概述

- 使用索引器可以用类似于数组的方式为对象建立索引。
- `get` 取值函数返回值。 `set` 取值函数分配值。
- [this](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/this) 关键字用于定义索引器。
- [value](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/value) 关键字用于定义 `set` 索引器所赋的值。
- 索引器不必根据整数值进行索引；由你决定如何定义特定的查找机制。
- 索引器可被重载。
- 索引器可以有多个形参，例如当访问二维数组时。

### [Using Indexers](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/indexers/using-indexers)

索引器使你可从语法上方便地创建[类](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/class)、[结构](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/struct)或[接口](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/interface)，以便客户端应用程序能像访问数组一样访问它们。 在主要目标是封装内部集合或数组的类型中，常常要实现索引器。 例如，假设有一个类 `TempRecord`，它表示 24 小时的周期内在 10 个不同时间点所记录的温度（单位为华氏度）。 此类包含类型 `float[]` 的一个数组 `temps`，用于存储温度值。 通过在此类中实现索引器，客户端可采用 `float temp = tr[4]` 的形式（而非 `float temp = tr.temps[4]`）访问 `TempRecord` 实例中的温度。 索引器表示法不但简化了客户端应用程序的语法；它还使类及其目标更容易直观地为其它开发者所理解。

若要在类或结构上声明索引器，请使用 [this](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/this) 关键字，如以下示例所示：

C#复制

```csharp
public int this[int index]    // Indexer declaration  
{  
    // get and set accessors  
}  
```

#### 备注

索引器及其参数的类型必须至少具有和索引器相同的可访问性。 有关可访问性级别的详细信息，请参阅[访问修饰符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/access-modifiers)。

有关如何在接口上使用索引器的详细信息，请参阅[接口索引器](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/indexers/indexers-in-interfaces)。

索引器的签名由其形参的数目和类型所组成。 它不包含索引器类型或形参的名称。 如果要在相同类中声明多个索引器，则它们的签名必须不同。

索引器值不分类为变量；因此，无法将索引器值作为 [ref](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ref) 或 [out](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/out-parameter-modifier) 参数来传递。

若要使索引器的名称可为其他语言所用，请使用 [System.Runtime.CompilerServices.IndexerNameAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.compilerservices.indexernameattribute)，如以下示例所示：

```csharp
[System.Runtime.CompilerServices.IndexerName("TheItem")]  
public int this[int index]   // Indexer declaration  
{
    // get and set accessors  
}  
```

此索引器将具有名称 `TheItem`。 如果不提供名称属性，则 `Item` 将成为默认名称。

#### 示例 1

下列示例演示如何声明专用数组字段 `temps` 和索引器。 索引器可以实现对实例 `tempRecord[i]` 的直接访问。 若不使用索引器，则将数组声明为[公共](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/public)成员，并直接访问其成员 `tempRecord.temps[i]`。

请注意，当评估索引器访问时（例如在 `Console.Write` 语句中），将调用 [get](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/get) 访问器。 因此，如果不存在 `get`访问器，则会发生编译时错误。

```csharp
class TempRecord
{
    // Array of temperature values
    private float[] temps = new float[10] { 56.2F, 56.7F, 56.5F, 56.9F, 58.8F, 
                                            61.3F, 65.9F, 62.1F, 59.2F, 57.5F };

    // To enable client code to validate input 
    // when accessing your indexer.
    public int Length
    {
        get { return temps.Length; }
    }
    // Indexer declaration.
    // If index is out of range, the temps array will throw the exception.
    public float this[int index]
    {
        get
        {
            return temps[index];
        }

        set
        {
            temps[index] = value;
        }
    }
}

class MainClass
{
    static void Main()
    {
        TempRecord tempRecord = new TempRecord();
        // Use the indexer's set accessor
        tempRecord[3] = 58.3F;
        tempRecord[5] = 60.1F;

        // Use the indexer's get accessor
        for (int i = 0; i < 10; i++)
        {
            System.Console.WriteLine("Element #{0} = {1}", i, tempRecord[i]);
        }

        // Keep the console window open in debug mode.
        System.Console.WriteLine("Press any key to exit.");
        System.Console.ReadKey();

    }
}
/* Output:
        Element #0 = 56.2
        Element #1 = 56.7
        Element #2 = 56.5
        Element #3 = 58.3
        Element #4 = 58.8
        Element #5 = 60.1
        Element #6 = 65.9
        Element #7 = 62.1
        Element #8 = 59.2
        Element #9 = 57.5
    */
```

#### 使用其他值进行索引

C# 不将索引参数类型限制为整数。 例如，对索引器使用字符串可能有用。 通过搜索集合内的字符串并返回相应的值，可以实现此类索引器。 由于访问器可被重载，字符串和整数版本可以共存。

#### 示例 2

下面的示例声明了存储星期几的类。 `get` 访问器采用字符串（星期几）并返回对应的整数。 例如，“Sunday”返回 0，“Monday”返回 1，依此类推。

```csharp
// Using a string as an indexer value
class DayCollection
{
    string[] days = { "Sun", "Mon", "Tues", "Wed", "Thurs", "Fri", "Sat" };

    // This method finds the day or returns an Exception if the day is not found
    private int GetDay(string testDay)
    {

        for (int j = 0; j < days.Length; j++)
        {
            if (days[j] == testDay)
            {
                return j;
            }
        }

        throw new System.ArgumentOutOfRangeException(testDay, "testDay must be in the form \"Sun\", \"Mon\", etc");
    }

    // The get accessor returns an integer for a given string
    public int this[string day]
    {
        get
        {
            return (GetDay(day));
        }
    }
}

class Program
{
    static void Main(string[] args)
    {
        DayCollection week = new DayCollection();
        System.Console.WriteLine(week["Fri"]);

        // Raises ArgumentOutOfRangeException
        System.Console.WriteLine(week["Made-up Day"]);

        // Keep the console window open in debug mode.
        System.Console.WriteLine("Press any key to exit.");
        System.Console.ReadKey();
    }
}
// Output: 5
```

#### 可靠编程

提高索引器的安全性和可靠性有两种主要方法：

- 请确保结合某一类型的错误处理策略，以处理万一客户端代码传入无效索引值的情况。 在本主题前面的第一个示例中，TempRecord 类提供了 Length 属性，使客户端代码能在将输入传递给索引器之前对其进行验证。也可将错误处理代码放入索引器自身内部。 请确保为用户记录在索引器的访问器中引发的任何异常。
- 在可接受的程度内，为 [get](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/get) 和 [set](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/set) 访问器的可访问性设置尽可能多的限制。 这一点对 `set` 访问器尤为重要。 有关详细信息，请参阅[限制访问器可访问性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/restricting-accessor-accessibility)。

### [Indexers in Interfaces](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/indexers/indexers-in-interfaces)

可以在[接口](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/interface)上声明索引器。 接口索引器的访问器与[类](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/class)索引器的访问器有所不同，差异如下：

- 接口访问器不使用修饰符。
- 接口访问器没有正文。

因此，访问器的用途是指示索引器为读写、只读还是只写。

下面是接口索引器访问器的示例：

```csharp
public interface ISomeInterface
{
    //...

    // Indexer declaration:
    string this[int index]
    {
        get;
        set;
    }
}
```

索引器的签名必须不同于同一接口中声明的所有其他索引器的签名。

#### 示例

下面的示例演示如何实现接口索引器。

```csharp
// Indexer on an interface:
public interface ISomeInterface
{
    // Indexer declaration:
    int this[int index]
    {
        get;
        set;
    }
}

// Implementing the interface.
class IndexerClass : ISomeInterface
{
    private int[] arr = new int[100];
    public int this[int index]   // indexer declaration
    {
        get
        {
            // The arr object will throw IndexOutOfRange exception.
            return arr[index];
        }
        set
        {
            arr[index] = value;
        }
    }
}

class MainClass
{
    static void Main()
    {
        IndexerClass test = new IndexerClass();
        System.Random rand = new System.Random();
        // Call the indexer to initialize its elements.
        for (int i = 0; i < 10; i++)
        {
            test[i] = rand.Next();
        }
        for (int i = 0; i < 10; i++)
        {
            System.Console.WriteLine("Element #{0} = {1}", i, test[i]);
        }

        // Keep the console window open in debug mode.
        System.Console.WriteLine("Press any key to exit.");
        System.Console.ReadKey();
    }
}
/* Sample output:
    Element #0 = 360877544
    Element #1 = 327058047
    Element #2 = 1913480832
    Element #3 = 1519039937
    Element #4 = 601472233
    Element #5 = 323352310
    Element #6 = 1422639981
    Element #7 = 1797892494
    Element #8 = 875761049
    Element #9 = 393083859
 */
```

在前面的示例中，可通过使用接口成员的完全限定名来使用显示接口成员实现。 例如:

```c#
string ISomeInterface.this[int index]   
{   
}   
```

但仅当类采用相同的索引签名实现多个接口时，才需用到完全限定名称以避免歧义。 例如，如果 `Employee` 类正在实现接口 `ICitizen` 和接口 `IEmployee`，而这两个接口具有相同的索引签名，则需要用到显式接口成员实现。即是说以下索引器声明：

```c#
string IEmployee.this[int index]   
{   
}   
```

在 `IEmployee` 接口中实现索引器，而以下声明：

```c#
string ICitizen.this[int index]
{   
}   
```

在 `ICitizen` 接口中实现索引器。

### [Comparison Between Properties and Indexers](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/indexers/comparison-between-properties-and-indexers)

索引器与属性相似。 除下表所示的差别外，对属性访问器定义的所有规则也适用于索引器访问器。

| Property                                                     | 索引器                                                       |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| 允许以将方法视作公共数据成员的方式调用方法。                 | 通过在对象自身上使用数组表示法，允许访问对象内部集合的元素。 |
| 通过简单名称访问。                                           | 通过索引访问。                                               |
| 可为静态成员或实例成员。                                     | 必须是实例成员。                                             |
| 属性的 [get](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/get) 访问器没有任何参数。 | 索引器的 `get` 访问器具有与索引器相同的形参列表。            |
| 属性的 [set](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/set) 访问器包含隐式 `value` 参数。 | 索引器的 `set` 访问器具有与索引器相同的形参列表，[value](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/value) 参数也是如此。 |
| 通过[自动实现的属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/auto-implemented-properties)支持简短语法。 | 不支持简短语法。                                             |

