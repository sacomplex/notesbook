# [Query Keywords](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/query-keywords)

本部分包含在查询表达式中使用的上下文关键字。

| 子句                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [from](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/from-clause) | 指定数据源和范围变量（类似于迭代变量）。                     |
| [where](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/where-clause) | 基于由逻辑 AND 和 OR 运算符（`&&` 或 `||`）分隔的一个或多个布尔表达式筛选源元素。 |
| [select](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/select-clause) | 指定执行查询时，所返回序列中元素的类型和形状。               |
| [group](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/group-clause) | 根据指定的密钥值对查询结果分组。                             |
| [into](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/into) | 提供可作为对 join、group 或 select 子句结果引用的标识符。    |
| [orderby](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/orderby-clause) | 根据元素类型的默认比较器对查询结果进行升序或降序排序。       |
| [join](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/join-clause) | 基于两个指定匹配条件间的相等比较而联接两个数据源。           |
| [let](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/let-clause) | 引入范围变量，在查询表达式中存储子表达式结果。               |
| [in](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/in) | [join](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/join-clause) 子句中的上下文关键字。 |
| [on](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/on) | [join](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/join-clause) 子句中的上下文关键字。 |
| [equals](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/equals) | [join](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/join-clause) 子句中的上下文关键字。 |
| [by](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/by) | [group](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/group-clause) 子句中的上下文关键字。 |
| [ascending](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ascending) | [orderby](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/orderby-clause) 子句中的上下文关键字。 |
| [descending](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/descending) | [orderby](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/orderby-clause) 子句中的上下文关键字。 |

## [from clause](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/from-clause)

查询表达式必须以 `from` 子句开头。 此外，查询表达式可包含也以 `from` 子句开头的子查询。 `from` 子句指定下列各项：

- 将在其上运行查询或子查询的数据源。
- 表示源序列中每个元素的本地范围变量。

范围变量和数据源已强类型化。 `from` 子句中引用的数据源必须具有 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable)、[IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 类型之一，或 [IQueryable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.iqueryable-1) 等派生类型。

在下面的示例中，`numbers` 是数据源，`num` 是范围变量。 请注意，这两个变量都已强类型化，即使使用 [var](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/var) 关键字也是如此。

C#复制

```csharp
class LowNums
{
    static void Main()
    {   
        // A simple data source.
        int[] numbers = { 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };

        // Create the query.
        // lowNums is an IEnumerable<int>
        var lowNums = from num in numbers
            where num < 5
            select num;

        // Execute the query.
        foreach (int i in lowNums)
        {
            Console.Write(i + " ");
        }
    }        
}
// Output: 4 1 3 2 0
```

### 范围变量

数据源实现 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 时，编译器推断范围变量的类型。 例如，如果源具有 `IEnumerable<Customer>` 类型，则范围变量会被推断为 `Customer`。 仅在以下情况下必须显式指定类型：源是 [ArrayList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.arraylist) 等非泛型 `IEnumerable` 类型时。 有关详细信息，请参阅[如何：使用 LINQ 查询 ArrayList](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-query-an-arraylist-with-linq)。

在以上示例中，`num` 推断为 `int` 类型。 由于强类型化了范围变量，所以可以在其上调用方法，或将其用于其他操作中。 例如，不再编写 `select num`，而编写 `select num.ToString()`，使查询表达式返回字符串序列，而不是整数序列。 或者可以编写 `select num + 10`，使表达式返回序列 14、11、13、12、10。 有关详细信息，请参阅 [select 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/select-clause)。

范围变量与 [foreach](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/foreach-in) 语句中的迭代变量类似，一项非常重要的区别除外：范围变量从不实际存储来自源的数据。它只是一种语法上的便利，让查询能够描述执行查询时将发生的情况。 有关详细信息，请参阅 [LINQ 查询简介 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/introduction-to-linq-queries)。

### 复合 from 子句

在某些情况下，源序列中的每个元素可能本身就是一个序列，或者包含一个序列。 例如，数据源可能是 `IEnumerable<Student>`，其中序列中的每个学生对象都包含测试分数的列表。 要访问每个 `Student` 元素的内部列表，可以使用复合 `from` 子句。 这种方法类似于使用嵌套的 [foreach](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/foreach-in) 语句。 可以向任一 `from`子句添加 [where](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/partial-method) 或 [orderby](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/orderby-clause) 子句筛选结果。 下面的示例演示 `Student` 对象的序列，其中每个对象都包含一个整数内部 `List`，表示测验分数。 访问内部列表可使用复合 `from` 子句。 如有必要，可以在这两个 `from` 子句间插入子句。

C#复制

```csharp
class CompoundFrom
{
    // The element type of the data source.
    public class Student
    {
        public string LastName { get; set; }
        public List<int> Scores {get; set;}
    }

    static void Main()
    {
        
        // Use a collection initializer to create the data source. Note that 
        // each element in the list contains an inner sequence of scores.
        List<Student> students = new List<Student>
        {
           new Student {LastName="Omelchenko", Scores= new List<int> {97, 72, 81, 60}},
           new Student {LastName="O'Donnell", Scores= new List<int> {75, 84, 91, 39}},
           new Student {LastName="Mortensen", Scores= new List<int> {88, 94, 65, 85}},
           new Student {LastName="Garcia", Scores= new List<int> {97, 89, 85, 82}},
           new Student {LastName="Beebe", Scores= new List<int> {35, 72, 91, 70}} 
        };        

        // Use a compound from to access the inner sequence within each element.
        // Note the similarity to a nested foreach statement.
        var scoreQuery = from student in students
                         from score in student.Scores
                            where score > 90
                            select new { Last = student.LastName, score };
                    
        // Execute the queries.
        Console.WriteLine("scoreQuery:");
        // Rest the mouse pointer on scoreQuery in the following line to 
        // see its type. The type is IEnumerable<'a>, where 'a is an 
        // anonymous type defined as new {string Last, int score}. That is,
        // each instance of this anonymous type has two members, a string 
        // (Last) and an int (score).
        foreach (var student in scoreQuery)
        {
            Console.WriteLine("{0} Score: {1}", student.Last, student.score);
        }
        
        // Keep the console window open in debug mode.
        Console.WriteLine("Press any key to exit.");
        Console.ReadKey();
    }       
}
/*
scoreQuery:
Omelchenko Score: 97
O'Donnell Score: 91
Mortensen Score: 94
Garcia Score: 97
Beebe Score: 91
*/
```

### 使用多个 from 子句执行联接

复合 `from` 子句用于访问单个数据源中的内部集合。 但是，查询也可以包含多个 `from` 子句，这些子句从独立的数据源生成补充查询。 通过此方法，可以执行使用 [join 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/join-clause) 无法实现的某类联接操作。

下面的示例演示两个 `from` 子句如何用于形成两个数据源的完全交叉联接。

```csharp
class CompoundFrom2
{
    static void Main()
    {
        char[] upperCase = { 'A', 'B', 'C' };
        char[] lowerCase = { 'x', 'y', 'z' };

        // The type of joinQuery1 is IEnumerable<'a>, where 'a
        // indicates an anonymous type. This anonymous type has two
        // members, upper and lower, both of type char.
        var joinQuery1 =
            from upper in upperCase
            from lower in lowerCase
            select new { upper, lower };

        // The type of joinQuery2 is IEnumerable<'a>, where 'a
        // indicates an anonymous type. This anonymous type has two
        // members, upper and lower, both of type char.
        var joinQuery2 =
            from lower in lowerCase
            where lower != 'x'
            from upper in upperCase
            select new { lower, upper };


        // Execute the queries.
        Console.WriteLine("Cross join:");
        // Rest the mouse pointer on joinQuery1 to verify its type.
        foreach (var pair in joinQuery1)
        {
            Console.WriteLine("{0} is matched to {1}", pair.upper, pair.lower);
        }

        Console.WriteLine("Filtered non-equijoin:");
        // Rest the mouse pointer over joinQuery2 to verify its type.
        foreach (var pair in joinQuery2)
        {
            Console.WriteLine("{0} is matched to {1}", pair.lower, pair.upper);
        }

        // Keep the console window open in debug mode.
        Console.WriteLine("Press any key to exit.");
        Console.ReadKey();
    }
}
/* Output:
        Cross join:
        A is matched to x
        A is matched to y
        A is matched to z
        B is matched to x
        B is matched to y
        B is matched to z
        C is matched to x
        C is matched to y
        C is matched to z
        Filtered non-equijoin:
        y is matched to A
        y is matched to B
        y is matched to C
        z is matched to A
        z is matched to B
        z is matched to C
        */
```

若要详细了解使用多个 `from` 子句的联接操作，请参阅[执行左外部联结](https://docs.microsoft.com/zh-cn/dotnet/csharp/linq/perform-left-outer-joins)。

## [where clause](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/where-clause)

`where` 子句用在查询表达式中，用于指定将在查询表达式中返回数据源中的哪些元素。 它将一个布尔条件（谓词）应用于每个源元素（由范围变量引用），并返回满足指定条件的元素。 一个查询表达式可以包含多个 `where` 子句，一个子句可以包含多个谓词子表达式。

### 示例

在下面的示例中，`where` 子句筛选出除小于五的数字外的所有数字。 如果删除 `where` 子句，则会返回数据源中的所有数字。 表达式 `num < 5` 是应用于每个元素的谓词。

C#复制

```csharp
class WhereSample
{
    static void Main()
    {   
        // Simple data source. Arrays support IEnumerable<T>.
        int[] numbers = { 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };

        // Simple query with one predicate in where clause.
        var queryLowNums =
            from num in numbers
            where num < 5
            select num;

        // Execute the query.
        foreach (var s in queryLowNums)
        {
            Console.Write(s.ToString() + " ");
        }
    }
}
//Output: 4 1 3 2 0
```

### 示例

在单个 `where` 子句中，可以使用 [&&](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/conditional-and-operator) 和 [||](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/conditional-or-operator) 运算符根据需要指定任意多个谓词。 在下面的示例中，查询将指定两个谓词，以便只选择小于五的偶数。

C#复制

```csharp
class WhereSample2
{
    static void Main()
    {
        // Data source.
        int[] numbers = { 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };

        // Create the query with two predicates in where clause.
        var queryLowNums2 =
            from num in numbers
            where num < 5 && num % 2 == 0
            select num;

        // Execute the query
        foreach (var s in queryLowNums2)
        {
            Console.Write(s.ToString() + " ");
        }
        Console.WriteLine();

        // Create the query with two where clause.
        var queryLowNums3 =
            from num in numbers
            where num < 5
            where num % 2 == 0
            select num;

        // Execute the query
        foreach (var s in queryLowNums3)
        {
            Console.Write(s.ToString() + " ");
        }

    }
}
// Output: 
// 4 2 0
// 4 2 0
```

### 示例

一个 `where` 子句可以包含一个或多个返回布尔值的方法。 在下面的示例中，`where` 子句使用一种方法来确定范围变量的当前值是偶数还是奇数。

C#复制

```csharp
class WhereSample3
{       
    static void Main()
    {
        // Data source
        int[] numbers = { 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };

        // Create the query with a method call in the where clause.
        // Note: This won't work in LINQ to SQL unless you have a
        // stored procedure that is mapped to a method by this name.
        var queryEvenNums =
            from num in numbers
            where IsEven(num)
            select num;

         // Execute the query.
        foreach (var s in queryEvenNums)
        {
            Console.Write(s.ToString() + " ");
        }
    }

    // Method may be instance method or static method.
    static bool IsEven(int i)
    {
        return i % 2 == 0;
    }    
}
//Output: 4 8 6 2 0
```

### 备注

`where` 子句是一种筛选机制。 除了不能是第一个或最后一个子句外，它几乎可以放在查询表达式中的任何位置。 `where` 子句可以出现在 [group](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/group-clause) 子句的前面或后面，具体取决于时必须在对源元素进行分组之前还是之后来筛选源元素。

如果指定的谓词对于数据源中的元素无效，则会发生编译时错误。 这是 LINQ 提供的强类型检查的一个优点。

在编译时，`where` 关键字将转换为对 [Where](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.where) 标准查询运算符方法的调用。

## [select clause](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/select-clause)

在查询表达式中，`select` 子句指定在执行查询时产生的值的类型。 根据计算所有以前的子句以及根据 `select`子句本身的所有表达式得出结果。 查询表达式必须以 `select` 子句或 [group](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/group-clause) 子句结尾。

以下示例演示查询表达式中的简单的 `select` 子句。

C#复制

```csharp
class SelectSample1
{   
    static void Main()
    {           
        //Create the data source
        List<int> Scores = new List<int>() { 97, 92, 81, 60 };

        // Create the query.
        IEnumerable<int> queryHighScores =
            from score in Scores
            where score > 80
            select score;

        // Execute the query.
        foreach (int i in queryHighScores)
        {
            Console.Write(i + " ");
        }            
    }
}
//Output: 97 92 81
```

`select` 子句生成的序列的类型确定查询变量 `queryHighScores` 的类型。 在最简单的情况下，`select` 子句仅指定范围变量。 这将导致返回的序列包含与数据源类型相同的元素。 有关详细信息，请参阅 [LINQ 查询操作中的类型关系](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/type-relationships-in-linq-query-operations)。 但是，`select` 子句还提供了强大的机制，用于将源数据转换（或投影）为新类型。 有关详细信息，请参阅[使用 LINQ 进行数据转换 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/data-transformations-with-linq)。

### 示例

以下示例展示 `select` 子句可能采用的所有不同窗体。 在每个查询中，请注意 `select` 子句和查询变量（`studentQuery1`、`studentQuery2` 等）类型之间的关系。

```csharp
    class SelectSample2
    {
        // Define some classes
        public class Student
        {
            public string First { get; set; }
            public string Last { get; set; }
            public int ID { get; set; }
            public List<int> Scores;
            public ContactInfo GetContactInfo(SelectSample2 app, int id)
            {
                ContactInfo cInfo =
                    (from ci in app.contactList
                    where ci.ID == id
                    select ci)
                    .FirstOrDefault();
                    
                return cInfo;
            }

            public override string ToString()
            {
                return First + " " + Last + ":" + ID;
            }
        }

        public class ContactInfo
        {
            public int ID { get; set; }
            public string Email { get; set; }
            public string Phone { get; set; }
            public override string ToString() { return Email + "," + Phone; }
        }

        public class ScoreInfo
        {
            public double Average { get; set; }
            public int ID { get; set; }
        }

        // The primary data source
        List<Student> students = new List<Student>()
        {
             new Student {First="Svetlana", Last="Omelchenko", ID=111, Scores= new List<int>() {97, 92, 81, 60}},
             new Student {First="Claire", Last="O'Donnell", ID=112, Scores= new List<int>() {75, 84, 91, 39}},
             new Student {First="Sven", Last="Mortensen", ID=113, Scores= new List<int>() {88, 94, 65, 91}},
             new Student {First="Cesar", Last="Garcia", ID=114, Scores= new List<int>() {97, 89, 85, 82}},
        };

        // Separate data source for contact info.
        List<ContactInfo> contactList = new List<ContactInfo>()
        {
            new ContactInfo {ID=111, Email="SvetlanO@Contoso.com", Phone="206-555-0108"},
            new ContactInfo {ID=112, Email="ClaireO@Contoso.com", Phone="206-555-0298"},
            new ContactInfo {ID=113, Email="SvenMort@Contoso.com", Phone="206-555-1130"},
            new ContactInfo {ID=114, Email="CesarGar@Contoso.com", Phone="206-555-0521"}
        };


        static void Main(string[] args)
        {
            SelectSample2 app = new SelectSample2();

            // Produce a filtered sequence of unmodified Students.
            IEnumerable<Student> studentQuery1 =
                from student in app.students
                where student.ID > 111
                select student;

            Console.WriteLine("Query1: select range_variable");
            foreach (Student s in studentQuery1)
            {
                Console.WriteLine(s.ToString());
            }

            // Produce a filtered sequence of elements that contain
            // only one property of each Student.
            IEnumerable<String> studentQuery2 =
                from student in app.students
                where student.ID > 111
                select student.Last;

            Console.WriteLine("\r\n studentQuery2: select range_variable.Property");
            foreach (string s in studentQuery2)
            {
                Console.WriteLine(s);
            }

            // Produce a filtered sequence of objects created by
            // a method call on each Student.
            IEnumerable<ContactInfo> studentQuery3 =
                from student in app.students
                where student.ID > 111
                select student.GetContactInfo(app, student.ID);

            Console.WriteLine("\r\n studentQuery3: select range_variable.Method");
            foreach (ContactInfo ci in studentQuery3)
            {
                Console.WriteLine(ci.ToString());
            }

            // Produce a filtered sequence of ints from
            // the internal array inside each Student.
            IEnumerable<int> studentQuery4 =
                from student in app.students
                where student.ID > 111
                select student.Scores[0];

            Console.WriteLine("\r\n studentQuery4: select range_variable[index]");
            foreach (int i in studentQuery4)
            {
                Console.WriteLine("First score = {0}", i);
            }

            // Produce a filtered sequence of doubles 
            // that are the result of an expression.
            IEnumerable<double> studentQuery5 =
                from student in app.students
                where student.ID > 111
                select student.Scores[0] * 1.1;

            Console.WriteLine("\r\n studentQuery5: select expression");
            foreach (double d in studentQuery5)
            {
                Console.WriteLine("Adjusted first score = {0}", d);
            }

            // Produce a filtered sequence of doubles that are
            // the result of a method call.
            IEnumerable<double> studentQuery6 =
                from student in app.students
                where student.ID > 111
                select student.Scores.Average();

            Console.WriteLine("\r\n studentQuery6: select expression2");
            foreach (double d in studentQuery6)
            {
                Console.WriteLine("Average = {0}", d);
            }

            // Produce a filtered sequence of anonymous types
            // that contain only two properties from each Student.
            var studentQuery7 =
                from student in app.students
                where student.ID > 111
                select new { student.First, student.Last };

            Console.WriteLine("\r\n studentQuery7: select new anonymous type");
            foreach (var item in studentQuery7)
            {
                Console.WriteLine("{0}, {1}", item.Last, item.First);
            }

            // Produce a filtered sequence of named objects that contain
            // a method return value and a property from each Student.
            // Use named types if you need to pass the query variable 
            // across a method boundary.
            IEnumerable<ScoreInfo> studentQuery8 =
                from student in app.students
                where student.ID > 111
                select new ScoreInfo
                {
                    Average = student.Scores.Average(),
                    ID = student.ID
                };

            Console.WriteLine("\r\n studentQuery8: select new named type");
            foreach (ScoreInfo si in studentQuery8)
            {
                Console.WriteLine("ID = {0}, Average = {1}", si.ID, si.Average);
            }

            // Produce a filtered sequence of students who appear on a contact list
            // and whose average is greater than 85.
            IEnumerable<ContactInfo> studentQuery9 =
                from student in app.students
                where student.Scores.Average() > 85
                join ci in app.contactList on student.ID equals ci.ID
                select ci;

            Console.WriteLine("\r\n studentQuery9: select result of join clause");
            foreach (ContactInfo ci in studentQuery9)
            {
                Console.WriteLine("ID = {0}, Email = {1}", ci.ID, ci.Email);
            }

            // Keep the console window open in debug mode
            Console.WriteLine("Press any key to exit.");
            Console.ReadKey();
            }
        }
    /* Output
        Query1: select range_variable
        Claire O'Donnell:112
        Sven Mortensen:113
        Cesar Garcia:114

        studentQuery2: select range_variable.Property
        O'Donnell
        Mortensen
        Garcia

        studentQuery3: select range_variable.Method
        ClaireO@Contoso.com,206-555-0298
        SvenMort@Contoso.com,206-555-1130
        CesarGar@Contoso.com,206-555-0521

        studentQuery4: select range_variable[index]
        First score = 75
        First score = 88
        First score = 97

        studentQuery5: select expression
        Adjusted first score = 82.5
        Adjusted first score = 96.8
        Adjusted first score = 106.7

        studentQuery6: select expression2
        Average = 72.25
        Average = 84.5
        Average = 88.25

        studentQuery7: select new anonymous type
        O'Donnell, Claire
        Mortensen, Sven
        Garcia, Cesar

        studentQuery8: select new named type
        ID = 112, Average = 72.25
        ID = 113, Average = 84.5
        ID = 114, Average = 88.25

        studentQuery9: select result of join clause
        ID = 114, Email = CesarGar@Contoso.com
*/
```

如前面示例中的 `studentQuery8` 所示，有时可能想要返回序列的元素仅包含一部分源元素属性。 通过让返回序列尽可能变小，可以减少内存需求并提高执行查询的速度。 在 `select` 子句中创建匿名类型并使用对象初始值设定项通过源元素中的相应属性初始化该类型可以完成此操作。 有关如何执行此操作的示例，请参阅[对象和集合初始值设定项](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/object-and-collection-initializers)。

### 备注

在编译时，`select` 子句被转换为 [Select](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.select) 标准查询运算符的方法调用。

## [group clause](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/group-clause)

`group` 子句返回一个 [IGrouping](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.igrouping-2) 对象序列，这些对象包含零个或更多与该组的键值匹配的项。例如，可以按照每个字符串中的第一个字母对字符串序列进行分组。 在这种情况下，第一个字母就是键，类型为[char](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/char)，并且存储在每个 [IGrouping](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.igrouping-2) 对象的 `Key` 属性中。 编译器可推断键的类型。

可以用 `group` 子句结束查询表达式，如以下示例所示：

C#复制

```csharp
// Query variable is an IEnumerable<IGrouping<char, Student>>
var studentQuery1 =
    from student in students
    group student by student.Last[0];
```

如果要对每个组执行附加查询操作，可使用上下文关键字 [into](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/into) 指定一个临时标识符。 使用 `into` 时，必须继续编写该查询，并最终使用一个`select` 语句或另一个 `group` 子句结束该查询，如以下代码摘录所示：

C#复制

```csharp
// Group students by the first letter of their last name
// Query variable is an IEnumerable<IGrouping<char, Student>>
var studentQuery2 =
    from student in students
    group student by student.Last[0] into g
    orderby g.Key
    select g;
```

对于含有和不含 `into` 的 `group`，本文中的“示例”部分提供有关其用法的更完整示例。

### 枚举查询分组的结果

由于 `group` 查询产生的 [IGrouping](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.igrouping-2) 对象实质上是一个由列表组成的列表，因此必须使用嵌套的 [foreach](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/foreach-in) 循环来访问每一组中的各个项。 外部循环用于循环访问组键，内部循环用于循环访问组本身包含的每个项。 组可能具有键，但没有元素。 下面的 `foreach` 循环执行上述代码示例中的查询：

C#复制

```csharp
// Iterate group items with a nested foreach. This IGrouping encapsulates
// a sequence of Student objects, and a Key of type char.
// For convenience, var can also be used in the foreach statement.
foreach (IGrouping<char, Student> studentGroup in studentQuery2)
{
     Console.WriteLine(studentGroup.Key);
     // Explicit type for student could also be used here.
     foreach (var student in studentGroup)
     {
         Console.WriteLine("   {0}, {1}", student.Last, student.First);
     }
 }
```

### 键类型

组键可以是任何类型，如字符串、内置数值类型、用户定义的命名类型或匿名类型。

#### 按字符串分组

上述代码示例使用 `char`。 可轻松改为指定字符串键，如完整的姓氏：

C#复制

```csharp
// Same as previous example except we use the entire last name as a key.
// Query variable is an IEnumerable<IGrouping<string, Student>>
var studentQuery3 =
    from student in students
    group student by student.Last;
```

#### 按布尔值分组

下面的示例演示使用布尔值作为键将结果划分成两个组。 请注意，该值由 `group` 子句中的子表达式生成。

C#复制

```csharp
class GroupSample1
{
    // The element type of the data source.
    public class Student
    {
        public string First { get; set; }
        public string Last { get; set; }
        public int ID { get; set; }
        public List<int> Scores;
    }

    public static List<Student> GetStudents()
    {
        // Use a collection initializer to create the data source. Note that each element
        //  in the list contains an inner sequence of scores.
        List<Student> students = new List<Student>
        {
           new Student {First="Svetlana", Last="Omelchenko", ID=111, Scores= new List<int> {97, 72, 81, 60}},
           new Student {First="Claire", Last="O'Donnell", ID=112, Scores= new List<int> {75, 84, 91, 39}},
           new Student {First="Sven", Last="Mortensen", ID=113, Scores= new List<int> {99, 89, 91, 95}},
           new Student {First="Cesar", Last="Garcia", ID=114, Scores= new List<int> {72, 81, 65, 84}},
           new Student {First="Debra", Last="Garcia", ID=115, Scores= new List<int> {97, 89, 85, 82}} 
        };

        return students;

    }

    static void Main()
    {
        // Obtain the data source.
        List<Student> students = GetStudents();

        // Group by true or false.
        // Query variable is an IEnumerable<IGrouping<bool, Student>>
        var booleanGroupQuery =
            from student in students
            group student by student.Scores.Average() >= 80; //pass or fail!

        // Execute the query and access items in each group
        foreach (var studentGroup in booleanGroupQuery)
        {
            Console.WriteLine(studentGroup.Key == true ? "High averages" : "Low averages");
            foreach (var student in studentGroup)
            {
                Console.WriteLine("   {0}, {1}:{2}", student.Last, student.First, student.Scores.Average());
            }
        }

        // Keep the console window open in debug mode.
        Console.WriteLine("Press any key to exit.");
        Console.ReadKey();
    }
}
/* Output:
  Low averages
   Omelchenko, Svetlana:77.5
   O'Donnell, Claire:72.25
   Garcia, Cesar:75.5
  High averages
   Mortensen, Sven:93.5
   Garcia, Debra:88.25
*/
```

#### 按数值范围分组

下一示例使用表达式创建表示百分比范围的数值组键。 请注意，该示例使用 [let](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/let-clause) 作为方法调用结果的方便存储位置，因此无需在 `group` 子句中调用该方法两次。 若要详细了解如何在查询表达式中安全地使用方法，请参阅[操作说明：在查询表达式中处理异常](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/linq-query-expressions/how-to-handle-exceptions-in-query-expressions)。

C#复制

```csharp
class GroupSample2
{
    // The element type of the data source.
    public class Student
    {
        public string First { get; set; }
        public string Last { get; set; }
        public int ID { get; set; }
        public List<int> Scores;
    }

    public static List<Student> GetStudents()
    {
        // Use a collection initializer to create the data source. Note that each element
        //  in the list contains an inner sequence of scores.
        List<Student> students = new List<Student>
        {
           new Student {First="Svetlana", Last="Omelchenko", ID=111, Scores= new List<int> {97, 72, 81, 60}},
           new Student {First="Claire", Last="O'Donnell", ID=112, Scores= new List<int> {75, 84, 91, 39}},
           new Student {First="Sven", Last="Mortensen", ID=113, Scores= new List<int> {99, 89, 91, 95}},
           new Student {First="Cesar", Last="Garcia", ID=114, Scores= new List<int> {72, 81, 65, 84}},
           new Student {First="Debra", Last="Garcia", ID=115, Scores= new List<int> {97, 89, 85, 82}} 
        };

        return students;

    }

    // This method groups students into percentile ranges based on their
    // grade average. The Average method returns a double, so to produce a whole
    // number it is necessary to cast to int before dividing by 10. 
    static void Main()
    {
        // Obtain the data source.
        List<Student> students = GetStudents();

        // Write the query.
        var studentQuery =
            from student in students
            let avg = (int)student.Scores.Average()
            group student by (avg / 10) into g
            orderby g.Key
            select g;            

        // Execute the query.
        foreach (var studentGroup in studentQuery)
        {
            int temp = studentGroup.Key * 10;
            Console.WriteLine("Students with an average between {0} and {1}", temp, temp + 10);
            foreach (var student in studentGroup)
            {
                Console.WriteLine("   {0}, {1}:{2}", student.Last, student.First, student.Scores.Average());
            }
        }

        // Keep the console window open in debug mode.
        Console.WriteLine("Press any key to exit.");
        Console.ReadKey();
    }
}
/* Output:
     Students with an average between 70 and 80
       Omelchenko, Svetlana:77.5
       O'Donnell, Claire:72.25
       Garcia, Cesar:75.5
     Students with an average between 80 and 90
       Garcia, Debra:88.25
     Students with an average between 90 and 100
       Mortensen, Sven:93.5
 */
```

#### 按复合键分组

希望按照多个键对元素进行分组时，可使用复合键。 使用匿名类型或命名类型来存储键元素，创建复合键。 在下面的示例中，假定已经使用名为 `surname` 和 `city` 的两个成员声明了类 `Person`。 `group` 子句会为每组姓氏和城市相同的人员创建一个单独的组。

C#复制

```csharp
group person by new {name = person.surname, city = person.city};
```

如果必须将查询变量传递给其他方法，请使用命名类型。 使用键的自动实现的属性创建一个特殊类，然后替代 [Equals](https://docs.microsoft.com/zh-cn/dotnet/api/system.object.equals) 和 [GetHashCode](https://docs.microsoft.com/zh-cn/dotnet/api/system.object.gethashcode) 方法。 还可以使用结构，在此情况下，并不严格要求替代这些方法。 有关详细信息，请参阅[操作说明：使用自动实现的属性实现轻量类](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/how-to-implement-a-lightweight-class-with-auto-implemented-properties)和[操作说明：在目录树中查询重复文件](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-query-for-duplicate-files-in-a-directory-tree-linq)。 后文包含的代码示例演示了如何将复合键与命名类型结合使用。

### 示例

下面的示例演示在没有向组应用附加查询逻辑时，将源数据按顺序放入组中的标准模式。 这称为不带延续的分组。 字符串数组中的元素按照它们的首字母进行分组。 查询的结果是 [IGrouping](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.igrouping-2) 类型（包含一个 `char` 类型的公共 `Key` 属性）和一个 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 集合（在分组中包含每个项）。

`group` 子句的结果是由序列组成的序列。 因此，若要访问返回的每个组中的单个元素，请在循环访问组键的循环内使用嵌套的 `foreach` 循环，如以下示例所示。

C#复制

```csharp
class GroupExample1
{
    static void Main()
    {
        // Create a data source.
        string[] words = { "blueberry", "chimpanzee", "abacus", "banana", "apple", "cheese" };

        // Create the query.
        var wordGroups =
            from w in words
            group w by w[0];

        // Execute the query.
        foreach (var wordGroup in wordGroups)
        {
            Console.WriteLine("Words that start with the letter '{0}':", wordGroup.Key);
            foreach (var word in wordGroup)
            {
                Console.WriteLine(word);
            }
        }

        // Keep the console window open in debug mode
        Console.WriteLine("Press any key to exit.");
        Console.ReadKey();
    }        
}
/* Output:
      Words that start with the letter 'b':
        blueberry
        banana
      Words that start with the letter 'c':
        chimpanzee
        cheese
      Words that start with the letter 'a':
        abacus
        apple
     */
```

### 示例

此示例演示在创建组之后，如何使用通过 `into` 实现的延续对这些组执行附加逻辑。 有关详细信息，请参阅 [into](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/into)。 下面的示例查询每个组，仅选择键值为元音的元素。

C#复制

```csharp
class GroupClauseExample2
{
    static void Main()
    {
        // Create the data source.
        string[] words2 = { "blueberry", "chimpanzee", "abacus", "banana", "apple", "cheese", "elephant", "umbrella", "anteater" };

        // Create the query.
        var wordGroups2 =
            from w in words2
            group w by w[0] into grps
            where (grps.Key == 'a' || grps.Key == 'e' || grps.Key == 'i'
                   || grps.Key == 'o' || grps.Key == 'u')
            select grps;

        // Execute the query.
        foreach (var wordGroup in wordGroups2)
        {
            Console.WriteLine("Groups that start with a vowel: {0}", wordGroup.Key);
            foreach (var word in wordGroup)
            {
                Console.WriteLine("   {0}", word);
            }
        }

        // Keep the console window open in debug mode
        Console.WriteLine("Press any key to exit.");
        Console.ReadKey();
    }
}
/* Output:
    Groups that start with a vowel: a
        abacus
        apple
        anteater
    Groups that start with a vowel: e
        elephant
    Groups that start with a vowel: u
        umbrella
*/    
```

### 备注

在编译时，`group` 子句转换为对 [GroupBy](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.groupby) 方法的调用。

## [into](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/into)

可使用 `into` 上下文关键字创建临时标识符，将 [group](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/group-clause)、[join](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/join-clause) 或 [select](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/select-clause) 子句的结果存储至新标识符。 此标识符本身可以是附加查询命令的生成器。 有时称在 `group` 或 `select` 子句中使用新标识符为“延续”。

### 示例

下面的示例演示使用 `into` 关键字来启用具有推断类型 `IGrouping` 的临时标识符 `fruitGroup`。 通过使用该标识符，可对每个组调用 [Count](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.count) 方法，并且仅选择那些包含两个或更多个单词的组。

C#复制

```csharp
class IntoSample1
{
    static void Main()
    {
        
        // Create a data source.
        string[] words = { "apples", "blueberries", "oranges", "bananas", "apricots"};

        // Create the query.
        var wordGroups1 =
            from w in words
            group w by w[0] into fruitGroup
            where fruitGroup.Count() >= 2
            select new { FirstLetter = fruitGroup.Key, Words = fruitGroup.Count() };

        // Execute the query. Note that we only iterate over the groups, 
        // not the items in each group
        foreach (var item in wordGroups1)
        {
            Console.WriteLine(" {0} has {1} elements.", item.FirstLetter, item.Words);
        }

        // Keep the console window open in debug mode
        Console.WriteLine("Press any key to exit.");
        Console.ReadKey();
    }
}
/* Output:
   a has 2 elements.
   b has 2 elements.
*/
```

仅当希望对每个组执行附加查询操作时，才需在 `group` 子句中使用 `into`。 有关详细信息，请参阅 [group 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/group-clause)。

有关在 `join` 子句中使用 `into` 的示例，请参见 [join 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/join-clause)。

## [orderby clause](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/orderby-clause)

在查询表达式中，`orderby` 子句可导致返回的序列或子序列（组）以升序或降序排序。 若要执行一个或多个次级排序操作，可以指定多个键。 元素类型的默认比较器执行排序。 默认排序顺序为升序。 还可以指定自定义比较器。 但是，只适用于使用基于方法的语法。 有关详细信息，请参阅[对数据进行排序](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sorting-data)。

### 示例

在以下示例中，第一个查询按字母顺序从 A 开始对字词排序，而第二个查询则按降序对相同的字词排序。 （`ascending` 关键字是默认排序值，可省略。）

C#复制

```csharp
class OrderbySample1
{
    static void Main()
    {            
        // Create a delicious data source.
        string[] fruits = { "cherry", "apple", "blueberry" };

        // Query for ascending sort.
        IEnumerable<string> sortAscendingQuery =
            from fruit in fruits
            orderby fruit //"ascending" is default
            select fruit;

        // Query for descending sort.
        IEnumerable<string> sortDescendingQuery =
            from w in fruits
            orderby w descending
            select w;            

        // Execute the query.
        Console.WriteLine("Ascending:");
        foreach (string s in sortAscendingQuery)
        {
            Console.WriteLine(s);
        }

        // Execute the query.
        Console.WriteLine(Environment.NewLine + "Descending:");
        foreach (string s in sortDescendingQuery)
        {
            Console.WriteLine(s);
        }

        // Keep the console window open in debug mode.
        Console.WriteLine("Press any key to exit.");
        Console.ReadKey();
    }
}
/* Output:
Ascending:
apple
blueberry
cherry

Descending:
cherry
blueberry
apple
*/
```

### 示例

以下示例对学生的姓氏进行主要排序，然后对其名字进行次要排序。

C#复制

```csharp
class OrderbySample2
{
    // The element type of the data source.
    public class Student
    {
        public string First { get; set; }
        public string Last { get; set; }
        public int ID { get; set; }
    }

    public static List<Student> GetStudents()
    {
        // Use a collection initializer to create the data source. Note that each element
        //  in the list contains an inner sequence of scores.
        List<Student> students = new List<Student>
        {
           new Student {First="Svetlana", Last="Omelchenko", ID=111},
           new Student {First="Claire", Last="O'Donnell", ID=112},
           new Student {First="Sven", Last="Mortensen", ID=113},
           new Student {First="Cesar", Last="Garcia", ID=114},
           new Student {First="Debra", Last="Garcia", ID=115} 
        };

        return students;

    }
    static void Main(string[] args)
    {
        // Create the data source.
        List<Student> students = GetStudents();
        
        // Create the query.
        IEnumerable<Student> sortedStudents =
            from student in students
            orderby student.Last ascending, student.First ascending
            select student;

        // Execute the query.
        Console.WriteLine("sortedStudents:");
        foreach (Student student in sortedStudents)
            Console.WriteLine(student.Last + " " + student.First);           

        // Now create groups and sort the groups. The query first sorts the names
        // of all students so that they will be in alphabetical order after they are
        // grouped. The second orderby sorts the group keys in alpha order.            
        var sortedGroups =
            from student in students
            orderby student.Last, student.First
            group student by student.Last[0] into newGroup
            orderby newGroup.Key
            select newGroup;

        // Execute the query.
        Console.WriteLine(Environment.NewLine + "sortedGroups:");
        foreach (var studentGroup in sortedGroups)
        {
            Console.WriteLine(studentGroup.Key);
            foreach (var student in studentGroup)
            {
                Console.WriteLine("   {0}, {1}", student.Last, student.First);
            }
        }

        // Keep the console window open in debug mode
        Console.WriteLine("Press any key to exit.");
        Console.ReadKey();
    }
}
/* Output:  
sortedStudents:
Garcia Cesar
Garcia Debra
Mortensen Sven
O'Donnell Claire
Omelchenko Svetlana

sortedGroups:
G
   Garcia, Cesar
   Garcia, Debra
M
   Mortensen, Sven
O
   O'Donnell, Claire
   Omelchenko, Svetlana
*/
```

### 备注

编译时，`orderby` 子句将转换为对 [OrderBy](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.orderby) 方法的调用。 `orderby` 子句中的多个关键值将转换为 [ThenBy](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.thenby) 方法调用。

## [join clause](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/join-clause)

`join` 子句可用于将来自不同源序列并且在对象模型中没有直接关系的元素相关联。 唯一的要求是每个源中的元素需要共享某个可以进行比较以判断是否相等的值。 例如，食品经销商可能拥有某种产品的供应商列表以及买主列表。 例如，可以使用 `join` 子句创建该产品同一指定地区供应商和买主的列表。

`join` 子句将 2 个源序列作为输入。 每个序列中的元素都必须是可以与其他序列中的相应属性进行比较的属性，或者包含一个这样的属性。 `join` 子句使用特殊 `equals` 关键字比较指定的键是否相等。 `join` 子句执行的所有联接都是同等联接。 `join` 子句的输出形式取决于执行的联接的具体类型。 以下是 3 种最常见的联接类型：

- 内部联接
- 分组联接
- 左外部联接

### 内部联接

以下示例演示了一个简单的内部同等联接。 此查询生成一个“产品名称/类别”对平面序列。 同一类别字符串将出现在多个元素中。 如果 `categories` 中的某个元素不具有匹配的 `products`，则该类别不会出现在结果中。

C#复制

```csharp
var innerJoinQuery =
    from category in categories
    join prod in products on category.ID equals prod.CategoryID
    select new { ProductName = prod.Name, Category = category.Name }; //produces flat sequence
```

有关详细信息，请参阅[执行内联](https://docs.microsoft.com/zh-cn/dotnet/csharp/linq/perform-inner-joins)。

### 分组联接

含有 `into` 表达式的 `join` 子句称为分组联接。

C#复制

```csharp
var innerGroupJoinQuery =
    from category in categories
    join prod in products on category.ID equals prod.CategoryID into prodGroup
    select new { CategoryName = category.Name, Products = prodGroup };
```

分组联接会生成分层的结果序列，该序列将左侧源序列中的元素与右侧源序列中的一个或多个匹配元素相关联。分组联接没有等效的关系术语；它本质上是一个对象数组序列。

如果在右侧源序列中找不到与左侧源中的元素相匹配的元素，则 `join` 子句会为该项生成一个空数组。 因此，分组联接基本上仍然是一种内部同等联接，区别在于分组联接将结果序列组织为多个组。

如果只选择分组联接的结果，则可访问各项，但无法识别结果所匹配的项。 因此，通常更为有用的做法是：选择分组联接的结果并将其放入一个也包含该项名的新类型中，如上例所示。

当然，还可以将分组联接的结果用作其他子查询的生成器：

C#复制

```csharp
var innerGroupJoinQuery2 =
    from category in categories
    join prod in products on category.ID equals prod.CategoryID into prodGroup
    from prod2 in prodGroup
    where prod2.UnitPrice > 2.50M
    select prod2;
```

有关详细信息，请参阅[执行分组联接](https://docs.microsoft.com/zh-cn/dotnet/csharp/linq/perform-grouped-joins)。

### 左外部联接

在左外部联接中，将返回左侧源序列中的所有元素，即使右侧序列中没有其匹配元素也是如此。 若要在 LINQ 中执行左外部联接，请结合使用 `DefaultIfEmpty` 方法与分组联接，指定要在某个左侧元素不具有匹配元素时生成的默认右侧元素。 可以使用 `null` 作为任何引用类型的默认值，也可以指定用户定义的默认类型。 以下示例演示了用户定义的默认类型：

C#复制

```csharp
var leftOuterJoinQuery =
    from category in categories
    join prod in products on category.ID equals prod.CategoryID into prodGroup
    from item in prodGroup.DefaultIfEmpty(new Product { Name = String.Empty, CategoryID = 0 })
    select new { CatName = category.Name, ProdName = item.Name };
```

有关详细信息，请参阅[执行左外部联接](https://docs.microsoft.com/zh-cn/dotnet/csharp/linq/perform-left-outer-joins)。

### 等于运算符

`join` 子句执行同等联接。 换言之，只能基于 2 个项之间的相等关系进行匹配。 不支持其他类型的比较，例如“大于”或“不等于”。 为了表明所有联接都是同等联接，`join` 子句使用 `equals` 关键字而不是 `==` 运算符。 `equals` 关键字只能在 `join` 子句中使用，并且其与 `==` 运算符之间存在一个重要差别。 对于 `equals`，左键使用外部源序列，而右键使用内部源序列。 外部源仅在 `equals` 的左侧位于范围内，而内部源序列仅在其右侧位于范围内。

### 非同等联接

通过使用多个 `from` 子句将新序列单独引入查询，可以执行非同等联接、交叉联接和其他自定义联接操作。 有关详细信息，请参阅[执行自定义联接操作](https://docs.microsoft.com/zh-cn/dotnet/csharp/linq/perform-custom-join-operations)。

### 对象集合联接与关系表

在LINQ 查询表达式中，联接操作是在对象集合上执行的。 不能使用与 2 个关系表完全相同的方式“联接”对象集合。 在 LINQ 中，仅当 2 个源序列没有通过任何关系相互联系时，才需要使用显式 `join` 子句。 使用 LINQ to SQL 时，外键表在对象模型中表示为主表的属性。 例如，在 Northwind 数据库中，Customer 表与 Orders 表之间具有外键关系。 将这两个表映射到对象模型时，Customer 类具有一个 Orders 属性，其中包含与该 Customer 相关联的 Orders 集合。 实际上，已经为你执行了联接。

若要详细了解如何在 LINQ to SQL 的上下文中跨相关表执行查询，请参阅[操作说明：映射数据库关系](https://docs.microsoft.com/zh-cn/dotnet/framework/data/adonet/sql/linq/how-to-map-database-relationships)。

### 组合键

可通过使用组合键测试多个值是否相等。 有关详细信息，请参阅[使用组合键进行联接](https://docs.microsoft.com/zh-cn/dotnet/csharp/linq/join-by-using-composite-keys)。 还可以在 `group` 子句中使用组合键。

### 示例

以下示例比较了使用相同的匹配键对相同数据源执行内部联接、分组联接和左外部联接的结果。 这些示例中添加了一些额外的代码，以便在控制台显示中阐明结果。

C#复制

```csharp
   class JoinDemonstration
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


       static void Main(string[] args)
       {
           JoinDemonstration app = new JoinDemonstration();

           app.InnerJoin();
           app.GroupJoin();
           app.GroupInnerJoin();
           app.GroupJoin3();
           app.LeftOuterJoin();
           app.LeftOuterJoin2();

           // Keep the console window open in debug mode.
           Console.WriteLine("Press any key to exit.");
           Console.ReadKey();
       }

       void InnerJoin()
       {
           // Create the query that selects 
           // a property from each element.
           var innerJoinQuery =
              from category in categories
              join prod in products on category.ID equals prod.CategoryID
              select new { Category = category.ID, Product = prod.Name };

           Console.WriteLine("InnerJoin:");
           // Execute the query. Access results 
           // with a simple foreach statement.
           foreach (var item in innerJoinQuery)
           {
               Console.WriteLine("{0,-10}{1}", item.Product, item.Category);
           }
           Console.WriteLine("InnerJoin: {0} items in 1 group.", innerJoinQuery.Count());
           Console.WriteLine(System.Environment.NewLine);

       }

       void GroupJoin()
       {
           // This is a demonstration query to show the output
           // of a "raw" group join. A more typical group join
           // is shown in the GroupInnerJoin method.
           var groupJoinQuery =
              from category in categories
              join prod in products on category.ID equals prod.CategoryID into prodGroup
              select prodGroup;

           // Store the count of total items (for demonstration only).
           int totalItems = 0;

           Console.WriteLine("Simple GroupJoin:");

           // A nested foreach statement is required to access group items.
           foreach (var prodGrouping in groupJoinQuery)
           {
               Console.WriteLine("Group:");
               foreach (var item in prodGrouping)
               {
                   totalItems++;
                   Console.WriteLine("   {0,-10}{1}", item.Name, item.CategoryID);
               }
           }
           Console.WriteLine("Unshaped GroupJoin: {0} items in {1} unnamed groups", totalItems, groupJoinQuery.Count());
           Console.WriteLine(System.Environment.NewLine);
       }

       void GroupInnerJoin()
       {
           var groupJoinQuery2 =
               from category in categories
               orderby category.ID
               join prod in products on category.ID equals prod.CategoryID into prodGroup
               select new
               {
                   Category = category.Name,
                   Products = from prod2 in prodGroup
                              orderby prod2.Name
                              select prod2
               };

           //Console.WriteLine("GroupInnerJoin:");
           int totalItems = 0;

           Console.WriteLine("GroupInnerJoin:");
           foreach (var productGroup in groupJoinQuery2)
           {
               Console.WriteLine(productGroup.Category);
               foreach (var prodItem in productGroup.Products)
               {
                   totalItems++;
                   Console.WriteLine("  {0,-10} {1}", prodItem.Name, prodItem.CategoryID);
               }
           }
           Console.WriteLine("GroupInnerJoin: {0} items in {1} named groups", totalItems, groupJoinQuery2.Count());
           Console.WriteLine(System.Environment.NewLine);
       }

       void GroupJoin3()
       {

           var groupJoinQuery3 =
               from category in categories
               join product in products on category.ID equals product.CategoryID into prodGroup
               from prod in prodGroup
               orderby prod.CategoryID
               select new { Category = prod.CategoryID, ProductName = prod.Name };

           //Console.WriteLine("GroupInnerJoin:");
           int totalItems = 0;

           Console.WriteLine("GroupJoin3:");
           foreach (var item in groupJoinQuery3)
           {
               totalItems++;
               Console.WriteLine("   {0}:{1}", item.ProductName, item.Category);
           }

           Console.WriteLine("GroupJoin3: {0} items in 1 group", totalItems, groupJoinQuery3.Count());
           Console.WriteLine(System.Environment.NewLine);
       }

       void LeftOuterJoin()
       {
           // Create the query.
           var leftOuterQuery =
              from category in categories
              join prod in products on category.ID equals prod.CategoryID into prodGroup
              select prodGroup.DefaultIfEmpty(new Product() { Name = "Nothing!", CategoryID = category.ID });

           // Store the count of total items (for demonstration only).
           int totalItems = 0;

           Console.WriteLine("Left Outer Join:");

           // A nested foreach statement  is required to access group items
           foreach (var prodGrouping in leftOuterQuery)
           {
               Console.WriteLine("Group:", prodGrouping.Count());
               foreach (var item in prodGrouping)
               {
                   totalItems++;
                   Console.WriteLine("  {0,-10}{1}", item.Name, item.CategoryID);
               }
           }
           Console.WriteLine("LeftOuterJoin: {0} items in {1} groups", totalItems, leftOuterQuery.Count());
           Console.WriteLine(System.Environment.NewLine);
       }

       void LeftOuterJoin2()
       {
           // Create the query.
           var leftOuterQuery2 =
              from category in categories
              join prod in products on category.ID equals prod.CategoryID into prodGroup
              from item in prodGroup.DefaultIfEmpty()
              select new { Name = item == null ? "Nothing!" : item.Name, CategoryID = category.ID };

           Console.WriteLine("LeftOuterJoin2: {0} items in 1 group", leftOuterQuery2.Count());
           // Store the count of total items
           int totalItems = 0;

           Console.WriteLine("Left Outer Join 2:");

           // Groups have been flattened.
           foreach (var item in leftOuterQuery2)
           {
               totalItems++;
               Console.WriteLine("{0,-10}{1}", item.Name, item.CategoryID);
           }
           Console.WriteLine("LeftOuterJoin2: {0} items in 1 group", totalItems);
       }
   }
   /*Output:

   InnerJoin:
   Cola      1
   Tea       1
   Mustard   2
   Pickles   2
   Carrots   3
   Bok Choy  3
   Peaches   5
   Melons    5
   InnerJoin: 8 items in 1 group.


   Unshaped GroupJoin:
   Group:
       Cola      1
       Tea       1
   Group:
       Mustard   2
       Pickles   2
   Group:
       Carrots   3
       Bok Choy  3
   Group:
   Group:
       Peaches   5
       Melons    5
   Unshaped GroupJoin: 8 items in 5 unnamed groups


   GroupInnerJoin:
   Beverages
       Cola       1
       Tea        1
   Condiments
       Mustard    2
       Pickles    2
   Vegetables
       Bok Choy   3
       Carrots    3
   Grains
   Fruit
       Melons     5
       Peaches    5
   GroupInnerJoin: 8 items in 5 named groups


   GroupJoin3:
       Cola:1
       Tea:1
       Mustard:2
       Pickles:2
       Carrots:3
       Bok Choy:3
       Peaches:5
       Melons:5
   GroupJoin3: 8 items in 1 group


   Left Outer Join:
   Group:
       Cola      1
       Tea       1
   Group:
       Mustard   2
       Pickles   2
   Group:
       Carrots   3
       Bok Choy  3
   Group:
       Nothing!  4
   Group:
       Peaches   5
       Melons    5
   LeftOuterJoin: 9 items in 5 groups


   LeftOuterJoin2: 9 items in 1 group
   Left Outer Join 2:
   Cola      1
   Tea       1
   Mustard   2
   Pickles   2
   Carrots   3
   Bok Choy  3
   Nothing!  4
   Peaches   5
   Melons    5
   LeftOuterJoin2: 9 items in 1 group
   Press any key to exit.
   */
```

### 备注

后面未跟 `into` 的 `join` 子句转换为 [Join](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.join) 方法调用。 后面跟 `into` 的 `join` 子句转换为 [GroupJoin](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.groupjoin) 方法调用。

## [let clause](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/let-clause)

在查询表达式中，存储子表达式的结果有时很有帮助，可在后续子句中使用。 可以通过 `let` 关键字执行此操作，该关键字创建一个新的范围变量并通过提供的表达式结果初始化该变量。 使用值进行初始化后，范围变量不能用于存储另一个值。 但是，如果范围变量持有可查询类型，则可以查询该变量。

### 示例

以两种方式使用以下示例 `let`：

1. 创建一个可以查询其自身的可枚举类型。
2. 使查询仅调用一次范围变量 `word` 上的 `ToLower`。 如果不使用 `let`，则不得不调用 `where` 子句中的每个谓词的 `ToLower`。

```csharp
class LetSample1
{
    static void Main()
    {
        string[] strings = 
        {
            "A penny saved is a penny earned.",
            "The early bird catches the worm.",
            "The pen is mightier than the sword." 
        };

        // Split the sentence into an array of words
        // and select those whose first letter is a vowel.
        var earlyBirdQuery =
            from sentence in strings
            let words = sentence.Split(' ')
            from word in words
            let w = word.ToLower()
            where w[0] == 'a' || w[0] == 'e'
                || w[0] == 'i' || w[0] == 'o'
                || w[0] == 'u'
            select word;

        // Execute the query.
        foreach (var v in earlyBirdQuery)
        {
            Console.WriteLine("\"{0}\" starts with a vowel", v);
        }

        // Keep the console window open in debug mode.
        Console.WriteLine("Press any key to exit.");
        Console.ReadKey();
    }
}
/* Output:
    "A" starts with a vowel
    "is" starts with a vowel
    "a" starts with a vowel
    "earned." starts with a vowel
    "early" starts with a vowel
    "is" starts with a vowel
*/
```

## [ascending](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/ascending)

查询表达式中的 [orderby 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/orderby-clause) 中使用 `ascending` 上下文关键字指定排序顺序为从小到大。 由于 `ascending` 为默认排序顺序，因此无需加以指定。

### 示例

下面的示例说明 `ascending` 在 [orderby 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/orderby-clause)中的用法。

```csharp
IEnumerable<string> sortAscendingQuery =
    from vegetable in vegetables
    orderby vegetable ascending
    select vegetable;
```

## [descending](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/descending)

查询表达式中的 [orderby 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/orderby-clause)中使用 `descending` 上下文关键字指定排序顺序为从大到小。

下面的示例说明 `descending` 在 [orderby 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/orderby-clause)中的用法。

```csharp
IEnumerable<string> sortDescendingQuery =
    from vegetable in vegetables
    orderby vegetable descending
    select vegetable;
```

## [on](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/on)

`on` 上下文关键字用于在查询表达式的[ join 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/join-clause)中指定联接条件。

下面的示例说明了 `on` 在 `join` 子句中的用法

```csharp
var innerJoinQuery =
    from category in categories
    join prod in products on category.ID equals prod.CategoryID
    select new { ProductName = prod.Name, Category = category.Name };
```

## [equals](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/equals)

`equals` 上下文关键字用于在查询表达式的 `join` 子句中比较两个序列的元素。 有关详细信息，请参阅 [join 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/join-clause)。

下面的示例说明 `equals` 关键字在 `join` 子句中的用法。

```csharp
var innerJoinQuery =
    from category in categories
    join prod in products on category.ID equals prod.CategoryID
    select new { ProductName = prod.Name, Category = category.Name };
```

## [by](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/by)

`by` 上下文关键字用于在查询表达式的 `group` 子句中指定应返回项的分组方式。 有关详细信息，请参阅 [group 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/group-clause)。

下面的示例演示在 `group` 字句中使用 `by` 关键字指定应根据每个学生的姓氏首字母对学生分组。

```csharp
var query = from student in students
            group student by student.LastName[0];
```

## [in](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/in)

在四种上下文中使用 `in` 关键字：

- 泛型接口和委托中的[泛型类型参数](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/in-generic-modifier)。
- 作为[参数修饰符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/in-parameter-modifier)，它允许按引用而不是按值向方法传递参数。
- [foreach](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/foreach-in) 语句。
- LINQ 查询表达式中的 [from 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/from-clause)。
- LINQ 查询表达式中的 [join 子句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/join-clause)。