// ColorPaint.h : ColorPaint DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CColorPaintApp
// �йش���ʵ�ֵ���Ϣ������� ColorPaint.cpp
//

class CColorPaintApp : public CWinApp
{
public:
	CColorPaintApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
