# [Introduction to LINQ](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/introductiontolinq)

语言集成查询 (LINQ) 是 .NET Framework 3.5 版中引入的一项创新功能，它在对象领域和数据领域之间架起了一座桥梁。

数据查询历来都表示为简单的字符串，没有编译时类型检查或 IntelliSense 支持。 此外，需要针对每种类型的数据源了解不同的查询语言：SQL 数据库、XML 文档、各种 Web 服务等。 LINQ 使查询成为 C# 中的一流语言构造。可以使用语言关键字和熟悉的运算符针对强类型化对象集合编写查询。

在 C# 中可为以下对象编写 LINQ 查询：SQL Server 数据库、XML 文档、ADO.NET 数据集以及支持 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable)或泛型 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 接口的任何对象集合。 此外，第三方也为许多 Web 服务和其他数据库实现提供了 LINQ 支持。

LINQ 查询既可在新项目中使用，也可在现有项目中与非 LINQ 查询一起使用。 唯一的要求是项目应面向 .NET Framework 3.5 或更高版本。

下图为 Visual Studio 中的图例，显示了使用 C# 和 Visual Basic 针对 SQL Server 数据库编写的不完整 LINQ 查询，并具有完全类型检查和 IntelliSense 支持。

![具有 Intellisense 的 LINQ 查询](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/media/query_intell.png)

## 后续步骤

若要了解有关 LINQ 的详细信息，请先熟悉入门部分 [C# 中的 LINQ 入门](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/getting-started-with-linq)中的一些基本概念，然后阅读你感兴趣的 LINQ 技术的文档：

- SQL Server 数据库：[LINQ to SQL](https://docs.microsoft.com/zh-cn/dotnet/framework/data/adonet/sql/linq/index)
- XML 文档：[LINQ to XML (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/linq-to-xml)
- ADO.NET 数据集：[LINQ to DataSet](https://docs.microsoft.com/zh-cn/dotnet/framework/data/adonet/linq-to-dataset)
- .NET 集合、文件、字符串等：[LINQ to Objects (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/linq-to-objects)

