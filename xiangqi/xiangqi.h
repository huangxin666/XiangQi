
// xiangqi.h : xiangqi 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CXiangQiApp:
// 有关此类的实现，请参阅 xiangqi.cpp
//

class CXiangQiApp : public CWinApp
{
public:
	CXiangQiApp();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CXiangQiApp theApp;
