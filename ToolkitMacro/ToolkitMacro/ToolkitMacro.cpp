// ToolkitMacro.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "ToolkitMacro.h"

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

// CToolkitMacroApp

BEGIN_MESSAGE_MAP(CToolkitMacroApp, CWinApp)
END_MESSAGE_MAP()

// CToolkitMacroApp ����

CToolkitMacroApp::CToolkitMacroApp()
{
    // TODO: �ڴ˴���ӹ�����룬
    // ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CToolkitMacroApp ����

CToolkitMacroApp theApp;

// CToolkitMacroApp ��ʼ��

BOOL CToolkitMacroApp::InitInstance()
{
    CWinApp::InitInstance();

    return TRUE;
}

typedef enum _hint
{
    Fun = 0,
    About = 1,
} HINT;
HINT hint;

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


static uiCmdAccessState AccessDefault(uiCmdAccessMode access_mode)
{
    if (CurrentMdlType() == PRO_PART)
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
    ProUIMessageDialogDisplay(PROUIMESSAGE_INFO, _T("��ʾ"), Message, buttons, PRO_UI_MESSAGE_OK, &user_choice);
    ProArrayFree((ProArray *)&buttons);
    return PRO_TK_NO_ERROR;
}

void about()
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());
    if (hint == Fun)
    {
        AfxMessageBox(_T("����������mfc�Ĵ��룡"));
        AfxMessageBox(_T("����һ�Σ�"));
        AfxMessageBox(_T("�����ڶ��Σ�"));
    }
    else
    {
        ShowDialog(_T("�����������������mfc���롣\n�����ҵĲ��ͻ�ø�����Ϣ��\nhttp://www.hudi.site"));
    }
    hint = About;
}

void runMacro()
{
    ProError status;
    CString Macro = _T("vvv ~ Select `main_dlg_cur` `PHTLeft.AssyTree` 1 `node0`;~ Activate `main_dlg_cur` `page_Render_control_btn` 1;~ Select `main_dlg_cur` `Render:ProCmdViewGallery`;~ Close `main_dlg_cur` `Render:ProCmdViewGallery`;~ Command `ProCmdViewAppearanceEditor` ;~ Activate `pgl_appearance_manager` `ColorButton` 1;~ Arm `pgl_color_editor` `SRed`;~ Update `pgl_color_editor` `SRed` 74;~ Update `pgl_color_editor` `SRed` 90;~ Update `pgl_color_editor` `SRed` 100;~ Disarm `pgl_color_editor` `SRed` 100;~ Arm `pgl_color_editor` `SGreen`;~ Update `pgl_color_editor` `SGreen` 71;~ Update `pgl_color_editor` `SGreen` 90;~ Update `pgl_color_editor` `SGreen` 100;~ Disarm `pgl_color_editor` `SGreen` 100;~ Arm `pgl_color_editor` `SBlue`;~ Update `pgl_color_editor` `SBlue` 78;~ Update `pgl_color_editor` `SBlue` 89;~ Update `pgl_color_editor` `SBlue` 100;~ Disarm `pgl_color_editor` `SBlue` 100;~ Activate `pgl_color_editor` `StdOk`;~ FocusOut `pgl_appearance_manager` `AppearanceName`;~ Activate `pgl_appearance_manager` `stdOk`;~ Command `ProCmdRegenPart` ;~ Command `ProCmdWinActivate`;");
    Macro += _T("~ Command `About_Act`;");
    wchar_t *macro = Macro.AllocSysString();
    hint = Fun;
    status = ProMacroLoad(macro);
    //Note that this function is not supported for the following situations and tasks
    //1.Activating windows or setting the current model
    //2.Erasing the current model
    //3.Completing dialog commands ending with an "OK" button press. It will cancel some dialogs after showing them.
    //4.Executing macros during a trail file replay.
    //status = ProMacroExecute();//��������϶������ƣ�����ĺ��жԻ��������������ˢ�´��ڣ��ǲ�������ִ�еġ�
    SysFreeString(macro);
}

extern "C" int user_initialize()
{
    //MFC��ʼ��
    AFX_MANAGE_STATE(AfxGetStaticModuleState());

    ProError status;
    uiCmdCmdId RunmacroId, AboutId;

    status = ProMenubarMenuAdd("Toolkitmacro", "Toolkitmacro", "About", PRO_B_TRUE, MSGFILE);
    status = ProMenubarmenuMenuAdd("Toolkitmacro", "Toolkitmacro", "OneKey", NULL, PRO_B_TRUE, MSGFILE);

    status = ProCmdActionAdd("Runmacro_Act", (uiCmdCmdActFn)runMacro, uiProeImmediate, AccessDefault, PRO_B_TRUE, PRO_B_TRUE, &RunmacroId);
    status = ProMenubarmenuPushbuttonAdd("Toolkitmacro", "Runmacro", "Runmacro", "Runmacrotips", NULL, PRO_B_TRUE, RunmacroId, MSGFILE);

    status = ProCmdActionAdd("About_Act", (uiCmdCmdActFn)about, uiProeImmediate, AccessDefault, PRO_B_TRUE, PRO_B_TRUE, &AboutId);
    status = ProMenubarmenuPushbuttonAdd("Toolkitmacro", "About", "About", "Abouttips", NULL, PRO_B_TRUE, AboutId, MSGFILE);

    hint = About;
    return PRO_TK_NO_ERROR;
}
extern "C" void user_terminate()
{
}