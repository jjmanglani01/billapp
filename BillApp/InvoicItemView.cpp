// InvoicItemView.cpp : implementation file
//

#include "stdafx.h"
#include "BillApp.h"
#include "InvoicItemView.h"


// InvoicItemView

IMPLEMENT_DYNCREATE(InvoicItemView, CFormView)

InvoicItemView::InvoicItemView()
	: CFormView(IDD_INVOICITEMVIEW)
{

}

InvoicItemView::~InvoicItemView()
{
}

void InvoicItemView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(InvoicItemView, CFormView)
END_MESSAGE_MAP()


// InvoicItemView diagnostics

#ifdef _DEBUG
void InvoicItemView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void InvoicItemView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// InvoicItemView message handlers
