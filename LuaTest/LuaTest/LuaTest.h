// LuaTest.h : LuaTest DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CLuaTestApp
// �йش���ʵ�ֵ���Ϣ������� LuaTest.cpp
//

class CLuaTestApp : public CWinApp
{
public:
	CLuaTestApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
