// Protktooltips.h : Protktooltips DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h" // ������

// CProtktooltipsApp
// �йش���ʵ�ֵ���Ϣ������� Protktooltips.cpp
//

class CProtktooltipsApp : public CWinApp
{
  public:
	CProtktooltipsApp();

	// ��д
  public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
