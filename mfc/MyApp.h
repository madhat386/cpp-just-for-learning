#pragma once
#include<afxwin.h>//mfc需要包含的头文件

//应用程序类
class MyApp :public CWinApp {
	//应用程序入口
	BOOL InitInstance() override;
};


//窗口框架类
class MyFrame :public CFrameWnd {
public:
	MyFrame();//窗口构造函数

	//使用消息映射机制，必须使用声明宏（类的声明）和对应的分界宏（实现）
	DECLARE_MESSAGE_MAP()//声明宏

	afx_msg void OnLButtonDown(UINT, CPoint);//鼠标左键按下处理方法声明
	afx_msg void OnChar(UINT, UINT, UINT);//按键按下且抬起前触发的方法声明
	afx_msg void OnPaint();//绘图事件的声明

};

