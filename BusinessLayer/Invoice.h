#pragma once
#ifndef __INVOICE_H_INCLUDED_
#define __INVOICE_H_INCLUDED_
#include <string>
#include "stdafx.h"
#include <vector>
#include <memory>
class ItemInterface;

class Invoice
{
protected:
public:
	BUSINESSLAYER_API Invoice();
	BUSINESSLAYER_API ~Invoice();
	virtual BUSINESSLAYER_API std::string GetFieldName(int col);
	virtual BUSINESSLAYER_API std::vector<std::unique_ptr<ItemInterface>>& GetAllItem();
};

#endif