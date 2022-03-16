#pragma once
#include "afxwin.h"


// ���������� ���� FilterDlg

class FilterDlg : public CDialogEx
{
	DECLARE_DYNAMIC(FilterDlg)

public:
	FilterDlg(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~FilterDlg();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FILTER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString m_more;
	CString m_less;
	CString getMore() { return m_more; }
	CString getLess() { return m_less; }
};
