// ImiDialogTest.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ImiProTKDLl.h"
#include "ImiDialogTest.h"
#include "afxdialogex.h"

// ImiDialogTest �Ի���

IMPLEMENT_DYNAMIC(ImiDialogTest, CDialog)

ImiDialogTest::ImiDialogTest(CWnd *pParent /*=NULL*/)
	: CDialog(ImiDialogTest::IDD, pParent)
{
}

ImiDialogTest::~ImiDialogTest()
{
}

void ImiDialogTest::DoDataExchange(CDataExchange *pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(ImiDialogTest, CDialog)

ON_BN_CLICKED(IDC_BUTTON1, &ImiDialogTest::OnBnClickedButton1)
END_MESSAGE_MAP()

// ImiDialogTest ��Ϣ�������

void ImiDialogTest::OnBnClickedButton1()
{
	AfxMessageBox(_T("����˰�ť"));
}