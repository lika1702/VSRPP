
// SnopokLR_5Doc.h : ��������� ������ CSnopokLR_5Doc
//


#pragma once
#include "SnopokLR_5Set.h"


class CSnopokLR_5Doc : public CDocument
{
protected: // ������� ������ �� ������������
	CSnopokLR_5Doc();
	DECLARE_DYNCREATE(CSnopokLR_5Doc)

// ��������
public:
	CSnopokLR_5Set m_SnopokLR_5Set;

// ��������
public:

// ���������������
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ����������
public:
	virtual ~CSnopokLR_5Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ��������������� �������, �������� ���������� ������ ��� ����������� ������
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
