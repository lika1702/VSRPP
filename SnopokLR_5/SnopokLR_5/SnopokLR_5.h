
// SnopokLR_5.h : ������� ���� ��������� ��� ���������� SnopokLR_5
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CSnopokLR_5App:
// � ���������� ������� ������ ��. SnopokLR_5.cpp
//

class CSnopokLR_5App : public CWinAppEx
{
public:
	CSnopokLR_5App();


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

extern CSnopokLR_5App theApp;
