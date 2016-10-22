#include "stdafx.h"
#include "FabricSupplierService.h"


FabricSupplierService::FabricSupplierService()
{
}


FabricSupplierService::~FabricSupplierService()
{
}

unsigned int  FabricSupplierService::insert(std::string strSupplierName, std::string strAddress1, std::string strAddress2,
	std::string strCity, std::string strState, std::string strEmail)
{
	unsigned int retID = 0;
	DataAccess::DataAccessManager* oDataAccess = DataAccess::DataAccessManager::getInstance();
	try {
		oDataAccess->connect();
		std::unique_ptr < sql::Connection>& pCon = oDataAccess->getConnection();
		std::unique_ptr< sql::ResultSet > pRes;
		std::unique_ptr< sql::Statement > pStmt = std::unique_ptr<sql::Statement>(pCon->createStatement());

		std::unique_ptr<sql::PreparedStatement> pPrepStmt = std::unique_ptr<sql::PreparedStatement>(pCon->prepareStatement("CALL insert_fabric_supplier(?,?,?,?,?,?,@FabricSupplierID)"));

		pPrepStmt->setString(1, strSupplierName);
		pPrepStmt->setString(2, strAddress1);
		pPrepStmt->setString(3, strAddress2);
		pPrepStmt->setString(4, strCity);
		pPrepStmt->setString(5, strState);
		pPrepStmt->setString(6, strEmail);
		pPrepStmt->execute();
		pCon->commit();

		pRes.reset(pStmt->executeQuery("SELECT @FabricSupplierID AS _ID"));
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

bool FabricSupplierService::insertPhoneNumber(unsigned int iFabricSupplierID, std::string _strPhoneType, std::string _strPhoneDescription, std::string _strPhoneNumber)
{
	bool bRet = false;
	DataAccess::DataAccessManager* oDataAccess = DataAccess::DataAccessManager::getInstance();
	try
	{
		oDataAccess->connect();
		std::unique_ptr <sql::Connection>& pCon = oDataAccess->getConnection();

		std::unique_ptr<sql::PreparedStatement> pPrepStmt = std::unique_ptr<sql::PreparedStatement>(pCon->prepareStatement("CALL insert_fabric_supplier_phonenumber(?,?,?,?)"));

		pPrepStmt->setInt(1, iFabricSupplierID);
		pPrepStmt->setString(2, _strPhoneType);
		pPrepStmt->setString(3, _strPhoneDescription);
		pPrepStmt->setString(4, _strPhoneNumber);
		pPrepStmt->execute();
		pCon->commit();
		bRet = true;
		pPrepStmt->close();
	}
	catch (std::exception& e)
	{
		//TODO: 
	}
	oDataAccess->disconnect();
	return bRet;
}

std::unique_ptr<sql::ResultSet> FabricSupplierService::getAll()
{
	DataAccess::DataAccessManager* oDataAccess = DataAccess::DataAccessManager::getInstance();
	std::unique_ptr<sql::ResultSet> pRes;
	try {
		oDataAccess->connect();
		std::unique_ptr < sql::Connection>& pCon = oDataAccess->getConnection();
		if (pCon&&pCon->isValid()) {
			std::unique_ptr<sql::PreparedStatement> pPrepStmt = std::unique_ptr<sql::PreparedStatement>(pCon->prepareStatement("CALL get_all_fabric_supplier()"));

			pRes = std::unique_ptr<sql::ResultSet>(pPrepStmt->executeQuery());
			pCon->commit();
			pPrepStmt->close();
		}
	}
	catch (std::exception e) {
		//TODO:: error
	}
	oDataAccess->disconnect();
	return std::move(pRes);
}
