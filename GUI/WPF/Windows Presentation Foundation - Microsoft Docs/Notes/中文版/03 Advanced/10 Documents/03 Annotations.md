# [Annotations](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/annotations)

Windows Presentation Foundation (WPF) 提供的文档查看支持批注文档内容的控件。

[批注概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/annotations-overview)
[注释架构](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/annotations-schema)

## [Annotations Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/annotations-overview)

在纸质文档上编写说明或注释毫不稀奇，我们几乎认为这是理所当然的。 这些说明或注释就是“批注”，我们将其添加到文档，用于标注信息或突出显示兴趣项以供日后参考。 虽然在打印文档上编写注释很简单也很平常，但是就算在所有电子文档上添加个人注释，功能上却通常有很多限制。

本主题介绍几个常见类型的批注，特别是粘滞便笺和突出显示，并说明了如何将Microsoft Annotations Framework简化这些类型的应用程序可以通过 Windows Presentation Foundation (WPF) 文档中的批注查看控件。WPF 支持批注的文档查看控件包括[FlowDocumentReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentreader)并[FlowDocumentScrollViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentscrollviewer)，以及控件派生自[DocumentViewerBase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.documentviewerbase)如[DocumentViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.documentviewer)和[FlowDocumentPageViewer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.flowdocumentpageviewer)。

### 便笺

平常的便笺是将信息写在小块彩纸上，随后将这张彩纸“粘贴”到文档。 数字便笺为电子文档提供类似的功能，但灵活性更高，可包括许多其他类型的内容，如键入文本、手写注释（如 Tablet PC“墨迹”笔划）或 Web 链接。

下图显示了突出显示、文本便笺以及墨迹便笺批注的一些示例。

![突出显示、文本和墨迹便笺批注。](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/caf-stickynote.jpg)

下面的示例演示了可用于在应用程序中启用批注支持的方法。

```csharp
// ------------------------ StartAnnotations --------------------------
/// <summary>
///   Enables annotations and displays all that are viewable.</summary>
private void StartAnnotations()
{
    // If there is no AnnotationService yet, create one.
    if (_annotService == null)
        // docViewer is a document viewing control named in Window1.xaml.
        _annotService = new AnnotationService(docViewer);

    // If the AnnotationService is currently enabled, disable it.
    if (_annotService.IsEnabled == true)
        _annotService.Disable();

    // Open a stream to the file for storing annotations.
    _annotStream = new FileStream(
        _annotStorePath, FileMode.OpenOrCreate, FileAccess.ReadWrite);

    // Create an AnnotationStore using the file stream.
    _annotStore = new XmlStreamStore(_annotStream);

    // Enable the AnnotationService using the new store.
    _annotService.Enable(_annotStore);
}// end:StartAnnotations()
```

### 突出显示

当人们在纸质文档上作标记时，往往使用创造性的方法来突出显示兴趣项，例如对于句子中的某些字词，加下划线、高亮显示、圈出，或者将在空白的地方绘制标记或符号。 Microsoft Annotations Framework 中的突出显示批注具有类似的功能，用于标记在 WPF 文档查看控件中显示的信息。

下图演示了一个突出显示批注的示例。

![突出显示批注](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/caf-callouts.png)

用户通常通过首先选择一些文本或自己感兴趣的项，然后右键单击以显示创建批注[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)批注选项。 下面的示例演示可扩展应用程序标记语言 (XAML)可用于声明[ContextMenu](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contextmenu)用户可以访问创建和管理批注的路由命令。

```xaml
<DocumentViewer.ContextMenu>
  <ContextMenu>
    <MenuItem Command="ApplicationCommands.Copy" />
    <Separator />
    <!-- Add a Highlight annotation to a user selection. -->
    <MenuItem Command="ann:AnnotationService.CreateHighlightCommand"
              Header="Add Highlight" />
    <!-- Add a Text Note annotation to a user selection. -->
    <MenuItem Command="ann:AnnotationService.CreateTextStickyNoteCommand"
              Header="Add Text Note" />
    <!-- Add an Ink Note annotation to a user selection. -->
    <MenuItem Command="ann:AnnotationService.CreateInkStickyNoteCommand"
              Header="Add Ink Note" />
    <Separator />
    <!-- Remove Highlights from a user selection. -->
    <MenuItem Command="ann:AnnotationService.ClearHighlightsCommand"
              Header="Remove Highlights" />
    <!-- Remove Text Notes and Ink Notes from a user selection. -->
    <MenuItem Command="ann:AnnotationService.DeleteStickyNotesCommand"
              Header="Remove Notes" />
    <!-- Remove Highlights, Text Notes, Ink Notes from a selection. -->
    <MenuItem Command="ann:AnnotationService.DeleteAnnotationsCommand"
              Header="Remove Highlights &amp; Notes" />
  </ContextMenu>
</DocumentViewer.ContextMenu>
```

### 数据锚定

Annotations Framework 将批注与用户选择的数据绑定，而不仅仅是绑定到显示视图中的某个位置。 因此，如果文档视图更改（例如，当用户滚动显示窗口或者调整其大小时），批注将仍然跟随它绑定到的所选数据。 例如，下图显示了用户在所选文本上做的批注。 当文档视图更改时（滚动、调整大小、缩放或者移动），突出显示批注将与最初所选数据一起移动。

![批注数据锚定](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/caf-dataanchoring.png)

###  匹配批注与批注对象

你可以将批注与对应的批注对象匹配。 以具有注释窗格的简单文档读取器应用程序为例。 注释窗格可能是一个列表框，用于显示锚定到文档的批注列表的文本。 如果用户在列表框中选择一项，应用程序将显示相应的批注对象所锚定到的文档段落。

下面的示例演示如何实现充当注释窗格的此类列表框的事件处理程序。

```csharp
void annotationsListBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
{

    Annotation comment = (sender as ListBox).SelectedItem as Annotation;
    if (comment != null)
    {
        // IAnchorInfo info;
        // service is an AnnotationService object
        // comment is an Annotation object
        info = AnnotationHelper.GetAnchorInfo(this.service, comment);
        TextAnchor resolvedAnchor = info.ResolvedAnchor as TextAnchor;
        TextPointer textPointer = (TextPointer)resolvedAnchor.BoundingStart;
        textPointer.Paragraph.BringIntoView();
    }
}
```

另一个示例方案涉及到应用程序，使交换批注和文档通过电子邮件的读取者之间的粘滞便笺。 凭借此功能，这些应用程序可以将读取器导航到包含要交换的批注的页面。

## [Annotations Schema](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/annotations-schema)

本主题介绍 Microsoft Annotations Framework 用来保存和检索用户批注数据的 XML 架构定义 (XSD)。

Annotations Framework 将批注数据从内部表示形式序列化为 XML 格式。 Annotations Framework XSD 架构描述了用于此转换的 XML 格式。 该架构定义独立于实现、可用来在应用程序之间交换批注数据的 XML 格式。

Annotations Framework XML 架构定义由两个子架构组成

- 批注 XML 核心架构（核心架构）。
- 批注 XML 基本架构（核心架构）。

核心架构定义的主 XML 结构[Annotation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.annotations.annotation)。 大部分核心架构中定义的 XML 元素中的类型对应[System.Windows.Annotations](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.annotations)命名空间。 核心架构公开应用程序可在其中添加自己的 XML 数据的三个扩展点。 这些扩展点包括[Authors](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.annotations.annotation.authors)， [ContentLocatorPart](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.annotations.contentlocatorpart)，和"内容"。 (内容元素中的窗体提供了[XmlElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.xmlelement)列表。)

本主题中描述的基本架构定义的扩展[Authors](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.annotations.annotation.authors)， [ContentLocatorPart](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.annotations.contentlocatorpart)，和内容的初始 Windows Presentation Foundation (WPF) 版本中包含的类型。

### 批注 XML 核心架构

批注 XML 核心架构定义用于存储的 XML 结构[Annotation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.annotations.annotation)对象。

XML复制

```xml
<xsd:schema elementFormDefault="qualified" attributeFormDefault="unqualified"  
            blockDefault="#all"  
            xmlns:xsd="http://www.w3.org/2001/XMLSchema"  
            targetNamespace="http://schemas.microsoft.com/windows/annotations/2003/11/core"  
            xmlns:anc="http://schemas.microsoft.com/windows/annotations/2003/11/core">  
  
  <!--  The Annotations element groups a number of annotations.  -->  
  <xsd:element name="Annotations" type="anc:AnnotationsType" />  
  
  <xsd:complexType name="AnnotationsType">  
    <xsd:sequence>  
      <xsd:element name="Annotation" minOccurs="0" maxOccurs="unbounded"  
                   type="anc:AnnotationType" />  
    </xsd:sequence>  
  </xsd:complexType>  
  
  <!-- AnnotationType defines the structure of the Annotation element. -->  
  <xsd:complexType name="AnnotationType">  
    <xsd:sequence>  
  
      <!-- List of 0 or more authors. -->  
      <xsd:element name="Authors" minOccurs="0" maxOccurs="1"  
                   type="anc:AuthorListType" />  
  
      <!-- List of 0 or more anchors. -->  
      <xsd:element name="Anchors" minOccurs="0" maxOccurs="1"  
                   type="anc:ResourceListType" />  
  
      <!-- List of 0 or more cargos. -->  
      <xsd:element name="Cargos" minOccurs="0" maxOccurs="1"  
                   type="anc:ResourceListType" />  
  
    </xsd:sequence>  
  
    <!-- Unique annotation ID. -->  
    <xsd:attribute name="Id" type="xsd:string" use="required" />  
  
    <!-- Annotation "Type" is used to map the annotation to an annotation  
         component that takes care of the visual representation of the  
         annotation.  WPF V1 recognizes three annotation types:  
  http://schemas.microsoft.com/windows/annotations/2003/11/base:Highlight  
  http://schemas.microsoft.com/windows/annotations/2003/11/base:TextStickyNote  
  http://schemas.microsoft.com/windows/annotations/2003/11/base:InkStickyNote  
    -->  
    <xsd:attribute name="Type" type="xsd:QName" use="required" />  
  
    <!--  Time when the annotation was last modified.  -->  
    <xsd:attribute name="LastModificationTime" use="optional"  
                   type="xsd:dateTime" />  
  
    <!--  Time when the annotation was created.  -->  
    <xsd:attribute name="CreationTime" use="optional"  
                   type="xsd:dateTime" />  
  </xsd:complexType>  
  
  <!-- "Authors" consists of 0 or more elements that represent an author. -->  
  <xsd:complexType name="AuthorListType">  
    <xsd:sequence minOccurs="0" maxOccurs="unbounded">  
      <xsd:element ref="anc:Author" />  
    </xsd:sequence>  
  </xsd:complexType>  
  
  <!-- The core schema allows any author type. Supported author types  
       in version 1 (V1) are described in the base schema. -->  
  <xsd:element name="Author" abstract="true" block="extension restriction"/>  
  
  <!-- Both annotation anchor and annotation cargo are represented by the  
       ResourceListType which contains 0 or more "Resource" elements. -->  
  <xsd:complexType name="ResourceListType">  
    <xsd:sequence>  
      <xsd:element name="Resource" minOccurs="0" maxOccurs="unbounded"  
                   type="anc:ResourceType" />  
    </xsd:sequence>  
  </xsd:complexType>  
  
  <!-- Resource groups identification, location  
       and/or content of some information.  -->  
  <xsd:complexType name="ResourceType">  
    <xsd:choice minOccurs="0" maxOccurs="unbounded" >  
      <xsd:choice>  
        <xsd:element name="ContentLocator" type="anc:ContentLocatorType" />  
        <xsd:element name="ContentLocatorGroup" type="anc:ContentLocatorGroupType" />  
      </xsd:choice>  
      <xsd:element ref="anc:Content"/>  
    </xsd:choice>  
  
    <!-- Unique resource identifier. -->  
    <xsd:attribute name="Id" type="xsd:string" use="required" />  
  
    <!-- Optional resource name. -->  
    <xsd:attribute name="Name" type="xsd:string" use="optional" />  
  </xsd:complexType>  
  
  <!-- ContentLocatorGroup contains a set of ContentLocators -->  
  <xsd:complexType name="ContentLocatorGroupType">  
    <xsd:sequence>  
      <xsd:element name="ContentLocator" minOccurs="1" maxOccurs="unbounded"  
                   type="anc:ContentLocatorType" />  
    </xsd:sequence>  
  </xsd:complexType>  
  
  <!-- A ContentLocator describes the location or the identification  
       of particular data within some context.  The ContentLocator consists  
       of one or more ContentLocatorParts.  Each ContentLocatorPart needs to  
       be successively applied to the context to arrive at the data.  What  
       "applying", "context", and "data" mean is application dependent.  
  -->  
  <xsd:complexType name="ContentLocatorType">  
    <xsd:sequence minOccurs="1" maxOccurs="unbounded">  
      <xsd:element ref="anc:ContentLocatorPart" />  
    </xsd:sequence>  
  </xsd:complexType>  
  
  <!-- A ContentLocatorPart is a set of "Item" elements.  Each "Item" element  
       has "Name" and "Value" attributes that define a name/value pair.  
       ContentLocatorPart is an abstract type that must be restricted for each  
       concrete ContentLocatorPart definition.  This restriction should define  
       allowed names and values for the concrete ContentLocatorPart type. That  
       way the application can define its own way of locating information. The   
       ContentLocatorPartTypes that are allowed in version 1 (V1) of WPF are  
       defined in the Annotations Base Schema.  
  -->  
  <xsd:element name="ContentLocatorPart" type="anc:ContentLocatorPartType"  
               abstract="true" />  
  
  <xsd:complexType name="ContentLocatorPartType" abstract="true"  
                   block="restriction">  
    <xsd:sequence minOccurs="0" maxOccurs="unbounded">  
      <xsd:element name="Item" type="anc:ItemType" />  
    </xsd:sequence>  
  </xsd:complexType>  
  
  <xsd:complexType name="ItemType" abstract="true" >  
    <xsd:attribute name="Name" type='xsd:string' use="required" />  
    <xsd:attribute name="Value" type='xsd:string' use="optional" />  
  </xsd:complexType>  
  
  <!-- Content describes the underlying content of a resource.  This is an  
       abstract type that should be redefined for each concrete content type  
       through restriction.  Allowed content types in WPF version 1 are  
       defined in the Annotations Base Schema.  
  -->  
  <xsd:element name="Content" abstract="true" block="extension restriction"/>  
  
</xsd:schema>  
```

### 批注 XML 基本架构

基本架构定义为核心架构中定义的三个抽象元素的 XML 结构[Authors](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.annotations.annotation.authors)， [ContentLocatorPart](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.annotations.contentlocatorpart)，和[Contents](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.annotations.annotationresource.contents)。

XML复制

```xml
<xsd:schema elementFormDefault="qualified" attributeFormDefault="unqualified"  
     blockDefault="#all"  
     xmlns:xsd="http://www.w3.org/2001/XMLSchema"  
     targetNamespace="http://schemas.microsoft.com/windows/annotations/2003/11/base"  
     xmlns:anb="http://schemas.microsoft.com/windows/annotations/2003/11/base"   
     xmlns:anc="http://schemas.microsoft.com/windows/annotations/2003/11/core">  
  
  <xsd:import schemaLocation="AnnotationCoreV1.xsd"  
       namespace="http://schemas.microsoft.com/windows/annotations/2003/11/core"/>  
  
  <!-- ***** Author ***** -->  
  <!-- Simple DisplayName Author -->  
  <xsd:complexType name="StringAuthorType">  
    <xsd:simpleContent >  
      <xsd:extension base='xsd:string' />  
    </xsd:simpleContent>  
  </xsd:complexType>  
  <xsd:element name="StringAuthor" type="anb:StringAuthorType"  
               substitutionGroup="anc:Author"/>  
  
  <!-- ***** LocatorParts ***** -->  
  
  <!-- Helper types -->  
  
  <!-- CountItemNameType - helper type to define count item -->  
  <xsd:simpleType name="CountItemNameType">  
    <xsd:restriction base='xsd:string'>  
      <xsd:pattern value="Count" />  
    </xsd:restriction>  
  </xsd:simpleType>  
  
  <!-- NumberType - helper type to define segment count item -->  
  <xsd:simpleType name="NumberType">  
    <xsd:restriction base='xsd:string'>  
      <xsd:pattern value="\d*" />  
    </xsd:restriction>  
  </xsd:simpleType>  
  
  <!-- SegmentNameType: helper type to define possible segment name types -->  
  <xsd:simpleType name="SegmentItemNameType">  
    <xsd:restriction base='xsd:string'>  
      <xsd:pattern value="Segment\d*" />  
    </xsd:restriction>  
  </xsd:simpleType>  
  
  <!-- Flow Locator Part -->  
  
  <!-- FlowSegmentValueItemType: helper type to define flow segment values -->  
  <xsd:simpleType name="FlowSegmentItemValueType">  
    <xsd:restriction base='xsd:string'>  
      <xsd:pattern value=" \d*,\d*" />  
    </xsd:restriction>  
  </xsd:simpleType>  
  
  <!-- FlowItemType -->  
  <xsd:complexType name="FlowItemType" abstract = "true">  
    <xsd:complexContent>  
      <xsd:restriction base="anc:ItemType">  
      </xsd:restriction>  
   </xsd:complexContent>  
  </xsd:complexType>  
  
  <!-- FlowSegmentItemType -->  
  <xsd:complexType name="FlowSegmentItemType">  
    <xsd:complexContent>  
      <xsd:restriction base="anb:FlowItemType">  
        <xsd:attribute name="Name" use="required"  
                       type="anb:SegmentItemNameType"/>  
        <xsd:attribute name="Value" use="required"  
                       type="anb:FlowSegmentItemValueType"/>  
       </xsd:restriction>  
    </xsd:complexContent>  
 </xsd:complexType>  
  
  <!-- FlowCountItemType -->  
  <xsd:complexType name="FlowCountItemType">  
    <xsd:complexContent>  
      <xsd:restriction base="anb:FlowItemType">  
        <xsd:attribute name="Name" type="anb:CountItemNameType" use="required"/>  
        <xsd:attribute name="Value" type="anb:NumberType" use="required"/>  
       </xsd:restriction>  
    </xsd:complexContent>  
  </xsd:complexType>  
  
  <!-- CharacterRangeType is an extension of ContentLocatorPartType that locates  
  *    part of the content within a FlowDocument. CharacterRangeType contains one  
  *    "Item" element with name "Count" and value the number(N) of "SegmentXX"  
  *    elements that this ContentLocatorPart has.  It also contains N "Item"  
  *    elements with name "SegmentXX" where XX is a number from 0 to N-1. The  
  *    value of each "SegmnetXX" element is a string in the form "offset, length"  
  *    which locates one sequence of symbols in the FlowDocument. Example:  
  
  *        <anb:CharacterRange>  
  *          <anc:Item Name="Count" Value="2" />  
  *          <anc:Item Name="Segment0" Value="5,10" />  
  *          <anc:Item Name="Segment1" Value="25,2" />  
  *        </anb:ChacterRange>  
  -->  
  <xsd:complexType name="CharacterRangeType">  
    <xsd:complexContent>  
      <xsd:extension base="anc:ContentLocatorPartType">  
        <xsd:sequence minOccurs="1" maxOccurs="unbounded">  
          <xsd:element name="Item" type="anb:FlowItemType" />  
        </xsd:sequence>  
      </xsd:extension>  
    </xsd:complexContent>  
  </xsd:complexType>  
  
  <!-- CharacterRange element substitutes ContentLocatorPart element -->  
  <xsd:element name="CharacterRange" type="anb:CharacterRangeType"  
               substitutionGroup="anc:ContentLocatorPart"/>  
  
  <!-- Fixed LocatorPart -->  
  
  <!-- Helper type – FixedItemType -->  
  <xsd:complexType name="FixedItemType" abstract = "true">  
    <xsd:complexContent>  
      <xsd:restriction base="anc:ItemType">  
      </xsd:restriction>  
    </xsd:complexContent>  
  </xsd:complexType>  
  
  <!-- Helper type – FixedCountItemType: ContentLocatorPart items count -->  
  <xsd:complexType name="FixedCountItemType">  
    <xsd:complexContent>  
      <xsd:restriction base="anb:FixedItemType">  
        <xsd:attribute name="Name" type="anb:CountItemNameType" use="required"/>  
        <xsd:attribute name="Value" type="anb:NumberType" use="required"/>  
      </xsd:restriction>  
    </xsd:complexContent>  
  </xsd:complexType>  
  
  <!-- Helper type -FixedSegmentValue: Defines possible fixed segment values -->  
  <xsd:simpleType name="FixedSegmentItemValueType">  
     <xsd:restriction base='xsd:string'>  
        <xsd:pattern value="\d*,\d*,\d*,\d*" />  
     </xsd:restriction>  
  </xsd:simpleType>  
  
  <!-- Helper type - FixedSegmentItemType -->  
  <xsd:complexType name="FixedSegmentItemType">  
    <xsd:complexContent>  
      <xsd:restriction base="anb:FixedItemType">  
        <xsd:attribute name="Name" use="required"  
                       type="anb:SegmentItemNameType"/>  
        <xsd:attribute name="Value" use="required"  
                       type="anb:FixedSegmentItemValueType "/>  
      </xsd:restriction>  
    </xsd:complexContent>  
  </xsd:complexType>  
  
  <!-- FixedTextRangeType is an extension of ContentLocatorPartType that locates  
  *    content within a FixedDocument.  It contains one "Item" element with name  
  *    "Count" and value the number (N) of "Item" elements with name "SegmentXX"  
  *    that this ContentLocatorPart has.  FixedTextRange locator part also  
  *    contains N "Item" elements with one attribute Name="SegmentXX" where XX is  
  *    a number from 0 to N-1 and one attribute "Value" in the form "X1, Y1, X2,  
  *    Y2".  Here X1,Y1 are the coordinates of the start symbol in this segment,  
  *    X2,Y2 are the coordinates of the end symbol in this segment.  Example:  
  *  
  *        <anb:FixedTextRange>  
  *          <anc:Item Name="Count" Value="2" />  
  *          <anc:Item Name="Segment0" Value="10,5,20,5" />  
  *          <anc:Item Name="Segment1" Value="25,15, 25,20" />  
  *        </anb:FixedTextRange>  
  -->  
  <xsd:complexType name="FixedTextRangeType">  
     <xsd:complexContent>  
        <xsd:extension base="anc:ContentLocatorPartType">  
           <xsd:sequence minOccurs="1" maxOccurs="unbounded">  
              <xsd:element name="Item" type="anb:FixedItemType" />  
           </xsd:sequence>  
       </xsd:extension>  
     </xsd:complexContent>  
  </xsd:complexType>  
  
  <!-- FixedTextRange element substitutes ContentLocatorPart element -->  
  <xsd:element name="FixedTextRange" type="anb:FixedTextRangeType"  
               substitutionGroup="anc:ContentLocatorPart"/>  
  
  <!-- DataId -->  
  
  <!-- ValueItemNameType: helper type to define value item -->  
  <xsd:simpleType name="ValueItemNameType">  
    <xsd:restriction base='xsd:string'>  
      <xsd:pattern value="Value" />  
    </xsd:restriction>  
  </xsd:simpleType>  
  
  <!-- StringValueItemType -->  
  <xsd:complexType name="StringValueItemType">  
     <xsd:complexContent>  
        <xsd:restriction base="anc:ItemType">  
           <xsd:attribute name="Name" type="anb:ValueItemNameType" use="required"/>  
        <xsd:attribute name="Value" type="xsd:string" use="required"/>  
        </xsd:restriction>  
     </xsd:complexContent>  
  </xsd:complexType>  
  
  <xsd:complexType name="StringValueLocatorPartType">  
    <xsd:complexContent>  
      <xsd:extension base="anc:ContentLocatorPartType">  
        <xsd:sequence minOccurs="1" maxOccurs="1">  
          <xsd:element name="Item" type="anb:ValueItemType" />  
        </xsd:sequence>  
      </xsd:extension>  
    </xsd:complexContent>  
  </xsd:complexType>  
  
  <!-- DataId element substitutes ContentLocatorPart and is used to locate a  
  *    subtree in the logical tree.  Including DataId locator part in a  
  *    ContentLocator helps to narrow down the search for a particular content.  
  *    Examle of DataId ContentLocatorPart:  
  *      
  *        <anb:DataId>  
  *          <anc:Item Name="Value" Value="FlowDocument" />  
  *        </anb:DataId>  
  -->  
  
  <xsd:element name="DataId" type="anb: StringValueLocatorPartType "  
               substitutionGroup="anc:ContentLocatorPart"/>  
  
  <!-- PageNumber -->  
  
  <!-- NumberValueItemType -->  
  <xsd:complexType name="NumberValueItemType">  
    <xsd:complexContent>  
      <xsd:restriction base="anc:ItemType">  
        <xsd:attribute name="Name" type="anb:ValueItemNameType" use="required"/>  
        <xsd:attribute name="Value" type="anb:NumberType" use="required"/>  
      </xsd:restriction>  
    </xsd:complexContent>  
  </xsd:complexType>  
  
  <xsd:complexType name="NumberValueLocatorPartType">  
    <xsd:complexContent>  
      <xsd:extension base="anc:ContentLocatorPartType">  
        <xsd:sequence minOccurs="1" maxOccurs="1">  
          <xsd:element name="Item" type="anb:ValueItemType" />  
        </xsd:sequence>  
      </xsd:extension>  
    </xsd:complexContent>  
  </xsd:complexType>  
  
  <!-- PageNumber element substitutes ContentLocatorPart and is used to locate a  
  *    page in a FixedDocument.  PageNumber ContentLocatorPart is used in  
  *    conjunction with the FixedTextRange ContentLocatorPart and it shows on with  
  *    page are the coordinates defined in the FixedTextRange.  
  *    Example of a PageNumber ContentLocatorPart:  
  *     
  *       <anb:PageNumber>  
  *         <anc:Item Name="Value" Value="1" />  
  *       </anb:PageNumber>  
  -->  
  <xsd:element name="PageNumber" type="anb:NumbnerValueLocatorPartType"  
               substitutionGroup="anc:ContentLocatorPart"/>  
  
  <!-- ***** Content ***** -->  
  <!-- Highlight colors – defines highlight color for annotations of type  
  *    Highlight or normal and active anchor colors for annotations of type  
  *    TextStickyNote and InkStickyNote.   
  -->  
  <xsd:complexType name="ColorsContentType">  
    <xsd:attribute name="Background" type='xsd:string' use="required" />  
    <xsd:attribute name="ActiveBackground" type='xsd:string' use="optional" />  
  </xsd:complexType>  
  
  <xsd:element name="Colors" type="anb:ColorsContentType"  
               substitutionGroup="anc:Content"/>  
  
  <!-- RTB Text –contains XAML representing StickyNote Reach Text Box text.  
  *    Used in annotations of type TextStickyNote. -->  
  <xsd:complexType name="TextContentType">  
    <!-- See XAML schema for RTB content -->  
  </xsd:complexType>  
  
  <xsd:element name="Text" type="anb:TextContentType"  
               substitutionGroup="anc:Content"/>  
  
  <!-- Ink – contains XAML representing Sticky Note ink.  
  *    Used in annotations of type InkStickyNote. -->  
  <xsd:complexType name="InkContentType">  
    <!-- See XAML schema for Ink content -->  
  </xsd:complexType>  
  
  <xsd:element name="Ink" type="anb:InkContentType"  
               substitutionGroup="anc:Content"/>  
  
  <!-- SN Metadata – defines StickyNote attributes as position width, height,  
  *    etc.  Used in annotations of type TextStickyNote and InkStickyNote. -->  
  <xsd:complexType name="MetadataContentType">  
    <xsd:attribute name="Left" type='xsd:decimal' use="optional"  />  
    <xsd:attribute name="Top" type='xsd:decimal' use="optional" />  
    <xsd:attribute name="Width" type='xsd:decimal' use="optional" />  
    <xsd:attribute name="Height" type='xsd:decimal' use="optional" />  
    <xsd:attribute name="XOffset" type='xsd:decimal' use="optional" />  
    <xsd:attribute name="YOffset" type='xsd:decimal' use="optional" />  
    <xsd:attribute name="ZOrder" type='xsd:decimal' use="optional" />  
  </xsd:complexType>  
  
  <xsd:element name="Metadata" type="anb:MetadataContentType"   
               substitutionGroup="anc:Content"/>  
  
</xsd:schema>  
```

### 批注 XmlStreamStore 所生成的示例 XML

下面的 XML 显示了批注的输出[XmlStreamStore](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.annotations.storage.xmlstreamstore)和组织的一个示例文件，包含三个批注： 突出显示、 文本粘滞便笺以及墨迹便笺。

```xml
<?xml version="1.0" encoding="utf-8"?>  
<anc:Annotations  
     xmlns:anc="http://schemas.microsoft.com/windows/annotations/2003/11/core"  
     xmlns:anb="http://schemas.microsoft.com/windows/annotations/2003/11/base">  
  
  <anc:Annotation Id="d308ea9b-36eb-4cc4-94d0-97634f10f7a2"  
                  CreationTime="2006-09-13T18:28:51.4465702-07:00"  
                  LastModificationTime="2006-09-13T18:28:51.4465702-07:00"  
                  Type="anb:Highlight">  
    <anc:Anchors>  
      <anc:Resource Id="4f53661b-7328-4673-8e3f-c53f08b9cd94">  
        <anc:ContentLocator>  
          <anb:DataId>  
            <anc:Item Name="Value" Value="FlowDocument" />  
          </anb:DataId>  
          <anb:CharacterRange>  
            <anc:Item Name="Segment0" Value="600,609" />  
            <anc:Item Name="Count" Value="1" />  
          </anb:CharacterRange>  
        </anc:ContentLocator>  
      </anc:Resource>  
    </anc:Anchors>  
  </anc:Annotation>  
  
  <anc:Annotation Id="d7a8d271-387e-4144-9f8b-bc3c97816e5f"  
                  CreationTime="2006-09-13T18:28:56.7903202-07:00"  
                  LastModificationTime="2006-09-13T18:28:56.8996952-07:00"  
                  Type="anb:TextStickyNote">  
    <anc:Authors>  
      <anb:StringAuthor>Denise Smith</anb:StringAuthor>  
    </anc:Authors>  
  
    <anc:Anchors>  
      <anc:Resource Id="dab2560e-6ebd-4ad0-80f9-483356a3be0b">  
        <anc:ContentLocator>  
          <anb:DataId>  
            <anc:Item Name="Value" Value="FlowDocument" />  
          </anb:DataId>  
          <anb:CharacterRange>  
            <anc:Item Name="Segment0" Value="787,801" />  
            <anc:Item Name="Count" Value="1" />  
          </anb:CharacterRange>  
        </anc:ContentLocator>  
      </anc:Resource>  
    </anc:Anchors>  
  
    <anc:Cargos>  
      <anc:Resource Id="ea4dbabd-b400-4cf9-8908-5716b410f9e4" Name="Meta Data">  
        <anb:MetaData anb:ZOrder="0" />  
      </anc:Resource>  
    </anc:Cargos>  
  </anc:Annotation>  
  
  <anc:Annotation Id="66803c69-b0d7-4cc3-bdff-cacc1955e806"  
                  CreationTime="2006-09-13T18:29:03.6653202-07:00"  
                  LastModificationTime="2006-09-13T18:29:03.7121952-07:00"  
                  Type="anb:InkStickyNote">  
    <anc:Authors>  
      <anb:StringAuthor>Mike Nash</anb:StringAuthor>  
    </anc:Authors>  
  
    <anc:Anchors>  
      <anc:Resource Id="52251c53-8eeb-4fd7-b8f3-94e78dfc25fa">  
        <anc:ContentLocator>  
          <anb:DataId>  
            <anc:Item Name="Value" Value="FlowDocument" />  
          </anb:DataId>  
          <anb:CharacterRange>  
            <anc:Item Name="Segment0" Value="880,884" />  
            <anc:Item Name="Count" Value="1" />  
          </anb:CharacterRange>  
        </anc:ContentLocator>  
      </anc:Resource>  
    </anc:Anchors>  
  
    <anc:Cargos>  
      <anc:Resource Id="11e50b97-8d91-4ff9-82c3-16607b2b552b" Name="Meta Data">  
        <anb:MetaData anb:ZOrder="1" />  
      </anc:Resource>  
    </anc:Cargos>  
  </anc:Annotation>  
  
</anc:Annotations>  
```