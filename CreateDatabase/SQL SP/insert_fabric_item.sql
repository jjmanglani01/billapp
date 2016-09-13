CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_fabric_item`(IN FabricName VARCHAR(100),
    IN Quantity DECIMAL,
    IN UnitPrice DECIMAL(11 , 2 ),
    IN Color VARCHAR(15),
    IN FabricType VARCHAR(15))
BEGIN
	INSERT INTO FabricItems(FabricName,Quantity,UnitPrice,Color,FabricType)
		VALUES (FabricName,Quantity,UnitPrice,Color,FabricType);
END