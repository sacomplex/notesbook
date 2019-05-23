## [Label](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/label)

[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label) 控件通常会提供中的信息用户界面 (UI)。 从历史上看，[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)具有包含纯文本，但由于[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)随Windows Presentation Foundation (WPF)是[ContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentcontrol)，它可以包含文本或[UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement)。

一个[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)提供访问密钥的功能和视觉支持。 它通常用于启用对控件的快速键盘访问，例如[TextBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textbox)。 若要将分配[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)到[Control](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control)，将[Label.Target](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label.target)属性设置为在用户按访问密钥时，应获得焦点的控件。

下图显示[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)"主题"面向[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)。 当用户按下时，[ComboBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.combobox)接收焦点。 有关详细信息，请参阅[如何： 将标签的目标属性设置](https://msdn.microsoft.com/library/b24c6977-ebcb-4855-a9bb-3fd4435af8f8)。

![显示属性显示按用法标记](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/labeledby.jpg)

### 本节内容

[如何：设置 Label 的目标属性](https://msdn.microsoft.com/library/b24c6977-ebcb-4855-a9bb-3fd4435af8f8)

### [Create a Control That Has an Access Key and Text Wrapping](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-create-a-control-that-has-an-access-key-and-text-wrapping)

此示例演示如何创建具有访问键且支持文本换行的控件。 该示例使用[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)控件来说明这些概念。

##### 示例

**将文本换行添加到标签**

[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)控件不支持文本换行。 如果需要一个多次换行的标签，可以嵌套其他支持文本换行的元素，并将该元素放在标签内。 下面的示例演示如何使用[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)进行包装若干行文本的标签。

```xaml
<Label Width="200" HorizontalAlignment="Left">
  <TextBlock TextWrapping="WrapWithOverflow">
    A long piece of text that requires text wrapping
    goes here.
  </TextBlock>
</Label>
```

**将访问键和文本换行添加到标签**

如果你需要[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)具有访问键 （助记键），请使用[AccessText](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.accesstext)内元素[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)。

控件，如[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)， [Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)， [RadioButton](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.radiobutton)， [CheckBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.checkbox)， [MenuItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.menuitem)， [TabItem](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tabitem)， [Expander](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.expander)，和[GroupBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.groupbox)具有默认控件模板。 这些模板包含[ContentPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter)。 您可以设置的属性之一[ContentPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter)是[RecognizesAccessKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter.recognizesaccesskey)="true"，这可用于指定控件的访问密钥。

下面的示例演示如何创建[Label](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.label)的具有访问键且支持文本换行。 若要启用文本换行，该示例设置[TextWrapping](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.accesstext.textwrapping)属性，并使用下划线字符指定访问密钥。 （紧跟下划线字符后面的字符就是访问键。）

```xaml
<TextBox Name="textBox1" Width="50" Height="20"/>
<Label Width="200" HorizontalAlignment="Left"
       Target="{Binding ElementName=textBox1}">
  <AccessText TextWrapping="WrapWithOverflow">
    _Another long piece of text that requires text wrapping
    goes here.
  </AccessText>
</Label>
```