# [Graphics Rendering Registry Settings](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/graphics-rendering-registry-settings)

本主题概述了影响 WPF 应用程序的 WPF 图形呈现注册表设置。

## 何时使用图形呈现注册表设置

这些注册表设置为故障排除、调试和产品支持目的而提供。 由于对注册表的更改会影响所有 WPF 应用程序，应用程序永远不应该自动或在安装期间更改这些注册表项。

## 什么是 XPDM 和 WDDM？

某些图形呈现注册表设置具有不同的默认值，具体取决于视频卡使用的是 XPDM 还是 WDDM 驱动程序。 XPDM 是 Microsoft Windows XP 显示驱动程序模式，WDDM 是 Windows 显示驱动程序模型。 WDDM 适用于运行 Windows Vista 和 Windows 7 的计算机。 WDDM 适用于运行 Windows Vista、Microsoft Windows XP 和Microsoft Windows Server 2003 的计算机。 有关 WDDM 的详细信息，请参阅 [Windows Vista 显示驱动程序模式设计指南](https://go.microsoft.com/fwlink/?LinkId=178394)。

## 注册表设置

WPF 提供了四个注册表设置来控制 WPF 呈现：

| 设置                           | 描述                                                         |
| ------------------------------ | ------------------------------------------------------------ |
| **禁用硬件加速选项**           | 指定是否应启用硬件加速。                                     |
| **最大多重采样值**             | 指定用于消除 三维 内容锯齿的多重采样级别。                   |
| **必需的视频驱动程序日期设置** | 指定系统是否对 2004 年 11 月之前发布的驱动程序禁用硬件加速。 |
| **使用参考光栅器选项**         | 指定 WPF 是否应使用参考光栅器。                              |

知道如何引用 WPF 注册表设置的任何外部配置实用工具都可以访问这些设置。 还可以直接使用 Windows 注册表编辑器来访问这些值，从而创建或修改这些设置。

## 禁用硬件加速选项

| 注册表项                                                     | 值类型 |
| ------------------------------------------------------------ | ------ |
| `HKEY_CURRENT_USER\SOFTWARE\Microsoft\Avalon.Graphics\DisableHWAcceleration` | DWORD  |

使用“禁用硬件加速选项”，可以出于调试和测试目的而关闭硬件加速。 查看应用程序中的呈现项目时，尝试关闭硬件加速。 如果项目消失，则视频驱动程序可能有问题。

“禁用硬件加速选项”是一个等于 0 或 1 的 DWORD 值。 如果值为 1，表示禁用硬件加速。 如果值为 0，表示启用硬件加速，前提是系统满足硬件加速要求；有关详细信息，请参阅[图形呈现层](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/graphics-rendering-tiers)。

## 最大多重采样值

| 注册表项                                                     | 值类型 |
| ------------------------------------------------------------ | ------ |
| `HKEY_CURRENT_USER\SOFTWARE\Microsoft\Avalon.Graphics\MaxMultisampleType` | DWORD  |

使用“最大多重采样值”，可以调整 三维 内容的最大抗锯齿量。 使用此级别，在 Windows Vista 中禁用 三维 抗锯齿或在 Microsoft Windows XP 中启用它。

“最大多重采样值”是一个 DWORD 值，范围为从 0 到 16。 如果值为 0，则指定应禁用 3-D 内容的多重采样抗锯齿；如果值为 16，将尝试设置最多 16 倍多重采样抗锯齿（如果受视频卡支持）。 请注意，在使用 XPDM 驱动程序的计算机上设置此注册表项值将导致应用程序使用大量额外视频内存，降低 三维 呈现的性能，并且有可能导致发生呈现错误和稳定性问题。

当未设置此注册表项时， WPF 将默认为 0（对于 XPDM 驱动程序）和 4（对于 WDDM 驱动程序）。

## 必需的视频驱动程序日期设置

| 注册表项                                                     | 值类型 |
| ------------------------------------------------------------ | ------ |
| `HKEY_CURRENT_USER\SOFTWARE\Microsoft\Avalon.Graphics\RequiredVideoDriverDate` | String |

在 2004 年 11 月，Microsoft 发布了新版本的驱动程序测试指南；在此日期之后写入的驱动程序提供更好的稳定性。 默认情况下，WPF 将为这些驱动程序使用硬件加速管道，并将回退到此日期之前发布的 XPDM 驱动程序的软件呈现。

使用“必需的视频驱动程序日期设置”，可以为 XPDM 驱动程序指定最早备用日期。 如果确信视频驱动程序足够稳定，可支持 WPF，应仅指定早于 2004 年 11 月的日期。

必需的视频驱动程序采用以下格式的字符串：

|                          |
| ------------------------ |
| *YYYY* `/` *MM* `/` *DD* |

其中 *YYYY* 是四位数年份，*MM* 是两位数月份，而 *DD* 是两位数日期。 当未设置此值时，WPF 使用 2004 年 11 月作为必需的视频驱动程序日期。

## 使用参考光栅器选项

| 注册表项                                                     | 值类型 |
| ------------------------------------------------------------ | ------ |
| `HKEY_CURRENT_USER\SOFTWARE\Microsoft\Avalon.Graphics\UseReferenceRasterizer` | DWORD  |

使用“使用参考光栅器选项”，可以在模拟硬件呈现模式中强制执行 WPF 以进行调试：WPF 转到硬件模式，但使用 Microsoft Direct3D 参考软件光栅器 d3dref9.dll，而不是实际的硬件设备。

参考光栅器非常缓慢，但可以绕过视频驱动程序以避免由驱动程序问题导致的任何呈现问题。 出于此原因，可使用参考光栅器确定呈现问题是否由视频驱动程序导致。 d3dref9.dll 文件必须位于应用程序可访问它的位置，如系统路径或应用程序的本地目录中的任何位置。

“使用参考光栅器选项”采用 DWORD 值。 值为 0 指示不使用参考光栅器。 任何其他非零值都强制 WPF 使用参考光栅器。