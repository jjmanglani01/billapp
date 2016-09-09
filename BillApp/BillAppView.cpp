
// BillAppView.cpp : implementation of the CBillAppView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "BillApp.h"
#endif

#include "BillAppDoc.h"
#include "BillAppView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBillAppView

IMPLEMENT_DYNCREATE(CBillAppView, CView)

BEGIN_MESSAGE_MAP(CBillAppView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CBillAppView construction/destruction

CBillAppView::CBillAppView()
{
	// TODO: add construction code here
}

CBillAppView::~CBillAppView()
{
}

BOOL CBillAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CBillAppView drawing

void CBillAppView::OnDraw(CDC* pDC)
{
	CBillAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CBillAppView printing

BOOL CBillAppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBillAppView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBillAppView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CBillAppView diagnostics

#ifdef _DEBUG
void CBillAppView::AssertValid() const
{
	CView::AssertValid();
}

void CBillAppView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBillAppDoc* CBillAppView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBillAppDoc)));
	return (CBillAppDoc*)m_pDocument;
}
#endif //_DEBUG


// CBillAppView message handlers
