// OneKeyalign.h : OneKeyalign DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// COneKeyalignApp
// �йش���ʵ�ֵ���Ϣ������� OneKeyalign.cpp
//

class COneKeyalignApp : public CWinApp
{
public:
	COneKeyalignApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
