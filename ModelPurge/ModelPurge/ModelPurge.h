// ModelPurge.h : ModelPurge DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CModelPurgeApp
// �йش���ʵ�ֵ���Ϣ������� ModelPurge.cpp
//

class CModelPurgeApp : public CWinApp
{
public:
	CModelPurgeApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
