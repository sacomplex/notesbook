## [ListView](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/listview)

[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控件提供的基础结构在不同的布局或视图中显示的数据项目集。

下图显示[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)。

![具有 GridView 输出的 ListView](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/listviewgridview.jpg)

### 本节内容

[概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/listview-overviews)
[帮助主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/listview-how-to-topics)

#### [Overviews](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/listview-overviews)

#### 本节内容

[ListView 概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/listview-overview)
[GridView 概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/gridview-overview)
[GridView 列标题的样式和模板概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/gridview-column-header-styles-and-templates-overview)

#### [ListView Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/listview-overview)

[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控件提供了用于显示数据项的一组不同的布局或视图中的基础结构。 例如，用户可能需要在表格中显示数据项，并同时对表格的列进行排序。

##### 什么是 ListView？

[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控件是[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)派生自[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)。 通常情况下，其项是数据集合的成员，表示为[ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listviewitem)对象。 一个[ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listviewitem)是[ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)，并且可以包含单个子元素。 但是，该子元素可以是任何视觉元素。

##### 为 ListView 定义视图模式

若要指定的内容的视图模式[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控件，设置[View](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview.view)属性。 一个视图模式的Windows Presentation Foundation (WPF)提供了为[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)，具有可自定义列的表中显示的数据项的集合。

下面的示例演示如何定义[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)为[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)显示员工信息的控件。

```xaml
<ListView ItemsSource="{Binding Source=
                       {StaticResource EmployeeInfoDataSource}}">

  <ListView.View>

    <GridView AllowsColumnReorder="true"
              ColumnHeaderToolTip="Employee Information">

      <GridViewColumn DisplayMemberBinding=
                          "{Binding Path=FirstName}" 
                      Header="First Name" Width="100"/>
        
                  <GridViewColumn DisplayMemberBinding=
                          "{Binding Path=LastName}" 
                      Width="100">
                      <GridViewColumnHeader>Last Name
                          <GridViewColumnHeader.ContextMenu>
                          <ContextMenu  MenuItem.Click="LastNameCM_Click"  
                                        Name="LastNameCM">
                              <MenuItem Header="Ascending" />
                              <MenuItem Header="Descending" />
                          </ContextMenu>
                          </GridViewColumnHeader.ContextMenu>
                      </GridViewColumnHeader>
                  </GridViewColumn>

                  <GridViewColumn DisplayMemberBinding=
                          "{Binding Path=EmployeeNumber}" 
                      Header="Employee No." Width="100"/>
    </GridView>

  </ListView.View>
</ListView>
```

下图演示上一个示例的数据显示方式。

![具有 GridView 输出的 ListView](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/listviewgridview.jpg)

您可以通过定义继承的类创建自定义视图模式[ViewBase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewbase)类。 [ViewBase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewbase)类提供了您需要创建自定义视图的基础结构。 有关如何创建自定义视图的详细信息，请参阅[为 ListView 创建自定义视图模式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-create-a-custom-view-mode-for-a-listview)。



##### 将数据绑定到 ListView

使用[Items](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.items)并[ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource)属性，以指定的项[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控件。 下面的示例设置[ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource)属性设置为的数据集合的称为`EmployeeInfoDataSource`。

```xaml
<ListView ItemsSource="{Binding Source=
                       {StaticResource EmployeeInfoDataSource}}">
```

在中[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)，[GridViewColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn)对象绑定到指定的数据字段。 以下示例将绑定[GridViewColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn)通过指定数据字段的对象[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)为[DisplayMemberBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn.displaymemberbinding)属性。

```csharp
GridViewColumn gvc1 = new GridViewColumn();
gvc1.DisplayMemberBinding = new Binding("FirstName");
gvc1.Header = "FirstName";
gvc1.Width = 100;
```

```xaml
<GridViewColumn DisplayMemberBinding=
                    "{Binding Path=FirstName}" 
                Header="First Name" Width="100"/>
```

此外可以指定[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)作为的一部分[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)用于设置列中的单元格的样式定义。 在以下示例中，[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)用标识[ResourceKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcekey)设置[Binding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding)为[GridViewColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn)。 请注意，此示例未定义[DisplayMemberBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn.displaymemberbinding)因为这样做将覆盖由指定的绑定[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)。

```xaml
<DataTemplate x:Key="myCellTemplateMonth">
  <DockPanel>
    <TextBlock Foreground="DarkBlue" HorizontalAlignment="Center">
      <TextBlock.Text>
        <Binding Path="Month"/>
      </TextBlock.Text>
    </TextBlock>
  </DockPanel>
</DataTemplate>
```

```xaml
<GridViewColumn Header="Month" Width="80"
      CellTemplate="{StaticResource myCellTemplateMonth}"/>
```

##### 为实现 GridView 的 ListView 设置样式

[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控件包含[ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listviewitem)对象，表示显示的数据项。 可使用以下属性定义数据项的内容和样式：

- 上[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控制，请使用[ItemTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemtemplate)， [ItemTemplateSelector](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemtemplateselector)，和[ItemContainerStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemcontainerstyle)属性。
- 上[ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listviewitem)控制，请使用[ContentTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.contenttemplate)和[ContentTemplateSelector](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol.contenttemplateselector)属性。

若要避免出现对齐问题中的单元格之间[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)，请不要使用[ItemContainerStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemcontainerstyle)来设置属性或添加内容中的项的宽度有影响[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)。 例如，可能出现对齐问题，设置时[Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)中的属性[ItemContainerStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemcontainerstyle)。 若要指定属性或定义中的项的宽度有影响的内容[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)，使用的属性[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)类和其相关的类，如[GridViewColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn)。

有关如何使用详细信息[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)和及其支持类，请参阅[GridView 概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/gridview-overview)。

如果定义了[ItemContainerStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemcontainerstyle)有关[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控制，还可定义[ItemTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemtemplate)，必须包括[ContentPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter)在样式中的顺序[ItemTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemtemplate)才能正常工作。

不要使用[HorizontalContentAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.horizontalcontentalignment)并[VerticalContentAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.verticalcontentalignment)属性[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)通过使用显示的内容[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)。若要指定的列中的内容的对齐方式[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)，定义[CellTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn.celltemplate)。

##### 共享同一视图模式

两个[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控件不能在同一时间共享同一视图模式。 如果你尝试与多个使用同一视图模式[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控件，则会发生异常。

若要指定可同时由多个视图模式[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)，使用模板或样式。

##### 创建自定义视图模式

自定义视图，如[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)派生自[ViewBase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewbase)抽象类，该类提供工具，用于显示数据项表示为[ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listviewitem)对象。

#### [GridView Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/gridview-overview)

[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview) 视图模式是一种视图模式的[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控件。 [GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)类和及其支持类使您和您的用户能够查看通常使用按钮作为交互式列标题的表中的项集合。 本主题介绍[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)类，并概述了其用途。

##### 什么是 GridView 视图？

[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)模式通过将数据字段绑定到列以及显示列标题，可标识的字段显示的数据项列表的视图。 默认值[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)样式实现按钮作为列标题。 通过使用列标题按钮，可以实现重要的用户交互功能;例如，用户可以单击要排序的列标题[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)根据特定列的内容的数据。

> 按钮控件[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)用于列标题派生自[ButtonBase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase)。

如下图所示[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)查看的[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)内容。

**ListView 内容的 GridView 视图**

![带样式的 ListView](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/styledlistview.png)

[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview) 列由[GridViewColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn)对象，可以对其内容自动调整大小。 （可选） 可以显式设置[GridViewColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn)为一个特定宽度。 可通过拖动列标题之间的手柄重设列的大小。 您可以还可以动态地添加、 删除、 替换和对列重新排序，因为此功能内置到[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)。 但是，[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)不能直接更新它显示的数据。

下面的示例演示如何定义[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)显示员工数据。 在此示例中，[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)定义`EmployeeInfoDataSource`作为[ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource)。 属性定义[DisplayMemberBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn.displaymemberbinding)绑定[GridViewColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn)内容到`EmployeeInfoDataSource`数据类别。

XAML复制

```xaml
<ListView ItemsSource="{Binding Source=
                       {StaticResource EmployeeInfoDataSource}}">

  <ListView.View>

    <GridView AllowsColumnReorder="true"
              ColumnHeaderToolTip="Employee Information">

      <GridViewColumn DisplayMemberBinding=
                          "{Binding Path=FirstName}" 
                      Header="First Name" Width="100"/>
        
                  <GridViewColumn DisplayMemberBinding=
                          "{Binding Path=LastName}" 
                      Width="100">
                      <GridViewColumnHeader>Last Name
                          <GridViewColumnHeader.ContextMenu>
                          <ContextMenu  MenuItem.Click="LastNameCM_Click"  
                                        Name="LastNameCM">
                              <MenuItem Header="Ascending" />
                              <MenuItem Header="Descending" />
                          </ContextMenu>
                          </GridViewColumnHeader.ContextMenu>
                      </GridViewColumnHeader>
                  </GridViewColumn>

                  <GridViewColumn DisplayMemberBinding=
                          "{Binding Path=EmployeeNumber}" 
                      Header="Employee No." Width="100"/>
    </GridView>

  </ListView.View>
</ListView>
```

下图显示了上一示例创建的表格。

**显示 ItemsSource 中的数据的 GridView**

![具有 GridView 输出的 ListView](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/listviewgridview.jpg)



##### GridView 布局和样式

列单元格和列标题的[GridViewColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn)具有相同的宽度。 默认情况下，每一列都根据其内容来调整宽度大小。 也可以选择将列设置为固定宽度。

相关的数据内容显示在水平行中。 例如，在上图中，每个员工的姓氏、名字和 ID 号显示为一组，因为它们显示在一个水平行中。

###### 在 GridView 中定义列并设置其样式

定义要在中显示的数据字段时[GridViewColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn)，使用[DisplayMemberBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn.displaymemberbinding)， [CellTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn.celltemplate)，或[CellTemplateSelector](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn.celltemplateselector)属性。 [DisplayMemberBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn.displaymemberbinding)属性优先于任何模板属性。

若要指定的列中的内容的对齐方式[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)，定义[CellTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn.celltemplate)。 不要使用[HorizontalContentAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.horizontalcontentalignment)并[VerticalContentAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.verticalcontentalignment)属性[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)通过使用显示的内容[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)。

若要指定列标题的模板和样式属性，请使用[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)， [GridViewColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn)，和[GridViewColumnHeader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumnheader)类。 有关详细信息，请参阅 [GridView 列标题的样式和模板概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/gridview-column-header-styles-and-templates-overview)。

###### 将可视元素添加到 GridView

添加可视元素，例如[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)并[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)控件，为[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)视图模式中，使用模板或样式。

如果您显式定义为数据项的可视元素，它可以只出现一次在[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)。 之所以存在此限制，是因为元素只能有一个父级，因此，只能在可视化树中出现一次。

###### 设置 GridView 中的行的样式

使用[GridViewRowPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewrowpresenter)并[GridViewHeaderRowPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewheaderrowpresenter)类来格式化和显示的行[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)。 有关如何的示例中的样式行[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)查看模式，请参阅[的行设置样式中 ListView，实现 GridView](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-style-a-row-in-a-listview-that-implements-a-gridview)。

###### 使用 ItemContainerStyle 时的对齐问题

若要防止列标题和单元格之间对齐问题，未设置属性或指定模板中的项的宽度有影响[ItemContainerStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemcontainerstyle)。 例如，未设置[Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)属性，或者指定[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)，它将[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)到[ItemContainerStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemcontainerstyle)上定义[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控件。而是指定的属性和影响列宽度，直接在定义的类上的模板[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)视图模式。

例如，若要添加[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)对中的行[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)视图模式中，添加[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)到[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)，然后设置[CellTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn.celltemplate)属性设置为的[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)。

##### 与 GridView 的用户交互

当你使用[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)用户可以在应用程序中与之交互和修改的格式设置[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)。 例如，用户可以对列重新排序、重设列的大小、选择表中的项以及滚动查看内容。 还可定义当用户单击列标题按钮时响应的事件处理程序。 事件处理程序可以执行操作，如显示在对数据进行排序[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)根据列的内容。

以下列表更详细地讨论使用的功能[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)进行用户交互：

- **使用拖放方法对列重新排序。**

  用户可以对中的列重新排序[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)由列标题上时按鼠标左键，然后将该列拖动到新位置。 当用户拖动列标题时，将显示标题的浮动版本以及显示列的插入位置的黑色实线。

  如果你想要修改的浮动版本的标头的默认样式，指定[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)有关[GridViewColumnHeader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumnheader)，它是键入触发时[Role](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumnheader.role)属性设置为[Floating](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumnheaderrole#System_Windows_Controls_GridViewColumnHeaderRole_Floating)。 有关详细信息，请参阅[为拖动的 GridView 列标题创建样式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-create-a-style-for-a-dragged-gridview-column-header)。

- **根据列的内容重设其大小。**

  用户可双击列标题右侧的手柄来根据列的内容重设其大小。

   备注

  可以设置[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn.width)属性设置为`Double.NaN`以生成相同的效果。

- **选择行项目。**

  用户可以选择中的一个或多个项[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)。

  如果你想要更改[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)选定项，请参阅[使用触发器为 ListView 中选定项设置样式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-use-triggers-to-style-selected-items-in-a-listview)。

- **滚动查看最初未显示在屏幕上的内容。**

  如果的大小[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)是不足够大以显示所有项，用户可以滚动浏览水平或垂直通过使用滚动条，其中提供的[ScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.scrollviewer)控件。 一个[ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar)处于隐藏状态，如果所有内容都是在特定方向中可见。 列标题不会随着垂直滚动条滚动，但可水平滚动。

- **通过单击列标题按钮与列交互。**

  如果提供了排序算法，则当用户单击列标题按钮时，可以对列中显示的数据进行排序。

  您可以处理[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)以便提供类似排序算法的功能的列标题按钮的事件。 若要处理[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)一个列标题，为事件设置事件处理程序上[GridViewColumnHeader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumnheader)。 若要设置的事件处理程序处理[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)的所有列标题，为事件设置处理程序上[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控件。



##### 获取其他自定义视图

[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)类，该类派生自[ViewBase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewbase)抽象类，只是可能视图模式的一个[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)类。 可以创建其他自定义视图[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)通过派生自[ViewBase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewbase)类。 有关自定义视图模式的示例，请参阅[为 ListView 创建自定义视图模式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-create-a-custom-view-mode-for-a-listview)。

##### GridView 支持类

下面的类支持[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)视图模式。

- [GridViewColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn)
- [GridViewColumnHeader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumnheader)
- [GridViewRowPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewrowpresenter)
- [GridViewHeaderRowPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewheaderrowpresenter)
- [GridViewColumnCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumncollection)
- [GridViewColumnHeaderRole](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumnheaderrole)

#### [GridView Column Header Styles and Templates Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/gridview-column-header-styles-and-templates-overview)

#### [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/listview-how-to-topics)

本部分中的主题介绍如何使用[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控件来显示组的数据项。

##### 本节内容

[在标题获得单击时对 GridView 列进行排序](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-sort-a-gridview-column-when-a-header-is-clicked)
[创建 ListView 的自定义视图模式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-create-a-custom-view-mode-for-a-listview)
[使用模板设置使用 GridView 的 ListView 的样式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-use-templates-to-style-a-listview-that-uses-gridview)
[创建拖动的 GridView 列标题的样式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-create-a-style-for-a-dragged-gridview-column-header)
[使用 GridView 显示 ListView 内容](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-display-listview-contents-by-using-a-gridview)
[使用触发器在 ListView 中设置选定项的样式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-use-triggers-to-style-selected-items-in-a-listview)
[使用 CheckBox 创建 ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-create-listviewitems-with-a-checkbox)
[使用 GridViewRowPresenter 显示数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-display-data-by-using-gridviewrowpresenter)
[在实现 GridView 的 ListView 中对项进行分组](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-group-items-in-a-listview-that-implements-a-gridview)
[在实现 GridView 的 ListView 中设置行样式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-style-a-row-in-a-listview-that-implements-a-gridview)
[更改 ListView 中列的水平对齐方式](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-change-the-horizontal-alignment-of-a-column-in-a-listview)
[处理 ListView 中每一项的 MouseDoubleClick 事件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-handle-the-mousedoubleclick-event-for-each-item-in-a-listview)

##### [Sort a GridView Column When a Header Is Clicked](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-sort-a-gridview-column-when-a-header-is-clicked)

此示例演示如何创建[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)实现控件[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)查看模式和数据内容，当用户单击列标题排序。

**示例**

下面的示例定义[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)包含三列的绑定到[Year](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime.year)， [Month](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime.month)，和[Day](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime.day)，属性的[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)结构。

```xaml
<GridView>  
  <GridViewColumn DisplayMemberBinding="{Binding Path=Year}"   
                  Header="Year"  
                  Width="100"/>  
  <GridViewColumn DisplayMemberBinding="{Binding Path=Month}"   
                  Header="Month"  
                  Width="100"/>  
  <GridViewColumn DisplayMemberBinding="{Binding Path=Day}"   
                  Header="Day"  
                  Width="100"/>  
</GridView>  
```

下面的示例演示定义为数据项[ArrayList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.arraylist)的[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)对象。 [ArrayList](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.arraylist)指[ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource)为[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控件。

```xaml
<ListView.ItemsSource>  
  <s:ArrayList>  
    <p:DateTime>1993/1/1 12:22:02</p:DateTime>  
    <p:DateTime>1993/1/2 13:2:01</p:DateTime>  
    <p:DateTime>1997/1/3 2:1:6</p:DateTime>  
    <p:DateTime>1997/1/4 13:6:55</p:DateTime>  
    <p:DateTime>1999/2/1 12:22:02</p:DateTime>  
    <p:DateTime>1998/2/2 13:2:01</p:DateTime>  
    <p:DateTime>2000/2/3 2:1:6</p:DateTime>  
    <p:DateTime>2002/2/4 13:6:55</p:DateTime>  
    <p:DateTime>2001/3/1 12:22:02</p:DateTime>  
    <p:DateTime>2006/3/2 13:2:01</p:DateTime>  
    <p:DateTime>2004/3/3 2:1:6</p:DateTime>  
    <p:DateTime>2004/3/4 13:6:55</p:DateTime>  
  </s:ArrayList>  
</ListView.ItemsSource>  
```

XAML 标记中的 `s` 和 `p` 标识符引用在 XAML 页面元数据中定义的命名空间映射。 下面的示例显示了元数据定义。

```xaml
<Window        
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"  
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"  
    x:Class="ListViewSort.Window1"      
    xmlns:s="clr-namespace:System.Collections;assembly=mscorlib"  
    xmlns:p="clr-namespace:System;assembly=mscorlib">  
```

若要根据列的内容数据进行排序，该示例定义一个事件处理程序以处理[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)按列标题按钮时发生的事件。 下面的示例演示如何指定的事件处理程序[GridViewColumnHeader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumnheader)控件。

```xaml
<ListView x:Name='lv' Height="150" HorizontalAlignment="Center"   
  VerticalAlignment="Center"   
  GridViewColumnHeader.Click="GridViewColumnHeaderClickedHandler"  
 >  
```

该示例定义了事件处理程序，以便每次按下列标题按钮时，排序方向会在升序和降序之间发生变化。 下面的示例显示了事件处理程序。

```csharp
public partial class Window1 : Window  
{  
    public Window1()  
    {  
        InitializeComponent();  
    }  
  
    GridViewColumnHeader _lastHeaderClicked = null;  
    ListSortDirection _lastDirection = ListSortDirection.Ascending;  
  
    void GridViewColumnHeaderClickedHandler(object sender,  
                                            RoutedEventArgs e)  
    {  
        var headerClicked = e.OriginalSource as GridViewColumnHeader;  
        ListSortDirection direction;  
  
        if (headerClicked != null)  
        {  
            if (headerClicked.Role != GridViewColumnHeaderRole.Padding)  
            {  
                if (headerClicked != _lastHeaderClicked)  
                {  
                    direction = ListSortDirection.Ascending;  
                }  
                else  
                {  
                    if (_lastDirection == ListSortDirection.Ascending)  
                    {  
                        direction = ListSortDirection.Descending;  
                    }  
                    else  
                    {  
                        direction = ListSortDirection.Ascending;  
                    }  
                }  
  
                var columnBinding = headerClicked.Column.DisplayMemberBinding as Binding;
                var sortBy = columnBinding?.Path.Path ?? headerClicked.Column.Header as string;

                Sort(sortBy, direction);
  
                if (direction == ListSortDirection.Ascending)  
                {  
                    headerClicked.Column.HeaderTemplate =  
                      Resources["HeaderTemplateArrowUp"] as DataTemplate;  
                }  
                else  
                {  
                    headerClicked.Column.HeaderTemplate =  
                      Resources["HeaderTemplateArrowDown"] as DataTemplate;  
                }  
  
                // Remove arrow from previously sorted header  
                if (_lastHeaderClicked != null && _lastHeaderClicked != headerClicked)  
                {  
                    _lastHeaderClicked.Column.HeaderTemplate = null;  
                }  
  
                _lastHeaderClicked = headerClicked;  
                _lastDirection = direction;  
            }  
        }  
    }
}
```

下面的示例演示由事件处理程序调用以供对数据进行排序的排序算法。 通过创建新执行排序[SortDescription](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.sortdescription)结构。

```csharp
private void Sort(string sortBy, ListSortDirection direction)  
{  
    ICollectionView dataView =  
      CollectionViewSource.GetDefaultView(lv.ItemsSource);  
  
    dataView.SortDescriptions.Clear();  
    SortDescription sd = new SortDescription(sortBy, direction);  
    dataView.SortDescriptions.Add(sd);  
    dataView.Refresh();  
}  
```

##### [Create a Custom View Mode for a ListView](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-create-a-custom-view-mode-for-a-listview)

此示例演示如何创建自定义[View](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview.view)模式[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控件。

**示例**

必须使用[ViewBase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewbase)类创建的自定义视图时[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控件。 下面的示例演示调用的视图模式`PlainView`，它派生自[ViewBase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewbase)类。

```csharp
  public class PlainView : ViewBase
  {    

    public static readonly DependencyProperty 
      ItemContainerStyleProperty =
      ItemsControl.ItemContainerStyleProperty.AddOwner(typeof(PlainView));

    public Style ItemContainerStyle
    {
        get { return (Style)GetValue(ItemContainerStyleProperty); }
        set { SetValue(ItemContainerStyleProperty, value); }
    }

    public static readonly DependencyProperty ItemTemplateProperty =
        ItemsControl.ItemTemplateProperty.AddOwner(typeof(PlainView));

    public DataTemplate ItemTemplate
    {
        get { return (DataTemplate)GetValue(ItemTemplateProperty); }
        set { SetValue(ItemTemplateProperty, value); }
    }

    public static readonly DependencyProperty ItemWidthProperty =
        WrapPanel.ItemWidthProperty.AddOwner(typeof(PlainView));

    public double ItemWidth
    {
        get { return (double)GetValue(ItemWidthProperty); }           
        set { SetValue(ItemWidthProperty, value); }
    }


    public static readonly DependencyProperty ItemHeightProperty =
        WrapPanel.ItemHeightProperty.AddOwner(typeof(PlainView));

    public double ItemHeight
    {
        get { return (double)GetValue(ItemHeightProperty); }
        set { SetValue(ItemHeightProperty, value); }
    }


    protected override object DefaultStyleKey
    {
        get 
        { 
          return new ComponentResourceKey(GetType(), "myPlainViewDSK"); 
        }
    }

  }
```

若要将样式应用到自定义视图，请使用[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)类。 下面的示例定义[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)为`PlainView`视图模式。 在上一示例中，此样式设置的值作为[DefaultStyleKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewbase.defaultstylekey)属性，可为定义`PlainView`。

```xaml
<Style x:Key="{ComponentResourceKey 
      TypeInTargetAssembly={x:Type l:PlainView},
      ResourceId=myPlainViewDSK}" 
       TargetType="{x:Type ListView}" 
       BasedOn="{StaticResource {x:Type ListBox}}"
       >
  <Setter Property="HorizontalContentAlignment"
          Value="Center"/>
  <Setter Property="ItemContainerStyle" 
          Value="{Binding (ListView.View).ItemContainerStyle,
          RelativeSource={RelativeSource Self}}"/>
  <Setter Property="ItemTemplate" 
          Value="{Binding (ListView.View).ItemTemplate,
          RelativeSource={RelativeSource Self}}"/>
  <Setter Property="ItemsPanel">
    <Setter.Value>
      <ItemsPanelTemplate>
        <WrapPanel Width="{Binding (FrameworkElement.ActualWidth),
                   RelativeSource={RelativeSource 
                                   AncestorType=ScrollContentPresenter}}"
                   ItemWidth="{Binding (ListView.View).ItemWidth,
                   RelativeSource={RelativeSource AncestorType=ListView}}"
                   MinWidth="{Binding (ListView.View).ItemWidth,
                   RelativeSource={RelativeSource AncestorType=ListView}}"
                   ItemHeight="{Binding (ListView.View).ItemHeight,
                   RelativeSource={RelativeSource AncestorType=ListView}}"/>
      </ItemsPanelTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

若要在自定义视图模式中定义的数据布局，定义[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)对象。 下面的示例定义[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)可用来显示数据中的`PlainView`视图模式。

```xaml
<DataTemplate x:Key="centralTile">
  <StackPanel Height="100" Width="90">
    <Grid Width="70" Height="70" HorizontalAlignment="Center">
      <Image Source="{Binding XPath=@Image}" Margin="6,6,6,9"/>
    </Grid>
    <TextBlock Text="{Binding XPath=@Name}" FontSize="13" 
               HorizontalAlignment="Center" Margin="0,0,0,1" />
    <TextBlock Text="{Binding XPath=@Type}" FontSize="9" 
               HorizontalAlignment="Center" Margin="0,0,0,1" />
  </StackPanel>
</DataTemplate>
```

下面的示例演示如何定义[ResourceKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.resourcekey)有关`PlainView`使用的视图模式[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)上一示例中定义。

```xaml
<l:PlainView x:Key="tileView" 
             ItemTemplate="{StaticResource centralTile}" 
             ItemWidth="100"/>
```

一个[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控件可以使用自定义视图，如果您设置[View](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview.view)属性设置为资源键。 下面的示例演示如何指定`PlainView`的视图模式[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)。

```csharp
//Set the ListView View property to the tileView custom view
lv.View = lv.FindResource("tileView") as ViewBase;
```

有关完整示例，请参阅[具有多个视图的 ListView (C#)](https://github.com/dotnet/samples/tree/master/snippets/csharp/VS_Snippets_Wpf/ListViewCustomView/CSharp)或[ListView 与多个 Views(Visual Basic)](https://github.com/dotnet/samples/tree/master/snippets/visualbasic/VS_Snippets_Wpf/ListViewCustomView/visualbasic)。

##### [Use Templates to Style a ListView That Uses GridView](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-use-templates-to-style-a-listview-that-uses-gridview)

此示例演示如何使用[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)并[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)对象来指定的外观[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控件，它使用[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)视图模式。

**示例**

下面的示例演示[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)并[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)对象的自定义的列标题的外观[GridViewColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn)。

```xaml
<Style x:Key="myHeaderStyle" TargetType="{x:Type GridViewColumnHeader}">
  <Setter Property="Background" Value="LightBlue"/>
</Style>
```

```xaml
<DataTemplate x:Key="myHeaderTemplate">
  <DockPanel>
    <CheckBox/>
    <TextBlock FontSize="16" Foreground="DarkBlue">
      <TextBlock.Text>
        <Binding/>
      </TextBlock.Text>
    </TextBlock>
  </DockPanel>
</DataTemplate>
```

下面的示例演示如何使用这些[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)并[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)对象来设置[HeaderContainerStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn.headercontainerstyle)并[HeaderTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn.headertemplate)的属性[GridViewColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn)。 [DisplayMemberBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn.displaymemberbinding)属性定义的列单元格的内容。

```xaml
<GridViewColumn Header="Month" Width="80"
      HeaderContainerStyle="{StaticResource myHeaderStyle}"
      HeaderTemplate="{StaticResource myHeaderTemplate}"
      DisplayMemberBinding="{Binding Path=Month}"/>
```

[HeaderContainerStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn.headercontainerstyle)并[HeaderTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn.headertemplate)只有两种可用于自定义列标题外观的多个属性[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)控件。 有关详细信息，请参阅 [GridView 列标题的样式和模板概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/gridview-column-header-styles-and-templates-overview)。

下面的示例演示如何定义[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)的自定义中的单元格的外观[GridViewColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn)。

```xaml
<DataTemplate x:Key="myCellTemplateMonth">
  <DockPanel>
    <TextBlock Foreground="DarkBlue" HorizontalAlignment="Center">
      <TextBlock.Text>
        <Binding Path="Month"/>
      </TextBlock.Text>
    </TextBlock>
  </DockPanel>
</DataTemplate>
```

下面的示例演示如何使用此[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)定义的内容[GridViewColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn)单元格。 而不是使用此模板[DisplayMemberBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn.displaymemberbinding)在以前显示的属性[GridViewColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn)示例。

```xaml
<GridViewColumn Header="Month" Width="80"
      CellTemplate="{StaticResource myCellTemplateMonth}"/>
```

##### [Create a Style for a Dragged GridView Column Header](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-create-a-style-for-a-dragged-gridview-column-header)

此示例演示如何更改外观的拖动[GridViewColumnHeader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumnheader)当用户更改的列位置。

**示例**

当将列标题拖到其他位置[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)，它使用[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)作为其视图模式，在列移至新位置。 当您拖动列标题时，标头的浮点副本会显示除了原始标头。 中的列标题[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)为由[GridViewColumnHeader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumnheader)对象。

若要自定义这两个浮点型和原始标头的外观，可以设置[Triggers](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate.triggers)修改[GridViewColumnHeader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumnheader) [Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)。 这些[Triggers](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate.triggers)时应用[IsPressed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.ispressed)属性值是`true`并且[Role](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumnheader.role)属性值是[Floating](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumnheaderrole#System_Windows_Controls_GridViewColumnHeaderRole_Floating)。

当用户按下鼠标左键和鼠标悬停在按住[GridViewColumnHeader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumnheader)，则[IsPressed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.ispressed)属性值更改为`true`。 同样，当用户开始拖动操作时，才[Role](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumnheader.role)属性更改为[Floating](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumnheaderrole#System_Windows_Controls_GridViewColumnHeaderRole_Floating)。

下面的示例演示如何设置[Triggers](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate.triggers)若要更改[Foreground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.foreground)和[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)原始窗口和浮动的标头时用户将列拖至新位置的颜色。

XAML复制

```xaml
<ControlTemplate TargetType="{x:Type GridViewColumnHeader}">
```

XAML复制

```xaml
<ControlTemplate.Triggers>
```

XAML复制

```xaml
<Trigger Property="IsPressed"
         Value="true">
  <Setter TargetName="HighlightBorder"
          Property="Visibility"
          Value="Hidden"/>
  <Setter TargetName="PART_HeaderGripper"
          Property="Visibility"
          Value="Hidden"/>
  <Setter Property="Background"
          Value="SkyBlue"/>
  <Setter Property="Foreground"
          Value="Yellow"/>
</Trigger>
```

XAML复制

```xaml
<Trigger Property="Role"
         Value="Floating">
  <Setter TargetName="PART_HeaderGripper"
          Property="Visibility"
          Value="Collapsed"/>
  <Setter Property="Background"
          Value="Yellow"/>
  <Setter Property="Foreground"
          Value="SkyBlue"/>
</Trigger>
```

XAML复制

```xaml
</ControlTemplate.Triggers>
```

XAML复制

```xaml
</ControlTemplate>
```

##### [Display ListView Contents by Using a GridView](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-display-listview-contents-by-using-a-gridview)

此示例演示如何定义[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)视图模式[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控件。

**示例**

您可以定义的视图模式[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)通过指定[GridViewColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn)对象。 下面的示例演示如何定义[GridViewColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn)绑定到为指定的数据内容的对象[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控件。 这[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)的示例指定三个[GridViewColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn)映射到的对象`FirstName`， `LastName`，并`EmployeeNumber`的字段`EmployeeInfoDataSource`设置为[ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource)的[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控件。

```xaml
<ListView ItemsSource="{Binding Source=
                       {StaticResource EmployeeInfoDataSource}}">

  <ListView.View>

    <GridView AllowsColumnReorder="true"
              ColumnHeaderToolTip="Employee Information">

      <GridViewColumn DisplayMemberBinding=
                          "{Binding Path=FirstName}" 
                      Header="First Name" Width="100"/>
        
                  <GridViewColumn DisplayMemberBinding=
                          "{Binding Path=LastName}" 
                      Width="100">
                      <GridViewColumnHeader>Last Name
                          <GridViewColumnHeader.ContextMenu>
                          <ContextMenu  MenuItem.Click="LastNameCM_Click"  
                                        Name="LastNameCM">
                              <MenuItem Header="Ascending" />
                              <MenuItem Header="Descending" />
                          </ContextMenu>
                          </GridViewColumnHeader.ContextMenu>
                      </GridViewColumnHeader>
                  </GridViewColumn>

                  <GridViewColumn DisplayMemberBinding=
                          "{Binding Path=EmployeeNumber}" 
                      Header="Employee No." Width="100"/>
    </GridView>

  </ListView.View>
</ListView>
```

下图显示了此示例中的显示方式。

![具有 GridView 输出的 ListView](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/listviewgridview.jpg)

##### [Use Triggers to Style Selected Items in a ListView](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-use-triggers-to-style-selected-items-in-a-listview)

此示例演示如何定义[Triggers](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style.triggers)有关[ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listviewitem)控件，以便时的属性值[ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listviewitem)更改，[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)的[ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listviewitem)响应中的更改。

**示例**

如果你想[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)的[ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listviewitem)若要更改以响应属性更改，请定义[Triggers](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style.triggers)为[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)更改。

下面的示例定义[Trigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.trigger)，用于设置[Foreground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.foreground)属性设置为[Blue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brushes.blue)，并更改[Cursor](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.cursor)以显示[Hand](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.input.cursortype#System_Windows_Input_CursorType_Hand)时[IsMouseOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ismouseover)属性更改为`true`。

XAML复制

```xaml
<Style x:Key="MyContainer" TargetType="{x:Type ListViewItem}">

  <Setter Property="Margin" Value="0,1,0,0"/>
  <Setter Property="Height" Value="21"/>

  <Style.Triggers>
```

XAML复制

```xaml
<Trigger Property="IsMouseOver" Value="true">
  <Setter Property="Foreground" Value="Blue" />
  <Setter Property="Cursor" Value="Hand"/>
</Trigger>
```

XAML复制

```xaml
  </Style.Triggers>
</Style>
```

下面的示例定义[MultiTrigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.multitrigger)，用于设置[Foreground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.foreground)的属性[ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listviewitem)到[Yellow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brushes.yellow)时[ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listviewitem)是选定的项且具有键盘焦点。

XAML复制

```xaml
<Style x:Key="MyContainer" TargetType="{x:Type ListViewItem}">

  <Setter Property="Margin" Value="0,1,0,0"/>
  <Setter Property="Height" Value="21"/>

  <Style.Triggers>
```

XAML复制

```xaml
<MultiTrigger>
  <MultiTrigger.Conditions>
    <Condition Property="IsSelected" Value="true" />
    <Condition Property="Selector.IsSelectionActive" Value="true" />
  </MultiTrigger.Conditions>
  <Setter Property="Foreground" Value="Yellow" />
</MultiTrigger>
```

XAML复制

```xaml
  </Style.Triggers>
</Style>
```

##### [Create ListViewItems with a CheckBox](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-create-listviewitems-with-a-checkbox)

此示例演示如何显示的列[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)中的控件[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控件，它使用[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)。

**示例**

若要创建包含的列[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)中的控件[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)，创建[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)，其中包含[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)。 然后设置[CellTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn.celltemplate)的[GridViewColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn)到[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)。

下面的示例演示[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)，其中包含[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)。 该示例将绑定[IsChecked](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.togglebutton.ischecked)的属性[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)到[IsSelected](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem.isselected)属性值为[ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listviewitem)包含它。 因此，当[ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listviewitem)，其中包含[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)已选中[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)检查。

XAML复制

```xaml
<DataTemplate x:Key="FirstCell">
  <StackPanel Orientation="Horizontal">
    <CheckBox IsChecked="{Binding Path=IsSelected, 
      RelativeSource={RelativeSource FindAncestor, AncestorType={x:Type ListViewItem}}}"/>
  </StackPanel>
</DataTemplate>
```

下面的示例演示如何创建一列[CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)控件。 若要将列，该示例设置[CellTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn.celltemplate)的属性[GridViewColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn)到[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)。

```xaml
<GridViewColumn CellTemplate="{StaticResource FirstCell}" 
                Width="30"/>
```

##### [Display Data by Using GridViewRowPresenter](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-display-data-by-using-gridviewrowpresenter)

此示例演示如何使用[GridViewRowPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewrowpresenter)和[GridViewHeaderRowPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewheaderrowpresenter)要在列中显示数据的对象。

**示例**

下面的示例演示如何指定[GridViewColumnCollection](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumncollection)，它显示[DayOfWeek](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime.dayofweek)并[Year](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime.year)的[DateTime](https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime)使用的对象[GridViewRowPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewrowpresenter)和[GridViewHeaderRowPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewheaderrowpresenter)对象。 该示例还定义了[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)有关[Header](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn.header)的[GridViewColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn)。

```xaml
<Window xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
        xmlns:x='http://schemas.microsoft.com/winfx/2006/xaml'
        xmlns:sys="clr-namespace:System;assembly=mscorlib">
 
  <Window.Resources>

    <Style x:Key="MyHeaderStyle" TargetType="{x:Type GridViewColumnHeader}">
     <Setter Property="Background" Value="BurlyWood"/>
    </Style>

    <GridViewColumnCollection x:Key="gvcc">
      <GridViewColumn Header="Year" 
                      DisplayMemberBinding="{Binding Year}" 
                      Width="80"/>
      <GridViewColumn Header="Day"  
                      DisplayMemberBinding="{Binding DayOfWeek}" 
                      Width="80" />

    </GridViewColumnCollection>

  </Window.Resources>
  
  <StackPanel>
    <GridViewHeaderRowPresenter Name="hrp" Columns="{StaticResource gvcc}"  
                                ColumnHeaderContainerStyle=
                                 "{StaticResource MyHeaderStyle}" />

    <GridViewRowPresenter Columns="{StaticResource gvcc}" >
      <GridViewRowPresenter.Content>
        <sys:DateTime>2005/2/1</sys:DateTime>
      </GridViewRowPresenter.Content>
     </GridViewRowPresenter>
    <GridViewRowPresenter Columns="{StaticResource gvcc}" >
      <GridViewRowPresenter.Content>
        <sys:DateTime>2006/10/12</sys:DateTime>
      </GridViewRowPresenter.Content>
    </GridViewRowPresenter>
  </StackPanel>

</Window>
```


##### [Group Items in a ListView That Implements a GridView](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-group-items-in-a-listview-that-implements-a-gridview)

此示例演示如何显示组中的项数[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)视图模式[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控件。

**示例**

若要显示组中的项数[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)，定义[CollectionViewSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource)。 下面的示例演示[CollectionViewSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource)分组数据项的值根据`Catalog`数据字段。

```xaml
<CollectionViewSource x:Key='src' 
                      Source="{Binding Source={StaticResource MyData}, 
                               XPath=Item}">
  <CollectionViewSource.GroupDescriptions>
    <PropertyGroupDescription PropertyName="@Catalog" />
  </CollectionViewSource.GroupDescriptions>
</CollectionViewSource>
```

下面的示例设置[ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource)有关[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)到[CollectionViewSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource)前面的示例定义。 该示例还定义了[GroupStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.groupstyle)实现[Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)控件。

```xaml
<ListView ItemsSource='{Binding Source={StaticResource src}}' 
          BorderThickness="0">
  <ListView.GroupStyle>
    <GroupStyle>
      <GroupStyle.ContainerStyle>
        <Style TargetType="{x:Type GroupItem}">
          <Setter Property="Margin" Value="0,0,0,5"/>
          <Setter Property="Template">
            <Setter.Value>
              <ControlTemplate TargetType="{x:Type GroupItem}">
                <Expander IsExpanded="True" BorderBrush="#FFA4B97F" 
                          BorderThickness="0,0,0,1">
                  <Expander.Header>
                    <DockPanel>
                      <TextBlock FontWeight="Bold" Text="{Binding Path=Name}" 
                                 Margin="5,0,0,0" Width="100"/>
                      <TextBlock FontWeight="Bold" 
                                 Text="{Binding Path=ItemCount}"/>
                    </DockPanel>
                  </Expander.Header>
                  <Expander.Content>
                    <ItemsPresenter />
                  </Expander.Content>
                </Expander>
              </ControlTemplate>
            </Setter.Value>
          </Setter>
        </Style>
      </GroupStyle.ContainerStyle>
    </GroupStyle>
  </ListView.GroupStyle>
```

```xaml
</ListView>
```

##### [Style a Row in a ListView That Implements a GridView](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-style-a-row-in-a-listview-that-implements-a-gridview)

此示例演示如何在中的行设置样式[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)实现控件[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)[View](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview.view)模式。

**示例**

您可以在中的行设置样式[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)通过设置控件[ItemContainerStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemcontainerstyle)上[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)控件。 表示为其项的样式设置[ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listviewitem)对象。 [ItemContainerStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemcontainerstyle)引用[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)用于显示行内容的对象。

提取了以下示例的完整示例中显示了存储在 XML 数据库中的歌曲信息集合。 数据库中的每首歌都有一个评级字段，此字段的值指定了歌曲信息行的显示方式。

下面的示例演示如何定义[ItemContainerStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemcontainerstyle)为[ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listviewitem)表示歌曲集合中的歌曲的对象。 [ItemContainerStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemcontainerstyle)引用[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)指定如何显示歌曲信息行的对象。

XAML复制

```xaml
 <ListView.ItemContainerStyle>
  <Style TargetType="{x:Type ListViewItem}"  >
    <Setter Property="Template"
          Value="{StaticResource Default}"/>
    <Style.Triggers>
      <DataTrigger Binding="{Binding XPath=@Rating}" Value="5">
              <Setter Property="Template" 
              Value="{StaticResource StronglyRecommended}"/>
      </DataTrigger>
      <DataTrigger Binding="{Binding XPath=@Rating}" Value="4">
        <Setter Property="Template" 
              Value="{StaticResource Recommended}"/>
      </DataTrigger>
    </Style.Triggers>
  </Style>
</ListView.ItemContainerStyle>
```

下面的示例演示[ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)，它将文本字符串`"Strongly Recommended"`到行。 此模板中引用[ItemContainerStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemcontainerstyle)，并在歌曲的评级的值为 5 （五） 时显示。 [ControlTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.controltemplate)包括[GridViewRowPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewrowpresenter)对象，它定义的列中的行的内容布局[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)视图模式。

XAML复制

```xaml
<ControlTemplate x:Key="StronglyRecommended" 
                 TargetType='{x:Type ListViewItem}'>
  <StackPanel Background="Beige">
    <GridViewRowPresenter Content="{TemplateBinding Content}"
       Columns="{TemplateBinding GridView.ColumnCollection}"/>
    <TextBlock Background="LightBlue" Text="Strongly Recommended" />
  </StackPanel>
</ControlTemplate>
```

下面的示例定义[GridView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridview)。

XAML复制

```xaml
<ListView.View>
  <GridView ColumnHeaderContainerStyle="{StaticResource MyHeaderStyle}">
    <GridViewColumn Header="Name" 
                    DisplayMemberBinding="{Binding XPath=@Name}" 
                    Width="100"/>
    <GridViewColumn Header="Time" 
                    DisplayMemberBinding="{Binding XPath=@Time}" 
                    Width="80"/>
    <GridViewColumn Header="Artist"  
                    DisplayMemberBinding="{Binding XPath=@Artist}" 
                    Width="80" />
    <GridViewColumn Header="Disk" 
                    DisplayMemberBinding="{Binding XPath=@Disk}"  
                    Width="100"/>
  </GridView>
</ListView.View>
```

##### [Change the Horizontal Alignment of a Column in a ListView](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-change-the-horizontal-alignment-of-a-column-in-a-listview)

默认情况下，在每个列的内容[ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listviewitem)是左对齐。 可以通过提供更改每个列的对齐方式[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)并设置[HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.horizontalalignment)属性中的元素上[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)。 本主题介绍如何[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)将其内容默认情况下和如何更改某一列中的对齐方式对齐[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)。

**示例**

在下面的示例中的数据`Title`和`ISBN`列是左对齐。

```xaml
<!--XmlDataProvider is defined in a ResourceDictionary, 
    such as Window.Resources-->
<XmlDataProvider x:Key="InventoryData" XPath="Books">
    <x:XData>
        <Books xmlns="">
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
    </x:XData>
</XmlDataProvider>
```

```xaml
<ListView ItemsSource="{Binding Source={StaticResource InventoryData}, XPath=Book}">
    <ListView.View>
        <GridView>
            <GridViewColumn Width="300" Header="Title" 
                            DisplayMemberBinding="{Binding XPath=Title}"/>
            <GridViewColumn Width="150" Header="ISBN" 
                            DisplayMemberBinding="{Binding XPath=@ISBN}"/>
        </GridView>
    </ListView.View>
</ListView>
```

若要更改的对齐方式`ISBN`列中，您需要指定[HorizontalContentAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.horizontalcontentalignment)每个属性[ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listviewitem)是[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.horizontalalignment#System_Windows_HorizontalAlignment_Stretch)，以便在每个元素[ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listviewitem)可以跨或占据整个宽度的每个列。 因为[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)绑定到数据源，您需要创建样式设置[HorizontalContentAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.horizontalcontentalignment)。 接下来，需要使用[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)若要显示的内容而不是使用[DisplayMemberBinding](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn.displaymemberbinding)属性。 若要显示`ISBN`的每个模板[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)可以只包含[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)具有其[HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.horizontalalignment)属性设置为[Right](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.horizontalalignment#System_Windows_HorizontalAlignment_Right)。

下面的示例定义的样式和[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)不必`ISBN`右对齐的列和更改[GridViewColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridviewcolumn)引用[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)。

```xaml
<!--The Style and DataTemplate are defined in a ResourceDictionary, 
    such as Window.Resources-->
<Style TargetType="ListViewItem">
    <Setter Property="HorizontalContentAlignment" Value="Stretch"/>
</Style>

<DataTemplate x:Key="ISBNTemplate">
    <TextBlock HorizontalAlignment="Right" 
               Text="{Binding XPath=@ISBN}"/>
</DataTemplate>
```

```xaml
<ListView ItemsSource="{Binding Source={StaticResource InventoryData}, XPath=Book}">
    <ListView.View>
        <GridView>
            <GridViewColumn Width="300" Header="Title" 
                            DisplayMemberBinding="{Binding XPath=Title}"/>
            <GridViewColumn Width="150" Header="ISBN" 
                            CellTemplate="{StaticResource ISBNTemplate}"/>
        </GridView>
    </ListView.View>
</ListView>
```

##### [Handle the MouseDoubleClick Event for Each Item in a ListView](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-handle-the-mousedoubleclick-event-for-each-item-in-a-listview)

若要处理的事件中的项[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)，需要将事件处理程序添加到每个[ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listviewitem)。 当[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)绑定到数据源，您无需显式创建[ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listviewitem)，可以通过添加处理每个项的事件，但[EventSetter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.eventsetter)样式的[ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listviewitem)。

**示例**

下面的示例创建数据绑定[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)，并创建[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)若要将事件处理程序添加到每个[ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listviewitem)。

```xaml
<!--XmlDataProvider is defined in a ResourceDictionary, 
    such as Window.Resources-->
<XmlDataProvider x:Key="InventoryData" XPath="Books">
    <x:XData>
        <Books xmlns="">
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
    </x:XData>
</XmlDataProvider>
```



```xaml
<!--The Style is defined in a ResourceDictionary, 
    such as Window.Resources-->
<Style TargetType="ListViewItem">
    <EventSetter Event="MouseDoubleClick" Handler="ListViewItem_MouseDoubleClick"/>
</Style>
```

```xaml
<ListView ItemsSource="{Binding Source={StaticResource InventoryData}, XPath=Book}">
    <ListView.View>
        <GridView>
            <GridViewColumn Width="300" Header="Title" 
                            DisplayMemberBinding="{Binding XPath=Title}"/>
            <GridViewColumn Width="150" Header="ISBN" 
                            DisplayMemberBinding="{Binding XPath=@ISBN}"/>
        </GridView>
    </ListView.View>
</ListView>
```

下面的示例处理[MouseDoubleClick](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.mousedoubleclick)事件。

```csharp
void ListViewItem_MouseDoubleClick(object sender, MouseButtonEventArgs e)
{

    XmlElement book = ((ListViewItem) sender).Content as XmlElement;

    if (book == null)
    {
        return;
    }

    if (book.GetAttribute("Stock") == "out")
    {
        MessageBox.Show("Time to order more copies of " + book["Title"].InnerText);
    }
    else
    {
        MessageBox.Show(book["Title"].InnerText + " is available.");
    }
}
```

> 尽管最常见的绑定[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)到数据源，可以使用一种样式，将事件处理程序添加到每个[ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listviewitem)在非数据绑定到的[ListView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listview)无论是否显式创建[ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listviewitem)。 有关详细信息创建显式和隐式[ListViewItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listviewitem)控件，请参阅[ItemsControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol)。