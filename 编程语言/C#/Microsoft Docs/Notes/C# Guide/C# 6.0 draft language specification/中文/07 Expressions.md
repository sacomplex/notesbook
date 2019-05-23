# [Expressions](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/language-specification/expressions)

表达式是一系列运算符和操作数。 本章定义的语法，操作数和运算符的求值和表达式的含义的顺序。

## 表达式分类

表达式分类为以下类别之一：

- 一个值。 每个值都有关联的类型。
- 一个变量。 每个变量具有关联的类型，即该变量的声明类型。
- 一个命名空间。 具有此分类的表达式只显示为的左侧*member_access* ([成员访问](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#member-access))。 在任何其他上下文中，分类为一个命名空间的表达式将导致编译时错误。
- 一种类型。 具有此分类的表达式只显示为的左侧*member_access* ([成员访问](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#member-access))，或为有关操作数`as`运算符 ([As 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#the-as-operator))，则`is`运算符 ([是运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#the-is-operator))，或`typeof`运算符 ([typeof 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#the-typeof-operator))。 在任何其他上下文中，分类为一种类型的表达式将导致编译时错误。
- 一组重载方法，从而得到从成员查找方法组 ([成员查找](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#member-lookup))。 方法组可能有一个关联的实例表达式和关联的类型参数列表。 调用实例方法时，实例表达式的计算结果将成为所表示的实例`this`([此访问权限](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#this-access))。 方法组允许在*invocation_expression* ([调用表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#invocation-expressions))、 一个*delegate_creation_expression* ([委托创建表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#delegate-creation-expressions)) 的左侧，以及为运算符，且可以隐式转换为兼容的委托类型 ([方法组转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#method-group-conversions))。 在任何其他上下文中，分类为方法组的表达式将导致编译时错误。
- Null 文本。 具有此分类的表达式可以隐式转换为引用类型或可以为 null 的类型。
- 匿名函数。 具有此分类的表达式可以隐式转换为兼容的委托类型或表达式树类型。
- 属性访问。 每个属性访问具有关联的类型，即属性的类型。 此外，属性访问可以有一个关联的实例表达式。 当一个访问器 (`get`或`set`块) 的实例调用属性访问、 实例表达式的计算结果将成为所表示的实例`this`([此访问权限](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#this-access))。
- 事件的访问。 每个事件访问具有关联的类型，即该事件的类型。 此外，事件访问可以有一个关联的实例表达式。 事件访问可能显示为左操作数`+=`并`-=`运算符 ([事件分配](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#event-assignment))。 在任何其他上下文中，分类为事件访问的表达式将导致编译时错误。
- 索引器访问。 每个索引器访问具有关联的类型，即元素的索引器的类型。 此外，索引器访问有一个关联的实例表达式和关联的参数列表。 取值函数时 (`get`或`set`块) 的索引器调用访问、 实例表达式的计算结果将成为所表示的实例`this`([此访问权限](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#this-access))，和的结果计算参数列表将变为调用的参数列表。
- 执行任何操作。 发生这种情况的一种方法的调用的返回类型与表达式时`void`。 归类为执行任何操作才有效的上下文中的表达式*statement_expression* ([表达式语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/statements#expression-statements))。

命名空间、 类型、 方法组或事件访问，永远不会是一个表达式的最终结果。 相反，如上文所述，这些类别的表达式是只能在某些上下文中使用的中间构造。

属性访问或索引器访问始终重新分类为一个值，通过执行调用*get 访问器*或*set 访问器*。 由属性或索引器访问的上下文确定特定的访问器：如果访问为赋值的目标*set 访问器*调用来分配新值 ([简单赋值](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#simple-assignment))。 否则为*get 访问器*调用来获取当前值 ([表达式的值](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#values-of-expressions))。

### 表达式的值

大多数构造都表达式最终要求表达式指示***值***。 在这种情况下，如果实际表达式指示一个命名空间、 类型、 方法组，或执行任何操作，会发生编译时错误。 但是，如果表达式指示属性访问、 索引器访问或变量，将隐式替换的属性、 索引器或变量的值：

- 变量的值就是当前存储在由该变量的存储位置中的值。 必须考虑一个变量明确赋值 ([明确赋值](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/variables#definite-assignment)) 可以获取其值，或否则会发生编译时错误之前。
- 属性访问表达式的值通过调用*get 访问器*的属性。 如果该属性不具有*get 访问器*，则发生编译时错误。 否则为函数成员调用 ([进行编译时检查的动态重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#compile-time-checking-of-dynamic-overload-resolution)) 执行，并调用的结果将成为属性访问表达式的值。
- 索引器访问表达式的值通过调用*get 访问器*的索引器。 如果索引器没有*get 访问器*，则发生编译时错误。 否则为函数成员调用 ([进行编译时检查的动态重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#compile-time-checking-of-dynamic-overload-resolution)) 执行具有参数列表与索引器访问表达式，并调用的结果将成为值索引器访问表达式。

## 静态和动态绑定

确定基于类型或值构成的表达式 （自变量，操作数，接收方） 的操作的含义的过程通常称为***绑定***。 例如根据接收方和自变量的类型确定方法调用的含义。 运算符的含义是根据其操作数的类型确定的。

在 C# 中的操作的含义通常在编译时根据确定其构成表达式的编译时类型。 同样，如果表达式包含错误，错误将检测到并将由编译器报告。 这种方法称为***静态绑定***。

但是，如果表达式是动态表达式 (即具有类型`dynamic`) 这表示，它参与任何绑定应基于其运行时类型 （即它在运行时表示的对象的实际类型） 而不是它在具有的类型编译时。 此类操作的绑定因此推迟到其中的操作是在程序运行期间执行的时间。 这被称为***动态绑定***。

当动态绑定操作时，由编译器执行很少或没有检查。 改为如果运行时绑定失败，错误报告为在运行时异常。

根据绑定是在 C# 中的以下操作：

- 成员访问： `e.M`
- 方法调用： `e.M(e1, ..., eN)`
- 委托调用：`e(e1, ..., eN)`
- 元素的访问权限： `e[e1, ..., eN]`
- 创建对象： `new C(e1, ..., eN)`
- 重载一元运算符： `+`， `-`， `!`， `~`， `++`， `--`， `true`， `false`
- 重载二元运算符： `+`， `-`， `*`， `/`， `%`， `&`， `&&`， `|`， `||`， `??`， `^`， `<<`, `>>`, `==`,`!=`, `>`, `<`, `>=`, `<=`
- 赋值运算符： `=`， `+=`， `-=`， `*=`， `/=`， `%=`， `&=`， `|=`， `^=`， `<<=`， `>>=`
- 隐式和显式转换

当不涉及任何动态表达式时，C# 默认为静态绑定，这意味着，在选择过程中使用构成表达式的编译时类型。 但是，在上面列出的操作构成的表达式之一时动态表达式，该操作改为动态绑定。

### 绑定时间

静态绑定都将在编译时进行而动态绑定发生在运行时。 在以下部分中，术语***绑定时***指编译时或运行时间，具体取决于绑定发生。

下面的示例说明了概念和绑定时的静态和动态绑定：

C#复制

```csharp
object  o = 5;
dynamic d = 5;

Console.WriteLine(5);  // static  binding to Console.WriteLine(int)
Console.WriteLine(o);  // static  binding to Console.WriteLine(object)
Console.WriteLine(d);  // dynamic binding to Console.WriteLine(int)
```

前两个调用都以静态方式绑定： 的重载`Console.WriteLine`选择基于其自变量的编译时类型。 因此，绑定时是编译时。

第三个调用动态绑定： 的重载`Console.WriteLine`选择基于其参数的运行时类型。 这是因为自变量是动态表达式--它的编译时类型是`dynamic`。 因此，第三个调用绑定时间是运行时。

### 动态绑定

动态绑定的目的是允许 C# 程序可以与之交互***动态对象***，即不遵循 C# 的一般规则的对象类型系统。 动态对象可能与不同类型系统，其他编程语言中的对象，或者它们可能是以编程方式安装程序以实现自己的绑定语义表示不同的操作的对象。

依据一个动态对象实现其自己的语义的机制是定义的实现。 动态对象，将信号发送到 C# 运行时它们具有特殊的语义由实现给定的接口-再次实现定义。 因此，动态绑定动态对象上的操作，只要它们自己的绑定语义，而不是 C# 中本文档中，指定的接管。

虽然动态绑定的目的是允许使用动态对象互操作，C# 允许动态绑定上的所有对象，无论它们是动态的还是不。这可以更顺畅地集成的动态对象，对其操作的结果可能不是本身是动态对象，但仍属于未知的程序员在编译时类型。 此外动态绑定可以帮助消除易出错的基于反射的代码，即使不不涉及任何对象的动态对象。

以下部分介绍每个构造在语言中完全动态绑定应用时，内容编译时检查-如果应用任何-，和何种编译时结果和表达式分类为。

### 构成表达式的类型

当以静态方式绑定操作时，构成的表达式 （例如接收方和自变量、 索引或操作数） 的类型始终被视为可该表达式的编译时类型。

当动态绑定操作时，具体取决于构成表达式的编译时类型不同的方式确定构成表达式的类型：

- 编译时类型的构成表达式`dynamic`被视为具有表达式计算结果为在运行时的实际值的类型
- 编译时类型为类型参数构成表达式将被视为已在运行时绑定到类型参数的类型
- 否则构成的表达式被视为具有其编译时类型。

## 运算符

表达式从构造***操作数***并***运算符***。 表达式的运算符指明了向操作数应用的运算。 运算符的示例包括 `+`、`-`、`*`、`/` 和 `new`。 操作数的示例包括文本、字段、局部变量和表达式。

有三种类型的运算符：

- 一元运算符。 一元运算符接受一个操作数，并使用任一前缀表示法 (例如`--x`) 或后缀表示法 (例如`x++`)。
- 二元运算符。 二进制运算符采用两个操作数，并且所有使用中缀表示法 (例如`x + y`)。
- 三元运算符。 只有一个三元运算符`?:`，存在; 它采用三个操作数，并使用中缀表示法 (`c ? x : y`)。

在表达式中运算符的计算顺序由***优先***和***关联性***的运算符 ([运算符优先级和结合性](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#operator-precedence-and-associativity)).

从左到右情况下，在表达式中的操作数进行求值。 例如，在`F(i) + G(i++) * H(i)`，方法`F`使用的旧值调用`i`，然后方法`G`使用的旧值调用`i`，并，最后，方法`H`的新值与名为`i`. 这是运算符优先级独立于和不相关。

某些运算符可以是***重载***。 运算符重载允许用户定义的运算符实现为操作指定一个或两个操作数均为用户定义的类或结构类型 ([运算符重载](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#operator-overloading))。

### 运算符优先级和关联性

如果表达式包含多个运算符，那么运算符的***优先级***决定了各个运算符的计算顺序。 例如，表达式`x + y * z`评为`x + (y * z)`因为`*`运算符的优先级高于该二进制文件`+`运算符。 运算符的优先顺序建立其关联的语法生产的定义。 例如， *additive_expression*包含的一系列*multiplicative_expression*s 分隔`+`或`-`运算符，从而为提供`+`和`-`运算符较低的优先级高于`*`， `/`，和`%`运算符。

下表汇总了所有运算符按优先级从高到低的顺序：

| **节**                                                       | **类别**             | **运算符**                                                   |
| ------------------------------------------------------------ | -------------------- | ------------------------------------------------------------ |
| [主要表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#primary-expressions) | 基本                 | `x.y` `f(x)` `a[x]` `x++` `x--` `new` `typeof` `default` `checked``unchecked` `delegate` |
| [一元运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#unary-operators) | 一元                 | `+` `-` `!` `~` `++x` `--x` `(T)x`                           |
| [算术运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#arithmetic-operators) | 乘法                 | `*` `/` `%`                                                  |
| [算术运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#arithmetic-operators) | 加法                 | `+` `-`                                                      |
| [移位运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#shift-operators) | 移位                 | `<<` `>>`                                                    |
| [关系和类型测试运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#relational-and-type-testing-operators) | 关系和类型测试       | `<` `>` `<=` `>=` `is` `as`                                  |
| [关系和类型测试运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#relational-and-type-testing-operators) | 相等                 | `==` `!=`                                                    |
| [逻辑运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#logical-operators) | 逻辑“与”             | `&`                                                          |
| [逻辑运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#logical-operators) | 逻辑 XOR             | `^`                                                          |
| [逻辑运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#logical-operators) | 逻辑“或”             | `|`                                                          |
| [条件逻辑运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#conditional-logical-operators) | 条件“与”             | `&&`                                                         |
| [条件逻辑运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#conditional-logical-operators) | 条件“或”             | `||`                                                         |
| [Null 合并运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#the-null-coalescing-operator) | null 合并            | `??`                                                         |
| [条件运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#conditional-operator) | 条件运算             | `?:`                                                         |
| [赋值运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#assignment-operators)，[匿名函数表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#anonymous-function-expressions) | 赋值和 lambda 表达式 | `=` `*=` `/=` `%=` `+=` `-=` `<<=` `>>=` `&=` `^=` `|=` `=>` |

如果操作数具有相同优先级的两个运算符之间，运算符的关联性控件执行的操作的顺序：

- 除赋值运算符和 null 合并运算符，所有二元运算符均***左结合***，即操作执行从左到右。 例如，`x + y + z` 将计算为 `(x + y) + z`。
- 赋值运算符、 null 合并运算符和条件运算符 (`?:`) 是***右结合运算符***，这意味着从右到左执行运算。 例如，`x = y = z` 将计算为 `x = (y = z)`。

可以使用括号控制优先级和结合性。 例如，`x + y * z` 先计算 `y` 乘 `z`，并将结果与 `x` 相加，而 `(x + y) * z` 则先计算 `x` 加 `y`，然后将结果与 `z` 相乘。

### 运算符重载

所有的一元和二元运算符具有预定义的任何表达式中会自动提供的实现。 除了预定义的实现中，用户定义的实现可以引入通过包括`operator`类和结构中的声明 ([运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#operators))。 用户定义的运算符实现始终优先于预定义的运算符实现：仅当没有适用的用户定义运算符实现存在将会考虑预定义的运算符实现，如中所述[一元运算符重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#unary-operator-overload-resolution)和[二元运算符重载解析](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#binary-operator-overload-resolution)。

***可重载的一元运算符***是：

C#复制

```csharp
+   -   !   ~   ++   --   true   false
```

尽管`true`和`false`不在表达式中显式使用 (并因此不包括的优先顺序表中[运算符优先级和结合性](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#operator-precedence-and-associativity))，因为它们是，它们将被视为运算符在多个表达式上下文中调用： 布尔表达式 ([布尔表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#boolean-expressions)) 和包含条件表达式 ([条件运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#conditional-operator))，和条件逻辑运算符 ([条件逻辑运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#conditional-logical-operators))。

***可重载的二元运算符***是：

C#复制

```csharp
+   -   *   /   %   &   |   ^   <<   >>   ==   !=   >   <   >=   <=
```

只有上面列出的运算符可以进行重载。 具体而言，不能重载成员访问，方法调用中，或`=`， `&&`， `||`， `??`， `?:`， `=>`， `checked`， `unchecked`， `new`， `typeof`， `default`， `as`，和`is`运算符。

重载二元运算符时，也会隐式重载相应的赋值运算符（若有）。 例如，运算符重载`*`也是运算符重载`*=`。 这是中作了进一步介绍[复合赋值](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#compound-assignment)。 请注意，赋值运算符本身 (`=`) 不能重载。 始终分配到一个变量执行简单的值的按位复制。

将强制转换操作，比如`(T)x`，通过提供用户定义的转换重载 ([用户定义的转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#user-defined-conversions))。

元素访问，例如`a[x]`，不被视为输入可重载运算符。 相反，用户定义的索引通过索引器支持 ([索引器](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#indexers))。

在表达式中，使用运算符表示法来引用运算符，并在声明中，使用函数表示法来引用运算符。 下表显示了运算符和函数表示法一元和二元运算符之间的关系。 中的第一个条目*op*表示任何可重载的一元前缀运算符。 在第二个条目中， *op*表示一元后缀`++`和`--`运算符。 在第三个条目中， *op*表示任何可重载的二元运算符。

| **运算符表示法** | **函数表示法**     |
| ---------------- | ------------------ |
| `op x`           | `operator op(x)`   |
| `x op`           | `operator op(x)`   |
| `x op y`         | `operator op(x,y)` |

用户定义的运算符声明始终需要至少一个要包含在运算符声明的类或结构类型的参数。 因此，不能为用户定义的运算符具有与预定义的运算符相同的签名。

用户定义的运算符声明不能修改语法、 优先级或运算符的关联性。 例如，`/`运算符始终是二元运算符始终具有优先级中指定的级别[运算符优先级和结合性](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#operator-precedence-and-associativity)，并且始终是左结合运算符。

用户定义的运算符，可以执行的任何计算它所请求的操作时，生成的结果而非直观地预期的实现都是强烈建议不要使用。 例如，实现`operator ==`应比较是否相等的两个操作数，并返回相应`bool`结果。

中的各个运算符的说明[主表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#primary-expressions)通过[条件逻辑运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#conditional-logical-operators)指定的预定义的运算符和任何其他规则适用的实现与每个运算符。 在这些说明使用的条款***一元运算符重载决策***，***二元运算符重载决策***，并***数值升级***，其中的定义在以下各节中找到。

### 一元运算符重载决策

操作的窗体`op x`或`x op`，其中`op`是可重载的一元运算符，和`x`类型的表达式`X`，处理时，如下所示：

- 提供的候选用户定义运算符的一套`X`操作`operator op(x)`使用的规则确定[候选用户定义的运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#candidate-user-defined-operators)。
- 如果候选用户定义的运算符集不为空，则这成为候选操作的运算符集。 否则为预定义的一元`operator op`实现，包括其提升的窗体，成为候选操作的运算符集。 运算符的说明中指定的预定义的实现给定运算符 ([主表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#primary-expressions)并[一元运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#unary-operators))。
- 重载决策规则[重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#overload-resolution)将应用于的候选运算符来选择关于参数列表的最佳运算符集`(x)`，此运算符将成为该重载的结果解析过程。 如果选择单个最佳运算符重载决策失败，发生绑定时错误。

### 二元运算符重载决策

操作的窗体`x op y`，其中`op`是可重载的二元运算符`x`类型的表达式`X`，和`y`类型的表达式`Y`，处理时，如下所示：

- 提供的候选用户定义运算符的一套`X`并`Y`操作`operator op(x,y)`确定。 集包括的联合提供的候选运算符`X`和由提供的候选运算符`Y`，每个确定使用的规则[候选用户定义的运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#candidate-user-defined-operators)。 如果`X`并`Y`具有相同的类型，或者如果`X`和`Y`派生自公共基类型，然后共享的候选运算符仅在出现的组合集一次。
- 如果候选用户定义的运算符集不为空，则这成为候选操作的运算符集。 否则为预定义的二进制文件`operator op`实现，包括其提升的窗体，成为候选操作的运算符集。 运算符的说明中指定的预定义的实现给定运算符 ([算术运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#arithmetic-operators)通过[条件逻辑运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#conditional-logical-operators))。 对于预定义的枚举和委托运算符，唯一的运算符被视为是定义的其中一个操作数的绑定时类型的枚举或委托类型。
- 重载决策规则[重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#overload-resolution)将应用于的候选运算符来选择关于参数列表的最佳运算符集`(x,y)`，此运算符将成为该重载的结果解析过程。 如果选择单个最佳运算符重载决策失败，发生绑定时错误。

### 候选用户定义的运算符

对于给定的类型`T`和操作`operator op(A)`，其中`op`是可重载运算符和`A`是由用户定义的运算符的参数列表中，组候选`T`为`operator op(A)`确定按如下所示：

- 确定类型`T0`。 如果`T`为 null 的类型，`T0`是其基础类型，否则`T0`等同于`T`。
- 为所有`operator op`中的声明`T0`以及所有提升此类运算符的形式，如果至少一个运算符适用 ([适用函数成员](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#applicable-function-member)) 与参数列表`A`，然后的集候选运算符包含中的所有此类适用运算符`T0`。
- 否则为如果`T0`是`object`，候选运算符集为空。
- 否则，候选运算符集提供的`T0`是一组提供的直接基类的候选运算符`T0`，或有效的类的基类`T0`如果`T0`是类型参数。

### 数值提升

数值升级包含自动执行某些隐式转换的预定义的一元和二进制数字运算符的操作数。 数值提升不是一种不同机制，而是将应用到预定义的运算符重载决策的影响。 数值升级专门不影响评估用户定义的运算符，尽管可以实现用户定义的运算符来表现类似的效果。

作为数值升级的示例，请考虑将二进制文件的预定义的实现`*`运算符：

C#复制

```csharp
int operator *(int x, int y);
uint operator *(uint x, uint y);
long operator *(long x, long y);
ulong operator *(ulong x, ulong y);
float operator *(float x, float y);
double operator *(double x, double y);
decimal operator *(decimal x, decimal y);
```

当重载决策规则 ([重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#overload-resolution)) 应用于此集的运算符的效果是以选择存在隐式转换运算符的第一个操作数类型。 例如，对于该操作`b * s`，其中`b`是`byte`并`s`是`short`，重载解析选择`operator *(int,int)`为最佳的运算符。因此的效果是，`b`并`s`转换为`int`，并且结果的类型为`int`。 同样，为操作`i * d`，其中`i`是`int`并`d`是`double`，重载解析选择`operator *(double,double)`为最佳的运算符。

#### 一元数值提升

预定义的操作数进行一元数值升级`+`， `-`，和`~`一元运算符。 一元数值升级只包含的转换类型的操作数`sbyte`， `byte`， `short`， `ushort`，或`char`以键入`int`。 此外，对于一元`-`运算符，一元数值升级将转换的类型的操作数`uint`键入`long`。

#### 二进制数值提升

预定义的操作数进行二进制数值升级`+`， `-`， `*`， `/`， `%`， `&`， `|`， `^`， `==`， `!=`，`>`， `<`， `>=`，和`<=`二元运算符。 二进制数值升级隐式转换为通用类型的非关系运算符时也将成为该操作的结果类型的两个操作数。 二进制数值升级包含将应用以下规则按其在此处显示的顺序：

- 如果其中一个操作数的类型`decimal`，另一个操作数将转换为类型`decimal`，或者如果另一个操作数的类型发生了绑定时间错误`float`或`double`。
- 否则为如果其中一个操作数的类型`double`，另一个操作数将转换为类型`double`。
- 否则为如果其中一个操作数的类型`float`，另一个操作数将转换为类型`float`。
- 否则为如果其中一个操作数的类型`ulong`，另一个操作数将转换为类型`ulong`，或者如果另一个操作数的类型发生了绑定时间错误`sbyte`， `short`， `int`，或`long`。
- 否则为如果其中一个操作数的类型`long`，另一个操作数将转换为类型`long`。
- 否则为如果其中一个操作数的类型`uint`和另一个操作数的类型是`sbyte`， `short`，或`int`，这两个操作数都转换为键入`long`。
- 否则为如果其中一个操作数的类型`uint`，另一个操作数将转换为类型`uint`。
- 否则，两个操作数都转换为类型`int`。

请注意第一个规则不允许混合使用任何操作`decimal`类型具有`double`和`float`类型。 此规则遵循这一事实之间没有隐式转换从`decimal`类型和`double`和`float`类型。

另请注意不能为操作数的类型是`ulong`当另一个操作数属于有符号的整型。 原因是任何整型类型存在，可以表示完整范围的`ulong`以及带符号整数类型。

在这种上述情况下，强制转换表达式可用于显式将一个操作数转换为符合另一个操作数的类型。

在示例

C#复制

```csharp
decimal AddPercent(decimal x, double percent) {
    return x * (1.0 + percent / 100.0);
}
```

发生绑定时错误的原因`decimal`不能乘以`double`。 通过显式转换的第二个操作数解决错误`decimal`，按如下所示：

C#复制

```csharp
decimal AddPercent(decimal x, double percent) {
    return x * (decimal)(1.0 + percent / 100.0);
}
```

### 提升的运算符

***提升运算符***允许在不可以为 null 的值类型也可用于这些类型的可以为 null 的窗体运行的预定义和用户定义运算符。 提升的运算符构造从预定义和用户定义运算符的满足某些要求，如以下所述：

- 对于一元运算符

  C#复制

  ```csharp
  +  ++  -  --  !  ~
  ```

  如果操作数和结果类型都为这两个不可以为 null 的值类型，运算符的提升的形式存在。 通过将一个构造提升的形式`?`操作数和结果类型的修饰符。 如果操作数为 null，则提升的运算符将产生一个 null 值。 否则为提升的运算符对操作数进行解包、 应用基础运算符，并将结果包装。

- 对于二元运算符

  C#复制

  ```csharp
  +  -  *  /  %  &  |  ^  <<  >>
  ```

  如果操作数和结果类型是所有不可为 null 的值类型，将存在运算符的提升的形式。 通过将一个构造提升的形式`?`为每个操作数和结果的类型修饰符。 提升的运算符产生一个 null 值，如果一个或两个操作数均为 null (异常正在`&`并`|`运算符的`bool?`类型，如中所述[布尔逻辑运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#boolean-logical-operators))。 否则为提升的运算符对操作数进行解包、 应用基础运算符，并将结果包装。

- 相等运算符

  C#复制

  ```csharp
  ==  !=
  ```

  如果操作数类型不可以为 null 的值类型和结果类型是否存在的运算符的提升的形式`bool`。 通过将一个构造提升的形式`?`为每个操作数的类型修饰符。 提升的运算符会将两个 null 值相等，而 null 的值为任何非 null 值不相等。 如果两个操作数都为非空，则提升的运算符对操作数进行解包和应用基础运算符以产生`bool`结果。

- 对于关系运算符

  C#复制

  ```csharp
  <  >  <=  >=
  ```

  如果操作数类型不可以为 null 的值类型和结果类型是否存在的运算符的提升的形式`bool`。 通过将一个构造提升的形式`?`为每个操作数的类型修饰符。 提升的运算符产生值`false`如果一个或两个操作数都为 null。 否则为提升的运算符对操作数进行解包和应用基础运算符以产生`bool`结果。

## 成员查找

成员查找是，由此确定一种类型的上下文中名称的含义的过程。 成员查找可以作为评估过程的一部分出现*simple_name* ([简单名称](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#simple-names)) 或*member_access* ([成员访问](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#member-access)) 中表达式。 如果*simple_name*或*member_access*作为发生*primary_expression*的*invocation_expression* ([方法调用](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#method-invocations))，则称该成员被调用。

如果成员是方法或事件，或如果它是常量、 字段或委托类型的属性 ([委托](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/delegates)) 或类型`dynamic`([动态类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/types#the-dynamic-type))，则称该成员是*invocable*。

成员查找会考虑不仅成员还有数成员具有的类型参数和成员是否可访问的名称。 为了成员查找，泛型方法和嵌套的泛型类型具有在其各自的声明中所指示的类型参数的数目和所有其他成员都具有零个类型参数。

名称的成员查找 `N`与`K` 类型参数的类型中 `T`进行处理，如下所示：

- 首先，可访问的成员名为一组 `N`确定：

  - 如果`T`是一个类型参数，则组是一组可访问的成员名为联合 `N`中每个类型指定为主约束或辅助约束 ([类型参数约束](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#type-parameter-constraints)) 为 `T`，以及可访问的成员命名集 `N`中`object`。
  - 否则，集包括的所有可访问 ([成员访问](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/basic-concepts#member-access)) 成员命名 `N`中 `T`，包括继承的成员和可访问的成员命名 `N`中`object`。 如果`T`是一个构造的类型的成员集获取，只需替换类型参数，如中所述[构造类型的成员](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#members-of-constructed-types)。包含成员的`override`修饰符从集中排除。

- 接下来，如果`K`为零，所有嵌套类型声明中包含的类型参数会删除的。 如果`K`不为零，具有不同数目的类型参数已删除的所有成员。 请注意，当`K`零个、 方法具有的类型参数不会删除，因为类型推断过程 ([类型推理](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#type-inference)) 可能能够推断类型参数。

- 接下来，如果该成员是*调用*，所有非-*invocable*从集中删除成员。

- 接下来，从集中移除其他成员隐藏的成员。

   

  每个成员`S.M`在组中，其中`S`是在其中的类型成员 `M`声明时，将应用以下规则：

  - 如果`M`为常量、 字段、 属性、 事件或枚举成员，则所有成员的基类型中都声明`S`从集中删除。
  - 如果`M`为的类型声明，则所有非类型的基类型中声明`S`从集合中移除和所有类型声明具有相同数量的类型参数作为`M`的基类型中声明`S`删除从组中。
  - 如果`M`是一种方法，然后在基类型中声明非方法的所有成员`S`从集中删除。

- 接下来，是从集中移除接口成员的隐藏的类成员。

   

  此步骤才有意义，如果`T`是一个类型参数和`T`而不具有这两个的有效基类`object`和设置的非空有效接口 ([类型参数约束](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#type-parameter-constraints))。

   

  每个成员`S.M`在组中，其中`S`是在其中的类型成员`M`声明，如果应用以下规则`S`而不是类声明`object`:

  - 如果`M`为常量、 字段、 属性、 事件、 枚举成员或类型声明，则从集中删除接口声明中声明的所有成员。
  - 如果`M`是一种方法，则在接口声明中声明的所有非方法成员删除组，以及所有具有相同的签名方法从`M`声明在接口中声明从集合中移除。

- 最后，删除隐藏的成员，确定查找的结果：

  - 如果集包含不是一种方法的单个成员，此成员是查找的结果。
  - 否则，如果集包含只有方法，此组的方法是查找的结果。
  - 否则为查找不明确的并将绑定时出现错误。

为非类型参数和接口的类型中的成员查找和严格的单一继承的接口中的成员查找 （继承链中的每个接口都只有零个或一个直接基接口），查找规则的效果是只需派生出来的具有相同名称或签名的成员隐藏基成员。 这种单一继承查找会永远不会引起歧义。 中介绍了多个继承接口中的成员查找可能引起歧义[接口成员访问](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/interfaces#interface-member-access)。

### 基类型

有关成员查找，一种类型的目的`T`被视为具有以下基本类型：

- 如果`T`是`object`，然后`T`没有基类型。
- 如果`T`是*enum_type*，类型的基类型`T`是类类型`System.Enum`， `System.ValueType`，和`object`。
- 如果`T`是*struct_type*，类型的基类型`T`是类类型`System.ValueType`和`object`。
- 如果`T`是*class_type*，类型的基类型`T`的基类`T`，其中包括类类型`object`。
- 如果`T`是*interface_type*，类型的基类型`T`是接口的基`T`和类类型`object`。
- 如果`T`是*array_type*，类型的基类型`T`是类类型`System.Array`和`object`。
- 如果`T`是*delegate_type*，类型的基类型`T`是类类型`System.Delegate`和`object`。

## 函数成员

函数成员是包含可执行语句的成员。 函数成员始终是类型的成员，并且不能为命名空间的成员。 C# 定义函数成员的以下的类别：

- 方法
- 属性
- 事件
- 索引器
- 用户定义的运算符
- 实例构造函数
- 静态构造函数
- 析构函数

除了析构函数和静态构造函数 （它们不能显式调用），函数成员中包含的语句执行通过函数成员调用。 编写一个函数成员调用的实际语法取决于特定函数成员类别。

参数列表 ([自变量列表](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#argument-lists)) 的函数成员调用提供了实际值或变量引用的函数成员的参数。

泛型方法的调用可能会使用类型推理来确定要传递给该方法的类型参数的集合。 此过程所述[类型推理](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#type-inference)。

调用的方法、 索引器、 运算符和实例构造函数采用重载解析，以确定要调用的函数成员的候选项集。 此过程所述[重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#overload-resolution)。

一旦确定具体的函数成员在绑定时，可能是通过重载解析调用的函数成员的运行时的实际过程不中所述[编译时检查的动态重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#compile-time-checking-of-dynamic-overload-resolution).

下表总结了涉及可以显式调用的函数成员的六个类别的构造中进行处理。 在表中， `e`， `x`， `y`，和`value`指示表达式分类为变量或值，`T`指示分类为一个类型的表达式`F`是简单的方法，并名称`P`是一个属性的简单名称。

| **构造**         | **示例**         | **说明**                                                     |
| ---------------- | ---------------- | ------------------------------------------------------------ |
| 方法调用         | `F(x,y)`         | 重载决策应用选择最佳方法`F`包含类或结构中。 与参数列表调用该方法`(x,y)`。 如果此方法不是`static`，实例表达式是`this`。 |
|                  | `T.F(x,y)`       | 重载决策应用选择最佳的方法`F`类或结构中`T`。 如果该方法不会发生绑定时间错误`static`。 与参数列表调用该方法`(x,y)`。 |
|                  | `e.F(x,y)`       | 重载决策被用于类、 结构或接口的类型的给定中选择最佳的方法 F `e`。 绑定时错误，则该方法是否`static`。 该方法调用的实例表达式`e`和参数列表`(x,y)`。 |
| 和               | `P`              | `get`属性访问器`P`调用中包含的类或结构。 如果会发生编译时错误`P`是只写的。 如果`P`不是`static`，实例表达式是`this`。 |
|                  | `P = value`      | `set`属性访问器`P`包含类或结构中使用参数列表调用`(value)`。 如果会发生编译时错误`P`是只读的。 如果`P`不是`static`，实例表达式是`this`。 |
|                  | `T.P`            | `get`属性访问器`P`类或结构中`T`调用。 如果会发生编译时错误`P`不是`static`或者如果`P`是只写的。 |
|                  | `T.P = value`    | `set`属性访问器`P`类或结构中`T`与参数列表调用`(value)`。 如果会发生编译时错误`P`不是`static`或者如果`P`是只读的。 |
|                  | `e.P`            | `get`属性访问器`P`在类、 结构或接口的类型的给定`e`调用的实例表达式`e`。 如果绑定时间错误会发生`P`是`static`或者如果`P`是只写的。 |
|                  | `e.P = value`    | `set`属性访问器`P`在类、 结构或接口的类型的给定`e`调用的实例表达式`e`和参数列表`(value)`。 如果绑定时间错误会发生`P`是`static`或者如果`P`是只读的。 |
| 事件访问         | `E += value`     | `add`事件访问器`E`调用中包含的类或结构。 如果`E`为非静态实例表达式是`this`。 |
|                  | `E -= value`     | `remove`事件访问器`E`调用中包含的类或结构。 如果`E`为非静态实例表达式是`this`。 |
|                  | `T.E += value`   | `add`事件访问器`E`类或结构中`T`调用。 绑定时错误，则如果`E`不是静态的。 |
|                  | `T.E -= value`   | `remove`事件访问器`E`类或结构中`T`调用。 绑定时错误，则如果`E`不是静态的。 |
|                  | `e.E += value`   | `add`事件访问器`E`在类、 结构或接口的类型的给定`e`调用的实例表达式`e`。 绑定时错误，则如果`E`是静态的。 |
|                  | `e.E -= value`   | `remove`事件访问器`E`在类、 结构或接口的类型的给定`e`调用的实例表达式`e`。 绑定时错误，则如果`E`是静态的。 |
| 索引器访问       | `e[x,y]`         | 重载决策被用于类、 结构或接口由 e 的类型中选择最佳索引器。 `get`访问器的索引器的调用的实例表达式`e`和参数列表`(x,y)`。 如果索引器是只写，发生绑定时错误。 |
|                  | `e[x,y] = value` | 重载决策应用选择最佳索引器在类、 结构或接口的类型的给定`e`。 `set`访问器的索引器的调用的实例表达式`e`和参数列表`(x,y,value)`。 如果索引器是只读的会发生绑定时错误。 |
| 运算符调用       | `-x`             | 重载决策应用选择最佳的一元运算符中的类或结构的类型的给定`x`。 使用参数列表调用所选的运算符`(x)`。 |
|                  | `x + y`          | 重载决策应用选择最佳的二元运算符中的类或结构类型的给定`x`和`y`。 使用参数列表调用所选的运算符`(x,y)`。 |
| 实例构造函数调用 | `new T(x,y)`     | 重载决策应用选择最佳的实例构造函数中的类或结构`T`。 实例构造函数调用具有参数列表`(x,y)`。 |

### 自变量列表

每个函数成员和委托调用包括一个自变量列表，其中提供的函数成员的参数的实际值或变量引用。 指定的函数成员调用的参数列表的语法取决于函数成员类别：

- 实例构造函数、 方法、 索引器和委托，则参数被指定为*argument_list*，如下所述。 对于索引器，在调用时`set`访问器，自变量列表此外还包括为赋值运算符的右操作数指定的表达式。
- 对于属性，该参数列表为空时调用`get`访问器，并由调用时指定为赋值运算符的右操作数的表达式组成`set`访问器。
- 对于事件，参数列表包含指定为右操作数的表达式`+=`或`-=`运算符。
- 对于用户定义的运算符，参数列表包含的单个运算符的操作数的一元或二元运算符的两个操作数。

属性的参数 ([属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#properties))，事件 ([事件](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#events))，和用户定义的运算符 ([运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#operators)) 始终作为值参数传递 ([值参数](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#value-parameters))。 索引器的自变量 ([索引器](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#indexers)) 始终作为值参数传递 ([值参数](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#value-parameters)) 或参数数组 ([参数数组](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#parameter-arrays))。 不支持对这些类别的函数成员的引用和输出参数。

实例构造函数、 方法、 索引器或委托调用的参数被指定为*argument_list*:

antlr复制

```antlr
argument_list
    : argument (',' argument)*
    ;

argument
    : argument_name? argument_value
    ;

argument_name
    : identifier ':'
    ;

argument_value
    : expression
    | 'ref' variable_reference
    | 'out' variable_reference
    ;
```

*Argument_list*包含一个或多个*自变量*s，由逗号分隔。 每个自变量组成的可选*argument_name*跟*argument_value*。 *自变量*与*argument_name*称为***命名参数***，而*参数*而无需*argument_name*是***位置自变量***。 它是错误的位置自变量中的命名参数后出现*argument_list*。

*Argument_value*可以采用以下形式之一：

- *表达式*，指示作为值参数传递自变量 ([值参数](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#value-parameters))。
- 关键字`ref`跟*variable_reference* ([变量引用](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/variables#variable-references))，指示作为引用参数传递参数 ([引用参数](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#reference-parameters)). 变量必须明确赋值 ([明确赋值](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/variables#definite-assignment)) 它可以作为引用参数传递之前。 关键字`out`跟*variable_reference* ([变量引用](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/variables#variable-references))，指示作为输出参数传递参数 ([输出参数](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#output-parameters)). 被视为一个变量明确赋值 ([明确赋值](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/variables#definite-assignment)) 在该变量传递作为输出参数的函数成员调用之后。

#### 相应的参数

对于每个自变量参数列表中必须有委托调用的函数成员中的相应参数。

在下面使用的参数列表中，如下所示确定：

- 对于虚拟方法和类中定义的索引器，参数列表从最具体的声明中选取或重写的函数成员，开头的静态类型的接收方，并通过其基类，这些类搜索。
- 对于接口方法和索引器，选择的参数列表窗体中的成员，从接口类型和搜索的基接口中的最具体的定义。如果找到任何唯一的参数列表，构造具有不可访问的名称和任何可选参数的参数列表，以便调用不能使用命名的参数或省略可选参数。
- 对于分部方法，使用定义的分部方法声明的参数列表。
- 对于所有其他函数成员和委托没有仅一个单一参数列表，即使用。

自变量或参数的位置定义为参数的个数或参数列表或参数列表中前面的参数。

建立函数成员参数的相应参数，如下所示：

- 中的自变量*argument_list*的实例构造函数、 方法、 索引器和委托：
  - 固定的参数出现在参数列表中的相同位置的位置自变量对应于该参数。
  - 以普通形式调用的参数数组的函数成员的位置自变量对应于参数数组，必须在参数列表中的同一位置。
  - 带有以扩展形式，其中没有固定的参数出现在参数列表中的同一位置中，调用的参数数组的函数成员的位置自变量对应于参数数组中的元素。
  - 命名的参数对应于参数列表中的相同名称的参数。
  - 对于索引器，在调用时`set`访问器，指定为赋值运算符的右操作数对应的隐式表达式`value`参数的`set`访问器声明。
- 对于属性，调用时`get`有访问器都没有自变量。 调用时`set`访问器，指定为赋值运算符的右操作数对应的隐式表达式`value`参数的`set`访问器声明。
- 对于用户定义的一元运算符 （包括转换），单个操作数与运算符声明的单个参数相对应。
- 对于用户定义二元运算符，对应于第一个参数的左的操作数和右操作数与运算符声明的第二个参数相对应。

#### 运行时计算的自变量列表

函数成员调用的运行时处理过程中 ([进行编译时检查的动态重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#compile-time-checking-of-dynamic-overload-resolution))，表达式或变量引用自变量列表的顺序从左到右，评估为如下所示：

- 对于值参数，参数表达式求值的隐式转换和 ([隐式转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#implicit-conversions)) 为相应的参数执行类型。 生成的值将成为该函数成员的调用中的值参数的初始值。
- 对于引用或输出参数，计算变量的引用和生成的存储位置将成为中函数成员调用的参数所表示的存储位置。如果引用或输出参数中给出的变量引用的数组元素*reference_type*，将运行时检查以确保数组的元素类型与参数的类型相同。 如果此检查失败，`System.ArrayTypeMismatchException`引发。

方法、 索引器和实例构造函数可以声明为一个参数数组，其最右边的参数 ([参数数组](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#parameter-arrays))。 此类函数成员调用其正常形式或以其具体取决于所适用的扩展形式 ([适用函数成员](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#applicable-function-member)):

- 在最普通的形式调用带有参数数组的函数成员时，提供的参数数组的参数必须是一个隐式转换的表达式 ([隐式转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#implicit-conversions)) 为参数数组类型。 在这种情况下，参数数组的作用与值参数完全一样。
- 调用以展开形式调用带有参数数组的函数成员时，必须指定参数数组，其中每个参数都是隐式转换的表达式的零个或多个位置自变量 ([隐式转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#implicit-conversions)) 为参数数组的元素类型。 在这种情况下，调用创建具有对应的参数的数目的长度参数数组类型的实例、 初始化具有给定的参数值的数组实例的元素并将新创建的数组实例用作实际自变量。

写入时的顺序始终计算自变量列表的表达式。 因此，示例

C#复制

```csharp
class Test
{
    static void F(int x, int y = -1, int z = -2) {
        System.Console.WriteLine("x = {0}, y = {1}, z = {2}", x, y, z);
    }

    static void Main() {
        int i = 0;
        F(i++, i++, i++);
        F(z: i++, x: i++);
    }
}
```

生成输出

复制

```
x = 0, y = 1, z = 2
x = 4, y = -1, z = 3
```

数组协变规则 ([数组协方差](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/arrays#array-covariance)) 允许使用数组类型的值`A[]`是对的数组类型实例的引用`B[]`，则从存在的隐式引用转换`B`到`A`. 由于这些规则的数组元素时*reference_type*传递作为引用或输出参数，运行时检查是需要确保数组的实际元素类型是相同的参数。 在示例

C#复制

```csharp
class Test
{
    static void F(ref object x) {...}

    static void Main() {
        object[] a = new object[10];
        object[] b = new string[10];
        F(ref a[0]);        // Ok
        F(ref b[1]);        // ArrayTypeMismatchException
    }
}
```

第二次调用`F`会导致`System.ArrayTypeMismatchException`因为实际的元素类型的引发`b`是`string`而不`object`。

正如使用数组初始值设定项的数组创建表达式以展开形式调用带有参数数组的函数成员时，处理调用 ([数组创建表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#array-creation-expressions)) 周围插入扩展的参数。 例如，给定声明

C#复制

```csharp
void F(int x, int y, params object[] args);
```

该方法的展开形式的以下调用

C#复制

```csharp
F(10, 20);
F(10, 20, 30, 40);
F(10, 20, 1, "hello", 3.0);
```

完全对应于

C#复制

```csharp
F(10, 20, new object[] {});
F(10, 20, new object[] {30, 40});
F(10, 20, new object[] {1, "hello", 3.0});
```

具体而言，请注意有零个参数提供的参数数组时，创建一个空数组。

当从带有相应的可选参数的函数成员省略参数时，隐式传递函数成员声明的默认参数。 这些始终是常量，因为其评估不会影响其余的参数的计算顺序。

### 类型推理

不指定类型参数的情况下调用泛型方法时***类型推理***进程将尝试推断调用的类型参数。 类型推断存在允许更方便的语法，用于调用泛型方法，并允许程序员不必指定冗余类型信息。 例如，给定方法声明：

C#复制

```csharp
class Chooser
{
    static Random rand = new Random();

    public static T Choose<T>(T first, T second) {
        return (rand.Next(2) == 0)? first: second;
    }
}
```

可以调用`Choose`而无需显式指定类型参数的方法：

C#复制

```csharp
int i = Chooser.Choose(5, 213);                 // Calls Choose<int>

string s = Chooser.Choose("foo", "bar");        // Calls Choose<string>
```

通过类型推断的类型实参`int`和`string`将根据对方法的参数。

作为方法调用的绑定时处理的一部分，会发生类型推理 ([方法调用](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#method-invocations)) 和调用的重载解决方法步骤之前发生。 在方法调用中，指定某一特定方法组并作为方法调用的一部分未指定任何类型参数，类型推理被应用于方法组中每个泛型方法。 如果类型推理成功，然后推断的类型参数用于确定后续重载解决方法的参数的类型。 如果重载决策选择与要调用泛型方法，然后推断的类型参数用作调用的实际类型参数。 如果使用的特定方法的类型推理失败，该方法将不参与重载决策。 失败的类型推断，本身并不会导致绑定时错误。 但是，它通常会导致绑定时错误时重载决策然后未能找到任何适用的方法。

如果提供的参数数目与方法中的参数的数目不同，则推断立即失败。 否则，假定该泛型方法具有以下签名：

C#复制

```csharp
Tr M<X1,...,Xn>(T1 x1, ..., Tm xm)
```

使用窗体的方法调用`M(E1...Em)`类型推断的任务是查找唯一类型参数`S1...Sn`为每个类型参数`X1...Xn`，以便在调用`M<S1...Sn>(E1...Em)`开始生效。

推理过程中，每个类型参数`Xi`可以是*修复*为特定类型`Si`或*非固定*具有一组关联的*边界*. 每个边界都是某种类型`T`。 最初的每个类型变量`Xi`是未固定的边界为空集。

类型推理分阶段进行。 每个阶段将尝试推断根据上一阶段发现更多类型的变量的类型参数。 第一阶段可指定边界内的某些初始推断，而第二个阶段解决了为特定类型的类型变量并进一步推断边界。 第二个阶段都必须重复次数的时间。

*注意：* 类型推理，将发生不只调用泛型方法。 中介绍了为方法组转换的类型推理[类型推理为方法组转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#type-inference-for-conversion-of-method-groups)和中所述查找一组表达式的最常见类型[查找一组的最常见类型表达式的](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#finding-the-best-common-type-of-a-set-of-expressions)。

#### 第一阶段

为每个方法自变量`Ei`:

- 如果`Ei`是一个匿名函数*显式参数类型推断*([显式参数类型推断](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#explicit-parameter-type-inferences)) 从进行`Ei`到 `Ti`
- 否则为如果`Ei`具有类型`U`和`xi`是一个值参数，则*下限推断*由*从* `U` *到*`Ti`.
- 否则为如果`Ei`具有类型`U`并`xi`是`ref`或`out`参数则*精确推理*由*从* `U`*到* `Ti`。
- 否则，不进行推断。 为此参数。

#### 第二个阶段

第二个阶段将继续，如下所示：

- 所有*非固定*类型变量`Xi`哪些则不*依赖于*([依赖](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#dependence)) 任何`Xj`固定的 ([正在修复](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#fixing)).
- 如果没有此类类型变量存在，所有*非固定*类型变量`Xi`是*修复*为其所有以下保存：
  - 至少一个类型变量`Xj`这取决于 `Xi`
  - `Xi` 具有非空集合的界限
- 如果存在任何此类类型的变量，并且仍有*非固定*类型变量、 类型推断将失败。
- 否则为如果无法进一步*非固定*类型变量存在，则类型推理成功。
- 否则，为所有参数`Ei`相应的参数类型与`Ti`其中*输出类型*([输出类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#output-types)) 包含*非固定*键入变量`Xj`但*输入类型*([输入类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#input-types)) 不会这样，*输出类型推理*([输出类型推断](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#output-type-inferences)) 进行*从* `Ei` *到* `Ti`。 然后，重复执行第二个阶段。

#### 输入的类型

如果`E`是一个方法组或隐式类型的匿名函数和`T`类型或表达式树类型则的所有参数类型是一个委托`T`是*输入类型*的`E` *具有类型* `T`。

#### 输出类型

如果`E`是一个方法组或匿名函数和`T`类型或表达式树类型然后的返回类型是一个委托`T`是*输出的类型* `E` *与类型* `T`.

#### 依赖关系

*非固定*类型的变量`Xi`*直接依赖于*固定的类型变量`Xj`如果某些参数`Ek`类型`Tk` `Xj`中发生*输入类型*的`Ek`与类型`Tk`并`Xi`中发生*输出类型*的`Ek`类型`Tk`。

`Xj` *取决于*`Xi`如果`Xj`*直接依赖于*`Xi`或者如果`Xi`*直接依赖于*`Xk`和`Xk`*取决于* `Xj`。 因此，"依赖于"是"直接依赖于"的可传递，但不是反身闭包。

#### 输出类型推断

*输出类型推理*由*从*表达式`E`*到*类型`T`如下所示：

- 如果`E`是一个匿名函数推断返回类型与`U`([推断返回类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#inferred-return-type)) 和`T`是委托类型或返回类型与表达式目录树类型`Tb`，然后*下限推断*([下限推断](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#lower-bound-inferences)) 由*从* `U` *到* `Tb`。
- 否则为如果`E`是一个方法组和`T`是委托类型或参数类型的表达式目录树类型`T1...Tk`和返回类型`Tb`，和的重载解析`E`与类型`T1...Tk`生成单一方法具有返回类型`U`，然后*下限推断*由*从* `U` *到* `Tb`。
- 否则为如果`E`是具有类型的表达式`U`，然后*下限推断*由*从* `U` *到* `T`.
- 否则，不进行任何推断。

#### 显式参数类型推断

*显式参数类型推断*由*从*表达式`E`*到*类型`T`如下所示：

- 如果`E`是一个显式类型化的匿名函数参数类型与`U1...Uk`并`T`是委托类型或参数类型的表达式目录树类型`V1...Vk`然后对于每个`Ui`*确切推理*([精确推断](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#exact-inferences)) 进行*从* `Ui` *到*相应`Vi`。

#### 确切推断

*精确推理**从*类型`U`*到*类型`V`由，如下所示：

- 如果`V`是之一*非固定*`Xi`然后`U`添加到的确切边界集`Xi`。

- 否则，设置`V1...Vk`和`U1...Uk`由检查是否任何以下情况下适用：

  - `V` 是一个数组类型`V1[...]`并`U`是一个数组类型`U1[...]`相同的排名
  - `V` 是类型`V1?`和`U`是类型 `U1?`
  - `V` 为构造的类型`C<V1...Vk>`和`U`为构造的类型 `C<U1...Uk>`

  如果任何这些情况下然后适用*精确推理*由*从*每个`Ui`*到*相应`Vi`。

- 否则不进行任何推断。

#### 下界推断

一个*下限推断**从*类型`U`*到*类型`V`由，如下所示：

- 如果`V`是之一*非固定*`Xi`然后`U`添加到的一套为下限`Xi`。

- 否则为如果`V`是类型`V1?`并`U`是类型`U1?`则从进行下限推断`U1`到`V1`。

- 否则，设置`U1...Uk`和`V1...Vk`由检查是否任何以下情况下适用：

  - `V` 是一个数组类型`V1[...]`并`U`是一个数组类型`U1[...]`(或类型参数的有效基类型是`U1[...]`) 相同的排名

  - `V` 是的一个`IEnumerable<V1>`，`ICollection<V1>`或`IList<V1>`并`U`是一维数组类型`U1[]`(或类型参数的有效基类型是`U1[]`)

  - `V` 为构造的类、 结构、 接口或委托类型`C<V1...Vk>`且是唯一的类型`C<U1...Uk>`以便`U`(或者，如果`U`是类型参数、 其有效的基类或其有效的接口集的任何成员) 是要完全相同 （直接或间接） 继承或实现 （直接或间接） `C<U1...Uk>`。

    ("唯一性"限制意味着，在大小写的界面`C<T> {} class U: C<X>, C<Y> {}`，则无法推断进行时推断`U`到`C<T>`因为`U1`可能是`X`或`Y`。)

  如果任何这些情况下适用进行推断*从*每个`Ui`*到*相应`Vi`，如下所示：

  - 如果`Ui`未知引用类型，然后*精确推理*由
  - 否则为如果`U`是一个数组类型，然后*下限推断*由
  - 否则为如果`V`是`C<V1...Vk>`推理取决于的第 i 个类型参数，然后`C`:
    - 如果它是协变，然后*下限推断*进行。
    - 如果它是逆变则*上限推断*进行。
    - 如果它是固定然后*精确推理*进行。

- 否则，不进行任何推断。

#### 上限推断

*上限推断**从*类型`U`*到*类型`V`由，如下所示：

- 如果`V`是之一*非固定*`Xi`然后`U`添加到为上限的一套`Xi`。

- 否则，设置`V1...Vk`和`U1...Uk`由检查是否任何以下情况下适用：

  - `U` 是一个数组类型`U1[...]`并`V`是一个数组类型`V1[...]`相同的排名

  - `U` 是的一个`IEnumerable<Ue>`，`ICollection<Ue>`或`IList<Ue>`和`V`是一维数组类型 `Ve[]`

  - `U` 是类型`U1?`和`V`是类型 `V1?`

  - `U` 是构造的类、 结构、 接口或委托类型`C<U1...Uk>`和`V`（直接或间接） 是一个类、 结构、 接口或委托的类型相同，继承自 （直接或间接），该类型或实现一个唯一的类型 `C<V1...Vk>`

    ("唯一性"限制意味着，如果我们有`interface C<T>{} class V<Z>: C<X<Z>>, C<Y<Z>>{}`，则无法推断进行时推断`C<U1>`到`V<Q>`。 从不进行推断`U1`至任一`X<Q>`或`Y<Q>`。)

  如果任何这些情况下适用进行推断*从*每个`Ui`*到*相应`Vi`，如下所示：

  - 如果`Ui`未知引用类型，然后*精确推理*由
  - 否则为如果`V`是一个数组类型，然后*上限推断*由
  - 否则为如果`U`是`C<U1...Uk>`推理取决于的第 i 个类型参数，然后`C`:
    - 如果它是协变，然后*上限推断*进行。
    - 如果它是逆变则*下限推断*进行。
    - 如果它是固定然后*精确推理*进行。

- 否则，不进行任何推断。

#### 修复

*非固定*类型的变量`Xi`与一组边界*修复*，如下所示：

- 一套*候选类型*`Uj`边界组中的所有类型的集的起始点`Xi`。
- 然后，我们检查的每个绑定`Xi`反过来：对于每个确切绑定`U`的`Xi`所有类型`Uj`不等于`U`从候选集合中移除。 对于每个下限`U`的`Xi`所有类型`Uj`到另一个的位置是*不*隐式转换`U`从候选集合中移除。 对于每个上限`U`的`Xi`所有类型`Uj`从其中有*不*隐式转换为`U`从候选集合中移除。
- 如果在其余候选类型之间`Uj`唯一类型`V`它们没有隐式转换为所有的其他候选类型，然后从`Xi`被固定为`V`。
- 否则，类型推理失败。

#### 推断返回类型

返回一个匿名函数的类型推断出`F`在类型推理和重载解析过程中使用。 仅可以为所有参数类型已知的或者用户显式获得了，因为通过匿名函数转换提供或推断在上的类型推理封闭泛型过程的其中一个匿名函数确定推断返回类型方法调用。

***推断出的结果类型***，如下所示确定：

- 如果正文`F`是*表达式*具有一个类型，然后推断的结果类型为`F`是该表达式的类型。
- 如果正文`F`是*块*和表达式块中的一`return`语句具有最佳的通用类型`T`([查找一组表达式的最常见类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#finding-the-best-common-type-of-a-set-of-expressions))，然后推断的结果类型为`F`是`T`。
- 否则，不能为推断结果类型`F`。

***推断返回类型***，如下所示确定：

- 如果`F`是异步和正文`F`是归类为执行任何操作的表达式 ([表达式分类](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#expression-classifications))，或语句块，其中没有返回语句具有表达式，推断出的返回类型是 `System.Threading.Tasks.Task`
- 如果`F`异步，且是一个推断的结果类型`T`，推断出的返回类型是`System.Threading.Tasks.Task<T>`。
- 如果`F`非异步，且是一个推断的结果类型`T`，推断出的返回类型是`T`。
- 否则，不能为推断返回类型`F`。

作为涉及匿名函数的类型推理的示例，请考虑`Select`扩展方法中声明`System.Linq.Enumerable`类：

C#复制

```csharp
namespace System.Linq
{
    public static class Enumerable
    {
        public static IEnumerable<TResult> Select<TSource,TResult>(
            this IEnumerable<TSource> source,
            Func<TSource,TResult> selector)
        {
            foreach (TSource element in source) yield return selector(element);
        }
    }
}
```

假设`System.Linq`命名空间与已导入`using`子句，并给定一个类`Customer`与`Name`类型的属性`string`，则`Select`方法可用于选择一个客户列表的名称：

C#复制

```csharp
List<Customer> customers = GetCustomerList();
IEnumerable<string> names = customers.Select(c => c.Name);
```

扩展方法调用 ([扩展方法调用](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#extension-method-invocations)) 的`Select`处理的重写的静态方法调用的调用：

C#复制

```csharp
IEnumerable<string> names = Enumerable.Select(customers, c => c.Name);
```

由于未显式指定类型参数，使用类型推理来推断类型参数。 首先，`customers`参数与`source`参数，推断`T`为`Customer`。 然后，使用匿名函数键入推断过程，上面所述`c`给定类型`Customer`，和表达式`c.Name`的返回类型与相关`selector`参数，推断`S`要`string`. 因此，调用等同于

C#复制

```csharp
Sequence.Select<Customer,string>(customers, (Customer c) => c.Name)
```

结果的类型为`IEnumerable<string>`。

下面的示例演示如何匿名函数类型推理允许"流"中的泛型方法调用的自变量之间的类型信息。 对于给定的方法：

C#复制

```csharp
static Z F<X,Y,Z>(X value, Func<X,Y> f1, Func<Y,Z> f2) {
    return f2(f1(value));
}
```

调用的类型推断：

C#复制

```csharp
double seconds = F("1:15:30", s => TimeSpan.Parse(s), t => t.TotalSeconds);
```

将继续，按如下所示：首先，该参数`"1:15:30"`与相关`value`参数，推断`X`为`string`。 然后，第一个匿名函数的参数`s`，为给定的推断的类型`string`，和表达式`TimeSpan.Parse(s)`的返回类型与相关`f1`、 推断`Y`为`System.TimeSpan`。 最后，第二个匿名函数的参数`t`，为给定的推断的类型`System.TimeSpan`，和表达式`t.TotalSeconds`的返回类型与相关`f2`、 推断`Z`为`double`。 因此，调用的结果属于类型`double`。

#### 为方法组转换的类型推理

与泛型方法的调用类似，类型推断还必须应用时方法组`M`包含泛型方法转换为给定的委托类型`D`([方法组转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#method-group-conversions))。 给定方法

C#复制

```csharp
Tr M<X1...Xn>(T1 x1 ... Tm xm)
```

和方法组`M`赋给委托类型`D`的类型推理任务是查找类型实参`S1...Sn`以便表达式：

C#复制

```csharp
M<S1...Sn>
```

将成为兼容 ([委托声明](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/delegates#delegate-declarations)) 与`D`。

与不同的泛型方法调用的类型推断算法，在这种情况下有仅参数*类型*，没有参数*表达式*。 具体而言，没有匿名函数，因此无需进行推理的多个阶段。

相反，所有`Xi`被视为*非固定*，和一个*下限推断*由*从*每个参数类型`Uj`的`D`*到*对应的参数类型`Tj`的`M`。 如果任一`Xi`没有找到，类型推理失败。 否则为所有`Xi`都*修复*到对应`Si`，这是类型推理的结果。

#### 查找一组表达式的最常见类型

在某些情况下，需要为一组表达式推断通用类型。 在特定、 隐式类型化数组的元素类型和使用匿名函数的返回类型*块*正文在这种方式中找到。

直观地说，给定一组表达式`E1...Em`此推断应为等效于调用方法

C#复制

```csharp
Tr M<X>(X x1 ... X xm)
```

使用`Ei`作为参数。

更确切地说，推理首先*非固定*类型的变量`X`。 *输出类型推理*然后做*从*每个`Ei`*到* `X`。 最后，`X`是*修复*和，如果成功，则生成键入`S`是表达式的结果的最通用类型。 如果没有此`S`存在，两个表达式有任何最佳的常用类型。

### 重载决策

重载解析是绑定时机制，用于选择要调用给定的参数列表和一组候选函数成员的最佳函数成员。 重载决策选择要在 C# 中下列不同的上下文中调用的函数成员：

- 在名为方法的调用*invocation_expression* ([方法调用](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#method-invocations))。
- 实例构造函数中名为调用*object_creation_expression* ([对象创建表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#object-creation-expressions))。
- 索引器取值函数通过调用*element_access* ([元素访问](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#element-access))。
- 在表达式中引用预定义或用户定义运算符的调用 ([一元运算符重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#unary-operator-overload-resolution)并[二元运算符重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#binary-operator-overload-resolution))。

这些上下文中的每个定义的候选函数成员集的参数列表中和其自己独特的方式，上面列出的章节中的详细信息中所述。 例如，为方法调用的候选项的集不包括标记的方法`override`([成员查找](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#member-lookup))，而且在基类中的方法不是候选项，如果派生类中的任何方法适用 ([方法调用](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#method-invocations))。

一旦已确定候选函数成员和参数列表，最佳函数成员的选择是在所有情况下相同的：

- 给定的一套适用的候选函数成员，最佳函数成员的操作，在其中找到。 如果集包含只有一个函数成员，则该函数成员为最佳的函数成员。 否则，最佳函数成员是优于成员对给定的参数列表中，前提是每个函数成员进行比较的使用中的规则的所有其他函数成员的一个函数成员[更好的函数成员](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#better-function-member)。 如果不完全是一个函数成员优于所有其他函数成员，则该函数成员的调用是不明确和绑定时出错。

以下几节定义条款的准确含义***适用函数成员***并***更好的函数成员***。

#### 适用函数成员

函数成员称为***适用函数成员***相对于参数列表`A`当所有以下均为 true:

- 在每个自变量`A`对应于函数成员声明中的参数，如中所述[相应参数](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#corresponding-parameters)，和任何自变量对应的任何参数是一个可选参数。
- 中每个参数的`A`、 参数传递的参数的模式 (即，值`ref`，或`out`) 等同于的相应参数的参数传递模式和
  - 值参数或参数数组的隐式转换 ([隐式转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#implicit-conversions)) 存在从参数到的相应参数的类型或
  - 有关`ref`或`out`参数自变量的类型是与对应参数的类型相同。 毕竟`ref`或`out`参数是传递的参数的别名。

对于函数成员，包括参数数组，如果通过上述规则适用的函数成员，它则称其适用于其***范式***。 如果包括参数数组的函数成员，以常规形式适用函数成员而可能适用于其***扩展窗体***:

- 扩展的形式构造的函数成员声明中的形参数组替换为零或更多值参数的参数的元素类型的数组，如该自变量列表中的参数数目`A`匹配总计参数数目。 如果`A`函数成员声明中具有较少的参数，而固定的参数数目、 的函数成员的展开的形式不能构造，因此不适用。
- 否则，扩展的形式是适用于在每个自变量如果`A`自变量的参数传递模式等同于的相应参数的参数传递模式和
  - 固定的值参数或创建扩展的隐式转换的值参数 ([隐式转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#implicit-conversions)) 存在从自变量的类型的相应参数的类型或
  - 有关`ref`或`out`参数自变量的类型是与对应参数的类型相同。

#### 更好的函数成员

为了确定更好的函数成员，精简的实参列表 A 构造包含只参数表达式本身原始的参数列表中的显示顺序。

参数列出了为每个候选函数成员的构造如下所示：

- 如果函数成员是只适用于扩展的形式，则使用扩展的形式。
- 从参数列表中删除没有相应的自变量的可选参数
- 因此，它们在与相应的自变量参数列表中相同的位置会发生重新排序参数。

给定的参数列表`A`与一组自变量表达式`{E1, E2, ..., En}`和两个适用的函数成员`Mp`和`Mq`与参数类型`{P1, P2, ..., Pn}`并`{Q1, Q2, ..., Qn}`，`Mp`被定义为***更好的函数成员***比`Mq`如果

- 对于每个参数，请从隐式转换`Ex`到`Qx`不是从隐式转换优于`Ex`到`Px`，和
- 对于至少一个参数，请从转换`Ex`到`Px`从转换优于`Ex`到`Qx`。

在执行此计算时，如果`Mp`或`Mq`是适用于它的扩展形式，然后`Px`或`Qx`指的是展开形式的参数列表中的参数。

如果参数类型序列 `{P1, P2, ..., Pn}`和`{Q1, Q2, ..., Qn}`是等效的 (即每个`Pi`标识转换为相应`Qi`)，以下的决定性规则，按顺序应用，以确定，性能越好函数成员。

- 如果`Mp`是一种非泛型方法和`Mq`是一个泛型方法，则`Mp`优于`Mq`。

- 否则为如果`Mp`适用于其正常的窗体并`Mq`已`params`数组也适用于仅在其扩展形式中，然后`Mp`优于`Mq`。

- 否则为如果`Mp`的详细信息已声明参数比`Mq`，然后`Mp`优于`Mq`。 发生这种情况这两种方法具有`params`数组，并且只适用于它们扩展的形式。

- 如果所有参数的`Mp`具有相应参数，而默认自变量需要替换为在至少一个可选参数`Mq`然后`Mp`优于`Mq`。

- 否则为如果`Mp`具有更具体的参数类型比`Mq`，然后`Mp`优于`Mq`。

   

  让`{R1, R2, ..., Rn}`并`{S1, S2, ..., Sn}`表示未实例化和非扩展的参数类型的`Mp`和`Mq`。

   

  `Mp`参数类型为比更具体`Mq`的当每个参数，对于`Rx`不是具体`Sx`，和至少一个参数`Rx`比更具体`Sx`:

  - 类型参数是更具体的非类型参数。
  - 以递归方式，构造的类型是不是另一个构造的类型 （具有相同的类型参数） 如果至少一个类型实参是更具体且没有类型参数为更具体的相应类型参数中的其他更具体。
  - 如果第一个元素类型是比第二个元素类型更具体，数组类型是比 （具有相同维数的） 的另一个数组类型更具体。

- 否则，如果一个成员是一个非提升运算符，另一个提升的运算符，是更好的非提升一个。

- 否则，两个函数成员是更好。

#### 从表达式更好的转换

给定的隐式转换`C1`，它将从表达式`E`为某种`T1`，和隐式转换`C2`，它将从表达式`E`为某种`T2`， `C1`是***更好的转换***比`C2`如果`E`不完全匹配`T2`和至少一个以下包含：

- `E` 完全匹配`T1`([表达式完全匹配的](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#exactly-matching-expression))
- `T1` 是更好的转换目标比`T2`([更好地转换目标](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#better-conversion-target))

#### 完全匹配的表达式

提供了一个表达式`E`并键入`T`，`E`完全匹配`T`如果下列之一保存：

- `E` 具有类型`S`，并且是标识转换存在一个从`S`到 `T`
- `E` 是一个匿名函数`T`是委托类型`D`或表达式树类型`Expression<D>`和以下之一保存：
  - 推断返回类型`X`存在`E`中的参数列表的上下文`D`([推断返回类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#inferred-return-type))，并且是标识转换存在一个从`X`到的返回类型 `D`
  - 任一`E`为非异步和`D`具有返回类型`Y`或`E`是异步和`D`具有返回类型`Task<Y>`，并包含以下项之一：
    - 正文`E`是完全匹配的表达式 `Y`
    - 正文`E`是语句块，其中每个 return 语句返回的表达式完全匹配的 `Y`

#### 更好地转换目标

提供两种不同类型`T1`并`T2`，`T1`是更好的转换目标比`T2`如果从没有隐式转换`T2`到`T1`存在，并在至少一个以下保留：

- 隐式转换`T1`到`T2`存在

- `T1` 是委托类型`D1`或表达式树类型`Expression<D1>`，`T2`是委托类型`D2`或表达式树类型`Expression<D2>`，`D1`具有返回类型`S1`以及之一以下包含：

  - `D2` 返回 void
  - `D2` 具有返回类型`S2`，和`S1`是比更好地转换目标 `S2`

- `T1` 是`Task<S1>`，`T2`是`Task<S2>`，和`S1`是比更好地转换目标 `S2`

- `T1` 是`S1`或`S1?`其中`S1`是带符号的整型类型，以及`T2`是`S2`或`S2?`其中`S2`是无符号整数类型。

  尤其是在下列情况下：

  - `S1` 是`sbyte`并`S2`是`byte`， `ushort`， `uint`，或 `ulong`
  - `S1` 是`short`并`S2`是`ushort`， `uint`，或 `ulong`
  - `S1` 是`int`并`S2`是`uint`，或 `ulong`
  - `S1` 是`long`和`S2`是 `ulong`

#### 泛型类中重载

声明的签名必须是唯一的而是可能的类型参数替换的会导致完全相同的签名。 在这种情况下，更高版本的重载决策的决定性规则将挑选最明确的成员。

以下示例显示有效和无效根据此规则的重载：

C#复制

```csharp
interface I1<T> {...}

interface I2<T> {...}

class G1<U>
{
    int F1(U u);                  // Overload resolution for G<int>.F1
    int F1(int i);                // will pick non-generic

    void F2(I1<U> a);             // Valid overload
    void F2(I2<U> a);
}

class G2<U,V>
{
    void F3(U u, V v);            // Valid, but overload resolution for
    void F3(V v, U u);            // G2<int,int>.F3 will fail

    void F4(U u, I1<V> v);        // Valid, but overload resolution for    
    void F4(I1<V> v, U u);        // G2<I1<int>,int>.F4 will fail

    void F5(U u1, I1<V> v2);      // Valid overload
    void F5(V v1, U u2);

    void F6(ref U u);             // valid overload
    void F6(out V v);
}
```

### 编译时检查的动态重载决策

对于最动态绑定操作的一套用于解析可能的候选项是在编译时未知。 在某些情况下，但候选集知道在编译时：

- 使用动态参数的静态方法调用
- 接收方不是动态表达式的实例方法调用
- 索引器调用接收方不是动态表达式
- 使用动态参数的构造函数调用

在这些情况下每个候选，若要查看是否其中任何一个无法可能是应用在运行时执行有限的编译时检查。此检查包括以下步骤：

- 分部类型推断：任何类型不依赖于直接或间接的类型参数的实参`dynamic`使用的规则推断[类型推理](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#type-inference)。 其余的类型参数是未知的。
- 部分适用性检查：根据检查适用性[适用函数成员](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#applicable-function-member)，但忽略其类型是未知的参数。
- 如果没有候选人通过此测试，则发生编译时错误。

### 函数成员调用

本部分介绍在运行时调用特定函数成员的过程。 假定绑定时进程具有已确定要调用的可能采用重载解析到一组候选函数成员的特定成员。

用于描述在调用进程的目的，函数成员分为两类：

- 静态函数成员。 这些是实例构造函数、 静态方法、 静态属性访问器和用户定义的运算符。 静态函数成员始终是非虚拟的。
- 实例函数成员。 这些是实例方法、 实例属性访问器和索引器访问器。 实例函数成员为非虚拟或虚拟的并且始终调用的特定实例上。 实例计算的实例表达式，且可访问作为函数成员内`this`([此访问权限](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#this-access))。

函数成员调用的运行时处理包括以下步骤，其中`M`是函数成员，并且在`M`是实例成员，`E`的实例表达式：

- 如果`M`是静态函数成员：
  - 参数列表中所述的顺序进行计算[自变量列表](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#argument-lists)。
  - `M` 调用。
- 如果`M`中声明的实例函数成员*value_type*:
  - `E` 计算。 如果此计算导致了异常，然后不执行任何进一步的操作。
  - 如果`E`未归类为变量，然后的临时本地变量`E`的创建类型和值`E`分配给该变量。 `E` 然后重新归类为对该临时本地变量的引用。 临时变量是可访问性`this`内`M`，但不是在另一种方法。 因此，仅当`E`是 true 变量是调用方以观察所做的更改的`M`对`this`。
  - 参数列表中所述的顺序进行计算[自变量列表](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#argument-lists)。
  - `M` 调用。 通过所引用的变量`E`成为引用变量`this`。
- 如果`M`中声明的实例函数成员*reference_type*:
  - `E` 计算。 如果此计算导致了异常，然后不执行任何进一步的操作。
  - 参数列表中所述的顺序进行计算[自变量列表](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#argument-lists)。
  - 如果类型`E`是*value_type*，装箱转换 ([装箱转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/types#boxing-conversions)) 执行来将转换`E`键入`object`，和`E`被视为为类型`object`中的以下步骤。 在这种情况下，`M`只能属于`System.Object`。
  - 值`E`进行检查，以保持有效。 如果的值`E`是`null`、`System.NullReferenceException`引发并执行任何进一步的操作。
  - 确定要调用的函数成员实现：
    - 如果绑定时类型`E`是一个接口，要调用的函数成员是实现`M`提供的引用的实例的运行时类型`E`。通过应用的接口映射规则来确定此函数成员 ([接口映射](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/interfaces#interface-mapping)) 来确定的实现`M`提供的引用的实例的运行时类型`E`。
    - 否则为如果`M`是虚函数成员，要调用的函数成员是实现`M`提供的引用的实例的运行时类型`E`。 通过应用用于确定派生程度最高的实现的规则来确定此函数成员 ([虚拟方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#virtual-methods)) 的`M`相对于引用的实例的运行时类型`E`。
    - 否则为`M`所在的非虚拟函数，并要调用的函数成员是`M`本身。
  - 调用在上述步骤中确定的函数成员实现。 所引用的对象`E`所引用的对象将成为`this`。

#### 装箱的实例上调用

在中实现的函数成员*value_type*可以通过的已装箱的实例调用*value_type*在以下情况下：

- 函数成员何时`override`继承自类型的方法`object`和类型的实例表达式通过调用`object`。
- 当函数成员是一种实现的接口函数成员和的实例表达式通过调用*interface_type*。
- 当通过委托调用的函数成员。

在这些情况下，则认为该装箱的实例包含的变量*value_type*，并且此变量成为引用的变量`this`内函数成员调用。具体而言，这意味着，当装箱实例上调用的函数成员，很可能要修改的已装箱的实例中包含的值的函数成员。

## 主表达式

主表达式包含表达式的最简单形式。

antlr复制

```antlr
primary_expression
    : primary_no_array_creation_expression
    | array_creation_expression
    ;

primary_no_array_creation_expression
    : literal
    | interpolated_string_expression
    | simple_name
    | parenthesized_expression
    | member_access
    | invocation_expression
    | element_access
    | this_access
    | base_access
    | post_increment_expression
    | post_decrement_expression
    | object_creation_expression
    | delegate_creation_expression
    | anonymous_object_creation_expression
    | typeof_expression
    | checked_expression
    | unchecked_expression
    | default_value_expression
    | nameof_expression
    | anonymous_method_expression
    | primary_no_array_creation_expression_unsafe
    ;
```

主表达式分为*array_creation_expression*s 和*primary_no_array_creation_expression*s。 以这种方式处理数组创建表达式，而不是列出的其他简单表达式窗体，以及使语法如禁止可能令人混淆的代码

C#复制

```csharp
object o = new int[3][1];
```

它将否则解释为

C#复制

```csharp
object o = (new int[3])[1];
```

### 文本

一个*primary_expression*组成*文字*([文本](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#literals)) 分类为一个值。

### 内插字符串

*Interpolated_string_expression*组成`$`号后跟正则或原义字符串文本、 漏洞，其中由分隔`{`和`}`、 括起来的表达式和格式设置规范。 内插的字符串表达式是对*interpolated_string_literal* ，已被拆分成各个单独的标记中所述[内插字符串文本](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#interpolated-string-literals)。

antlr复制

```antlr
interpolated_string_expression
    : '$' interpolated_regular_string
    | '$' interpolated_verbatim_string
    ;

interpolated_regular_string
    : interpolated_regular_string_whole
    | interpolated_regular_string_start interpolated_regular_string_body interpolated_regular_string_end
    ;

interpolated_regular_string_body
    : interpolation (interpolated_regular_string_mid interpolation)*
    ;

interpolation
    : expression
    | expression ',' constant_expression
    ;

interpolated_verbatim_string
    : interpolated_verbatim_string_whole
    | interpolated_verbatim_string_start interpolated_verbatim_string_body interpolated_verbatim_string_end
    ;

interpolated_verbatim_string_body
    : interpolation (interpolated_verbatim_string_mid interpolation)+
    ;
```

*Constant_expression*内插中必须具有隐式转换为`int`。

*Interpolated_string_expression*分类为一个值。 如果立即将其转换为`System.IFormattable`或`System.FormattableString`隐式的内插的字符串转换 ([隐式内插字符串转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#implicit-interpolated-string-conversions)) 内, 插的字符串表达式也为该类型。否则，它具有类型`string`。

如果内插字符串的类型为`System.IFormattable`或`System.FormattableString`，含义是对的调用`System.Runtime.CompilerServices.FormattableStringFactory.Create`。 如果类型为`string`，该表达式的含义是对的调用`string.Format`。 在这两种情况下，调用的参数列表包含格式字符串文本，与每个内插的占位符和对应的占位符的每个表达式的参数。

格式字符串文本构造，如下所示，其中`N`是数中的内插*interpolated_string_expression*:

- 如果*interpolated_regular_string_whole*或*interpolated_verbatim_string_whole*遵循`$`登录，则格式字符串文本是该令牌。
- 否则，文本的格式字符串组成：
  - 第一个*interpolated_regular_string_start*或*interpolated_verbatim_string_start*
  - 然后对于每个数字`I`从`0`到`N-1`:
    - 十进制表示形式 `I`
    - 然后，如果相应*内插*已*constant_expression*即`,`（逗号） 的值的十进制表示形式后, 跟*constant_expression*
    - 然后*interpolated_regular_string_mid*， *interpolated_regular_string_end*，*interpolated_verbatim_string_mid*或*interpolated_verbatim_string_end*紧随相应的内插。

后续参数将只需*表达式*从*内插*（如果有），按顺序。

TODO： 示例。

### 简单名称

一个*simple_name*包含的标识符，可以选择后跟类型参数列表：

antlr复制

```antlr
simple_name
    : identifier type_argument_list?
    ;
```

一个*simple_name*是窗体`I`或窗体`I<A1,...,Ak>`，其中`I`是单个标识符和`<A1,...,Ak>`是一个可选*type_argument_list*。 如果未*type_argument_list*是指定，请考虑`K`为零。 *Simple_name*计算和分类，如下所示：

- 如果`K`为零， *simple_name*中将显示*块*如果*块*的 (或封闭*块*的) 本地变量声明空间 ([声明](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/basic-concepts#declarations)) 包含本地变量、 参数或具有名称的常量 `I`，然后*simple_name*引用该本地变量参数或常量和分类为变量或值。

- 如果`K`为零， *simple_name*出现在泛型方法声明的主体中，如果该声明包含名称的类型参数 `I`，则*simple_name*指的是该类型参数。

- 否则，为每个实例类型 `T`([的实例类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#the-instance-type))，从最近的封闭类型声明的实例类型开始，继续执行的每个封闭类或结构的实例类型声明 （如果有）：

  - 如果`K`是零的声明`T`包括具有名称的类型参数 `I`，然后*simple_name*引用该类型参数。
  - 否则为如果成员查找 ([成员查找](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#member-lookup)) 的`I`中`T`与`K` 类型自变量生成匹配项：
    - 如果`T`是否立即封闭类或结构类型的实例类型和查找识别一个或多个方法，结果是方法组，其中的关联的实例表达式`this`。 如果指定了类型自变量列表，它将在调用泛型方法中使用 ([方法调用](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#method-invocations))。
    - 否则为如果`T`如果查找标识一个实例成员，并且引用出现在实例构造函数、 实例方法或实例访问器的主体是最近的封闭类或结构类型的实例类型结果是相同的成员访问 ([成员访问](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#member-access)) 的窗体`this.I`。 才会发生此时`K`为零。
    - 否则，结果是相同的成员访问 ([成员访问](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#member-access)) 的窗体`T.I`或`T.I<A1,...,Ak>`。 在这种情况下，它是的绑定时错误*simple_name*来指代的实例成员。

- 否则为每个命名空间 `N`，在其中命名空间从开始*simple_name*发生，继续到每个封闭命名空间 （如果有），结束与全局命名空间，执行以下步骤只有一个实体就是位于才进行计算：

  - 如果`K`为零并`I`中的命名空间名称 `N`，然后：
    - 如果位置其中*simple_name*发生的命名空间声明括`N`和命名空间声明中包含*extern_alias_directive*或*using_alias_directive* ，将名称相关联 `I`与命名空间或类型，则*simple_name*不明确，并且发生编译时错误。
    - 否则为*simple_name*指的是名为的命名空间`I`中`N`。
  - 否则为如果`N`包含可访问类型具有名称 `I`并`K` 类型形参，则：
    - 如果`K`是零和位置， *simple_name*发生括起来的命名空间声明`N`和命名空间声明中包含*extern_alias_directive*或*using_alias_directive*将关联名称 `I`与命名空间或类型，则*simple_name*不明确，则发生编译时错误。
    - 否则为*namespace_or_type_name*指构造具有给定的类型参数的类型。
  - 否则为如果位置其中*simple_name*发生括起来的命名空间声明 `N`:
    - 如果`K`为零，并且命名空间声明中包含*extern_alias_directive*或*using_alias_directive*将关联名称 `I`与导入的命名空间或类型，则*simple_name*指的是该命名空间或类型。
    - 否则为如果通过导入的命名空间和类型声明*using_namespace_directive*s 和*using_static_directive*的命名空间声明包含一个可访问类型或具有名称的非扩展静态成员 `I`并`K` 类型参数，则*simple_name*指的是该类型或成员构造具有给定的类型参数。
    - 否则为如果通过导入的命名空间和类型*using_namespace_directive*的命名空间声明包含多个可访问类型或非扩展方法具有名称的静态成员 `I`和`K` 类型参数，则*simple_name*不明确并产生一个错误。

  请注意，此整个步骤中的处理相应的步骤完全并行*namespace_or_type_name* ([Namespace 和类型名称](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/basic-concepts#namespace-and-type-names))。

- 否则为*simple_name*是未定义，且将发生编译时错误。

### 带括号的表达式

一个*parenthesized_expression*组成*表达式*括在括号中。

antlr复制

```antlr
parenthesized_expression
    : '(' expression ')'
    ;
```

一个*parenthesized_expression*通过评估来评估计算*表达式*在括号中。 如果*表达式*在括号中表示的命名空间或类型，则发生编译时错误。 否则为结果*parenthesized_expression*是所包含的计算结果*表达式*。

### 成员访问

一个*member_access*组成*primary_expression*即*predefined_type*，或者*qualified_alias_member*后, 跟"`.`"令牌后, 跟*标识符*，后面可跟*type_argument_list*。

antlr复制

```antlr
member_access
    : primary_expression '.' identifier type_argument_list?
    | predefined_type '.' identifier type_argument_list?
    | qualified_alias_member '.' identifier
    ;

predefined_type
    : 'bool'   | 'byte'  | 'char'  | 'decimal' | 'double' | 'float' | 'int' | 'long'
    | 'object' | 'sbyte' | 'short' | 'string'  | 'uint'   | 'ulong' | 'ushort'
    ;
```

*Qualified_alias_member*中定义生产[Namespace 别名限定符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/namespaces#namespace-alias-qualifiers)。

一个*member_access*是窗体`E.I`或窗体`E.I<A1, ..., Ak>`，其中`E`是主表达式`I`是单个标识符和`<A1, ..., Ak>`是可选的*type_argument_list*。 如果未*type_argument_list*是指定，请考虑`K`为零。

一个*member_access*与*primary_expression*类型的`dynamic`动态绑定 ([动态绑定](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#dynamic-binding))。 在这种情况下，编译器将成员访问分类为属性访问类型的`dynamic`。 规则可确定的含义*member_access*然后，在运行时，使用运行时类型而非编译时类型的应用*primary_expression*。 如果此运行时分类的潜在顾客到方法组，则必须是成员访问*primary_expression*的*invocation_expression*。

*Member_access*计算和分类，如下所示：

- 如果`K`为零并`E`是一个命名空间和`E`包含嵌套的命名空间与名称 `I`，则结果为该命名空间。
- 否则为如果`E`是一个命名空间和`E`包含可访问类型具有名称 `I`并`K` 类型参数，则结果为构造具有给定的类型参数的该类型。
- 如果`E`是*predefined_type*或*primary_expression*归类为一种类型，如果`E`不是类型参数，并且如果成员查找 ([成员查找](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#member-lookup))`I`中`E`与`K` 类型参数生成匹配项，然后`E.I`计算和分类，如下所示：
  - 如果`I`标识的类型，则结果为构造具有给定的类型参数的该类型。
  - 如果`I`标识一个或多个方法，则结果为方法组没有关联的实例表达式。 如果指定了类型自变量列表，它将在调用泛型方法中使用 ([方法调用](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#method-invocations))。
  - 如果`I`标识`static`属性，则结果是不包含关联的实例表达式的属性访问。
  - 如果`I`标识`static`字段：
    - 如果此字段为`readonly`和引用发生之外的静态构造函数的类或结构在其中声明该字段，则结果为一个值，即静态字段的值 `I`中 `E`。
    - 否则，结果是一个变量，即静态字段 `I`在 `E`。
  - 如果`I`标识`static`事件：
    - 如果引用出现在类或结构在其中声明了事件，并声明了事件，而无需*event_accessor_declarations* ([事件](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#events))，然后`E.I`完全处理像`I`已静态字段。
    - 否则，结果为无关联的实例表达式的事件访问。
  - 如果`I`标识一个常量，则结果为一个值，即该常量的值。
  - 如果`I`标识枚举成员，则结果为一个值，即该枚举成员的值。
  - 否则为`E.I`是无效的成员引用，并且将发生编译时错误。
- 如果`E`是属性访问、 索引器访问、 变量或值的类型是 `T`，和成员查找 ([成员查找](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#member-lookup)) 的`I`中`T`与`K`  类型参数生成匹配项，然后`E.I`计算和分类，如下所示：
  - 首先，如果`E`是一个属性或索引器访问，则属性的值或获取索引器访问 ([表达式的值](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#values-of-expressions)) 和`E`重新分类为一个值。
  - 如果`I`标识一个或多个方法，则结果为方法组的关联的实例表达式与`E`。 如果指定了类型自变量列表，它将在调用泛型方法中使用 ([方法调用](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#method-invocations))。
  - 如果`I`标识实例属性
    - 如果`E`是`this`，`I`标识的自动实现的属性 ([自动实现的属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#automatically-implemented-properties)) 没有 setter，并且引用出现在实例构造函数类或结构类型`T`，则结果为变量，即为给定的自动属性隐藏的支持字段`I`的实例中`T`由给定`this`。
    - 否则，结果是提供的关联的实例表达式的属性访问 `E`。
  - 如果`T`是*class_type*并`I`标识的实例字段*class_type*:
    - 如果的值`E`是`null`，然后`System.NullReferenceException`引发。
    - 否则为如果该字段是`readonly`和发生的外部声明该字段的类的实例构造函数的引用，则结果为一个值，即字段的值 `I`中所引用的对象 `E`。
    - 否则，结果是一个变量，即字段 `I`中所引用的对象 `E`。
  - 如果`T`是*struct_type*并`I`标识的实例字段*struct_type*:
    - 如果`E`是一个值，或如果字段是`readonly`和引用出现在其中声明该字段，该结构的实例构造函数外，则结果为一个值，即字段的值 `I`中给定的结构实例 `E`.
    - 否则，结果是一个变量，即字段 `I`中给定的结构实例 `E`。
  - 如果`I`标识实例事件：
    - 如果引用出现在类或结构在其中声明了事件，并声明了事件，而无需*event_accessor_declarations* ([事件](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#events))，并为不发生引用左上方`+=`或`-=`运算符，然后`E.I`完全处理像`I`是实例字段。
    - 否则，会得到的关联的实例表达式的事件访问 `E`。
- 否则，尝试处理`E.I`扩展方法调用的形式 ([扩展方法调用](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#extension-method-invocations))。 如果此操作失败，`E.I`是无效的成员引用，并且绑定时出错。

#### 相同的简单名称和类型名称

在窗体的成员访问`E.I`，如果`E`是一个单一的标识符，并且如果的含义`E`作为*simple_name* ([简单名称](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#simple-names)) 是常量、 字段、 属性，本地变量或参数类型相同的含义`E`作为*type_name* ([Namespace 和类型名称](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/basic-concepts#namespace-and-type-names))，则这两个可能的含义的`E`是允许使用。 两个可能的含义`E.I`永远不会不明确，因为`I`一定必须是类型的成员`E`这两种情况。 换而言之，此规则只是允许访问静态成员和嵌套的类型`E`本来已发生编译时错误。 例如：

C#复制

```csharp
struct Color
{
    public static readonly Color White = new Color(...);
    public static readonly Color Black = new Color(...);

    public Color Complement() {...}
}

class A
{
    public Color Color;                // Field Color of type Color

    void F() {
        Color = Color.Black;           // References Color.Black static member
        Color = Color.Complement();    // Invokes Complement() on Color field
    }

    static void G() {
        Color c = Color.White;         // References Color.White static member
    }
}
```

#### 语法二义性

对于生产*simple_name* ([简单名称](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#simple-names)) 和*member_access* ([成员访问](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#member-access)) 可能导致引发方面的多义性问题表达式的语法。例如，语句：

复制

```
F(G<A,B>(7));
```

可解释为调用`F`具有两个参数`G < A`和`B > (7)`。 或者，也可以解释为调用`F`带有一个自变量，这是对泛型方法的调用 `G`使用两个类型参数和一个正则自变量。

如果可以为分析 （在上下文中） 的标记序列*simple_name* ([简单名称](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#simple-names))， *member_access* ([成员访问](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#member-access))，或*pointer_member_access* ([指针成员访问](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/unsafe-code#pointer-member-access)) 结尾*type_argument_list* ([类型实参](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/types#type-arguments))，则令牌紧跟`>`检查令牌。 如果它是一个

C#复制

```csharp
(  )  ]  }  :  ;  ,  .  ?  ==  !=  |  ^
```

然后*type_argument_list*保留为一部分*simple_name*， *member_access*或者*pointer_member_access*和任何令牌的序列的其他可能分析将被放弃。 否则为*type_argument_list*不属于被视为*simple_name*， *member_access*或*pointer_member_access*，即使不没有令牌的序列的任何其他可能分析。 请注意，这些规则不应用分析时*type_argument_list*中*namespace_or_type_name* ([Namespace 和类型名称](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/basic-concepts#namespace-and-type-names))。 语句

C#复制

```csharp
F(G<A,B>(7));
```

将此规则，根据被解释为调用`F`带有一个自变量，这是对泛型方法的调用`G`使用两个类型参数和一个正则自变量。 语句

C#复制

```csharp
F(G < A, B > 7);
F(G < A, B >> 7);
```

将每个被解释为调用`F`具有两个参数。 语句

C#复制

```csharp
x = F < A > +y;
```

将被解释为小于运算符，大于运算符和一元加运算符，该语句必须编写`x = (F < A) > (+y)`，而不是作为*simple_name*与*type_argument_list*后跟二进制加运算符。 在语句中

C#复制

```csharp
x = y is C<T> + z;
```

令牌`C<T>`解释为*namespace_or_type_name*与*type_argument_list*。

### 调用表达式

*Invocation_expression*用于调用的方法。

antlr复制

```antlr
invocation_expression
    : primary_expression '(' argument_list? ')'
    ;
```

*Invocation_expression*动态绑定 ([动态绑定](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#dynamic-binding)) 如果在至少一个以下保留：

- *Primary_expression*具有编译时类型`dynamic`。
- 至少一个参数的可选*argument_list*具有编译时类型`dynamic`并且*primary_expression*没有委托类型。

在这种情况下，编译器将分类*invocation_expression*类型的值作为`dynamic`。 规则可确定的含义*invocation_expression*然后应用在运行时，使用运行时类型，而不其中的编译时类型*primary_expression*和其具有编译时类型的参数`dynamic`。 如果*primary_expression*没有编译时类型`dynamic`，然后方法调用中所述进行有限的编译时检查[编译时检查的动态重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#compile-time-checking-of-dynamic-overload-resolution).

*Primary_expression*的*invocation_expression*方法组或的值必须是*delegate_type*。 如果*primary_expression*是方法组*invocation_expression*是方法调用 ([方法调用](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#method-invocations))。 如果*primary_expression*的值为*delegate_type*，则*invocation_expression*是委托调用 ([委托调用](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#delegate-invocations)). 如果*primary_expression*是方法组和值都不*delegate_type*，绑定时出错。

可选*argument_list* ([自变量列表](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#argument-lists)) 提供的方法参数的值或变量引用。

计算结果*invocation_expression*分类，如下所示：

- 如果*invocation_expression*调用方法或委托，可返回`void`，结果是执行任何操作。 一个表达式，被归类为可执行任何操作的上下文中仅允许*statement_expression* ([表达式语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/statements#expression-statements)) 或作为正文*lambda_expression*([匿名函数表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#anonymous-function-expressions))。 否则绑定时出错。
- 否则，结果为返回的方法或委托的类型的值。

#### 方法调用

有关方法调用中， *primary_expression*的*invocation_expression*必须为方法组。 方法组标识要调用的一个方法或从中进行选择要调用的特定方法的重载方法的集。 在后一种情况下，确定特定的方法来调用基于上下文中的参数的类型提供*argument_list*。

在窗体的方法调用的处理的绑定时间`M(A)`，其中`M`是方法组 (可能包括*type_argument_list*)，并`A`是一个可选*argument_列表*，包括以下步骤：

- 构造的方法调用的候选方法集。

   

  为每个方法`F`与方法组相关联`M`:

  - 如果`F`是非泛型`F`是候选版本时：
    - `M` 没有类型参数列表，并
    - `F` 与适用`A`([适用函数成员](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#applicable-function-member))。
  - 如果`F`是泛型方法和`M`没有类型参数列表，`F`是候选版本时：
    - 类型推理 ([类型推理](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#type-inference)) 成功，推断出的调用，类型参数列表和
    - F 中的参数列表的所有构造的类型后的推断的类型参数将替换为相应的方法类型参数，满足其约束 ([满足约束](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/types#satisfying-constraints))，以及的参数列表`F`与适用`A`([适用函数成员](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#applicable-function-member))。
  - 如果`F`是泛型方法和`M`包含类型参数列表，`F`是候选版本时：
    - `F` 具有相同数量的方法类型参数在类型参数列表中，提供和
    - F 中的参数列表的所有构造的类型后的类型参数将替换为相应的方法类型参数，满足其约束 ([满足约束](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/types#satisfying-constraints))，和参数列表的`F`与适用`A`([适用函数成员](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#applicable-function-member))。

- 候选方法集减少到仅包含从派生程度最高的类型：为每个方法`C.F`在组中，其中`C`是在其中的类型方法`F`的所有方法的基类型中都声明的都声明`C`从集中删除。 此外，如果`C`而不是类类型`object`，从集中删除接口类型中声明的所有方法。 （此后一种规则只能具有影响时该方法组是具有非对象的有效基类和非空有效接口集的类型形参上的成员查找结果。）

- 如果生成的候选方法集为空，然后进一步处理沿以下步骤将弃用，并改为尝试处理该调用扩展方法调用的形式 ([扩展方法调用](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#extension-method-invocations)). 如果此操作失败，则不适用的方法存在，并将绑定时出现错误。

- 候选方法集的最佳方法使用的重载决策规则标识[重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#overload-resolution)。 如果不能确定一个最佳方法，该方法调用是不明确的并绑定时出错。 执行重载决策时，泛型方法的参数替换之后考虑 （提供或推断） 的类型参数的相应的方法类型参数。

- 执行最终验证，所选的最佳方法：

  - 在方法组的上下文中验证方法：如果最佳方法是静态方法，方法组必须已由产生*simple_name*或*member_access*通过一种类型。 如果最佳方法是实例方法，方法组必须已由产生*simple_name*即*member_access*通过变量或值，或*base_access*。 如果这些要求都不为 true，将绑定时出现错误。
  - 如果最佳方法是泛型方法，根据的约束检查类型实参 （提供或推断出） ([满足约束](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/types#satisfying-constraints)) 声明的泛型方法。 如果任何类型实参不满足类型参数上的对应约束，绑定时出错。

一旦选择一种方法并将其绑定时在验证通过上述步骤，根据函数成员调用中所述的规则处理实际的运行时调用[编译时检查的动态重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#compile-time-checking-of-dynamic-overload-resolution).

上面所述的解析规则的直观效果是，如下所示：若要查找调用的方法调用的特定方法，启动方法调用所指示的类型，并一直向上继承链，直到找到至少一个适用的、 可访问的、 非重写方法声明。 然后执行类型推断和重载决策的一套适用的、 可访问的、 非重写该类型中声明的方法并调用由此选定的方法。 如果不找到任何方法，改为尝试处理该调用为扩展方法调用。

#### 扩展方法调用

在方法调用中 ([装箱实例上的调用](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#invocations-on-boxed-instances)) 之一的窗体

C#复制

```csharp
expr . identifier ( )

expr . identifier ( args )

expr . identifier < typeargs > ( )

expr . identifier < typeargs > ( args )
```

如果正常处理的调用不发现任何适用的方法，尝试处理构造作为扩展方法调用。 如果*expr*或任一*args*编译时类型`dynamic`，扩展方法将不适用。

目的是找到最*type_name* `C`，以便可以进行相应的静态方法调用：

C#复制

```csharp
C . identifier ( expr )

C . identifier ( expr , args )

C . identifier < typeargs > ( expr )

C . identifier < typeargs > ( expr , args )
```

扩展方法`Ci.Mj`是***符合条件***如果：

- `Ci` 是一个非泛型的非嵌套类
- 名称`Mj`是*标识符*
- `Mj` 可访问，并且适用时应用的自变量作为静态方法，如上所示
- 存在从的隐式标识、 引用或装箱转换*expr*的第一个参数的类型为`Mj`。

搜索`C`继续，如下所示：

- 从开始继续执行每个封闭命名空间声明和使用包含的编译单元中，结束的最接近封闭命名空间声明连续尝试进行查找候选组扩展方法：
  - 如果给定的命名空间或编译单元直接包含非泛型类型声明`Ci`符合条件的扩展方法与`Mj`，则这些扩展方法的集为候选项集。
  - 如果类型`Ci`导入*using_static_declarations*并且直接由导入的命名空间中声明*using_namespace_directive*给定命名空间或编译单元中直接 s包含符合条件的扩展方法`Mj`，则这些扩展方法的集为候选项集。
- 如果任何封闭命名空间声明或编译单元中不找到任何候选集，则发生编译时错误。
- 否则，将重载解析应用于设置中所述的候选项 ([重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#overload-resolution))。 如果未找到任何单个的最佳方法，将发生编译时错误。
- `C` 是在其中最好的方法声明为扩展方法的类型。

使用`C`为目标，方法调用然后处理作为静态方法调用 ([进行编译时检查的动态重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#compile-time-checking-of-dynamic-overload-resolution))。

上述规则意味着，实例方法优先扩展方法、 内部命名空间声明中可用的扩展方法，优先于在外部命名空间声明和该扩展中可用的扩展方法直接在命名空间中声明的方法优先于扩展方法导入到该命名空间与 using 命名空间指令。 例如：

C#复制

```csharp
public static class E
{
    public static void F(this object obj, int i) { }

    public static void F(this object obj, string s) { }
}

class A { }

class B
{
    public void F(int i) { }
}

class C
{
    public void F(object obj) { }
}

class X
{
    static void Test(A a, B b, C c) {
        a.F(1);              // E.F(object, int)
        a.F("hello");        // E.F(object, string)

        b.F(1);              // B.F(int)
        b.F("hello");        // E.F(object, string)

        c.F(1);              // C.F(object)
        c.F("hello");        // C.F(object)
    }
}
```

在示例中，`B`的方法将优先于第一个扩展方法和`C`的方法将优先于这两种扩展方法。

C#复制

```csharp
public static class C
{
    public static void F(this int i) { Console.WriteLine("C.F({0})", i); }
    public static void G(this int i) { Console.WriteLine("C.G({0})", i); }
    public static void H(this int i) { Console.WriteLine("C.H({0})", i); }
}

namespace N1
{
    public static class D
    {
        public static void F(this int i) { Console.WriteLine("D.F({0})", i); }
        public static void G(this int i) { Console.WriteLine("D.G({0})", i); }
    }
}

namespace N2
{
    using N1;

    public static class E
    {
        public static void F(this int i) { Console.WriteLine("E.F({0})", i); }
    }

    class Test
    {
        static void Main(string[] args)
        {
            1.F();
            2.G();
            3.H();
        }
    }
}
```

此示例的输出是：

复制

```
E.F(1)
D.G(2)
C.H(3)
```

`D.G` 将优先于`C.G`，并`E.F`优先于同时`D.F`和`C.F`。

#### 委托调用

对于委托调用， *primary_expression*的*invocation_expression*必须是值为*delegate_type*。 此外，考虑*delegate_type*是一个具有相同的参数列表的函数成员*delegate_type*，则*delegate_type*必须为适用 （[适用函数成员](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#applicable-function-member)) 与*argument_list*的*invocation_expression*。

委托调用窗体的运行时处理`D(A)`，其中`D`是*primary_expression*的*delegate_type*和`A`是可选*argument_list*，包括以下步骤：

- `D` 计算。 如果此计算导致了异常，不执行任何进一步的操作。
- 值`D`进行检查，以保持有效。 如果的值`D`是`null`、`System.NullReferenceException`引发并执行任何进一步的操作。
- 否则为`D`是对委托实例的引用。 函数成员调用 ([进行编译时检查的动态重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#compile-time-checking-of-dynamic-overload-resolution)) 在每个委托的调用列表中的可调用实体上执行。 对于可调用实体组成的实例和实例方法，调用的实例是可调用实体中包含的实例。

### 元素访问

*Element_access*组成*primary_no_array_creation_expression*后, 跟"`[`"令牌后, 跟*argument_list*后, 跟"`]`"令牌。*Argument_list*包含一个或多个*自变量*s，由逗号分隔。

antlr复制

```antlr
element_access
    : primary_no_array_creation_expression '[' expression_list ']'
    ;
```

*Argument_list*的*element_access*不允许包含`ref`或`out`参数。

*Element_access*动态绑定 ([动态绑定](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#dynamic-binding)) 如果在至少一个以下保留：

- *Primary_no_array_creation_expression*具有编译时类型`dynamic`。
- 至少一个表达式的*argument_list*具有编译时类型`dynamic`并且*primary_no_array_creation_expression*不具有数组类型。

在这种情况下，编译器将分类*element_access*类型的值作为`dynamic`。 规则可确定的含义*element_access*然后应用在运行时，使用运行时类型，而不其中的编译时类型*primary_no_array_creation_expression*并*argument_list*其具有编译时类型的表达式`dynamic`。 如果*primary_no_array_creation_expression*没有编译时类型`dynamic`，然后元素访问进行限制的编译时检查，如中所述[编译时检查的动态重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#compile-time-checking-of-dynamic-overload-resolution)。

如果*primary_no_array_creation_expression*的*element_access*的值为*array_type*，则*element_access*是数组访问 ([数组访问](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#array-access))。 否则为*primary_no_array_creation_expression*必须是变量或值类、 结构或接口类型，在这种情况下具有一个或多个索引器成员*element_access*是索引器访问 ([索引器访问](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#indexer-access))。

#### 数组访问

对于数组访问*primary_no_array_creation_expression*的*element_access*必须是值为*array_type*。 此外， *argument_list*数组的访问不允许包含命名的参数。表达式的数目*argument_list*必须是相同的秩*array_type*，并且每个表达式必须是类型`int`， `uint`， `long`， `ulong`，或者必须是隐式转换为一个或多个这些类型。

评估数组访问的结果为数组，即所选的中的表达式的值的数组元素的元素类型的变量*argument_list*。

数组访问窗体的运行时处理`P[A]`，其中`P`是*primary_no_array_creation_expression*的*array_type*和`A`是*argument_list*，包括以下步骤：

- `P` 计算。 如果此计算导致了异常，不执行任何进一步的操作。
- 索引表达式*argument_list*按从左到右的顺序计算。 以下每个索引表达式，隐式转换的计算结果 ([隐式转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#implicit-conversions)) 执行以下类型之一： `int`， `uint`， `long`， `ulong`。 选择在此列表中存在的隐式转换的第一种类型。例如，如果索引表达式的类型`short`然后隐式转换到`int`执行，因为从隐式转换`short`到`int`以及从`short`到`long`可使用。 索引表达式或后续的隐式转换的计算会导致异常，如果没有更多的索引表达式的计算，并不能进一步执行步骤。
- 值`P`进行检查，以保持有效。 如果的值`P`是`null`、`System.NullReferenceException`引发并执行任何进一步的操作。
- 在每个表达式的值*argument_list*根据每个维度的引用的数组实例的实际边界检查`P`。 如果一个或多个值超出范围，`System.IndexOutOfRangeException`引发并执行任何进一步的操作。
- 计算由索引表达式给定的数组元素的位置，并且此位置将成为数组访问的结果。

#### 索引器访问

对于索引器访问， *primary_no_array_creation_expression*的*element_access*必须是变量或值类、 结构或接口类型，并且此类型必须实现一个或多个索引器与适用*argument_list*的*element_access*。

处理窗体的索引器访问的绑定时间`P[A]`，其中`P`是*primary_no_array_creation_expression*的类、 结构或接口类型`T`，并`A`是*argument_list*，包括以下步骤：

- 索引器提供的一套`T`构造。 集包括的所有索引器中声明`T`或基类型的`T`不是`override`声明，并可在当前上下文中访问 ([成员访问](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/basic-concepts#member-access))。

- 集减少到由其他索引器适用的并且不会隐藏这些索引器。

   

  以下规则应用于每个索引器`S.I`在组中，其中`S`是在其中的类型索引器`I`声明：

  - 如果`I`不与适用`A`([适用函数成员](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#applicable-function-member))，然后`I`从集中删除。
  - 如果`I`与适用`A`([适用函数成员](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#applicable-function-member))，所有索引器的基类型中的声明然后`S`从集中删除。
  - 如果`I`与适用`A`([适用函数成员](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#applicable-function-member)) 和`S`而不是类类型`object`，从集合中移除接口中声明的所有索引器。

- 如果生成候选索引器的集为空，则不适用的索引器存在，并将绑定时出现错误。

- 使用的重载决策规则标识的一套候选索引器的最佳索引器[重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#overload-resolution)。 如果无法识别单个最佳索引器，索引器访问是不明确，并将绑定时出现错误。

- 索引表达式*argument_list*按从左到右的顺序计算。 处理索引器访问的结果是归类为索引器访问的表达式。索引器访问表达式引用在上述步骤中确定索引器，并具有关联的实例表达式的`P`和关联的参数列表的`A`。

根据使用它的上下文，索引器访问会导致调用任一*get 访问器*或*set 访问器*的索引器。 如果索引器访问是作为赋值目标*set 访问器*调用来分配新值 ([简单赋值](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#simple-assignment))。 在所有其他情况下， *get 访问器*调用来获取当前值 ([表达式的值](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#values-of-expressions))。

### 此访问权限

一个*this_access*包含保留字`this`。

antlr复制

```antlr
this_access
    : 'this'
    ;
```

一个*this_access*仅在允许*块*的实例构造函数、 实例方法或实例访问器。 它具有以下含义之一：

- 当`this`中使用*primary_expression*内类的实例构造函数，它分类为一个值。 值的类型为类型的实例 ([的实例类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#the-instance-type)) 的类使用情况发生，并且该值是对所构造的对象的引用。

- 当`this`中使用*primary_expression*内实例方法或类的实例访问器，它分类为一个值。 值的类型为类型的实例 ([的实例类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#the-instance-type)) 的类使用情况发生，并且该值是对为其调用方法或访问器的对象的引用。

- 当`this`中使用*primary_expression*内结构的实例构造函数，它分类为变量。 变量的类型是使用实例类型 ([的实例类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#the-instance-type)) 的结构在其中使用情况发生，并且该变量表示正在构造的结构。 `this`变量的结构的实例构造函数的行为完全相同`out`结构类型的参数-具体而言，这意味着变量必须明确赋值的实例的每个执行路径中构造函数。

- 当`this`中使用*primary_expression*内实例方法或实例访问器的结构，它分类为变量。

   

  变量的类型是使用实例类型 ([的实例类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#the-instance-type)) 的出现该表达式的结构。

  - 如果方法或访问器不是一个迭代器 ([迭代器](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#iterators))，则`this`变量表示为其方法或访问器被调用，并具有完全相同的行为的结构`ref`结构类型的参数。
  - 如果方法或访问器是一个迭代器，`this`变量表示的结构为其方法或访问器被调用，并具有的行为与值类型参数的结构完全相同副本。

利用`this`中*primary_expression*上述之外的上下文中是编译时错误。 具体而言，不能是指`this`中的静态方法，静态属性访问器，或在*variable_initializer*字段声明。

### 基访问

一个*base_access*包含保留字`base`后面有"`.`"标记标识符和一个*argument_list*括在方括号中：

antlr复制

```antlr
base_access
    : 'base' '.' identifier
    | 'base' '[' expression_list ']'
    ;
```

一个*base_access*用于访问以同样在当前类或结构中命名的成员隐藏基类成员。 一个*base_access*仅在允许*块*的实例构造函数、 实例方法或实例访问器。 当`base.I`出现在类或结构，`I`必须表示该类或结构的基类的成员。 同样，当`base[E]`出现在类中，适用的索引器必须存在于类的基类。

在绑定时， *base_access*形式的表达式`base.I`和`base[E]`正如它们的编写计算`((B)this).I`并`((B)this)[E]`，其中`B`是类的基类或构造会发生的结构。 因此，`base.I`并`base[E]`对应于`this.I`并`this[E]`，除`this`被视为与基的类的实例。

当*base_access*引用确定该函数在运行时调用的成员的虚函数成员 （方法、 属性或索引器），([编译时检查的动态重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#compile-time-checking-of-dynamic-overload-resolution)) 发生更改。 通过查找派生程度最高的实现来确定调用的函数成员 ([虚拟方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#virtual-methods)) 的函数成员与`B`(而不是相对于的运行时类型`this`，作为是通常在非基本访问权限）。 因此，在`override`的`virtual`函数成员*base_access*可用于调用的函数成员的继承的实现。 如果引用的函数成员*base_access*是抽象的绑定时出错。

### 后缀递增和递减运算符

antlr复制

```antlr
post_increment_expression
    : primary_expression '++'
    ;

post_decrement_expression
    : primary_expression '--'
    ;
```

操作数的后缀递增或递减操作必须是归类为变量、 属性访问或索引器访问的表达式。 操作的结果是类型的操作数相同的值。

如果*primary_expression*具有编译时类型`dynamic`运算符动态绑定 ([动态绑定](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#dynamic-binding))，则*post_increment_expression*或*post_decrement_expression*具有编译时类型`dynamic`并在运行时使用的运行时类型应用以下规则*primary_expression*。

如果操作数的后缀递增或递减操作是一个属性或索引器访问、 属性或索引器必须同时具有`get`和一个`set`访问器。 如果这不是这种情况，绑定时出错。

一元运算符重载决策 ([一元运算符重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#unary-operator-overload-resolution)) 应用以选择特定的运算符实现。 预定义`++`并`--`运算符存在以下类型： `sbyte`， `byte`， `short`， `ushort`， `int`， `uint`， `long`， `ulong`， `char``float`， `double`， `decimal`，和任何枚举类型。 预定义`++`运算符将返回通过将 1 添加到操作数，并在预定义生成的值`--`运算符返回生成的数减去 1 的操作数的值。 在中`checked`情况下，如果此加法或减法的结果是结果类型的范围之外，结果类型是整数类型或枚举类型`System.OverflowException`引发。

运行时处理的后缀递增或递减运算的窗体`x++`或`x--`包括以下步骤：

- 如果`x`分类为变量：
  - `x` 计算为生成变量。
  - 值`x`保存。
  - 所选的运算符调用已保存的值为`x`作为其参数。
  - 运算符返回的值存储在给定的评估结果的位置`x`。
  - 保存的值的`x`使其成为操作的结果。
- 如果`x`归类为属性或索引器访问：
  - 实例表达式 (如果`x`不是`static`) 和参数列表 (如果`x`的索引器访问) 与关联`x`计算，然后在后续结果`get`和`set`取值函数调用。
  - `get`访问器的`x`调用并保存返回的值。
  - 所选的运算符调用已保存的值为`x`作为其参数。
  - `set`访问器的`x`作为运算符所返回的值调用其`value`参数。
  - 保存的值的`x`使其成为操作的结果。

`++`并`--`运算符也支持前缀表示法 ([前缀递增和递减运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#prefix-increment-and-decrement-operators))。 通常情况下的结果`x++`或`x--`的值`x`前该操作，而的结果`++x`或`--x`的值`x`操作完成后。 在任一情况下，`x`本身完成操作后具有相同的值。

`operator ++`或`operator --`实现可以使用后缀或前缀表示法来调用。 不能具有这两种表示的运算符的不同实现。

### 调用 new 运算符

`new`运算符用于创建类型的新实例。

有三种形式的`new`表达式：

- 对象创建表达式用于创建类类型和值类型的新实例。
- 数组创建表达式用于创建数组类型的新实例。
- 委托创建表达式用于创建类型的委托的新实例。

`new`运算符表示创建的类型的实例，但不一定意味着动态分配的内存。 具体而言，值类型的实例需要在其中它们驻留，并发生任何动态分配的变量以外没有其他内存时`new`用于创建值类型的实例。

#### 对象创建表达式

*Object_creation_expression*用来创建的新实例*class_type*或*value_type*。

antlr复制

```antlr
object_creation_expression
    : 'new' type '(' argument_list? ')' object_or_collection_initializer?
    | 'new' type object_or_collection_initializer
    ;

object_or_collection_initializer
    : object_initializer
    | collection_initializer
    ;
```

*类型*的*object_creation_expression*必须是*class_type*即*value_type*或*type_parameter*. *类型*不能`abstract`*class_type*。

可选*argument_list* ([自变量列表](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#argument-lists))，才允许*类型*是*class_type*或*struct_类型*。

对象创建表达式可以省略构造函数参数列表和封闭括号提供它包括对象初始值设定项或集合初始值设定项。 省略构造函数参数列表和封闭括号是等效于指定参数列表为空。

处理的对象创建表达式，其中包括对象初始值设定项或集合初始值设定项包括的第一次处理的实例构造函数，然后处理成员或元素初始化指定的对象初始值设定项 ([对象初始值设定项](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#object-initializers)) 或集合初始值设定项 ([集合初始值设定项](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#collection-initializers))。

如果任何可选参数*argument_list*具有编译时类型`dynamic`则*object_creation_expression*动态绑定 ([动态绑定](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#dynamic-binding))和在运行时使用的这些参数的运行时类型应用以下规则*argument_list*具有编译时类型`dynamic`。 但是，对象创建进行有限的编译时检查，如中所述[进行编译时检查的动态重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#compile-time-checking-of-dynamic-overload-resolution)。

绑定时处理*object_creation_expression*窗体`new T(A)`，其中`T`是*class_type*或者*value_type*和`A`是一个可选*argument_list*，包括以下步骤：

- 如果`T`是*value_type*和`A`不存在：
  - *Object_creation_expression*是默认的构造函数调用。 结果*object_creation_expression*是类型的值`T`，即的默认值为`T`中定义[System.ValueType 类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/types#the-systemvaluetype-type)。
- 否则为如果`T`是*type_parameter*和`A`不存在：
  - 如果没有值类型约束或构造函数约束 ([类型参数约束](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#type-parameter-constraints)) 为指定`T`，绑定时出错。
  - 结果*object_creation_expression*是类型参数已绑定到，运行时类型的值即调用该类型的默认构造函数的结果。 运行时类型可以是引用类型或值类型。
- 否则为如果`T`是*class_type*或*struct_type*:
  - 如果`T`是`abstract` *class_type*，则发生编译时错误。
  - 使用的重载决策规则确定要调用的实例构造函数[重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#overload-resolution)。 候选实例构造函数集包括的所有可访问的实例构造函数中声明`T`这是与适用`A`([适用函数成员](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#applicable-function-member))。 如果候选实例构造函数的集为空，或者如果无法确定一个最佳实例构造函数，绑定时出错。
  - 结果*object_creation_expression*是类型的值`T`，即通过调用在上述步骤中确定的实例构造函数生成的值。
- 否则为*object_creation_expression*是无效的并将绑定时出现错误。

即使*object_creation_expression*是否为动态绑定，编译时类型是否仍`T`。

运行时处理*object_creation_expression*窗体`new T(A)`，其中`T`是*class_type*或者*struct_type*和`A`是一个可选*argument_list*，包括以下步骤：

- 如果`T`是*class_type*:
  - 类的新实例`T`分配。 如果没有足够内存可用于分配新实例，`System.OutOfMemoryException`引发并执行任何进一步的操作。
  - 所有字段的新实例都初始化为其默认值 ([默认值](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/variables#default-values))。
  - 实例构造函数调用的函数成员调用规则根据 ([进行编译时检查的动态重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#compile-time-checking-of-dynamic-overload-resolution))。 对新分配的实例的引用会自动传递到的实例构造函数和该实例可以作为该构造函数中访问从`this`。
- 如果`T`是*struct_type*:
  - 类型的实例`T`创建通过分配一个临时本地变量。 实例构造函数的以来*struct_type*需肯定将值分配给要创建的临时变量未初始化是必需的实例的每个字段。
  - 实例构造函数调用的函数成员调用规则根据 ([进行编译时检查的动态重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#compile-time-checking-of-dynamic-overload-resolution))。 对新分配的实例的引用会自动传递到的实例构造函数和该实例可以作为该构造函数中访问从`this`。

#### 对象初始值设定项

***对象初始值设定项***指定零个或多个字段、 属性或索引的对象的元素的值。

antlr复制

```antlr
object_initializer
    : '{' member_initializer_list? '}'
    | '{' member_initializer_list ',' '}'
    ;

member_initializer_list
    : member_initializer (',' member_initializer)*
    ;

member_initializer
    : initializer_target '=' initializer_value
    ;

initializer_target
    : identifier
    | '[' argument_list ']'
    ;

initializer_value
    : expression
    | object_or_collection_initializer
    ;
```

对象初始值设定项包含成员初始值设定项，括在一系列`{`和`}`标记并用逗号分隔。 每个*member_initializer*指定初始化的目标。 *标识符*必须命名的可访问字段或属性要初始化的对象而*argument_list*括在方括号必须为指定参数的可访问的索引器上要初始化的对象。 它是错误的对象初始值设定项包含的相同字段或属性的多个成员初始值设定项。

每个*initializer_target*后跟一个等号和表达式、 对象初始值设定项或集合初始值设定项。 不能为对象初始值设定项来引用它正在初始化新创建的对象中的表达式。

指定一个表达式，为分配相同的方式处理等号后的成员初始值设定项 ([简单的赋值](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#simple-assignment)) 到目标。

等号后指定的对象初始值设定项的成员初始值设定项***嵌套的对象初始值设定项***，即，嵌入对象的初始化。 而不是将新值分配到的字段或属性，嵌套的对象初始值设定项中的分配将被视为分配给字段或属性的成员。 嵌套的对象初始值设定项不能应用到属性使用值类型，或使用值类型的只读字段。

在等号后面指定的集合初始值设定项的成员初始值设定项是嵌入集合的初始化。 而不是将一个新集合分配给目标字段、 属性或索引器，初始值设定项中给定元素添加到所引用的目标集合。 目标必须满足的需求中指定的集合类型[集合初始值设定项](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#collection-initializers)。

索引初始值设定项的参数将始终仅一次计算。 因此，即使参数最终会永远不会使用 （例如由于空嵌套初始值设定项），它们将为其副作用计算。

下面的类表示具有两个坐标的点：

C#复制

```csharp
public class Point
{
    int x, y;

    public int X { get { return x; } set { x = value; } }
    public int Y { get { return y; } set { y = value; } }
}
```

实例`Point`可以创建和初始化，如下所示：

C#复制

```csharp
Point a = new Point { X = 0, Y = 1 };
```

具有相同的效果

C#复制

```csharp
Point __a = new Point();
__a.X = 0;
__a.Y = 1; 
Point a = __a;
```

其中`__a`是临时变量，否则为不可见且不可访问。 下面的类表示从两个点创建一个矩形：

C#复制

```csharp
public class Rectangle
{
    Point p1, p2;

    public Point P1 { get { return p1; } set { p1 = value; } }
    public Point P2 { get { return p2; } set { p2 = value; } }
}
```

实例`Rectangle`可以创建和初始化，如下所示：

C#复制

```csharp
Rectangle r = new Rectangle {
    P1 = new Point { X = 0, Y = 1 },
    P2 = new Point { X = 2, Y = 3 }
};
```

具有相同的效果

C#复制

```csharp
Rectangle __r = new Rectangle();
Point __p1 = new Point();
__p1.X = 0;
__p1.Y = 1;
__r.P1 = __p1;
Point __p2 = new Point();
__p2.X = 2;
__p2.Y = 3;
__r.P2 = __p2; 
Rectangle r = __r;
```

其中`__r`，`__p1`和`__p2`是临时的变量，否则是不可见且不可访问。

如果`Rectangle`的构造函数分配两个嵌入`Point`实例

C#复制

```csharp
public class Rectangle
{
    Point p1 = new Point();
    Point p2 = new Point();

    public Point P1 { get { return p1; } }
    public Point P2 { get { return p2; } }
}
```

以下构造可用于初始化嵌入`Point`实例而不是将分配新的实例：

C#复制

```csharp
Rectangle r = new Rectangle {
    P1 = { X = 0, Y = 1 },
    P2 = { X = 2, Y = 3 }
};
```

具有相同的效果

C#复制

```csharp
Rectangle __r = new Rectangle();
__r.P1.X = 0;
__r.P1.Y = 1;
__r.P2.X = 2;
__r.P2.Y = 3;
Rectangle r = __r;
```

假设存在相应的 C，下面的示例：

C#复制

```csharp
var c = new C {
    x = true,
    y = { a = "Hello" },
    z = { 1, 2, 3 },
    ["x"] = 5,
    [0,0] = { "a", "b" },
    [1,2] = {}
};
```

等同于这一系列的分配：

C#复制

```csharp
C __c = new C();
__c.x = true;
__c.y.a = "Hello";
__c.z.Add(1); 
__c.z.Add(2);
__c.z.Add(3);
string __i1 = "x";
__c[__i1] = 5;
int __i2 = 0, __i3 = 0;
__c[__i2,__i3].Add("a");
__c[__i2,__i3].Add("b");
int __i4 = 1, __i5 = 2;
var c = __c;
```

其中`__c`等，是不可见且无法访问源代码的生成的变量。 请注意，为参数`[0,0]`有计算仅执行一次，以及有关参数`[1,2]`只计算一次，即使从不使用它们。

#### 集合初始值设定项

集合初始值设定项指定集合中的元素。

antlr复制

```antlr
collection_initializer
    : '{' element_initializer_list '}'
    | '{' element_initializer_list ',' '}'
    ;

element_initializer_list
    : element_initializer (',' element_initializer)*
    ;

element_initializer
    : non_assignment_expression
    | '{' expression_list '}'
    ;

expression_list
    : expression (',' expression)*
    ;
```

集合初始值设定项包含的元素初始值设定项，括在一系列`{`和`}`标记并用逗号分隔。 每个元素初始值设定项指定要添加到要初始化的集合对象的元素，并包含通过括起来的表达式列表`{`和`}`标记并用逗号分隔。 单表达式元素初始值设定项可以不使用大括号，编写，但不能是赋值表达式，以避免多义性与成员初始值设定项。*Non_assignment_expression*中定义生产[表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#expression)。

下面是包含集合初始值设定项的对象创建表达式的示例：

C#复制

```csharp
List<int> digits = new List<int> { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
```

集合初始值设定项应用到的集合对象必须实现的类型的`System.Collections.IEnumerable`或者发生了编译时错误。集合初始值设定项为每个指定元素的顺序，调用`Add`方法在目标上的元素初始值设定项表达式列表对象作为自变量列表中，将应用普通成员查找并重载决策的每个调用。 因此，集合对象必须有一个具有名称的适用实例或扩展方法`Add`对于每个元素初始值设定项。

下面的类表示的联系人的名称和电话号码的列表：

C#复制

```csharp
public class Contact
{
    string name;
    List<string> phoneNumbers = new List<string>();

    public string Name { get { return name; } set { name = value; } }

    public List<string> PhoneNumbers { get { return phoneNumbers; } }
}
```

一个`List<Contact>`可以创建和初始化，如下所示：

C#复制

```csharp
var contacts = new List<Contact> {
    new Contact {
        Name = "Chris Smith",
        PhoneNumbers = { "206-555-0101", "425-882-8080" }
    },
    new Contact {
        Name = "Bob Harris",
        PhoneNumbers = { "650-555-0199" }
    }
};
```

具有相同的效果

C#复制

```csharp
var __clist = new List<Contact>();
Contact __c1 = new Contact();
__c1.Name = "Chris Smith";
__c1.PhoneNumbers.Add("206-555-0101");
__c1.PhoneNumbers.Add("425-882-8080");
__clist.Add(__c1);
Contact __c2 = new Contact();
__c2.Name = "Bob Harris";
__c2.PhoneNumbers.Add("650-555-0199");
__clist.Add(__c2);
var contacts = __clist;
```

其中`__clist`，`__c1`和`__c2`是临时的变量，否则是不可见且不可访问。

#### 数组创建表达式

*Array_creation_expression*用来创建的新实例*array_type*。

antlr复制

```antlr
array_creation_expression
    : 'new' non_array_type '[' expression_list ']' rank_specifier* array_initializer?
    | 'new' array_type array_initializer
    | 'new' rank_specifier array_initializer
    ;
```

第一个窗体的数组创建表达式分配表达式列表中删除每个单个表达式结果的类型数组的实例。 例如，数组创建表达式`new int[10,20]`生成类型的数组实例`int[,]`，和数组创建表达式`new int[10][,]`生成类型的数组`int[][,]`。 在表达式列表中的每个表达式必须为类型`int`， `uint`， `long`，或`ulong`，或隐式转换为一个或多个这些类型。 每个表达式的值确定新分配的数组实例中的相应维度的长度。 数组维度的长度必须为非负的因为它是具有导致编译时错误*constant_expression*使用负值表达式列表中。

不安全的上下文中除外 ([不安全的上下文](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/unsafe-code#unsafe-contexts))，未指定数组的布局。

如果第一个窗体的数组创建表达式中包含的数组初始值设定项，在表达式列表中的每个表达式必须是常量和指定的表达式列表的秩和维度长度必须匹配数组初始值设定项。

在第二个或第三个窗体的数组创建表达式，指定的数组类型或秩说明符的秩必须匹配的数组初始值设定项。 单独的维度长度推断出的每个相应的嵌套级别的数组初始值设定项中的元素数。 因此，表达式

C#复制

```csharp
new int[,] {{0, 1}, {2, 3}, {4, 5}}
```

完全对应于

C#复制

```csharp
new int[3, 2] {{0, 1}, {2, 3}, {4, 5}}
```

第三个窗体的数组创建表达式被称为***隐式类型化数组创建表达式***。 它类似于第二个窗体，只是数组的元素类型未显式提供，但确定为最常见类型 ([查找一组表达式的最常见类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#finding-the-best-common-type-of-a-set-of-expressions)) 的数组中的表达式集初始值设定项。 对于多维数组，即，其中*rank_specifier*包含至少一个逗号，此组包含所有*表达式*中找到 s 嵌套*array_initializer*s。

数组初始值设定项中进行了描述进一步[数组初始值设定项](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/arrays#array-initializers)。

数组创建表达式的计算结果被分类为一个值，即对新分配的数组实例的引用。 数组创建表达式的运行时处理包括以下步骤：

- 维度长度表达式的*expression_list*按从左到右的顺序计算。 以下每个表达式的隐式转换的计算结果 ([隐式转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#implicit-conversions)) 执行以下类型之一： `int`， `uint`， `long`， `ulong`。 选择在此列表中存在的隐式转换的第一种类型。 如果计算的表达式或后续的隐式转换导致异常，然后计算任何其他表达式，并执行任何进一步的操作。
- 维的长度的计算所得的值进行验证，如下所示。 如果一个或多个值都小于零，`System.OverflowException`引发并执行任何进一步的操作。
- 分配具有给定的维的长度的数组实例。 如果没有足够内存可用于分配新实例，`System.OutOfMemoryException`引发并执行任何进一步的操作。
- 新数组实例的所有元素将都初始化为其默认值 ([默认值](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/variables#default-values))。
- 如果数组创建表达式中包含的数组初始值设定项，然后计算数组初始值设定项中的每个表达式的值，并将分配给其对应的数组元素。 表达式用数组初始值设定项的顺序执行的计算和分配 — 换句话说，元素将初始化按递增第一次增加最右边的维度的索引顺序。 如果给定的表达式或后续分配给相应的数组元素的计算会导致异常，然后初始化任何其他元素 （和剩余的元素将因此具有其默认值）。

数组创建表达式允许实例化数组的元素的数组类型，但必须手动初始化此类数组的元素。 例如，语句

C#复制

```csharp
int[][] a = new int[100][];
```

创建具有 100 个元素类型的一维数组`int[]`。 每个元素的初始值是`null`。 不能为相同的数组创建表达式以子数组和该语句还实例化

C#复制

```csharp
int[][] a = new int[100][5];        // Error
```

在编译时错误的结果。 必须改为手动，如下所示执行的子数组实例化

C#复制

```csharp
int[][] a = new int[100][];
for (int i = 0; i < 100; i++) a[i] = new int[5];
```

当数组的数组具有"矩形"形状时，子数组都具有相同时，是长度的使用多维数组更加高效。 在上面的示例中，实例化的数组的数组创建 101 个对象，一个外部数组和 100 的子数组。 与此相反，

C#复制

```csharp
int[,] = new int[100, 5];
```

只创建单个对象，一个二维数组，并完成单个语句中的分配。

隐式类型化的数组创建表达式的示例如下：

C#复制

```csharp
var a = new[] { 1, 10, 100, 1000 };                       // int[]

var b = new[] { 1, 1.5, 2, 2.5 };                         // double[]

var c = new[,] { { "hello", null }, { "world", "!" } };   // string[,]

var d = new[] { 1, "one", 2, "two" };                     // Error
```

最后一个表达式会导致编译时错误，因为既`int`也不`string`隐式转换为另一个，并那里是不是最常见类型。 显式类型化的数组创建表达式必须使用这种情况下，例如指定的类型为`object[]`。 或者，一个元素可以转换为通用的基类型，就会处于推断的元素类型。

可以与匿名对象初始值设定项结合使用隐式类型化的数组创建表达式 ([匿名对象创建表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#anonymous-object-creation-expressions)) 以匿名方式创建类型化数据结构。 例如：

C#复制

```csharp
var contacts = new[] {
    new {
        Name = "Chris Smith",
        PhoneNumbers = new[] { "206-555-0101", "425-882-8080" }
    },
    new {
        Name = "Bob Harris",
        PhoneNumbers = new[] { "650-555-0199" }
    }
};
```

#### 委托创建表达式

一个*delegate_creation_expression*用来创建的新实例*delegate_type*。

antlr复制

```antlr
delegate_creation_expression
    : 'new' delegate_type '(' expression ')'
    ;
```

委托创建表达式的参数必须是方法组、 匿名函数或编译时类型的值`dynamic`或*delegate_type*。 如果参数为方法组，它标识的方法和实例方法，为其创建委托的对象。 如果该参数是一个匿名函数，它直接定义的参数和委托目标的方法体。 如果参数为一个值，它标识要创建副本的一个委托实例。

如果*表达式*具有编译时类型`dynamic`，则*delegate_creation_expression*动态绑定 ([动态绑定](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#dynamic-binding))，以及下面的规则在运行时使用的运行时类型应用*表达式*。 否则，在编译时应用规则。

绑定时处理*delegate_creation_expression*窗体`new D(E)`，其中`D`是*delegate_type*并`E`是*表达式*，包括以下步骤：

- 如果`E`是一个方法组，方法组转换为相同的方式处理委托创建表达式 ([方法组转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#method-group-conversions)) 从`E`到`D`。
- 如果`E`是一个匿名函数的匿名函数转换为相同的方式处理委托创建表达式 ([匿名函数转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#anonymous-function-conversions)) 从`E`到`D`。
- 如果`E`是一个值，`E`必须是兼容的 ([委托声明](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/delegates#delegate-declarations)) 与`D`，并且结果是对新创建的委托类型的引用`D`，是指同一调用列为`E`。 如果`E`与不兼容`D`，则发生编译时错误。

运行时处理*delegate_creation_expression*窗体`new D(E)`，其中`D`是*delegate_type*并`E`是*表达式*，包括以下步骤：

- 如果`E`是一个方法组，委托创建表达式计算为方法组转换 ([方法组转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#method-group-conversions)) 从`E`到`D`。
- 如果`E`是一个匿名函数委托创建计算作为一种从匿名函数转换`E`到`D`([匿名函数转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#anonymous-function-conversions))。
- 如果`E`的值为*delegate_type*:
  - `E` 计算。 如果此计算导致了异常，不执行任何进一步的操作。
  - 如果的值`E`是`null`、`System.NullReferenceException`引发并执行任何进一步的操作。
  - 委托类型的新实例`D`分配。 如果没有足够内存可用于分配新实例，`System.OutOfMemoryException`引发并执行任何进一步的操作。
  - 使用给定的委托实例相同的调用列表初始化新的委托实例`E`。

委托实例化和委托的整个生存期内保持不变时确定委托的调用列表。 换而言之，不能创建它后更改目标可调用实体的委托。 当两个委托组合或一个删除从另一个 ([委托声明](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/delegates#delegate-declarations))，新的委托; 没有现有委托具有更改其内容。

不能创建引用属性、 索引、 用户定义的运算符、 实例构造函数、 析构函数或静态构造函数的委托。

上文所述，当创建委托时从方法组，形式参数列表和委托的返回类型确定哪些要选择的重载方法。 在示例

C#复制

```csharp
delegate double DoubleFunc(double x);

class A
{
    DoubleFunc f = new DoubleFunc(Square);

    static float Square(float x) {
        return x * x;
    }

    static double Square(double x) {
        return x * x;
    }
}
```

`A.f`字段会初始化与指的是第二个委托`Square`方法因为该方法完全匹配的形参列表和返回类型`DoubleFunc`。具有第二个`Square`方法尚未存在，会出现编译时错误。

#### 匿名对象创建表达式

*Anonymous_object_creation_expression*用于创建匿名类型的对象。

antlr复制

```antlr
anonymous_object_creation_expression
    : 'new' anonymous_object_initializer
    ;

anonymous_object_initializer
    : '{' member_declarator_list? '}'
    | '{' member_declarator_list ',' '}'
    ;

member_declarator_list
    : member_declarator (',' member_declarator)*
    ;

member_declarator
    : simple_name
    | member_access
    | base_access
    | null_conditional_member_access
    | identifier '=' expression
    ;
```

匿名对象初始值设定项声明匿名类型，并返回该类型的实例。 匿名类型是直接继承自的无名称的类类型`object`。 匿名类型的成员是一系列从用于创建类型的实例的匿名对象初始值设定项推断出的只读属性。 具体而言，匿名对象初始值设定项的窗体

C#复制

```csharp
new { p1 = e1, p2 = e2, ..., pn = en }
```

声明匿名类型的窗体

C#复制

```csharp
class __Anonymous1
{
    private readonly T1 f1;
    private readonly T2 f2;
    ...
    private readonly Tn fn;

    public __Anonymous1(T1 a1, T2 a2, ..., Tn an) {
        f1 = a1;
        f2 = a2;
        ...
        fn = an;
    }

    public T1 p1 { get { return f1; } }
    public T2 p2 { get { return f2; } }
    ...
    public Tn pn { get { return fn; } }

    public override bool Equals(object __o) { ... }
    public override int GetHashCode() { ... }
}
```

其中每个`Tx`是一种相应表达式`ex`。 中使用的表达式*member_declarator*必须具有类型。 因此，它是中的表达式的编译时错误*member_declarator*为 null 或匿名函数。 它也是不安全类型的表达式的编译时错误。

匿名类型和参数的名称及其`Equals`方法由编译器自动生成，不能引用中程序文本。

在同一程序中两个匿名对象初始值设定项的相同顺序指定相同的名称和编译时类型的属性的序列将生成相同匿名类型的实例。

在示例

C#复制

```csharp
var p1 = new { Name = "Lawnmower", Price = 495.00 };
var p2 = new { Name = "Shovel", Price = 26.95 };
p1 = p2;
```

允许在最后一行的分配进行，因为`p1`和`p2`同一匿名类型。

`Equals`和`GetHashcode`匿名类型的方法重写方法继承自`object`，和定义的`Equals`和`GetHashcode`属性，以便同一匿名类型的两个实例相等，如果且仅当所有属性都都相等。

成员声明符可以缩写为简单名称 ([类型推理](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#type-inference))，成员访问 ([进行编译时检查的动态重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#compile-time-checking-of-dynamic-overload-resolution))，基访问 ([基访问](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#base-access))或 null 条件成员访问 ([Null 条件表达式作为投影初始值设定项](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#null-conditional-expressions-as-projection-initializers))。 这称为***投影初始值设定项***和是分配到具有相同名称的属性和声明的简写。 具体而言，成员声明符的窗体

C#复制

```csharp
identifier
expr.identifier
```

完全等效于以下内容，分别是：

C#复制

```csharp
identifier = identifier
identifier = expr.identifier
```

因此，在投影初始值设定项*标识符*选择值和字段或属性赋值。 直观地说，投影初始值设定项项目而不仅仅是一个值，但还的值的名称。

### Typeof 运算符

`typeof`运算符用于获取`System.Type`类型对象。

antlr复制

```antlr
typeof_expression
    : 'typeof' '(' type ')'
    | 'typeof' '(' unbound_type_name ')'
    | 'typeof' '(' 'void' ')'
    ;

unbound_type_name
    : identifier generic_dimension_specifier?
    | identifier '::' identifier generic_dimension_specifier?
    | unbound_type_name '.' identifier generic_dimension_specifier?
    ;

generic_dimension_specifier
    : '<' comma* '>'
    ;

comma
    : ','
    ;
```

第一个窗体*typeof_expression*组成`typeof`关键字后跟用圆括号括起来*类型*。 这种形式的表达式的结果是`System.Type`所指示类型的对象。 只有一个`System.Type`对于任何给定类型的对象。 这意味着，对于类型 `T`，`typeof(T) == typeof(T)`始终为 true。 *类型*不能为`dynamic`。

第二个窗体*typeof_expression*组成`typeof`关键字后跟用圆括号括起来*unbound_type_name*。*Unbound_type_name*非常类似于*type_name* ([Namespace 和类型名称](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/basic-concepts#namespace-and-type-names))，只不过*unbound_type_name*包含*generic_dimension_specifier*s 其中*type_name*包含*type_argument_list*s。 时的操作数*typeof_expression*是满足这两者的语法的标记序列*unbound_type_name*并*type_name*，即当它所包含的位置既不*generic_dimension_specifier*也不是*type_argument_list*，令牌的序列被视为可*type_name*。 含义*unbound_type_name* ，如下所示确定：

- 将转换为标记的顺序*type_name*通过替换每个*generic_dimension_specifier*与*type_argument_list*具有相同数量的逗号和关键字`object`为每个*type_argument*。
- 评估得到*type_name*，但会忽略所有类型参数约束。
- *Unbound_type_name*解析为与生成的构造类型关联的未绑定泛型类型 ([绑定和未绑定类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/types#bound-and-unbound-types))。

结果*typeof_expression*是`System.Type`对象生成未绑定泛型类型。

第三种形式*typeof_expression*组成`typeof`关键字后跟用圆括号括起来`void`关键字。 这种形式的表达式的结果是`System.Type`表示没有一种类型的对象。 返回的类型对象`typeof(void)`不同于为任何类型返回的类型对象。 这种特殊类型对象在类库中的反射到方法允许在语言中，这些方法希望有一种方法来表示任何方法，包括具有的实例 void 方法的返回类型很有用`System.Type`。

`typeof`运算符可以用于类型参数。 结果是`System.Type`已绑定到类型参数的运行时类型的对象。 `typeof`运算符还可构造的类型或未绑定的泛型类型上 ([绑定和未绑定类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/types#bound-and-unbound-types))。 `System.Type`对象未绑定的泛型类型不是与相同`System.Type`实例类型的对象。 实例类型都在运行时封闭式构造的类型因此其`System.Type`对象取决于在使用中，运行时类型自变量而未绑定的泛型类型不具有任何类型实参。

该示例

C#复制

```csharp
using System;

class X<T>
{
    public static void PrintTypes() {
        Type[] t = {
            typeof(int),
            typeof(System.Int32),
            typeof(string),
            typeof(double[]),
            typeof(void),
            typeof(T),
            typeof(X<T>),
            typeof(X<X<T>>),
            typeof(X<>)
        };
        for (int i = 0; i < t.Length; i++) {
            Console.WriteLine(t[i]);
        }
    }
}

class Test
{
    static void Main() {
        X<int>.PrintTypes();
    }
}
```

生成以下输出：

复制

```
System.Int32
System.Int32
System.String
System.Double[]
System.Void
System.Int32
X`1[System.Int32]
X`1[X`1[System.Int32]]
X`1[T]
```

请注意，`int`和`System.Int32`属于同一类型。

另请注意的结果`typeof(X<>)`不依赖于类型参数，但的结果`typeof(X<T>)`does。

### Checked 和 unchecked 运算符

`checked`并`unchecked`运算符用于控制***溢出检查上下文***整型类型算术运算和转换。

antlr复制

```antlr
checked_expression
    : 'checked' '(' expression ')'
    ;

unchecked_expression
    : 'unchecked' '(' expression ')'
    ;
```

`checked`运算符计算包含在 checked 上下文中，表达式和`unchecked`运算符会求值在未检查的上下文中包含的表达式。 一个*checked_expression*或*unchecked_expression*完全对应于*parenthesized_expression* ([带括号的表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#parenthesized-expressions))，但包含的表达式计算中给定的溢出检查上下文。

此外可以通过控制溢出检查上下文`checked`并`unchecked`语句 ([checked 和 unchecked 语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/statements#the-checked-and-unchecked-statements))。

以下操作受溢出检查上下文来建立`checked`和`unchecked`运算符和语句：

- 预定义`++`并`--`一元运算符 ([后缀递增和递减运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#postfix-increment-and-decrement-operators)并[前缀递增和递减运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#prefix-increment-and-decrement-operators))、 一个操作数是一个整型的类型。
- 预定义`-`一元运算符 ([一元负运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#unary-minus-operator))、 一个操作数是一种整型类型。
- 预定义`+`， `-`， `*`，和`/`二元运算符 ([算术运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#arithmetic-operators))，当这两个操作数都是整数类型。
- 显式数值转换 ([显式数值转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#explicit-numeric-conversions)) 从一种整型类型到另一个整型类型，或从`float`或`double`为整型类型。

当上述操作的其中一个生成的结果太大而无法表示目标类型，该操作执行的控件的上下文中产生的行为：

- 在中`checked`情况下，如果该操作是一个常量表达式 ([常量表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#constant-expressions))，则发生编译时错误。 否则为如果在运行时执行该操作`System.OverflowException`引发。
- 在`unchecked`上下文中，结果被截断，放弃不适合目标类型中的任何高序位。

对非常量表达式 （在运行时计算的表达式），不包含任何`checked`或`unchecked`运算符或语句时，默认值溢出检查上下文是`unchecked`除非外部因素 （如编译器有关交换机和执行环境配置） 调用`checked`评估。

常量表达式 （可以在编译时完全计算的表达式），对于默认溢出检查上下文始终是`checked`。 除非常量表达式显式置于`unchecked`上下文中，表达式始终的编译时计算期间发生的溢出会导致编译时错误。

匿名函数的主体不会影响`checked`或`unchecked`匿名函数中发生的上下文。

在示例

C#复制

```csharp
class Test
{
    static readonly int x = 1000000;
    static readonly int y = 1000000;

    static int F() {
        return checked(x * y);      // Throws OverflowException
    }

    static int G() {
        return unchecked(x * y);    // Returns -727379968
    }

    static int H() {
        return x * y;               // Depends on default
    }
}
```

由于可以在编译时计算的表达式都不报告任何编译时错误。 在运行时`F`方法会抛出`System.OverflowException`，和`G`方法返回-727379968 （超出范围结果的低 32 位）。 行为`H`方法取决于默认溢出检查上下文在编译中，但它是与相同`F`或相同`G`。

在示例

C#复制

```csharp
class Test
{
    const int x = 1000000;
    const int y = 1000000;

    static int F() {
        return checked(x * y);      // Compile error, overflow
    }

    static int G() {
        return unchecked(x * y);    // Returns -727379968
    }

    static int H() {
        return x * y;               // Compile error, overflow
    }
}
```

评估中的常量表达式时发生溢出`F`并`H`导致编译时错误报告，因为在计算这些表达式`checked`上下文。 评估中的常量表达式时，也会发生溢出`G`，但由于计算发生在`unchecked`上下文中，不报告溢出。

`checked`并`unchecked`运算符只会影响溢出检查上下文的那些操作的文本中包含"`(`"和"`)`"令牌。 运算符具有作为包含的表达式求值结果调用的函数成员没有影响。 在示例

C#复制

```csharp
class Test
{
    static int Multiply(int x, int y) {
        return x * y;
    }

    static int F() {
        return checked(Multiply(1000000, 1000000));
    }
}
```

利用`checked`中`F`不会影响的评估`x * y`中`Multiply`，因此`x * y`默认溢出检查上下文中计算。

`unchecked`运算符时，可以方便十六进制表示法中编写的带符号整型的常数。 例如：

C#复制

```csharp
class Test
{
    public const int AllBits = unchecked((int)0xFFFFFFFF);

    public const int HighBit = unchecked((int)0x80000000);
}
```

这两个以上的十六进制常量的类型是`uint`。 因为这些常量包括外部`int`范围，不带`unchecked`运算符、 强制转换到`int`会生成编译时错误。

`checked`和`unchecked`运算符和语句，程序员可以控制某些数值计算的某些方面。 但是，某些数字运算符的行为取决于其操作数的数据类型。 例如，始终乘以两位小数会导致溢出异常，即使在显式`unchecked`构造。 同样，乘以两个浮动永远不会结果中溢出异常，即使在显式`checked`构造。 此外，其他运算符永远不会受检查的模式，无论是默认或显式。

### 默认值表达式

默认值表达式用于获取默认值 ([默认值](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/variables#default-values)) 的类型。 通常默认值表达式用于类型参数，因为它可能不知道如果类型参数为值类型或引用类型。 (不存在从转换`null`除非类型参数已知为引用类型的类型参数为文字。)

antlr复制

```antlr
default_value_expression
    : 'default' '(' type ')'
    ;
```

如果*类型*中*default_value_expression*计算结果为引用类型运行时，结果是`null`转换为该类型。 如果*类型*中*default_value_expression*计算结果在运行时对值类型，结果是*value_type*的默认值 ([默认构造函数](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/types#default-constructors))。

一个*default_value_expression*是常量表达式 ([常量表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#constant-expressions)) 如果类型是引用类型或类型参数引用类型已知的 ([类型参数约束](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#type-parameter-constraints))。 此外， *default_value_expression*是常量表达式，如果类型为以下值类型之一： `sbyte`， `byte`， `short`， `ushort`， `int`， `uint`，`long`， `ulong`， `char`， `float`， `double`， `decimal`， `bool`，或任何枚举类型。

### Nameof 表达式

一个*nameof_expression*用于获得常量字符串作为程序实体的名称。

antlr复制

```antlr
nameof_expression
    : 'nameof' '(' named_entity ')'
    ;

named_entity
    : simple_name
    | named_entity_target '.' identifier type_argument_list?
    ;

named_entity_target
    : 'this'
    | 'base'
    | named_entity 
    | predefined_type 
    | qualified_alias_member
    ;
```

语法上讲， *named_entity*操作数始终是一个表达式。 因为`nameof`不是保留的关键字，nameof 表达式始终是语法上使用的简单名称的调用不明确`nameof`。 出于兼容性原因，如果名称查找 ([的简单名称](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#simple-names)) 的名称`nameof`成功，该表达式将被视为*invocation_expression* -无论是否调用处于法律。 否则它是*nameof_expression*。

含义*named_entity*的*nameof_expression*是表达式，则为它的含义，即以作为*simple_name*、 *base_access*或*member_access*。 但是，在其中查找中所述[的简单名称](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#simple-names)并[成员访问](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#member-access)会导致出现错误，因为在静态上下文中，发现了实例成员*nameof_expression*会生成任何此类错误。

它是编译时错误*named_entity*指定一个方法组能够*type_argument_list*。 它是用于编译时错误*named_entity_target*类型`dynamic`。

一个*nameof_expression*是类型的常量表达式`string`，因此在运行时已失效。 具体而言，其*named_entity*则不会评估，并忽略有关进行明确赋值分析 ([简单表达式的一般规则](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/variables#general-rules-for-simple-expressions))。 其值是最后一个标识符*named_entity*之前的可选最终*type_argument_list*转换如下所示：

- 前缀"`@`"，如果使用，会删除。
- 每个*unicode_escape_sequence*转换为其对应的 Unicode 字符。
- 任何*formatting_characters*删除。

这些是相同的转换应用于[标识符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#identifiers)时测试标识符是否相等。

TODO： 示例

### 匿名方法表达式

*Anonymous_method_expression*是定义一个匿名函数的两种方式之一。 在中进一步说明[匿名函数表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#anonymous-function-expressions)。

## 一元运算符

`?`， `+`， `-`， `!`， `~`， `++`，`--`强制转换，和`await`运算符被称作一元运算符。

antlr复制

```antlr
unary_expression
    : primary_expression
    | null_conditional_expression
    | '+' unary_expression
    | '-' unary_expression
    | '!' unary_expression
    | '~' unary_expression
    | pre_increment_expression
    | pre_decrement_expression
    | cast_expression
    | await_expression
    | unary_expression_unsafe
    ;
```

如果操作数*unary_expression*具有编译时类型`dynamic`，动态绑定 ([动态绑定](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#dynamic-binding))。 在这种情况下的编译时类型*unary_expression*是`dynamic`，如下所述的分辨率将发生在运行时使用的运行时类型操作数的和。

### Null 条件运算符

仅当该操作数为非 null，null 条件运算符适用于其操作数的操作的列表。 否则应用运算符的结果是`null`。

antlr复制

```antlr
null_conditional_expression
    : primary_expression null_conditional_operations
    ;

null_conditional_operations
    : null_conditional_operations? '?' '.' identifier type_argument_list?
    | null_conditional_operations? '?' '[' argument_list ']'
    | null_conditional_operations '.' identifier type_argument_list?
    | null_conditional_operations '[' argument_list ']'
    | null_conditional_operations '(' argument_list? ')'
    ;
```

成员访问和元素访问操作 （它本身可能是 null 条件），以及调用可以包含的操作的列表。

例如，表达式`a.b?[0]?.c()`是*null_conditional_expression*与*primary_expression* `a.b`和*null_conditional_operations* `?[0]` （null 条件元素访问）， `?.c` （null 条件成员访问） 和`()`（调用）。

有关*null_conditional_expression* `E`与*primary_expression* `P`，可让`E0`是通过文本上删除了前导获取表达式`?`从每个*null_conditional_operations*的`E`，有一个。 从概念上讲，`E0`无 null 检查所表示的情况下计算的表达式`?`找到了 s `null`。

此外，让`E1`是获取通过文本上删除了前导表达式`?`只需从的第一个*null_conditional_operations*中`E`。 这可能会导致*主表达式*(如果有一个`?`) 或另一个*null_conditional_expression*。

例如，如果`E`的表达式`a.b?[0]?.c()`，然后`E0`表达式`a.b[0].c()`并`E1`的表达式`a.b[0]?.c()`。

如果`E0`归类为执行任何操作，然后`E`归类为执行任何操作。 否则 E 分类为一个值。

`E0` 并`E1`用于确定的含义`E`:

- 如果`E`作为发生*statement_expression*的含义`E`等同于该语句

  C#复制

  ```csharp
  if ((object)P != null) E1;
  ```

  除非 P 计算仅一次。

- 否则为如果`E0`归类为任何内容将发生编译时错误。

- 否则，让`T0`是类型的`E0`。

  - 如果`T0`是类型参数都不知道为引用类型或不可以为 null 的值类型，则发生编译时错误。

  - 如果`T0`为非空值类型，则类型`E`是`T0?`，和的含义`E`相同

    C#复制

    ```csharp
    ((object)P == null) ? (T0?)null : E1
    ```

    只不过`P`只计算一次。

  - 否则 E 的类型是 T0，和 E 的含义等同于

    C#复制

    ```csharp
    ((object)P == null) ? null : E1
    ```

    只不过`P`只计算一次。

如果`E1`本身*null_conditional_expression*，然后这些规则应用同样，嵌套的测试`null`直到不再有`?`的并一直向下减少了表达式主表达式`E0`。

例如，如果表达式`a.b?[0]?.c()`发生作为语句的表达式，如在语句中所示：

C#复制

```csharp
a.b?[0]?.c();
```

它的含义等同于：

C#复制

```csharp
if (a.b != null) a.b[0]?.c();
```

这同样是等效于：

C#复制

```csharp
if (a.b != null) if (a.b[0] != null) a.b[0].c();
```

只不过`a.b`和`a.b[0]`计算仅一次。

如果它出现在其中使用它的值，如下所示： 上下文中：

C#复制

```csharp
var x = a.b?[0]?.c();
```

并假设的最后一个调用的类型不是不可以为 null 的值类型，其含义等同于：

C#复制

```csharp
var x = (a.b == null) ? null : (a.b[0] == null) ? null : a.b[0].c();
```

只不过`a.b`和`a.b[0]`计算仅一次。

#### Null 条件表达式作为投影初始值设定项

Null 条件表达式仅允许作为*member_declarator*中*anonymous_object_creation_expression* ([匿名对象创建表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#anonymous-object-creation-expressions)) 如果它以结尾 （根据需要 null 条件） 成员访问。 从语法角度而言，此要求可表示为：

antlr复制

```antlr
null_conditional_member_access
    : primary_expression null_conditional_operations? '?' '.' identifier type_argument_list?
    | primary_expression null_conditional_operations '.' identifier type_argument_list?
    ;
```

这是一种特殊的语法的情况*null_conditional_expression*上面。 对于生产*member_declarator*中[匿名对象创建表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#anonymous-object-creation-expressions)只包含*null_conditional_member_access*。

#### Null 条件表达式作为语句表达式

Null 条件表达式仅允许作为*statement_expression* ([表达式语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/statements#expression-statements)) 如果使用的调用结束。 从语法角度而言，此要求可表示为：

antlr复制

```antlr
null_conditional_invocation_expression
    : primary_expression null_conditional_operations '(' argument_list? ')'
    ;
```

这是一种特殊的语法的情况*null_conditional_expression*上面。 对于生产*statement_expression*中[表达式语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/statements#expression-statements)只包含*null_conditional_invocation_expression*。

### 一元加运算符

有关操作的窗体`+x`，一元运算符重载决策 ([一元运算符重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#unary-operator-overload-resolution)) 应用以选择特定的运算符实现。 操作数转换为所选运算符的参数类型和结果的类型是运算符的返回类型。 预定义的一元加运算符为：

C#复制

```csharp
int operator +(int x);
uint operator +(uint x);
long operator +(long x);
ulong operator +(ulong x);
float operator +(float x);
double operator +(double x);
decimal operator +(decimal x);
```

对于每个这些运算符，结果就是操作数的值。

### 一元负运算符

有关操作的窗体`-x`，一元运算符重载决策 ([一元运算符重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#unary-operator-overload-resolution)) 应用以选择特定的运算符实现。 操作数转换为所选运算符的参数类型和结果的类型是运算符的返回类型。 预定义的求反运算符为：

- 整数求反：

  C#复制

  ```csharp
  int operator -(int x);
  long operator -(long x);
  ```

  通过减去计算结果`x`从零开始。 如果的值的`x`是最小的可表示的操作数类型值 (-2 ^31 个`int`或-2 ^63 有关`long`)，然后的算术求反`x`不能显示中的操作数类型。 如果发生此情况中`checked`上下文中，`System.OverflowException`引发; 如果它出现在`unchecked`上下文中，结果是操作数的值，并且不报告溢出。

  求反运算符的操作数是否为类型`uint`，它将转换为类型`long`，并且结果的类型为`long`。 例外情况是规则，允许`int`值介于-2147483648 (-2 ^31) 写为十进制整数 ([整数文本](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#integer-literals))。

  如果求反运算符的操作数是类型`ulong`，则发生编译时错误。 例外情况是规则，允许`long`值-9223372036854775808 (-2 ^63) 写为十进制整数 ([整数文本](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#integer-literals))。

- 浮点求反：

  C#复制

  ```csharp
  float operator -(float x);
  double operator -(double x);
  ```

  结果为的值`x`符号相反的。 如果`x`为 NaN，则结果也为 NaN。

- 十进制求反：

  C#复制

  ```csharp
  decimal operator -(decimal x);
  ```

  通过减去计算结果`x`从零开始。 十进制求反运算等效于使用一元负运算符类型的`System.Decimal`。

### 逻辑求反运算符

有关操作的窗体`!x`，一元运算符重载决策 ([一元运算符重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#unary-operator-overload-resolution)) 应用以选择特定的运算符实现。 操作数转换为所选运算符的参数类型和结果的类型是运算符的返回类型。 只有一个预定义的逻辑求反运算符存在：

C#复制

```csharp
bool operator !(bool x);
```

此运算符将计算操作数的逻辑求反运算：如果操作数是`true`，结果是`false`。 如果操作数是`false`，结果是`true`。

### 按位求补运算符

有关操作的窗体`~x`，一元运算符重载决策 ([一元运算符重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#unary-operator-overload-resolution)) 应用以选择特定的运算符实现。 操作数转换为所选运算符的参数类型和结果的类型是运算符的返回类型。 预定义的按位求补运算符为：

C#复制

```csharp
int operator ~(int x);
uint operator ~(uint x);
long operator ~(long x);
ulong operator ~(ulong x);
```

对于每个这些运算符，该操作的结果是按位求补`x`。

每个枚举类型`E`隐式提供了以下的按位求补运算符：

C#复制

```csharp
E operator ~(E x);
```

计算结果`~x`，其中`x`是枚举类型的表达式`E`与基础类型`U`，正是与评估相同`(E)(~(U)x)`，只不过转换为`E`是始终作为执行中的 if`unchecked`上下文 ([checked 和 unchecked 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#the-checked-and-unchecked-operators))。

### 前缀增量和减量运算符

antlr复制

```antlr
pre_increment_expression
    : '++' unary_expression
    ;

pre_decrement_expression
    : '--' unary_expression
    ;
```

操作数的前缀递增或递减操作必须是归类为变量、 属性访问或索引器访问的表达式。 操作的结果是类型的操作数相同的值。

如果操作数的前缀递增或递减操作是一个属性或索引器访问、 属性或索引器必须同时具有`get`和一个`set`访问器。 如果这不是这种情况，绑定时出错。

一元运算符重载决策 ([一元运算符重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#unary-operator-overload-resolution)) 应用以选择特定的运算符实现。 预定义`++`并`--`运算符存在以下类型： `sbyte`， `byte`， `short`， `ushort`， `int`， `uint`， `long`， `ulong`， `char``float`， `double`， `decimal`，和任何枚举类型。 预定义`++`运算符将返回通过将 1 添加到操作数，并在预定义生成的值`--`运算符返回生成的数减去 1 的操作数的值。 在中`checked`情况下，如果此加法或减法的结果是结果类型的范围之外，结果类型是整数类型或枚举类型`System.OverflowException`引发。

运行时处理的前缀递增或递减运算的窗体`++x`或`--x`包括以下步骤：

- 如果`x`分类为变量：
  - `x` 计算为生成变量。
  - 所选的运算符调用值为`x`作为其参数。
  - 运算符返回的值存储在给定的评估结果的位置`x`。
  - 运算符返回的值将成为操作的结果。
- 如果`x`归类为属性或索引器访问：
  - 实例表达式 (如果`x`不是`static`) 和参数列表 (如果`x`的索引器访问) 与关联`x`计算，然后在后续结果`get`和`set`取值函数调用。
  - `get`访问器的`x`调用。
  - 使用返回的值调用所选的运算符`get`作为其参数的取值函数。
  - `set`访问器的`x`作为运算符所返回的值调用其`value`参数。
  - 运算符返回的值将成为操作的结果。

`++`并`--`运算符也支持后缀表示法 ([后缀递增和递减运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#postfix-increment-and-decrement-operators))。 通常情况下的结果`x++`或`x--`的值`x`前该操作，而的结果`++x`或`--x`的值`x`操作完成后。 在任一情况下，`x`本身完成操作后具有相同的值。

`operator++`或`operator--`实现可以使用后缀或前缀表示法来调用。 不能具有这两种表示的运算符的不同实现。

### 强制转换表达式

一个*cast_expression*用于将表达式显式转换为给定类型。

antlr复制

```antlr
cast_expression
    : '(' type ')' unary_expression
    ;
```

一个*cast_expression*窗体`(T)E`，其中`T`是*类型*并`E`是*unary_expression*，执行显式转换 ([显式转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#explicit-conversions)) 的值的`E`键入`T`。 如果不存在从任何显式转换`E`到`T`，绑定时出错。 否则，结果为显式转换生成的值。 结果始终分类为一个值，即使`E`表示的变量。

语法*cast_expression*会导致某些语法多义性。 例如，表达式`(x)-y`是可解释为*cast_expression* (的强制转换`-y`键入`x`) 或*additive_expression*与结合使用*parenthesized_expression* (用于计算值`x - y)`。

若要解决*cast_expression*存在二义性，以下规则：一个或多个序列*令牌*s ([空白区域](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#white-space)) 括在括号中被视为开头*cast_expression*仅当至少一个以下条件成立：

- 标记的顺序是为正确的语法*类型*，而不是*表达式*。
- 标记的顺序是为正确的语法*类型*，并紧接在右括号是令牌"`~`"，令牌"`!`"，令牌"`(`"、 *标识符*([Unicode 字符转义序列](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#unicode-character-escape-sequences))、 一个*文字*([文本](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#literals))，或任何*关键字*([关键字](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#keywords)) 除外`as`和`is`。

术语"正确的语法"表示仅标记的顺序必须符合特定的语法产生上面。 它专门不考虑任何构成的标识符的实际含义。 例如，如果`x`并`y`是标识符，然后`x.y`是正确的语法，对于类型，即使`x.y`实际并不表示一种类型。

从消除歧义规则，它遵循的如果`x`和`y`是标识符，都`(x)y`， `(x)(y)`，并`(x)(-y)`是*cast_expression*s，但`(x)-y`不是，即使`x`标识的类型。 但是，如果`x`是标识预定义的类型的关键字 (如`int`)，则所有四个窗体*cast_expression*s （因为这种关键字不可能是表达式本身）。

### Await 表达式

Await 运算符用于挂起封闭的异步函数的求值，直到在操作数表示的异步操作完成。

antlr复制

```antlr
await_expression
    : 'await' unary_expression
    ;
```

*Await_expression*只允许在异步函数的主体 ([迭代器](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#iterators))。 在最近的封闭异步函数*await_expression*可能不会出现在这些位置：

- 在嵌套的 （非异步） 匿名函数
- 在的块内*lock_statement*
- 在不安全的上下文中

请注意， *await_expression*不能出现在大多数位置内*query_expression*，因为这些语法上转换为使用非异步 lambda 表达式。

在异步函数，内部`await`不能用作标识符。 因此是 await 表达式和各种表达式涉及标识符之间没有句法歧义。异步函数之外`await`充当正常的标识符。

操作数*await_expression*称为***任务***。 表示异步操作，可能会或可能不完整时*await_expression*进行计算。 Await 运算符的目的是能够挂起封闭的异步函数的执行，直到所等待的任务已完成，然后获取其结果。

#### 可等待操作的表达式

该任务的 await 表达式必须是***awaitable***。 一个表达式`t`是以下之一保存的情况下可等待：

- `t` 编译时类型 `dynamic`
- `t` 已调用的可访问实例或扩展方法`GetAwaiter`没有参数和没有类型参数和返回类型与`A`为其满足以下所有保存：
  - `A` 实现接口`System.Runtime.CompilerServices.INotifyCompletion`(以后称为`INotifyCompletion`为简洁起见)
  - `A` 具有可访问的、 可读的实例属性`IsCompleted`的类型 `bool`
  - `A` 具有可访问的实例方法`GetResult`没有参数，没有类型参数

目的`GetAwaiter`的方法是获取***awaiter***任务。 类型`A`称为***awaiter 类型***await 表达式。

用途`IsCompleted`属性将确定任务是否已完成。 如果是这样，就不必挂起评估。

目的`INotifyCompletion.OnCompleted`方法是注册到任务;"继续"即委托 (类型的`System.Action`) 任务完成后，将调用的。

用途`GetResult`方法是完成后获得的结果的任务。 这种情况可能会成功完成后，可能与结果值，也可能是由引发该异常`GetResult`方法。

#### 分类的 await 表达式

表达式`await t`分类的表达式的相同方式`(t).GetAwaiter().GetResult()`。 因此，如果的返回类型的`GetResult`是`void`，则*await_expression*归类为执行任何操作。 如果它具有非 void 返回类型`T`，则*await_expression*分类类型的值为`T`。

#### 运行时计算的 await 表达式

在运行时，该表达式`await t`的计算方式如下：

- Awaiter`a`通过计算该表达式获得`(t).GetAwaiter()`。

- 一个`bool``b`通过计算该表达式获得`(a).IsCompleted`。

- 如果`b`是`false`，然后计算取决于是否`a`实现接口`System.Runtime.CompilerServices.ICriticalNotifyCompletion`(以后称为`ICriticalNotifyCompletion`为简洁起见)。

   

  在绑定时间; 执行此检查即在运行时如果`a`具有的编译时类型`dynamic`，而是在编译时以其他方式。

   

  让`r`表示恢复委托 ([迭代器](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#iterators)):

  - 如果`a`不实现`ICriticalNotifyCompletion`，然后表达式`(a as (INotifyCompletion)).OnCompleted(r)`进行计算。
  - 如果`a`实现`ICriticalNotifyCompletion`，然后表达式`(a as (ICriticalNotifyCompletion)).UnsafeOnCompleted(r)`进行计算。
  - 然后暂停计算，以及将控制返回给异步函数的当前调用方。

- 任一后立即 (如果`b`已`true`)，或更高版本调用恢复委托时 (如果`b`已`false`)，该表达式`(a).GetResult()`进行计算。 如果它返回一个值，该值是对*await_expression*。 否则结果是执行任何操作。

接口方法实现的 awaiter`INotifyCompletion.OnCompleted`和`ICriticalNotifyCompletion.UnsafeOnCompleted`应导致委托`r`最多一次调用。 否则，将封闭的异步函数的行为是不确定的。

## 算术运算符

`*`， `/`， `%`， `+`，和`-`运算符被称作算术运算符。

antlr复制

```antlr
multiplicative_expression
    : unary_expression
    | multiplicative_expression '*' unary_expression
    | multiplicative_expression '/' unary_expression
    | multiplicative_expression '%' unary_expression
    ;

additive_expression
    : multiplicative_expression
    | additive_expression '+' multiplicative_expression
    | additive_expression '-' multiplicative_expression
    ;
```

如果操作数的算术运算符的已编译时类型`dynamic`，然后动态绑定表达式 ([动态绑定](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#dynamic-binding))。 在这种情况下该表达式的编译时类型是`dynamic`，如下所述的分辨率将发生在运行时使用这些具有编译时类型的操作数的运行时类型和`dynamic`。

### 乘法运算符

有关操作的窗体`x * y`，二元运算符重载决策 ([二元运算符重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#binary-operator-overload-resolution)) 应用以选择特定的运算符实现。 操作数都转换为所选运算符的参数类型和结果的类型是运算符的返回类型。

下面列出了预定义的乘法运算符。 所有运算符将都计算的产品`x`和`y`。

- 整数乘法：

  C#复制

  ```csharp
  int operator *(int x, int y);
  uint operator *(uint x, uint y);
  long operator *(long x, long y);
  ulong operator *(ulong x, ulong y);
  ```

  在中`checked`情况下，该产品已超出范围的结果类型，如果`System.OverflowException`引发。 在`unchecked`上下文，则不报告溢出和范围之外的结果类型的任何重大高顺序位将被丢弃。

- 浮点乘法：

  C#复制

  ```csharp
  float operator *(float x, float y);
  double operator *(double x, double y);
  ```

  根据 IEEE 754 算法的规则计算乘积。 下表列出的所有可能组合的非零的有限值、 零、 无穷大和 NaN 的结果。 在表中，`x`和`y`是有限的正值。 `z` 是的结果`x * y`。 如果结果为目标类型太大`z`为无穷大。 如果结果为目标类型太小`z`为零。

  |      |      |      |      |      |      |      |      |
  | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
  |      | +y   | -y   | +0   | -0   | +inf | -inf | NaN  |
  | +x   | +z   | -z   | +0   | -0   | +inf | -inf | NaN  |
  | -x   | -z   | +z   | -0   | +0   | -inf | +inf | NaN  |
  | +0   | +0   | -0   | +0   | -0   | NaN  | NaN  | NaN  |
  | -0   | -0   | +0   | -0   | +0   | NaN  | NaN  | NaN  |
  | +inf | +inf | -inf | NaN  | NaN  | +inf | -inf | NaN  |
  | -inf | -inf | +inf | NaN  | NaN  | -inf | +inf | NaN  |
  | NaN  | NaN  | NaN  | NaN  | NaN  | NaN  | NaN  | NaN  |

- 十进制乘法：

  C#复制

  ```csharp
  decimal operator *(decimal x, decimal y);
  ```

  如果生成的值是太大，无法表示在`decimal`格式，`System.OverflowException`引发。 如果结果值就太小，无法在表示`decimal`格式，则结果为零。 结果，任何舍入之前, 的小数位数是这些标度的两个操作数之和。

  十进制乘法相当于使用类型的乘法运算符`System.Decimal`。

### 除法运算符

有关操作的窗体`x / y`，二元运算符重载决策 ([二元运算符重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#binary-operator-overload-resolution)) 应用以选择特定的运算符实现。 操作数都转换为所选运算符的参数类型和结果的类型是运算符的返回类型。

下面列出了预定义的除法运算符。 所有运算符将都计算所得的商`x`和`y`。

- 整数除法：

  C#复制

  ```csharp
  int operator /(int x, int y);
  uint operator /(uint x, uint y);
  long operator /(long x, long y);
  ulong operator /(ulong x, ulong y);
  ```

  如果右操作数的值为零，`System.DivideByZeroException`引发。

  该除法运算将向零结果舍入。 因此，结果的绝对值是商的小于或等于两个操作数的绝对值的最大可能整数。 时两个操作数具有相同的登录以及零个或两个操作数具有符号相反时为负，则结果为零或正数。

  如果左的操作数是可表示最小`int`或`long`值和右操作数是`-1`，会发生溢出。 在中`checked`上下文中，这会导致`System.ArithmeticException`（或其中的子类） 引发。 在`unchecked`上下文中，它是实现定义的还是`System.ArithmeticException`（或其中的子类） 会引发或溢出进入未报告与生成正在的左操作数的值。

- 浮点除法运算：

  C#复制

  ```csharp
  float operator /(float x, float y);
  double operator /(double x, double y);
  ```

  根据 IEEE 754 算法的规则计算商。 下表列出的所有可能组合的非零的有限值、 零、 无穷大和 NaN 的结果。 在表中，`x`和`y`是有限的正值。 `z` 是的结果`x / y`。 如果结果为目标类型太大`z`为无穷大。 如果结果为目标类型太小`z`为零。

  |      |      |      |      |      |      |      |      |
  | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
  |      | +y   | -y   | +0   | -0   | +inf | -inf | NaN  |
  | +x   | +z   | -z   | +inf | -inf | +0   | -0   | NaN  |
  | -x   | -z   | +z   | -inf | +inf | -0   | +0   | NaN  |
  | +0   | +0   | -0   | NaN  | NaN  | +0   | -0   | NaN  |
  | -0   | -0   | +0   | NaN  | NaN  | -0   | +0   | NaN  |
  | +inf | +inf | -inf | +inf | -inf | NaN  | NaN  | NaN  |
  | -inf | -inf | +inf | -inf | +inf | NaN  | NaN  | NaN  |
  | NaN  | NaN  | NaN  | NaN  | NaN  | NaN  | NaN  | NaN  |

- 十进制除法：

  C#复制

  ```csharp
  decimal operator /(decimal x, decimal y);
  ```

  如果右操作数的值为零，`System.DivideByZeroException`引发。 如果生成的值是太大，无法表示在`decimal`格式，`System.OverflowException`引发。 如果结果值就太小，无法在表示`decimal`格式，则结果为零。 结果的小数位数是保留结果等于最小缩放接近的可表示的十进制值为 true 的数学运算结果。

  十进制除法相当于使用类型的除法运算符`System.Decimal`。

### 余数运算符

有关操作的窗体`x % y`，二元运算符重载决策 ([二元运算符重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#binary-operator-overload-resolution)) 应用以选择特定的运算符实现。 操作数都转换为所选运算符的参数类型和结果的类型是运算符的返回类型。

下面列出了预定义的余数运算符。 所有运算符将都计算之间除法的余数`x`和`y`。

- 整数余数：

  C#复制

  ```csharp
  int operator %(int x, int y);
  uint operator %(uint x, uint y);
  long operator %(long x, long y);
  ulong operator %(ulong x, ulong y);
  ```

  结果`x % y`由生成的值`x - (x / y) * y`。 如果`y`为零，`System.DivideByZeroException`引发。

  如果左的操作数是最小`int`或`long`值和右操作数是`-1`、`System.OverflowException`引发。 在任何情况下执行`x % y`引发异常位置`x / y`将不会引发异常。

- 浮点余数：

  C#复制

  ```csharp
  float operator %(float x, float y);
  double operator %(double x, double y);
  ```

  下表列出的所有可能组合的非零的有限值、 零、 无穷大和 NaN 的结果。 在表中，`x`和`y`是有限的正值。 `z` 是的结果`x % y`，并作为计算出`x - n * y`，其中`n`小于或等于最大可能整数`x / y`。 计算余数的此方法类似于用于整数操作数，但不同于 IEEE 754 定义 (在其中`n`是最接近的整数`x / y`)。

  |      |      |      |      |      |      |      |      |
  | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
  |      | +y   | -y   | +0   | -0   | +inf | -inf | NaN  |
  | +x   | +z   | +z   | NaN  | NaN  | x    | x    | NaN  |
  | -x   | -z   | -z   | NaN  | NaN  | -x   | -x   | NaN  |
  | +0   | +0   | +0   | NaN  | NaN  | +0   | +0   | NaN  |
  | -0   | -0   | -0   | NaN  | NaN  | -0   | -0   | NaN  |
  | +inf | NaN  | NaN  | NaN  | NaN  | NaN  | NaN  | NaN  |
  | -inf | NaN  | NaN  | NaN  | NaN  | NaN  | NaN  | NaN  |
  | NaN  | NaN  | NaN  | NaN  | NaN  | NaN  | NaN  | NaN  |

- 十进制的其余部分：

  C#复制

  ```csharp
  decimal operator %(decimal x, decimal y);
  ```

  如果右操作数的值为零，`System.DivideByZeroException`引发。 结果，任何舍入之前, 的小数位数是较大的两个操作数，这些标度和运算的结果，如果非零，则将相同的是`x`。

  十进制的其余部分相当于使用余数运算符的类型`System.Decimal`。

### 加法运算符

有关操作的窗体`x + y`，二元运算符重载决策 ([二元运算符重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#binary-operator-overload-resolution)) 应用以选择特定的运算符实现。 操作数都转换为所选运算符的参数类型和结果的类型是运算符的返回类型。

下面列出了预定义的加法运算符。 对于数值和枚举类型预定义的加法运算符计算两个操作数之和。 当一个或两个操作数都是字符串类型时，预定义的加法运算符串联操作数的字符串表示形式。

- 整数添加：

  C#复制

  ```csharp
  int operator +(int x, int y);
  uint operator +(uint x, uint y);
  long operator +(long x, long y);
  ulong operator +(ulong x, ulong y);
  ```

  在中`checked`情况下，如果总和不在范围内的结果类型，`System.OverflowException`引发。 在`unchecked`上下文，则不报告溢出和范围之外的结果类型的任何重大高顺序位将被丢弃。

- 浮点加法：

  C#复制

  ```csharp
  float operator +(float x, float y);
  double operator +(double x, double y);
  ```

  根据 IEEE 754 算法的规则计算总和。 下表列出的所有可能组合的非零的有限值、 零、 无穷大和 NaN 的结果。 在表中，`x`并`y`为非零的有限值，并`z`结果的`x + y`。 如果`x`并`y`具有相同的量值，但符号相反，`z`为正零。 如果`x + y`太大而无法在目标类型，表示`z`是相同的符号与无穷`x + y`。

  |      |      |      |      |      |      |      |
  | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
  |      | y    | +0   | -0   | +inf | -inf | NaN  |
  | x    | z    | x    | x    | +inf | -inf | NaN  |
  | +0   | y    | +0   | +0   | +inf | -inf | NaN  |
  | -0   | y    | +0   | -0   | +inf | -inf | NaN  |
  | +inf | +inf | +inf | +inf | +inf | NaN  | NaN  |
  | -inf | -inf | -inf | -inf | NaN  | -inf | NaN  |
  | NaN  | NaN  | NaN  | NaN  | NaN  | NaN  | NaN  |

- 十进制添加：

  C#复制

  ```csharp
  decimal operator +(decimal x, decimal y);
  ```

  如果生成的值是太大，无法表示在`decimal`格式，`System.OverflowException`引发。 结果，任何舍入之前, 的小数位数是较大的两个操作数的刻度。

  十进制添加相当于使用加法运算符的类型`System.Decimal`。

- 枚举加法。 每个枚举类型都隐式提供以下预定义的运算符，其中`E`是枚举类型，并`U`是基础类型`E`:

  C#复制

  ```csharp
  E operator +(E x, U y);
  E operator +(U x, E y);
  ```

  在运行时这些运算符的计算结果恰好`(E)((U)x + (U)y)`。

- 字符串串联：

  C#复制

  ```csharp
  string operator +(string x, string y);
  string operator +(string x, object y);
  string operator +(object x, string y);
  ```

  该二进制文件的这些重载`+`运算符执行字符串串联。 如果操作数字符串串联为`null`，替换为空字符串。否则，任何非字符串参数转换为其字符串表示形式通过调用虚拟`ToString`方法继承自类型`object`。 如果`ToString`返回`null`，替换为空字符串。

  C#复制

  ```csharp
  using System;
  
  class Test
  {
      static void Main() {
          string s = null;
          Console.WriteLine("s = >" + s + "<");        // displays s = ><
          int i = 1;
          Console.WriteLine("i = " + i);               // displays i = 1
          float f = 1.2300E+15F;
          Console.WriteLine("f = " + f);               // displays f = 1.23E+15
          decimal d = 2.900m;
          Console.WriteLine("d = " + d);               // displays d = 2.900
      }
  }
  ```

  字符串串联运算符的结果是一个左操作数的右操作数的字符后跟的字符组成的字符串。 字符串串联运算符永远不会返回`null`值。 一个`System.OutOfMemoryException`可能会引发，如果没有足够内存可用于分配生成的字符串。

- 委托组合。 每个委托类型都隐式提供以下预定义的运算符，其中`D`是委托类型：

  C#复制

  ```csharp
  D operator +(D x, D y);
  ```

  二进制`+`运算符执行委托组合两个操作数属于特定的委托类型时`D`。 （如果操作数有不同的委托类型绑定时出错。）如果在第一个操作数`null`，该操作的结果是第二个操作数的值 (即使这也是`null`)。 否则为如果第二个操作数为`null`，则该操作的结果为第一个操作数的值。 否则，该操作的结果是一个新委托实例，该实例时调用，调用第一个操作数，然后调用第二个操作数。 委托组合的示例，请参阅[减法运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#subtraction-operator)并[委托调用](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/delegates#delegate-invocation)。 由于`System.Delegate`不是委托类型， `operator`  `+`不为其定义。

### 减法运算符

有关操作的窗体`x - y`，二元运算符重载决策 ([二元运算符重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#binary-operator-overload-resolution)) 应用以选择特定的运算符实现。 操作数都转换为所选运算符的参数类型和结果的类型是运算符的返回类型。

下面列出了预定义的减法运算符。 所有减的运算符`y`从`x`。

- 整数减法运算：

  C#复制

  ```csharp
  int operator -(int x, int y);
  uint operator -(uint x, uint y);
  long operator -(long x, long y);
  ulong operator -(ulong x, ulong y);
  ```

  在中`checked`情况下，如果结果类型的范围之外的区别是`System.OverflowException`引发。 在`unchecked`上下文，则不报告溢出和范围之外的结果类型的任何重大高顺序位将被丢弃。

- 浮点减法运算：

  C#复制

  ```csharp
  float operator -(float x, float y);
  double operator -(double x, double y);
  ```

  根据 IEEE 754 算法的规则计算差。 下表列出所有可能组合的非零的有限值、 零、 无穷大和 Nan 的结果。在表中，`x`并`y`为非零的有限值，并`z`结果的`x - y`。 如果`x`并`y`相等，`z`为正零。 如果`x - y`太大而无法在目标类型，表示`z`是相同的符号与无穷`x - y`。

  |      |      |      |      |      |      |      |
  | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
  | NaN  | y    | +0   | -0   | +inf | -inf | NaN  |
  | x    | z    | x    | x    | -inf | +inf | NaN  |
  | +0   | -y   | +0   | +0   | -inf | +inf | NaN  |
  | -0   | -y   | -0   | +0   | -inf | +inf | NaN  |
  | +inf | +inf | +inf | +inf | NaN  | +inf | NaN  |
  | -inf | -inf | -inf | -inf | -inf | NaN  | NaN  |
  | NaN  | NaN  | NaN  | NaN  | NaN  | NaN  | NaN  |

- 十进制减法运算：

  C#复制

  ```csharp
  decimal operator -(decimal x, decimal y);
  ```

  如果生成的值是太大，无法表示在`decimal`格式，`System.OverflowException`引发。 结果，任何舍入之前, 的小数位数是较大的两个操作数的刻度。

  十进制减法相当于使用类型的减法运算符`System.Decimal`。

- 枚举减法。 每个枚举类型都隐式提供以下预定义的运算符，其中`E`是枚举类型，并`U`是基础类型`E`:

  C#复制

  ```csharp
  U operator -(E x, E y);
  ```

  此计算运算符的值严格按照`(U)((U)x - (U)y)`。 换而言之，该运算符计算的序号值之间的差异`x`和`y`，并且结果的类型是枚举的基础类型。

  C#复制

  ```csharp
  E operator -(E x, U y);
  ```

  此计算运算符的值严格按照`(E)((U)x - y)`。 换而言之，运算符从减去的值的基础类型的枚举，生成的枚举值。

- 移除的委托。 每个委托类型都隐式提供以下预定义的运算符，其中`D`是委托类型：

  C#复制

  ```csharp
  D operator -(D x, D y);
  ```

  二进制`-`运算符执行委托移除两个操作数属于特定的委托类型时`D`。 如果操作数有不同的委托类型绑定时出错。 如果在第一个操作数`null`，该操作的结果是`null`。 否则为如果第二个操作数为`null`，则该操作的结果为第一个操作数的值。 否则，两个操作数表示的调用列表 ([委托声明](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/delegates#delegate-declarations)) 具有一个或多个条目，并将该结果是第一个操作数的列表包括从删除的第二个操作数的条目具有一个新的调用列表它提供第二个操作数的列表是正确的连续子列表的第一个。 (若要确定子列表相等，对应项进行比较委托是否相等运算符 ([委托相等运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#delegate-equality-operators))。)否则，结果为左操作数的值。 在过程中更改任一操作数的列表。 如果第二个操作数的列表与连续列表中项的第一个操作数的多个子列表相匹配，则删除连续条目最右侧的匹配子列表。 如果删除会导致空列表，则结果是`null`。 例如：

  C#复制

  ```csharp
  delegate void D(int x);
  
  class C
  {
      public static void M1(int i) { /* ... */ }
      public static void M2(int i) { /* ... */ }
  }
  
  class Test
  {
      static void Main() { 
          D cd1 = new D(C.M1);
          D cd2 = new D(C.M2);
          D cd3 = cd1 + cd2 + cd2 + cd1;   // M1 + M2 + M2 + M1
          cd3 -= cd1;                      // => M1 + M2 + M2
  
          cd3 = cd1 + cd2 + cd2 + cd1;     // M1 + M2 + M2 + M1
          cd3 -= cd1 + cd2;                // => M2 + M1
  
          cd3 = cd1 + cd2 + cd2 + cd1;     // M1 + M2 + M2 + M1
          cd3 -= cd2 + cd2;                // => M1 + M1
  
          cd3 = cd1 + cd2 + cd2 + cd1;     // M1 + M2 + M2 + M1
          cd3 -= cd2 + cd1;                // => M1 + M2
  
          cd3 = cd1 + cd2 + cd2 + cd1;     // M1 + M2 + M2 + M1
          cd3 -= cd1 + cd1;                // => M1 + M2 + M2 + M1
      }
  }
  ```

## 移位运算符

`<<`和`>>`运算符用于执行移位运算。

antlr复制

```antlr
shift_expression
    : additive_expression
    | shift_expression '<<' additive_expression
    | shift_expression right_shift additive_expression
    ;
```

如果操作数的*shift_expression*具有编译时类型`dynamic`，然后表达式动态绑定 ([动态绑定](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#dynamic-binding))。 在这种情况下该表达式的编译时类型是`dynamic`，如下所述的分辨率将发生在运行时使用这些具有编译时类型的操作数的运行时类型和`dynamic`。

有关操作的窗体`x << count`或`x >> count`，二元运算符重载决策 ([二元运算符重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#binary-operator-overload-resolution)) 应用以选择特定的运算符实现。 操作数都转换为所选运算符的参数类型和结果的类型是运算符的返回类型。

当声明重载的移位运算符时，第一个操作数的类型必须始终为类或结构包含运算符声明和第二个操作数的类型必须始终为`int`。

下面列出了预定义的移位运算符。

- 左移位：

  C#复制

  ```csharp
  int operator <<(int x, int count);
  uint operator <<(uint x, int count);
  long operator <<(long x, int count);
  ulong operator <<(ulong x, int count);
  ```

  `<<`运算符 shifts`x`左旋转比特数计算如下所述。

  结果类型的范围之外的高顺序位`x`会被丢弃，剩余的位向左和低序空位位置设置为零。

- 右移：

  C#复制

  ```csharp
  int operator >>(int x, int count);
  uint operator >>(uint x, int count);
  long operator >>(long x, int count);
  ulong operator >>(ulong x, int count);
  ```

  `>>`运算符 shifts`x`右旋转比特数计算如下所述。

  时`x`属于类型`int`或`long`的低顺序位`x`会被丢弃，剩余的位向右，位移和高序空位位置设置为零`x`为非负，并且已设置一个用于在`x`为负。

  当`x`属于类型`uint`或`ulong`的低顺序位`x`是被丢弃，剩余的位向右位移，和高序空位位置设置为零。

对于预定义的运算符，移动的位数，如下所示计算：

- 时的类型`x`是`int`或`uint`，则移位计数由的低序五位给定`count`。 换而言之，则移位计数计算得出`count & 0x1F`。
- 时的类型`x`是`long`或`ulong`，则移位计数由的低序六位给定`count`。 换而言之，则移位计数计算得出`count & 0x3F`。

如果在生成的 shift 计数为零，则移位运算符只需返回的值`x`。

移位操作永远不会导致溢出并产生相同的结果中`checked`和`unchecked`上下文。

当左的操作数的`>>`运算符为带符号整型类型时，运算符执行算术右操作数的最高有效位 （符号位） 的值将传播其中到高序空位位置。 当左的操作数的`>>`运算符是无符号整数类型，该运算符执行逻辑右其中高序空位位置始终设置为零。 若要执行的操作数类型推断的相反的操作，可以使用显式强制转换。 例如，如果`x`类型的变量`int`，该操作`unchecked((int)((uint)x >> y))`执行的一种逻辑移位`x`。

## 关系和类型测试运算符

`==`， `!=`， `<`， `>`， `<=`， `>=`，`is`和`as`运算符被称作关系和类型测试运算符。

antlr复制

```antlr
relational_expression
    : shift_expression
    | relational_expression '<' shift_expression
    | relational_expression '>' shift_expression
    | relational_expression '<=' shift_expression
    | relational_expression '>=' shift_expression
    | relational_expression 'is' type
    | relational_expression 'as' type
    ;

equality_expression
    : relational_expression
    | equality_expression '==' relational_expression
    | equality_expression '!=' relational_expression
    ;
```

`is`运算符中所述[是运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#the-is-operator)并且`as`运算符中所述[As 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#the-as-operator)。

`==`， `!=`， `<`， `>`，`<=`并`>=`运算符是***比较运算符***。

如果比较运算符的操作数具有编译时类型`dynamic`，然后动态绑定表达式 ([动态绑定](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#dynamic-binding))。 在这种情况下该表达式的编译时类型是`dynamic`，如下所述的分辨率将发生在运行时使用这些具有编译时类型的操作数的运行时类型和`dynamic`。

有关操作的窗体`x` *op* `y`，其中*op*是一个比较运算符，重载决策 ([二元运算符重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#binary-operator-overload-resolution)) 用于选择特定的运算符实现。 操作数都转换为所选运算符的参数类型和结果的类型是运算符的返回类型。

以下各节描述了预定义的比较运算符。 所有预定义的比较运算符将返回类型的结果`bool`下, 表中所述。

| **Operation** | **结果**                                   |
| ------------- | ------------------------------------------ |
| `x == y`      | `true` 如果`x`等同于`y`，`false`否则为     |
| `x != y`      | `true` 如果`x`不等于`y`，`false`否则为     |
| `x < y`       | `true` 如果`x`是小于`y`，`false`否则为     |
| `x > y`       | `true` 如果`x`大于`y`，`false`否则为       |
| `x <= y`      | `true` 如果`x`小于或等于`y`，`false`否则为 |
| `x >= y`      | `true` 如果`x`大于或等于`y`，`false`否则为 |

### 整数比较运算符

预定义的整数比较运算符为：

C#复制

```csharp
bool operator ==(int x, int y);
bool operator ==(uint x, uint y);
bool operator ==(long x, long y);
bool operator ==(ulong x, ulong y);

bool operator !=(int x, int y);
bool operator !=(uint x, uint y);
bool operator !=(long x, long y);
bool operator !=(ulong x, ulong y);

bool operator <(int x, int y);
bool operator <(uint x, uint y);
bool operator <(long x, long y);
bool operator <(ulong x, ulong y);

bool operator >(int x, int y);
bool operator >(uint x, uint y);
bool operator >(long x, long y);
bool operator >(ulong x, ulong y);

bool operator <=(int x, int y);
bool operator <=(uint x, uint y);
bool operator <=(long x, long y);
bool operator <=(ulong x, ulong y);

bool operator >=(int x, int y);
bool operator >=(uint x, uint y);
bool operator >=(long x, long y);
bool operator >=(ulong x, ulong y);
```

每个运算符进行比较的两个整数操作数和返回数值`bool`值，该值指示是否将特定关系`true`或`false`。

### 浮点比较运算符

预定义的浮点比较运算符为：

C#复制

```csharp
bool operator ==(float x, float y);
bool operator ==(double x, double y);

bool operator !=(float x, float y);
bool operator !=(double x, double y);

bool operator <(float x, float y);
bool operator <(double x, double y);

bool operator >(float x, float y);
bool operator >(double x, double y);

bool operator <=(float x, float y);
bool operator <=(double x, double y);

bool operator >=(float x, float y);
bool operator >=(double x, double y);
```

这些运算符来比较根据 IEEE 754 标准规则操作数：

- 如果其中一个操作数为 NaN，则结果是`false`的所有运算符除外`!=`，则结果为`true`。 对于任何两个操作数，`x != y`始终生成相同的结果`!(x == y)`。 然而，当一个或两个操作数为 NaN `<`， `>`， `<=`，和`>=`运算符不产生与逻辑求反的相反运算符相同的结果。 例如，如果任一的`x`并`y`为 NaN，则`x < y`是`false`，但`!(x >= y)`是`true`。

- 当两个操作数为 NaN 时，这些运算符比较两个浮点操作数与顺序相关的值

  复制

  ```
  -inf < -max < ... < -min < -0.0 == +0.0 < +min < ... < +max < +inf
  ```

  其中`min`和`max`是最小和最大正有限值可以以给定的浮点格式表示。 值得注意的这一顺序的影响是：

  - 负数和正数零被视为相等。
  - 负无穷大被视为小于所有其他值，但等于另一个负无穷大。
  - 正无穷大被视为大于所有其他值，但等于另一个正无穷大。

### 十进制比较运算符

预定义的十进制比较运算符为：

C#复制

```csharp
bool operator ==(decimal x, decimal y);
bool operator !=(decimal x, decimal y);
bool operator <(decimal x, decimal y);
bool operator >(decimal x, decimal y);
bool operator <=(decimal x, decimal y);
bool operator >=(decimal x, decimal y);
```

每个运算符进行比较的两个十进制操作数和返回数值`bool`值，该值指示是否将特定关系`true`或`false`。 每个十进制比较相当于使用的对应关系或类型的相等运算符`System.Decimal`。

### 布尔值的相等运算符

预定义的布尔相等运算符为：

C#复制

```csharp
bool operator ==(bool x, bool y);
bool operator !=(bool x, bool y);
```

结果`==`是`true`如果这两种`x`并`y`是`true`或如果这两个`x`并`y`是`false`。 否则，结果为 `false`。

结果`!=`是`false`如果这两种`x`并`y`是`true`或如果这两个`x`并`y`是`false`。 否则，结果为 `true`。 如果操作数均为类型`bool`，则`!=`运算符会产生相同的结果`^`运算符。

### 枚举的比较运算符

每个枚举类型隐式提供了以下预定义的比较运算符：

C#复制

```csharp
bool operator ==(E x, E y);
bool operator !=(E x, E y);
bool operator <(E x, E y);
bool operator >(E x, E y);
bool operator <=(E x, E y);
bool operator >=(E x, E y);
```

计算结果`x op y`，其中`x`并`y`是枚举类型的表达式`E`与基础类型`U`，并`op`为其中一个比较运算符，为完全相同评估`((U)x) op ((U)y)`。 换而言之，枚举类型比较运算符只需比较两个操作数的基础整数值。

### 引用类型相等运算符

预定义的引用类型的相等运算符为：

C#复制

```csharp
bool operator ==(object x, object y);
bool operator !=(object x, object y);
```

运算符将返回比较相等或不相等的两个引用的结果。

由于预定义的引用类型的相等运算符接受类型的操作数`object`，它们将应用于所有类型的未声明适用`operator ==`和`operator !=`成员。 相反，任何适用的用户定义的相等运算符有效地隐藏预定义的引用类型的相等运算符。

预定义的引用类型的相等运算符需要以下项之一：

- 这两个操作数都是已知类型的值*reference_type*或文本`null`。 此外，显式引用转换 ([显式引用转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#explicit-reference-conversions)) 存在从其中一个操作数的类型到另一个操作数的类型。
- 一个操作数的值为类型`T`其中`T`是*type_parameter*和另一个操作数为字面值`null`。 此外`T`不具有值类型约束。

除非以下条件之一为真，则绑定时间发生错误。 值得注意这些规则的含义是：

- 它是使用预定义的引用类型相等运算符比较两个已知可在绑定时不同的引用的绑定时错误。 例如，如果绑定时间类型的操作数是两个类类型`A`并`B`，和如果既没有`A`也不`B`派生另一个，然后它就不可能的两个操作数引用同一对象。 因此，该操作被视为绑定时错误。
- 预定义的引用类型的相等运算符不允许值类型操作数进行比较。 因此，除非将结构类型声明其自己的相等运算符，不能对该结构类型的值进行比较。
- 预定义的引用类型的相等运算符永远不会导致对其操作数执行装箱操作。 将无意义，若要执行此类装箱操作，因为对新分配的装箱实例必将区别于其他所有引用。
- 如果类型参数类型的操作数`T`进行比较的`null`，和的运行时类型`T`是值类型，比较的结果是`false`。

下面的示例检查不受约束的类型参数类型的自变量是否`null`。

C#复制

```csharp
class C<T>
{
    void F(T x) {
        if (x == null) throw new ArgumentNullException();
        ...
    }
}
```

`x == null`即使允许构造`T`可表示值类型，且结果只需定义`false`时`T`是值类型。

有关操作的窗体`x == y`或`x != y`，如果任何适用`operator ==`或`operator !=`存在，运算符重载解析 ([二元运算符重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#binary-operator-overload-resolution)) 规则将选择的运算符而不是预定义的引用类型的相等运算符。 但是，则始终可以选择预定义的引用类型的相等运算符通过一个或两个操作数类型显式转换`object`。 该示例

C#复制

```csharp
using System;

class Test
{
    static void Main() {
        string s = "Test";
        string t = string.Copy(s);
        Console.WriteLine(s == t);
        Console.WriteLine((object)s == t);
        Console.WriteLine(s == (object)t);
        Console.WriteLine((object)s == (object)t);
    }
}
```

生成输出

复制

```
True
False
False
False
```

`s`并`t`变量引用两个不同`string`实例包含相同字符。 第一次比较输出`True`因为预定义的字符串相等运算符 ([字符串是否相等运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#string-equality-operators)) 时这两个操作数均为类型选择`string`。 输出所有其余的比较`False`因为一个或两个操作数属于类型时选择预定义的引用类型的相等运算符`object`。

请注意，上面的技术不是对值类型有意义。 该示例

C#复制

```csharp
class Test
{
    static void Main() {
        int i = 123;
        int j = 123;
        System.Console.WriteLine((object)i == (object)j);
    }
}
```

输出`False`由于强制转换创建的两个单独实例的引用，因此装箱`int`值。

### 字符串相等运算符

预定义的字符串相等运算符为：

C#复制

```csharp
bool operator ==(string x, string y);
bool operator !=(string x, string y);
```

两个`string`值被视为相等，以下项之一为 true 时：

- 两个值均`null`。
- 这两个值是对每个字符位置中具有相同长度和字符的字符串实例的非 null 引用。

字符串相等运算符比较字符串值而不是字符串的引用。 当两个单独的字符串实例包含完全相同的字符序列时，字符串的值相等，但不同的引用。 如中所述[引用类型相等运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#reference-type-equality-operators)，引用类型的相等运算符可用于比较字符串引用而不是字符串值。

### 委托相等运算符

每个委托类型隐式提供了以下预定义的比较运算符：

C#复制

```csharp
bool operator ==(System.Delegate x, System.Delegate y);
bool operator !=(System.Delegate x, System.Delegate y);
```

两个委托实例视为相等，如下所示：

- 如果委托实例之一`null`，它们是否相等的当且仅当两者都是`null`。
- 如果委托具有不同的运行时类型为永远不会相等。
- 如果这两个委托实例必须调用列表 ([委托声明](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/delegates#delegate-declarations))，当且仅当它们的调用列表相同的长度，并且其中一个的调用列表中每个条目是相等 （如定义如下），这些实例是否相等到顺序，请在对方的调用列表中的相应条目。

以下规则控制调用列表项的相等的性：

- 如果两个调用列表条目这两个都指向相同的静态方法然后条目相等。
- 如果两个调用列表条目这两个都指向相同的目标对象上的同一个非静态方法 （如引用相等运算符所定义） 条目相等。
- 从评估版在语义上完全相同的调用列表项生成*anonymous_method_expression*s 或*lambda_expression*与 （可能为空） 一组相同的捕获的外部变量允许 （但不是必需的） 实例相等。

### 相等运算符和 null

`==`并`!=`运算符允许一个操作数是值为 null 的类型和其他要`null`文字，即使没有预定义或用户定义运算符 （在未提升或提升窗体） 存在的操作。

对于使用某种形式的操作

C#复制

```csharp
x == null
null == x
x != null
null != x
```

其中`x`运算符重载决策时为 null 的类型的表达式 ([二元运算符重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#binary-operator-overload-resolution)) 无法找到适用的运算符，结果而是计算得出`HasValue`属性的`x`。 具体而言前, 两个窗体将转换成`!x.HasValue`，并最后两个窗体转换为`x.HasValue`。

### Is 运算符

`is`运算符用于动态检查对象的运行时类型是否与给定类型兼容。 操作的结果`E is T`，其中`E`是一个表达式和`T`是一种类型，是一个布尔值，该值指示是否`E`可以成功转换为类型`T`通过引用转换、 装箱转换或取消装箱转换。 类型参数都已替换为所有类型参数后，将按如下所示，计算该操作：

- 如果`E`是一个匿名函数，则发生编译时错误
- 如果`E`是方法组或`null`文字，如果类型`E`是引用类型或可以为 null 的类型和值的`E`是 null，则结果为 false。
- 否则，让`D`表示的动态类型`E`，如下所示：
  - 如果类型`E`是引用类型，`D`是引用的实例的运行时类型`E`。
  - 如果类型`E`为 null 的类型，`D`是该可以为 null 的类型的基础类型。
  - 如果类型`E`是不可以为 null 的值类型，`D`是一种`E`。
- 操作的结果取决于`D`和`T`，如下所示：
  - 如果`T`是引用类型，则结果为 true 如果`D`并`T`是相同的类型，如果`D`是引用类型，从的隐式引用转换`D`到`T`存在，或者如果`D`是值类型和装箱转换从`D`到`T`存在。
  - 如果`T`为 null 的类型，则结果为 true 如果`D`是基础类型`T`。
  - 如果`T`是不可以为 null 的值类型，则结果为 true 如果`D`和`T`属于同一类型。
  - 否则，结果为 false。

请注意，用户定义的转换，不考虑`is`运算符。

### As 运算符

`as`运算符用于将值显式转换为给定的引用类型或可以为 null 的类型。 与不同的强制转换表达式 ([强制转换表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#cast-expressions))，则`as`运算符永远不会引发异常。 相反，如果指定的转换不可能，生成的值是`null`。

在操作中的窗体`E as T`，`E`必须为的表达式和`T`必须是引用类型，已知为引用类型或为 null 的类型的类型参数。 此外，在至少一个以下必须为 true，否则会发生编译时错误：

- 标识 ([标识转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#identity-conversion))、 隐式可以为 null ([可以为 null 的隐式转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#implicit-nullable-conversions))，隐式引用 ([隐式引用转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#implicit-reference-conversions))，装箱 ([装箱转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#boxing-conversions))、 显式可以为 null ([可以为 null 的显式转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#explicit-nullable-conversions))，显式引用 ([显式引用转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#explicit-reference-conversions))，或取消装箱 ([取消装箱转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#unboxing-conversions)) 存在从转换`E`到`T`。
- 类型`E`或`T`是开放类型。
- `E` 是`null`文本。

如果编译时类型`E`不是`dynamic`，该操作`E as T`生成相同的结果

C#复制

```csharp
E is T ? (T)(E) : (T)null
```

不同的是 `E` 只计算一次。 编译器需要优化`E as T`执行一个有最多动态类型检查而不是上面的扩展权限隐含的两个动态类型检查。

如果编译时类型`E`是`dynamic`，与强制转换运算符不同`as`运算符未动态绑定 ([动态绑定](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#dynamic-binding))。 因此扩展在这种情况下是：

C#复制

```csharp
E is T ? (T)(object)(E) : (T)null
```

请注意某些转换，如用户定义的转换，不可能实现`as`运算符，并且应改为执行使用强制转换表达式。

在示例

C#复制

```csharp
class X
{

    public string F(object o) {
        return o as string;        // OK, string is a reference type
    }

    public T G<T>(object o) where T: Attribute {
        return o as T;             // Ok, T has a class constraint
    }

    public U H<U>(object o) {
        return o as U;             // Error, U is unconstrained 
    }
}
```

类型参数`T`的`G`已知为引用类型，因为它具有类约束。 类型参数`U`的`H`不但是; 因此使用`as`中的运算符`H`不允许的。

## 逻辑运算符

`&`， `^`，和`|`操作员称为逻辑运算符。

antlr复制

```antlr
and_expression
    : equality_expression
    | and_expression '&' equality_expression
    ;

exclusive_or_expression
    : and_expression
    | exclusive_or_expression '^' and_expression
    ;

inclusive_or_expression
    : exclusive_or_expression
    | inclusive_or_expression '|' exclusive_or_expression
    ;
```

如果一个逻辑运算符的操作数具有编译时类型`dynamic`，然后动态绑定表达式 ([动态绑定](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#dynamic-binding))。 在这种情况下该表达式的编译时类型是`dynamic`，如下所述的分辨率将发生在运行时使用这些具有编译时类型的操作数的运行时类型和`dynamic`。

有关操作的窗体`x op y`，其中`op`是一个逻辑运算符和重载决策 ([二元运算符重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#binary-operator-overload-resolution)) 应用以选择特定的运算符实现。 操作数都转换为所选运算符的参数类型和结果的类型是运算符的返回类型。

以下各节描述了预定义的逻辑运算符。

### 整数逻辑运算符

预定义的整数逻辑运算符为：

C#复制

```csharp
int operator &(int x, int y);
uint operator &(uint x, uint y);
long operator &(long x, long y);
ulong operator &(ulong x, ulong y);

int operator |(int x, int y);
uint operator |(uint x, uint y);
long operator |(long x, long y);
ulong operator |(ulong x, ulong y);

int operator ^(int x, int y);
uint operator ^(uint x, uint y);
long operator ^(long x, long y);
ulong operator ^(ulong x, ulong y);
```

`&`运算符计算的按位逻辑`AND`的两个操作数`|`运算符计算的按位逻辑`OR`的两个操作数和`^`运算符计算的按位逻辑异`OR`的两个操作数。 从这些操作可能不会出现任何溢出。

### 枚举逻辑运算符

每个枚举类型`E`隐式提供以下预定义的逻辑运算符：

C#复制

```csharp
E operator &(E x, E y);
E operator |(E x, E y);
E operator ^(E x, E y);
```

计算结果`x op y`，其中`x`并`y`是枚举类型的表达式`E`与基础类型`U`，并`op`是一个逻辑运算符，是完全相同评估`(E)((U)x op (U)y)`。 换而言之，枚举类型的逻辑运算符只需执行两个操作数的基础类型上的逻辑操作。

### 布尔逻辑运算符

预定义的布尔逻辑运算符为：

C#复制

```csharp
bool operator &(bool x, bool y);
bool operator |(bool x, bool y);
bool operator ^(bool x, bool y);
```

如果 `x` 和 `y` 都为 `true`，则 `x & y` 的结果为 `true`。 否则，结果为 `false`。

结果`x | y`是`true`如果任一`x`或`y`是`true`。 否则，结果为 `false`。

结果`x ^ y`是`true`如果`x`是`true`并`y`是`false`，或者`x`是`false`和`y`是`true`。 否则，结果为 `false`。如果操作数均为类型`bool`，则`^`运算符计算相同的结果`!=`运算符。

### 可以为 null 的布尔逻辑运算符

可以为 null 的布尔类型`bool?`可以表示三个值`true`， `false`，和`null`，它从概念上讲类似于用于在 SQL 中的布尔表达式的三个值类型。 若要确保生成的结果`&`并`|`运算符`bool?`操作数都与 SQL 的三值逻辑一致的提供以下预定义的运算符：

C#复制

```csharp
bool? operator &(bool? x, bool? y);
bool? operator |(bool? x, bool? y);
```

下表列出了这些运算符时针对所有值的组合所产生的结果`true`， `false`，和`null`。

| `x`     | `y`     | `x & y` | `x | y` |
| ------- | ------- | ------- | ------- |
| `true`  | `true`  | `true`  | `true`  |
| `true`  | `false` | `false` | `true`  |
| `true`  | `null`  | `null`  | `true`  |
| `false` | `true`  | `false` | `true`  |
| `false` | `false` | `false` | `false` |
| `false` | `null`  | `false` | `null`  |
| `null`  | `true`  | `null`  | `true`  |
| `null`  | `false` | `false` | `null`  |
| `null`  | `null`  | `null`  | `null`  |

## 条件逻辑运算符

`&&`和`||`操作员称为条件逻辑运算符。 它们也称为"短路"逻辑运算符。

antlr复制

```antlr
conditional_and_expression
    : inclusive_or_expression
    | conditional_and_expression '&&' inclusive_or_expression
    ;

conditional_or_expression
    : conditional_and_expression
    | conditional_or_expression '||' conditional_and_expression
    ;
```

`&&`并`||`运算符是条件新版`&`和`|`运算符：

- 该操作`x && y`对应于该操作`x & y`，只不过`y`才计算`x`不是`false`。
- 该操作`x || y`对应于该操作`x | y`，只不过`y`才计算`x`不是`true`。

如果条件的逻辑运算符的操作数具有编译时类型`dynamic`，然后动态绑定表达式 ([动态绑定](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#dynamic-binding))。 在这种情况下该表达式的编译时类型是`dynamic`，如下所述的分辨率将发生在运行时使用这些具有编译时类型的操作数的运行时类型和`dynamic`。

操作的窗体`x && y`或`x || y`处理通过应用重载解析 ([二元运算符重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#binary-operator-overload-resolution)) 编写该操作已`x & y`或`x | y`。 然后，

- 如果重载解决方法未能找到一个最佳运算符，或者如果重载决策选择其中一个预定义的整数逻辑运算符，会发生绑定时错误。
- 否则为如果所选的运算符是一个预定义的布尔逻辑运算符 ([布尔逻辑运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#boolean-logical-operators)) 或可以为 null 的布尔逻辑运算符 ([可以为 Null 的布尔逻辑运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#nullable-boolean-logical-operators))，则处理操作中所述[布尔条件逻辑运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#boolean-conditional-logical-operators)。
- 否则为所选的运算符是用户定义的运算符，该操作处理中所述[用户定义的条件逻辑运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#user-defined-conditional-logical-operators)。

不能直接重载条件逻辑运算符。 但是，因为按常规逻辑运算符计算条件逻辑运算符，重载常规逻辑运算符，在某些限制，也被视为条件逻辑运算符的重载。 这是中作了进一步介绍[用户定义的条件逻辑运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#user-defined-conditional-logical-operators)。

### 布尔条件逻辑运算符

时的操作数`&&`或`||`属于类型`bool`，或未定义适用的类型的操作数时`operator &`或`operator |`，但定义隐式转换为`bool`，操作处理，如下所示：

- 该操作`x && y`评为`x ? y : false`。 换而言之，`x`首先计算并将转换为类型`bool`。 然后，如果`x`是`true`，`y`进行计算并转换为类型`bool`，这将成为该操作的结果。 否则，该操作的结果是`false`。
- 该操作`x || y`评为`x ? true : y`。 换而言之，`x`首先计算并将转换为类型`bool`。 然后，如果`x`是`true`，该操作的结果是`true`。 否则为`y`进行计算并转换为类型`bool`，这将成为该操作的结果。

### 用户定义的条件逻辑运算符

时的操作数`&&`或`||`是声明适用的类型的用户定义`operator &`或`operator |`，下列两个条件必须为 true，其中`T`是在其中声明所选的运算符的类型：

- 返回类型和所选运算符的每个参数的类型必须是`T`。 换而言之，操作员必须计算逻辑`AND`或逻辑`OR`的类型的两个操作数`T`，并且必须返回类型的结果`T`。
- `T` 必须包含的声明`operator true`和`operator false`。

如果不满足任一要求，则会发生绑定时错误。 否则为`&&`或`||`通过组合用户定义运算`operator true`或`operator false`与所选用户定义的运算符：

- 该操作`x && y`评为`T.false(x) ? x : T.&(x, y)`，其中`T.false(x)`的调用`operator false`中声明`T`，和`T.&(x, y)`的所选调用`operator &`。 换而言之，`x`首先计算并`operator false`结果可确定是否调用`x`肯定为假。 然后，如果`x`肯定为假，该操作的结果是为以前计算的值`x`。 否则为`y`计算时，并且所选`operator &`为以前计算的值上调用`x`的计算值和`y`生成操作的结果。
- 该操作`x || y`评为`T.true(x) ? x : T.|(x, y)`，其中`T.true(x)`的调用`operator true`中声明`T`，和`T.|(x,y)`的所选调用`operator|`。 换而言之，`x`首先计算并`operator true`结果可确定是否调用`x`肯定为真。 然后，如果`x`则肯定会这样，该操作的结果是为以前计算的值`x`。 否则为`y`计算时，并且所选`operator |`为以前计算的值上调用`x`的计算值和`y`生成操作的结果。

这些操作，提供的表达式之一`x`是只计算一次，并由给定的表达式`y`或者不在评估或仅计算一次。

有关实现的类型的示例`operator true`并`operator false`，请参阅[数据库布尔类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/structs#database-boolean-type)。

## Null 合并运算符

`??`运算符称作 null 合并运算符。

antlr复制

```antlr
null_coalescing_expression
    : conditional_or_expression
    | conditional_or_expression '??' null_coalescing_expression
    ;
```

在窗体 null 合并表达式`a ?? b`需要`a`为可以为 null 的类型或引用类型。 如果`a`为非 null 的结果`a ?? b`是`a`; 否则为结果是`b`。 操作会评估`b`仅当`a`为 null。

Null 合并运算符是右结合运算符，这意味着操作将从右到左分组。 例如，窗体的表达式`a ?? b ?? c`评为`a ?? (b ?? c)`。 一般情况下条款形式的表达式`E1 ?? E2 ?? ... ?? En`返回第一个操作数的非 null 或为 null，如果所有操作数都都为 null。

表达式的类型`a ?? b`取决于哪个隐式转换都可通过对操作数。 首选项的类型的顺序`a ?? b`是`A0`， `A`，或`B`，其中`A`是一种`a`(前提是`a`具有类型)，`B`是一种`b`(前提`b`有一个类型)，并`A0`是基础类型`A`如果`A`是一个可以为 null 的类型，或`A`否则为。 具体而言，`a ?? b`进行处理，如下所示：

- 如果`A`存在且不为 null 的类型或引用类型，将发生编译时错误。
- 如果`b`是一个动态表达式的结果类型是`dynamic`。 在运行时`a`首先计算。 如果`a`不为 null，`a`转换为动态，这将成为结果。 否则为`b`计算时，这将成为结果。
- 否则为如果`A`存在和为 null 的类型和隐式转换`b`到`A0`，该结果类型是`A0`。 在运行时`a`首先计算。 如果`a`不为 null，`a`解包为类型`A0`，这将成为结果。 否则为`b`进行计算并转换为类型`A0`，这将成为结果。
- 否则为如果`A`存在并且存在一个隐式转换从`b`到`A`，该结果类型是`A`。 在运行时`a`首先计算。 如果`a`不为 null，`a`使其成为结果。 否则为`b`进行计算并转换为类型`A`，这将成为结果。
- 否则为如果`b`具有类型`B`并且从存在的隐式转换`a`到`B`，结果类型是`B`。 在运行时`a`首先计算。 如果`a`不为 null，`a`解包为类型`A0`(如果`A`是否存在以及是否可以为 null) 和转换为键入`B`，这将成为结果。 否则为`b`计算，并使其成为结果。
- 否则为`a`和`b`是不兼容，并且编译时错误发生。

## 条件运算符

`?:`调用条件运算符的运算符。 它有时也称为三元运算符。

antlr复制

```antlr
conditional_expression
    : null_coalescing_expression
    | null_coalescing_expression '?' expression ':' expression
    ;
```

形式的条件表达式`b ? x : y`先计算条件`b`。 然后，如果`b`是`true`，`x`计算，并使其成为操作的结果。 否则为`y`计算，并使其成为操作的结果。 条件的表达式永远不会计算这两`x`和`y`。

条件运算符是右结合运算符，这意味着操作将从右到左分组。 例如，窗体的表达式`a ? b : c ? d : e`评为`a ? b : (c ? d : e)`。

第一个操作数`?:`运算符必须可以隐式转换为的表达式`bool`，或实现的类型的表达式`operator true`。 如果满足这些要求都不会发生编译时错误。

第二个和第三个操作数，`x`并`y`的`?:`运算符控制条件表达式的类型。

- 如果`x`具有类型`X`并`y`具有类型`Y`然后
  - 如果隐式转换 ([隐式转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#implicit-conversions)) 中存在`X`到`Y`，但不能从`Y`到`X`，然后`Y`是条件表达式的类型。
  - 如果隐式转换 ([隐式转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#implicit-conversions)) 中存在`Y`到`X`，但不能从`X`到`Y`，然后`X`是条件表达式的类型。
  - 否则为可以确定任何表达式类型，并将发生编译时错误。
- 如果只有之一`x`并`y`具有一个类型，并且两个`x`和`y`的是隐式转换为该类型，那么它就是条件表达式的类型。
- 否则为可以确定任何表达式类型，并将发生编译时错误。

处理窗体的条件表达式的运行时间`b ? x : y`包括以下步骤：

- 首先，`b`计算，并`bool`的值`b`确定：
  - 如果从的类型的隐式转换`b`到`bool`存在，则执行此隐式转换以生成`bool`值。
  - 否则为`operator true`的类型由定义`b`调用，以生成`bool`值。
- 如果`bool`由上述步骤生成的值是`true`，然后`x`是计算并转换为的类型的条件表达式，这将成为条件表达式的结果。
- 否则为`y`是计算并转换为的类型的条件表达式，这将成为条件表达式的结果。

## 匿名函数表达式

***匿名函数***一个表达式，表示"行中"方法定义。 匿名函数没有值或类型本身，但转换为兼容的委托或表达式树类型。 匿名函数转换的计算取决于转换的目标类型：如果它是委托类型，转换计算结果为引用它的匿名函数定义的方法的委托值。 如果表达式目录树类型，转换计算结果为表达式树表示形式的对象结构的方法的结构。

由于历史原因有两种语法类型的匿名函数，即*lambda_expression*s 和*anonymous_method_expression*s。 对于几乎所有目的*lambda_expression*是更简洁、 更具表现力比*anonymous_method_expression*s，保留的语言为向后兼容性。

antlr复制

```antlr
lambda_expression
    : anonymous_function_signature '=>' anonymous_function_body
    ;

anonymous_method_expression
    : 'delegate' explicit_anonymous_function_signature? block
    ;

anonymous_function_signature
    : explicit_anonymous_function_signature
    | implicit_anonymous_function_signature
    ;

explicit_anonymous_function_signature
    : '(' explicit_anonymous_function_parameter_list? ')'
    ;

explicit_anonymous_function_parameter_list
    : explicit_anonymous_function_parameter (',' explicit_anonymous_function_parameter)*
    ;

explicit_anonymous_function_parameter
    : anonymous_function_parameter_modifier? type identifier
    ;

anonymous_function_parameter_modifier
    : 'ref'
    | 'out'
    ;

implicit_anonymous_function_signature
    : '(' implicit_anonymous_function_parameter_list? ')'
    | implicit_anonymous_function_parameter
    ;

implicit_anonymous_function_parameter_list
    : implicit_anonymous_function_parameter (',' implicit_anonymous_function_parameter)*
    ;

implicit_anonymous_function_parameter
    : identifier
    ;

anonymous_function_body
    : expression
    | block
    ;
```

`=>`运算符具有与赋值相同的优先级 (`=`) 并且是右结合运算符。

使用匿名函数`async`修饰符是异步函数，并遵循中所述的规则[迭代器](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#iterators)。

中的窗体的匿名函数的参数*lambda_expression*可以显式或隐式类型化。 在显式类型化的参数列表中，显式声明每个参数的类型。 在隐式类型化的参数列表中，参数的类型推断匿名函数的上下文从 — 具体来说，匿名函数转换为兼容的委托类型或类型提供的表达式目录树类型参数类型 ([匿名函数转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#anonymous-function-conversions))。

在单一、 隐式类型化参数使用一个匿名函数，则可能会省略括号从参数列表。 换而言之，窗体的匿名函数

C#复制

```csharp
( param ) => expr
```

可缩写为

C#复制

```csharp
param => expr
```

中的窗体的匿名函数的参数列表*anonymous_method_expression*是可选的。 如果指定，则必须显式键入参数。 如果不是，匿名函数转换为一个委托，其任何参数列表不包含`out`参数。

一个*块*匿名函数的主体是可访问 ([终结点和可访问性](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/statements#end-points-and-reachability)) 除非匿名函数发生在无法访问语句内。

下面是匿名函数的一些示例：

C#复制

```csharp
x => x + 1                              // Implicitly typed, expression body
x => { return x + 1; }                  // Implicitly typed, statement body
(int x) => x + 1                        // Explicitly typed, expression body
(int x) => { return x + 1; }            // Explicitly typed, statement body
(x, y) => x * y                         // Multiple parameters
() => Console.WriteLine()               // No parameters
async (t1,t2) => await t1 + await t2    // Async
delegate (int x) { return x + 1; }      // Anonymous method expression
delegate { return 1 + 1; }              // Parameter list omitted
```

行为*lambda_expression*s 和*anonymous_method_expression*s 是除以下几点：

- *anonymous_method_expression*s 允许要完全，省略的参数列表生成可转换为委托类型的任何值参数的列表。
- *lambda_expression*s 允许省略和而这方面的推断参数类型*anonymous_method_expression*需要显式指定的参数类型。
- 正文*lambda_expression*可以是表达式或语句块而正文*anonymous_method_expression*必须是语句块。
- 仅*lambda_expression*具有到兼容的表达式树类型的转换 ([表达式树类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/types#expression-tree-types))。

### 匿名函数签名

可选*anonymous_function_signature*匿名函数的定义名称和 （可选） 的匿名函数的形参的类型。 匿名函数的参数的范围是*anonymous_function_body*。 ([作用域](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/basic-concepts#scopes)) 参数列表 （如果已指定） 一起构成了匿名方法体，声明空间 ([声明](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/basic-concepts#declarations))。 因此是要与本地变量、 局部常量或其作用域包括的参数的名称匹配的匿名函数的参数的名称的编译时错误*anonymous_method_expression*或*lambda_表达式*。

如果具有一个匿名函数*explicit_anonymous_function_signature*，则限制为那些相同的顺序中具有相同参数类型和修饰符的兼容的委托类型和表达式树类型集。 与方法组转换相反 ([方法组转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#method-group-conversions))，不支持匿名函数参数类型的逆变。 如果匿名函数不具有*anonymous_function_signature*，则限制为那些没有兼容的委托类型和表达式树类型的集`out`参数。

请注意， *anonymous_function_signature*不能包含属性或参数数组。 不过， *anonymous_function_signature*可能用其参数列表包含参数数组的委托类型兼容。

另请注意该转换为表达式树类型，即使兼容，可能仍会在编译时失败 ([表达式树类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/types#expression-tree-types))。

### 匿名函数体

正文 (*表达式*或*块*) 的匿名函数时要遵循以下规则：

- 如果匿名函数包含签名，签名中指定的参数提供了在正文。 如果匿名函数没有签名它可转换为委托类型或具有参数的表达式类型 ([匿名函数转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#anonymous-function-conversions))，但参数不能访问正文中。
- 除`ref`或`out`最近的封闭的签名 （如果有） 中指定的参数匿名函数，它是要访问的正文的编译时错误`ref`或`out`参数。
- 时的类型`this`是一个结构类型，它是要访问的正文的编译时错误`this`。 这是 true 的访问是否是显式 (如`this.x`) 或隐式 (如`x`其中`x`是结构的一个实例成员)。 此规则只需禁止此类访问权限并不会影响是否成员查找导致该结构的成员。
- 正文有权访问的外部变量 ([外部变量](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#outer-variables)) 的匿名函数。 外部变量的访问将引用的变量时处于活动状态的实例*lambda_expression*或*anonymous_method_expression*计算 ([的评估匿名函数表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#evaluation-of-anonymous-function-expressions))。
- 它是正文中所含的编译时错误`goto`语句中，`break`语句，或`continue`其目标为表体外部或包含匿名函数主体内的语句。
- 一个`return`在正文中的语句将控制权返回从最近的封闭的调用不是来自封闭函数成员的匿名函数。 中指定的表达式`return`语句必须是隐式转换为委托类型或为表达式树类型的返回类型的最近的封闭*lambda_expression*或*anonymous_method_expression*转换 ([匿名函数转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#anonymous-function-conversions))。

是否没有任何方法来执行通过评估和调用的匿名函数以外的其他块没有显式指定*lambda_expression*或*anonymous_method_expression*. 具体而言，编译器可以选择实现一个匿名函数，通过合成一个或多个命名方法或类型。 合成的任何此类元素的名称必须是保留供编译器使用的窗体。

### 重载决策和匿名函数

参数列表中的匿名函数参与类型推理和重载决策。 请参阅[类型推理](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#type-inference)并[重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#overload-resolution)的确切规则。

下面的示例说明了匿名函数对重载决策的影响。

C#复制

```csharp
class ItemList<T>: List<T>
{
    public int Sum(Func<T,int> selector) {
        int sum = 0;
        foreach (T item in this) sum += selector(item);
        return sum;
    }

    public double Sum(Func<T,double> selector) {
        double sum = 0;
        foreach (T item in this) sum += selector(item);
        return sum;
    }
}
```

`ItemList<T>`类具有两个`Sum`方法。 每个都采用`selector`参数，从提取的值为 sum 通过列表项。 提取的值可以是`int`或`double`并将生成的和为同样`int`或`double`。

`Sum`方法为例无法用于计算的详细信息行的顺序从列表的总和。

C#复制

```csharp
class Detail
{
    public int UnitCount;
    public double UnitPrice;
    ...
}

void ComputeSums() {
    ItemList<Detail> orderDetails = GetOrderDetails(...);
    int totalUnits = orderDetails.Sum(d => d.UnitCount);
    double orderTotal = orderDetails.Sum(d => d.UnitPrice * d.UnitCount);
    ...
}
```

中的第一个调用`orderDetails.Sum`，这两个`Sum`方法都适用因为匿名函数`d => d. UnitCount`两个兼容`Func<Detail,int>`和`Func<Detail,double>`。 不过，重载决策会选取第一个`Sum`方法因为转换`Func<Detail,int>`转换为更好`Func<Detail,double>`。

在第二个调用中`orderDetails.Sum`，仅第二`Sum`方法是适用因为匿名函数`d => d.UnitPrice * d.UnitCount`产生的值的类型`double`。 因此，重载解析选取第二个`Sum`对于该调用的方法。

### 匿名函数和动态绑定

接收方、 参数或动态绑定运算的操作数，不能为匿名函数。

### 外部变量

任何本地变量、 值参数或其作用域包括参数数组*lambda_expression*或*anonymous_method_expression*称为***外部变量***匿名函数。 中的一个类，实例函数成员`this`值被视为值参数，并且函数成员内包含任何匿名函数的外部变量。

#### 捕获的外部变量

当匿名函数引用的外部变量时，则称外部变量已被***捕获***匿名函数。 通常，本地变量的生存期仅限于执行块或与之关联的语句 ([局部变量](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/variables#local-variables))。 但是，捕获的外部变量的生存期至少延期到委托或表达式树中创建的匿名函数变得可以进行垃圾回收。

在示例

C#复制

```csharp
using System;

delegate int D();

class Test
{
    static D F() {
        int x = 0;
        D result = () => ++x;
        return result;
    }

    static void Main() {
        D d = F();
        Console.WriteLine(d());
        Console.WriteLine(d());
        Console.WriteLine(d());
    }
}
```

本地变量`x`捕获的匿名函数和的生命周期`x`至少从返回的委托扩展`F`变得垃圾回收 （这不会发生的最后才符合条件程序）。 由于匿名函数的每个调用对在同一个实例`x`，该示例的输出是：

复制

```
1
2
3
```

当匿名函数捕获本地变量或值参数时，局部变量或参数被不再视为可为固定的变量 ([固定和可移动变量](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/unsafe-code#fixed-and-moveable-variables))，而是被视为可可移动但变量。 因此任何`unsafe`代码，用来捕获的外部变量的地址必须首先使用`fixed`固定该变量的语句。

请注意，与 uncaptured 变量不同，可以向多个执行线程同时公开捕获本地变量。

#### 本地变量的实例化

本地变量被视为***实例化***时执行进入变量的作用域。 例如，以下方法调用时，本地变量`x`进行实例化和初始化三次，每个迭代的循环一次。

C#复制

```csharp
static void F() {
    for (int i = 0; i < 3; i++) {
        int x = i * 2 + 1;
        ...
    }
}
```

但是，移动的声明`x`之外的单一实例化此循环导致`x`:

C#复制

```csharp
static void F() {
    int x;
    for (int i = 0; i < 3; i++) {
        x = i * 2 + 1;
        ...
    }
}
```

时不会捕获，没有方法来观察完全何种频率进行实例化本地变量，因为实例化生存期是连续的就可以为每个实例化，只需使用相同的存储位置。 但是，当一个匿名函数捕获本地变量时，实例化的效果很明显。

该示例

C#复制

```csharp
using System;

delegate void D();

class Test
{
    static D[] F() {
        D[] result = new D[3];
        for (int i = 0; i < 3; i++) {
            int x = i * 2 + 1;
            result[i] = () => { Console.WriteLine(x); };
        }
        return result;
    }

    static void Main() {
        foreach (D d in F()) d();
    }
}
```

生成输出：

复制

```
1
3
5
```

但是，当声明`x`移出循环：

C#复制

```csharp
static D[] F() {
    D[] result = new D[3];
    int x;
    for (int i = 0; i < 3; i++) {
        x = i * 2 + 1;
        result[i] = () => { Console.WriteLine(x); };
    }
    return result;
}
```

输出为：

复制

```
5
5
5
```

如果 for 循环中声明的迭代变量，该变量本身是被视为位于循环外声明。 因此，如果该示例更改要捕获的迭代变量本身：

C#复制

```csharp
static D[] F() {
    D[] result = new D[3];
    for (int i = 0; i < 3; i++) {
        result[i] = () => { Console.WriteLine(i); };
    }
    return result;
}
```

捕获的迭代变量只有一个实例，这会生成输出：

复制

```
3
3
3
```

它是匿名函数委托可共享一些捕获的变量，但是又有其他人的单独实例。 例如，如果`F`更改为

C#复制

```csharp
static D[] F() {
    D[] result = new D[3];
    int x = 0;
    for (int i = 0; i < 3; i++) {
        int y = 0;
        result[i] = () => { Console.WriteLine("{0} {1}", ++x, ++y); };
    }
    return result;
}
```

三个委托捕获的同一个实例`x`但的单个实例`y`，而输出是：

复制

```
1 1
2 1
3 1
```

单独的匿名函数可以捕获一个外部变量的同一个实例。 在下面的示例中：

C#复制

```csharp
using System;

delegate void Setter(int value);

delegate int Getter();

class Test
{
    static void Main() {
        int x = 0;
        Setter s = (int value) => { x = value; };
        Getter g = () => { return x; };
        s(5);
        Console.WriteLine(g());
        s(10);
        Console.WriteLine(g());
    }
}
```

两个匿名函数捕获本地变量的同一实例`x`，并且它们可以因此"通信"通过该变量。 该示例的输出是：

复制

```
5
10
```

### 匿名函数表达式的计算

匿名函数`F`必须始终转换为委托类型`D`或表达式树类型`E`，直接或通过执行委托创建表达式`new D(F)`。 此转换确定的匿名函数的结果，如中所述[匿名函数转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#anonymous-function-conversions)。

## 查询表达式

***查询表达式***提供语言集成语法的查询，类似于关系和层次查询语言，如 SQL 和 XQuery。

antlr复制

```antlr
query_expression
    : from_clause query_body
    ;

from_clause
    : 'from' type? identifier 'in' expression
    ;

query_body
    : query_body_clauses? select_or_group_clause query_continuation?
    ;

query_body_clauses
    : query_body_clause
    | query_body_clauses query_body_clause
    ;

query_body_clause
    : from_clause
    | let_clause
    | where_clause
    | join_clause
    | join_into_clause
    | orderby_clause
    ;

let_clause
    : 'let' identifier '=' expression
    ;

where_clause
    : 'where' boolean_expression
    ;

join_clause
    : 'join' type? identifier 'in' expression 'on' expression 'equals' expression
    ;

join_into_clause
    : 'join' type? identifier 'in' expression 'on' expression 'equals' expression 'into' identifier
    ;

orderby_clause
    : 'orderby' orderings
    ;

orderings
    : ordering (',' ordering)*
    ;

ordering
    : expression ordering_direction?
    ;

ordering_direction
    : 'ascending'
    | 'descending'
    ;

select_or_group_clause
    : select_clause
    | group_clause
    ;

select_clause
    : 'select' expression
    ;

group_clause
    : 'group' expression 'by' expression
    ;

query_continuation
    : 'into' identifier query_body
    ;
```

查询表达式开头`from`子句和任一结尾`select`或`group`子句。 初始`from`子句可以后跟零个或多`from`， `let`， `where`，`join`或`orderby`子句。 每个`from`子句是一个生成器简介***范围变量***的元素范围***序列***。 每个`let`子句引入范围变量表示计算通过之前的范围变量的值。 每个`where`子句是从结果中排除项的筛选器。 每个`join`子句将指定的源序列中的另一个序列，无法完成匹配对的键的键进行比较。 每个`orderby`子句会根据指定条件的项进行重新排序。最终`select`或`group`子句指定结果的范围变量的形状。 最后，`into`子句可用于"接合"查询通过将视为一个生成器的后续查询中的一个查询的结果。

### 在查询表达式中的多义性

查询表达式包含大量的"上下文关键字"，即，在给定上下文中具有特殊含义的标识符。 特别是这些`from`， `where`， `join`， `on`， `equals`， `into`， `let`， `orderby`， `ascending`， `descending`， `select`，`group`和`by`. 为了避免在为关键字或简单名称引起混合使用这些标识符的查询表达式中的多义性，这些标识符被视为关键字时查询表达式中任何位置发生。

为此，查询表达式是开头的任何表达式"`from identifier`"后跟除外的任何令牌"`;`"，"`=`"或"`,`"。

若要使用这些字作为标识符中的查询表达式，它们可以前缀为"`@`"([标识符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/lexical-structure#identifiers))。

### 在查询表达式转换

C# 语言不会指定查询表达式的执行语义。 相反，查询表达式转换为调用的方法的遵守*查询表达式模式*([查询表达式模式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#the-query-expression-pattern))。 具体而言，查询表达式转换为调用的方法名为`Where`， `Select`， `SelectMany`， `Join`， `GroupJoin`， `OrderBy`， `OrderByDescending`， `ThenBy`， `ThenByDescending`， `GroupBy`，和`Cast`。这些方法应具有特定签名和结果类型，如中所述[查询表达式模式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#the-query-expression-pattern)。 这些方法可以是正在查询的对象的实例方法或外部的对象的扩展方法，实现实际执行查询。

从查询表达式转换为方法调用是任何类型绑定之前发生的语法映射或已执行重载决策。 翻译保证语法正确，但不是保证能够产生在语义上是正确的 C# 代码。 查询表达式的转换时，生成的方法调用处理为正则方法调用，且这又可能会发现错误，例如，如果方法不存在，如果自变量具有错误类型，或如果方法是泛型和类型推理失败。

查询表达式由重复应用以下转换，直到没有更多降低是两个可能进行处理。 翻译中应用程序的顺序列出： 每个部分假定已彻底，执行前面部分中的翻译并后已用完，一个部分将不更高版本再次讨论在处理同一个查询表达式。

查询表达式中不允许的范围变量赋值。 但是允许的 C# 实现并非始终强制执行这种限制，因为这有时不可能与此处介绍的在语法上转换方案。

某些转换为由透明标识符将插入的范围变量`*`。 透明标识符的特殊属性进行讨论中进一步[透明标识符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#transparent-identifiers)。

#### 使用继续符的选择和 groupby 子句

查询表达式中使用继续符

C#复制

```csharp
from ... into x ...
```

转换为

C#复制

```csharp
from x in ( from ... ) ...
```

以下各节中的翻译假定查询没有任何`into`继续符。

该示例

C#复制

```csharp
from c in customers
group c by c.Country into g
select new { Country = g.Key, CustCount = g.Count() }
```

转换为

C#复制

```csharp
from g in
    from c in customers
    group c by c.Country
select new { Country = g.Key, CustCount = g.Count() }
```

最后一个转换是

C#复制

```csharp
customers.
GroupBy(c => c.Country).
Select(g => new { Country = g.Key, CustCount = g.Count() })
```

#### 显式范围变量类型

一个`from`子句显式指定范围变量类型

C#复制

```csharp
from T x in e
```

转换为

C#复制

```csharp
from x in ( e ) . Cast < T > ( )
```

一个`join`子句显式指定范围变量类型

复制

```
join T x in e on k1 equals k2
```

转换为

复制

```
join x in ( e ) . Cast < T > ( ) on k1 equals k2
```

以下各节中的翻译假定查询有无显式范围变量的类型。

该示例

C#复制

```csharp
from Customer c in customers
where c.City == "London"
select c
```

转换为

C#复制

```csharp
from c in customers.Cast<Customer>()
where c.City == "London"
select c
```

最后一个转换是

C#复制

```csharp
customers.
Cast<Customer>().
Where(c => c.City == "London")
```

显式范围变量的类型可用于查询实现非泛型的集合`IEnumerable`接口，但不是通用`IEnumerable<T>`接口。 在上面的示例中，这是如果`customers`类型的`ArrayList`。

#### 退化的查询表达式

查询表达式中的窗体

C#复制

```csharp
from x in e select x
```

转换为

C#复制

```csharp
( e ) . Select ( x => x )
```

该示例

C#复制

```csharp
from c in customers
select c
```

转换为

C#复制

```csharp
customers.Select(c => c)
```

退化的查询表达式是指不费力地选择源的元素。 翻译的后面的阶段中删除引入的其他转换步骤通过将替换其源的退化查询。 它很重要，确保查询的结果表达式是永远不会是源对象本身，但因为的到客户端的查询显示的类型和源的标识。 因此，此步骤保护退化通过显式调用编写直接在源代码中的查询`Select`源上。 这样，它将最多的实施者`Select`和其他查询运算符，以确保这些方法永远不会返回的源对象本身。

#### From、 let、 where、 join 和 orderby 子句

与第二个查询表达式`from`子句跟`select`子句

C#复制

```csharp
from x1 in e1
from x2 in e2
select v
```

转换为

C#复制

```csharp
( e1 ) . SelectMany( x1 => e2 , ( x1 , x2 ) => v )
```

与第二个查询表达式`from`子句而不遵循由`select`子句：

C#复制

```csharp
from x1 in e1
from x2 in e2
...
```

转换为

C#复制

```csharp
from * in ( e1 ) . SelectMany( x1 => e2 , ( x1 , x2 ) => new { x1 , x2 } )
...
```

查询表达式与`let`子句

C#复制

```csharp
from x in e
let y = f
...
```

转换为

C#复制

```csharp
from * in ( e ) . Select ( x => new { x , y = f } )
...
```

查询表达式与`where`子句

C#复制

```csharp
from x in e
where f
...
```

转换为

C#复制

```csharp
from x in ( e ) . Where ( x => f )
...
```

使用查询表达式`join`子句而无需`into`跟`select`子句

C#复制

```csharp
from x1 in e1
join x2 in e2 on k1 equals k2
select v
```

转换为

C#复制

```csharp
( e1 ) . Join( e2 , x1 => k1 , x2 => k2 , ( x1 , x2 ) => v )
```

使用查询表达式`join`子句而无需`into`而不遵循由`select`子句

C#复制

```csharp
from x1 in e1
join x2 in e2 on k1 equals k2
...
```

转换为

C#复制

```csharp
from * in ( e1 ) . Join( e2 , x1 => k1 , x2 => k2 , ( x1 , x2 ) => new { x1 , x2 })
...
```

使用查询表达式`join`子句`into`跟`select`子句

C#复制

```csharp
from x1 in e1
join x2 in e2 on k1 equals k2 into g
select v
```

转换为

C#复制

```csharp
( e1 ) . GroupJoin( e2 , x1 => k1 , x2 => k2 , ( x1 , g ) => v )
```

使用查询表达式`join`子句`into`而不遵循由`select`子句

C#复制

```csharp
from x1 in e1
join x2 in e2 on k1 equals k2 into g
...
```

转换为

C#复制

```csharp
from * in ( e1 ) . GroupJoin( e2 , x1 => k1 , x2 => k2 , ( x1 , g ) => new { x1 , g })
...
```

查询表达式与`orderby`子句

C#复制

```csharp
from x in e
orderby k1 , k2 , ..., kn
...
```

转换为

C#复制

```csharp
from x in ( e ) . 
OrderBy ( x => k1 ) . 
ThenBy ( x => k2 ) .
... .
ThenBy ( x => kn )
...
```

如果进行的排序子句指定`descending`方向指示器中，调用`OrderByDescending`或`ThenByDescending`改为生成。

下面的翻译假定没有任何`let`， `where`，`join`或`orderby`子句，并且不能超过一个初始`from`中每个查询表达式子句。

该示例

C#复制

```csharp
from c in customers
from o in c.Orders
select new { c.Name, o.OrderID, o.Total }
```

转换为

C#复制

```csharp
customers.
SelectMany(c => c.Orders,
     (c,o) => new { c.Name, o.OrderID, o.Total }
)
```

该示例

C#复制

```csharp
from c in customers
from o in c.Orders
orderby o.Total descending
select new { c.Name, o.OrderID, o.Total }
```

转换为

C#复制

```csharp
from * in customers.
    SelectMany(c => c.Orders, (c,o) => new { c, o })
orderby o.Total descending
select new { c.Name, o.OrderID, o.Total }
```

最后一个转换是

C#复制

```csharp
customers.
SelectMany(c => c.Orders, (c,o) => new { c, o }).
OrderByDescending(x => x.o.Total).
Select(x => new { x.c.Name, x.o.OrderID, x.o.Total })
```

其中`x`是编译器生成的标识符，否则是不可见且不可访问。

该示例

C#复制

```csharp
from o in orders
let t = o.Details.Sum(d => d.UnitPrice * d.Quantity)
where t >= 1000
select new { o.OrderID, Total = t }
```

转换为

C#复制

```csharp
from * in orders.
    Select(o => new { o, t = o.Details.Sum(d => d.UnitPrice * d.Quantity) })
where t >= 1000 
select new { o.OrderID, Total = t }
```

最后一个转换是

C#复制

```csharp
orders.
Select(o => new { o, t = o.Details.Sum(d => d.UnitPrice * d.Quantity) }).
Where(x => x.t >= 1000).
Select(x => new { x.o.OrderID, Total = x.t })
```

其中`x`是编译器生成的标识符，否则是不可见且不可访问。

该示例

C#复制

```csharp
from c in customers
join o in orders on c.CustomerID equals o.CustomerID
select new { c.Name, o.OrderDate, o.Total }
```

转换为

C#复制

```csharp
customers.Join(orders, c => c.CustomerID, o => o.CustomerID,
    (c, o) => new { c.Name, o.OrderDate, o.Total })
```

该示例

C#复制

```csharp
from c in customers
join o in orders on c.CustomerID equals o.CustomerID into co
let n = co.Count()
where n >= 10
select new { c.Name, OrderCount = n }
```

转换为

C#复制

```csharp
from * in customers.
    GroupJoin(orders, c => c.CustomerID, o => o.CustomerID,
        (c, co) => new { c, co })
let n = co.Count()
where n >= 10 
select new { c.Name, OrderCount = n }
```

最后一个转换是

C#复制

```csharp
customers.
GroupJoin(orders, c => c.CustomerID, o => o.CustomerID,
    (c, co) => new { c, co }).
Select(x => new { x, n = x.co.Count() }).
Where(y => y.n >= 10).
Select(y => new { y.x.c.Name, OrderCount = y.n)
```

其中`x`和`y`是编译器生成的标识符，否则是不可见且不可访问。

该示例

C#复制

```csharp
from o in orders
orderby o.Customer.Name, o.Total descending
select o
```

具有最终的转换

C#复制

```csharp
orders.
OrderBy(o => o.Customer.Name).
ThenByDescending(o => o.Total)
```

#### Select 子句

查询表达式中的窗体

C#复制

```csharp
from x in e select v
```

转换为

C#复制

```csharp
( e ) . Select ( x => v )
```

除非 v 是标识符 x，该转换是只需

C#复制

```csharp
( e )
```

例如

C#复制

```csharp
from c in customers.Where(c => c.City == "London")
select c
```

只需转换为

C#复制

```csharp
customers.Where(c => c.City == "London")
```

#### Groupby 子句

查询表达式中的窗体

C#复制

```csharp
from x in e group v by k
```

转换为

C#复制

```csharp
( e ) . GroupBy ( x => k , x => v )
```

除非 v 是标识符 x，该转换是

C#复制

```csharp
( e ) . GroupBy ( x => k )
```

该示例

C#复制

```csharp
from c in customers
group c.Name by c.Country
```

转换为

C#复制

```csharp
customers.
GroupBy(c => c.Country, c => c.Name)
```

#### 透明标识符

某些翻译注入与范围变量***透明标识符***为由`*`。 透明标识符不是一种适当的语言功能;它们仅作为中间步骤在查询表达式转换过程中存在。

当查询转换注入透明标识符时，进一步转换步骤会将透明标识符传播的匿名函数和匿名对象初始值设定项。 在这些上下文中，透明标识符具有以下行为：

- 作为匿名函数中的参数的透明标识符时，关联的匿名类型的成员会自动在匿名函数的主体的范围内。
- 作用域具有透明标识符成员时，该成员的成员处于范围内以及。
- 作为匿名对象初始值设定项中的成员声明符是透明的标识符时，它引入了一个具有透明标识符成员。
- 在上面所述的转换步骤，以及匿名类型，为单个对象的成员捕获多个范围变量的意向始终介绍透明标识符了。 允许使用匿名类型相比，另一种机制来组合在一起的多个范围变量的 C# 实现。 下面的转换示例假定匿名类型使用，并显示如何透明标识符可以立即转换。

该示例

C#复制

```csharp
from c in customers
from o in c.Orders
orderby o.Total descending
select new { c.Name, o.Total }
```

转换为

C#复制

```csharp
from * in customers.
    SelectMany(c => c.Orders, (c,o) => new { c, o })
orderby o.Total descending
select new { c.Name, o.Total }
```

这是进一步转换为

C#复制

```csharp
customers.
SelectMany(c => c.Orders, (c,o) => new { c, o }).
OrderByDescending(* => o.Total).
Select(* => new { c.Name, o.Total })
```

时将删除透明标识符，其中，是等效于

C#复制

```csharp
customers.
SelectMany(c => c.Orders, (c,o) => new { c, o }).
OrderByDescending(x => x.o.Total).
Select(x => new { x.c.Name, x.o.Total })
```

其中`x`是编译器生成的标识符，否则是不可见且不可访问。

该示例

C#复制

```csharp
from c in customers
join o in orders on c.CustomerID equals o.CustomerID
join d in details on o.OrderID equals d.OrderID
join p in products on d.ProductID equals p.ProductID
select new { c.Name, o.OrderDate, p.ProductName }
```

转换为

C#复制

```csharp
from * in customers.
    Join(orders, c => c.CustomerID, o => o.CustomerID, 
        (c, o) => new { c, o })
join d in details on o.OrderID equals d.OrderID
join p in products on d.ProductID equals p.ProductID
select new { c.Name, o.OrderDate, p.ProductName }
```

这是进一步简化为

C#复制

```csharp
customers.
Join(orders, c => c.CustomerID, o => o.CustomerID, (c, o) => new { c, o }).
Join(details, * => o.OrderID, d => d.OrderID, (*, d) => new { *, d }).
Join(products, * => d.ProductID, p => p.ProductID, (*, p) => new { *, p }).
Select(* => new { c.Name, o.OrderDate, p.ProductName })
```

最后一个转换是

C#复制

```csharp
customers.
Join(orders, c => c.CustomerID, o => o.CustomerID,
    (c, o) => new { c, o }).
Join(details, x => x.o.OrderID, d => d.OrderID,
    (x, d) => new { x, d }).
Join(products, y => y.d.ProductID, p => p.ProductID,
    (y, p) => new { y, p }).
Select(z => new { z.y.x.c.Name, z.y.x.o.OrderDate, z.p.ProductName })
```

其中`x`， `y`，和`z`是编译器生成的标识符，否则是不可见且不可访问。

### 查询表达式模式

***查询表达式模式***建立一种模式的类型可以实现以支持查询表达式的方法。 通过语法映射情况下，查询表达式转换为方法调用，因为类型具有相当大的灵活性，在查询表达式模式的实现方式。 例如，模式的方法可以实现作为实例方法或扩展方法这两个具有相同的调用语法，因此方法可以请求委托或表达式树，因为匿名函数都可以转换为两者。

泛型类型的建议的形状`C<T>`，支持的查询表达式模式如下所示。 为了说明正确的参数和结果类型之间的关系使用的泛型类型，但可以实现非泛型类型的模式。

C#复制

```csharp
delegate R Func<T1,R>(T1 arg1);

delegate R Func<T1,T2,R>(T1 arg1, T2 arg2);

class C
{
    public C<T> Cast<T>();
}

class C<T> : C
{
    public C<T> Where(Func<T,bool> predicate);

    public C<U> Select<U>(Func<T,U> selector);

    public C<V> SelectMany<U,V>(Func<T,C<U>> selector,
        Func<T,U,V> resultSelector);

    public C<V> Join<U,K,V>(C<U> inner, Func<T,K> outerKeySelector,
        Func<U,K> innerKeySelector, Func<T,U,V> resultSelector);

    public C<V> GroupJoin<U,K,V>(C<U> inner, Func<T,K> outerKeySelector,
        Func<U,K> innerKeySelector, Func<T,C<U>,V> resultSelector);

    public O<T> OrderBy<K>(Func<T,K> keySelector);

    public O<T> OrderByDescending<K>(Func<T,K> keySelector);

    public C<G<K,T>> GroupBy<K>(Func<T,K> keySelector);

    public C<G<K,E>> GroupBy<K,E>(Func<T,K> keySelector,
        Func<T,E> elementSelector);
}

class O<T> : C<T>
{
    public O<T> ThenBy<K>(Func<T,K> keySelector);

    public O<T> ThenByDescending<K>(Func<T,K> keySelector);
}

class G<K,T> : C<T>
{
    public K Key { get; }
}
```

上述两种方法使用泛型委托类型`Func<T1,R>`和`Func<T1,T2,R>`，但它们也同样也可以使用其他委托或表达式树类型使用中的参数和结果类型相同的关系。

请注意之间的建议的关系`C<T>`并`O<T>`这可确保`ThenBy`并`ThenByDescending`方法是仅适用于的结果`OrderBy`或`OrderByDescending`。 此外请注意，建议的结果的形状`GroupBy`-一系列序列，其中每个内部序列具有一个额外`Key`属性。

`System.Linq`命名空间提供用于实现的任何类型的查询运算符模式实现`System.Collections.Generic.IEnumerable<T>`接口。

## 赋值运算符

赋值运算符将一个新值分配给变量、 属性、 事件或索引器元素。

antlr复制

```antlr
assignment
    : unary_expression assignment_operator expression
    ;

assignment_operator
    : '='
    | '+='
    | '-='
    | '*='
    | '/='
    | '%='
    | '&='
    | '|='
    | '^='
    | '<<='
    | right_shift_assignment
    ;
```

赋值的左的操作数必须是归类为变量、 属性访问、 索引器访问或事件访问的表达式。

`=`调用运算符***简单赋值运算符***。 它将右操作数的值分配给由左操作数给定的变量、 属性或索引器元素。 简单赋值运算符的左的操作数不可能是一个事件访问 (除非中所述[类似字段的事件](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#field-like-events))。 简单赋值运算符中所述[简单的赋值](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#simple-assignment)。

以外的其他赋值运算符`=`调用的运算符***复合赋值运算符***。 这些运算符执行两个操作数，指示的运算，然后将生成的值分配给由左操作数给定的变量、 属性或索引器元素。 中介绍了复合赋值运算符[复合赋值](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#compound-assignment)。

`+=`并`-=`事件访问表达式作为左操作数的运算符称为*事件赋值运算符*。 没有其他赋值运算符的左操作数的作为有效事件访问。 中介绍了事件赋值运算符[事件分配](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#event-assignment)。

赋值运算符是右结合运算符，这意味着操作将从右到左分组。 例如，窗体的表达式`a = b = c`评为`a = (b = c)`。

### 简单赋值

`=`调用运算符是简单赋值运算符。

简单赋值的左的操作数是否为窗体`E.P`或`E[Ei]`其中`E`具有编译时类型`dynamic`，然后分配动态绑定 ([动态绑定](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#dynamic-binding))。 在这种情况下是赋值表达式的编译时类型`dynamic`，如下所述的分辨率将发生在运行时基于的运行时类型和`E`。

在简单赋值中，右操作数必须是隐式转换为左操作数的类型的表达式。 该操作将右操作数的值分配给由左操作数给定的变量、 属性或索引器元素。

简单的赋值表达式的结果是分配给左操作数的值。 结果具有左操作数为相同的类型，并始终分类为一个值。

如果左的操作数是属性或索引器访问，必须具有属性或索引器`set`访问器。 如果这不是这种情况，绑定时出错。

窗体的简单分配的运行时处理`x = y`包括以下步骤：

- 如果`x`分类为变量：
  - `x` 计算为生成变量。
  - `y` 是计算并，如有必要，转换为的类型`x`通过隐式转换 ([隐式转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#implicit-conversions))。
  - 如果通过给出的变量`x`是一个数组元素的*reference_type*，将运行时检查以确保计算的值`y`数组实例与兼容`x`是元素。 如果箱子`y`是`null`，或如果隐式引用转换 ([隐式引用转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#implicit-reference-conversions)) 存在从引用的实例的实际类型`y`为实际的元素类型数组实例包含`x`。 否则，将会引发 `System.ArrayTypeMismatchException`。
  - 从评估和转换所产生的值`y`存储到给定的评估结果的位置`x`。
- 如果`x`归类为属性或索引器访问：
  - 实例表达式 (如果`x`不是`static`) 和参数列表 (如果`x`的索引器访问) 与关联`x`计算，然后在后续结果`set`取值函数调用。
  - `y` 是计算并，如有必要，转换为的类型`x`通过隐式转换 ([隐式转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#implicit-conversions))。
  - `set`访问器的`x`为计算的值使用调用`y`作为其`value`参数。

数组协变规则 ([数组协方差](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/arrays#array-covariance)) 允许使用数组类型的值`A[]`是对的数组类型实例的引用`B[]`，则从存在的隐式引用转换`B`到`A`. 由于这些规则，对的数组元素赋值*reference_type*需要运行时检查以确保所赋的值与数组实例兼容。 在示例

C#复制

```csharp
string[] sa = new string[10];
object[] oa = sa;

oa[0] = null;               // Ok
oa[1] = "Hello";            // Ok
oa[2] = new ArrayList();    // ArrayTypeMismatchException
```

最后一个分配会导致`System.ArrayTypeMismatchException`因为引发的实例`ArrayList`不能存储在一个元素的`string[]`。

当属性或索引器声明中*struct_type*所分配的实例表达式的目标关联的属性或索引器访问必须分类为变量。 如果实例表达式分类为一个值，绑定时出错。 由于[成员访问](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#member-access)，相同的规则也适用于字段。

给定下列声明：

C#复制

```csharp
struct Point
{
    int x, y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int X {
        get { return x; }
        set { x = value; }
    }

    public int Y {
        get { return y; }
        set { y = value; }
    }
}

struct Rectangle
{
    Point a, b;

    public Rectangle(Point a, Point b) {
        this.a = a;
        this.b = b;
    }

    public Point A {
        get { return a; }
        set { a = value; }
    }

    public Point B {
        get { return b; }
        set { b = value; }
    }
}
```

在示例

C#复制

```csharp
Point p = new Point();
p.X = 100;
p.Y = 100;
Rectangle r = new Rectangle();
r.A = new Point(10, 10);
r.B = p;
```

对分配`p.X`， `p.Y`， `r.A`，和`r.B`允许，因为`p`和`r`是变量。 但是，在以下示例

C#复制

```csharp
Rectangle r = new Rectangle();
r.A.X = 10;
r.A.Y = 10;
r.B.X = 100;
r.B.Y = 100;
```

分配都无效，因为`r.A`和`r.B`不是变量。

### 复合赋值

复合赋值的左的操作数是否为窗体`E.P`或`E[Ei]`其中`E`具有编译时类型`dynamic`，然后分配动态绑定 ([动态绑定](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#dynamic-binding))。 在这种情况下是赋值表达式的编译时类型`dynamic`，如下所述的分辨率将发生在运行时基于的运行时类型和`E`。

操作的窗体`x op= y`处理的应用的二元运算符重载解析 ([二元运算符重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#binary-operator-overload-resolution)) 该操作已编写`x op y`。 然后，

- 如果所选运算符的返回类型是隐式转换为的类型`x`，该操作将被视为`x = x op y`，只不过`x`只计算一次。
- 否则为如果所选的运算符是一个预定义的运算符，如果所选运算符的返回类型是显式转换为的类型`x`，并且如果`y`隐式转换为的类型`x`或操作员移位运算符，则该操作将被视为`x = (T)(x op y)`，其中`T`是一种`x`，只不过`x`只计算一次。
- 否则为复合赋值是无效的并且绑定时出错。

术语"仅计算一次"意味着在评估`x op y`，任何构成表达式的结果`x`是暂时保存并重用时执行的赋值`x`。 例如，在赋值`A()[B()] += C()`，其中`A`是一种方法返回`int[]`，和`B`并`C`方法返回`int`，按顺序一次，调用这些方法`A`，`B`, `C`.

属性访问或索引器访问的左的操作数的复合赋值时，属性或索引器必须同时具有`get`访问器和一个`set`访问器。 如果这不是这种情况，绑定时出错。

允许的值之上的第二个段落`x op= y`计算结果为`x = (T)(x op y)`在某些上下文中。 此规则存在，使预定义的运算符可以用作复合运算符，如果左的操作数的类型`sbyte`， `byte`， `short`， `ushort`，或`char`。 甚至当两个参数都属于这些类型之一时，预定义的运算符生成类型的结果`int`，如中所述[二进制数值提升](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#binary-numeric-promotions)。 因此，不进行强制转换它就不可能要将结果分配到左操作数。

预定义的运算符的规则的直观的效果是只需`x op= y`如果这两个，则允许的`x op y`和`x = y`允许。 在示例

C#复制

```csharp
byte b = 0;
char ch = '\0';
int i = 0;

b += 1;             // Ok
b += 1000;          // Error, b = 1000 not permitted
b += i;             // Error, b = i not permitted
b += (byte)i;       // Ok

ch += 1;            // Error, ch = 1 not permitted
ch += (char)1;      // Ok
```

每个错误的直观原因是，相应的简单分配也已经出现错误。

这也意味着复合赋值操作支持取消操作。 在示例

C#复制

```csharp
int? i = 0;
i += 1;             // Ok
```

提升的运算符`+(int?,int?)`使用。

### 事件分配

如果左的操作数`+=`或`-=`运算符属于事件访问，则表达式进行计算，如下所示：

- 实例，如果有，事件访问的被计算表达式。
- 右操作数`+=`或`-=`运算符要计算，并如有必要，转换为通过隐式转换的左操作数的类型 ([隐式转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#implicit-conversions))。
- 事件的事件访问器会调用带有参数组成的列表，右操作数，在评估之后，如有必要，转换。 如果该运算符`+=`，则`add`调用访问器; 如果该运算符`-=`，则`remove`调用访问器。

事件赋值表达式不产生值。 因此，事件赋值表达式是有效的上下文中仅*statement_expression* ([表达式语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/statements#expression-statements))。

## 表达式

*表达式*可以是*non_assignment_expression*或*分配*。

antlr复制

```antlr
expression
    : non_assignment_expression
    | assignment
    ;

non_assignment_expression
    : conditional_expression
    | lambda_expression
    | query_expression
    ;
```

## 常量表达式

一个*constant_expression*是可以在编译时完全计算的表达式。

antlr复制

```antlr
constant_expression
    : expression
    ;
```

常量表达式必须为`null`文字或具有以下类型之一的值： `sbyte`， `byte`， `short`， `ushort`， `int`， `uint`， `long`， `ulong`， `char``float`， `double`， `decimal`， `bool`， `object`， `string`，或任何枚举类型。常量表达式中允许仅以下构造：

- 文本 (包括`null`文字)。
- 对引用`const`类和结构类型的成员。
- 对枚举类型的成员的引用。
- 对引用`const`参数或局部变量
- 带括号的子表达式，其自身是常量表达式。
- 强制转换表达式，前提是目标类型是上面列出的类型之一。
- `checked` 和`unchecked`表达式
- 默认值表达式
- Nameof 表达式
- 预定义`+`， `-`， `!`，和`~`一元运算符。
- 预定义`+`， `-`， `*`， `/`， `%`， `<<`， `>>`， `&`， `|`， `^`， `&&`， `||`， `==`， `!=`， `<`， `>`， `<=`，并`>=`二元运算符，提供每个操作数是上面列出的类型。
- `?:`条件运算符。

在常量表达式中允许以下转换：

- 标识转换
- 数值转换
- 枚举的转换
- 常量表达式转换
- 提供的转换的源是常量表达式的计算结果为 null 值的隐式和显式引用转换。

其他转换，包括装箱，取消装箱转换和隐式引用转换的非 null 值的常量表达式中不允许。 例如：

C#复制

```csharp
class C {
    const object i = 5;         // error: boxing conversion not permitted
    const object str = "hello"; // error: implicit reference conversion
}
```

初始化 i 是一个错误，因为是必需的装箱转换。 Str 初始化是一个错误，因为从非 null 值的隐式引用转换是必需的。

只要表达式可满足上面列出的要求，是在编译时计算该表达式。 即使该表达式是包含非常量构造较大表达式的子表达式，这是如此。

只不过时，运行时计算引发异常，而编译时计算会导致编译时错误发生，常量表达式的编译时计算为非常量表达式的运行时评估使用相同的规则。

除非常量表达式显式置于`unchecked`上下文，在编译时计算的表达式始终过程发生在整型类型算术运算和转换的溢出会导致编译时错误 ([常量表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#constant-expressions))。

以下列出的上下文中发生的常量表达式。 在这些上下文中，如果不能在编译时完全计算表达式，则发生编译时错误。

- 常数声明 ([常量](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#constants))。
- 枚举成员声明 ([枚举成员](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/enums#enum-members))。
- 默认自变量的形式参数列表 ([方法参数](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/classes#method-parameters))
- `case` 标签`switch`语句 ([switch 语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/statements#the-switch-statement))。
- `goto case` 语句 ([goto 语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/statements#the-goto-statement))。
- 数组创建表达式中的维度长度 ([数组创建表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#array-creation-expressions))，其中包含初始值设定项。
- 属性 ([属性](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/attributes))。

常量表达式隐式转换 ([隐式的常量表达式转换](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/conversions#implicit-constant-expression-conversions)) 允许类型的常量表达式`int`转换为`sbyte`， `byte`， `short`， `ushort`， `uint`，或`ulong`，前提是目标类型的范围内的常量表达式的值。

## Boolean 表达式

一个*boolean_expression*是生成类型的结果的表达式`bool`; 或者直接或通过应用程序的`operator true`在某些上下文中指定在下面的示例。

antlr复制

```antlr
boolean_expression
    : expression
    ;
```

控制条件表达式*if_statement* ([if 语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/statements#the-if-statement))， *while_statement* ([while 语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/statements#the-while-statement))，*do_statement* ([do 语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/statements#the-do-statement))，或*for_statement*([语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/statements#the-for-statement)) 是*boolean_表达式*。 控制条件表达式`?:`运算符 ([条件运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#conditional-operator)) 遵循相同的规则*boolean_expression*，但出于运算符优先级进行分类作为*conditional_or_expression*。

一个*boolean_expression* `E`生成类型的值所需`bool`，按如下所示：

- 如果`E`隐式转换为`bool`然后该隐式转换将它应用在运行时。
- 否则，一元运算符重载决策 ([一元运算符重载决策](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/expressions#unary-operator-overload-resolution)) 用于查找运算符的唯一最佳实现`true`上`E`，并在运行时应用该实现。
- 如果不找到任何此类运算符，则绑定时出错。

`DBBool`中的结构类型[数据库布尔类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/language-specification/structs#database-boolean-type)提供了实现的类型的一个示例`operator true`和`operator false`。