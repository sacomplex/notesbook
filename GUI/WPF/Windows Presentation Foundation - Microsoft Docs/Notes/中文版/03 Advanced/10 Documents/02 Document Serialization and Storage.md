# [Document Serialization and Storage](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/document-serialization-and-storage)

Microsoft.NET Framework 提供了功能强大的环境，用于创建和显示高质量的文档。 增强的功能，支持固定文档和流文档以及高级查看控件，结合功能强大的二维和三维图形功能需要.NET Framework 应用程序到新的质量和用户体验级别。 能够灵活地管理文档的内存中表示形式是.NET Framework 中，一项主要功能并能够高效保存和加载数据存储区中的文档是几乎每个应用程序的需求。 将文档从内部的内存中表示形式转换为外部数据存储的过程称为序列化。 反之，读取数据存储并重新创建原始内存中实例的过程则称为反序列化。



## 关于文档序列化

理论上，对于应用程序来说，从内存中序列化文档和将文档反序列到原来的内存中都是透明的。 应用程序调用序列化程序“write”方法来保存文档，而反序列化程序“read”方法则访问数据存储并在内存中重新创建原始实例。 对于应用程序来说，只要序列化和反序列化进程将文档重新创建为其原始格式，数据存储的特定格式通常无关紧要。

应用程序通常提供多个序列化选项，用户可以使用这些选项将文档保存到不同的介质或保存为不同格式。 例如，应用程序可提供“另存为”选项将文档存储到磁盘文件、数据库或 Web 服务。 同样，不同的序列化程序可将文档存储为不同的格式，例如 HTML、RTF、XML、XPS 或第三方格式。 对于应用程序，序列化定义了一个接口，该接口可以隔离每个特定序列化程序的实现内部的存储介质的详细信息。 除了封装存储详细信息，.NET Framework 的优点[System.Windows.Documents.Serialization](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.serialization)API提供几个其他重要功能。

### .NET Framework 3.0 文档序列化程序的功能

- 通过直接访问高级别文档对象（逻辑树和视觉对象），可以有效存储已分页的内容、二维/三维元素、图像、媒体、超链接、注释以及其他支持内容。
- 同步和异步操作。
- 支持具有以下增强功能的插件序列化程序：
  - 所有.NET Framework 应用程序使用的系统级访问。
  - 简单应用程序插件的发现功能。
  - 第三方自定义插件的简单部署、安装和更新。
  - 对自定义运行时设置和选项的用户界面支持。

### XPS 打印路径

Microsoft.NET FrameworkXPS打印路径还提供了一个可扩展机制，用于编写通过打印输出的文档。 XPS 可以作为文档文件格式，也可以作为 Windows Vista 的本机后台打印格式。 XPS 文档可直接发送到与 XPS 兼容的打印机，而无需转换为中间格式。 有关打印路径输出选项和功能的其他信息，请参阅[打印概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/printing-overview)。



## 插件序列化程序

[System.Windows.Documents.Serialization](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.serialization) Api 为插件序列化程序和链接应用程序中单独安装的序列化程序提供支持，在运行时，将绑定并使用访问[SerializerProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.serialization.serializerprovider)发现机制。 插件序列化程序提供增强功能，可以简化部署和系统范围的使用。 你还可以针对无法在其中访问插件序列化程序的部分可信环境（例如 XAML 浏览器应用程序 (XBAP)）实现链接序列化程序。 链接序列化程序，它基于派生的实现[SerializerWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.serialization.serializerwriter)类，将编译并直接链接到该应用程序。 插件序列化程序和链接序列化程序都是通过相同的公共方法和事件来运行的，这样可以方便地在同一应用程序中使用其中一种或两种序列化程序。

插件序列化程序对应用程序开发人员很有帮助：它向新的存储设计和文件格式提供扩展性，而无需在生成时对每种潜在的格式进行直接编码。 插件序列化程序还通过为自定义或专有文件格式提供部署、安装和更新系统可访问插件的标准方法，使第三方开发人员受益匪浅。

### 使用插件序列化程序

插件序列化程序易于使用。 [SerializerProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.serialization.serializerprovider)类枚举[SerializerDescriptor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.serialization.serializerdescriptor)对象对每个插件已安装的系统上。[IsLoadable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.serialization.serializerdescriptor.isloadable)属性筛选基于当前的配置已安装的插件，并验证是否可以加载和应用程序使用序列化程序。[SerializerDescriptor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.serialization.serializerdescriptor)还提供其他属性，如[DisplayName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.serialization.serializerdescriptor.displayname)和[DefaultFileExtension](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.serialization.serializerdescriptor.defaultfileextension)，应用程序可以用来提示用户选择可用的输出格式的序列化程序。 默认插件序列化程序XPS随.NET Framework 一起提供，会始终进行枚举。 在用户选择输出格式后[CreateSerializerWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.serialization.serializerprovider.createserializerwriter)方法用于创建[SerializerWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.serialization.serializerwriter)为特定的格式。 [SerializerWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.serialization.serializerwriter).[Write](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.serialization.serializerwriter.write) 然后可以调用方法以将数据存储到的文档流输出。

下面的示例演示使用的应用程序[SerializerProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.serialization.serializerprovider)"PlugInFileFilter"属性中的方法。 PlugInFileFilter 枚举已安装的插件，并生成一个筛选器字符串，使用可用的文件的选项[SaveFileDialog](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.win32.savefiledialog)。

C#复制

```csharp
// ------------------------ PlugInFileFilter --------------------------
/// <summary>
///   Gets a filter string for installed plug-in serializers.</summary>
/// <remark>
///   PlugInFileFilter is used to set the SaveFileDialog or
///   OpenFileDialog "Filter" property when saving or opening files
///   using plug-in serializers.</remark>
private string PlugInFileFilter
{
    get
    {   // Create a SerializerProvider for accessing plug-in serializers.
        SerializerProvider serializerProvider = new SerializerProvider();
        string filter = "";

        // For each loadable serializer, add its display
        // name and extension to the filter string.
        foreach (SerializerDescriptor serializerDescriptor in
            serializerProvider.InstalledSerializers)
        {
            if (serializerDescriptor.IsLoadable)
            {
                // After the first, separate entries with a "|".
                if (filter.Length > 0)   filter += "|";

                // Add an entry with the plug-in name and extension.
                filter += serializerDescriptor.DisplayName + " (*" +
                    serializerDescriptor.DefaultFileExtension + ")|*" +
                    serializerDescriptor.DefaultFileExtension;
            }
        }

        // Return the filter string of installed plug-in serializers.
        return filter;
    }
}
```

用户已选择输出文件的名称后，下面的示例演示使用[CreateSerializerWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.serialization.serializerprovider.createserializerwriter)方法来存储给定的文档中指定的格式。

C#复制

```csharp
// Create a SerializerProvider for accessing plug-in serializers.
SerializerProvider serializerProvider = new SerializerProvider();

// Locate the serializer that matches the fileName extension.
SerializerDescriptor selectedPlugIn = null;
foreach ( SerializerDescriptor serializerDescriptor in
                serializerProvider.InstalledSerializers )
{
    if ( serializerDescriptor.IsLoadable &&
         fileName.EndsWith(serializerDescriptor.DefaultFileExtension) )
    {   // The plug-in serializer and fileName extensions match.
        selectedPlugIn = serializerDescriptor;
        break; // foreach
    }
}

// If a match for a plug-in serializer was found,
// use it to output and store the document.
if (selectedPlugIn != null)
{
    Stream package = File.Create(fileName);
    SerializerWriter serializerWriter =
        serializerProvider.CreateSerializerWriter(selectedPlugIn,
                                                  package);
    IDocumentPaginatorSource idoc =
        flowDocument as IDocumentPaginatorSource;
    serializerWriter.Write(idoc.DocumentPaginator, null);
    package.Close();
    return true;
}
```



### 安装插件序列化程序

[SerializerProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.serialization.serializerprovider)类提供的插件序列化程序发现和访问权限较高级别应用程序接口。 [SerializerProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.serialization.serializerprovider) 查找，并提供应用程序已安装并在系统上可访问的序列化程序的列表。 已安装序列化程序的具体信息通过注册表设置来定义。 插件序列化程序可以通过使用添加到注册表[RegisterSerializer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.serialization.serializerprovider.registerserializer)方法; 或如果不是.NET Framework 尚未安装，插件安装脚本可以直接设置注册表值本身。 [UnregisterSerializer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.serialization.serializerprovider.unregisterserializer)方法可用于删除以前安装插件，或注册表设置都可以通过卸载脚本同样重置。

### 创建插件序列化程序

插件序列化程序和链接序列化程序使用同一公开的公共方法和事件，并且可同样设计为以同步或异步方式运行。创建插件序列化程序通常应执行下列三个基本步骤：

1. 首先以链接序列化程序的形式实现和调试序列化程序。 开始时通过创建直接编译和链接到测试应用程序的序列化程序，可以提供对断点以及其他有助于测试的调试服务的完全访问权限。
2. 完全测试序列化程序之后，[ISerializerFactory](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.serialization.iserializerfactory)接口添加以创建插件。 [ISerializerFactory](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.serialization.iserializerfactory)接口允许对所有.NET Framework 对象的完全访问，其中包括逻辑树中，[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)对象， [IDocumentPaginatorSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.idocumentpaginatorsource)，和[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)元素。 此外[ISerializerFactory](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.serialization.iserializerfactory)提供相同的同步和异步方法和链接序列化程序使用的事件。 由于输出大型文档需要一定时间，因此推荐使用异步操作以维持响应用户交互，并在数据存储出现问题时提供“取消”选项。
3. 创建插件序列化程序之后，实现安装脚本以分发和安装（以及卸载）插件（请参阅上面的“[安装插件序列化程序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/document-serialization-and-storage#InstallingPluginSerializers)”）。