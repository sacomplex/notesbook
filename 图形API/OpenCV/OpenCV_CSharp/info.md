# OpenCVSharp

## 简介

[OpenCvSharp](https://github.com/shimat/opencvsharp)

Cross platform wrapper of OpenCV for .NET Framework.

## 环境配置

### 前置需求

- [OpenCV 4.0.0](http://opencv.org/) with [opencv_contrib](https://github.com/opencv/opencv_contrib)
- (Windows)[Visual C++ 2017 Redistributable Package](https://go.microsoft.com/fwlink/?LinkId=746572)
- [.NET Framework 2.0](http://www.microsoft.com/ja-jp/download/details.aspx?id=1639) or later / [.NET Core 2.0](https://www.microsoft.com/net/download) / [Mono](http://www.mono-project.com/Main_Page)

### NuGet

| Package                                   | Description                                                  | Link                                                         |
| ----------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| **OpenCvSharp4**                          | OpenCvSharp core libraries                                   | [![NuGet version](https://camo.githubusercontent.com/7619f3808a29d62f0293033e3f34cae1d679378b/68747470733a2f2f62616467652e667572792e696f2f6e752f4f70656e43765368617270342e737667)](https://badge.fury.io/nu/OpenCvSharp4) |
| **OpenCvSharp4.Windows**                  | All-in-one package for Windows - same as [OpenCvSharp3-AnyCPU](https://www.nuget.org/packages/OpenCvSharp3-AnyCPU/) | [![NuGet version](https://camo.githubusercontent.com/b38e1bec8737913d9b26c8faf5be0e2b4815ccfd/68747470733a2f2f62616467652e667572792e696f2f6e752f4f70656e43765368617270342e57696e646f77732e737667)](https://badge.fury.io/nu/OpenCvSharp4.Windows) |
| **OpenCvSharp4.runtime.win**              | Native bindings for Windows x64/x86                          | [![NuGet version](https://camo.githubusercontent.com/2d1acbc7bfa1df416b0a66273cb6634b1a6bfc26/68747470733a2f2f62616467652e667572792e696f2f6e752f4f70656e43765368617270342e72756e74696d652e77696e2e737667)](https://badge.fury.io/nu/OpenCvSharp4.runtime.win) |
| **OpenCvSharp4.runtime.ubuntu.18.04-x64** | Native bindings for Ubuntu 18.04 x64                         | [![NuGet version](https://camo.githubusercontent.com/744e2b05d6701301a14f3351ea1881406a621be3/68747470733a2f2f62616467652e667572792e696f2f6e752f4f70656e43765368617270342e72756e74696d652e7562756e74752e31382e30342d7836342e737667)](https://badge.fury.io/nu/OpenCvSharp4.runtime.ubuntu.18.04-x64) |

### Windows

方式一

- 使用NuGet为项目安装OpenCVSharp

方式二

- Add a reference to OpenCvSharp.dll (Project -> Add Reference, Browse, find DLL). 
- 将下载文件中的OpenCvSharpExtern.dll复制到可执行文件的Debug文件夹下

```c#
using System;
using System.Runtime.InteropServices;
using OpenCvSharp;

namespace WindowsFormsApplication1
{
    static class Program
    {
        static void Main()
        {
            using (IplImage image = new IplImage(128, 128, BitDepth.U8, 1)) 
            {
                image.Zero();
                for (int x = 0; x < image.Width; x++) 
                {
                    for (int y = 0; y < image.Height; y++) 
                    {
                        int offset = y * image.WidthStep + x;
                        byte value = (byte)(x + y);
                        Marshal.WriteByte(image.ImageData, offset, value);
                    }
                }
                using (CvWindow window = new CvWindow(image))
                {
                    CvWindow.WaitKey();
                }
            }
        }
    }
}
```

## OpenCVSharp Samples测试

下载[Sample-4.0.0-20181130](https://github.com/shimat/opencvsharp/releases/download/4.0.0.20181130/Sample-4.0.0-20181130.zip)

简单测试

```c#
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using OpenCvSharp;

namespace OpenCVSharpDemo
{
    class Program
    {

        static void Main(string[] args)
        {
            Mat source = new Mat(@"01.jpg", ImreadModes.Color);
            Cv2.ImShow("Demo", source);
            Cv2.WaitKey(0);
        }
    }
}
```

