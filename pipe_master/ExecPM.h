// ExecPM.h: interface for the CExecPM class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXECPM_H__B9DD3529_2B92_477F_B134_FE9660A71C3B__INCLUDED_)
#define AFX_EXECPM_H__B9DD3529_2B92_477F_B134_FE9660A71C3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CExecPM  
{
public:
	int exec_return(LPCTSTR szCmdLine, CByteArray & rAry, LPCTSTR szPath = NULL, DWORD dwTimeoutMs = INFINITE);
	int exec(LPCTSTR szCmdLine, LPCTSTR szPath = NULL, DWORD dwTimeoutMs = INFINITE);
	CExecPM();
	virtual ~CExecPM();

};

#endif // !defined(AFX_EXECPM_H__B9DD3529_2B92_477F_B134_FE9660A71C3B__INCLUDED_)
