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
		std::unique_ptr < sql::Connection>& _pCon = oDataAccess->getConnection();
		std::unique_ptr< sql::ResultSet > res;
		std::unique_ptr< sql::Statement > _pStmt = std::unique_ptr<sql::Statement>(_pCon->createStatement());

		std::unique_ptr<sql::PreparedStatement> prepStmt = std::unique_ptr<sql::PreparedStatement>(_pCon->prepareStatement("CALL insert_fabric_supplier(?,?,?,?,?,?,@FabricSupplierID)"));

		prepStmt->setString(1, strSupplierName);
		prepStmt->setString(2, strAddress1);
		prepStmt->setString(3, strAddress2);
		prepStmt->setString(4, strCity);
		prepStmt->setString(5, strState);
		prepStmt->setString(6, strEmail);
		prepStmt->execute();
		_pCon->commit();

		res.reset(_pStmt->executeQuery("SELECT @FabricSupplierID AS _ID"));
		while (res->next()) {
			retID = res->getInt("_ID");
		}
		oDataAccess->disconnect();
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
		std::unique_ptr < sql::Connection>& _pCon = oDataAccess->getConnection();

		std::unique_ptr<sql::PreparedStatement> prepStmt = std::unique_ptr<sql::PreparedStatement>(_pCon->prepareStatement("CALL insert_fabric_supplier_phonenumber(?,?,?,?)"));

		prepStmt->setInt(1, iFabricSupplierID);
		prepStmt->setString(2, _strPhoneType);
		prepStmt->setString(3, _strPhoneDescription);
		prepStmt->setString(4, _strPhoneNumber);
		prepStmt->execute();
		_pCon->commit();
		bRet = true;
	}
	catch (std::exception& e)
	{
		//TODO: 
	}
	oDataAccess->disconnect();
	return bRet;
}
