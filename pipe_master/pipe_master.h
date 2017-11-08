// pipe_master.h : main header file for the PIPE_MASTER application
//

#if !defined(AFX_PIPE_MASTER_H__5A754320_0264_4E75_863E_481EDE15D138__INCLUDED_)
#define AFX_PIPE_MASTER_H__5A754320_0264_4E75_863E_481EDE15D138__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

#ifdef _DEBUG
#define DBGPRINT  	_tprintf
#else
#define DBGPRINT    1 ? (void)0 : _tprintf
#endif

/////////////////////////////////////////////////////////////////////////////
// CPipe_masterApp:
// See pipe_master.cpp for the implementation of this class
//

class CPipe_masterApp : public CWinApp
{
public:
	CPipe_masterApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPipe_masterApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPipe_masterApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PIPE_MASTER_H__5A754320_0264_4E75_863E_481EDE15D138__INCLUDED_)
