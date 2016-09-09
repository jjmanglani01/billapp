
// BillApp.h : main header file for the BillApp application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CBillApp:
// See BillApp.cpp for the implementation of this class
//

class CBillApp : public CWinApp
{
public:
	CBillApp();

private:
	CView* m_pStartView;
	CView* m_pSupplierFormView;

// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	afx_msg void OnAddSupplier();
	bool SetActiveView(CView* pView);
	DECLARE_MESSAGE_MAP()
};

extern CBillApp theApp;
