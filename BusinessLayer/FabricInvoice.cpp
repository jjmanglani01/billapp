#include "stdafx.h"
#include "FabricInvoice.h"
#include "Response.h"
#include "FabricInvoiceService.h"
#include "FabricItem.h"
#include "FabricItemService.h"

FabricInvoice::FabricInvoice()
{
}


FabricInvoice::~FabricInvoice()
{
}

Response FabricInvoice::setFabricInvoiceID(unsigned int iId)
{
	_iFabricInvoicID = iId;
	return  generateResponse(ALL_OK);
}

unsigned int FabricInvoice::getFabricInvoiceID()
{
	return _iFabricInvoicID;
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

bool FabricInvoice::addInvoiceItem(unsigned int iFabricItemId, double dQuantity,double dUnitPrice, bool bAddQuantity)
{
	FabricInvoiceService oService;
	return oService.insertFabricInvoiceItem(_iFabricInvoicID, iFabricItemId, dQuantity, dUnitPrice,bAddQuantity);
}

bool FabricInvoice::save()
{
	bool bRet = false;
	FabricInvoiceService oService;
	unsigned int iRet = oService.insert(_iFabricSupplierID, 0, _strDate);
	if (iRet)
	{
		_iFabricInvoicID = iRet;
		bRet = true;
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
	switch (col) {
	case -1:
		return "sr no";
	case 0:
		return "Fabric ItemId";
	case 1:
		return "Fabric ItemName";
	case 2:
		return "Quantity";
	case 3:
		return "Unit Price";
	case 4:
		return "Amount";
	default:
		return "";
	}
}

std::vector< std::unique_ptr < ItemInterface > >&  FabricInvoice::GetAllItem()
{
	return FabricItem::getAllItem();
}
