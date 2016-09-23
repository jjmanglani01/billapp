#include "stdafx.h"
#include "FabricItem.h"
#include "FabricItemService.h"
#include "Response.h"

FabricItem::FabricItem()
{
}


FabricItem::~FabricItem()
{
}

Response FabricItem::setFabricItemID(unsigned int iId)
{
	_iFabricItemID = iId;
	return generateResponse(ALL_OK, "");
}

unsigned int FabricItem::getFabricItemID()
{
	return _iFabricItemID;
}

Response FabricItem::setFabricName(std::string strFabricName)
{
	Response stResponse = getResponseForLength(LENGTH_100, strFabricName, "Fabric Name");
	if (stResponse.iResponseCode == ALL_OK)
	{
		_strFabricName = strFabricName;
	}
	return stResponse;
}

std::string FabricItem::getFabicName()
{
	return _strFabricName;
}

Response FabricItem::setFabricShortcut(std::string strShortcut)
{
	Response stResponse = getResponseForLength(LENGTH_5, strShortcut, "Fabric Shortcut");
	if (stResponse.iResponseCode == ALL_OK)
	{
		_strFabricShortcutName = strShortcut;
	}
	return stResponse;
}

std::string FabricItem::getFabricShortcut()
{
	return _strFabricShortcutName;
}

Response FabricItem::setFabricQuantity(double quantity)
{
	_dQuantity = quantity;
	return generateResponse(ALL_OK, "");
}

double FabricItem::getFabricQuantity()
{
	return _dQuantity;
}

Response FabricItem::setFabricUnitPrice(double unitPrice)
{
	_dUnitPrice = unitPrice;
	return generateResponse(ALL_OK, "");
}

double FabricItem::getFabricUnitPrice()
{
	return _dUnitPrice;
}

Response FabricItem::setFabricColor(std::string strColor)
{
	Response stResponse = getResponseForLength(LENGTH_15, strColor, "Fabric colour");
	if (stResponse.iResponseCode == ALL_OK)
	{
		_strColor = strColor;
	}
	return stResponse;
}

std::string FabricItem::getFabricColor()
{
	return _strColor;
}

Response FabricItem::setFabricType(std::string strType)
{
	Response stResponse = getResponseForLength(LENGTH_15, strType, "Fabric Type");
	if (stResponse.iResponseCode == ALL_OK)
	{
		_strFabricType = strType;
	}
	return stResponse;
}

std::string FabricItem::getFabricType()
{
	return _strFabricType;
}

bool FabricItem::save()
{
	bool bRet = false;
	FabricItemService oService;
	unsigned int iRet = oService.insert(_strFabricName,_strFabricShortcutName,_dQuantity,_dUnitPrice,_strColor,_strFabricType);
	if (iRet)
	{
		setFabricItemID(iRet);
		bRet = true;
	}
	return bRet;
}

bool FabricItem::update()
{
	return bool();
}

bool FabricItem::deleteData()
{
	return  bool();
}

