# [Data](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/)

Windows Presentation Foundation (WPF) 数据绑定为应用程序呈现数据并与数据交互提供了一种简单且一致的方式。 元素能够以 公共语言运行时 (CLR) 对象和 XML 的形式绑定到各种数据源中的数据。 Windows Presentation Foundation (WPF) 还提供了通过拖放操作传输数据的机制。

## 本节内容

[数据绑定](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-wpf)
[拖放](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/drag-and-drop)

## [Data Binding](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/data-binding-wpf)

Windows Presentation Foundation (WPF) 数据绑定提供了简单的应用程序为与数据交互和呈现的一致方法。 元素可以从多个公共语言运行时 (CLR) 对象和 XML 的形式中的数据源绑定到数据。

### 本节内容

[数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview)
[绑定源概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/binding-sources-overview)
[数据模板化概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-templating-overview)
[绑定声明概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/binding-declarations-overview)
[帮助主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-how-to-topics)

### [Data Binding Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/data-binding-overview)

Windows Presentation Foundation (WPF) 数据绑定为应用程序呈现数据并与数据交互提供了一种简单且一致的方式。 元素能够以 公共语言运行时 (CLR) 对象和 XML 形式绑定到来自各种数据源的数据。 [ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)如 s[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)并[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)如 s[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)和[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)具有内置功能，使灵活的样式设置单个数据项的集合。 可基于数据生成排序、筛选和分组视图。

WPF 中的数据绑定功能与传统模型相比具有几个优点，包括本质上支持数据绑定的大量属性、灵活的 UI 数据 UI 表示形式以及业务逻辑与 UI 的完全分离。

本主题首先讨论基本概念WPF的使用情况数据绑定，然后[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)类和数据绑定的其他功能。

#### 什么是数据绑定？

数据绑定是在应用程序 UI 和业务逻辑之间建立连接的过程。 如果绑定具有正确的设置，并且数据提供适当的通知，则在数据更改其值时，绑定到该数据的元素会自动反映更改。 数据绑定还意味着，如果元素中数据的外部表示形式发生更改，则基础数据可以自动进行更新以反映更改。 例如，如果用户编辑中的值[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)元素，则基础数据值自动更新以反映所做的更改。

数据绑定的典型用法是将服务器或本地配置数据放置到窗体或其他 UI 控件中。 在 WPF 中，此概念得到扩展，包括将大量属性绑定到各种数据源。 在 WPF 中，元素的依赖属性可以绑定到 CLR 对象（包括 ADO.NET 对象或与 Web 服务和 Web 属性关联的对象）和 XML 数据。

有关数据绑定的示例，请参阅[数据绑定演示](https://go.microsoft.com/fwlink/?LinkID=163703)中的以下应用程序 UI：

![数据绑定示例屏幕快照](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/media/databinding-databindingdemo.png)

以上是一个显示拍卖项列表的应用程序 UI。 应用程序演示了数据绑定的以下功能：

- 内容[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)绑定到的集合*AuctionItem*对象。 *AuctionItem* 对象具有 *Description*、*StartPrice*、*StartDate*、*Category*、*SpecialFeatures* 等属性。
- 数据 (*AuctionItem*对象) 中显示[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)是模板化，以便每个项显示的说明和当前价格。 这是使用[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)。 此外，每个项的外观取决于要显示的 *AuctionItem* 的 *SpecialFeatures* 值。 如果 *AuctionItem*的 *SpecialFeatures* 值为 *Color*，则该项具有蓝色边框。 如果值为 *Highlight*，则该项具有橙色边框和一个星号。 [数据模板化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview#data_templating)部分提供了数据模板化的相关信息。
- 用户可以进行分组、 筛选或排序数据使用[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)es 提供。 在上图中，"按类别的组"和"按类别和日期排序" [CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)es 选择。 你可能已注意到，数据按产品类别分组，类别名称按字母顺序排序。 这些项还按每个类别中的开始日期排序，但难以从图中注意到这一点。 这可使用*集合视图*来实现。 [绑定到集合](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview#binding_to_collections)部分讨论了集合视图。
- 当用户选择某个项，[ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)显示选定项的详细信息。 这称为*主从方案*。 [主从方案](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview#master_detail_scenario)部分提供了有关此类型的绑定方案的信息。
- 类型*StartDate*属性是[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)，这会返回一个日期，包括到毫秒的时间。 在此应用程序中，使用了一个自定义转换器，以便显示较短的日期字符串。 [数据转换](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview#data_conversion)部分提供了有关转换器的信息。

当用户单击“添加产品”按钮时，会出现以下窗体：

![添加产品清单页](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/media/databinding-demo-addproductlisting.png)

用户可以编辑窗体中的字段，使用简略预览和详细预览窗格来预览产品清单，然后单击“提交”以添加新的产品清单。 任何现有的分组、筛选和排序功能都将应用于新项。 在这种特殊情况下，上图中输入的项会作为 *Computer*类别中的第二项显示。

不会显示此映像是中提供的验证逻辑*Start Date* [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。 如果用户输入无效日期 （格式无效或为过去的日期），将通过通知用户[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)和一个红色感叹号旁边[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。 [数据验证](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview#data_validation)一节讨论了如何创建验证逻辑。

在详细介绍数据绑定的上述不同功能之前，我们会先在下一节中讨论一些对理解 WPF 数据绑定非常重要的基本概念。

#### 数据绑定基本概念

不论要绑定什么元素，也不论数据源的特性是什么，每个绑定都始终遵循下图所示的模型：

![基本数据绑定示意图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/media/databindingmostbasic.png)

如上图所示，数据绑定实质上是绑定目标与绑定源之间的桥梁。 该图演示了以下基本的 WPF 数据绑定概念：

- 通常，每个绑定都具有以下四个组件：绑定目标对象、目标属性、绑定源，以及要使用的绑定源中的值路径。 例如，如果你想要的内容绑定[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)到*名称*的属性*员工*对象，您的目标对象是[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)，目标属性是[Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.text)属性，要使用的值是*名称*，和源对象是*员工*对象。
- 目标属性必须为依赖属性。 大多数[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)属性是依赖关系属性和大多数依赖项属性，除了只读属性，默认情况下支持数据绑定。 (仅[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)类型可以定义依赖关系属性和所有[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)派生自[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)。)
- 尽管图中并未指出，但请注意，绑定源对象并不限于自定义 CLR 对象。 WPF 数据绑定支持 CLR 对象和 XML形式的数据。 若要提供一些示例，绑定源可以是[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)，任何列表对象、CLR与关联的对象ADO.NET数据或 Web 服务或 XmlNode 包含你XML数据。 有关详细信息，请参阅[绑定源概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/binding-sources-overview)。

在通读其他 软件开发工具包 (SDK) 主题时，请务必记住：在建立绑定时，需要将绑定目标绑定*到*绑定源。 例如，如果您要显示某些基础XML中的数据[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)使用数据绑定时，要绑定您[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)到XML数据。

若要建立绑定，请使用[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)对象。 本主题的其余部分将讨论的许多相关的概念和一些属性和使用情况的[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)对象。

##### 数据流的方向

正如前面提到的以及在上图中箭头所示，绑定的数据流可以进入从绑定目标绑定源 (例如，源值发生更改时用户编辑的值[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)) 和/或从绑定源到绑定目标 (例如，你[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)内容更新的是绑定源中的更改) 如果绑定源提供适当的通知。

可能希望应用程序允许用户更改数据，然后将该数据传播回源对象。 或者，可能不希望允许用户更新源数据。 您可以通过设置控制这[Mode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.mode)属性在[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)对象。 下图演示了不同类型的数据流：

![数据绑定数据流](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/media/databinding-dataflow.png)

- [OneWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_OneWay) 绑定导致更改源属性自动更新目标属性，但对目标属性的更改不会传播回源属性。 如果绑定的控件为隐式只读，则此类型的绑定适用。 例如，可能绑定到如股票行情自动收录器这样的源，或许目标属性没有用于进行更改的控件接口（如表的数据绑定背景色）。 如果无需监视目标属性的更改，则使用 [OneWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_OneWay) 绑定模式可避免 [TwoWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_TwoWay) 绑定模式的系统开销。
- [TwoWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_TwoWay) 绑定导致更改源属性或自动更新另的目标属性。 此类型的绑定适用于可编辑窗体或其他完整交互式的 UI 方案。 大多数属性默认为[OneWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_OneWay)绑定，但某些依赖关系属性 (通常是用户可编辑控件的属性[Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.text)属性[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)并[IsChecked](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.togglebutton.ischecked)属性[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)) 默认为[TwoWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_TwoWay)绑定。 确定依赖属性绑定在默认情况下是单向还是双向的编程方法是：使用 [GetMetadata](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.getmetadata) 获取属性的属性元数据，然后检查 [BindsTwoWayByDefault](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkpropertymetadata.bindstwowaybydefault) 属性的布尔值。
- [OneWayToSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_OneWayToSource) 相反[OneWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_OneWay)绑定; 它的源属性更改时，更新目标属性。 一个示例方案是只需要从 UI 重新计算源值的情况。
- 不在图中所示是[OneTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_OneTime)绑定，这将导致源属性传入以初始化目标属性，但不是传播后续更改。 这意味着，如果数据上下文发生了更改，或者数据上下文中的对象发生了更改，该更改不会反映在目标属性中。 如果你在适合使用当前状态的快照或数据实际为静态数据的位置使用数据，则此类型的绑定适合。 如果你想使用源属性中的某个值来初始化目标属性，且提前不知道数据上下文，则此类型的绑定也有用。 这是实质上是 [OneWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_OneWay) 绑定的一种简化形式，它在源值不更改的情况下提供更好的性能。

请注意，若要检测源更改 (适用于[OneWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_OneWay)并[TwoWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_TwoWay)绑定)，源必须实现一种合适的属性更改通知机制如[INotifyPropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.inotifypropertychanged)。 请参阅[实现属性更改通知](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-implement-property-change-notification)有关的示例[INotifyPropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.inotifypropertychanged)实现。

[Mode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.mode)属性页提供了有关绑定模式和如何指定绑定方向的示例的详细信息。



##### 触发源更新的因素

绑定[TwoWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_TwoWay)或[OneWayToSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_OneWayToSource)侦听目标属性中的更改并将其传播回源。 这称为更新源。 例如，可以编辑文本框的文本以更改基础源值。 如在上一部分中所述，通过的值来确定数据流的方向[Mode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.mode)绑定的属性。

但是，源值是在编辑文本的同时进行更新，还是在结束编辑文本并将鼠标指针从文本框移走后才进行更新呢？[UpdateSourceTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.updatesourcetrigger)绑定属性确定触发源更新。 下图中的右箭头的点说明的角色[UpdateSourceTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.updatesourcetrigger)属性：

![UpdateSourceTrigger 关系图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/media/databindingupdatesourcetrigger.png)

如果[UpdateSourceTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.updatesourcetrigger)值是[PropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.updatesourcetrigger#System_Windows_Data_UpdateSourceTrigger_PropertyChanged)，然后值指向的向右箭头[TwoWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_TwoWay)或[OneWayToSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_OneWayToSource)获取尽快目标属性更改更新绑定。 但是，如果[UpdateSourceTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.updatesourcetrigger)值是[LostFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.updatesourcetrigger#System_Windows_Data_UpdateSourceTrigger_LostFocus)，则该值仅获取更新的新值与目标属性失去焦点时。

类似于[Mode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.mode)属性，不同的依赖属性具有不同的默认[UpdateSourceTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.updatesourcetrigger)值。 大多数依赖属性的默认值为 [PropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.updatesourcetrigger#System_Windows_Data_UpdateSourceTrigger_PropertyChanged)，而 [Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.text) 属性的默认值为 [LostFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.updatesourcetrigger#System_Windows_Data_UpdateSourceTrigger_LostFocus)。 这意味着源更新通常会在每当目标属性更改，这是相当不错的[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)es 和其他简单控件。 但对于文本字段，每次击键之后都进行更新会降低性能，用户也没有机会在提交新值之前使用 Backspace 键修改键入错误。 这就是为什么[Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.text)属性具有默认值为[LostFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.updatesourcetrigger#System_Windows_Data_UpdateSourceTrigger_LostFocus)而不是[PropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.updatesourcetrigger#System_Windows_Data_UpdateSourceTrigger_PropertyChanged)。

请参阅[UpdateSourceTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.updatesourcetrigger)属性页，了解有关如何查找默认信息[UpdateSourceTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.updatesourcetrigger)依赖属性的值。

下表为每个提供的示例方案[UpdateSourceTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.updatesourcetrigger)值使用[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)作为示例：

| UpdateSourceTrigger 值                                       | 源值何时进行更新                                             | 文本框的示例方案                                             |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| LostFocus (默认为[TextBox.Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.text)) | 当 TextBox 控件失去焦点时                                    | 一个[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)验证逻辑与该键相关联 （请参阅数据验证部分） |
| PropertyChanged                                              | 如您将键入 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) | [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 聊天室窗口中的控件 |
| Explicit                                                     | 当应用程序调用 [UpdateSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingexpression.updatesource) | [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) （仅当用户单击提交按钮时，更新源值） 的可编辑窗体中的控件 |

有关示例，请参阅[控制文本框文本更新源的时间](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-control-when-the-textbox-text-updates-the-source)。

#### 创建绑定

可以概括一些前面各节中讨论的概念，在建立绑定使用[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)对象，并将每个绑定通常具有四个组件： 绑定到要使用的源值的目标、 目标属性、 绑定源和路径。 本节讨论如何设置绑定。

请考虑以下示例，其中的绑定源对象是一个名为 *MyData* 的类，该类在 *SDKSample* 命名空间中定义。 出于演示目的，*MyData* 类具有一个名为 *ColorName* 的字符串属性，该属性的值设置为“Red”。 因此，此示例生成一个具有红色背景的按钮。

```xaml
<DockPanel
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  xmlns:c="clr-namespace:SDKSample">
  <DockPanel.Resources>
    <c:MyData x:Key="myDataSource"/>
  </DockPanel.Resources>
  <DockPanel.DataContext>
    <Binding Source="{StaticResource myDataSource}"/>
  </DockPanel.DataContext>
  <Button Background="{Binding Path=ColorName}"
          Width="150" Height="30">I am bound to be RED!</Button>
</DockPanel>
```

有关绑定声明语法的详细信息以及如何在代码中设置绑定的示例，请参阅[绑定声明概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/binding-declarations-overview)。

如果将此示例应用于基本关系图，则生成的图如下所示。 这是[OneWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_OneWay)绑定，因为 Background 属性支持[OneWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_OneWay)绑定默认情况下。

![数据绑定关系图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/media/databindingbuttonbackgroundexample.png)

您可能想知道为什么这样即使*ColorName*属性的类型是字符串时[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)属性属于类型[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)。 这是由于进行了默认类型转换，此类型转换在[数据转换](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview#data_conversion)一节中进行讨论。

##### 指定绑定源

请注意，在上一示例中，绑定源指定通过设置[DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext)属性上的[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)元素。 [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)然后继承[DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext)值从[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)，这是其父元素。 重申一下，绑定源对象是绑定的四个必需组件之一。 因此，如果未指定绑定源对象，则绑定将没有任何作用。

可通过多种方法指定绑定源对象。 使用[DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext)父元素上的属性时要将多个属性绑定到同一源很有用。 不过，有时在个别绑定声明中指定绑定源可能更为合适。 对于上述示例中，而不是使用[DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext)属性，可以通过设置指定绑定源[Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.source)直接上的按钮，如以下示例所示的绑定声明的属性：

```xaml
<DockPanel.Resources>
  <c:MyData x:Key="myDataSource"/>
</DockPanel.Resources>
<Button Width="150" Height="30"
        Background="{Binding Source={StaticResource myDataSource},
                             Path=ColorName}">I am bound to be RED!</Button>
```

而不设置[DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext)属性元素上直接，继承[DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext)值从上级 （如第一个示例中的按钮），并显式指定绑定源设置[Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.source)上的属性[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)（如按钮为最后一个示例） 还可以使用[ElementName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.elementname)属性或[RelativeSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.relativesource)属性指定绑定源。 [ElementName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.elementname)属性绑定到其他元素中的应用程序，例如当使用滑块调整按钮的宽度时很有用。[RelativeSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.relativesource)属性中指定的绑定时很有用[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)或[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)。 有关详细信息，请参阅[指定绑定源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-specify-the-binding-source)。

##### 指定值的路径

如果绑定源是一个对象，则使用[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.path)属性来指定要用于绑定的值。 如果要绑定到XML数据，使用[XPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.xpath)属性指定的值。 在某些情况下，它可能是适用于使用[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.path)属性，即使你的数据是XML。 例如，如果你想要访问返回的 XmlNode （作为 XPath 查询） 的结果的 Name 属性，则应使用[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.path)属性设置为除[XPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.xpath)属性。

有关语法信息和示例，请参阅[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.path)和[XPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.xpath)属性页。

请注意，虽然我们已强调[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.path)到要使用的值是你想要绑定到整个对象的情况中的一个绑定的四个必要组件之一，要使用的值将作为绑定源对象相同。 在这些情况下，它是不适宜指定[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.path)。 请看下面的示例：

```xaml
<ListBox ItemsSource="{Binding}"
         IsSynchronizedWithCurrentItem="true"/>
```

以上示例使用空绑定语法：{Binding}。 在这种情况下，[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)从父 DockPanel 元素 （不在此示例中所示） 继承 DataContext。 未指定路径时，默认为绑定到整个对象。 换而言之，在此示例中，该路径已被省略，因为我们要绑定[ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource)到整个对象的属性。 （有关深入讨论，请参阅[绑定到集合](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview#binding_to_collections)一节。）

除了绑定到集合以外，在希望绑定到整个对象，而不是仅绑定到对象的单个属性时，也可以使用此方案。 例如，在源对象为类型字符串，并且仅仅希望绑定到该字符串本身时。 另一种常见情况是希望将一个元素绑定到一个具有多个属性的对象。

请注意，可能需要应用自定义逻辑，以便数据对于绑定的目标属性有意义。 自定义逻辑可能采用自定义转换器形式（如果不存在默认的类型转换）。 有关转换器的信息，请参阅[数据转换](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview#data_conversion)。



##### Binding 和 BindingExpression

之前的其他功能和数据绑定的用法，它可以用来引入[BindingExpression](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingexpression)类。 如前面部分中所见[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)类是绑定; 声明的高级类[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)类提供了许多允许您指定的绑定特性的属性。 相关的类， [BindingExpression](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingexpression)，是保留在源和目标之间连接的基础对象。 一个绑定包含了可以在多个绑定表达式之间共享的所有信息。 一个[BindingExpression](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingexpression)是不能共享的实例表达式，包含的所有实例信息[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)。

例如，考虑以下内容，其中*myDataObject*的一个实例*MyData*类*myBinding*源[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)对象，并且*MyData*类是一个包含名为的字符串属性的定义的类*MyDataProperty*。 此示例绑定的文本内容*mytext*，实例[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)到*MyDataProperty*。

```csharp
// Make a new source.
MyData myDataObject = new MyData(DateTime.Now);      
Binding myBinding = new Binding("MyDataProperty");
myBinding.Source = myDataObject;
// Bind the new data source to the myText TextBlock control's Text dependency property.
myText.SetBinding(TextBlock.TextProperty, myBinding);
```

可以使用同一 *myBinding* 对象来创建其他绑定。 例如，可以使用 *myBinding* 对象将复选框的文本内容绑定到 *MyDataProperty*。 在这种情况下，将有两个实例[BindingExpression](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingexpression)共享*myBinding*对象。

一个[BindingExpression](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingexpression)对象可以通过调用的返回值获得[GetBindingExpression](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingoperations.getbindingexpression)数据绑定对象上。 以下主题演示一些的用法[BindingExpression](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingexpression)类：

- [从已绑定的目标属性获取绑定对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-get-the-binding-object-from-a-bound-target-property)
- [控制文本框文本更新源的时间](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-control-when-the-textbox-text-updates-the-source)

#### 数据转换

在上一示例中，按钮为红色，因为其[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)属性绑定到具有值"Red"的字符串属性。 这样做的原因是上存在的类型转换器[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)要转换到的字符串值类型[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)。

若要将此信息添加到[创建绑定](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview#creating_a_binding)一节的图中，关系图如下所示：

![数据绑定关系图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/media/databindingbuttondefaultconversion.png)

但是，如果而不是让您的绑定源对象具有类型字符串的属性*颜色*类型的属性[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.color)？ 在这种情况下，为了使绑定能够处理您需要首先*颜色*转换的内容的属性值的[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)属性接受。 需要通过实现来创建自定义转换器[IValueConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.ivalueconverter)接口，如以下示例所示：

```csharp
[ValueConversion(typeof(Color), typeof(SolidColorBrush))]
public class ColorBrushConverter : IValueConverter
{
    public object Convert(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
    {
        Color color = (Color)value;
        return new SolidColorBrush(color);
    }

    public object ConvertBack(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
    {
        return null;
    }
}
```

[IValueConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.ivalueconverter)参考页提供了详细信息。

现在使用自定义转换器而不是默认转换，关系图如下所示：

![数据绑定关系图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/media/databindingconvertercolorexample.png)

重申一下，由于要绑定到的类型中提供了类型转换器，因此可以使用默认转换。 此行为取决于目标中可用的类型转换器。 如果无法确定，请创建自己的转换器。

下面提供了一些典型方案，在这些方案中，实现数据转换器非常有意义：

- 数据应根据区域性以不同方式显示。 例如，可能需要根据在特定区域性中使用的值或标准，实现货币转换器或日历日期/时间转换器。
- 使用的数据不一定会更改属性的文本值，但会更改其他某个值（如图像的源，或显示文本的颜色或样式）。在这种情况下，可以通过转换可能不合适的属性绑定（如将文本字段绑定到表单元格的 Background 属性）来使用转换器。
- 将多个控件或控件的多个属性绑定到相同数据。 在这种情况下，主绑定可能仅显示文本，而其他绑定则处理特定的显示问题，但仍使用同一绑定作为源信息。
- 到目前为止我们尚未讨论[MultiBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.multibinding)，其中的目标属性都有绑定的集合。 情况下[MultiBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.multibinding)，使用自定义[IMultiValueConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.imultivalueconverter)以生成最终值从绑定的值。 例如，可以从红色、蓝色和绿色的值来计算颜色，这些值可能来自相同绑定源对象，也可能来自不同绑定源对象。 请参阅[MultiBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.multibinding)类页有关示例和信息。

#### 绑定到集合

绑定源对象可以视为其属性包含数据的单个对象，也可以视为通常组合在一起的多态对象的数据集合（如数据库的查询结果）。 到目前为止，我们仅讨论了绑定到单个对象，但绑定到数据集合才是一种常见方案。 例如，一种常见方案是使用[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)如[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)， [ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)，或[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)来显示数据集合，如在应用程序中所示[什么是数据绑定？](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview#what_is_data_binding)部分。

幸运的是，基本关系图仍然适用。 如果要绑定[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)到一个集合，该关系图如下所示：

![数据绑定 ItemsControl 关系图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/media/databindingitemscontrol.png)

如要绑定此关系图中所示[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)的集合对象，[ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource)属性是要使用的属性。 您可以看作[ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource)属性的内容作为[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)。 请注意，该绑定是[OneWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_OneWay)因为[ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource)属性支持[OneWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_OneWay)绑定默认情况下。

##### 如何实现集合

可以枚举实现任何集合[IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable)接口。 但是，若要设置动态绑定，以便插入或删除集合中的更新UI自动，该集合必须实现[INotifyCollectionChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.specialized.inotifycollectionchanged)接口。 此接口公开一个事件，只要基础集合发生更改，就应该引发该事件。

WPF 提供了[ObservableCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.objectmodel.observablecollection-1)类，该类是公开的数据集合的内置实现[INotifyCollectionChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.specialized.inotifycollectionchanged)接口。 请注意，若要完全支持传输来自源对象到目标的数据值，支持可绑定属性在集合中的每个对象还必须实现[INotifyPropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.inotifypropertychanged)接口。 有关详细信息，请参阅[绑定源概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/binding-sources-overview)。

在实现自己的集合之前, 请考虑使用[ObservableCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.objectmodel.observablecollection-1)或一个现有集合类，如[List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1)， [Collection](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.objectmodel.collection-1)，和[BindingList](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.bindinglist-1)，此外还有许多其他。 如果有高级的方案，但希望实现自己的集合，请考虑使用[IList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ilist)，它提供可单独访问的索引，因此获得最佳性能的对象的非泛型集合。

##### 集合视图

一次你[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)绑定到数据集合，您可能需要排序、 筛选或分组数据。 若要执行此操作，应使用集合视图，这是实现的类[ICollectionView](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.icollectionview)接口。

###### 什么是集合视图？

集合视图这一层基于绑定源集合，它允许基于排序、筛选和分组查询来导航并显示源集合，而无需更改基础源集合本身。 集合视图还维护一个指向集合中当前项的指针。 如果源集合实现[INotifyCollectionChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.specialized.inotifycollectionchanged)接口，所做的更改引起[CollectionChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.specialized.inotifycollectionchanged.collectionchanged)事件传播到视图。

由于视图不会更改基础源集合，因此每个源集合都可以有多个关联的视图。 例如，可以有 *Task* 对象的集合。 使用视图，可以通过不同方式显示相同数据。 例如，可能希望在页面左侧显示按优先级排序的任务，而在页面右侧显示按区域分组的任务。

#### 如何创建视图

创建并使用视图的一种方式是直接实例化视图对象，然后将它用作绑定源。 例如，请考虑在[什么是数据绑定？](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview#what_is_data_binding)一节中显示的[数据绑定演示](https://go.microsoft.com/fwlink/?LinkID=163703)应用程序。 实现应用程序，以便[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)直接绑定到视图而不是数据收集的数据集合。 下面的示例摘自[数据绑定演示](https://go.microsoft.com/fwlink/?LinkID=163703)应用程序。 [CollectionViewSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource)类是可扩展应用程序标记语言 (XAML)继承的类的代理[CollectionView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionview)。 在此特定示例中，[Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource.source)视图的绑定到*AuctionItems*集合 (类型的[ObservableCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.objectmodel.observablecollection-1)) 的当前应用程序对象。

```xaml
<Window.Resources>
```

```xaml
<CollectionViewSource 
      Source="{Binding Source={x:Static Application.Current}, Path=AuctionItems}"   
      x:Key="listingDataView" />
```

```xaml
</Window.Resources>
```

资源*listingDataView*然后如用作应用程序中的元素的绑定源[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox):

```xaml
<ListBox Name="Master" Grid.Row="2" Grid.ColumnSpan="3" Margin="8"
    ItemsSource="{Binding Source={StaticResource listingDataView}}">
```

```xaml
</ListBox>
```

若要创建另一个视图相同的集合，可以创建另一个[CollectionViewSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource)实例，并为其提供不同`x:Key`名称。

下表显示了哪些视图数据类型创建为默认集合视图或[CollectionViewSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource)基于源集合类型。

| 源集合类型                                                   | 集合视图类型                                                 | 说明               |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------ |
| [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable) | 基于内部类型 [CollectionView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionview) | 无法对项进行分组。 |
| [IList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ilist) | [ListCollectionView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.listcollectionview) | 最快。             |
| [IBindingList](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.ibindinglist) | [BindingListCollectionView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindinglistcollectionview) |                    |

##### 使用默认视图

创建并使用集合视图的一种方式是指定集合视图作为绑定源。 WPF 还会为用作绑定源的每个集合创建一个默认集合视图。 如果直接绑定到集合，WPF 会绑定到该集合的默认视图。 请注意，此默认视图由同一集合的所有绑定共享，因此一个绑定控件或代码对默认视图所做的更改（如排序或对当前项指针的更改，下文将对此进行讨论）会反映到同一集合的所有其他绑定中。

若要获取的默认视图，请使用[GetDefaultView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource.getdefaultview)方法。 有关示例，请参阅[获取数据集合的默认视图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-get-the-default-view-of-a-data-collection)。

##### 包含 ADO.NET DataTables 的集合视图

若要提高性能，ADO.NET 的集合视图[DataTable](https://docs.microsoft.com/zh-cn/dotnet/api/system.data.datatable)或[DataView](https://docs.microsoft.com/zh-cn/dotnet/api/system.data.dataview)对象将排序和筛选来委派[DataView](https://docs.microsoft.com/zh-cn/dotnet/api/system.data.dataview)。 这会导致排序和筛选任务由数据源的所有集合视图分担。 若要启用每个集合视图进行排序和筛选独立，初始化每个集合视图有其自身[DataView](https://docs.microsoft.com/zh-cn/dotnet/api/system.data.dataview)对象。

###### 排序

如前所述，视图可以将排序顺序应用于集合。 如同在基础集合中一样，数据可能具有或不具有相关的固有顺序。借助集合视图，可以根据自己提供的比较条件来强制确定顺序，或更改默认顺序。 由于这是基于客户端的数据视图，因此一种常见情况是用户可能希望根据列对应的值，对多列表格数据进行排序。 通过使用视图，可以应用这种用户实施的排序，而无需对基础集合进行任何更改，甚至不必再次查询集合内容。 有关示例，请参阅[在单击标题时对 GridView 列进行排序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-sort-a-gridview-column-when-a-header-is-clicked)。

下面的示例显示了"按类别和日期排序"的排序逻辑[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)的应用程序UI中[什么是数据绑定？](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview#what_is_data_binding)部分：

```csharp
private void AddSorting(object sender, RoutedEventArgs args)
{
    // This sorts the items first by Category and within each Category,
    // by StartDate. Notice that because Category is an enumeration,
    // the order of the items is the same as in the enumeration declaration
    listingDataView.SortDescriptions.Add(
        new SortDescription("Category", ListSortDirection.Ascending));
    listingDataView.SortDescriptions.Add(
        new SortDescription("StartDate", ListSortDirection.Ascending));
}
```

###### 筛选

视图还可以将筛选器应用于集合。 这意味着即使集合中可能存在一个项，此特定视图也仅用于显示整个集合的某个子集。 可以根据条件在数据中进行筛选。 例如，正如在[什么是数据绑定？](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview#what_is_data_binding)部分中，"显示仅成交价等于"[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)包含逻辑，以便筛选出或大于 25 美元的项。 执行以下代码来设置*ShowOnlyBargainsFilter*作为[Filter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource.filter)事件处理程序时，[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)处于选中状态：

```csharp
listingDataView.Filter += new FilterEventHandler(ShowOnlyBargainsFilter);
```

*ShowOnlyBargainsFilter* 事件处理程序具有以下实现：

```csharp
private void ShowOnlyBargainsFilter(object sender, FilterEventArgs e)
{
    AuctionItem product = e.Item as AuctionItem;
    if (product != null)
    {
        // Filter out products with price 25 or above
        if (product.CurrentPrice < 25)
        {
            e.Accepted = true;
        }
        else
        {
            e.Accepted = false;
        }
    }
}
```

如果您正在使用它的[CollectionView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionview)类而不是直接[CollectionViewSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource)，将使用[Filter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionview.filter)属性指定一个回调。 有关示例，请参阅[筛选视图中的数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-filter-data-in-a-view)。

###### 分组

除了视图的内部类[IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable)集合中，所有集合视图都支持分组，这样用户就可以分区成逻辑组的集合视图中的集合的功能。 这些组可以是显式的，由用户提供组列表；也可以是隐式的，这些组依据数据动态生成。

下面的示例显示了"按类别的组"的逻辑[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox):

```csharp
// This groups the items in the view by the property "Category"
PropertyGroupDescription groupDescription = new PropertyGroupDescription();
groupDescription.PropertyName = "Category";
listingDataView.GroupDescriptions.Add(groupDescription);
```

有关其他分组示例，请参阅[对实现 GridView 的 ListView 中的项进行分组](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-group-items-in-a-listview-that-implements-a-gridview)。

###### 当前项指针

视图还支持当前项的概念。 可以在集合视图中的对象之间导航。 在导航时，你是在移动项指针，该指针可用于检索存在于集合中特定位置的对象。 有关示例，请参阅[在数据集合视图中的对象之间导航](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-navigate-through-the-objects-in-a-data-collectionview)。

由于 WPF 只通过使用视图（你指定的视图或集合的默认视图）绑定到集合，因此集合的所有绑定都有一个当前项指针。 绑定到视图时，`Path` 值中的斜杠（“/”）字符用于指定视图的当前项。 在下面的示例中，数据上下文是一个集合视图。 第一行绑定到集合。 第二行绑定到集合中的当前项。 第三行绑定到集合中当前项的 `Description`属性。

```xaml
<Button Content="{Binding }" />  
<Button Content="{Binding Path=/}" />  
<Button Content="{Binding Path=/Description}" />   
```

还可以连着使用斜杠和属性语法以遍历集合的分层。 以下示例绑定到一个名为 `Offices` 的集合的当前项，此集合是源集合的当前项的属性。

```xaml
<Button Content="{Binding /Offices/}" />  
```

当前项指针可能会受对集合应用的任何排序或筛选操作的影响。 排序操作将当前项指针保留在所选的最后一项上，但集合视图现已围绕此指针重构。 （或许所选项以前曾位于列表的开头，但现在所选项可能位于中间的某个位置。）如果所选内容在筛选之后保留在视图中，则筛选操作会保留所选项。 否则，当前项指针会设置为经过筛选的集合视图的第一项。

###### 主-从绑定方案

当前项的概念不仅适用于集合中各项的导航，也适用于主-从绑定方案。 再考虑一下[什么是数据绑定？](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview#what_is_data_binding)一节中的应用程序 UI。 在该应用程序的所选[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)确定中所示的内容[ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)。 若要将其放在另一种方法时[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)选择了项目，[ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)显示选定项的详细信息。

只需将两个或更多控件绑定到同一视图即可实现主-从方案。 下面的示例摘自[数据绑定演示](https://go.microsoft.com/fwlink/?LinkID=163703)显示的标记[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)和[ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)应用程序上看到UI中[什么是数据绑定？](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview#what_is_data_binding)部分：

```xaml
<ListBox Name="Master" Grid.Row="2" Grid.ColumnSpan="3" Margin="8"
    ItemsSource="{Binding Source={StaticResource listingDataView}}">
```

```xaml
</ListBox>
```

```xaml
<ContentControl Name="Detail" Grid.Row="3" Grid.ColumnSpan="3" 
        Content="{Binding Source={StaticResource listingDataView}}" 
        ContentTemplate="{StaticResource detailsProductListingTemplate}" 
        Margin="9,0,0,0"/>
```

请注意，这两个控件都绑定到同一个源，即 *listingDataView* 静态资源（请参阅[如何创建视图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview#how_to_create_a_view)一节中此资源的定义）。 这样做的原因时单一实例对象 ([ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)这种情况下) 绑定到一个集合视图，它会自动将绑定到[CurrentItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionview.currentitem)的视图。 请注意，[CollectionViewSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource)对象自动同步货币与所选内容。 如果列表控件未绑定到[CollectionViewSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource)对象与此示例中，则需要设置其[IsSynchronizedWithCurrentItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.selector.issynchronizedwithcurrentitem)属性设置为`true`为实现此目的。

有关其他示例，请参阅[绑定到集合并基于选择显示信息](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-bind-to-a-collection-and-display-information-based-on-selection)和[对分层数据使用主-从模式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-use-the-master-detail-pattern-with-hierarchical-data)。

你可能已经注意到上述示例使用了一个模板。 事实上，数据不会显示我们也希望而不使用模板的方式 (显式使用的那个[ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)和隐式使用的那个[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox))。 现在，我们开始介绍下一节中的数据模板化。

#### 数据模板化

如果不使用数据模板，[什么是数据绑定？](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview#what_is_data_binding)一节中的应用程序 UI 将如下所示：

![没有数据模板的数据绑定演示](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/media/databindingdemotemplates.png)

上一节中的示例中所示同时[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)控件和[ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)绑定到整个集合对象 （或更具体地说，集合对象视图） 的*AuctionItem*s。 如果没有特殊说明如何显示数据集合的[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)显示基础集合中的每个对象的字符串表示形式和[ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)显示它所绑定到的对象的字符串表示形式。

若要解决该问题，应用程序定义[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)s。 上一节中的示例中所示[ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)显式地使用*detailsProductListingTemplate*[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)。 [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)控制隐式使用以下[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)显示时*AuctionItem*集合中的对象：

```xaml
<DataTemplate DataType="{x:Type src:AuctionItem}">
    <Border BorderThickness="1" BorderBrush="Gray"
            Padding="7" Name="border" Margin="3" Width="500">
        <Grid>
          <Grid.RowDefinitions>
            <RowDefinition/>
            <RowDefinition/>
            <RowDefinition/>
            <RowDefinition/>
          </Grid.RowDefinitions>
          <Grid.ColumnDefinitions>
            <ColumnDefinition Width="20"/>
            <ColumnDefinition Width="86"/>
            <ColumnDefinition Width="*"/>
          </Grid.ColumnDefinitions>
              
            <Polygon Grid.Row="0" Grid.Column="0" Grid.RowSpan="4"
                     Fill="Yellow" Stroke="Black" StrokeThickness="1"
                     StrokeLineJoin="Round" Width="20" Height="20"
                     Stretch="Fill"
                     Points="9,2 11,7 17,7 12,10 14,15 9,12 4,15 6,10 1,7 7,7"
                     Visibility="Hidden" Name="star"/>

            <TextBlock Grid.Row="0" Grid.Column="1" Margin="0,0,8,0"
                       Name="descriptionTitle"
                       Style="{StaticResource smallTitleStyle}">Description:</TextBlock>
            <TextBlock Name="DescriptionDTDataType" Grid.Row="0" Grid.Column="2" 
                Text="{Binding Path=Description}" 
                Style="{StaticResource textStyleTextBlock}"/>

            <TextBlock Grid.Row="1" Grid.Column="1" Margin="0,0,8,0"
                       Name="currentPriceTitle"
                       Style="{StaticResource smallTitleStyle}">Current Price:</TextBlock>
            <StackPanel Grid.Row="1" Grid.Column="2" Orientation="Horizontal">
                <TextBlock Text="$" Style="{StaticResource textStyleTextBlock}"/>
                <TextBlock Name="CurrentPriceDTDataType" 
                    Text="{Binding Path=CurrentPrice}" 
                    Style="{StaticResource textStyleTextBlock}"/>
            </StackPanel>
        </Grid>
    </Border>
    <DataTemplate.Triggers>
        <DataTrigger Binding="{Binding Path=SpecialFeatures}">
            <DataTrigger.Value>
                <src:SpecialFeatures>Color</src:SpecialFeatures>
            </DataTrigger.Value>
          <DataTrigger.Setters>
            <Setter Property="BorderBrush" Value="DodgerBlue" TargetName="border" />
            <Setter Property="Foreground" Value="Navy" TargetName="descriptionTitle" />
            <Setter Property="Foreground" Value="Navy" TargetName="currentPriceTitle" />
            <Setter Property="BorderThickness" Value="3" TargetName="border" />
            <Setter Property="Padding" Value="5" TargetName="border" />
          </DataTrigger.Setters>
        </DataTrigger>
        <DataTrigger Binding="{Binding Path=SpecialFeatures}">
            <DataTrigger.Value>
                <src:SpecialFeatures>Highlight</src:SpecialFeatures>
            </DataTrigger.Value>
            <Setter Property="BorderBrush" Value="Orange" TargetName="border" />
            <Setter Property="Foreground" Value="Navy" TargetName="descriptionTitle" />
            <Setter Property="Foreground" Value="Navy" TargetName="currentPriceTitle" />
            <Setter Property="Visibility" Value="Visible" TargetName="star" />
            <Setter Property="BorderThickness" Value="3" TargetName="border" />
            <Setter Property="Padding" Value="5" TargetName="border" />
        </DataTrigger>
    </DataTemplate.Triggers>
</DataTemplate>
```

通过使用这两个[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)s，生成的 UI 是中所示[什么是数据绑定？](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview#what_is_data_binding)部分。 您可以看到屏幕快照，除了让您将数据放在控件中[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)s 允许您定义引人注目的视觉对象，为你的数据。 例如，[DataTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatrigger)更高版本中使用了[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)以便*AuctionItem*s *SpecialFeatures*的值*突出显示*会显示为带有橙色边框和一个星号。

有关数据模板的详细信息，请参阅[数据模板化概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-templating-overview)。

#### 数据验证

接受用户输入的大多数应用程序都需要具有验证逻辑，以确保用户输入了预期信息。 可基于类型、范围、格式或特定于应用程序的其他要求执行验证检查。 本节讨论了数据验证在 WPF 中的工作原理。

##### 将验证规则与绑定关联

WPF数据绑定模型，可将相关联[ValidationRules](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.validationrules)与你[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)对象。 例如，下面的示例将绑定[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)到名为的属性`StartPrice`，并添加[ExceptionValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.exceptionvalidationrule)对象传递给[Binding.ValidationRules](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.validationrules)属性。

```xaml
<TextBox Name="StartPriceEntryForm" Grid.Row="2" Grid.Column="1"
    Style="{StaticResource textStyleTextBox}" Margin="8,5,0,5">
  <TextBox.Text>
    <Binding Path="StartPrice" UpdateSourceTrigger="PropertyChanged">
      <Binding.ValidationRules>
        <ExceptionValidationRule />
      </Binding.ValidationRules>
    </Binding>
  </TextBox.Text>
</TextBox>
```

一个[ValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule)对象检查属性的值是否有效。 WPF 具有以下两种类型的内置[ValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule)对象：

- 一个[ExceptionValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.exceptionvalidationrule)检查的绑定源属性更新过程中引发的异常。 在以上示例中，`StartPrice` 为整数类型。 当用户输入的值无法转换为整数时，将引发异常，这会导致将绑定标记为无效。 设置的可选语法[ExceptionValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.exceptionvalidationrule)显式是设置[ValidatesOnExceptions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.validatesonexceptions)属性设置为`true`上你[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)或[MultiBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.multibinding)对象。
- 一个[DataErrorValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dataerrorvalidationrule)对象由对象实现的对象引发的错误检查[IDataErrorInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.idataerrorinfo)接口。 使用此验证规则的示例，请参阅[DataErrorValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dataerrorvalidationrule)。 设置的可选语法[DataErrorValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dataerrorvalidationrule)显式是设置[ValidatesOnDataErrors](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.validatesondataerrors)属性设置为`true`上你[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)或[MultiBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.multibinding)对象。

此外可以通过从派生来创建你自己的验证规则[ValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule)类和实现[Validate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule.validate)方法。 下面的示例演示使用的规则*添加产品清单*"开始日期"[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)从[什么是数据绑定？](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview#what_is_data_binding)部分：

```csharp
class FutureDateRule : ValidationRule
{
    public override ValidationResult Validate(object value, CultureInfo cultureInfo)
    {
        DateTime date;
        try
        {
            date = DateTime.Parse(value.ToString());
        }
        catch (FormatException)
        {
            return new ValidationResult(false, "Value is not a valid date.");
        }
        if (DateTime.Now.Date > date)
        {
            return new ValidationResult(false, "Please enter a date in the future.");
        }
        else
        {
            return ValidationResult.ValidResult;
        }
    }
}
```

*StartDateEntryForm* [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)使用此*FutureDateRule*，如以下示例所示：

```xaml
<TextBox Name="StartDateEntryForm" Grid.Row="3" Grid.Column="1" 
    Validation.ErrorTemplate="{StaticResource validationTemplate}" 
    Style="{StaticResource textStyleTextBox}" Margin="8,5,0,5">
    <TextBox.Text>
        <Binding Path="StartDate" UpdateSourceTrigger="PropertyChanged" 
            Converter="{StaticResource dateConverter}" >
            <Binding.ValidationRules>
                <src:FutureDateRule />
            </Binding.ValidationRules>
        </Binding>
    </TextBox.Text>
</TextBox>
```

请注意，由于[UpdateSourceTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.updatesourcetrigger)值是[PropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.updatesourcetrigger#System_Windows_Data_UpdateSourceTrigger_PropertyChanged)，绑定引擎都会更新源值在每次击键，这意味着它还检查中的每个规则[ValidationRules](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.validationrules)在每次击键的集合。 我们会在“验证过程”一节中对此深入讨论。

##### 提供视觉反馈

如果用户输入的值无效，你可能希望在应用程序 UI 上提供一些有关错误的反馈。 提供此类反馈是设置的一种方法[Validation.ErrorTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation.errortemplate)附加属性设置为自定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。 在上一小节中所示*StartDateEntryForm* [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)使用[ErrorTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation.errortemplate)调用*validationTemplate*。 以下示例显示了 *validationTemplate* 的定义：

```xaml
<ControlTemplate x:Key="validationTemplate">
  <DockPanel>
    <TextBlock Foreground="Red" FontSize="20">!</TextBlock>
    <AdornedElementPlaceholder/>
  </DockPanel>
</ControlTemplate>
```

[AdornedElementPlaceholder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.adornedelementplaceholder)元素指定要装饰的控件应放置的位置。

此外，还可以使用[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)显示错误消息。 这两个*StartDateEntryForm*并*StartPriceEntryForm*[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)es 使用样式*textStyleTextBox*，这将创建[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)，显示错误消息。 以下示例显示了 *textStyleTextBox* 的定义。 附加的属性[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)是`true`当一个或多个绑定元素的属性的绑定存在错误。

```xaml
<Style x:Key="textStyleTextBox" TargetType="TextBox">
  <Setter Property="Foreground" Value="#333333" />
  <Setter Property="MaxLength" Value="40" />
  <Setter Property="Width" Value="392" />
  <Style.Triggers>
    <Trigger Property="Validation.HasError" Value="true">
      <Setter Property="ToolTip"
        Value="{Binding RelativeSource={RelativeSource Self},
                        Path=(Validation.Errors)[0].ErrorContent}"/>
    </Trigger>
  </Style.Triggers>
</Style>
```

使用的自定义[ErrorTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation.errortemplate)并[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)，则*StartDateEntryForm* [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)验证错误时，看起来如下所示：

![数据绑定验证错误](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/media/databindingdemo-validation.png)

如果你[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)具有关联的验证规则，但不是指定[ErrorTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation.errortemplate)在绑定控件上，默认值[ErrorTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation.errortemplate)将用于验证错误时通知用户。 默认值[ErrorTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation.errortemplate)是装饰器层中定义红色边框的控件模板。 默认值[ErrorTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation.errortemplate)并[ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)，则UI的*StartPriceEntryForm* [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)验证错误时，看起来如下所示：

![数据绑定验证错误](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/media/databindingdemo-validationdefault.png)

有关如何提供逻辑以验证对话框中所有控件的示例，请参阅[对话框概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/dialog-boxes-overview)中的“自定义对话框”一节。

##### 验证过程

通常，在目标的值传输到绑定源属性时会进行验证。 在将发生这种情况[TwoWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_TwoWay)和[OneWayToSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_OneWayToSource)绑定。 重申一下，哪些因素会导致源更新依赖于的值[UpdateSourceTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.updatesourcetrigger)属性，如中所述[触发源更新](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview#what_triggers_source_updates)部分。

下面描述了*验证*过程。 注意，只要在验证过程中发生验证错误或其他类型的错误，该过程就会中断。

1. 绑定引擎会检查是否有任何自定义[ValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule)对象定义其[ValidationStep](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule.validationstep)设置为[RawProposedValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationstep#System_Windows_Controls_ValidationStep_RawProposedValue)为该[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)，在这种情况下它将调用[Validate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule.validate)上每个方法[ValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule)到其中一个运行时遇到错误或直到全部规则都通过为止。
2. 绑定引擎随后会调用转换器（如果存在）。
3. 如果转换器成功，绑定引擎会检查是否有任何自定义[ValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule)对象定义其[ValidationStep](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule.validationstep)设置为[ConvertedProposedValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationstep#System_Windows_Controls_ValidationStep_ConvertedProposedValue)为该[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)，在这种情况下它将调用[Validate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule.validate)上每个方法[ValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule)具有[ValidationStep](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule.validationstep)设置为[ConvertedProposedValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationstep#System_Windows_Controls_ValidationStep_ConvertedProposedValue)直到其中一个运行一个规则出错或者全部规则都通过。
4. 绑定引擎设置源属性。
5. 绑定引擎会检查是否有任何自定义[ValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule)对象定义其[ValidationStep](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule.validationstep)设置为[UpdatedValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationstep#System_Windows_Controls_ValidationStep_UpdatedValue)为该[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)，在这种情况下它将调用[Validate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule.validate)上每个方法[ValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule)具有[ValidationStep](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule.validationstep)设置为[UpdatedValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationstep#System_Windows_Controls_ValidationStep_UpdatedValue)直到其中一个运行一个规则出错或者全部规则都通过。 如果[DataErrorValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dataerrorvalidationrule)与绑定相关联并将其[ValidationStep](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule.validationstep)设置为默认情况下， [UpdatedValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationstep#System_Windows_Controls_ValidationStep_UpdatedValue)，则[DataErrorValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dataerrorvalidationrule)此时检查。 这也是点时具有的绑定[ValidatesOnDataErrors](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.validatesondataerrors)设置为`true`检查。
6. 绑定引擎会检查是否有任何自定义[ValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule)对象定义其[ValidationStep](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule.validationstep)设置为[CommittedValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationstep#System_Windows_Controls_ValidationStep_CommittedValue)为该[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)，在这种情况下它将调用[Validate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule.validate)上每个方法[ValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule)具有[ValidationStep](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule.validationstep)设置为[CommittedValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationstep#System_Windows_Controls_ValidationStep_CommittedValue)直到其中一个运行一个规则出错或者全部规则都通过。

如果[ValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule)没有通过在此过程的任意时间，绑定引擎创建[ValidationError](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationerror)对象，并将其添加到[Errors](https://msdn.microsoft.com/library/system.windows.controls.validation.errors.aspx)的绑定元素集合。 之前绑定引擎在运行[ValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule)对象在任何给定的步骤，它会删除任何[ValidationError](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationerror)已添加到[Errors](https://msdn.microsoft.com/library/system.windows.controls.validation.errors.aspx)在该步骤附加属性的绑定元素。 例如，如果[ValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule)其[ValidationStep](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule.validationstep)设置为[UpdatedValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationstep#System_Windows_Controls_ValidationStep_UpdatedValue)失败下, 一次验证过程时，绑定引擎会移除该[ValidationError](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationerror)立即之前调用任意[ValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule)具有[ValidationStep](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule.validationstep)设置为[UpdatedValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationstep#System_Windows_Controls_ValidationStep_UpdatedValue).

当[Errors](https://msdn.microsoft.com/library/system.windows.controls.validation.errors.aspx)不为空，[HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror)元素的附加的属性设置为`true`。 此外，如果[NotifyOnValidationError](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.notifyonvalidationerror)的属性[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)设置为`true`，然后，绑定引擎会引发[Validation.Error](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation.error)附加在元素上的事件。

另请注意，在任一方向 （从目标到源或源到目标） 的有效值传输清除[Errors](https://msdn.microsoft.com/library/system.windows.controls.validation.errors.aspx)附加属性。

如果绑定具有[ExceptionValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.exceptionvalidationrule)与之关联，或具有[ValidatesOnExceptions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.validatesonexceptions)属性设置为`true`，绑定引擎设置源时，将引发异常，绑定引擎检查是否有[UpdateSourceExceptionFilter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.updatesourceexceptionfilter)。 可以选择使用[UpdateSourceExceptionFilter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.updatesourceexceptionfilter)回调以提供自定义处理程序处理异常。 如果[UpdateSourceExceptionFilter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.updatesourceexceptionfilter)中未指定[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)，绑定引擎就会创建[ValidationError](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationerror)与该异常并将其添加到[Errors](https://msdn.microsoft.com/library/system.windows.controls.validation.errors.aspx)的绑定元素集合。

#### 调试机制

可以设置附加的属性[TraceLevel](https://msdn.microsoft.com/library/system.diagnostics.presentationtracesources.tracelevel.aspx)上与绑定相关的对象，以接收特定绑定状态信息。

### [Binding Sources Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/binding-sources-overview)

在数据绑定中，绑定源对象是指用户从其获取数据的对象。 本主题讨论可用作绑定源的对象类型。

#### 绑定源类型

Windows Presentation Foundation (WPF) 数据绑定支持以下绑定源类型：

| 绑定源                                                       | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| 公共语言运行时 (CLR) 对象                                    | 可以绑定到任何 公共语言运行时 (CLR) 对象的公有属性、子属性以及索引器。 绑定引擎使用 CLR 反射来获取属性值。 或者，对象实现[ICustomTypeDescriptor](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.icustomtypedescriptor)或注册了[TypeDescriptionProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.typedescriptionprovider)也适用于绑定引擎。  有关如何实现可用作绑定源的类的详细信息，请参阅本主题后面的[为绑定源实现类](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/binding-sources-overview#classes)。 |
| 动态对象                                                     | 可以将绑定到可用的属性和实现的对象的索引器[IDynamicMetaObjectProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.dynamic.idynamicmetaobjectprovider)接口。 如果可以访问代码中的成员，则可以绑定到该成员。 例如，如果动态对象使用户可以通过 `someObjet.AProperty` 访问代码中的成员，则可以通过将绑定路径设置为 `AProperty` 来绑定到该成员。 |
| ADO.NET 对象                                                 | 可以将绑定到ADO.NET对象，如[DataTable](https://docs.microsoft.com/zh-cn/dotnet/api/system.data.datatable)。 ADO.NET [DataView](https://docs.microsoft.com/zh-cn/dotnet/api/system.data.dataview)实现[IBindingList](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.ibindinglist)接口，它提供了绑定引擎侦听的更改通知。 |
| XML 对象                                                     | 你可以将绑定到并运行`XPath`查询上的[XmlNode](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlnode)， [XmlDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmldocument)，或[XmlElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlelement)。 方便地访问XML标记中的绑定源的数据是使用[XmlDataProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.xmldataprovider)对象。 有关详细信息，请参阅[使用 XMLDataProvider 和 XPath 查询绑定到 XML 数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-bind-to-xml-data-using-an-xmldataprovider-and-xpath-queries)。  此外可以绑定到[XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)或[XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument)，或绑定到这些类型的对象上运行通过使用 LINQ to XML 查询的结果。 使用 LINQ to XML 访问 XML 数据的标记中的绑定源的简便方法是使用[ObjectDataProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.objectdataprovider)对象。 有关详细信息，请参阅[绑定到 XDocument、XElement 或 LINQ for XML 查询结果](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-bind-to-xdocument-xelement-or-linq-for-xml-query-results)。 |
| [DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)对象 | 可以绑定到的任何依赖关系属性[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)。 有关示例，请参阅[绑定两个控件的属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-bind-the-properties-of-two-controls)。 |

#### 为绑定源实现类

可以创建自己的绑定源。 本部分讨论在要实现用作绑定源的类时需要了解的内容。

#### 提供更改通知

如果正在使用[OneWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_OneWay)或[TwoWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_TwoWay)绑定 (因为您希望您UI更新绑定源属性动态更改时)，您必须实现适当的属性更改通知机制。 建议的机制是有关CLR或动态类，以实现[INotifyPropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.inotifypropertychanged)接口。 有关详细信息，请参阅[实现属性更改通知](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-implement-property-change-notification)。

如果您创建CLR对象，它不实现[INotifyPropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.inotifypropertychanged)，必须安排您自己的通知系统，以确保绑定中使用的数据保持最新。 可以通过支持要更改通知的每个属性的 `PropertyChanged` 模式来提供更改通知。 若要支持此模式，请为每个属性定义一个 *PropertyName*Changed 事件，其中 *PropertyName* 是属性的名称。 每次更改属性时都会引发该事件。

如果绑定源实现了其中一个通知机制，将会自动进行目标更新。 如果出于任何原因绑定源不提供正确的属性更改通知，可以选择要使用[UpdateTarget](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingexpression.updatetarget)方法来显式更新目标属性。

#### 其他特性

下表提供了需要注意的其他要点：

- 如果要在 XAML 中创建对象，类必须具有默认的构造函数。 在某些.NET语言，如C#，可能会为你创建的默认构造函数。
- 用作绑定的绑定源属性的属性必须为类的公共属性。 不能出于绑定目的来访问显式定义的接口属性，也不能访问没有基实现的受保护、私有、内部或虚拟属性。
- 不能绑定到公共字段。
- 类中声明的属性类型是传递给绑定的类型。 不过，绑定最终所用的类型取决于绑定目标属性的类型，而不是绑定源属性的类型。 如果类型不同，可能需要编写一个转换器来处理自定义属性最初传递给绑定的方式。 有关详细信息，请参阅 [IValueConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.ivalueconverter)。

#### 将整个对象用作绑定源

可以将整个对象用作绑定源。 可以通过使用指定绑定源[Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.source)或[DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext)属性，然后提供一个空白绑定声明： `{Binding}`。 适用的场景包括绑定到属于类型字符串的对象、绑定到具有感兴趣的多个属性的对象或绑定到集合对象。 有关绑定到整个集合对象的示例，请参阅[对分层数据使用主-从模式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-use-the-master-detail-pattern-with-hierarchical-data)。

请注意，可能需要应用自定义逻辑，以便数据对于绑定的目标属性有意义。 自定义逻辑可能采用自定义转换器形式 （如果尚不存在默认的类型转换） 或[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)。 有关转换器的详细信息，请参阅[数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview)的“数据转换”一节。 有关数据模板的详细信息，请参阅[数据模板化概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-templating-overview)。

#### 将集合对象用作绑定源

通常，要用作绑定源的对象是自定义对象的集合。 每个对象都用作重复绑定的一个实例的源。 例如，可能存在由 `CustomerOrder` 对象组成的 `CustomerOrders` 集合，其中应用程序会循环访问该集合以确定存在的订单数量，以及每个订单中的数据。

可以枚举实现任何集合[IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable)接口。 但是，若要设置动态绑定，以便插入或删除集合中的更新UI自动，该集合必须实现[INotifyCollectionChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.specialized.inotifycollectionchanged)接口。 此接口公开一个事件，只要基础集合发生更改，就必须引发该事件。

[ObservableCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.objectmodel.observablecollection-1)类是公开的数据集合的内置实现[INotifyCollectionChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.specialized.inotifycollectionchanged)接口。 集合中的个别数据对象必须满足前面章节中所述的要求。 有关示例，请参阅[创建和绑定到 ObservableCollection](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-create-and-bind-to-an-observablecollection)。 在实现自己的集合之前, 请考虑使用[ObservableCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.objectmodel.observablecollection-1)或一个现有集合类，如[List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1)， [Collection](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.objectmodel.collection-1)，和[BindingList](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.bindinglist-1)，此外还有许多其他。

WPF 从不直接绑定到集合。 如果指定集合作为绑定源，WPF 实际上会绑定到该集合的默认视图。 有关默认视图的信息，请参阅[数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview)。

如果有高级的方案，并且您想要实现自己的集合，请考虑使用[IList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ilist)接口。 [IList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ilist) 提供了可按照索引，这可以提高性能单独访问的对象的非泛型集合。

#### 数据绑定中的权限要求

当进行数据绑定时，必须考虑应用程序的信任级别。 下表总结了在完全信任或部分信任级别下执行的应用程序中可以绑定到的属性类型：

| 属性类型  （所有访问修饰符） | 动态对象属性 | 动态对象属性 | CLR 属性     | CLR 属性     | 依赖属性     | 依赖属性     |
| ---------------------------- | ------------ | ------------ | ------------ | ------------ | ------------ | ------------ |
| **信任级别**                 | **完全信任** | **部分信任** | **完全信任** | **部分信任** | **完全信任** | **部分信任** |
| 公共类                       | 是           | 是           | 是           | 是           | 是           | 是           |
| 非公共类                     | 是           | No           | 是           | No           | 是           | 是           |

此表描述了数据绑定中有关权限要求的以下要点：

- 对于 CLR 属性，只要绑定引擎能够使用反射访问绑定源属性，数据绑定就有效。 否则，绑定引擎会发出找不到属性的警告，并使用回退值或默认值（如果可用）。
- 可以绑定到在编译时或运行时定义的动态对象上的属性。
- 始终可以绑定到依赖属性。

XML 绑定的权限要求非常类似。 在部分信任沙盒中，[XmlDataProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.xmldataprovider)没有权限访问指定的数据时将失败。

具有匿名类型的对象是内部对象。 只有在完全信任级别下运行，才能绑定到匿名类型的属性。 有关匿名类型的详细信息，请参阅[匿名类型（C# 编程指南）](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/anonymous-types)或[匿名类型 (Visual Basic)](https://docs.microsoft.com/zh-cn/dotnet/visual-basic/programming-guide/language-features/objects-and-classes/anonymous-types) (Visual Basic)。

有关部分信任安全的详细信息，请参阅 [WPF 部分信任安全](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/wpf-partial-trust-security)。

### [Data Templating Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/data-templating-overview)

WPF 数据模板化模型为定义数据的表示提供了很大的灵活性。 WPF 控件具有支持自定义数据表示的内置功能。本主题首先演示如何定义[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)，然后介绍其他数据模板化功能，例如选择了模板基于自定义逻辑和显示分层数据的支持。

#### 系统必备

本主题重点介绍数据模板化功能，不介绍数据绑定概念。 有关基本数据绑定概念的信息，请参阅[数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview)。

[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate) 有关数据的表示形式，由 WPF 样式和模板化模型提供的众多功能之一。 有关 WPF 样式和模板化模型，例如，如何使用的介绍[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)若要设置控件的属性，请参阅[样式和模板化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/styling-and-templating)主题。

此外，务必了解`Resources`，这实质上是什么使对象，如[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)和[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)能够重复使用。 有关资源的详细信息，请参阅 [XAML 资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-resources)。

#### 数据模板化基础知识

为了演示原因[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)是重要的是，让我们看一下数据绑定示例。 在此示例中，我们有[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)绑定到一系列`Task`对象。 每个 `Task` 对象都有 `TaskName` (string)、`Description` (string)、`Priority` (int) 和 `TaskType` 类型的属性（它是一个 `Enum`，其值为 `Home` 和 `Work`）。

```xaml
<Window x:Class="SDKSample.Window1"
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  xmlns:local="clr-namespace:SDKSample"
  Title="Introduction to Data Templating Sample">
  <Window.Resources>
    <local:Tasks x:Key="myTodoList"/>
```

```xaml
</Window.Resources>
  <StackPanel>
    <TextBlock Name="blah" FontSize="20" Text="My Task List:"/>
    <ListBox Width="400" Margin="10"
             ItemsSource="{Binding Source={StaticResource myTodoList}}"/>
```

```xaml
  </StackPanel>
</Window>
```

##### 不提供 DataTemplate

无需[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)中，我们[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)当前如下所示：

![数据模板化示例屏幕快照](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/media/datatemplatingintro-fig1.png)

发生了什么情况是，如果没有任何特殊说明[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)默认调用`ToString`时尝试显示集合中的对象。 因此，如果`Task`对象重写`ToString`方法，则[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)显示基础集合中的每个源对象的字符串表示形式。

例如，如果 `Task` 类以这种方式重写 `ToString` 方法，其中 `name` 是 `TaskName` 属性的字段：

```csharp
public override string ToString()
{
    return name.ToString();
}
```

然后[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)如下所示：

![数据模板化示例屏幕快照](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/media/datatemplatingintro-fig2.png)

但是，这会受到限制且不灵活。 此外，如果要绑定到 XML 数据，将不能重写 `ToString`。

##### 定义简单的 DataTemplate

解决方法是定义[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)。 若要执行此操作的一种方法是设置[ItemTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemtemplate)的属性[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)到[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)。中指定你[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)变成数据对象的可视结构。 以下[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)相当简单。 我们将向每个项都显示为三个说明[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)中的元素[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)。 每个[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)元素绑定到的属性`Task`类。

```xaml
<ListBox Width="400" Margin="10"
         ItemsSource="{Binding Source={StaticResource myTodoList}}">
   <ListBox.ItemTemplate>
     <DataTemplate>
       <StackPanel>
         <TextBlock Text="{Binding Path=TaskName}" />
         <TextBlock Text="{Binding Path=Description}"/>
         <TextBlock Text="{Binding Path=Priority}"/>
       </StackPanel>
     </DataTemplate>
   </ListBox.ItemTemplate>
 </ListBox>
```

本主题中示例的基础数据是 CLR 对象的一个集合。 如果要绑定到 XML 数据，基本概念都相同，只不过语法稍微不同。 例如，而不是让`Path=TaskName`，则会将设置[XPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.xpath)到`@TaskName`(如果`TaskName`是一个属性的你XML节点)。

现在我们[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)如下所示：

![数据模板化示例屏幕快照](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/media/datatemplatingintro-fig3.png)



##### 将 DataTemplate 创建为资源

在上述示例中，我们定义了[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)内联。 常常在资源部分中定义它，以使其成为一个可重复使用的对象，如以下示例所示：

```xaml
<Window.Resources>
```

```xaml
<DataTemplate x:Key="myTaskTemplate">
  <StackPanel>
    <TextBlock Text="{Binding Path=TaskName}" />
    <TextBlock Text="{Binding Path=Description}"/>
    <TextBlock Text="{Binding Path=Priority}"/>
  </StackPanel>
</DataTemplate>
```

```xaml
</Window.Resources>
```

现在可以将 `myTaskTemplate` 用作资源，如以下示例所示：

```xaml
<ListBox Width="400" Margin="10"
         ItemsSource="{Binding Source={StaticResource myTodoList}}"
         ItemTemplate="{StaticResource myTaskTemplate}"/>
```

因为`myTaskTemplate`是一种资源，您可以具有一个属性，采用其他控件现在使用[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)类型。 如上所示，对于[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)对象，如[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)，它是[ItemTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemtemplate)属性。 有关[ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)对象，它是[ContentTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.contenttemplate)属性。

##### DataType 属性

[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)类具有[DataType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate.datatype)非常相似的属性[TargetType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style.targettype)属性的[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)类。 因此，而不是指定`x:Key`为[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)在上述示例中，可以执行以下：

```xaml
<DataTemplate DataType="{x:Type local:Task}">
  <StackPanel>
    <TextBlock Text="{Binding Path=TaskName}" />
    <TextBlock Text="{Binding Path=Description}"/>
    <TextBlock Text="{Binding Path=Priority}"/>
  </StackPanel>
</DataTemplate>
```

这[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)自动应用于所有`Task`对象。 请注意，在这种情况下，隐式设置 `x:Key`。 因此，如果你转让[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)`x:Key`值，你将重写的隐式`x:Key`和[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)不会自动应用。

如果要绑定[ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)的一系列`Task`对象，[ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)不会使用上述[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)自动。 这是因为在绑定[ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)需要更多信息才能区分是你想要将绑定到整个集合或单个对象。 如果你[ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)跟踪的所选内容[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)类型，可以设置[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.path)的属性[ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)绑定到"`/`"以指示你感兴趣的当前项。 有关示例，请参阅[绑定到集合并基于选择显示信息](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-bind-to-a-collection-and-display-information-based-on-selection)。 否则，你需要指定[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)显式通过设置[ContentTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.contenttemplate)属性。

[DataType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate.datatype)属性是特别有用，有时[CompositeCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.compositecollection)的不同类型的数据对象。 有关示例，请参阅[实现 CompositeCollection](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-implement-a-compositecollection)。

#### 向 DataTemplate 添加更多信息

当前，数据显示了必要信息，但还可以显示更多信息。 让我们通过添加改进演示文稿[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)、 一个[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)，和一些[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)描述要显示的数据的元素。

```xaml
<DataTemplate x:Key="myTaskTemplate">
  <Border Name="border" BorderBrush="Aqua" BorderThickness="1"
          Padding="5" Margin="5">
    <Grid>
      <Grid.RowDefinitions>
        <RowDefinition/>
        <RowDefinition/>
        <RowDefinition/>
      </Grid.RowDefinitions>
      <Grid.ColumnDefinitions>
        <ColumnDefinition />
        <ColumnDefinition />
      </Grid.ColumnDefinitions>
      <TextBlock Grid.Row="0" Grid.Column="0" Text="Task Name:"/>
      <TextBlock Grid.Row="0" Grid.Column="1" Text="{Binding Path=TaskName}" />
      <TextBlock Grid.Row="1" Grid.Column="0" Text="Description:"/>
      <TextBlock Grid.Row="1" Grid.Column="1" Text="{Binding Path=Description}"/>
      <TextBlock Grid.Row="2" Grid.Column="0" Text="Priority:"/>
      <TextBlock Grid.Row="2" Grid.Column="1" Text="{Binding Path=Priority}"/>
    </Grid>
  </Border>
```

```xaml
</DataTemplate>
```

以下屏幕截图显示[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)与此修改[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate):

![数据模板化示例屏幕快照](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/media/datatemplatingintro-fig4.png)

我们可以设置[HorizontalContentAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.horizontalcontentalignment)到[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.horizontalalignment#System_Windows_HorizontalAlignment_Stretch)上[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)以确保项的宽度占据整个空间：

```xaml
<ListBox Width="400" Margin="10"
     ItemsSource="{Binding Source={StaticResource myTodoList}}"
     ItemTemplate="{StaticResource myTaskTemplate}" 
     HorizontalContentAlignment="Stretch"/>
```

与[HorizontalContentAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.horizontalcontentalignment)属性设置为[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.horizontalalignment#System_Windows_HorizontalAlignment_Stretch)，则[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)现在如下所示：

![数据模板化示例屏幕快照](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/media/datatemplatingintro-fig5.png)

##### 使用 DataTriggers 应用属性值

当前表示形式并未指出 `Task` 是家庭任务还是办公室任务。 请记住，`Task` 对象具有类型为 `TaskType` 的 `TaskType` 属性（该属性是一个枚举，其值为 `Home` 和 `Work`）。

在以下示例中，[DataTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatrigger)设置[BorderBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border.borderbrush)的名为的元素`border`到`Yellow`如果`TaskType`属性是`TaskType.Home`。

```xaml
<DataTemplate x:Key="myTaskTemplate">
```

```xaml
<DataTemplate.Triggers>
  <DataTrigger Binding="{Binding Path=TaskType}">
    <DataTrigger.Value>
      <local:TaskType>Home</local:TaskType>
    </DataTrigger.Value>
    <Setter TargetName="border" Property="BorderBrush" Value="Yellow"/>
  </DataTrigger>
</DataTemplate.Triggers>
```

```xaml
</DataTemplate>
```

应用程序现在如下所示。 家庭任务的边界显示为黄色，办公室任务的边界显示为浅绿色：

![数据模板化示例屏幕快照](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/media/datatemplatingintro-fig6.png)

在此示例中[DataTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatrigger)使用[Setter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.setter)设置属性值。 触发器类还具有[EnterActions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.triggerbase.enteractions)和[ExitActions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.triggerbase.exitactions)，你可以启动一系列操作，例如动画的属性。 此外，还有[MultiDataTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.multidatatrigger)类，该类允许您将更改应用根据多个数据绑定属性值。

若要达到同样的效果的替代方法是将绑定[BorderBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border.borderbrush)属性设置为`TaskType`属性，然后使用值转换器来返回颜色基于`TaskType`值。 就性能而言，使用转换器实现上述效果的效率要高一些。 另外，创建自己的转换器可以提供更多灵活性，因为提供了自己的逻辑。 最后，选择使用何种技术取决于当时的具体情况和偏好。 有关如何编写转换器的信息，请参阅[IValueConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.ivalueconverter)。

##### DataTemplate 中有哪些内容？

在上一示例中，我们将触发器放入[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)使用[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)。[Triggers](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate.triggers) 属性。 [Setter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.setter)触发器的设置的元素的属性的值 ([Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)元素)，位于[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)。 但是，如果属性，你`Setters`关心的不是在当前元素的属性[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)，它可能更适合于以设置使用的属性[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)，它针对[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)类 (如果要绑定的控件是[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox))。 例如，如果你想你[Trigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.trigger)进行动画处理[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)值的项时鼠标指向一个项，定义内的触发器[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)样式。 有关示例，请参阅[样式设置和模板化示例简介](https://github.com/Microsoft/WPF-Samples/tree/master/Styles%20&%20Templates/IntroToStylingAndTemplating)。

一般情况下，请记住[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)要应用于所生成的每个[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)(有关如何以及在何处，它实际应用的详细信息，请参阅[ItemTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemtemplate)页。)。 你[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)关心的演示文稿和数据对象的外观。 在大多数情况下，所有其他方面的演示文稿，例如，某项看起来像选择此项时或如何[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)的定义不属于排列项， [DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)。 有关示例，请参阅[对 ItemsControl 进行样式设置和模板化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-templating-overview#DataTemplating_ItemsControl)一节。

#### 根据数据对象的属性选择 DataTemplate

在 [DataType 属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-templating-overview#Styling_DataType)一节中，我们讨论了可为不同的数据对象定义不同的数据模板。 是特别有用，有时[CompositeCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.compositecollection)的不同类型或具有不同类型的项的集合。 在中[使用 Datatrigger 应用属性值](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-templating-overview#DataTrigger_to_Apply_Property_Values)部分中，我们已经演示，是否有一个相同类型的数据对象的集合可以创建[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)，然后使用触发器以应用更改的属性值为基础的每个数据对象。 虽然触发器允许你应用属性值或启动动画，但是它们无法让你灵活地重构数据对象的结构。 某些情况下，可能需要创建不同[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)数据属于相同的对象类型，但具有不同的属性。

例如，当 `Task` 对象的 `Priority` 值为 `1` 时，可能需要为它指定完全不同的外观，以给予你自己一个提醒。 在这种情况下，创建[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)高优先级的显示器`Task`对象。 让我们将以下代码添加[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)到资源部分：

```xaml
<DataTemplate x:Key="importantTaskTemplate">
  <DataTemplate.Resources>
    <Style TargetType="TextBlock">
      <Setter Property="FontSize" Value="20"/>
    </Style>
  </DataTemplate.Resources>
  <Border Name="border" BorderBrush="Red" BorderThickness="1"
          Padding="5" Margin="5">
    <DockPanel HorizontalAlignment="Center">
      <TextBlock Text="{Binding Path=Description}" />
      <TextBlock>!</TextBlock>
    </DockPanel>
  </Border>
</DataTemplate>
```

请注意，此示例使用[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)。[Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworktemplate.resources) 属性。 资源定义中共享该部分中的元素[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)。

若要提供逻辑来选择哪些[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)使用基于`Priority`值的数据对象中，创建一个子类[DataTemplateSelector](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datatemplateselector)并重写[SelectTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datatemplateselector.selecttemplate)方法。 在以下示例中，[SelectTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datatemplateselector.selecttemplate)方法提供逻辑以返回相应的模板值的基础`Priority`属性。 封装的资源中找到要返回的模板[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)元素。

```csharp
using System.Windows;
using System.Windows.Controls;

namespace SDKSample
{
    public class TaskListDataTemplateSelector : DataTemplateSelector
    {
        public override DataTemplate
            SelectTemplate(object item, DependencyObject container)
        {
            FrameworkElement element = container as FrameworkElement;

            if (element != null && item != null && item is Task)
            {
                Task taskitem = item as Task;

                if (taskitem.Priority == 1)
                    return
                        element.FindResource("importantTaskTemplate") as DataTemplate;
                else
                    return
                        element.FindResource("myTaskTemplate") as DataTemplate;
            }

            return null;
        }
    }
}
```

然后，我们可以将 `TaskListDataTemplateSelector` 声明为资源：

```xaml
<Window.Resources>
```

```xaml
<local:TaskListDataTemplateSelector x:Key="myDataTemplateSelector"/>
```

```xaml
</Window.Resources>
```

若要使用的模板选择器资源，将其分配给[ItemTemplateSelector](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemtemplateselector)属性的[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)。 [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)调用[SelectTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datatemplateselector.selecttemplate)方法的`TaskListDataTemplateSelector`为每个基础集合中的项。 该调用会将数据对象作为项参数传递。 [DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)返回该方法然后应用于该数据对象。

```xaml
<ListBox Width="400" Margin="10"
         ItemsSource="{Binding Source={StaticResource myTodoList}}"
         ItemTemplateSelector="{StaticResource myDataTemplateSelector}"
         HorizontalContentAlignment="Stretch"/>
```

使用模板选择器后，[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)现在显示，如下所示：

![数据模板化示例屏幕快照](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/media/datatemplatingintro-fig7.png)

这正是此示例要得到的结果。 有关完整示例，请参阅[数据模板化示例简介](https://github.com/Microsoft/WPF-Samples/tree/master/Data%20Binding/DataTemplatingIntro)。

#### 对 ItemsControl 进行样式设置和模板化

即使[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)不是可以使用的唯一控件类型[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)，它是要绑定的情况很常见[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)到集合。 在[哪些内容属于 DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-templating-overview#what_belongs_in_datatemplate)我们讨论过的部分的定义在[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)只应关心数据的表示形式。 若要了解何时不适合用于[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)务必要了解提供的不同样式和模板属性[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)。 以下示例旨在演示上述每个属性的功能。 [ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)在此示例绑定到相同`Tasks`如前面的示例中所示的集合。 为便于演示，本示例中的样式和模板都进行了内联声明。

```xaml
<ItemsControl Margin="10"
              ItemsSource="{Binding Source={StaticResource myTodoList}}">
  <!--The ItemsControl has no default visual appearance.
      Use the Template property to specify a ControlTemplate to define
      the appearance of an ItemsControl. The ItemsPresenter uses the specified
      ItemsPanelTemplate (see below) to layout the items. If an
      ItemsPanelTemplate is not specified, the default is used. (For ItemsControl,
      the default is an ItemsPanelTemplate that specifies a StackPanel.-->
  <ItemsControl.Template>
    <ControlTemplate TargetType="ItemsControl">
      <Border BorderBrush="Aqua" BorderThickness="1" CornerRadius="15">
        <ItemsPresenter/>
      </Border>
    </ControlTemplate>
  </ItemsControl.Template>
  <!--Use the ItemsPanel property to specify an ItemsPanelTemplate
      that defines the panel that is used to hold the generated items.
      In other words, use this property if you want to affect
      how the items are laid out.-->
  <ItemsControl.ItemsPanel>
    <ItemsPanelTemplate>
      <WrapPanel />
    </ItemsPanelTemplate>
  </ItemsControl.ItemsPanel>
  <!--Use the ItemTemplate to set a DataTemplate to define
      the visualization of the data objects. This DataTemplate
      specifies that each data object appears with the Proriity
      and TaskName on top of a silver ellipse.-->
  <ItemsControl.ItemTemplate>
    <DataTemplate>
      <DataTemplate.Resources>
        <Style TargetType="TextBlock">
          <Setter Property="FontSize" Value="18"/>
          <Setter Property="HorizontalAlignment" Value="Center"/>
        </Style>
      </DataTemplate.Resources>
      <Grid>
        <Ellipse Fill="Silver"/>
        <StackPanel>
          <TextBlock Margin="3,3,3,0"
                     Text="{Binding Path=Priority}"/>
          <TextBlock Margin="3,0,3,7"
                     Text="{Binding Path=TaskName}"/>
        </StackPanel>
      </Grid>
    </DataTemplate>
  </ItemsControl.ItemTemplate>
  <!--Use the ItemContainerStyle property to specify the appearance
      of the element that contains the data. This ItemContainerStyle
      gives each item container a margin and a width. There is also
      a trigger that sets a tooltip that shows the description of
      the data object when the mouse hovers over the item container.-->
  <ItemsControl.ItemContainerStyle>
    <Style>
      <Setter Property="Control.Width" Value="100"/>
      <Setter Property="Control.Margin" Value="5"/>
      <Style.Triggers>
        <Trigger Property="Control.IsMouseOver" Value="True">
          <Setter Property="Control.ToolTip"
                  Value="{Binding RelativeSource={x:Static RelativeSource.Self},
                          Path=Content.Description}"/>
        </Trigger>
      </Style.Triggers>
    </Style>
  </ItemsControl.ItemContainerStyle>
</ItemsControl>
```

下面是该示例在呈现时的屏幕快照：

![ItemsControl 示例屏幕快照](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/media/databinding-itemscontrolproperties.png)

请注意，而不是使用[ItemTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemtemplate)，可以使用[ItemTemplateSelector](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemtemplateselector)。 请参考上一节中的示例。 同样，而不是使用[ItemContainerStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemcontainerstyle)，可以选择使用[ItemContainerStyleSelector](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemcontainerstyleselector)。

两个其他样式相关的属性[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)，不会显示如下[GroupStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.groupstyle)和[GroupStyleSelector](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.groupstyleselector)。

#### 对分层数据的支持

到目前为止，我们仅讨论了如何绑定到并显示单个集合。 某些时候，具有的集合包含其他集合。[HierarchicalDataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.hierarchicaldatatemplate)类旨在用于[HeaderedItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headereditemscontrol)要显示此类数据类型。 在以下示例中，`ListLeagueList` 是 `League` 对象的列表。 每个 `League` 对象都有一个 `Name` 和 `Division` 对象的集合。 每个 `Division` 都有一个 `Name` 和 `Team` 对象的集合，并且每个 `Team` 对象都有一个 `Name`。

```xaml
<Window x:Class="SDKSample.Window1"
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  Title="HierarchicalDataTemplate Sample"
  xmlns:src="clr-namespace:SDKSample">
  <DockPanel>
    <DockPanel.Resources>
      <src:ListLeagueList x:Key="MyList"/>

      <HierarchicalDataTemplate DataType    = "{x:Type src:League}"
                                ItemsSource = "{Binding Path=Divisions}">
        <TextBlock Text="{Binding Path=Name}"/>
      </HierarchicalDataTemplate>

      <HierarchicalDataTemplate DataType    = "{x:Type src:Division}"
                                ItemsSource = "{Binding Path=Teams}">
        <TextBlock Text="{Binding Path=Name}"/>
      </HierarchicalDataTemplate>

      <DataTemplate DataType="{x:Type src:Team}">
        <TextBlock Text="{Binding Path=Name}"/>
      </DataTemplate>
    </DockPanel.Resources>

    <Menu Name="menu1" DockPanel.Dock="Top" Margin="10,10,10,10">
        <MenuItem Header="My Soccer Leagues"
                  ItemsSource="{Binding Source={StaticResource MyList}}" />
    </Menu>

    <TreeView>
      <TreeViewItem ItemsSource="{Binding Source={StaticResource MyList}}" Header="My Soccer Leagues" />
    </TreeView>

  </DockPanel>
</Window>
```

该示例表明，与使用[HierarchicalDataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.hierarchicaldatatemplate)，可以轻松地显示包含其他列表的列表数据。 下面是该示例的一个屏幕快照。

![HierarchicalDataTemplate 示例屏幕快照](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/media/databinding-hierarchicaldatatemplate.png)

### [Binding Declarations Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/binding-declarations-overview)

本主题讨论声明绑定的不同方法。

#### 系统必备

在阅读本主题之前，请务必熟悉标记扩展的概念和使用。 有关标记扩展的详细信息，请参阅[标记扩展和 WPF XAML](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/markup-extensions-and-wpf-xaml)。

本主题未涉及数据绑定概念。 有关数据绑定概念的讨论，请参阅[数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview)。

#### 在 XAML 中声明绑定

本部分介绍如何在 XAML 中声明绑定。

##### 标记扩展使用

[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding) 是标记扩展。 使用绑定扩展声明绑定时，声明包含一系列子句，这些子句跟在 `Binding` 关键字后面，并由逗号 (,) 分隔。 绑定声明中的子句可以按任意顺序排列，有多种可能的组合。 这些子句都是*名称*=*值*对，其中*名称*的名称[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)属性和*值*是要设置的属性值。

在标记中创建绑定声明字符串时，必须将这些字符串附加到目标对象的特定依赖属性。 下面的示例演示如何将绑定[TextBox.Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.text)属性使用的绑定扩展，指定[Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.source)和[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.path)属性。

```xaml
<TextBlock Text="{Binding Source={StaticResource myDataSource}, Path=PersonName}"/>
```

您可以指定的属性中的大多数[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)类这种方式。 有关绑定扩展以及的一些详细信息[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)不能使用绑定扩展设置的属性，请查看[绑定标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/binding-markup-extension)概述。

##### 对象元素语法

对象元素语法是创建绑定声明的替代方法。 在大多数情况下，使用标记扩展或对象元素语法没有特定的优势。 不过，如果标记扩展不支持你的方案，例如，当属性值是不存在任何类型转换的非字符串类型时，需要使用对象元素语法。

下面是对象元素语法和标记扩展使用的示例：

```xaml
<TextBlock Name="myconvertedtext"
  Foreground="{Binding Path=TheDate,
                       Converter={StaticResource MyConverterReference}}">
  <TextBlock.Text>
    <Binding Path="TheDate"
             Converter="{StaticResource MyConverterReference}"/>
  </TextBlock.Text>
</TextBlock>
```

该示例将绑定[Foreground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.foreground)通过声明使用扩展语法绑定的属性。 绑定声明[Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.text)属性使用对象元素语法。

有关其他术语的详细信息，请参阅 [XAML 语法详述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-syntax-in-detail)。



##### MultiBinding 和 PriorityBinding

[MultiBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.multibinding) 和[PriorityBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.prioritybinding)不支持 XAML 扩展语法。 因此，必须使用对象元素语法，如果要声明[MultiBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.multibinding)或[PriorityBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.prioritybinding)在 XAML 中。

#### 在代码中创建绑定

若要指定绑定的另一种方法是直接设置属性[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)在代码中的对象。 下面的示例演示如何创建[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)对象，并在代码中指定的属性。 在此示例中，`TheConverter`是一个对象，实现[IValueConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.ivalueconverter)接口。

```csharp
private void OnPageLoaded(object sender, EventArgs e)
{
    // Make a new source, to grab a new timestamp
    MyData myChangedData = new MyData();
    
    // Create a new binding
    // TheDate is a property of type DateTime on MyData class
    Binding myNewBindDef = new Binding("TheDate");
    
    myNewBindDef.Mode = BindingMode.OneWay;
    myNewBindDef.Source = myChangedData;
    myNewBindDef.Converter = TheConverter;
    myNewBindDef.ConverterCulture = new CultureInfo("en-US");
    
      // myDatetext is a TextBlock object that is the binding target object
    BindingOperations.SetBinding(myDateText, TextBlock.TextProperty, myNewBindDef);
    BindingOperations.SetBinding(myDateText, TextBlock.ForegroundProperty, myNewBindDef);

    lbChooseCulture.SelectedIndex = 0;
}
```

要绑定的对象是否[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)或[FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement)可以调用`SetBinding`方法，而使用不是直接[BindingOperations.SetBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingoperations.setbinding)。 有关示例，请参阅[在代码中创建绑定](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-create-a-binding-in-code)。



#### 绑定路径语法

使用[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.path)属性来指定你想要将绑定到的源值：

- 在最简单的情况下，[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.path)属性值是要使用的绑定，如下所示的源对象的属性名称`Path=PropertyName`。
- 可以通过类似语法中指定属性的属性子C#。 例如，子句 `Path=ShoppingCart.Order` 设置与对象或属性 `ShoppingCart` 的子属性 `Order` 的绑定。
- 若要绑定到附加属性，请将附加属性置于括号中。 例如，若要将绑定到附加属性[DockPanel.Dock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel.dock)的语法是`Path=(DockPanel.Dock)`。
- 可以在已应用索引器的属性名后面的方括号内指定属性的索引器。 例如，子句 `Path=ShoppingCart[0]` 将绑定设置为与属性的内部索引处理文本字符串“0”的方式对应的索引。 还支持嵌套索引器。
- 可以在 `Path` 子句中混用索引器和子属性，例如 `Path=ShoppingCart.ShippingInfo[MailingAddress,Street].`
- 可以在索引器内使用多个由逗号 (,) 分隔的索引器参数。 可以使用括号指定每个参数的类型。 例如，可以使用 `Path="[(sys:Int32)42,(sys:Int32)24]"`，其中 `sys` 将映射到 `System` 命名空间。
- 如果源是集合视图，则可以使用斜杠 (/) 指定当前项。 例如，子句 `Path=/` 设置与视图中当前项的绑定。 如果源是集合，则此语法指定默认集合视图的当前项。
- 可以组合使用属性名和斜杠，以遍历作为集合的属性。 例如，`Path=/Offices/ManagerName` 指定源集合的当前项，源集合中包含的 `Offices` 属性也是一个集合。 它的当前项是一个包含 `ManagerName` 属性的对象。
- 句点 (.) 路径也可以用于绑定到当前源。 例如，`Text="{Binding}"` 与 `Text="{Binding Path=.}"` 等效。

##### 转义机制

- 在索引器 ([ ]) 内部，脱字符号 (^) 用于对下一个字符进行转义。
- 如果您设置[Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.path)在 XAML，您还需要转义 （使用 XML 实体） 对 XML 语言定义的某些字符：
  - 使用 `&` 对字符“&”进行转义。
  - 使用 `>` 对结束标记“>”进行转义。
- 此外，如果在属性中使用标记扩展语法描述整个绑定，需要（使用反斜杠 \）对 WPF 标记扩展分析器专用的字符进行转义：
  - 反斜杠 (\) 本身是转义字符。
  - 等号 (=) 将属性名与属性值分隔开。
  - 逗号 (,) 用于分隔属性。
  - 右大括号 (}) 是标记扩展的结尾。

#### 默认行为

如果未在声明中指定默认行为，则默认行为如下所示。

- 创建一个默认转换器，尝试在绑定源值和绑定目标值之间执行类型转换。 如果不能进行转换，默认转换器会返回 `null`。
- 如果未设置[ConverterCulture](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.converterculture)，则绑定引擎使用`Language`绑定目标对象的属性。 在 XAML 中，此属性默认为“en-US”，如果已显式设置了一个值，则从页面的根元素（或任何元素）继承该值。
- 只要绑定已有的数据上下文 （例如，继承的数据上下文来自父元素），并且任何项或集合所返回的该上下文仅适用于绑定而无需进一步修改路径，绑定声明可以在所有具有任何子句：`{Binding}` 这通常是一个绑定指定为数据样式，其中该绑定作用于集合的方式。 有关详细信息，请参阅[绑定源概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/binding-sources-overview)中的“整个对象用作绑定源”一节。
- 默认值[Mode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.mode)单向和双向，具体取决于要绑定的依赖关系属性而异。 始终可以显式声明绑定模式，以确保绑定具有所需行为。 一般而言，用户可编辑的控件属性，如[TextBox.Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.text)和[RangeBase.Value](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.rangebase.value)，默认为双向绑定，而其他大多数属性默认为单向绑定。
- 默认值[UpdateSourceTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.updatesourcetrigger)值之间变化[PropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.updatesourcetrigger#System_Windows_Data_UpdateSourceTrigger_PropertyChanged)和[LostFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.updatesourcetrigger#System_Windows_Data_UpdateSourceTrigger_LostFocus)具体取决于绑定的依赖属性。 大多数依赖属性的默认值为 [PropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.updatesourcetrigger#System_Windows_Data_UpdateSourceTrigger_PropertyChanged)，而 [TextBox.Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.text) 属性的默认值为 [LostFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.updatesourcetrigger#System_Windows_Data_UpdateSourceTrigger_LostFocus)。

### [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/data-binding-how-to-topics)

本部分中的主题介绍如何使用数据绑定来从各种数据源在公共语言运行时 (CLR) 对象和 XML 的形式将元素绑定到数据。

#### 本节内容

[创建简单绑定](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-create-a-simple-binding)
[指定绑定源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-specify-the-binding-source)
[让数据可供 XAML 中的绑定使用](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-make-data-available-for-binding-in-xaml)
[控制文本框文本更新源的时间](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-control-when-the-textbox-text-updates-the-source)
[指定绑定方向](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-specify-the-direction-of-the-binding)
[绑定到集合并根据选择的内容显示信息](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-bind-to-a-collection-and-display-information-based-on-selection)
[绑定到枚举](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-bind-to-an-enumeration)
[绑定两个控件的属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-bind-the-properties-of-two-controls)
[实现绑定验证](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-implement-binding-validation)
[在自定义对象上实现验证逻辑](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-implement-validation-logic-on-custom-objects)
[从已绑定的目标属性获取绑定对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-get-the-binding-object-from-a-bound-target-property)
[实现 CompositeCollection](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-implement-a-compositecollection)
[转换已绑定的数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-convert-bound-data)
[在代码中创建绑定](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-create-a-binding-in-code)
[获取数据集合的默认视图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-get-the-default-view-of-a-data-collection)
[在数据集合视图中浏览对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-navigate-through-the-objects-in-a-data-collectionview)
[在视图中筛选数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-filter-data-in-a-view)
[在视图中对数据进行排序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-sort-data-in-a-view)
[在 XAML 中使用视图对数据进行排序和分组](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-sort-and-group-data-using-a-view-in-xaml)
[将主-详细模式与分层数据结合使用](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-use-the-master-detail-pattern-with-hierarchical-data)
[将主-详细模式与分层 XML 数据结合使用](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-use-the-master-detail-pattern-with-hierarchical-xml-data)
[根据已绑定项的列表生成值](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-produce-a-value-based-on-a-list-of-bound-items)
[实现属性更改通知](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-implement-property-change-notification)
[创建和绑定到 ObservableCollection](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-create-and-bind-to-an-observablecollection)
[实现 PriorityBinding](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-implement-prioritybinding)
[使用 XMLDataProvider 和 XPath 查询绑定到 XML 数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-bind-to-xml-data-using-an-xmldataprovider-and-xpath-queries)
[绑定到 XDocument、XElement 或 LINQ to XML 查询结果](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-bind-to-xdocument-xelement-or-linq-for-xml-query-results)
[在数据绑定中使用 XML 命名空间](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-use-xml-namespaces-in-data-binding)
[绑定到 ADO.NET 数据源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-bind-to-an-ado-net-data-source)
[绑定到方法](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-bind-to-a-method)
[设置绑定更新通知](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-set-up-notification-of-binding-updates)
[清除绑定](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-clear-bindings)
[查找由 DataTemplate 生成的元素](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-find-datatemplate-generated-elements)
[绑定到 Web 服务](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-bind-to-a-web-service)
[绑定到 LINQ 查询结果](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-bind-to-the-results-of-a-linq-query)

#### [Create a Simple Binding](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-create-a-simple-binding)

此示例演示如何创建一个简单[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)。

##### 示例

此示例中有一个 `Person` 对象，该对象具有名为 `PersonName` 的字符串属性。 该 `Person` 对象在名为 `SDKSample`的命名空间中定义。

在下面的示例中，突出显示的包含 `<src>` 元素的行将实例化 `Person` 对象，该对象的 `PersonName` 属性值为 `Joe`。 该操作在 `Resources` 部分完成，并指定了 `x:Key`。

```xaml
<Window
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  xmlns:src="clr-namespace:SDKSample"
  SizeToContent="WidthAndHeight"
  Title="Simple Data Binding Sample">

  <Window.Resources>
    <src:Person x:Key="myDataSource" PersonName="Joe"/>
    <Style TargetType="{x:Type Label}">
      <Setter Property="DockPanel.Dock" Value="Top"/>
      <Setter Property="FontSize" Value="12"/>
    </Style>
    <Style TargetType="{x:Type TextBox}">
      <Setter Property="Width" Value="100"/>
      <Setter Property="Height" Value="25"/>
      <Setter Property="DockPanel.Dock" Value="Top"/>
    </Style>
    <Style TargetType="{x:Type TextBlock}">
      <Setter Property="Width" Value="100"/>
      <Setter Property="Height" Value="25"/>
      <Setter Property="DockPanel.Dock" Value="Top"/>
      <Setter Property="Padding" Value="3"/>
    </Style>
  </Window.Resources>
  <Border Margin="5" BorderBrush="Aqua" BorderThickness="1" Padding="8" CornerRadius="3">
    <DockPanel Width="200" Height="100" Margin="35">
      <Label>Enter a Name:</Label>
      <TextBox>
        <TextBox.Text>
          <Binding Source="{StaticResource myDataSource}" Path="PersonName"
                   UpdateSourceTrigger="PropertyChanged"/>
        </TextBox.Text>
      </TextBox>
      
      <Label>The name you entered:</Label>
      <TextBlock Text="{Binding Source={StaticResource myDataSource}, Path=PersonName}"/>
    </DockPanel>
  </Border>
</Window>
```

然后，突出显示的包含 `<TextBlock>` 元素的行会将 [TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock) 控件绑定到 `PersonName` 属性。 这样，[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock) 显示的值将为 “Joe”。

#### [Specify the Binding Source](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-specify-the-binding-source)

在数据绑定中，绑定源对象是指从其获取数据的对象。 本主题描述了指定绑定源的不同方法。

##### 示例

如果要将几个属性绑定到一个通用源，则需要使用 `DataContext` 属性，它能让你方便地建立一个范围，所有数据绑定的属性都在该范围中继承通用源。

在下面的示例中，数据上下文建立在应用程序的根元素上。 这允许所有子元素继承该数据上下文。 绑定的数据来自自定义数据类 `NetIncome`，可通过映射直接引用该类，已为该类分配了 `incomeDataSource` 资源键。

```xaml
<Grid
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  x:Class="SDKSample.DirectionalBinding"
  xmlns:c="clr-namespace:SDKSample"
  Name="Page1"
>
  <Grid.Resources>
    <c:NetIncome x:Key="incomeDataSource"/>
    <Style TargetType="{x:Type TextBlock}">
      <Setter Property="Padding" Value="8"/>
    </Style>
    <Style TargetType="{x:Type TextBox}">
      <Setter Property="Margin" Value="0,6,0,0"/>
    </Style>
  </Grid.Resources>
  <Grid.DataContext>
    <Binding Source="{StaticResource incomeDataSource}"/>
  </Grid.DataContext>
```

```xaml
</Grid>
```

下面的示例展示了 `NetIncome` 类的定义。

```csharp
public class NetIncome : INotifyPropertyChanged
{
    private int totalIncome = 5000;
    private int rent = 2000;
    private int food = 0;
    private int misc = 0;
    private int savings = 0;
    public NetIncome()
    {
        savings = totalIncome - (rent+food+misc);
    }

    public int TotalIncome
    {
        get
        {
            return totalIncome;
        }
        set
        {
            if( TotalIncome != value)
            {
                totalIncome = value;
                OnPropertyChanged("TotalIncome");
            }
        }
    }
    public int Rent
    {
        get
        {
            return rent;
        }
        set
        {
            if( Rent != value)
            {
                rent = value;
                OnPropertyChanged("Rent");
                UpdateSavings();
            }
        }
    }
    public int Food
    {
        get
        {
            return food;
        }
        set
        {
            if( Food != value)
            {
                food = value;
                OnPropertyChanged("Food");
                UpdateSavings();
            }
        }
    }
    public int Misc
    {
        get
        {
            return misc;
        }
        set
        {
            if( Misc != value)
            {
                misc = value;
                OnPropertyChanged("Misc");
                UpdateSavings();
            }
        }
    }
    public int Savings
    {
        get
        {
            return savings;
        }
        set
        {
            if( Savings != value)
            {
                savings = value;
                OnPropertyChanged("Savings");
                UpdateSavings();
            }
        }
    }

    private void UpdateSavings()
    {
        Savings = TotalIncome - (Rent+Misc+Food);
        if(Savings < 0)
        {}
        else if(Savings >= 0)
        {}
    }
    public event PropertyChangedEventHandler PropertyChanged;
    private void OnPropertyChanged(String info)
    {
        PropertyChangedEventHandler handler = PropertyChanged;
        if (handler !=null)
        {
            handler(this, new PropertyChangedEventArgs(info));
        }
    }
}
```

> 以上示例实例化标记中的对象，并将其用作资源。 如果希望绑定到已在代码中实例化的对象，需要通过编程方式设置 `DataContext` 属性。 有关示例，请参阅[使数据可用于 XAML 中的绑定](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-make-data-available-for-binding-in-xaml)。

另外，如果希望在个别绑定上显式指定源，可以选择以下选项。 这些选项优先于继承的数据上下文。

| 属性                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.source) | 使用此属性将源设置为对象的实例。 如果不需要特定功能（用于建立其中有多个属性继承相同的数据上下文的作用域），则可以使用 [Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.source) 属性而不是 `DataContext` 属性。 有关详细信息，请参阅[Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.source)。 |
| [RelativeSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.relativesource) | 当希望指定相对于绑定目标位置的源时，这很有用。 当想要将元素的一个属性绑定到同一元素的另一个属性时，或者如果要在样式或模板中定义绑定，则可能需要使用此属性。 有关详细信息，请参阅[RelativeSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.relativesource)。 |
| [ElementName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.elementname) | 指定一个字符串，用于表示你希望绑定到的元素。 当希望绑定到应用程序上另一个元素的属性时，这很有用。 例如，想用 [Slider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider) 来控制应用程序中另一个控件的高度，或想将控件的 [Content](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.content) 绑定到 [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 控件的 [SelectedValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.selector.selectedvalue)属性。 有关详细信息，请参阅 [ElementName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.elementname)。 |

#### [Make Data Available for Binding in XAML](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-make-data-available-for-binding-in-xaml)

本主题讨论使数据可用于 可扩展应用程序标记语言 (XAML) 绑定的各种方法，取决于应用程序的需求。

##### 示例

如果想通过 XAML 绑定到某个公共语言运行时 (CLR) 对象，使该对象可用于绑定的一种方法是将其定义为资源并为其提供 `x:Key`。 以下示例中提供一个`Person`对象，它具有名为 `PersonName` 的字符串属性。 `Person`对象 (在突出显示且包含 `<src>` 元素的行中) 在名为 `SDKSample` 的命名空间中定义。

```xaml
<Window
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  xmlns:src="clr-namespace:SDKSample"
  SizeToContent="WidthAndHeight"
  Title="Simple Data Binding Sample">

  <Window.Resources>
    <src:Person x:Key="myDataSource" PersonName="Joe"/>
    <Style TargetType="{x:Type Label}">
      <Setter Property="DockPanel.Dock" Value="Top"/>
      <Setter Property="FontSize" Value="12"/>
    </Style>
    <Style TargetType="{x:Type TextBox}">
      <Setter Property="Width" Value="100"/>
      <Setter Property="Height" Value="25"/>
      <Setter Property="DockPanel.Dock" Value="Top"/>
    </Style>
    <Style TargetType="{x:Type TextBlock}">
      <Setter Property="Width" Value="100"/>
      <Setter Property="Height" Value="25"/>
      <Setter Property="DockPanel.Dock" Value="Top"/>
      <Setter Property="Padding" Value="3"/>
    </Style>
  </Window.Resources>
  <Border Margin="5" BorderBrush="Aqua" BorderThickness="1" Padding="8" CornerRadius="3">
    <DockPanel Width="200" Height="100" Margin="35">
      <Label>Enter a Name:</Label>
      <TextBox>
        <TextBox.Text>
          <Binding Source="{StaticResource myDataSource}" Path="PersonName"
                   UpdateSourceTrigger="PropertyChanged"/>
        </TextBox.Text>
      </TextBox>
      
      <Label>The name you entered:</Label>
      <TextBlock Text="{Binding Source={StaticResource myDataSource}, Path=PersonName}"/>
    </DockPanel>
  </Border>
</Window>
```

然后就可以将 [TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock) 控件绑定到 XAML 中的对象，如突出显示的包含 `<TextBlock>` 元素的行所示。

或者，可以使用 [ObjectDataProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.objectdataprovider) 类，如以下示例所示：

```xaml
<Window
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  xmlns:src="clr-namespace:SDKSample"
  xmlns:system="clr-namespace:System;assembly=mscorlib"
  SizeToContent="WidthAndHeight"
  Title="Simple Data Binding Sample">

  <Window.Resources>
    <ObjectDataProvider x:Key="myDataSource" ObjectType="{x:Type src:Person}">
      <ObjectDataProvider.ConstructorParameters>
        <system:String>Joe</system:String>
      </ObjectDataProvider.ConstructorParameters>
    </ObjectDataProvider>
    <Style TargetType="{x:Type Label}">
      <Setter Property="DockPanel.Dock" Value="Top"/>
      <Setter Property="FontSize" Value="12"/>
    </Style>
    <Style TargetType="{x:Type TextBox}">
      <Setter Property="Width" Value="100"/>
      <Setter Property="Height" Value="25"/>
      <Setter Property="DockPanel.Dock" Value="Top"/>
    </Style>
    <Style TargetType="{x:Type TextBlock}">
      <Setter Property="Width" Value="100"/>
      <Setter Property="Height" Value="25"/>
      <Setter Property="DockPanel.Dock" Value="Top"/>
    </Style>
  </Window.Resources>

  <Border Margin="25" BorderBrush="Aqua" BorderThickness="3" Padding="8">
    <DockPanel Width="200" Height="100">
      <Label>Enter a Name:</Label>
      <TextBox>
        <TextBox.Text>
          <Binding Source="{StaticResource myDataSource}" Path="Name"
                   UpdateSourceTrigger="PropertyChanged"/>
        </TextBox.Text>
      </TextBox>

      <Label>The name you entered:</Label>
      <TextBlock Text="{Binding Source={StaticResource myDataSource}, Path=Name}"/>
    </DockPanel>
  </Border>
</Window>
```

以相同的方式定义绑定，如突出显示的包含 `<TextBlock>` 元素的行所示。

在此特定示例中，结果是相同的：[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock) 的文本内容为 `Joe`。 但是，[ObjectDataProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.objectdataprovider) 类还提供了其他功能，例如能够绑定到方法的结果。 如果需要 [ObjectDataProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.objectdataprovider) 类提供的功能，则可以选用它。

但是，如果要绑定到已创建的对象，则需要在代码中设置 `DataContext`，如以下示例所示。

```csharp
DataSet myDataSet;

private void OnInit(object sender, EventArgs e)
{
  string mdbFile = Path.Combine(AppDataPath, "BookData.mdb");
  string connString = string.Format(
      "Provider=Microsoft.Jet.OLEDB.4.0; Data Source={0}", mdbFile);
  OleDbConnection conn = new OleDbConnection(connString);
  OleDbDataAdapter adapter = new OleDbDataAdapter("SELECT * FROM BookTable;", conn);

  myDataSet = new DataSet();
  adapter.Fill(myDataSet, "BookTable");

  // myListBox is a ListBox control.
  // Set the DataContext of the ListBox to myDataSet
  myListBox.DataContext = myDataSet;
}
```

若要使用 [XmlDataProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.xmldataprovider) 类访问 XML 数据以进行绑定，请参阅[使用 XMLDataProvider 和 XPath 查询绑定到 XML 数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-bind-to-xml-data-using-an-xmldataprovider-and-xpath-queries)。 若要使用 [ObjectDataProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.objectdataprovider) 类访问 XML 数据以进行绑定，请参阅[绑定到 XDocument、XElement 或 LINQ for XML 查询结果](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-bind-to-xdocument-xelement-or-linq-for-xml-query-results)。

有关指定要绑定到的数据的多种方法的相关信息，请参阅[指定绑定源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-specify-the-binding-source)。 有关可以绑定到哪些数据类型或如何实现你自己的公共语言运行时 (CLR) 对象以进行绑定的相关信息，请参阅[绑定源概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/binding-sources-overview)。

#### [Control When the TextBox Text Updates the Source](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-control-when-the-textbox-text-updates-the-source)

本主题介绍如何使用 [UpdateSourceTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.updatesourcetrigger) 属性控制绑定源更新的时机。 本主题使用 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 控件作为示例。

##### 示例

[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox).[Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.text) 属性具有默认值[UpdateSourceTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.updatesourcetrigger)的值[LostFocus](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.updatesourcetrigger#System_Windows_Data_UpdateSourceTrigger_LostFocus)。 这意味着应用程序是否已[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)与数据绑定[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。[Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.text) 属性中，您将键入的文本[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)不会更新源之前[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)失去焦点 (例如，当单击离开[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox))。

如果希望源在键入时更新，请将绑定的 [UpdateSourceTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.updatesourcetrigger) 设置为 [PropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.updatesourcetrigger#System_Windows_Data_UpdateSourceTrigger_PropertyChanged)。 在下面的示例中，突出显示的代码行表明 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 和 [TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock) 的 `Text` 属性绑定到相同的源属性。 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 绑定的[UpdateSourceTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.updatesourcetrigger) 属性设置为 [PropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.updatesourcetrigger#System_Windows_Data_UpdateSourceTrigger_PropertyChanged)。

```xaml
<Window
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  xmlns:src="clr-namespace:SDKSample"
  xmlns:system="clr-namespace:System;assembly=mscorlib"
  SizeToContent="WidthAndHeight"
  Title="Simple Data Binding Sample">

  <Window.Resources>
    <ObjectDataProvider x:Key="myDataSource" ObjectType="{x:Type src:Person}">
      <ObjectDataProvider.ConstructorParameters>
        <system:String>Joe</system:String>
      </ObjectDataProvider.ConstructorParameters>
    </ObjectDataProvider>
    <Style TargetType="{x:Type Label}">
      <Setter Property="DockPanel.Dock" Value="Top"/>
      <Setter Property="FontSize" Value="12"/>
    </Style>
    <Style TargetType="{x:Type TextBox}">
      <Setter Property="Width" Value="100"/>
      <Setter Property="Height" Value="25"/>
      <Setter Property="DockPanel.Dock" Value="Top"/>
    </Style>
    <Style TargetType="{x:Type TextBlock}">
      <Setter Property="Width" Value="100"/>
      <Setter Property="Height" Value="25"/>
      <Setter Property="DockPanel.Dock" Value="Top"/>
    </Style>
  </Window.Resources>

  <Border Margin="25" BorderBrush="Aqua" BorderThickness="3" Padding="8">
    <DockPanel Width="200" Height="100">
      <Label>Enter a Name:</Label>
      <TextBox>
        <TextBox.Text>
          <Binding Source="{StaticResource myDataSource}" Path="Name"
                   UpdateSourceTrigger="PropertyChanged"/>
        </TextBox.Text>
      </TextBox>

      <Label>The name you entered:</Label>
      <TextBlock Text="{Binding Source={StaticResource myDataSource}, Path=Name}"/>
    </DockPanel>
  </Border>
</Window>
```

因此，[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock) 会在用户将文本输入到 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 时显示相同的文本（因为源发生了更改），如示例的以下屏幕截图所示：

![简单数据绑定示例屏幕快照](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/media/databindingsimplebindingsample2.png)

如果有一个对话框或可供用户编辑的窗体，并且需要将源更新延迟到用户完成字段的编辑并单击“确定”的时候，则可将绑定的 [UpdateSourceTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.updatesourcetrigger) 值设置为 [Explicit](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.updatesourcetrigger#System_Windows_Data_UpdateSourceTrigger_Explicit)，如以下示例所示：

```xaml
<TextBox Name="itemNameTextBox"
         Text="{Binding Path=ItemName, UpdateSourceTrigger=Explicit}" />
```

将 [UpdateSourceTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.updatesourcetrigger) 值设置为 [Explicit](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.updatesourcetrigger#System_Windows_Data_UpdateSourceTrigger_Explicit) 时，源值只会在应用程序调用 [UpdateSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingexpression.updatesource) 方法时更改。 下面的示例演示如何为 `itemNameTextBox` 调用 [UpdateSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingexpression.updatesource)：

```csharp
// itemNameTextBox is an instance of a TextBox
BindingExpression be = itemNameTextBox.GetBindingExpression(TextBox.TextProperty);
be.UpdateSource();
```

> 可以对其他控件的属性使用相同的技巧，但请记住，其他大多数属性的 [UpdateSourceTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.updatesourcetrigger) 默认值为 [PropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.updatesourcetrigger#System_Windows_Data_UpdateSourceTrigger_PropertyChanged)。 有关详细信息，请参阅 [UpdateSourceTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.updatesourcetrigger) 属性页。

> [UpdateSourceTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.updatesourcetrigger) 属性用于处理源更新，因此仅适用于 [TwoWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_TwoWay) 或 [OneWayToSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_OneWayToSource) 绑定。 为了使 [TwoWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_TwoWay) 和 [OneWayToSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_OneWayToSource) 绑定生效，源对象需要提供属性更改通知。 有关详细信息，可以参阅本主题中引用的示例。 此外，也可以参阅[实现属性更改通知](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-implement-property-change-notification)。

#### [Specify the Direction of the Binding](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-specify-the-direction-of-the-binding)

本示例演示如何指定绑定是仅更新绑定目标（目标）属性或绑定源（源）属性，还是同时更新目标属性和源属性。

##### 示例

使用[Mode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.mode)属性指定绑定的方向。 以下枚举列表显示了可供绑定更新的选项：

- [TwoWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_TwoWay) 会在目标属性或源属性更改时进行目标属性或源属性的更新。
- [OneWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_OneWay) 仅当源属性更改时更新目标属性。
- [OneTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_OneTime) 仅当应用程序启动时或[DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext)发生更改时更新目标属性。
- [OneWayToSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_OneWayToSource) 在目标属性更改时更新源属性。
- [Default](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_Default) 迫使系统将使用目标属性的默认 [Mode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.mode) 值。

有关详细信息，请参见 [BindingMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode) 枚举。

下面的示例演示如何设置 [Mode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.mode) 属性。

```xaml
<TextBlock Name="IncomeText" Grid.Row="0" Grid.Column="1"
  Text="{Binding Path=TotalIncome, Mode=OneTime}"/>
```

若要检测源更改 (适用于[OneWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_OneWay)并[TwoWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_TwoWay)绑定)，源必须实现一种合适的属性更改通知机制如[INotifyPropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.inotifypropertychanged)。 请参阅[实现属性更改通知](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-implement-property-change-notification)有关的示例[INotifyPropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.inotifypropertychanged)实现。

有关[TwoWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_TwoWay)或[OneWayToSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_OneWayToSource)绑定的更多信息，您可以通过设置控制源更新的计时[UpdateSourceTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.updatesourcetrigger)属性。有关更多信息，请参见[UpdateSourceTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.updatesourcetrigger)。

#### [Bind to a Collection and Display Information Based on Selection](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-bind-to-a-collection-and-display-information-based-on-selection)

在简单的母版-详细信息方案中，具有数据绑定[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)如[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)。 基于用户所选内容上，显示有关选定项的详细信息。 此示例演示如何实现此方案。

##### 示例

在此示例中，`People` 是 `Person` 类的 [ObservableCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.objectmodel.observablecollection-1)。 `Person` 类包含三个属性：`FirstName`、`LastName` 和 `HomeTown`，类型均为 `string`。

```xaml
<Window x:Class="SDKSample.Window1"
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  xmlns:local="clr-namespace:SDKSample"
  Title="Binding to a Collection"
  SizeToContent="WidthAndHeight">
  <Window.Resources>
    <local:People x:Key="MyFriends"/>
```

```xaml
  </Window.Resources>

  <StackPanel>
    <TextBlock FontFamily="Verdana" FontSize="11"
               Margin="5,15,0,10" FontWeight="Bold">My Friends:</TextBlock>
    <ListBox Width="200" IsSynchronizedWithCurrentItem="True"
             ItemsSource="{Binding Source={StaticResource MyFriends}}"/>
    <TextBlock FontFamily="Verdana" FontSize="11"
               Margin="5,15,0,5" FontWeight="Bold">Information:</TextBlock>
    <ContentControl Content="{Binding Source={StaticResource MyFriends}}"
                    ContentTemplate="{StaticResource DetailTemplate}"/>
  </StackPanel>
</Window>
```

[ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol) 使用以下 [DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)，它定义了 `Person` 信息的显示方式：

```xaml
<DataTemplate x:Key="DetailTemplate">
  <Border Width="300" Height="100" Margin="20"
          BorderBrush="Aqua" BorderThickness="1" Padding="8">
    <Grid>
      <Grid.RowDefinitions>
        <RowDefinition/>
        <RowDefinition/>
        <RowDefinition/>
      </Grid.RowDefinitions>
      <Grid.ColumnDefinitions>
        <ColumnDefinition/>
        <ColumnDefinition/>
      </Grid.ColumnDefinitions>
      <TextBlock Grid.Row="0" Grid.Column="0" Text="First Name:"/>
      <TextBlock Grid.Row="0" Grid.Column="1" Text="{Binding Path=FirstName}"/>
      <TextBlock Grid.Row="1" Grid.Column="0" Text="Last Name:"/>
      <TextBlock Grid.Row="1" Grid.Column="1" Text="{Binding Path=LastName}"/>
      <TextBlock Grid.Row="2" Grid.Column="0" Text="Home Town:"/>
      <TextBlock Grid.Row="2" Grid.Column="1" Text="{Binding Path=HomeTown}"/>
    </Grid>
  </Border>
</DataTemplate>
```

下面是该示例生成的屏幕截图。 [ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol) 显示选中人员的其他属性。

![绑定到集合](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/media/databinding-collectionbindingsample.png)

在此示例中，需要注意两个事项：

1. [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 和 [ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol) 将绑定到相同的源。 两个绑定的 [Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.path) 属性都没有指定，因为这两个控件都绑定到整个集合对象。
2. 必须将 [IsSynchronizedWithCurrentItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.selector.issynchronizedwithcurrentitem) 属性设置为 `true` 才能使其生效。 设置此属性可确保所选的项始终设置为 [CurrentItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemcollection.currentitem)。 或者，如果 [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 从 [CollectionViewSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource) 获取数据，它将自动同步所选内容和货币。

需要注意，`Person` 类将按以下方式重写 `ToString` 方法。 默认情况下，[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 会调用 `ToString` 并以字符串形式显示绑定集合中的每个对象。 这就是每个 `Person` 在 [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 中显示为名字的原因。

```csharp
public override string ToString()
{
    return firstname.ToString();
}
```

#### [Bind to an Enumeration](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-bind-to-an-enumeration)

此示例演示如何将绑定到通过绑定到枚举的 GetValues 方法的枚举。

##### 示例

在下面的示例中，[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 通过数据绑定来显示 [HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.horizontalalignment) 的枚举值列表。 [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 和 [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) 已进行绑定，目的是使你可以通过选择 [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 中的值来更改 [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) 的 [HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.horizontalalignment) 属性值。

```xaml
<Window
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  xmlns:sys="clr-namespace:System;assembly=mscorlib" 
  SizeToContent="WidthAndHeight" 
  Title="Show Enums in a ListBox using Binding">

  <Window.Resources>
    <ObjectDataProvider MethodName="GetValues"
                        ObjectType="{x:Type sys:Enum}"
                        x:Key="AlignmentValues">
      <ObjectDataProvider.MethodParameters>
        <x:Type TypeName="HorizontalAlignment" />
      </ObjectDataProvider.MethodParameters>
    </ObjectDataProvider>
  </Window.Resources>

  <Border Margin="10" BorderBrush="Aqua"
          BorderThickness="3" Padding="8">
    <StackPanel Width="300">
      <TextBlock>Choose the HorizontalAlignment value of the Button:</TextBlock>
      <ListBox Name="myComboBox" SelectedIndex="0" Margin="8"
               ItemsSource="{Binding Source={StaticResource AlignmentValues}}"/>
      <Button Content="Click Me!"
              HorizontalAlignment="{Binding ElementName=myComboBox,
                                            Path=SelectedItem}"/>
    </StackPanel>
  </Border>
</Window>
```

#### [Bind the Properties of Two Controls](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-bind-the-properties-of-two-controls)

此示例演示如何使用 [ElementName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.elementname) 属性将一个实例化控件的属性绑定到另一个。

##### 示例

下面的示例演示如何将 [Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas) 的 [Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.background) 属性绑定到[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox) 的 [SelectedItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.selector.selecteditem).[Content](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.content) 属性： 属性的[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox):

```xaml
<Window
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  Width="460" Height="200"
  Title="Binding the Properties of Two Controls">

  <Window.Resources>
    <Style TargetType="TextBlock">
      <Setter Property="FontSize" Value="16"/>
      <Setter Property="FontWeight" Value="Bold"/>
      <Setter Property="DockPanel.Dock" Value="Top"/>
      <Setter Property="HorizontalAlignment" Value="Center"/>
    </Style>
    <Style TargetType="Canvas">
      <Setter Property="Height" Value="50"/>
      <Setter Property="Width" Value="50"/>
      <Setter Property="Margin" Value="8"/>
      <Setter Property="DockPanel.Dock" Value="Top"/>
    </Style>
    <Style TargetType="ComboBox">
      <Setter Property="Width" Value="150"/>
      <Setter Property="Margin" Value="8"/>
      <Setter Property="DockPanel.Dock" Value="Top"/>
    </Style>
  </Window.Resources>

  <Border Margin="10" BorderBrush="Silver" BorderThickness="3" Padding="8">
    <DockPanel>
      <TextBlock>Choose a Color:</TextBlock>
      <ComboBox Name="myComboBox" SelectedIndex="0">
        <ComboBoxItem>Green</ComboBoxItem>
        <ComboBoxItem>Blue</ComboBoxItem>
        <ComboBoxItem>Red</ComboBoxItem>
      </ComboBox>
      <Canvas>
        <Canvas.Background>
          <Binding ElementName="myComboBox" Path="SelectedItem.Content"/>
        </Canvas.Background>
      </Canvas>
    </DockPanel>
  </Border>
</Window>
```

当此示例呈现时，应如下所示：

![具有绿色背景的画布](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/media/databindingbindingdpssample.png)

**注意** 绑定目标属性（在此示例中为 [Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.background) 属性）必须是依赖项属性。 有关详细信息，请参阅[数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview)。

#### [Implement Binding Validation](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-implement-binding-validation)

此示例演示如何在用户输入无效值后，基于自定义验证规则使用 [ErrorTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation.errortemplate) 和样式触发器来提供视觉反馈，以便通知用户。

##### 示例

在下面的示例中，[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 的文本内容绑定到一个名为 `ods` 的绑定源对象的 `Age` 属性（类型为 int) 。 该绑定已设置为使用名为 `AgeRangeRule` 的验证规则。因此，当用户输入了非数值字符或输入的值小于 21 或者大于 130 时，文本框旁边会显示一个红色感叹号，而当用户将鼠标移动到该文本框上时，会显示包含错误消息的工具提示。

```xaml
<TextBox Name="textBox1" Width="50" FontSize="15"
         Validation.ErrorTemplate="{StaticResource validationTemplate}"
         Style="{StaticResource textBoxInError}"
         Grid.Row="1" Grid.Column="1" Margin="2">
  <TextBox.Text>
    <Binding Path="Age" Source="{StaticResource ods}"
             UpdateSourceTrigger="PropertyChanged" >
      <Binding.ValidationRules>
        <c:AgeRangeRule Min="21" Max="130"/>
      </Binding.ValidationRules>
    </Binding>
  </TextBox.Text>
</TextBox>
```

下面的示例演示如何实现 `AgeRangeRule`，它继承 [ValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule) 并重写 [Validate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule.validate) 方法。 对值调用 Int32.Parse() 方法是为了确保该值不包含任何无效字符。 [Validate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule.validate) 方法将返回 [ValidationResult](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationresult)，该返回结果指示值是否有效（根据是否在分析期间捕获了异常，以及年龄值是否超出了下限和上限）。

```csharp
public class AgeRangeRule : ValidationRule
{
    private int _min;
    private int _max;

    public AgeRangeRule()
    {
    }

    public int Min
    {
        get { return _min; }
        set { _min = value; }
    }

    public int Max
    {
        get { return _max; }
        set { _max = value; }
    }

    public override ValidationResult Validate(object value, CultureInfo cultureInfo)
    {
        int age = 0;

        try
        {
            if (((string)value).Length > 0)
                age = Int32.Parse((String)value);
        }
        catch (Exception e)
        {
            return new ValidationResult(false, "Illegal characters or " + e.Message);
        }

        if ((age < Min) || (age > Max))
        {
            return new ValidationResult(false,
              "Please enter an age in the range: " + Min + " - " + Max + ".");
        }
        else
        {
            return ValidationResult.ValidResult;
        }
    }
}
```

下面的示例演示了自定义 [ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate) `validationTemplate`，后者会创建一个红色感叹号来通知用户存在验证错误。 控件模板用于重新定义控件的外观。

```xaml
<ControlTemplate x:Key="validationTemplate">
  <DockPanel>
    <TextBlock Foreground="Red" FontSize="20">!</TextBlock>
    <AdornedElementPlaceholder/>
  </DockPanel>
</ControlTemplate>
```

如以下示例所示，显示错误消息的 [ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip) 是通过名为 `textBoxInError` 的样式创建的。 如果 [HasError](https://msdn.microsoft.com/library/system.windows.controls.validation.haserror) 的值是 `true`，该触发器会将当前 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 的工具提示设置为其第一个验证错误。 [RelativeSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.relativesource) 设置为 [Self](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.relativesourcemode#System_Windows_Data_RelativeSourceMode_Self)，用于引用当前元素。

```xaml
<Style x:Key="textBoxInError" TargetType="{x:Type TextBox}">
  <Style.Triggers>
    <Trigger Property="Validation.HasError" Value="true">
      <Setter Property="ToolTip"
        Value="{Binding RelativeSource={x:Static RelativeSource.Self},
                        Path=(Validation.Errors)[0].ErrorContent}"/>
    </Trigger>
  </Style.Triggers>
</Style>
```

有关完整示例，请参阅[绑定验证示例](https://go.microsoft.com/fwlink/?LinkID=159972)。

请注意，如果未提供自定义 [ErrorTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation.errortemplate)，则当验证出错时,系统会使用默认错误模板向用户提供可视反馈。 有关详细信息，请参阅[数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview)中的“数据验证”。 另外，WPF 还提供了内置验证规则，该规则捕获在更新绑定源属性期间引发的异常。 有关详细信息，请参阅 [ExceptionValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.exceptionvalidationrule)。

#### [Implement Validation Logic on Custom Objects](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-implement-validation-logic-on-custom-objects)

此示例演示如何自定义对象上实现验证逻辑，然后绑定到它。

##### 示例

如果源对象实现了 [IDataErrorInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.idataerrorinfo) 接口，就可以在业务层上提供验证逻辑，如以下示例所示，其中定义了一个 `Person` 对象，它实现了 [IDataErrorInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.idataerrorinfo):

```csharp
public class Person : IDataErrorInfo
{
    private int age;

    public int Age
    {
        get { return age; }
        set { age = value; }
    }

    public string Error
    {
        get
        {
            return null;
        }
    }

    public string this[string name]
    {
        get
        {
            string result = null;

            if (name == "Age")
            {
                if (this.age < 0 || this.age > 150)
                {
                    result = "Age must not be less than 0 or greater than 150.";
                }
            }
            return result;
        }
    }
}
```

以下示例中，文本框的 text 属性绑定到 `Person.Age` 属性，已通过一个（给定 `x:Key` `data`的）资源声明来使得该属性对象可用于绑定。 [DataErrorValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dataerrorvalidationrule) 检查 [IDataErrorInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.idataerrorinfo) 实现引发的验证错误。

```xaml
<Window x:Class="BusinessLayerValidation.Window1"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        Title="WPF IDataErrorInfo Sample" Width="350" Height="150"
        xmlns:src="clr-namespace:BusinessLayerValidation">
    
    <Window.Resources>
        <src:Person x:Key="data"/>

        <!--The tool tip for the TextBox to display the validation error message.-->
        <Style x:Key="textBoxInError" TargetType="TextBox">
            <Style.Triggers>
                <Trigger Property="Validation.HasError" Value="true">
                    <Setter Property="ToolTip"
                            Value="{Binding RelativeSource={x:Static RelativeSource.Self},
                        Path=(Validation.Errors)[0].ErrorContent}"/>
                </Trigger>
            </Style.Triggers>
        </Style>
    </Window.Resources>

    <StackPanel Margin="20">
        <TextBlock>Enter your age:</TextBlock>

        <TextBox Style="{StaticResource textBoxInError}">
            <TextBox.Text>
                <!--By setting ValidatesOnExceptions to True, it checks for exceptions
                that are thrown during the update of the source property.
                An alternative syntax is to add <ExceptionValidationRule/> within
                the <Binding.ValidationRules> section.-->
                <Binding Path="Age" Source="{StaticResource data}"
                         ValidatesOnExceptions="True"
                         UpdateSourceTrigger="PropertyChanged">
                    <Binding.ValidationRules>
                        <!--DataErrorValidationRule checks for validation 
                            errors raised by the IDataErrorInfo object.-->
                        <!--Alternatively, you can set ValidationOnDataErrors="True" on the Binding.-->
                        <DataErrorValidationRule/>
                    </Binding.ValidationRules>
                </Binding>
            </TextBox.Text>
        </TextBox>

        <TextBlock>Mouse-over to see the validation error message.</TextBlock>
    </StackPanel>
</Window>
```

或者，也可以将 [ValidatesOnDataErrors](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.validatesondataerrors) 属性设置为`true`，而不是使用 [DataErrorValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dataerrorvalidationrule)。

#### [Get the Binding Object from a Bound Target Property](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-get-the-binding-object-from-a-bound-target-property)

本示例演示如何从数据绑定的目标属性获取绑定对象。

##### 示例

可以执行以下操作来获取 [Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding) 对象：

```csharp
// textBox3 is an instance of a TextBox
// the TextProperty is the data-bound dependency property
Binding myBinding = BindingOperations.GetBinding(textBox3, TextBox.TextProperty);
```

> 要获取所需的绑定，必须指定依赖属性，因为目标对象中正在使用数据绑定的属性可能不止一个。

或者，可以获取 [BindingExpression](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingexpression)，然后获取 [ParentBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingexpression.parentbinding) 属性的值。

有关完整示例，请参阅[绑定验证示例](https://go.microsoft.com/fwlink/?LinkID=159972)。

> 如果绑定是 [MultiBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.multibinding)，则使用 [BindingOperations](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingoperations).[GetMultiBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingoperations.getmultibinding)。 如果是 [PriorityBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.prioritybinding)，则使用 [BindingOperations](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingoperations).[GetPriorityBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingoperations.getprioritybinding)。 如果你不确定目标属性是否使用 [Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)、[MultiBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.multibinding) 或 [PriorityBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.prioritybinding) 进行了绑定，可以使用 [BindingOperations](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingoperations).[GetBindingBase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingoperations.getbindingbase)。

#### [Implement a CompositeCollection](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-implement-a-compositecollection)

##### 示例

下面的示例演示如何使用 [CompositeCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.compositecollection) 类将多个集合和项显示为一个列表。 在此示例中，`GreekGods` 是 `GreekGod` 自定义对象的一个 [ObservableCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.objectmodel.observablecollection-1)。 定义了数据模板以便 `GreekGod` 对象和 `GreekHero` 对象分别以金色和青色作为前景色显示。

```xaml
<Window Background="Cornsilk"
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  xmlns:c="clr-namespace:SDKSample"
  x:Class="SDKSample.Window1"
  Title="CompositeCollections"
  SizeToContent="WidthAndHeight"
  >
  <Window.Resources>
    <c:GreekGods x:Key="GreekGodsData"/>

    <XmlDataProvider x:Key="GreekHeroesData" XPath="GreekHeroes/Hero">
      <x:XData>
      <GreekHeroes xmlns="">
        <Hero Name="Jason" />
        <Hero Name="Hercules" />
        <Hero Name="Bellerophon" />
        <Hero Name="Theseus" />
        <Hero Name="Odysseus" />
        <Hero Name="Perseus" />
      </GreekHeroes>
      </x:XData>
    </XmlDataProvider>

    <DataTemplate DataType="{x:Type c:GreekGod}">
      <TextBlock Text="{Binding Path=Name}" Foreground="Gold"/>
    </DataTemplate>
    <DataTemplate DataType="Hero">
      <TextBlock Text="{Binding XPath=@Name}" Foreground="Cyan"/>
    </DataTemplate>
    </Window.Resources>
    
  <StackPanel>
    <TextBlock FontSize="18" FontWeight="Bold" Margin="10"
      HorizontalAlignment="Center">Composite Collections Sample</TextBlock>
    <ListBox Name="myListBox" Height="300" Width="200" Background="White">
      <ListBox.ItemsSource>
        <CompositeCollection>
          <CollectionContainer
            Collection="{Binding Source={StaticResource GreekGodsData}}" />
          <CollectionContainer
            Collection="{Binding Source={StaticResource GreekHeroesData}}" />
          <ListBoxItem Foreground="Red">Other Listbox Item 1</ListBoxItem>
          <ListBoxItem Foreground="Red">Other Listbox Item 2</ListBoxItem>
        </CompositeCollection>
      </ListBox.ItemsSource>
    </ListBox>
  </StackPanel>

</Window>
```

#### [Convert Bound Data](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-convert-bound-data)

此示例演示如何将应用到绑定中使用的数据转换。

若要在绑定期间转换数据，必须创建一个类以实现 [IValueConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.ivalueconverter) 接口，其中包括 [Convert](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.ivalueconverter.convert) 和 [ConvertBack](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.ivalueconverter.convertback) 方法。

##### 示例

下面的示例演示了一个日期转换器的实现，该转换器将转换传入的日期值，使其仅显示年、月、日。 实现[IValueConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.ivalueconverter) 接口时，使用 [ValueConversionAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.valueconversionattribute) 属性修饰该实现以向开发工具表明转换中涉及的数据类型，这是一个非常好的做法，如以下示例所示：

```csharp
[ValueConversion(typeof(DateTime), typeof(String))]
public class DateConverter : IValueConverter
{
    public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
    {
        DateTime date = (DateTime)value;
        return date.ToShortDateString();
    }

    public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
    {
        string strValue = value as string;
        DateTime resultDateTime;
        if (DateTime.TryParse(strValue, out resultDateTime))
        {
            return resultDateTime;
        }
        return DependencyProperty.UnsetValue;
    }
}
```

创建一个转换器后，可以将其添加为中的资源在可扩展应用程序标记语言 (XAML)文件。 在以下示例中， *src*映射到在其中命名空间*DateConverter*定义。

```xaml
<src:DateConverter x:Key="dateConverter"/>
```

最后，您可以使用以下语法在绑定中使用转换器。 在下面的示例中，文本的内容[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)绑定到*StartDate*，这是外部数据源属性。

```xaml
<TextBlock Grid.Row="2" Grid.Column="0" Margin="0,0,8,0"
           Name="startDateTitle"
           Style="{StaticResource smallTitleStyle}">Start Date:</TextBlock>
<TextBlock Name="StartDateDTKey" Grid.Row="2" Grid.Column="1" 
    Text="{Binding Path=StartDate, Converter={StaticResource dateConverter}}" 
    Style="{StaticResource textStyleTextBlock}"/>
```

上面的示例引用的样式资源在一个未在此主题中列出的资源部分中定义。

#### [Create a Binding in Code](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-create-a-binding-in-code)

此示例演示如何在代码中创建和设置 [Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)。

##### 示例

[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement) 类和 [FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement) 类都公开了 `SetBinding` 方法。 如果要绑定的元素继承其中的一个类，则可直接调用 [SetBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.setbinding) 方法。

下面的示例创建了一个名为 `MyData` 的类，其中包含一个名为 `MyDataProperty` 的属性。

```csharp
public class MyData : INotifyPropertyChanged
{
    private string myDataProperty;

    public MyData() { }

    public MyData(DateTime dateTime)
    {
        myDataProperty = "Last bound time was " + dateTime.ToLongTimeString();
    }

    public String MyDataProperty
    {
        get { return myDataProperty; }
        set
        {
            myDataProperty = value;
            OnPropertyChanged("MyDataProperty");
        }
    }

    public event PropertyChangedEventHandler PropertyChanged;
    
    private void OnPropertyChanged(string info)
    {
        PropertyChangedEventHandler handler = PropertyChanged;
        if (handler != null)
        {
            handler(this, new PropertyChangedEventArgs(info));
        }
    }
}
```

下面的示例演示如何创建绑定对象来设置绑定源。 该示例使用 [SetBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.setbinding) 将 `myText` （一个 [TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock) 控件）的 [Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.text) 属性绑定到 `MyDataProperty`。

```csharp
// Make a new source.
MyData myDataObject = new MyData(DateTime.Now);      
Binding myBinding = new Binding("MyDataProperty");
myBinding.Source = myDataObject;
// Bind the new data source to the myText TextBlock control's Text dependency property.
myText.SetBinding(TextBlock.TextProperty, myBinding);
```

有关完整的代码示例，请参阅[仅限代码的绑定示例](https://msdn.microsoft.com/library/764aaf0b-2216-4941-9548-9c98da18d1a6)。

可以使用 [BindingOperations](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingoperations) 类的静态方法 [SetBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingoperations.setbinding)，而不是调用 [SetBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.setbinding)。 下面的示例通过调用 [BindingOperations.SetBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingoperations.setbinding) 而不是 [FrameworkElement.SetBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.setbinding) 将 `myText` 绑定到 `myDataProperty`。

```csharp
//make a new source
MyData myDataObject = new MyData(DateTime.Now);
Binding myBinding = new Binding("MyDataProperty");
myBinding.Source = myDataObject;
BindingOperations.SetBinding(myText, TextBlock.TextProperty, myBinding);
```

#### [Get the Default View of a Data Collection](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-get-the-default-view-of-a-data-collection)

可以通过视图以不同的方式查看同一数据集合，具体取决于排序、筛选或分组规则。 每个集合都有一个共享的默认视图，在绑定指定一个集合作为其源时用作实际绑定源。 此示例演示如何获取集合的默认视图。

##### 示例

若要创建视图，需要一个针对该集合的对象引用。 可以通过引用自己的代码隐藏对象、获取数据上下文、获取数据源属性、获取绑定属性的方式来获得该数据对象。 此示例演示如何获取数据对象的 [DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext) 并使用它来直接获取该集合的默认集合视图。

```csharp
myCollectionView = (CollectionView)
    CollectionViewSource.GetDefaultView(rootElem.DataContext);
```

在此示例中，根元素是 [StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)。 [DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext) 设置为 *myDataSource*，它引用的数据提供程序是 *Order* 对象的[ObservableCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.objectmodel.observablecollection-1)。

```xaml
<StackPanel.DataContext>
  <Binding Source="{StaticResource myDataSource}"/>
</StackPanel.DataContext>
```

也可使用 [CollectionViewSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource) 类实例化你自己的集合视图并将内容绑定到它。 此集合视图仅由直接绑定到它的控件共享。 有关示例，请参阅[数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview)中的“如何创建视图”部分。

有关集合视图提供的功能的示例，请参阅[在视图中对数据进行排序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-sort-data-in-a-view)、[在视图中筛选数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-filter-data-in-a-view)和[在数据 CollectionView 中的对象之间导航](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-navigate-through-the-objects-in-a-data-collectionview)。

#### [Navigate Through the Objects in a Data CollectionView](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-navigate-through-the-objects-in-a-data-collectionview)

视图允许相同的数据收集，以便在不同的方式，具体取决于排序、 筛选或分组中查看。 视图还提供一个当前记录指针概念，并启用移动指针。 此示例演示如何获取当前对象，以及在使用中提供的功能的数据集合的对象之间导航[CollectionView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionview)类。

##### 示例

在此示例中，`myCollectionView`是[CollectionView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionview)对绑定集合是一个视图的对象。

在以下示例中，`OnButton`是事件处理程序`Previous`和`Next`应用程序，这两个允许用户导航数据收集的按钮的按钮。 请注意，[IsCurrentBeforeFirst](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionview.iscurrentbeforefirst)并[IsCurrentAfterLast](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionview.iscurrentafterlast)是否当前记录指针是否到达的开头和列表的末尾分别因此的属性报告[MoveCurrentToFirst](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionview.movecurrenttofirst)和[MoveCurrentToLast](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionview.movecurrenttolast)可以相应地调用。

[CurrentItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionview.currentitem)视图的属性强制转换为`Order`要在集合中返回当前的订单项。

```csharp
//OnButton is called whenever the Next or Previous buttons
//are clicked to change the currency
  private void OnButton(Object sender, RoutedEventArgs args)
  {
      Button b = sender as Button;

      switch (b.Name)
      {
          case "Previous":
              myCollectionView.MoveCurrentToPrevious();

              if (myCollectionView.IsCurrentBeforeFirst)
              {
                  myCollectionView.MoveCurrentToLast();
              }
              break;

          case "Next":
              myCollectionView.MoveCurrentToNext();
              if (myCollectionView.IsCurrentAfterLast)
              {
                  myCollectionView.MoveCurrentToFirst();
              }
              break;
              
          o = myCollectionView.CurrentItem as Order;
          // TODO: do something with the current Order o 
      }
  }
```

#### [Filter Data in a View](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-filter-data-in-a-view)

此示例演示如何对视图中的数据进行筛选。

##### 示例

若要创建筛选器，需要定义提供筛选逻辑的方法。 该方法用作回调，接受 `object` 类型的参数。 以下方法将返回所有`Order`对象与`filled`属性设置为"否"，筛选出的对象的其余部分。

```csharp
public bool Contains(object de)
{
    Order order = de as Order;
    //Return members whose Orders have not been filled
    return(order.Filled== "No");
}
```

然后可以应用筛选器，如下面的示例中所示。 在此示例中，`myCollectionView`是 [ListCollectionView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.listcollectionview) 对象。

```csharp
myCollectionView.Filter = new Predicate<object>(Contains);
```

若要撤销筛选，可以将 [Filter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionview.filter) 属性设置为 `null`：

```csharp
myCollectionView.Filter = null;
```

有关如何创建或获取视图的信息，请参阅[获取数据集合的默认视图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-get-the-default-view-of-a-data-collection)。 有关完整示例，请参阅[对视图中的项目进行排序和筛选的示例](https://go.microsoft.com/fwlink/?LinkID=160040)。

如果视图对象是一个 [CollectionViewSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource) 对象，可以通过设置 [Filter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource.filter) 事件的事件处理程序来应用筛选逻辑。 在以下示例中，`listingDataView` 是 [CollectionViewSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource) 的一个实例。

```csharp
listingDataView.Filter += new FilterEventHandler(ShowOnlyBargainsFilter);
```

下面展示了如何实现示例筛选器 `ShowOnlyBargainsFilter` 的事件处理程序。 此事件处理程序使用 [Accepted](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.filtereventargs.accepted) 属性来过滤掉 `CurrentPrice` 至少为 25 美元的 `AuctionItem` 对象。

```csharp
private void ShowOnlyBargainsFilter(object sender, FilterEventArgs e)
{
    AuctionItem product = e.Item as AuctionItem;
    if (product != null)
    {
        // Filter out products with price 25 or above
        if (product.CurrentPrice < 25)
        {
            e.Accepted = true;
        }
        else
        {
            e.Accepted = false;
        }
    }
}
```

#### [Sort Data in a View](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-sort-data-in-a-view)

本示例介绍如何在视图中对数据进行排序。

##### 示例

下面的示例创建了一个简单的 [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 和一个 [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button):

```xaml
<Window x:Class="ListBoxSort_snip.Window1"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    Title="ListBoxSort_snip" Height="300" Width="300">
    <DockPanel>
      <ListBox Name="myListBox" DockPanel.Dock="Top">
        <ListBoxItem>my</ListBoxItem>
        <!--Or you can set the content this way:-->
        <!--<ListBoxItem Content="my"/>-->
        <ListBoxItem>1</ListBoxItem>
        <ListBoxItem>Sort</ListBoxItem>
        <ListBoxItem>3</ListBoxItem>
        <ListBoxItem>ListBox</ListBoxItem>
        <ListBoxItem>2</ListBoxItem>
      </ListBox>
      <Button Click="OnClick" Width="30" Height="20" DockPanel.Dock="Top">Sort</Button>
    </DockPanel>
</Window>
```

按钮的 [Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click) 事件处理程序包含对 [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 中的项进行降序排序的逻辑。 之所以可以这样做是因为以这种方式将对象添加到 [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 实际是将它们添加到了 [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 的 [ItemCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemcollection)，而 [ItemCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemcollection) 派生自 [CollectionView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionview) 类。如果用 [ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource) 属性将[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 绑定到一个集合，也可以使用相同的技术进行排序。

```csharp
private void OnClick(object sender, RoutedEventArgs e)
{
    myListBox.Items.SortDescriptions.Add(
        new SortDescription("Content", ListSortDirection.Descending));
}
```

只要有视图对象的引用，就可以使用相同的技术对其他集合视图的内容进行排序。 有关如何获取视图的示例，请参阅[获取数据集合的默认视图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-get-the-default-view-of-a-data-collection)。 另一个示例请参阅[在单击标题时对 GridView 列进行排序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-sort-a-gridview-column-when-a-header-is-clicked)。 有关视图的详细信息，请参阅 [数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview)中的“绑定到集合”。

有关如何在可扩展应用程序标记语言 (XAML)中应用排序逻辑的示例，请参阅[在 XAML 中使用视图对数据进行排序和分组](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-sort-and-group-data-using-a-view-in-xaml)。

#### [Sort and Group Data Using a View in XAML](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-sort-and-group-data-using-a-view-in-xaml)

此示例演示如何在可扩展应用程序标记语言 (XAML)中创建数据集合的视图。 视图提供分组、排序、筛选功能和当前项的概念。

##### 示例

在下面的示例中，名为 *places* 的静态资源被定义为 *Place* 对象的集合，其中每个 *Place* 对象包含城市名和州。 前缀 *src* 映射到定义 *Places* 数据源的命名空间。 前缀 *scm* 映射到`"clr-namespace:System.ComponentModel;assembly=WindowsBase"`，*dat* 映射到`"clr-namespace:System.Windows.Data;assembly=PresentationFramework"`。

下面的示例创建数据集合的视图，数据按城市名称排序，并按州分组。

```xaml
<Window.Resources>

  <src:Places x:Key="places"/>

  <CollectionViewSource Source="{StaticResource places}" x:Key="cvs">
    <CollectionViewSource.SortDescriptions>
      <scm:SortDescription PropertyName="CityName"/>
    </CollectionViewSource.SortDescriptions>
    <CollectionViewSource.GroupDescriptions>
      <dat:PropertyGroupDescription PropertyName="State"/>
    </CollectionViewSource.GroupDescriptions>
  </CollectionViewSource>
```

然后，该视图可以是绑定源，如以下示例所示：

```xaml
<ListBox ItemsSource="{Binding Source={StaticResource cvs}}"
         DisplayMemberPath="CityName" Name="lb">
  <ListBox.GroupStyle>
    <x:Static Member="GroupStyle.Default"/>
  </ListBox.GroupStyle>
</ListBox>
```

绑定到 [XmlDataProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.xmldataprovider) 资源中定义的 XML 数据时，XML 名称前面要加上 @ 符号。

```xaml
<XmlDataProvider x:Key="myTasks" XPath="Tasks/Task">
    <x:XData>
        <Tasks xmlns="">
            <Task Name="Groceries" Priority="2" Type="Home">
```

```xaml
<CollectionViewSource x:Key="mySortedTasks"
                      Source="{StaticResource myTasks}">
    <CollectionViewSource.SortDescriptions>
        <scm:SortDescription PropertyName="@Priority" />
    </CollectionViewSource.SortDescriptions>
    <CollectionViewSource.GroupDescriptions>
        <dat:PropertyGroupDescription PropertyName="@Priority" />
    </CollectionViewSource.GroupDescriptions>
</CollectionViewSource>
```

#### [Use the Master-Detail Pattern with Hierarchical Data](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-use-the-master-detail-pattern-with-hierarchical-data)

此示例演示如何实现母版-详细信息方案。

##### 示例

在此示例中，`LeagueList` 是 `Leagues` 的集合。 每个 `League` 有一个 `Name` 和一个 `Divisions` 的集合，每个 `Division` 有一个名称和一个 `Teams` 的集合。 每个 `Team` 有一个团队名称。

```xaml
<Window
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  xmlns:src="clr-namespace:SDKSample"
  Width="400" Height="180"
  Title="Master-Detail Binding" 
  Background="Silver">
  <Window.Resources>
    <src:LeagueList x:Key="MyList"/>
```

```xaml
  <DockPanel DataContext="{Binding Source={StaticResource MyList}}">
    <StackPanel>
      <Label>My Soccer Leagues</Label>
      <ListBox ItemsSource="{Binding}" DisplayMemberPath="Name"
               IsSynchronizedWithCurrentItem="true"/>
    </StackPanel>

    <StackPanel>
      <Label Content="{Binding Path=Name}"/>
      <ListBox ItemsSource="{Binding Path=Divisions}" DisplayMemberPath="Name"
               IsSynchronizedWithCurrentItem="true"/>
    </StackPanel>

    <StackPanel>
      <Label Content="{Binding Path=Divisions/Name}"/>
      <ListBox DisplayMemberPath="Name" ItemsSource="{Binding Path=Divisions/Teams}"/>
    </StackPanel>
  </DockPanel>
</Window>
```

下面是该示例的一个屏幕快照。 `Divisions` 列表框[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)自动跟踪 `Leagues` 列表框[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)中的选择并显示相应的数据。 `Teams` 列表框[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)跟踪其他两个列表框[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)控件中的选择。

![Master-详细信息示例](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/media/databindingmasterdetailsample.png)

在此示例中，有两点需要注意：

1. 这三个 [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 控件绑定到相同的源。 需设置绑定的 [Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.path) 属性，用于指定 [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 显示哪个级别的数据。
2. 对于要跟踪其选择内容的 [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 控件, 须将其 [IsSynchronizedWithCurrentItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.selector.issynchronizedwithcurrentitem) 属性设置为 `true`。 设置此属性可确保所选的项始终设置为 [CurrentItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemcollection.currentitem)。 或者，如果 [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 从 [CollectionViewSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource) 获取数据，它会自动同步所选内容和货币。

使用XML数据时，采用的方法略有不同。 有关示例，请参阅[对分层 XML 数据使用主-从模式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-use-the-master-detail-pattern-with-hierarchical-xml-data)。

#### [Use the Master-Detail Pattern with Hierarchical XML Data](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-use-the-master-detail-pattern-with-hierarchical-xml-data)

此示例演示如何使用 XML 数据实现主 - 从方案。

##### 示例

此示例是[对分层数据使用主-从模式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-use-the-master-detail-pattern-with-hierarchical-data)中讨论的示例的 XML 版本。 在此示例中，数据来自文件 `League.xml`。 请注意第三个 [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 控件如何通过绑定到 [SelectedValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.selector.selectedvalue) 属性来跟踪第二个 [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 中的选择变化。

```xaml
<Window x:Class="SDKSample.Window1"
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  Title="Multiple ListBox Binding Sample"
  Width="400" Height="200"
  Background="Cornsilk">
    <Window.Resources>
      <XmlDataProvider x:Key="MyList" Source="Data\Leagues.xml"
                       XPath="Leagues/League"/>
      <DataTemplate x:Key="dataTemplate">
        <TextBlock Text="{Binding XPath=@name}" />
      </DataTemplate>
```

```xaml
    </Window.Resources>

    <DockPanel DataContext="{Binding Source={StaticResource MyList}}">
      <StackPanel>
        <Label>My Soccer Leagues</Label>
        <ListBox ItemsSource="{Binding}"
                 ItemTemplate="{StaticResource dataTemplate}"
                 IsSynchronizedWithCurrentItem="true"/>
      </StackPanel>

      <StackPanel>
        <Label Content="{Binding XPath=@name}"/>
        <ListBox Name="divisionsListBox"
                 ItemsSource="{Binding XPath=Division}"
                 ItemTemplate="{StaticResource dataTemplate}"
                 IsSynchronizedWithCurrentItem="true"/>
      </StackPanel>

      <StackPanel>
        <Label Content="{Binding XPath=@name}"/>
        <ListBox DataContext="{Binding ElementName=divisionsListBox,
                                       Path=SelectedItem}"
                 ItemsSource="{Binding XPath=Team}"
                 ItemTemplate="{StaticResource dataTemplate}"/>
      </StackPanel>
    </DockPanel>
</Window>
```

#### [Produce a Value Based on a List of Bound Items](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-produce-a-value-based-on-a-list-of-bound-items)

[MultiBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.multibinding) 可以将绑定目标属性绑定到的源属性列表，然后应用逻辑以生成使用给定的输入值。 此示例演示如何使用[MultiBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.multibinding)。

##### 示例

在下面的示例中，`NameListData` 引用包含 `firstName` 和 `lastName` 这两个属性的 `PersonName` 对象的集合。 下面的示例生成[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)，显示的第一个和最后一个名称的人员的姓氏第一个。

```xaml
<Window
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  xmlns:c="clr-namespace:SDKSample"
  x:Class="SDKSample.Window1"
  Width="400"
  Height="280"
  Title="MultiBinding Sample">
    
  <Window.Resources>
    <c:NameList x:Key="NameListData"/>
    <c:NameConverter x:Key="myNameConverter"/>
```

```xaml
</Window.Resources>
```

```xaml
<TextBlock Name="textBox2" DataContext="{StaticResource NameListData}">
  <TextBlock.Text>
    <MultiBinding Converter="{StaticResource myNameConverter}"
                  ConverterParameter="FormatLastFirst">
      <Binding Path="FirstName"/>
      <Binding Path="LastName"/>
    </MultiBinding>
  </TextBlock.Text>
</TextBlock>
```

```xaml
</Window>
```

为了了解如何生成姓氏在前的格式，我们来了解一下 `NameConverter` 的实现：

```csharp
public class NameConverter : IMultiValueConverter
{
    public object Convert(object[] values, Type targetType, object parameter, CultureInfo culture)
    {
        string name;

        switch ((string)parameter)
        {
            case "FormatLastFirst":
                name = values[1] + ", " + values[0];
                break;
            case "FormatNormal":
            default:
                name = values[0] + " " + values[1];
                break;
        }

        return name;
    }

    public object[] ConvertBack(object value, Type[] targetTypes, object parameter, CultureInfo culture)
    {
        string[] splitValues = ((string)value).Split(' ');
        return splitValues;
    }
}
```

`NameConverter` 实现 [IMultiValueConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.imultivalueconverter) 接口。 `NameConverter` 从个别绑定获取值并将其存储在值对象数组中。 依据的顺序[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)元素出现在[MultiBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.multibinding)元素是在其中这些值存储在数组中的顺序。 值[ConverterParameter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.multibinding.converterparameter)属性引用的参数自变量的[Converter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.multibinding.converter)方法，后者将执行一个开关参数以确定如何设置名称格式。

#### [Implement Property Change Notification](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-implement-property-change-notification)

若要支持[OneWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_OneWay)或[TwoWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_TwoWay)绑定，从而使绑定目标属性能够自动反映绑定源 （例如，若要自动更新，当用户编辑窗体时，预览窗格），动态更改您的类需要提供相应的属性更改通知。 此示例演示如何创建实现的类[INotifyPropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.inotifypropertychanged)。

##### 示例

若要实现[INotifyPropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.inotifypropertychanged)需要声明[PropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.inotifypropertychanged.propertychanged)事件并创建`OnPropertyChanged`方法。 然后，对于每个需要更改通知的属性，只要进行了更新，就可以调用 `OnPropertyChanged`。

```csharp
using System.ComponentModel;

namespace SDKSample
{
  // This class implements INotifyPropertyChanged
  // to support one-way and two-way bindings
  // (such that the UI element updates when the source
  // has been changed dynamically)
  public class Person : INotifyPropertyChanged
  {
      private string name;
      // Declare the event
      public event PropertyChangedEventHandler PropertyChanged;

      public Person()
      {
      }

      public Person(string value)
      {
          this.name = value;
      }
      
      public string PersonName
      {
          get { return name; }
          set
          {
              name = value;
              // Call OnPropertyChanged whenever the property is updated
              OnPropertyChanged("PersonName");
          }
      }

      // Create the OnPropertyChanged method to raise the event
      protected void OnPropertyChanged(string name)
      {
          PropertyChangedEventHandler handler = PropertyChanged;
          if (handler != null)
          {
              handler(this, new PropertyChangedEventArgs(name));
          }
      }
  }
}
```

若要查看如何的示例`Person`类可用于支持[TwoWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_TwoWay)绑定，请参阅[控制文本框文本更新源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-control-when-the-textbox-text-updates-the-source)。

#### [Create and Bind to an ObservableCollection](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-create-and-bind-to-an-observablecollection)

此示例演示如何创建和绑定到一个集合，其中派生[ObservableCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.objectmodel.observablecollection-1)类，该类是一个集合类，添加或移除项时提供通知。

##### 示例

下面的示例演示 `NameList` 集合的实现：

```csharp
public class NameList : ObservableCollection<PersonName>  
{  
    public NameList() : base()  
    {  
        Add(new PersonName("Willa", "Cather"));  
        Add(new PersonName("Isak", "Dinesen"));  
        Add(new PersonName("Victor", "Hugo"));  
        Add(new PersonName("Jules", "Verne"));  
    }  
  }  
  
  public class PersonName  
  {  
      private string firstName;  
      private string lastName;  
  
      public PersonName(string first, string last)  
      {  
          this.firstName = first;  
          this.lastName = last;  
      }  
  
      public string FirstName  
      {  
          get { return firstName; }  
          set { firstName = value; }  
      }  
  
      public string LastName  
      {  
          get { return lastName; }  
          set { lastName = value; }  
      }  
  }  
```

可以根据[使数据可用于 XAML 中的绑定](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-make-data-available-for-binding-in-xaml)中的说明，按照与其他 公共语言运行时 (CLR) 对象相同的方式使集合可用于绑定。 例如，可以在 XAML 中实例化该集合，并将该集合指定为一个资源，如下所示：

```xaml
<Window  
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"  
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"  
  xmlns:c="clr-namespace:SDKSample"  
  x:Class="SDKSample.Window1"  
  Width="400"  
  Height="280"  
  Title="MultiBinding Sample">  
  
  <Window.Resources>  
    <c:NameList x:Key="NameListData"/>  
  
...  
  
</Window.Resources>  
```

然后可以绑定到该集合：

```xaml
<ListBox Width="200"  
         ItemsSource="{Binding Source={StaticResource NameListData}}"  
         ItemTemplate="{StaticResource NameItemTemplate}"  
         IsSynchronizedWithCurrentItem="True"/>  
```

此处没有显示 `NameItemTemplate` 的定义。

> 集合中的对象必须满足[绑定源概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/binding-sources-overview)中所述的要求。 具体而言，如果使用的[OneWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_OneWay)或[TwoWay](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingmode#System_Windows_Data_BindingMode_TwoWay)(例如，希望你UI时更新源属性发生显著变化)，必须实现适当的属性更改通知机制，如[INotifyPropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.inotifypropertychanged)接口。

有关详细信息，请参阅[数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview)中的“绑定到集合”一节。

#### [Implement PriorityBinding](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-implement-prioritybinding)

Windows Presentation Foundation (WPF) 中 [PriorityBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.prioritybinding) 的工作方式是指定一个绑定列表。 列表中的绑定按优先级从高到低排序。 对最高优先级绑定进行处理时，如果成功返回一个值，就不再需要处理列表中的其他绑定。在最高优先级绑定需要长时间计算的情况下，则会使用已成功返回值的下一个优先级最高的绑定，直到优先级更高的绑定成功返回值为止。

##### 示例

为了演示 [PriorityBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.prioritybinding) 的工作方式，我们创建了 `AsyncDataSource` 对象，该对象具有三个属性：`FastDP`、`SlowerDP` 和 `SlowestDP`。

`FastDP` 的 Get 访问器返回数据成员 `_fastDP` 的值。

`SlowerDP` 的 Get 访问器等待 3 秒后返回数据成员 `_slowerDP` 的值。

`SlowestDP` 的 Get 访问器等待 5 秒后返回数据成员 `_slowestDP` 的值。

> 此示例仅供演示。 Microsoft .NET 准则不建议将比字段设置更慢的操作定义为属性。 有关详细信息，请参阅 [NIB：选择属性和方法](https://msdn.microsoft.com/library/55825e8f-7e2e-448a-9505-7217cc91b1af)。

```csharp
public class AsyncDataSource
{
  private string _fastDP;
  private string _slowerDP;
  private string _slowestDP;

  public AsyncDataSource()
  {
  }

  public string FastDP
  {
    get { return _fastDP; }
    set { _fastDP = value; }
  }

  public string SlowerDP
  {
    get
    {
      // This simulates a lengthy time before the
      // data being bound to is actualy available.
      Thread.Sleep(3000);
      return _slowerDP;
    }
    set { _slowerDP = value; }
  }

  public string SlowestDP
  {
    get
    {
      // This simulates a lengthy time before the
      // data being bound to is actualy available.
      Thread.Sleep(5000);
      return _slowestDP;
    }
    set { _slowestDP = value; }
  }
}
```

[Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.text) 属性使用 [PriorityBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.prioritybinding) 绑定到上述 `AsyncDS`:

```xaml
<Window.Resources>
  <c:AsyncDataSource SlowestDP="Slowest Value" SlowerDP="Slower Value"
                     FastDP="Fast Value" x:Key="AsyncDS" />
</Window.Resources>
  
<StackPanel HorizontalAlignment="Center" VerticalAlignment="Center"
  DataContext="{Binding Source={StaticResource AsyncDS}}">
  <TextBlock FontSize="18" FontWeight="Bold" Margin="10"
    HorizontalAlignment="Center">Priority Binding</TextBlock>
  <TextBlock Background="Honeydew" Width="100" HorizontalAlignment="Center">
    <TextBlock.Text>
      <PriorityBinding FallbackValue="defaultvalue">
        <Binding Path="SlowestDP" IsAsync="True"/>
        <Binding Path="SlowerDP" IsAsync="True"/>
        <Binding Path="FastDP" />
      </PriorityBinding>
    </TextBlock.Text>
  </TextBlock>	
</StackPanel>
```

绑定引擎在处理 [Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding) 对象时，会从已绑定到 `SlowestDP` 属性的第一个 [Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding) 开始。 处理此 [Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding) 时并未成功返回值，因为它正处于 5 秒的睡眠状态，因此会开始处理下一个 [Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding) 元素。 该 [Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding) 也没有成功返回值，因为它正处于 3 秒的睡眠状态。 绑定引擎随后会转至下一个 [Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding) 元素，该元素已绑定到 `FastDP` 属性。该 [Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding) 会返回值“Fast Value”。 于是 [TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock) 会显示值“Fast Value”。

3 秒后，`SlowerDP` 属性返回了值“Slower Value”。 于是 [TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock) 会显示值“Slower Value”。

5 秒后，`SlowestDP` 属性返回了值“Slowest Value”。 该绑定第一个列出，因此具有最高优先级。 于是 [TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)会显示值“Slowest Value”。

请参阅 [PriorityBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.prioritybinding)，了解“何为成功的绑定返回值” 相关信息。

#### [Bind to XML Data Using an XMLDataProvider and XPath Queries](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-bind-to-xml-data-using-an-xmldataprovider-and-xpath-queries)

此示例演示如何通过 [XmlDataProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.xmldataprovider) 绑定到 XML 数据。

使用 [XmlDataProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.xmldataprovider) 时，可以在应用程序中通过数据绑定访问的底层数据可以是任何 XML 节点树。 换言之，可以通过 [XmlDataProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.xmldataprovider) 很方便地将任何 XML 节点树用作绑定源。

##### 示例

在以下示例中，数据作为 XML 数据岛直接嵌入 [Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.resources) 节中。 XML 数据岛必须包装在 `<x:XData>` 标记中，并且始终有一个根节点，在本示例中根节点为 *Inventory*。

> XML 数据的根节点有一个将 XML 命名空间设置为空字符串的 **xmlns** 属性。 将 XPath 查询应用到 XAML 页中内联的数据岛时，需要此属性。 在本内联示例中，XAML 继承 [System.Windows](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows) 命名空间，数据岛也是如此。 因此，需要将命名空间设置为空，以防止 XPath 查询被限制在 [System.Windows](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows) 命名空间，从而误导查询。

```xaml
<StackPanel
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  Background="Cornsilk">

  <StackPanel.Resources>
    <XmlDataProvider x:Key="InventoryData" XPath="Inventory/Books">
      <x:XData>
        <Inventory xmlns="">
          <Books>
            <Book ISBN="0-7356-0562-9" Stock="in" Number="9">
              <Title>XML in Action</Title>
              <Summary>XML Web Technology</Summary>
            </Book>
            <Book ISBN="0-7356-1370-2" Stock="in" Number="8">
              <Title>Programming Microsoft Windows With C#</Title>
              <Summary>C# Programming using the .NET Framework</Summary>
            </Book>
            <Book ISBN="0-7356-1288-9" Stock="out" Number="7">
              <Title>Inside C#</Title>
              <Summary>C# Language Programming</Summary>
            </Book>
            <Book ISBN="0-7356-1377-X" Stock="in" Number="5">
              <Title>Introducing Microsoft .NET</Title>
              <Summary>Overview of .NET Technology</Summary>
            </Book>
            <Book ISBN="0-7356-1448-2" Stock="out" Number="4">
              <Title>Microsoft C# Language Specifications</Title>
              <Summary>The C# language definition</Summary>
            </Book>
          </Books>
          <CDs>
            <CD Stock="in" Number="3">
              <Title>Classical Collection</Title>
              <Summary>Classical Music</Summary>
            </CD>
            <CD Stock="out" Number="9">
              <Title>Jazz Collection</Title>
              <Summary>Jazz Music</Summary>
            </CD>
          </CDs>
        </Inventory>
      </x:XData>
    </XmlDataProvider>
  </StackPanel.Resources>

  <TextBlock FontSize="18" FontWeight="Bold" Margin="10"
    HorizontalAlignment="Center">XML Data Source Sample</TextBlock>
  <ListBox
    Width="400" Height="300" Background="Honeydew">
    <ListBox.ItemsSource>
      <Binding Source="{StaticResource InventoryData}"
               XPath="*[@Stock='out'] | *[@Number>=8 or @Number=3]"/>
    </ListBox.ItemsSource>

    <!--Alternatively, you can do the following. -->
    <!--<ListBox Width="400" Height="300" Background="Honeydew"
      ItemsSource="{Binding Source={StaticResource InventoryData},
      XPath=*[@Stock\=\'out\'] | *[@Number>\=8 or @Number\=3]}">-->

    <ListBox.ItemTemplate>
      <DataTemplate>
        <TextBlock FontSize="12" Foreground="Red">
          <TextBlock.Text>
            <Binding XPath="Title"/>
          </TextBlock.Text>
        </TextBlock>
      </DataTemplate>
    </ListBox.ItemTemplate>
  </ListBox>
</StackPanel>
```

如此示例中所示，若要使用属性语法创建相同的绑定声明，必须对特殊字符进行正确转义。 有关详细信息，请参阅 [XML 字符实体和 XAML](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/xml-character-entities-and-xaml)。

运行此示例时，[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 将显示以下项。 它们是 *Books* 中，*Stock* 值为“*out*”，或者 *Number* 值为 3 或者大于等于 8 的所有元素的 *Title*。 请注意，没有返回 *CD* 项，因为 [XmlDataProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.xmldataprovider) 中设置的 [XPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.xmldataprovider.xpath) 值指定了仅公开 *Books* 元素（实质上设置了一个筛选器）。

![XPath 示例](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/media/xpathexample.png)

在此示例中，显示书名是因为在 [DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate) 中，[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock) 绑定的 [XPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.xpath) 被设置为 "*Title*"。 若要显示某个属性（如 *ISBN*）的值，则可将该 [XPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.xpath) 值设置为 "`@ISBN`"。

WPF 中的 **XPath** 属性使用 XmlNode.SelectNodes 方法处理。 可以修改 **XPath** 查询以获取不同的结果。 以下是前一示例中被绑定 [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 的 [XPath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.xpath) 查询的一些示例：

- `XPath="Book[1]"` 将返回第一个 Book 元素（“XML in Action”）。 请注意，**XPath** 索引从 1 而不是从 0 开始。
- `XPath="Book[@*]"` 将返回带有任意属性的所有 Book 元素。
- `XPath="Book[last()-1]"` 将返回倒数第二个 Book 元素（“Introducing Microsoft .NET”）。
- `XPath="*[position()>3]"` 将返回除前 3 个元素之外的所有 Book 元素。

运行 **XPath** 查询时，它将返回 [XmlNode](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlnode) 或 XmlNode 的列表。 [XmlNode](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlnode) 是公共语言运行时 (CLR)对象，这意味着你可以使用 [Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.path) 属性来绑定到公共语言运行时 (CLR)属性。 再以上述示例为例。 如果该示例的其余部分保持不变，而你将 [TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock) 绑定更改为如下所示，则会在 [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 中看到返回的 XmlNode 的名称。 在此情况下，所有返回节点的名称为“*Book*”。

```xaml
<TextBlock FontSize="12" Foreground="Red">
  <TextBlock.Text>
    <Binding Path="Name"/>
  </TextBlock.Text>
</TextBlock>
```

在某些应用程序中，将 XML 作为 XAML 页面源码内的数据岛嵌入可能很不方便，因为在编译时必须知道该数据的确切内容。 因此，也支持从外部 XML 文件获取数据，如下面的示例所示：

```xaml
<XmlDataProvider x:Key="BookData" Source="data\bookdata.xml" XPath="Books"/>
```

如果 XML 数据驻留在远程 XML 文件中，则可通过指定 [Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.xmldataprovider.source) 属性的相应 URL 来定义对数据的访问权限，如下所示：

```xml
<XmlDataProvider x:Key="BookData" Source="http://MyUrl" XPath="Books"/>  
```

#### [Bind to XDocument, XElement, or LINQ for XML Query Results](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-bind-to-xdocument-xelement-or-linq-for-xml-query-results)

此示例演示如何使用 [XDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument) 将 XML 数据绑定到 [ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)。

##### 示例

下面的 XAML 代码定义了一个 [ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)，并在 `http://planetsNS` XML 命名空间中包括了一个数据模板，该模板适用于类型为 `Planet` 的数据。 占用命名空间的 XML 数据类型必须将命名空间括在大括号中，并且如果它出现在 XAML 标记扩展可能出现的位置，则还必须在相应命名空间前加上大括号转义序列。 此代码绑定到对应于[XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 类的 [Element](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.element) 与 [Attribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.attribute) 方法的动态属性。 借助动态属性，XAML 可以绑定到共享方法名称的动态属性。 有关详细信息，请参阅 [LINQ to XML 动态属性](https://docs.microsoft.com/zh-cn/visualstudio/designers/linq-to-xml-dynamic-properties)。 请注意 XML 的默认命名空间声明为何不适用于特性名。

```xaml
<StackPanel Name="stacky">
  <StackPanel.Resources>
    <DataTemplate DataType="{}{http://planetsNS}Planet" >
      <StackPanel Orientation="Horizontal">
        <TextBlock Width="100" Text="{Binding Path=Element[{http://planetsNS}DiameterKM].Value}" />
        <TextBlock Width="100" Text="{Binding Path=Attribute[Name].Value}" />
        <TextBlock Text="{Binding Path=Element[{http://planetsNS}Details].Value}" /> 
      </StackPanel>
    </DataTemplate>
  </StackPanel.Resources>
```

```xaml
  <ItemsControl 
    ItemsSource="{Binding }" >
  </ItemsControl>
</StackPanel>
```

下面的 C# 代码调用 [Load](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xdocument.load) 并将堆栈面板的数据上下文设置为 `http://planetsNS` XML 命名空间中名为 `SolarSystemPlanets` 的元素的所有子元素。

```csharp
planetsDoc = XDocument.Load("../../Planets.xml");
stacky.DataContext = planetsDoc.Element("{http://planetsNS}SolarSystemPlanets").Elements();
```

XML 数据可以使用 [ObjectDataProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.objectdataprovider) 存储为 XAML 资源。 有关完整示例，请参阅 [L2DBForm.xaml 源代码](https://msdn.microsoft.com/library/624e96d4-6d27-4195-8ac2-2f3835f6c57e)。 下面的示例演示代码如何将数据上下文设置为对象资源。

```csharp
planetsDoc = (XDocument)((ObjectDataProvider)Resources["justTwoPlanets"]).Data;
stacky.DataContext = planetsDoc.Element("{http://planetsNS}SolarSystemPlanets").Elements();
```

映射到 [Element](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xcontainer.element) 和 [Attribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement.attribute) 的动态属性在 XAML 中非常灵活。 代码还可以绑定到 LINQ for XML 查询的结果。 此示例绑定到按元素值排序的查询结果。

```csharp
stacky.DataContext =
from c in planetsDoc.Element("{http://planetsNS}SolarSystemPlanets").Elements()
orderby Int32.Parse(c.Element("{http://planetsNS}DiameterKM").Value)
select c;
```

#### [Use XML Namespaces in Data Binding](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-use-xml-namespaces-in-data-binding)

##### 示例

本示例演示如何处理在 XML 绑定源中指定的命名空间。

如果 XML 数据具有以下 XML 命名空间定义：

```
<rss version="2.0" xmlns:dc="http://purl.org/dc/elements/1.1/">
```

可以使用[XmlNamespaceMapping](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.xmlnamespacemapping)元素将映射到命名空间[Prefix](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.xmlnamespacemapping.prefix)，如下面的示例。 然后，可以使用[Prefix](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.xmlnamespacemapping.prefix)来指代XML命名空间。 [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)在此示例中显示*标题*并*标题*每个*项*。

```xaml
<StackPanel.Resources>
  <XmlNamespaceMappingCollection x:Key="mapping">
    <XmlNamespaceMapping Uri="http://purl.org/dc/elements/1.1/" Prefix="dc" />
  </XmlNamespaceMappingCollection>

  <XmlDataProvider Source="http://msdn.microsoft.com/subscriptions/rss.xml"
                   XmlNamespaceManager="{StaticResource mapping}"
                   XPath="rss/channel/item" x:Key="provider"/>

  <DataTemplate x:Key="dataTemplate">
    <Border BorderThickness="1" BorderBrush="Gray">
      <Grid Width="600" Height="50">
        <Grid.RowDefinitions>
          <RowDefinition Height="25"/>
          <RowDefinition Height="25"/>
        </Grid.RowDefinitions>
        <TextBlock Grid.Row="0" Text="{Binding XPath=title}" />
        <TextBlock Grid.Row="1" Text="{Binding XPath=dc:date}" />
      </Grid>
    </Border>
  </DataTemplate>
</StackPanel.Resources>

<ListBox
  Width="600"
  Height="600"
  Background="Honeydew"
  ItemsSource="{Binding Source={StaticResource provider}}"
  ItemTemplate="{StaticResource dataTemplate}"/>
```

请注意，[Prefix](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.xmlnamespacemapping.prefix)指定不需要匹配中使用的一个XML源; 如果前缀中的更改XML源映射仍然正常工作。

在此特定示例中，XML数据来自于 web 服务，但[XmlNamespaceMapping](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.xmlnamespacemapping)元素还处理内联XML或XML嵌入的文件中的数据。

#### [Bind to an ADO.NET Data Source](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-bind-to-an-ado-net-data-source)

此示例演示如何将 Windows Presentation Foundation (WPF) [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 控件绑定到 ADO.NET `DataSet`。

##### 示例

在本示例中，`OleDbConnection` 对象用于连接到数据源，该数据源是在连接字符串中指定的 `Access MDB` 文件。建立连接后，会创建一个 `OleDbDataAdpater` 对象。 `OleDbDataAdpater` 对象执行一个 select 结构化查询语言 (SQL)语句，以便从数据库中检索记录集。 通过调用 `OleDbDataAdapter` 的 `Fill` 方法，可将此 SQL 命令的结果存储在 `DataSet` 的 `DataTable` 中。 本示例中，`DataTable` 命名为 `BookTable`。 然后，该示例将 [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 的[DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext) 属性设置为 `DataSet` 对象。

```csharp
DataSet myDataSet;

private void OnInit(object sender, EventArgs e)
{
  string mdbFile = Path.Combine(AppDataPath, "BookData.mdb");
  string connString = string.Format(
      "Provider=Microsoft.Jet.OLEDB.4.0; Data Source={0}", mdbFile);
  OleDbConnection conn = new OleDbConnection(connString);
  OleDbDataAdapter adapter = new OleDbDataAdapter("SELECT * FROM BookTable;", conn);

  myDataSet = new DataSet();
  adapter.Fill(myDataSet, "BookTable");

  // myListBox is a ListBox control.
  // Set the DataContext of the ListBox to myDataSet
  myListBox.DataContext = myDataSet;
}
```

然后，我们可以将 [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 的 [ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource) 属性绑定到 `DataSet` 的 `BookTable`:

```xaml
<ListBox Name="myListBox" Height="200"
  ItemsSource="{Binding Path=BookTable}"
  ItemTemplate  ="{StaticResource BookItemTemplate}"/>
```

`BookItemTemplate` 是定义数据显示方式的 [DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)：

```xaml
<StackPanel.Resources>
  <c:IntColorConverter x:Key="MyConverter"/>

  <DataTemplate x:Key="BookItemTemplate">
    <Grid>
      <Grid.ColumnDefinitions>
        <ColumnDefinition Width="250" />
        <ColumnDefinition Width="100" />
        <ColumnDefinition Width="*"/>
      </Grid.ColumnDefinitions>
      <TextBlock Text="{Binding Path=Title}" Grid.Column="0"
        FontWeight="Bold" />
      <TextBlock Text="{Binding Path=ISBN}" Grid.Column="1" />
      <TextBlock Grid.Column="2" Text="{Binding Path=NumPages}"
                 Background="{Binding Path=NumPages,
          Converter={StaticResource MyConverter}}"/>
    </Grid>
  </DataTemplate>
</StackPanel.Resources>
```

`IntColorConverter` 将 `int` 转换为颜色。 通过使用此转换器，如果 `NumPages` 的值小于 350，第三个 [TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)的 [Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.background) 颜色将显示为绿色，否则为红色。 此处未展示该转换器的实现。

#### [Bind to a Method](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-bind-to-a-method)

下面的示例演示如何将绑定到方法使用[ObjectDataProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.objectdataprovider)。

##### 示例

在本示例中，`TemperatureScale` 是一个具有 `ConvertTemp` 方法的类，该方法接收两个参数（分别为 `double` 和 `enum` 类型的 `TempType)`），将给定值从一个温标转换为另一个温标。 在以下示例中，[ObjectDataProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.objectdataprovider) 用来实例化 `TemperatureScale` 对象。 将使用两个指定参数调用 `ConvertTemp` 方法。

```xaml
<Window.Resources>
  <ObjectDataProvider ObjectType="{x:Type local:TemperatureScale}"
                      MethodName="ConvertTemp" x:Key="convertTemp">
    <ObjectDataProvider.MethodParameters>
      <system:Double>0</system:Double>
      <local:TempType>Celsius</local:TempType>
    </ObjectDataProvider.MethodParameters>
  </ObjectDataProvider>

  <local:DoubleToString x:Key="doubleToString" />

</Window.Resources>
```

现在此方法可以作为资源使用，因此可绑定到其结果。 在以下示例中，[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 的 [Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.text) 属性和 [ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox) 的 [SelectedValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.selector.selectedvalue) 绑定到该方法的两个参数。 这样用户就可以指定要转换的温度以及要从哪个温标进行转换。 注意，[BindsDirectlyToSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.bindsdirectlytosource) 设置为 `true` 是因为我们要绑定到 [ObjectDataProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.objectdataprovider) 实例的 [MethodParameters](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.objectdataprovider.methodparameters) 属性，而不是由 [ObjectDataProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.objectdataprovider) 包装的对象（`TemperatureScale`对象）的属性。

最后一个 [Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label) 的 [Content](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.content) 会在用户修改 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 的内容或 [ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox) 的选项时更新。

```xaml
<Label Grid.Row="1" HorizontalAlignment="Right">Enter the degree to convert:</Label>
<TextBox Grid.Row="1" Grid.Column="1" Name="tb">
  <TextBox.Text>
    <Binding Source="{StaticResource convertTemp}" Path="MethodParameters[0]"
             BindsDirectlyToSource="true" UpdateSourceTrigger="PropertyChanged"
             Converter="{StaticResource doubleToString}">
      <Binding.ValidationRules>
        <local:InvalidCharacterRule/>
      </Binding.ValidationRules>
    </Binding>
  </TextBox.Text>
</TextBox>
<ComboBox Grid.Row="1" Grid.Column="2" 
  SelectedValue="{Binding Source={StaticResource convertTemp},
  Path=MethodParameters[1], BindsDirectlyToSource=true}">
  <local:TempType>Celsius</local:TempType>
  <local:TempType>Fahrenheit</local:TempType>
</ComboBox>
<Label Grid.Row="2" HorizontalAlignment="Right">Result:</Label>
<Label Content="{Binding Source={StaticResource convertTemp}}"
    Grid.Row="2" Grid.Column="1" Grid.ColumnSpan="2"/>
```

`DoubleToString` 转换器在 [Convert](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.ivalueconverter.convert) 方向接受一个双精度值并将其转换为字符串（从绑定源到绑定目标，后者为 [Text](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox.text) 属性），在[ConvertBack](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.ivalueconverter.convertback) 方向将 `string` 转换为 `double`。

`InvalidationCharacterRule` 是一个 [ValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule)，用于检查无效字符。 当输入值不是一个 `double` 值时，默认错误模板（一个围绕 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) 的红色边框）将出现，对用户进行通知。

#### [Set Up Notification of Binding Updates](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-set-up-notification-of-binding-updates)

本示例演示如何设置在绑定的绑定目标（目标）或绑定源（源）属性更新时收到通知。

#### 示例

Windows Presentation Foundation (WPF) 在每次更新绑定源或目标时都会引发数据更新事件。 从内部来看，此事件用于通知用户界面 用户界面 (UI) 执行更新，因为绑定数据已更改。 注意，要确保这些事件起作用，并确保单向或双向绑定正常工作，需要使用 [INotifyPropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.inotifypropertychanged) 接口实现数据类。 有关详细信息，请参阅[实现属性更改通知](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-implement-property-change-notification)。

将绑定中的 [NotifyOnTargetUpdated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.notifyontargetupdated) 或 [NotifyOnSourceUpdated](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.notifyonsourceupdated) 属性（或两者）设置为 `true`。 提供的用于侦听此事件的处理程序必须直接附加到希望收到更改通知的元素，但如果希望在上下文中的任何内容发生变化时得到通知，则必须附加到整个数据上下文。

下面的示例演示如何设置当目标属性更新时收到通知。

```xaml
<TextBlock Grid.Row="1" Grid.Column="1" Name="RentText"
  Text="{Binding Path=Rent, Mode=OneWay, NotifyOnTargetUpdated=True}"
  TargetUpdated="OnTargetUpdated"/>
```

然后，可以根据 EventHandler<T> 委托（在本示例中为 *OnTargetUpdated*）分配处理程序来处理该事件：

```csharp
private void OnTargetUpdated(Object sender, DataTransferEventArgs args)
{

  // Handle event
```

```csharp
}
```

事件的参数可用于确定已更改属性的详细信息（例如，如果同一处理程序附加到多个元素，则可确定类型或特定元素信息），如果在单个元素上有多个绑定属性，则这些详细信息将很有用。

#### [Clear Bindings](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-clear-bindings)

此示例演示如何从对象中清除绑定。

##### 示例

若要从对象中某一个属性清除绑定，可以调用 [ClearBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingoperations.clearbinding)，如以下示例所示。 以下示例将从 mytext（[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)对象）的 [TextProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.textproperty) 删除绑定。

```csharp
BindingOperations.ClearBinding(myText, TextBlock.TextProperty);
```

清除绑定会移除绑定，这样依赖属性的值会更改为过去尚未绑定时的值。 此值可以是默认值、继承值或来自数据模板绑定的值。

若要清除一个对象的所有可操作属性的绑定，请使用 [ClearAllBindings](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindingoperations.clearallbindings)。

#### [Find DataTemplate-Generated Elements](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-find-datatemplate-generated-elements)

此示例演示如何查找由 [DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate) 生成的元素。

##### 示例

在此示例中，有一个 [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 已绑定到一些 XML 数据：

```xaml
<ListBox Name="myListBox" ItemTemplate="{StaticResource myDataTemplate}"
         IsSynchronizedWithCurrentItem="True">
  <ListBox.ItemsSource>
    <Binding Source="{StaticResource InventoryData}" XPath="Books/Book"/>
  </ListBox.ItemsSource>
</ListBox>
```

[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox) 使用以下 [DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate):

```xaml
<DataTemplate x:Key="myDataTemplate">
  <TextBlock Name="textBlock" FontSize="14" Foreground="Blue">
    <TextBlock.Text>
      <Binding XPath="Title"/>
    </TextBlock.Text>
  </TextBlock>
</DataTemplate>
```

如果想要检索由特定 [ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem) 的 [DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate) 生成的 [TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock) 元素，需要先获取 [ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)，在该 [ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem) 中查找 [ContentPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter)，然后在该 [ContentPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter) 设置的 [DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate) 上调用 [FindName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworktemplate.findname) 。 以下示例演示如何执行这些步骤。 出于演示目的，此示例会创建一个消息框，显示 [DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate) 生成的文本块的文本内容。

```csharp
// Getting the currently selected ListBoxItem
// Note that the ListBox must have
// IsSynchronizedWithCurrentItem set to True for this to work
ListBoxItem myListBoxItem =
    (ListBoxItem)(myListBox.ItemContainerGenerator.ContainerFromItem(myListBox.Items.CurrentItem));

// Getting the ContentPresenter of myListBoxItem
ContentPresenter myContentPresenter = FindVisualChild<ContentPresenter>(myListBoxItem);

// Finding textBlock from the DataTemplate that is set on that ContentPresenter
DataTemplate myDataTemplate = myContentPresenter.ContentTemplate;
TextBlock myTextBlock = (TextBlock)myDataTemplate.FindName("textBlock", myContentPresenter);

// Do something to the DataTemplate-generated TextBlock
MessageBox.Show("The text of the TextBlock of the selected list item: "
    + myTextBlock.Text);
```

以下是 `FindVisualChild` 的实现，使用了 [VisualTreeHelper](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualtreehelper) 方法：

```csharp
private childItem FindVisualChild<childItem>(DependencyObject obj)
    where childItem : DependencyObject
{
    for (int i = 0; i < VisualTreeHelper.GetChildrenCount(obj); i++)
    {
        DependencyObject child = VisualTreeHelper.GetChild(obj, i);
        if (child != null && child is childItem)
            return (childItem)child;
        else
        {
            childItem childOfChild = FindVisualChild<childItem>(child);
            if (childOfChild != null)
                return childOfChild;
        }
    }
    return null;
}
```

#### [Bind to a Web Service](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-bind-to-a-web-service)

此示例演示如何将绑定到由 Web 服务方法调用返回的对象。

##### 示例

此示例使用[MSDN/TechNet 发布系统 (MTPS) Content Service](https://go.microsoft.com/fwlink/?LinkId=95677)检索支持指定的文档的语言的列表。

在调用 Web 服务之前，需要创建对它的引用。 若要创建对 MTPS 服务使用的 Web 引用Microsoft Visual Studio，请执行以下步骤：

1. 在 Visual Studio 中打开项目。
2. 从**项目**菜单上，单击**添加 Web 引用**。
3. 在对话框中，将 **URL** 设置为 [http://services.msdn.microsoft.com/contentservices/contentservice.asmx?wsdl](https://services.msdn.microsoft.com/contentservices/contentservice.asmx?wsdl)。
4. 按“转到”，然后按“添加引用”。

接下来，调用 Web 服务方法并将相应控件或窗口的 [DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext) 设置为返回的对象。 MTPS 服务的 **GetContent**方法将引用 **getContentRequest** 对象。 因此，下面的示例首先设置请求对象：

```csharp
// 1. Include the web service namespace
using BindtoContentService.com.microsoft.msdn.services;
```

```csharp
// 2. Set up the request object
// To use the MSTP web service, we need to configure and send a request
// In this example, we create a simple request that has the ID of the XmlReader.Read method page
getContentRequest request = new getContentRequest();
request.contentIdentifier = "abhtw0f1";

// 3. Create the proxy
ContentService proxy = new ContentService();

// 4. Call the web service method and set the DataContext of the Window
// (GetContent returns an object of type getContentResponse)
this.DataContext = proxy.GetContent(request);
```

[DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext) 设置完成后，即可创建对特定对象（已将 [DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext) 设置为此对象）的属性的绑定。 在此示例中，[DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext) 设置为 **GetContent** 方法返回的 **getContentResponse** 对象。 在以下示例中，[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol) 绑定到 **getContentResponse** 的 **availableVersionsAndLocales** 的 **locale** 值并显示这些值。

```xaml
<ItemsControl Grid.Column="1" Grid.Row="2" Margin="0,3,0,0"
              ItemsSource="{Binding Path=availableVersionsAndLocales}"
              DisplayMemberPath="locale"/>
```

有关 **getContentResponse** 结构的信息，请参阅[内容服务文档](https://services.msdn.microsoft.com/ContentServices/ContentService.asmx)。

#### [Bind to the Results of a LINQ Query](https://docs.microsoft.com/en-us/dotnet/framework/wpf/data/how-to-bind-to-the-results-of-a-linq-query)

此示例演示如何运行 LINQ 查询，然后绑定到结果。

##### 示例

以下示例创建两个列表框。 第一个列表框包含三个列表项。

```xaml
<ListBox SelectionChanged="ListBox_SelectionChanged"
         SelectedIndex="0" Margin="10,0,10,0" >
    <ListBoxItem>1</ListBoxItem>
    <ListBoxItem>2</ListBoxItem>
    <ListBoxItem>3</ListBoxItem>
</ListBox>
<ListBox Width="400" Margin="10" Name="myListBox"
         HorizontalContentAlignment="Stretch"
         ItemsSource="{Binding}"
         ItemTemplate="{StaticResource myTaskTemplate}"/>
```

从第一个列表框中选择一项即可调用以下事件处理程序。 在此示例中，`Tasks` 是一系列 `Task` 对象。 `Task` 类有一个名为 `Priority` 的属性。 此事件处理程序会运行 LINQ 查询，返回具有所选优先级值的 `Task` 对象集合，然后将其设置为 [DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext):

```csharp
using System.Linq;
```

```csharp
Tasks tasks = new Tasks();
```

```csharp
private void ListBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
{
    int pri = Int32.Parse(((sender as ListBox).SelectedItem as ListBoxItem).Content.ToString());

    this.DataContext = from task in tasks
                       where task.Priority == pri
                       select task;
}
```

第二个列表框将绑定到该集合，因为其 [ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource) 值设置为 `{Binding}`。 因此，它将显示返回的集合（基于 `myTaskTemplate` [DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)）。