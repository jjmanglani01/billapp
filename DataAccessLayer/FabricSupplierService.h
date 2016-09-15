#pragma once
#ifndef __FABRICSUPPLIERSERVICE_H_INCLUDED__
#define __FABRICSUPPLIERSERVICE_H_INCLUDED__

#include "DataAccessManager.h"

class FabricSupplierService
{
public:
	DATAACCESSLAYER_API  FabricSupplierService();
	DATAACCESSLAYER_API  ~FabricSupplierService();
	DATAACCESSLAYER_API  int unsigned insert(std::string strSupplierName, std::string strAddress1, std::string strAddress2, std::string strCity,
		std::string strState, std::string strEmail);
};

#endif