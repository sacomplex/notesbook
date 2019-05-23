#  [How To C# Topics](https://docs.microsoft.com/en-us/dotnet/csharp/how-to/)

在 C# 指南中的操作指南部分快速了解常见问题的答案。 在某些情况下，可能会在多个部分列出相关文章。 我们希望用户可从多个搜索路径找到操作指南。

## C# 一般概念

此处介绍了 C# 开发者在实践中常会用到的几个提示和技巧。

- [使用对象初始值设定项初始化对象](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/how-to-initialize-objects-by-using-an-object-initializer)。
- [了解向方法传递结构和传递类的区别](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/how-to-know-the-difference-passing-a-struct-and-passing-a-class-to-a-method)。
- [如何使用 Lambda 表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/how-to-use-lambda-expressions-outside-linq)。
- [使用全局命名空间别名解决类型名冲突](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/namespaces/how-to-use-the-global-namespace-alias)。
- [使用运算符重载](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/operator)。
- [实现和调用自定义扩展方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/how-to-implement-and-call-a-custom-extension-method)。
- 即使是 C# 程序员也可能需要[使用 VB `My` 命名空间](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/namespaces/how-to-use-the-my-namespace)。
- [使用扩展方法创建新 `enum` 类型方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/how-to-create-a-new-method-for-an-enumeration)。

### 类和结构成员

创建类和结构来实现程序。 编写类或结构时常会使用这些方法。

- [声明自动实现的属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/how-to-implement-a-lightweight-class-with-auto-implemented-properties)。
- [声明和使用读/写属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/how-to-declare-and-use-read-write-properties)。
- [定义常量](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/how-to-define-constants)。
- [替代 `ToString` 方法以提供字符串输出](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/how-to-override-the-tostring-method)。
- [定义抽象属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/how-to-define-abstract-properties)。
- [使用 XML 文档功能记录代码](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/how-to-use-the-xml-documentation-features)。
- [显式实现接口成员](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/interfaces/how-to-explicitly-implement-interface-members)，使公共接口保持简洁。
- [显式实现两个接口的成员](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/interfaces/how-to-explicitly-implement-members-of-two-interfaces)。

### 使用集合

这些文章有助于了解如何使用数据集合。

- [使用集合初始值设定项初始化字典](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/how-to-initialize-a-dictionary-with-a-collection-initializer)。

## 处理字符串

字符串是用于显示或操作文本的基本数据类型。 这些文章介绍了字符串的常见处理方法。

- [比较字符串](https://docs.microsoft.com/zh-cn/dotnet/csharp/how-to/compare-strings)。
- [修改字符串内容](https://docs.microsoft.com/zh-cn/dotnet/csharp/how-to/modify-string-contents)。
- [确定字符串是否表示数字](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/strings/how-to-determine-whether-a-string-represents-a-numeric-value)。
- [使用 `String.Split` 分隔字符串](https://docs.microsoft.com/zh-cn/dotnet/csharp/how-to/parse-strings-using-split)。
- [将多个字符串合并为一个字符串](https://docs.microsoft.com/zh-cn/dotnet/csharp/how-to/concatenate-multiple-strings)。
- [在字符串中搜索文本](https://docs.microsoft.com/zh-cn/dotnet/csharp/how-to/search-strings)。

## 在类型间转换

你可能需要将对象转换为其他类型。

- [确定字符串是否表示数字](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/strings/how-to-determine-whether-a-string-represents-a-numeric-value)。
- [在表示十六进制数的字符串和数字之间进行转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/types/how-to-convert-between-hexadecimal-strings-and-numeric-types)。
- [将字符串转换为 `DateTime`](https://docs.microsoft.com/zh-cn/dotnet/standard/base-types/parsing-datetime)。
- [将字节数组转换为 int](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/types/how-to-convert-a-byte-array-to-an-int)。
- [将字符串转换为数字](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/types/how-to-convert-a-string-to-a-number)。
- [使用模式匹配、`as` 和 `is` 运算符安全强制转换为其他类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/how-to/safely-cast-using-pattern-matching-is-and-as-operators)。
- [定义 `struct` 类型的转换运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/how-to-implement-user-defined-conversions-between-structs)。
- [确定类型是否为可为 null 的值类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/nullable-types/how-to-identify-a-nullable-type)。
- [在可为 null 和不可为 null 的值类型之间转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/nullable-types/using-nullable-types#conversion-from-a-nullable-type-to-an-underlying-type)。

## 相等比较和排序比较

可创建类型来定义自己的相等规则，或者定义该类型对象间的自然顺序。

- [基于引用的相等性测试](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/how-to-test-for-reference-equality-identity)。
- [为类型定义基于值的相等](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/how-to-define-value-equality-for-a-type)。

## 异常处理

.NET 程序通过引发异常报告方法未能成功完成其任务。 通过这些文章可了解如何处理异常。

- [使用 `try` 和 `catch` 处理异常](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/exceptions/how-to-handle-an-exception-using-try-catch)。
- [使用 `finally` 子句清理资源](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/exceptions/how-to-execute-cleanup-code-using-finally)。
- [从非 CLS （公共语言规范）异常中恢复](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/exceptions/how-to-catch-a-non-cls-exception)。

## 委托和事件

委托和事件为涉及松散耦合代码块的策略提供了功能。

- [声明、实例化和使用委托](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/delegates/how-to-declare-instantiate-and-use-a-delegate)。
- [合并多播委托](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/delegates/how-to-combine-delegates-multicast-delegates)。

事件提供发布或订阅通知的机制。

- [订阅和取消订阅事件](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/events/how-to-subscribe-to-and-unsubscribe-from-events)。
- [实现接口中声明的事件](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/events/how-to-implement-interface-events)。
- [代码发布事件时，遵循 .NET Framework 准则](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/events/how-to-publish-events-that-conform-to-net-framework-guidelines)。
- [从派生类中引发在基类中定义的事件](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/events/how-to-raise-base-class-events-in-derived-classes)。
- [在字典中存储事件实例](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/events/how-to-use-a-dictionary-to-store-event-instances)。
- [实现自定义事件访问器](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/events/how-to-implement-custom-event-accessors)。

## LINQ 做法

通过 LINQ 可编写代码来查询任何支持 LINQ 查询表达式模式的数据源。 这些文章有助于你理解该模式并使用不同的数据源。

- [查询集合](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-query-an-arraylist-with-linq)。
- [在查询中使用 Lambda 表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/how-to-use-lambda-expressions-in-a-query)。
- [在查询表达式中使用 `var`](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/how-to-use-implicitly-typed-local-variables-and-arrays-in-a-query-expression)。
- [从查询返回元素属性的子集](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/how-to-return-subsets-of-element-properties-in-a-query)。
- [编写使用复杂筛选的查询](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-write-queries-with-complex-filtering)。
- [对数据源的元素排序](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-sort-elements)。
- [对多个键上的元素排序](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-sort-elements-on-multiple-keys)。
- [控制投影的类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-control-the-type-of-a-projection)。
- [计算源序列中某个值的出现次数](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-count-occurrences-of-a-word-in-a-string-linq)。
- [计算中间值](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-calculate-intermediate-values)。
- [合并来自多个源的数据](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-populate-object-collections-from-multiple-sources-linq)。
- [查找两个序列之间的差集](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-find-the-set-difference-between-two-lists-linq)。
- [调试空查询结果](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-debug-empty-query-results-sets)。
- [向 LINQ 查询添加自定义方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-add-custom-methods-for-linq-queries)。

## 多线程和异步处理

新式程序常使用异步操作。 这些文章可帮助你了解如何使用这些方法。

- [使用 `System.Threading.Tasks.Task.WhenAll` 提高异步性能](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/how-to-extend-the-async-walkthrough-by-using-task-whenall)。
- [使用 `async` 和 `await` 并行发出多个 Web 请求](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/how-to-make-multiple-web-requests-in-parallel-by-using-async-and-await)。
- [使用线程池](https://docs.microsoft.com/zh-cn/dotnet/standard/threading/the-managed-thread-pool#using-the-thread-pool)。

## 程序的命令行参数

通常情况下，C# 程序具有命令行参数。 通过这些文章可了解如何访问和处理这些命令行参数。

- [使用 `for` 检索所有命令行参数](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/main-and-command-args/how-to-display-command-line-arguments)。
- [使用 `foreach` 检索所有命令行参数](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/main-and-command-args/how-to-access-command-line-arguments-using-foreach)。

## [Parse strings using String.Split](https://docs.microsoft.com/en-us/dotnet/csharp/how-to/parse-strings-using-split)

[String.Split](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.split) 方法通过基于一个或多个分隔符拆分输入字符串来创建子字符串数组。 最简单的方法通常是分隔字边界上的字符串。 它也用于拆分其他特定字符或字符串上的字符串。

> 本文中的 C# 示例运行在 [Try.NET](https://try.dot.net/) 内联代码运行程序和演练环境中。 选择“运行”按钮以在交互窗口中运行示例。 执行代码后，可通过再次选择“运行”来修改它并运行已修改的代码。 已修改的代码要么在交互窗口中运行，要么编译失败时，交互窗口将显示所有 C# 编译器错误消息。

下方代码将一个常用短语拆分为一个由每个单词组成的字符串数组。

```csharp
string phrase = "The quick brown fox jumps over the lazy dog.";
string[] words = phrase.Split(' ');

foreach (var word in words)
{
    System.Console.WriteLine($"<{word}>");
}
```

分隔符的每个实例都会在返回的数组中产生一个值。 连续的分隔符将生成空字符串作为返回的数组中的值。 在下方示例中可以看到上述情况，其中使用空格作为分隔符：

```csharp
string phrase = "The quick brown    fox     jumps over the lazy dog.";
string[] words = phrase.Split(' ');

foreach (var word in words)
{
    System.Console.WriteLine($"<{word}>");
}
```

该行为可以更容易地用逗号分隔值 (CSV) 文件之类的格式表示表格数据。 连续的逗号表示空白列。

可传递可选 [StringSplitOptions.RemoveEmptyEntries](https://docs.microsoft.com/zh-cn/dotnet/api/system.stringsplitoptions#System_StringSplitOptions_RemoveEmptyEntries) 参数来排除返回数组中的任何空字符串。 要对返回的集合进行更复杂的处理，可使用 [LINQ](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/index) 来处理结果序列。

[String.Split](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.split) 可使用多个分隔符。 以下示例使用空格、逗号、句点、冒号和制表符，所有内容均在包含这些分隔字符的数组中传递到 [Split](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.split)。 代码底部的循环显示返回数组中的每个单词。

```csharp
char[] delimiterChars = { ' ', ',', '.', ':', '\t' };

string text = "one\ttwo three:four,five six seven";
System.Console.WriteLine($"Original text: '{text}'");

string[] words = text.Split(delimiterChars);
System.Console.WriteLine($"{words.Length} words in text:");

foreach (var word in words)
{
    System.Console.WriteLine($"<{word}>");
}
```

任何分隔符的连续实例都会在输出数组中生成空字符串：

```csharp
char[] delimiterChars = { ' ', ',', '.', ':', '\t' };

string text = "one\ttwo :,five six seven";
System.Console.WriteLine($"Original text: '{text}'");

string[] words = text.Split(delimiterChars);
System.Console.WriteLine($"{words.Length} words in text:");

foreach (var word in words)
{
    System.Console.WriteLine($"<{word}>");
}
```

[String.Split](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.split) 可采用字符串数组（充当用于分析目标字符串的分隔符的字符序列，而非单个字符）。

```csharp
        string[] separatingChars = { "<<", "..." };  

        string text = "one<<two......three<four";  
        System.Console.WriteLine("Original text: '{0}'", text);  

        string[] words = text.Split(separatingChars, System.StringSplitOptions.RemoveEmptyEntries );  
        System.Console.WriteLine("{0} substrings in text:", words.Length);  

        foreach (var word in words)
        {
            System.Console.WriteLine(word);
        }
```

可通过查看 [GitHub 存储库](https://github.com/dotnet/samples/tree/master/snippets/csharp/how-to/strings)中的代码来尝试这些示例。 也可以下载这些示例的 [zip 文件](https://github.com/dotnet/samples/raw/master/snippets/csharp/how-to/strings.zip)。

## [Concatenate strings](https://docs.microsoft.com/en-us/dotnet/csharp/how-to/concatenate-multiple-strings)

串联是将一个字符串追加到另一字符串末尾的过程。 可使用 `+` 运算符连接字符串。 对于字符串文本和字符串常量，会在编译时进行串联，运行时不串联。 对于字符串变量，仅在运行时串联。

> 本文中的 C# 示例运行在 [Try.NET](https://try.dot.net/) 内联代码运行程序和演练环境中。 选择“运行”按钮以在交互窗口中运行示例。 执行代码后，可通过再次选择“运行”来修改它并运行已修改的代码。 已修改的代码要么在交互窗口中运行，要么编译失败时，交互窗口将显示所有 C# 编译器错误消息。

以下示例通过串联将长字符串文本拆分为较短的字符串，从而提高源代码的可读性。 编译时将这些部分连接到单个字符串中。 无论涉及到多少个字符串，均不产生运行时性能开销。

```csharp
// Concatenation of literals is performed at compile time, not run time.
string text = "Historically, the world of data and the world of objects " +
"have not been well integrated. Programmers work in C# or Visual Basic " +
"and also in SQL or XQuery. On the one side are concepts such as classes, " +
"objects, fields, inheritance, and .NET Framework APIs. On the other side " +
"are tables, columns, rows, nodes, and separate languages for dealing with " +
"them. Data types often require translation between the two worlds; there are " +
"different standard functions. Because the object world has no notion of query, a " +
"query can only be represented as a string without compile-time type checking or " +
"IntelliSense support in the IDE. Transferring data from SQL tables or XML trees to " +
"objects in memory is often tedious and error-prone.";

System.Console.WriteLine(text);
```

若要连接字符串变量，可使用 `+` 或 `+=` 运算符、[字符串内插](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/tokens/interpolated)或 [String.Format](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.format)、[String.Concat](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.concat)、[String.Join](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.join)、[StringBuilder.Append](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.stringbuilder.append) 方法。 `+` 运算符易于使用，有利于产生直观代码。 即使在一个语句中使用多个 `+` 运算符，字符串内容也仅会被复制一次。 以下代码演示使用 `+` 和 `+=` 运算符串联字符串的示例：

```csharp
string userName = "<Type your name here>";
string dateString = DateTime.Today.ToShortDateString();

// Use the + and += operators for one-time concatenations.
string str = "Hello " + userName + ". Today is " + dateString + ".";
System.Console.WriteLine(str);

str += " How are you today?";
System.Console.WriteLine(str);
```

在某些表达式中，使用字符串内插进行字符串串联更简单，如以下代码所示：

```csharp
string userName = "<Type your name here>";
string date = DateTime.Today.ToShortDateString();

// Use string interpolation to concatenate strings.
string str = $"Hello {userName}. Today is {date}.";
System.Console.WriteLine(str);

str = $"{str} How are you today?";
System.Console.WriteLine(str);
```

> 在字符串串联操作中，C# 编译器将 null 字符串视为空字符串进行处理。

另一个字符串连接方法为 [String.Format](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.format)。 此方法非常适用于从少量组件字符串生成字符串的情况。

在其他情况下，可能要将字符串合并在循环中，此时不知道要合并的源字符串的数量，而且源字符串的实际数量可能非常大。 [StringBuilder](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.stringbuilder) 类专门用于此类方案。 以下代码使用 [StringBuilder](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.stringbuilder) 类的 [Append](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.stringbuilder.append) 方法串联字符串。

```csharp
// Use StringBuilder for concatenation in tight loops.
var sb = new System.Text.StringBuilder();
for (int i = 0; i < 20; i++)
{
    sb.AppendLine(i.ToString());
}
System.Console.WriteLine(sb.ToString());
```

有关详细信息，请阅读[选择字符串串联或 `StringBuilder` 类的原因](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.stringbuilder#StringAndSB)

还可使用 [String.Concat](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.concat) 方法联接集合中的字符串。 如果源字符串应使用分隔符分隔，请使用 [String.Join](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.join) 方法。以下代码使用这两种方法合并单词数组：

```csharp
string[] words = { "The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog." };

var unreadablePhrase = string.Concat(words);
System.Console.WriteLine(unreadablePhrase);

var readablePhrase = string.Join(" ", words);
System.Console.WriteLine(readablePhrase);
```

最后，可以使用 [LINQ](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/index) 和 [Enumerable.Aggregate](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.aggregate) 方法联接集合中的字符串。 此方法利用 lambda 表达式合并源字符串。 lambda 表达式用于将所有字符串添加到现有累积。 下面的示例通过在数组中的每两个单词之间添加一个空格来合并一组单词：

```csharp
string[] words = { "The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog." };

var phrase = words.Aggregate((partialPhrase, word) =>$"{partialPhrase} {word}");
System.Console.WriteLine(phrase);
```

可通过查看 [GitHub 存储库](https://github.com/dotnet/samples/tree/master/snippets/csharp/how-to/strings)中的代码来尝试这些示例。 也可以下载这些示例的 [zip 文件](https://github.com/dotnet/samples/raw/master/snippets/csharp/how-to/strings.zip)。

## [Convert a string to a DateTime](https://docs.microsoft.com/en-us/dotnet/standard/base-types/parsing-datetime)

[分析 .NET 中的日期和时间字符串](https://docs.microsoft.com/zh-cn/dotnet/standard/base-types/parsing-datetime)

## [Search strings](https://docs.microsoft.com/en-us/dotnet/csharp/how-to/search-strings)

可以使用两种主要策略搜索字符串中的文本。 [String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string) 类的方法搜索特定文本。 正则表达式搜索文本中的模式。

> 本文中的 C# 示例运行在 [Try.NET](https://try.dot.net/) 内联代码运行程序和演练环境中。 选择“运行”按钮以在交互窗口中运行示例。 执行代码后，可通过再次选择“运行”来修改它并运行已修改的代码。 已修改的代码要么在交互窗口中运行，要么编译失败时，交互窗口将显示所有 C# 编译器错误消息。

[string](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/string) 类型是 [System.String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string) 类的别名，可提供多种有效方法用于搜索字符串的内容。 其中包括 [Contains](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.contains)、[StartsWith](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.startswith)、[EndsWith](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.endswith)、[IndexOf](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.indexof) 以及 [LastIndexOf](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.lastindexof)。 [System.Text.RegularExpressions.Regex](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.regularexpressions.regex) 类具备丰富的词汇来对文本中的模式进行搜索。 你将在本文中了解这些技术以及如何选择符合需求的最佳方法。

#### 字符串包含文本吗？

[String.Contains](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.contains)、[String.StartsWith](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.startswith) 和 [String.EndsWith](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.endswith) 方法搜索字符串中的特定文本。 下面的示例显示了每一个方法以及使用不区分大小写的搜索的差异：

```csharp
string factMessage = "Extension methods have all the capabilities of regular static methods.";

// Write the string and include the quotation marks.
Console.WriteLine($"\"{factMessage}\"");

// Simple comparisons are always case sensitive!
bool containsSearchResult = factMessage.Contains("extension");
Console.WriteLine($"Starts with \"extension\"? {containsSearchResult}");

// For user input and strings that will be displayed to the end user, 
// use the StringComparison parameter on methods that have it to specify how to match strings.
bool ignoreCaseSearchResult = factMessage.StartsWith("extension", System.StringComparison.CurrentCultureIgnoreCase);
Console.WriteLine($"Starts with \"extension\"? {ignoreCaseSearchResult} (ignoring case)");

bool endsWithSearchResult = factMessage.EndsWith(".", System.StringComparison.CurrentCultureIgnoreCase);
Console.WriteLine($"Ends with '.'? {endsWithSearchResult}");
```

前面的示例演示了使用这些方法的重点。 默认情况下搜索是区分大小写的。 使用 [StringComparison.CurrentCultureIgnoreCase](https://docs.microsoft.com/zh-cn/dotnet/api/system.stringcomparison#System_StringComparison_CurrentCultureIgnoreCase) 枚举值指定区分大小写的搜索。

#### 寻找的文本出现在字符串的什么位置？

[IndexOf](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.indexof) 和 [LastIndexOf](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.lastindexof) 方法也搜索字符串中的文本。 这些方法返回查找到的文本的位置。 如果未找到文本，则返回 `-1`。 下面的示例显示“methods”第一次出现和最后一次出现的搜索结果，并显示了它们之间的文本。

```csharp
string factMessage = "Extension methods have all the capabilities of regular static methods.";

// Write the string and include the quotation marks.
Console.WriteLine($"\"{factMessage}\"");

// This search returns the substring between two strings, so 
// the first index is moved to the character just after the first string.
int first = factMessage.IndexOf("methods") + "methods".Length;
int last = factMessage.LastIndexOf("methods");
string str2 = factMessage.Substring(first, last - first);
Console.WriteLine($"Substring between \"methods\" and \"methods\": '{str2}'");
```

#### 使用正则表达式查找特定文本

[System.Text.RegularExpressions.Regex](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.regularexpressions.regex) 类可用于搜索字符串。 这些搜索的范围可以从简单的内容到复杂的文本模式。

下面的代码示例在一个句子中搜索了“the”或“their”（忽略大小写）。 静态方法 [Regex.IsMatch](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.regularexpressions.regex.ismatch) 执行此次搜索。 你向它提供要搜索的字符串以及搜索模式。 在这种情况下，第三个参数指定不区分大小写的搜索。 有关更多信息，请参见[System.Text.RegularExpressions.RegexOptions](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.regularexpressions.regexoptions)。

搜索模式描述你所搜索的文本。 下表描述搜索模式的每个元素。 （下表使用单个 `\`，它在 C# 字符串中必须转义为 `\\`）。

| pattern | 含义                  |
| ------- | --------------------- |
| the     | 匹配文本“the”         |
| (eir)?  | 匹配 0 个或 1 个“eir” |
| \s      | 与空白符匹配          |

```csharp
string[] sentences =
{
    "Put the water over there.",
    "They're quite thirsty.",
    "Their water bottles broke."
};

string sPattern = "the(ir)?\\s";

foreach (string s in sentences)
{
    Console.Write($"{s,24}");

    if (System.Text.RegularExpressions.Regex.IsMatch(s, sPattern, System.Text.RegularExpressions.RegexOptions.IgnoreCase))
    {
        Console.WriteLine($"  (match for '{sPattern}' found)");
    }
    else
    {
        Console.WriteLine();
    }
}
```

> 搜索精确的字符串时，`string` 方法通常是更好的选择。 正则表达式更适用于搜索是源字符串的一些模式。

#### 字符串是否遵循模式？

以下代码使用正则表达式验证数组中每个字符串的格式。 验证要求每个字符串具备电话号码的形式：用短划线分隔成三组数字，前两组包含 3 个数字，而第三组包含 4 个数字。 搜索模式采用正则表达式 `^\\d{3}-\\d{3}-\\d{4}$`。 有关更多信息，请参见[正则表达式语言 - 快速参考](https://docs.microsoft.com/zh-cn/dotnet/standard/base-types/regular-expression-language-quick-reference)。

| pattern | 含义                 |
| ------- | -------------------- |
| ^       | 匹配字符串的开头部分 |
| \d{3}   | 完全匹配 3 位字符    |
| -       | 匹配字符“-”          |
| \d{3}   | 完全匹配 3 位字符    |
| -       | 匹配字符“-”          |
| \d{4}   | 完全匹配 4 位字符    |
| $       | 匹配字符串的结尾部分 |

```csharp
string[] numbers =
{
    "123-555-0190",
    "444-234-22450",
    "690-555-0178",
    "146-893-232",
    "146-555-0122",
    "4007-555-0111",
    "407-555-0111",
    "407-2-5555",
    "407-555-8974",
    "407-2ab-5555",
    "690-555-8148",
    "146-893-232-"
};

string sPattern = "^\\d{3}-\\d{3}-\\d{4}$";

foreach (string s in numbers)
{
    Console.Write($"{s,14}");

    if (System.Text.RegularExpressions.Regex.IsMatch(s, sPattern))
    {
        Console.WriteLine(" - valid");
    }
    else
    {
        Console.WriteLine(" - invalid");
    }
}
```

此单个搜索模式匹配很多有效字符串。 正则表达式更适用于搜索或验证模式，而不是单个文本字符串。

可通过查看 [GitHub 存储库](https://github.com/dotnet/samples/tree/master/snippets/csharp/how-to/strings)中的代码来尝试这些示例。 也可以下载这些示例的 [zip 文件](https://github.com/dotnet/samples/raw/master/snippets/csharp/how-to/strings.zip)。

## [Modify string contents](https://docs.microsoft.com/en-us/dotnet/csharp/how-to/modify-string-contents)

本文演示通过修改现有 `string` 来生成 `string` 的几种方法。 演示的所有方法均将修改的结果返回为新的 `string` 对象。 为了清楚地演示这一点，所有示例均将结果存储在新的变量中。 之后，你可以检查原始 `string`和运行每个示例时从修改中得到的 `string`。

> 本文中的 C# 示例运行在 [Try.NET](https://try.dot.net/) 内联代码运行程序和演练环境中。 选择“运行”按钮以在交互窗口中运行示例。 执行代码后，可通过再次选择“运行”来修改它并运行已修改的代码。 已修改的代码要么在交互窗口中运行，要么编译失败时，交互窗口将显示所有 C# 编译器错误消息。

本文中演示了几种方法。 你可以替换现有文本。 可以搜索模式并将匹配的文本替换为其他文本。 可以将字符串视为字符序列。 还可以使用删除空格的简便方法。 应选择与你的方案最匹配的方法。

### 替换文本

下面的代码通过将现有文本替换为替代文本来创建新的字符串。

```csharp
string source = "The mountains are behind the clouds today.";

// Replace one substring with another with String.Replace.
// Only exact matches are supported.
var replacement = source.Replace("mountains", "peaks");
Console.WriteLine($"The source string is <{source}>");
Console.WriteLine($"The updated string is <{replacement}>");
```

上述代码演示了字符串的不可变属性。 在上述示例中可以看到，原始字符串 `source` 并未被修改。[String.Replace](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.replace) 方法创建的是包含修改的新 `string`。

[Replace](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.replace) 可替换字符串或单个字符。 在这两种情况下，搜索文本的每个匹配项均被替换。 下面的示例将所有的“ ”替换为“_”：

```csharp
string source = "The mountains are behind the clouds today.";

// Replace all occurrences of one char with another.
var replacement = source.Replace(' ', '_');
Console.WriteLine(source);
Console.WriteLine(replacement);
```

源字符串并未发生更改，而是通过替换操作返回了一个新的字符串。

### 去除空格

可使用 [String.Trim](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.trim)、[String.TrimStart](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.trimstart) 和 [String.TrimEnd](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.trimend) 方法删除任何前导空格或尾随空格。 下面的代码就是删除两种空格的示例。 源字符串不会发生变化；这些方法返回带修改内容的新字符串。

```csharp
// Remove trailing and leading white space.
string source = "    I'm wider than I need to be.      ";
// Store the results in a new string variable.
var trimmedResult = source.Trim();
var trimLeading = source.TrimStart();
var trimTrailing = source.TrimEnd();
Console.WriteLine($"<{source}>");
Console.WriteLine($"<{trimmedResult}>");
Console.WriteLine($"<{trimLeading}>");
Console.WriteLine($"<{trimTrailing}>");
```

### 删除文本

可使用 [String.Remove](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.remove) 方法删除字符串中的文本。 此方法移删除特定索引处开始的某些字符。 下面的示例演示如何使用 [String.IndexOf](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.indexof)（后接 [Remove](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.remove)）方法，删除字符串中的文本：

```csharp
string source = "Many mountains are behind many clouds today.";
// Remove a substring from the middle of the string.
string toRemove = "many ";
string result = string.Empty;
int i = source.IndexOf(toRemove);
if (i >= 0)
{
    result= source.Remove(i, toRemove.Length);
}
Console.WriteLine(source);
Console.WriteLine(result);
```

### 替换匹配模式

可使用[正则表达式](https://docs.microsoft.com/zh-cn/dotnet/standard/base-types/regular-expressions)将匹配模式的文本替换为新文本，新文本可能由模式定义。 下面的示例使用 [System.Text.RegularExpressions.Regex](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.regularexpressions.regex) 类从源字符串中查找模式并将其替换为正确的大写。[Regex.Replace(String, String, MatchEvaluator, RegexOptions)](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.regularexpressions.regex.replace#System_Text_RegularExpressions_Regex_Replace_System_String_System_String_System_Text_RegularExpressions_MatchEvaluator_System_Text_RegularExpressions_RegexOptions_) 方法使用将替换逻辑提供为其参数之一的函数。 在本示例中，该函数 `LocalReplaceMatchCase` 是在示例方法中声明的本地函数。 `LocalReplaceMatchCase` 使用 [System.Text.StringBuilder](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.stringbuilder)类，以生成具有正确大写的替换字符串。

正则表达式最适合用于搜索和替换遵循模式的文本，而不是已知的文本。 请参阅[如何：搜索字符串](https://docs.microsoft.com/zh-cn/dotnet/csharp/how-to/search-strings)了解详细信息。 搜索模式“the\s”搜索“the”后接空格字符的单词。 该部分的模式可确保它不与源字符串中的“there”相匹配。有关正则表达式语言元素的更多信息，请参阅[正则表达式语言 - 快速参考](https://docs.microsoft.com/zh-cn/dotnet/standard/base-types/regular-expression-language-quick-reference)。

```csharp
string source = "The mountains are still there behind the clouds today.";

// Use Regex.Replace for more flexibility. 
// Replace "the" or "The" with "many" or "Many".
// using System.Text.RegularExpressions
string replaceWith = "many ";
source = System.Text.RegularExpressions.Regex.Replace(source, "the\\s", LocalReplaceMatchCase, 
    System.Text.RegularExpressions.RegexOptions.IgnoreCase);
Console.WriteLine(source);

string LocalReplaceMatchCase(System.Text.RegularExpressions.Match matchExpression)
{
    // Test whether the match is capitalized
    if (Char.IsUpper(matchExpression.Value[0]))
    {
        // Capitalize the replacement string
        System.Text.StringBuilder replacementBuilder = new System.Text.StringBuilder(replaceWith);
        replacementBuilder[0] = Char.ToUpper(replacementBuilder[0]);
        return replacementBuilder.ToString();
    }
    else
    {
        return replaceWith;
    }
}
```

[StringBuilder.ToString](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.stringbuilder.tostring) 方法返回一个不可变的字符串，其中包含 [StringBuilder](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.stringbuilder) 对象中的内容。

### 修改单个字符

可从字符串生成字符数组，修改数组的内容，然后从数组的已修改内容创建新的字符串。

下面的示例演示如何替换字符串中的一组字符。 首先，它使用 [ToCharArray()](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.tochararray#System_String_ToCharArray) 方法来创建字符数组。 它使用 [IndexOf](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.indexof) 方法来查找单词“fox”的起始索引。 接下来的三个字符将替换为其他单词。 最终，从更新的字符串数组中构造了新的字符串。

```csharp
string phrase = "The quick brown fox jumps over the fence";
Console.WriteLine(phrase);

char[] phraseAsChars = phrase.ToCharArray();
int animalIndex = phrase.IndexOf("fox");
if (animalIndex != -1)
{
    phraseAsChars[animalIndex++] = 'c';
    phraseAsChars[animalIndex++] = 'a';
    phraseAsChars[animalIndex] = 't';
}

string updatedPhrase = new string(phraseAsChars);
Console.WriteLine(updatedPhrase);
```

### 对字符串进行不安全修改

使用不安全代码，可在创建字符串后“就地”进行修改。 不安全代码会绕过许多 .NET 旨在用于尽量减少代码中某些类型 bug 的功能。 需使用不安全代码来就地修改字符串，因为字符串类型已设计为不可变类型。 创建之后，它的值就不会更改。 不安全代码通过访问和修改 `string` 使用的内存来避开此属性，而不使用常规的 `string`方法。 下面提供了这些少数情况下的示例，因为某些时候，你可能希望使用不安全代码就地修改字符串。 示例演示如何使用 `fixed` 关键字。 `fixed` 关键字可防止垃圾回收器 (GC) 在代码使用不安全指针访问内存时移动内存中的字符串对象。 此外还演示对字符串进行不安全操作可能产生的一个副作用，此副作用是由于 C# 编译器在内部存储（暂存）字符串的方式而导致的。 通常，除非绝对必要，否则不应使用这种方法。 可在关于 [unsafe](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/unsafe) 和 [fixed](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/fixed-statement) 的文章中了解详细信息。 [Intern](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.intern) 的 API 参考包括字符串集中的信息。

```csharp
unsafe
{
    // Compiler will store (intern) 
    // these strings in same location.
    string helloOne = "Hello";
    string helloTwo = "Hello";

    // Change one string using unsafe code.
    fixed (char* p = helloOne)
    {
        p[0] = 'C';
    }

    //  Both strings have changed.
    Console.WriteLine(helloOne);
    Console.WriteLine(helloTwo);
}
```

可通过查看 [GitHub 存储库](https://github.com/dotnet/samples/tree/master/snippets/csharp/how-to/strings)中的代码来尝试这些示例。 也可以下载这些示例的 [zip 文件](https://github.com/dotnet/samples/raw/master/snippets/csharp/how-to/strings.zip)。

## [Compare strings](https://docs.microsoft.com/en-us/dotnet/csharp/how-to/compare-strings)

通过比较字符串可以回答两个问题，一个是：“这两个字符串相等吗？” 另一个是“排序时，应该按什么顺序排列这些字符串？”

这两个问题非常复杂，因为字符串比较受很多因素的影响：

- 可以选择序号比较或语义比较。
- 可以选择是否区分大小写。
- 可以选择区域性特定的比较。
- 语义比较取决于区域性和平台。

> 本文中的 C# 示例运行在 [Try.NET](https://try.dot.net/) 内联代码运行程序和演练环境中。 选择“运行”按钮以在交互窗口中运行示例。 执行代码后，可通过再次选择“运行”来修改它并运行已修改的代码。 已修改的代码要么在交互窗口中运行，要么编译失败时，交互窗口将显示所有 C# 编译器错误消息。

在比较字符串时定义它们的顺序。 通过比较决定字符串的序列。 确定序列顺序后，软件和人工都可以更轻松地进行搜索。 其他比较可能会检查字符串是否相同。 这种一致性检查与相等性检查类似，但是也有一些不同之处，例如可能会忽略大小写的差异。

### 默认的序号比较

最常见的操作：

- [String.CompareTo](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.compareto)
- [String.Equals](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.equals)
- [String.Equality](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.op_equality)

使用序号比较（一种区分大小写的比较）并使用当前区域性。 结果如下例所示：

```csharp
string root = @"C:\users";
string root2 = @"C:\Users";

bool result = root.Equals(root2);
Console.WriteLine($"Ordinal comparison: <{root}> and <{root2}> are {(result ? "equal." : "not equal.")}");

result = root.Equals(root2, StringComparison.Ordinal);
Console.WriteLine($"Ordinal comparison: <{root}> and <{root2}> are {(result ? "equal." : "not equal.")}");

Console.WriteLine($"Using == says that <{root}> and <{root2}> are {(root == root2 ? "equal" : "not equal")}");               
```

默认序号比较在比较字符串时不会考虑语义规则。 它会比较两个字符串中每个 [Char](https://docs.microsoft.com/zh-cn/dotnet/api/system.char) 对象的二进制值。 因此，默认的序号比较也是区分大小写的。

请注意，使用 [String.Equals](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.equals) 和 [String.Equality](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.op_equality) 的相等性测试不同于使用 [String.CompareTo](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.compareto) 和 [Compare(String, String)](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.compare#System_String_Compare_System_String_System_String_) 方法的字符串比较。 虽然相等性测试执行区分大小写的序号比较，但比较方法使用当前区域性执行区分大小写、区分区域性的比较。 由于默认比较方法通常执行不同类型的比较，因此建议始终调用显式指定要执行的比较类型的重载，确保代码意图明确。

### 不区分大小写的序号比较

[String.Equals(String, StringComparison)](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.equals#System_String_Equals_System_String_System_StringComparison_) 方法允许指定 [StringComparison.OrdinalIgnoreCase](https://docs.microsoft.com/zh-cn/dotnet/api/system.stringcomparison#System_StringComparison_OrdinalIgnoreCase) 的 [StringComparison](https://docs.microsoft.com/zh-cn/dotnet/api/system.stringcomparison) 值 对于不区分大小写的序号比较。 此外还有静态 [String.Compare(String, String, StringComparison)](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.compare#System_String_Compare_System_String_System_String_System_StringComparison_) 方法，该方法执行不区分大小写的序号比较，前提是你指定 [StringComparison](https://docs.microsoft.com/zh-cn/dotnet/api/system.stringcomparison) 参数的 [StringComparison.OrdinalIgnoreCase](https://docs.microsoft.com/zh-cn/dotnet/api/system.stringcomparison#System_StringComparison_OrdinalIgnoreCase) 值。 如以下代码所示：

```csharp
string root = @"C:\users";
string root2 = @"C:\Users";

bool result = root.Equals(root2, StringComparison.OrdinalIgnoreCase);
bool areEqual = String.Equals(root, root2, StringComparison.OrdinalIgnoreCase);
int comparison = String.Compare(root, root2, comparisonType: StringComparison.OrdinalIgnoreCase);

Console.WriteLine($"Ordinal ignore case: <{root}> and <{root2}> are {(result ? "equal." : "not equal.")}");
Console.WriteLine($"Ordinal static ignore case: <{root}> and <{root2}> are {(areEqual ? "equal." : "not equal.")}");
if (comparison < 0)
    Console.WriteLine($"<{root}> is less than <{root2}>");
else if (comparison > 0)
    Console.WriteLine($"<{root}> is greater than <{root2}>");
else
    Console.WriteLine($"<{root}> and <{root2}> are equivalent in order");
```

执行不区分大小写的序号比较时，这些方法使用[固定区域性](https://docs.microsoft.com/zh-cn/dotnet/api/system.globalization.cultureinfo.invariantculture#System_Globalization_CultureInfo_InvariantCulture)的大小写约定。

### 语义比较

可以使用当前区域性的语义规则来对字符串进行排序。 这有时被称为“文字排序顺序”。 在执行语义比较时，一些非字母数字的 Unicode 字符可能分配有特殊的权重。 例如，连字符“-”分配的权重可能很小，所以“co-op”和“coop”在排序顺序中会彼此相邻。 此外，一些 Unicode 字符可能与一系列 [Char](https://docs.microsoft.com/zh-cn/dotnet/api/system.char) 实例等效。 下面以德语短句“他们在街上跳舞。”为例， 在德语中，一个字符串中有“ss”(U+0073 U+0073)，另一个字符串中有“ß”(U+00DF)。 （在 Windows 系统中）从语义上说，“ss”在“en-US”和“de-DE”区域性中都等同于德语中的“'ß”。

```csharp
string first = "Sie tanzen auf der Straße.";
string second = "Sie tanzen auf der Strasse.";

Console.WriteLine($"First sentence is <{first}>");
Console.WriteLine($"Second sentence is <{second}>");

bool equal = String.Equals(first, second, StringComparison.InvariantCulture);
Console.WriteLine($"The two strings {(equal == true ? "are" : "are not")} equal.");
showComparison(first, second);

string word = "coop";
string words = "co-op";
string other = "cop";

showComparison(word, words);
showComparison(word, other);
showComparison(words, other);
void showComparison(string one, string two)
{
    int compareLinguistic = String.Compare(one, two, StringComparison.InvariantCulture);
    int compareOrdinal = String.Compare(one, two, StringComparison.Ordinal);
    if (compareLinguistic < 0)
        Console.WriteLine($"<{one}> is less than <{two}> using invariant culture");
    else if (compareLinguistic > 0)
        Console.WriteLine($"<{one}> is greater than <{two}> using invariant culture");
    else
        Console.WriteLine($"<{one}> and <{two}> are equivalent in order using invariant culture");
    if (compareOrdinal < 0)
        Console.WriteLine($"<{one}> is less than <{two}> using ordinal comparison");
    else if (compareOrdinal > 0)
        Console.WriteLine($"<{one}> is greater than <{two}> using ordinal comparison");
    else
        Console.WriteLine($"<{one}> and <{two}> are equivalent in order using ordinal comparison");
}
```

此示例说明了语义比较是依赖于操作系统的。 交互式窗口的主机为 Linux 主机。 语义比较和序号比较的结果是一样的。 如果在 Windows 主机上运行同样的示例，会看到如下输出内容：

console复制

```console
<coop> is less than <co-op> using invariant culture
<coop> is greater than <co-op> using ordinal comparison
<coop> is less than <cop> using invariant culture
<coop> is less than <cop> using ordinal comparison
<co-op> is less than <cop> using invariant culture
<co-op> is less than <cop> using ordinal comparison
```

在 Windows 上，从语义比较改为序号比较时，“cop”、“coop”和“co-op”的排序顺序产生了变化。 使用不同的比较类型时，这两个德语句子的比较结果也就不同了。

### 使用特定区域性的比较

此示例为 en-US 和 de-DE 区域性存储 [CultureInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.globalization.cultureinfo) 对象。 使用 [CultureInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.globalization.cultureinfo) 对象执行比较以确保执行的是特定于区域性的比较。

所用的区域性会对语义比较产生影响。 以下示例展示使用“en-US”区域性和“de-DE”区域性对两个德语句子进行比较的结果：

```csharp
string first = "Sie tanzen auf der Straße.";
string second = "Sie tanzen auf der Strasse.";

Console.WriteLine($"First sentence is <{first}>");
Console.WriteLine($"Second sentence is <{second}>");

var en = new System.Globalization.CultureInfo("en-US");

// For culture-sensitive comparisons, use the String.Compare 
// overload that takes a StringComparison value.
int i = String.Compare(first, second, en, System.Globalization.CompareOptions.None);
Console.WriteLine($"Comparing in {en.Name} returns {i}.");

var de = new System.Globalization.CultureInfo("de-DE");
i = String.Compare(first, second, de, System.Globalization.CompareOptions.None);
Console.WriteLine($"Comparing in {de.Name} returns {i}.");

bool b = String.Equals(first, second, StringComparison.CurrentCulture);
Console.WriteLine($"The two strings {(b ? "are" : "are not")} equal.");

string word = "coop";
string words = "co-op";
string other = "cop";

showComparison(word, words, en);
showComparison(word, other, en);
showComparison(words, other, en);
void showComparison(string one, string two, System.Globalization.CultureInfo culture)
{
    int compareLinguistic = String.Compare(one, two, en, System.Globalization.CompareOptions.None);
    int compareOrdinal = String.Compare(one, two, StringComparison.Ordinal);
    if (compareLinguistic < 0)
        Console.WriteLine($"<{one}> is less than <{two}> using en-US culture");
    else if (compareLinguistic > 0)
        Console.WriteLine($"<{one}> is greater than <{two}> using en-US culture");
    else
        Console.WriteLine($"<{one}> and <{two}> are equivalent in order using en-US culture");
    if (compareOrdinal < 0)
        Console.WriteLine($"<{one}> is less than <{two}> using ordinal comparison");
    else if (compareOrdinal > 0)
        Console.WriteLine($"<{one}> is greater than <{two}> using ordinal comparison");
    else
        Console.WriteLine($"<{one}> and <{two}> are equivalent in order using ordinal comparison");
}
```

区分区域性的比较通常用于对用户输入的字符串以及用户输入的其他字符串进行比较和排序。 字符和这些字符的排序约定可能会根据用户计算机的区域设置而有所不同。 即使是包含相同字符的字符串，也可能因当前线程的区域性而具有不同的排序。 此外，请在本地 Windows 计算机上尝试下列示例代码，将得到下列结果：

console复制

```console
<coop> is less than <co-op> using en-US culture
<coop> is greater than <co-op> using ordinal comparison
<coop> is less than <cop> using en-US culture
<coop> is less than <cop> using ordinal comparison
<co-op> is less than <cop> using en-US culture
<co-op> is less than <cop> using ordinal comparison
```

语义比较取决于当前区域性以及操作系统。 在进行字符串比较时，需要考虑这些内容。

### 数组中的语义排序和字符串搜索

以下示例演示如何在数组中使用依赖当前区域性的语义比较对字符串进行排序和搜索。 使用采用 [System.StringComparer](https://docs.microsoft.com/zh-cn/dotnet/api/system.stringcomparer) 参数的静态 [Array](https://docs.microsoft.com/zh-cn/dotnet/api/system.array) 方法。

此示例演示如何使用当前区域性对字符串数组进行排序：

```csharp
string[] lines = new string[]
{
    @"c:\public\textfile.txt",
    @"c:\public\textFile.TXT",
    @"c:\public\Text.txt",
    @"c:\public\testfile2.txt"
};

Console.WriteLine("Non-sorted order:");
foreach (string s in lines)
{
    Console.WriteLine($"   {s}");
}

Console.WriteLine("\n\rSorted order:");

// Specify Ordinal to demonstrate the different behavior.
Array.Sort(lines, StringComparer.CurrentCulture);

foreach (string s in lines)
{
    Console.WriteLine($"   {s}");
}
```

对数组进行排序后，可以使用二分搜索法搜索条目。 二分搜索法从集合的中间开始搜索，判断集合的哪一半包含所找字符串。 后续的每个比较都将集合的剩余部分再次对半分开。 使用 [StringComparer.CurrentCulture](https://docs.microsoft.com/zh-cn/dotnet/api/system.stringcomparer.currentculture#System_StringComparer_CurrentCulture) 存储数组。 本地函数 `ShowWhere` 显示发现字符串所在位置的信息。 如果未找到字符串，返回的值会指示它可能会在的位置（如果找到）。

C#复制运行

```csharp
string[] lines = new string[]
{
    @"c:\public\textfile.txt",
    @"c:\public\textFile.TXT",
    @"c:\public\Text.txt",
    @"c:\public\testfile2.txt"
};
Array.Sort(lines, StringComparer.CurrentCulture);

string searchString = @"c:\public\TEXTFILE.TXT";
Console.WriteLine($"Binary search for <{searchString}>");
int result = Array.BinarySearch(lines, searchString, StringComparer.CurrentCulture);
ShowWhere<string>(lines, result);

Console.WriteLine($"{(result > 0 ? "Found" : "Did not find")} {searchString}");

void ShowWhere<T>(T[] array, int index)
{
    if (index < 0)
    {
        index = ~index;

        Console.Write("Not found. Sorts between: ");

        if (index == 0)
            Console.Write("beginning of sequence and ");
        else
            Console.Write($"{array[index - 1]} and ");

        if (index == array.Length)
            Console.WriteLine("end of sequence.");
        else
            Console.WriteLine($"{array[index]}.");
    }
    else
    {
        Console.WriteLine($"Found at index {index}.");
    }
}
```

### 集合中的序号排序和搜索

以下代码使用 [System.Collections.Generic.List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1) 集合类存储字符串。 字符串是通过 [List.Sort](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1.sort) 方法排序的。此方法需要对两个字符串进行比较和排序的委托。 [String.CompareTo](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.compareto) 方法提供该比较函数。 请运行示例并观察顺序。 此排序操作使用区分大小写的序号排序。 你要使用静态 [String.Compare](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.compare) 方法指定不同的比较规则。

```csharp
List<string> lines = new List<string>
{
    @"c:\public\textfile.txt",
    @"c:\public\textFile.TXT",
    @"c:\public\Text.txt",
    @"c:\public\testfile2.txt"
};

Console.WriteLine("Non-sorted order:");
foreach (string s in lines)
{
    Console.WriteLine($"   {s}");
}

Console.WriteLine("\n\rSorted order:");

lines.Sort((left, right) => left.CompareTo(right)); 
foreach (string s in lines)
{
    Console.WriteLine($"   {s}");
}
```

排序后，可以使用二分搜索法对字符串列表进行搜索。 以下示例演示如何使用相同的比较函数搜索排序列表。本地函数 `ShowWhere` 显示所查找的文本所在的位置或可能会在位置：

C#复制运行

```csharp
List<string> lines = new List<string>
{
    @"c:\public\textfile.txt",
    @"c:\public\textFile.TXT",
    @"c:\public\Text.txt",
    @"c:\public\testfile2.txt"
};
lines.Sort((left, right) => left.CompareTo(right));

string searchString = @"c:\public\TEXTFILE.TXT";
Console.WriteLine($"Binary search for <{searchString}>");
int result = lines.BinarySearch(searchString);
ShowWhere<string>(lines, result);

Console.WriteLine($"{(result > 0 ? "Found" : "Did not find")} {searchString}");

void ShowWhere<T>(IList<T> collection, int index)
{
    if (index < 0)
    {
        index = ~index;

        Console.Write("Not found. Sorts between: ");

        if (index == 0)
            Console.Write("beginning of sequence and ");
        else
            Console.Write($"{collection[index - 1]} and ");

        if (index == collection.Count)
            Console.WriteLine("end of sequence.");
        else
            Console.WriteLine($"{collection[index]}.");
    }
    else
    {
        Console.WriteLine($"Found at index {index}.");
    }
}
```

在排序和搜索过程中，请始终确保使用相同的比较类型。 使用不同的比较类型进行排序和搜索会产生意外的结果。

元素或键的类型为 `string` 时，[System.Collections.Hashtable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.hashtable)、[System.Collections.Generic.Dictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.dictionary-2) 和 [System.Collections.Generic.List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1) 等集合类的构造函数具有 [System.StringComparer](https://docs.microsoft.com/zh-cn/dotnet/api/system.stringcomparer) 参数。 通常，应尽可能使用这些构造函数，并指定 [StringComparer.Ordinal](https://docs.microsoft.com/zh-cn/dotnet/api/system.stringcomparer.ordinal#System_StringComparer_Ordinal) 或 [StringComparer.OrdinalIgnoreCase](https://docs.microsoft.com/zh-cn/dotnet/api/system.stringcomparer.ordinalignorecase#System_StringComparer_OrdinalIgnoreCase)。

### 引用相等性和字符串集中

这些示例都没有使用 [ReferenceEquals](https://docs.microsoft.com/zh-cn/dotnet/api/system.object.referenceequals)。 此方法确定两个字符串是否为相同的对象。 这可能会在字符串比较中产生不一致的结果。 以下示例演示了 C# 中的字符串集中功能。 如果程序声明了 2 个或多个相同的字符串变量，则编译器会将其存储在同一位置。 通过调用 [ReferenceEquals](https://docs.microsoft.com/zh-cn/dotnet/api/system.object.referenceequals) 方法，可以看到这两个字符串实际上引用的是内存中的同一对象。 使用 [String.Copy](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.copy) 方法可避免集中。 创建副本后，两个字符串存储在不同位置（即使它们具有相同的值）。 运行下列示例以显示字符串 `a` 和 `b` 是集中的，也就是说它们共享相同的存储。 字符串 `a` 和 `c` 不是。

```csharp
string a = "The computer ate my source code.";
string b = "The computer ate my source code.";

if (String.ReferenceEquals(a, b))
    Console.WriteLine("a and b are interned.");
else
    Console.WriteLine("a and b are not interned.");

string c = String.Copy(a);

if (String.ReferenceEquals(a, c))
    Console.WriteLine("a and c are interned.");
else
    Console.WriteLine("a and c are not interned.");
```

> 测试字符串是否相等时，使用的方法应显式指定要执行的比较类型。 你的代码具备更强的可维护性和可读性。 重载采用了 [StringComparison](https://docs.microsoft.com/zh-cn/dotnet/api/system.stringcomparison) 枚举参数的 [System.String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string) 和 [System.Array](https://docs.microsoft.com/zh-cn/dotnet/api/system.array) 类的方法。 指定要执行的比较类型。 在测试相等性时，请避免使用 `==` 和 `!=` 运算符。 [String.CompareTo](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.compareto) 实例方法始终执行区分大小写的序号比较。 它们主要适用于按字母顺序进行的字符串排序。

可以通过调用 [String.Intern](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.intern) 方法暂存字符串或检索对现有暂存字符串的引用。 要确定字符串是否暂存，请调用 [String.IsInterned](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.isinterned) 方法。

## [Safely cast using pattern matching, is and as operators](https://docs.microsoft.com/en-us/dotnet/csharp/how-to/safely-cast-using-pattern-matching-is-and-as-operators)

由于是多态对象，基类类型的变量可以保存派生[类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/types/index)。 要访问派生类型的实例成员，必须将值[强制转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/types/casting-and-type-conversions)回派生类型。 但是，强制转换会引发 [InvalidCastException](https://docs.microsoft.com/zh-cn/dotnet/api/system.invalidcastexception) 风险。 C# 提供[模式匹配](https://docs.microsoft.com/zh-cn/dotnet/csharp/pattern-matching)语句，该语句只有在成功时才会有条件地执行强制转换。 C# 还提供 [is](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/is) 和 [as](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/as) 运算符来测试值是否属于特定类型。

> 本文中的 C# 示例运行在 [Try.NET](https://try.dot.net/) 内联代码运行程序和演练环境中。 选择“运行”按钮以在交互窗口中运行示例。 执行代码后，可通过再次选择“运行”来修改它并运行已修改的代码。 已修改的代码要么在交互窗口中运行，要么编译失败时，交互窗口将显示所有 C# 编译器错误消息。

下面的代码演示模式匹配 `is` 语句。 它包含测试方法参数的方法，以确定它是否是一组可能的派生类型：

```csharp
class Animal
{
    public void Eat() { Console.WriteLine("Eating."); }
    public override string ToString()
    {
        return "I am an animal.";
    }
}
class Mammal : Animal { }
class Giraffe : Mammal { }

class SuperNova { }

class Program
{
    static void Main(string[] args)
    {
        Giraffe g = new Giraffe();
        FeedMammals(g);

        TestForMammals(g);

        SuperNova sn = new SuperNova();
        TestForMammals(sn);
    }

    static void FeedMammals(Animal a)
    {
        // Use the is operator to verify the type
        // before performing a cast.
        if (a is Mammal m)
        {
            m.Eat();
        }
    }

    static void TestForMammals(object o)
    {
        // Alternatively, use the as operator and test for null
        // before referencing the variable.
        if (o is Mammal m)
        {
            Console.WriteLine(m.ToString());
        }
        else
        {
            // variable 'm' is not in scope here, and can't be used.
            Console.WriteLine($"{o.GetType().Name} is not a Mammal");
        }
    }
}
```

前面的示例演示了模式匹配语法的一些功能。 `if (a is Mammal m)` 和 `if (o is Mammal m)` 语句将测试与初始化赋值相结合。 只有在测试成功时才会进行赋值。 变量 `m` 仅在已赋值的嵌入式 `if` 语句的范围内。 以后无法在同一方法中访问 `m`。 在交互式窗口中尝试操作。

也可以使用同一语法来测试[可以为 null 的类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/nullable-types/index)是否具有值，如以下示例代码所示：

```csharp
class Program
{
    static void Main(string[] args)
    {
        // Use the as operator with a value type.
        // Note the implicit conversion to int? in 
        // the method body.
        int i = 5;
        PatternMatchingNullable(i);

        int? j = null;
        PatternMatchingNullable(j);

        double d = 9.78654;
        PatternMatchingNullable(d);

        PatternMatchingSwitch(i);
        PatternMatchingSwitch(j);
        PatternMatchingSwitch(d);
    }

    static void PatternMatchingNullable(System.ValueType val)
    {
        if (val is int j) // Nullable types are not allowed in patterns
        {
            Console.WriteLine(j);
        }
        else if (val is null) // If val is a nullable type with no value, this expression is true
        {
            Console.WriteLine("val is a nullable type with the null value");
        }
        else
        {
            Console.WriteLine("Could not convert " + val.ToString());
        }
    }

    static void PatternMatchingSwitch(System.ValueType val)
    {
        switch (val)
        {
            case int number:
                Console.WriteLine(number);
                break;
            case long number:
                Console.WriteLine(number);
                break;
            case decimal number:
                Console.WriteLine(number);
                break;
            case float number:
                Console.WriteLine(number);
                break;
            case double number:
                Console.WriteLine(number);
                break;
            case null:
                Console.WriteLine("val is a nullable type with the null value");
                break;
            default:
                Console.WriteLine("Could not convert " + val.ToString());
                break;
        }
    }
}
```

前面的示例演示了模式匹配用于转换的其他功能。 可以通过专门检查 `null` 值来测试 NULL 模式的变量。 当变量的运行时值为 `null` 时，用于检查类型的 `is` 语句始终返回 `false`。 模式匹配 `is` 语句不允许可以为 null 值的类型，如 `int?` 或 `Nullable<int>`，但你可以测试任何其他值类型。

前面的示例还演示如何在变量为其他类型的 `switch` 语句中使用模式匹配 `is` 表达式。

如果想要测试变量是否为给定类型，但不将其分配给新变量，则可以对引用类型和可以为 null 的类型使用 `is`和 `as` 运算符。 以下代码演示如何在引入模式匹配以测试变量是否为给定类型前，使用 C# 语言中的 `is` 和 `as` 语句：

```csharp
class Animal
{
    public void Eat() { Console.WriteLine("Eating."); }
    public override string ToString()
    {
        return "I am an animal.";
    }
}
class Mammal : Animal { }
class Giraffe : Mammal { }

class SuperNova { }


class Program
{
    static void Main(string[] args)
    {
        // Use the is operator to verify the type.
        // before performing a cast.
        Giraffe g = new Giraffe();
        UseIsOperator(g);

        // Use the as operator and test for null
        // before referencing the variable.
        UseAsOperator(g);

        // Use the as operator to test
        // an incompatible type.
        SuperNova sn = new SuperNova();
        UseAsOperator(sn);

        // Use the as operator with a value type.
        // Note the implicit conversion to int? in 
        // the method body.
        int i = 5;
        UseAsWithNullable(i);

        double d = 9.78654;
        UseAsWithNullable(d);
    }

    static void UseIsOperator(Animal a)
    {
        if (a is Mammal)
        {
            Mammal m = (Mammal)a;
            m.Eat();
        }
    }

    static void UsePatternMatchingIs(Animal a)
    {
        if (a is Mammal m)
        {
            m.Eat();
        }
    }

    static void UseAsOperator(object o)
    {
        Mammal m = o as Mammal;
        if (m != null)
        {
            Console.WriteLine(m.ToString());
        }
        else
        {
            Console.WriteLine($"{o.GetType().Name} is not a Mammal");
        }
    }

    static void UseAsWithNullable(System.ValueType val)
    {
        int? j = val as int?;
        if (j != null)
        {
            Console.WriteLine(j);
        }
        else
        {
            Console.WriteLine("Could not convert " + val.ToString());
        }
    }
}
```

正如你所看到的，将此代码与模式匹配代码进行比较，模式匹配语法通过在单个语句中结合测试和赋值来提供更强大的功能。 尽量使用模式匹配语法。

可通过查看 [GitHub 存储库](https://github.com/dotnet/samples/tree/master/snippets/csharp/how-to/safelycast)中的代码来尝试这些示例。 也可以下载这些示例的 [zip 文件](https://github.com/dotnet/samples/raw/master/snippets/csharp/how-to/safelycast.zip)。