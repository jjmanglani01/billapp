CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_press_invoice_item`(IN PressInvoiceID INT UNSIGNED,
    IN PressItemID INT UNSIGNED,
    IN InvoiceQuantity INT UNSIGNED)
BEGIN
	UPDATE PressItems SET Quantity = Quantity - InvoiceQuantity
    WHERE PressItemID = PressItemID;
	INSERT INTO PressInvoiceItems(PressInvoiceID,PressItemID,Quantity,UnitPrice)
    SELECT PressInvoiceID,PressItemID,InvoiceQuantity,PressItems.UnitPrice
    FROM PressItems WHERE PressItemID = PressItemID;
END