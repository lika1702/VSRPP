
// SnopokIDZ_2Set.h: интерфейс класса CSnopokIDZ_2Set
//


#pragma once

// создаваемый код 7 ноября 2021 г., 19:30

class CSnopokIDZ_2Set : public CRecordset
{
public:
	CSnopokIDZ_2Set(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CSnopokIDZ_2Set)

// Данные полей и параметров

// Следующие типы строк (если присутствуют) отражают фактические типы данных 
// поля базы данных - CStringA для типов данных ANSI и CStringW для типов 
// данных Юникода. Это должно предотвратить выполнение драйвером ODBC 
// потенциально ненужных преобразований.  При желании можно заменить эти члены на 
// типы CString, и драйвер ODBC выполнит все необходимые преобразования.
// (Примечание. Необходимо использовать драйвер ODBC версии 3.5 или более поздней 
// для поддержки как Юникода, так и этих преобразований).

	long	m_index;
	CString	m_name;
	long	m_quantity;
	double	m_price;
	CTime	m_date;

// Переопределение
	// Мастер создал переопределения виртуальных функций
	public:
	virtual CString GetDefaultConnect();	// Строка подключения по умолчанию

	virtual CString GetDefaultSQL(); 	// код SQL по умолчанию для набора записей
	virtual void DoFieldExchange(CFieldExchange* pFX);	// поддержка RFX

// Реализация
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

