// ToolkitCsharp.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "ToolkitCsharp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CToolkitCsharpApp

BEGIN_MESSAGE_MAP(CToolkitCsharpApp, CWinApp)
END_MESSAGE_MAP()

// CToolkitCsharpApp ����

CToolkitCsharpApp::CToolkitCsharpApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CToolkitCsharpApp ����

CToolkitCsharpApp theApp;

// CToolkitCsharpApp ��ʼ��

BOOL CToolkitCsharpApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

extern "C"  void SaveFile()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	ProError status;
	status = ProMacroLoad(L"~ Command `ProCmdModelSave` ;~ Activate `file_saveas` `OK`;");
}

static uiCmdAccessState AccessDefault(uiCmdAccessMode access_mode)
{
	return (ACCESS_AVAILABLE);
}

DWORD CallCSharpFun(LPCWSTR DotNetVer, LPCWSTR DLLfile, LPCWSTR NameSpace, LPCWSTR FunctionName, LPCWSTR Param)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HRESULT hr;
	ICLRMetaHost *pMetaHost = NULL;
	ICLRRuntimeInfo *pRuntimeInfo = NULL;
	ICLRRuntimeHost *pClrRuntimeHost = NULL;
	DWORD pReturnValue;

	hr = CLRCreateInstance(CLSID_CLRMetaHost, IID_PPV_ARGS(&pMetaHost));
	hr = pMetaHost->GetRuntime(DotNetVer, IID_PPV_ARGS(&pRuntimeInfo));
	hr = pRuntimeInfo->GetInterface(CLSID_CLRRuntimeHost, IID_PPV_ARGS(&pClrRuntimeHost));
	hr = pClrRuntimeHost->Start();
	hr = pClrRuntimeHost->ExecuteInDefaultAppDomain(DLLfile, NameSpace, FunctionName, Param, &pReturnValue);
	pMetaHost->Release();
	pRuntimeInfo->Release();
	pClrRuntimeHost->Release();
	return pReturnValue;
}

void ShowCSharpDlg()
{
	LPCWSTR DotNetVer, DLLfile, NameSpace, FunctionName, Param;
	DotNetVer = L"v4.0.30319";
	DLLfile = L"D:\\mydoc\\creo_toolkit\\ToolkitCsharp\\x64\\Debug\\CsharpDll.dll";
	NameSpace = L"CsharpDll.MyDialog";
	FunctionName = L"ShowWindow";
	Param = L"ֻ�ܴ���1���ַ�����������ӿ��Կ�����txt�ļ�·������";
	CallCSharpFun(DotNetVer, DLLfile, NameSpace, FunctionName, Param);
}

extern "C" int user_initialize()
{
	ProError status;
	uiCmdCmdId ToolkitCsharpID;

	status = ProMenubarMenuAdd("ToolkitCsharp", "ToolkitCsharp", "About", PRO_B_TRUE, MSGFILE);
	status = ProMenubarmenuMenuAdd("ToolkitCsharp", "ToolkitCsharp", "ToolkitCsharp", NULL, PRO_B_TRUE, MSGFILE);

	status = ProCmdActionAdd("ToolkitCsharp_Act", (uiCmdCmdActFn)ShowCSharpDlg, uiProeImmediate, AccessDefault, PRO_B_TRUE, PRO_B_TRUE, &ToolkitCsharpID);
	status = ProMenubarmenuPushbuttonAdd("ToolkitCsharp", "ToolkitCsharpmenu", "ToolkitCsharpmenu", "ToolkitCsharpmenutips", NULL, PRO_B_TRUE, ToolkitCsharpID, MSGFILE);

	return PRO_TK_NO_ERROR;
}

extern "C" void user_terminate()
{
}
