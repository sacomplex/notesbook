# [Getting Started with LINQ in C#](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/linq/getting-started-with-linq)

本部分包含可帮助了解 LINQ 文档和示例的其余内容的基本背景信息。

## 本节内容

[LINQ 查询简介 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/introduction-to-linq-queries)
介绍所有语言和数据源共有的基本 LINQ 查询操作的 3 个部分。

[LINQ 和泛型类型 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/linq-and-generic-types)
简单介绍泛型类型在 LINQ 中的使用。

[基本 LINQ 查询操作](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/basic-linq-query-operations)
介绍最常见的查询操作类型及其在 C# 中的表示方法。

[使用 LINQ 进行数据转换 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/data-transformations-with-linq)
介绍转换在查询中检索到的数据时可采用的各种方式。

[LINQ 查询操作中的类型关系](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/type-relationships-in-linq-query-operations)
介绍如何在 LINQ 查询操作的 3 个部分中保留和/或转换类型

[LINQ 中的查询语法和方法语法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/query-syntax-and-method-syntax-in-linq)
比较表达 LINQ 查询的两种方式：方法语法和查询语法。

[支持 LINQ 的 C# 功能](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/features-that-support-linq)
介绍 C# 3.0 中增加的支持 LINQ 的语言构造。

[演练：用 C# 编写查询](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/walkthrough-writing-queries-linq)
关于创建 C# LINQ 项目、添加简单数据源和执行某些基本查询操作的分步说明。

## [Introduction to LINQ Queries](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/introductiontolinqqueries)

*查询*是一种从数据源检索数据的表达式。 查询通常用专门的查询语言来表示。 随着时间的推移，人们已经为各种数据源开发了不同的语言；例如，用于关系数据库的 SQL 和用于 XML 的 XQuery。 因此，开发人员对于他们必须支持的每种数据源或数据格式，都不得不学习一种新的查询语言。 LINQ 通过提供一种跨各种数据源和数据格式使用数据的一致模型，简化了这一情况。 在 LINQ 查询中，始终会用到对象。 可以使用相同的基本编码模式来查询和转换 XML 文档、SQL 数据库、ADO.NET 数据集、.NET 集合中的数据以及对其有 LINQ 提供程序可用的任何其他格式的数据。

### 查询操作的三个部分

所有 LINQ 查询操作都由以下三个不同的操作组成：

1. 获取数据源。
2. 创建查询。
3. 执行查询。

下面的示例演示如何用源代码表示查询操作的三个部分。 为方便起见，此示例将一个整数数组用作数据源；但其中涉及的概念同样适用于其他数据源。 本主题的其余部分也会引用此示例。

```csharp
class IntroToLINQ
{        
    static void Main()
    {
        // The Three Parts of a LINQ Query:
        // 1. Data source.
        int[] numbers = new int[7] { 0, 1, 2, 3, 4, 5, 6 };

        // 2. Query creation.
        // numQuery is an IEnumerable<int>
        var numQuery =
            from num in numbers
            where (num % 2) == 0
            select num;

        // 3. Query execution.
        foreach (int num in numQuery)
        {
            Console.Write("{0,1} ", num);
        }
    }
}
```

下图演示完整的查询操作。 在 LINQ 中，查询的执行与查询本身截然不同；换句话说，如果只是创建查询变量，则不会检索任何数据。

![完整的 LINQ 查询操作](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/media/linq_query.png)

##### 数据源

上例中，数据源是一个数组，因此它隐式支持泛型 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 接口。 这一事实意味着该数据源可以用 LINQ进行查询。 查询在 `foreach` 语句中执行，且 `foreach` 需要 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable) 或 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1)。 支持 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 或派生接口（如泛型 [IQueryable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.iqueryable-1)）的类型称为可查询类型。

可查询类型不需要进行修改或特殊处理就可以用作 LINQ 数据源。 如果源数据还没有作为可查询类型出现在内存中，则 LINQ 提供程序必须以此方式表示源数据。 例如，LINQ to XML 将 XML 文档加载到可查询的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 类型中：

```csharp
// Create a data source from an XML document.
// using System.Xml.Linq;
XElement contacts = XElement.Load(@"c:\myContactList.xml");
```

借助 LINQ to SQL，首先在 Visual Studio 中手动或使用 [Visual Studio 中的 LINQ to SQL 工具](https://docs.microsoft.com/zh-cn/visualstudio/data-tools/linq-to-sql-tools-in-visual-studio2)在设计时创建对象关系映射。 针对这些对象编写查询，然后由 LINQ to SQL 在运行时处理与数据库的通信。 下例中，`Customers` 表示数据库中的特定表，而查询结果的类型 [IQueryable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.iqueryable-1) 派生自 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1)。

```csharp
Northwnd db = new Northwnd(@"c:\northwnd.mdf");  
  
// Query for customers in London.  
IQueryable<Customer> custQuery =  
    from cust in db.Customers  
    where cust.City == "London"  
    select cust;  
```

有关如何创建特定类型的数据源的详细信息，请参阅各种 LINQ 提供程序的文档。 但基本规则很简单：LINQ 数据源是支持泛型 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 接口或从中继承的接口的任意对象。

> 支持非泛型 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable) 接口的类型（如 [ArrayList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.arraylist)）还可用作 LINQ 数据源。 有关详细信息，请参阅[如何：使用 LINQ 查询 ArrayList (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-query-an-arraylist-with-linq)。

### 查询

查询指定要从数据源中检索的信息。 查询还可以指定在返回这些信息之前如何对其进行排序、分组和结构化。 查询存储在查询变量中，并用查询表达式进行初始化。 为使编写查询的工作变得更加容易，C# 引入了新的查询语法。

上一个示例中的查询从整数数组中返回所有偶数。 该查询表达式包含三个子句：`from`、`where` 和 `select`。（如果熟悉 SQL，会注意到这些子句的顺序与 SQL 中的顺序相反。）`from` 子句指定数据源，`where` 子句应用筛选器，`select` 子句指定返回的元素的类型。 [LINQ 查询表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/linq-query-expressions/index)一节中详细讨论了这些子句和其他查询子句。 目前需要注意的是，在 LINQ 中，查询变量本身不执行任何操作并且不返回任何数据。 它只是存储在以后某个时刻执行查询时为生成结果而必需的信息。 有关在后台如何构造查询的详细信息，请参阅[标准查询运算符概述 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/standard-query-operators-overview)。

> 还可以使用方法语法来表示查询。 有关详细信息，请参阅 [LINQ 中的查询语法和方法语法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/query-syntax-and-method-syntax-in-linq)。

#### 查询执行

##### 延迟执行

如前所述，查询变量本身只存储查询命令。 查询的实际执行将推迟到在 `foreach` 语句中循环访问查询变量之后进行。 此概念称为*延迟执行*，下面的示例对此进行了演示：

```csharp
//  Query execution. 
foreach (int num in numQuery)
{
    Console.Write("{0,1} ", num);
}
```

`foreach` 语句也是检索查询结果的地方。 例如，在上一个查询中，迭代变量 `num` 保存了返回的序列中的每个值（一次保存一个值）。

由于查询变量本身从不保存查询结果，因此可以根据需要随意执行查询。 例如，可以通过一个单独的应用程序持续更新数据库。 在应用程序中，可以创建一个检索最新数据的查询，并可以按某一时间间隔反复执行该查询以便每次检索不同的结果。

##### 强制立即执行

对一系列源元素执行聚合函数的查询必须首先循环访问这些元素。 `Count`、`Max`、`Average` 和 `First` 就属于此类查询。 由于查询本身必须使用 `foreach` 以便返回结果，因此这些查询在执行时不使用显式 `foreach` 语句。 另外还要注意，这些类型的查询返回单个值，而不是 `IEnumerable` 集合。 下面的查询返回源数组中偶数的计数：

```csharp
var evenNumQuery = 
    from num in numbers
    where (num % 2) == 0
    select num;

int evenNumCount = evenNumQuery.Count();
```

要强制立即执行任何查询并缓存其结果，可调用 [ToList](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.tolist) 或 [ToArray](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.toarray) 方法。

```csharp
List<int> numQuery2 =
    (from num in numbers
     where (num % 2) == 0
     select num).ToList();

// or like this:
// numQuery3 is still an int[]

var numQuery3 =
    (from num in numbers
     where (num % 2) == 0
     select num).ToArray();
```

此外，还可以通过在紧跟查询表达式之后的位置放置一个 `foreach` 循环来强制执行查询。 但是，通过调用 `ToList` 或 `ToArray`，也可以将所有数据缓存在单个集合对象中。

##  [LINQ and Generic Types](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/linqandgenerictypes)

LINQ 查询基于 .NET Framework 2.0 版中引入的泛型类型。 无需深入了解泛型即可开始编写查询。 但是，可能需要了解 2 个基本概念：

1. 创建泛型集合类（如 [List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1)）的实例时，需将“T”替换为列表将包含的对象类型。 例如，字符串列表表示为 `List<string>`，`Customer` 对象列表表示为 `List<Customer>`。 泛型列表属于强类型，与将其元素存储为 [Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object) 的集合相比，泛型列表具备更多优势。 如果尝试将 `Customer` 添加到 `List<string>`，则会在编译时收到错误。 泛型集合易于使用的原因是不必执行运行时类型转换。
2. [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 是一个接口，通过该接口，可以使用 `foreach` 语句来枚举泛型集合类。 泛型集合类支持 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1)，正如非泛型集合类（如 [ArrayList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.arraylist)）支持 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable)。

有关泛型的详细信息，请参阅[泛型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/generics/index)。

### LINQ 查询中的 IEnumerable<T> 变量

LINQ 查询变量被类型化为 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 或者派生类型（如 [IQueryable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.iqueryable-1)）。 看到类型化为 `IEnumerable<Customer>` 的查询变量时，这只意味着执行查询时，该查询将生成包含零个或多个 `Customer` 对象的序列。

```csharp
IEnumerable<Customer> customerQuery =
    from cust in customers
    where cust.City == "London"
    select cust;

foreach (Customer customer in customerQuery)
{
    Console.WriteLine(customer.LastName + ", " + customer.FirstName);
}
```

有关详细信息，请参阅 [LINQ 查询操作中的类型关系](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/type-relationships-in-linq-query-operations)。

### 让编译器处理泛型类型声明

如果愿意，可以使用 [var](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/var) 关键字来避免使用泛型语法。 `var` 关键字指示编译器通过查看在 `from` 子句中指定的数据源来推断查询变量的类型。 以下示例生成与上例相同的编译代码：

```csharp
var customerQuery2 = 
    from cust in customers
    where cust.City == "London"
    select cust;

foreach(var customer in customerQuery2)
{
    Console.WriteLine(customer.LastName + ", " + customer.FirstName);
}
```

变量的类型明显或显式指定嵌套泛型类型（如由组查询生成的那些类型）并不重要时，`var` 关键字很有用。 通常，我们建议如果使用 `var`，应意识到这可能使他人更难以理解代码。 有关详细信息，请参阅[隐式类型局部变量](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/implicitly-typed-local-variables)。

##  [Basic LINQ Query Operations](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/basiclinqqueryoperations)

本主题简要介绍了 LINQ 查询表达式和一些在查询中执行的典型操作。 下面各主题中提供了更具体的信息：

[LINQ 查询表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/linq-query-expressions/index)

[标准查询运算符概述 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/standard-query-operators-overview)

[演练：用 C# 编写查询](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/walkthrough-writing-queries-linq)

> 如果你已熟悉查询语言（如 SQL 或 XQuery），则可以跳过本主题的大部分内容。 请参阅下一节中的“`from`子句”部分，了解 LINQ 查询表达式中的子句顺序。

### 获取数据源

在 LINQ 查询中，第一步是指定数据源。 和大多数编程语言相同，在使用 C# 时也必须先声明变量，然后才能使用它。 在 LINQ 查询中，先使用 `from` 子句引入数据源 (`customers`) 和范围变量 (`cust`)。

```csharp
//queryAllCustomers is an IEnumerable<Customer>
var queryAllCustomers = from cust in customers
                        select cust;
```

范围变量就像 `foreach` 循环中的迭代变量，但查询表达式中不会真正发生迭代。 当执行查询时，范围变量将充当对 `customers` 中每个连续的元素的引用。 由于编译器可以推断 `cust` 的类型，因此无需显式指定它。 可通过 `let` 子句引入其他范围变量。 有关详细信息，请参阅 [let 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/let-clause)。

> 对于非泛型数据源（例如 [ArrayList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.arraylist)），必须显式键入范围变量。 有关详细信息，请参阅[如何：使用 LINQ 查询 ArrayList (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-query-an-arraylist-with-linq) 和 [from 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/from-clause)。

### 筛选

或许，最常见的查询操作是以布尔表达式的形式应用筛选器。 筛选器使查询仅返回表达式为 true 的元素。 将通过使用 `where` 子句生成结果。 筛选器实际指定要从源序列排除哪些元素。 在下列示例中，仅返回地址位于“London”的 `customers`。

```csharp
var queryLondonCustomers = from cust in customers
                           where cust.City == "London"
                           select cust;
```

可使用熟悉的 C# 逻辑 `AND` 和 `OR` 运算符，在 `where` 子句中根据需要应用尽可能多的筛选器表达式。 例如，若要仅返回来自“London”的客户 `AND` 该客户名称为“Devon”，可编写以下代码：

```csharp
where cust.City=="London" && cust.Name == "Devon"
```

要返回来自 London 或 Paris 的客户，可编写以下代码：

```csharp
where cust.City == "London" || cust.City == "Paris"
```

有关详细信息，请参阅 [where 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/where-clause)。

### 中间件排序

对返回的数据进行排序通常很方便。 `orderby` 子句根据要排序类型的默认比较器，对返回序列中的元素排序。 例如，基于 `Name` 属性，可将下列查询扩展为对结果排序。 由于 `Name` 是字符串，默认比较器将按字母顺序从 A 到 Z 进行排序。

```csharp
var queryLondonCustomers3 = 
    from cust in customers
    where cust.City == "London"
    orderby cust.Name ascending
    select cust;
```

要对结果进行从 Z 到 A 的逆序排序，请使用 `orderby…descending` 子句。

有关详细信息，请参阅 [orderby 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/orderby-clause)。

### 分组

`group` 子句用于对根据您指定的键所获得的结果进行分组。 例如，可指定按 `City` 对结果进行分组，使来自 London 或 Paris 的所有客户位于单独的组内。 在这种情况下，`cust.City` 是键。

```csharp
// queryCustomersByCity is an IEnumerable<IGrouping<string, Customer>>
  var queryCustomersByCity =
      from cust in customers
      group cust by cust.City;

  // customerGroup is an IGrouping<string, Customer>
  foreach (var customerGroup in queryCustomersByCity)
  {
      Console.WriteLine(customerGroup.Key);
      foreach (Customer customer in customerGroup)
      {
          Console.WriteLine("    {0}", customer.Name);
      }
  }
```

使用 `group` 子句结束查询时，结果将以列表的形式列出。 列表中的每个元素都是具有 `Key` 成员的对象，列表中的元素根据该键被分组。 在循环访问生成组序列的查询时，必须使用嵌套 `foreach` 循环。 外层循环循环访问每个组，内层循环循环访问每个组的成员。

如果必须引用某个组操作的结果，可使用 `into` 关键字创建能被进一步查询的标识符。 下列查询仅返回包含两个以上客户的组：

```csharp
// custQuery is an IEnumerable<IGrouping<string, Customer>>
var custQuery =
    from cust in customers
    group cust by cust.City into custGroup
    where custGroup.Count() > 2
    orderby custGroup.Key
    select custGroup;
```

有关详细信息，请参阅 [group 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/group-clause)。

### 联接

联接操作在不同序列间创建关联，这些序列在数据源中未被显式模块化。 例如，可通过执行联接来查找所有位置相同的客户和分销商。 在 LINQ 中，`join` 子句始终作用于对象集合，而非直接作用于数据库表。

```csharp
var innerJoinQuery =
    from cust in customers
    join dist in distributors on cust.City equals dist.City
    select new { CustomerName = cust.Name, DistributorName = dist.Name };
```

在 LINQ 中，不必像在 SQL 中那样频繁使用 `join`，因为 LINQ 中的外键在对象模型中表示为包含项集合的属性。例如 `Customer` 对象包含 `Order` 对象的集合。 不必执行联接，只需使用点表示法访问订单：

```csharp
from order in Customer.Orders...  
```

有关详细信息，请参阅 [join 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/join-clause)。

### 选择（投影）

`select` 子句生成查询结果并指定每个返回的元素的“形状”或类型。 例如，可以指定结果包含的是整个 `Customer`对象、仅一个成员、成员的子集，还是某个基于计算或新对象创建的完全不同的结果类型。 当 `select` 子句生成除源元素副本以外的内容时，该操作称为投影。 使用投影转换数据是 LINQ 查询表达式的一种强大功能。 有关详细信息，请参阅[使用 LINQ (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/data-transformations-with-linq) 和 [select 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/select-clause)进行数据转换。

##  [Data Transformations with LINQ](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/datatransformationswithlinq)

语言集成查询 (LINQ) 不只是检索数据。 它也是用于转换数据的强大工具。 通过使用 LINQ 查询，可以使用源序列作为输入，并通过多种方式对其进行修改，以创建新的输出序列。 通过排序和分组，你可以修改序列本身，而无需修改这些元素本身。 但也许 LINQ 查询最强大的功能是创建新类型。 这可以在 [select](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/select-clause) 子句中完成。 例如，可以执行下列任务：

- 将多个输入序列合并为具有新类型的单个输出序列。
- 创建其元素由源序列中每个元素的一个或多个属性组成的输出序列。
- 创建其元素由对源数据执行的操作结果组成的输出序列。
- 创建其他格式的输出序列。 例如，可以将数据从 SQL 行或文本文件转换为 XML。

这只是几个例子。 当然，可以以各种方式在同一查询中组合这些转换。 此外，一个查询的输出序列可以用作新查询的输入序列。

### 将多个输入联接到一个输出序列中

可以使用 LINQ 查询创建包含元素的输出序列，这些元素来自多个输入序列。 以下示例演示如何组合两个内存中数据结构，但相同的原则可应用于组合来自 XML 或 SQL 或数据集源的数据。 假设以下两种类类型：

```csharp
class Student
{
    public string First { get; set; }
    public string Last {get; set;}
    public int ID { get; set; }
    public string Street { get; set; }
    public string City { get; set; }
    public List<int> Scores;
}

class Teacher
{
    public string First { get; set; }
    public string Last { get; set; }
    public int ID { get; set; } 
    public string City { get; set; }
}
```

以下示例演示了查询：

```csharp
class DataTransformations
{
    static void Main()
    {
        // Create the first data source.
        List<Student> students = new List<Student>()
        {
            new Student { First="Svetlana",
                Last="Omelchenko",
                ID=111,
                Street="123 Main Street",
                City="Seattle",
                Scores= new List<int> { 97, 92, 81, 60 } },
            new Student { First="Claire",
                Last="O’Donnell",
                ID=112,
                Street="124 Main Street",
                City="Redmond",
                Scores= new List<int> { 75, 84, 91, 39 } },
            new Student { First="Sven",
                Last="Mortensen",
                ID=113,
                Street="125 Main Street",
                City="Lake City",
                Scores= new List<int> { 88, 94, 65, 91 } },
        };

        // Create the second data source.
        List<Teacher> teachers = new List<Teacher>()
        {                
            new Teacher { First="Ann", Last="Beebe", ID=945, City="Seattle" },
            new Teacher { First="Alex", Last="Robinson", ID=956, City="Redmond" },
            new Teacher { First="Michiyo", Last="Sato", ID=972, City="Tacoma" }
        };
        
        // Create the query.
        var peopleInSeattle = (from student in students
                    where student.City == "Seattle"
                    select student.Last)
                    .Concat(from teacher in teachers
                            where teacher.City == "Seattle"
                            select teacher.Last);

        Console.WriteLine("The following students and teachers live in Seattle:");
        // Execute the query.
        foreach (var person in peopleInSeattle)
        {
            Console.WriteLine(person);
        }
        
        Console.WriteLine("Press any key to exit.");
        Console.ReadKey();
    }
}
/* Output:
    The following students and teachers live in Seattle:
    Omelchenko
    Beebe
 */
```

有关详细信息，请参阅 [join 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/join-clause)和 [select 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/select-clause)。

### 选择每个源元素的子集

有两种主要方法来选择源序列中每个元素的子集：

1. 若要仅选择源元素的一个成员，请使用点操作。 在以下示例中，假设 `Customer` 对象包含多个公共属性，包括名为 `City` 的字符串。 在执行时，此查询将生成字符串的输出序列。

   ```csharp
   var query = from cust in Customers  
               select cust.City;  
   ```

2. 若要创建包含多个源元素属性的元素，可以使用带有命名对象或匿名类型的对象初始值设定项。 以下示例演示如何使用匿名类型封装每个 `Customer` 元素的两个属性：

   ```csharp
   var query = from cust in Customer  
               select new {Name = cust.Name, City = cust.City};  
   ```

有关详细信息，请参阅[对象和集合初始值设定项](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/object-and-collection-initializers)和[匿名类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/anonymous-types)。

### 将内存中对象转换为 XML

LINQ 查询可以方便地在内存中数据结构、SQL 数据库、ADO.NET 数据集和 XML 流或文档之间转换数据。 以下示例将内存中数据结构中的对象转换为 XML 元素。

```csharp
class XMLTransform
{
    static void Main()
    {            
        // Create the data source by using a collection initializer.
        // The Student class was defined previously in this topic.
        List<Student> students = new List<Student>()
        {
            new Student {First="Svetlana", Last="Omelchenko", ID=111, Scores = new List<int>{97, 92, 81, 60}},
            new Student {First="Claire", Last="O’Donnell", ID=112, Scores = new List<int>{75, 84, 91, 39}},
            new Student {First="Sven", Last="Mortensen", ID=113, Scores = new List<int>{88, 94, 65, 91}},
        };

        // Create the query.
        var studentsToXML = new XElement("Root",
            from student in students
            let scores = string.Join(",", student.Scores)
            select new XElement("student",
                       new XElement("First", student.First),
                       new XElement("Last", student.Last),
                       new XElement("Scores", scores)
                    ) // end "student"
                ); // end "Root"

        // Execute the query.
        Console.WriteLine(studentsToXML);

        // Keep the console open in debug mode.
        Console.WriteLine("Press any key to exit.");
        Console.ReadKey();
    }
}
```

此代码生成以下 XML 输出：

```xml
<Root>  
  <student>  
    <First>Svetlana</First>  
    <Last>Omelchenko</Last>  
    <Scores>97,92,81,60</Scores>  
  </student>  
  <student>  
    <First>Claire</First>  
    <Last>O'Donnell</Last>  
    <Scores>75,84,91,39</Scores>  
  </student>  
  <student>  
    <First>Sven</First>  
    <Last>Mortensen</Last>  
    <Scores>88,94,65,91</Scores>  
  </student>  
</Root>  
```

有关详细信息，请参阅[在 C# 中创建 XML 树 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/creating-xml-trees-linq-to-xml-2)。

### 对源元素执行操作

输出序列可能不包含源序列中的任何元素或元素属性。 输出可能是使用源元素作为输入参数而计算得出的值序列。 以下简单查询在执行时会输出一串字符串，其值表示基于 `double` 类型的元素的源序列的计算结果。

> 如果查询将被转换为另一个域，则不支持在查询表达式中调用方法。 例如，不能在 LINQ to SQL 中调用普通的 C# 方法，因为 SQL Server 没有用于它的上下文。 但是，可以将存储过程映射到方法并调用这些方法。 有关详细信息，请参阅[存储过程](https://docs.microsoft.com/zh-cn/dotnet/framework/data/adonet/sql/linq/stored-procedures)。

```csharp
class FormatQuery
{
    static void Main()
    {            
        // Data source.
        double[] radii = { 1, 2, 3 };

        // Query.
        IEnumerable<string> query =
            from rad in radii
            select $"Area = {rad * rad * Math.PI:F2}";

        // Query execution. 
        foreach (string s in query)
            Console.WriteLine(s);

        // Keep the console open in debug mode.
        Console.WriteLine("Press any key to exit.");
        Console.ReadKey();
    }
}
/* Output:
    Area = 3.14
    Area = 12.57
    Area = 28.27
*/
```

##  [Type Relationships in LINQ Query Operations](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/typerelationshipsinlinqqueryoperations)

若要有效编写查询，应了解完整的查询操作中的变量类型是如何全部彼此关联的。 如果了解这些关系，就能够更容易地理解文档中的 LINQ 示例和代码示例。 另外，还能了解在使用 `var` 隐式对变量进行类型化时的后台操作。

LINQ 查询操作在数据源、查询本身及查询执行中是强类型化的。 查询中变量的类型必须与数据源中元素的类型和 `foreach` 语句中迭代变量的类型兼容。 此强类型保证在编译时捕获类型错误，以便可以在用户遇到这些错误之前更正它们。

为了演示这些类型关系，下面的大多数示例对所有变量使用显式类型。 最后一个示例演示在利用使用 [var](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/var) 的隐式类型时，如何应用相同的原则。

### 不转换源数据的查询

下图演示不对数据执行转换的 LINQ to Objects 查询操作。 源包含一个字符串序列，查询输出也是一个字符串序列。

![LINQ 查询中的数据类型关系](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/media/linq_flow1.png)

1. 数据源的类型参数决定范围变量的类型。
2. 所选对象的类型决定查询变量的类型。 此处的 `name` 是一个字符串。 因此，查询变量是一个 `IEnumerable<string>`。
3. 在 `foreach` 语句中循环访问查询变量。 因为查询变量是一个字符串序列，所以迭代变量也是一个字符串。

### 转换源数据的查询

下图演示对数据执行简单转换的 LINQ to SQL 查询操作。 查询将一个 `Customer` 对象序列用作输入，并只选择结果中的 `Name` 属性。 因为 `Name` 是一个字符串，所以查询生成一个字符串序列作为输出。

![转换数据类型的查询](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/media/linq_flow2.png)

1. 数据源的类型参数决定范围变量的类型。
2. `select` 语句返回 `Name` 属性，而非完整的 `Customer` 对象。 因为 `Name` 是一个字符串，所以 `custNameQuery` 的类型参数是 `string`，而非 `Customer`。
3. 因为 `custNameQuery` 是一个字符串序列，所以 `foreach` 循环的迭代变量也必须是 `string`。

下图演示稍微复杂的转换。 `select` 语句返回只捕获原始 `Customer` 对象的两个成员的匿名类型。

![转换数据类型的查询](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/media/linq_flow3.png)

1. 数据源的类型参数始终为查询中范围变量的类型。
2. 因为 `select` 语句生成匿名类型，所以必须使用 `var` 隐式类型化查询变量。
3. 因为查询变量的类型是隐式的，所以 `foreach` 循环中的迭代变量也必须是隐式的。

### 让编译器推断类型信息

虽然需要了解查询操作中的类型关系，但是也可以选择让编译器执行全部工作。 关键字 [var](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/var) 可用于查询操作中的任何本地变量。 下图与前面讨论的第二个示例相似。 但是，编译器为查询操作中的各个变量提供强类型。

![具有隐式类型的类型流](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/media/linq_flow4.png)

有关 `var` 的详细信息，请参阅[隐式类型本地变量](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/implicitly-typed-local-variables)。

## [Query Syntax and Method Syntax in LINQ](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/querysyntaxandmethodsyntaxinlinq)

介绍性的语言集成查询 (LINQ) 文档中的大多数查询是使用 LINQ 声明性查询语法编写的。 但是在编译代码时，查询语法必须转换为针对 .NET 公共语言运行时 (CLR) 的方法调用。 这些方法调用会调用标准查询运算符（名称为 `Where`、`Select`、`GroupBy`、`Join`、`Max` 和 `Average` 等）。 可以使用方法语法（而不查询语法）来直接调用它们。

查询语法和方法语法在语义上是相同的，但是许多人发现查询语法更简单且更易于阅读。 某些查询必须表示为方法调用。 例如，必须使用方法调用表示检索与指定条件匹配的元素数的查询。 还必须对检索源序列中具有最大值的元素的查询使用方法调用。 [System.Linq](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq) 命名空间中的标准查询运算符的参考文档通常使用方法语法。 因此，即使在开始编写 LINQ 查询时，熟悉如何在查询和查询表达式本身中使用方法语法也十分有用。

### 标准查询运算符扩展方法

下面的示例演示一个简单查询表达式以及编写为基于方法的查询的语义上等效的查询。

```csharp
class QueryVMethodSyntax
{
    static void Main()
    {
        int[] numbers = { 5, 10, 8, 3, 6, 12};

        //Query syntax:
        IEnumerable<int> numQuery1 = 
            from num in numbers
            where num % 2 == 0
            orderby num
            select num;

        //Method syntax:
        IEnumerable<int> numQuery2 = numbers.Where(num => num % 2 == 0).OrderBy(n => n);

        foreach (int i in numQuery1)
        {
            Console.Write(i + " ");
        }
        Console.WriteLine(System.Environment.NewLine);
        foreach (int i in numQuery2)
        {
            Console.Write(i + " ");
        }
        
        // Keep the console open in debug mode.
        Console.WriteLine(System.Environment.NewLine);
        Console.WriteLine("Press any key to exit");
        Console.ReadKey();
    }
}
/*
    Output:
    6 8 10 12
    6 8 10 12
 */
```

这两个示例的输出是相同的。 可以看到查询变量的类型在两种形式中是相同的：[IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1)。

为了了解基于方法的查询，我们来仔细讨论它。 在表达式右侧，请注意，`where` 子句现在表示为 `numbers` 对象上的实例方法，它具有类型 `IEnumerable<int>`（如同你会回忆起的那样）。 如果熟悉泛型 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 接口，则会知道它没有 `Where` 方法。 但是，如果在 Visual Studio IDE 中调用 IntelliSense 完成列表，则不仅会看到 `Where` 方法，还会看到许多其他方法（如 `Select`、`SelectMany`、`Join` 和 `Orderby`）。 这些都是标准查询运算符。

![Intellisense 中的标准查询运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/media/standardqueryops.png)

虽然看起来似乎 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 进行了重新定义以包括这些其他方法，不过实际上情况并非如此。 标准查询运算符作为一种新类型的方法（称为扩展方法）来实现。 扩展方法可“扩展”现有类型；它们可以如同类型上的实例方法一样进行调用。 标准查询运算符扩展了 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1)，因此可以写入 `numbers.Where(...)`。

若要开始使用 LINQ，你在扩展方法方面实际需要了解的所有内容是如何使用正确的 `using` 指令将它们引入应用程序的范围。 从应用程序的角度来看，扩展方法与常规实例方法是相同的。

有关扩展方法的详细信息，请参阅[扩展方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/extension-methods)。 有关标准查询运算符的详细信息，请参阅[标准查询运算符概述 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/standard-query-operators-overview)。 某些 LINQ 提供程序（如 LINQ to SQL 和 LINQ to XML），会实现自己的标准查询运算符，并为 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 之外的其他类型实现额外的扩展方法。

### Lambda 表达式

在上面的示例中，请注意，条件表达式 (`num % 2 == 0`) 作为内联参数传递给 `Where` 方法：`Where(num => num % 2 == 0).` 此内联表达式称为 lambda 表达式。 可采用匿名方法、泛型委托或表达式树的形式编写原本必须以更繁琐的形式编写的代码，这是一种便利的方式。 在 C# 中，`=>` 是 lambda 运算符（读为“转到”）。 运算符左侧的 `num` 是输入变量，它与查询表达式中的 `num` 对应。 编译器可以推断出 `num` 的类型，因为它知道 `numbers` 是泛型 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 类型。 Lambda 的主体与查询语法中或任何其他 C# 表达式或语句中的表达式完全相同；它可以包含方法调用和其他复杂逻辑。 “返回值”就是表达式结果。

若要开始使用 LINQ，不必大量使用 lambda。 但是，某些查询只能采用方法语法进行表示，而其中一些查询需要 lambda 表达式。 进一步熟悉 lambda 之后，你会发现它们是 LINQ 工具箱中一种强大而灵活的工具。 有关详细信息，请参阅 [Lambda 表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/lambda-expressions)。

### 查询的可组合性

在前面的代码示例中，请注意，`OrderBy` 方法通过对 `Where` 调用使用点运算符来调用。 `Where` 会生成经过筛选的序列，然后 `Orderby` 通过进行排序来对该序列进行操作。 由于查询返回 `IEnumerable`，因此可通过将方法调用链接在一起在方法语法中撰写查询。 这是当你使用查询语法编写查询时，编译器在幕后进行的工作。 因为查询变量不存储查询的结果，所以可以随时修改它或将它用作新查询的基础（即使在执行过它之后）。

##  [C# Features That Support LINQ](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/featuresthatsupportlinq)

下一节介绍 C# 3.0 中引入的新语言构造。 虽然这些新功能在一定程度上都用于 LINQ 查询，但并不限于 LINQ，如果认为有用，在任何情况下都可以使用这些新功能。

### 查询表达式

查询表达式使用类似于 SQL 或 XQuery 的声明性语法来查询 IEnumerable 集合。 在编译时，查询语法转换为对 LINQ 提供程序的标准查询运算符扩展方法实现的方法调用。 应用程序通过使用 `using` 指令指定适当的命名空间来控制范围内的标准查询运算符。 下面的查询表达式获取一个字符串数组，按字符串中的第一个字符对字符串进行分组，然后对各组进行排序。

```csharp
var query = from str in stringArray  
            group str by str[0] into stringGroup  
            orderby stringGroup.Key  
            select stringGroup;  
```

有关详细信息，请参阅 [LINQ 查询表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/linq-query-expressions/index)。

### 隐式类型化变量 (var)

可以使用 [var](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/var) 修饰符来指示编译器推断并分配类型，而不必在声明并初始化变量时显式指定类型，如下所示：

```csharp
var number = 5;  
var name = "Virginia";  
var query = from str in stringArray  
            where str[0] == 'm'  
            select str;  
```

声明为 `var` 的变量与显式指定其类型的变量一样都是强类型。 通过使用 `var`，可以创建匿名类型，但它只能用于本地变量。 也可以使用隐式类型声明数组。

有关详细信息，请参阅[隐式类型局部变量](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/implicitly-typed-local-variables)。

### 对象和集合初始值设定项

通过对象和集合初始值设定项，初始化对象时无需为对象显式调用构造函数。 初始值设定项通常用在将源数据投影到新数据类型的查询表达式中。 假定一个类名为 `Customer`，具有公共 `Name` 和 `Phone` 属性，可以按下列代码中所示使用对象初始值设定项：

```csharp
Customer cust = new Customer { Name = "Mike", Phone = "555-1212" };  
```

继续我们的 `Customer` 类，假设有一个名为 `IncomingOrders` 的数据源，并且每个订单具有一个较大的 `OrderSize`，我们希望基于该订单创建新的 `Customer`。 可以在此数据源上执行 LINQ 查询，并使用对象初始化来填充集合：

```csharp
var newLargeOrderCustomers = from o in IncomingOrders
                            where o.OrderSize > 5
                            select new Customer { Name = o.Name, Phone = o.Phone };
```

数据源可能具有比 `Customer` 类更多的属性，例如 `OrderSize`，但执行对象初始化后，从查询返回的数据被定型为所需的数据类型；我们选择与我们的类相关的数据。 因此，我们现在有填充了我们想要的多个新 `Customer` 的 `IEnumerable`。 上述代码也可以使用 LINQ 的方法语法编写：

```csharp
var newLargeOrderCustomers = IncomingOrders.Where(x => x.OrderSize > 5).Select(y => new Customer { Name = y.Name, Phone = y.Phone });
```

有关详细信息，请参见:

- [对象和集合初始值设定项](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/object-and-collection-initializers)
- [标准查询运算符的查询表达式语法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/query-expression-syntax-for-standard-query-operators)

### 匿名类型

匿名类型由编译器构造，且类型名称只可用于编译器。 匿名类型提供一种在查询结果中对一组属性临时分组的简便方法，无需定义单独的命名类型。 使用新的表达式和对象初始值设定项初始化匿名类型，如下所示：

```csharp
select new {name = cust.Name, phone = cust.Phone};  
```

有关详细信息，请参阅[匿名类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/anonymous-types)。

### 扩展方法

扩展方法是一种可与类型关联的静态方法，因此可以像实例方法那样对类型调用它。 实际上，利用此功能，可以将新方法“添加”到现有类型，而不会实际修改它们。 标准查询运算符是一组扩展方法，它们为实现 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的任何类型提供 LINQ 查询功能。

有关详细信息，请参阅[扩展方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/extension-methods)。

### Lambda 表达式

Lambda 表达式是一种内联函数，该函数使用 => 运算符将输入参数与函数体分离，并且可以在编译时转换为委托或表达式树。 在 LINQ 编程中，在对标准查询运算符进行直接方法调用时，会遇到 lambda 表达式。

有关详细信息，请参见:

- [匿名函数](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/anonymous-functions)
- [Lambda 表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/lambda-expressions)
- [表达式树 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/expression-trees/index)

## [Walkthrough: Writing Queries in C# (LINQ)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/walkthroughwritingquerieslinq)

### 创建 C# 项目

> 以下说明适用于 Visual Studio。 如果使用其他开发环境，请创建包含对 System.Core.dll 的引用的控制台项目和用于 [System.Linq](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq) 命名空间的 `using` 指令。

#### 在 Visual Studio 中创建项目

1. 启动 Visual Studio。

2. 在菜单栏上，依次选择“文件” 、“新建” 、“项目” 。

   **“新建项目”** 对话框随即打开。

3. 依次展开“已安装”、“模板”、“Visual C#”，然后选择“控制台应用程序”。

4. 在“名称”文本框中，输入不同的名称或接受默认名称，然后选择“确定”按钮。

   新项目将出现在“解决方案资源管理器”中。

5. 注意，此项目包含对 System.Core.dll 的引用和用于 [System.Linq](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq) 命名空间的 `using` 指令。

### 创建内存中的数据源

用于查询的数据源是 `Student` 对象的简单列表。 每个 `Student` 记录都有名字、姓氏和整数数组（表示该学生在课堂上的测试分数）。 将此代码复制到项目中。 请注意下列特性：

- `Student` 类包含自动实现的属性。
- 列表中的每个学生都可使用对象初始值设定项进行初始化。
- 列表本身可使用集合初始值设定项进行初始化。

将在不显式调用任何构造函数和使用显式成员访问的情况下初始化并实例化整个数据结构。 有关这些新功能的详细信息，请参阅[自动实现的属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/auto-implemented-properties)与[对象和集合初始值设定项](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/object-and-collection-initializers)。

#### 添加数据源

- 向项目中的 `Program` 类添加 `Student` 类和经过初始化的学生列表。

  ```csharp
  public class Student
  {
      public string First { get; set; }
      public string Last { get; set; }
      public int ID { get; set; }
      public List<int> Scores;
  }
  
  // Create a data source by using a collection initializer.
  static List<Student> students = new List<Student>
  {
      new Student {First="Svetlana", Last="Omelchenko", ID=111, Scores= new List<int> {97, 92, 81, 60}},
      new Student {First="Claire", Last="O'Donnell", ID=112, Scores= new List<int> {75, 84, 91, 39}},
      new Student {First="Sven", Last="Mortensen", ID=113, Scores= new List<int> {88, 94, 65, 91}},
      new Student {First="Cesar", Last="Garcia", ID=114, Scores= new List<int> {97, 89, 85, 82}},
      new Student {First="Debra", Last="Garcia", ID=115, Scores= new List<int> {35, 72, 91, 70}},
      new Student {First="Fadi", Last="Fakhouri", ID=116, Scores= new List<int> {99, 86, 90, 94}},
      new Student {First="Hanying", Last="Feng", ID=117, Scores= new List<int> {93, 92, 80, 87}},
      new Student {First="Hugo", Last="Garcia", ID=118, Scores= new List<int> {92, 90, 83, 78}},
      new Student {First="Lance", Last="Tucker", ID=119, Scores= new List<int> {68, 79, 88, 92}},
      new Student {First="Terry", Last="Adams", ID=120, Scores= new List<int> {99, 82, 81, 79}},
      new Student {First="Eugene", Last="Zabokritski", ID=121, Scores= new List<int> {96, 85, 91, 60}},
      new Student {First="Michael", Last="Tucker", ID=122, Scores= new List<int> {94, 92, 91, 91}}
  };
  ```

#### 向学生列表添加新学生

1. 向 `Students` 列表添加一个新 `Student`，并按自己的选择使用名称和测试分数。 尝试键入所有新学生信息，以便更好地了解对象初始值设定项的语法。

### 创建查询

#### 创建简单查询

- 在应用程序的 `Main` 方法中，创建简单查询，执行该查询时，将生成所有在第一次测试中分数高于 90 的学生的列表。 注意，由于选定全部 `Student` 对象，所以查询的类型为 `IEnumerable<Student>`。 尽管该代码也可以通过使用 [var](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/var) 关键字来使用隐式类型化，但可以使用显式类型化清楚地展示结果。 （有关 `var` 的详细信息，请参阅[隐式类型化局部变量](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/implicitly-typed-local-variables)。）

  另请注意，查询的范围变量 `student` 用作指向源中每个 `Student` 引用，提供对每个对象的成员访问。

```csharp
// Create the query.
// The first line could also be written as "var studentQuery ="
IEnumerable<Student> studentQuery =
    from student in students
    where student.Scores[0] > 90
    select student;
```

### 执行查询

#### 执行查询

1. 现在，编写 `foreach` 循环，用于执行查询。 注意以下有关代码的注意事项：
   - 通过 `foreach` 循环中的迭代变量，可访问返回的序列中的每个元素。
   - 此变量的类型是 `Student`，并且可与查询变量 `IEnumerable<Student>` 的类型兼容。
2. 添加此代码后，生成并运行应用程序，以在“控制台”窗口中查看结果。

```csharp
// Execute the query.
// var could be used here also.
foreach (Student student in studentQuery)
{
    Console.WriteLine("{0}, {1}", student.Last, student.First);
}

// Output:
// Omelchenko, Svetlana
// Garcia, Cesar
// Fakhouri, Fadi
// Feng, Hanying
// Garcia, Hugo
// Adams, Terry
// Zabokritski, Eugene
// Tucker, Michael
```

#### 添加其他筛选条件

1. 在 `where` 子句中，可以组合多个布尔条件，以便进一步细化查询。 以下代码添加了一个条件，以便该查询返回第一个分数高于 90 分，并且最后一个分数低于 80 分的那些学生。 `where` 子句应与以下代码类似。

   C#复制

   ```csharp
   where student.Scores[0] > 90 && student.Scores[3] < 80  
   ```

   有关详细信息，请参阅 [where 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/where-clause)。

### 修改查询

#### 对结果进行排序

1. 如果结果按某种顺序排列，则浏览结果会更容易。 你可以根据源元素中的任何可访问字段对返回的序列进行排序。 例如，以下 `orderby` 子句将结果按照每个学生的姓氏以字母从 A 到 Z 的顺序排列。 将以下 `orderby` 子句添加到查询中，紧跟 `where` 语句之后、`select` 语句之前：

   ```csharp
   orderby student.Last ascending  
   ```

2. 现在，更改 `orderby` 子句，以便将结果根据第一次测试的分数以倒序（从最高分到最低分）的顺序排列。

   ```csharp
   orderby student.Scores[0] descending  
   ```

3. 更改 `WriteLine` 格式字符串，以便查看分数：

   ```csharp
   Console.WriteLine("{0}, {1} {2}", student.Last, student.First, student.Scores[0]);  
   ```

   有关详细信息，请参阅 [orderby 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/orderby-clause)。

#### 对结果进行分组

1. 分组是查询表达式中的强大功能。 包含 group 子句的查询将生成一系列组，每个组本身包含一个 `Key` 和一个序列，该序列由该组的所有成员组成。 以下新查询使用学生的姓的第一个字母作为关键字对学生进行分组。

   ```csharp
   // studentQuery2 is an IEnumerable<IGrouping<char, Student>>
   var studentQuery2 =
       from student in students
       group student by student.Last[0];
   ```

2. 注意，查询类型现已更改。 该查询现在生成一系列将 `char` 类型作为键的组，以及一系列 `Student` 对象。由于查询的类型已更改，因此以下代码也将更改 `foreach` 执行循环：

   ```csharp
   // studentGroup is a IGrouping<char, Student>
   foreach (var studentGroup in studentQuery2)
   {
       Console.WriteLine(studentGroup.Key);
       foreach (Student student in studentGroup)
       {
           Console.WriteLine("   {0}, {1}",
                     student.Last, student.First);
       }
   }
   
   // Output:
   // O
   //   Omelchenko, Svetlana
   //   O'Donnell, Claire
   // M
   //   Mortensen, Sven
   // G
   //   Garcia, Cesar
   //   Garcia, Debra
   //   Garcia, Hugo
   // F
   //   Fakhouri, Fadi
   //   Feng, Hanying
   // T
   //   Tucker, Lance
   //   Tucker, Michael
   // A
   //   Adams, Terry
   // Z
   //   Zabokritski, Eugene
   ```

3. 在“控制台”窗口中运行应用程序并查看结果。

   有关详细信息，请参阅 [group 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/group-clause)。

#### 对变量进行隐式类型化

1. `IGroupings` 的显式编码 `IEnumerables` 将快速变得冗长。 使用 `var` 可以更方便地编写相同的查询和 `foreach` 循环。 `var` 关键字不会更改对象的类型；它仅指示编译器推断类型。 将 `studentQuery` 和迭代变量 `group` 的类型更改为 `var`，然后重新运行查询。 注意，在内部 `foreach` 循环中，该迭代变量仍类型化为 `Student`，并且查询的工作原理和以前一样。 将 `s` 迭代变量更改为 `var`，然后再次运行查询。 将看到完全相同的结果。

   ```csharp
   var studentQuery3 =
       from student in students
       group student by student.Last[0];
   
   foreach (var groupOfStudents in studentQuery3)
   {
       Console.WriteLine(groupOfStudents.Key);
       foreach (var student in groupOfStudents)
       {
           Console.WriteLine("   {0}, {1}",
               student.Last, student.First);
       }
   }
   
   // Output:
   // O
   //   Omelchenko, Svetlana
   //   O'Donnell, Claire
   // M
   //   Mortensen, Sven
   // G
   //   Garcia, Cesar
   //   Garcia, Debra
   //   Garcia, Hugo
   // F
   //   Fakhouri, Fadi
   //   Feng, Hanying
   // T
   //   Tucker, Lance
   //   Tucker, Michael
   // A
   //   Adams, Terry
   // Z
   //   Zabokritski, Eugene
   ```

   有关 [var](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/var) 的详细信息，请参阅[隐式类型化局部变量](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/implicitly-typed-local-variables)。

#### 按照键值对组进行排序

1. 运行上一查询时，会发现这些组不是按字母顺序排序的。 若要更改此排序，必须在 `group` 子句后提供 `orderby` 子句。 但若要使用 `orderby` 子句，首先需要一个标识符，用作对 `group` 子句创建的组的引用。可以使用 `into` 关键字提供该标识符，如下所示：

   ```csharp
   var studentQuery4 =
       from student in students
       group student by student.Last[0] into studentGroup
       orderby studentGroup.Key
       select studentGroup;
   
   foreach (var groupOfStudents in studentQuery4)
   {
       Console.WriteLine(groupOfStudents.Key);
       foreach (var student in groupOfStudents)
       {
           Console.WriteLine("   {0}, {1}",
               student.Last, student.First);
       }
   }
   
   // Output:
   //A
   //   Adams, Terry
   //F
   //   Fakhouri, Fadi
   //   Feng, Hanying
   //G
   //   Garcia, Cesar
   //   Garcia, Debra
   //   Garcia, Hugo
   //M
   //   Mortensen, Sven
   //O
   //   Omelchenko, Svetlana
   //   O'Donnell, Claire
   //T
   //   Tucker, Lance
   //   Tucker, Michael
   //Z
   //   Zabokritski, Eugene
   ```

   运行此查询时，将看到这些组现在已按字母顺序排序。

#### 使用 let 引入标识符

1. 可以使用 `let` 关键字来引入查询表达式中任何表达式结果的标识符。 此标识符可以提供方便（如下面的示例所示），也可以通过存储表达式的结果来避免多次计算，从而提高性能。

   ```csharp
   // studentQuery5 is an IEnumerable<string>
   // This query returns those students whose
   // first test score was higher than their
   // average score.
   var studentQuery5 =
       from student in students
       let totalScore = student.Scores[0] + student.Scores[1] +
           student.Scores[2] + student.Scores[3]
       where totalScore / 4 < student.Scores[0]
       select student.Last + " " + student.First;
   
   foreach (string s in studentQuery5)
   {
       Console.WriteLine(s);
   }
   
   // Output:
   // Omelchenko Svetlana
   // O'Donnell Claire
   // Mortensen Sven
   // Garcia Cesar
   // Fakhouri Fadi
   // Feng Hanying
   // Garcia Hugo
   // Adams Terry
   // Zabokritski Eugene
   // Tucker Michael
   ```

   有关详细信息，请参阅 [let 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/let-clause)。

#### 在查询表达式中使用方法语法

1. 如 [LINQ 中的查询语法和方法语法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/query-syntax-and-method-syntax-in-linq) 中所述，某些查询操作只能使用方法语法来表示。 以下代码为源序列中的每个 `Student` 计算总分，然后对该查询的结果调用 `Average()` 方法来计算班级平均分。

   ```csharp
   var studentQuery6 =
       from student in students
       let totalScore = student.Scores[0] + student.Scores[1] +
           student.Scores[2] + student.Scores[3]
       select totalScore;
   
   double averageScore = studentQuery6.Average();
   Console.WriteLine("Class average score = {0}", averageScore);
   
   // Output:
   // Class average score = 334.166666666667
   ```

#### 在 select 子句转换或投影

1. 查询生成的序列的元素与源序列中的元素不同，这种情况很常见。 删除或注释掉以前的查询和执行循环，并将其替换为以下代码。 请注意，该查询将返回字符串序列，而不是 `Students`，这种情况将反映在 `foreach`循环中。

   ```csharp
   IEnumerable<string> studentQuery7 =
       from student in students
       where student.Last == "Garcia"
       select student.First;
   
   Console.WriteLine("The Garcias in the class are:");
   foreach (string s in studentQuery7)
   {
       Console.WriteLine(s);
   }
   
   // Output:
   // The Garcias in the class are:
   // Cesar
   // Debra
   // Hugo
   ```

2. 本演练中前面的代码表明班级平均分大约为 334 分。 若要生成总分数高于班级平均分的 `Students` 及其 `Student ID` 的序列，可以在 `select` 语句中使用匿名类型：

   ```csharp
   var studentQuery8 =
       from student in students
       let x = student.Scores[0] + student.Scores[1] +
           student.Scores[2] + student.Scores[3]
       where x > averageScore
       select new { id = student.ID, score = x };
   
   foreach (var item in studentQuery8)
   {
       Console.WriteLine("Student ID: {0}, Score: {1}", item.id, item.score);
   }
   
   // Output:
   // Student ID: 113, Score: 338
   // Student ID: 114, Score: 353
   // Student ID: 116, Score: 369
   // Student ID: 117, Score: 352
   // Student ID: 118, Score: 343
   // Student ID: 120, Score: 341
   // Student ID: 122, Score: 368
   ```

### 后续步骤

熟悉了在 C# 中使用查询的基本情况后，便可以开始阅读你感兴趣的具体类型的 LINQ 提供程序的文档和示例：

[LINQ to SQL](https://docs.microsoft.com/zh-cn/dotnet/framework/data/adonet/sql/linq/index)

[LINQ to DataSet](https://docs.microsoft.com/zh-cn/dotnet/framework/data/adonet/linq-to-dataset)

[LINQ to XML (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/linq-to-xml)

[LINQ to Objects (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/linq-to-objects)