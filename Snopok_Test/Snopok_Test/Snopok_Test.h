
// Snopok_Test.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CSnopok_TestApp:
// О реализации данного класса см. Snopok_Test.cpp
//

class CSnopok_TestApp : public CWinApp
{
public:
	CSnopok_TestApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CSnopok_TestApp theApp;