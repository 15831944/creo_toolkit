// LuaTest.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "LuaTest.h"

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

// CLuaTestApp

BEGIN_MESSAGE_MAP(CLuaTestApp, CWinApp)
END_MESSAGE_MAP()

// CLuaTestApp ����

CLuaTestApp::CLuaTestApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CLuaTestApp ����

CLuaTestApp theApp;

// CLuaTestApp ��ʼ��

BOOL CLuaTestApp::InitInstance()
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
	ProUIMessageDialogDisplay(PROUIMESSAGE_INFO, L"Warning", Message, buttons, PRO_UI_MESSAGE_OK, &user_choice);
	ProArrayFree((ProArray *)&buttons);
	return PRO_TK_NO_ERROR;
}

lua_State *L;
int luaAdd(int x, int y)
{
	int sum;
	lua_getglobal(L, "add");
	lua_pushnumber(L, x);
	lua_pushnumber(L, y);
	lua_call(L, 2, 1);
	sum = (int)lua_tonumber(L, -1);
	lua_pop(L, 1);
	return sum;
}

extern "C" int user_initialize()
{
	ProError status;
	status = ShowDialog(L"����lua����2+3");

	L = luaL_newstate();
	luaopen_base(L);
	luaL_openlibs(L);
	luaL_loadfile(L, "D:\\mydoc\\creo_toolkit\\LuaTest\\add.lua");
	lua_pcall(L, 0, LUA_MULTRET, 0);
	int sum = luaAdd(2, 3);
	lua_close(L);

	WCHAR buf[5];
	wsprintfW(buf, L"%d", sum);
	status = ShowDialog(buf);

	return PRO_TK_NO_ERROR;
}
extern "C" void user_terminate()
{
	ProError status;
	status = ShowDialog(L"�������˳�");
}