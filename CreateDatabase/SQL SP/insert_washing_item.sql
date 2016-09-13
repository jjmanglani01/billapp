CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_washing_item`(IN WashingName VARCHAR(100),
    IN Quantity INT,
    IN UnitPrice DECIMAL(11 , 2 ),
    IN Color VARCHAR(15),
    IN SewingItemID INT UNSIGNED)
BEGIN
	INSERT INTO WashingItems(WashingName,Quantity,UnitPrice,Color,SewingItemID)
		VALUES (WashingName,Quantity,UnitPrice,Color,SewingItemID);
END