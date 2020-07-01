// MdlRename.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "MdlRename.h"

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

// CMdlRenameApp

BEGIN_MESSAGE_MAP(CMdlRenameApp, CWinApp)
END_MESSAGE_MAP()

// CMdlRenameApp ����

CMdlRenameApp::CMdlRenameApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CMdlRenameApp ����

CMdlRenameApp theApp;

// CMdlRenameApp ��ʼ��

BOOL CMdlRenameApp::InitInstance()
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

static uiCmdAccessState AccessPRT(uiCmdAccessMode access_mode)
{
	if (CurrentMdlType() == PRO_PART)
		return ACCESS_AVAILABLE;
	else
		return ACCESS_INVISIBLE;
}

void RenamePrtandDrw()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	ProError status;
	ProMdl mdl, drw;
	ProMdldata mdldata;
	ProName newName;
	CString drwname;
	ProPath currentPath;
	bool findDrw;
	status = ProMdlCurrentGet(&mdl);
	status = ProDirectoryCurrentGet(currentPath);
	status = ProMessageDisplay(MSGFILE, "Enter Prompt");
	status = ProMessageStringRead(PRO_NAME_SIZE, newName);
	if (status == PRO_TK_NO_ERROR)
	{
		status = ProMdlDataGet(mdl, &mdldata);
		drwname = CString(mdldata.device) + _T(":") + CString(mdldata.path);
		wchar_t *p = drwname.AllocSysString();
		status = ProDirectoryChange(p);
		findDrw = ProMdlLoad(mdldata.name, PRO_MDL_DRAWING, PRO_B_FALSE, &drw) == PRO_TK_NO_ERROR ? true : false;
		status = ProMdlRename(mdl, newName);
		status = ProMdlSave(mdl);
		if (findDrw)
		{
			status = ProMdlRename(drw, newName);
			status = ProMdlSave(drw);
		}
		SysFreeString(p);
		status = ProDirectoryChange(currentPath);
	}
}

extern "C" int user_initialize()
{
	ProError status;
	uiCmdCmdId MdlRenameID;

	status = ProMenubarMenuAdd("MdlRename", "MdlRename", "About", PRO_B_TRUE, MSGFILE);
	status = ProMenubarmenuMenuAdd("MdlRename", "MdlRename", "MdlRename", NULL, PRO_B_TRUE, MSGFILE);

	status = ProCmdActionAdd("MdlRename_Act", (uiCmdCmdActFn)RenamePrtandDrw, uiProeImmediate, AccessPRT, PRO_B_TRUE, PRO_B_TRUE, &MdlRenameID);
	status = ProMenubarmenuPushbuttonAdd("MdlRename", "MdlRenamemenu", "MdlRenamemenu", "MdlRenamemenutips", NULL, PRO_B_TRUE, MdlRenameID, MSGFILE);

	return PRO_TK_NO_ERROR;
}

extern "C" void user_terminate()
{
}