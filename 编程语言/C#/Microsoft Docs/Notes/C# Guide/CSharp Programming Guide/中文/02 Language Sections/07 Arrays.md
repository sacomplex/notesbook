[C# programming guide](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/index)

# Language Sections

## [Arrays](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/arrays/index)

可以将同一类型的多个变量存储在一个数组数据结构中。 通过指定数组的元素类型来声明数组。

```
type[] arrayName;
```

下面的示例创建一维数组、多维数组和交错数组：

```csharp
class TestArraysClass
{
    static void Main()
    {
        // Declare a single-dimensional array 
        int[] array1 = new int[5];

        // Declare and set array element values
        int[] array2 = new int[] { 1, 3, 5, 7, 9 };

        // Alternative syntax
        int[] array3 = { 1, 2, 3, 4, 5, 6 };

        // Declare a two dimensional array
        int[,] multiDimensionalArray1 = new int[2, 3];

        // Declare and set array element values
        int[,] multiDimensionalArray2 = { { 1, 2, 3 }, { 4, 5, 6 } };

        // Declare a jagged array
        int[][] jaggedArray = new int[6][];

        // Set the values of the first array in the jagged array structure
        jaggedArray[0] = new int[4] { 1, 2, 3, 4 };
    }
}
```

### 数组概述

数组具有以下属性：

- 数组可以是[一维](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/arrays/single-dimensional-arrays)、[多维](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/arrays/multidimensional-arrays)或[交错](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/arrays/jagged-arrays)的。
- 创建数组实例时，将建立纬度数量和每个纬度的长度。 这些值在实例的生存期内无法更改。
- 数值数组元素的默认值设置为零，而引用元素设置为 null。
- 交错数组是数组的数组，因此其元素为引用类型且被初始化为 `null`。
- 数组从零开始编制索引：包含 `n` 元素的数组从 `0` 索引到 `n-1`。
- 数组元素可以是任何类型，其中包括数组类型。
- 数组类型是从抽象的基类型 [Array](https://docs.microsoft.com/zh-cn/dotnet/api/system.array) 派生的[引用类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/reference-types)。 由于此类型实现 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable) 和 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1)，因此可以在 C# 中的所有数组上使用 [foreach](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/foreach-in) 迭代。

### [Arrays as Objects](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/arrays/arrays-as-objects)

在 C# 中，数组实际上是对象，而不只是如在 C 和 C++ 中的连续内存的可寻址区域。 [Array](https://docs.microsoft.com/zh-cn/dotnet/api/system.array) 是所有数组类型的抽象基类型。 可以使用 [Array](https://docs.microsoft.com/zh-cn/dotnet/api/system.array) 具有的属性和其他类成员。 例如，使用 [Length](https://docs.microsoft.com/zh-cn/dotnet/api/system.array.length) 属性来获取数组的长度。 以下代码可将 `numbers` 数组的长度 `5` 分配给名为 `lengthOfNumbers` 的变量：

```csharp
int[] numbers = { 1, 2, 3, 4, 5 };
int lengthOfNumbers = numbers.Length;
```

[Array](https://docs.microsoft.com/zh-cn/dotnet/api/system.array) 类可提供多种其他有用的方法和属性，用于对数组进行排序、搜索和复制。

#### 示例

此示例使用 [Rank](https://docs.microsoft.com/zh-cn/dotnet/api/system.array.rank) 属性显示数组的维数。

```csharp
class TestArraysClass
{
    static void Main()
    {
        // Declare and initialize an array:
        int[,] theArray = new int[5, 10];
        System.Console.WriteLine("The array has {0} dimensions.", theArray.Rank);
    }
}
// Output: The array has 2 dimensions.
```

### [Single-Dimensional Arrays](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/arrays/single-dimensional-arrays)

可以声明五个整数的一维数组，如以下示例所示：

```csharp
int[] array = new int[5];
```

此数组包含从 `array[0]` 到 `array[4]` 的元素。 [new](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/new) 运算符用于创建数组并将数组元素初始化为其默认值。 在此示例中，所有数组元素都将被初始化为零。

可使用相同方式声明存储字符串元素的数组。 例如:

```csharp
string[] stringArray = new string[6];
```

#### 数组初始化

可以在声明时初始化数组，在这种情况下，无需长度说明符，因为它已由初始化列表中的元素数目提供。 例如:

```csharp
int[] array1 = new int[] { 1, 3, 5, 7, 9 };
```

可使用相同方式初始化字符串数组。 下面是一个字符串数组的声明，其中每个数组元素都由一天的名称初始化：

```csharp
string[] weekDays = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
```

如果在声明时初始化数组，可以使用以下快捷方式：

```csharp
int[] array2 = { 1, 3, 5, 7, 9 };
string[] weekDays2 = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
```

可以在不初始化的情况下声明数组变量，但必须使用 `new` 运算符向此变量分配数组。 例如:

```csharp
int[] array3;
array3 = new int[] { 1, 3, 5, 7, 9 };   // OK
//array3 = {1, 3, 5, 7, 9};   // Error
```

C# 3.0 引入了隐式类型化数组。 有关详细信息，请参阅[隐式类型化数组](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/arrays/implicitly-typed-arrays)。

#### 值类型和引用类型数组

请考虑以下数组声明：

```csharp
SomeType[] array4 = new SomeType[10];
```

此语句的结果取决于 `SomeType` 是值类型还是引用类型。 如果它是值类型，该语句将创建一个 10 个元素的数组，其中每个元素的类型都为 `SomeType`。 如果 `SomeType` 是引用类型，该语句将创建一个 10 个元素的数组，其中每个元素都将被初始化为空引用。

有关值类型和引用类型的详细信息，请参阅[类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/types)。

### [Multidimensional Arrays](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/arrays/multidimensional-arrays)

数组可具有多个维度。 例如，以下声明创建一个具有四行两列的二维数组。

```csharp
int[,] array = new int[4, 2];
```

以下声明创建一个具有三个维度（4、2 和 3）的数组。

```csharp
int[, ,] array1 = new int[4, 2, 3];
```

#### 数组初始化

声明后即可初始化数组，如以下示例所示。

```csharp
// Two-dimensional array.
int[,] array2D = new int[,] { { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } };
// The same array with dimensions specified.
int[,] array2Da = new int[4, 2] { { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } };
// A similar array with string elements.
string[,] array2Db = new string[3, 2] { { "one", "two" }, { "three", "four" },
                                        { "five", "six" } };

// Three-dimensional array.
int[, ,] array3D = new int[,,] { { { 1, 2, 3 }, { 4, 5, 6 } }, 
                                 { { 7, 8, 9 }, { 10, 11, 12 } } };
// The same array with dimensions specified.
int[, ,] array3Da = new int[2, 2, 3] { { { 1, 2, 3 }, { 4, 5, 6 } }, 
                                       { { 7, 8, 9 }, { 10, 11, 12 } } };

// Accessing array elements.
System.Console.WriteLine(array2D[0, 0]);
System.Console.WriteLine(array2D[0, 1]);
System.Console.WriteLine(array2D[1, 0]);
System.Console.WriteLine(array2D[1, 1]);
System.Console.WriteLine(array2D[3, 0]);
System.Console.WriteLine(array2Db[1, 0]);
System.Console.WriteLine(array3Da[1, 0, 1]);
System.Console.WriteLine(array3D[1, 1, 2]);

// Getting the total count of elements or the length of a given dimension.
var allLength = array3D.Length;
var total = 1;
for (int i = 0; i < array3D.Rank; i++) {
    total *= array3D.GetLength(i);
}
System.Console.WriteLine("{0} equals {1}", allLength, total);

// Output:
// 1
// 2
// 3
// 4
// 7
// three
// 8
// 12
// 12 equals 12
```

还可在不指定秩的情况下初始化数组。

```csharp
int[,] array4 = { { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } };
```

如果选择在不初始化的情况下声明数组变量，则必须使用 `new` 运算符将数组赋予变量。 `new` 的用法如以下示例所示。

```csharp
int[,] array5;
array5 = new int[,] { { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } };   // OK
//array5 = {{1,2}, {3,4}, {5,6}, {7,8}};   // Error
```

以下示例将值赋予特定的数组元素。

```csharp
array5[2, 1] = 25;
```

同样，以下示例将获取特定数组元素的值并将其赋予变量 `elementValue`。

```csharp
int elementValue = array5[2, 1];
```

以下代码示例将数组元素初始化为默认值（交错数组除外）。

```csharp
int[,] array6 = new int[10, 10];
```

### [Jagged Arrays](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/arrays/jagged-arrays)

交错数组是元素为数组的数组。 交错数组元素的维度和大小可以不同。 交错数组有时称为“数组的数组”。 以下示例说明如何声明、初始化和访问交错数组。

下面声明一个具有三个元素的一维数组，其中每个元素都是一维整数数组：

```csharp
int[][] jaggedArray = new int[3][];
```

必须初始化 `jaggedArray` 的元素后才可使用它。 可按下方操作初始化元素：

```csharp
jaggedArray[0] = new int[5];
jaggedArray[1] = new int[4];
jaggedArray[2] = new int[2];
```

每个元素都是一维整数数组。 第一个元素是由 5 个整数组成的数组，第二个是由 4 个整数组成的数组，而第三个是由 2 个整数组成的数组。

也可使用初始化表达式通过值来填充数组元素，这种情况下不需要数组大小。 例如:

```csharp
jaggedArray[0] = new int[] { 1, 3, 5, 7, 9 };
jaggedArray[1] = new int[] { 0, 2, 4, 6 };
jaggedArray[2] = new int[] { 11, 22 };
```

还可在声明数组时将其初始化，如：

```csharp
int[][] jaggedArray2 = new int[][] 
{
    new int[] { 1, 3, 5, 7, 9 },
    new int[] { 0, 2, 4, 6 },
    new int[] { 11, 22 }
};
```

可以使用下面的缩写形式。 请注意：不能从元素初始化中省略 `new` 运算符，因为不存在元素的默认初始化：

```csharp
int[][] jaggedArray3 = 
{
    new int[] { 1, 3, 5, 7, 9 },
    new int[] { 0, 2, 4, 6 },
    new int[] { 11, 22 }
};
```

交错数组是数组的数组，因此其元素为引用类型且被初始化为 `null`。

可以如下例所示访问个别数组元素：

```csharp
// Assign 77 to the second element ([1]) of the first array ([0]):
jaggedArray3[0][1] = 77;

// Assign 88 to the second element ([1]) of the third array ([2]):
jaggedArray3[2][1] = 88;
```

可以混合使用交错数组和多维数组。 下面声明和初始化一个包含大小不同的三个二维数组元素的一维交错数组。有关二维数组的详细信息，请参阅[多维数组](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/arrays/multidimensional-arrays)。

```csharp
int[][,] jaggedArray4 = new int[3][,] 
{
    new int[,] { {1,3}, {5,7} },
    new int[,] { {0,2}, {4,6}, {8,10} },
    new int[,] { {11,22}, {99,88}, {0,9} } 
};
```

可以如本例所示访问个别元素，示例显示第一个数组的元素 `[1,0]` 的值（值为 `5`）：

```csharp
System.Console.Write("{0}", jaggedArray4[0][1, 0]);
```

方法 `Length` 返回包含在交错数组中的数组的数目。 例如，假定已声明了前一个数组，则此行：

```csharp
System.Console.WriteLine(jaggedArray4.Length);
```

返回值 3。

#### 示例

本例生成一个数组，该数组的元素为数组自身。 每一个数组元素都有不同的大小。

```csharp
class ArrayTest
{
    static void Main()
    {
        // Declare the array of two elements:
        int[][] arr = new int[2][];

        // Initialize the elements:
        arr[0] = new int[5] { 1, 3, 5, 7, 9 };
        arr[1] = new int[4] { 2, 4, 6, 8 };

        // Display the array elements:
        for (int i = 0; i < arr.Length; i++)
        {
            System.Console.Write("Element({0}): ", i);

            for (int j = 0; j < arr[i].Length; j++)
            {
                System.Console.Write("{0}{1}", arr[i][j], j == (arr[i].Length - 1) ? "" : " ");
            }
            System.Console.WriteLine();            
        }
        // Keep the console window open in debug mode.
        System.Console.WriteLine("Press any key to exit.");
        System.Console.ReadKey();
    }
}
/* Output:
    Element(0): 1 3 5 7 9
    Element(1): 2 4 6 8
*/
```

### [Using foreach with Arrays](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/arrays/using-foreach-with-arrays)

[foreach](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/foreach-in) 语句提供一种简单、明了的方法来循环访问数组的元素。

对于单维数组，`foreach` 语句以递增索引顺序处理元素（从索引 0 开始并以索引 `Length - 1` 结束）：

```csharp
int[] numbers = { 4, 5, 6, 1, 2, 3, -2, -1, 0 };
foreach (int i in numbers)
{
    System.Console.Write("{0} ", i);
}
// Output: 4 5 6 1 2 3 -2 -1 0
```

对于多维数组，遍历元素的方式为：首先增加最右边维度的索引，然后是它左边的一个维度，以此类推，向左遍历元素：

```csharp
int[,] numbers2D = new int[3, 2] { { 9, 99 }, { 3, 33 }, { 5, 55 } };
// Or use the short form:
// int[,] numbers2D = { { 9, 99 }, { 3, 33 }, { 5, 55 } };

foreach (int i in numbers2D)
{
    System.Console.Write("{0} ", i);
}
// Output: 9 99 3 33 5 55
```

但对于多维数组，使用嵌套的 [for](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/for) 循环可以更好地控制处理数组元素的顺序。

### [Passing Arrays as Arguments](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/arrays/passing-arrays-as-arguments)

数组可以作为实参传递给方法形参。 由于数组是引用类型，因此方法可以更改元素的值。

#### 将一维数组作为参数传递

可将初始化的一维数组传递给方法。 例如，下列语句将一个数组发送给了 Print 方法。

```csharp
int[] theArray = { 1, 3, 5, 7, 9 };
PrintArray(theArray);
```

下面的代码演示 Print 方法的部分实现。

```csharp
void PrintArray(int[] arr)
{
    // Method code.
}
```

可在同一步骤中初始化并传递新数组，如下例所示。

```csharp
PrintArray(new int[] { 1, 3, 5, 7, 9 });
```

#### 示例

在下面的示例中，先初始化一个字符串数组，然后将其作为参数传递给字符串的 `DisplayArray` 方法。 该方法将显示数组的元素。 接下来，`ChangeArray` 方法会反转数组元素，然后由 `ChangeArrayElements` 方法修改该数组的前三个元素。 每个方法返回后，`DisplayArray` 方法会显示按值传递数组不会阻止对数组元素的更改。

```csharp
using System;

class ArrayExample
{
    static void DisplayArray(string[] arr) => Console.WriteLine(string.Join(" ", arr));

    // Change the array by reversing its elements.
    static void ChangeArray(string[] arr) => Array.Reverse(arr);

    static void ChangeArrayElements(string[] arr)
    {
        // Change the value of the first three array elements. 
        arr[0] = "Mon";
        arr[1] = "Wed";
        arr[2] = "Fri";
    }

    static void Main()
    {
        // Declare and initialize an array.
        string[] weekDays = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
        // Display the array elements.
        DisplayArray(weekDays);
        Console.WriteLine();

        // Reverse the array.
        ChangeArray(weekDays);
        // Display the array again to verify that it stays reversed.
        Console.WriteLine("Array weekDays after the call to ChangeArray:");
        DisplayArray(weekDays);
        Console.WriteLine();

        // Assign new values to individual array elements.
        ChangeArrayElements(weekDays);
        // Display the array again to verify that it has changed.
        Console.WriteLine("Array weekDays after the call to ChangeArrayElements:");
        DisplayArray(weekDays);
    }
}
// The example displays the following output: 
//         Sun Mon Tue Wed Thu Fri Sat
//
//        Array weekDays after the call to ChangeArray:
//        Sat Fri Thu Wed Tue Mon Sun
//
//        Array weekDays after the call to ChangeArrayElements:
//        Mon Wed Fri Wed Tue Mon Sun
```

#### 将多维数组作为参数传递

通过与传递一维数组相同的方式，向方法传递初始化的多维数组。

```csharp
int[,] theArray = { { 1, 2 }, { 2, 3 }, { 3, 4 } };
Print2DArray(theArray);
```

下列代码演示了 Print 方法的部分声明（该方法接受将二维数组作为其参数）。

```csharp
void Print2DArray(int[,] arr)
{
    // Method code.
}
```

可在一个步骤中初始化并传递新数组，如下例所示：

```csharp
Print2DArray(new int[,] { { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } });
```

#### 示例

在下列示例中，初始化一个整数的二维数组，并将其传递至 `Print2DArray` 方法。 该方法将显示数组的元素。

```csharp
class ArrayClass2D
{
    static void Print2DArray(int[,] arr)
    {
        // Display the array elements.
        for (int i = 0; i < arr.GetLength(0); i++)
        {
            for (int j = 0; j < arr.GetLength(1); j++)
            {
                System.Console.WriteLine("Element({0},{1})={2}", i, j, arr[i, j]);
            }
        }
    }
    static void Main()
    {
        // Pass the array as an argument.
        Print2DArray(new int[,] { { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } });

        // Keep the console window open in debug mode.
        System.Console.WriteLine("Press any key to exit.");
        System.Console.ReadKey();
    }
}
    /* Output:
        Element(0,0)=1
        Element(0,1)=2
        Element(1,0)=3
        Element(1,1)=4
        Element(2,0)=5
        Element(2,1)=6
        Element(3,0)=7
        Element(3,1)=8
    */
```

### [使用 ref 和 out 传递数组](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/arrays/passing-arrays-using-ref-and-out)

> 原文已删除

### [Implicitly Typed Arrays](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/arrays/implicitly-typed-arrays)

可以创建隐式类型化的数组，其中数组实例的类型通过数组初始值设定项中指定的元素来推断。 针对隐式类型化变量的任何规则也适用于隐式类型化数组。 有关详细信息，请参阅[隐式类型局部变量](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/implicitly-typed-local-variables)。

隐式类型化数组通常用于查询表达式、匿名类型、对象和集合初始值设定项。

下列示例演示如何创建隐式类型化数组：

```csharp
class ImplicitlyTypedArraySample
{
    static void Main()
    {
        var a = new[] { 1, 10, 100, 1000 }; // int[]
        var b = new[] { "hello", null, "world" }; // string[]

        // single-dimension jagged array
        var c = new[]   
        {  
            new[]{1,2,3,4},
            new[]{5,6,7,8}
        };

        // jagged array of strings
        var d = new[]   
        {
            new[]{"Luca", "Mads", "Luke", "Dinesh"},
            new[]{"Karen", "Suma", "Frances"}
        };
    }
}
```

在上个示例中，请注意对于隐式类型化数组，初始化语句的左侧没有使用方括号。 另请注意，和一维数组一样，通过使用 `new []` 来初始化交错数组。

#### 对象初始值设定项中隐式类型化数组

创建包含数组的匿名类型时，必须在类型的对象初始值设定项中隐式类型化数组。 在下列示例中，`contacts` 是匿名类型的隐式类型化数组，每个类型都包含名为 `PhoneNumbers` 的数组。 请注意，不可在对象初始值设定项中使用 `var` 关键字。

```csharp
var contacts = new[]
{
    new {
        Name = " Eugene Zabokritski",
        PhoneNumbers = new[] { "206-555-0108", "425-555-0001" }
    },
    new {
        Name = " Hanying Feng",
        PhoneNumbers = new[] { "650-555-0199" }
    }
};
```