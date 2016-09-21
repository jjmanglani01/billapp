#pragma once
#ifndef __FABRICITEMSERVICE_H_INCLUDED__
#define __FABRICITEMSERVICE_H_INCLUDED__

#include "DataAccessManager.h"

class FabricItemService
{
public:
	DATAACCESSLAYER_API FabricItemService();
	DATAACCESSLAYER_API ~FabricItemService();
	DATAACCESSLAYER_API unsigned int insert(std::string strFabricName,std::string strShortcut,float fQuantity,float fUnitPrice,std::string strColor,std::string strFabricType);
};

#endif