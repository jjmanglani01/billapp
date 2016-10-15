#pragma once



// InvoicItemView form view

class InvoicItemView : public CFormView
{
	DECLARE_DYNCREATE(InvoicItemView)

protected:
	InvoicItemView();           // protected constructor used by dynamic creation
	virtual ~InvoicItemView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INVOICITEMVIEW };
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


