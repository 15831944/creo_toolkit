// originview.h : originview DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CoriginviewApp
// �йش���ʵ�ֵ���Ϣ������� originview.cpp
//

class CoriginviewApp : public CWinApp
{
public:
	CoriginviewApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


void CalendarSet(CString Value);