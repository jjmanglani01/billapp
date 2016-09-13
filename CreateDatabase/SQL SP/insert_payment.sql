CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_payment`(IN PaymentType ENUM('Cash', 'Cheque', 'Net Banking'),
    IN PaymentDate DATE,
    IN Amount DECIMAL(11 , 2 ),OUT PaymentID BIGINT UNSIGNED)
BEGIN
	INSERT INTO Payments(PaymentType,PaymentDate,Amount)
		VALUES (PaymentType,PaymentDate,Amount);
	SELECT LAST_INSERT_ID() INTO PaymentID;
END