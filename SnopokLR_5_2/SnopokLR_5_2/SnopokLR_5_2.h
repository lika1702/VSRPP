
// SnopokLR_5_2.h : ������� ���� ��������� ��� ���������� SnopokLR_5_2
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CSnopokLR_5_2App:
// � ���������� ������� ������ ��. SnopokLR_5_2.cpp
//

class CSnopokLR_5_2App : public CWinAppEx
{
public:
	CSnopokLR_5_2App();


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

extern CSnopokLR_5_2App theApp;
