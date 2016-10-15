#include "stdafx.h"
#include "Invoice.h"
#include "ItemInterface.h"

Invoice::Invoice()
{
}


Invoice::~Invoice()
{
}

std::string Invoice::GetFieldName(int col)
{
	return std::string();
}

std::vector<std::unique_ptr<ItemInterface>>& Invoice::GetAllItem()
{
	return std::vector<std::unique_ptr<ItemInterface>>();
}


