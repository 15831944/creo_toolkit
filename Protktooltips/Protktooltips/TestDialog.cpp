// TestDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Protktooltips.h"
#include "TestDialog.h"
#include "afxdialogex.h"

// CTestDialog �Ի���

IMPLEMENT_DYNAMIC(CTestDialog, CDialog)

CTestDialog::CTestDialog(CWnd *pParent /*=NULL*/)
	: CDialog(CTestDialog::IDD, pParent)
{
}

CTestDialog::~CTestDialog()
{
}

void CTestDialog::DoDataExchange(CDataExchange *pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestDialog, CDialog)
END_MESSAGE_MAP()

// CTestDialog ��Ϣ�������

BOOL CTestDialog::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_ToolTipCtrl.Create(this);
	m_ToolTipCtrl.AddTool(GetDlgItem(IDC_BUTTONTEST), _T("���ǲ���TOOLTIPS�ַ���"));
	m_ToolTipCtrl.SetMaxTipWidth(300);
	m_ToolTipCtrl.Activate(TRUE);

	return TRUE;
}
