// ImiProTKDLl.h : ImiProTKDLl DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h" // ������

// CImiProTKDLlApp
// �йش���ʵ�ֵ���Ϣ������� ImiProTKDLl.cpp
//

class CImiProTKDLlApp : public CWinApp
{
  public:
	CImiProTKDLlApp();

	// ��д
  public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
