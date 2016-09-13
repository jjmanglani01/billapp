CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_fabric_supplier_phonenumber`(IN FabricSupplierID INT UNSIGNED,IN PhoneType ENUM('Work','Home','Temporary','Other'),IN PhoneDescription VARCHAR(30),IN PhoneNumber VARCHAR(13))
BEGIN
	CALL insert_phonetypes(PhoneType,PhoneDescription,PhoneNumber,@PhoneID);
    INSERT INTO FabricSupplierPhones(FabricSupplierID,PhoneID) 
		VALUES (FabricSupplierID,@PhoneID);
END