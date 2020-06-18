// JpgSnapShot.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "JpgSnapShot.h"

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

// CJpgSnapShotApp

BEGIN_MESSAGE_MAP(CJpgSnapShotApp, CWinApp)
END_MESSAGE_MAP()

// CJpgSnapShotApp ����

CJpgSnapShotApp::CJpgSnapShotApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CJpgSnapShotApp ����

CJpgSnapShotApp theApp;

// CJpgSnapShotApp ��ʼ��

BOOL CJpgSnapShotApp::InitInstance()
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

static uiCmdAccessState AccessPRTORASM(uiCmdAccessMode access_mode)
{
	if (CurrentMdlType() == PRO_PART || CurrentMdlType() == PRO_ASSEMBLY)
		return ACCESS_AVAILABLE;
	else
		return ACCESS_INVISIBLE;
}

void Snapshot()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	ProError status;
	int wid;
	ProPath currentPath;
	CString filter = "ͼƬ�ļ� (*.jpg)|*.jpg";

	CFileDialog saveFileDlg(FALSE, "", "", OFN_HIDEREADONLY | OFN_READONLY, filter, NULL);
	if (saveFileDlg.DoModal() == IDOK)
	{
		status = ProDirectoryCurrentGet(currentPath);
		wchar_t *p = saveFileDlg.GetFolderPath().AllocSysString();
		status = ProDirectoryChange(p);
		SysFreeString(p);
		status = ProWindowCurrentGet(&wid);
		status = ProViewReset(NULL, NULL);
		status = ProMacroLoad(L"~ Command `ProCmdEnvDtmDisp` 0; ~ Command `ProCmdEnvAxisDisp` 0; ~ Command `ProCmdViewSpinCntr` 0; ~ Command `ProCmdEnvPntsDisp`  0;~ Command `ProCmdEnvCsysDisp`  0;");//����ʾ�߿������ϵ�������ˢ�µ���ʵҲ�����ú�������
		status = ProMacroExecute();
		status = ProWindowClear(wid);
		status = ProWindowRefresh(PRO_VALUE_UNUSED);

		p = saveFileDlg.GetFileName().AllocSysString();
		status = ProRasterFileWrite(wid, PRORASTERDEPTH_24, 10, 10, PRORASTERDPI_100, PRORASTERTYPE_JPEG, p);//�޸Ĳ�������Ӧ��Ҫ��ͼƬ��dpi�Լ��ߴ�
		SysFreeString(p);
		status = ProDirectoryChange(currentPath);
	}
}
extern "C" int user_initialize()
{
	ProError status;
	uiCmdCmdId JpgSnapShotID;

	status = ProMenubarMenuAdd("JpgSnapShot", "JpgSnapShot", "About", PRO_B_TRUE, MSGFILE);
	status = ProMenubarmenuMenuAdd("JpgSnapShot", "JpgSnapShot", "JpgSnapShot", NULL, PRO_B_TRUE, MSGFILE);

	status = ProCmdActionAdd("JpgSnapShot1_Act", (uiCmdCmdActFn)Snapshot, uiProeImmediate, AccessPRTORASM, PRO_B_TRUE, PRO_B_TRUE, &JpgSnapShotID);
	status = ProMenubarmenuPushbuttonAdd("JpgSnapShot", "JpgSnapShotmenu", "JpgSnapShotmenu", "JpgSnapShotmenutips", NULL, PRO_B_TRUE, JpgSnapShotID, MSGFILE);

	return PRO_TK_NO_ERROR;
}

extern "C" void user_terminate()
{
}