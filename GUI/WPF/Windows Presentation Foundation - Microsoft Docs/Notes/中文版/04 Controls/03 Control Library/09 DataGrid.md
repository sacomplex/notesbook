## [DataGrid](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/datagrid)

[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)控件可以显示和编辑来自许多不同数据源，例如从 SQL 数据库、 LINQ 查询或任何其他可绑定数据源。有关详细信息，请参阅[绑定源概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/binding-sources-overview)。

列可以显示文本、 控件，如[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)，或任何其他 WPF 内容，例如图像、 按钮或模板中包含的任何内容。 可以使用[DataGridTemplateColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridtemplatecolumn)显示模板中定义的数据。 下表列出了默认情况下提供的列类型。

| 生成的列类型                                                 | 数据类型                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [DataGridTextColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridtextcolumn) | [String](https://docs.microsoft.com/zh-cn/dotnet/api/system.string) |
| [DataGridCheckBoxColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridcheckboxcolumn) | [Boolean](https://docs.microsoft.com/zh-cn/dotnet/api/system.boolean) |
| [DataGridComboBoxColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridcomboboxcolumn) | [Enum](https://docs.microsoft.com/zh-cn/dotnet/api/system.enum) |
| [DataGridHyperlinkColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridhyperlinkcolumn) | [Uri](https://docs.microsoft.com/zh-cn/dotnet/api/system.uri) |

[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid) 可以自定义外观，例如设置单元格字体、 颜色和大小。 [DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid) 支持其他 WPF 控件的所有样式和模板化功能。 [DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid) 此外包括默认值和可自定义行为的编辑、 排序和验证。

下表列出了一些常见任务[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)以及如何完成它们。 通过查看相关的 API，您可以找到详细信息和示例代码。

| 方案                              | 方法                                                         |
| --------------------------------- | ------------------------------------------------------------ |
| 交替的背景色                      | 设置[AlternationIndex](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.alternationindex)属性设置为 2 或更大，然后将分配[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)到[RowBackground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.rowbackground)和[AlternatingRowBackground](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.alternatingrowbackground)属性。 |
| 定义单元格和行选择行为            | 设置 [SelectionMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.selectionmode) 和 [SelectionUnit](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.selectionunit) 属性。 |
| 自定义标头、 单元格和行的可视外观 | 应用的新[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)到[ColumnHeaderStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.columnheaderstyle)， [RowHeaderStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.rowheaderstyle)， [CellStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.cellstyle)，或[RowStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.rowstyle)属性。 |
| 设置调整大小选项                  | 设置[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)， [MaxHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.maxheight)， [MinHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.minheight)， [Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)， [MaxWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.maxwidth)，或[MinWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.minwidth)属性。 有关详细信息，请参阅[DataGrid 控件中调整大小选项](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/sizing-options-in-the-datagrid-control)。 |
| 访问选定项                        | 检查[SelectedCells](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.selectedcells)属性来获取所选单元格和[SelectedItems](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.multiselector.selecteditems)属性来获取所选的行。 有关详细信息，请参阅 [SelectedCells](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.selectedcells)。 |
| 自定义最终用户交互                | 设置[CanUserAddRows](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.canuseraddrows)， [CanUserDeleteRows](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.canuserdeleterows)， [CanUserReorderColumns](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.canuserreordercolumns)， [CanUserResizeColumns](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.canuserresizecolumns)，[CanUserResizeRows](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.canuserresizerows)，并[CanUserSortColumns](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.canusersortcolumns)属性。 |
| 取消或更改自动生成的列            | 处理[AutoGeneratingColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.autogeneratingcolumn)事件。 |
| 冻结列                            | 设置[FrozenColumnCount](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.frozencolumncount)属性设置为 1 并将列移动到的最左边的位置通过设置[DisplayIndex](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridcolumn.displayindex)属性设为 0。 |
| 使用 XML 数据作为数据源           | 将绑定[ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource)上[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)对 XPath 查询的表示的项的集合。 创建在每个列[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)。 通过对查询上项的源获取的属性的绑定上设置 XPath 绑定每个列。 有关示例，请参见 [DataGridTextColumn](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridtextcolumn)。 |

### 相关主题

| 标题                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [演练：DataGrid 控件中显示的 SQL Server 数据库中的数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/walkthrough-display-data-from-a-sql-server-database-in-a-datagrid-control) | 介绍如何设置新的 WPF 项目，添加实体框架元素、 设置源，并显示中的数据[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)。 |
| [如何：将行详细信息添加到 DataGrid 控件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-add-row-details-to-a-datagrid-control) | 介绍如何创建用于行详细信息[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)。 |
| [如何：使用 DataGrid 控件实现验证](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-implement-validation-with-the-datagrid-control) | 描述如何验证中的值[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)单元格和行，以及显示验证反馈。 |
| [DataGrid 控件中的默认键盘和鼠标行为](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/default-keyboard-and-mouse-behavior-in-the-datagrid-control) | 介绍如何与之交互[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)控件中的使用键盘和鼠标。 |
| [如何：分组、 排序和筛选数据的 DataGrid 控件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-group-sort-and-filter-data-in-the-datagrid-control) | 描述如何查看中的数据[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)分组、 排序和筛选的数据通过不同的方式。 |
| [DataGrid 控件中的重设大小选项](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/sizing-options-in-the-datagrid-control) | 描述如何控制中的绝对和自动大小调整[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)。 |

### [Default Keyboard and Mouse Behavior in the DataGrid Control](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/default-keyboard-and-mouse-behavior-in-the-datagrid-control)

本主题介绍用户如何与交互[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)控件中的使用键盘和鼠标。

与典型交互[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)包括导航、 选择和编辑。 选择行为受[SelectionMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.selectionmode)和[SelectionUnit](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.selectionunit)属性。 本主题中导致所述的行为的默认值是[DataGridSelectionMode.Extended](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridselectionmode#System_Windows_Controls_DataGridSelectionMode_Extended)和[DataGridSelectionUnit.FullRow](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridselectionunit#System_Windows_Controls_DataGridSelectionUnit_FullRow)。 更改这些值可能会导致不同于所述的行为。 编辑控件时单元格处于编辑模式下，可能会重写的标准键盘行为[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)。

#### 默认键盘行为

下表列出的默认键盘行为[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)。

| 键或键组合     | 描述                                                         |
| -------------- | ------------------------------------------------------------ |
| 向下键         | 将焦点移到当前单元格的正下方的单元格。 如果焦点位于最后一行中，按向下键没有任何影响。 |
| 向上键         | 将焦点移到当前单元格的正上方的单元格。 如果焦点位于第一行中，按向上键没有任何影响。 |
| 向左键         | 将焦点移到上一个单元格的行中。 如果焦点位于行中的第一个单元中，按向左键没有任何影响。 |
| 向右键         | 将焦点移到下一个单元格的行中。 如果焦点位于行中的最后一个单元中，按向右箭头没有任何影响。 |
| Home           | 将焦点移到当前行中的第一个单元。                             |
| End            | 将焦点移到当前行中的最后一个单元。                           |
| PAGE DOWN      | 如果未分组的行，将控件向下滚动完全显示的行数。 将焦点移动到完全显示的最后一行，而无需更改的列。  如果行分组，将焦点移到中的最后一行[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)而无需更改的列。 |
| PAGE UP        | 如果未分组的行，该控件向上滚动完全显示的行数。 将焦点移到而无需更改列显示的第一行。  如果行分组，将焦点移到中的第一行[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)而无需更改的列。 |
| Tab            | 将焦点移到下一个单元格的当前行。 如果焦点位于行的最后一个单元格，则将焦点移到下一行中的第一个单元。 如果焦点在控件中的最后一个单元中，将焦点移到下一个控件的父容器的 tab 键顺序。  如果当前单元格处于编辑模式并按 tab 键引起焦点将从当前行移开，对行所做的任何更改会提交更改焦点之前。 |
| Shift+Tab      | 将焦点移到上一个单元格的当前行中。 如果焦点已在行的第一个单元中，将焦点移到上一行中的最后一个单元。 如果焦点在控件中的第一个单元中，将焦点移到上一个控件的父容器的 tab 键顺序。  如果当前单元格处于编辑模式并按 tab 键引起焦点将从当前行移开，对行所做的任何更改会提交更改焦点之前。 |
| Ctrl+向下键    | 将焦点移到当前列中的最后一个单元格。                         |
| Ctrl+向上键    | 将焦点移到当前列中的第一个单元格。                           |
| Ctrl+向右键    | 将焦点移到当前行中的最后一个单元。                           |
| Ctrl+向左键    | 将焦点移到当前行中的第一个单元。                             |
| CTRL + HOME    | 将焦点移到控件中的第一个单元。                               |
| CTRL + END     | 将焦点移到控件中的最后一个单元。                             |
| Ctrl+Page Down | 向下翻页相同。                                               |
| Ctrl+Page Up   | 向上翻页相同。                                               |
| F2             | 如果[DataGrid.IsReadOnly](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.isreadonly)属性是`false`并[DataGridColumn.IsReadOnly](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridcolumn.isreadonly)属性是`false`当前列中，将当前单元格放入单元格编辑模式。 |
| Enter          | 提交到当前单元格和行的任何更改并将焦点移到当前单元格的正下方的单元格。 如果焦点位于最后一行中，而无需移动焦点提交任何更改。 |
| Esc            | 如果控件处于编辑模式下，取消编辑，恢复在控件中所做的任何更改。 如果基础数据源实现[IEditableObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.ieditableobject)，第二次按 esc 键取消整个行的编辑模式。 |
| 退格符         | 编辑单元格时，请删除光标位置前的字符。                       |
| DELETE         | 编辑单元格时，光标位置后删除的字符。                         |
| Ctrl+Enter     | 而无需将焦点移动到当前单元格提交任何更改。                   |
| Ctrl+A         | 如果[SelectionMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.selectionmode)设置为[Extended](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridselectionmode#System_Windows_Controls_DataGridSelectionMode_Extended)，选择中的所有行[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)。 |

#### 选择键

如果[SelectionMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.selectionmode)属性设置为[Extended](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridselectionmode#System_Windows_Controls_DataGridSelectionMode_Extended)、 导航行为不会更改，但按下 shift 键 （包括 CTRL + SHIFT） 时使用键盘导航将修改多行选择。 导航开始前，该控件将当前行标记为定位行。 导航在按住 SHIFT 的同时，所选内容包括定位行和当前行之间的所有行。

以下选择键修改多行的选择。

- Shift+向下键
- Shift+向上键
- Shift+Page Down
- Shift+Page Up
- Ctrl+Shift+向下键
- Ctrl+Shift+向上键
- CTRL + SHIFT + HOME
- CTRL + SHIFT + END

#### 默认鼠标行为

下表列出了默认鼠标行为[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)。

| 鼠标操作                                                     | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| 单击未选定的行                                               | 将当前行，并单击的单元格的当前单元格包含被单击的行。         |
| 单击当前单元格                                               | 当前单元格置于编辑模式。                                     |
| 拖动列标题单元格                                             | 如果[DataGrid.CanUserReorderColumns](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.canuserreordercolumns)属性是`true`并[DataGridColumn.CanUserReorder](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridcolumn.canuserreorder)属性是`true`当前列中，移动列，使其可以放入新的位置。 |
| 拖动列标题分隔符                                             | 如果[DataGrid.CanUserResizeColumns](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.canuserresizecolumns)属性是`true`并[DataGridColumn.CanUserResize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridcolumn.canuserresize)属性是`true`当前列中，调整大小的列。 |
| 双击列标题分隔符                                             | 如果[DataGrid.CanUserResizeColumns](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.canuserresizecolumns)属性是`true`并[DataGridColumn.CanUserResize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridcolumn.canuserresize)属性是`true`当前列中，自动大小的列使用[Auto](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridlength.auto)调整大小模式。 |
| 单击列标题单元格                                             | 如果[DataGrid.CanUserSortColumns](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.canusersortcolumns)属性是`true`并[DataGridColumn.CanUserSort](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridcolumn.canusersort)属性是`true`当前列进行排序的列。  单击已排序的列标题将反转该列的排序方向。  当单击多个列标题会按顺序单击多个列进行排序时，按下 SHIFT 键。 |
| CTRL + 单击的行                                              | 如果[SelectionMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.selectionmode)设置为[Extended](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridselectionmode#System_Windows_Controls_DataGridSelectionMode_Extended)，修改非连续多行选择。  如果已选择的行，则取消选择该行。 |
| 按住 SHIFT 的同时单击的行                                    | 如果[SelectionMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.selectionmode)设置为[Extended](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridselectionmode#System_Windows_Controls_DataGridSelectionMode_Extended)，修改连续多行选择。 |
| 单击行组标题                                                 | 展开或折叠组。                                               |
| 单击左上角的全选按钮 [DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid) | 如果[SelectionMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.selectionmode)设置为[Extended](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridselectionmode#System_Windows_Controls_DataGridSelectionMode_Extended)，选择中的所有行[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)。 |

#### 鼠标选择

如果[SelectionMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.selectionmode)属性设置为[Extended](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridselectionmode#System_Windows_Controls_DataGridSelectionMode_Extended)，在按下 CTRL 或 SHIFT 的同时单击某一行将修改多行选择。

时按住 CTRL 的同时单击某一行，该行将更改其选择状态，而所有其他行保留其当前选择状态。 这样做可以选择不相邻的行。

在按住 SHIFT 的同时单击某一行，所选内容将包括当前行和当前行之前单击位置定位行之间的所有行。 随后按下 shift 键的同时单击更改当前行，而不是定位点行。 此方法选择相邻的行的范围。

CTRL + SHIFT 可以组合以选择相邻的行的非相邻的范围。 若要执行此操作，选择第一个范围，通过使用 SHIFT + 单击前面所述。 选择的行的第一个范围后，使用 CTRL + 单击可在下一步的范围内，选择第一行，然后按 CTRL + SHIFT 的同时单击下一个范围中的最后一行。

### [How to: Add Row Details to a DataGrid Control](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-add-row-details-to-a-datagrid-control)

使用时[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)控件，你可以自定义数据表示通过添加行详细信息部分。 添加行详细信息部分，可根据需要可见还是折叠的模板中的某些数据进行分组。 例如，你可以添加行详细信息，以便[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)这将显示仅用于中的每一行的数据的摘要[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)，但当用户选择某一行显示更多数据字段。 定义行详细信息部分中的模板[RowDetailsTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.rowdetailstemplate)属性。 下图显示行详细信息部分的示例。

![显示与行详细信息的 DataGrid](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/ndp-rowdetails.png)

为任一内联 XAML 或作为资源定义行详细信息模板。 这两种方法的以下过程所示。 可以在整个项目能使用作为资源添加的数据模板，而无需重新创建模板。 添加，如内联 XAML，才可以访问从控件定义数据模板。

#### 若要使用内联 XAML 显示行详细信息

1. 创建[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)显示来自数据源的数据。

2. 在 [DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid) 元素内，添加一个 [RowDetailsTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.rowdetailstemplate) 元素。

3. 创建[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)定义行详细信息部分的外观。

   下面的 XAML 演示[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)以及如何定义[RowDetailsTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.rowdetailstemplate)内联。 [DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)显示三个值中的每一行和第三个更多的值选择的行时。

   ```xaml
   <Window x:Class="WpfApplication1.MainWindow"
           xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
           xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
           Title="MainWindow" Height="350" Width="525" 
           Loaded="Window_Loaded">
       <Grid>
           <DataGrid Name="dataGrid1" IsReadOnly="True" AutoGenerateColumns="False" >
               <DataGrid.Columns>
                   <DataGridTextColumn Header="Company Name" Binding="{Binding CompanyName}"></DataGridTextColumn>
                   <DataGridTextColumn Header="Contact First Name" Binding="{Binding FirstName}"></DataGridTextColumn>
                   <DataGridTextColumn Header="Contact Last Name" Binding="{Binding LastName}"></DataGridTextColumn>
               </DataGrid.Columns>
               <DataGrid.RowDetailsTemplate>
                   <DataTemplate>
                       <Border BorderThickness="0" Background="BlanchedAlmond" Padding="10">
                           <StackPanel Orientation="Vertical">
                               <StackPanel Orientation="Horizontal">
                                   <TextBlock FontSize="12" Text="Email: " VerticalAlignment="Center" />
                                   <TextBlock FontSize="16" Foreground="MidnightBlue" Text="{Binding EmailAddress}" VerticalAlignment="Center" />
                               </StackPanel>
                               <StackPanel Orientation="Horizontal">
                                   <TextBlock FontSize="12" Text="Phone: " VerticalAlignment="Center" />
                                   <TextBlock FontSize="16" Foreground="MidnightBlue" Text="{Binding Phone}" VerticalAlignment="Center" />
                               </StackPanel>
                               <StackPanel Orientation="Horizontal">
                                   <TextBlock FontSize="12" Text="Sales Person: " VerticalAlignment="Center" />
                                   <TextBlock FontSize="16" Foreground="MidnightBlue" Text="{Binding SalesPerson}" VerticalAlignment="Center" />
                               </StackPanel>
                           </StackPanel>
                       </Border>
                   </DataTemplate>
               </DataGrid.RowDetailsTemplate>
           </DataGrid>
       </Grid>
   </Window>
   ```

   下面的代码演示用于选择中显示的数据的查询[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)。 在此示例中，查询从包含客户信息的实体中选择数据。

   ```csharp
   private void Window_Loaded(object sender, RoutedEventArgs e)
   {
       AdventureWorksLT2008Entities advenWorksEntities = new AdventureWorksLT2008Entities();
   
       ObjectQuery<Customer> customers = advenWorksEntities.Customers;
   
       var query =
       from customer in customers
       orderby customer.CompanyName
       select new
       {
           customer.LastName,
           customer.FirstName,
           customer.CompanyName,
           customer.Title,
           customer.EmailAddress,
           customer.Phone,
           customer.SalesPerson
       };
   
       dataGrid1.ItemsSource = query.ToList();
   }
   ```

#### 若要使用的资源显示行详细信息

1. 创建[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)显示来自数据源的数据。

2. 添加[Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.resources)元素到根元素，如[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)控件或[Page](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.page)控制，或添加[Resources](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application.resources)元素[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)App.xaml （或 Application.xaml） 文件中的类。

3. 在资源元素中，创建[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)定义行详细信息部分的外观。

   下面的 XAML 演示[RowDetailsTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.rowdetailstemplate)中定义[Application](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.application)类。

   ```xaml
   <Application.Resources>
       <DataTemplate x:Key="CustomerDetail">
           <Border BorderThickness="0" Background="BlanchedAlmond" Padding="10">
               <StackPanel Orientation="Vertical">
                   <StackPanel Orientation="Horizontal">
                       <TextBlock FontSize="12" Text="Email: " VerticalAlignment="Center" />
                       <TextBlock FontSize="16" Foreground="MidnightBlue" Text="{Binding EmailAddress}" VerticalAlignment="Center" />
                   </StackPanel>
                   <StackPanel Orientation="Horizontal">
                       <TextBlock FontSize="12" Text="Phone: " VerticalAlignment="Center" />
                       <TextBlock FontSize="16" Foreground="MidnightBlue" Text="{Binding Phone}" VerticalAlignment="Center" />
                   </StackPanel>
                   <StackPanel Orientation="Horizontal">
                       <TextBlock FontSize="12" Text="Sales Person: " VerticalAlignment="Center" />
                       <TextBlock FontSize="16" Foreground="MidnightBlue" Text="{Binding SalesPerson}" VerticalAlignment="Center" />
                   </StackPanel>
               </StackPanel>
           </Border>
       </DataTemplate>
   </Application.Resources>
   ```

4. 上[DataTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.datatemplate)，将其设置[X:key 指令](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-key-directive)为唯一标识数据模板的值。

5. 在[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)元素，设置[RowDetailsTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.rowdetailstemplate)属性设置为前面步骤中定义的资源。 将资源分配为静态资源。

   下面的 XAML 演示[RowDetailsTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.rowdetailstemplate)属性设置为资源从前面的示例。

   XAML复制

   ```xaml
   <DataGrid Name="dataGrid1" IsReadOnly="True" AutoGenerateColumns="False" RowDetailsTemplate="{StaticResource CustomerDetail}" >
       <DataGrid.Columns>
           <DataGridTextColumn Header="Company Name" Binding="{Binding CompanyName}"></DataGridTextColumn>
           <DataGridTextColumn Header="Contact First Name" Binding="{Binding FirstName}"></DataGridTextColumn>
           <DataGridTextColumn Header="Contact Last Name" Binding="{Binding LastName}"></DataGridTextColumn>
       </DataGrid.Columns>
   </DataGrid>
   ```

#### 若要设置可见性，并且允许水平滚动的行详细信息

1. 如果需要设置[RowDetailsVisibilityMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.rowdetailsvisibilitymode)属性[DataGridRowDetailsVisibilityMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridrowdetailsvisibilitymode)值。

   默认情况下，值设置为[VisibleWhenSelected](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridrowdetailsvisibilitymode#System_Windows_Controls_DataGridRowDetailsVisibilityMode_VisibleWhenSelected)。 你可以将其设置为[Visible](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridrowdetailsvisibilitymode#System_Windows_Controls_DataGridRowDetailsVisibilityMode_Visible)以显示的所有行的详细信息或[Collapsed](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridrowdetailsvisibilitymode#System_Windows_Controls_DataGridRowDetailsVisibilityMode_Collapsed)隐藏所有行的详细信息。

2. 如果需要设置[AreRowDetailsFrozen](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.arerowdetailsfrozen)属性`true`禁止行详细信息中水平滚动的部分。

### [How to: Group, Sort, and Filter Data in the DataGrid Control](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-group-sort-and-filter-data-in-the-datagrid-control)

通常很有用，若要查看中的数据[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)分组、 排序和筛选的数据通过不同的方式。 若要进行分组、 排序和筛选器中的数据[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)，你将其绑定到[CollectionView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionview)支持这些函数。 然后可以使用中的数据[CollectionView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionview)而不会影响基础数据源。 集合视图中的更改会反映在[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)用户界面 (UI)。

[CollectionView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionview)类提供了分组和排序功能，实现为数据源[IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable)接口。 [CollectionViewSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource)类，可设置的属性[CollectionView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionview)从 XAML。

在此示例中，一系列`Task`对象绑定到[CollectionViewSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource)。 [CollectionViewSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource)用作[ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource)为[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)。 在执行分组、 排序和筛选[CollectionViewSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource)，并显示在[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)UI。

![数据网格中的数据进行分组](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/wpf-datagridgroups.png)分组数据网格中的数据

#### CollectionViewSource 用作 ItemsSource

为进行分组、 排序和筛选器中的数据[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)控件，您将绑定[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)到[CollectionView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionview)支持这些函数。 在此示例中，[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)绑定到[CollectionViewSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource)，它提供有关这些函数[List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1)的`Task`对象。

##### 若要将 DataGrid 绑定到 CollectionViewSource

1. 创建的数据集合的实现[IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.ienumerable)接口。

   如果您使用[List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1)若要创建你的集合，应创建的新类继承自[List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1)而不是实例化的实例[List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1)。 这可以将数据绑定到 XAML 中的集合。

   > 集合中的对象必须实现[INotifyPropertyChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.inotifypropertychanged)已更改的接口和[IEditableObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.ieditableobject)接口，以便[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)以正确响应属性更改和编辑。 有关详细信息，请参阅[实现属性更改通知](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-implement-property-change-notification)。

   ```csharp
   // Requires using System.Collections.ObjectModel;
   public class Tasks : ObservableCollection<Task>
   {
       // Creating the Tasks collection in this way enables data binding from XAML.
   }
   ```

2. 在 XAML 中，创建集合类的实例并设置[X:key 指令](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-key-directive)。

3. 在 XAML 中，创建的实例[CollectionViewSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource)类中，设置[X:key 指令](https://docs.microsoft.com/zh-cn/dotnet/framework/xaml-services/x-key-directive)，并将设置为你的集合类的实例[Source](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource.source)。

   ```xaml
   <Window.Resources>
       <local:Tasks x:Key="tasks" />
       <CollectionViewSource x:Key="cvsTasks" Source="{StaticResource tasks}" 
                             Filter="CollectionViewSource_Filter">
       </CollectionViewSource>    
   </Window.Resources>
   ```

4. 创建的实例[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)类，并设置[ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource)属性设置为[CollectionViewSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource)。

   ```xaml
   <DataGrid x:Name="dataGrid1" 
             ItemsSource="{Binding Source={StaticResource cvsTasks}}"
             CanUserAddRows="False">
   ```

5. 访问[CollectionViewSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource)在代码中，使用[GetDefaultView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource.getdefaultview)方法以获取对引用[CollectionViewSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource)。

   ```csharp
   ICollectionView cvTasks = CollectionViewSource.GetDefaultView(dataGrid1.ItemsSource);
   ```

#### 对数据网格中的项进行分组

若要指定项中的分组方式[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)，则使用[PropertyGroupDescription](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.propertygroupdescription)类型在源视图中的项进行分组。

##### 使用 XAML 的 DataGrid 中的项

1. 创建[PropertyGroupDescription](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.propertygroupdescription)指定分组所依据的属性。 在 XAML 或代码中，可以指定属性。

   1. 在 XAML 中，设置[PropertyName](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.propertygroupdescription.propertyname)分组所依据的属性的名称。
   2. 在代码中，将传递到构造函数分组依据的属性的名称。

2. 添加[PropertyGroupDescription](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.propertygroupdescription)到[CollectionViewSource.GroupDescriptions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource.groupdescriptions)集合。

3. 添加的其他实例[PropertyGroupDescription](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.propertygroupdescription)到[GroupDescriptions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource.groupdescriptions)集合添加更多级别的分组。

   ```xaml
   <CollectionViewSource.GroupDescriptions>
       <PropertyGroupDescription PropertyName="ProjectName"/>
       <PropertyGroupDescription PropertyName="Complete"/>
   </CollectionViewSource.GroupDescriptions>
   ```

   ```csharp
   ICollectionView cvTasks = CollectionViewSource.GetDefaultView(dataGrid1.ItemsSource);
   if (cvTasks != null && cvTasks.CanGroup == true)
   {
       cvTasks.GroupDescriptions.Clear();
       cvTasks.GroupDescriptions.Add(new PropertyGroupDescription("ProjectName"));
       cvTasks.GroupDescriptions.Add(new PropertyGroupDescription("Complete"));
   }
   ```

4. 若要删除某个组，请删除[PropertyGroupDescription](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.propertygroupdescription)从[GroupDescriptions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource.groupdescriptions)集合。

5. 若要删除的所有组，请调用[Clear](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.objectmodel.collection-1.clear)方法的[GroupDescriptions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource.groupdescriptions)集合。

   ```csharp
   ICollectionView cvTasks = CollectionViewSource.GetDefaultView(dataGrid1.ItemsSource);
   if (cvTasks != null)
   {
       cvTasks.GroupDescriptions.Clear();
   }
   ```

项中的分组时[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)，可以定义[GroupStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.groupstyle)，它指定每个组的外观。 您将应用[GroupStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.groupstyle)通过将其添加到[GroupStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.groupstyle)DataGrid 的集合。 如果有多个级别的分组，可以将不同的样式应用到每个分组级别。 样式中定义的顺序应用。 例如，如果定义了两种样式，第一个将应用于顶级行组。 第二个样式将应用于在第二个级别的所有行组和更低版本。 [DataContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.datacontext)的[GroupStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.groupstyle)是[CollectionViewGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewgroup)组表示。

#### 若要更改的行组标题的外观

1. 创建[GroupStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.groupstyle)定义行组的外观。

2. 将放[GroupStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.groupstyle)内`<DataGrid.GroupStyle>`标记。

   ```xaml
   <DataGrid.GroupStyle>
       <!-- Style for groups at top level. -->
       <GroupStyle>
           <GroupStyle.ContainerStyle>
               <Style TargetType="{x:Type GroupItem}">
                   <Setter Property="Margin" Value="0,0,0,5"/>
                   <Setter Property="Template">
                       <Setter.Value>
                           <ControlTemplate TargetType="{x:Type GroupItem}">
                               <Expander IsExpanded="True" Background="#FF112255" BorderBrush="#FF002255" Foreground="#FFEEEEEE" BorderThickness="1,1,1,5">
                                   <Expander.Header>
                                       <DockPanel>
                                           <TextBlock FontWeight="Bold" Text="{Binding Path=Name}" Margin="5,0,0,0" Width="100"/>
                                           <TextBlock FontWeight="Bold" Text="{Binding Path=ItemCount}"/>
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
       <!-- Style for groups under the top level. -->
       <GroupStyle>
           <GroupStyle.HeaderTemplate>
               <DataTemplate>
                   <DockPanel Background="LightBlue">
                       <TextBlock Text="{Binding Path=Name, Converter={StaticResource completeConverter}}" Foreground="Blue" Margin="30,0,0,0" Width="100"/>
                       <TextBlock Text="{Binding Path=ItemCount}" Foreground="Blue"/>
                   </DockPanel>
               </DataTemplate>
           </GroupStyle.HeaderTemplate>
       </GroupStyle>
   </DataGrid.GroupStyle>
   ```

#### 数据网格中的项进行排序

若要指定项中的排序方式[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)，则使用[SortDescription](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.sortdescription)类型在源视图中的项进行排序。

##### 数据网格中的项进行排序

1. 创建[SortDescription](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.sortdescription)，它指定要作为排序依据的属性。 在 XAML 或代码中，可以指定属性。

   1. 在 XAML 中，设置[PropertyName](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.sortdescription.propertyname)为要作为排序依据的属性的名称。
   2. 在代码中，传递要作为排序依据的属性名称和[ListSortDirection](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.listsortdirection)到构造函数。

2. 添加[SortDescription](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.sortdescription)到[CollectionViewSource.SortDescriptions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource.sortdescriptions)集合。

3. 添加的其他实例[SortDescription](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.sortdescription)到[SortDescriptions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource.sortdescriptions)若要按其他属性的集合。

   ```xaml
   <CollectionViewSource.SortDescriptions>
       <!-- Requires 'xmlns:scm="clr-namespace:System.ComponentModel;assembly=WindowsBase"' declaration. -->
       <scm:SortDescription PropertyName="ProjectName"/>
       <scm:SortDescription PropertyName="Complete" />
       <scm:SortDescription PropertyName="DueDate" />
   </CollectionViewSource.SortDescriptions>
   ```

   ```csharp
   // Requires using System.ComponentModel;
   ICollectionView cvTasks = CollectionViewSource.GetDefaultView(dataGrid1.ItemsSource);
   if (cvTasks != null && cvTasks.CanSort == true)
   {
       cvTasks.SortDescriptions.Clear();
       cvTasks.SortDescriptions.Add(new SortDescription("ProjectName", ListSortDirection.Ascending));
       cvTasks.SortDescriptions.Add(new SortDescription("Complete", ListSortDirection.Ascending));
       cvTasks.SortDescriptions.Add(new SortDescription("DueDate", ListSortDirection.Ascending));
   }
   ```

#### 筛选数据网格中的项

筛选器中的项[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)使用[CollectionViewSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource)，提供的处理程序中的筛选逻辑[CollectionViewSource.Filter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource.filter)事件。

##### 若要筛选数据网格中的项

1. 添加的处理程序[CollectionViewSource.Filter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource.filter)事件。

2. 在[Filter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource.filter)事件处理程序，定义筛选逻辑。

   每次刷新该视图时，将应用筛选器。

   ```xaml
   <CollectionViewSource x:Key="cvsTasks" Source="{StaticResource tasks}" 
                         Filter="CollectionViewSource_Filter">
   ```

   ```csharp
   private void CollectionViewSource_Filter(object sender, FilterEventArgs e)
   {
       Task t = e.Item as Task;
       if (t != null)
       // If filter is turned on, filter completed items.
       {
           if (this.cbCompleteFilter.IsChecked == true && t.Complete == true)
               e.Accepted = false;
           else
               e.Accepted = true;
       }
   }
   ```

或者，可以筛选中的项[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)通过创建提供筛选逻辑和设置方法[CollectionView.Filter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionview.filter)应用该筛选器的属性。 若要查看此方法的示例，请参阅[视图中的筛选器数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/how-to-filter-data-in-a-view)。

#### 示例

下面的示例演示分组、 排序和筛选`Task`中的数据[CollectionViewSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource)并显示经过分组、 排序和筛选`Task`中的数据[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)。 [CollectionViewSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource)用作[ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource)为[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)。 在执行分组、 排序和筛选[CollectionViewSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.collectionviewsource)，并显示在[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)UI。

若要测试此示例中，你将需要调整 DGGroupSortFilterExample 名称以匹配你的项目名称。 如果使用的 Visual Basic，您需要更改的类名[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)所示。

```
<Window x:Class="MainWindow"
```

```xaml
<Window x:Class="DGGroupSortFilterExample.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:local="clr-namespace:DGGroupSortFilterExample"
        xmlns:scm="clr-namespace:System.ComponentModel;assembly=WindowsBase"
        Title="Group, Sort, and Filter Example" Height="575" Width="525">
    <Window.Resources>
        <local:CompleteConverter x:Key="completeConverter" />
        <local:Tasks x:Key="tasks" />
        <CollectionViewSource x:Key="cvsTasks" Source="{StaticResource tasks}" 
                              Filter="CollectionViewSource_Filter">
            <CollectionViewSource.SortDescriptions>
                <!-- Requires 'xmlns:scm="clr-namespace:System.ComponentModel;assembly=WindowsBase"' declaration. -->
                <scm:SortDescription PropertyName="ProjectName"/>
                <scm:SortDescription PropertyName="Complete" />
                <scm:SortDescription PropertyName="DueDate" />
            </CollectionViewSource.SortDescriptions>
            <CollectionViewSource.GroupDescriptions>
                <PropertyGroupDescription PropertyName="ProjectName"/>
                <PropertyGroupDescription PropertyName="Complete"/>
            </CollectionViewSource.GroupDescriptions>
        </CollectionViewSource>
    </Window.Resources>
    <Grid>
        <Grid.RowDefinitions>
            <RowDefinition />
            <RowDefinition Height="30" />
        </Grid.RowDefinitions>
        <DataGrid x:Name="dataGrid1" 
                  ItemsSource="{Binding Source={StaticResource cvsTasks}}"
                  CanUserAddRows="False">
            <DataGrid.GroupStyle>
                <!-- Style for groups at top level. -->
                <GroupStyle>
                    <GroupStyle.ContainerStyle>
                        <Style TargetType="{x:Type GroupItem}">
                            <Setter Property="Margin" Value="0,0,0,5"/>
                            <Setter Property="Template">
                                <Setter.Value>
                                    <ControlTemplate TargetType="{x:Type GroupItem}">
                                        <Expander IsExpanded="True" Background="#FF112255" BorderBrush="#FF002255" Foreground="#FFEEEEEE" BorderThickness="1,1,1,5">
                                            <Expander.Header>
                                                <DockPanel>
                                                    <TextBlock FontWeight="Bold" Text="{Binding Path=Name}" Margin="5,0,0,0" Width="100"/>
                                                    <TextBlock FontWeight="Bold" Text="{Binding Path=ItemCount}"/>
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
                <!-- Style for groups under the top level. -->
                <GroupStyle>
                    <GroupStyle.HeaderTemplate>
                        <DataTemplate>
                            <DockPanel Background="LightBlue">
                                <TextBlock Text="{Binding Path=Name, Converter={StaticResource completeConverter}}" Foreground="Blue" Margin="30,0,0,0" Width="100"/>
                                <TextBlock Text="{Binding Path=ItemCount}" Foreground="Blue"/>
                            </DockPanel>
                        </DataTemplate>
                    </GroupStyle.HeaderTemplate>
                </GroupStyle>
            </DataGrid.GroupStyle>
            <DataGrid.RowStyle>
                <Style TargetType="DataGridRow">
                    <Setter Property="Foreground" Value="Black" />
                    <Setter Property="Background" Value="White" />
                </Style>
            </DataGrid.RowStyle>
        </DataGrid>
        <StackPanel Orientation="Horizontal" Grid.Row="1">
            <TextBlock Text=" Filter completed items " VerticalAlignment="Center" />
            <CheckBox x:Name="cbCompleteFilter" VerticalAlignment="Center"
                      Checked="CompleteFilter_Changed" Unchecked="CompleteFilter_Changed" />
            <Button Content="Remove Groups" Margin="10,2,2,2" Click="UngroupButton_Click" />
            <Button Content="Group by Project/Status" Margin="2" Click="GroupButton_Click" />
        </StackPanel>
    </Grid>
</Window>
```

```csharp
using System;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Windows;
using System.Windows.Data;

namespace DGGroupSortFilterExample
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            
            // Get a reference to the tasks collection.
            Tasks _tasks = (Tasks)this.Resources["tasks"];

            // Generate some task data and add it to the task list.
            for (int i = 1; i <= 14; i++)
            {
                _tasks.Add(new Task()
                {
                    ProjectName = "Project " + ((i % 3) + 1).ToString(),
                    TaskName = "Task " + i.ToString(),
                    DueDate = DateTime.Now.AddDays(i),
                    Complete = (i % 2 == 0)
                });
            }
        }
        
        private void UngroupButton_Click(object sender, RoutedEventArgs e)
        {
            ICollectionView cvTasks = CollectionViewSource.GetDefaultView(dataGrid1.ItemsSource);
            if (cvTasks != null)
            {
                cvTasks.GroupDescriptions.Clear();
            }
        }
        
        private void GroupButton_Click(object sender, RoutedEventArgs e)
        {
            ICollectionView cvTasks = CollectionViewSource.GetDefaultView(dataGrid1.ItemsSource);
            if (cvTasks != null && cvTasks.CanGroup == true)
            {
                cvTasks.GroupDescriptions.Clear();
                cvTasks.GroupDescriptions.Add(new PropertyGroupDescription("ProjectName"));
                cvTasks.GroupDescriptions.Add(new PropertyGroupDescription("Complete"));
            }
        }
        
        private void CompleteFilter_Changed(object sender, RoutedEventArgs e)
        {
            // Refresh the view to apply filters.
            CollectionViewSource.GetDefaultView(dataGrid1.ItemsSource).Refresh();
        }

        private void CollectionViewSource_Filter(object sender, FilterEventArgs e)
        {
            Task t = e.Item as Task;
            if (t != null)
            // If filter is turned on, filter completed items.
            {
                if (this.cbCompleteFilter.IsChecked == true && t.Complete == true)
                    e.Accepted = false;
                else
                    e.Accepted = true;
            }
        }
    }

    [ValueConversion(typeof(Boolean), typeof(String))]
    public class CompleteConverter : IValueConverter
    {
        // This converter changes the value of a Tasks Complete status from true/false to a string value of
        // "Complete"/"Active" for use in the row group header.
        public object Convert(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            bool complete = (bool)value;
            if (complete)
                return "Complete";
            else
                return "Active";
        }

        public object ConvertBack(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            string strComplete = (string)value;
            if (strComplete == "Complete")
                return true;
            else
                return false;
        }
    }

    // Task Class
    // Requires using System.ComponentModel;
    public class Task : INotifyPropertyChanged, IEditableObject
    {
        // The Task class implements INotifyPropertyChanged and IEditableObject 
        // so that the datagrid can properly respond to changes to the 
        // data collection and edits made in the DataGrid.

        // Private task data.
        private string m_ProjectName = string.Empty;
        private string m_TaskName = string.Empty;
        private DateTime m_DueDate = DateTime.Now;
        private bool m_Complete = false;

        // Data for undoing canceled edits.
        private Task temp_Task = null;
        private bool m_Editing = false;

        // Public properties. 
        public string ProjectName
        {
            get { return this.m_ProjectName; }
            set
            {
                if (value != this.m_ProjectName)
                {
                    this.m_ProjectName = value;
                    NotifyPropertyChanged("ProjectName");
                }
            }
        }

        public string TaskName
        {
            get { return this.m_TaskName; }
            set
            {
                if (value != this.m_TaskName)
                {
                    this.m_TaskName = value;
                    NotifyPropertyChanged("TaskName");
                }
            }
        }

        public DateTime DueDate
        {
            get { return this.m_DueDate; }
            set
            {
                if (value != this.m_DueDate)
                {
                    this.m_DueDate = value;
                    NotifyPropertyChanged("DueDate");
                }
            }
        }

        public bool Complete
        {
            get { return this.m_Complete; }
            set
            {
                if (value != this.m_Complete)
                {
                    this.m_Complete = value;
                    NotifyPropertyChanged("Complete");
                }
            }
        }

        // Implement INotifyPropertyChanged interface.
        public event PropertyChangedEventHandler PropertyChanged;

        private void NotifyPropertyChanged(string propertyName)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
            }
        }

        // Implement IEditableObject interface.
        public void BeginEdit()
        {
            if (m_Editing == false)
            {
                temp_Task = this.MemberwiseClone() as Task;
                m_Editing = true;
            }
        }

        public void CancelEdit()
        {
            if (m_Editing == true)
            {
                this.ProjectName = temp_Task.ProjectName;
                this.TaskName = temp_Task.TaskName;
                this.DueDate = temp_Task.DueDate;
                this.Complete = temp_Task.Complete;
                m_Editing = false;
            }
        }

        public void EndEdit()
        {
            if (m_Editing == true)
            {
                temp_Task = null;
                m_Editing = false;
            }
        }
    }
    // Requires using System.Collections.ObjectModel;
    public class Tasks : ObservableCollection<Task>
    {
        // Creating the Tasks collection in this way enables data binding from XAML.
    }
}
```

### [How to: Implement Validation with the DataGrid Control](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-implement-validation-with-the-datagrid-control)

[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)控件，可以在单元格和行级别执行验证。 与单元格级别验证时用户更新的值验证绑定的数据对象的各个属性。 使用行级验证时用户将更改提交到行验证整个数据对象。 此外可以为验证错误，提供自定义可视反馈，或使用默认的可视反馈的[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)控件提供。

下面的过程介绍如何将应用到的验证规则[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)绑定和自定义可视反馈。

#### 若要验证单个单元格的值

- 指定的列使用绑定上的一个或多个验证规则。 这是类似于验证简单控件中的数据，如中所述[数据绑定概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/data/data-binding-overview)。

  下面的示例演示[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)具有四个列绑定到业务对象的不同属性的控件。 三个列指定[ExceptionValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.exceptionvalidationrule)通过设置[ValidatesOnExceptions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.binding.validatesonexceptions)属性设置为`true`。

  ```xaml
  <Grid>
  
    <Grid.Resources>
      <local:Courses x:Key="courses"/>
    </Grid.Resources>
  
    <DataGrid Name="dataGrid1" FontSize="20"
      ItemsSource="{StaticResource courses}" 
      AutoGenerateColumns="False">
      <DataGrid.Columns>
        <DataGridTextColumn Header="Course Name" 
          Binding="{Binding Name, TargetNullValue=(enter a course name)}"/>
        <DataGridTextColumn Header="Course ID"
          Binding="{Binding Id, ValidatesOnExceptions=True}"/>
        <DataGridTextColumn Header="Start Date"
          Binding="{Binding StartDate, ValidatesOnExceptions=True, 
            StringFormat=d}"/>
        <DataGridTextColumn Header="End Date"
          Binding="{Binding EndDate, ValidatesOnExceptions=True,
            StringFormat=d}"/>
      </DataGrid.Columns>
    </DataGrid>
    
  </Grid>
  ```

  当用户输入无效值 （如非整数中的课程 ID 列） 时，在单元格周围将出现一个红色边框。 您可以更改此默认验证反馈，如下面的过程中所述。

#### 若要自定义单元格验证反馈

- 设置列的[EditingElementStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridboundcolumn.editingelementstyle)属性设置为一种样式适用于列的编辑控件。 由于在运行时创建编辑控件，不能使用[Validation.ErrorTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validation.errortemplate)附加属性，就像对简单控件。

  下面的示例通过添加由验证规则的三个列共享了错误样式更新前面的示例。 当用户输入的值无效时，样式更改单元格背景色，添加工具提示。 请注意，使用的触发器，以确定是否存在验证错误。 这是必需的因为当前单元格没有专用的错误模板。

  ```xaml
  <DataGrid.Resources>
    <Style x:Key="errorStyle" TargetType="{x:Type TextBox}">
      <Setter Property="Padding" Value="-2"/>
      <Style.Triggers>
        <Trigger Property="Validation.HasError" Value="True">
          <Setter Property="Background" Value="Red"/>
          <Setter Property="ToolTip" 
            Value="{Binding RelativeSource={RelativeSource Self},
              Path=(Validation.Errors)[0].ErrorContent}"/>
        </Trigger>
      </Style.Triggers>
    </Style>
  </DataGrid.Resources>
  
  <DataGrid.Columns>
    <DataGridTextColumn Header="Course Name" 
      Binding="{Binding Name, TargetNullValue=(enter a course name)}"/>
    <DataGridTextColumn Header="Course ID"
      EditingElementStyle="{StaticResource errorStyle}"
      Binding="{Binding Id, ValidatesOnExceptions=True}"/>
    <DataGridTextColumn Header="Start Date"
      EditingElementStyle="{StaticResource errorStyle}"
      Binding="{Binding StartDate, ValidatesOnExceptions=True, 
        StringFormat=d}"/>
    <DataGridTextColumn Header="End Date"
      EditingElementStyle="{StaticResource errorStyle}"
      Binding="{Binding EndDate, ValidatesOnExceptions=True,
        StringFormat=d}"/>
  </DataGrid.Columns>
  ```

  您可以通过替换来实现更广泛的自定义[CellStyle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridcolumn.cellstyle)列使用。

#### 若要验证单个行中的多个值

1. 实现[ValidationRule](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule)检查多个属性的绑定的数据对象的子类。 在你[Validate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule.validate)方法实现转换`value`参数值到[BindingGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindinggroup)实例。 然后可以访问通过此数据对象[Items](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindinggroup.items)属性。

   下面的示例展示了此过程来验证是否`StartDate`属性值`Course`对象是早于其`EndDate`属性值。

   ```csharp
   public class CourseValidationRule : ValidationRule
   {
       public override ValidationResult Validate(object value,
           System.Globalization.CultureInfo cultureInfo)
       {
           Course course = (value as BindingGroup).Items[0] as Course;
           if (course.StartDate > course.EndDate)
           {
               return new ValidationResult(false,
                   "Start Date must be earlier than End Date.");
           }
           else
           {
               return ValidationResult.ValidResult;
           }
       }
   }
   ```

2. 添加验证规则与[DataGrid.RowValidationRules](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.rowvalidationrules)集合。 [RowValidationRules](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.rowvalidationrules)属性提供直接访问权限[ValidationRules](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindinggroup.validationrules)属性的[BindingGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.data.bindinggroup)分组控件使用的所有绑定的实例。

   下面的示例设置[RowValidationRules](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.rowvalidationrules)在 XAML 中的属性。 [ValidationStep](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationrule.validationstep)属性设置为[UpdatedValue](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.validationstep#System_Windows_Controls_ValidationStep_UpdatedValue)，以便仅在绑定的数据对象更新后进行的验证。

   ```xaml
   <DataGrid.RowValidationRules>
     <local:CourseValidationRule ValidationStep="UpdatedValue"/>
   </DataGrid.RowValidationRules>
   ```

   当用户指定结束日期早于开始日期时，行标题中会显示一个红色感叹号 （！）。 您可以更改此默认验证反馈，如下面的过程中所述。

#### 若要自定义行验证反馈

- 设置 [DataGrid.RowValidationErrorTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.rowvalidationerrortemplate) 属性。 此属性可以自定义为各个行验证反馈[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)控件。 您也可以通过使用隐式行样式设置影响多个控件[DataGridRow.ValidationErrorTemplate](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridrow.validationerrortemplate)属性。

  下面的示例使用一个更可见的指示符替换默认行验证反馈。 当用户输入的值无效时，一个带有白色感叹号红色圆圈显示在行标题中。 这是个行和单元格的验证错误。 工具提示中显示相关联的错误消息。

  ```xaml
  <DataGrid.RowValidationErrorTemplate>
    <ControlTemplate>
      <Grid Margin="0,-2,0,-2"
        ToolTip="{Binding RelativeSource={RelativeSource
        FindAncestor, AncestorType={x:Type DataGridRow}},
        Path=(Validation.Errors)[0].ErrorContent}">
        <Ellipse StrokeThickness="0" Fill="Red" 
          Width="{TemplateBinding FontSize}" 
          Height="{TemplateBinding FontSize}" />
        <TextBlock Text="!" FontSize="{TemplateBinding FontSize}" 
          FontWeight="Bold" Foreground="White" 
          HorizontalAlignment="Center"  />
      </Grid>
    </ControlTemplate>
  </DataGrid.RowValidationErrorTemplate>
  ```

#### 示例

> 下面的示例提供了单元格和行验证的完整演示。 `Course`类提供了实现的示例数据对象[IEditableObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.ieditableobject)以支持事务。 [DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)控件与交互[IEditableObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.componentmodel.ieditableobject)以使用户能够通过按 esc 键还原更改。

如果使用的 Visual Basic 中，在 MainWindow.xaml 的第一行中，替换`x:Class="DataGridValidation.MainWindow"`与`x:Class="MainWindow"`。

若要测试验证，请尝试以下操作：

- 在课程 ID 列中，输入一个非整数值。
- 在结束日期列中，输入日期早于开始日期。
- 删除课程 ID、 开始日期或结束日期中的值。
- 若要撤消了无效的单元值，请将光标放回该单元格，然后按 ESC 键。
- 若要撤消整个行的更改，当前单元格处于编辑模式时，请按 ESC 键两次。
- 出现验证错误时，将鼠标指针移动行标题以查看相关联的错误消息中的指示符。

```csharp
using System;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;

namespace DataGridValidation
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            dataGrid1.InitializingNewItem += (sender, e) =>
            {
                Course newCourse = e.NewItem as Course;
                newCourse.StartDate = newCourse.EndDate = DateTime.Today;
            };
        }
    }

    public class Courses : ObservableCollection<Course>
    {
        public Courses()
        {
            this.Add(new Course
            {
                Name = "Learning WPF",
                Id = 1001,
                StartDate = new DateTime(2010, 1, 11),
                EndDate = new DateTime(2010, 1, 22)
            });
            this.Add(new Course
            {
                Name = "Learning Silverlight",
                Id = 1002,
                StartDate = new DateTime(2010, 1, 25),
                EndDate = new DateTime(2010, 2, 5)
            });
            this.Add(new Course
            {
                Name = "Learning Expression Blend",
                Id = 1003,
                StartDate = new DateTime(2010, 2, 8),
                EndDate = new DateTime(2010, 2, 19)
            });
            this.Add(new Course
            {
                Name = "Learning LINQ",
                Id = 1004,
                StartDate = new DateTime(2010, 2, 22),
                EndDate = new DateTime(2010, 3, 5)
            });
        }
    }

    public class Course : IEditableObject, INotifyPropertyChanged
    {
        private string _name;
        public string Name
        {
            get
            {
                return _name;
            }
            set
            {
                if (_name == value) return;
                _name = value;
                OnPropertyChanged("Name");
            }
        }

        private int _number;
        public int Id
        {
            get
            {
                return _number;
            }
            set
            {
                if (_number == value) return;
                _number = value;
                OnPropertyChanged("Id");
            }
        }

        private DateTime _startDate;
        public DateTime StartDate
        {
            get
            {
                return _startDate;
            }
            set
            {
                if (_startDate == value) return;
                _startDate = value;
                OnPropertyChanged("StartDate");
            }
        }

        private DateTime _endDate;
        public DateTime EndDate
        {
            get
            {
                return _endDate;
            }
            set
            {
                if (_endDate == value) return;
                _endDate = value;
                OnPropertyChanged("EndDate");
            }
        }

        #region IEditableObject

        private Course backupCopy;
        private bool inEdit;

        public void BeginEdit()
        {
            if (inEdit) return;
            inEdit = true;
            backupCopy = this.MemberwiseClone() as Course;
        }

        public void CancelEdit()
        {
            if (!inEdit) return;
            inEdit = false;
            this.Name = backupCopy.Name;
            this.Id = backupCopy.Id;
            this.StartDate = backupCopy.StartDate;
            this.EndDate = backupCopy.EndDate;
        }

        public void EndEdit()
        {
            if (!inEdit) return;
            inEdit = false;
            backupCopy = null;
        }

        #endregion

        #region INotifyPropertyChanged

        public event PropertyChangedEventHandler PropertyChanged;

        private void OnPropertyChanged(string propertyName)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this,
                    new PropertyChangedEventArgs(propertyName));
            }
        }

        #endregion

    }

    public class CourseValidationRule : ValidationRule
    {
        public override ValidationResult Validate(object value,
            System.Globalization.CultureInfo cultureInfo)
        {
            Course course = (value as BindingGroup).Items[0] as Course;
            if (course.StartDate > course.EndDate)
            {
                return new ValidationResult(false,
                    "Start Date must be earlier than End Date.");
            }
            else
            {
                return ValidationResult.ValidResult;
            }
        }
    }

}
```

```xaml
<Window x:Class="DataGridValidation.MainWindow"
  xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  xmlns:local="clr-namespace:DataGridValidation"
  Title="DataGrid Validation Example" Height="240" Width="600">

  <Grid>

    <Grid.Resources>
      <local:Courses x:Key="courses"/>
    </Grid.Resources>

    <DataGrid Name="dataGrid1" FontSize="20" RowHeaderWidth="27"
      ItemsSource="{StaticResource courses}" 
      AutoGenerateColumns="False">

      <DataGrid.Resources>
        <Style x:Key="errorStyle" TargetType="{x:Type TextBox}">
          <Setter Property="Padding" Value="-2"/>
          <Style.Triggers>
            <Trigger Property="Validation.HasError" Value="True">
              <Setter Property="Background" Value="Red"/>
              <Setter Property="ToolTip" 
                Value="{Binding RelativeSource={RelativeSource Self},
                  Path=(Validation.Errors)[0].ErrorContent}"/>
            </Trigger>
          </Style.Triggers>
        </Style>
      </DataGrid.Resources>

      <DataGrid.Columns>
        <DataGridTextColumn Header="Course Name" 
          Binding="{Binding Name, TargetNullValue=(enter a course name)}"/>
        <DataGridTextColumn Header="Course ID"
          EditingElementStyle="{StaticResource errorStyle}"
          Binding="{Binding Id, ValidatesOnExceptions=True}"/>
        <DataGridTextColumn Header="Start Date"
          EditingElementStyle="{StaticResource errorStyle}"
          Binding="{Binding StartDate, ValidatesOnExceptions=True, 
            StringFormat=d}"/>
        <DataGridTextColumn Header="End Date"
          EditingElementStyle="{StaticResource errorStyle}"
          Binding="{Binding EndDate, ValidatesOnExceptions=True,
            StringFormat=d}"/>
      </DataGrid.Columns>

      <DataGrid.RowValidationRules>
        <local:CourseValidationRule ValidationStep="UpdatedValue"/>
      </DataGrid.RowValidationRules>

      <DataGrid.RowValidationErrorTemplate>
        <ControlTemplate>
          <Grid Margin="0,-2,0,-2"
            ToolTip="{Binding RelativeSource={RelativeSource
            FindAncestor, AncestorType={x:Type DataGridRow}},
            Path=(Validation.Errors)[0].ErrorContent}">
            <Ellipse StrokeThickness="0" Fill="Red" 
              Width="{TemplateBinding FontSize}" 
              Height="{TemplateBinding FontSize}" />
            <TextBlock Text="!" FontSize="{TemplateBinding FontSize}" 
              FontWeight="Bold" Foreground="White" 
              HorizontalAlignment="Center"  />
          </Grid>
        </ControlTemplate>
      </DataGrid.RowValidationErrorTemplate>

    </DataGrid>

  </Grid>
</Window>
```

### [Walkthrough: Display Data from a SQL Server Database in a DataGrid Control](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/walkthrough-display-data-from-a-sql-server-database-in-a-datagrid-control)

在本演练中，将从 SQL Server 数据库中检索数据和显示中的这些数据[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)控件。 ADO.NET 实体框架用于创建表示数据，并使用 LINQ 编写从实体类检索指定的数据的查询的实体类。

#### 系统必备

你需要以下组件来完成本演练：

- Visual Studio。
- 正在运行的 SQL Server 或 SQL Server Express 的 AdventureWorks 示例数据库附加到该实例的访问权限。 您可以下载 AdventureWorks 数据库从[GitHub](https://github.com/Microsoft/sql-server-samples/releases)。

#### 创建实体类

1. 在 Visual Basic 或 C# 中，创建一个新的 WPF 应用程序项目并将其命名`DataGridSQLExample`。

2. 在解决方案资源管理器中右键单击你的项目，指向**外**，然后选择**新项**。

   添加新项对话框。

3. 在已安装的模板窗格中，选择**数据**，然后在模板列表中，选择**ADO.NET 实体数据模型**。

   ![ADO.NET 实体数据模型项模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wcf/feature-details/media/ado-net-entity-data-model-item-template.png)

4. 将文件命名`AdventureWorksModel.edmx`，然后单击**添加**。

   此时将显示实体数据模型向导。

5. 在选择模型内容屏幕中，选择**EF 设计器从数据库**，然后单击**下一步**。

6. 在选择数据连接屏幕中，提供 AdventureWorksLT2008 数据库的连接。 有关详细信息，请参阅[选择数据连接对话框中](https://go.microsoft.com/fwlink/?LinkId=160190)。

   请确保名称是`AdventureWorksLT2008Entities`并且**将实体连接设置保存在 App.Config 作为**复选框已选中，然后依次**下一步**。

7. 在选择数据库对象屏幕中，展开表节点，并选择**产品**并**ProductCategory**表。

   您可以为生成实体类的所有表;但是，在此示例中您只能从检索数据这两个表。

   ![从表中选择 Product 和 ProductCategory](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/datagrid-sql-ef-step4.png)

8. 单击 **“完成”**。

   在实体设计器中显示 Product 和 ProductCategory 实体。

   ![Product 和 ProductCategory 实体模型](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/datagrid-sql-ef-step5.png)

#### 检索和呈现数据

1. 打开 MainWindow.xaml 文件。

2. 设置[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)属性上的[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)到 450。

3. 在 XAML 编辑器中，添加以下[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)标记之间`<Grid>`并`</Grid>`要添加的标记[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)名为`dataGrid1`。

   ```xaml
   <DataGrid Name="dataGrid1" />
   ```

   ![含 DataGrid 的窗口](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/datagrid-sql-ef-step6.png)

4. 选择 [Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)。

5. 使用属性窗口或 XAML 编辑器中，创建的事件处理程序[Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)名为`Window_Loaded`为[Loaded](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.loaded)事件。 有关详细信息，请参阅[如何： 创建简单的事件处理程序](https://msdn.microsoft.com/library/b1456e07-9dec-4354-99cf-18666b64f480)。

   下图显示 XAML mainwindow.xaml。

   > 如果使用的 Visual Basic 中，在 MainWindow.xaml 的第一行中，替换`x:Class="DataGridSQLExample.MainWindow"`与`x:Class="MainWindow"`。

   ```xaml
   <Window x:Class="DataGridSQLExample.MainWindow"
           xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
           xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
           Title="MainWindow" Height="350" Width="450" 
           Loaded="Window_Loaded">
       <Grid>
           <DataGrid Name="dataGrid1" />
       </Grid>
   </Window>
   ```

6. 打开代码隐藏文件 （MainWindow.xaml.vb 或 MainWindow.xaml.cs） [Window](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.window)。

7. 添加以下代码来联接表中检索特定的值并设置[ItemsSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemscontrol.itemssource)属性的[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)到查询的结果。

   ```csharp
   using System.Data.Objects;
   using System.Linq;
   using System.Windows;
   
   namespace DataGridSQLExample
   {
       /// <summary>
       /// Interaction logic for MainWindow.xaml
       /// </summary>
       public partial class MainWindow : Window
       {
           AdventureWorksLT2008Entities dataEntities = new AdventureWorksLT2008Entities();
   
           public MainWindow()
           {
               InitializeComponent();
           }
   
           private void Window_Loaded(object sender, RoutedEventArgs e)
           {
               ObjectQuery<Product> products = dataEntities.Products;
   
               var query =
               from product in products
               where product.Color == "Red"
               orderby product.ListPrice
               select new { product.Name, product.Color, CategoryName = product.ProductCategory.Name, product.ListPrice };
   
               dataGrid1.ItemsSource = query.ToList();
           }
       }
   }
   ```

8. 运行示例。

   应会看到[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)显示数据。

   ![SQL 数据库中的数据的 DataGrid](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/datagrid-sql-ef-step7.png)

### [Sizing Options in the DataGrid Control](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/sizing-options-in-the-datagrid-control)

各种选项来控制如何[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)调整自身大小。 [DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)，以及各个行和列中的[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)，可以设置为其内容自动调整大小，也可以设置为特定值。 默认情况下，[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)将放大或缩小以适合其内容的大小。

#### 大小调整数据网格

##### 使用自动大小调整时的注意事项

默认情况下[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)并[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)的属性[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)设置为[Double.NaN](https://docs.microsoft.com/zh-cn/dotnet/api/system.double.nan)("`Auto`"在 XAML 中)，和[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)将调整其内容的大小。

当放置在不限制及其子项的大小，如容器内[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)或[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)，则[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)将拉伸到容器的可见的边框之外并且不会显示滚动条。 这种情况会影响可用性和性能。

当绑定到数据集，如果[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)的[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)是不受限制，它将继续添加绑定数据集中的每个数据项的行。 这可能会导致[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)添加行时增加到超过您的应用程序的可见边界。 [DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)将不显示滚动条在这种情况下由于其[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)将继续增大以容纳新行。

中的每一行创建一个对象[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)。 如果你正在使用的大型数据集并且您允许[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)自动调整自身大小，请创建大量对象可能会影响应用程序的性能。

若要避免这些问题，在处理大型数据集时，建议您专门设置[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)的[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)或将其放在一个容器，它将限制其[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)，如[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)。 当[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)受到限制，[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)才会创建将适合其指定的行[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)，并根据需要以显示新数据将回收这些行。

##### 数据网格大小设置

[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)可以设置为自动指定边界内的大小或[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)可以设置为特定大小。 下表显示了可以设置到控件的属性的[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)大小。

| 属性                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height) | 设置为特定高度[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)。 |
| [MaxHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.maxheight) | 设置高度的上限[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)。 [DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)将沿垂直方向增长，直到它达到此高度。 |
| [MinHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.minheight) | 设置高度的下限[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)。 [DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)将垂直收缩，直到其达到此高度。 |
| [Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width) | 设置为特定宽度[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)。 |
| [MaxWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.maxwidth) | 设置的宽度上限[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)。 [DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)将水平增长，直到它达到此宽度。 |
| [MinWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.minwidth) | 设置的宽度下限[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)。 [DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)会水平缩小，直到它达到此宽度。 |

#### 调整行和行标题

##### DataGrid Rows

默认情况下[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)行的[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)属性设置为[Double.NaN](https://docs.microsoft.com/zh-cn/dotnet/api/system.double.nan)("`Auto`"在 XAML 中)，和行的高度将扩展到其内容的大小。 中的所有行的高度[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)可以通过设置指定[DataGrid.RowHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.rowheight)属性。 用户可以通过拖动行标题分隔符更改行的高度。

##### DataGrid 行标题

若要显示行标题[HeadersVisibility](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.headersvisibility)属性必须设置为[DataGridHeadersVisibility.Row](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridheadersvisibility#System_Windows_Controls_DataGridHeadersVisibility_Row)或[DataGridHeadersVisibility.All](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridheadersvisibility#System_Windows_Controls_DataGridHeadersVisibility_All)。默认情况下，显示行标题和自动调整大小以适合其内容。 行标题可以通过设置给定特定宽度[DataGrid.RowHeaderWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.rowheaderwidth)属性。

#### 大小调整列标题和列标题

##### DataGrid 列

[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)使用的值[DataGridLength](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridlength)和[DataGridLengthUnitType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridlengthunittype)结构，以指定绝对或自动大小调整模式。

下表显示了由提供的值[DataGridLengthUnitType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridlengthunittype)结构。

| name                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [Auto](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridlengthunittype#System_Windows_Controls_DataGridLengthUnitType_Auto) | 默认自动调整大小模式大小[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)列基于单元格和列标题的内容。 |
| [SizeToCells](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridlengthunittype#System_Windows_Controls_DataGridLengthUnitType_SizeToCells) | 基于单元格的自动调整大小模式大小[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)列基于的列，不包括列标题中的单元格的内容。 |
| [SizeToHeader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridlengthunittype#System_Windows_Controls_DataGridLengthUnitType_SizeToHeader) | 基于标头的自动调整大小模式大小[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)列基于列标头的内容。 |
| [Pixel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridlengthunittype#System_Windows_Controls_DataGridLengthUnitType_Pixel) | 基于像素的大小调整模式大小[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)列基于提供的数字值。 |
| [Star](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridlengthunittype#System_Windows_Controls_DataGridLengthUnitType_Star) | 星形调整大小模式用于根据加权比例分配可用空间。  在 XAML 中，星号值表示为 n * 其中 n 表示的数字值。 1*等效于*。 例如，如果两个中的列[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)具有的宽度*和 2 个*、 第一列将会收到的可用空间的一部分和第二列将会收到的可用空间的两个部分。 |

[DataGridLengthConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridlengthconverter)类可用于数字或字符串值之间转换数据和[DataGridLength](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridlength)值。

默认情况下[DataGrid.ColumnWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.columnwidth)属性设置为[SizeToHeader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridlength.sizetoheader)，并[DataGridColumn.Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridcolumn.width)属性设置为[Auto](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridlength.auto)。 如果调整大小模式设置为[Auto](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridlength.auto)或[SizeToCells](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridlength.sizetocells)，列会增长到其尽可能广泛的可见内容的宽度。 当滚动时，这些调整大小模式的将导致列进行扩展内容大于当前的列大小滚动到视图。 列不会收缩后的内容滚动到视图之外。

中的列[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)还可以设置为自动仅在指定边界内的大小或列可设置为特定大小。 下表显示可以用来控制列的大小的属性。

| 属性                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [DataGrid.MaxColumnWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.maxcolumnwidth) | 设置中的所有列的上限[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)。 |
| [DataGridColumn.MaxWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridcolumn.maxwidth) | 设置的单个列的上限。 重写 [DataGrid.MaxColumnWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.maxcolumnwidth)。 |
| [DataGrid.MinColumnWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.mincolumnwidth) | 设置中的所有列的下限[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)。 |
| [DataGridColumn.MinWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridcolumn.minwidth) | 设置的单个列的下限。 重写 [DataGrid.MinColumnWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.mincolumnwidth)。 |
| [DataGrid.ColumnWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.columnwidth) | 设置中的所有列的特定宽度[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)。 |
| [DataGridColumn.Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridcolumn.width) | 设置特定的单个列宽度。 重写 [DataGrid.ColumnWidth](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.columnwidth)。 |

##### DataGrid 列标题

默认情况下，[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)显示列标题。 若要隐藏列标题[HeadersVisibility](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.headersvisibility)属性必须设置为[DataGridHeadersVisibility.Row](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridheadersvisibility#System_Windows_Controls_DataGridHeadersVisibility_Row)或[DataGridHeadersVisibility.None](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridheadersvisibility#System_Windows_Controls_DataGridHeadersVisibility_None)。 默认情况下，当显示列标题时，自动调整大小以适合其内容。 列标题可以通过设置指定特定高度[DataGrid.ColumnHeaderHeight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.columnheaderheight)属性。

##### 使用鼠标调整大小

用户可以调整大小[DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)行和列通过拖动行或列标题分隔符。 [DataGrid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid)还支持自动调整大小的行和列通过双击行或列标题分隔符。 若要防止用户调整特定列的大小，设置[DataGridColumn.CanUserResize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagridcolumn.canuserresize)属性设置为`false`为各个列。 若要阻止用户调整所有列，设置[DataGrid.CanUserResizeColumns](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.canuserresizecolumns)属性设置为`false`。 若要阻止用户调整所有行，将设置[DataGrid.CanUserResizeRows](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.datagrid.canuserresizerows)属性设置为`false`。