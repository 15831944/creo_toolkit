// FrmReplacer.h : FrmReplacer DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������

class CFrmReplacerApp : public CWinApp
{
public:
	CFrmReplacerApp();
public:
	virtual BOOL InitInstance();
	DECLARE_MESSAGE_MAP()
};

void GetFrmlist(CString Path, CArray<CString, CString &> *lst);
void ReplaceFrm(CString Drw,int SheetNum,CString Frm,bool DelTab);


typedef struct CCurrentSheet
{
    CString Drw;
    CString Format;
	int SheetNum;
}CURRENTSHT;