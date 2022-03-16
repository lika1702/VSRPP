
// SnopokIDZ_2Set.h: ��������� ������ CSnopokIDZ_2Set
//


#pragma once

// ����������� ��� 7 ������ 2021 �., 19:30

class CSnopokIDZ_2Set : public CRecordset
{
public:
	CSnopokIDZ_2Set(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CSnopokIDZ_2Set)

// ������ ����� � ����������

// ��������� ���� ����� (���� ������������) �������� ����������� ���� ������ 
// ���� ���� ������ - CStringA ��� ����� ������ ANSI � CStringW ��� ����� 
// ������ �������. ��� ������ ������������� ���������� ��������� ODBC 
// ������������ �������� ��������������.  ��� ������� ����� �������� ��� ����� �� 
// ���� CString, � ������� ODBC �������� ��� ����������� ��������������.
// (����������. ���������� ������������ ������� ODBC ������ 3.5 ��� ����� ������� 
// ��� ��������� ��� �������, ��� � ���� ��������������).

	long	m_index;
	CString	m_name;
	long	m_quantity;
	double	m_price;
	CTime	m_date;

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

