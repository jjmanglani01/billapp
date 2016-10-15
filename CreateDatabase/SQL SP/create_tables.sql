CREATE DEFINER=`root`@`localhost` PROCEDURE `create_tables`()
BEGIN
CREATE TABLE IF NOT EXISTS `PhoneTypes`(
	PhoneID BIGINT UNSIGNED AUTO_INCREMENT,
	PhoneType ENUM('Work','Home','Temporary','Other') default 'Other',
    PhoneDescription VARCHAR(30),
    PhoneNumber VARCHAR(13),
    PRIMARY KEY (PhoneID)
)ENGINE=InnoDB;
CREATE TABLE IF NOT EXISTS `Payments` (
    PaymentID BIGINT UNSIGNED AUTO_INCREMENT,
    PaymentType ENUM('Cash', 'Cheque', 'Net Banking') DEFAULT 'Cash',
    PaymentDate DATE,
    Amount DECIMAL(11 , 2 ),
    PRIMARY KEY (PaymentID)
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `ChequePayments` (
    PaymentID BIGINT UNSIGNED,
    ChequeNo VARCHAR(10),
    ChequeDate DATE,
    INDEX (PaymentID),
    FOREIGN KEY (PaymentID)
        REFERENCES Payments (PaymentID)
        ON DELETE CASCADE ON UPDATE CASCADE
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `FabricSuppliers` (
    FabricSupplierID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    SupplierName VARCHAR(100) NOT NULL,
    Address1 VARCHAR(200),
    Address2 VARCHAR(200),
    City VARCHAR(20),
    State VARCHAR(15),
    Email VARCHAR(50),
    BillAmount DECIMAL(11 , 2 ) DEFAULT 0,
    PaidAmount DECIMAL(11 , 2 ) DEFAULT 0,
    PRIMARY KEY (FabricSupplierID)
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `FabricSupplierPhones` (
    FabricSupplierID INT UNSIGNED,
    PhoneID BIGINT UNSIGNED,
    INDEX (FabricSupplierID),
    FOREIGN KEY (FabricSupplierID)
        REFERENCES FabricSuppliers (FabricSupplierID)
        ON DELETE CASCADE ON UPDATE CASCADE,
    INDEX (PhoneID),
    FOREIGN KEY (PhoneID)
        REFERENCES PhoneTypes (PhoneID)
        ON DELETE CASCADE ON UPDATE CASCADE
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `FabricItems` (
    FabricItemID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    FabricName VARCHAR(100) NOT NULL,
    ShortcutName VARCHAR(5),
    Quantity DECIMAL DEFAULT 0,
    UnitPrice DECIMAL(11 , 2 ) NOT NULL DEFAULT 0,
    Color VARCHAR(15) DEFAULT NULL,
    FabricType VARCHAR(15) DEFAULT NULL,
    PRIMARY KEY (FabricItemID)
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `FabricInvoices` (
    FabricInvoiceID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    FabricSupplierID INT UNSIGNED,
    BillAmount DECIMAL(11 , 2 ) NOT NULL DEFAULT 0,
    BillDate DATETIME NOT NULL,
    PRIMARY KEY (FabricInvoiceID),
    INDEX (FabricSupplierID),
    FOREIGN KEY (FabricSupplierID)
        REFERENCES FabricSuppliers (FabricSupplierID)
        ON UPDATE CASCADE ON DELETE CASCADE
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `FabricPayments` (
    FabricSupplierID INT UNSIGNED,
    PaymentID BIGINT UNSIGNED,
    INDEX (FabricSupplierID),
    FOREIGN KEY (FabricSupplierID)
        REFERENCES FabricSuppliers (FabricSupplierID)
        ON DELETE CASCADE ON UPDATE CASCADE,
    INDEX (PaymentID),
    FOREIGN KEY (PaymentID)
        REFERENCES Payments (PaymentID)
        ON DELETE CASCADE ON UPDATE CASCADE
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `FabricInvoiceItems` (
    FabricInvoiceID INT UNSIGNED NOT NULL,
    FabricItemID INT UNSIGNED NOT NULL,
    Quantity DECIMAL DEFAULT 0,
    UnitPrice DECIMAL(11 , 2 ),
    PRIMARY KEY (FabricInvoiceID , FabricItemID),
    INDEX (FabricItemID),
    FOREIGN KEY (FabricItemID)
        REFERENCES FabricItems (FabricItemID)
        ON UPDATE CASCADE ON DELETE CASCADE,
    INDEX (FabricInvoiceID),
    FOREIGN KEY (FabricInvoiceID)
        REFERENCES FabricInvoices (FabricInvoiceID)
        ON UPDATE CASCADE ON DELETE CASCADE
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `SewingWorkers` (
    SewingWorkerID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    WorkerName VARCHAR(100) NOT NULL,
    Email VARCHAR(50) DEFAULT NULL,
    Address1 VARCHAR(200) DEFAULT NULL,
    Address2 VARCHAR(200),
    City VARCHAR(20),
    State VARCHAR(15),
    BillAmount DECIMAL(11 , 2 ) DEFAULT 0,
    PaidAmount DECIMAL(11 , 2 ) DEFAULT 0,
    PRIMARY KEY (SewingWorkerID)
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `SewingWorkerPhones` (
    SewingWorkerID INT UNSIGNED,
    PhoneID BIGINT UNSIGNED,
    INDEX (SewingWorkerID),
    FOREIGN KEY (SewingWorkerID)
        REFERENCES SewingWorkers (SewingWorkerID)
        ON DELETE CASCADE ON UPDATE CASCADE,
    INDEX (PhoneID),
    FOREIGN KEY (PhoneID)
        REFERENCES PhoneTypes (PhoneID)
        ON DELETE CASCADE ON UPDATE CASCADE
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `SewingItems` (
    SewingItemID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    SewingName VARCHAR(100) NOT NULL,
    FabricItemID INT UNSIGNED NOT NULL,
    Quantity INT NOT NULL DEFAULT 0,
    UnitPrice DECIMAL(11 , 2 ) NOT NULL DEFAULT 0,
    Color VARCHAR(15) DEFAULT NULL,
    QuantityFabricItem DECIMAL,
    PRIMARY KEY (SewingItemID),
    INDEX (FabricItemID),
    FOREIGN KEY (FabricItemID)
        REFERENCES FabricItems (FabricItemID)
        ON UPDATE CASCADE ON DELETE CASCADE
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `SewingInvoices` (
    SewingInvoiceID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    SewingWorkerID INT UNSIGNED,
    BillAmount DECIMAL(11 , 2 ) NOT NULL DEFAULT 0,
    BillDate DATE NOT NULL,
    PRIMARY KEY (SewingInvoiceID),
    INDEX (SewingWorkerID),
    FOREIGN KEY (SewingWorkerID)
        REFERENCES SewingWorkers (SewingWorkerID)
        ON UPDATE CASCADE ON DELETE CASCADE
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `SewingPayments` (
    SewingWorkerID INT UNSIGNED,
    PaymentID BIGINT UNSIGNED,
    INDEX (SewingWorkerID),
    FOREIGN KEY (SewingWorkerID)
        REFERENCES SewingWorkers (SewingWorkerID)
        ON DELETE CASCADE ON UPDATE CASCADE,
    INDEX (PaymentID),
    FOREIGN KEY (PaymentID)
        REFERENCES Payments (PaymentID)
        ON DELETE CASCADE ON UPDATE CASCADE
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `SewingInvoiceItems` (
    SewingInvoiceID INT UNSIGNED NOT NULL,
    SewingItemID INT UNSIGNED NOT NULL,
    Quantity INT UNSIGNED DEFAULT 0,
    UnitPrice DECIMAL(11 , 2 ),
    PRIMARY KEY (SewingInvoiceID , SewingItemID),
    INDEX (SewingItemID),
    FOREIGN KEY (SewingItemID)
        REFERENCES SewingItems (SewingItemID)
        ON UPDATE CASCADE ON DELETE CASCADE,
    INDEX (SewingInvoiceID),
    FOREIGN KEY (SewingInvoiceID)
        REFERENCES SewingInvoices (SewingInvoiceID)
        ON UPDATE CASCADE ON DELETE CASCADE
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `WashingWorkers` (
    WashingWorkerID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    WorkerName VARCHAR(100) NOT NULL,
    Email VARCHAR(50),
    Address1 VARCHAR(200),
    Address2 VARCHAR(200),
    City VARCHAR(20),
    State VARCHAR(15),
    BillAmount DECIMAL(11 , 2 ) DEFAULT 0,
    PaidAmount DECIMAL(11 , 2 ) DEFAULT 0,
    PRIMARY KEY (WashingWorkerID)
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `WashingWorkerPhones` (
    WashingWorkerID INT UNSIGNED,
    PhoneID BIGINT UNSIGNED,
    INDEX (WashingWorkerID),
    FOREIGN KEY (WashingWorkerID)
        REFERENCES WashingWorkers (WashingWorkerID)
        ON DELETE CASCADE ON UPDATE CASCADE,
    INDEX (PhoneID),
    FOREIGN KEY (PhoneID)
        REFERENCES PhoneTypes (PhoneID)
        ON DELETE CASCADE ON UPDATE CASCADE
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `WashingItems` (
    WashingItemID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    WashingName VARCHAR(100) NOT NULL,
    Quantity INT NOT NULL DEFAULT 0,
    UnitPrice DECIMAL(11 , 2 ) NOT NULL DEFAULT 0,
    Color VARCHAR(15) DEFAULT NULL,
    SewingItemID INT UNSIGNED NOT NULL,
    INDEX (SewingItemID),
    FOREIGN KEY (SewingItemID)
        REFERENCES SewingItems (SewingItemID)
        ON UPDATE CASCADE ON DELETE CASCADE,
    PRIMARY KEY (WashingItemID)
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `WashingInvoices` (
    WashingInvoiceID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    WashingWorkerID INT UNSIGNED,
    BillAmount DECIMAL(11 , 2 ) NOT NULL DEFAULT 0,
    BillDate DATE NOT NULL,
    PRIMARY KEY (WashingInvoiceID),
    INDEX (WashingWorkerID),
    FOREIGN KEY (WashingWorkerID)
        REFERENCES WashingWorkers (WashingWorkerID)
        ON UPDATE CASCADE ON DELETE CASCADE
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `WashingPayments` (
    WashingWorkerID INT UNSIGNED,
    PaymentID BIGINT UNSIGNED,
    INDEX (WashingWorkerID),
    FOREIGN KEY (WashingWorkerID)
        REFERENCES WashingWorkers (WashingWorkerID)
        ON DELETE CASCADE ON UPDATE CASCADE,
    INDEX (PaymentID),
    FOREIGN KEY (PaymentID)
        REFERENCES Payments (PaymentID)
        ON DELETE CASCADE ON UPDATE CASCADE
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `WashingInvoiceItems` (
    WashingInvoiceID INT UNSIGNED NOT NULL,
    WashingItemID INT UNSIGNED NOT NULL,
    Quantity INT UNSIGNED DEFAULT 0,
    UnitPrice DECIMAL(11 , 2 ),
    PRIMARY KEY (WashingInvoiceID , WashingItemID),
    INDEX (WashingItemID),
    FOREIGN KEY (WashingItemID)
        REFERENCES WashingItems (WashingItemID)
        ON UPDATE CASCADE ON DELETE CASCADE,
    INDEX (WashingInvoiceID),
    FOREIGN KEY (WashingInvoiceID)
        REFERENCES WashingInvoices (WashingInvoiceID)
        ON UPDATE CASCADE ON DELETE CASCADE
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `PressWorkers` (
    PressWorkerID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    WorkerName VARCHAR(100) NOT NULL,
    Email VARCHAR(50),
    Address1 VARCHAR(200),
    Address2 VARCHAR(200),
    City VARCHAR(20),
    State VARCHAR(15),
    BillAmount DECIMAL(11 , 2 ) DEFAULT 0,
    PaidAmount DECIMAL(11 , 2 ) DEFAULT 0,
    PRIMARY KEY (PressWorkerID)
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `PressWorkerPhones` (
    PressWorkerID INT UNSIGNED,
    PhoneID BIGINT UNSIGNED,
    INDEX (PressWorkerID),
    FOREIGN KEY (PressWorkerID)
        REFERENCES PressWorkers (PressWorkerID)
        ON DELETE CASCADE ON UPDATE CASCADE,
    INDEX (PhoneID),
    FOREIGN KEY (PhoneID)
        REFERENCES PhoneTypes (PhoneID)
        ON DELETE CASCADE ON UPDATE CASCADE
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `PressItems` (
    PressItemID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    PressName VARCHAR(100) NOT NULL,
    Quantity INT NOT NULL DEFAULT 0,
    UnitPrice DECIMAL(11 , 2 ) NOT NULL DEFAULT 0,
    Color VARCHAR(15) DEFAULT NULL,
    WashingItemID INT UNSIGNED NOT NULL,
    INDEX (WashingItemID),
    FOREIGN KEY (WashingItemID)
        REFERENCES WashingItems (WashingItemID)
        ON UPDATE CASCADE ON DELETE CASCADE,
    PRIMARY KEY (PressItemID)
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `PressInvoices` (
    PressInvoiceID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    PressWorkerID INT UNSIGNED,
    BillAmount DECIMAL(11 , 2 ) NOT NULL DEFAULT 0,
    BillDate DATE NOT NULL,
    PRIMARY KEY (PressInvoiceID),
    INDEX (PressWorkerID),
    FOREIGN KEY (PressWorkerID)
        REFERENCES PressWorkers (PressWorkerID)
        ON UPDATE CASCADE ON DELETE CASCADE
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `PressPayments` (
    PressWorkerID INT UNSIGNED,
    PaymentID BIGINT UNSIGNED,
    INDEX (PressWorkerID),
    FOREIGN KEY (PressWorkerID)
        REFERENCES PressWorkers (PressWorkerID)
        ON DELETE CASCADE ON UPDATE CASCADE,
    INDEX (PaymentID),
    FOREIGN KEY (PaymentID)
        REFERENCES Payments (PaymentID)
        ON DELETE CASCADE ON UPDATE CASCADE
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `PressInvoiceItems` (
    PressInvoiceID INT UNSIGNED NOT NULL,
    PressItemID INT UNSIGNED NOT NULL,
    Quantity INT UNSIGNED DEFAULT 0,
    UnitPrice DECIMAL(11 , 2 ),
    PRIMARY KEY (PressInvoiceID , PressItemID),
    INDEX (PressItemID),
    FOREIGN KEY (PressItemID)
        REFERENCES PressItems (PressItemID)
        ON UPDATE CASCADE ON DELETE CASCADE,
    INDEX (PressInvoiceID),
    FOREIGN KEY (PressInvoiceID)
        REFERENCES PressInvoices (PressInvoiceID)
        ON UPDATE CASCADE ON DELETE CASCADE
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `Items` (
    ItemID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    ItemName VARCHAR(50),
    Quantity INT NOT NULL DEFAULT 0,
    UnitPrice DECIMAL(11 , 2 ) NOT NULL DEFAULT 0,
    Color VARCHAR(10),
    Size VARCHAR(10),
    BrandMake VARCHAR(20),
    BrandModel VARCHAR(20),
    PRIMARY KEY (ItemID),
    PressItemID INT UNSIGNED NOT NULL,
    INDEX (PressItemID),
    FOREIGN KEY (PressItemID)
        REFERENCES PressItems (PressItemID)
        ON UPDATE CASCADE ON DELETE CASCADE
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `ItemDetail` (
    ItemID INT UNSIGNED NOT NULL,
    Size VARCHAR(10),
    INDEX (ItemID),
    FOREIGN KEY (ItemID)
        REFERENCES Items (ItemID)
        ON UPDATE CASCADE ON DELETE CASCADE
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `Customers` (
    CustomerID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    CustomerName VARCHAR(100) NOT NULL,
    Email VARCHAR(50),
    Address1 VARCHAR(200),
    Address2 VARCHAR(200),
    City VARCHAR(20),
    State VARCHAR(15),
    BillAmount DECIMAL(11 , 2 ) DEFAULT 0,
    PaidAmount DECIMAL(11 , 2 ) DEFAULT 0,
    PRIMARY KEY (CustomerID)
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `CustomerPhones` (
    CustomerID INT UNSIGNED,
    PhoneID BIGINT UNSIGNED,
    INDEX (CustomerID),
    FOREIGN KEY (CustomerID)
        REFERENCES Customers (CustomerID)
        ON DELETE CASCADE ON UPDATE CASCADE,
    INDEX (PhoneID),
    FOREIGN KEY (PhoneID)
        REFERENCES PhoneTypes (PhoneID)
        ON DELETE CASCADE ON UPDATE CASCADE
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `CustomerInvoices` (
    CustomerInvoiceID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    CustomerID INT UNSIGNED,
    BillAmount DECIMAL(11 , 2 ) NOT NULL DEFAULT 0,
    BillDate DATE NOT NULL,
    PRIMARY KEY (CustomerInvoiceID),
    INDEX (CustomerID),
    FOREIGN KEY (CustomerID)
        REFERENCES Customers (CustomerID)
        ON UPDATE CASCADE ON DELETE CASCADE
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `CustomerPayments` (
    CustomerID INT UNSIGNED,
    PaymentID BIGINT UNSIGNED,
    INDEX (CustomerID),
    FOREIGN KEY (CustomerID)
        REFERENCES Customers (CustomerID)
        ON DELETE CASCADE ON UPDATE CASCADE,
    INDEX (PaymentID),
    FOREIGN KEY (PaymentID)
        REFERENCES Payments (PaymentID)
        ON DELETE CASCADE ON UPDATE CASCADE
)  ENGINE=INNODB;
CREATE TABLE IF NOT EXISTS `CustomerInvoiceItems` (
    CustomerInvoiceID INT UNSIGNED NOT NULL,
    ItemID INT UNSIGNED NOT NULL,
    Quantity INT UNSIGNED DEFAULT 0,
    UnitPrice DECIMAL(11 , 2 ),
    PRIMARY KEY (CustomerInvoiceID , ItemID),
    INDEX (ItemID),
    FOREIGN KEY (ItemID)
        REFERENCES Items (ItemID)
        ON UPDATE CASCADE ON DELETE CASCADE,
    INDEX (CustomerInvoiceID),
    FOREIGN KEY (CustomerInvoiceID)
        REFERENCES CustomerInvoices (CustomerInvoiceID)
        ON UPDATE CASCADE ON DELETE CASCADE
)  ENGINE=INNODB;
END