// RelFunctions.h : RelFunctions DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CRelFunctionsApp
// �йش���ʵ�ֵ���Ϣ������� RelFunctions.cpp
//

class CRelFunctionsApp : public CWinApp
{
public:
	CRelFunctionsApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
