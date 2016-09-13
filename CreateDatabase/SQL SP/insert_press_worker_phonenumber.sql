CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_press_worker_phonenumber`(IN PressWorkerID INT UNSIGNED,IN PhoneType ENUM('Work','Home','Temporary','Other'),IN PhoneDescription VARCHAR(30),IN PhoneNumber VARCHAR(13))
BEGIN
	CALL insert_phonetypes(PhoneType,PhoneDescription,PhoneNumber,@PhoneID);
    INSERT INTO PressWorkerPhones(PressWorkerID,PhoneID) 
		VALUES (PressWorkerID,@PhoneID);
END