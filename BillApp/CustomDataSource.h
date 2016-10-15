#pragma once
#ifndef __CUSTOMDATASOURCE_H_INCLUDED__
#define __CUSTOMDATASOURCE_H_INCLUDED__

#include "UGCtrl.h"
#include <memory>
class Invoice;

class CustomDataSource :
	public CUGDataSource
{
private:
	std::shared_ptr<Invoice> m_pData;
public:
	CustomDataSource(std::shared_ptr<Invoice> ptr);
	~CustomDataSource();
	int	GetCell(int col, long row, CUGCell *cell);
	int	SetCell(int col, long row, CUGCell *cell);
	int GetColName(int col, CString * string);
	long GetNumRows();
	int GetNumCols();
};

#endif