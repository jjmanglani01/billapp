#pragma once
#include "afxwin.h"



// PhoneView form view

class PhoneView : public CFormView
{
	DECLARE_DYNCREATE(PhoneView)
public:
	PhoneView();           // protected constructor used by dynamic creation
	virtual ~PhoneView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PHONEVIEW };
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
	CEdit m_cPhoneNumber;
	CComboBox m_cPhoneType;
	CEdit m_cPhoneDesc;
};


