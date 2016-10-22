#pragma once

#ifndef __FABRICINVOICEVIEW_H_INCLUDED_
#define __FABRICINVOICEVIEW_H_INCLUDED_

#include "stdafx.h"
#include "MyCUG.h"
class CCustomAutoComplete;
// FabricInvoiceView form view

class FabricInvoiceView : public CFormView
{
	DECLARE_DYNCREATE(FabricInvoiceView)
private:
	MyCug m_grid;
	std::shared_ptr<Invoice> m_ptrInvoice;
	CButton m_btnSave;
	CDateTimeCtrl m_date;
	CEdit m_editSupplierID;
	CEdit m_editSupplierName;
	std::unique_ptr<CCustomAutoComplete> m_pAutoComplete;
public:
	FabricInvoiceView();           
	~FabricInvoiceView();
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
public:
	afx_msg void OnBnClickedButtonFabricinvoiceSave();
};

#endif