// MaterialSet.h : MaterialSet DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMaterialSetApp
// �йش���ʵ�ֵ���Ϣ������� MaterialSet.cpp
//

class CMaterialSetApp : public CWinApp
{
public:
	CMaterialSetApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
