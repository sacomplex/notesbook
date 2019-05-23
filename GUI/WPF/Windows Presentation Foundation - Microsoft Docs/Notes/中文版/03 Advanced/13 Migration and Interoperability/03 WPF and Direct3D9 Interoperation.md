# [WPF and Direct3D9 Interoperation](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/wpf-and-direct3d9-interoperation)

可以在 Windows Presentation Foundation (WPF) 应用程序中包含 Direct3D9 内容。 本主题介绍如何创建 Direct3D9 内容，以便它有效地与 WPF 互操作。

 备注

在 WPF 中使用 Direct3D9 内容，还需要考虑到性能。 有关如何优化性能的详细信息，请参阅[Direct3D9 和 WPF 互操作性的性能注意事项](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/performance-considerations-for-direct3d9-and-wpf-interoperability)。

## 显示缓冲区

[D3DImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage)类管理两个显示缓冲区，称为*后台缓冲区*并且*前台缓冲区*。 后台缓冲区是 Direct3D9 图面。 对后台缓冲区的更改复制前滚到前台缓冲区调用时[Unlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage.unlock)方法。

下图显示后台缓冲区和前台缓冲区之间的关系。

![D3DImage 显示缓冲区](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/d3dimage-buffers.png)

## 创建 Direct3D9 设备

若要呈现 Direct3D9 内容，必须创建 Direct3D9 设备。 有两个可用于创建设备的 Direct3D9 对象`IDirect3D9`和`IDirect3D9Ex`。 使用这些对象创建`IDirect3DDevice9`和`IDirect3DDevice9Ex`设备，分别。

通过调用以下方法之一创建一个设备。

- `IDirect3D9 * Direct3DCreate9(UINT SDKVersion);`
- `HRESULT Direct3DCreate9Ex(UINT SDKVersion, IDirect3D9Ex **ppD3D);`

在 Windows Vista 或更高版本操作系统上，使用`Direct3DCreate9Ex`与配置为使用 Windows 显示驱动程序模型 (WDDM) 显示的方法。 使用`Direct3DCreate9`任何其他平台上的方法。

### Direct3DCreate9Ex 方法的可用性

D3d9.dll 具有`Direct3DCreate9Ex`仅在 Windows Vista 或更高版本操作系统上的方法。 如果直接链接在 Windows XP 上的函数，你的应用程序加载失败。 若要确定是否`Direct3DCreate9Ex`支持方法、 加载 DLL 和查找进程的地址。 下面的代码演示如何为测试`Direct3DCreate9Ex`方法。 有关完整的代码示例，请参阅[演练：创建在 WPF 中承载的 Direct3D9 内容](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/walkthrough-creating-direct3d9-content-for-hosting-in-wpf)。

C++复制

```cpp
HRESULT
CRendererManager::EnsureD3DObjects()
{
    HRESULT hr = S_OK;

    HMODULE hD3D = NULL;
    if (!m_pD3D)
    {
        hD3D = LoadLibrary(TEXT("d3d9.dll"));
        DIRECT3DCREATE9EXFUNCTION pfnCreate9Ex = (DIRECT3DCREATE9EXFUNCTION)GetProcAddress(hD3D, "Direct3DCreate9Ex");
        if (pfnCreate9Ex)
        {
            IFC((*pfnCreate9Ex)(D3D_SDK_VERSION, &m_pD3DEx));
            IFC(m_pD3DEx->QueryInterface(__uuidof(IDirect3D9), reinterpret_cast<void **>(&m_pD3D)));
        }
        else
        {
            m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
            if (!m_pD3D) 
            {
                IFC(E_FAIL);
            }
        }

        m_cAdapters = m_pD3D->GetAdapterCount();
    }

Cleanup:
    if (hD3D)
    {
        FreeLibrary(hD3D);
    }

    return hr;
}
```

### HWND 创建

创建设备需要 HWND。 一般情况下，您创建 Direct3D9 使用虚拟 HWND。 下面的代码示例演示如何创建虚拟 HWND。

C++复制

```cpp
HRESULT
CRendererManager::EnsureHWND()
{
    HRESULT hr = S_OK;

    if (!m_hwnd)
    {
        WNDCLASS wndclass;

        wndclass.style = CS_HREDRAW | CS_VREDRAW;
        wndclass.lpfnWndProc = DefWindowProc;
        wndclass.cbClsExtra = 0;
        wndclass.cbWndExtra = 0;
        wndclass.hInstance = NULL;
        wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
        wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
        wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH);
        wndclass.lpszMenuName = NULL;
        wndclass.lpszClassName = szAppName;

        if (!RegisterClass(&wndclass))
        {
            IFC(E_FAIL);
        }

        m_hwnd = CreateWindow(szAppName,
                            TEXT("D3DImageSample"),
                            WS_OVERLAPPEDWINDOW,
                            0,                   // Initial X
                            0,                   // Initial Y
                            0,                   // Width
                            0,                   // Height
                            NULL,
                            NULL,
                            NULL,
                            NULL);
    }

Cleanup:
    return hr;
}
```

### 存在参数

创建设备还需要`D3DPRESENT_PARAMETERS`结构，但只有几个参数非常重要。 这些参数会选择最大程度减少内存占用量。

设置`BackBufferHeight`和`BackBufferWidth`字段为 1。 将它们设置为 0 会导致它们被设置为该 HWND 的尺寸。

始终设置`D3DCREATE_MULTITHREADED`和`D3DCREATE_FPU_PRESERVE`标记以避免损坏了用于通过 Direct3D9 并防止 Direct3D9 更改 FPU 设置。

下面的代码演示如何初始化`D3DPRESENT_PARAMETERS`结构。

C++复制

```cpp
HRESULT 
CRenderer::Init(IDirect3D9 *pD3D, IDirect3D9Ex *pD3DEx, HWND hwnd, UINT uAdapter)
{
    HRESULT hr = S_OK;

    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory(&d3dpp, sizeof(d3dpp));
    d3dpp.Windowed = TRUE;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
    d3dpp.BackBufferHeight = 1;
    d3dpp.BackBufferWidth = 1;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;

    D3DCAPS9 caps;
    DWORD dwVertexProcessing;
    IFC(pD3D->GetDeviceCaps(uAdapter, D3DDEVTYPE_HAL, &caps));
    if ((caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT) == D3DDEVCAPS_HWTRANSFORMANDLIGHT)
    {
        dwVertexProcessing = D3DCREATE_HARDWARE_VERTEXPROCESSING;
    }
    else
    {
        dwVertexProcessing = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
    }

    if (pD3DEx)
    {
        IDirect3DDevice9Ex *pd3dDevice = NULL;
        IFC(pD3DEx->CreateDeviceEx(
            uAdapter,
            D3DDEVTYPE_HAL,
            hwnd,
            dwVertexProcessing | D3DCREATE_MULTITHREADED | D3DCREATE_FPU_PRESERVE,
            &d3dpp,
            NULL,
            &m_pd3dDeviceEx
            ));

        IFC(m_pd3dDeviceEx->QueryInterface(__uuidof(IDirect3DDevice9), reinterpret_cast<void**>(&m_pd3dDevice)));  
    }
    else 
    {
        assert(pD3D);

        IFC(pD3D->CreateDevice(
            uAdapter,
            D3DDEVTYPE_HAL,
            hwnd,
            dwVertexProcessing | D3DCREATE_MULTITHREADED | D3DCREATE_FPU_PRESERVE,
            &d3dpp,
            &m_pd3dDevice
            ));
    }

Cleanup:
    return hr;
}
```

## 创建后台缓冲区呈现器目标

若要显示在 Direct3D9 内容[D3DImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage)，创建 Direct3D9 面并将其分配通过调用[SetBackBuffer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage.setbackbuffer)方法。

### 验证适配器支持

创建图面之前, 验证所有适配器都支持所需的图面属性。 即使您呈现到只有一个适配器，可能会在系统中任何适配器上显示 WPF 窗口。 您应始终编写处理多适配器配置的 Direct3D9 代码和您应检查所有适配器的支持，因为 WPF 可能移动之间的可用适配器的图面。

下面的代码示例演示如何检查 Direct3D9 的系统上的所有适配器都支持。

C++复制

```cpp
HRESULT
CRendererManager::TestSurfaceSettings()
{
    HRESULT hr = S_OK;

    D3DFORMAT fmt = m_fUseAlpha ? D3DFMT_A8R8G8B8 : D3DFMT_X8R8G8B8;

    // 
    // We test all adapters because because we potentially use all adapters.
    // But even if this sample only rendered to the default adapter, you
    // should check all adapters because WPF may move your surface to
    // another adapter for you!
    //

    for (UINT i = 0; i < m_cAdapters; ++i)
    {
        // Can we get HW rendering?
        IFC(m_pD3D->CheckDeviceType(
            i,
            D3DDEVTYPE_HAL,
            D3DFMT_X8R8G8B8,
            fmt,
            TRUE
            )); 

        // Is the format okay?
        IFC(m_pD3D->CheckDeviceFormat(
            i,
            D3DDEVTYPE_HAL,
            D3DFMT_X8R8G8B8,
            D3DUSAGE_RENDERTARGET | D3DUSAGE_DYNAMIC, // We'll use dynamic when on XP
            D3DRTYPE_SURFACE,
            fmt
            ));

        // D3DImage only allows multisampling on 9Ex devices. If we can't 
        // multisample, overwrite the desired number of samples with 0.
        if (m_pD3DEx && m_uNumSamples > 1)
        {   
            assert(m_uNumSamples <= 16);

            if (FAILED(m_pD3D->CheckDeviceMultiSampleType(
                i,
                D3DDEVTYPE_HAL,
                fmt,
                TRUE,
                static_cast<D3DMULTISAMPLE_TYPE>(m_uNumSamples),
                NULL
                )))
            {
                m_uNumSamples = 0;
            }
        }
        else
        {
            m_uNumSamples = 0;
        }
    }

Cleanup:
    return hr;
}
```

### 创建在图面

创建图面之前, 请确认设备功能，在目标操作系统上支持良好的性能。 有关详细信息，请参阅[Direct3D9 和 WPF 互操作性的性能注意事项](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/performance-considerations-for-direct3d9-and-wpf-interoperability)。

如果你已验证设备功能，可以创建在图面。 下面的代码示例演示如何创建呈现器目标。

C++复制

```cpp
HRESULT
CRenderer::CreateSurface(UINT uWidth, UINT uHeight, bool fUseAlpha, UINT m_uNumSamples)
{
    HRESULT hr = S_OK;

    SAFE_RELEASE(m_pd3dRTS);

    IFC(m_pd3dDevice->CreateRenderTarget(
        uWidth,
        uHeight,
        fUseAlpha ? D3DFMT_A8R8G8B8 : D3DFMT_X8R8G8B8,
        static_cast<D3DMULTISAMPLE_TYPE>(m_uNumSamples),
        0,
        m_pd3dDeviceEx ? FALSE : TRUE,  // Lockable RT required for good XP perf
        &m_pd3dRTS,
        NULL
        ));

    IFC(m_pd3dDevice->SetRenderTarget(0, m_pd3dRTS));

Cleanup:
    return hr;
}
```

### WDDM

在 Windows Vista 和更高版本的操作系统，已配置为使用 WDDM，可以创建呈现器目标纹理，并将传递到在级别 0 面[SetBackBuffer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage.setbackbuffer)方法。 不建议使用此方法在 Windows XP 上因为不能创建可锁定的呈现目标纹理，并会降低性能。

## 处理设备状态

[D3DImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage)类管理两个显示缓冲区，称为*后台缓冲区*并且*前台缓冲区*。 后台缓冲区是 Direct3D 图面。 对后台缓冲区的更改复制前滚到前台缓冲区调用时[Unlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage.unlock)方法，其中显示在硬件。 有时，前台缓冲区变得不可用。 缺乏可用性可能引起屏幕锁定、 全屏独占 Direct3D 应用程序、 用户切换或其他系统活动。 在 WPF 应用程序时出现这种情况，通过处理通知[IsFrontBufferAvailableChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage.isfrontbufferavailablechanged)事件。 你的应用程序到前台缓冲区变得不可用的响应方式取决于是否启用了 WPF 回退到软件呈现。 [SetBackBuffer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage.setbackbuffer)方法具有一个重载采用一个参数，指定是否 WPF 回退到软件呈现。

当您调用[SetBackBuffer(D3DResourceType, IntPtr)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage.setbackbuffer#System_Windows_Interop_D3DImage_SetBackBuffer_System_Windows_Interop_D3DResourceType_System_IntPtr_)重载或调用[SetBackBuffer(D3DResourceType, IntPtr, Boolean)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage.setbackbuffer#System_Windows_Interop_D3DImage_SetBackBuffer_System_Windows_Interop_D3DResourceType_System_IntPtr_System_Boolean_)重载，并`enableSoftwareFallback`参数设置为`false`，呈现系统时前台缓冲区变得不可用和没有释放其对后台缓冲区的引用显示。 呈现系统前台缓冲区再次可用时，会引发[IsFrontBufferAvailableChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage.isfrontbufferavailablechanged)事件，以通知在 WPF 应用程序。 可以创建的事件处理程序[IsFrontBufferAvailableChanged](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage.isfrontbufferavailablechanged)重启再次使用有效的 Direct3D 图面呈现的事件。 若要重新启动呈现，必须调用[SetBackBuffer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage.setbackbuffer)。

当您调用[SetBackBuffer(D3DResourceType, IntPtr, Boolean)](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage.setbackbuffer#System_Windows_Interop_D3DImage_SetBackBuffer_System_Windows_Interop_D3DResourceType_System_IntPtr_System_Boolean_)重载，并`enableSoftwareFallback`参数设置为`true`，呈现系统保留对后台缓冲区的引用时前台缓冲区变得不可用，因此无需调用[SetBackBuffer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage.setbackbuffer)时前面再次可用时缓冲区。

当启用软件呈现时，可能存在的用户的设备变得不可用，但呈现系统将保留的引用的 Direct3D 图面。 若要检查的 Direct3D9 设备是否不可用，请调用`TestCooperativeLevel`方法。 若要检查的 Direct3D9Ex 设备调用`CheckDeviceState`方法，因为`TestCooperativeLevel`方法已弃用，并始终返回成功。 如果用户设备已变为不可用，则调用[SetBackBuffer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage.setbackbuffer)释放对后台缓冲区的 WPF 的引用。 如果你需要重置你的设备，则调用[SetBackBuffer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage.setbackbuffer)与`backBuffer`参数设置为`null`，然后调用[SetBackBuffer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage.setbackbuffer)再次使用`backBuffer`设置为有效的 Direct3D 图面。

调用`Reset`方法仅当实现多适配器支持从无效的设备中恢复。 否则为释放所有 Direct3D9 接口并完全重新创建它们。 如果适配器布局已发生更改，更改之前创建的 Direct3D9 对象不会更新。

## 处理调整大小

如果[D3DImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage)将显示最适宜的分辨率以外其固有尺寸，则图像会根据当前[BitmapScalingMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.renderoptions.bitmapscalingmode)，只不过[Bilinear](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.samplingmode#System_Windows_Media_Effects_SamplingMode_Bilinear)替换为[Fant](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.bitmapscalingmode#System_Windows_Media_BitmapScalingMode_Fant)。

如果需要更高的保真度，您必须创建一个新图面时的容器[D3DImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage)更改大小。

有三种方法可以处理调整大小。

- 参与布局系统时，并创建新的图面大小发生更改。 不要创建太多应用层，因为可能会用完可用抵或视频内存碎片。
- 等待，直到固定时间内创建新的图面从未发生调整大小事件。
- 创建[DispatcherTimer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatchertimer)，用于检查每秒钟多次容器维度。

## 多监视器优化

呈现系统移动时，可能导致性能显著降低[D3DImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage)到另一个监视器。

在上 WDDM，只要这些监视器上相同的视频卡上，并使用`Direct3DCreate9Ex`，就不会在性能下降。 如果监视器位于不同的视频卡上，性能会下降。 在 Windows XP 中，会始终会降低性能。

当[D3DImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage)将移到另一个监视器，您可以创建新的图面上相应的适配器，以还原良好的性能。

若要避免对性能产生影响，编写专门为多监视器情况的代码。 以下列表显示了一种方法来编写多监视器的代码。

1. 找到的一点[D3DImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage)中使用的屏幕空间`Visual.ProjectToScreen`方法。
2. 使用`MonitorFromPoint`GDI 方法查找的监视器的显示该点。
3. 使用`IDirect3D9::GetAdapterMonitor`法查找哪个 Direct3D9 适配器监视器已打开。
4. 如果适配器不是与后台缓冲区的适配器相同，新的监视器上创建新的后台缓冲区，并将其分配给[D3DImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage)后台缓冲区。

 备注

如果[D3DImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage)跨多台监视器，性能将会很慢，除非在 WDDM 的情况下和`IDirect3D9Ex`同一适配器上。 没有方法在这种情况下提高性能。

下面的代码示例演示如何查找当前的监视器。

C++复制

```cpp
void 
CRendererManager::SetAdapter(POINT screenSpacePoint)
{
    CleanupInvalidDevices();

    //
    // After CleanupInvalidDevices, we may not have any D3D objects. Rather than
    // recreate them here, ignore the adapter update and wait for render to recreate.
    //

    if (m_pD3D && m_rgRenderers)
    {
        HMONITOR hMon = MonitorFromPoint(screenSpacePoint, MONITOR_DEFAULTTONULL);

        for (UINT i = 0; i < m_cAdapters; ++i)
        {
            if (hMon == m_pD3D->GetAdapterMonitor(i))
            {
                m_pCurrentRenderer = m_rgRenderers[i];
                break;
            }
        }
    }
}
```

更新监视器时[D3DImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage)容器的大小或位置更改或更新使用监视器`DispatcherTimer`每秒几次更新。

## WPF 软件呈现

在以下情况下的软件中的 UI 线程中的 WPF 呈现以同步方式。

- 打印
- [BitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.bitmapeffect)
- [RenderTargetBitmap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.rendertargetbitmap)

当发生以下情况之一时，呈现系统调用[CopyBackBuffer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage.copybackbuffer)方法将复制到软件的硬件缓冲区。 默认实现将调用`GetRenderTargetData`方法与您的图面。 因为此调用发生在锁定/解锁模式之外，则可能会失败。 在这种情况下，`CopyBackBuffer`方法将返回`null`和不显示任何图像。

您可以重写[CopyBackBuffer](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage.copybackbuffer)方法，调用基实现中，如果它返回`null`，可以返回占位符[BitmapSource](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.bitmapsource)。

此外可以实现自己的软件呈现，而不是调用基实现。

> 如果在软件中，完全呈现 WPF[D3DImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage)没有显示，因为 WPF 没有前台缓冲区。

## [Performance Considerations for Direct3D9 and WPF Interoperability](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/performance-considerations-for-direct3d9-and-wpf-interoperability)

你可以通过使用承载 Direct3D9 内容[D3DImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage)类。 承载 Direct3D9 内容可能会影响应用程序的性能。 本主题介绍承载 Windows Presentation Foundation (WPF) 应用程序中的 Direct3D9 内容时优化性能的最佳做法。 这些最佳实践包括如何使用[D3DImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage)和最佳做法，当你使用的 Windows Vista，Windows XP，并且多监视器显示。

> 有关代码示例说明了这些最佳实践，请参阅[WPF 和 Direct3D9 互操作](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/wpf-and-direct3d9-interoperation)。

### 尽量少使用 D3DImage

在中托管 Direct3D9 内容[D3DImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage)实例不会使同样快如纯 Direct3D 应用程序中所示。 复制图面和刷新命令缓冲区可能成本高昂的操作。 为数[D3DImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage)实例会增加，多个刷新发生，并且性能降低的程度。 因此，应使用[D3DImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage)尽量少。

### Windows Vista 的最佳做法

与配置为使用 Windows 显示驱动程序模型 (WDDM) 显示在 Windows Vista 上获得最佳性能，创建 Direct3D9 图面上`IDirect3DDevice9Ex`设备。 这使图面上的共享。 视频卡必须支持`D3DDEVCAPS2_CAN_STRETCHRECT_FROM_TEXTURES`和`D3DCAPS2_CANSHARERESOURCE`Windows Vista 上的驱动程序功能。 任何其他设置会导致面以复制通过软件，从而显著降低性能。

 备注

如果 Windows Vista 具有配置为使用 Windows XP 显示驱动程序模型 (XDDM) 显示，在图面是始终复制通过软件，无论设置如何。 使用正确的设置和视频卡，会更好的性能在 Windows Vista 上时使用 WDDM，因为在硬件中执行图面上的副本。

### Windows XP 的最佳做法

为了获得最佳性能，在 Windows XP 中，使用 Windows XP 显示驱动程序模型 (XDDM)，创建正确的行为的可锁定表面时`IDirect3DSurface9::GetDC`调用方法。 在内部，`BitBlt`方法在硬件中的设备之间传输图面。 `GetDC`方法始终适用 XRGB 图面上。 但是，如果客户端计算机正在运行 Windows XP SP3 或 SP2，并且客户端还具有分层窗口功能的修补程序，此方法仅适用于 ARGB 图面。 视频卡必须支持`D3DDEVCAPS2_CAN_STRETCHRECT_FROM_TEXTURES`驱动程序功能。

16 位桌面显示深度可以显著降低性能。 建议使用 32 位桌面。

如果你正在开发适用于 Windows Vista 和 Windows XP，测试在 Windows XP 上的性能。 在 Windows XP 上的视频内存不足是一个问题。 此外， [D3DImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage) Windows XP 上使用更多视频内存和带宽比 Windows Vista WDDM，由于所需的额外视频内存复制。 因此，可以获得更糟糕的是 Windows vista 比 Windows XP 上是相同的视频硬件的性能。

> XDDM 是适用于 Windows XP 和 Windows Vista;但是，WDDM 是仅在 Windows Vista 上可用。

### 常规最佳做法

创建设备，请使用`D3DCREATE_MULTITHREADED`创建标记。 这会降低性能，但 WPF 呈现系统从另一个线程在此设备上调用方法。 务必遵循锁定协议正确，因此，没有两个线程同时访问设备。

如果 WPF 托管线程上执行呈现，则强烈建议您创建与设备`D3DCREATE_FPU_PRESERVE`创建标记。 如果没有此设置，D3D 呈现可以减少 WPF 双精度运算的准确性，并引入呈现问题。

平铺[D3DImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage)速度快，除非磁贴非 pow2 图面，而无需硬件支持，或如果选择平铺[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)或[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)，其中包含[D3DImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage)。

### 多监视器显示的最佳做法

如果使用了多个监视器的计算机，你应遵循前面所述的最佳做法。 也有多监视器配置的一些额外的性能注意事项。

创建后台缓冲区时，创建在特定的设备和适配器，但 WPF 可能会显示任何适配器上的前台缓冲区。 在适配器，以更新前台缓冲区之间复制会产生大量费用。 在配置为用于多个视频卡以及 WDDM 的 Windows Vista 上`IDirect3DDevice9Ex`设备，如果上一个不同的适配器，但仍相同的视频卡前台缓冲区，没有任何性能损失。 但是，在 Windows XP 和具有多个视频卡 XDDM，没有对显著的性能产生负面影响时前台缓冲区，系统会在不同于后台缓冲区的适配器。 有关详细信息，请参阅[WPF 和 Direct3D9 互操作](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/wpf-and-direct3d9-interoperation)。

### 性能摘要

下表显示了前台缓冲区更新的操作系统、 像素格式和图面上可锁定性的函数的性能。 前台缓冲区和后台缓冲区都假定为同一适配器上。 适配器配置中，根据硬件更新一些通常比软件更新快得多。

| 图面上的像素格式               | Windows Vista、 WDDM 和 9Ex | 其他 Windows Vista 配置 | Windows XP SP3 或修补程序带 SP2 | Windows XP SP2 |
| ------------------------------ | --------------------------- | ----------------------- | ------------------------------- | -------------- |
| D3DFMT_X8R8G8B8 （不是可锁定） | **硬件更新**                | 软件更新                | 软件更新                        | 软件更新       |
| D3DFMT_X8R8G8B8 (lockable)     | **硬件更新**                | 软件更新                | **硬件更新**                    | **硬件更新**   |
| D3DFMT_A8R8G8B8 （不是可锁定） | **硬件更新**                | 软件更新                | 软件更新                        | 软件更新       |
| D3DFMT_A8R8G8B8 (lockable)     | **硬件更新**                | 软件更新                | **硬件更新**                    | 软件更新       |

## [Walkthrough: Creating Direct3D9 Content for Hosting in WPF](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/walkthrough-creating-direct3d9-content-for-hosting-in-wpf)

本演练演示如何创建适用于 Windows Presentation Foundation (WPF) 应用程序中承载的 Direct3D9 内容。 承载 WPF 应用程序中的 Direct3D9 内容的详细信息，请参阅[WPF 和 Direct3D9 互操作](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/wpf-and-direct3d9-interoperation)。

在本演练中，你将要执行以下任务：

- 创建 Direct3D9 项目。
- 配置用于 WPF 应用程序中承载的 Direct3D9 项目。

完成，你将拥有一个 DLL，它包含在 WPF 应用程序中使用的 Direct3D9 内容。

### 系统必备

你需要以下组件来完成本演练：

- Visual Studio 2010。
- DirectX 9 或更高版本的 SDK。

### 创建 Direct3D9 项目

第一步是创建和配置 Direct3D9 项目。

#### 若要创建 Direct3D9 项目

1. 在名为 c + + 中创建新的 Win32 项目`D3DContent`。

   Win32 应用程序向导将打开并显示欢迎屏幕。

2. 单击 **“下一步”**。

   应用程序设置屏幕会显示。

3. 在中**应用程序类型：** 部分中，选择**DLL**选项。

4. 单击 **“完成”**。

   将生成 D3DContent 项目。

5. 在解决方案资源管理器，右键单击 D3DContent 项目并选择**属性**。

   **D3DContent 属性页**对话框随即打开。

6. 选择**C/c + +** 节点。

7. 在中**附加包含目录**字段中，指定的 DirectX 的位置包括文件夹。 此文件夹的默认位置为 %ProgramFiles%\Microsoft DirectX SDK (*版本*) \Include。

8. 双击**链接器**节点以将其展开。

9. 在中**附加库目录**字段中，指定 DirectX 库文件夹的位置。 此文件夹的默认位置为 %ProgramFiles%\Microsoft DirectX SDK (*版本*) \Lib\x86。

10. 选择**输入**节点。

11. 在中**附加依赖项**字段中，添加`d3d9.lib`和`d3dx9.lib`文件。

12. 在解决方案资源管理器，添加新模块定义文件 (.def) 名为`D3DContent.def`到项目。

### 创建 Direct3D9 内容

若要获得最佳性能，Direct3D9 内容必须使用特定的设置。 下面的代码演示如何创建具有最佳的性能特征的 Direct3D9 曲面。 有关详细信息，请参阅[Direct3D9 和 WPF 互操作性的性能注意事项](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/performance-considerations-for-direct3d9-and-wpf-interoperability)。

#### 若要创建 Direct3D9 内容

1. 使用解决方案资源管理器，将三个 c + + 类添加到名为以下的项目。

   `CRenderer` （具有虚拟析构函数）

   `CRendererManager`

   `CTriangleRenderer`

2. 在代码编辑器中打开 Renderer.h 并自动生成的代码替换为以下代码。

   C++复制

   ```cpp
   #pragma once
   
   class CRenderer
   {
   public:
       virtual ~CRenderer();
   
       HRESULT CheckDeviceState();
       HRESULT CreateSurface(UINT uWidth, UINT uHeight, bool fUseAlpha, UINT m_uNumSamples);
   
       virtual HRESULT Render() = 0;
   
       IDirect3DSurface9 *GetSurfaceNoRef() { return m_pd3dRTS; }
   
   protected:
       CRenderer();
   
       virtual HRESULT Init(IDirect3D9 *pD3D, IDirect3D9Ex *pD3DEx, HWND hwnd, UINT uAdapter);
   
       IDirect3DDevice9   *m_pd3dDevice;
       IDirect3DDevice9Ex *m_pd3dDeviceEx;
   
       IDirect3DSurface9 *m_pd3dRTS;
   
   };
   ```

3. 在代码编辑器中打开 Renderer.cpp 并自动生成的代码替换为以下代码。

   C++复制

   ```cpp
   //+-----------------------------------------------------------------------------
   //
   //  CRenderer
   //
   //      An abstract base class that creates a device and a target render 
   //      surface. Derive from this class and override Init() and Render() 
   //      to do your own rendering. See CTriangleRenderer for an example.
   
   
   //------------------------------------------------------------------------------
   
   #include "StdAfx.h"
   
   //+-----------------------------------------------------------------------------
   //
   //  Member:
   //      CRenderer ctor
   //
   //------------------------------------------------------------------------------
   CRenderer::CRenderer() : m_pd3dDevice(NULL), m_pd3dDeviceEx(NULL), m_pd3dRTS(NULL)
   {
   }
   
   //+-----------------------------------------------------------------------------
   //
   //  Member:
   //      CRenderer dtor
   //
   //------------------------------------------------------------------------------
   CRenderer::~CRenderer()
   {
       SAFE_RELEASE(m_pd3dDevice);
       SAFE_RELEASE(m_pd3dDeviceEx);
       SAFE_RELEASE(m_pd3dRTS);
   }
   
   //+-----------------------------------------------------------------------------
   //
   //  Member:
   //      CRenderer::CheckDeviceState
   //
   //  Synopsis:
   //      Returns the status of the device. 9Ex devices are a special case because 
   //      TestCooperativeLevel() has been deprecated in 9Ex.
   //
   //------------------------------------------------------------------------------
   HRESULT 
   CRenderer::CheckDeviceState()
   {
       if (m_pd3dDeviceEx)
       {
           return m_pd3dDeviceEx->CheckDeviceState(NULL);
       }
       else if (m_pd3dDevice)
       {
           return m_pd3dDevice->TestCooperativeLevel();
       }
       else
       {
           return D3DERR_DEVICELOST;
       }
   }
   
   //+-----------------------------------------------------------------------------
   //
   //  Member:
   //      CRenderer::CreateSurface
   //
   //  Synopsis:
   //      Creates and sets the render target
   //
   //------------------------------------------------------------------------------
   HRESULT
   CRenderer::CreateSurface(UINT uWidth, UINT uHeight, bool fUseAlpha, UINT m_uNumSamples)
   {
       HRESULT hr = S_OK;
   
       SAFE_RELEASE(m_pd3dRTS);
   
       IFC(m_pd3dDevice->CreateRenderTarget(
           uWidth,
           uHeight,
           fUseAlpha ? D3DFMT_A8R8G8B8 : D3DFMT_X8R8G8B8,
           static_cast<D3DMULTISAMPLE_TYPE>(m_uNumSamples),
           0,
           m_pd3dDeviceEx ? FALSE : TRUE,  // Lockable RT required for good XP perf
           &m_pd3dRTS,
           NULL
           ));
   
       IFC(m_pd3dDevice->SetRenderTarget(0, m_pd3dRTS));
   
   Cleanup:
       return hr;
   }
   
   //+-----------------------------------------------------------------------------
   //
   //  Member:
   //      CRenderer::Init
   //
   //  Synopsis:
   //      Creates the device
   //
   //------------------------------------------------------------------------------
   HRESULT 
   CRenderer::Init(IDirect3D9 *pD3D, IDirect3D9Ex *pD3DEx, HWND hwnd, UINT uAdapter)
   {
       HRESULT hr = S_OK;
   
       D3DPRESENT_PARAMETERS d3dpp;
       ZeroMemory(&d3dpp, sizeof(d3dpp));
       d3dpp.Windowed = TRUE;
       d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
       d3dpp.BackBufferHeight = 1;
       d3dpp.BackBufferWidth = 1;
       d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
   
       D3DCAPS9 caps;
       DWORD dwVertexProcessing;
       IFC(pD3D->GetDeviceCaps(uAdapter, D3DDEVTYPE_HAL, &caps));
       if ((caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT) == D3DDEVCAPS_HWTRANSFORMANDLIGHT)
       {
           dwVertexProcessing = D3DCREATE_HARDWARE_VERTEXPROCESSING;
       }
       else
       {
           dwVertexProcessing = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
       }
   
       if (pD3DEx)
       {
           IDirect3DDevice9Ex *pd3dDevice = NULL;
           IFC(pD3DEx->CreateDeviceEx(
               uAdapter,
               D3DDEVTYPE_HAL,
               hwnd,
               dwVertexProcessing | D3DCREATE_MULTITHREADED | D3DCREATE_FPU_PRESERVE,
               &d3dpp,
               NULL,
               &m_pd3dDeviceEx
               ));
   
           IFC(m_pd3dDeviceEx->QueryInterface(__uuidof(IDirect3DDevice9), reinterpret_cast<void**>(&m_pd3dDevice)));  
       }
       else 
       {
           assert(pD3D);
   
           IFC(pD3D->CreateDevice(
               uAdapter,
               D3DDEVTYPE_HAL,
               hwnd,
               dwVertexProcessing | D3DCREATE_MULTITHREADED | D3DCREATE_FPU_PRESERVE,
               &d3dpp,
               &m_pd3dDevice
               ));
       }
   
   Cleanup:
       return hr;
   }
   ```

4. 在代码编辑器中打开 RendererManager.h 并自动生成的代码替换为以下代码。

   C++复制

   ```cpp
   #pragma once
   
   class CRenderer;
   
   class CRendererManager
   {
   public:
       static HRESULT Create(CRendererManager **ppManager);
       ~CRendererManager();
   
       HRESULT EnsureDevices();
   
       void SetSize(UINT uWidth, UINT uHeight);
       void SetAlpha(bool fUseAlpha);
       void SetNumDesiredSamples(UINT uNumSamples);
       void SetAdapter(POINT screenSpacePoint);
   
       HRESULT GetBackBufferNoRef(IDirect3DSurface9 **ppSurface);
   
       HRESULT Render();
   
   private:
       CRendererManager();
   
       void CleanupInvalidDevices();
       HRESULT EnsureRenderers();
       HRESULT EnsureHWND();
       HRESULT EnsureD3DObjects();
       HRESULT TestSurfaceSettings();
       void DestroyResources();
   
       IDirect3D9    *m_pD3D;
       IDirect3D9Ex  *m_pD3DEx;
   
       UINT m_cAdapters;
       CRenderer **m_rgRenderers;
       CRenderer *m_pCurrentRenderer;
   
       HWND m_hwnd;
   
       UINT m_uWidth;
       UINT m_uHeight;
       UINT m_uNumSamples;
       bool m_fUseAlpha;
       bool m_fSurfaceSettingsChanged;
   };
   ```

5. 在代码编辑器中打开 RendererManager.cpp 并自动生成的代码替换为以下代码。

   C++复制

   ```cpp
   //+-----------------------------------------------------------------------------
   //
   //  CRendererManager
   //
   //      Manages the list of CRenderers. Managed code pinvokes into this class
   //      and this class forwards to the appropriate CRenderer.
   //
   //------------------------------------------------------------------------------
   
   #include "StdAfx.h"
   
   const static TCHAR szAppName[] = TEXT("D3DImageSample");
   typedef HRESULT (WINAPI *DIRECT3DCREATE9EXFUNCTION)(UINT SDKVersion, IDirect3D9Ex**);
   
   //+-----------------------------------------------------------------------------
   //
   //  Member:
   //      CRendererManager ctor
   //
   //------------------------------------------------------------------------------
   CRendererManager::CRendererManager() 
       : 
       m_pD3D(NULL),
       m_pD3DEx(NULL),
       m_cAdapters(0),
       m_hwnd(NULL),
       m_pCurrentRenderer(NULL),
       m_rgRenderers(NULL),
       m_uWidth(1024),
       m_uHeight(1024),
       m_uNumSamples(0),
       m_fUseAlpha(false),
       m_fSurfaceSettingsChanged(true)
   {
   
   }
   
   //+-----------------------------------------------------------------------------
   //
   //  Member:
   //      CRendererManager dtor
   //
   //------------------------------------------------------------------------------
   CRendererManager::~CRendererManager()
   {
       DestroyResources();
   
       if (m_hwnd)
       {
           DestroyWindow(m_hwnd);
           UnregisterClass(szAppName, NULL);
       }
   }
   
   //+-----------------------------------------------------------------------------
   //
   //  Member:
   //      CRendererManager::Create
   //
   //  Synopsis:
   //      Creates the manager
   //
   //------------------------------------------------------------------------------
   HRESULT
   CRendererManager::Create(CRendererManager **ppManager)
   {
       HRESULT hr = S_OK;
   
       *ppManager = new CRendererManager();
       IFCOOM(*ppManager);
   
   Cleanup:
       return hr;
   }
   
   //+-----------------------------------------------------------------------------
   //
   //  Member:
   //      CRendererManager::EnsureRenderers
   //
   //  Synopsis:
   //      Makes sure the CRenderer objects exist
   //
   //------------------------------------------------------------------------------
   HRESULT
   CRendererManager::EnsureRenderers()
   {
       HRESULT hr = S_OK;
   
       if (!m_rgRenderers)
       {
           IFC(EnsureHWND());
   
           assert(m_cAdapters);    
           m_rgRenderers = new CRenderer*[m_cAdapters];
           IFCOOM(m_rgRenderers);
           ZeroMemory(m_rgRenderers, m_cAdapters * sizeof(m_rgRenderers[0]));
   
           for (UINT i = 0; i < m_cAdapters; ++i)
           {
               IFC(CTriangleRenderer::Create(m_pD3D, m_pD3DEx, m_hwnd, i, &m_rgRenderers[i]));
           }
   
           // Default to the default adapter 
           m_pCurrentRenderer = m_rgRenderers[0];
       }
   
   Cleanup:
       return hr;
   }
   
   //+-----------------------------------------------------------------------------
   //
   //  Member:
   //      CRendererManager::EnsureHWND
   //
   //  Synopsis:
   //      Makes sure an HWND exists if we need it
   //
   //------------------------------------------------------------------------------
   HRESULT
   CRendererManager::EnsureHWND()
   {
       HRESULT hr = S_OK;
   
       if (!m_hwnd)
       {
           WNDCLASS wndclass;
   
           wndclass.style = CS_HREDRAW | CS_VREDRAW;
           wndclass.lpfnWndProc = DefWindowProc;
           wndclass.cbClsExtra = 0;
           wndclass.cbWndExtra = 0;
           wndclass.hInstance = NULL;
           wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
           wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
           wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH);
           wndclass.lpszMenuName = NULL;
           wndclass.lpszClassName = szAppName;
   
           if (!RegisterClass(&wndclass))
           {
               IFC(E_FAIL);
           }
   
           m_hwnd = CreateWindow(szAppName,
                               TEXT("D3DImageSample"),
                               WS_OVERLAPPEDWINDOW,
                               0,                   // Initial X
                               0,                   // Initial Y
                               0,                   // Width
                               0,                   // Height
                               NULL,
                               NULL,
                               NULL,
                               NULL);
       }
   
   Cleanup:
       return hr;
   }
   
   //+-----------------------------------------------------------------------------
   //
   //  Member:
   //      CRendererManager::EnsureD3DObjects
   //
   //  Synopsis:
   //      Makes sure the D3D objects exist
   //
   //------------------------------------------------------------------------------
   HRESULT
   CRendererManager::EnsureD3DObjects()
   {
       HRESULT hr = S_OK;
   
       HMODULE hD3D = NULL;
       if (!m_pD3D)
       {
           hD3D = LoadLibrary(TEXT("d3d9.dll"));
           DIRECT3DCREATE9EXFUNCTION pfnCreate9Ex = (DIRECT3DCREATE9EXFUNCTION)GetProcAddress(hD3D, "Direct3DCreate9Ex");
           if (pfnCreate9Ex)
           {
               IFC((*pfnCreate9Ex)(D3D_SDK_VERSION, &m_pD3DEx));
               IFC(m_pD3DEx->QueryInterface(__uuidof(IDirect3D9), reinterpret_cast<void **>(&m_pD3D)));
           }
           else
           {
               m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
               if (!m_pD3D) 
               {
                   IFC(E_FAIL);
               }
           }
   
           m_cAdapters = m_pD3D->GetAdapterCount();
       }
   
   Cleanup:
       if (hD3D)
       {
           FreeLibrary(hD3D);
       }
   
       return hr;
   }
   
   //+-----------------------------------------------------------------------------
   //
   //  Member:
   //      CRendererManager::CleanupInvalidDevices
   //
   //  Synopsis:
   //      Checks to see if any devices are bad and if so, deletes all resources
   //
   //      We could delete resources and wait for D3DERR_DEVICENOTRESET and reset
   //      the devices, but if the device is lost because of an adapter order 
   //      change then our existing D3D objects would have stale adapter 
   //      information. We'll delete everything to be safe rather than sorry.
   //
   //------------------------------------------------------------------------------
   void
   CRendererManager::CleanupInvalidDevices()
   {
       for (UINT i = 0; i < m_cAdapters; ++i)
       {
           if (FAILED(m_rgRenderers[i]->CheckDeviceState()))
           {
               DestroyResources();
               break;
           }
       }
   }
   
   //+-----------------------------------------------------------------------------
   //
   //  Member:
   //      CRendererManager::GetBackBufferNoRef
   //
   //  Synopsis:
   //      Returns the surface of the current renderer without adding a reference
   //
   //      This can return NULL if we're in a bad device state.
   //
   //------------------------------------------------------------------------------
   HRESULT 
   CRendererManager::GetBackBufferNoRef(IDirect3DSurface9 **ppSurface)
   {
       HRESULT hr = S_OK;
   
       // Make sure we at least return NULL
       *ppSurface = NULL;
   
       CleanupInvalidDevices();
   
       IFC(EnsureD3DObjects());
   
       //
       // Even if we never render to another adapter, this sample creates devices
       // and resources on each one. This is a potential waste of video memory,
       // but it guarantees that we won't have any problems (e.g. out of video
       // memory) when switching to render on another adapter. In your own code
       // you may choose to delay creation but you'll need to handle the issues
       // that come with it.
       //
   
       IFC(EnsureRenderers());
   
       if (m_fSurfaceSettingsChanged)
       {
           if (FAILED(TestSurfaceSettings()))
           {
               IFC(E_FAIL);
           }
   
           for (UINT i = 0; i < m_cAdapters; ++i)
           {
               IFC(m_rgRenderers[i]->CreateSurface(m_uWidth, m_uHeight, m_fUseAlpha, m_uNumSamples));
           }
   
           m_fSurfaceSettingsChanged = false;
       }
   
       if (m_pCurrentRenderer)
       {
           *ppSurface = m_pCurrentRenderer->GetSurfaceNoRef();
       }
   
   Cleanup:
       // If we failed because of a bad device, ignore the failure for now and 
       // we'll clean up and try again next time.
       if (hr == D3DERR_DEVICELOST)
       {
           hr = S_OK;
       }
   
       return hr;
   }
   
   //+-----------------------------------------------------------------------------
   //
   //  Member:
   //      CRendererManager::TestSurfaceSettings
   //
   //  Synopsis:
   //      Checks to see if our current surface settings are allowed on all
   //      adapters.
   //
   //------------------------------------------------------------------------------
   HRESULT
   CRendererManager::TestSurfaceSettings()
   {
       HRESULT hr = S_OK;
   
       D3DFORMAT fmt = m_fUseAlpha ? D3DFMT_A8R8G8B8 : D3DFMT_X8R8G8B8;
   
       // 
       // We test all adapters because because we potentially use all adapters.
       // But even if this sample only rendered to the default adapter, you
       // should check all adapters because WPF may move your surface to
       // another adapter for you!
       //
   
       for (UINT i = 0; i < m_cAdapters; ++i)
       {
           // Can we get HW rendering?
           IFC(m_pD3D->CheckDeviceType(
               i,
               D3DDEVTYPE_HAL,
               D3DFMT_X8R8G8B8,
               fmt,
               TRUE
               )); 
   
           // Is the format okay?
           IFC(m_pD3D->CheckDeviceFormat(
               i,
               D3DDEVTYPE_HAL,
               D3DFMT_X8R8G8B8,
               D3DUSAGE_RENDERTARGET | D3DUSAGE_DYNAMIC, // We'll use dynamic when on XP
               D3DRTYPE_SURFACE,
               fmt
               ));
   
           // D3DImage only allows multisampling on 9Ex devices. If we can't 
           // multisample, overwrite the desired number of samples with 0.
           if (m_pD3DEx && m_uNumSamples > 1)
           {   
               assert(m_uNumSamples <= 16);
   
               if (FAILED(m_pD3D->CheckDeviceMultiSampleType(
                   i,
                   D3DDEVTYPE_HAL,
                   fmt,
                   TRUE,
                   static_cast<D3DMULTISAMPLE_TYPE>(m_uNumSamples),
                   NULL
                   )))
               {
                   m_uNumSamples = 0;
               }
           }
           else
           {
               m_uNumSamples = 0;
           }
       }
   
   Cleanup:
       return hr;
   }
   
   //+-----------------------------------------------------------------------------
   //
   //  Member:
   //      CRendererManager::DestroyResources
   //
   //  Synopsis:
   //      Delete all D3D resources
   //
   //------------------------------------------------------------------------------
   void 
   CRendererManager::DestroyResources()
   {
       SAFE_RELEASE(m_pD3D);
       SAFE_RELEASE(m_pD3DEx);
   
       for (UINT i = 0; i < m_cAdapters; ++i)
       {
           delete m_rgRenderers[i];
       }
       delete [] m_rgRenderers;
       m_rgRenderers = NULL;
   
       m_pCurrentRenderer = NULL;
       m_cAdapters = 0;
   
       m_fSurfaceSettingsChanged = true;
   }
   
   //+-----------------------------------------------------------------------------
   //
   //  Member:
   //      CRendererManager::SetSize
   //
   //  Synopsis:
   //      Update the size of the surface. Next render will create a new surface.
   //
   //------------------------------------------------------------------------------
   void 
   CRendererManager::SetSize(UINT uWidth, UINT uHeight)
   {
       if (uWidth != m_uWidth || uHeight != m_uHeight)
       {
           m_uWidth = uWidth;
           m_uHeight = uHeight;
           m_fSurfaceSettingsChanged = true;
       }
   }
   
   //+-----------------------------------------------------------------------------
   //
   //  Member:
   //      CRendererManager::SetAlpha
   //
   //  Synopsis:
   //      Update the format of the surface. Next render will create a new surface.
   //
   //------------------------------------------------------------------------------
   void
   CRendererManager::SetAlpha(bool fUseAlpha)
   {
       if (fUseAlpha != m_fUseAlpha)
       {
           m_fUseAlpha = fUseAlpha;
           m_fSurfaceSettingsChanged = true;
       }
   }
   
   //+-----------------------------------------------------------------------------
   //
   //  Member:
   //      CRendererManager::SetNumDesiredSamples
   //
   //  Synopsis:
   //      Update the MSAA settings of the surface. Next render will create a 
   //      new surface.
   //
   //------------------------------------------------------------------------------
   void 
   CRendererManager::SetNumDesiredSamples(UINT uNumSamples)
   {
       if (m_uNumSamples != uNumSamples)
       {
           m_uNumSamples = uNumSamples;
           m_fSurfaceSettingsChanged = true;
       }
   }
   
   //+-----------------------------------------------------------------------------
   //
   //  Member:
   //      CRendererManager::SetAdapter
   //
   //  Synopsis:
   //      Update the current renderer. Next render will use the new renderer.
   //
   //------------------------------------------------------------------------------
   void 
   CRendererManager::SetAdapter(POINT screenSpacePoint)
   {
       CleanupInvalidDevices();
   
       //
       // After CleanupInvalidDevices, we may not have any D3D objects. Rather than
       // recreate them here, ignore the adapter update and wait for render to recreate.
       //
   
       if (m_pD3D && m_rgRenderers)
       {
           HMONITOR hMon = MonitorFromPoint(screenSpacePoint, MONITOR_DEFAULTTONULL);
   
           for (UINT i = 0; i < m_cAdapters; ++i)
           {
               if (hMon == m_pD3D->GetAdapterMonitor(i))
               {
                   m_pCurrentRenderer = m_rgRenderers[i];
                   break;
               }
           }
       }
   }
   
   //+-----------------------------------------------------------------------------
   //
   //  Member:
   //      CRendererManager::Render
   //
   //  Synopsis:
   //      Forward to the current renderer
   //
   //------------------------------------------------------------------------------
   HRESULT
   CRendererManager::Render()
   {
       return m_pCurrentRenderer ? m_pCurrentRenderer->Render() : S_OK;
   }
   ```

6. 在代码编辑器中打开 TriangleRenderer.h 并自动生成的代码替换为以下代码。

   C++复制

   ```cpp
   #pragma once
   
   class CTriangleRenderer : public CRenderer
   {
   public:
       static HRESULT Create(IDirect3D9 *pD3D, IDirect3D9Ex *pD3DEx, HWND hwnd, UINT uAdapter, CRenderer **ppRenderer);
       ~CTriangleRenderer();
   
       HRESULT Render();
   
   protected:
       HRESULT Init(IDirect3D9 *pD3D, IDirect3D9Ex *pD3DEx, HWND hwnd, UINT uAdapter);
   
   private:
       CTriangleRenderer();
   
       IDirect3DVertexBuffer9 *m_pd3dVB;
   };
   ```

7. 在代码编辑器中打开 TriangleRenderer.cpp 并自动生成的代码替换为以下代码。

   C++复制

   ```cpp
   //+-----------------------------------------------------------------------------
   //
   //  CTriangleRenderer
   //
   //      Subclass of CRenderer that renders a single, spinning triangle
   //
   //------------------------------------------------------------------------------
   
   #include "StdAfx.h"
   
   struct CUSTOMVERTEX
   {
       FLOAT x, y, z; 
       DWORD color;
   };
   
   #define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ | D3DFVF_DIFFUSE)
   
   //+-----------------------------------------------------------------------------
   //
   //  Member:
   //      CTriangleRenderer ctor
   //
   //------------------------------------------------------------------------------
   CTriangleRenderer::CTriangleRenderer() : CRenderer(), m_pd3dVB(NULL)
   {
   }
   
   //+-----------------------------------------------------------------------------
   //
   //  Member:
   //      CTriangleRenderer dtor
   //
   //------------------------------------------------------------------------------
   CTriangleRenderer::~CTriangleRenderer()
   {
       SAFE_RELEASE(m_pd3dVB);
   }
   
   //+-----------------------------------------------------------------------------
   //
   //  Member:
   //      CTriangleRenderer::Create
   //
   //  Synopsis:
   //      Creates the renderer
   //
   //------------------------------------------------------------------------------
   HRESULT 
   CTriangleRenderer::Create(IDirect3D9 *pD3D, IDirect3D9Ex *pD3DEx, HWND hwnd, UINT uAdapter, CRenderer **ppRenderer)
   {
       HRESULT hr = S_OK;
       
       CTriangleRenderer *pRenderer = new CTriangleRenderer();
       IFCOOM(pRenderer);
   
       IFC(pRenderer->Init(pD3D, pD3DEx, hwnd, uAdapter));
   
       *ppRenderer = pRenderer;
       pRenderer = NULL;
   
   Cleanup:
       delete pRenderer;
   
       return hr;
   }
   
   //+-----------------------------------------------------------------------------
   //
   //  Member:
   //      CTriangleRenderer::Init
   //
   //  Synopsis:
   //      Override of CRenderer::Init that calls base to create the device and 
   //      then creates the CTriangleRenderer-specific resources
   //
   //------------------------------------------------------------------------------
   HRESULT 
   CTriangleRenderer::Init(IDirect3D9 *pD3D, IDirect3D9Ex *pD3DEx, HWND hwnd, UINT uAdapter)
   {
       HRESULT hr = S_OK;
       D3DXMATRIXA16 matView, matProj;
       D3DXVECTOR3 vEyePt(0.0f, 0.0f,-5.0f);
       D3DXVECTOR3 vLookatPt(0.0f, 0.0f, 0.0f);
       D3DXVECTOR3 vUpVec(0.0f, 1.0f, 0.0f);
   
       // Call base to create the device and render target
       IFC(CRenderer::Init(pD3D, pD3DEx, hwnd, uAdapter));
   
       // Set up the VB
       CUSTOMVERTEX vertices[] =
       {
           { -1.0f, -1.0f, 0.0f, 0xffff0000, }, // x, y, z, color
           {  1.0f, -1.0f, 0.0f, 0xff00ff00, },
           {  0.0f,  1.0f, 0.0f, 0xff00ffff, },
       };
   
       IFC(m_pd3dDevice->CreateVertexBuffer(sizeof(vertices), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &m_pd3dVB, NULL));
   
       void *pVertices;
       IFC(m_pd3dVB->Lock(0, sizeof(vertices), &pVertices, 0));
       memcpy(pVertices, vertices, sizeof(vertices));
       m_pd3dVB->Unlock();
   
       // Set up the camera
       D3DXMatrixLookAtLH(&matView, &vEyePt, &vLookatPt, &vUpVec);
       IFC(m_pd3dDevice->SetTransform(D3DTS_VIEW, &matView));
       D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4, 1.0f, 1.0f, 100.0f);
       IFC(m_pd3dDevice->SetTransform(D3DTS_PROJECTION, &matProj));
   
       // Set up the global state
       IFC(m_pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE));
       IFC(m_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE));
       IFC(m_pd3dDevice->SetStreamSource(0, m_pd3dVB, 0, sizeof(CUSTOMVERTEX)));
       IFC(m_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX));
   
   Cleanup:
       return hr;
   }
   
   //+-----------------------------------------------------------------------------
   //
   //  Member:
   //      CTriangleRenderer::Render
   //
   //  Synopsis:
   //      Renders the rotating triangle
   //
   //------------------------------------------------------------------------------
   HRESULT
   CTriangleRenderer::Render()
   {
       HRESULT hr = S_OK;
       D3DXMATRIXA16 matWorld;
   
       IFC(m_pd3dDevice->BeginScene());
       IFC(m_pd3dDevice->Clear(
           0,
           NULL,
           D3DCLEAR_TARGET,
           D3DCOLOR_ARGB(128, 0, 0, 128),  // NOTE: Premultiplied alpha!
           1.0f,
           0
           ));
   
       // Set up the rotation
       UINT  iTime  = GetTickCount() % 1000;
       FLOAT fAngle = iTime * (2.0f * D3DX_PI) / 1000.0f;
       D3DXMatrixRotationY(&matWorld, fAngle);
       IFC(m_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld));
   
       IFC(m_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1));
   
       IFC(m_pd3dDevice->EndScene());
   
   Cleanup:
       return hr;
   }
   ```

8. 在代码编辑器中打开 stdafx.h 和自动生成的代码替换为以下代码。

   C++复制

   ```cpp
   // stdafx.h : include file for standard system include files,
   // or project specific include files that are used frequently, but
   // are changed infrequently
   //
   
   #pragma once
   
   #define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
   // Windows Header Files:
   #include <windows.h>
   
   #include <d3d9.h>
   #include <d3dx9.h>
   
   #include <assert.h>
   
   #include "RendererManager.h"
   #include "Renderer.h"
   #include "TriangleRenderer.h"
   
   #define IFC(x) { hr = (x); if (FAILED(hr)) goto Cleanup; }
   #define IFCOOM(x) { if ((x) == NULL) { hr = E_OUTOFMEMORY; IFC(hr); } }
   #define SAFE_RELEASE(x) { if (x) { x->Release(); x = NULL; } }
   ```

9. 在代码编辑器中打开 dllmain.cpp 并自动生成的代码替换为以下代码。

   C++复制

   ```cpp
   // dllmain.cpp : Defines the entry point for the DLL application.
   #include "stdafx.h"
   
   BOOL APIENTRY DllMain( HMODULE hModule,
                          DWORD  ul_reason_for_call,
                          LPVOID lpReserved
                        )
   {
       switch (ul_reason_for_call)
       {
       case DLL_PROCESS_ATTACH:
       case DLL_THREAD_ATTACH:
       case DLL_THREAD_DETACH:
       case DLL_PROCESS_DETACH:
           break;
       }
       return TRUE;
   }
   
   static CRendererManager *pManager = NULL;
   
   static HRESULT EnsureRendererManager()
   {
       return pManager ? S_OK : CRendererManager::Create(&pManager);
   }
   
   extern "C" HRESULT WINAPI SetSize(UINT uWidth, UINT uHeight)
   {
       HRESULT hr = S_OK;
   
       IFC(EnsureRendererManager());
   
       pManager->SetSize(uWidth, uHeight);
   
   Cleanup:
       return hr;
   }
   
   extern "C" HRESULT WINAPI SetAlpha(BOOL fUseAlpha)
   {
       HRESULT hr = S_OK;
   
       IFC(EnsureRendererManager());
   
       pManager->SetAlpha(!!fUseAlpha);
   
   Cleanup:
       return hr;
   }
   
   extern "C" HRESULT WINAPI SetNumDesiredSamples(UINT uNumSamples)
   {
       HRESULT hr = S_OK;
   
       IFC(EnsureRendererManager());
   
       pManager->SetNumDesiredSamples(uNumSamples);
   
   Cleanup:
       return hr;
   }
   
   extern "C" HRESULT WINAPI SetAdapter(POINT screenSpacePoint)
   {
       HRESULT hr = S_OK;
   
       IFC(EnsureRendererManager());
   
       pManager->SetAdapter(screenSpacePoint);
   
   Cleanup:
       return hr;
   }
   
   extern "C" HRESULT WINAPI GetBackBufferNoRef(IDirect3DSurface9 **ppSurface)
   {
       HRESULT hr = S_OK;
   
       IFC(EnsureRendererManager());
   
       IFC(pManager->GetBackBufferNoRef(ppSurface));
   
   Cleanup:
       return hr;
   }
   
   extern "C" HRESULT WINAPI Render()
   {
       assert(pManager);
   
       return pManager->Render();
   }
   
   extern "C" void WINAPI Destroy()
   {
       delete pManager;
       pManager = NULL;
   }
   ```

10. 在代码编辑器中打开 D3DContent.def。

11. 自动生成的代码替换为以下代码。

    复制

    ```
    LIBRARY "D3DContent"
    
    EXPORTS
    
    SetSize
    SetAlpha
    SetNumDesiredSamples
    SetAdapter
    
    GetBackBufferNoRef
    Render
    Destroy
    ```

12. 生成项目。

###  后续步骤

- 承载 Direct3D9 内容在 WPF 应用程序。 有关详细信息，请参见[演练：承载 Direct3D9 内容在 WPF 中的](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/walkthrough-hosting-direct3d9-content-in-wpf)。

## [Walkthrough: Hosting Direct3D9 Content in WPF](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/walkthrough-hosting-direct3d9-content-in-wpf)

本演练演示如何承载 Windows Presentation Foundation (WPF) 应用程序中的 Direct3D9 内容。

在本演练中，你将要执行以下任务：

- 创建用于承载 Direct3D9 内容的 WPF 项目。
- 导入的 Direct3D9 内容。
- 使用显示 Direct3D9 内容[D3DImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage)类。

完成后，您将知道如何进行承载 Direct3D9 内容在 WPF 应用程序。

### 系统必备

你需要以下组件来完成本演练：

- Visual Studio。
- DirectX 9 或更高版本的 SDK。
- 包含 WPF 兼容格式的 Direct3D9 内容的 DLL。 有关详细信息，请参阅[WPF 和 Direct3D9 互操作](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/wpf-and-direct3d9-interoperation)和[演练：创建在 WPF 中承载的 Direct3D9 内容](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/walkthrough-creating-direct3d9-content-for-hosting-in-wpf)。

### 创建 WPF 项目

第一步是创建 WPF 应用程序的项目。

#### 创建 WPF 项目

- 新的 WPF 应用程序项目中 Visual C# 创建名为`D3DHost`。 有关详细信息，请参阅[如何：创建新的 WPF 应用程序项目](https://msdn.microsoft.com/library/1f6aea7a-33e1-4d3f-8555-1daa42e95d82)。

  在中打开 MainWindow.xaml WPF 设计器。

### 导入的 Direct3D9 内容

使用导入的 Direct3D9 内容从非托管 DLL`DllImport`属性。

#### 要导入 Direct3D9 内容

1. 打开 MainWindow.xaml.cs 在代码编辑器中。

2. 自动生成的代码替换为以下代码。

   C#复制

   ```csharp
   using System;
   using System.Collections.Generic;
   using System.Linq;
   using System.Text;
   using System.Windows;
   using System.Windows.Controls;
   using System.Windows.Data;
   using System.Windows.Documents;
   using System.Windows.Input;
   using System.Windows.Interop;
   using System.Windows.Media;
   using System.Windows.Media.Imaging;
   using System.Windows.Navigation;
   using System.Windows.Shapes;
   using System.Windows.Threading;
   using System.Runtime.InteropServices;
   using System.Security.Permissions;
   
   namespace D3DHost
   {
       public partial class MainWindow : Window
       {
           public MainWindow()
           {
               InitializeComponent();
   
               // Set up the initial state for the D3DImage.
               HRESULT.Check(SetSize(512, 512));
               HRESULT.Check(SetAlpha(false));
               HRESULT.Check(SetNumDesiredSamples(4));
   
               // 
               // Optional: Subscribing to the IsFrontBufferAvailableChanged event.
               //
               // If you don't render every frame (e.g. you only render in 
               // reaction to a button click), you should subscribe to the
               // IsFrontBufferAvailableChanged event to be notified when rendered content 
               // is no longer being displayed. This event also notifies you when 
               // the D3DImage is capable of being displayed again. 
               
               // For example, in the button click case, if you don't render again when 
               // the IsFrontBufferAvailable property is set to true, your 
               // D3DImage won't display anything until the next button click.
               //
               // Because this application renders every frame, there is no need to
               // handle the IsFrontBufferAvailableChanged event.
               // 
               CompositionTarget.Rendering += new EventHandler(CompositionTarget_Rendering);
   
               //
               // Optional: Multi-adapter optimization
               //
               // The surface is created initially on a particular adapter.
               // If the WPF window is dragged to another adapter, WPF
               // ensures that the D3DImage still shows up on the new
               // adapter. 
               //
               // This process is slow on Windows XP.
               //
               // Performance is better on Vista with a 9Ex device. It's only 
               // slow when the D3DImage crosses a video-card boundary.
               //
               // To work around this issue, you can move your surface when
               // the D3DImage is displayed on another adapter. To
               // determine when that is the case, transform a point on the
               // D3DImage into screen space and find out which adapter
               // contains that screen space point.
               //
               // When your D3DImage straddles two adapters, nothing  
               // can be done, because one will be updating slowly.
               //
               _adapterTimer = new DispatcherTimer();
               _adapterTimer.Tick += new EventHandler(AdapterTimer_Tick);
               _adapterTimer.Interval = new TimeSpan(0, 0, 0, 0, 500);
               _adapterTimer.Start();
   
               //
               // Optional: Surface resizing
               //
               // The D3DImage is scaled when WPF renders it at a size 
               // different from the natural size of the surface. If the
               // D3DImage is scaled up significantly, image quality 
               // degrades. 
               // 
               // To avoid this, you can either create a very large
               // texture initially, or you can create new surfaces as
               // the size changes. Below is a very simple example of
               // how to do the latter.
               //
               // By creating a timer at Render priority, you are guaranteed
               // that new surfaces are created while the element
               // is still being arranged. A 200 ms interval gives
               // a good balance between image quality and performance.
               // You must be careful not to create new surfaces too 
               // frequently. Frequently allocating a new surface may 
               // fragment or exhaust video memory. This issue is more 
               // significant on XDDM than it is on WDDM, because WDDM 
               // can page out video memory.
               //
               // Another approach is deriving from the Image class, 
               // participating in layout by overriding the ArrangeOverride method, and
               // updating size in the overriden method. Performance will degrade
               // if you resize too frequently.
               //
               // Blurry D3DImages can still occur due to subpixel 
               // alignments. 
               //
               _sizeTimer = new DispatcherTimer(DispatcherPriority.Render);
               _sizeTimer.Tick += new EventHandler(SizeTimer_Tick);
               _sizeTimer.Interval = new TimeSpan(0, 0, 0, 0, 200);
               _sizeTimer.Start();
           }
   
           ~MainWindow()
           {
               Destroy();
           }
   
           void AdapterTimer_Tick(object sender, EventArgs e)
           {
               POINT p = new POINT(imgelt.PointToScreen(new Point(0, 0)));
   
               HRESULT.Check(SetAdapter(p));
           }
   
           void SizeTimer_Tick(object sender, EventArgs e)
           {
               // The following code does not account for RenderTransforms.
               // To handle that case, you must transform up to the root and 
               // check the size there.
   
               // Given that the D3DImage is at 96.0 DPI, its Width and Height 
               // properties will always be integers. ActualWidth/Height 
               // may not be integers, so they are cast to integers. 
               uint actualWidth = (uint)imgelt.ActualWidth;
               uint actualHeight = (uint)imgelt.ActualHeight;
               if ((actualWidth > 0 && actualHeight > 0) &&
                   (actualWidth != (uint)d3dimg.Width || actualHeight != (uint)d3dimg.Height))
               {
                   HRESULT.Check(SetSize(actualWidth, actualHeight));
               }
           }
   
           void CompositionTarget_Rendering(object sender, EventArgs e)
           {
               RenderingEventArgs args = (RenderingEventArgs)e;
   
               // It's possible for Rendering to call back twice in the same frame 
               // so only render when we haven't already rendered in this frame.
               if (d3dimg.IsFrontBufferAvailable && _lastRender != args.RenderingTime)
               {
                   IntPtr pSurface = IntPtr.Zero;
                   HRESULT.Check(GetBackBufferNoRef(out pSurface));
                   if (pSurface != IntPtr.Zero)
                   {
                       d3dimg.Lock();
                       // Repeatedly calling SetBackBuffer with the same IntPtr is 
                       // a no-op. There is no performance penalty.
                       d3dimg.SetBackBuffer(D3DResourceType.IDirect3DSurface9, pSurface);
                       HRESULT.Check(Render());
                       d3dimg.AddDirtyRect(new Int32Rect(0, 0, d3dimg.PixelWidth, d3dimg.PixelHeight));
                       d3dimg.Unlock();
   
                       _lastRender = args.RenderingTime;
                   }
               }
           }
   
           DispatcherTimer _sizeTimer;
           DispatcherTimer _adapterTimer;
           TimeSpan _lastRender;
   
           // Import the methods exported by the unmanaged Direct3D content.
   
           [DllImport("D3DCode.dll")]
           static extern int GetBackBufferNoRef(out IntPtr pSurface);
   
           [DllImport("D3DCode.dll")]
           static extern int SetSize(uint width, uint height);
   
           [DllImport("D3DCode.dll")]
           static extern int SetAlpha(bool useAlpha);
   
           [DllImport("D3DCode.dll")]
           static extern int SetNumDesiredSamples(uint numSamples);
   
           [StructLayout(LayoutKind.Sequential)]
           struct POINT
           {
               public POINT(Point p)
               {
                   x = (int)p.X;
                   y = (int)p.Y;
               }
   
               public int x;
               public int y;
           }
   
           [DllImport("D3DCode.dll")]
           static extern int SetAdapter(POINT screenSpacePoint);
   
           [DllImport("D3DCode.dll")]
           static extern int Render();
   
           [DllImport("D3DCode.dll")]
           static extern void Destroy();
       }
   
       public static class HRESULT
       {
           [SecurityPermissionAttribute(SecurityAction.Demand, Flags = SecurityPermissionFlag.UnmanagedCode)]
           public static void Check(int hr)
           {
               Marshal.ThrowExceptionForHR(hr);
           }
       }
   }
   ```

### 承载 Direct3D9 内容

最后，使用[D3DImage](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.interop.d3dimage)类以承载 Direct3D9 内容。

#### 若要承载 Direct3D9 内容

1. 在 MainWindow.xaml 中，自动生成的 XAML 将替换为以下 XAML。

   XAML复制

   ```xaml
       <Window x:Class="D3DHost.MainWindow"
       xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
       xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
       xmlns:i="clr-namespace:System.Windows.Interop;assembly=PresentationCore"
       Title="MainWindow" Height="300" Width="300" Background="PaleGoldenrod">
       <Grid>
           <Image x:Name="imgelt">
               <Image.Source>
                   <i:D3DImage x:Name="d3dimg" />
               </Image.Source>
           </Image>
       </Grid>
   </Window>
   ```

2. 生成项目。

3. 将复制到 bin/Debug 文件夹的 Direct3D9 内容包含的 DLL。

4. 按 F5 运行项目。

   Direct3D9 内容出现在 WPF 应用程序。