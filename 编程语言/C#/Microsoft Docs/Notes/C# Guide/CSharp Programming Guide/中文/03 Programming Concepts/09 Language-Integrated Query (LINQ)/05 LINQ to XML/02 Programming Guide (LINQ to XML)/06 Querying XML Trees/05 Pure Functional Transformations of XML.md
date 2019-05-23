# [Pure Functional Transformations of XML](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/purefunctionaltransformationsofxml)

本节提供 XML 的函数转换教程。 它包括使用函数转换所必须理解的主要概念和语言构造的说明以及使用函数转换来操作 XML 文档的示例。 虽然本教程提供 LINQ to XML 代码示例，但所有基础概念也适用于其他 LINQ 技术。

[教程：：操作 WordprocessingML 文档中的内容 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/tutorial-manipulating-content-in-a-wordprocessingml-document) 教程提供一系列示例，每个示例都是在前一个示例的基础上生成的。 这些示例演示用于操作 XML 的纯函数转换方法。

本教程假定你了解 C# 的使用知识。 本教程不提供语言构造的详细语义，但提供到相应语言文档的链接。

还假定您已了解基本计算机科学概念和 XML（包括 XML 命名空间）的使用知识。

## 本节内容

| 主题                                                         | 说明                         |
| ------------------------------------------------------------ | ---------------------------- |
| [纯函数转换简介 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/introduction-to-pure-functional-transformations) | 说明函数转换并定义相关术语。 |
| [教程：将查询链接在一起 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/tutorial-chaining-queries-together) | 详细说明迟缓计算和延迟执行。 |
| [教程：操作 WordprocessingML 文档中的内容 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/tutorial-manipulating-content-in-a-wordprocessingml-document) | 演示函数转换的教程。         |

## [Introduction to Pure Functional Transformations](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/introductiontopurefunctionaltransformations)

本节介绍函数转换，包括基本概念和支持的语言构造。 本节对面向对象的编程方法与函数转换编程方法进行了对比，并针对如何转换到后者提供了一些建议。 尽管可以在很多编程方案中都使用函数转换，但此处使用 XML 转换作为具体示例。

### 本节内容

| 主题                                                         | 说明                                             |
| ------------------------------------------------------------ | ------------------------------------------------ |
| [概念和术语（功能转换）(C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/concepts-and-terminology-functional-transformation) | 介绍纯函数转换的概念和术语。                     |
| [函数编程与命令式编程 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/functional-programming-vs-imperative-programming) | 将函数编程与更传统的命令性（过程）编程进行对比。 |
| [重构为纯函数 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/refactoring-into-pure-functions) | 介绍纯函数，并提供了纯函数和非纯函数的示例。     |
| [功能转换的适用性 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/applicability-of-functional-transformation) | 描述函数转换的典型应用场景。                     |
| [XML 的功能转换 (Visual Basic)](https://docs.microsoft.com/zh-cn/dotnet/visual-basic/programming-guide/concepts/linq/functional-transformation-of-xml) | 描述在转换 XML 树的上下文中的函数转换。          |

### [Concepts and Terminology (Functional Transformation)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/conceptsandterminologyfunctionaltransformation)

本主题介绍纯函数转换的概念和术语。 与更加传统的命令性编程方式相比，用来转换数据的函数转换方法所生成的代码往往编程速度更快、含义更明确、更易于调试和维护。

请注意，本节中的主题并不是要透彻解释函数编程。 这些主题只是介绍函数编程的一些功能，这些功能降低了将 XML 从一种形状转换为另一种形状的难度。

**什么是纯函数转换？**

在纯函数转换中，称为“纯函数”的一组函数定义如何将一组结构化数据从其原始格式转换为另一种格式。 “纯”表示这些函数是可组合的，这要求这些函数具有以下特点：

- 独立，这样函数就可以自由排序和重新排列，而不会与程序的其他部分相互牵连和依赖。 纯转换不了解其环境，对环境也没有任何影响。 也就是说，用在转换中的函数没有负作用。
- 无状态，因而对相同输入执行相同的函数或特定的一组函数将始终产生相同的输出。 纯转换对于先前对它的使用没有记忆。

>  在本教程的其余部分，术语“纯函数”用于概括表示编程方法，而不是具体的语言功能。
>  请注意，纯函数在 C# 中必须实现为方法。
>  此外，不要将纯函数与 C++ 中的纯虚方法混淆。 后者表示包含类是抽象的，并且不提供方法体。

**函数编程**

函数编程是一种编程方法，直接支持纯函数转换。

学术团体对诸如 ML、Scheme、Haskell 和 F# 等通用函数编程语言一直抱有浓厚的兴趣。 虽然 C# 一直可以用来编写纯函数转换，然而实际操作的困难使之对大多数程序员来说不具吸引力。 但是在最新版本的 C# 中，像 Lambda 表达式和类型推理这样的新语言构造大大降低了函数编程的难度，也提高了函数编程的效率。

有关函数编程的详细信息，请参阅[函数编程与命令式编程 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/functional-programming-vs-imperative-programming)。

**特定于域的 FP 语言**

虽然通用函数编程语言并未得到广泛采用，但特定于域的函数编程语言却得到了较为成功的应用。 例如，级联样式表 (CSS) 用于确定许多网页的外观，可扩展样式表转换语言 (XSLT) 样式表广泛应用于 XML 数据操作中。 有关 XSLT 的详细信息，请参阅 [XSLT 转换](https://docs.microsoft.com/zh-cn/dotnet/standard/data/xml/xslt-transformations)。

**术语**

下面定义了一些与函数转换相关的术语。

高阶（第一类）函数

- 可作为编程对象的一种函数。 例如，高阶函数可以传递到其他函数或从其他函数返回。 在 C# 中，委托和 Lambda 表达式是支持高阶函数的语言功能。 若要编写高阶函数，需要声明一个或多个自变量来接受委托，而在调用该函数时通常使用 lambda 表达式。 许多标准查询运算符都属于高阶函数。

> 有关详细信息，请参阅[标准查询运算符概述 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/standard-query-operators-overview)。

lambda 表达式

- 实质上是一个匿名的内联函数，可用在任何需要委托类型的地方。 这是对 lambda 表达式的一个简化的定义，但足以满足本教程的需要。

> 有关 Lambda 表达式的详细信息，请参阅 [Lambda 表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/lambda-expressions)。

集合

- 结构化的一组数据，通常具有统一的类型。 若要与 LINQ 兼容，集合必须实现 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable) 接口或 [IQueryable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.iqueryable) 接口（或它们对应的泛型接口 [IEnumerator](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerator-1) 或 [IQueryable](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.iqueryable-1) 之一）。

元组（匿名类型）

- 一个数学概念，元组是一个有限的对象序列，每个对象具有特定的类型。 元组也称为有序列表。 匿名类型是此概念的语言实现，支持在声明未命名类类型的同时实例化该类型的对象。

> 有关详细信息，请参阅[匿名类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/anonymous-types)。

类型推理（隐式确定类型）

- 在没有显式类型声明的情况下编译器确定变量类型的能力。

> 有关详细信息，请参阅[隐式类型本地变量](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/implicitly-typed-local-variables)。

延迟执行和迟缓计算

- 延迟表达式的计算，直到实际需要它的求解值。 集合中支持延迟执行。

> 有关详细信息，请参阅 [LINQ 查询简介 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/introduction-to-linq-queries) 和 [LINQ to XML 中的延迟执行和迟缓计算 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/deferred-execution-and-lazy-evaluation-in-linq-to-xml)。

本节各处的代码示例中将使用这些语言功能。

### [Functional Programming vs. Imperative Programming](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/functionalprogrammingvsimperativeprogramming)

本主题对函数编程和更传统的命令性（过程性）编程进行比较。

**函数编程与命令式编程**

为支持使用纯函数方法解决问题，特此创建了函数编程范例。 函数编程是一种声明性编程形式。 相比之下，大多数主流语言，包括面向对象的编程 (OOP) 语言（如 C#、Visual Basic、C++ 和 Java）主要都是为支持命令性（过程性）编程而设计的。

使用命令性方法时，开发人员编写的代码应严格细致地说明计算机为完成目标而必须执行的步骤。 这有时称为算法编程。 相比之下，函数方法涉及将问题编成一组要执行的函数。 您要仔细地定义每个函数的输入值和每个函数的返回值。 下表说明了这两种方法之间的一些总体差别。

| 特征         | 命令性方法                               | 函数方法                         |
| ------------ | ---------------------------------------- | -------------------------------- |
| 程序员关注点 | 如何执行任务（算法）和如何跟踪状态更改。 | 需要哪些信息和需要进行什么转换。 |
| 状态更改     | 重要。                                   | 不存在。                         |
| 执行顺序     | 重要。                                   | 不太重要。                       |
| 主要流控制   | 循环、条件和函数（方法）调用。           | 函数调用，包括递归。             |
| 主要操作单元 | 结构或类的实例。                         | 作为第一类对象和数据集合的函。   |

虽然多数语言旨在支持特定编程范例，但许多通用语言具有很高的灵活性，能够支持多个范例。 例如，包含函数指针的多数语言都可用于可靠地支持函数编程。 此外，C# 包含显式语言扩展以支持函数编程，包括 lambda 表达式和类型推理。 LINQ 技术是一种声明性函数编程形式。

**使用 XSLT 的函数编程**

很多 XSLT 开发人员熟悉纯函数方法。 开发 XSLT 样式表的最有效方式是将每个模板视为一个独立的、可组合的转换。 执行顺序完全不重要。 XSLT 不允许副作用（但用于执行过程代码的转义机制除外，它可能引入可导致功能不纯的副作用）。 不过，虽然 XSLT 是一个有效的工具，但其某些特性并不是最佳的。 例如，在 XML 中表示编程构造会使代码相对繁琐，因此难于维护。 而且，流控制对递归的依赖性很强，因此会使代码的可读性较差。 有关 XSLT 的详细信息，请参阅 [XSLT 转换](https://docs.microsoft.com/zh-cn/dotnet/standard/data/xml/xslt-transformations)。

但 XSLT 在使用纯函数方法将 XML 从一种形状转换为另一种形状方面确有其自身的价值。 使用 LINQ to XML 的纯函数编程在许多方面与 XSLT 类似。 但 LINQ to XML 和 C# 中引入的编程构造允许你编写比 XSLT 更具可读性且更容易维护的纯函数转换。

**纯函数的优点**

以纯函数形式实现函数转换的主要原因是纯函数是可以组合的：即独立并且无状态。 这些特性可带来很多好处，包括以下各项：

- 可读性和可维护性更高。 这是因为每个函数都设计为在给定参数的情况下完成特定任务。 函数不依赖于任何外部状态。
- 更易于反复开发。 因为代码更容易重构，因此对设计的更改通常更容易实现。 例如，假设您编写了一个复杂的转换，但随后发现某些代码在转换中重复多次。 如果您通过纯方法重构，则可以随意调用纯方法而不必担心会有什么副作用。
- 更易于测试和调试。 由于纯函数更容易单独测试，因此您可以编写使用典型值、有效边缘情况和无效边缘情况调用纯函数的测试代码。

**针对 OOP 开发人员的转换**

在传统的面向对象编程 (OOP) 中，大多数开发人员都习惯于命令性/过程式编程。 若要切换到纯函数式开发，开发人员必须转变开发思路和方法。

为了解决问题，OOP 开发人员需要设计类层次结构，注意进行恰当的包装并按照类约定进行思考。 对象类型的行为和状态至为重要，并提供语言功能（如类、接口、继承和多态性）以解除这些问题。

相比之下，函数编程将计算机的操作问题处理为数据集合的纯函数转换计算。 函数编程可以避免使用状态和可变数据，并改为强调函数的应用。

但 C# 并不要求完全转变为函数编程，因为它同时支持命令性编程和函数编程方法。 开发人员可以选择哪种方法最适合特定方案。 实际上，程序通常组合使用这两种方法。

### [Refactoring Into Pure Functions](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/refactoringintopurefunctions)

纯函数转换的一个重要方面是学习如何使用纯函数重构代码。

> 函数编程中的常用术语是使用纯函数重构程序。 在 Visual Basic 和 C++ 中，这对应于使用相应语言的函数。但在 C# 中，函数称为方法。 出于本文论述的需要，在 C# 中以方法的形式实现了一个纯函数。

如本节前面所述，纯函数具有两个有用的特性：

- 它没有任何副作用。 函数不会更改函数以外的任何变量或任何类型的数据。
- 它具有一致性。 在提供同一组输入数据的情况下，它将始终返回相同的输出值。

转换为函数编程的一种方式是重构现有代码以消除不必要的副作用和外部依赖项。 这样，您可以创建现有代码的纯函数版本。

本主题讨论什么是纯函数，什么不是纯函数。 [教程：操作 WordprocessingML 文档中的内容 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/tutorial-manipulating-content-in-a-wordprocessingml-document) 教程演示如何操作 WordprocessingML 文档并包括两个有关如何使用纯函数进行重构的示例。

**消除副作用和外部依赖项**

下面的示例对比两个非纯函数和一个纯函数。

**可更改类成员的非纯函数**

在下面的代码中，`HyphenatedConcat` 函数不是纯函数，因为它修改了类中的 `aMember` 数据成员：

```csharp
public class Program  
{  
    private static string aMember = "StringOne";  
  
    public static void HyphenatedConcat(string appendStr)  
    {  
        aMember += '-' + appendStr;  
    }  
  
    public static void Main()  
    {  
        HyphenatedConcat("StringTwo");  
        Console.WriteLine(aMember);  
    }  
}  
```

此代码生成以下输出：

```
StringOne-StringTwo  
```

请注意，它与修改的数据是具有 `public` 还是 `private` 访问权限或者是 `static` 成员还是实例成员均无关。 纯函数不会更改函数以外的任何数据。

**可更改参数的非纯函数**

此外，此同一个函数的下面版本不是纯函数，因为它修改了其参数 `sb` 的内容。

```csharp
public class Program  
{  
    public static void HyphenatedConcat(StringBuilder sb, String appendStr)  
    {  
        sb.Append('-' + appendStr);  
    }  
  
    public static void Main()  
    {  
        StringBuilder sb1 = new StringBuilder("StringOne");  
        HyphenatedConcat(sb1, "StringTwo");  
        Console.WriteLine(sb1);  
    }  
}  
```

此版本的程序生成的输出与第一个版本相同，因为 `HyphenatedConcat` 函数已通过调用 [Append](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.stringbuilder.append) 成员函数而更改了其第一个参数的值（状态）。 请注意，即使 `HyphenatedConcat` 实际上使用了按值调用参数传递，也会发生此更改。

> 对于引用类型，按值传递参数会得到对所传递对象的引用的副本。 此副本与原始引用一样，仍与同一个实例数据关联（除非为引用变量分配新对象）。 函数修改参数不一定需要按引用调用。

**纯函数**

下面版本的程序演示如何将 `HyphenatedConcat` 函数作为纯函数实现。

```csharp
class Program  
{  
    public static string HyphenatedConcat(string s, string appendStr)  
    {  
        return (s + '-' + appendStr);  
    }  
  
    public static void Main(string[] args)  
    {  
        string s1 = "StringOne";  
        string s2 = HyphenatedConcat(s1, "StringTwo");  
        Console.WriteLine(s2);  
    }  
}  
```

此版本同样生成相同的输出行：`StringOne-StringTwo`。 请注意保留串联值，它存储在中间变量 `s2` 中。

一种非常实用的方法是编写本地不纯（即声明和修改本地变量）但在全局为纯的函数。 这些函数具有许多需要的可组合特性，但舍弃了一些较为繁复的函数编程语法，如在使用简单的循环即可完成同样操作时必须使用递归。

**标准查询运算符**

标准查询运算符的重要特性是它们以纯函数的形式实现。

有关详细信息，请参阅[标准查询运算符概述 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/standard-query-operators-overview)。

### [Applicability of Functional Transformation](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/applicabilityoffunctionaltransformation)

纯函数转换适用于多种情况。

函数转换方法最适合查询和操作结构化数据，因此它非常适合 LINQ 技术。 但函数转换比使用 LINQ 具有更广泛的适用性。 任何侧重于将数据从一种形式转换为另一种形式的进程都可以考虑作为函数转换的候选项。

此方法适用于乍看可能不是候选项的许多问题。 在独立或与 LINQ 一起使用时，应考虑对以下方面使用函数转换：

- 基于 XML 的文档。 使用任何 XML 方言的格式良好的数据均可以通过函数转换容易地操作。 有关详细信息，请参阅 [XML 的功能转换 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/functional-transformation-of-xml)。
- 其他结构化文件格式。 从 Windows.ini 文件到纯文本文档，多数文件都有适于本身进行分析和转换的结构。
- 数据流协议。 将数据编码为通信协议和从通信协议解码数据通常可以由简单的函数转换来表示。
- RDBMS 和 OODBMS 数据。 关系数据库和面向对象的数据库和 XML 一样，是广泛使用的结构化数据源。
- 数学、统计和科学解决方案。 这些字段适用于操作大型数据集，以帮助用户处理可视化、评估或实际解决重要问题。

如[重构为纯函数 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/refactoring-into-pure-functions) 中所述，使用纯函数是函数编程的一个示例。 除了直接好处外，使用纯函数还可对从函数转换角度考虑问题提供宝贵的经验。 这种方法也可能对程序和类设计产生重要影响。 当问题本身适于数据转换解决方案（如上所述）时更是如此。

虽然受函数转换透视影响的设计不在本教程的范围内，但在以进程为中心作为操作者和以对象为中心作为操作者之间，他们更倾向于前者，生成的解决方案倾向于以一系列大规模转换而不是单独的对象状态更改的形式实现。

此外请记住，C# 同时支持命令性方法和函数方法，因此应用程序的最佳设计可能需要合并使用这两个元素。

### [Functional Transformation of XML](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/functionaltransformationofxml)

本主题讨论用于修改 XML 文档的纯函数转换方法，并将该方法与过程方法进行比较。

**修改 XML 文档**

对 XML 程序员来说，最常见的任务之一就是将 XML 从一种形状转换为另一种形状。 XML 文档的形状就是文档的结构，包括下列内容：

- 文档所表达的层次结构。
- 元素和属性的名称。
- 元素和属性的数据类型。

通常，将 XML 从一种形状转换为另一种形状的最有效方法是纯函数转换方法。 在这种方法中，程序员的主要任务是创建一个转换，该转换将应用到整个 XML 文档（或应用到一个或多个严格定义的节点）。 可以说，函数转换最容易进行编码（如果程序员熟悉这种方法），生成的代码最容易维护，并且相比其他方法通常更加简洁。

**XML 函数转换技术**

Microsoft 提供了两种函数转换技术用于 XML 文档：XSLT 和 LINQ to XML。 在 [System.Xml.Xsl](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xsl) 托管命名空间和 MSXML 的本机 COM 实现中都支持 XSLT。 尽管 XSLT 是操作 XML 文档的可靠技术，但它要求专门领域的专业知识，即 XSLT 语言和支持它的 API。

LINQ to XML 提供了必要的工具，使用这些工具可以在 C# 或 Visual Basic 代码中以富于表现力而又强有力的方式编写纯函数转换。 例如，LINQ to XML 文档中的很多示例都使用纯函数方法。 此外，在[教程：操作 WordprocessingML 文档中的内容 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/tutorial-manipulating-content-in-a-wordprocessingml-document) 教程中，我们在函数方法中使用 LINQ to XML 操作 Microsoft Word 文档中的信息。

有关 LINQ to XML 与其他 Microsoft XML 技术的更全面比较，请参见 [LINQ to XML 和其他 XML 技术](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/linq-to-xml-vs-other-xml-technologies)。

如果源文档具有不规则的结构，则推荐使用 XSLT 工具进行以文档为中心的转换。 但是 LINQ to XML 也可以执行以文档为中心的转换。 有关详细信息，请参阅[如何：使用批注转换 XSLT 样式中的 LINQ to XML 树 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-use-annotations-to-transform-linq-to-xml-trees-in-an-xslt-style)。

## [Tutorial: Chaining Queries Together](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/tutorialchainingqueriestogether)

本教程阐释将查询链接在一起时的处理模型。 将查询链接在一起是编写函数转换的一个关键部分。 确切理解链接的查询如何工作非常重要。

处理 Office Open XML 文档的查询广泛使用了这种方法。

### 本节内容

| 主题                                                         | 说明                                         |
| ------------------------------------------------------------ | -------------------------------------------- |
| [LINQ to XML 中的延迟执行和迟缓计算 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/deferred-execution-and-lazy-evaluation-in-linq-to-xml) | 描述延迟执行和迟缓计算的概念。               |
| [延迟执行示例 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/deferred-execution-example) | 提供一个延迟执行的示例。                     |
| [链接查询示例 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/chaining-queries-example) | 演示在将查询链接在一起时延迟执行的工作方式。 |
| [中间具体化 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/intermediate-materialization) | 确定和说明中间具体化的语义。                 |
| [将标准查询运算符链接在一起 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/chaining-standard-query-operators-together) | 描述标准查询运算符的迟缓语义。               |

### [Deferred Execution and Lazy Evaluation in LINQ to XML](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/deferredexecutionandlazyevaluationinlinqtoxml)

实现查询和轴操作通常是为了使用延迟执行。 本主题解释延迟执行的要求和优点，以及某些实现注意事项。

**延迟执行**

延迟执行意味着表达式的计算延迟，直到真正需要其实现值为止。 当必须操作大型数据集合，特别是在包含一系列链接的查询或操作的程序中操作时，延迟执行可以大大改善性能。 在最佳情况下，延迟执行只允许对源集合的单个循环访问。

LINQ 技术广泛应用了延迟执行，包括在核心 [System.Linq](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq) 类的成员和不同 LINQ 命名空间中的扩展方法（如[System.Xml.Linq.Extensions](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.extensions)）中使用。

在迭代器块内使用时，C# 语言可以通过 [yield](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/yield) 关键字（以 `yield-return` 语句形式），直接支持延迟执行。 此类迭代器必须返回类型为 [IEnumerator](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerator) 或 [IEnumerator](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerator-1)（或派生类型）的集合。

**积极计算与迟缓计算**

当您编写实现延迟执行的方法时，还必须确定是使用迟缓计算还是积极计算来实现该方法。

- 在迟缓计算中，每次调用迭代器时都会处理源集合的一个元素。 这是实现迭代器的典型方式。
- 在积极计算中，第一次调用迭代器时就会对整个集合进行处理。 还可能需要源集合的临时副本。 例如，[OrderBy](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.orderby) 方法必须在返回第一个元素前对整个集合进行排序。

迟缓计算通常产生更好的性能，因为它将系统开销处理平均分配到整个集合的计算中，并将临时数据的使用降至最低。 当然，对于某些操作，除了具体化中间结果之外，再没有其他选择。

**后续步骤**

本教程的下一个主题将解释延迟执行：

- [延迟执行示例 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/deferred-execution-example)

### [Deferred Execution Example](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/deferredexecutionexample)

本主题演示延迟执行和迟缓计算如何影响 LINQ to XML 查询的执行。

- 示例

下面的示例演示使用采用延迟执行的扩展方法时的执行顺序。 此示例声明一个由三个字符串组成的数组。 然后，循环访问 `ConvertCollectionToUpperCase` 所返回的集合。

```csharp
public static class LocalExtensions  
{  
    public static IEnumerable<string>  
      ConvertCollectionToUpperCase(this IEnumerable<string> source)  
    {  
        foreach (string str in source)  
        {  
            Console.WriteLine("ToUpper: source {0}", str);  
            yield return str.ToUpper();  
        }  
    }  
}  
  
class Program  
{  
    static void Main(string[] args)  
    {  
        string[] stringArray = { "abc", "def", "ghi" };  
  
        var q = from str in stringArray.ConvertCollectionToUpperCase()  
                select str;  
  
        foreach (string str in q)  
            Console.WriteLine("Main: str {0}", str);  
    }  
}  
```

该示例产生下面的输出：

```
ToUpper: source abc  
Main: str ABC  
ToUpper: source def  
Main: str DEF  
ToUpper: source ghi  
Main: str GHI  
```

请注意，在循环访问 `ConvertCollectionToUpperCase` 所返回的集合时，每一项都从源字符串数组检索，并且在源字符串数组中检索下一项之前，被转换为大写形式。

可以看到，在 `foreach` 的 `Main` 循环中处理所返回集合的每一项之后，字符串数组才会完全转换为大写形式。

本教程下一主题演示如何将查询链接到一起：

- [链接查询示例 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/chaining-queries-example)

### [Chaining Queries Example](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/chainingqueriesexample)

此示例建立在前一示例的基础上，演示两个都使用延迟执行和迟缓计算的查询链接到一起时会发生什么情况。

**示例**

在此示例中，还会引入另一个扩展方法 `AppendString`，该方法将一个指定字符串追加到源集合的每个字符串上，然后生成新的字符串。

```csharp
public static class LocalExtensions  
{  
    public static IEnumerable<string>  
      ConvertCollectionToUpperCase(this IEnumerable<string> source)  
    {  
        foreach (string str in source)  
        {  
            Console.WriteLine("ToUpper: source >{0}<", str);  
            yield return str.ToUpper();  
        }  
    }  
  
    public static IEnumerable<string>  
      AppendString(this IEnumerable<string> source, string stringToAppend)  
    {  
        foreach (string str in source)  
        {  
            Console.WriteLine("AppendString: source >{0}<", str);  
            yield return str + stringToAppend;  
        }  
    }  
}  
  
class Program  
{  
    static void Main(string[] args)  
    {  
        string[] stringArray = { "abc", "def", "ghi" };  
  
        IEnumerable<string> q1 =  
            from s in stringArray.ConvertCollectionToUpperCase()  
            select s;  
  
        IEnumerable<string> q2 =  
            from s in q1.AppendString("!!!")  
            select s;  
  
        foreach (string str in q2)  
        {  
            Console.WriteLine("Main: str >{0}<", str);  
            Console.WriteLine();  
        }  
    }  
}  
```

该示例产生下面的输出：

```
ToUpper: source >abc<  
AppendString: source >ABC<  
Main: str >ABC!!!<  
  
ToUpper: source >def<  
AppendString: source >DEF<  
Main: str >DEF!!!<  
  
ToUpper: source >ghi<  
AppendString: source >GHI<  
Main: str >GHI!!!<  
```

在此示例中，可以看到，每个扩展方法每次只对源集合中的一个项进行一次操作。

在此示例中，可以清楚地看到，尽管已将生成集合的查询链接到了一起，但未具体化任何中间集合。 相反，每一项只是从一个迟缓方法传递到下一个迟缓方法。 这种方法的内存需求量比另一种方法小得多，在另一种方法中，首先获取一个字符串数组，然后创建第二个字符串数组（其中的字符串都已转换为大写形式），最后创建第三个字符串数组（其中的每个字符串都追加了感叹号）。

本教程下一主题演示中间具体化：

- [中间具体化 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/intermediate-materialization)

### [Intermediate Materialization](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/intermediatematerialization)

有时，稍不小心就会导致查询中的集合过早具体化，从而显著改变应用程序的内存和性能配置文件。 有些标准查询运算符会在生成单个元素之前导致其源集合具体化。 例如，[Enumerable.OrderBy](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.orderby) 首先循环访问其整个源集合，然后对所有项排序，最后生成第一项。 这意味着获取排序集合中的第一项需要高开销；其后的每一项不需要高开销。 这样做很有意义：该查询运算符将不可能以其他方式操作。

**示例**

本示例改自上一示例。 `AppendString` 方法在循环访问源之前调用 [ToList](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.tolist)。 这将导致具体化。

```csharp
public static class LocalExtensions  
{  
    public static IEnumerable<string>  
      ConvertCollectionToUpperCase(this IEnumerable<string> source)  
    {  
        foreach (string str in source)  
        {  
            Console.WriteLine("ToUpper: source >{0}<", str);  
            yield return str.ToUpper();  
        }  
    }  
  
    public static IEnumerable<string>  
      AppendString(this IEnumerable<string> source, string stringToAppend)  
    {  
        // the following statement materializes the source collection in a List<T>  
        // before iterating through it  
        foreach (string str in source.ToList())  
        {  
            Console.WriteLine("AppendString: source >{0}<", str);  
            yield return str + stringToAppend;  
        }  
    }  
}  
  
class Program  
{  
    static void Main(string[] args)  
    {  
        string[] stringArray = { "abc", "def", "ghi" };  
  
        IEnumerable<string> q1 =  
            from s in stringArray.ConvertCollectionToUpperCase()  
            select s;  
  
        IEnumerable<string> q2 =  
            from s in q1.AppendString("!!!")  
            select s;  
  
        foreach (string str in q2)  
        {  
            Console.WriteLine("Main: str >{0}<", str);  
            Console.WriteLine();  
        }  
    }  
}  
```

该示例产生下面的输出：

```
ToUpper: source >abc<  
ToUpper: source >def<  
ToUpper: source >ghi<  
AppendString: source >ABC<  
Main: str >ABC!!!<  
  
AppendString: source >DEF<  
Main: str >DEF!!!<  
  
AppendString: source >GHI<  
Main: str >GHI!!!<  
```

在此示例中，您可以看到，对 [ToList](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.tolist) 的调用会导致 `AppendString` 生成第一项之前枚举其整个源。 如果源是一个大数组，这将显著改变应用程序的内存配置文件。

标准查询运算符也可以链接在一起。 本教程的最后一个主题将对此进行说明。

- [将标准查询运算符链接在一起 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/chaining-standard-query-operators-together)

### [Chaining Standard Query Operators Together](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/chainingstandardqueryoperatorstogether)

这是[教程：将查询链接在一起 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/tutorial-chaining-queries-together) 教程中的最后一个主题。

标准查询运算符也可以链接在一起。 例如，您可以插入 [Enumerable.Where](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.where) 运算符，并且该运算符也可以以迟缓方式操作。 它不会具体化任何中间结果。

**示例**

在此示例中，调用 [Where](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.where) 之前将调用 `ConvertCollectionToUpperCase` 方法。 [Where](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.where) 方法的操作方式与本教程前面示例中使用的迟缓方法 `ConvertCollectionToUpperCase` 和 `AppendString` 几乎完全相同。

区别之一是在本例中，[Where](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.where) 方法循环访问其源集合，确定第一项不传递谓词，然后获取传递谓词的下一项。 示例然后生成第二项。

但基本要旨是相同的：除非必要，否则不具体化中间集合。

在使用查询表达式时，会将查询表达式转换为对标准查询运算符的调用，这一原理同样适用。

本节中查询 Office Open XML 文档的所有示例都使用相同的原理。 延迟执行和迟缓计算是有效使用 LINQ（和 LINQ to XML）所必须理解的一些基础概念。

```csharp
public static class LocalExtensions  
{  
    public static IEnumerable<string>  
      ConvertCollectionToUpperCase(this IEnumerable<string> source)  
    {  
        foreach (string str in source)  
        {  
            Console.WriteLine("ToUpper: source >{0}<", str);  
            yield return str.ToUpper();  
        }  
    }  
  
    public static IEnumerable<string>  
      AppendString(this IEnumerable<string> source, string stringToAppend)  
    {  
        foreach (string str in source)  
        {  
            Console.WriteLine("AppendString: source >{0}<", str);  
            yield return str + stringToAppend;  
        }  
    }  
}  
  
class Program  
{  
    static void Main(string[] args)  
    {  
        string[] stringArray = { "abc", "def", "ghi" };  
  
        IEnumerable<string> q1 =  
            from s in stringArray.ConvertCollectionToUpperCase()  
            where s.CompareTo("D") >= 0  
            select s;  
  
        IEnumerable<string> q2 =  
            from s in q1.AppendString("!!!")  
            select s;  
  
        foreach (string str in q2)  
        {  
            Console.WriteLine("Main: str >{0}<", str);  
            Console.WriteLine();  
        }  
    }  
}  
```

该示例产生下面的输出：

```
ToUpper: source >abc<  
ToUpper: source >def<  
AppendString: source >DEF<  
Main: str >DEF!!!<  
  
ToUpper: source >ghi<  
AppendString: source >GHI<  
Main: str >GHI!!!<  
```

## [Tutorial: Manipulating Content in a WordprocessingML Document](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/tutorialmanipulatingcontentinawordprocessingmldocument)

本教程演示如何应用函数转换方法和 LINQ to XML 来操作 XML 文档。 C# 示例查询和操作用 Microsoft Word 保存的 Office Open XML WordprocessingML 文档中的信息。

有关详细信息，请参阅 [WordprocessingML 简介](https://ericwhite.com/blog/introduction-to-wordprocessingml-series/)。

### 本节内容

| 主题                                                         | 说明                                                       |
| ------------------------------------------------------------ | ---------------------------------------------------------- |
| [WordprocessingML 文档的形状 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/shape-of-wordprocessingml-documents) | 提供有关 WordprocessingML 文档详细信息的简要说明。         |
| [创建源 Office Open XML 文档 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/creating-the-source-office-open-xml-document) | 为创建用于本教程中的查询的源文档提供分步说明。             |
| [查找默认段落样式 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/finding-the-default-paragraph-style) | 演示用于查找文档默认样式名称的查询。                       |
| [检索段落及其样式 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/retrieving-the-paragraphs-and-their-styles) | 演示用于检索文档段落集合的查询。                           |
| [检索段落的文本 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/retrieving-the-text-of-the-paragraphs) | 补充前一个查询以检索每个段落的文本。                       |
| [使用扩展方法重构 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/refactoring-using-an-extension-method) | 通过使用扩展方法进行重构来简化代码。                       |
| [使用纯函数重构 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/refactoring-using-a-pure-function) | 通过使用纯函数进行重构来进一步简化代码。                   |
| [对不同形状的 XML 进行投影 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/projecting-xml-in-a-different-shape) | 通过将 XML 投影为不同于原始文档的形状来完成 XML 转换。     |
| [查找 Word 文档中的文本 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/finding-text-in-word-documents) | 使用前面的查询在文档中查找指定的文本字符串。               |
| [Office Open XML WordprocessingML 文档的详细信息 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/details-of-office-open-xml-wordprocessingml-documents) | 提供 Office Open XML WordprocessingML 文档的一些详细信息。 |

### [Shape of WordprocessingML Documents](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/shapeofwordprocessingmldocuments)

本主题介绍 WordprocessingML 文档的 XML 形状。

**Microsoft Office 格式**

2007 Microsoft Office 系统的本机文件格式为 Office Open XML（通常称为 Open XML）。 Open XML 是一种基于 XML 的格式（Ecma 标准），当前即将通过 ISO-IEC 标准流程。 Open XML 中用于文字处理文件的标记语言称为 WordprocessingML。 本教程使用 WordprocessingML 源文件作为示例的输入。

如果使用 Microsoft Office 2003，则在已安装适用于 Word、Excel 和 PowerPoint 2007 文件格式的 Microsoft Office 兼容包的情况下，可以将文档保存为 Office Open XML 格式。

**WordprocessingML 文档的形状**

首先要了解的是 WordprocessingML 文档的形状。 WordprocessingML 文档包含一个正文元素（称为 `w:body`），该元素包含文档的各个段落。 每个段落包含一个或多个文本域（称为 `w:r`）。 每个文本域包含一个或多个文本块（称为 `w:t`）。

下面是一个非常简单的 WordprocessingML 文档：

```xml
<?xml version="1.0" encoding="utf-8" standalone="yes"?>  
<w:document  
xmlns:ve="http://schemas.openxmlformats.org/markup-compatibility/2006"  
xmlns:o="urn:schemas-microsoft-com:office:office"  
xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships"  
xmlns:m="http://schemas.openxmlformats.org/officeDocument/2006/math"  
xmlns:v="urn:schemas-microsoft-com:vml"  
xmlns:wp="http://schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing"  
xmlns:w10="urn:schemas-microsoft-com:office:word"  
xmlns:w="http://schemas.openxmlformats.org/wordprocessingml/2006/main"  
xmlns:wne="http://schemas.microsoft.com/office/word/2006/wordml">  
  <w:body>  
    <w:p w:rsidR="00E22EB6"  
         w:rsidRDefault="00E22EB6">  
      <w:r>  
        <w:t>This is a paragraph.</w:t>  
      </w:r>  
    </w:p>  
    <w:p w:rsidR="00E22EB6"  
         w:rsidRDefault="00E22EB6">  
      <w:r>  
        <w:t>This is another paragraph.</w:t>  
      </w:r>  
    </w:p>  
  </w:body>  
</w:document>  
```

此文档包含两个段落。 这两个段落都包含单个文本域，每个文本域都包含单个文本块。

查看 XML 格式的 WordprocessingML 文档内容的最简单方式是使用 Microsoft Word 创建一个 XML 文档，保存该文档，然后运行下面的程序，将该 XML 打印到控制台。

本示例使用 WindowsBase 程序集中的类。 它使用 [System.IO.Packaging](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging) 命名空间中的类型。

```csharp
const string documentRelationshipType =  
  "http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument";  
const string wordmlNamespace =  
  "http://schemas.openxmlformats.org/wordprocessingml/2006/main";  
XNamespace w = wordmlNamespace;  
  
using (Package wdPackage = Package.Open("SampleDoc.docx", FileMode.Open, FileAccess.Read))  
{  
    PackageRelationship relationship =  
        wdPackage  
        .GetRelationshipsByType(documentRelationshipType)  
        .FirstOrDefault();  
    if (relationship != null)  
    {  
        Uri documentUri =  
            PackUriHelper.ResolvePartUri(  
                new Uri("/", UriKind.Relative),  
                relationship.TargetUri);  
        PackagePart documentPart = wdPackage.GetPart(documentUri);  
  
        //  Get the officeDocument part from the package.  
        //  Load the XML in the part into an XDocument instance.  
        XDocument xdoc =  
            XDocument.Load(XmlReader.Create(documentPart.GetStream()));  
        Console.WriteLine(xdoc.Root);  
    }  
}  
```

**外部资源**

[介绍 Office (2007) Open XML 文件格式](https://docs.microsoft.com/previous-versions/office/developer/office-2007/aa338205%28v=office.12%29)
[Overview of WordprocessingML](https://docs.microsoft.com/previous-versions/office/developer/office-2003/aa212812%28v=office.11%29)（WordprocessingML 概述）
[WordProcessingML 文件剖析](http://officeopenxml.com/anatomyofOOXML.php)
[WordprocessingML 简介](https://ericwhite.com/blog/introduction-to-wordprocessingml-series/)
[Office 2003：XML 参考架构下载页](https://www.microsoft.com/en-us/download/details.aspx?id=101)

### [Creating the Source Office Open XML Document](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/creatingthesourceofficeopenxmldocument)

本主题演示如何创建本教程其他示例中使用的 Office Open XML WordprocessingML 文档。 如果您按照这些说明操作，您的输出结果将与每个示例中提供的输出相匹配。

不过，本教程中的示例可以使用任何有效的 WordprocessingML 文档。

若要创建本教程使用的文档，必须安装 Microsoft Office 2007 或更高版本，或者具有 Microsoft Office Word、Excel 和 PowerPoint 2007 文件格式兼容包的 Microsoft Office 2003。

**创建 WordprocessingML 文档**

1. 创建一个新的 Microsoft Word 文档。

2. 将以下文本粘贴到新文档中：

   ```
   Parsing WordprocessingML with LINQ to XML  
   
   The following example prints to the console.  
   
   using System;  
   
   class Program {  
       public static void Main(string[] args) {  
           Console.WriteLine("Hello World");  
       }  
   }  
   
   This example produces the following output:  
   
   Hello World  
   ```

3. 用“标题 1”样式格式化第一行。

4. 选择包含 C# 代码的行。 第一行以 `using` 关键字开头。 最后一行是最后一个右大括号。 用 courier 字体格式化这些行。 用新样式格式化这些行并将新样式命名为“Code”。

5. 最后，选择包含输出的整个行，并用 `Code` 样式格式化该行。

6. 保存文档，并将其命名为 SampleDoc.docx。

   备注

   如果使用的是 Microsoft Word 2003，请在“保存类型”下拉列表中选择“Word 2007 文档”。

### [Finding the Default Paragraph Style](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/findingthedefaultparagraphstyle)

在 WordprocessingML 文档中操作信息教程中的第一项任务是在文档中查找默认段落样式。

**示例**

**说明**

下面的示例打开一个 Office Open XML WordprocessingML 文档，查找文档和包的样式部分，然后执行查找默认样式名称的查询。 有关 Office Open XML 文档包及其构成包的信息，请参阅 [Office Open XML WordprocessingML 文档的详细信息 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/details-of-office-open-xml-wordprocessingml-documents)。

查询将查找名为 `w:style` 的节点，该节点具有值为“paragraph”的名为 `w:type` 的属性和值为“1”的名为 `w:default` 的属性。 由于将只有一个 XML 节点具有这些属性，因此查询使用 [Enumerable.First](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.first) 运算符将集合转换为单一实例。 然后，它获取名为 `w:styleId` 的属性的值。

本示例使用 WindowsBase 程序集中的类。 它使用 [System.IO.Packaging](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging) 命名空间中的类型。

**代码**

```csharp
const string fileName = "SampleDoc.docx";  
  
const string documentRelationshipType =  
  "http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument";  
const string stylesRelationshipType =  
  "http://schemas.openxmlformats.org/officeDocument/2006/relationships/styles";  
const string wordmlNamespace =  
  "http://schemas.openxmlformats.org/wordprocessingml/2006/main";  
XNamespace w = wordmlNamespace;  
  
XDocument xDoc = null;  
XDocument styleDoc = null;  
  
using (Package wdPackage = Package.Open(fileName, FileMode.Open, FileAccess.Read))  
{  
    PackageRelationship docPackageRelationship =  
      wdPackage.GetRelationshipsByType(documentRelationshipType).FirstOrDefault();  
    if (docPackageRelationship != null)  
    {  
        Uri documentUri = PackUriHelper.ResolvePartUri(new Uri("/", UriKind.Relative),  
          docPackageRelationship.TargetUri);  
        PackagePart documentPart = wdPackage.GetPart(documentUri);  
  
        //  Load the document XML in the part into an XDocument instance.  
        xDoc = XDocument.Load(XmlReader.Create(documentPart.GetStream()));  
  
        //  Find the styles part. There will only be one.  
        PackageRelationship styleRelation =  
          documentPart.GetRelationshipsByType(stylesRelationshipType).FirstOrDefault();  
        if (styleRelation != null)  
        {  
            Uri styleUri = PackUriHelper.ResolvePartUri(documentUri, styleRelation.TargetUri);  
            PackagePart stylePart = wdPackage.GetPart(styleUri);  
  
            //  Load the style XML in the part into an XDocument instance.  
            styleDoc = XDocument.Load(XmlReader.Create(stylePart.GetStream()));  
        }  
    }  
}  
  
// The following query finds all the paragraphs that have the default style.  
string defaultStyle =   
    (string)(  
        from style in styleDoc.Root.Elements(w + "style")  
        where (string)style.Attribute(w + "type") == "paragraph"&&  
              (string)style.Attribute(w + "default") == "1"  
              select style  
    ).First().Attribute(w + "styleId");  
  
Console.WriteLine("The default style is: {0}", defaultStyle);  
```

**注释**

该示例产生下面的输出：

```
The default style is: Normal  
```

后续步骤

下一个示例中将创建一个类似的查询，查找文档中的所有段落及其样式：

- [检索段落及其样式 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/retrieving-the-paragraphs-and-their-styles)

### [Retrieving the Paragraphs and Their Styles](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/retrievingtheparagraphsandtheirstyles)

在本示例中，我们编写一个从 WordprocessingML 文档检索段落节点的查询。 它还标识每个段落的样式。

此查询建立在前一示例[查找默认段落样式 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/finding-the-default-paragraph-style) 中的查询的基础之上，该查询从样式列表中检索默认样式。 这些信息是必需的，以便查询能标识未显式设置样式的段落样式。 段落样式通过 `w:pPr` 元素来设置；如果段落未包含此元素，则它会使用默认样式的格式。

本主题解释某些查询的意义，然后作为一个完整工作示例的一部分来显示查询。

#### 示例

检索文档中所有段落及其样式的查询的源如下所示：

```csharp
xDoc.Root.Element(w + "body").Descendants(w + "p")  
```

此表达式与前一示例[查找默认段落样式 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/finding-the-default-paragraph-style) 中的查询的源相似。 主要区别是它使用 [Descendants](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.descendants) 轴，而不是 [Elements](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.elements) 轴。 该查询使用 [Descendants](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.descendants) 轴，因为在包含节的文档中，段落将不是正文元素的直接子元素；而是在层次结构中的两个级别之下。 通过使用 [Descendants](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.descendants) 轴，无论文档是否使用节，代码都能运行。

#### 示例

该查询使用 `let` 子句来确定包含样式节点的元素。 如果没有任何元素，则将 `styleNode` 设置为 `null`：

```csharp
let styleNode = para.Elements(w + "pPr").Elements(w + "pStyle").FirstOrDefault()  
```

`let` 子句首先使用 [Elements](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.elements) 轴，查找所有名为 `pPr` 的元素，然后使用 [Elements](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.extensions.elements) 扩展方法，查找所有名为 `pStyle` 的子元素，最后使用 [FirstOrDefault](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.firstordefault) 标准查询运算符，将集合转换为单一实例。 如果集合为空，则将 `styleNode` 设置为 `null`。 这是一个用于查找 `pStyle` 子代节点的有用方法。 请注意，如果 `pPr` 子节点不存在，代码不会通过引发异常而运行失败；相反，它会将 `styleNode` 设置为 `null`，这是此 `let` 子句的期望行为。

该查询投影一个具有两个成员 `StyleName` 和 `ParagraphNode` 的匿名类型的集合。

#### 示例

本示例处理一个 WordprocessingML 文档，它从 WordprocessingML 文档中检索段落节点。 它还标识每个段落的样式。 本示例以本教程中前面的一些示例为基础构建。 下面代码中的注释标识出了这个新查询。

若要查找用于创建此示例的源文档的说明，请参阅[创建源 Office Open XML 文档 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/creating-the-source-office-open-xml-document)。

本示例使用 WindowsBase 程序集中的类。 它使用 [System.IO.Packaging](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging) 命名空间中的类型。

```csharp
const string fileName = "SampleDoc.docx";  
  
const string documentRelationshipType = "http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument";  
const string stylesRelationshipType = "http://schemas.openxmlformats.org/officeDocument/2006/relationships/styles";  
const string wordmlNamespace = "http://schemas.openxmlformats.org/wordprocessingml/2006/main";  
XNamespace w = wordmlNamespace;  
  
XDocument xDoc = null;  
XDocument styleDoc = null;  
  
using (Package wdPackage = Package.Open(fileName, FileMode.Open, FileAccess.Read))  
{  
    PackageRelationship docPackageRelationship = wdPackage.GetRelationshipsByType(documentRelationshipType).FirstOrDefault();  
    if (docPackageRelationship != null)  
    {  
        Uri documentUri = PackUriHelper.ResolvePartUri(new Uri("/", UriKind.Relative), docPackageRelationship.TargetUri);  
        PackagePart documentPart = wdPackage.GetPart(documentUri);  
  
        //  Load the document XML in the part into an XDocument instance.  
        xDoc = XDocument.Load(XmlReader.Create(documentPart.GetStream()));  
  
        //  Find the styles part. There will only be one.  
        PackageRelationship styleRelation = documentPart.GetRelationshipsByType(stylesRelationshipType).FirstOrDefault();  
        if (styleRelation != null)  
        {  
            Uri styleUri = PackUriHelper.ResolvePartUri(documentUri, styleRelation.TargetUri);  
            PackagePart stylePart = wdPackage.GetPart(styleUri);  
  
            //  Load the style XML in the part into an XDocument instance.  
            styleDoc = XDocument.Load(XmlReader.Create(stylePart.GetStream()));  
        }  
    }  
}  
  
string defaultStyle =   
    (string)(  
        from style in styleDoc.Root.Elements(w + "style")  
        where (string)style.Attribute(w + "type") == "paragraph"&&  
              (string)style.Attribute(w + "default") == "1"  
              select style  
    ).First().Attribute(w + "styleId");  
  
// Following is the new query that finds all paragraphs in the  
// document and their styles.  
var paragraphs =  
    from para in xDoc  
                 .Root  
                 .Element(w + "body")  
                 .Descendants(w + "p")  
    let styleNode = para  
                    .Elements(w + "pPr")  
                    .Elements(w + "pStyle")  
                    .FirstOrDefault()  
    select new  
    {  
        ParagraphNode = para,  
        StyleName = styleNode != null ?  
            (string)styleNode.Attribute(w + "val") :  
            defaultStyle  
    };  
  
foreach (var p in paragraphs)  
    Console.WriteLine("StyleName:{0}", p.StyleName);  
```

当此示例应用于[创建源 Office Open XML 文档 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/creating-the-source-office-open-xml-document) 中说明的文档时，会生成以下输出。

```
StyleName:Heading1  
StyleName:Normal  
StyleName:Normal  
StyleName:Normal  
StyleName:Code  
StyleName:Code  
StyleName:Code  
StyleName:Code  
StyleName:Code  
StyleName:Code  
StyleName:Code  
StyleName:Normal  
StyleName:Normal  
StyleName:Normal  
StyleName:Code  
```

#### 后续步骤

在下一主题[检索段落的文本 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/retrieving-the-text-of-the-paragraphs) 中，将创建一个查询来检索段落的文本。

### [Retrieving the Text of the Paragraphs](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/retrievingthetextoftheparagraphs)

此示例以上一个示例[检索段落及其样式 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/retrieving-the-paragraphs-and-their-styles) 为基础。 这个新示例将每个段落的文本作为字符串进行检索。

为检索文本，此示例另外添加了一个查询，该查询循环访问匿名类型的集合，并通过添加新成员 `Text` 对一个匿名类型的新集合进行投影。 该示例使用 [Aggregate](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.aggregate) 标准查询运算符将多个字符串串联为一个字符串。

这种方法（即首先投影到一个匿名类型集合，然后使用该集合投影到一个新的匿名类型集合）是一种既常用又有效的方法。 此查询在编写时本来可以不投影到第一个匿名类型。 但是因为使用迟缓计算，即使这样做也并不会过多占用额外的处理能力。 此方法在堆上创建更多生存时间很短的对象，但这并不会显著降低性能。

当然，可以只编写一个查询，使之包含检索段落、每个段落的样式以及每个段落的文本这些功能。 但是，将一个比较复杂的查询分解成多个查询通常很有好处，因为这样产生的代码更加模块化，更易于维护。 而且，如果需要重用查询的某一部分，使用此方式编写的查询更容易重构。

这些链接在一起的查询使用的处理模型在[教程：将查询链接在一起 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/tutorial-chaining-queries-together) 中有详细的讨论。

#### 示例

本示例处理一个 WordprocessingML 文档，它确定元素节点、样式名称和每个段落的文本。 本示例以本教程中前面的一些示例为基础构建。 下面代码中的注释标识出了这个新查询。

有关创建此示例的源文档的说明，请参阅[创建源 Office Open XML 文档 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/creating-the-source-office-open-xml-document)。

本示例使用 WindowsBase 程序集中的类。 它使用 [System.IO.Packaging](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging) 命名空间中的类型。

```csharp
const string fileName = "SampleDoc.docx";  
  
const string documentRelationshipType =  
  "http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument";  
const string stylesRelationshipType =  
  "http://schemas.openxmlformats.org/officeDocument/2006/relationships/styles";  
const string wordmlNamespace =  
  "http://schemas.openxmlformats.org/wordprocessingml/2006/main";  
XNamespace w = wordmlNamespace;  
  
XDocument xDoc = null;  
XDocument styleDoc = null;  
  
using (Package wdPackage = Package.Open(fileName, FileMode.Open, FileAccess.Read))  
{  
    PackageRelationship docPackageRelationship =  
      wdPackage.GetRelationshipsByType(documentRelationshipType).FirstOrDefault();  
    if (docPackageRelationship != null)  
    {  
        Uri documentUri = PackUriHelper.ResolvePartUri(new Uri("/", UriKind.Relative),  
          docPackageRelationship.TargetUri);  
        PackagePart documentPart = wdPackage.GetPart(documentUri);  
  
        //  Load the document XML in the part into an XDocument instance.  
        xDoc = XDocument.Load(XmlReader.Create(documentPart.GetStream()));  
  
        //  Find the styles part. There will only be one.  
        PackageRelationship styleRelation =  
          documentPart.GetRelationshipsByType(stylesRelationshipType).FirstOrDefault();  
        if (styleRelation != null)  
        {  
            Uri styleUri = PackUriHelper.ResolvePartUri(documentUri, styleRelation.TargetUri);  
            PackagePart stylePart = wdPackage.GetPart(styleUri);  
  
            //  Load the style XML in the part into an XDocument instance.  
            styleDoc = XDocument.Load(XmlReader.Create(stylePart.GetStream()));  
        }  
    }  
}  
  
string defaultStyle =   
    (string)(  
        from style in styleDoc.Root.Elements(w + "style")  
        where (string)style.Attribute(w + "type") == "paragraph"&&  
              (string)style.Attribute(w + "default") == "1"  
              select style  
    ).First().Attribute(w + "styleId");  
  
// Find all paragraphs in the document.  
var paragraphs =  
    from para in xDoc  
                 .Root  
                 .Element(w + "body")  
                 .Descendants(w + "p")  
    let styleNode = para  
                    .Elements(w + "pPr")  
                    .Elements(w + "pStyle")  
                    .FirstOrDefault()  
    select new  
    {  
        ParagraphNode = para,  
        StyleName = styleNode != null ?  
            (string)styleNode.Attribute(w + "val") :  
            defaultStyle  
    };  
  
// Following is the new query that retrieves the text of  
// each paragraph.  
var paraWithText =  
    from para in paragraphs  
    select new  
    {  
        ParagraphNode = para.ParagraphNode,  
        StyleName = para.StyleName,  
        Text = para  
               .ParagraphNode  
               .Elements(w + "r")  
               .Elements(w + "t")  
               .Aggregate(  
                   new StringBuilder(),  
                   (s, i) => s.Append((string)i),  
                   s => s.ToString()  
               )  
    };  
  
foreach (var p in paraWithText)  
    Console.WriteLine("StyleName:{0} >{1}<", p.StyleName, p.Text);  
```

当此示例应用于[创建源 Office Open XML 文档 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/creating-the-source-office-open-xml-document) 中说明的文档时，会生成以下输出。

```
StyleName:Heading1 >Parsing WordprocessingML with LINQ to XML<  
StyleName:Normal ><  
StyleName:Normal >The following example prints to the console.<  
StyleName:Normal ><  
StyleName:Code >using System;<  
StyleName:Code ><  
StyleName:Code >class Program {<  
StyleName:Code >    public static void (string[] args) {<  
StyleName:Code >        Console.WriteLine("Hello World");<  
StyleName:Code >    }<  
StyleName:Code >}<  
StyleName:Normal ><  
StyleName:Normal >This example produces the following output:<  
StyleName:Normal ><  
StyleName:Code >Hello World<  
```

#### 后续步骤

下面的示例演示如何使用扩展方法而不是 [Aggregate](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.aggregate) 将多个字符串串联为一个字符串。

- [使用扩展方法重构 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/refactoring-using-an-extension-method)

### [Refactoring Using an Extension Method](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/refactoringusinganextensionmethod)

本示例建立在前面示例（[检索段落的文本 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/retrieving-the-text-of-the-paragraphs)）的基础之上，具体方法是使用作为扩展方法实现的一个纯函数来重构字符串的串联。

前面的示例使用 [Aggregate](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.aggregate) 标准查询运算符将多个字符串串联为一个字符串。 不过，编写一个扩展方法来执行此操作会更方便，因为这样实现的查询会更小、更简单。

#### 示例

本示例处理一个 WordprocessingML 文档，检索段落、每个段落的样式以及每个段落的文本。 本示例以本教程中前面的一些示例为基础构建。

本示例包含 `StringConcatenate` 方法的多个重载。

若要查找用于创建此示例的源文档的说明，请参阅[创建源 Office Open XML 文档 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/creating-the-source-office-open-xml-document)。

本示例使用 WindowsBase 程序集中的类。 它使用 [System.IO.Packaging](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging) 命名空间中的类型。

```csharp
public static class LocalExtensions  
{  
    public static string StringConcatenate(this IEnumerable<string> source)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (string s in source)  
            sb.Append(s);  
        return sb.ToString();  
    }  
  
    public static string StringConcatenate<T>(this IEnumerable<T> source,  
        Func<T, string> func)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (T item in source)  
            sb.Append(func(item));  
        return sb.ToString();  
    }  
  
    public static string StringConcatenate(this IEnumerable<string> source, string separator)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (string s in source)  
            sb.Append(s).Append(separator);  
        return sb.ToString();  
    }  
  
    public static string StringConcatenate<T>(this IEnumerable<T> source,  
        Func<T, string> func, string separator)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (T item in source)  
            sb.Append(func(item)).Append(separator);  
        return sb.ToString();  
    }  
}  
```

#### 示例

`StringConcatenate` 方法有四个重载。 其中一个重载仅接受字符串集合并返回单个字符串。 另一个重载可以接受任何类型的集合，以及从该集合的单一实例映射到字符串的委托。 使用其余两个重载可以指定分隔符字符串。

下面的代码使用所有四个重载

```csharp
string[] numbers = { "one", "two", "three" };  
  
Console.WriteLine("{0}", numbers.StringConcatenate());  
Console.WriteLine("{0}", numbers.StringConcatenate(":"));  
  
int[] intNumbers = { 1, 2, 3 };  
Console.WriteLine("{0}", intNumbers.StringConcatenate(i => i.ToString()));  
Console.WriteLine("{0}", intNumbers.StringConcatenate(i => i.ToString(), ":"));  
```

该示例产生下面的输出：

复制

```
onetwothree  
one:two:three:  
123  
1:2:3:  
```

#### 示例

现在，可以对示例进行修改，从而利用新扩展方法。

```csharp
public static class LocalExtensions  
{  
    public static string StringConcatenate(this IEnumerable<string> source)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (string s in source)  
            sb.Append(s);  
        return sb.ToString();  
    }  
  
    public static string StringConcatenate<T>(this IEnumerable<T> source,  
        Func<T, string> func)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (T item in source)  
            sb.Append(func(item));  
        return sb.ToString();  
    }  
  
    public static string StringConcatenate(this IEnumerable<string> source, string separator)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (string s in source)  
            sb.Append(s).Append(separator);  
        return sb.ToString();  
    }  
  
    public static string StringConcatenate<T>(this IEnumerable<T> source,  
        Func<T, string> func, string separator)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (T item in source)  
            sb.Append(func(item)).Append(separator);  
        return sb.ToString();  
    }  
}  
  
class Program  
{  
    static void Main(string[] args)  
    {  
        const string fileName = "SampleDoc.docx";  
  
        const string documentRelationshipType =  
          "http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument";  
        const string stylesRelationshipType =  
          "http://schemas.openxmlformats.org/officeDocument/2006/relationships/styles";  
        const string wordmlNamespace =  
          "http://schemas.openxmlformats.org/wordprocessingml/2006/main";  
        XNamespace w = wordmlNamespace;  
  
        XDocument xDoc = null;  
        XDocument styleDoc = null;  
  
        using (Package wdPackage = Package.Open(fileName, FileMode.Open, FileAccess.Read))  
        {  
            PackageRelationship docPackageRelationship =  
              wdPackage.GetRelationshipsByType(documentRelationshipType).FirstOrDefault();  
            if (docPackageRelationship != null)  
            {  
                Uri documentUri = PackUriHelper.ResolvePartUri(new Uri("/", UriKind.Relative),  
                  docPackageRelationship.TargetUri);  
                PackagePart documentPart = wdPackage.GetPart(documentUri);  
  
                //  Load the document XML in the part into an XDocument instance.  
                xDoc = XDocument.Load(XmlReader.Create(documentPart.GetStream()));  
  
                //  Find the styles part. There will only be one.  
                PackageRelationship styleRelation =  
                  documentPart.GetRelationshipsByType(stylesRelationshipType).FirstOrDefault();  
                if (styleRelation != null)  
                {  
                    Uri styleUri =  
                      PackUriHelper.ResolvePartUri(documentUri, styleRelation.TargetUri);  
                    PackagePart stylePart = wdPackage.GetPart(styleUri);  
  
                    //  Load the style XML in the part into an XDocument instance.  
                    styleDoc = XDocument.Load(XmlReader.Create(stylePart.GetStream()));  
                }  
            }  
        }  
  
        string defaultStyle =  
            (string)(  
                from style in styleDoc.Root.Elements(w + "style")  
                where (string)style.Attribute(w + "type") == "paragraph" &&  
                      (string)style.Attribute(w + "default") == "1"  
                select style  
            ).First().Attribute(w + "styleId");  
  
        // Find all paragraphs in the document.  
        var paragraphs =  
            from para in xDoc  
                         .Root  
                         .Element(w + "body")  
                         .Descendants(w + "p")  
            let styleNode = para  
                            .Elements(w + "pPr")  
                            .Elements(w + "pStyle")  
                            .FirstOrDefault()  
            select new  
            {  
                ParagraphNode = para,  
                StyleName = styleNode != null ?  
                    (string)styleNode.Attribute(w + "val") :  
                    defaultStyle  
            };  
  
        // Retrieve the text of each paragraph.  
        var paraWithText =  
            from para in paragraphs  
            select new  
            {  
                ParagraphNode = para.ParagraphNode,  
                StyleName = para.StyleName,  
                Text = para  
                       .ParagraphNode  
                       .Elements(w + "r")  
                       .Elements(w + "t")  
                       .StringConcatenate(e => (string)e)  
            };  
  
        foreach (var p in paraWithText)  
            Console.WriteLine("StyleName:{0} >{1}<", p.StyleName, p.Text);  
    }  
}  
```

当此示例应用于[创建源 Office Open XML 文档 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/creating-the-source-office-open-xml-document) 中说明的文档时，会生成以下输出。

```
StyleName:Heading1 >Parsing WordprocessingML with LINQ to XML<  
StyleName:Normal ><  
StyleName:Normal >The following example prints to the console.<  
StyleName:Normal ><  
StyleName:Code >using System;<  
StyleName:Code ><  
StyleName:Code >class Program {<  
StyleName:Code >    public static void (string[] args) {<  
StyleName:Code >        Console.WriteLine("Hello World");<  
StyleName:Code >    }<  
StyleName:Code >}<  
StyleName:Normal ><  
StyleName:Normal >This example produces the following output:<  
StyleName:Normal ><  
StyleName:Code >Hello World<  
```

请注意，此重构是重构到纯函数的一种变体。 下一主题将更详细地介绍重构到纯函数的概念。

#### 后续步骤

下一示例演示如何使用纯函数以其他方式重构此代码：

- [使用纯函数重构 (Visual Basic)](https://docs.microsoft.com/zh-cn/dotnet/visual-basic/programming-guide/concepts/linq/refactoring-using-a-pure-function)

### [Refactoring Using a Pure Function](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/refactoringusingapurefunction)

下面的示例使用一个纯函数对前面的示例[使用扩展方法重构 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/refactoring-using-an-extension-method) 进行重构。在本示例中，查找段落文本的代码将移至纯静态方法 `ParagraphText` 中。

#### 示例

本示例处理一个 WordprocessingML 文档，它从 WordprocessingML 文档中检索段落节点。 它还标识每个段落的样式。 本示例以本教程中前面的一些示例为基础构建。 下面代码中的注释标识出了重构的代码。

有关创建此示例的源文档的说明，请参阅[创建源 Office Open XML 文档 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/creating-the-source-office-open-xml-document)。

本示例使用 WindowsBase 程序集中的类。 它使用 [System.IO.Packaging](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging) 命名空间中的类型。

```csharp
public static class LocalExtensions  
{  
    public static string StringConcatenate(this IEnumerable<string> source)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (string s in source)  
            sb.Append(s);  
        return sb.ToString();  
    }  
  
    public static string StringConcatenate<T>(this IEnumerable<T> source,  
        Func<T, string> func)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (T item in source)  
            sb.Append(func(item));  
        return sb.ToString();  
    }  
  
    public static string StringConcatenate(this IEnumerable<string> source, string separator)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (string s in source)  
            sb.Append(s).Append(separator);  
        return sb.ToString();  
    }  
  
    public static string StringConcatenate<T>(this IEnumerable<T> source,  
        Func<T, string> func, string separator)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (T item in source)  
            sb.Append(func(item)).Append(separator);  
        return sb.ToString();  
    }  
}  
  
class Program  
{  
    // This is a new method that assembles the paragraph text.  
    public static string ParagraphText(XElement e)  
    {  
        XNamespace w = e.Name.Namespace;  
        return e  
               .Elements(w + "r")  
               .Elements(w + "t")  
               .StringConcatenate(element => (string)element);  
    }  
  
    static void Main(string[] args)  
    {  
        const string fileName = "SampleDoc.docx";  
  
        const string documentRelationshipType =  
          "http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument";  
        const string stylesRelationshipType =  
          "http://schemas.openxmlformats.org/officeDocument/2006/relationships/styles";  
        const string wordmlNamespace =  
          "http://schemas.openxmlformats.org/wordprocessingml/2006/main";  
        XNamespace w = wordmlNamespace;  
  
        XDocument xDoc = null;  
        XDocument styleDoc = null;  
  
        using (Package wdPackage = Package.Open(fileName, FileMode.Open, FileAccess.Read))  
        {  
            PackageRelationship docPackageRelationship =  
              wdPackage.GetRelationshipsByType(documentRelationshipType).FirstOrDefault();  
            if (docPackageRelationship != null)  
            {  
                Uri documentUri = PackUriHelper.ResolvePartUri(new Uri("/", UriKind.Relative),  
                  docPackageRelationship.TargetUri);  
                PackagePart documentPart = wdPackage.GetPart(documentUri);  
  
                //  Load the document XML in the part into an XDocument instance.  
                xDoc = XDocument.Load(XmlReader.Create(documentPart.GetStream()));  
  
                //  Find the styles part. There will only be one.  
                PackageRelationship styleRelation =  
                  documentPart.GetRelationshipsByType(stylesRelationshipType).FirstOrDefault();  
                if (styleRelation != null)  
                {  
                    Uri styleUri = PackUriHelper.ResolvePartUri(documentUri,  
                      styleRelation.TargetUri);  
                    PackagePart stylePart = wdPackage.GetPart(styleUri);  
  
                    //  Load the style XML in the part into an XDocument instance.  
                    styleDoc = XDocument.Load(XmlReader.Create(stylePart.GetStream()));  
                }  
            }  
        }  
  
        string defaultStyle =  
            (string)(  
                from style in styleDoc.Root.Elements(w + "style")  
                where (string)style.Attribute(w + "type") == "paragraph" &&  
                      (string)style.Attribute(w + "default") == "1"  
                select style  
            ).First().Attribute(w + "styleId");  
  
        // Find all paragraphs in the document.  
        var paragraphs =  
            from para in xDoc  
                         .Root  
                         .Element(w + "body")  
                         .Descendants(w + "p")  
            let styleNode = para  
                            .Elements(w + "pPr")  
                            .Elements(w + "pStyle")  
                            .FirstOrDefault()  
            select new  
            {  
                ParagraphNode = para,  
                StyleName = styleNode != null ?  
                    (string)styleNode.Attribute(w + "val") :  
                    defaultStyle  
            };  
  
        // Retrieve the text of each paragraph.  
        var paraWithText =  
            from para in paragraphs  
            select new  
            {  
                ParagraphNode = para.ParagraphNode,  
                StyleName = para.StyleName,  
                Text = ParagraphText(para.ParagraphNode)  
            };  
  
        foreach (var p in paraWithText)  
            Console.WriteLine("StyleName:{0} >{1}<", p.StyleName, p.Text);  
    }  
}  
```

此示例生成与重构前相同的输出：

```
StyleName:Heading1 >Parsing WordprocessingML with LINQ to XML<  
StyleName:Normal ><  
StyleName:Normal >The following example prints to the console.<  
StyleName:Normal ><  
StyleName:Code >using System;<  
StyleName:Code ><  
StyleName:Code >class Program {<  
StyleName:Code >    public static void (string[] args) {<  
StyleName:Code >        Console.WriteLine("Hello World");<  
StyleName:Code >    }<  
StyleName:Code >}<  
StyleName:Normal ><  
StyleName:Normal >This example produces the following output:<  
StyleName:Normal ><  
StyleName:Code >Hello World<  
```

#### 后续步骤

下面的示例演示如何将 XML 投影到一个不同的形状：

- [对不同形状的 XML 进行投影 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/projecting-xml-in-a-different-shape)

### [Projecting XML in a Different Shape](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/projectingxmlinadifferentshape)

本主题演示对形状不同于源 XML 的 XML 进行投影的示例。

许多典型的 XML 转换由链接的查询组成，如本示例中所示。 一种很常见的做法是从某种格式的 XML 开始，将中间结果投影为匿名类型或命名类型的集合，最后将结果投影回与源 XML 形状完全不同的 XML。

#### 示例

本示例处理一个 WordprocessingML 文档，它从 WordprocessingML 文档中检索段落节点。 本示例还标识每个段落的样式和文本。 最后，本示例将以不同的形状投影 XML。 本示例以本教程中前面的一些示例为基础构建。 下面代码中的注释标识出了执行投影操作的新语句。

有关创建此示例的源文档的说明，请参阅[创建源 Office Open XML 文档 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/creating-the-source-office-open-xml-document)。

本示例使用 WindowsBase 程序集中的类。 它使用 [System.IO.Packaging](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging) 命名空间中的类型。

```csharp
public static class LocalExtensions  
{  
    public static string StringConcatenate(this IEnumerable<string> source)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (string s in source)  
            sb.Append(s);  
        return sb.ToString();  
    }  
  
    public static string StringConcatenate<T>(this IEnumerable<T> source,  
        Func<T, string> func)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (T item in source)  
            sb.Append(func(item));  
        return sb.ToString();  
    }  
  
    public static string StringConcatenate(this IEnumerable<string> source, string separator)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (string s in source)  
            sb.Append(s).Append(separator);  
        return sb.ToString();  
    }  
  
    public static string StringConcatenate<T>(this IEnumerable<T> source,  
        Func<T, string> func, string separator)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (T item in source)  
            sb.Append(func(item)).Append(separator);  
        return sb.ToString();  
    }  
}  
  
class Program  
{  
    public static string ParagraphText(XElement e)  
    {  
        XNamespace w = e.Name.Namespace;  
        return e  
               .Elements(w + "r")  
               .Elements(w + "t")  
               .StringConcatenate(element => (string)element);  
    }  
  
    static void Main(string[] args)  
    {  
        const string fileName = "SampleDoc.docx";  
  
        const string documentRelationshipType =  
          "http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument";  
        const string stylesRelationshipType =  
          "http://schemas.openxmlformats.org/officeDocument/2006/relationships/styles";  
        const string wordmlNamespace =  
          "http://schemas.openxmlformats.org/wordprocessingml/2006/main";  
        XNamespace w = wordmlNamespace;  
  
        XDocument xDoc = null;  
        XDocument styleDoc = null;  
  
        using (Package wdPackage = Package.Open(fileName, FileMode.Open, FileAccess.Read))  
        {  
            PackageRelationship docPackageRelationship =  
              wdPackage.GetRelationshipsByType(documentRelationshipType).FirstOrDefault();  
            if (docPackageRelationship != null)  
            {  
                Uri documentUri = PackUriHelper.ResolvePartUri(new Uri("/", UriKind.Relative),  
                  docPackageRelationship.TargetUri);  
                PackagePart documentPart = wdPackage.GetPart(documentUri);  
  
                //  Load the document XML in the part into an XDocument instance.  
                xDoc = XDocument.Load(XmlReader.Create(documentPart.GetStream()));  
  
                //  Find the styles part. There will only be one.  
                PackageRelationship styleRelation =  
                  documentPart.GetRelationshipsByType(stylesRelationshipType).FirstOrDefault();  
                if (styleRelation != null)  
                {  
                    Uri styleUri =  
                      PackUriHelper.ResolvePartUri(documentUri, styleRelation.TargetUri);  
                    PackagePart stylePart = wdPackage.GetPart(styleUri);  
  
                    //  Load the style XML in the part into an XDocument instance.  
                    styleDoc = XDocument.Load(XmlReader.Create(stylePart.GetStream()));  
                }  
            }  
        }  
  
        string defaultStyle =  
            (string)(  
                from style in styleDoc.Root.Elements(w + "style")  
                where (string)style.Attribute(w + "type") == "paragraph" &&  
                      (string)style.Attribute(w + "default") == "1"  
                select style  
            ).First().Attribute(w + "styleId");  
  
        // Find all paragraphs in the document.  
        var paragraphs =  
            from para in xDoc  
                         .Root  
                         .Element(w + "body")  
                         .Descendants(w + "p")  
            let styleNode = para  
                            .Elements(w + "pPr")  
                            .Elements(w + "pStyle")  
                            .FirstOrDefault()  
            select new  
            {  
                ParagraphNode = para,  
                StyleName = styleNode != null ?  
                    (string)styleNode.Attribute(w + "val") :  
                    defaultStyle  
            };  
  
        // Retrieve the text of each paragraph.  
        var paraWithText =  
            from para in paragraphs  
            select new  
            {  
                ParagraphNode = para.ParagraphNode,  
                StyleName = para.StyleName,  
                Text = ParagraphText(para.ParagraphNode)  
            };  
  
        // The following is the new code that projects XML in a new shape.  
        XElement root = new XElement("Root",  
            from p in paraWithText  
            select new XElement("Paragraph",  
                new XElement("StyleName", p.StyleName),  
                new XElement("Text", p.Text)  
            )  
        );  
  
        Console.WriteLine(root);  
    }  
}  
```

该示例产生下面的输出：

```xml
<Root>  
  <Paragraph>  
    <StyleName>Heading1</StyleName>  
    <Text>Parsing WordprocessingML with LINQ to XML</Text>  
  </Paragraph>  
  <Paragraph>  
    <StyleName>Normal</StyleName>  
    <Text></Text>  
  </Paragraph>  
  <Paragraph>  
    <StyleName>Normal</StyleName>  
    <Text>The following example prints to the console.</Text>  
  </Paragraph>  
  <Paragraph>  
    <StyleName>Normal</StyleName>  
    <Text></Text>  
  </Paragraph>  
  <Paragraph>  
    <StyleName>Code</StyleName>  
    <Text>using System;</Text>  
  </Paragraph>  
  <Paragraph>  
    <StyleName>Code</StyleName>  
    <Text></Text>  
  </Paragraph>  
  <Paragraph>  
    <StyleName>Code</StyleName>  
    <Text>class Program {</Text>  
  </Paragraph>  
  <Paragraph>  
    <StyleName>Code</StyleName>  
    <Text>    public static void (string[] args) {</Text>  
  </Paragraph>  
  <Paragraph>  
    <StyleName>Code</StyleName>  
    <Text>        Console.WriteLine("Hello World");</Text>  
  </Paragraph>  
  <Paragraph>  
    <StyleName>Code</StyleName>  
    <Text>    }</Text>  
  </Paragraph>  
  <Paragraph>  
    <StyleName>Code</StyleName>  
    <Text>}</Text>  
  </Paragraph>  
  <Paragraph>  
    <StyleName>Normal</StyleName>  
    <Text></Text>  
  </Paragraph>  
  <Paragraph>  
    <StyleName>Normal</StyleName>  
    <Text>This example produces the following output:</Text>  
  </Paragraph>  
  <Paragraph>  
    <StyleName>Normal</StyleName>  
    <Text></Text>  
  </Paragraph>  
  <Paragraph>  
    <StyleName>Code</StyleName>  
    <Text>Hello World</Text>  
  </Paragraph>  
</Root>  
```

#### 后续步骤

下面的示例通过查询查找 Word 文档中的所有文本：

- [查找 Word 文档中的文本 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/finding-text-in-word-documents)

### [Finding Text in Word Documents](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/findingtextinworddocuments)

本主题扩展了以前的查询，以执行一些有用的任务：在文档中查找一个字符串的所有匹配项。

#### 示例

本示例处理一个 WordprocessingML 文档，在该文档中查找特定文本片断的所有匹配项。 为演示此操作，我们使用一个查询，查找字符串“Hello”。 本示例以本教程中前面的一些示例为基础构建。 下面代码中的注释标识出了这个新查询。

有关创建此示例的源文档的说明，请参阅[创建源 Office Open XML 文档 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/creating-the-source-office-open-xml-document)。

本示例使用 WindowsBase 程序集中的类。 它使用 [System.IO.Packaging](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging) 命名空间中的类型。

```csharp
public static class LocalExtensions  
{  
    public static string StringConcatenate(this IEnumerable<string> source)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (string s in source)  
            sb.Append(s);  
        return sb.ToString();  
    }  
  
    public static string StringConcatenate<T>(this IEnumerable<T> source,  
        Func<T, string> func)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (T item in source)  
            sb.Append(func(item));  
        return sb.ToString();  
    }  
  
    public static string StringConcatenate(this IEnumerable<string> source, string separator)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (string s in source)  
            sb.Append(s).Append(separator);  
        return sb.ToString();  
    }  
  
    public static string StringConcatenate<T>(this IEnumerable<T> source,  
        Func<T, string> func, string separator)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (T item in source)  
            sb.Append(func(item)).Append(separator);  
        return sb.ToString();  
    }  
}  
  
class Program  
{  
    public static string ParagraphText(XElement e)  
    {  
        XNamespace w = e.Name.Namespace;  
        return e  
               .Elements(w + "r")  
               .Elements(w + "t")  
               .StringConcatenate(element => (string)element);  
    }  
  
    static void Main(string[] args)  
    {  
        const string fileName = "SampleDoc.docx";  
  
        const string documentRelationshipType =  
          "http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument";  
        const string stylesRelationshipType =  
          "http://schemas.openxmlformats.org/officeDocument/2006/relationships/styles";  
        const string wordmlNamespace =  
          "http://schemas.openxmlformats.org/wordprocessingml/2006/main";  
        XNamespace w = wordmlNamespace;  
  
        XDocument xDoc = null;  
        XDocument styleDoc = null;  
  
        using (Package wdPackage = Package.Open(fileName, FileMode.Open, FileAccess.Read))  
        {  
            PackageRelationship docPackageRelationship =  
              wdPackage.GetRelationshipsByType(documentRelationshipType).FirstOrDefault();  
            if (docPackageRelationship != null)  
            {  
                Uri documentUri = PackUriHelper.ResolvePartUri(new Uri("/", UriKind.Relative),  
                  docPackageRelationship.TargetUri);  
                PackagePart documentPart = wdPackage.GetPart(documentUri);  
  
                //  Load the document XML in the part into an XDocument instance.  
                xDoc = XDocument.Load(XmlReader.Create(documentPart.GetStream()));  
  
                //  Find the styles part. There will only be one.  
                PackageRelationship styleRelation =  
                  documentPart.GetRelationshipsByType(stylesRelationshipType).FirstOrDefault();  
                if (styleRelation != null)  
                {  
                    Uri styleUri =  
                      PackUriHelper.ResolvePartUri(documentUri, styleRelation.TargetUri);  
                    PackagePart stylePart = wdPackage.GetPart(styleUri);  
  
                    //  Load the style XML in the part into an XDocument instance.  
                    styleDoc = XDocument.Load(XmlReader.Create(stylePart.GetStream()));  
                }  
            }  
        }  
  
        string defaultStyle =  
            (string)(  
                from style in styleDoc.Root.Elements(w + "style")  
                where (string)style.Attribute(w + "type") == "paragraph" &&  
                      (string)style.Attribute(w + "default") == "1"  
                select style  
            ).First().Attribute(w + "styleId");  
  
        // Find all paragraphs in the document.  
        var paragraphs =  
            from para in xDoc  
                         .Root  
                         .Element(w + "body")  
                         .Descendants(w + "p")  
            let styleNode = para  
                            .Elements(w + "pPr")  
                            .Elements(w + "pStyle")  
                            .FirstOrDefault()  
            select new  
            {  
                ParagraphNode = para,  
                StyleName = styleNode != null ?  
                    (string)styleNode.Attribute(w + "val") :  
                    defaultStyle  
            };  
  
        // Retrieve the text of each paragraph.  
        var paraWithText =  
            from para in paragraphs  
            select new  
            {  
                ParagraphNode = para.ParagraphNode,  
                StyleName = para.StyleName,  
                Text = ParagraphText(para.ParagraphNode)  
            };  
  
        // Following is the new query that retrieves all paragraphs  
        // that have specific text in them.  
        var helloParagraphs =  
            from para in paraWithText  
            where para.Text.Contains("Hello")  
            select new  
            {  
                ParagraphNode = para.ParagraphNode,  
                StyleName = para.StyleName,  
                Text = para.Text  
            };  
  
        foreach (var p in helloParagraphs)  
            Console.WriteLine("StyleName:{0} >{1}<", p.StyleName, p.Text);  
    }  
}  
```

该示例产生下面的输出：

```
StyleName:Code >        Console.WriteLine("Hello World");<  
StyleName:Code >Hello World<  
```

当然，您可以修改搜索条件，使它搜索具有特定样式的行。 下面的查询查找具有“Code”样式的所有空行：

```csharp
public static class LocalExtensions  
{  
    public static string StringConcatenate(this IEnumerable<string> source)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (string s in source)  
            sb.Append(s);  
        return sb.ToString();  
    }  
  
    public static string StringConcatenate<T>(this IEnumerable<T> source,  
        Func<T, string> func)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (T item in source)  
            sb.Append(func(item));  
        return sb.ToString();  
    }  
  
    public static string StringConcatenate(this IEnumerable<string> source, string separator)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (string s in source)  
            sb.Append(s).Append(separator);  
        return sb.ToString();  
    }  
  
    public static string StringConcatenate<T>(this IEnumerable<T> source,  
        Func<T, string> func, string separator)  
    {  
        StringBuilder sb = new StringBuilder();  
        foreach (T item in source)  
            sb.Append(func(item)).Append(separator);  
        return sb.ToString();  
    }  
}  
  
class Program  
{  
    public static string ParagraphText(XElement e)  
    {  
        XNamespace w = e.Name.Namespace;  
        return e  
               .Elements(w + "r")  
               .Elements(w + "t")  
               .StringConcatenate(element => (string)element);  
    }  
  
    static void Main(string[] args)  
    {  
        const string fileName = "SampleDoc.docx";  
  
        const string documentRelationshipType = "http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument";  
        const string stylesRelationshipType = "http://schemas.openxmlformats.org/officeDocument/2006/relationships/styles";  
        const string wordmlNamespace = "http://schemas.openxmlformats.org/wordprocessingml/2006/main";  
        XNamespace w = wordmlNamespace;  
  
        XDocument xDoc = null;  
        XDocument styleDoc = null;  
  
        using (Package wdPackage = Package.Open(fileName, FileMode.Open, FileAccess.Read))  
        {  
            PackageRelationship docPackageRelationship = wdPackage.GetRelationshipsByType(documentRelationshipType).FirstOrDefault();  
            if (docPackageRelationship != null)  
            {  
                Uri documentUri = PackUriHelper.ResolvePartUri(new Uri("/", UriKind.Relative), docPackageRelationship.TargetUri);  
                PackagePart documentPart = wdPackage.GetPart(documentUri);  
  
                //  Load the document XML in the part into an XDocument instance.  
                xDoc = XDocument.Load(XmlReader.Create(documentPart.GetStream()));  
  
                //  Find the styles part. There will only be one.  
                PackageRelationship styleRelation = documentPart.GetRelationshipsByType(stylesRelationshipType).FirstOrDefault();  
                if (styleRelation != null)  
                {  
                    Uri styleUri = PackUriHelper.ResolvePartUri(documentUri, styleRelation.TargetUri);  
                    PackagePart stylePart = wdPackage.GetPart(styleUri);  
  
                    //  Load the style XML in the part into an XDocument instance.  
                    styleDoc = XDocument.Load(XmlReader.Create(stylePart.GetStream()));  
                }  
            }  
        }  
  
        string defaultStyle =  
            (string)(  
                from style in styleDoc.Root.Elements(w + "style")  
                where (string)style.Attribute(w + "type") == "paragraph" &&  
                      (string)style.Attribute(w + "default") == "1"  
                select style  
            ).First().Attribute(w + "styleId");  
  
        // Find all paragraphs in the document.  
        var paragraphs =  
            from para in xDoc  
                         .Root  
                         .Element(w + "body")  
                         .Descendants(w + "p")  
            let styleNode = para  
                            .Elements(w + "pPr")  
                            .Elements(w + "pStyle")  
                            .FirstOrDefault()  
            select new  
            {  
                ParagraphNode = para,  
                StyleName = styleNode != null ?  
                    (string)styleNode.Attribute(w + "val") :  
                    defaultStyle  
            };  
  
        // Retrieve the text of each paragraph.  
        var paraWithText =  
            from para in paragraphs  
            select new  
            {  
                ParagraphNode = para.ParagraphNode,  
                StyleName = para.StyleName,  
                Text = ParagraphText(para.ParagraphNode)  
            };  
  
        // Retrieve all paragraphs that have no text and are styled Code.  
        var blankCodeParagraphs =  
            from para in paraWithText  
            where para.Text == "" && para.StyleName == "Code"  
            select new  
            {  
                ParagraphNode = para.ParagraphNode,  
                StyleName = para.StyleName,  
                Text = para.Text  
            };  
  
        foreach (var p in blankCodeParagraphs)  
            Console.WriteLine("StyleName:{0} >{1}<", p.StyleName, p.Text);  
    }  
}  
```

该示例产生下面的输出：

```
StyleName:Code ><  
```

当然，可以通过多种方式对此示例进行改进。 例如，可以使用正则表达式来搜索文本，可以循环访问某一特定目录下的所有 Word 文件等等。

请注意，此示例的执行效果与将它编写为一个单个查询几乎同样好。 因为每个查询都以迟缓方式实现，每个查询直到循环到该查询时才生成结果。 有关执行和迟缓计算的详细信息，请参阅 [LINQ to XML 中的延迟执行和迟缓计算 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/deferred-execution-and-lazy-evaluation-in-linq-to-xml)。

#### 后续步骤

下一节提供有关 WordprocessingML 文档的更多信息：

- [Office Open XML WordprocessingML 文档的详细信息 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/details-of-office-open-xml-wordprocessingml-documents)

### [Details of Office Open XML WordprocessingML Documents](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/detailsofofficeopenxmlwordprocessingmldocuments)

本节提供有关 Office Open XML WordprocessingML 文档详情的信息。 它演示 Open XML 文档的文档和样式部分的示例。

#### 本节内容

| 主题                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [具有样式的 WordprocessingML 文档](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/wordprocessingml-document-with-styles) | 演示 Office Open XML WordprocessingML 文档的文档部分。       |
| [WordprocessingML 文档的样式部件](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/style-part-of-a-wordprocessingml-document) | 演示 Office Open XML WordprocessingML 文档的样式部分。       |
| [输出 Office Open XML 文档部件的示例 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/example-that-outputs-office-open-xml-document-parts) | 提供一个打开 Office Open XML WordprocessingML 文档，并将文档和样式部分输出到控制台的示例。 |

#### [WordprocessingML Document with Styles](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/wordprocessingmldocumentwithstyles)

较为复杂的 WordprocessingML 文档具有使用样式格式的段落。

对 WordprocessingML 文档的结构做一些注释是很有帮助的。 WordprocessingML 文档存储在包中。 包具有多个部分（“部分”在包上下文中具有明确的意义，部分实质上是压缩在一起组成包的多个文件）。 如果一个文档包含使用样式格式的段落，将会有一个文档部分包含应用了样式的段落。 还会有一个样式部分包含文档引用的样式。

访问包时，重要的是通过部分之间的关系来访问包，而不是使用任意路径来访问包。 此问题超出了在 WordprocessingML 文档教程中使用内容的范围，但是本教程包含的示例程序演示了正确的方法。

##### 使用样式的文档

[WordprocessingML 文档的形状 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/shape-of-wordprocessingml-documents) 主题中提供的 WordML 示例是非常简单的文档。 以下文档更复杂：它具有使用样式格式的段落。 查看构成 Office Open XML 文档的 XML 的最简单方法是，运行[输出 Office Open XML 文档部件的示例 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/example-that-outputs-office-open-xml-document-parts)。

在下面的文档中，第一段具有 `Heading1` 样式。 很多段落具有默认样式。 还有一些段落具有 `Code` 样式。 由于这种相对复杂性，这个文档更值得使用 LINQ to XML 来解析。

在那些使用非默认样式的段落中，段落元素具有名为 `w:pPr` 的子元素，该子元素又具有子元素 `w:pStyle`。 该元素具有属性 `w:val`，该属性包含样式名称。 如果段落具有默认样式，则意味着段落元素不具有 `w:p.Pr` 子元素。

```xml
<?xml version="1.0" encoding="utf-8"?>  
<w:document  
    xmlns:ve="http://schemas.openxmlformats.org/markup-compatibility/2006"  
    xmlns:o="urn:schemas-microsoft-com:office:office"  
    xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships"  
    xmlns:m="http://schemas.openxmlformats.org/officeDocument/2006/math"  
    xmlns:v="urn:schemas-microsoft-com:vml"  
    xmlns:wp="http://schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing"  
    xmlns:w10="urn:schemas-microsoft-com:office:word"  
    xmlns:w="http://schemas.openxmlformats.org/wordprocessingml/2006/main"  
    xmlns:wne="http://schemas.microsoft.com/office/word/2006/wordml">  
  <w:body>  
    <w:p w:rsidR="00A75AE0" w:rsidRDefault="00A75AE0" w:rsidP="006027C7">  
      <w:pPr>  
        <w:pStyle w:val="Heading1" />  
      </w:pPr>  
      <w:r>  
        <w:t>Parsing WordprocessingML with LINQ to XML</w:t>  
      </w:r>  
    </w:p>  
    <w:p w:rsidR="00A75AE0" w:rsidRDefault="00A75AE0" />  
    <w:p w:rsidR="00A75AE0" w:rsidRDefault="00A75AE0">  
      <w:r>  
        <w:t>The following example prints to the console.</w:t>  
      </w:r>  
    </w:p>  
    <w:p w:rsidR="00A75AE0" w:rsidRDefault="00A75AE0" />  
    <w:p w:rsidR="00A75AE0" w:rsidRDefault="00A75AE0" w:rsidP="006027C7">  
      <w:pPr>  
        <w:pStyle w:val="Code" />  
      </w:pPr>  
      <w:r>  
        <w:t>using System;</w:t>  
      </w:r>  
    </w:p>  
    <w:p w:rsidR="00A75AE0" w:rsidRDefault="00A75AE0" w:rsidP="006027C7">  
      <w:pPr>  
        <w:pStyle w:val="Code" />  
      </w:pPr>  
    </w:p>  
    <w:p w:rsidR="00A75AE0" w:rsidRPr="00876F34" w:rsidRDefault="00A75AE0" w:rsidP="006027C7">  
      <w:pPr>  
        <w:pStyle w:val="Code" />  
      </w:pPr>  
      <w:r w:rsidRPr="00876F34">  
        <w:t>class Program {</w:t>  
      </w:r>  
    </w:p>  
    <w:p w:rsidR="00A75AE0" w:rsidRPr="00876F34" w:rsidRDefault="00A75AE0" w:rsidP="006027C7">  
      <w:pPr>  
        <w:pStyle w:val="Code" />  
      </w:pPr>  
      <w:r w:rsidRPr="00876F34">  
        <w:t xml:space="preserve">    public static void </w:t>  
      </w:r>  
      <w:smartTag w:uri="urn:schemas-microsoft-com:office:smarttags" w:element="place">  
        <w:r w:rsidRPr="00876F34">  
          <w:t>Main</w:t>  
        </w:r>  
      </w:smartTag>  
      <w:r w:rsidRPr="00876F34">  
        <w:t>(string[] args) {</w:t>  
      </w:r>  
    </w:p>  
    <w:p w:rsidR="00A75AE0" w:rsidRPr="00876F34" w:rsidRDefault="00A75AE0" w:rsidP="006027C7">  
      <w:pPr>  
        <w:pStyle w:val="Code" />  
      </w:pPr>  
      <w:r w:rsidRPr="00876F34">  
        <w:t xml:space="preserve">        Console.WriteLine("Hello World");</w:t>  
      </w:r>  
    </w:p>  
    <w:p w:rsidR="00A75AE0" w:rsidRPr="00876F34" w:rsidRDefault="00A75AE0" w:rsidP="006027C7">  
      <w:pPr>  
        <w:pStyle w:val="Code" />  
      </w:pPr>  
      <w:r w:rsidRPr="00876F34">  
        <w:t xml:space="preserve">    }</w:t>  
      </w:r>  
    </w:p>  
    <w:p w:rsidR="00A75AE0" w:rsidRPr="00876F34" w:rsidRDefault="00A75AE0" w:rsidP="006027C7">  
      <w:pPr>  
        <w:pStyle w:val="Code" />  
      </w:pPr>  
      <w:r w:rsidRPr="00876F34">  
        <w:t>}</w:t>  
      </w:r>  
    </w:p>  
    <w:p w:rsidR="00A75AE0" w:rsidRDefault="00A75AE0" />  
    <w:p w:rsidR="00A75AE0" w:rsidRDefault="00A75AE0">  
      <w:r>  
        <w:t>This example produces the following output:</w:t>  
      </w:r>  
    </w:p>  
    <w:p w:rsidR="00A75AE0" w:rsidRDefault="00A75AE0" />  
    <w:p w:rsidR="00A75AE0" w:rsidRDefault="00A75AE0" w:rsidP="006027C7">  
      <w:pPr>  
        <w:pStyle w:val="Code" />  
      </w:pPr>  
      <w:r>  
        <w:t>Hello World</w:t>  
      </w:r>  
    </w:p>  
    <w:sectPr w:rsidR="00A75AE0" w:rsidSect="00A75AE0">  
      <w:pgSz w:w="12240" w:h="15840" />  
      <w:pgMar w:top="1440" w:right="1800" w:bottom="1440" w:left="1800" w:header="720" w:footer="720" w:gutter="0" />  
      <w:cols w:space="720" />  
      <w:docGrid w:linePitch="360" />  
    </w:sectPr>  
  </w:body>  
</w:document>  
```

#### [Style Part of a WordprocessingML Document](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/stylepartofawordprocessingmldocument)

本主题演示 Office Open XML WordprocessingML 文档的样式部分的示例。

##### 示例

下面的示例是构成 Office Open XML WordprocessingML 文档的样式部分的 XML。

默认段落样式有一个具有下面开始标记的元素：

```xml
<w:style w:type="paragraph" w:default="1" w:styleId="Normal">  
```

在编写用于查找默认样式标识符的查询时需要知道此信息，以便查询能够识别具有默认样式的段落的样式。

请注意，与 Microsoft Word 生成的典型文档相比，这些文档非常简单。 在许多情况下，Word 会保存大量附加信息、附加格式设置和元数据。 而且，Word 不会将行设置为像本示例这样易于阅读的格式；而在保存 XML 时不会带缩进。 不过，所有 WordprocessingML 文档都具有相同的基本 XML 形状。 因此，本教程中演示的查询将适用于更复杂的文档。

```xml
<?xml version="1.0" encoding="utf-8"?>  
<w:styles  
    xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships"  
    xmlns:w="http://schemas.openxmlformats.org/wordprocessingml/2006/main">  
  <w:docDefaults>  
    <w:rPrDefault>  
      <w:rPr>  
        <w:rFonts  
            w:ascii="Times New Roman"  
            w:eastAsia="Times New Roman"  
            w:hAnsi="Times New Roman"  
            w:cs="Times New Roman" />  
        <w:sz w:val="22" />  
        <w:szCs w:val="22" />  
        <w:lang w:val="en-US" w:eastAsia="en-US" w:bidi="ar-SA" />  
      </w:rPr>  
    </w:rPrDefault>  
    <w:pPrDefault />  
  </w:docDefaults>  
  <w:style w:type="paragraph" w:default="1" w:styleId="Normal">  
    <w:name w:val="Normal" />  
    <w:qFormat />  
    <w:rPr>  
      <w:sz w:val="24" />  
      <w:szCs w:val="24" />  
    </w:rPr>  
  </w:style>  
  <w:style w:type="paragraph" w:styleId="Heading1">  
    <w:name w:val="heading 1" />  
    <w:basedOn w:val="Normal" />  
    <w:next w:val="Normal" />  
    <w:link w:val="Heading1Char" />  
    <w:uiPriority w:val="99" />  
    <w:qFormat />  
    <w:rsid w:val="006027C7" />  
    <w:pPr>  
      <w:keepNext />  
      <w:spacing w:before="240" w:after="60" />  
      <w:outlineLvl w:val="0" />  
    </w:pPr>  
    <w:rPr>  
      <w:rFonts w:ascii="Arial" w:hAnsi="Arial" w:cs="Arial" />  
      <w:b />  
      <w:bCs />  
      <w:kern w:val="32" />  
      <w:sz w:val="32" />  
      <w:szCs w:val="32" />  
    </w:rPr>  
  </w:style>  
  <w:style w:type="character" w:default="1" w:styleId="DefaultParagraphFont">  
    <w:name w:val="Default Paragraph Font" />  
    <w:uiPriority w:val="99" />  
    <w:semiHidden />  
  </w:style>  
  <w:style w:type="table" w:default="1" w:styleId="TableNormal">  
    <w:name w:val="Normal Table" />  
    <w:uiPriority w:val="99" />  
    <w:semiHidden />  
    <w:unhideWhenUsed />  
    <w:qFormat />  
    <w:tblPr>  
      <w:tblInd w:w="0" w:type="dxa" />  
      <w:tblCellMar>  
        <w:top w:w="0" w:type="dxa" />  
        <w:left w:w="108" w:type="dxa" />  
        <w:bottom w:w="0" w:type="dxa" />  
        <w:right w:w="108" w:type="dxa" />  
      </w:tblCellMar>  
    </w:tblPr>  
  </w:style>  
  <w:style w:type="numbering" w:default="1" w:styleId="NoList">  
    <w:name w:val="No List" />  
    <w:uiPriority w:val="99" />  
    <w:semiHidden />  
    <w:unhideWhenUsed />  
  </w:style>  
  <w:style w:type="character" w:customStyle="1" w:styleId="Heading1Char">  
    <w:name w:val="Heading 1 Char" />  
    <w:basedOn w:val="DefaultParagraphFont" />  
    <w:link w:val="Heading1" />  
    <w:uiPriority w:val="9" />  
    <w:rsid w:val="009765E3" />  
    <w:rPr>  
      <w:rFonts  
          w:asciiTheme="majorHAnsi"  
          w:eastAsiaTheme="majorEastAsia"  
          w:hAnsiTheme="majorHAnsi"  
          w:cstheme="majorBidi" />  
      <w:b />  
      <w:bCs />  
      <w:kern w:val="32" />  
      <w:sz w:val="32" />  
      <w:szCs w:val="32" />  
    </w:rPr>  
  </w:style>  
  <w:style w:type="paragraph" w:customStyle="1" w:styleId="Code">  
    <w:name w:val="Code" />  
    <w:aliases w:val="c" />  
    <w:uiPriority w:val="99" />  
    <w:rsid w:val="006027C7" />  
    <w:pPr>  
      <w:spacing w:after="60" w:line="300" w:lineRule="exact" />  
    </w:pPr>  
    <w:rPr>  
      <w:rFonts w:ascii="Courier New" w:hAnsi="Courier New" />  
      <w:noProof />  
      <w:color w:val="000080" />  
      <w:sz w:val="20" />  
      <w:szCs w:val="20" />  
    </w:rPr>  
  </w:style>  
</w:styles>  
```

#### [Example that Outputs Office Open XML Document Parts](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/examplethatoutputsofficeopenxmldocumentparts)

本主题演示如何打开 Office Open XML 文档并访问其中的部分。

##### 示例

下面的示例打开 Office Open XML 文档，并将文档部分和样式部分输出到控制台。

本示例使用 WindowsBase 程序集中的类。 它使用 [System.IO.Packaging](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.packaging) 命名空间中的类型。

```csharp
const string fileName = "SampleDoc.docx";  
  
const string documentRelationshipType =  
  "http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument";  
const string stylesRelationshipType =  
  "http://schemas.openxmlformats.org/officeDocument/2006/relationships/styles";  
const string wordmlNamespace =  
  "http://schemas.openxmlformats.org/wordprocessingml/2006/main";  
XNamespace w = wordmlNamespace;  
  
using (Package wdPackage = Package.Open(fileName, FileMode.Open, FileAccess.Read))  
{  
    PackageRelationship docPackageRelationship =  
      wdPackage.GetRelationshipsByType(documentRelationshipType).FirstOrDefault();  
    if (docPackageRelationship != null)  
    {  
        Uri documentUri = PackUriHelper.ResolvePartUri(new Uri("/", UriKind.Relative),  
          docPackageRelationship.TargetUri);  
        PackagePart documentPart = wdPackage.GetPart(documentUri);  
  
        //  Load the document XML in the part into an XDocument instance.  
        XDocument xdoc = XDocument.Load(XmlReader.Create(documentPart.GetStream()));  
  
        Console.WriteLine("TargetUri:{0}", docPackageRelationship.TargetUri);  
        Console.WriteLine("==================================================================");  
        Console.WriteLine(xdoc.Root);  
        Console.WriteLine();  
  
        //  Find the styles part. There will only be one.  
        PackageRelationship styleRelation =  
          documentPart.GetRelationshipsByType(stylesRelationshipType).FirstOrDefault();  
        if (styleRelation != null)  
        {  
            Uri styleUri = PackUriHelper.ResolvePartUri(documentUri, styleRelation.TargetUri);  
            PackagePart stylePart = wdPackage.GetPart(styleUri);  
  
            //  Load the style XML in the part into an XDocument instance.  
            XDocument styleDoc = XDocument.Load(XmlReader.Create(stylePart.GetStream()));  
  
            Console.WriteLine("TargetUri:{0}", styleRelation.TargetUri);  
            Console.WriteLine("==================================================================");  
            Console.WriteLine(styleDoc.Root);  
            Console.WriteLine();  
        }  
    }  
}  
```