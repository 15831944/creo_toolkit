// CreoAccess.h : CreoAccess DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCreoAccessApp
// �йش���ʵ�ֵ���Ϣ������� CreoAccess.cpp
//

class CCreoAccessApp : public CWinApp
{
public:
	CCreoAccessApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
