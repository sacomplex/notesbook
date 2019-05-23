# [File System and the Registry](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/file-system/)

下面各主题介绍了如何使用 C# 和 .NET Framework 对文件、文件夹和注册表执行各种基本操作。

## 本节内容

| **标题**                                                     | **说明**                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [如何：循环访问目录树](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/file-system/how-to-iterate-through-a-directory-tree) | 介绍了如何手动循环访问目录树。                               |
| [如何：获取文件、文件夹和驱动器的相关信息](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/file-system/how-to-get-information-about-files-folders-and-drives) | 介绍了如何检索有关文件、文件夹和驱动器的信息，如创建时间和大小。 |
| [如何：创建文件或文件夹](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/file-system/how-to-create-a-file-or-folder) | 介绍了如何新建文件或文件夹。                                 |
| [如何：复制、删除和移动文件和文件夹（C# 编程指南）](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/file-system/how-to-copy-delete-and-move-files-and-folders) | 介绍了如何复制、删除、移动文件和文件夹。                     |
| [如何：提供文件操作进度对话框](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/file-system/how-to-provide-a-progress-dialog-box-for-file-operations) | 介绍了如何显示特定文件操作的标准 Windows 进度对话框。        |
| [如何：写入到文本文件](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/file-system/how-to-write-to-a-text-file) | 介绍了如何将内容写入文本文件。                               |
| [如何：从文本文件读取](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/file-system/how-to-read-from-a-text-file) | 介绍了如何读取文本文件中的内容。                             |
| [如何：一次一行地读取文本文件](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/file-system/how-to-read-a-text-file-one-line-at-a-time) | 介绍了如何一次一行地检索文件文本。                           |
| [如何：在注册表中创建注册表项](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/file-system/how-to-create-a-key-in-the-registry) | 介绍了如何将注册表项写入系统注册表。                         |

## [How to: Iterate Through a Directory Tree](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/file-system/how-to-iterate-through-a-directory-tree)

短语“循环访问目录树”的意思是访问特定根文件夹下的每个嵌套子目录中的每个文件，可以是任意深度。 不需要打开每个文件。 可以以 `string` 的形式只检索文件或子目录的名称，也可以以 [System.IO.FileInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.fileinfo) 或[System.IO.DirectoryInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.directoryinfo) 对象的形式检索其他信息。

> 在 Windows 中，术语“目录”和“文件夹”可以互换使用。 大多数文档和用户界面文本使用术语“文件夹”，但.NET Framework 类库使用术语“目录”。

在最简单的情况下，如果你确信拥有指定根目录下的所有目录的访问权限，则可以使用 `System.IO.SearchOption.AllDirectories` 标志。 此标志返回与指定的模式匹配的所有嵌套的子目录。 下面的示例演示如何使用此标志。

```csharp
root.GetDirectories("*.*", System.IO.SearchOption.AllDirectories);  
```

此方法的缺点是，如果指定根目录下的任何子目录引发 [DirectoryNotFoundException](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.directorynotfoundexception) 或[UnauthorizedAccessException](https://docs.microsoft.com/zh-cn/dotnet/api/system.unauthorizedaccessexception) 异常，则整个方法失败且不返回任何目录。 使用 [GetFiles](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.directoryinfo.getfiles) 方法时也是如此。 如果需要处理特定子文件夹中的异常，则必须手动遍历目录树，如以下示例所示。

手动遍历目录树时，可以先处理子目录（前序遍历），或者先处理文件（后序遍历）。 如果执行前序遍历，那么在遍历直接位于当前文件夹中的文件之前，先遍历此文件夹下的整棵树。 本文档后面的示例执行的是后序遍历，但你可以轻松地修改它们以执行前序遍历。

另一种选择是，是使用递归遍历还是基于堆栈的遍历。 本文档后面的示例演示了这两种方法。

如果需要对文件和文件夹执行各种操作，则可以模块化这些示例，方法是将操作重构为可使用单个委托进行调用的单独的函数。

> NTFS 文件系统可以包含交接点、符号链接和硬链接等形式的重解析点。 诸如 [GetFiles](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.directoryinfo.getfiles) 和 [GetDirectories](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.directoryinfo.getdirectories) 的 .NET Framework 方法不会返回重分析点下的任何子目录。 当两个重解析点相互引用时，此行为可防止进入无限循环。 通常，处理重解析点时应格外小心，以确保不会无意中修改或删除文件。 如果需要精确控制重解析点，请使用平台调用或本机代码直接调用相应的 Win32 文件系统方法。

### 示例

下面的示例演示如何以递归方式遍历目录树。 递归方法是一种很好的方法，但是如果目录树较大且嵌套深度较深，则可能引起堆栈溢出异常。

在每个文件或文件夹上处理的特定异常和执行的特定操作仅作为示例提供。 你可以修改此代码来满足你的特定要求。 有关详细信息，请参阅代码中的注释。

```csharp
public class RecursiveFileSearch
{
    static System.Collections.Specialized.StringCollection log = new System.Collections.Specialized.StringCollection();

    static void Main()
    {
        // Start with drives if you have to search the entire computer.
        string[] drives = System.Environment.GetLogicalDrives();

        foreach (string dr in drives)
        {
            System.IO.DriveInfo di = new System.IO.DriveInfo(dr);

            // Here we skip the drive if it is not ready to be read. This
            // is not necessarily the appropriate action in all scenarios.
            if (!di.IsReady)
            {
                Console.WriteLine("The drive {0} could not be read", di.Name);
                continue;
            }
            System.IO.DirectoryInfo rootDir = di.RootDirectory;
            WalkDirectoryTree(rootDir);
        }

        // Write out all the files that could not be processed.
        Console.WriteLine("Files with restricted access:");
        foreach (string s in log)
        {
            Console.WriteLine(s);
        }
        // Keep the console window open in debug mode.
        Console.WriteLine("Press any key");
        Console.ReadKey();
    }

    static void WalkDirectoryTree(System.IO.DirectoryInfo root)
    {
        System.IO.FileInfo[] files = null;
        System.IO.DirectoryInfo[] subDirs = null;

        // First, process all the files directly under this folder
        try
        {
            files = root.GetFiles("*.*");
        }
        // This is thrown if even one of the files requires permissions greater
        // than the application provides.
        catch (UnauthorizedAccessException e)
        {
            // This code just writes out the message and continues to recurse.
            // You may decide to do something different here. For example, you
            // can try to elevate your privileges and access the file again.
            log.Add(e.Message);
        }

        catch (System.IO.DirectoryNotFoundException e)
        {
            Console.WriteLine(e.Message);
        }
        
        if (files != null)
        {
            foreach (System.IO.FileInfo fi in files)
            {
                // In this example, we only access the existing FileInfo object. If we
                // want to open, delete or modify the file, then
                // a try-catch block is required here to handle the case
                // where the file has been deleted since the call to TraverseTree().
                Console.WriteLine(fi.FullName);
            }

            // Now find all the subdirectories under this directory.
            subDirs = root.GetDirectories();

            foreach (System.IO.DirectoryInfo dirInfo in subDirs)
            {
                // Resursive call for each subdirectory.
                WalkDirectoryTree(dirInfo);
            }
        }            
    }
}
```

### 示例

下面的示例演示如何不使用递归方式遍历目录树中的文件和文件夹。 此方法使用泛型 [Stack](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.stack-1) 集合类型，此集合类型是一个后进先出 (LIFO) 堆栈。

在每个文件或文件夹上处理的特定异常和执行的特定操作仅作为示例提供。 你可以修改此代码来满足你的特定要求。 有关详细信息，请参阅代码中的注释。

```csharp
public class StackBasedIteration
{
    static void Main(string[] args)
    {
        // Specify the starting folder on the command line, or in 
        // Visual Studio in the Project > Properties > Debug pane.
        TraverseTree(args[0]);

        Console.WriteLine("Press any key");
        Console.ReadKey();
    }

    public static void TraverseTree(string root)
    {
        // Data structure to hold names of subfolders to be
        // examined for files.
        Stack<string> dirs = new Stack<string>(20);

        if (!System.IO.Directory.Exists(root))
        {
            throw new ArgumentException();
        }
        dirs.Push(root);

        while (dirs.Count > 0)
        {
            string currentDir = dirs.Pop();
            string[] subDirs;
            try
            {
                subDirs = System.IO.Directory.GetDirectories(currentDir);
            }
            // An UnauthorizedAccessException exception will be thrown if we do not have
            // discovery permission on a folder or file. It may or may not be acceptable 
            // to ignore the exception and continue enumerating the remaining files and 
            // folders. It is also possible (but unlikely) that a DirectoryNotFound exception 
            // will be raised. This will happen if currentDir has been deleted by
            // another application or thread after our call to Directory.Exists. The 
            // choice of which exceptions to catch depends entirely on the specific task 
            // you are intending to perform and also on how much you know with certainty 
            // about the systems on which this code will run.
            catch (UnauthorizedAccessException e)
            {                    
                Console.WriteLine(e.Message);
                continue;
            }
            catch (System.IO.DirectoryNotFoundException e)
            {
                Console.WriteLine(e.Message);
                continue;
            }

            string[] files = null;
            try
            {
                files = System.IO.Directory.GetFiles(currentDir);
            }

            catch (UnauthorizedAccessException e)
            {
                
                Console.WriteLine(e.Message);
                continue;
            }

            catch (System.IO.DirectoryNotFoundException e)
            {
                Console.WriteLine(e.Message);
                continue;
            }
            // Perform the required action on each file here.
            // Modify this block to perform your required task.
            foreach (string file in files)
            {
                try
                {
                    // Perform whatever action is required in your scenario.
                    System.IO.FileInfo fi = new System.IO.FileInfo(file);
                    Console.WriteLine("{0}: {1}, {2}", fi.Name, fi.Length, fi.CreationTime);
                }
                catch (System.IO.FileNotFoundException e)
                {
                    // If file was deleted by a separate application
                    //  or thread since the call to TraverseTree()
                    // then just continue.
                    Console.WriteLine(e.Message);
                    continue;
                }
            }

            // Push the subdirectories onto the stack for traversal.
            // This could also be done before handing the files.
            foreach (string str in subDirs)
                dirs.Push(str);
        }
    }
}
```

通常，检测每个文件夹以确定应用程序是否有权限打开它是一个很费时的过程。 因此，此代码示例只将此部分操作封装在 `try/catch` 块中。 你可以修改 `catch` 块，以便在拒绝访问某个文件夹时，可以尝试提升权限，然后再次访问此文件夹。 一般来说，仅捕获可以处理的、不会将应用程序置于未知状态的异常。

如果必须在内存或磁盘上存储目录树的内容，那么最佳选择是仅存储每个文件的 [FullName](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.filesysteminfo.fullname) 属性（类型为 `string`）。 然后可以根据需要使用此字符串创建新的 [FileInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.fileinfo) 或 [DirectoryInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.directoryinfo) 对象，或打开需要进行其他处理的任何文件。

### 可靠编程

可靠的文件迭代代码必须考虑文件系统的诸多复杂性。 有关 Windows 文件系统的详细信息，请参阅 [NTFS 概述](https://docs.microsoft.com/zh-cn/windows-server/storage/file-server/ntfs-overview)。

## [How to: Get Information About Files, Folders, and Drives](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/file-system/how-to-get-information-about-files-folders-and-drives)

在 .NET Framework 中，可以使用以下类访问文件系统信息：

- [System.IO.FileInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.fileinfo)
- [System.IO.DirectoryInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.directoryinfo)
- [System.IO.DriveInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.driveinfo)
- [System.IO.Directory](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.directory)
- [System.IO.File](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.file)

[FileInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.fileinfo) 和 [DirectoryInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.directoryinfo) 类表示文件或目录，并包含用于公开 NTFS 文件系统所支持的许多文件特性的属性。 它们还包含用于打开、关闭、移动和删除文件和文件夹的方法。 可以通过将表示文件、文件夹或驱动器名称的字符串传入构造函数来创建这些类的实例：

```csharp
System.IO.DriveInfo di = new System.IO.DriveInfo(@"C:\");  
```

还可以使用对 [DirectoryInfo.GetDirectories](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.directoryinfo.getdirectories)[DirectoryInfo.GetFiles](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.directoryinfo.getfiles) 和 [DriveInfo.RootDirectory](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.driveinfo.rootdirectory) 的调用来获取文件、文件夹或驱动器的名称。

[System.IO.Directory](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.directory) 和 [System.IO.File](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.file) 类提供相关静态方法，用于检索有关目录和文件的信息。

### 示例

下面的示例演示用于访问有关文件和文件夹的信息的各种方法。

```csharp
class FileSysInfo
{
    static void Main()
    {
        // You can also use System.Environment.GetLogicalDrives to
        // obtain names of all logical drives on the computer.
        System.IO.DriveInfo di = new System.IO.DriveInfo(@"C:\");
        Console.WriteLine(di.TotalFreeSpace);
        Console.WriteLine(di.VolumeLabel);

        // Get the root directory and print out some information about it.
        System.IO.DirectoryInfo dirInfo = di.RootDirectory;
        Console.WriteLine(dirInfo.Attributes.ToString());

        // Get the files in the directory and print out some information about them.
        System.IO.FileInfo[] fileNames = dirInfo.GetFiles("*.*");


        foreach (System.IO.FileInfo fi in fileNames)
        {
            Console.WriteLine("{0}: {1}: {2}", fi.Name, fi.LastAccessTime, fi.Length);
        }

        // Get the subdirectories directly that is under the root.
        // See "How to: Iterate Through a Directory Tree" for an example of how to
        // iterate through an entire tree.
        System.IO.DirectoryInfo[] dirInfos = dirInfo.GetDirectories("*.*");

        foreach (System.IO.DirectoryInfo d in dirInfos)
        {
            Console.WriteLine(d.Name);
        }

        // The Directory and File classes provide several static methods
        // for accessing files and directories.

        // Get the current application directory.
        string currentDirName = System.IO.Directory.GetCurrentDirectory();
        Console.WriteLine(currentDirName);           

        // Get an array of file names as strings rather than FileInfo objects.
        // Use this method when storage space is an issue, and when you might
        // hold on to the file name reference for a while before you try to access
        // the file.
        string[] files = System.IO.Directory.GetFiles(currentDirName, "*.txt");

        foreach (string s in files)
        {
            // Create the FileInfo object only when needed to ensure
            // the information is as current as possible.
            System.IO.FileInfo fi = null;
            try
            {
                 fi = new System.IO.FileInfo(s);
            }
            catch (System.IO.FileNotFoundException e)
            {
                // To inform the user and continue is
                // sufficient for this demonstration.
                // Your application may require different behavior.
                Console.WriteLine(e.Message);
                continue;
            }
            Console.WriteLine("{0} : {1}",fi.Name, fi.Directory);
        }

        // Change the directory. In this case, first check to see
        // whether it already exists, and create it if it does not.
        // If this is not appropriate for your application, you can
        // handle the System.IO.IOException that will be raised if the
        // directory cannot be found.
        if (!System.IO.Directory.Exists(@"C:\Users\Public\TestFolder\"))
        {
            System.IO.Directory.CreateDirectory(@"C:\Users\Public\TestFolder\");
        }

        System.IO.Directory.SetCurrentDirectory(@"C:\Users\Public\TestFolder\");

        currentDirName = System.IO.Directory.GetCurrentDirectory();
        Console.WriteLine(currentDirName);

        // Keep the console window open in debug mode.
        Console.WriteLine("Press any key to exit.");
        Console.ReadKey();
    }
}
```

### 可靠编程

处理用户指定的路径字符串时，还应针对以下情况处理异常：

- 文件名格式不正确。 例如，它包含无效字符或只包含空格。
- 文件名为 null。
- 文件名超过系统定义的最大长度。
- 文件名包含冒号 (:)。

如果应用程序没有足够权限来读取指定文件，`Exists` 方法会返回 `false`（无论路径是否存在）；该方法不会引发异常。

## [How to: Create a File or Folder](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/file-system/how-to-create-a-file-or-folder)

可通过编程方式在计算机上创建文件夹、子文件夹和子文件夹中的文件，并将数据写入文件。

### 示例

```csharp
public class CreateFileOrFolder
{
    static void Main()
    {
        // Specify a name for your top-level folder.
        string folderName = @"c:\Top-Level Folder";

        // To create a string that specifies the path to a subfolder under your 
        // top-level folder, add a name for the subfolder to folderName.
        string pathString = System.IO.Path.Combine(folderName, "SubFolder");

        // You can write out the path name directly instead of using the Combine
        // method. Combine just makes the process easier.
        string pathString2 = @"c:\Top-Level Folder\SubFolder2";

        // You can extend the depth of your path if you want to.
        //pathString = System.IO.Path.Combine(pathString, "SubSubFolder");

        // Create the subfolder. You can verify in File Explorer that you have this
        // structure in the C: drive.
        //    Local Disk (C:)
        //        Top-Level Folder
        //            SubFolder
        System.IO.Directory.CreateDirectory(pathString);

        // Create a file name for the file you want to create. 
        string fileName = System.IO.Path.GetRandomFileName();

        // This example uses a random string for the name, but you also can specify
        // a particular name.
        //string fileName = "MyNewFile.txt";

        // Use Combine again to add the file name to the path.
        pathString = System.IO.Path.Combine(pathString, fileName);

        // Verify the path that you have constructed.
        Console.WriteLine("Path to my file: {0}\n", pathString);

        // Check that the file doesn't already exist. If it doesn't exist, create
        // the file and write integers 0 - 99 to it.
        // DANGER: System.IO.File.Create will overwrite the file if it already exists.
        // This could happen even with random file names, although it is unlikely.
        if (!System.IO.File.Exists(pathString))
        {
            using (System.IO.FileStream fs = System.IO.File.Create(pathString))
            {
                for (byte i = 0; i < 100; i++)
                {
                    fs.WriteByte(i);
                }
            }
        }
        else
        {
            Console.WriteLine("File \"{0}\" already exists.", fileName);
            return;
        }

        // Read and display the data from your file.
        try
        {
            byte[] readBuffer = System.IO.File.ReadAllBytes(pathString);
            foreach (byte b in readBuffer)
            {
                Console.Write(b + " ");
            }
            Console.WriteLine();
        }
        catch (System.IO.IOException e)
        {
            Console.WriteLine(e.Message);
        }

        // Keep the console window open in debug mode.
        System.Console.WriteLine("Press any key to exit.");
        System.Console.ReadKey();
    }
    // Sample output:

    // Path to my file: c:\Top-Level Folder\SubFolder\ttxvauxe.vv0

    //0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29
    //30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56
    // 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 8
    //3 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99
}
```

如果文件夹已存在，[CreateDirectory](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.directory.createdirectory) 不执行任何操作，未引发任何异常。 但 [File.Create](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.file.create) 用新文件替换现有文件。本示例使用 `if`-`else` 语句阻止替换现有文件。

通过在示例中作出以下更改，可根据具有特定名称的文件是否存在来指定不同的结果。 如果该文件不存在，代码就会创建一个文件。 如果该文件存在，代码就会将数据追加到该文件中。

- 指定一个非随机文件名。

  ```csharp
  // Comment out the following line.  
  //string fileName = System.IO.Path.GetRandomFileName();  
  
  // Replace that line with the following assignment.  
  string fileName = "MyNewFile.txt";  
  ```

- 用以下代码中的 `using` 语句替换 `if`-`else` 语句。

  ```csharp
  using (System.IO.FileStream fs = new System.IO.FileStream(pathString, FileMode.Append))   
  {  
      for (byte i = 0; i < 100; i++)  
      {  
          fs.WriteByte(i);  
      }  
  }  
  ```

多次运行此示例，验证数据是否每次都添加到了文件中。

有关可尝试的 `FileMode` 值，请参阅 [FileMode](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.filemode)。

以下情况可能会导致异常：

- 文件夹名称格式不正确。 例如，它包含非法字符或它仅为空格（[ArgumentException](https://docs.microsoft.com/zh-cn/dotnet/api/system.argumentexception) 类）。 使用 [Path](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.path) 类创建有效的路径名。
- 要创建的文件夹的父文件夹为只读（[IOException](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.ioexception) 类）。
- 文件夹名为 `null`[ArgumentNullException](https://docs.microsoft.com/zh-cn/dotnet/api/system.argumentnullexception) 类）。
- 文件夹名过长（[PathTooLongException](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.pathtoolongexception) 类）。
- 文件夹仅为冒号“:”（[PathTooLongException](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.pathtoolongexception) 类）。

### .NET Framework 安全性

可能在部分信任场景中引发 [SecurityException](https://docs.microsoft.com/zh-cn/dotnet/api/system.security.securityexception) 类的实例。

如果没有创建文件夹的权限，则本示例引发 [UnauthorizedAccessException](https://docs.microsoft.com/zh-cn/dotnet/api/system.unauthorizedaccessexception) 类的实例。

## [How to: Copy, Delete, and Move Files and Folders](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/file-system/how-to-copy-delete-and-move-files-and-folders)

以下示例演示如何从 [System.IO](https://docs.microsoft.com/zh-cn/dotnet/api/system.io) 命名空间使用 [System.IO.File](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.file)、[System.IO.Directory](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.directory)、[System.IO.FileInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.fileinfo) 和[System.IO.DirectoryInfo](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.directoryinfo) 类以同步方式复制、移动和删除文件与文件夹。 这些示例未提供进度栏或其他任何用户界面。 若要提供标准进度对话框，请参阅[操作说明：提供文件操作进度对话框](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/file-system/how-to-provide-a-progress-dialog-box-for-file-operations)。

操作多个文件时，请使用 [System.IO.FileSystemWatcher](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.filesystemwatcher) 提供事件，以便可以计算进度。 另一种方法是使用平台调用来调用 Windows Shell 中相应的文件相关方法。 有关如何异步执行这些文件操作的信息，请参阅[异步文件 I/O](https://docs.microsoft.com/zh-cn/dotnet/standard/io/asynchronous-file-i-o)。

### 示例

以下示例演示如何复制文件和目录。

```csharp
// Simple synchronous file copy operations with no user interface.
// To run this sample, first create the following directories and files:
// C:\Users\Public\TestFolder
// C:\Users\Public\TestFolder\test.txt
// C:\Users\Public\TestFolder\SubDir\test.txt
public class SimpleFileCopy
{
    static void Main()
    {
        string fileName = "test.txt";
        string sourcePath = @"C:\Users\Public\TestFolder";
        string targetPath =  @"C:\Users\Public\TestFolder\SubDir";

        // Use Path class to manipulate file and directory paths.
        string sourceFile = System.IO.Path.Combine(sourcePath, fileName);
        string destFile = System.IO.Path.Combine(targetPath, fileName);

        // To copy a folder's contents to a new location:
        // Create a new target folder, if necessary.
        if (!System.IO.Directory.Exists(targetPath))
        {
            System.IO.Directory.CreateDirectory(targetPath);
        }

        // To copy a file to another location and 
        // overwrite the destination file if it already exists.
        System.IO.File.Copy(sourceFile, destFile, true);
        
        // To copy all the files in one directory to another directory.
        // Get the files in the source folder. (To recursively iterate through
        // all subfolders under the current directory, see
        // "How to: Iterate Through a Directory Tree.")
        // Note: Check for target path was performed previously
        //       in this code example.
        if (System.IO.Directory.Exists(sourcePath))
        {
            string[] files = System.IO.Directory.GetFiles(sourcePath);

            // Copy the files and overwrite destination files if they already exist.
            foreach (string s in files)
            {
                // Use static Path methods to extract only the file name from the path.
                fileName = System.IO.Path.GetFileName(s);
                destFile = System.IO.Path.Combine(targetPath, fileName);
                System.IO.File.Copy(s, destFile, true);
            }
        }
        else
        {
            Console.WriteLine("Source path does not exist!");
        }

        // Keep console window open in debug mode.
        Console.WriteLine("Press any key to exit.");
        Console.ReadKey();
    }
}
```

### 示例

以下示例演示如何移动文件和目录。

```csharp
// Simple synchronous file move operations with no user interface.
public class SimpleFileMove
{
    static void Main()
    {
        string sourceFile = @"C:\Users\Public\public\test.txt";
        string destinationFile = @"C:\Users\Public\private\test.txt";

        // To move a file or folder to a new location:
        System.IO.File.Move(sourceFile, destinationFile);

        // To move an entire directory. To programmatically modify or combine
        // path strings, use the System.IO.Path class.
        System.IO.Directory.Move(@"C:\Users\Public\public\test\", @"C:\Users\Public\private");
    }
}
```

### 示例

以下示例演示如何删除文件和目录。

```csharp
// Simple synchronous file deletion operations with no user interface.
// To run this sample, create the following files on your drive:
// C:\Users\Public\DeleteTest\test1.txt
// C:\Users\Public\DeleteTest\test2.txt
// C:\Users\Public\DeleteTest\SubDir\test2.txt

public class SimpleFileDelete
{
    static void Main()
    {
        // Delete a file by using File class static method...
        if(System.IO.File.Exists(@"C:\Users\Public\DeleteTest\test.txt"))
        {
            // Use a try block to catch IOExceptions, to
            // handle the case of the file already being
            // opened by another process.
            try
            {
                System.IO.File.Delete(@"C:\Users\Public\DeleteTest\test.txt");
            }
            catch (System.IO.IOException e)
            {
                Console.WriteLine(e.Message);
                return;
            }
        }

        // ...or by using FileInfo instance method.
        System.IO.FileInfo fi = new System.IO.FileInfo(@"C:\Users\Public\DeleteTest\test2.txt");
        try
        {
            fi.Delete();
        }
        catch (System.IO.IOException e)
        {
            Console.WriteLine(e.Message);
        }

        // Delete a directory. Must be writable or empty.
        try
        {
            System.IO.Directory.Delete(@"C:\Users\Public\DeleteTest");
        }
        catch (System.IO.IOException e)
        {
            Console.WriteLine(e.Message);
        }
        // Delete a directory and all subdirectories with Directory static method...
        if(System.IO.Directory.Exists(@"C:\Users\Public\DeleteTest"))
        {
            try
            {
                System.IO.Directory.Delete(@"C:\Users\Public\DeleteTest", true);
            }

            catch (System.IO.IOException e)
            {
                Console.WriteLine(e.Message);
            }
        }

        // ...or with DirectoryInfo instance method.
        System.IO.DirectoryInfo di = new System.IO.DirectoryInfo(@"C:\Users\Public\public");
        // Delete this dir and all subdirs.
        try
        {
            di.Delete(true);
        }
        catch (System.IO.IOException e)
        {
            Console.WriteLine(e.Message);
        }

    }
}
```

## [How to: Provide a Progress Dialog Box for File Operations](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/file-system/how-to-provide-a-progress-dialog-box-for-file-operations)

如果在 [Microsoft.VisualBasic](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.visualbasic) 命名空间中使用 [CopyFile(String, String, UIOption)](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.visualbasic.fileio.filesystem.copyfile#Microsoft_VisualBasic_FileIO_FileSystem_CopyFile_System_String_System_String_Microsoft_VisualBasic_FileIO_UIOption_) 方法，可以在 Windows 中提供显示文件操作进度的标准对话框。

 备注

以下说明中的某些 Visual Studio 用户界面元素在计算机上出现的名称或位置可能会不同。 这些元素取决于你所使用的 Visual Studio 版本和你所使用的设置。 有关详细信息，请参阅[个性化设置 IDE](https://docs.microsoft.com/zh-cn/visualstudio/ide/personalizing-the-visual-studio-ide)。

### 在 Visual Studio 中添加引用

1. 在菜单栏上，依次选择“项目”、“添加引用”。

   此时将显示“引用管理器”对话框。

2. 在“程序集”区域，选择“Framework”（如果尚未选择它）。

3. 在名称列表中，选择“Microsoft.VisualBasic”复选框，然后再选择“确定”按钮以关闭对话框。

### 示例

以下代码将 `sourcePath` 指定的目录复制到 `destinationPath` 指定的目录。 此代码还提供了标准的对话框，其中显示在操作完成前估计的剩余时间量。

```csharp
// The following using directive requires a project reference to Microsoft.VisualBasic.
using Microsoft.VisualBasic.FileIO;

class FileProgress
{
    static void Main()
    {
        // Specify the path to a folder that you want to copy. If the folder is small, 
        // you won't have time to see the progress dialog box.
        string sourcePath = @"C:\Windows\symbols\";
        // Choose a destination for the copied files.
        string destinationPath = @"C:\TestFolder";

        FileSystem.CopyDirectory(sourcePath, destinationPath,
            UIOption.AllDialogs);
    }
}
```

## [How to: Write to a Text File](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/file-system/how-to-write-to-a-text-file)

以下示例给出了将文本写入文件的各种方法。 前两个示例对 [System.IO.File](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.file) 类使用静态便捷方法以将任何 `IEnumerable<string>` 的每个元素和字符串写入文本文件。 示例 3 展示了在写入文件时必须分别处理文本的每一行时，如何将文本添加到文件。 示例 1-3 覆盖文件中的所有现有内容，但示例 4 展示如何将文本追加到现有文件。

这些示例都将字符串文本写入了文件。 如果想设置写入文件的文本的格式，请使用 [Format](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.format) 方法或 C# [字符串内插](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/tokens/interpolated)功能。

### 示例

```csharp
class WriteTextFile
{
    static void Main()
    {

        // These examples assume a "C:\Users\Public\TestFolder" folder on your machine.
        // You can modify the path if necessary.
        

        // Example #1: Write an array of strings to a file.
        // Create a string array that consists of three lines.
        string[] lines = { "First line", "Second line", "Third line" };
        // WriteAllLines creates a file, writes a collection of strings to the file,
        // and then closes the file.  You do NOT need to call Flush() or Close().
        System.IO.File.WriteAllLines(@"C:\Users\Public\TestFolder\WriteLines.txt", lines);


        // Example #2: Write one string to a text file.
        string text = "A class is the most powerful data type in C#. Like a structure, " +
                       "a class defines the data and behavior of the data type. ";
        // WriteAllText creates a file, writes the specified string to the file,
        // and then closes the file.    You do NOT need to call Flush() or Close().
        System.IO.File.WriteAllText(@"C:\Users\Public\TestFolder\WriteText.txt", text);

        // Example #3: Write only some strings in an array to a file.
        // The using statement automatically flushes AND CLOSES the stream and calls 
        // IDisposable.Dispose on the stream object.
        // NOTE: do not use FileStream for text files because it writes bytes, but StreamWriter
        // encodes the output as text.
        using (System.IO.StreamWriter file = 
            new System.IO.StreamWriter(@"C:\Users\Public\TestFolder\WriteLines2.txt"))
        {
            foreach (string line in lines)
            {
                // If the line doesn't contain the word 'Second', write the line to the file.
                if (!line.Contains("Second"))
                {
                    file.WriteLine(line);
                }
            }
        }

        // Example #4: Append new text to an existing file.
        // The using statement automatically flushes AND CLOSES the stream and calls 
        // IDisposable.Dispose on the stream object.
        using (System.IO.StreamWriter file = 
            new System.IO.StreamWriter(@"C:\Users\Public\TestFolder\WriteLines2.txt", true))
        {
            file.WriteLine("Fourth line");
        }
    }
}
 //Output (to WriteLines.txt):
 //   First line
 //   Second line
 //   Third line
     
 //Output (to WriteText.txt):
 //   A class is the most powerful data type in C#. Like a structure, a class defines the data and behavior of the data type.
     
 //Output to WriteLines2.txt after Example #3:
 //   First line
 //   Third line
      
 //Output to WriteLines2.txt after Example #4:
 //   First line
 //   Third line
 //   Fourth line
```

### 可靠编程

以下情况可能会导致异常：

- 文件已存在并且为只读。
- 路径名可能太长。
- 磁盘可能已满。

## [How to: Read From a Text File](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/file-system/how-to-read-from-a-text-file)

此示例通过使用 [System.IO.File](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.file) 类的 [ReadAllText](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.file.readalltext) 和 [ReadAllLines](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.file.readalllines) 静态方法来确定文本文件的内容。

有关使用 [StreamReader](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.streamreader) 的示例，请参阅[操作说明：一次一行地读取文本文件](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/file-system/how-to-read-a-text-file-one-line-at-a-time)。

> 此示例所用的文件是在主题[操作说明：写入到文本文件](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/file-system/how-to-write-to-a-text-file)中创建。

### 示例

```csharp
class ReadFromFile
{
    static void Main()
    {
        // The files used in this example are created in the topic
        // How to: Write to a Text File. You can change the path and
        // file name to substitute text files of your own.

        // Example #1
        // Read the file as one string.
        string text = System.IO.File.ReadAllText(@"C:\Users\Public\TestFolder\WriteText.txt");

        // Display the file contents to the console. Variable text is a string.
        System.Console.WriteLine("Contents of WriteText.txt = {0}", text);

        // Example #2
        // Read each line of the file into a string array. Each element
        // of the array is one line of the file.
        string[] lines = System.IO.File.ReadAllLines(@"C:\Users\Public\TestFolder\WriteLines2.txt");

        // Display the file contents by using a foreach loop.
        System.Console.WriteLine("Contents of WriteLines2.txt = ");
        foreach (string line in lines)
        {
            // Use a tab to indent each line of the file.
            Console.WriteLine("\t" + line);
        }

        // Keep the console window open in debug mode.
        Console.WriteLine("Press any key to exit.");
        System.Console.ReadKey();
    }
}
```

### 编译代码

将代码复制并粘贴到 C# 控制台应用程序。

如果不使用[操作说明：写入到文本文件](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/file-system/how-to-write-to-a-text-file)中的文本文件，请将 `ReadAllText` 和 `ReadAllLines` 的参数替换为计算机上的适当路径和文件名。

### 可靠编程

以下情况可能会导致异常：

- 不存在该文件，或者指定位置不存在该文件。 检查文件名的路径和拼写。

### .NET Framework 安全性

不要依赖文件名来确定文件的内容。 例如，文件 `myFile.cs` 可能不是 C# 源文件。

## [How to: Read a Text File One Line at a Time (Visual C#)](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/file-system/how-to-read-a-text-file-one-line-at-a-time)

此示例使用 `StreamReader` 类的 `ReadLine` 方法，一次一行地将文本文件内容读入字符串。 每个文本行都存储到字符串 `line` 中并显示在屏幕上。

### 示例

```csharp
int counter = 0;  
string line;  
  
// Read the file and display it line by line.  
System.IO.StreamReader file =   
    new System.IO.StreamReader(@"c:\test.txt");  
while((line = file.ReadLine()) != null)  
{  
    System.Console.WriteLine(line);  
    counter++;  
}  
  
file.Close();  
System.Console.WriteLine("There were {0} lines.", counter);  
// Suspend the screen.  
System.Console.ReadLine();  
```

### 编译代码

复制代码，并将其粘贴到控制台应用程序的 `Main` 方法中。

将 `"c:\test.txt"` 替换为实际文件名。

### 可靠编程

以下情况可能会导致异常：

- 文件可能不存在。

### .NET Framework 安全性

不要根据文件的名称来判断文件的内容。 例如，文件 `myFile.cs` 可能不是 C# 源文件。

## [How to: Create a Key In the Registry (Visual C#)](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/file-system/how-to-create-a-key-in-the-registry)

本示例将值对“Name”和“Isabella”添加到当前用户注册表中的项“Names”之下。

### 示例

```csharp
Microsoft.Win32.RegistryKey key;  
key = Microsoft.Win32.Registry.CurrentUser.CreateSubKey("Names");  
key.SetValue("Name", "Isabella");  
key.Close();  
```

### 编译代码

- 复制代码，并将其粘贴到控制台应用程序的 `Main` 方法中。
- 将 `Names` 参数替换为直接存在于注册表 HKEY_CURRENT_USER 节点下的项的名称。
- 将 `Name` 参数替换为直接存在于“Names”节点下的值的名称。

### 可靠编程

检查注册表结构，查找适合项的位置。 例如，可能需要打开当前用户的 Software 项，并用公司的名称创建一项。然后将注册表值添加到公司的项上。

以下情况可能会导致异常：

- 项的名称为空。
- 用户没有创建注册表项的权限。
- 项名称超过 255 个字符的限制。
- 项已关闭。
- 注册表项为只读。

### .NET Framework 安全性

将数据写入用户文件夹 `Microsoft.Win32.Registry.CurrentUser` 比写入本地计算机 `Microsoft.Win32.Registry.LocalMachine` 更安全。

创建注册表值时，需要确定该值已存在时应执行的操作。 另一进程（可能是恶意进程）可能已创建了该值，并拥有对该值的访问权。 将数据放入注册表值后，其他进程即可使用这些数据。 若要防止出现这种情况，请使用 `Overload:Microsoft.Win32.RegistryKey.GetValue` 方法。 如果项不存在，则该方法返回 null。

即使注册表项受访问控制列表 (ACL) 保护，在注册表中以纯文本形式存储机密信息（例如密码）也不安全。