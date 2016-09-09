#pragma once



// SupplierForm form view

class SupplierForm : public CFormView
{
	DECLARE_DYNCREATE(SupplierForm)

public:
	SupplierForm(); 
	virtual ~SupplierForm();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SUPPLIERFORM };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	virtual void OnDraw(CDC *);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedSupplierAdd();
};


