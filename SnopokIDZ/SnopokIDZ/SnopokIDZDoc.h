
// SnopokIDZDoc.h: интерфейс класса CSnopokIDZDoc 
//
#include "Afxtempl.h"

#pragma once

class CFigure : public CObject {
protected:
	int m_X1, m_Y1, m_X2, m_Y2, m_flag;
	COLORREF m_color;
	CFigure() {}
	DECLARE_SERIAL(CFigure)
public:
	CFigure(int X1, int Y1, int X2, int Y2, COLORREF color, int flag) {
		m_X1 = X1; m_Y1 = Y1; m_X2 = X2; m_Y2 = Y2;
		this->m_color = color;
		this->m_flag = flag;
	}
	void Draw(CDC* PDC);
	virtual void Serialize(CArchive& ar);
	void Flag(int flag) { this->m_flag = flag; }
	void Color(COLORREF color) { this->m_color = color; }
	int getFlag() { return m_flag; }
};

class CSnopokIDZDoc : public CDocument {
protected:
	CTypedPtrArray<CObArray, CFigure*> m_FigureArray;
	CTypedPtrArray<CObArray, CFigure*> m_redo_FigureArray;
public:
	void AddFigure(int X1, int Y1, int X2, int Y2, COLORREF color, int flag);
	CFigure* GetFigure(int Index);
	int GetNumFigures();
	void setFlag(int flag);
	void setColor(COLORREF color);
protected: // создать только из сериализации
	CSnopokIDZDoc() noexcept;
	DECLARE_DYNCREATE(CSnopokIDZDoc)

// Атрибуты
public:

// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CSnopokIDZDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual void DeleteContents();
	afx_msg void OnEditClearAll();
	afx_msg void OnUpdateEditClearAll(CCmdUI* pCmdUI);
	afx_msg void OnEditUndo();
	afx_msg void OnUpdateEditUndo(CCmdUI* pCmdUI);
//	afx_msg void On32772();
//	afx_msg void OnEditRedo();
//	afx_msg void OnUpdateEditRedo(CCmdUI* pCmdUI);
//	afx_msg void OnEditRedoAll();
//	afx_msg void OnUpdateEditRedoAll(CCmdUI* pCmdUI);
	afx_msg void OnEditRedo();
	afx_msg void OnUpdateEditRedo(CCmdUI* pCmdUI);
	afx_msg void OnEditRedoAll();
	afx_msg void OnUpdateEditRedoAll(CCmdUI* pCmdUI);
};
