# [Design XAML in Visual Studio](https://docs.microsoft.com/en-us/visualstudio/designers/designing-xaml-in-visual-studio?view=vs-2019)

Visual Studio 和 Blend for Visual Studio 两者都是可视化工具，用于使用 XAML 针对各种应用类型构建具有吸引力的用户界面和丰富的媒体体验。 两种工具共享一组通用功能，包括可视化 XAML 编辑器，但 Blend for Visual Studio 为更高级的任务（如动画和行为）提供了额外的设计工具。

设计应用的过程具体取决于所选工具和目标平台。 本文比较 Visual Studio 和 Blend for Visual Studio 中的 XAML 设计工具。 有关使用这些工具的更详细演练，请参阅以下主题：

- [在 Visual Studio 中使用 XAML 设计器创建 UI](https://docs.microsoft.com/zh-cn/visualstudio/designers/creating-a-ui-by-using-xaml-designer-in-visual-studio?view=vs-2019)
- [使用 Blend for Visual Studio 创建 UI](https://docs.microsoft.com/zh-cn/visualstudio/designers/creating-a-ui-by-using-blend-for-visual-studio?view=vs-2019)

## 选择合适的工具

你选择的设计工具在很大程度上取决于你的技能集。 如果你更加面向代码，则可以在 Visual Studio 中编写的 XAML 代码来完成高级设计任务。 如果你更加面向设计，则可以使用 Blend for Visual Studio 执行高级任务，而无需编写代码。

可以 Visual Studio 与 Blend for Visual Studio 之间来回切换，甚至可以同时在两者中打开同一个项目。 在一个 IDE 中对 XAML 文件进行的更改可以在你切换到另一个 IDE 时，通过自动重载进行应用。 可以通过任一 IDE 中的“工具” > “选项”对话框中的选项控制重载行为。

### 共享功能

对于最基本的任务，IDE for Visual Studio 和 Blend for Visual Studio 共享一组相同的窗口和功能（其中有一些细微的差异）。 一些要点包括：

- **一致的用户界面：** 可以在熟悉的 Visual Studio 用户界面环境中设计应用程序，这会使 IDE 之间的切换成为更加愉快且高效的体验。 Blend for Visual Studio 使用 Visual Studio 深色主题，该主题可提高你的内容与用户界面之间的对比度，从而帮助你专注于正在设计的内容。 请参阅[使用 XAML 设计器创建 UI](https://docs.microsoft.com/zh-cn/visualstudio/designers/creating-a-ui-by-using-xaml-designer-in-visual-studio?view=vs-2019)。

  ![Blend for Visual Studio IDE](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/blendide.png?view=vs-2019)

- **XAML IntelliSense：** 两个 IDE 都支持期望从 IntelliSense 获得的所有常见功能，包括语句完成、对常见编辑器操作（如对代码进行注释和格式设置）的支持以及针对资源、绑定和代码进行的导航。

- **基础调试功能：** 现在可以在 Blend 中进行调试，包括在代码中设置断点来调试正在运行的应用。 为了保持与 Visual Studio 一致的调试体验，Blend for Visual Studio 包含 Visual Studio 的大多数调试窗口和工具栏。 高级调试功能（如诊断和代码分析）仅在 Visual Studio 中可用。 请参阅[在 Visual Studio 中调试](https://docs.microsoft.com/zh-cn/visualstudio/debugger/debugger-feature-tour?view=vs-2019)。

- **文件重载体验：** 可以在 Blend for Visual Studio 或 Visual Studio 中编辑 XAML 文件，并且在它们之间切换时自动重载编辑后的文件。 若要最大程度减少工作流中断，现在可以在文件重载对话框中设置文件重载首选项。

  ![文件重新加载体验](https://docs.microsoft.com/zh-cn/visualstudio/designers/media/blendfilereload.png?view=vs-2019)

- **已同步的布局和设置：** 通过自定义布局可以保存并应用工具窗口布局自定义项。 使用相同 Microsoft 帐户登录时，Visual Studio 会在计算机之间为 Visual Studio 和 Blend for Visual Studio 同步这些自定义项和首选项。 请参见[跨多台计算机同步设置](https://docs.microsoft.com/zh-cn/visualstudio/ide/synchronized-settings-in-visual-studio?view=vs-2019)。

- **通用的解决方案资源管理器：** 解决方案资源管理器可提供项目及其文件的组织有序的视图，并且可用于访问与它们关联的命令。 借助解决方案资源管理器，可以更方便地处理大型企业项目。 请参阅[解决方案和项目](https://docs.microsoft.com/zh-cn/visualstudio/ide/solutions-and-projects-in-visual-studio?view=vs-2019)。

- **团队资源管理器：** 通过团队资源管理器可以使用 GIT 或 TFS 存储库管理项目以促进团队协作。 请参阅 [在团队资源管理器中工作](https://docs.microsoft.com/zh-cn/azure/devops/user-guide/work-team-explorer)。

- **NuGet：** 可以在 Visual Studio 和 Blend for Visual Studio 中管理 NuGet 包。 NuGet 是用于 .NET Framework 的程序包管理器，它简化了从解决方案安装和删除程序包的过程。

## Blend for Visual Studio 中的高级功能

若要提高工作效率，请考虑对以下任务使用 Blend for Visual Studio。 Blend for Visual Studio 在这些领域中可提供比单独 Visual Studio 设计器或代码更快的速度和更多的功能。

| 到                                   | Visual Studio                                                | Blend for Visual Studio                                      | 详细信息                                                     |
| ------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| **创建动画**                         | 没有用于动画的设计工具；必须以编程方式创建它们。 这需要对 WPF 中的动画和时间系统的了解以及丰富的编码专业知识。 | 可直观地创建动画，并且可以在 Blend for Visual Studio 中预览它们。 这比采用代码构建动画更快且更精确。 可以添加触发器以处理用户交互，并且可以切换到代码以添加事件处理程序和其他功能。 | [动态显示对象](https://docs.microsoft.com/zh-cn/visualstudio/designers/animate-objects-in-xaml-designer?view=vs-2019) |
| **将形状和文本转换为路径以便于操作** | 不支持。                                                     | 可以通过将形状（如矩形和椭圆）转换为路径（这样可提供更好的编辑控制）来对形状进行细微或显著的更改。 可以重新调整路径形状或合并路径，以及从多个形状创建复合路径。  还可以将文本块转换为路径以便将它们作为矢量图像进行操作。 | [绘制形状和路径](https://docs.microsoft.com/zh-cn/visualstudio/designers/draw-shapes-and-paths?view=vs-2019) |
| **向 UI 设计添加交互性**             | 需要 C#、Visual Basic 或 C++ 代码。                          | 将行为拖放到控件上以便向静态设计添加交互性。 行为是随时可用的代码段，用于封装各种功能（例如拖放、缩放和可视状态更改）。 有一组不断增加的行为可供选择，并且可以创建自己的行为。  随后可以通过在 Blend for Visual Studio 中更改其属性或在代码中添加事件处理程序，来自定义每个行为。 | [插入控件并修改其行为](https://docs.microsoft.com/zh-cn/visualstudio/designers/insert-controls-and-modify-their-behavior-in-xaml-designer?view=vs-2019) |
| **使用 Adobe 图稿**                  | 不支持。                                                     | 在 Blend for Visual Studio 中导入 Adobe FXG、PhotoShop 或 Illustrator 图稿并实现 UI。 | [插入图像、视频和音频剪辑](https://docs.microsoft.com/zh-cn/visualstudio/designers/insert-images-videos-and-audio-clips-in-xaml-designer?view=vs-2019) |
| **编辑控件、模板和样式**             | 需要 WPF 样式和模板方面的编码和知识。                        | 将任何图像转换为控件。  使用模板编辑工具，只需少量鼠标单击便可对控件、样式和模板进行更改。  例如，可以使用 Blend for Visual Studio 样式资源实现常用 WPF 控件（如按钮、列表框、滚动条、菜单等）并直接在 Blend for Visual Studio 中更改其颜色、样式或基础模板。 如果需要，随后可以切换到代码以完成收尾工作。 | [修改对象样式](https://docs.microsoft.com/zh-cn/visualstudio/designers/modify-the-style-of-objects-in-blend?view=vs-2019) |
| **将 UI 连接到数据**                 | 可以从资源（如 SQL Server 数据库、WCF 或 Web 服务、对象或 SharePoint 列表创建数据源，并将数据源绑定到 UI 控件。  必须手动创建设计时数据来获得交互设计体验。 | 可轻松地为原型制作和测试创建示例数据。 在准备就绪时切换到实时数据。  Blend for Visual Studio 的数据生成功能十分出色（可以轻松地动态添加名称、数字、URL 和照片），可以节省大量时间。  对于实时数据，可以将 UI 控件绑定到 XML 文件或任何 CLR 数据源。 | [显示数据](https://docs.microsoft.com/zh-cn/visualstudio/designers/display-data-in-blend?view=vs-2019) |

有关高级 XAML 设计的详细信息，请参阅[使用 Blend for Visual Studio 创建 UI](https://docs.microsoft.com/zh-cn/visualstudio/designers/creating-a-ui-by-using-blend-for-visual-studio?view=vs-2019)。