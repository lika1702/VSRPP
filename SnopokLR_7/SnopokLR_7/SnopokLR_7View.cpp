
// SnopokLR_7View.cpp : реализация класса CSnopokLR_7View
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "SnopokLR_7.h"
#endif

#include "SnopokLR_7Doc.h"
#include "SnopokLR_7View.h"
#include "afxmt.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

volatile bool runningRed;
volatile bool runningBlue;
volatile bool runningGreen;
volatile bool runningPurple;
CEvent threadStartRed;
CEvent threadStartBlue;
CEvent threadStartGreen;
CEvent threadStartPurple;

int r = 0, g = 0, b = 0, p = 0;

// CSnopokLR_7View

IMPLEMENT_DYNCREATE(CSnopokLR_7View, CView)

BEGIN_MESSAGE_MAP(CSnopokLR_7View, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSnopokLR_7View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_CREATE_THREAD, &CSnopokLR_7View::OnCreateThread)
	ON_COMMAND(ID_START_RED, &CSnopokLR_7View::OnStartRed)
	ON_COMMAND(ID_START_GREEN, &CSnopokLR_7View::OnStartGreen)
	ON_COMMAND(ID_START_BLUE, &CSnopokLR_7View::OnStartBlue)
	ON_COMMAND(ID_START_PURPLE, &CSnopokLR_7View::OnStartPurple)
	ON_COMMAND(ID_START_RED_BLUE, &CSnopokLR_7View::OnStartRedBlue)
	ON_COMMAND(ID_START_RED_BLUE_GREEN, &CSnopokLR_7View::OnStartRedBlueGreen)
	ON_COMMAND(ID_START_RED_BLUE_GREEN_PURPLE, &CSnopokLR_7View::OnStartRedBlueGreenPurple)
	ON_COMMAND(ID_STOP_RED, &CSnopokLR_7View::OnStopRed)
	ON_COMMAND(ID_STOP_GREEN, &CSnopokLR_7View::OnStopGreen)
	ON_COMMAND(ID_STOP_BLUE, &CSnopokLR_7View::OnStopBlue)
	ON_COMMAND(ID_STOP_PURPLE, &CSnopokLR_7View::OnStopPurple)
	ON_COMMAND(ID_STOP_ALL, &CSnopokLR_7View::OnStopAll)
END_MESSAGE_MAP()

// создание/уничтожение CSnopokLR_7View

CSnopokLR_7View::CSnopokLR_7View()
{
	// TODO: добавьте код создания

}

CSnopokLR_7View::~CSnopokLR_7View()
{
}

BOOL CSnopokLR_7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование CSnopokLR_7View

void CSnopokLR_7View::OnDraw(CDC* pDC)
{
	CSnopokLR_7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
	CRect rect;
	GetWindowRect(&rect);
	CBrush bgColor(RGB(217, 217, 217));
	pDC->SelectObject(&bgColor);
	pDC->Rectangle(0, 0, rect.Width(), rect.Height());

	CBrush redColor(HS_BDIAGONAL, RGB(255, 61, 61));
	pDC->SelectObject(&redColor);
	pDC->Rectangle(0, 0, rect.Width() / 2, rect.Height() / 2);

	CBrush blueColor(HS_FDIAGONAL, RGB(61, 174, 255));
	pDC->SelectObject(&blueColor);
	pDC->Rectangle(rect.Width() / 2 +3, 0, rect.Width() - 3, rect.Height() / 2);

	CBrush greenColor(HS_FDIAGONAL, RGB(61, 255, 139));
	pDC->SelectObject(&greenColor);
	pDC->Rectangle(0, rect.Height()/2 + 3, rect.Width() / 2, rect.Height() - 3);

	CBrush purpleColor(HS_BDIAGONAL, RGB(239, 61, 255));
	pDC->SelectObject(&purpleColor);
	pDC->Rectangle(rect.Width() / 2 + 3, rect.Height() / 2 + 3, rect.Width() - 3, rect.Height() - 3);
}


// печать CSnopokLR_7View


void CSnopokLR_7View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSnopokLR_7View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CSnopokLR_7View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CSnopokLR_7View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}

void CSnopokLR_7View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSnopokLR_7View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// диагностика CSnopokLR_7View

#ifdef _DEBUG
void CSnopokLR_7View::AssertValid() const
{
	CView::AssertValid();
}

void CSnopokLR_7View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSnopokLR_7Doc* CSnopokLR_7View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSnopokLR_7Doc)));
	return (CSnopokLR_7Doc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CSnopokLR_7View
UINT ThreadRed(LPVOID pParam); // объявление функции потока 1
UINT ThreadBlue(LPVOID pParam); // объявление функции потока 2
UINT ThreadGreen(LPVOID pParam);
UINT ThreadPurple(LPVOID pParam);

UINT ThreadRed(LPVOID pParam) {
	CSingleLock syncObjStart(&threadStartRed);
	syncObjStart.Lock();
	CSnopokLR_7View *ptrView = (CSnopokLR_7View *)pParam;
	for (int i = r; i < 30000; i++) {
		CDC *dc = ptrView->GetDC();
		Sleep(500);
		CRect rect;
		ptrView->GetClientRect(&rect);
		int halfWidth = rect.Width() / 2;
		int halfHeight = rect.Height() / 2;
		dc->SetTextColor(RGB(204, 24, 24));
		dc->TextOut(rand() % (halfWidth + i) - i, rand() % (halfHeight + i) - i, CString("Red"), 3);

		if (runningRed == FALSE) {
			AfxMessageBox(CString("Красный остановлен"));
			r = i;
			break;
		}
	}

	return 0;
}

UINT ThreadBlue(LPVOID pParam) {
	CSingleLock syncObjStart(&threadStartBlue);
	syncObjStart.Lock();
	CSnopokLR_7View *ptrView = (CSnopokLR_7View *)pParam;
	for (int i = b; i < 30000; i++) {
		CDC *dc = ptrView->GetDC();
		Sleep(500);
		CRect rect;

		ptrView->GetClientRect(&rect);
		int halfWidth = rect.Width() / 2;
		int halfHeight = rect.Height() / 2;
		dc->SetTextColor(RGB(2, 141, 222));
		dc->TextOut((halfWidth + rand() % (rect.Width() - halfWidth + i)) - i, rand() % (halfHeight + i) - i, CString("Blue"), 4);

		if (runningBlue == FALSE) {
			b = i;
			AfxMessageBox(CString("Синий остановлен"));
			break;
		}
	}

	return 0;
}

UINT ThreadGreen(LPVOID pParam) {
	CSingleLock syncObjStart(&threadStartGreen);
	syncObjStart.Lock();
	CSnopokLR_7View *ptrView = (CSnopokLR_7View *)pParam;
	for (int i = g; i < 30000; i++) {
		CDC *dc = ptrView->GetDC();
		Sleep(500);
		CRect rect;
		ptrView->GetClientRect(&rect);
		int halfWidth = rect.Width() / 2;
		int halfHeight = rect.Height() / 2;
		dc->SetTextColor(RGB(2, 222, 90));
		dc->TextOut(rand() % (halfWidth + i) - i, (halfHeight + rand() % (rect.Height() - halfHeight + i)) - i, CString("Green"), 5);

		if (runningGreen == FALSE) {
			g = i;
			AfxMessageBox(CString("Зеленый остановлен"));
			break;
		}
	}

	return 0;
}

UINT ThreadPurple(LPVOID pParam) {
	CSingleLock syncObjStart(&threadStartPurple);
	syncObjStart.Lock();
	CSnopokLR_7View *ptrView = (CSnopokLR_7View *)pParam;
	for (int i = p; i < 30000; i++) {
		CDC *dc = ptrView->GetDC();
		Sleep(500);
		CRect rect;
		ptrView->GetClientRect(&rect);
		int halfWidth = rect.Width() / 2;
		int halfHeight = rect.Height() / 2;
		dc->SetTextColor(RGB(165, 24, 186));
		dc->TextOut((halfWidth + rand() % (rect.Width() - halfWidth + i)) - i, (halfHeight + rand() % (rect.Height() - halfHeight + i)) - i, CString("Purple"), 6);

		if (runningPurple == FALSE) {
			p = i;
			AfxMessageBox(CString("Фиолетовый остановлен"));
			break;
		}
	}

	return 0;
}

void CSnopokLR_7View::OnCreateThread() {
	AfxBeginThread(ThreadRed, this);
	AfxBeginThread(ThreadBlue, this);
	AfxBeginThread(ThreadGreen, this);
	AfxBeginThread(ThreadPurple, this);
}


void CSnopokLR_7View::OnStartRed() {
	if (r != 0) AfxBeginThread(ThreadRed, this);
	runningRed = TRUE;
	threadStartRed.SetEvent();
}
void CSnopokLR_7View::OnStartGreen() {
	if (g != 0) AfxBeginThread(ThreadGreen, this);
	runningGreen = TRUE;
	threadStartGreen.SetEvent();
}
void CSnopokLR_7View::OnStartBlue() {
	if (b != 0) AfxBeginThread(ThreadBlue, this);
	runningBlue = TRUE;
	threadStartBlue.SetEvent();
}
void CSnopokLR_7View::OnStartPurple() {
	if (p != 0) AfxBeginThread(ThreadPurple, this);
	runningPurple = TRUE;
	threadStartPurple.SetEvent();
}


void CSnopokLR_7View::OnStartRedBlue() {
	runningBlue = TRUE;
	runningRed = TRUE;
	threadStartRed.SetEvent();
	threadStartBlue.SetEvent();
}


void CSnopokLR_7View::OnStartRedBlueGreen() {
	runningGreen = TRUE;
	runningBlue = TRUE;
	runningRed = TRUE;
	threadStartRed.SetEvent();
	threadStartBlue.SetEvent();
	threadStartGreen.SetEvent();
}


void CSnopokLR_7View::OnStartRedBlueGreenPurple() {
	runningPurple = TRUE;
	runningGreen = TRUE;
	runningBlue = TRUE;
	runningRed = TRUE;
	threadStartRed.SetEvent();
	threadStartBlue.SetEvent();
	threadStartGreen.SetEvent();
	threadStartPurple.SetEvent();
}


void CSnopokLR_7View::OnStopRed() {
	runningRed = FALSE;
}
void CSnopokLR_7View::OnStopGreen() {
	runningGreen = FALSE;
}
void CSnopokLR_7View::OnStopBlue() {
	runningBlue = FALSE;
}
void CSnopokLR_7View::OnStopPurple() {
	runningPurple = FALSE;
}
void CSnopokLR_7View::OnStopAll() {
	runningPurple = FALSE;
	runningGreen = FALSE;
	runningBlue = FALSE;
	runningRed = FALSE;
}
