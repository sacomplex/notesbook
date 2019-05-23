## [GridSplitter](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/gridsplitter)

[GridSplitter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridsplitter)的行或列之间重新分配空间[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)控件。

### 本节内容

[帮助主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/gridsplitter-how-to-topics)

### [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/gridsplitter-how-to-topics)

本部分中的主题介绍如何使用[GridSplitter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridsplitter)控件。

#### 本节内容

[使用 GridSplitter 重设行大小](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-resize-rows-with-a-gridsplitter)
[使用 GridSplitter 重设列大小](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-resize-columns-with-a-gridsplitter)
[确保 GridSplitter 可见](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-make-sure-that-a-gridsplitter-is-visible)

#### [Resize Rows with a GridSplitter](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-resize-rows-with-a-gridsplitter)

此示例演示如何使用水平[GridSplitter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridsplitter)若要重新分发中的两个行之间的间距[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)而无需更改的维度[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)。

##### 示例

**如何创建覆盖行边缘的 GridSplitter**

若要指定[GridSplitter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridsplitter)相邻行中的大小进行调整[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)，将[Row](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid.row)附加属性设置为要重设大小的行之一。 如果你[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)具有多个列，设置[ColumnSpan](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid.columnspan)附加属性指定的列数。 然后设置[VerticalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.verticalalignment)到[Top](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.verticalalignment#System_Windows_VerticalAlignment_Top)或[Bottom](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.verticalalignment#System_Windows_VerticalAlignment_Bottom)（设置的对齐方式取决于你想要调整大小的两个行）。 最后，设置[HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.horizontalalignment)属性设置为[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.horizontalalignment#System_Windows_HorizontalAlignment_Stretch)。

下面的示例演示如何定义水平[GridSplitter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridsplitter)相邻的行的大小进行调整。

```xaml
<GridSplitter Grid.Row="1" 
              Grid.ColumnSpan="3" 
              HorizontalAlignment="Stretch" 
              VerticalAlignment="Top"
              Background="Black" 
              ShowsPreview="true"
              ResizeDirection="Rows"
              Height="5"/>
```

一个[GridSplitter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridsplitter)未占据其自己的行可能会被中的其他控件遮盖[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)。 有关如何避免此问题的详细信息，请参阅[确保 GridSplitter 可见](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-make-sure-that-a-gridsplitter-is-visible)。

**如何创建占据一行的 GridSplitter**

若要指定[GridSplitter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridsplitter)占据一行[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)，将[Row](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid.row)附加属性设置为要重设大小的行之一。 如果你[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)具有多个列，设置[ColumnSpan](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid.columnspan)附加属性设置为的列数。 然后设置[VerticalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.verticalalignment)到[Center](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.verticalalignment#System_Windows_VerticalAlignment_Center)，请设置[HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.horizontalalignment)属性设置为[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.horizontalalignment#System_Windows_HorizontalAlignment_Stretch)，并设置[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.rowdefinition.height)包含的行的[GridSplitter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridsplitter)到[Auto](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.gridlength.auto)。

下面的示例演示如何定义水平[GridSplitter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridsplitter)的占据一行并调整其大小的任意一侧的行。

```xaml
<Grid.RowDefinitions>
  <RowDefinition Height="50*" />
  <RowDefinition Height="Auto" />
  <RowDefinition Height="50*" />
</Grid.RowDefinitions>
```

```xaml
<StackPanel Grid.Row="0" Grid.Column="1" Background="Tan"/>
<GridSplitter Grid.Row="1"
              HorizontalAlignment="Stretch"
              VerticalAlignment="Center"
              Background="Black" 
              ShowsPreview="True"
              Height="5"
           />
<StackPanel Grid.Row="2" Grid.Column="0" Background="Brown"/>
```

#### [Resize Columns with a GridSplitter](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-resize-columns-with-a-gridsplitter)

此示例演示如何创建垂直[GridSplitter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridsplitter)若要重新分发中的两个列之间的间距[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)而无需更改的维度[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)。

##### 示例

**如何创建覆盖列边缘的 GridSplitter**

若要指定[GridSplitter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridsplitter)中的相邻列的大小进行调整[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)，将[Column](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid.column)附加属性设置为要重设大小的列之一。 如果你[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)具有多个行，设置[RowSpan](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid.rowspan)附加属性设置为行数。 然后设置[HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.horizontalalignment)属性设置为[Left](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.horizontalalignment#System_Windows_HorizontalAlignment_Left)或[Right](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.horizontalalignment#System_Windows_HorizontalAlignment_Right)（设置的对齐方式取决于你想要调整大小的两个列）。 最后，设置[VerticalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.verticalalignment)属性设置为[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.verticalalignment#System_Windows_VerticalAlignment_Stretch)。

```xaml
<GridSplitter Grid.Column="1" 
              Grid.RowSpan="3" 
              HorizontalAlignment="Left" 
              VerticalAlignment="Stretch"
              Background="Black" 
              ShowsPreview="true"
              Width="5"/>
```

一个[GridSplitter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridsplitter)不具有其各自的列中的其他控件可能会被遮盖[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)。 有关如何避免此问题的详细信息，请参阅[确保 GridSplitter 可见](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-make-sure-that-a-gridsplitter-is-visible)。

**如何创建占据一列的 GridSplitter**

若要指定[GridSplitter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridsplitter)占据一列中的[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)，将[Column](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid.column)附加属性设置为要重设大小的列之一。 如果您的网格包含多个行，请设置[RowSpan](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid.rowspan)附加属性设置为行数。 然后设置[HorizontalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.horizontalalignment)到[Center](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.horizontalalignment#System_Windows_HorizontalAlignment_Center)，请设置[VerticalAlignment](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.verticalalignment)属性设置为[Stretch](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.verticalalignment#System_Windows_VerticalAlignment_Stretch)，并设置[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.columndefinition.width)包含的列的[GridSplitter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridsplitter)到[Auto](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.gridlength.auto)。

下面的示例演示如何定义垂直[GridSplitter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridsplitter)的占据一列和调整任意一侧列的大小。

```xaml
<Grid.ColumnDefinitions>
  <ColumnDefinition/>
  <ColumnDefinition Width="Auto" />
  <ColumnDefinition/>
</Grid.ColumnDefinitions>
```

```xaml
<GridSplitter Grid.Column="1"
              HorizontalAlignment="Center"
              VerticalAlignment="Stretch"
              Background="Black" 
              ShowsPreview="True"
              Width="5"
              />
```

#### [Make Sure That a GridSplitter Is Visible](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-make-sure-that-a-gridsplitter-is-visible)

此示例演示如何以确保[GridSplitter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridsplitter)中的其他控件不隐藏控件[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)。

##### 示例

[Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.children)的[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)标记或代码中定义的顺序呈现控件。 [GridSplitter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridsplitter) 其他控件可以隐藏控件，如果您没有定义它们中的最后一个元素作为[Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.children)集合，或者如果您提供其他控制更高[ZIndexProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.zindexproperty)。

若要防止隐藏[GridSplitter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridsplitter)控件，执行下列操作之一。

- 请确保[GridSplitter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridsplitter)控件是最后[Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.children)添加到[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)。 下面的示例演示[GridSplitter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridsplitter)中的最后一个元素[Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.children)的集合[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)。

```xaml
<Grid>
  <Grid.ColumnDefinitions>
    <ColumnDefinition/>
    <ColumnDefinition/>
  </Grid.ColumnDefinitions>
  <Button Grid.Column="0"/>
  <GridSplitter Grid.Column ="0" Background="Blue"/>
</Grid>
```

- 设置[ZIndexProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.zindexproperty)上[GridSplitter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridsplitter)大于一个控件，否则将其隐藏。 下面的示例会[GridSplitter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridsplitter)控制更高[ZIndexProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.panel.zindexproperty)比[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)控件。

```xaml
<Grid>
  <Grid.ColumnDefinitions>
    <ColumnDefinition/>
    <ColumnDefinition/>
  </Grid.ColumnDefinitions>
  <GridSplitter Grid.Column="0" Background="Blue"
                Panel.ZIndex="1"/>
  <Button Grid.Column="0"/>
</Grid>
```

- 否则会隐藏在控件上设置边距[GridSplitter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridsplitter)，以便[GridSplitter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridsplitter)得以实现。 下面的示例设置上一个控件，否则会覆盖和隐藏边距[GridSplitter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.gridsplitter)。

```xaml
<Grid>
  <Grid.ColumnDefinitions>
    <ColumnDefinition/>
    <ColumnDefinition/>
  </Grid.ColumnDefinitions>
  <GridSplitter Grid.Column ="0" Background="Blue"/>
  <Button Grid.Column="0" Margin="0,0,5,0"/>
</Grid>
```