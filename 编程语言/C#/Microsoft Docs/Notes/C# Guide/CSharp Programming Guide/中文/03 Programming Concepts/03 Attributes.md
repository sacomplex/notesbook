# [Programming Concepts](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/)

## [Attributes](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/attributes/)

使用特性，可以有效地将元数据或声明性信息与代码（程序集、类型、方法、属性等）相关联。 将特性与程序实体相关联后，可以在运行时使用*反射*这项技术查询特性。 有关详细信息，请参阅[反射 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/reflection)。

特性具有以下属性：

- 特性向程序添加元数据。 *元数据*是程序中定义的类型的相关信息。 所有 .NET 程序集都包含一组指定的元数据，用于描述程序集中定义的类型和类型成员。 可以添加自定义特性来指定所需的其他任何信息。 有关详细信息，请参阅[创建自定义特性 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/attributes/creating-custom-attributes)。
- 可以将一个或多个特性应用于整个程序集、模块或较小的程序元素（如类和属性）。
- 特性可以像方法和属性一样接受自变量。
- 程序可使用反射来检查自己的元数据或其他程序中的元数据。 有关详细信息，请参阅[使用反射访问特性 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/attributes/accessing-attributes-by-using-reflection)。

### 使用特性

可以将特性附加到大多数的声明中，尽管特定特性可能会限制可有效附加到的声明的类型。 在 C# 中，通过用方括号 ([]) 将特性名称括起来，并置于应用该特性的实体的声明上方以指定特性。

在此示例中，[SerializableAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.serializableattribute) 特性用于将具体特征应用于类：

```csharp
[Serializable]
public class SampleClass
{
    // Objects of this type can be serialized.
}
```

下方示例声明了一个具有特性 [DllImportAttribute](https://msdn.microsoft.com/library/system.runtime.interopservices.dllimportattribute(v=vs.110).aspx) 的方法：

```csharp
[System.Runtime.InteropServices.DllImport("user32.dll")]
extern static void SampleMethod();
```

如下方示例所示，可以将多个特性附加到声明中：

```csharp
using System.Runtime.InteropServices;
```

```csharp
void MethodA([In][Out] ref double x) { }
void MethodB([Out][In] ref double x) { }
void MethodC([In, Out] ref double x) { }
```

对于给定实体，一些特性可以指定多次。 [ConditionalAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.diagnostics.conditionalattribute) 便属于此类多用途特性：

```csharp
[Conditional("DEBUG"), Conditional("TEST1")]
void TraceMethod()
{
    // ...
}
```

> 按照约定，所有特性名称均以“Attribute”一词结尾，以便与 .NET 库中的其他项区分开来。 不过，在代码中使用特性时，无需指定特性后缀。 例如，`[DllImport]` 等同于 `[DllImportAttribute]`，但 `DllImportAttribute`是此特性在 .NET Framework 类库中的实际名称。

#### 特性参数

许多属性都有参数，可以是位置参数、未命名参数或已命名参数。 必须以特定顺序指定任何位置参数，且不能省略。 已命名参数是可选参数，可以通过任何顺序指定。 首先指定的是位置参数。 例如，下面这三个特性是等同的：

```csharp
[DllImport("user32.dll")]
[DllImport("user32.dll", SetLastError=false, ExactSpelling=false)]
[DllImport("user32.dll", ExactSpelling=false, SetLastError=false)]
```

第一个参数（DLL 名称）是位置参数，始终第一个出现；其他是已命名参数。 在此示例中，两个已命名参数的默认值均为 false，因此可以省略。 位置参数与特性构造函数的参数相对应。 已命名或可选参数与该特性的属性或字段相对应。 若要了解默认参数值，请参阅各个特性文档。

#### 特性目标

特性的*目标*是指应用特性的实体。 例如，特性可应用于类、特定方法或整个程序集。 默认情况下，特性应用于它后面紧接着的元素。 不过，还可以进行显式标识。例如，可以标识为将特性应用于方法，还是应用于其参数或返回值。

若要显式标识特性目标，请使用以下语法：

```csharp
[target : attribute-list]
```

下表列出了可能的 `target` 值。

| 目标值     | 适用对象                                    |
| ---------- | ------------------------------------------- |
| `assembly` | 整个程序集                                  |
| `module`   | 当前程序集模块                              |
| `field`    | 类或结构中的字段                            |
| `event`    | 事件                                        |
| `method`   | 方法或 `get` 和 `set` 属性访问器            |
| `param`    | 方法参数或 `set` 属性访问器参数             |
| `property` | Property                                    |
| `return`   | 方法、属性索引器或 `get` 属性访问器的返回值 |
| `type`     | 结构、类、接口、枚举或委托                  |

指定 `field` 目标值，将特性应用到为[自动实现的属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/properties)创建的支持字段。

下面的示例展示了如何将特性应用于程序集和模块。 有关详细信息，请参阅[通用特性 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/attributes/common-attributes)。

```csharp
using System;
using System.Reflection;
[assembly: AssemblyTitleAttribute("Production assembly 4")]
[module: CLSCompliant(true)]
```

以下示例演示如何将特性应用于 C# 中的方法、方法参数和方法返回值。

```csharp
// default: applies to method
[ValidatedContract]
int Method1() { return 0; }

// applies to method
[method: ValidatedContract]
int Method2() { return 0; }

// applies to return value
[return: ValidatedContract]
int Method3() { return 0; }
```

> 无论在哪个目标上将 `ValidatedContract` 定义为有效，都必须指定 `return` 目标，即使 `ValidatedContract`定义为仅应用于返回值也是如此。 换言之，编译器不会使用 `AttributeUsage` 信息来解析不明确的特性目标。有关详细信息，请参阅 [AttributeUsage (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/attributes/attributeusage)。

### 特性的常见用途

下面列出了代码中特性的一些常见用途：

- 在 Web 服务中使用 `WebMethod` 特性标记方法，以指明方法应可通过 SOAP 协议进行调用。 有关更多信息，请参见[WebMethodAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.web.services.webmethodattribute)。
- 描述在与本机代码互操作时如何封送方法参数。 有关更多信息，请参见[MarshalAsAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.interopservices.marshalasattribute)。
- 描述类、方法和接口的 COM 属性。
- 使用 [DllImportAttribute](https://msdn.microsoft.com/library/system.runtime.interopservices.dllimportattribute(v=vs.110).aspx) 类调用非托管代码。
- 从标题、版本、说明或商标方面描述程序集。
- 描述要序列化并暂留类的哪些成员。
- 描述如何为了执行 XML 序列化在类成员和 XML 节点之间进行映射。
- 描述的方法的安全要求。
- 指定用于强制实施安全规范的特征。
- 通过实时 (JIT) 编译器控制优化，这样代码就一直都易于调试。
- 获取方法调用方的相关信息。

### [Creating Custom Attributes](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/attributes/creating-custom-attributes)

可通过定义特性类创建自己的自定义特性，特性类是直接或间接派生自 [Attribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.attribute) 的类，可快速轻松地识别元数据中的特性定义。 假设希望使用编写类型的程序员的姓名来标记该类型。 可能需要定义一个自定义 `Author` 特性类：

```csharp
[System.AttributeUsage(System.AttributeTargets.Class |  
                       System.AttributeTargets.Struct)  
]  
public class Author : System.Attribute  
{  
    private string name;  
    public double version;  
  
    public Author(string name)  
    {  
        this.name = name;  
        version = 1.0;  
    }  
}  
```

类名是该特性的名称，即 `Author`。 由于该类派生自 `System.Attribute`，因此它是一个自定义特性类。 构造函数的参数是自定义特性的位置参数。 在此示例中，`name` 是位置参数。 所有公共读写字段或属性都是命名参数。 在本例中，`version` 是唯一的命名参数。 请注意，使用 `AttributeUsage` 特性可使 `Author` 特性仅对类和 `struct`声明有效。

可按如下方式使用这一新特性：

```csharp
[Author("P. Ackerman", version = 1.1)]  
class SampleClass  
{  
    // P. Ackerman's code goes here...  
}  
```

`AttributeUsage` 有一个命名参数 `AllowMultiple`，通过此命名参数可一次或多次使用自定义特性。 下面的代码示例创建了一个多用特性。

```csharp
[System.AttributeUsage(System.AttributeTargets.Class |  
                       System.AttributeTargets.Struct,  
                       AllowMultiple = true)  // multiuse attribute  
]  
public class Author : System.Attribute  
```

在下面的代码示例中，某个类应用了同一类型的多个特性。

```csharp
[Author("P. Ackerman", version = 1.1)]  
[Author("R. Koch", version = 1.2)]  
class SampleClass  
{  
    // P. Ackerman's code goes here...  
    // R. Koch's code goes here...  
}  
```

#### [AttributeUsage](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/attributes/attributeusage)

确定如何使用自定义特性类。 [AttributeUsageAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.attributeusageattribute) 是应用到自定义特性定义的特性。 `AttributeUsage` 特性帮助控制：

- 可能应用到的具体程序元素特性。除非使用限制，否则特性可能应用到以下任意程序元素：
  - 程序集
  - name
  - Field — 字段
  - Event — 事件
  - 方法
  - param
  - 属性
  - return
  - 类型
- 某特性是否可多次应用于单个程序元素。
- 特性是否由派生类继承。

显式应用时，默认设置如以下示例所示：

```csharp
[System.AttributeUsage(System.AttributeTargets.All,
                   AllowMultiple = false,
                   Inherited = true)]
class NewAttribute : System.Attribute { }
```

在此示例中，`NewAttribute` 类可应用于任何受支持的程序元素。 但是它对每个实体仅能应用一次。 特性应用于基类时，它由派生类继承。

[AllowMultiple](https://docs.microsoft.com/zh-cn/dotnet/api/system.attributeusageattribute.allowmultiple#System_AttributeUsageAttribute_AllowMultiple) 和 [Inherited](https://docs.microsoft.com/zh-cn/dotnet/api/system.attributeusageattribute.inherited#System_AttributeUsageAttribute_Inherited) 参数是可选的，因此以下代码具有相同效果：

```csharp
[System.AttributeUsage(System.AttributeTargets.All)]
class NewAttribute : System.Attribute { }
```

第一个 [AttributeUsageAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.attributeusageattribute) 参数必须是 [AttributeTargets](https://docs.microsoft.com/zh-cn/dotnet/api/system.attributetargets) 枚举的一个或多个元素。 可将多个目标类型与 OR 运算符链接在一起，如下例所示：

```csharp
[AttributeUsage(AttributeTargets.Property | AttributeTargets.Field)]
class NewPropertyOrFieldAttribute : Attribute { }
```

从 C# 7.3 开始，特性可应用于自动实现的属性的属性或支持字段。 特性应用于属性，除非在特性上指定 `field`说明符。 都在以下示例中进行了演示：

```csharp
class MyClass
{
    // Attribute attached to property:
    [NewPropertyOrField]
    public string Name { get; set; }

    // Attribute attached to backing field:
    [field:NewPropertyOrField]
    public string Description { get; set; }
}
```

如果 [AllowMultiple](https://docs.microsoft.com/zh-cn/dotnet/api/system.attributeusageattribute.allowmultiple#System_AttributeUsageAttribute_AllowMultiple) 参数为 `true`，那么结果特性可多次应用于单个实体，如以下示例所示：

```csharp
[AttributeUsage(AttributeTargets.Class, AllowMultiple = true)]
class MultiUse : Attribute { }

[MultiUse]
[MultiUse]
class Class1 { }

[MultiUse, MultiUse]
class Class2 { }
```

在本例中，`MultiUseAttribute` 可重复应用，因为 `AllowMultiple` 设置为 `true`。 所显示的两种用于应用多个特性的格式均有效。

如果 [Inherited](https://docs.microsoft.com/zh-cn/dotnet/api/system.attributeusageattribute.inherited#System_AttributeUsageAttribute_Inherited) 为 `false`，那么该特性不是由特性类派生的类继承。 例如:

```csharp
[AttributeUsage(AttributeTargets.Class, Inherited = false)]
class NonInheritedAttribute : Attribute { }

[NonInherited]
class BClass { }

class DClass : BClass { }
```

在本例中，`NonInheritedAttribute` 不会通过继承应用于 `DClass`。

##### 备注

`AttributeUsage` 特性是单次使用的特性 -- 它无法应用于同一个类超过一次。 `AttributeUsage` 是 [AttributeUsageAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.attributeusageattribute) 的别名。

有关详细信息，请参阅[使用反射访问特性 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/attributes/accessing-attributes-by-using-reflection)。

##### 示例

以下示例演示 [Inherited](https://docs.microsoft.com/zh-cn/dotnet/api/system.attributeusageattribute.inherited#System_AttributeUsageAttribute_Inherited) 和 [AllowMultiple](https://docs.microsoft.com/zh-cn/dotnet/api/system.attributeusageattribute.allowmultiple#System_AttributeUsageAttribute_AllowMultiple) 参数对 [AttributeUsageAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.attributeusageattribute) 特性的影响，以及如何枚举应用于类的自定义特性。

```csharp
using System;

// Create some custom attributes:
[AttributeUsage(AttributeTargets.Class, Inherited = false)]
class FirstAttribute : Attribute { }

[AttributeUsage(AttributeTargets.Class)]
class SecondAttribute : Attribute { }

[AttributeUsage(AttributeTargets.Class, AllowMultiple = true)]
class ThirdAttribute : Attribute { }

// Apply custom attributes to classes:
[First, Second]
class BaseClass { }

[Third, Third]
class DerivedClass : BaseClass { }

public class TestAttributeUsage
{
    static void Main()
    {
        BaseClass b = new BaseClass();
        DerivedClass d = new DerivedClass();

        // Display custom attributes for each class.
        Console.WriteLine("Attributes on Base Class:");
        object[] attrs = b.GetType().GetCustomAttributes(true);
        foreach (Attribute attr in attrs)
        {
            Console.WriteLine(attr);
        }

        Console.WriteLine("Attributes on Derived Class:");
        attrs = d.GetType().GetCustomAttributes(true);
        foreach (Attribute attr in attrs)
        {
            Console.WriteLine(attr);
        }
    }
}
```

##### 示例输出

```text
Attributes on Base Class:
FirstAttribute
SecondAttribute
Attributes on Derived Class:
ThirdAttribute
ThirdAttribute
SecondAttribute
```

### [Accessing Attributes by Using Reflection](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/attributes/accessing-attributes-by-using-reflection)

你可以定义自定义特性并将其放入源代码中这一事实，在没有检索该信息并对其进行操作的方法的情况下将没有任何价值。 通过使用反射，可以检索通过自定义特性定义的信息。 主要方法是 `GetCustomAttributes`，它返回对象数组，这些对象在运行时等效于源代码特性。 此方法有多个重载版本。 有关更多信息，请参见[Attribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.attribute)。

特性规范，例如：

```csharp
[Author("P. Ackerman", version = 1.1)]  
class SampleClass  
```

在概念上等效于此：

```csharp
Author anonymousAuthorObject = new Author("P. Ackerman");  
anonymousAuthorObject.version = 1.1;  
```

但是，在为特性查询 `SampleClass` 之前，代码将不会执行。 对 `SampleClass` 调用 `GetCustomAttributes` 会导致按上述方式构造并初始化一个 `Author` 对象。 如果该类具有其他特性，则将以类似方式构造其他特性对象。 然后 `GetCustomAttributes` 会以数组形式返回 `Author` 对象和任何其他特性对象。 之后你便可以循环访问此数组，根据每个数组元素的类型确定所应用的特性，并从特性对象中提取信息。

##### 示例

此处是一个完整的示例。 定义自定义特性、将其应用于多个实体，并通过反射对其进行检索。

```csharp
// Multiuse attribute.  
[System.AttributeUsage(System.AttributeTargets.Class |  
                       System.AttributeTargets.Struct,  
                       AllowMultiple = true)  // Multiuse attribute.  
]  
public class Author : System.Attribute  
{  
    string name;  
    public double version;  
  
    public Author(string name)  
    {  
        this.name = name;  
  
        // Default value.  
        version = 1.0;  
    }  
  
    public string GetName()  
    {  
        return name;  
    }  
}  
  
// Class with the Author attribute.  
[Author("P. Ackerman")]  
public class FirstClass  
{  
    // ...  
}  
  
// Class without the Author attribute.  
public class SecondClass  
{  
    // ...  
}  
  
// Class with multiple Author attributes.  
[Author("P. Ackerman"), Author("R. Koch", version = 2.0)]  
public class ThirdClass  
{  
    // ...  
}  
  
class TestAuthorAttribute  
{  
    static void Test()  
    {  
        PrintAuthorInfo(typeof(FirstClass));  
        PrintAuthorInfo(typeof(SecondClass));  
        PrintAuthorInfo(typeof(ThirdClass));  
    }  
  
    private static void PrintAuthorInfo(System.Type t)  
    {  
        System.Console.WriteLine("Author information for {0}", t);  
  
        // Using reflection.  
        System.Attribute[] attrs = System.Attribute.GetCustomAttributes(t);  // Reflection.  
  
        // Displaying output.  
        foreach (System.Attribute attr in attrs)  
        {  
            if (attr is Author)  
            {  
                Author a = (Author)attr;  
                System.Console.WriteLine("   {0}, version {1:f}", a.GetName(), a.version);  
            }  
        }  
    }  
}  
/* Output:  
    Author information for FirstClass  
       P. Ackerman, version 1.00  
    Author information for SecondClass  
    Author information for ThirdClass  
       R. Koch, version 2.00  
       P. Ackerman, version 1.00  
*/  
```

### [How to: Create a C-C++ Union by Using Attributes](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/attributes/how-to-create-a-c-cpp-union-by-using-attributes)

通过使用特性，可自定义结构在内存中的布局方式。 例如，可使用 `StructLayout(LayoutKind.Explicit)` 和 `FieldOffset` 特性在 C/C++ 中创建所谓的联合。

#### 示例

在此代码段中，`TestUnion` 的所有字段均从内存中的同一位置开始。

```csharp
// Add a using directive for System.Runtime.InteropServices.  
  
       [System.Runtime.InteropServices.StructLayout(LayoutKind.Explicit)]  
       struct TestUnion  
       {  
           [System.Runtime.InteropServices.FieldOffset(0)]  
           public int i;  
  
           [System.Runtime.InteropServices.FieldOffset(0)]  
           public double d;  
  
           [System.Runtime.InteropServices.FieldOffset(0)]  
           public char c;  
  
           [System.Runtime.InteropServices.FieldOffset(0)]  
           public byte b;  
       }  
```

#### 示例

下面是另一个示例，其中的字段从不同的显式设置位置开始。

```csharp
// Add a using directive for System.Runtime.InteropServices.  
  
       [System.Runtime.InteropServices.StructLayout(LayoutKind.Explicit)]  
       struct TestExplicit  
       {  
           [System.Runtime.InteropServices.FieldOffset(0)]  
           public long lg;  
  
           [System.Runtime.InteropServices.FieldOffset(0)]  
           public int i1;  
  
           [System.Runtime.InteropServices.FieldOffset(4)]  
           public int i2;  
  
           [System.Runtime.InteropServices.FieldOffset(8)]  
           public double d;  
  
           [System.Runtime.InteropServices.FieldOffset(12)]  
           public char c;  
  
           [System.Runtime.InteropServices.FieldOffset(14)]  
           public byte b;  
       }  
```

两个整数字段 `i1` 和 `i2` 共享与 `lg` 相同的内存位置。 使用平台调用时，这种对结构布局的控制很有用。

### [Common Attributes](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/attributes/common-attributes)

本主题介绍在 C# 程序中最常用的属性。

- [全局特性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/attributes/common-attributes#Global)
- [Obsolete 特性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/attributes/common-attributes#Obsolete)
- [Conditional 特性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/attributes/common-attributes#Conditional)
- [调用方信息特性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/attributes/common-attributes#CallerInfo)

#### 全局特性

大多数特性应用于特定语言元素，如类或方法；但是，一些特性是全局特性 - 它们应用于整个程序集或模块。 例如，[AssemblyVersionAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.assemblyversionattribute) 属性可用于将版本信息嵌入程序集，如下所示：

```csharp
[assembly: AssemblyVersion("1.0.0.0")]  
```

全局特性出现在源代码中任何顶级 `using` 指令之后和任何类型、模块或命名空间声明之前。 全局特性可以出现在多个源文件中，但必须在单个编译过程中编译这些文件。 在 C# 项目中，全局特性放在 AssemblyInfo.cs 文件中。

程序集特性是提供程序集相关信息的值。 它们分为以下几类：

- 程序集标识特性
- 信息性特性
- 程序集清单特性

##### 程序集标识特性。

三个特性（与强名称（如果适用））组合起来可以确定程序集的标识：名称、版本和区域性。 这些特性构成程序集的全名，在代码中引用程序集时必需使用。 可使用特性设置程序集的版本和区域性。 但是，创建程序集时，根据包含程序集清单的文件，由编译器、[程序集信息对话框](https://docs.microsoft.com/zh-cn/visualstudio/ide/reference/assembly-information-dialog-box)中的 Visual Studio IDE 或程序集链接器 (Al.exe) 设置名称值。 [AssemblyFlagsAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.assemblyflagsattribute) 属性指定程序集的多个副本是否可以共存。

下表显示标识特性。

| 特性                                                         | 目标                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [AssemblyName](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.assemblyname) | 详细描述程序集的标识。                                       |
| [AssemblyVersionAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.assemblyversionattribute) | 指定程序集的版本。                                           |
| [AssemblyCultureAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.assemblycultureattribute) | 指定程序集支持的区域性。                                     |
| [AssemblyFlagsAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.assemblyflagsattribute) | 指定程序集是否支持在同一计算机上、同一进程中或同一应用程序域中并行执行。 |

##### 信息性特性

信息性特性可用于提供程序集的其他公司或产品信息。 下表显示 [System.Reflection](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection) 命名空间中定义的信息性属性。

| 特性                                                         | 目标                                            |
| ------------------------------------------------------------ | ----------------------------------------------- |
| [AssemblyProductAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.assemblyproductattribute) | 定义为程序集清单指定产品名称的自定义属性。      |
| [AssemblyTrademarkAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.assemblytrademarkattribute) | 定义为程序集清单指定商标的自定义属性。          |
| [AssemblyInformationalVersionAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.assemblyinformationalversionattribute) | 定义为程序集清单指定信息性版本的自定义属性。    |
| [AssemblyCompanyAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.assemblycompanyattribute) | 定义为程序集清单指定公司名称的自定义属性。      |
| [AssemblyCopyrightAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.assemblycopyrightattribute) | 定义为程序集清单指定版权的自定义属性。          |
| [AssemblyFileVersionAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.assemblyfileversionattribute) | 指示编译器使用 Win32 文件版本资源的特定版本号。 |
| [CLSCompliantAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.clscompliantattribute) | 指示程序集是否符合公共语言规范 (CLS)。          |

##### 程序集清单特性

程序集清单特性可用于提供程序集清单中的信息。 这些信息包括标题、说明、默认别名和配置。 下表显示 [System.Reflection](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection) 命名空间中定义的程序集清单属性。

| 特性                                                         | 目标                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [AssemblyTitleAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.assemblytitleattribute) | 定义为程序集清单指定程序集标题的自定义属性。                 |
| [AssemblyDescriptionAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.assemblydescriptionattribute) | 定义为程序集清单指定程序集说明的自定义属性。                 |
| [AssemblyConfigurationAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.assemblyconfigurationattribute) | 定义为程序集清单指定程序集配置（如零售或调试）的自定义属性。 |
| [AssemblyDefaultAliasAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.assemblydefaultaliasattribute) | 定义程序集清单的友好默认别名                                 |

#### Obsolete 特性

`Obsolete` 特性将程序实体标记为不再推荐使用。 每次使用标记为过时的实体后，将生成警告或错误，具体取决于该特性的配置方式。 例如:

```csharp
[System.Obsolete("use class B")]  
class A  
{  
    public void Method() { }  
}  
class B  
{  
    [System.Obsolete("use NewMethod", true)]  
    public void OldMethod() { }  
    public void NewMethod() { }  
}  
```

在此示例中，`Obsolete` 特性应用于类 `A` 和方法 `B.OldMethod`。 因为应用于 `B.OldMethod` 的特性构造函数的第二个参数设置为 `true`，所以此方法将导致编译器错误，而使用类 `A` 只会生成警告。 但是，调用 `B.NewMethod`不会生成任何警告或错误。

作为特性构造函数的第一个参数提供的字符串将作为警告或错误的一部分显示。 例如，将其与先前的定义一起使用时，以下代码会生成两个警告和一个错误：

```csharp
// Generates 2 warnings:  
// A a = new A();  
  
// Generate no errors or warnings:  
B b = new B();  
b.NewMethod();  
  
// Generates an error, terminating compilation:  
// b.OldMethod();  
```

将生成类 `A` 的两个警告：一个用于声明类引用，另一个用于类构造函数。

`Obsolete` 特性可以在不带参数的情况下使用，但建议包括说明项目过时的原因以及改为使用哪个项目。

`Obsolete` 特性是一次性特性，可以应用于任何允许特性的实体。 `Obsolete` 是 [ObsoleteAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.obsoleteattribute) 的别名。

#### Conditional 特性

`Conditional` 特性使得方法执行依赖于预处理标识符。 `Conditional` 属性是 [ConditionalAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.diagnostics.conditionalattribute) 的别名，可以应用于方法或特性类。

在此示例中，`Conditional` 应用于启用或禁用显示特定于程序的诊断信息的方法：

```csharp
#define TRACE_ON  
using System;  
using System.Diagnostics;  
  
public class Trace  
{  
    [Conditional("TRACE_ON")]  
    public static void Msg(string msg)  
    {  
        Console.WriteLine(msg);  
    }  
}  
  
public class ProgramClass  
{  
    static void Main()  
    {  
        Trace.Msg("Now in Main...");  
        Console.WriteLine("Done.");  
    }  
}  
```

如果未定义 `TRACE_ON` 标识符，则不会显示任何跟踪输出。

`Conditional` 特性通常与 `DEBUG` 标识符一起使用，以启用调试生成（而非发布生成）中的跟踪和日志记录功能，如下所示：

```csharp
[Conditional("DEBUG")]  
static void DebugMethod()  
{  
}  
```

当调用标记为 conditional 的方法时，指定的预处理符号是否存在将决定包括还是省略该调用。 如果定义了符号，则将包括调用；否则，将忽略该调用。 使用 `Conditional` 是将方法封闭在 `#if…#endif` 块内的更简洁且较不容易出错的替代方法，如下所示：

```csharp
#if DEBUG  
    void ConditionalMethod()  
    {  
    }  
#endif  
```

条件方法必须是类或结构声明中的方法，而且必须没有返回值。

##### 使用多个标识符

如果某个方法具有多个 `Conditional` 特性，则如果至少定义了其中一个条件符号（换言之，通过使用 OR 运算符将这些符号逻辑链接在一起），则包含对该方法的调用。 在此示例中，存在 `A` 或 `B` 将导致方法调用：

```csharp
[Conditional("A"), Conditional("B")]  
static void DoIfAorB()  
{  
    // ...  
}  
```

若要使用 AND 运算符实现逻辑链接符号的效果，可以定义串行条件方法。 例如，仅当同时定义了 `A` 和 `B` 时才会执行下面的第二个方法：

```csharp
[Conditional("A")]  
static void DoIfA()  
{  
    DoIfAandB();  
}  
  
[Conditional("B")]  
static void DoIfAandB()  
{  
    // Code to execute when both A and B are defined...  
}  
```

##### 将 Conditional 用于特性类

`Conditional` 特性还可应用于特性类定义。 在本示例中，如果定义了 DEBUG，则自定义属性 `Documentation` 将仅向元数据添加信息。

```csharp
[Conditional("DEBUG")]  
public class Documentation : System.Attribute  
{  
    string text;  
  
    public Documentation(string text)  
    {  
        this.text = text;  
    }  
}  
  
class SampleClass  
{  
    // This attribute will only be included if DEBUG is defined.  
    [Documentation("This method displays an integer.")]  
    static void DoWork(int i)  
    {  
        System.Console.WriteLine(i.ToString());  
    }  
}  
```

#### 调用方信息特性

通过使用调用方信息特性，可获取有关方法的调用方的信息。 可以获取源代码的文件路径、源代码中的行号和调用方的成员名称。

若要获取成员调用方信息，可以使用应用于可选参数的特性。 每个可选参数指定一个默认值。 下表列出在 [System.Runtime.CompilerServices](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.compilerservices) 命名空间中定义的调用方信息特性：

| 特性                                                         | 说明                                                         | 类型      |
| ------------------------------------------------------------ | ------------------------------------------------------------ | --------- |
| [CallerFilePathAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.compilerservices.callerfilepathattribute) | 包含调用方的源文件的完整路径。 这是编译时的路径。            | `String`  |
| [CallerLineNumberAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.compilerservices.callerlinenumberattribute) | 源文件中调用方法的行号。                                     | `Integer` |
| [CallerMemberNameAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.compilerservices.callermembernameattribute) | 调用方的方法名称或属性名称。 有关详细信息，请参阅[调用方信息 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/caller-information)。 | `String`  |

有关调用方信息特性的详细信息，请参阅[调用方信息 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/caller-information)。