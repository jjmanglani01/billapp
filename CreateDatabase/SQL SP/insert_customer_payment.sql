CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_customer_payment`(IN CustomerID INT UNSIGNED,IN PaymentType ENUM('Cash', 'Cheque', 'Net Banking'),
    IN PaymentDate DATE,
    IN Amount DECIMAL(11 , 2 ),
    IN ChequeNo VARCHAR(10),
    IN ChequeDate DATE)
BEGIN
	CALL insert_payment(PaymentType,PaymentDate,Amount,@PaymentID);
	IF PaymentType = 'Cheque' THEN
		CALL insert_cheque_payment(PaymentID,ChequeNo,ChequeDate);
	END IF;
    INSERT INTO CustomerPayments(CustomerID,PaymentID)
		VALUES(CustomerID,@PaymentID);
	UPDATE Customers SET PaidAmount = PadiAmount + Amount
		WHERE CustomerID = CustomerID;
END