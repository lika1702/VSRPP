// FilterDlg.cpp: файл реализации
//

#include "stdafx.h"
#include "SnopokLR_4.h"
#include "FilterDlg.h"
#include "afxdialogex.h"


// диалоговое окно FilterDlg

IMPLEMENT_DYNAMIC(FilterDlg, CDialogEx)

FilterDlg::FilterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_FILTER, pParent)
{

}

FilterDlg::~FilterDlg()
{
}

void FilterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_MORE_THAN, m_more);
	DDX_Text(pDX, IDC_EDIT_LESS_THAN, m_less);
}


BEGIN_MESSAGE_MAP(FilterDlg, CDialogEx)
END_MESSAGE_MAP()


// обработчики сообщений FilterDlg
