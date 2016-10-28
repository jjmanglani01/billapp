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

	CString cId, cDatePayment, cName, cPaymentType, cAmount, cChequeNo, cDateCheque;

	CTime datePayment, dateCheque;

	m_datePayment.GetTime(datePayment);
	m_dateCheque.GetTime(dateCheque);

	GetDlgItemText(IDC_EDIT_PAYMENT_FABRIC_SUPPLIER_ID, cId);

	GetDlgItemText(IDC_EDIT_PAYMENT_FABRIC_SUPPLIER_NAME, cName);

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

}
