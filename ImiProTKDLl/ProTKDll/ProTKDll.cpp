// ProTKDll.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "ProTKDll.h"
/******************************************
��dll�������渴��,ע��include��Ŀ¼��ϵ��
IDD_IMIDIALOGTEST = 16000����ImiProTKDLl���̵�res�ļ�,�������û�ж��壬���ض�����
******************************************/
#define IDD_IMIDIALOGTEST 16000
#include "..\ImiProTKDLl\ImiDialogTest.h"

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

// CProTKDllApp

BEGIN_MESSAGE_MAP(CProTKDllApp, CWinApp)
END_MESSAGE_MAP()

// CProTKDllApp ����

CProTKDllApp::CProTKDllApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CProTKDllApp ����

CProTKDllApp theApp;

// CProTKDllApp ��ʼ��

BOOL CProTKDllApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
static uiCmdAccessState AccessDefault(uiCmdAccessMode access_mode)
{
	return (ACCESS_AVAILABLE);
}
void Test()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	ProPath exec_path;
	ProToolkitApplExecPathGet(exec_path);

	HINSTANCE m_hDll = LoadLibrary(CString(exec_path).Left((CString(exec_path)).GetLength() - 12) + _T("ImiProTKDLl.dll"));
	if (NULL == m_hDll)
		AfxMessageBox(_T("���� ImiProTKDLl.dll ʧ��"));
	typedef ImiDialogTest *(*hpDllFun)();
	hpDllFun pShowDlg = (hpDllFun)GetProcAddress(m_hDll, "ShowDialog");
	if (NULL == pShowDlg)
	{
		AfxMessageBox(_T("DLL�к���Ѱ��ʧ��"));
		return;
	}
	//ָ�룬�ڴ�й©,�����Ӳ�������
	ImiDialogTest *imiDialogTest = pShowDlg();
}
extern "C" int user_initialize()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	AfxInitRichEdit2();
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);
	AfxEnableControlContainer();

	ProError status;
	uiCmdCmdId Test_cmd_id1;
	status = ProMenubarMenuAdd("Test", "Test", "File", PRO_B_TRUE, L"Test.txt");

	status = ProCmdActionAdd("Test_Act1", (uiCmdCmdActFn)Test, uiProeImmediate, AccessDefault, PRO_B_TRUE, PRO_B_TRUE, &Test_cmd_id1);
	status = ProMenubarmenuPushbuttonAdd("Test", "Cmd1", "Cmd1", "Tips1", NULL, PRO_B_TRUE, Test_cmd_id1, L"Test.txt");
	return PRO_TK_NO_ERROR;
}
extern "C" void user_terminate()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
}
