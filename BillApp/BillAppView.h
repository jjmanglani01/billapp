
// BillAppView.h : interface of the CBillAppView class
//

#pragma once

class CBillAppView : public CView
{
protected: // create from serialization only
	CBillAppView();
	DECLARE_DYNCREATE(CBillAppView)

// Attributes
public:
	CBillAppDoc* GetDocument() const;
// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CBillAppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BillAppView.cpp
inline CBillAppDoc* CBillAppView::GetDocument() const
   { return reinterpret_cast<CBillAppDoc*>(m_pDocument); }
#endif

