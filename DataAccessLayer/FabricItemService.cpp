#include "stdafx.h"
#include "FabricItemService.h"


FabricItemService::FabricItemService()
{
}


FabricItemService::~FabricItemService()
{
}

unsigned int FabricItemService::insert(std::string strFabricName, std::string strShortcut, double fQuantity, double fUnitPrice, std::string strColor, std::string strFabricType)
{
	unsigned int retID = 0;
	DataAccess::DataAccessManager* oDataAccess = DataAccess::DataAccessManager::getInstance();
	try {
		oDataAccess->connect();
		std::unique_ptr < sql::Connection>& pCon = oDataAccess->getConnection();
		std::unique_ptr< sql::ResultSet > pRes;
		std::unique_ptr< sql::Statement > pStmt = std::unique_ptr<sql::Statement>(pCon->createStatement());

		std::unique_ptr<sql::PreparedStatement> pPrepStmt = std::unique_ptr<sql::PreparedStatement>(pCon->prepareStatement("CALL insert_fabric_item(?,?,?,?,?,?,@FabricItemID)"));

		pPrepStmt->setString(1, strFabricName);
		pPrepStmt->setString(2, strShortcut);
		pPrepStmt->setDouble(3, fQuantity);
		pPrepStmt->setDouble(4, fUnitPrice);
		pPrepStmt->setString(5, strColor);
		pPrepStmt->setString(6, strFabricType);
		pPrepStmt->execute();
		pCon->commit();

		pRes.reset(pStmt->executeQuery("SELECT @FabricItemID AS _ID"));
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
	return retID;
}
