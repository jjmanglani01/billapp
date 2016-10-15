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

Response FabricItem::setFabricColor(const std::string &strColor)
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

Response FabricItem::setFabricType(const std::string &strType)
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
	unsigned int iRet = oService.insert(getName(), getShortcut(), getQuantity(), getUnitPrice(), _strColor, _strFabricType);
	if (iRet)
	{
		setItemID(iRet);
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

std::vector<std::unique_ptr<ItemInterface>>& FabricItem::getAllItem()
{
	return m_vecItem;
}

std::vector< std::unique_ptr< ItemInterface > > FabricItem::m_vecItem = []() -> std::vector< std::unique_ptr< ItemInterface > >
{
	std::vector< std::unique_ptr<ItemInterface > > vec;
	FabricItemService oSer;
	std::unique_ptr<sql::ResultSet> rs;
	oSer.getAll(rs);

	while (rs->next()) {
		std::unique_ptr<FabricItem> pFabricItem = std::make_unique<FabricItem>();

		pFabricItem->setItemID(rs->getInt(strId));
		pFabricItem->setName(rs->getString(strFabricname).operator const std::string &());
		pFabricItem->setShortcut(rs->getString(strShortcut).operator const std::string &());
		pFabricItem->setQuantity(rs->getDouble(strQuantity));
		pFabricItem->setUnitPrice(rs->getDouble(strUnitPrice));
		pFabricItem->setFabricColor(rs->getString(strColor).operator const std::string &());
		pFabricItem->setFabricType(rs->getString(strType).operator const std::string &());

		vec.push_back(std::move(pFabricItem));
	}
	rs->close();
	return vec;
}();



