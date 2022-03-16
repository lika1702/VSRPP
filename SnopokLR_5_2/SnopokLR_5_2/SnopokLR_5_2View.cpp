
// SnopokLR_5_2View.cpp : реализация класса CSnopokLR_5_2View
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "SnopokLR_5_2.h"
#endif

#include "SnopokLR_5_2Set.h"
#include "SnopokLR_5_2Doc.h"
#include "SnopokLR_5_2View.h"
#include "FilterDlg.h"
#include <fstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSnopokLR_5_2View

IMPLEMENT_DYNCREATE(CSnopokLR_5_2View, COleDBRecordView)

BEGIN_MESSAGE_MAP(CSnopokLR_5_2View, COleDBRecordView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &COleDBRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &COleDBRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSnopokLR_5_2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_STN_CLICKED(IDC_RECORD_DELETE, &CSnopokLR_5_2View::OnStnClickedRecordDelete)
	ON_STN_CLICKED(IDC_RECORD_ADD, &CSnopokLR_5_2View::OnStnClickedRecordAdd)
	ON_STN_CLICKED(IDC_RESET_FORM, &CSnopokLR_5_2View::OnStnClickedResetForm)
	ON_STN_CLICKED(IDC_RECORD_EDIT, &CSnopokLR_5_2View::OnStnClickedRecordEdit)
	ON_STN_CLICKED(IDC_RECORD_SUBMIT, &CSnopokLR_5_2View::OnStnClickedRecordSubmit)
	ON_BN_CLICKED(IDC_SORT_BY_INDEX, &CSnopokLR_5_2View::OnBnClickedSortByIndex)
	ON_BN_CLICKED(IDC_SORT_BY_LOGIN, &CSnopokLR_5_2View::OnBnClickedSortByLogin)
	ON_BN_CLICKED(IDC_SORT_BY_YEAR, &CSnopokLR_5_2View::OnBnClickedSortByYear)
	ON_BN_CLICKED(IDC_FILTER_BY_INDEX, &CSnopokLR_5_2View::OnBnClickedFilterByIndex)
	ON_BN_CLICKED(IDC_FILTER_BY_LOGIN, &CSnopokLR_5_2View::OnBnClickedFilterByLogin)
	ON_BN_CLICKED(IDC_FILTER_BY_YEAR, &CSnopokLR_5_2View::OnBnClickedFilterByYear)
	ON_BN_CLICKED(IDC_DISPLAY_LIST, &CSnopokLR_5_2View::OnBnClickedDisplayList)
	ON_BN_CLICKED(IDC_DISPLAY_REPORT, &CSnopokLR_5_2View::OnBnClickedDisplayReport)
	ON_STN_CLICKED(IDC_RESET_FILTER, &CSnopokLR_5_2View::OnStnClickedResetFilter)
	ON_BN_CLICKED(IDC_SORT_BY_SESSION, &CSnopokLR_5_2View::OnBnClickedSortBySession)
END_MESSAGE_MAP()

// создание/уничтожение CSnopokLR_5_2View

CSnopokLR_5_2View::CSnopokLR_5_2View() : COleDBRecordView(IDD_SNOPOKLR_5_2_FORM) { 
	m_pSet = NULL; 
	m_order_str = _T("[Код]");
	m_where_str = _T("");
}
CSnopokLR_5_2View::~CSnopokLR_5_2View() { }

void CSnopokLR_5_2View::DoDataExchange(CDataExchange* pDX) {
	COleDBRecordView::DoDataExchange(pDX);
	// можно вставить функции DDX_* , а также вызовы API SetDlgItem*/GetDlgItem* для связи базы данных с представлением
	// ex. ::SetDlgItemText(m_hWnd, IDC_MYCONTROL, m_pSet->m_MyColumn);
	// Для получения дополнительных сведений см. примеры MSDN и OLEDB
	char index[255], day[255], month[255], year[255], hour[255], minute[255], duration[255];
	_itoa_s(m_pSet->m_index, index, 10);
	::SetDlgItemText(m_hWnd, IDC_INDEX, (CString)index);
	::SetDlgItemText(m_hWnd, IDC_LOGIN, m_pSet->m_login);
	::SetDlgItemText(m_hWnd, IDC_PASSWORD, m_pSet->m_password);
	_itoa_s(m_pSet->m_day, day, 10);
	::SetDlgItemText(m_hWnd, IDC_DAY, (CString)day);
	_itoa_s(m_pSet->m_month, month, 10);
	::SetDlgItemText(m_hWnd, IDC_MONTH, (CString)month);
	_itoa_s(m_pSet->m_year, year, 10);
	::SetDlgItemText(m_hWnd, IDC_YEAR, (CString)year);
	_itoa_s(m_pSet->m_hour, hour, 10);
	::SetDlgItemText(m_hWnd, IDC_HOUR, (CString)hour);
	_itoa_s(m_pSet->m_minute, minute, 10);
	::SetDlgItemText(m_hWnd, IDC_MINUTE, (CString)minute);
	_itoa_s(m_pSet->m_duration, duration, 10);
	::SetDlgItemText(m_hWnd, IDC_SESSION_DURATION, (CString)duration);
	DDX_Control(pDX, IDC_INDEX, m_index);
	DDX_Control(pDX, IDC_LOGIN, m_login);
	DDX_Control(pDX, IDC_PASSWORD, m_password);
	DDX_Control(pDX, IDC_DAY, m_day);
	DDX_Control(pDX, IDC_MONTH, m_month);
	DDX_Control(pDX, IDC_YEAR, m_year);
	DDX_Control(pDX, IDC_HOUR, m_hour);
	DDX_Control(pDX, IDC_MINUTE, m_minute);
	DDX_Control(pDX, IDC_SESSION_DURATION, m_duration);
	DDX_Control(pDX, IDC_NEW_LOGIN, m_new_login);
	DDX_Control(pDX, IDC_NEW_LOGIN2, m_new_password);
	DDX_Control(pDX, IDC_NEW_LOGIN3, m_new_day);
	DDX_Control(pDX, IDC_NEW_LOGIN4, m_new_month);
	DDX_Control(pDX, IDC_NEW_LOGIN5, m_new_year);
	DDX_Control(pDX, IDC_NEW_LOGIN6, m_new_hour);
	DDX_Control(pDX, IDC_NEW_LOGIN7, m_new_minute);
	DDX_Control(pDX, IDC_NEW_LOGIN8, m_new_duration);
	DDX_Control(pDX, IDC_USER_LIST, m_user_list);
}

BOOL CSnopokLR_5_2View::PreCreateWindow(CREATESTRUCT& cs) {
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs
	return COleDBRecordView::PreCreateWindow(cs);
}

void CSnopokLR_5_2View::OnInitialUpdate() {
	m_pSet = &GetDocument()->m_SnopokLR_5_2Set;
	{
		CWaitCursor wait;
		HRESULT hr = m_pSet->OpenAll();
		if (FAILED(hr)) {
			// Не удается открыть набор записей.  Если recordset является хранимой процедурой, 
			//убедитесь в правильной инициализации любых входных параметров перед вызовом метода OpenAll().

			AfxMessageBox(_T("Не удалось открыть набор записей."), MB_OK);
			// Отключите команды "Следующая запись" и "Предыдущая запись",
			// поскольку попытка изменить текущую запись без открытия RowSet приведет к сбою
			m_bOnFirstRecord = TRUE;
			m_bOnLastRecord = TRUE;
		}
		if( hr == DB_S_ENDOFROWSET ) { // набор строк пуст (не содержит никаких строк)
			AfxMessageBox(_T("Набор записей открыт, но в нем нет строк для возврата."), MB_OK);
			// Отключите команды "Следующая запись" и "Предыдущая запись"
			m_bOnFirstRecord = TRUE;
			m_bOnLastRecord = TRUE;
		}
	}
	COleDBRecordView::OnInitialUpdate();
}

// печать CSnopokLR_5_2View

void CSnopokLR_5_2View::OnFilePrintPreview() {
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSnopokLR_5_2View::OnPreparePrinting(CPrintInfo* pInfo) { // подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CSnopokLR_5_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/) {
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CSnopokLR_5_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/) {
	// TODO: добавьте очистку после печати
}

void CSnopokLR_5_2View::OnRButtonUp(UINT /* nFlags */, CPoint point) {
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSnopokLR_5_2View::OnContextMenu(CWnd* /* pWnd */, CPoint point) {
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// диагностика CSnopokLR_5_2View

#ifdef _DEBUG
void CSnopokLR_5_2View::AssertValid() const { COleDBRecordView::AssertValid(); }
void CSnopokLR_5_2View::Dump(CDumpContext& dc) const { COleDBRecordView::Dump(dc); }
CSnopokLR_5_2Doc* CSnopokLR_5_2View::GetDocument() const { // встроена неотлаженная версия
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSnopokLR_5_2Doc)));
	return (CSnopokLR_5_2Doc*)m_pDocument;
}
#endif //_DEBUG


// поддержка базы данных CSnopokLR_5_2View
CRowset<>* CSnopokLR_5_2View::OnGetRowset() {
	return m_pSet->GetRowsetBase();
}



// обработчики сообщений CSnopokLR_5_2View
void CSnopokLR_5_2View::ReQuery() {
	m_pSet->ReOpen(m_where_str, m_order_str);
	OnMove(ID_RECORD_FIRST);
}

void CSnopokLR_5_2View::DoFilter(CString column) {
	CFilterDlg dlg;
	if (dlg.DoModal() == IDOK) {
		if(column == "[Логин]") m_where_str.Format(L"%s = '%s'", column, dlg.m_edit_param);
		else m_where_str.Format(L"%s = %s", column, dlg.m_edit_param);
		ReQuery();
	}
}

CString CSnopokLR_5_2View::toString() {
	CString str;

	str.Format(_T("%-20d%-40s%-50s%2d.%2d.%-50d%2d:%-50d%-d ms"),
		m_pSet->m_index, m_pSet->m_login, m_pSet->m_password, m_pSet->m_day, m_pSet->m_day, m_pSet->m_year, m_pSet->m_hour, m_pSet->m_minute, m_pSet->m_duration);
	return str;
}

void CSnopokLR_5_2View::displayMembersOfDataSourse() {
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


void CSnopokLR_5_2View::FillOleDBParameters() {
	CString str;
	
	m_new_login.GetWindowTextW(str);
	_tcscpy_s(m_pSet->m_login, str);
	m_pSet->m_dwcolumn1Length = str.GetLength();
	m_new_password.GetWindowTextW(str);
	_tcscpy_s(m_pSet->m_password, str);
	m_pSet->m_dwcolumn2Length = str.GetLength();

	m_new_day.GetWindowTextW(str);
	m_pSet->m_day = _ttoi(str);
	m_new_month.GetWindowTextW(str);
	m_pSet->m_month = _ttoi(str);
	m_new_year.GetWindowTextW(str);
	m_pSet->m_year = _ttoi(str);

	m_new_hour.GetWindowTextW(str);
	m_pSet->m_hour = _ttoi(str);
	m_new_minute.GetWindowTextW(str);
	m_pSet->m_minute = _ttoi(str);

	m_new_duration.GetWindowTextW(str);
	m_pSet->m_duration = _ttoi(str);

	m_pSet->m_dwcolumn0Status = DBSTATUS_S_OK;
	m_pSet->m_dwcolumn1Status = DBSTATUS_S_OK;
	m_pSet->m_dwcolumn2Status = DBSTATUS_S_OK;
	m_pSet->m_dwcolumn3Status = DBSTATUS_S_OK;
	m_pSet->m_dwcolumn4Status = DBSTATUS_S_OK;
	m_pSet->m_dwcolumn5Status = DBSTATUS_S_OK;
	m_pSet->m_dwcolumn6Status = DBSTATUS_S_OK;
	m_pSet->m_dwcolumn7Status = DBSTATUS_S_OK;
	m_pSet->m_dwcolumn8Status = DBSTATUS_S_OK;
}


void CSnopokLR_5_2View::OnStnClickedRecordDelete() {
	m_pSet->Delete();
	ReQuery();
}


void CSnopokLR_5_2View::OnStnClickedRecordAdd() {
	CString str;
	TCHAR login[255], password[255];
	LONG day, month, year, hour, minute, duration;

	m_new_login.GetWindowTextW(str); wcscpy_s(login, str);
	m_new_password.GetWindowTextW(str); wcscpy_s(password, str);
	m_new_day.GetWindowTextW(str); day = _ttoi(str);
	m_new_month.GetWindowTextW(str); month = _ttoi(str);
	m_new_year.GetWindowTextW(str); year = _ttoi(str);
	m_new_hour.GetWindowTextW(str); hour = _ttoi(str);
	m_new_minute.GetWindowTextW(str); minute = _ttoi(str);
	m_new_duration.GetWindowTextW(str); duration = _ttoi(str);

	m_pSet->AddRecord(login, password, day, month, year, hour, minute, duration);
	m_new_login.SetWindowTextW((CString)"");
	m_new_password.SetWindowTextW((CString)"");
	m_new_day.SetWindowTextW((CString)"");
	m_new_month.SetWindowTextW((CString)"");
	m_new_year.SetWindowTextW((CString)"");
	m_new_hour.SetWindowTextW((CString)"");
	m_new_minute.SetWindowTextW((CString)"");
	m_new_duration.SetWindowTextW((CString)"");
}


void CSnopokLR_5_2View::OnStnClickedResetForm() {
	m_new_login.SetWindowTextW((CString)"");
	m_new_password.SetWindowTextW((CString)"");
	m_new_day.SetWindowTextW((CString)"");
	m_new_month.SetWindowTextW((CString)"");
	m_new_year.SetWindowTextW((CString)"");
	m_new_hour.SetWindowTextW((CString)"");
	m_new_minute.SetWindowTextW((CString)"");
	m_new_duration.SetWindowTextW((CString)"");
}


void CSnopokLR_5_2View::OnStnClickedRecordEdit() {
	CEdit* pCtrl_1 = (CEdit*)GetDlgItem(IDC_LOGIN),
		*pCtrl_2 = (CEdit*)GetDlgItem(IDC_PASSWORD),
		*pCtrl_3 = (CEdit*)GetDlgItem(IDC_DAY),
		*pCtrl_4 = (CEdit*)GetDlgItem(IDC_MONTH),
		*pCtrl_5 = (CEdit*)GetDlgItem(IDC_YEAR),
		*pCtrl_6 = (CEdit*)GetDlgItem(IDC_HOUR),
		*pCtrl_7 = (CEdit*)GetDlgItem(IDC_MINUTE),
		*pCtrl_8 = (CEdit*)GetDlgItem(IDC_SESSION_DURATION),
		*pCtrl_mark = (CEdit*)GetDlgItem(IDC_RECORD_SUBMIT);
	pCtrl_1->SetReadOnly(FALSE);
	pCtrl_2->SetReadOnly(FALSE);
	pCtrl_3->SetReadOnly(FALSE);
	pCtrl_4->SetReadOnly(FALSE);
	pCtrl_5->SetReadOnly(FALSE);
	pCtrl_6->SetReadOnly(FALSE);
	pCtrl_7->SetReadOnly(FALSE);
	pCtrl_8->SetReadOnly(FALSE);
	pCtrl_mark->ShowWindow(SW_SHOW);
	UpdateData(FALSE);
}


void CSnopokLR_5_2View::OnStnClickedRecordSubmit() {
	CString str, index, login, password, day, month, year, hour, minute, duration;
	index.Format(_T("%d"), m_pSet->m_index);
	m_login.GetWindowTextW(login);
	m_password.GetWindowTextW(password);
	m_day.GetWindowTextW(day);
	m_month.GetWindowTextW(month);
	m_year.GetWindowTextW(year);
	m_hour.GetWindowTextW(hour);
	m_minute.GetWindowTextW(minute);
	m_duration.GetWindowTextW(duration);

	str = (CString)"UPDATE [User] SET [Логин] = '" + login + (CString)"', [Пароль] = '" + password + (CString)"', [День] = " + day + (CString)", [Месяц] = " + month + (CString)", [Год] = " + year + (CString)", [Часы] = " + hour + (CString)", [Минуты] = " + minute + (CString)", [Длительность сессии] = " + duration + (CString)" WHERE [Код] = " + index;
	m_pSet->EditRecord(str);

	CEdit* pCtrl_1 = (CEdit*)GetDlgItem(IDC_LOGIN),
		*pCtrl_2 = (CEdit*)GetDlgItem(IDC_PASSWORD),
		*pCtrl_3 = (CEdit*)GetDlgItem(IDC_DAY),
		*pCtrl_4 = (CEdit*)GetDlgItem(IDC_MONTH),
		*pCtrl_5 = (CEdit*)GetDlgItem(IDC_YEAR),
		*pCtrl_6 = (CEdit*)GetDlgItem(IDC_HOUR),
		*pCtrl_7 = (CEdit*)GetDlgItem(IDC_MINUTE),
		*pCtrl_8 = (CEdit*)GetDlgItem(IDC_SESSION_DURATION),
		*pCtrl_mark = (CEdit*)GetDlgItem(IDC_RECORD_SUBMIT);
	pCtrl_1->SetReadOnly(TRUE);
	pCtrl_2->SetReadOnly(TRUE);
	pCtrl_3->SetReadOnly(TRUE);
	pCtrl_4->SetReadOnly(TRUE);
	pCtrl_5->SetReadOnly(TRUE);
	pCtrl_6->SetReadOnly(TRUE);
	pCtrl_7->SetReadOnly(TRUE);
	pCtrl_8->SetReadOnly(TRUE);
	pCtrl_mark->ShowWindow(SW_HIDE);
	UpdateData(FALSE);
}

void CSnopokLR_5_2View::OnBnClickedSortByIndex() {
	m_order_str = L"[Код]";
	ReQuery();
}
void CSnopokLR_5_2View::OnBnClickedSortByLogin() {
	m_order_str = L"[Логин]";
	ReQuery();
}
void CSnopokLR_5_2View::OnBnClickedSortByYear() {
	m_order_str = L"[Год]";
	ReQuery();
}
void CSnopokLR_5_2View::OnBnClickedSortBySession() {
	m_order_str = L"[Длительность сессии]";
	ReQuery();
}

void CSnopokLR_5_2View::OnBnClickedFilterByIndex() { DoFilter(L"[Код]"); }
void CSnopokLR_5_2View::OnBnClickedFilterByLogin() { DoFilter(L"[Логин]"); }
void CSnopokLR_5_2View::OnBnClickedFilterByYear() { DoFilter(L"[Год]"); }

void CSnopokLR_5_2View::OnBnClickedDisplayList() {
	m_user_list.ResetContent();
	UpdateData();
	TCHAR mas[256];
	m_pSet->MoveFirst();
	do {
		_tcscpy_s(mas, toString());
		m_user_list.AddString(mas);
	} while (m_pSet->MoveNext() != DB_S_ENDOFROWSET);
	m_pSet->MoveFirst();
}


void CSnopokLR_5_2View::OnBnClickedDisplayReport() {
	std::wofstream fp;
	TCHAR mas[256];
	fp.open("Report.txt");
	fp << "\t\t\t\tОтчет\n\nСтатистика о подключениях\n\n";
	m_pSet->MoveFirst();
	do {
		_tcscpy_s(mas, toString());
		fp << mas << std::endl;
	} while (m_pSet->MoveNext() != DB_S_ENDOFROWSET);
	m_pSet->MoveFirst();
	fp.close();
	AfxMessageBox((CString)"Сгенерированнный отчет находится в файле Report.txt");
}


void CSnopokLR_5_2View::OnStnClickedResetFilter() {
	m_where_str = "";
	m_order_str = "[Код]";
	ReQuery();
}