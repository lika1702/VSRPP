
// SnopokLR_5_2View.h : интерфейс класса CSnopokLR_5_2View
//

#pragma once
#include "afxwin.h"

class CSnopokLR_5_2Set;

class CSnopokLR_5_2View : public COleDBRecordView
{
protected: // создать только из сериализации
	CSnopokLR_5_2View();
	DECLARE_DYNCREATE(CSnopokLR_5_2View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_SNOPOKLR_5_2_FORM };
#endif
	CSnopokLR_5_2Set* m_pSet;

// Атрибуты
public:
	CSnopokLR_5_2Doc* GetDocument() const;

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

// Реализация
public:
	virtual ~CSnopokLR_5_2View();
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
	CString m_where_str;
	CString m_order_str;
	CEdit m_index;
	CEdit m_login;
	CEdit m_password;
	CEdit m_day;
	CEdit m_month;
	CEdit m_year;
	CEdit m_hour;
	CEdit m_minute;
	CEdit m_duration;
	CEdit m_new_login;
	CEdit m_new_password;
	CEdit m_new_day;
	CEdit m_new_month;
	CEdit m_new_year;
	CEdit m_new_hour;
	CEdit m_new_minute;
	CEdit m_new_duration;
	void FillOleDBParameters();
	void displayMembersOfDataSourse();
	void ReQuery(void);
	void DoFilter(CString column);
	CString toString();
	afx_msg void OnStnClickedRecordDelete();
	afx_msg void OnStnClickedRecordAdd();
	afx_msg void OnStnClickedResetForm();
	afx_msg void OnStnClickedRecordEdit();
	afx_msg void OnStnClickedRecordSubmit();
	afx_msg void OnBnClickedSortByIndex();
	afx_msg void OnBnClickedSortByLogin();
	afx_msg void OnBnClickedSortByYear();
	afx_msg void OnBnClickedFilterByIndex();
	afx_msg void OnBnClickedFilterByLogin();
	afx_msg void OnBnClickedFilterByYear();
	CListBox m_user_list;
	afx_msg void OnBnClickedDisplayList();
	afx_msg void OnBnClickedDisplayReport();
	afx_msg void OnStnClickedResetFilter();
	afx_msg void OnBnClickedSortBySession();
};

#ifndef _DEBUG  // отладочная версия в SnopokLR_5_2View.cpp
inline CSnopokLR_5_2Doc* CSnopokLR_5_2View::GetDocument() const
   { return reinterpret_cast<CSnopokLR_5_2Doc*>(m_pDocument); }
#endif

