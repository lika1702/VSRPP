
// SnopokLR_4Set.h: ��������� ������ CSnopokLR_4Set
//


#pragma once

// ����������� ��� 22 ������� 2021 �., 16:07

class CSnopokLR_4Set : public CRecordset
{
public:
	CSnopokLR_4Set(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CSnopokLR_4Set)

// ������ ����� � ����������

// ��������� ���� ����� (���� ������������) �������� ����������� ���� ������ 
// ���� ���� ������ - CStringA ��� ����� ������ ANSI � CStringW ��� ����� 
// ������ �������. ��� ������ ������������� ���������� ��������� ODBC 
// ������������ �������� ��������������.  ��� ������� ����� �������� ��� ����� �� 
// ���� CString, � ������� ODBC �������� ��� ����������� ��������������.
// (����������. ���������� ������������ ������� ODBC ������ 3.5 ��� ����� ������� 
// ��� ��������� ��� �������, ��� � ���� ��������������).

	long	m_index;
	CString	m_login;
	CString	m_password;
	long	m_day;
	long	m_month;
	long	m_year;
	long	m_hour;
	long	m_minute;
	long	m_duration;

// ���������������
	// ������ ������ ��������������� ����������� �������
	public:
	virtual CString GetDefaultConnect();	// ������ ����������� �� ���������

	virtual CString GetDefaultSQL(); 	// ��� SQL �� ��������� ��� ������ �������
	virtual void DoFieldExchange(CFieldExchange* pFX);	// ��������� RFX

// ����������
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

