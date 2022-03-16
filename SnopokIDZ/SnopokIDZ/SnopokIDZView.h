
// SnopokIDZView.h: интерфейс класса CSnopokIDZView
//

#pragma once

class CSnopokIDZView : public CView {
protected:
	CString m_ClassName;
	int m_Dragging;
	HCURSOR m_HCross;
	CPoint m_PointOld;
	CPoint m_PointOrigin;
	COLORREF g_color;
	int flag;
protected: // создать только из сериализации
	CSnopokIDZView() noexcept;
	DECLARE_DYNCREATE(CSnopokIDZView)

// Атрибуты
public:
	CSnopokIDZDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CSnopokIDZView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRedrawEllipse();
	afx_msg void OnRedrawRectangle();
	afx_msg void OnDrawEllipse();
	afx_msg void OnDrawLine();
	afx_msg void OnDrawRectangle();
	afx_msg void OnColorBlack();
	afx_msg void OnColorBlue();
	afx_msg void OnColorCyan();
	afx_msg void OnColorGreen();
	afx_msg void OnColorOrange();
	afx_msg void OnColorPurple();
	afx_msg void OnColorRed();
	afx_msg void OnColorViolet();
	afx_msg void OnColorWhite();
	afx_msg void OnColorYellow();
	afx_msg void OnColorDarkGreen();
	afx_msg void OnColorSkyBlue();
	afx_msg void OnColorBrown();
	afx_msg void OnRedrawRedEllipse();
};

#ifndef _DEBUG  // версия отладки в SnopokIDZView.cpp
inline CSnopokIDZDoc* CSnopokIDZView::GetDocument() const
   { return reinterpret_cast<CSnopokIDZDoc*>(m_pDocument); }
#endif

