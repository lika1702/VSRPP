
// Snopok_Test.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CSnopok_TestApp:
// � ���������� ������� ������ ��. Snopok_Test.cpp
//

class CSnopok_TestApp : public CWinApp
{
public:
	CSnopok_TestApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CSnopok_TestApp theApp;