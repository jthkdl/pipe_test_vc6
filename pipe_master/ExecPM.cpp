// ExecPM.cpp: implementation of the CExecPM class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ExecPM.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CExecPM::CExecPM()
{

}

CExecPM::~CExecPM()
{

}

int CExecPM::exec(LPCTSTR szCmdLine, LPCTSTR szPath, DWORD dwTimeoutMs)
{
	int nRet = 0;
	CString csCmd = szCmdLine;
	PROCESS_INFORMATION   processInfo;   
	ZeroMemory(&processInfo,   sizeof(PROCESS_INFORMATION));
	STARTUPINFO startInfo;
	ZeroMemory(&startInfo,   sizeof(STARTUPINFO));
	startInfo.cb = sizeof(STARTUPINFO);

	if(CreateProcess(NULL,csCmd.GetBuffer(csCmd.GetLength()+1),NULL,NULL,FALSE,0,NULL,szPath,&startInfo,&processInfo) == FALSE) {
		nRet = -2;
		TRACE(_T("CreateProcess Error!\n"));
	}
	else 
	{
		DWORD waitret = WaitForSingleObject(processInfo.hProcess,   dwTimeoutMs);
		TRACE(_T("wait result = 0x%X\n"), waitret); // WAIT_TIMEOUT == 0x00000102L
		if (waitret == WAIT_OBJECT_0)
		{
			DWORD ExitCode;
			if (GetExitCodeProcess(processInfo.hProcess, &ExitCode))
			{
				nRet = ExitCode;
			}
			else nRet = -3;
		}
		else nRet = -128;

		// Close process and thread handles.
		CloseHandle( processInfo.hProcess );
		CloseHandle( processInfo.hThread );
	}
	csCmd.ReleaseBuffer();
	return nRet;
}

int CExecPM::exec_return(LPCTSTR szCmdLine, CByteArray &rAry, LPCTSTR szPath, DWORD dwTimeoutMs)
{
	int nRet = 0;
	CString csCmd = szCmdLine;
	HANDLE hRead,hWrite;
	rAry.RemoveAll();
	SECURITY_ATTRIBUTES sa;
	ZeroMemory(&sa,   sizeof(sa));
	sa.bInheritHandle = TRUE;
	sa.lpSecurityDescriptor = NULL;
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	if(CreatePipe(&hRead,&hWrite,&sa,0) == FALSE)
	{
		return -1;
	}
	
	PROCESS_INFORMATION   processInfo;   
	ZeroMemory(&processInfo,   sizeof(PROCESS_INFORMATION));
	STARTUPINFO startInfo;
	ZeroMemory(&startInfo,   sizeof(STARTUPINFO));
	startInfo.cb = sizeof(STARTUPINFO);
	startInfo.dwFlags = STARTF_USESTDHANDLES;
	startInfo.hStdInput  = GetStdHandle(STD_INPUT_HANDLE);//hRead;
	startInfo.hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);//hRead;//
	startInfo.hStdError  = hWrite;//GetStdHandle(STD_ERROR_HANDLE);//

	if(CreateProcess(NULL,csCmd.GetBuffer(csCmd.GetLength()+1),NULL,NULL,TRUE,0,NULL,szPath,&startInfo,&processInfo) == FALSE) 
	{
		nRet = -2;
		TRACE(_T("CreateProcess Error!\n"));
	}
	else 
	{
		DWORD waitret = WaitForSingleObject(processInfo.hProcess,   dwTimeoutMs);
		TRACE(_T("wait result = 0x%X\n"), waitret); // WAIT_TIMEOUT == 0x00000102L
		if (waitret == WAIT_OBJECT_0)
		{
			DWORD ExitCode;
			if (GetExitCodeProcess(processInfo.hProcess, &ExitCode))
			{
				nRet = ExitCode;
			}
			else nRet = -3;
			
			DWORD dwRead=64*1024;
			rAry.SetSize(dwRead);
			TRACE(_T("开始\n"));
			if (ReadFile(hRead,rAry.GetData(),dwRead,&dwRead,NULL) == FALSE)
			{
				dwRead = 0;
				TRACE(_T("读取数据失败！\n"));
			}
			else
			{
				TRACE(_T("读取成功！\n"));
			}
			rAry.SetSize(dwRead);
		}
		else nRet = -128;
		
		// Close process and thread handles.
		CloseHandle( processInfo.hProcess );
		CloseHandle( processInfo.hThread );
	}
	csCmd.ReleaseBuffer();
	CloseHandle(hRead);
	CloseHandle(hWrite);
	return nRet;
}
