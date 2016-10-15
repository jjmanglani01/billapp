// FabricInvoiceView.cpp : implementation file
//

#include "stdafx.h"
#include "BillApp.h"
#include "FabricInvoiceView.h"
#include "Helper.h"
#include "ItemInterface.h"
// FabricInvoiceView

IMPLEMENT_DYNCREATE(FabricInvoiceView, CFormView)

FabricInvoiceView::FabricInvoiceView()
	: CFormView(IDD_FABRICINVOICEVIEW)
{

}

FabricInvoiceView::~FabricInvoiceView()
{
}

void FabricInvoiceView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	m_grid.MoveWindow(20, 80, cx, cy-50);
	m_grid.SetHScrollMode(2);
	m_grid.SetVScrollMode(2);
	m_grid.SetHS_Height(cy - 130);
	m_grid.SetVS_Width(cx - 20);
}

void FabricInvoiceView::DoDataExchange(CDataExchange* pDX)
{
	m_grid.CreateGrid(WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this, 9999);
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(FabricInvoiceView, CFormView)
	ON_WM_SIZE()
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
