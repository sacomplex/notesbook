# [3-D Graphics Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/3-d-graphics-overview)

通过 Windows Presentation Foundation (WPF) 中的 三维 功能，开发人员可以使用标记和程序代码绘制和转换 3D 图形，并对其进行动画处理。 开发人员可以合并 二维 和 三维 图形以创建丰富的控件、提供复杂的数据图解，或者增强用户对应用程序界面的体验。 WPF 中的 三维 支持并非旨在提供功能齐全的游戏开发平台。 本主题概述了WPF 图形系统中的 三维 功能。

## 2D 容器中的 3D

三维 图形中的内容WPF封装在一个元素， [Viewport3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewport3d)，该元素可以参与二维元素结构。 该图形系统将[Viewport3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewport3d)等中的许多其他的二维视觉元素作为WPF。 [Viewport3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewport3d) 为窗口函数，视区 — 到三维场景。 更准确地说，它是 三维 场景所投影到的图面。

在传统二维应用程序中，使用[Viewport3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewport3d)就像 Grid 或 Canvas 之类的另一个容器元素。 尽管可以使用[Viewport3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewport3d)与其他二维对象绘制在同一个场景图中，您不能结合二维并三维中的对象[Viewport3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewport3d)。 本主题将重点介绍如何绘制三维内的图形[Viewport3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewport3d)。

## 3D 坐标空间

二维 图形的 WPF 坐标系将原点定位在呈现区域（通常是屏幕）的左上角。 在 二维 系统中，x 轴上的正值朝右，y 轴上的正值朝下。 但是，在 三维 坐标系中，原点位于呈现区域的中心，x 轴上的正值朝右，但是 y 轴上的正值朝上，z 轴上的正值从原点向外朝向观察者。

![坐标系](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/coordsystem-1.png)
传统的 2D 和 3D 坐标系表示形式

由这些轴定义的空间是 三维 对象在 WPF 中的固定参考框架。 当在该空间中生成模型并创建光源和照相机以查看这些模型时，一定要在向每个模型应用转换时，将固定参考框架或“全局空间”与为该模型创建的局部参考框架区分开。 另请记住，根据光源和照相机设置，全局空间中的对象可能会看上去完全不同或者根本不可见，但是照相机的位置不会改变对象在全局空间中的位置。

## 照相机和投影

处理 二维 的开发人员习惯于将绘图基元置于二维屏幕上。 创建 三维 场景时，务必记住实际上是要创建 三维 对象的 二维 表示形式。 由于 三维 场景的外观会因观察者的观察位置而异，因此必须指定观察位置。 [Camera](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.camera)类，可指定这种观点的三维场景。

了解 三维 场景如何在 二维 图面上表示的另一种方法就是将场景描述为到观察表面上的投影。 [ProjectionCamera](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.projectioncamera)允许您指定不同的投影和其属性以更改观察者如何查看三维模型。 一个[PerspectiveCamera](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.perspectivecamera)指定 foreshortens 场景的投影。 换而言之，[PerspectiveCamera](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.perspectivecamera)提供消失点透视。 可以指定照相机在场景坐标系中的位置、照相机的方向和视野以及用来定义场景中“向上”方向的矢量。 下图说明了[PerspectiveCamera](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.perspectivecamera)的投影。

[NearPlaneDistance](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.projectioncamera.nearplanedistance)并[FarPlaneDistance](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.projectioncamera.farplanedistance)的属性[ProjectionCamera](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.projectioncamera)限制照相机的投影范围。 由于照相机可以位于场景中的任何位置，因此照相机实际上可能会位于模型内部或者紧靠模型，这使正确区分对象变得很困难。[NearPlaneDistance](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.projectioncamera.nearplanedistance) 可以指定从照相机超过该值将不绘制对象的最小距离。 相反， [FarPlaneDistance](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.projectioncamera.farplanedistance) ，可以指定一个距离照相机超过该值将不绘制对象，这样可以确保对象太远而无法识别不会包括在场景。

![照相机设置](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/coordsystem-6.png)
照相机位置

[OrthographicCamera](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.orthographiccamera) 指定的正交投影三维模型到二维可视化图面。 与其他照相机一样，它指定位置、观察方向和“向上”方向。 与不同[PerspectiveCamera](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.perspectivecamera)，但是，[OrthographicCamera](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.orthographiccamera)描述不包括透视收缩的投影。 换而言之，[OrthographicCamera](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.orthographiccamera)描述了一个边是并行的而不是一个其侧面汇集在照相机上的点。 下图显示了相同的模型，如使用查看[PerspectiveCamera](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.perspectivecamera)和[OrthographicCamera](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.orthographiccamera)。

![正投影和透视投影](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/camera-projections4.png)
透视投影和正投影

下面的代码演示一些典型的照相机设置。

```csharp
// Defines the camera used to view the 3D object. In order to view the 3D object,
// the camera must be positioned and pointed such that the object is within view 
// of the camera.
PerspectiveCamera myPCamera = new PerspectiveCamera();

// Specify where in the 3D scene the camera is.
myPCamera.Position = new Point3D(0, 0, 2);

// Specify the direction that the camera is pointing.
myPCamera.LookDirection = new Vector3D(0, 0, -1);

// Define camera's horizontal field of view in degrees.
myPCamera.FieldOfView = 60;

// Asign the camera to the viewport
myViewport3D.Camera = myPCamera;
```

## 模型和网格基元

[Model3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.model3d) 是表示泛型的抽象基类三维对象。 若要构建三维场景，需要某些对象，若要查看，并构成场景图对象派生自[Model3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.model3d)。 目前，WPF支持使用几何形状进行建模[GeometryModel3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.geometrymodel3d)。 [Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.geometrymodel3d.geometry)此模型的属性采用网格基元。

若要生成模型，请首先生成一个基元或网格。 三维 基元是一系列构成单个 三维 实体的顶点。 大多数 三维 系统都提供在最简单的闭合图（由三个顶点定义的三角形）上建模的基元。 由于三角形的三个点在一个平面上，因此可以继续添加三角形，以便对网格这样较为复杂的形状建模。

WPF 三维系统目前提供[MeshGeometry3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.meshgeometry3d)类，可用于指定任何几何形状; 目前不支持预定义三维基元，如球体和立方体。 开始创建[MeshGeometry3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.meshgeometry3d)通过指定为三角形顶点的列表及其[Positions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.meshgeometry3d.positions)属性。 每个顶点都指定为[Point3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.point3d)。（在 可扩展应用程序标记语言 (XAML) 中，将该属性指定为三个一组的数字列表，每组中的三个数字表示每个顶点的坐标）。根据网格的几何形状，网格可能会由多个三角形组成，有些三角形共用相同的角（顶点）。 若要正确绘制网格，WPF 需要有关哪些顶点由哪些三角形共用的信息。 通过指定的与的三角形索引列表提供此信息[TriangleIndices](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.meshgeometry3d.triangleindices)属性。 此列表指定点在指定的顺序[Positions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.meshgeometry3d.positions)列表将确定一个三角形。

XAML复制

```xaml
<GeometryModel3D>
  <GeometryModel3D.Geometry>
          <MeshGeometry3D 
              Positions="-1 -1 0  1 -1 0  -1 1 0  1 1 0"
              Normals="0 0 1  0 0 1  0 0 1  0 0 1"
              TextureCoordinates="0 1  1 1  0 0  1 0   "
              TriangleIndices="0 1 2  1 3 2" />
      </GeometryModel3D.Geometry>
      <GeometryModel3D.Material>
          <DiffuseMaterial>
              <DiffuseMaterial.Brush>
                  <SolidColorBrush Color="Cyan" Opacity="0.3"/>
              </DiffuseMaterial.Brush>
          </DiffuseMaterial>
      </GeometryModel3D.Material>
  <!-- Translate the plane. -->
      <GeometryModel3D.Transform>
          <TranslateTransform3D
            OffsetX="2" OffsetY="0" OffsetZ="-1"   >
          </TranslateTransform3D>
      </GeometryModel3D.Transform>
  </GeometryModel3D>
```

在前面的示例中，[Positions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.meshgeometry3d.positions)列表指定八个顶点来定义立方体形状的网格。 [TriangleIndices](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.meshgeometry3d.triangleindices)属性指定由三个索引的十二个组的列表。 在列表中的每个数字的偏移量是指[Positions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.meshgeometry3d.positions)列表。 例如，由指定的前三个顶点[Positions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.meshgeometry3d.positions)列表是否 (1,1,0) (0,1,0) 和 (0,0,0)。 指定的前三个索引[TriangleIndices](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.meshgeometry3d.triangleindices)列表是 0、 2 和 1，其中第三，对应于第一个和第二个中的点[Positions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.meshgeometry3d.positions)列表。 因此，构成立方体模型的第一个三角形将按照从 (1,1,0) 到 (0,1,0) 再到 (0,0,0) 的顺序组合而成，其余的十一个三角形将按照类似方式确定。

您可以继续通过指定的值定义模型[Normals](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.meshgeometry3d.normals)和[TextureCoordinates](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.meshgeometry3d.texturecoordinates)属性。 为了呈现模型的图面，图形系统需要有关曲面在任何给定三角形上的朝向信息。 图形系统使用此信息来针对该模型进行照明计算：正对光源的图面比偏离光源的图面显得更亮。 尽管 WPF 可以使用位置坐标来确定默认的法矢量，但是你还可以指定不同的法矢量来近似计算曲面的外观。

[TextureCoordinates](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.meshgeometry3d.texturecoordinates)属性指定的集合[Point](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.point)用于通知图形系统如何映射确定如何将纹理绘制到网格的顶点的坐标。[TextureCoordinates](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.meshgeometry3d.texturecoordinates) 被指定为 0 和 1 之间，非独占值。 与使用[Normals](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.meshgeometry3d.normals)属性，该图形系统可以计算默认纹理坐标，但是您可以选择设置不同的纹理坐标，例如包括重复图案一部分的纹理的映射进行控制。 有关纹理坐标的详细信息，可在后续主题或 Managed Direct3D SDK 中找到。

下面的示例演示如何在过程代码中创建立方体模型的一面。 请注意，可以将整个立方体绘制为单个 GeometryModel3D；此示例将该立方体面绘制为一个不同的模型，以便在以后向每个面应用不同的纹理。

```csharp
MeshGeometry3D side1Plane = new MeshGeometry3D();
```

```csharp
side1Plane.Positions.Add(new Point3D(-0.5, -0.5, -0.5));
side1Plane.Positions.Add(new Point3D(-0.5, 0.5, -0.5));
side1Plane.Positions.Add(new Point3D(0.5, 0.5, -0.5));
side1Plane.Positions.Add(new Point3D(0.5, 0.5, -0.5));
side1Plane.Positions.Add(new Point3D(0.5, -0.5, -0.5));
side1Plane.Positions.Add(new Point3D(-0.5, -0.5, -0.5));

side1Plane.TriangleIndices.Add(0);
side1Plane.TriangleIndices.Add(1);
side1Plane.TriangleIndices.Add(2);
side1Plane.TriangleIndices.Add(3);
side1Plane.TriangleIndices.Add(4);
side1Plane.TriangleIndices.Add(5);

side1Plane.Normals.Add(new Vector3D(0, 0, -1));
side1Plane.Normals.Add(new Vector3D(0, 0, -1));
side1Plane.Normals.Add(new Vector3D(0, 0, -1));
side1Plane.Normals.Add(new Vector3D(0, 0, -1));
side1Plane.Normals.Add(new Vector3D(0, 0, -1));
side1Plane.Normals.Add(new Vector3D(0, 0, -1));

side1Plane.TextureCoordinates.Add(new Point(1, 0));
side1Plane.TextureCoordinates.Add(new Point(1, 1));
side1Plane.TextureCoordinates.Add(new Point(0, 1));
side1Plane.TextureCoordinates.Add(new Point(0, 1));
side1Plane.TextureCoordinates.Add(new Point(0, 0));
side1Plane.TextureCoordinates.Add(new Point(1, 0));
```

## 向模型应用材料

为了使网格看上去像三维对象，必须向其应用纹理，以便覆盖由顶点和三角形定义的图面，从而使其可以由照相机照明和投影。 在中二维，则使用[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)类要应用于屏幕区域的颜色、 图案、 渐变或其他可视内容。 但是，三维 对象的外观是照明模型的功能，而不只是应用于它们的颜色或图案。 实际对象的图面质量不同，它们反射光的方式也会有所不同：光亮的图面与粗糙或不光滑的图面看上去不同，某些对象似乎可以吸收光，而某些对象似乎能够发光。 可以向 三维 对象应用与应用于 二维 对象的完全相同的画笔，但是不能直接应用它们。

定义特性的模型的图面WPF使用[Material](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.material)抽象类。 Material 的具体子类用来确定模型图面的某些外观特征，每个子类还提供一个可以向其传递 SolidColorBrush、TileBrush 或 VisualBrush 的 Brush 属性。

- [DiffuseMaterial](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.diffusematerial) 指定将向模型应用画笔，就好像该模型已漫射光来照亮。 使用 DiffuseMaterial 与直接针对 二维 模型使用画笔非常相似；模型表面不反射光，就好像是自发光一样。
- [SpecularMaterial](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.specularmaterial) 指定将向模型应用画笔，就像模型的表面坚硬或者光亮，能够反射高光。 可以通过指定的值设置到此反射特质或"，"建议纹理的程度[SpecularPower](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.specularmaterial.specularpower)属性。
- [EmissiveMaterial](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.emissivematerial) 可以指定将应用纹理，就好像模型所发出的光与画笔的颜色。 这不会使模型成为光源；但是它参与阴影设置的方式将不同于用 DiffuseMaterial 或 SpecularMaterial 设置纹理时的情况。

为了提高性能的背面[GeometryModel3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.geometrymodel3d)（有视图之外，因为它们是将模型从照相机在相反一侧这些人脸） 可以从场景。 若要指定[Material](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.material)若要将应用于的模型如飞机隐面，将设置该模型的[BackMaterial](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.geometrymodel3d.backmaterial)属性。

为了实现某些图面质量（如发光或发射效果），用户可能希望向模型连续应用几个不同的画笔。 可以将应用并通过重用多个材料[MaterialGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.materialgroup)类。 MaterialGroup 的子级在多个呈现过程中按照从头到尾的顺序来应用。

下面的代码示例演示如何将纯色和绘图以画笔形式应用于 三维 模型。

```xaml
<GeometryModel3D.Material>
    <DiffuseMaterial>
        <DiffuseMaterial.Brush>
            <SolidColorBrush Color="Cyan" Opacity="0.3"/>
        </DiffuseMaterial.Brush>
    </DiffuseMaterial>
</GeometryModel3D.Material>
```

```xaml
<DrawingBrush x:Key="patternBrush" Viewport="0,0,0.1,0.1" TileMode="Tile">
  <DrawingBrush.Drawing>
    <DrawingGroup>
      <DrawingGroup.Children>
        <GeometryDrawing Geometry="M0,0.1 L0.1,0 1,0.9, 0.9,1z"
          Brush="Gray" />
        <GeometryDrawing Geometry="M0.9,0 L1,0.1 0.1,1 0,0.9z"
          Brush="Gray" />
        <GeometryDrawing Geometry="M0.25,0.25 L0.5,0.125 0.75,0.25 0.5,0.5z"
          Brush="#FFFF00" />
        <GeometryDrawing Geometry="M0.25,0.75 L0.5,0.875 0.75,0.75 0.5,0.5z"
          Brush="Black" />
        <GeometryDrawing Geometry="M0.25,0.75 L0.125,0.5 0.25,0.25 0.5,0.5z"
          Brush="#FF0000" />
        <GeometryDrawing Geometry="M0.75,0.25 L0.875,0.5 0.75,0.75 0.5,0.5z"
          Brush="MediumBlue" />
      </DrawingGroup.Children>
    </DrawingGroup>
  </DrawingBrush.Drawing>
</DrawingBrush>
```

```csharp
DiffuseMaterial side5Material = new DiffuseMaterial((Brush)Application.Current.Resources["patternBrush"]);
```

## 照亮场景

与实际的光一样，三维 图形中的光能够使图面可见。 更确切地说，光确定了场景的哪个部分将包括在投影中。WPF 中的光对象创建了各种光和阴影效果，并且按照各种实际光的行为进行了建模。 必须至少在场景中包括一个光，否则模型将不可见。

下面的光派生自的基类[Light](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.light):

- [AmbientLight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.ambientlight)：提供环境照明照亮所有对象，其位置或方向无关。
- [DirectionalLight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.directionallight)：像远处的光源那样照亮。 具有方向性光源[Direction](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.directionallight.direction)指定为 Vector3D，但是没有指定的位置。
- [PointLight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.pointlight)：像近处的光源那样照亮。 PointLights 具有一个位置并从该位置投射光。 场景中的对象根据对象相对于光源的位置和距离被照亮。 [PointLightBase](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.pointlightbase) 公开[Range](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.pointlightbase.range)属性，用于确定位置距离，超过该模型将不会由光源照亮。 PointLight 还公开了多个衰减属性，这些属性确定光源的亮度如何随距离的增加而减小。 可以为光源的衰减指定恒定、线性或二次内插算法。
- [SpotLight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.spotlight)：继承自 [PointLight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.pointlight)。 Spotlights 的照亮方式与 PointLight 类似，但是它既具有位置又具有方向。这些项目中设置的锥形区域的 light[InnerConeAngle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.spotlight.innerconeangle)和[OuterConeAngle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.spotlight.outerconeangle)以度为单位指定的属性。

光源是[Model3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.model3d)对象，因此可以转换，并对光源属性，包括位置、 颜色、 方向和范围进行动画处理。

```xaml
<ModelVisual3D.Content>
    <AmbientLight Color="#333333" />
</ModelVisual3D.Content>
```

```csharp
DirectionalLight myDirLight = new DirectionalLight();
```

```csharp
myDirLight.Color = Colors.White;
myDirLight.Direction = new Vector3D(-3, -4, -5);
```

```csharp
modelGroup.Children.Add(myDirLight);
```

## 转换模型

创建模型时，它们在场景中有特定的位置。 为了在场景中移动、旋转这些模型或者更改这些模型的大小而更改用来定义模型本身的顶点不切实际。 而正如在 二维 中一样，可以向模型应用转换。

每个模型对象具有[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.model3d.transform)属性与其可以移动、 重定向或调整模型的大小。 应用转换时，实际上是按照由转换功能指定的矢量或值（以适用者为准）来偏移模型的所有点。 换言之，用户已经转换了在其中定义模型的坐标空间（“模型空间”），但是尚未更改在整个场景的坐标系（“全局空间”）中构成模型几何形状的值。

有关转换模型的详细信息，请参阅 [3D 转换概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/3-d-transformations-overview)。

## 对模型进行动画处理

WPF 三维 实现与 二维 图形参与同一个计时和动画系统。 换言之，若要对 3D 场景进行动画处理，需要对其模型的属性进行动画处理。 可以直接对基元的属性进行动画处理，但是通常很容易对用来更改模型位置或外观的转换进行动画处理。 由于转换可以应用于[Model3DGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.model3dgroup)对象、 单个模型，可以将一组动画应用于向 Model3DGroup 的子级和另一组子对象的一组动画。 还可以通过对场景的照明属性进行动画处理来实现各种视觉效果。 最后，可以选择通过对照相机的位置或视野进行动画处理来对投影本身进行动画处理。 有关 WPF 计时和动画系统的背景信息，请参阅[动画概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/animation-overview)、[演示图板概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/storyboards-overview)和 [Freezable 对象概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/freezable-objects-overview)主题。

若要对 WPF 中的对象进行动画处理，可以创建时间线、定义动画（实际上是随着时间的推移而更改某个属性值）并指定要向其应用动画的属性。 因为中的所有对象三维场景是子级[Viewport3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewport3d)，面向想要应用于场景的任何动画的属性是 Viewport3D 的属性的属性。

假设你希望实现模型看上去是在原地摇摆的效果。 可以选择要应用[RotateTransform3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.rotatetransform3d)到模型中，并从一个矢量旋转到另一个轴进行动画处理。 下面的代码示例演示如何将 Vector3DAnimation 应用于该转换的 Rotation3D 的 Axis 属性，并假设 RotateTransform3D 是应用于具有 TransformGroup 的模型的几个转换之一。

```csharp
//Define a rotation
RotateTransform3D myRotateTransform = new RotateTransform3D(new AxisAngleRotation3D(new Vector3D(0, 1, 0), 1));
```

```csharp
Vector3DAnimation myVectorAnimation = new Vector3DAnimation(new Vector3D(-1, -1, -1), new Duration(TimeSpan.FromMilliseconds(5000)));
myVectorAnimation.RepeatBehavior = RepeatBehavior.Forever;
```

```csharp
myRotateTransform.Rotation.BeginAnimation(AxisAngleRotation3D.AxisProperty, myVectorAnimation);
```

```csharp
//Add transformation to the model
cube1TransformGroup.Children.Add(myRotateTransform);
```

## 向窗口中添加 3D 内容

若要呈现场景，将添加模型和到光源[Model3DGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.model3dgroup)，然后设置[Model3DGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.model3dgroup)作为[Content](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.modelvisual3d.content)的[ModelVisual3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.modelvisual3d)。添加[ModelVisual3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.modelvisual3d)到[Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewport3d.children)的集合[Viewport3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewport3d)。 添加到相机[Viewport3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewport3d)通过设置其[Camera](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewport3d.camera)属性。

最后，添加[Viewport3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewport3d)到窗口。 当[Viewport3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewport3d)是包含作为画布，如布局元素的内容指定通过设置 Viewport3D 的大小及其[Height](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.height)和[Width](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement.width)属性 (继承自[FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement))。

```xaml
<UserControl x:Class="HostingWpfUserControlInWf.UserControl1"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    >
  
    <Grid>

      <!-- Place a Label control at the top of the view. -->
      <Label 
                HorizontalAlignment="Center" 
                TextBlock.TextAlignment="Center" 
                FontSize="20" 
                Foreground="Red" 
                Content="Model: Cone"/>

      <!-- Viewport3D is the rendering surface. -->
      <Viewport3D Name="myViewport" >

        <!-- Add a camera. -->
        <Viewport3D.Camera>
          <PerspectiveCamera 
                        FarPlaneDistance="20" 
                        LookDirection="0,0,1" 
                        UpDirection="0,1,0" 
                        NearPlaneDistance="1" 
                        Position="0,0,-3" 
                        FieldOfView="45" />
        </Viewport3D.Camera>

        <!-- Add models. -->
        <Viewport3D.Children>

          <ModelVisual3D>
            <ModelVisual3D.Content>

              <Model3DGroup >
                <Model3DGroup.Children>

                  <!-- Lights, MeshGeometry3D and DiffuseMaterial objects are added to the ModelVisual3D. -->
                  <DirectionalLight Color="#FFFFFFFF" Direction="3,-4,5" />

                  <!-- Define a red cone. -->
                  <GeometryModel3D>

                    <GeometryModel3D.Geometry>
                      <MeshGeometry3D 
    Positions="0.293893 -0.5 0.404509  0.475528 -0.5 0.154509  0 0.5 0  0.475528 -0.5 0.154509  0 0.5 0  0 0.5 0  0.475528 -0.5 0.154509  0.475528 -0.5 -0.154509  0 0.5 0  0.475528 -0.5 -0.154509  0 0.5 0  0 0.5 0  0.475528 -0.5 -0.154509  0.293893 -0.5 -0.404509  0 0.5 0  0.293893 -0.5 -0.404509  0 0.5 0  0 0.5 0  0.293893 -0.5 -0.404509  0 -0.5 -0.5  0 0.5 0  0 -0.5 -0.5  0 0.5 0  0 0.5 0  0 -0.5 -0.5  -0.293893 -0.5 -0.404509  0 0.5 0  -0.293893 -0.5 -0.404509  0 0.5 0  0 0.5 0  -0.293893 -0.5 -0.404509  -0.475528 -0.5 -0.154509  0 0.5 0  -0.475528 -0.5 -0.154509  0 0.5 0  0 0.5 0  -0.475528 -0.5 -0.154509  -0.475528 -0.5 0.154509  0 0.5 0  -0.475528 -0.5 0.154509  0 0.5 0  0 0.5 0  -0.475528 -0.5 0.154509  -0.293892 -0.5 0.404509  0 0.5 0  -0.293892 -0.5 0.404509  0 0.5 0  0 0.5 0  -0.293892 -0.5 0.404509  0 -0.5 0.5  0 0.5 0  0 -0.5 0.5  0 0.5 0  0 0.5 0  0 -0.5 0.5  0.293893 -0.5 0.404509  0 0.5 0  0.293893 -0.5 0.404509  0 0.5 0  0 0.5 0  " 
    Normals="0.7236065,0.4472139,0.5257313  0.2763934,0.4472138,0.8506507  0.5308242,0.4294462,0.7306172  0.2763934,0.4472138,0.8506507  0,0.4294458,0.9030925  0.5308242,0.4294462,0.7306172  0.2763934,0.4472138,0.8506507  -0.2763934,0.4472138,0.8506507  0,0.4294458,0.9030925  -0.2763934,0.4472138,0.8506507  -0.5308242,0.4294462,0.7306172  0,0.4294458,0.9030925  -0.2763934,0.4472138,0.8506507  -0.7236065,0.4472139,0.5257313  -0.5308242,0.4294462,0.7306172  -0.7236065,0.4472139,0.5257313  -0.858892,0.429446,0.279071  -0.5308242,0.4294462,0.7306172  -0.7236065,0.4472139,0.5257313  -0.8944269,0.4472139,0  -0.858892,0.429446,0.279071  -0.8944269,0.4472139,0  -0.858892,0.429446,-0.279071  -0.858892,0.429446,0.279071  -0.8944269,0.4472139,0  -0.7236065,0.4472139,-0.5257313  -0.858892,0.429446,-0.279071  -0.7236065,0.4472139,-0.5257313  -0.5308242,0.4294462,-0.7306172  -0.858892,0.429446,-0.279071  -0.7236065,0.4472139,-0.5257313  -0.2763934,0.4472138,-0.8506507  -0.5308242,0.4294462,-0.7306172  -0.2763934,0.4472138,-0.8506507  0,0.4294458,-0.9030925  -0.5308242,0.4294462,-0.7306172  -0.2763934,0.4472138,-0.8506507  0.2763934,0.4472138,-0.8506507  0,0.4294458,-0.9030925  0.2763934,0.4472138,-0.8506507  0.5308249,0.4294459,-0.7306169  0,0.4294458,-0.9030925  0.2763934,0.4472138,-0.8506507  0.7236068,0.4472141,-0.5257306  0.5308249,0.4294459,-0.7306169  0.7236068,0.4472141,-0.5257306  0.8588922,0.4294461,-0.27907  0.5308249,0.4294459,-0.7306169  0.7236068,0.4472141,-0.5257306  0.8944269,0.4472139,0  0.8588922,0.4294461,-0.27907  0.8944269,0.4472139,0  0.858892,0.429446,0.279071  0.8588922,0.4294461,-0.27907  0.8944269,0.4472139,0  0.7236065,0.4472139,0.5257313  0.858892,0.429446,0.279071  0.7236065,0.4472139,0.5257313  0.5308242,0.4294462,0.7306172  0.858892,0.429446,0.279071  "                   TriangleIndices="0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 " />
                    </GeometryModel3D.Geometry>

                    <GeometryModel3D.Material>
                      <DiffuseMaterial>
                        <DiffuseMaterial.Brush>
                          <SolidColorBrush 
                            Color="Red" 
                            Opacity="1.0"/>
                        </DiffuseMaterial.Brush>
                      </DiffuseMaterial>
                    </GeometryModel3D.Material>

                  </GeometryModel3D>

                </Model3DGroup.Children>
              </Model3DGroup>

            </ModelVisual3D.Content>

          </ModelVisual3D>

        </Viewport3D.Children>

      </Viewport3D>
    </Grid>
  
</UserControl>
```

## [3-D Transformations Overview](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/3-d-transformations-overview)

本主题描述如何向 Windows Presentation Foundation (WPF) 图形系统中的 3D 模型应用转换。 开发人员可以借助转换功能对模型进行重定位、大小调整和重定向，而无需更改用来定义模型的基值。

### 3D 坐标空间

三维图形中的内容Windows Presentation Foundation (WPF)封装在一个元素， [Viewport3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewport3d)，该元素可以参与二维元素结构。 该图形系统将 Viewport3D 视为一个像 Windows Presentation Foundation (WPF) 中的许多其他元素一样的二维视觉元素。 Viewport3D 充当三维场景中的窗口（即视区）。 更准确地说，它是 3D 场景所投影到的图面。 尽管可以将 Viewport3D 与其他 2D 绘图对象用在同一个场景图中，但是不能在 Viewport3D 中渗透 2D 和 3D 对象。 以下讨论中所描述的坐标空间包含在 Viewport3D 元素中。

2D 图形的 Windows Presentation Foundation (WPF) 坐标系将原点定位在呈现图面（通常是屏幕）的左上角。 在 2D 系统中，x 轴上的正值朝右，y 轴上的正值朝下。 但是在 3D 坐标系中，原点位于屏幕中心，x 轴上的正值朝右，但是 y 轴上的正值朝上，z 轴上的正值从原点向外朝向观察者。

![坐标系](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/coordsystem-1.png)
坐标系比较

由这些轴定义的空间是 3D 对象在 Windows Presentation Foundation (WPF) 中的固定参考框架。 当在该空间中生成模型并创建光源和照相机以查看这些模型时，一定要在向每个模型应用转换时，将固定参考框架或“全局空间”与为该模型创建的局部参考框架区分开。 另请记住，根据光源和照相机设置，全局空间中的对象可能会看上去完全不同或者根本不可见，但是照相机的位置不会改变对象在全局空间中的位置。

### 转换模型

创建模型时，它们在场景中有特定的位置。 为了在场景中移动、旋转这些模型或者更改这些模型的大小而更改用来定义模型本身的顶点不切实际。 而正如在 2D 中一样，可以向模型应用转换。

每个模型对象具有[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.model3d.transform)属性与其可以移动、 重定向或调整模型的大小。 应用转换时，实际上是按照由转换功能指定的矢量或值（以适用者为准）来偏移模型的所有点。 换言之，用户已经转换了在其中定义模型的坐标空间（“模型空间”），但是尚未更改在整个场景的坐标系（“全局空间”）中构成模型几何形状的值。

### 平移转换

3d 转换继承自的抽象基类[Transform3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.transform3d); 其中包括仿射转换类[TranslateTransform3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.translatetransform3d)， [ScaleTransform3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.scaletransform3d)，和[RotateTransform3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.rotatetransform3d)。 Windows Presentation Foundation (WPF) 3d 系统还提供了[MatrixTransform3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.matrixtransform3d)类可以让您在更简明的矩阵操作中指定相同的转换。

[TranslateTransform3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.translatetransform3d) 将所有点都移动 model3d 中与指定的偏移矢量的方向[OffsetX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.translatetransform3d.offsetx)， [OffsetY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.translatetransform3d.offsety)，和[OffsetZ](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.translatetransform3d.offsetz)属性。例如，假设立方体的一个顶点位于 (2,2,2)，偏移矢量 (0,1.6,1) 会将该顶点 (2,2,2) 移到 (2,3.6,3)。 该立方体的顶点在模型空间中仍位于 (2,2,2)，但是现在，该模型空间与全局空间的关系已经发生改变，因此，模型空间中的 (2,2,2) 是世界空间中的 (2,3.6,3)。

![平移图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/transforms-translate.png)
偏移后的平移

下面的代码示例演示如何应用平移。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml" >
  <DockPanel>
    <Viewbox>
      <Canvas Width="600" Height="201">

        <!-- The Viewport3D provides a rendering surface for 3-D visual content. -->
        <Viewport3D Name="MyAnimatedObject"
          ClipToBounds="True" Width="600" Height="150"
          Canvas.Left="0" Canvas.Top="10">

          <!-- Defines the camera used to view the 3D object. -->
          <Viewport3D.Camera>
            <PerspectiveCamera x:Name="myPerspectiveCamera" Position="0,0,2" LookDirection="0,0,-1" 
             FieldOfView="60" />
          </Viewport3D.Camera>

          <!-- The ModelVisual3D children contain the 3D models -->
          <Viewport3D.Children>

            <!-- This ModelVisual3D defines the light cast in the scene. Without light, the
                 3D object cannot be seen. -->
            <ModelVisual3D>
              <ModelVisual3D.Content>
                <DirectionalLight Color="#FFFFFF" Direction="-0.612372,-0.5,-0.612372" />
              </ModelVisual3D.Content>
            </ModelVisual3D>
            <ModelVisual3D>
              <ModelVisual3D.Content>
                <GeometryModel3D>

                  <!-- The geometry specifes the shape of the 3D plane. In this case, a flat sheet is created. -->
                  <GeometryModel3D.Geometry>
                    <MeshGeometry3D
                     TriangleIndices="0,1,2 3,4,5 "
                     Normals="0,0,1 0,0,1 0,0,1 0,0,1 0,0,1 0,0,1 "
                     TextureCoordinates="0,0 1,0 1,1 1,1 0,1 0,0 "
                     Positions="-0.5,-0.5,0.5 0.5,-0.5,0.5 0.5,0.5,0.5 0.5,0.5,0.5 -0.5,0.5,0.5 -0.5,-0.5,0.5 " />
                  </GeometryModel3D.Geometry>

                  <!-- The material specifies the material applied to the plane. In this case it is a linear gradient.-->
                  <GeometryModel3D.Material>
                    <MaterialGroup>
                      <DiffuseMaterial>
                        <DiffuseMaterial.Brush>
                          <SolidColorBrush Color="Cyan" Opacity="0.3"/>
                        </DiffuseMaterial.Brush>
                      </DiffuseMaterial>
                    </MaterialGroup>
                  </GeometryModel3D.Material>
                  <!-- The Transform specifies how to transform the 3D object. The OffsetX property is animated
                       in the Storyboard below. -->
                  <GeometryModel3D.Transform>
                    <TranslateTransform3D x:Name="myTranslateTransform3D" OffsetX="0" OffsetY="0" OffsetZ="0" />
                  </GeometryModel3D.Transform>
                </GeometryModel3D>
              </ModelVisual3D.Content>
            </ModelVisual3D>
          </Viewport3D.Children>
          <!-- Trigger the TranslateTransform3D animation when the 3D object loads. -->
          <Viewport3D.Triggers>
            <EventTrigger RoutedEvent="Viewport3D.Loaded">
              <BeginStoryboard>
                <Storyboard>

                  <!-- This animation animates the OffsetX property of the TranslateTransform3D. -->
                  <DoubleAnimation
                   Storyboard.TargetName="myTranslateTransform3D" 
                   Storyboard.TargetProperty="OffsetX" 
                   To="-0.8" 
                   AutoReverse="True" RepeatBehavior="Forever" />

                  <!-- If you want to animate OffsetY and/or OffsetZ, create similar DoubleAnimations
                       respectively. -->

                </Storyboard>
              </BeginStoryboard>
            </EventTrigger>
          </Viewport3D.Triggers>
        </Viewport3D>
      </Canvas>
    </Viewbox>
  </DockPanel>
</Page>
```

### 缩放转换

[ScaleTransform3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.scaletransform3d) 由中心点指定的缩放矢量更改模型的比例。 可以指定等比缩放，即在 X、Y 和 Z 轴上将模型缩放同样的值来按比例更改模型的大小。 例如，将该转换[ScaleX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform.scalex)， [ScaleY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform.scaley)，和[ScaleZ](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.scaletransform3d.scalez)属性设置为 0.5 会模型; 将相同的属性设置为 2 两倍，其在所有三个轴的刻度。

![统一 ScaleTransform3D](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/threecubes-uniformscale-1.png)
ScaleVector 示例

通过指定非等比转换（X、Y 和 Z 值不相等的缩放转换），可以使模型在一个或两个维度上拉伸或收缩，而不会影响其他维度。 例如，设置[ScaleX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform.scalex)为 1，[ScaleY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform.scaley)为 2，和[ScaleZ](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.scaletransform3d.scalez)为 1 会导致转换后的模型以高度增加一倍，但仍保持不变的 X 和 Z 轴。

默认情况下，ScaleTransform3D 会使顶点围绕原点 (0,0,0) 拉伸或收缩。 但是，如果要转换的模型不是围绕原点绘制，则围绕原点缩放模型时，模型将不会“就地”缩放。 相反，当模型的顶点与缩放矢量相乘时，缩放操作对模型的平移和缩放都会产生影响。

![通过指定中心点的三个多维数据集调整](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/threecubes-scaledwithcenter-1.png)
缩放中心示例

若要向"就地"模型，通过设置 ScaleTransform3D 的指定模型的中心[CenterX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform.centerx)， [CenterY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.scaletransform.centery)，和[CenterZ](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.scaletransform3d.centerz)属性。 这可确保图形系统缩放模型空间，然后平移该，在指定中心[Point3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.point3d)。 相反，如果模型围绕原点生成，而且指定了其他中心点，则将看到模型会背离原点平移。

### 旋转转换

可以通过几种不同的方法来旋转 3D 模型。 典型的旋转转换指定一个轴以及围绕该轴旋转的角度。[RotateTransform3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.rotatetransform3d)类，可定义[Rotation3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.rotation3d)使用其[Rotation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.rotatetransform3d.rotation)属性。 然后指定[Axis](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.axisanglerotation3d.axis)并[Angle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.axisanglerotation3d.angle)属性上，在此情况下在 Rotation3D [AxisAngleRotation3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.axisanglerotation3d)，来定义转换。 下面的几个示例围绕 Y 轴将模型旋转 60 度。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml" >
  <DockPanel>
    <Viewbox>
      <Canvas Width="321" Height="201">

        <!-- The Viewport3D provides a rendering surface for 3-D visual content. -->
        <Viewport3D Name="MyAnimatedObject"
          ClipToBounds="True" Width="150" Height="150"
          Canvas.Left="0" Canvas.Top="10">

          <!-- Defines the camera used to view the 3D object. -->
          <Viewport3D.Camera>
            <PerspectiveCamera x:Name="myPerspectiveCamera" Position="0,0,2" LookDirection="0,0,-1" 
             FieldOfView="60" />
          </Viewport3D.Camera>

          <!-- The ModelVisual3D children contain the 3D models -->
          <Viewport3D.Children>

            <!-- Two ModelVisual3D define the lights cast in the scene. Without light, the
                 3D object cannot be seen. Also, the direction of the lights affect shadowing. -->
            <ModelVisual3D>
              <ModelVisual3D.Content>
                <DirectionalLight Color="#FFFFFF" Direction="-0.612372,-0.5,-0.612372" />
              </ModelVisual3D.Content>
            </ModelVisual3D>
            <ModelVisual3D>
              <ModelVisual3D.Content>
                <DirectionalLight Color="#FFFFFF" Direction="0.612372,-0.5,-0.612372" />
              </ModelVisual3D.Content>
            </ModelVisual3D>
            <ModelVisual3D>
              <ModelVisual3D.Content>
                <GeometryModel3D>

                  <!-- The geometry specifes the shape of the 3D plane. In this case, a flat sheet is created. -->
                  <GeometryModel3D.Geometry>
                    <MeshGeometry3D
                     TriangleIndices="0,1,2 3,4,5 "
                     Normals="0,0,1 0,0,1 0,0,1 0,0,1 0,0,1 0,0,1 "
                     TextureCoordinates="0,0 1,0 1,1 1,1 0,1 0,0 "
                     Positions="-0.5,-0.5,0.5 0.5,-0.5,0.5 0.5,0.5,0.5 0.5,0.5,0.5 -0.5,0.5,0.5 -0.5,-0.5,0.5 " />
                  </GeometryModel3D.Geometry>

                  <!-- The material specifies the material applied to the plane. In this case it is a linear gradient.-->
                  <GeometryModel3D.Material>
                    <MaterialGroup>
                      <DiffuseMaterial>
                        <DiffuseMaterial.Brush>
                          <LinearGradientBrush StartPoint="0,0.5" EndPoint="1,0.5">
                            <LinearGradientBrush.GradientStops>
                              <GradientStop Color="Yellow" Offset="0" />
                              <GradientStop Color="Red" Offset="0.25" />
                              <GradientStop Color="Blue" Offset="0.75" />
                              <GradientStop Color="LimeGreen" Offset="1" />
                            </LinearGradientBrush.GradientStops>
                          </LinearGradientBrush>
                        </DiffuseMaterial.Brush>
                      </DiffuseMaterial>
                    </MaterialGroup>
                  </GeometryModel3D.Material>

                  <!-- The Transform specifies how to transform the 3D object. The properties of the
                        Rotation object are animated causing the 3D object to rotate and "wobble" (see Storyboard below).-->
                  <GeometryModel3D.Transform>
                    <RotateTransform3D>
                      <RotateTransform3D.Rotation>
                        <AxisAngleRotation3D x:Name="myAngleRotation" Axis="0,3,0" Angle="40" />
                      </RotateTransform3D.Rotation>
                    </RotateTransform3D>
                  </GeometryModel3D.Transform>
                </GeometryModel3D>
              </ModelVisual3D.Content>
            </ModelVisual3D>
          </Viewport3D.Children>

          <!-- Trigger the rotation animation when the 3D object loads. -->
          <Viewport3D.Triggers>
            <EventTrigger RoutedEvent="Viewport3D.Loaded">
              <BeginStoryboard>
                <Storyboard>

                  <!-- This animation animates the Angle property of the AxisAngleRotation3D
                       making the 3D object rotate from -60 degrees to 60 degrees. -->
                  <DoubleAnimation 
                   Storyboard.TargetName="myAngleRotation" 
                   Storyboard.TargetProperty="Angle" 
                   From="-60" To="60" Duration="0:0:4" AutoReverse="True"  RepeatBehavior="Forever"/>

                  <!-- This animation animates the Axis property of the AxisAngleRotation3D
                       making the 3D wobble as it rotates. -->
                  <Vector3DAnimation 
                   Storyboard.TargetName="myAngleRotation" 
                   Storyboard.TargetProperty="Axis" 
                   From="0,3,0" To="1,0,1" Duration="0:0:4" AutoReverse="True"  RepeatBehavior="Forever"/>

                </Storyboard>
              </BeginStoryboard>
            </EventTrigger>
          </Viewport3D.Triggers>
        </Viewport3D>
      </Canvas>

    </Viewbox>
  </DockPanel>
</Page>
```

注意：Windows Presentation Foundation (WPF)三维效果是一个右手系统，这意味着，旋转的正角度值会导致围绕轴逆时针旋转。

如果没有为指定一个值，轴和角度的旋转假设围绕原点旋转[CenterX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.rotatetransform3d.centerx)， [CenterY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.rotatetransform3d.centery)，和[CenterZ](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.rotatetransform3d.centerz)RotateTransform3D 上的属性。 与缩放一样，牢记旋转时会转换模型的整个坐标空间，这会很有帮助。 如果模型不是围绕原点创建，或者它以前平移过，则旋转可能会围绕原点“转动”，而不是就地旋转。

![采用新中心点旋转](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/threecubes-rotationwithcenter-1.png)
围绕指定的新中心旋转

若要“就地”旋转模型，请将模型的实际中心指定为旋转中心。 由于几何形状通常围绕原点建模，因此，在依次执行下列操作时通常将获取一组预期的转换结果：调整模型大小（缩放该模型），然后设置模型方向（旋转该模型），最后将模型移到所需的位置（平移该模型）。

![旋转 60 度 x 中-和 y-轴](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/media/twocubes-rotation2axes-1.png)
旋转示例

指定了轴和角度的旋转非常适于静态转换和某些动画。 但是，请考虑围绕 X 轴将立方体模型旋转 60 度，然后围绕 Z 轴将其旋转 45 度。 可以将这种转换描述为两个离散的仿射转换，也可以将其描述为一个矩阵。 但是，对于按照这种方式定义的旋转，可能很难顺利地进行动画处理。 尽管按照这两种方法计算的模型起始位置和结束位置相同，但是，从计算的角度来看，无法确定该模型经过的中间位置。 四元数提供了一种用来在旋转的起始位置和结束位置之间计算内插值的替代方法。

四元数表示 3D 空间中的一个轴以及围绕该轴的旋转。 例如，四元数可以表示 (1,1,2) 轴以及 50 度的旋转角度。四元数在定义旋转方面的价值在于可以针对它们执行的两个运算：合成和内插。 应用于一个几何形状的两个四元数的合成是指“围绕 axis2 将几何形状旋转 rotation2 度，然后围绕 axis1 将其旋转 rotation1 度”。 通过使用合成运算，可以将应用于几何形状的两个旋转合成在一起，以便获得一个代表合成结果的四元数。 由于四元数内插可以计算出从一个轴和方向到另一个轴和方向的顺利而又合理的路径，因此可以从原始位置到合成的四元数之间进行内插，以便实现从一个位置到另一个位置的顺利过渡，从而可以对该转换进行动画处理。 对于要进行动画处理的模型，可以指定目标[Quaternion](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.quaternion)通过使用旋转[QuaternionRotation3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.quaternionrotation3d)为[Rotation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.rotatetransform3d.rotation)属性。

### 使用转换集合

生成场景时，通常会向模型应用多个转换。 添加到转换[Children](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.transform3dgroup.children)的集合[Transform3DGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.transform3dgroup)类进行分组可以方便地转换来将应用于场景中的各种模型。 通常，可以很方便地在几个不同的组中重复使用某个转换，这与通过向每个实例应用一组不同的转换来重复使用模型大体相同。 请注意，将转换添加到集合中的顺序至关重要：集合中的转换按照从第一个到最后一个的顺序应用。

### 对转换进行动画处理

Windows Presentation Foundation (WPF) 3D 实现与 2D 图形参与同一个计时和动画系统。 换言之，若要对 3D 场景进行动画处理，需要对其模型的属性进行动画处理。 可以直接对基元的属性进行动画处理，但是通常很容易对用来更改模型位置或外观的转换进行动画处理。 由于转换可以应用于[Model3DGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.model3dgroup)对象、 单个模型，可以将一组动画应用于向 Model3Dgroup 的子级和另一组对象的一组动画。 有关 Windows Presentation Foundation (WPF)计时和动画系统的背景信息，请参阅[动画概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/animation-overview)和[演示图板概述](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/storyboards-overview)。

若要对 Windows Presentation Foundation (WPF) 中的对象进行动画处理，可以创建时间线、定义动画（实际上是随着时间的推移而更改某个属性值）并指定要向其应用动画的属性。 此属性必须是 FrameworkElement 的属性。由于 3D 场景中的所有对象都是 Viewport3D 的子级，因此要应用于场景的任何动画所面向的属性都是 Viewport3D 属性的属性。 请务必仔细设计动画的属性路径，因为语法可能会极为冗长。

假设用户希望就地旋转某个对象，而且还希望应用摆动动作以公开要查看的对象的更多内容。 可以选择向模型应用 RotateTransform3D，并对模型从一个矢量旋转到另一个矢量时所围绕的轴进行动画处理。 下面的代码示例演示如何将[Vector3DAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.vector3danimation)转换的 Rotation3D 的 Axis 属性，假设 RotateTransform3D 是应用于模型的多个转换之一[TransformGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.transformgroup)。

```csharp
//Define a rotation
RotateTransform3D myRotateTransform = new RotateTransform3D(new AxisAngleRotation3D(new Vector3D(0, 1, 0), 1));
```

```csharp
Vector3DAnimation myVectorAnimation = new Vector3DAnimation(new Vector3D(-1, -1, -1), new Duration(TimeSpan.FromMilliseconds(5000)));
myVectorAnimation.RepeatBehavior = RepeatBehavior.Forever;
```

使用类似的语法面向其他转换属性来移动或缩放该对象。 例如，您可能要应用[Point3DAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.point3danimation)到缩放转换的模型，以便顺利扭曲其形状 ScaleCenter 属性。

尽管前面的示例转换的属性[GeometryModel3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.geometrymodel3d)，还有可能要转换的场景中其他模型的属性。 例如，通过对应用于 Light 对象的平移进行动画处理来创建移动灯光和阴影效果，这些效果可以显著改变模型的外观。

由于照相机也是模型，因此也可以对照相机属性进行转换。 尽管确实可以通过改变照相机的位置或平面距离来改变场景的外观（实际上是变换整个场景的投影），但应注意，对于观察者来说，以这种方法实现的许多效果不如将转换应用于场景中模型的地点或位置更有“视觉意义”。

## [Maximize WPF 3D Performance](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/maximize-wpf-3d-performance)

因为你使用Windows Presentation Foundation (WPF)若要生成三维控件和应用程序中包含三维场景，务必要考虑性能优化。 本主题提供 3D 类和属性的可能对性能产生影响的应用程序，以及使用它们时优化性能的建议的列表。

本主题假定您了解高级的Windows Presentation Foundation (WPF)3D 功能。 本文档中的建议适用于"呈现层 2"— 大致定义为支持像素着色器版本 2.0 和顶点着色器版本 2.0 的硬件。 有关更多详细信息，请参阅[图形呈现层](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/graphics-rendering-tiers)。

### 对性能的影响：高

| 属性                                                         | 建议                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush) | 画笔速度 （最快到速度最慢）：  [SolidColorBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.solidcolorbrush)  [LinearGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.lineargradientbrush)  [ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)  [DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush) （已缓存）  [VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush) （已缓存）  [RadialGradientBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.radialgradientbrush)  [DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush) （未缓存）  [VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush) （未缓存） |
| [ClipToBoundsProperty](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.cliptoboundsproperty) | 设置`Viewport3D.ClipToBounds`为 false 时不需要具有Windows Presentation Foundation (WPF)显式剪切的内容内容[Viewport3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewport3d)到 Viewport3D 的矩形。 Windows Presentation Foundation (WPF) 抗锯齿剪辑可能会很慢，并且`ClipToBounds`（较慢） 默认情况下启用上[Viewport3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewport3d)。 |
| [IsHitTestVisible](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ishittestvisible) | 设置`Viewport3D.IsHitTestVisible`为 false 时不需要Windows Presentation Foundation (WPF)要考虑的内容[Viewport3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewport3d)执行鼠标命中测试。 命中测试的 3D 内容在软件中完成，并可能会遇到大型网格很慢。 [IsHitTestVisible](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement.ishittestvisible) （较慢） 默认情况下启用上[Viewport3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewport3d)。 |
| [GeometryModel3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.geometrymodel3d) | 仅当它们需要不同的材料或转换时，请创建不同的模型。 否则，尝试 coalesce 许多[GeometryModel3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.geometrymodel3d)实例具有相同的材料和转换成更大一些[GeometryModel3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.geometrymodel3d)和[MeshGeometry3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.meshgeometry3d)实例。 |
| [MeshGeometry3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.meshgeometry3d) | 网格动画 — 更改每个帧以在网格的各个顶点 — 并不总是有效Windows Presentation Foundation (WPF)。 若要修改的每个顶点时，最小化的更改通知的性能影响，在执行每个顶点修改之前分离从可视化树网格。 一旦已修改网格，将其重新附加到可视化树。 此外，尝试尽量减少这种方式进行动画处理的网格的大小。 |
| 3D 抗锯齿                                                    | 若要提高呈现速度上, 禁用多重采样[Viewport3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewport3d)通过设置附加的属性[EdgeMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.renderoptions.edgemode)到`Aliased`。 默认情况下上, 禁用 3D 抗锯齿Microsoft Windows XP并且在上启用Windows Vista使用每像素 4 个样本。 |
| Text                                                         | Live 三维场景中的文本 (因为它在 live[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)或[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)) 可能会很慢。 尝试改为使用映像的文本 (通过[RenderTargetBitmap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.rendertargetbitmap)) 除非文本将更改。 |
| [TileBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.tilebrush) | 如果必须使用[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)或[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)三维场景中由于画笔的内容不是静态的请尝试缓存画笔 (设置附加的属性[CachingHint](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.renderoptions.cachinghint)到`Cache`)。 设置失效阈值最小值和最大缩放 (带有附加属性[CacheInvalidationThresholdMinimum](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.renderoptions.cacheinvalidationthresholdminimum)和[CacheInvalidationThresholdMaximum](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.renderoptions.cacheinvalidationthresholdmaximum))，以便缓存的画笔都不会同时仍保持所需的质量级别过于频繁地重新生成。 默认情况下[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)和[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)未缓存，这意味着，每次使用画笔绘制的内容必须是重新呈现，画笔的整个内容必须首先重新呈现到中间的图面。 |
| [BitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.bitmapeffect) | [BitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.bitmapeffect) 强制所有受影响的内容，如果不进行硬件加速呈现。 为了获得最佳性能，不要使用[BitmapEffect](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.effects.bitmapeffect)。 |

### 对性能的影响：中等

| 属性                                                         | 建议                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [MeshGeometry3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.meshgeometry3d) | 当网格定义为邻接通过共享顶点的三角形，这些顶点拥有相同的位置、 正常、 和纹理坐标时，定义共享的每个顶点仅一次，然后通过使用索引来定义三角形[TriangleIndices](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.meshgeometry3d.triangleindices)。 |
| [ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush) | 尝试时你可以显式控制大小最大程度减少纹理大小 (当使用[RenderTargetBitmap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.rendertargetbitmap)和/或[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush))。 请注意，较低分辨率纹理可以降低视觉质量，因此尝试查找质量和性能之间的最佳平衡。 |
| 不透明度                                                     | 当呈现半透明的三维内容 （如反射），画笔或材料上使用的不透明度属性 (通过[Opacity](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush.opacity)或[Color](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.diffusematerial.color)) 而不是创建单独的半透明[Viewport3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewport3d)通过设置`Viewport3D.Opacity`为小于 1 的值。 |
| [Viewport3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewport3d) | 数量降至最低[Viewport3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewport3d)对象在场景中使用。 多个三维模型置于同一个 Viewport3D，而无需创建单独的 Viewport3D 实例为每个模型。 |
| [Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable) | 通常最好重用[MeshGeometry3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.meshgeometry3d)， [GeometryModel3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.geometrymodel3d)，画笔和材料。 所有是 multiparentable，因为它们派生自`Freezable`。 |
| [Freezable](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable) | 调用[Freeze](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.freezable.freeze)上时将保留它们的属性的可冻结对象的方法在应用程序中保持不变。 冻结可以减少工作集，并提高速度。 |
| [Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush) | 使用[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)而不是[VisualBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualbrush)或[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)时画笔的内容将不会更改。 2D 内容可以转换为[Image](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.image)通过[RenderTargetBitmap](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imaging.rendertargetbitmap)，然后再在[ImageBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.imagebrush)。 |
| [BackMaterial](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.geometrymodel3d.backmaterial) | 不要使用[BackMaterial](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.geometrymodel3d.backmaterial)除非确实需要查看的背面，否则你[GeometryModel3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.geometrymodel3d)。 |
| [Light](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.light) | 浅速度 （最快到速度最慢）：  [AmbientLight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.ambientlight)  [DirectionalLight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.directionallight)  [PointLight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.pointlight)  [SpotLight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.spotlight) |
| [MeshGeometry3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.meshgeometry3d) | 尝试使网格大小小于这些限制：  [Positions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.meshgeometry3d.positions)：20001[Point3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.point3d)实例  [TriangleIndices](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.meshgeometry3d.triangleindices)：60,003[Int32](https://docs.microsoft.com/zh-cn/dotnet/api/system.int32)实例 |
| [Material](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.material) | 材料的速度 （最快到速度最慢）：  [EmissiveMaterial](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.emissivematerial)  [DiffuseMaterial](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.diffusematerial)  [SpecularMaterial](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.specularmaterial) |
| [Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush) | Windows Presentation Foundation (WPF) 3D 不一致的方式不参与 （黑色的环境画笔、 透明画笔等） 不可见的画笔。 请考虑您的场景中省略这些画笔。 |
| [MaterialGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.materialgroup) | 每个[Material](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.material)在[MaterialGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.materialgroup)会导致另一个呈现处理过程，因此包含多个材料，甚至简单的材料，可以极大地提高了对您的 GPU 的填充要求。 中的材料的数量降至最低你[MaterialGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.materialgroup)。 |

### 对性能的影响：低

| 属性                                                         | 建议                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [Transform3DGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.transform3dgroup) | 当不需要动画或数据绑定，而不使用包含多个转换的转换组使用单个[MatrixTransform3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.matrixtransform3d)，将其设置为要转换组中将否则独立存在的所有转换的产品。 |
| [Light](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.light) | 您的场景中的光源数量降至最低。 将强制在场景中太多的光源Windows Presentation Foundation (WPF)回退到软件呈现。 限制大约为 110[DirectionalLight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.directionallight)对象，70[PointLight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.pointlight)对象或 40[SpotLight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.spotlight)对象。 |
| [ModelVisual3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.modelvisual3d) | 单独的静态对象从移动对象，通过将它们放在单独[ModelVisual3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.modelvisual3d)实例。 ModelVisual3D 高于""[GeometryModel3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.geometrymodel3d)由于缓存转换后的边界。 GeometryModel3D 经过优化，可将模型;ModelVisual3D 经过优化，可以场景节点。 使用 ModelVisual3D 放入场景 GeometryModel3D 的共享的实例。 |
| [Light](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.light) | 最大程度减少更改的灯场景中的次数。 浅计数每次更改强制着色器重新生成和重新编译，除非之前已存在该配置 （并因此缓存其着色器）。 |
| 浅                                                           | 黑色光源是不可见，但它们将添加要呈现时间;请考虑省略它们。    |
| [MeshGeometry3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.meshgeometry3d) | 若要最大程度减少大型集合中的构造时间Windows Presentation Foundation (WPF)，如 MeshGeometry3D [Positions](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.meshgeometry3d.positions)， [Normals](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.meshgeometry3d.normals)， [TextureCoordinates](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.meshgeometry3d.texturecoordinates)，和[TriangleIndices](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.meshgeometry3d.triangleindices)，预调整大小之前值填充的集合。 如果可能，请将传递集合的构造函数预先填充的数据结构，例如数组或列表。 |

## [How-to Topics](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/3-d-graphics-how-to-topics)

此部分中的主题演示如何使用三维中的图形Windows Presentation Foundation (WPF)应用程序。

### 本节内容

[创建 3D 场景](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-3-d-scene)
[向 3D 模型应用绘图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-apply-a-drawing-to-a-3-d-model)
[向 3D 对象的正面和背面应用材料](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-apply-material-to-the-front-and-back-of-a-3-d-object)
[向 3D 对象应用放射材料](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-apply-emissive-material-to-a-3-d-object)
[转换 3D 模型的比例](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-transform-the-scale-of-a-3-d-model)
[向 3D 模型应用多个转换](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-apply-multiple-transformations-to-a-3-d-model)
[为 3D 转换设置动画效果](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-animate-3-d-translations)
[使用情节提要为 3D 旋转设置动画效果](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-animate-a-3-d-rotation-using-storyboards)
[使用 Rotation3DAnimation 为 3D 旋转设置动画效果](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-animate-a-3-d-rotation-using-rotation3danimation)
[使用四元数为 3D 旋转设置动画效果](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-animate-a-3-d-rotation-using-quaternions)
[使用关键帧为 3D 旋转设置动画效果 (Rotation3DAnimationUsingKeyFrames)](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-animate-a-3-d-rotation-using-key-frames)
[使用关键帧为 3D 旋转设置动画效果 (QuaternionAnimationUsingKeyFrames)](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/animate-a-3-d-rotation-quaternionanimationusingkeyframes)
[在 3D 场景中为照相机位置和方向设置动画效果](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-animate-camera-position-and-direction-in-a-3d-scene)
[使用关键帧为照相机位置和方向设置动画效果](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-animate-camera-position-and-direction-using-key-frames)
[在 3D 场景中为材料属性设置动画效果](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-animate-material-properties-in-a-3-d-scene)
[在 Viewport3D 中进行命中测试](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-hit-test-in-a-viewport3d)
[测试 Point4D 结构是否相等](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/graphics-multimedia/how-to-test-point4d-structures-for-equality-and-inequality)

### [Create a 3-D Scene](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-create-a-3-d-scene)

此示例演示如何创建三维对象，如下所示已旋转的纸张的平面表。 一个[Viewport3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.viewport3d)以及以下组件用于创建此简单的三维场景：

- 使用创建照相机[PerspectiveCamera](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.perspectivecamera)。 照相机指定可查看三维场景的哪个部分。
- 创建一个网格，以指定的三维对象 （张纸的） 使用形状[Geometry](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.geometrymodel3d.geometry)属性的[GeometryModel3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.geometrymodel3d)。
- 材料指定要在对象 （线性渐变在此示例中） 使用的图面上显示[Material](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.geometrymodel3d.material)属性的[GeometryModel3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.geometrymodel3d)。
- 创建光照射对象使用[DirectionalLight](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.directionallight)。

#### 示例

下面的代码演示如何在 XAML 中创建三维场景。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml" >
  <DockPanel>
    <Viewbox>
      <Canvas Width="321" Height="201">

        <!-- The Viewport3D provides a rendering surface for 3-D visual content. -->
        <Viewport3D ClipToBounds="True" Width="150" Height="150" Canvas.Left="0" Canvas.Top="10">

          <!-- Defines the camera used to view the 3D object. -->
          <Viewport3D.Camera>
            <PerspectiveCamera Position="0,0,2" LookDirection="0,0,-1" FieldOfView="60" />
          </Viewport3D.Camera>

          <!-- The ModelVisual3D children contain the 3D models -->
          <Viewport3D.Children>

            <!-- This ModelVisual3D defines the light cast in the scene. Without light, the 3D 
                 object cannot be seen. Also, the direction of the lights affect shadowing. If desired,
                 you can create multiple lights with different colors that shine from different directions. -->
            <ModelVisual3D>
              <ModelVisual3D.Content>
                <DirectionalLight Color="#FFFFFF" Direction="-0.612372,-0.5,-0.612372" />
              </ModelVisual3D.Content>
            </ModelVisual3D>
            <ModelVisual3D>
              <ModelVisual3D.Content>
                <GeometryModel3D>

                  <!-- The geometry specifies the shape of the 3D plane. In this sample, a flat sheet is created. -->
                  <GeometryModel3D.Geometry>
                    <MeshGeometry3D
                     TriangleIndices="0,1,2 3,4,5 "
                     Normals="0,0,1 0,0,1 0,0,1 0,0,1 0,0,1 0,0,1 "
                     TextureCoordinates="0,0 1,0 1,1 1,1 0,1 0,0 "
                     Positions="-0.5,-0.5,0.5 0.5,-0.5,0.5 0.5,0.5,0.5 0.5,0.5,0.5 -0.5,0.5,0.5 -0.5,-0.5,0.5 " />
                  </GeometryModel3D.Geometry>

                  <!-- The material specifies the material applied to the 3D object. In this sample a linear gradient 
                       covers the surface of the 3D object.-->
                  <GeometryModel3D.Material>
                    <MaterialGroup>
                      <DiffuseMaterial>
                        <DiffuseMaterial.Brush>
                          <LinearGradientBrush StartPoint="0,0.5" EndPoint="1,0.5">
                            <LinearGradientBrush.GradientStops>
                              <GradientStop Color="Yellow" Offset="0" />
                              <GradientStop Color="Red" Offset="0.25" />
                              <GradientStop Color="Blue" Offset="0.75" />
                              <GradientStop Color="LimeGreen" Offset="1" />
                            </LinearGradientBrush.GradientStops>
                          </LinearGradientBrush>
                        </DiffuseMaterial.Brush>
                      </DiffuseMaterial>
                    </MaterialGroup>
                  </GeometryModel3D.Material>

                  <!-- Apply a transform to the object. In this sample, a rotation transform is applied, rendering the 
                       3D object rotated. -->
                  <GeometryModel3D.Transform>
                    <RotateTransform3D>
                      <RotateTransform3D.Rotation>
                        <AxisAngleRotation3D Axis="0,3,0" Angle="40" />
                      </RotateTransform3D.Rotation>
                    </RotateTransform3D>
                  </GeometryModel3D.Transform>
                </GeometryModel3D>
              </ModelVisual3D.Content>
            </ModelVisual3D>
          </Viewport3D.Children>

        </Viewport3D>
      </Canvas>
    </Viewbox>
  </DockPanel>
</Page>
```

#### 示例

下面的代码演示如何在程序代码中创建相同的三维场景。

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Media3D;

namespace SDKSample
{
    public partial class Basic3DShapeExample : Page
    {
        public Basic3DShapeExample()
        {

            // Declare scene objects.
            Viewport3D myViewport3D = new Viewport3D();
            Model3DGroup myModel3DGroup = new Model3DGroup();
            GeometryModel3D myGeometryModel = new GeometryModel3D();
            ModelVisual3D myModelVisual3D = new ModelVisual3D();
            // Defines the camera used to view the 3D object. In order to view the 3D object,
            // the camera must be positioned and pointed such that the object is within view 
            // of the camera.
            PerspectiveCamera myPCamera = new PerspectiveCamera();

            // Specify where in the 3D scene the camera is.
            myPCamera.Position = new Point3D(0, 0, 2);

            // Specify the direction that the camera is pointing.
            myPCamera.LookDirection = new Vector3D(0, 0, -1);

            // Define camera's horizontal field of view in degrees.
            myPCamera.FieldOfView = 60;

            // Asign the camera to the viewport
            myViewport3D.Camera = myPCamera;
            // Define the lights cast in the scene. Without light, the 3D object cannot 
            // be seen. Note: to illuminate an object from additional directions, create 
            // additional lights.
            DirectionalLight myDirectionalLight = new DirectionalLight();
            myDirectionalLight.Color = Colors.White;
            myDirectionalLight.Direction = new Vector3D(-0.61, -0.5, -0.61);

            myModel3DGroup.Children.Add(myDirectionalLight);

            // The geometry specifes the shape of the 3D plane. In this sample, a flat sheet 
            // is created.
            MeshGeometry3D myMeshGeometry3D = new MeshGeometry3D();

            // Create a collection of normal vectors for the MeshGeometry3D.
            Vector3DCollection myNormalCollection = new Vector3DCollection();
            myNormalCollection.Add(new Vector3D(0,0,1));
            myNormalCollection.Add(new Vector3D(0,0,1));
            myNormalCollection.Add(new Vector3D(0,0,1));
            myNormalCollection.Add(new Vector3D(0,0,1));
            myNormalCollection.Add(new Vector3D(0,0,1));
            myNormalCollection.Add(new Vector3D(0,0,1));
            myMeshGeometry3D.Normals = myNormalCollection;

            // Create a collection of vertex positions for the MeshGeometry3D. 
            Point3DCollection myPositionCollection = new Point3DCollection();
            myPositionCollection.Add(new Point3D(-0.5, -0.5, 0.5));
            myPositionCollection.Add(new Point3D(0.5, -0.5, 0.5));
            myPositionCollection.Add(new Point3D(0.5, 0.5, 0.5));
            myPositionCollection.Add(new Point3D(0.5, 0.5, 0.5));
            myPositionCollection.Add(new Point3D(-0.5, 0.5, 0.5));
            myPositionCollection.Add(new Point3D(-0.5, -0.5, 0.5));
            myMeshGeometry3D.Positions = myPositionCollection;

            // Create a collection of texture coordinates for the MeshGeometry3D.
            PointCollection myTextureCoordinatesCollection = new PointCollection();
            myTextureCoordinatesCollection.Add(new Point(0, 0));
            myTextureCoordinatesCollection.Add(new Point(1, 0));
            myTextureCoordinatesCollection.Add(new Point(1, 1));
            myTextureCoordinatesCollection.Add(new Point(1, 1));
            myTextureCoordinatesCollection.Add(new Point(0, 1));
            myTextureCoordinatesCollection.Add(new Point(0, 0));
            myMeshGeometry3D.TextureCoordinates = myTextureCoordinatesCollection;

            // Create a collection of triangle indices for the MeshGeometry3D.
            Int32Collection myTriangleIndicesCollection = new Int32Collection();
            myTriangleIndicesCollection.Add(0);
            myTriangleIndicesCollection.Add(1);
            myTriangleIndicesCollection.Add(2);
            myTriangleIndicesCollection.Add(3);
            myTriangleIndicesCollection.Add(4);
            myTriangleIndicesCollection.Add(5);
            myMeshGeometry3D.TriangleIndices = myTriangleIndicesCollection;

            // Apply the mesh to the geometry model.
            myGeometryModel.Geometry = myMeshGeometry3D;

            // The material specifies the material applied to the 3D object. In this sample a  
            // linear gradient covers the surface of the 3D object.

            // Create a horizontal linear gradient with four stops.   
            LinearGradientBrush myHorizontalGradient = new LinearGradientBrush();
            myHorizontalGradient.StartPoint = new Point(0, 0.5);
            myHorizontalGradient.EndPoint = new Point(1, 0.5);
            myHorizontalGradient.GradientStops.Add(new GradientStop(Colors.Yellow, 0.0));
            myHorizontalGradient.GradientStops.Add(new GradientStop(Colors.Red, 0.25));
            myHorizontalGradient.GradientStops.Add(new GradientStop(Colors.Blue, 0.75));
            myHorizontalGradient.GradientStops.Add(new GradientStop(Colors.LimeGreen, 1.0));

            // Define material and apply to the mesh geometries.
            DiffuseMaterial myMaterial = new DiffuseMaterial(myHorizontalGradient);
            myGeometryModel.Material = myMaterial;

            // Apply a transform to the object. In this sample, a rotation transform is applied,  
            // rendering the 3D object rotated.
            RotateTransform3D myRotateTransform3D = new RotateTransform3D();
            AxisAngleRotation3D myAxisAngleRotation3d = new AxisAngleRotation3D();
            myAxisAngleRotation3d.Axis = new Vector3D(0,3,0);
            myAxisAngleRotation3d.Angle = 40;
            myRotateTransform3D.Rotation = myAxisAngleRotation3d;
            myGeometryModel.Transform = myRotateTransform3D;

            // Add the geometry model to the model group.
            myModel3DGroup.Children.Add(myGeometryModel);

            // Add the group of models to the ModelVisual3d.
            myModelVisual3D.Content = myModel3DGroup;

            // 
            myViewport3D.Children.Add(myModelVisual3D);

            // Apply the viewport to the page so it will be rendered.
            this.Content = myViewport3D;
        }
    }
}
```

### [Apply a Drawing to a 3-D Model](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-apply-a-drawing-to-a-3-d-model)

此示例演示如何使用[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)作为[Material](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.material)应用于三维模型。

下面的代码定义[DrawingGroup](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawinggroup)的内容作为[DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)。 [DrawingBrush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.drawingbrush)设置为[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.diffusematerial.brush)的属性[DiffuseMaterial](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.diffusematerial)应用于三维平面。

**注意：** 通常是需要复杂的对象和值，如下面的绘图定义为资源可以重复使用并简化你的代码。 请参阅[XAML 资源](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-resources)有关详细信息。

XAML复制

```xaml
<!-- The material specifies the material applied to the 3D object. In this sample a tiled drawing   
     covers the surface of the 3D object.-->
<GeometryModel3D.Material>
  <DiffuseMaterial>
    <DiffuseMaterial.Brush>
      <DrawingBrush Viewport="0,0,0.1,0.1" TileMode="Tile">
        <DrawingBrush.Drawing>
          <DrawingGroup>
            <DrawingGroup.Children>
              <GeometryDrawing Geometry="M0,0.1 L0.1,0 1,0.9, 0.9,1z"
                Brush="Gray" />
              <GeometryDrawing Geometry="M0.9,0 L1,0.1 0.1,1 0,0.9z"
                Brush="Gray" />
              <GeometryDrawing Geometry="M0.25,0.25 L0.5,0.125 0.75,0.25 0.5,0.5z"
                Brush="#FFFF00" />
              <GeometryDrawing Geometry="M0.25,0.75 L0.5,0.875 0.75,0.75 0.5,0.5z"
                Brush="Black" />
              <GeometryDrawing Geometry="M0.25,0.75 L0.125,0.5 0.25,0.25 0.5,0.5z"
                Brush="#FF0000" />
              <GeometryDrawing Geometry="M0.75,0.25 L0.875,0.5 0.75,0.75 0.5,0.5z"
                Brush="MediumBlue" />
            </DrawingGroup.Children>
          </DrawingGroup>
        </DrawingBrush.Drawing>
      </DrawingBrush>
    </DiffuseMaterial.Brush>
  </DiffuseMaterial>
</GeometryModel3D.Material>
```

#### 示例

下面的代码演示了整个示例。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml" >
  <DockPanel>
    <Viewbox>
      <Canvas Width="321" Height="201">

        <!-- The Viewport3D provides a rendering surface for 3-D visual content. -->
        <Viewport3D ClipToBounds="True" Width="150" Height="150" Canvas.Left="0" Canvas.Top="10">

          <!-- Defines the camera used to view the 3D object. -->
          <Viewport3D.Camera>
            <PerspectiveCamera Position="0,0,2" LookDirection="0,0,-1" FieldOfView="60" />
          </Viewport3D.Camera>

          <!-- The ModelVisual3D children contain the 3D models -->
          <Viewport3D.Children>

            <!-- This ModelVisual3D defines the light cast in the scene. Without light, the 3D 
                 object cannot be seen. Also, the direction of the lights affect shadowing. If desired,
                 you can create multiple lights with different colors that shine from different directions. -->
            <ModelVisual3D>
              <ModelVisual3D.Content>
                <DirectionalLight Color="#FFFFFF" Direction="-0.612372,-0.5,-0.612372" />
              </ModelVisual3D.Content>
            </ModelVisual3D>
            <ModelVisual3D>
              <ModelVisual3D.Content>
                <GeometryModel3D>

                  <!-- The geometry specifies the shape of the 3D plane. In this sample, a flat sheet is created. -->
                  <GeometryModel3D.Geometry>
                    <MeshGeometry3D
                     TriangleIndices="0,1,2 3,4,5 "
                     Normals="0,0,1 0,0,1 0,0,1 0,0,1 0,0,1 0,0,1 "
                     TextureCoordinates="0,0 1,0 1,1 1,1 0,1 0,0 "
                     Positions="-0.5,-0.5,0.5 0.5,-0.5,0.5 0.5,0.5,0.5 0.5,0.5,0.5 -0.5,0.5,0.5 -0.5,-0.5,0.5 " />
                  </GeometryModel3D.Geometry>
                  <!-- The material specifies the material applied to the 3D object. In this sample a tiled drawing   
                       covers the surface of the 3D object.-->
                  <GeometryModel3D.Material>
                    <DiffuseMaterial>
                      <DiffuseMaterial.Brush>
                        <DrawingBrush Viewport="0,0,0.1,0.1" TileMode="Tile">
                          <DrawingBrush.Drawing>
                            <DrawingGroup>
                              <DrawingGroup.Children>
                                <GeometryDrawing Geometry="M0,0.1 L0.1,0 1,0.9, 0.9,1z"
                                  Brush="Gray" />
                                <GeometryDrawing Geometry="M0.9,0 L1,0.1 0.1,1 0,0.9z"
                                  Brush="Gray" />
                                <GeometryDrawing Geometry="M0.25,0.25 L0.5,0.125 0.75,0.25 0.5,0.5z"
                                  Brush="#FFFF00" />
                                <GeometryDrawing Geometry="M0.25,0.75 L0.5,0.875 0.75,0.75 0.5,0.5z"
                                  Brush="Black" />
                                <GeometryDrawing Geometry="M0.25,0.75 L0.125,0.5 0.25,0.25 0.5,0.5z"
                                  Brush="#FF0000" />
                                <GeometryDrawing Geometry="M0.75,0.25 L0.875,0.5 0.75,0.75 0.5,0.5z"
                                  Brush="MediumBlue" />
                              </DrawingGroup.Children>
                            </DrawingGroup>
                          </DrawingBrush.Drawing>
                        </DrawingBrush>
                      </DiffuseMaterial.Brush>
                    </DiffuseMaterial>
                  </GeometryModel3D.Material>
                  <!-- Apply a transform to the object. In this sample, a rotation transform is applied, rendering the 
                       3D object rotated. -->
                  <GeometryModel3D.Transform>
                    <RotateTransform3D>
                      <RotateTransform3D.Rotation>
                        <AxisAngleRotation3D Axis="0,3,0" Angle="40" />
                      </RotateTransform3D.Rotation>
                    </RotateTransform3D>
                  </GeometryModel3D.Transform>
                </GeometryModel3D>
              </ModelVisual3D.Content>
            </ModelVisual3D>
          </Viewport3D.Children>
        </Viewport3D>
      </Canvas>
    </Viewbox>
  </DockPanel>
</Page>
```

### [Apply Material to the Front and Back of a 3-D Object](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-apply-material-to-the-front-and-back-of-a-3-d-object)

下面的示例演示如何应用[Material](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.material)到前面和背面三维对象，并对要显示对象的两侧的对象进行动画处理。 [Material](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.geometrymodel3d.material)的属性[GeometryModel3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.geometrymodel3d)用于将应用一个红色[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)到对象的正面和[BackMaterial](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.geometrymodel3d.backmaterial)属性[GeometryModel3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.geometrymodel3d)用于将应用一个蓝色[Brush](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.brush)到后端的对象。 下面的代码显示了应用到该对象的材料：

```xaml
<!-- This material is applied to the front of the 3D object (red side).-->
<GeometryModel3D.Material>
  <MaterialGroup>
    <DiffuseMaterial>
      <DiffuseMaterial.Brush>
        <SolidColorBrush Color="Red"/>
      </DiffuseMaterial.Brush>
    </DiffuseMaterial>
  </MaterialGroup>
</GeometryModel3D.Material>

<!-- This material is applied to the back of the 3D object (blue side).-->
<GeometryModel3D.BackMaterial>
  <MaterialGroup>
    <DiffuseMaterial>
      <DiffuseMaterial.Brush>
        <SolidColorBrush Color="Blue"/>
      </DiffuseMaterial.Brush>
    </DiffuseMaterial>
  </MaterialGroup>
</GeometryModel3D.BackMaterial>
```

#### 示例

下面的代码演示了整个示例。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml" >
  <DockPanel>
    <Viewbox>
      <Canvas Width="321" Height="201">

        <!-- The Viewport3D provides a rendering surface for 3-D visual content. -->
        <Viewport3D Name="MyAnimatedObject"
          ClipToBounds="True" Width="150" Height="150"
          Canvas.Left="0" Canvas.Top="10">

          <!-- Defines the camera used to view the 3D object. -->
          <Viewport3D.Camera>
            <PerspectiveCamera x:Name="myPerspectiveCamera" Position="0,0,2" LookDirection="0,0,-1" 
             FieldOfView="60" />
          </Viewport3D.Camera>

          <!-- The ModelVisual3D children contain the 3D models -->
          <Viewport3D.Children>

            <!-- Two ModelVisual3D define the lights cast in the scene. Without light, the
                 3D object cannot be seen. Also, the direction of the lights affect shadowing. -->
            <ModelVisual3D>
              <ModelVisual3D.Content>
                <DirectionalLight Color="#FFFFFF" Direction="-0.612372,-0.5,-0.612372" />
              </ModelVisual3D.Content>
            </ModelVisual3D>
            <ModelVisual3D>
              <ModelVisual3D.Content>
                <DirectionalLight Color="#FFFFFF" Direction="0.612372,-0.5,-0.612372" />
              </ModelVisual3D.Content>
            </ModelVisual3D>
            <ModelVisual3D>
              <ModelVisual3D.Content>
                <GeometryModel3D>

                  <!-- The geometry specifes the shape of the 3D plane. In this case, a flat sheet is created. -->
                  <GeometryModel3D.Geometry>
                    <MeshGeometry3D
                     TriangleIndices="0,1,2 3,4,5 "
                     Normals="0,0,1 0,0,1 0,0,1 0,0,1 0,0,1 0,0,1 "
                     TextureCoordinates="0,0 1,0 1,1 1,1 0,1 0,0 "
                     Positions="-0.5,-0.5,0.5 0.5,-0.5,0.5 0.5,0.5,0.5 0.5,0.5,0.5 -0.5,0.5,0.5 -0.5,-0.5,0.5 " />
                  </GeometryModel3D.Geometry>
                  <!-- This material is applied to the front of the 3D object (red side).-->
                  <GeometryModel3D.Material>
                    <MaterialGroup>
                      <DiffuseMaterial>
                        <DiffuseMaterial.Brush>
                          <SolidColorBrush Color="Red"/>
                        </DiffuseMaterial.Brush>
                      </DiffuseMaterial>
                    </MaterialGroup>
                  </GeometryModel3D.Material>

                  <!-- This material is applied to the back of the 3D object (blue side).-->
                  <GeometryModel3D.BackMaterial>
                    <MaterialGroup>
                      <DiffuseMaterial>
                        <DiffuseMaterial.Brush>
                          <SolidColorBrush Color="Blue"/>
                        </DiffuseMaterial.Brush>
                      </DiffuseMaterial>
                    </MaterialGroup>
                  </GeometryModel3D.BackMaterial>
                  <!-- The Transform specifies how to transform the 3D object. The properties of the
                        Rotation object are animated causing the 3D object to rotate (see Storyboard below).-->
                  <GeometryModel3D.Transform>
                    <RotateTransform3D>
                      <RotateTransform3D.Rotation>
                        <AxisAngleRotation3D x:Name="myAngleRotation" Axis="0,3,0" Angle="40" />
                      </RotateTransform3D.Rotation>
                    </RotateTransform3D>
                  </GeometryModel3D.Transform>
                </GeometryModel3D>
              </ModelVisual3D.Content>
            </ModelVisual3D>
          </Viewport3D.Children>

          <!-- Trigger the rotation animation when the 3D object loads. This animation is used to show
               both sides of the 3D object. -->
          <Viewport3D.Triggers>
            <EventTrigger RoutedEvent="Viewport3D.Loaded">
              <BeginStoryboard>
                <Storyboard>

                  <!-- This animation animates the Angle property of the AxisAngleRotation3D
                       making the 3D object rotate from -0 degrees to 360 degrees. -->
                  <DoubleAnimation 
                   Storyboard.TargetName="myAngleRotation" 
                   Storyboard.TargetProperty="Angle" 
                   From="0" To="360" Duration="0:0:4" AutoReverse="True"  RepeatBehavior="Forever"/>

                </Storyboard>
              </BeginStoryboard>
            </EventTrigger>
          </Viewport3D.Triggers>
        </Viewport3D>
      </Canvas>
    </Viewbox>
  </DockPanel>
</Page>
```

### [Apply Emissive Material to a 3-D Object](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-apply-emissive-material-to-a-3-d-object)

下面的示例演示如何使用[EmissiveMaterial](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.emissivematerial)将颜色添加到现有材料等于 EmissiveMaterial 的画笔的颜色。 下面的代码显示[DiffuseMaterial](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.diffusematerial)和[EmissiveMaterial](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.emissivematerial)应用中进行组合，以将蓝色添加到 DiffuseMaterial 的外观。

```xaml
<!-- The material applied to the 3D object is made up of a DiffuseMaterial (gradient brush) with 
     an EmissiveMaterial layered on top (blue SolidColorBrush). The EmissiveMaterial adds blue to the gradient. -->
<GeometryModel3D.Material>
  <MaterialGroup>
    <DiffuseMaterial>
      <DiffuseMaterial.Brush>
        <LinearGradientBrush StartPoint="0,0.5" EndPoint="1,0.5">
          <LinearGradientBrush.GradientStops>
            <GradientStop Color="Yellow" Offset="0" />
            <GradientStop Color="Red" Offset="0.25" />
            <GradientStop Color="Blue" Offset="0.75" />
            <GradientStop Color="LimeGreen" Offset="1" />
          </LinearGradientBrush.GradientStops>
        </LinearGradientBrush>
      </DiffuseMaterial.Brush>
    </DiffuseMaterial>
    <EmissiveMaterial>
      <EmissiveMaterial.Brush>
        <SolidColorBrush x:Name="mySolidColorBrush" Color="Blue" />
      </EmissiveMaterial.Brush>
    </EmissiveMaterial>
  </MaterialGroup>
</GeometryModel3D.Material>
```

在程序代码中：

```csharp
// The material property of GeometryModel3D specifies the material applied to the 3D object.  
// In this sample the material applied to the 3D object is made up of two materials layered  
// on top of each other - a DiffuseMaterial (gradient brush) with an EmissiveMaterial 
// layered on top (blue SolidColorBrush). The EmmisiveMaterial alters the appearance of  
// the gradient toward blue.

// Create a horizontal linear gradient with four stops.   
LinearGradientBrush myHorizontalGradient = new LinearGradientBrush();
myHorizontalGradient.StartPoint = new Point(0, 0.5);
myHorizontalGradient.EndPoint = new Point(1, 0.5);
myHorizontalGradient.GradientStops.Add(new GradientStop(Colors.Yellow, 0.0));
myHorizontalGradient.GradientStops.Add(new GradientStop(Colors.Red, 0.25));
myHorizontalGradient.GradientStops.Add(new GradientStop(Colors.Blue, 0.75));
myHorizontalGradient.GradientStops.Add(new GradientStop(Colors.LimeGreen, 1.0));

// Define material that will use the gradient.
DiffuseMaterial myDiffuseMaterial = new DiffuseMaterial(myHorizontalGradient);

// Add this gradient to a MaterialGroup.
MaterialGroup myMaterialGroup = new MaterialGroup();
myMaterialGroup.Children.Add(myDiffuseMaterial);

// Define an Emissive Material with a blue brush.
Color c = new Color();
c.ScA = 1;
c.ScB = 255;
c.ScR = 0;
c.ScG = 0;
EmissiveMaterial myEmissiveMaterial = new EmissiveMaterial(new SolidColorBrush(c));

// Add the Emmisive Material to the Material Group.
myMaterialGroup.Children.Add(myEmissiveMaterial);

// Add the composite material to the 3D model.
myGeometryModel.Material = myMaterialGroup;
```

#### 示例

下面的代码演示在 XAML 中的整个示例。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml" >
  <DockPanel>
    <Viewbox>
      <Canvas Width="321" Height="201">

        <!-- The Viewport3D provides a rendering surface for 3-D visual content. -->
        <Viewport3D ClipToBounds="True" Width="150" Height="150"
          Canvas.Left="0" Canvas.Top="10">

          <!-- Defines the camera used to view the 3D object. -->
          <Viewport3D.Camera>
            <PerspectiveCamera x:Name="myPerspectiveCamera" Position="0,0,2" LookDirection="0,0,-1" 
             FieldOfView="60" />
          </Viewport3D.Camera>

          <!-- The ModelVisual3D children contain the 3D models -->
          <Viewport3D.Children>

            <!-- This ModelVisual3D defines the lights cast in the scene. Without light, the
                 3D object cannot be seen. -->
            <ModelVisual3D>
              <ModelVisual3D.Content>
                <DirectionalLight Color="#FFFFFF" Direction="-0.612372,-0.5,-0.612372" />
              </ModelVisual3D.Content>
            </ModelVisual3D>
            <ModelVisual3D>
              <ModelVisual3D.Content>
                <GeometryModel3D>

                  <!-- The geometry specifies the shape of the 3D plane. In this case, a flat sheet is created. -->
                  <GeometryModel3D.Geometry>
                    <MeshGeometry3D
                     TriangleIndices="0,1,2 3,4,5 "
                     Normals="0,0,1 0,0,1 0,0,1 0,0,1 0,0,1 0,0,1 "
                     TextureCoordinates="0,0 1,0 1,1 1,1 0,1 0,0 "
                     Positions="-0.5,-0.5,0.5 0.5,-0.5,0.5 0.5,0.5,0.5 0.5,0.5,0.5 -0.5,0.5,0.5 -0.5,-0.5,0.5 " />
                  </GeometryModel3D.Geometry>
                  <!-- The material applied to the 3D object is made up of a DiffuseMaterial (gradient brush) with 
                       an EmissiveMaterial layered on top (blue SolidColorBrush). The EmissiveMaterial adds blue to the gradient. -->
                  <GeometryModel3D.Material>
                    <MaterialGroup>
                      <DiffuseMaterial>
                        <DiffuseMaterial.Brush>
                          <LinearGradientBrush StartPoint="0,0.5" EndPoint="1,0.5">
                            <LinearGradientBrush.GradientStops>
                              <GradientStop Color="Yellow" Offset="0" />
                              <GradientStop Color="Red" Offset="0.25" />
                              <GradientStop Color="Blue" Offset="0.75" />
                              <GradientStop Color="LimeGreen" Offset="1" />
                            </LinearGradientBrush.GradientStops>
                          </LinearGradientBrush>
                        </DiffuseMaterial.Brush>
                      </DiffuseMaterial>
                      <EmissiveMaterial>
                        <EmissiveMaterial.Brush>
                          <SolidColorBrush x:Name="mySolidColorBrush" Color="Blue" />
                        </EmissiveMaterial.Brush>
                      </EmissiveMaterial>
                    </MaterialGroup>
                  </GeometryModel3D.Material>
                  <!-- The Transform specifies how to transform the 3D object. This transform 
                       rotates the object.-->
                  <GeometryModel3D.Transform>
                    <RotateTransform3D>
                      <RotateTransform3D.Rotation>
                        <AxisAngleRotation3D x:Name="myAngleRotation" Axis="0,3,0" Angle="40" />
                      </RotateTransform3D.Rotation>
                    </RotateTransform3D>
                  </GeometryModel3D.Transform>
                </GeometryModel3D>
              </ModelVisual3D.Content>
            </ModelVisual3D>
          </Viewport3D.Children>
        </Viewport3D>
      </Canvas>
    </Viewbox>
  </DockPanel>
</Page>
```

#### 示例

下面是在程序代码中的整个示例。

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Media3D;

namespace SDKSample
{
    public partial class EmissiveMaterialExample : Page
    {
        public EmissiveMaterialExample()
        {

            // Declare scene objects.
            Viewport3D myViewport3D = new Viewport3D();
            Model3DGroup myModel3DGroup = new Model3DGroup();
            GeometryModel3D myGeometryModel = new GeometryModel3D();
            ModelVisual3D myModelVisual3D = new ModelVisual3D();

            // Defines the camera used to view the 3D object. In order to view the 3D object,
            // the camera must be positioned and pointed such that the object is within view 
            // of the camera.
            PerspectiveCamera myPCamera = new PerspectiveCamera();

            // Specify where in the 3D scene the camera is.
            myPCamera.Position = new Point3D(0, 0, 2);

            // Specify the direction that the camera is pointing.
            myPCamera.LookDirection = new Vector3D(0, 0, -1);

            // Define camera's horizontal field of view in degrees.
            myPCamera.FieldOfView = 60;

            // Asign the camera to the viewport
            myViewport3D.Camera = myPCamera;

            // Define the lights cast in the scene. Without light, the 3D object cannot 
            // be seen. Note: to illuminate an object from additional directions, create 
            // additional lights.
            DirectionalLight myDirectionalLight = new DirectionalLight();
            myDirectionalLight.Color = Colors.White;
            myDirectionalLight.Direction = new Vector3D(-0.61, -0.5, -0.61);

            myModel3DGroup.Children.Add(myDirectionalLight);

            // The geometry specifes the shape of the 3D plane. In this sample, a flat sheet 
            // is created.
            MeshGeometry3D myMeshGeometry3D = new MeshGeometry3D();

            // Create a collection of normal vectors for the MeshGeometry3D.
            Vector3DCollection myNormalCollection = new Vector3DCollection();
            myNormalCollection.Add(new Vector3D(0,0,1));
            myNormalCollection.Add(new Vector3D(0,0,1));
            myNormalCollection.Add(new Vector3D(0,0,1));
            myNormalCollection.Add(new Vector3D(0,0,1));
            myNormalCollection.Add(new Vector3D(0,0,1));
            myNormalCollection.Add(new Vector3D(0,0,1));
            myMeshGeometry3D.Normals = myNormalCollection;

            // Create a collection of vertex positions for the MeshGeometry3D. 
            Point3DCollection myPositionCollection = new Point3DCollection();
            myPositionCollection.Add(new Point3D(-0.5, -0.5, 0.5));
            myPositionCollection.Add(new Point3D(0.5, -0.5, 0.5));
            myPositionCollection.Add(new Point3D(0.5, 0.5, 0.5));
            myPositionCollection.Add(new Point3D(0.5, 0.5, 0.5));
            myPositionCollection.Add(new Point3D(-0.5, 0.5, 0.5));
            myPositionCollection.Add(new Point3D(-0.5, -0.5, 0.5));
            myMeshGeometry3D.Positions = myPositionCollection;

            // Create a collection of texture coordinates for the MeshGeometry3D.
            PointCollection myTextureCoordinatesCollection = new PointCollection();
            myTextureCoordinatesCollection.Add(new Point(0, 0));
            myTextureCoordinatesCollection.Add(new Point(1, 0));
            myTextureCoordinatesCollection.Add(new Point(1, 1));
            myTextureCoordinatesCollection.Add(new Point(1, 1));
            myTextureCoordinatesCollection.Add(new Point(0, 1));
            myTextureCoordinatesCollection.Add(new Point(0, 0));
            myMeshGeometry3D.TextureCoordinates = myTextureCoordinatesCollection;

            // Create a collection of triangle indices for the MeshGeometry3D.
            Int32Collection myTriangleIndicesCollection = new Int32Collection();
            myTriangleIndicesCollection.Add(0);
            myTriangleIndicesCollection.Add(1);
            myTriangleIndicesCollection.Add(2);
            myTriangleIndicesCollection.Add(3);
            myTriangleIndicesCollection.Add(4);
            myTriangleIndicesCollection.Add(5);
            myMeshGeometry3D.TriangleIndices = myTriangleIndicesCollection;

            // Apply the mesh to the geometry model.
            myGeometryModel.Geometry = myMeshGeometry3D;
            // The material property of GeometryModel3D specifies the material applied to the 3D object.  
            // In this sample the material applied to the 3D object is made up of two materials layered  
            // on top of each other - a DiffuseMaterial (gradient brush) with an EmissiveMaterial 
            // layered on top (blue SolidColorBrush). The EmmisiveMaterial alters the appearance of  
            // the gradient toward blue.

            // Create a horizontal linear gradient with four stops.   
            LinearGradientBrush myHorizontalGradient = new LinearGradientBrush();
            myHorizontalGradient.StartPoint = new Point(0, 0.5);
            myHorizontalGradient.EndPoint = new Point(1, 0.5);
            myHorizontalGradient.GradientStops.Add(new GradientStop(Colors.Yellow, 0.0));
            myHorizontalGradient.GradientStops.Add(new GradientStop(Colors.Red, 0.25));
            myHorizontalGradient.GradientStops.Add(new GradientStop(Colors.Blue, 0.75));
            myHorizontalGradient.GradientStops.Add(new GradientStop(Colors.LimeGreen, 1.0));

            // Define material that will use the gradient.
            DiffuseMaterial myDiffuseMaterial = new DiffuseMaterial(myHorizontalGradient);

            // Add this gradient to a MaterialGroup.
            MaterialGroup myMaterialGroup = new MaterialGroup();
            myMaterialGroup.Children.Add(myDiffuseMaterial);

            // Define an Emissive Material with a blue brush.
            Color c = new Color();
            c.ScA = 1;
            c.ScB = 255;
            c.ScR = 0;
            c.ScG = 0;
            EmissiveMaterial myEmissiveMaterial = new EmissiveMaterial(new SolidColorBrush(c));

            // Add the Emmisive Material to the Material Group.
            myMaterialGroup.Children.Add(myEmissiveMaterial);

            // Add the composite material to the 3D model.
            myGeometryModel.Material = myMaterialGroup;
            // Apply a transform to the object. In this sample, a rotation transform is applied,  
            // rendering the 3D object rotated.
            RotateTransform3D myRotateTransform3D = new RotateTransform3D();
            AxisAngleRotation3D myAxisAngleRotation3d = new AxisAngleRotation3D();
            myAxisAngleRotation3d.Axis = new Vector3D(0,3,0);
            myAxisAngleRotation3d.Angle = 40;
            myRotateTransform3D.Rotation = myAxisAngleRotation3d;
            myGeometryModel.Transform = myRotateTransform3D;

            // Add the geometry model to the model group.
            myModel3DGroup.Children.Add(myGeometryModel);

            // Add the group of models to the ModelVisual3d.
            myModelVisual3D.Content = myModel3DGroup; 
            myViewport3D.Children.Add(myModelVisual3D);

            // Apply the viewport to the page so it will be rendered.
            this.Content = myViewport3D;
        }
    }
}
```

### [Transform the Scale of a 3-D Model](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-transform-the-scale-of-a-3-d-model)

此示例演示如何缩放三维对象。 若要缩放三维对象，使用[ScaleTransform3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.scaletransform3d)。 [ScaleX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.scaletransform3d.scalex)， [ScaleY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.scaletransform3d.scaley)，和[ScaleZ](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.scaletransform3d.scalez)属性调整元素大小由指定的系数。 例如，[ScaleX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.scaletransform3d.scalex)值为 1.5 会拉伸到其原始宽度的 150%的对象。 一个[ScaleY](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.scaletransform3d.scaley)值为 0.5 会对象的高度缩小 50%。 下面的代码显示使用[ScaleTransform3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.scaletransform3d)的转换为[GeometryModel3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.geometrymodel3d)。

```xaml
<!-- Apply a scale transform to the object. You can transform the scale of the object
     for the X, Y, or Z axis. The ScaleX, ScaleY, and ScaleZ properties resize the object 
     by the factor you specify. For example, a ScaleX value of 1.5 stretches the object to 
     150 percent of its original width. A ScaleY value of 0.5 shrinks the height of an object 
     by 50 percent. -->
<GeometryModel3D.Transform>

  <!-- This Scale Transform stretches the object horizontally by 200 percent and shrinks it 
       vertically by 50 percent. -->
  <ScaleTransform3D ScaleX="2" ScaleY="0.5" ScaleZ="1" CenterX="0" CenterY="0" CenterZ="0" />
</GeometryModel3D.Transform>
```

#### 示例

下面的代码演示了整个示例。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml" >
  <DockPanel>
    <Viewbox>
      <Canvas Width="321" Height="201">

        <!-- The Viewport3D provides a rendering surface for 3-D visual content. -->
        <Viewport3D ClipToBounds="True" Width="150" Height="150" Canvas.Left="0" Canvas.Top="10">

          <!-- Defines the camera used to view the 3D object. -->
          <Viewport3D.Camera>
            <PerspectiveCamera Position="0,0,2" LookDirection="0,0,-1" FieldOfView="60" />
          </Viewport3D.Camera>

          <!-- The ModelVisual3D children contain the 3D models -->
          <Viewport3D.Children>

            <!-- This ModelVisual3D defines the light cast in the scene. Without light, the 3D 
                 object cannot be seen. Also, the direction of the lights affect shadowing. If desired,
                 you can create multiple lights with different colors that shine from different directions. -->
            <ModelVisual3D>
              <ModelVisual3D.Content>
                <DirectionalLight Color="#FFFFFF" Direction="-0.612372,-0.5,-0.612372" />
              </ModelVisual3D.Content>
            </ModelVisual3D>
            <ModelVisual3D>
              <ModelVisual3D.Content>
                <GeometryModel3D>

                  <!-- The geometry specifies the shape of the 3D plane. In this sample, a flat sheet is created. -->
                  <GeometryModel3D.Geometry>
                    <MeshGeometry3D
                     TriangleIndices="0,1,2 3,4,5 "
                     Normals="0,0,1 0,0,1 0,0,1 0,0,1 0,0,1 0,0,1 "
                     TextureCoordinates="0,0 1,0 1,1 1,1 0,1 0,0 "
                     Positions="-0.5,-0.5,0.5 0.5,-0.5,0.5 0.5,0.5,0.5 0.5,0.5,0.5 -0.5,0.5,0.5 -0.5,-0.5,0.5 " />
                  </GeometryModel3D.Geometry>

                  <!-- The material specifies the material applied to the 3D object. In this sample a linear gradient 
                       covers the surface of the 3D object.-->
                  <GeometryModel3D.Material>
                    <MaterialGroup>
                      <DiffuseMaterial>
                        <DiffuseMaterial.Brush>
                          <LinearGradientBrush StartPoint="0,0.5" EndPoint="1,0.5">
                            <LinearGradientBrush.GradientStops>
                              <GradientStop Color="Yellow" Offset="0" />
                              <GradientStop Color="Red" Offset="0.25" />
                              <GradientStop Color="Blue" Offset="0.75" />
                              <GradientStop Color="LimeGreen" Offset="1" />
                            </LinearGradientBrush.GradientStops>
                          </LinearGradientBrush>
                        </DiffuseMaterial.Brush>
                      </DiffuseMaterial>
                    </MaterialGroup>
                  </GeometryModel3D.Material>
                  <!-- Apply a scale transform to the object. You can transform the scale of the object
                       for the X, Y, or Z axis. The ScaleX, ScaleY, and ScaleZ properties resize the object 
                       by the factor you specify. For example, a ScaleX value of 1.5 stretches the object to 
                       150 percent of its original width. A ScaleY value of 0.5 shrinks the height of an object 
                       by 50 percent. -->
                  <GeometryModel3D.Transform>

                    <!-- This Scale Transform stretches the object horizontally by 200 percent and shrinks it 
                         vertically by 50 percent. -->
                    <ScaleTransform3D ScaleX="2" ScaleY="0.5" ScaleZ="1" CenterX="0" CenterY="0" CenterZ="0" />
                  </GeometryModel3D.Transform>
                </GeometryModel3D>
              </ModelVisual3D.Content>
            </ModelVisual3D>
          </Viewport3D.Children>

        </Viewport3D>
      </Canvas>
    </Viewbox>
  </DockPanel>
</Page>
```

### [Apply Multiple Transformations to a 3-D Model](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-apply-multiple-transformations-to-a-3-d-model)

此示例演示如何使用[RotateTransform3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.rotatetransform3d)和一个[ScaleTransform3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.scaletransform3d)旋转并更改其小数位数的三维模型。 下面的代码演示如何将应用到这些转换[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.model3d.transform)属性的[GeometryModel3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.geometrymodel3d)在 XAML 中。

```xaml
<!-- Apply multiple transformations to the object. In this sample, a rotation and scale transform 
is applied. -->
<GeometryModel3D.Transform>
  <Transform3DGroup>
    <Transform3DGroup.Children>
      <RotateTransform3D>
        <RotateTransform3D.Rotation>

        <!-- This transformation rotates the object. -->
        <AxisAngleRotation3D Axis="0,3,0" Angle="40" />
        </RotateTransform3D.Rotation>
      </RotateTransform3D>
      
      <!-- This Scale Transform stretches the object horizontally by 200 percent and shrinks it 
         vertically by 50 percent. -->
      <ScaleTransform3D ScaleX="2" ScaleY="0.5" ScaleZ="1" CenterX="0" CenterY="0" CenterZ="0" />
    </Transform3DGroup.Children>
 </Transform3DGroup>
</GeometryModel3D.Transform>
```

在代码中：

```csharp
// Apply multiple transformations to the object. In this sample, a rotation and scale 
// transform is applied.

// Create and apply a transformation that rotates the object.
RotateTransform3D myRotateTransform3D = new RotateTransform3D();
AxisAngleRotation3D myAxisAngleRotation3d = new AxisAngleRotation3D();
myAxisAngleRotation3d.Axis = new Vector3D(0,3,0);
myAxisAngleRotation3d.Angle = 40;
myRotateTransform3D.Rotation = myAxisAngleRotation3d;

// Add the rotation transform to a Transform3DGroup
Transform3DGroup myTransform3DGroup = new Transform3DGroup();
myTransform3DGroup.Children.Add(myRotateTransform3D);

// Create and apply a scale transformation that stretches the object along the local x-axis  
// by 200 percent and shrinks it along the local y-axis by 50 percent.
ScaleTransform3D myScaleTransform3D = new ScaleTransform3D();
myScaleTransform3D.ScaleX = 2;
myScaleTransform3D.ScaleY = 0.5;
myScaleTransform3D.ScaleZ = 1;

// Add the scale transform to the Transform3DGroup.
myTransform3DGroup.Children.Add(myScaleTransform3D);

// Set the Transform property of the GeometryModel to the Transform3DGroup which includes 
// both transformations. The 3D object now has two Transformations applied to it.
myGeometryModel.Transform = myTransform3DGroup;
```

#### 示例

下面的代码演示在 XAML 中的整个示例。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml" >
  <DockPanel>
    <Viewbox>
      <Canvas Width="321" Height="201">

        <!-- The Viewport3D provides a rendering surface for 3-D visual content. -->
        <Viewport3D ClipToBounds="True" Width="150" Height="150" Canvas.Left="0" Canvas.Top="10">

          <!-- Defines the camera used to view the 3D object. -->
          <Viewport3D.Camera>
            <PerspectiveCamera Position="0,0,2" LookDirection="0,0,-1" FieldOfView="60" />
          </Viewport3D.Camera>

          <!-- The ModelVisual3D children contain the 3D models -->
          <Viewport3D.Children>

            <!-- This ModelVisual3D defines the light cast in the scene. Without light, the 3D 
                 object cannot be seen. Also, the direction of the lights affect shadowing. If desired,
                 you can create multiple lights with different colors that shine from different directions. -->
            <ModelVisual3D>
              <ModelVisual3D.Content>
                <DirectionalLight Color="#FFFFFF" Direction="-0.612372,-0.5,-0.612372" />
              </ModelVisual3D.Content>
            </ModelVisual3D>
            <ModelVisual3D>
              <ModelVisual3D.Content>
                <GeometryModel3D>

                  <!-- The geometry specifies the shape of the 3D plane. In this sample, a flat sheet is created. -->
                  <GeometryModel3D.Geometry>
                    <MeshGeometry3D
                     TriangleIndices="0,1,2 3,4,5 "
                     Normals="0,0,1 0,0,1 0,0,1 0,0,1 0,0,1 0,0,1 "
                     TextureCoordinates="0,0 1,0 1,1 1,1 0,1 0,0 "
                     Positions="-0.5,-0.5,0.5 0.5,-0.5,0.5 0.5,0.5,0.5 0.5,0.5,0.5 -0.5,0.5,0.5 -0.5,-0.5,0.5 " />
                  </GeometryModel3D.Geometry>

                  <!-- The material specifies the material applied to the 3D object. In this sample a linear gradient 
                       covers the surface of the 3D object.-->
                  <GeometryModel3D.Material>
                    <MaterialGroup>
                      <DiffuseMaterial>
                        <DiffuseMaterial.Brush>
                          <LinearGradientBrush StartPoint="0,0.5" EndPoint="1,0.5">
                            <LinearGradientBrush.GradientStops>
                              <GradientStop Color="Yellow" Offset="0" />
                              <GradientStop Color="Red" Offset="0.25" />
                              <GradientStop Color="Blue" Offset="0.75" />
                              <GradientStop Color="LimeGreen" Offset="1" />
                            </LinearGradientBrush.GradientStops>
                          </LinearGradientBrush>
                        </DiffuseMaterial.Brush>
                      </DiffuseMaterial>
                    </MaterialGroup>
                  </GeometryModel3D.Material>
                  <!-- Apply multiple transformations to the object. In this sample, a rotation and scale transform 
                  is applied. -->
                  <GeometryModel3D.Transform>
                    <Transform3DGroup>
                      <Transform3DGroup.Children>
                        <RotateTransform3D>
                          <RotateTransform3D.Rotation>

                          <!-- This transformation rotates the object. -->
                          <AxisAngleRotation3D Axis="0,3,0" Angle="40" />
                          </RotateTransform3D.Rotation>
                        </RotateTransform3D>
                        
                        <!-- This Scale Transform stretches the object horizontally by 200 percent and shrinks it 
                           vertically by 50 percent. -->
                        <ScaleTransform3D ScaleX="2" ScaleY="0.5" ScaleZ="1" CenterX="0" CenterY="0" CenterZ="0" />
                      </Transform3DGroup.Children>
                   </Transform3DGroup>
                  </GeometryModel3D.Transform>
                </GeometryModel3D>
              </ModelVisual3D.Content>
            </ModelVisual3D>
          </Viewport3D.Children>

        </Viewport3D>
      </Canvas>
    </Viewbox>
  </DockPanel>
</Page>
```

#### 示例

下面是在代码中的完整示例。

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Media3D;

namespace SDKSample
{
    public partial class MultipleTransformationsExample : Page
    {
        public MultipleTransformationsExample()
        {

            // Declare scene objects.
            Viewport3D myViewport3D = new Viewport3D();
            Model3DGroup myModel3DGroup = new Model3DGroup();
            GeometryModel3D myGeometryModel = new GeometryModel3D();
            ModelVisual3D myModelVisual3D = new ModelVisual3D();
            
            // Defines the camera used to view the 3D object. In order to view the 3D object,
            // the camera must be positioned and pointed such that the object is within view 
            // of the camera.
            PerspectiveCamera myPCamera = new PerspectiveCamera();

            // Specify where in the 3D scene the camera is.
            myPCamera.Position = new Point3D(0, 0, 2);

            // Specify the direction that the camera is pointing.
            myPCamera.LookDirection = new Vector3D(0, 0, -1);

            // Define camera's horizontal field of view in degrees.
            myPCamera.FieldOfView = 60;

            // Asign the camera to the viewport
            myViewport3D.Camera = myPCamera;
            
            // Define the lights cast in the scene. Without light, the 3D object cannot 
            // be seen. Note: to illuminate an object from additional directions, create 
            // additional lights.
            DirectionalLight myDirectionalLight = new DirectionalLight();
            myDirectionalLight.Color = Colors.White;
            myDirectionalLight.Direction = new Vector3D(-0.61, -0.5, -0.61);

            myModel3DGroup.Children.Add(myDirectionalLight);

            // The geometry specifes the shape of the 3D plane. In this sample, a flat sheet 
            // is created.
            MeshGeometry3D myMeshGeometry3D = new MeshGeometry3D();

            // Create a collection of normal vectors for the MeshGeometry3D.
            Vector3DCollection myNormalCollection = new Vector3DCollection();
            myNormalCollection.Add(new Vector3D(0,0,1));
            myNormalCollection.Add(new Vector3D(0,0,1));
            myNormalCollection.Add(new Vector3D(0,0,1));
            myNormalCollection.Add(new Vector3D(0,0,1));
            myNormalCollection.Add(new Vector3D(0,0,1));
            myNormalCollection.Add(new Vector3D(0,0,1));
            myMeshGeometry3D.Normals = myNormalCollection;

            // Create a collection of vertex positions for the MeshGeometry3D. 
            Point3DCollection myPositionCollection = new Point3DCollection();
            myPositionCollection.Add(new Point3D(-0.5, -0.5, 0.5));
            myPositionCollection.Add(new Point3D(0.5, -0.5, 0.5));
            myPositionCollection.Add(new Point3D(0.5, 0.5, 0.5));
            myPositionCollection.Add(new Point3D(0.5, 0.5, 0.5));
            myPositionCollection.Add(new Point3D(-0.5, 0.5, 0.5));
            myPositionCollection.Add(new Point3D(-0.5, -0.5, 0.5));
            myMeshGeometry3D.Positions = myPositionCollection;

            // Create a collection of texture coordinates for the MeshGeometry3D.
            PointCollection myTextureCoordinatesCollection = new PointCollection();
            myTextureCoordinatesCollection.Add(new Point(0, 0));
            myTextureCoordinatesCollection.Add(new Point(1, 0));
            myTextureCoordinatesCollection.Add(new Point(1, 1));
            myTextureCoordinatesCollection.Add(new Point(1, 1));
            myTextureCoordinatesCollection.Add(new Point(0, 1));
            myTextureCoordinatesCollection.Add(new Point(0, 0));
            myMeshGeometry3D.TextureCoordinates = myTextureCoordinatesCollection;

            // Create a collection of triangle indices for the MeshGeometry3D.
            Int32Collection myTriangleIndicesCollection = new Int32Collection();
            myTriangleIndicesCollection.Add(0);
            myTriangleIndicesCollection.Add(1);
            myTriangleIndicesCollection.Add(2);
            myTriangleIndicesCollection.Add(3);
            myTriangleIndicesCollection.Add(4);
            myTriangleIndicesCollection.Add(5);
            myMeshGeometry3D.TriangleIndices = myTriangleIndicesCollection;

            // Apply the mesh to the geometry model.
            myGeometryModel.Geometry = myMeshGeometry3D;

            // The material specifies the material applied to the 3D object. In this sample a  
            // linear gradient covers the surface of the 3D object.

            // Create a horizontal linear gradient with four stops.   
            LinearGradientBrush myHorizontalGradient = new LinearGradientBrush();
            myHorizontalGradient.StartPoint = new Point(0, 0.5);
            myHorizontalGradient.EndPoint = new Point(1, 0.5);
            myHorizontalGradient.GradientStops.Add(new GradientStop(Colors.Yellow, 0.0));
            myHorizontalGradient.GradientStops.Add(new GradientStop(Colors.Red, 0.25));
            myHorizontalGradient.GradientStops.Add(new GradientStop(Colors.Blue, 0.75));
            myHorizontalGradient.GradientStops.Add(new GradientStop(Colors.LimeGreen, 1.0));

            // Define material and apply to the mesh geometries.
            DiffuseMaterial myMaterial = new DiffuseMaterial(myHorizontalGradient);
            myGeometryModel.Material = myMaterial;
            // Apply multiple transformations to the object. In this sample, a rotation and scale 
            // transform is applied.

            // Create and apply a transformation that rotates the object.
            RotateTransform3D myRotateTransform3D = new RotateTransform3D();
            AxisAngleRotation3D myAxisAngleRotation3d = new AxisAngleRotation3D();
            myAxisAngleRotation3d.Axis = new Vector3D(0,3,0);
            myAxisAngleRotation3d.Angle = 40;
            myRotateTransform3D.Rotation = myAxisAngleRotation3d;

            // Add the rotation transform to a Transform3DGroup
            Transform3DGroup myTransform3DGroup = new Transform3DGroup();
            myTransform3DGroup.Children.Add(myRotateTransform3D);

            // Create and apply a scale transformation that stretches the object along the local x-axis  
            // by 200 percent and shrinks it along the local y-axis by 50 percent.
            ScaleTransform3D myScaleTransform3D = new ScaleTransform3D();
            myScaleTransform3D.ScaleX = 2;
            myScaleTransform3D.ScaleY = 0.5;
            myScaleTransform3D.ScaleZ = 1;

            // Add the scale transform to the Transform3DGroup.
            myTransform3DGroup.Children.Add(myScaleTransform3D);

            // Set the Transform property of the GeometryModel to the Transform3DGroup which includes 
            // both transformations. The 3D object now has two Transformations applied to it.
            myGeometryModel.Transform = myTransform3DGroup;
            // Add the geometry model to the model group.
            myModel3DGroup.Children.Add(myGeometryModel);

            // Add the group of models to the ModelVisual3d.
            myModelVisual3D.Content = myModel3DGroup;

            myViewport3D.Children.Add(myModelVisual3D);

            // Apply the viewport to the page so it will be rendered.
            this.Content = myViewport3D;
        }
    }
}
```


### [Animate 3-D Translations](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-animate-3-d-translations)

本主题演示如何进行动画处理上设置的平移转换三维模型。

下面的代码显示的应用程序[TranslateTransform3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.translatetransform3d)对象传递给[Transform](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.model3d.transform)属性的[GeometryModel3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.geometrymodel3d)。

```xaml
<!-- The Transform specifies how to transform the 3D object. The OffsetX property is animated
     in the Storyboard below. -->
<GeometryModel3D.Transform>
  <TranslateTransform3D x:Name="myTranslateTransform3D" OffsetX="0" OffsetY="0" OffsetZ="0" />
</GeometryModel3D.Transform>
```

[OffsetX](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.translatetransform3d.offsetx)属性的[TranslateTransform3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.translatetransform3d)对象进行动画处理，使用下面的代码。

```xaml
<!-- Trigger the TranslateTransform3D animation when the 3D object loads. -->
<Viewport3D.Triggers>
  <EventTrigger RoutedEvent="Viewport3D.Loaded">
    <BeginStoryboard>
      <Storyboard>

        <!-- This animation animates the OffsetX property of the TranslateTransform3D. -->
        <DoubleAnimation
         Storyboard.TargetName="myTranslateTransform3D" 
         Storyboard.TargetProperty="OffsetX" 
         To="-0.8" 
         AutoReverse="True" RepeatBehavior="Forever" />

        <!-- If you want to animate OffsetY and/or OffsetZ, create similar DoubleAnimations
             respectively. -->

      </Storyboard>
    </BeginStoryboard>
  </EventTrigger>
</Viewport3D.Triggers>
```

#### 示例

下面的代码演示了整个示例。

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml" >
  <DockPanel>
    <Viewbox>
      <Canvas Width="600" Height="201">

        <!-- The Viewport3D provides a rendering surface for 3-D visual content. -->
        <Viewport3D Name="MyAnimatedObject"
          ClipToBounds="True" Width="600" Height="150"
          Canvas.Left="0" Canvas.Top="10">

          <!-- Defines the camera used to view the 3D object. -->
          <Viewport3D.Camera>
            <PerspectiveCamera x:Name="myPerspectiveCamera" Position="0,0,2" LookDirection="0,0,-1" 
             FieldOfView="60" />
          </Viewport3D.Camera>

          <!-- The ModelVisual3D children contain the 3D models -->
          <Viewport3D.Children>

            <!-- This ModelVisual3D defines the light cast in the scene. Without light, the
                 3D object cannot be seen. -->
            <ModelVisual3D>
              <ModelVisual3D.Content>
                <DirectionalLight Color="#FFFFFF" Direction="-0.612372,-0.5,-0.612372" />
              </ModelVisual3D.Content>
            </ModelVisual3D>
            <ModelVisual3D>
              <ModelVisual3D.Content>
                <GeometryModel3D>

                  <!-- The geometry specifes the shape of the 3D plane. In this case, a flat sheet is created. -->
                  <GeometryModel3D.Geometry>
                    <MeshGeometry3D
                     TriangleIndices="0,1,2 3,4,5 "
                     Normals="0,0,1 0,0,1 0,0,1 0,0,1 0,0,1 0,0,1 "
                     TextureCoordinates="0,0 1,0 1,1 1,1 0,1 0,0 "
                     Positions="-0.5,-0.5,0.5 0.5,-0.5,0.5 0.5,0.5,0.5 0.5,0.5,0.5 -0.5,0.5,0.5 -0.5,-0.5,0.5 " />
                  </GeometryModel3D.Geometry>

                  <!-- The material specifies the material applied to the plane. In this case it is a linear gradient.-->
                  <GeometryModel3D.Material>
                    <MaterialGroup>
                      <DiffuseMaterial>
                        <DiffuseMaterial.Brush>
                          <SolidColorBrush Color="Cyan" Opacity="0.3"/>
                        </DiffuseMaterial.Brush>
                      </DiffuseMaterial>
                    </MaterialGroup>
                  </GeometryModel3D.Material>
                  <!-- The Transform specifies how to transform the 3D object. The OffsetX property is animated
                       in the Storyboard below. -->
                  <GeometryModel3D.Transform>
                    <TranslateTransform3D x:Name="myTranslateTransform3D" OffsetX="0" OffsetY="0" OffsetZ="0" />
                  </GeometryModel3D.Transform>
                </GeometryModel3D>
              </ModelVisual3D.Content>
            </ModelVisual3D>
          </Viewport3D.Children>
          <!-- Trigger the TranslateTransform3D animation when the 3D object loads. -->
          <Viewport3D.Triggers>
            <EventTrigger RoutedEvent="Viewport3D.Loaded">
              <BeginStoryboard>
                <Storyboard>

                  <!-- This animation animates the OffsetX property of the TranslateTransform3D. -->
                  <DoubleAnimation
                   Storyboard.TargetName="myTranslateTransform3D" 
                   Storyboard.TargetProperty="OffsetX" 
                   To="-0.8" 
                   AutoReverse="True" RepeatBehavior="Forever" />

                  <!-- If you want to animate OffsetY and/or OffsetZ, create similar DoubleAnimations
                       respectively. -->

                </Storyboard>
              </BeginStoryboard>
            </EventTrigger>
          </Viewport3D.Triggers>
        </Viewport3D>
      </Canvas>
    </Viewbox>
  </DockPanel>
</Page>
```

### [Animate a 3-D Rotation Using Storyboards](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-animate-a-3-d-rotation-using-storyboards)

下面的示例演示如何创建旋转时它"松动"通过进行动画处理的三维对象[Angle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.axisanglerotation3d.angle)并[Axis](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.axisanglerotation3d.axis)的属性[AxisAngleRotation3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.axisanglerotation3d)对象。 这[AxisAngleRotation3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.axisanglerotation3d)对象指定的旋转变换的三维对象，并因此对其属性进行动画处理创建需的旋转效果。在情节提要[DoubleAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.doubleanimation)用于进行动画处理[Angle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.axisanglerotation3d.angle)属性，同时[Vector3DAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.vector3danimation)用于进行动画处理[Axis](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.axisanglerotation3d.axis)属性。

#### 示例

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml" >
  <DockPanel>
    <Viewbox>
      <Canvas Width="321" Height="201">

        <!-- The Viewport3D provides a rendering surface for 3-D visual content. -->
        <Viewport3D Name="MyAnimatedObject"
          ClipToBounds="True" Width="150" Height="150"
          Canvas.Left="0" Canvas.Top="10">

          <!-- Defines the camera used to view the 3D object. -->
          <Viewport3D.Camera>
            <PerspectiveCamera x:Name="myPerspectiveCamera" Position="0,0,2" LookDirection="0,0,-1" 
             FieldOfView="60" />
          </Viewport3D.Camera>

          <!-- The ModelVisual3D children contain the 3D models -->
          <Viewport3D.Children>

            <!-- Two ModelVisual3D define the lights cast in the scene. Without light, the
                 3D object cannot be seen. Also, the direction of the lights affect shadowing. -->
            <ModelVisual3D>
              <ModelVisual3D.Content>
                <DirectionalLight Color="#FFFFFF" Direction="-0.612372,-0.5,-0.612372" />
              </ModelVisual3D.Content>
            </ModelVisual3D>
            <ModelVisual3D>
              <ModelVisual3D.Content>
                <DirectionalLight Color="#FFFFFF" Direction="0.612372,-0.5,-0.612372" />
              </ModelVisual3D.Content>
            </ModelVisual3D>
            <ModelVisual3D>
              <ModelVisual3D.Content>
                <GeometryModel3D>

                  <!-- The geometry specifes the shape of the 3D plane. In this case, a flat sheet is created. -->
                  <GeometryModel3D.Geometry>
                    <MeshGeometry3D
                     TriangleIndices="0,1,2 3,4,5 "
                     Normals="0,0,1 0,0,1 0,0,1 0,0,1 0,0,1 0,0,1 "
                     TextureCoordinates="0,0 1,0 1,1 1,1 0,1 0,0 "
                     Positions="-0.5,-0.5,0.5 0.5,-0.5,0.5 0.5,0.5,0.5 0.5,0.5,0.5 -0.5,0.5,0.5 -0.5,-0.5,0.5 " />
                  </GeometryModel3D.Geometry>

                  <!-- The material specifies the material applied to the plane. In this case it is a linear gradient.-->
                  <GeometryModel3D.Material>
                    <MaterialGroup>
                      <DiffuseMaterial>
                        <DiffuseMaterial.Brush>
                          <LinearGradientBrush StartPoint="0,0.5" EndPoint="1,0.5">
                            <LinearGradientBrush.GradientStops>
                              <GradientStop Color="Yellow" Offset="0" />
                              <GradientStop Color="Red" Offset="0.25" />
                              <GradientStop Color="Blue" Offset="0.75" />
                              <GradientStop Color="LimeGreen" Offset="1" />
                            </LinearGradientBrush.GradientStops>
                          </LinearGradientBrush>
                        </DiffuseMaterial.Brush>
                      </DiffuseMaterial>
                    </MaterialGroup>
                  </GeometryModel3D.Material>

                  <!-- The Transform specifies how to transform the 3D object. The properties of the
                        Rotation object are animated causing the 3D object to rotate and "wobble" (see Storyboard below).-->
                  <GeometryModel3D.Transform>
                    <RotateTransform3D>
                      <RotateTransform3D.Rotation>
                        <AxisAngleRotation3D x:Name="myAngleRotation" Axis="0,3,0" Angle="40" />
                      </RotateTransform3D.Rotation>
                    </RotateTransform3D>
                  </GeometryModel3D.Transform>
                </GeometryModel3D>
              </ModelVisual3D.Content>
            </ModelVisual3D>
          </Viewport3D.Children>

          <!-- Trigger the rotation animation when the 3D object loads. -->
          <Viewport3D.Triggers>
            <EventTrigger RoutedEvent="Viewport3D.Loaded">
              <BeginStoryboard>
                <Storyboard>

                  <!-- This animation animates the Angle property of the AxisAngleRotation3D
                       making the 3D object rotate from -60 degrees to 60 degrees. -->
                  <DoubleAnimation 
                   Storyboard.TargetName="myAngleRotation" 
                   Storyboard.TargetProperty="Angle" 
                   From="-60" To="60" Duration="0:0:4" AutoReverse="True"  RepeatBehavior="Forever"/>

                  <!-- This animation animates the Axis property of the AxisAngleRotation3D
                       making the 3D wobble as it rotates. -->
                  <Vector3DAnimation 
                   Storyboard.TargetName="myAngleRotation" 
                   Storyboard.TargetProperty="Axis" 
                   From="0,3,0" To="1,0,1" Duration="0:0:4" AutoReverse="True"  RepeatBehavior="Forever"/>

                </Storyboard>
              </BeginStoryboard>
            </EventTrigger>
          </Viewport3D.Triggers>
        </Viewport3D>
      </Canvas>

    </Viewbox>
  </DockPanel>
</Page>
```

###  [Rotation Using Rotation3DAnimation](https://docs.microsoft.com/en-us/dotnet/framework/wpf/graphics-multimedia/how-to-animate-a-3-d-rotation-using-rotation3danimation)

下面的示例演示如何使旋转时它"松动"使用一个三维对象[Rotation3DAnimation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.animation.rotation3danimation)进行动画处理[Rotation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.rotatetransform3d.rotation)属性的[RotateTransform3D](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.media3d.rotatetransform3d)应用于三维对象的对象。

#### 示例

```xaml
<Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml" >
  <DockPanel>
    <Viewbox>
      <Canvas Width="321" Height="201">

        <!-- The Viewport3D provides a rendering surface for 3-D visual content. -->
        <Viewport3D Name="MyAnimatedObject"
          ClipToBounds="True" Width="150" Height="150"
          Canvas.Left="0" Canvas.Top="10">

          <!-- Defines the camera used to view the 3D object. -->
          <Viewport3D.Camera>
            <PerspectiveCamera x:Name="myPerspectiveCamera" Position="0,0,2" LookDirection="0,0,-1" 
             FieldOfView="60" />
          </Viewport3D.Camera>

          <!-- The ModelVisual3D children contain the 3D models -->
          <Viewport3D.Children>

            <!-- Two ModelVisual3D define the lights cast in the scene. Without light, the
                 3D object cannot be seen. Also, the direction of the lights affect shadowing. -->
            <ModelVisual3D>
              <ModelVisual3D.Content>
                <DirectionalLight Color="#FFFFFF" Direction="-0.612372,-0.5,-0.612372" />
              </ModelVisual3D.Content>
            </ModelVisual3D>
            <ModelVisual3D>
              <ModelVisual3D.Content>
                <DirectionalLight Color="#FFFFFF" Direction="0.612372,-0.5,-0.612372" />
              </ModelVisual3D.Content>
            </ModelVisual3D>
            <ModelVisual3D>
              <ModelVisual3D.Content>
                <GeometryModel3D>

                  <!-- The geometry specifes the shape of the 3D plane. In this case, a flat sheet is created. -->
                  <GeometryModel3D.Geometry>
                    <MeshGeometry3D
                     TriangleIndices="0,1,2 3,4,5 "
                     Normals="0,0,1 0,0,1 0,0,1 0,0,1 0,0,1 0,0,1 "
                     TextureCoordinates="0,0 1,0 1,1 1,1 0,1 0,0 "
                     Positions="-0.5,-0.5,0.5 0.5,-0.5,0.5 0.5,0.5,0.5 0.5,0.5,0.5 -0.5,0.5,0.5 -0.5,-0.5,0.5 " />
                  </GeometryModel3D.Geometry>

                  <!-- The material specifies the material applied to the plane. In this case it is a linear gradient.-->
                  <GeometryModel3D.Material>
                    <MaterialGroup>
                      <DiffuseMaterial>
                        <DiffuseMaterial.Brush>
                          <LinearGradientBrush StartPoint="0,0.5" EndPoint="1,0.5">
                            <LinearGradientBrush.GradientStops>
                              <GradientStop Color="Yellow" Offset="0" />
                              <GradientStop Color="Red" Offset="0.25" />
                              <GradientStop Color="Blue" Offset="0.75" />
                              <GradientStop Color="LimeGreen" Offset="1" />
                            </LinearGradientBrush.GradientStops>
                          </LinearGradientBrush>
                        </DiffuseMaterial.Brush>
                      </DiffuseMaterial>
                    </MaterialGroup>
                  </GeometryModel3D.Material>

                  <!-- The Transform specifies how to transform the 3D object. The properties of the
                        Rotation object are animated causing the 3D object to rotate and "wobble" (see Storyboard below).-->
                  <GeometryModel3D.Transform>
                    <RotateTransform3D x:Name="myRotateTransform3D" >
                      <RotateTransform3D.Rotation>
                        <AxisAngleRotation3D Axis="0,3,0" Angle="40" />
                      </RotateTransform3D.Rotation>
                    </RotateTransform3D>
                  </GeometryModel3D.Transform>
                </GeometryModel3D>
              </ModelVisual3D.Content>
            </ModelVisual3D>
          </Viewport3D.Children>

          <!-- Trigger the rotation animation when the 3D object loads. -->
          <Viewport3D.Triggers>
            <EventTrigger RoutedEvent="Viewport3D.Loaded">
              <BeginStoryboard>
                <Storyboard>

                  <!-- This animation animates the Rotation property of the RotateTransform
                       causing the 3D shape to rotate and wobble as the rotation angle and 
                       axis are animated. -->
                  <Rotation3DAnimation
                   Storyboard.TargetName="myRotateTransform3D" 
                   Storyboard.TargetProperty="Rotation" 
                   AutoReverse="True"  RepeatBehavior="Forever">
                    <Rotation3DAnimation.From>
                      <AxisAngleRotation3D Axis="0,3,0" Angle="-60" />
                    </Rotation3DAnimation.From>
                    <Rotation3DAnimation.To>
                      <AxisAngleRotation3D Axis="1,0,1" Angle="60" />
                    </Rotation3DAnimation.To>
                  </Rotation3DAnimation>

                </Storyboard>
              </BeginStoryboard>
            </EventTrigger>
          </Viewport3D.Triggers>
        </Viewport3D>
      </Canvas>
    </Viewbox>
  </DockPanel>
</Page>
```