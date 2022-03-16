
// SnopokLR_4Doc.h : интерфейс класса CSnopokLR_4Doc
//


#pragma once
#include "SnopokLR_4Set.h"


class CSnopokLR_4Doc : public CDocument
{
protected: // создать только из сериализации
	CSnopokLR_4Doc();
	DECLARE_DYNCREATE(CSnopokLR_4Doc)

// Атрибуты
public:
	CSnopokLR_4Set m_SnopokLR_4Set;

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
	virtual ~CSnopokLR_4Doc();
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
