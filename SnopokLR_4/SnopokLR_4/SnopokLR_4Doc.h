
// SnopokLR_4Doc.h : ��������� ������ CSnopokLR_4Doc
//


#pragma once
#include "SnopokLR_4Set.h"


class CSnopokLR_4Doc : public CDocument
{
protected: // ������� ������ �� ������������
	CSnopokLR_4Doc();
	DECLARE_DYNCREATE(CSnopokLR_4Doc)

// ��������
public:
	CSnopokLR_4Set m_SnopokLR_4Set;

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
	virtual ~CSnopokLR_4Doc();
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
