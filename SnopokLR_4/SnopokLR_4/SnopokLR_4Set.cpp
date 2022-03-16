
// SnopokLR_4Set.cpp : реализация класса CSnopokLR_4Set
//

#include "stdafx.h"
#include "SnopokLR_4.h"
#include "SnopokLR_4Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// реализация CSnopokLR_4Set

// создаваемый код 22 октября 2021 г., 16:07

IMPLEMENT_DYNAMIC(CSnopokLR_4Set, CRecordset)

CSnopokLR_4Set::CSnopokLR_4Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_index = 0;
	m_login = L"";
	m_password = L"";
	m_day = 0;
	m_month = 0;
	m_year = 0;
	m_hour = 0;
	m_minute = 0;
	m_duration = 0;
	m_nFields = 9;
	m_nDefaultType = dynaset;
}
//#error Проблема безопасности: строка подключения может содержать пароль 
// Следующая строка подключения может содержать незашифрованные пароли или 
// другую конфиденциальную информацию. Удалите #error после просмотра строки подключения 
// в целях безопасности. Возможно, 
// потребуется сохранить пароль в другом виде или использовать другую аутентификацию.
CString CSnopokLR_4Set::GetDefaultConnect()
{
	return _T("DSN=MS Access Database;DBQ=D:\\\x0412\x0421\x0420\x041f\x041f\\DB_for_4.accdb;DefaultDir=D:\\\x0412\x0421\x0420\x041f\x041f;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CSnopokLR_4Set::GetDefaultSQL()
{
	return _T("[User]");
}

void CSnopokLR_4Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Такие макросы, как RFX_Text() и RFX_Int(), зависят от типа 
// переменной члена, а не от типа поля в базе данных.
// ODBC выполняет попытку автоматически преобразовать значение столбца к нужному типу
	RFX_Long(pFX, _T("[Код]"), m_index);
	RFX_Text(pFX, _T("[Логин]"), m_login);
	RFX_Text(pFX, _T("[Пароль]"), m_password);
	RFX_Long(pFX, _T("[День]"), m_day);
	RFX_Long(pFX, _T("[Месяц]"), m_month);
	RFX_Long(pFX, _T("[Год]"), m_year);
	RFX_Long(pFX, _T("[Часы]"), m_hour);
	RFX_Long(pFX, _T("[Минуты]"), m_minute);
	RFX_Long(pFX, _T("[Длительность сессии]"), m_duration);

}
/////////////////////////////////////////////////////////////////////////////
// CSnopokLR_4Set диагностика

#ifdef _DEBUG
void CSnopokLR_4Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CSnopokLR_4Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

