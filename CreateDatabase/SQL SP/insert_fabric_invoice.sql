CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_fabric_invoice`(IN FabricSupplierID INT UNSIGNED,
    IN pBillAmount DECIMAL(11 , 2 ),
    IN BillDate DATETIME,
    OUT FabricInvoiceID INT UNSIGNED)
BEGIN
	UPDATE FabricSuppliers SET BillAmount = BillAmount + pBillAmount 
	WHERE FabricSupplierID = FabricSupplierID;
	INSERT INTO FabricInvoices(FabricSupplierID,BillAmount,BillDate)
		VALUES (FabricSupplierID,pBillAmount,BillDate);
	SELECT LAST_INSERT_ID() INTO FabricInvoiceID;
END