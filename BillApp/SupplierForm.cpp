// SupplierForm.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "SupplierForm.h"
#include "FabricSupplier.h"
#include "Helper.h"
#include "Response.h"
#include "CustomAutoComplete.h"
#include "PhoneView.h"

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
void SupplierForm::OnInitialUpdate()
{
	CView* phoneView;
	phoneView = new PhoneView();
	//TODO: UI ID
	phoneView->Create(NULL, NULL, WS_CHILD|WS_VISIBLE, CRect(415, 0, 670, 180),this, 2001);
	phoneView->SendMessage(WM_INITIALUPDATE, 0, 0);
	m_vecPhoneView.push_back(phoneView);
	CCustomAutoComplete* m_pAutoComplete;

	m_pAutoComplete = new CCustomAutoComplete(HKEY_CURRENT_USER,
		_T("Software\\VBBox.com\\StgAutoCompleteDemo\\Recent"));
	CString str;
	str = "Jitesh";
	m_pAutoComplete->AddItem(str);

	str = "Manglani";
	m_pAutoComplete->AddItem(str);
	HWND hWnd;
	GetDlgItem(IDC_EDIT_SUPPLIER_NAME, &hWnd);
	m_pAutoComplete->Bind(hWnd, ACO_UPDOWNKEYDROPSLIST | ACO_AUTOSUGGEST | ACO_AUTOAPPEND, _T("www.%s.com"));
}


void SupplierForm::OnClickedSupplierAdd()
{
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

	for (int index = 0; index < m_vecPhoneView.size(); index++)
	{
		PhoneView* view = (PhoneView*)m_vecPhoneView[index];
		CString strPhoneNumber, strPhoneType, strPhoneDescription;

		view->m_cPhoneNumber.GetWindowTextW(strPhoneNumber);
		view->m_cPhoneType.GetWindowTextW(strPhoneType);
		view->m_cPhoneDesc.GetWindowTextW(strPhoneDescription);

		stResponse = oFabricSupplier.addPhoneNumber(Helper::convertCstringToString(strPhoneType), Helper::convertCstringToString(strPhoneDescription),
			Helper::convertCstringToString(strPhoneNumber));

		if (Helper::showDialog(stResponse))
		{
			return;
		}

	}
}
