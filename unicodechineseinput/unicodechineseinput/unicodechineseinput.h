// unicodechineseinput.h : unicodechineseinput DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CunicodechineseinputApp
// �йش���ʵ�ֵ���Ϣ������� unicodechineseinput.cpp
//

class CunicodechineseinputApp : public CWinApp
{
public:
	CunicodechineseinputApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
