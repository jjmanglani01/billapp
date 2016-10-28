#include "stdafx.h"
#include "FabricInvoiceService.h"


FabricInvoiceService::FabricInvoiceService()
{
}


FabricInvoiceService::~FabricInvoiceService()
{
}

unsigned int FabricInvoiceService::insert(unsigned int iFabricSupplierId, double dBillAmount, std::string strDate)
{
	unsigned int retID = 0;
	DataAccess::DataAccessManager* oDataAccess = DataAccess::DataAccessManager::getInstance();
	try {
		oDataAccess->connect();
		std::unique_ptr < sql::Connection>& pCon = oDataAccess->getConnection();
		std::unique_ptr< sql::ResultSet > pRes;
		std::unique_ptr< sql::Statement > pStmt = std::unique_ptr<sql::Statement>(pCon->createStatement());

		std::unique_ptr<sql::PreparedStatement> pPrepStmt = std::unique_ptr<sql::PreparedStatement>(pCon->prepareStatement("CALL insert_fabric_invoice(?,?,?,@FabricInvoiceID)"));

		pPrepStmt->setUInt(1, iFabricSupplierId);
		pPrepStmt->setDouble(2, dBillAmount);
		pPrepStmt->setDateTime(3, sql::SQLString(strDate));
		pPrepStmt->execute();
		pCon->commit();

		pRes.reset(pStmt->executeQuery("SELECT @FabricInvoiceID AS _ID"));
		while (pRes->next()) {
			retID = pRes->getInt("_ID");
		}
		pStmt->close();
		pPrepStmt->close();
		pRes->close();
	}
	catch (std::exception e) {
		//TODO:: error
	}
	oDataAccess->disconnect();
	return retID;
}

bool FabricInvoiceService::insertInvoiceItem(unsigned int iInvoiceId, unsigned int iItemId, double dQuantity, double dUnitPrice, bool bAddQuantity)
{
	bool bRet = false;
	DataAccess::DataAccessManager* oDataAccess = DataAccess::DataAccessManager::getInstance();
	try {
		oDataAccess->connect();
		std::unique_ptr < sql::Connection>& pCon = oDataAccess->getConnection();
		std::unique_ptr< sql::Statement > pStmt = std::unique_ptr<sql::Statement>(pCon->createStatement());

		std::unique_ptr<sql::PreparedStatement> pPrepStmt = std::unique_ptr<sql::PreparedStatement>(pCon->prepareStatement("CALL insert_fabric_invoice_item(?,?,?,?,?)"));

		pPrepStmt->setInt(1, iInvoiceId);
		pPrepStmt->setInt(2, iItemId);
		pPrepStmt->setDouble(3, dQuantity);
		pPrepStmt->setDouble(4, dUnitPrice);
		pPrepStmt->setBoolean(5, bAddQuantity);
		pPrepStmt->execute();
		pCon->commit();


		pStmt->close();
		pPrepStmt->close();
		bRet = true;
	}
	catch (std::exception e) {
		//TODO:: error
	}
	oDataAccess->disconnect();
	return bRet;
}
