# [Access Keywords](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/access-keywords)

本部分介绍以下访问关键字：

- [base](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/base)

  访问基类成员。

- [this](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/this)

  引用类的当前实例。

## [base](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/base)

`base` 关键字用于从派生类中访问基类的成员：

- 调用基类上已被其他方法重写的方法。
- 指定创建派生类实例时应调用的基类构造函数。

仅允许基类访问在构造函数、实例方法或实例属性访问器中进行。

从静态方法中使用 `base` 关键字是错误的。

所访问的基类是类声明中指定的基类。 例如，如果指定 `class ClassB : ClassA`，则从 ClassB 访问 ClassA 的成员，而不考虑 ClassA 的基类。

### 示例

在本例中，基类 `Person` 和派生类 `Employee` 都有一个名为 `Getinfo` 的方法。 通过使用 `base` 关键字，可以从派生类中调用基类的 `Getinfo` 方法。

```csharp
public class Person
{
    protected string ssn = "444-55-6666";
    protected string name = "John L. Malgraine";

    public virtual void GetInfo()
    {
        Console.WriteLine("Name: {0}", name);
        Console.WriteLine("SSN: {0}", ssn);
    }
}
class Employee : Person
{
    public string id = "ABC567EFG";
    public override void GetInfo()
    {
        // Calling the base class GetInfo method:
        base.GetInfo();
        Console.WriteLine("Employee ID: {0}", id);
    }
}

class TestClass
{
    static void Main()
    {
        Employee E = new Employee();
        E.GetInfo();
    }
}
/*
Output
Name: John L. Malgraine
SSN: 444-55-6666
Employee ID: ABC567EFG
*/
```

有关其他示例，请参阅 [new](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/new)、[virtual](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/virtual) 和 [override](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/override)。

### 示例

本示例显示如何指定在创建派生类实例时调用的基类构造函数。

```csharp
public class BaseClass
{
    int num;

    public BaseClass()
    {
        Console.WriteLine("in BaseClass()");
    }

    public BaseClass(int i)
    {
        num = i;
        Console.WriteLine("in BaseClass(int i)");
    }

    public int GetNum()
    {
        return num;
    }
}

public class DerivedClass : BaseClass
{
    // This constructor will call BaseClass.BaseClass()
    public DerivedClass() : base()
    {
    }

    // This constructor will call BaseClass.BaseClass(int i)
    public DerivedClass(int i) : base(i)
    {
    }

    static void Main()
    {
        DerivedClass md = new DerivedClass();
        DerivedClass md1 = new DerivedClass(1);
    }
}
/*
Output:
in BaseClass()
in BaseClass(int i)
*/
```

## [this](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/this)

`this` 关键字指代类的当前实例，还可用作扩展方法的第一个参数的修饰符。

> 本文介绍 `this` 在类实例中的用法。 若要深入了解它在扩展方法中的用法，请参阅[扩展方法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/extension-methods)。

以下是 `this` 的常见用法：

- 限定类似名称隐藏的成员，例如：

  ```csharp
  public class Employee
  {
      private string alias;
      private string name;
  
      public Employee(string name, string alias)
      {
          // Use this to qualify the members of the class 
          // instead of the constructor parameters.
          this.name = name;
          this.alias = alias;
      }
  }
  ```

- 将对象作为参数传递给方法，例如：

  ```csharp
  CalcTax(this);
  ```

- 声明索引器，例如：

  ```csharp
  public int this[int param]
  {
      get { return array[param]; }
      set { array[param] = value; }
  }
  ```

静态成员函数，因为它们存在于类级别且不属于对象，不具有 `this` 指针。 在静态方法中引用 `this` 是错误的。

### 示例

在此示例中，`this` 用于限定类似名称隐藏的 `Employee` 类成员、`name` 和 `alias`。 它还用于将某个对象传递给属于其他类的方法 `CalcTax`。

```csharp
class Employee
{
    private string name;
    private string alias;
    private decimal salary = 3000.00m;

    // Constructor:
    public Employee(string name, string alias)
    {
        // Use this to qualify the fields, name and alias:
        this.name = name;
        this.alias = alias;
    }

    // Printing method:
    public void printEmployee()
    {
        Console.WriteLine("Name: {0}\nAlias: {1}", name, alias);
        // Passing the object to the CalcTax method by using this:
        Console.WriteLine("Taxes: {0:C}", Tax.CalcTax(this));
    }

    public decimal Salary
    {
        get { return salary; }
    }
}

class Tax
{
    public static decimal CalcTax(Employee E)
    {
        return 0.08m * E.Salary;
    }
}

class MainClass
{
    static void Main()
    {
        // Create objects:
        Employee E1 = new Employee("Mingda Pan", "mpan");

        // Display results:
        E1.printEmployee();
    }
}
/*
Output:
    Name: Mingda Pan
    Alias: mpan
    Taxes: $240.00
 */
```