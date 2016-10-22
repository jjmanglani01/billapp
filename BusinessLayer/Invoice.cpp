#include "stdafx.h"
#include "Invoice.h"
#include "ItemInterface.h"
#include "InvoiceItem.h"
#include "InvoiceService.h"
#include <algorithm>

Invoice::Invoice()
{
}


Invoice::~Invoice()
{
}

Response Invoice::setInvoiceID(unsigned int iId)
{
	m_iInvoiceID = iId;
	return  generateResponse(ALL_OK);
}

unsigned int Invoice::getInvoiceID()
{
	return m_iInvoiceID;
}

std::string Invoice::GetFieldName(int col)
{
	return std::string();
}

std::vector<std::unique_ptr<ItemInterface>>& Invoice::GetAllItem()
{
	return std::vector<std::unique_ptr<ItemInterface>>();
}

Response Invoice::addItemId(int row, unsigned int iId)
{
	int iCode = ALL_OK;
	std::string strResponse = "";
	auto it = std::find_if(begin(m_vecItem), end(m_vecItem), [&iId](InvoiceItem obj) {return obj.m_iItemId == iId; });
	if (it == end(m_vecItem)) {
		if (row < m_vecItem.size()) {
			InvoiceItem item = m_vecItem[row];
			item.m_iItemId = iId;
		}
		else {
			InvoiceItem item;
			item.m_iItemId = iId;
			m_vecItem.push_back(item);
		}
	}
	else {
		iCode = ERROR_CODE_DUPLICATE;
		strResponse = (std::string)DUPLICATE_VALUE;
	}
	return generateResponse(iCode, strResponse);
}

void Invoice::addQuantity(int row, double dQuan)
{
	if (row < m_vecItem.size()) {
		InvoiceItem item = m_vecItem[row];
		item.m_dQuantity = dQuan;
		m_vecItem[row] = item;
	}
	else {
		InvoiceItem item;
		item.m_dQuantity = dQuan;
		m_vecItem.push_back(item);
	}
}

void Invoice::addUnitPrice(int row, double dUnitPrice)
{
	if (row < m_vecItem.size()) {
		InvoiceItem item = m_vecItem[row];
		item.m_dUnitPrice = dUnitPrice;
		m_vecItem[row] = item;
	}
	else {
		InvoiceItem item;
		item.m_dUnitPrice = dUnitPrice;
		m_vecItem.push_back(item);
	}
}

void Invoice::addboolbAdd(int row, bool bAdd = true)
{

}

std::string Invoice::getValueForField(int row, int col)
{
	return std::string();
}

int Invoice::getNumCols()
{
	return 6;
}

int Invoice::getNumRows()
{
	return m_vecItem.size() + 1;
}

int Invoice::getColType(int col)
{
	return 0;
}

int Invoice::getColDataType(int col)
{
	return int();
}

bool Invoice::addInvoiceItem(unsigned int iItemId, double dQuantity, double dUnitPrice, bool bAddQuantity)
{
	return m_ptrInvoiceSer->insertInvoiceItem(m_iInvoiceID, iItemId, dQuantity, dUnitPrice, bAddQuantity);
}



