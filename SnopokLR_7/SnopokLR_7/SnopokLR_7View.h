
// SnopokLR_7View.h : интерфейс класса CSnopokLR_7View
//

#pragma once


class CSnopokLR_7View : public CView
{
protected: // создать только из сериализации
	CSnopokLR_7View();
	DECLARE_DYNCREATE(CSnopokLR_7View)

// Атрибуты
public:
	CSnopokLR_7Doc* GetDocument() const;

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
	virtual ~CSnopokLR_7View();
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
	afx_msg void OnCreateThread();
	afx_msg void OnStartRed();
	afx_msg void OnStartGreen();
	afx_msg void OnStartBlue();
	afx_msg void OnStartPurple();
	afx_msg void OnStartRedBlue();
	afx_msg void OnStartRedBlueGreen();
	afx_msg void OnStartRedBlueGreenPurple();
	afx_msg void OnStopRed();
	afx_msg void OnStopGreen();
	afx_msg void OnStopBlue();
	afx_msg void OnStopPurple();
	afx_msg void OnStopAll();
};

#ifndef _DEBUG  // отладочная версия в SnopokLR_7View.cpp
inline CSnopokLR_7Doc* CSnopokLR_7View::GetDocument() const
   { return reinterpret_cast<CSnopokLR_7Doc*>(m_pDocument); }
#endif

