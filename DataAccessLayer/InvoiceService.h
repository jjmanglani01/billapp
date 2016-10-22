#pragma once
#ifndef __INVOICESERVICE_H_INCLUDED__
#define __INVOICESERVICE_H_INCLUDED__

#include "DataAccessManager.h"

class InvoiceService
{
public:
	DATAACCESSLAYER_API InvoiceService();
	DATAACCESSLAYER_API ~InvoiceService();
	virtual DATAACCESSLAYER_API bool insertInvoiceItem(unsigned int iInvoiceId, unsigned int iItemId, double dQuantity, double dUnitPrice, bool bAddQuantity);
};

#endif