// ProTKDll.h : ProTKDll DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h" // ������

// CProTKDllApp
// �йش���ʵ�ֵ���Ϣ������� ProTKDll.cpp
//

class CProTKDllApp : public CWinApp
{
  public:
	CProTKDllApp();

	// ��д
  public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
