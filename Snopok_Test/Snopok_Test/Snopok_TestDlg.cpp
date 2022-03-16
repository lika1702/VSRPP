
// Snopok_TestDlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "Snopok_Test.h"
#include "Snopok_TestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ���������� ���� CSnopok_TestDlg



CSnopok_TestDlg::CSnopok_TestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SNOPOK_TEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pEditBkBrush = new CBrush(RGB(0, 0, 0));
}

void CSnopok_TestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ADODC1, m_adodc);
	DDX_Control(pDX, IDC_APP_FILTER, m_app_filter);
	DDX_Control(pDX, IDC_DESC_SORT, m_sort_obr);
	DDX_Control(pDX, IDC_SORT_BY, m_sort_value);
	DDX_Control(pDX, IDC_FILTER_BY, m_filter_spis);
	DDX_Control(pDX, IDC_DATAGRID_TABLE, m_grid);
	DDX_Control(pDX, IDC_FILTER_VALUE, m_filter_value);
}

BEGIN_MESSAGE_MAP(CSnopok_TestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_SORT_BY, &CSnopok_TestDlg::OnCbnSelchangeSortBy)
	ON_BN_CLICKED(IDC_APP_FILTER, &CSnopok_TestDlg::OnBnClickedAppFilter)
	//ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// ����������� ��������� CSnopok_TestDlg

BOOL CSnopok_TestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���������� ������ "� ���������..." � ��������� ����.

	// IDM_ABOUTBOX ������ ���� � �������� ��������� �������.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ������ ������ ��� ����� ����������� ����.  ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������

	m_sort_value.AddString((CString)"unsort");
	m_sort_value.AddString((CString)"���");
	m_sort_value.AddString((CString)"�����");
	m_sort_value.AddString((CString)"������");
	m_sort_value.AddString((CString)"���");
	m_sort_value.AddString((CString)"������������ ������");

	m_filter_spis.AddString((CString)"unfilter");
	m_filter_spis.AddString((CString)"���");
	m_filter_spis.AddString((CString)"�����");
	m_filter_spis.AddString((CString)"������");
	m_filter_spis.AddString((CString)"���");
	m_filter_spis.AddString((CString)"������������ ������");

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void CSnopok_TestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������.  ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CSnopok_TestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CSnopok_TestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSnopok_TestDlg::OnCbnSelchangeSortBy() {
	CString execute_str, field;
	m_sort_value.GetLBText(m_sort_value.GetCurSel(), field);
	if (field == "unsort") execute_str = "SELECT * FROM User";
	else {
		execute_str.Format(_T("SELECT * FROM User ORDER BY [%s]"), field);
		if (m_sort_obr.GetCheck())	execute_str += " DESC";
	}

	m_adodc.put_RecordSource(execute_str);
	m_adodc.Refresh();
}


void CSnopok_TestDlg::OnBnClickedAppFilter() {
	CString value, field, str3, execute_str;
	m_filter_spis.GetLBText(m_filter_spis.GetCurSel(), field);
	m_filter_value.GetWindowText(value);
	if (field != "unfilter")
		if (value != "") {
			if (field == "�����" || field == "������") //execute_str.Format(_T("SELECT * FROM User WHERE [%s] = '%s'"), field, value);
			{
				execute_str += "SELECT * FROM User WHERE [";
				execute_str += field; execute_str += "] LIKE '%"; execute_str += value; execute_str += "%'";
			}
			else execute_str.Format(_T("SELECT * FROM User WHERE [%s] = %s"), field, value);
		}
		else execute_str = _T("SELECT * FROM User");
	else {
		execute_str = _T("SELECT * FROM User");
		m_filter_value.SetWindowTextW(_T(""));
	}

	m_adodc.put_RecordSource(execute_str);
	m_adodc.Refresh();
}

HBRUSH CSnopok_TestDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) {
	
	switch (nCtlColor) {
		case CTLCOLOR_DLG :{
			CBrush* new_brush = new CBrush(RGB(201, 240, 235));
			m_pEditBkBrush = new_brush;
			return (HBRUSH)(m_pEditBkBrush->GetSafeHandle());
		}
		case CTLCOLOR_STATIC: {
			CBrush* new_brush = new CBrush(RGB(201, 240, 235));
			m_pEditBkBrush = new_brush;
			return (HBRUSH)(m_pEditBkBrush->GetSafeHandle());
		}
	}		
	
	return (HBRUSH)CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
