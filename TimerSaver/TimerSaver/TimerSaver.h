// TimerSaver.h : TimerSaver DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTimerSaverApp
// �йش���ʵ�ֵ���Ϣ������� TimerSaver.cpp
//

class CTimerSaverApp : public CWinApp
{
public:
	CTimerSaverApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
