# [Exceptions and Exception Handling](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/exceptions/)

C# 语言的异常处理功能有助于处理在程序运行期间发生的任何意外或异常情况。 异常处理功能使用 `try`、`catch` 和 `finally` 关键字来尝试执行可能失败的操作、在你确定合理的情况下处理故障，以及在事后清除资源。 公共语言运行时 (CLR)、.NET Framework/任何第三方库或应用程序代码都可以生成异常。 异常是使用 `throw` 关键字创建而成。

在许多情况下，异常并不是由代码直接调用的方法抛出，而是由调用堆栈中再往下的另一方法抛出。 如果出现这种情况，CLR 会展开堆栈，同时针对特定异常类型查找包含 `catch` 代码块的方法，并执行找到的首个此类 `catch` 代码块。 如果在调用堆栈中找不到相应的 `catch` 代码块，将会终止进程并向用户显示消息。

在以下示例中，方法用于测试除数是否为零，并捕获相应的错误。 如果没有异常处理功能，此程序将终止，并显示 **DivideByZeroException was unhandled** 错误。

```csharp
class ExceptionTest
{
    static double SafeDivision(double x, double y)
    {
        if (y == 0)
            throw new System.DivideByZeroException();
        return x / y;
    }
    static void Main()
    {
        // Input for test purposes. Change the values to see
        // exception handling behavior.
        double a = 98, b = 0;
        double result = 0;

        try
        {
            result = SafeDivision(a, b);
            Console.WriteLine("{0} divided by {1} = {2}", a, b, result);
        }
        catch (DivideByZeroException e)
        {
            Console.WriteLine("Attempted divide by zero.");
        }
    }
}
```

## 异常概述

异常具有以下属性：

- 异常是最终全都派生自 `System.Exception` 的类型。
- 在可能抛出异常的语句周围使用 `try` 代码块。
- 在 `try` 代码块中出现异常后，控制流会跳转到调用堆栈中任意位置上的首个相关异常处理程序。 在 C# 中，`catch` 关键字用于定义异常处理程序。
- 如果给定的异常没有对应的异常处理程序，那么程序会停止执行，并显示错误消息。
- 除非可以处理异常并让应用程序一直处于已知状态，否则不捕获异常。 如果捕获 `System.Exception`，使用 `catch` 代码块末尾的 `throw` 关键字重新抛出异常。
- 如果 `catch` 代码块定义异常变量，可以用它来详细了解所发生的异常类型。
- 使用 `throw` 关键字，程序可以显式生成异常。
- 异常对象包含错误详细信息，如调用堆栈的状态和错误的文本说明。
- 即使有异常抛出，`finally` 代码块中的代码仍会执行。 使用 `finally` 代码块可释放资源。例如，关闭在 `try` 代码块中打开的任何流或文件。
- .NET Framework 中的托管异常在 Win32 结构化异常处理机制的基础之上实现。 有关详细信息，请参阅[结构化异常处理 (C/C++)](https://docs.microsoft.com/zh-cn/cpp/cpp/structured-exception-handling-c-cpp) 和[速成教程：深入了解 Win32 结构化异常处理](https://bytepointer.com/resources/pietrek_crash_course_depths_of_win32_seh.htm)。

## [Using Exceptions](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/exceptions/using-exceptions)

在 C# 中，程序中的运行时错误通过使用一种称为“异常”的机制在程序中传播。 异常由遇到错误的代码引发，由能够更正错误的代码捕捉。 异常可由 .NET Framework 公共语言运行时 (CLR) 或由程序中的代码引发。 一旦引发了一个异常，此异常会在调用堆栈中传播，直到找到针对它的 `catch` 语句。 未捕获的异常由系统提供的通用异常处理程序处理，该处理程序会显示一个对话框。

异常由从 [Exception](https://docs.microsoft.com/zh-cn/dotnet/api/system.exception) 派生的类表示。 此类标识异常的类型，并包含详细描述异常的属性。 引发异常涉及创建异常派生类的实例，配置异常的属性（可选），然后使用 `throw` 关键字引发该对象。 例如:

```csharp
       class CustomException : Exception
       {
           public CustomException(string message)
           {
              
           }

       }
       private static void TestThrow()
       {
           CustomException ex =
               new CustomException("Custom exception in TestThrow()");

           throw ex;
       }
```

引发异常后，运行时将检查当前语句，以确定它是否在 `try` 块内。 如果在，则将检查与 `try` 块关联的所有 `catch` 块，以确定它们是否可以捕获该异常。 `Catch` 块通常会指定异常类型；如果该 `catch` 块的类型与异常或异常的基类的类型相同，则该 `catch` 块可处理该方法。 例如:

```csharp
static void TestCatch()
{
    try
    {
        TestThrow();
    }
    catch (CustomException ex)
    {
        System.Console.WriteLine(ex.ToString());
    }
}
```

如果引发异常的语句不在 `try` 块内或者包含该语句的 `try` 块没有匹配的 `catch` 块，则运行时将检查调用方法中是否有 `try` 语句和 `catch` 块。 运行时将继续调用堆栈，搜索兼容的 `catch` 块。 在找到并执行 `catch` 块之后，控制权将传递给 `catch` 块之后的下一个语句。

一个 `try` 语句可包含多个 `catch` 块。 将执行第一个能够处理该异常的 `catch` 语句；将忽略任何后续的 `catch` 语句，即使它们是兼容的也是如此。 因此，应始终按照从最具有针对性（或派生程序最高）到最不具有针对性的顺序来捕获块。 例如:

```csharp
using System;
using System.IO;

public class ExceptionExample
{
    static void Main()
    {
        try
        {
            using (var sw = new StreamWriter(@"C:\test\test.txt"))
            {
                sw.WriteLine("Hello");
            }   
        }
        // Put the more specific exceptions first.
        catch (DirectoryNotFoundException ex)
        {
            Console.WriteLine(ex);  
        }
        catch (FileNotFoundException ex)
        {
            Console.WriteLine(ex);  
        }
        // Put the least specific exception last.
        catch (IOException ex)
        {
            Console.WriteLine(ex);  
        }

        Console.WriteLine("Done"); 
    }
}
```

执行 `catch` 块之前，运行时会检查 `finally` 块。 `Finally` 块使程序员可以清除中止的 `try` 块可能遗留下的任何模糊状态，或者释放任何外部资源（例如图形句柄、数据库连接或文件流），而无需等待垃圾回收器在运行时完成这些对象。 例如:

```csharp
static void TestFinally()
{
    System.IO.FileStream file = null;
    //Change the path to something that works on your machine.
    System.IO.FileInfo fileInfo = new System.IO.FileInfo(@"C:\file.txt");

    try
    {
        file = fileInfo.OpenWrite();
        file.WriteByte(0xF);
    }
    finally
    {
        // Closing the file allows you to reopen it immediately - otherwise IOException is thrown.
        if (file != null)
        {
            file.Close();
        }
    }

    try
    {
        file = fileInfo.OpenWrite();
        System.Console.WriteLine("OpenWrite() succeeded");
    }
    catch (System.IO.IOException)
    {
        System.Console.WriteLine("OpenWrite() failed");
    }
}
```

如果 `WriteByte()` 引发了异常并且未调用 `file.Close()`，则第二个 `try` 块中尝试重新打开文件的代码将会失败，并且文件将保持锁定状态。 由于即使引发异常也会执行 `finally` 块，前一示例中的 `finally` 块可使文件正确关闭，从而有助于避免错误。

如果引发异常之后没有在调用堆栈上找到兼容的 `catch` 块，则会出现以下三种情况之一：

- 如果异常存在于终结器内，将中止终结器，并调用基类终结器（如果有）。
- 如果调用堆栈包含静态构造函数或静态字段初始值设定项，将引发 [TypeInitializationException](https://docs.microsoft.com/zh-cn/dotnet/api/system.typeinitializationexception)，同时将原始异常分配给新异常的 [InnerException](https://docs.microsoft.com/zh-cn/dotnet/api/system.exception.innerexception) 属性。
- 如果到达线程的开头，则终止线程。

## [Exception Handling](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/exceptions/exception-handling)

C# 程序员使用 [try](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/try-catch) 块来对可能受异常影响的代码进行分区。 关联的 [catch](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/try-catch) 块用于处理生成的任何异常。 [finally](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/try-finally) 块包含无论 `try` 块中是否引发异常都会运行的代码，如发布 `try` 块中分配的资源。 `try` 块需要一个或多个关联的 `catch` 块或一个 `finally` 块，或两者皆之。

下面的示例演示 `try-catch` 语句、`try-finally` 语句和 `try-catch-finally` 语句。

```csharp
try
{
    // Code to try goes here.
}
catch (SomeSpecificException ex)
{
    // Code to handle the exception goes here.
    // Only catch exceptions that you know how to handle.
    // Never catch base class System.Exception without
    // rethrowing it at the end of the catch block.
}
```

```csharp
try
{
    // Code to try goes here.
}
finally
{
    // Code to execute after the try block goes here.
}
```

```csharp
try
{
    // Code to try goes here.
}
catch (SomeSpecificException ex)
{
    // Code to handle the exception goes here.
}
finally
{
    // Code to execute after the try (and possibly catch) blocks 
    // goes here.
}
```

一个不具有 `catch` 或 `finally` 块的 `try` 块会导致编译器错误。

### catch 块

`catch` 块可以指定要捕获的异常的类型。 该类型规范称为异常筛选器。 异常类型应派生自 [Exception](https://docs.microsoft.com/zh-cn/dotnet/api/system.exception)。 一般情况下，不要将 [Exception](https://docs.microsoft.com/zh-cn/dotnet/api/system.exception) 指定为异常筛选器，除非了解如何处理可能在 `try` 块中引发的所有异常，或者已在 `catch` 块的末尾处包括了 [throw](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/throw) 语句。

可将具有不同异常筛选器的多个 `catch` 块链接在一起。 代码中 `catch` 块的计算顺序为从上到下，但针对引发的每个异常，仅执行一个 `catch` 块。 将执行指定所引发的异常的确切类型或基类的第一个 `catch` 块。 如果没有 `catch` 块指定匹配的异常筛选器，则将选择不具有筛选器的 `catch` 块（如果语句中存在）。 务必首先定位具有最具体的（即，最底层派生的）异常类型的 `catch` 块。

应当会在下列条件为 true 时捕获到异常：

- 能够很好地理解可能会引发异常的原因，并且可以实现特定的恢复，例如捕获 [FileNotFoundException](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.filenotfoundexception) 对象时提示用户输入新文件名。

- 可以创建和引发一个新的、更具体的异常。

  ```csharp
  int GetInt(int[] array, int index)
  {
      try
      {
          return array[index];
      }
      catch(System.IndexOutOfRangeException e)
      {
          throw new System.ArgumentOutOfRangeException(
              "Parameter index is out of range.", e);
      }
  }
  ```

- 想要先对异常进行部分处理，然后再将其传递以进行额外处理。 在下面的示例中，`catch` 块用于在重新引发异常之前将条目添加到错误日志。

  ```csharp
  try
  {
      // Try to access a resource.
  }
  catch (System.UnauthorizedAccessException e)
  {
      // Call a custom error logging procedure.
      LogError(e);
      // Re-throw the error.
      throw;     
  }
  ```

### Finally 块

`finally` 块让你可以清理在 `try` 块中所执行的操作。 如果存在 `finally` 块，将在执行 `try` 块和任何匹配的 `catch` 块之后，最后执行它。 无论是否会引发异常或找到匹配异常类型的 `catch` 块，`finally` 块都将始终运行。

`finally` 块可用于发布资源（如文件流、数据库连接和图形句柄）而无需等待运行时中的垃圾回收器来完成对象。 有关详细信息，请参阅 [using 语句](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/using-statement)。

在下面的示例中，`finally` 块用于关闭在 `try` 块中打开的文件。 请注意，在关闭文件之前，将检查文件句柄的状态。 如果 `try` 块不能打开文件，则文件句柄仍将具有值 `null` 且 `finally` 块不会尝试将其关闭。 或者，如果在 `try` 块中成功打开文件，则 `finally` 块将关闭打开的文件。

```csharp
System.IO.FileStream file = null;
System.IO.FileInfo fileinfo = new System.IO.FileInfo("C:\\file.txt");
try
{
    file = fileinfo.OpenWrite();
    file.WriteByte(0xF);
}
finally
{
    // Check for null because OpenWrite might have failed.
    if (file != null)
    {
        file.Close();
    }
}
```

## [Creating and Throwing Exceptions](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/exceptions/creating-and-throwing-exceptions)

异常用于指示在运行程序时发生了错误。 此时将创建一个描述错误的异常对象，然后使用 [throw](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/throw) 关键字引发。 然后，运行时搜索最兼容的异常处理程序。

当存在下列一种或多种情况时，程序员应引发异常：

- 方法无法完成其定义的功能。

  例如，如果一种方法的参数具有无效的值：

  ```csharp
  static void CopyObject(SampleClass original)
  {
      if (original == null)
      {
          throw new System.ArgumentException("Parameter cannot be null", "original");
      }
  
  }
  ```

- 根据对象的状态，对某个对象进行不适当的调用。

  一个示例可能是尝试写入只读文件。 在对象状态不允许操作的情况下，引发 [InvalidOperationException](https://docs.microsoft.com/zh-cn/dotnet/api/system.invalidoperationexception) 的实例或基于此类的派生的对象。 这是引发 [InvalidOperationException](https://docs.microsoft.com/zh-cn/dotnet/api/system.invalidoperationexception) 对象的方法示例：

  ```csharp
  class ProgramLog
  {
      System.IO.FileStream logFile = null;
      void OpenLog(System.IO.FileInfo fileName, System.IO.FileMode mode) {}
  
      void WriteLog()
      {
          if (!this.logFile.CanWrite)
          {
              throw new System.InvalidOperationException("Logfile cannot be read-only");
          }
          // Else write data to the log and return.
      }
  }
  ```

- 方法的参数引发了异常。

  在这种情况下，应捕获原始异常，并创建 [ArgumentException](https://docs.microsoft.com/zh-cn/dotnet/api/system.argumentexception) 实例。 应将原始异常作为 [InnerException](https://docs.microsoft.com/zh-cn/dotnet/api/system.exception.innerexception) 参数传递给 [ArgumentException](https://docs.microsoft.com/zh-cn/dotnet/api/system.argumentexception) 的构造函数：

  ```csharp
  static int GetValueFromArray(int[] array, int index)
  {
      try
      {
          return array[index];
      }
      catch (System.IndexOutOfRangeException ex)
      {
          System.ArgumentException argEx = new System.ArgumentException("Index is out of range", "index", ex);
          throw argEx;
      }
  }
  ```

异常包含一个名为 [StackTrace](https://docs.microsoft.com/zh-cn/dotnet/api/system.exception.stacktrace) 的属性。 此字符串包含当前调用堆栈上的方法的名称，以及为每个方法引发异常的位置（文件名和行号）。 [StackTrace](https://docs.microsoft.com/zh-cn/dotnet/api/system.exception.stacktrace) 对象由公共语言运行时 (CLR) 从 `throw` 语句的位置点自动创建，因此必须从堆栈跟踪的开始点引发异常。

所有异常都包含一个名为 [Message](https://docs.microsoft.com/zh-cn/dotnet/api/system.exception.message) 的属性。 应设置此字符串来解释发生异常的原因。 请注意，不应将安全敏感的信息放在消息文本中。 除 [Message](https://docs.microsoft.com/zh-cn/dotnet/api/system.exception.message) 以外，[ArgumentException](https://docs.microsoft.com/zh-cn/dotnet/api/system.argumentexception) 也包含一个名为 [ParamName](https://docs.microsoft.com/zh-cn/dotnet/api/system.argumentexception.paramname) 的属性，应将该属性设置为导致引发异常的参数的名称。 对于属性资源库，[ParamName](https://docs.microsoft.com/zh-cn/dotnet/api/system.argumentexception.paramname) 应设置为 `value`。

公共的受保护方法在无法完成其预期功能时应引发异常。 引发的异常类应是符合错误条件的最具体的可用异常。这些异常应编写为类功能的一部分，并且原始类的派生类或更新应保留相同的行为以实现后向兼容性。

### 引发异常时应避免的情况

以下列表标识了引发异常时要避免的做法：

- 异常不能用于在正常执行过程中更改程序的流程。 异常只能用于报告和处理错误条件。
- 只能引发异常，而不能作为返回值或参数返回异常。
- 请勿有意从自己的源代码中引发 [System.Exception](https://docs.microsoft.com/zh-cn/dotnet/api/system.exception)、[System.SystemException](https://docs.microsoft.com/zh-cn/dotnet/api/system.systemexception)、[System.NullReferenceException](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullreferenceexception) 或 [System.IndexOutOfRangeException](https://docs.microsoft.com/zh-cn/dotnet/api/system.indexoutofrangeexception)。
- 不要创建可在调试模式下引发，但不会在发布模式下引发的异常。 若要在开发阶段确定运行时错误，请改用调试断言。

### 定义异常类

程序可以引发 [System](https://docs.microsoft.com/zh-cn/dotnet/api/system) 命名空间中的预定义异常类（前面提到的情况除外），或通过从 [Exception](https://docs.microsoft.com/zh-cn/dotnet/api/system.exception) 派生来创建其自己的异常类。 派生类应至少定义四个构造函数：一个默认构造函数、一个用于设置消息属性的构造函数，以及一个用于设置 [Message](https://docs.microsoft.com/zh-cn/dotnet/api/system.exception.message) 和 [InnerException](https://docs.microsoft.com/zh-cn/dotnet/api/system.exception.innerexception) 属性的构造函数。 第四个构造函数用于序列化异常。 新的异常类应可序列化。 例如:

```csharp
[Serializable()]
public class InvalidDepartmentException : System.Exception
{
    public InvalidDepartmentException() : base() { }
    public InvalidDepartmentException(string message) : base(message) { }
    public InvalidDepartmentException(string message, System.Exception inner) : base(message, inner) { }

    // A constructor is needed for serialization when an
    // exception propagates from a remoting server to the client. 
    protected InvalidDepartmentException(System.Runtime.Serialization.SerializationInfo info,
        System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
}
```

只有当新属性提供的数据有助于解决异常时，才应将其添加到异常类中。 如果将新属性添加到派生异常类中，则应替代 `ToString()` 以返回添加的信息。

## [Compiler-Generated Exceptions](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/exceptions/compiler-generated-exceptions)

当基本操作失败时，.NET Framework 的公共语言运行时 (CLR) 会自动引发一些异常。 这些异常及其错误条件在下表中列出。

| 例外                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [ArithmeticException](https://docs.microsoft.com/zh-cn/dotnet/api/system.arithmeticexception) | 算术运算期间出现的异常的基类，例如 [DivideByZeroException](https://docs.microsoft.com/zh-cn/dotnet/api/system.dividebyzeroexception) 和 [OverflowException](https://docs.microsoft.com/zh-cn/dotnet/api/system.overflowexception)。 |
| [ArrayTypeMismatchException](https://docs.microsoft.com/zh-cn/dotnet/api/system.arraytypemismatchexception) | 由于元素的实际类型与数组的实际类型不兼容而导致数组无法存储给定元素时引发。 |
| [DivideByZeroException](https://docs.microsoft.com/zh-cn/dotnet/api/system.dividebyzeroexception) | 尝试将整数值除以零时引发。                                   |
| [IndexOutOfRangeException](https://docs.microsoft.com/zh-cn/dotnet/api/system.indexoutofrangeexception) | 索引小于零或超出数组边界时，尝试对数组编制索引时引发。       |
| [InvalidCastException](https://docs.microsoft.com/zh-cn/dotnet/api/system.invalidcastexception) | 从基类型显式转换为接口或派生类型在运行时失败时引发。         |
| [NullReferenceException](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullreferenceexception) | 尝试引用值为 [null](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/null) 的对象时引发。 |
| [OutOfMemoryException](https://docs.microsoft.com/zh-cn/dotnet/api/system.outofmemoryexception) | 尝试使用[新](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/new-operator)运算符分配内存失败时引发。 这表示可用于公共语言运行时的内存已用尽。 |
| [OverflowException](https://docs.microsoft.com/zh-cn/dotnet/api/system.overflowexception) | `checked` 上下文中的算术运算溢出时引发。                     |
| [StackOverflowException](https://docs.microsoft.com/zh-cn/dotnet/api/system.stackoverflowexception) | 执行堆栈由于有过多挂起的方法调用而用尽时引发；通常表示非常深的递归或无限递归。 |
| [TypeInitializationException](https://docs.microsoft.com/zh-cn/dotnet/api/system.typeinitializationexception) | 静态构造函数引发异常并且没有兼容的 `catch` 子句来捕获异常时引发。 |

## [How to: Handle an Exception Using try-catch](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/exceptions/how-to-handle-an-exception-using-try-catch)

[try-catch](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/try-catch) 块的用途是捕获并处理工作代码产生的异常。 某些异常可以在 `catch` 块中进行处理，问题得以解决并不再出现异常；但是，大多数情况下你唯一可做的是确保引发的异常是合理异常。

### 示例

在此示例中，[IndexOutOfRangeException](https://docs.microsoft.com/zh-cn/dotnet/api/system.indexoutofrangeexception) 不是最合理的异常：[ArgumentOutOfRangeException](https://docs.microsoft.com/zh-cn/dotnet/api/system.argumentoutofrangeexception) 对于此方法来说更有意义，因为此错误是由调用方传递的 `index` 参数引起的。

```csharp
class TestTryCatch
{
    static int GetInt(int[] array, int index)
    {
        try
        {
            return array[index];
        }
        catch (System.IndexOutOfRangeException e)  // CS0168
        {
            System.Console.WriteLine(e.Message);
            // Set IndexOutOfRangeException to the new exception's InnerException.
            throw new System.ArgumentOutOfRangeException("index parameter is out of range.", e);
        }
    }
}
```

### 注释

引发异常的代码包含在 `try` 块中。 在此块后面紧挨着添加 `catch` 语句以处理 `IndexOutOfRangeException` 异常（如果发生此异常）。 `catch` 块处理 `IndexOutOfRangeException` 异常并改为引发更合理的 `ArgumentOutOfRangeException` 异常。 为了向调用方提供尽可能多的信息，请考虑将原始异常指定为新异常的 [InnerException](https://docs.microsoft.com/zh-cn/dotnet/api/system.exception.innerexception)。 因为 [InnerException](https://docs.microsoft.com/zh-cn/dotnet/api/system.exception.innerexception) 属性为 [readonly](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/readonly)，所以必须在新异常的构造函数中指定此属性。

## [How to: Execute Cleanup Code Using finally](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/exceptions/how-to-execute-cleanup-code-using-finally)

`finally` 语句的用途是确保立即进行对象（通常是容纳外部资源的对象）的必要清理（即使引发异常）。 这类清理的一个示例是在使用之后立即对 [FileStream](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.filestream) 调用 [Close](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.stream.close)（而不是等待公共语言运行时对对象进行垃圾回收），如下所示：

```csharp
static void CodeWithoutCleanup()
{
    System.IO.FileStream file = null;
    System.IO.FileInfo fileInfo = new System.IO.FileInfo("C:\\file.txt");

    file = fileInfo.OpenWrite();
    file.WriteByte(0xF);

    file.Close();
}
```

### 示例

若要将上面的代码转换为 `try-catch-finally` 语句，可将清理代码与工作代码分开，如下所示。

```csharp
static void CodeWithCleanup()
{
    System.IO.FileStream file = null;
    System.IO.FileInfo fileInfo = null;

    try
    {
        fileInfo = new System.IO.FileInfo("C:\\file.txt");

        file = fileInfo.OpenWrite();
        file.WriteByte(0xF);
    }
    catch(System.UnauthorizedAccessException e)
    {
        System.Console.WriteLine(e.Message);
    }
    finally
    {
        if (file != null)
        {
            file.Close();
        }
    }
}
```

因为可能会在 `try` 块中进行 `OpenWrite()` 调用之前的任何时候发生异常，或 `OpenWrite()` 调用本身可能会失败，所以我们不保证在尝试关闭文件时文件处于打开状态。 `finally` 块添加了一个检查，以便在调用 [Close](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.stream.close) 方法之前确保 [FileStream](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.filestream) 对象不是 `null`。 如果不进行 `null` 检查，则 `finally` 块可能会引发自己的 [NullReferenceException](https://docs.microsoft.com/zh-cn/dotnet/api/system.nullreferenceexception)，但是在可能时应避免在 `finally` 块中引发异常。

数据库连接是在 `finally` 块中进行关闭的另一个很好的候选项。 因为与数据库服务器之间的允许连接数有时会受到限制，所以应尽快关闭数据库连接。 如果在可以关闭连接之前引发异常，则这是使用 `finally` 块比等待垃圾回收更好的另一种情况。

## [How to: Catch a non-CLS Exception](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/exceptions/how-to-catch-a-non-cls-exception)

包括 C++/CLI 在内的某些 .NET 语言允许对象引发并非派生自 [Exception](https://docs.microsoft.com/zh-cn/dotnet/api/system.exception) 的异常。 这类异常被称为非 CLS 异常或非异常。 无法在 C# 中引发非 CLS 异常，但有两种方式可以捕获它们：

- 在 `catch (RuntimeWrappedException e)` 块内捕获。

  默认情况下，Visual C# 程序集将非 CLS 异常作为包装的异常捕获。 如需访问原始异常（可通过 [RuntimeWrappedException.WrappedException](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.compilerservices.runtimewrappedexception.wrappedexception) 属性访问），请使用此方法。 本主题的后续过程将解释如何通过此方式捕获异常。

- 在位于所有其他 `catch` 块之后的常规 catch 块（未指定异常类型的 catch 块）之中。

  如果为了响应非 CLS 异常需要执行某些操作（如写入日志文件），且无需访问异常信息时，请使用此方法。默认情况下，公共语言运行时包装所有异常。 要禁用此行为，请将此程序集级别属性添加到代码中，通常位于 AssemblyInfo.cs 文件：`[assembly: RuntimeCompatibilityAttribute(WrapNonExceptionThrows = false)]`。

### 要捕捉非 CLS 异常

在 `catch(RuntimeWrappedException e)` 块中通过 [RuntimeWrappedException.WrappedException](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.compilerservices.runtimewrappedexception.wrappedexception) 属性访问原始异常。

## 示例

下面示例显示如何捕捉以 C++/CLI 编写的类库所引发的非 CLS 异常。 请注意，在此示例中，C# 客户端代码预先已知被引发的异常类型是 [System.String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string)。 可将 [RuntimeWrappedException.WrappedException](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.compilerservices.runtimewrappedexception.wrappedexception) 属性转换回其原始类型，前提是可从代码访问该类型。

```csharp
// Class library written in C++/CLI.
var myClass = new ThrowNonCLS.Class1();

try
{
    // throws gcnew System::String(  
    // "I do not derive from System.Exception!");  
    myClass.TestThrow();
}
catch (RuntimeWrappedException e)
{
    String s = e.WrappedException as String;
    if (s != null)
    {
        Console.WriteLine(s);
    }
}
```

)