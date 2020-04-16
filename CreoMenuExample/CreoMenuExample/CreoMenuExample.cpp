// CreoMenuExample.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "CreoMenuExample.h"

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

// CCreoMenuExampleApp

BEGIN_MESSAGE_MAP(CCreoMenuExampleApp, CWinApp)
END_MESSAGE_MAP()

// CCreoMenuExampleApp ����

CCreoMenuExampleApp::CCreoMenuExampleApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CCreoMenuExampleApp ����

CCreoMenuExampleApp theApp;

// CCreoMenuExampleApp ��ʼ��

BOOL CCreoMenuExampleApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

static uiCmdAccessState AccessDefault(uiCmdAccessMode access_mode)
{
	return ACCESS_AVAILABLE;
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

void MainMenuAct()
{
	ShowDialog(L"��������˵������ͼ����ģ����ѡ�������Ҽ�Ҳ������Ҽ��˵�������������˵�һ�¡��������ܽ�ֻ�����˶Ի���");
}


//static ProMenuItemName check_group_items[] = {"CheckButtonMenu"};
//static ProMenuItemLabel check_group_labels[] = {"CheckButtonMenuItem"};
//static ProMenuLineHelp check_group_help[] = {"CheckButtonMenuItemtips"};
//static ProCmdItemIcon check_group_icons[]={"Icon.png"};

typedef struct procheckbuttonstruct
{
	uiCmdCmdId command;
	ProBoolean state;
} ProCheckButton;

static ProCheckButton _checkbutton[1];

int CheckButtonActfn(uiCmdCmdId command, uiCmdValue *p_value, void *p_push_command_data)
{
	//Ӧ����ѭ����Ӧ������������ֻ��һ���˵������Լ���
	if (command == _checkbutton[0].command)
	{
		if (_checkbutton[0].state == PRO_B_FALSE)
		{
			_checkbutton[0].state = PRO_B_TRUE;
			ShowDialog(L"CheckButton�Ѱ��¡��������ܽ�ֻ�����˶Ի���");
		}
		else
		{
			_checkbutton[0].state = PRO_B_FALSE;
			ShowDialog(L"CheckButton���ɿ����������ܽ�ֻ�����˶Ի���");
		}
	}
	return 0;
}

int CheckButtonValFn(uiCmdCmdId command, uiCmdValue *p_value)
{
	ProError status;
	ProBoolean value;
	//Ӧ����ѭ������Ӧ������������ֻ��һ���˵������Լ���
	if (_checkbutton[0].command == command)
	{
		status = ProMenubarmenuChkbuttonValueGet(p_value, &value);
		if (value == _checkbutton[0].state)
		{
			return 0;
		}
		status = ProMenubarmenuChkbuttonValueSet(p_value, _checkbutton[0].state);
		return 0;
	}
	return 0;
}

static ProMenuItemName radio_group_items[] = {"RadioButtonMenu1", "RadioButtonMenu2","RadioButtonMenu3", "RadioButtonMenu4"};
static ProMenuItemLabel radio_group_labels[] = {"RadioButtonMenuItem1", "RadioButtonMenuItem2","RadioButtonMenuItem3","RadioButtonMenuItem4"};
static ProMenuLineHelp radio_group_help[] = {"RadioButtonMenuItem1tips", "RadioButtonMenuItem2tips","RadioButtonMenuItem3tips","RadioButtonMenuItem4tips"};
static ProCmdItemIcon radio_group_icons[]={"Icon.png", "Icon.png","Icon.png", "Icon.png"};

int RadioButtonValFn(uiCmdCmdId command, uiCmdValue *p_value)
{
	ProError status;
	ProMenuItemName name;

	status = ProMenubarMenuRadiogrpValueGet (p_value, name);
	status = ProMenubarMenuRadiogrpValueSet(p_value, name);
	return 0;
}

int RadioButtonActFn(uiCmdCmdId command, uiCmdValue *p_value)
{
	ProError status;
	ProMenuItemName  name;
	status = ProMenubarMenuRadiogrpValueGet(p_value, name);
	if(strcmp(name,"RadioButtonMenu1") ==0)
	{
		ShowDialog(L"ѡ����RadioButton��1���������ܽ�ֻ�����˶Ի���");
	}
	else if(strcmp(name,"RadioButtonMenu2") ==0)
	{
		ShowDialog(L"ѡ����RadioButton��2���������ܽ�ֻ�����˶Ի���");
	}
	else if(strcmp(name,"RadioButtonMenu3") ==0)
	{
		ShowDialog(L"ѡ����RadioButton��3���������ܽ�ֻ�����˶Ի���");
	}
	else if(strcmp(name,"RadioButtonMenu4") ==0)
	{
		ShowDialog(L"ѡ����RadioButton��4���������ܽ�ֻ�����˶Ի���");
	}
	else
	{
		ShowDialog(L"������һ��������Ӧ�ô��ڵġ�");
	}
	return 0;
}

static uiCmdAccessState AccessPopupmenu(uiCmdCmdId command,ProAppData appdata, ProSelection* sel_buffer)
{
	//Ӧ�ø���ѡ��Ķ���ȷ���Ҽ��˵��Ƿ���֣�����Ĭ�϶�����
	return ACCESS_AVAILABLE;
}

ProError ProPopupMenuNotification(ProMenuName name)
{
	ProError status;
	uiCmdCmdId MainMenuID;
	ProPopupMenuId PopupMenuID;
	ProLine label;
	ProLine help;

	status = ProPopupmenuIdGet(name, &PopupMenuID);
	status = ProCmdCmdIdFind("MainMenu_Act", &MainMenuID);
	status = ProMessageToBuffer(label, MSGFILE,"MainMenuItem");
	status = ProMessageToBuffer(help, MSGFILE,"MainMenuItemtips");
	status = ProPopupmenuButtonAdd(PopupMenuID, PRO_VALUE_UNUSED, "HFUTGDM.MainMenu_Act",label, help,MainMenuID,AccessPopupmenu,NULL);

	return PRO_TK_NO_ERROR;
}

extern "C" int user_initialize()
{
	ProError status;
	uiCmdCmdId MainMenuID;
	uiCmdCmdId RadioMenuID;

	status = ProMenubarMenuAdd("CreoMenuExample", "CreoMenuExample", "Help", PRO_B_TRUE, MSGFILE);

	//��ͨ�˵�+ribbon��ť
	status = ProMenubarmenuMenuAdd("CreoMenuExample", "MainMenu", "MainMenu", NULL, PRO_B_TRUE, MSGFILE);
	status = ProCmdActionAdd("MainMenu_Act", (uiCmdCmdActFn)MainMenuAct, uiProeImmediate, AccessDefault, PRO_B_TRUE, PRO_B_TRUE, &MainMenuID);
	status = ProMenubarmenuPushbuttonAdd("MainMenu", "MainMenuItem", "MainMenuItem", "MainMenuItemtips", NULL, PRO_B_TRUE, MainMenuID, MSGFILE);
	status = ProCmdIconSet(MainMenuID, "Icon.png");
	status = ProCmdDesignate(MainMenuID, "MainMenuItem", "MainMenuItem", "MainMenuItemtips", MSGFILE);

	//��radio�Ĳ˵�+ribbon��ť
	status = ProMenubarmenuMenuAdd("CreoMenuExample", "RadioButtonMenu", "RadioButtonMenu", NULL, PRO_B_TRUE, MSGFILE);
	status = ProCmdOptionAdd("RadioButtonMenu_Act", (uiCmdCmdActFn)RadioButtonActFn, PRO_B_FALSE, (uiCmdCmdValFn)RadioButtonValFn, AccessDefault, PRO_B_TRUE, PRO_B_TRUE, &RadioMenuID);
	status = ProMenubarmenuRadiogrpAdd("RadioButtonMenu", "RadioButtonGroup",2, radio_group_items, radio_group_labels, radio_group_help,NULL, PRO_B_FALSE,RadioMenuID,MSGFILE);
	status = ProCmdRadiogrpDesignate(RadioMenuID, 4, radio_group_items, radio_group_labels, radio_group_help,radio_group_icons,"RadioButtonGroupDescription",MSGFILE);

	//��checkbox�Ĳ˵�+ribbon��ť�����ͼ�귽��δ֪
	status = ProMenubarmenuMenuAdd("CreoMenuExample", "CheckButtonMenu", "CheckButtonMenu", NULL, PRO_B_TRUE, MSGFILE);
	status = ProCmdOptionAdd("CheckButtonMenu_Act", (uiCmdCmdActFn)CheckButtonActfn, PRO_B_TRUE, (uiCmdCmdValFn)CheckButtonValFn, AccessDefault, PRO_B_TRUE, PRO_B_TRUE, &(_checkbutton[0].command));
	status = ProMenubarmenuChkbuttonAdd("CheckButtonMenu", "CheckButtonMenuItem", "CheckButtonMenuItem", "CheckButtonMenuItemtips", NULL, PRO_B_TRUE, _checkbutton[0].command, MSGFILE);
	status = ProCmdDesignate(_checkbutton[0].command, "CheckButtonMenuItem", "CheckButtonMenuItem", "CheckButtonMenuItemtips", MSGFILE);
	//status = ProCmdRadiogrpDesignate(_checkbutton[0].command,1,check_group_items,check_group_labels,check_group_help,check_group_icons,"CheckButtonGroupDescription",MSGFILE);
	//status = ProCmdIconSet(_checkbutton[0].command, "Icon.png");

	//ע���Ҽ��˵������¼�����������ͨ�˵�һ��
	status = ProNotificationSet(PRO_POPUPMENU_CREATE_POST,  (ProFunction)ProPopupMenuNotification);

	return PRO_TK_NO_ERROR;
}

extern "C" void user_terminate()
{
	ProError status;
	status = ProNotificationUnset(PRO_POPUPMENU_CREATE_POST);
}