
// SnopokIDZ_2.h : главный файл заголовка для приложения SnopokIDZ_2
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CSnopokIDZ_2App:
// О реализации данного класса см. SnopokIDZ_2.cpp
//

class CSnopokIDZ_2App : public CWinAppEx
{
public:
	CSnopokIDZ_2App();


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

extern CSnopokIDZ_2App theApp;
