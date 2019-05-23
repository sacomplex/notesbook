[C# programming guide](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/index)

# Language Sections

## [LINQ Query Expressions](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/linq-query-expressions/index)

语言集成查询 (LINQ) 是一系列直接将查询功能集成到 C# 语言的技术统称。 数据查询历来都表示为简单的字符串，没有编译时类型检查或 IntelliSense 支持。 此外，对于每种数据源，还需要学习不同的查询语言：SQL 数据库、XML 文档、各种 Web 服务等。 借助 LINQ，查询成为了最高级的语言构造，就像类、方法和事件一样。

对于编写查询的开发者来说，LINQ 最明显的“语言集成”部分就是查询表达式。 查询表达式采用声明性*查询语法*编写而成。 使用查询语法，可以用最少的代码对数据源执行筛选、排序和分组操作。 可使用相同的基本查询表达式模式来查询和转换 SQL 数据库、ADO .NET 数据集、XML 文档和流以及 .NET 集合中的数据。

下面的示例展示了完整的查询操作。 完整的操作包括创建数据源、定义查询表达式和在 `foreach` 语句中执行查询。

```csharp
class LINQQueryExpressions
{
    static void Main()
    {
        
        // Specify the data source.
        int[] scores = new int[] { 97, 92, 81, 60 };

        // Define the query expression.
        IEnumerable<int> scoreQuery =
            from score in scores
            where score > 80
            select score;

        // Execute the query.
        foreach (int i in scoreQuery)
        {
            Console.Write(i + " ");
        }            
    }
}
// Output: 97 92 81
```

### 查询表达式概述

- 查询表达式可用于查询并转换所有启用了 LINQ 的数据源中的数据。 例如，通过一个查询即可检索 SQL 数据库中的数据，并生成 XML 流作为输出。
- 查询表达式易于掌握，因为使用了许多熟悉的 C# 语言构造。
- 查询表达式中的变量全都是强类型，尽管在许多情况下，无需显式提供类型，因为编译器可以推断出。 有关详细信息，请参阅 [LINQ 查询操作中的类型关系](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/type-relationships-in-linq-query-operations)。
- 只有在循环访问查询变量后，才会执行查询（例如，在 `foreach` 语句中）。 有关详细信息，请参阅 [LINQ 查询简介](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/introduction-to-linq-queries)。
- 在编译时，查询表达式根据 C# 规范规则转换成标准查询运算符方法调用。 可使用查询语法表示的任何查询都可以使用方法语法进行表示。 不过，在大多数情况下，查询语法的可读性更高，也更为简洁。 有关详细信息，请参阅 [C# 语言规范](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#query-expressions)和[标准查询运算符概述](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/standard-query-operators-overview)。
- 通常，我们建议在编写 LINQ 查询时尽量使用查询语法，并在必要时尽可能使用方法语法。 这两种不同的形式在语义或性能上毫无差异。 查询表达式通常比使用方法语法编写的等同表达式更具可读性。
- 一些查询操作（如 [Count](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.count) 或 [Max](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.max)）没有等效的查询表达式子句，因此必须表示为方法调用。 可以各种方式结合使用方法语法和查询语法。 有关详细信息，请参阅 [LINQ 中的查询语法和方法语法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/query-syntax-and-method-syntax-in-linq)。
- 查询表达式可被编译成表达式树或委托，具体视应用查询的类型而定。 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 查询编译为委托。[IQueryable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.iqueryable) 和 [IQueryable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.iqueryable-1) 查询编译为表达式树。 有关详细信息，请参阅[表达式树](https://docs.microsoft.com/zh-cn/dotnet/csharp/expression-trees)。

### 后续步骤

若要详细了解 LINQ，请先自行熟悉[查询表达式基础知识](https://docs.microsoft.com/zh-cn/dotnet/csharp/linq/query-expression-basics)中的一些基本概念，然后再阅读感兴趣的 LINQ 技术的相关文档：

- XML 文档：[LINQ to XML](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/linq-to-xml)
- ADO.NET 实体框架：[LINQ to Entities](https://docs.microsoft.com/zh-cn/dotnet/framework/data/adonet/ef/language-reference/linq-to-entities)
- .NET 集合、文件、字符串等：[LINQ to Objects](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/linq-to-objects)

若要更深入地全面了解 LINQ，请参阅 [C# 中的 LINQ](https://docs.microsoft.com/zh-cn/dotnet/csharp/linq/linq-in-csharp)。

若要开始在 C# 中使用 LINQ，请参阅教程[使用 LINQ](https://docs.microsoft.com/zh-cn/dotnet/csharp/tutorials/working-with-linq)。

### [Query expression basics](https://docs.microsoft.com/en-us/dotnet/csharp/linq/query-expression-basics)

本文介绍与 C# 中的查询表达式相关的基本概念。

#### 查询是什么及其作用是什么？

查询是一组指令，描述要从给定数据源（或源）检索的数据以及返回的数据应具有的形状和组织。 查询与它生成的结果不同。

通常情况下，源数据按逻辑方式组织为相同类型的元素的序列。 例如，SQL 数据库表包含行的序列。 在 XML 文件中，存在 XML 元素的“序列”（尽管这些元素在树结构按层次结构进行组织）。 内存中集合包含对象的序列。

从应用程序的角度来看，原始源数据的特定类型和结构并不重要。 应用程序始终将源数据视为 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1)或 [IQueryable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.iqueryable-1) 集合。 例如在 LINQ to XML 中，源数据显示为 `IEnumerable`<[XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)>。

对于此源序列，查询可能会执行三种操作之一：

- 检索元素的子集以生成新序列，而不修改各个元素。 查询然后可能以各种方式对返回的序列进行排序或分组，如下面的示例所示（假定 `scores` 是 `int[]`）：

  ```csharp
  IEnumerable<int> highScoresQuery =
      from score in scores
      where score > 80
      orderby score descending
      select score;
  ```

- 如前面的示例所示检索元素的序列，但是将它们转换为新类型的对象。 例如，查询可以只从数据源中的某些客户记录检索姓氏。 或者可以检索完整记录，然后用于构造其他内存中对象类型甚至是 XML 数据，再生成最终的结果序列。 下面的示例演示从 `int` 到 `string` 的投影。 请注意 `highScoresQuery` 的新类型。

  ```csharp
  IEnumerable<string> highScoresQuery2 =
      from score in scores
      where score > 80
      orderby score descending
      select $"The score is {score}";
  ```

- 检索有关源数据的单独值，如：

  - 与特定条件匹配的元素数。

  - 具有最大或最小值的元素。

  - 与某个条件匹配的第一个元素，或指定元素集中特定值的总和。 例如，下面的查询从 `scores` 整数数组返回大于 80 的分数的数量：

    ```csharp
    int highScoreCount =
        (from score in scores
         where score > 80
         select score)
         .Count();
    ```

    在前面的示例中，请注意在调用 `Count` 方法之前，在查询表达式两边使用了括号。 也可以通过使用新变量存储具体结果，来表示此行为。 这种方法更具可读性，因为它使存储查询的变量与存储结果的查询分开。

    ```csharp
    IEnumerable<int> highScoresQuery3 =
        from score in scores
        where score > 80
        select score;
    
    int scoreCount = highScoresQuery3.Count();
    ```

在上面的示例中，查询在 `Count` 调用中执行，因为 `Count` 必须循环访问结果才能确定 `highScoresQuery` 返回的元素数。

#### 查询表达式是什么？

查询表达式是以查询语法表示的查询。 查询表达式是一流的语言构造。 它如同任何其他表达式一样，可以在 C# 表达式有效的任何上下文中使用。 查询表达式由一组用类似于 SQL 或 XQuery 的声明性语法所编写的子句组成。每个子句进而包含一个或多个 C# 表达式，而这些表达式可能本身是查询表达式或包含查询表达式。

查询表达式必须以 [from](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/from-clause) 子句开头，且必须以 [select](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/select-clause) 或 [group](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/group-clause) 子句结尾。 在第一个 `from` 子句与最后一个 `select` 或 `group` 子句之间，可以包含以下这些可选子句中的一个或多个：[where](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/where-clause)、[orderby](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/orderby-clause)、[join](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/join-clause)、[let](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/let-clause)，甚至是其他 [from](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/from-clause) 子句。 还可以使用 [into](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/into) 关键字，使 `join` 或 `group` 子句的结果可以充当相同查询表达式中的其他查询子句的源。

##### 查询变量

在 LINQ 中，查询变量是存储查询而不是查询结果的任何变量。 更具体地说，查询变量始终是可枚举类型，在 `foreach` 语句或对其 `IEnumerator.MoveNext` 方法的直接调用中循环访问时会生成元素序列。

下面的代码示例演示一个简单查询表达式，它具有一个数据源、一个筛选子句、一个排序子句并且不转换源元素。该查询以 `select` 子句结尾。

```csharp
static void Main()
{
    // Data source.
    int[] scores = { 90, 71, 82, 93, 75, 82 };

    // Query Expression.
    IEnumerable<int> scoreQuery = //query variable
        from score in scores //required
        where score > 80 // optional
        orderby score descending // optional
        select score; //must end with select or group

    // Execute the query to produce the results
    foreach (int testScore in scoreQuery)
    {
        Console.WriteLine(testScore);
    }                  
}
// Outputs: 93 90 82 82      
```

在上面的示例中，`scoreQuery` 是查询变量，它有时仅仅称为查询。 查询变量不存储在 `foreach` 循环生成中的任何实际结果数据。 并且当 `foreach` 语句执行时，查询结果不会通过查询变量 `scoreQuery` 返回。 而是通过迭代变量 `testScore` 返回。 `scoreQuery` 变量可以在另一个 `foreach` 循环中进行循环访问。 只要既没有修改它，也没有修改数据源，便会生成相同结果。

查询变量可以存储采用查询语法、方法语法或是两者的组合进行表示的查询。 在以下示例中，`queryMajorCities`和 `queryMajorCities2` 都是查询变量：

```csharp
//Query syntax
IEnumerable<City> queryMajorCities =
    from city in cities
    where city.Population > 100000
    select city;


// Method-based syntax
IEnumerable<City> queryMajorCities2 = cities.Where(c => c.Population > 100000);
```

另一方面，以下两个示例演示不是查询变量的变量（即使各自使用查询进行初始化）。 它们不是查询变量，因为它们存储结果：

```csharp
int highestScore =
    (from score in scores
     select score)
    .Max();

// or split the expression
IEnumerable<int> scoreQuery =
    from score in scores
    select score;

int highScore = scoreQuery.Max();
// the following returns the same result
int highScore = scores.Max();

List<City> largeCitiesList =
    (from country in countries
     from city in country.Cities
     where city.Population > 10000
     select city)
       .ToList();

// or split the expression
IEnumerable<City> largeCitiesQuery =
    from country in countries
    from city in country.Cities
    where city.Population > 10000
    select city;

List<City> largeCitiesList2 = largeCitiesQuery.ToList();
```

有关表示查询的不同方式的详细信息，请参阅 [LINQ 中的查询语法和方法语法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/query-syntax-and-method-syntax-in-linq)。

###### 查询变量的显式和隐式类型化

本文档通常提供查询变量的显式类型以便显示查询变量与 [select 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/select-clause)之间的类型关系。 但是，还可以使用 [var](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/var) 关键字指示编译器在编译时推断查询变量（或任何其他局部变量）的类型。 例如，本主题中前面演示的查询示例也可以使用隐式类型化进行表示：

```csharp
// Use of var is optional here and in all queries.
// queryCities is an IEnumerable<City> just as 
// when it is explicitly typed.
var queryCities =
    from city in cities
    where city.Population > 100000
    select city;
```

有关详细信息，请参阅[隐式类型化局部变量](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/implicitly-typed-local-variables)和 [LINQ 查询操作中的类型关系](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/type-relationships-in-linq-query-operations)。

##### 开始查询表达式

查询表达式必须以 `from` 子句开头。 它指定数据源以及范围变量。 范围变量表示遍历源序列时，源序列中的每个连续元素。 范围变量基于数据源中元素的类型进行强类型化。 在下面的示例中，因为 `countries` 是 `Country` 对象的数组，所以范围变量也类型化为 `Country`。 因为范围变量是强类型，所以可以使用点运算符访问该类型的任何可用成员。

```csharp
IEnumerable<Country> countryAreaQuery =
    from country in countries
    where country.Area > 500000 //sq km
    select country;
```

范围变量一直处于范围中，直到查询使用分号或 continuation 子句退出。

查询表达式可能会包含多个 `from` 子句。 在源序列中的每个元素本身是集合或包含集合时，可使用其他 `from` 子句。 例如，假设具有 `Country` 对象的集合，其中每个对象都包含名为 `Cities` 的 `City` 对象集合。 若要查询每个 `Country` 中的 `City` 对象，请使用两个 `from` 子句，如下所示：

```csharp
IEnumerable<City> cityQuery =
    from country in countries
    from city in country.Cities
    where city.Population > 10000
    select city;
```

有关详细信息，请参阅 [from 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/from-clause)。

##### 结束查询表达式

查询表达式必须以 `group` 子句或 `select` 子句结尾。

###### group 子句

使用 `group` 子句可生成按指定键组织的组的序列。 键可以是任何数据类型。 例如，下面的查询会创建包含一个或多个 `Country` 对象并且其键是 `char` 值的组的序列。

```csharp
var queryCountryGroups =
    from country in countries
    group country by country.Name[0];
```

有关分组的详细信息，请参阅 [group 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/group-clause)。

###### select 子句

使用 `select` 子句可生成所有其他类型的序列。 简单 `select` 子句只生成类型与数据源中包含的对象相同的对象的序列。 在此示例中，数据源包含 `Country` 对象。 `orderby` 子句只按新顺序对元素进行排序，而 `select` 子句生成重新排序的 `Country` 对象的序列。

```csharp
IEnumerable<Country> sortedQuery =
    from country in countries
    orderby country.Area
    select country;
```

`select` 子句可以用于将源数据转换为新类型的序列。 此转换也称为投影。 在下面的示例中，`select` 子句对只包含原始元素中的字段子集的匿名类型序列进行投影。 请注意，新对象使用对象初始值设定项进行初始化。

```csharp
// Here var is required because the query
// produces an anonymous type.
var queryNameAndPop =
    from country in countries
    select new { Name = country.Name, Pop = country.Population };
```

有关可以使用 `select` 子句转换源数据的所有方法的详细信息，请参阅 [select 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/select-clause)。

###### 使用“into”进行延续

可以在 `select` 或 `group` 子句中使用 `into` 关键字创建存储查询的临时标识符。 如果在分组或选择操作之后必须对查询执行其他查询操作，则可以这样做。 在下面的示例中，`countries` 按 1000 万范围，根据人口进行分组。 创建这些组之后，附加子句会筛选出一些组，然后按升序对组进行排序。 若要执行这些附加操作，需要由 `countryGroup` 表示的延续。

```csharp
// percentileQuery is an IEnumerable<IGrouping<int, Country>>
var percentileQuery =
    from country in countries
    let percentile = (int) country.Population / 10_000_000
    group country by percentile into countryGroup
    where countryGroup.Key >= 20
    orderby countryGroup.Key
    select countryGroup;

// grouping is an IGrouping<int, Country>
foreach (var grouping in percentileQuery)
{
    Console.WriteLine(grouping.Key);
    foreach (var country in grouping)
        Console.WriteLine(country.Name + ":" + country.Population);
}
```

有关详细信息，请参阅 [into](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/into)。

##### 筛选、排序和联接

在开头 `from` 子句与结尾 `select` 或 `group` 子句之间，所有其他子句（`where`、`join`、`orderby`、`from`、`let`）都是可选的。 任何可选子句都可以在查询正文中使用零次或多次。

###### where 子句

使用 `where` 子句可基于一个或多个谓词表达式，从源数据中筛选出元素。 以下示例中的 `where` 子句具有一个谓词及两个条件。

```csharp
IEnumerable<City> queryCityPop =
    from city in cities
    where city.Population < 200000 && city.Population > 100000
    select city;
```

有关详细信息，请参阅 [where 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/where-clause)。

###### orderby 子句

使用 `orderby` 子句可按升序或降序对结果进行排序。 还可以指定次要排序顺序。 下面的示例使用 `Area` 属性对 `country` 对象执行主要排序。 然后使用 `Population` 属性执行次要排序。

```csharp
IEnumerable<Country> querySortedCountries =
    from country in countries
    orderby country.Area, country.Population descending
    select country;
```

`ascending` 关键字是可选的；如果未指定任何顺序，则它是默认排序顺序。 有关详细信息，请参阅 [orderby 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/orderby-clause)。

###### join 子句

使用 `join` 子句可基于每个元素中指定的键之间的相等比较，将一个数据源中的元素与另一个数据源中的元素进行关联和/或合并。 在 LINQ 中，联接操作是对元素属于不同类型的对象序列执行。 联接了两个序列之后，必须使用 `select` 或 `group` 语句指定要存储在输出序列中的元素。 还可以使用匿名类型将每组关联元素中的属性合并到输出序列的新类型中。 下面的示例关联其 `Category` 属性与 `categories` 字符串数组中一个类别匹配的 `prod`对象。 筛选出其 `Category` 不与 `categories` 中的任何字符串匹配的产品。`select` 语句会投影其属性取自 `cat`和 `prod` 的新类型。

```csharp
var categoryQuery =
    from cat in categories
    join prod in products on cat equals prod.Category
    select new { Category = cat, Name = prod.Name };
```

还可以通过使用 [into](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/into) 关键字将 `join` 操作的结果存储到临时变量中来执行分组联接。 有关详细信息，请参阅 [join 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/join-clause)。

###### let 子句

使用 `let` 子句可将表达式（如方法调用）的结果存储在新范围变量中。 在下面的示例中，范围变量 `firstName`存储 `Split` 返回的字符串数组的第一个元素。

```csharp
string[] names = { "Svetlana Omelchenko", "Claire O'Donnell", "Sven Mortensen", "Cesar Garcia" };
IEnumerable<string> queryFirstNames =
    from name in names
    let firstName = name.Split(' ')[0]
    select firstName;

foreach (string s in queryFirstNames)
    Console.Write(s + " ");
//Output: Svetlana Claire Sven Cesar
```

有关详细信息，请参阅 [let 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/let-clause)。

##### 查询表达式中的子查询

查询子句本身可能包含查询表达式，这有时称为子查询。 每个子查询都以自己的 `from` 子句开头，该子句不一定指向第一个 `from` 子句中的相同数据源。 例如，下面的查询演示在 select 语句用于检索分组操作结果的查询表达式。

```csharp
var queryGroupMax =
    from student in students
    group student by student.GradeLevel into studentGroup
    select new
    {
        Level = studentGroup.Key,
        HighestScore =
            (from student2 in studentGroup
             select student2.Scores.Average())
             .Max()
    };
```

有关详细信息，请参阅[如何：对分组操作执行子查询](https://docs.microsoft.com/zh-cn/dotnet/csharp/linq/perform-a-subquery-on-a-grouping-operation)。

### [LINQ in C#](https://docs.microsoft.com/en-us/dotnet/csharp/linq/linq-in-csharp)

此部分包含提供有关 LINQ 的详细信息的主题链接。

#### 本节内容

[LINQ 查询简介](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/introduction-to-linq-queries)
介绍所有语言和数据源共有的基本 LINQ 查询操作的 3 个部分。

[LINQ 和泛型类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/linq-and-generic-types)
简单介绍泛型类型在 LINQ 中的使用。

[使用 LINQ 进行数据转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/data-transformations-with-linq)
介绍转换在查询中检索到的数据时可采用的各种方式。

[LINQ 查询操作中的类型关系](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/type-relationships-in-linq-query-operations)
介绍如何在 LINQ 查询操作的 3 个部分中保留和/或转换类型

[LINQ 中的查询语法和方法语法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/query-syntax-and-method-syntax-in-linq)
比较表达 LINQ 查询的两种方式：方法语法和查询语法。

[支持 LINQ 的 C# 功能](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/features-that-support-linq)
描述 C# 中支持 LINQ 的语言构造。

### [Write LINQ queries in C#](https://docs.microsoft.com/en-us/dotnet/csharp/linq/write-linq-queries)

本文介绍可以用于在 C# 中编写 LINQ 查询的三种方法：

1. 使用查询语法。
2. 使用方法语法。
3. 结合使用查询语法和方法语法。

下面的示例演示使用前面列出的每种方法的一些简单 LINQ 查询。 一般情况下，规则是尽可能使用 (1)，每当需要时使用 (2) 和 (3)。

> 这些查询对简单的内存中集合进行操作；但是，基本语法等同于在 LINQ to Entities 和 LINQ to XML 中使用的语法。

#### 示例 - 查询语法

编写大多数查询的推荐方式是使用查询语法创建查询表达式。 下面的示例演示三个查询表达式。 第一个查询表达式演示如何通过应用包含 `where` 子句的条件来筛选或限制结果。 它返回源序列中值大于 7 或小于 3 的所有元素。 第二个表达式演示如何对返回的结果进行排序。 第三个表达式演示如何根据某个键对结果进行分组。 此查询基于单词的第一个字母返回两个组。

```csharp
// Query #1.
List<int> numbers = new List<int>() { 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };

// The query variable can also be implicitly typed by using var
IEnumerable<int> filteringQuery =
    from num in numbers
    where num < 3 || num > 7
    select num;

// Query #2.
IEnumerable<int> orderingQuery =
    from num in numbers
    where num < 3 || num > 7
    orderby num ascending
    select num;

// Query #3.
string[] groupingQuery = { "carrots", "cabbage", "broccoli", "beans", "barley" };
IEnumerable<IGrouping<char, string>> queryFoodGroups =
    from item in groupingQuery
    group item by item[0];
```

注意，查询类型为 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1)。 可以使用 `var` 编写所有这些查询，如下面的示例所示：

```
var query = from num in numbers...
```

在前面的每个示例中，在 `foreach` 语句或其他语句中循环访问查询变量之前，查询不会实际执行。 有关详细信息，请参阅 [LINQ 查询介绍](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/introduction-to-linq-queries)。

#### 示例 - 方法语法

某些查询操作必须表示为方法调用。 最常见的此类方法是可返回单一数值的方法，例如 [Sum](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.sum)、[Max](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.max)、[Min](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.min)、[Average](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.average) 等。 这些方法在任何查询中都必须始终最后一个调用，因为它们只表示单个值，不能用作其他查询操作的源。 下面的示例演示查询表达式中的方法调用：

```csharp
List<int> numbers1 = new List<int>() { 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
List<int> numbers2 = new List<int>() { 15, 14, 11, 13, 19, 18, 16, 17, 12, 10 };
// Query #4.
double average = numbers1.Average();

// Query #5.
IEnumerable<int> concatenationQuery = numbers1.Concat(numbers2);
```

如果方法具有 Action 或 Func 参数，则这些参数以 [lambda](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/lambda-expressions) 表达式的形式提供，如下面的示例所示：

```csharp
// Query #6.
IEnumerable<int> largeNumbersQuery = numbers2.Where(c => c > 15);
```

在上面的查询中，只有查询 #4 立即执行。 这是因为它将返回单个值，而不是泛型 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 集合。 该方法本身必须使用 `foreach` 才能计算其值。

上面的每个查询可以通过 [var](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/var) 使用隐式类型化进行编写，如下面的示例所示：

```csharp
// var is used for convenience in these queries
var average = numbers1.Average();
var concatenationQuery = numbers1.Concat(numbers2);
var largeNumbersQuery = numbers2.Where(c => c > 15);
```

#### 示例 - 混合查询和方法语法

此示例演示如何对查询子句的结果使用方法语法。 只需将查询表达式括在括号中，然后应用点运算符并调用方法。 在下面的示例中，查询 #7 返回对值介于 3 与 7 之间的数字进行的计数。 但是通常情况下，最好使用另一个变量存储方法调用的结果。 采用此方法时，查询不太可能与查询的结果相混淆。

```csharp
// Query #7.

// Using a query expression with method syntax
int numCount1 =
    (from num in numbers1
     where num < 3 || num > 7
     select num).Count();

// Better: Create a new variable to store
// the method call result
IEnumerable<int> numbersQuery =
    from num in numbers1
    where num < 3 || num > 7
    select num;

int numCount2 = numbersQuery.Count();
```

由于查询 #7 返回单个值而不是集合，因此查询立即执行。

前面的查询可以通过 `var` 使用隐式类型化进行编写，如下所示：

```csharp
var numCount = (from num in numbers...
```

它可以采用方法语法进行编写，如下所示：

```csharp
var numCount = numbers.Where(n => n < 3 || n > 7).Count();
```

它可以使用显式类型化进行编写，如下所示：

```csharp
int numCount = numbers.Where(n => n < 3 || n > 7).Count();
```

### [Query a collection of objects](https://docs.microsoft.com/en-us/dotnet/csharp/linq/query-a-collection-of-objects)

此示例演示如何对一系列 `Student` 对象执行简单查询。 每个 `Student` 对象均包含一些关于学生的基本信息和表示学生在四门考试中的分数的列表。

该应用程序充当本部分中使用相同 `students` 数据源的许多其他示例的框架。

#### 示例

以下查询将返回在第一堂考试中得分为 90 或更高的学生。

```csharp
public class StudentClass
{
    #region data
    protected enum GradeLevel { FirstYear = 1, SecondYear, ThirdYear, FourthYear };
    protected class Student
    {
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public int ID { get; set; }
        public GradeLevel Year;
        public List<int> ExamScores;
    }

    protected static List<Student> students = new List<Student>
    {
        new Student {FirstName = "Terry", LastName = "Adams", ID = 120, 
            Year = GradeLevel.SecondYear, 
            ExamScores = new List<int>{ 99, 82, 81, 79}},
        new Student {FirstName = "Fadi", LastName = "Fakhouri", ID = 116, 
            Year = GradeLevel.ThirdYear,
            ExamScores = new List<int>{ 99, 86, 90, 94}},
        new Student {FirstName = "Hanying", LastName = "Feng", ID = 117, 
            Year = GradeLevel.FirstYear, 
            ExamScores = new List<int>{ 93, 92, 80, 87}},
        new Student {FirstName = "Cesar", LastName = "Garcia", ID = 114, 
            Year = GradeLevel.FourthYear,
            ExamScores = new List<int>{ 97, 89, 85, 82}},
        new Student {FirstName = "Debra", LastName = "Garcia", ID = 115, 
            Year = GradeLevel.ThirdYear, 
            ExamScores = new List<int>{ 35, 72, 91, 70}},
        new Student {FirstName = "Hugo", LastName = "Garcia", ID = 118, 
            Year = GradeLevel.SecondYear, 
            ExamScores = new List<int>{ 92, 90, 83, 78}},
        new Student {FirstName = "Sven", LastName = "Mortensen", ID = 113, 
            Year = GradeLevel.FirstYear, 
            ExamScores = new List<int>{ 88, 94, 65, 91}},
        new Student {FirstName = "Claire", LastName = "O'Donnell", ID = 112, 
            Year = GradeLevel.FourthYear, 
            ExamScores = new List<int>{ 75, 84, 91, 39}},
        new Student {FirstName = "Svetlana", LastName = "Omelchenko", ID = 111, 
            Year = GradeLevel.SecondYear, 
            ExamScores = new List<int>{ 97, 92, 81, 60}},
        new Student {FirstName = "Lance", LastName = "Tucker", ID = 119, 
            Year = GradeLevel.ThirdYear, 
            ExamScores = new List<int>{ 68, 79, 88, 92}},
        new Student {FirstName = "Michael", LastName = "Tucker", ID = 122, 
            Year = GradeLevel.FirstYear, 
            ExamScores = new List<int>{ 94, 92, 91, 91}},
        new Student {FirstName = "Eugene", LastName = "Zabokritski", ID = 121,
            Year = GradeLevel.FourthYear, 
            ExamScores = new List<int>{ 96, 85, 91, 60}}
    };
    #endregion

    //Helper method, used in GroupByRange.
    protected static int GetPercentile(Student s)
    {
        double avg = s.ExamScores.Average();
        return avg > 0 ? (int)avg / 10 : 0;
    }

    

    public void QueryHighScores(int exam, int score)
    {
        var highScores = from student in students
                         where student.ExamScores[exam] > score
                         select new {Name = student.FirstName, Score = student.ExamScores[exam]};

        foreach (var item in highScores)
        {
            Console.WriteLine($"{item.Name,-15}{item.Score}");
        }
    }
}

public class Program
{
    public static void Main()
    {
        StudentClass sc = new StudentClass();
        sc.QueryHighScores(1, 90);

        // Keep the console window open in debug mode.
        Console.WriteLine("Press any key to exit");
        Console.ReadKey();
    }
}
```

该查询有意简单，以使你可以进行实验。 例如，你可以在 `where` 子句中尝试其他条件或使用 `orderby` 子句对结果进行排序。

### [Return a query from a method](https://docs.microsoft.com/en-us/dotnet/csharp/linq/return-a-query-from-a-method)

此示例演示如何以返回值和 `out` 参数形式从方法中返回查询。

查询对象可编写，这意味着你可以从方法中返回查询。 表示查询的对象不会存储生成的集合，而会根据需要存储生成结果的步骤。 从方法中返回查询对象的好处是可以进一步编写或修改这些对象。 因此，返回查询的方法的任何返回值或 `out` 输出参数也必须具有该类型。 如果某个方法可将查询具体化为具体的 [List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1) 或 [Array](https://docs.microsoft.com/zh-cn/dotnet/api/system.array) 类型，则认为该方法在返回查询结果（而不是查询本身）。 仍然能够编写或修改从方法中返回的查询变量。

#### 示例

在下面的示例中，第一个方法以返回值的形式返回查询，第二个方法以 `out` 参数的形式返回查询。 请注意，在这两种情况下，返回的都是查询，而不是查询结果。

```csharp
class MQ
{
    // QueryMethhod1 returns a query as its value.
    IEnumerable<string> QueryMethod1(ref int[] ints)
    {
        var intsToStrings = from i in ints
                            where i > 4
                            select i.ToString();
        return intsToStrings;
    }

    // QueryMethod2 returns a query as the value of parameter returnQ.
    void QueryMethod2(ref int[] ints, out IEnumerable<string> returnQ)
    {
        var intsToStrings = from i in ints
                            where i < 4
                            select i.ToString();
        returnQ = intsToStrings;
    }

    static void Main()
    {
        MQ app = new MQ();

        int[] nums = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        // QueryMethod1 returns a query as the value of the method.
        var myQuery1 = app.QueryMethod1(ref nums);

        // Query myQuery1 is executed in the following foreach loop.
        Console.WriteLine("Results of executing myQuery1:");
        // Rest the mouse pointer over myQuery1 to see its type.
        foreach (string s in myQuery1)
        {
            Console.WriteLine(s);
        }

        // You also can execute the query returned from QueryMethod1 
        // directly, without using myQuery1.
        Console.WriteLine("\nResults of executing myQuery1 directly:");
        // Rest the mouse pointer over the call to QueryMethod1 to see its
        // return type.
        foreach (string s in app.QueryMethod1(ref nums))
        {
            Console.WriteLine(s);
        }


        IEnumerable<string> myQuery2;
        // QueryMethod2 returns a query as the value of its out parameter.
        app.QueryMethod2(ref nums, out myQuery2);

        // Execute the returned query.
        Console.WriteLine("\nResults of executing myQuery2:");
        foreach (string s in myQuery2)
        {
            Console.WriteLine(s);
        }


        // You can modify a query by using query composition. A saved query
        // is nested inside a new query definition that revises the results
        // of the first query.
        myQuery1 = from item in myQuery1
                   orderby item descending
                   select item;

        // Execute the modified query.
        Console.WriteLine("\nResults of executing modified myQuery1:");
        foreach (string s in myQuery1)
        {
            Console.WriteLine(s);
        }

        // Keep console window open in debug mode.
        Console.WriteLine("Press any key to exit.");
        Console.ReadKey();
    }
} 
```

### [Store the results of a query in memory](https://docs.microsoft.com/en-us/dotnet/csharp/linq/store-the-results-of-a-query-in-memory)

查询基本上是针对如何检索和组织数据的一套说明。 当请求结果中的每个后续项目时，查询将延迟执行。 使用 `foreach` 循环访问结果时，项将在受到访问时返回。 若要在不执行 `foreach` 循环的情况下评估查询并存储其结果，只需调用查询变量上的以下方法之一：

- [ToList](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.tolist)
- [ToArray](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.toarray)
- [ToDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.todictionary)
- [ToLookup](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.tolookup)

建议在存储查询结果时，将返回的集合对象分配给一个新变量，如下面的示例所示：

#### 示例

```csharp
class StoreQueryResults
{
    static List<int> numbers = new List<int>() { 1, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
    static void Main()
    {

        IEnumerable<int> queryFactorsOfFour =
            from num in numbers
            where num % 4 == 0
            select num;

        // Store the results in a new variable
        // without executing a foreach loop.
        List<int> factorsofFourList = queryFactorsOfFour.ToList();

        // Iterate the list just to prove it holds data.
        Console.WriteLine(factorsofFourList[2]);
        factorsofFourList[2] = 0;
        Console.WriteLine(factorsofFourList[2]);

        // Keep the console window open in debug mode.
        Console.WriteLine("Press any key");
        Console.ReadKey();
    }
}
```

### [Group query results](https://docs.microsoft.com/en-us/dotnet/csharp/linq/group-query-results)

分组是 LINQ 最强大的功能之一。 以下示例演示如何以各种方式对数据进行分组：

- 依据单个属性。
- 依据字符串属性的首字母。
- 依据计算出的数值范围。
- 依据布尔谓词或其他表达式。
- 依据组合键。

此外，最后两个查询将其结果投影到一个新的匿名类型中，该类型仅包含学生的名字和姓氏。 有关详细信息，请参阅 [group 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/group-clause)。

#### 示例1

本主题中的所有示例都使用下列帮助程序类和数据源。

```csharp
public class StudentClass
{
    #region data
    protected enum GradeLevel { FirstYear = 1, SecondYear, ThirdYear, FourthYear };
    protected class Student
    {
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public int ID { get; set; }
        public GradeLevel Year;
        public List<int> ExamScores;
    }

    protected static List<Student> students = new List<Student>
    {
        new Student {FirstName = "Terry", LastName = "Adams", ID = 120, 
            Year = GradeLevel.SecondYear, 
            ExamScores = new List<int>{ 99, 82, 81, 79}},
        new Student {FirstName = "Fadi", LastName = "Fakhouri", ID = 116, 
            Year = GradeLevel.ThirdYear,
            ExamScores = new List<int>{ 99, 86, 90, 94}},
        new Student {FirstName = "Hanying", LastName = "Feng", ID = 117, 
            Year = GradeLevel.FirstYear, 
            ExamScores = new List<int>{ 93, 92, 80, 87}},
        new Student {FirstName = "Cesar", LastName = "Garcia", ID = 114, 
            Year = GradeLevel.FourthYear,
            ExamScores = new List<int>{ 97, 89, 85, 82}},
        new Student {FirstName = "Debra", LastName = "Garcia", ID = 115, 
            Year = GradeLevel.ThirdYear, 
            ExamScores = new List<int>{ 35, 72, 91, 70}},
        new Student {FirstName = "Hugo", LastName = "Garcia", ID = 118, 
            Year = GradeLevel.SecondYear, 
            ExamScores = new List<int>{ 92, 90, 83, 78}},
        new Student {FirstName = "Sven", LastName = "Mortensen", ID = 113, 
            Year = GradeLevel.FirstYear, 
            ExamScores = new List<int>{ 88, 94, 65, 91}},
        new Student {FirstName = "Claire", LastName = "O'Donnell", ID = 112, 
            Year = GradeLevel.FourthYear, 
            ExamScores = new List<int>{ 75, 84, 91, 39}},
        new Student {FirstName = "Svetlana", LastName = "Omelchenko", ID = 111, 
            Year = GradeLevel.SecondYear, 
            ExamScores = new List<int>{ 97, 92, 81, 60}},
        new Student {FirstName = "Lance", LastName = "Tucker", ID = 119, 
            Year = GradeLevel.ThirdYear, 
            ExamScores = new List<int>{ 68, 79, 88, 92}},
        new Student {FirstName = "Michael", LastName = "Tucker", ID = 122, 
            Year = GradeLevel.FirstYear, 
            ExamScores = new List<int>{ 94, 92, 91, 91}},
        new Student {FirstName = "Eugene", LastName = "Zabokritski", ID = 121,
            Year = GradeLevel.FourthYear, 
            ExamScores = new List<int>{ 96, 85, 91, 60}}
    };
    #endregion

    //Helper method, used in GroupByRange.
    protected static int GetPercentile(Student s)
    {
        double avg = s.ExamScores.Average();
        return avg > 0 ? (int)avg / 10 : 0;
    }

    

    public void QueryHighScores(int exam, int score)
    {
        var highScores = from student in students
                         where student.ExamScores[exam] > score
                         select new {Name = student.FirstName, Score = student.ExamScores[exam]};

        foreach (var item in highScores)
        {
            Console.WriteLine($"{item.Name,-15}{item.Score}");
        }
    }
}

public class Program
{
    public static void Main()
    {
        StudentClass sc = new StudentClass();
        sc.QueryHighScores(1, 90);

        // Keep the console window open in debug mode.
        Console.WriteLine("Press any key to exit");
        Console.ReadKey();
    }
}
```

#### 示例2

以下示例演示如何通过使用元素的单个属性作为分组键对源元素进行分组。 在此示例中，键是 `string`，即学生的姓氏。 还可以使用子字符串作为键。 分组操作对该类型使用默认的相等比较器。

将以下方法粘贴到 `StudentClass` 类。 将 `Main` 方法中的调用语句更改为 `sc.GroupBySingleProperty()`。

```csharp
public void GroupBySingleProperty()
{
    Console.WriteLine("Group by a single property in an object:");

    // Variable queryLastNames is an IEnumerable<IGrouping<string, 
    // DataClass.Student>>. 
    var queryLastNames =
        from student in students
        group student by student.LastName into newGroup
        orderby newGroup.Key
        select newGroup;

    foreach (var nameGroup in queryLastNames)
    {
        Console.WriteLine($"Key: {nameGroup.Key}");
        foreach (var student in nameGroup)
        {
            Console.WriteLine($"\t{student.LastName}, {student.FirstName}");
        }
    }
}
/* Output:
    Group by a single property in an object:
    Key: Adams
            Adams, Terry
    Key: Fakhouri
            Fakhouri, Fadi
    Key: Feng
            Feng, Hanying
    Key: Garcia
            Garcia, Cesar
            Garcia, Debra
            Garcia, Hugo
    Key: Mortensen
            Mortensen, Sven
    Key: O'Donnell
            O'Donnell, Claire
    Key: Omelchenko
            Omelchenko, Svetlana
    Key: Tucker
            Tucker, Lance
            Tucker, Michael
    Key: Zabokritski
            Zabokritski, Eugene
*/
```

#### 示例3

下例演示如何通过使用除对象属性以外的某个项作为分组键对源元素进行分组。 在此示例中，键是学生姓氏的第一个字母。

将以下方法粘贴到 `StudentClass` 类。 将 `Main` 方法中的调用语句更改为 `sc.GroupBySubstring()`。

```csharp
public void GroupBySubstring()
{            
    Console.WriteLine("\r\nGroup by something other than a property of the object:");

    var queryFirstLetters =
        from student in students
        group student by student.LastName[0];

    foreach (var studentGroup in queryFirstLetters)
    {
        Console.WriteLine($"Key: {studentGroup.Key}");
        // Nested foreach is required to access group items.
        foreach (var student in studentGroup)
        {
            Console.WriteLine($"\t{student.LastName}, {student.FirstName}");
        }
    }           
}
/* Output:
    Group by something other than a property of the object:
    Key: A
            Adams, Terry
    Key: F
            Fakhouri, Fadi
            Feng, Hanying
    Key: G
            Garcia, Cesar
            Garcia, Debra
            Garcia, Hugo
    Key: M
            Mortensen, Sven
    Key: O
            O'Donnell, Claire
            Omelchenko, Svetlana
    Key: T
            Tucker, Lance
            Tucker, Michael
    Key: Z
            Zabokritski, Eugene
*/
```

#### 示例4

以下示例演示如何通过使用某个数值范围作为分组键对源元素进行分组。 然后，查询将结果投影到一个匿名类型中，该类型仅包含学生的名字和姓氏以及该学生所属的百分点范围。 使用匿名类型的原因是没有必要使用完整的 `Student` 对象来显示结果。 `GetPercentile` 是一个帮助程序函数，它根据学生的平均分数计算百分比。 该方法返回 0 到 10 之间的整数。

```csharp
//Helper method, used in GroupByRange.
protected static int GetPercentile(Student s)
{
    double avg = s.ExamScores.Average();
    return avg > 0 ? (int)avg / 10 : 0;
}
```

将以下方法粘贴到 `StudentClass` 类。 将 `Main` 方法中的调用语句更改为 `sc.GroupByRange()`。

```csharp
public void GroupByRange()
{            
    Console.WriteLine("\r\nGroup by numeric range and project into a new anonymous type:");

    var queryNumericRange =
        from student in students
        let percentile = GetPercentile(student)
        group new { student.FirstName, student.LastName } by percentile into percentGroup
        orderby percentGroup.Key
        select percentGroup;

    // Nested foreach required to iterate over groups and group items.
    foreach (var studentGroup in queryNumericRange)
    {
        Console.WriteLine($"Key: {studentGroup.Key * 10}"); 
        foreach (var item in studentGroup)
        {
            Console.WriteLine($"\t{item.LastName}, {item.FirstName}");
        }
    }            
}
/* Output:
    Group by numeric range and project into a new anonymous type:
    Key: 60
            Garcia, Debra
    Key: 70
            O'Donnell, Claire
    Key: 80
            Adams, Terry
            Feng, Hanying
            Garcia, Cesar
            Garcia, Hugo
            Mortensen, Sven
            Omelchenko, Svetlana
            Tucker, Lance
            Zabokritski, Eugene
    Key: 90
            Fakhouri, Fadi
            Tucker, Michael
*/
```

#### 示例5

以下示例演示如何通过使用布尔比较表达式对源元素进行分组。 在此示例中，布尔表达式会测试学生的平均考试分数是否超过 75。 与上述示例一样，结果被投影到一个匿名类型中，因为不需要完整的源元素。 请注意，执行查询时，该匿名类型中的属性会变成 `Key` 成员上的属性，并且可以通过名称进行访问。

将以下方法粘贴到 `StudentClass` 类。 将 `Main` 方法中的调用语句更改为 `sc.GroupByBoolean()`。

```csharp
public void GroupByBoolean()
{            
    Console.WriteLine("\r\nGroup by a Boolean into two groups with string keys");
    Console.WriteLine("\"True\" and \"False\" and project into a new anonymous type:");
    var queryGroupByAverages = from student in students
                               group new { student.FirstName, student.LastName }
                                    by student.ExamScores.Average() > 75 into studentGroup
                               select studentGroup;

    foreach (var studentGroup in queryGroupByAverages)
    {
        Console.WriteLine($"Key: {studentGroup.Key}");
        foreach (var student in studentGroup)
            Console.WriteLine($"\t{student.FirstName} {student.LastName}");
    }            
}
/* Output:
    Group by a Boolean into two groups with string keys
    "True" and "False" and project into a new anonymous type:
    Key: True
            Terry Adams
            Fadi Fakhouri
            Hanying Feng
            Cesar Garcia
            Hugo Garcia
            Sven Mortensen
            Svetlana Omelchenko
            Lance Tucker
            Michael Tucker
            Eugene Zabokritski
    Key: False
            Debra Garcia
            Claire O'Donnell
*/
```

####  示例6

以下示例演示如何使用匿名类型来封装包含多个值的键。 在此示例中，第一个键值是学生姓氏的第一个字母。 第二个键值是一个布尔值，指定该学生在第一次考试中的得分是否超过了 85。 可以按照该键中的任何属性对组进行排序。

将以下方法粘贴到 `StudentClass` 类。 将 `Main` 方法中的调用语句更改为 `sc.GroupByCompositeKey()`。

```csharp
public void GroupByCompositeKey()
{
    var queryHighScoreGroups =
        from student in students
        group student by new { FirstLetter = student.LastName[0], 
            Score = student.ExamScores[0] > 85 } into studentGroup
        orderby studentGroup.Key.FirstLetter
        select studentGroup;

    Console.WriteLine("\r\nGroup and order by a compound key:");
    foreach (var scoreGroup in queryHighScoreGroups)
    {
        string s = scoreGroup.Key.Score == true ? "more than" : "less than";
        Console.WriteLine($"Name starts with {scoreGroup.Key.FirstLetter} who scored {s} 85");
        foreach (var item in scoreGroup)
        {
            Console.WriteLine($"\t{item.FirstName} {item.LastName}");
        }
    }
}

/* Output:
    Group and order by a compound key:
    Name starts with A who scored more than 85
            Terry Adams
    Name starts with F who scored more than 85
            Fadi Fakhouri
            Hanying Feng
    Name starts with G who scored more than 85
            Cesar Garcia
            Hugo Garcia
    Name starts with G who scored less than 85
            Debra Garcia
    Name starts with M who scored more than 85
            Sven Mortensen
    Name starts with O who scored less than 85
            Claire O'Donnell
    Name starts with O who scored more than 85
            Svetlana Omelchenko
    Name starts with T who scored less than 85
            Lance Tucker
    Name starts with T who scored more than 85
            Michael Tucker
    Name starts with Z who scored more than 85
            Eugene Zabokritski
*/
```

### [Create a nested group](https://docs.microsoft.com/en-us/dotnet/csharp/linq/create-a-nested-group)

以下示例演示如何在 LINQ 查询表达式中创建嵌套组。 首先根据学生年级创建每个组，然后根据每个人的姓名进一步细分为小组。

#### 示例

> 此示例包含对[查询对象集合](https://docs.microsoft.com/zh-cn/dotnet/csharp/linq/query-a-collection-of-objects)内示例代码中所定义对象的引用。

```csharp
public void QueryNestedGroups()
{
    var queryNestedGroups =
        from student in students
        group student by student.Year into newGroup1
        from newGroup2 in
            (from student in newGroup1
             group student by student.LastName)
        group newGroup2 by newGroup1.Key;

    // Three nested foreach loops are required to iterate 
    // over all elements of a grouped group. Hover the mouse 
    // cursor over the iteration variables to see their actual type.
    foreach (var outerGroup in queryNestedGroups)
    {
        Console.WriteLine($"DataClass.Student Level = {outerGroup.Key}");
        foreach (var innerGroup in outerGroup)
        {
            Console.WriteLine($"\tNames that begin with: {innerGroup.Key}");
            foreach (var innerGroupElement in innerGroup)
            {
                Console.WriteLine($"\t\t{innerGroupElement.LastName} {innerGroupElement.FirstName}");
            }
        }
    }
}
/*
 Output:
DataClass.Student Level = SecondYear
        Names that begin with: Adams
                Adams Terry
        Names that begin with: Garcia
                Garcia Hugo
        Names that begin with: Omelchenko
                Omelchenko Svetlana
DataClass.Student Level = ThirdYear
        Names that begin with: Fakhouri
                Fakhouri Fadi
        Names that begin with: Garcia
                Garcia Debra
        Names that begin with: Tucker
                Tucker Lance
DataClass.Student Level = FirstYear
        Names that begin with: Feng
                Feng Hanying
        Names that begin with: Mortensen
                Mortensen Sven
        Names that begin with: Tucker
                Tucker Michael
DataClass.Student Level = FourthYear
        Names that begin with: Garcia
                Garcia Cesar
        Names that begin with: O'Donnell
                O'Donnell Claire
        Names that begin with: Zabokritski
                Zabokritski Eugene        
 */
```

请注意，需要使用 3 个嵌套的 `foreach` 循环来循环访问嵌套组的内部元素。

### [Perform a subquery on a grouping operation](https://docs.microsoft.com/en-us/dotnet/csharp/linq/perform-a-subquery-on-a-grouping-operation)

本文演示创建查询的两种不同方式，此查询将源数据排序成组，然后分别对每个组执行子查询。 每个示例中的基本方法是使用名为 `newGroup` 的“接续块”对源元素进行分组，然后针对 `newGroup` 生成新的子查询。 针对由外部查询创建的每个新组运行此子查询。 请注意，在此特定示例中，最终输出不是组，而是一系列匿名类型。

有关如何分组的详细信息，请参阅 [group 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/group-clause)。

有关接续块的详细信息，请参阅 [into](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/into)。 下面的示例使用内存数据结构作为数据源，但相同的原则适用于任何类型的 LINQ 数据源。

#### 示例

>  此示例包含对[查询对象集合](https://docs.microsoft.com/zh-cn/dotnet/csharp/linq/query-a-collection-of-objects)内示例代码中所定义对象的引用。

```csharp
public void QueryMax()
{
    var queryGroupMax =
        from student in students
        group student by student.Year into studentGroup
        select new
        {
            Level = studentGroup.Key,
            HighestScore =
            (from student2 in studentGroup
             select student2.ExamScores.Average()).Max()
        };

    int count = queryGroupMax.Count();
    Console.WriteLine($"Number of groups = {count}");

    foreach (var item in queryGroupMax)
    {
        Console.WriteLine($"  {item.Level} Highest Score={item.HighestScore}");
    }
}
```

此外，还可以使用方法语法编写上述代码片段中的查询。 下面的代码片段具有使用方法语法编写的语义上等效的查询。

```csharp
public void QueryMaxUsingMethodSyntax()
{
    var queryGroupMax = students
        .GroupBy(student => student.Year)
        .Select(studentGroup => new
        {
            Level = studentGroup.Key,
            HighestScore = studentGroup.Select(student2 => student2.ExamScores.Average()).Max()
        });

    int count = queryGroupMax.Count();
    Console.WriteLine($"Number of groups = {count}");

    foreach (var item in queryGroupMax)
    {
        Console.WriteLine($"  {item.Level} Highest Score={item.HighestScore}");
    }
}
```

### [Group results by contiguous keys](https://docs.microsoft.com/en-us/dotnet/csharp/linq/group-results-by-contiguous-keys)

下面的示例演示如何将元素分组为表示连续键子序列的区块。 例如，假设给定下列键值对的序列：

| 键                    | “值”   |
| --------------------- | ------ |
| 包含当前请求的 URL 的 | We     |
| 包含当前请求的 URL 的 | think  |
| 包含当前请求的 URL 的 | that   |
| B                     | Linq   |
| C                     | is     |
| 包含当前请求的 URL 的 | really |
| B                     | cool   |
| B                     | !      |

以下组将按此顺序创建：

1. We, think, that
2. Linq
3. is
4. really
5. cool, !

此解决方案是以扩展方法实现的，该扩展方法是线程安全的，并以流的方式返回其结果。 换言之，它在源序列中遍历移动时生成其组。 与 `group` 或 `orderby` 运算符不同，它能在所有序列被读取之前开始将组返回给调用方。

线程安全通过在循环访问源序列的同时创建每个组或区块的副本来实现，如源代码注释中所述。 如果源序列具有大型的连续项序列，则公共语言运行时可能会引发 [OutOfMemoryException](https://docs.microsoft.com/zh-cn/dotnet/api/system.outofmemoryexception)。

#### 示例

下面的示例演示该扩展方法以及使用它的客户端代码：

```csharp
using System;
using System.Collections.Generic;
using System.Linq;


namespace ChunkIt
{
    // Static class to contain the extension methods.
    public static class MyExtensions
    {
        public static IEnumerable<IGrouping<TKey, TSource>> ChunkBy<TSource, TKey>(this IEnumerable<TSource> source, Func<TSource, TKey> keySelector)
        {
            return source.ChunkBy(keySelector, EqualityComparer<TKey>.Default);
        }

        public static IEnumerable<IGrouping<TKey, TSource>> ChunkBy<TSource, TKey>(this IEnumerable<TSource> source, Func<TSource, TKey> keySelector, IEqualityComparer<TKey> comparer)
        {
            // Flag to signal end of source sequence.
            const bool noMoreSourceElements = true;

            // Auto-generated iterator for the source array.       
            var enumerator = source.GetEnumerator();

            // Move to the first element in the source sequence.
            if (!enumerator.MoveNext()) yield break;

            // Iterate through source sequence and create a copy of each Chunk.
            // On each pass, the iterator advances to the first element of the next "Chunk"
            // in the source sequence. This loop corresponds to the outer foreach loop that
            // executes the query.
            Chunk<TKey, TSource> current = null;
            while (true)
            {
                // Get the key for the current Chunk. The source iterator will churn through
                // the source sequence until it finds an element with a key that doesn't match.
                var key = keySelector(enumerator.Current);

                // Make a new Chunk (group) object that initially has one GroupItem, which is a copy of the current source element.
                current = new Chunk<TKey, TSource>(key, enumerator, value => comparer.Equals(key, keySelector(value)));

                // Return the Chunk. A Chunk is an IGrouping<TKey,TSource>, which is the return value of the ChunkBy method.
                // At this point the Chunk only has the first element in its source sequence. The remaining elements will be
                // returned only when the client code foreach's over this chunk. See Chunk.GetEnumerator for more info.
                yield return current;

                // Check to see whether (a) the chunk has made a copy of all its source elements or 
                // (b) the iterator has reached the end of the source sequence. If the caller uses an inner
                // foreach loop to iterate the chunk items, and that loop ran to completion,
                // then the Chunk.GetEnumerator method will already have made
                // copies of all chunk items before we get here. If the Chunk.GetEnumerator loop did not
                // enumerate all elements in the chunk, we need to do it here to avoid corrupting the iterator
                // for clients that may be calling us on a separate thread.
                if (current.CopyAllChunkElements() == noMoreSourceElements)
                {
                    yield break;
                }
            }
        }

        // A Chunk is a contiguous group of one or more source elements that have the same key. A Chunk 
        // has a key and a list of ChunkItem objects, which are copies of the elements in the source sequence.
        class Chunk<TKey, TSource> : IGrouping<TKey, TSource>
        {
            // INVARIANT: DoneCopyingChunk == true || 
            //   (predicate != null && predicate(enumerator.Current) && current.Value == enumerator.Current)

            // A Chunk has a linked list of ChunkItems, which represent the elements in the current chunk. Each ChunkItem
            // has a reference to the next ChunkItem in the list.
            class ChunkItem
            {
                public ChunkItem(TSource value)
                {
                    Value = value;
                }
                public readonly TSource Value;
                public ChunkItem Next = null;
            }

            // The value that is used to determine matching elements
            private readonly TKey key;

            // Stores a reference to the enumerator for the source sequence
            private IEnumerator<TSource> enumerator;

            // A reference to the predicate that is used to compare keys.
            private Func<TSource, bool> predicate;

            // Stores the contents of the first source element that
            // belongs with this chunk.
            private readonly ChunkItem head;

            // End of the list. It is repositioned each time a new
            // ChunkItem is added.
            private ChunkItem tail;

            // Flag to indicate the source iterator has reached the end of the source sequence.
            internal bool isLastSourceElement = false;

            // Private object for thread syncronization
            private object m_Lock;

            // REQUIRES: enumerator != null && predicate != null
            public Chunk(TKey key, IEnumerator<TSource> enumerator, Func<TSource, bool> predicate)
            {
                this.key = key;
                this.enumerator = enumerator;
                this.predicate = predicate;

                // A Chunk always contains at least one element.
                head = new ChunkItem(enumerator.Current);

                // The end and beginning are the same until the list contains > 1 elements.
                tail = head;

                m_Lock = new object();
            }

            // Indicates that all chunk elements have been copied to the list of ChunkItems, 
            // and the source enumerator is either at the end, or else on an element with a new key.
            // the tail of the linked list is set to null in the CopyNextChunkElement method if the
            // key of the next element does not match the current chunk's key, or there are no more elements in the source.
            private bool DoneCopyingChunk => tail == null;

            // Adds one ChunkItem to the current group
            // REQUIRES: !DoneCopyingChunk && lock(this)
            private void CopyNextChunkElement()
            {
                // Try to advance the iterator on the source sequence.
                // If MoveNext returns false we are at the end, and isLastSourceElement is set to true
                isLastSourceElement = !enumerator.MoveNext();

                // If we are (a) at the end of the source, or (b) at the end of the current chunk
                // then null out the enumerator and predicate for reuse with the next chunk.
                if (isLastSourceElement || !predicate(enumerator.Current))
                {
                    enumerator = null;
                    predicate = null;
                }
                else
                {
                    tail.Next = new ChunkItem(enumerator.Current);
                }

                // tail will be null if we are at the end of the chunk elements
                // This check is made in DoneCopyingChunk.
                tail = tail.Next;
            }

            // Called after the end of the last chunk was reached. It first checks whether
            // there are more elements in the source sequence. If there are, it 
            // Returns true if enumerator for this chunk was exhausted.
            internal bool CopyAllChunkElements()
            {
                while (true)
                {
                    lock (m_Lock)
                    {
                        if (DoneCopyingChunk)
                        {
                            // If isLastSourceElement is false,
                            // it signals to the outer iterator
                            // to continue iterating.
                            return isLastSourceElement;
                        }
                        else
                        {
                            CopyNextChunkElement();
                        }
                    }
                }
            }

            public TKey Key => key;

            // Invoked by the inner foreach loop. This method stays just one step ahead
            // of the client requests. It adds the next element of the chunk only after
            // the clients requests the last element in the list so far.
            public IEnumerator<TSource> GetEnumerator()
            {
                //Specify the initial element to enumerate.
                ChunkItem current = head;

                // There should always be at least one ChunkItem in a Chunk.
                while (current != null)
                {
                    // Yield the current item in the list.
                    yield return current.Value;

                    // Copy the next item from the source sequence, 
                    // if we are at the end of our local list.
                    lock (m_Lock)
                    {
                        if (current == tail)
                        {
                            CopyNextChunkElement();
                        }
                    }

                    // Move to the next ChunkItem in the list.
                    current = current.Next;
                }
            }

            System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator() => GetEnumerator();
        }
    }

    // A simple named type is used for easier viewing in the debugger. Anonymous types
    // work just as well with the ChunkBy operator.
    public class KeyValPair
    {
        public string Key { get; set; }
        public string Value { get; set; }
    }

    class Program
    {
        // The source sequence.
        public static IEnumerable<KeyValPair> list;

        // Query variable declared as class member to be available
        // on different threads.
        static IEnumerable<IGrouping<string, KeyValPair>> query;

        static void Main(string[] args)
        {
            // Initialize the source sequence with an array initializer.
            list = new[]
            {
                new KeyValPair{ Key = "A", Value = "We" },
                new KeyValPair{ Key = "A", Value = "think" },
                new KeyValPair{ Key = "A", Value = "that" },
                new KeyValPair{ Key = "B", Value = "Linq" },
                new KeyValPair{ Key = "C", Value = "is" },
                new KeyValPair{ Key = "A", Value = "really" },
                new KeyValPair{ Key = "B", Value = "cool" },
                new KeyValPair{ Key = "B", Value = "!" }
            };

            // Create the query by using our user-defined query operator.
            query = list.ChunkBy(p => p.Key);


            // ChunkBy returns IGrouping objects, therefore a nested
            // foreach loop is required to access the elements in each "chunk".
            foreach (var item in query)
            {
                Console.WriteLine($"Group key = {item.Key}");
                foreach (var inner in item)
                {
                    Console.WriteLine($"\t{inner.Value}");
                }
            }

            Console.WriteLine("Press any key to exit");
            Console.ReadKey();
        }
    }
}
```

若要在项目中使用扩展方法，请将 `MyExtensions` 静态类复制到新的或现有源代码文件中，并且如有需要，请为它所在的命名空间添加 `using` 指令。

### [Dynamically specify predicate filters at runtime](https://docs.microsoft.com/en-us/dotnet/csharp/linq/dynamically-specify-predicate-filters-at-runtime)

在某些情况下，在运行时之前你不知道必须将多少个谓词应用于 `where` 子句中的源元素。 动态指定多个谓词筛选器的方法之一是使用 [Contains](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.contains) 方法，如以下示例中所示。 该示例通过两种方式构造。 首先，通过对程序中提供的值进行筛选来运行项目。 然后通过使用在运行时提供的输入再次运行该项目。

#### 使用 Contains 方法进行筛选

1. 打开一个新的控制台应用程序并将其命名为 `PredicateFilters`。

2. 从[查询对象的集合](https://docs.microsoft.com/zh-cn/dotnet/csharp/linq/query-a-collection-of-objects)复制 `StudentClass` 类，并将其粘贴到类 `Program` 下方的命名空间 `PredicateFilters`。 `StudentClass` 提供 `Student` 对象的列表。

3. 注释禁止 `StudentClass` 中的 `Main` 方法。

4. 将类 `Program` 替换为以下代码：

   ```csharp
   class DynamicPredicates : StudentClass
   {
       static void Main(string[] args)
       {
           string[] ids = { "111", "114", "112" };
   
           Console.WriteLine("Press any key to exit.");
           Console.ReadKey();
       }
   
       static void QueryByID(string[] ids)
       {
           var queryNames =
               from student in students
               let i = student.ID.ToString()
               where ids.Contains(i)
               select new { student.LastName, student.ID };
   
           foreach (var name in queryNames)
           {
               Console.WriteLine($"{name.LastName}: {name.ID}");
           }
       }
   }
   ```

5. 将以下行添加到类 `DynamicPredicates` 中 `ids` 声明下的 `Main` 方法。

   ```csharp
   QueryById(ids);
   ```

6. 运行该项目。

7. 在控制台窗口中显示以下输出：

   ```
   Garcia:114
   O'Donnell:112
   Omelchenko:111
   ```

8. 下一步是再次运行该项目，此次是通过使用在运行时输入的输入而非数组 `ids` 来执行此操作。 在 `Main` 方法中，将 `QueryByID(ids)` 更改为 `QueryByID(args)`。

9. 使用命令行参数 `122 117 120 115` 运行该项目。 运行项目时，这些值将成为 `args` 的元素，它们是 `Main`方法的参数。

10. 在控制台窗口中显示以下输出：

    ```
    Adams:120
    Feng:117
    Garcia:115
    Tucker:122
    ```

#### 使用 switch 语句进行筛选

1. 可以使用 `switch` 语句在预先确定的备选查询中进行选择。 在下面的示例中，`studentQuery` 使用不同的 `where` 子句，具体取决于在运行时指定的等级级别或年。

2. 复制下面的方法，并将其粘贴到类 `DynamicPredicates`。

   ```csharp
   // To run this sample, first specify an integer value of 1 to 4 for the command
   // line. This number will be converted to a GradeLevel value that specifies which
   // set of students to query. 
   // Call the method: QueryByYear(args[0]);
   
   static void QueryByYear(string level)
   {
       GradeLevel year = (GradeLevel)Convert.ToInt32(level);
       IEnumerable<Student> studentQuery = null;
       switch (year)
       {
           case GradeLevel.FirstYear:
               studentQuery = from student in students
                              where student.Year == GradeLevel.FirstYear
                              select student;
               break;
           case GradeLevel.SecondYear:
               studentQuery = from student in students
                              where student.Year == GradeLevel.SecondYear
                              select student;
               break;
           case GradeLevel.ThirdYear:
               studentQuery = from student in students
                              where student.Year == GradeLevel.ThirdYear
                              select student;
               break;
           case GradeLevel.FourthYear:
               studentQuery = from student in students
                              where student.Year == GradeLevel.FourthYear
                              select student;
               break;
   
           default:
               break;
       }
       Console.WriteLine($"The following students are at level {year}");
       foreach (Student name in studentQuery)
       {
           Console.WriteLine($"{name.LastName}: {name.ID}");
       }
   }
   ```

3. 在 `Main` 方法中，将对 `QueryByID` 的调用替换为以下调用，该调用将 `args` 数组中的第一个元素作为其参数发送：`QueryByYear(args[0])`。

4. 运行该项目，其命令行参数为介于 1 和 4 之间的整数值。

### [Perform inner joins](https://docs.microsoft.com/en-us/dotnet/csharp/linq/perform-inner-joins)

在关系数据库术语中，内部联接会生成一个结果集，在该结果集中，第一个集合的每个元素对于第二个集合中的每个匹配元素都会出现一次。 如果第一个集合中的元素没有匹配元素，则它不会出现在结果集中。 由 C# 中的 `join` 子句调用的 [Join](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.join) 方法可实现内部联接。

本文演示如何执行内联的四种变体：

- 基于简单键使两个数据源中的元素相关联的简单内部联接。
- 基于复合键使两个数据源中的元素相关联的内部联接。 复合键是由多个值组成的键，使你可以基于多个属性使元素相关联。
- 在其中将连续联接操作相互追加的多联接。
- 使用分组联接实现的内部联接。

#### 示例 - 简单键联接

下面的示例创建两个集合，其中包含两种用户定义类型 `Person` 和 `Pet` 的对象。 查询使用 C# 中的 `join` 子句将 `Person` 对象与 `Owner` 是该 `Person` 的 `Pet` 对象匹配。 C# 中的 `select` 子句定义结果对象的外观。 在此示例中，结果对象是由所有者名字和宠物姓名组成的匿名类型。

```csharp
class Person
{
    public string FirstName { get; set; }
    public string LastName { get; set; }
}

class Pet
{
    public string Name { get; set; }
    public Person Owner { get; set; }
}

/// <summary>
/// Simple inner join.
/// </summary>
public static void InnerJoinExample()
{
    Person magnus = new Person { FirstName = "Magnus", LastName = "Hedlund" };
    Person terry = new Person { FirstName = "Terry", LastName = "Adams" };
    Person charlotte = new Person { FirstName = "Charlotte", LastName = "Weiss" };
    Person arlene = new Person { FirstName = "Arlene", LastName = "Huff" };
    Person rui = new Person { FirstName = "Rui", LastName = "Raposo" };

    Pet barley = new Pet { Name = "Barley", Owner = terry };
    Pet boots = new Pet { Name = "Boots", Owner = terry };
    Pet whiskers = new Pet { Name = "Whiskers", Owner = charlotte };
    Pet bluemoon = new Pet { Name = "Blue Moon", Owner = rui };
    Pet daisy = new Pet { Name = "Daisy", Owner = magnus };

    // Create two lists.
    List<Person> people = new List<Person> { magnus, terry, charlotte, arlene, rui };
    List<Pet> pets = new List<Pet> { barley, boots, whiskers, bluemoon, daisy };

    // Create a collection of person-pet pairs. Each element in the collection
    // is an anonymous type containing both the person's name and their pet's name.
    var query = from person in people
                join pet in pets on person equals pet.Owner
                select new { OwnerName = person.FirstName, PetName = pet.Name };

    foreach (var ownerAndPet in query)
    {
        Console.WriteLine($"\"{ownerAndPet.PetName}\" is owned by {ownerAndPet.OwnerName}");
    }
}

// This code produces the following output:
//
// "Daisy" is owned by Magnus
// "Barley" is owned by Terry
// "Boots" is owned by Terry
// "Whiskers" is owned by Charlotte
// "Blue Moon" is owned by Rui
```

请注意，`LastName` 是“Huff”的 `Person` 对象未出现在结果集中，因为没有 `Pet` 对象的 `Pet.Owner` 等于该 `Person`。

#### 示例 - 组合键联接

可以使用复合键基于多个属性来比较元素，而不是只基于一个属性使元素相关联。 为此，请为每个集合指定键选择器函数，以返回由要比较的属性组成的匿名类型。 如果对属性进行标记，则它们必须在每个键的匿名类型中具有相同标签。 属性还必须按相同顺序出现。

下面的示例使用 `Employee` 对象的列表和 `Student` 对象的列表来确定哪些雇员同时还是学生。 这两种类型都具有 [String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string) 类型的 `FirstName` 和 `LastName` 属性。 通过每个列表的元素创建联接键的函数会返回由每个元素的 `FirstName` 和 `LastName` 属性组成的匿名类型。 联接运算会比较这些复合键是否相等，并从每个列表返回名字和姓氏都匹配的对象对。

```csharp
class Employee
{
    public string FirstName { get; set; }
    public string LastName { get; set; }
    public int EmployeeID { get; set; }
}

class Student
{
    public string FirstName { get; set; }
    public string LastName { get; set; }
    public int StudentID { get; set; }
}

/// <summary>
/// Performs a join operation using a composite key.
/// </summary>
public static void CompositeKeyJoinExample()
{
    // Create a list of employees.
    List<Employee> employees = new List<Employee> {
        new Employee { FirstName = "Terry", LastName = "Adams", EmployeeID = 522459 },
         new Employee { FirstName = "Charlotte", LastName = "Weiss", EmployeeID = 204467 },
         new Employee { FirstName = "Magnus", LastName = "Hedland", EmployeeID = 866200 },
         new Employee { FirstName = "Vernette", LastName = "Price", EmployeeID = 437139 } };

    // Create a list of students.
    List<Student> students = new List<Student> {
        new Student { FirstName = "Vernette", LastName = "Price", StudentID = 9562 },
        new Student { FirstName = "Terry", LastName = "Earls", StudentID = 9870 },
        new Student { FirstName = "Terry", LastName = "Adams", StudentID = 9913 } };

    // Join the two data sources based on a composite key consisting of first and last name,
    // to determine which employees are also students.
    IEnumerable<string> query = from employee in employees
                                join student in students
                                on new { employee.FirstName, employee.LastName }
                                equals new { student.FirstName, student.LastName }
                                select employee.FirstName + " " + employee.LastName;

    Console.WriteLine("The following people are both employees and students:");
    foreach (string name in query)
        Console.WriteLine(name);
}

// This code produces the following output:
//
// The following people are both employees and students:
// Terry Adams
// Vernette Price
```

#### 示例 - 多联接

可以将任意数量的联接操作相互追加，以执行多联接。 C# 中的每个 `join` 子句会将指定数据源与上一个联接的结果相关联。

下面的示例创建三个集合：`Person` 对象的列表、`Cat` 对象的列表和 `Dog` 对象的列表。

C# 中的第一个 `join` 子句基于与 `Cat.Owner` 匹配的 `Person` 对象来匹配人和猫。 它返回包含 `Person` 对象和 `Cat.Name` 的匿名类型的序列。

C# 中的第二个 `join` 子句基于由 `Owner` 类型的 `Person` 属性和动物姓名的第一个字母组成的复合键，将第一个联接返回的匿名类型与提供的狗列表中的 `Dog` 对象相关联。 它返回包含来自每个匹配对的 `Cat.Name` 和 `Dog.Name` 属性的匿名类型的序列。 由于这是内部联接，因此只返回第一个数据源中在第二个数据源中具有匹配项的对象。

```csharp
class Person
{
    public string FirstName { get; set; }
    public string LastName { get; set; }
}

class Pet
{
    public string Name { get; set; }
    public Person Owner { get; set; }
}

class Cat : Pet
{ }

class Dog : Pet
{ }

public static void MultipleJoinExample()
{
    Person magnus = new Person { FirstName = "Magnus", LastName = "Hedlund" };
    Person terry = new Person { FirstName = "Terry", LastName = "Adams" };
    Person charlotte = new Person { FirstName = "Charlotte", LastName = "Weiss" };
    Person arlene = new Person { FirstName = "Arlene", LastName = "Huff" };
    Person rui = new Person { FirstName = "Rui", LastName = "Raposo" };
    Person phyllis = new Person { FirstName = "Phyllis", LastName = "Harris" };

    Cat barley = new Cat { Name = "Barley", Owner = terry };
    Cat boots = new Cat { Name = "Boots", Owner = terry };
    Cat whiskers = new Cat { Name = "Whiskers", Owner = charlotte };
    Cat bluemoon = new Cat { Name = "Blue Moon", Owner = rui };
    Cat daisy = new Cat { Name = "Daisy", Owner = magnus };

    Dog fourwheeldrive = new Dog { Name = "Four Wheel Drive", Owner = phyllis };
    Dog duke = new Dog { Name = "Duke", Owner = magnus };
    Dog denim = new Dog { Name = "Denim", Owner = terry };
    Dog wiley = new Dog { Name = "Wiley", Owner = charlotte };
    Dog snoopy = new Dog { Name = "Snoopy", Owner = rui };
    Dog snickers = new Dog { Name = "Snickers", Owner = arlene };

    // Create three lists.
    List<Person> people =
        new List<Person> { magnus, terry, charlotte, arlene, rui, phyllis };
    List<Cat> cats =
        new List<Cat> { barley, boots, whiskers, bluemoon, daisy };
    List<Dog> dogs =
        new List<Dog> { fourwheeldrive, duke, denim, wiley, snoopy, snickers };

    // The first join matches Person and Cat.Owner from the list of people and
    // cats, based on a common Person. The second join matches dogs whose names start
    // with the same letter as the cats that have the same owner.
    var query = from person in people
                join cat in cats on person equals cat.Owner
                join dog in dogs on 
                new { Owner = person, Letter = cat.Name.Substring(0, 1) }
                equals new { dog.Owner, Letter = dog.Name.Substring(0, 1) }
                select new { CatName = cat.Name, DogName = dog.Name };

    foreach (var obj in query)
    {
        Console.WriteLine( 
            $"The cat \"{obj.CatName}\" shares a house, and the first letter of their name,
            with \"{obj.DogName}\".");  
    }
}

// This code produces the following output:
//
// The cat "Daisy" shares a house, and the first letter of their name, with "Duke".
// The cat "Whiskers" shares a house, and the first letter of their name, with "Wiley".
```

#### 示例 - 使用分组联接的内联

下面的示例演示如何使用分组联接实现内部联接。

在 `query1` 中，`Person` 对象的列表会基于与 `Pet.Owner` 属性匹配的 `Person`，分组联接到 `Pet` 对象队列中。分组联接会创建中间组的集合，其中每个组都包含 `Person` 对象和匹配 `Pet` 对象的序列。

通过向查询添加另一个 `from` 子句，此序列的序列会合并（或平展）为一个较长的序列。 最后一个序列的元素的类型由 `select` 子句指定。 在此示例中，该类型是由每个匹配对的 `Person.FirstName` 和 `Pet.Name` 属性组成的匿名类型。

`query1` 的结果等效于通过使用 `join` 子句（不使用 `into` 子句）执行内部联接来获取的结果集。 `query2` 变量演示了此等效查询。

```csharp
class Person
{
    public string FirstName { get; set; }
    public string LastName { get; set; }
}

class Pet
{
    public string Name { get; set; }
    public Person Owner { get; set; }
}

/// <summary>
/// Performs an inner join by using GroupJoin().
/// </summary>
public static void InnerGroupJoinExample()
{
    Person magnus = new Person { FirstName = "Magnus", LastName = "Hedlund" };
    Person terry = new Person { FirstName = "Terry", LastName = "Adams" };
    Person charlotte = new Person { FirstName = "Charlotte", LastName = "Weiss" };
    Person arlene = new Person { FirstName = "Arlene", LastName = "Huff" };

    Pet barley = new Pet { Name = "Barley", Owner = terry };
    Pet boots = new Pet { Name = "Boots", Owner = terry };
    Pet whiskers = new Pet { Name = "Whiskers", Owner = charlotte };
    Pet bluemoon = new Pet { Name = "Blue Moon", Owner = terry };
    Pet daisy = new Pet { Name = "Daisy", Owner = magnus };

    // Create two lists.
    List<Person> people = new List<Person> { magnus, terry, charlotte, arlene };
    List<Pet> pets = new List<Pet> { barley, boots, whiskers, bluemoon, daisy };

    var query1 = from person in people
                 join pet in pets on person equals pet.Owner into gj
                 from subpet in gj
                 select new { OwnerName = person.FirstName, PetName = subpet.Name };

    Console.WriteLine("Inner join using GroupJoin():");
    foreach (var v in query1)
    {
        Console.WriteLine($"{v.OwnerName} - {v.PetName}"));
    }

    var query2 = from person in people
                 join pet in pets on person equals pet.Owner
                 select new { OwnerName = person.FirstName, PetName = pet.Name };
        
    Console.WriteLine("\nThe equivalent operation using Join():");
    foreach (var v in query2)
        Console.WriteLine($"{v.OwnerName} - {v.PetName}"));
}

// This code produces the following output:
//
// Inner join using GroupJoin():
// Magnus - Daisy
// Terry - Barley
// Terry - Boots
// Terry - Blue Moon
// Charlotte - Whiskers
//
// The equivalent operation using Join():
// Magnus - Daisy
// Terry - Barley
// Terry - Boots
// Terry - Blue Moon
// Charlotte - Whiskers
```

### [Perform grouped joins](https://docs.microsoft.com/en-us/dotnet/csharp/linq/perform-grouped-joins)

分组联接对于生成分层数据结构十分有用。 它将第一个集合中的每个元素与第二个集合中的一组相关元素进行配对。

例如，一个名为 `Student` 的类或关系数据库表可能包含两个字段：`Id` 和 `Name`。 另一个名为 `Course` 的类或关系数据库表可能包含两个字段：`StudentId` 和 `CourseTitle`。 这两个数据源的分组联接（基于匹配 `Student.Id` 和 `Course.StudentId`）会对具有 `Course` 对象集合（可能为空）的每个 `Student` 进行分组。

> 第一个集合的每个元素都会出现在分组联接的结果集中（无论是否在第二个集合中找到关联元素）。 在未找到任何相关元素的情况下，该元素的相关元素序列为空。 因此，结果选择器有权访问第一个集合的每个元素。 这与非分组联接中的结果选择器不同，后者无法访问第一个集合中在第二个集合中没有匹配项的元素。

本文的第一个示例演示如何执行分组联接。 第二个示例演示如何使用分组联接创建 XML 元素。

#### 示例 - 分组联接

下面的示例基于与 `Pet.Owner` 属性匹配的 `Person`，来执行类型 `Person` 和 `Pet` 的对象的分组联接。 与非分组联接（会为每个匹配生成元素对）不同，分组联接只为第一个集合的每个元素生成一个结果对象（在此示例中为 `Person` 对象）。 第二个集合中的对应元素（在此示例中为 `Pet` 对象）会分组到集合中。 最后，结果选择器函数会为每个匹配都创建一种匿名类型，其中包含 `Person.FirstName` 和 `Pet` 对象集合。

```csharp
class Person
{
    public string FirstName { get; set; }
    public string LastName { get; set; }
}

class Pet
{
    public string Name { get; set; }
    public Person Owner { get; set; }
}

/// <summary>
/// This example performs a grouped join.
/// </summary>
public static void GroupJoinExample()
{
    Person magnus = new Person { FirstName = "Magnus", LastName = "Hedlund" };
    Person terry = new Person { FirstName = "Terry", LastName = "Adams" };
    Person charlotte = new Person { FirstName = "Charlotte", LastName = "Weiss" };
    Person arlene = new Person { FirstName = "Arlene", LastName = "Huff" };

    Pet barley = new Pet { Name = "Barley", Owner = terry };
    Pet boots = new Pet { Name = "Boots", Owner = terry };
    Pet whiskers = new Pet { Name = "Whiskers", Owner = charlotte };
    Pet bluemoon = new Pet { Name = "Blue Moon", Owner = terry };
    Pet daisy = new Pet { Name = "Daisy", Owner = magnus };

    // Create two lists.
    List<Person> people = new List<Person> { magnus, terry, charlotte, arlene };
    List<Pet> pets = new List<Pet> { barley, boots, whiskers, bluemoon, daisy };

    // Create a list where each element is an anonymous type
    // that contains the person's first name and a collection of 
    // pets that are owned by them.
    var query = from person in people
                join pet in pets on person equals pet.Owner into gj
                select new { OwnerName = person.FirstName, Pets = gj };

    foreach (var v in query)
    {
        // Output the owner's name.
        Console.WriteLine($"{v.OwnerName}:");
        // Output each of the owner's pet's names.
        foreach (Pet pet in v.Pets)
            Console.WriteLine($"  {pet.Name}");
    }
}

// This code produces the following output:
//
// Magnus:
//   Daisy
// Terry:
//   Barley
//   Boots
//   Blue Moon
// Charlotte:
//   Whiskers
// Arlene:
```

#### 示例 - 用于创建 XML 的分组联接

分组联接非常适合于使用 LINQ to XML 创建 XML。 下面的示例类似于上面的示例，不过结果选择器函数不会创建匿名类型，而是创建表示联接对象的 XML 元素。

```csharp
class Person
{
    public string FirstName { get; set; }
    public string LastName { get; set; }
}

class Pet
{
    public string Name { get; set; }
    public Person Owner { get; set; }
}

/// <summary>
/// This example creates XML output from a grouped join.
/// </summary>
public static void GroupJoinXMLExample()
{
    Person magnus = new Person { FirstName = "Magnus", LastName = "Hedlund" };
    Person terry = new Person { FirstName = "Terry", LastName = "Adams" };
    Person charlotte = new Person { FirstName = "Charlotte", LastName = "Weiss" };
    Person arlene = new Person { FirstName = "Arlene", LastName = "Huff" };

    Pet barley = new Pet { Name = "Barley", Owner = terry };
    Pet boots = new Pet { Name = "Boots", Owner = terry };
    Pet whiskers = new Pet { Name = "Whiskers", Owner = charlotte };
    Pet bluemoon = new Pet { Name = "Blue Moon", Owner = terry };
    Pet daisy = new Pet { Name = "Daisy", Owner = magnus };

    // Create two lists.
    List<Person> people = new List<Person> { magnus, terry, charlotte, arlene };
    List<Pet> pets = new List<Pet> { barley, boots, whiskers, bluemoon, daisy };

    // Create XML to display the hierarchical organization of people and their pets.
    XElement ownersAndPets = new XElement("PetOwners",
        from person in people
        join pet in pets on person equals pet.Owner into gj
        select new XElement("Person",
            new XAttribute("FirstName", person.FirstName),
            new XAttribute("LastName", person.LastName),
            from subpet in gj
            select new XElement("Pet", subpet.Name)));

    Console.WriteLine(ownersAndPets);
}

// This code produces the following output:
//
// <PetOwners>
//   <Person FirstName="Magnus" LastName="Hedlund">
//     <Pet>Daisy</Pet>
//   </Person>
//   <Person FirstName="Terry" LastName="Adams">
//     <Pet>Barley</Pet>
//     <Pet>Boots</Pet>
//     <Pet>Blue Moon</Pet>
//   </Person>
//   <Person FirstName="Charlotte" LastName="Weiss">
//     <Pet>Whiskers</Pet>
//   </Person>
//   <Person FirstName="Arlene" LastName="Huff" />
// </PetOwners>
```

### [Perform left outer joins](https://docs.microsoft.com/en-us/dotnet/csharp/linq/perform-left-outer-joins)

左外部联接是这样定义的：返回第一个集合的每个元素，无论该元素在第二个集合中是否有任何相关元素。 可以使用 LINQ 通过对分组联接的结果调用 [DefaultIfEmpty](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.defaultifempty) 方法来执行左外部联接。

#### 示例

下面的示例演示如何对分组联接的结果调用 [DefaultIfEmpty](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.defaultifempty) 方法来执行左外部联接。

若要生成两个集合的左外部联接，第一步是使用分组联接执行内联。 （有关此过程的说明，请参阅[执行内联](https://docs.microsoft.com/zh-cn/dotnet/csharp/linq/perform-inner-joins)。）在此示例中，`Person` 对象列表基于与 `Pet.Owner` 匹配的 `Person` 对象内联到 `Pet` 对象列表。

第二步是在结果集内包含第一个（左）集合的每个元素，即使该元素在右集合中没有匹配的元素也是如此。 这是通过对分组联接中的每个匹配元素序列调用 [DefaultIfEmpty](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.defaultifempty) 来实现的。 此示例中，对每个匹配 `Pet` 对象的序列调用 [DefaultIfEmpty](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.defaultifempty)。 如果对于任何 `Person` 对象，匹配 `Pet` 对象序列均为空，则该方法返回一个包含单个默认值的集合，从而确保结果集合中显示每个 `Person` 对象。

> 引用类型的默认值为 `null`；因此，该示例在访问每个 `Pet` 集合的每个元素之前会先检查是否存在空引用。

```csharp
class Person
{
    public string FirstName { get; set; }
    public string LastName { get; set; }
}

class Pet
{
    public string Name { get; set; }
    public Person Owner { get; set; }
}

public static void LeftOuterJoinExample()
{
    Person magnus = new Person { FirstName = "Magnus", LastName = "Hedlund" };
    Person terry = new Person { FirstName = "Terry", LastName = "Adams" };
    Person charlotte = new Person { FirstName = "Charlotte", LastName = "Weiss" };
    Person arlene = new Person { FirstName = "Arlene", LastName = "Huff" };

    Pet barley = new Pet { Name = "Barley", Owner = terry };
    Pet boots = new Pet { Name = "Boots", Owner = terry };
    Pet whiskers = new Pet { Name = "Whiskers", Owner = charlotte };
    Pet bluemoon = new Pet { Name = "Blue Moon", Owner = terry };
    Pet daisy = new Pet { Name = "Daisy", Owner = magnus };

    // Create two lists.
    List<Person> people = new List<Person> { magnus, terry, charlotte, arlene };
    List<Pet> pets = new List<Pet> { barley, boots, whiskers, bluemoon, daisy };

    var query = from person in people
                join pet in pets on person equals pet.Owner into gj
                from subpet in gj.DefaultIfEmpty()
                select new { person.FirstName, PetName = subpet?.Name ?? String.Empty };

    foreach (var v in query)
    {
        Console.WriteLine($"{v.FirstName+":",-15}{v.PetName}");
    }
}

// This code produces the following output:
//
// Magnus:        Daisy
// Terry:         Barley
// Terry:         Boots
// Terry:         Blue Moon
// Charlotte:     Whiskers
// Arlene:
```

### [Order the results of a join clause](https://docs.microsoft.com/en-us/dotnet/csharp/linq/order-the-results-of-a-join-clause)

此示例演示如何对联接运算的结果进行排序。 请注意，排序在联接之后执行。 虽然可以在联接之前将 `orderby`子句用于一个或多个源序列，不过通常不建议这样做。 某些 LINQ 提供程序可能不会在联接之后保留该排序。

#### 示例

此查询创建一个分组联接，然后基于类别元素（仍处于范围中）对组进行排序。 在匿名类型初始值设定项内，一个子查询对来自产品序列的所有匹配元素进行排序。

```csharp
     class HowToOrderJoins
     {
         #region Data
         class Product
         {
             public string Name { get; set; }
             public int CategoryID { get; set; }
         }

         class Category
         {
             public string Name { get; set; }
             public int ID { get; set; }
         }

         // Specify the first data source.
         List<Category> categories = new List<Category>()
 { 
     new Category(){Name="Beverages", ID=001},
     new Category(){ Name="Condiments", ID=002},
     new Category(){ Name="Vegetables", ID=003},
     new Category() {  Name="Grains", ID=004},
     new Category() {  Name="Fruit", ID=005}            
 };

         // Specify the second data source.
         List<Product> products = new List<Product>()
{
   new Product{Name="Cola",  CategoryID=001},
   new Product{Name="Tea",  CategoryID=001},
   new Product{Name="Mustard", CategoryID=002},
   new Product{Name="Pickles", CategoryID=002},
   new Product{Name="Carrots", CategoryID=003},
   new Product{Name="Bok Choy", CategoryID=003},
   new Product{Name="Peaches", CategoryID=005},
   new Product{Name="Melons", CategoryID=005},
 };
         #endregion
         static void Main()
         {
             HowToOrderJoins app = new HowToOrderJoins();
             app.OrderJoin1();

             // Keep console window open in debug mode.
             Console.WriteLine("Press any key to exit.");
             Console.ReadKey();

         }

         void OrderJoin1()
         {
             var groupJoinQuery2 =
                 from category in categories
                 join prod in products on category.ID equals prod.CategoryID into prodGroup
                 orderby category.Name
                 select new
                 {
                     Category = category.Name,
                     Products = from prod2 in prodGroup
                                orderby prod2.Name
                                select prod2
                 };

             foreach (var productGroup in groupJoinQuery2)
             {
                 Console.WriteLine(productGroup.Category);
                 foreach (var prodItem in productGroup.Products)
                 {
                     Console.WriteLine($"  {prodItem.Name,-10} {prodItem.CategoryID}");
                 }
             }
         }
         /* Output:
             Beverages
               Cola       1
               Tea        1
             Condiments
               Mustard    2
               Pickles    2
             Fruit
               Melons     5
               Peaches    5
             Grains
             Vegetables
               Bok Choy   3
               Carrots    3
          */
     }
```

### [Join by using composite keys](https://docs.microsoft.com/en-us/dotnet/csharp/linq/join-by-using-composite-keys)

此示例演示如何执行想要使用多个键来定义匹配的联接操作。 使用组合键来完成此操作。 以匿名类型或包含要比较值的命名类型的形式来创建组合键。 若要跨方法边界传递查询变量，请为该键使用重写 [Equals](https://docs.microsoft.com/zh-cn/dotnet/api/system.object.equals) 和 [GetHashCode](https://docs.microsoft.com/zh-cn/dotnet/api/system.object.gethashcode)的命名类型。 属性的名称以及属性出现的顺序在每个键中必须相同。

#### 示例

以下示例演示如何使用组合键联接 3 个表中的数据：

```csharp
var query = from o in db.Orders
    from p in db.Products
    join d in db.OrderDetails
        on new {o.OrderID, p.ProductID} equals new {d.OrderID, d.ProductID} into details
        from d in details
        select new {o.OrderID, p.ProductID, d.UnitPrice};
```

组合键上的类型推理取决于这些键中属性的名称，以及属性出现的顺序。 如果源序列中属性的名称不同，则必须在键中分配新名称。 例如，如果 `Orders` 表和 `OrderDetails` 表为各自的列分别使用不同的名称，则可通过在匿名类型中分配相同的名称来创建组合键：

```csharp
join...on new {Name = o.CustomerName, ID = o.CustID} equals
    new {Name = d.CustName, ID = d.CustID }
```

还可以在 `group` 子句中使用组合键。

### [Perform custom join operations](https://docs.microsoft.com/en-us/dotnet/csharp/linq/perform-custom-join-operations)

此示例演示如何执行无法使用 `join` 子句实现的联接操作。 在查询表达式中，`join` 子句只限于同等联接（并针对其进行优化），这类联接到目前为止是最常见的联接操作类型。 执行同等联接时，可能会始终使用 `join` 子句获得最佳性能。

但是，在以下情况下不能使用 `join` 子句：

- 当联接依据不等式表达式时（非同等联接）。
- 当联接依据多个等式或不等式表达式时。
- 当必须为联接操作前的右侧（内部）序列引入临时范围变量。

若要执行不是同等联接的联接，可以使用多个 `from` 子句独立引入每个数据源。 随后可在 `where` 子句中将谓词表达式应用于每个源的范围变量。 表达式还可以采用方法调用的形式。

>  不要将这种类型的自定义联接操作与使用多个 `from` 子句访问内部集合相混淆。 有关详细信息，请参阅 [join 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/join-clause)。

#### 示例

以下示例中的第一个方法演示一个简单的交叉联接。 必须谨慎使用交叉联接，因为它们可能会生成非常大的结果集。 但是，在创建针对其运行其他查询的源序列的某些情况下，它们可能会十分有用。

第二个方法会生成其类别 ID 在左侧类别列表中列出的所有产品的序列。 请注意，其中使用 `let` 子句和 `Contains` 方法创建临时数组。 还可以在查询前创建数组并去掉第一个 `from` 子句。

```csharp
     class CustomJoins
     {

         #region Data

         class Product
         {
             public string Name { get; set; }
             public int CategoryID { get; set; }
         }

         class Category
         {
             public string Name { get; set; }
             public int ID { get; set; }
         }

         // Specify the first data source.
         List<Category> categories = new List<Category>()
 { 
     new Category(){Name="Beverages", ID=001},
     new Category(){ Name="Condiments", ID=002},
     new Category(){ Name="Vegetables", ID=003},         
 };

         // Specify the second data source.
         List<Product> products = new List<Product>()
{
   new Product{Name="Tea",  CategoryID=001},
   new Product{Name="Mustard", CategoryID=002},
   new Product{Name="Pickles", CategoryID=002},
   new Product{Name="Carrots", CategoryID=003},
   new Product{Name="Bok Choy", CategoryID=003},
   new Product{Name="Peaches", CategoryID=005},
   new Product{Name="Melons", CategoryID=005},
   new Product{Name="Ice Cream", CategoryID=007},
   new Product{Name="Mackerel", CategoryID=012},
 };
         #endregion

         static void Main()
         {
             CustomJoins app = new CustomJoins();
             app.CrossJoin();
             app.NonEquijoin();

             Console.WriteLine("Press any key to exit.");
             Console.ReadKey();
         }

         void CrossJoin()
         {
             var crossJoinQuery =
                 from c in categories
                 from p in products
                 select new { c.ID, p.Name };

             Console.WriteLine("Cross Join Query:");
             foreach (var v in crossJoinQuery)
             {
                 Console.WriteLine($"{v.ID:-5}{v.Name}");
             }
         }

         void NonEquijoin()
         {
             var nonEquijoinQuery =
                 from p in products
                 let catIds = from c in categories
                              select c.ID
                 where catIds.Contains(p.CategoryID) == true
                 select new { Product = p.Name, CategoryID = p.CategoryID };

             Console.WriteLine("Non-equijoin query:");
             foreach (var v in nonEquijoinQuery)
             {
                 Console.WriteLine($"{v.CategoryID:-5}{v.Product}");
             }
         }
     }
     /* Output:
 Cross Join Query:
 1    Tea
 1    Mustard
 1    Pickles
 1    Carrots
 1    Bok Choy
 1    Peaches
 1    Melons
 1    Ice Cream
 1    Mackerel
 2    Tea
 2    Mustard
 2    Pickles
 2    Carrots
 2    Bok Choy
 2    Peaches
 2    Melons
 2    Ice Cream
 2    Mackerel
 3    Tea
 3    Mustard
 3    Pickles
 3    Carrots
 3    Bok Choy
 3    Peaches
 3    Melons
 3    Ice Cream
 3    Mackerel
 Non-equijoin query:
 1    Tea
 2    Mustard
 2    Pickles
 3    Carrots
 3    Bok Choy
 Press any key to exit.
      */
```

#### 示例

在下面的示例中，查询必须基于匹配键（对于内部（右侧）序列，无法在 join 子句本身之前获取这些键）联接两个序列。 如果使用 `join` 子句执行了此联接，则必须为每个元素调用 `Split` 方法。 使用多个 `from` 子句可使查询避免重复进行方法调用的开销。 但是，因为 `join` 经过了优化，所有在此特定情况下，它可能仍然比使用多个 `from` 子句更快。 结果的变化主要取决于方法调用的成本高低。

```csharp
class MergeTwoCSVFiles
{
    static void Main()
    {
        // See section Compiling the Code for information about the data files.
        string[] names = System.IO.File.ReadAllLines(@"../../../names.csv");
        string[] scores = System.IO.File.ReadAllLines(@"../../../scores.csv");

        // Merge the data sources using a named type.
        // You could use var instead of an explicit type for the query.
        IEnumerable<Student> queryNamesScores =
            // Split each line in the data files into an array of strings.
            from name in names
            let x = name.Split(',')
            from score in scores
            let s = score.Split(',')
            // Look for matching IDs from the two data files.
            where x[2] == s[0]
            // If the IDs match, build a Student object.
            select new Student()
            {
                FirstName = x[0],
                LastName = x[1],
                ID = Convert.ToInt32(x[2]),
                ExamScores = (from scoreAsText in s.Skip(1)
                              select Convert.ToInt32(scoreAsText)).
                              ToList()
            };

        // Optional. Store the newly created student objects in memory
        // for faster access in future queries
        List<Student> students = queryNamesScores.ToList();

        foreach (var student in students)
        {
            Console.WriteLine($"The average score of {student.FirstName} {student.LastName} is 
                {student.ExamScores.Average()}.");
        }

        //Keep console window open in debug mode
        Console.WriteLine("Press any key to exit.");
        Console.ReadKey();
    }
}

class Student
{
    public string FirstName { get; set; }
    public string LastName { get; set; }
    public int ID { get; set; }
    public List<int> ExamScores { get; set; }
}

/* Output: 
    The average score of Omelchenko Svetlana is 82.5.
    The average score of O'Donnell Claire is 72.25.
    The average score of Mortensen Sven is 84.5.
    The average score of Garcia Cesar is 88.25.
    The average score of Garcia Debra is 67.
    The average score of Fakhouri Fadi is 92.25.
    The average score of Feng Hanying is 88.
    The average score of Garcia Hugo is 85.75.
    The average score of Tucker Lance is 81.75.
    The average score of Adams Terry is 85.25.
    The average score of Zabokritski Eugene is 83.
    The average score of Tucker Michael is 92.
 */
```

### [Handle null values in query expressions](https://docs.microsoft.com/en-us/dotnet/csharp/linq/handle-null-values-in-query-expressions)

此示例显示如何在源集合中处理可能的 null 值。 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 等对象集合可包含值为 [null](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/null) 的元素。 如果源集合为 null 或包含值为 null 的元素，并且查询不处理 null 值，则在执行查询时将引发 [NullReferenceException](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullreferenceexception)。

#### 示例

可采用防御方式进行编码，以避免空引用异常，如以下示例所示：

```csharp
var query1 =
    from c in categories
    where c != null
    join p in products on c.ID equals
        p?.CategoryID
    select new { Category = c.Name, Name = p.Name };
```

在前面的示例中，`where` 子句筛选出类别序列中的所有 null 元素。 此方法独立于 join 子句中的 null 检查。 在此示例中，带有 null 的条件表达式有效，因为 `Products.CategoryID` 的类型为 `int?`，这是 `Nullable<int>` 的速记形式。

#### 示例

在 join 子句中，如果只有一个比较键是可以为 null 的类型，则可以在查询表达式中将另一个比较键转换为可以为 null 的类型。 在以下示例中，假定 `EmployeeID` 是包含 `int?` 类型的值列：

```csharp
void TestMethod(Northwind db)
{
    var query =
        from o in db.Orders
        join e in db.Employees
            on o.EmployeeID equals (int?)e.EmployeeID
        select new { o.OrderID, e.FirstName };
}
```

### [Handle exceptions in query expressions](https://docs.microsoft.com/en-us/dotnet/csharp/linq/handle-exceptions-in-query-expressions)

在查询表达式的上下文中可以调用任何方法。 但是，我们建议避免在查询表达式中调用任何会产生副作用（如修改数据源内容或引发异常）的方法。 此示例演示在查询表达式中调用方法时如何避免引发异常，而不违反有关异常处理的常规 .NET 指南。 这些指南阐明，当你理解在给定上下文中为何会引发异常时，捕获到该特定异常是可以接受的。 有关详细信息，请参阅[异常的最佳做法](https://docs.microsoft.com/zh-cn/dotnet/standard/exceptions/best-practices-for-exceptions)。

最后的示例演示了在执行查询期间必须引发异常时，该如何处理这种情况。

#### 示例

以下示例演示如何将异常处理代码移到查询表达式外。 只有当方法不取决于查询的任何本地变量时，才可以执行此操作。

```csharp
class ExceptionsOutsideQuery
{
    static void Main()
    {
        // DO THIS with a datasource that might
        // throw an exception. It is easier to deal with
        // outside of the query expression.
        IEnumerable<int> dataSource;
        try
        {
            dataSource = GetData();
        }
        catch (InvalidOperationException)
        {
            // Handle (or don't handle) the exception 
            // in the way that is appropriate for your application.
            Console.WriteLine("Invalid operation");
            goto Exit;
        }
        
        // If we get here, it is safe to proceed.
        var query = from i in dataSource
                    select i * i;

        foreach (var i in query)
            Console.WriteLine(i.ToString());

        //Keep the console window open in debug mode
        Exit:
        Console.WriteLine("Press any key to exit");
        Console.ReadKey();
    }

    // A data source that is very likely to throw an exception!
    static IEnumerable<int> GetData()
    {
        throw new InvalidOperationException();
    }
}
```

#### 示例

在某些情况下，针对由查询内部引发的异常的最佳措施可能是立即停止执行查询。 下面的示例演示如何处理可能在查询正文内部引发的异常。 假定 `SomeMethodThatMightThrow` 可能导致要求停止执行查询的异常。

请注意，`try` 块封装 `foreach` 循环，且不对自身进行查询。 这是由于 `foreach` 循环正是实际执行查询时的点。 有关详细信息，请参阅 [LINQ 查询简介](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/introduction-to-linq-queries)。

```csharp
class QueryThatThrows
{
    static void Main()
    {
        // Data source.
        string[] files = { "fileA.txt", "fileB.txt", "fileC.txt" };

        // Demonstration query that throws.
        var exceptionDemoQuery =
            from file in files
            let n = SomeMethodThatMightThrow(file)
            select n;

        // Runtime exceptions are thrown when query is executed.
        // Therefore they must be handled in the foreach loop.
        try
        {
            foreach (var item in exceptionDemoQuery)
            {
                Console.WriteLine($"Processing {item}");
            }
        }

        // Catch whatever exception you expect to raise
        // and/or do any necessary cleanup in a finally block
        catch (InvalidOperationException e)
        {
            Console.WriteLine(e.Message);
        }

        //Keep the console window open in debug mode
        Console.WriteLine("Press any key to exit");
        Console.ReadKey();
    }

    // Not very useful as a general purpose method.
    static string SomeMethodThatMightThrow(string s)
    {
        if (s[4] == 'C')
            throw new InvalidOperationException();
        return @"C:\newFolder\" + s;
    }
}
/* Output:
    Processing C:\newFolder\fileA.txt
    Processing C:\newFolder\fileB.txt
    Operation is not valid due to the current state of the object.
 */
```