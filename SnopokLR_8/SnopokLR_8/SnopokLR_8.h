
// SnopokLR_8.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CSnopokLR_8App:
// � ���������� ������� ������ ��. SnopokLR_8.cpp
//

class CSnopokLR_8App : public CWinApp
{
public:
	CSnopokLR_8App();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CSnopokLR_8App theApp;