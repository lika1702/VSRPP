#pragma once
#include "afxwin.h"


// диалоговое окно FilterDlg

class FilterDlg : public CDialogEx
{
	DECLARE_DYNAMIC(FilterDlg)

public:
	FilterDlg(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~FilterDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FILTER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString m_more;
	CString m_less;
	CString getMore() { return m_more; }
	CString getLess() { return m_less; }
};
