#pragma once
#ifndef __FABRICPAYMENTSERVICE_H_INCLUDED_
#define __FABRICPAYMENTSERVICE_H_INCLUDED_
#include "DataAccessManager.h"

class FabricPaymentService
{
public:
	DATAACCESSLAYER_API  FabricPaymentService();
	DATAACCESSLAYER_API  ~FabricPaymentService();
	DATAACCESSLAYER_API  bool insert(unsigned int iFabricSupplierID, std::string strPaymentType, std::string strDate, double dAmount, std::string strChequeNo, std::string strChequeDate);
	DATAACCESSLAYER_API  std::unique_ptr<sql::ResultSet> getAll();
};

#endif