
// SnopokLR_4Set.h: интерфейс класса CSnopokLR_4Set
//


#pragma once

// создаваемый код 22 октября 2021 г., 16:07

class CSnopokLR_4Set : public CRecordset
{
public:
	CSnopokLR_4Set(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CSnopokLR_4Set)

// Данные полей и параметров

// Следующие типы строк (если присутствуют) отражают фактические типы данных 
// поля базы данных - CStringA для типов данных ANSI и CStringW для типов 
// данных Юникода. Это должно предотвратить выполнение драйвером ODBC 
// потенциально ненужных преобразований.  При желании можно заменить эти члены на 
// типы CString, и драйвер ODBC выполнит все необходимые преобразования.
// (Примечание. Необходимо использовать драйвер ODBC версии 3.5 или более поздней 
// для поддержки как Юникода, так и этих преобразований).

	long	m_index;
	CString	m_login;
	CString	m_password;
	long	m_day;
	long	m_month;
	long	m_year;
	long	m_hour;
	long	m_minute;
	long	m_duration;

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

