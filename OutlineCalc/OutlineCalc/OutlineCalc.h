// OutlineCalc.h : OutlineCalc DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// COutlineCalcApp
// �йش���ʵ�ֵ���Ϣ������� OutlineCalc.cpp
//

class COutlineCalcApp : public CWinApp
{
public:
	COutlineCalcApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
