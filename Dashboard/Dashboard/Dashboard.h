// Dashboard.h : Dashboard DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDashboardApp
// �йش���ʵ�ֵ���Ϣ������� Dashboard.cpp
//

class CDashboardApp : public CWinApp
{
public:
	CDashboardApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
