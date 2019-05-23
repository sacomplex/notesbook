# [Programming Concepts](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/)

## [Serialization (C#)](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/serialization/)

序列化是指将对象转换成字节流，从而存储对象或将对象传输到内存、数据库或文件的过程。 它的主要用途是保存对象的状态，以便能够在需要时重新创建对象。 反向过程称为“反序列化”。

### 序列化的工作原理

下图展示了序列化的整个过程。

![序列化图](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/serialization/media/serialization.gif)

对象被序列化成流，其中不仅包含数据，还包含对象类型的相关信息，如版本、区域性和程序集名称。 可以将此流中的内容存储在数据库、文件或内存中。

#### 序列化的用途

借助序列化，开发者可以保存对象的状态，并能在需要时重新创建对象，同时还能存储对象和交换数据。 通过序列化，开发者可以执行如下操作：通过 Web 服务将对象发送到远程应用程序、在域之间传递对象、以 XML 字符串的形式传递对象通过防火墙、跨应用程序维护安全性或用户专属信息。

#### 让对象可序列化

若要序列化对象，需要具有要序列化的对象、包含已序列化对象的一个流，以及一个 [Formatter](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.serialization.formatter)。[System.Runtime.Serialization](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.serialization) 包含序列化和反序列化对象所必需的类。

将 [SerializableAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.serializableattribute) 特性应用于某个类型，以指示此类型的实例可以被序列化。 如果尝试对没有[SerializableAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.serializableattribute) 特性的类型进行序列化，则会引发异常。

如果想让类中的某个字段不可序列化，请应用 [NonSerializedAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.nonserializedattribute) 特性。 如果可序列化的类型中的一个字段包含指针、句柄或特定环境专用的其他一些数据结构，且不能在其他环境中有意义地重构，不妨让其不可序列化。

如果已序列化的类引用被标记为 [SerializableAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.serializableattribute) 的其他类的对象，那么这些对象也会被序列化。

### 二进制和 XML 序列化

可以使用二进制或 XML 序列化。 在二进制序列化中，所有成员（包括只读成员）都会被序列化，且性能也会有所提升。 XML 序列化可提高代码可读性，以及对象共享和使用的灵活性，从而实现互操作性。

#### 二进制序列化

二进制序列化使用二进制编码来生成精简的序列化以供使用，如基于存储或套接字的网络流。

#### XML 序列化

XML 序列化将对象的公共字段和属性或方法的参数和返回值序列化成符合特定 XML 架构定义语言 (XSD) 文档要求的 XML 流。 XML 序列化生成已转换成 XML 的强类型类，其中包含公共属性和字段。 [System.Xml.Serialization](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.serialization) 包含序列化和反序列化 XML 所必需的类。

将特性应用于类和类成员，从而控制 [XmlSerializer](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.serialization.xmlserializer) 如何序列化或反序列化类的实例。

### 基本和自定义序列化

序列化有两种执行方式：基本和自定义序列化。 基本序列化使用 .NET Framework 自动序列化对象。

#### 基本序列化

基本序列化的唯一要求是对象必须已应用 [SerializableAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.serializableattribute) 特性。 [NonSerializedAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.nonserializedattribute) 可用于防止特定字段被序列化。

使用基本序列化时，对象的版本控制可能会产生问题。 对于重要的版本控制问题，可以使用自定义序列化。 基本序列化是最简单的序列化执行方式，但无法提供太多的进程控制。

#### 自定义序列化

在自定义序列化中，可以精确指定要序列化的对象以及具体执行方式。 类必须被标记为 [SerializableAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.serializableattribute)，并实现 [ISerializable](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.serialization.iserializable) 接口。

如果还想按自定义方式反序列化对象，必须使用自定义构造函数。

### 设计器序列化

设计器序列化是一种特殊形式的序列化，涉及与开发工具相关联的对象暂留。 设计器序列化是指将对象图转换成源文件以供日后用于恢复对象图的过程。 源文件可以包含代码、标记或 SQL 表信息。

### 相关主题和示例

[演练：在 Visual Studio 中暂留对象 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/serialization/walkthrough-persisting-an-object-in-visual-studio)
展示了如何使用序列化在实例之间暂留对象数据，以便可以存储值并在下次实例化对象时检索值。

[如何：读取 XML 文件中的对象数据 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/serialization/how-to-read-object-data-from-an-xml-file)
介绍如何使用 [XmlSerializer](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.serialization.xmlserializer) 类读取之前写入 XML 文件的对象数据。

[如何：将对象数据写入 XML 文件 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/serialization/how-to-write-object-data-to-an-xml-file)
介绍如何使用 [XmlSerializer](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.serialization.xmlserializer) 类从某个类将对象写入 XML 文件。

### [How to: Write Object Data to an XML File](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/serialization/how-to-write-object-data-to-an-xml-file)

本示例使用 [XmlSerializer](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.serialization.xmlserializer) 类从某个类将对象写入 XML 文件。

#### 示例

```csharp
public class XMLWrite  
{  
  
   static void Main(string[] args)  
    {  
        WriteXML();  
    }  
  
    public class Book  
    {  
        public String title;   
    }  
  
    public static void WriteXML()  
    {  
        Book overview = new Book();  
        overview.title = "Serialization Overview";  
        System.Xml.Serialization.XmlSerializer writer =   
            new System.Xml.Serialization.XmlSerializer(typeof(Book));  
  
        var path = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments) + "//SerializationOverview.xml";  
        System.IO.FileStream file = System.IO.File.Create(path);  
  
        writer.Serialize(file, overview);  
        file.Close();  
    }  
}  
```

#### 编译代码

类必须有一个公共的无参数构造函数。

#### 可靠编程

以下情况可能会导致异常：

- 进行序列化的类没有公共的无参数构造函数。
- 文件存在且为只读 ([IOException](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.ioexception))。
- 路径过长 ([PathTooLongException](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.pathtoolongexception))。
- 磁盘已满 ([IOException](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.ioexception))。

#### .NET Framework 安全性

此示例在文件尚未存在时创建新文件。 如果某个应用程序需要创建文件，则该应用程序需要针对文件夹的 `Create` 访问权限。 如果文件已存在，则该应用程序只需要 `Write` 访问权限（这是较弱的特权）。 如有可能，在部署过程中创建文件，并且仅授予针对单个文件的 `Read` 访问权限（而不是针对 `Create` 文件夹的访问权限）会更加安全。

### [How to: Read Object Data from an XML File](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/serialization/how-to-read-object-data-from-an-xml-file)

本示例使用 [XmlSerializer](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.serialization.xmlserializer) 类读取之前写入 XML 文件的对象数据。

#### 示例

```csharp
public class Book  
{  
    public String title;  
}         
  
public void ReadXML()  
{  
    // First write something so that there is something to read ...  
    var b = new Book { title = "Serialization Overview" };  
    var writer = new System.Xml.Serialization.XmlSerializer(typeof(Book));  
    var wfile = new System.IO.StreamWriter(@"c:\temp\SerializationOverview.xml");  
    writer.Serialize(wfile, b);  
    wfile.Close();  
  
    // Now we can read the serialized book ...  
    System.Xml.Serialization.XmlSerializer reader =   
        new System.Xml.Serialization.XmlSerializer(typeof(Book));  
    System.IO.StreamReader file = new System.IO.StreamReader(  
        @"c:\temp\SerializationOverview.xml");  
    Book overview =  (Book)reader.Deserialize(file);  
    file.Close();  
  
    Console.WriteLine(overview.title);  
  
}  
```

#### 编译代码

将文件名称“c:\temp\SerializationOverview.xml”替换为包含序列化数据的文件的名称。 有关如何序列化数据的详细信息，请参阅[如何：将对象数据写入 XML 文件 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/serialization/how-to-write-object-data-to-an-xml-file)。

类必须有一个公共的无参数构造函数。

只有公共属性和字段才会进行反序列化。

#### 可靠编程

以下情况可能会导致异常：

- 进行序列化的类没有公共的无参数构造函数。
- 文件中的数据不表示要进行反序列化的类中的数据。
- 该文件不存在 ([IOException](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.ioexception))。

#### .NET Framework 安全性

始终验证输入，并且绝不会反序列化来自不受信任源的数据。 重新创建的对象会在具有对它进行反序列化的代码的权限的本地计算机上运行。 在应用程序中使用输入的数据之前，需验证所有的输入内容。

### [Walkthrough: Persisting an Object in Visual Studio](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/serialization/walkthrough-persisting-an-object-in-visual-studio)

可使用序列化在实例之间保持对象的数据，以便可存储值并在下次实例化对象时检索这些值。

本演练将创建一个基础的 `Loan` 对象，并将其值保留在文件中。 当重新创建该对象时，将检索文件中的数据。

> 如果此文件尚不存在，本示例将新建文件。 如果应用程序必须创建文件，则该应用程序必须对文件夹具有 `Create` 权限。 可使用访问控制列表设置权限。 如果文件已存在，则该应用程序只需要 `Write` 权限（这是较弱的权限）。 如有可能，较安全的做法是在部署过程中创建文件并仅向单个文件授予 `Read` 权限（而不是授予文件夹的“创建”权限）。 此外，较安全的做法是将数据写入用户文件夹，而不是根文件夹或 Program Files 文件夹。

> 此示例将数据存储为二进制格式的文件。 不应将这些格式用于敏感数据，如密码或信用卡信息。

#### 系统必备

- 若要生成并运行，请安装 [.NET Core SDK](https://www.microsoft.com/net/core)。
- 安装常用的代码编辑器（如果尚未安装）。

> 需要安装代码编辑器？ 试用 [Visual Studio](https://visualstudio.com/downloads)！

- 该示例需要 C# 7.3。 请参阅[选择 C# 语言版本](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/configure-language-version)

可在 [.NET 示例 GitHub 存储库](https://github.com/dotnet/samples/tree/master/csharp/serialization)在线检查示例代码。

#### 创建 Loan 对象

第一步是创建 `Loan` 类和使用该类的控制台应用程序：

1. 创建一个新的应用程序。 键入 `dotnet new console -o serialization`，在名为 `serialization` 的子目录下创建新的控制台应用程序。
2. 在编辑器中打开应用程序，然后添加名为 `Loan.cs` 的新类。
3. 将以下代码添加到 `Loan` 类：

```csharp
public class Loan : INotifyPropertyChanged
 {
     public double LoanAmount { get; set; }
     public double InterestRate { get; set; }

     [field:NonSerialized()]
     public DateTime TimeLastLoaded { get; set; }

     public int Term { get; set; }

     private string customer;
     public string Customer
     {
         get { return customer; }
         set
         {
             customer = value;
             PropertyChanged?.Invoke(this,
               new PropertyChangedEventArgs(nameof(Customer)));
         }
     }

     [field: NonSerialized()]
     public event System.ComponentModel.PropertyChangedEventHandler PropertyChanged;

     public Loan(double loanAmount,
                 double interestRate,
                 int term,
                 string customer)
     {
         this.LoanAmount = loanAmount;
         this.InterestRate = interestRate;
         this.Term = term;
         this.customer = customer;
     }

 }
```

还需要创建一个使用 `Loan` 类的应用程序。

#### 串行化 Loan 对象

1. 打开 `Program.cs`。 添加以下代码：

```csharp
Loan TestLoan = new Loan(10000.0, 0.075, 36, "Neil Black");
```

添加 `PropertyChanged` 事件的事件处理程序和几行以修改 `Loan` 对象并显示此更改。 你可以在下列代码中查看添加项：

```csharp
TestLoan.PropertyChanged += (_, __) => Console.WriteLine($"New customer value: {TestLoan.Customer}");

TestLoan.Customer = "Henry Clay";
Console.WriteLine(TestLoan.InterestRate);
TestLoan.InterestRate = 7.1;
Console.WriteLine(TestLoan.InterestRate);
```

现在，可运行该代码，并查看当前输出：

```console
New customer value: Henry Clay
7.5
7.1
```

重复运行此应用程序始终编写相同值。 每次运行该程序都会创建新的 Loan 对象。 在现实生活中，利率会定期更改，但不必在每次运行应用程序时都更改利率。 序列化代码表示在应用程序的实例之间保存最新的利率。 下一步是通过向 Loan 类添加序列化来执行此操作。

#### 使用序列化保持对象

为了保持 Loan 类的值，必须首先使用 `Serializable` 属性标记该类。 将下面的代码添加到 Loan 类声明的上方：

```csharp
[Serializable()]
```

[SerializableAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.serializableattribute) 通知编译器可将类中的所有内容保留到文件中。 因为 `PropertyChanged` 事件不表示应该存储的对象图的部分，所以它不应序列化。 执行此操作可能将所有附加到该事件的对象序列化。 可将 [NonSerializedAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.nonserializedattribute) 添加到 `PropertyChanged` 事件处理程序的字段声明。

```csharp
[field: NonSerialized()]
public event System.ComponentModel.PropertyChangedEventHandler PropertyChanged;
```

从 C# 7.3 开始，可使用 `field` 目标值将特性附加到自动实现的属性的支持字段。 以下代码添加 `TimeLastLoaded`属性并将其标记为不可序列化：

```csharp
[field:NonSerialized()]
public DateTime TimeLastLoaded { get; set; }
```

下一步是向 LoanApp 应用程序添加序列化代码。 为了将该类序列化并将其写入到文件，可使用 [System.IO](https://docs.microsoft.com/zh-cn/dotnet/api/system.io) 和 [System.Runtime.Serialization.Formatters.Binary](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.serialization.formatters.binary) 命名空间。 为了避免键入完全限定的名称，可以添加对必要命名空间的引用，如以下代码所示：

```csharp
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
```

下一步是添加代码，在创建对象时对文件中的对象进行反序列化。 向序列化数据的文件名的类中添加一个常量，如以下代码所示：

```csharp
const string FileName = @"../../../SavedLoan.bin";
```

接下来，在创建 `TestLoan` 对象的行后添加以下代码：

```csharp
if (File.Exists(FileName))
{
    Console.WriteLine("Reading saved file");
    Stream openFileStream = File.OpenRead(FileName);
    BinaryFormatter deserializer = new BinaryFormatter();
    TestLoan = (Loan)deserializer.Deserialize(openFileStream);
    TestLoan.TimeLastLoaded = DateTime.Now;
    openFileStream.Close();
}
```

首先必须检查该文件是否存在。 如果存在，则创建 [Stream](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.stream) 类来读取二进制文件和 [BinaryFormatter](https://docs.microsoft.com/zh-cn/dotnet/api/system.runtime.serialization.formatters.binary.binaryformatter) 类，以转换该文件。 还需将流类型转换为 Loan 对象类型。

然后必须添加代码以将该类序列化到文件中。 以 `Main` 方式在现有代码后添加以下代码：

```csharp
Stream SaveFileStream = File.Create(FileName);
BinaryFormatter serializer = new BinaryFormatter();
serializer.Serialize(SaveFileStream, TestLoan);
SaveFileStream.Close();
```

此时可再次生成并运行应用程序。 首次运行时，请注意起始利率为 7.5，然后更改为 7.1. 关闭该应用程序，然后重新运行。 现在，应用程序打印已读取所保存文件的消息，即使在代码更改它之前，利率也是 7.1。

