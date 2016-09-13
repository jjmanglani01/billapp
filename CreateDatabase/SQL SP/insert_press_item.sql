CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_press_item`(IN PressName VARCHAR(100),
    IN Quantity INT,
    IN UnitPrice DECIMAL(11 , 2 ),
    IN Color VARCHAR(15),
    IN WashingItemID INT UNSIGNED)
BEGIN
	INSERT INTO PressItems(PressName,Quantity,UnitPrice,Color,WashingItemID)
		VALUES(PressName,Quantity,UnitPrice,Color,WashingItemID);
END