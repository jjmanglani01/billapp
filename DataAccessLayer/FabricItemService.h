#pragma once
#ifndef __FABRICITEMSERVICE_H_INCLUDED__
#define __FABRICITEMSERVICE_H_INCLUDED__

#include "DataAccessManager.h"

class FabricItemService
{
public:
	DATAACCESSLAYER_API FabricItemService();
	DATAACCESSLAYER_API ~FabricItemService();
	DATAACCESSLAYER_API unsigned int insert(std::string strFabricName,std::string strShortcut,double fQuantity,double fUnitPrice,std::string strColor,std::string strFabricType);
	DATAACCESSLAYER_API void getAll(std::unique_ptr<sql::ResultSet>& pRes);
};

#endif