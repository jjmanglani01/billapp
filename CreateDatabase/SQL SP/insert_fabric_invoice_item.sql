CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_fabric_invoice_item`(IN FabricInvoiceID INT UNSIGNED,
    IN FabricItemID INT UNSIGNED,
    IN InvoiceQuantity INT UNSIGNED)
BEGIN
	UPDATE FabricItems SET Quantity = Quantity - InvoiceQuantity WHERE FabricItemID = FabricItemID;
	INSERT INTO FabricInvoiceItems(FabricInvoiceID,FabricItemID,Quantity,UnitPrice)
    SELECT FabricInvoiceID,FabricItemID,InvoiceQuantity,FabricItems.UnitPrice
    FROM FabricItems WHERE FabricItemID = FabricItemID;
END