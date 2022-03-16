
// SnopokIDZ_2Doc.cpp : реализация класса CSnopokIDZ_2Doc
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "SnopokIDZ_2.h"
#endif

#include "SnopokIDZ_2Set.h"
#include "SnopokIDZ_2Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSnopokIDZ_2Doc

IMPLEMENT_DYNCREATE(CSnopokIDZ_2Doc, CDocument)

BEGIN_MESSAGE_MAP(CSnopokIDZ_2Doc, CDocument)
END_MESSAGE_MAP()


// создание/уничтожение CSnopokIDZ_2Doc

CSnopokIDZ_2Doc::CSnopokIDZ_2Doc()
{
	// TODO: добавьте код для одноразового вызова конструктора

}

CSnopokIDZ_2Doc::~CSnopokIDZ_2Doc()
{
}

BOOL CSnopokIDZ_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}



#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CSnopokIDZ_2Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
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

// Поддержка обработчиков поиска
void CSnopokIDZ_2Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задайте содержимое поиска из данных документа. 
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CSnopokIDZ_2Doc::SetSearchContent(const CString& value)
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

// диагностика CSnopokIDZ_2Doc

#ifdef _DEBUG
void CSnopokIDZ_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSnopokIDZ_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// команды CSnopokIDZ_2Doc
