
// SnopokIDZ_2.h : ������� ���� ��������� ��� ���������� SnopokIDZ_2
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CSnopokIDZ_2App:
// � ���������� ������� ������ ��. SnopokIDZ_2.cpp
//

class CSnopokIDZ_2App : public CWinAppEx
{
public:
	CSnopokIDZ_2App();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSnopokIDZ_2App theApp;
