[TOC]

# 委托

## 什么是委托
- 类类型,即委托是一种类,是一种引用类型
    - 可以被赋予null,类的实例  
- 特殊性
    - 功能:用来包裹着一些方法,通过委托来间接调用方法,即委托是一个方法的包装器
        - 相当于C++的函数指针
        - 多播委托:一次调用相当于调用一组函数
    - 声明:用`delegate`关键字,需要说明包裹的函数类型(函数的返回值类型,参数列表)

## 委托类型是怎么声明出来的 

## 泛型委托

## 我们必须自己创建委托类型吗
- .Net内置了
    - void类型委托
    - 有返回值类型

## 泛型委托的类型参数推断

# Lambda
- 匿名方法
- Inline方法
    - 声明并调用

- 减少代码的碎片化

## 方法与Lambda表达式之间的关系

## 如何把一个Lambda表达式赋值给一个委托类型变量

## 如何把一个Lambda表达式"喂"给一个委托类型的参数

# LINQ
- LINQ:.NET Language Intergrated Query
- C# => SQL

## ADO.NET Entity Data Model
- 需要安装SQL Server
- ORM:Object->Relational Mapping
- LINQ 扩展方法:[Enumerable Methods](https://msdn.microsoft.com/en-us/library/system.linq.enumerable_methods(v=vs.110).aspx)