CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_cheque_payment`(IN PaymentID BIGINT UNSIGNED,
    IN ChequeNo VARCHAR(10),
    IN ChequeDate DATE)
BEGIN
	INSERT INTO ChequePayments(PaymentID,ChequeNo,ChequeDate)
		VALUES (PaymentID,ChequeNo,ChequeDate);
END