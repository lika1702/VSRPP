
// SnopokIDZ_2Set.cpp : ���������� ������ CSnopokIDZ_2Set
//

#include "stdafx.h"
#include "SnopokIDZ_2.h"
#include "SnopokIDZ_2Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� CSnopokIDZ_2Set

// ����������� ��� 7 ������ 2021 �., 19:30

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
//#error �������� ������������: ������ ����������� ����� ��������� ������ 
// ��������� ������ ����������� ����� ��������� ��������������� ������ ��� 
// ������ ���������������� ����������. ������� #error ����� ��������� ������ ����������� 
// � ����� ������������. ��������, 
// ����������� ��������� ������ � ������ ���� ��� ������������ ������ ��������������.
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
// ����� �������, ��� RFX_Text() � RFX_Int(), ������� �� ���� 
// ���������� �����, � �� �� ���� ���� � ���� ������.
// ODBC ��������� ������� ������������� ������������� �������� ������� � ������� ����
	RFX_Long(pFX, _T("[���]"), m_index);
	RFX_Text(pFX, _T("[��������]"), m_name);
	RFX_Long(pFX, _T("[����������]"), m_quantity);
	RFX_Double(pFX, _T("[����]"), m_price);
	RFX_Date(pFX, _T("[���� �����������]"), m_date);

}
/////////////////////////////////////////////////////////////////////////////
// CSnopokIDZ_2Set �����������

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

