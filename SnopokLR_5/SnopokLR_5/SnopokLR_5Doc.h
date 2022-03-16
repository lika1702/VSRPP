
// SnopokLR_5Doc.h : интерфейс класса CSnopokLR_5Doc
//


#pragma once
#include "SnopokLR_5Set.h"


class CSnopokLR_5Doc : public CDocument
{
protected: // создать только из сериализации
	CSnopokLR_5Doc();
	DECLARE_DYNCREATE(CSnopokLR_5Doc)

// Атрибуты
public:
	CSnopokLR_5Set m_SnopokLR_5Set;

// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CSnopokLR_5Doc();
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
};
