// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // �� Windows ͷ���ų�����ʹ�õ�����
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // ĳЩ CString ���캯��������ʽ��

#include <afxwin.h>         // MFC ��������ͱ�׼���
#include <afxext.h>         // MFC ��չ

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>         // MFC OLE ��
#include <afxodlgs.h>       // MFC OLE �Ի�����
#include <afxdisp.h>        // MFC �Զ�����
#endif // _AFX_NO_OLE_SUPPORT

//
//#ifndef _AFX_NO_DB_SUPPORT
//#include <afxdb.h>                      // MFC ODBC ���ݿ���
//#endif // _AFX_NO_DB_SUPPORT
//
//#ifndef _AFX_NO_DAO_SUPPORT
//#include <afxdao.h>                     // MFC DAO ���ݿ���
//#endif // _AFX_NO_DAO_SUPPORT

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC �� Internet Explorer 4 �����ؼ���֧��
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>                     // MFC �� Windows �����ؼ���֧��
#endif // _AFX_NO_AFXCMN_SUPPORT

#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace  rename("EOF", "adoEOF")
#if !defined CATCH_ERROR
#define CATCH_ERROR											\
		{													\
			CString strComError;							\
			strComError.Format("������: %08lx\n������Ϣ: %s\n����Դ: %s\n��������: %s", \
								e.Error(),                  \
								e.ErrorMessage(),           \
								(LPCSTR) e.Source(),        \
								(LPCSTR) e.Description());  \
			::MessageBox(NULL,strComError,"����",MB_ICONEXCLAMATION);	\
		}
#endif

#define MSGFILE L"CreoAccess.txt"

#include <ProUICmd.h>
#include <ProUtil.h>
#include <ProMenu.h>
#include <ProUIMessage.h>
#include <ProToolkitDll.h>
#include <ProMenubar.h>
#include <ProUtil.h>

