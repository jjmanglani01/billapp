// FabricPaymentView.cpp : implementation file
//

#include "stdafx.h"
#include "BillApp.h"
#include "FabricPaymentView.h"
#include "FabricPayment.h"
#include "Helper.h"
#include "Response.h"

// FabricPaymentView

IMPLEMENT_DYNCREATE(FabricPaymentView, CFormView)

FabricPaymentView::FabricPaymentView()
	: CFormView(IDD_FABRICPAYMENTVIEW)
{

}

FabricPaymentView::~FabricPaymentView()
{
}

void FabricPaymentView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DATETIMEPICKER_PAYMENT_FABRIC, m_datePayment);
	DDX_Control(pDX, IDC_DATETIMEPICKER_PAYMENT_FABRIC_CHEQUE_DATE, m_dateCheque);

	m_datePayment.SetFormat(_T("dddd, dd MMMM, yyyy"));
	m_dateCheque.SetFormat(_T("dddd, dd MMMM, yyyy"));
}

BEGIN_MESSAGE_MAP(FabricPaymentView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON_PAYMENT_FABRIC_SAVE, &FabricPaymentView::OnBnClickedButtonPaymentFabricSave)
	ON_EN_CHANGE(IDC_EDIT_PAYMENT_FABRIC_AMOUNT, &FabricPaymentView::OnEnChangeEditPaymentFabricAmount)
END_MESSAGE_MAP()


// FabricPaymentView diagnostics

#ifdef _DEBUG
void FabricPaymentView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FabricPaymentView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// FabricPaymentView message handlers

void FabricPaymentView::OnBnClickedButtonPaymentFabricSave()
{
	FabricPayment oPayment;

	CString cId, cDatePayment, cPaymentType, cAmount, cChequeNo, cDateCheque;

	CTime datePayment, dateCheque;

	m_datePayment.GetTime(datePayment);
	m_dateCheque.GetTime(dateCheque);

	GetDlgItemText(IDC_EDIT_PAYMENT_FABRIC_SUPPLIER_ID, cId);

	GetDlgItemText(IDC_COMBO_PAYMENT_FABRIC_PAYMENT_TYPE, cPaymentType);

	GetDlgItemText(IDC_EDIT_PAYMENT_FABRIC_CHEQUE_NO, cChequeNo);

	GetDlgItemText(IDC_EDIT_PAYMENT_FABRIC_AMOUNT, cAmount);

	cDatePayment = datePayment.Format(_T("%Y-%m-%d %H:%M:%S "));

	cDateCheque = dateCheque.Format(_T("%Y-%m-%d %H:%M:%S "));

	oPayment.setFabricSupplierID(Helper::convertCstringToInt(cId));

	Response stResponse;

	stResponse = oPayment.setPaymentDate(Helper::convertCstringToString(cDatePayment));

	if (Helper::showDialog(stResponse)) {
		return;
	}

	stResponse = oPayment.setPaymentType(Helper::convertCstringToString(cPaymentType));

	if (Helper::showDialog(stResponse)) {
		return;
	}

	stResponse = oPayment.setAmount(_tstof(cAmount));
	if (Helper::showDialog(stResponse)) {
		return;
	}

	stResponse = oPayment.setChequeDate(Helper::convertCstringToString(cChequeNo));
	if (Helper::showDialog(stResponse)) {
		return;
	}

	stResponse = oPayment.setChequeDate(Helper::convertCstringToString(cDateCheque));
	if (Helper::showDialog(stResponse)) {
		return;
	}
	oPayment.save();
}


void FabricPaymentView::OnEnChangeEditPaymentFabricAmount()
{
	CString value;

	CEdit* ctrlEditBox = (CEdit*)GetDlgItem(IDC_EDIT_PAYMENT_FABRIC_AMOUNT);
	ctrlEditBox->GetWindowText(value);   //m_ValueEditBox is a variable for EditControl

	int lastSel = ctrlEditBox->GetSel();

	if (Helper::validateDoubleString(value))
	{
		m_valueAmount = value;   //m_ValueText  is a variable of type CString to hold old value of EditControl
	}
	else
	{
		ctrlEditBox->SetWindowText(m_valueAmount);

		//Setting the cursor position to previous position
		/* This step is very important, because if it is not written then cursor will move to left or right after above step depending whether the text is left or right aligned.*/
		ctrlEditBox->SetSel(lastSel);
		Helper::showDialog(NOT_ACCEPTED_VALUE);
	}
}
