
// SnopokIDZ_2Doc.h : ��������� ������ CSnopokIDZ_2Doc
//


#pragma once
#include "SnopokIDZ_2Set.h"


class CSnopokIDZ_2Doc : public CDocument
{
protected: // ������� ������ �� ������������
	CSnopokIDZ_2Doc();
	DECLARE_DYNCREATE(CSnopokIDZ_2Doc)

// ��������
public:
	CSnopokIDZ_2Set m_SnopokIDZ_2Set;

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
	virtual ~CSnopokIDZ_2Doc();
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
