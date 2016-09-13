CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_press_invoice`(IN PressWorkerID INT UNSIGNED,
    IN pBillAmount DECIMAL(11 , 2 ),
    IN BillDate DATE)
BEGIN
	UPDATE PressWorkers SET BillAmount = BillAmount + pBillAmount
    WHERE PressWorkerID = PressWorkerID;
	INSERT INTO PressInvoices(PressWorkerID,BillAmount,BillDate)
		VALUES(PressWorkerID,pBillAmount,BillDate);
END