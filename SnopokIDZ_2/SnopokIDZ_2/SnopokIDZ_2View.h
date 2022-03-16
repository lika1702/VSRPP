
// SnopokIDZ_2View.h : интерфейс класса CSnopokIDZ_2View
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"

class CSnopokIDZ_2Set;

class CSnopokIDZ_2View : public CRecordView
{
protected: // создать только из сериализации
	CSnopokIDZ_2View();
	DECLARE_DYNCREATE(CSnopokIDZ_2View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_SNOPOKIDZ_2_FORM };
#endif
	CSnopokIDZ_2Set* m_pSet;

// Атрибуты
public:
	CSnopokIDZ_2Doc* GetDocument() const;

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
	virtual ~CSnopokIDZ_2View();
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
	afx_msg void OnStnClickedRecordAdd();
	afx_msg void OnStnClickedRecordEdit();
	afx_msg void OnStnClickedRecordDelete();
	afx_msg void OnStnClickedFormClose();
	afx_msg void OnBnClickedRecordSave();

	void ShowForm(int param);
	void ClearForm();
	void SetRead(bool param);
	void DoFilter(CString column, bool flag);
	void DisplayList();
	CString toString();

	CEdit m_index;
	CEdit m_name;
	CEdit m_quantity;
	CEdit m_price;
	CEdit m_date;
	CEdit m_new_name;
	CEdit m_new_quantity;
	CEdit m_new_price;
	CEdit m_new_date;

	bool m_editing;
	bool m_exist_list;
	
	afx_msg void OnBnClickedSortByIndex();
	afx_msg void OnBnClickedSortByName();
	afx_msg void OnBnClickedSortByQuantity();
	afx_msg void OnBnClickedSortByPrice();
	afx_msg void OnBnClickedSortByDate();
	
	CButton m_desc;
	afx_msg void OnStnClickedDisplayList();
	CListCtrl m_list_equipment;
	afx_msg void OnBnClickedFilterByIndex();
	afx_msg void OnBnClickedFilterByName();
	afx_msg void OnBnClickedFilterByPrice();
	afx_msg void OnBnClickedFilterByQuantity();
	afx_msg void OnBnClickedFilterByDate();
	afx_msg void OnBnClickedReport();
	afx_msg void OnBnClickedFilterReset();
	afx_msg void OnCreateListDialog();
};

#ifndef _DEBUG  // отладочная версия в SnopokIDZ_2View.cpp
inline CSnopokIDZ_2Doc* CSnopokIDZ_2View::GetDocument() const
   { return reinterpret_cast<CSnopokIDZ_2Doc*>(m_pDocument); }
#endif

