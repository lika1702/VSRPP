
// SnopokLR_4View.h : интерфейс класса CSnopokLR_4View
//

#pragma once
#include "afxwin.h"

class CSnopokLR_4Set;

class CSnopokLR_4View : public CRecordView
{
protected: // создать только из сериализации
	CSnopokLR_4View();
	DECLARE_DYNCREATE(CSnopokLR_4View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_SNOPOKLR_4_FORM };
#endif
	CSnopokLR_4Set* m_pSet;

// Атрибуты
public:
	CSnopokLR_4Doc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CSnopokLR_4View();
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
	long m_index;
	CString m_login;
	CString m_password;
	long m_day;
	long m_month;
	long m_year;
	long m_hour;
	long m_minute;
	long m_duration;

	CEdit m_n_login;
	CEdit m_n_password;
	CEdit m_n_day;
	CEdit m_n_month;
	CEdit m_n_year;
	CEdit m_n_hour;
	CEdit m_n_minute;
	CEdit m_n_duration;
	afx_msg void OnBnClickedAddButton();
	afx_msg void OnStnClickedDeleteButton();
	CListBox m_list;
	afx_msg void OnBnClickedButtonFilter();
	CButton m_radio;
	CButton m_check_log;
	CButton m_check_year;
	CButton m_check_duration;
	afx_msg void OnBnClickedButtonFilterReset();
	afx_msg void OnStnClickedRecordEdit();
	afx_msg void OnStnClickedSubmitEdit();
	afx_msg void OnStnClickedGenerateReport();
	afx_msg void OnBnClickedFilterDuration();
};

#ifndef _DEBUG  // отладочная версия в SnopokLR_4View.cpp
inline CSnopokLR_4Doc* CSnopokLR_4View::GetDocument() const
   { return reinterpret_cast<CSnopokLR_4Doc*>(m_pDocument); }
#endif

