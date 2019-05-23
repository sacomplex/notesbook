# [LINQ to ADO.NET (Portal Page)](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/linq/linq-to-adonet-portal-page)

通过 LINQ to ADO.NET，你可以使用 语言集成查询 (LINQ) 编程模型针对 ADO.NET 中的任何可枚举对象进行查询。

> LINQ to ADO.NET 文档位于 .NET Framework SDK 的 ADO.NET 部分：[LINQ 和 ADO.NET](https://docs.microsoft.com/zh-cn/dotnet/framework/data/adonet/linq-and-ado-net)。

有三种独立的 ADO.NET 语言集成查询 (LINQ) 技术：LINQ to DataSet、LINQ to SQL 和 LINQ to Entities。 LINQ to DataSet 提供针对 [DataSet](https://docs.microsoft.com/zh-cn/dotnet/api/system.data.dataset) 的形式多样的优化查询，LINQ to SQL 使你可直接查询 SQL Server 数据库架构，而LINQ to Entities 允许你查询 实体数据模型。

## LINQ to DataSet

[DataSet](https://docs.microsoft.com/zh-cn/dotnet/api/system.data.dataset) 是 ADO.NET 中使用最广泛的组件之一，也是断开连接的编程模型的关键元素，该模型是构建 ADO.NET的基础。 [DataSet](https://docs.microsoft.com/zh-cn/dotnet/api/system.data.dataset) 虽然具有突出的优点，但其查询功能也存在限制。

LINQ to DataSet 让你可通过使用为其他多种数据源提供的相同查询功能，在 [DataSet](https://docs.microsoft.com/zh-cn/dotnet/api/system.data.dataset) 中加入更丰富的查询功能。

有关详细信息，请参阅 [LINQ to DataSet](https://docs.microsoft.com/zh-cn/dotnet/framework/data/adonet/linq-to-dataset)。

## LINQ to SQL

LINQ to SQL 提供用于将关系数据作为对象进行管理的运行时基础结构。 在 LINQ to SQL 中，关系数据库的数据模型映射到用开发人员所用的编程语言表示的对象模型。 执行应用程序时，LINQ to SQL 会将对象模型中的语言集成查询转换为 SQL，然后将其发送到数据库进行执行。 数据库返回结果时，LINQ to SQL 会将结果转换回可操作对象。

LINQ to SQL 包括对数据库中的已存储过程和用户定义的函数和对象模型中的继承的支持。

有关详细信息，请参阅 [LINQ to SQL](https://docs.microsoft.com/zh-cn/dotnet/framework/data/adonet/sql/linq/index)。

## LINQ to Entities

通过 实体数据模型，在 .NET 环境中将关系数据作为对象公开。 这使得对象层成为实现 LINQ 支持的理想目标，开发人员可以采用生成业务逻辑所用的语言来构建数据库查询。 此功能称为 LINQ to Entities。 有关详细信息，请参阅 [LINQ to Entities](https://docs.microsoft.com/zh-cn/dotnet/framework/data/adonet/ef/language-reference/linq-to-entities)。