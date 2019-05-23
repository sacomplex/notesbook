[C# programming guide](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/index)

# Language Sections

## [Events](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/events/index)

[类](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/class) 或对象可以通过事件向其他类或对象通知发生的相关事情。 发送（或 *引发*）事件的类称为“发行者” ，接收（或 *处理*）事件的类称为“订户” 。

在典型的 C# Windows 窗体或 Web 应用程序中，可订阅由按钮和列表框等控件引发的事件。 可以使用 Visual C# 集成开发环境 (IDE) 来浏览控件发布的事件，并选择想要处理的事件。 借助 IDE，可轻松自动添加空白事件处理程序方法以及要订阅该事件的代码。 有关详细信息，请参阅[如何：订阅和取消订阅事件](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/events/how-to-subscribe-to-and-unsubscribe-from-events)。

### 事件概述

事件具有以下属性：

- 发行者确定何时引发事件；订户确定对事件作出何种响应。
- 一个事件可以有多个订户。 订户可以处理来自多个发行者的多个事件。
- 没有订户的事件永远也不会引发。
- 事件通常用于表示用户操作，例如单击按钮或图形用户界面中的菜单选项。
- 当事件具有多个订户时，引发该事件时会同步调用事件处理程序。 若要异步调用事件，请参阅 [Calling Synchronous Methods Asynchronously](https://docs.microsoft.com/zh-cn/dotnet/standard/asynchronous-programming-patterns/calling-synchronous-methods-asynchronously)。
- 在 .NET Framework 类库中，事件基于 [EventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.eventhandler) 委托和 [EventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.eventargs) 基类。

### [How to: Subscribe to and Unsubscribe from Events](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/events/how-to-subscribe-to-and-unsubscribe-from-events)

如果想编写引发事件时调用的自定义代码，则可以订阅由其他类发布的事件。 例如，可以订阅某个按钮的 `click`事件，以使应用程序在用户单击该按钮时执行一些有用的操作。

#### 订阅事件

##### 使用 Visual Studio IDE 订阅事件

1. 如果看不到“属性”窗口，请在“设计”视图中，右键单击要为其创建事件处理程序的窗体或控件，然后选择“属性”。

2. 在“属性”窗口的顶部，单击“事件”图标。

3. 双击要创建的事件，例如 `Load` 事件。

   Visual C# 会创建一个空事件处理程序方法，并将其添加到你的代码中。 或者，也可以在“代码”视图中手动添加代码。 例如，下面的代码行声明了一个在 `Form` 类引发 `Load` 事件时调用的事件处理程序方法。

   ```csharp
   private void Form1_Load(object sender, System.EventArgs e)
   {
       // Add your form load event handling code here.
   }
   ```

   还会在项目的 Form1.Designer.cs 文件的 `InitializeComponent` 方法中自动生成订阅该事件所需的代码行。该代码行类似于：

   ```csharp
   this.Load += new System.EventHandler(this.Form1_Load);  
   ```

##### 以编程方式订阅事件

1. 定义一个事件处理程序方法，其签名与该事件的委托签名匹配。 例如，如果事件基于 [EventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.eventhandler) 委托类型，则下面的代码表示方法存根：

   ```csharp
   void HandleCustomEvent(object sender, CustomEventArgs a)  
   {  
      // Do something useful here.  
   }  
   ```

2. 使用加法赋值运算符 (`+=`) 来为事件附加事件处理程序。 在下面的示例中，假设名为 `publisher` 的对象拥有一个名为 `RaiseCustomEvent` 的事件。 请注意，订户类需要引用发行者类才能订阅其事件。

   ```csharp
   publisher.RaiseCustomEvent += HandleCustomEvent;  
   ```

   请注意，前面的语法是 C# 2.0 中的新语法。 此语法完全等效于必须使用 `new` 关键字显式创建封装委托的 C# 1.0 语法：

   ```csharp
   publisher.RaiseCustomEvent += new CustomEventHandler(HandleCustomEvent);  
   ```

   还可以通过使用 lambda 表达式添加事件处理程序：

   ```csharp
   public Form1()  
   {  
       InitializeComponent();  
       // Use a lambda expression to define an event handler.  
       this.Click += (s,e) => { MessageBox.Show(  
          ((MouseEventArgs)e).Location.ToString());};  
   }  
   ```

   有关详细信息，请参阅[如何：在 LINQ 外部使用 Lambda 表达式](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/how-to-use-lambda-expressions-outside-linq)。

##### 使用匿名方法订阅事件

- 如果以后不必取消订阅某个事件，则可以使用加法赋值运算符 (`+=`) 将匿名方法附加到此事件。 在下面的示例中，假设名为 `publisher` 的对象拥有一个名为 `RaiseCustomEvent` 的事件，并且还定义了一个 `CustomEventArgs` 类以承载某些类型的专用事件信息。 请注意，订户类需要引用 `publisher` 才能订阅其事件。

  ```csharp
  publisher.RaiseCustomEvent += delegate(object o, CustomEventArgs e)  
  {  
    string s = o.ToString() + " " + e.ToString();  
    Console.WriteLine(s);  
  };  
  ```

  请务必注意，如果使用匿名函数订阅事件，事件的取消订阅过程将比较麻烦。 这种情况下若要取消订阅，必须返回到该事件的订阅代码，将该匿名方法存储在委托变量中，然后将此委托添加到该事件中。 一般来说，如果必须在后面的代码中取消订阅某个事件，则建议不要使用匿名函数订阅此事件。 有关匿名函数的详细信息，请参阅[匿名函数](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/statements-expressions-operators/anonymous-functions)。

#### 取消订阅

若要防止在引发事件时调用事件处理程序，请取消订阅该事件。 为了防止资源泄露，应在释放订户对象之前取消订阅事件。 在取消订阅事件之前，在发布对象中作为该事件的基础的多播委托会引用封装了订户的事件处理程序的委托。 只要发布对象保持该引用，垃圾回收功能就不会删除订户对象。

##### 取消订阅事件

- 使用减法赋值运算符 (`-=`) 取消订阅事件：

  ```csharp
  publisher.RaiseCustomEvent -= HandleCustomEvent;  
  ```

  所有订户都取消订阅事件后，发行者类中的事件实例将设置为 `null`。

### [How to: Publish Events that Conform to .NET Framework Guidelines](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/events/how-to-publish-events-that-conform-to-net-framework-guidelines)

下面的过程演示了如何将遵循标准 .NET Framework 模式的事件添加到类和结构中。 .NET Framework 类库中的所有事件均基于 [EventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.eventhandler) 委托，定义如下：

```csharp
public delegate void EventHandler(object sender, EventArgs e);  
```

>  .NET Framework 2.0 引入了泛型版本的委托 [EventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.eventhandler-1)。 下例演示了如何使用这两个版本。

尽管定义的类中的事件可基于任何有效委托类型，甚至是返回值的委托，但一般还是建议使用 [EventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.eventhandler) 使事件基于 .NET Framework 模式，如下例中所示。

#### 发布基于 EventHandler 模式的事件

1. （如果无需随事件一起发送自定义数据，请跳过此步骤转到步骤 3a。）将自定义数据的类声明为对发布服务器和订阅者类均可见的范围。 然后添加所需成员以保留自定义事件数据。 在此示例中，将返回一个简单的字符串。

   ```csharp
   public class CustomEventArgs : EventArgs  
   {  
       public CustomEventArgs(string s)  
       {  
           msg = s;  
       }  
       private string msg;  
       public string Message  
       {  
           get { return msg; }  
       }   
   }  
   ```

2. （如果正在使用泛型版本 [EventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.eventhandler-1)，请跳过此步骤。）声明发布类中的委托。 为以 EventHandler 结尾的委托命名。 第二个参数指定自定义 EventArgs 类型。

   ```csharp
   public delegate void CustomEventHandler(object sender, CustomEventArgs a);  
   ```

3. 使用下列步骤之一来声明发布类中的事件。

   1. 如果没有任何自定义 EventArgs 类，事件类型将为非泛型 EventHandler 委托。 你无需声明该委托，因为它已在创建 C# 项目时包括的 [System](https://docs.microsoft.com/zh-cn/dotnet/api/system) 命名空间中声明。 将以下代码添加到发布服务器类。

      ```csharp
      public event EventHandler RaiseCustomEvent;  
      ```

   2. 如果使用非泛型版本 [EventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.eventhandler) 并且具有派生自 [EventArgs](https://docs.microsoft.com/zh-cn/dotnet/api/system.eventargs) 的自定义类，请声明发布类中的事件，并将步骤 2 中的委托用作类型。

      ```csharp
      public event CustomEventHandler RaiseCustomEvent;  
      ```

   3. 如果使用泛型版本，则无需自定义委托。 而是在发布类中，将事件类型指定为 `EventHandler<CustomEventArgs>`，替换尖括号中自定义类的名称。

      ```csharp
      public event EventHandler<CustomEventArgs> RaiseCustomEvent;  
      ```

#### 示例

下例通过使用自定义 EventArgs 类和 [EventHandler](https://docs.microsoft.com/zh-cn/dotnet/api/system.eventhandler-1) 作为事件类型来演示之前的步骤。

```csharp
namespace DotNetEvents
{
    using System;
    using System.Collections.Generic;

    // Define a class to hold custom event info
    public class CustomEventArgs : EventArgs
    {
        public CustomEventArgs(string s)
        {
            message = s;
        }
        private string message;

        public string Message
        {
            get { return message; }
            set { message = value; }
        }
    }

    // Class that publishes an event
    class Publisher
    {

        // Declare the event using EventHandler<T>
        public event EventHandler<CustomEventArgs> RaiseCustomEvent;

        public void DoSomething()
        {
            // Write some code that does something useful here
            // then raise the event. You can also raise an event
            // before you execute a block of code.
            OnRaiseCustomEvent(new CustomEventArgs("Did something"));

        }

        // Wrap event invocations inside a protected virtual method
        // to allow derived classes to override the event invocation behavior
        protected virtual void OnRaiseCustomEvent(CustomEventArgs e)
        {
            // Make a temporary copy of the event to avoid possibility of
            // a race condition if the last subscriber unsubscribes
            // immediately after the null check and before the event is raised.
            EventHandler<CustomEventArgs> handler = RaiseCustomEvent;

            // Event will be null if there are no subscribers
            if (handler != null)
            {
                // Format the string to send inside the CustomEventArgs parameter
                e.Message += $" at {DateTime.Now}";

                // Use the () operator to raise the event.
                handler(this, e);
            }
        }
    }

    //Class that subscribes to an event
    class Subscriber
    {
        private string id;
        public Subscriber(string ID, Publisher pub)
        {
            id = ID;
            // Subscribe to the event using C# 2.0 syntax
            pub.RaiseCustomEvent += HandleCustomEvent;
        }

        // Define what actions to take when the event is raised.
        void HandleCustomEvent(object sender, CustomEventArgs e)
        {
            Console.WriteLine(id + " received this message: {0}", e.Message);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Publisher pub = new Publisher();
            Subscriber sub1 = new Subscriber("sub1", pub);
            Subscriber sub2 = new Subscriber("sub2", pub);

            // Call the method that raises the event.
            pub.DoSomething();

            // Keep the console window open
            Console.WriteLine("Press Enter to close this window.");
            Console.ReadLine();

        }
    }
}
```

### [How to: Raise Base Class Events in Derived Classes](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/events/how-to-raise-base-class-events-in-derived-classes)

下面的简单示例演示用于在基类中声明事件，以便也可以从派生类引发它们的标准方法。 在 .NET Framework 类库的 Windows 窗体类中广泛使用了此模式。

创建可以用作其他类的基类的类时，应考虑到以下事实：事件是特殊类型的委托，只能从声明它们的类中进行调用。 派生类不能直接调用在基类中声明的事件。 虽然有时可能需要只能由基类引发的事件，不过在大多数情况下，应使派生类可以调用基类事件。 为此，可以在包装事件的基类中创建受保护的调用方法。 通过调用或重写此调用方法，派生类可以间接调用事件。

> 不要在基类中声明虚拟事件并在派生类中重写它们。 C# 编译器不会处理这些事件，并且无法预知派生事件的订阅者是否实际上会订阅基类事件。

#### 示例

```csharp
namespace BaseClassEvents
{
    using System;
    using System.Collections.Generic;

    // Special EventArgs class to hold info about Shapes.
    public class ShapeEventArgs : EventArgs
    {
        private double newArea;

        public ShapeEventArgs(double d)
        {
            newArea = d;
        }
        public double NewArea
        {
            get { return newArea; }
        }
    }

    // Base class event publisher
    public abstract class Shape
    {
        protected double area;

        public double Area
        {
            get { return area; }
            set { area = value; }
        }
        // The event. Note that by using the generic EventHandler<T> event type
        // we do not need to declare a separate delegate type.
        public event EventHandler<ShapeEventArgs> ShapeChanged;

        public abstract void Draw();

        //The event-invoking method that derived classes can override.
        protected virtual void OnShapeChanged(ShapeEventArgs e)
        {
            // Make a temporary copy of the event to avoid possibility of
            // a race condition if the last subscriber unsubscribes
            // immediately after the null check and before the event is raised.
            EventHandler<ShapeEventArgs> handler = ShapeChanged;
            if (handler != null)
            {
                handler(this, e);
            }
        }
    }

    public class Circle : Shape
    {
        private double radius;
        public Circle(double d)
        {
            radius = d;
            area = 3.14 * radius * radius;
        }
        public void Update(double d)
        {
            radius = d;
            area = 3.14 * radius * radius;
            OnShapeChanged(new ShapeEventArgs(area));
        }
        protected override void OnShapeChanged(ShapeEventArgs e)
        {
            // Do any circle-specific processing here.

            // Call the base class event invocation method.
            base.OnShapeChanged(e);
        }
        public override void Draw()
        {
            Console.WriteLine("Drawing a circle");
        }
    }

    public class Rectangle : Shape
    {
        private double length;
        private double width;
        public Rectangle(double length, double width)
        {
            this.length = length;
            this.width = width;
            area = length * width;
        }
        public void Update(double length, double width)
        {
            this.length = length;
            this.width = width;
            area = length * width;
            OnShapeChanged(new ShapeEventArgs(area));
        }
        protected override void OnShapeChanged(ShapeEventArgs e)
        {
            // Do any rectangle-specific processing here.

            // Call the base class event invocation method.
            base.OnShapeChanged(e);
        }
        public override void Draw()
        {
            Console.WriteLine("Drawing a rectangle");
        }

    }

    // Represents the surface on which the shapes are drawn
    // Subscribes to shape events so that it knows
    // when to redraw a shape.
    public class ShapeContainer
    {
        List<Shape> _list;

        public ShapeContainer()
        {
            _list = new List<Shape>();
        }

        public void AddShape(Shape s)
        {
            _list.Add(s);
            // Subscribe to the base class event.
            s.ShapeChanged += HandleShapeChanged;
        }

        // ...Other methods to draw, resize, etc.

        private void HandleShapeChanged(object sender, ShapeEventArgs e)
        {
            Shape s = (Shape)sender;

            // Diagnostic message for demonstration purposes.
            Console.WriteLine("Received event. Shape area is now {0}", e.NewArea);

            // Redraw the shape here.
            s.Draw();
        }
    }

    class Test
    {

        static void Main(string[] args)
        {
            //Create the event publishers and subscriber
            Circle c1 = new Circle(54);
            Rectangle r1 = new Rectangle(12, 9);
            ShapeContainer sc = new ShapeContainer();

            // Add the shapes to the container.
            sc.AddShape(c1);
            sc.AddShape(r1);

            // Cause some events to be raised.
            c1.Update(57);
            r1.Update(7, 7);

            // Keep the console window open in debug mode.
            System.Console.WriteLine("Press any key to exit.");
            System.Console.ReadKey();
        }
    }
}
/* Output:
        Received event. Shape area is now 10201.86
        Drawing a circle
        Received event. Shape area is now 49
        Drawing a rectangle
 */
```

### [How to: Implement Interface Events](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/events/how-to-implement-interface-events)

[接口](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/interface)可以声明[事件](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/event)。 下面的示例演示如何在类中实现接口事件。 这些规则基本上都与实现任何接口方法或属性时的相同。

#### 在类中实现接口事件

在类中声明事件，然后在相应区域中调用它。

```csharp
namespace ImplementInterfaceEvents  
{  
    public interface IDrawingObject  
    {  
        event EventHandler ShapeChanged;  
    }  
    public class MyEventArgs : EventArgs   
    {  
        // class members  
    }  
    public class Shape : IDrawingObject  
    {  
        public event EventHandler ShapeChanged;  
        void ChangeShape()  
        {  
            // Do something here before the event…  

            OnShapeChanged(new MyEventArgs(/*arguments*/));  

            // or do something here after the event.   
        }  
        protected virtual void OnShapeChanged(MyEventArgs e)  
        {  
            ShapeChanged?.Invoke(this, e);  
        }  
    }  

}  
```

#### 示例

下面的示例演示如何处理不太常见的情况：类继承自两个或多个接口，且每个接口都具有相同名称的事件。 在这种情况下，你必须为至少其中一个事件提供显式接口实现。 为事件编写显式接口实现时，还必须编写 `add` 和 `remove` 事件访问器。 通常这些访问器由编译器提供，但在这种情况下编译器不提供它们。

通过提供自己的访问器，可以指定两个事件是由类中的同一个事件表示，还是由不同事件表示。 例如，如果根据接口规范应在不同时间引发事件，可以在类中将每个事件与单独实现关联。 在下面的示例中，订阅服务器确定它们通过将形状引用转换为 `IShape` 或 `IDrawingObject` 接收哪个 `OnDraw` 事件。

```csharp
namespace WrapTwoInterfaceEvents
{
    using System;

    public interface IDrawingObject
    {
        // Raise this event before drawing
        // the object.
        event EventHandler OnDraw;
    }
    public interface IShape
    {
        // Raise this event after drawing
        // the shape.
        event EventHandler OnDraw;
    }


    // Base class event publisher inherits two
    // interfaces, each with an OnDraw event
    public class Shape : IDrawingObject, IShape
    {
        // Create an event for each interface event
        event EventHandler PreDrawEvent;
        event EventHandler PostDrawEvent;

        object objectLock = new Object();

        // Explicit interface implementation required.
        // Associate IDrawingObject's event with
        // PreDrawEvent
        event EventHandler IDrawingObject.OnDraw
        {
            add
            {
                lock (objectLock)
                {
                    PreDrawEvent += value;
                }
            }
            remove
            {
                lock (objectLock)
                {
                    PreDrawEvent -= value;
                }
            }
        }

        // Explicit interface implementation required.
        // Associate IShape's event with
        // PostDrawEvent
        event EventHandler IShape.OnDraw
        {
            add
            {
                lock (objectLock)
                {
                    PostDrawEvent += value;
                }
            }
            remove
            {
                lock (objectLock)
                {
                    PostDrawEvent -= value;
                }
            }


        }

        // For the sake of simplicity this one method
        // implements both interfaces. 
        public void Draw()
        {
            // Raise IDrawingObject's event before the object is drawn.
            PreDrawEvent?.Invoke(this, EventArgs.Empty);

            Console.WriteLine("Drawing a shape.");

            // Raise IShape's event after the object is drawn.
            PostDrawEvent?.Invoke(this, EventArgs.Empty);
        }
    }
    public class Subscriber1
    {
        // References the shape object as an IDrawingObject
        public Subscriber1(Shape shape)
        {
            IDrawingObject d = (IDrawingObject)shape;
            d.OnDraw += d_OnDraw;
        }

        void d_OnDraw(object sender, EventArgs e)
        {
            Console.WriteLine("Sub1 receives the IDrawingObject event.");
        }
    }
    // References the shape object as an IShape
    public class Subscriber2
    {
        public Subscriber2(Shape shape)
        {
            IShape d = (IShape)shape;
            d.OnDraw += d_OnDraw;
        }

        void d_OnDraw(object sender, EventArgs e)
        {
            Console.WriteLine("Sub2 receives the IShape event.");
        }
    }


    public class Program
    {
        static void Main(string[] args)
        {
            Shape shape = new Shape();
            Subscriber1 sub = new Subscriber1(shape);
            Subscriber2 sub2 = new Subscriber2(shape);
            shape.Draw();

            // Keep the console window open in debug mode.
            System.Console.WriteLine("Press any key to exit.");
            System.Console.ReadKey();
        }
    }

}
/* Output:
    Sub1 receives the IDrawingObject event.
    Drawing a shape.
    Sub2 receives the IShape event.
*/
```

### [How to: Use a Dictionary to Store Event Instances](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/events/how-to-use-a-dictionary-to-store-event-instances)

`accessor-declarations` 的一个用途是公开多个事件，无需为每个事件分配一个字段，而是改用词典存储事件实例。 仅当拥有多个事件，但预计不会实现大多数事件时有用。

#### 示例

```csharp
using System;    
using System.Collections.Generic;    

public delegate void EventHandler1(int i);

public delegate void EventHandler2(string s);

public class PropertyEventsSample
{
    private readonly Dictionary<string, Delegate> _eventTable;
    private readonly List<EventHandler1> _event1List = new List<EventHandler1>();
    private readonly List<EventHandler2> _event2List = new List<EventHandler2>();
    public PropertyEventsSample()
    {
        _eventTable = new Dictionary<string, Delegate>
        {
            {"Event1", null},
            {"Event2", null}
        };
    }

    public event EventHandler1 Event1
    {
        add
        {
            _event1List.Add(value);
            lock (_eventTable)
            {
                _eventTable["Event1"] = (EventHandler1) _eventTable["Event1"] + value;
            }
        }
        remove
        {
            if (!_event1List.Contains(value)) return;
            _event1List.Remove(value);
            lock (_eventTable)
            {
                _eventTable["Event1"] = null;
                foreach (var event1 in _event1List)
                {
                    _eventTable["Event1"] = (EventHandler1) _eventTable["Event1"] + event1;
                }
            }
        }
    }

    public event EventHandler2 Event2
    {
        add
        {
            _event2List.Add(value);
            lock (_eventTable)
            {
                _eventTable["Event2"] = (EventHandler2) _eventTable["Event2"] + value;
            }
        }
        remove
        {
            if (!_event2List.Contains(value)) return;
            _event2List.Remove(value);
            lock (_eventTable)
            {
                _eventTable["Event2"] = null;
                foreach (var event2 in _event2List)
                {
                    _eventTable["Event2"] = (EventHandler2) _eventTable["Event2"] + event2;
                }
            }
        }
    }

    internal void RaiseEvent1(int i)
    {
        lock (_eventTable)
        {
            var handler1 = (EventHandler1) _eventTable["Event1"];
            handler1?.Invoke(i);
        }
    }

    internal void RaiseEvent2(string s)
    {
        lock (_eventTable)
        {
            var handler2 = (EventHandler2) _eventTable["Event2"];
            handler2?.Invoke(s);
        }
    }
}

public static class TestClass
{
    private static void Delegate1Method(int i)
    {
        Console.WriteLine(i);
    }

    private static void Delegate2Method(string s)
    {
        Console.WriteLine(s);
    }

    private static void Main()
    {
        var p = new PropertyEventsSample();

        p.Event1 += Delegate1Method;
        p.Event1 += Delegate1Method;
        p.Event1 -= Delegate1Method;
        p.RaiseEvent1(2);

        p.Event2 += Delegate2Method;
        p.Event2 += Delegate2Method;
        p.Event2 -= Delegate2Method;
        p.RaiseEvent2("TestString");

        // Keep the console window open in debug mode.
        Console.WriteLine("Press any key to exit.");
        Console.ReadKey();
    }
}
/* Output:
    2
    TestString
*/
```

### [How to: Implement Custom Event Accessors](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/events/how-to-implement-custom-event-accessors)

事件是一种特殊的多播委托，只能从声明它的类中进行调用。 客户端代码通过提供对应在引发事件时调用的方法的引用来订阅事件。 这些方法通过事件访问器添加到委托的调用列表中，事件访问器类似于属性访问器，不同之处在于事件访问器命名为 `add` 和 `remove`。 在大多数情况下，无需提供自定义事件访问器。 如果代码中没有提供自定义事件访问器，编译器将自动添加它们。 但在某些情况下，可能需要提供自定义行为。 主题[操作说明：实现接口事件](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/events/how-to-implement-interface-events)中介绍了这样一种情况。

#### 示例

下面的示例演示如何实现自定义的 add 和 remove 事件访问器。 虽然可以替换访问器内的任何代码，但建议先锁定事件，再添加或删除新的事件处理程序方法。

```csharp
event EventHandler IDrawingObject.OnDraw
{
    add
    {
        lock (objectLock)
        {
            PreDrawEvent += value;
        }
    }
    remove
    {
        lock (objectLock)
        {
            PreDrawEvent -= value;
        }
    }
}
```