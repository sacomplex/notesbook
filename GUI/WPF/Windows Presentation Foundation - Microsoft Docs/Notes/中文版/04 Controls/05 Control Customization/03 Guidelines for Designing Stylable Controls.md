# [Guidelines for Designing Stylable Controls](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/guidelines-for-designing-stylable-controls)

本文档概述在设计可方便地样式化和模板化的控件时需要考虑的一组最佳做法。 在为内置的 WPF 控件集处理主题控件样式时，我们通过大量试验和错误总结出了这组最佳做法。 我们已经认识到，成功的样式设置不只是设计完善的对象模型的功能，也是样式本身的功能。 本文档面向控件作者，而不是样式作者。



## 术语

“样式设置和模板化”是一组技术，控件作者可以通过该组技术将控件的可视化特性延迟到控件的样式和模板。 这组技术包括：

- 样式（包括属性资源库、触发器和演示图板）。
- 资源。
- 控件模板。
- 数据模板。

有关样式设置和模板化简介，请参阅[样式设置和模板化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/styling-and-templating)。



## 在开始之前：了解您的控件

在开始阅读这些准则之前，请务必了解并定义了控件的常见用法。 样式设置公开一组通常不受约束的可能性。旨在由许多开发人员在许多应用程序中广泛使用的控件面临着如下挑战：可以使用样式设置对控件的可视化外观进行广泛更改。 实际上，带样式的控件甚至可能并非控件作者的本意。 由于样式设置在本质上可以提供无限的灵活性，因此可以使用“常见用法”这一概念来帮助你限制自己的决定。

若要了解控件的常见用法，最好考虑控件的价值主张。 你的控件能够在表中提供哪些无法由其他控件提供的内容？ 常见用法并不表示任何特定的可视化外观，而是表示控件的基本原理和一组有关其用法的合理预期。 了解到这一点，就可以对控件在一般情况下的撰写模型和样式定义行为进行一些假设。 情况下[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)，例如，了解常见的使用情况不会深入分析任何有关某个特定[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)具有圆的角，但能够让你深入了解这一事实，[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)可能需要一个弹出窗口和切换是否处于打开状态的一些方法。



## 通用准则

- **不严格实施模板协定。** 控件的模板协定可能包含元素、命令、绑定和触发器，甚至还可以包含必需的或为了使控件正常工作而应当使用的属性设置。

  - 最大限度地减少协定。
  - 围绕如下预期进行设计：在设计时（即，在使用设计工具时），控件模板通常处于不完整状态。 WPF 不提供“正在撰写”状态的基础结构，因此，控件必须围绕这样的状态可能有效这一预期来生成。
  - 在没有遵循模板协定的任何方面时，不引发异常。 按照这一原则，当面板的子级太多或太少时，面板不应引发异常。

- **将外围功能分解成模板帮助程序元素。** 每个控件都应当将重点放在其核心功能和真正的价值主张上，而且每个控件都应当由控件的常见用法定义。 为此，请使用模板中的撰写和帮助程序元素实现外围行为和可视化（即，那些不构成控件核心功能的行为和可视化）。 帮助程序元素分为三类：

  - **独立**帮助程序类型是以“匿名方式”用在模板中的可重用的公共控件或基元，这意味着帮助程序元素和带样式的控件无法互相识别。 在技术上，任何元素都可以是匿名类型，但是在此上下文中，该术语描述了那些封装专用功能以实现目标方案的类型。
  - **基于类型的**帮助程序元素是封装专用功能的新类型。 通常，这些元素在设计上比通用控件或基元的功能范围要窄。 与独立帮助程序元素不同的是，基于类型的帮助程序元素能够识别它们的使用上下文，而且通常必须与包含它们所属模板的控件共享数据。
  - **命名的**帮助程序元素是控件应当能够在其模板中根据名称找到的常用控件或基元。 这些元素在模板中具有一个已知的名称，这使得控件能够找到这些元素并以编程方式与之交互。 在任何模板中，都只能有一个具有给定名称的元素。

  下表显示了由目前的控件样式使用的部分帮助程序元素列表：

  | 元素                                                         | 类型       | 通过者                                                       |
  | ------------------------------------------------------------ | ---------- | ------------------------------------------------------------ |
  | [ContentPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter) | 基于类型的 | [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)， [RadioButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.radiobutton)，[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)等 (所有[ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)类型) |
  | [ItemsPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemspresenter) | 基于类型的 | [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)，[Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)等 (所有[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)类型) |
  | [ToolBarOverflowPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.toolbaroverflowpanel) | 命名的     | [ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar) |
  | [Popup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.popup) | 独立       | [ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)， [Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)， [ToolTip](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tooltip)，等等 |
  | [RepeatButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.repeatbutton) | 命名的     | [Slider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider)[ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar)，等等 |
  | [ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar) | 命名的     | [ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer) |
  | [ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer) | 独立       | [ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)， [Menu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menu)， [Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)，等等 |
  | [TabPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.tabpanel) | 独立       | [TabControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tabcontrol) |
  | [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox) | 命名的     | [ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox) |
  | [TickBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.tickbar) | 基于类型的 | [Slider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider) |

- **最大限度地减少帮助程序元素所必需的、特定于用户的绑定或属性设置**。 通常，帮助程序元素需要某些绑定或属性设置才能在控件模板中正确工作。 帮助程序元素和模板化控件应当尽可能多地生成这些设置。 在设置属性或者建立绑定时，注意不要重写由用户设置的值。 具体的最佳做法如下所示：

  - 命名的帮助程序元素应当由父级标识，而且父级应当针对帮助程序元素建立任何必需的设置。
  - 基于类型的帮助程序元素应当直接针对自身建立任何必需的设置。 这样做可能需要帮助程序元素查找它在使用时的信息上下文，包括其 `TemplatedParent`（它在使用时的模板的控件类型）。 例如，[ContentPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter)会自动将绑定`Content`的属性及其`TemplatedParent`到其[Content](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter.content)属性中使用时[ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)派生类型。
  - 独立帮助程序元素不能按这种方式进行优化，这是因为按照定义，帮助程序元素和父级不能相互识别。

- **使用 Name 属性标记模板中的元素**。 如果控件需要在样式中查找某个元素才能以编程方式访问它，则该控件应当使用 `Name` 属性和 `FindName` 范例来进行查找。 控件不应在未找到所需元素时引发异常，而是应在不提示的情况下禁用需要该元素的功能。

- **使用最佳做法来表示样式中的控件状态和行为。** 下面按顺序列出了用来表示样式中的控件状态更改和行为的最佳做法。 应使用列表上的第一项来实现你的方案。

  1. 属性绑定。 示例： 绑定之间[ComboBox.IsDropDownOpen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox.isdropdownopen)和[ToggleButton.IsChecked](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.togglebutton.ischecked)。
  2. 触发的属性更改或属性动画。 示例： 悬停状态的[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。
  3. 命令。 示例： [LineUpCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar.lineupcommand) / [LineDownCommand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar.linedowncommand)中[ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar)。
  4. 独立帮助程序元素。 示例：[TabPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.tabpanel)在[TabControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tabcontrol)。
  5. 基于类型的帮助程序类型。 示例：[ContentPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter)中[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)，[TickBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.tickbar)中[Slider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.slider)。
  6. 命名的帮助程序元素。 示例：[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)在[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)。
  7. 命名的帮助程序类型中的冒泡事件。 如果侦听样式元素中的冒泡事件，应当要求生成该事件的元素能够进行唯一标识。 示例：[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)在[ToolBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.toolbar)。
  8. 自定义 `OnRender` 行为。 示例：[ButtonChrome](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.windows.themes.buttonchrome)在[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。

- **慎用样式触发器（与模板触发器相对）**。 影响模板中元素上的属性的触发器必须在模板中声明。 影响控件上的属性的触发器（没有 `TargetName`）可以在样式中声明，除非你知道更改模板还可能会损坏触发器。

- **与现有的样式设置模式保持一致。** 一个问题常常有多种解决办法。 注意尽可能与现有的控件样式设置模式保持一致。 这一点尤其重要的控件的派生自同一基类型 (例如， [ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)， [ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)， [RangeBase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.rangebase)，依此类推)。

- **在不重新模板化的情况下公开属性来启用常见自定义项方案**。 WPF 不支持可插入/可自定义的部件，因此控件用户只能使用两种自定义方法：直接设置属性或者使用样式设置属性。 请记住，比较合适的做法是，设置数量有限的属性，使其面向极其常见的高优先级自定义项方案，否则的话，这些方案需要重新模板化。下面是有关何时以及如何启用自定义项方案的最佳方法：

  - 极其常见的自定义项应当作为属性在控件上公开并由模板使用。
  - 不太常见（尽管并非极少见）的自定义项应当作为附加属性公开并由模板使用。
  - 需要对已知但是极少见的自定义项重新模板化，这一点也是可接受的。



## 主题注意事项

- **主题样式应尝试在所有主题中具有一致的属性语义，但不保证能够实现这一点**。 作为控件文档的一部分，控件应当具有一个描述其属性语义（即控件属性的“含义”）的文档。 例如，[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)控件应当定义的含义[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)属性内的[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)。 控件的默认样式应当尝试遵循在其文档中的所有主题中定义的语义。 另一方面，控件用户应当注意属性语义可能因主题而异。 在某些情况下，给定的属性在由特定主题所需的可视化约束下可能无法表示。 （例如，对于许多控件来说，传统主题没有可以向其应用 `Thickness` 的边框。）
- **主题样式不需要在所有主题中具有一致的触发器语义**。 由控件样式通过触发器或动画公开的行为可能因主题而异。 控件用户应当注意到，控件不必使用同一个机制在所有主题中实现特定的行为。 例如，一个主题可以使用动画来表示悬停行为，而另一个主题则可以使用触发器。 这可能会导致自定义控件上的行为保留出现不一致。 （例如，如果控件的悬停状态使用触发器来表示，则更改背景属性可能不会影响该状态。 但是，如果悬停状态使用动画来实现，则更改背景属性可能会不可挽回地中断动画，从而中断状态过渡。）
- **主题样式不需要在所有主题中具有一致的“布局”语义**。 例如，默认的样式不需要保证控件将在所有主题中占用同样的大小，也不需要保证控件将在所有主题中具有同样的内容边距/空白。