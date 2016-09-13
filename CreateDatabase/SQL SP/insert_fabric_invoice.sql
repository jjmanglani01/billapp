CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_fabric_invoice`(IN FabricSupplierID INT UNSIGNED,
    IN pBillAmount DECIMAL(11 , 2 ),
    IN BillDate DATE)
BEGIN
	UPDATE FabricSuppliers SET BillAmount = BillAmount + pBillAmount 
	WHERE FabricSupplierID = FabricSupplierID;
	INSERT INTO FabricInvoices(FabricSupplierID,BillAmount,BillDate)
		VALUES (FabricSupplierID,pBillAmount,BillDate);
END