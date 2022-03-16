// FilterDlg.cpp: файл реализации
//

#include "stdafx.h"
#include "SnopokLR_5_2.h"
#include "FilterDlg.h"
#include "afxdialogex.h"


// диалоговое окно CFilterDlg

IMPLEMENT_DYNAMIC(CFilterDlg, CDialogEx)

CFilterDlg::CFilterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_edit_param(_T(""))
{

}

CFilterDlg::~CFilterDlg()
{
}

void CFilterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_FILTER_PARAM, m_edit_param);
}


BEGIN_MESSAGE_MAP(CFilterDlg, CDialogEx)
END_MESSAGE_MAP()


// обработчики сообщений CFilterDlg
