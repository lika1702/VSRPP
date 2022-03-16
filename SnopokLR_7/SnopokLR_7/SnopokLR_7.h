
// SnopokLR_7.h : главный файл заголовка для приложения SnopokLR_7
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CSnopokLR_7App:
// О реализации данного класса см. SnopokLR_7.cpp
//

class CSnopokLR_7App : public CWinAppEx
{
public:
	CSnopokLR_7App();


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

extern CSnopokLR_7App theApp;
