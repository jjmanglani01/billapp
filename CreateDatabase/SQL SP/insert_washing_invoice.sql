CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_washing_invoice`(IN WashingWorkerID INT UNSIGNED,
    IN pBillAmount DECIMAL(11 , 2 ),
    IN BillDate DATE)
BEGIN
	UPDATE WashingWorkers SET BillAmount = BillAmount + pBillAmount
	WHERE WashingWorkerID = WashingWorkerID;
	INSERT INTO WashingWorkerInvoices(WashigWorkerID,BillAmount,BillDate)
		VALUES (WashigWorkerID,pBillAmount,BillDate);
END