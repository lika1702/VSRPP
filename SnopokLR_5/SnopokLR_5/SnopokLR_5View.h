
// SnopokLR_5View.h : интерфейс класса CSnopokLR_5View
//

#pragma once
#include "afxwin.h"

class CSnopokLR_5Set;

class CSnopokLR_5View : public COleDBRecordView
{
protected: // создать только из сериализации
	CSnopokLR_5View();
	DECLARE_DYNCREATE(CSnopokLR_5View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_SNOPOKLR_5_FORM };
#endif
	CSnopokLR_5Set* m_pSet;

// Атрибуты
public:
	CSnopokLR_5Doc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual CRowset<>* OnGetRowset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	void displayMembersOfDataSourse();
	void FillOleDBParameters();
// Реализация
public:
	virtual ~CSnopokLR_5View();
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
	bool m_bAdding;
	CEdit m_index;
	CEdit m_login;
	CEdit m_password;
	CEdit m_day;
	CEdit m_month;
	CEdit m_year;
	CEdit m_hour;
	CEdit m_minute;
	CEdit m_duration;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordLast();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordPrev();
	afx_msg void OnUpdateRecordFirst(CCmdUI *pCmdUI);
	afx_msg void OnUpdateRecordPrev(CCmdUI *pCmdUI);
	afx_msg void OnBnClickedInsert();
	afx_msg void OnBnClickedEdit();
	afx_msg void OnBnClickedDelete();
};

#ifndef _DEBUG  // отладочная версия в SnopokLR_5View.cpp
inline CSnopokLR_5Doc* CSnopokLR_5View::GetDocument() const
   { return reinterpret_cast<CSnopokLR_5Doc*>(m_pDocument); }
#endif

