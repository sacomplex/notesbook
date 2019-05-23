# [Standard Query Operators Overview](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/standardqueryoperatorsoverview)

*标准查询运算符*是组成 LINQ 模式的方法。 这些方法中的大多数都作用于序列；其中序列指其类型实现 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 接口或 [IQueryable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.iqueryable-1) 接口的对象。 标准查询运算符提供包括筛选、投影、聚合、排序等在内的查询功能。

共有两组 LINQ 标准查询运算符，一组作用于类型 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的对象，另一组作用于类型 [IQueryable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.iqueryable-1) 的对象。 构成每个集合的方法分别是 [Enumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable) 和 [Queryable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable) 类的静态成员。 这些方法被定义为作为方法运行目标的类型的*扩展方法*。 这意味着可以使用静态方法语法或实例方法语法来调用它们。

此外，多个标准查询运算符方法作用于那些基于 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 或 [IQueryable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.iqueryable-1) 的类型外的类型。[Enumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable) 类型定义了两种这样的方法，这两种方法都作用于类型 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable) 的对象。 这些方法（[Cast(IEnumerable)](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.cast#System_Linq_Enumerable_Cast__1_System_Collections_IEnumerable_) 和 [OfType(IEnumerable)](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.oftype#System_Linq_Enumerable_OfType__1_System_Collections_IEnumerable_)）均允许在 LINQ 模式中查询非参数化或非泛型集合。 这些方法通过创建一个强类型的对象集合来实现这一点。 [Queryable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable) 类定义了两种类似的方法 [Cast(IQueryable)](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.cast#System_Linq_Queryable_Cast__1_System_Linq_IQueryable_) 和 [OfType(IQueryable)](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.oftype#System_Linq_Queryable_OfType__1_System_Linq_IQueryable_)，这两种方法都作用于类型 [Queryable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable) 的对象。

各个标准查询运算符在执行时间上有所不同，具体情况取决于它们是返回单一值还是值序列。 返回单一实例值的这些方法（例如 [Average](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.average) 和 [Sum](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.sum)）立即执行。 返回序列的方法会延迟查询执行，并返回一个可枚举的对象。

对于在内存中集合上运行的方法（即扩展 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的那些方法），返回的可枚举对象将捕获传递到方法的参数。 在枚举该对象时，将使用查询运算符的逻辑，并返回查询结果。

与之相反，扩展 [IQueryable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.iqueryable-1) 的方法不会实现任何查询行为，但会生成一个表示要执行的查询的表达式树。 源 [IQueryable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.iqueryable-1) 对象执行查询处理。

可以在一个查询中将对查询方法的调用链接在一起，这就使得查询的复杂性可能会变得不确定。

下面的代码示例演示如何使用标准查询运算符来获取有关序列的信息。

```csharp
string sentence = "the quick brown fox jumps over the lazy dog";  
// Split the string into individual words to create a collection.  
string[] words = sentence.Split(' ');  
  
// Using query expression syntax.  
var query = from word in words  
            group word.ToUpper() by word.Length into gr  
            orderby gr.Key  
            select new { Length = gr.Key, Words = gr };  
  
// Using method-based query syntax.  
var query2 = words.  
    GroupBy(w => w.Length, w => w.ToUpper()).  
    Select(g => new { Length = g.Key, Words = g }).  
    OrderBy(o => o.Length);  
  
foreach (var obj in query)  
{  
    Console.WriteLine("Words of length {0}:", obj.Length);  
    foreach (string word in obj.Words)  
        Console.WriteLine(word);  
}  
  
// This code example produces the following output:  
//  
// Words of length 3:  
// THE  
// FOX  
// THE  
// DOG  
// Words of length 4:  
// OVER  
// LAZY  
// Words of length 5:  
// QUICK  
// BROWN  
// JUMPS   
```

## 查询表达式语法

某些使用更频繁的标准查询运算符具有专用的 C# 和 Visual Basic 语言关键字语法，使用这些语法可以在*查询**表达式*中调用这些运算符。 有关具有专用关键字及其对应语法的标准查询运算符的详细信息，请参阅[标准查询运算符的查询表达式语法 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/query-expression-syntax-for-standard-query-operators)。

## 扩展标准查询运算符

通过创建适合于目标域或技术的特定于域的方法，可以增大标准查询运算符的集合。 也可以用自己的实现来替换标准查询运算符，这些实现提供诸如远程计算、查询转换和优化之类的附加服务。 有关示例，请参见 [AsEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.asenumerable)。

## 相关章节

通过以下链接可转到一些主题，这些主题基于功能提供有关各种标准查询运算符的附加信息。

[对数据进行排序 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sorting-data)

[集运算 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/set-operations)

[筛选数据 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/filtering-data)

[限定符运算 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/quantifier-operations)

[投影运算 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/projection-operations)

[数据分区 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/partitioning-data)

[联接运算 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/join-operations)

[数据分组 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/grouping-data)

[生成运算 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/generation-operations)

[相等运算 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/equality-operations)

[元素运算 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/element-operations)

[转换数据类型 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/converting-data-types)

[串联运算 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/concatenation-operations)

[聚合运算 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/aggregation-operations)

## [Query Expression Syntax for Standard Query Operators](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/queryexpressionsyntaxforstandardqueryoperators)

某些使用更频繁的标准查询运算符具有专用的 C# 语言关键字语法，使用这些语法可以在查询表达式中调用这些运算符。 查询表达式是比基于方法的等效项更具可读性的另一种查询表示形式。 查询表达式子句在编译时被转换为对查询方法的调用。

列出包含等效查询表达式子句的标准查询运算符。

- [Cast](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.cast)
  - 使用显式类型化范围变量
  - 例如
    - `from int i in numbers`
  - 有关详细信息，请参阅 [from 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/from-clause)。
- [GroupBy](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.groupby)
  - `group … by`或`group … by … into …`
  - 有关详细信息，请参阅 [group 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/group-clause)。
- [GroupJoin<TOuter,TInner,TKey,TResult>(IEnumerable<TOuter>, IEnumerable<TInner>, Func<TOuter,TKey>, Func<TInner,TKey>, Func<TOuter,IEnumerable<TInner>,TResult>)](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.groupjoin#System_Linq_Enumerable_GroupJoin__4_System_Collections_Generic_IEnumerable___0__System_Collections_Generic_IEnumerable___1__System_Func___0___2__System_Func___1___2__System_Func___0_System_Collections_Generic_IEnumerable___1____3__)
  - `join … in … on … equals … into …`
  - 有关详细信息，请参阅 [join 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/join-clause)。
- [Join<TOuter,TInner,TKey,TResult>(IEnumerable<TOuter>, IEnumerable<TInner>, Func<TOuter,TKey>, Func<TInner,TKey>, Func<TOuter,TInner,TResult>)](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.join#System_Linq_Enumerable_Join__4_System_Collections_Generic_IEnumerable___0__System_Collections_Generic_IEnumerable___1__System_Func___0___2__System_Func___1___2__System_Func___0___1___3__)
  - `join … in … on … equals …`
  - 有关详细信息，请参阅 [join 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/join-clause)。
- [OrderBy<TSource,TKey>(IEnumerable<TSource>, Func<TSource,TKey>)](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.orderby#System_Linq_Enumerable_OrderBy__2_System_Collections_Generic_IEnumerable___0__System_Func___0___1__)
  - orderby
  - 有关详细信息，请参阅 [orderby 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/orderby-clause)。
- [OrderByDescending<TSource,TKey>(IEnumerable<TSource>, Func<TSource,TKey>)](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.orderbydescending#System_Linq_Enumerable_OrderByDescending__2_System_Collections_Generic_IEnumerable___0__System_Func___0___1__)
  - `orderby … descending`
  - 有关详细信息，请参阅 [orderby 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/orderby-clause)。
- [Select](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.select)
  - `select`
  - 有关详细信息，请参阅 [let 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/select-clause)
- [SelectMany](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.selectmany)
  - 多个 `from` 子句
  - 有关详细信息，请参阅 [from 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/from-clause)
- [ThenBy<TSource,TKey>(IOrderedEnumerable<TSource>, Func<TSource,TKey>)](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.thenby#System_Linq_Enumerable_ThenBy__2_System_Linq_IOrderedEnumerable___0__System_Func___0___1__)
  - `orderby …, …`
  - 有关详细信息，请参阅 [orderby 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/orderby-clause)。
- [ThenByDescending<TSource,TKey>(IOrderedEnumerable<TSource>, Func<TSource,TKey>)](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.thenbydescending#System_Linq_Enumerable_ThenByDescending__2_System_Linq_IOrderedEnumerable___0__System_Func___0___1__)
  - orderby …, … descending
  - 有关详细信息，请参阅 [orderby 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/orderby-clause)

## [Classification of Standard Query Operators by Manner of Execution](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/classificationofstandardqueryoperatorsbymannerofexecution)

标准查询运算符方法的 LINQ to Objects 实现主要通过两种方法之一执行：立即执行和延迟执行。 使用延迟执行的查询运算符可以进一步分为两种类别：流式处理和非流式处理。 如果你了解不同查询运算符的执行方式，则有助于理解从给定查询中获得的结果。 如果数据源是不断变化的，或者如果你要在另一个查询的基础上构建查询，这种帮助尤其明显。 本主题根据标准查询运算符的执行方式对其进行分类。

### 执行方式

#### 即时

立即执行指的是在代码中声明查询的位置读取数据源并执行运算。 返回单个不可枚举的结果的所有标准查询运算符都立即执行。

#### 推迟

延迟执行指的是不在代码中声明查询的位置执行运算。 仅当对查询变量进行枚举时才执行运算，例如通过使用 `foreach` 语句执行。 这意味着，查询的执行结果取决于执行查询而非定义查询时的数据源内容。 如果多次枚举查询变量，则每次结果可能都不同。 几乎所有返回类型为 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 或 [IOrderedEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.iorderedenumerable-1) 的标准查询运算符皆以延迟方式执行。

使用延迟执行的查询运算符可以另外分类为流式处理和非流式处理。

##### 流式处理

流式处理运算符不需要在生成元素前读取所有源数据。 在执行时，流式处理运算符一边读取每个源元素，一边对该源元素执行运算，并在可行时生成元素。 流式处理运算符将持续读取源元素直到可以生成结果元素。 这意味着可能要读取多个源元素才能生成一个结果元素。

##### 非流式处理

非流式处理运算符必须先读取所有源数据，然后才能生成结果元素。 排序或分组等运算均属于此类别。 在执行时，非流式处理查询运算符将读取所有源数据，将其放入数据结构，执行运算，然后生成结果元素。

### 分类表

下表按照执行方法对每个标准查询运算符方法进行了分类。

> 如果某个运算符被标入两个列中，则表示在运算中涉及两个输入序列，每个序列的计算方式不同。 在此类情况下，参数列表中的第一个序列始终以延迟流式处理方式来执行计算。

| 标准查询运算符                                               | 返回类型                                                     | 立即执行 | 延迟的流式处理执行 | 延迟非流式处理执行 |
| ------------------------------------------------------------ | ------------------------------------------------------------ | -------- | ------------------ | ------------------ |
| [Aggregate](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.aggregate) | TSource                                                      | X        |                    |                    |
| [All](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.all) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | X        |                    |                    |
| [Any](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.any) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | X        |                    |                    |
| [AsEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.asenumerable) | [IEnumerable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) |          | X                  |                    |
| [Average](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.average) | 单个数值                                                     | X        |                    |                    |
| [Cast](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.cast) | [IEnumerable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) |          | X                  |                    |
| [Concat](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.concat) | [IEnumerable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) |          | X                  |                    |
| [Contains](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.contains) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | X        |                    |                    |
| [Count](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.count) | [Int32](https://docs.microsoft.com/zh-cn/dotnet/api/system.int32) | X        |                    |                    |
| [DefaultIfEmpty](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.defaultifempty) | [IEnumerable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) |          | X                  |                    |
| [Distinct](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.distinct) | [IEnumerable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) |          | X                  |                    |
| [ElementAt](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.elementat) | TSource                                                      | X        |                    |                    |
| [ElementAtOrDefault](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.elementatordefault) | TSource                                                      | X        |                    |                    |
| [Empty](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.empty) | [IEnumerable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) | X        |                    |                    |
| [Except](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.except) | [IEnumerable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) |          | X                  | X                  |
| [First](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.first) | TSource                                                      | X        |                    |                    |
| [FirstOrDefault](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.firstordefault) | TSource                                                      | X        |                    |                    |
| [GroupBy](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.groupby) | [IEnumerable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) |          |                    | X                  |
| [GroupJoin](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.groupjoin) | [IEnumerable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) |          | X                  | X                  |
| [Intersect](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.intersect) | [IEnumerable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) |          | X                  | X                  |
| [Join](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.join) | [IEnumerable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) |          | X                  | X                  |
| [Last](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.last) | TSource                                                      | X        |                    |                    |
| [LastOrDefault](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.lastordefault) | TSource                                                      | X        |                    |                    |
| [LongCount](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.longcount) | [Int64](https://docs.microsoft.com/zh-cn/dotnet/api/system.int64) | X        |                    |                    |
| [Max](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.max) | 单个数值、TSource 或 TResult                                 | X        |                    |                    |
| [Min](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.min) | 单个数值、TSource 或 TResult                                 | X        |                    |                    |
| [OfType](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.oftype) | [IEnumerable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) |          | X                  |                    |
| [OrderBy](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.orderby) | [IOrderedEnumerable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.iorderedenumerable-1) |          |                    | X                  |
| [OrderByDescending](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.orderbydescending) | [IOrderedEnumerable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.iorderedenumerable-1) |          |                    | X                  |
| [Range](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.range) | [IEnumerable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) |          | X                  |                    |
| [Repeat](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.repeat) | [IEnumerable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) |          | X                  |                    |
| [Reverse](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.reverse) | [IEnumerable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) |          |                    | X                  |
| [Select](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.select) | [IEnumerable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) |          | X                  |                    |
| [SelectMany](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.selectmany) | [IEnumerable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) |          | X                  |                    |
| [SequenceEqual](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.sequenceequal) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) | X        |                    |                    |
| [Single](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.single) | TSource                                                      | X        |                    |                    |
| [SingleOrDefault](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.singleordefault) | TSource                                                      | X        |                    |                    |
| [Skip](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.skip) | [IEnumerable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) |          | X                  |                    |
| [SkipWhile](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.skipwhile) | [IEnumerable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) |          | X                  |                    |
| [Sum](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.sum) | 单个数值                                                     | X        |                    |                    |
| [Take](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.take) | [IEnumerable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) |          | X                  |                    |
| [TakeWhile](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.takewhile) | [IEnumerable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) |          | X                  |                    |
| [ThenBy](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.thenby) | [IOrderedEnumerable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.iorderedenumerable-1) |          |                    | X                  |
| [ThenByDescending](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.thenbydescending) | [IOrderedEnumerable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.iorderedenumerable-1) |          |                    | X                  |
| [ToArray](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.toarray) | TSource 数组                                                 | X        |                    |                    |
| [ToDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.todictionary) | [Dictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.dictionary-2) | X        |                    |                    |
| [ToList](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.tolist) | [IList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ilist-1) | X        |                    |                    |
| [ToLookup](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.tolookup) | [ILookup](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.ilookup-2) | X        |                    |                    |
| [Union](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.union) | [IEnumerable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) |          | X                  |                    |
| [Where](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.where) | [IEnumerable<T>](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) |          | X                  |                    |

## [Sorting Data](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/sortingdata)

排序操作基于一个或多个属性对序列的元素进行排序。 第一个排序条件对元素执行主要排序。 通过指定第二个排序条件，您可以对每个主要排序组内的元素进行排序。

下图演示对一个字符序列执行按字母排序操作的结果。

![LINQ 排序操作](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/media/linq_ordering.png)

下节列出了对数据进行排序的标准查询运算符方法。

### 方法

| 方法名            | 说明                   | C# 查询表达式语法         | 详细信息                                                     |
| ----------------- | ---------------------- | ------------------------- | ------------------------------------------------------------ |
| OrderBy           | 按升序对值排序。       | `orderby`                 | [Enumerable.OrderBy](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.orderby)  [Queryable.OrderBy](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.orderby) |
| OrderByDescending | 按降序对值排序。       | `orderby … descending`    | [Enumerable.OrderByDescending](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.orderbydescending)  [Queryable.OrderByDescending](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.orderbydescending) |
| ThenBy            | 按升序执行次要排序。   | `orderby …, …`            | [Enumerable.ThenBy](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.thenby)  [Queryable.ThenBy](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.thenby) |
| ThenByDescending  | 按降序执行次要排序。   | `orderby …, … descending` | [Enumerable.ThenByDescending](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.thenbydescending)  [Queryable.ThenByDescending](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.thenbydescending) |
| Reverse           | 反转集合中元素的顺序。 | 不适用。                  | [Enumerable.Reverse](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.reverse)  [Queryable.Reverse](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.reverse) |

### 查询表达式语法示例

#### 主要排序示例

##### 主要升序排序

下面的示例演示如何在 LINQ 查询中使用 `orderby` 子句按字符串长度对数组中的字符串进行升序排序。

```csharp
string[] words = { "the", "quick", "brown", "fox", "jumps" };  
  
IEnumerable<string> query = from word in words  
                            orderby word.Length  
                            select word;  
  
foreach (string str in query)  
    Console.WriteLine(str);  
  
/* This code produces the following output:  
  
    the  
    fox  
    quick  
    brown  
    jumps  
*/  
```

##### 主要降序排序

下面的示例演示如何在 LINQ 查询中使用 `orderby descending` 子句按字符串的第一个字母对字符串进行降序排序。

```csharp
string[] words = { "the", "quick", "brown", "fox", "jumps" };  
  
IEnumerable<string> query = from word in words  
                            orderby word.Substring(0, 1) descending  
                            select word;  
  
foreach (string str in query)  
    Console.WriteLine(str);  
  
/* This code produces the following output:  
  
    the  
    quick  
    jumps  
    fox  
    brown  
*/  
```

#### 次要排序示例

##### 次要升序排序

下面的示例演示如何在 LINQ 查询中使用 `orderby` 子句对数组中的字符串执行主要和次要排序。 首先按字符串长度，其次按字符串的第一个字母，对字符串进行升序排序。

```csharp
string[] words = { "the", "quick", "brown", "fox", "jumps" };  
  
IEnumerable<string> query = from word in words  
                            orderby word.Length, word.Substring(0, 1)  
                            select word;  
  
foreach (string str in query)  
    Console.WriteLine(str);  
  
/* This code produces the following output:  
  
    fox  
    the  
    brown  
    jumps  
    quick  
*/  
```

##### 次要降序排序

下面的示例演示如何在 LINQ 查询中使用 `orderby descending` 子句按升序执行主要排序，按降序执行次要排序。首先按字符串长度，其次按字符串的第一个字母，对字符串进行排序。

```csharp
string[] words = { "the", "quick", "brown", "fox", "jumps" };  
  
IEnumerable<string> query = from word in words  
                            orderby word.Length, word.Substring(0, 1) descending  
                            select word;  
  
foreach (string str in query)  
    Console.WriteLine(str);  
  
/* This code produces the following output:  
  
    the  
    fox  
    quick  
    jumps  
    brown  
*/  
```

## [Set Operations](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/setoperations)

LINQ 中的集运算是指根据相同或不同集合（或集）中是否存在等效元素来生成结果集的查询运算。

下节列出了执行集运算的标准查询运算符方法。

### 方法

| 方法名   | 说明                                                   | C# 查询表达式语法 | 详细信息                                                     |
| -------- | ------------------------------------------------------ | ----------------- | ------------------------------------------------------------ |
| Distinct | 删除集合中的重复值。                                   | 不适用。          | [Enumerable.Distinct](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.distinct)  [Queryable.Distinct](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.distinct) |
| Except   | 返回差集，差集指位于一个集合但不位于另一个集合的元素。 | 不适用。          | [Enumerable.Except](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.except)  [Queryable.Except](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.except) |
| 相交     | 返回交集，交集指同时出现在两个集合中的元素。           | 不适用。          | [Enumerable.Intersect](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.intersect)  [Queryable.Intersect](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.intersect) |
| 联合     | 返回并集，并集指位于两个集合中任一集合的唯一的元素。   | 不适用。          | [Enumerable.Union](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.union)  [Queryable.Union](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.union) |

### 比较集运算

#### Distinct

下图演示字符序列上 [Enumerable.Distinct](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.distinct) 方法的行为。 返回的序列包含输入序列的唯一元素。

![演示 Distinct() 的行为的图。](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/media/distinct.png)

#### Except

下图演示 [Enumerable.Except](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.except) 的行为。 返回的序列只包含位于第一个输入序列但不位于第二个输入序列的元素。

![显示 Except() 的操作的图。](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/media/except.png)

#### 相交

下图演示 [Enumerable.Intersect](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.intersect) 的行为。 返回的序列包含两个输入序列共有的元素。

![显示两个序列的交集的图。](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/media/intersect.png)

#### 联合

下图演示对两个字符序列执行的联合操作。 返回的序列包含两个输入序列的唯一元素。

![显示两个序列的联合的图。](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/media/union.png)

## [Filtering Data](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/filteringdata)

筛选是指将结果集限制为仅包含满足指定条件的元素的操作。 它也称为选定内容。

下图演示了对字符序列进行筛选的结果。 筛选操作的谓词指定字符必须为“A”。

![LINQ 筛选操作](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/media/linq_filter.png)

下面一节列出了执行所选内容的标准查询运算符方法。

### 方法

| 方法名 | 说明                               | C# 查询表达式语法 | 详细信息                                                     |
| ------ | ---------------------------------- | ----------------- | ------------------------------------------------------------ |
| OfType | 根据其转换为特定类型的能力选择值。 | 不适用。          | [Enumerable.OfType](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.oftype)  [Queryable.OfType](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.oftype) |
| Where  | 选择基于谓词函数的值。             | `where`           | [Enumerable.Where](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.where)  [Queryable.Where](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.where) |

### 查询表达式语法示例

以下示例使用 `where` 子句从数组中筛选具有特定长度的字符串。

```csharp
string[] words = { "the", "quick", "brown", "fox", "jumps" };  
  
IEnumerable<string> query = from word in words  
                            where word.Length == 3  
                            select word;  
  
foreach (string str in query)  
    Console.WriteLine(str);  
  
/* This code produces the following output:  
  
    the  
    fox  
*/  
```

## [Quantifier Operations](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/quantifieroperations)

限定符运算返回一个 [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) 值，该值指示序列中是否有一些元素满足条件或是否所有元素都满足条件。

下图描述了两个不同源序列上的两个不同限定符运算。 第一个运算询问是否有一个或多个元素为字符“A”，结果为 `true`。 第二个运算询问是否所有元素都为字符“A”，结果为 `true`。

![LINQ 限定符运算](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/media/linq_quantifier.png)

下节列出了执行限定符运算的标准查询运算符方法。

### 方法

| 方法名 | 说明                                 | C# 查询表达式语法 | 详细信息                                                     |
| ------ | ------------------------------------ | ----------------- | ------------------------------------------------------------ |
| 全部   | 确定是否序列中的所有元素都满足条件。 | 不适用。          | [Enumerable.All](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.all)  [Queryable.All](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.all) |
| 任意   | 确定序列中是否有元素满足条件。       | 不适用。          | [Enumerable.Any](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.any)  [Queryable.Any](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.any) |
| 包含   | 确定序列是否包含指定的元素。         | 不适用。          | [Enumerable.Contains](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.contains)  [Queryable.Contains](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.contains) |

##  [Projection Operations](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/projectionoperations)

投影是指将对象转换为一种新形式的操作，该形式通常只包含那些将随后使用的属性。 通过使用投影，您可以构造从每个对象生成的新类型。 可以投影属性，并对该属性执行数学函数。 还可以在不更改原始对象的情况下投影该对象。

下面一节列出了执行投影的标准查询运算符方法。

### 方法

| 方法名     | 说明                                                 | C# 查询表达式语法    | 详细信息                                                     |
| ---------- | ---------------------------------------------------- | -------------------- | ------------------------------------------------------------ |
| 选择       | 投影基于转换函数的值。                               | `select`             | [Enumerable.Select](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.select)  [Queryable.Select](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.select) |
| SelectMany | 投影基于转换函数的值序列，然后将它们展平为一个序列。 | 使用多个 `from` 子句 | [Enumerable.SelectMany](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.selectmany)  [Queryable.SelectMany](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.selectmany) |

### 查询表达式语法示例

#### 选择

下面的示例使用 `select` 子句来投影字符串列表中每个字符串的第一个字母。

```csharp
List<string> words = new List<string>() { "an", "apple", "a", "day" };  
  
var query = from word in words  
            select word.Substring(0, 1);  
  
foreach (string s in query)  
    Console.WriteLine(s);  
  
/* This code produces the following output:  
  
    a  
    a  
    a  
    d  
*/  
```

#### SelectMany

下面的示例使用多个 `from` 子句来投影字符串列表中每个字符串中的每个单词。

```csharp
List<string> phrases = new List<string>() { "an apple a day", "the quick brown fox" };  
  
var query = from phrase in phrases  
            from word in phrase.Split(' ')  
            select word;  
  
foreach (string s in query)  
    Console.WriteLine(s);  
  
/* This code produces the following output:  
  
    an  
    apple  
    a  
    day  
    the  
    quick  
    brown  
    fox  
*/  
```

### Select 与 SelectMany

`Select()` 和 `SelectMany()` 的工作都是依据源值生成一个或多个结果值。 `Select()` 为每个源值生成一个结果值。 因此，总体结果是一个与源集合具有相同元素数目的集合。 与之相反，`SelectMany()` 生成单个总体结果，其中包含来自每个源值的串联子集合。 作为参数传递到 `SelectMany()` 的转换函数必须为每个源值返回一个可枚举值序列。 然后，`SelectMany()` 串联这些可枚举序列，以创建一个大的序列。

下面两个插图演示了这两个方法的操作之间的概念性区别。 在每种情况下，假定选择器（转换）函数从每个源值中选择一个由花卉数据组成的数组。

下图描述 `Select()` 如何返回一个与源集合具有相同元素数目的集合。

![Select() 的操作的概念图](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/media/selectaction.png)

下图描述 `SelectMany()` 如何将中间数组序列串联为一个最终结果值，其中包含每个中间数组中的每个值。

![显示 SelectMany() 的操作的图。](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/media/selectmany.png)

#### 代码示例

下面的示例比较 `Select()` 和 `SelectMany()` 的行为。 代码通过从源集合的每个花卉名称列表中提取前两项来创建一个“花束”。 此示例中，transform 函数 [Select(IEnumerable, Func)](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.select#System_Linq_Enumerable_Select__2_System_Collections_Generic_IEnumerable___0__System_Func___0___1__) 使用的“单值”本身即是值的集合。 这需要额外的 `foreach` 循环，以便枚举每个子序列中的每个字符串。

```csharp
class Bouquet  
{  
    public List<string> Flowers { get; set; }  
}  
  
static void SelectVsSelectMany()  
{  
    List<Bouquet> bouquets = new List<Bouquet>() {  
        new Bouquet { Flowers = new List<string> { "sunflower", "daisy", "daffodil", "larkspur" }},  
        new Bouquet{ Flowers = new List<string> { "tulip", "rose", "orchid" }},  
        new Bouquet{ Flowers = new List<string> { "gladiolis", "lily", "snapdragon", "aster", "protea" }},  
        new Bouquet{ Flowers = new List<string> { "larkspur", "lilac", "iris", "dahlia" }}  
    };  
  
    // *********** Select ***********              
    IEnumerable<List<string>> query1 = bouquets.Select(bq => bq.Flowers);  
  
    // ********* SelectMany *********  
    IEnumerable<string> query2 = bouquets.SelectMany(bq => bq.Flowers);  
  
    Console.WriteLine("Results by using Select():");  
    // Note the extra foreach loop here.  
    foreach (IEnumerable<String> collection in query1)  
        foreach (string item in collection)  
            Console.WriteLine(item);  
  
    Console.WriteLine("\nResults by using SelectMany():");  
    foreach (string item in query2)  
        Console.WriteLine(item);  
  
    /* This code produces the following output:  
  
       Results by using Select():  
        sunflower  
        daisy  
        daffodil  
        larkspur  
        tulip  
        rose  
        orchid  
        gladiolis  
        lily  
        snapdragon  
        aster  
        protea  
        larkspur  
        lilac  
        iris  
        dahlia  
  
       Results by using SelectMany():  
        sunflower  
        daisy  
        daffodil  
        larkspur  
        tulip  
        rose  
        orchid  
        gladiolis  
        lily  
        snapdragon  
        aster  
        protea  
        larkspur  
        lilac  
        iris  
        dahlia  
    */  
  
}  
```

## [Partitioning Data](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/partitioningdata)

LINQ 中的分区是指将输入序列划分为两个部分的操作，无需重新排列元素，然后返回其中一个部分。

下图显示对字符序列进行三种不同的分区操作的结果。 第一个操作返回序列中的前三个元素。 第二个操作跳过前三个元素，返回剩余元素。 第三个操作跳过序列中的前两个元素，返回接下来的三个元素。

![LINQ 分区操作](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/media/linq_partition.png)

下面一节列出了对序列进行分区的标准查询运算符方法。

### 运算符

| 运算符名称 | 说明                                       | C# 查询表达式语法 | 详细信息                                                     |
| ---------- | ------------------------------------------ | ----------------- | ------------------------------------------------------------ |
| Skip       | 跳过序列中指定位置之前的元素。             | 不适用。          | [Enumerable.Skip](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.skip)  [Queryable.Skip](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.skip) |
| SkipWhile  | 基于谓词函数跳过元素，直到元素不符合条件。 | 不适用。          | [Enumerable.SkipWhile](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.skipwhile)  [Queryable.SkipWhile](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.skipwhile) |
| Take       | 获取序列中指定位置之前的元素。             | 不适用。          | [Enumerable.Take](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.take)  [Queryable.Take](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.take) |
| TakeWhile  | 基于谓词函数获取元素，直到元素不符合条件。 | 不适用。          | [Enumerable.TakeWhile](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.takewhile)  [Queryable.TakeWhile](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.takewhile) |

## [Join Operations](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/joinoperations)

联接两个数据源就是将一个数据源中的对象与另一个数据源中具有相同公共属性的对象相关联。

当查询所面向的数据源相互之间具有无法直接领会的关系时，联接就成为一项重要的运算。 在面向对象的编程中，这可能意味着在未建模对象之间进行关联，例如对单向关系进行反向推理。 下面是单向关系的一个示例：Customer 类有一个类型为 City 的属性，但 City 类没有作为 Customer 对象集合的属性。 如果你具有一个 City 对象列表，并且要查找每个城市中的所有客户，则可以使用联接运算完成此项查找。

LINQ 框架中提供的 join 方法包括 [Join](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.join) 和 [GroupJoin](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.groupjoin)。 这些方法执行同等联接，即根据 2 个数据源的键是否相等来匹配这 2 个数据源的联接。 （与此相较，Transact-SQL 支持除“等于”之外的联接运算符，例如“小于”运算符。）用关系数据库术语表达，就是说 [Join](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.join) 实现了内部联接，这种联接只返回那些在另一个数据集中具有匹配项的对象。 [GroupJoin](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.groupjoin) 方法在关系数据库术语中没有直接等效项，但实现了内部联接和左外部联接的超集。 左外部联接是指返回第一个（左侧）数据源的每个元素的联接，即使其他数据源中没有关联元素。

下图显示了一个概念性视图，其中包含两个集合以及这两个集合中的包含在内部联接或左外部联接中的元素。

![显示内部/外部的两个重叠圆圈。](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/media/joincircles.png)

### 方法

| 方法名    | 说明                                                         | C# 查询表达式语法                  | 详细信息                                                     |
| --------- | ------------------------------------------------------------ | ---------------------------------- | ------------------------------------------------------------ |
| 联接      | 根据键选择器函数联接两个序列并提取值对。                     | `join … in … on … equals …`        | [Enumerable.Join](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.join)  [Queryable.Join](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.join) |
| GroupJoin | 根据键选择器函数联接两个序列，并对每个元素的结果匹配项进行分组。 | `join … in … on … equals … into …` | [Enumerable.GroupJoin](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.groupjoin)  [Queryable.GroupJoin](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.groupjoin) |

## [Grouping Data](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/groupingdata)

分组是指将数据分到不同的组，使每组中的元素拥有公共的属性。

下图演示了对字符序列进行分组的结果。 每个组的键是字符。

![LINQ 分组操作](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/media/linq_group.png)

下一节列出了对数据元素进行分组的标准查询运算符方法。

### 方法

| 方法名   | 说明                                                         | C# 查询表达式语法                       | 详细信息                                                     |
| -------- | ------------------------------------------------------------ | --------------------------------------- | ------------------------------------------------------------ |
| GroupBy  | 对共享通用属性的元素进行分组。 每组由一个 [IGrouping](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.igrouping-2) 对象表示。 | `group … by`  或  `group … by … into …` | [Enumerable.GroupBy](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.groupby)  [Queryable.GroupBy](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.groupby) |
| ToLookup | 将元素插入基于键选择器函数的 [Lookup](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.lookup-2)（一种一对多字典）。 | 不适用。                                | [Enumerable.ToLookup](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.tolookup) |

### 查询表达式语法示例

下列代码示例根据奇偶性，使用 `group by` 子句对列表中的整数进行分组。

```csharp
List<int> numbers = new List<int>() { 35, 44, 200, 84, 3987, 4, 199, 329, 446, 208 };  
  
IEnumerable<IGrouping<int, int>> query = from number in numbers  
                                         group number by number % 2;  
  
foreach (var group in query)  
{  
    Console.WriteLine(group.Key == 0 ? "\nEven numbers:" : "\nOdd numbers:");  
    foreach (int i in group)  
        Console.WriteLine(i);  
}  
  
/* This code produces the following output:  
  
    Odd numbers:  
    35  
    3987  
    199  
    329  
  
    Even numbers:  
    44  
    200  
    84  
    4  
    446  
    208  
*/  
```

## [Generation Operations](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/generationoperations)

生成是指创建新的值序列。

下面一节列出了执行生成的标准查询运算符方法。

### 方法

| 方法名         | 说明                             | C# 查询表达式语法 | 详细信息                                                     |
| -------------- | -------------------------------- | ----------------- | ------------------------------------------------------------ |
| DefaultIfEmpty | 用默认值单一实例集合替换空集合。 | 不适用。          | [Enumerable.DefaultIfEmpty](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.defaultifempty)  [Queryable.DefaultIfEmpty](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.defaultifempty) |
| 空             | 返回一个空集合。                 | 不适用。          | [Enumerable.Empty](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.empty) |
| 范围           | 生成包含数字序列的集合。         | 不适用。          | [Enumerable.Range](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.range) |
| Repeat         | 生成包含一个重复值的集合。       | 不适用。          | [Enumerable.Repeat](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.repeat) |

## [Equality Operations](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/equalityoperations)

两个序列，其相应元素相等且具有被视为相等的相同数量的元素。

### 方法

| 方法名        | 说明                                         | C# 查询表达式语法 | 更多信息                                                     |
| ------------- | -------------------------------------------- | ----------------- | ------------------------------------------------------------ |
| SequenceEqual | 通过以成对方式比较元素确定两个序列是否相等。 | 不适用。          | [Enumerable.SequenceEqual](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.sequenceequal)  [Queryable.SequenceEqual](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.sequenceequal) |

## [Element Operations](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/elementoperations)

元素运算从序列中返回唯一、特定的元素。

下节列出了执行元素运算的标准查询运算符方法。

### 方法

| 方法名             | 说明                                                         | C# 查询表达式语法 | 详细信息                                                     |
| ------------------ | ------------------------------------------------------------ | ----------------- | ------------------------------------------------------------ |
| ElementAt          | 返回集合中指定索引处的元素。                                 | 不适用。          | [Enumerable.ElementAt](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.elementat)  [Queryable.ElementAt](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.elementat) |
| ElementAtOrDefault | 返回集合中指定索引处的元素；如果索引超出范围，则返回默认值。 | 不适用。          | [Enumerable.ElementAtOrDefault](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.elementatordefault)  [Queryable.ElementAtOrDefault](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.elementatordefault) |
| First              | 返回集合的第一个元素或满足条件的第一个元素。                 | 不适用。          | [Enumerable.First](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.first)  [Queryable.First](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.first) |
| FirstOrDefault     | 返回集合的第一个元素或满足条件的第一个元素。 如果此类元素不存在，则返回默认值。 | 不适用。          | [Enumerable.FirstOrDefault](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.firstordefault)  [Queryable.FirstOrDefault](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.firstordefault)  [Queryable.FirstOrDefault(IQueryable)](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.firstordefault#System_Linq_Queryable_FirstOrDefault__1_System_Linq_IQueryable___0__) |
| 上一个             | 返回集合的最后一个元素或满足条件的最后一个元素。             | 不适用。          | [Enumerable.Last](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.last)  [Queryable.Last](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.last) |
| LastOrDefault      | 返回集合的最后一个元素或满足条件的最后一个元素。 如果此类元素不存在，则返回默认值。 | 不适用。          | [Enumerable.LastOrDefault](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.lastordefault)  [Queryable.LastOrDefault](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.lastordefault) |
| Single             | 返回集合的唯一一个元素或满足条件的唯一一个元素。 如果没有要返回的元素或要返回多个元素，则引发 [InvalidOperationException](https://docs.microsoft.com/zh-cn/dotnet/api/system.invalidoperationexception)。 | 不适用。          | [Enumerable.Single](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.single)  [Queryable.Single](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.single) |
| SingleOrDefault    | 返回集合的唯一一个元素或满足条件的唯一一个元素。 如果没有要返回的元素，则返回默认值。 如果要返回多个元素，则引发 [InvalidOperationException](https://docs.microsoft.com/zh-cn/dotnet/api/system.invalidoperationexception)。 | 不适用。          | [Enumerable.SingleOrDefault](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.singleordefault)  [Queryable.SingleOrDefault](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.singleordefault) |

## [Converting Data Types](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/convertingdatatypes)

转换方法可更改输入对象的类型。

LINQ 查询中的转换运算可用于各种应用程序。 以下是一些示例：

- [Enumerable.AsEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.asenumerable) 方法可用于隐藏类型的标准查询运算符自定义实现。
- [Enumerable.OfType](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.oftype) 方法可用于为 LINQ 查询启用非参数化集合。
- [Enumerable.ToArray](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.toarray)、[Enumerable.ToDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.todictionary)、[Enumerable.ToList](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.tolist) 和 [Enumerable.ToLookup](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.tolookup) 方法可用于强制执行即时的查询，而不是将其推迟到枚举该查询时。

### 方法

下表列出了执行数据类型转换的标准查询运算符方法。

本表中名称以“As”开头的转换方法可更改源集合的静态类型，但不对其进行枚举。 名称以“To”开头的方法可枚举源集合，并将项放入相应的集合类型。

| 方法名       | 说明                                                         | C# 查询表达式语法                                            | 详细信息                                                     |
| ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| AsEnumerable | 返回类型化为 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的输入。 | 不适用。                                                     | [Enumerable.AsEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.asenumerable) |
| AsQueryable  | 将（泛型）[IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable) 转换为（泛型）[IQueryable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.iqueryable)。 | 不适用。                                                     | [Queryable.AsQueryable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.asqueryable) |
| Cast         | 将集合中的元素转换为指定类型。                               | 使用显式类型化的范围变量。 例如:  `from string str in words` | [Enumerable.Cast](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.cast)  [Queryable.Cast](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.cast) |
| OfType       | 根据其转换为指定类型的能力筛选值。                           | 不适用。                                                     | [Enumerable.OfType](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.oftype)  [Queryable.OfType](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.oftype) |
| ToArray      | 将集合转换为数组。 此方法强制执行查询。                      | 不适用。                                                     | [Enumerable.ToArray](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.toarray) |
| ToDictionary | 根据键选择器函数将元素放入 [Dictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.dictionary-2)。 此方法强制执行查询。 | 不适用。                                                     | [Enumerable.ToDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.todictionary) |
| ToList       | 将集合转换为 [List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1)。 此方法强制执行查询。 | 不适用。                                                     | [Enumerable.ToList](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.tolist) |
| ToLookup     | 根据键选择器函数将元素放入 [Lookup](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.lookup-2)（一对多字典）。 此方法强制执行查询。 | 不适用。                                                     | [Enumerable.ToLookup](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.tolookup) |

### 查询表达式语法示例

下面的代码示例使用显式类型化的范围变量将类型转换为子类型，然后才访问仅在此子类型上可用的成员。

```csharp
class Plant  
{  
    public string Name { get; set; }  
}  
  
class CarnivorousPlant : Plant  
{  
    public string TrapType { get; set; }  
}  
  
static void Cast()  
{  
    Plant[] plants = new Plant[] {  
        new CarnivorousPlant { Name = "Venus Fly Trap", TrapType = "Snap Trap" },  
        new CarnivorousPlant { Name = "Pitcher Plant", TrapType = "Pitfall Trap" },  
        new CarnivorousPlant { Name = "Sundew", TrapType = "Flypaper Trap" },  
        new CarnivorousPlant { Name = "Waterwheel Plant", TrapType = "Snap Trap" }  
    };  
  
    var query = from CarnivorousPlant cPlant in plants  
                where cPlant.TrapType == "Snap Trap"  
                select cPlant;  
  
    foreach (Plant plant in query)  
        Console.WriteLine(plant.Name);  
  
    /* This code produces the following output:  
  
        Venus Fly Trap  
        Waterwheel Plant  
    */  
}  
```

## [Concatenation Operations](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/concatenationoperations)

串联是指将一个序列附加到另一个序列的操作。

下图描绘了两个字符序列的串联操作。

![显示两个序列的串联的图。](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/media/concat.png)

下面一节列出了执行串联的标准查询运算符方法。

### 方法

| 方法名 | 说明                         | C# 查询表达式语法 | 详细信息                                                     |
| ------ | ---------------------------- | ----------------- | ------------------------------------------------------------ |
| Concat | 连接两个序列以组成一个序列。 | 不适用。          | [Enumerable.Concat](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.concat)  [Queryable.Concat](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.concat) |

## [Aggregation Operations](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/aggregationoperations)

聚合运算从值的集合中计算出单个值。 例如，从一个月累计的每日温度值计算出日平均温度值就是一个聚合运算。

下图显示对数字序列进行两种不同聚合操作所得结果。 第一个操作累加数字。 第二个操作返回序列中的最大值。

![LINQ 聚合操作](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/media/linq_aggregation.png)

下节列出了执行聚合运算的标准查询运算符方法。

### 方法

| 方法名    | 说明                                                     | C# 查询表达式语法 | 详细信息                                                     |
| --------- | -------------------------------------------------------- | ----------------- | ------------------------------------------------------------ |
| 聚合      | 对集合的值执行自定义聚合运算。                           | 不适用。          | [Enumerable.Aggregate](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.aggregate)  [Queryable.Aggregate](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.aggregate) |
| 平均值    | 计算值集合的平均值。                                     | 不适用。          | [Enumerable.Average](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.average)  [Queryable.Average](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.average) |
| 计数      | 对集合中元素计数，可选择仅对满足谓词函数的元素计数。     | 不适用。          | [Enumerable.Count](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.count)  [Queryable.Count](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.count) |
| LongCount | 对大型集合中元素计数，可选择仅对满足谓词函数的元素计数。 | 不适用。          | [Enumerable.LongCount](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.longcount)  [Queryable.LongCount](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.longcount) |
| 最大值    | 确定集合中的最大值。                                     | 不适用。          | [Enumerable.Max](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.max)  [Queryable.Max](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.max) |
| 最小值    | 确定集合中的最小值。                                     | 不适用。          | [Enumerable.Min](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.min)  [Queryable.Min](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.min) |
| Sum       | 对集合中的值求和。                                       | 不适用。          | [Enumerable.Sum](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.sum)  [Queryable.Sum](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable.sum) |