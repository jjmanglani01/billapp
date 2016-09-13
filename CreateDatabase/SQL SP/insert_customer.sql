CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_customer`(IN CustomerName VARCHAR(100),IN Address1 VARCHAR(200),IN Address2 VARCHAR(200),
	IN City VARCHAR(20),IN State VARCHAR(15),IN Email VARCHAR(50),OUT CustomerID INT UNSIGNED)
BEGIN
	INSERT INTO Customers(CustomerName, Address1, Address2, City, State, Email)
		values (CustomerName, Address1, Address2, City, State, Email);
	SELECT LAST_INSERT_ID() INTO CustomerID;
END