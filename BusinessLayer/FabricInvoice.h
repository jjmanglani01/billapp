#pragma once
#ifndef __FABRICINVOICE_H_INCLUDED__
#define __FABRICINVOICE_H_INCLUDED__

#include <string>
#include <map>
struct Response;
#include "Invoice.h"
#include "stdafx.h"
class FabricItem;

class FabricInvoice : public Invoice
{
private:
	unsigned int _iFabricInvoicID;
	unsigned int _iFabricSupplierID;
	std::map<unsigned int, double> _mapItemToQuantity;
	std::string _strDate;
public:
	BUSINESSLAYER_API FabricInvoice();
	BUSINESSLAYER_API ~FabricInvoice();
	BUSINESSLAYER_API Response setFabricInvoiceID(unsigned int iId);
	BUSINESSLAYER_API unsigned int getFabricInvoiceID();
	BUSINESSLAYER_API Response setFabricSupplierID(unsigned int iSupplierID);
	BUSINESSLAYER_API unsigned int getFabricSupplierID();
	BUSINESSLAYER_API Response setInvoiceDate(std::string strDate);
	BUSINESSLAYER_API std::string getInvoiceDate();
	BUSINESSLAYER_API bool addInvoiceItem(unsigned int iFabricItemId, double dQuantity, double dUnitPrice,bool bAddQuantity);
	

	BUSINESSLAYER_API bool save();
	BUSINESSLAYER_API bool update();
	BUSINESSLAYER_API bool deleteInvoice();
	BUSINESSLAYER_API std::string GetFieldName(int col);
	BUSINESSLAYER_API std::vector< std::unique_ptr < ItemInterface > >& GetAllItem();
};

#endif