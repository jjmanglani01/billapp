CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_sewing_worker_phonenumber`(IN SewingWorkerID INT UNSIGNED,IN PhoneType ENUM('Work','Home','Temporary','Other'),IN PhoneDescription VARCHAR(30),IN PhoneNumber VARCHAR(13))
BEGIN
	CALL insert_phonetypes(PhoneType,PhoneDescription,PhoneNumber,@PhoneID);
    INSERT INTO SewingWorkerPhones(SewingWorkerID,PhoneID) 
		VALUES (SewingWorkerID,@PhoneID);
END