// JpgSnapShot.h : JpgSnapShot DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CJpgSnapShotApp
// �йش���ʵ�ֵ���Ϣ������� JpgSnapShot.cpp
//

class CJpgSnapShotApp : public CWinApp
{
public:
	CJpgSnapShotApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
