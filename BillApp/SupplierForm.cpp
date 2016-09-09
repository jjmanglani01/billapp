// SupplierForm.cpp : implementation file
//

#include "stdafx.h"
#include "BillApp.h"
#include "SupplierForm.h"
#include "DataAccessLayer.h"

// SupplierForm

IMPLEMENT_DYNCREATE(SupplierForm, CFormView)

SupplierForm::SupplierForm()
	: CFormView(IDD_SUPPLIERFORM)
{

}

SupplierForm::~SupplierForm()
{
}

void SupplierForm::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

void SupplierForm::OnDraw(CDC*pDc) {
}

BEGIN_MESSAGE_MAP(SupplierForm, CFormView)
	ON_BN_CLICKED(IDC_BUTTON_SUPPLIER_ADD, &SupplierForm::OnClickedSupplierAdd)
END_MESSAGE_MAP()


// SupplierForm diagnostics

#ifdef _DEBUG
void SupplierForm::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void SupplierForm::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// SupplierForm message handlers


void SupplierForm::OnClickedSupplierAdd()
{
	// TODO: Add your control notification handler code here
	DataAccess::DataAccessLayer dl;
	CString cName;
	CString cPhoneNo;
	CString cAddress;
	CString cEmail;

	GetDlgItemText(IDC_EDIT_SUPPLIER_NAME, cName);

	GetDlgItemText(IDC_EDIT_SUPPLIER_PHONE, cPhoneNo);

	GetDlgItemText(IDC_EDIT_SUPPLIER_ADDRESS, cAddress);

	GetDlgItemText(IDC_EDIT_SUPPLIER_EMAIL, cEmail);

	CT2CA lpstrName(cName);
	CT2CA lpstrPhoneNo(cPhoneNo);
	CT2CA lpstrAddress(cAddress);
	CT2CA lpstrEmail(cEmail);

	dl.insertToFabricSupplier(std::string(lpstrName), std::string(lpstrPhoneNo), std::string(lpstrEmail), std::string(lpstrAddress));
}
