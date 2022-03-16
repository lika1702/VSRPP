
// SnopokIDZ_2Set.cpp : реализация класса CSnopokIDZ_2Set
//

#include "stdafx.h"
#include "SnopokIDZ_2.h"
#include "SnopokIDZ_2Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// реализация CSnopokIDZ_2Set

// создаваемый код 7 ноября 2021 г., 19:30

IMPLEMENT_DYNAMIC(CSnopokIDZ_2Set, CRecordset)

CSnopokIDZ_2Set::CSnopokIDZ_2Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_index = 0;
	m_name = L"";
	m_quantity = 0;
	m_price = 0.0;
	m_date;
	m_nFields = 5;
	m_nDefaultType = dynaset;
}
//#error Проблема безопасности: строка подключения может содержать пароль 
// Следующая строка подключения может содержать незашифрованные пароли или 
// другую конфиденциальную информацию. Удалите #error после просмотра строки подключения 
// в целях безопасности. Возможно, 
// потребуется сохранить пароль в другом виде или использовать другую аутентификацию.
CString CSnopokIDZ_2Set::GetDefaultConnect()
{
	return _T("DSN=MS Access Database;DBQ=D:\\\x0412\x0421\x0420\x041f\x041f\\DB_for_IDZ.accdb;DefaultDir=D:\\\x0412\x0421\x0420\x041f\x041f;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CSnopokIDZ_2Set::GetDefaultSQL()
{
	return _T("[Equipment]");
}

void CSnopokIDZ_2Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Такие макросы, как RFX_Text() и RFX_Int(), зависят от типа 
// переменной члена, а не от типа поля в базе данных.
// ODBC выполняет попытку автоматически преобразовать значение столбца к нужному типу
	RFX_Long(pFX, _T("[Код]"), m_index);
	RFX_Text(pFX, _T("[Название]"), m_name);
	RFX_Long(pFX, _T("[Количество]"), m_quantity);
	RFX_Double(pFX, _T("[Цена]"), m_price);
	RFX_Date(pFX, _T("[Дата поступления]"), m_date);

}
/////////////////////////////////////////////////////////////////////////////
// CSnopokIDZ_2Set диагностика

#ifdef _DEBUG
void CSnopokIDZ_2Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CSnopokIDZ_2Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

