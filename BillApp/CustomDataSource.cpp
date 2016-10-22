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
			if (!str.empty()) {
				cell->SetText(Helper::stringToLpctstr(str));
				cell->SetPropertyFlags(UGCELL_TEXT_SET);
			}
		}
	}
	else {
		if (!cell->IsPropertySet(UGCELL_TEXT_SET)) {
			if (col == -1) {
				cell->SetText(Helper::stringToLpctstr(std::to_string(row + 1)));
			}
			
			std::string str = m_pData->getValueForField(row, col);
			if (!str.empty()) {
				cell->SetText(Helper::stringToLpctstr(str));
				cell->SetPropertyFlags(UGCELL_TEXT_SET);
			}
		}
		else if (!cell->IsPropertySet(UGCELL_CELLTYPE_SET) && m_pData->getColType(col)) {
			cell->SetCellType(m_pData->getColType(col));
			cell->SetPropertyFlags(UGCELL_CELLTYPE_SET);
			cell->SetReadOnly(FALSE);
		}
		else if (!cell->IsPropertySet(UGCELL_DATATYPE_SET) && m_pData->getColDataType(col)) {
			cell->SetDataType(m_pData->getColDataType(col));
			cell->SetPropertyFlags(UGCELL_DATATYPE_SET);
		}
	}
	return UG_SUCCESS;
}

int CustomDataSource::SetCell(int col, long row, CUGCell * cell)
{
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
	return m_pData->getNumRows();
}

int CustomDataSource::GetNumCols()
{
	return m_pData->getNumCols();
}
