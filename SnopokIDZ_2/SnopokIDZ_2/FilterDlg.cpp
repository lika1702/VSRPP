// FilterDlg.cpp: файл реализации
//

#include "stdafx.h"
#include "SnopokIDZ_2.h"
#include "FilterDlg.h"
#include "afxdialogex.h"


// диалоговое окно CFilterDlg

IMPLEMENT_DYNAMIC(CFilterDlg, CDialogEx)

CFilterDlg::CFilterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FILTER_DIALOG, pParent)
	, m_filter_value(_T(""))
{

}

CFilterDlg::~CFilterDlg()
{
}

void CFilterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_FILTER_VALUE, m_filter_value);
}


BEGIN_MESSAGE_MAP(CFilterDlg, CDialogEx)
END_MESSAGE_MAP()


// обработчики сообщений CFilterDlg
