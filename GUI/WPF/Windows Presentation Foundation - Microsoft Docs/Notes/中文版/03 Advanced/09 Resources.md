# [Resources](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/resources-wpf)

资源是可以在应用程序中的不同位置重复使用的对象。 WPF 支持不同类型的资源。 这些资源是主要两种类型的资源： XAML 资源和资源数据文件。 XAML 资源的示例包括画笔和样式。 资源数据文件是应用程序所需的非可执行文件数据文件。

[XAML 资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-resources)
[WPF 应用程序资源、内容和数据文件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/wpf-application-resource-content-and-data-files)
[WPF 中的 Pack URI](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/pack-uris-in-wpf)

## [XAML Resources](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/xaml-resources)

资源是可以在应用程序中的不同位置重复使用的对象。 资源的示例包括画笔和样式。 本概述介绍如何使用中的资源XAML。 此外可以创建并使用代码，或者通过互换使用代码访问资源和可扩展应用程序标记语言 (XAML)。有关详细信息，请参阅[资源和代码](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/resources-and-code)。

> 本主题中所述的资源文件是不同的资源文件中所述[WPF 应用程序资源、 内容和数据文件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/wpf-application-resource-content-and-data-files)和不同于嵌入或链接的资源中所述[管理应用程序资源 (.NET)](https://msdn.microsoft.com/library/f2582734-8ada-4baa-8a7c-e2ef943ddf7e)。

### 在 XAML 中使用资源

下面的示例定义[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)作为页面的根元素上的资源。 该示例然后引用的资源，并使用它来设置多个子元素，其中包括的属性[Ellipse](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.ellipse)、 一个[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)，和一个[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。

```xaml
<Page Name="root"
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
>
  <Page.Resources>
    <SolidColorBrush x:Key="MyBrush" Color="Gold"/>
    <Style TargetType="Border" x:Key="PageBackground">
      <Setter Property="Background" Value="Blue"/>
    </Style>
    <Style TargetType="TextBlock" x:Key="TitleText">
      <Setter Property="Background" Value="Blue"/>
      <Setter Property="DockPanel.Dock" Value="Top"/>
      <Setter Property="FontSize" Value="18"/>
      <Setter Property="Foreground" Value="#4E87D4"/>
      <Setter Property="FontFamily" Value="Trebuchet MS"/>
      <Setter Property="Margin" Value="0,40,10,10"/>
    </Style>
    <Style TargetType="TextBlock" x:Key="Label">
      <Setter Property="DockPanel.Dock" Value="Right"/>
      <Setter Property="FontSize" Value="8"/>
      <Setter Property="Foreground" Value="{StaticResource MyBrush}"/>
      <Setter Property="FontFamily" Value="Arial"/>
      <Setter Property="FontWeight" Value="Bold"/>
      <Setter Property="Margin" Value="0,3,10,0"/>
    </Style>
  </Page.Resources>
  <StackPanel>
    <Border Style="{StaticResource PageBackground}">
      <DockPanel>
        <TextBlock Style="{StaticResource TitleText}">Title</TextBlock>
        <TextBlock Style="{StaticResource Label}">Label</TextBlock>
        <TextBlock DockPanel.Dock="Top" HorizontalAlignment="Left" FontSize="36" Foreground="{StaticResource MyBrush}" Text="Text" Margin="20" />
        <Button DockPanel.Dock="Top" HorizontalAlignment="Left" Height="30" Background="{StaticResource MyBrush}" Margin="40">Button</Button>
        <Ellipse DockPanel.Dock="Top" HorizontalAlignment="Left" Width="100" Height="100" Fill="{StaticResource MyBrush}" Margin="40" />
      </DockPanel>
    </Border>
  </StackPanel>
</Page>
```

每个框架级元素 ([FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)或[FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement)) 具有[Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.resources)属性，它是包含资源的属性 (作为[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)) 某个资源定义。 您可以在任意元素上定义资源。 但是，资源最常定义在根元素，它是[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)在示例中。

资源字典中的每个资源都必须具有唯一键。 在标记中定义的资源，则指定通过唯一键[X:key 指令](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-key-directive)。 通常情况下，这个键是一个字符串；但是，也可使用相应的标记扩展将其设置为其他对象类型。 非字符串键用于资源使用的某些功能区中WPF，尤其是样式、 组件资源和数据样式。

在定义好资源后，可以使用能够指定键名称的资源标记扩展语法来引用该资源以用于属性值，例如：

XAML复制

```xaml
<Button Background="{StaticResource MyBrush}"/>
<Ellipse Fill="{StaticResource MyBrush}"/>
```

在前面的示例中，当XAML加载程序处理值`{StaticResource MyBrush}`的[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)属性[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)，资源查找逻辑首先检查的资源字典[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)元素。 如果[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)不具有定义的资源键`MyBrush`（不是; 其资源集合为空），查找接下来检查父元素的[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)，这是[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)。 因此，当您定义资源上[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)根元素，在逻辑树中的所有元素[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)可以访问它，并可以重复使用相同的资源，为设置任何属性的值时，接受[Type](https://docs.microsoft.com/zh-cn/dotnet/api/system.type)的资源表示。 在上一示例中，相同`MyBrush`资源设置两个不同的属性：[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)的[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)，和[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)的[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)。



### 静态和动态资源

资源可以作为静态资源或动态资源加以引用。 这是通过使用任一[StaticResource 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/staticresource-markup-extension)或[DynamicResource 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dynamicresource-markup-extension)。 标记扩展是一项功能XAML使您可以通过使用标记扩展来处理属性字符串，并返回到该对象指定的对象引用由此XAML加载程序。 有关标记扩展行为的详细信息，请参阅[标记扩展和 WPF XAML](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/markup-extensions-and-wpf-xaml)。

当使用标记扩展时，通常会以字符串的形式提供一个或多个参数，这些参数由该特定标记扩展来处理，而不是在所设置属性的上下文中进行计算。 [StaticResource 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/staticresource-markup-extension)通过查找所有可用的资源字典中的键的值来处理键。这个操作会在加载期间执行；执行时，加载进程需要分配采用静态资源引用的属性值。 [DynamicResource 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dynamicresource-markup-extension)改为进程通过创建一个表达式，并且该表达式的键会一直保持未计算直到实际运行该应用程序，在这段时间表达式进行计算，并提供一个值。

在引用某个资源时，下列注意事项可能会对于使用静态资源引用还是使用动态资源引用产生影响：

- 如何为应用程序创建资源的整体设计 (每页上，在应用程序中，在宽松XAML，在资源的唯一程序集中)。
- 应用程序的功能：实时更新资源是应用程序的要求之一吗?
- 该资源引用类型的相应查找行为。
- 特定的属性或资源类型，以及这些类型的本机行为。

#### 静态资源

在以下情况下，最适合使用静态资源引用：

- 所采用的应用程序设计将其所含的大多数资源都集中到了页面级或应用程序级资源字典中。 静态资源引用不会基于运行时行为（如重载页面）重新进行计算，因此可以通过以下方式在一定程度上提高性能：当资源和所采用的应用程序设计无需使用大量动态资源引用时，就避免使用。
- 设置不在属性的值[DependencyObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyobject)或[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)。
- 正在创建的资源字典将编译成 DLL，并将打包为应用程序的一部分或在应用程序间共享。
- 正在为自定义控件创建主题，并定义要在主题中使用的资源。 在这种情况下，通常不希望执行动态资源引用查找行为，而是希望执行静态资源引用行为，以确保查找可预测且自包含到主题中。 使用动态资源引用时，即使主题中的引用会保持未计算状态直至运行时，且主题可能会得到应用，但某个本地元素仍会重新定义主题正尝试引用的键，并且该本地元素在查找期间会排在主题前面。 如果发生这种情况，主题的行为将偏离预期方式。
- 正在使用资源设置大量依赖属性。 依赖属性会通过属性系统启用有效值缓存功能；因此，如果为可在加载时进行计算的依赖属性提供了值，则该依赖属性不必检查是否存在重新计算的表达式并可返回上一个有效值。 此项技术可以提高性能。
- 你想要为所有使用者更改基础资源，或者你想要使用的每个使用者维护单独的可写实例[x： 共享属性](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-shared-attribute)。

#### 静态资源查找行为

1. 查找进程在用于设置属性的元素所定义的资源字典中查找请求的键。
2. 查找进程随后会向上遍历逻辑树，以查找父元素及其资源字典。 直至到达根元素，遍历操作才会停止。
3. 接下来，将检查应用程序资源。 应用程序的资源是由定义的资源字典中的这些资源[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)对象在WPF应用程序。

从资源字典中进行的静态资源引用必须引用已在资源引用前进行过词法定义的资源。 静态资源引用无法解析前向引用。 因此，如果使用静态资源引用，则必须对资源字典的结构进行设计，以便在每个相应资源字典的开头或临近位置定义要按资源使用的资源。

静态资源查找可以扩展到主题，或系统资源，但支持此功能只是因为XAML加载程序延迟了请求。 为了让页面加载时的运行时主题正确地应用至该应用程序，这种延迟是必需的。 但是，如果某些键已知仅存在于主题中或属于系统资源，则建议不要使用针对这类键的静态资源引用。 这是因为如果用户实时更改主题，此类引用不会重新计算。 请求主题或系统资源时，动态资源引用更为可靠。 例外情况是当主题元素自身请求另一个资源。 出于上述原因，这些引用应该是静态资源引用。

因找不到静态资源引用而引发的异常行为各不相同。 如果资源被延迟，则异常会在运行时发生。 如果资源未延迟，则异常会在加载时发生。

#### 动态资源

在以下情况下，最适合使用动态资源：

- 资源的值取决于直到运行时才能获悉的条件。 这包括系统资源或用户可设置的资源。 例如，可以创建引用系统属性的 setter 值，如公开[SystemColors](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemcolors)， [SystemFonts](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemfonts)，或[SystemParameters](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemparameters)。 这些值是真正的动态值，因为它们最终来自用户和操作系统的运行时环境。 或许还拥有可能会发生变化的应用程序级主题，而页面级资源访问也必须捕获其中的变化。
- 正在为自定义控件创建或引用主题样式。
- 你想要调整的内容[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)应用程序生存期内。
- 拥有存在相互依赖关系且可能需要进行前向引用的复杂资源结构。 静态资源引用不支持前向引用，但动态资源引用却支持，因为该资源不需要进行计算，直到运行时，并且前向引用是不相关的概念。
- 从编译或工作集的角度来看，所引用的资源特别大，而且该资源在页面加载时可能不会立即使用。 静态资源引用总是从加载XAML加载页面时; 但是，动态资源引用不实际使用之前未加载。
- 所创建样式中的 Setter 值可能来自受主题或其他用户设置影响的其他值。
- 正在将资源应用于可能会在应用程序生存期内在逻辑树中重定父级的元素。 父级更改后，资源查找范围也可能会随之更改；因此，如果希望重定父级的元素的资源基于新范围重新进行计算，请始终使用动态资源引用。

#### 动态资源查找行为

动态资源引用的资源查找行为与在代码中的查找行为，如果您调用[FindResource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.findresource)或[SetResourceReference](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.setresourcereference)。

1. 查找进程在用于设置属性的元素所定义的资源字典中查找请求的键。
   - 如果该元素定义[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.style)属性，[Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style.resources)中的字典[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)检查。
   - 如果该元素定义[Template](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.template)属性，[Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworktemplate.resources)中的字典[FrameworkTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworktemplate)检查。
2. 查找进程随后会向上遍历逻辑树，以查找父元素及其资源字典。 直至到达根元素，遍历操作才会停止。
3. 接下来，将检查应用程序资源。 应用程序的资源是由定义的资源字典中的这些资源[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)对象在WPF应用程序。
4. 在主题资源字典中查找当前处于活动状态的主题。 如果主题在运行时发生更改，则会重新计算值。
5. 检查系统资源。

异常行为（如果有）各不相同：

- 如果请求的资源的[FindResource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.findresource)调用，但未找到，则引发异常。
- 如果请求的资源的[TryFindResource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.tryfindresource)调用，但未找到，会引发任何异常，但返回的值是`null`。 如果要设置的属性不接受`null`，则仍可能会引发更深的异常 （这取决于要设置的单个属性）。
- 如果通过中的动态资源引用请求了资源XAML，和未找到，则行为取决于常规属性系统中，但常规行为是像在资源所在的级别发生任何属性设置操作。 例如，如果尝试使用无法计算的资源来设置个别按钮元素上的背景，则值设置操作不会产生任何结果，但是有效的值可能仍来自属性系统和值优先级中的其他参与者。例如，背景值可能仍来自在本地定义的某个按钮样式，或来自主题样式。 对于并非由主题样式定义的属性，资源计算失败后的有效值可能来自属性元数据中的默认值。

#### 限制

动态资源引用存在一些重要限制。 必须至少满足以下条件之一：

- 要设置的属性必须是属性上[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)或[FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement)。 属性必须为后盾[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)。
- 中的值是引用[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style) [Setter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.setter)。
- 要设置的属性必须是属性上[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)提供的值作为[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)或[FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement)属性，或[Setter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.setter)值。

因为要设置的属性必须是[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)或[Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable)属性，属性的大多数更改可以传播到 UI，因为属性更改 （更改的动态资源值） 会经由属性系统。 大多数控件都包含逻辑将强制执行控件的另一个布局，如果[DependencyProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.dependencyproperty)更改和属性可能会影响布局。 但是，并非所有属性都都会[DynamicResource 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dynamicresource-markup-extension)作为它们的值保证提供的值中在 UI 中的实时更新的方式。 此功能可能仍会因属性、属性所属的类型，甚至因应用程序的逻辑结果而异。



### 样式、数据模板和隐式键

前面曾提到中的所有项[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)必须有一个键。 但是，这并不并不意味着所有资源必须都具有显式`x:Key`。 多种对象类型在定义为资源时都支持隐式键，其键值会与另一属性的值绑定。 这称为隐式键，而`x:Key`属性则为显式键。 任何隐式键都可通过指定显式键来覆盖。

资源的一个非常重要的方案是在定义时[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)。 事实上，[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)由于样式本质上是可供重复使用几乎始终定义为使用的资源字典中的条目。 有关样式的详细信息，请参阅[样式和模板化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/styling-and-templating)。

控件样式可通过隐式键来创建和引用。 用于定义控件默认外观的主题样式依赖于该隐式键。 从请求它的角度来看，隐式键是[Type](https://docs.microsoft.com/zh-cn/dotnet/api/system.type)控件本身。 从资源定义的角度来看，隐式键是[TargetType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style.targettype)的样式。 因此，如果要创建自定义控件的主题，现有主题样式，即创建进行交互的样式不需要指定[X:key 指令](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-key-directive)为此， [Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)。 另外，如果想要使用主题样式，则根本无需指定任何样式。 例如，以下样式定义的工作原理，即使[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)资源似乎不具有键：

XAML复制

```xaml
<Style TargetType="Button">
  <Setter Property="Background">
    <Setter.Value>
      <LinearGradientBrush>
        <GradientStop Offset="0.0" Color="AliceBlue"/>
        <GradientStop Offset="1.0" Color="Salmon"/>           
      </LinearGradientBrush>
    </Setter.Value>
  </Setter>  
  <Setter Property="FontSize" Value="18"/>
</Style>
```

该样式实际上有一个键： 隐式键`typeof(` [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button) `)`。 在标记中，可以指定[TargetType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style.targettype)直接作为类型名称 (或者可以根据需要使用[{x: Type...}](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-type-markup-extension) 若要返回[Type](https://docs.microsoft.com/zh-cn/dotnet/api/system.type)。

通过使用的默认主题样式机制WPF，为运行时样式的应用样式[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)页上，即使[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)本身不会尝试指定其[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.style)属性或特定资源引用的样式。 比主题字典样式，使用相同键的主题字典样式位于查找序列中先前找到的页中定义的样式。 您可能只需指定`<Button>Hello</Button>`页上，使用定义的样式中的任意位置[TargetType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style.targettype)的`Button`会应用于该按钮。 如果需要，可以仍显式键使用类型值与相同的样式[TargetType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style.targettype)、 清楚起见，在您的标记，但这是可选的。

如果不在控件上适用样式的隐式键[OverridesDefaultStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.overridesdefaultstyle)是`true`(另请注意，[OverridesDefaultStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.overridesdefaultstyle)可能设置为本机行为对于控件类中，而不是显式的控件实例的一部分)。 此外，为了支持派生的类应用场景的隐式键，控件必须重写[DefaultStyleKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.defaultstylekey)(作为的一部分提供的所有现有控件WPF执行此操作)。 有关样式、 主题和控件设计的详细信息，请参阅[控件的设计准则的指导原则](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/guidelines-for-designing-stylable-controls)。

[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate) 还有一个隐式键。 隐式键[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)是[DataType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate.datatype)属性值。 [DataType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate.datatype) 也可以指定为的类型名称而不是使用显式[{x: Type...}](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-type-markup-extension). 有关详细信息，请参阅[数据模板化概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-templating-overview)。

### [Resources and Code](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/resources-and-code)

本概述主要介绍如何使用代码（而非 可扩展应用程序标记语言 (XAML) 语法）来访问或创建 Windows Presentation Foundation (WPF) 资源。 有关常规资源用法以及 XAML 语法角度的资源的详细信息，请参阅 [XAML 资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-resources)。

#### 从代码访问资源

用于识别通过 XAML 定义的资源的键也用于检索特定资源（如果你在代码中请求此资源）。 从代码检索资源的最简单方法是调用[FindResource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.findresource)或[TryFindResource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.tryfindresource)从应用程序中的框架级对象的方法。 这两个方法之间的行为差异在于当未找到所请求的键时所发生的情况。 [FindResource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.findresource) 引发了异常;[TryFindResource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.tryfindresource)不会引发异常，而是返回`null`。 每个方法都将资源键作为一个输入参数，并返回一个松散类型化对象。 资源键通常是字符串，但有时也用作非字符串；有关详细信息，请参阅[将对象用作键](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/resources-and-code#objectaskey)部分。 通常应将返回的对象强制转换为请求资源时设置的属性所要求的类型。 代码资源解析的查找逻辑与动态资源引用 XAML 情况相同。 对资源的搜索从调用元素开始，然后继续搜索逻辑树中的后续父元素。 如果必要，将继续查找应用程序资源、主题以及系统资源。 资源的代码请求将正确地说明资源字典（可能排在从 XAML 加载的资源字典之后）中的运行时更改，也将说明实时系统资源更改。

以下是一个简短的代码示例，通过键查找资源，并使用返回的值来设置属性，作为实现[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件处理程序。

```csharp
void SetBGByResource(object sender, RoutedEventArgs e)
{
  Button b = sender as Button;
  b.Background = (Brush)this.FindResource("RainbowBrush");
}
```

将分配的资源引用的一种替代方法是[SetResourceReference](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.setresourcereference)。 该方法采用两个参数：资源的键，以及特定依赖属性（应向其分配资源值的元素实例上的依赖属性）的标识符。 就功能而言，此方法是相同的，且具有无需强制转换任何返回值的优点。

仍另一种方法以编程方式访问资源访问的内容是[Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.resources)作为字典的属性。 通过访问该属性包含的字典，还可以向现有集合添加新资源、检查集合中是否已经存在给定的键名称以及执行其他字典/集合操作。 如果你正在编写WPF完全在代码中的应用程序，您还可以创建整个集合在代码中，将密钥分配给它，，然后将分配到的已完成的集合[Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.resources)建立的元素的属性。 这将在下一部分介绍。

你可以在任何给定索引[Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.resources)集合，并为该索引，但你使用特定密钥应注意访问这种方式中的资源未遵循资源解析的正常运行时规则。 你访问的仅是该特定集合。 如果在请求的键处未找到有效的对象，则资源查找将不会遍历范围直至根或应用程序。 但是，在某些情况下，正因为对键的搜索范围进行了更多的约束，才使得此方法在性能上具有优势。 请参阅[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)如何直接使用的资源字典的更多详细信息的类。



#### 使用代码创建资源

如果要通过代码方式创建整个 WPF 应用程序，可能也需要通过代码方式创建该应用程序中的任何资源。 若要实现此目的，创建一个新[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)实例，并将所有资源添加到字典使用连续调用[ResourceDictionary.Add](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary.add)。 然后，使用[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)因此创建设置[Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.resources)位于页范围内的元素上的属性或[Application.Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.resources)。 此外可以维护[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)作为独立对象，而无需将其添加到元素。 但是，如果这样做，必须通过项键来访问其中的资源，就好像它是泛型字典一样。 一个[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)，它未附加到元素`Resources`属性将不存在元素树的一部分并可供查找序列中没有作用域[FindResource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.findresource)和相关方法。

#### 将对象用作键

大多数资源用法都会将资源的键设置为字符串。 但是，各个 WPF 功能都特意不使用字符串类型来指定键，而是将此参数设置为对象。 WPF 样式和主题支持使用按对象对资源进行键控的功能。 主题中成为否则非样式的控件的默认样式的样式来进行键控的[Type](https://docs.microsoft.com/zh-cn/dotnet/api/system.type)它们应当应用于的控件。 按类型进行键控提供了一种可靠的查找机制，该机制作用于每个控件类型的默认实例，即使派生类型不具有默认样式，也可以通过反射检测到类型，并将类型用于设置派生类的样式。 您可以指定[Type](https://docs.microsoft.com/zh-cn/dotnet/api/system.type)密钥对中定义的资源XAML通过使用[X:type 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-type-markup-extension)。 对于支持 WPF 功能的其他非字符串键用法，也存在类似扩展，如 [ComponentResourceKey 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/componentresourcekey-markup-extension)。

### [Merged Resource Dictionaries](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/merged-resource-dictionaries)

Windows Presentation Foundation (WPF) 资源支持合并资源字典功能。 此功能提供一种方法，可在编译的 XAML应用程序外部定义 WPF 应用程序的资源部分。 然后可以在应用程序之间共享资源，还可更方便地将资源隔离以进行本地化。

#### 引入合并资源字典

在标记中，使用以下语法将合并资源字典引入页面：

```xaml
<Page.Resources>
  <ResourceDictionary>
    <ResourceDictionary.MergedDictionaries>
      <ResourceDictionary Source="myresourcedictionary.xaml"/>
      <ResourceDictionary Source="myresourcedictionary2.xaml"/>
    </ResourceDictionary.MergedDictionaries>
  </ResourceDictionary>
</Page.Resources>
```

请注意，[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)元素不具有[X:key 指令](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-key-directive)，通常需要的资源集合中的所有项。 但另一个[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)中引用[MergedDictionaries](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary.mergeddictionaries)集合是一种特殊情况，保留此合并的资源字典方案。[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)引入了合并资源字典不能有[X:key 指令](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-key-directive)。 通常情况下，每个[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)内[MergedDictionaries](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary.mergeddictionaries)集合指定[Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary.source)属性。 值[Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary.source)应为统一资源标识符 (URI)解析到要合并的资源文件的位置。目标URI必须是另一个XAML文件中，使用[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)作为其根元素。

 备注

它是合法定义中的资源[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)作为指定的替代方法指定为合并字典[Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary.source)，或除了任何资源都包含从指定的源。 但是，这不是一种常见方案；合并字典的主要方案是从外部文件位置合并资源。 如果你想要指定页的标记中的资源，则应通常定义这些主[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)而不是在合并的字典。

#### 合并字典的行为

合并字典中的资源占用资源查找范围中的一个位置，此范围恰好在它们合并到的主要资源字典中的范围之后。 尽管任何字典中的资源键必须唯一，但一个资源键可在一组合并字典中多次存在。 在这种情况下，返回的资源将来自按顺序在找到的最后一个字典[MergedDictionaries](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary.mergeddictionaries)集合。 如果[MergedDictionaries](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary.mergeddictionaries)集合中定义XAML，则合并的字典集合中的顺序是提供在标记中元素的顺序。 如果在主要字典和合并的字典中均定义了同一个键，则返回的资源将来自主要字典。 这些范围规则同等地适用于静态资源引用和动态资源引用。

##### 合并字典和代码

可通过代码将合并字典添加到 `Resources` 字典。 默认情况下，最初为空[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)存在于任何`Resources`属性都具有默认值，最初为空[MergedDictionaries](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary.mergeddictionaries)集合属性。 若要添加的代码通过合并的字典，则获取到所需的主副本的引用[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)，获取其[MergedDictionaries](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary.mergeddictionaries)属性值，然后调用`Add`泛型`Collection`中包含的[MergedDictionaries](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary.mergeddictionaries)。 添加的对象必须是一个新[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)。 在代码中，未设置[Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary.source)属性。 相反，你必须获取[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)通过创建或加载其中一个对象。 加载现有的一种方法[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)来调用[XamlReader.Load](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.xamlreader.load)上的现有XAML具有文件流[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)根，然后强制转换[XamlReader.Load](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.markup.xamlreader.load)返回值为[ResourceDictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary)。

##### 合并资源字典 URI

可通过几种技术来包括合并资源字典，具体由将使用的 统一资源标识符 (URI) 格式指示。 这些技术可概括地分为两类：作为项目的一部分编译的资源，和不作为项目的一部分编译的资源。

对于作为项目的一部分编译的资源，可使用引用资源位置的相对路径。 相对路径会在编辑期间计算。 必须将资源作为“资源”生成操作定义为项目的一部分。 如果将资源 .xaml 文件作为“资源”包括在项目中，则无需将资源文件复制到输出目录，因为资源已包括在编译的应用程序中。 也可以使用“内容”生成操作，但必须将文件复制到输出目录，还需将相同路径关系中的资源文件部署到可执行文件。

> 不要使用“嵌入资源”生成操作。 支持生成操作本身WPF应用程序，但的分辨率[Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcedictionary.source)不会合并[ResourceManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.resources.resourcemanager)，并因此不能将单个资源分离流外。 您仍可以使用嵌入的资源，出于其他目的，只要还使用[ResourceManager](https://docs.microsoft.com/zh-cn/dotnet/api/system.resources.resourcemanager)才能访问资源。

还有一种相关技术是使用指向 XAML 文件的 Pack URI，并将其作为“源”进行引用。 Pack URI 可启用对引用程序集的组件和其他技术的引用。 有关 Pack URI 的详细信息，请参阅 [WPF 应用程序资源、内容和数据文件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/app-development/wpf-application-resource-content-and-data-files)。

对于不作为项目的一部分编译的资源，URI 将在运行时计算。 可使用常见的 URI 传输（如 file: 或 http:）引用资源文件。 使用非编译资源方法的缺点是：file: 访问需要额外部署步骤，并且 http: 访问意味着需访问 Internet 安全区域。

##### 重用合并字典

可以重复使用或在应用程序之间共享合并资源字典，因为可以通过任何有效的 统一资源标识符 (URI) 引用要合并的资源字典。 执行此操作的确切方式取决于应用程序部署策略和所遵循的应用程序模型。 前面提及的 Pack URI 策略提供了一种方法，通常可通过共享程序集引用在开发期间跨多个项目将合并资源作为源使用。 在此方案中，资源仍由客户端分发，并且至少有一个应用程序必须部署引用的程序集。 还有可能通过使用 http 协议的分布式 URI 引用合并资源。

另一种合并字典/应用程序部署的可能方案是将合并字典编写为本地应用程序文件或编写到共享存储。

##### 本地化

如果需要本地化的资源保留为松散的 XAML，并且隔离于将合并为主要字典的字典，则可单独本地化这些文件。这是本地化附属资源程序集的轻量级替代方法。 有关详细信息，请参阅 [WPF 全球化和本地化概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/wpf-globalization-and-localization-overview)。

### [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/resources-how-to-topics)

本部分中的主题介绍如何使用 Windows Presentation Foundation (WPF) 资源。

[定义和引用资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-define-and-reference-a-resource)
[使用应用程序资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-use-application-resources)
[使用 SystemFonts](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-use-systemfonts)
[使用系统字体键](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-use-system-fonts-keys)
[使用 SystemParameters](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-use-systemparameters)
[使用系统参数键](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/how-to-use-system-parameters-keys)

#### [Define and Reference a Resource](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-define-and-reference-a-resource)

此示例演示如何定义资源，通过使用中的一个属性引用该可扩展应用程序标记语言 (XAML)。

下面的示例定义两种类型的资源：[SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)资源和多个[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)资源。 [SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)资源`MyBrush`用于提供多个属性的值，每个需要[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)键入值。 [Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)资源`PageBackground`，`TitleText`和`Label`每个目标特定控件类型。 样式时设置的各种不同的属性上的目标控件，该样式资源引用的资源键，用于设置[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.style)属性中定义的多个特定的控件元素XAML。

第一个属性的 setter 中注意`Label`样式也引用`MyBrush`前面定义的资源。 这是一种常用技术，但请务必记住，资源是分析，并输入到的资源字典中，系统将提供的顺序。 如果使用的字典中找到的顺序也请求资源[StaticResource 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/staticresource-markup-extension)另一个资源中引用它们。 请确保你引用的任何资源比然后请求该资源所在的资源集合中之前定义。 如果有必要，您可以解决资源这样的严格的创建顺序通过使用[DynamicResource 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/dynamicresource-markup-extension)相反，引用在运行时的资源，但应注意，此 DynamicResource方法对性能产生影响。 有关详细信息，请参阅[XAML 资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-resources)。

XAML复制

```xaml
<Page Name="root"
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
  <Page.Resources>
    <SolidColorBrush x:Key="MyBrush" Color="Gold"/>
    <Style TargetType="Border" x:Key="PageBackground">
      <Setter Property="Background" Value="Blue"/>
    </Style>
    <Style TargetType="TextBlock" x:Key="TitleText">
      <Setter Property="Background" Value="Blue"/>
      <Setter Property="DockPanel.Dock" Value="Top"/>
      <Setter Property="FontSize" Value="18"/>
      <Setter Property="Foreground" Value="#4E87D4"/>
      <Setter Property="FontFamily" Value="Trebuchet MS"/>
      <Setter Property="Margin" Value="0,40,10,10"/>
    </Style>
    <Style TargetType="TextBlock" x:Key="Label">
      <Setter Property="DockPanel.Dock" Value="Right"/>
      <Setter Property="FontSize" Value="8"/>
      <Setter Property="Foreground" Value="{StaticResource MyBrush}"/>
      <Setter Property="FontFamily" Value="Arial"/>
      <Setter Property="FontWeight" Value="Bold"/>
      <Setter Property="Margin" Value="0,3,10,0"/>
    </Style>
  </Page.Resources>
  <StackPanel>
    <Border Style="{StaticResource PageBackground}">
      <DockPanel>
        <TextBlock Style="{StaticResource TitleText}">Title</TextBlock>
        <TextBlock Style="{StaticResource Label}">Label</TextBlock>
        <TextBlock DockPanel.Dock="Top" HorizontalAlignment="Left" FontSize="36" Foreground="{StaticResource MyBrush}" Text="Text" Margin="20" />
        <Button DockPanel.Dock="Top" HorizontalAlignment="Left" Height="30" Background="{StaticResource MyBrush}" Margin="40">Button</Button>
        <Ellipse DockPanel.Dock="Top" HorizontalAlignment="Left" Width="100" Height="100" Fill="{StaticResource MyBrush}" Margin="40" />
      </DockPanel>
    </Border>
  </StackPanel>
</Page>
```

#### [Use Application Resources](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-use-application-resources)

本示例演示如何使用应用程序资源。

以下示例演示应用程序定义文件。 应用程序定义文件定义资源部分 (值为[Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.resources)属性)。 构成应用程序的所有其他页均可访问在应用程序级别定义的资源。 这种情况下，资源是声明样式。 包含控件模板的完整样式可能耗时较长，因为此示例中省略中定义的控件模板[ContentTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.contenttemplate)的样式的属性 setter。

```xaml
<Application.Resources>
  <Style TargetType="Button" x:Key="GelButton" >
    <Setter Property="Margin" Value="1,2,1,2"/>
    <Setter Property="HorizontalAlignment" Value="Left"/>
    <Setter Property="Template">
      <Setter.Value>
```

```xaml
      </Setter.Value>
    </Setter>
  </Style>
</Application.Resources>
```

下面的示例演示XAML页引用上例中定义的应用程序级资源。 使用引用资源[StaticResource 标记扩展](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/staticresource-markup-extension)，它指定请求的资源的唯一资源键。 在当前页中没有找到具有“GelButton”键的资源，所以请求资源的资源查找范围超出当前页，进入已定义的应用程序级资源。

```xaml
<StackPanel
  Name="root"
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  >
  <Button Height="50" Width="250" Style="{StaticResource GelButton}" Content="Button 1" />
  <Button Height="50" Width="250" Style="{StaticResource GelButton}" Content="Button 2" />
</StackPanel>
```

#### [Use SystemFonts](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-use-systemfonts)

此示例演示如何使用的静态资源[SystemFonts](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemfonts)样式或自定义按钮的类。

系统资源将系统确定的许多值以资源和属性的形式公开，以帮助创建与系统设置一致的视觉效果。 [SystemFonts](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemfonts)是包含这两个系统字体值作为静态属性和引用可用于在运行时动态访问这些值的资源键的属性的类。 例如，[CaptionFontFamily](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemfonts.captionfontfamily)是[SystemFonts](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemfonts)值，和[CaptionFontFamilyKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemfonts.captionfontfamilykey)是相应的资源键。

在中XAML，你可以使用的成员[SystemFonts](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemfonts)作为静态属性或动态资源引用 （静态属性值作为键）。 如果希望字体规格在应用程序运行时自动更新，请使用动态资源引用；否则，请使用静态值引用。

> 资源键属性名称后面附有“Key”后缀。

下面的示例演示如何访问和使用的属性[SystemFonts](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemfonts)作为静态值来设置样式或自定义按钮。 此标记示例将分配[SystemFonts](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemfonts)至一个按钮的值。

```xaml
<Button Margin="10, 10, 5, 5" Grid.Column="0" Grid.Row="3"      
     FontSize="{x:Static SystemFonts.IconFontSize}"
     FontWeight="{x:Static SystemFonts.MessageFontWeight}"
     FontFamily="{x:Static SystemFonts.CaptionFontFamily}">
     SystemFonts
</Button>
```

若要使用的值[SystemFonts](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemfonts)不需要在代码中，使用静态值或动态资源引用。 相反，使用的非键属性[SystemFonts](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemfonts)类。 尽管非键属性已明确定义的运行时行为的静态属性形式WPF承载系统将重新评估在真实时间中的属性，并且会适当考虑对系统值面向用户的更改。 以下示例演示如何指定按钮的字体设置。

```csharp
Button btncsharp = new Button();
btncsharp.Content = "SystemFonts";
btncsharp.Background = SystemColors.ControlDarkDarkBrush;
btncsharp.FontSize = SystemFonts.IconFontSize;
btncsharp.FontWeight = SystemFonts.MessageFontWeight;
btncsharp.FontFamily = SystemFonts.CaptionFontFamily;
cv1.Children.Add(btncsharp);
```

#### [Use System Fonts Keys](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-use-system-fonts-keys)

系统资源将多个系统规格以资源的形式公开，以帮助开发人员创建与系统设置一致的视觉效果。 [SystemFonts](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemfonts) 是一个类，包含系统字体值和绑定到这些值的系统字体资源 — 例如，[CaptionFontFamily](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemfonts.captionfontfamily)和[CaptionFontFamilyKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemfonts.captionfontfamilykey)。

系统字体规格可用作静态或动态资源。 如果希望字体规格在应用程序运行时自动更新，请使用动态资源；否则，请使用静态资源。

> 动态资源具有关键字*密钥*追加到属性名称。

以下示例演示如何访问和使用系统字体动态资源来设计按钮样式或自定义按钮。 这XAML的示例创建分配的按钮样式[SystemFonts](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemfonts)至一个按钮的值。

```xaml
<Style x:Key="SimpleFont" TargetType="{x:Type Button}">
    <Setter Property = "FontSize" Value= "{DynamicResource {x:Static SystemFonts.IconFontSizeKey}}"/>
    <Setter Property = "FontWeight" Value= "{DynamicResource {x:Static SystemFonts.MessageFontWeightKey}}"/>
    <Setter Property = "FontFamily" Value= "{DynamicResource {x:Static SystemFonts.CaptionFontFamilyKey}}"/>
</Style>
```

#### [Use SystemParameters](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-use-systemparameters)

此示例演示如何访问和使用的属性[SystemParameters](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemparameters)样式或自定义按钮。

系统资源将多个基于系统的设置以资源的形式公开，以帮助创建与系统设置一致的视觉效果。 [SystemParameters](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemparameters)是一个类，包含系统参数值属性，并将绑定到值的资源键。 例如，[FullPrimaryScreenHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemparameters.fullprimaryscreenheight)是[SystemParameters](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemparameters)属性值和[FullPrimaryScreenHeightKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemparameters.fullprimaryscreenheightkey)是相应的资源键。

在中XAML，你可以使用的成员[SystemParameters](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemparameters)作为静态属性使用或动态资源引用 （静态属性值作为键）。 如果希望基于系统的值在应用程序运行时自动更新，请使用动态资源引用；否则，请使用静态引用。 资源键具有后缀`Key`追加到属性名称。

下面的示例演示如何访问和使用的静态值[SystemParameters](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemparameters)样式或自定义按钮。 此标记示例调整按钮大小通过应用[SystemParameters](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemparameters)至一个按钮的值。

```xaml
<Button FontSize="8" Margin="10, 10, 5, 5" Grid.Column="0" Grid.Row="5"      
     HorizontalAlignment="Left" 
     Height="{x:Static SystemParameters.CaptionHeight}"
     Width="{x:Static SystemParameters.IconGridWidth}">
     SystemParameters
</Button>
```

若要使用的值[SystemParameters](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemparameters)不需要在代码中，使用静态引用或动态资源引用。 相反，使用的值[SystemParameters](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemparameters)类。 尽管非键属性已明确定义为静态属性，运行时行为的WPF系统承载将实时重新计算属性，并且会适当考虑对系统值面向用户的更改。 下面的示例演示如何使用设置的宽度和按钮的高度[SystemParameters](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemparameters)值。

```csharp
Button btncsharp = new Button();
btncsharp.Content = "SystemParameters";
btncsharp.FontSize = 8;
btncsharp.Background = SystemColors.ControlDarkDarkBrush;
btncsharp.Height = SystemParameters.CaptionHeight;
btncsharp.Width = SystemParameters.IconGridWidth;
cv2.Children.Add(btncsharp);
```

#### [Use System Parameters Keys](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/how-to-use-system-parameters-keys)

系统资源将多个系统规格以资源的形式公开，以帮助开发人员创建与系统设置一致的视觉效果。[SystemParameters](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemparameters) 是一个类，包含系统参数值和绑定到这些值的资源键 — 例如，[FullPrimaryScreenHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemparameters.fullprimaryscreenheight)和[FullPrimaryScreenHeightKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemparameters.fullprimaryscreenheightkey)。 系统参数规格可用作静态或动态资源。 如果希望参数规格在应用程序运行时自动更新，请使用动态资源；否则，请使用静态资源。

> 动态资源具有关键字*密钥*追加到属性名称。

以下示例演示如何访问和使用系统参数动态资源来设计按钮样式或自定义按钮。 这XAML示例调整按钮大小分配[SystemParameters](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemparameters)为按钮的宽度和高度的值。

```xaml
<Style x:Key="SimpleParam" TargetType="{x:Type Button}">
    <Setter Property = "Height" Value= "{DynamicResource {x:Static SystemParameters.CaptionHeightKey}}"/>
    <Setter Property = "Width" Value= "{DynamicResource {x:Static SystemParameters.IconGridWidthKey}}"/>
</Style>
```