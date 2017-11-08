// pipe_slave.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "pipe_slave.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define MAIN_VER				100
/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;

static int MyMain(int argc, TCHAR* argv[]);
int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		cerr << _T("Fatal Error: MFC initialization failed") << endl;
		nRetCode = 1;
	}
	else
	{
		// TODO: code your application's behavior here.
		nRetCode = MyMain(argc, argv);
	}

	return nRetCode;
}

static int Usage(TCHAR* argv[])
{
	CString csTmp0 = argv[0];
	csTmp0 = csTmp0.Right(csTmp0.GetLength()-csTmp0.ReverseFind(_T('\\'))-1);
	cerr<< _T("Usage:\n") << (LPCTSTR)csTmp0 << _T(" \"\"") << endl;

	_tprintf(_T("ver %d.%02d\r\n@%s\r\n"),MAIN_VER/100,MAIN_VER%100,__TIMESTAMP__);
	cout<<"author:Jin Tao"<<endl<<"copyright 2016(c)"<<endl;
	return 2;
}

static int MyMain(int argc, TCHAR* argv[])
{
	if (argc<2 || _tcsrchr(argv[1],_T('?'))) {
		return Usage(argv);
	}

	return 0;
}
