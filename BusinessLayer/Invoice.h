#pragma once
#ifndef __INVOICE_H_INCLUDED_
#define __INVOICE_H_INCLUDED_
#include <string>
#include "stdafx.h"
#include <vector>
#include <map>
#include <memory>
class ItemInterface;
struct Response;
struct InvoiceItem;
class InvoiceService;

class Invoice
{
protected:
	unsigned int m_iInvoiceID;
	std::vector<InvoiceItem> m_vecItem;
	std::string _strDate;
	double m_dAmount;
	std::unique_ptr<InvoiceService> m_ptrInvoiceSer;
public:
	BUSINESSLAYER_API Invoice();
	BUSINESSLAYER_API ~Invoice();

	virtual BUSINESSLAYER_API Response setInvoiceID(unsigned int iId);
	virtual BUSINESSLAYER_API unsigned int getInvoiceID();
	virtual BUSINESSLAYER_API Response setInvoiceDate(std::string strDate);
	virtual BUSINESSLAYER_API std::string getInvoiceDate();

	virtual BUSINESSLAYER_API std::string GetFieldName(int col);
	virtual BUSINESSLAYER_API std::vector<std::unique_ptr<ItemInterface>>& GetAllItem();
	virtual BUSINESSLAYER_API Response addItemId(int row, unsigned int iId);
	virtual BUSINESSLAYER_API void addQuantity(int row, double dQuan);
	virtual BUSINESSLAYER_API void addUnitPrice(int row, double dUnitPrice);
	virtual BUSINESSLAYER_API void addboolbAdd(int row);
	virtual BUSINESSLAYER_API std::string getValueForField(int row, int col);
	virtual BUSINESSLAYER_API int getNumCols();
	virtual BUSINESSLAYER_API int getNumRows();
	virtual BUSINESSLAYER_API int getColType(int col);
	virtual BUSINESSLAYER_API int getColDataType(int col);

	virtual BUSINESSLAYER_API bool save() = 0;
	virtual BUSINESSLAYER_API bool update() = 0;
	virtual BUSINESSLAYER_API bool deleteInvoice() = 0;
	virtual BUSINESSLAYER_API bool addInvoiceItem(unsigned int iFabricItemId, double dQuantity, double dUnitPrice, bool bAddQuantity);
};

#endif