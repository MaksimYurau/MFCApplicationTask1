
// MFCApplicationTask1.h: основной файл заголовка для приложения MFCApplicationTask1
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CMFCApplicationTask1App:
// Сведения о реализации этого класса: MFCApplicationTask1.cpp
//

class CMFCApplicationTask1App : public CWinAppEx
{
public:
	CMFCApplicationTask1App() noexcept;


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

extern CMFCApplicationTask1App theApp;
