CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_press_payment`(IN PressWorkerID INT UNSIGNED,IN PaymentType ENUM('Cash', 'Cheque', 'Net Banking'),
    IN PaymentDate DATE,
    IN Amount DECIMAL(11 , 2 ),
    IN ChequeNo VARCHAR(10),
    IN ChequeDate DATE)
BEGIN
	CALL insert_payment(PaymentType,PaymentDate,Amount,@PaymentID);
	IF PaymentType = 'Cheque' THEN
		CALL insert_cheque_payment(PaymentID,ChequeNo,ChequeDate);
	END IF;
    INSERT INTO PressPayments(PressWorkerID,PaymentID)
		VALUES(PressWorkerID,@PaymentID);
	UPDATE PressWorkers SET PaidAmount = PadiAmount + Amount
		WHERE PressWorkerID = PressWorkerID;
END