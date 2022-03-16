
// SnopokLR_5_2.h : главный файл заголовка для приложения SnopokLR_5_2
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CSnopokLR_5_2App:
// О реализации данного класса см. SnopokLR_5_2.cpp
//

class CSnopokLR_5_2App : public CWinAppEx
{
public:
	CSnopokLR_5_2App();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSnopokLR_5_2App theApp;
