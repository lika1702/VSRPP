
// SnopokLR_4.h : ������� ���� ��������� ��� ���������� SnopokLR_4
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CSnopokLR_4App:
// � ���������� ������� ������ ��. SnopokLR_4.cpp
//

class CSnopokLR_4App : public CWinAppEx
{
public:
	CSnopokLR_4App();


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

extern CSnopokLR_4App theApp;
