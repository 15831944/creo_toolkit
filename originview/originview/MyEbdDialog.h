#pragma once


// CMyEbdDialog �Ի���

class CMyEbdDialog : public CDialog
{
	DECLARE_DYNAMIC(CMyEbdDialog)

public:
	CMyEbdDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMyEbdDialog();

// �Ի�������
	enum { IDD = IDD_EBDDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
	virtual void OnCancel();
public:
	afx_msg void OnMcnSelectMonthcalendar(NMHDR *pNMHDR, LRESULT *pResult);
	CMonthCalCtrl m_MonthCalCtrl;
	CEdit m_Edit;
	void SetEdit(CString Value);
};
