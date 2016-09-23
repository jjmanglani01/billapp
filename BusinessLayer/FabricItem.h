#pragma once
#ifndef __FABRICITEM_H_INCLUDED__
#define __FABRICITEM_H_INCLUDED__

#include <string>
#include "stdafx.h"
struct Response;

class FabricItem
{
private:
	unsigned int _iFabricItemID;
	std::string _strFabricName;
	std::string _strFabricShortcutName;
	double _dQuantity;
	double _dUnitPrice;
	std::string _strColor;
	std::string _strFabricType;
public:
	BUSINESSLAYER_API FabricItem();
	BUSINESSLAYER_API ~FabricItem();

	BUSINESSLAYER_API Response setFabricItemID(unsigned int iId);
	BUSINESSLAYER_API unsigned int getFabricItemID();

	BUSINESSLAYER_API Response setFabricName(std::string strFabricName);
	BUSINESSLAYER_API std::string getFabicName();

	BUSINESSLAYER_API Response setFabricShortcut(std::string strShortcut);
	BUSINESSLAYER_API std::string getFabricShortcut();

	BUSINESSLAYER_API Response setFabricQuantity(double quantity);
	BUSINESSLAYER_API double getFabricQuantity();

	BUSINESSLAYER_API Response setFabricUnitPrice(double unitPrice);
	BUSINESSLAYER_API double getFabricUnitPrice();

	BUSINESSLAYER_API Response setFabricColor(std::string strColor);
	BUSINESSLAYER_API std::string getFabricColor();
	
	BUSINESSLAYER_API Response setFabricType(std::string strType);
	BUSINESSLAYER_API std::string getFabricType();

	BUSINESSLAYER_API bool save();
	BUSINESSLAYER_API bool update();
	BUSINESSLAYER_API bool deleteData();

};

#endif