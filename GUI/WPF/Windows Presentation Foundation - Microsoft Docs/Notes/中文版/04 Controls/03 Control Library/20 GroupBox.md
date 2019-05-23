## [GroupBox](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/groupbox)

[GroupBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.groupbox)控件是[HeaderedContentControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headeredcontentcontrol)提供名为的容器图形用户界面 (GUI)内容。

下图显示[GroupBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.groupbox)包含[TabControl](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.tabcontrol)和[Button](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button)括在[StackPanel](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.stackpanel)。

![GroupBoxImage](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/media/groupboximage.jpg)

### 本节内容

[定义 GroupBox 模板](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/controls/how-to-define-a-groupbox-template)

### [Define a GroupBox Template](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-define-a-groupbox-template)

此示例演示如何创建模板[GroupBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.groupbox)控件。

##### 示例

下面的示例定义[GroupBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.groupbox)通过使用控件模板[Grid](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.grid)布局的控制。 该模板使用[BorderGapMaskConverter](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.bordergapmaskconverter)定义的边框[GroupBox](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.groupbox)以便边框不会遮盖[Header](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.headeredcontentcontrol.header)内容。

```xaml
<!--=================================================================
    GroupBox Template Example
==================================================================-->
<BorderGapMaskConverter x:Key="BorderGapMaskConverter"/>
<Style x:Key="{x:Type GroupBox}"
       TargetType="{x:Type GroupBox}">
  <Setter Property="BorderBrush"
          Value="Gray"/>
  <Setter Property="Foreground"
          Value="White"/>
  <Setter Property="BorderThickness"
          Value="1"/>
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="{x:Type GroupBox}">
        <Grid>
          <Grid.ColumnDefinitions>
            <ColumnDefinition Width="4"/>
            <ColumnDefinition Width="Auto"/>
            <ColumnDefinition Width="*"/>
            <ColumnDefinition Width="4"/>
          </Grid.ColumnDefinitions>
          <Grid.RowDefinitions>
            <RowDefinition Height="Auto"/>
            <RowDefinition Height="Auto"/>
            <RowDefinition Height="*"/>
            <RowDefinition Height="4"/>
          </Grid.RowDefinitions>
          <Border CornerRadius="4"
                  Grid.Row="1"
                  Grid.RowSpan="3"
                  Grid.Column="0"
                  Grid.ColumnSpan="4"
                  BorderThickness="{TemplateBinding BorderThickness}"
                  BorderBrush="Transparent"
                  Background="{TemplateBinding Background}"/>
          <!-- ContentPresenter for the header -->
          <Border x:Name="Header"
                  Padding="6,0,6,0"
                  Grid.Row="0"
                  Grid.RowSpan="2"
                  Grid.Column="1">
            <ContentPresenter ContentSource="Header" 
                              RecognizesAccessKey="True" />
          </Border>
          <!-- Primary content for GroupBox -->
          <ContentPresenter Grid.Row="2"
                            Grid.Column="1"
                            Grid.ColumnSpan="2"
                            Margin="{TemplateBinding Padding}"/>
          <Border CornerRadius="0"
                  Grid.Row="1"
                  Grid.RowSpan="3"
                  Grid.ColumnSpan="4"
                  BorderThickness="{TemplateBinding BorderThickness}"
                  BorderBrush="{TemplateBinding BorderBrush}">
            <Border.OpacityMask>
              <MultiBinding Converter=
                            "{StaticResource BorderGapMaskConverter}"
                            ConverterParameter="6">
                <Binding ElementName="Header"
                         Path="ActualWidth"/>
                <Binding RelativeSource="{RelativeSource Self}"
                         Path="ActualWidth"/>
                <Binding RelativeSource="{RelativeSource Self}"
                         Path="ActualHeight"/>
              </MultiBinding>
            </Border.OpacityMask>
          </Border>
        </Grid>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```