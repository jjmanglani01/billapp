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

		std::unique_ptr<sql::PreparedStatement> pPrepStmt = std::unique_ptr<sql::PreparedStatement>(pCon->prepareStatement("CALL insert_fabric_invoice(?,?,@FabricInvoiceID)"));

		pPrepStmt->setInt(1, iFabricSupplierId);
		pPrepStmt->setString(2, strDate);
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

bool FabricInvoiceService::insertFabricInvoiceItem(unsigned int iFabricInvoiceId, unsigned int iFabricItemId, double dQuantity, double dUnitPrice,bool bAddQuantity)
{
	bool bRet = false;
	DataAccess::DataAccessManager* oDataAccess = DataAccess::DataAccessManager::getInstance();
	try {
		oDataAccess->connect();
		std::unique_ptr < sql::Connection>& pCon = oDataAccess->getConnection();
		std::unique_ptr< sql::ResultSet > pRes;
		std::unique_ptr< sql::Statement > pStmt = std::unique_ptr<sql::Statement>(pCon->createStatement());

		std::unique_ptr<sql::PreparedStatement> pPrepStmt = std::unique_ptr<sql::PreparedStatement>(pCon->prepareStatement("CALL insert_fabric_invoice_item(?,?,?,?)"));

		pPrepStmt->setInt(1, iFabricInvoiceId);
		pPrepStmt->setInt(2, iFabricItemId);
		pPrepStmt->setDouble(3, dQuantity);
		pPrepStmt->setDouble(4, dUnitPrice);
		pPrepStmt->setBoolean(5, bAddQuantity);
		pPrepStmt->execute();
		pCon->commit();


		pStmt->close();
		pPrepStmt->close();
		pRes->close();
		bRet = true;
	}
	catch (std::exception e) {
		//TODO:: error
	}
	oDataAccess->disconnect();
	return bRet;
}
