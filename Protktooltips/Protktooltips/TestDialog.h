#pragma once

// CTestDialog �Ի���

class CTestDialog : public CDialog
{
	DECLARE_DYNAMIC(CTestDialog)

  public:
	CTestDialog(CWnd *pParent = NULL); // ��׼���캯��
	virtual ~CTestDialog();

	// �Ի�������
	enum
	{
		IDD = IDD_DIALOGTESTTOOLTIPS
	};

  protected:
	virtual void DoDataExchange(CDataExchange *pDX); // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
  public:
	virtual BOOL OnInitDialog();
	CToolTipCtrl m_ToolTipCtrl;
};
