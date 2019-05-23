# [Drag and Drop](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/drag-and-drop)

Windows Presentation Foundation (WPF) 提供高度灵活拖放基础结构支持拖放数据内均WPF应用程序以及其他Windows应用程序。

[拖放概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/drag-and-drop-overview)
[数据和数据对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/data-and-data-objects)
[演练：在用户控件上启用拖放功能](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/walkthrough-enabling-drag-and-drop-on-a-user-control)
[帮助主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/drag-and-drop-how-to-topics)

## [Drag and Drop Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/drag-and-drop-overview)

本主题概述 Windows Presentation Foundation (WPF) 应用程序中的拖放支持。 拖放通常指一种数据传输方法：使用鼠标（或一些其他指针设备）选择一个或多个对象，将其拖至 用户界面 (UI) 中的某些所需拖放目标之上并放置。

### WPF 中的拖放支持

拖放操作通常涉及两个参与方：拖动对象所源自的拖动源和接收放置对象的拖放目标。 拖动源和放置目标可能是相同应用程序或不同应用程序中的 UI 元素。

可借助拖放操纵的对象的类型和数量是完全任意的。 例如，文件、文件夹和内容选择是利用拖放操作操纵的一些常见对象。

拖放操作期间执行的特定操作特定于应用程序，并且通常由上下文而定。 例如，将选择的文件从一个文件夹一拖动至相同存储设备上的另一个文件夹将默认移动文件；而将文件从 通用命名约定 (UNC) 共享拖动至本地文件夹将默认复制文件。

WPF 提供的拖放设施拥有高度的灵活性并可自定义，以便支持各种拖放方案。 拖放支持在单个应用程序内或不同应用程序之间操作对象。 拖放之间WPF也完全支持应用程序和其他 Windows 应用程序。

在 WPF 中，任何 [UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement) 或 [ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement) 都可以参与拖放。 拖放操作所需的事件和方法是在 [DragDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop) 类中定义的。 [UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement) 和 [ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement) 类包含 [DragDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop) 附加事件的别名，从而在 [UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement) 或 [ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement) 作为基元素继承时，这些事件出现在类成员列表中。 附加到这些事件的事件处理程序会附加到基础 [DragDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop) 附加事件，并接收相同的事件数据实例。 有关详细信息，请参阅 [UIElement.Drop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.drop) 事件。

> 在 Internet 区域中 OLE 拖放无效。

### 数据传输

拖放属于广义的数据传输。 数据传输包括拖放和复制粘贴操作。 拖放操作类似于用于借助系统剪贴板将数据从一个对象或应用程序传输到另一个对象或应用程序的复制粘贴或剪切和粘贴操作。 这两种类型的操作均要求：

- 提供数据的源对象。
- 用于临时存储传输的数据的方法。
- 接收数据的目标对象。

在复制粘贴操作中，系统剪贴板用于临时存储传输的数据；在拖放操作中，[DataObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject) 用于存储数据。 从概念上讲，数据对象由一对或多对包含实际数据的 [Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object) 和对应的数据格式标识符组成。

拖动源通过调用静态 [DragDrop.DoDragDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dodragdrop) 方法和向其传递传输的数据来启动拖放操作。 如有必要，[DoDragDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dodragdrop) 方法将使 [DataObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject) 中的数据自动换行。 为了更好地控制数据格式，可将 [DataObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject) 中的数据换行，然后再将其传递至 [DoDragDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dodragdrop) 方法。 拖放目标负责从 [DataObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject) 中提取数据。 有关使用数据对象的详细信息，请参阅[数据和数据对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/data-and-data-objects)。

拖放操作的源和目标均为 UI 元素；然而，实际正在传输的数据通常不具有可视表示形式。 可以编写代码来提供拖动的数据的可视表示形式（比如当在 Windows 资源管理器中拖动文件时会出现这种情况）。 默认情况下，通过更改光标将反馈提供给用户，以便表示拖放操作将对数据产生的影响，例如将移动数据还是复制数据。

#### 拖放效果

拖放操作对传输的数据可具有不同的效果。 例如，可以复制数据，或者可以移动数据。 WPF 定义可用于指定拖放操作效果的 [DragDropEffects](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdropeffects) 枚举。 在拖动源中，可以指定源在 [DoDragDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dodragdrop) 方法中允许的效果。 在拖放目标中，可以指定目标在 [Effects](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.drageventargs.effects) 类的 [DragEventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.drageventargs) 属性的中预期的效果。 当拖放目标指定其在 [DragOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dragover) 事件中的预期效果时，该信息将被传递回 [GiveFeedback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.givefeedback) 事件中的拖动源。 拖动源则使用此信息通知用户拖放目标想要对数据产生的效果。 放置数据时，拖放目标指定其在 [Drop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.drop) 事件中的实际效果。 该信息会作为 [DoDragDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dodragdrop) 方法的返回值传递回拖动源。 如果拖放目标返回并不在 `allowedEffects` 拖动源列表中的效果，那么将取消拖放操作，且不会进行任何数据传输。

请务必记住，在 WPF 中，[DragDropEffects](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdropeffects) 值仅用于提供有关拖放操作效果的拖动源和拖放目标之间的通信。 拖放操作的实际效果取决于你在应用程序中编写的相应代码。

例如，拖放目标可以指定在其中放置数据的效果是移动数据。 然而，若要移动数据，必须将数据添加到目标元素并从源元素中删除数据。 源元素可能指示允许移动数据，但是如果没有提供从源元素中删除数据的代码，那么最终结果将为复制但不删除数据。



### 拖放事件

拖放操作支持事件驱动模型。 拖动源和拖放目标都使用一组标准的事件来处理拖放操作。 下表总结了标准的拖放事件。 它们是 [DragDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop) 类中的附加事件。 有关附加事件的详细信息，请参阅[附加事件概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/attached-events-overview)。

#### 拖动源事件

| Event                                                        | 总结                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [GiveFeedback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.givefeedback) | 此事件在拖放操作期间持续发生，并且使放置源能够向用户提供反馈信息。 通常通过更改鼠标指针外观来指示拖放目标允许的效果这一方式来提供这种反馈。 这是冒泡事件。 |
| [QueryContinueDrag](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.querycontinuedrag) | 此事件于拖放操作期间键盘或鼠标按钮状态发生变化时发生，并使放置源能够根据键/按钮状态取消拖放操作。 这是冒泡事件。 |
| [PreviewGiveFeedback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.previewgivefeedback) | [GiveFeedback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.givefeedback) 的隧道版本。 |
| [PreviewQueryContinueDrag](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.previewquerycontinuedrag) | [QueryContinueDrag](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.querycontinuedrag) 的隧道版本。 |

#### 拖放目标事件

| Event                                                        | 总结                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [DragEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dragenter) | 将对象拖到拖放目标的边界中时发生此事件。 这是冒泡事件。      |
| [DragLeave](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dragleave) | 将对象拖出拖放目标边界时发生此事件。 这是冒泡事件。          |
| [DragOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dragover) | 在拖放目标的边界内拖动（移动）对象时会持续发生此事件。 这是冒泡事件。 |
| [Drop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.drop) | 将对象放置在拖放目标上时发生此事件。 这是冒泡事件。          |
| [PreviewDragEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.previewdragenter) | [DragEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dragenter) 的隧道版本。 |
| [PreviewDragLeave](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.previewdragleave) | [DragLeave](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dragleave) 的隧道版本。 |
| [PreviewDragOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.previewdragover) | [DragOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dragover) 的隧道版本。 |
| [PreviewDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.previewdrop) | [Drop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.drop) 的隧道版本。 |

若要处理对象实例的拖放事件，请为上表中所列的事件添加处理程序。 若要处理类级别的拖放事件，请替代相应的虚拟 On*Event 和 On*PreviewEvent 方法。 有关详细信息，请参阅[按控件基类进行的路由事件类处理](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/marking-routed-events-as-handled-and-class-handling#Class_Handling_of_Routed_Events)。

### 实现拖放

UI 元素可以是拖动源、拖放目标或两者均可。 若要实现基本拖放，请编写用于启动拖放操作和处理放置的数据的代码。 可以通过处理可选拖放事件增强拖放体验。

若要实现基本拖放，将完成以下任务：

- 标识将作为拖动源的元素。 拖动源可以是 [UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement) 或 [ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement)。
- 在将启动拖放操作的拖动源上创建事件处理程序。 此事件通常是 [MouseMove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mousemove) 事件。
- 在拖动源事件处理程序中，调用 [DoDragDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dodragdrop) 方法启动拖放操作。 在 [DoDragDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dodragdrop) 调用中，指定拖动源、要传输的数据和允许的效果。
- 标识将作为拖放目标的元素。 拖放目标可以是 [UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement) 或 [ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement)。
- 在拖放目标上，将 [AllowDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.allowdrop) 属性设置为 `true`。
- 在拖放目标中，创建 [Drop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.drop) 事件处理程序以处理放置的数据。
- 在 [Drop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.drop) 事件处理程序中，利用 [DragEventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.drageventargs) 和 [GetDataPresent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.getdatapresent) 方法提取 [GetData](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.getdata) 中的数据。
- 在 [Drop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.drop) 事件处理程序中，使用数据来执行所需的拖放操作。

可以通过创建自定义 [DataObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject) 和处理可选拖动源和拖放目标事件来增加拖放实现，如以下任务中所示：

- 若要传输自定义数据或多个数据项，请创建一个 [DataObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject)以传递至 [DoDragDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dodragdrop) 方法。
- 若要在拖动过程中执行其他操作，请处理拖放目标上的 [DragEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dragenter)[DragOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dragover) 和 [DragLeave](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dragleave) 事件。
- 若要更改鼠标指针外观，请处理拖动源上的 [GiveFeedback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.givefeedback) 事件。
- 若要更改取消拖放操作的方式，请处理拖动源上的 [QueryContinueDrag](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.querycontinuedrag) 事件。

### 拖放示例

本节介绍如何实现 [Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse) 元素的拖放。 [Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse) 既是拖动源也是拖放目标。 传输的数据是椭圆形的 [Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill) 属性的字符串表示形式。 下面的 XAML 展示 [Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse) 元素和它处理的拖放相关事件。 有关如何实现拖放的完整步骤，请参阅[演练：对用户控件启用拖放](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/walkthrough-enabling-drag-and-drop-on-a-user-control)。

```xaml
<Ellipse Height="50" Width="50" Fill="Green"
     MouseMove="ellipse_MouseMove"
     GiveFeedback="ellipse_GiveFeedback"
     AllowDrop="True"
     DragEnter="ellipse_DragEnter" DragLeave="ellipse_DragLeave"
     DragOver="ellipse_DragOver" Drop="ellipse_Drop" />
```

#### 使元素作为拖动源

拖动源对象用于：

- 标识拖动发生的时候。
- 启动拖放操作。
- 标识要传输的数据。
- 指定允许拖放操作对传输的数据产生的效果。

拖动源还可能针对允许的操作（移动、复制、无）向用户提供反馈，并且可以根据额外用户输入（如拖动过程中按 ESC 键）取消拖放操作。

你的应用程序负责确定发生拖动的时间，然后通过调用 [DoDragDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dodragdrop) 方法启动拖放操作。 通常情况下，这是在按下鼠标按钮的同时，要拖动的元素上发生 [MouseMove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mousemove) 事件时。 下面的示例显示了如何从 [MouseMove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mousemove) 元素的 [Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse) 事件处理程序中启动拖放操作，以将其作为拖动源。 传输的数据是椭圆形的 [Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill) 属性的字符串表示形式。

C#复制

```csharp
private void ellipse_MouseMove(object sender, MouseEventArgs e)
{
    Ellipse ellipse = sender as Ellipse;
    if (ellipse != null && e.LeftButton == MouseButtonState.Pressed)
    {
        DragDrop.DoDragDrop( ellipse,
                             ellipse.Fill.ToString(),
                             DragDropEffects.Copy);
    }
}
```

在 [MouseMove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mousemove) 事件处理程序中，调用 [DoDragDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dodragdrop) 方法启动拖放操作。 [DoDragDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dodragdrop) 方法采用三个参数：

- `dragSource` – 引用作为传输的数据的源的依赖项对象；通常是 [MouseMove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mousemove) 事件的源。
- `data` - 包含传输的数据（包装在 [DataObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject) 中）的对象。
- `allowedEffects` - 指定拖放操作允许的效果的 [DragDropEffects](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdropeffects) 枚举值之一。

任何可序列化对象都可以在 `data` 参数中传递。 如果数据尚未包装在 [DataObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject) 中，则它将自动包装在一个新的 [DataObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject) 中。 若要传递多个数据项，必须自行创建 [DataObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject)，并将其传递到 [DoDragDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dodragdrop) 方法。 有关详细信息，请参阅[数据和数据对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/data-and-data-objects)。

`allowedEffects` 参数用于指定拖动源允许拖放目标对传输的数据进行什么操作。 拖动源公共值为 [Copy](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdropeffects#System_Windows_DragDropEffects_Copy)[Move](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdropeffects#System_Windows_DragDropEffects_Move) 和[All](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdropeffects#System_Windows_DragDropEffects_All)。

 备注

拖放目标也能够指定其对放置的数据的预期效果。 例如，如果拖放目标不能识别要放置的数据类型，则可以通过将其允许的效果设置为 [None](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdropeffects#System_Windows_DragDropEffects_None) 来拒绝数据。 通常在其 [DragOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dragover) 事件处理程序中进行此操作。

拖动源还可以可选地处理 [GiveFeedback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.givefeedback) 和 [QueryContinueDrag](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.querycontinuedrag) 事件。 这些事件都具有使用的默认处理程序，除非将事件标记为已处理。 通常将忽略这些事件，除非有更改其默认行为的特定需要。

对拖动源进行拖动时，持续引发 [GiveFeedback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.givefeedback) 事件。 此事件的默认处理程序会检查拖动源是否在有效拖放目标之上。 如果是，它会检查拖放目标的允许的效果。 然后向最终用户提供有关允许的放置效果的反馈。 通常通过将鼠标光标更改为非放置、复制或移动光标实现此操作。 仅在需要使用自定义光标向用户提供反馈时处理此事件。 在处理此事件时，请务必将其标记为“已处理”，以便默认处理程序不会替代你的处理程序。

对拖动源进行拖动时，持续引发 [QueryContinueDrag](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.querycontinuedrag) 事件。 你可以根据 ESC、SHIFT、CTRL 和 ALT 键以及鼠标按钮的状态处理此事件，以确定结束拖放操作的操作。 此事件的默认处理程序在按下 ESC 键后取消拖放操作，并且在释放鼠标按钮后放置数据。

 注意

在拖放操作过程中，将持续引发这些事件。 因此，应避免事件处理程序中的资源密集型任务。 例如，每次引发 [GiveFeedback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.givefeedback) 事件时，请使用缓存的光标，而不是创建新光标。

#### 使元素作为拖放目标

作为拖放目标的对象用于：

- 指定其是有效的拖放目标。
- 当它拖动到目标之上时，向拖动源作出响应。
- 检查传输的数据是否是它可以接收的格式。
- 处理已放置的数据。

若要指定一个元素是拖放目标，请将其 [AllowDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.allowdrop) 属性设置为 `true`。 然后，元素中将引发拖放目标事件，以便处理这些事件。 在拖放操作期间，拖放目标上将依次发生以下事件：

1. [DragEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dragenter)
2. [DragOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dragover)
3. [DragLeave](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dragleave) 或 [Drop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.drop)

将数据拖到拖放目标的边界中时发生 [DragEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dragenter) 事件。 通常，如果适用于你的应用程序，可处理此事件，以便提供拖放操作效果预览。 请勿设置 [DragEventArgs.Effects](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.drageventargs.effects) 事件中的 [DragEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dragenter) 属性，因为在 [DragOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dragover) 事件中该属性将被覆盖。

下面的示例演示 [Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse) 元素的 [DragEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dragenter) 事件处理程序。 此代码通过保存当前的 [Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill) 画笔预览拖放操作的效果。然后，它使用 [GetDataPresent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.getdatapresent) 方法来检查是否已将 [DataObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject) 拖动到包含可以转换为 [Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush) 的字符串数据的椭圆上方。 如果是，则使用 [GetData](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.getdata) 方法提取数据。 然后将其转换为 [Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush) 并应用于椭圆。 在 [DragLeave](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dragleave) 事件处理程序中还原更改。 如果数据无法转换为 [Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)，则不执行任何操作。

C#复制

```csharp
private Brush _previousFill = null;
private void ellipse_DragEnter(object sender, DragEventArgs e)
{
    Ellipse ellipse = sender as Ellipse;
    if (ellipse != null)
    {
        // Save the current Fill brush so that you can revert back to this value in DragLeave.
        _previousFill = ellipse.Fill;
        
        // If the DataObject contains string data, extract it.
        if (e.Data.GetDataPresent(DataFormats.StringFormat))
        {
            string dataString = (string)e.Data.GetData(DataFormats.StringFormat);

            // If the string can be converted into a Brush, convert it.
            BrushConverter converter = new BrushConverter();
            if (converter.IsValid(dataString))
            {
                Brush newFill = (Brush)converter.ConvertFromString(dataString);
                ellipse.Fill = newFill;
            }
        }
    }
}
```

将数据拖动到拖放目标上方时持续发生 [DragOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dragover) 事件。 此事件和拖动源上的 [GiveFeedback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.givefeedback) 事件成对出现。 在 [DragOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dragover) 事件处理程序中，通常使用 [GetDataPresent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.getdatapresent) 和 [GetData](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.getdata) 方法来检查传输的数据是否是拖放目标可以处理的格式。 还可以检查是否已按下修改键，这通常指示用户想进行移动操作还是复制操作。 执行这些检查后，设置 [DragEventArgs.Effects](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.drageventargs.effects) 属性以通知拖动源放置数据将产生的效果。 拖动源收到 [GiveFeedback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.givefeedback) 事件参数中的此信息，并且可以设置相应的光标以向用户提供反馈。

下面的示例演示 [Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse) 元素的 [DragOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dragover) 事件处理程序。 此代码检查是否已将 [DataObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject) 拖动到包含可以转换为 [Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush) 的字符串数据的椭圆上方。 如果是，它会将 [DragEventArgs.Effects](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.drageventargs.effects) 属性设置为 [Copy](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdropeffects#System_Windows_DragDropEffects_Copy)。 这将向拖动源指示可以将数据复制到椭圆。 如果数据无法转换为 [Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)，则将 [DragEventArgs.Effects](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.drageventargs.effects) 属性设置为 [None](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdropeffects#System_Windows_DragDropEffects_None)。 这将向拖动源指示椭圆不是数据的有效拖放目标。

C#复制

```csharp
private void ellipse_DragOver(object sender, DragEventArgs e)
{
    e.Effects = DragDropEffects.None;

    // If the DataObject contains string data, extract it.
    if (e.Data.GetDataPresent(DataFormats.StringFormat))
    {
        string dataString = (string)e.Data.GetData(DataFormats.StringFormat);

        // If the string can be converted into a Brush, allow copying.
        BrushConverter converter = new BrushConverter();
        if (converter.IsValid(dataString))
        {
            e.Effects = DragDropEffects.Copy | DragDropEffects.Move;
        }
    }
}
```

将数据拖出目标边界而未放置时，发生 [DragLeave](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dragleave) 事件。 可以处理此事件，以便撤销在 [DragEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dragenter) 事件处理程序中进行的一切操作。

下面的示例演示 [Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse) 元素的 [DragLeave](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dragleave) 事件处理程序。 此代码通过将保存的 [Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush) 应用到椭圆来撤销 [DragEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dragenter) 事件处理程序中执行的预览。

C#复制

```csharp
private void ellipse_DragLeave(object sender, DragEventArgs e)
{
    Ellipse ellipse = sender as Ellipse;
    if (ellipse != null)
    {
        ellipse.Fill = _previousFill;
    }
}
```

数据放置在拖放目标上方时，发生 [Drop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.drop) 事件；默认情况下，释放鼠标按钮时，发生此事件。 在 [Drop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.drop) 事件处理程序中，使用 [GetData](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.getdata) 方法提取 [DataObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject) 中的传输的数据并执行应用程序所需的任何数据处理。 [Drop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.drop) 事件结束拖放操作。

下面的示例演示 [Drop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.drop) 元素的 [Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse) 事件处理程序。 此代码应用拖放操作的效果，并且它类似于 [DragEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dragenter) 事件处理程序中的代码。 它会检查是否将 [DataObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject) 拖动到包含可以转换为 [Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush) 的字符串数据的椭圆上方。 如果是，将 [Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush) 应用于椭圆。 如果数据无法转换为 [Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)，则不执行任何操作。

C#复制

```csharp
private void ellipse_Drop(object sender, DragEventArgs e)
{
    Ellipse ellipse = sender as Ellipse;
    if (ellipse != null)
    {
        // If the DataObject contains string data, extract it.
        if (e.Data.GetDataPresent(DataFormats.StringFormat))
        {
            string dataString = (string)e.Data.GetData(DataFormats.StringFormat);

            // If the string can be converted into a Brush, 
            // convert it and apply it to the ellipse.
            BrushConverter converter = new BrushConverter();
            if (converter.IsValid(dataString))
            {
                Brush newFill = (Brush)converter.ConvertFromString(dataString);
                ellipse.Fill = newFill;
            }
        }
    }
}
```

## [Data and Data Objects](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/data-and-data-objects)

作为拖放操作的一部分传输的数据存储在数据对象。 从概念上讲，数据对象由一个或多个以下对组成：

- [Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object)包含实际数据。
- 相应的数据格式标识符。

数据本身可以包含的任何内容可以表示为基础[Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object)。 相应的数据格式是字符串或[Type](https://docs.microsoft.com/zh-cn/dotnet/api/system.type)，它提供有关设置数据的格式的提示是中。 数据对象支持承载多个数据/数据格式对;这使单个数据对象可以提供多个格式的数据。

### 数据对象

所有数据对象必须都实现[IDataObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.idataobject)接口，从而提供以下标准组方法，用于启用和帮助进行数据传输。

| 方法                                                         | 总结                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [GetData](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.idataobject.getdata) | 检索指定的数据格式中的数据对象。                             |
| [GetDataPresent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.idataobject.getdatapresent) | 检查以确定是否可在中，或者可以转换为指定的格式数据。         |
| [GetFormats](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.idataobject.getformats) | 返回此数据对象中的数据存储在中，或可以转换为的格式中的列表。 |
| [SetData](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.idataobject.setdata) | 将指定的数据存储在此数据对象。                               |

WPF 提供的基本实现[IDataObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.idataobject)中[DataObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject)类。 常用[DataObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject)类是足够的许多常用的数据传输方案。

有几个预定义的格式，如位图、 CSV、 文件、 HTML、 RTF、 字符串、 文本和音频。 有关与提供的预定义的数据格式信息WPF，请参阅[DataFormats](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataformats)类参考主题。

数据对象通常包括一个工具，以便自动将在提取数据; 时存储在为不同格式的一种格式的数据的转换此功能被称为自动转换。 当查询数据对象中可用的数据格式，可以通过调用筛选从本机数据格式自动转换的数据格式[GetFormats(Boolean)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.getformats#System_Windows_DataObject_GetFormats_System_Boolean_)或[GetDataPresent(String, Boolean)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.getdatapresent#System_Windows_DataObject_GetDataPresent_System_String_System_Boolean_)方法并指定`autoConvert`参数作为`false`。 将数据添加到具有的数据对象时[SetData(String, Object, Boolean)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.setdata#System_Windows_DataObject_SetData_System_String_System_Object_System_Boolean_)方法，自动转换的数据，可以通过设置禁止`autoConvert`参数`false`。



### 使用数据对象

本部分介绍用于创建和使用数据对象的常见技术。

#### 创建新的数据对象

[DataObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject)类提供了多个重载的构造函数，以方便填充新[DataObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject)使用单一数据格式对的实例。

下面的代码示例创建一个新的数据对象，并利用重载的构造函数之一[DataObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.-ctor)([DataObject(String, Object)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.-ctor#System_Windows_DataObject__ctor_System_String_System_Object_)) 来初始化具有一个字符串，指定的数据格式的数据对象。 字符串; 在这种情况下，指定数据格式[DataFormats](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataformats)类提供一组预定义的类型字符串。 默认情况下允许存储的数据的自动转换。

C#复制

```csharp
string stringData = "Some string data to store...";
string dataFormat = DataFormats.UnicodeText;
DataObject dataObject = new DataObject(dataFormat, stringData);
```

创建数据对象的代码的更多示例，请参阅[创建数据对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-create-a-data-object)。

#### 以多种格式存储数据

单个数据对象是能够以多种格式存储数据。 战略使用单个数据对象中的多个数据格式可能会使数据对象使用广泛的放置目标比如果只有无法表示一种数据格式。 请注意，一般情况下，拖动源必须是可由潜在的放置目标的数据格式不可知。

下面的示例演示如何使用[SetData(String, Object)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.setdata#System_Windows_DataObject_SetData_System_String_System_Object_)方法将数据添加到多个格式中的数据对象。

C#复制

```csharp
DataObject dataObject = new DataObject();
string sourceData = "Some string data to store...";

// Encode the source string into Unicode byte arrays.
byte[] unicodeText = Encoding.Unicode.GetBytes(sourceData); // UTF-16
byte[] utf8Text = Encoding.UTF8.GetBytes(sourceData);
byte[] utf32Text = Encoding.UTF32.GetBytes(sourceData);

// The DataFormats class does not provide data format fields for denoting
// UTF-32 and UTF-8, which are seldom used in practice; the following strings 
// will be used to identify these "custom" data formats.
string utf32DataFormat = "UTF-32";
string utf8DataFormat  = "UTF-8";

// Store the text in the data object, letting the data object choose
// the data format (which will be DataFormats.Text in this case).
dataObject.SetData(sourceData);
// Store the Unicode text in the data object.  Text data can be automatically
// converted to Unicode (UTF-16 / UCS-2) format on extraction from the data object; 
// Therefore, explicitly converting the source text to Unicode is generally unnecessary, and
// is done here as an exercise only.
dataObject.SetData(DataFormats.UnicodeText, unicodeText);
// Store the UTF-8 text in the data object...
dataObject.SetData(utf8DataFormat, utf8Text);
// Store the UTF-32 text in the data object...
dataObject.SetData(utf32DataFormat, utf32Text);
```

#### 查询可用的格式数据对象

由于单个数据对象可以包含任意数目的数据格式，数据对象将包括用于检索可用的数据格式的列表的功能。

下面的代码示例使用[GetFormats](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.getformats)重载获取表示所有可用数据对象 （本机和通过自动转换） 中的数据格式的字符串的数组。

C#复制

```csharp
DataObject dataObject = new DataObject("Some string data to store...");

// Get an array of strings, each string denoting a data format
// that is available in the data object.  This overload of GetDataFormats
// returns all available data formats, native and auto-convertible.
string[] dataFormats = dataObject.GetFormats();

// Get the number of data formats present in the data object, including both
// auto-convertible and native data formats.
int numberOfDataFormats = dataFormats.Length;

// To enumerate the resulting array of data formats, and take some action when
// a particular data format is found, use a code structure similar to the following.
foreach (string dataFormat in dataFormats)
{
    if (dataFormat == DataFormats.Text)
    {
        // Take some action if/when data in the Text data format is found.
        break;
    }
    else if(dataFormat == DataFormats.StringFormat)
    {
        // Take some action if/when data in the string data format is found.
        break;
    }
}
```

查询可用的数据格式的数据对象的代码的更多示例，请参阅[列出数据对象中的数据格式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-list-the-data-formats-in-a-data-object)。 查询数据对象是否存在特定的数据格式的示例，请参阅[确定数据格式是否存在数据对象中](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-determine-if-a-data-format-is-present-in-a-data-object)。

#### 从数据对象中检索数据

从特定的格式中的数据对象中检索数据只需调用之一[GetData](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.getdata)方法并指定所需的数据格式。 之一[GetDataPresent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.getdatapresent)方法可以用于检查是否存在特定的数据格式。 [GetData](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.getdata) 返回中的数据[Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object); 具体取决于数据格式，此对象可以强制转换为特定类型的容器。

下面的代码示例使用[GetDataPresent(String)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.getdatapresent#System_Windows_DataObject_GetDataPresent_System_String_)重载，以检查是否可指定的数据格式 （本机编译或通过自动转换）。指定的格式是否可用，该示例通过使用检索的数据[GetData(String)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.getdata#System_Windows_DataObject_GetData_System_String_)方法。

C#复制

```csharp
DataObject dataObject = new DataObject("Some string data to store...");

string desiredFormat = DataFormats.UnicodeText;
byte[] data = null;

// Use the GetDataPresent method to check for the presence of a desired data format.
// This particular overload of GetDataPresent looks for both native and auto-convertible 
// data formats.
if (dataObject.GetDataPresent(desiredFormat))
{
    // If the desired data format is present, use one of the GetData methods to retrieve the
    // data from the data object.
    data = dataObject.GetData(desiredFormat) as byte[];
}
```

有关的数据对象中检索数据的代码的更多示例，请参阅[检索特定的数据格式的数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-retrieve-data-in-a-particular-data-format)。

#### 从数据对象中删除数据

数据对象不能直接删除数据。 若要有效地从数据对象中删除数据，请按照下列步骤：

1. 创建一个新的数据对象将包含你想要保留数据。
2. "复制"所需的数据，可从旧的数据对象到新的数据对象。 若要将数据复制，使用之一[GetData](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.getdata)方法来检索[Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object)，其中包含原始数据，，然后执行下列任一[SetData](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.setdata)方法将数据添加到新的数据对象。
3. 将替换为新旧数据对象。

 备注

[SetData](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.setdata)方法仅将数据添加到数据对象; 即使数据和数据格式时完全相同的先前调用作为不替换数据。 调用[SetData](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.setdata)两次以相同的数据和数据格式将导致两次中的数据对象存在的数据/数据格式。

## [Walkthrough: Enabling Drag and Drop on a User Control](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/walkthrough-enabling-drag-and-drop-on-a-user-control)

本演练演示如何创建可在 Windows Presentation Foundation (WPF) 中参与拖放数据传输的自定义用户控件。

在本演练中，你将创建自定义 WPF[UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol)表示圆形形状。 你将在该控件上实现可通过拖放进行数据传输的功能。 例如，如果从一个圆形控件拖到另一个圆形控件，则会将填充颜色数据从源圆形复制到目标圆形。 如果从到一个圆形控件拖[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)，填充颜色的字符串表示形式复制到[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。 您还将创建包含两个面板控件的小型应用程序和一个[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)测试拖放功能。 你将编写可使面板处理放置的圆形数据的代码，这样就可以将圆形从一个面板的 Children 集合移动或复制到其他面板。

本演练阐释了以下任务：

- 创建自定义用户控件。
- 使用户控件成为拖动源。
- 使用户控件成为拖放目标。
- 使面板能够接收用户控件中放置的数据。

### 系统必备

若要完成本演练，必须具有 Visual Studio。

### 创建应用程序项目

在本部分中，您将创建应用程序基础结构，其中包括主页，其中两个面板和[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。

1. 在 Visual Basic 或 Visual C# 中创建名为 `DragDropExample` 的新 WPF 应用程序项目。 有关详细信息，请参阅[如何：创建新的 WPF 应用程序项目](https://msdn.microsoft.com/library/1f6aea7a-33e1-4d3f-8555-1daa42e95d82)。

2. 打开 MainWindow.xaml。

3. 添加以下标记的开始和结束之间[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)标记。

   此标记将创建用于测试应用程序的用户界面。

   XAML复制

   ```xaml
   <Grid.ColumnDefinitions>
       <ColumnDefinition />
       <ColumnDefinition />
   </Grid.ColumnDefinitions>
   <StackPanel Grid.Column="0"
               Background="Beige">
       <TextBox Width="Auto" Margin="2"
                Text="green"/>
   </StackPanel>
   <StackPanel Grid.Column="1"
               Background="Bisque">
   </StackPanel>
   ```

### 向项目添加新的用户控件

本节将介绍如何向项目添加新的用户控件。

1. 在“项目”菜单中，选择“添加用户控件”。

2. 在中**添加新项**对话框框中，将名称更改为`Circle.xaml`，然后单击**添加**。

   Circle.xaml 及其代码隐藏内容将添加到项目中。

3. 打开 Circle.xaml。

   此文件将包含用户控件的用户界面元素。

4. 将以下标记添加到根[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)若要创建将蓝色圆形作为其 UI 的简单用户控件。

   XAML复制

   ```xaml
   <Ellipse x:Name="circleUI" 
            Height="100" Width="100"
            Fill="Blue" />
   ```

5. 打开 Circle.xaml.cs 或 Circle.xaml.vb。

6. 在 C# 中，在默认构造函数后面添加以下代码以创建复制构造函数。 在 Visual Basic 中，添加以下代码以同时创建默认构造函数和复制构造函数。

   若要允许复制用户控件，需在代码隐藏文件中添加复制构造函数方法。 在简化的圆形用户控件中，将只复制该用户控件的填充和大小。

   C#复制

   ```csharp
   public Circle(Circle c)
   {
       InitializeComponent();
       this.circleUI.Height = c.circleUI.Height;
       this.circleUI.Width = c.circleUI.Height;
       this.circleUI.Fill = c.circleUI.Fill;
   }
   ```

### 将用户控件添加到主窗口

1. 打开 MainWindow.xaml。

2. 将以下 XAML 添加到起始[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)标记以创建对当前应用程序的 XML 命名空间引用。

   复制

   ```
   xmlns:local="clr-namespace:DragDropExample"
   ```

3. 在第一个[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)，添加以下 XAML 在第一个面板中创建圆形用户控件的两个实例。

   XAML复制

   ```xaml
   <local:Circle Margin="2" />
   <local:Circle Margin="2" />
   ```

   此面板的完整 XAML 如下所示。

   XAML复制

   ```xaml
   <StackPanel Grid.Column="0"
               Background="Beige">
       <TextBox Width="Auto" Margin="2"
                Text="green"/>
       <local:Circle Margin="2" />
       <local:Circle Margin="2" />
   </StackPanel>
   <StackPanel Grid.Column="1"
               Background="Bisque">
   </StackPanel>
   ```

### 在用户控件中实现拖动源事件

在本部分中，你将重写[OnMouseMove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.onmousemove)方法并启动拖放操作。

如果已开始拖动 （按下鼠标按钮并移动鼠标），将打包到传输的数据[DataObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject)。 在这种情况下，圆形控件将打包三个数据项：其填充颜色的字符串表示形式、其高度的双精度表示形式以及其自身的副本。

#### 启动拖放操作

1. 打开 Circle.xaml.cs 或 Circle.xaml.vb。

2. 添加以下[OnMouseMove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.onmousemove)替代，以便提供类处理[MouseMove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mousemove)事件。

   C#复制

   ```csharp
   protected override void OnMouseMove(MouseEventArgs e)
   {
       base.OnMouseMove(e);
       if (e.LeftButton == MouseButtonState.Pressed)
       {
           // Package the data.
           DataObject data = new DataObject();
           data.SetData(DataFormats.StringFormat, circleUI.Fill.ToString());
           data.SetData("Double", circleUI.Height);
           data.SetData("Object", this);
   
           // Inititate the drag-and-drop operation.
           DragDrop.DoDragDrop(this, data, DragDropEffects.Copy | DragDropEffects.Move);
       }
   }
   ```

   这[OnMouseMove](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.onmousemove)替代执行以下任务：

   - 检查移动鼠标时是否按下了鼠标左键。
   - 将圆形数据打包到[DataObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject)。 在这种情况下，圆形控件将打包三个数据项：其填充颜色的字符串表示形式、其高度的双精度表示形式以及其自身的副本。
   - 调用静态[DragDrop.DoDragDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dodragdrop)方法启动拖放操作。 传递到以下三个参数[DoDragDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dodragdrop)方法：
     - `dragSource` – 对此控件的引用。
     - `data` –[DataObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject)前面的代码中创建。
     - `allowedEffects` – 允许的拖放操作，即[Copy](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdropeffects#System_Windows_DragDropEffects_Copy)或[Move](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdropeffects#System_Windows_DragDropEffects_Move)。

3. 按 F5 生成并运行该应用程序。

4. 单击其中一个圆形控件并将其拖到面板、 另一个圆形和[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。 当上拖动[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)，光标发生变化，以指示移动。

5. 同时通过拖动圆形[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)，按**Ctrl**密钥。 请注意光标是如何更改以指示复制的。

6. 拖放到上的一个圆圈[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。 圆形填充颜色的字符串表示形式追加到[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。

   ![圆形填充颜色的字符串表示形式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/dragdrop-colorstring.png)

默认情况下，光标会在拖放操作过程中更改，以指示放置数据会产生的效果。 你可以自定义提供给用户，通过处理反馈[GiveFeedback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.givefeedback)事件和设置不同光标。

### 向用户提供反馈

1. 打开 Circle.xaml.cs 或 Circle.xaml.vb。

2. 添加以下[OnGiveFeedback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ongivefeedback)替代，以便提供类处理[GiveFeedback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.givefeedback)事件。

   C#复制

   ```csharp
   protected override void OnGiveFeedback(GiveFeedbackEventArgs e)
   {
       base.OnGiveFeedback(e);
       // These Effects values are set in the drop target's
       // DragOver event handler.
       if (e.Effects.HasFlag(DragDropEffects.Copy))
       {
           Mouse.SetCursor(Cursors.Cross);
       }
       else if (e.Effects.HasFlag(DragDropEffects.Move))
       {
           Mouse.SetCursor(Cursors.Pen);
       }
       else
       {
           Mouse.SetCursor(Cursors.No);
       }
       e.Handled = true;
   }
   ```

   这[OnGiveFeedback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ongivefeedback)替代执行以下任务：

   - 检查[Effects](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.givefeedbackeventargs.effects)拖放目标中设置的值[DragOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.dragover)事件处理程序。
   - 设置基于自定义光标[Effects](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.givefeedbackeventargs.effects)值。 该光标旨在向用户提供关于放置数据所产生的效果的可视反馈。

3. 按 F5 生成并运行该应用程序。

4. 拖动其中一个圆形的面板，另一个圆形，通过控制和[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。 请注意，现在的光标是你在中指定的自定义光标[OnGiveFeedback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ongivefeedback)重写。

   ![使用自定义光标拖放](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/dragdrop-customcursor.png)

5. 选择的文本`green`从[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。

6. 将 `green` 文本拖到一个圆形控件上。 请注意，将显示默认光标以指示拖放操作效果。 反馈光标始终由拖动源设置。

### 在用户控件中实现拖放目标事件

在本节中，你将指定用户控件为拖放目标，替代可使用户控件成为拖放目标的方法，并处理用户控件上放置的数据。

#### 使用户控件成为拖放目标

1. 打开 Circle.xaml。

2. 在左括号[UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol)标记中，添加[AllowDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.allowdrop)属性并将其设置为`true`。

   XAML复制

   ```xaml
   <UserControl x:Class="DragDropWalkthrough.Circle"
                xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
                xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
                xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006" 
                xmlns:d="http://schemas.microsoft.com/expression/blend/2008" 
                mc:Ignorable="d" 
                d:DesignHeight="300" d:DesignWidth="300"
                AllowDrop="True">
   ```

[OnDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ondrop)时调用方法[AllowDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.allowdrop)属性设置为`true`和拖动源中的数据放置在圆形用户控件上。 在这种方法中，将处理已放置的数据，并将这些数据应用于圆形。

#### 处理已放置的数据

1. 打开 Circle.xaml.cs 或 Circle.xaml.vb。

2. 添加以下[OnDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ondrop)替代，以便提供类处理[Drop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.drop)事件。

   C#复制

   ```csharp
   protected override void OnDrop(DragEventArgs e)
   {
       base.OnDrop(e);
   
       // If the DataObject contains string data, extract it.
       if (e.Data.GetDataPresent(DataFormats.StringFormat))
       {
           string dataString = (string)e.Data.GetData(DataFormats.StringFormat);
   
           // If the string can be converted into a Brush, 
           // convert it and apply it to the ellipse.
           BrushConverter converter = new BrushConverter();
           if (converter.IsValid(dataString))
           {
               Brush newFill = (Brush)converter.ConvertFromString(dataString);
               circleUI.Fill = newFill;
   
               // Set Effects to notify the drag source what effect
               // the drag-and-drop operation had.
               // (Copy if CTRL is pressed; otherwise, move.)
               if (e.KeyStates.HasFlag(DragDropKeyStates.ControlKey))
               {
                   e.Effects = DragDropEffects.Copy;
               }
               else
               {
                   e.Effects = DragDropEffects.Move;
               }
           }
       }
       e.Handled = true;
   }
   ```

   这[OnDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ondrop)替代执行以下任务：

   - 使用[GetDataPresent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.getdatapresent)方法用于检查拖动的数据是否包含字符串对象。
   - 使用[GetData](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.getdata)方法提取字符串数据，如果存在。
   - 使用[BrushConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brushconverter)尝试将字符串转换为[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)。
   - 如果转换成功，将应用到画笔[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)的[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)提供圆形控件的 UI。
   - 标记[Drop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.drop)为已处理的事件。 应将放置事件标记为已处理，这样接收此事件的其他元素才会知道圆形用户控件已处理了该事件。

3. 按 F5 生成并运行该应用程序。

4. 选择的文本`green`在[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。

5. 将文本拖放到一个圆形控件上。 该圆形会从蓝色变为绿色。

   ![将字符串转换为画笔](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/dragdrop-dropgreentext.png)

6. 键入的文本`green`在[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。

7. 选择的文本`gre`在[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。

8. 将其拖放到一个圆形控件上。 请注意，光标会更改以指示允许放置，但圆形的颜色不会更改，因为 `gre` 不是有效颜色。

9. 从绿色圆形控件拖放到蓝色圆形控件。 该圆形会从蓝色变为绿色。 请注意，显示的光标取决于是否[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)还是圆形作为拖动源。

设置[AllowDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.allowdrop)属性设置为`true`和处理放置的数据是只需要启用要拖放目标的元素。 但是，若要提供更好的用户体验，您还应处理[DragEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.dragenter)， [DragLeave](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.dragleave)，和[DragOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.dragover)事件。 在这些事件中，你可以在放置数据前执行检查并向用户提供其他反馈。

将数据拖动到圆形用户控件上时，该控件应通知拖动源它是否可以处理所拖动的数据。 如果该控件不知如何处理这些数据，则它应拒绝放置。 若要执行此操作，你将处理[DragOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.dragover)事件并设置[Effects](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.drageventargs.effects)属性。

#### 验证是否允许数据放置

1. 打开 Circle.xaml.cs 或 Circle.xaml.vb。

2. 添加以下[OnDragOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ondragover)替代，以便提供类处理[DragOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.dragover)事件。

   C#复制

   ```csharp
   protected override void OnDragOver(DragEventArgs e)
   {
       base.OnDragOver(e);
       e.Effects = DragDropEffects.None;
   
       // If the DataObject contains string data, extract it.
       if (e.Data.GetDataPresent(DataFormats.StringFormat))
       {
           string dataString = (string)e.Data.GetData(DataFormats.StringFormat);
   
           // If the string can be converted into a Brush, allow copying or moving.
           BrushConverter converter = new BrushConverter();
           if (converter.IsValid(dataString))
           {
               // Set Effects to notify the drag source what effect
               // the drag-and-drop operation will have. These values are 
               // used by the drag source's GiveFeedback event handler.
               // (Copy if CTRL is pressed; otherwise, move.)
               if (e.KeyStates.HasFlag(DragDropKeyStates.ControlKey))
               {
                   e.Effects = DragDropEffects.Copy;
               }
               else
               {
                   e.Effects = DragDropEffects.Move;
               }
           }
       }
       e.Handled = true;
   }
   ```

   这[OnDragOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ondragover)替代执行以下任务：

   - 将 [Effects](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.drageventargs.effects) 属性设置为 [None](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdropeffects#System_Windows_DragDropEffects_None)。
   - 执行在中执行的相同检查[OnDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ondrop)方法，以确定圆形用户控件是否可以处理拖动的数据。
   - 如果用户控件可以处理数据，设置[Effects](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.drageventargs.effects)属性设置为[Copy](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdropeffects#System_Windows_DragDropEffects_Copy)或[Move](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdropeffects#System_Windows_DragDropEffects_Move)。

3. 按 F5 生成并运行该应用程序。

4. 选择的文本`gre`在[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。

5. 将文本拖到一个圆形控件上。 请注意，光标此时会更改以指示不允许放置，因为 `gre` 不是有效颜色。

可通过应用拖放操作预览进一步增强用户体验。 对于圆形用户控件，您将重写[OnDragEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ondragenter)和[OnDragLeave](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ondragleave)方法。 当将数据拖动控件当前的背景上[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)保存在一个占位符变量中。 然后转换为画笔并应用于字符串[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)提供圆形 UI。 如果将数据拖动出该圆形而没有放置，原始[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)值重新应用于该圆形。

#### 预览拖放操作的效果

1. 打开 Circle.xaml.cs 或 Circle.xaml.vb。

2. 在圆形类中，声明一个私有[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)名为变量`_previousFill`并将其初始化`null`。

   C#复制

   ```csharp
   public partial class Circle : UserControl
   {
       private Brush _previousFill = null;
   ```

3. 添加以下[OnDragEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ondragenter)替代，以便提供类处理[DragEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.dragenter)事件。

   C#复制

   ```csharp
   protected override void OnDragEnter(DragEventArgs e)
   {
       base.OnDragEnter(e);
       // Save the current Fill brush so that you can revert back to this value in DragLeave.
       _previousFill = circleUI.Fill;
   
       // If the DataObject contains string data, extract it.
       if (e.Data.GetDataPresent(DataFormats.StringFormat))
       {
           string dataString = (string)e.Data.GetData(DataFormats.StringFormat);
   
           // If the string can be converted into a Brush, convert it.
           BrushConverter converter = new BrushConverter();
           if (converter.IsValid(dataString))
           {
               Brush newFill = (Brush)converter.ConvertFromString(dataString.ToString());
               circleUI.Fill = newFill;
           }
       }
   }
   ```

   这[OnDragEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ondragenter)替代执行以下任务：

   - 将保存[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)的属性[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)中`_previousFill`变量。
   - 执行在中执行的相同检查[OnDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ondrop)方法，以确定数据是否可以转换为[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)。
   - 如果数据转换为有效[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)，将其应用于[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)的[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)。

4. 添加以下[OnDragLeave](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ondragleave)替代，以便提供类处理[DragLeave](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.dragleave)事件。

   C#复制

   ```csharp
   protected override void OnDragLeave(DragEventArgs e)
   {
       base.OnDragLeave(e);
       // Undo the preview that was applied in OnDragEnter.
       circleUI.Fill = _previousFill;
   }
   ```

   这[OnDragLeave](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ondragleave)替代执行以下任务：

   - 适用[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)以保存`_previousFill`变量[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)的[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)提供圆形用户控件的 UI。

5. 按 F5 生成并运行该应用程序。

6. 选择的文本`green`在[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。

7. 将该文本拖到一个圆形控件上而不放置。 该圆形会从蓝色变为绿色。

   ![预览拖放操作的效果](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/dragdrop-previeweffects.png)

8. 将文本拖离该圆形控件。 该圆形会从绿色变回蓝色。

### 使面板能够接收放置的数据

在本部分中，允许承载圆形用户控件，使其作为拖动圆形数据的放置目标的面板。 将实现的代码，使你可以将圆形从一个面板移动到另一个，或通过按下创建一个圆形控件的副本**Ctrl**拖放圆形时键。

1. 打开 MainWindow.xaml。

2. 以下 XAML 中的每个中所示[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)控件，则添加的处理程序[DragOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.dragover)和[Drop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.drop)事件。 名称[DragOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.dragover)事件处理程序`panel_DragOver`，并将命名[Drop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.drop)事件处理程序`panel_Drop`。

   XAML复制

   ```xaml
   <StackPanel Grid.Column="0"
               Background="Beige"
               AllowDrop="True"
               DragOver="panel_DragOver"
               Drop="panel_Drop">
       <TextBox Width="Auto" Margin="2"
                Text="green"/>
       <local:Circle Margin="2" />
       <local:Circle Margin="2" />
   </StackPanel>
   <StackPanel Grid.Column="1"
               Background="Bisque"
               AllowDrop="True"
               DragOver="panel_DragOver"
               Drop="panel_Drop">
   </StackPanel>
   ```

3. 打开 MainWindows.xaml.cs 或 MainWindow.xaml.vb。

4. 添加以下代码为[DragOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.dragover)事件处理程序。

   C#复制

   ```csharp
   private void panel_DragOver(object sender, DragEventArgs e)
   {
       if (e.Data.GetDataPresent("Object"))
       {
           // These Effects values are used in the drag source's
           // GiveFeedback event handler to determine which cursor to display.
           if (e.KeyStates == DragDropKeyStates.ControlKey)
           {
               e.Effects = DragDropEffects.Copy;
           }
           else
           {
               e.Effects = DragDropEffects.Move;
           }
       }
   }
   ```

   这[DragOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.dragover)事件处理程序执行以下任务：

   - 检查拖动的数据包含已打包的中的"对象"数据[DataObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject)由圆形用户控件，并对的调用中传递[DoDragDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dodragdrop)。
   - 如果"对象"数据存在，检查是否**Ctrl**按下键。
   - 如果**Ctrl**按下键，集[Effects](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.drageventargs.effects)属性设置为[Copy](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdropeffects#System_Windows_DragDropEffects_Copy)。 否则，设置[Effects](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.drageventargs.effects)属性设置为[Move](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdropeffects#System_Windows_DragDropEffects_Move)。

5. 添加以下代码为[Drop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.drop)事件处理程序。

   C#复制

   ```csharp
   private void panel_Drop(object sender, DragEventArgs e)
   {
       // If an element in the panel has already handled the drop,
       // the panel should not also handle it.
       if (e.Handled == false)
       {
           Panel _panel = (Panel)sender;
           UIElement _element = (UIElement)e.Data.GetData("Object");
   
           if (_panel != null && _element != null)
           {
               // Get the panel that the element currently belongs to,
               // then remove it from that panel and add it the Children of
               // the panel that its been dropped on.
               Panel _parent = (Panel)VisualTreeHelper.GetParent(_element);
   
               if (_parent != null)
               {
                   if (e.KeyStates == DragDropKeyStates.ControlKey &&
                       e.AllowedEffects.HasFlag(DragDropEffects.Copy))
                   {
                       Circle _circle = new Circle((Circle)_element);
                       _panel.Children.Add(_circle);
                       // set the value to return to the DoDragDrop call
                       e.Effects = DragDropEffects.Copy;
                   }
                   else if (e.AllowedEffects.HasFlag(DragDropEffects.Move))
                   {
                       _parent.Children.Remove(_element);
                       _panel.Children.Add(_element);
                       // set the value to return to the DoDragDrop call
                       e.Effects = DragDropEffects.Move;
                   }
               }
           }
       }
   }
   ```

   这[Drop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.drop)事件处理程序执行以下任务：

   - 检查是否[Drop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.drop)已处理事件。 例如，如果一个圆形放置在另一圈的句柄[Drop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.drop)事件，您不希望包含还处理该圆形的面板。
   - 如果[Drop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.drop)不处理事件，检查是否**Ctrl**按下键。
   - 如果**Ctrl**按下键时[Drop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.drop)发生，会复制该圆形控件并将其添加到[Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.children)的集合[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)。
   - 如果**Ctrl**未按下键，将移动从圆[Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.children)到其父面板的集合[Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.children)面板已被删除的集合。
   - 集[Effects](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.drageventargs.effects)属性以通知[DoDragDrop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dodragdrop)方法是否执行了移动或复制操作。

6. 按 F5 生成并运行该应用程序。

7. 选择的文本`green`从[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。

8. 将文本拖放到一个圆形控件上。

9. 将一个圆形控件从左面板拖放到右面板。 该圆形会从[Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.children)左面板中的集合并添加到右侧面板的 Children 集合。

10. 从面板到另一个面板将一个圆形控件拖放时按**Ctrl**密钥。 将复制该圆形并将副本添加到[Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.children)接收面板的集合。

    ![按住 Ctrl 键的同时拖动圆形](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/dragdrop-paneldrop.png)

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/drag-and-drop-how-to-topics)

下面的示例演示如何完成常见任务使用Windows Presentation Foundation (WPF)拖放框架。

[打开放入 RichTextBox 控件的文件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-open-a-file-that-is-dropped-on-a-richtextbox-control)
[创建数据对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-create-a-data-object)
[确定数据对象中是否有数据格式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-determine-if-a-data-format-is-present-in-a-data-object)
[列出数据对象中的数据格式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-list-the-data-formats-in-a-data-object)
[以特定数据格式检索数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-retrieve-data-in-a-particular-data-format)
[在数据对象中存储多种数据格式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-store-multiple-data-formats-in-a-data-object)

### [Open a File That is Dropped on a RichTextBox Control](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-open-a-file-that-is-dropped-on-a-richtextbox-control)

在Windows Presentation Foundation (WPF)、 [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)， [RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)，和[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)控件所有具有内置拖放功能。 内置功能，可拖放文本内部或之间控件。 但是，它不支持通过删除该控件上的文件打开的文件。 这些控件还会将拖放事件标记为已处理。 因此，默认情况下，无法添加你自己的事件处理程序来提供功能以打开拖放的文件。

若要添加这些控件中的拖放事件的其他处理，使用[AddHandler(RoutedEvent, Delegate, Boolean)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.addhandler#System_Windows_UIElement_AddHandler_System_Windows_RoutedEvent_System_Delegate_System_Boolean_)方法以添加事件处理程序的拖放事件。 设置`handledEventsToo`参数`true`为具有已标记为由事件路由的其他元素处理的路由事件调用所指定的处理程序。

> 你可以替换内置的拖放功能的[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)， [RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)，和[FlowDocument](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.documents.flowdocument)通过处理拖放事件的预览版本并将预览事件标记为已处理。 但是，这将禁用与内置的拖放功能，并且不建议。

下面的示例演示如何添加处理程序[DragOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.dragover)和[Drop](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dragdrop.drop)上的事件[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)。 此示例使用[AddHandler(RoutedEvent, Delegate, Boolean)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.addhandler#System_Windows_UIElement_AddHandler_System_Windows_RoutedEvent_System_Delegate_System_Boolean_)方法和集`handledEventsToo`参数`true`，以便将即使调用事件处理程序[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)标记为已处理这些事件。 中的事件处理程序的代码的新增功能可打开放置一个文本文件[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)。

若要测试此示例，请将拖动的文本文件或丰富文本格式 (RTF) 文件从 Windows 资源管理器到[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)。 将在中打开文件[RichTextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.richtextbox)。 如果你在按住 SHIFT 键之前删除该文件，将以纯文本格式打开文件。



```xaml
<RichTextBox x:Name="richTextBox1"
             AllowDrop="True" />
```

C#复制

```csharp
public MainWindow()
{
    InitializeComponent();

    // Add using System.Windows.Controls;
    richTextBox1.AddHandler(RichTextBox.DragOverEvent, new DragEventHandler(RichTextBox_DragOver), true);
    richTextBox1.AddHandler(RichTextBox.DropEvent, new DragEventHandler(RichTextBox_Drop), true);
}

private void RichTextBox_DragOver(object sender, DragEventArgs e)
{
    if (e.Data.GetDataPresent(DataFormats.FileDrop))
    {
        e.Effects = DragDropEffects.All;
    }
    else
    {
        e.Effects = DragDropEffects.None;
    }
    e.Handled = false;
}

private void RichTextBox_Drop(object sender, DragEventArgs e)
{
    if (e.Data.GetDataPresent(DataFormats.FileDrop))
    {
        string[] docPath = (string[])e.Data.GetData(DataFormats.FileDrop);

        // By default, open as Rich Text (RTF).
        var dataFormat = DataFormats.Rtf;

        // If the Shift key is pressed, open as plain text.
        if (e.KeyStates == DragDropKeyStates.ShiftKey)
        {
            dataFormat = DataFormats.Text;
        }

        System.Windows.Documents.TextRange range;
        System.IO.FileStream fStream;
        if (System.IO.File.Exists(docPath[0]))
        {
            try
            {
                // Open the document in the RichTextBox.
                range = new System.Windows.Documents.TextRange(richTextBox1.Document.ContentStart, richTextBox1.Document.ContentEnd);
                fStream = new System.IO.FileStream(docPath[0], System.IO.FileMode.OpenOrCreate);
                range.Load(fStream, dataFormat);
                fStream.Close();
            }
            catch (System.Exception)
            {
                MessageBox.Show("File could not be opened. Make sure the file is a text file.");
            }
        }
    }
}
```

### [Create a Data Object](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-create-a-data-object)

下面的示例演示创建数据对象使用的构造函数提供的各种方式[DataObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject)类。

#### 示例

下面的代码示例创建一个新的数据对象，并使用重载的构造函数之一 ([DataObject(Object)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.-ctor#System_Windows_DataObject__ctor_System_Object_)) 来初始化数据对象的字符串。 在这种情况下，根据存储的数据类型自动确定适当的数据格式，且默认情况下允许存储的数据自动转换。

```csharp
string stringData = "Some string data to store...";
DataObject dataObject = new DataObject(stringData);
```

下面的代码示例是代码的上面所示的精简的版本。

```csharp
DataObject dataObject = new DataObject("Some string data to store...");
```

#### 示例

下面的代码示例创建一个新的数据对象，并使用重载的构造函数之一 ([DataObject(String, Object)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.-ctor#System_Windows_DataObject__ctor_System_String_System_Object_)) 来初始化具有一个字符串，指定的数据格式的数据对象。 一个字符串; 在这种情况下指定的数据格式[DataFormats](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataformats)类提供了一组预定义的类型字符串。 默认情况下，允许存储的数据将自动转换。

```csharp
string stringData = "Some string data to store...";
string dataFormat = DataFormats.UnicodeText;
DataObject dataObject = new DataObject(dataFormat, stringData);
```

下面的代码示例是代码的上面所示的精简的版本。

```csharp
DataObject dataObject = new DataObject(DataFormats.UnicodeText, "Some string data to store...");
```

#### 示例

下面的代码示例创建一个新的数据对象，并使用重载的构造函数之一 ([DataObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.-ctor)) 来初始化具有一个字符串，指定的数据格式的数据对象。 指定数据格式在这种情况下[Type](https://docs.microsoft.com/zh-cn/dotnet/api/system.type)参数。 默认情况下，允许存储的数据将自动转换。

```csharp
string stringData = "Some string data to store...";
Type dataFormat = stringData.GetType();
DataObject dataObject = new DataObject(dataFormat, stringData);
```

下面的代码示例是代码的上面所示的精简的版本。

```csharp
DataObject dataObject = new DataObject("".GetType(), "Some string data to store...");
```

#### 示例

下面的代码示例创建一个新的数据对象，并使用重载的构造函数之一 ([DataObject(String, Object, Boolean)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.-ctor#System_Windows_DataObject__ctor_System_String_System_Object_System_Boolean_)) 来初始化具有一个字符串，指定的数据格式的数据对象。 一个字符串; 在这种情况下指定的数据格式[DataFormats](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataformats)类提供了一组预定义的类型字符串。 此特定构造函数重载允许调用方指定是否允许将自动转换。

```csharp
string stringData = "Some string data to store...";
string dataFormat = DataFormats.Text;
bool autoConvert = false;
DataObject dataObject = new DataObject(dataFormat, stringData, autoConvert);
```

下面的代码示例是代码的上面所示的精简的版本。

```csharp
DataObject dataObject = new DataObject(DataFormats.Text, "Some string data to store...", false);
```

### [Determine if a Data Format is Present in a Data Object](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-determine-if-a-data-format-is-present-in-a-data-object)

以下示例演示如何使用各种[GetDataPresent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.getdatapresent)方法重载来查询特定的数据格式是否存在于数据对象中。

#### 示例

下面的示例代码使用[GetDataPresent(String)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.getdatapresent#System_Windows_DataObject_GetDataPresent_System_String_)查询是否存在特定的数据格式的描述符字符串的重载。

```csharp
DataObject dataObject = new DataObject("Some string data to store...");

// Query for the presence of Text data in the data object, by a data format descriptor string.
// In this overload of GetDataPresent, the method will return true both for native data formats
// and when the data can automatically be converted to the specifed format.

// In this case, string data is present natively, so GetDataPresent returns "true".
string textData = null;
if (dataObject.GetDataPresent(DataFormats.StringFormat))
{
    textData = dataObject.GetData(DataFormats.StringFormat) as string;
}

// In this case, the Text data in the data object can be autoconverted to 
// Unicode text, so GetDataPresent returns "true".
byte[] unicodeData = null;
if (dataObject.GetDataPresent(DataFormats.UnicodeText))
{
    unicodeData = dataObject.GetData(DataFormats.UnicodeText) as byte[];
}
```

#### 示例

下面的示例代码使用[GetDataPresent(Type)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.getdatapresent#System_Windows_DataObject_GetDataPresent_System_Type_)查询是否存在特定的数据格式由类型的重载。

```csharp
DataObject dataObject = new DataObject("Some string data to store...");

// Query for the presence of String data in the data object, by type.  In this overload 
// of GetDataPresent, the method will return true both for native data formats
// and when the data can automatically be converted to the specifed format.

// In this case, the Text data present in the data object can be autoconverted
// to type string (also represented by DataFormats.String), so GetDataPresent returns "true".
string stringData = null;
if (dataObject.GetDataPresent(typeof(string)))
{
    stringData = dataObject.GetData(DataFormats.Text) as string;
}
```

#### 示例

下面的示例代码使用[GetDataPresent(String, Boolean)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.getdatapresent#System_Windows_DataObject_GetDataPresent_System_String_System_Boolean_)描述符字符串重载查询数据，并指定如何处理可自动转换的数据格式。

```csharp
DataObject dataObject = new DataObject("Some string data to store...");

// Query for the presence of Text data in the data object, by data format descriptor string,
// and specifying whether auto-convertible data formats are acceptable.  

// In this case, Text data is present natively, so GetDataPresent returns "true".
string textData = null;
if (dataObject.GetDataPresent(DataFormats.Text, false /* Auto-convert? */))
{
    textData = dataObject.GetData(DataFormats.Text) as string;
}

// In this case, the Text data in the data object can be autoconverted to 
// Unicode text, but it is not available natively, so GetDataPresent returns "false".
byte[] unicodeData = null;
if (dataObject.GetDataPresent(DataFormats.UnicodeText, false /* Auto-convert? */))
{
    unicodeData = dataObject.GetData(DataFormats.UnicodeText) as byte[];
}

// In this case, the Text data in the data object can be autoconverted to 
// Unicode text, so GetDataPresent returns "true".
if (dataObject.GetDataPresent(DataFormats.UnicodeText, true /* Auto-convert? */))
{
    unicodeData = dataObject.GetData(DataFormats.UnicodeText) as byte[];
}
```

### [List the Data Formats in a Data Object](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-list-the-data-formats-in-a-data-object)

下面的示例演示如何使用[GetFormats](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.getformats)方法重载获取表示可在数据对象中每个数据格式的字符串数组。

#### 示例

下面的示例代码使用[GetFormats](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.getformats)重载获取表示所有可用数据对象 （本机和可自动转换） 中的数据格式的字符串数组。

```csharp
DataObject dataObject = new DataObject("Some string data to store...");

// Get an array of strings, each string denoting a data format
// that is available in the data object.  This overload of GetDataFormats
// returns all available data formats, native and auto-convertible.
string[] dataFormats = dataObject.GetFormats();

// Get the number of data formats present in the data object, including both
// auto-convertible and native data formats.
int numberOfDataFormats = dataFormats.Length;

// To enumerate the resulting array of data formats, and take some action when
// a particular data format is found, use a code structure similar to the following.
foreach (string dataFormat in dataFormats)
{
    if (dataFormat == DataFormats.Text)
    {
        // Take some action if/when data in the Text data format is found.
        break;
    }
    else if(dataFormat == DataFormats.StringFormat)
    {
        // Take some action if/when data in the string data format is found.
        break;
    }
}
```

#### 示例

下面的示例代码使用[GetFormats](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.getformats)重载获取表示仅在数据对象 （可自动转换数据格式进行筛选） 中可用数据格式的字符串数组。

```csharp
DataObject dataObject = new DataObject("Some string data to store...");

// Get an array of strings, each string denoting a data format
// that is available in the data object.  This overload of GetDataFormats
// accepts a Boolean parameter inidcating whether to include auto-convertible
// data formats, or only return native data formats.
string[] dataFormats = dataObject.GetFormats(false /* Include auto-convertible? */);

// Get the number of native data formats present in the data object.
int numberOfDataFormats = dataFormats.Length;

// To enumerate the resulting array of data formats, and take some action when
// a particular data format is found, use a code structure similar to the following.
foreach (string dataFormat in dataFormats)
{
    if (dataFormat == DataFormats.Text)
    {
        // Take some action if/when data in the Text data format is found.
        break;
    }
}
```

### [Retrieve Data in a Particular Data Format](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-retrieve-data-in-a-particular-data-format)

以下示例演示如何从指定的格式中的数据对象中检索数据。

#### 示例

下面的代码示例使用[GetDataPresent(String)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.getdatapresent#System_Windows_DataObject_GetDataPresent_System_String_)重载，以首先检查是否指定的数据格式 （本机或通过自动转换）; 如果指定的格式不可用，该示例通过检索数据[GetData(String)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.getdata#System_Windows_DataObject_GetData_System_String_)方法。

```csharp
DataObject dataObject = new DataObject("Some string data to store...");

string desiredFormat = DataFormats.UnicodeText;
byte[] data = null;

// Use the GetDataPresent method to check for the presence of a desired data format.
// This particular overload of GetDataPresent looks for both native and auto-convertible 
// data formats.
if (dataObject.GetDataPresent(desiredFormat))
{
    // If the desired data format is present, use one of the GetData methods to retrieve the
    // data from the data object.
    data = dataObject.GetData(desiredFormat) as byte[];
}
```

#### 示例

下面的示例代码使用[GetDataPresent(String, Boolean)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.getdatapresent#System_Windows_DataObject_GetDataPresent_System_String_System_Boolean_)重载来首先检查指定的数据格式是否可用本机 （自动转换的数据格式已筛选的）; 如果指定的格式不可用，该示例通过使用检索数据[GetData(String)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.getdata#System_Windows_DataObject_GetData_System_String_)方法。

```csharp
DataObject dataObject = new DataObject("Some string data to store...");

string desiredFormat = DataFormats.UnicodeText;
bool noAutoConvert = false;
byte[] data = null;

// Use the GetDataPresent method to check for the presence of a desired data format.
// The autoconvert parameter is set to false to filter out auto-convertible data formats,
// returning true only if the specified data format is available natively.
if (dataObject.GetDataPresent(desiredFormat, noAutoConvert))
{
    // If the desired data format is present, use one of the GetData methods to retrieve the
    // data from the data object.
    data = dataObject.GetData(desiredFormat) as byte[];
}
```

### [Store Multiple Data Formats in a Data Object](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-store-multiple-data-formats-in-a-data-object)

下面的示例演示如何使用[SetData(String, Object)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dataobject.setdata#System_Windows_DataObject_SetData_System_String_System_Object_)方法将数据添加到多个格式中的数据对象。

#### 示例

```csharp
DataObject dataObject = new DataObject();
string sourceData = "Some string data to store...";

// Encode the source string into Unicode byte arrays.
byte[] unicodeText = Encoding.Unicode.GetBytes(sourceData); // UTF-16
byte[] utf8Text = Encoding.UTF8.GetBytes(sourceData);
byte[] utf32Text = Encoding.UTF32.GetBytes(sourceData);

// The DataFormats class does not provide data format fields for denoting
// UTF-32 and UTF-8, which are seldom used in practice; the following strings 
// will be used to identify these "custom" data formats.
string utf32DataFormat = "UTF-32";
string utf8DataFormat  = "UTF-8";

// Store the text in the data object, letting the data object choose
// the data format (which will be DataFormats.Text in this case).
dataObject.SetData(sourceData);
// Store the Unicode text in the data object.  Text data can be automatically
// converted to Unicode (UTF-16 / UCS-2) format on extraction from the data object; 
// Therefore, explicitly converting the source text to Unicode is generally unnecessary, and
// is done here as an exercise only.
dataObject.SetData(DataFormats.UnicodeText, unicodeText);
// Store the UTF-8 text in the data object...
dataObject.SetData(utf8DataFormat, utf8Text);
// Store the UTF-32 text in the data object...
dataObject.SetData(utf32DataFormat, utf32Text);
```