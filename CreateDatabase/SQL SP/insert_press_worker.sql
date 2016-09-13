CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_press_worker`(IN WorkerName VARCHAR(100),IN Address1 VARCHAR(200),IN Address2 VARCHAR(200),
	IN City VARCHAR(20),IN State VARCHAR(15),IN Email VARCHAR(50),OUT PressWorkerID INT UNSIGNED)
BEGIN
	INSERT INTO PressWorkers(WorkerName, Address1, Address2, City, State, Email)
		values (WorkerName, Address1, Address2, City, State, Email);
	SELECT LAST_INSERT_ID() INTO PressWorkerID;
END