
// SnopokLR_4View.cpp : реализация класса CSnopokLR_4View
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "SnopokLR_4.h"
#endif

#include "SnopokLR_4Set.h"
#include "SnopokLR_4Doc.h"
#include "SnopokLR_4View.h"
#include <fstream>
#include <string>
#include "FilterDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSnopokLR_4View

IMPLEMENT_DYNCREATE(CSnopokLR_4View, CRecordView)

BEGIN_MESSAGE_MAP(CSnopokLR_4View, CRecordView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSnopokLR_4View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_ADD_BUTTON, &CSnopokLR_4View::OnBnClickedAddButton)
	ON_STN_CLICKED(IDC_DELETE_BUTTON, &CSnopokLR_4View::OnStnClickedDeleteButton)
	ON_BN_CLICKED(IDC_BUTTON_FILTER, &CSnopokLR_4View::OnBnClickedButtonFilter)
	ON_BN_CLICKED(IDC_BUTTON_FILTER_RESET, &CSnopokLR_4View::OnBnClickedButtonFilterReset)
	ON_STN_CLICKED(IDC_RECORD_EDIT, &CSnopokLR_4View::OnStnClickedRecordEdit)
	ON_STN_CLICKED(IDC_SUBMIT_EDIT, &CSnopokLR_4View::OnStnClickedSubmitEdit)
	ON_STN_CLICKED(IDC_GENERATE_REPORT, &CSnopokLR_4View::OnStnClickedGenerateReport)
	ON_BN_CLICKED(IDC_FILTER_DURATION, &CSnopokLR_4View::OnBnClickedFilterDuration)
END_MESSAGE_MAP()

// создание/уничтожение CSnopokLR_4View

CSnopokLR_4View::CSnopokLR_4View()
	: CRecordView(IDD_SNOPOKLR_4_FORM)
	, m_index(0)
	, m_login(_T(""))
	, m_password(_T(""))
	, m_day(0)
	, m_month(0)
	, m_year(0)
	, m_hour(0)
	, m_minute(0)
	, m_duration(0)
{
	m_pSet = NULL;
	// TODO: добавьте код создания
}

CSnopokLR_4View::~CSnopokLR_4View()
{
}

void CSnopokLR_4View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// место для вставки функций DDX_Field* для подключения элементов управления к полям базы данных, например
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// Для получения дополнительных сведений см. примеры MSDN и ODBC
	DDX_FieldText(pDX, IDC_INDEX, m_pSet->m_index, m_pSet);
	DDX_FieldText(pDX, IDC_LOGIN, m_pSet->m_login, m_pSet);
	DDX_FieldText(pDX, IDC_PASSWORD, m_pSet->m_password, m_pSet);
	DDX_FieldText(pDX, IDC_DATE_DAY, m_pSet->m_day, m_pSet);
	DDX_FieldText(pDX, IDC_DATE_MONTH, m_pSet->m_month, m_pSet);
	DDX_FieldText(pDX, IDC_DATE_YEAR, m_pSet->m_year, m_pSet);
	DDX_FieldText(pDX, IDC_TIME_HOUR, m_pSet->m_hour, m_pSet);
	DDX_FieldText(pDX, IDC_TIME_MINUTE, m_pSet->m_minute, m_pSet);
	DDX_FieldText(pDX, IDC_SESSION_DURATION, m_pSet->m_duration, m_pSet);
	DDX_Control(pDX, IDC_NEW_LOGIN, m_n_login);
	DDX_Control(pDX, IDC_NEW_PASSWORD, m_n_password);
	DDX_Control(pDX, IDC_NEW_DATE_DAY, m_n_day);
	DDX_Control(pDX, IDC_NEW_DATE_MONTH, m_n_month);
	DDX_Control(pDX, IDC_NEW_DATE_YEAR, m_n_year);
	DDX_Control(pDX, IDC_NEW_TIME_HOUR, m_n_hour);
	DDX_Control(pDX, IDC_NEW_TIME_MINUTE, m_n_minute);
	DDX_Control(pDX, IDC_NEW_SESSION_DURATION, m_n_duration);
	DDX_Control(pDX, IDC_LIST_DATA, m_list);
	DDX_Control(pDX, IDC_RADIO2, m_radio);
	DDX_Control(pDX, IDC_CHECK_2, m_check_log);
	DDX_Control(pDX, IDC_CHECK_3, m_check_year);
	DDX_Control(pDX, IDC_CHECK_4, m_check_duration);
}

BOOL CSnopokLR_4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CSnopokLR_4View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_SnopokLR_4Set;
	CRecordView::OnInitialUpdate();

}


// печать CSnopokLR_4View


void CSnopokLR_4View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSnopokLR_4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CSnopokLR_4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CSnopokLR_4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}

void CSnopokLR_4View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSnopokLR_4View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// диагностика CSnopokLR_4View

#ifdef _DEBUG
void CSnopokLR_4View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CSnopokLR_4View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CSnopokLR_4Doc* CSnopokLR_4View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSnopokLR_4Doc)));
	return (CSnopokLR_4Doc*)m_pDocument;
}
#endif //_DEBUG


// поддержка базы данных CSnopokLR_4View
CRecordset* CSnopokLR_4View::OnGetRecordset()
{
	return m_pSet;
}



// обработчики сообщений CSnopokLR_4View


void CSnopokLR_4View::OnBnClickedAddButton() {
	UpdateData();
	CString login, password, day, month, year, hour, min, duration;
	m_n_login.GetWindowTextW(login); m_n_login.SetWindowTextW((CString)"");
	m_n_password.GetWindowTextW(password); m_n_password.SetWindowTextW((CString)"");
	m_n_day.GetWindowTextW(day); m_n_day.SetWindowTextW((CString)"");
	m_n_month.GetWindowTextW(month); m_n_month.SetWindowTextW((CString)"");
	m_n_year.GetWindowTextW(year); m_n_year.SetWindowTextW((CString)"");
	m_n_hour.GetWindowTextW(hour); m_n_hour.SetWindowTextW((CString)"");
	m_n_minute.GetWindowTextW(min); m_n_minute.SetWindowTextW((CString)"");
	m_n_duration.GetWindowTextW(duration); m_n_duration.SetWindowTextW((CString)"");
	m_pSet->m_pDatabase->ExecuteSQL(
		(CString)("insert into [User] ([Логин], [Пароль], [День], [Месяц], [Год], [Часы], [Минуты], [Длительность сессии]) Values ('")
		+ login + "','" + password + "','" + day + "','" + month + "','" + year + "','" + hour + "','" + min + "','" + duration + "');");
	UpdateData();
	m_pSet->Requery();
	m_pSet->MoveFirst();
	UpdateData(FALSE);
}


void CSnopokLR_4View::OnStnClickedDeleteButton() {
	m_pSet->Delete();
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	if (m_pSet->IsBOF())
		m_pSet->SetFieldNull(NULL);
	UpdateData(FALSE);
}


void CSnopokLR_4View::OnBnClickedButtonFilter() {
	m_list.ResetContent();
	CString sorting = (CString)"";
	if (m_radio.GetCheck()) sorting = " DESC";
	m_pSet->Close();
	if (m_check_log.GetCheck() && m_check_year && m_check_duration)
		m_pSet->m_strSort = (CString)"[Логин]" + sorting + (CString)", [Год]" + sorting + (CString)", [Длительность сессии]" + sorting;
	if (m_check_log.GetCheck() && m_check_year && !m_check_duration) 
		m_pSet->m_strSort = (CString)"[Логин]" + sorting +(CString)", [Год]" + sorting;
	if (m_check_log.GetCheck() && !m_check_year && m_check_duration) 
		m_pSet->m_strSort = (CString)"[Логин]" + sorting + (CString)", [Длительность сессии]" + sorting;
	if (!m_check_log.GetCheck() && m_check_year && m_check_duration) 
		m_pSet->m_strSort = (CString)"[Год]" + sorting + (CString)", [Длительность сессии]" + sorting;
	if (m_check_log.GetCheck() && !m_check_year && !m_check_duration)
		m_pSet->m_strSort = (CString)"[Логин]" + sorting;
	if (!m_check_log.GetCheck() && m_check_year && !m_check_duration)
		m_pSet->m_strSort = (CString)"[Год]" + sorting;
	if (!m_check_log.GetCheck() && !m_check_year && m_check_duration) 
		m_pSet->m_strSort = (CString)"[Длительность сессии]" + sorting;
	m_pSet->Open();
	
	for (int i = 0; !m_pSet->IsEOF(); i++) {
		CString str, data;
		m_pSet->GetFieldValue((short)0, data);
		str += data + (CString)"             ";
		m_pSet->GetFieldValue((short)1, data);
		str += data + (CString)"             ";
		m_pSet->GetFieldValue((short)2, data);
		str += data + (CString)"             ";
		m_pSet->GetFieldValue((short)3, data);
		str += data + (CString)".";
		m_pSet->GetFieldValue((short)4, data);
		str += data + (CString)".";
		m_pSet->GetFieldValue((short)5, data);
		str += data + (CString)"             ";
		m_pSet->GetFieldValue((short)6, data);
		str += data + (CString)":";
		m_pSet->GetFieldValue((short)7, data);
		str += data + (CString)"             ";
		m_pSet->GetFieldValue((short)8, data);
		str += data + (CString)" ms";
		m_list.AddString(str);
		m_pSet->MoveNext();
	}
	m_pSet->MoveFirst();
	UpdateData(FALSE);
}

void CSnopokLR_4View::OnBnClickedButtonFilterReset() {
	m_list.ResetContent();
	
	m_pSet->Close();
	m_pSet->m_strSort = "";
	m_pSet->m_strFilter = "";
	m_pSet->Open();
	for (int i = 0; !m_pSet->IsEOF(); i++) {
		CString str, data;
		m_pSet->GetFieldValue((short)0, data);
		str += data + (CString)"             ";
		m_pSet->GetFieldValue((short)1, data);
		str += data + (CString)"             ";
		m_pSet->GetFieldValue((short)2, data);
		str += data + (CString)"             ";
		m_pSet->GetFieldValue((short)3, data);
		str += data + (CString)".";
		m_pSet->GetFieldValue((short)4, data);
		str += data + (CString)".";
		m_pSet->GetFieldValue((short)5, data);
		str += data + (CString)"             ";
		m_pSet->GetFieldValue((short)6, data);
		str += data + (CString)":";
		m_pSet->GetFieldValue((short)7, data);
		str += data + (CString)"             ";
		m_pSet->GetFieldValue((short)8, data);
		str += data + (CString)" ms";
		m_list.AddString(str);
		m_pSet->MoveNext();
	}
	m_pSet->MoveFirst();
	m_check_log.SetCheck(FALSE);
	m_check_year.SetCheck(FALSE);
	m_check_duration.SetCheck(FALSE);
	m_radio.SetCheck(FALSE);
	UpdateData(FALSE);
}


void CSnopokLR_4View::OnStnClickedRecordEdit() {
	CEdit* pCtrl_1 = (CEdit*)GetDlgItem(IDC_LOGIN),
		*pCtrl_2 = (CEdit*)GetDlgItem(IDC_PASSWORD),
		*pCtrl_mark = (CEdit*)GetDlgItem(IDC_SUBMIT_EDIT);
	pCtrl_1->SetReadOnly(FALSE);
	pCtrl_2->SetReadOnly(FALSE);
	pCtrl_mark->ShowWindow(SW_SHOW);
	UpdateData(FALSE);
}


void CSnopokLR_4View::OnStnClickedSubmitEdit() {
	UpdateData();
	char index[255];
	_itoa_s(m_pSet->m_index, index, 10);
	m_pSet->m_pDatabase->ExecuteSQL(
		(CString)("UPDATE [User] SET [Логин] = '") + m_pSet->m_login + (CString)"' WHERE [Код] = " + index + (CString)";");
	m_pSet->m_pDatabase->ExecuteSQL(
		(CString)("UPDATE [User] SET [Пароль] = '") + m_pSet->m_password + (CString)"' where  [Код] = " + index + (CString)";");
	UpdateData();
	m_pSet->Requery();
	m_pSet->MoveFirst();

	CEdit* pCtrl_1 = (CEdit*)GetDlgItem(IDC_LOGIN),
		*pCtrl_2 = (CEdit*)GetDlgItem(IDC_PASSWORD),
		*pCtrl_mark = (CEdit*)GetDlgItem(IDC_SUBMIT_EDIT);
	pCtrl_1->SetReadOnly(TRUE);
	pCtrl_2->SetReadOnly(TRUE);
	pCtrl_mark->ShowWindow(SW_HIDE);
	UpdateData(FALSE);
}


void CSnopokLR_4View::OnStnClickedGenerateReport() {
	UpdateData();
	std::wofstream fp;
	fp.open("Report.txt");
	fp << "\t\t\t\tОтчет\n\nСтатистика о подключениях\n\n";
	m_pSet->MoveFirst();
	for (int i = 0; !m_pSet->IsEOF(); i++) {
		CString str, data;
		m_pSet->GetFieldValue((short)0, data);
		str += data + (CString)"             ";
		m_pSet->GetFieldValue((short)1, data);
		str += data + (CString)"             ";
		m_pSet->GetFieldValue((short)2, data);
		str += data + (CString)"             ";
		m_pSet->GetFieldValue((short)3, data);
		str += data + (CString)".";
		m_pSet->GetFieldValue((short)4, data);
		str += data + (CString)".";
		m_pSet->GetFieldValue((short)5, data);
		str += data + (CString)"             ";
		m_pSet->GetFieldValue((short)6, data);
		str += data + (CString)":";
		m_pSet->GetFieldValue((short)7, data);
		str += data + (CString)"             ";
		m_pSet->GetFieldValue((short)8, data);
		str += data + (CString)" ms\n";
		fp << str.GetString();
		m_pSet->MoveNext();
	}
	m_pSet->MoveFirst();
	fp.close();
	AfxMessageBox((CString)"Сгенерированнный отчет находится в файле Report.txt");
}

void CSnopokLR_4View::OnBnClickedFilterDuration() {
	FilterDlg dlg;
	dlg.DoModal();
	m_list.ResetContent();
	m_pSet->Close();
	m_pSet->m_strFilter = (CString)"[Длительность сессии] < " + dlg.getLess() + (CString)" AND [Длительность сессии] > " + dlg.getMore();
	m_pSet->Open();
		for (int i = 0; !m_pSet->IsEOF(); i++) {
		CString str, data;
		m_pSet->GetFieldValue((short)0, data);
		str += data + (CString)"             ";
		m_pSet->GetFieldValue((short)1, data);
		str += data + (CString)"             ";
		m_pSet->GetFieldValue((short)2, data);
		str += data + (CString)"             ";
		m_pSet->GetFieldValue((short)3, data);
		str += data + (CString)".";
		m_pSet->GetFieldValue((short)4, data);
		str += data + (CString)".";
		m_pSet->GetFieldValue((short)5, data);
		str += data + (CString)"             ";
		m_pSet->GetFieldValue((short)6, data);
		str += data + (CString)":";
		m_pSet->GetFieldValue((short)7, data);
		str += data + (CString)"             ";
		m_pSet->GetFieldValue((short)8, data);
		str += data + (CString)" ms";
		m_list.AddString(str);
		m_pSet->MoveNext();
	}
	m_pSet->MoveFirst();
	UpdateData(FALSE);
}
