#pragma once
#ifndef __FABRICPAYMENTVIEW_H_INCLUDED_
#define __FABRICPAYMENTVIEW_H_INCLUDED_


// FabricPaymentView form view

class FabricPaymentView : public CFormView
{
	DECLARE_DYNCREATE(FabricPaymentView)

private:
	CDateTimeCtrl m_datePayment, m_dateCheque;
public:
	FabricPaymentView();           // protected constructor used by dynamic creation
	virtual ~FabricPaymentView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FABRICPAYMENTVIEW };
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
	afx_msg void OnBnClickedButtonPaymentFabricSave();
};


#endif