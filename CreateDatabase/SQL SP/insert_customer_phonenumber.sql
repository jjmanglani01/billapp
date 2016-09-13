CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_customer_phonenumber`(IN CustomerID INT UNSIGNED,IN PhoneType ENUM('Work','Home','Temporary','Other'),IN PhoneDescription VARCHAR(30),IN PhoneNumber VARCHAR(13))
BEGIN
	CALL insert_phonetypes(PhoneType,PhoneDescription,PhoneNumber,@PhoneID);
    INSERT INTO CustomerPhones(CustomerID,PhoneID) 
		VALUES (CustomerID,@PhoneID);
END