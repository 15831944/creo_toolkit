// ToolkitMacro.h : ToolkitMacro DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CToolkitMacroApp
// �йش���ʵ�ֵ���Ϣ������� ToolkitMacro.cpp
//

class CToolkitMacroApp : public CWinApp
{
public:
	CToolkitMacroApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
