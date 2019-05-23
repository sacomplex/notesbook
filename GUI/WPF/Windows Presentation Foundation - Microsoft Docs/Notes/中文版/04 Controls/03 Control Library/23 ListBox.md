## [ListBox](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/listbox)

A[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)控件提供用户提供的可选择项的列表。

下图说明了典型[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)。

![ListBox 屏幕快照](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/ss-ctl-listbox.gif)
典型的 ListBox

### 本节内容

[帮助主题](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/listbox-how-to-topics)

### [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/listbox-how-to-topics)

在本部分中的主题介绍如何使用[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)控件来显示可选择的项的列表。

#### 本节内容

[将 ListBox 绑定到数据](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-bind-a-listbox-to-data)
[获取 ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-get-a-listboxitem)
[如何： 将数据添加到 ItemsControl](https://msdn.microsoft.com/library/271e52ce-0f44-4b1f-a7da-0bc72bd9ed65)
[提升 ListBox 的滚动性能](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-improve-the-scrolling-performance-of-a-listbox)

#### [Bind a ListBox to Data](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-bind-a-listbox-to-data)

应用程序开发人员可以创建[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)而无需指定的每个内容控件[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)单独。 数据绑定可用于将数据绑定到的各个项。

下面的示例演示如何创建[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)填充[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)通过数据绑定到的数据源的元素*颜色*。 在这种情况下不需要使用[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)标记，以指定每个项的内容。

##### 示例

```xaml
<Canvas.Resources>
  <src:myColors x:Key="Colors"/>
</Canvas.Resources>
```

```xaml
<ListBox Name="myListBox" HorizontalAlignment="Left" SelectionMode="Extended" 
      Width="265" Height="55" Background="HoneyDew" SelectionChanged="myListBox_SelectionChanged"
      ItemsSource="{Binding Source={StaticResource Colors}}" IsSynchronizedWithCurrentItem="true">
</ListBox>
```

#### [Get a ListBoxItem](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-get-a-listboxitem)

如果您需要先获取特定[ListBoxItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listboxitem)中的特定索引处[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)，你可以使用[ItemContainerGenerator](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemcontainergenerator)。

##### 示例

下面的示例演示[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)及其项。

```xaml
<ListBox Margin="10,0,0,5" Name="lb" VerticalAlignment="Top" Grid.Column="0" Grid.Row="2">
    <ListBoxItem>Item 0</ListBoxItem>
    <ListBoxItem>Item 1</ListBoxItem>
    <ListBoxItem>Item 2</ListBoxItem>
    <ListBoxItem>Item 3</ListBoxItem>
</ListBox>
```

下面的示例演示如何通过指定中的项的索引中检索项[ContainerFromIndex](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemcontainergenerator.containerfromindex)属性[ItemContainerGenerator](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.itemcontainergenerator)。

```csharp
private void GetIndex0(object sender, RoutedEventArgs e)
{
  ListBoxItem lbi = (ListBoxItem)
      (lb.ItemContainerGenerator.ContainerFromIndex(0));
  Item.Content = "The contents of the item at index 0 are: " +
      (lbi.Content.ToString()) + ".";
}
```

在检索列表框项后，可以显示的项的内容，如下面的示例中所示。

```csharp
Item.Content = "The contents of the item at index 0 are: " +
    (lbi.Content.ToString()) + ".";
```

#### [Improve the Scrolling Performance of a ListBox](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-improve-the-scrolling-performance-of-a-listbox)

如果[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)包含多个项，用户界面响应可能会很慢，当用户滚动[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)通过使用鼠标滚轮或拖动滚动条上的滚动块。 你可以提高的性能[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)通过设置在用户滚动时`VirtualizingStackPanel.VirtualizationMode`附加到属性[VirtualizationMode.Recycling](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizationmode#System_Windows_Controls_VirtualizationMode_Recycling)。

##### 示例

下面的示例创建[ListBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.listbox)和设置`VirtualizingStackPanel.VirtualizationMode`附加到属性[VirtualizationMode.Recycling](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.virtualizationmode#System_Windows_Controls_VirtualizationMode_Recycling)若要在滚动期间提高性能。

```xaml
<StackPanel>

  <StackPanel.Resources>
    <src:LotsOfItems x:Key="data"/>
  </StackPanel.Resources>

  <ListBox Height="150" ItemsSource="{StaticResource data}" 
             VirtualizingStackPanel.VirtualizationMode="Recycling" />

</StackPanel>
```

下面的示例显示了数据，使用前面的示例。

```csharp
public class LotsOfItems : ObservableCollection<String>
{
    public LotsOfItems()
    {
        for (int i = 0; i < 1000; ++i)
        {
            Add("item " + i.ToString());
        }
    }
}
```