// SqliteTest.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "SqliteTest.h"

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

// CSqliteTestApp

BEGIN_MESSAGE_MAP(CSqliteTestApp, CWinApp)
END_MESSAGE_MAP()

// CSqliteTestApp ����

CSqliteTestApp::CSqliteTestApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CSqliteTestApp ����

CSqliteTestApp theApp;

// CSqliteTestApp ��ʼ��

BOOL CSqliteTestApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

ProError ShowDialog(wchar_t *Message)
{
	ProUIMessageButton *buttons;
	ProUIMessageButton user_choice;
	ProArrayAlloc(1, sizeof(ProUIMessageButton), 1, (ProArray *)&buttons);
	buttons[0] = PRO_UI_MESSAGE_OK;
	ProUIMessageDialogDisplay(PROUIMESSAGE_INFO, L"��ʾ", Message, buttons, PRO_UI_MESSAGE_OK, &user_choice);
	ProArrayFree((ProArray *)&buttons);
	return PRO_TK_NO_ERROR;
}

int Utf82Unicode(const char *utf, wchar_t *unicode, int nBuffSize)
{
	if (!utf || !strlen(utf))
	{
		return 0;
	}
	int dwUnicodeLen = MultiByteToWideChar(CP_UTF8, 0, utf, -1, NULL, 0);
	size_t num = dwUnicodeLen * sizeof(wchar_t);
	if (num > nBuffSize)
	{
		return 0;
	}
	MultiByteToWideChar(CP_UTF8, 0, utf, -1, unicode, dwUnicodeLen);
	return dwUnicodeLen;
}

int callback(void *, int nCount, char **pValue, char **pName)
{
	CString str = _T("");
	for (int i = 0; i < nCount; i++)
	{
		wchar_t t[100];
		int a = Utf82Unicode(pValue[i], t, 100);
		str += CString(pName[i]) + _T("   ") + CString(t);
		str += _T("\n");
	}
	wchar_t *msg = str.AllocSysString();
	ShowDialog(msg);
	SysFreeString(msg);
	return 0;
}

extern "C" int user_initialize()
{
	ProError status;
	sqlite3 *db;
	char *sql = "SELECT * FROM TEST";
	char *zErrMsg = 0;

	status = ShowDialog(L"����������,׼�������ݿ⡣");

	int res = sqlite3_open("D:\\mydoc\\creo_toolkit\\SqliteTest\\test.db", &db);
	if (res != SQLITE_OK)
	{
		status = ShowDialog(L"���ݿ��ʧ�ܡ�");
		return PRO_TK_NO_ERROR;
	}

	res = sqlite3_exec(db, sql, callback, NULL, &zErrMsg);
	sqlite3_free(zErrMsg);
	sqlite3_close(db);
	return PRO_TK_NO_ERROR;
}
extern "C" void user_terminate()
{
	ProError status;
	status = ShowDialog(L"�������˳�");
}