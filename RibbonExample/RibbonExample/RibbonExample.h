// RibbonExample.h : RibbonExample DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CRibbonExampleApp
// �йش���ʵ�ֵ���Ϣ������� RibbonExample.cpp
//

class CRibbonExampleApp : public CWinApp
{
public:
	CRibbonExampleApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
