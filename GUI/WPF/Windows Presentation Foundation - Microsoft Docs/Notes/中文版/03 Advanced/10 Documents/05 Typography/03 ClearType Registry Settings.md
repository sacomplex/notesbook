本主题提供的概述WPFMicrosoft ClearType由注册表设置WPF应用程序。



## 技术概述

WPF 文本呈现给显示设备使用的应用程序ClearType特征可以提供增强的阅读体验。 ClearType 是一种由Microsoft 开发的软件技术，可提高现有 LCD（液晶显示器，如笔记本电脑屏幕、Pocket PC 屏幕和平板显示器）上文本的可读性。 ClearType 在工作时访问 LCD 屏幕中每个像素的各个垂直色条元素。 有关详细信息ClearType，请参阅[ClearType 概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/cleartype-overview)。

使用呈现的文本ClearType可能会在不同的显示设备上查看时明显不同。 例如，少数监视器实现色条元素按蓝色、 绿色、 红色顺序而不是更常见的红色、 绿色、 蓝色 ( RGB) 顺序。

使用呈现的文本ClearType还会查看由具有不同的色彩敏感度级别时大大不同。 某些人能够比别人更擅长发觉颜色的微小差异。

在每个这些情况下，ClearType需要修改，以提供最佳阅读体验每个单独的功能。



## 注册表设置

WPF 指定四个注册表设置用于控制ClearType功能：

| 设置           | 描述                               |
| -------------- | ---------------------------------- |
| ClearType 级别 | 描述级别的ClearType色彩清晰度。    |
| 伽马级别       | 描述显示设备的像素颜色组件的级别。 |
| 像素结构       | 描述显示设备的像素排列。           |
| 文本对比度级别 | 描述显示文本的对比度级别。         |

这些设置可以访问由知道如何引用已标识的外部配置实用工具WPFClearType注册表设置。 还可以直接使用 Windows 注册表编辑器来访问这些值，从而创建或修改这些设置。

如果WPFClearType注册表设置未设置 （这是默认状态），WPF应用程序查询Windows字体平滑设置的系统参数信息。

 备注

有关枚举显示设备名称的信息，请参阅`SystemParametersInfo`Win32函数。



## ClearType 级别

ClearType级别使您可以调整色彩敏感度和感知度个人在基于文本的呈现。 对于某些人而言，文本的呈现使用ClearType其最高级别不会产生最佳阅读体验。

ClearType级别是一个介于 0 到 100 的整数值。 默认级别为 100，这意味着ClearType使用显示设备的色条元素的最大能力。 但是，ClearType级别为 0 将文本呈现为灰度级。 通过设置ClearType级别 0 和 100 之间的某个位置，可以创建适合个人色彩敏感度的中间级别。

### 注册表设置

注册表设置位置ClearType级别是对应于特定显示设备名称的单个用户设置：

```
HKEY_CURRENT_USER\SOFTWARE\Microsoft\Avalon.Graphics\<displayName>
```

对于用户，每个显示设备名称`ClearTypeLevel`定义 DWORD 值。 下面的屏幕截图显示了注册表编辑器设置ClearType级别。

![注册表编辑器中的 ClearType 设置](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/cleartyperegistry01.png)

 备注

WPF 应用程序呈现文本中使用和不是两种模式之一ClearType。 无需呈现文本时ClearType，它被称为灰度呈现。



## 伽马级别

伽玛级别指的是像素值和亮度之间的非线性关系。 伽玛级别设置应对应于显示设备的物理特性；否则呈现的输出中可能会出现失真。 例如，测试可能显得太宽或太窄，或者字形的垂直主体的边缘上可能会出现彩色条纹。

伽马级别是一个介于 1000 到 2200 之间的整数值。 默认级别为 1900。

### 注册表设置

伽马级别的注册表设置位置是对应于特定显示设备名称的本地计算机设置：

```
HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Avalon.Graphics\<displayName>
```

对于用户，每个显示设备名称`GammaLevel`定义 DWORD 值。 以下屏幕快照显示了伽马级别的注册表编辑器设置。

![注册表编辑器中的 ClearType 设置](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/cleartyperegistry02.png)



## 像素结构

像素结构描述构成显示设备的像素的类型。 像素结构定义为三种类型之一：

| 类型 | 值   | 描述                                                         |
| ---- | ---- | ------------------------------------------------------------ |
| 平面 | 0    | 显示设备没有像素结构。 这意味着每种颜色的光源均匀分布在像素区域上，称为灰度呈现。 这是标准显示设备的工作方式。 ClearType 从不应用于呈现的文本。 |
| RGB  | 1    | 显示设备的像素由三种色条按以下顺序构成：红色、绿色和蓝色。 ClearType 应用于呈现的文本。 |
| BGR  | 2    | 显示设备的像素由三种色条按以下顺序构成：蓝色、绿色和红色。 ClearType 应用于呈现的文本。 注意该顺序与 RGB 类型相反。 |

像素结构对应于 0 到 2 之间的一个整数值。 默认级别为 0，表示平面像素结构。

 备注

有关枚举显示设备名称的信息，请参阅`EnumDisplayDevices`Win32函数。

### 注册表设置

像素结构的注册表设置位置是对应于特定显示设备名称的本地计算机设置：

```
HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Avalon.Graphics\<displayName>
```

对于用户，每个显示设备名称`PixelStructure`定义 DWORD 值。 以下屏幕快照显示了像素结构的注册表编辑器设置。

![注册表编辑器中的 ClearType 设置](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/cleartyperegistry02.png)



## 文本对比度级别

通过文本对比度级别可以根据字形的主体宽度来调整文本的呈现。 文本对比度级别是一个 0 到 6 之间的整数值 - 整数值越大，主体就越宽。 默认级别为 1。

### 注册表设置

文本对比度级别的注册表设置位置是对应于特定显示设备名称的单个用户设置：

```
HKEY_CURRENT_USER\Software\Microsoft\Avalon.Graphics\<displayName>
```

对于用户，每个显示设备名称`TextContrastLevel`定义 DWORD 值。 以下屏幕快照显示了文本对比度级别的注册表编辑器设置。

![注册表编辑器中的 ClearType 设置](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/cleartyperegistry01.png)