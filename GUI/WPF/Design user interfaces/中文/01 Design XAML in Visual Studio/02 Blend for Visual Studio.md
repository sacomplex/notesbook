# [Blend for Visual Studio](https://docs.microsoft.com/en-us/visualstudio/designers/creating-a-ui-by-using-blend-for-visual-studio?view=vs-2019)

Blend for Visual Studio 可用于设计基于 XAML 的 Windows 和 Web 应用程序。 它提供了与 Visual studio 相同的基本 XAML 设计体验，并添加了可视化设计器，以用于高级任务，例如动画和行为。 有关 Blend 和 Visual Studio 之间的比较，请参阅[在 Visual Studio 和 Blend for Visual Studio 中设计 XAML](https://docs.microsoft.com/zh-cn/visualstudio/designers/designing-xaml-in-visual-studio?view=vs-2019)。

Blend for Visual Studio 是 Visual Studio 的一个组件。 若要安装 Blend，请在 Visual Studio 安装程序中，选择“通用 Windows 平台开发”或“.NET 桌面开发”工作负载。 这两种工作负载均包括 Blend for Visual Studio 组件。

![UWP 工作负载组件](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/installer-uwp.png?view=vs-2019)    ![.NET 桌面开发工作负载组件](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/installer-dotnet-desktop.png?view=vs-2019)

如果是初次接触 Blend for Visual Studio，则要花一些时间来熟悉工作区的特有功能。 本主题将作用快速教程。

 备注

若要浏览共享的设计功能，例如美工板、“文档大纲”窗口和“设备”窗口，请参阅[使用 XAML 设计器创建 UI](https://docs.microsoft.com/zh-cn/visualstudio/designers/creating-a-ui-by-using-xaml-designer-in-visual-studio?view=vs-2019)。

## “工具”面板概览

可在应用程序中通过 Blend for Visual Studio 的“工具”面板创建和修改对象。 可以通过使用鼠标选择工具并在美工板上进行绘制来创建对象。

![“工具”面板](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/blend5toolspanel.png?view=vs-2019)

|                                                              |                                                              |                                                              |                    |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------ |
| ![选择工具](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_1.png?view=vs-2019) | **选择工具** - 选择对象和路径。  使用“直接选择”工具可选择嵌套对象和路径段。 | ![标注 A](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b5_label_a.png?view=vs-2019) | **渐变和画笔工具** |
| ![视图工具](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_2.png?view=vs-2019) | **视图工具** - 调整美工板的视图，例如平移和缩放。            | ![标注 B](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b5_label_b.png?view=vs-2019) | **路径工具**       |
| ![画笔工具](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_3.png?view=vs-2019) | **画笔工具** - 处理对象的可视特性，例如转换画笔、绘制对象，或者选择某对象属性将其应用到其他对象。 | ![标注 C](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b5_label_c.png?view=vs-2019) | **形状工具**       |
| ![对象工具](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_4.png?view=vs-2019) | **对象工具** - 在美工板上绘制最常用的对象，例如路径、形状、布局面板、文本和控件。 | ![标注 D](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b5_label_d.png?view=vs-2019) | **版式面板**       |
| ![资产工具](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_5.png?view=vs-2019) | **资产工具** - 访问“资产”面板并显示库中最近用过的资产。      | ![标注 E](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b5_label_e.png?view=vs-2019) | **文本控件**       |
|                                                              |                                                              | ![标注 F](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b5_label_f.png?view=vs-2019) | **常见控件**       |

**观看短片：**![配置已安装的功能](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/bldadminconsoleinitialconfigicon.png?view=vs-2019) [工具栏](https://www.youtube.com/watch?v=VkdUJcvoo54&list=PLBDF977B2F1DAB358&index=4)。

## “资产”面板概览

可在“资产”面板中找到所有控件，它类似于 Visual Studio 中的“工具箱”。 除控件外，“资产”面板还包括所有可添加到美工板的内容，例如样式、媒体、行为和效果等。

![“资产”面板](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/blend5_assets_panel.png?view=vs-2019)

|                                                              |                                                              |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![img](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_1.png?view=vs-2019) | **搜索框** - 可在“搜索”框中键入值来筛选资产列表。            |
| ![网格模式和列表模式](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_2.png?view=vs-2019) | **网格模式和列表模式** - 在资产的“网格模式”视图和“列表模式”视图之间切换。 |
| ![资产类别](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_3.png?view=vs-2019) | **资产类别** - 单击类别或子类别查看该类别中资产的列表。      |
| ![样式](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_4.png?view=vs-2019) | **样式** - 显示资源字典中包含的所有样式。                    |
| ![说明](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_5.png?view=vs-2019) | **说明** - 查看所选资产类别或子类别的说明。                  |

## “对象和时间线”面板概览

使用此面板可在美工板上组织对象以及（如果需要）对它们进行动画处理。

![动画模式中的“对象和时间线”面板](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b5_object_timeline_animation.png?view=vs-2019)

|                                                              |                                                              |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![对象视图](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_1.png?view=vs-2019) | **对象视图** - 查看文档的可视树。 可以深化到不同级别的详细信息。 还可以添加层以便进一步在美工板上组织对象。通过这种方式可以将它们作为组进行锁定和隐藏。 |
| ![记录模式指示器](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_2.png?view=vs-2019) | 记录模式指示器 - 查看是否在时间线中记录属性更改。            |
| ![情节提要选取器](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_3.png?view=vs-2019) | 情节提要选取器 - 查看已创建的情节提要的列表。                |
| ![关闭情节提要](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_4.png?view=vs-2019) | **关闭情节提要** - 关闭当前情节提要。                        |
| ![情节提要选项](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_5.png?view=vs-2019) | **情节提要选项** - 创建、复制、反向、删除、重命名或关闭情节提要。 |
| ![播放控件](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_6.png?view=vs-2019) | **播放控件** - 在时间线中导航。 也可拖动播放指针来定位（或*推移*）时间线。 |
| ![返回到范围](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_7.png?view=vs-2019) | **返回到范围** - 将对象视图的范围返回到上一个根对象或上一个范围。 仅当修改样式或模板时，才能执行此操作。 |
| ![记录关键帧](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_8.png?view=vs-2019) | **记录关键帧** - 记录所选对象属性在当前时间点的快照。        |
| ![对齐选项](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_9.png?view=vs-2019) | **对齐选项** - 设置时间线对齐、对齐分辨率以及关闭时间线对齐。 |
| ![显示 隐藏 锁定 解除锁定](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/97fa60b9-0caf-4387-9225-b57510d32209.png?view=vs-2019) | **显示/隐藏**、**锁定/解除锁定** - 显示或隐藏对象视图的可见性和锁定选项。 |
| ![播放指针在时间线上的位置](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_11.png?view=vs-2019) | **播放指针在时间线上的位置** - 以毫秒为单位显示当前时间。 也可以直接在此字段中输入时间值以跳到特定的时间点。 精度取决于“对齐选项”中设置的对齐分辨率。 |
| ![播放指针](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_12.png?view=vs-2019) | **播放指针** - 确定动画所处的时间点。 可以在时间线中拖动播放指针，以便预览动画。 |
| ![时间线上设置的关键帧](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_13.png?view=vs-2019) | **时间线上设置的关键帧** - 更改特点时间点的属性值。          |
| ![更改对象顺序](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/d839d12c-07a1-4127-a830-4a8e7069f4fe.png?view=vs-2019) | **更改对象顺序** - 设置对象的显示顺序。 单击此按钮可在结构视图中按 Z 顺序（从前到后）或按标记顺序（在“XAML”视图中出现的顺序）排列对象。 |
| ![时间线缩放](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_15.png?view=vs-2019) | **时间线缩放** - 设置时间线的缩放分辨率。 通过放大，可以编辑动画的更多细节；而通过缩小，可更全面地显示在更长时间段内发生的情况。 如果进行放大，但无法在所需时间位置设置关键帧，请验证设置的对齐分辨率是否足够高。 |
| ![标注 16](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b5_label_16.png?view=vs-2019) | **时间线构成区域** - 查看时间线，并通过拖动关键帧或通过其快捷菜单移动关键帧。 |

## “属性”面板概览

使用此面板可查看和修改对象的属性。 还可以直接在美工板上设置它们。 若如此操作，则“属性”面板中将反映出属性更改。

![“属性”面板](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/blend5_properties_panel.png?view=vs-2019)

**类别** - 展开和折叠类别的属性。 单击“展开”![展开](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/6375953d-074c-421a-bbb3-6f5055b67b64.png?view=vs-2019)和“折叠”![折叠](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b5_collapse_button.png?view=vs-2019)以显示或隐藏类别详细信息。

|                                                              |                                                              |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![名称和类型](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_1.png?view=vs-2019) | **名称和类型** - 查看所选对象的图标、名称和类型。            |
| ![排列依据](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_2.png?view=vs-2019) | **排列方式** - 按名称、源或类别的字母顺序排列属性。          |
| ![画笔属性](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_3.png?view=vs-2019) | **画笔属性** - 设置填充画笔、笔划画笔和前景画笔等画笔的可视属性。 |
| ![颜色编辑器](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_4.png?view=vs-2019) | **颜色编辑器** - 用于纯色画笔和渐变画笔。                    |
| ![颜色选取器](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_5.png?view=vs-2019) | **颜色选取器** - 选择颜色。                                  |
| ![色卡](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_6.png?view=vs-2019) | **色卡** - 查看初始颜色、当前颜色和上一种颜色                |
| ![取色器](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_7.png?view=vs-2019) | **取色器** - 使用屏幕上任意元素的颜色。 选择“纯色画笔”时，“颜色取色器”可用。 选择“渐变画笔”时，“渐变取色器”可用。 |
| ![属性和事件](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_8.png?view=vs-2019) | **属性和事件** - 为所选元素设置属性或选择事件。              |
| ![搜索框](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_9.png?view=vs-2019) | **搜索框** - 搜索属性。 在“搜索”框中键入值来筛选显示的属性。 |
| ![画笔编辑器选项卡](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/97fa60b9-0caf-4387-9225-b57510d32209.png?view=vs-2019) | **画笔编辑器选项卡** - 用于选择画笔编辑器。 可选择“无画笔”、“纯色画笔”、“渐变画笔”、“平铺画笔”或“画笔资源”。 |
| ![颜色资源](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_11.png?view=vs-2019) | **颜色资源** - 将完全相同的颜色应用于不同属性。 “颜色资源”选项卡包括“本地资源”和“系统资源”。 |
| ![RGB 颜色空间](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_12.png?view=vs-2019) | **RGB 颜色空间**- 通过调整“R”、“G”或“B”（分别表示红、绿、蓝）数字编辑器中的值修改颜色。 |
| ![Alpha 通道](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_13.png?view=vs-2019) | **Alpha 通道** - 使用 **A** 旁边的数字编辑器修改 Alpha 值。  |
| ![将颜色转换为资源](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/d839d12c-07a1-4127-a830-4a8e7069f4fe.png?view=vs-2019) | **将颜色转换为资源** - 将所选颜色转换为颜色资源。 在单击“颜色资源”选项卡时，可以获得颜色资源。 |
| ![img](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_15.png?view=vs-2019) | **十六进制值** - 查看所显示颜色的十六进制值。                |
| ![标注 16](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b5_label_16.png?view=vs-2019) | **渐变滑块** - 仅当选择渐变画笔时才显示。                    |
| ![显示高级属性](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/d50027a1-6824-4ad8-8b4e-558b0756dcf8.png?view=vs-2019) | **显示高级属性** - 查看不常用属性的类别。                    |

**观看短片：**![配置已安装的功能](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/bldadminconsoleinitialconfigicon.png?view=vs-2019) [属性面板](https://www.youtube.com/watch?v=HCqQfiobdag&list=PLBDF977B2F1DAB358&index=7)。

## [Insert controls and modify their behavior](https://docs.microsoft.com/en-us/visualstudio/designers/insert-controls-and-modify-their-behavior-in-xaml-designer?view=vs-2019)

控件使用户能够与你的应用进行交互。 可以使用它们收集信息并执行操作（如对对象进行动画处理或查询数据源）。

### 向美工板添加控件

可以将控件从“资产” 面板拖到“美工板” ，然后在“属性” 窗口中进行修改。

![Blend 资产选项卡控件](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/blend_assetsflipview_xaml.png?view=vs-2019)

#### 使用图像、形状或路径创建控件

可以使任何对象都成为控件。

![Blend“构成控件”对话框](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/blend_makeintocontrol_xaml.png?view=vs-2019)

例如，假设页面中心的电视的图片。 可以使用类似于电视按钮的小图像创建控件。 然后，用户可以单击这些按钮以更改频道。

可以这样做的原因是因为这些按钮现在是控件。 借助控件，可以响应用户交互；在此例中是当用户单击按钮时。

若要创建控件，请选择对象。 然后在“工具” 菜单上，单击“创建控件” 。

### 使控件执行操作

控件可以在用户与之交互时执行操作。 例如，这些操作可以启动动画、更新数据源或播放视频。

使用 *触发器*、 *行为*和 *事件* 可使控件执行操作。

#### 触发器

*触发器* 更改属性或执行任务以响应事件或另一个属性中的更改。 例如，可以在用户将鼠标指针悬停在按钮上方时更改按钮的颜色。

![“触发器”面板](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/custom_button_blend_propertytriggerinfo.png?view=vs-2019)

#### 行为

*行为* 是可重复重用的代码包。 它发挥的作用比更改属性稍微多一点。 它可以执行操作，例如查询数据服务。Blend 附带了小型行为集合，但可以添加更多。 将行为拖动到到你美工板中的任何对象，然后通过设置属性来自定义行为。

![“属性”面板中的 FluidMoveBehavior](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b4_fluidmovebehaviorproperties_sample.png?view=vs-2019)

**观看视频：**![播放图标](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/bldadminconsoleinitialconfigicon.png?view=vs-2019) [Blend 提示：使用行为简介第 1 部分](http://www.bing.com/videos/search?q=Expression%20blend%20behaviors&qs=n&form=QBVR&pq=expression%20blend%20behavior&sc=4-25&sp=-1&sk=#view=detail&mid=CF0DD797ED84DE740904CF0DD797ED84DE740904)。

#### 事件

最获得最佳灵活性，请处理 *事件*。 必须编写一些代码。

## [Insert images, videos, and audio clips](https://docs.microsoft.com/en-us/visualstudio/designers/insert-images-videos-and-audio-clips-in-xaml-designer?view=vs-2019)

图像、视频和音频剪辑可向应用添加视觉效果。

![已固定大小的图像](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b5_memory_images_sized.png?view=vs-2019)

若要使用图像、视频或音频剪辑，请将其添加到项目，然后将其从“资产” 面板拖到“美工板” 。

这些视频可帮助你将图像、视频和音频剪辑插入应用。

| 任务                        | 观看简短视频                                                 |
| --------------------------- | ------------------------------------------------------------ |
| 导入 Adobe FXG 文件         | ![配置已安装的功能](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/bldadminconsoleinitialconfigicon.png?view=vs-2019) [Blend 中的 FXG 导入预览](http://www.bing.com/videos/search?q=blend%20import%20FXG%20file&qs=n&form=QBVR&pq=blend%20import%20fxg%20file&sc=0-13&sp=-1&sk=#view=detail&mid=3C733B0B50A43166C55C3C733B0B50A43166C55C) |
| 导入 Adobe Illustrator 文件 | ![配置已安装的功能](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/bldadminconsoleinitialconfigicon.png?view=vs-2019) [将 Adobe Illustrator (ai) 文件导入 Blend](http://www.bing.com/videos/search?q=add%20illustrator%20file%20to%20blend&qs=n&form=QBVR&pq=add%20illustrator%20file%20to%20blend&sc=0-0&sp=-1&sk=#view=detail&mid=FDB1B25D4DEB69D24515FDB1B25D4DEB69D24515) |
| 导入 Adobe Photoshop 文件   | ![配置已安装的功能](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/bldadminconsoleinitialconfigicon.png?view=vs-2019) [将 Photoshop 文件导入 Blend](https://www.youtube.com/watch?v=ekYyhirFKs0) |
| 插入音频剪辑                | ![配置已安装的功能](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/bldadminconsoleinitialconfigicon.png?view=vs-2019) [添加音频剪辑](https://www.youtube.com/watch?v=7qW9l0tmkAI&index=52&list=PLBDF977B2F1DAB358) |

## [Draw shapes and paths](https://docs.microsoft.com/en-us/visualstudio/designers/draw-shapes-and-paths?view=vs-2019)

在 XAML 设计器中，“形状”正是你所期望的内容。 例如：矩形、圆或椭圆。 *路径* 是更加灵活的形状版本。 你可以执行某些操作，如重新调整它们的形状，或将它们合并在一起以形成新形状。

形状和路径使用矢量图形，因此它们可很好地按高分辨率显示进行缩放。 若要了解有关向量图形的详细信息，请参阅 [什么是向量图形](https://www.youtube.com/watch?v=MoCSwF0n-io) 或 [向量图形](http://www.webopedia.com/TERM/V/vector_graphics.html)。

### 绘制形状

可以在“资产” 面板中查找形状。

![“资产”面板上的“形状”类别](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b4_shapes_assetspanel.png?view=vs-2019)

将所需的任何形状拖到美工板上。 然后，可以使用形状的图柄缩放、旋转、移动或扭曲形状。

![Handles](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/84261e83-3091-4490-ab58-4218b188439e.png?view=vs-2019)

### 绘制路径

路径是一系列连接的直线和曲线。 使用路径可创建“资产” 面板中未提供的有趣形状。

可以使用线条、笔或铅笔绘制路径。 可以在“工具” 面板中找到这些工具。

![触笔工具](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/717956a8-b6a5-4e37-8af3-70bcfc78c82a.png?view=vs-2019) ![触笔工具选项](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/8fbbbb21-be83-4cf6-903b-3a49f00c9860.png?view=vs-2019)

#### 绘制直线

使用“触笔”工具![触笔工具](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/894f8612-e0ed-4e00-84cf-a9bc8f38fc54.png?view=vs-2019)或“线条”工具![线条工具](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/eb618397-5283-48be-8396-3449be7b6fbf.png?view=vs-2019)。

**使用“触笔”工具**![触笔工具](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/894f8612-e0ed-4e00-84cf-a9bc8f38fc54.png?view=vs-2019)

在美工板上，单击一次以定义开始点，然后再次单击以定义线条末尾。

**使用“线条”工具**![线条工具](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/eb618397-5283-48be-8396-3449be7b6fbf.png?view=vs-2019)

在美工板上，从所需线条起始位置处拖动，然后在所需线条结束位置处释放。

#### 绘制曲线

使用“触笔”工具![触笔工具](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/894f8612-e0ed-4e00-84cf-a9bc8f38fc54.png?view=vs-2019)。

在美工板上，单击一次以定义线条的起点，然后单击并拖动指针以创建所需的曲线。

如果要闭合路径，请单击线条上的第一个点。

#### 更改曲线的形状

使用“路径选择”工具![路径选择工具](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/6dd6571f-c116-451d-8dd2-1f88b8406362.png?view=vs-2019)。

单击形状，然后拖动形状上的任何点以更改曲线形状。

#### 绘制任意形状的路径

使用“铅笔”工具![铅笔工具](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/509dc167-734f-46c9-b012-987ee63450cd.png?view=vs-2019)。

在美工板上，如同使用真正的铅笔一样绘制任意形状的路径。

#### 删除路径的一部分

使用“路径选择”工具![路径选择工具](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/6dd6571f-c116-451d-8dd2-1f88b8406362.png?view=vs-2019)。

选择包含要删除的段的路径，然后单击“删除” 按钮。

#### 删除路径中的点

使用“选择”工具![选择工具](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/2ff91340-477e-4efa-a0f7-af20851e4daa.png?view=vs-2019)和“触笔”工具![触笔工具](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/894f8612-e0ed-4e00-84cf-a9bc8f38fc54.png?view=vs-2019)。

使用“选择”工具![选择工具](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/2ff91340-477e-4efa-a0f7-af20851e4daa.png?view=vs-2019)选择路径。 然后，使用“触笔”工具![触笔工具](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/894f8612-e0ed-4e00-84cf-a9bc8f38fc54.png?view=vs-2019)，以单击想要删除的点。

#### 向路径添加点

使用“选择”工具![选择工具](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/2ff91340-477e-4efa-a0f7-af20851e4daa.png?view=vs-2019)和“触笔”工具![触笔工具](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/894f8612-e0ed-4e00-84cf-a9bc8f38fc54.png?view=vs-2019)。

使用“选择”工具![选择工具](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/2ff91340-477e-4efa-a0f7-af20851e4daa.png?view=vs-2019)选择路径。 使用“触笔”工具![触笔工具](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/894f8612-e0ed-4e00-84cf-a9bc8f38fc54.png?view=vs-2019)，以单击想要在其中添加点的路径上的任意位置。

### 将形状转换为路径

若要采用与修改路径相同的方式来修改形状，请将形状转换为路径。

**观看短片：**![配置已安装的功能](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/bldadminconsoleinitialconfigicon.png?view=vs-2019) [使用路径：将形状转换为路径](https://www.youtube.com/watch?v=Io5bC0-nH6Q#t=147)。

### 合并路径

可以将路径和形状合并到单个路径中。

![合并路径](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/2df17a5d-a338-4ef4-96c5-dae51cc1ca8a.png?view=vs-2019)

|                                                              |                    |                                                              |          |
| ------------------------------------------------------------ | ------------------ | ------------------------------------------------------------ | -------- |
| ![合并之前的两个形状](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_1.png?view=vs-2019) | 合并之前的两个形状 | ![相交](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_4.png?view=vs-2019) | 相交     |
| ![相斥](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_2.png?view=vs-2019) | 相并               | ![img](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_5.png?view=vs-2019) | 排除重叠 |
| ![减](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_3.png?view=vs-2019) | 除                 | ![img](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b1_6.png?view=vs-2019) | 减       |

**观看短片：**![配置已安装的功能](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/bldadminconsoleinitialconfigicon.png?view=vs-2019) [使用路径：合并路径](https://www.youtube.com/watch?v=Io5bC0-nH6Q#t=195)。

### 创建复合路径

创建复合路径时，会从结果中减去路径的任何相交部分，生成的路径会采取最底部路径的视觉属性。

可以在创建之后随时分离复合路径。

![中断复合路径](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/2157a8aa-d9a7-4de4-8de5-b10d28f08a84.png?view=vs-2019)

**观看短片：**![配置已安装的功能](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/bldadminconsoleinitialconfigicon.png?view=vs-2019) [使用路径：创建复合路径](https://www.youtube.com/watch?v=Io5bC0-nH6Q)。

### 创建剪切路径

剪切路径是应用于另一个对象的路径或形状，可隐藏遮蔽对象处于剪切路径之外的部分。

![剪切路径](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/22471e98-a841-4f39-a3ef-36090cf5a625.png?view=vs-2019)

**观看短片：**![配置已安装的功能](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/bldadminconsoleinitialconfigicon.png?view=vs-2019) [使用路径：创建剪切路径](https://www.youtube.com/watch?v=Io5bC0-nH6Q#t=232)。

## [Modify the style of objects in Blend](https://docs.microsoft.com/en-us/visualstudio/designers/modify-the-style-of-objects-in-blend?view=vs-2019)

自定义对象的最简单方法是在“属性”窗格中设置属性。

如果你希望重复使用设置或设置组，请创建可重复使用的资源。 这可以是样式、模板或如自定义颜色一样简单的对象。 还可以使控件基于其状态以不同方式出现。 例如，按钮在用户单击它时变为绿色。

### 画笔：修改对象的外观

如果要更改对象外观，请向它应用画笔。

#### 在对象上绘制重复图像或图案

可使用平铺画笔在对象上绘制重复图像或图案。

若要创建平铺画笔，请首先创建图像画笔、图形画笔或视觉画笔资源。

使用图像创建图像画笔。 下图显示图像画笔、平铺的图像画笔和翻转的图像画笔。

![图像画笔](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/81f84f56-906d-456b-8288-d77da1e01e31.png?view=vs-2019) ![平铺图像画笔](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/d3782ca8-64da-47a4-a095-c6cdd0fa47a2.png?view=vs-2019) ![翻转图像画笔](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/38ae3691-f3f1-4a1e-82ca-c7fa164bf56e.png?view=vs-2019)

使用矢量图形（如路径或形状）创建图形画笔。 下图显示图形画笔、平铺的图形画笔和翻转的图形画笔。

![图形画笔](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/197666ac-ef57-4c5c-9779-669e991a00a5.png?view=vs-2019) ![平铺图形画笔](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/ba09cda3-4cee-40ba-b3d4-edc032158bdc.png?view=vs-2019) ![翻转图形画笔](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/15bf6021-620c-4490-9eae-086153d3f14f.png?view=vs-2019)

通过控件（如按钮）创建视觉画笔。 下图显示视觉画笔和平铺的视觉画笔。

![视觉画笔](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/fb6c90e0-153c-48fe-b563-e601beac6227.png?view=vs-2019) ![平铺视觉画笔](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/e261b99f-7d8f-4d91-bc84-19c7beccc255.png?view=vs-2019)

### 样式和模板：跨控件创建一致的外观

可以一次性设计控件的外观和行为，然后将该设计应用于其他控件，以便不必分别进行维护。

**是否应使用样式？**：如果只是想设置默认属性（如按钮的颜色），请使用样式。 即使在应用了样式之后，也可以修改控件。

**是否应使用模板？**：如果想要更改控件的结构，请使用模板。 假设将图形或徽标转换为按钮。 在向控件应用模板之后，无法修改控件。

#### 创建模板或样式

可通过两种方法创建模板。 可以将美工板上的任何对象转换为控件，也可以使模板基于现有控件。

若要将任何对象转换为控件模板，请选择对象，然后在“工具”菜单上，选择“构成控件”。

如果想要使模板基于现有控件，请选择美工板上的对象。 然后，在美工板顶部，选择痕迹导航按钮，选择“编辑模板”，然后选择“编辑副本”或“创建空白项”。

![编辑“模板”菜单](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/5ebdb33f-aad2-4c10-a328-5e8b04c56a36.png?view=vs-2019)

若要创建样式，请选择对象，在“对象”菜单上选择“编辑样式”，然后选择“编辑副本”或“创建空白项”。

- 选择“编辑副本”可从控件的默认样式或模板开始。
- 选择“创建空白项”可从头开始。

仅当编辑已创建的样式或模板时，“编辑当前形状”选项才会出现。 对于仍在使用默认系统模板的控件，它不会出现。

在“创建样式资源”对话框中，可以命名样式或模板以便可以在以后使用它，也可以将样式或模板应用于该类型的所有控件。

![“创建样式资源”对话框](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/4818ee6a-ce60-4b79-91c8-3b1871829eea.png?view=vs-2019)

> 不能为控件的每种类型都创建样式或模板。 如果控件不支持它们，则痕迹导航按钮不会出现在美工板上方。若要返回主文档编辑范围，请单击“返回范围”![返回到图标范围](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/55844eb3-ed98-4f20-aa66-a6f5b23eeb2b.png?view=vs-2019)。

#### 将样式或模板应用于控件

在[对象和时间线](https://docs.microsoft.com/zh-cn/visualstudio/designers/creating-a-ui-by-using-blend-for-visual-studio?view=vs-2019#tour-of-the-objects-and-timeline-panel)面板中右键单击某个对象，选择“编辑模板”，然后选择“应用资源”。

![“应用资源”菜单](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/dc12debc-7711-47d9-84ce-10322a384397.png?view=vs-2019)

#### 还原控件的默认样式或模板

选择控件，在[属性面板](https://docs.microsoft.com/zh-cn/visualstudio/designers/creating-a-ui-by-using-blend-for-visual-studio?view=vs-2019#tour-of-the-properties-panel)中，找到“样式”或“模板”属性。 选择“高级选项”，然后在快捷菜单上单击“重置”。

### 可视状态：根据控件状态更改其外观

控件可以基于用户交互而具有不同的视觉外观。 例如，可以在用户单击时使按钮变为绿色，也可以运行动画。 可使用过渡缩短或延长可视状态之间的时间。

![鼠标悬停状态](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/a95c671a-5639-40b9-83db-1e6b214330d5.png?view=vs-2019)

**观看短片：**![播放按钮](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/bldadminconsoleinitialconfigicon.png?view=vs-2019) [管理 WPF 控件的状态](https://www.youtube.com/watch?v=m0PlkF5i6uw)。

### 资源：创建颜色、样式和模板，并在以后重复使用它们

可以将项目中的几乎所有对象转换为资源。 资源只是可以在应用程序中的不同位置重复使用的对象。 例如，可以一次性创建一种颜色，使它成为资源，然后在多个对象上使用该颜色。 若要更改所有这些对象的颜色，只需更改该颜色资源。

![将颜色转换为资源按钮](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/89203705-cf66-46e0-b153-52a23cd744f7.png?view=vs-2019) ![“创建颜色资源”对话框](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/6bff8b19-3cd5-41a0-bbf9-ff65532d5aae.png?view=vs-2019)

## [Animate objects](https://docs.microsoft.com/en-us/visualstudio/designers/animate-objects-in-xaml-designer?view=vs-2019)

可以创建移动对象或使它们淡入和淡出的简短动画。

若要开始，请创建 *情节提要*。 情节提要包含一个或多个 *时间线*。 在时间线上设置 *关键帧* 以标记属性更改。 随后在运行动画时，Blend 将在指定时间段内插入属性更改。 这样便可实现平滑过渡。 可以对属于对象的任何属性（甚至非可视属性）进行动画处理。

下图显示了一个名为“MoveUp” 的情节提要。 时间线包含标记矩形的 X 和 Y 位置的关键帧。 当此动画运行时，矩形平滑地从一个位置移动到另一个位置。

![XAML 设计器中的 MoveUp 情节提要](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/982f031a-74a3-414a-abc2-a0f41a741075.png?view=vs-2019)

## [Display data](https://docs.microsoft.com/en-us/visualstudio/designers/display-data-in-blend?view=vs-2019)

自定义页面的布局时，可以在设计器中查看示例数据。 可以从头开始或使用现有类生成示例数据。 也可以连接到在连接到应用时出现在应用中的实时数据。

### 生成示例数据

若要生成示例数据，请打开 XAML 文档。 在“数据”面板中，选择“创建示例数据”![创建示例数据](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/30540d76-7256-43ce-b5d9-4b2edf3d339f.png?view=vs-2019)按钮，然后选择“新建示例数据”。

在“数据” 面板中定义数据的结构，然后将它绑定到任何页面上的 UI 元素。

![数据面板](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/496d7ebc-fe46-42f6-95a8-57b0e5be5d49.png?view=vs-2019)

如果希望示例数据在运行该应用程序时出现在页面中，则选择“数据源选项”![数据源选项图标](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/ae1fd260-4f84-420d-b196-45fde357d81d.png?view=vs-2019)，然后选择“运行应用程序时启用”。

![“在运行应用程序时启用”菜单项](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/05d5356d-91bb-4e6b-b3f7-29b76852c4b3.png?view=vs-2019)

**观看短片：**![播放图标](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/bldadminconsoleinitialconfigicon.png?view=vs-2019) [从头开始创建示例数据](http://www.bing.com/videos/search?q=blend%20data&qs=n&form=QBVR&pq=blend%20data&sc=8-7&sp=-1&sk=#view=detail&mid=F8F2449A76956D480FD2F8F2449A76956D480FD2)。

**观看短片：**![播放图标](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/bldadminconsoleinitialconfigicon.png?view=vs-2019) [将一些数据绑定与 Blend 混合](https://www.youtube.com/watch?v=LSwPB6CAvjg)。

### 从类生成示例数据

如果已创建了描述数据结构的类，则可以从这些类生成示例数据。

若要从类生成示例数据，请打开一个 XAML 文档，然后在“数据”面板中，单击“创建示例数据”![创建示例数据图标](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/30540d76-7256-43ce-b5d9-4b2edf3d339f.png?view=vs-2019)按钮，然后单击“从类创建示例数据”。

**观看短片：**![播放图标](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/bldadminconsoleinitialconfigicon.png?view=vs-2019) [从类开始创建示例数据](https://channel9.msdn.com/Shows/Inside+Windows+Phone/IWP54--Windows-Phone-Data-Binding-and-the-Magic-of-XAML)。

**观看短片：**![播放图标](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/bldadminconsoleinitialconfigicon.png?view=vs-2019) [将一些数据绑定与 Blend 混合](https://www.youtube.com/watch?v=LSwPB6CAvjg)。

### 在 WPF 应用程序中显示实时数据

**观看短片：**![播放图标](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/bldadminconsoleinitialconfigicon.png?view=vs-2019) [创建 XML 数据源](https://www.youtube.com/watch?v=RjQueappjqk&feature=youtube_gdata)。

### 在应用商店或 Phone 应用中显示实时数据

请参阅[使用数据和文件 (XAML)](https://docs.microsoft.com/zh-cn/previous-versions/windows/apps/br229562(v=win.10))。

## [Keyboard shortcuts and modifier keys](https://docs.microsoft.com/en-us/visualstudio/designers/keyboard-shortcuts-and-modifier-keys-in-blend?view=vs-2019)

通过使用键盘快捷方式，你需要多次单击鼠标按钮完成的操作只需按一次键盘快捷方式即可完成，从而可加快你的工作速度。 Blend for Visual Studio 中的键盘快捷方式分为以下两种类别：

- 访问键 可以使用访问键，即通过按键盘上的特定键来访问菜单命令或对话框中的某个区域。 访问键由当前选定命令或对话框中显示的下划线标识。

  若要使用访问键，请先按 Alt 或 F10 以显示下划线，然后按特定菜单项或对话框项的对应字母。 或者，可以通过使用 Tab 键或箭头键在菜单或对话框中导航。 例如，如果在 Blend 中按 Alt，则“文件”菜单中的字母“F”下会出现下划线，以将其标识为访问键。 若要打开项目，你可以按住 Alt，按 F，然后按 O。

  ![访问键](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/441d5d67-48ee-4ba3-9e55-1826167e8d64.png?view=vs-2019)

- 快捷键 可以使用快捷键，即通过按键盘快捷方式来执行操作（例如选择菜单命令或修改工具的行为）。

  大多数键盘快捷方式都可以轻松地在 Blend 的用户界面中确定；它们显示在菜单命令的右边。 例如，在“文件”菜单上，“打开项目”菜单命令包括键盘快捷键 Ctrl+Shift+O。 要查看“工具”面板中的工具的快捷键，请将鼠标指针悬停在工具的上方。

  ![示例快捷键](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/f147fc85-9fc5-4e8a-8039-bead80a3e595.png?view=vs-2019)

有关辅助功能和其他功能的详细信息，请参阅 [Microsoft 辅助功能](http://go.microsoft.com/fwlink/?LinkId=75069)。

### 修改键

某些键盘快捷方式没有关联的菜单项，这意味着你无法使用 Blend 用户界面来发现这些键盘快捷方式。 以下主题列出了用于修改工具行为或修改操作（例如重设对象大小）的快捷方式：

- [“美工板”修改键](https://docs.microsoft.com/zh-cn/visualstudio/designers/artboard-modifier-keys-in-blend?view=vs-2019)
- [“笔”工具修改键](https://docs.microsoft.com/zh-cn/visualstudio/designers/pen-tool-modifier-keys-in-blend?view=vs-2019)
- [“路径选择”工具修改键](https://docs.microsoft.com/zh-cn/visualstudio/designers/direct-selection-tool-modifier-keys-in-blend?view=vs-2019)

### [Keyboard shortcuts](https://docs.microsoft.com/en-us/visualstudio/designers/keyboard-shortcuts-in-blend?view=vs-2019)

### 项目快捷方式

| 任务                           | 操作步骤         |
| ------------------------------ | ---------------- |
| 创建新项目                     | Ctrl+Shift+N     |
| 打开项目或解决方案（不是站点） | Ctrl+Shift+O     |
| 关闭解决方案                   | Ctrl + Shift + C |
| 保存解决方案或站点的副本       | Ctrl+Shift+P     |
| 将现有项添加到项目             | Ctrl+I           |
| 添加对 DLL 的引用 (WPF)        | Alt+Shift+R      |
| 生成项目                       | Ctrl+Shift+B     |
| 测试项目或站点                 | **F5**           |

### 文档快捷方式

| 任务                                                         | 操作步骤                 |
| ------------------------------------------------------------ | ------------------------ |
| 在打开的文档之间切换                                         | Ctrl + Tab               |
| 保存活动文档                                                 | Ctrl + S                 |
| 保存所有文档                                                 | Ctrl + Shift + S         |
| 关闭活动文档                                                 | **Ctrl**+**W**           |
| 关闭所有打开的文档                                           | **Ctrl**+**Shift**+**W** |
| 撤消上一项操作                                               | Ctrl+Z                   |
| 重做上一次撤消的操作                                         | Ctrl+Y 或 Ctrl+Shift+Z   |
| 创建设计时注释                                               | Ctrl+Shift+T             |
| 剪切                                                         | Ctrl+X                   |
| 复制                                                         | Ctrl+C                   |
| 粘贴                                                         | Ctrl+V                   |
| 删除                                                         | **删除**                 |
| 查找文本（仅限于 XAML 视图或 JavaScript 编辑器）             | Ctrl+F                   |
| 查找文本的下一个匹配项（仅限于 XAML 视图或 JavaScript 编辑器） | F3 或 Ctrl+H             |

### 对象快捷方式

| 任务                         | 操作步骤                       |
| ---------------------------- | ------------------------------ |
| 创建新项目                   | Ctrl + N                       |
| 复制对象                     | 按住 Alt 并拖动对象            |
| 将对象重新定义为父项         | 将对象拖到版式面板上，并按 Alt |
| 编辑控件中的文本             | F2（按 Esc 退出）              |
| 编辑控件 (WPF)               | Ctrl+E                         |
| 使选定对象的宽度相同         | Ctrl+Shift+1                   |
| 使选定对象的高度相同         | Ctrl+Shift+2                   |
| 使选定对象的大小相同         | Ctrl+Shift+9                   |
| 水平翻转选定对象             | Ctrl+Shift+3                   |
| 垂直翻转选定对象             | Ctrl+Shift+4                   |
| 选择多个对象                 | 按住 Ctrl                      |
| 选择多个相邻的对象           | 按住 Shift                     |
| 调整所选内容以适合屏幕大小   | Ctrl+9                         |
| 固定活动容器                 | Ctrl+Shift+D                   |
| 微移选定对象                 | 箭头键                         |
| 自动调整宽度                 | Ctrl+Shift+5                   |
| 自动调整高度                 | Ctrl+Shift+6                   |
| 将对象组合到布局面板中       | Ctrl+G                         |
| 取消组合对象                 | Ctrl+Shift+G                   |
| 将选定对象置于顶层           | Ctrl+Shift+]                   |
| 上移一层                     | Ctrl+]                         |
| 将所选定象发送到后面         | Ctrl+Shift+[                   |
| 下移一层                     | Ctrl+[                         |
| 从选定对象生成用户控件 (WPF) | **F8**                         |
| 约束对象的比例               | 拖动对象时按住 Shift           |
| 按 15 度的增量旋转对象       | 旋转对象时按住 Shift           |
| 生成剪切路径                 | Ctrl+7                         |
| 释放剪切路径                 | Ctrl+Shift+7                   |
| 生成复合路径                 | Ctrl+8                         |
| 释放复合路径                 | Ctrl+Shift+8                   |
| 锁定选定内容                 | Ctrl + L                       |
| 解除对所有对象的锁定         | Ctrl+Shift+L                   |
| 显示选定内容                 | Ctrl + T                       |
| 隐藏选定内容                 | Ctrl+3                         |
| 选择所有对象                 | Ctrl+A                         |
| 取消选择所有对象             | Ctrl+Shift+A                   |

### 视图快捷方式

| 任务                                     | 操作步骤                  |
| ---------------------------------------- | ------------------------- |
| 在“设计”、“代码”和“拆分”视图之间进行切换 | F11                       |
| 在美工板上放大                           | Ctrl+等于号 (=)           |
| 在美工板上缩小                           | Ctrl+减号 (-)             |
| 在美工板上放大或缩小                     | 旋转鼠标滚轮              |
| 将美工板左移或右移                       | 按住 Shift 并旋转鼠标滚轮 |
| 将美工板上移或下移                       | 按住 Ctrl 并旋转鼠标滚轮  |
| 调整所选内容以适合屏幕大小               | Ctrl+0                    |
| 以实际大小查看美工板                     | Ctrl+1                    |
| 显示或隐藏句柄                           | **F9**                    |
| 显示或隐藏对象边界                       | Ctrl+Shift+H              |
| 在“设计”、“XAML”和“拆分”视图之间进行切换 | F11                       |

### 工作区快捷方式

| 任务                                                 | 操作步骤     |
| ---------------------------------------------------- | ------------ |
| 在“动画”和“设计”工作区之间进行切换                   | Ctrl+F11     |
| 显示或隐藏“资产”面板                                 | Ctrl+句点    |
| 显示或隐藏“结果”面板                                 | **F12**      |
| 显示或隐藏所有面板                                   | F4           |
| 重置活动工作区布局                                   | Ctrl+Shift+R |
| 平移工作区                                           | 按住空格键   |
| 临时使用“选择”工具（在其他工具处于选定状态的情况下） | 按住 Ctrl    |

### [Artboard modifier keys](https://docs.microsoft.com/en-us/visualstudio/designers/artboard-modifier-keys-in-blend?view=vs-2019)

某些键盘快捷方式没有关联的菜单项，这意味着你无法使用 Blend 用户界面来发现这些键盘快捷方式。 下表列出了修改操作（例如调整对象的大小）的快捷方式。

| 任务                                                         | 操作步骤                                       |
| ------------------------------------------------------------ | ---------------------------------------------- |
| 在选择其他工具的同时，暂时选中“选择”工具。此操作可减少你在“工具”面板中单击的次数，以及在“选择”工具和其他内容间来回切换的次数） | 按住 Ctrl                                      |
| 选中“选择”工具时微移所选对象                                 | 按箭头键                                       |
| 平移美工板                                                   | 按住空格键并拖动美工板                         |
| 在美工板上放大和缩小                                         | 旋转鼠标滚轮                                   |
| 在美工板上放大                                               | 单击美工板上的任意位置时按住 Ctrl+空格键       |
| 在美工板上缩小                                               | 单击美工板上的任意位置时按住 Ctrl+Alt+空格键   |
| 将美工板左移和右移                                           | 按住 Shift 并滚动鼠标滚轮                      |
| 将美工板上移和下移                                           | 按住 Ctrl 并滚动鼠标滚轮                       |
| 约束要绘制或转换的对象比例                                   | 按住 Shift                                     |
| 按 15 度的增量旋转对象                                       | 按住 Shift                                     |
| 复制对象                                                     | 按住 Alt 并拖动对象                            |
| 将对象重新定义为父项                                         | 将对象拖到版式面板上，在松开鼠标按钮前按住 Alt |
| 选择多个对象                                                 | 在选择每个对象时按住 Ctrl                      |
| 选择多个相邻的对象                                           | 选择第一个和最后一个对象时按住 Shift           |
| 通过绘制字幕进行选择                                         | 按住 Shift 并拖动                              |
| 选择另一个对象下面的对象                                     | 按住 Alt 并单击每个对象层一次                  |
| 在打开的文档之间切换                                         | 按 Ctrl+Tab                                    |
| 打开“资产”面板                                               | 按 Ctrl+句点                                   |

### [Pen tool modifier keys](https://docs.microsoft.com/en-us/visualstudio/designers/pen-tool-modifier-keys-in-blend?view=vs-2019)

下表列出了在使用“笔”工具 ![笔工具](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/d514358f-185a-412f-a55d-36633b25dc8a.png?view=vs-2019) 创建路径时可用于修改此路径的快捷方式。 “笔”工具还可用于在现有路径上添加或删除点，或联接两个现有路径。

| 任务                                                       | 操作步骤                                                     | 指针                                                         |
| ---------------------------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 创建一个点来开始绘制直线线段                               | 单击以创建新点                                               | ![创建一个点来开始绘制直线线段](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/0bfb1b71-80ac-4ad4-aed8-40e09f8b7ab8.png?view=vs-2019)  “钢笔”指针 |
| 创建一个点来开始绘制曲线线段                               | 单击以创建新点，然后在松开鼠标按钮前拖动以调整切线图柄       | ![创建一个点来开始绘制曲线线段](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/0bfb1b71-80ac-4ad4-aed8-40e09f8b7ab8.png?view=vs-2019)  “钢笔”指针 |
| 在没有平滑限制的情况下调整最后的切线，使您生成尖锐的角     | 单击以创建新点，然后在松开鼠标按钮前按 Alt                   | ![在没有平滑限制的情况下调整最后一根切线](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/317e5475-b70c-489f-9477-110a98639ade.png?view=vs-2019)  “钢笔”调整指针 |
| 拆分最后一个切线，以便切线终结点独立操作，使您生成尖锐的角 | 单击以创建新点，然后在松开鼠标按钮前按住 Alt 并拖动          | ![拆分最后一根切线，使切线终点独立存在](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/317e5475-b70c-489f-9477-110a98639ade.png?view=vs-2019)  “钢笔”调整指针 |
| 以 15 度的增量将切线终结点绕新点移动                       | 单击以创建新点，然后在松开鼠标按钮前按住 Shift+Alt 并拖动    | ![以 15 度的增量将切线终结点绕新点移动](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/317e5475-b70c-489f-9477-110a98639ade.png?view=vs-2019)  “钢笔”调整指针 |
| 将一个终结点处的切线减小为零长度                           | 单击该终结点                                                 | ![将一个终结点处的切线减小为零长度](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/317e5475-b70c-489f-9477-110a98639ade.png?view=vs-2019)  “钢笔”调整指针 |
| 向现有路径添加新点                                         | 单击您需要新点的位置处的路径                                 | ![向现有路径添加新点](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/b004ad5a-33a4-46ae-81c0-20be0d819332.png?view=vs-2019)  “钢笔”插入指针 |
| 从路径删除一个点                                           | 悬浮在现有点上并单击                                         | ![img](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/08a64b78-f3df-4730-8169-c56b5631b071.png?view=vs-2019)  “钢笔”删除指针 |
| 结束具有尖锐角的路径                                       | 单击起始点                                                   | ![从路径删除一个点](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/a12fd3b4-a553-4762-b01c-c35efa594362.png?view=vs-2019)  “钢笔”结束指针 |
| 结束边角处具有平滑曲线的路径                               | 单击起始点并在松开鼠标按钮前拖动以修改切线图柄               | ![结束边角处具有平滑曲线的路径](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/a12fd3b4-a553-4762-b01c-c35efa594362.png?view=vs-2019)  “钢笔”结束指针 |
| 在联接两个路径时创建尖锐的角                               | 选择两个路径，单击“笔”工具，并单击其中一个路径的终结点，然后单击另一路径的终结点 | ![在联接两个路径时创建尖锐的角](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/bd12dfa4-112e-4f37-9765-3479e6b69894.png?view=vs-2019)  “钢笔”联接指针 |
| 在联接两个路径时创建平滑的角                               | 选择两个路径，单击“笔”工具，并单击其中一个路径的终结点，然后拖动另一路径的终结点 | ![在联接两个路径时创建平滑的角](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/bd12dfa4-112e-4f37-9765-3479e6b69894.png?view=vs-2019)  “钢笔”联接指针 |
| 创建一个新路径                                             | 按住 Ctrl 并在前一路径外单击以停止向前一路径添加点，然后单击或拖动新路径开始的位置 | ![创建一个新路径](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/69758176-5f53-465b-808c-f13fd1a0b3f2.png?view=vs-2019)  “钢笔”开始指针 |

### [Direct selection tool modifier keys](https://docs.microsoft.com/en-us/visualstudio/designers/direct-selection-tool-modifier-keys-in-blend?view=vs-2019)

下表列出了在使用“路径选择”工具 ![Direct selection tool](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/6dd6571f-c116-451d-8dd2-1f88b8406362.png?view=vs-2019) 修改现有路径形状时可使用的快捷方式。 要在现有路径上添加或删除点，或联接两个现有路径，请使用“钢笔”工具。

| 任务                                                         | 操作步骤                                                     | 指针                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 为路径上的某个点显示切线图柄                                 | 单击路径上的某个点                                           | ![为路径上的某个点显示切线图柄](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/cfcc5f41-a666-4524-a958-50b9051130ca.png?view=vs-2019)  移动点指针 |
| 移动路径上的某个点                                           | 拖动路径上的某个点                                           | ![移动路径上的某个点](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/cfcc5f41-a666-4524-a958-50b9051130ca.png?view=vs-2019)  移动点指针 |
| 为路径上两个点之间的线段显示切线图柄                         | 单击路径的一个线段                                           | ![为路径上两个点之间的线段显示切线图柄](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/2ace930f-98fa-410b-92cf-7a4b88503ee7.png?view=vs-2019)  移动线段指针 |
| 移动路径上两个点之间的线段                                   | 拖动路径的一个线段                                           | ![移动路径上两个点之间的线段](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/2ace930f-98fa-410b-92cf-7a4b88503ee7.png?view=vs-2019)  移动线段指针 |
| 更改路径上某点的切线角度                                     | 单击路径的某个点或某个线段以显示切线图柄，然后拖动切线的一个终结点 | ![img](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/beb1a907-1e50-450c-aab3-4d7026f5e426.png?view=vs-2019)  移动切线指针 |
| 使点变为尖锐的角或将切线长度减小为零                         | 在某个点上悬浮，按住 Alt，然后单击该点                       | ![使点变为尖锐的角或将切线长度减小为零](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/21197b10-aba4-4a9d-8145-647d0ba8e518.png?view=vs-2019)  转换点指针 |
| 使任何尖锐的角变平滑（或如果已经是平滑的，当指针经过单击的点时更改曲线的角度） | 在某个点上悬浮，按住 Alt，然后拖动该点                       | ![使任何尖锐的角变平滑](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/21197b10-aba4-4a9d-8145-647d0ba8e518.png?view=vs-2019)  转换点指针 |
| 将曲线线段变为直线                                           | 在路径中的某个线段上悬浮，按住 Alt，然后单击该线段           | ![将曲线线段变为直线](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/975a855a-8536-441f-97ed-2f1496e416bf.png?view=vs-2019)  转换线段指针 |
| 取一个线段并将其弯曲为曲线以经过指针位置                     | 在路径中的某个线段上悬浮，按住 Alt，然后拖动该线段           | ![取一个线段并将其弯曲为曲线以经过指针位置](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/975a855a-8536-441f-97ed-2f1496e416bf.png?view=vs-2019)  转换线段指针 |
| 独立调整切线的一端                                           | 直接选择一个点或线段，按住 Alt，然后拖动切线终结点           | ![独立调整切线的一端](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/923951da-4081-4f8b-bebc-0f1f64d87504.png?view=vs-2019)  转换切线指针 |

## [Accessibility products and services for Blend](https://docs.microsoft.com/en-us/visualstudio/designers/accessibility-products-and-services-blend?view=vs-2019)

Microsoft 致力于让每位用户可以更便捷地使用其产品和服务。 以下各节提供有关使得残障人士更易访问 Microsoft Windows 的功能、产品和服务的信息：

- Windows 辅助功能
- 替代格式的文档
- 针对有听力障碍人士的客户服务
- 更多相关信息

> 本节中的信息仅适用于美国境内获得 Microsoft 产品许可证的用户。 如果你在美国之外获得本产品，可以使用软件包附带的分公司信息卡，也可以访问 [Microsoft 辅助功能站点](http://go.microsoft.com/fwlink/?LinkID=75069)，以获取 Microsoft 支持服务电话号码和地址的列表。 你可以与当地的分公司联系，了解你所在的地区是否供应本节中描述的产品和服务类型。 有关辅助功能的信息有其他语言版本，包括日语和法语。

### Windows 辅助功能

Windows 操作系统具备许多内置辅助功能，这些功能适用于不便打字或使用鼠标、失明或视力较差，或者失聪或具有听力障碍的人群。 安装时将安装这些功能。 有关这些功能的详细信息，请参阅 Windows 中的“帮助”和 [Microsoft 辅助功能站点](http://go.microsoft.com/fwlink/?LinkID=75069)。

#### 免费分步教程

Microsoft 提供了一系列分步教程，这些教程提供了有关如何调整计算机上的辅助功能选项和设置的详细过程。 此信息以并行格式提供，以便你能够了解如何使用鼠标和/或键盘。

若要查找 Microsoft 产品的分步教程，请参阅 [Microsoft 辅助功能站点](http://go.microsoft.com/fwlink/?LinkID=75069)。

#### Windows 辅助技术产品

提供各种辅助技术产品以便残障人士更方便地使用计算机。 你可以在 [Microsoft 辅助功能站点](http://go.microsoft.com/fwlink/?LinkID=75069)上搜索在 Windows 上运行的辅助性技术产品的目录。

如果使用辅助技术，请务必在升级软件或硬件之前与辅助技术供应商联系，以检查是否存在可能的兼容性问题。

### 替代格式的文档

如果你有阅读困难或难以处理印刷材料，可以获取许多 Microsoft 产品的更易于访问的格式的文档。 你可以在 [Microsoft 辅助功能站点](http://go.microsoft.com/fwlink/?LinkID=75069)上查看辅助产品文档的索引。

此外，还可以从 Blind & Dyslexic, Inc (RFB&D) 获得其他的 Microsoft 出版物。 RFB&D 将这些文档分发给已注册使用其分发服务的合格成员。 有关 Microsoft 产品文档和 Microsoft 出版社所出版书籍的提供情况信息，请联系：

**了解 Ally**

20 Roszel Road

Princeton, NJ 08540

美国境内电话号码：(800) 221-4792

美国及加拿大境外电话号码：(609) 452-0606

传真：(609) 987-8116

[了解 Ally 网站](http://go.microsoft.com/fwlink/?LinkId=111110)

Web 地址可能会有所更改，因此你可能无法连接此处提及的站点。

### 针对有听力障碍人士的客户服务

如果您有听力障碍，可以通过文本电话 (TTY/TDD) 服务来了解 Microsoft 产品和客户服务：

有关客户服务，请拨打 (800) 892-5234 与 Microsoft Sales Information Center 联系，服务时间为星期一到星期五太平洋时间上午 6:30 至下午 5:30（节假日除外）。

有关美国国内技术协助，请拨打 (800) 892-5234 与 Microsoft 产品支持服务联系，服务时间为星期一到星期五太平洋时间上午 6:00 至下午 6:00（节假日除外）。 在加拿大，请拨打 (905) 568-9641，服务时间为星期一到星期五东部时间上午 8:00 至下午 8:00（节假日除外）。

Microsoft 支持服务受使用服务时实施的价格、条款和条件约束。