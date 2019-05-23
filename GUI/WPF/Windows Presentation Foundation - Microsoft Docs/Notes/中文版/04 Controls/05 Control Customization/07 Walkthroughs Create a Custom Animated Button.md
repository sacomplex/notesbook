# [Walkthroughs: Create a Custom Animated Button](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/walkthroughs-create-a-custom-animated-button)

顾名思义，Windows Presentation Foundation (WPF) 非常适合的客户进行丰富的表示体验。 这些演练演示了如何自定义的外观和行为 （包括动画） 的按钮。 此自定义完成，以便你可以应用此自定义按钮轻松于任何按钮在你的应用程序中使用的样式和模板。 下图显示的自定义的按钮，你将要创建。

![你将创建的自定义的按钮](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-intro.jpg)

通过使用创建构成该按钮的外观的向量图形可扩展应用程序标记语言 (XAML)。 XAML 它是更功能强大且可扩展除外，则是类似于 HTML。 可扩展应用程序标记语言 (XAML) 可以键入中手动使用 Microsoft Visual Studio 或记事本，或者可以使用 Microsoft Expression Blend 等 visual 设计工具。 Expression Blend 工作方式是创建基础XAML代码，因此这两种方法创建相同的图形。

## 本节内容

[使用 Microsoft Expression Blend 创建按钮](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/walkthrough-create-a-button-by-using-microsoft-expression-blend)
演示如何通过使用设计器功能的 Expression Blend 创建具有自定义行为的按钮。

[使用 XAML 创建按钮](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/walkthrough-create-a-button-by-using-xaml)
演示如何创建按钮与自定义行为通过使用XAML和 Visual Studio。

## 相关章节

[样式设置和模板化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/styling-and-templating)
介绍如何使用样式和模板来确定的外观和行为的控件。

[动画概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/animation-overview)
描述了可以如何在使用动态显示对象WPF动画和时间系统。

[使用纯色和渐变进行绘制概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/painting-with-solid-colors-and-gradients-overview)
描述如何使用画笔对象用纯色、 线性渐变和径向渐变进行绘制。

[位图效果概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/bitmap-effects-overview)
介绍支持的位图效果WPF并说明如何将其应用。

## [Create a Button by Using Microsoft Expression Blend](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/walkthrough-create-a-button-by-using-microsoft-expression-blend)

本演练将引导你完成创建过程WPF使用 Microsoft Expression Blend 的自定义的按钮。

> Microsoft Expression Blend 的工作原理是生成可扩展应用程序标记语言 (XAML)然后编译以使可执行程序。如果使用中而不是所起的作用可扩展应用程序标记语言 (XAML)直接，没有创建一个使用此条件的应用程序的另一个演练可扩展应用程序标记语言 (XAML)与 Visual Studio 而不是 Blend。 请参阅[创建一个按钮通过使用 XAML](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/walkthrough-create-a-button-by-using-xaml)有关详细信息。

下图显示了您将创建的自定义的按钮。

![您将创建的自定义的按钮](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-intro.jpg)

### 将形状转换为一个按钮

在本演练的第一部分创建的自定义按钮的自定义外观。 若要执行此操作，您首先将一个矩形成一个按钮。 您将添加其他形状到模板的按钮，创建更复杂的美观按钮。 为什么不使用常规按钮启动和自定义它？ 因为一个按钮具有内置功能，您不需要;对于自定义按钮，它是更轻松地开始一个矩形。

#### 若要在 Expression Blend 中创建新项目

1. 开始在 Expression Blend。 (单击**启动**，依次指向**所有程序**，指向**Microsoft Expression**，然后单击**Microsoft Expression Blend**。)
2. 如果需要最大化应用程序。
3. 在“文件”菜单上，单击“新建项目”。
4. 选择**标准应用程序 (.exe)**。
5. 将项目命名`CustomButton`并按**确定**。

此时您已具有一个空WPF项目。 可以按 F5 运行该应用程序。 正如您所料，此应用程序包含一个空白的窗口。 接下来，创建一个圆角的矩形，并将其转换为一个按钮。

#### 若要将一个矩形转换为一个按钮

1. **窗口背景属性设置为黑色：** 选择该窗口中，单击**属性选项卡**，并设置[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)属性设置为`Black`。

   ![如何将按钮的背景设置为黑色](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-changebackground.png)

2. **窗口上绘制一个矩形大小与按钮：** 选择左侧的工具面板上的矩形工具并将该矩形拖到窗口。

   ![如何绘制一个矩形](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-drawrect.png)

3. **为圆角矩形：** 拖动矩形的控点，或者直接设置[RadiusX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle.radiusx)和[RadiusY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle.radiusy)属性。 设置的值[RadiusX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle.radiusx)和[RadiusY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle.radiusy)为 20。

   ![如何使矩形的角倒圆角](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-roundcorners.png)

4. **将矩形更改为一个按钮：** 选择该矩形。 上**工具**菜单上，单击**使按钮**。

   ![如何使形状变为按钮](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-makebutton.png)

5. **指定样式模板的作用域：** 会显示如下所示的对话框。

   !["创建样式资源"对话框](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-makebutton2.gif)

   有关**资源名称 （键）**，选择**应用到所有**。 这将使生成的样式和应用于所有对象的按钮的按钮模板。 有关**中定义**，选择**应用程序**。 这将使生成的样式和按钮模板的范围涵盖整个应用程序。 当这两个框中设置的值，在按钮样式和模板应用于整个应用程序中的所有按钮，创建应用程序中任何按钮将默认情况下，使用此模板。

### 编辑按钮模板

你现在有一个已更改为一个按钮的矩形。 在本部分中，将修改的按钮模板并进一步自定义其外观。

#### 若要编辑要更改按钮外观的按钮模板

1. **请转到编辑模板视图：** 若要进一步自定义按钮的外观，我们需要编辑按钮模板。 此模板创建时我们转换成一个按钮的矩形。 若要编辑的按钮模板，右键单击该按钮，然后选择**编辑控件部件 （模板）** ，然后**编辑模板**。

   ![如何编辑模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-edittemplate.jpg)

   在模板编辑器中，请注意，现在分为按钮[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)和[ContentPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter)。 [ContentPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter)用于呈现按钮 （例如，字符串"Button"） 中的内容。 这两个矩形并[ContentPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter)内的布局[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)。

   ![组件中的矩形的演示文稿](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-templatepanel.png)

2. **更改模板组件的名称：** 右键单击在模板清单，更改矩形[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)名称从"[Rectangle]"到"outerRectangle"，并将"[ContentPresenter]"更改为"myContentPresenter"。

   ![如何重命名模板的组件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-renamecomponents.png)

3. **Alter 矩形，使其为空内 （如一个圆环图）：** 选择**outerRectangle**并设置[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)为"透明"和[StrokeThickness](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.strokethickness)为 5。

   ![如何使矩形为空](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-changerectproperties.png)

   然后设置[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.stroke)该模板将在任何内容的颜色。 若要执行此操作，请单击小白色框旁边**笔划**，选择**CustomExpression**，并在对话框中键入"{TemplateBinding 后台}"。

   ![如何设置使用的模板的颜色](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-templatestroke.png)

4. **创建一个内部矩形：** 现在，创建另一个矩形 （名称"innerRectangle"） 并将其定位对称的内部**outerRectangle** 。 对于此类型的工作，可能需要放大以使该按钮编辑区域在更大。

   > 在矩形可能看起来比图中的一个不同 （例如，它可能会有了圆形角）。

   ![如何创建一个矩形内另一个矩形](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-innerrectangleproperties.png)

5. **将 ContentPresenter 移到顶部：** 此时，就可以文本"Button"才能不再可见。 如果该条件，否则这是因为**innerRectangle**之上**myContentPresenter**。 若要解决此问题，拖动**myContentPresenter**如下**innerRectangle**。 重新定位矩形并**myContentPresenter** ，看起来像下面。

   > 或者，您可以定位**myContentPresenter**通过右键单击它并按顶部**转发发送**。

   ![如何移动一个按钮在另一个按钮之上](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-innerrectangle2.png)

6. **更改 innerRectangle 的外观：** 设置[RadiusX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle.radiusx)， [RadiusY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle.radiusy)，和[StrokeThickness](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.strokethickness)值为 20。 此外，设置[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)到后台，使用自定义表达式"{TemplateBinding 后台}"的模板) 并设置[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.stroke)"透明"。 请注意，设置[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)并[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.stroke)的**innerRectangle**那些与相对**outerRectangle**。

   ![如何更改矩形的外观](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-glassrectangleproperties1.png)

7. **在最前面添加玻璃层：** 自定义按钮的外观的最后一部分是在最前面添加玻璃层。 此平台层由第三个矩形构成。 玻璃矩形玻璃将涵盖整个按钮，因为是在维度与类似**outerRectangle**。 因此，创建矩形，从而只需一份**outerRectangle**。 突出显示**outerRectangle** ，并使用 CTRL + C 和 CTRL + V 制作副本。 命名此新矩形"glassCube"。

8. **如有必要，重新定位 glassCube:** 如果**glassCube**是尚不存在定位，以便它涵盖了整个按钮，将其拖至相应位置。

9. **为 glassCube 提供比 outerRectangle 略有不同的形状：** 更改的属性**glassCube**。 首先，更改[RadiusX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle.radiusx)并[RadiusY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle.radiusy)属性设置为 10 和[StrokeThickness](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.strokethickness)为 2。

   ![GlassCube 的外观设置](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-glasscubeappearance.gif)

10. **请看起来像玻璃 glassCube:** 设置[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)到玻璃介绍通过使用线性渐变的 75%不透明和之间交替颜色白色和透明超过 6 大约均匀分布的时间间隔。 这是要设置为梯度停止点：

    - 梯度停止点 1:Alpha 值为 75%的白色
    - 梯度停止点 2:透明
    - 梯度停止点 3:Alpha 值为 75%的白色
    - 梯度停止点 4:透明
    - 梯度停止点 5:Alpha 值为 75%的白色
    - 梯度停止点 6:透明

    这将创建"波浪"玻璃外观。

    ![看起来像玻璃的矩形](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-glassrectangleproperties2.png)

11. **隐藏玻璃层：** 现在，您看到玻璃层如下所示，请转到**外观窗格**的**属性面板**和不透明度设置为 0%，以将其隐藏。 在以下各部分，我们将使用属性触发器和事件来显示和操作玻璃层。

    ![如何隐藏玻璃矩形](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-glassrectangleproperties3.gif)

### 自定义按钮行为

此时，已通过编辑其模板自定义按钮的演示文稿，但该按钮不响应用户操作作为典型的按钮执行操作 （例如，更改在鼠标悬停时的外观，接收焦点，然后单击。）接下来两个过程演示如何构建类似这样到自定义按钮的行为。我们将使用简单的属性触发器启动，然后添加事件触发器和动画。

#### 若要设置属性触发器

1. **创建新的属性触发器：** 与**glassCube**处于选中状态，单击 **+ 属性**中**触发器**面板 （见图后面的下一步）。 这将创建具有默认属性触发器的属性触发器。

2. **请 IsMouseOver 由触发器使用的属性：** 将属性更改为[IsMouseOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ismouseover)。 这使属性触发器激活时[IsMouseOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ismouseover)属性是`true`（当用户指向使用鼠标按钮）。

   ![如何在属性上设置触发器](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-ismousedoverpropertytrigger.png)

3. **IsMouseOver 触发 glasscube 的 100%的不透明度：** 请注意，**触发器录制已打开**（请参阅上图中）。 这意味着，对的属性值进行任何更改**glassCube**录制已打开时将会发生时的操作[IsMouseOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ismouseover)是`true`。 录制时，更改[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)的**glassCube**为 100%。

   ![如何设置按钮的不透明度](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-ismousedoverpropertytrigger2.gif)

   现在已创建你的第一个属性触发器。 请注意，**触发器面板**编辑器的已记录[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)更改为 100%。

   ![“触发器”面板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-propertytriggerinfo.png)

   按 F5 以运行应用程序，并将鼠标指针移动和关闭按钮。 应会看到玻璃层时显示鼠标悬停按钮并在指针离开时消失。

4. **IsMouseOver 触发器进行描边值更改：** 让我们将一些其他操作相关联[IsMouseOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ismouseover)触发器。 尽管仍录制，切换您的选择从**glassCube**到**outerRectangle**。 然后设置[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.stroke)的**outerRectangle**到"{DynamicResource {x： 静态 SystemColors.HighlightBrushKey}}"的自定义表达式。 这将设置[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.stroke)到典型突出显示使用按钮的颜色。 按 f5 键来查看当你将鼠标置于按钮上的效果。

   ![如何将笔画设置为突出显示颜色](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-ismousedoverpropertytrigger3.png)

5. **IsMouseOver 触发模糊的文本：** 让我们将关联到一个更多操作[IsMouseOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ismouseover)属性触发器。 使玻璃出现其上方时显示有点模糊按钮的内容。 若要执行此操作，我们可以应用模糊[BitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.bitmapeffect)到[ContentPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter)(**myContentPresenter**)。

   ![如何使按钮内容变得模糊](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-propertytriggerwithbitmapeffect.png)

   > 若要返回**属性面板**回其是你之前的搜索[BitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.bitmapeffect)，清除从文本**搜索框**。

   此时，我们使用了属性触发器与多个关联的操作时将鼠标指针进入和离开按钮区域创建突出显示行为。 另一个按钮的典型行为是突出显示具有焦点时 （如后单击它）。 我们可以通过添加另一个属性触发器中添加此类行为[IsFocused](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.isfocused)属性。

6. **创建 IsFocused 属性触发器：** 使用相同的过程[IsMouseOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ismouseover)（请参阅本部分中的第一步），创建另一个属性触发器[IsFocused](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.isfocused)属性。 虽然**触发器录制已打开**，到触发器中添加下列操作：

   - **glassCube**获取[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)的 100%。
   - **outerRectangle**获取[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.stroke)"{DynamicResource {x： 静态 SystemColors.HighlightBrushKey}}"的自定义表达式值。

作为本演练的最后一步，我们将向按钮添加动画。 将由事件触发这些动画 — 具体而言，[MouseEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouseenter)和[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件。

#### 若要使用事件触发器和动画添加交互性

1. **创建 MouseEnter 事件触发器：** 添加新的事件触发器，然后选择[MouseEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouseenter)作为要在触发器中使用的事件。

   ![如何创建 MouseEnter 事件触发器](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-mouseovereventtrigger.png)

2. **创建动画时间线：** 接下来，将关联到动画时间线[MouseEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouseenter)事件。

   ![如何向事件添加动画时间线](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-mouseovereventtrigger2.png)

   按后**确定**若要创建新的时间线**时间线面板**显示，"时间线录制已打开"设计面板中。 这意味着我们可以开始 （进行动画处理属性更改） 在时间线中记录属性更改。

   > 您可能需要调整大小窗口和/或面板，以查看它们的显示。

   ![时间线面板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-mouseovereventtrigger3.png)

3. **创建关键帧：** 若要创建动画，请选择你想要进行动画处理，创建两个或多个关键帧在时间线，并在这些关键帧，设置您希望该动画之间进行内插的属性值的对象。 下图将引导您完成创建关键帧。

   ![如何创建关键帧](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-mouseovereventtrigger4.png)

4. **此关键帧处收缩 glassCube:** 所选的第二个关键帧的大小收缩**glassCube**为使用其完整大小的 90%**大小转换**。

   ![如何缩小按钮的大小](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-sizetransform.png)

   按 F5 运行该应用程序。 将鼠标指针移到按钮上方。 请注意，玻璃层会缩小按钮的顶部。

5. **创建另一个事件触发器，并将不同的动画与它相关联：** 让我们添加一个更多的动画。 使用你用于创建上一个事件触发器动画到类似的步骤：

   1. 创建新的事件触发器使用[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件。
   2. 将相关联的新时间线[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)事件。

   ![如何创建新的时间线](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-clickeventtrigger1.png)

   1. 对于此时间线，创建两个关键帧，0.0 秒时的一个，另一个位于 0.3 秒之间。
   2. 在突出显示的 0.3 秒之间的关键帧，设置**旋转变换角度**到 360 度。

   ![如何创建旋转转换](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-rotatetransform.gif)

   1. 按 F5 运行该应用程序。 单击按钮。 请注意，在玻璃层会旋转一周。

### 结束语

您已经完成了自定义的按钮。 执行此过程通过已应用到应用程序中的所有按钮的按钮模板。 如果将模板编辑模式 （请参阅下图） 并创建多个按钮，会看到它们的外观和行为类似自定义按钮而不是像默认按钮。

![自定义按钮模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-scopeup.gif)

![使用相同的模板的多个按钮](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-createmultiplebuttons.png)

按 F5 运行该应用程序。 单击的按钮，并请注意，所有的行为方式相同。

请记住，虽然您已自定义模板，您设置[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)的属性**innerRectangle**并且[Stroke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.stroke)属性**outerRectangle**到模板背景 （{TemplateBinding 后台}）。 正因为如此，当你设置的各个按钮的背景色时您设置的背景将用于这些相应的属性。 请尝试现在更改背景。 在下图中，使用不同的渐变效果。 因此，尽管模板非常有用的控件类似按钮的整体自定义项，使用模板的控件可以仍可修改看起来彼此不同。

![查找其他具有相同模板按钮](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-blend-blendconclusion.jpg)

总之，自定义按钮模板的过程中已了解如何执行以下操作在 Microsoft Expression Blend 中：

- 自定义控件的外观。
- 设置属性触发器。 属性触发器是非常有用，因为它们可以用于大多数对象，而不仅仅是控件。
- 设置事件触发器。 事件触发器是非常有用，因为它们可以用于大多数对象，而不仅仅是控件。
- 创建动画。
- 杂项： 创建渐变添加 BitmapEffects，使用转换，并设置对象的基本属性。

## [Create a Button by Using XAML](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/walkthrough-create-a-button-by-using-xaml)

本演练的目的是了解如何创建 Windows Presentation Foundation (WPF) 应用程序中使用的动画的按钮。 本演练使用样式和模板来创建自定义的按钮资源允许重用代码和从按钮声明按钮逻辑的分离。 本演练完全在编写可扩展应用程序标记语言 (XAML)。

> 本演练将指导您完成创建应用程序，通过键入或复制并粘贴步骤可扩展应用程序标记语言 (XAML)到 Microsoft Visual Studio。 如果你想要了解如何使用设计工具 (Microsoft Expression Blend) 来创建相同的应用程序，请参阅[创建一个按钮通过使用 Microsoft Expression Blend](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/walkthrough-create-a-button-by-using-microsoft-expression-blend)。

下图显示了已完成的按钮。

![通过使用 XAML 创建的自定义按钮](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-animatedbutton-5.gif)

### 创建基本按钮

让我们首先创建一个新项目并将几个按钮添加到窗口。

#### 若要创建新的 WPF 项目并将按钮添加到窗口

1. 启动 Visual Studio。

2. **创建新的 WPF 项目：** 在 **“文件”** 菜单上，指向 **“新建”**，然后单击 **“项目”**。 查找**Windows 应用程序 (WPF)**模板，并命名项目"AnimatedButton"。 这将创建应用程序的主干。

3. **添加基本的默认按钮：** 在本演练中所需的所有文件均由模板都提供。 通过双击它在解决方案资源管理器中打开 Window1.xaml 文件。 默认情况下，没有[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)在 Window1.xaml 中的元素。 删除[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)元素，并添加到了几个按钮可扩展应用程序标记语言 (XAML)通过键入或复制并粘贴到 Window1.xaml 以下突出显示的代码页：

   XAML复制

   ```xaml
   <Window x:Class="AnimatedButton.Window1"  
     xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"  
     xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"  
     Title="AnimatedButton" Height="300" Width="300"   
     Background="Black">
     <!-- Buttons arranged vertically inside a StackPanel. -->
     <StackPanel HorizontalAlignment="Left">
         <Button>Button 1</Button>
         <Button>Button 2</Button>
         <Button>Button 3</Button>
     </StackPanel>  
   </Window>  
   ```

   按 F5 运行该应用程序;您将看到类似于下图的按钮的组。

   ![三个基本按钮](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-animatedbutton-1.gif)

   现在，已创建的基本按钮，您已完成 Window1.xaml 文件中的工作。 本演练的其余部分重点介绍 app.xaml 文件中，定义样式和模板的按钮。

### 设置基本属性

接下来，让我们来设置这些按钮来控制按钮外观和布局的某些属性。 而不是单独在按钮上设置属性，将使用的资源来定义整个应用程序的按钮属性。 应用程序资源是从概念上讲类似于外部级联样式表 (CSS)网页; 但是，资源将比强大得多级联样式表 (CSS)，正如您将看到本演练结束。 若要了解有关资源的详细信息，请参阅[XAML 资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-resources)。

#### 若要使用样式按钮上设置基本属性

1. **定义 Application.Resources 块：** 打开 app.xaml 并添加以下突出显示的标记，如果尚不存在：

   XAML复制

   ```xaml
   <Application x:Class="AnimatedButton.App"  
     xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"  
     xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"  
     StartupUri="Window1.xaml"  
     >  
     <Application.Resources>
       <!-- Resources for the entire application can be defined here. -->
     </Application.Resources>  
   </Application>  
   ```

   您在其中定义资源取决于资源范围。 定义中的资源`Application.Resources`在 app.xaml 文件，要使用从任意位置的应用程序中的资源。 若要了解有关定义你的资源范围的详细信息，请参阅[XAML 资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-resources)。

2. **创建一个样式，并定义与它的基本属性值：** 添加以下标记到`Application.Resources`块。 此标记创建[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)应用于的应用程序设置中的所有按钮[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)的按钮为 90 和[Margin](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.margin)到 10:

   XAML复制

   ```xaml
   <Application.Resources>  
     <Style TargetType="Button">
       <Setter Property="Width" Value="90" />
       <Setter Property="Margin" Value="10" />
     </Style>  
   </Application.Resources>  
   ```

   [TargetType](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style.targettype)属性指定该样式应用于类型的所有对象[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。 每个[Setter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.setter)设置为不同的属性值[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)。 因此，此时应用程序中的每个按钮具有宽度为 90、 边距为 10。 如果按 F5 运行该应用程序时，你会看到以下窗口。

   ![具有宽度为 90、 边距为 10 的按钮](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-animatedbutton-2.gif)

   没有你可以执行更多使用样式，包括各种的方式来优化对象的目标、 指定复杂属性值，以及甚至使用样式作为输入的其他样式。 有关详细信息，请参阅[样式设置和模板化](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/styling-and-templating)。

3. **样式属性值设置为资源：** 资源启用重用通常定义的对象和值的简单方法。 它是特别有用，可以定义使用的资源以使代码更加模块化的复杂值。 将以下突出显示的标记添加到 app.xaml。

   XAML复制

   ```xaml
   <Application.Resources>  
     <LinearGradientBrush x:Key="GrayBlueGradientBrush" StartPoint="0,0" EndPoint="1,1">
       <GradientStop Color="DarkGray" Offset="0" />
       <GradientStop Color="#CCCCFF" Offset="0.5" />
       <GradientStop Color="DarkGray" Offset="1" />
     </LinearGradientBrush>  
     <Style TargetType="{x:Type Button}">  
       <Setter Property="Background" Value="{StaticResource GrayBlueGradientBrush}" />  
       <Setter Property="Width" Value="80" />  
       <Setter Property="Margin" Value="10" />  
     </Style>  
   </Application.Resources>  
   ```

   直接在`Application.Resources`块中，创建名为"GrayBlueGradientBrush"的资源。 该资源定义水平渐变。 此资源可从任何位置的属性值作为应用程序，包括内部的按钮样式资源库中[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)属性。 现在，所有按钮都有[Background](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.background)此渐变的属性值。

   按 F5 运行该应用程序。 它应如以下所示。

   ![具有渐变背景的按钮](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-animatedbutton-3.gif)

### 创建用于定义按钮的外观的模板

在本部分中，你创建自定义按钮的外观 (presentation) 的模板。 按钮演示文稿是组成包括矩形和其他组件的多个对象提供独特外观的按钮。

到目前为止，应用程序中的按钮外观的控件已限制为更改按钮的属性。 如果你想要对按钮的外观进行更激进的更改？ 模板启用功能强大的对象显示的控制。 因为样式中，可以使用模板，您可以将模板应用于 （在本演练中，按钮），该样式应用到的所有对象。

#### 若要使用模板来定义按钮的外观

1. **设置模板：** 因为的控件，如[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)具有[Template](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.control.template)属性，可以定义模板属性值，就像我们已经设置了中的其他属性值一样[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)使用[Setter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.setter)。 将以下突出显示的标记添加到按钮样式。

   XAML复制

   ```xaml
   <Application.Resources>  
     <LinearGradientBrush x:Key="GrayBlueGradientBrush"   
       StartPoint="0,0" EndPoint="1,1">  
       <GradientStop Color="DarkGray" Offset="0" />  
       <GradientStop Color="#CCCCFF" Offset="0.5" />  
       <GradientStop Color="DarkGray" Offset="1" />  
     </LinearGradientBrush>  
     <Style TargetType="{x:Type Button}">  
       <Setter Property="Background" Value="{StaticResource GrayBlueGradientBrush}" />  
       <Setter Property="Width" Value="80" />  
       <Setter Property="Margin" Value="10" />  
       <Setter Property="Template">
         <Setter.Value>
           <!-- The button template is defined here. -->
         </Setter.Value>
       </Setter>  
     </Style>  
   </Application.Resources>  
   ```

2. **更改按钮表示：** 此时，您需要定义模板。 添加以下突出显示的标记。 此标记指定了两个[Rectangle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.rectangle)元素具有圆角边缘、 后跟[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)。 [DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)使用到主机[ContentPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter)的按钮。 一个[ContentPresenter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.contentpresenter)显示按钮的内容。 在本演练中，内容是文本 （"按钮 1"、"按钮 2"、"Button 3"）。 所有模板组件 (矩形并[DockPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.dockpanel)) 内的布局[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)。

   XAML复制

   ```xaml
   <Setter.Value>  
     <ControlTemplate TargetType="Button">
       <Grid Width="{TemplateBinding Width}" Height="{TemplateBinding Height}" ClipToBounds="True">
         <!-- Outer Rectangle with rounded corners. -->
         <Rectangle x:Name="outerRectangle" HorizontalAlignment="Stretch" VerticalAlignment="Stretch" Stroke="{TemplateBinding Background}" RadiusX="20" RadiusY="20" StrokeThickness="5" Fill="Transparent" />
         <!-- Inner Rectangle with rounded corners. -->
         <Rectangle x:Name="innerRectangle" HorizontalAlignment="Stretch" VerticalAlignment="Stretch" Stroke="Transparent" StrokeThickness="20" Fill="{TemplateBinding Background}" RadiusX="20" RadiusY="20" />
         <!-- Present Content (text) of the button. -->
         <DockPanel Name="myContentPresenterDockPanel">
           <ContentPresenter x:Name="myContentPresenter" Margin="20" Content="{TemplateBinding  Content}" TextBlock.Foreground="Black" />
         </DockPanel>
       </Grid>
     </ControlTemplate>  
   </Setter.Value>  
   ```

   按 F5 运行该应用程序。 它应如以下所示。

   ![custom_button_AnimatedButton_4](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-animatedbutton-4.gif)

3. **将玻璃添加到模板：** 接下来将添加玻璃效果。 首先创建一些创建玻璃渐变效果的资源。 添加这些渐变中的资源任意位置`Application.Resources`块：

   XAML复制

   ```xaml
   <Application.Resources>  
     <GradientStopCollection x:Key="MyGlassGradientStopsResource">
       <GradientStop Color="WhiteSmoke" Offset="0.2" />     
       <GradientStop Color="Transparent" Offset="0.4" />    
       <GradientStop Color="WhiteSmoke" Offset="0.5" />     
       <GradientStop Color="Transparent" Offset="0.75" />     
       <GradientStop Color="WhiteSmoke" Offset="0.9" />     
       <GradientStop Color="Transparent" Offset="1" />   
     </GradientStopCollection>   
     <LinearGradientBrush x:Key="MyGlassBrushResource"    
       StartPoint="0,0" EndPoint="1,1" Opacity="0.75"
       GradientStops="{StaticResource MyGlassGradientStopsResource}" />  
   <!-- Styles and other resources below here. -->  
   ```

   这些资源用作为[Fill](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.shapes.shape.fill)矩形，我们将其插入到[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)的按钮模板。 将以下突出显示的标记添加到模板。

   XAML复制

   ```xaml
   <Setter.Value>  
     <ControlTemplate TargetType="{x:Type Button}">  
       <Grid Width="{TemplateBinding Width}" Height="{TemplateBinding Height}"  
         ClipToBounds="True">  
   
       <!-- Outer Rectangle with rounded corners. -->  
       <Rectangle x:Name="outerRectangle" HorizontalAlignment="Stretch"   
         VerticalAlignment="Stretch" Stroke="{TemplateBinding Background}"   
         RadiusX="20" RadiusY="20" StrokeThickness="5" Fill="Transparent" />  
   
       <!-- Inner Rectangle with rounded corners. -->  
       <Rectangle x:Name="innerRectangle" HorizontalAlignment="Stretch"   
         VerticalAlignment="Stretch" Stroke="Transparent" StrokeThickness="20"   
         Fill="{TemplateBinding Background}" RadiusX="20" RadiusY="20" />  
   
       <!-- Glass Rectangle -->     
       <Rectangle x:Name="glassCube" HorizontalAlignment="Stretch"       
         VerticalAlignment="Stretch"       
         StrokeThickness="2" RadiusX="10" RadiusY="10" Opacity="0"       
         Fill="{StaticResource MyGlassBrushResource}"       
         RenderTransformOrigin="0.5,0.5">
         <Rectangle.Stroke>         
           <LinearGradientBrush StartPoint="0.5,0" EndPoint="0.5,1">
             <LinearGradientBrush.GradientStops>
               <GradientStop Offset="0.0" Color="LightBlue" />
               <GradientStop Offset="1.0" Color="Gray" />
             </LinearGradientBrush.GradientStops>
           </LinearGradientBrush>       
         </Rectangle.Stroke>       
         <!-- These transforms have no effect as they are declared here.
         The reason the transforms are included is to be targets
         for animation (see later). -->       
         <Rectangle.RenderTransform>
           <TransformGroup>
             <ScaleTransform />
             <RotateTransform />
           </TransformGroup>
         </Rectangle.RenderTransform>
         <!-- A BevelBitmapEffect is applied to give the button a "Beveled" look. -->
         <Rectangle.BitmapEffect>
           <BevelBitmapEffect />
         </Rectangle.BitmapEffect>
       </Rectangle>  
   
       <!-- Present Text of the button. -->  
       <DockPanel Name="myContentPresenterDockPanel">  
         <ContentPresenter x:Name="myContentPresenter" Margin="20"   
           Content="{TemplateBinding  Content}" TextBlock.Foreground="Black" />  
       </DockPanel>  
     </Grid>  
   </ControlTemplate>  
   </Setter.Value>  
   ```

   请注意，[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)与矩形的`x:Name`"glassCube"属性为 0，当您运行该示例，看不到玻璃矩形叠加在最前面。这是因为我们将更高版本时添加触发器用于模板用户交互的按钮。 但是，可以看到该按钮如下所示现在通过更改[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)值与 1 和运行应用程序。 请参见下图。 在前进到下一步前, 更改[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.opacity)回 0。

   ![通过使用 XAML 创建的自定义按钮](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/custom-button-animatedbutton-5.gif)

### 创建按钮交互性

在本部分中，将创建属性触发器和事件触发器可以更改属性值和运行动画以响应用户操作，例如将鼠标指针移动到按钮上方并单击。

添加交互性 （鼠标悬停、 鼠标离开，单击，等） 的简单方法是定义模板或样式中的触发器。 若要创建[Trigger](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.trigger)，如定义属性"条件":按钮[IsMouseOver](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ismouseover)属性值等于`true`。 然后定义触发器条件为 true 时进行的资源库 （操作）。

#### 若要创建按钮交互性

1. **添加模板触发器：** 将突出显示的标记添加到你的模板。

   XAML复制

   ```xaml
   <Setter.Value>  
     <ControlTemplate TargetType="{x:Type Button}">  
       <Grid Width="{TemplateBinding Width}"   
         Height="{TemplateBinding Height}" ClipToBounds="True">  
   
         <!-- Outer Rectangle with rounded corners. -->  
         <Rectangle x:Name="outerRectangle" HorizontalAlignment="Stretch"   
         VerticalAlignment="Stretch" Stroke="{TemplateBinding Background}"   
         RadiusX="20" RadiusY="20" StrokeThickness="5" Fill="Transparent" />  
   
         <!-- Inner Rectangle with rounded corners. -->  
         <Rectangle x:Name="innerRectangle" HorizontalAlignment="Stretch"   
           VerticalAlignment="Stretch" Stroke="Transparent"   
           StrokeThickness="20"   
           Fill="{TemplateBinding Background}" RadiusX="20" RadiusY="20"   
         />  
   
         <!-- Glass Rectangle -->  
         <Rectangle x:Name="glassCube" HorizontalAlignment="Stretch"  
           VerticalAlignment="Stretch"  
           StrokeThickness="2" RadiusX="10" RadiusY="10" Opacity="0"  
           Fill="{StaticResource MyGlassBrushResource}"  
           RenderTransformOrigin="0.5,0.5">  
           <Rectangle.Stroke>  
             <LinearGradientBrush StartPoint="0.5,0" EndPoint="0.5,1">  
               <LinearGradientBrush.GradientStops>  
                 <GradientStop Offset="0.0" Color="LightBlue" />  
                 <GradientStop Offset="1.0" Color="Gray" />  
               </LinearGradientBrush.GradientStops>  
             </LinearGradientBrush>  
           </Rectangle.Stroke>  
   
           <!-- These transforms have no effect as they   
                are declared here.   
                The reason the transforms are included is to be targets   
                for animation (see later). -->  
           <Rectangle.RenderTransform>  
             <TransformGroup>  
               <ScaleTransform />  
               <RotateTransform />  
             </TransformGroup>  
           </Rectangle.RenderTransform>  
   
             <!-- A BevelBitmapEffect is applied to give the button a   
                  "Beveled" look. -->  
           <Rectangle.BitmapEffect>  
             <BevelBitmapEffect />  
           </Rectangle.BitmapEffect>  
         </Rectangle>  
   
         <!-- Present Text of the button. -->  
         <DockPanel Name="myContentPresenterDockPanel">  
           <ContentPresenter x:Name="myContentPresenter" Margin="20"   
             Content="{TemplateBinding  Content}" TextBlock.Foreground="Black" />  
         </DockPanel>  
       </Grid>  
   
       <ControlTemplate.Triggers>       <!-- Set action triggers for the buttons and define            what the button does in response to those triggers. -->     </ControlTemplate.Triggers>  
     </ControlTemplate>  
   </Setter.Value>  
   ```

2. **添加属性触发器：** 添加到突出显示的标记`ControlTemplate.Triggers`块：

   XAML复制

   ```xaml
   <ControlTemplate.Triggers>  
   
     <!-- Set properties when mouse pointer is over the button. -->   <Trigger Property="IsMouseOver" Value="True">     <!-- Below are three property settings that occur when the           condition is met (user mouses over button).  -->     <!-- Change the color of the outer rectangle when user           mouses over it. -->     <Setter Property ="Rectangle.Stroke" TargetName="outerRectangle"       Value="{DynamicResource {x:Static SystemColors.HighlightBrushKey}}" />     <!-- Sets the glass opacity to 1, therefore, the           glass "appears" when user mouses over it. -->     <Setter Property="Rectangle.Opacity" Value="1" TargetName="glassCube" />     <!-- Makes the text slightly blurry as though you           were looking at it through blurry glass. -->     <Setter Property="ContentPresenter.BitmapEffect"        TargetName="myContentPresenter">       <Setter.Value>         <BlurBitmapEffect Radius="1" />       </Setter.Value>     </Setter>   </Trigger>  
   
   <ControlTemplate.Triggers/>  
   ```

   按 F5 以运行应用程序并查看效果，如对按钮运行鼠标指针。

3. **添加焦点触发器：** 接下来，我们将添加一些类似的 setter 来处理这种情况时该按钮具有焦点 （例如，在用户单击它）。

   XAML复制

   ```xaml
   <ControlTemplate.Triggers>  
   
     <!-- Set properties when mouse pointer is over the button. -->  
     <Trigger Property="IsMouseOver" Value="True">  
   
       <!-- Below are three property settings that occur when the   
            condition is met (user mouses over button).  -->  
       <!-- Change the color of the outer rectangle when user          mouses over it. -->  
       <Setter Property ="Rectangle.Stroke" TargetName="outerRectangle"  
         Value="{DynamicResource {x:Static SystemColors.HighlightBrushKey}}" />  
   
       <!-- Sets the glass opacity to 1, therefore, the          glass "appears" when user mouses over it. -->  
       <Setter Property="Rectangle.Opacity" Value="1"       TargetName="glassCube" />  
   
       <!-- Makes the text slightly blurry as though you were          looking at it through blurry glass. -->  
       <Setter Property="ContentPresenter.BitmapEffect"       TargetName="myContentPresenter">  
         <Setter.Value>  
           <BlurBitmapEffect Radius="1" />  
         </Setter.Value>  
       </Setter>  
     </Trigger>  
     <!-- Set properties when button has focus. -->   <Trigger Property="IsFocused" Value="true">     <Setter Property="Rectangle.Opacity" Value="1"       TargetName="glassCube" />     <Setter Property="Rectangle.Stroke" TargetName="outerRectangle"       Value="{DynamicResource {x:Static SystemColors.HighlightBrushKey}}" />     <Setter Property="Rectangle.Opacity" Value="1" TargetName="glassCube" />   </Trigger>  
   
   </ControlTemplate.Triggers>  
   ```

   按 F5 以运行该应用程序并单击其中一个按钮。 请注意，在单击因为它仍然具有焦点的按钮始终保持突出显示。 如果单击另一个按钮，新建按钮获得焦点，而最后一个失去它。

4. **添加动画**[MouseEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouseenter) **并** [MouseLeave](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouseleave) **:** 接下来我们将某些动画添加到触发器。 添加以下标记内部的任意位置`ControlTemplate.Triggers`块。

   XAML复制

   ```xaml
   <!-- Animations that start when mouse enters and leaves button. -->  
   <EventTrigger RoutedEvent="Mouse.MouseEnter">  
     <EventTrigger.Actions>  
       <BeginStoryboard Name="mouseEnterBeginStoryboard">  
         <Storyboard>  
         <!-- This animation makes the glass rectangle shrink in the X direction. -->  
           <DoubleAnimation Storyboard.TargetName="glassCube"   
             Storyboard.TargetProperty=  
             "(Rectangle.RenderTransform).(TransformGroup.Children)[0].(ScaleTransform.ScaleX)"  
             By="-0.1" Duration="0:0:0.5" />  
           <!-- This animation makes the glass rectangle shrink in the Y direction. -->  
           <DoubleAnimation  
           Storyboard.TargetName="glassCube"   
             Storyboard.TargetProperty=  
             "(Rectangle.RenderTransform).(TransformGroup.Children)[0].(ScaleTransform.ScaleY)"   
             By="-0.1" Duration="0:0:0.5" />  
         </Storyboard>  
       </BeginStoryboard>  
     </EventTrigger.Actions>  
   </EventTrigger>  
   <EventTrigger RoutedEvent="Mouse.MouseLeave">  
     <EventTrigger.Actions>  
       <!-- Stopping the storyboard sets all animated properties back to default. -->  
       <StopStoryboard BeginStoryboardName="mouseEnterBeginStoryboard" />  
     </EventTrigger.Actions>  
   </EventTrigger>  
   ```

   当鼠标指针移动到按钮上方并返回到正常大小当指针离开时，透明矩形会缩小。

   当鼠标指针移到该按钮时触发的两个动画 ([MouseEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouseenter)引发事件)。 这些动画收缩玻璃矩形沿 X 和 Y 轴。 请注意，属性在[DoubleAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation)元素 —[Duration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.duration)和[By](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation.by)。 [Duration](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.timeline.duration)指定动画发生超过半秒，和[By](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation.by)指定玻璃收缩 10%。

   第二个事件触发器 ([MouseLeave](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouseleave)) 就会停止运行的第一个。 当您停止[Storyboard](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.storyboard)，经过动画处理的所有属性都返回到其默认值。 因此，当用户移动指针离开按钮，按钮将恢复为之前在按钮上移动鼠标指针的方式。有关动画的详细信息，请参阅[动画概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/animation-overview)。

5. **添加动画，以单击按钮时：** 最后一步是添加用于的触发器，当用户单击按钮。 添加以下标记内部的任意位置`ControlTemplate.Triggers`块：

   XAML复制

   ```xaml
   <!-- Animation fires when button is clicked, causing glass to spin.  -->  
   <EventTrigger RoutedEvent="Button.Click">  
     <EventTrigger.Actions>  
       <BeginStoryboard>  
         <Storyboard>  
           <DoubleAnimation Storyboard.TargetName="glassCube"   
             Storyboard.TargetProperty=  
             "(Rectangle.RenderTransform).(TransformGroup.Children)[1].(RotateTransform.Angle)"   
             By="360" Duration="0:0:0.5" />  
         </Storyboard>  
       </BeginStoryboard>  
     </EventTrigger.Actions>  
   </EventTrigger>  
   ```

   按 F5 以运行该应用程序，并单击其中一个按钮。 当单击按钮时，透明矩形会旋转一周。

### 总结

在本演练中，您执行了以下练习：

- 面向[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)为对象类型 ([Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button))。
- 控制在整个应用程序中使用的按钮的基本属性[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)。
- 创建资源，如渐变来使用的属性值的[Style](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.style)资源库。
- 通过将模板应用于按钮自定义整个应用程序中的按钮的外观。
- 自定义行为响应用户操作中的按钮 (如[MouseEnter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouseenter)， [MouseLeave](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.mouseleave)，和[Click](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.buttonbase.click)) 包含的动画效果。