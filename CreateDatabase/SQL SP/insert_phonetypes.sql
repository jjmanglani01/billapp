CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_phonetypes`(IN PhoneType ENUM('Work','Home','Temporary','Other'),IN PhoneDescription VARCHAR(30),IN PhoneNumber VARCHAR(13),OUT IncrementID BIGINT UNSIGNED)
BEGIN
	INSERT INTO PhoneTypes(PhoneType,PhoneDescription,PhoneNumber) 
		VALUES (PhoneType,PhoneDescription,PhoneNumber);
	SELECT LAST_INSERT_ID() INTO IncrementID;
END