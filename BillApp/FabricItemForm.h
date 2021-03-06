#pragma once



// FabricItemForm form view

class FabricItemForm : public CFormView
{
	DECLARE_DYNCREATE(FabricItemForm)

private:
	CString m_valueQuantity;
	CString m_valueUnitPrice;
public:
	FabricItemForm();           // protected constructor used by dynamic creation
	virtual ~FabricItemForm();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FABRICITEMFORM };
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
public:
	afx_msg void OnBnClickedButtonFabricitemsave();
	afx_msg void OnEnChangeEditFabricitemquantity();
	afx_msg void OnEnChangeEditFabricitemunitprice();
};


