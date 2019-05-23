# [Programming Concepts](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/)

## [Expression Trees](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/expression-trees/)

表达式树以树形数据结构表示代码，其中每一个节点都是一种表达式，比如方法调用和 `x < y` 这样的二元运算等。

你可以对表达式树中的代码进行编辑和运算。 这样能够动态修改可执行代码、在不同数据库中执行 LINQ 查询以及创建动态查询。 若要详细了解 LINQ 中的表达式树，请参阅[操作说明：使用表达式树生成动态查询 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/expression-trees/how-to-use-expression-trees-to-build-dynamic-queries)。

表达式树还能用于动态语言运行时 (DLR) 以提供动态语言和 .NET Framework 之间的互操作性，同时保证编译器编写员能够发射表达式树而非 Microsoft 中间语言 (MSIL)。 有关 DLR 的详细信息，请参阅[动态语言运行时概述](https://docs.microsoft.com/zh-cn/dotnet/framework/reflection-and-codedom/dynamic-language-runtime-overview)。

你可以基于匿名 lambda 表达式通过 C# 或者 Visual Basic 编译器创建表达式树，或者通过[System.Linq.Expressions](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions) 名称空间手动创建。

### 根据 Lambda 表达式创建表达式树

若 lambda 表达式被分配给 [Expression](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions.expression-1) 类型的变量，则编译器可以发射代码以创建表示该 lambda 表达式的表达式树。

C# 编译器只能从表达式 Lambda（或单行 Lambda）生成表达式树。 它无法解析语句 lambda （或多行 lambda）。 有关 C# 中 Lambda 表达式的详细信息，请参阅 [Lambda 表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/lambda-expressions)。

下列代码示例展示如何通过 C# 编译器创建表示 Lambda 表达式 `num => num < 5` 的表达式树。

```csharp
Expression<Func<int, bool>> lambda = num => num < 5;  
```

### 通过 API 创建表达式树

通过 API 创建表达式树需要使用 [Expression](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions.expression) 类。 类包含创建特定类型表达式树节点的静态工厂方法，比如表示参数变量的 [ParameterExpression](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions.parameterexpression)，或者是表示方法调用的 [MethodCallExpression](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions.methodcallexpression)。 [ParameterExpression](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions.parameterexpression) 名称空间还解释了 [MethodCallExpression](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions.methodcallexpression)、[System.Linq.Expressions](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions)和另一种具体表达式类型。 这些类型来源于抽象类型 [Expression](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions.expression)。

下列代码示例展示如何使用 API 创建表示 Lambda 表达式 `num => num < 5` 的表达式树。

```csharp
// Add the following using directive to your code file:  
// using System.Linq.Expressions;  
  
// Manually build the expression tree for   
// the lambda expression num => num < 5.  
ParameterExpression numParam = Expression.Parameter(typeof(int), "num");  
ConstantExpression five = Expression.Constant(5, typeof(int));  
BinaryExpression numLessThanFive = Expression.LessThan(numParam, five);  
Expression<Func<int, bool>> lambda1 =  
    Expression.Lambda<Func<int, bool>>(  
        numLessThanFive,  
        new ParameterExpression[] { numParam });  
```

在 .NET Framework 4 或更高版本中，表达式树 API 还支持赋值表达式和控制流表达式，例如循环、条件块和 `try-catch` 块等。 相对于通过 C# 编译器和 Lambda 表达式创建表达式树，还可利用 API 创建更加复杂的表达式树。 下列示例展示如何创建计算数字阶乘的表达式树。

```csharp
// Creating a parameter expression.  
ParameterExpression value = Expression.Parameter(typeof(int), "value");  
  
// Creating an expression to hold a local variable.   
ParameterExpression result = Expression.Parameter(typeof(int), "result");  
  
// Creating a label to jump to from a loop.  
LabelTarget label = Expression.Label(typeof(int));  
  
// Creating a method body.  
BlockExpression block = Expression.Block(  
    // Adding a local variable.  
    new[] { result },  
    // Assigning a constant to a local variable: result = 1  
    Expression.Assign(result, Expression.Constant(1)),  
    // Adding a loop.  
        Expression.Loop(  
    // Adding a conditional block into the loop.  
           Expression.IfThenElse(  
    // Condition: value > 1  
               Expression.GreaterThan(value, Expression.Constant(1)),  
    // If true: result *= value --  
               Expression.MultiplyAssign(result,  
                   Expression.PostDecrementAssign(value)),  
    // If false, exit the loop and go to the label.  
               Expression.Break(label, result)  
           ),  
    // Label to jump to.  
       label  
    )  
);  
  
// Compile and execute an expression tree.  
int factorial = Expression.Lambda<Func<int, int>>(block, value).Compile()(5);  
  
Console.WriteLine(factorial);  
// Prints 120.  
```

有关详细信息，请参阅[在 Visual Studio 2010 中使用表达式树生成动态方法](https://blogs.msdn.microsoft.com/csharpfaq/2009/09/14/generating-dynamic-methods-with-expression-trees-in-visual-studio-2010/)，该方法也适用于 Visual Studio 的更高版本。

### 解析表达式树

下列代码示例展示如何分解表示 Lambda 表达式 `num => num < 5` 的表达式树。

```csharp
// Add the following using directive to your code file:  
// using System.Linq.Expressions;  
  
// Create an expression tree.  
Expression<Func<int, bool>> exprTree = num => num < 5;  
  
// Decompose the expression tree.  
ParameterExpression param = (ParameterExpression)exprTree.Parameters[0];  
BinaryExpression operation = (BinaryExpression)exprTree.Body;  
ParameterExpression left = (ParameterExpression)operation.Left;  
ConstantExpression right = (ConstantExpression)operation.Right;  
  
Console.WriteLine("Decomposed expression: {0} => {1} {2} {3}",  
                  param.Name, left.Name, operation.NodeType, right.Value);  
  
// This code produces the following output:  
  
// Decomposed expression: num => num LessThan 5  
```

### 表达式树永久性

表达式树应具有永久性。 这意味着如果你想修改某个表达式树，则必须复制该表达式树然后替换其中的节点来创建一个新的表达式树。 你可以使用表达式树访问者遍历现有表达式树。 有关详细信息，请参阅[如何：修改表达式树 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/expression-trees/how-to-modify-expression-trees)。

### 编译表达式树

[Expression](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions.expression-1) 类型提供了 [Compile](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions.expression-1.compile) 方法以将表达式树表示的代码编译成可执行委托。

下列代码示例展示如何编译表达式树并运行结果代码。

```csharp
// Creating an expression tree.  
Expression<Func<int, bool>> expr = num => num < 5;  
  
// Compiling the expression tree into a delegate.  
Func<int, bool> result = expr.Compile();  
  
// Invoking the delegate and writing the result to the console.  
Console.WriteLine(result(4));  
  
// Prints True.  
  
// You can also use simplified syntax  
// to compile and run an expression tree.  
// The following line can replace two previous statements.  
Console.WriteLine(expr.Compile()(4));  
  
// Also prints True.  
```

有关详细信息，请参阅[如何：执行表达式树 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/expression-trees/how-to-execute-expression-trees)。

### [How to: Execute Expression Trees](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/expression-trees/how-to-execute-expression-trees)

本主题演示如何执行表达式树。 执行表达式树可能返回一个值，或者它可能只是执行操作，例如调用方法。

仅可以执行表示 lambda 表达式的表达式树。 表示 Lambda 表达式的表达式树的类型为 [LambdaExpression](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions.lambdaexpression) 或[Expression](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions.expression-1)。 若要执行这些表达式树，请调用 [Compile](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions.lambdaexpression.compile) 方法来创建一个可执行的委托，然后调用该委托。

> 如果委托的类型未知，也就是说 Lambda 表达式的类型为 [LambdaExpression](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions.lambdaexpression)，而不是[Expression](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions.expression-1)，则必须对委托调用 [DynamicInvoke](https://docs.microsoft.com/zh-cn/dotnet/api/system.delegate.dynamicinvoke) 方法，而不是直接调用委托。

如果表达式树不表示 Lambda 表达式，可以通过调用 [Lambda(Expression, IEnumerable)](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions.expression.lambda#System_Linq_Expressions_Expression_Lambda__1_System_Linq_Expressions_Expression_System_Collections_Generic_IEnumerable_System_Linq_Expressions_ParameterExpression__) 方法创建一个新的 Lambda 表达式，此表达式的主体为原始表达式树。 然后，按本节前面所述执行此 lambda 表达式。

#### 示例

下面的代码示例演示如何通过创建 lambda 表达式并执行它来执行代表幂运算的表达式树。 示例最后显示幂运算的结果。

```csharp
// The expression tree to execute.  
BinaryExpression be = Expression.Power(Expression.Constant(2D), Expression.Constant(3D));  
  
// Create a lambda expression.  
Expression<Func<double>> le = Expression.Lambda<Func<double>>(be);  
  
// Compile the lambda expression.  
Func<double> compiledExpression = le.Compile();  
  
// Execute the lambda expression.  
double result = compiledExpression();  
  
// Display the result.  
Console.WriteLine(result);  
  
// This code produces the following output:  
// 8  
```

#### 编译代码

- 添加对 System.Core.dll 的项目引用（如果尚未引用）。
- 包括 System.Linq.Expressions 命名空间。

### [How to: Modify Expression Trees](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/expression-trees/how-to-modify-expression-trees)

本主题演示如何修改表达式树。 表达式树是不可变的，这意味着不能直接对它们进行修改。 若要更改表达式树，必须创建现有表达式树的副本，创建此副本后，进行必要的更改。 可以使用 [ExpressionVisitor](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions.expressionvisitor) 类遍历现有表达式树，以及复制它访问的每个节点。

#### 修改表达式树

1. 创建新的**控制台应用程序**项目。

2. 为 `System.Linq.Expressions` 命名空间的文件添加 `using` 指令。

3. 向项目中添加 `AndAlsoModifier` 类。

   ```csharp
   public class AndAlsoModifier : ExpressionVisitor  
   {  
       public Expression Modify(Expression expression)  
       {  
           return Visit(expression);  
       }  
   
       protected override Expression VisitBinary(BinaryExpression b)  
       {  
           if (b.NodeType == ExpressionType.AndAlso)  
           {  
               Expression left = this.Visit(b.Left);  
               Expression right = this.Visit(b.Right);  
   
               // Make this binary expression an OrElse operation instead of an AndAlso operation.  
               return Expression.MakeBinary(ExpressionType.OrElse, left, right, b.IsLiftedToNull, b.Method);  
           }  
   
           return base.VisitBinary(b);  
       }  
   }  
   ```

   此类继承 [ExpressionVisitor](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions.expressionvisitor) 类，并且专用于修改表示条件 `AND` 运算的表达式。 它将运算从条件 `AND` 更改为条件 `OR`。 若要执行此操作，此类替代基类型的 [VisitBinary](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions.expressionvisitor.visitbinary) 方法，因为条件 `AND` 表达式表示为二进制表达式。 在 `VisitBinary` 方法中，如果传递给它的表达式表示条件 `AND` 操作，那么代码将构造一个新的表达式，此表达式包含条件 `OR` 运算符，而不是条件 `AND` 运算符。 如果传递给 `VisitBinary` 的表达式不表示条件 `AND` 运算，那么此方法遵从基类实现。 基类方法构造类似于所传递的表达式树的节点，但是这些节点将子树替换为访问者以递归方式生成的表达式树。

4. 为 `System.Linq.Expressions` 命名空间的文件添加 `using` 指令。

5. 向 Program.cs 文件中的 `Main` 方法添加代码以创建表达式树，并将其传递给将对其进行修改的方法。

   ```csharp
   Expression<Func<string, bool>> expr = name => name.Length > 10 && name.StartsWith("G");  
   Console.WriteLine(expr);  
   
   AndAlsoModifier treeModifier = new AndAlsoModifier();  
   Expression modifiedExpr = treeModifier.Modify((Expression) expr);  
   
   Console.WriteLine(modifiedExpr);  
   
   /*  This code produces the following output:  
   
       name => ((name.Length > 10) && name.StartsWith("G"))  
       name => ((name.Length > 10) || name.StartsWith("G"))  
   */  
   ```

   此代码创建的表达式中包含条件 `AND` 运算。 然后，此代码创建 `AndAlsoModifier` 类的实例，并将表达式传递给此类的 `Modify` 方法。 输出原始以及修改后的表达式树以显示更改。

6. 编译并运行该应用程序。

### [How to: Use Expression Trees to Build Dynamic Queries](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/expression-trees/how-to-use-expression-trees-to-build-dynamic-queries)

在 LINQ 中，表达式树用于表示针对数据源的结构化查询，这些数据源可实现 [IQueryable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.iqueryable-1)。 例如，LINQ 提供程序可实现 [IQueryable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.iqueryable-1) 接口，用于查询关系数据存储。 C# 编译器将针对此类数据源的查询编译为代码，该代码在运行时会生成一个表达式树。 然后，查询提供程序可以遍历表达式树数据结构，并将其转换为适合于数据源的查询语言。

表达式树还可以用在 LINQ 中，用于表示分配给类型为 [Expression](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions.expression-1) 的变量的 lambda 表达式。

本主题描述如何使用表达式树来创建动态 LINQ 查询。 如果在编译时不知道查询的细节，动态查询将十分有用。例如，应用程序可能会提供一个用户界面，最终用户可以使用该用户界面指定一个或多个谓词来筛选数据。 为了使用 LINQ 进行查询，这种应用程序必须使用表达式树在运行时创建 LINQ 查询。

#### 示例

下面的示例演示如何使用表达式树依据 `IQueryable` 数据源构造一个查询，然后执行该查询。 代码将生成一个表达式树来表示以下查询：

```
companies.Where(company => (company.ToLower() == "coho winery" || company.Length > 16)).OrderBy(company => company)
```

[System.Linq.Expressions](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions) 命名空间中的工厂方法用于创建表达式树，这些表达式树表示构成总体查询的表达式。表示标准查询运算符方法调用的表达式将引用这些方法的 [Queryable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.queryable) 实现。 最终的表达式树将传递给 `IQueryable` 数据源的提供程序的 [CreateQuery(Expression)](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.iqueryprovider.createquery#System_Linq_IQueryProvider_CreateQuery__1_System_Linq_Expressions_Expression_) 实现，以创建 `IQueryable` 类型的可执行查询。 通过枚举该查询变量获得结果。

```csharp
// Add a using directive for System.Linq.Expressions.  
  
string[] companies = { "Consolidated Messenger", "Alpine Ski House", "Southridge Video", "City Power & Light",  
                   "Coho Winery", "Wide World Importers", "Graphic Design Institute", "Adventure Works",  
                   "Humongous Insurance", "Woodgrove Bank", "Margie's Travel", "Northwind Traders",  
                   "Blue Yonder Airlines", "Trey Research", "The Phone Company",  
                   "Wingtip Toys", "Lucerne Publishing", "Fourth Coffee" };  
  
// The IQueryable data to query.  
IQueryable<String> queryableData = companies.AsQueryable<string>();  
  
// Compose the expression tree that represents the parameter to the predicate.  
ParameterExpression pe = Expression.Parameter(typeof(string), "company");  
  
// ***** Where(company => (company.ToLower() == "coho winery" || company.Length > 16)) *****  
// Create an expression tree that represents the expression 'company.ToLower() == "coho winery"'.  
Expression left = Expression.Call(pe, typeof(string).GetMethod("ToLower", System.Type.EmptyTypes));  
Expression right = Expression.Constant("coho winery");  
Expression e1 = Expression.Equal(left, right);  
  
// Create an expression tree that represents the expression 'company.Length > 16'.  
left = Expression.Property(pe, typeof(string).GetProperty("Length"));  
right = Expression.Constant(16, typeof(int));  
Expression e2 = Expression.GreaterThan(left, right);  
  
// Combine the expression trees to create an expression tree that represents the  
// expression '(company.ToLower() == "coho winery" || company.Length > 16)'.  
Expression predicateBody = Expression.OrElse(e1, e2);  
  
// Create an expression tree that represents the expression  
// 'queryableData.Where(company => (company.ToLower() == "coho winery" || company.Length > 16))'  
MethodCallExpression whereCallExpression = Expression.Call(  
    typeof(Queryable),  
    "Where",  
    new Type[] { queryableData.ElementType },  
    queryableData.Expression,  
    Expression.Lambda<Func<string, bool>>(predicateBody, new ParameterExpression[] { pe }));  
// ***** End Where *****  
  
// ***** OrderBy(company => company) *****  
// Create an expression tree that represents the expression  
// 'whereCallExpression.OrderBy(company => company)'  
MethodCallExpression orderByCallExpression = Expression.Call(  
    typeof(Queryable),  
    "OrderBy",  
    new Type[] { queryableData.ElementType, queryableData.ElementType },  
    whereCallExpression,  
    Expression.Lambda<Func<string, string>>(pe, new ParameterExpression[] { pe }));  
// ***** End OrderBy *****  
  
// Create an executable query from the expression tree.  
IQueryable<string> results = queryableData.Provider.CreateQuery<string>(orderByCallExpression);  
  
// Enumerate the results.  
foreach (string company in results)  
    Console.WriteLine(company);  
  
/*  This code produces the following output:  
  
    Blue Yonder Airlines  
    City Power & Light  
    Coho Winery  
    Consolidated Messenger  
    Graphic Design Institute  
    Humongous Insurance  
    Lucerne Publishing  
    Northwind Traders  
    The Phone Company  
    Wide World Importers  
*/  
```

此代码在传递到 `Queryable.Where` 方法的谓词中使用固定数量的表达式。 但是，可以编写一个视用户输入而定来合并可变数量谓词表达式的应用程序。 视用户输入而定，也可以更改在查询中调用的标准查询运算符。

#### 编译代码

- 创建新的**控制台应用程序**项目。
- 添加对 System.Core.dll 的引用（如果尚未引用）。
- 包括 System.Linq.Expressions 命名空间。
- 从示例中复制代码，并将其粘贴到 `Main` 方法中。

### [Debugging Expression Trees in Visual Studio](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/expression-trees/debugging-expression-trees-in-visual-studio)

可以在调试应用程序时分析表达式树的结构和内容。 若要快速了解表达式树结构，可以使用 `DebugView` 属性，该属性仅在调试模式下可用。 有关调试的详细信息，请参阅[在 Visual Studio 中进行调试](https://docs.microsoft.com/zh-cn/visualstudio/debugger/debugging-in-visual-studio)。

为了更好地表示表达式树的内容，`DebugView` 属性使用 Visual Studio 可视化工具。 有关详细信息，请参阅[创建自定义可视化工具](https://docs.microsoft.com/zh-cn/visualstudio/debugger/create-custom-visualizers-of-data)。

#### 打开表达式树的可视化工具

1. 单击“数据提示”、“监视”窗口、“自动”或“局部变量”窗口中表达式树的 `DebugView` 属性旁边显示的放大镜图标。

   将会显示可视化工具列表。

2. 单击要使用的可视化工具。

每个表达式类型如以下各节所述显示在可视化工具中。

#### ParameterExpressions

[ParameterExpression](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions.parameterexpression) 变量名称的开头显示有“$”符号。

如果参数没有名称，则会为其分配一个自动生成的名称，例如 `$var1` 或 `$var2`。

- 示例

| 表达式                                                       | `DebugView` 属性 |
| ------------------------------------------------------------ | ---------------- |
| `ParameterExpression numParam = Expression.Parameter(typeof(int), "num");` | `$num`           |
| `ParameterExpression numParam = Expression.Parameter(typeof(int));` | `$var1`          |

#### ConstantExpressions

对于表示整数值、字符串和 `null` 的 [ConstantExpression](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions.constantexpression) 对象，将显示常数的值。

对于使用标准后缀作为 C# 原义字符的数值类型，将后缀添加到值。 下表显示与各种数值类型关联的后缀。

| 类型                                                         | 后缀 |
| ------------------------------------------------------------ | ---- |
| [UInt32](https://docs.microsoft.com/zh-cn/dotnet/api/system.uint32) | U    |
| [Int64](https://docs.microsoft.com/zh-cn/dotnet/api/system.int64) | L    |
| [UInt64](https://docs.microsoft.com/zh-cn/dotnet/api/system.uint64) | UL   |
| [Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double) | D    |
| [Single](https://docs.microsoft.com/zh-cn/dotnet/api/system.single) | F    |
| [Decimal](https://docs.microsoft.com/zh-cn/dotnet/api/system.decimal) | M    |

- 示例

| 表达式                                                       | `DebugView` 属性 |
| ------------------------------------------------------------ | ---------------- |
| `int num = 10; ConstantExpression expr = Expression.Constant(num);` | 10               |
| `double num = 10; ConstantExpression expr = Expression.Constant(num);` | 10D              |

#### BlockExpression

如果 [BlockExpression](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions.blockexpression) 对象的类型与块中最后一个表达式的类型不同，则该类型将显示在 `DebugInfo` 属性中的尖括号（< 和 >）中。 否则，将不显示 [BlockExpression](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions.blockexpression) 对象的类型。

- 示例

| 表达式                                                       | `DebugView` 属性                           |
| ------------------------------------------------------------ | ------------------------------------------ |
| `BlockExpression block = Expression.Block(Expression.Constant("test"));` | `.Block() {`  `"test"`  `}`                |
| `BlockExpression block = Expression.Block(typeof(Object), Expression.Constant("test"));` | `.Block<System.Object>() {`  `"test"`  `}` |

#### LambdaExpression

显示 [LambdaExpression](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions.lambdaexpression) 对象及其委托类型。

如果 lambda 表达式没有名称，则会为其分配一个自动生成的名称，例如 `#Lambda1` 或 `#Lambda2`。

- 示例

| 表达式                                                       | `DebugView` 属性                                             |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| `LambdaExpression lambda = Expression.Lambda<Func<int>>(Expression.Constant(1));` | `.Lambda #Lambda1<System.Func'1[System.Int32]>() {`  `1`  `}` |
| `LambdaExpression lambda = Expression.Lambda<Func<int>>(Expression.Constant(1), "SampleLambda", null);` | `.Lambda SampleLambda<System.Func'1[System.Int32]>() {`  `1`  `}` |

#### LabelExpression

如果指定 [LabelExpression](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions.labelexpression) 对象的默认值，则在 [LabelTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.expressions.labeltarget) 对象之前显示此值。

`.Label` 令牌指示标签的开头。 `.LabelTarget` 令牌指示要跳转到的目标的目的地。

如果标签没有名称，则会为其分配一个自动生成的名称，例如 `#Label1` 或 `#Label2`。

- 示例

| 表达式                                                       | `DebugView` 属性                                             |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| `LabelTarget target = Expression.Label(typeof(int), "SampleLabel"); BlockExpression block = Expression.Block( Expression.Goto(target, Expression.Constant(0)), Expression.Label(target, Expression.Constant(-1)));` | `.Block() {`  `.Goto SampleLabel { 0 };`  `.Label`  `-1`  `.LabelTarget SampleLabel:`  `}` |
| `LabelTarget target = Expression.Label(); BlockExpression block = Expression.Block( Expression.Goto(target5), Expression.Label(target5));` | `.Block() {`  `.Goto #Label1 { };`  `.Label`  `.LabelTarget #Label1:`  `}` |

#### Checked 运算符

Checked 运算符在运算符前面显示 “#” 符号。 例如，checked 加号显示为 `#+`。

- 示例

| 表达式                                                       | `DebugView` 属性     |
| ------------------------------------------------------------ | -------------------- |
| `Expression expr = Expression.AddChecked( Expression.Constant(1), Expression.Constant(2));` | `1 #+ 2`             |
| `Expression expr = Expression.ConvertChecked( Expression.Constant(10.0), typeof(int));` | `#(System.Int32)10D` |