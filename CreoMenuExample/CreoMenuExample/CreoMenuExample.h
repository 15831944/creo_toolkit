// CreoMenuExample.h : CreoMenuExample DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCreoMenuExampleApp
// �йش���ʵ�ֵ���Ϣ������� CreoMenuExample.cpp
//

class CCreoMenuExampleApp : public CWinApp
{
public:
	CCreoMenuExampleApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
