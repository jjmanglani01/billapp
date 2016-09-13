CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_washing_invoice_item`(IN WashingInvoiceID INT UNSIGNED,
    IN WashingItemID INT UNSIGNED,
    IN InvoiceQuantity INT UNSIGNED)
BEGIN
	UPDATE WashingItems SET Quantity = Quantity - InvoiceQuantity
    WHERE WashingItemID = WashingItemID;
	INSERT INTO WashingInvoiceItems(WashingInvoiceID,WashingItemID,Quantity,UnitPrice)
    SELECT WashingInvoiceID,WashingItemID,InvoiceQuantity,WashingItems.UnitPrice
    FROM WashingItems WHERE WashingItemID = WashingItemID;
END