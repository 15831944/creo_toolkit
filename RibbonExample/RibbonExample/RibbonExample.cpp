// RibbonExample.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "RibbonExample.h"

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

// CRibbonExampleApp

BEGIN_MESSAGE_MAP(CRibbonExampleApp, CWinApp)
END_MESSAGE_MAP()


// CRibbonExampleApp ����

CRibbonExampleApp::CRibbonExampleApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CRibbonExampleApp ����

CRibbonExampleApp theApp;


// CRibbonExampleApp ��ʼ��

BOOL CRibbonExampleApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

CString _lastRibbonTab;
ProMdl CurrentMdl()
{
	ProMdl mdl;
	ProError status;
	status = ProMdlCurrentGet (&mdl);
	return mdl;
}

int CurrentMdlType()
{
	ProMdl mdl;
	ProMdlType mdltype;
	ProError status;
	status = ProMdlCurrentGet(&mdl);
	if (status != PRO_TK_NO_ERROR)
		return -1;
	status = ProMdlTypeGet(mdl, &mdltype);
	if (status != PRO_TK_NO_ERROR)
		return -1;
	else
		return mdltype;
}

static uiCmdAccessState AccessDrawing(uiCmdAccessMode access_mode)
{
	if (CurrentMdlType() == PRO_DRAWING)
		return ACCESS_AVAILABLE;
	else
		return ACCESS_INVISIBLE;
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

void WrongAct()
{
	ProError status;
	status = ShowDialog(L"ע��Ribbon����Ҫ�л�����ͼ����");
	status = ProMacroLoad(L"~ Command `ProCmdDwgRegenModel` ; ~Command `ProCmdWinActivate`;");
}

void RightAct()
{
	ProError status;
	CString macro;
	status = ShowDialog(L"ͬ���Ĺ��ܽ�ֹ��Ribbon������л�");
	macro = "~ Command `ProCmdDwgRegenModel` ; ~Command `ProCmdWinActivate`;";
	if(_lastRibbonTab != "")
	{
		macro += _T("~ Activate `main_dlg_cur` `" + _lastRibbonTab + "_control_btn` 1;");
	}
	wchar_t *p = macro.AllocSysString();
	status = ProMacroLoad(p);
	SysFreeString(p);
}

void LoadRibbonAct()
{
	ProError status;
	status = ProRibbonDefinitionfileLoad(L"RibbonExample.rbn");
}

ProError ProRibbonTabSwitchNotification(char* from_tab, char* to_tab)
{
	_lastRibbonTab = CString(to_tab);
	return PRO_TK_NO_ERROR;
}

extern "C" int user_initialize()
{
	ProError status;
	uiCmdCmdId WrongActID, RightActID, LoadRibbonItemID;

	status = ProMenubarMenuAdd("RibbonExample", "RibbonExample", "Help", PRO_B_TRUE, MSGFILE);
	status = ProMenubarmenuMenuAdd("RibbonExample", "MainMenu", "MainMenu", NULL, PRO_B_TRUE, MSGFILE);
	
	status = ProCmdActionAdd("WrongMainMenu_Act", (uiCmdCmdActFn)WrongAct, uiProeImmediate, AccessDrawing, PRO_B_TRUE, PRO_B_TRUE, &WrongActID);
	status = ProMenubarmenuPushbuttonAdd("MainMenu", "WrongMenuItem", "WrongMenuItem", "WrongMenuItemtips", NULL, PRO_B_TRUE, WrongActID, MSGFILE);
	
	status = ProCmdActionAdd("RightMainMenu_Act", (uiCmdCmdActFn)RightAct, uiProeImmediate, AccessDrawing, PRO_B_TRUE, PRO_B_TRUE, &RightActID);
	status = ProMenubarmenuPushbuttonAdd("MainMenu", "RightMenuItem", "RightMenuItem", "RightMenuItemtips", NULL, PRO_B_TRUE, RightActID, MSGFILE);
	
	status = ProCmdActionAdd("LoadRibbonItem_Act", (uiCmdCmdActFn)LoadRibbonAct, uiProeImmediate, AccessDrawing, PRO_B_TRUE, PRO_B_TRUE, &LoadRibbonItemID);
	status = ProMenubarmenuPushbuttonAdd("MainMenu", "LoadRibbonItem", "LoadRibbonItem", "LoadRibbonItemtips", NULL, PRO_B_TRUE, LoadRibbonItemID, MSGFILE);
	
	status = ProNotificationSet(PRO_RIBBON_TAB_SWITCH,  (ProFunction)ProRibbonTabSwitchNotification);
	return PRO_TK_NO_ERROR;
}

extern "C" void user_terminate()
{
	ProError status;
	status = ProNotificationUnset(PRO_RIBBON_TAB_SWITCH);
}