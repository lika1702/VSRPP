#pragma once
#include "afxwin.h"
#include "afxcoll.h"
#include <vector>


// диалоговое окно CListDlg

class CListDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CListDlg)

public:
	CListDlg(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~CListDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MANAGE_LIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
//	CListBox m_source_list;
	CListBox m_result_list;
	CButton m_even;
	CButton m_odd;

	bool is_selected_even;
	bool is_selected_odd;

	afx_msg void OnStnClickedArrow();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedResetResult();
	afx_msg void OnBnClickedEvenString();
	CListBox m_source_list;
	afx_msg void OnBnClickedOddString();
	CStringArray m_selected;

	std::vector<int> transformToInt();
	std::vector<int> OnlyEven(std::vector<int> mas, bool even);
	bool check(int* mas, int size, int number);
	afx_msg void OnStnClickedResetSelection();
};
