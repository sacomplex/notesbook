# [LINQ to Objects](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/linqtoobjects)

术语“LINQ to Objects”指直接将 LINQ 查询与任何 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable) 或 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 集合一起使用，而不使用中间 LINQ 提供程序或 API，例如 [LINQ to SQL](https://docs.microsoft.com/zh-cn/dotnet/framework/data/adonet/sql/linq/index) 或 [LINQ to XML](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/linq-to-xml)。 可以使用 LINQ 来查询任何可枚举的集合，例如[List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1)、[Array](https://docs.microsoft.com/zh-cn/dotnet/api/system.array) 或 [Dictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.dictionary-2)。 该集合可以是用户定义的集合，也可以是由 .NET Framework API 返回的集合。

从根本上说，“LINQ to Objects”表示一种新的处理集合的方法。 采用旧方法，必须编写指定如何从集合检索数据的复杂的 `foreach` 循环。 而采用 LINQ 方法，只需编写描述要检索的内容的声明性代码。

此外，LINQ 查询与传统 `foreach` 循环相比具有三大优势：

1. 它们更简明、更易读，尤其在筛选多个条件时。
2. 它们使用最少的应用程序代码提供强大的筛选、排序和分组功能。
3. 无需修改或只需做很小的修改即可将它们移植到其他数据源。

通常，对数据执行的操作越复杂，就越能体会到 LINQ 相较于传统迭代技术的优势。

本节的目的是使用一些精选示例来演示 LINQ 方法。 并不打算详尽说明。

## 本节内容

[LINQ 和字符串 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/linq-and-strings)
阐释如何使用 LINQ 来查询和转换字符串和字符串集合。 还包括指向演示这些原则的主题的链接。

[LINQ 和反射 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/linq-and-reflection)
指向演示 LINQ 如何使用反射的示例的链接。

[LINQ 和文件目录 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/linq-and-file-directories)
阐释如何使用 LINQ 来与文件系统进行交互。 还包括指向演示这些概念的主题的链接。

[如何：使用 LINQ 查询 ArrayList (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-query-an-arraylist-with-linq)
演示如何使用 C# 查询 ArrayList。

[如何：为 LINQ 查询添加自定义方法 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-add-custom-methods-for-linq-queries)
阐释如何通过向 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 接口中添加扩展方法来扩展可用于 LINQ 查询的方法集。

[语言集成查询 (LINQ) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/index)
提供指向阐释 LINQ 并提供执行查询的代码示例的主题的链接。

## [LINQ and Strings](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/linqandstrings)

### [How to: Count Occurrences of a Word in a String (LINQ)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtocountoccurrencesofawordinastringlinq)

此示例演示如何使用 LINQ 查询对指定词在字符串中出现的次数进行计数。 请注意，若要执行计数，首先需调用[Split](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.split) 方法来创建词数组。 [Split](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.split) 方法存在性能开销。 如果只需要统计字符串的字数，则应考虑改用 [Matches](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.regularexpressions.regex.matches) 或[IndexOf](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.indexof) 方法。 但是，如果性能不是关键问题，或者已拆分句子以对其执行其他类型的查询，则使用 LINQ 来计数词或短语同样有意义。

#### 示例

```csharp
class CountWords  
{  
    static void Main()  
    {  
        string text = @"Historically, the world of data and the world of objects" +  
          @" have not been well integrated. Programmers work in C# or Visual Basic" +  
          @" and also in SQL or XQuery. On the one side are concepts such as classes," +  
          @" objects, fields, inheritance, and .NET Framework APIs. On the other side" +  
          @" are tables, columns, rows, nodes, and separate languages for dealing with" +  
          @" them. Data types often require translation between the two worlds; there are" +  
          @" different standard functions. Because the object world has no notion of query, a" +  
          @" query can only be represented as a string without compile-time type checking or" +  
          @" IntelliSense support in the IDE. Transferring data from SQL tables or XML trees to" +  
          @" objects in memory is often tedious and error-prone.";  
  
        string searchTerm = "data";  
  
        //Convert the string into an array of words  
        string[] source = text.Split(new char[] { '.', '?', '!', ' ', ';', ':', ',' }, StringSplitOptions.RemoveEmptyEntries);  
  
        // Create the query.  Use ToLowerInvariant to match "data" and "Data"   
        var matchQuery = from word in source  
                         where word.ToLowerInvariant() == searchTerm.ToLowerInvariant()  
                         select word;  
  
        // Count the matches, which executes the query.  
        int wordCount = matchQuery.Count();  
        Console.WriteLine("{0} occurrences(s) of the search term \"{1}\" were found.", wordCount, searchTerm);  
  
        // Keep console window open in debug mode  
        Console.WriteLine("Press any key to exit");  
        Console.ReadKey();  
    }  
}  
/* Output:  
   3 occurrences(s) of the search term "data" were found.  
*/  
```

#### 编译代码

创建面向 .NET Framework 3.5 或更高版本的项目，此项目包含对 System.Core.dll 的引用和针对 System.Linq 和 System.IO 命名空间的 `using` 指令。

### [How to: Query for Sentences that Contain a Specified Set of Words (LINQ)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoqueryforsentencesthatcontainaspecifiedsetofwordslinq)

此示例演示如何在包含一组指定的词语的每个匹配项的文本文件中查找句子。 尽管此示例中的搜索词数组采用硬编码形式，但它也可在运行时以动态方式进行填充。 在此示例中，查询将返回包含单词“Historically,”、“data,”和“integrated”的句子。

#### 示例

```csharp
class FindSentences  
{  
    static void Main()  
    {  
        string text = @"Historically, the world of data and the world of objects " +  
        @"have not been well integrated. Programmers work in C# or Visual Basic " +  
        @"and also in SQL or XQuery. On the one side are concepts such as classes, " +  
        @"objects, fields, inheritance, and .NET Framework APIs. On the other side " +  
        @"are tables, columns, rows, nodes, and separate languages for dealing with " +  
        @"them. Data types often require translation between the two worlds; there are " +  
        @"different standard functions. Because the object world has no notion of query, a " +  
        @"query can only be represented as a string without compile-time type checking or " +  
        @"IntelliSense support in the IDE. Transferring data from SQL tables or XML trees to " +  
        @"objects in memory is often tedious and error-prone.";  
  
        // Split the text block into an array of sentences.  
        string[] sentences = text.Split(new char[] { '.', '?', '!' });  
  
        // Define the search terms. This list could also be dynamically populated at runtime.  
        string[] wordsToMatch = { "Historically", "data", "integrated" };  
  
        // Find sentences that contain all the terms in the wordsToMatch array.  
        // Note that the number of terms to match is not specified at compile time.  
        var sentenceQuery = from sentence in sentences  
                            let w = sentence.Split(new char[] { '.', '?', '!', ' ', ';', ':', ',' },  
                                                    StringSplitOptions.RemoveEmptyEntries)  
                            where w.Distinct().Intersect(wordsToMatch).Count() == wordsToMatch.Count()  
                            select sentence;  
  
        // Execute the query. Note that you can explicitly type  
        // the iteration variable here even though sentenceQuery  
        // was implicitly typed.   
        foreach (string str in sentenceQuery)  
        {  
            Console.WriteLine(str);  
        }  
  
        // Keep the console window open in debug mode.  
        Console.WriteLine("Press any key to exit");  
        Console.ReadKey();  
    }  
}  
/* Output:  
Historically, the world of data and the world of objects have not been well integrated  
*/  
```

查询运行时首先将文本拆分成句子，然后将句子拆分成包含每个单词的字符串数组。 对于每个数组，[Distinct](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.distinct) 方法将删除所有重复字词，然后查询将对字词数组和 `wordsToMatch` 数组执行 [Intersect](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.intersect) 操作。 如果相交数与 `wordsToMatch` 数组的计数相同，将在单词中找到所有单词并返回原始句子。

在对 [Split](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.split) 的调用中，使用标点符号作为分隔符，以从字符串中删除标点符号。 如果你没有不这样做，则假如你有一个字符串 “Historically,”，该字符串不会与 `wordsToMatch` 数组中的“Historically”匹配。 根据在源文本中找到的标点类型，可能需要使用其他分隔符。

#### 编译代码

创建面向 .NET Framework 3.5 或更高版本的项目，此项目包含对 System.Core.dll 的引用和针对 System.Linq 和 System.IO 命名空间的 `using` 指令。

### [How to: Query for Characters in a String (LINQ)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoqueryforcharactersinastringlinq)

因为 [String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string) 类可实现泛型 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 接口，因此任何字符串都可以字符序列的形式进行查询。 但是，这不是 LINQ 的一般用法。 对于复杂的模式匹配操作，请使用 [Regex](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.regularexpressions.regex) 类。

#### 示例

以下示例查询一个字符串以确定它所包含的数字数量。 请注意，在第一次执行此查询后将“重用”此查询。 这是可能的，因为查询本身并不存储任何实际的结果。

```csharp
class QueryAString  
{  
    static void Main()  
    {  
        string aString = "ABCDE99F-J74-12-89A";  
  
        // Select only those characters that are numbers  
        IEnumerable<char> stringQuery =  
          from ch in aString  
          where Char.IsDigit(ch)  
          select ch;  
  
        // Execute the query  
        foreach (char c in stringQuery)  
            Console.Write(c + " ");  
  
        // Call the Count method on the existing query.  
        int count = stringQuery.Count();  
        Console.WriteLine("Count = {0}", count);  
  
        // Select all characters before the first '-'  
        IEnumerable<char> stringQuery2 = aString.TakeWhile(c => c != '-');  
  
        // Execute the second query  
        foreach (char c in stringQuery2)  
            Console.Write(c);  
  
        Console.WriteLine(System.Environment.NewLine + "Press any key to exit");  
        Console.ReadKey();  
    }  
}  
/* Output:  
  Output: 9 9 7 4 1 2 8 9  
  Count = 8  
  ABCDE99F  
*/  
```

#### 编译代码

创建面向 .NET Framework 3.5 或更高版本的项目，此项目包含对 System.Core.dll 的引用和针对 System.Linq 和 System.IO 命名空间的 `using` 指令。

### [How to: Combine LINQ Queries with Regular Expressions](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtocombinelinqquerieswithregularexpressions)

此示例演示如何使用 [Regex](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.regularexpressions.regex) 类在文本字符串中为更复杂的匹配创建正则表达式。 通过 LINQ 查询可以轻松地准确筛选要用正则表达式搜索的文件，并对结果进行改良。

#### 示例

```csharp
class QueryWithRegEx  
{  
    public static void Main()  
    {  
        // Modify this path as necessary so that it accesses your version of Visual Studio.  
        string startFolder = @"C:\Program Files (x86)\Microsoft Visual Studio 14.0\";  
        // One of the following paths may be more appropriate on your computer.  
        //string startFolder = @"C:\Program Files (x86)\Microsoft Visual Studio\2017\";  
  
        // Take a snapshot of the file system.  
        IEnumerable<System.IO.FileInfo> fileList = GetFiles(startFolder);  
  
        // Create the regular expression to find all things "Visual".  
        System.Text.RegularExpressions.Regex searchTerm =  
            new System.Text.RegularExpressions.Regex(@"Visual (Basic|C#|C\+\+|Studio)");  
  
        // Search the contents of each .htm file.  
        // Remove the where clause to find even more matchedValues!  
        // This query produces a list of files where a match  
        // was found, and a list of the matchedValues in that file.  
        // Note: Explicit typing of "Match" in select clause.  
        // This is required because MatchCollection is not a   
        // generic IEnumerable collection.  
        var queryMatchingFiles =  
            from file in fileList  
            where file.Extension == ".htm"  
            let fileText = System.IO.File.ReadAllText(file.FullName)  
            let matches = searchTerm.Matches(fileText)  
            where matches.Count > 0  
            select new  
            {  
                name = file.FullName,  
                matchedValues = from System.Text.RegularExpressions.Match match in matches  
                                select match.Value  
            };  
  
        // Execute the query.  
        Console.WriteLine("The term \"{0}\" was found in:", searchTerm.ToString());  
  
        foreach (var v in queryMatchingFiles)  
        {  
            // Trim the path a bit, then write   
            // the file name in which a match was found.  
            string s = v.name.Substring(startFolder.Length - 1);  
            Console.WriteLine(s);  
  
            // For this file, write out all the matching strings  
            foreach (var v2 in v.matchedValues)  
            {  
                Console.WriteLine("  " + v2);  
            }  
        }  
  
        // Keep the console window open in debug mode  
        Console.WriteLine("Press any key to exit");  
        Console.ReadKey();  
    }  
  
    // This method assumes that the application has discovery   
    // permissions for all folders under the specified path.  
    static IEnumerable<System.IO.FileInfo> GetFiles(string path)  
    {  
        if (!System.IO.Directory.Exists(path))  
            throw new System.IO.DirectoryNotFoundException();  
  
        string[] fileNames = null;  
        List<System.IO.FileInfo> files = new List<System.IO.FileInfo>();  
  
        fileNames = System.IO.Directory.GetFiles(path, "*.*", System.IO.SearchOption.AllDirectories);  
        foreach (string name in fileNames)  
        {  
            files.Add(new System.IO.FileInfo(name));  
        }  
        return files;  
    }  
}  
```

请注意，还可以查询 `RegEx` 搜索返回的 [MatchCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.regularexpressions.matchcollection) 对象。 在本例中，只在结果中生成每个匹配项的值。但是，也可以使用 LINQ 对集合执行筛选、排序和分组等各种操作。 由于 [MatchCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.regularexpressions.matchcollection) 为非泛型 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable)集合，所以必须显式声明查询中范围变量的类型。

#### 编译代码

创建面向 .NET Framework 3.5 或更高版本的项目，此项目包含对 System.Core.dll 的引用和针对 System.Linq 和 System.IO 命名空间的 `using` 指令。

### [How to: Find the Set Difference Between Two Lists (LINQ)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtofindthesetdifferencebetweentwolistslinq)

此示例演示如何使用 LINQ 对两个字符串列表进行比较，并输出那些位于 names1.txt 中但不在 names2.txt 中的行。

#### 创建数据文件

1. 按照[如何：组合和比较字符串集合 (LINQ) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-combine-and-compare-string-collections-linq) 中的说明，将 names1.txt 和 names2.txt 复制到解决方案文件夹中。

#### 示例

```csharp
class CompareLists  
{          
    static void Main()  
    {  
        // Create the IEnumerable data sources.  
        string[] names1 = System.IO.File.ReadAllLines(@"../../../names1.txt");  
        string[] names2 = System.IO.File.ReadAllLines(@"../../../names2.txt");  
  
        // Create the query. Note that method syntax must be used here.  
        IEnumerable<string> differenceQuery =  
          names1.Except(names2);  
  
        // Execute the query.  
        Console.WriteLine("The following lines are in names1.txt but not names2.txt");  
        foreach (string s in differenceQuery)  
            Console.WriteLine(s);  
  
        // Keep the console window open in debug mode.  
        Console.WriteLine("Press any key to exit");  
        Console.ReadKey();  
    }  
}  
/* Output:  
     The following lines are in names1.txt but not names2.txt  
    Potra, Cristina  
    Noriega, Fabricio  
    Aw, Kam Foo  
    Toyoshima, Tim  
    Guy, Wey Yuan  
    Garcia, Debra  
     */  
```

C# 中某些类型的查询操作（例如 [Except](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.except)、[Distinct](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.distinct)、[Union](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.union) 和 [Concat](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.concat)）只能用基于方法的语法表示。

#### 编译代码

创建面向 .NET Framework 3.5 或更高版本的项目，此项目包含对 System.Core.dll 的引用和针对 System.Linq 和 System.IO 命名空间的 `using` 指令。

### [How to: Sort or Filter Text Data by Any Word or Field (LINQ)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtosortorfiltertextdatabyanywordorfieldlinq)

下面的示例演示如何按行中的任何字段对结构化文本（如以逗号分隔的值）行进行排序。 可以在运行时动态指定字段。 假定 scores.csv 中的字段表示学生的 ID 号，后跟一系列四个测试分数。

#### 创建包含数据的文件

1. 从主题[如何：联接不同文件的内容 (LINQ) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-join-content-from-dissimilar-files-linq) 复制 scores.csv 数据并将它保存到解决方案文件夹。

#### 示例

```csharp
public class SortLines  
{  
    static void Main()  
    {  
        // Create an IEnumerable data source  
        string[] scores = System.IO.File.ReadAllLines(@"../../../scores.csv");  
  
        // Change this to any value from 0 to 4.  
        int sortField = 1;  
  
        Console.WriteLine("Sorted highest to lowest by field [{0}]:", sortField);  
  
        // Demonstrates how to return query from a method.  
        // The query is executed here.  
        foreach (string str in RunQuery(scores, sortField))  
        {  
            Console.WriteLine(str);  
        }  
  
        // Keep the console window open in debug mode.  
        Console.WriteLine("Press any key to exit");  
        Console.ReadKey();  
    }  
  
    // Returns the query variable, not query results!  
    static IEnumerable<string> RunQuery(IEnumerable<string> source, int num)  
    {  
        // Split the string and sort on field[num]  
        var scoreQuery = from line in source  
                         let fields = line.Split(',')  
                         orderby fields[num] descending  
                         select line;  
  
        return scoreQuery;  
    }  
}  
/* Output (if sortField == 1):  
   Sorted highest to lowest by field [1]:  
    116, 99, 86, 90, 94  
    120, 99, 82, 81, 79  
    111, 97, 92, 81, 60  
    114, 97, 89, 85, 82  
    121, 96, 85, 91, 60  
    122, 94, 92, 91, 91  
    117, 93, 92, 80, 87  
    118, 92, 90, 83, 78  
    113, 88, 94, 65, 91  
    112, 75, 84, 91, 39  
    119, 68, 79, 88, 92  
    115, 35, 72, 91, 70  
 */  
```

此示例还演示如何从方法返回查询变量。

#### 编译代码

创建面向 .NET Framework 3.5 或更高版本的项目，此项目包含对 System.Core.dll 的引用和针对 System.Linq 和 System.IO 命名空间的 `using` 指令。

### [How to: Reorder the Fields of a Delimited File (LINQ)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoreorderthefieldsofadelimitedfilelinq)

逗号分隔值 (CSV) 文件是一种文本文件，通常用于存储电子表格数据或其他由行和列表示的表格数据。 通过使用[Split](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.split) 方法分隔字段，可以非常轻松地使用 LINQ 来查询和操作 CSV 文件。 事实上，可以使用此技术来重新排列任何结构化文本行部分；此技术不局限于 CSV 文件。

在下面的示例中，假设有三列分别代表学生的“姓氏”、“名字”和“ID”。 这些字段基于学生的姓氏按字母顺序排列。查询生成一个新序列，其中首先出现的是 ID 列，后面的第二列组合了学生的名字和姓氏。 根据 ID 字段重新排列各行。 结果保存到新文件，但不修改原始数据。

#### 创建数据文件

1. 将以下各行复制到名为 spreadsheet1.csv 的纯文本文件。 将此文件保存到项目文件夹。

   ```
   Adams,Terry,120  
   Fakhouri,Fadi,116  
   Feng,Hanying,117  
   Garcia,Cesar,114  
   Garcia,Debra,115  
   Garcia,Hugo,118  
   Mortensen,Sven,113  
   O'Donnell,Claire,112  
   Omelchenko,Svetlana,111  
   Tucker,Lance,119  
   Tucker,Michael,122  
   Zabokritski,Eugene,121  
   ```

#### 示例

```csharp
class CSVFiles  
{  
    static void Main(string[] args)  
    {  
        // Create the IEnumerable data source  
        string[] lines = System.IO.File.ReadAllLines(@"../../../spreadsheet1.csv");  
  
        // Create the query. Put field 2 first, then  
        // reverse and combine fields 0 and 1 from the old field  
        IEnumerable<string> query =  
            from line in lines  
            let x = line.Split(',')  
            orderby x[2]  
            select x[2] + ", " + (x[1] + " " + x[0]);  
  
        // Execute the query and write out the new file. Note that WriteAllLines  
        // takes a string[], so ToArray is called on the query.  
        System.IO.File.WriteAllLines(@"../../../spreadsheet2.csv", query.ToArray());  
  
        Console.WriteLine("Spreadsheet2.csv written to disk. Press any key to exit");  
        Console.ReadKey();  
    }  
}  
/* Output to spreadsheet2.csv:  
111, Svetlana Omelchenko  
112, Claire O'Donnell  
113, Sven Mortensen  
114, Cesar Garcia  
115, Debra Garcia  
116, Fadi Fakhouri  
117, Hanying Feng  
118, Hugo Garcia  
119, Lance Tucker  
120, Terry Adams  
121, Eugene Zabokritski  
122, Michael Tucker  
 */  
```

#### 编译代码

创建面向 .NET Framework 3.5 或更高版本的项目，此项目包含对 System.Core.dll 的引用和针对 System.Linq 和 System.IO 命名空间的 `using` 指令。

### [How to: Combine and Compare String Collections (LINQ)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtocombineandcomparestringcollectionslinq)

此示例演示如何合并包含文本行的文件，并对结果排序。 具体而言，此示例演示如何对两组文本行执行简单的串联、联合和交集。

#### 设置项目和文本文件

1. 将下面的姓名复制到名为 names1.txt 的文本文件，然后将此文件保存到项目文件夹：

   ```
   Bankov, Peter  
   Holm, Michael  
   Garcia, Hugo  
   Potra, Cristina  
   Noriega, Fabricio  
   Aw, Kam Foo  
   Beebe, Ann  
   Toyoshima, Tim  
   Guy, Wey Yuan  
   Garcia, Debra  
   ```

2. 将下面的姓名复制到名为 names2.txt 的文本文件，然后将此文件保存到项目文件夹。 请注意，这两个文件拥有一些共同的名称。

   ```
   Liu, Jinghao  
   Bankov, Peter  
   Holm, Michael  
   Garcia, Hugo  
   Beebe, Ann  
   Gilchrist, Beth  
   Myrcha, Jacek  
   Giakoumakis, Leo  
   McLin, Nkenge  
   El Yassir, Mehdi  
   ```

#### 示例

```csharp
class MergeStrings  
    {  
        static void Main(string[] args)  
        {  
            //Put text files in your solution folder  
            string[] fileA = System.IO.File.ReadAllLines(@"../../../names1.txt");  
            string[] fileB = System.IO.File.ReadAllLines(@"../../../names2.txt");  
  
            //Simple concatenation and sort. Duplicates are preserved.  
            IEnumerable<string> concatQuery =  
                fileA.Concat(fileB).OrderBy(s => s);  
  
            // Pass the query variable to another function for execution.  
            OutputQueryResults(concatQuery, "Simple concatenate and sort. Duplicates are preserved:");  
  
            // Concatenate and remove duplicate names based on  
            // default string comparer.  
            IEnumerable<string> uniqueNamesQuery =  
                fileA.Union(fileB).OrderBy(s => s);  
            OutputQueryResults(uniqueNamesQuery, "Union removes duplicate names:");  
  
            // Find the names that occur in both files (based on  
            // default string comparer).  
            IEnumerable<string> commonNamesQuery =  
                fileA.Intersect(fileB);  
            OutputQueryResults(commonNamesQuery, "Merge based on intersect:");  
  
            // Find the matching fields in each list. Merge the two   
            // results by using Concat, and then  
            // sort using the default string comparer.  
            string nameMatch = "Garcia";  
  
            IEnumerable<String> tempQuery1 =  
                from name in fileA  
                let n = name.Split(',')  
                where n[0] == nameMatch  
                select name;  
  
            IEnumerable<string> tempQuery2 =  
                from name2 in fileB  
                let n2 = name2.Split(',')  
                where n2[0] == nameMatch  
                select name2;  
  
            IEnumerable<string> nameMatchQuery =  
                tempQuery1.Concat(tempQuery2).OrderBy(s => s);  
            OutputQueryResults(nameMatchQuery, $"Concat based on partial name match \"{nameMatch}\":");
  
            // Keep the console window open in debug mode.  
            Console.WriteLine("Press any key to exit");  
            Console.ReadKey();  
        }  
  
        static void OutputQueryResults(IEnumerable<string> query, string message)  
        {  
            Console.WriteLine(System.Environment.NewLine + message);  
            foreach (string item in query)  
            {  
                Console.WriteLine(item);  
            }  
            Console.WriteLine("{0} total names in list", query.Count());  
        }  
    }  
    /* Output:  
        Simple concatenate and sort. Duplicates are preserved:  
        Aw, Kam Foo  
        Bankov, Peter  
        Bankov, Peter  
        Beebe, Ann  
        Beebe, Ann  
        El Yassir, Mehdi  
        Garcia, Debra  
        Garcia, Hugo  
        Garcia, Hugo  
        Giakoumakis, Leo  
        Gilchrist, Beth  
        Guy, Wey Yuan  
        Holm, Michael  
        Holm, Michael  
        Liu, Jinghao  
        McLin, Nkenge  
        Myrcha, Jacek  
        Noriega, Fabricio  
        Potra, Cristina  
        Toyoshima, Tim  
        20 total names in list  
  
        Union removes duplicate names:  
        Aw, Kam Foo  
        Bankov, Peter  
        Beebe, Ann  
        El Yassir, Mehdi  
        Garcia, Debra  
        Garcia, Hugo  
        Giakoumakis, Leo  
        Gilchrist, Beth  
        Guy, Wey Yuan  
        Holm, Michael  
        Liu, Jinghao  
        McLin, Nkenge  
        Myrcha, Jacek  
        Noriega, Fabricio  
        Potra, Cristina  
        Toyoshima, Tim  
        16 total names in list  
  
        Merge based on intersect:  
        Bankov, Peter  
        Holm, Michael  
        Garcia, Hugo  
        Beebe, Ann  
        4 total names in list  
  
        Concat based on partial name match "Garcia":  
        Garcia, Debra  
        Garcia, Hugo  
        Garcia, Hugo  
        3 total names in list  
*/  
```

#### 编译代码

创建面向 .NET Framework 3.5 或更高版本的项目，此项目包含对 System.Core.dll 的引用和针对 System.Linq 和 System.IO 命名空间的 `using` 指令。

### [How to: Populate Object Collections from Multiple Sources (LINQ)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtopopulateobjectcollectionsfrommultiplesourceslinq)

本示例演示如何将来自不同源的数据合并到一系列新的类型。

> 请勿尝试将内存中数据或文件系统中的数据与仍在数据库中的数据进行联接。 这种跨域联接可能产生未定义的结果，因为可能为数据库查询和其他类型的源定义了联接操作的不同方式。 此外，如果数据库中的数据量足够大，这样的操作还存在可能导致内存不足的异常的风险。 若要将数据库中的数据联接到内存数据，首先对数据库查询调用 `ToList` 或 `ToArray`，然后对返回的集合执行联接。

#### 创建数据文件

按照后列文章中的说明将 names.csv 和 scores.csv 文件复制到项目文件夹：[如何：联接不同文件中的内容 (LINQ) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-join-content-from-dissimilar-files-linq)。

#### 示例

下面的示例演示如何使用命名类型 `Student` 存储来自两个内存字符串集合（模拟 .csv 格式的电子表格数据）的合并数据。 第一个字符串集合代表学生姓名和 ID，第二个集合代表学生 ID（在第一列）和四次考试分数。 此 ID 用作外键。

```csharp
using System;
using System.Collections.Generic;
using System.Linq;

class Student
{
    public string FirstName { get; set; }
    public string LastName { get; set; }
    public int ID { get; set; }
    public List<int> ExamScores { get; set; }
}

class PopulateCollection
{
    static void Main()
    {
        // These data files are defined in How to: Join Content from
        // Dissimilar Files (LINQ).

        // Each line of names.csv consists of a last name, a first name, and an
        // ID number, separated by commas. For example, Omelchenko,Svetlana,111
        string[] names = System.IO.File.ReadAllLines(@"../../../names.csv");

        // Each line of scores.csv consists of an ID number and four test
        // scores, separated by commas. For example, 111, 97, 92, 81, 60
        string[] scores = System.IO.File.ReadAllLines(@"../../../scores.csv");

        // Merge the data sources using a named type.
        // var could be used instead of an explicit type. Note the dynamic
        // creation of a list of ints for the ExamScores member. The first item
        // is skipped in the split string because it is the student ID,
        // not an exam score.
        IEnumerable<Student> queryNamesScores =
            from nameLine in names
            let splitName = nameLine.Split(',')
            from scoreLine in scores
            let splitScoreLine = scoreLine.Split(',')
            where Convert.ToInt32(splitName[2]) == Convert.ToInt32(splitScoreLine[0])
            select new Student()
            {
                FirstName = splitName[0],
                LastName = splitName[1],
                ID = Convert.ToInt32(splitName[2]),
                ExamScores = (from scoreAsText in splitScoreLine.Skip(1)
                              select Convert.ToInt32(scoreAsText)).
                              ToList()
            };

        // Optional. Store the newly created student objects in memory
        // for faster access in future queries. This could be useful with
        // very large data files.
        List<Student> students = queryNamesScores.ToList();

        // Display each student's name and exam score average.
        foreach (var student in students)
        {
            Console.WriteLine("The average score of {0} {1} is {2}.",
                student.FirstName, student.LastName,
                student.ExamScores.Average());
        }

        //Keep console window open in debug mode
        Console.WriteLine("Press any key to exit.");
        Console.ReadKey();
    }
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

在 [select](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/select-clause) 子句中，对象初始值设定项使用来自两个源的数据实例化每个新的 `Student` 对象。

如果不需要存储查询的结果，那么和命名类型相比，匿名类型使用起来更方便。 如果在执行查询的方法外部传递查询结果，则需要使用命名类型。 下面的示例执行与前面示例相同的任务，但使用的是匿名类型，而不是命名类型：

```csharp
// Merge the data sources by using an anonymous type.
// Note the dynamic creation of a list of ints for the
// ExamScores member. We skip 1 because the first string
// in the array is the student ID, not an exam score.
var queryNamesScores2 =
    from nameLine in names
    let splitName = nameLine.Split(',')
    from scoreLine in scores
    let splitScoreLine = scoreLine.Split(',')
    where Convert.ToInt32(splitName[2]) == Convert.ToInt32(splitScoreLine[0])
    select new
    {
        First = splitName[0],
        Last = splitName[1],
        ExamScores = (from scoreAsText in splitScoreLine.Skip(1)
                      select Convert.ToInt32(scoreAsText))
                      .ToList()
    };

// Display each student's name and exam score average.
foreach (var student in queryNamesScores2)
{
    Console.WriteLine("The average score of {0} {1} is {2}.",
        student.First, student.Last, student.ExamScores.Average());
}
```

#### 编译代码

创建并编译面向下列选项之一的项目：

- .NET Framework 版本 3.5，含对 System.Core.dll 的引用。
- .NET Framework 版本 4.0或更高版本。
- .NET Core 版本 1.0 或更高版本。

### [How to: Split a File Into Many Files by Using Groups (LINQ)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtosplitafileintomanyfilesbyusinggroupslinq)

此示例演示一种进行以下操作的方法：合并两个文件的内容，然后创建一组以新方式整理数据的新文件。

#### 创建数据文件

1. 将下面的姓名复制到名为 names1.txt 的文本文件，然后将此文件保存到项目文件夹：

   ```
   Bankov, Peter  
   Holm, Michael  
   Garcia, Hugo  
   Potra, Cristina  
   Noriega, Fabricio  
   Aw, Kam Foo  
   Beebe, Ann  
   Toyoshima, Tim  
   Guy, Wey Yuan  
   Garcia, Debra  
   ```

2. 将下面的姓名复制到名为 names2.txt 的文本文件，然后将此文件保存到项目文件夹：请注意，这两个文件拥有一些共同的名称。

   ```
   Liu, Jinghao  
   Bankov, Peter  
   Holm, Michael  
   Garcia, Hugo  
   Beebe, Ann  
   Gilchrist, Beth  
   Myrcha, Jacek  
   Giakoumakis, Leo  
   McLin, Nkenge  
   El Yassir, Mehdi  
   ```

#### 示例

```csharp
class SplitWithGroups  
{  
    static void Main()  
    {  
        string[] fileA = System.IO.File.ReadAllLines(@"../../../names1.txt");  
        string[] fileB = System.IO.File.ReadAllLines(@"../../../names2.txt");  
  
        // Concatenate and remove duplicate names based on  
        // default string comparer  
        var mergeQuery = fileA.Union(fileB);  
  
        // Group the names by the first letter in the last name.  
        var groupQuery = from name in mergeQuery  
                         let n = name.Split(',')  
                         group name by n[0][0] into g  
                         orderby g.Key  
                         select g;  
  
        // Create a new file for each group that was created  
        // Note that nested foreach loops are required to access  
        // individual items with each group.  
        foreach (var g in groupQuery)  
        {  
            // Create the new file name.  
            string fileName = @"../../../testFile_" + g.Key + ".txt";  
  
            // Output to display.  
            Console.WriteLine(g.Key);  
  
            // Write file.  
            using (System.IO.StreamWriter sw = new System.IO.StreamWriter(fileName))  
            {  
                foreach (var item in g)  
                {  
                    sw.WriteLine(item);  
                    // Output to console for example purposes.  
                    Console.WriteLine("   {0}", item);  
                }  
            }  
        }  
        // Keep console window open in debug mode.  
        Console.WriteLine("Files have been written. Press any key to exit");  
        Console.ReadKey();  
    }  
}  
/* Output:   
    A  
       Aw, Kam Foo  
    B  
       Bankov, Peter  
       Beebe, Ann  
    E  
       El Yassir, Mehdi  
    G  
       Garcia, Hugo  
       Guy, Wey Yuan  
       Garcia, Debra  
       Gilchrist, Beth  
       Giakoumakis, Leo  
    H  
       Holm, Michael  
    L  
       Liu, Jinghao  
    M  
       Myrcha, Jacek  
       McLin, Nkenge  
    N  
       Noriega, Fabricio  
    P  
       Potra, Cristina  
    T  
       Toyoshima, Tim  
 */  
```

对于与数据文件位于同一文件夹中的每个组，程序将为这些组编写单独的文件。

#### 编译代码

创建面向 .NET Framework 3.5 或更高版本的项目，此项目包含对 System.Core.dll 的引用和针对 System.Linq 和 System.IO 命名空间的 `using` 指令。

### [How to: Join Content from Dissimilar Files (LINQ)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtojoincontentfromdissimilarfileslinq)

本示例演示如何联接两个逗号分隔文件中的数据，这两个文件共享一个用作匹配键的公共值。 如果需要合并来自两个电子表格的数据，或者从一个电子表格和具有另一种格式的文件合并到一个新文件时，此技术很有用。 可以修改此示例以用于任何类型的结构化文本。

#### 创建数据文件

1. 将以下行复制到名为 scores.csv 的文件，并将文件保存到项目文件夹。 此文件表示电子表格数据。 第 1 列是学生的 ID，第 2 至 5 列是测验分数。

   ```
   111, 97, 92, 81, 60  
   112, 75, 84, 91, 39  
   113, 88, 94, 65, 91  
   114, 97, 89, 85, 82  
   115, 35, 72, 91, 70  
   116, 99, 86, 90, 94  
   117, 93, 92, 80, 87  
   118, 92, 90, 83, 78  
   119, 68, 79, 88, 92  
   120, 99, 82, 81, 79  
   121, 96, 85, 91, 60  
   122, 94, 92, 91, 91  
   ```

2. 将以下行复制到名为 names.csv 的文件，并将文件保存到项目文件夹。 此文件表示电子表格，其中包含学生的姓氏、名字和学生 ID。

   ```
   Omelchenko,Svetlana,111  
   O'Donnell,Claire,112  
   Mortensen,Sven,113  
   Garcia,Cesar,114  
   Garcia,Debra,115  
   Fakhouri,Fadi,116  
   Feng,Hanying,117  
   Garcia,Hugo,118  
   Tucker,Lance,119  
   Adams,Terry,120  
   Zabokritski,Eugene,121  
   Tucker,Michael,122  
   ```

#### 示例

```csharp
using System;
using System.Collections.Generic;
using System.Linq;

class JoinStrings  
{  
    static void Main()  
    {  
        // Join content from dissimilar files that contain  
        // related information. File names.csv contains the student  
        // name plus an ID number. File scores.csv contains the ID   
        // and a set of four test scores. The following query joins  
        // the scores to the student names by using ID as a  
        // matching key.  
  
        string[] names = System.IO.File.ReadAllLines(@"../../../names.csv");  
        string[] scores = System.IO.File.ReadAllLines(@"../../../scores.csv");  
  
        // Name:    Last[0],       First[1],  ID[2]  
        //          Omelchenko,    Svetlana,  11  
        // Score:   StudentID[0],  Exam1[1]   Exam2[2],  Exam3[3],  Exam4[4]  
        //          111,           97,        92,        81,        60  
  
        // This query joins two dissimilar spreadsheets based on common ID value.  
        // Multiple from clauses are used instead of a join clause  
        // in order to store results of id.Split.  
        IEnumerable<string> scoreQuery1 =  
            from name in names  
            let nameFields = name.Split(',')  
            from id in scores  
            let scoreFields = id.Split(',')  
            where Convert.ToInt32(nameFields[2]) == Convert.ToInt32(scoreFields[0])
            select nameFields[0] + "," + scoreFields[1] + "," + scoreFields[2]   
                   + "," + scoreFields[3] + "," + scoreFields[4];  
  
        // Pass a query variable to a method and execute it  
        // in the method. The query itself is unchanged.  
        OutputQueryResults(scoreQuery1, "Merge two spreadsheets:");  
  
        // Keep console window open in debug mode.  
        Console.WriteLine("Press any key to exit");  
        Console.ReadKey();  
    }  
  
    static void OutputQueryResults(IEnumerable<string> query, string message)  
    {  
        Console.WriteLine(System.Environment.NewLine + message);  
        foreach (string item in query)  
        {  
            Console.WriteLine(item);  
        }  
        Console.WriteLine("{0} total names in list", query.Count());  
    }  
}  
/* Output:  
Merge two spreadsheets:
Omelchenko, 97, 92, 81, 60
O'Donnell, 75, 84, 91, 39
Mortensen, 88, 94, 65, 91
Garcia, 97, 89, 85, 82
Garcia, 35, 72, 91, 70
Fakhouri, 99, 86, 90, 94
Feng, 93, 92, 80, 87
Garcia, 92, 90, 83, 78
Tucker, 68, 79, 88, 92
Adams, 99, 82, 81, 79
Zabokritski, 96, 85, 91, 60
Tucker, 94, 92, 91, 91
12 total names in list
 */  
```

#### 编译代码

创建并编译面向下列选项之一的项目：

- .NET Framework 版本 3.5，含对 System.Core.dll 的引用。
- .NET Framework 版本 4.0或更高版本。
- .NET Core 版本 1.0 或更高版本。

### [How to: Compute Column Values in a CSV Text File (LINQ)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtocomputecolumnvaluesinacsvtextfilelinq)

此示例演示如何对 .csv 文件的列执行 Sum、Average、Min 和 Max 等聚合计算。 此处所示的示例原则可以应用于其他类型的结构化文本。

#### 创建源文件

1. 将以下行复制到名为 scores.csv 的文件，并将文件保存到项目文件夹。 假定第一列表示学生 ID，后面几列表示四次考试的分数。

   ```
   111, 97, 92, 81, 60  
   112, 75, 84, 91, 39  
   113, 88, 94, 65, 91  
   114, 97, 89, 85, 82  
   115, 35, 72, 91, 70  
   116, 99, 86, 90, 94  
   117, 93, 92, 80, 87  
   118, 92, 90, 83, 78  
   119, 68, 79, 88, 92  
   120, 99, 82, 81, 79  
   121, 96, 85, 91, 60  
   122, 94, 92, 91, 91  
   ```

#### 示例

```csharp
class SumColumns  
{  
    static void Main(string[] args)  
    {  
        string[] lines = System.IO.File.ReadAllLines(@"../../../scores.csv");  
  
        // Specifies the column to compute.  
        int exam = 3;  
  
        // Spreadsheet format:  
        // Student ID    Exam#1  Exam#2  Exam#3  Exam#4  
        // 111,          97,     92,     81,     60  
  
        // Add one to exam to skip over the first column,  
        // which holds the student ID.  
        SingleColumn(lines, exam + 1);  
        Console.WriteLine();  
        MultiColumns(lines);  
  
        Console.WriteLine("Press any key to exit");  
        Console.ReadKey();  
    }  
  
    static void SingleColumn(IEnumerable<string> strs, int examNum)  
    {  
        Console.WriteLine("Single Column Query:");  
  
        // Parameter examNum specifies the column to   
        // run the calculations on. This value could be  
        // passed in dynamically at runtime.               
  
        // Variable columnQuery is an IEnumerable<int>.  
        // The following query performs two steps:  
        // 1) use Split to break each row (a string) into an array   
        //    of strings,   
        // 2) convert the element at position examNum to an int  
        //    and select it.  
        var columnQuery =  
            from line in strs  
            let elements = line.Split(',')  
            select Convert.ToInt32(elements[examNum]);  
  
        // Execute the query and cache the results to improve  
        // performance. This is helpful only with very large files.  
        var results = columnQuery.ToList();  
  
        // Perform aggregate calculations Average, Max, and  
        // Min on the column specified by examNum.  
        double average = results.Average();  
        int max = results.Max();  
        int min = results.Min();  
  
        Console.WriteLine("Exam #{0}: Average:{1:##.##} High Score:{2} Low Score:{3}",  
                 examNum, average, max, min);  
    }  
  
    static void MultiColumns(IEnumerable<string> strs)  
    {  
        Console.WriteLine("Multi Column Query:");  
  
        // Create a query, multiColQuery. Explicit typing is used  
        // to make clear that, when executed, multiColQuery produces   
        // nested sequences. However, you get the same results by  
        // using 'var'.  
  
        // The multiColQuery query performs the following steps:  
        // 1) use Split to break each row (a string) into an array   
        //    of strings,   
        // 2) use Skip to skip the "Student ID" column, and store the   
        //    rest of the row in scores.  
        // 3) convert each score in the current row from a string to  
        //    an int, and select that entire sequence as one row   
        //    in the results.  
        IEnumerable<IEnumerable<int>> multiColQuery =  
            from line in strs  
            let elements = line.Split(',')  
            let scores = elements.Skip(1)  
            select (from str in scores  
                    select Convert.ToInt32(str));  
  
        // Execute the query and cache the results to improve  
        // performance.   
        // ToArray could be used instead of ToList.  
        var results = multiColQuery.ToList();  
  
        // Find out how many columns you have in results.  
        int columnCount = results[0].Count();  
  
        // Perform aggregate calculations Average, Max, and  
        // Min on each column.              
        // Perform one iteration of the loop for each column   
        // of scores.  
        // You can use a for loop instead of a foreach loop   
        // because you already executed the multiColQuery   
        // query by calling ToList.  
        for (int column = 0; column < columnCount; column++)  
        {  
            var results2 = from row in results  
                           select row.ElementAt(column);  
            double average = results2.Average();  
            int max = results2.Max();  
            int min = results2.Min();  
  
            // Add one to column because the first exam is Exam #1,  
            // not Exam #0.  
            Console.WriteLine("Exam #{0} Average: {1:##.##} High Score: {2} Low Score: {3}",  
                          column + 1, average, max, min);  
        }  
    }  
}  
/* Output:  
    Single Column Query:  
    Exam #4: Average:76.92 High Score:94 Low Score:39  
  
    Multi Column Query:  
    Exam #1 Average: 86.08 High Score: 99 Low Score: 35  
    Exam #2 Average: 86.42 High Score: 94 Low Score: 72  
    Exam #3 Average: 84.75 High Score: 91 Low Score: 65  
    Exam #4 Average: 76.92 High Score: 94 Low Score: 39  
 */  
```

查询的工作原理是使用 [Split](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.split) 方法将每一行文本转换为数组。 每个数组元素表示一列。 最后，每一列中的文本都转换为其数字表示形式。 如果文件是制表符分隔文件，只需将 `Split` 方法中的参数更新为 `\t`。

#### 编译代码

创建面向 .NET Framework 3.5 或更高版本的项目，此项目包含对 System.Core.dll 的引用和针对 System.Linq 和 System.IO 命名空间的 `using` 指令。

## [LINQ and Reflection](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/linqandreflection)

.NET Framework 类库反射 API 可用于检查 .NET 程序集中的元数据，以及创建位于该程序集中的类型、类型成员、参数等等的集合。 因为这些集合支持泛型 `IEnumerable` 接口，所以可以使用 LINQ 查询它们。

本节包含下列主题：

[如何：使用反射查询程序集的元数据 (LINQ) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-query-an-assembly-s-metadata-with-reflection-linq)
演示如何将 LINQ 与反射一起使用。

### [How to: Query An Assembly's Metadata with Reflection (LINQ)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoqueryanassemblysmetadatawithreflectionlinq)

下面的示例演示了如何将 LINQ 与反射配合使用以检索有关与指定搜索条件匹配的方法的特定元数据。 在这种情况下，该查询将在返回数组等可枚举类型的程序集中查找所有方法的名称。

#### 示例

```csharp
using System.Reflection;  
using System.IO;  
namespace LINQReflection  
{  
    class ReflectionHowTO  
    {  
        static void Main(string[] args)  
        {  
            Assembly assembly = Assembly.Load("System.Core, Version=3.5.0.0, Culture=neutral, PublicKeyToken= b77a5c561934e089");  
            var pubTypesQuery = from type in assembly.GetTypes()  
                        where type.IsPublic  
                            from method in type.GetMethods()  
                            where method.ReturnType.IsArray == true   
                                || ( method.ReturnType.GetInterface(  
                                    typeof(System.Collections.Generic.IEnumerable<>).FullName ) != null  
                                && method.ReturnType.FullName != "System.String" )  
                            group method.ToString() by type.ToString();  
  
            foreach (var groupOfMethods in pubTypesQuery)  
            {  
                Console.WriteLine("Type: {0}", groupOfMethods.Key);  
                foreach (var method in groupOfMethods)  
                {  
                    Console.WriteLine("  {0}", method);  
                }  
            }  
  
            Console.WriteLine("Press any key to exit");  
            Console.ReadKey();  
        }  
    }    
}  
```

该示例使用 [GetTypes](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.assembly.gettypes) 方法返回指定程序集中的类型的数组。 将应用 [where](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/where-clause) 筛选器，以便仅返回公共类型。 对于每个公共类型，子查询使用从 [GetMethods](https://docs.microsoft.com/zh-cn/dotnet/api/system.type.getmethods) 调用返回的 [MethodInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.methodinfo) 数组生成。 筛选这些结果，以仅返回其返回类型为数组或实现 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的其他类型的方法。 最后，通过使用类型名称作为键来对这些结果进行分组。

#### 编译代码

创建面向 .NET Framework 3.5 或更高版本的项目，此项目包含对 System.Core.dll 的引用和针对 System.Linq 和 System.IO 命名空间的 `using` 指令。

## [LINQ and File Directories](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/linqandfiledirectories)

许多文件系统操作实质上是查询，因此非常适合使用 LINQ 方法。

请注意，本部分中的查询是非破坏性查询。 它们不用于更改原始文件或文件夹的内容。 这遵循了查询不应引起任何副作用这条规则。 通常，修改源数据的任何代码（包括执行创建/更新/删除运算符的查询）应与只查询数据的代码分开。

本节包含下列主题：

[如何：查询具有指定属性或名称的文件 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-query-for-files-with-a-specified-attribute-or-name)
演示如何通过检查文件的 [FileInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.fileinfo) 对象的一个或多个属性来搜索文件。

[如何：按扩展名对文件进行分组 (LINQ) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-group-files-by-extension-linq)
演示如何根据文件扩展名返回 [FileInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.fileinfo) 对象组。

[如何：查询一组文件夹中的总字节数 (LINQ) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-query-for-the-total-number-of-bytes-in-a-set-of-folders-linq)
演示如何返回指定目录树中所有文件的总字节数。

[如何：比较两个文件夹的内容 (LINQ) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-compare-the-contents-of-two-folders-linq)
演示如何返回位于两个指定文件夹中的所有文件，以及仅位于其中一个文件夹中的所有文件。

[如何：查询最大的文件或目录树中的文件 (LINQ) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-query-for-the-largest-file-or-files-in-a-directory-tree-linq)
演示如何返回目录树中的最大文件、最小文件或指定数量的文件。

[如何：在目录树中查询重复文件 (LINQ) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-query-for-duplicate-files-in-a-directory-tree-linq)
演示如何对出现在指定目录树中多个位置的所有文件名进行分组。 此外，还演示如何根据自定义比较器执行更复杂的比较。

[如何：查询文件夹中文件的内容 (LINQ) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-query-the-contents-of-files-in-a-folder-lin)
演示如何循环访问树中的文件夹，打开每个文件以及查询文件的内容。

### 注释

创建准确表示文件系统的内容并适当处理异常的数据源，存在一定难度。 本部分中的示例创建 [FileInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.fileinfo) 对象的快照集合，该集合表示指定的根文件夹及其所有子文件夹下的所有文件。 每个 [FileInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.fileinfo) 的实际状态可能会在开始和结束执行查询期间发生更改。 例如，可以创建 [FileInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.fileinfo) 对象的列表来用作数据源。 如果尝试通过查询访问 `Length` 属性，则 [FileInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.fileinfo) 对象会尝试访问文件系统来更新 `Length` 的值。 如果该文件不再存在，则你会在查询中获得 [FileNotFoundException](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.filenotfoundexception)，即使未直接查询文件系统也是如此。 本部分中的一些查询使用不同的方法，在某些情况下使用该方法不会出现这些特定异常。 另一种方法是使用 [FileSystemWatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.filesystemwatcher) 保持数据源动态更新。

### [How to: Query for Files with a Specified Attribute or Name](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoqueryforfileswithaspecifiedattributeorname)

此示例演示了如何在指定目录树中查找具有指定文件扩展名（如“.txt”）的所有文件。 它还演示了如何基于时间在树中返回最新或最旧的文件。

#### 示例

```csharp
class FindFileByExtension  
{  
    // This query will produce the full path for all .txt files  
    // under the specified folder including subfolders.  
    // It orders the list according to the file name.  
    static void Main()  
    {  
        string startFolder = @"c:\program files\Microsoft Visual Studio 9.0\";  
  
        // Take a snapshot of the file system.  
        System.IO.DirectoryInfo dir = new System.IO.DirectoryInfo(startFolder);  
  
        // This method assumes that the application has discovery permissions  
        // for all folders under the specified path.  
        IEnumerable<System.IO.FileInfo> fileList = dir.GetFiles("*.*", System.IO.SearchOption.AllDirectories);  
  
        //Create the query  
        IEnumerable<System.IO.FileInfo> fileQuery =  
            from file in fileList  
            where file.Extension == ".txt"  
            orderby file.Name  
            select file;  
  
        //Execute the query. This might write out a lot of files!  
        foreach (System.IO.FileInfo fi in fileQuery)  
        {  
            Console.WriteLine(fi.FullName);  
        }  
  
        // Create and execute a new query by using the previous   
        // query as a starting point. fileQuery is not   
        // executed again until the call to Last()  
        var newestFile =  
            (from file in fileQuery  
             orderby file.CreationTime  
             select new { file.FullName, file.CreationTime })  
            .Last();  
  
        Console.WriteLine("\r\nThe newest .txt file is {0}. Creation time: {1}",  
            newestFile.FullName, newestFile.CreationTime);  
  
        // Keep the console window open in debug mode.  
        Console.WriteLine("Press any key to exit");  
        Console.ReadKey();  
    }  
}  
```

#### 编译代码

创建面向 .NET Framework 3.5 或更高版本的项目，此项目包含对 System.Core.dll 的引用和针对 System.Linq 和 System.IO 命名空间的 `using` 指令。

### [How to: Group Files by Extension (LINQ)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtogroupfilesbyextensionlinq)

本示例演示如何使用 LINQ 来执行高级分组和对文件或文件夹列表执行排序操作。 它还演示如何使用 [Skip](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.skip) 和 [Take](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.take)方法在控制台窗口中对输出进行分页。

#### 示例

下面的查询演示如何按文件扩展名对指定的目录树的内容进行分组。

```csharp
class GroupByExtension  
{  
    // This query will sort all the files under the specified folder  
    //  and subfolder into groups keyed by the file extension.  
    private static void Main()  
    {  
        // Take a snapshot of the file system.  
        string startFolder = @"c:\program files\Microsoft Visual Studio 9.0\Common7";  
  
        // Used in WriteLine to trim output lines.  
        int trimLength = startFolder.Length;  
  
        // Take a snapshot of the file system.  
        System.IO.DirectoryInfo dir = new System.IO.DirectoryInfo(startFolder);  
  
        // This method assumes that the application has discovery permissions  
        // for all folders under the specified path.  
        IEnumerable<System.IO.FileInfo> fileList = dir.GetFiles("*.*", System.IO.SearchOption.AllDirectories);  
  
        // Create the query.  
        var queryGroupByExt =  
            from file in fileList  
            group file by file.Extension.ToLower() into fileGroup  
            orderby fileGroup.Key  
            select fileGroup;  
  
        // Display one group at a time. If the number of   
        // entries is greater than the number of lines  
        // in the console window, then page the output.  
        PageOutput(trimLength, queryGroupByExt);  
    }  
  
    // This method specifically handles group queries of FileInfo objects with string keys.  
    // It can be modified to work for any long listings of data. Note that explicit typing  
    // must be used in method signatures. The groupbyExtList parameter is a query that produces  
    // groups of FileInfo objects with string keys.  
    private static void PageOutput(int rootLength,  
                                    IEnumerable<System.Linq.IGrouping<string, System.IO.FileInfo>> groupByExtList)  
    {  
        // Flag to break out of paging loop.  
        bool goAgain = true;  
  
        // "3" = 1 line for extension + 1 for "Press any key" + 1 for input cursor.  
        int numLines = Console.WindowHeight - 3;  
  
        // Iterate through the outer collection of groups.  
        foreach (var filegroup in groupByExtList)  
        {  
            // Start a new extension at the top of a page.  
            int currentLine = 0;  
  
            // Output only as many lines of the current group as will fit in the window.  
            do  
            {  
                Console.Clear();  
                Console.WriteLine(filegroup.Key == String.Empty ? "[none]" : filegroup.Key);  
  
                // Get 'numLines' number of items starting at number 'currentLine'.  
                var resultPage = filegroup.Skip(currentLine).Take(numLines);  
  
                //Execute the resultPage query  
                foreach (var f in resultPage)  
                {  
                    Console.WriteLine("\t{0}", f.FullName.Substring(rootLength));  
                }  
  
                // Increment the line counter.  
                currentLine += numLines;  
  
                // Give the user a chance to escape.  
                Console.WriteLine("Press any key to continue or the 'End' key to break...");  
                ConsoleKey key = Console.ReadKey().Key;  
                if (key == ConsoleKey.End)  
                {  
                    goAgain = false;  
                    break;  
                }  
            } while (currentLine < filegroup.Count());  
  
            if (goAgain == false)  
                break;  
        }  
    }  
}  
```

此程序的输出可能很长，具体取决于本地文件系统的详细信息和 `startFolder` 的设置。 为了能够查看所有结果，此示例演示如何对结果进行分页。 相同的方法适用于 Windows 和 Web 应用程序。 请注意，由于代码对组中的项进行分页，因此需要使用 `foreach` 循环。 此外，还有一些其他逻辑用于计算列表中的当前位置，以及使用户能够停止分页并退出程序。 在此特定情况下，根据原始查询的缓存结果运行分页查询。 在其他上下文中，如 LINQ to SQL，则不需要此类缓存。

#### 编译代码

创建面向 .NET Framework 3.5 或更高版本的项目，此项目包含对 System.Core.dll 的引用和针对 System.Linq 和 System.IO 命名空间的 `using` 指令。

### [How to: Query for the Total Number of Bytes in a Set of Folders (LINQ)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoqueryforthetotalnumberofbytesinasetoffolderslinq)

此示例演示如何检索由指定文件夹及其所有子文件夹中的所有文件使用的字节总数。

#### 示例

[Sum](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.sum) 方法可将 `select` 子句中选择的所有项的值相加。 可轻松修改此查询以检索指定目录树中的最大或最小文件，方法是调用 [Min](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.min) 或 [Max](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.max) 方法，而不是 [Sum](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.sum) 方法。

```csharp
class QuerySize  
{  
    public static void Main()  
    {  
        string startFolder = @"c:\program files\Microsoft Visual Studio 9.0\VC#";  
  
        // Take a snapshot of the file system.  
        // This method assumes that the application has discovery permissions  
        // for all folders under the specified path.  
        IEnumerable<string> fileList = System.IO.Directory.GetFiles(startFolder, "*.*", System.IO.SearchOption.AllDirectories);  
  
        var fileQuery = from file in fileList  
                        select GetFileLength(file);  
  
        // Cache the results to avoid multiple trips to the file system.  
        long[] fileLengths = fileQuery.ToArray();  
  
        // Return the size of the largest file  
        long largestFile = fileLengths.Max();  
  
        // Return the total number of bytes in all the files under the specified folder.  
        long totalBytes = fileLengths.Sum();  
  
        Console.WriteLine("There are {0} bytes in {1} files under {2}",  
            totalBytes, fileList.Count(), startFolder);  
        Console.WriteLine("The largest files is {0} bytes.", largestFile);  
  
        // Keep the console window open in debug mode.  
        Console.WriteLine("Press any key to exit.");  
        Console.ReadKey();  
    }  
  
    // This method is used to swallow the possible exception  
    // that can be raised when accessing the System.IO.FileInfo.Length property.  
    static long GetFileLength(string filename)  
    {  
        long retval;  
        try  
        {  
            System.IO.FileInfo fi = new System.IO.FileInfo(filename);  
            retval = fi.Length;  
        }  
        catch (System.IO.FileNotFoundException)  
        {  
            // If a file is no longer present,  
            // just add zero bytes to the total.  
            retval = 0;  
        }  
        return retval;  
    }  
}  
```

如果只需对指定目录树中的字节数进行计数，则可以更高效地执行此操作而无需创建 LINQ 查询（这会产生创建列表集合作为数据源的开销）。 随着查询变得更加复杂，或者在必须对相同数据源运行多个查询时，LINQ 方法会更加有用。

查询调用单独的方法来获取文件长度。 这是为了使用在以下情况下会引发的可能异常：在 `GetFiles` 调用中创建了 [FileInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.fileinfo) 对象之后，在其他线程中删除了文件。 即使已创建 [FileInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.fileinfo) 对象，该异常也可能出现，因为 [FileInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.fileinfo) 对象会在首次访问其 [Length](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.fileinfo.length) 属性时，尝试使用最近长度刷新该属性。 通过将此操作置于查询外部的 try-catch 块中，代码可遵循在查询中避免可能导致副作用的操作这一规则。 一般情况下，在使用异常时必须格外谨慎，以确保应用程序不会处于未知状态。

#### 编译代码

创建面向 .NET Framework 3.5 或更高版本的项目，此项目包含对 System.Core.dll 的引用和针对 System.Linq 和 System.IO 命名空间的 `using` 指令。

### [How to: Compare the Contents of Two Folders (LINQ)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtocomparethecontentsoftwofolderslinq)

此示例演示了比较两个文件列表的 3 种方法：

- 通过查询布尔值指定两个文件列表是否相同。

- 通过查询交集检索同时存在于两个文件夹中的文件。

- 通过查询差集检索仅存在于一个文件夹中的文件。

  > 此处的方法适用于比较任何类型的对象序列。

此处的 `FileComparer` 类演示如何将自定义比较器类与标准查询运算符结合使用。 此类不适合在实际方案中使用。 它仅使用每个文件的名称和字节长度来确定每个文件夹的内容是否相同。 在实际方案中，应修改此比较器以执行更严格的等同性检查。

#### 示例

```csharp
namespace QueryCompareTwoDirs  
{  
    class CompareDirs  
    {  
  
        static void Main(string[] args)  
        {  
  
            // Create two identical or different temporary folders   
            // on a local drive and change these file paths.  
            string pathA = @"C:\TestDir";  
            string pathB = @"C:\TestDir2";  
  
            System.IO.DirectoryInfo dir1 = new System.IO.DirectoryInfo(pathA);  
            System.IO.DirectoryInfo dir2 = new System.IO.DirectoryInfo(pathB);  
  
            // Take a snapshot of the file system.  
            IEnumerable<System.IO.FileInfo> list1 = dir1.GetFiles("*.*", System.IO.SearchOption.AllDirectories);  
            IEnumerable<System.IO.FileInfo> list2 = dir2.GetFiles("*.*", System.IO.SearchOption.AllDirectories);  
  
            //A custom file comparer defined below  
            FileCompare myFileCompare = new FileCompare();  
  
            // This query determines whether the two folders contain  
            // identical file lists, based on the custom file comparer  
            // that is defined in the FileCompare class.  
            // The query executes immediately because it returns a bool.  
            bool areIdentical = list1.SequenceEqual(list2, myFileCompare);  
  
            if (areIdentical == true)  
            {  
                Console.WriteLine("the two folders are the same");  
            }  
            else  
            {  
                Console.WriteLine("The two folders are not the same");  
            }  
  
            // Find the common files. It produces a sequence and doesn't   
            // execute until the foreach statement.  
            var queryCommonFiles = list1.Intersect(list2, myFileCompare);  
  
            if (queryCommonFiles.Count() > 0)  
            {  
                Console.WriteLine("The following files are in both folders:");  
                foreach (var v in queryCommonFiles)  
                {  
                    Console.WriteLine(v.FullName); //shows which items end up in result list  
                }  
            }  
            else  
            {  
                Console.WriteLine("There are no common files in the two folders.");  
            }  
  
            // Find the set difference between the two folders.  
            // For this example we only check one way.  
            var queryList1Only = (from file in list1  
                                  select file).Except(list2, myFileCompare);  
  
            Console.WriteLine("The following files are in list1 but not list2:");  
            foreach (var v in queryList1Only)  
            {  
                Console.WriteLine(v.FullName);  
            }  
  
            // Keep the console window open in debug mode.  
            Console.WriteLine("Press any key to exit.");  
            Console.ReadKey();  
        }  
    }  
  
    // This implementation defines a very simple comparison  
    // between two FileInfo objects. It only compares the name  
    // of the files being compared and their length in bytes.  
    class FileCompare : System.Collections.Generic.IEqualityComparer<System.IO.FileInfo>  
    {  
        public FileCompare() { }  
  
        public bool Equals(System.IO.FileInfo f1, System.IO.FileInfo f2)  
        {  
            return (f1.Name == f2.Name &&  
                    f1.Length == f2.Length);  
        }  
  
        // Return a hash that reflects the comparison criteria. According to the   
        // rules for IEqualityComparer<T>, if Equals is true, then the hash codes must  
        // also be equal. Because equality as defined here is a simple value equality, not  
        // reference identity, it is possible that two or more objects will produce the same  
        // hash code.  
        public int GetHashCode(System.IO.FileInfo fi)  
        {  
            string s = $"{fi.Name}{fi.Length}";
            return s.GetHashCode();  
        }  
    }  
}  
```

#### 编译代码

创建面向 .NET Framework 3.5 或更高版本的项目，此项目包含对 System.Core.dll 的引用和针对 System.Linq 和 System.IO 命名空间的 `using` 指令。

### [How to: Query for the Largest File or Files in a Directory Tree (LINQ)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoqueryforthelargestfileorfilesinadirectorytreelinq)

此示例演示与文件大小（以字节为单位）相关的五个查询：

- 如何检索最大文件的大小（以字节为单位）。
- 如何检索最小文件的大小（以字节为单位）。
- 如何从指定根文件夹下的一个或多个文件夹检索 [FileInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.fileinfo) 对象最大或最小文件。
- 如何检索序列（如 10 个最大文件）。
- 如何基于文件大小（以字节为单位）按组对文件进行排序（忽略小于指定大小的文件）。

#### 示例

下面的示例包含五个单独的查询，它们演示如何根据文件大小（以字节为单位）对文件进行查询和分组。 可以轻松地修改这些示例，以便使查询基于 [FileInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.fileinfo) 对象的其他某个属性。

```csharp
class QueryBySize  
{  
    static void Main(string[] args)  
    {  
        QueryFilesBySize();  
        Console.WriteLine("Press any key to exit");  
        Console.ReadKey();  
    }  
  
    private static void QueryFilesBySize()  
    {  
        string startFolder = @"c:\program files\Microsoft Visual Studio 9.0\";  
  
        // Take a snapshot of the file system.  
        System.IO.DirectoryInfo dir = new System.IO.DirectoryInfo(startFolder);  
  
        // This method assumes that the application has discovery permissions  
        // for all folders under the specified path.  
        IEnumerable<System.IO.FileInfo> fileList = dir.GetFiles("*.*", System.IO.SearchOption.AllDirectories);  
  
        //Return the size of the largest file  
        long maxSize =  
            (from file in fileList  
             let len = GetFileLength(file)  
             select len)  
             .Max();  
  
        Console.WriteLine("The length of the largest file under {0} is {1}",  
            startFolder, maxSize);  
  
        // Return the FileInfo object for the largest file  
        // by sorting and selecting from beginning of list  
        System.IO.FileInfo longestFile =  
            (from file in fileList  
             let len = GetFileLength(file)  
             where len > 0  
             orderby len descending  
             select file)  
            .First();  
  
        Console.WriteLine("The largest file under {0} is {1} with a length of {2} bytes",  
                            startFolder, longestFile.FullName, longestFile.Length);  
  
        //Return the FileInfo of the smallest file  
        System.IO.FileInfo smallestFile =  
            (from file in fileList  
             let len = GetFileLength(file)  
             where len > 0  
             orderby len ascending  
             select file).First();  
  
        Console.WriteLine("The smallest file under {0} is {1} with a length of {2} bytes",  
                            startFolder, smallestFile.FullName, smallestFile.Length);  
  
        //Return the FileInfos for the 10 largest files  
        // queryTenLargest is an IEnumerable<System.IO.FileInfo>  
        var queryTenLargest =  
            (from file in fileList  
             let len = GetFileLength(file)  
             orderby len descending  
             select file).Take(10);  
  
        Console.WriteLine("The 10 largest files under {0} are:", startFolder);  
  
        foreach (var v in queryTenLargest)  
        {  
            Console.WriteLine("{0}: {1} bytes", v.FullName, v.Length);  
        }  
  
        // Group the files according to their size, leaving out  
        // files that are less than 200000 bytes.   
        var querySizeGroups =  
            from file in fileList  
            let len = GetFileLength(file)  
            where len > 0  
            group file by (len / 100000) into fileGroup  
            where fileGroup.Key >= 2  
            orderby fileGroup.Key descending  
            select fileGroup;  
  
        foreach (var filegroup in querySizeGroups)  
        {  
            Console.WriteLine(filegroup.Key.ToString() + "00000");  
            foreach (var item in filegroup)  
            {  
                Console.WriteLine("\t{0}: {1}", item.Name, item.Length);  
            }  
        }  
    }  
  
    // This method is used to swallow the possible exception  
    // that can be raised when accessing the FileInfo.Length property.  
    // In this particular case, it is safe to swallow the exception.  
    static long GetFileLength(System.IO.FileInfo fi)  
    {  
        long retval;  
        try  
        {  
            retval = fi.Length;  
        }  
        catch (System.IO.FileNotFoundException)  
        {  
            // If a file is no longer present,  
            // just add zero bytes to the total.  
            retval = 0;  
        }  
        return retval;  
    }  
  
}  
```

若要返回一个或多个完整的 [FileInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.fileinfo) 对象，查询必须首先检查数据中的每个对象，然后按其 Length 属性值对它们进行排序。 随后它便可以返回具有最大长度的单个对象或对象序列。 使用 [First](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.first) 返回列表中的第一个元素。 使用 [Take](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.take) 返回前 n 个元素。 指定降序排序顺序可将最小元素置于列表开头。

查询调用单独的方法来获取文件大小（以字节为单位），以便使用在以下情况下会引发的可能异常：自在 `GetFiles` 调用中创建了 [FileInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.fileinfo) 对象以来的时间段内，在其他线程中删除了文件。 即使创建了 [FileInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.fileinfo) 对象，该异常也可能出现，因为 [FileInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.fileinfo) 对象会在首次访问其 [Length](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.fileinfo.length) 属性时，尝试使用最新大小（以字节为单位）刷新该属性。 通过将此操作置于查询外部的 try-catch 块中，我们可遵循在查询中避免可能导致副作用的操作这一规则。一般情况下，在使用异常时必须格外谨慎，以确保应用程序不会处于未知状态。

#### 编译代码

创建面向 .NET Framework 3.5 或更高版本的项目，此项目包含对 System.Core.dll 的引用和针对 System.Linq 和 System.IO 命名空间的 `using` 指令。

### [How to: Query for Duplicate Files in a Directory Tree (LINQ)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoqueryforduplicatefilesinadirectorytreelinq)

有时，具有相同名称的文件可能位于多个文件夹中。 例如，在 Visual Studio 安装文件夹下，多个文件夹中都有 readme.htm 文件。 此示例显示如何在指定根文件夹下查询此类重复文件名。 第二个示例显示如何查询大小和创建时间都匹配的文件。

#### 示例

```csharp
class QueryDuplicateFileNames  
{  
    static void Main(string[] args)  
    {  
        // Uncomment QueryDuplicates2 to run that query.  
        QueryDuplicates();  
        // QueryDuplicates2();  
  
        // Keep the console window open in debug mode.  
        Console.WriteLine("Press any key to exit.");  
        Console.ReadKey();  
    }  
  
    static void QueryDuplicates()  
    {  
        // Change the root drive or folder if necessary  
        string startFolder = @"c:\program files\Microsoft Visual Studio 9.0\";  
  
        // Take a snapshot of the file system.  
        System.IO.DirectoryInfo dir = new System.IO.DirectoryInfo(startFolder);  
  
        // This method assumes that the application has discovery permissions  
        // for all folders under the specified path.  
        IEnumerable<System.IO.FileInfo> fileList = dir.GetFiles("*.*", System.IO.SearchOption.AllDirectories);  
  
        // used in WriteLine to keep the lines shorter  
        int charsToSkip = startFolder.Length;  
  
        // var can be used for convenience with groups.  
        var queryDupNames =  
            from file in fileList  
            group file.FullName.Substring(charsToSkip) by file.Name into fileGroup  
            where fileGroup.Count() > 1  
            select fileGroup;  
  
        // Pass the query to a method that will  
        // output one page at a time.  
        PageOutput<string, string>(queryDupNames);  
    }  
  
    // A Group key that can be passed to a separate method.  
    // Override Equals and GetHashCode to define equality for the key.  
    // Override ToString to provide a friendly name for Key.ToString()  
    class PortableKey  
    {  
        public string Name { get; set; }  
        public DateTime CreationTime { get; set; }  
        public long Length { get; set; }  
  
        public override bool Equals(object obj)  
        {  
            PortableKey other = (PortableKey)obj;  
            return other.CreationTime == this.CreationTime &&  
                   other.Length == this.Length &&  
                   other.Name == this.Name;  
        }  
  
        public override int GetHashCode()  
        {  
            string str = $"{this.CreationTime}{this.Length}{this.Name}";
            return str.GetHashCode();  
        }  
        public override string ToString()  
        {  
            return $"{this.Name} {this.Length} {this.CreationTime}";
        }  
    }  
    static void QueryDuplicates2()  
    {  
        // Change the root drive or folder if necessary.  
        string startFolder = @"c:\program files\Microsoft Visual Studio 9.0\Common7";  
  
        // Make the lines shorter for the console display  
        int charsToSkip = startFolder.Length;  
  
        // Take a snapshot of the file system.  
        System.IO.DirectoryInfo dir = new System.IO.DirectoryInfo(startFolder);  
        IEnumerable<System.IO.FileInfo> fileList = dir.GetFiles("*.*", System.IO.SearchOption.AllDirectories);  
  
        // Note the use of a compound key. Files that match  
        // all three properties belong to the same group.  
        // A named type is used to enable the query to be  
        // passed to another method. Anonymous types can also be used  
        // for composite keys but cannot be passed across method boundaries  
        //   
        var queryDupFiles =  
            from file in fileList  
            group file.FullName.Substring(charsToSkip) by  
                new PortableKey { Name = file.Name, CreationTime = file.CreationTime, Length = file.Length } into fileGroup  
            where fileGroup.Count() > 1  
            select fileGroup;  
  
        var list = queryDupFiles.ToList();  
  
        int i = queryDupFiles.Count();  
  
        PageOutput<PortableKey, string>(queryDupFiles);  
    }  
  
    // A generic method to page the output of the QueryDuplications methods  
    // Here the type of the group must be specified explicitly. "var" cannot  
    // be used in method signatures. This method does not display more than one  
    // group per page.  
    private static void PageOutput<K, V>(IEnumerable<System.Linq.IGrouping<K, V>> groupByExtList)  
    {  
        // Flag to break out of paging loop.  
        bool goAgain = true;  
  
        // "3" = 1 line for extension + 1 for "Press any key" + 1 for input cursor.  
        int numLines = Console.WindowHeight - 3;  
  
        // Iterate through the outer collection of groups.  
        foreach (var filegroup in groupByExtList)  
        {  
            // Start a new extension at the top of a page.  
            int currentLine = 0;  
  
            // Output only as many lines of the current group as will fit in the window.  
            do  
            {  
                Console.Clear();  
                Console.WriteLine("Filename = {0}", filegroup.Key.ToString() == String.Empty ? "[none]" : filegroup.Key.ToString());  
  
                // Get 'numLines' number of items starting at number 'currentLine'.  
                var resultPage = filegroup.Skip(currentLine).Take(numLines);  
  
                //Execute the resultPage query  
                foreach (var fileName in resultPage)  
                {  
                    Console.WriteLine("\t{0}", fileName);  
                }  
  
                // Increment the line counter.  
                currentLine += numLines;  
  
                // Give the user a chance to escape.  
                Console.WriteLine("Press any key to continue or the 'End' key to break...");  
                ConsoleKey key = Console.ReadKey().Key;  
                if (key == ConsoleKey.End)  
                {  
                    goAgain = false;  
                    break;  
                }  
            } while (currentLine < filegroup.Count());  
  
            if (goAgain == false)  
                break;  
        }  
    }  
}  
```

第一个查询使用简单键来确定匹配；此查询可以找到名称相同但内容可能不同的文件。 第二个查询使用复合键来匹配 [FileInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.fileinfo) 对象的 3 个属性。 此查询更可能找到名称相同且内容相似或相同的文件。

#### 编译代码

创建面向 .NET Framework 3.5 或更高版本的项目，此项目包含对 System.Core.dll 的引用和针对 System.Linq 和 System.IO 命名空间的 `using` 指令。

### [How to: Query the Contents of Files in a Folder (LINQ)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoquerythecontentsoffilesinafolderlin)

此示例演示如何查询指定目录树中的所有文件、打开每个文件并检查其内容。 此类技术可用于对目录树的内容创建索引或反向索引。 此示例中执行的是简单的字符串搜索。 但是，可使用正则表达式执行类型更复杂的模式匹配。 有关详细信息，请参阅[如何：将 LINQ 查询与正则表达式合并 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-combine-linq-queries-with-regular-expressions)。

#### 示例

```csharp
class QueryContents  
{  
    public static void Main()  
    {  
        // Modify this path as necessary.  
        string startFolder = @"c:\program files\Microsoft Visual Studio 9.0\";  
  
        // Take a snapshot of the file system.  
        System.IO.DirectoryInfo dir = new System.IO.DirectoryInfo(startFolder);  
  
        // This method assumes that the application has discovery permissions  
        // for all folders under the specified path.  
        IEnumerable<System.IO.FileInfo> fileList = dir.GetFiles("*.*", System.IO.SearchOption.AllDirectories);  
  
        string searchTerm = @"Visual Studio";  
  
        // Search the contents of each file.  
        // A regular expression created with the RegEx class  
        // could be used instead of the Contains method.  
        // queryMatchingFiles is an IEnumerable<string>.  
        var queryMatchingFiles =  
            from file in fileList  
            where file.Extension == ".htm"  
            let fileText = GetFileText(file.FullName)  
            where fileText.Contains(searchTerm)  
            select file.FullName;  
  
        // Execute the query.  
        Console.WriteLine("The term \"{0}\" was found in:", searchTerm);  
        foreach (string filename in queryMatchingFiles)  
        {  
            Console.WriteLine(filename);  
        }  
  
        // Keep the console window open in debug mode.  
        Console.WriteLine("Press any key to exit");  
        Console.ReadKey();  
    }  
  
    // Read the contents of the file.  
    static string GetFileText(string name)  
    {  
        string fileContents = String.Empty;  
  
        // If the file has been deleted since we took   
        // the snapshot, ignore it and return the empty string.  
        if (System.IO.File.Exists(name))  
        {  
            fileContents = System.IO.File.ReadAllText(name);  
        }  
        return fileContents;  
    }  
}  
```

#### 编译代码

创建面向 .NET Framework 3.5 或更高版本的项目，此项目包含对 System.Core.dll 的引用和针对 System.Linq 和 System.IO 命名空间的 `using` 指令。

## [How to: Query an ArrayList with LINQ](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoqueryanarraylistwithlinq)

如果使用 LINQ 来查询非泛型 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable) 集合（例如 [ArrayList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.arraylist)），必须显式声明范围变量的类型，以反映集合中对象的特定类型。 例如，如果有 `Student` 对象的 [ArrayList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.arraylist)，那么 [from 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/from-clause)应如下所示：

```
var query = from Student s in arrList  
...  
```

通过指定范围变量的类型，可将 [ArrayList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.arraylist) 中的每项强制转换为 `Student`。

在查询表达式中使用显式类型范围变量等效于调用 [Cast](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.cast) 方法。 如果无法执行指定的强制转换，[Cast](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.cast) 将引发异常。[Cast](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.cast) 和 [OfType](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.oftype) 是两个标准查询运算符方法，可对非泛型 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable) 类型执行操作。 有关详细信息，请参阅[LINQ 查询操作中的类型关系](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/type-relationships-in-linq-query-operations)。

#### 示例

下面的示例演示对 [ArrayList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.arraylist) 的简单查询。 请注意，本示例在代码调用 [Add](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.arraylist.add) 方法时使用对象初始值设定项，但这不是必需的。

```csharp
using System;  
using System.Collections;  
using System.Linq;  
  
namespace NonGenericLINQ  
{  
    public class Student  
    {  
        public string FirstName { get; set; }  
        public string LastName { get; set; }  
        public int[] Scores { get; set; }  
    }  
  
    class Program  
    {  
        static void Main(string[] args)  
        {  
            ArrayList arrList = new ArrayList();  
            arrList.Add(  
                new Student  
                    {  
                        FirstName = "Svetlana", LastName = "Omelchenko", Scores = new int[] { 98, 92, 81, 60 }  
                    });  
            arrList.Add(  
                new Student  
                    {  
                        FirstName = "Claire", LastName = "O’Donnell", Scores = new int[] { 75, 84, 91, 39 }  
                    });  
            arrList.Add(  
                new Student  
                    {  
                        FirstName = "Sven", LastName = "Mortensen", Scores = new int[] { 88, 94, 65, 91 }  
                    });  
            arrList.Add(  
                new Student  
                    {  
                        FirstName = "Cesar", LastName = "Garcia", Scores = new int[] { 97, 89, 85, 82 }  
                    });  
  
            var query = from Student student in arrList  
                        where student.Scores[0] > 95  
                        select student;  
  
            foreach (Student s in query)  
                Console.WriteLine(s.LastName + ": " + s.Scores[0]);  
  
            // Keep the console window open in debug mode.  
            Console.WriteLine("Press any key to exit.");  
            Console.ReadKey();  
        }  
    }  
}  
/* Output:   
    Omelchenko: 98  
    Garcia: 97  
*/  
```

## [How to: Add Custom Methods for LINQ Queries](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoaddcustommethodsforlinqqueries)

可通过向 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 接口添加扩展方法扩展可用于 LINQ 查询的方法集。 例如，除了标准平均值或最大值运算，还可以创建自定义聚合方法，从一系列值计算单个值。 此外可以创建一个方法，用作一个值序列的自定义筛选器或用于对其进行特定数据转换，并返回新的序列。 [Distinct](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.distinct)、[Skip](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.skip) 和 [Reverse](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.reverse) 就是此类方法的示例。

扩展 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 接口时，可以将自定义方法应用于任何可枚举集合。 有关详细信息，请参阅[扩展方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/extension-methods)。

### 添加聚合对象

聚合方法可从一组值计算单个值。 LINQ 提供多个聚合方法，包括 [Average](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.average)、[Min](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.min) 和 [Max](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.max)。 可以通过向[IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 接口添加扩展方法来创建自己的聚合方法。

下面的代码示例演示如何创建名为 `Median` 的扩展方法来计算类型为 `double` 的数字序列的中间值。

```csharp
public static class LINQExtension  
{  
    public static double Median(this IEnumerable<double> source)  
    {  
        if (source.Count() == 0)  
        {  
            throw new InvalidOperationException("Cannot compute median for an empty set.");  
        }  
  
        var sortedList = from number in source  
                         orderby number  
                         select number;  
  
        int itemIndex = (int)sortedList.Count() / 2;  
  
        if (sortedList.Count() % 2 == 0)  
        {  
            // Even number of items.  
            return (sortedList.ElementAt(itemIndex) + sortedList.ElementAt(itemIndex - 1)) / 2;  
        }  
        else  
        {  
            // Odd number of items.  
            return sortedList.ElementAt(itemIndex);  
        }  
    }  
}  
```

使用从 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 接口调用其他聚合方法的方式为任何可枚举集合调用此扩展方法。

下面的代码示例说明如何为类型 `double` 的数组使用 `Median` 方法。

```csharp
double[] numbers1 = { 1.9, 2, 8, 4, 5.7, 6, 7.2, 0 };  
  
var query1 = numbers1.Median();  
  
Console.WriteLine("double: Median = " + query1);  
```

```csharp
/*  
 This code produces the following output:  
  
 Double: Median = 4.85  
*/  
```

#### 重载聚合方法以接受各种类型

可以重载聚合方法，以便其接受各种类型的序列。 标准做法是为每种类型都创建一个重载。 另一种方法是创建一个采用泛型类型的重载，并使用委托将其转换为特定类型。 还可以将两种方法结合。

#### 为每种类型创建重载

可以为要支持的每种类型创建特定重载。 下面的代码示例演示 `integer` 类型的 `Median` 方法的重载。

```csharp
//int overload  
  
public static double Median(this IEnumerable<int> source)  
{  
    return (from num in source select (double)num).Median();  
}  
```

现在便可以为 `integer` 和 `double` 类型调用 `Median` 重载了，如以下代码中所示：

C#复制

```csharp
double[] numbers1 = { 1.9, 2, 8, 4, 5.7, 6, 7.2, 0 };  
  
var query1 = numbers1.Median();  
  
Console.WriteLine("double: Median = " + query1);  
```

```csharp
int[] numbers2 = { 1, 2, 3, 4, 5 };  
  
var query2 = numbers2.Median();  
  
Console.WriteLine("int: Median = " + query2);  
```

```csharp
/*  
 This code produces the following output:  
  
 Double: Median = 4.85  
 Integer: Median = 3  
*/  
```

#### 创建一般重载

还可以创建接受泛型对象序列的重载。 此重载采用委托作为参数，并使用该参数将泛型类型的对象序列转换为特定类型。

下面的代码展示 `Median` 方法的重载，该重载将 [Func](https://docs.microsoft.com/zh-cn/dotnet/api/system.func-2) 委托作为参数。 此委托采用泛型类型 T 的对象，并返回类型 `double` 的对象。

```csharp
// Generic overload.  
  
public static double Median<T>(this IEnumerable<T> numbers,  
                       Func<T, double> selector)  
{  
    return (from num in numbers select selector(num)).Median();  
}  
```

现在，可以为任何类型的对象序列调用 `Median` 方法。 如果类型不具有自己的方法重载，必须手动传递委托参数。 在 C# 中，可以使用 lambda 表达式实现此目的。 此外，仅限在 Visual Basic 中，如果使用 `Aggregate` 或 `Group By` 子句而不是方法调用，可以传递此子句范围内的任何值或表达式。

下面的代码示例演示如何为整数数组和字符串数组调用 `Median` 方法。 对于字符串，将计算数组中字符串长度的中值。 该示例演示如何将 [Func](https://docs.microsoft.com/zh-cn/dotnet/api/system.func-2) 委托参数传递给每个用例的 `Median` 方法。

```csharp
int[] numbers3 = { 1, 2, 3, 4, 5 };  
  
/*   
  You can use the num=>num lambda expression as a parameter for the Median method   
  so that the compiler will implicitly convert its value to double.  
  If there is no implicit conversion, the compiler will display an error message.            
*/  
  
var query3 = numbers3.Median(num => num);  
  
Console.WriteLine("int: Median = " + query3);  
  
string[] numbers4 = { "one", "two", "three", "four", "five" };  
  
// With the generic overload, you can also use numeric properties of objects.  
  
var query4 = numbers4.Median(str => str.Length);  
  
Console.WriteLine("String: Median = " + query4);  
  
/*  
 This code produces the following output:  
  
 Integer: Median = 3  
 String: Median = 4  
*/  
```

### 添加返回集合的方法

可以使用会返回值序列的自定义查询方法来扩展 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 接口。 在这种情况下，该方法必须返回类型 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的集合。 此类方法可用于将筛选器或数据转换应用于值序列。

下面的示例演示如何创建名为 `AlternateElements` 的扩展方法，该方法从集合中第一个元素开始按相隔一个元素的方式返回集合中的元素。

```csharp
// Extension method for the IEnumerable<T> interface.   
// The method returns every other element of a sequence.  
  
public static IEnumerable<T> AlternateElements<T>(this IEnumerable<T> source)  
{  
    List<T> list = new List<T>();  
  
    int i = 0;  
  
    foreach (var element in source)  
    {  
        if (i % 2 == 0)  
        {  
            list.Add(element);  
        }  
  
        i++;  
    }  
  
    return list;  
}  
```

可使用从 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 接口调用其他方法的方式对任何可枚举集合调用此扩展方法，如下面的代码中所示：

```csharp
string[] strings = { "a", "b", "c", "d", "e" };  
  
var query = strings.AlternateElements();  
  
foreach (var element in query)  
{  
    Console.WriteLine(element);  
}  
/*  
 This code produces the following output:  
  
 a  
 c  
 e  
*/  
```