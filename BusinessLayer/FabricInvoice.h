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
	unsigned int _iFabricSupplierID;
public:
	BUSINESSLAYER_API FabricInvoice();
	BUSINESSLAYER_API ~FabricInvoice();
	BUSINESSLAYER_API Response setFabricSupplierID(unsigned int iSupplierID);
	BUSINESSLAYER_API unsigned int getFabricSupplierID();

	BUSINESSLAYER_API bool save();
	BUSINESSLAYER_API bool update();
	BUSINESSLAYER_API bool deleteInvoice();
	
	BUSINESSLAYER_API std::string GetFieldName(int col);
	BUSINESSLAYER_API std::vector< std::unique_ptr < ItemInterface > >& GetAllItem();
	BUSINESSLAYER_API std::string getValueForField(int row, int col);
	BUSINESSLAYER_API int getColType(int col);
	BUSINESSLAYER_API int getColDataType(int col);
};

#endif