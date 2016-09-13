CREATE DEFINER=`root`@`localhost` PROCEDURE `insert_customer_invoice`(IN CustomerID INT UNSIGNED,
    IN pBillAmount DECIMAL(11 , 2 ),
    IN BillDate DATE)
BEGIN
	UPDATE Customers SET BillAmount = BillAmount + pBillAmount
    WHERE CustomerID = CustomerID;
	INSERT INTO CustomerInvoices(CustomerID,BillAmount,BillDate)
		VALUES (CustomerID,pBillAmount,BillDate);
END