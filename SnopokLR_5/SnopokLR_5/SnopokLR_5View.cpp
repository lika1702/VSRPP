
// SnopokLR_5View.cpp : ���������� ������ CSnopokLR_5View
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "SnopokLR_5.h"
#endif

#include "SnopokLR_5Set.h"
#include "SnopokLR_5Doc.h"
#include "SnopokLR_5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSnopokLR_5View

IMPLEMENT_DYNCREATE(CSnopokLR_5View, COleDBRecordView)

BEGIN_MESSAGE_MAP(CSnopokLR_5View, COleDBRecordView)
	// ����������� ������� ������
	ON_COMMAND(ID_FILE_PRINT, &COleDBRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &COleDBRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSnopokLR_5View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_RECORD_FIRST, &CSnopokLR_5View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_LAST, &CSnopokLR_5View::OnRecordLast)
	ON_COMMAND(ID_RECORD_NEXT, &CSnopokLR_5View::OnRecordNext)
	ON_COMMAND(ID_RECORD_PREV, &CSnopokLR_5View::OnRecordPrev)
	ON_UPDATE_COMMAND_UI(ID_RECORD_FIRST, &CSnopokLR_5View::OnUpdateRecordFirst)
	ON_UPDATE_COMMAND_UI(ID_RECORD_PREV, &CSnopokLR_5View::OnUpdateRecordPrev)
	ON_BN_CLICKED(IDC_INSERT, &CSnopokLR_5View::OnBnClickedInsert)
	ON_BN_CLICKED(IDC_EDIT, &CSnopokLR_5View::OnBnClickedEdit)
	ON_BN_CLICKED(IDC_DELETE, &CSnopokLR_5View::OnBnClickedDelete)
END_MESSAGE_MAP()

// ��������/����������� CSnopokLR_5View

CSnopokLR_5View::CSnopokLR_5View()
	: COleDBRecordView(IDD_SNOPOKLR_5_FORM)
{
	m_pSet = NULL;
	// TODO: �������� ��� ��������
	m_bAdding = false;
}

CSnopokLR_5View::~CSnopokLR_5View()
{
}

void CSnopokLR_5View::DoDataExchange(CDataExchange* pDX)
{
	COleDBRecordView::DoDataExchange(pDX);
	// ����� �������� ������� DDX_* , � ����� ������ API SetDlgItem*/GetDlgItem* ��� ����� ���� ������ � ��������������
	// ex. ::SetDlgItemText(m_hWnd, IDC_MYCONTROL, m_pSet->m_MyColumn);
	// ��� ��������� �������������� �������� ��. ������� MSDN � OLEDB
	DDX_Control(pDX, IDC_INDEX, m_index);
	DDX_Control(pDX, IDC_LOGIN, m_login);
	DDX_Control(pDX, IDC_PASSWORD, m_password);
	DDX_Control(pDX, IDC_DAY, m_day);
	DDX_Control(pDX, IDC_MONTH, m_month);
	DDX_Control(pDX, IDC_YEAR, m_year);
	DDX_Control(pDX, IDC_HOUR, m_hour);
	DDX_Control(pDX, IDC_MINUTE, m_minute);
	DDX_Control(pDX, IDC_SESSION_DURATION, m_duration);
}

BOOL CSnopokLR_5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return COleDBRecordView::PreCreateWindow(cs);
}

void CSnopokLR_5View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_SnopokLR_5Set;
	{
		CWaitCursor wait;
		HRESULT hr = m_pSet->OpenAll();
		if (FAILED(hr))
		{
			// �� ������� ������� ����� �������.  ���� recordset �������� 
			// �������� ����������, ��������� � ����������
			// ������������� ����� ������� ���������� ����� �������
			// ������ OpenAll().

			AfxMessageBox(_T("�� ������� ������� ����� �������."), MB_OK);
			// ��������� ������� "��������� ������" � "���������� ������",
			// ��������� ������� �������� ������� ������ ���
			// �������� RowSet �������� � ����
			m_bOnFirstRecord = TRUE;
			m_bOnLastRecord = TRUE;
		}
		if( hr == DB_S_ENDOFROWSET )
		{
			// ����� ����� ���� (�� �������� ������� �����)
			AfxMessageBox(_T("����� ������� ������, �� � ��� ��� ����� ��� ��������."), MB_OK);
			// ��������� ������� "��������� ������" � "���������� ������"
			m_bOnFirstRecord = TRUE;
			m_bOnLastRecord = TRUE;
		}
	}
	COleDBRecordView::OnInitialUpdate();

}


// ������ CSnopokLR_5View


void CSnopokLR_5View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSnopokLR_5View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ���������� �� ���������
	return DoPreparePrinting(pInfo);
}

void CSnopokLR_5View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� �������������� ������������� ����� �������
}

void CSnopokLR_5View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� ������� ����� ������
}

void CSnopokLR_5View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSnopokLR_5View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// ����������� CSnopokLR_5View

#ifdef _DEBUG
void CSnopokLR_5View::AssertValid() const
{
	COleDBRecordView::AssertValid();
}

void CSnopokLR_5View::Dump(CDumpContext& dc) const
{
	COleDBRecordView::Dump(dc);
}

CSnopokLR_5Doc* CSnopokLR_5View::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSnopokLR_5Doc)));
	return (CSnopokLR_5Doc*)m_pDocument;
}
#endif //_DEBUG


// ��������� ���� ������ CSnopokLR_5View
CRowset<>* CSnopokLR_5View::OnGetRowset()
{
	return m_pSet->GetRowsetBase();
}



// ����������� ��������� CSnopokLR_5View
void CSnopokLR_5View::displayMembersOfDataSourse() {
	CString str;
	str.Format(_T("%d"), m_pSet->m_index);
	m_index.SetWindowText(str);

	str = m_pSet->m_login;
	m_login.SetWindowText(str);

	str = m_pSet->m_password;
	m_password.SetWindowText(str);

	str.Format(_T("%d"), m_pSet->m_day);
	m_day.SetWindowText(str);

	str.Format(_T("%d"), m_pSet->m_month);
	m_month.SetWindowText(str);

	str.Format(_T("%d"), m_pSet->m_year);
	m_year.SetWindowText(str);

	str.Format(_T("%d"), m_pSet->m_hour);
	m_hour.SetWindowText(str);

	str.Format(_T("%d"), m_pSet->m_minute);
	m_minute.SetWindowText(str);

	str.Format(_T("%d"), m_pSet->m_duration);
	m_duration.SetWindowText(str);
}

void CSnopokLR_5View::FillOleDBParameters()
{
	int i;
	CString str;
	m_index.GetWindowTextW(str);
	m_pSet->m_index = _ttoi(str);

	m_login.GetWindowTextW(str);
	wcscpy_s(m_pSet->m_login, str.GetBuffer(40));
	
	m_password.GetWindowTextW(str);
	wcscpy_s(m_pSet->m_password, str.GetBuffer(40));

	m_day.GetWindowTextW(str);
	m_pSet->m_day = _ttoi(str);

	m_month.GetWindowTextW(str);
	m_pSet->m_month = _ttoi(str);

	m_year.GetWindowTextW(str);
	m_pSet->m_year = _ttoi(str);

	m_hour.GetWindowTextW(str);
	m_pSet->m_hour = _ttoi(str);

	m_minute.GetWindowTextW(str);
	m_pSet->m_minute = _ttoi(str);

	m_duration.GetWindowTextW(str);
	m_pSet->m_duration = _ttoi(str);
}

void CSnopokLR_5View::OnRecordFirst() {
	m_pSet->MoveFirst(); // ������� �� ������ �������
	displayMembersOfDataSourse();

}


void CSnopokLR_5View::OnRecordLast() {
	m_pSet->MoveLast();
	displayMembersOfDataSourse();
}


void CSnopokLR_5View::OnRecordNext() {
	m_pSet->MoveNext();
	displayMembersOfDataSourse();
	CString str;
	m_index.GetWindowText(str);
	if (str == "") OnRecordLast();
}


void CSnopokLR_5View::OnRecordPrev() {
	CString str;
	m_pSet->MovePrev();
	displayMembersOfDataSourse();
	m_index.GetWindowText(str);
	if (str == "") OnRecordFirst();
}


void CSnopokLR_5View::OnUpdateRecordFirst(CCmdUI *pCmdUI)
{
	// TODO: �������� ���� ��� ����������� �� ���������� ������
}


void CSnopokLR_5View::OnUpdateRecordPrev(CCmdUI *pCmdUI)
{
	// TODO: �������� ���� ��� ����������� �� ���������� ������
}


void CSnopokLR_5View::OnBnClickedInsert() {
	if (!m_bAdding)
	{
		m_bAdding = true;
		SetDlgItemText(IDC_INSERT, _T("���������"));
		GetDlgItem(IDC_INDEX)->EnableWindow(SW_SHOW);
		SetDlgItemText(IDC_LOGIN, NULL);
		SetDlgItemText(IDC_PASSWORD, NULL);
		SetDlgItemText(IDC_DAY, NULL);
		SetDlgItemText(IDC_MONTH, NULL);
		SetDlgItemText(IDC_YEAR, NULL);
		SetDlgItemText(IDC_HOUR, NULL);
		SetDlgItemText(IDC_MINUTE, NULL);
		SetDlgItemText(IDC_SESSION_DURATION, NULL);
		GetDlgItem(IDC_INDEX)->SetFocus();
	}
	else
	{
		m_pSet->MoveLast();
		FillOleDBParameters();
		HRESULT result;
		CString login, password, day, month, year, hour, minute, duration;
		m_login.GetWindowTextW(login);
		m_password.GetWindowTextW(password);
		m_day.GetWindowTextW(day);
		m_month.GetWindowTextW(month);
		m_year.GetWindowTextW(year);
		m_hour.GetWindowTextW(hour);
		m_minute.GetWindowTextW(minute);
		m_duration.GetWindowTextW(duration);
		result = m_pSet->AddRow(login, password, day, month, year, hour, minute, duration);
		SetDlgItemText(IDC_INSERT, _T("��������"));
		GetDlgItem(IDC_INDEX)->EnableWindow(SW_HIDE);
		m_bAdding = false;
	}

}


void CSnopokLR_5View::OnBnClickedEdit() {
	FillOleDBParameters();
	m_pSet->SetData(); // ��������� �������� ����� ��������� ������
					   // �������� ��������� ������ ���������� �� ����������, 
					   // ����������� ��� �������.
	m_pSet->Update();

}


void CSnopokLR_5View::OnBnClickedDelete() {
	m_pSet->Delete();
}
