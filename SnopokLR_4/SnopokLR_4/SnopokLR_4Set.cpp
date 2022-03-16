
// SnopokLR_4Set.cpp : ���������� ������ CSnopokLR_4Set
//

#include "stdafx.h"
#include "SnopokLR_4.h"
#include "SnopokLR_4Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� CSnopokLR_4Set

// ����������� ��� 22 ������� 2021 �., 16:07

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
//#error �������� ������������: ������ ����������� ����� ��������� ������ 
// ��������� ������ ����������� ����� ��������� ��������������� ������ ��� 
// ������ ���������������� ����������. ������� #error ����� ��������� ������ ����������� 
// � ����� ������������. ��������, 
// ����������� ��������� ������ � ������ ���� ��� ������������ ������ ��������������.
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
// ����� �������, ��� RFX_Text() � RFX_Int(), ������� �� ���� 
// ���������� �����, � �� �� ���� ���� � ���� ������.
// ODBC ��������� ������� ������������� ������������� �������� ������� � ������� ����
	RFX_Long(pFX, _T("[���]"), m_index);
	RFX_Text(pFX, _T("[�����]"), m_login);
	RFX_Text(pFX, _T("[������]"), m_password);
	RFX_Long(pFX, _T("[����]"), m_day);
	RFX_Long(pFX, _T("[�����]"), m_month);
	RFX_Long(pFX, _T("[���]"), m_year);
	RFX_Long(pFX, _T("[����]"), m_hour);
	RFX_Long(pFX, _T("[������]"), m_minute);
	RFX_Long(pFX, _T("[������������ ������]"), m_duration);

}
/////////////////////////////////////////////////////////////////////////////
// CSnopokLR_4Set �����������

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

