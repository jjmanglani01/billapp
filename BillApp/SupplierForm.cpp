// SupplierForm.cpp : implementation file
//

#include "stdafx.h"
#include "BillApp.h"
#include "SupplierForm.h"
#include "FabricSupplier.h"
#include "Helper.h"
#include "Response.h"

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
	FabricSupplier oFabricSupplier;
	CString cName;
	CString cPhoneNo;
	CString cAddress1;
	CString cAddress2;
	CString cCity;
	CString cState;
	CString cEmail;

	GetDlgItemText(IDC_EDIT_SUPPLIER_NAME, cName);

	GetDlgItemText(IDC_EDIT_SUPPLIER_ADDRESS1, cAddress1);

	GetDlgItemText(IDC_EDIT_SUPPLIER_ADDRESS2, cAddress2);

	GetDlgItemText(IDC_EDIT_SUPPLIER_CITY, cCity);

	GetDlgItemText(IDC_EDIT_SUPPLIER_STATE, cState);

	GetDlgItemText(IDC_EDIT_SUPPLIER_EMAIL, cEmail);

	Response stResponse;
	stResponse = oFabricSupplier.setName(Helper::convertCstringToString(cName));
	if (Helper::showDialog(stResponse))
	{
		return;
	}

	stResponse = oFabricSupplier.setAddress1(Helper::convertCstringToString(cAddress1));
	if (Helper::showDialog(stResponse))
	{
		return;
	}

	stResponse = oFabricSupplier.setAddress2(Helper::convertCstringToString(cAddress2));
	if (Helper::showDialog(stResponse))
	{
		return;
	}
	
	stResponse = oFabricSupplier.setCity(Helper::convertCstringToString(cCity));
	if (Helper::showDialog(stResponse))
	{
		return;
	}

	stResponse = oFabricSupplier.setState(Helper::convertCstringToString(cState));
	if (Helper::showDialog(stResponse))
	{
		return;
	}
	
	stResponse = oFabricSupplier.setEmail(Helper::convertCstringToString(cEmail));
	if (Helper::showDialog(stResponse))
	{
		return;
	}
	
	oFabricSupplier.save();
}
