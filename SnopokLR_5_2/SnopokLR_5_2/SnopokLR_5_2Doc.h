
// SnopokLR_5_2Doc.h : ��������� ������ CSnopokLR_5_2Doc
//


#pragma once
#include "SnopokLR_5_2Set.h"


class CSnopokLR_5_2Doc : public CDocument
{
protected: // ������� ������ �� ������������
	CSnopokLR_5_2Doc();
	DECLARE_DYNCREATE(CSnopokLR_5_2Doc)

// ��������
public:
	CSnopokLR_5_2Set m_SnopokLR_5_2Set;

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
	virtual ~CSnopokLR_5_2Doc();
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
