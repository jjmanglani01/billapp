// FabricInvoiceView.cpp : implementation file
//

#include "stdafx.h"
#include "BillApp.h"
#include "FabricInvoiceView.h"
#include "Helper.h"
#include "ItemInterface.h"
#include "FabricSupplier.h"
#include "CustomAutoComplete.h"
#include "FabricInvoice.h"
#include <iomanip>

// FabricInvoiceView

IMPLEMENT_DYNCREATE(FabricInvoiceView, CFormView)

FabricInvoiceView::FabricInvoiceView()
	: CFormView(IDD_FABRICINVOICEVIEW)
{
	m_pAutoComplete = std::make_unique<CCustomAutoComplete>(HKEY_CURRENT_USER, _T("Software\\AutoComplete\\FabricSupplier"));
}

FabricInvoiceView::~FabricInvoiceView()
{
}

void FabricInvoiceView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	m_grid.MoveWindow(20, 100, cx - 40, cy - 150);
	m_date.SetTime(time(0));
	//TODO: change width
	m_btnSave.MoveWindow(cx / 2, cy - 50, 50, 20);
}

void FabricInvoiceView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_BUTTON_FABRICINVOICE_SAVE, m_btnSave);
	DDX_Control(pDX, IDC_DATETIMEPICKER_FABRICINVOICE, m_date);
	//TODO: change id
	m_grid.CreateGrid(WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this, 9999);
	m_ptrInvoice = std::make_shared<FabricInvoice>();
	m_grid.SetInvoiceDataSource(m_ptrInvoice);

	m_date.SetFormat(_T("dddd, dd MMMM, yyyy"));
	FabricSupplier oSupplier;
	CString str;
	std::vector< std::unique_ptr < FabricSupplier > >& vec = oSupplier.getAllItem();

	m_pAutoComplete->Clear();
	for (std::size_t i = 0; i != vec.size(); ++i) {
		str = std::to_string(vec[i]->getSupplierID()).c_str();
		m_pAutoComplete->AddItem(str);
	}

	DDX_Control(pDX, IDC_EDIT_FABRICINVOICE_SUPPLIER, m_editSupplierID);
	HWND hnd = m_editSupplierID.GetSafeHwnd();
	m_pAutoComplete->Bind(hnd, ACO_UPDOWNKEYDROPSLIST | ACO_AUTOSUGGEST | ACO_AUTOAPPEND, _T("www.%s.com"));

	/*DDX_Control(pDX, IDC_EDIT_FABRICINVOICE_SUPPLIER, m_editSupplierName);
	HWND hndName = m_editSupplierName.GetSafeHwnd();
	m_pAutoComplete->Bind(hndName, ACO_UPDOWNKEYDROPSLIST | ACO_AUTOSUGGEST | ACO_AUTOAPPEND, _T("www.%s.com"));*/
}

BEGIN_MESSAGE_MAP(FabricInvoiceView, CFormView)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON_FABRICINVOICE_SAVE, &FabricInvoiceView::OnBnClickedButtonFabricinvoiceSave)
END_MESSAGE_MAP()


// FabricInvoiceView diagnostics

#ifdef _DEBUG
void FabricInvoiceView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FabricInvoiceView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


void FabricInvoiceView::OnBnClickedButtonFabricinvoiceSave()
{
	CString strSupplierID;
	CTime billDate;

	GetDlgItemText(IDC_EDIT_FABRICINVOICE_SUPPLIER, strSupplierID);

	wchar_t* ptr = new wchar_t();
	int iSupplierID = _tcstoul((LPCTSTR)strSupplierID, &ptr, 10);

	m_date.GetTime(billDate);

	static_cast<FabricInvoice*>(m_ptrInvoice.get())->setFabricSupplierID(iSupplierID);
	CString strDate = billDate.Format(_T("%Y-%m-%d %H:%M:%S "));
	static_cast<FabricInvoice*>(m_ptrInvoice.get())->setInvoiceDate(Helper::convertCstringToString(strDate));
	m_ptrInvoice->save();
}
