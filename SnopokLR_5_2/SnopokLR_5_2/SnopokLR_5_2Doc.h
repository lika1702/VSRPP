
// SnopokLR_5_2Doc.h : интерфейс класса CSnopokLR_5_2Doc
//


#pragma once
#include "SnopokLR_5_2Set.h"


class CSnopokLR_5_2Doc : public CDocument
{
protected: // создать только из сериализации
	CSnopokLR_5_2Doc();
	DECLARE_DYNCREATE(CSnopokLR_5_2Doc)

// Атрибуты
public:
	CSnopokLR_5_2Set m_SnopokLR_5_2Set;

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
	virtual ~CSnopokLR_5_2Doc();
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
