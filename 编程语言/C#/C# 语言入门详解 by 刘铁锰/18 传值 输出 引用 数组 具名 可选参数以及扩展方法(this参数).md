[TOC]

# 18 传值/输出/引用/数组/具名/可选参数以及扩展方法(this参数)
- 对方法的进一步学习

## 值参数/传值参数
- 传入的是实参的副本,在方法体内的修改形参并不会改变实参  

- 传值参数->值类型(数据类型例如int)
- 传值参数->引用类型,并且新创建对象
    - 引用类型变量存储的是对象在内存中的地址
    - 方法的形参与实参指向同一个对象
    - 若在方法内部对形参赋值(new),形参会指向新的对象
    - `Object.GetHashCode()`:获取标识对象的唯一值
- 传值参数->引用类型,只操作对象,不创建新对象
    - 注意:因为形参和实参存储的是同一个对象的地址,在函数体内只是通过形参改变了对象内(属性/字段)的值.

## 引用参数  
- 声明时用`ref`修饰
- 引用参数并不会为传入的参数创建副本,而是直接指向实参的内存地址
- 变量在可以作为引用参数传递之前,必须先明确赋值,并加上`ref`修饰符

- 引用参数->值类型
    - 不创建副本
    - 需要显示使用`ref`关键字
    - 在函数内部改变了引用参数,实参也跟着改变
- 引用参数->引用类型,创建新对象
    - 参数如果被创建的新的对象赋值后,将不再指向实参的对象的地址
- 引用参数->引用类型,不创建新对象只改变对象值
    - 与传值参数效果类似,只是改变了对象的值(字段/属性),注意引用参数并不创建内存副本

## 输出参数
- 声明是使用`out`修饰符
- 输出参数不会创建新的实参副本
- 在方法返回之前,输出参数必须被明确赋值
- 输出形参通常用在需要产生多个返回值的方法中,即将方法之内值输出但方法之外
    - 否则方法只有一个返回值  
- 需要显示使用`out`关键字

- 输出参数->值类型
- 输出参数->引用类型

## 数组参数  
- 需要`params`关键字修饰  
- 不需要提前声明一个数组了,可以直接输入数组的元素即可
```
CalculateSum(1, 2, 3)
```
```
Console.WriteLine("{0} + {1} = {2}", x, y, z)
```
- 形参列表中只能有一个参数是数组参数,且必须是形参列表中的最后一个

## 具名参数
- 参数的位置不受约束
- 提高代码可读性
- 具名调用
```
namespace ParametersExample
{
    class Program
    {
        static void Main(string[] args)
        {
            PrintInfo(age:34, name:"Tim");
        }

        static void PrintInfo(string name, int age)
        {
            Console.WriteLine("Hello {0}, you are {1}", name, age);
        }
    }
}
```

## 可选参数  
- 参数因为具有默认值而变得可选
- 不推荐使用可选参数
```
namespace ParametersExample
{
    class Program
    {
        static void Main(string[] args)
        {
            PrintInfo();
        }

        static void PrintInfo(string name = "Tim", int age = 34)
        {
            Console.WriteLine("Hello {0}, you are {1}", name, age);
        }
    }
}
```

## 扩展方法(this参数)(重要)
- 对现有类的方法功能的扩展
- 方法必须是公有的,静态的,即被public static 所修饰
- 必需是形参列表中的第一个,由this修饰
- 必需由一个静态类(一般类名为SomeTypeExtension)来统一对SomeType类型的扩展方法
```
namespace ParametersExample
{
    class Program
    {
        static void Main(string[] args)
        {
            double x = 3.14159;
            //double y = Math.Round(x, 4);
            double y = x.Round(4);
            Console.WriteLine(y);
        }
    }

    static class DoubleExtension
    {
        public static double Round(this double input, int digits)
        {
            double result = Math.Round(input, digits);
            return result;
        }
    }
}
```
### LINQ  
```
using System;
using System.Collections.Generic;
using System.Linq;

namespace ParametersExample
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> myList = new List<int>() { 11, 12, 10, 14, 15};
            Console.WriteLine(myList.All(i => i > 10));
        }
    }
}
```