# [Namespace Keywords](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/namespace-keywords)

本节介绍与 using 命名空间关联的关键字和运算符：

- [namespace](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/namespace)
- [using](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/using)
- [using static](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/using-static)
- [。运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/member-access-operator)
- [::运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/namespace-alias-qualifer)
- [外部别名](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/extern-alias)

## [namespace](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/namespace)

`namespace` 关键字用于声明包含一组相关对象的作用域。 可以使用命名空间来组织代码元素并创建全局唯一类型。

C#复制

```csharp
namespace SampleNamespace
{
    class SampleClass { }

    interface ISampleInterface { }

    struct SampleStruct { }

    enum SampleEnum { a, b }

    delegate void SampleDelegate(int i);

    namespace Nested
    {
        class SampleClass2 { }
    }
}
```

### 备注

在命名空间中，可以声明零个或多个以下类型：

- 另一个命名空间
- [class](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/class)
- [接口](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/interface)
- [struct](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/struct)
- [enum](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/enum)
- [delegate](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/delegate)

无论是否在 C# 源文件中显式声明命名空间，编译器都会添加一个默认命名空间。 此未命名的命名空间（有时被称为全局命名空间）存在于每个文件中。 全局命名空间中的任何标识符都可用于已命名的命名空间。

命名空间隐式具有公共访问权限，这是不可修改的。 有关可以分配给命名空间中元素的访问修饰符的讨论，请参阅[访问修饰符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/access-modifiers)。

可以在两个或多个声明中定义一个命名空间。 例如，以下示例将两个类定义为 `MyCompany` 命名空间的一部分：

C#复制

```csharp
namespace MyCompany.Proj1
{
    class MyClass
    {
    }
}

namespace MyCompany.Proj1
{
    class MyClass1
    {
    }
}
```

### 示例

以下示例显示如何在嵌套命名空间中调用静态方法。

```csharp
namespace SomeNameSpace
{
    public class MyClass 
    {
        static void Main() 
        {
            Nested.NestedNameSpaceClass.SayHello();
        }
    }

    // a nested namespace
    namespace Nested   
    {
        public class NestedNameSpaceClass 
        {
            public static void SayHello() 
            {
                Console.WriteLine("Hello");
            }
        }
    }
}
// Output: Hello
```

### 相关资源

有关使用命名空间的详细信息，请参阅以下主题：

- [命名空间](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/namespaces/index)
- [使用命名空间](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/namespaces/using-namespaces)
- [如何：使用全局命名空间别名](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/namespaces/how-to-use-the-global-namespace-alias)

## [using](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/using)

`using` 关键字有两个主要用途：

- 作为指令：用于为命名空间创建别名或导入在其他命名空间中定义的类型。 请参阅 [using 指令](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/using-directive)。
- 作为语句：用于定义一个范围，在此范围的末尾将释放对象。 请参阅 [using 语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/using-statement)。

此外，使用 [using 静态](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/using-static)指令可定义一种类型，在未指定类型名称的情况下即可访问该类型的静态成员。

### [using Directive](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/using-directive)

`using` 指令有三种用途：

- 允许在命名空间中使用类型，这样无需在该命名空间中限定某个类型的使用：

  C#复制

  ```csharp
  using System.Text;
  ```

- 允许访问类型的静态成员和嵌套类型，而无需限定使用类型名称进行访问。

  C#复制

  ```csharp
  using static System.Math;
  ```

  有关详细信息，请参阅 [using static 指令](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/using-static)。

- 为命名空间或类型创建别名。 这称为 *using 别名指令*。

  C#复制

  ```csharp
  using Project = PC.MyCompany.Project;
  ```

`using` 关键字还用于创建 using 语句，此类语句有助于确保正确处理 [IDisposable](https://docs.microsoft.com/zh-cn/dotnet/api/system.idisposable) 对象（如文件和字体）。 有关详细信息，请参阅 [using 语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/using-statement)。

#### Using 静态类型

你可以访问类型的静态成员，而无需限定使用类型名称进行访问：

C#复制

```csharp
using static System.Console;
using static System.Math;
class Program
{
    static void Main()
    {
        WriteLine(Sqrt(3*3 + 4*4));
    }
}
```

#### 备注

`using` 指令的范围限于显示它的文件。

可能出现 `using` 指令的位置：

- 源代码文件的开头，位于任何命名空间或类型定义之前。
- 在任何命名空间中，但位于此命名空间中声明的任何命名空间或类型之前。

否则，将生成编译器错误 [CS1529](https://docs.microsoft.com/zh-cn/dotnet/csharp/misc/cs1529)。

创建 `using` 别名指令，以便更易于将标识符限定为命名空间或类型。 在任何 `using` 指令中，都必须使用完全限定的命名空间或类型，而无需考虑它之前的 `using` 指令。 `using` 指令的声明中不能使用 `using` 别名。 例如，以下代码生成一个编译器错误：

C#复制

```csharp
using s = System.Text;
using s.RegularExpressions;
```

创建 `using` 指令，以便在命名空间中使用类型而不必指定命名空间。 `using` 指令不为你提供对嵌套在指定命名空间中的任何命名空间的访问权限。

命名空间分为两类：用户定义的命名空间和系统定义的命名空间。 用户定义的命名空间是在代码中定义的命名空间。 有关系统定义的命名空间的列表，请参阅 [.NET API 浏览器](https://docs.microsoft.com/zh-cn/dotnet/api/index)。

有关在其他程序集中引用方法的示例，请参阅[使用命令行创建和使用程序集](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/assemblies-gac/how-to-create-and-use-assemblies-using-the-command-line)。

#### 示例 1

下面的示例显示如何为命名空间定义和使用 `using` 别名：

C#复制

```csharp
namespace PC
{
    // Define an alias for the nested namespace.
    using Project = PC.MyCompany.Project;
    class A
    {
        void M()
        {
            // Use the alias
            Project.MyClass mc = new Project.MyClass();
        }
    }
    namespace MyCompany
    {
        namespace Project
        {
            public class MyClass { }
        }
    }
}
```

using 别名指令的右侧不能有开放式泛型类型。 例如，不能为 `List<T>` 创建 using 别名，但可以为 `List<int>`创建 using 别名。

#### 示例 2

下面的示例显示如何为类定义 `using` 指令和 `using` 别名：

C#复制

```csharp
using System;

// Using alias directive for a class.
using AliasToMyClass = NameSpace1.MyClass;

// Using alias directive for a generic class.
using UsingAlias = NameSpace2.MyClass<int>;

namespace NameSpace1
{
    public class MyClass
    {
        public override string ToString()
        {
            return "You are in NameSpace1.MyClass.";
        }
    }

}

namespace NameSpace2
{
    class MyClass<T>
    {
        public override string ToString()
        {
            return "You are in NameSpace2.MyClass.";
        }
    }
}

namespace NameSpace3
{
    // Using directive:
    using NameSpace1;
    // Using directive:
    using NameSpace2;

    class MainClass
    {
        static void Main()
        {
            AliasToMyClass instance1 = new AliasToMyClass();
            Console.WriteLine(instance1);

            UsingAlias instance2 = new UsingAlias();
            Console.WriteLine(instance2);

        }
    }
}
// Output: 
//    You are in NameSpace1.MyClass.
//    You are in NameSpace2.MyClass.
```

### [using static Directive](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/using-static)

`using static` 指令指定一种类型，无需指定类型名称即可访问其静态成员和嵌套类型。 语法为：

C#复制

```csharp
using static <fully-qualified-type-name>;
```

其中，fully-qualified-type-name 是无需指定类型名称即可访问其静态成员和嵌套类型的类型名称。 如果你不提供完全限定的类型名称（完整的命名空间名称以及类型名称），C# 便会生成编译器错误 [CS0246](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-messages/cs0246)：“找不到类型名称或命名空间名称 ’type/namespace’ (是否缺少 using 指令或程序集引用?)”。

`using static` 指令适用于任何具有静态成员（或嵌套类型）的类型，即使该类型还具有实例成员。 但是，只能通过类型实例来调用实例成员。

`using static` 指令是在 C# 6 中引入的。

#### 备注

通常，调用某个静态成员时，即会提供类型名称以及成员名称。 重复输入相同的类型名称来调用该类型的成员将生成详细的晦涩代码。 例如，`Circle` 类的以下定义引用 [Math](https://docs.microsoft.com/zh-cn/dotnet/api/system.math) 类的成员数。

C#复制

```csharp
using System;

public class Circle
{
   public Circle(double radius)
   {
      Radius = radius;
   }

   public double Radius { get; set; }

   public double Diameter
   {
      get { return 2 * Radius; }
   }

   public double Circumference
   {
      get { return 2 * Radius * Math.PI; }      
   }

   public double Area
   {
      get { return Math.PI * Math.Pow(Radius, 2); }
   }
}
```

通过消除每次引用成员时，显式引用 [Math](https://docs.microsoft.com/zh-cn/dotnet/api/system.math) 类的需求，`using static` 指令将生成更简洁的代码：

C#复制

```csharp
using System;
using static System.Math;

public class Circle
{
   public Circle(double radius)
   {
      Radius = radius;
   }

   public double Radius { get; set; }

   public double Diameter
   {
      get { return 2 * Radius; }
   }

   public double Circumference
   {
      get { return 2 * Radius * PI; }      
   }

   public double Area
   {
      get { return PI * Pow(Radius, 2); }
   }
}
```

`using static` 仅导入可访问的静态成员和指定类型中声明的嵌套类型。 不导入继承的成员。 可以从任何带 using static 指令的已命名类型导入，包括 Visual Basic 模块。 如果 F# 顶级函数在元数据中显示为一个已命名类型（其名称是有效的 C# 标识符）的静态成员，则可以导入该 F# 函数。

`using static` 使指定类型中声明的扩展方法可用于扩展方法查找。 但是，扩展方法的名称不导入到代码中非限定引用的作用域中。

同一编译单元或命名空间中通过不同 `using static` 命令从不同类型导入的具有相同名称的方法组成一个方法组。 这些方法组内的重载解决方法遵循一般 C# 规则。

#### 示例

以下示例使用 `using static` 指令来提供 [Console](https://docs.microsoft.com/zh-cn/dotnet/api/system.console)、[Math](https://docs.microsoft.com/zh-cn/dotnet/api/system.math) 和 [String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string) 类的静态成员，而无需指定其类型名称。

C#复制

```csharp
using System;
using static System.Console;
using static System.Math;
using static System.String;

class Program
{
   static void Main()
   {
      Write("Enter a circle's radius: ");
      var input = ReadLine();
      if (!IsNullOrEmpty(input) && double.TryParse(input, out var radius)) {
         var c = new Circle(radius);
         
         string s = "\nInformation about the circle:\n";
         s = s + Format("   Radius: {0:N2}\n", c.Radius);
         s = s + Format("   Diameter: {0:N2}\n", c.Diameter);
         s = s + Format("   Circumference: {0:N2}\n", c.Circumference);
         s = s + Format("   Area: {0:N2}\n", c.Area);
         WriteLine(s);
      }
      else {
         WriteLine("Invalid input...");
      }
   }
}

public class Circle
{
   public Circle(double radius)
   {
      Radius = radius;
   }

   public double Radius { get; set; }

   public double Diameter
   {
      get { return 2 * Radius; }
   }

   public double Circumference
   {
      get { return 2 * Radius * PI; }      
   }

   public double Area
   {
      get { return PI * Pow(Radius, 2); }
   }
}
// The example displays the following output:
//       Enter a circle's radius: 12.45
//       
//       Information about the circle:
//          Radius: 12.45
//          Diameter: 24.90
//          Circumference: 78.23
//          Area: 486.95
```

在此示例中，`using static` 指令也已经应用于 [Double](https://docs.microsoft.com/zh-cn/dotnet/api/system.double) 类型。 这使得在未指定类型名称情况下调用[TryParse(String, Double)](https://docs.microsoft.com/zh-cn/dotnet/api/system.double.tryparse#System_Double_TryParse_System_String_System_Double__) 方法成为可能。 但是，如此创建的代码可读性较差，因为这样有必要检查 `using static` 语句，以确定所调用的数值类型的 `TryParse` 方法。

### [using Statement](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/using-statement)

提供可确保正确使用 [IDisposable](https://docs.microsoft.com/zh-cn/dotnet/api/system.idisposable) 对象的方便语法。

#### 示例

下面的示例演示如何使用 `using` 语句。

C#复制

```csharp
using (Font font1 = new Font("Arial", 10.0f)) 
{
    byte charset = font1.GdiCharSet;
}
```

#### 备注

[File](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.file) 和 [Font](https://docs.microsoft.com/zh-cn/dotnet/api/system.drawing.font) 是访问非托管资源（本例中为文件句柄和设备上下文）的托管类型的示例。 有许多其他类别的非托管资源和封装这些资源的类库类型。 所有此类类型都必须实现 [IDisposable](https://docs.microsoft.com/zh-cn/dotnet/api/system.idisposable) 接口。

`IDisposable` 对象的生存期限于单个方法时，应在 `using` 语句中声明并实例化它。 `using` 语句按照正确的方式调用对象上的 [Dispose](https://docs.microsoft.com/zh-cn/dotnet/api/system.idisposable.dispose) 方法，并（在按照前面所示方式使用它时）会导致在调用 [Dispose](https://docs.microsoft.com/zh-cn/dotnet/api/system.idisposable.dispose) 时对象自身处于范围之外。 在 `using` 块中，对象是只读的并且无法进行修改或重新分配。

`using` 语句可确保调用 [Dispose](https://docs.microsoft.com/zh-cn/dotnet/api/system.idisposable.dispose)，即使 `using` 块中发生异常也是如此。 通过将对象放入 `try` 块中，然后调用 `finally` 块中的 [Dispose](https://docs.microsoft.com/zh-cn/dotnet/api/system.idisposable.dispose)，可以实现相同的结果；实际上，这就是编译器转换 `using` 语句的方式。 前面的代码示例在编译时将扩展到以下代码（请注意，使用额外的大括号为对象创建有限范围）：

C#复制

```csharp
{
  Font font1 = new Font("Arial", 10.0f);
  try
  {
    byte charset = font1.GdiCharSet;
  }
  finally
  {
    if (font1 != null)
      ((IDisposable)font1).Dispose();
  }
}
```

有关 `try`-`finally` 语句的详细信息，请参阅 [try-finally](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/try-finally) 主题。

可在 `using` 语句中声明一个类型的多个实例，如下面的示例中所示：

C#复制

```csharp
using (Font font3 = new Font("Arial", 10.0f),
            font4 = new Font("Arial", 10.0f))
{
    // Use font3 and font4.
}
```

可以实例化资源对象，然后将变量传递到 `using` 语句，但这不是最佳做法。 在这种情况下，控件退出 `using`块以后，对象保留在作用域中，但是可能没有访问其未托管资源的权限。 换而言之，它不再是完全初始化的。如果尝试在 `using` 块外部使用该对象，则可能导致引发异常。 因此，通常最好在 `using` 语句中实例化该对象并将其范围限制在 `using` 块中。

C#复制

```csharp
Font font2 = new Font("Arial", 10.0f);
using (font2) // not recommended
{
    // use font2
}
// font2 is still in scope
// but the method call throws an exception
float f = font2.GetHeight();
```

有关释放 `IDisposable` 对象的详细信息，请参阅[使用实现 IDisposable 的对象](https://docs.microsoft.com/zh-cn/dotnet/standard/garbage-collection/using-objects)。

## [extern alias](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/extern-alias)

有时你可能不得不引用具有相同的完全限定类型名称的程序集的两个版本。 例如，可能需要在同一应用程序中使用某程序集的两个或多个版本。 通过使用外部程序集别名，可在别名命名的根级别命名空间内包装每个程序集的命名空间，使其能够在同一文件中使用。

> [外部](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/extern)关键字还被用作方法修饰符，用于声明在非托管代码中编写的方法。

若要引用具有相同的完全限定类型名称的两个程序集，必须在命令提示符处指定别名，如下所示：

```
/r:GridV1=grid.dll
/r:GridV2=grid20.dll
```

这将创建外部别名 `GridV1` 和 `GridV2`。 若要从程序中使用这些别名，请通过使用 `extern` 关键字引用它们。例如:

```
extern alias GridV1;
extern alias GridV2;
```

每个外部别名声明都会引入与全局命名空间并行（但不位于其中）的额外根级别命名空间。 因此，可以使用其完全限定的名称（根植于相应的命名空间别名中）无歧义地引用每个程序集的类型。

在上一示例中，`GridV1::Grid` 是 `grid.dll` 中的网格控件，`GridV2::Grid` 是 `grid20.dll` 中的网格控件。