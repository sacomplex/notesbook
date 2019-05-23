# [TreeView](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/treeview)

[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)控件显示的层次结构中使用可折叠的节点的信息。

下图是一种[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)有嵌套的控件[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)控件。
![TreeView 图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/treeviewillustration.jpg)

## [TreeView Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/treeview-overview)

[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)控件提供了一种方法，通过使用可折叠节点在层次结构中显示的信息。 本主题介绍[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)和[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)控件，并提供其用法的简单示例。

### 什么是 TreeView？

[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview) 是[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)通过使用嵌套项[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)控件。 下面的示例创建[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)。

```xaml
<TreeView Name="myTreeViewEvent" >
  <TreeViewItem Header="Employee1" IsSelected="True">
    <TreeViewItem Header="Jesper Aaberg"/>
    <TreeViewItem Header="Employee Number">
      <TreeViewItem Header="12345"/>
    </TreeViewItem>
    <TreeViewItem Header="Work Days">
      <TreeViewItem Header="Monday"/>
      <TreeViewItem Header="Tuesday"/>
      <TreeViewItem Header="Thursday"/>
    </TreeViewItem>
  </TreeViewItem>
  <TreeViewItem Header="Employee2">
    <TreeViewItem Header="Dominik Paiha"/>
    <TreeViewItem Header="Employee Number">
      <TreeViewItem Header="98765"/>
    </TreeViewItem>
    <TreeViewItem Header="Work Days">
      <TreeViewItem Header="Tuesday"/>
      <TreeViewItem Header="Wednesday"/>
      <TreeViewItem Header="Friday"/>
    </TreeViewItem>
  </TreeViewItem>
</TreeView>
```

### 创建 TreeView

[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)控件包含的层次结构[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)控件。 一个[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)控件是[HeaderedItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headereditemscontrol)具有[Header](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headereditemscontrol.header)和[Items](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.items)集合。

如果您要定义[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)通过使用可扩展应用程序标记语言 (XAML)，可以显式定义[Header](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headereditemscontrol.header)内容的[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)控件以及组成其集合的项。 上图演示了此方法。

此外可以指定[ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource)作为数据源，然后指定[HeaderTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headereditemscontrol.headertemplate)并[ItemTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemtemplate)可以定义[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)内容。

若要定义的布局[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)控件，您还可以使用[HierarchicalDataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.hierarchicaldatatemplate)对象。 有关详细信息和示例，请参阅[使用 SelectedValue、SelectedValuePath 和 SelectedItem](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-use-selectedvalue-selectedvaluepath-and-selecteditem)。

如果项不是[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)控件，它将自动包括[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)控制何时[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)显示控件。

### 展开和折叠 TreeViewItem

如果在用户展开[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)，则[IsExpanded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem.isexpanded)属性设置为`true`。 您还可以展开或折叠[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)而无需通过设置任何直接的用户操作[IsExpanded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem.isexpanded)属性设置为`true`（展开） 或`false`（折叠）。 此属性更改时，[Expanded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem.expanded)或[Collapsed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem.collapsed)事件发生。

当[BringIntoView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.bringintoview)上调用方法[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)控件，[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)及其父[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)控件展开。 如果[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)不可见或部分可见，[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)滚动以使其可见。

### TreeViewItem 选择

当用户单击[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)控件以选择它，[Selected](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem.selected)发生事件时，并将其[IsSelected](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem.isselected)属性设置为`true`。[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)也将变为[SelectedItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview.selecteditem)的[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)控件。 相反，所选内容由[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)控件，其[Unselected](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem.unselected)发生事件并将其[IsSelected](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem.isselected)属性设置为`false`。

[SelectedItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview.selecteditem)属性上的[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)控件是只读属性; 因此，您不能显式将其设置。 [SelectedItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview.selecteditem)属性设置在用户单击上[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)控件时，或者当[IsSelected](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem.isselected)属性设置为`true`上[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)控件。

使用[SelectedValuePath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview.selectedvaluepath)属性来指定[SelectedValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview.selectedvalue)的[SelectedItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview.selecteditem)。 有关详细信息，请参阅[使用 SelectedValue、SelectedValuePath 和 SelectedItem](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-use-selectedvalue-selectedvaluepath-and-selecteditem)。

可以在注册事件处理程序[SelectedItemChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview.selecteditemchanged)事件，以确定当所选[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)更改。[RoutedPropertyChangedEventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedpropertychangedeventargs-1)提供对事件处理程序指定[OldValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedpropertychangedeventargs-1.oldvalue)，这是以前的选项，和[NewValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.routedpropertychangedeventargs-1.newvalue)，这是当前所选内容。 如果应用程序或用户未进行上一个或当前选择，则任一值都可能为 `null`。

### TreeView 样式

默认样式[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)控件将其内部放置[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)对象，其中包含[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)控件。 当设置[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)和[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)属性[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)，这些值用于为大小[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)显示的对象[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)。 如果要显示的内容大于显示区域中，[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)自动显示，以便用户可以滚动浏览[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)内容。

若要自定义的外观[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)控件，将[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.style)属性设置为自定义[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)。

下面的示例演示如何设置[Foreground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.foreground)并[FontSize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.fontsize)属性值的[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)控件中的使用[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.style)。

```xaml
<Style TargetType="{x:Type TreeViewItem}">
  <Setter Property="Foreground" Value="Blue"/>
  <Setter Property="FontSize" Value="12"/>
</Style>
```

### 向 TreeView 项添加图像和其他内容

可以包含多个对象中的[Header](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headereditemscontrol.header)内容的[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)。 若要包括在多个对象[Header](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headereditemscontrol.header)内容，如将括在布局控件内的对象[Panel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel)或[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)。

下面的示例演示如何定义[Header](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headereditemscontrol.header)的[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)作为[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)并[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)，括在[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)控件。

```xaml
<TreeViewItem>
  <TreeViewItem.Header>
    <DockPanel>
      <CheckBox/>
      <TextBlock>
        TreeViewItem Text
      </TextBlock>
    </DockPanel>
  </TreeViewItem.Header>
</TreeViewItem>
```

下面的示例演示如何定义[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)，其中包含[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)和一个[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)括在[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)控件。 可以使用[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)若要设置[HeaderTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headereditemscontrol.headertemplate)或[ItemTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemtemplate)为[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)。

XAML复制

```xaml
<DataTemplate x:Key="NewspaperTVItem">
  <DockPanel>
    <Image Source="images\icon.jpg"/>
    <TextBlock VerticalAlignment="center" Text ="{Binding Path=Name}"/>
  </DockPanel>
</DataTemplate>
```

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/treeview-how-to-topics)

本部分中的主题介绍如何使用[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)控件来显示层次结构中的信息。

[创建简单或复杂的 TreeView](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-create-simple-or-complex-treeviews)
[使用 SelectedValue、SelectedValuePath 和 SelectedItem](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-use-selectedvalue-selectedvaluepath-and-selecteditem)
[将 TreeView 绑定到深度无法确定的数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-bind-a-treeview-to-data-that-has-an-indeterminable-depth)
[提升 TreeView 的性能](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-improve-the-performance-of-a-treeview)
[在 TreeView 中查找 TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-find-a-treeviewitem-in-a-treeview)

### [Create Simple or Complex TreeViews](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-create-simple-or-complex-treeviews)

此示例演示如何创建简单或复杂[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)控件。

一个[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)包含的层次结构[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)控件，它们可以包含简单文本字符串和也更复杂的内容，如[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)控件或[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)与嵌入的内容。 您可以显式定义[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)内容或数据源可以提供内容。 本主题提供了这些概念的示例。

[Header](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headereditemscontrol.header)的属性[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)包含的内容的[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)显示该项。 一个[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)还可以[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)控件作为其子元素，您可以通过使用定义这些子元素[Items](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.items)属性。

下面的示例演示如何显式定义[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)通过设置内容[Header](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headereditemscontrol.header)属性设置为文本字符串。

```xaml
<TreeView>
  <TreeViewItem Header="Employee1">
    <TreeViewItem Header="Jesper"/>
    <TreeViewItem Header="Aaberg"/>
    <TreeViewItem Header="12345"/>
  </TreeViewItem>
 <TreeViewItem Header="Employee2">
    <TreeViewItem Header="Dominik"/>
    <TreeViewItem Header="Paiha"/>
    <TreeViewItem Header="98765"/>
  </TreeViewItem>
</TreeView>
```

下面的示例演示如何定义的子元素[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)通过定义[Items](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.items)的[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)控件。

```xaml
<TreeView>
  <TreeViewItem Header ="Employee1">
    <TreeViewItem.Items>
      <Button>Jesper</Button>
      <Button>Aaberg</Button>
      <Button>12345</Button>
    </TreeViewItem.Items>
  </TreeViewItem>
  <TreeViewItem Header="Employee2">
    <TreeViewItem.Items>
      <Button>Dominik</Button>
      <Button>Paiha</Button>
      <Button>98765</Button>
    </TreeViewItem.Items>
  </TreeViewItem>
</TreeView>
```

下面的示例演示如何创建[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)其中[XmlDataProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.xmldataprovider)提供[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)内容和[HierarchicalDataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.hierarchicaldatatemplate)定义内容的外观。

```xaml
<XmlDataProvider x:Key="myEmployeeData" XPath="/EmployeeData">
  <x:XData>
    <EmployeeData xmlns="">
      <EmployeeInfo>
        <EmployeeInfoData>Employee1</EmployeeInfoData>
        <Item Type="FirstName">Jesper</Item>
        <Item Type="LastName">Aaberg</Item>
        <Item Type="EmployeeNumber">12345</Item>
      </EmployeeInfo>
      <EmployeeInfo>
        <EmployeeInfoData>Employee2</EmployeeInfoData>
        <Item Type="FirstName">Dominik</Item>
        <Item Type="LastName">Paiha</Item>
        <Item Type="EmployeeNumber">98765</Item>
      </EmployeeInfo>
    </EmployeeData>
  </x:XData>
</XmlDataProvider>
```

```xaml
<HierarchicalDataTemplate DataType="EmployeeInfo" 
  ItemsSource ="{Binding XPath=Item}">
  <TextBlock Text="{Binding XPath=EmployeeInfoData}" />
</HierarchicalDataTemplate>
```

```xaml
<TreeView ItemsSource="{Binding Source={StaticResource myEmployeeData}, 
  XPath=EmployeeInfo}"/>
```

下面的示例演示如何创建[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)其中[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)内容包含[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)嵌入内容的控件。

```xaml
<TreeView>
  <TreeViewItem Header="Animals">
    <TreeViewItem.Items>
    <DockPanel>
      <Image Source="data\fish.png"/>
      <TextBlock Margin="5" Foreground="Brown"
                 FontSize="12">Fish</TextBlock>
    </DockPanel>
    <DockPanel>
      <Image Source="data\dog.png"/>
      <TextBlock Margin="5" Foreground="Brown"
                 FontSize="12">Dog</TextBlock>
    </DockPanel>
    <DockPanel>
      <Image Source="data\cat.png"/>
      <TextBlock Margin="5" Foreground="Brown"
                 FontSize="12">Cat</TextBlock>
    </DockPanel>
  </TreeViewItem.Items>
  </TreeViewItem>      
</TreeView>
```

### [Use SelectedValue, SelectedValuePath, and SelectedItem](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-use-selectedvalue-selectedvaluepath-and-selecteditem)

此示例演示如何使用[SelectedValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview.selectedvalue)并[SelectedValuePath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview.selectedvaluepath)属性，以指定的值[SelectedItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview.selecteditem)的[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)。

[SelectedValuePath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview.selectedvaluepath)属性提供了一种方法来指定[SelectedValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview.selectedvalue)有关[SelectedItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview.selecteditem)中[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)。 [SelectedItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview.selecteditem)表示中的对象[Items](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.items)集合和[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)显示选定项的单个属性的值。 [SelectedValuePath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview.selectedvaluepath)属性指定用于确定值的属性的路径[SelectedValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview.selectedvalue)属性。 本主题中的示例演示了这一概念。

下面的示例演示[XmlDataProvider](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.xmldataprovider)包含雇员的信息。

```xaml
<XmlDataProvider x:Key="myEmployeeData" XPath="/EmployeeData">
  <x:XData>
    <EmployeeData xmlns="">
      <EmployeeInfo>
        <EmployeeName>Jesper Aabergy</EmployeeName>
        <EmployeeWorkDay>Monday</EmployeeWorkDay>
        <EmployeeWorkDay>Wednesday</EmployeeWorkDay>
        <EmployeeWorkDay>Friday</EmployeeWorkDay>
        <EmployeeStartTime>8:00am</EmployeeStartTime>
        <EmployeeNumber>12345</EmployeeNumber>
      </EmployeeInfo>
      <EmployeeInfo>
        <EmployeeName>Dominik Paiha</EmployeeName>
        <EmployeeWorkDay>Monday</EmployeeWorkDay>
        <EmployeeWorkDay>Tuesday</EmployeeWorkDay>
        <EmployeeStartTime>6:30am</EmployeeStartTime>
        <EmployeeNumber>98765</EmployeeNumber>
      </EmployeeInfo>
    </EmployeeData>
  </x:XData>
</XmlDataProvider>
```

下面的示例定义[HierarchicalDataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.hierarchicaldatatemplate)，它显示`EmployeeName`并`EmployeeWorkDay`的`Employee`。 请注意，[HierarchicalDataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.hierarchicaldatatemplate)未指定`EmployeeNumber`作为模板的一部分。

```xaml
<HierarchicalDataTemplate x:Key="SampleTemplate" DataType="EmployeeInfo" 
  ItemsSource ="{Binding XPath=EmployeeWorkDay}">
  <TextBlock Text="{Binding XPath=EmployeeName}" />
</HierarchicalDataTemplate>
```

下面的示例演示[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)，它使用以前定义[HierarchicalDataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.hierarchicaldatatemplate)，用于设置和[SelectedValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview.selectedvalue)属性设置为`EmployeeNumber`。 当选择`EmployeeName`中[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)，则[SelectedItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview.selecteditem)属性将返回`EmployeeInfo`对应于所选的数据项`EmployeeName`。 但是，由于[SelectedValuePath](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview.selectedvaluepath)的这[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)设置为`EmployeeNumber`，则[SelectedValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview.selectedvalue)设置为`EmployeeNumber`。

```xaml
<TreeView ItemsSource="{Binding Source={StaticResource myEmployeeData}, 
    ItemTemplate={StaticResource SampleTemplate},
    XPath=EmployeeInfo}" 
    Name="myTreeView" 
    SelectedValuePath="EmployeeNumber" 
    />

<TextBlock Margin="10">SelectedValuePath: </TextBlock>
<TextBlock Margin="10,0,0,0" 
           Text="{Binding ElementName=myTreeView, 
                          Path=SelectedValuePath}"
           Foreground="Blue"/>

<TextBlock Margin="10">SelectedValue: </TextBlock>
<TextBlock Margin="10,0,0,0" 
           Text="{Binding ElementName=myTreeView, 
                          Path=SelectedValue}"
           Foreground="Blue"/>
```

### [Bind a TreeView to Data That Has an Indeterminable Depth](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-bind-a-treeview-to-data-that-has-an-indeterminable-depth)

可能存在你想要将绑定[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)与数据源不知道其深度。 这可能的数据时递归性质，例如文件系统，其中的文件夹可以包含文件夹或公司的组织结构，其中员工具有作为直接下属的其他员工。

数据源必须具有一个分层对象模型。 例如，`Employee`类可能包含一系列 Employee 对象的直接下属的员工。 如果不是分层的方式表示数据，则必须生成数据的分层表示形式。

当您将设置[ItemsControl.ItemTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemtemplate)属性，如果[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)生成[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)每个子项，则子[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)使用相同[ItemTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemtemplate)作为父级。 例如，如果您设置[ItemTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemtemplate)属性数据绑定[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)，则每个[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)，它是生成的使用[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)的已分配给[ItemTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemtemplate)属性[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)。

[HierarchicalDataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.hierarchicaldatatemplate) ，可指定[ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource)有关[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)，或任何[HeaderedItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headereditemscontrol)，数据模板。当您将设置[HierarchicalDataTemplate.ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.hierarchicaldatatemplate.itemssource)属性的值时使用[HierarchicalDataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.hierarchicaldatatemplate)应用。 通过使用[HierarchicalDataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.hierarchicaldatatemplate)，你可以以递归方式集[ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource)每个[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)中[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)。



下面的示例演示如何将绑定[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)到层次结构数据，使用[HierarchicalDataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.hierarchicaldatatemplate)来指定[ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource)为每个[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)。 [TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)将绑定到表示员工的公司中的 XML 数据。 每个`Employee`元素可以包含其他`Employee`元素，以指示隶属关系。 由于数据是递归的[HierarchicalDataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.hierarchicaldatatemplate)可以应用于每个级别。

```xaml
<Page 
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
  <Page.Resources>
    <XmlDataProvider x:Key="myCompany" XPath="Company/Employee">
      <x:XData>
        <Company xmlns="">
          <Employee Name="Don Hall">
            <Employee Name="Alice Ciccu">
              <Employee Name="David Pelton">
                <Employee Name="Vivian Atlas"/>
              </Employee>
              <Employee Name="Jeff Price"/>
              <Employee Name="Andy Jacobs"/>
            </Employee>
            <Employee Name="Bill Malone">
              <Employee Name="Maurice Taylor"/>
              <Employee Name="Sunil Uppal"/>
              <Employee Name="Qiang Wang"/>
            </Employee>
          </Employee>
        </Company>
      </x:XData>
    </XmlDataProvider>

    <!-- Bind the HierarchicalDataTemplate.ItemsSource property to the employees under
         each Employee element. -->
    <HierarchicalDataTemplate x:Key="EmployeeTemplate" 
                              ItemsSource="{Binding XPath=Employee}">
      <TextBlock Text="{Binding XPath=@Name}" ></TextBlock>
    </HierarchicalDataTemplate>

    <Style TargetType="TreeViewItem">
      <Setter Property="IsExpanded" Value="True"/>
    </Style>
  </Page.Resources>

  <Grid>
    <TreeView ItemsSource="{Binding Source={StaticResource myCompany}}" 
              ItemTemplate="{StaticResource EmployeeTemplate}"/>
  </Grid>
</Page>
```

### [Improve the Performance of a TreeView](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-improve-the-performance-of-a-treeview)

如果[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)包含很多项所花费的时间量可能会导致明显的延迟导致用户界面中。 可以通过设置缩短加载时间`VirtualizingStackPanel.IsVirtualizing`附加属性设置为`true`。 UI 也可能较慢时用户滚动做出反应[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)通过使用鼠标滚轮或拖动滚动条的滚动块。 您可以提高的性能[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)通过设置在用户滚动时`VirtualizingStackPanel.VirtualizationMode`附加属性设置为[VirtualizationMode.Recycling](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizationmode#System_Windows_Controls_VirtualizationMode_Recycling)。



下面的示例创建[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)，用于设置`VirtualizingStackPanel.IsVirtualizing`附加属性设置为 true 并`VirtualizingStackPanel.VirtualizationMode`附加到属性[VirtualizationMode.Recycling](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizationmode#System_Windows_Controls_VirtualizationMode_Recycling)以优化其性能。

```xaml
<StackPanel>
  <StackPanel.Resources>
    <src:TreeViewData x:Key="dataItems"/>


    <HierarchicalDataTemplate DataType="{x:Type src:ItemsForTreeView}"
                              ItemsSource="{Binding Path=SecondLevelItems}">

      <!--Display the TopLevelName property in the first level.-->
      <TextBlock Text="{Binding Path=TopLevelName}"/>
      
      <!--Display each string in the SecondLevelItems property in
          the second level.-->
      <HierarchicalDataTemplate.ItemTemplate>
          <DataTemplate>
              <TextBlock Text="{Binding}"/>
          </DataTemplate>
      </HierarchicalDataTemplate.ItemTemplate>
      
      <!--Set the foreground of the items in the second level
          to Navy.-->
      <HierarchicalDataTemplate.ItemContainerStyle>
        <Style TargetType="TreeViewItem">
          <Setter Property="Foreground" Value="Navy"/>
        </Style>
      </HierarchicalDataTemplate.ItemContainerStyle>  
    </HierarchicalDataTemplate>
  </StackPanel.Resources>

  <TreeView Height="200" 
            ItemsSource="{Binding Source={StaticResource dataItems}}"
            VirtualizingStackPanel.IsVirtualizing="True"
            VirtualizingStackPanel.VirtualizationMode="Recycling">
    <TreeView.ItemContainerStyle>
      
      <!--Expand each TreeViewItem in the first level and 
          set its foreground to Green.-->
      <Style TargetType="TreeViewItem">
        <Setter Property="IsExpanded" Value="True"/>
        <Setter Property="Foreground" Value="Green"/>
      </Style>
    </TreeView.ItemContainerStyle>
  </TreeView>
</StackPanel>
```

下面的示例显示了前面的示例使用的数据。

```csharp
public class TreeViewData : ObservableCollection<ItemsForTreeView>
{

    public TreeViewData()
    {
        for (int i = 0; i < 100; ++i)
        {
            ItemsForTreeView item = new ItemsForTreeView();
            item.TopLevelName = "item " + i.ToString();
            Add(item);
        }
    }
}


public class ItemsForTreeView
{
    public string TopLevelName { get; set; }
    private ObservableCollection<string> level2Items;

    public ObservableCollection<string> SecondLevelItems
    {
        get 
        {
            if (level2Items == null)
            {
                level2Items = new ObservableCollection<string>();
            }
            return level2Items;
        }
    }

    public ItemsForTreeView()
    {
        for (int i = 0; i < 10; ++i)
        {
            SecondLevelItems.Add("Second Level " + i.ToString());
        }
    }
}
```

### [Find a TreeViewItem in a TreeView](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-find-a-treeviewitem-in-a-treeview)

[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)控件提供了方便地显示分层数据。 如果你[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)绑定到数据源，[SelectedItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview.selecteditem)属性提供的简便方法，以便快速检索所选的数据对象。 通常，最好使用基础数据对象，但有时您可能需要以编程方式处理的数据包含[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)。 例如，可能需要以编程方式展开[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)，或选择不同的项在[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)。

若要查找[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)，其中包含特定的数据对象，您必须遍历每个级别的[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)。 中的项[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)可以还虚拟化以提高性能。 在项可能虚拟化的情况下，您还必须认识到[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)检查它是否包含数据对象。



以下示例将搜索[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)特定的对象并返回该对象的包含[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)。 该示例确保每个[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)实例化，以便可以搜索其子项。 如果此示例也适用于[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)不使用虚拟化的项。

> 下面的示例适用于任何[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)，而不考虑基础数据模型和搜索每个[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)直到找到该对象。 具有更好的性能的另一个方法是搜索指定对象的数据模型、 跟踪的数据层次结构中的其位置，然后找到相应[TreeViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeviewitem)在[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)。 但是，具有更好的性能的技术需要了解数据模型，并且不能使用通用对于任何给定[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)。



```csharp
/// <summary>
/// Recursively search for an item in this subtree.
/// </summary>
/// <param name="container">
/// The parent ItemsControl. This can be a TreeView or a TreeViewItem.
/// </param>
/// <param name="item">
/// The item to search for.
/// </param>
/// <returns>
/// The TreeViewItem that contains the specified item.
/// </returns>
private TreeViewItem GetTreeViewItem(ItemsControl container, object item)
{
    if (container != null)
    {
        if (container.DataContext == item)
        {
            return container as TreeViewItem;
        }

        // Expand the current container
        if (container is TreeViewItem && !((TreeViewItem)container).IsExpanded)
        {
            container.SetValue(TreeViewItem.IsExpandedProperty, true);
        }

        // Try to generate the ItemsPresenter and the ItemsPanel.
        // by calling ApplyTemplate.  Note that in the 
        // virtualizing case even if the item is marked 
        // expanded we still need to do this step in order to 
        // regenerate the visuals because they may have been virtualized away.

        container.ApplyTemplate();
        ItemsPresenter itemsPresenter = 
            (ItemsPresenter)container.Template.FindName("ItemsHost", container);
        if (itemsPresenter != null)
        {
            itemsPresenter.ApplyTemplate();
        }
        else
        {
            // The Tree template has not named the ItemsPresenter, 
            // so walk the descendents and find the child.
            itemsPresenter = FindVisualChild<ItemsPresenter>(container);
            if (itemsPresenter == null)
            {
                container.UpdateLayout();

                itemsPresenter = FindVisualChild<ItemsPresenter>(container);
            }
        }

        Panel itemsHostPanel = (Panel)VisualTreeHelper.GetChild(itemsPresenter, 0);


        // Ensure that the generator for this panel has been created.
        UIElementCollection children = itemsHostPanel.Children; 

        MyVirtualizingStackPanel virtualizingPanel = 
            itemsHostPanel as MyVirtualizingStackPanel;

        for (int i = 0, count = container.Items.Count; i < count; i++)
        {
            TreeViewItem subContainer;
            if (virtualizingPanel != null)
            {
                // Bring the item into view so 
                // that the container will be generated.
                virtualizingPanel.BringIntoView(i);

                subContainer = 
                    (TreeViewItem)container.ItemContainerGenerator.
                    ContainerFromIndex(i);
            }
            else
            {
                subContainer = 
                    (TreeViewItem)container.ItemContainerGenerator.
                    ContainerFromIndex(i);

                // Bring the item into view to maintain the 
                // same behavior as with a virtualizing panel.
                subContainer.BringIntoView();
            }

            if (subContainer != null)
            {
                // Search the next level for the object.
                TreeViewItem resultContainer = GetTreeViewItem(subContainer, item);
                if (resultContainer != null)
                {
                    return resultContainer;
                }
                else
                {
                    // The object is not under this TreeViewItem
                    // so collapse it.
                    subContainer.IsExpanded = false;
                }
            }
        }
    }

    return null;
}

/// <summary>
/// Search for an element of a certain type in the visual tree.
/// </summary>
/// <typeparam name="T">The type of element to find.</typeparam>
/// <param name="visual">The parent element.</param>
/// <returns></returns>
private T FindVisualChild<T>(Visual visual) where T : Visual
{
    for (int i = 0; i < VisualTreeHelper.GetChildrenCount(visual); i++)
    {
        Visual child = (Visual)VisualTreeHelper.GetChild(visual, i);
        if (child != null)
        {
            T correctlyTyped = child as T;
            if (correctlyTyped != null)
            {
                return correctlyTyped;
            }

            T descendent = FindVisualChild<T>(child);
            if (descendent != null)
            {
                return descendent;
            }
        }
    }

    return null;
}
```

前面的代码依赖于自定义[VirtualizingStackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel)公开一个名为方法`BringIntoView`。 下面的代码定义自定义[VirtualizingStackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel)。

```csharp
public class MyVirtualizingStackPanel : VirtualizingStackPanel
{
    /// <summary>
    /// Publically expose BringIndexIntoView.
    /// </summary>
    public void BringIntoView(int index)
    {

        this.BringIndexIntoView(index);
    }
}
```

以下 XAML 演示如何创建[TreeView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.treeview)，它使用自定义[VirtualizingStackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizingstackpanel)。

```xaml
<TreeView VirtualizingStackPanel.IsVirtualizing="True">

  <!--Use the custom class MyVirtualizingStackPanel
      as the ItemsPanel for the TreeView and
      TreeViewItem object.-->
  <TreeView.ItemsPanel>
    <ItemsPanelTemplate>
      <src:MyVirtualizingStackPanel/>
    </ItemsPanelTemplate>
  </TreeView.ItemsPanel>
  <TreeView.ItemContainerStyle>
    <Style TargetType="TreeViewItem">
      <Setter Property="ItemsPanel">
        <Setter.Value>
          <ItemsPanelTemplate>
            <src:MyVirtualizingStackPanel/>
          </ItemsPanelTemplate>
        </Setter.Value>
      </Setter>
    </Style>
  </TreeView.ItemContainerStyle>
</TreeView>
```