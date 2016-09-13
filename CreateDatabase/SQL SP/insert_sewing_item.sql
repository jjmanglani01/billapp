CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_sewing_item`(IN SewingName VARCHAR(100),
    IN FabricItemID INT UNSIGNED,
    IN Quantity INT,
    IN UnitPrice DECIMAL(11 , 2 ),
    IN Color VARCHAR(15))
BEGIN
	INSERT INTO SewingItems(SewingName,FabricItemID,Quantitiy,UnitPrice,Color)
		VALUES (SewingName,FabricItemID,Quantitiy,UnitPrice,Color);
END