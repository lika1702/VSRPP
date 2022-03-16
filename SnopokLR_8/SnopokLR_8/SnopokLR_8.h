
// SnopokLR_8.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CSnopokLR_8App:
// О реализации данного класса см. SnopokLR_8.cpp
//

class CSnopokLR_8App : public CWinApp
{
public:
	CSnopokLR_8App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CSnopokLR_8App theApp;