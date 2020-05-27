// MaterialSet.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "MaterialSet.h"

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

// CMaterialSetApp

BEGIN_MESSAGE_MAP(CMaterialSetApp, CWinApp)
END_MESSAGE_MAP()

// CMaterialSetApp ����

CMaterialSetApp::CMaterialSetApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CMaterialSetApp ����

CMaterialSetApp theApp;

// CMaterialSetApp ��ʼ��

BOOL CMaterialSetApp::InitInstance()
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

void ChangeMaterial()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	ProPath currentPath;
	ProError status;
	ProMdl mdl;
	ProMaterial material;

	CString filter = "�����ļ� (*.mtl)|*.mtl||";
	CFileDialog openFileDlg(TRUE, "", "", OFN_HIDEREADONLY | OFN_READONLY, filter, NULL);
	if (openFileDlg.DoModal() == IDOK)
	{
		status = ProDirectoryCurrentGet(currentPath);
		status = ProMdlCurrentGet(&mdl);

		wchar_t *p = openFileDlg.GetFolderPath().AllocSysString();
		status = ProDirectoryChange(p);
		SysFreeString(p);

		p = openFileDlg.GetFileTitle().AllocSysString();
		status = ProMaterialfileRead(ProMdlToSolid(mdl), p);
		status = ProWstringCopy(p, material.matl_name, PRO_VALUE_UNUSED);
		material.part = ProMdlToSolid(mdl);
		SysFreeString(p);

		status = ProMaterialCurrentSet(&material);

		status = ProDirectoryChange(currentPath);
		status = ProMacroLoad(L"~ Command `ProCmdModelSave` ;~ Activate `file_saveas` `OK`;");
	}
}

extern "C" int user_initialize()
{
	ProError status;
	uiCmdCmdId MaterialSetID;

	status = ProMenubarMenuAdd("MaterialSet", "MaterialSet", "About", PRO_B_TRUE, MSGFILE);
	status = ProMenubarmenuMenuAdd("MaterialSet", "MaterialSet", "MaterialSet", NULL, PRO_B_TRUE, MSGFILE);

	status = ProCmdActionAdd("MaterialSet1_Act", (uiCmdCmdActFn)ChangeMaterial, uiProeImmediate, AccessPRT, PRO_B_TRUE, PRO_B_TRUE, &MaterialSetID);
	status = ProMenubarmenuPushbuttonAdd("MaterialSet", "MaterialSetmenu", "MaterialSetmenu", "MaterialSetmenutips", NULL, PRO_B_TRUE, MaterialSetID, MSGFILE);

	return PRO_TK_NO_ERROR;
}

extern "C" void user_terminate()
{
}