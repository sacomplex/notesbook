[C# programming guide](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/index)

# Language Sections

## [XML Documentation Comments](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/xmldoc/xml-documentation-comments)

在 Visual C# 中，你可以通过以下方式为代码创建文档：将特殊注释字段中的 XML 元素包含在源代码中注释引用的代码块的前面，例如：

```csharp
/// <summary>  
///  This class performs an important function.  
/// </summary>  
public class MyClass {}  
```

使用 [/doc](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/doc-compiler-option) 选项进行编译时，编译器会在源代码中搜索所有 XML 标记，并创建一个 XML 文档文件。 若要基于编译器生成的文件创建最终文档，可以创建一个自定义工具，也可以使用 [Sandcastle](https://github.com/EWSoftware/SHFB) 或 [DocFX](https://dotnet.github.io/docfx/) 等工具。

若要引用 XML 元素（例如，你的函数将处理你要在 XML 文档注释中描述的特定 XML 元素），你可使用标准引用机制（`<` 和 `>`）。 若要引用代码引用 (`cref`) 元素中的通用标识符，可使用转义字符（例如，`cref="List&lt;T&gt;"`）或大括号 (`cref="List{T}"`)。 作为特例，编译器会将大括号解析为尖括号以在引用通用标识符时使作者能够更轻松地进行文档注释。

> XML 文档注释不是元数据；它们不包括在编译的程序集中，因此无法通过反射对其进行访问。

### [Recommended Tags for Documentation Comments](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/xmldoc/recommended-tags-for-documentation-comments)

C# 编译器处理代码中的文档注释，并在文件中将其设置为 XML 格式，该文件的名称通过 /doc 命令行选项指定。若要基于编译器生成的文件创建最终文档，可以创建一个自定义工具，也可以使用 [Sandcastle](https://github.com/EWSoftware/SHFB) 等工具。

在类型和类型成员等代码构造中处理标记。

 备注

不可对命名空间应用文档注释。

编译器将处理属于有效 XML 形式的任何标记。 下列标记提供用户文档的中常用功能。

#### Tags

|                                                              |                                                              |                                                              |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| [`<c>`](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/code-inline) | [`<para>`](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/para) | [`<see>*`](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/see) |
| [`<code>`](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/code) | [`<param>*`](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/param) | [`<seealso>*`](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/seealso) |
| [`<example>`](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/example) | [`<paramref>`](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/paramref) | [`<summary>`](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/summary) |
| [`<exception>*`](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/exception) | [`<permission>*`](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/permission) | [`<typeparam>*`](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/typeparam) |
| [`<include>*`](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/include) | [`<remarks>`](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/remarks) | [`<typeparamref>`](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/typeparamref) |
| [`<list>`](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/list) | [`<returns>`](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/returns) | [`<value>`](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/value) |

（* 表示编译器验证语法。）

如果希望在文档注释的文本中显示尖括号，请使用 `<` 和 `>`，如下例所示。

```csharp
/// <summary cref="C < T >">  
/// </summary>  
```

#### [<c>](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/code-inline)

- 语法

```xml
<c>text</c>  
```

- 参数

`text`
要指示为代码的文本。

- 备注

使用 <c> 标记可以指示应将说明内的文本标记为代码。 使用 [](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/code) 指示作为代码的多行文本。

使用 [/doc](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/doc-compiler-option) 进行编译可以将文档注释处理到文件中。

- 示例

```csharp
// compile with: -doc:DocFileName.xml 

/// text for class TestClass
public class TestClass
{
    /// <summary><c>DoWork</c> is a method in the <c>TestClass</c> class.
    /// </summary>
    public static void DoWork(int Int1)
    {
    }

    /// text for Main
    static void Main()
    {
    }
}
```

#### [<code>](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/code)

- 语法

```xml
<code>content</code>  
```

- 参数

`content`
要标记为代码的文本。

- 备注

<code> 标记可将多行内容指示为代码。 使用 <c> 指示应将说明内的文本标记为代码。

使用 [/doc](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/doc-compiler-option) 进行编译可以将文档注释处理到文件中。

- 示例

有关如何使用 <code> 标记的示例，请参阅 [](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/example) 主题。

#### [cref 特性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/cref-attribute)

XML 文档标记中的 `cref` 属性是指“代码引用”。 它指定标记的内部文本是一个代码元素，例如类型、方法或属性。 文档工具（例如 [Sandcastle](https://github.com/EWSoftware/SHFB)）使用 `cref` 属性自动生成指向记录类型或成员的页面的超链接。

##### 示例

下面的示例演示了在 [`<see>`](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/see) 标记中使用的 `cref` 属性。

```csharp
// Save this file as CRefTest.cs
// Compile with: csc CRefTest.cs -doc:Results.xml 

namespace TestNamespace
{
    /// <summary>
    /// TestClass contains several cref examples.
    /// </summary>
    public class TestClass
    {
        /// <summary>
        /// This sample shows how to specify the <see cref="TestClass"/> constructor as a cref attribute.
        /// </summary>
        public TestClass()
        { }

        /// <summary>
        /// This sample shows how to specify the <see cref="TestClass(int)"/> constructor as a cref attribute.
        /// </summary>
        public TestClass(int value)
        { }

        /// <summary>
        /// The GetZero method.
        /// </summary>
        /// <example> 
        /// This sample shows how to call the <see cref="GetZero"/> method.
        /// <code>
        /// class TestClass 
        /// {
        ///     static int Main() 
        ///     {
        ///         return GetZero();
        ///     }
        /// }
        /// </code>
        /// </example>
        public static int GetZero()
        {
            return 0;
        }

        /// <summary>
        /// The GetGenericValue method.
        /// </summary>
        /// <remarks> 
        /// This sample shows how to specify the <see cref="GetGenericValue"/> method as a cref attribute.
        /// </remarks>

        public static T GetGenericValue<T>(T para)
        {
            return para;
        }
    }

    /// <summary>
    /// GenericClass.
    /// </summary>
    /// <remarks> 
    /// This example shows how to specify the <see cref="GenericClass{T}"/> type as a cref attribute.
    /// </remarks>
    class GenericClass<T>
    {
        // Fields and members.
    }

    class Program
    {
        static int Main()
        {
            return TestClass.GetZero();
        }
    }
}
```

在编译时，该程序生成以下 XML 文件。 请注意，例如 `GetZero` 方法的 `cref` 属性已被编译器转换为 `"M:TestNamespace.TestClass.GetZero"`。 “M:”前缀表示“方法”，并且是一种由文档工具（例如 Sandcastle）识别的约定。 有关前缀的完整列表，请参阅[处理 XML 文件](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/processing-the-xml-file)。

```xml
<?xml version="1.0"?>  
<doc>  
    <assembly>  
        <name>CRefTest</name>  
    </assembly>  
    <members>  
        <member name="T:TestNamespace.TestClass">  
            <summary>  
            TestClass contains cref examples.  
            </summary>  
        </member>  
        <member name="M:TestNamespace.TestClass.#ctor">  
            <summary>  
            This sample shows how to specify the <see cref="T:TestNamespace.TestClass"/> constructor as a cref attribute.   
            </summary>  
        </member>  
        <member name="M:TestNamespace.TestClass.#ctor(System.Int32)">  
            <summary>  
            This sample shows how to specify the <see cref="M:TestNamespace.TestClass.#ctor(System.Int32)"/> constructor as a cref attribute.   
            </summary>  
        </member>  
        <member name="M:TestNamespace.TestClass.GetZero">  
            <summary>  
            The GetZero method.  
            </summary>  
            <example>   
            This sample shows how to call the <see cref="M:TestNamespace.TestClass.GetZero"/> method.  
            <code>  
            class TestClass   
            {  
                static int Main()   
                {  
                    return GetZero();  
                }  
            }  
            </code>  
            </example>  
        </member>  
        <member name="M:TestNamespace.TestClass.GetGenericValue``1(``0)">  
            <summary>  
            The GetGenericValue method.  
            </summary>  
            <remarks>   
            This sample shows how to specify the <see cref="M:TestNamespace.TestClass.GetGenericValue``1(``0)"/> method as a cref attribute.  
            </remarks>  
        </member>  
        <member name="T:TestNamespace.GenericClass`1">  
            <summary>  
            GenericClass.  
            </summary>  
            <remarks>   
            This example shows how to specify the <see cref="T:TestNamespace.GenericClass`1"/> type as a cref attribute.  
            </remarks>  
        </member>  
    </members>    <members>  
        <member name="T:TestNamespace.TestClass">  
            <summary>  
            TestClass contains two cref examples.  
            </summary>  
        </member>  
        <member name="M:TestNamespace.TestClass.GetZero">  
            <summary>  
            The GetZero method.  
            </summary>  
            <example> This sample shows how to call the <see cref="M:TestNamespace.TestClass.GetZero"/> method.  
            <code>  
            class TestClass   
            {  
                static int Main()   
                {  
                    return GetZero();  
                }  
            }  
            </code>  
            </example>  
        </member>  
        <member name="M:TestNamespace.TestClass.GetGenericValue``1(``0)">  
            <summary>  
            The GetGenericValue method.  
            </summary>  
            <remarks>   
            This sample shows how to specify the <see cref="M:TestNamespace.TestClass.GetGenericValue``1(``0)"/> method as a cref attribute.  
            </remarks>  
        </member>  
        <member name="T:TestNamespace.GenericClass`1">  
            <summary>  
            GenericClass.  
            </summary>  
            <remarks>   
            This example shows how to specify the <see cref="T:TestNamespace.GenericClass`1"/> type as a cref attribute.  
            </remarks>  
        </member>  
    </members>  
</doc>  
```

#### [<example>](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/example)

- 语法

```xml
<example>description</example>  
```

- 参数

`description`
代码示例的说明。

- 备注

借助 <example> 标记，可以指定如何使用方法或其他库成员的示例。 这通常涉及到使用 [](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/code) 标记。

使用 [/doc](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/doc-compiler-option) 进行编译可以将文档注释处理到文件中。

- 示例

```csharp
// Save this file as CRefTest.cs
// Compile with: csc CRefTest.cs -doc:Results.xml 

namespace TestNamespace
{
    /// <summary>
    /// TestClass contains several cref examples.
    /// </summary>
    public class TestClass
    {
        /// <summary>
        /// This sample shows how to specify the <see cref="TestClass"/> constructor as a cref attribute.
        /// </summary>
        public TestClass()
        { }

        /// <summary>
        /// This sample shows how to specify the <see cref="TestClass(int)"/> constructor as a cref attribute.
        /// </summary>
        public TestClass(int value)
        { }

        /// <summary>
        /// The GetZero method.
        /// </summary>
        /// <example> 
        /// This sample shows how to call the <see cref="GetZero"/> method.
        /// <code>
        /// class TestClass 
        /// {
        ///     static int Main() 
        ///     {
        ///         return GetZero();
        ///     }
        /// }
        /// </code>
        /// </example>
        public static int GetZero()
        {
            return 0;
        }

        /// <summary>
        /// The GetGenericValue method.
        /// </summary>
        /// <remarks> 
        /// This sample shows how to specify the <see cref="GetGenericValue"/> method as a cref attribute.
        /// </remarks>

        public static T GetGenericValue<T>(T para)
        {
            return para;
        }
    }

    /// <summary>
    /// GenericClass.
    /// </summary>
    /// <remarks> 
    /// This example shows how to specify the <see cref="GenericClass{T}"/> type as a cref attribute.
    /// </remarks>
    class GenericClass<T>
    {
        // Fields and members.
    }

    class Program
    {
        static int Main()
        {
            return TestClass.GetZero();
        }
    }
}
```

#### [<exception>](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/exception)

- 语法

```xml
<exception cref="member">description</exception>  
```

- 参数

cref = " `member`"
对当前编译环境中出现的一个异常的引用。 编译器检查是否存在给定的异常，并将 `member` 转换为输出 XML 中的规范的元素名称。 `member` 必须出现在双引号 (" ") 内。

有关如何创建对泛型类型的 cref 引用的详细信息，请参阅[<查看>](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/see)。

`description`
异常的说明。

- 备注

<exception> 标记让你指定可引发的异常。 此标记可应用于方法、属性、事件和索引器的定义。

使用 [/doc](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/doc-compiler-option) 进行编译可以将文档注释处理到文件中。

有关异常处理的详细信息，请参阅[异常和异常处理](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/exceptions/index)。

- 示例

```csharp
// compile with: -doc:DocFileName.xml 

/// Comment for class
public class EClass : System.Exception
{
    // class definition...
}

/// Comment for class
class TestClass
{
    /// <exception cref="System.Exception">Thrown when...</exception>
    public void DoSomething()
    {
        try
        {
        }
        catch (EClass)
        {
        }
    }
}
```

#### [<include>](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/include)

- 语法

```xml
<include file='filename' path='tagpath[@name="id"]' />  
```

- 参数

`filename`
包含文档的 XML 文件的名称。 可使用相对于源代码文件的路径限定文件名。 使用单引号 (' ') 将 `filename` 括起来。

`tagpath`
`filename` 中标记的路径，它指向标记 `name`。 使用单引号 (' ') 将路径括起来。

`name`
标记中的名称说明符（位于注释之前）；`name` 将有 `id`。

`id`
标记的 ID（位于注释之前）。 用双引号 (" ") 将 ID 括起来。

- 备注

通过 <include> 标记，可在其他文件中引用描述源代码中类型和成员的注释。 这是对直接在源代码文件中放入文档注释的替代方法。 通过将文档放入不同文件，可以单独从源代码对文档应用源控件。 一人可以签出源代码文件，而其他人可以签出文档文件。

<include> 标记使用 XML XPath 语法。 有关如何自定义 <include> 的用法，请参阅 XPath 文档。

- 示例

这是多文件示例。 第一个文件使用 <include>，列在下面：

```csharp
// compile with: -doc:DocFileName.xml 

/// <include file='xml_include_tag.doc' path='MyDocs/MyMembers[@name="test"]/*' />
class Test
{
    static void Main()
    {
    }
}

/// <include file='xml_include_tag.doc' path='MyDocs/MyMembers[@name="test2"]/*' />
class Test2
{
    public void Test()
    {
    }
}
```

第二个文件是 xml_include_tag.doc，包含下列文档注释：

```xml
<MyDocs>  
  
<MyMembers name="test">  
<summary>  
The summary for this type.  
</summary>  
</MyMembers>  
  
<MyMembers name="test2">  
<summary>  
The summary for this other type.  
</summary>  
</MyMembers>  
  
</MyDocs>  
```

- 程序输出

使用以下命令行编译 Test 和 Test2 类时，便会生成下面的输出：`/doc:DocFileName.xml.`。在 Visual Studio 的项目设计器的“生成”窗格中，指定 XML 文档注释选项。 当 C# 编译器发现 <include> 标记时，它将在 xml_include_tag.doc（而不是当前源文件）中搜索文档注释。 然后编译器生成 DocFileName.xml，这是由文档工具（如 [Sandcastle](https://github.com/EWSoftware/SHFB)）所使用的文件，用于生成最终文档。

```xml
<?xml version="1.0"?>   
<doc>   
    <assembly>   
        <name>xml_include_tag</name>   
    </assembly>   
    <members>   
        <member name="T:Test">   
            <summary>   
The summary for this type.   
</summary>   
        </member>   
        <member name="T:Test2">   
            <summary>   
The summary for this other type.   
</summary>   
        </member>   
    </members>   
</doc>   
```

#### [<list>](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/list)

- 语法

```xml
<list type="bullet" | "number" | "table">  
    <listheader>  
        <term>term</term>  
        <description>description</description>  
    </listheader>  
    <item>  
        <term>term</term>  
        <description>description</description>  
    </item>  
</list>  
```

- 参数

`term`
要定义的术语，将在 `description` 中进行定义。

`description`
项目符号或编号列表中的项或 `term` 的定义。

- 备注

<listheader> 块用于定义表或定义列表的标题行。 定义表时，只需提供标题中的术语的项。

列表中的每个项均使用 <item> 块指定。 创建定义列表时，需要同时指定 `term` 和 `description`。 但是，对于表、项目符号列表或编号列表，只需提供 `description` 的项。

列表或表可根据需要具有多个 <item> 块。

使用 [/doc](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/doc-compiler-option) 进行编译可以将文档注释处理到文件中。

- 示例

```csharp
// compile with: -doc:DocFileName.xml 

/// text for class TestClass
public class TestClass
{
    /// <summary>Here is an example of a bulleted list:
    /// <list type="bullet">
    /// <item>
    /// <description>Item 1.</description>
    /// </item>
    /// <item>
    /// <description>Item 2.</description>
    /// </item>
    /// </list>
    /// </summary>
    static void Main()
    {
    }
}
```

#### [<para>](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/para)

- 语法

```xml
<para>content</para>  
```

- 参数

`content`
段落文本。

- 备注

`<para>` 标记用于标记内，例如 [<summary>](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/summary)、[<remarks>](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/remarks) 或 [<returns>](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/returns)，允许向文本添加结构。

使用 [/doc](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/doc-compiler-option) 进行编译可以将文档注释处理到文件中。

- 示例
  有关使用 `<para>` 的示例，请参阅 [<summary>](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/summary)。

#### [<param>](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/param)

- 语法

```xml
<param name="name">description</param>  
```

- 参数

`name`
方法参数的名称。 用双引号 (" ") 将名称引起来。

`description`
参数的说明。

- 备注

在方法声明的注释中，应使用 <param> 标记来描述方法参数之一。 若要记录多个参数，请使用多个 <param > 标记。

<param> 标记的文本将显示在 IntelliSense、对象浏览器和代码注释 Web 报表中。

使用 [/doc](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/doc-compiler-option) 进行编译可以将文档注释处理到文件中。

- 示例

```csharp
// compile with: -doc:DocFileName.xml 

/// text for class TestClass
public class TestClass
{
    // Single parameter.
    /// <param name="Int1">Used to indicate status.</param>
    public static void DoWork(int Int1)
    {
    }

    // Multiple parameters.
    /// <param name="Int1">Used to indicate status.</param>
    /// <param name="Float1">Used to specify context.</param>
    public static void DoWork(int Int1, float Float1)
    {
    }

    /// text for Main
    static void Main()
    {
    }
}
```

#### [<paramref>](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/paramref)

- 语法

```xml
<paramref name="name"/>  
```

- 参数

`name`
要引用的参数的名称。 用双引号 (" ") 将名称引起来。

- 备注

<paramref> 标记提供一种方式，用于指示 <summary> 或 <remarks> 块等代码注释中的单词引用某个参数。 可以处理 XML 文件以明显的方式设置此单词的格式，如使用粗体或斜体。

使用 [/doc](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/doc-compiler-option) 进行编译可以将文档注释处理到文件中。

- 示例

```csharp
// compile with: -doc:DocFileName.xml 

/// text for class TestClass
public class TestClass
{
    /// <summary>DoWork is a method in the TestClass class.  
    /// The <paramref name="int1"/> parameter takes a number.
    /// </summary>
    public static void DoWork(int int1)
    {
    }

    /// text for Main
    static void Main()
    {
    }
}
```

#### [<permission>](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/permission)

- 语法

```xml
<permission cref="member">description</permission>  
```

- 参数

cref = " `member`"
对可从当前编译环境调用的成员或字段的引用。 编译器检查是否存在给定的代码元素，并将 `member` 转换为输出 XML 中规范的元素名称。 成员必须出现在双引号 (" ") 内。

有关如何创建对泛型类型的 cref 引用的信息，请参阅 [](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/see)。

`description`
对成员访问权限的说明。

- 备注

使用 <permission> 可以记录成员访问权限 [PermissionSet](https://docs.microsoft.com/zh-cn/dotnet/api/system.security.permissionset) 类可指定对成员的访问权限。

使用 [/doc](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/doc-compiler-option) 进行编译可以将文档注释处理到文件中。

- 示例

```csharp
// compile with: -doc:DocFileName.xml 

class TestClass
{
    /// <permission cref="System.Security.PermissionSet">Everyone can access this method.</permission>
    public static void Test()
    {
    }

    static void Main()
    {
    }
}
```

#### [<remarks>](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/remarks)

- 语法

```xml
<remarks>description</remarks>  
```

- 参数

`Description`
对成员的说明。

- 备注

<remarks> 标记用于添加有关某个类型的信息，从而补充由 [](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/summary) 指定的信息。 此信息显示在对象浏览器窗口中。

使用 [/doc](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/doc-compiler-option) 进行编译可以将文档注释处理到文件中。

- 示例

```csharp
// compile with: -doc:DocFileName.xml 

/// <summary>
/// You may have some primary information about this class.
/// </summary>
/// <remarks>
/// You may have some additional information about this class.
/// </remarks>
public class TestClass
{
    /// text for Main
    static void Main()
    {
    }
}
```

#### [<returns>](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/returns)

- 语法

```xml
<returns>description</returns>  
```

- 参数

`description`
返回值的说明。

- 备注

在方法声明的注释中应使用 <returns> 标记来描述返回值。

使用 [/doc](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/doc-compiler-option) 进行编译可以将文档注释处理到文件中。

- 示例

```csharp
// compile with: -doc:DocFileName.xml 

/// text for class TestClass
public class TestClass
{
    /// <returns>Returns zero.</returns>
    public static int GetZero()
    {
        return 0;
    }

    /// text for Main
    static void Main()
    {
    }
}
```

#### [<see>](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/see)

- 语法

```xml
<see cref="member"/>  
```

- 参数

cref = " `member`"
对可从当前编译环境调用的成员或字段的引用。 编译器检查是否存在给定的码位元素，并将 `member` 传递到输出 XML 中的元素名称。 将成员置于双引号 (" ") 内。

- 备注

通过 <see> 标记可以从文本内指定链接。 使用 [](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/seealso) 指示文本应该放在“另请参阅”部分中。 使用 [cref 属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/cref-attribute)创建指向代码元素的文档页的内部超链接。

使用 [-doc](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/doc-compiler-option) 进行编译以便将文档注释处理到文件中。

下面的示例展示摘要部分中的 <see> 标记。

```csharp
// compile with: -doc:DocFileName.xml 

/// text for class TestClass
public class TestClass
{
    /// <summary>DoWork is a method in the TestClass class.
    /// <para>Here's how you could make a second paragraph in a description. <see cref="System.Console.WriteLine(System.String)"/> for information about output statements.</para>
    /// <seealso cref="TestClass.Main"/>
    /// </summary>
    public static void DoWork(int Int1)
    {
    }

    /// text for Main
    static void Main()
    {
    }
}
```

#### [<seealso>](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/seealso)

- 语法

```xml
<seealso cref="member"/>  
```

- 参数

cref = " `member`"
对可从当前编译环境调用的成员或字段的引用。 编译器检查是否存在给定的码位元素，并将 `member` 传递到输出 XML 中的元素名称。`member` 必须在双引号 (" ") 内。

有关如何创建对泛型类型的 cref 引用的信息，请参阅 [ <see>](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/see)。

- 备注

使用 <seealso> 标记，可以指定想要在“另请参阅”部分中显示的文本。 使用 [ <see>](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/see) 从文本内指定链接。

使用 [/doc](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/doc-compiler-option) 进行编译可以将文档注释处理到文件中。

- 示例

有关使用 <seealso> 的示例，请参阅 [ <summary>](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/summary)。

#### [<summary>](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/summary)

- 语法

```xml
<summary>description</summary>  
```

- 参数

`description`
对象的摘要。

- 备注

<summary> 标记应当用于描述类型或类型成员。 使用 [](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/remarks) 可针对某个类型说明添加补充信息。 使用 [cref 属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/cref-attribute)可启用文档工具（如 [Sandcastle](https://github.com/EWSoftware/SHFB)）来创建指向代码元素的文档页的内部超链接。

<summary> 标记的文本是唯一有关 IntelliSense 中的类型的信息源，它也显示在对象浏览器窗口中。

使用 [/doc](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/doc-compiler-option) 进行编译可以将文档注释处理到文件中。 若要基于编译器生成的文件创建最终文档，可以创建一个自定义工具，也可以使用 [Sandcastle](https://github.com/EWSoftware/SHFB) 等工具。

- 示例1

```csharp
// compile with: -doc:DocFileName.xml 

/// text for class TestClass
public class TestClass
{
    /// <summary>DoWork is a method in the TestClass class.
    /// <para>Here's how you could make a second paragraph in a description. <see cref="System.Console.WriteLine(System.String)"/> for information about output statements.</para>
    /// <seealso cref="TestClass.Main"/>
    /// </summary>
    public static void DoWork(int Int1)
    {
    }

    /// text for Main
    static void Main()
    {
    }
}
```

前面的示例生成下面的 XML 文件。

```xml
<?xml version="1.0"?>  
<doc>  
    <assembly>  
        <name>YourNamespace</name>  
    </assembly>  
    <members>  
        <member name="T:DotNetEvents.TestClass">  
            text for class TestClass  
        </member>  
        <member name="M:DotNetEvents.TestClass.DoWork(System.Int32)">  
            <summary>DoWork is a method in the TestClass class.  
            <para>Here's how you could make a second paragraph in a description. <see cref="M:System.Console.WriteLine(System.String)"/> for information about output statements.</para>  
            <seealso cref="M:DotNetEvents.TestClass.Main"/>  
            </summary>  
        </member>  
        <member name="M:DotNetEvents.TestClass.Main">  
            text for Main  
        </member>  
    </members>  
</doc>  
```

- 示例2

下面的示例演示如何对泛型类型进行 `cref` 引用。

```csharp
// compile with: -doc:DocFileName.xml 

// the following cref shows how to specify the reference, such that,
// the compiler will resolve the reference
/// <summary cref="C{T}">
/// </summary>
class A { }

// the following cref shows another way to specify the reference, 
// such that, the compiler will resolve the reference
// <summary cref="C &lt; T &gt;">

// the following cref shows how to hard-code the reference
/// <summary cref="T:C`1">
/// </summary>
class B { }

/// <summary cref="A">
/// </summary>
/// <typeparam name="T"></typeparam>
class C<T> { }
```

前面的示例生成下面的 XML 文件。

```xml
<?xml version="1.0"?>  
<doc>  
    <assembly>  
        <name>YourNamespace</name>  
    </assembly>  
    <members>  
        <member name="T:ExtensionMethodsDemo1.A">  
            <summary cref="T:ExtensionMethodsDemo1.C`1">  
            </summary>  
        </member>  
        <member name="T:ExtensionMethodsDemo1.B">  
            <summary cref="T:C`1">  
            </summary>  
        </member>  
        <member name="T:ExtensionMethodsDemo1.C`1">  
            <summary cref="T:ExtensionMethodsDemo1.A">  
            </summary>  
            <typeparam name="T"></typeparam>  
        </member>  
    </members>  
</doc>  
```

#### [<typeparam>](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/typeparam)

- 语法

```xml
<typeparam name="name">description</typeparam>  
```

- 参数

`name`
类型参数的名称。 用双引号 (" ") 将名称引起来。

`description`
类型参数的说明。

- 备注

在泛型类型或方法声明的注释中，应使用 `<typeparam>` 标记来描述类型参数。 为泛型类型或方法的每个类型参数添加标记。

有关详细信息，请参阅[泛型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/generics/index)。

`<typeparam>` 标记的文本将显示在 IntelliSense、[对象浏览器窗口](https://docs.microsoft.com/zh-cn/visualstudio/ide/viewing-the-structure-of-code#BKMK_ObjectBrowser)代码注释 Web 报表。

使用 [/doc](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/doc-compiler-option) 进行编译可以将文档注释处理到文件中。

- 示例

```csharp
// compile with: -doc:DocFileName.xml 

/// comment for class
public class TestClass
{
    /// <summary>
    /// Creates a new array of arbitrary type <typeparamref name="T"/>
    /// </summary>
    /// <typeparam name="T">The element type of the array</typeparam>
    public static T[] mkArray<T>(int n)
    {
        return new T[n];
    }
}
```

#### [<typeparamref>](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/typeparamref)

- 语法

```xml
<typeparamref name="name"/>  
```

- 参数

`name`
类型参数的名称。 用双引号 (" ") 将名称引起来。

- 备注

有关泛型类型中的类型参数及方法的详细信息，请参阅[泛型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/generics/index)。

通过此标记，文档文件的使用者可显著设置字体格式，例如采用斜体。

使用 [/doc](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/doc-compiler-option) 进行编译可以将文档注释处理到文件中。

- 示例

```csharp
// compile with: -doc:DocFileName.xml 

/// comment for class
public class TestClass
{
    /// <summary>
    /// Creates a new array of arbitrary type <typeparamref name="T"/>
    /// </summary>
    /// <typeparam name="T">The element type of the array</typeparam>
    public static T[] mkArray<T>(int n)
    {
        return new T[n];
    }
}
```

#### [<value>](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/value)

- 语法

```xml
<value>property-description</value>  
```

- 参数

`property-description`
属性的说明。

- 备注

<value> 标记可以描述属性表示的值。 请注意，在 Visual Studio .NET 开发环境中通过代码向导添加属性时，将添加新属性的 [](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/summary) 标记。 然后，应手动添加 <value> 标记，描述属性表示的值。

使用 [/doc](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/doc-compiler-option) 进行编译可以将文档注释处理到文件中。

- 示例

```csharp
// compile with: -doc:DocFileName.xml 

/// text for class Employee
public class Employee
{
    private string _name;

    /// <summary>The Name property represents the employee's name.</summary>
    /// <value>The Name property gets/sets the value of the string field, _name.</value>

    public string Name
    {
        get
        {
            return _name;
        }
        set
        {
            _name = value;
        }
    }
}

/// text for class MainClass
public class MainClass
{
    /// text for Main
    static void Main()
    {
    }
}
```

### [Processing the XML File](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/xmldoc/processing-the-xml-file)

编译器为代码（已标记以生成文档）中的每个构造生成一个 ID 字符串。 （有关如何标记代码的信息，请参阅[文档注释的建议标记](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/recommended-tags-for-documentation-comments)。）ID 字符串唯一标识构造。 处理 XML 文件的程序可以使用 ID 字符串来标识文档应用于的相应 .NET Framework 元数据/反射项目。

XML 文件不是代码的分层表示形式；它是具有每个元素生成的 ID 的简单列表。

编译器在生成 ID 字符串时应遵循以下规则：

- 字符串不得包含空白符。

- ID 字符串的第一部分标识被标识的成员类型，单个字符后跟一个冒号。 使用下面的成员类型：

  | 字符 | 说明                                                         |
  | ---- | ------------------------------------------------------------ |
  | N    | namespace  无法将文档注释添加到命名空间中，但可以在支持的情况下对它们进行 cref 引用。 |
  | T    | 类型：类、接口、结构、枚举、委托                             |
  | F    | Field — 字段                                                 |
  | P    | 属性（包括索引器或其他的索引属性）                           |
  | M    | 方法（包括构造函数、运算符等特殊方法）                       |
  | E    | Event — 事件                                                 |
  | !    | 错误字符串  字符串的其余部分提供有关错误的信息。 C# 编译器将生成无法解析的链接的错误信息。 |

- 该字符串的第二部分是项目的完全限定名称，从命名空间的根开始。 用句点分隔项目名称、其封闭类型和命名空间。 如果项目名称本身包含句点，会将其替换为哈希符号 ('#')。 假定没有名称中恰好包含哈希符号的项目。 例如，String 构造函数的完全限定名称将是“System.String.#ctor”。

- 对于属性和方法，如果方法带有自变量，则后跟用括号括起来的自变量列表。 如果没有任何自变量，则不会出现括号。 确保自变量之间用逗号分隔。 每个自变量的编码直接遵循它在 .NET Framework 签名中的编码方式：

  - 基类型。 常规的类型（ELEMENT_TYPE_CLASS 或 ELEMENT_TYPE_VALUETYPE）表示为该类型的完全限定名称。
  - 内部类型（例如，ELEMENT_TYPE_I4、ELEMENT_TYPE_OBJECT、ELEMENT_TYPE_STRING、ELEMENT_TYPE_TYPEDBYREF 和 ELEMENT_TYPE_VOID）表示为对应的完整类型的完全限定名称。 例如，System.Int32 或 System.TypedReference。
  - ELEMENT_TYPE_PTR 表示为修改类型之后的“*”。
  - ELEMENT_TYPE_BYREF 表示为修改类型之后的“@”。
  - ELEMENT_TYPE_PINNED 表示为修改类型之后的“^”。 C# 编译器不会生成此类型。
  - ELEMENT_TYPE_CMOD_REQ 表示为“|”和修饰符类的完全限定名称，前面是修改类型。 C# 编译器不会生成此类型。
  - ELEMENT_TYPE_CMOD_OPT 表示为“!”和修饰符类的完全限定名称，前面是修改类型。
  - ELEMENT_TYPE_SZARRAY 表示为“[]”，前面是数组的元素类型。
  - ELEMENT_TYPE_GENERICARRAY 表示为“[?]”，前面是数组的元素类型。 C# 编译器不会生成此类型。
  - ELEMENT_TYPE_ARRAY 表示为 [*lowerbound*:`size`,*lowerbound*:`size`]，其中逗号的数量是秩 - 1，每个维度的下限和大小（如果已知）以十进制形式表示。 如果未指定下限或大小，则只需将其省略。 如果省略某个特定维度的下限和大小，也会省略“:”。 例如，以 1 作为下限并且未指定大小的二维数组是 [1:,1:]。
  - ELEMENT_TYPE_FNPTR 表示为“=FUNC:`type`(*signature*)”，其中 `type` 是返回类型，*signature* 是方法的自变量。 如果没有任何自变量，则省略括号。 C# 编译器不会生成此类型。

  不表示下列签名组件，因为它们永远不会用于区分重载方法：

  - 调用约定
  - 返回类型
  - ELEMENT_TYPE_SENTINEL

- 仅适用于转换运算符（op_Implicit 和 op_Explicit），该方法的返回值被编码为“”，后面是返回类型，如上面的编码所示。

- 对于泛型类型，类型名称后跟反引号，然后是指示泛型类型参数数量的一个数字。 例如:

  `<member name="T:SampleClass`2">` 是定义为 `public class SampleClass<T, U>` 的类型的标记。

  对于将泛型类型用作参数的方法，泛型类型参数被指定为前面加上反引号的数字（例如 `0、`1）。 每个数字表示该类型的泛型参数的从零开始的数组表示法。

#### 示例

下面的示例演示如何为类及其成员生成 ID 字符串：

```csharp
namespace N
{
    /// <summary>
    /// Enter description here for class X. 
    /// ID string generated is "T:N.X". 
    /// </summary>
    public unsafe class X
    {
        /// <summary>
        /// Enter description here for the first constructor.
        /// ID string generated is "M:N.X.#ctor".
        /// </summary>
        public X() { }


        /// <summary>
        /// Enter description here for the second constructor.
        /// ID string generated is "M:N.X.#ctor(System.Int32)".
        /// </summary>
        /// <param name="i">Describe parameter.</param>
        public X(int i) { }


        /// <summary>
        /// Enter description here for field q.
        /// ID string generated is "F:N.X.q".
        /// </summary>
        public string q;


        /// <summary>
        /// Enter description for constant PI.
        /// ID string generated is "F:N.X.PI".
        /// </summary>
        public const double PI = 3.14;


        /// <summary>
        /// Enter description for method f.
        /// ID string generated is "M:N.X.f".
        /// </summary>
        /// <returns>Describe return value.</returns>
        public int f() { return 1; }


        /// <summary>
        /// Enter description for method bb.
        /// ID string generated is "M:N.X.bb(System.String,System.Int32@,System.Void*)".
        /// </summary>
        /// <param name="s">Describe parameter.</param>
        /// <param name="y">Describe parameter.</param>
        /// <param name="z">Describe parameter.</param>
        /// <returns>Describe return value.</returns>
        public int bb(string s, ref int y, void* z) { return 1; }


        /// <summary>
        /// Enter description for method gg.
        /// ID string generated is "M:N.X.gg(System.Int16[],System.Int32[0:,0:])". 
        /// </summary>
        /// <param name="array1">Describe parameter.</param>
        /// <param name="array">Describe parameter.</param>
        /// <returns>Describe return value.</returns>
        public int gg(short[] array1, int[,] array) { return 0; }


        /// <summary>
        /// Enter description for operator.
        /// ID string generated is "M:N.X.op_Addition(N.X,N.X)". 
        /// </summary>
        /// <param name="x">Describe parameter.</param>
        /// <param name="xx">Describe parameter.</param>
        /// <returns>Describe return value.</returns>
        public static X operator +(X x, X xx) { return x; }


        /// <summary>
        /// Enter description for property.
        /// ID string generated is "P:N.X.prop".
        /// </summary>
        public int prop { get { return 1; } set { } }


        /// <summary>
        /// Enter description for event.
        /// ID string generated is "E:N.X.d".
        /// </summary>
        public event D d;


        /// <summary>
        /// Enter description for property.
        /// ID string generated is "P:N.X.Item(System.String)".
        /// </summary>
        /// <param name="s">Describe parameter.</param>
        /// <returns></returns>
        public int this[string s] { get { return 1; } }


        /// <summary>
        /// Enter description for class Nested.
        /// ID string generated is "T:N.X.Nested".
        /// </summary>
        public class Nested { }


        /// <summary>
        /// Enter description for delegate.
        /// ID string generated is "T:N.X.D". 
        /// </summary>
        /// <param name="i">Describe parameter.</param>
        public delegate void D(int i);


        /// <summary>
        /// Enter description for operator.
        /// ID string generated is "M:N.X.op_Explicit(N.X)~System.Int32".
        /// </summary>
        /// <param name="x">Describe parameter.</param>
        /// <returns>Describe return value.</returns>
        public static explicit operator int(X x) { return 1; }

    }
}
```

### [Delimiters for Documentation Tags](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/xmldoc/delimiters-for-documentation-tags)

XML 文档注释需要使用分隔符，用来向编译器指示文档注释开始和结束的位置。 可以使用以下采用 XML 文档标记的分隔符：

`///`
单行分隔符。 这是在文档示例中显示的格式，由 Visual C# 项目模板使用。 如果在分隔符后面有一个空格字符，那么此字符不会包括在 XML 输出中。

> Visual Studio IDE 具有一种称为智能注释编辑的功能，在代码编辑器中键入 `///` 分隔符后，此功能可自动插入 <summary> 和 </summary> 标记，并在此标记中移动游标。 可以在[“选项”对话框](https://docs.microsoft.com/zh-cn/visualstudio/ide/reference/options-text-editor-csharp-advanced)中打开/关闭此功能。

`/** */`
多行分隔符。

使用 `/** */` 分隔符时需遵守一些格式设置规则。

- 在包含 `/**` 分隔符的行上，如果行的其余部分为空格，则不将此行作为注释处理。 如果 `/**` 分隔符后面的第一个字符为空格，则忽略此空格字符，并处理行的其余部分。 否则，将 `/**` 分隔符后面的行的所有文本作为注释的一部分进行处理。
- 在包含 `*/` 分隔符的行中，如果 `*/` 分隔符前面只有空格，此行将被忽略。 否则，`*/` 分隔符前面的行的文本被处理为注释的一部分，并且需符合后面的项目符号所描述的模式匹配规则。
- 对于以 `/**` 分隔符开头的行后面的行，编译器在各行的开头寻找共同模式。 此模式可以包含空格和星号 (`*`)，后面跟更多空格。 如果编译器在不以 `/**` 分隔符或 `*/` 分隔符开头的各行开头找到共同模式，则忽略此每个行的模式。

以下示例说明了这些规则。

- 以下注释中将被处理的唯一部分是以 `<summary>` 开头的行。 三种标记格式产生的注释相同。

  ```csharp
  /** <summary>text</summary> */   
  
  /**   
  <summary>text</summary>   
  */   
  
  /**   
   * <summary>text</summary>   
  */  
  ```

- 编译器识别出第二和第三行开头的共同模式“*”。 此模式不包括在输出中。

  ```csharp
  /**   
   * <summary>   
   * text </summary>*/   
  ```

- 编译器在下面的注释中未找到共同模式，因为第三行的第二个字符不是一个星号。 因此，第二和第三行上的所有文本将处理为注释的一部分。

  ```csharp
  /**   
   * <summary>   
     text </summary>  
  */   
  ```

- 编译器在以下注释中未找到模式，原因有两个。 首先，星号前的空格数不一致。 其次，第 5 行以制表符开头，这与空格不匹配。 因此，第二到第五行的所有文本都作为注释的一部分进行处理。

  ```csharp
  /**   
    * <summary>   
    * text   
   *  text2   
      *  </summary>   
  */   
  ```

### [How to: Use the XML Documentation Features](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/xmldoc/how-to-use-the-xml-documentation-features)

下面的示例提供对某个已存档类型的基本概述。

#### 示例

```csharp
// If compiling from the command line, compile with: -doc:YourFileName.xml

/// <summary>
/// Class level summary documentation goes here.
/// </summary>
/// <remarks>
/// Longer comments can be associated with a type or member through
/// the remarks tag.
/// </remarks>
public class TestClass : TestInterface
{
    /// <summary>
    /// Store for the Name property.
    /// </summary>
    private string _name = null;

    /// <summary>
    /// The class constructor.
    /// </summary>
    public TestClass()
    {
        // TODO: Add Constructor Logic here.
    }

    /// <summary>
    /// Name property.
    /// </summary>
    /// <value>
    /// A value tag is used to describe the property value.
    /// </value>
    public string Name
    {
        get
        {
            if (_name == null)
            {
                throw new System.Exception("Name is null");
            }
            return _name;
        }
    }

    /// <summary>
    /// Description for SomeMethod.
    /// </summary>
    /// <param name="s"> Parameter description for s goes here.</param>
    /// <seealso cref="System.String">
    /// You can use the cref attribute on any tag to reference a type or member 
    /// and the compiler will check that the reference exists.
    /// </seealso>
    public void SomeMethod(string s)
    {
    }

    /// <summary>
    /// Some other method.
    /// </summary>
    /// <returns>
    /// Return values are described through the returns tag.
    /// </returns>
    /// <seealso cref="SomeMethod(string)">
    /// Notice the use of the cref attribute to reference a specific method.
    /// </seealso>
    public int SomeOtherMethod()
    {
        return 0;
    }

    public int InterfaceMethod(int n)
    {
        return n * n;
    }

    /// <summary>
    /// The entry point for the application.
    /// </summary>
    /// <param name="args"> A list of command line arguments.</param>
    static int Main(System.String[] args)
    {
        // TODO: Add code to start application here.
        return 0;
    }
}

/// <summary>
/// Documentation that describes the interface goes here.
/// </summary>
/// <remarks>
/// Details about the interface go here.
/// </remarks>
interface TestInterface
{
    /// <summary>
    /// Documentation that describes the method goes here.
    /// </summary>
    /// <param name="n">
    /// Parameter n requires an integer argument.
    /// </param>
    /// <returns>
    /// The method returns an integer.
    /// </returns>
    int InterfaceMethod(int n);
}
```

该示例生成一个包含以下内容的 .xml 文件：

```xml
<?xml version="1.0"?>
<doc>
    <assembly>
        <name>xmlsample</name>
    </assembly>
    <members>
        <member name="T:TestClass">
            <summary>
            Class level summary documentation goes here.
            </summary>
            <remarks>
            Longer comments can be associated with a type or member through
            the remarks tag.
            </remarks>
        </member>
        <member name="F:TestClass._name">
            <summary>
            Store for the Name property.
            </summary>
        </member>
        <member name="M:TestClass.#ctor">
            <summary>
            The class constructor.
            </summary>
        </member>
        <member name="P:TestClass.Name">
            <summary>
            Name property.
            </summary>
            <value>
            A value tag is used to describe the property value.
            </value>
        </member>
        <member name="M:TestClass.SomeMethod(System.String)">
            <summary>
            Description for SomeMethod.
            </summary>
            <param name="s"> Parameter description for s goes here.</param>
            <seealso cref="T:System.String">
            You can use the cref attribute on any tag to reference a type or member 
            and the compiler will check that the reference exists.
            </seealso>
        </member>
        <member name="M:TestClass.SomeOtherMethod">
            <summary>
            Some other method.
            </summary>
            <returns>
            Return values are described through the returns tag.
            </returns>
            <seealso cref="M:TestClass.SomeMethod(System.String)">
            Notice the use of the cref attribute to reference a specific method.
            </seealso>
        </member>
        <member name="M:TestClass.Main(System.String[])">
            <summary>
            The entry point for the application.
            </summary>
            <param name="args"> A list of command line arguments.</param>
        </member>
        <member name="T:TestInterface">
            <summary>
            Documentation that describes the interface goes here.
            </summary>
            <remarks>
            Details about the interface go here.
            </remarks>
        </member>
        <member name="M:TestInterface.InterfaceMethod(System.Int32)">
            <summary>
            Documentation that describes the method goes here.
            </summary>
            <param name="n">
            Parameter n requires an integer argument.
            </param>
            <returns>
            The method returns an integer.
            </returns>
        </member>
    </members>
</doc>
```

#### 编译代码

若要编译该示例，请键入以下命令行：

```
csc XMLsample.cs /doc:XMLsample.xml
```

此命令创建 XML 文件 XMLsample.xml，可在浏览器中或使用 TYPE 命令查看该文件。

#### 可靠编程

XML 文档以 /// 开头。 创建新项目时，向导会放置一些以 /// 开头的行。 处理这些注释时存在一些限制：

- 文档必须是格式正确的 XML。 如果 XML 格式不正确，则会生成警告，并且文档文件将包含一条注释，指出遇到错误。

- 开发人员可以随意创建自己的标记集。 推荐的标记集（请参阅[建议的文档注释标记](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/xmldoc/recommended-tags-for-documentation-comments)）。 部分建议标记具有特殊含义：

  - <param> 标记用于描述参数。 如果已使用，编译器会验证该参数是否存在，以及文档是否描述了所有参数。 如果验证失败，编译器会发出警告。

  - `cref` 属性可以附加到任何标记，以提供对代码元素的引用。 编译器验证此代码元素是否存在。 如果验证失败，编译器会发出警告。 编译器在查找 `cref` 属性中描述的类型时会考虑所有 `using` 语句。

  - <summary> 标记由 Visual Studio 中的 IntelliSense 用于显示有关某个类型或成员的附加信息。

    > XML 文件不提供有关该类型和成员的完整信息（例如，它不包含任何类型信息）。 若要获取有关类型或成员的完整信息，必须将文档文件与对实际类型或成员的反射一起使用。

