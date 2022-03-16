
// SnopokLR_5.h : главный файл заголовка для приложения SnopokLR_5
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CSnopokLR_5App:
// О реализации данного класса см. SnopokLR_5.cpp
//

class CSnopokLR_5App : public CWinAppEx
{
public:
	CSnopokLR_5App();


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

extern CSnopokLR_5App theApp;
