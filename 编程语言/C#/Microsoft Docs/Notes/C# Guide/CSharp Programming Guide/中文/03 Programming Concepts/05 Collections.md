# [Programming Concepts](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/)

## [Collections](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/collections)

对于许多应用程序，你会想要创建和管理相关对象的组。 有两种方法对对象进行分组：通过创建对象的数组，以及通过创建对象的集合。

数组最适用于创建和使用固定数量的强类型化对象。 有关数组的信息，请参阅[数组](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/arrays/index)。

集合提供更灵活的方式来使用对象组。 与数组不同，你使用的对象组随着应用程序更改的需要动态地放大和缩小。 对于某些集合，你可以为放入集合中的任何对象分配一个密钥，这样你便可以使用该密钥快速检索此对象。

集合是一个类，因此必须在向该集合添加元素之前，声明类的实例。

如果集合中只包含一种数据类型的元素，则可以使用 [System.Collections.Generic](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic) 命名空间中的一个类。 泛型集合强制类型安全，因此无法向其添加任何其他数据类型。 当你从泛型集合检索元素时，你无需确定其数据类型或对其进行转换。

> 在本主题的示例中，针对 `System.Collections.Generic` 和 `System.Linq` 命名空间包括 [using](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/using-directive) 指令。

**在本主题中**

- [使用简单集合](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/collections#BKMK_SimpleCollection)
- [集合的类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/collections#BKMK_KindsOfCollections)
  - [System.Collections.Generic 类](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/collections#BKMK_Generic)
  - [System.Collections.Concurrent 类](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/collections#BKMK_Concurrent)
  - [System.Collections 类](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/collections#BKMK_Collections)
- [实现键/值对集合](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/collections#BKMK_KeyValuePairs)
- [使用 LINQ 访问集合](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/collections#BKMK_LINQ)
- [对集合排序](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/collections#BKMK_Sorting)
- [定义自定义集合](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/collections#BKMK_CustomCollection)
- [迭代器](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/collections#BKMK_Iterators)

### 使用简单集合

本部分中的示例使用泛型 [List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1) 类，通过此类可使用对象的强类型列表。

以下示例创建字符串列表，并通过使用 [foreach](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/foreach-in) 语句循环访问字符串。

```csharp
// Create a list of strings.  
var salmons = new List<string>();  
salmons.Add("chinook");  
salmons.Add("coho");  
salmons.Add("pink");  
salmons.Add("sockeye");  
  
// Iterate through the list.  
foreach (var salmon in salmons)  
{  
    Console.Write(salmon + " ");  
}  
// Output: chinook coho pink sockeye  
```

如果集合中的内容是事先已知的，则可以使用集合初始值设定项来初始化集合。 有关详细信息，请参阅[对象和集合初始值设定项](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/object-and-collection-initializers)。

以下示例与上一示例相同，除了有一个集合初始值设定项用于将元素添加到集合。

```csharp
// Create a list of strings by using a  
// collection initializer.  
var salmons = new List<string> { "chinook", "coho", "pink", "sockeye" };  
  
// Iterate through the list.  
foreach (var salmon in salmons)  
{  
    Console.Write(salmon + " ");  
}  
// Output: chinook coho pink sockeye  
```

可以使用 [for](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/for) 语句，而不是 `foreach` 语句来循环访问集合。 通过按索引位置访问集合元素实现此目的。 元素的索引开始于 0，结束于元素计数减 1。

以下示例通过使用 `for` 而不是 `foreach` 循环访问集合中的元素。

```csharp
// Create a list of strings by using a  
// collection initializer.  
var salmons = new List<string> { "chinook", "coho", "pink", "sockeye" };  
  
for (var index = 0; index < salmons.Count; index++)  
{  
    Console.Write(salmons[index] + " ");  
}  
// Output: chinook coho pink sockeye  
```

以下示例通过指定要删除的对象，从集合中删除一个元素。

```csharp
// Create a list of strings by using a  
// collection initializer.  
var salmons = new List<string> { "chinook", "coho", "pink", "sockeye" };  
  
// Remove an element from the list by specifying  
// the object.  
salmons.Remove("coho");  
  
// Iterate through the list.  
foreach (var salmon in salmons)  
{  
    Console.Write(salmon + " ");  
}  
// Output: chinook pink sockeye  
```

以下示例从一个泛型列表中删除元素。 使用以降序进行循环访问的 [for](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/for) 语句，而非 `foreach` 语句。 这是因为 [RemoveAt](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1.removeat) 方法将导致已移除的元素后的元素的索引值减小。

```csharp
var numbers = new List<int> { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };  
  
// Remove odd numbers.  
for (var index = numbers.Count - 1; index >= 0; index--)  
{  
    if (numbers[index] % 2 == 1)  
    {  
        // Remove the element by specifying  
        // the zero-based index in the list.  
        numbers.RemoveAt(index);  
    }  
}  
  
// Iterate through the list.  
// A lambda expression is placed in the ForEach method  
// of the List(T) object.  
numbers.ForEach(  
    number => Console.Write(number + " "));  
// Output: 0 2 4 6 8  
```

对于 [List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1) 中的元素类型，还可以定义自己的类。 在下面的示例中，由 [List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1) 使用的 `Galaxy` 类在代码中定义。

```csharp
private static void IterateThroughList()  
{  
    var theGalaxies = new List<Galaxy>  
        {  
            new Galaxy() { Name="Tadpole", MegaLightYears=400},  
            new Galaxy() { Name="Pinwheel", MegaLightYears=25},  
            new Galaxy() { Name="Milky Way", MegaLightYears=0},  
            new Galaxy() { Name="Andromeda", MegaLightYears=3}  
        };  
  
    foreach (Galaxy theGalaxy in theGalaxies)  
    {  
        Console.WriteLine(theGalaxy.Name + "  " + theGalaxy.MegaLightYears);  
    }  
  
    // Output:  
    //  Tadpole  400  
    //  Pinwheel  25  
    //  Milky Way  0  
    //  Andromeda  3  
}  
  
public class Galaxy  
{  
    public string Name { get; set; }  
    public int MegaLightYears { get; set; }  
}  
```

### 集合的类型

许多通用集合由 .NET Framework 提供。 每种类型的集合用于特定的用途。

本部分介绍了一些通用集合类：

- [System.Collections.Generic](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic) 类
- [System.Collections.Concurrent](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.concurrent) 类
- [System.Collections](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections) 类

#### `System.Collections.Generic` 类

可以使用 [System.Collections.Generic](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic) 命名空间中的某个类来创建泛型集合。 当集合中的所有项都具有相同的数据类型时，泛型集合会非常有用。 泛型集合通过仅允许添加所需的数据类型，强制实施强类型化。

下表列出了 [System.Collections.Generic](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic) 命名空间中的一些常用类：
| 类                                                           | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [Dictionary<TKey,TValue>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.dictionary-2) | 表示基于键进行组织的键/值对的集合。                          |
| [List<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1) | 表示可按索引访问的对象的列表。 提供用于对列表进行搜索、排序和修改的方法。 |
| [Queue<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.queue-1) | 表示对象的先进先出 (FIFO) 集合。                             |
| [SortedList<TKey,TValue>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.sortedlist-2) | 表示基于相关的 [IComparer<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.icomparer-1) 实现按键进行排序的键/值对的集合。 |
| [Stack<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.stack-1) | 表示对象的后进先出 (LIFO) 集合。                             |

有关其他信息，请参阅[常用集合类型](https://docs.microsoft.com/zh-cn/dotnet/standard/collections/commonly-used-collection-types)、[选择集合类](https://docs.microsoft.com/zh-cn/dotnet/standard/collections/selecting-a-collection-class)和 [System.Collections.Generic](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic)。

#### `System.Collections.Concurrent` 类

在 .NET Framework 4 或更新的版本中，[System.Collections.Concurrent](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.concurrent) 命名空间中的集合可提供高效的线程安全操作，以便从多个线程访问集合项。

只要多个线程同时访问集合，就应使用 [System.Collections.Concurrent](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.concurrent) 命名空间中的类，而不是[System.Collections.Generic](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic) 和 [System.Collections](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections) 命名空间中的相应类型。 有关详细信息，请参阅[线程安全集合](https://docs.microsoft.com/zh-cn/dotnet/standard/collections/thread-safe/index)和 [System.Collections.Concurrent](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.concurrent)。

包含在 [System.Collections.Concurrent](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.concurrent) 命名空间中的一些类为 [BlockingCollection<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.concurrent.blockingcollection-1)、[ConcurrentDictionary<TKey,TValue>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.concurrent.concurrentdictionary-2)、[ConcurrentQueue<T> ](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.concurrent.concurrentqueue-1) 和 [ConcurrentStack<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.concurrent.concurrentstack-1)。

#### `System.Collections` 类

[System.Collections](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections) 命名空间中的类不会将元素作为特别类型化的对象存储，而是作为 `Object` 类型的对象存储。

只要可能，则应使用 [System.Collections.Generic](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic) 命名空间或 [System.Collections.Concurrent](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.concurrent) 命名空间中的泛型集合，而不是 `System.Collections` 命名空间中的旧类型。

下表列出了 `System.Collections` 命名空间中的一些常用类：

| **类**                                                       | 说明                                               |
| ------------------------------------------------------------ | -------------------------------------------------- |
| [ArrayList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.arraylist) | 表示对象的数组，这些对象的大小会根据需要动态增加。 |
| [Hashtable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.hashtable) | 表示根据键的哈希代码进行组织的键/值对的集合。      |
| [Queue](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.queue) | 表示对象的先进先出 (FIFO) 集合。                   |
| [Stack](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.stack) | 表示对象的后进先出 (LIFO) 集合。                   |

[System.Collections.Specialized](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.specialized) 命名空间提供专门类型化以及强类型化的集合类，例如只包含字符串的集合以及链接列表和混合字典。

### 实现键/值对集合

[Dictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.dictionary-2) 泛型集合可通过每个元素的键访问集合中的元素。 每次对字典的添加都包含一个值和与其关联的键。 通过使用键来检索值十分快捷，因为 `Dictionary` 类实现为哈希表。

以下示例创建 `Dictionary` 集合并通过使用 `foreach` 语句循环访问字典。

```csharp
private static void IterateThruDictionary()  
{  
    Dictionary<string, Element> elements = BuildDictionary();  
  
    foreach (KeyValuePair<string, Element> kvp in elements)  
    {  
        Element theElement = kvp.Value;  
  
        Console.WriteLine("key: " + kvp.Key);  
        Console.WriteLine("values: " + theElement.Symbol + " " +  
            theElement.Name + " " + theElement.AtomicNumber);  
    }  
}  
  
private static Dictionary<string, Element> BuildDictionary()  
{  
    var elements = new Dictionary<string, Element>();  
  
    AddToDictionary(elements, "K", "Potassium", 19);  
    AddToDictionary(elements, "Ca", "Calcium", 20);  
    AddToDictionary(elements, "Sc", "Scandium", 21);  
    AddToDictionary(elements, "Ti", "Titanium", 22);  
  
    return elements;  
}  
  
private static void AddToDictionary(Dictionary<string, Element> elements,  
    string symbol, string name, int atomicNumber)  
{  
    Element theElement = new Element();  
  
    theElement.Symbol = symbol;  
    theElement.Name = name;  
    theElement.AtomicNumber = atomicNumber;  
  
    elements.Add(key: theElement.Symbol, value: theElement);  
}  
  
public class Element  
{  
    public string Symbol { get; set; }  
    public string Name { get; set; }  
    public int AtomicNumber { get; set; }  
}  
```

若要转而使用集合初始值设定项生成 `Dictionary` 集合，可使用以下方法替换 `BuildDictionary` 和 `AddToDictionary`。

```csharp
private static Dictionary<string, Element> BuildDictionary2()  
{  
    return new Dictionary<string, Element>  
    {  
        {"K",  
            new Element() { Symbol="K", Name="Potassium", AtomicNumber=19}},  
        {"Ca",  
            new Element() { Symbol="Ca", Name="Calcium", AtomicNumber=20}},  
        {"Sc",  
            new Element() { Symbol="Sc", Name="Scandium", AtomicNumber=21}},  
        {"Ti",  
            new Element() { Symbol="Ti", Name="Titanium", AtomicNumber=22}}  
    };  
}  
```

以下示例使用 [ContainsKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.dictionary-2.containskey) 方法和 `Dictionary` 的 [Item[TKey\]](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.dictionary-2.item) 属性按键快速查找某个项。 使用 `Item` 属性可通过 C# 中的 `elements[symbol]` 来访问 `elements` 集合中的项。

```csharp
private static void FindInDictionary(string symbol)  
{  
    Dictionary<string, Element> elements = BuildDictionary();  
  
    if (elements.ContainsKey(symbol) == false)  
    {  
        Console.WriteLine(symbol + " not found");  
    }  
    else  
    {  
        Element theElement = elements[symbol];  
        Console.WriteLine("found: " + theElement.Name);  
    }  
}  
```

以下示例则使用 [TryGetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.dictionary-2.trygetvalue) 方法按键快速查找某个项。

```csharp
private static void FindInDictionary2(string symbol)  
{  
    Dictionary<string, Element> elements = BuildDictionary();  
  
    Element theElement = null;  
    if (elements.TryGetValue(symbol, out theElement) == false)  
        Console.WriteLine(symbol + " not found");  
    else  
        Console.WriteLine("found: " + theElement.Name);  
}  
```

### 使用 LINQ 访问集合

可以使用 LINQ（语言集成查询）来访问集合。 LINQ 查询提供筛选、排序和分组功能。 有关详细信息，请参阅[C# 中的 LINQ 入门](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/getting-started-with-linq)。

以下示例运行一个对泛型 `List` 的 LINQ 查询。 LINQ 查询返回一个包含结果的不同集合。

```csharp
private static void ShowLINQ()  
{  
    List<Element> elements = BuildList();  
  
    // LINQ Query.  
    var subset = from theElement in elements  
                 where theElement.AtomicNumber < 22  
                 orderby theElement.Name  
                 select theElement;  
  
    foreach (Element theElement in subset)  
    {  
        Console.WriteLine(theElement.Name + " " + theElement.AtomicNumber);  
    }  
  
    // Output:  
    //  Calcium 20  
    //  Potassium 19  
    //  Scandium 21  
}  
  
private static List<Element> BuildList()  
{  
    return new List<Element>  
    {  
        { new Element() { Symbol="K", Name="Potassium", AtomicNumber=19}},  
        { new Element() { Symbol="Ca", Name="Calcium", AtomicNumber=20}},  
        { new Element() { Symbol="Sc", Name="Scandium", AtomicNumber=21}},  
        { new Element() { Symbol="Ti", Name="Titanium", AtomicNumber=22}}  
    };  
}  
  
public class Element  
{  
    public string Symbol { get; set; }  
    public string Name { get; set; }  
    public int AtomicNumber { get; set; }  
}  
```

### 对集合排序

以下示例阐释了对集合排序的过程。 该示例对 [List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1) 中存储的 `Car` 类的实例进行排序。 `Car` 类实现 [IComparable](https://docs.microsoft.com/zh-cn/dotnet/api/system.icomparable-1) 接口，此操作需要实现 [CompareTo](https://docs.microsoft.com/zh-cn/dotnet/api/system.icomparable-1.compareto) 方法。

每次对 [CompareTo](https://docs.microsoft.com/zh-cn/dotnet/api/system.icomparable-1.compareto) 方法的调用均会执行用于排序的单一比较。 `CompareTo` 方法中用户编写的代码针对当前对象与另一个对象的每个比较返回一个值。 如果当前对象小于另一个对象，则返回的值小于零；如果当前对象大于另一个对象，则返回的值大于零；如果当前对象等于另一个对象，则返回的值等于零。 这使你可以在代码中定义大于、小于和等于条件。

在 `ListCars` 方法中，`cars.Sort()` 语句对列表进行排序。 对 [List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1) 的 [Sort](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1.sort) 方法的此调用将导致为 `List` 中的 `Car` 对象自动调用 `CompareTo` 方法。

```csharp
private static void ListCars()  
{  
    var cars = new List<Car>  
    {  
        { new Car() { Name = "car1", Color = "blue", Speed = 20}},  
        { new Car() { Name = "car2", Color = "red", Speed = 50}},  
        { new Car() { Name = "car3", Color = "green", Speed = 10}},  
        { new Car() { Name = "car4", Color = "blue", Speed = 50}},  
        { new Car() { Name = "car5", Color = "blue", Speed = 30}},  
        { new Car() { Name = "car6", Color = "red", Speed = 60}},  
        { new Car() { Name = "car7", Color = "green", Speed = 50}}  
    };  
  
    // Sort the cars by color alphabetically, and then by speed  
    // in descending order.  
    cars.Sort();  
  
    // View all of the cars.  
    foreach (Car thisCar in cars)  
    {  
        Console.Write(thisCar.Color.PadRight(5) + " ");  
        Console.Write(thisCar.Speed.ToString() + " ");  
        Console.Write(thisCar.Name);  
        Console.WriteLine();  
    }  
  
    // Output:  
    //  blue  50 car4  
    //  blue  30 car5  
    //  blue  20 car1  
    //  green 50 car7  
    //  green 10 car3  
    //  red   60 car6  
    //  red   50 car2  
}  
  
public class Car : IComparable<Car>  
{  
    public string Name { get; set; }  
    public int Speed { get; set; }  
    public string Color { get; set; }  
  
    public int CompareTo(Car other)  
    {  
        // A call to this method makes a single comparison that is  
        // used for sorting.  
  
        // Determine the relative order of the objects being compared.  
        // Sort by color alphabetically, and then by speed in  
        // descending order.  
  
        // Compare the colors.  
        int compare;  
        compare = String.Compare(this.Color, other.Color, true);  
  
        // If the colors are the same, compare the speeds.  
        if (compare == 0)  
        {  
            compare = this.Speed.CompareTo(other.Speed);  
  
            // Use descending order for speed.  
            compare = -compare;  
        }  
  
        return compare;  
    }  
}  
```

### 定义自定义集合

可以通过实现 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 或 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable) 接口来定义集合。

尽管可以定义自定义集合，但通常最好使用包含在 .NET Framework 中的集合，这在本主题前面的[集合类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/collections#BKMK_KindsOfCollections)中进行了介绍。

以下示例定义一个名为 `AllColors` 的自定义集合类。 此类实现 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable) 接口，此操作需要实现 [GetEnumerator](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable.getenumerator) 方法。

`GetEnumerator` 方法返回 `ColorEnumerator` 类的一个实例。 `ColorEnumerator` 实现 [IEnumerator](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerator) 接口，此操作需要实现 [Current](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerator.current) 属性、[MoveNext](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerator.movenext) 方法以及 [Reset](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerator.reset) 方法。

```csharp
private static void ListColors()  
{  
    var colors = new AllColors();  
  
    foreach (Color theColor in colors)  
    {  
        Console.Write(theColor.Name + " ");  
    }  
    Console.WriteLine();  
    // Output: red blue green  
}  
  
// Collection class.  
public class AllColors : System.Collections.IEnumerable  
{  
    Color[] _colors =  
    {  
        new Color() { Name = "red" },  
        new Color() { Name = "blue" },  
        new Color() { Name = "green" }  
    };  
  
    public System.Collections.IEnumerator GetEnumerator()  
    {  
        return new ColorEnumerator(_colors);  
  
        // Instead of creating a custom enumerator, you could  
        // use the GetEnumerator of the array.  
        //return _colors.GetEnumerator();  
    }  
  
    // Custom enumerator.  
    private class ColorEnumerator : System.Collections.IEnumerator  
    {  
        private Color[] _colors;  
        private int _position = -1;  
  
        public ColorEnumerator(Color[] colors)  
        {  
            _colors = colors;  
        }  
  
        object System.Collections.IEnumerator.Current  
        {  
            get  
            {  
                return _colors[_position];  
            }  
        }  
  
        bool System.Collections.IEnumerator.MoveNext()  
        {  
            _position++;  
            return (_position < _colors.Length);  
        }  
  
        void System.Collections.IEnumerator.Reset()  
        {  
            _position = -1;  
        }  
    }  
}  
  
// Element class.  
public class Color  
{  
    public string Name { get; set; }  
}  
```

### Iterators

迭代器用于对集合执行自定义迭代。 迭代器可以是一种方法，或是一个 `get` 访问器。 迭代器使用 [yield return](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/yield) 语句返回集合的每一个元素，每次返回一个元素。

通过使用 [foreach](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/foreach-in) 语句调用迭代器。 `foreach` 循环的每次迭代都会调用迭代器。 迭代器中到达 `yield return` 语句时，会返回一个表达式，并保留当前在代码中的位置。 下次调用迭代器时，将从该位置重新开始执行。

有关详细信息，请参阅[迭代器 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/iterators)。

下面的示例使用迭代器方法。 迭代器方法具有位于 [for](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/for) 循环中的 `yield return` 语句。 在 `ListEvenNumbers` 方法中，`foreach` 语句体的每次迭代都会创建对迭代器方法的调用，并将继续到下一个 `yield return` 语句。

```csharp
private static void ListEvenNumbers()  
{  
    foreach (int number in EvenSequence(5, 18))  
    {  
        Console.Write(number.ToString() + " ");  
    }  
    Console.WriteLine();  
    // Output: 6 8 10 12 14 16 18  
}  
  
private static IEnumerable<int> EvenSequence(  
    int firstNumber, int lastNumber)  
{  
    // Yield even numbers in the range.  
    for (var number = firstNumber; number <= lastNumber; number++)  
    {  
        if (number % 2 == 0)  
        {  
            yield return number;  
        }  
    }  
}  
```