// RotateView.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "RotateView.h"

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

// CRotateViewApp

BEGIN_MESSAGE_MAP(CRotateViewApp, CWinApp)
END_MESSAGE_MAP()

// CRotateViewApp ����

CRotateViewApp::CRotateViewApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CRotateViewApp ����

CRotateViewApp theApp;

// CRotateViewApp ��ʼ��

BOOL CRotateViewApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
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

static uiCmdAccessState AccessPRTorASM(uiCmdAccessMode access_mode)
{
	if (CurrentMdlType() == PRO_PART || CurrentMdlType() == PRO_ASSEMBLY)
		return ACCESS_AVAILABLE;
	else
		return ACCESS_INVISIBLE;
}

void _setView(ProRotate rotation_axis, double angle)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	ProError status;
	status = ProViewRotate(NULL, NULL, rotation_axis, angle);
	status = ProWindowClear(PRO_VALUE_UNUSED);
	status = ProWindowRefresh(PRO_VALUE_UNUSED);
}

void RotateX()
{
	_setView(PRO_X_ROTATION, 90);
}

void RotateY()
{
	_setView(PRO_Y_ROTATION, 90);
}

void RotateZ()
{
	_setView(PRO_Z_ROTATION, 90);
}

extern "C" int user_initialize()
{
	ProError status;
	uiCmdCmdId RotateViewXID, RotateViewYID, RotateViewZID;

	status = ProMenubarMenuAdd("RotateView", "RotateView", "About", PRO_B_TRUE, MSGFILE);

	status = ProCmdActionAdd("RotateViewX_Act", (uiCmdCmdActFn)RotateX, uiProeImmediate, AccessPRTorASM, PRO_B_TRUE, PRO_B_TRUE, &RotateViewXID);
	status = ProMenubarmenuPushbuttonAdd("RotateView", "RotateViewX", "RotateViewXmenu", "RotateViewXmenutips", NULL, PRO_B_TRUE, RotateViewXID, MSGFILE);

	status = ProCmdActionAdd("RotateViewY_Act", (uiCmdCmdActFn)RotateY, uiProeImmediate, AccessPRTorASM, PRO_B_TRUE, PRO_B_TRUE, &RotateViewYID);
	status = ProMenubarmenuPushbuttonAdd("RotateView", "RotateViewY", "RotateViewYmenu", "RotateViewYmenutips", NULL, PRO_B_TRUE, RotateViewYID, MSGFILE);

	status = ProCmdActionAdd("RotateViewZ_Act", (uiCmdCmdActFn)RotateZ, uiProeImmediate, AccessPRTorASM, PRO_B_TRUE, PRO_B_TRUE, &RotateViewZID);
	status = ProMenubarmenuPushbuttonAdd("RotateView", "RotateViewZ", "RotateViewZmenu", "RotateViewZmenutips", NULL, PRO_B_TRUE, RotateViewZID, MSGFILE);

	return PRO_TK_NO_ERROR;
}

extern "C" void user_terminate()
{
}