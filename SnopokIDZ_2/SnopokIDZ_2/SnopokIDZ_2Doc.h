
// SnopokIDZ_2Doc.h : интерфейс класса CSnopokIDZ_2Doc
//


#pragma once
#include "SnopokIDZ_2Set.h"


class CSnopokIDZ_2Doc : public CDocument
{
protected: // создать только из сериализации
	CSnopokIDZ_2Doc();
	DECLARE_DYNCREATE(CSnopokIDZ_2Doc)

// Атрибуты
public:
	CSnopokIDZ_2Set m_SnopokIDZ_2Set;

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
	virtual ~CSnopokIDZ_2Doc();
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
