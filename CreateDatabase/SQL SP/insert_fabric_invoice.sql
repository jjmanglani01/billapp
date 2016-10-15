CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_fabric_invoice`(IN FabricSupplierID INT UNSIGNED,
    IN pBillAmount DECIMAL(11 , 2 ),
    IN BillDate VARCHAR(20),
    OUT FabricInvoiceID INT UNSIGNED)
BEGIN
	UPDATE FabricSuppliers SET BillAmount = BillAmount + pBillAmount 
	WHERE FabricSupplierID = FabricSupplierID;
	INSERT INTO FabricInvoices(FabricSupplierID,BillAmount,BillDate)
		VALUES (FabricSupplierID,pBillAmount,STR_TO_DATE(BillDate,'%Y%m%d %h%i')) 
        ON DUPLICATE KEY UPDATE 
        FabircSupplierID = FabricSupplierID,BillAmount=pBillAmount,BillDate=STR_TO_DATE(BillDate,'%Y%m%d %h%i');
	SELECT LAST_INSERT_ID() INTO FabricInvoiceID;
END