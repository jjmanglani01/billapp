CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_fabric_invoice_item`(IN FabricInvoiceID INT UNSIGNED,
    IN FabricItemID INT UNSIGNED,
    IN InvoiceQuantity DECIMAL,
    IN UnitPrice DECIMAL(11,2),
    IN bAdd BOOL)
BEGIN
	UPDATE FabricItems SET Quantity = IF(bADD, Quantity + InvoiceQuantity,Quantity),UnitPrice = UnitPrice WHERE FabricItemID = FabricItemID;
	INSERT INTO FabricInvoiceItems(FabricInvoiceID,FabricItemID,Quantity,UnitPrice)
    VALUES (FabricInvoiceID,FabricItemID,InvoiceQuantity,UnitPrice);
END