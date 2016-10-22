#pragma once
#ifndef __FABRICINVOICESERVICE_H_INCLUDED__
#define __FABRICINVOICESERVICE_H_INCLUDED__

#include "DataAccessManager.h"
#include "InvoiceService.h"

class FabricInvoiceService : public InvoiceService
{
public:
	DATAACCESSLAYER_API  FabricInvoiceService();
	DATAACCESSLAYER_API  ~FabricInvoiceService();
	DATAACCESSLAYER_API  unsigned int insert(unsigned int iFabricSupplierId, double dBillAmount, std::string strDate);
	DATAACCESSLAYER_API  bool insertInvoiceItem(unsigned int iInvoiceId, unsigned int iItemId, double dQuantity, double dUnitPrice, bool bAddQuantity);
};

#endif