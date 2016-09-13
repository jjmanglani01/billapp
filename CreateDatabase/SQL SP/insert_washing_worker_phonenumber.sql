CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_washing_worker_phonenumber`(IN WashingWorkerID INT UNSIGNED,IN PhoneType ENUM('Work','Home','Temporary','Other'),IN PhoneDescription VARCHAR(30),IN PhoneNumber VARCHAR(13))
BEGIN
	CALL insert_phonetypes(PhoneType,PhoneDescription,PhoneNumber,@PhoneID);
    INSERT INTO WashingWorkerPhones(WashingWorkerID,PhoneID) 
		VALUES (WashingWorkerID,@PhoneID);
END