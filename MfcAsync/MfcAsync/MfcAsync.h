
// MfcAsync.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMfcAsyncApp:
// �йش����ʵ�֣������ MfcAsync.cpp
//

class CMfcAsyncApp : public CWinApp
{
public:
	CMfcAsyncApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMfcAsyncApp theApp;