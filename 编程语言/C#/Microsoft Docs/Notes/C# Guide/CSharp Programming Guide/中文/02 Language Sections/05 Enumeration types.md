[C# programming guide](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/index)

# Language Sections

## [Enumeration Types](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/enumeration-types)

枚举类型（也称为枚举）提供了一种有效的方式来定义可能分配给变量的一组已命名整数常量。 例如，假设你需要定义一个变量，其值表示一周内的某一天。 该变量只会存储七个有意义的值。 若要定义这些值，可以使用枚举类型，该类型是使用 [enum](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/enum) 关键字声明的。

```csharp
enum Day { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
enum Month : byte { Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec }; 
```

默认情况下，枚举中每个元素的基础类型都为 [int](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/int)。可以使用冒号指定另一种整数类型，如上例所示。 有关可能的类型的完整列表，请参阅 [enum（C# 参考）](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/enum)。

可以通过转换为基础类型来验证基础数值，如下例所示。

```csharp
Day today = Day.Monday;
int dayNumber =(int)today;
Console.WriteLine("{0} is day number #{1}.", today, dayNumber);

Month thisMonth = Month.Dec;
byte monthNumber = (byte)thisMonth;
Console.WriteLine("{0} is month number #{1}.", thisMonth, monthNumber);

// Output:
// Monday is day number #1.
// Dec is month number #11.
```

以下是使用枚举而不使用数值类型的好处：

- 明确为客户端代码指定对变量有效的值。
- 在 Visual Studio 中，IntelliSense 列出了定义的值。

如果未为枚举器列表中的元素指定值，则值将自动按 1 递增。 在上例中，`Day.Sunday` 的值为 0，`Day.Monday` 的值为 1，依此类推。 创建新的 `Day` 对象时，如果没有明确为其分配值，它将具有默认值 `Day.Sunday` (0)。 创建枚举时，请选择最有逻辑的默认值，并为其分配值零。 这将导致所有枚举都具有默认值（如果未在创建时显式分配值）。

如果变量 `meetingDay` 的类型为 `Day`，那么在没有显式转换的情况下只能为其分配由 `Day` 定义的值。 如果会议日期更改，可以将 `Day` 中的新值分配给 `meetingDay`：

```csharp
Day meetingDay = Day.Monday;
//...
meetingDay = Day.Friday;
```

> 可以将任意整数值分配给 `meetingDay`。 例如，代码行 `meetingDay = (Day) 42` 不会产生错误。 但应避免这样做，因为隐式预期是枚举变量只会持有枚举所定义的其中一个值。 为枚举类型的变量分配任意值很可能会引发错误。

可以为枚举类型的枚举器列表中的元素分配任何值，也可以使用计算值：

```csharp
enum MachineState
{
    PowerOff = 0,
    Running = 5,
    Sleeping = 10,
    Hibernating = Sleeping + 5
}
```

### 作为位标志的枚举类型

可以使用枚举类型来定义位标志，这使枚举类型的实例能够存储枚举器列表中定义的值的任何组合。 （当然，某些组合在你的程序代码中可能没有意义或不允许使用。）

创建位标志枚举的方法是，应用 [System.FlagsAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.flagsattribute) 属性并适当定义一些值，以便可以对这些值执行 `AND`、`OR`、`NOT` 和 `XOR` 按位运算。 在位标志枚举中，包括一个值为零（表示“未设置任何标志”）的命名常量。 如果零值不表示“未设置任何标志”，请勿为标志指定零值。

在以下示例中，定义了名为 `Days` 枚举的另一个版本，命名为 `Day`。 `Days` 具有 `Flags` 属性，且它的每个值都是 2 的若干次幂，指数依次递增。 这样，你就能够创建值为 `Days.Tuesday | Days.Thursday` 的 `Days` 变量。

```csharp
[Flags]
enum Days
{
    None = 0x0,
    Sunday = 0x1,
    Monday = 0x2,
    Tuesday = 0x4,
    Wednesday = 0x8,
    Thursday = 0x10,
    Friday = 0x20,
    Saturday = 0x40
}
class MyClass
{
    Days meetingDays = Days.Tuesday | Days.Thursday;
}
```

若要在枚举上设置标志，请使用按位 `OR` 运算符，如以下示例所示：

```csharp
// Initialize with two flags using bitwise OR.
meetingDays = Days.Tuesday | Days.Thursday;

// Set an additional flag using bitwise OR.
meetingDays = meetingDays | Days.Friday;

Console.WriteLine("Meeting days are {0}", meetingDays);
// Output: Meeting days are Tuesday, Thursday, Friday

// Remove a flag using bitwise XOR.
meetingDays = meetingDays ^ Days.Tuesday;
Console.WriteLine("Meeting days are {0}", meetingDays);
// Output: Meeting days are Thursday, Friday
```

若要确定是否设置了特定标志，请使用按位 `AND` 运算，如以下示例所示：

```csharp
// Test value of flags using bitwise AND.
bool test = (meetingDays & Days.Thursday) == Days.Thursday;
Console.WriteLine("Thursday {0} a meeting day.", test == true ? "is" : "is not");
// Output: Thursday is a meeting day.
```

有关使用 [System.FlagsAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.flagsattribute) 特性定义枚举类型时应考虑事项的详细信息，请参阅 [System.Enum](https://docs.microsoft.com/zh-cn/dotnet/api/system.enum)。

### 使用 System.Enum 方法来发现和操作枚举值

所有枚举都是 [System.Enum](https://docs.microsoft.com/zh-cn/dotnet/api/system.enum) 类型的实例。 不能从 [System.Enum](https://docs.microsoft.com/zh-cn/dotnet/api/system.enum) 中派生新类，但可以使用它的方法来发现有关枚举实例中操作值的信息。

```csharp
string s = Enum.GetName(typeof(Day), 4);
Console.WriteLine(s);

Console.WriteLine("The values of the Day Enum are:");
foreach (int i in Enum.GetValues(typeof(Day)))
    Console.WriteLine(i);

Console.WriteLine("The names of the Day Enum are:");
foreach (string str in Enum.GetNames(typeof(Day)))
    Console.WriteLine(str);
```

有关更多信息，请参见[System.Enum](https://docs.microsoft.com/zh-cn/dotnet/api/system.enum)。

还可以使用扩展方法创建枚举的新方法。 有关详细信息，请参阅[如何：为枚举创建新方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/how-to-create-a-new-method-for-an-enumeration)。