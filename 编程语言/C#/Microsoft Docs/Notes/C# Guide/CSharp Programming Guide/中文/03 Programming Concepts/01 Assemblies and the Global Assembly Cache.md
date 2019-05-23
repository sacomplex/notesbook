# [Programming Concepts](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/)

此部分介绍了 C# 语言中的编程概念。

## [Assemblies and the Global Assembly Cache](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/assemblies-gac/)

程序集构成了 .NET 应用程序的部署、版本控制、重用、激活范围和安全权限的基本单元。 作为 .NET Framework 的构建基块，程序集采用可执行文件 (.exe) 或动态链接库文件 (.dll) 的形式。 它们向公共语言运行时提供了注意类型实现代码所需的信息。 可以将程序集视为一组构成功能逻辑单元并旨在配合使用的类型和资源。

程序集可以包含一个或多个模块。 例如，可以将大型项目规划为，由多个开发者单独开发各个模块，最后将所有这些模块整合成一个程序集。 若要详细了解模块，请参阅主题[操作说明：生成多文件程序集](https://docs.microsoft.com/zh-cn/dotnet/framework/app-domains/how-to-build-a-multifile-assembly)。

程序集具有以下属性：

- 程序集以 .exe 或 .dll 文件的形式实现。
- 可以将程序集放入全局程序集缓存，以便在应用程序之间共用程序集。 必须先为程序集命名强名称，然后才能将其添加到全局程序集缓存中。 有关详细信息，请参阅[具有强名称的程序集](https://docs.microsoft.com/zh-cn/dotnet/framework/app-domains/strong-named-assemblies)。
- 只有在需要使用时才会将程序集加载到内存中。 如果不使用，就不会加载程序集。 也就是说，使用程序集，可以在大型项目中高效管理资源。
- 可以使用反射，以编程方式获取程序集的相关信息。 有关详细信息，请参阅[反射 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/reflection)。
- 如果想加载一个程序集以仅对其进行检查，请使用如 [ReflectionOnlyLoadFrom](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.assembly.reflectiononlyloadfrom) 之类的方法。

### 程序集清单

在每个程序集内，都有一个程序集清单。 与目录类似，程序集清单包含以下内容：

- 程序集的标识（名称和版本）。
- 文件表，描述构成程序集的其他所有文件（例如，.exe 或 .dll 文件依赖的其他任何程序集、位图或自述文件）。
- *程序集引用列表*，列出了应用程序需要的可能由其他人创建的所有外部依赖项（.dll 或其他文件）。 程序集既可以引用全局对象，也可以引用私有对象。 全局对象驻留在全局程序集缓存中，此区域对其他应用程序也可用。 私有对象必须位于级别不高于应用程序安装目录的目录中。

由于程序集包含内容、版本控制和依赖项的相关信息，因此使用 C# 创建的应用程序不依赖 Windows 注册表值也能正常运行。 程序集减少了 .dll 冲突，让应用程序变得更可靠、更易于部署。 在许多情况下，只需将 .NET 应用程序的文件复制到目标计算机，即可进行安装。

有关详细信息，请参阅[程序集清单](https://docs.microsoft.com/zh-cn/dotnet/framework/app-domains/assembly-manifest)。

### 添加对程序集的引用

必须添加对程序集的引用，才能使用程序集。 接下来，使用 [using 指令](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/using-directive)选择要使用的项的命名空间。 引用并导入程序集后，所有可访问的类、属性、方法和命名空间的其他成员都可供应用程序使用，就像其代码属于源文件一样。

在 C# 中，还可以在单个应用程序中使用同一程序集的两个版本。 有关详细信息，请参阅[外部别名](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/extern-alias)。

### 创建程序集

通过单击“生成”菜单上的“生成”或使用命令行编译器从命令行生成应用程序，从而编译应用程序。 若要深入了解如何从命令行生成程序集，请参阅[使用 csc.exe 实现命令行生成](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/command-line-building-with-csc-exe)。

> 若要在 Visual Studio 中生成程序集，请选择“生成”菜单上的“生成”。

### [Friend Assemblies](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/assemblies-gac/friend-assemblies)

友元程序集是可以访问其他程序集的[内部](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/internal)类型和成员的程序集。 如果将一个程序集标识为友元程序集，则无需再将类型和成员标记为公共，其他程序集就能访问它们。 此举在下列情境中尤其方便：

- 在单元测试期间，当测试代码在单独的程序集上运行，但要求访问标记为 `internal` 的正在被测试的程序集中的成员时。
- 当你正在开发类库，库的添加包含在单独的程序集中，但要求访问标记为 `internal` 的现有程序集中的成员时。

#### 备注

可使用 [InternalsVisibleToAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.compilerservices.internalsvisibletoattribute) 属性标识给定程序集的一个或多个友元程序集。 如下示例使用程序集 A 中的[InternalsVisibleToAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.compilerservices.internalsvisibletoattribute) 属性，并将程序集 `AssemblyB` 指定为友元程序集。 这使程序集 `AssemblyB` 能访问标记为 `internal` 的程序集 A 中的所有类型和成员。

> 在编译将访问另一程序集（程序集 *A*）的内部类型或内部成员的程序集（程序集 `AssemblyB`）时，必须使用**/out** 编译器选项显式指定输出文件（.exe 或 .dll）的名称。 这是必需的，因为编译器尚未为它在绑定到外部引用时而正在构建的程序集生成名称。 有关详细信息，请参阅 [/out (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/out-compiler-option)。

```csharp
using System.Runtime.CompilerServices;  
using System;  
  
[assembly: InternalsVisibleTo("AssemblyB")]  
  
// The class is internal by default.  
class FriendClass  
{  
    public void Test()  
    {  
        Console.WriteLine("Sample Class");  
    }  
}  
  
// Public class that has an internal method.  
public class ClassWithFriendMethod  
{  
    internal void Test()  
    {  
        Console.WriteLine("Sample Method");  
    }  
  
}  
```

只有显式指定为友元的程序集才能访问 `internal` 类型和成员。 例如，如果程序集 B 是程序集 A 的友元，且程序集 C 引用了程序集 B，则 C 无法访问 A 中的 `internal` 类型。

编译器对传递到 [InternalsVisibleToAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.compilerservices.internalsvisibletoattribute) 属性的友元程序集名称执行一些基本验证。 如果程序集 *A* 将 *B* 声明为友元程序集，则验证规则如下：

- 如果程序集 *A* 是强名称的程序集，那么程序集 *B* 也必须是强名称的。 传递到特性的友元程序集名称必须包含有程序集名称，和用于对程序集 *B* 签名的强名称密钥的公钥。

  传递到 [InternalsVisibleToAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.compilerservices.internalsvisibletoattribute) 属性的友元程序集名称不能是程序集 B 的强名称：请勿包含程序集版本、区域性、体系结构或公钥令牌。

- 如果程序集 *A* 不是强名称，则友元程序集名称应仅由程序集名称构成。 有关详细信息，请参阅[如何：创建未签名的友元程序集 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/assemblies-gac/how-to-create-unsigned-friend-assemblies)。

- 如果程序集 *B* 是强名称，则必须使用项目设置或命令行 `/keyfile` 编译器选项为程序集 *B* 指定强名称密钥。有关详细信息，请参阅[如何：创建签名的友元程序集 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/assemblies-gac/how-to-create-signed-friend-assemblies)。

[StrongNameIdentityPermission](https://docs.microsoft.com/zh-cn/dotnet/api/system.security.permissions.strongnameidentitypermission) 类还提供类型共享功能，但具有以下差异：

- [StrongNameIdentityPermission](https://docs.microsoft.com/zh-cn/dotnet/api/system.security.permissions.strongnameidentitypermission) 应用到单个类型，而友元程序集应用到整个程序集。
- 如果要与程序集 B 共享程序集 A 中的数百个类型，则必须向它们全部添加 [StrongNameIdentityPermission](https://docs.microsoft.com/zh-cn/dotnet/api/system.security.permissions.strongnameidentitypermission)。如果使用友元程序集，只需声明友元关系一次。
- 如果使用 [StrongNameIdentityPermission](https://docs.microsoft.com/zh-cn/dotnet/api/system.security.permissions.strongnameidentitypermission)，必须将要共享的类型声明为公共类型。 如果使用友元程序集，共享的类型会声明为 `internal`。

有关如何从模块文件（扩展名为 .netmodule 的文件）访问程序集的 `internal` 类型和方法，请参阅 [/moduleassemblyname (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/moduleassemblyname-compiler-option)。

#### [How to: Create Unsigned Friend Assemblies](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/assemblies-gac/how-to-create-unsigned-friend-assemblies)

本示例演示如何将友元程序集和未签名的程序集一起使用。

##### 创建程序集和友元程序集

1. 打开命令提示。

2. 创建一个名为 `friend_unsigned_A.` 的 C# 文件，其中包含以下代码。 该代码使用 [InternalsVisibleToAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.compilerservices.internalsvisibletoattribute)属性将 friend_unsigned_B 声明为友元程序集。

   ```csharp
   // friend_unsigned_A.cs  
   // Compile with:   
   // csc /target:library friend_unsigned_A.cs  
   using System.Runtime.CompilerServices;  
   using System;  
   
   [assembly: InternalsVisibleTo("friend_unsigned_B")]  
   
   // Type is internal by default.  
   class Class1  
   {  
       public void Test()  
       {  
           Console.WriteLine("Class1.Test");  
       }  
   }  
   
   // Public type with internal member.  
   public class Class2  
   {  
       internal void Test()  
       {  
           Console.WriteLine("Class2.Test");  
       }  
   }  
   ```

3. 使用以下命令编译 friend_unsigned_A 并为其签名。

   ```csharp
   csc /target:library friend_unsigned_A.cs  
   ```

4. 创建一个名为 `friend_unsigned_B` 的 C# 文件，其中包含以下代码。 由于 friend_unsigned_A 将 friend_unsigned_B 指定为友元程序集，因此 friend_unsigned_B 中的代码可以访问 friend_unsigned_A 中的 `internal` 类型和成员。

   ```csharp
   // friend_unsigned_B.cs  
   // Compile with:   
   // csc /r:friend_unsigned_A.dll /out:friend_unsigned_B.exe friend_unsigned_B.cs  
   public class Program  
   {  
       static void Main()  
       {  
           // Access an internal type.  
           Class1 inst1 = new Class1();  
           inst1.Test();  
   
           Class2 inst2 = new Class2();  
           // Access an internal member of a public type.  
           inst2.Test();  
   
           System.Console.ReadLine();  
       }  
   }  
   ```

5. 使用以下命令编译 friend_unsigned_B。

   ```csharp
   csc /r:friend_unsigned_A.dll /out:friend_unsigned_B.exe friend_unsigned_B.cs  
   ```

   编译器生成的程序集的名称必须与传递给 [InternalsVisibleToAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.compilerservices.internalsvisibletoattribute) 属性的友元程序集的名称匹配。 必须使用 `/out` 编译器选项显式指定输出程序集（.exe 或 .dll）的名称。 有关详细信息，请参阅 [/out（C# 编译器选项）](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/out-compiler-option)。

6. 运行 friend_unsigned_B.exe 文件。

   该程序将输出两个字符串：“Class1.Test”和“Class2.Test”。

##### .NET Framework 安全性

[InternalsVisibleToAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.compilerservices.internalsvisibletoattribute) 属性和 [StrongNameIdentityPermission](https://docs.microsoft.com/zh-cn/dotnet/api/system.security.permissions.strongnameidentitypermission) 类之间具有相似之处。 主要区别是，[StrongNameIdentityPermission](https://docs.microsoft.com/zh-cn/dotnet/api/system.security.permissions.strongnameidentitypermission) 可以要求安全权限来运行一段特定代码，而 [InternalsVisibleToAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.compilerservices.internalsvisibletoattribute) 属性控制 `internal` 类型和成员的可见性。

#### [How to: Create Signed Friend Assemblies](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/assemblies-gac/how-to-create-signed-friend-assemblies)

本示例演示如何将友元程序集和具有强名称的程序集一起使用。 这两种程序集必须都使用强名称。 尽管本示例中的两种程序集使用相同的密钥，但可以对这两种程序集使用不同的密钥。

##### 创建签名的程序集和友元程序集

1. 打开命令提示。

2. 使用强名称工具，通过以下命令序列生成 keyfile 并显示其公钥。 有关详细信息，请参阅 [Sn.exe （强名称工具）](https://docs.microsoft.com/zh-cn/dotnet/framework/tools/sn-exe-strong-name-tool)。

   1. 生成此示例的强名称密钥，并将其存储在 FriendAssemblies.snk 文件中：

      `sn -k FriendAssemblies.snk`

   2. 从 FriendAssemblies.snk 文件中提取公钥，将其放入 FriendAssemblies.publickey 中：

      `sn -p FriendAssemblies.snk FriendAssemblies.publickey`

   3. 显示存储在 FriendAssemblies.publickey 文件中的公钥：

      `sn -tp FriendAssemblies.publickey`

3. 创建一个名为 `friend_signed_A` 的 C# 文件，其中包含以下代码。 该代码使用 [InternalsVisibleToAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.compilerservices.internalsvisibletoattribute) 属性将 friend_signed_B 声明为友元程序集。

   强名称工具在每次运行时生成新的公钥。 因此，必须将以下代码中的公钥替换为刚生成的公钥，如以下示例所示。

   ```csharp
   // friend_signed_A.cs  
   // Compile with:   
   // csc /target:library /keyfile:FriendAssemblies.snk friend_signed_A.cs  
   using System.Runtime.CompilerServices;  
   
   [assembly: InternalsVisibleTo("friend_signed_B, PublicKey=0024000004800000940000000602000000240000525341310004000001000100e3aedce99b7e10823920206f8e46cd5558b4ec7345bd1a5b201ffe71660625dcb8f9a08687d881c8f65a0dcf042f81475d2e88f3e3e273c8311ee40f952db306c02fbfc5d8bc6ee1e924e6ec8fe8c01932e0648a0d3e5695134af3bb7fab370d3012d083fa6b83179dd3d031053f72fc1f7da8459140b0af5afc4d2804deccb6")]  
   class Class1  
   {  
       public void Test()  
       {  
           System.Console.WriteLine("Class1.Test");  
           System.Console.ReadLine();  
       }  
   }  
   ```

4. 使用以下命令编译 friend_signed_A 并为其签名。

   ```csharp
   csc /target:library /keyfile:FriendAssemblies.snk friend_signed_A.cs  
   ```

5. 创建一个名为 `friend_signed_B` 的 C# 文件，并包含以下代码。 由于 friend_signed_A 将 friend_signed_B 指定为友元程序集，因此 friend_signed_B 中的代码可以访问 friend_signed_A 中的 `internal` 类型和成员。 文件包含以下代码。

   ```csharp
   // friend_signed_B.cs  
   // Compile with:   
   // csc /keyfile:FriendAssemblies.snk /r:friend_signed_A.dll /out:friend_signed_B.exe friend_signed_B.cs  
   public class Program  
   {  
       static void Main()  
       {  
           Class1 inst = new Class1();  
           inst.Test();  
       }  
   }  
   ```

6. 使用以下命令编译 friend_signed_B 并为其签名。

   ```csharp
   csc /keyfile:FriendAssemblies.snk /r:friend_signed_A.dll /out:friend_signed_B.exe friend_signed_B.cs  
   ```

   编译器生成的程序集的名称必须与传递给 [InternalsVisibleToAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.compilerservices.internalsvisibletoattribute) 属性的友元程序集的名称匹配。 必须使用 `/out` 编译器选项显式指定输出程序集（.exe 或 .dll）的名称。 有关详细信息，请参阅 [/out（C# 编译器选项）](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/out-compiler-option)。

7. 运行 friend_signed_B.exe 文件。

   程序将打印字符串“Class1.Test”。

##### .NET Framework 安全性

[InternalsVisibleToAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.compilerservices.internalsvisibletoattribute) 属性和 [StrongNameIdentityPermission](https://docs.microsoft.com/zh-cn/dotnet/api/system.security.permissions.strongnameidentitypermission) 类之间具有相似之处。 主要区别是，[StrongNameIdentityPermission](https://docs.microsoft.com/zh-cn/dotnet/api/system.security.permissions.strongnameidentitypermission) 可以要求安全权限来运行一段特定代码，而 [InternalsVisibleToAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.compilerservices.internalsvisibletoattribute) 属性控制 `internal` 类型和成员的可见性。

### [How to: Create and Use Assemblies Using the Command Line](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/assemblies-gac/how-to-create-and-use-assemblies-using-the-command-line)

程序集或动态链接库 (DLL) 会在运行时链接到程序。 为了演示如何生成和使用 DLL，请考虑以下方案：

- `MathLibrary.DLL`：包含要在运行时调用的方法的库文件。 在此示例中，DLL 包含两个方法，即 `Add` 和 `Multiply`。
- `Add`：包含方法 `Add` 的源文件。 它返回其参数的总和。 包含方法 `Add` 的类 `AddClass` 是命名空间 `UtilityMethods` 的成员。
- `Mult`：包含方法 `Multiply` 的源代码。 它返回其参数的乘积。 包含方法 `Multiply` 的类 `MultiplyClass`也是命名空间 `UtilityMethods` 的成员。
- `TestCode`：包含 `Main` 方法的文件。 它使用 DLL 文件中的方法计算运行时参数的总和与乘积。

#### 示例

```csharp
// File: Add.cs   
namespace UtilityMethods  
{  
    public class AddClass   
    {  
        public static long Add(long i, long j)   
        {   
            return (i + j);  
        }  
    }  
}  
```

```csharp
// File: Mult.cs  
namespace UtilityMethods   
{  
    public class MultiplyClass  
    {  
        public static long Multiply(long x, long y)   
        {  
            return (x * y);   
        }  
    }  
}  
```

```csharp
// File: TestCode.cs  
  
using UtilityMethods;  
  
class TestCode  
{  
    static void Main(string[] args)   
    {  
        System.Console.WriteLine("Calling methods from MathLibrary.DLL:");  
  
        if (args.Length != 2)  
        {  
            System.Console.WriteLine("Usage: TestCode <num1> <num2>");  
            return;  
        }  
  
        long num1 = long.Parse(args[0]);  
        long num2 = long.Parse(args[1]);  
  
        long sum = AddClass.Add(num1, num2);  
        long product = MultiplyClass.Multiply(num1, num2);  
  
        System.Console.WriteLine("{0} + {1} = {2}", num1, num2, sum);  
        System.Console.WriteLine("{0} * {1} = {2}", num1, num2, product);  
    }  
}  
/* Output (assuming 1234 and 5678 are entered as command-line arguments):  
    Calling methods from MathLibrary.DLL:  
    1234 + 5678 = 6912  
    1234 * 5678 = 7006652          
*/  
```

此文件包含使用 DLL 方法 `Add` 和 `Multiply` 的算法。 它首先分析从命令行输入的参数 `num1` 和 `num2`。 然后通过对 `AddClass` 类使用 `Add` 方法来计算总和，并通过对 `MultiplyClass` 类使用 `Multiply` 方法来计算乘积。

请注意，文件开头的 `using` 指令使你可以使用非限定类名在编译时引用 DLL 方法，如下所示：

```csharp
MultiplyClass.Multiply(num1, num2);  
```

否则，你必须使用完全限定的名称，如下所示：

```csharp
UtilityMethods.MultiplyClass.Multiply(num1, num2);  
```

#### 执行

若要运行程序，请输入 EXE 文件的名称，后跟两个数字，如下所示：

```
TestCode 1234 5678
```

#### 编译代码

若要生成文件 `MathLibrary.DLL`，请使用以下命令行编译两个文件 `Add` 和 `Mult`。

```csharp
csc /target:library /out:MathLibrary.DLL Add.cs Mult.cs  
```

[/target:library](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/target-library-compiler-option) 编译器选项告知编译器输出 DLL 而不是 EXE 文件。 后跟文件名的 [/out](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/out-compiler-option) 编译器选项用于指定 DLL 文件名。 否则，编译器使用第一个文件 (`Add.cs`) 作为 DLL 的名称。

若要生成可执行文件 `TestCode.exe`，请使用以下命令行：

```csharp
csc /out:TestCode.exe /reference:MathLibrary.DLL TestCode.cs  
```

**/out** 编译器选项告知编译器输出 EXE 文件并指定输出文件的名称 (`TestCode.exe`)。 此编译器选项是可选的。[/reference](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/reference-compiler-option) 编译器选项指定此程序使用的 DLL 文件。 有关详细信息，请参阅 [/reference](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/reference-compiler-option)。

有关从命令行进行生成的详细信息，请参阅[在命令行上使用 csc.exe 生成](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/command-line-building-with-csc-exe)。

### [How to: Determine If a File Is an Assembly](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/assemblies-gac/how-to-determine-if-a-file-is-an-assembly)

当且仅当程序集处于托管状态，并在其元数据中包含程序集条目时，该文件才为程序集。 有关程序集和元数据的详细信息，请参阅主题[程序集清单](https://docs.microsoft.com/zh-cn/dotnet/framework/app-domains/assembly-manifest)。

#### 如何手动确定文件是否为程序集

1. 启动 [Ildasm.exe（IL 反汇编程序）](https://docs.microsoft.com/zh-cn/dotnet/framework/tools/ildasm-exe-il-disassembler)。
2. 加载要测试的文件。
3. 如果 **ILDASM** 报告文件不是可移植的可执行 (PE) 文件，则不是程序集。 有关详细信息，请参阅主题[如何：查看程序集内容](https://docs.microsoft.com/zh-cn/dotnet/framework/app-domains/how-to-view-assembly-contents)。

#### 如何以编程方式确定文件是否为程序集

1. 调用 [GetAssemblyName](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.assemblyname.getassemblyname) 方法，传递要测试的文件的完整文件路径和名称。
2. 如果引发 [BadImageFormatException](https://docs.microsoft.com/zh-cn/dotnet/api/system.badimageformatexception) 异常，则该文件不是程序集。

#### 示例

此示例测试 DLL 以查看其是否为程序集。

```csharp
class TestAssembly  
{  
    static void Main()  
    {  
  
        try  
        {  
            System.Reflection.AssemblyName testAssembly =  
                System.Reflection.AssemblyName.GetAssemblyName(@"C:\Windows\Microsoft.NET\Framework\v3.5\System.Net.dll");  
  
            System.Console.WriteLine("Yes, the file is an assembly.");  
        }  
  
        catch (System.IO.FileNotFoundException)  
        {  
            System.Console.WriteLine("The file cannot be found.");  
        }  
  
        catch (System.BadImageFormatException)  
        {  
            System.Console.WriteLine("The file is not an assembly.");  
        }  
  
        catch (System.IO.FileLoadException)  
        {  
            System.Console.WriteLine("The assembly has already been loaded.");  
        }  
    }  
}  
/* Output (with .NET Framework 3.5 installed):  
    Yes, the file is an assembly.  
*/  
```

[GetAssemblyName](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.assemblyname.getassemblyname) 方法加载测试文件，然后在读取信息之后释放它。

### [How to: Load and Unload Assemblies](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/assemblies-gac/how-to-load-and-unload-assemblies)

在生成时自动加载程序所引用的程序集，但也可以在运行时将特定的程序集加载到当前的应用程序域。 有关详细信息，请参阅[如何：将程序集加载到应用程序域中](https://docs.microsoft.com/zh-cn/dotnet/framework/app-domains/how-to-load-assemblies-into-an-application-domain)。

在没有卸载所有包含单个程序集的应用程序域之前，无法卸载此程序集。 即使程序集不在范围之内，在卸载包含它的所有应用程序域之前，实际的程序集文件都将保持加载状态。

如果想要卸载某些程序集而不是其他程序集，请考虑创建一个新的应用程序域，在此域中执行代码，然后卸载此应用程序域。 有关详细信息，请参阅[如何：卸载应用程序域](https://docs.microsoft.com/zh-cn/dotnet/framework/app-domains/how-to-unload-an-application-domain)。

#### 将程序集加载到应用程序域中

1. 使用 [AppDomain](https://docs.microsoft.com/zh-cn/dotnet/api/system.appdomain) 和 [System.Reflection](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection) 类中包含的几种加载方法中的一种。 有关详细信息，请参阅[如何：将程序集加载到应用程序域中](https://docs.microsoft.com/zh-cn/dotnet/framework/app-domains/how-to-load-assemblies-into-an-application-domain)。

#### 卸载应用程序域

1. 在没有卸载所有包含单个程序集的应用程序域之前，无法卸载此程序集。 使用 [AppDomain](https://docs.microsoft.com/zh-cn/dotnet/api/system.appdomain) 中的 `Unload` 方法卸载应用程序域。 有关详细信息，请参阅[如何：卸载应用程序域](https://docs.microsoft.com/zh-cn/dotnet/framework/app-domains/how-to-unload-an-application-domain)。

### [How to: Share an Assembly with Other Applications](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/assemblies-gac/how-to-share-an-assembly-with-other-applications)

程序集可以是私有或共享程序集：默认情况下，大多数简单程序都包含一个私有程序集，因为它们并不打算由其他应用程序使用。

若要与其他应用程序共享程序集，必须将它放置在[全局程序集缓存](https://docs.microsoft.com/zh-cn/dotnet/framework/app-domains/gac) (GAC) 中。

#### 共享程序集

1. 创建程序集。 有关详细信息，请参阅[创建程序集](https://docs.microsoft.com/zh-cn/dotnet/framework/app-domains/create-assemblies)。
2. 向程序集分配强名称。 有关详细信息，请参阅[如何：使用强名称为程序集签名](https://docs.microsoft.com/zh-cn/dotnet/framework/app-domains/how-to-sign-an-assembly-with-a-strong-name)。
3. 将版本信息分配给程序集。 有关详细信息，请参阅[程序集版本控制](https://docs.microsoft.com/zh-cn/dotnet/framework/app-domains/assembly-versioning)。
4. 将程序集添加到全局程序集缓存中。 有关详细信息，请参阅[如何：将程序集安装到全局程序集缓存](https://docs.microsoft.com/zh-cn/dotnet/framework/app-domains/how-to-install-an-assembly-into-the-gac)。
5. 从其他应用程序访问该程序集中包含的类型。 有关详细信息，请参阅[如何：引用具有强名称的程序集](https://docs.microsoft.com/zh-cn/dotnet/framework/app-domains/how-to-reference-a-strong-named-assembly)。

### [Walkthrough: Embedding Types from Managed Assemblies in Visual Studio](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/assemblies-gac/walkthrough-embedding-types-from-managed-assemblies-in-visual-studio)

如果嵌入强命名托管程序集中的类型信息，则可以对应用程序中的类型进行松耦合，以实现版本独立性。 也就是说，可以将程序编写为使用多个托管库版本中的类型，而不必对每个版本重新编译程序。

类型嵌入经常与 COM 互操作一起使用，例如使用 Microsoft Office 中的自动化对象的应用程序。 通过嵌入类型信息，程序的同一个版本可以处理不同计算机上的不同 Microsoft Office 版本。 但也可以在完全托管的解决方案中使用类型嵌入。

可从具有以下特征的程序集嵌入类型信息：

- 程序集至少公开一个公共接口。
- 嵌入的接口使用 `ComImport` 特性和 `Guid` 特性（及一个唯一 GUID）进行批注。
- 程序集使用 `ImportedFromTypeLib` 特性或 `PrimaryInteropAssembly` 特性和程序集级别的 `Guid` 特性进行批注。 （默认情况下，Visual C# 项目模板包含程序集级别的 `Guid` 特性。）

指定可嵌入的公共接口后，可以创建实现这些接口的运行时类。 然后，客户端程序可以通过引用包含这些公共接口的程序集，并将该引用的 `Embed Interop Types` 属性设置为 `True`，在设计时嵌入这些接口的类型信息。 这等效于使用命令行编译器和通过 `/link` 编译器选项引用该程序集。 然后，客户端程序可以加载类型化为这些接口的运行时对象的实例。 如果创建新版本的强命名运行时程序集，则不必使用更新的运行时程序集来重新编译客户端程序。 客户端程序将使用公共接口的嵌入类型信息，从而继续使用任何可用的运行时程序集版本。

由于类型嵌入的主要功能是提供对 COM 互操作程序集中类型信息的嵌入的支持，因此以下限制在将类型信息嵌入完全托管解决方案中时适用：

- 仅嵌入特定于 COM 互操作的特性；忽略其他特性。
- 如果一个类型使用泛型参数且泛型参数的类型是嵌入类型，则不能跨程序集边界使用该类型。 跨程序集边界的示例包括从另一个程序集调用方法或从另一个程序集中定义的类型派生类型。
- 不嵌入常量。
- [System.Collections.Generic.Dictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.dictionary-2) 类不支持将嵌入类型作为密钥。 可以实现自己的字典类型以支持将嵌入类型作为密钥。

本演练中将执行以下操作：

- 创建一个强命名程序集，它具有包含可嵌入类型信息的公共接口。
- 创建一个实现该公共接口的强命名运行时程序集。
- 创建一个客户端程序，该程序嵌入公共接口中的类型信息，并创建运行时程序集中的类的实例。
- 修改并重新生成运行时程序集。
- 运行客户端程序，查看正在使用的运行时程序集新版本，而不必重新编译该客户端程序。

 备注

以下说明中的某些 Visual Studio 用户界面元素在计算机上出现的名称或位置可能会不同。 这些元素取决于你所使用的 Visual Studio 版本和你所使用的设置。 有关详细信息，请参阅[个性化设置 IDE](https://docs.microsoft.com/zh-cn/visualstudio/ide/personalizing-the-visual-studio-ide)。

#### 创建接口

##### 创建类型等效性接口项目

1. 在 Visual Studio 中的“文件”菜单上，选择“新建”，然后单击“项目”。

2. 在“新建项目”对话框的“项目类型”窗格中，确保选中“Windows”。 在“模板”窗格中，选择“类库”。 在“名称”框中，键入 `TypeEquivalenceInterface`，然后单击“确定”。 新项目创建完成。

3. 在“解决方案资源管理器”中，右键单击 Class1.cs 文件，然后单击“重命名”。 将文件重命名为 `ISampleInterface.cs`，然后按 Enter。 重命名文件也会将类重命名为 `ISampleInterface`。 此类将表示类的公共接口。

4. 右键单击 TypeEquivalenceInterface 项目，然后单击“属性”。 单击“生成”选项卡。将输出路径设置为开发计算机上的有效位置，例如 `C:\TypeEquivalenceSample`。 本演练的后续步骤中也将使用此位置。

5. 在编辑项目属性期间，单击“签名”选项卡。选择“为程序集签名”选项。 在“选择强名称密钥文件”列表中，单击“<新建…>”。 在“密钥文件名”框中，键入 `key.snk`。 清除“使用密码保护密钥文件”复选框。 单击 **“确定”**。

6. 打开 ISampleInterface.cs 文件。 将以下代码添加到 ISampleInterface 类文件，以创建 ISampleInterface 接口。

   ```csharp
   using System;  
   using System.Runtime.InteropServices;  
   
   namespace TypeEquivalenceInterface  
   {  
       [ComImport]  
       [Guid("8DA56996-A151-4136-B474-32784559F6DF")]  
       public interface ISampleInterface  
       {  
           void GetUserInput();  
           string UserInput { get; }  
       }  
   }  
   ```

7. 在“工具”菜单上，单击“创建 Guid”。 在“创建 GUID”对话框中，单击“注册表格式”，然后单击“复制”。 单击“退出” 。

8. 在 `Guid` 特性中，删除示例 GUID ，并粘贴从“创建 GUID”对话框复制的 GUID。 删除复制的 GUID 中的大括号 ({})。

9. 在“解决方案资源管理器”中，展开“属性”文件夹。 双击 AssemblyInfo.cs 文件。 向文件中添加以下特性。

   C#复制

   ```csharp
   [assembly: ImportedFromTypeLib("")]  
   ```

   保存该文件。

10. 保存项目。

11. 右键单击 TypeEquivalenceInterface 项目，然后单击“生成”。 此时将编译类库 .dll 文件，并保存到指定的生成输出路径中（如 C:\TypeEquivalenceSample）。

#### 创建运行时类

##### 创建类型等效性运行时项目

1. 在 Visual Studio 中的“文件”菜单上，指向“新建”，然后单击“项目”。

2. 在“新建项目”对话框的“项目类型”窗格中，确保选中“Windows”。 在“模板”窗格中，选择“类库”。 在“名称”框中，键入 `TypeEquivalenceRuntime`，然后单击“确定”。 新项目创建完成。

3. 在“解决方案资源管理器”中，右键单击 Class1.cs 文件，然后单击“重命名”。 将文件重命名为 `SampleClass.cs`，然后按 Enter。 重命名文件也会将类重命名为 `SampleClass`。 此类将实现 `ISampleInterface` 接口。

4. 右键单击 TypeEquivalenceRuntime 项目，然后单击“属性”。 单击“生成”选项卡。将输出路径设置为 TypeEquivalenceInterface 项目中所用的同一位置，例如，`C:\TypeEquivalenceSample`。

5. 在编辑项目属性期间，单击“签名”选项卡。选择“为程序集签名”选项。 在“选择强名称密钥文件”列表中，单击“<新建…>”。 在“密钥文件名”框中，键入 `key.snk`。 清除“使用密码保护密钥文件”复选框。 单击 **“确定”**。

6. 右键单击 TypeEquivalenceRuntime 项目，然后单击“添加引用”。 单击“浏览”选项卡，然后浏览到输出路径文件夹。 选择 TypeEquivalenceInterface.dll 文件并单击“确定”。

7. 在“解决方案资源管理器”中，展开“引用”文件夹。 选择 TypeEquivalenceInterface 引用。 在 TypeEquivalenceInterface 引用的“属性”窗口中，将“特定版本”属性设置为“False”。

8. 将以下代码添加到 SampleClass 类文件，以创建 SampleClass 类。

   ```csharp
   using System;  
   using System.Collections.Generic;  
   using System.Linq;  
   using System.Text;  
   using TypeEquivalenceInterface;  
   
   namespace TypeEquivalenceRuntime  
   {  
       public class SampleClass : ISampleInterface  
       {  
           private string p_UserInput;  
           public string UserInput { get { return p_UserInput; } }  
   
           public void GetUserInput()  
           {  
               Console.WriteLine("Please enter a value:");  
               p_UserInput = Console.ReadLine();  
           }  
       }  
   }  
   ```

9. 保存项目。

10. 右键单击 TypeEquivalenceRuntime 项目，然后单击“生成”。 此时将编译类库 .dll 文件，并保存到指定的生成输出路径中（如 C:\TypeEquivalenceSample）。

#### 创建客户端项目

##### 创建类型等效性客户端项目

1. 在 Visual Studio 中的“文件”菜单上，指向“新建”，然后单击“项目”。

2. 在“新建项目”对话框的“项目类型”窗格中，确保选中“Windows”。 在“模板”窗格中，选择“控制台应用程序”。在“名称”框中，键入 `TypeEquivalenceClient`，然后单击“确定”。 新项目创建完成。

3. 右键单击 TypeEquivalenceClient 项目，然后单击“属性”。 单击“生成”选项卡。将输出路径设置为 TypeEquivalenceInterface 项目中所用的同一位置，例如，`C:\TypeEquivalenceSample`。

4. 右键单击 TypeEquivalenceClient 项目，然后单击“添加引用”。 单击“浏览”选项卡，然后浏览到输出路径文件夹。 选择 TypeEquivalenceInterface.dll 文件（不是 TypeEquivalenceRuntime.dll）并单击“确定”。

5. 在“解决方案资源管理器”中，展开“引用”文件夹。 选择 TypeEquivalenceInterface 引用。 在 TypeEquivalenceInterface 引用的“属性”窗口中，将“嵌入互操作类型”属性设置为“True”。

6. 将以下代码添加到 Program.cs 文件，以创建客户端程序。

   C#复制

   ```csharp
   using System;  
   using System.Collections.Generic;  
   using System.Linq;  
   using System.Text;  
   using TypeEquivalenceInterface;  
   using System.Reflection;  
   
   namespace TypeEquivalenceClient  
   {  
       class Program  
       {  
           static void Main(string[] args)  
           {  
               Assembly sampleAssembly = Assembly.Load("TypeEquivalenceRuntime");  
               ISampleInterface sampleClass =   
                   (ISampleInterface)sampleAssembly.CreateInstance("TypeEquivalenceRuntime.SampleClass");  
               sampleClass.GetUserInput();  
               Console.WriteLine(sampleClass.UserInput);  
               Console.WriteLine(sampleAssembly.GetName().Version.ToString());  
               Console.ReadLine();  
           }  
       }  
   }  
   ```

7. 按 Ctrl+F5 生成并运行程序。

#### 修改接口

##### 修改接口

1. 在 Visual Studio 中的“文件”菜单上，指向“打开”，然后单击“项目/解决方案”。

2. 在“打开项目”对话框中，右键单击 TypeEquivalenceInterface 项目，然后单击“属性”。 单击“应用程序” 选项卡。单击“程序集信息”按钮。 将“程序集版本”和“文件版本”的值更改为 `2.0.0.0`。

3. 打开 SampleInterface.cs 文件。 将以下代码行添加到 ISampleInterface 接口。

   ```csharp
   DateTime GetDate();  
   ```

   保存该文件。

4. 保存项目。

5. 右键单击 TypeEquivalenceInterface 项目，然后单击“生成”。 此时将编译新版本的类库 .dll 文件，并保存到指定的生成输出路径中（如 C:\TypeEquivalenceSample）。

#### 修改运行时类

##### 修改运行时类

1. 在 Visual Studio 中的“文件”菜单上，指向“打开”，然后单击“项目/解决方案”。

2. 在“打开项目”对话框中，右键单击 TypeEquivalenceRuntime 项目，然后单击“属性”。 单击“应用程序” 选项卡。单击“程序集信息”按钮。 将“程序集版本”和“文件版本”的值更改为 `2.0.0.0`。

3. 打开 SampleClass.cs 文件。 将以下代码行添加到 SampleClass 类。

   ```csharp
   public DateTime GetDate()  
   {  
       return DateTime.Now;  
   }  
   ```

   保存该文件。

4. 保存项目。

5. 右键单击 TypeEquivalenceRuntime 项目，然后单击“生成”。 此时将编译更新版本的类库 .dll 文件，并保存到之前指定的生成输出路径中（如 C:\TypeEquivalenceSample）。

6. 在文件资源管理器中，打开输出路径文件夹（如 C:\TypeEquivalenceSample）。 双击 TypeEquivalenceClient.exe 运行该程序。 程序将反映 TypeEquivalenceRuntime 程序集的未经重新编译的新版本。

### [Walkthrough: Embedding Type Information from Microsoft Office Assemblies in Visual Studio](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/assemblies-gac/walkthrough-embedding-type-information-from-microsoft-office-assemblies)

如果在引用 COM 对象的应用程序中嵌入类型信息，则无需使用主互操作程序集 (PIA)。 此外，利用嵌入的类型信息可实现应用程序的版本独立性。 也就是说，可将程序编写为使用多个 COM 库版本中的类型，而无需使用每个版本的特定 PIA。 对于使用 Microsoft Office 库中对象的应用程序，这是一种常用方案。 通过嵌入类型信息，程序的同一个生成可以使用不同计算机上的不同 Microsoft Office 版本，而无需为 Microsoft Office 的每个版本重新部署该程序或 PIA。

> 以下说明中的某些 Visual Studio 用户界面元素在计算机上出现的名称或位置可能会不同。 这些元素取决于你所使用的 Visual Studio 版本和你所使用的设置。 有关详细信息，请参阅[个性化设置 IDE](https://docs.microsoft.com/zh-cn/visualstudio/ide/personalizing-the-visual-studio-ide)。

#### 系统必备

本演练需要如下内容：

- 安装有 Visual Studio 和 Microsoft Excel 的计算机。
- 安装有 .NET Framework 4 或更高版本和其他 Excel 版本的另一台计算机。

#### 创建适用于多个 Microsoft Office 版本的应用程序

1. 在安装有 Excel 的计算机上启动 Visual Studio。

2. 在“文件” 菜单上，选择“新建” 、“项目” 。

3. 在“新建项目”对话框的“项目类型”窗格中，确保选中“Windows”。 在“模板”窗格中，选择“控制台应用程序”。在“新建项目”框中，输入 `CreateExcelWorkbook`，然后选择“确定”按钮。 新项目创建完成。

4. 在“解决方案资源管理器”中，打开“引用”文件夹的快捷菜单，然后选择“添加引用”。

5. 在“.NET”选项卡上，选择最新版本的 `Microsoft.Office.Interop.Excel`。 例如 **Microsoft.Office.Interop.Excel 14.0.0.0**。 选择“确定” 按钮。

6. 在 **CreateExcelWorkbook** 项目的引用列表中，选择上一步添加的 `Microsoft.Office.Interop.Excel` 引用。在“属性”窗口中，确保 `Embed Interop Types` 属性已设置为 `True`。

    备注

   由于嵌入的互操作类型信息，本演练中创建的应用程序可与不同的 Microsoft Office 版本一起运行。 如果 `Embed Interop Types` 属性设置为 `False`，则必须为与应用程序一起运行的每个 Microsoft Office 版本添加一个 PIA。

7. 打开 **Program.cs** 文件。 用下面的代码替换文件中的代码：

   ```csharp
   using System;  
   using System.Collections.Generic;  
   using System.Linq;  
   using System.Text;  
   using System.IO;  
   using Excel = Microsoft.Office.Interop.Excel;  
   
   namespace CreateExcelWorkbook  
   {  
       class Program  
       {  
           static void Main(string[] args)  
           {  
               int[] values = {4, 6, 18, 2, 1, 76, 0, 3, 11};  
   
               CreateWorkbook(values, @"C:\SampleFolder\SampleWorkbook.xls");  
           }  
   
           static void CreateWorkbook(int[] values, string filePath)  
           {  
               Excel.Application excelApp = null;  
               Excel.Workbook wkbk;  
               Excel.Worksheet sheet;  
   
               try  
               {  
                       // Start Excel and create a workbook and worksheet.  
                       excelApp = new Excel.Application();  
                       wkbk = excelApp.Workbooks.Add();  
                       sheet = wkbk.Sheets.Add() as Excel.Worksheet;  
                       sheet.Name = "Sample Worksheet";  
   
                       // Write a column of values.  
                       // In the For loop, both the row index and array index start at 1.  
                       // Therefore the value of 4 at array index 0 is not included.  
                       for (int i = 1; i < values.Length; i++)  
                       {  
                           sheet.Cells[i, 1] = values[i];  
                       }  
   
                       // Suppress any alerts and save the file. Create the directory   
                       // if it does not exist. Overwrite the file if it exists.  
                       excelApp.DisplayAlerts = false;  
                       string folderPath = Path.GetDirectoryName(filePath);  
                       if (!Directory.Exists(folderPath))  
                       {  
                           Directory.CreateDirectory(folderPath);  
                       }  
                       wkbk.SaveAs(filePath);  
               }  
               catch  
               {  
               }  
               finally  
               {  
                   sheet = null;  
                   wkbk = null;  
   
                   // Close Excel.  
                   excelApp.Quit();  
                   excelApp = null;  
               }  
           }  
       }  
   }  
   ```

8. 保存项目。

9. 按 Ctrl+F5 生成并运行项目。 验证是否已在示例代码中指定的位置创建 Excel 工作簿：C:\SampleFolder\SampleWorkbook.xls。

#### 将应用程序发布到安装有不同 Microsoft Office 版本的计算机

1. 在 Visual Studio 中打开本演练创建的项目。
2. 在“生成”菜单上，选择“发布 CreateExcelWorkbook”。 按照发布向导的步骤创建应用程序的可安装版本。 有关详细信息，请参阅[发布向导（Visual Studio 中的 Office 开发）](https://docs.microsoft.com/zh-cn/visualstudio/vsto/publish-wizard-office-development-in-visual-studio)。
3. 在安装有 .NET Framework 4 或更高版本和另一个 Excel 版本的计算机上，安装该应用程序。
4. 完成安装后，运行安装的程序。
5. 验证是否已在示例代码中指定的位置创建了 Excel 工作簿：C:\SampleFolder\SampleWorkbook.xls。

