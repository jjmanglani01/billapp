// FabricItemForm.cpp : implementation file
//

#include "stdafx.h"
#include "FabricItemForm.h"
#include "FabricItem.h"
#include "Response.h"
#include "resource.h"
#include "Helper.h"

// FabricItemForm

IMPLEMENT_DYNCREATE(FabricItemForm, CFormView)

FabricItemForm::FabricItemForm()
	: CFormView(IDD_FABRICITEMFORM)
{

}

FabricItemForm::~FabricItemForm()
{
}

void FabricItemForm::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(FabricItemForm, CFormView)
	ON_BN_CLICKED(IDC_BUTTON_FABRICITEMSAVE, &FabricItemForm::OnBnClickedButtonFabricitemsave)
	ON_EN_CHANGE(IDC_EDIT_FABRICITEMQUANTITY, &FabricItemForm::OnEnChangeEditFabricitemquantity)
	ON_EN_CHANGE(IDC_EDIT_FABRICITEMUNITPRICE, &FabricItemForm::OnEnChangeEditFabricitemunitprice)
END_MESSAGE_MAP()


// FabricItemForm diagnostics

#ifdef _DEBUG
void FabricItemForm::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FabricItemForm::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// FabricItemForm message handlers


void FabricItemForm::OnBnClickedButtonFabricitemsave()
{
	FabricItem oFabricItem;
	CString cName, cShortcut, cQuantity, cUnitPrice, cColor, cFabricType;


	GetDlgItemText(IDC_EDIT_FABRICITEMNAME, cName);

	GetDlgItemText(IDC_EDIT_FABRICITEMSHORTCUT, cShortcut);

	GetDlgItemText(IDC_EDIT_FABRICITEMQUANTITY, cQuantity);

	GetDlgItemText(IDC_EDIT_FABRICITEMUNITPRICE, cUnitPrice);

	GetDlgItemText(IDC_EDIT_FABRICITEMCOLOR, cColor);

	GetDlgItemText(IDC_EDIT_FABRICITEMTYPE, cFabricType);

	Response stResponse;
	stResponse = oFabricItem.setFabricName(Helper::convertCstringToString(cName));
	if (Helper::showDialog(stResponse))
	{
		return;
	}

	stResponse = oFabricItem.setFabricShortcut(Helper::convertCstringToString(cShortcut));
	if (Helper::showDialog(stResponse))
	{
		return;
	}

	stResponse = oFabricItem.setFabricQuantity(_tstof(cQuantity));
	if (Helper::showDialog(stResponse))
	{
		return;
	}

	stResponse = oFabricItem.setFabricUnitPrice(_tstof(cUnitPrice));
	if (Helper::showDialog(stResponse))
	{
		return;
	}

	stResponse = oFabricItem.setFabricColor(Helper::convertCstringToString(cColor));
	if (Helper::showDialog(stResponse))
	{
		return;
	}

	stResponse = oFabricItem.setFabricType(Helper::convertCstringToString(cFabricType));
	if (Helper::showDialog(stResponse))
	{
		return;
	}

	oFabricItem.save();
}


void FabricItemForm::OnEnChangeEditFabricitemquantity()
{
	CString value;

	CEdit* m_ValueEditBox = (CEdit*)GetDlgItem(IDC_EDIT_FABRICITEMQUANTITY);
	m_ValueEditBox->GetWindowText(value);   //m_ValueEditBox is a variable for EditControl

										   //Cursor position in Edit Control
	int lastSel = m_ValueEditBox->GetSel();

	if (Helper::validateDoubleString(value))
	{
		m_valueQuantity = value;   //m_ValueText  is a variable of type CString to hold old value of EditControl
	}
	else
	{
		m_ValueEditBox->SetWindowText(m_valueQuantity);

		//Setting the cursor position to previous position
		/* This step is very important, because if it is not written then cursor will move to left or right after above step depending whether the text is left or right aligned.*/
		m_ValueEditBox->SetSel(lastSel);
		Helper::showDialog(NOT_ACCEPTED_VALUE);
	}
}


void FabricItemForm::OnEnChangeEditFabricitemunitprice()
{
	CString value;

	CEdit* m_ValueEditBox = (CEdit*)GetDlgItem(IDC_EDIT_FABRICITEMUNITPRICE);
	m_ValueEditBox->GetWindowText(value);   //m_ValueEditBox is a variable for EditControl

											//Cursor position in Edit Control
	int lastSel = m_ValueEditBox->GetSel();

	if (Helper::validateDoubleString(value))
	{
		m_valueUnitPrice = value;   //m_ValueText  is a variable of type CString to hold old value of EditControl
	}
	else
	{
		m_ValueEditBox->SetWindowText(m_valueUnitPrice);

		//Setting the cursor position to previous position
		/* This step is very important, because if it is not written then cursor will move to left or right after above step depending whether the text is left or right aligned.*/
		m_ValueEditBox->SetSel(lastSel);
		Helper::showDialog(NOT_ACCEPTED_VALUE);
	}
}
