// AuxiliaryLine.h : AuxiliaryLine DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CAuxiliaryLineApp
// �йش���ʵ�ֵ���Ϣ������� AuxiliaryLine.cpp
//

class CAuxiliaryLineApp : public CWinApp
{
public:
	CAuxiliaryLineApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
