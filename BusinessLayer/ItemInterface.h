#pragma once
#ifndef __ITEMINTERFACE_H_INCLUDED_
#define __ITEMINTERFACE_H_INCLUDED_
#include <string>
#include <vector>
#include <memory>
#include "Response.h"
#include "stdafx.h"

class ItemInterface
{
private:
	unsigned int _iItemID;
	std::string _strName;
	std::string _strShortcutName;
	double _dQuantity;
	double _dUnitPrice;
public:
	BUSINESSLAYER_API ItemInterface();
	BUSINESSLAYER_API ~ItemInterface();

	BUSINESSLAYER_API virtual Response setItemID(unsigned int iId);
	BUSINESSLAYER_API virtual unsigned int getItemID();

	BUSINESSLAYER_API virtual Response setName(const std::string &strName);
	BUSINESSLAYER_API virtual std::string getName();

	BUSINESSLAYER_API virtual Response setShortcut(const std::string &strShortcut);
	BUSINESSLAYER_API virtual std::string getShortcut();

	BUSINESSLAYER_API virtual Response setQuantity(double quantity);
	BUSINESSLAYER_API virtual double getQuantity();

	BUSINESSLAYER_API virtual Response setUnitPrice(double unitPrice);
	BUSINESSLAYER_API virtual double getUnitPrice();

};

#endif