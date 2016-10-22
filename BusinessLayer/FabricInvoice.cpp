#include "stdafx.h"
#include "FabricInvoice.h"
#include "Response.h"
#include "FabricInvoiceService.h"
#include "FabricItem.h"
#include "FabricItemService.h"
#include "InvoiceItem.h"

FabricInvoice::FabricInvoice()
{
	m_ptrInvoiceSer = std::make_unique<FabricInvoiceService>();
	m_dAmount = 0;
	setInvoiceDate("");
}


FabricInvoice::~FabricInvoice()
{
}


Response FabricInvoice::setFabricSupplierID(unsigned int iSupplierID)
{
	_iFabricSupplierID = iSupplierID;
	return generateResponse(ALL_OK);
}

unsigned int FabricInvoice::getFabricSupplierID()
{
	return _iFabricSupplierID;
}

Response FabricInvoice::setInvoiceDate(std::string strDate)
{
	_strDate = strDate;
	return generateResponse(ALL_OK);
}

std::string FabricInvoice::getInvoiceDate()
{
	return _strDate;
}

bool FabricInvoice::save()
{
	bool bRet = false;
	unsigned int iRet = static_cast<FabricInvoiceService*>(m_ptrInvoiceSer.get())->insert(_iFabricSupplierID, m_dAmount, _strDate);
	if (iRet)
	{
		m_iInvoiceID = iRet;
		bRet = true;
	}

	for (const InvoiceItem &ele : m_vecItem) {
		bRet = m_ptrInvoiceSer->insertInvoiceItem(m_iInvoiceID, ele.m_iItemId, ele.m_dQuantity, ele.m_dUnitPrice, ele.m_bAdd);
		if (!bRet) {
			//TODO: Delete entry from database
			break;
		}
	}
	return bRet;
}

BUSINESSLAYER_API bool FabricInvoice::update()
{
	return bool();
}

BUSINESSLAYER_API bool FabricInvoice::deleteInvoice()
{
	return bool();
}

std::string FabricInvoice::GetFieldName(int col)
{
	std::string strReturnValue = "";
	switch (col) {
	case -1:
		strReturnValue = "sr no";
		break;
	case 0:
		strReturnValue = "Fabric ItemId";
		break;
	case 1:
		strReturnValue = "Fabric ItemName";
		break;
	case 2:
		strReturnValue = "Quantity";
		break;
	case 3:
		strReturnValue = "Unit Price";
		break;
	case 4:
		strReturnValue = "Amount";
		break;
	case 5:
		strReturnValue = "Add";
		break;
	default:
		strReturnValue = "";
		break;
	}
	return strReturnValue;
}

std::vector< std::unique_ptr < ItemInterface > >&  FabricInvoice::GetAllItem()
{
	return FabricItem::getAllItem();
}

std::string FabricInvoice::getValueForField(int row, int col)
{
	std::string strReturnValue = "";
	if (m_vecItem.size() < row + 1) {
		return strReturnValue;
	}

	if (col == 0) {
		strReturnValue = std::to_string(m_vecItem[row].m_iItemId);
	}
	else if (col == 1) {
		std::unique_ptr<ItemInterface> &pFabricItem = FabricItem::getItemById(m_vecItem[row].m_iItemId);
		strReturnValue = pFabricItem->getName();
	}
	else if (col == 2) {
		strReturnValue = std::to_string(m_vecItem[row].m_dQuantity);
	}
	else if (col == 3) {
		strReturnValue = std::to_string(m_vecItem[row].m_dUnitPrice);
	}
	return strReturnValue;
}


int FabricInvoice::getColType(int col)
{
	int iRetType = 0;
	if (col == 5) {
		//2- UGCT_CHECKBOX
		return 2;
	}
}

int FabricInvoice::getColDataType(int col)
{
	int iRet = 0;
	if (col == 3 || col == 4) {
		//5 - Currency 
		return 5;
	}
	return iRet;
}

