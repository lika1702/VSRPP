
// SnopokLR_7.h : ������� ���� ��������� ��� ���������� SnopokLR_7
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CSnopokLR_7App:
// � ���������� ������� ������ ��. SnopokLR_7.cpp
//

class CSnopokLR_7App : public CWinAppEx
{
public:
	CSnopokLR_7App();


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

extern CSnopokLR_7App theApp;
