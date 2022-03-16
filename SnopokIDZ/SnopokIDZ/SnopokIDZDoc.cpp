
// SnopokIDZDoc.cpp: реализация класса CSnopokIDZDoc 
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "SnopokIDZ.h"
#endif

#include "SnopokIDZDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSnopokIDZDoc

IMPLEMENT_DYNCREATE(CSnopokIDZDoc, CDocument)

BEGIN_MESSAGE_MAP(CSnopokIDZDoc, CDocument)
	ON_COMMAND(ID_EDIT_CLEAR_ALL, &CSnopokIDZDoc::OnEditClearAll)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CLEAR_ALL, &CSnopokIDZDoc::OnUpdateEditClearAll)
	ON_COMMAND(ID_EDIT_UNDO, &CSnopokIDZDoc::OnEditUndo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_UNDO, &CSnopokIDZDoc::OnUpdateEditUndo)
	ON_COMMAND(ID_EDIT_REDO, &CSnopokIDZDoc::OnEditRedo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_REDO, &CSnopokIDZDoc::OnUpdateEditRedo)
	ON_COMMAND(ID_EDIT_REDO_ALL, &CSnopokIDZDoc::OnEditRedoAll)
	ON_UPDATE_COMMAND_UI(ID_EDIT_REDO_ALL, &CSnopokIDZDoc::OnUpdateEditRedoAll)
END_MESSAGE_MAP()


// Создание или уничтожение CSnopokIDZDoc

CSnopokIDZDoc::CSnopokIDZDoc() noexcept {
	// TODO: добавьте код для одноразового вызова конструктора

}

CSnopokIDZDoc::~CSnopokIDZDoc() { }

BOOL CSnopokIDZDoc::OnNewDocument() {
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}

// Сериализация CSnopokIDZDoc

void CSnopokIDZDoc::Serialize(CArchive& ar) {
	if (ar.IsStoring()) {
		m_FigureArray.Serialize(ar);
	}
	else {
		m_FigureArray.Serialize(ar);
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CSnopokIDZDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CSnopokIDZDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CSnopokIDZDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Диагностика CSnopokIDZDoc

#ifdef _DEBUG
void CSnopokIDZDoc::AssertValid() const {
	CDocument::AssertValid();
}

void CSnopokIDZDoc::Dump(CDumpContext& dc) const {
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды CSnopokIDZDoc
IMPLEMENT_SERIAL(CFigure, CObject, 1)
void CFigure::Draw(CDC* PDC) {
	CPen oldPen(PS_SOLID, 1, RGB(0, 0, 0));
	PDC->SelectObject(&oldPen);
	if (m_flag == 0) {
		CBrush brush(m_color);
		PDC->SelectObject(&brush);
		PDC->Rectangle(m_X1, m_Y1, m_X2, m_Y2);
	}
	if (m_flag == 1) {
		CBrush brush(m_color);
		PDC->SelectObject(&brush);
		PDC->Ellipse(m_X1, m_Y1, m_X2, m_Y2);
	}
	if (m_flag == 2) {
		CPen pen(PS_SOLID, 2, m_color);
		PDC->SelectObject(&pen);
		PDC->MoveTo(m_X1, m_Y1);
		PDC->LineTo(m_X2, m_Y2);
	}
}

void CFigure::Serialize(CArchive& ar) {
	if (ar.IsStoring())
		ar << m_X1 << m_Y1 << m_X2 << m_Y2 << m_color << m_flag;
	else
		ar >> m_X1 >> m_Y1 >> m_X2 >> m_Y2 >> m_color >> m_flag;
}


void CSnopokIDZDoc::AddFigure(int X1, int Y1, int X2, int Y2, COLORREF color, int flag) {
	CFigure* pFigure = new CFigure(X1, Y1, X2, Y2, color, flag);
	m_FigureArray.Add(pFigure);
	SetModifiedFlag();
}

CFigure* CSnopokIDZDoc::GetFigure(int Index) {
	if (Index<0 || Index>m_FigureArray.GetUpperBound())
		return 0;
	return m_FigureArray.GetAt(Index);
}

int CSnopokIDZDoc::GetNumFigures() {
	return (int)m_FigureArray.GetSize();
}
void CSnopokIDZDoc::setFlag(int flag) {
	int size = m_FigureArray.GetSize();
	for (int i = 0; i < size; i++) {
		if (m_FigureArray.GetAt(i)->getFlag() != 2)
			m_FigureArray.GetAt(i)->Flag(flag);
	}
}
void CSnopokIDZDoc::setColor(COLORREF color) {
	int size = m_FigureArray.GetSize();
	for (int i = 0; i < size; i++) {
		if (m_FigureArray.GetAt(i)->getFlag() != 2 && m_FigureArray.GetAt(i)->getFlag() != 1)
			m_FigureArray.GetAt(i)->Color(color);
	}
}

void CSnopokIDZDoc::DeleteContents() {
	// TODO: добавьте специализированный код или вызов базового класса
	int Index = (int)m_FigureArray.GetSize();
	while (Index--)
		m_redo_FigureArray.Add(m_FigureArray.GetAt(Index));
	m_FigureArray.RemoveAll();
	CDocument::DeleteContents();
}

void CSnopokIDZDoc::OnEditClearAll() {
	// TODO: добавьте свой код обработчика команд
	DeleteContents();
	UpdateAllViews(0);
	SetModifiedFlag();
}

void CSnopokIDZDoc::OnUpdateEditClearAll(CCmdUI* pCmdUI) {
	// TODO: добавьте свой код обработчика ИП обновления команд
	pCmdUI->Enable((int)m_FigureArray.GetSize());
}

void CSnopokIDZDoc::OnEditUndo() {
	// TODO: добавьте свой код обработчика команд
	int Index = (int)m_FigureArray.GetUpperBound();
	int Index2 = (int)m_redo_FigureArray.GetUpperBound();
	if (Index > -1) {
		m_redo_FigureArray.Add(m_FigureArray.GetAt(Index));
		m_FigureArray.RemoveAt(Index);
	}

	UpdateAllViews(0);
	SetModifiedFlag();
}

void CSnopokIDZDoc::OnUpdateEditUndo(CCmdUI* pCmdUI) {
	// TODO: добавьте свой код обработчика ИП обновления команд
	pCmdUI->Enable((int)m_FigureArray.GetSize());
}

void CSnopokIDZDoc::OnEditRedo() {
	int Index2 = (int)m_redo_FigureArray.GetUpperBound();
	if (Index2 > -1) {
		m_FigureArray.Add(m_redo_FigureArray.GetAt(Index2));
		m_redo_FigureArray.RemoveAt(Index2);
		m_redo_FigureArray.RemoveAll();
	}
	UpdateAllViews(0);
	SetModifiedFlag();
}

void CSnopokIDZDoc::OnUpdateEditRedo(CCmdUI* pCmdUI) {
	pCmdUI->Enable((int)m_FigureArray.GetSize());
}

void CSnopokIDZDoc::OnEditRedoAll() {
	int Index = (int)m_redo_FigureArray.GetSize();
	while (Index--) {
		m_FigureArray.Add(m_redo_FigureArray.GetAt(Index));
	}
	m_redo_FigureArray.RemoveAll();
	UpdateAllViews(0);
	SetModifiedFlag();
}

void CSnopokIDZDoc::OnUpdateEditRedoAll(CCmdUI* pCmdUI) {
	pCmdUI->Enable((int)m_redo_FigureArray.GetSize());
}
