#pragma once
#ifndef __FABRICITEM_H_INCLUDED__
#define __FABRICITEM_H_INCLUDED__

#include <string>

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
	FabricItem();
	~FabricItem();


};

#endif