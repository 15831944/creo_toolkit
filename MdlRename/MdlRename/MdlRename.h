// MdlRename.h : MdlRename DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMdlRenameApp
// �йش���ʵ�ֵ���Ϣ������� MdlRename.cpp
//

class CMdlRenameApp : public CWinApp
{
public:
	CMdlRenameApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
