# [Sample XML Documents (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/samplexmldocumentslinqtoxml)

整个 LINQ to XML 文档的代码示例和代码段中均使用下面的示例文件。

> 此处描述的示例公司、组织、产品、域名、电子邮件地址、徽标、人员、地点和事件均属虚构。 我们无意将它们与任何真实的公司、单位、产品、域名、电子邮件地址、徽标、人员、地点或事件挂钩，请勿“对号入座”。

## 本节内容

| 主题                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [示例 XML 文件：典型采购订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-typical-purchase-order-linq-to-xml-1) | 包含一个典型采购订单的 XML 文档。                            |
| [示例 XML 文件：命名空间中的典型采购订单](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-typical-purchase-order-in-a-namespace) | 处于某一命名空间中的包含一个典型采购订单的 XML 文档。        |
| [示例 XML 文件：多个采购订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-multiple-purchase-orders-linq-to-xml) | 包含多个采购订单的 XML 文档。                                |
| [示例 XML 文件：命名空间中的多个采购订单](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-multiple-purchase-orders-in-a-namespace) | 处于某一命名空间中的包含多个采购订单的 XML 文档。            |
| [示例 XML 文件：测试配置 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-test-configuration-linq-to-xml) | 包含一些伪测试配置数据的 XML 文档。                          |
| [示例 XML 文件：命名空间中的测试配置](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-test-configuration-in-a-namespace1) | 处于某一命名空间中的包含一些伪测试配置数据的 XML 文档。      |
| [示例 XML 文件：客户和订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-customers-and-orders-linq-to-xml-2) | 包含客户和订单的 XML 文档。                                  |
| [示例 XSD 文件：客户和订单](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xsd-file-customers-and-orders1) | XML 架构定义 (XSD)，用于验证[示例 XML 文件：客户和订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-customers-and-orders-linq-to-xml-2)。 |
| [示例 XML 文件：命名空间中的客户和订单](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-customers-and-orders-in-a-namespace) | 处于某一命名空间中的包含客户和订单的 XML 文档。              |
| [示例 XML 文件：数值数据 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-numerical-data-linq-to-xml) | 包含适合于求和和分组的数据的 XML 文档。                      |
| [示例 XML 文件：命名空间中的数值数据](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-numerical-data-in-a-namespace) | 处于某一命名空间中的包含适合于求和和分组的数据的 XML 文档。  |
| [示例 XML 文件：图书 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-books-linq-to-xml) | 包含书籍目录的 XML 文档。                                    |
| [示例 XML 文件：合并采购订单](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-consolidated-purchase-orders) | 表示包含处于不同命名空间中的采购订单的 XML 文档。            |

## [Sample XML File: Typical Purchase Order (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/samplexmlfiletypicalpurchaseorderlinqtoxml1)

下面的 XML 文件用在 LINQ to XML 文档的很多示例中。 此文件是典型的采购单。

### PurchaseOrder.xml

```xml
<?xml version="1.0"?>  
<PurchaseOrder PurchaseOrderNumber="99503" OrderDate="1999-10-20">  
  <Address Type="Shipping">  
    <Name>Ellen Adams</Name>  
    <Street>123 Maple Street</Street>  
    <City>Mill Valley</City>  
    <State>CA</State>  
    <Zip>10999</Zip>  
    <Country>USA</Country>  
  </Address>  
  <Address Type="Billing">  
    <Name>Tai Yee</Name>  
    <Street>8 Oak Avenue</Street>  
    <City>Old Town</City>  
    <State>PA</State>  
    <Zip>95819</Zip>  
    <Country>USA</Country>  
  </Address>  
  <DeliveryNotes>Please leave packages in shed by driveway.</DeliveryNotes>  
  <Items>  
    <Item PartNumber="872-AA">  
      <ProductName>Lawnmower</ProductName>  
      <Quantity>1</Quantity>  
      <USPrice>148.95</USPrice>  
      <Comment>Confirm this is electric</Comment>  
    </Item>  
    <Item PartNumber="926-AA">  
      <ProductName>Baby Monitor</ProductName>  
      <Quantity>2</Quantity>  
      <USPrice>39.98</USPrice>  
      <ShipDate>1999-05-21</ShipDate>  
    </Item>  
  </Items>  
</PurchaseOrder>  
```

## [Sample XML File: Typical Purchase Order in a Namespace](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/samplexmlfiletypicalpurchaseorderinanamespace)

下面的 XML 文件用在 LINQ to XML 文档的很多示例中。 此文件是典型的采购单。 该 XML 在某个命名空间中。

### PurchaseOrderInNamespace.xml

```xml
<?xml version="1.0"?>  
<aw:PurchaseOrder  
    aw:PurchaseOrderNumber="99503"  
    aw:OrderDate="1999-10-20"  
    xmlns:aw="http://www.adventure-works.com">  
  <aw:Address aw:Type="Shipping">  
    <aw:Name>Ellen Adams</aw:Name>  
    <aw:Street>123 Maple Street</aw:Street>  
    <aw:City>Mill Valley</aw:City>  
    <aw:State>CA</aw:State>  
    <aw:Zip>10999</aw:Zip>  
    <aw:Country>USA</aw:Country>  
  </aw:Address>  
  <aw:Address aw:Type="Billing">  
    <aw:Name>Tai Yee</aw:Name>  
    <aw:Street>8 Oak Avenue</aw:Street>  
    <aw:City>Old Town</aw:City>  
    <aw:State>PA</aw:State>  
    <aw:Zip>95819</aw:Zip>  
    <aw:Country>USA</aw:Country>  
  </aw:Address>  
  <aw:DeliveryNotes>Please leave packages in shed by driveway.</aw:DeliveryNotes>  
  <aw:Items>  
    <aw:Item aw:PartNumber="872-AA">  
      <aw:ProductName>Lawnmower</aw:ProductName>  
      <aw:Quantity>1</aw:Quantity>  
      <aw:USPrice>148.95</aw:USPrice>  
      <aw:Comment>Confirm this is electric</aw:Comment>  
    </aw:Item>  
    <aw:Item aw:PartNumber="926-AA">  
      <aw:ProductName>Baby Monitor</aw:ProductName>  
      <aw:Quantity>2</aw:Quantity>  
      <aw:USPrice>39.98</aw:USPrice>  
      <aw:ShipDate>1999-05-21</aw:ShipDate>  
    </aw:Item>  
  </aw:Items>  
</aw:PurchaseOrder>  
```

## [Sample XML File: Multiple Purchase Orders (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/samplexmlfilemultiplepurchaseorderslinqtoxml)

下面的 XML 文件用在 LINQ to XML 文档的很多示例中。 此文件包含多个采购订单。

### PurchaseOrders.xml

```xml
<?xml version="1.0"?>  
<PurchaseOrders>  
  <PurchaseOrder PurchaseOrderNumber="99503" OrderDate="1999-10-20">  
    <Address Type="Shipping">  
      <Name>Ellen Adams</Name>  
      <Street>123 Maple Street</Street>  
      <City>Mill Valley</City>  
      <State>CA</State>  
      <Zip>10999</Zip>  
      <Country>USA</Country>  
    </Address>  
    <Address Type="Billing">  
      <Name>Tai Yee</Name>  
      <Street>8 Oak Avenue</Street>  
      <City>Old Town</City>  
      <State>PA</State>  
      <Zip>95819</Zip>  
      <Country>USA</Country>  
    </Address>  
    <DeliveryNotes>Please leave packages in shed by driveway.</DeliveryNotes>  
    <Items>  
      <Item PartNumber="872-AA">  
        <ProductName>Lawnmower</ProductName>  
        <Quantity>1</Quantity>  
        <USPrice>148.95</USPrice>  
        <Comment>Confirm this is electric</Comment>  
      </Item>  
      <Item PartNumber="926-AA">  
        <ProductName>Baby Monitor</ProductName>  
        <Quantity>2</Quantity>  
        <USPrice>39.98</USPrice>  
        <ShipDate>1999-05-21</ShipDate>  
      </Item>  
    </Items>  
  </PurchaseOrder>  
  <PurchaseOrder PurchaseOrderNumber="99505" OrderDate="1999-10-22">  
    <Address Type="Shipping">  
      <Name>Cristian Osorio</Name>  
      <Street>456 Main Street</Street>  
      <City>Buffalo</City>  
      <State>NY</State>  
      <Zip>98112</Zip>  
      <Country>USA</Country>  
    </Address>  
    <Address Type="Billing">  
      <Name>Cristian Osorio</Name>  
      <Street>456 Main Street</Street>  
      <City>Buffalo</City>  
      <State>NY</State>  
      <Zip>98112</Zip>  
      <Country>USA</Country>  
    </Address>  
    <DeliveryNotes>Please notify me before shipping.</DeliveryNotes>  
    <Items>  
      <Item PartNumber="456-NM">  
        <ProductName>Power Supply</ProductName>  
        <Quantity>1</Quantity>  
        <USPrice>45.99</USPrice>  
      </Item>  
    </Items>  
  </PurchaseOrder>  
  <PurchaseOrder PurchaseOrderNumber="99504" OrderDate="1999-10-22">  
    <Address Type="Shipping">  
      <Name>Jessica Arnold</Name>  
      <Street>4055 Madison Ave</Street>  
      <City>Seattle</City>  
      <State>WA</State>  
      <Zip>98112</Zip>  
      <Country>USA</Country>  
    </Address>  
    <Address Type="Billing">  
      <Name>Jessica Arnold</Name>  
      <Street>4055 Madison Ave</Street>  
      <City>Buffalo</City>  
      <State>NY</State>  
      <Zip>98112</Zip>  
      <Country>USA</Country>  
    </Address>  
    <Items>  
      <Item PartNumber="898-AZ">  
        <ProductName>Computer Keyboard</ProductName>  
        <Quantity>1</Quantity>  
        <USPrice>29.99</USPrice>  
      </Item>  
      <Item PartNumber="898-AM">  
        <ProductName>Wireless Mouse</ProductName>  
        <Quantity>1</Quantity>  
        <USPrice>14.99</USPrice>  
      </Item>  
    </Items>  
  </PurchaseOrder>  
</PurchaseOrders>  
```

## [Sample XML File: Multiple Purchase Orders in a Namespace](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/samplexmlfilemultiplepurchaseordersinanamespace)

下面的 XML 文件用在 LINQ to XML 文档的很多示例中。 此文件包含多个采购订单。 该 XML 在某个命名空间中。

### PurchaseOrdersInNamespace.xml

```xml
<?xml version="1.0" encoding="utf-8"?>  
<aw:PurchaseOrders xmlns:aw="http://www.adventure-works.com">  
  <aw:PurchaseOrder aw:PurchaseOrderNumber="99503" aw:OrderDate="1999-10-20">  
    <aw:Address aw:Type="Shipping">  
      <aw:Name>Ellen Adams</aw:Name>  
      <aw:Street>123 Maple Street</aw:Street>  
      <aw:City>Mill Valley</aw:City>  
      <aw:State>CA</aw:State>  
      <aw:Zip>10999</aw:Zip>  
      <aw:Country>USA</aw:Country>  
    </aw:Address>  
    <aw:Address aw:Type="Billing">  
      <aw:Name>Tai Yee</aw:Name>  
      <aw:Street>8 Oak Avenue</aw:Street>  
      <aw:City>Old Town</aw:City>  
      <aw:State>PA</aw:State>  
      <aw:Zip>95819</aw:Zip>  
      <aw:Country>USA</aw:Country>  
    </aw:Address>  
    <aw:DeliveryNotes>Please leave packages in shed by driveway.</aw:DeliveryNotes>  
    <aw:Items>  
      <aw:Item aw:PartNumber="872-AA">  
        <aw:ProductName>Lawnmower</aw:ProductName>  
        <aw:Quantity>1</aw:Quantity>  
        <aw:USPrice>148.95</aw:USPrice>  
        <aw:Comment>Confirm this is electric</aw:Comment>  
      </aw:Item>  
      <aw:Item aw:PartNumber="926-AA">  
        <aw:ProductName>Baby Monitor</aw:ProductName>  
        <aw:Quantity>2</aw:Quantity>  
        <aw:USPrice>39.98</aw:USPrice>  
        <aw:ShipDate>1999-05-21</aw:ShipDate>  
      </aw:Item>  
    </aw:Items>  
  </aw:PurchaseOrder>  
  <aw:PurchaseOrder aw:PurchaseOrderNumber="99505" aw:OrderDate="1999-10-22">  
    <aw:Address aw:Type="Shipping">  
      <aw:Name>Cristian Osorio</aw:Name>  
      <aw:Street>456 Main Street</aw:Street>  
      <aw:City>Buffalo</aw:City>  
      <aw:State>NY</aw:State>  
      <aw:Zip>98112</aw:Zip>  
      <aw:Country>USA</aw:Country>  
    </aw:Address>  
    <aw:Address aw:Type="Billing">  
      <aw:Name>Cristian Osorio</aw:Name>  
      <aw:Street>456 Main Street</aw:Street>  
      <aw:City>Buffalo</aw:City>  
      <aw:State>NY</aw:State>  
      <aw:Zip>98112</aw:Zip>  
      <aw:Country>USA</aw:Country>  
    </aw:Address>  
    <aw:DeliveryNotes>Please notify me before shipping.</aw:DeliveryNotes>  
    <aw:Items>  
      <aw:Item aw:PartNumber="456-NM">  
        <aw:ProductName>Power Supply</aw:ProductName>  
        <aw:Quantity>1</aw:Quantity>  
        <aw:USPrice>45.99</aw:USPrice>  
      </aw:Item>  
    </aw:Items>  
  </aw:PurchaseOrder>  
  <aw:PurchaseOrder aw:PurchaseOrderNumber="99504" aw:OrderDate="1999-10-22">  
    <aw:Address aw:Type="Shipping">  
      <aw:Name>Jessica Arnold</aw:Name>  
      <aw:Street>4055 Madison Ave</aw:Street>  
      <aw:City>Seattle</aw:City>  
      <aw:State>WA</aw:State>  
      <aw:Zip>98112</aw:Zip>  
      <aw:Country>USA</aw:Country>  
    </aw:Address>  
    <aw:Address aw:Type="Billing">  
      <aw:Name>Jessica Arnold</aw:Name>  
      <aw:Street>4055 Madison Ave</aw:Street>  
      <aw:City>Buffalo</aw:City>  
      <aw:State>NY</aw:State>  
      <aw:Zip>98112</aw:Zip>  
      <aw:Country>USA</aw:Country>  
    </aw:Address>  
    <aw:Items>  
      <aw:Item aw:PartNumber="898-AZ">  
        <aw:ProductName>Computer Keyboard</aw:ProductName>  
        <aw:Quantity>1</aw:Quantity>  
        <aw:USPrice>29.99</aw:USPrice>  
      </aw:Item>  
      <aw:Item aw:PartNumber="898-AM">  
        <aw:ProductName>Wireless Mouse</aw:ProductName>  
        <aw:Quantity>1</aw:Quantity>  
        <aw:USPrice>14.99</aw:USPrice>  
      </aw:Item>  
    </aw:Items>  
  </aw:PurchaseOrder>  
</aw:PurchaseOrders>  
```

## [Sample XML File: Test Configuration (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/samplexmlfiletestconfigurationlinqtoxml)

下面的 XML 文件用在 LINQ to XML 文档的很多示例中。 这是一个测试配置文件。

### TestConfig.xml

```xml
<?xml version="1.0"?>  
<Tests>  
  <Test TestId="0001" TestType="CMD">  
    <Name>Convert number to string</Name>  
    <CommandLine>Examp1.EXE</CommandLine>  
    <Input>1</Input>  
    <Output>One</Output>  
  </Test>  
  <Test TestId="0002" TestType="CMD">  
    <Name>Find succeeding characters</Name>  
    <CommandLine>Examp2.EXE</CommandLine>  
    <Input>abc</Input>  
    <Output>def</Output>  
  </Test>  
  <Test TestId="0003" TestType="GUI">  
    <Name>Convert multiple numbers to strings</Name>  
    <CommandLine>Examp2.EXE /Verbose</CommandLine>  
    <Input>123</Input>  
    <Output>One Two Three</Output>  
  </Test>  
  <Test TestId="0004" TestType="GUI">  
    <Name>Find correlated key</Name>  
    <CommandLine>Examp3.EXE</CommandLine>  
    <Input>a1</Input>  
    <Output>b1</Output>  
  </Test>  
  <Test TestId="0005" TestType="GUI">  
    <Name>Count characters</Name>  
    <CommandLine>FinalExamp.EXE</CommandLine>  
    <Input>This is a test</Input>  
    <Output>14</Output>  
  </Test>  
  <Test TestId="0006" TestType="GUI">  
    <Name>Another Test</Name>  
    <CommandLine>Examp2.EXE</CommandLine>  
    <Input>Test Input</Input>  
    <Output>10</Output>  
  </Test>  
</Tests>  
```

## [Sample XML File: Test Configuration in a Namespace](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/samplexmlfiletestconfigurationinanamespace1)

下面的 XML 文件用在 LINQ to XML 文档的很多示例中。 这是一个测试配置文件。 该 XML 在某个命名空间中。

### TestConfigInNamespace.xml

```xml
<?xml version="1.0"?>  
<Tests xmlns="http://www.adatum.com">  
  <Test TestId="0001" TestType="CMD">  
    <Name>Convert number to string</Name>  
    <CommandLine>Examp1.EXE</CommandLine>  
    <Input>1</Input>  
    <Output>One</Output>  
  </Test>  
  <Test TestId="0002" TestType="CMD">  
    <Name>Find succeeding characters</Name>  
    <CommandLine>Examp2.EXE</CommandLine>  
    <Input>abc</Input>  
    <Output>def</Output>  
  </Test>  
  <Test TestId="0003" TestType="GUI">  
    <Name>Convert multiple numbers to strings</Name>  
    <CommandLine>Examp2.EXE /Verbose</CommandLine>  
    <Input>123</Input>  
    <Output>One Two Three</Output>  
  </Test>  
  <Test TestId="0004" TestType="GUI">  
    <Name>Find correlated key</Name>  
    <CommandLine>Examp3.EXE</CommandLine>  
    <Input>a1</Input>  
    <Output>b1</Output>  
  </Test>  
  <Test TestId="0005" TestType="GUI">  
    <Name>Count characters</Name>  
    <CommandLine>FinalExamp.EXE</CommandLine>  
    <Input>This is a test</Input>  
    <Output>14</Output>  
  </Test>  
  <Test TestId="0006" TestType="GUI">  
    <Name>Another Test</Name>  
    <CommandLine>Examp2.EXE</CommandLine>  
    <Input>Test Input</Input>  
    <Output>10</Output>  
  </Test>  
</Tests>  
```

## [Sample XML File: Customers and Orders (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/samplexmlfilecustomersandorderslinqtoxml2)

下面的 XML 文件用在 LINQ to XML 文档的很多示例中。 此文件包含客户和订单。

主题[示例 XSD 文件：客户和订单](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xsd-file-customers-and-orders1)包含可用于验证此文档的 XSD。 它使用 XSD 的 `xs:key` 和 `xs:keyref` 功能，将`CustomerID` 元素的 `Customer` 属性设置为键，并在每个 `CustomerID` 元素的 `Order` 元素和每个 `CustomerID` 元素的 `Customer` 属性之间建立关系。

有关使用 `Join` 子句编写利用此关系的 LINQ 查询的示例，请参阅[如何：联接两个集合 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-join-two-collections-linq-to-xml)。

### CustomersOrders.xml

```xml
<?xml version="1.0" encoding="utf-8"?>  
<Root>  
  <Customers>  
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
      <Fax>(503) 555-2376</Fax>  
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
      <Fax>(509) 555-6221</Fax>  
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
  </Customers>  
  <Orders>  
    <Order>  
      <CustomerID>GREAL</CustomerID>  
      <EmployeeID>6</EmployeeID>  
      <OrderDate>1997-05-06T00:00:00</OrderDate>  
      <RequiredDate>1997-05-20T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-05-09T00:00:00">  
        <ShipVia>2</ShipVia>  
        <Freight>3.35</Freight>  
        <ShipName>Great Lakes Food Market</ShipName>  
        <ShipAddress>2732 Baker Blvd.</ShipAddress>  
        <ShipCity>Eugene</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97403</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>GREAL</CustomerID>  
      <EmployeeID>8</EmployeeID>  
      <OrderDate>1997-07-04T00:00:00</OrderDate>  
      <RequiredDate>1997-08-01T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-07-14T00:00:00">  
        <ShipVia>2</ShipVia>  
        <Freight>4.42</Freight>  
        <ShipName>Great Lakes Food Market</ShipName>  
        <ShipAddress>2732 Baker Blvd.</ShipAddress>  
        <ShipCity>Eugene</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97403</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>GREAL</CustomerID>  
      <EmployeeID>1</EmployeeID>  
      <OrderDate>1997-07-31T00:00:00</OrderDate>  
      <RequiredDate>1997-08-28T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-08-05T00:00:00">  
        <ShipVia>2</ShipVia>  
        <Freight>116.53</Freight>  
        <ShipName>Great Lakes Food Market</ShipName>  
        <ShipAddress>2732 Baker Blvd.</ShipAddress>  
        <ShipCity>Eugene</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97403</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>GREAL</CustomerID>  
      <EmployeeID>4</EmployeeID>  
      <OrderDate>1997-07-31T00:00:00</OrderDate>  
      <RequiredDate>1997-08-28T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-08-04T00:00:00">  
        <ShipVia>2</ShipVia>  
        <Freight>18.53</Freight>  
        <ShipName>Great Lakes Food Market</ShipName>  
        <ShipAddress>2732 Baker Blvd.</ShipAddress>  
        <ShipCity>Eugene</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97403</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>GREAL</CustomerID>  
      <EmployeeID>6</EmployeeID>  
      <OrderDate>1997-09-04T00:00:00</OrderDate>  
      <RequiredDate>1997-10-02T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-09-10T00:00:00">  
        <ShipVia>1</ShipVia>  
        <Freight>57.15</Freight>  
        <ShipName>Great Lakes Food Market</ShipName>  
        <ShipAddress>2732 Baker Blvd.</ShipAddress>  
        <ShipCity>Eugene</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97403</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>GREAL</CustomerID>  
      <EmployeeID>3</EmployeeID>  
      <OrderDate>1997-09-25T00:00:00</OrderDate>  
      <RequiredDate>1997-10-23T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-09-30T00:00:00">  
        <ShipVia>3</ShipVia>  
        <Freight>76.13</Freight>  
        <ShipName>Great Lakes Food Market</ShipName>  
        <ShipAddress>2732 Baker Blvd.</ShipAddress>  
        <ShipCity>Eugene</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97403</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>GREAL</CustomerID>  
      <EmployeeID>4</EmployeeID>  
      <OrderDate>1998-01-06T00:00:00</OrderDate>  
      <RequiredDate>1998-02-03T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1998-02-04T00:00:00">  
        <ShipVia>2</ShipVia>  
        <Freight>719.78</Freight>  
        <ShipName>Great Lakes Food Market</ShipName>  
        <ShipAddress>2732 Baker Blvd.</ShipAddress>  
        <ShipCity>Eugene</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97403</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>GREAL</CustomerID>  
      <EmployeeID>3</EmployeeID>  
      <OrderDate>1998-03-09T00:00:00</OrderDate>  
      <RequiredDate>1998-04-06T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1998-03-18T00:00:00">  
        <ShipVia>2</ShipVia>  
        <Freight>33.68</Freight>  
        <ShipName>Great Lakes Food Market</ShipName>  
        <ShipAddress>2732 Baker Blvd.</ShipAddress>  
        <ShipCity>Eugene</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97403</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>GREAL</CustomerID>  
      <EmployeeID>3</EmployeeID>  
      <OrderDate>1998-04-07T00:00:00</OrderDate>  
      <RequiredDate>1998-05-05T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1998-04-15T00:00:00">  
        <ShipVia>2</ShipVia>  
        <Freight>25.19</Freight>  
        <ShipName>Great Lakes Food Market</ShipName>  
        <ShipAddress>2732 Baker Blvd.</ShipAddress>  
        <ShipCity>Eugene</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97403</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>GREAL</CustomerID>  
      <EmployeeID>4</EmployeeID>  
      <OrderDate>1998-04-22T00:00:00</OrderDate>  
      <RequiredDate>1998-05-20T00:00:00</RequiredDate>  
      <ShipInfo>  
        <ShipVia>3</ShipVia>  
        <Freight>18.84</Freight>  
        <ShipName>Great Lakes Food Market</ShipName>  
        <ShipAddress>2732 Baker Blvd.</ShipAddress>  
        <ShipCity>Eugene</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97403</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>GREAL</CustomerID>  
      <EmployeeID>4</EmployeeID>  
      <OrderDate>1998-04-30T00:00:00</OrderDate>  
      <RequiredDate>1998-06-11T00:00:00</RequiredDate>  
      <ShipInfo>  
        <ShipVia>3</ShipVia>  
        <Freight>14.01</Freight>  
        <ShipName>Great Lakes Food Market</ShipName>  
        <ShipAddress>2732 Baker Blvd.</ShipAddress>  
        <ShipCity>Eugene</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97403</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>HUNGC</CustomerID>  
      <EmployeeID>3</EmployeeID>  
      <OrderDate>1996-12-06T00:00:00</OrderDate>  
      <RequiredDate>1997-01-03T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1996-12-09T00:00:00">  
        <ShipVia>2</ShipVia>  
        <Freight>20.12</Freight>  
        <ShipName>Hungry Coyote Import Store</ShipName>  
        <ShipAddress>City Center Plaza 516 Main St.</ShipAddress>  
        <ShipCity>Elgin</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97827</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>HUNGC</CustomerID>  
      <EmployeeID>1</EmployeeID>  
      <OrderDate>1996-12-25T00:00:00</OrderDate>  
      <RequiredDate>1997-01-22T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-01-03T00:00:00">  
        <ShipVia>3</ShipVia>  
        <Freight>30.34</Freight>  
        <ShipName>Hungry Coyote Import Store</ShipName>  
        <ShipAddress>City Center Plaza 516 Main St.</ShipAddress>  
        <ShipCity>Elgin</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97827</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>HUNGC</CustomerID>  
      <EmployeeID>3</EmployeeID>  
      <OrderDate>1997-01-15T00:00:00</OrderDate>  
      <RequiredDate>1997-02-12T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-01-24T00:00:00">  
        <ShipVia>1</ShipVia>  
        <Freight>0.2</Freight>  
        <ShipName>Hungry Coyote Import Store</ShipName>  
        <ShipAddress>City Center Plaza 516 Main St.</ShipAddress>  
        <ShipCity>Elgin</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97827</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>HUNGC</CustomerID>  
      <EmployeeID>4</EmployeeID>  
      <OrderDate>1997-07-16T00:00:00</OrderDate>  
      <RequiredDate>1997-08-13T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-07-21T00:00:00">  
        <ShipVia>1</ShipVia>  
        <Freight>45.13</Freight>  
        <ShipName>Hungry Coyote Import Store</ShipName>  
        <ShipAddress>City Center Plaza 516 Main St.</ShipAddress>  
        <ShipCity>Elgin</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97827</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>HUNGC</CustomerID>  
      <EmployeeID>8</EmployeeID>  
      <OrderDate>1997-09-08T00:00:00</OrderDate>  
      <RequiredDate>1997-10-06T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-10-15T00:00:00">  
        <ShipVia>1</ShipVia>  
        <Freight>111.29</Freight>  
        <ShipName>Hungry Coyote Import Store</ShipName>  
        <ShipAddress>City Center Plaza 516 Main St.</ShipAddress>  
        <ShipCity>Elgin</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97827</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>LAZYK</CustomerID>  
      <EmployeeID>1</EmployeeID>  
      <OrderDate>1997-03-21T00:00:00</OrderDate>  
      <RequiredDate>1997-04-18T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-04-10T00:00:00">  
        <ShipVia>3</ShipVia>  
        <Freight>7.48</Freight>  
        <ShipName>Lazy K Kountry Store</ShipName>  
        <ShipAddress>12 Orchestra Terrace</ShipAddress>  
        <ShipCity>Walla Walla</ShipCity>  
        <ShipRegion>WA</ShipRegion>  
        <ShipPostalCode>99362</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>LAZYK</CustomerID>  
      <EmployeeID>8</EmployeeID>  
      <OrderDate>1997-05-22T00:00:00</OrderDate>  
      <RequiredDate>1997-06-19T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-06-26T00:00:00">  
        <ShipVia>2</ShipVia>  
        <Freight>11.92</Freight>  
        <ShipName>Lazy K Kountry Store</ShipName>  
        <ShipAddress>12 Orchestra Terrace</ShipAddress>  
        <ShipCity>Walla Walla</ShipCity>  
        <ShipRegion>WA</ShipRegion>  
        <ShipPostalCode>99362</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>LETSS</CustomerID>  
      <EmployeeID>1</EmployeeID>  
      <OrderDate>1997-06-25T00:00:00</OrderDate>  
      <RequiredDate>1997-07-23T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-07-04T00:00:00">  
        <ShipVia>2</ShipVia>  
        <Freight>13.73</Freight>  
        <ShipName>Let's Stop N Shop</ShipName>  
        <ShipAddress>87 Polk St. Suite 5</ShipAddress>  
        <ShipCity>San Francisco</ShipCity>  
        <ShipRegion>CA</ShipRegion>  
        <ShipPostalCode>94117</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>LETSS</CustomerID>  
      <EmployeeID>8</EmployeeID>  
      <OrderDate>1997-10-27T00:00:00</OrderDate>  
      <RequiredDate>1997-11-24T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-11-05T00:00:00">  
        <ShipVia>2</ShipVia>  
        <Freight>51.44</Freight>  
        <ShipName>Let's Stop N Shop</ShipName>  
        <ShipAddress>87 Polk St. Suite 5</ShipAddress>  
        <ShipCity>San Francisco</ShipCity>  
        <ShipRegion>CA</ShipRegion>  
        <ShipPostalCode>94117</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>LETSS</CustomerID>  
      <EmployeeID>6</EmployeeID>  
      <OrderDate>1997-11-10T00:00:00</OrderDate>  
      <RequiredDate>1997-12-08T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-11-21T00:00:00">  
        <ShipVia>2</ShipVia>  
        <Freight>45.97</Freight>  
        <ShipName>Let's Stop N Shop</ShipName>  
        <ShipAddress>87 Polk St. Suite 5</ShipAddress>  
        <ShipCity>San Francisco</ShipCity>  
        <ShipRegion>CA</ShipRegion>  
        <ShipPostalCode>94117</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>LETSS</CustomerID>  
      <EmployeeID>4</EmployeeID>  
      <OrderDate>1998-02-12T00:00:00</OrderDate>  
      <RequiredDate>1998-03-12T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1998-02-13T00:00:00">  
        <ShipVia>2</ShipVia>  
        <Freight>90.97</Freight>  
        <ShipName>Let's Stop N Shop</ShipName>  
        <ShipAddress>87 Polk St. Suite 5</ShipAddress>  
        <ShipCity>San Francisco</ShipCity>  
        <ShipRegion>CA</ShipRegion>  
        <ShipPostalCode>94117</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
  </Orders>  
</Root>  
```

## [Sample XSD File: Customers and Orders](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/samplexsdfilecustomersandorders1)

下面的 XSD 文件用在 LINQ to XML 文档的很多示例中。 此文件包含[示例 XML 文件：客户和订单 (LINQ to XML)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/sample-xml-file-customers-and-orders-linq-to-xml-2)的架构定义。 架构使用 XSD 的 `xs:key` 和 `xs:keyref` 功能将 `CustomerID` 元素的 `Customer` 属性设置为键，并在每个 `CustomerID` 元素的 `Order` 元素和每个 `CustomerID` 元素的 `Customer` 属性之间建立关系。

有关使用 `Join` 子句编写利用此关系的 LINQ 查询的示例，请参阅[如何：联接两个集合 (LINQ to XML) (C#)](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/how-to-join-two-collections-linq-to-xml)。

### CustomersOrders.xsd

```xml
<?xml version="1.0" encoding="utf-8" ?>  
<xs:schema xmlns:xs="http://www.w3.org/2001/XMLSchema">  
  <xs:element name='Root'>  
    <xs:complexType>  
      <xs:sequence>  
        <xs:element name='Customers'>  
          <xs:complexType>  
            <xs:sequence>  
              <xs:element name='Customer' type='CustomerType' minOccurs='0' maxOccurs='unbounded' />  
            </xs:sequence>  
          </xs:complexType>  
        </xs:element>  
        <xs:element name='Orders'>  
          <xs:complexType>  
            <xs:sequence>  
              <xs:element name='Order' type='OrderType' minOccurs='0' maxOccurs='unbounded' />  
            </xs:sequence>  
          </xs:complexType>  
        </xs:element>  
      </xs:sequence>  
    </xs:complexType>  
    <xs:key name='CustomerIDKey'>  
      <xs:selector xpath='Customers/Customer'/>  
      <xs:field xpath='@CustomerID'/>  
    </xs:key>  
    <xs:keyref name='CustomerIDKeyRef' refer='CustomerIDKey'>  
      <xs:selector xpath='Orders/Order'/>  
      <xs:field xpath='CustomerID'/>  
    </xs:keyref>  
  </xs:element>  
  <xs:complexType name='CustomerType'>  
    <xs:sequence>  
      <xs:element name='CompanyName' type='xs:string'/>  
      <xs:element name='ContactName' type='xs:string'/>  
      <xs:element name='ContactTitle' type='xs:string'/>  
      <xs:element name='Phone' type='xs:string'/>  
      <xs:element name='Fax' minOccurs='0' type='xs:string'/>  
      <xs:element name='FullAddress' type='AddressType'/>  
    </xs:sequence>  
    <xs:attribute name='CustomerID' type='xs:token'/>  
  </xs:complexType>  
  <xs:complexType name='AddressType'>  
    <xs:sequence>  
      <xs:element name='Address' type='xs:string'/>  
      <xs:element name='City' type='xs:string'/>  
      <xs:element name='Region' type='xs:string'/>  
      <xs:element name='PostalCode' type='xs:string' />  
      <xs:element name='Country' type='xs:string'/>  
    </xs:sequence>  
    <xs:attribute name='CustomerID' type='xs:token'/>  
  </xs:complexType>  
  <xs:complexType name='OrderType'>  
    <xs:sequence>  
      <xs:element name='CustomerID' type='xs:token'/>  
      <xs:element name='EmployeeID' type='xs:token'/>  
      <xs:element name='OrderDate' type='xs:dateTime'/>  
      <xs:element name='RequiredDate' type='xs:dateTime'/>  
      <xs:element name='ShipInfo' type='ShipInfoType'/>  
    </xs:sequence>  
  </xs:complexType>  
  <xs:complexType name='ShipInfoType'>  
    <xs:sequence>  
      <xs:element name='ShipVia' type='xs:integer'/>  
      <xs:element name='Freight' type='xs:decimal'/>  
      <xs:element name='ShipName' type='xs:string'/>  
      <xs:element name='ShipAddress' type='xs:string'/>  
      <xs:element name='ShipCity' type='xs:string'/>  
      <xs:element name='ShipRegion' type='xs:string'/>  
      <xs:element name='ShipPostalCode' type='xs:string'/>  
      <xs:element name='ShipCountry' type='xs:string'/>  
    </xs:sequence>  
    <xs:attribute name='ShippedDate' type='xs:dateTime'/>  
  </xs:complexType>  
</xs:schema>  
```

## [Sample XML File: Customers and Orders in a Namespace](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/samplexmlfilecustomersandordersinanamespace)

下面的 XML 文件用在 LINQ to XML 文档的很多示例中。 此文件包含客户和订单。 该 XML 在某个命名空间中。

### CustomersOrdersInNamespace.xml

```xml
<?xml version="1.0" encoding="utf-8"?>  
<Root xmlns="http://www.adventure-works.com">  
  <Customers>  
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
      <Fax>(503) 555-2376</Fax>  
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
      <Fax>(509) 555-6221</Fax>  
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
  </Customers>  
  <Orders>  
    <Order>  
      <CustomerID>GREAL</CustomerID>  
      <EmployeeID>6</EmployeeID>  
      <OrderDate>1997-05-06T00:00:00</OrderDate>  
      <RequiredDate>1997-05-20T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-05-09T00:00:00">  
        <ShipVia>2</ShipVia>  
        <Freight>3.35</Freight>  
        <ShipName>Great Lakes Food Market</ShipName>  
        <ShipAddress>2732 Baker Blvd.</ShipAddress>  
        <ShipCity>Eugene</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97403</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>GREAL</CustomerID>  
      <EmployeeID>8</EmployeeID>  
      <OrderDate>1997-07-04T00:00:00</OrderDate>  
      <RequiredDate>1997-08-01T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-07-14T00:00:00">  
        <ShipVia>2</ShipVia>  
        <Freight>4.42</Freight>  
        <ShipName>Great Lakes Food Market</ShipName>  
        <ShipAddress>2732 Baker Blvd.</ShipAddress>  
        <ShipCity>Eugene</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97403</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>GREAL</CustomerID>  
      <EmployeeID>1</EmployeeID>  
      <OrderDate>1997-07-31T00:00:00</OrderDate>  
      <RequiredDate>1997-08-28T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-08-05T00:00:00">  
        <ShipVia>2</ShipVia>  
        <Freight>116.53</Freight>  
        <ShipName>Great Lakes Food Market</ShipName>  
        <ShipAddress>2732 Baker Blvd.</ShipAddress>  
        <ShipCity>Eugene</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97403</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>GREAL</CustomerID>  
      <EmployeeID>4</EmployeeID>  
      <OrderDate>1997-07-31T00:00:00</OrderDate>  
      <RequiredDate>1997-08-28T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-08-04T00:00:00">  
        <ShipVia>2</ShipVia>  
        <Freight>18.53</Freight>  
        <ShipName>Great Lakes Food Market</ShipName>  
        <ShipAddress>2732 Baker Blvd.</ShipAddress>  
        <ShipCity>Eugene</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97403</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>GREAL</CustomerID>  
      <EmployeeID>6</EmployeeID>  
      <OrderDate>1997-09-04T00:00:00</OrderDate>  
      <RequiredDate>1997-10-02T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-09-10T00:00:00">  
        <ShipVia>1</ShipVia>  
        <Freight>57.15</Freight>  
        <ShipName>Great Lakes Food Market</ShipName>  
        <ShipAddress>2732 Baker Blvd.</ShipAddress>  
        <ShipCity>Eugene</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97403</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>GREAL</CustomerID>  
      <EmployeeID>3</EmployeeID>  
      <OrderDate>1997-09-25T00:00:00</OrderDate>  
      <RequiredDate>1997-10-23T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-09-30T00:00:00">  
        <ShipVia>3</ShipVia>  
        <Freight>76.13</Freight>  
        <ShipName>Great Lakes Food Market</ShipName>  
        <ShipAddress>2732 Baker Blvd.</ShipAddress>  
        <ShipCity>Eugene</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97403</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>GREAL</CustomerID>  
      <EmployeeID>4</EmployeeID>  
      <OrderDate>1998-01-06T00:00:00</OrderDate>  
      <RequiredDate>1998-02-03T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1998-02-04T00:00:00">  
        <ShipVia>2</ShipVia>  
        <Freight>719.78</Freight>  
        <ShipName>Great Lakes Food Market</ShipName>  
        <ShipAddress>2732 Baker Blvd.</ShipAddress>  
        <ShipCity>Eugene</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97403</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>GREAL</CustomerID>  
      <EmployeeID>3</EmployeeID>  
      <OrderDate>1998-03-09T00:00:00</OrderDate>  
      <RequiredDate>1998-04-06T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1998-03-18T00:00:00">  
        <ShipVia>2</ShipVia>  
        <Freight>33.68</Freight>  
        <ShipName>Great Lakes Food Market</ShipName>  
        <ShipAddress>2732 Baker Blvd.</ShipAddress>  
        <ShipCity>Eugene</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97403</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>GREAL</CustomerID>  
      <EmployeeID>3</EmployeeID>  
      <OrderDate>1998-04-07T00:00:00</OrderDate>  
      <RequiredDate>1998-05-05T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1998-04-15T00:00:00">  
        <ShipVia>2</ShipVia>  
        <Freight>25.19</Freight>  
        <ShipName>Great Lakes Food Market</ShipName>  
        <ShipAddress>2732 Baker Blvd.</ShipAddress>  
        <ShipCity>Eugene</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97403</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>GREAL</CustomerID>  
      <EmployeeID>4</EmployeeID>  
      <OrderDate>1998-04-22T00:00:00</OrderDate>  
      <RequiredDate>1998-05-20T00:00:00</RequiredDate>  
      <ShipInfo>  
        <ShipVia>3</ShipVia>  
        <Freight>18.84</Freight>  
        <ShipName>Great Lakes Food Market</ShipName>  
        <ShipAddress>2732 Baker Blvd.</ShipAddress>  
        <ShipCity>Eugene</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97403</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>GREAL</CustomerID>  
      <EmployeeID>4</EmployeeID>  
      <OrderDate>1998-04-30T00:00:00</OrderDate>  
      <RequiredDate>1998-06-11T00:00:00</RequiredDate>  
      <ShipInfo>  
        <ShipVia>3</ShipVia>  
        <Freight>14.01</Freight>  
        <ShipName>Great Lakes Food Market</ShipName>  
        <ShipAddress>2732 Baker Blvd.</ShipAddress>  
        <ShipCity>Eugene</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97403</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>HUNGC</CustomerID>  
      <EmployeeID>3</EmployeeID>  
      <OrderDate>1996-12-06T00:00:00</OrderDate>  
      <RequiredDate>1997-01-03T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1996-12-09T00:00:00">  
        <ShipVia>2</ShipVia>  
        <Freight>20.12</Freight>  
        <ShipName>Hungry Coyote Import Store</ShipName>  
        <ShipAddress>City Center Plaza 516 Main St.</ShipAddress>  
        <ShipCity>Elgin</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97827</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>HUNGC</CustomerID>  
      <EmployeeID>1</EmployeeID>  
      <OrderDate>1996-12-25T00:00:00</OrderDate>  
      <RequiredDate>1997-01-22T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-01-03T00:00:00">  
        <ShipVia>3</ShipVia>  
        <Freight>30.34</Freight>  
        <ShipName>Hungry Coyote Import Store</ShipName>  
        <ShipAddress>City Center Plaza 516 Main St.</ShipAddress>  
        <ShipCity>Elgin</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97827</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>HUNGC</CustomerID>  
      <EmployeeID>3</EmployeeID>  
      <OrderDate>1997-01-15T00:00:00</OrderDate>  
      <RequiredDate>1997-02-12T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-01-24T00:00:00">  
        <ShipVia>1</ShipVia>  
        <Freight>0.2</Freight>  
        <ShipName>Hungry Coyote Import Store</ShipName>  
        <ShipAddress>City Center Plaza 516 Main St.</ShipAddress>  
        <ShipCity>Elgin</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97827</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>HUNGC</CustomerID>  
      <EmployeeID>4</EmployeeID>  
      <OrderDate>1997-07-16T00:00:00</OrderDate>  
      <RequiredDate>1997-08-13T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-07-21T00:00:00">  
        <ShipVia>1</ShipVia>  
        <Freight>45.13</Freight>  
        <ShipName>Hungry Coyote Import Store</ShipName>  
        <ShipAddress>City Center Plaza 516 Main St.</ShipAddress>  
        <ShipCity>Elgin</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97827</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>HUNGC</CustomerID>  
      <EmployeeID>8</EmployeeID>  
      <OrderDate>1997-09-08T00:00:00</OrderDate>  
      <RequiredDate>1997-10-06T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-10-15T00:00:00">  
        <ShipVia>1</ShipVia>  
        <Freight>111.29</Freight>  
        <ShipName>Hungry Coyote Import Store</ShipName>  
        <ShipAddress>City Center Plaza 516 Main St.</ShipAddress>  
        <ShipCity>Elgin</ShipCity>  
        <ShipRegion>OR</ShipRegion>  
        <ShipPostalCode>97827</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>LAZYK</CustomerID>  
      <EmployeeID>1</EmployeeID>  
      <OrderDate>1997-03-21T00:00:00</OrderDate>  
      <RequiredDate>1997-04-18T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-04-10T00:00:00">  
        <ShipVia>3</ShipVia>  
        <Freight>7.48</Freight>  
        <ShipName>Lazy K Kountry Store</ShipName>  
        <ShipAddress>12 Orchestra Terrace</ShipAddress>  
        <ShipCity>Walla Walla</ShipCity>  
        <ShipRegion>WA</ShipRegion>  
        <ShipPostalCode>99362</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>LAZYK</CustomerID>  
      <EmployeeID>8</EmployeeID>  
      <OrderDate>1997-05-22T00:00:00</OrderDate>  
      <RequiredDate>1997-06-19T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-06-26T00:00:00">  
        <ShipVia>2</ShipVia>  
        <Freight>11.92</Freight>  
        <ShipName>Lazy K Kountry Store</ShipName>  
        <ShipAddress>12 Orchestra Terrace</ShipAddress>  
        <ShipCity>Walla Walla</ShipCity>  
        <ShipRegion>WA</ShipRegion>  
        <ShipPostalCode>99362</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>LETSS</CustomerID>  
      <EmployeeID>1</EmployeeID>  
      <OrderDate>1997-06-25T00:00:00</OrderDate>  
      <RequiredDate>1997-07-23T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-07-04T00:00:00">  
        <ShipVia>2</ShipVia>  
        <Freight>13.73</Freight>  
        <ShipName>Let's Stop N Shop</ShipName>  
        <ShipAddress>87 Polk St. Suite 5</ShipAddress>  
        <ShipCity>San Francisco</ShipCity>  
        <ShipRegion>CA</ShipRegion>  
        <ShipPostalCode>94117</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>LETSS</CustomerID>  
      <EmployeeID>8</EmployeeID>  
      <OrderDate>1997-10-27T00:00:00</OrderDate>  
      <RequiredDate>1997-11-24T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-11-05T00:00:00">  
        <ShipVia>2</ShipVia>  
        <Freight>51.44</Freight>  
        <ShipName>Let's Stop N Shop</ShipName>  
        <ShipAddress>87 Polk St. Suite 5</ShipAddress>  
        <ShipCity>San Francisco</ShipCity>  
        <ShipRegion>CA</ShipRegion>  
        <ShipPostalCode>94117</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>LETSS</CustomerID>  
      <EmployeeID>6</EmployeeID>  
      <OrderDate>1997-11-10T00:00:00</OrderDate>  
      <RequiredDate>1997-12-08T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1997-11-21T00:00:00">  
        <ShipVia>2</ShipVia>  
        <Freight>45.97</Freight>  
        <ShipName>Let's Stop N Shop</ShipName>  
        <ShipAddress>87 Polk St. Suite 5</ShipAddress>  
        <ShipCity>San Francisco</ShipCity>  
        <ShipRegion>CA</ShipRegion>  
        <ShipPostalCode>94117</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
    <Order>  
      <CustomerID>LETSS</CustomerID>  
      <EmployeeID>4</EmployeeID>  
      <OrderDate>1998-02-12T00:00:00</OrderDate>  
      <RequiredDate>1998-03-12T00:00:00</RequiredDate>  
      <ShipInfo ShippedDate="1998-02-13T00:00:00">  
        <ShipVia>2</ShipVia>  
        <Freight>90.97</Freight>  
        <ShipName>Let's Stop N Shop</ShipName>  
        <ShipAddress>87 Polk St. Suite 5</ShipAddress>  
        <ShipCity>San Francisco</ShipCity>  
        <ShipRegion>CA</ShipRegion>  
        <ShipPostalCode>94117</ShipPostalCode>  
        <ShipCountry>USA</ShipCountry>  
      </ShipInfo>  
    </Order>  
  </Orders>  
</Root>  
```

## [Sample XML File: Numerical Data (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/samplexmlfilenumericaldatalinqtoxml)

下面的 XML 文件用在 LINQ to XML 文档的很多示例中。 此文件包含数值数据，用于求和、求平均值和分组。

### Data.xml

```xml
<Root>  
  <TaxRate>7.25</TaxRate>  
  <Data>  
    <Category>A</Category>  
    <Quantity>3</Quantity>  
    <Price>24.50</Price>  
  </Data>  
  <Data>  
    <Category>B</Category>  
    <Quantity>1</Quantity>  
    <Price>89.99</Price>  
  </Data>  
  <Data>  
    <Category>A</Category>  
    <Quantity>5</Quantity>  
    <Price>4.95</Price>  
  </Data>  
  <Data>  
    <Category>A</Category>  
    <Quantity>3</Quantity>  
    <Price>66.00</Price>  
  </Data>  
  <Data>  
    <Category>B</Category>  
    <Quantity>10</Quantity>  
    <Price>.99</Price>  
  </Data>  
  <Data>  
    <Category>A</Category>  
    <Quantity>15</Quantity>  
    <Price>29.00</Price>  
  </Data>  
  <Data>  
    <Category>B</Category>  
    <Quantity>8</Quantity>  
    <Price>6.99</Price>  
  </Data>  
</Root>  
```

## [Sample XML File: Numerical Data in a Namespace](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/samplexmlfilenumericaldatainanamespace)

下面的 XML 文件用在 LINQ to XML 文档的很多示例中。 此文件包含数值数据，用于求和、求平均值和分组。 该 XML 在某个命名空间中。

### 数据

```xml
<Root xmlns='http://www.adatum.com'>  
  <TaxRate>7.25</TaxRate>  
  <Data>  
    <Category>A</Category>  
    <Quantity>3</Quantity>  
    <Price>24.50</Price>  
  </Data>  
  <Data>  
    <Category>B</Category>  
    <Quantity>1</Quantity>  
    <Price>89.99</Price>  
  </Data>  
  <Data>  
    <Category>A</Category>  
    <Quantity>5</Quantity>  
    <Price>4.95</Price>  
  </Data>  
  <Data>  
    <Category>A</Category>  
    <Quantity>3</Quantity>  
    <Price>66.00</Price>  
  </Data>  
  <Data>  
    <Category>B</Category>  
    <Quantity>10</Quantity>  
    <Price>.99</Price>  
  </Data>  
  <Data>  
    <Category>A</Category>  
    <Quantity>15</Quantity>  
    <Price>29.00</Price>  
  </Data>  
  <Data>  
    <Category>B</Category>  
    <Quantity>8</Quantity>  
    <Price>6.99</Price>  
  </Data>  
</Root>  
```

## [Sample XML File: Books (LINQ to XML)](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/samplexmlfilebookslinqtoxml)

下面的 XML 文件用在 LINQ to XML 文档的很多示例中。 该文件包含有关图书的信息。

### books.xml

```xml
<?xml version="1.0"?>  
<Catalog>  
   <Book id="bk101">  
      <Author>Garghentini, Davide</Author>  
      <Title>XML Developer's Guide</Title>  
      <Genre>Computer</Genre>  
      <Price>44.95</Price>  
      <PublishDate>2000-10-01</PublishDate>  
      <Description>An in-depth look at creating applications   
      with XML.</Description>  
   </Book>  
   <Book id="bk102">  
      <Author>Garcia, Debra</Author>  
      <Title>Midnight Rain</Title>  
      <Genre>Fantasy</Genre>  
      <Price>5.95</Price>  
      <PublishDate>2000-12-16</PublishDate>  
      <Description>A former architect battles corporate zombies,   
      an evil sorceress, and her own childhood to become queen   
      of the world.</Description>  
   </Book>  
</Catalog>  
```

## [Sample XML File: Consolidated Purchase Orders](https://docs.microsoft.com/enus/dotnet/csharp/programmingguide/concepts/linq/samplexmlfileconsolidatedpurchaseorders)

下面的 XML 文件用在 LINQ to XML 文档的很多示例中。 此文件是一组来自多家公司、具有不同形状的采购订单。每家公司的采购订单位于单独的命名空间中。

### ConsolidatedPurchaseOrders.xml

```xml
<?xml version="1.0"?>  
<PurchaseOrders xmlns="www.contoso.com">  
  <PurchaseOrder  
      PurchaseOrderNumber="99503"  
      OrderDate="1999-10-20">  
    <Address Type="Shipping">  
      <Name>Ellen Adams</Name>  
      <Street>123 Maple Street</Street>  
      <City>Mill Valley</City>  
      <State>CA</State>  
      <Zip>10999</Zip>  
      <Country>USA</Country>  
    </Address>  
    <Address Type="Billing">  
      <Name>Tai Yee</Name>  
      <Street>8 Oak Avenue</Street>  
      <City>Old Town</City>  
      <State>PA</State>  
      <Zip>95819</Zip>  
      <Country>USA</Country>  
    </Address>  
    <DeliveryNotes>Please leave packages in shed by driveway.</DeliveryNotes>  
    <Items>  
      <Item PartNumber="872-AA">  
        <ProductName>Lawnmower</ProductName>  
        <Quantity>1</Quantity>  
        <USPrice>148.95</USPrice>  
        <Comment>Confirm this is electric</Comment>  
      </Item>  
      <Item PartNumber="926-AA">  
        <ProductName>Baby Monitor</ProductName>  
        <Quantity>2</Quantity>  
        <USPrice>39.98</USPrice>  
        <ShipDate>1999-05-21</ShipDate>  
      </Item>  
    </Items>  
  </PurchaseOrder>  
  <PurchaseOrder PurchaseOrderNumber="99505" OrderDate="1999-10-22">  
    <Address Type="Shipping">  
      <Name>Cristian Osorio</Name>  
      <Street>456 Main Street</Street>  
      <City>Buffalo</City>  
      <State>NY</State>  
      <Zip>98112</Zip>  
      <Country>USA</Country>  
    </Address>  
    <Address Type="Billing">  
      <Name>Cristian Osorio</Name>  
      <Street>456 Main Street</Street>  
      <City>Buffalo</City>  
      <State>NY</State>  
      <Zip>98112</Zip>  
      <Country>USA</Country>  
    </Address>  
    <DeliveryNotes>Please notify by email before shipping.</DeliveryNotes>  
    <Items>  
      <Item PartNumber="456-NM">  
        <ProductName>Power Supply</ProductName>  
        <Quantity>1</Quantity>  
        <USPrice>45.99</USPrice>  
      </Item>  
    </Items>  
  </PurchaseOrder>  
  <PurchaseOrder PurchaseOrderNumber="99504" OrderDate="1999-10-22">  
    <Address Type="Shipping">  
      <Name>Jessica Arnold</Name>  
      <Street>4055 Madison Ave</Street>  
      <City>Seattle</City>  
      <State>WA</State>  
      <Zip>98112</Zip>  
      <Country>USA</Country>  
    </Address>  
    <Address Type="Billing">  
      <Name>Jessica Arnold</Name>  
      <Street>4055 Madison Ave</Street>  
      <City>Buffalo</City>  
      <State>NY</State>  
      <Zip>98112</Zip>  
      <Country>USA</Country>  
    </Address>  
    <DeliveryNotes>Please do not deliver on Saturday.</DeliveryNotes>  
    <Items>  
      <Item PartNumber="898-AZ">  
        <ProductName>Computer Keyboard</ProductName>  
        <Quantity>1</Quantity>  
        <USPrice>29.99</USPrice>  
      </Item>  
      <Item PartNumber="898-AM">  
        <ProductName>Wireless Mouse</ProductName>  
        <Quantity>1</Quantity>  
        <USPrice>14.99</USPrice>  
      </Item>  
    </Items>  
  </PurchaseOrder>  
  <aw:PurchaseOrder  
    PONumber="11223"  
    Date="2000-01-15"  
    xmlns:aw="http://www.adventure-works.com">  
    <aw:ShippingAddress>  
      <aw:Name>Chris Preston</aw:Name>  
      <aw:Street>123 Main St.</aw:Street>  
      <aw:City>Seattle</aw:City>  
      <aw:State>WA</aw:State>  
      <aw:Zip>98113</aw:Zip>  
      <aw:Country>USA</aw:Country>  
    </aw:ShippingAddress>  
    <aw:BillingAddress>  
      <aw:Name>Chris Preston</aw:Name>  
      <aw:Street>123 Main St.</aw:Street>  
      <aw:City>Seattle</aw:City>  
      <aw:State>WA</aw:State>  
      <aw:Zip>98113</aw:Zip>  
      <aw:Country>USA</aw:Country>  
    </aw:BillingAddress>  
    <aw:DeliveryInstructions>Ship only complete order.</aw:DeliveryInstructions>  
    <aw:Item PartNum="LIT-01">  
      <aw:ProductID>Litware Networking Card</aw:ProductID>  
      <aw:Qty>1</aw:Qty>  
      <aw:Price>20.99</aw:Price>  
    </aw:Item>  
    <aw:Item PartNum="LIT-25">  
      <aw:ProductID>Litware 17in LCD Monitor</aw:ProductID>  
      <aw:Qty>1</aw:Qty>  
      <aw:Price>199.99</aw:Price>  
    </aw:Item>  
  </aw:PurchaseOrder>  
</PurchaseOrders>  
```