# [Projections and Transformations (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/projectionsandtransformationslinqtoxml)

本节提供 LINQ to XML 投影和转换的示例。

## 本节内容

| 主题                                                         | 说明                                                  |
| ------------------------------------------------------------ | ----------------------------------------------------- |
| [如何：通过 LINQ to XML 使用字典 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-work-with-dictionaries-using-linq-to-xml) | 演示如何将字典转换为 XML，以及如何将 XML 转换为字典。 |
| [如何：转换 XML 树的形状 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-transform-the-shape-of-an-xml-tree) | 演示如何转换 XML 文档的形状。                         |
| [如何：控制投影的类型 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-control-the-type-of-a-projection) | 演示如何控制 LINQ to XML 查询的类型。                 |
| [如何：投影新类型 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-project-a-new-type-linq-to-xml) | 演示如何从 LINQ to XML 查询投影用户定义类型的集合。   |
| [如何：投影对象图 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-project-an-object-graph) | 演示如何从 LINQ to XML 查询投影更复杂的对象图。       |
| [如何：投影匿名类型 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-project-an-anonymous-type) | 演示如何从 LINQ to XML 查询投影匿名对象的集合。       |
| [如何：从 XML 生成文本文件 (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-generate-text-files-from-xml) | 演示如何将 XML 文件转换为非 XML 文本文件。            |
| [如何：从 CSV 文件生成 XML (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-generate-xml-from-csv-files) | 演示如何使用 LINQ 分析 CSV 文件并从它生成 XML。       |

## [How to: Work with Dictionaries Using LINQ to XML](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoworkwithdictionariesusinglinqtoxml)

通常需要将各种数据结构转换为 XML 和将 XML 转换回其他数据结构。 本主题通过 [Dictionary](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.dictionary-2) 和 XML 的相互转换演示这一常规方法的具体实现。

- 示例

本示例使用函数构造形式：查询投影新 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 对象，生成的集合作为自变量传递给根 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 对象的构造函数。

```csharp
Dictionary<string, string> dict = new Dictionary<string, string>();  
dict.Add("Child1", "Value1");  
dict.Add("Child2", "Value2");  
dict.Add("Child3", "Value3");  
dict.Add("Child4", "Value4");  
XElement root = new XElement("Root",  
    from keyValue in dict  
    select new XElement(keyValue.Key, keyValue.Value)  
);  
Console.WriteLine(root);  
```

此代码生成以下输出：

```xml
<Root>  
  <Child1>Value1</Child1>  
  <Child2>Value2</Child2>  
  <Child3>Value3</Child3>  
  <Child4>Value4</Child4>  
</Root>  
```

- 示例

下面的代码从 XML 创建一个字典。

```csharp
XElement root = new XElement("Root",  
    new XElement("Child1", "Value1"),  
    new XElement("Child2", "Value2"),  
    new XElement("Child3", "Value3"),  
    new XElement("Child4", "Value4")  
);  
  
Dictionary<string, string> dict = new Dictionary<string, string>();  
foreach (XElement el in root.Elements())  
    dict.Add(el.Name.LocalName, el.Value);  
foreach (string str in dict.Keys)  
    Console.WriteLine("{0}:{1}", str, dict[str]);  
```

此代码生成以下输出：

```
Child1:Value1  
Child2:Value2  
Child3:Value3  
Child4:Value4  
```

## [How to: Transform the Shape of an XML Tree](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtotransformtheshapeofanxmltree)

XML 文档的*形状*是指它的元素名称、属性名称以及它的层次结构的特征。

有时，您将不得不更改 XML 文档的形状。 例如，您可能必须将一个现有 XML 文档发送到另一个系统，而该系统要求使用不同的元素和属性名称。 你可以在整个文档中，根据需要删除和重命名元素，但是，如果使用函数构造，则可获得可读性更强、更易于维护的代码。 有关函数构造的详细信息，请参阅[函数构造 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/functional-construction-linq-to-xml)。

第一个示例更改 XML 文档的组织结构。 它将复杂元素从树中的一个位置移动到另一个位置。

本主题的第二个示例创建一个 XML 文档，该文档具有与源文档不同的形状。 它更改元素名称的大小写，重命名某些元素，转换后的树中不包含源树的某些元素。

- 示例

下面的代码使用嵌入式查询表达式更改 XML 文件的形状。

本示例中的源 XML 文档在 `Customers` 元素（它包含所有客户）下包含一个 `Root` 元素。 此外，在 `Orders` 元素（包含所有订单）下包含一个 `Root` 元素。 本示例创建一个新的 XML 树，在该树中，每个客户的订单都包含在 `Orders` 元素内的 `Customer` 元素中。 原始文档还在 `CustomerID` 元素中包含一个 `Order` 元素；此元素将从重新变形的文档中移除。

本示例使用下面的 XML 文档：[示例 XML 文件：客户和订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-customers-and-orders-linq-to-xml-2)。

```csharp
XElement co = XElement.Load("CustomersOrders.xml");  
XElement newCustOrd =  
    new XElement("Root",  
        from cust in co.Element("Customers").Elements("Customer")  
        select new XElement("Customer",  
            cust.Attributes(),  
            cust.Elements(),  
            new XElement("Orders",  
                from ord in co.Element("Orders").Elements("Order")  
                where (string)ord.Element("CustomerID") == (string)cust.Attribute("CustomerID")  
                select new XElement("Order",  
                    ord.Attributes(),  
                    ord.Element("EmployeeID"),  
                    ord.Element("OrderDate"),  
                    ord.Element("RequiredDate"),  
                    ord.Element("ShipInfo")  
                )  
            )  
        )  
    );  
Console.WriteLine(newCustOrd);  
```

此代码生成以下输出：

```xml
<Root>  
  <Customer CustomerID="GREAL">  
    <CompanyName>Great Lakes Food Market</CompanyName>  
    <ContactName>Howard Snyder</ContactName>  
    <ContactTitle>Marketing Manager</ContactTitle>  
    <Phone>(503) 555-7555</Phone>  
    <FullAddress>  
      <Address>2732 Baker Blvd.</Address>  
      <City>Eugene</City>  
      <Region>OR</Region>  
      <PostalCode>97403</PostalCode>  
      <Country>USA</Country>  
    </FullAddress>  
    <Orders />  
  </Customer>  
  <Customer CustomerID="HUNGC">  
    <CompanyName>Hungry Coyote Import Store</CompanyName>  
    <ContactName>Yoshi Latimer</ContactName>  
    <ContactTitle>Sales Representative</ContactTitle>  
    <Phone>(503) 555-6874</Phone>  
    <Fax>(503) 555-2376</Fax>  
    <FullAddress>  
      <Address>City Center Plaza 516 Main St.</Address>  
      <City>Elgin</City>  
      <Region>OR</Region>  
      <PostalCode>97827</PostalCode>  
      <Country>USA</Country>  
    </FullAddress>  
    <Orders />  
  </Customer>  
  . . .  
```

- 示例

本示例重命名某些元素并将某些属性转换为元素。

代码调用 `ConvertAddress`，它返回一个 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement) 对象列表。 此方法的参数是一个查询，该查询确定 `Address`属性值为 `Type` 的 `"Shipping"` 复杂元素。

本示例使用下面的 XML 文档：[示例 XML 文件：典型采购订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-typical-purchase-order-linq-to-xml-1)。

```csharp
static IEnumerable<XElement> ConvertAddress(XElement add)  
{  
    List<XElement> fragment = new List<XElement>() {  
        new XElement("NAME", (string)add.Element("Name")),  
        new XElement("STREET", (string)add.Element("Street")),  
        new XElement("CITY", (string)add.Element("City")),  
        new XElement("ST", (string)add.Element("State")),  
        new XElement("POSTALCODE", (string)add.Element("Zip")),  
        new XElement("COUNTRY", (string)add.Element("Country"))  
    };  
    return fragment;  
}  
  
static void Main(string[] args)  
{  
    XElement po = XElement.Load("PurchaseOrder.xml");  
    XElement newPo = new XElement("PO",  
        new XElement("ID", (string)po.Attribute("PurchaseOrderNumber")),  
        new XElement("DATE", (DateTime)po.Attribute("OrderDate")),  
        ConvertAddress(  
            (from el in po.Elements("Address")  
            where (string)el.Attribute("Type") == "Shipping"  
            select el)  
            .First()  
        )  
    );  
    Console.WriteLine(newPo);  
}  
```

此代码生成以下输出

```xml
<PO>  
  <ID>99503</ID>  
  <DATE>1999-10-20T00:00:00</DATE>  
  <NAME>Ellen Adams</NAME>  
  <STREET>123 Maple Street</STREET>  
  <CITY>Mill Valley</CITY>  
  <ST>CA</ST>  
  <POSTALCODE>10999</POSTALCODE>  
  <COUNTRY>USA</COUNTRY>  
</PO>  
```

## [How to: Control the Type of a Projection](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtocontrolthetypeofaprojection)

投影是一个过程，这一过程包括：获取一组数据，筛选这些数据，更改数据形状，甚至更改数据的类型。 大多数查询表达式都可执行投影。 本节中介绍的大多数查询表达式的计算结果都是 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)，不过，可以控制投影的类型从而创建其他类型的集合。 本主题演示如何执行此操作。

- 示例

下面的示例定义一个新类型 `Customer`。 然后，查询表达式在 `Customer` 子句中实例化新的 `Select` 对象。 这样，查询表达式的类型就是 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的 `Customer`。

本示例使用下面的 XML 文档：[示例 XML 文件：客户和订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-customers-and-orders-linq-to-xml-2)。

```csharp
public class Customer  
{  
    private string customerID;  
    public string CustomerID{ get{return customerID;} set{customerID = value;}}  
  
    private string companyName;  
    public string CompanyName{ get{return companyName;} set{companyName = value;}}  
  
    private string contactName;  
    public string ContactName { get{return contactName;} set{contactName = value;}}  
  
    public Customer(string customerID, string companyName, string contactName)  
    {  
        CustomerID = customerID;  
        CompanyName = companyName;  
        ContactName = contactName;  
    }  
  
    public override string ToString()  
    {  
        return $"{this.customerID}:{this.companyName}:{this.contactName}";
    }  
}  
  
class Program  
{  
    static void Main(string[] args)  
    {  
        XElement custOrd = XElement.Load("CustomersOrders.xml");  
        IEnumerable<Customer> custList =  
            from el in custOrd.Element("Customers").Elements("Customer")  
            select new Customer(  
                (string)el.Attribute("CustomerID"),  
                (string)el.Element("CompanyName"),  
                (string)el.Element("ContactName")  
            );  
        foreach (Customer cust in custList)  
            Console.WriteLine(cust);  
    }  
}  
```

此代码生成以下输出：

```
GREAL:Great Lakes Food Market:Howard Snyder  
HUNGC:Hungry Coyote Import Store:Yoshi Latimer  
LAZYK:Lazy K Kountry Store:John Steel  
LETSS:Let's Stop N Shop:Jaime Yorres  
```

## [How to: Project a New Type (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoprojectanewtypelinqtoxml)

本节中的其他示例已演示了一些查询，这些查询以 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的 [XElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.xml.linq.xelement)、[IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的 `string`和 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的 `int` 的形式返回结果。 这些是常见结果类型，但它们不是对所有情况都适用。 在很多情况下，会希望查询返回其他类型的 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1)。

- 示例

此示例演示如何在 `select` 子句中实例化对象。 代码首先定义一个具有一个构造函数的新类，然后修改 `select`语句，使该表达式成为新类的新实例。

本示例使用下面的 XML 文档：[示例 XML 文件：典型采购订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-typical-purchase-order-linq-to-xml-1)。

```csharp
class NameQty {  
    public string name;  
    public int qty;  
    public NameQty(string n, int q)  
    {  
        name = n;  
        qty = q;  
    }  
};  
  
class Program {  
    public static void Main() {  
        XElement po = XElement.Load("PurchaseOrder.xml");  
  
        IEnumerable<NameQty> nqList =  
            from n in po.Descendants("Item")  
            select new NameQty(  
                    (string)n.Element("ProductName"),  
                    (int)n.Element("Quantity")  
                );  
  
        foreach (NameQty n in nqList)  
            Console.WriteLine(n.name + ":" + n.qty);  
    }  
}  
```

本示例使用 `M:System.Xml.Linq.XElement.Element` 方法，该方法在主题[如何：检索单个子元素 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-retrieve-a-single-child-element-linq-to-xml).中有介绍。 还使用强制转换来检索 `M:System.Xml.Linq.XElement.Element` 方法返回的元素值。

该示例产生下面的输出：

```
Lawnmower:1  
Baby Monitor:2  
```

## [How to: Project an Object Graph](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoprojectanobjectgraph)

本主题演示如何从 XML 投影或填充对象图。

- 示例

以下代码使用[示例 XML 文件中的 `Address`、`PurchaseOrder` 和 `PurchaseOrderItem` 类填充对象图：典型采购订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-typical-purchase-order-linq-to-xml-1) XML 文档。

```csharp
class Address  
{  
    public enum AddressUse  
    {  
        Shipping,  
        Billing,  
    }  
  
    private AddressUse addressType;  
    private string name;  
    private string street;  
    private string city;  
    private string state;  
    private string zip;  
    private string country;  
  
    public AddressUse AddressType {  
        get { return addressType; } set { addressType = value; }  
    }  
  
    public string Name {  
        get { return name; } set { name = value; }  
    }  
  
    public string Street {  
        get { return street; } set { street = value; }  
    }  
  
    public string City {  
        get { return city; } set { city = value; }  
    }  
  
    public string State {  
        get { return state; } set { state = value; }  
    }  
  
    public string Zip {  
        get { return zip; } set { zip = value; }  
    }  
  
    public string Country {  
        get { return country; } set { country = value; }  
    }  
  
    public override string ToString()  
    {  
        StringBuilder sb = new StringBuilder();
        sb.Append($"Type: {(addressType == AddressUse.Shipping ? "Shipping" : "Billing")}\n");
        sb.Append($"Name: {name}\n");
        sb.Append($"Street: {street}\n");
        sb.Append($"City: {city}\n");
        sb.Append($"State: {state}\n");
        sb.Append($"Zip: {zip}\n");
        sb.Append($"Country: {country}\n");
        return sb.ToString();
    }  
}  
  
class PurchaseOrderItem  
{  
    private string partNumber;  
    private string productName;  
    private int quantity;  
    private Decimal usPrice;  
    private string comment;  
    private DateTime shipDate;  
  
    public string PartNumber {  
        get { return partNumber; } set { partNumber = value; }  
    }  
  
    public string ProductName {  
        get { return productName; } set { productName = value; }  
    }  
  
    public int Quantity {  
        get { return quantity; } set { quantity = value; }  
    }  
  
    public Decimal USPrice {  
        get { return usPrice; } set { usPrice = value; }  
    }  
  
    public string Comment {  
        get { return comment; } set { comment = value; }  
    }  
  
    public DateTime ShipDate {  
        get { return shipDate; } set { shipDate = value; }  
    }  
  
    public override string ToString()  
    {  
        StringBuilder sb = new StringBuilder();
        sb.Append($"PartNumber: {partNumber}\n");
        sb.Append($"ProductName: {productName}\n");
        sb.Append($"Quantity: {quantity}\n");
        sb.Append($"USPrice: {usPrice}\n");
        if (comment != null)
            sb.Append($"Comment: {comment}\n");
        if (shipDate != DateTime.MinValue)
            sb.Append($"ShipDate: {shipDate:d}\n");
        return sb.ToString();
    }  
}  
  
class PurchaseOrder  
{  
    private string purchaseOrderNumber;  
    private DateTime orderDate;  
    private string comment;  
    private List<Address> addresses;  
    private List<PurchaseOrderItem> items;  
  
    public string PurchaseOrderNumber {  
        get { return purchaseOrderNumber; } set { purchaseOrderNumber = value; }  
    }  
  
    public DateTime OrderDate {  
        get { return orderDate; } set { orderDate = value; }  
    }  
  
    public string Comment {  
        get { return comment; } set { comment = value; }  
    }  
  
    public List<Address> Addresses {  
        get { return addresses; } set { addresses = value; }  
    }  
  
    public List<PurchaseOrderItem> Items {  
        get { return items; } set { items = value; }  
    }  
  
    public override string ToString()  
    {  
        StringBuilder sb = new StringBuilder();
        sb.Append($"PurchaseOrderNumber: {purchaseOrderNumber}\n");
        sb.Append($"OrderDate: {orderDate:d}\n");
        sb.Append("\n");
        sb.Append("Addresses\n");
        sb.Append("=====\n");
        foreach (Address address in addresses)
        {
            sb.Append(address);
            sb.Append("\n");
        }
        sb.Append("Items\n");
        sb.Append("=====\n");
        foreach (PurchaseOrderItem item in items)
        {
            sb.Append(item);
            sb.Append("\n");
        }
        return sb.ToString();
    }  
}  
  
class Program {  
    public static void Main()  
    {  
        XElement po = XElement.Load("PurchaseOrder.xml");  
        PurchaseOrder purchaseOrder = new PurchaseOrder {  
            PurchaseOrderNumber = (string)po.Attribute("PurchaseOrderNumber"),  
            OrderDate = (DateTime)po.Attribute("OrderDate"),  
            Addresses = (  
                            from a in po.Elements("Address")  
                            select new Address {  
                                AddressType = ((string)a.Attribute("Type") == "Shipping") ?  
                                    Address.AddressUse.Shipping :   
                                    Address.AddressUse.Billing,  
                                Name = (string)a.Element("Name"),  
                                Street = (string)a.Element("Street"),  
                                City = (string)a.Element("City"),  
                                State = (string)a.Element("State"),  
                                Zip = (string)a.Element("Zip"),  
                                Country = (string)a.Element("Country")  
                            }  
                        ).ToList(),  
            Items = (  
                        from i in po.Element("Items").Elements("Item")  
                        select new PurchaseOrderItem {  
                            PartNumber = (string)i.Attribute("PartNumber"),  
                            ProductName = (string)i.Element("ProductName"),  
                            Quantity = (int)i.Element("Quantity"),  
                            USPrice = (Decimal)i.Element("USPrice"),  
                            Comment = (string)i.Element("Comment"),  
                            ShipDate = (i.Element("ShipDate") != null) ?  
                                (DateTime)i.Element("ShipDate") :  
                                DateTime.MinValue  
                        }  
                    ).ToList()  
        };  
        Console.WriteLine(purchaseOrder);  
    }  
}  
```

在此示例中，LINQ 查询的结果以 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的 `PurchaseOrderItem` 形式返回。 `PurchaseOrder` 类中各项的类型都是 [IEnumerable](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.ienumerable-1) 的 `PurchaseOrderItem`。 该代码使用 [ToList](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq.enumerable.tolist) 扩展方法，根据查询结果来创建 [List](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1) 集合。

此示例产生以下输出：

```
PurchaseOrderNumber: 99503  
OrderDate: 10/20/1999  
  
Addresses  
=====  
Type: Shipping  
Name: Ellen Adams  
Street: 123 Maple Street  
City: Mill Valley  
State: CA  
Zip: 10999  
Country: USA  
  
Type: Billing  
Name: Tai Yee  
Street: 8 Oak Avenue  
City: Old Town  
State: PA  
Zip: 95819  
Country: USA  
  
Items  
=====  
PartNumber: 872-AA  
ProductName: Lawnmower  
Quantity: 1  
USPrice: 148.95  
Comment: Confirm this is electric  
  
PartNumber: 926-AA  
ProductName: Baby Monitor  
Quantity: 2  
USPrice: 39.98  
ShipDate: 5/21/1999  
```

## [How to: Project an Anonymous Type](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtoprojectananonymoustype)

在某些情况下，您可能需要将查询投影到新类型，即使您知道只是短时间使用此类型。 创建仅在投影中使用的新类型需要大量额外工作。 在这种情况下，一种更有效的方法是投影到匿名类型。 匿名类型允许您定义一个类，然后在不给出类名称的情况下声明并初始化该类的对象。

匿名类型是“元组”这一数学概念的 C# 实现。 数学术语元组源自序列单元组、双元组、三元组、四元组、五元组和 n 元组。 它指有限的对象序列，每个对象具有特定的类型。 有时，它称为名称/值对的列表。 例如，[示例XML文件：典型采购订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-typical-purchase-order-linq-to-xml-1) XML 文档中的地址内容可表示如下：

```
Name: Ellen Adams  
Street: 123 Maple Street  
City: Mill Valley  
State: CA  
Zip: 90952  
Country: USA  
```

在创建匿名类型的实例时，可以将其想像为创建 n 阶元组。 如果编写一个将在 `select` 子句中创建元组的查询，该查询将返回该元组的一个 `IEnumerable`。

- 示例

在此示例中，`select` 子句投影一个匿名类型。 然后，示例使用 `var` 创建 `IEnumerable` 对象。 在 `foreach` 循环中，该迭代变量成为在查询表达式中创建的匿名类型的实例。

本示例使用下面的 XML 文档：[示例 XML 文件：客户和订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-customers-and-orders-linq-to-xml-2)。

```csharp
XElement custOrd = XElement.Load("CustomersOrders.xml");  
var custList =  
    from el in custOrd.Element("Customers").Elements("Customer")  
    select new {  
        CustomerID = (string)el.Attribute("CustomerID"),  
        CompanyName = (string)el.Element("CompanyName"),  
        ContactName = (string)el.Element("ContactName")  
    };  
foreach (var cust in custList)  
    Console.WriteLine("{0}:{1}:{2}", cust.CustomerID, cust.CompanyName, cust.ContactName);  
```

此代码生成以下输出：

```
GREAL:Great Lakes Food Market:Howard Snyder  
HUNGC:Hungry Coyote Import Store:Yoshi Latimer  
LAZYK:Lazy K Kountry Store:John Steel  
LETSS:Let's Stop N Shop:Jaime Yorres  
```

## [How to: Generate Text Files from XML](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtogeneratetextfilesfromxml)

本示例演示如何从 XML 文件生成逗号分隔值 (CSV) 文件。

- 示例

本示例的 C# 版本使用方法语法和 `Aggregate` 运算符通过一个表达式从 XML 文档生成 CSV 文件。 有关详细信息，请参阅 [LINQ 中的查询语法和方法语法](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/query-syntax-and-method-syntax-in-linq)。

本示例使用下面的 XML 文档：[示例 XML 文件：客户和订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-customers-and-orders-linq-to-xml-2)。

```csharp
XElement custOrd = XElement.Load("CustomersOrders.xml");  
string csv =  
    (from el in custOrd.Element("Customers").Elements("Customer")  
    select  
        String.Format("{0},{1},{2},{3},{4},{5},{6},{7},{8},{9}{10}",  
            (string)el.Attribute("CustomerID"),  
            (string)el.Element("CompanyName"),  
            (string)el.Element("ContactName"),  
            (string)el.Element("ContactTitle"),  
            (string)el.Element("Phone"),  
            (string)el.Element("FullAddress").Element("Address"),  
            (string)el.Element("FullAddress").Element("City"),  
            (string)el.Element("FullAddress").Element("Region"),  
            (string)el.Element("FullAddress").Element("PostalCode"),  
            (string)el.Element("FullAddress").Element("Country"),  
            Environment.NewLine  
        )  
    )  
    .Aggregate(  
        new StringBuilder(),  
        (sb, s) => sb.Append(s),  
        sb => sb.ToString()  
    );  
Console.WriteLine(csv);  
```

此代码生成以下输出：

```
GREAL,Great Lakes Food Market,Howard Snyder,Marketing Manager,(503) 555-7555,2732 Baker Blvd.,Eugene,OR,97403,USA  
HUNGC,Hungry Coyote Import Store,Yoshi Latimer,Sales Representative,(503) 555-6874,City Center Plaza 516 Main St.,Elgin,OR,97827,USA  
LAZYK,Lazy K Kountry Store,John Steel,Marketing Manager,(509) 555-7969,12 Orchestra Terrace,Walla Walla,WA,99362,USA  
LETSS,Let's Stop N Shop,Jaime Yorres,Owner,(415) 555-5938,87 Polk St. Suite 5,San Francisco,CA,94117,USA  
```

## [How to: Generate XML from CSV Files](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/howtogeneratexmlfromcsvfiles)

本示例演示如何使用 语言集成查询 (LINQ) 和 LINQ to XML 从逗号分隔值 (CSV) 文件生成 XML 文件。

- 示例

下面的代码对字符串数组执行 LINQ 查询。

该查询使用 `let` 子句将每个字符串分隔成字段数组。

```csharp
// Create the text file.  
string csvString = @"GREAL,Great Lakes Food Market,Howard Snyder,Marketing Manager,(503) 555-7555,2732 Baker Blvd.,Eugene,OR,97403,USA  
HUNGC,Hungry Coyote Import Store,Yoshi Latimer,Sales Representative,(503) 555-6874,City Center Plaza 516 Main St.,Elgin,OR,97827,USA  
LAZYK,Lazy K Kountry Store,John Steel,Marketing Manager,(509) 555-7969,12 Orchestra Terrace,Walla Walla,WA,99362,USA  
LETSS,Let's Stop N Shop,Jaime Yorres,Owner,(415) 555-5938,87 Polk St. Suite 5,San Francisco,CA,94117,USA";  
File.WriteAllText("cust.csv", csvString);  
  
// Read into an array of strings.  
string[] source = File.ReadAllLines("cust.csv");  
XElement cust = new XElement("Root",  
    from str in source  
    let fields = str.Split(',')  
    select new XElement("Customer",  
        new XAttribute("CustomerID", fields[0]),  
        new XElement("CompanyName", fields[1]),  
        new XElement("ContactName", fields[2]),  
        new XElement("ContactTitle", fields[3]),  
        new XElement("Phone", fields[4]),  
        new XElement("FullAddress",  
            new XElement("Address", fields[5]),  
            new XElement("City", fields[6]),  
            new XElement("Region", fields[7]),  
            new XElement("PostalCode", fields[8]),  
            new XElement("Country", fields[9])  
        )  
    )  
);  
Console.WriteLine(cust);  
```

此代码生成以下输出：

```xml
<Root>  
  <Customer CustomerID="GREAL">  
    <CompanyName>Great Lakes Food Market</CompanyName>  
    <ContactName>Howard Snyder</ContactName>  
    <ContactTitle>Marketing Manager</ContactTitle>  
    <Phone>(503) 555-7555</Phone>  
    <FullAddress>  
      <Address>2732 Baker Blvd.</Address>  
      <City>Eugene</City>  
      <Region>OR</Region>  
      <PostalCode>97403</PostalCode>  
      <Country>USA</Country>  
    </FullAddress>  
  </Customer>  
  <Customer CustomerID="HUNGC">  
    <CompanyName>Hungry Coyote Import Store</CompanyName>  
    <ContactName>Yoshi Latimer</ContactName>  
    <ContactTitle>Sales Representative</ContactTitle>  
    <Phone>(503) 555-6874</Phone>  
    <FullAddress>  
      <Address>City Center Plaza 516 Main St.</Address>  
      <City>Elgin</City>  
      <Region>OR</Region>  
      <PostalCode>97827</PostalCode>  
      <Country>USA</Country>  
    </FullAddress>  
  </Customer>  
  <Customer CustomerID="LAZYK">  
    <CompanyName>Lazy K Kountry Store</CompanyName>  
    <ContactName>John Steel</ContactName>  
    <ContactTitle>Marketing Manager</ContactTitle>  
    <Phone>(509) 555-7969</Phone>  
    <FullAddress>  
      <Address>12 Orchestra Terrace</Address>  
      <City>Walla Walla</City>  
      <Region>WA</Region>  
      <PostalCode>99362</PostalCode>  
      <Country>USA</Country>  
    </FullAddress>  
  </Customer>  
  <Customer CustomerID="LETSS">  
    <CompanyName>Let's Stop N Shop</CompanyName>  
    <ContactName>Jaime Yorres</ContactName>  
    <ContactTitle>Owner</ContactTitle>  
    <Phone>(415) 555-5938</Phone>  
    <FullAddress>  
      <Address>87 Polk St. Suite 5</Address>  
      <City>San Francisco</City>  
      <Region>CA</Region>  
      <PostalCode>94117</PostalCode>  
      <Country>USA</Country>  
    </FullAddress>  
  </Customer>  
</Root>  
```