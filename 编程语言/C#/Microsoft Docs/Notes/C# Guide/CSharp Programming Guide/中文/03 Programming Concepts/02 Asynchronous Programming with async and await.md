# [Programming Concepts](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/)

## [Asynchronous Programming with async and await](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/async/)

通过使用异步编程，你可以避免性能瓶颈并增强应用程序的总体响应能力。 但是，编写异步应用程序的传统技术可能比较复杂，使它们难以编写、调试和维护。

[C# 5](https://docs.microsoft.com/zh-cn/dotnet/csharp/whats-new/csharp-version-history#c-version-50) 引入了一种简便方法，即异步编程。此方法利用了 .NET Framework 4.5 及更高版本、.NET Core 和 Windows 运行时中的异步支持。 编译器可执行开发人员曾进行的高难度工作，且应用程序保留了一个类似于同步代码的逻辑结构。 因此，你只需做一小部分工作就可以获得异步编程的所有好处。

本主题概述了何时以及如何使用异步编程，并包括指向包含详细信息和示例的支持主题的链接。

### 异步编程提升响应能力

异步对可能会被屏蔽的活动（如 Web 访问）至关重要。 对 Web 资源的访问有时很慢或会延迟。 如果此类活动在同步过程中被屏蔽，整个应用必须等待。 在异步过程中，应用程序可继续执行不依赖 Web 资源的其他工作，直至潜在阻止任务完成。

下表显示了异步编程提高响应能力的典型区域。 列出的 .NET 和 Windows 运行时 API 包含支持异步编程的方法。

| 应用程序区域 | 包含异步方法的 .NET 类型                                     | 包含异步方法的 Windows 运行时类型                            |
| ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Web 访问     | [HttpClient](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.http.httpclient) | [SyndicationClient](https://docs.microsoft.com/zh-cn/uwp/api/windows.web.syndication.syndicationclient) |
| 使用文件     | [StreamWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.streamwriter), [StreamReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.streamreader), [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) | [StorageFile](https://docs.microsoft.com/zh-cn/uwp/api/windows.storage.storagefile) |
| 使用图像     |                                                              | [MediaCapture](https://docs.microsoft.com/zh-cn/uwp/api/windows.media.capture.mediacapture), [BitmapEncoder](https://docs.microsoft.com/zh-cn/uwp/api/windows.graphics.imaging.bitmapencoder), [BitmapDecoder](https://docs.microsoft.com/zh-cn/uwp/api/windows.graphics.imaging.bitmapdecoder) |
| WCF 编程     | [同步和异步操作](https://docs.microsoft.com/zh-cn/dotnet/framework/wcf/synchronous-and-asynchronous-operations) |                                                              |

由于所有与用户界面相关的活动通常共享一个线程，因此，异步对访问 UI 线程的应用程序来说尤为重要。 如果任何进程在同步应用程序中受阻，则所有进程都将受阻。 你的应用程序停止响应，因此，你可能在其等待过程中认为它已经失败。

使用异步方法时，应用程序将继续响应 UI。 例如，你可以调整窗口的大小或最小化窗口；如果你不希望等待应用程序结束，则可以将其关闭。

当设计异步操作时，该基于异步的方法将自动传输的等效对象添加到可从中选择的选项列表中。 开发人员只需要投入较少的工作量即可使你获取传统异步编程的所有优点。

### 异步方法更容易编写

C# 中的 [Async](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/async) 和 [Await](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/await) 关键字是异步编程的核心。 通过这两个关键字，可以使用 .NET Framework、.NET Core 或 Windows 运行时中的资源，轻松创建异步方法（几乎与创建同步方法一样轻松）。 使用 `async` 关键字定义的异步方法简称为“异步方法”。

下面的示例演示了一种异步方法。 你应对代码中的几乎所有内容都非常熟悉。 注释调出你添加的用来创建异步的功能。

本主题的末尾提供完整的 Windows Presentation Foundation (WPF) 示例文件，可以从[异步示例：“使用 Async 和 Await 的异步编程”示例](https://code.msdn.microsoft.com/Async-Sample-Example-from-9b9f505c)下载此示例。

```csharp
// Three things to note in the signature:  
//  - The method has an async modifier.   
//  - The return type is Task or Task<T>. (See "Return Types" section.)  
//    Here, it is Task<int> because the return statement returns an integer.  
//  - The method name ends in "Async."  
async Task<int> AccessTheWebAsync()  
{   
    // You need to add a reference to System.Net.Http to declare client.  
    using (HttpClient client = new HttpClient())  
    {  
        // GetStringAsync returns a Task<string>. That means that when you await the  
        // task you'll get a string (urlContents).  
        Task<string> getStringTask = client.GetStringAsync("https://docs.microsoft.com");  
  
        // You can do work here that doesn't rely on the string from GetStringAsync.  
        DoIndependentWork();  
  
        // The await operator suspends AccessTheWebAsync.  
        //  - AccessTheWebAsync can't continue until getStringTask is complete.  
        //  - Meanwhile, control returns to the caller of AccessTheWebAsync.  
        //  - Control resumes here when getStringTask is complete.   
        //  - The await operator then retrieves the string result from getStringTask.  
        string urlContents = await getStringTask;  
  
        // The return statement specifies an integer result.  
        // Any methods that are awaiting AccessTheWebAsync retrieve the length value.  
        return urlContents.Length;  
    }  
}  
```

如果 `AccessTheWebAsync` 在调用 `GetStringAsync` 和等待其完成期间不能进行任何工作，则你可以通过在下面的单个语句中调用和等待来简化代码。

```csharp
string urlContents = await client.GetStringAsync("https://docs.microsoft.com");  
```

以下特征总结了使上一个示例成为异步方法的原因。

- 方法签名包含 `async` 修饰符。

- 按照约定，异步方法的名称以“Async”后缀结尾。

- 返回类型为下列类型之一：

  - 如果你的方法有操作数为 `TResult` 类型的返回语句，则为 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1)。
  - 如果你的方法没有返回语句或具有没有操作数的返回语句，则为 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task)。
  - `void`：如果要编写异步事件处理程序。
  - 包含 `GetAwaiter` 方法的其他任何类型（自 C# 7.0 起）。

  有关详细信息，请参阅[返回类型和参数](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/#BKMK_ReturnTypesandParameters)部分。

- 方法通常包含至少一个 await 表达式，该表达式标记一个点，在该点上，直到等待的异步操作完成方法才能继续。 同时，将方法挂起，并且控件返回到方法的调用方。 本主题的下一节将解释悬挂点发生的情况。

在异步方法中，可使用提供的关键字和类型来指示需要完成的操作，且编译器会完成其余操作，其中包括持续跟踪控件以挂起方法返回等待点时发生的情况。 一些常规流程（例如，循环和异常处理）在传统异步代码中处理起来可能很困难。 在异步方法中，元素的编写频率与同步解决方案相同且此问题得到解决。

若要详细了解旧版 .NET Framework 中的异步性，请参阅 [TPL 和传统 .NET Framework 异步编程](https://docs.microsoft.com/zh-cn/dotnet/standard/parallel-programming/tpl-and-traditional-async-programming)。

### 异步方法的运行机制

异步编程中最需弄清的是控制流是如何从方法移动到方法的。 下图可引导你完成该过程。

![跟踪异步程序](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/media/navigationtrace.png)

关系图中的数值对应于以下步骤。

1. 事件处理程序调用并等待 `AccessTheWebAsync` 异步方法。

2. `AccessTheWebAsync` 可创建 [HttpClient](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.http.httpclient) 实例并调用 [GetStringAsync](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.http.httpclient.getstringasync) 异步方法以下载网站内容作为字符串。

3. `GetStringAsync` 中发生了某种情况，该情况挂起了它的进程。 可能必须等待网站下载或一些其他阻止活动。 为避免阻止资源，`GetStringAsync` 会将控制权出让给其调用方 `AccessTheWebAsync`。

   `GetStringAsync` 返回 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1)，其中 `TResult` 为字符串，并且 `AccessTheWebAsync` 将任务分配给 `getStringTask` 变量。 该任务表示调用 `GetStringAsync` 的正在进行的进程，其中承诺当工作完成时产生实际字符串值。

4. 由于尚未等待 `getStringTask`，因此，`AccessTheWebAsync` 可以继续执行不依赖于 `GetStringAsync` 得出的最终结果的其他工作。 该任务由对同步方法 `DoIndependentWork` 的调用表示。

5. `DoIndependentWork` 是完成其工作并返回其调用方的同步方法。

6. `AccessTheWebAsync` 已用完工作，可以不受 `getStringTask` 的结果影响。 接下来，`AccessTheWebAsync` 需要计算并返回该下载字符串的长度，但该方法仅在具有字符串时才能计算该值。

   因此，`AccessTheWebAsync` 使用一个 await 运算符来挂起其进度，并把控制权交给调用 `AccessTheWebAsync`的方法。 `AccessTheWebAsync` 将 `Task<int>` 返回给调用方。 该任务表示对产生下载字符串长度的整数结果的一个承诺。

   > 如果 `GetStringAsync`（因此 `getStringTask`）在 `AccessTheWebAsync` 等待前完成，则控制会保留在 `AccessTheWebAsync` 中。 如果异步调用过程 (`getStringTask`) 已完成，并且 `AccessTheWebSync` 不必等待最终结果，则挂起然后返回到 `AccessTheWebAsync` 将造成成本浪费。

   在调用方内部（此示例中的事件处理程序），处理模式将继续。 在等待结果前，调用方可以开展不依赖于 `AccessTheWebAsync` 结果的其他工作，否则就需等待片刻。 事件处理程序等待 `AccessTheWebAsync`，而 `AccessTheWebAsync` 等待 `GetStringAsync`。

7. `GetStringAsync` 完成并生成一个字符串结果。 字符串结果不是通过按你预期的方式调用 `GetStringAsync` 所返回的。 （记住，该方法已返回步骤 3 中的一个任务）。相反，字符串结果存储在表示 `getStringTask` 方法完成的任务中。 await 运算符从 `getStringTask` 中检索结果。 赋值语句将检索到的结果赋给 `urlContents`。

8. 当 `AccessTheWebAsync` 具有字符串结果时，该方法可以计算字符串长度。 然后，`AccessTheWebAsync` 工作也将完成，并且等待事件处理程序可继续使用。 在此主题结尾处的完整示例中，可确认事件处理程序检索并打印长度结果的值。
   如果你不熟悉异步编程，请花 1 分钟时间考虑同步行为和异步行为之间的差异。 当其工作完成时（第 5 步）会返回一个同步方法，但当其工作挂起时（第 3 步和第 6 步），异步方法会返回一个任务值。 在异步方法最终完成其工作时，任务会标记为已完成，而结果（如果有）将存储在任务中。

若要详细了解控制流，请参阅[异步程序中的控制流 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/control-flow-in-async-programs)。

### API 异步方法

你可能想知道从何处可以找到 `GetStringAsync` 等支持异步编程的方法。 .NET Framework 4.5 或更高版本以及 .NET Core 包含许多可与 `async` 和 `await` 结合使用的成员。 可以通过追加到成员名称的“Async”后缀和 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task) 或 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1) 的返回类型，识别这些成员。 例如，`System.IO.Stream` 类包含 [CopyToAsync](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.stream.copytoasync)、[ReadAsync](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.stream.readasync) 和 [WriteAsync](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.stream.writeasync) 等方法，以及同步方法 [CopyTo](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.stream.copyto)、[Read](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.stream.read) 和 [Write](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.stream.write)。

Windows 运行时也包含许多可以在 Windows 应用中与 `async` 和 `await` 结合使用的方法。 有关详细信息，请参阅[线程处理和异步编程](https://docs.microsoft.com/zh-cn/windows/uwp/threading-async/)进行 UWP 开发；如果使用的是旧版 Windows 运行时，还请参阅[异步编程（Windows 应用商店应用）](https://docs.microsoft.com/previous-versions/windows/apps/hh464924(v=win.10))和[快速入门：在 C# 或 Visual Basic 中调用异步 API](https://docs.microsoft.com/previous-versions/windows/apps/hh452713(v=win.10))。

### 线程

异步方法旨在成为非阻止操作。 异步方法中的 `await` 表达式在等待的任务正在运行时不会阻止当前线程。 相反，表达式在继续时注册方法的其余部分并将控件返回到异步方法的调用方。

`async` 和 `await` 关键字不会创建其他线程。 因为异步方法不会在其自身线程上运行，因此它不需要多线程。 只有当方法处于活动状态时，该方法将在当前同步上下文中运行并使用线程上的时间。 可以使用 [Task.Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task.run) 将占用大量 CPU 的工作移到后台线程，但是后台线程不会帮助正在等待结果的进程变为可用状态。

对于异步编程而言，该基于异步的方法优于几乎每个用例中的现有方法。 具体而言，此方法比 [BackgroundWorker](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.backgroundworker) 类更适用于 I/O 绑定操作，因为此代码更简单且无需防止争用条件。 结合 [Task.Run](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task.run) 方法使用时，异步编程比 [BackgroundWorker](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.backgroundworker) 更适用于 CPU 绑定操作，因为异步编程将运行代码的协调细节与 `Task.Run`传输至线程池的工作区分开来。

### async 和 await

如果使用 [async](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/async) 修饰符将某种方法指定为异步方法，即启用以下两种功能。

- 标记的异步方法可以使用 [await](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/await) 来指定暂停点。 `await` 运算符通知编译器异步方法：在等待的异步过程完成后才能继续通过该点。 同时，控制返回至异步方法的调用方。

  异步方法在 `await` 表达式执行时暂停并不构成方法退出，只会导致 `finally` 代码块不运行。

- 标记的异步方法本身可以通过调用它的方法等待。

异步方法通常包含 `await` 运算符的一个或多个实例，但缺少 `await` 表达式也不会导致生成编译器错误。 如果异步方法未使用 `await` 运算符标记暂停点，那么异步方法会作为同步方法执行，即使有 `async` 修饰符，也不例外。 编译器将为此类方法发布一个警告。

`async` 和 `await` 都是上下文关键字。 有关更多信息和示例，请参见以下主题：

- [async](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/async)
- [await](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/await)

### 返回类型和参数

异步方法通常返回 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task) 或 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1)。 在异步方法中，`await` 运算符应用于通过调用另一个异步方法返回的任务。

如果方法包含指定 `TResult` 类型操作数的 [return](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/return) 语句，将 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1) 指定为返回类型。

如果方法不含任何 return 语句或包含不返回操作数的 return 语句，将 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task) 用作返回类型。

自 C# 7.0 起，还可以指定任何其他返回类型，前提是类型包含 `GetAwaiter` 方法。 例如，[ValueTask](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.valuetask-1) 就是这种类型。 可用于 [System.Threading.Tasks.Extension](https://www.nuget.org/packages/System.Threading.Tasks.Extensions/) NuGet 包。

下面的示例演示如何声明并调用可返回 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1) 或 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task) 的方法。

```csharp
// Signature specifies Task<TResult>  
async Task<int> GetTaskOfTResultAsync()  
{  
    int hours = 0;  
    await Task.Delay(0);  
    // Return statement specifies an integer result.  
    return hours;  
}  
  
// Calls to GetTaskOfTResultAsync  
Task<int> returnedTaskTResult = GetTaskOfTResultAsync();  
int intResult = await returnedTaskTResult;  
// or, in a single statement  
int intResult = await GetTaskOfTResultAsync();  
  
// Signature specifies Task  
async Task GetTaskAsync()  
{  
    await Task.Delay(0);  
    // The method has no return statement.    
}  
  
// Calls to GetTaskAsync  
Task returnedTask = GetTaskAsync();  
await returnedTask;  
// or, in a single statement  
await GetTaskAsync();  
```

每个返回的任务表示正在进行的工作。 任务可封装有关异步进程状态的信息，如果未成功，则最后会封装来自进程的最终结果或进程引发的异常。

异步方法也可以具有 `void` 返回类型。 该返回类型主要用于定义需要 `void` 返回类型的事件处理程序。 异步事件处理程序通常用作异步程序的起始点。

无法等待具有 `void` 返回类型的异步方法，并且无效返回方法的调用方捕获不到异步方法抛出的任何异常。

异步方法无法声明 [in](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/in-parameter-modifier)、[ref](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/ref) 或 [out](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/out-parameter-modifier) 参数，但可以调用包含此类参数的方法。 同样，异步方法无法通过引用返回值，但可以调用包含 ref 返回值的方法。

有关详细信息和示例，请参阅[异步返回类型 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/async-return-types)。 若要详细了解如何在异步方法中捕获异常，请参阅 [try-catch](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/try-catch)。

Windows 运行时编程中的异步 API 具有下列返回类型之一（类似于任务）：

- [IAsyncOperation](https://docs.microsoft.com/zh-cn/uwp/api/windows.foundation.iasyncoperation_tresult_)（对应于 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1)）
- [IAsyncAction](https://docs.microsoft.com/zh-cn/uwp/api/windows.foundation.iasyncaction)（对应于 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task)）
- [IAsyncActionWithProgress](https://docs.microsoft.com/zh-cn/uwp/api/windows.foundation.iasyncactionwithprogress_tprogress_)
- [IAsyncOperationWithProgress](https://docs.microsoft.com/zh-cn/uwp/api/windows.foundation.iasyncoperationwithprogress_tresult_tprogress_)

### 命名约定

按照约定，将“Async”追加到包含 `async` 修饰符的方法的名称中。

如果某一约定中的事件、基类或接口协定建议其他名称，则可以忽略此约定。 例如，你不应重命名常用事件处理程序，例如 `Button1_Click`。

### 相关主题和示例 (Visual Studio)

| 标题                                                         | 说明                                                         | 示例                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| [演练：使用 Async 和 Await 访问 Web (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/walkthrough-accessing-the-web-by-using-async-and-await) | 演示如何将一个同步 WPF 解决方案转换成一个异步 WPF 解决方案。 应用程序下载一系列网站。 | [异步示例：“访问 Web”演练](https://code.msdn.microsoft.com/Async-Sample-Accessing-the-9c10497f) |
| [如何：使用 Task.WhenAll 扩展异步演练 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/how-to-extend-the-async-walkthrough-by-using-task-whenall) | 将 [Task.WhenAll](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task.whenall) 添加到上一个演练。 使用 `WhenAll` 同时启动所有下载。 |                                                              |
| [如何：使用 Async 和 Await 并行发出多个 Web 请求 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/how-to-make-multiple-web-requests-in-parallel-by-using-async-and-await) | 演示如何同时开始几个任务。                                   | [异步示例：并行发出多个 Web 请求](https://code.msdn.microsoft.com/Async-Make-Multiple-Web-49adb82e) |
| [异步返回类型 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/async-return-types) | 描述异步方法可返回的类型，并解释每种类型适用于的情况。       |                                                              |
| [异步程序中的控制流 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/control-flow-in-async-programs) | 通过异步程序中的一系列 await 表达式来详细跟踪控制流。        | [异步示例：异步程序中的控制流](https://code.msdn.microsoft.com/Async-Sample-Control-Flow-5c804fc0) |
| [微调异步应用程序 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/fine-tuning-your-async-application) | 演示如何将以下功能添加到异步解决方案：  - [取消一个异步任务或一组任务(C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/cancel-an-async-task-or-a-list-of-tasks) - [在一段时间后取消异步任务 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/cancel-async-tasks-after-a-period-of-time) - [在完成一个异步任务后取消剩余任务 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/cancel-remaining-async-tasks-after-one-is-complete) - [启动多个异步任务并在其完成时进行处理 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/start-multiple-async-tasks-and-process-them-as-they-complete) | [异步示例：微调应用程序](https://code.msdn.microsoft.com/Async-Fine-Tuning-Your-a676abea) |
| [在异步应用程序中处理重入 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/handling-reentrancy-in-async-apps) | 演示如何处理有效的异步操作在运行时重启的情况。               |                                                              |
| [WhenAny：综合运用 .NET Framework 和 Windows 运行时](https://docs.microsoft.com/previous-versions/visualstudio/visual-studio-2013/jj635140(v=vs.120)) | 展示了如何桥接 .NET Framework 与 Windows 运行时中 IAsyncOperations 的任务类型，以便可以将 [WhenAny](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task.whenany) 与 Windows 运行时 方法结合使用。 | [异步示例：综合运用 .NET 和 Windows 运行时（AsTask 和 WhenAny）](https://code.msdn.microsoft.com/Async-Sample-Bridging-d6a2f739) |
| 异步取消：综合运用 .NET Framework 和 Windows 运行时          | 展示了如何桥接 .NET Framework 与 Windows 运行时中 IAsyncOperations 的任务类型，以便可以将 [CancellationTokenSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.cancellationtokensource) 与 Windows 运行时 方法结合使用。 | [异步示例：综合运用 .NET 和 Windows 运行时（AsTask 和 Cancellation）](https://code.msdn.microsoft.com/Async-Sample-Bridging-9479eca3) |
| [使用 Async 进行文件访问 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/using-async-for-file-access) | 列出并演示使用 async 和 await 访问文件的好处。               |                                                              |
| [基于任务的异步模式 (TAP)](https://docs.microsoft.com/zh-cn/dotnet/standard/asynchronous-programming-patterns/task-based-asynchronous-pattern-tap) | 描述 .NET Framework 中异步的新模式。 该模式基于 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task) 和 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1) 类型。 |                                                              |
| [Channel 9 上的异步相关视频](https://channel9.msdn.com/search?term=async%20&type=All#pubDate=year&ch9Search&lang-en=en) | 提供指向有关异步编程的各种视频的链接。                       |                                                              |

### 完整示例

下面的代码来自于本主题介绍的 Windows Presentation Foundation (WPF) 应用程序的 MainWindow.xaml.cs 文件。 可以从[异步示例：“使用 Async 和 Await 的异步编程”示例](https://code.msdn.microsoft.com/Async-Sample-Example-from-9b9f505c)下载此示例。

```csharp
using System;  
using System.Collections.Generic;  
using System.Linq;  
using System.Text;  
using System.Threading.Tasks;  
using System.Windows;  
using System.Windows.Controls;  
using System.Windows.Data;  
using System.Windows.Documents;  
using System.Windows.Input;  
using System.Windows.Media;  
using System.Windows.Media.Imaging;  
using System.Windows.Navigation;  
using System.Windows.Shapes;  
  
// Add a using directive and a reference for System.Net.Http;  
using System.Net.Http;  
  
namespace AsyncFirstExample  
{  
    public partial class MainWindow : Window  
    {  
        // Mark the event handler with async so you can use await in it.  
        private async void StartButton_Click(object sender, RoutedEventArgs e)  
        {  
            // Call and await separately.  
            //Task<int> getLengthTask = AccessTheWebAsync();  
            //// You can do independent work here.  
            //int contentLength = await getLengthTask;  
  
            int contentLength = await AccessTheWebAsync();  
  
            resultsTextBox.Text +=
                $"\r\nLength of the downloaded string: {contentLength}.\r\n";
        }  
  
        // Three things to note in the signature:  
        //  - The method has an async modifier.   
        //  - The return type is Task or Task<T>. (See "Return Types" section.)  
        //    Here, it is Task<int> because the return statement returns an integer.  
        //  - The method name ends in "Async."  
        async Task<int> AccessTheWebAsync()  
        {   
            // You need to add a reference to System.Net.Http to declare client.  
            using (HttpClient client = new HttpClient())  
            {  
                    // GetStringAsync returns a Task<string>. That means that when you await the  
                    // task you'll get a string (urlContents).  
                    Task<string> getStringTask = client.GetStringAsync("https://docs.microsoft.com");  
  
                    // You can do work here that doesn't rely on the string from GetStringAsync.  
                    DoIndependentWork();  
  
                    // The await operator suspends AccessTheWebAsync.  
                    //  - AccessTheWebAsync can't continue until getStringTask is complete.  
                    //  - Meanwhile, control returns to the caller of AccessTheWebAsync.  
                    //  - Control resumes here when getStringTask is complete.   
                    //  - The await operator then retrieves the string result from getStringTask.  
                    string urlContents = await getStringTask;  
  
                    // The return statement specifies an integer result.  
                    // Any methods that are awaiting AccessTheWebAsync retrieve the length value.  
                    return urlContents.Length;  
            }  
        }  
  
        void DoIndependentWork()  
        {  
            resultsTextBox.Text += "Working . . . . . . .\r\n";  
        }  
    }  
}  
  
// Sample Output:  
  
// Working . . . . . . .  
  
// Length of the downloaded string: 25035.  
```

### [Walkthrough: Accessing the Web by Using async and await](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/async/walkthrough-accessing-the-web-by-using-async-and-await)

使用 async/await 功能可以更轻松直观地编写异步程序。 你可以编写类似于同步代码的异步代码，并让编译器处理异步代码通常需要的疑难回调函数和延续。

有关 Async 功能的详细信息，请参阅[使用 Async 和 Await 的异步编程 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/index)。

本演练从对网站列表中的字节数进行求和的同步 Windows Presentation Foundation (WPF) 应用程序入手， 然后使用新功能将该应用程序转换为异步解决方案。

如果不想自行生成应用程序，可以下载 [异步示例：访问 Web 演练（C# 和 Visual Basic）](https://code.msdn.microsoft.com/Async-Sample-Accessing-the-9c10497f)

> 若要运行该示例，计算机上必须安装有 Visual Studio 2012 或更高版本和 .NET Framework 4.5 或更高版本。

#### 创建 WPF 应用程序

1. 启动 Visual Studio。

2. 在菜单栏上，依次选择“文件” > “新建” > “项目”。

   **“新建项目”** 对话框随即打开。

3. 在“已安装的模板”窗格中，选择“Visual C#”，然后从项目类型列表选择“WPF 应用程序”。

4. 在“名称”文本框中，输入 `AsyncExampleWPF`，然后选择“确定”按钮。

   新项目将出现在“解决方案资源管理器”中。

####  设计简单的 WPF MainWindow

1. 在 Visual Studio 代码编辑器中，选择 **“MainWindow.xaml”** 选项卡。

2. 如果“工具箱”窗口不可见，则打开“视图”菜单，然后选择“工具箱”。

3. 向“MainWindow”窗口添加一个“Button”控件和一个“TextBox”控件。

4. 突出显示“TextBox”控件，在“属性”窗口中，设置下列值：

   - 将“名称”属性设置为 `resultsTextBox`。
   - 将“高度”属性设置为 250。
   - 将“宽度”属性设置为 500。
   - 在“文本”选项卡中，指定等宽字体，例如 Lucida Console 或 Global Monospace。

5. 突出显示“Button”控件，在“属性”窗口中，设置下列值：

   - 将“名称”属性设置为 `startButton`。
   - 将“内容”属性的值从“Button”更改为“Start”。

6. 确定文本框和按钮的位置，以便它们都在“MainWindow”窗口中显示。

   有关 WPF XAML 设计器的详细信息，请参阅[使用 XAML 设计器创建 UI](https://docs.microsoft.com/zh-cn/visualstudio/designers/creating-a-ui-by-using-xaml-designer-in-visual-studio)。

####  添加引用

1. 在“解决方案资源管理器”中，突出显示项目的名称。

2. 在菜单栏上，选择“项目” > “添加引用”。

   此时将显示“引用管理器”对话框。

3. 在对话框顶部，验证项目是否以 .NET Framework 4.5 或更高版本为目标。

4. 在“程序集”类别中，选择“Framework”（如果尚未选择它）。

5. 在名称列表中，选中“System.Net.Http”复选框。

6. 选择“确定”按钮关闭对话框。

####  添加必要的 using 指令

1. 在“解决方案资源管理器”中，打开 MainWindow.xaml.cs 的快捷菜单，然后选择“查看代码”。

2. 将下列 `using` 指令添加到代码文件的顶部（如果它们尚不存在）。

   C#复制

   ```csharp
   using System.Net.Http;
   using System.Net;
   using System.IO;
   ```

####  创建同步应用

1. 在设计窗口 MainWindow.xaml 中，双击“启动”按钮以在 MainWindow.xaml.cs 中创建 `startButton_Click` 事件处理程序。

2. 在 MainWindow.xaml.cs 中，将下列代码复制到 `startButton_Click` 的正文中：

   ```csharp
   resultsTextBox.Clear();
   SumPageSizes();
   resultsTextBox.Text += "\r\nControl returned to startButton_Click.";
   ```

   代码调用驱动应用程序 `SumPageSizes` 的方法，并在控件返回到 `startButton_Click` 时显示一条消息。

3. 该同步解决方案的代码包含以下四个方法：

   - `SumPageSizes`，从 `SetUpURLList` 获取网页 URL 列表并随后调用 `GetURLContents` 和 `DisplayResults`以处理每个 URL。
   - `SetUpURLList`，生成并返回 Web 地址列表。
   - `GetURLContents`，下载每个网站的内容并将内容作为字节数组返回。
   - `DisplayResults`，显示每个 URL 的字节数组中的字节数。

   复制以下四个方法，然后将它们粘贴在 MainWindow.xaml.cs 中的 `startButton_Click` 事件处理程序下：

   ```csharp
   private void SumPageSizes()
   {
       // Make a list of web addresses.
       List<string> urlList = SetUpURLList();
   
       var total = 0;
       foreach (var url in urlList)
       {
           // GetURLContents returns the contents of url as a byte array.
           byte[] urlContents = GetURLContents(url);
   
           DisplayResults(url, urlContents);
   
           // Update the total.
           total += urlContents.Length;
       }
   
       // Display the total count for all of the web addresses.
       resultsTextBox.Text += $"\r\n\r\nTotal bytes returned:  {total}\r\n";
   }
   
   private List<string> SetUpURLList()
   {
       var urls = new List<string>
       {
           "https://msdn.microsoft.com/library/windows/apps/br211380.aspx",
           "https://msdn.microsoft.com",
           "https://msdn.microsoft.com/library/hh290136.aspx",
           "https://msdn.microsoft.com/library/ee256749.aspx",
           "https://msdn.microsoft.com/library/hh290138.aspx",
           "https://msdn.microsoft.com/library/hh290140.aspx",
           "https://msdn.microsoft.com/library/dd470362.aspx",
           "https://msdn.microsoft.com/library/aa578028.aspx",
           "https://msdn.microsoft.com/library/ms404677.aspx",
           "https://msdn.microsoft.com/library/ff730837.aspx"
       };
       return urls;
   }
   
   private byte[] GetURLContents(string url)
   {
       // The downloaded resource ends up in the variable named content.
       var content = new MemoryStream();
   
       // Initialize an HttpWebRequest for the current URL.
       var webReq = (HttpWebRequest)WebRequest.Create(url);
   
       // Send the request to the Internet resource and wait for
       // the response.
       // Note: you can't use HttpWebRequest.GetResponse in a Windows Store app.
       using (WebResponse response = webReq.GetResponse())
       {
           // Get the data stream that is associated with the specified URL.
           using (Stream responseStream = response.GetResponseStream())
           {
               // Read the bytes in responseStream and copy them to content.
               responseStream.CopyTo(content);
           }
       }
   
       // Return the result as a byte array.
       return content.ToArray();
   }
   
   private void DisplayResults(string url, byte[] content)
   {
       // Display the length of each website. The string format
       // is designed to be used with a monospaced font, such as
       // Lucida Console or Global Monospace.
       var bytes = content.Length;
       // Strip off the "https://".
       var displayURL = url.Replace("https://", "");
       resultsTextBox.Text += $"\n{displayURL,-58} {bytes,8}";
   }
   ```

####  测试同步解决方案

按 F5 键运行程序，然后选择“启动”按钮。

此时应显示类似于以下列表的输出：

```text
msdn.microsoft.com/library/windows/apps/br211380.aspx        383832
msdn.microsoft.com                                            33964
msdn.microsoft.com/library/hh290136.aspx               225793
msdn.microsoft.com/library/ee256749.aspx               143577
msdn.microsoft.com/library/hh290138.aspx               237372
msdn.microsoft.com/library/hh290140.aspx               128279
msdn.microsoft.com/library/dd470362.aspx               157649
msdn.microsoft.com/library/aa578028.aspx               204457
msdn.microsoft.com/library/ms404677.aspx               176405
msdn.microsoft.com/library/ff730837.aspx               143474

Total bytes returned:  1834802

Control returned to startButton_Click.
```

请注意，显示计数需要几秒钟时间。 与此同时，在等待请求的资源下载时，UI 线程处于被阻止状态。 因此，选择“启动”按钮后，将无法移动、最大化、最小化显示窗口，甚至也无法关闭显示窗口。 在字节计数开始显示之前，这些操作都会失败。 如果网站没有响应，将不会指示哪个网站失败。 甚至停止等待和关闭程序也会很困难。

####  将 GetURLContents 转换为异步方法

1. 要将同步解决方案转换为异步解决方案，最佳着手点在 `GetURLContents` 中，因为对 [HttpWebRequest](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.httpwebrequest) 方法 [GetResponse](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.httpwebrequest.getresponse) 的调用以及对 [Stream](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.stream) 方法 [CopyTo](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.stream.copyto) 的调用是应用程序访问 Web 的位置。 .NET Framework 提供两种方法的异步版本，这让转换变得轻松。

   有关 `GetURLContents` 中使用的方法的详细信息，请参阅 [WebRequest](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.webrequest)。

   > 在你按照本演练中的步骤进行操作的过程中，将出现多个编译器错误。 你可以忽略这些错误并继续演练。

   将在 `GetURLContents` 的第三行中调用的方法从 `GetResponse` 更改为基于任务的异步 [GetResponseAsync](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.webrequest.getresponseasync) 方法。

   ```csharp
   using (WebResponse response = webReq.GetResponseAsync())
   ```

2. `GetResponseAsync` 返回 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1)。 在这种情况下，任务返回变量 `TResult` 具有类型 [WebResponse](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.webresponse)。该任务是在请求的任务已下载且任务已完成运行后，生成实际 `WebResponse` 对象的承诺。

   要从任务检索 `WebResponse` 值，请将 [await](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/await) 运算符应用到对 `GetResponseAsync` 的调用，如下列代码所示。

   ```csharp
   using (WebResponse response = await webReq.GetResponseAsync())
   ```

   `await` 运算符将当前方法 `GetURLContents` 的执行挂起，直到完成等待的任务为止。 同时，控制权返回给当前方法的调用方。 在此示例中，当前方法是 `GetURLContents`，调用方是 `SumPageSizes`。 任务完成时，承诺的 `WebResponse` 对象作为等待的任务的值生成，并分配给变量 `response`。

   上一条语句可以分为以下两条语句，以阐明所发生的情况。

   ```csharp
   //Task<WebResponse> responseTask = webReq.GetResponseAsync();
   //using (WebResponse response = await responseTask)
   ```

   对 `webReq.GetResponseAsync` 的调用返回 `Task(Of WebResponse)` 或 `Task<WebResponse>`。 然后，await 运算符将应用于任务以检索 `WebResponse` 值。

   如果你的异步方法需要完成不依赖于任务的完成的工作，则在调用异步方法之后及应用 `await` 运算符之前的这段时间，该方法可以在这两个语句之间继续完成该工作。 有关示例，请参阅[如何：使用 Async 和 Await 并行发起多个 Web 请求 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/how-to-make-multiple-web-requests-in-parallel-by-using-async-and-await) 和[如何：使用 Task.WhenAll 扩展异步演练 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/how-to-extend-the-async-walkthrough-by-using-task-whenall)。

3. 因为在上一步中添加了 `await` 运算符，所以会发生编译器错误。 该运算符仅可在使用 [async](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/async) 修饰符标记的方法中使用。 当你重复转换步骤以使用对 `CopyToAsync` 的调用替换对 `CopyTo` 的调用时，请忽略该错误。

   - 更改被调用到 [CopyToAsync](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.stream.copytoasync) 的方法的名称。

   - `CopyTo` 或 `CopyToAsync` 方法复制字节到其参数 `content`，并且不返回有意义的值。 在同步版本中，对 `CopyTo` 的调用是不返回值的简单语句。 异步版本 `CopyToAsync` 返回 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task)。 任务函数类似“Task(void)”，并让该方法能够等待。 应用 `Await` 或 `await` 到对 `CopyToAsync` 的调用，如下列代码所示。

     ```csharp
     await responseStream.CopyToAsync(content);
     ```

     上一条语句缩写以下两行代码。

     ```csharp
     // CopyToAsync returns a Task, not a Task<T>.
     //Task copyTask = responseStream.CopyToAsync(content);
     
     // When copyTask is completed, content contains a copy of
     // responseStream.
     //await copyTask;
     ```

4. `GetURLContents` 中仍需要完成的操作是调整方法签名。 仅可在使用 [async](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/async) 修饰符标记的方法中使用 `await`运算符。 添加修饰符以将方法标记为*异步方法*，如下列代码所示。

   ```csharp
   private async byte[] GetURLContents(string url)
   ```

5. 异步方法的返回类型在 C# 中只能为 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task)、[Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1) 或 `void`。 通常情况下，`void` 的返回类型仅可在异步事件处理程序中使用，其中需要 `void`。 在其他情况下，如果完成的方法具有返回 T 类型的值的 [return](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/return) 语句，则使用 `Task(T)`；如果完成的方法不返回有意义的值，则使用 `Task`。 可以将 `Task` 返回类型视为表示“Task(void)”。

   有关详细信息，请参阅[异步返回类型 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/async-return-types)。

   方法 `GetURLContents` 具有 return 语句，且该语句返回字节数组。 因此，异步版本的返回类型为 Task(T)，其中 T 为字节数组。 在方法签名中进行下列更改：

   - 将返回类型更改为 `Task<byte[]>`。
   - 按照约定，异步方法的名称以“Async”结尾，因此，请重命名方法 `GetURLContentsAsync`。

   下列代码显示这些更改。

   ```csharp
   private async Task<byte[]> GetURLContentsAsync(string url)
   ```

   进行这几处更改后，`GetURLContents` 到异步方法的转换完成。

####  将 SumPageSizes 转换为异步方法

1. 为 `SumPageSizes` 重复之前过程中的步骤。 首先，将对 `GetURLContents` 的调用更改为异步调用。

   - 将调用的方法的名称从 `GetURLContents` 更改为 `GetURLContentsAsync`（如果尚未执行此操作）。
   - 将 `await` 应用到 `GetURLContentsAsync` 返回的任务，以便获取字节数组值。

   下列代码显示这些更改。

   ```csharp
   byte[] urlContents = await GetURLContentsAsync(url);
   ```

   上一个分配缩写以下两行代码。

   ```csharp
   // GetURLContentsAsync returns a Task<T>. At completion, the task
   // produces a byte array.
   //Task<byte[]> getContentsTask = GetURLContentsAsync(url);
   //byte[] urlContents = await getContentsTask;
   ```

2. 在方法签名中进行下列更改：

   - 使用 `async` 修饰符标记方法。
   - 将“Async”添加到方法名称。
   - 这一次没有任务返回变量 T，因为 `SumPageSizesAsync` 不返回 T 的值。（该方法没有 `return` 语句。）但是，该方法必须返回 `Task` 才能进行等待。 因此，将该方法的返回类型从 `void` 更改为 `Task`。

   下列代码显示这些更改。

   ```csharp
   private async Task SumPageSizesAsync()
   ```

   从 `SumPageSizes` 到 `SumPageSizesAsync` 的转换完成。

####  将 startButton_Click 转换为异步方法

1. 在事件处理程序中，将调用的方法的名称从 `SumPageSizes` 更改为 `SumPageSizesAsync`（如果尚未执行此操作）。

2. 由于 `SumPageSizesAsync` 是异步方法，请更改事件处理程序中的代码以等待结果。

   对 `SumPageSizesAsync` 的调用反射对 `GetURLContentsAsync` 中的 `CopyToAsync` 的调用。 调用返回的是 `Task`，而不是 `Task(T)`。

   与之前的过程一样，你可以使用一条语句或两条语句转换调用。 下列代码显示这些更改。

   ```csharp
   // One-step async call.
   await SumPageSizesAsync();
   
   // Two-step async call.
   //Task sumTask = SumPageSizesAsync();
   //await sumTask;
   ```

3. 要防止意外重新进入操作，请在 `startButton_Click` 顶部添加下列语句，以禁用“启动”按钮。

   ```csharp
   // Disable the button until the operation is complete.
   startButton.IsEnabled = false;
   ```

   可以重新启用事件处理程序末尾的按钮。

   ```csharp
   // Reenable the button in case you want to run the operation again.
   startButton.IsEnabled = true;
   ```

   有关重新进入的详细信息，请参阅[处理异步应用中的重新进入 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/handling-reentrancy-in-async-apps)。

4. 最后，将 `async` 修饰符添加到声明，以便事件处理程序可以等待 `SumPagSizesAsync`。

   ```csharp
   private async void startButton_Click(object sender, RoutedEventArgs e)
   ```

   通常情况下，事件处理程序的名称不会更改。 返回类型没有更改为 `Task`，因为事件处理程序必须返回 `void`。

   项目从同步处理到异步处理的转换完成。

####  测试异步解决方案

1. 按 F5 键运行程序，然后选择“启动”按钮。
2. 此时应显示类似于同步解决方案的输出的输出。 但是，请注意下列差异。
   - 处理完成后，所有结果不会同时出现。 例如，两个程序都在 `startButton_Click` 中包含一行可以清除文本框的代码。 目的在于，在一组结果显示后，第二次选择“启动”按钮时，可以清除运行之间的文本框。 在同步版本中，下载完成且 UI 线程可以自由完成其他工作时，文本框在计数第二次显示之前即被清除。 在异步版本中，选择“启动”按钮后立即清除文本框。
   - 最重要的是，UI 线程在下载过程中未被阻止。 在 Web 资源下载、计数和显示期间，可以移动窗口或调整窗口大小。 如果其中一个网站速度缓慢或没有响应，则可以通过选择“关闭”按钮取消操作（右上角红色字段中的 x）。

####  使用 .NET Framework 方法替换 GetURLContentsAsync

1. .NET Framework 4.5 提供可供你使用的许多异步方法。 其中一个是 [HttpClient](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.http.httpclient) 方法 [GetByteArrayAsync(String)](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.http.httpclient.getbytearrayasync#System_Net_Http_HttpClient_GetByteArrayAsync_System_String_)，它可以执行本演练所需的操作。 你可以使用它来替代你在早前过程中创建的 `GetURLContentsAsync` 方法。

   第一步是在方法 `SumPageSizesAsync` 中创建 `HttpClient` 对象。 在方法的开头添加下列声明。

   ```csharp
   // Declare an HttpClient object and increase the buffer size. The
   // default buffer size is 65,536.
   HttpClient client =
       new HttpClient() { MaxResponseContentBufferSize = 1000000 };
   ```

2. 在 `SumPageSizesAsync,` 中，使用对 `HttpClient` 方法的调用替换对 `GetURLContentsAsync` 方法的调用。

   ```csharp
   byte[] urlContents = await client.GetByteArrayAsync(url);
   ```

3. 删除或注释禁用你编写的 `GetURLContentsAsync` 方法。

4. 按 F5 键运行程序，然后选择“启动”按钮。

   此版本的项目的行为应与“测试异步解决方案”过程描述的行为匹配，且你的工作量应该更少。

####  示例代码

下列代码包含使用你编写的异步 `GetURLContentsAsync` 方法从同步解决方案转换为异步解决方案的完整示例。 请注意，它与原始同步解决方案十分类似。

```csharp
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

// Add the following using directives, and add a reference for System.Net.Http.
using System.Net.Http;
using System.IO;
using System.Net;

namespace AsyncExampleWPF
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private async void startButton_Click(object sender, RoutedEventArgs e)
        {
            // Disable the button until the operation is complete.
            startButton.IsEnabled = false;

            resultsTextBox.Clear();

            // One-step async call.
            await SumPageSizesAsync();

            // Two-step async call.
            //Task sumTask = SumPageSizesAsync();
            //await sumTask;

            resultsTextBox.Text += "\r\nControl returned to startButton_Click.\r\n";

            // Reenable the button in case you want to run the operation again.
            startButton.IsEnabled = true;
        }

        private async Task SumPageSizesAsync()
        {
            // Make a list of web addresses.
            List<string> urlList = SetUpURLList();

            var total = 0;

            foreach (var url in urlList)
            {
                byte[] urlContents = await GetURLContentsAsync(url);

                // The previous line abbreviates the following two assignment statements.

                // GetURLContentsAsync returns a Task<T>. At completion, the task
                // produces a byte array.
                //Task<byte[]> getContentsTask = GetURLContentsAsync(url);
                //byte[] urlContents = await getContentsTask;

                DisplayResults(url, urlContents);

                // Update the total.
                total += urlContents.Length;
            }
            // Display the total count for all of the websites.
            resultsTextBox.Text +=
                $"\r\n\r\nTotal bytes returned:  {total}\r\n";
        }

        private List<string> SetUpURLList()
        {
            List<string> urls = new List<string>
            {
                "https://msdn.microsoft.com/library/windows/apps/br211380.aspx",
                "https://msdn.microsoft.com",
                "https://msdn.microsoft.com/library/hh290136.aspx",
                "https://msdn.microsoft.com/library/ee256749.aspx",
                "https://msdn.microsoft.com/library/hh290138.aspx",
                "https://msdn.microsoft.com/library/hh290140.aspx",
                "https://msdn.microsoft.com/library/dd470362.aspx",
                "https://msdn.microsoft.com/library/aa578028.aspx",
                "https://msdn.microsoft.com/library/ms404677.aspx",
                "https://msdn.microsoft.com/library/ff730837.aspx"
            };
            return urls;
        }

        private async Task<byte[]> GetURLContentsAsync(string url)
        {
            // The downloaded resource ends up in the variable named content.
            var content = new MemoryStream();

            // Initialize an HttpWebRequest for the current URL.
            var webReq = (HttpWebRequest)WebRequest.Create(url);

            // Send the request to the Internet resource and wait for
            // the response.
            using (WebResponse response = await webReq.GetResponseAsync())

            // The previous statement abbreviates the following two statements.

            //Task<WebResponse> responseTask = webReq.GetResponseAsync();
            //using (WebResponse response = await responseTask)
            {
                // Get the data stream that is associated with the specified url.
                using (Stream responseStream = response.GetResponseStream())
                {
                    // Read the bytes in responseStream and copy them to content.
                    await responseStream.CopyToAsync(content);

                    // The previous statement abbreviates the following two statements.

                    // CopyToAsync returns a Task, not a Task<T>.
                    //Task copyTask = responseStream.CopyToAsync(content);

                    // When copyTask is completed, content contains a copy of
                    // responseStream.
                    //await copyTask;
                }
            }
            // Return the result as a byte array.
            return content.ToArray();
        }

        private void DisplayResults(string url, byte[] content)
        {
            // Display the length of each website. The string format
            // is designed to be used with a monospaced font, such as
            // Lucida Console or Global Monospace.
            var bytes = content.Length;
            // Strip off the "https://".
            var displayURL = url.Replace("https://", "");
            resultsTextBox.Text += $"\n{displayURL,-58} {bytes,8}";
        }
    }
}
```

下列代码包含使用 `HttpClient` 方法 `GetByteArrayAsync` 的解决方案的完整示例。

```csharp
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

// Add the following using directives, and add a reference for System.Net.Http.
using System.Net.Http;
using System.IO;
using System.Net;

namespace AsyncExampleWPF
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private async void startButton_Click(object sender, RoutedEventArgs e)
        {
            resultsTextBox.Clear();

            // Disable the button until the operation is complete.
            startButton.IsEnabled = false;

            // One-step async call.
            await SumPageSizesAsync();

            //// Two-step async call.
            //Task sumTask = SumPageSizesAsync();
            //await sumTask;

            resultsTextBox.Text += "\r\nControl returned to startButton_Click.\r\n";

            // Reenable the button in case you want to run the operation again.
            startButton.IsEnabled = true;
        }

        private async Task SumPageSizesAsync()
        {
            // Declare an HttpClient object and increase the buffer size. The
            // default buffer size is 65,536.
            HttpClient client =
                new HttpClient() { MaxResponseContentBufferSize = 1000000 };

            // Make a list of web addresses.
            List<string> urlList = SetUpURLList();

            var total = 0;

            foreach (var url in urlList)
            {
                // GetByteArrayAsync returns a task. At completion, the task
                // produces a byte array.
                byte[] urlContents = await client.GetByteArrayAsync(url);

                // The following two lines can replace the previous assignment statement.
                //Task<byte[]> getContentsTask = client.GetByteArrayAsync(url);
                //byte[] urlContents = await getContentsTask;

                DisplayResults(url, urlContents);

                // Update the total.
                total += urlContents.Length;
            }

            // Display the total count for all of the websites.
            resultsTextBox.Text +=
                $"\r\n\r\nTotal bytes returned:  {total}\r\n";
        }

        private List<string> SetUpURLList()
        {
            List<string> urls = new List<string>
            {
                "https://msdn.microsoft.com/library/windows/apps/br211380.aspx",
                "https://msdn.microsoft.com",
                "https://msdn.microsoft.com/library/hh290136.aspx",
                "https://msdn.microsoft.com/library/ee256749.aspx",
                "https://msdn.microsoft.com/library/hh290138.aspx",
                "https://msdn.microsoft.com/library/hh290140.aspx",
                "https://msdn.microsoft.com/library/dd470362.aspx",
                "https://msdn.microsoft.com/library/aa578028.aspx",
                "https://msdn.microsoft.com/library/ms404677.aspx",
                "https://msdn.microsoft.com/library/ff730837.aspx"
            };
            return urls;
        }

        private void DisplayResults(string url, byte[] content)
        {
            // Display the length of each website. The string format
            // is designed to be used with a monospaced font, such as
            // Lucida Console or Global Monospace.
            var bytes = content.Length;
            // Strip off the "https://".
            var displayURL = url.Replace("https://", "");
            resultsTextBox.Text += $"\n{displayURL,-58} {bytes,8}";
        }
    }
}
```

### [How to: Extend the async Walkthrough by Using Task.WhenAll](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/async/how-to-extend-the-async-walkthrough-by-using-task-whenall)

提高[演练：使用 Async 和 Await 访问 Web (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/walkthrough-accessing-the-web-by-using-async-and-await)中的异步解决方案的性能，方法是使用 [Task.WhenAll](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task.whenall) 方法。 此方法以异步方式等待多个异步操作（它们表示为任务的集合）。

你可能已在演练中注意到网站以不同速率进行下载。 有时一个网站非常慢，这会延迟所有其余下载。 运行在演练中生成的异步解决方案时，如果不想等待，则可以方便地结束程序，但更好的选项是同时启动所有下载，并让较快的下载继续进行而不等待延迟的下载。

可将 `Task.WhenAll` 方法应用于任务的集合。 `WhenAll` 的应用程序返回单个任务，直到集合中的每个任务都已完成之后，该任务才会完成。 任务会表现为并行运行，但不会创建其他线程。 任务可以按任何顺序完成。

> 下面的过程介绍[演练：使用 Async 和 Await 访问 Web (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/walkthrough-accessing-the-web-by-using-async-and-await) 中开发的异步应用程序的扩展。 可以通过完成演练或从[开发人员代码示例](https://code.msdn.microsoft.com/Async-Sample-Accessing-the-9c10497f)下载代码来开发应用程序。

若要运行示例，必须在计算机上安装 Visual Studio 2012 或更高版本。

#### 向你的 GetURLContentsAsync 解决方案中添加 Task.WhenAll

1. 将 `ProcessURLAsync` 方法添加到[演练：使用 Async 和 Await 访问 Web (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/walkthrough-accessing-the-web-by-using-async-and-await)中开发的第一个应用程序。

   - 如果是从[开发人员代码示例](https://code.msdn.microsoft.com/Async-Sample-Accessing-the-9c10497f)下载的代码，请打开 AsyncWalkthrough 项目，然后向 MainWindow.xaml.cs 文件添加 `ProcessURLAsync`。
   - 如果是通过完成演练开发的代码，请向包含 `GetURLContentsAsync` 方法的应用程序添加 `ProcessURLAsync`。 此应用程序的 MainWindow.xaml.cs 文件是“完成演练中的代码示例”部分中的第一个示例。

   `ProcessURLAsync` 方法整合了原始演练的 `SumPageSizesAsync` 中的 `foreach` 循环体中的操作。 该方法以异步方式将指定网站的内容作为字节数组进行下载，然后显示并返回字节数组的长度。

   ```csharp
   private async Task<int> ProcessURLAsync(string url)  
   {  
       var byteArray = await GetURLContentsAsync(url);  
       DisplayResults(url, byteArray);  
       return byteArray.Length;  
   }  
   ```

2. 注释禁止或删除 `SumPageSizesAsync` 中的 `foreach` 循环，如以下代码所示。

   ```csharp
   //var total = 0;  
   //foreach (var url in urlList)  
   //{  
   //    byte[] urlContents = await GetURLContentsAsync(url);  
   
   //    // The previous line abbreviates the following two assignment statements.  
   //    // GetURLContentsAsync returns a Task<T>. At completion, the task  
   //    // produces a byte array.  
   //    //Task<byte[]> getContentsTask = GetURLContentsAsync(url);  
   //    //byte[] urlContents = await getContentsTask;  
   
   //    DisplayResults(url, urlContents);  
   
   //    // Update the total.            
   //    total += urlContents.Length;  
   //}  
   ```

3. 创建任务集合。 以下代码定义一个[查询](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/index)，由 [ToArray](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.toarray) 方法执行该查询时，它会创建下载每个网站内容的任务集合。 计算该查询时，会启动任务。

   在 `urlList` 的声明后，将以下代码添加到方法 `SumPageSizesAsync` 中。

   ```csharp
   // Create a query.   
   IEnumerable<Task<int>> downloadTasksQuery =   
       from url in urlList select ProcessURLAsync(url);  
   
   // Use ToArray to execute the query and start the download tasks.  
   Task<int>[] downloadTasks = downloadTasksQuery.ToArray();  
   ```

4. 将 `Task.WhenAll` 应用于任务集合 `downloadTasks`。 `Task.WhenAll` 返回单个任务，它在任务集合中的所有任务都已完成时完成。

   在以下示例中，`await` 表达式等待 `WhenAll` 返回的单个任务完成。 该表达式的计算结果为整数数组，其中每个整数都是一个下载的网站的长度。 就在上一步添加的代码后，将以下代码添加到 `SumPageSizesAsync`中。

   ```csharp
   // Await the completion of all the running tasks.  
   int[] lengths = await Task.WhenAll(downloadTasks);  
   
   //// The previous line is equivalent to the following two statements.  
   //Task<int[]> whenAllTask = Task.WhenAll(downloadTasks);  
   //int[] lengths = await whenAllTask;  
   ```

5. 最后，使用 [Sum](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.sum) 方法计算所有网站的长度总和。 将以下行添加到 `SumPageSizesAsync` 中。

   ```csharp
   int total = lengths.Sum();  
   ```

#### 向 HttpClient.GetByteArrayAsync 解决方案中添加 Task.WhenAll

1. 将 `ProcessURLAsync` 的以下版本添加到[演练：使用 Async 和 Await 访问 Web (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/walkthrough-accessing-the-web-by-using-async-and-await)中开发的第二个应用程序。

   - 如果是从[开发人员代码示例](https://code.msdn.microsoft.com/Async-Sample-Accessing-the-9c10497f)下载的代码，请打开 AsyncWalkthrough_HttpClient 项目，然后向 MainWindow.xaml.cs 文件添加 `ProcessURLAsync`。
   - 如果是通过完成演练开发的代码，请向使用 `HttpClient.GetByteArrayAsync` 方法的应用程序添加 `ProcessURLAsync`。 此应用程序的 MainWindow.xaml.cs 文件是“完成演练中的代码示例”部分中的第二个示例。

   `ProcessURLAsync` 方法整合了原始演练的 `SumPageSizesAsync` 中的 `foreach` 循环体中的操作。 该方法以异步方式将指定网站的内容作为字节数组进行下载，然后显示并返回字节数组的长度。

   与上面过程中的 `ProcessURLAsync` 方法的唯一区别是使用 [HttpClient](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.http.httpclient) 实例 `client`。

   ```csharp
   async Task<int> ProcessURLAsync(string url, HttpClient client)  
   {  
       byte[] byteArray = await client.GetByteArrayAsync(url);  
       DisplayResults(url, byteArray);  
       return byteArray.Length;  
   }  
   ```

2. 注释禁止或删除 `SumPageSizesAsync` 中的 `For Each` 或 `foreach` 循环，如以下代码所示。

   ```csharp
   //var total = 0;  
   //foreach (var url in urlList)  
   //{  
   //    // GetByteArrayAsync returns a Task<T>. At completion, the task  
   //    // produces a byte array.  
   //    byte[] urlContent = await client.GetByteArrayAsync(url);  
   
   //    // The previous line abbreviates the following two assignment  
   //    // statements.  
   //    Task<byte[]> getContentTask = client.GetByteArrayAsync(url);  
   //    byte[] urlContent = await getContentTask;  
   
   //    DisplayResults(url, urlContent);  
   
   //    // Update the total.  
   //    total += urlContent.Length;  
   //}  
   ```

3. 定义一个[查询](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/index)，由 [ToArray](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.toarray) 方法执行该查询时，它会创建下载每个网站内容的任务集合。 计算该查询时，会启动任务。

   在 `client` 和 `urlList` 的声明后，将以下代码添加到方法 `SumPageSizesAsync` 中。

   ```csharp
   // Create a query.  
   IEnumerable<Task<int>> downloadTasksQuery =   
       from url in urlList select ProcessURLAsync(url, client);  
   
   // Use ToArray to execute the query and start the download tasks.  
   Task<int>[] downloadTasks = downloadTasksQuery.ToArray();  
   ```

4. 接下来，将 `Task.WhenAll` 应用于任务集合 `downloadTasks`。 `Task.WhenAll` 返回单个任务，它在任务集合中的所有任务都已完成时完成。

   在以下示例中，`await` 表达式等待 `WhenAll` 返回的单个任务完成。 完成后，`await` 表达式的计算结果为整数数组，其中每个整数都是一个下载的网站的长度。 就在上一步添加的代码后，将以下代码添加到 `SumPageSizesAsync` 中。

   ```csharp
   // Await the completion of all the running tasks.  
   int[] lengths = await Task.WhenAll(downloadTasks);  
   
   //// The previous line is equivalent to the following two statements.  
   //Task<int[]> whenAllTask = Task.WhenAll(downloadTasks);  
   //int[] lengths = await whenAllTask;  
   ```

5. 最后，使用 [Sum](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.sum) 方法获取所有网站的长度总和。 将以下行添加到 `SumPageSizesAsync` 中。

   ```csharp
   int total = lengths.Sum();
   ```

#### 测试 Task.WhenAll 解决方案

- 对于任一解决方案，按 F5 键以运行程序，然后选择“启动”按钮。 输出应类似于[演练：使用 Async 和 Await 访问 Web (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/walkthrough-accessing-the-web-by-using-async-and-await)中的异步解决方案中的输出。 但请注意，网站每次会以不同顺序出现。

#### 示例

以下代码演示使用 `GetURLContentsAsync` 方法从 Web 下载内容的项目的扩展。

```csharp
// Add the following using directives, and add a reference for System.Net.Http.  
using System.Net.Http;  
using System.IO;  
using System.Net;  
  
namespace AsyncExampleWPF_WhenAll  
{  
    public partial class MainWindow : Window  
    {  
        public MainWindow()  
        {  
            InitializeComponent();  
        }  
  
        private async void startButton_Click(object sender, RoutedEventArgs e)  
        {  
            resultsTextBox.Clear();  
  
            // Two-step async call.  
            Task sumTask = SumPageSizesAsync();  
            await sumTask;  
  
            // One-step async call.  
            //await SumPageSizesAsync();  
  
            resultsTextBox.Text += "\r\nControl returned to startButton_Click.\r\n";  
        }  
  
        private async Task SumPageSizesAsync()  
        {  
            // Make a list of web addresses.  
            List<string> urlList = SetUpURLList();  
  
            // Create a query.   
            IEnumerable<Task<int>> downloadTasksQuery =   
                from url in urlList select ProcessURLAsync(url);  
  
            // Use ToArray to execute the query and start the download tasks.  
            Task<int>[] downloadTasks = downloadTasksQuery.ToArray();  
  
            // You can do other work here before awaiting.  
  
            // Await the completion of all the running tasks.  
            int[] lengths = await Task.WhenAll(downloadTasks);  
  
            //// The previous line is equivalent to the following two statements.  
            //Task<int[]> whenAllTask = Task.WhenAll(downloadTasks);  
            //int[] lengths = await whenAllTask;  
  
            int total = lengths.Sum();  
  
            //var total = 0;  
            //foreach (var url in urlList)  
            //{  
            //    byte[] urlContents = await GetURLContentsAsync(url);  
  
            //    // The previous line abbreviates the following two assignment statements.  
            //    // GetURLContentsAsync returns a Task<T>. At completion, the task  
            //    // produces a byte array.  
            //    //Task<byte[]> getContentsTask = GetURLContentsAsync(url);  
            //    //byte[] urlContents = await getContentsTask;  
  
            //    DisplayResults(url, urlContents);  
  
            //    // Update the total.            
            //    total += urlContents.Length;  
            //}  
  
            // Display the total count for all of the websites.  
            resultsTextBox.Text +=  
                $"\r\n\r\nTotal bytes returned:  {total}\r\n";
        }  
  
        private List<string> SetUpURLList()  
        {  
            List<string> urls = new List<string>   
            {   
                "https://msdn.microsoft.com",  
                "https://msdn.microsoft.com/library/windows/apps/br211380.aspx",  
                "https://msdn.microsoft.com/library/hh290136.aspx",  
                "https://msdn.microsoft.com/library/ee256749.aspx",  
                "https://msdn.microsoft.com/library/hh290138.aspx",  
                "https://msdn.microsoft.com/library/hh290140.aspx",  
                "https://msdn.microsoft.com/library/dd470362.aspx",  
                "https://msdn.microsoft.com/library/aa578028.aspx",  
                "https://msdn.microsoft.com/library/ms404677.aspx",  
                "https://msdn.microsoft.com/library/ff730837.aspx"  
            };  
            return urls;  
        }  
  
        // The actions from the foreach loop are moved to this async method.  
        private async Task<int> ProcessURLAsync(string url)  
        {  
            var byteArray = await GetURLContentsAsync(url);  
            DisplayResults(url, byteArray);  
            return byteArray.Length;  
        }  
  
        private async Task<byte[]> GetURLContentsAsync(string url)  
        {  
            // The downloaded resource ends up in the variable named content.  
            var content = new MemoryStream();  
  
            // Initialize an HttpWebRequest for the current URL.  
            var webReq = (HttpWebRequest)WebRequest.Create(url);  
  
            // Send the request to the Internet resource and wait for  
            // the response.  
            using (WebResponse response = await webReq.GetResponseAsync())  
            {  
                // Get the data stream that is associated with the specified url.  
                using (Stream responseStream = response.GetResponseStream())  
                {  
                    await responseStream.CopyToAsync(content);  
                }  
            }  
  
            // Return the result as a byte array.  
            return content.ToArray();  
  
        }  
  
        private void DisplayResults(string url, byte[] content)  
        {  
            // Display the length of each website. The string format   
            // is designed to be used with a monospaced font, such as  
            // Lucida Console or Global Monospace.  
            var bytes = content.Length;  
            // Strip off the "https://".  
            var displayURL = url.Replace("https://", "");  
            resultsTextBox.Text += $"\n{displayURL,-58} {bytes,8}";
        }
    }  
}  
```

#### 示例

以下代码演示使用 `HttpClient.GetByteArrayAsync` 方法从 Web 下载内容的项目的扩展。

```csharp
// Add the following using directives, and add a reference for System.Net.Http.  
using System.Net.Http;  
using System.IO;  
using System.Net;  
  
namespace AsyncExampleWPF_HttpClient_WhenAll  
{  
    public partial class MainWindow : Window  
    {  
        public MainWindow()  
        {  
            InitializeComponent();  
        }  
  
        private async void startButton_Click(object sender, RoutedEventArgs e)  
        {  
            resultsTextBox.Clear();  
  
            // One-step async call.  
            await SumPageSizesAsync();  
  
            // Two-step async call.  
            //Task sumTask = SumPageSizesAsync();  
            //await sumTask;  
  
            resultsTextBox.Text += "\r\nControl returned to startButton_Click.\r\n";  
        }  
  
        private async Task SumPageSizesAsync()  
        {  
            // Make a list of web addresses.  
            List<string> urlList = SetUpURLList();  
  
            // Declare an HttpClient object and increase the buffer size. The  
            // default buffer size is 65,536.  
            HttpClient client = new HttpClient() { MaxResponseContentBufferSize = 1000000 };  
  
            // Create a query.  
            IEnumerable<Task<int>> downloadTasksQuery =   
                from url in urlList select ProcessURLAsync(url, client);  
  
            // Use ToArray to execute the query and start the download tasks.  
            Task<int>[] downloadTasks = downloadTasksQuery.ToArray();  
  
            // You can do other work here before awaiting.  
  
            // Await the completion of all the running tasks.  
            int[] lengths = await Task.WhenAll(downloadTasks);  
  
            //// The previous line is equivalent to the following two statements.  
            //Task<int[]> whenAllTask = Task.WhenAll(downloadTasks);  
            //int[] lengths = await whenAllTask;  
  
            int total = lengths.Sum();  
  
            //var total = 0;  
            //foreach (var url in urlList)  
            //{  
            //    // GetByteArrayAsync returns a Task<T>. At completion, the task  
            //    // produces a byte array.  
            //    byte[] urlContent = await client.GetByteArrayAsync(url);  
  
            //    // The previous line abbreviates the following two assignment  
            //    // statements.  
            //    Task<byte[]> getContentTask = client.GetByteArrayAsync(url);  
            //    byte[] urlContent = await getContentTask;  
  
            //    DisplayResults(url, urlContent);  
  
            //    // Update the total.  
            //    total += urlContent.Length;  
            //}  
  
            // Display the total count for all of the web addresses.  
            resultsTextBox.Text +=  
                $"\r\n\r\nTotal bytes returned:  {total}\r\n";
        }  
  
        private List<string> SetUpURLList()  
        {  
            List<string> urls = new List<string>   
            {   
                "https://msdn.microsoft.com",  
                "https://msdn.microsoft.com/library/hh290136.aspx",  
                "https://msdn.microsoft.com/library/ee256749.aspx",  
                "https://msdn.microsoft.com/library/hh290138.aspx",  
                "https://msdn.microsoft.com/library/hh290140.aspx",  
                "https://msdn.microsoft.com/library/dd470362.aspx",  
                "https://msdn.microsoft.com/library/aa578028.aspx",  
                "https://msdn.microsoft.com/library/ms404677.aspx",  
                "https://msdn.microsoft.com/library/ff730837.aspx"  
            };  
            return urls;  
        }  
  
        // The actions from the foreach loop are moved to this async method.  
        async Task<int> ProcessURLAsync(string url, HttpClient client)  
        {  
            byte[] byteArray = await client.GetByteArrayAsync(url);  
            DisplayResults(url, byteArray);  
            return byteArray.Length;  
        }  
  
        private void DisplayResults(string url, byte[] content)  
        {  
            // Display the length of each web site. The string format   
            // is designed to be used with a monospaced font, such as  
            // Lucida Console or Global Monospace.  
            var bytes = content.Length;  
            // Strip off the "https://".  
            var displayURL = url.Replace("https://", "");  
            resultsTextBox.Text += $"\n{displayURL,-58} {bytes,8}";
        }  
    }  
}  
```

### [How to: Make Multiple Web Requests in Parallel by Using async and await](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/async/how-to-make-multiple-web-requests-in-parallel-by-using-async-and-await)

在 async 方法中，任务在创建后即启动。 在任务完成前处理无法继续的方法中将 [await](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/await) 运算符应用于任务。 通常任务被创建后即等待，如下面的示例所示。

```csharp
var result = await someWebAccessMethodAsync(url);  
```

但是，如果程序有其他不依赖于任务的完成的工作要完成，则可以将创建任务和等待任务分开。

```csharp
// The following line creates and starts the task.  
var myTask = someWebAccessMethodAsync(url);  
  
// While the task is running, you can do other work that doesn't depend  
// on the results of the task.  
// . . . . .  
  
// The application of await suspends the rest of this method until the task is complete.  
var result = await myTask;  
```

在启动任务和等待任务之间，可以启动其他任务。 其他任务以并行方式隐式运行，但不会创建其他线程。

下面的程序启动三个异步 Web 下载任务，然后按照任务的调用顺序等待其完成。 请注意，运行此程序时，任务并不总是按照创建和等待它们的顺序完成。 任务在创建后开始运行，在此方法到达 await 表达式之前可能已完成一个或多个任务。

 备注

若要完成此项目，计算机上必须安装有 Visual Studio 2012 或更高版本和 .NET Framework 4.5 或更高版本。

有关同时启动多个任务的另一个示例，请参阅[如何：使用 Task.WhenAll 扩展异步演练 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/how-to-extend-the-async-walkthrough-by-using-task-whenall)。

可以从[开发人员代码示例](https://code.msdn.microsoft.com/Async-Make-Multiple-Web-49adb82e)下载此示例的代码。

#### 设置项目

1. 若要设置 WPF 应用程序，请完成以下步骤。 可以在[演练：使用 Async 和 Await 访问 Web (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/walkthrough-accessing-the-web-by-using-async-and-await) 中找到有关这些步骤的详细说明。
   - 创建包含一个文本框和一个按钮的 WPF 应用程序。 将按钮命名为 `startButton`，将文本框命名为 `resultsTextBox`。
   - 对 [System.Net.Http](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.http) 添加引用。
   - 在 MainWindow.xaml.cs 文件中添加用于 `System.Net.Http` 的 `using` 指令。

#### 添加代码

1. 在设计窗口的 MainWindow.xaml 中，双击按钮以在 MainWindow.xaml.cs 中创建 `startButton_Click` 事件处理程序。

2. 复制以下代码并粘贴到 MainWindow.xaml.cs 中的 `startButton_Click` 的正文中。

   ```csharp
   resultsTextBox.Clear();  
   await CreateMultipleTasksAsync();  
   resultsTextBox.Text += "\r\n\r\nControl returned to startButton_Click.\r\n";  
   ```

   此代码调用异步方法 `CreateMultipleTasksAsync`，此方法驱动应用程序。

3. 向项目中添加以下支持方法：

   - `ProcessURLAsync` 使用 [HttpClient](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.http.httpclient) 方法将网站内容下载为字节数组。 支持方法 `ProcessURLAsync` 随后显示并返回数组的长度。
   - `DisplayResults` 显示每个 URL 的字节数组中的字节数。 当所有任务完成下载后显示。

   复制以下方法，并将它们粘贴在 MainWindow.xaml.cs 中的 `startButton_Click` 事件处理程序后面。

   ```csharp
   async Task<int> ProcessURLAsync(string url, HttpClient client)  
   {  
       var byteArray = await client.GetByteArrayAsync(url);  
       DisplayResults(url, byteArray);  
       return byteArray.Length;  
   }  
   
   private void DisplayResults(string url, byte[] content)  
   {  
       // Display the length of each website. The string format   
       // is designed to be used with a monospaced font, such as  
       // Lucida Console or Global Monospace.  
       var bytes = content.Length;  
       // Strip off the "https://".  
       var displayURL = url.Replace("https://", "");  
       resultsTextBox.Text += $"\n{displayURL,-58} {bytes,8}";
   }  
   ```

4. 最后，定义方法 `CreateMultipleTasksAsync`，用于执行以下步骤。

   - 该方法声明 `HttpClient` 对象，这需要你访问 `ProcessURLAsync` 中的 [GetByteArrayAsync](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.http.httpclient.getbytearrayasync) 方法。
   - 此方法创建并启动三个类型为 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1) 的任务，其中 `TResult` 是一个整数。 每个任务完成后，`DisplayResults` 显示任务的 URL 和下载内容的长度。 由于任务是异步运行的，因此显示结果的顺序可能与声明任务的顺序不同。
   - 此方法等待每个任务完成。 每个 `await` 运算符暂停执行 `CreateMultipleTasksAsync`，直到所等待的任务完成。 此运算符还会从每个已完成的任务的 `ProcessURLAsync` 调用中检索返回值。
   - 当任务已完成并已检索到整数值时，此方法对网站的长度求和，并显示结果。

   复制下面的方法，并将其粘贴到你的解决方案。

   ```csharp
   private async Task CreateMultipleTasksAsync()  
   {  
       // Declare an HttpClient object, and increase the buffer size. The  
       // default buffer size is 65,536.  
       HttpClient client =  
           new HttpClient() { MaxResponseContentBufferSize = 1000000 };  
   
       // Create and start the tasks. As each task finishes, DisplayResults   
       // displays its length.  
       Task<int> download1 =   
           ProcessURLAsync("https://msdn.microsoft.com", client);  
       Task<int> download2 =   
           ProcessURLAsync("https://msdn.microsoft.com/library/hh156528(VS.110).aspx", client);  
       Task<int> download3 =   
           ProcessURLAsync("https://msdn.microsoft.com/library/67w7t67f.aspx", client);  
   
       // Await each task.  
       int length1 = await download1;  
       int length2 = await download2;  
       int length3 = await download3;  
   
       int total = length1 + length2 + length3;  
   
       // Display the total count for the downloaded websites.  
       resultsTextBox.Text += $"\r\n\r\nTotal bytes returned:  {total}\r\n";
   }  
   ```

5. 按 F5 键以运行程序，然后选择 **“启动”** 按钮。

   多次运行此程序以确认三个任务并不总是以相同的顺序完成，并且完成的顺序不一定是创建和等待任务的顺序。

#### 示例

下面的代码包括完整的示例。

```csharp
using System;  
using System.Collections.Generic;  
using System.Linq;  
using System.Text;  
using System.Threading.Tasks;  
using System.Windows;  
using System.Windows.Controls;  
using System.Windows.Data;  
using System.Windows.Documents;  
using System.Windows.Input;  
using System.Windows.Media;  
using System.Windows.Media.Imaging;  
using System.Windows.Navigation;  
using System.Windows.Shapes;  
  
// Add the following using directive, and add a reference for System.Net.Http.  
using System.Net.Http;  
  
namespace AsyncExample_MultipleTasks  
{  
    public partial class MainWindow : Window  
    {  
        public MainWindow()  
        {  
            InitializeComponent();  
        }  
  
        private async void startButton_Click(object sender, RoutedEventArgs e)  
        {  
            resultsTextBox.Clear();  
            await CreateMultipleTasksAsync();  
            resultsTextBox.Text += "\r\n\r\nControl returned to startButton_Click.\r\n";  
        }  
  
        private async Task CreateMultipleTasksAsync()  
        {  
            // Declare an HttpClient object, and increase the buffer size. The  
            // default buffer size is 65,536.  
            HttpClient client =  
                new HttpClient() { MaxResponseContentBufferSize = 1000000 };  
  
            // Create and start the tasks. As each task finishes, DisplayResults   
            // displays its length.  
            Task<int> download1 =   
                ProcessURLAsync("https://msdn.microsoft.com", client);  
            Task<int> download2 =   
                ProcessURLAsync("https://msdn.microsoft.com/library/hh156528(VS.110).aspx", client);  
            Task<int> download3 =   
                ProcessURLAsync("https://msdn.microsoft.com/library/67w7t67f.aspx", client);  
  
            // Await each task.  
            int length1 = await download1;  
            int length2 = await download2;  
            int length3 = await download3;  
  
            int total = length1 + length2 + length3;  
  
            // Display the total count for the downloaded websites.  
            resultsTextBox.Text += $"\r\n\r\nTotal bytes returned:  {total}\r\n";
        }  
  
        async Task<int> ProcessURLAsync(string url, HttpClient client)  
        {  
            var byteArray = await client.GetByteArrayAsync(url);  
            DisplayResults(url, byteArray);  
            return byteArray.Length;  
        }  
  
        private void DisplayResults(string url, byte[] content)  
        {  
            // Display the length of each website. The string format   
            // is designed to be used with a monospaced font, such as  
            // Lucida Console or Global Monospace.  
            var bytes = content.Length;  
            // Strip off the "https://".  
            var displayURL = url.Replace("https://", "");  
            resultsTextBox.Text += $"\n{displayURL,-58} {bytes,8}";
        }
    }  
}  
```

### [Async Return Types](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/async/async-return-types)

异步方法可以具有以下返回类型：

- [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1)（对于返回值的异步方法）。
- [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task)（对于执行操作但不返回任何值的异步方法）。
- `void`（对于事件处理程序）。
- 从 C# 7.0 开始，任何具有可访问的 `GetAwaiter` 方法的类型。 `GetAwaiter` 方法返回的对象必须实现[System.Runtime.CompilerServices.ICriticalNotifyCompletion](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.compilerservices.icriticalnotifycompletion) 接口。

有关异步方法的详细信息，请参阅[使用 Async 和 Await 的异步编程 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/index)。

在以下其中一节检查每个返回类型，且在本主题末尾可以找到使用全部三种类型的完整示例。

#### Task<TResult> 返回类型

[Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1) 返回类型用于某种异步方法，此异步方法包含 [return](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/return) (C#) 语句，其中操作数具有类型 `TResult`。

在下面的示例中，`GetLeisureHours` 异步方法包含返回整数的 `return` 语句。 因此，该方法声明必须指定 `Task<int>` 的返回类型。 [FromResult](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task.fromresult) 异步方法是返回字符串的操作的占位符。

```csharp
using System;
using System.Linq;
using System.Threading.Tasks;

public class Example
{
   public static void Main()
   {
      Console.WriteLine(ShowTodaysInfo().Result);
   }

   private static async Task<string> ShowTodaysInfo()
   {
      string ret = $"Today is {DateTime.Today:D}\n" +
                   "Today's hours of leisure: " +
                   $"{await GetLeisureHours()}";
      return ret;
   }

   static async Task<int> GetLeisureHours()  
   {  
       // Task.FromResult is a placeholder for actual work that returns a string.  
       var today = await Task.FromResult<string>(DateTime.Now.DayOfWeek.ToString());  
     
       // The method then can process the result in some way.  
       int leisureHours;  
       if (today.First() == 'S')  
           leisureHours = 16;  
       else  
           leisureHours = 5;  
     
       return leisureHours;  
   }  
}
// The example displays output like the following:
//       Today is Wednesday, May 24, 2017
//       Today's hours of leisure: 5
// </Snippet >
```

在 `ShowTodaysInfo` 方法中从 await 表达式内调用 `GetLeisureHours` 时，await 表达式检索存储在由 `GetLeisureHours` 方法返回的任务中的整数值（`leisureHours` 的值）。 有关 await 表达式的详细信息，请参阅 [await](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/await)。

通过从应用程序 `await` 中分离对 `GetLeisureHours` 的调用，你可以更好地了解此操作，如下面的代码所示。 对非立即等待的方法 `GetLeisureHours` 的调用返回 `Task<int>`，正如你从方法声明预料的一样。 该任务指派给示例中的 `integerTask` 变量。 因为 `integerTask` 是 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1)，所以它包含类型 `TResult` 的 [Result](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1.result#System_Threading_Tasks_Task_1_Result) 属性。 在这种情况下，`TResult` 表示整数类型。 `await` 应用于 `integerTask`，await 表达式的计算结果为 `integerTask` 的 [Result](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1.result) 属性内容。 此值分配给 `ret` 变量。

> [Result](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1.result) 属性为阻止属性。 如果你在其任务完成之前尝试访问它，当前处于活动状态的线程将被阻止，直到任务完成且值为可用。 在大多数情况下，应通过使用 `await` 访问此值，而不是直接访问属性。 
> 上一示例通过检索 [Result](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1.result) 属性的值来阻止主线程，从而使 `ShowTodaysInfo` 方法可在应用程序结束之前完成执行。

```csharp
var integerTask = GetLeisureHours();

// You can do other work that does not rely on integerTask before awaiting.

string ret = $"Today is {DateTime.Today:D}\n" +
             "Today's hours of leisure: " +
             $"{await integerTask}";
```

#### 任务返回类型

不包含 `return` 语句的异步方法或包含不返回操作数的 `return` 语句的异步方法通常具有返回类型 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task)。 如果此类方法同步运行，它们将返回 `void`。 如果在异步方法中使用 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task) 返回类型，调用方法可以使用 `await` 运算符暂停调用方的完成，直至被调用的异步方法结束。

如下示例中，`WaitAndApologize` 异步方法不包含 `return` 语句，因此此方法返回 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task) 对象。 通过这样可等待 `WaitAndApologize`。 请注意，[Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task) 类型不包含 `Result` 属性，因为它不具有任何返回值。

```csharp
using System;
using System.Threading.Tasks;

public class Example
{
   public static void Main()
   {
      DisplayCurrentInfo().Wait();
   }

   static async Task DisplayCurrentInfo()
   {
      await WaitAndApologize();
      Console.WriteLine($"Today is {DateTime.Now:D}");
      Console.WriteLine($"The current time is {DateTime.Now.TimeOfDay:t}");
      Console.WriteLine("The current temperature is 76 degrees.");
   }

   static async Task WaitAndApologize()
   {
      // Task.Delay is a placeholder for actual work.  
      await Task.Delay(2000);  
      // Task.Delay delays the following line by two seconds.  
      Console.WriteLine("\nSorry for the delay. . . .\n");  
   }
}
// The example displays the following output:
//       Sorry for the delay. . . .
//       
//       Today is Wednesday, May 24, 2017
//       The current time is 15:25:16.2935649
//       The current temperature is 76 degrees.
```

通过使用 await 语句而不是 await 表达式等待 `WaitAndApologize`，类似于返回 void 的同步方法的调用语句。Await 运算符的应用程序在这种情况下不生成值。

如同上一个 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1) 示例，可以从 await 运算符的应用程序中分离对 `WaitAndApologize` 的调用，如以下代码所示。 但是，请记住，`Task` 没有 `Result` 属性，并且当 await 运算符应用于 `Task` 时不产生值。

以下代码将调用 `WaitAndApologize` 方法和等待此方法返回的任务分离。

```csharp
Task wait = WaitAndApologize();

string output = $"Today is {DateTime.Now:D}\n" + 
                $"The current time is {DateTime.Now.TimeOfDay:t}\n" +
                $"The current temperature is 76 degrees.\n";
await wait;
Console.WriteLine(output);
```

#### Void 返回类型

在异步事件处理程序中使用 `void` 返回类型，这需要 `void` 返回类型。 对于事件处理程序以外的不返回值的方法，应返回 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task)，因为无法等待返回 `void` 的异步方法。 这种方法的任何调用方必须能够继续完成，而无需等待调用的异步方法完成，并且调用方必须独立于异步方法生成的任何值或异常。

返回 void 的异步方法的调用方无法捕获从该方法引发的异常，且此类未经处理的异常可能会导致应用程序故障。如果返回 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task) 或 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1) 的异步方法中出现异常，此异常将存储于返回的任务中，并在等待该任务时再次引发。 因此，请确保可以产生异常的任何异步方法都具有返回类型 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task) 或 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1)，并确保会等待对方法的调用。

有关如何在异步方法中捕获异常的详细信息，请参阅 [try-catch](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/try-catch) 主题的[异步方法中的异常](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/try-catch#exceptions-in-async-methods)部分。

以下示例演示异步事件处理程序的行为。 请注意，在本示例代码中，异步事件处理程序必须在完成时通知主线程。 然后，主线程可在退出程序之前等待异步事件处理程序完成。

```csharp
using System;
using System.Threading.Tasks;

public class NaiveButton
{
    public event EventHandler Clicked;

    public void Click()
    {
        Console.WriteLine("Somebody has clicked a button. Let's raise the event...");
        Clicked?.Invoke(this, EventArgs.Empty);
        Console.WriteLine("All listeners are notified.");
    }
}

public class AsyncVoidExample
{
    static TaskCompletionSource<bool> tcs;

    static async Task Main()
    {
        tcs = new TaskCompletionSource<bool>();
        var secondHandlerFinished = tcs.Task;

        var button = new NaiveButton();
        button.Clicked += Button_Clicked_1;
        button.Clicked += Button_Clicked_2_Async;
        button.Clicked += Button_Clicked_3;

        Console.WriteLine("About to click a button...");
        button.Click();
        Console.WriteLine("Button's Click method returned.");

        await secondHandlerFinished;
    }

    private static void Button_Clicked_1(object sender, EventArgs e)
    {
        Console.WriteLine("   Handler 1 is starting...");
        Task.Delay(100).Wait();
        Console.WriteLine("   Handler 1 is done.");
    }

    private static async void Button_Clicked_2_Async(object sender, EventArgs e)
    {
        Console.WriteLine("   Handler 2 is starting...");
        Task.Delay(100).Wait();
        Console.WriteLine("   Handler 2 is about to go async...");
        await Task.Delay(500);
        Console.WriteLine("   Handler 2 is done.");
        tcs.SetResult(true);
    }

    private static void Button_Clicked_3(object sender, EventArgs e)
    {
        Console.WriteLine("   Handler 3 is starting...");
        Task.Delay(100).Wait();
        Console.WriteLine("   Handler 3 is done.");
    }
}

// Expected output:
// About to click a button...
// Somebody has clicked a button. Let's raise the event...
//    Handler 1 is starting...
//    Handler 1 is done.
//    Handler 2 is starting...
//    Handler 2 is about to go async...
//    Handler 3 is starting...
//    Handler 3 is done.
// All listeners are notified.
// Button's Click method returned.
//    Handler 2 is done.
```

#### 通用的异步返回类型和 ValueTask<TResult>

从 C# 7.0 开始，异步方法可返回任何具有可访问的 `GetAwaiter` 方法的类型。

[Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task) 和 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1) 是引用类型，因此，性能关键路径中的内存分配会对性能产生负面影响，尤其当分配出现在紧凑循环中时。 支持通用返回类型意味着可返回轻量值类型（而不是引用类型），从而避免额外的内存分配。

.NET 提供 [System.Threading.Tasks.ValueTask](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.valuetask-1) 结构作为返回任务的通用值的轻量实现。 要使用 [System.Threading.Tasks.ValueTask](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.valuetask-1) 类型，必须向项目添加 `System.Threading.Tasks.Extensions` NuGet 包。 如下示例使用 [ValueTask](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.valuetask-1) 结构检索两个骰子的值。

```csharp
using System;
using System.Threading.Tasks;

class Program
{
   static Random rnd;
   
   static void Main()
   {
      Console.WriteLine($"You rolled {GetDiceRoll().Result}");
   }
   
   private static async ValueTask<int> GetDiceRoll()
   {
      Console.WriteLine("...Shaking the dice...");
      int roll1 = await Roll();
      int roll2 = await Roll();
      return roll1 + roll2; 
   } 
   
   private static async ValueTask<int> Roll()
   {
      if (rnd == null)
         rnd = new Random();
      
      await Task.Delay(500);
      int diceRoll = rnd.Next(1, 7);
      return diceRoll;
   } 
}
// The example displays output like the following:
//       ...Shaking the dice...
//       You rolled 8
```

### [Control Flow in Async Programs](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/async/control-flow-in-async-programs)

可以使用 `async` 和 `await` 关键字更加轻松地编写和维护异步程序。 但是，如果不了解程序的运行方式，结果可能会让你大吃一惊。 此主题通过一个简单的异步程序跟踪控制流，以显示控制从一种方法移动到另一种方法的情况，以及每次所传输的信息。

一般情况下，使用 [async (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/async) 修饰符标记包含异步代码的方法。 在使用 async 修饰符标记的方法中，可以使用[await (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/await) 运算符来指定暂停该方法以等待调用的异步进程完成的位置。 有关详细信息，请参阅[使用 Async 和 Await 的异步编程 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/index)。

下面的示例使用异步方法以字符串的形式下载指定网站的内容，并显示该字符串的长度。 此示例包含以下两种方法。

- `startButton_Click`，它调用 `AccessTheWebAsync` 并显示结果。
- `AccessTheWebAsync`，它以字符串的形式下载网站的内容，并返回该字符串的长度。 `AccessTheWebAsync` 使用异步 [HttpClient](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.http.httpclient) 方法 [GetStringAsync(String)](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.http.httpclient.getstringasync#System_Net_Http_HttpClient_GetStringAsync_System_String_) 来下载内容。

编号的显示行显示在整个程序的策略点处，以帮助你了解程序的运行方式和说明被标记的每个点处发生的情况。显示行标记为“1”到“6”。 该标签表示程序到达这些代码行的顺序。

下面的代码显示该程序的概要。

```csharp
public partial class MainWindow : Window
{
    // . . .
    private async void startButton_Click(object sender, RoutedEventArgs e)
    {
        // ONE
        Task<int> getLengthTask = AccessTheWebAsync();

        // FOUR
        int contentLength = await getLengthTask;

        // SIX
        resultsTextBox.Text +=
            $"\r\nLength of the downloaded string: {contentLength}.\r\n";
    }

    async Task<int> AccessTheWebAsync()
    {
        // TWO
        HttpClient client = new HttpClient();
        Task<string> getStringTask =
            client.GetStringAsync("https://msdn.microsoft.com");

        // THREE
        string urlContents = await getStringTask;

        // FIVE
        return urlContents.Length;
    }
}
```

每个标记位置（“1”到“6”）显示有关该程序的当前状态的信息。 将生成以下输出：

```text
ONE:   Entering startButton_Click.
           Calling AccessTheWebAsync.

TWO:   Entering AccessTheWebAsync.
           Calling HttpClient.GetStringAsync.

THREE: Back in AccessTheWebAsync.
           Task getStringTask is started.
           About to await getStringTask & return a Task<int> to startButton_Click.

FOUR:  Back in startButton_Click.
           Task getLengthTask is started.
           About to await getLengthTask -- no caller to return to.

FIVE:  Back in AccessTheWebAsync.
           Task getStringTask is complete.
           Processing the return statement.
           Exiting from AccessTheWebAsync.

SIX:   Back in startButton_Click.
           Task getLengthTask is finished.
           Result from AccessTheWebAsync is stored in contentLength.
           About to display contentLength and exit.

Length of the downloaded string: 33946.
```

#### 设置程序

可以从 MSDN 下载本主题使用的代码，也可以自行生成该代码。

> 若要运行该示例，计算机上必须安装 Visual Studio 2012 或更高版本和 .NET Framework 4.5 或更高版本。

#### 下载程序

可以从[异步示例：异步程序中的控制流](https://code.msdn.microsoft.com/Async-Sample-Control-Flow-5c804fc0)中下载此主题的应用程序。 以下步骤将打开并运行该程序。

1. 解压缩下载的文件，然后启动 Visual Studio。
2. 在菜单栏上，依次选择“文件” > “打开” > “项目/解决方案”。
3. 导航到保存已解压缩的示例代码的文件夹，打开解决方案 (.sln) 文件，然后选择 F5 键以生成并运行项目。

#### 自行创建程序

以下 Windows Presentation Foundation (WPF) 项目包含本主题的代码示例。

若要运行项目，请执行下列步骤：

1. 启动 Visual Studio。

2. 在菜单栏上，依次选择“文件” > “新建” > “项目”。

   **“新建项目”** 对话框随即打开。

3. 选择“已安装” > “Visual C#” > “Windows 桌面”类别，然后从项目模板列表中选择“WPF 应用”。

4. 输入 `AsyncTracer` 作为项目名称，然后选择“确定”按钮。

   新项目将出现在“解决方案资源管理器”中。

5. 在 Visual Studio 代码编辑器中，选择 **“MainWindow.xaml”** 选项卡。

   如果此选项卡不可见，则在“解决方案资源管理器”中，打开 MainWindow.xaml 的快捷菜单，然后选择“查看代码”。

6. 在 MainWindow.xaml 的“XAML”视图中，将代码替换为以下代码。

   ```csharp
   <Window
           xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
           xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
           xmlns:d="http://schemas.microsoft.com/expression/blend/2008" xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006" mc:Ignorable="d" x:Class="AsyncTracer.MainWindow"
           Title="Control Flow Trace" Height="350" Width="592">
       <Grid>
           <Button x:Name="startButton" Content="Start
   " HorizontalAlignment="Left" Margin="250,10,0,0" VerticalAlignment="Top" Width="75" Height="24"  Click="startButton_Click" d:LayoutOverrides="GridBox"/>
           <TextBox x:Name="resultsTextBox" HorizontalAlignment="Left" TextWrapping="Wrap" VerticalAlignment="Bottom" Width="576" Height="265" FontFamily="Lucida Console" FontSize="10" VerticalScrollBarVisibility="Visible" Grid.ColumnSpan="3"/>
       </Grid>
   </Window>
   ```

   MainWindow.xaml 的“设计”视图中将显示一个简单的窗口，其中包含一个文本框和一个按钮。

7. 对 [System.Net.Http](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.http) 添加引用。

8. 在“解决方案资源管理器”中，打开 MainWindow.xaml.cs 的快捷菜单，然后选择“查看代码”。

9. 在 MainWindow.xaml.cs 中，将代码替换为以下代码。

   ```csharp
   using System;
   using System.Collections.Generic;
   using System.Linq;
   using System.Text;
   using System.Threading.Tasks;
   using System.Windows;
   using System.Windows.Controls;
   using System.Windows.Data;
   using System.Windows.Documents;
   using System.Windows.Input;
   using System.Windows.Media;
   using System.Windows.Media.Imaging;
   using System.Windows.Navigation;
   using System.Windows.Shapes;
   
   // Add a using directive and a reference for System.Net.Http;
   using System.Net.Http;
   
   namespace AsyncTracer
   {
       public partial class MainWindow : Window
       {
           public MainWindow()
           {
               InitializeComponent();
           }
   
           private async void startButton_Click(object sender, RoutedEventArgs e)
           {
               // The display lines in the example lead you through the control shifts.
               resultsTextBox.Text += "ONE:   Entering startButton_Click.\r\n" +
                   "           Calling AccessTheWebAsync.\r\n";
   
               Task<int> getLengthTask = AccessTheWebAsync();
   
               resultsTextBox.Text += "\r\nFOUR:  Back in startButton_Click.\r\n" +
                   "           Task getLengthTask is started.\r\n" +
                   "           About to await getLengthTask -- no caller to return to.\r\n";
   
               int contentLength = await getLengthTask;
   
               resultsTextBox.Text += "\r\nSIX:   Back in startButton_Click.\r\n" +
                   "           Task getLengthTask is finished.\r\n" +
                   "           Result from AccessTheWebAsync is stored in contentLength.\r\n" +
                   "           About to display contentLength and exit.\r\n";
   
               resultsTextBox.Text +=
                   $"\r\nLength of the downloaded string: {contentLength}.\r\n";
           }
   
           async Task<int> AccessTheWebAsync()
           {
               resultsTextBox.Text += "\r\nTWO:   Entering AccessTheWebAsync.";
   
               // Declare an HttpClient object.
               HttpClient client = new HttpClient();
   
               resultsTextBox.Text += "\r\n           Calling HttpClient.GetStringAsync.\r\n";
   
               // GetStringAsync returns a Task<string>.
               Task<string> getStringTask = client.GetStringAsync("https://msdn.microsoft.com");
   
               resultsTextBox.Text += "\r\nTHREE: Back in AccessTheWebAsync.\r\n" +
                   "           Task getStringTask is started.";
   
               // AccessTheWebAsync can continue to work until getStringTask is awaited.
   
               resultsTextBox.Text +=
                   "\r\n           About to await getStringTask and return a Task<int> to startButton_Click.\r\n";
   
               // Retrieve the website contents when task is complete.
               string urlContents = await getStringTask;
   
               resultsTextBox.Text += "\r\nFIVE:  Back in AccessTheWebAsync." +
                   "\r\n           Task getStringTask is complete." +
                   "\r\n           Processing the return statement." +
                   "\r\n           Exiting from AccessTheWebAsync.\r\n";
   
               return urlContents.Length;
           }
       }
   }
   ```

10. 按 F5 键运行程序，然后选择“启动”按钮。

    将显示以下输出：

    ```text
    ONE:   Entering startButton_Click.
               Calling AccessTheWebAsync.
    
    TWO:   Entering AccessTheWebAsync.
               Calling HttpClient.GetStringAsync.
    
    THREE: Back in AccessTheWebAsync.
               Task getStringTask is started.
               About to await getStringTask & return a Task<int> to startButton_Click.
    
    FOUR:  Back in startButton_Click.
               Task getLengthTask is started.
               About to await getLengthTask -- no caller to return to.
    
    FIVE:  Back in AccessTheWebAsync.
               Task getStringTask is complete.
               Processing the return statement.
               Exiting from AccessTheWebAsync.
    
    SIX:   Back in startButton_Click.
               Task getLengthTask is finished.
               Result from AccessTheWebAsync is stored in contentLength.
               About to display contentLength and exit.
    
    Length of the downloaded string: 33946.
    ```

#### 跟踪程序

#### 步骤 1 和步骤 2

在 `startButton_Click` 调用 `AccessTheWebAsync` 及 `AccessTheWebAsync` 调用异步 [HttpClient](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.http.httpclient) 方法 [GetStringAsync(String)](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.http.httpclient.getstringasync#System_Net_Http_HttpClient_GetStringAsync_System_String_) 时，前两个显示行会跟踪路径。 下图概述了从方法到方法的调用。

![步骤 1 和步骤 2](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/media/asynctrace-onetwo.png)

`AccessTheWebAsync` 和 `client.GetStringAsync` 的返回类型都是 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1)。 对于 `AccessTheWebAsync`，TResult 是一个整数。 对于 `GetStringAsync`，TResult 是一个字符串。 有关异步方法返回类型的详细信息，请参阅[异步返回类型 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/async-return-types)。

在控制切换回调用方时，任务返回异步方法将返回一个任务实例。 在调用的方法中遇到 `await` 运算符或在调用的方法结束时，控制会从异步方法返回其调用方。 标记为“3”到“6”的显示行将跟踪过程的这一部分。

##### 步骤 3

在 `AccessTheWebAsync` 中，调用异步方法 [GetStringAsync(String)](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.http.httpclient.getstringasync#System_Net_Http_HttpClient_GetStringAsync_System_String_) 以下载目标网页的内容。 返回 `client.GetStringAsync` 时，控制将从 `client.GetStringAsync` 返回到 `AccessTheWebAsync`。

`client.GetStringAsync` 方法将返回分配给 `AccessTheWebAsync` 中的 `getStringTask` 变量的字符串任务。 该示例程序中的以下行说明了对 `client.GetStringAsync` 的调用和赋值。

```csharp
Task<string> getStringTask = client.GetStringAsync("https://msdn.microsoft.com");
```

可以将任务视为 `client.GetStringAsync` 的一个承诺，用于最终生成实际字符串。 同时，如果 `AccessTheWebAsync`有要执行的工作，且该工作不依赖于 `client.GetStringAsync` 中承诺的字符串，则可在 `client.GetStringAsync` 等待时继续此工作。 在示例中，以下标记为“3”的输出行表示执行独立工作的机会

```
THREE: Back in AccessTheWebAsync.
           Task getStringTask is started.
           About to await getStringTask & return a Task<int> to startButton_Click.
```

当 `getStringTask` 处于等待状态时，下面的语句将暂停 `AccessTheWebAsync` 中的进度。

```csharp
string urlContents = await getStringTask;
```

下图显示了从 `client.GetStringAsync` 到 `getStringTask` 的赋值和从 `getStringTask` 的创建到 await 运算符的应用程序的控制流。

![步骤 3](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/media/asynctrace-three.png)

Await 表达式将暂停 `AccessTheWebAsync`，直到返回 `client.GetStringAsync`。 同时，控件返回至 `AccessTheWebAsync` 的调用方 `startButton_Click`。

 备注

通常情况下，应立即等待对异步方法的调用。 例如，以下赋值可以替换前面创建的代码，然后等待 `getStringTask`：`string urlContents = await client.GetStringAsync("https://msdn.microsoft.com");`

在本主题中，稍后将应用 await 运算符，以容纳通过程序标记控制流的输出行。

##### 步骤 4

`AccessTheWebAsync` 的声明的返回类型是 `Task<int>`。 因此，当 `AccessTheWebAsync` 处于挂起状态时，它会将整数任务返回到 `startButton_Click`。 应该了解返回的任务不是 `getStringTask`。 返回的任务是一个新的整数任务，它表示挂起的方法 `AccessTheWebAsync` 中仍需完成的任务。 该任务是 `AccessTheWebAsync` 中的一个承诺，当任务完成时，将生成一个整数。

下列语句将此任务分配给 `getLengthTask` 变量。

```csharp
Task<int> getLengthTask = AccessTheWebAsync();
```

如 `AccessTheWebAsync` 中一样，`startButton_Click` 可以继续执行不依赖于异步任务 (`getLengthTask`) 的结果的工作，直到该任务处于等待状态。 下面的输出行表示该工作。

```
FOUR:  Back in startButton_Click.
           Task getLengthTask is started.
           About to await getLengthTask -- no caller to return to.
```

当 `getLengthTask` 处于等待状态时，`startButton_Click` 中的进度将挂起。 下面的赋值语句将挂起 `startButton_Click`，直到完成 `AccessTheWebAsync`。

```csharp
int contentLength = await getLengthTask;
```

下图中的箭头显示控制流，该控制流从 `AccessTheWebAsync` 中的 await 表达式到 `getLengthTask` 的赋值值，后跟 `startButton_Click` 中的正常处理，直到 `getLengthTask` 处于等待状态。

![步骤 4](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/media/asynctrace-four.png)

##### 步骤 5

当 `client.GetStringAsync` 指示它已完成时，`AccessTheWebAsync` 中的处理将从挂起状态释放，且可以继续通过 await 语句。 下面的输出行表示继续处理。

```
FIVE:  Back in AccessTheWebAsync.
           Task getStringTask is complete.
           Processing the return statement.
           Exiting from AccessTheWebAsync.
```

return 语句 `urlContents.Length` 的操作数存储于 `AccessTheWebAsync` 返回的任务中。 Await 表达式从 `startButton_Click` 中的 `getLengthTask` 检索该值。

下图显示了完成 `client.GetStringAsync`（和 `getStringTask`）后控制的转移。

![步骤 5](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/media/asynctrace-five.png)

`AccessTheWebAsync` 将一直运行直到完成，且控制将返回到 `startButton_Click`，它正在等待完成。

##### 步骤 6

当 `AccessTheWebAsync` 指示它已完成时，处理可以继续通过 `startButton_Async` 中的 await 语句。 事实上，该程序没有更多可执行的操作。

下面的输出行表示 `startButton_Async` 中处理的恢复：

```
SIX:   Back in startButton_Click.
           Task getLengthTask is finished.
           Result from AccessTheWebAsync is stored in contentLength.
           About to display contentLength and exit.
```

Await 表达式从 `getLengthTask` 中检索为 `AccessTheWebAsync` 中 return 语句的操作数的整数值。 下面的语句将该值赋给 `contentLength` 变量。

```csharp
int contentLength = await getLengthTask;
```

下图显示从 `AccessTheWebAsync` 到 `startButton_Click` 的控制的返回。

![步骤 6](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/media/asynctrace-six.png)

### [Fine-Tuning Your Async Application](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/async/fine-tuning-your-async-application)

可以使用由 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task) 类型提供的方法和属性将精度和灵活性添加到异步应用程序。 本部分中的主题介绍使用[CancellationToken](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.cancellationtoken) 的示例和一些重要的 `Task` 方法，例如 [Task.WhenAll](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task.whenall) 和 [Task.WhenAny](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task.whenany)。

使用 `WhenAny` 和 `WhenAll` 可以更轻松地启动多个任务并通过监视单个任务待其完成。

- 集合中的任何任务完成时，`WhenAny` 将返回完成的任务。

  有关使用 `WhenAny` 的示例，请参阅[在完成一个异步任务后取消剩余任务 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/cancel-remaining-async-tasks-after-one-is-complete) 和[启动多个异步任务并在其完成时进行处理 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/start-multiple-async-tasks-and-process-them-as-they-complete)。

- 集合中的所有任务完成时，`WhenAll` 将返回完成的任务。

  有关使用 `WhenAll` 的详细信息和示例，请参阅 [如何：使用 Task.WhenAll 扩展异步演练 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/how-to-extend-the-async-walkthrough-by-using-task-whenall)。

本部分包括下列示例。

- [取消一个异步任务或一组任务(C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/cancel-an-async-task-or-a-list-of-tasks)。
- [在一段时间后取消异步任务 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/cancel-async-tasks-after-a-period-of-time)
- [在完成一个异步任务后取消剩余任务 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/cancel-remaining-async-tasks-after-one-is-complete)
- [启动多个异步任务并在其完成时进行处理 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/start-multiple-async-tasks-and-process-them-as-they-complete)

> 若要运行该示例，计算机上必须安装有 Visual Studio 2012 或更高版本和 .NET Framework 4.5 或更高版本。

项目将创建一个 UI，其中包含用于启动进程和取消进程的按钮，如下图所示。 这些按钮名为 `startButton` 和 `cancelButton`。

![WPF 窗口与“取消”按钮](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/media/cancellation.png)

要下载完整的 Windows Presentation Foundation (WPF) 项目，请参阅 [Async Sample:Fine Tuning Your Application](https://code.msdn.microsoft.com/Async-Fine-Tuning-Your-a676abea)（异步示例：微调应用程序）。

#### [Cancel an Async Task or a List of Tasks](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/async/cancel-an-async-task-or-a-list-of-tasks)

如果不想等待异步应用程序完成，可以设置一个按钮用来取消它。 通过遵循本主题中的示例，可以为下载一个或一组网站内容的应用程序添加一个取消按钮。

示例使用[微调异步应用程序 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/fine-tuning-your-async-application) 描述的 UI。

> 若要运行该示例，计算机上必须安装有 Visual Studio 2012 或更高版本和 .NET Framework 4.5 或更高版本。

##### 取消任务

第一个示例将“取消”按钮与单个下载任务关联。 如果在应用程序下载内容时选择按钮，下载将取消。

###### 下载示例

若要下载完整的 Windows Presentation Foundation (WPF) 项目，请参阅 [Async Sample: Fine Tuning Your Application](https://code.msdn.microsoft.com/Async-Fine-Tuning-Your-a676abea)（异步示例：微调应用程序），然后遵循以下步骤。

1. 解压缩下载的文件，然后启动 Visual Studio。
2. 在菜单栏上，依次选择“文件” > “打开” > “项目/解决方案”。
3. 在“打开项目”对话框中，打开保存已解压的示例代码的文件夹，然后打开 AsyncFineTuningCS 的解决方案 (.sln) 文件。
4. 在“解决方案资源管理器”中，打开 “CancelATask” 项目的快捷菜单，然后选择“设为启动项目”。
5. 选择“F5”键以运行项目（或按 Ctrl+F5 以运行该项目，而无需调试它）。

> 如果不想下载项目，可在本主题末尾处查看 MainWindow.xaml.cs 文件。

###### 生成示例

下列更改将“取消”按钮添加到下载网站的应用程序中。 如果不想下载或生成示例，则可在本主题末尾的“完整示例”部分查看最终产品。 星号标记了代码中的更改。

要自行生成示例，请按“下载示例”部分的说明逐步操作，选择“StarterCode”而不是“CancelATask”作为“启动项目”。

然后将下列更改添加到该项目的 MainWindow.xaml.cs 文件。

1. 声明一个 `CancellationTokenSource` 变量 `cts`，它作用于所有访问它的方法。

   ```csharp
   public partial class MainWindow : Window
   {
       // ***Declare a System.Threading.CancellationTokenSource.
       CancellationTokenSource cts;
   ```

2. 为“取消”按钮添加以下事件处理程序。 用户请求取消时，事件处理程序使用 [CancellationTokenSource.Cancel](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.cancellationtokensource.cancel)方法通知 `cts`。

   ```csharp
   // ***Add an event handler for the Cancel button.
   private void cancelButton_Click(object sender, RoutedEventArgs e)
   {
       if (cts != null)
       {
           cts.Cancel();
       }
   }
   ```

3. 为“启动”按钮 `startButton_Click` 在事件处理程序中进行下列更改。

   - 实例化 `CancellationTokenSource`、`cts`。

     ```csharp
     // ***Instantiate the CancellationTokenSource.
     cts = new CancellationTokenSource();
     ```

   - 在 `AccessTheWebAsync` 调用中（该操作下载指定网站的内容），将 `cts` 的[CancellationTokenSource.Token](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.cancellationtokensource.token) 属性作为参数发送。 如果请求取消，则 `Token` 属性传播消息。 如果用户选择取消下载操作，请添加显示消息的 catch 块。 下列代码显示这些更改。

     ```csharp
     try
     {
         // ***Send a token to carry the message if cancellation is requested.
         int contentLength = await AccessTheWebAsync(cts.Token);
         resultsTextBox.Text += $"\r\nLength of the downloaded string: {contentLength}.\r\n";
     }
     // *** If cancellation is requested, an OperationCanceledException results.
     catch (OperationCanceledException)
     {
         resultsTextBox.Text += "\r\nDownload canceled.\r\n";
     }
     catch (Exception)
     {
         resultsTextBox.Text += "\r\nDownload failed.\r\n";
     }
     ```

4. 在 `AccessTheWebAsync` 中，使用 [HttpClient](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.http.httpclient) 类型中 `GetAsync` 方法的 [HttpClient.GetAsync(String, CancellationToken)](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.http.httpclient.getasync#System_Net_Http_HttpClient_GetAsync_System_String_System_Threading_CancellationToken_) 重载来下载网站内容。 将 `ct`（`AccessTheWebAsync` 的 [CancellationToken](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.cancellationtoken) 参数）作为第二个参数传递。 如果用户选择“取消”按钮，则令牌携带消息。

   下列代码显示 `AccessTheWebAsync` 中的更改。

   ```csharp
   // ***Provide a parameter for the CancellationToken.
   async Task<int> AccessTheWebAsync(CancellationToken ct)
   {
       HttpClient client = new HttpClient();
   
       resultsTextBox.Text += "\r\nReady to download.\r\n";
   
       // You might need to slow things down to have a chance to cancel.
       await Task.Delay(250);
   
       // GetAsync returns a Task<HttpResponseMessage>.
       // ***The ct argument carries the message if the Cancel button is chosen.
       HttpResponseMessage response = await client.GetAsync("https://msdn.microsoft.com/library/dd470362.aspx", ct);
   
       // Retrieve the website contents from the HttpResponseMessage.
       byte[] urlContents = await response.Content.ReadAsByteArrayAsync();
   
       // The result of the method is the length of the downloaded website.
       return urlContents.Length;
   }
   ```

5. 如果不取消该程序，它将生成以下输出。

   ```text
   Ready to download.
   Length of the downloaded string: 158125.
   ```

   如果在程序完成下载内容前，选择“取消”按钮，则程序将生成以下输出。

   ```text
   Ready to download.
   Download canceled.
   ```

#####  取消任务列表

通过将相同的 `CancellationTokenSource` 示例与每个任务关联，可以扩展先前的示例，从而取消多个任务。 如果选择“取消”按钮，则将取消所有尚未完成的任务。

######  下载示例

若要下载完整的 Windows Presentation Foundation (WPF) 项目，请参阅 [Async Sample: Fine Tuning Your Application](https://code.msdn.microsoft.com/Async-Fine-Tuning-Your-a676abea)（异步示例：微调应用程序），然后遵循以下步骤。

1. 解压缩下载的文件，然后启动 Visual Studio。

2. 在菜单栏上，依次选择“文件” > “打开” > “项目/解决方案”。

3. 在“打开项目”对话框中，打开保存已解压的示例代码的文件夹，然后打开 AsyncFineTuningCS 的解决方案 (.sln) 文件。

4. 在“解决方案资源管理器”中，打开 “CancelAListOfTasks” 项目的快捷菜单，然后选择“设为启动项目”。

5. 按 F5 键运行此项目。

   选择 Ctrl+F5 键来运行此项目，而无需调试。

如果不想下载项目，可在本主题末尾处查看 MainWindow.xaml.cs 文件。

######  生成示例

要自行扩展示例，请按“下载示例”部分的说明逐步操作，但要选择“CancelATask”作为“启动项目”。 向该项目添加下列更改。 星号标记了程序中的更改。

1. 添加一个方法，用于创建 Web 地址的列表。

   ```csharp
   // ***Add a method that creates a list of web addresses.
   private List<string> SetUpURLList()
   {
       List<string> urls = new List<string>
       {
           "https://msdn.microsoft.com",
           "https://msdn.microsoft.com/library/hh290138.aspx",
           "https://msdn.microsoft.com/library/hh290140.aspx",
           "https://msdn.microsoft.com/library/dd470362.aspx",
           "https://msdn.microsoft.com/library/aa578028.aspx",
           "https://msdn.microsoft.com/library/ms404677.aspx",
           "https://msdn.microsoft.com/library/ff730837.aspx"
       };
       return urls;
   }
   ```

2. 在 `AccessTheWebAsync` 中调用方法。

   ```csharp
   // ***Call SetUpURLList to make a list of web addresses.
   List<string> urlList = SetUpURLList();
   ```

3. 在 `AccessTheWebAsync` 中添加下列循环，用于处理列表中的每个 Web 地址。

   ```csharp
   // ***Add a loop to process the list of web addresses.
   foreach (var url in urlList)
   {
       // GetAsync returns a Task<HttpResponseMessage>.
       // Argument ct carries the message if the Cancel button is chosen.
       // ***Note that the Cancel button can cancel all remaining downloads.
       HttpResponseMessage response = await client.GetAsync(url, ct);
   
       // Retrieve the website contents from the HttpResponseMessage.
       byte[] urlContents = await response.Content.ReadAsByteArrayAsync();
   
       resultsTextBox.Text +=
           $"\r\nLength of the downloaded string: {urlContents.Length}.\r\n";
   }
   ```

4. 由于 `AccessTheWebAsync` 显示了长度，因此该方法无需返回任何内容。 删除返回语句，并将方法的返回类型更改为 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task)，而不是 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1)。

   ```csharp
   async Task AccessTheWebAsync(CancellationToken ct)
   ```

   使用语句而非表达式从 `startButton_Click` 调用方法。

   ```csharp
   await AccessTheWebAsync(cts.Token);
   ```

5. 如果不取消该程序，它将生成以下输出。

   ```text
   Length of the downloaded string: 35939.
   
   Length of the downloaded string: 237682.
   
   Length of the downloaded string: 128607.
   
   Length of the downloaded string: 158124.
   
   Length of the downloaded string: 204890.
   
   Length of the downloaded string: 175488.
   
   Length of the downloaded string: 145790.
   
   Downloads complete.
   ```

   如果在下载完成之前选择“取消”按钮，则输出将包含取消前已完成下载的长度。

   ```text
   Length of the downloaded string: 35939.
   
   Length of the downloaded string: 237682.
   
   Length of the downloaded string: 128607.
   
   Downloads canceled.
   ```

#####  完成示例

以下各部分包含每个前面示例的代码。 请注意，必须为 [System.Net.Http](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.http) 添加引用。

可以从 [Async Sample: Fine Tuning Your Application](https://code.msdn.microsoft.com/Async-Fine-Tuning-Your-a676abea)（异步示例：微调应用程序）下载这些项目。

######  示例 - 取消任务

下列代码是取消单个任务示例的完整 MainWindow.xaml.cs 文件。

```csharp
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

// Add a using directive and a reference for System.Net.Http.
using System.Net.Http;

// Add the following using directive for System.Threading.

using System.Threading;
namespace CancelATask
{
    public partial class MainWindow : Window
    {
        // ***Declare a System.Threading.CancellationTokenSource.
        CancellationTokenSource cts;

        public MainWindow()
        {
            InitializeComponent();
        }

        private async void startButton_Click(object sender, RoutedEventArgs e)
        {
            // ***Instantiate the CancellationTokenSource.
            cts = new CancellationTokenSource();

            resultsTextBox.Clear();

            try
            {
                // ***Send a token to carry the message if cancellation is requested.
                int contentLength = await AccessTheWebAsync(cts.Token);
                resultsTextBox.Text +=
                    $"\r\nLength of the downloaded string: {contentLength}.\r\n";
            }
            // *** If cancellation is requested, an OperationCanceledException results.
            catch (OperationCanceledException)
            {
                resultsTextBox.Text += "\r\nDownload canceled.\r\n";
            }
            catch (Exception)
            {
                resultsTextBox.Text += "\r\nDownload failed.\r\n";
            }

            // ***Set the CancellationTokenSource to null when the download is complete.
            cts = null;
        }

        // ***Add an event handler for the Cancel button.
        private void cancelButton_Click(object sender, RoutedEventArgs e)
        {
            if (cts != null)
            {
                cts.Cancel();
            }
        }

        // ***Provide a parameter for the CancellationToken.
        async Task<int> AccessTheWebAsync(CancellationToken ct)
        {
            HttpClient client = new HttpClient();

            resultsTextBox.Text += "\r\nReady to download.\r\n";

            // You might need to slow things down to have a chance to cancel.
            await Task.Delay(250);

            // GetAsync returns a Task<HttpResponseMessage>.
            // ***The ct argument carries the message if the Cancel button is chosen.
            HttpResponseMessage response = await client.GetAsync("https://msdn.microsoft.com/library/dd470362.aspx", ct);

            // Retrieve the website contents from the HttpResponseMessage.
            byte[] urlContents = await response.Content.ReadAsByteArrayAsync();

            // The result of the method is the length of the downloaded website.
            return urlContents.Length;
        }
    }

    // Output for a successful download:

    // Ready to download.

    // Length of the downloaded string: 158125.

    // Or, if you cancel:

    // Ready to download.

    // Download canceled.
}
```

######  示例 - 取消任务列表

下列代码是取消任务列表示例的完整 MainWindow.xaml.cs 文件。

```csharp
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

// Add a using directive and a reference for System.Net.Http.
using System.Net.Http;

// Add the following using directive for System.Threading.
using System.Threading;

namespace CancelAListOfTasks
{
    public partial class MainWindow : Window
    {
        // Declare a System.Threading.CancellationTokenSource.
        CancellationTokenSource cts;

        public MainWindow()
        {
            InitializeComponent();
        }

        private async void startButton_Click(object sender, RoutedEventArgs e)
        {
            // Instantiate the CancellationTokenSource.
            cts = new CancellationTokenSource();

            resultsTextBox.Clear();

            try
            {
                await AccessTheWebAsync(cts.Token);
                // ***Small change in the display lines.
                resultsTextBox.Text += "\r\nDownloads complete.";
            }
            catch (OperationCanceledException)
            {
                resultsTextBox.Text += "\r\nDownloads canceled.";
            }
            catch (Exception)
            {
                resultsTextBox.Text += "\r\nDownloads failed.";
            }

            // Set the CancellationTokenSource to null when the download is complete.
            cts = null;
        }

        // Add an event handler for the Cancel button.
        private void cancelButton_Click(object sender, RoutedEventArgs e)
        {
            if (cts != null)
            {
                cts.Cancel();
            }
        }

        // Provide a parameter for the CancellationToken.
        // ***Change the return type to Task because the method has no return statement.
        async Task AccessTheWebAsync(CancellationToken ct)
        {
            // Declare an HttpClient object.
            HttpClient client = new HttpClient();

            // ***Call SetUpURLList to make a list of web addresses.
            List<string> urlList = SetUpURLList();

            // ***Add a loop to process the list of web addresses.
            foreach (var url in urlList)
            {
                // GetAsync returns a Task<HttpResponseMessage>.
                // Argument ct carries the message if the Cancel button is chosen.
                // ***Note that the Cancel button can cancel all remaining downloads.
                HttpResponseMessage response = await client.GetAsync(url, ct);

                // Retrieve the website contents from the HttpResponseMessage.
                byte[] urlContents = await response.Content.ReadAsByteArrayAsync();

                resultsTextBox.Text +=
                    $"\r\nLength of the downloaded string: {urlContents.Length}.\r\n";
            }
        }

        // ***Add a method that creates a list of web addresses.
        private List<string> SetUpURLList()
        {
            List<string> urls = new List<string>
            {
                "https://msdn.microsoft.com",
                "https://msdn.microsoft.com/library/hh290138.aspx",
                "https://msdn.microsoft.com/library/hh290140.aspx",
                "https://msdn.microsoft.com/library/dd470362.aspx",
                "https://msdn.microsoft.com/library/aa578028.aspx",
                "https://msdn.microsoft.com/library/ms404677.aspx",
                "https://msdn.microsoft.com/library/ff730837.aspx"
            };
            return urls;
        }
    }

    // Output if you do not choose to cancel:

    //Length of the downloaded string: 35939.

    //Length of the downloaded string: 237682.

    //Length of the downloaded string: 128607.

    //Length of the downloaded string: 158124.

    //Length of the downloaded string: 204890.

    //Length of the downloaded string: 175488.

    //Length of the downloaded string: 145790.

    //Downloads complete.

    // Sample output if you choose to cancel:

    //Length of the downloaded string: 35939.

    //Length of the downloaded string: 237682.

    //Length of the downloaded string: 128607.

    //Downloads canceled.
}
```

#### [Cancel Async Tasks after a Period of Time](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/async/cancel-async-tasks-after-a-period-of-time)

如果不希望等待操作结束，可使用 [CancellationTokenSource.CancelAfter](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.cancellationtokensource.cancelafter) 方法在一段时间后取消异步操作。 此方法会计划取消未在 `CancelAfter` 表达式指定的时间段内完成的任何关联任务。

此示例添加到[取消异步任务或任务列表 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/cancel-an-async-task-or-a-list-of-tasks)中开发的代码，以下载网站列表并显示每个网站的内容长度。

> 若要运行该示例，计算机上必须安装有 Visual Studio 2012 或更高版本和 .NET Framework 4.5 或更高版本。

##### 下载示例

若要下载完整的 Windows Presentation Foundation (WPF) 项目，请参阅 [Async Sample: Fine Tuning Your Application](https://code.msdn.microsoft.com/Async-Fine-Tuning-Your-a676abea)（异步示例：微调应用程序），然后遵循以下步骤。

1. 解压缩下载的文件，然后启动 Visual Studio。
2. 在菜单栏上，依次选择“文件” > “打开” > “项目/解决方案”。
3. 在“打开项目”对话框中，打开保存已解压的示例代码的文件夹，然后打开 AsyncFineTuningCS 的解决方案 (.sln) 文件。
4. 在“解决方案资源管理器”中，打开“CancelAfterTime”项目的快捷菜单，然后选择“设为启动项目”。
5. 按 F5 键运行此项目。 （或者，按 Ctrl +F5 运行该项目，无需调试）。
6. 多次运行程序以验证输出是否显示所有网站的输出、不显示网站的输出或显示某些网站的输出。

如果不想下载项目，可在本主题末尾处查看 MainWindow.xaml.cs 文件。

##### 生成示例

本主题中的示例添加到[取消异步任务或任务列表 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/cancel-an-async-task-or-a-list-of-tasks)中开发的项目，以取消任务列表。 该示例使用相同的 UI，但未显示使用“取消”按钮。

若要自行生成示例，请按“下载示例”部分的说明逐步操作，选择“CancelAListOfTasks”作为“启动项目”。 将此主题中的更改添加到该项目。

若要指定将任务标记为取消之前的最长时间，请将对 `CancelAfter` 的调用添加到 `startButton_Click`，如以下示例所示。 新增内容标有星号。

```csharp
private async void startButton_Click(object sender, RoutedEventArgs e)
{
    // Instantiate the CancellationTokenSource.
    cts = new CancellationTokenSource();

    resultsTextBox.Clear();

    try
    {
        // ***Set up the CancellationTokenSource to cancel after 2.5 seconds. (You
        // can adjust the time.)
        cts.CancelAfter(2500);

        await AccessTheWebAsync(cts.Token);
        resultsTextBox.Text += "\r\nDownloads succeeded.\r\n";
    }
    catch (OperationCanceledException)
    {
        resultsTextBox.Text += "\r\nDownloads canceled.\r\n";
    }
    catch (Exception)
    {
        resultsTextBox.Text += "\r\nDownloads failed.\r\n";
    }

    cts = null;
}
```

多次运行程序以验证输出是否显示所有网站的输出、不显示网站的输出或显示某些网站的输出。 以下输出为示例。

```
Length of the downloaded string: 35990.

Length of the downloaded string: 407399.

Length of the downloaded string: 226091.

Downloads canceled.
```

##### 完整示例

下列代码是示例的 MainWindow.xaml.cs 文件的完整文本。 对添加到此示例的元素进行了星号标记。

请注意，必须为 [System.Net.Http](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.http) 添加引用。

可以从 [Async Sample: Fine Tuning Your Application](https://code.msdn.microsoft.com/Async-Fine-Tuning-Your-a676abea)（异步示例：微调应用程序）下载这些项目。

```csharp
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

// Add a using directive and a reference for System.Net.Http.
using System.Net.Http;

// Add the following using directive.
using System.Threading;

namespace CancelAfterTime
{
    public partial class MainWindow : Window
    {
        // Declare a System.Threading.CancellationTokenSource.
        CancellationTokenSource cts;

        public MainWindow()
        {
            InitializeComponent();
        }

        private async void startButton_Click(object sender, RoutedEventArgs e)
        {
            // Instantiate the CancellationTokenSource.
            cts = new CancellationTokenSource();

            resultsTextBox.Clear();

            try
            {
                // ***Set up the CancellationTokenSource to cancel after 2.5 seconds. (You
                // can adjust the time.)
                cts.CancelAfter(2500);

                await AccessTheWebAsync(cts.Token);
                resultsTextBox.Text += "\r\nDownloads succeeded.\r\n";
            }
            catch (OperationCanceledException)
            {
                resultsTextBox.Text += "\r\nDownloads canceled.\r\n";
            }
            catch (Exception)
            {
                resultsTextBox.Text += "\r\nDownloads failed.\r\n";
            }

            cts = null;
        }

        // You can still include a Cancel button if you want to.
        private void cancelButton_Click(object sender, RoutedEventArgs e)
        {
            if (cts != null)
            {
                cts.Cancel();
            }
        }

        async Task AccessTheWebAsync(CancellationToken ct)
        {
            // Declare an HttpClient object.
            HttpClient client = new HttpClient();

            // Make a list of web addresses.
            List<string> urlList = SetUpURLList();

            foreach (var url in urlList)
            {
                // GetAsync returns a Task<HttpResponseMessage>.
                // Argument ct carries the message if the Cancel button is chosen.
                // Note that the Cancel button cancels all remaining downloads.
                HttpResponseMessage response = await client.GetAsync(url, ct);

                // Retrieve the website contents from the HttpResponseMessage.
                byte[] urlContents = await response.Content.ReadAsByteArrayAsync();

                resultsTextBox.Text +=
                    $"\r\nLength of the downloaded string: {urlContents.Length}.\r\n";
            }
        }

        private List<string> SetUpURLList()
        {
            List<string> urls = new List<string>
            {
                "https://msdn.microsoft.com",
                "https://msdn.microsoft.com/library/windows/apps/br211380.aspx",
                "https://msdn.microsoft.com/library/hh290136.aspx",
                "https://msdn.microsoft.com/library/ee256749.aspx",
                "https://msdn.microsoft.com/library/ms404677.aspx",
                "https://msdn.microsoft.com/library/ff730837.aspx"
            };
            return urls;
        }
    }

    // Sample Output:

    // Length of the downloaded string: 35990.

    // Length of the downloaded string: 407399.

    // Length of the downloaded string: 226091.

    // Downloads canceled.
}
```

#### [Cancel Remaining Async Tasks after One Is Complete](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/async/cancel-remaining-async-tasks-after-one-is-complete)

通过结合使用 [Task.WhenAny](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task.whenany) 方法和 [CancellationToken](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.cancellationtoken)，可在一个任务完成时取消所有剩余任务。 `WhenAny` 方法采用任务集合中的一个参数。 该方法启动所有任务，并返回单个任务。 当集合中任意任务完成时，完成单个任务。

此示例演示如何结合使用取消标记与 `WhenAny` 保留任务集合中第一个要完成的任务，并取消剩余任务。 每个任务都下载网站内容。 本示例显示第一个完成的下载的内容长度，并取消其他下载。

> 若要运行该示例，计算机上必须安装有 Visual Studio 2012 或更高版本和 .NET Framework 4.5 或更高版本。

##### 下载示例

若要下载完整的 Windows Presentation Foundation (WPF) 项目，请参阅 [Async Sample:Fine Tuning Your Application](https://code.msdn.microsoft.com/Async-Fine-Tuning-Your-a676abea)（异步示例：微调应用程序）。

1. 解压缩下载的文件，然后启动 Visual Studio。

2. 在菜单栏上，依次选择 **“文件”**、 **“打开”** 和 **“项目/解决方案”**。

3. 在“打开项目”对话框中，打开保存已解压的示例代码的文件夹，然后打开 AsyncFineTuningCS 的解决方案 (.sln) 文件。

4. 在“解决方案资源管理器”中，打开“CancelAfterOneTask”项目的快捷菜单，然后选择“设为启动项目”。

5. 选择 F5 键运行该项目。

   选择 Ctrl+F5 键运行该项目，而不进行调试。

6. 运行程序若干次，以验证首先完成的下载是不同的。

如果不想下载项目，可在本主题末尾处查看 MainWindow.xaml.cs 文件。

##### 生成示例

本主题中的示例添加到[取消异步任务或任务列表 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/cancel-an-async-task-or-a-list-of-tasks)中开发的项目，以取消任务列表。 该示例使用相同的 UI，但未显示使用“取消”按钮。

若要自行生成示例，请按“下载示例”部分的说明逐步操作，选择“CancelAListOfTasks”作为“启动项目”。 将此主题中的更改添加到该项目。

在 **CancelAListOfTasks** 项目的 MainWindow.xaml.cs 文件中，通过将每个网站的处理步骤从 `AccessTheWebAsync`中的循环移动至下列异步方法来启动转换。

```csharp
/ ***Bundle the processing steps for a website into one async method.  
async Task<int> ProcessURLAsync(string url, HttpClient client, CancellationToken ct)  
{  
    // GetAsync returns a Task<HttpResponseMessage>.   
    HttpResponseMessage response = await client.GetAsync(url, ct);  
  
    // Retrieve the website contents from the HttpResponseMessage.  
    byte[] urlContents = await response.Content.ReadAsByteArrayAsync();  
  
    return urlContents.Length;  
}  
```

在 `AccessTheWebAsync` 中，此示例使用查询、[ToArray](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.toarray) 方法和 `WhenAny` 方法创建并启动任务数组。 将 `WhenAny`应用到数组将返回单个任务，该任务在等待时对任务数组中首先完成的任务进行评估。

在 `AccessTheWebAsync` 中，进行下列更改。 星号标记了代码文件中的更改。

1. 注释禁止或删除循环。

2. 创建一个查询，它在执行时将生成常规任务的集合。 每次调用 `ProcessURLAsync` 均在 `TResult` 为整数时返回 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1)。

   ```csharp
   // ***Create a query that, when executed, returns a collection of tasks.  
   IEnumerable<Task<int>> downloadTasksQuery =  
       from url in urlList select ProcessURLAsync(url, client, ct);  
   ```

3. 通过调用 `ToArray` 来执行查询并启动任务。 下一步中应用 `WhenAny` 方法将在不使用 `ToArray` 的情况下执行查询并启动任务，但其他方法可能无法执行此操作。 最安全的做法是显式强制执行查询。

   ```csharp
   // ***Use ToArray to execute the query and start the download tasks.   
   Task<int>[] downloadTasks = downloadTasksQuery.ToArray();  
   ```

4. 在任务集合上调用 `WhenAny`。 `WhenAny` 返回 `Task(Of Task(Of Integer))` 或 `Task<Task<int>>`。 也就是说，在等待时 `WhenAny` 将返回一个任务，它将评估单个的 `Task(Of Integer)` 或 `Task<int>`。 该单个任务是集合中首先完成的任务。 首先完成的任务被分配给 `firstFinishedTask`。 `firstFinishedTask` 的类型为 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1)，其中 `TResult` 是整数，这是因为它是 `ProcessURLAsync` 的返回类型。

   ```csharp
   // ***Call WhenAny and then await the result. The task that finishes   
   // first is assigned to firstFinishedTask.  
   Task<int> firstFinishedTask = await Task.WhenAny(downloadTasks);  
   ```

5. 在此示例中，你只对首先完成的任务感兴趣。 因此，使用 [CancellationTokenSource.Cancel](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.cancellationtokensource.cancel) 取消剩余任务。

   ```csharp
   // ***Cancel the rest of the downloads. You just want the first one.  
   cts.Cancel();  
   ```

6. 最后，等待 `firstFinishedTask` 检索下载内容的长度。

   ```csharp
   var length = await firstFinishedTask;  
   resultsTextBox.Text += $"\r\nLength of the downloaded website:  {length}\r\n";
   ```

运行程序若干次，以验证首先完成的下载是不同的。

##### 完整的示例

下列代码是示例的完整 MainWindow.xaml.cs 文件。 对添加到此示例的元素进行了星号标记。

请注意，必须为 [System.Net.Http](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.http) 添加引用。

可以从 [Async Sample:Fine Tuning Your Application](https://code.msdn.microsoft.com/Async-Fine-Tuning-Your-a676abea)（异步示例：微调应用程序）下载这些项目。

```csharp
using System;  
using System.Collections.Generic;  
using System.Linq;  
using System.Text;  
using System.Threading.Tasks;  
using System.Windows;  
using System.Windows.Controls;  
using System.Windows.Data;  
using System.Windows.Documents;  
using System.Windows.Input;  
using System.Windows.Media;  
using System.Windows.Media.Imaging;  
using System.Windows.Navigation;  
using System.Windows.Shapes;  
  
// Add a using directive and a reference for System.Net.Http.  
using System.Net.Http;  
  
// Add the following using directive.  
using System.Threading;  
  
namespace CancelAfterOneTask  
{  
    public partial class MainWindow : Window  
    {  
        // Declare a System.Threading.CancellationTokenSource.  
        CancellationTokenSource cts;  
  
        public MainWindow()  
        {  
            InitializeComponent();  
        }  
  
        private async void startButton_Click(object sender, RoutedEventArgs e)  
        {  
            // Instantiate the CancellationTokenSource.  
            cts = new CancellationTokenSource();  
  
            resultsTextBox.Clear();  
  
            try  
            {  
                await AccessTheWebAsync(cts.Token);  
                resultsTextBox.Text += "\r\nDownload complete.";  
            }  
            catch (OperationCanceledException)  
            {  
                resultsTextBox.Text += "\r\nDownload canceled.";  
            }  
            catch (Exception)  
            {  
                resultsTextBox.Text += "\r\nDownload failed.";  
            }  
  
            // Set the CancellationTokenSource to null when the download is complete.  
            cts = null;  
        }  
  
        // You can still include a Cancel button if you want to.  
        private void cancelButton_Click(object sender, RoutedEventArgs e)  
        {  
            if (cts != null)  
            {  
                cts.Cancel();  
            }  
        }  
  
        // Provide a parameter for the CancellationToken.  
        async Task AccessTheWebAsync(CancellationToken ct)  
        {  
            HttpClient client = new HttpClient();  
  
            // Call SetUpURLList to make a list of web addresses.  
            List<string> urlList = SetUpURLList();  
  
            // ***Comment out or delete the loop.  
            //foreach (var url in urlList)  
            //{  
            //    // GetAsync returns a Task<HttpResponseMessage>.   
            //    // Argument ct carries the message if the Cancel button is chosen.   
            //    // ***Note that the Cancel button can cancel all remaining downloads.  
            //    HttpResponseMessage response = await client.GetAsync(url, ct);  
  
            //    // Retrieve the website contents from the HttpResponseMessage.  
            //    byte[] urlContents = await response.Content.ReadAsByteArrayAsync();  
  
            //    resultsTextBox.Text +=  
            //        $"\r\nLength of the downloaded string: {urlContents.Length}.\r\n";
            //}  
  
            // ***Create a query that, when executed, returns a collection of tasks.  
            IEnumerable<Task<int>> downloadTasksQuery =  
                from url in urlList select ProcessURLAsync(url, client, ct);  
  
            // ***Use ToArray to execute the query and start the download tasks.   
            Task<int>[] downloadTasks = downloadTasksQuery.ToArray();  
  
            // ***Call WhenAny and then await the result. The task that finishes   
            // first is assigned to firstFinishedTask.  
            Task<int> firstFinishedTask = await Task.WhenAny(downloadTasks);  
  
            // ***Cancel the rest of the downloads. You just want the first one.  
            cts.Cancel();  
  
            // ***Await the first completed task and display the results.   
            // Run the program several times to demonstrate that different  
            // websites can finish first.  
            var length = await firstFinishedTask;  
            resultsTextBox.Text += $"\r\nLength of the downloaded website:  {length}\r\n";
        }  
  
        // ***Bundle the processing steps for a website into one async method.  
        async Task<int> ProcessURLAsync(string url, HttpClient client, CancellationToken ct)  
        {  
            // GetAsync returns a Task<HttpResponseMessage>.   
            HttpResponseMessage response = await client.GetAsync(url, ct);  
  
            // Retrieve the website contents from the HttpResponseMessage.  
            byte[] urlContents = await response.Content.ReadAsByteArrayAsync();  
  
            return urlContents.Length;  
        }  
  
        // Add a method that creates a list of web addresses.  
        private List<string> SetUpURLList()  
        {  
            List<string> urls = new List<string>   
            {   
                "https://msdn.microsoft.com",  
                "https://msdn.microsoft.com/library/hh290138.aspx",  
                "https://msdn.microsoft.com/library/hh290140.aspx",  
                "https://msdn.microsoft.com/library/dd470362.aspx",  
                "https://msdn.microsoft.com/library/aa578028.aspx",  
                "https://msdn.microsoft.com/library/ms404677.aspx",  
                "https://msdn.microsoft.com/library/ff730837.aspx"  
            };  
            return urls;  
        }  
    }  
    // Sample output:  
  
    // Length of the downloaded website:  158856  
  
    // Download complete.  
}  
```

#### [Start Multiple Async Tasks and Process Them As They Complete](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/async/start-multiple-async-tasks-and-process-them-as-they-complete)

通过使用 [Task.WhenAny](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task.whenany)，可以同时启动多个任务，并在它们完成时逐个对它们进行处理，而不是按照它们的启动顺序进行处理。

下面的示例使用查询来创建一组任务。 每个任务都下载指定网站的内容。 在对 while 循环的每次迭代中，对 `WhenAny` 的等待调用返回任务集合中首先完成下载的任务。 此任务从集合中删除并进行处理。 循环重复进行，直到集合中不包含任何任务。

> 若要运行示例，计算机上必须安装有 Visual Studio（2012 或更高版本）和 .NET Framework 4.5 或更高版本。

##### 下载示例解决方案

若要下载完整的 Windows Presentation Foundation (WPF) 项目，请参阅 [Async Sample: Fine Tuning Your Application](https://code.msdn.microsoft.com/Async-Fine-Tuning-Your-a676abea)（异步示例：微调应用程序），然后遵循以下步骤。

> 如果不想下载项目，可在本主题末尾处查看 MainWindow.xaml.cs 文件。

1. 从 .zip 文件中提取已下载的文件，然后启动 Visual Studio。
2. 在菜单栏上，依次选择“文件” > “打开” > “项目/解决方案”。
3. 在“打开项目”对话框中，打开保存已下载的示例代码的文件夹，然后打开 AsyncFineTuningCS 的解决方案 (.sln) 文件。
4. 在“解决方案资源管理器”中，打开“ProcessTasksAsTheyFinish”项目的快捷菜单，选择“设为启动项目”。
5. 选择 F5 键以运行此程序（或按 Ctrl+F5 键以运行此程序，而不对其进行调试）。
6. 多次运行此项目以验证并不总是以相同顺序显示已下载的长度。

##### 自行创建程序

本示例对[在一个任务完成后取消剩余异步任务 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/cancel-remaining-async-tasks-after-one-is-complete) 中开发的代码进行了补充，并使用了相同的 UI。

若要自行生成示例，请按[下载示例](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/cancel-remaining-async-tasks-after-one-is-complete#downloading-the-example)部分的说明逐步操作，但将“CancelAfterOneTask”设置为“启动项目”。 将此主题中的更改添加到项目中的 `AccessTheWebAsync` 方法。 这些更改标有星号。

**CancelAfterOneTask** 项目已包含一个查询，执行此查询时，将创建任务集合。 每次对以下代码中的 `ProcessURLAsync` 进行调用都会返回 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1)，其中 `TResult` 是一个整数：

```csharp
IEnumerable<Task<int>> downloadTasksQuery = from url in urlList select ProcessURL(url, client, ct);
```

在项目的 MainWindow.xaml.cs 文件中，对 `AccessTheWebAsync` 方法进行以下更改。

- 通过应用 [Enumerable.ToList](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.tolist) 而非 [ToArray](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.toarray) 执行查询。

  ```csharp
  List<Task<int>> downloadTasks = downloadTasksQuery.ToList();
  ```

- 添加 `while` 循环，针对集合中的每个任务执行以下步骤：

  1. 等待调用 `WhenAny`，以标识集合中首个完成下载的任务。

     ```csharp
     Task<int> firstFinishedTask = await Task.WhenAny(downloadTasks);
     ```

  2. 从集合中移除任务。

     ```csharp
     downloadTasks.Remove(firstFinishedTask);
     ```

  3. 等待 `firstFinishedTask`，由对 `ProcessURLAsync` 的调用返回。 `firstFinishedTask` 变量是 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task-1)，其中 `TReturn` 是整数。 任务已完成，但需等待它检索已下载网站的长度，如以下示例所示。

     ```csharp
     int length = await firstFinishedTask;
     resultsTextBox.Text += $"\r\nLength of the download:  {length}";
     ```

多次运行此程序以验证并不总是以相同顺序显示已下载的长度。

> 如示例所示，可以在循环中使用 `WhenAny` 来解决涉及少量任务的问题。 但是，如果要处理大量任务，可以采用其他更高效的方法。 有关详细信息和示例，请参阅 [Processing tasks as they complete](https://blogs.msdn.microsoft.com/pfxteam/2012/08/02/processing-tasks-as-they-complete/)（在任务完成时处理它们）。

##### 完整示例

下列代码是示例的 MainWindow.xaml.cs 文件的完整文本。 对添加到此示例的元素进行了星号标记。 另请注意，必须为 [System.Net.Http](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.http) 添加引用。

可以从 [Async Sample: Fine Tuning Your Application](https://code.msdn.microsoft.com/Async-Fine-Tuning-Your-a676abea)（异步示例：微调应用程序）下载这些项目。

```csharp
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

// Add a using directive and a reference for System.Net.Http.
using System.Net.Http;

// Add the following using directive.
using System.Threading;

namespace ProcessTasksAsTheyFinish
{
    public partial class MainWindow : Window
    {
        // Declare a System.Threading.CancellationTokenSource.
        CancellationTokenSource cts;

        public MainWindow()
        {
            InitializeComponent();
        }

        private async void startButton_Click(object sender, RoutedEventArgs e)
        {
            resultsTextBox.Clear();

            // Instantiate the CancellationTokenSource.
            cts = new CancellationTokenSource();

            try
            {
                await AccessTheWebAsync(cts.Token);
                resultsTextBox.Text += "\r\nDownloads complete.";
            }
            catch (OperationCanceledException)
            {
                resultsTextBox.Text += "\r\nDownloads canceled.\r\n";
            }
            catch (Exception)
            {
                resultsTextBox.Text += "\r\nDownloads failed.\r\n";
            }

            cts = null;
        }

        private void cancelButton_Click(object sender, RoutedEventArgs e)
        {
            if (cts != null)
            {
                cts.Cancel();
            }
        }

        async Task AccessTheWebAsync(CancellationToken ct)
        {
            HttpClient client = new HttpClient();

            // Make a list of web addresses.
            List<string> urlList = SetUpURLList();

            // ***Create a query that, when executed, returns a collection of tasks.
            IEnumerable<Task<int>> downloadTasksQuery =
                from url in urlList select ProcessURL(url, client, ct);

            // ***Use ToList to execute the query and start the tasks.
            List<Task<int>> downloadTasks = downloadTasksQuery.ToList();

            // ***Add a loop to process the tasks one at a time until none remain.
            while (downloadTasks.Count > 0)
            {
                    // Identify the first task that completes.
                    Task<int> firstFinishedTask = await Task.WhenAny(downloadTasks);

                    // ***Remove the selected task from the list so that you don't
                    // process it more than once.
                    downloadTasks.Remove(firstFinishedTask);

                    // Await the completed task.
                    int length = await firstFinishedTask;
                    resultsTextBox.Text += $"\r\nLength of the download:  {length}";
            }
        }

        private List<string> SetUpURLList()
        {
            List<string> urls = new List<string>
            {
                "https://msdn.microsoft.com",
                "https://msdn.microsoft.com/library/windows/apps/br211380.aspx",
                "https://msdn.microsoft.com/library/hh290136.aspx",
                "https://msdn.microsoft.com/library/dd470362.aspx",
                "https://msdn.microsoft.com/library/aa578028.aspx",
                "https://msdn.microsoft.com/library/ms404677.aspx",
                "https://msdn.microsoft.com/library/ff730837.aspx"
            };
            return urls;
        }

        async Task<int> ProcessURL(string url, HttpClient client, CancellationToken ct)
        {
            // GetAsync returns a Task<HttpResponseMessage>.
            HttpResponseMessage response = await client.GetAsync(url, ct);

            // Retrieve the website contents from the HttpResponseMessage.
            byte[] urlContents = await response.Content.ReadAsByteArrayAsync();

            return urlContents.Length;
        }
    }
}

// Sample Output:

// Length of the download:  226093
// Length of the download:  412588
// Length of the download:  175490
// Length of the download:  204890
// Length of the download:  158855
// Length of the download:  145790
// Length of the download:  44908
// Downloads complete.
```

### [Handling Reentrancy in Async Apps](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/async/handling-reentrancy-in-async-apps)

在应用中包含异步代码时，应考虑并且可以阻止重新进入（指在异步操作完成之前重新进入它）。 如果不识别并处理重新进入的可能性，则它可能会导致意外结果。

**在本主题中**

- [识别重新进入](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/handling-reentrancy-in-async-apps#BKMK_RecognizingReentrancy)
- [处理重新进入](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/handling-reentrancy-in-async-apps#BKMK_HandlingReentrancy)
  - [禁用“开始”按钮](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/handling-reentrancy-in-async-apps#BKMK_DisableTheStartButton)
  - [取消和重启操作](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/handling-reentrancy-in-async-apps#BKMK_CancelAndRestart)
  - [运行多个操作并将输出排入队列](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/handling-reentrancy-in-async-apps#BKMK_RunMultipleOperations)
- [检查并运行示例应用](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/handling-reentrancy-in-async-apps#BKMD_SettingUpTheExample)

> 若要运行该示例，计算机上必须安装 Visual Studio 2012 或更高版本和 .NET Framework 4.5 或更高版本。

#### 识别重新进入

在本主题中的示例中，用户选择“开始”按钮以启动一个异步应用，该应用下载一系列网站并计算下载的总字节数。该示例的同步版本以相同方式进行响应（无论用户选择该按钮多少次），因为在第一次选择之后，UI 线程会忽略这些事件，直到应用完成运行。 但是，在异步应用中，UI 线程会继续响应，你可能会在它完成之前重新进入异步操作。

下面的示例显示用户仅选择“开始”按钮一次时的预期输出。 下载网站的列表会出现，其中包含每个站点的大小（以字节为单位）。 总字节数会在结尾处显示。

```
1. msdn.microsoft.com/library/hh191443.aspx                83732  
2. msdn.microsoft.com/library/aa578028.aspx               205273  
3. msdn.microsoft.com/library/jj155761.aspx                29019  
4. msdn.microsoft.com/library/hh290140.aspx               117152  
5. msdn.microsoft.com/library/hh524395.aspx                68959  
6. msdn.microsoft.com/library/ms404677.aspx               197325  
7. msdn.microsoft.com                                            42972  
8. msdn.microsoft.com/library/ff730837.aspx               146159  
  
TOTAL bytes returned:  890591  
```

但是，如果用户多次选择按钮，则会反复调用事件处理程序，并且每次都会重新进入下载进程。 因此，会有多个异步操作同时运行，输出会使结果交错，而总字节数令人困惑。

复制

```
1. msdn.microsoft.com/library/hh191443.aspx                83732  
2. msdn.microsoft.com/library/aa578028.aspx               205273  
3. msdn.microsoft.com/library/jj155761.aspx                29019  
4. msdn.microsoft.com/library/hh290140.aspx               117152  
5. msdn.microsoft.com/library/hh524395.aspx                68959  
1. msdn.microsoft.com/library/hh191443.aspx                83732  
2. msdn.microsoft.com/library/aa578028.aspx               205273  
6. msdn.microsoft.com/library/ms404677.aspx               197325  
3. msdn.microsoft.com/library/jj155761.aspx                29019  
7. msdn.microsoft.com                                            42972  
4. msdn.microsoft.com/library/hh290140.aspx               117152  
8. msdn.microsoft.com/library/ff730837.aspx               146159  
  
TOTAL bytes returned:  890591  
  
5. msdn.microsoft.com/library/hh524395.aspx                68959  
1. msdn.microsoft.com/library/hh191443.aspx                83732  
2. msdn.microsoft.com/library/aa578028.aspx               205273  
6. msdn.microsoft.com/library/ms404677.aspx               197325  
3. msdn.microsoft.com/library/jj155761.aspx                29019  
4. msdn.microsoft.com/library/hh290140.aspx               117152  
7. msdn.microsoft.com                                            42972  
5. msdn.microsoft.com/library/hh524395.aspx                68959  
8. msdn.microsoft.com/library/ff730837.aspx               146159  
  
TOTAL bytes returned:  890591  
  
6. msdn.microsoft.com/library/ms404677.aspx               197325  
7. msdn.microsoft.com                                            42972  
8. msdn.microsoft.com/library/ff730837.aspx               146159  
  
TOTAL bytes returned:  890591  
```

可以滚动到本主题末尾来评审生成此输出的代码。 可以通过将解决方案下载到本地计算机，然后运行 WebsiteDownload 项目，或是通过使用本主题末尾的代码创建自己的项目，来体验该代码。 有关详细信息和说明，请参阅[检查并运行示例应用](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/handling-reentrancy-in-async-apps#BKMD_SettingUpTheExample)。

#### 处理重新进入

可以采用各种方式处理重新进入，具体取决于希望应用执行的操作。 本主题展示了以下示例：

- [禁用“开始”按钮](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/handling-reentrancy-in-async-apps#BKMK_DisableTheStartButton)

  在操作运行期间禁用“开始”按钮，以便用户无法中断它。

- [取消和重启操作](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/handling-reentrancy-in-async-apps#BKMK_CancelAndRestart)

  当用户再次选择“开始”按钮时取消仍在运行的任何操作，然后让最近请求的操作继续运行。

- [运行多个操作并将输出排入队列](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/handling-reentrancy-in-async-apps#BKMK_RunMultipleOperations)

  允许所有请求的操作异步运行，但是会协调输出的显示，以便每个操作的结果按顺序一起显示。

##### 禁用“开始”按钮

可以通过在 `StartButton_Click` 事件处理程序顶部禁用“开始”按钮，在操作运行期间阻止该按钮。 随后可以在操作完成时从 `finally` 块中重新启用中该按钮，以便用户可以再次运行应用。

若要设置此方案，请对[检查并运行示例应用](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/handling-reentrancy-in-async-apps#BKMD_SettingUpTheExample)中提供的基本代码进行以下更改。 还可以从[异步示例：.NET 桌面应用中的重新进入](https://code.msdn.microsoft.com/Async-Sample-Preventing-a8489f06)下载已完成的应用。 项目名是 DisableStartButton。

```csharp
private async void StartButton_Click(object sender, RoutedEventArgs e)  
{  
    // This line is commented out to make the results clearer in the output.  
    //ResultsTextBox.Text = "";  
  
    // ***Disable the Start button until the downloads are complete.   
    StartButton.IsEnabled = false;   
  
    try  
    {  
        await AccessTheWebAsync();  
    }  
    catch (Exception)  
    {  
        ResultsTextBox.Text += "\r\nDownloads failed.";  
    }  
    // ***Enable the Start button in case you want to run the program again.   
    finally  
    {  
        StartButton.IsEnabled = true;  
    }  
}  
```

由于进行了这些更改，所以该按钮在 `AccessTheWebAsync` 下载网站期间不会进行响应，因此无法重新进入该进程。

##### 取消和重启操作

可以使“开始”按钮保持活动状态而不是禁用该按钮，但是如果用户再次选择该按钮，则取消已在运行的操作，让最近开始的操作继续运行。

有关取消的详细信息，请参阅[微调异步应用程序 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/fine-tuning-your-async-application)。

若要设置此方案，请对[检查并运行示例应用](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/handling-reentrancy-in-async-apps#BKMD_SettingUpTheExample)中提供的基本代码进行以下更改。 还可以从[异步示例：.NET 桌面应用中的重新进入](https://code.msdn.microsoft.com/Async-Sample-Preventing-a8489f06)下载已完成的应用。 项目名是 CancelAndRestart。

1. 声明 [CancellationTokenSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.cancellationtokensource) 变量 `cts`，它处于所有方法的范围内。

   ```csharp
   public partial class MainWindow : Window   // Or class MainPage  
   {  
       // *** Declare a System.Threading.CancellationTokenSource.  
       CancellationTokenSource cts;  
   ```

2. 在 `StartButton_Click` 中，确定操作是否已在进行。 如果 `cts` 的值为 null，则没有任何操作处于活动状态。 如果该值不为 null，则取消已在运行的操作。

   ```csharp
   // *** If a download process is already underway, cancel it.  
   if (cts != null)  
   {  
       cts.Cancel();  
   }  
   ```

3. 将 `cts` 设置为表示当前进程的不同值。

   ```csharp
   // *** Now set cts to a new value that you can use to cancel the current process  
   // if the button is chosen again.  
   CancellationTokenSource newCTS = new CancellationTokenSource();  
   cts = newCTS;  
   ```

4. 在 `StartButton_Click` 末尾，当前进程完成，因此将 `cts` 的值重新设置为 null。

   ```csharp
   // *** When the process is complete, signal that another process can begin.  
   if (cts == newCTS)  
       cts = null;  
   ```

以下代码显示了 `StartButton_Click` 中的所有更改。 新增内容标有星号。

```csharp
private async void StartButton_Click(object sender, RoutedEventArgs e)  
{  
    // This line is commented out to make the results clearer in the output.  
    //ResultsTextBox.Clear();  
  
    // *** If a download process is already underway, cancel it.  
    if (cts != null)  
    {  
        cts.Cancel();  
    }  
  
    // *** Now set cts to cancel the current process if the button is chosen again.  
    CancellationTokenSource newCTS = new CancellationTokenSource();  
    cts = newCTS;  
  
    try  
    {  
        // ***Send cts.Token to carry the message if there is a cancellation request.  
        await AccessTheWebAsync(cts.Token);  
  
    }  
    // *** Catch cancellations separately.  
    catch (OperationCanceledException)  
    {  
        ResultsTextBox.Text += "\r\nDownloads canceled.\r\n";  
    }  
    catch (Exception)  
    {  
        ResultsTextBox.Text += "\r\nDownloads failed.\r\n";  
    }  
    // *** When the process is complete, signal that another process can proceed.  
    if (cts == newCTS)  
        cts = null;  
}  
```

在 `AccessTheWebAsync` 中，进行下列更改。

- 添加参数以从 `StartButton_Click` 接受取消标记。
- 使用 [GetAsync](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.http.httpclient.getasync) 方法下载网站，因为 `GetAsync` 接受 [CancellationToken](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.cancellationtoken) 参数。
- 调用 `DisplayResults` 以显示下载的每个网站的结果之前，检查 `ct` 以验证当前操作是否未取消。

下面的代码演示了这些更改（使用星号标记）。

```csharp
// *** Provide a parameter for the CancellationToken from StartButton_Click.  
async Task AccessTheWebAsync(CancellationToken ct)  
{  
    // Declare an HttpClient object.  
    HttpClient client = new HttpClient();  
  
    // Make a list of web addresses.  
    List<string> urlList = SetUpURLList();  
  
    var total = 0;  
    var position = 0;  
  
    foreach (var url in urlList)  
    {  
        // *** Use the HttpClient.GetAsync method because it accepts a   
        // cancellation token.  
        HttpResponseMessage response = await client.GetAsync(url, ct);  
  
        // *** Retrieve the website contents from the HttpResponseMessage.  
        byte[] urlContents = await response.Content.ReadAsByteArrayAsync();  
  
        // *** Check for cancellations before displaying information about the   
        // latest site.   
        ct.ThrowIfCancellationRequested();  
  
        DisplayResults(url, urlContents, ++position);  
  
        // Update the total.  
        total += urlContents.Length;  
    }  
  
    // Display the total count for all of the websites.  
    ResultsTextBox.Text +=  
        $"\r\n\r\nTOTAL bytes returned:  {total}\r\n";
}     
```

如果在此应用运行期间多次选择“开始”按钮，则它应生成类似于以下输出的结果。

```
1. msdn.microsoft.com/library/hh191443.aspx                83732  
2. msdn.microsoft.com/library/aa578028.aspx               205273  
3. msdn.microsoft.com/library/jj155761.aspx                29019  
4. msdn.microsoft.com/library/hh290140.aspx               122505  
5. msdn.microsoft.com/library/hh524395.aspx                68959  
6. msdn.microsoft.com/library/ms404677.aspx               197325  
Download canceled.  
  
1. msdn.microsoft.com/library/hh191443.aspx                83732  
2. msdn.microsoft.com/library/aa578028.aspx               205273  
3. msdn.microsoft.com/library/jj155761.aspx                29019  
Download canceled.  
  
1. msdn.microsoft.com/library/hh191443.aspx                83732  
2. msdn.microsoft.com/library/aa578028.aspx               205273  
3. msdn.microsoft.com/library/jj155761.aspx                29019  
4. msdn.microsoft.com/library/hh290140.aspx               117152  
5. msdn.microsoft.com/library/hh524395.aspx                68959  
6. msdn.microsoft.com/library/ms404677.aspx               197325  
7. msdn.microsoft.com                                            42972  
8. msdn.microsoft.com/library/ff730837.aspx               146159  
  
TOTAL bytes returned:  890591  
```

若要消除部分列表，请对 `StartButton_Click` 中的第一行代码取消注释以在用户每次重新启动操作时清除文本框。

##### 运行多个操作并将输出排入队列

此第三个示例最复杂，因为应用会在用户每次选择“开始”按钮时启动另一个异步操作，并且所有操作都会运行到完成。 所有请求的操作以异步方式从列表中下载网站，但是操作的输出会按顺序呈现。 也就是说，实际下载活动是交错进行的（如[识别重新进入](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/handling-reentrancy-in-async-apps#BKMK_RecognizingReentrancy)中的输出所示），但是每个组的结果列表会分开呈现。

操作会共享一个全局 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task) (`pendingWork`)，它用作显示进程的守卫。

若要设置此方案，请对[检查并运行示例应用](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/handling-reentrancy-in-async-apps#BKMD_SettingUpTheExample)中提供的基本代码进行以下更改。 还可以从[异步示例：.NET 桌面应用中的重新进入](https://code.msdn.microsoft.com/Async-Sample-Preventing-a8489f06)下载已完成的应用。 项目名是 QueueResults。

下面的输出显示用户仅选择“开始”按钮一次时的结果。 字母标签 A 指示结果来自首次选择“开始”按钮。 编号显示下载目标列表中 URL 的顺序。

```
#Starting group A.  
#Task assigned for group A.  
  
A-1. msdn.microsoft.com/library/hh191443.aspx                87389  
A-2. msdn.microsoft.com/library/aa578028.aspx               209858  
A-3. msdn.microsoft.com/library/jj155761.aspx                30870  
A-4. msdn.microsoft.com/library/hh290140.aspx               119027  
A-5. msdn.microsoft.com/library/hh524395.aspx                71260  
A-6. msdn.microsoft.com/library/ms404677.aspx               199186  
A-7. msdn.microsoft.com                                            53266  
A-8. msdn.microsoft.com/library/ff730837.aspx               148020  
  
TOTAL bytes returned:  918876  
  
#Group A is complete.  
```

如果用户选择“开始”按钮三次，则应用会生成类似于以下各行的输出。 以井号 (#) 开头的信息行会跟踪应用程序的进度。

```
#Starting group A.  
#Task assigned for group A.  
  
A-1. msdn.microsoft.com/library/hh191443.aspx                87389  
A-2. msdn.microsoft.com/library/aa578028.aspx               207089  
A-3. msdn.microsoft.com/library/jj155761.aspx                30870  
A-4. msdn.microsoft.com/library/hh290140.aspx               119027  
A-5. msdn.microsoft.com/library/hh524395.aspx                71259  
A-6. msdn.microsoft.com/library/ms404677.aspx               199185  
  
#Starting group B.  
#Task assigned for group B.  
  
A-7. msdn.microsoft.com                                            53266  
  
#Starting group C.  
#Task assigned for group C.  
  
A-8. msdn.microsoft.com/library/ff730837.aspx               148010  
  
TOTAL bytes returned:  916095  
  
B-1. msdn.microsoft.com/library/hh191443.aspx                87389  
B-2. msdn.microsoft.com/library/aa578028.aspx               207089  
B-3. msdn.microsoft.com/library/jj155761.aspx                30870  
B-4. msdn.microsoft.com/library/hh290140.aspx               119027  
B-5. msdn.microsoft.com/library/hh524395.aspx                71260  
B-6. msdn.microsoft.com/library/ms404677.aspx               199186  
  
#Group A is complete.  
  
B-7. msdn.microsoft.com                                            53266  
B-8. msdn.microsoft.com/library/ff730837.aspx               148010  
  
TOTAL bytes returned:  916097  
  
C-1. msdn.microsoft.com/library/hh191443.aspx                87389  
C-2. msdn.microsoft.com/library/aa578028.aspx               207089  
  
#Group B is complete.  
  
C-3. msdn.microsoft.com/library/jj155761.aspx                30870  
C-4. msdn.microsoft.com/library/hh290140.aspx               119027  
C-5. msdn.microsoft.com/library/hh524395.aspx                72765  
C-6. msdn.microsoft.com/library/ms404677.aspx               199186  
C-7. msdn.microsoft.com                                            56190  
C-8. msdn.microsoft.com/library/ff730837.aspx               148010  
  
TOTAL bytes returned:  920526  
  
#Group C is complete.  
```

组 B 和 C 会在组 A 完成之前开始，但是每个组的输出会分开显示。 组 A 的所有输出会首先显示，后跟组 B 的所有输出，再然后是组 C 的所有输出。应用会始终按顺序显示组，并且对于每个组，始终按 URL 在 URL 列表中的显示顺序来显示有关各个网站的信息。

但是，无法预测下载实际发生的顺序。 在多个组启动之后，它们生成的下载任务都处于活动状态。 无法假定 A-1 会在 B-1 之前下载，并且无法假定 A-1 会在 A-2 之前下载。

##### 全局定义

示例代码包含所有方法都可见的以下两个全局声明。

```csharp
public partial class MainWindow : Window  // Class MainPage in Windows Store app.  
{  
    // ***Declare the following variables where all methods can access them.   
    private Task pendingWork = null;     
    private char group = (char)('A' - 1);  
```

`Task` 变量 `pendingWork` 会监视显示进程并防止任何组中断另一个组的显示操作。 字符变量 `group` 标记来自不同组的输出以验证结果是否按预期顺序出现。

##### 单击事件处理程序

事件处理程序 `StartButton_Click` 会在用户每次选择“开始”按钮时增加组号。 随后处理程序会调用 `AccessTheWebAsync` 以运行下载操作。

```csharp
private async void StartButton_Click(object sender, RoutedEventArgs e)  
{  
    // ***Verify that each group's results are displayed together, and that  
    // the groups display in order, by marking each group with a letter.  
    group = (char)(group + 1);  
    ResultsTextBox.Text += $"\r\n\r\n#Starting group {group}.";
  
    try  
    {  
        // *** Pass the group value to AccessTheWebAsync.  
        char finishedGroup = await AccessTheWebAsync(group);  
  
        // The following line verifies a successful return from the download and  
        // display procedures.   
        ResultsTextBox.Text += $"\r\n\r\n#Group {finishedGroup} is complete.\r\n";
    }  
    catch (Exception)  
    {  
        ResultsTextBox.Text += "\r\nDownloads failed.";  
    }  
}  
```

##### AccessTheWebAsync 方法

此示例将 `AccessTheWebAsync` 拆分为两个方法。 第一个方法 `AccessTheWebAsync` 会为组启动所有下载任务并设置 `pendingWork` 以控制显示进程。 该方法使用语言集成查询（LINQ 查询）和 [ToArray](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.toarray) 同时启动所有下载任务。

`AccessTheWebAsync` 随后调用 `FinishOneGroupAsync` 以等待每个下载完成并显示其长度。

`FinishOneGroupAsync` 会返回在 `AccessTheWebAsync` 中分配给 `pendingWork` 的任务。 该值会在任务完成之前阻止另一个操作进行中断。

```csharp
private async Task<char> AccessTheWebAsync(char grp)  
{  
    HttpClient client = new HttpClient();  
  
    // Make a list of the web addresses to download.  
    List<string> urlList = SetUpURLList();  
  
    // ***Kick off the downloads. The application of ToArray activates all the download tasks.  
    Task<byte[]>[] getContentTasks = urlList.Select(url => client.GetByteArrayAsync(url)).ToArray();  
  
    // ***Call the method that awaits the downloads and displays the results.  
    // Assign the Task that FinishOneGroupAsync returns to the gatekeeper task, pendingWork.  
    pendingWork = FinishOneGroupAsync(urlList, getContentTasks, grp);  
  
    ResultsTextBox.Text += $"\r\n#Task assigned for group {grp}. Download tasks are active.\r\n";
  
    // ***This task is complete when a group has finished downloading and displaying.  
    await pendingWork;  
  
    // You can do other work here or just return.  
    return grp;  
}  
```

##### FinishOneGroupAsync 方法

此方法会循环访问组中的下载任务（等待每个任务、显示下载网站的长度并将该长度添加到总和中）。

`FinishOneGroupAsync` 中的第一个语句使用 `pendingWork` 确保进入方法不会干扰已在显示进程中或已在等待的操作。 如果这类操作正在进行，则进入操作必须等待轮到它。

```csharp
private async Task FinishOneGroupAsync(List<string> urls, Task<byte[]>[] contentTasks, char grp)  
{  
    // ***Wait for the previous group to finish displaying results.  
    if (pendingWork != null) await pendingWork;  
  
    int total = 0;  
  
    // contentTasks is the array of Tasks that was created in AccessTheWebAsync.  
    for (int i = 0; i < contentTasks.Length; i++)  
    {  
        // Await the download of a particular URL, and then display the URL and  
        // its length.  
        byte[] content = await contentTasks[i];  
        DisplayResults(urls[i], content, i, grp);  
        total += content.Length;  
    }  
  
    // Display the total count for all of the websites.  
    ResultsTextBox.Text +=  
        $"\r\n\r\nTOTAL bytes returned:  {total}\r\n";
}  
```

##### 兴趣点

输出中以井号 (#) 开头的信息行阐明了此示例的工作原理。

输出演示以下模式。

- 一个组可以上一组显示其输出期间启动，但上一组的输出显示不会中断。

  ```
  #Starting group A.  
  #Task assigned for group A. Download tasks are active.  
  
  A-1. msdn.microsoft.com/library/hh191443.aspx                87389  
  A-2. msdn.microsoft.com/library/aa578028.aspx               207089  
  A-3. msdn.microsoft.com/library/jj155761.aspx                30870  
  A-4. msdn.microsoft.com/library/hh290140.aspx               119037  
  A-5. msdn.microsoft.com/library/hh524395.aspx                71260  
  
  #Starting group B.  
  #Task assigned for group B. Download tasks are active.  
  
  A-6. msdn.microsoft.com/library/ms404677.aspx               199186  
  A-7. msdn.microsoft.com                                            53078  
  A-8. msdn.microsoft.com/library/ff730837.aspx               148010  
  
  TOTAL bytes returned:  915919  
  
  B-1. msdn.microsoft.com/library/hh191443.aspx                87388  
  B-2. msdn.microsoft.com/library/aa578028.aspx               207089  
  B-3. msdn.microsoft.com/library/jj155761.aspx                30870  
  
  #Group A is complete.  
  
  B-4. msdn.microsoft.com/library/hh290140.aspx               119027  
  B-5. msdn.microsoft.com/library/hh524395.aspx                71260  
  B-6. msdn.microsoft.com/library/ms404677.aspx               199186  
  B-7. msdn.microsoft.com                                            53078  
  B-8. msdn.microsoft.com/library/ff730837.aspx               148010  
  
  TOTAL bytes returned:  915908  
  ```

- 仅对于组 A（它首先启动），`pendingWork` 任务才在 `FinishOneGroupAsync` 启动时为 null。 组 A 在它到达 `FinishOneGroupAsync` 时尚未尚未完成 await 表达式。 因此，控制权未返回给 `AccessTheWebAsync`，对 `pendingWork` 的第一个分配尚未发生。

- 下面两行始终在输出中一起显示。 该代码从不会在于 `StartButton_Click` 中启动组操作与将组的任务分配给 `pendingWork` 之间中断。

  复制

  ```
  #Starting group B.  
  #Task assigned for group B. Download tasks are active.  
  ```

  组进入 `StartButton_Click` 之后，操作在操作进入 `FinishOneGroupAsync` 之前不会完成 await 表达式。 因此，没有其他操作可以在代码段期间获得控制权。

#### 检查并运行示例应用

若要更好地了解示例应用，可以下载它，自己生成或查看本主题末尾的代码，而无需实现应用。

> 若要将示例作为 Windows Presentation Foundation (WPF) 桌面应用运行，计算机上必须安装有 Visual Studio 2012 或更高版本和 .NET Framework 4.5 或更高版本。

##### 下载应用

1. 从[异步示例：.NET 桌面应用中的重新进入](https://code.msdn.microsoft.com/Async-Sample-Preventing-a8489f06)下载压缩文件。
2. 解压缩下载的文件，然后启动 Visual Studio。
3. 在菜单栏上，依次选择 **“文件”**、 **“打开”** 和 **“项目/解决方案”**。
4. 导航到保存解压缩的示例代码的文件夹，然后打开解决方案 (.sln) 文件。
5. 在“解决方案资源管理器”中，打开要运行的项目的快捷菜单，然后选择“设置为 StartUpProject”。
6. 选择 CTRL+F5 键以生成并运行项目。

##### 生成应用

以下部分提供用于将示例生成为 WPF 应用的代码。

###### 生成 WPF 应用程序

1. 启动 Visual Studio。

2. 在菜单栏上，依次选择“文件” 、“新建” 、“项目” 。

   **“新建项目”** 对话框随即打开。

3. 在“已安装的模板”窗格中，展开“Visual C#”，然后展开“Windows”。

4. 在项目类型列表中，选择“WPF 应用程序”。

5. 将项目命名为 `WebsiteDownloadWPF`，然后选择“确定”按钮。

   新项目将出现在“解决方案资源管理器”中。

6. 在 Visual Studio 代码编辑器中，选择 **“MainWindow.xaml”** 选项卡。

   如果此选项卡不可见，则在“解决方案资源管理器”中，打开 MainWindow.xaml 的快捷菜单，然后选择“查看代码”。

7. 在 MainWindow.xaml 的“XAML”视图中，将代码替换为以下代码。

   ```csharp
   <Window x:Class="WebsiteDownloadWPF.MainWindow"  
       xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"  
       xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"  
       xmlns:local="using:WebsiteDownloadWPF"  
       xmlns:d="http://schemas.microsoft.com/expression/blend/2008"  
       xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"  
       mc:Ignorable="d">  
   
       <Grid Width="517" Height="360">  
           <Button x:Name="StartButton" Content="Start" HorizontalAlignment="Left" Margin="-1,0,0,0" VerticalAlignment="Top" Click="StartButton_Click" Height="53" Background="#FFA89B9B" FontSize="36" Width="518"  />  
           <TextBox x:Name="ResultsTextBox" HorizontalAlignment="Left" Margin="-1,53,0,-36" TextWrapping="Wrap" VerticalAlignment="Top" Height="343" FontSize="10" ScrollViewer.VerticalScrollBarVisibility="Visible" Width="518" FontFamily="Lucida Console" />  
       </Grid>  
   </Window>  
   ```

   MainWindow.xaml 的“设计”视图中将显示一个简单的窗口，其中包含一个文本框和一个按钮。

8. 对 [System.Net.Http](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.http) 添加引用。

9. 在“解决方案资源管理器”中，打开 MainWindow.xaml.cs 的快捷菜单，然后选择“查看代码”。

10. 在 MainWindow.xaml.cs 中，将代码替换为以下代码。

    ```csharp
    using System;  
    using System.Collections.Generic;  
    using System.Linq;  
    using System.Text;  
    using System.Threading.Tasks;  
    using System.Windows;  
    using System.Windows.Controls;  
    using System.Windows.Data;  
    using System.Windows.Documents;  
    using System.Windows.Input;  
    using System.Windows.Media;  
    using System.Windows.Media.Imaging;  
    using System.Windows.Navigation;  
    using System.Windows.Shapes;  
    
    // Add the following using directives, and add a reference for System.Net.Http.  
    using System.Net.Http;  
    using System.Threading;  
    
    namespace WebsiteDownloadWPF  
    {  
        public partial class MainWindow : Window  
        {  
            public MainWindow()  
            {  
                InitializeComponent();  
            }  
    
            private async void StartButton_Click(object sender, RoutedEventArgs e)  
            {  
                // This line is commented out to make the results clearer in the output.  
                //ResultsTextBox.Text = "";  
    
                try  
                {  
                    await AccessTheWebAsync();  
                }  
                catch (Exception)  
                {  
                    ResultsTextBox.Text += "\r\nDownloads failed.";  
                }  
            }  
    
            private async Task AccessTheWebAsync()  
            {  
                // Declare an HttpClient object.  
                HttpClient client = new HttpClient();  
    
                // Make a list of web addresses.  
                List<string> urlList = SetUpURLList();  
    
                var total = 0;  
                var position = 0;  
    
                foreach (var url in urlList)  
                {  
                    // GetByteArrayAsync returns a task. At completion, the task  
                    // produces a byte array.  
                    byte[] urlContents = await client.GetByteArrayAsync(url);  
    
                    DisplayResults(url, urlContents, ++position);  
    
                    // Update the total.  
                    total += urlContents.Length;  
                }  
    
                // Display the total count for all of the websites.  
                ResultsTextBox.Text +=  
                    $"\r\n\r\nTOTAL bytes returned:  {total}\r\n";
            }  
    
            private List<string> SetUpURLList()  
            {  
                List<string> urls = new List<string>   
                {   
                    "https://msdn.microsoft.com/library/hh191443.aspx",  
                    "https://msdn.microsoft.com/library/aa578028.aspx",  
                    "https://msdn.microsoft.com/library/jj155761.aspx",  
                    "https://msdn.microsoft.com/library/hh290140.aspx",  
                    "https://msdn.microsoft.com/library/hh524395.aspx",  
                    "https://msdn.microsoft.com/library/ms404677.aspx",  
                    "https://msdn.microsoft.com",  
                    "https://msdn.microsoft.com/library/ff730837.aspx"  
                };  
                return urls;  
            }  
    
            private void DisplayResults(string url, byte[] content, int pos)  
            {  
                // Display the length of each website. The string format is designed  
                // to be used with a monospaced font, such as Lucida Console or   
                // Global Monospace.  
    
                // Strip off the "https://".  
                var displayURL = url.Replace("https://", "");  
                // Display position in the URL list, the URL, and the number of bytes.  
                ResultsTextBox.Text += $"\n{pos}. {displayURL,-58} {content.Length,8}";
            }  
        }  
    }  
    ```

11. 选择 CTRL+F5 键以运行程序，然后多次选择“开始”按钮。

12. 从[禁用“开始”按钮](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/handling-reentrancy-in-async-apps#BKMK_DisableTheStartButton)、[取消并重启操作](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/handling-reentrancy-in-async-apps#BKMK_CancelAndRestart)或[运行多个操作并将输出排入队列](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/handling-reentrancy-in-async-apps#BKMK_RunMultipleOperations)中进行更改以处理重新进入。

### [Using Async for File Access](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/async/using-async-for-file-access)

可使用异步功能访问文件。 通过使用异步功能，你可以调用异步方法而无需使用回调，也不需要跨多个方法或 lambda 表达式来拆分代码。 若要使同步代码异步，只需调用异步方法而非同步方法，并向代码中添加几个关键字。

可能出于以下原因向文件访问调用中添加异步：

- 异步使 UI 应用程序响应速度更快，因为启动该操作的 UI 线程可以执行其他操作。 如果 UI 线程必须执行耗时较长的代码（例如超过 50 毫秒），UI 可能会冻结，直到 I/O 完成，此时 UI 线程可以再次处理键盘和鼠标输入及其他事件。
- 异步可减少对线程的需要，进而提高 ASP.NET 和其他基于服务器的应用程序的可伸缩性。 如果应用程序对每次响应都使用专用线程，同时处理 1000 个请求时，则需要 1000 个线程。 异步操作在等待期间通常不需要使用线程。 异步操作仅需在结束时短暂使用现有 I/O 完成线程。
- 当前条件下，文件访问操作的延迟可能非常低，但以后可能大幅增加。 例如，文件可能会移动到覆盖全球的服务器。
- 使用异步功能所增加的开销很小。
- 异步任务可以轻松地并行运行。

#### 运行示例

若要运行本主题中的示例，可创建“WPF 应用程序”或“Windows 窗体应用程序”，然后添加一个“按钮”。 在按钮的 `Click` 事件中，添加对每个示例的第一个方法的调用。

在下面的示例中，包括以下 `using` 语句。

```csharp
using System;  
using System.Collections.Generic;  
using System.Diagnostics;  
using System.IO;  
using System.Text;  
using System.Threading.Tasks;  
```

#### 使用 FileStream 类

本主题中的示例使用 [FileStream](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.filestream) 类，该类包含可导致在操作系统级别出现异步 I/O 的选项。 使用此选项可避免在许多情况下阻止 ThreadPool 线程。 若要启用此选项，可在构造函数调用中指定 `useAsync=true` 或 `options=FileOptions.Asynchronous` 参数。

如果通过指定文件路径直接打开 [StreamReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.streamreader) 和 [StreamWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.streamwriter)，则无法将此选项与这二者配合使用。 但是，如果为二者提供已由 [FileStream](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.filestream) 类打开的 [Stream](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.stream)，则可以使用此选项。 请注意，即使 ThreadPool 线程受到阻止，UI 应用中的异步调用仍然更快，因为 UI 线程在等待期间不会受到阻止。

#### 编写文本

下面的示例将文本写入文件。 在每个 await 语句中，该方法会立即退出。 文件 I/O 完成后，该方法将在 await 语句后面的语句中继续。 请注意，async 修饰符在使用 await 语句的方法的定义中。

```csharp
public async void ProcessWrite()  
{  
    string filePath = @"temp2.txt";  
    string text = "Hello World\r\n";  
  
    await WriteTextAsync(filePath, text);  
}  
  
private async Task WriteTextAsync(string filePath, string text)  
{  
    byte[] encodedText = Encoding.Unicode.GetBytes(text);  
  
    using (FileStream sourceStream = new FileStream(filePath,  
        FileMode.Append, FileAccess.Write, FileShare.None,  
        bufferSize: 4096, useAsync: true))  
    {  
        await sourceStream.WriteAsync(encodedText, 0, encodedText.Length);  
    };  
}  
```

原始示例包含 `await sourceStream.WriteAsync(encodedText, 0, encodedText.Length);` 语句，它是下面两个语句的缩写式：

```csharp
Task theTask = sourceStream.WriteAsync(encodedText, 0, encodedText.Length);  
await theTask;  
```

第一条语句返回任务，并会导致文件处理启动。 具有 await 的第二条语句将使方法立即退出并返回一个不同的任务。 文件处理稍后完成后，执行将返回到 await 后面的语句中。 有关详细信息，请参阅[异步程序中的控制流 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/control-flow-in-async-programs)。

#### 读取文本

下面的示例读取文件中的文本。 将会缓冲文本，并且在此情况下，会将其放入 [StringBuilder](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.stringbuilder)。 与前一示例不同，await 的计算将生成一个值。 [ReadAsync](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.stream.readasync) 方法返回 [Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task)<[Int32](https://docs.microsoft.com/zh-cn/dotnet/api/system.int32)>，因此在操作完成后 await 的评估会得出 `Int32`值 (`numRead`)。 有关详细信息，请参阅[异步返回类型 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/async-return-types)。

```csharp
public async void ProcessRead()  
{  
    string filePath = @"temp2.txt";  
  
    if (File.Exists(filePath) == false)  
    {  
        Debug.WriteLine("file not found: " + filePath);  
    }  
    else  
    {  
        try  
        {  
            string text = await ReadTextAsync(filePath);  
            Debug.WriteLine(text);  
        }  
        catch (Exception ex)  
        {  
            Debug.WriteLine(ex.Message);  
        }  
    }  
}  
  
private async Task<string> ReadTextAsync(string filePath)  
{  
    using (FileStream sourceStream = new FileStream(filePath,  
        FileMode.Open, FileAccess.Read, FileShare.Read,  
        bufferSize: 4096, useAsync: true))  
    {  
        StringBuilder sb = new StringBuilder();  
  
        byte[] buffer = new byte[0x1000];  
        int numRead;  
        while ((numRead = await sourceStream.ReadAsync(buffer, 0, buffer.Length)) != 0)  
        {  
            string text = Encoding.Unicode.GetString(buffer, 0, numRead);  
            sb.Append(text);  
        }  
  
        return sb.ToString();  
    }  
}  
```

#### 并行异步 I/O

下面的示例通过编写 10 个文本文件来演示并行处理。 对于每个文件，[WriteAsync](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.stream.writeasync) 方法将返回一个任务，此任务随后将添加到任务列表中。 `await Task.WhenAll(tasks);` 语句将退出该方法，并在所有任务的文件处理完成时在此方法中继续。

该示例将在任务完成后关闭 `finally` 块中的所有 [FileStream](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.filestream) 实例。 如果每个 `FileStream` 均已在 `using` 语句中创建，则可能在任务完成前释放 `FileStream`。

请注意，性能提升几乎完全来自并行处理而不是异步处理。 异步的优点在于它不会占用多个线程，也不会占用用户界面线程。

```csharp
public async void ProcessWriteMult()  
{  
    string folder = @"tempfolder\";  
    List<Task> tasks = new List<Task>();  
    List<FileStream> sourceStreams = new List<FileStream>();  
  
    try  
    {  
        for (int index = 1; index <= 10; index++)  
        {  
            string text = "In file " + index.ToString() + "\r\n";  
  
            string fileName = "thefile" + index.ToString("00") + ".txt";  
            string filePath = folder + fileName;  
  
            byte[] encodedText = Encoding.Unicode.GetBytes(text);  
  
            FileStream sourceStream = new FileStream(filePath,  
                FileMode.Append, FileAccess.Write, FileShare.None,  
                bufferSize: 4096, useAsync: true);  
  
            Task theTask = sourceStream.WriteAsync(encodedText, 0, encodedText.Length);  
            sourceStreams.Add(sourceStream);  
  
            tasks.Add(theTask);  
        }  
  
        await Task.WhenAll(tasks);  
    }  
  
    finally  
    {  
        foreach (FileStream sourceStream in sourceStreams)  
        {  
            sourceStream.Close();  
        }  
    }  
}  
```

当使用 [WriteAsync](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.stream.writeasync) 和 [ReadAsync](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.stream.readasync) 方法时，可以指定可用于取消操作中间流的 [CancellationToken](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.cancellationtoken)。 有关详细信息，请参阅[微调异步应用程序 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/fine-tuning-your-async-application) 和 [Cancellation in Managed Threads](https://docs.microsoft.com/zh-cn/dotnet/standard/threading/cancellation-in-managed-threads)（托管线程中的取消）。