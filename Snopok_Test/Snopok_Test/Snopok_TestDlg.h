
// Snopok_TestDlg.h : ���� ���������
//

#pragma once
#include "adodc1.h"
#include "afxwin.h"
#include "datagrid_table.h"


// ���������� ���� CSnopok_TestDlg
class CSnopok_TestDlg : public CDialogEx
{
// ��������
public:
	CSnopok_TestDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SNOPOK_TEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	CBrush* m_pEditBkBrush;
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CAdodc1 m_adodc;
	CButton m_app_filter;
	CButton m_sort_obr;
	CComboBox m_sort_value;
	CComboBox m_filter_spis;
	CDatagrid_table m_grid;
	CEdit m_filter_value;
	afx_msg void OnCbnSelchangeSortBy();
	afx_msg void OnBnClickedAppFilter();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
