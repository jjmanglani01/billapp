CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_item`(IN ItemName VARCHAR(50),
    IN Quantity INT,
    IN UnitPrice DECIMAL(11 , 2 ),
    IN Color VARCHAR(10),
    IN Size VARCHAR(10),
    IN BrandMake VARCHAR(20),
    IN BrandModel VARCHAR(20))
BEGIN
	INSERT INTO Items(ItemName,Quantity,UnitPrice,Color,Size,BrandMake,BrandModel)
		VALUES (ItemName,Quantity,UnitPrice,Color,Size,BrandMake,BrandModel);
END