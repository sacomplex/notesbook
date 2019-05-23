# [Programming Concepts](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/)

## [Reflection](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/reflection)

反射提供描述程序集、模块和类型的对象（[Type](https://docs.microsoft.com/zh-cn/dotnet/api/system.type) 类型）。 可以使用反射动态地创建类型的实例，将类型绑定到现有对象，或从现有对象中获取类型，然后调用其方法或访问其字段和属性。 如果代码中使用了特性，可以利用反射来访问它们。 有关更多信息，请参阅[特性](https://docs.microsoft.com/zh-cn/dotnet/standard/attributes/index)。

下面一个简单的反射示例，使用静态方法 `GetType`被 `Object` 基类的所有类型继承）以获取变量类型：

```csharp
// Using GetType to obtain type information:  
int i = 42;  
System.Type type = i.GetType();  
System.Console.WriteLine(type);  
```

输出为：

```
System.Int32
```

下面的示例使用反射获取已加载的程序集的完整名称。

```csharp
// Using Reflection to get information from an Assembly:  
System.Reflection.Assembly info = typeof(System.Int32).Assembly;  
System.Console.WriteLine(info);  
```

输出为：

```
mscorlib, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089
```

> C# 关键字 `protected` 和 `internal` 在 IL 中没有任何意义，且不会用于反射 API 中。 在 IL 中对应的术语为“系列”和“程序集”。 若要标识 `internal` 使用反射的方法，请使用 [IsAssembly](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.methodbase.isassembly) 属性。 若要标识 `protected internal` 方法，请使用 [IsFamilyOrAssembly](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.methodbase.isfamilyorassembly)。

### 反射概述

反射在以下情况下很有用：

- 需要访问程序元数据中的特性时。 有关详细信息，请参阅[检索存储在特性中的信息](https://docs.microsoft.com/zh-cn/dotnet/standard/attributes/retrieving-information-stored-in-attributes)。
- 检查和实例化程序集中的类型。
- 在运行时构建新类型。 使用 [System.Reflection.Emit](https://docs.microsoft.com/zh-cn/dotnet/api/system.reflection.emit) 中的类。
- 执行后期绑定，访问在运行时创建的类型上的方法。 请参阅主题 [Dynamically Loading and Using Types](https://docs.microsoft.com/zh-cn/dotnet/framework/reflection-and-codedom/dynamically-loading-and-using-types)（动态加载和使用类型）。