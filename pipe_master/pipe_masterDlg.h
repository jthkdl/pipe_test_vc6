// pipe_masterDlg.h : header file
//

#if !defined(AFX_PIPE_MASTERDLG_H__7686E72E_7A66_42EE_AEE4_F6394597D921__INCLUDED_)
#define AFX_PIPE_MASTERDLG_H__7686E72E_7A66_42EE_AEE4_F6394597D921__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPipe_masterDlg dialog

class CPipe_masterDlg : public CDialog
{
// Construction
public:
	CPipe_masterDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPipe_masterDlg)
	enum { IDD = IDD_PIPE_MASTER_DIALOG };
	CEdit	m_MsgCEdit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPipe_masterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPipe_masterDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PIPE_MASTERDLG_H__7686E72E_7A66_42EE_AEE4_F6394597D921__INCLUDED_)
