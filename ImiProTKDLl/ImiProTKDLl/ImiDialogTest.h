#pragma once


// ImiDialogTest �Ի���

class ImiDialogTest : public CDialog
{
	DECLARE_DYNAMIC(ImiDialogTest)

public:
	ImiDialogTest(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ImiDialogTest();

// �Ի�������
	enum { IDD = IDD_IMIDIALOGTEST };
	CString text;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:

};
