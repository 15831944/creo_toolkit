// ToolkitCsharp.h : ToolkitCsharp DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CToolkitCsharpApp
// �йش���ʵ�ֵ���Ϣ������� ToolkitCsharp.cpp
//

class CToolkitCsharpApp : public CWinApp
{
public:
	CToolkitCsharpApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
