# [ScrollBar](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/scrollbar)

A [ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar) ，您可以查看通过滑动是当前查看区之外的内容[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)使可见的内容。

## [Customize the Thumb Size on a ScrollBar](https://docs.microsoft.com/en-us/dotnet/framework/wpf/controls/how-to-customize-the-thumb-size-on-a-scrollbar)

本主题介绍如何设置[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)的[ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar)固定的大小以及如何指定的最小大小[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)的[ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar)。

### 示例

下面的示例创建[ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar)具有[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)具有固定大小。 该示例设置[ViewportSize](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.track.viewportsize)的属性[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)到[NaN](https://docs.microsoft.com/zh-cn/dotnet/api/system.double.nan)设置的高度和[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)。 若要创建水平[ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar)与[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)具有固定的宽度，则设置的宽度[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)。

```xaml
<Style TargetType="ScrollBar">
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="ScrollBar">
        <Grid Name="Bg"
              Background="{TemplateBinding Background}"
              SnapsToDevicePixels="true">
          <Grid.RowDefinitions>
            <RowDefinition MaxHeight="{DynamicResource 
            {x:Static SystemParameters.VerticalScrollBarButtonHeightKey}}"/>
            <RowDefinition Height="0.00001*"/>
            <RowDefinition MaxHeight="{DynamicResource 
            {x:Static SystemParameters.VerticalScrollBarButtonHeightKey}}"/>
          </Grid.RowDefinitions>
          <RepeatButton Style="{StaticResource ScrollBarButton}"
                        IsEnabled="{TemplateBinding IsMouseOver}"
                        Height="18"
                      
                        Command="ScrollBar.LineUpCommand"
                        Content="M 0 4 L 8 4 L 4 0 Z" />
          <!-- Set the ViewporSize to NaN to disable autosizing of the Thumb. -->
          <Track Name="PART_Track" 
                 ViewportSize="NaN"
                 IsDirectionReversed="true"
                 Grid.Row="1"
                 Grid.ZIndex="-1">
            <Track.DecreaseRepeatButton>
              <RepeatButton Style="{StaticResource VerticalScrollBarPageButton}"
                            Command="ScrollBar.PageUpCommand"/>
            </Track.DecreaseRepeatButton>
            <Track.IncreaseRepeatButton>
              <RepeatButton Style="{StaticResource VerticalScrollBarPageButton}"
                            Command="ScrollBar.PageDownCommand"/>
            </Track.IncreaseRepeatButton>
            <Track.Thumb>
              <!-- Set the height of the Thumb.-->
              <Thumb Height="30"/>
            </Track.Thumb>
          </Track>
          <RepeatButton 
            Grid.Row="2" 
            Style="{StaticResource ScrollBarButton}"
            Height="18"
            Command="ScrollBar.LineDownCommand"
            Content="M 0 0 L 4 4 L 8 0 Z"/>

        </Grid>
        <ControlTemplate.Triggers>
          <Trigger SourceName="PART_Track" Property="IsEnabled" Value="false">
            <Setter TargetName="PART_Track" Property="Visibility" Value="Hidden"/>
          </Trigger>
        </ControlTemplate.Triggers>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```

下面的示例创建[ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar)具有[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)与最小大小。 该示例设置的值[VerticalScrollBarButtonHeightKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemparameters.verticalscrollbarbuttonheightkey)。 若要创建水平[ScrollBar](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.scrollbar)与[Thumb](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.controls.primitives.thumb)的最小宽度，设置[HorizontalScrollBarButtonWidthKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.systemparameters.horizontalscrollbarbuttonwidthkey)。

```xaml
<Style TargetType="ScrollBar">
  <Setter Property="Template">
    <Setter.Value>
      <ControlTemplate TargetType="ScrollBar">
        <Grid Name="Bg"
              Background="{TemplateBinding Background}"
              SnapsToDevicePixels="true">
          <Grid.RowDefinitions>
            <RowDefinition MaxHeight="{DynamicResource 
            {x:Static SystemParameters.VerticalScrollBarButtonHeightKey}}"/>
            <RowDefinition Height="0.00001*"/>
            <RowDefinition MaxHeight="{DynamicResource 
            {x:Static SystemParameters.VerticalScrollBarButtonHeightKey}}"/>
          </Grid.RowDefinitions>
          <RepeatButton Style="{StaticResource ScrollBarButton}"
                        IsEnabled="{TemplateBinding IsMouseOver}"
                        Height="18"
                        Command="ScrollBar.LineUpCommand"
                        Content="M 0 4 L 8 4 L 4 0 Z" />
          <Track Name="PART_Track" 
               IsDirectionReversed="true"
               Grid.Row="1"
               Grid.ZIndex="-1">
            <Track.Resources>
              <!-- Set the Thumb's minimum height to 50.
            The Thumb's minimum height is half the
            value of VerticalScrollBarButtonHeightKey. -->
              <sys:Double 
                x:Key="{x:Static SystemParameters.VerticalScrollBarButtonHeightKey}">
                100
              </sys:Double>
            </Track.Resources>
            <Track.DecreaseRepeatButton>
              <RepeatButton Style="{StaticResource VerticalScrollBarPageButton}"
                            Command="ScrollBar.PageUpCommand"/>
            </Track.DecreaseRepeatButton>
            <Track.IncreaseRepeatButton>
              <RepeatButton Style="{StaticResource VerticalScrollBarPageButton}"
                            Command="ScrollBar.PageDownCommand"/>
            </Track.IncreaseRepeatButton>
            <Track.Thumb>
              <Thumb/>
            </Track.Thumb>
          </Track>
          <RepeatButton 
            Grid.Row="2" 
            Style="{StaticResource ScrollBarButton}"
            Height="18"
            Command="ScrollBar.LineDownCommand"
            Content="M 0 0 L 4 4 L 8 0 Z"/>
        </Grid>
        <ControlTemplate.Triggers>
          <Trigger SourceName="PART_Track" 
                   Property="IsEnabled" Value="false">
            <Setter TargetName="PART_Track" 
                    Property="Visibility" Value="Hidden"/>
          </Trigger>
        </ControlTemplate.Triggers>
      </ControlTemplate>
    </Setter.Value>
  </Setter>
</Style>
```