
// SnopokIDZ_2View.cpp : реализация класса CSnopokIDZ_2View
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "SnopokIDZ_2.h"
#endif

#include "SnopokIDZ_2Set.h"
#include "SnopokIDZ_2Doc.h"
#include "SnopokIDZ_2View.h"
#include "FilterDlg.h"
#include "ListDlg.h"
#include <fstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSnopokIDZ_2View

IMPLEMENT_DYNCREATE(CSnopokIDZ_2View, CRecordView)

BEGIN_MESSAGE_MAP(CSnopokIDZ_2View, CRecordView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSnopokIDZ_2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_STN_CLICKED(IDC_RECORD_ADD, &CSnopokIDZ_2View::OnStnClickedRecordAdd)
	ON_STN_CLICKED(IDC_RECORD_EDIT, &CSnopokIDZ_2View::OnStnClickedRecordEdit)
	ON_STN_CLICKED(IDC_RECORD_DELETE, &CSnopokIDZ_2View::OnStnClickedRecordDelete)
	ON_STN_CLICKED(IDC_FORM_CLOSE, &CSnopokIDZ_2View::OnStnClickedFormClose)
	ON_BN_CLICKED(IDC_RECORD_SAVE, &CSnopokIDZ_2View::OnBnClickedRecordSave)
	ON_BN_CLICKED(IDC_SORT_BY_INDEX, &CSnopokIDZ_2View::OnBnClickedSortByIndex)
	ON_BN_CLICKED(IDC_SORT_BY_NAME, &CSnopokIDZ_2View::OnBnClickedSortByName)
	ON_BN_CLICKED(IDC_SORT_BY_QUANTITY, &CSnopokIDZ_2View::OnBnClickedSortByQuantity)
	ON_BN_CLICKED(IDC_SORT_BY_PRICE, &CSnopokIDZ_2View::OnBnClickedSortByPrice)
	ON_BN_CLICKED(IDC_SORT_BY_DATE, &CSnopokIDZ_2View::OnBnClickedSortByDate)
	ON_STN_CLICKED(IDC_DISPLAY_LIST, &CSnopokIDZ_2View::OnStnClickedDisplayList)
	ON_BN_CLICKED(IDC_FILTER_BY_INDEX, &CSnopokIDZ_2View::OnBnClickedFilterByIndex)
	ON_BN_CLICKED(IDC_FILTER_BY_NAME, &CSnopokIDZ_2View::OnBnClickedFilterByName)
	ON_BN_CLICKED(IDC_FILTER_BY_PRICE, &CSnopokIDZ_2View::OnBnClickedFilterByPrice)
	ON_BN_CLICKED(IDC_FILTER_BY_QUANTITY, &CSnopokIDZ_2View::OnBnClickedFilterByQuantity)
	ON_BN_CLICKED(IDC_FILTER_BY_DATE, &CSnopokIDZ_2View::OnBnClickedFilterByDate)
	ON_BN_CLICKED(IDC_REPORT, &CSnopokIDZ_2View::OnBnClickedReport)
	ON_BN_CLICKED(IDC_FILTER_RESET, &CSnopokIDZ_2View::OnBnClickedFilterReset)
	ON_COMMAND(ID_CREATE_LIST_DIALOG, &CSnopokIDZ_2View::OnCreateListDialog)
END_MESSAGE_MAP()

// создание/уничтожение CSnopokIDZ_2View

CSnopokIDZ_2View::CSnopokIDZ_2View()
	: CRecordView(IDD_SNOPOKIDZ_2_FORM)
{
	m_pSet = NULL;
	// TODO: добавьте код создания
	m_editing = false;
	m_exist_list = false;
}

CSnopokIDZ_2View::~CSnopokIDZ_2View()
{
}

void CSnopokIDZ_2View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// место для вставки функций DDX_Field* для подключения элементов управления к полям базы данных, например
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// Для получения дополнительных сведений см. примеры MSDN и ODBC
	CString str;

	DDX_FieldText(pDX, IDC_INDEX, m_pSet->m_index, m_pSet);
	DDX_FieldText(pDX, IDC_NAME, m_pSet->m_name, m_pSet);
	DDX_FieldText(pDX, IDC_QUANTITY, m_pSet->m_quantity, m_pSet);
	DDX_FieldText(pDX, IDC_PRICE, m_pSet->m_price, m_pSet);
	str = m_pSet->m_date.Format(_T("%d.%m.%Y"));
	::SetDlgItemText(m_hWnd, IDC_DATE, str);

	DDX_Control(pDX, IDC_INDEX, m_index);
	DDX_Control(pDX, IDC_NAME, m_name);
	DDX_Control(pDX, IDC_QUANTITY, m_quantity);
	DDX_Control(pDX, IDC_PRICE, m_price);
	DDX_Control(pDX, IDC_DATE, m_date);
	DDX_Control(pDX, IDC_NEW_NAME, m_new_name);
	DDX_Control(pDX, IDC_NEW_QUANTITY, m_new_quantity);
	DDX_Control(pDX, IDC_NEW_PRICE, m_new_price);
	DDX_Control(pDX, IDC_NEW_DATE, m_new_date);
	DDX_Control(pDX, IDC_DESC, m_desc);
	DDX_Control(pDX, IDC_RECORD_LIST, m_list_equipment);
}

BOOL CSnopokIDZ_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CSnopokIDZ_2View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_SnopokIDZ_2Set;
	CRecordView::OnInitialUpdate();
}


// печать CSnopokIDZ_2View


void CSnopokIDZ_2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSnopokIDZ_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CSnopokIDZ_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CSnopokIDZ_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}

void CSnopokIDZ_2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSnopokIDZ_2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// диагностика CSnopokIDZ_2View

#ifdef _DEBUG
void CSnopokIDZ_2View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CSnopokIDZ_2View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CSnopokIDZ_2Doc* CSnopokIDZ_2View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSnopokIDZ_2Doc)));
	return (CSnopokIDZ_2Doc*)m_pDocument;
}
#endif //_DEBUG


// поддержка базы данных CSnopokIDZ_2View
CRecordset* CSnopokIDZ_2View::OnGetRecordset()
{
	return m_pSet;
}



// обработчики сообщений CSnopokIDZ_2View


void CSnopokIDZ_2View::OnStnClickedRecordAdd() {
	ShowForm(SW_SHOW);
}
void CSnopokIDZ_2View::OnBnClickedRecordSave() {
	CString execute_str, name, quantity, price, date;
	m_new_name.GetWindowTextW(name);
	m_new_quantity.GetWindowTextW(quantity);
	m_new_price.GetWindowTextW(price);
	m_new_date.GetWindowTextW(date);
	execute_str.Format(_T("INSERT INTO [Equipment]([Название], [Количество], [Цена], [Дата поступления]) VALUES('%s', %s, %s, '%s')"),
		name, quantity, price, date);
	m_pSet->m_pDatabase->ExecuteSQL(execute_str);
	m_pSet->Requery();
	ClearForm();
	DisplayList();
}
void CSnopokIDZ_2View::OnStnClickedFormClose() {
	ClearForm();
	ShowForm(SW_HIDE);
}

void CSnopokIDZ_2View::OnStnClickedRecordEdit() {
	CEdit* pCtrl_save = (CEdit*)GetDlgItem(IDC_STATIC_edit);
	if (!m_editing) {
		SetRead(FALSE);
		pCtrl_save->SetWindowTextW(_T("Сохранить"));
		m_editing = true;
	}
	else {
		CString execute_str, index, name, quantity, price, date;
		m_index.GetWindowTextW(index);
		m_name.GetWindowTextW(name);
		m_quantity.GetWindowTextW(quantity);
		m_price.GetWindowTextW(price);
		m_date.GetWindowTextW(date);
		execute_str.Format(_T("UPDATE [Equipment] SET [Название] = '%s', [Количество] = %s, [Цена] = %s, [Дата поступления] = '%s' WHERE [Код] = %s"),
			name, quantity, price, date, index);
		m_pSet->m_pDatabase->ExecuteSQL(execute_str);
		m_pSet->Requery();
		SetRead(TRUE);
		pCtrl_save->SetWindowTextW(_T("Редактировать"));
		m_editing = false;
		DisplayList();
	}
}

void CSnopokIDZ_2View::OnStnClickedRecordDelete() {
	m_pSet->Delete();
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	if (m_pSet->IsBOF())
		m_pSet->SetFieldNull(NULL);
	DisplayList();
	UpdateData(FALSE);
}

void CSnopokIDZ_2View::ShowForm(int param) {
	CEdit* pCtrl_1 = (CEdit*)GetDlgItem(IDC_NEW_NAME),
		*pCtrl_1_label = (CEdit*)GetDlgItem(IDC_STATIC_name),
		*pCtrl_2 = (CEdit*)GetDlgItem(IDC_NEW_QUANTITY),
		*pCtrl_2_label = (CEdit*)GetDlgItem(IDC_STATIC_quantity),
		*pCtrl_3 = (CEdit*)GetDlgItem(IDC_NEW_PRICE),
		*pCtrl_3_label = (CEdit*)GetDlgItem(IDC_STATIC_price),
		*pCtrl_4 = (CEdit*)GetDlgItem(IDC_NEW_DATE),
		*pCtrl_4_label = (CEdit*)GetDlgItem(IDC_STATIC_date),
		*pCtrl_5 = (CEdit*)GetDlgItem(IDC_RECORD_SAVE),
		*pCtrl_6 = (CEdit*)GetDlgItem(IDC_STATIC_border),
		*pCtrl_7 = (CEdit*)GetDlgItem(IDC_FORM_CLOSE);
	pCtrl_1->ShowWindow(param); pCtrl_1_label->ShowWindow(param);
	pCtrl_2->ShowWindow(param); pCtrl_2_label->ShowWindow(param);
	pCtrl_3->ShowWindow(param); pCtrl_3_label->ShowWindow(param);
	pCtrl_4->ShowWindow(param); pCtrl_4_label->ShowWindow(param);
	pCtrl_5->ShowWindow(param); pCtrl_6->ShowWindow(param);  pCtrl_7->ShowWindow(param);
	UpdateData(FALSE);
}
void CSnopokIDZ_2View::ClearForm() {
	m_new_name.SetWindowTextW(_T(""));
	m_new_quantity.SetWindowTextW(_T(""));
	m_new_price.SetWindowTextW(_T(""));
	m_new_date.SetWindowTextW(_T(""));
	UpdateData(FALSE);
}
void CSnopokIDZ_2View::SetRead(bool param) {
	CEdit* pCtrl_1 = (CEdit*)GetDlgItem(IDC_NAME),
		*pCtrl_2 = (CEdit*)GetDlgItem(IDC_QUANTITY),
		*pCtrl_3 = (CEdit*)GetDlgItem(IDC_PRICE),
		*pCtrl_4 = (CEdit*)GetDlgItem(IDC_DATE);
	pCtrl_1->SetReadOnly(param);
	pCtrl_2->SetReadOnly(param);
	pCtrl_3->SetReadOnly(param);
	pCtrl_4->SetReadOnly(param);
	UpdateData(FALSE);
}
void CSnopokIDZ_2View::DoFilter(CString column, bool flag) {
	CFilterDlg dlg;
	CString str;
	if (dlg.DoModal() == IDOK)
		if (flag) str = column + (CString)" = " + dlg.m_filter_value;
		else str = column + (CString)" = '" + dlg.m_filter_value + (CString)"'";
	m_pSet->m_strFilter = str;
	m_pSet->Requery();
	int recCount = m_pSet->GetRecordCount();
	if (recCount == 0) {
		AfxMessageBox((CString)"No matching records.");
		m_pSet->m_strFilter = "";
		m_pSet->Requery();
	}
	m_pSet->MoveFirst();
	UpdateData(FALSE);
}
CString CSnopokIDZ_2View::toString() {
	CString str, index, quantity, price, date;
	m_pSet->GetFieldValue((short)0, index);
	m_pSet->GetFieldValue((short)2, quantity);
	m_pSet->GetFieldValue((short)3, price);
	date = m_pSet->m_date.Format(_T("%d.%m.%Y"));
	str.Format(_T("%s\t%s pcs.\t%s BYN\t%s\n"), index, quantity, price, date);
	return str;
}

void CSnopokIDZ_2View::OnBnClickedSortByIndex() {
	m_pSet->Close();
	if (m_desc.GetCheck()) m_pSet->m_strSort = "[Код] DESC";
	else m_pSet->m_strSort = "[Код]";
	m_pSet->Open();
	m_pSet->MoveFirst();
	DisplayList();
	UpdateData(FALSE);
}
void CSnopokIDZ_2View::OnBnClickedSortByName() {
	m_pSet->Close();
	if (m_desc.GetCheck()) m_pSet->m_strSort = "[Название] DESC";
	else m_pSet->m_strSort = "[Название]";
	m_pSet->Open();
	m_pSet->MoveFirst();
	DisplayList();
	UpdateData(FALSE);
}
void CSnopokIDZ_2View::OnBnClickedSortByQuantity() {
	m_pSet->Close();
	if (m_desc.GetCheck()) m_pSet->m_strSort = "[Количество] DESC";
	else m_pSet->m_strSort = "[Количество]";
	m_pSet->Open();
	m_pSet->MoveFirst();
	DisplayList();
	UpdateData(FALSE);
}
void CSnopokIDZ_2View::OnBnClickedSortByPrice() {
	m_pSet->Close();
	if (m_desc.GetCheck()) m_pSet->m_strSort = "[Цена] DESC";
	else m_pSet->m_strSort = "[Цена]";
	m_pSet->Open();
	m_pSet->MoveFirst();
	DisplayList();
	UpdateData(FALSE);
}
void CSnopokIDZ_2View::OnBnClickedSortByDate() {
	m_pSet->Close();
	if (m_desc.GetCheck()) m_pSet->m_strSort = "[Дата поступления] DESC";
	else m_pSet->m_strSort = "[Дата поступления]";
	m_pSet->Open();
	m_pSet->MoveFirst();
	DisplayList();
	UpdateData(FALSE);
}

void CSnopokIDZ_2View::DisplayList() {
	m_list_equipment.DeleteAllItems();
	if (!m_exist_list) {
		CRect rect;
		m_list_equipment.GetClientRect(rect);
		int colWidth = rect.Width() / 10;

		m_list_equipment.InsertColumn(0, _T("Код"), LVCFMT_LEFT, colWidth);
		m_list_equipment.InsertColumn(1, _T("Наименование"), LVCFMT_LEFT, colWidth * 3);
		m_list_equipment.InsertColumn(2, _T("Количество"), LVCFMT_LEFT, colWidth * 2);
		m_list_equipment.InsertColumn(3, _T("Цена"), LVCFMT_LEFT, colWidth * 2);
		m_list_equipment.InsertColumn(4, _T("Дата поступления"), LVCFMT_LEFT, rect.Width() - colWidth * 8 - 25);
		m_exist_list = true;
	}

	m_pSet->MoveFirst();
	for (int i = 0; !m_pSet->IsEOF(); i++) {
		CString index;
		m_pSet->GetFieldValue((short)0, index);
		m_list_equipment.InsertItem(i, index);
		for (short j = 1; j < 5; j++) {
			CString data;
			m_pSet->GetFieldValue(j, data);
			m_list_equipment.SetItemText(i, j, data);
		}
		m_pSet->MoveNext();
	}
	m_pSet->MoveFirst();
	UpdateData(FALSE);
}

void CSnopokIDZ_2View::OnStnClickedDisplayList() {
	DisplayList();
}

void CSnopokIDZ_2View::OnBnClickedFilterByIndex() { DoFilter((CString)"[Код]", true); DisplayList(); }
void CSnopokIDZ_2View::OnBnClickedFilterByName() { DoFilter((CString)"[Название]", false); DisplayList(); }
void CSnopokIDZ_2View::OnBnClickedFilterByPrice() { DoFilter((CString)"[Цена]", true); DisplayList(); }
void CSnopokIDZ_2View::OnBnClickedFilterByQuantity() { DoFilter((CString)"[Количество]", true); DisplayList(); }
void CSnopokIDZ_2View::OnBnClickedFilterByDate() { DoFilter((CString)"[Дата поступления]", false); DisplayList(); }

void CSnopokIDZ_2View::OnBnClickedReport() {
	UpdateData();
	std::wofstream fp;
	fp.open("Report.txt");
	fp << "\t\t\t\tОтчет\n\nО поставках оборудования\n\n";
	m_pSet->MoveFirst();
	for (int i = 0; !m_pSet->IsEOF(); m_pSet->MoveNext()) fp << toString().GetString();
	m_pSet->MoveFirst();
	fp.close();
	AfxMessageBox((CString)"Сгенерированнный отчет находится в файле Report.txt");
}


void CSnopokIDZ_2View::OnBnClickedFilterReset() {
	m_pSet->m_strFilter = "";
	m_pSet->Requery();
	DisplayList();
}


void CSnopokIDZ_2View::OnCreateListDialog() {
	CListDlg dlg;
	if (dlg.DoModal() == IDOK) { }
	else { }
}
