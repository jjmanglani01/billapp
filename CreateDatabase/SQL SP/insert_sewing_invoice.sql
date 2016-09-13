CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_sewing_invoice`(IN SewingWorkerID INT UNSIGNED,
    IN pBillAmount DECIMAL(11 , 2 ),
    IN BillDate DATE)
BEGIN
	UPDATE SewingWorkers SET BillAmount = BillAmount + pBillAmount 
	WHERE SewingWorkerID = SewingWorkerID;
	INSERT INTO SewingInvoices(SewingWorkerID,BillAmount,BillDate)
		VALUES (SewingWorkerID,pBillAmount,BillDate);
END