CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_fabric_payment`(IN FabricSupplierID INT UNSIGNED,
	IN PaymentType ENUM('Cash', 'Cheque', 'Net Banking'),
    IN PaymentDate DATETIME,
    IN Amount DECIMAL(11 , 2 ),
    IN ChequeNo VARCHAR(10),
    IN ChequeDate DATETIME)
BEGIN
	CALL insert_payment(PaymentType,PaymentDate,Amount,@PaymentID);
	IF PaymentType = 'Cheque' THEN
		CALL insert_cheque_payment(PaymentID,ChequeNo,ChequeDate);
	END IF;
    INSERT INTO FabricPayments(FabricSupplierID,PaymentID)
		VALUES(FabricSupplierID,@PaymentID);
	UPDATE FabricSuppliers 
SET 
    PaidAmount = PaidAmount + Amount
WHERE
    FabricSuppliers.FabricSupplierID = FabricSupplierID;
END