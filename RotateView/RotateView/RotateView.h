// RotateView.h : RotateView DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CRotateViewApp
// �йش���ʵ�ֵ���Ϣ������� RotateView.cpp
//

class CRotateViewApp : public CWinApp
{
public:
	CRotateViewApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
