# [WPF Unmanaged API Reference](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/wpf-unmanaged-api-reference)

Windows Presentation Foundation (WPF) 库公开一系列旨在仅供内部使用的非托管函数。 它们不应从用户代码调用。

[Activate 函数](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/activate-function-wpf-unmanaged-api-reference)
[CreateIDispatchSTAForwarder 函数](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/createidispatchstaforwarder-function-wpf-unmanaged-api-reference)
[Deactivate 函数](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/deactivate-function-wpf-unmanaged-api-reference)
[ForwardTranslateAccelerator 函数](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/forwardtranslateaccelerator-function-wpf-unmanaged-api-reference)
[LoadFromHistory 函数](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/loadfromhistory-function-wpf-unmanaged-api-reference)
[ProcessUnhandledException 函数](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/processunhandledexception-function-wpf-unmanaged-api-reference)
[SaveToHistory 函数](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/savetohistory-function-wpf-unmanaged-api-reference)
[SetFakeActiveWindow 函数](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/setfakeactivewindow-function-wpf-unmanaged-api-reference)

## [Activate Function](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/activate-function-wpf-unmanaged-api-reference)

此 API 支持 Windows Presentation Foundation (WPF) 基础结构，不应在代码中直接使用。

Windows Presentation Foundation (WPF) 基础结构使用的 windows 管理。

### 语法

```cpp
void Activate(  
    const ActivateParameters* pParameters,  
    __deref_out_ecount(1) LPUNKNOWN* ppInner,  
    );  
```

#### 参数

pParameters
指向窗口的激活参数的指针。

ppInner
指向包含一个指向单个元素缓冲区的地址的指针[IOleDocument](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.visualstudio.ole.interop.ioledocument)对象。

### 要求

**平台：** 请参阅[.NET Framework 系统需求](https://docs.microsoft.com/zh-cn/dotnet/framework/get-started/system-requirements)。

**DLL:**

在.NET Framework 3.0 和 3.5:PresentationHostDLL.dll

在.NET Framework 4 及更高版本：PresentationHost_v0400.dll

**.NET framework 版本：** 4.6、4.5.2、4.5.1、4.5、4、3.5 SP1、3.5、3.0 SP1、3.0

## [CreateIDispatchSTAForwarder Function](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/createidispatchstaforwarder-function-wpf-unmanaged-api-reference)

此 API 支持 Windows Presentation Foundation (WPF) 基础结构，不应在代码中直接使用。

Windows Presentation Foundation (WPF) 基础结构使用的线程和 windows 管理。

### 语法

```cpp
HRESULT CreateIDispatchSTAForwarder(  
   __in IDispatch *pDispatchDelegate,   
   __deref_out IDispatch **ppForwarder  
)  
```

#### 参数

### 属性值/返回值

pDispatchDelegate
一个指向`IDispatch`接口。

ppForwarder
指向的地址的指针`IDispatch`接口。

### 要求

**平台：** 请参阅[.NET Framework 系统需求](https://docs.microsoft.com/zh-cn/dotnet/framework/get-started/system-requirements)。

**DLL:**

在.NET Framework 3.0 和 3.5:PresentationHostDLL.dll

在.NET Framework 4 及更高版本：PresentationHost_v0400.dll

**.NET framework 版本：** 4.6、4.5.2、4.5.1、4.5、4、3.5 SP1、3.5、3.0 SP1、3.0

## [Deactivate Function](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/deactivate-function-wpf-unmanaged-api-reference)

此 API 支持 Windows Presentation Foundation (WPF) 基础结构，不应在代码中直接使用。

Windows Presentation Foundation (WPF) 基础结构使用的 windows 管理。

### 语法

```cpp
void Deactivate()  
```

### 要求

**平台：** 请参阅[.NET Framework 系统需求](https://docs.microsoft.com/zh-cn/dotnet/framework/get-started/system-requirements)。

**DLL:**

在.NET Framework 3.0 和 3.5:PresentationHostDLL.dll

在.NET Framework 4 及更高版本：PresentationHost_v0400.dll

**.NET framework 版本：** 4.6、4.5.2、4.5.1、4.5、4、3.5 SP1、3.5、3.0 SP1、3.0

## [ForwardTranslateAccelerator Function](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/forwardtranslateaccelerator-function-wpf-unmanaged-api-reference)

此 API 支持 Windows Presentation Foundation (WPF) 基础结构，不应在代码中直接使用。

Windows Presentation Foundation (WPF) 基础结构使用的 windows 管理。

### 语法

```cpp
HRESULT ForwardTranslateAccelerator(  
   MSG* pMsg,   
   VARIANT_BOOL appUnhandled  
)  
```

#### 参数

pMsg
一条消息指向的指针。

appUnhandled
`true` 当应用程序已提供有机会处理输入的消息，但不是处理它;否则为`false`。

### 要求

**平台：** 请参阅[.NET Framework 系统需求](https://docs.microsoft.com/zh-cn/dotnet/framework/get-started/system-requirements)。

**DLL:**

在.NET Framework 3.0 和 3.5:PresentationHostDLL.dll

在.NET Framework 4 及更高版本：PresentationHost_v0400.dll

**.NET framework 版本：** 4.6、4.5.2、4.5.1、4.5、4、3.5 SP1、3.5、3.0 SP1、3.0

## [LoadFromHistory Function](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/loadfromhistory-function-wpf-unmanaged-api-reference)

此 API 支持 Windows Presentation Foundation (WPF) 基础结构，不应在代码中直接使用。

Windows Presentation Foundation (WPF) 基础结构使用的 windows 管理。

### 语法

```cpp
HRESULT LoadFromHistory_export(  
        IStream* pHistoryStream,   
        IBindCtx* pBindCtx  
)  
```

#### 参数

pHistoryStream
指向流的历史记录信息的指针。

pBindCtx
指向绑定上下文的指针。

### 要求

**平台：** 请参阅[.NET Framework 系统需求](https://docs.microsoft.com/zh-cn/dotnet/framework/get-started/system-requirements)。

**DLL:**

在.NET Framework 3.0 和 3.5:PresentationHostDLL.dll

在.NET Framework 4 及更高版本：PresentationHost_v0400.dll

**.NET framework 版本：** 4.6、4.5.2、4.5.1、4.5、4、3.5 SP1、3.5、3.0 SP1、3.0

## [ProcessUnhandledException Function](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/processunhandledexception-function-wpf-unmanaged-api-reference)

此 API 支持 Windows Presentation Foundation (WPF) 基础结构，不应在代码中直接使用。

Windows Presentation Foundation (WPF) 基础结构用于异常处理。

### 语法

```cpp
void __stdcall ProcessUnhandledException(  
   __in_ecount(1) BSTR errorMsg  
)  
```

#### 参数

errorMsg
错误消息。

### 要求

**平台：** 请参阅[.NET Framework 系统需求](https://docs.microsoft.com/zh-cn/dotnet/framework/get-started/system-requirements)。

**DLL:**

在.NET Framework 3.0 和 3.5:PresentationHostDLL.dll

在.NET Framework 4 及更高版本：PresentationHost_v0400.dll

**.NET framework 版本：** 4.6、4.5.2、4.5.1、4.5、4、3.5 SP1、3.5、3.0 SP1、3.0

## [SaveToHistory Function](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/savetohistory-function-wpf-unmanaged-api-reference)

此 API 支持 Windows Presentation Foundation (WPF) 基础结构，不应在代码中直接使用。

Windows Presentation Foundation (WPF) 基础结构使用的 windows 管理。

### 语法

```cpp
HRESULT SaveToHistory(  
   __in_ecount(1) IStream* pHistoryStream  
)  
```

#### 参数

pHistoryStream
一个指向历史记录流。

### 要求

**平台：** 请参阅[.NET Framework 系统需求](https://docs.microsoft.com/zh-cn/dotnet/framework/get-started/system-requirements)。

**DLL:**

在.NET Framework 3.0 和 3.5:PresentationHostDLL.dll

在.NET Framework 4 及更高版本：PresentationHost_v0400.dll

**.NET framework 版本：** 4.6、4.5.2、4.5.1、4.5、4、3.5 SP1、3.5、3.0 SP1、3.0

## [SetFakeActiveWindow Function](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/setfakeactivewindow-function-wpf-unmanaged-api-reference)

此 API 支持 Windows Presentation Foundation (WPF) 基础结构，不应在代码中直接使用。

Windows Presentation Foundation (WPF) 基础结构使用的 windows 管理。

### 语法

```cpp
void __stdcall SetFakeActiveWindow(  
   HWND hwnd  
)  
```

#### 参数

hwnd
窗口句柄。

### 要求

**平台：** 请参阅[.NET Framework 系统需求](https://docs.microsoft.com/zh-cn/dotnet/framework/get-started/system-requirements)。

**DLL:** PresentationHost_v0400.dll

**.NET framework 版本：** 自 4 之后可用