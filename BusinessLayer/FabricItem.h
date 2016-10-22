#pragma once
#ifndef __FABRICITEM_H_INCLUDED__
#define __FABRICITEM_H_INCLUDED__

#include <string>
#include "stdafx.h"
#include "ItemInterface.h"
#include <vector>
#include <memory>

struct Response;
const std::string strId = "FabricItemId";
const std::string strFabricname = "FabricName";
const std::string strShortcut = "ShortcutName";
const std::string strQuantity = "Quantity";
const std::string strUnitPrice = "UnitPrice";
const std::string strColor = "Color";
const std::string strType = "FabricType";

class FabricItem:public ItemInterface
{
private:
	std::string _strColor;
	std::string _strFabricType;
	static std::vector< std::unique_ptr<ItemInterface > > m_vecItem;
public:
	BUSINESSLAYER_API FabricItem();
	BUSINESSLAYER_API ~FabricItem();

	BUSINESSLAYER_API Response setFabricColor(const std::string &strColor);
	BUSINESSLAYER_API std::string getFabricColor();
	
	BUSINESSLAYER_API Response setFabricType(const std::string &strType);
	BUSINESSLAYER_API std::string getFabricType();

	BUSINESSLAYER_API bool save();
	BUSINESSLAYER_API bool update();
	BUSINESSLAYER_API bool deleteData();
	BUSINESSLAYER_API static std::vector< std::unique_ptr< ItemInterface > >& getAllItem();
	BUSINESSLAYER_API static std::unique_ptr<ItemInterface>& getItemById(unsigned int iId);
};

#endif