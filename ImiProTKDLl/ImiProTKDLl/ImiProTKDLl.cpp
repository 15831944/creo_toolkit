// ImiProTKDLl.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "ImiProTKDLl.h"
#include "ImiDialogTest.h"
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

// CImiProTKDLlApp

BEGIN_MESSAGE_MAP(CImiProTKDLlApp, CWinApp)
END_MESSAGE_MAP()


// CImiProTKDLlApp ����

CImiProTKDLlApp::CImiProTKDLlApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CImiProTKDLlApp ����

CImiProTKDLlApp theApp;


// CImiProTKDLlApp ��ʼ��

BOOL CImiProTKDLlApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

extern "C" __declspec(dllexport) ImiDialogTest* ShowDialog()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	ImiDialogTest *Dialog = new ImiDialogTest;
	Dialog->Create(ImiDialogTest::IDD);
	Dialog->ShowWindow(SW_SHOW);
	return Dialog;
}