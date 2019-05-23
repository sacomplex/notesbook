# [Literal Keywords](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/literal-keywords)

C# 包含以下文本关键字：

- [null](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/null)
- [true](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/true)
- [false](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/false)
- [default](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/default)

## [null](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/null)

`null` 关键字是表示不引用任何对象的空引用的文字值。 `null` 是引用类型变量的默认值。 普通值类型不能为 null。 但是，C# 2.0 引入了可以为 null 的值类型。 请参阅[可以为 Null 的类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/nullable-types/index)。

下面的示例演示 null 关键字的一些行为：

```csharp
 class Program
 {
     class MyClass
     {
         public void MyMethod() { }
     }

     static void Main(string[] args)
     {
         // Set a breakpoint here to see that mc = null.
         // However, the compiler considers it "unassigned."
         // and generates a compiler error if you try to
         // use the variable.
         MyClass mc;

         // Now the variable can be used, but...
         mc = null;

         // ... a method call on a null object raises 
         // a run-time NullReferenceException.
         // Uncomment the following line to see for yourself.
         // mc.MyMethod();

         // Now mc has a value.
         mc = new MyClass();

         // You can call its method.
         mc.MyMethod();

         // Set mc to null again. The object it referenced
         // is no longer accessible and can now be garbage-collected.
         mc = null;

         // A null string is not the same as an empty string.
         string s = null;
         string t = String.Empty; // Logically the same as ""
         
         // Equals applied to any null object returns false.
         bool b = (t.Equals(s));
         Console.WriteLine(b);

         // Equality operator also returns false when one
         // operand is null.
         Console.WriteLine("Empty string {0} null string", s == t ? "equals": "does not equal");

         // Returns true.
         Console.WriteLine("null == null is {0}", null == null);


         // A value type cannot be null
         // int i = null; // Compiler error!

         // Use a nullable value type instead:
         int? i = null;

         // Keep the console window open in debug mode.
         System.Console.WriteLine("Press any key to exit.");
         System.Console.ReadKey();

     }
 }
```

## [default](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/default)

`default` 关键字可用于 `switch` 语句或默认值表达式中：

- [switch 语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/switch)：指定默认标签。
- [默认值表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/default-value-expressions)：生成类型的默认值。