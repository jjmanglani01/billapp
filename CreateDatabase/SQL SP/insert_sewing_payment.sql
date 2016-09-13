CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_sewing_payment`(IN SewingWorkerID INT UNSIGNED,IN PaymentType ENUM('Cash', 'Cheque', 'Net Banking'),
    IN PaymentDate DATE,
    IN Amount DECIMAL(11 , 2 ),
    IN ChequeNo VARCHAR(10),
    IN ChequeDate DATE)
BEGIN
	CALL insert_payment(PaymentType,PaymentDate,Amount,@PaymentID);
	IF PaymentType = 'Cheque' THEN
		CALL insert_cheque_payment(PaymentID,ChequeNo,ChequeDate);
	END IF;
    INSERT INTO SewingPayments(SewingWorkerID,PaymentID)
		VALUES(SewingWorkerID,@PaymentID);
	UPDATE SewingWorkers SET PaidAmount = PadiAmount + Amount
		WHERE SewingWorkerID = SewingWorkerID;
END