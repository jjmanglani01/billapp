CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_customer_invoice_item`(IN CustomerInvoiceID INT UNSIGNED,
    IN ItemID INT UNSIGNED,
    IN InvoiceQuantity INT UNSIGNED)
BEGIN
	UPDATE Items SET Quantity = Quantity - InvoiceQuantity
    WHERE ItemID = ItemID;
	INSERT INTO CustomerInvoiceItems(CustomerInvoiceID,CustomerItemID,Quantity,UnitPrice)
    SELECT CustomerInvoiceID,CustomerItemID,InvoiceQuantity,Items.UnitPrice
    FROM Items WHERE ItemID = ItemID;
END