
// SnopokLR_7View.h : ��������� ������ CSnopokLR_7View
//

#pragma once


class CSnopokLR_7View : public CView
{
protected: // ������� ������ �� ������������
	CSnopokLR_7View();
	DECLARE_DYNCREATE(CSnopokLR_7View)

// ��������
public:
	CSnopokLR_7Doc* GetDocument() const;

// ��������
public:

// ���������������
public:
	virtual void OnDraw(CDC* pDC);  // �������������� ��� ��������� ����� �������������
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ����������
public:
	virtual ~CSnopokLR_7View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
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

#ifndef _DEBUG  // ���������� ������ � SnopokLR_7View.cpp
inline CSnopokLR_7Doc* CSnopokLR_7View::GetDocument() const
   { return reinterpret_cast<CSnopokLR_7Doc*>(m_pDocument); }
#endif

