// QRCodeGen.h : QRCodeGen DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CQRCodeGenApp
// �йش���ʵ�ֵ���Ϣ������� QRCodeGen.cpp
//

class CQRCodeGenApp : public CWinApp
{
public:
	CQRCodeGenApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
