CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_sewing_invoice_item`(IN SewingInvoiceID INT UNSIGNED,
    IN SewingItemID INT UNSIGNED,
    IN InvoiceQuantity INT UNSIGNED,
    IN UnitPrice DECIMAL(11 , 2 ))
BEGIN
	UPDATE SewingItems SET Quantity = Quantity - InvoiceQuantity 
    WHERE SewingItemID = SewingItemID;
	INSERT INTO SewingInvoiceItems(SewingInvoiceID,SewingItemID,Quantity,UnitPrice)
    SELECT SewingInvoiceID,SewingItemID,InvoiceQuantity,SewingItems.UnitPrice
    FROM SewingItems WHERE SewingItemID = SewingItemID;
END