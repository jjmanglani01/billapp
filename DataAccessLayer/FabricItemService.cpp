#include "stdafx.h"
#include "FabricItemService.h"


FabricItemService::FabricItemService()
{
}


FabricItemService::~FabricItemService()
{
}

unsigned int FabricItemService::insert(std::string strFabricName, std::string strShortcut, float fQuantity, float fUnitPrice, std::string strColor, std::string strFabricType)
{
	unsigned int retID = 0;
	DataAccess::DataAccessManager* oDataAccess = DataAccess::DataAccessManager::getInstance();
	try {
		oDataAccess->connect();
		std::unique_ptr < sql::Connection>& _pCon = oDataAccess->getConnection();
		std::unique_ptr< sql::ResultSet > res;
		std::unique_ptr< sql::Statement > _pStmt = std::unique_ptr<sql::Statement>(_pCon->createStatement());

		std::unique_ptr<sql::PreparedStatement> prepStmt = std::unique_ptr<sql::PreparedStatement>(_pCon->prepareStatement("CALL insert_fabric_item(?,?,?,?,?,?,@FabricSupplierID)"));

		prepStmt->setString(1, strFabricName);
		prepStmt->setString(2, strShortcut);
		prepStmt->setDouble(3, fQuantity);
		prepStmt->setDouble(4, fUnitPrice);
		prepStmt->setString(5, strColor);
		prepStmt->setString(6, strFabricType);
		prepStmt->execute();
		_pCon->commit();

		res.reset(_pStmt->executeQuery("SELECT @FabricSupplierID AS _ID"));
		while (res->next()) {
			retID = res->getInt("_ID");
		}
	}
	catch (std::exception e) {
		//TODO:: error
	}
	return retID;
}
