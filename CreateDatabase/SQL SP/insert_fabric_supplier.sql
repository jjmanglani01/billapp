CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_fabric_supplier`(IN SupplierName VARCHAR(100),IN Address1 VARCHAR(200),IN Address2 VARCHAR(200),
	IN City VARCHAR(20),IN State VARCHAR(15),IN Email VARCHAR(50),OUT FabricSupplierID INT UNSIGNED)
BEGIN
	INSERT INTO FabricSuppliers(SupplierName, Address1, Address2, City, State, Email)
		values (supplierName, Address1, Address2, City, State, Email);
	SELECT LAST_INSERT_ID() INTO FabricSupplierID;
END