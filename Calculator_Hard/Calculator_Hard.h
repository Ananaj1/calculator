
// Calculator_Hard.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CCalculatorHardApp:
// Сведения о реализации этого класса: Calculator_Hard.cpp
//

class CCalculatorHardApp : public CWinApp
{
public:
	CCalculatorHardApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CCalculatorHardApp theApp;
