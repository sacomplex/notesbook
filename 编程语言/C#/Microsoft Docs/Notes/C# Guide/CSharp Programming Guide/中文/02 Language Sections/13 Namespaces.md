[C# programming guide](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/index)

# Language Sections

## [Namespaces](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/namespaces/index)

在 C# 编程中，命名空间在两个方面被大量使用。 首先，.NET Framework 使用命名空间来组织许多类，如下所示：

```csharp
System.Console.WriteLine("Hello World!");
```

`System` 是一个命名空间，`Console` 是该命名空间中的一个类。 可以使用 `using` 关键字，如此则不必使用完整的名称，如下例所示：

```csharp
using System;
```

```csharp
Console.WriteLine("Hello");
Console.WriteLine("World!");
```

有关详细信息，请参阅 [using 指令](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/using-directive)。

其次，在较大的编程项目中，声明自己的命名空间可以帮助控制类和方法名称的范围。 使用 [namespace](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/namespace) 关键字可声明命名空间，如下例所示：

```csharp
namespace SampleNamespace
{
    class SampleClass
    {
        public void SampleMethod()
        {
            System.Console.WriteLine(
              "SampleMethod inside SampleNamespace");
        }
    }
}
```

命名空间的名称必须是有效的 C# [标识符名称](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/inside-a-program/identifier-names)。

### 命名空间概述

命名空间具有以下属性：

- 它们组织大型代码项目。
- 通过使用 `.` 运算符分隔它们。
- `using` 指令可免去为每个类指定命名空间的名称。
- `global` 命名空间是“根”命名空间：`global::System` 始终引用 .NET [System](https://docs.microsoft.com/zh-cn/dotnet/api/system) 命名空间。

### [Using Namespaces](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/namespaces/using-namespaces)

在 C# 编程中，命名空间在两个方面被大量使用。 首先，.NET Framework 类使用命名空间来组织它的众多类。 其次，在较大的编程项目中，声明自己的命名空间可以帮助控制类名称和方法名称的范围。

#### 访问命名空间

大多数 C# 应用程序以 `using` 指令开头。 本部分列出了应用程序将频繁使用的命名空间，使程序员避免在每次使用包含在命名空间中的方法时都要指定完全限定名称。

例如，通过包括行：

```csharp
using System;
```

在程序的开始，程序员可以使用代码：

```csharp
Console.WriteLine("Hello, World!");
```

而不是：

```csharp
System.Console.WriteLine("Hello, World!");
```

#### 命名空间别名

[Using 指令](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/using-directive)还可用于创建[命名空间](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/namespace)的别名。 例如，如果使用之前编写的含嵌套命名空间的命名空间，建议你声明一个别名，特别提供一种快速的引用方法，如以下示例所示：

```csharp
using Co = Company.Proj.Nested;  // define an alias to represent a namespace
```

#### 使用命名空间控制范围

`namespace` 关键字用于声明范围。 在项目内创建范围有助于整理代码，并允许创建全局唯一类型。 在下面的示例中，名为 `SampleClass` 的类在两个命名空间中定义，其中一个嵌套在另一个之中。 [运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/member-access-operator) 用于区分调用的方法。

```csharp
namespace SampleNamespace
{
    class SampleClass
    {
        public void SampleMethod()
        {
            System.Console.WriteLine(
              "SampleMethod inside SampleNamespace");
        }
    }

    // Create a nested namespace, and define another class.
    namespace NestedNamespace
    {
        class SampleClass
        {
            public void SampleMethod()
            {
                System.Console.WriteLine(
                  "SampleMethod inside NestedNamespace");
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            // Displays "SampleMethod inside SampleNamespace."
            SampleClass outer = new SampleClass();
            outer.SampleMethod();

            // Displays "SampleMethod inside SampleNamespace."
            SampleNamespace.SampleClass outer2 = new SampleNamespace.SampleClass();
            outer2.SampleMethod();

            // Displays "SampleMethod inside NestedNamespace."
            NestedNamespace.SampleClass inner = new NestedNamespace.SampleClass();
            inner.SampleMethod();
        }
    }
}
```

#### 完全限定名

命名空间和类型具有指示逻辑层次结构的完全限定名称所描述的唯一标题。 例如，语句 `A.B` 意味着 `A` 是命名空间或类型的名称，而 `B` 嵌套在其中。

以下示例中具有嵌套的类和命名空间。 完全限定名称表示为跟随每个实体的注释。

```csharp
namespace N1     // N1
{
    class C1      // N1.C1
    {
        class C2   // N1.C1.C2
        {
        }
    }
    namespace N2  // N1.N2
    {
        class C2   // N1.N2.C2
        {
        }
    }
}
```

在前面的代码片段中：

- 命名空间 `N1` 是全局命名空间的成员。 其完全限定名称为 `N1`。
- 命名空间 `N2` 是 `N1` 的成员。 其完全限定名称为 `N1.N2`。
- 类 `C1` 是 `N1` 的成员。 其完全限定名称为 `N1.C1`。
- 类名 `C2` 在此代码中使用了两次。 但完全限定名称是唯一的。 `C2` 的第一个实例在 `C1` 中声明；因此，其完全限定名称是：`N1.C1.C2`。 `C2` 的第二个实例在命名空间 `N2` 中声明；因此，其完全限定名称是 `N1.N2.C2`。

使用前面的代码段，可向命名空间 `N1.N2` 添加新的类成员 `C3`，如下所示：

```csharp
namespace N1.N2
{
    class C3   // N1.N2.C3
    {
    }
}
```

一般情况下，使用 `::` 来引用命名空间别名，或使用 `global::` 来引用全局命名空间，以及使用 `.` 来限定类型或成员。

将 `::` 与引用类型而非引用命名空间的别名一起使用是错误的。 例如:

```csharp
using Alias = System.Console;
```

```csharp
class TestClass
{
    static void Main()
    {
        // Error
        //Alias::WriteLine("Hi");

        // OK
        Alias.WriteLine("Hi");
    }
}
```

请记住，单词 `global` 不是预定义的别名；因此，`global.X` 不具有任何特殊含义。 仅当将其与 `::` 一起使用时，它才具有特殊意义。

定义名为 global 的别名时将生成编译器警告 CS0440，因为 `global::` 始终引用全局命名空间而非别名。 例如，以下行将生成该警告：

```csharp
using global = System.Collections;   // Warning
```

将 `::` 与别名一起使用是一个不错的主意，可防止意外引入其他类型。 例如，请考虑以下示例：

```csharp
using Alias = System;
```

```csharp
namespace Library
{
    public class C : Alias.Exception { }
}
```

这是可行的，但如果随后要引入名为 `Alias` 的类型，`Alias.` 将改为绑定到该类型。 使用 `Alias::Exception` 确保 `Alias` 被视为命名空间别名，而不被误解为类型。

请参阅主题[操作说明：使用全局命名空间别名](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/namespaces/how-to-use-the-global-namespace-alias)，以详细了解 `global` 别名。

### [How to: Use the Global Namespace Alias](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/namespaces/how-to-use-the-global-namespace-alias)

当具有同一名称的其他实体可能隐藏了成员时，访问全局[命名空间](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/namespace)中的成员的功能将十分有用。

例如，在下面的代码中，`Console` 解析为 `TestApp.Console` 而不是 [System](https://docs.microsoft.com/zh-cn/dotnet/api/system) 命名空间中的 `Console` 类型。

```csharp
using System;
```

```csharp
class TestApp
{
    // Define a new class called 'System' to cause problems.
    public class System { }

    // Define a constant called 'Console' to cause more problems.
    const int Console = 7;
    const int number = 66;

    static void Main()
    {
        // The following line causes an error. It accesses TestApp.Console,
        // which is a constant.
        //Console.WriteLine(number);
    }
}
```

使用 `System.Console` 仍会导致错误，因为类 `TestApp.System` 隐藏了 `System` 命名空间：

```csharp
// The following line causes an error. It accesses TestApp.System,
// which does not have a Console.WriteLine method.
System.Console.WriteLine(number);
```

但是，可以使用 `global::System.Console` 解决此错误，如下所示：

```csharp
// OK
global::System.Console.WriteLine(number);
```

如果左标识符为 `global`，则会在全局命名空间开始搜索右标识符。 例如，以下声明引用 `TestApp` 作为全局空间的成员。

```csharp
class TestClass : global::TestApp
```

显然，不建议将自己的命名空间的名称创建为 `System`，并且不可能会遇到发生此情况的代码。 但是，在大型项目中，很有可能会以一种或另一种形式发生命名空间重复。 在这些情况下，全局命名空间限定符可保证指定根命名空间。

#### 示例

在此示例中，命名空间 `System` 用于包括类 `TestClass`，因此， `global::System.Console` 必须用于引用 `System.Console` 类，该类由 `System` 命名空间隐藏。 此外，别名 `colAlias` 用于引用命名空间 `System.Collections`；因此，[System.Collections.Hashtable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.hashtable) 实例是使用此别名而不是命名空间创建的。

```csharp
using colAlias = System.Collections;
namespace System
{
    class TestClass
    {
        static void Main()
        {
            // Searching the alias:
            colAlias::Hashtable test = new colAlias::Hashtable();

            // Add items to the table.
            test.Add("A", "1");
            test.Add("B", "2");
            test.Add("C", "3");

            foreach (string name in test.Keys)
            {
                // Searching the global namespace:
                global::System.Console.WriteLine(name + " " + test[name]);
            }
        }
    }
}
```

**A 1** **B 2** **C 3**

### [How to: Use the My Namespace](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/namespaces/how-to-use-the-my-namespace)

[Microsoft.VisualBasic.MyServices](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.visualbasic.myservices) 命名空间（在 Visual Basic 中为 `My`）使访问多个 .NET Framework 类变得轻松直观，让你能够编写与计算机、应用程序、设置、资源等交互的代码。 虽然最初设计用于 Visual Basic，但 `MyServices` 命名空间仍可用于 C# 应用程序。

有关使用 Visual Basic 的 `MyServices` 命名空间的详细信息，请参阅[使用 My 开发](https://docs.microsoft.com/zh-cn/dotnet/visual-basic/developing-apps/development-with-my/index)。

#### 添加引用

可以在解决方案中使用 `MyServices` 类之前，必须添加对 Visual Basic 库的引用。

##### 添加对 Visual Basic 库的引用

1. 在解决方案资源管理器中，右键单击“引用”节点并选择“添加引用”。

2. 出现“引用”对话框时，向下滚动列表，然后选择“Microsoft.VisualBasic.dll”。

   同时建议将以下行包括在程序开头的 `using` 部分。

   ```csharp
   using Microsoft.VisualBasic.Devices;
   ```

#### 示例

此示例调用 `MyServices` 命名空间中包含的各种静态方法。 若要编译此代码，必须向项目添加对 Microsoft.VisualBasic.DLL 的引用。

```csharp
using System;
using Microsoft.VisualBasic.Devices;

class TestMyServices
{
    static void Main()
    {
        // Play a sound with the Audio class:
        Audio myAudio = new Audio();
        Console.WriteLine("Playing sound...");
        myAudio.Play(@"c:\WINDOWS\Media\chimes.wav");

        // Display time information with the Clock class:
        Clock myClock = new Clock();
        Console.Write("Current day of the week: ");
        Console.WriteLine(myClock.LocalTime.DayOfWeek);
        Console.Write("Current date and time: ");
        Console.WriteLine(myClock.LocalTime);
        
        // Display machine information with the Computer class:
        Computer myComputer = new Computer();
        Console.WriteLine("Computer name: " + myComputer.Name);

        if (myComputer.Network.IsAvailable)
        {
            Console.WriteLine("Computer is connected to network.");
        }
        else
        {
            Console.WriteLine("Computer is not connected to network.");
        }
    }
}
```

并不是 `MyServices` 命名空间中的所有类均可从 C# 应用程序中调用：例如，[FileSystemProxy](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.visualbasic.myservices.filesystemproxy) 类不兼容。 在此特定情况下，可以改为使用属于 [FileSystem](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.visualbasic.fileio.filesystem) 的静态方法，这些方法也包含在 VisualBasic.dll 中。 例如，下面介绍了如何使用此类方法来复制目录：

```csharp
// Duplicate a directory
Microsoft.VisualBasic.FileIO.FileSystem.CopyDirectory(
    @"C:\original_directory",
    @"C:\copy_of_original_directory");
```