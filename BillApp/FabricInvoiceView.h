#pragma once


#include "stdafx.h"
#include "MyCUG.h"

// FabricInvoiceView form view

class FabricInvoiceView : public CFormView
{
	DECLARE_DYNCREATE(FabricInvoiceView)
private:
	MyCug m_grid;
public:
	FabricInvoiceView();           // protected constructor used by dynamic creation
	virtual ~FabricInvoiceView();
protected:
	void OnSize(UINT nType, int cx, int cy);
public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FABRICINVOICEVIEW };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};


