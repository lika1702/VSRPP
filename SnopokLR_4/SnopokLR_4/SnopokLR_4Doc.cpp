
// SnopokLR_4Doc.cpp : ���������� ������ CSnopokLR_4Doc
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "SnopokLR_4.h"
#endif

#include "SnopokLR_4Set.h"
#include "SnopokLR_4Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSnopokLR_4Doc

IMPLEMENT_DYNCREATE(CSnopokLR_4Doc, CDocument)

BEGIN_MESSAGE_MAP(CSnopokLR_4Doc, CDocument)
END_MESSAGE_MAP()


// ��������/����������� CSnopokLR_4Doc

CSnopokLR_4Doc::CSnopokLR_4Doc()
{
	// TODO: �������� ��� ��� ������������ ������ ������������

}

CSnopokLR_4Doc::~CSnopokLR_4Doc()
{
}

BOOL CSnopokLR_4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �������� ��� ��������� �������������
	// (��������� SDI ����� �������� ������������ ���� ��������)

	return TRUE;
}



#ifdef SHARED_HANDLERS

// ��������� ��� �������
void CSnopokLR_4Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �������� ���� ��� ��� ����������� ������ ���������
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ��������� ������������ ������
void CSnopokLR_4Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������� ���������� ������ �� ������ ���������. 
	// ����� ����������� ������ ����������� ������ � ������� ";"

	// ��������:  strSearchContent = _T("�����;�������������;����;������ ole;");
	SetSearchContent(strSearchContent);
}

void CSnopokLR_4Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// ����������� CSnopokLR_4Doc

#ifdef _DEBUG
void CSnopokLR_4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSnopokLR_4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// ������� CSnopokLR_4Doc
