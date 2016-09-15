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
	try {
		DataAccess::DataAccessManager* oDataAccess = DataAccess::DataAccessManager::getInstance();
		oDataAccess->connect();
		std::unique_ptr < sql::Connection>& con = oDataAccess->getConnection();
		std::unique_ptr< sql::ResultSet > res;
		std::unique_ptr< sql::Statement > stmt = std::unique_ptr<sql::Statement>(con->createStatement());

		std::unique_ptr<sql::PreparedStatement> prepStmt = std::unique_ptr<sql::PreparedStatement>(con->prepareStatement("CALL insert_fabric_supplier(?,?,?,?,?,?,@FabricSupplierID)"));

		prepStmt->setString(1, strSupplierName);
		prepStmt->setString(2, strAddress1);
		prepStmt->setString(3, strAddress2);
		prepStmt->setString(4, strCity);
		prepStmt->setString(5, strState);
		prepStmt->setString(6, strEmail);
		prepStmt->execute();
		con->commit();

		res.reset(stmt->executeQuery("SELECT @FabricSupplierID AS _ID"));
		while (res->next()) {
			retID = res->getInt("_ID");
		}
	}
	catch (std::exception e) {
		//TODO:: error
	}
	return retID;
}
