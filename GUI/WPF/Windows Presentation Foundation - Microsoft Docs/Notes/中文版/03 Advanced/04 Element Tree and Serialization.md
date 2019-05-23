# [Element Tree and Serialization](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/element-tree-and-serialization)

WPF 编程元素彼此之间通常以某种形式的树关系存在。 例如，XAML 中创建的应用程序 UI 可概念化为一个对象树。 可进一步将元素树分为两个离散但有时会并行的树：逻辑树和可视化树。 WPF 中的序列化涉及保存这两个树和应用程序的状态并将状态写入文件（可能以 XAML 形式）。

## 本节内容

[WPF 中的树](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/trees-in-wpf)
[XamlWriter.Save 的序列化限制](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/serialization-limitations-of-xamlwriter-save)
[不在对象树中的对象元素的初始化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/initialization-for-object-elements-not-in-an-object-tree)
[帮助主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/element-tree-and-serialization-how-to-topics)

## [Trees in WPF](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/trees-in-wpf)

在许多技术中，元素和组件都按树结构的形式组织。在这种结构中，开发人员可以直接操作树中的对象节点来影响应用程序的绘制或行为。 Windows Presentation Foundation (WPF) 也使用了若干树结构形式来定义程序元素之间的关系。 多数情况下，在概念层面考虑对象树形式时，WPF 开发人员会用代码创建应用程序，或用 XAML 定义应用程序的组成部分，但他们会调用具体的 API 或使用特定的标记来执行此操作，而不是像在 XML DOM 中那样，使用某些常规对象树操作 API。 WPF 公开提供树形式视图的两个帮助器类[LogicalTreeHelper](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.logicaltreehelper)和[VisualTreeHelper](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualtreehelper)。WPF 文档中还使用了“可视化树”和“逻辑树”两个术语，它们有助于理解某些关键 WPF 功能的行为。 本主题定义的可视化树和逻辑树的表示，讨论这些树与总体对象树概念，并引入了[LogicalTreeHelper](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.logicaltreehelper)和[VisualTreeHelper](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualtreehelper)s。

### WPF 中的树

WPF 中，最完整的树结构是对象树。 如果在 XAML 中定义一个应用程序页，然后加载 XAML，将根据标记中元素之间的嵌套关系来创建树结构。 如果使用代码定义应用程序或应用程序的一部分，则将根据为属性（属性实现给定对象的内容模型）分配属性值的方式来创建树结构。 在 Windows Presentation Foundation (WPF) 中，完整的对象树可通过两种方式进行概念化并报告给其公共 API：作为逻辑树和作为可视化树。 逻辑树与可视化树之间的区别不一定重要，但在某些 WPF 子系统中它们偶尔可能会导致问题，并影响你对标记或代码的选择。

尽管你并不会总是直接操作逻辑树或可视化树，但理解它们之间的关系有助于你从技术角度了解 WPF。 若要理解WPF 中属性继承和事件路由的工作原理，将 WPF 视为某种树形式也相当重要。

> 因为对象树更像是概念，而不像是实际 API，所以还可以将此概念视为对象图。 实际上，在运行时，对象之间的某些关系不能由树形式表示。 尽管如此，树形式的相关性还是很强，尤其是对于 XAML 定义的 UI。因此，大多数 WPF 文档在引用这个常见概念时，仍使用术语“对象树”。

### 逻辑树

在 WPF 中，通过为支持 UI 元素的对象设置属性，可以向这些 UI 元素添加内容。 例如，你将项添加到[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)通过操作控制其[Items](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.items)属性。 通过执行此操作，你将项放入[ItemCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemcollection)，它是[Items](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.items)属性值。 同样，可以将对象添加到[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)，则操作其[Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.children)属性值。 在这里，你会将对象添加到[UIElementCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.uielementcollection)。 有关代码示例，请参阅[动态添加元素](https://msdn.microsoft.com/library/d00f258a-7973-4de7-bc54-a3fc1f638419)。

中可扩展应用程序标记语言 (XAML)，当你将在列表项放入[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)控件或中的其他 UI 元素[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)，还使用[Items](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.items)和[Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.children)属性，显式或隐式，如以下示例所示。

XAML复制

```xaml
<DockPanel
  Name="ParentElement"
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  >
  <!--implicit: <DockPanel.Children>-->
  <ListBox DockPanel.Dock="Top">
    <!--implicit: <ListBox.Items>-->
    <ListBoxItem>
      <TextBlock>Dog</TextBlock>
    </ListBoxItem>
    <ListBoxItem>
      <TextBlock>Cat</TextBlock>
    </ListBoxItem>
    <ListBoxItem>
      <TextBlock>Fish</TextBlock>
    </ListBoxItem>
  <!--implicit: </ListBox.Items>-->
  </ListBox>
  <Button Height="20" Width="100" DockPanel.Dock="Top">Buy a Pet</Button>
  <!--implicit: </DockPanel.Children>-->
</DockPanel>
```

如果此 XAML 是作为文档对象模型下的 XML 进行处理，且已包含作为隐式项禁止注释的标记（可能是合法的），生成的 XML DOM 树已包含 `<ListBox.Items>` 的元素以及其他隐式项。 但是，读取标记和写入对象时，XAML 不会这样处理，生成的对象图不包含 `ListBox.Items`。 但是，它也有[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)名为属性`Items`，其中包含[ItemCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemcollection)，并且[ItemCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemcollection)已初始化，但为空时[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)处理 XAML。 然后，作为内容存在于每个子对象元素[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)添加到[ItemCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemcollection)的分析器调用`ItemCollection.Add`。 此示例将 XAML 处理成对象树，目前这似乎表明所创建的对象树基本上是逻辑树。

不过，即使不考虑 XAML 隐式语法项，该逻辑树也不是应用程序 UI 在运行时存在的整个对象图。这主要是因为视觉对象和模板。 例如，考虑[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。 逻辑树报告[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)对象以及其字符串`Content`。 但在运行时对象树中，此按钮还有更多内容。 具体而言，该按钮才会显示在屏幕上是因为它的方法特定[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)应用控件模板。 来自应用的模板的视觉对象 (例如模板定义[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)可视化按钮周围的深灰色的) 不会报告逻辑树中，即使您正在查看逻辑树在运行时 (例如处理来自的输入的事件可见的 UI，然后读取逻辑树）。 若要查找模板视觉对象，需要改为检查可视化树。

有关 XAML 语法如何映射到所创建的对象图，以及 XAML 中隐式语法的详细信息，请参阅 [XAML 语法详述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-syntax-in-detail)或 [XAML 概述 (WPF)](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-overview-wpf)。

#### 逻辑树用途

借助逻辑树，内容模型可以方便地循环访问其可能的子对象，从而实现扩展。 此外，逻辑树还为某些通知提供框架，例如在加载逻辑树中的所有对象时。 基本上，逻辑树是框架级别的近似运行时对象图（排除了视觉对象），但其足以用于对你自己的运行时应用程序组合执行多种查询操作。

此外，通过沿逻辑树向上查找来解析这两个静态和动态资源引用[Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.resources)上请求的初始对象，然后继续向上逻辑树并检查每个集合[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)（或[FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement))为另一个`Resources`值，该值包含[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)，可能包含该键。 当同时存在逻辑树和可视化树时，将使用逻辑树进行资源查找。 有关资源字典和查找的详细信息，请参见 [XAML 资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-resources)。

#### 逻辑树的构成

逻辑树在 WPF 框架级别，这意味着是逻辑树操作关系最为密切的 WPF 基元素是定义[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)或[FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement)。 但是，可以看出，是否实际使用[LogicalTreeHelper](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.logicaltreehelper)API，逻辑树有时会包含节点不是选择题[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)或[FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement)。 例如，逻辑树报告[Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.text)的值[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)，它是一个字符串。

#### 替代逻辑树

经验丰富的控件作者会通过替代若干 API（用于定义常规对象或内容模型如何在逻辑树中添加或删除对象）来替代逻辑树。 有关如何替代逻辑树的示例，请参阅[替代逻辑树](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-override-the-logical-tree)。

#### 属性值继承

属性值继承通过混合树操作。 包含的实际元数据[Inherits](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata.inherits)启用属性继承的属性是 WPF 框架级[FrameworkPropertyMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata)类。 因此，保留原始值的父和子对象继承该值都必须[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)或[FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement)，并且它们必须都是一些逻辑树的一部分。 但是，对于支持属性继承的现有 WPF 属性，属性值的继承可通过逻辑树中没有的中介对象永久存在。 这主要适用于以下情况：让模板元素使用在应用了模板的实例上设置的任何继承属性值，或者使用在更高级别的页级构成（因此在逻辑树中也位于更高位置）中设置的任何继承属性值。 为了使属性值的继承在这两种情况下保持一致，继承属性必须注册为附加属性。如果要定义具有属性继承行为的自定义依赖属性，则应采用这种模式。 无法通过帮助器类实用工具方法完全预测属性继承确切使用的树，即使在运行时也是如此。 有关详细信息，请参阅[属性值继承](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/property-value-inheritance)。

### 可视化树

WPF 中除了逻辑树的概念，还存在可视化树的概念。 可视化树描述的视觉对象的结构，由表示[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)基类。 为控件编写模板时，将定义或重新定义适用于该控件的可视化树。 对于出于性能和优化考虑需要对绘图进行较低级别控制的开发人员来说，他们也会对可视化树感兴趣。 在传统 WPF 应用程序编程中，可视化树的一个应用是：路由事件的事件路由大多遍历可视化树而非逻辑树。 路由事件行为的这种微妙之处可能不会很明显，除非你是控件作者。 通过可视化树对事件进行路由可使控件在可视化级别实现组合以处理事件或创建事件资源库。

### 树、内容元素和内容宿主

内容元素 (派生的类[ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement)) 不属于可视化树的一部分; 它们不是继承[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)和不具有可视表示形式。 若要显示在 UI 中，[ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement)必须承载在既是内容宿主[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)和逻辑树参与者。 此类对象通常是[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)。 从概念上讲，内容宿主有些类似于内容的“浏览器”，它选择在该宿主控制的屏幕区域中显示内容的方式。 承载内容时，可以使内容成为通常与可视化树关联的某些树进程的参与者。 通常情况下，[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)宿主类包括添加所有托管的实现代码[ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement)到通过内容逻辑树的子节点的事件路由，即使所承载的内容不属于实际可视化树。 这是必需的以便[ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement)可以获得将路由到非自身的任何元素的路由的事件。

### 树遍历

[LogicalTreeHelper](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.logicaltreehelper)类提供了[GetChildren](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.logicaltreehelper.getchildren)， [GetParent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.logicaltreehelper.getparent)，和[FindLogicalNode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.logicaltreehelper.findlogicalnode)逻辑树遍历的方法。 在大多数情况下，不需要遍历现有控件的逻辑树，因为这些控件几乎总是将其逻辑子元素公开为一个专用集合属性，这种属性支持集合访问，如 `Add`、索引器等等。 树遍历是一种主要方案由控件作者选择不从预期的控件模式派生，如[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)或[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)其中已定义集合属性，并且希望提供自己的集合属性的支持。

可视化树还支持用于可视化树遍历的帮助器类[VisualTreeHelper](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualtreehelper)。 不通过特定于控件的属性，方便地公开可视化树，因此[VisualTreeHelper](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualtreehelper)类是遍历可视化树，如果这是你的编程方案所需的建议的方法。 有关详细信息，请参阅 [WPF 图形呈现概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/wpf-graphics-rendering-overview)。

> 有时有必要检查所应用模板的可视化树。 执行此操作时应谨慎。 即使遍历可视化树的控件在其中定义该模板，您的控件的使用者始终可以通过设置更改模板[Template](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.template)属性情况下，甚至最终用户可以通过以下方式影响应用的模板更改系统主题。

### “树”形式路由事件的路由

如前所述，对于任何给定的路由事件，其路由都沿着一条预定的树路径进行，这棵树是可视化树和逻辑树表示形式的混合体。 事件路由可在树中向上或向下进行，具体取决于该事件是隧道路由事件还是浮升路由事件。 事件路由概念没有直接支持的帮助器类（此类可用于独立于引发实际路由的事件，遍历事件）。 没有一个类，表示路由， [EventRoute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventroute)，但该类的方法通常仅供内部使用。

### 资源字典和树

对页中定义的所有 `Resources` 进行资源字典查找时，基本上遍历逻辑树。 逻辑树之外的对象可以引用键控资源，但资源查找顺序将从该对象与逻辑树的连接点开始。 在 WPF 中，只有逻辑树节点可以具有`Resources`属性，其中包含[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)，因此没有任何益处在遍历可视化树中查找键控资源从[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)。

但是，资源查找也可以超出直接逻辑树。 对于应用程序标记，资源查找可向前继续进行到应用程序级资源字典，然后再到作为静态属性或键进行引用的主题支持和系统值。 如果资源引用是动态的，则主题本身也可以引用主题逻辑树之外的系统值。 有关资源字典和查找逻辑的详细信息，请参阅 [XAML 资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-resources)。

## [Serialization Limitations of XamlWriter.Save](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/serialization-limitations-of-xamlwriter-save)

API [Save](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.xamlwriter.save)可以用于序列化的内容Windows Presentation Foundation (WPF)作为应用程序可扩展应用程序标记语言 (XAML)文件。 但是，对于所序列化的内容有一些显著限制。 本主题对这些限制和某些一般注意事项进行了介绍。

### 运行时、非设计时表示形式

通过调用序列化的内容的基本原理[Save](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.xamlwriter.save)是结果将是正在序列化，在运行时对象的表示形式。 许多设计时属性的原始XAML文件可能已优化或丢失时，XAML加载为内存中对象，并在调用时不保留[Save](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.xamlwriter.save)要序列化。 序列化的结果是应用程序的结构化逻辑树的有效表示形式，但并不一定是生成该树的原始 XAML 的有效表示形式。 这些问题导致非常难以使用[Save](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.xamlwriter.save)一部分的一个全面的序列化XAML设计图面。

### 序列化是自包含的

序列化的输出[Save](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.xamlwriter.save)是自包含; 序列化的所有内容包含在XAML单个页，其中一个根元素，并且不包含外部引用以外的其他URI。 例如，如果页面从应用程序资源引用了资源，则这些资源看上去如同正在进行序列化的页面的一个组件。

### 取消引用扩展引用

由各种标记扩展格式（如 `StaticResource` 或 `Binding`）对对象进行的公共引用将会由序列化进程取消引用。 已由应用程序运行时，创建了内存中对象时将这些取消引用和[Save](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.xamlwriter.save)逻辑重新原始不访问XAML以还原对序列化输出此类引用。 这样可能会将任何数据绑定的或资源获得的值冻结为运行时表示形式最后使用的值，并且只能有限地或间接地区别这样的值与任何其他在本地设置的值。 由于图像存在于项目中，因此图像也会序列化为图像的对象引用（而不是原始的源引用），从而会丢失最初引用的文件名或 URI。 即使是在同一页面内声明的资源，也会序列化到引用点内，而不是保留为资源集合的键。

### 不保留事件处理

当对通过 XAML 添加的事件处理程序进行序列化后，不会保留这些事件处理程序。 不具有代码隐藏功能（并且也不具有相关的 x:Code 机制）的 XAML 无法对运行时过程逻辑进行序列化。 因为序列化是自包含的且限于逻辑树，所以不存在用于存储事件处理程序的设施。 因此，会从输出 XAML 中删除事件处理程序特性（特性本身和用于命名处理程序的字符串值）。

### XAMLWriter.Save 实用方案

虽然限制列出如下相当大，仍有几种使用的相应方案[Save](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.xamlwriter.save)序列化。

- 向量或图形输出：所呈现的区域的输出可用于在重新加载时重新生成相同的向量或图形。
- 格式文本和流文档：输出中会保留文本以及文本内的所有元素格式和元素所含内容。 这对类似于剪贴板功能的机制可能非常有用。
- 保留业务对象数据：如果已在自定义元素中存储数据（如 XML 数据），只要业务对象遵循基本 XAML 规则（如为按引用属性值提供自定义构造函数和转换），这些业务对象就可以通过序列化永久保留。

## [Initialization for Object Elements Not in an Object Tree](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/initialization-for-object-elements-not-in-an-object-tree)

Windows Presentation Foundation (WPF) 初始化时某些方面会被推迟，在通常依赖连接到逻辑树或可视化树的元素的进程中执行。 本主题介绍了针对未连接到两种树之一的元素，将其初始化可能需要的步骤。

### 元素和逻辑树

在代码中创建 Windows Presentation Foundation (WPF) 类的实例时，应该注意在调用类构造函数时所执行的代码中，需要有意地不包含 Windows Presentation Foundation (WPF) 类的对象初始化的几个方面。 特别是对于控件类，该控件的大部分可视化表示形式都不是由构造函数定义的。 而是由控件的模板定义。 模板可能来自各种源，但最常见的情况是来自于主题样式。 模板实际上是晚期绑定的；在控件已准备好布局之后，才会将所需模板附加到相关控件。 并且控件只有在已附加到连接到根级别的呈现图面的逻辑树时，才能准备好应用布局。 正是该根级别元素启动逻辑树中定义的所有子元素的呈现。

可视化树也参与此过程。 通过模板成为可视化树一部分的元素也是在连接后才完全实例化的。

此行为的结果是依赖某个元素已完成的可视化特征的某些操作需要额外的步骤。 例如，如果你试图获取一个已构造但尚未附加到树中的类的可视化特征，就需要额外的步骤。 例如，如果你想要调用[Render](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.rendertargetbitmap.render)上[RenderTargetBitmap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.rendertargetbitmap)均通过视觉对象是未连接到树中，元素和额外的初始化步骤在完成之前，该元素不是直观地完成。

#### 使用 BeginInit 和 EndInit 初始化元素

各个类中的WPF实现[ISupportInitialize](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.isupportinitialize)接口。 您使用[BeginInit](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.isupportinitialize.begininit)和[EndInit](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.isupportinitialize.endinit)接口来表示包含初始化步骤 （例如，设置属性的值影响呈现的） 在代码中的区域的方法。 之后[EndInit](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.isupportinitialize.endinit)调用布局系统在序列中，可以处理元素并开始查找隐式样式。

如果该元素设置属性上是[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)或[FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement)派生的类，则可以调用的类版本[BeginInit](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.begininit)并[EndInit](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.endinit)而不是强制转换为[ISupportInitialize](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.isupportinitialize)。

#### 代码示例

下面的示例是使用呈现的控制台应用程序的示例代码API并[XamlReader.Load(Stream)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.xamlreader.load#System_Windows_Markup_XamlReader_Load_System_IO_Stream_)松散XAML文件来说明的正确位置[BeginInit](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.begininit)并[EndInit](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.endinit)相对于其他API调用调整影响呈现的属性。

该示例仅演示主要函数。 函数 `Rasterize` 和 `Save`（未显示）是负责图像处理和 IO 的实用工具函数。

```csharp
[STAThread]
static void Main(string[] args)
{
    UIElement e;
    string file = Directory.GetCurrentDirectory() + "\\starting.xaml";
    using (Stream stream = File.Open(file, FileMode.Open))
    {
        // loading files from current directory, project settings take care of copying the file
        ParserContext pc = new ParserContext();
        pc.BaseUri = new Uri(file, UriKind.Absolute);
        e = (UIElement)XamlReader.Load(stream, pc);
    }

    Size paperSize = new Size(8.5 * 96, 11 * 96);
    e.Measure(paperSize);
    e.Arrange(new Rect(paperSize));
    e.UpdateLayout();

    /*
     *   Render effect at normal dpi, indicator is the original RED rectangle
     */
    RenderTargetBitmap image1 = Rasterize(e, paperSize.Width, paperSize.Height, 96, 96);
    Save(image1, "render1.png");

    Button b = new Button();
    b.BeginInit();
    b.Background = Brushes.Blue;
    b.Width = b.Height = 200;
    b.EndInit();
    b.Measure(paperSize);
    b.Arrange(new Rect(paperSize));
    b.UpdateLayout();

    // now render the altered version, with the element built up and initialized

    RenderTargetBitmap image2 = Rasterize(b, paperSize.Width, paperSize.Height, 96, 96);
    Save(image2, "render2.png");
}
```

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/element-tree-and-serialization-how-to-topics)

本部分中的主题介绍如何使用 WPF 元素树。

### 本节内容

[按名称查找元素](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-find-an-element-by-its-name)
[重写逻辑树](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-override-the-logical-tree)

### [Find an Element by Its Name](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-find-an-element-by-its-name)

本示例介绍了如何使用[FindName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.findname)方法以查找元素其[Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.name)值。

#### 示例

在此示例中，要按其名称查找特定元素的方法是编写为一个按钮的事件处理程序。 `stackPanel` 是[Name](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.name)根的[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)要搜索和示例方法然后直观指示所找到的元素通过强制转换为其作为[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)和更改其中一个[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)可见UI属性。

```csharp
void Find(object sender, RoutedEventArgs e)
{
    object wantedNode = stackPanel.FindName("dog");
    if (wantedNode is TextBlock)
    {
        // Following executed if Text element was found.
        TextBlock wantedChild = wantedNode as TextBlock;
        wantedChild.Foreground = Brushes.Blue;
    }
}
```

### [Override the Logical Tree](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-override-the-logical-tree)

尽管在大多数情况下不必重写逻辑树，但资深的控件创作者可选择执行此操作。

#### 示例

本示例介绍了如何子类[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)重写逻辑树中，在这种情况下强制执行面板可能只能有并且将仅呈现单个子元素的行为。 这不一定是实际需要的行为，但在这里进行演示是为了举例说明重写元素的正常逻辑树的情况。

```csharp
public class SingletonPanel : StackPanel
{
    //private UIElementCollection _children; 
    private FrameworkElement _child;

    public SingletonPanel()
    {

    }

    public FrameworkElement SingleChild
    {

        get { return _child; }
        set
        {
            if (value == null)
            {
                RemoveLogicalChild(_child);
            }
            else
            {
                if (_child == null)
                {
                    _child = value;
                }
                else
                {
                    // raise an exception?
                    MessageBox.Show("Needs to be a single element");
                }
            }
        }
    }
    public void SetSingleChild(object child)
    {
        this.AddLogicalChild(child);
    }

    public new void AddLogicalChild(object child)
    {
        _child = (FrameworkElement)child;
        if (this.Children.Count == 1)
        {
            this.RemoveLogicalChild(this.Children[0]);
            this.Children.Add((UIElement)child);
        }
        else
        {
            this.Children.Add((UIElement)child);
        }
    }

    public new void RemoveLogicalChild(object child)
    {
        _child = null;
        this.Children.Clear();
    }
    protected override IEnumerator LogicalChildren
    {
        get
        {
            // cheat, make a list with one member and return the enumerator
            ArrayList _list = new ArrayList();
            _list.Add(_child);
            return (IEnumerator)_list.GetEnumerator();
        }
    }
}
```

有关逻辑树的详细信息，请参阅 [WPF 中的树](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/trees-in-wpf)。