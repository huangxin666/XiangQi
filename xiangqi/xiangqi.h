
// xiangqi.h : xiangqi Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CXiangQiApp:
// �йش����ʵ�֣������ xiangqi.cpp
//

class CXiangQiApp : public CWinApp
{
public:
	CXiangQiApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CXiangQiApp theApp;
