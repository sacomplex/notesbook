# [UI Automation of a WPF Custom Control](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/ui-automation-of-a-wpf-custom-control)

Microsoft UI 自动化 提供了一个通用接口，自动化客户端可使用该接口来检查或操作各种平台和框架的用户界面。 UI 自动化 使质量保证（测试）代码和具有辅助功能的应用程序（如屏幕阅读器）能够检查用户界面元素，以及能够模拟与其他代码中的用户元素进行的用户交互。 有关跨所有平台的 UI 自动化 的信息，请参阅“辅助功能”。

本主题介绍如何实现在 WPF 应用程序中运行的自定义控件的服务器端 UI 自动化提供程序。 WPF 通过等同于用户界面元素树的对等自动化对象树来支持 UI 自动化。 测试代码和提供辅助功能的应用程序可以直接使用自动化对等对象（适用于进程内代码），也可以通过 UI 自动化 提供的通用接口使用自动化对等对象。



## 自动化对等类

WPF 控件支持UI 自动化通过派生自的对等类树[AutomationPeer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.automationpeer)。 按照约定，对等类名以控件类名开头，以“AutomationPeer”结尾。 例如，[ButtonAutomationPeer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.buttonautomationpeer)是为对等类[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)控件类。 对等类大致相当于 UI 自动化 控件类型，但特定于 WPF 元素。 通过 UI 自动化 接口访问 WPF 应用程序的自动化代码不直接使用自动化对等，但同一进程空间中的自动化代码可以直接使用自动化对等。



## 内置的自动化对等类

如果元素接受用户的接口活动，或者如果元素包含屏幕阅读器应用程序的用户所需的信息，则这些元素会实现一个自动化对等类。 并非所有 WPF 视觉元素都具有自动化对等。 实现自动化对等的类示例包括[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)， [TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)，和[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)。 未实现自动化对等的类的示例包括派生的类[Decorator](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.decorator)，如[Border](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border)，并基于类[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)，如[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)和[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)。

基[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)类没有相应的对等类。 如果您需要一个对等类对应于自定义控件派生自[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)，应派生自定义对等类从[FrameworkElementAutomationPeer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.frameworkelementautomationpeer)。



## 派生对等的安全注意事项

自动化对等必须在部分信任环境中运行。 UIAutomationClient 程序集中的代码未配置为在部分信任环境中运行，自动化对等代码不应引用该程序集。 应改用 UIAutomationTypes 程序集中的类。 例如，应使用[AutomationElementIdentifiers](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.automationelementidentifiers)类从 UIAutomationTypes 程序集，它对应于[AutomationElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.automationelement)UIAutomationClient 程序集中的类。 可以安全地在自动化对等代码中引用 UIAutomationTypes 程序集。



## 对等导航

找到后的自动化对等方，进程内代码可以在树中导航对等方通过调用对象的[GetChildren](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.automationpeer.getchildren)和[GetParent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.automationpeer.getparent)方法。 之间的导航WPF在控件内的元素支持的对等节点的实现[GetChildrenCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.automationpeer.getchildrencore)方法。 UI 自动化系统调用此方法生成控件内包含的子元素树（例如，列表框中的列表项）。 默认值[UIElementAutomationPeer.GetChildrenCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.uielementautomationpeer.getchildrencore)方法会遍历可视化树的元素来构建自动化对等树。 自定义控件重写此方法以向自动化客户端公开子元素，这会返回传达信息或允许用户交互的元素自动化对等。



## 派生对等中的自定义项

所有派生的类[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)并[ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement)包含受保护的虚拟方法[OnCreateAutomationPeer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.oncreateautomationpeer)。 WPF 调用[OnCreateAutomationPeer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.oncreateautomationpeer)若要获取的每个控件的自动化对等对象。 自动化代码可使用对等来获取有关控件特征和功能的信息，并模拟交互使用。 支持自动化的自定义控件必须重写[OnCreateAutomationPeer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.oncreateautomationpeer)，并返回派生的类的实例[AutomationPeer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.automationpeer)。 例如，如果自定义控件派生自[ButtonBase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase)类，则返回的对象[OnCreateAutomationPeer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.oncreateautomationpeer)应派生自[ButtonBaseAutomationPeer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.buttonbaseautomationpeer)。

实现自定义控件时，必须重写自动化对等基类中的“Core”方法，这些方法描述了特定于自定义控件的唯一行为。

### 重写 OnCreateAutomationPeer

重写[OnCreateAutomationPeer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.oncreateautomationpeer)方法使其返回在提供程序对象，必须直接或间接派生自定义控件[AutomationPeer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.automationpeer)。

### 重写 GetPattern

自动化对等简化了服务器端 UI 自动化 提供程序的一部分实现，但自定义控件自动化对等仍必须处理模式接口。非 WPF 提供程序，如对等方支持控件模式中的接口的实现，从而[System.Windows.Automation.Provider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.provider)命名空间，如[IInvokeProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.provider.iinvokeprovider)。 控件模式接口可以由对等本身或其他对象实现。 对等节点的实现[GetPattern](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.automationpeer.getpattern)返回支持指定的模式的对象。 UI 自动化 代码调用[GetPattern](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.uielementautomationpeer.getpattern)方法，并指定[PatternInterface](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.patterninterface)枚举值。 重写[GetPattern](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.uielementautomationpeer.getpattern)应返回实现了指定的模式的对象。 如果您的控件不具有一种模式的自定义实现，则可以调用基类型实现[GetPattern](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.automationpeer.getpattern)要检索其实现或返回 null，如果模式不支持此控件类型。 例如，自定义的 NumericUpDown 控件可以被设置为范围内的值以便其UI 自动化对等实现[IRangeValueProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.provider.irangevalueprovider)接口。 下面的示例演示如何对等节点的[GetPattern](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.uielementautomationpeer.getpattern)重写方法以响应[PatternInterface.RangeValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.patterninterface#System_Windows_Automation_Peers_PatternInterface_RangeValue)值。

C#复制

```csharp
public override object GetPattern(PatternInterface patternInterface)
{
    if (patternInterface == PatternInterface.RangeValue)
    {
        return this;
    }
    return base.GetPattern(patternInterface);
}
```

一个[GetPattern](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.uielementautomationpeer.getpattern)方法还可以指定子元素作为模式提供程序。 下面的代码演示如何[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)传输滚动模式处理传递给其内部的对等方[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)控件。

C#复制

```csharp
public override object GetPattern(PatternInterface patternInterface)  
{  
    if (patternInterface == PatternInterface.Scroll)  
    {  
        ItemsControl owner = (ItemsControl) base.Owner;  
  
        // ScrollHost is internal to the ItemsControl class  
        if (owner.ScrollHost != null)  
        {  
            AutomationPeer peer = UIElementAutomationPeer.CreatePeerForElement(owner.ScrollHost);  
            if ((peer != null) && (peer is IScrollProvider))  
            {  
                peer.EventsSource = this;  
                return (IScrollProvider) peer;  
            }  
        }  
    }  
    return base.GetPattern(patternInterface);  
}  
```

若要指定用于模式处理子元素，此代码将获取子元素的对象，通过创建一个对等[CreatePeerForElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.uielementautomationpeer.createpeerforelement)方法，设置[EventsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.automationpeer.eventssource)当前对等方，新的对等方的属性，并返回新对等方。 设置[EventsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.automationpeer.eventssource)子元素上可防止子元素出现在自动化对等类树中，并将引发的子元素的所有事件都指定为来自中指定的控件[EventsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.automationpeer.eventssource)。 [ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)控件不会出现在自动化树中，并且它将生成的滚动事件显示为来自[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)对象。

### 重写“Core”方法

自动化代码通过调用对等类的公共方法来获取控件的相关信息。 在控件实现不同于自动化对等基类提供的实现的情况下，若要提供控件的相关信息，请重写名称以“Core”结尾的每个方法。 至少，您的控件必须实现[GetClassNameCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.automationpeer.getclassnamecore)和[GetAutomationControlTypeCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.automationpeer.getautomationcontroltypecore)方法，如下面的示例中所示。

C#复制

```csharp
protected override string GetClassNameCore()
{
    return "NumericUpDown";
}

protected override AutomationControlType GetAutomationControlTypeCore()
{
    return AutomationControlType.Spinner;
}
```

实现[GetAutomationControlTypeCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.automationpeer.getautomationcontroltypecore)通过返回描述您的控件[ControlType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.controltype)值。 尽管您可以返回[ControlType.Custom](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.controltype.custom)，如果它准确地描述您的控件应返回更具体的控件类型之一。 返回值[ControlType.Custom](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.controltype.custom)为要实现的提供程序的额外工作量UI 自动化，和UI 自动化客户端产品不能以应对预期的控件结构、 键盘交互和可能的控件模式。

实现[IsContentElementCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.automationpeer.iscontentelementcore)和[IsControlElementCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.automationpeer.iscontrolelementcore)方法，以指示控件是否包含数据内容或实现交互角色中的用户界面 （或两者）。 默认情况下，这两个方法返回 `true`。 这些设置提高了屏幕阅读器等自动化工具的可用性，此类工具可使用这些方法筛选自动化树。 如果你[GetPattern](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.automationpeer.getpattern)方法将模式处理到一个子元素对等的子元素对等方的[IsControlElementCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.automationpeer.iscontrolelementcore)方法可返回 false 来隐藏自动化树中的子元素对等方。 例如，在滚动[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)由处理[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)，和的自动化对等方[PatternInterface.Scroll](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.patterninterface#System_Windows_Automation_Peers_PatternInterface_Scroll)返回[GetPattern](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.automationpeer.getpattern)方法[ScrollViewerAutomationPeer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.scrollviewerautomationpeer)关联[ListBoxAutomationPeer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.listboxautomationpeer)。因此，[IsControlElementCore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.automationpeer.iscontrolelementcore)方法[ScrollViewerAutomationPeer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.scrollviewerautomationpeer)返回`false`，以便[ScrollViewerAutomationPeer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.scrollviewerautomationpeer)没有显示在自动化树中。

自动化对等应为控件提供合适的默认值。 请注意，引用你的控件的 XAML 可以通过重写 core 方法的对等实现包括[AutomationProperties](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.automationproperties)属性。 例如，以下 XAML 创建的按钮具有两个自定义的 UI 自动化 属性。

XAML复制

```xaml
<Button AutomationProperties.Name="Special"   
    AutomationProperties.HelpText="This is a special button."/>  
```

### 实现模式提供程序

如果拥有元素直接派生自定义提供程序实现的接口显式声明[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)。 例如，下面的代码声明的对等方[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)实现一个范围值。

C#复制

```csharp
public class RangePeer1 : FrameworkElementAutomationPeer, IRangeValueProvider { }  
```

如果所属的控件派生自指定类型的控件如[RangeBase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.rangebase)，对等方可以派生自等效的派生对等类。 在这种情况下，对等方将派生自[RangeBaseAutomationPeer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.rangebaseautomationpeer)，其中提供的基实现[IRangeValueProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.provider.irangevalueprovider)。 以下代码演示了此类对等的声明。

C#复制

```csharp
public class RangePeer2 : RangeBaseAutomationPeer { }  
```

有关示例实现，请参阅[带有主题和 UI 自动化支持示例的 NumericUpDown 自定义控件](https://go.microsoft.com/fwlink/?LinkID=160025)。

### 引发事件

自动化客户端可订阅自动化事件。 自定义控件必须报告更改，以通过调用控件状态[RaiseAutomationEvent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.automationpeer.raiseautomationevent)方法。同样，属性值发生更改时调用[RaisePropertyChangedEvent](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.automation.peers.automationpeer.raisepropertychangedevent)方法。 以下代码演示了如何在控件代码内获取对等对象，并调用一个方法来引发事件。 作为一种优化，该代码会确定是否有适用于此事件类型的任何侦听器。 仅当有侦听器时才引发事件，可避免不必要的开销，有助于控件保持响应状态。

C#复制

```csharp
if (AutomationPeer.ListenerExists(AutomationEvents.PropertyChanged))
{
    NumericUpDownAutomationPeer peer = 
        UIElementAutomationPeer.FromElement(nudCtrl) as NumericUpDownAutomationPeer;

    if (peer != null)
    {
        peer.RaisePropertyChangedEvent(
            RangeValuePatternIdentifiers.ValueProperty,
            (double)oldValue,
            (double)newValue);
    }
}
```