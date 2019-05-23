# [Threading Model](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/threading-model)

Windows Presentation Foundation (WPF) 旨在帮助开发人员处理复杂的线程处理问题。 因此，大部分WPF开发人员无需编写一个接口，使用多个线程。 由于多线程程序既复杂又难以调试，因此当存在单线程解决方案时，应避免使用多线程程序。

无论构建得多好，但是，否UIframework 曾经能够为每种问题提供单线程解决方案。 WPF 就关闭，但仍有些情况下，多个线程来改进用户界面 (UI)响应能力或应用程序的性能。 基于上文所述的背景材料，本文对上述情况进行探讨，然后通过对一些低级别的细节进行讨论作出总结。

> 本主题讨论了使用线程处理[BeginInvoke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher.begininvoke)异步调用的方法。 您还可以通过调用进行异步调用[InvokeAsync](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher.invokeasync)方法，这需要[Action](https://docs.microsoft.com/zh-cn/dotnet/api/system.action)或[Func](https://docs.microsoft.com/zh-cn/dotnet/api/system.func-1)作为参数。 [InvokeAsync](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher.invokeasync)方法将返回[DispatcherOperation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcheroperation)或[DispatcherOperation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcheroperation-1)，其中包含[Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcheroperation.task)属性。 可以使用`await`使用的关键字[DispatcherOperation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcheroperation)或关联[Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task)。 如果你需要同步等待[Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task)返回的[DispatcherOperation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcheroperation)或[DispatcherOperation](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcheroperation-1)，调用[DispatcherOperationWait](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.taskextensions.dispatcheroperationwait)扩展方法。 调用[Task.Wait](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task.wait)将导致死锁。 详细了解使用[Task](https://docs.microsoft.com/zh-cn/dotnet/api/system.threading.tasks.task)执行异步操作，请参阅任务并行。 [Invoke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher.invoke)方法还具有采用重载[Action](https://docs.microsoft.com/zh-cn/dotnet/api/system.action)或[Func](https://docs.microsoft.com/zh-cn/dotnet/api/system.func-1)作为参数。 可以使用[Invoke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher.invoke)方法来进行同步调用通过传入一个委托，委托[Action](https://docs.microsoft.com/zh-cn/dotnet/api/system.action)或[Func](https://docs.microsoft.com/zh-cn/dotnet/api/system.func-1)。



## 概述和调度程序

通常情况下，WPF应用程序启动两个线程： 一个用于处理呈现和另一个用于管理UI。 呈现线程有效地在隐藏模式运行的同时在后台UI线程接收输入、 处理事件、 绘制屏幕和运行应用程序代码。 大多数应用程序使用单个UI线程，尽管在某些情况下最好使用多个。 我们将稍后通过示例对此进行讨论。

UI线程队列工作项调用的对象内[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)。 [Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher) 基于优先级选择工作项，并运行每一个工作项直到完成。 每个UI线程必须至少一个[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)，和每个[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)可以在一个线程中执行的工作项。

构建响应迅速的用户友好应用程序的诀窍是最大限度地[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)通过保留的工作项小吞吐量。 这样，工作项永远不会过时坐在[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)队列等待处理。 输入和响应间任何可察觉的延迟都会让用户不满。

如何WPF应用程序应处理大型操作？ 如果代码涉及大型计算，或需要查询某些远程服务器上的数据库，应该怎么办？ 通常情况下，答案是处理大型操作在单独的线程，离开UI线程可以自由地倾向于中的项[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)队列。 大型操作完成后，它可以报告其结果返回到UI线程以进行显示。

从历史上看，Windows允许UI元素只能由创建它们的线程访问。 这意味着，负责长时间运行任务的后台线程无法在任务完成时更新文本框。 Windows 这样做是为了确保完整性UI组件。 如果在绘制过程中后台线程更新了列表框的内容，则此列表框看起来可能会很奇怪。

WPF 具有内置互相排斥机制，此机制能强制执行这种协调。 中的大多数类WPF派生自[DispatcherObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcherobject)。 在构建过程中[DispatcherObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcherobject)存储到的引用[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)链接到当前运行的线程。 实际上，[DispatcherObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcherobject)将与创建它的线程相关联。 在程序执行期间[DispatcherObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcherobject)可以调用它的公共[VerifyAccess](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcherobject.verifyaccess)方法。 [VerifyAccess](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcherobject.verifyaccess) 检查[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)与当前线程相关联并将其到比较[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)构造过程中存储的引用。 如果它们不匹配，[VerifyAccess](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcherobject.verifyaccess)将引发异常。 [VerifyAccess](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcherobject.verifyaccess) 应属于每个方法的开头调用[DispatcherObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcherobject)。

如果只有一个线程可以修改UI，如何执行后台线程与用户交互？ 后台线程可请求UI线程来执行代表其自身的操作。 这是通过注册与工作项[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)的UI线程。 [Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)类提供了两种方法来注册工作项：[Invoke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher.invoke)和[BeginInvoke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher.begininvoke)。 这两种方法都计划一个用于执行的委托。 [Invoke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher.invoke) 是一个同步调用 – 也就是说，它不会返回直到UI线程完成执行委托。 [BeginInvoke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher.begininvoke) 是异步的将立即返回。

[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)按优先级排列其队列中的元素。 有可能会添加到的元素时指定的十个级别[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)队列。 这些优先级均维护在[DispatcherPriority](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcherpriority)枚举。 有关详细信息[DispatcherPriority](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcherpriority)级别可在Windows SDK文档。



## 在操作中的线程：这些示例



### 具有长时间运行计算的单线程应用程序

大多数图形用户界面 (GUI)花费其时间处于空闲状态等待响应用户交互中生成的事件时有很大一部分。 通过精心编程此空闲时间可建设性地，而不会影响的响应能力UI。 WPF线程模型不允许输入中断中发生的操作UI线程。 这意味着您必须确保返回到[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)定期到挂起的输入事件在过时之前的进程。

请看下面的示例：

![质数屏幕快照](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/threadingprimenumberscreenshot.png)

这个简单的应用程序从 3 开始向上计数以搜索质数。 当用户单击**启动**按钮，开始执行搜索。 当程序查找到一个质数时，它将根据其发现内容更新用户界面。 用户可随时停止搜索。

尽管十分简单，但对质数的搜索可以永远持续下去，这会带来一些问题。 如果我们处理整个搜索按钮的单击事件处理程序，我们绝不会给UI线程有机会处理其他事件。 UI者将无法响应输入或进程消息。 它将永远不会重绘，也永远不会响应按钮单击。

可以在单独的线程中搜索质数，但这样的话，我们需要处理一些同步问题。 通过单线程方法，可以直接更新列出所找到的最大质数的标签。

如果我们分解成可管理块的计算的任务，我们可以定期返回到[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)和处理事件。 我们可以提供WPF机会重绘和处理输入。

划分计算和事件处理之间的处理时间的最佳方式是管理计算从[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)。 通过使用[BeginInvoke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher.begininvoke)方法中，我们可以计划质数检查中的同一队列UI来自事件。 在我们的示例中，一次仅计划一个质数检查。 完成质数检查后，立即计划下一个检查。 此检查才会继续后才挂起UI已处理事件。

![调度程序队列图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/threadingdispatcherqueue.png)

Microsoft Word 通过此机制完成拼写检查。 使用的空闲时间在后台执行了拼写检查UI线程。 我们来看一看代码。

下列示例显示了创建用户界面的 XAML。

XAML复制

```xaml
<Window x:Class="SDKSamples.Window1"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    Title="Prime Numbers" Width="260" Height="75"
    >
  <StackPanel Orientation="Horizontal" VerticalAlignment="Center" >
    <Button Content="Start"  
            Click="StartOrStop"
            Name="startStopButton"
            Margin="5,0,5,0"
            />
    <TextBlock Margin="10,5,0,0">Biggest Prime Found:</TextBlock>
    <TextBlock Name="bigPrime" Margin="4,5,0,0">3</TextBlock>
  </StackPanel>
</Window>
```

以下示例显示了代码隐藏。

C#复制

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Threading;
using System.Threading;

namespace SDKSamples
{
    public partial class Window1 : Window
    {
        public delegate void NextPrimeDelegate();
        
        //Current number to check 
        private long num = 3;   

        private bool continueCalculating = false;

        public Window1() : base()
        {
            InitializeComponent();
        }

        private void StartOrStop(object sender, EventArgs e)
        {
            if (continueCalculating)
            {
                continueCalculating = false;
                startStopButton.Content = "Resume";
            }
            else
            {
                continueCalculating = true;
                startStopButton.Content = "Stop";
                startStopButton.Dispatcher.BeginInvoke(
                    DispatcherPriority.Normal,
                    new NextPrimeDelegate(CheckNextNumber));
            }
        }

        public void CheckNextNumber()
        {
            // Reset flag.
            NotAPrime = false;

            for (long i = 3; i <= Math.Sqrt(num); i++)
            {
                if (num % i == 0)
                {
                    // Set not a prime flag to true.
                    NotAPrime = true;
                    break;
                }
            }

            // If a prime number.
            if (!NotAPrime)
            {
                bigPrime.Text = num.ToString();
            }

            num += 2;
            if (continueCalculating)
            {
                startStopButton.Dispatcher.BeginInvoke(
                    System.Windows.Threading.DispatcherPriority.SystemIdle, 
                    new NextPrimeDelegate(this.CheckNextNumber));
            }
        }
        
        private bool NotAPrime = false;
    }
}
```

下面的示例演示的事件处理程序[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)。

C#复制

```csharp
private void StartOrStop(object sender, EventArgs e)
{
    if (continueCalculating)
    {
        continueCalculating = false;
        startStopButton.Content = "Resume";
    }
    else
    {
        continueCalculating = true;
        startStopButton.Content = "Stop";
        startStopButton.Dispatcher.BeginInvoke(
            DispatcherPriority.Normal,
            new NextPrimeDelegate(CheckNextNumber));
    }
}
```

除了上更新的文本[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)，此处理程序负责通过添加委托，计划首个质数检查[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)队列。 此事件处理程序完成其工作后一段时间内[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)将选择执行此委托。

更早版本，我们提到[BeginInvoke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher.begininvoke)是[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)成员用于计划用于执行的委托。 在这种情况下，我们选择[SystemIdle](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcherpriority#System_Windows_Threading_DispatcherPriority_SystemIdle)优先级。 [Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)仅当没有要处理的重要事件时，会执行此委托。 UI 响应能力比数字检查更重要。我们还传递了一个表示数字检查例程的新委托。

C#复制

```csharp
public void CheckNextNumber()
{
    // Reset flag.
    NotAPrime = false;

    for (long i = 3; i <= Math.Sqrt(num); i++)
    {
        if (num % i == 0)
        {
            // Set not a prime flag to true.
            NotAPrime = true;
            break;
        }
    }

    // If a prime number.
    if (!NotAPrime)
    {
        bigPrime.Text = num.ToString();
    }

    num += 2;
    if (continueCalculating)
    {
        startStopButton.Dispatcher.BeginInvoke(
            System.Windows.Threading.DispatcherPriority.SystemIdle, 
            new NextPrimeDelegate(this.CheckNextNumber));
    }
}

private bool NotAPrime = false;
```

此方法检查下一个奇数是否是质数。 如果是质数，此方法将直接更新`bigPrime`[TextBlock](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock)以反映此发现。 可以如此操作的原因是，该计算发生在用于创建组件的相同线程中。 如果选择使用单独的线程进行计算，我们必须使用更复杂的同步机制，并执行在更新UI线程。 我们将在下一步中演示这种情况。

此示例的完整源代码，请参阅[单线程应用程序使用长时间运行计算示例](https://go.microsoft.com/fwlink/?LinkID=160038)



### 使用后台线程处理阻塞操作

在图形应用程序中处理阻塞操作可能很困难。 我们不希望从事件处理程序调用阻塞方法，因为应用程序可能看上去冻结。 我们可以使用单独的线程来处理这些操作，但操作完成后，我们必须将与同步UI线程因为我们不能直接修改GUI从工作线程。 我们可以使用[Invoke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher.invoke)或[BeginInvoke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher.begininvoke)要插入到委托[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)的UI线程。 最终，将以具有修改权限执行这些委托UI元素。

在本例中，我们模拟了一个检索天气预报的远程过程调用。 我们使用单独的工作线程来执行此调用，并且计划中的更新方法在调用[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)的UI线程完成时。

![天气 UI 屏幕快照](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/threadingweatheruiscreenshot.png)

C#复制

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using System.Windows.Threading;
using System.Threading;

namespace SDKSamples
{
    public partial class Window1 : Window
    {
        // Delegates to be used in placking jobs onto the Dispatcher.
        private delegate void NoArgDelegate();
        private delegate void OneArgDelegate(String arg);

        // Storyboards for the animations.
        private Storyboard showClockFaceStoryboard;
        private Storyboard hideClockFaceStoryboard;
        private Storyboard showWeatherImageStoryboard;
        private Storyboard hideWeatherImageStoryboard;

        public Window1(): base()
        {
            InitializeComponent();
        }  

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            // Load the storyboard resources.
            showClockFaceStoryboard = 
                (Storyboard)this.Resources["ShowClockFaceStoryboard"];
            hideClockFaceStoryboard = 
                (Storyboard)this.Resources["HideClockFaceStoryboard"];
            showWeatherImageStoryboard = 
                (Storyboard)this.Resources["ShowWeatherImageStoryboard"];
            hideWeatherImageStoryboard = 
                (Storyboard)this.Resources["HideWeatherImageStoryboard"];   
        }

        private void ForecastButtonHandler(object sender, RoutedEventArgs e)
        {
            // Change the status image and start the rotation animation.
            fetchButton.IsEnabled = false;
            fetchButton.Content = "Contacting Server";
            weatherText.Text = "";
            hideWeatherImageStoryboard.Begin(this);
            
            // Start fetching the weather forecast asynchronously.
            NoArgDelegate fetcher = new NoArgDelegate(
                this.FetchWeatherFromServer);

            fetcher.BeginInvoke(null, null);
        }

        private void FetchWeatherFromServer()
        {
            // Simulate the delay from network access.
            Thread.Sleep(4000);              
            
            // Tried and true method for weather forecasting - random numbers.
            Random rand = new Random();
            String weather;

            if (rand.Next(2) == 0)
            {
                weather = "rainy";
            }
            else
            {
                weather = "sunny";
            }

            // Schedule the update function in the UI thread.
            tomorrowsWeather.Dispatcher.BeginInvoke(
                System.Windows.Threading.DispatcherPriority.Normal,
                new OneArgDelegate(UpdateUserInterface), 
                weather);
        }

        private void UpdateUserInterface(String weather)
        {    
            //Set the weather image
            if (weather == "sunny")
            {       
                weatherIndicatorImage.Source = (ImageSource)this.Resources[
                    "SunnyImageSource"];
            }
            else if (weather == "rainy")
            {
                weatherIndicatorImage.Source = (ImageSource)this.Resources[
                    "RainingImageSource"];
            }

            //Stop clock animation
            showClockFaceStoryboard.Stop(this);
            hideClockFaceStoryboard.Begin(this);

            //Update UI text
            fetchButton.IsEnabled = true;
            fetchButton.Content = "Fetch Forecast";
            weatherText.Text = weather;     
        }

        private void HideClockFaceStoryboard_Completed(object sender,
            EventArgs args)
        {         
            showWeatherImageStoryboard.Begin(this);
        }
        
        private void HideWeatherImageStoryboard_Completed(object sender,
            EventArgs args)
        {           
            showClockFaceStoryboard.Begin(this, true);
        }        
    }
}
```

以下是一些需要注意的详细信息。

- 创建按钮处理程序

  C#复制

  ```csharp
  private void ForecastButtonHandler(object sender, RoutedEventArgs e)
  {
      // Change the status image and start the rotation animation.
      fetchButton.IsEnabled = false;
      fetchButton.Content = "Contacting Server";
      weatherText.Text = "";
      hideWeatherImageStoryboard.Begin(this);
      
      // Start fetching the weather forecast asynchronously.
      NoArgDelegate fetcher = new NoArgDelegate(
          this.FetchWeatherFromServer);
  
      fetcher.BeginInvoke(null, null);
  }
  ```

单击按钮时，会显示时钟绘图并开始对其进行动画处理。 禁用该按钮。 我们调用`FetchWeatherFromServer`中一个新线程，然后，我们的方法返回，从而允许[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)处理事件时我们等待收集天气预报。

- 获取天气

  C#复制

  ```csharp
  private void FetchWeatherFromServer()
  {
      // Simulate the delay from network access.
      Thread.Sleep(4000);              
      
      // Tried and true method for weather forecasting - random numbers.
      Random rand = new Random();
      String weather;
  
      if (rand.Next(2) == 0)
      {
          weather = "rainy";
      }
      else
      {
          weather = "sunny";
      }
  
      // Schedule the update function in the UI thread.
      tomorrowsWeather.Dispatcher.BeginInvoke(
          System.Windows.Threading.DispatcherPriority.Normal,
          new OneArgDelegate(UpdateUserInterface), 
          weather);
  }
  ```

为简便起见，本例中没有任何网络代码。 通过使新线程进入休眠状态四秒钟，模拟网络访问的延迟。 在此期间，原始UI线程仍在运行并对事件作出响应。 为了对此进行演示，我们让动画保持运行状态，最小化和最大化按钮也继续工作。

当延迟已完成，并且我们随机选择了天气预报时，就可以报告回时UI线程。 为此，计划调用我们`UpdateUserInterface`中UI线程使用该线程[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)。 将描述天气的字符串传递给此计划方法调用。

- 正在更新 UI

  C#复制

  ```csharp
  private void UpdateUserInterface(String weather)
  {    
      //Set the weather image
      if (weather == "sunny")
      {       
          weatherIndicatorImage.Source = (ImageSource)this.Resources[
              "SunnyImageSource"];
      }
      else if (weather == "rainy")
      {
          weatherIndicatorImage.Source = (ImageSource)this.Resources[
              "RainingImageSource"];
      }
  
      //Stop clock animation
      showClockFaceStoryboard.Stop(this);
      hideClockFaceStoryboard.Begin(this);
  
      //Update UI text
      fetchButton.IsEnabled = true;
      fetchButton.Content = "Fetch Forecast";
      weatherText.Text = weather;     
  }
  ```

当[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)中UI线程有时间时，它将执行计划的调用`UpdateUserInterface`。 此方法停止时钟动画，并选择一张映像用于描述天气。 它将显示此映像，并还原“获取预报”按钮。



### 多窗口、多线程

某些WPF应用程序需要多个顶层窗口。 它是完全可以接受一个线程 /[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)组合来管理多个时段，但有时多线程更好地。 尤其当这些窗口中的某一个将有可能要独占线程时，更是如此。

Windows 资源管理器以这种方式工作。 每个新资源管理器窗口都属于原始进程，但它是在独立线程的控件下创建的。

通过使用WPF[Frame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.frame)控件中，我们可以显示网页。 我们可以轻松地创建一个简单Internet Explorer替换。 让我们从一个重要功能开始：打开新资源管理器窗口的能力。 当用户单击“新建窗口”按钮时，我们将在单独的线程中启动窗口的副本。 这样一来，在其中一个窗口中的长时间运行或阻塞操作将不会锁定其他窗口。

在实际情况下，Web 浏览器模型自身拥有复杂的线程模型。 由于大多数读者都熟悉它，所以我们选择它。

以下示例显示了代码。

XAML复制

```xaml
<Window x:Class="SDKSamples.Window1"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    Title="MultiBrowse"
    Height="600" 
    Width="800"
    Loaded="OnLoaded"
    >
  <StackPanel Name="Stack" Orientation="Vertical">
    <StackPanel Orientation="Horizontal">
      <Button Content="New Window"
              Click="NewWindowHandler" />
      <TextBox Name="newLocation"
               Width="500" />
      <Button Content="GO!"
              Click="Browse" />
    </StackPanel>

    <Frame Name="placeHolder"
            Width="800"
            Height="550"></Frame>
  </StackPanel>
</Window>
```

C#复制

```csharp
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Threading;
using System.Threading;


namespace SDKSamples
{
    public partial class Window1 : Window
    {

        public Window1() : base()
        {
            InitializeComponent();
        }

        private void OnLoaded(object sender, RoutedEventArgs e)
        {
           placeHolder.Source = new Uri("http://www.msn.com");
        }

        private void Browse(object sender, RoutedEventArgs e)
        {
            placeHolder.Source = new Uri(newLocation.Text);
        }

        private void NewWindowHandler(object sender, RoutedEventArgs e)
        {       
            Thread newWindowThread = new Thread(new ThreadStart(ThreadStartingPoint));
            newWindowThread.SetApartmentState(ApartmentState.STA);
            newWindowThread.IsBackground = true;
            newWindowThread.Start();
        }

        private void ThreadStartingPoint()
        {
            Window1 tempWindow = new Window1();
            tempWindow.Show();       
            System.Windows.Threading.Dispatcher.Run();
        }
    }
}
```

此代码中的以下线程段对我们来说是最有趣的：

C#复制

```csharp
private void NewWindowHandler(object sender, RoutedEventArgs e)
{       
    Thread newWindowThread = new Thread(new ThreadStart(ThreadStartingPoint));
    newWindowThread.SetApartmentState(ApartmentState.STA);
    newWindowThread.IsBackground = true;
    newWindowThread.Start();
}
```

当单击“新建窗口”按钮时，将调用该方法。 它创建了一个新线程，并以异步方式启动。

C#复制

```csharp
private void ThreadStartingPoint()
{
    Window1 tempWindow = new Window1();
    tempWindow.Show();       
    System.Windows.Threading.Dispatcher.Run();
}
```

此方法是新线程的起点。 我们在此线程的控件下创建了一个新窗口。 WPF 自动创建一个新[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)来管理新线程。 我们所要执行的操作使窗口功能是启动[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)。



## 技术详细信息和疑难点

### 使用线程处理编写组件

Microsoft.NET Framework 开发人员指南介绍了如何一个组件可以公开给其客户端的异步行为的模式 (请参阅[基于事件的异步模式概述](https://docs.microsoft.com/zh-cn/dotnet/standard/asynchronous-programming-patterns/event-based-asynchronous-pattern-overview))。 例如，假设我们想要打包`FetchWeatherFromServer`到可重用的非图形组件的方法。 遵循标准的 Microsoft.NET Framework 模式，它看起来应如下所示。

C#复制

```csharp
public class WeatherComponent : Component
{
    //gets weather: Synchronous 
    public string GetWeather()
    {
        string weather = "";

        //predict the weather

        return weather;
    }

    //get weather: Asynchronous 
    public void GetWeatherAsync()
    {
        //get the weather
    }

    public event GetWeatherCompletedEventHandler GetWeatherCompleted;
}

public class GetWeatherCompletedEventArgs : AsyncCompletedEventArgs
{
    public GetWeatherCompletedEventArgs(Exception error, bool canceled,
        object userState, string weather)
        :
        base(error, canceled, userState)
    {
        _weather = weather;
    }

    public string Weather
    {
        get { return _weather; }
    }
    private string _weather;
}

public delegate void GetWeatherCompletedEventHandler(object sender,
    GetWeatherCompletedEventArgs e);
```

`GetWeatherAsync` 将使用上述的技术之一（如创建后台线程）来以异步方式工作，而非阻止调用线程。

此模式的最重要的部分之一调用*MethodName* `Completed`方法调用的同一线程上*MethodName* `Async`方法开头。无法执行此操作使用WPF相当轻松地通过将存储[CurrentDispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher.currentdispatcher)— 但然后非图形组件可能只能用在WPF应用程序，不在Windows 窗体或ASP.NET程序。

[DispatcherSynchronizationContext](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatchersynchronizationcontext)类解决了上述需要，将其视为的简化版本[Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)的工作方式与其他UI框架的积极。

C#复制

```csharp
public class WeatherComponent2 : Component
{
    public string GetWeather()
    {
        return fetchWeatherFromServer();
    }

    private DispatcherSynchronizationContext requestingContext = null;

    public void GetWeatherAsync()
    {
        if (requestingContext != null)
            throw new InvalidOperationException("This component can only handle 1 async request at a time");

        requestingContext = (DispatcherSynchronizationContext)DispatcherSynchronizationContext.Current;

        NoArgDelegate fetcher = new NoArgDelegate(this.fetchWeatherFromServer);

        // Launch thread
        fetcher.BeginInvoke(null, null);
    }

    private void RaiseEvent(GetWeatherCompletedEventArgs e)
    {
        if (GetWeatherCompleted != null)
            GetWeatherCompleted(this, e);
    }

    private string fetchWeatherFromServer()
    {
        // do stuff
        string weather = "";

        GetWeatherCompletedEventArgs e =
            new GetWeatherCompletedEventArgs(null, false, null, weather);

        SendOrPostCallback callback = new SendOrPostCallback(DoEvent);
        requestingContext.Post(callback, e);
        requestingContext = null;

        return e.Weather;
    }

    private void DoEvent(object e)
    {
        //do stuff
    }

    public event GetWeatherCompletedEventHandler GetWeatherCompleted;
    public delegate string NoArgDelegate();
}
```

### 嵌套泵

有时不可行完全锁定UI线程。 让我们考虑[Show](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.messagebox.show)方法的[MessageBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.messagebox)类。 [Show](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.messagebox.show) 不会返回，直到用户单击确定按钮。 但是，它却会创建一个窗口，该窗口为了获得交互性而必须具有消息循环。 在等待用户单击“确定”时，原始应用程序窗口将不会响应用户的输入。 但是，它将继续处理绘制消息。 当被覆盖和被显示时，原始窗口将重绘其本身。

![具有“确定”按钮的消息框](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/threadingnestedpumping.png)

一些线程必须负责消息框窗口。 WPF 可以为消息框窗口创建新线程，但此线程无法在原始窗口中绘制禁用的元素（请回忆之前所讨论的互相排斥）。 相反，WPF使用嵌套的消息处理系统。 [Dispatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher)类包含一个名为的特殊方法[PushFrame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher.pushframe)，用于存储应用程序的当前执行点然后开始新的消息循环。 当嵌套的消息循环完成后时，原始后恢复执行[PushFrame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher.pushframe)调用。

在这种情况下，[PushFrame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher.pushframe)维护到调用程序上下文[MessageBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.messagebox)。[Show](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.messagebox.show)，并启动新的消息循环重绘后台窗口和处理消息框窗口的输入。 当用户单击确定，并清除弹出窗口中时，嵌套的循环退出，并在调用后继续控制[Show](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.messagebox.show)。

### 过时的路由事件

中的路由的事件系统WPF会引发事件时通知整个树。

XAML复制

```xaml
<Canvas MouseLeftButtonDown="handler1" 
        Width="100"
        Height="100"
        >
  <Ellipse Width="50"
           Height="50"
           Fill="Blue" 
           Canvas.Left="30"
           Canvas.Top="50" 
           MouseLeftButtonDown="handler2"
           />
</Canvas>
```

在椭圆上按下鼠标左键时`handler2`执行。 之后`handler2`完成之后，事件将传递到[Canvas](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.canvas)对象，后者使用`handler1`若要对其进行处理。 仅当发生这种情况`handler2`没有显式标记事件对象为已处理。

可能的`handler2`将需要很长的时间来处理此事件。 `handler2` 可以使用[PushFrame](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher.pushframe)开始小时内不会返回一个嵌套的消息循环。 如果`handler2`不的标记该事件为已处理此消息循环时完成，则树向上传递事件，即使它是非常陈旧。

### 重新进入和锁定

锁定机制公共语言运行时 (CLR)不完全相同的行为可能想象一个; 可能有人以为将完全停止操作，请求锁定时的线程。 实际上，该线程将继续接收和处理高优先级的消息。 这样有助于防止死锁，并使接口最低限度地响应，但这样做有可能引入细微 bug。 大多数情况下无需知道任何有关此操作，但在极少数情况下 (通常涉及Win32窗口消息或 COM STA 组件) 这可能是值得。

大多数接口不构建记住的线程安全，因为开发人员在假设的UI永远不会由多个线程访问。 在此情况下，单个线程可能会使在意外情况的环境更改可导致这些错误影响的[DispatcherObject](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcherobject)应该互相排斥机制来解决。 请看下面的伪代码：

![线程处理重入示意图](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/media/threadingreentrancy.png)

大多数情况下，这是正确的事情，但有时候，在WPF其中此类异常的重入确实会造成问题。 这样，在某些关键时刻WPF调用[DisableProcessing](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher.disableprocessing)，这将更改为使用该线程的锁定指令WPF无重入锁，而非常规CLR锁。

那么，为什么未CLR团队选择这种行为？ 它与 COM STA 对象和完成线程有关。 当一个对象进行垃圾回收，其`Finalize`方法不运行，在专用终结器线程上UI线程。 其中问题出在这里，因为 COM STA 对象，其上创建UI线程仅在释放上UI线程。 CLR相当于[BeginInvoke](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.threading.dispatcher.begininvoke)(在这种情况下使用 Win32 的`SendMessage`)。 但是，如果UI线程正忙，终结器线程被停止，COM STA 对象无法被释放，这种结构造成严重的内存泄漏。 因此CLR团队通过严格的调用，使锁定的工作方式以它们执行操作。

有关任务WPF是为了避免意外重新进入而无需重新引入内存泄露，这正是我们不会阻止无处不在可重入性。