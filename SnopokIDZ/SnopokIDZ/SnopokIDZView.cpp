
// SnopokIDZView.cpp: реализация класса CSnopokIDZView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "SnopokIDZ.h"
#endif

#include "SnopokIDZDoc.h"
#include "SnopokIDZView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSnopokIDZView
IMPLEMENT_DYNCREATE(CSnopokIDZView, CView)

BEGIN_MESSAGE_MAP(CSnopokIDZView, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSnopokIDZView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_REDRAW_ELLIPSE, &CSnopokIDZView::OnRedrawEllipse)
	ON_COMMAND(ID_REDRAW_RECTANGLE, &CSnopokIDZView::OnRedrawRectangle)
	ON_COMMAND(ID_DRAW_ELLIPSE, &CSnopokIDZView::OnDrawEllipse)
	ON_COMMAND(ID_DRAW_LINE, &CSnopokIDZView::OnDrawLine)
	ON_COMMAND(ID_DRAW_RECTANGLE, &CSnopokIDZView::OnDrawRectangle)
	ON_COMMAND(ID_COLOR_BLACK, &CSnopokIDZView::OnColorBlack)
	ON_COMMAND(ID_COLOR_BLUE, &CSnopokIDZView::OnColorBlue)
	ON_COMMAND(ID_COLOR_CYAN, &CSnopokIDZView::OnColorCyan)
	ON_COMMAND(ID_COLOR_GREEN, &CSnopokIDZView::OnColorGreen)
	ON_COMMAND(ID_COLOR_ORANGE, &CSnopokIDZView::OnColorOrange)
	ON_COMMAND(ID_COLOR_PURPLE, &CSnopokIDZView::OnColorPurple)
	ON_COMMAND(ID_COLOR_RED, &CSnopokIDZView::OnColorRed)
	ON_COMMAND(ID_COLOR_VIOLET, &CSnopokIDZView::OnColorViolet)
	ON_COMMAND(ID_COLOR_WHITE, &CSnopokIDZView::OnColorWhite)
	ON_COMMAND(ID_COLOR_YELLOW, &CSnopokIDZView::OnColorYellow)
	ON_COMMAND(ID_COLOR_DARK_GREEN, &CSnopokIDZView::OnColorDarkGreen)
	ON_COMMAND(ID_COLOR_SKY_BLUE, &CSnopokIDZView::OnColorSkyBlue)
	ON_COMMAND(ID_COLOR_BROWN, &CSnopokIDZView::OnColorBrown)
	ON_COMMAND(ID_REDRAW_RED_ELLIPSE, &CSnopokIDZView::OnRedrawRedEllipse)
END_MESSAGE_MAP()

// Создание или уничтожение CSnopokIDZView

CSnopokIDZView::CSnopokIDZView() noexcept {
	// TODO: добавьте код создания
	m_Dragging = 0;
	m_HCross = AfxGetApp()->LoadStandardCursor(IDC_CROSS);
}

CSnopokIDZView::~CSnopokIDZView() { }

BOOL CSnopokIDZView::PreCreateWindow(CREATESTRUCT& cs) {
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs
	m_ClassName = AfxRegisterWndClass(
		CS_HREDRAW | CS_VREDRAW, // стили окна
		0, // без указателя;
		(HBRUSH)::GetStockObject(WHITE_BRUSH), // задать чисто белый фон;
		0); // без значка

	cs.lpszClass = m_ClassName;

	return CView::PreCreateWindow(cs);
}

// Рисование CSnopokIDZView
void CSnopokIDZView::OnDraw(CDC* pDC) {
	CSnopokIDZDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
	int Index = pDoc->GetNumFigures();
	int i = 0;
	while (i < Index) {
		pDoc->GetFigure(i)->Draw(pDC);
		i++;
	}
}

// Печать CSnopokIDZView
void CSnopokIDZView::OnFilePrintPreview() {
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSnopokIDZView::OnPreparePrinting(CPrintInfo* pInfo) {
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CSnopokIDZView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/) {
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CSnopokIDZView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/) {
	// TODO: добавьте очистку после печати
}

void CSnopokIDZView::OnRButtonUp(UINT /* nFlags */, CPoint point) {
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSnopokIDZView::OnContextMenu(CWnd* /* pWnd */, CPoint point) {
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}

// Диагностика CSnopokIDZView
#ifdef _DEBUG
void CSnopokIDZView::AssertValid() const {
	CView::AssertValid();
}

void CSnopokIDZView::Dump(CDumpContext& dc) const {
	CView::Dump(dc);
}

CSnopokIDZDoc* CSnopokIDZView::GetDocument() const { // встроена неотлаженная версия
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSnopokIDZDoc)));
	return (CSnopokIDZDoc*)m_pDocument;
}
#endif //_DEBUG

// Обработчики сообщений CSnopokIDZView
void CSnopokIDZView::OnLButtonDown(UINT nFlags, CPoint point) {
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	m_PointOld = point;
	m_PointOrigin = point;
	SetCapture();
	m_Dragging = 1;
	RECT Rect;
	GetClientRect(&Rect);
	ClientToScreen(&Rect);
	::ClipCursor(&Rect);
	CView::OnLButtonDown(nFlags, point);
}

void CSnopokIDZView::OnMouseMove(UINT nFlags, CPoint point) {
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	::SetCursor(m_HCross);
	if (m_Dragging) {
		CClientDC ClientDC(this);
		if (flag == 0) {
			ClientDC.SetROP2(R2_NOT);
			ClientDC.Rectangle(m_PointOrigin.x, m_PointOrigin.y, m_PointOld.x, m_PointOld.y);
			ClientDC.Rectangle(m_PointOrigin.x, m_PointOrigin.y, point.x, point.y);
		}
		if (flag == 1) {
			ClientDC.SetROP2(R2_NOT);
			ClientDC.Ellipse(m_PointOrigin.x, m_PointOrigin.y, m_PointOld.x, m_PointOld.y);
			ClientDC.Ellipse(m_PointOrigin.x, m_PointOrigin.y, point.x, point.y);
		}
		if (flag == 2) {
			ClientDC.SetROP2(R2_NOT);
			ClientDC.MoveTo(m_PointOrigin);
			ClientDC.LineTo(m_PointOld);
			ClientDC.MoveTo(m_PointOrigin);
			ClientDC.LineTo(point);
		}
		m_PointOld = point;
	}
	CView::OnMouseMove(nFlags, point);
}

void CSnopokIDZView::OnLButtonUp(UINT nFlags, CPoint point) {
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	if (m_Dragging) {
		m_Dragging = 0;
		::ReleaseCapture();
		::ClipCursor(NULL);
		CClientDC ClientDC(this);
		CSnopokIDZDoc* pDoc = GetDocument();
		if (flag == 0) {
			CBrush brush(g_color);
			ClientDC.SelectObject(&brush);
			ClientDC.SetROP2(R2_NOT);
			ClientDC.Rectangle(m_PointOrigin.x, m_PointOrigin.y, m_PointOld.x, m_PointOld.y);
			ClientDC.SetROP2(R2_COPYPEN);
			ClientDC.Rectangle(m_PointOrigin.x, m_PointOrigin.y, point.x, point.y);
			pDoc->AddFigure(m_PointOrigin.x, m_PointOrigin.y, point.x, point.y, g_color, flag);
		}
		if (flag == 1) {
			CBrush brush(g_color);
			ClientDC.SelectObject(&brush);
			ClientDC.SetROP2(R2_NOT);
			ClientDC.Ellipse(m_PointOrigin.x, m_PointOrigin.y, m_PointOld.x, m_PointOld.y);
			ClientDC.SetROP2(R2_COPYPEN);
			ClientDC.Ellipse(m_PointOrigin.x, m_PointOrigin.y, point.x, point.y);
			pDoc->AddFigure(m_PointOrigin.x, m_PointOrigin.y, point.x, point.y, g_color, flag);
		}
		if (flag == 2) {
			CPen pen(PS_SOLID, 2, g_color);
			ClientDC.SelectObject(&pen);
			ClientDC.SetROP2(R2_NOT);
			ClientDC.MoveTo(m_PointOrigin);
			ClientDC.LineTo(m_PointOld);
			ClientDC.SetROP2(R2_COPYPEN);
			ClientDC.MoveTo(m_PointOrigin);
			ClientDC.LineTo(point);
			pDoc->AddFigure(m_PointOrigin.x, m_PointOrigin.y, point.x, point.y, g_color, flag);
		}		
	}

	CView::OnLButtonUp(nFlags, point);
}

void CSnopokIDZView::OnRedrawEllipse() {
	CSnopokIDZDoc* pDoc = GetDocument();
	pDoc->setFlag(1);
	RedrawWindow();
}


void CSnopokIDZView::OnRedrawRedEllipse() {
	CSnopokIDZDoc* pDoc = GetDocument();
	pDoc->setColor(RGB(255, 0, 0));
	pDoc->setFlag(1);
	RedrawWindow();
}


void CSnopokIDZView::OnRedrawRectangle() {
	CSnopokIDZDoc* pDoc = GetDocument();
	pDoc->setFlag(0);
	RedrawWindow();
}

void CSnopokIDZView::OnDrawRectangle() { flag = 0; }
void CSnopokIDZView::OnDrawEllipse() { flag = 1; }
void CSnopokIDZView::OnDrawLine() {	flag = 2; }

void CSnopokIDZView::OnColorRed() { g_color = RGB(255, 0, 0); }
void CSnopokIDZView::OnColorOrange() { g_color = RGB(255, 170, 0); }
void CSnopokIDZView::OnColorYellow() { g_color = RGB(251, 255, 0); }
void CSnopokIDZView::OnColorGreen() { g_color = RGB(0, 255, 0); }
void CSnopokIDZView::OnColorCyan() { g_color = RGB(0, 255, 255); }
void CSnopokIDZView::OnColorBlue() { g_color = RGB(0, 0, 255); }
void CSnopokIDZView::OnColorViolet() { g_color = RGB(221, 0, 255); }

void CSnopokIDZView::OnColorBlack() { g_color = RGB(0, 0, 0); }
void CSnopokIDZView::OnColorWhite() { g_color = RGB(255, 255, 255); }

void CSnopokIDZView::OnColorPurple() { g_color = RGB(226, 0, 122); }
void CSnopokIDZView::OnColorBrown() { g_color = RGB(152, 118, 84); }
void CSnopokIDZView::OnColorDarkGreen() { g_color = RGB(23, 114, 69); }
void CSnopokIDZView::OnColorSkyBlue() { g_color = RGB(0, 191, 255); }