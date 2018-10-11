// RelFunctions.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "RelFunctions.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#
#pragma region MFC
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

// CRelFunctionsApp

BEGIN_MESSAGE_MAP(CRelFunctionsApp, CWinApp)
END_MESSAGE_MAP()

// CRelFunctionsApp ����

CRelFunctionsApp::CRelFunctionsApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CRelFunctionsApp ����

CRelFunctionsApp theApp;

// CRelFunctionsApp ��ʼ��

BOOL CRelFunctionsApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
#pragma endregion
ProRelfuncArg* Args_StrToDouble = NULL;
ProRelfuncArg* Args_DoubleToStr = NULL;
ProError StrToDouble (ProRelset* relset, ProMdl mdl,char* ext_func_name,ProParamvalue* args,ProAppData data, ProParamvalue* result)
{
	CString str = CString(args [0].value.s_val);
	result->type = PRO_PARAM_DOUBLE;
	result->value.d_val = atof(str);
	return (PRO_TK_NO_ERROR);
}
ProError DoubleToStr (ProRelset* relset, ProMdl mdl,char* ext_func_name,ProParamvalue* args,ProAppData data, ProParamvalue* result)
{
	CString str;
	int i;
	str.Format("%g",args [0].value.d_val);
	wchar_t *p = str.AllocSysString();
	result->type = PRO_PARAM_STRING;
	for(i = 0; i<PRO_LINE_SIZE; i++)
	{
		if(i == str.GetLength())
			break;
		result->value.s_val[i] = p[i];
	}
	if(i < PRO_LINE_SIZE)
		result->value.s_val[i] = '\0';
	SysFreeString(p);
	p = NULL;
	return (PRO_TK_NO_ERROR);
}
extern "C" int user_initialize()
{
	ProError status;
	status = ProArrayAlloc (1, sizeof (ProRelfuncArg), 1, (ProArray*)&Args_StrToDouble);
	Args_StrToDouble [0].type = PRO_PARAM_STRING;
	Args_StrToDouble [0].attributes = PRO_RELF_ATTR_NONE;

	status = ProArrayAlloc (1, sizeof (ProRelfuncArg), 1, (ProArray*)&Args_DoubleToStr);
	Args_DoubleToStr [0].type = PRO_PARAM_DOUBLE;
	Args_DoubleToStr [0].attributes = PRO_RELF_ATTR_NONE;

	status = ProRelationFunctionRegister ("IMI_StrToDouble", Args_StrToDouble,  StrToDouble, NULL, NULL,PRO_B_FALSE, NULL);
	status = ProRelationFunctionRegister ("IMI_DoubleToStr", Args_DoubleToStr,  DoubleToStr, NULL, NULL,PRO_B_FALSE, NULL);

	return PRO_TK_NO_ERROR;
}
extern "C" void user_terminate()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	ProError status;
	status = ProArrayFree((ProArray*)&Args_StrToDouble);
	Args_StrToDouble = NULL;
	status = ProArrayFree((ProArray*)&Args_DoubleToStr);
	Args_DoubleToStr = NULL;
}
