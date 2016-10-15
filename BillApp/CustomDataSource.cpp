#include "stdafx.h"
#include "CustomDataSource.h"
#include "Invoice.h"
#include "FabricItem.h"
#include "Helper.h"

CustomDataSource::CustomDataSource(std::shared_ptr<Invoice> ptr) :m_pData(std::move(ptr))
{
}

CustomDataSource::~CustomDataSource()
{
}

int CustomDataSource::GetCell(int col, long row, CUGCell * cell)
{
	if (row == -1) {
		if (!cell->IsPropertySet(UGCELL_TEXT_SET)) {
			std::string str = m_pData->GetFieldName(col);
			cell->SetText(Helper::convertStringToLpcwstr(str));
			cell->SetPropertyFlags(UGCELL_TEXT_SET);
		}
	}

	return UG_SUCCESS;
}

int CustomDataSource::SetCell(int col, long row, CUGCell * cell)
{
	CString text;
	cell->GetText(&text);
	return 0;
}

int CustomDataSource::GetColName(int col, CString * string)
{
	switch (col)
	{
	case 0:
		string->Append(L"Id 2");
		break;
	case 1:
		string->Append(L"Id 3");
		break;

	}
	return 1;
}

long CustomDataSource::GetNumRows()
{
	return 2;
}

int CustomDataSource::GetNumCols()
{
	return 4;
}
