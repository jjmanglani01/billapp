// PhoneView.cpp : implementation file
//

#include "stdafx.h"
#include "BillApp.h"
#include "PhoneView.h"


// PhoneView

IMPLEMENT_DYNCREATE(PhoneView, CFormView)

PhoneView::PhoneView()
	: CFormView(IDD_PHONEVIEW)
{

}

PhoneView::~PhoneView()
{
}

void PhoneView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_PHONENUMBER, m_cPhoneNumber);
	DDX_Control(pDX, IDC_COMBO_PHONETYPE, m_cPhoneType);
	DDX_Control(pDX, IDC_EDIT_PHONEDESCRIPTION, m_cPhoneDesc);
}

BEGIN_MESSAGE_MAP(PhoneView, CFormView)
END_MESSAGE_MAP()


// PhoneView diagnostics

#ifdef _DEBUG
void PhoneView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void PhoneView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// PhoneView message handlers
