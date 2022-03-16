
// SnopokLR_4.h : главный файл заголовка для приложения SnopokLR_4
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CSnopokLR_4App:
// О реализации данного класса см. SnopokLR_4.cpp
//

class CSnopokLR_4App : public CWinAppEx
{
public:
	CSnopokLR_4App();


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

extern CSnopokLR_4App theApp;
