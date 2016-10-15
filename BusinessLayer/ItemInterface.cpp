#include "stdafx.h"
#include "ItemInterface.h"
#include "Response.h"

ItemInterface::ItemInterface()
{
}


ItemInterface::~ItemInterface()
{
}

Response ItemInterface::setItemID(unsigned int iId)
{
	_iItemID = iId;
	return generateResponse(ALL_OK, "");
}

unsigned int ItemInterface::getItemID()
{
	return _iItemID;
}

Response ItemInterface::setName(const std::string &strName)
{
	Response stResponse = getResponseForLength(LENGTH_100, strName, "Item Name");
	if (stResponse.iResponseCode == ALL_OK)
	{
		_strName = strName;
	}
	return stResponse;
}

std::string ItemInterface::getName()
{
	return _strName;
}

Response ItemInterface::setShortcut(const std::string &strShortcut)
{
	Response stResponse = getResponseForLength(LENGTH_5, strShortcut, "Fabric Shortcut");
	if (stResponse.iResponseCode == ALL_OK)
	{
		_strShortcutName = strShortcut;
	}
	return stResponse;
}

std::string ItemInterface::getShortcut()
{
	return _strShortcutName;
}

Response ItemInterface::setQuantity(double quantity)
{
	_dQuantity = quantity;
	return generateResponse(ALL_OK, "");
}

double ItemInterface::getQuantity()
{
	return _dQuantity;
}

Response ItemInterface::setUnitPrice(double unitPrice)
{
	_dUnitPrice = unitPrice;
	return generateResponse(ALL_OK, "");
}

double ItemInterface::getUnitPrice()
{
	return _dUnitPrice;
}
