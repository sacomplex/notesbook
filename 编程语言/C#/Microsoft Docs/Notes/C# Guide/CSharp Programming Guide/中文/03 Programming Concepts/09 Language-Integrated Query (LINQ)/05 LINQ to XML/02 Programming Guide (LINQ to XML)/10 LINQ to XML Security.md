# [LINQ to XML Security](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/linqtoxmlsecurity)

本主题说明与 LINQ to XML 相关的安全问题。 此外，它还提供减轻安全隐患的一些指导。

## LINQ to XML 安全性概述

在旨在提高编程方便性和使服务器端应用程序具有严格安全要求两者之间，LINQ to XML 更倾向于前者。 多数 XML 方案均涉及处理受信任的 XML 文档，而不涉及处理上载到服务器的不受信任的 XML 文档。 LINQ to XML 针对这些方案进行了优化。

如果您必须处理来自未知源的不受信任的数据，Microsoft 建议您使用 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 类的一个实例，并将该实例配置为筛除已知 XML 拒绝服务 (DoS) 攻击。

如果您已配置 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 以缓解拒绝服务攻击，则可以使用该读取器填充 LINQ to XML 树，同时仍可受益于 LINQ to XML 所提供的高编程效率。 许多缓解技术均涉及创建配置为可缓解安全问题的读取器，然后通过配置的读取器实例化 XML 树。

由于文档不受大小、深度、元素名称大小等的限制，因此 XML 从本质上就容易受到拒绝服务攻击。 不管使用哪个组件处理 XML，都应该始终准备好在应用程序域使用过多资源的情况下回收应用程序域。

## 缓解 XML、XSD、XPath 和 XSLT 攻击

LINQ to XML 是基于 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 和 [XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwriter) 生成的。 LINQ to XML 通过 [System.Xml.Schema](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.schema) 和 [System.Xml.XPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xpath) 命名空间中的扩展方法支持 XSD 和 XPath。 在结合 LINQ to XML 使用 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader)、[XPathNavigator](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xpath.xpathnavigator) 和 [XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwriter) 类时，可以调用 XSLT 来转换 XML 树。

如果在不足够安全的环境中操作，则可能会遇到许多与 XML 及 [System.Xml](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml)、[System.Xml.Schema](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.schema)、[System.Xml.XPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xpath) 和 [System.Xml.Xsl](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xsl) 中的类的使用相关的安全问题。 这些问题包括但不限于以下问题：

- XSD、XPath 和 XSLT 是基于字符串的语言，您可以使用此语言指定消耗很多时间和内存的操作。 从不受信任的源获取 XSD、XPath 或 XSLT 字符串的应用程序程序员应当负责验证这些字符串以确保其中不包含恶意内容，或监视这些字符串并尽量避免计算这些字符串时消耗过多的系统资源。
- XSD 架构（包括内联架构）从本质上就容易受到拒绝服务攻击，因此不应接受来自不受信任的源的架构。
- XSD 和 XSLT 可能包括对其他文件的引用，这种引用可能导致跨区和跨域攻击。
- DTD 中的外部实体可能会导致跨区和跨域攻击。
- DTD 容易受到拒绝服务攻击。
- 异常深的 XML 文档可能引起拒绝服务问题；您可能需要限制 XML 文档的深度。
- 不接受不受信任的程序集中的支持组件，如 [NameTable](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.nametable)、[XmlNamespaceManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlnamespacemanager) 和 [XmlResolver](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlresolver) 对象。
- 分块区读取数据以缓解大文档攻击。
- XSLT 样式表中的脚本块易于受到多种攻击。
- 构造动态 XPath 表达式之前需仔细验证这些表达式。

## LINQ to XML 安全问题

本主题中介绍的安全问题不区分顺序。 所有问题都很重要，都应得到相应解决。

成功的特权提升攻击可使恶意程序集能够更好地控制其环境。 成功的特权提升攻击可能导致数据泄露、拒绝服务等。

应用程序不应该向未经授权查看数据的用户泄露数据。

拒绝服务攻击会导致 XML 分析器或 LINQ to XML 消耗过多的内存或 CPU 时间。 拒绝服务攻击的严重性可视为比特权提升攻击或数据泄露攻击的严重性低。 但在服务器需要处理来自不受信任的源的 XML 文档的方案中，拒绝服务攻击很重要。

### 异常和错误消息可能会泄露数据

错误说明中可能会显示数据，如正在转换的数据、文件名或实现详细信息。 不应向不受信任的调用方公开错误消息。 您应该捕捉所有错误并用自己的自定义错误消息报告错误。

### 不要在事件处理程序中调用 CodeAccessPermissions.Assert

程序集可具有较低或较高的权限。 程序集的权限越高，其对计算机及其环境的控制程度也就越高。

如果具有较高权限的程序集中的代码在事件处理程序中调用 [CodeAccessPermission.Assert](https://docs.microsoft.com/zh-cn/dotnet/api/system.security.codeaccesspermission.assert)，然后将 XML 树传递给具有受限制权限的恶意程序集，则恶意程序集可能引发事件。 由于该事件运行具有较高权限的程序集中的代码，因此恶意程序集将使用提升的特权运行。

Microsoft 建议您永远不要在事件处理程序中调用 [CodeAccessPermission.Assert](https://docs.microsoft.com/zh-cn/dotnet/api/system.security.codeaccesspermission.assert)。

### DTD 不安全

DTD 中的实体在本质上就不安全。 包含 DTD 的恶意 XML 文档可使分析器使用全部内存和 CPU 时间，从而导致拒绝服务攻击。 因此，在 LINQ to XML 中，默认情况下关闭 DTD 处理。 您不应接受来自不受信任源的 DTD。

接受来自不受信任源的 DTD 的一个示例是：允许 Web 用户上载引用 DTD 和 DTD 文件的 XML 文件的 Web 应用程序。 在验证该文件时，恶意 DTD 会在您的服务器上执行拒绝服务攻击。 接受来自不受信任源的 DTD 的另一个示例是：引用网络共享上也允许匿名 FTP 访问的 DTD。

### 避免分配过多的缓冲区

应用程序开发人员应该知道，过大的数据源可能导致资源耗尽和拒绝服务攻击。

如果恶意用户提交或上载非常大的 XML 文档，则可能导致 LINQ to XML 使用过多的系统资源。 这可能构成拒绝服务攻击。 为防止这种情况的发生，可以设置 [XmlReaderSettings.MaxCharactersInDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreadersettings.maxcharactersindocument) 属性并创建一个读取器，然后限制读取器可以加载的文档大小。 然后使用该读取器创建 XML 树。

例如，如果您知道来自不受信任源的 XML 文档的预计最大大小不会超过 50K 字节，则将 [XmlReaderSettings.MaxCharactersInDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreadersettings.maxcharactersindocument) 设置为 100,000。 这不会妨碍您处理 XML 文档，同时还可在要上载的文档会使用大量内存的情况下缓解拒绝服务威胁。

### 避免过度扩展实体

使用 DTD 时的一种已知拒绝服务攻击是导致过度扩展实体的文档造成的。 为防止这种情况的发生，可以设置 [XmlReaderSettings.MaxCharactersFromEntities](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreadersettings.maxcharactersfromentities) 属性并创建一个读取器，然后限制从实体扩展中生成的字符数。然后使用该读取器创建 XML 树。

### 限制 XML 层次结构的深度

在提交具有过深层次结构的文档时，会发生一种可能的拒绝服务攻击。 为了防止这种情况的发生，可以将 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 包装在您自己的可计算元素深度的类中。 如果深度超过预设的合理等级，您可以终止处理恶意文档。

### 防止不受信任的 XmlReader 或 XmlWriter 实现

管理员应验证任何外部提供的 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 或 [XmlWriter](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlwriter) 实现都要具有强名称且已经在计算机配置中注册。 这可防止加载伪装成读取器或编写器的恶意代码。

### 定期释放引用 XName 的对象

为防止某些类型的攻击，应用程序程序员应该定期释放引用应用程序域中的 [XName](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xname) 对象的所有对象。

### 防止随机 XML 名称

从不受信任的源中获取数据的应用程序应该考虑使用包装在自定义代码中的 [XmlReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlreader) 来检查是否可能会出现随机 XML 名称和命名空间。 如果检测到这样的随机 XML 名称和命名空间，则应用程序可以终止处理恶意文档。

您可能需要将任何给定命名空间中的名称数目（包括不在命名空间中的名称）限制为合理的极限。

### 通过共享 LINQ to XML 树的软件组件可以访问批注

LINQ to XML 可用于生成处理管道，其中的不同应用程序组件可分别加载、验证、查询、转换、更新和保存在组件之间作为 XML 树传递的 XML 数据。 这有助于优化性能，因为仅在管道末端消耗加载对象并将对象序列化为 XML 文本的系统资源。 但开发人员必须知道，由一个组件创建的所有批注和事件处理程序都可以由其他组件访问。 如果组件的信任级别不同，这可能会造成很多安全漏洞。 若要在低信任级别的组件之间生成安全管道，在将数据传递给不受信任的组件之前，您必须将 LINQ to XML 对象序列化为 XML 文本。

某些安全功能是由公共语言运行库 (CLR) 提供的。 例如，不包括私有类的组件无法访问由该类键控的批注。 但是，不能读取批注的组件却可以删除该批注。 这可能用作篡改攻击。