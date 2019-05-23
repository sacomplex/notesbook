# [Control Authoring Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/control-authoring-overview)

Windows Presentation Foundation (WPF) 控件模型的扩展性极大地减少了创建新控件的需要。 但在某些情况下，仍可能需要创建自定义控件。 本主题讨论可最大限度减少在 Windows Presentation Foundation (WPF) 中创建自定义控件以及其他控件创作模型的需要的功能。 本主题还演示如何创建新控件。



## 编写新控件的替代方法

以前，如果要通过现有控件获取自定义体验，只能更改控件的标准属性，例如背景色、边框宽度和字号。 如果希望在这些预定义参数的基础之上扩展控件的外观或行为，则需要创建新控件，常用的方法是继承现有控件并重写负责绘制该控件的方法。 虽然这仍是一种可选方法，但也可以利用 WPF 的丰富内容模型、样式、模板和触发器来自定义现有的控件。 下表提供了一些示例，演示如何在不创建新控件的情况下使用这些功能来实现一致的自定义体验。

- **丰富内容。** 很多标准 WPF 控件都支持丰富内容。 例如，内容属性的[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)属于类型[Object](https://docs.microsoft.com/zh-cn/dotnet/api/system.object)，因此理论上的任何内容都可以显示在[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。 若要使按钮显示图像和文本，可以添加的图像和一个[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)到[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)，并将分配[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)到[Content](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.content)属性。 由于这些控件可以显示 WPF 视觉元素和任意数据，因此，降低了创建新控件或修改现有控件来支持复杂可视化效果的需求。 详细了解的内容模型[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)和其他内容中的模型WPF，请参阅[WPF 内容模型](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/wpf-content-model)。

- **样式。** 一个[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)是表示控件的属性的值的集合。 使用样式可创建所需控件外观和行为的可重用表示形式，而无需编写新控件。 例如，假设您希望的所有你[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)控件具有红色 Arial 字体，并且字号为 14。 可以创建一个样式作为资源，并相应设置适当属性。 然后每个[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)，您将添加到你的应用程序将具有相同的外观。

- **数据模板。** 一个[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)，可以自定义控件上显示数据的方式。 例如，[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)可用于指定数据中的显示方式[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)。 有关这种情况的示例，请参阅[数据模块化概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-templating-overview)。 除了自定义的数据，外观[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)可以包含 UI 元素，后者可提供很大的灵活性在自定义 Ui。 例如，通过使用[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)，可以创建[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)中的每个项包含一个复选框。

- **控件模板。** 中的许多控件WPF使用[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)来定义控件的结构和外观，将控件的外观与控件的功能分隔开来。 您可以极大地更改控件的外观，通过重新定义其[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。 例如，假设需要一个看起来像交通信号灯的控件。 此控件具有简单的用户界面和功能。 该控件有三个圆圈，一次只有一个圆圈亮起。经过考虑之后，您可能会发现[RadioButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.radiobutton)提供的功能只选择一个时间，但的默认外观[RadioButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.radiobutton)完全不像交通信号灯上的灯。 因为[RadioButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.radiobutton)使用的控件模板来定义其外观，很容易重新定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)，使其适合的控件，要求使用单选按钮来制作交通信号灯。

   备注

  尽管[RadioButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.radiobutton)可以使用[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)、[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)不足在此示例中。 [DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)定义控件的内容的外观。 情况下[RadioButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.radiobutton)，内容是圆圈，以指示右侧出现的任何内容是否[RadioButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.radiobutton)处于选中状态。 在交通信号灯的示例中，单选按钮只需要是可“点亮”的圆圈。 由于交通信号灯的外观要求很大差异的默认外观[RadioButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.radiobutton)，有必要重新定义[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。 一般情况下[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)用于定义的内容 （或数据），一个控件，以及一个[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)用于定义控件的方式。

- **触发器。** 一个[Trigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.trigger)，可动态更改的外观和行为的控件，而无需创建一个新的控件。 例如，假设您有多个[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)应用程序中的控件，并且希望在每个项[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)在选中时为粗体和红色。 在第一个想到的可能是创建继承自类[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)并重写[OnSelectionChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.selector.onselectionchanged)方法来更改外观，所选的项，但更好的方法是将触发器添加到样式的[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)更改的外观所选的项。 触发器可以更改属性值或根据属性值执行操作。 [EventTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventtrigger)使您能够在事件发生时执行操作。

有关样式、模板和触发器的详细信息，请参阅[样式设置和模板化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/styling-and-templating)。

一般情况下，如果控件可以镜像现有控件的功能，但希望该控件具有不同的外观，则应先考虑是否可以使用本节中讨论的某些方法来更改现有控件的外观。

## 控件创作模型

通过丰富内容模型、样式、模板和触发器，最大程度地减少创建新控件的需要。 但是，如果确实需要创建新控件，则理解 WPF 中的不同控件创作模型就显得非常重要。 WPF 提供三个用于创建控件的常规模型，每个模型都提供不同的功能集和灵活度。 基类的三个模型都[UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol)， [Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)，和[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)。

### 从 UserControl 派生

若要创建的控件中的最简单方法WPF是从派生[UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol)。 当你生成控件的继承[UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol)，将添加到现有的组件[UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol)，命名组件，并引用中的事件处理程序可扩展应用程序标记语言 (XAML)。 随后可以在代码中引用命名的元素和定义事件处理程序。 此开发模型与用于在 WPF 中开发应用程序的模型非常相似。

如果生成无误，[UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol)可以充分利用丰富的内容、 样式和触发器的优势。 但是，如果控件继承自[UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol)，使用您的控件的用户将无法再使用[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)或[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)来自定义其外观。 必须派生自[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)类或其派生类之一 (而不[UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol)) 创建支持模板的自定义控件。

#### 从 UserControl 派生的优点

请考虑从派生[UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol)如果所有以下应用：

- 希望采用与生成应用程序相似的方法生成控件。
- 控件仅包含现有组件。
- 无需支持复杂的自定义项。

### 从 Control 派生

派生自[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)类是使用大多数现有的模型WPF控件。 当你创建的控件的继承[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)类，您通过使用模板定义其外观。 通过这种方式，可以将运算逻辑从视觉表示形式中分离出来。 您还可以确保 UI 和逻辑分离而不是事件和避免引用元素中的使用命令和绑定[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)只要有可能。 如果 UI 和控件的逻辑正确分离，您的控件的用户可以重新定义控件的[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)来自定义其外观。 尽管生成自定义[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)不是作为构造简单[UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol)，自定义[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)提供最大的灵活性。

#### 从 Control 派生的优点

请考虑从派生[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)而不是使用[UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol)类如果以下任一情况:

- 你想要通过可自定义控件的外观[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。
- 希望控件支持不同的主题。

### 从 FrameworkElement 派生

从派生的控件[UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol)或[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)依赖于组合现有元素。 对于许多方案，这是一个可接受的解决方案，因为任何对象，它继承自[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)可以是[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。 但是，某些时候，简单的元素组合不能满足控件的外观需要。 对于这些方案，使组件基于[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)是正确的选择。

有两种标准方法，用于生成[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)-基于组件： 直接呈现和自定义元素组合。 直接呈现涉及重写[OnRender](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.onrender)方法[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)，并提供[DrawingContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingcontext)显式定义组件视觉对象的操作。 这是使用的方法[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)和[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)。 自定义元素组合涉及到使用类型的对象[Visual](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visual)组件的外观。 有关示例，请参阅[使用 DrawingVisual 对象](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/using-drawingvisual-objects)。 [Track](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.track) 是一个示例中的控件WPF，它使用自定义元素组合。 在同一控件中，也可以混合使用直接呈现和自定义元素组合。

#### 从 FrameworkElement 派生的优点

请考虑从派生[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)如果以下任一情况:

- 希望对控件的外观进行精确控制，而不仅仅是简单的元素组合提供的效果。
- 希望通过定义自己的呈现逻辑来定义控件的外观。
- 你想要在超过可能采用的新颖方式组合现有元素[UserControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.usercontrol)和[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)。

## 控件创作基础知识

如前所述，WPF 的最强大功能之一在于，它能够在不需要创建自定义控件的情况下，不只是通过设置控件的基本属性来更改其外观和行为。 样式设置、数据绑定和触发器功能通过 WPF 属性系统和 WPF 事件系统实现。 以下各部分介绍应遵循的一些做法（与创建自定义控件时所用的模型无关），以便自定义控件的用户可以像使用 WPF附带的控件一样使用这些功能。

### 使用依赖属性

当属性为依赖属性时，可以执行以下操作：

- 在样式中设置该属性。
- 将该属性绑定到数据源。
- 使用动态资源作为该属性的值。
- 对该属性进行动画处理。

如果希望控件的属性支持以上任一功能，应将该属性实现为依赖属性。 下面的示例通过执行以下操作定义一个名为 `Value` 的依赖属性：

- 定义[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)名为标识符`ValueProperty`作为`public` `static` `readonly`字段。
- 通过调用属性系统注册的属性名称[DependencyProperty.Register](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.register)，以指定以下内容：
  - 属性的名称。
  - 属性的类型。
  - 拥有属性的类型。
  - 属性的元数据。 元数据包含该属性的默认值[CoerceValueCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.coercevaluecallback)和一个[PropertyChangedCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertychangedcallback)。
- 通过实现该属性的 `get` 和 `set` 访问器，定义一个名为 `Value`（与用来注册该依赖属性的名称相同）的 CLR 包装器属性。 请注意，`get`并`set`访问器仅调用[GetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.getvalue)和[SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue)分别。 建议依赖项属性的访问器不包含其他逻辑，因为客户端和WPF取值函数和调用可以绕过[GetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.getvalue)和[SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue)直接。 例如，如果属性绑定到数据源，则不会调用该属性的 `set` 访问器。 而不是将额外的逻辑添加到 get 和 set 访问器，请使用[ValidateValueCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.validatevaluecallback)， [CoerceValueCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.coercevaluecallback)，和[PropertyChangedCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertychangedcallback)委托进行响应或发生更改时检查的值。 有关这些回叫的详细信息，请参阅[依赖属性回叫和验证](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dependency-property-callbacks-and-validation)。
- 定义一种方法[CoerceValueCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.coercevaluecallback)名为`CoerceValue`。 `CoerceValue` 确保 `Value` 大于或等于 `MinValue`且小于或等于 `MaxValue`。
- 定义一种方法[PropertyChangedCallback](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.propertychangedcallback)名为`OnValueChanged`。 `OnValueChanged` 创建[RoutedPropertyChangedEventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedpropertychangedeventargs-1)对象，并准备引发`ValueChanged`路由的事件。 路由事件在下一节中讨论。

```csharp
       /// <summary>
       /// Identifies the Value dependency property.
       /// </summary>
       public static readonly DependencyProperty ValueProperty =
           DependencyProperty.Register(
               "Value", typeof(decimal), typeof(NumericUpDown),
               new FrameworkPropertyMetadata(MinValue, new PropertyChangedCallback(OnValueChanged),
                                             new CoerceValueCallback(CoerceValue)));

       /// <summary>
       /// Gets or sets the value assigned to the control.
       /// </summary>
       public decimal Value
       {          
           get { return (decimal)GetValue(ValueProperty); }
           set { SetValue(ValueProperty, value); }
       }

       private static object CoerceValue(DependencyObject element, object value)
       {
           decimal newValue = (decimal)value;
           NumericUpDown control = (NumericUpDown)element;

           newValue = Math.Max(MinValue, Math.Min(MaxValue, newValue));
           
           return newValue;
       }

       private static void OnValueChanged(DependencyObject obj, DependencyPropertyChangedEventArgs args)
       {
           NumericUpDown control = (NumericUpDown)obj;			

           RoutedPropertyChangedEventArgs<decimal> e = new RoutedPropertyChangedEventArgs<decimal>(
               (decimal)args.OldValue, (decimal)args.NewValue, ValueChangedEvent);
           control.OnValueChanged(e);
       }
```

有关详细信息，请参阅[自定义依赖属性](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/custom-dependency-properties)。

### 使用路由事件

就像依赖属性以附加功能扩展 CLR 属性的概念一样，路由事件扩展标准 CLR 事件的概念。 在创建新的 WPF 控件时，将事件实现为路由事件也是一种好方法，因为路由事件支持以下行为：

- 事件可以在多个控件的父级上进行处理。 如果事件是浮升事件，元素树中的单个父级可订阅该事件。 然后，应用程序作者可以使用一个处理程序来响应多个控件的该事件。 例如，如果您的控件是在每个项的一部分[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)(因为它包含在[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate))，应用程序开发人员可以在定义控件的事件的事件处理程序[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)。 每当其中任何控件发生该事件时，都会调用该事件处理程序。
- 路由的事件可在[EventSetter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventsetter)，这使应用程序开发人员能够指定的样式中的事件处理程序。
- 路由的事件可在[EventTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventtrigger)，可用于通过对属性进行动画处理XAML。 有关详细信息，请参阅 [动画概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/animation-overview)。

下面的示例通过执行以下操作定义了一个路由事件：

- 定义[RoutedEvent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedevent)名为标识符`ValueChangedEvent`作为`public` `static` `readonly`字段。
- 通过调用注册路由的事件[EventManager.RegisterRoutedEvent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventmanager.registerroutedevent)方法。 该示例在调用时指定以下信息[RegisterRoutedEvent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventmanager.registerroutedevent):
  - 事件名称是 `ValueChanged`。
  - 路由策略是[Bubble](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routingstrategy#System_Windows_RoutingStrategy_Bubble)，这意味着首先，调用源 （引发事件的对象） 上的事件处理程序，然后使用上的最近的事件处理程序开始，相继调用源的父元素上的事件处理程序父元素。
  - 事件处理程序的类型是[RoutedPropertyChangedEventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedpropertychangedeventhandler-1)、 构造与[Decimal](https://docs.microsoft.com/zh-cn/dotnet/api/system.decimal)类型。
  - 该事件的所属类型为 `NumericUpDown`。
- 声明一个名为 `ValueChanged` 的公共事件，并包含事件访问器声明。 此示例调用[AddHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.addhandler)中`add`访问器声明并[RemoveHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.removehandler)中`remove`访问器声明，以使用WPF事件服务。
- 创建一个名为 `OnValueChanged` 的受保护的虚拟方法，该方法会引发 `ValueChanged` 事件。

```csharp
/// <summary>
/// Identifies the ValueChanged routed event.
/// </summary>
public static readonly RoutedEvent ValueChangedEvent = EventManager.RegisterRoutedEvent(
    "ValueChanged", RoutingStrategy.Bubble, 
    typeof(RoutedPropertyChangedEventHandler<decimal>), typeof(NumericUpDown));

/// <summary>
/// Occurs when the Value property changes.
/// </summary>
public event RoutedPropertyChangedEventHandler<decimal> ValueChanged
{
    add { AddHandler(ValueChangedEvent, value); }
    remove { RemoveHandler(ValueChangedEvent, value); }
}

/// <summary>
/// Raises the ValueChanged event.
/// </summary>
/// <param name="args">Arguments associated with the ValueChanged event.</param>
protected virtual void OnValueChanged(RoutedPropertyChangedEventArgs<decimal> args)
{
    RaiseEvent(args);
}
```

有关详细信息，请参阅[路由事件概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/routed-events-overview)和[创建自定义路由事件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-create-a-custom-routed-event)。

### 使用绑定

若要将控件的 UI 与其逻辑分离，请考虑使用数据绑定。 这一点特别重要，如果您通过使用定义控件外观[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。 使用数据绑定时，或许可以避免在代码中引用 UI 的特定部分。 它是一个好办法避免引用中的元素[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)因为当代码引用中的元素[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)并[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)已更改，引用的元素需要包含在新[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)。

以下示例更新[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)的`NumericUpDown`向它分配一个名称，并且在代码中按名称引用该文本框控件。

```xaml
<Border BorderThickness="1" BorderBrush="Gray" Margin="2" 
        Grid.RowSpan="2" VerticalAlignment="Center" HorizontalAlignment="Stretch">
  <TextBlock Name="valueText" Width="60" TextAlignment="Right" Padding="5"/>
</Border>
```

```csharp
private void UpdateTextBlock()
{
    valueText.Text = Value.ToString();
}
```

下面的示例使用绑定来达到相同的目的。

```xaml
<Border BorderThickness="1" BorderBrush="Gray" Margin="2" 
        Grid.RowSpan="2" VerticalAlignment="Center" HorizontalAlignment="Stretch">

    <!--Bind the TextBlock to the Value property-->
    <TextBlock 
        Width="60" TextAlignment="Right" Padding="5"
        Text="{Binding RelativeSource={RelativeSource FindAncestor, 
                       AncestorType={x:Type local:NumericUpDown}}, 
                       Path=Value}"/>

</Border>
```

有关数据绑定的详细信息，请参阅[数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview)。

### 设计器的设计

若要在 适用于 Visual Studio 的 WPF 设计器 中获得对自定义 WPF 控件的支持（例如，使用“属性”窗口编辑属性），请遵循以下准则。 有关开发的详细信息WPF 设计器，请参阅[Visual Studio 中设计 XAML](https://docs.microsoft.com/zh-cn/visualstudio/designers/designing-xaml-in-visual-studio)。

#### 依赖项属性

确保实现 CLR `get` 和 `set` 访问器，如前面的“使用依赖属性”中所述。 设计器可以使用包装器来检测某个依赖属性是否存在，但与 WPF 和控件客户端一样，在获取或设置属性时不需要使用设计器来调用访问器。

#### 附加属性

应使用以下准则在自定义控件上实现附加属性：

- 具有`public` `static` `readonly` [DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)窗体*PropertyName* `Property`创建使用[RegisterAttached](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.registerattached)方法。 属性名称传递给[RegisterAttached](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.registerattached)必须匹配*PropertyName*。
- 实现一对名为`Set`*属性名称*和`Get`*属性名称*的 `public` `static` CLR 方法。 这两种方法应接受派生自的类[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)作为其第一个参数。 `Set`*属性名称*方法还接受其类型与属性的注册数据类型匹配的参数。 `Get`*属性名称* 方法应返回相同类型的值。 如果缺少 `Set`*属性名称*方法，则该属性标记为只读。
- `Set` *PropertyName*并`Get` *PropertyName*必须直接路由到[GetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.getvalue)和[SetValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject.setvalue)方法目标依赖对象，分别。通过调用方法包装器或直接调用目标依赖对象，设计器可以访问附加属性。

有关附加属性的详细信息，请参阅[附加属性概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/attached-properties-overview)。

### 定义和使用共享资源

可以将控件包含在应用程序所在的程序集中，也可以将控件打包到可在多个应用程序中使用的单独程序集中。 大多数情况下，不管使用什么方法，本主题中讨论的信息都适用。 但有一处差异值得注意。 将控件放入应用程序所在的程序集中时，可以随意向 App.xaml 文件添加全局资源。 但只包含控件的程序集不具有[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)与其相关的对象，因此 App.xaml 文件不可用。

当应用程序查找资源时，它会按以下顺序在三个级别进行查找：

1. 元素级别。

   系统从引用该资源的元素开始搜索，接着搜索逻辑父级的资源，依此类推，直至到达根元素。

2. 应用程序级别。

   定义的资源，[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)对象。

3. 主题级别。

   主题级别的字典存储在名为“Themes”的子文件夹中。 Themes 文件夹中的文件与主题对应。 例如，可能有 Aero.NormalColor.xaml、Luna.NormalColor.xaml、Royale.NormalColor.xaml 等。 可能还有一个名为 generic.xaml 的文件。 当系统在主题级别查找资源时，它会先在特定于主题的文件中查找相应资源，然后在 generic.xaml 中进行查找。

当控件位于独立于应用程序的程序集中时，必须将全局资源放在元素级别或主题级别。 这两种方法都各有优点。

#### 在元素级别定义资源

可以通过创建自定义资源字典并将其与控件的资源字典合并，在元素级别定义共享资源。 采用此方法时，可以为资源文件指定任意名称，并且资源文件可以与控件位于同一文件夹中。 元素级别的资源还可以使用简单字符串作为键。 下面的示例创建[LinearGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush)名为 Dictionary1.xaml 的资源文件。

```xaml
<ResourceDictionary 
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
  <LinearGradientBrush 
    x:Key="myBrush"  
    StartPoint="0,0" EndPoint="1,1">
    <GradientStop Color="Red" Offset="0.25" />
    <GradientStop Color="Blue" Offset="0.75" />
  </LinearGradientBrush>
  
</ResourceDictionary>
```

定义字典后，需要将其与控件的资源字典合并。 可以使用 XAML 或代码执行此操作。

下面的示例通过使用 XAML 合并资源字典。

```xaml
<UserControl.Resources>
    <ResourceDictionary>
        <ResourceDictionary.MergedDictionaries>
            <ResourceDictionary Source="Dictionary1.xaml"/>
        </ResourceDictionary.MergedDictionaries>
    </ResourceDictionary>
</UserControl.Resources>
```

这种方法的缺点是[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)引用它每次创建对象。 例如，如果您库中有 10 个自定义控件，并通过使用 XAML 来合并每个控件的共享的资源字典，则创建 10 相同[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)对象。 您可以避免这种情况创建合并在代码中的资源，并返回结果的静态类[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)。

下面的示例创建一个返回共享的类[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)。

```csharp
internal static class SharedDictionaryManager
{
    internal static ResourceDictionary SharedDictionary
    {
        get
        {
            if (_sharedDictionary == null)
            {
                System.Uri resourceLocater =
                    new System.Uri("/ElementResourcesCustomControlLibrary;component/Dictionary1.xaml", 
                                    System.UriKind.Relative);

                _sharedDictionary = 
                    (ResourceDictionary)Application.LoadComponent(resourceLocater);
            }

            return _sharedDictionary;
        }
    }

    private static ResourceDictionary _sharedDictionary;
}
```

下面的示例先在一个自定义控件的构造函数中将共享资源与该控件的资源合并，然后再调用 `InitializeComponent`。 因为`SharedDictionaryManager.SharedDictionary`是一个静态属性，[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)创建仅一次。 因为资源字典在调用 `InitializeComponent` 前已合并，所以控件可以在它的 XAML 文件中使用资源。

```csharp
public NumericUpDown()
{
    this.Resources.MergedDictionaries.Add(SharedDictionaryManager.SharedDictionary);
    InitializeComponent();

}
```

#### 在主题级别定义资源

通过 WPF 可以为不同的 Windows 主题创建资源。 作为控件作者，可以为特定主题定义资源，以根据所使用的主题更改控件的外观。 例如的外观[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)在 Windows 经典主题 （Windows 2000 的默认主题） 不同于[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)Windows Luna 主题 （Windows XP 的默认主题） 中由于[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)使用不同[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)为每个主题。

特定于主题的资源以特定文件名保留在资源字典中。 这些文件必须位于一个名为 `Themes` 的文件夹中，此文件夹是包含该控件的文件夹的子文件夹。 下表列出了资源字典文件以及与每个文件关联的主题：

| 资源字典文件名            | Windows 主题                                 |
| ------------------------- | -------------------------------------------- |
| `Classic.xaml`            | Windows XP 中的经典 Windows 9x/2000 外观     |
| `Luna.NormalColor.xaml`   | Windows XP 上的默认蓝色主题                  |
| `Luna.Homestead.xaml`     | Windows XP 上的橄榄色主题                    |
| `Luna.Metallic.xaml`      | Windows XP 上的银色主题                      |
| `Royale.NormalColor.xaml` | Windows XP Media Center Edition 上的默认主题 |
| `Aero.NormalColor.xaml`   | Windows Vista 上的默认主题                   |

无需为每一种主题都定义资源。 如果没有为特定主题定义资源，控件将在 `Classic.xaml` 中检查资源。 如果在与当前主题对应的文件或 `Classic.xaml` 中没有定义资源，控件将使用常规资源，该资源位于名为 `generic.xaml`的资源字典文件中。 `generic.xaml` 文件与特定于主题的资源词典文件位于同一文件夹中。 尽管 `generic.xaml`不与特定的 Windows 主题对应，但它仍是一个主题级别字典。

[带有主题和 UI 自动化支持的 NumericUpDown 自定义控件示例](https://go.microsoft.com/fwlink/?LinkID=160025)包含两个用于 `NumericUpDown` 控件的资源字典：一个在 generic.xaml 中，另一个在 Luna.NormalColor.xaml 中。 可以运行应用程序并在 Windows XP 中的银色主题和另一主题之间切换，以查看这两个控件模板之间的差别。 （如果运行的是 Windows Vista，可以将 Luna.NormalColor.xaml 重命名为 Aero.NormalColor.xaml，然后在两个主题之间切换，例如在 Windows 经典主题和 Windows Vista 的默认主题之间切换。）

当将[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)必须在任何特定于主题资源字典文件，创建控件和调用静态构造函数[OverrideMetadata(Type, PropertyMetadata)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty.overridemetadata#System_Windows_DependencyProperty_OverrideMetadata_System_Type_System_Windows_PropertyMetadata_)方法[DefaultStyleKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.defaultstylekey)，如以下示例所示。

```csharp
static NumericUpDown()
{
    DefaultStyleKeyProperty.OverrideMetadata(typeof(NumericUpDown),
               new FrameworkPropertyMetadata(typeof(NumericUpDown)));
}
```

##### 定义和引用主题资源的键

在元素级别定义资源时，可以指定一个字符串作为它的键，然后通过该字符串访问该资源。 在定义在主题级别的资源时，必须使用[ComponentResourceKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.componentresourcekey)作为键。 以下示例定义 generic.xaml 中的资源。

```xaml
<LinearGradientBrush 
     x:Key="{ComponentResourceKey TypeInTargetAssembly={x:Type local:Painter}, 
                                  ResourceId=MyEllipseBrush}"  
                                  StartPoint="0,0" EndPoint="1,0">
    <GradientStop Color="Blue" Offset="0" />
    <GradientStop Color="Red" Offset="0.5" />
    <GradientStop Color="Green" Offset="1"/>
</LinearGradientBrush>
```

下面的示例通过指定引用的资源[ComponentResourceKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.componentresourcekey)作为键。

```xaml
<RepeatButton 
    Grid.Column="1" Grid.Row="0"
    Background="{StaticResource {ComponentResourceKey 
                        TypeInTargetAssembly={x:Type local:NumericUpDown}, 
                        ResourceId=ButtonBrush}}">
    Up
</RepeatButton>
<RepeatButton 
    Grid.Column="1" Grid.Row="1"
    Background="{StaticResource {ComponentResourceKey 
                    TypeInTargetAssembly={x:Type local:NumericUpDown}, 
                    ResourceId=ButtonBrush}}">
    Down
 </RepeatButton>
```

##### 指定主题资源的位置

若要找到控件的资源，承载应用程序需要知道相应程序集包含特定于控件的资源。 您可以实现此目的通过添加[ThemeInfoAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.themeinfoattribute)到包含该控件的程序集。 [ThemeInfoAttribute](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.themeinfoattribute)已[GenericDictionaryLocation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.themeinfoattribute.genericdictionarylocation)属性，它指定泛型资源的位置和一个[ThemeDictionaryLocation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.themeinfoattribute.themedictionarylocation)属性，它指定特定于主题的资源的位置。

下面的示例设置[GenericDictionaryLocation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.themeinfoattribute.genericdictionarylocation)并[ThemeDictionaryLocation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.themeinfoattribute.themedictionarylocation)属性设置为[SourceAssembly](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionarylocation#System_Windows_ResourceDictionaryLocation_SourceAssembly)，以指定的通用和特定于主题资源位于控件所在的程序集。

```csharp
[assembly: ThemeInfo(ResourceDictionaryLocation.SourceAssembly, 
           ResourceDictionaryLocation.SourceAssembly)]
```

