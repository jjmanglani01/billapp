#include "stdafx.h"
#include "FabricPaymentService.h"


FabricPaymentService::FabricPaymentService()
{
}


FabricPaymentService::~FabricPaymentService()
{
}

bool FabricPaymentService::insert(unsigned int iFabricSupplierID, std::string strPaymentType, std::string strDate, double dAmount, std::string strChequeNo, std::string strChequeDate)
{
	bool bRet = true;
	DataAccess::DataAccessManager* oDataAccess = DataAccess::DataAccessManager::getInstance();
	try {
		oDataAccess->connect();
		std::unique_ptr < sql::Connection>& pCon = oDataAccess->getConnection();

		std::unique_ptr<sql::PreparedStatement> pPrepStmt = std::unique_ptr<sql::PreparedStatement>(pCon->prepareStatement("CALL insert_fabric_payment(?,?,?,?,?,?)"));

		pPrepStmt->setUInt(1, iFabricSupplierID);
		pPrepStmt->setString(2, strPaymentType);
		pPrepStmt->setDateTime(3, strDate);
		pPrepStmt->setDouble(4, dAmount);
		pPrepStmt->setString(5, strChequeNo);
		pPrepStmt->setDateTime(6, strChequeDate);
		pPrepStmt->execute();
		pCon->commit();

		pPrepStmt->close();
	}
	catch (std::exception e) {
		//TODO:: error
		bRet = false;
	}
	oDataAccess->disconnect();
	return bRet;
}

std::unique_ptr<sql::ResultSet> FabricPaymentService::getAll()
{
	return std::unique_ptr<sql::ResultSet>();
}
