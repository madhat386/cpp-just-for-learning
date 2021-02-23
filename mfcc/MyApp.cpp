#include "MyApp.h"

MyApp app;//应用程序对象，有且仅有一个

BOOL MyApp::InitInstance() {
	//创建窗口
	this->m_pMainWnd = new MyFrame; //保存指向应用程序主窗口的指针
	//显示和更新
	this->m_pMainWnd->ShowWindow(SW_SHOWNORMAL);
	this->m_pMainWnd->UpdateWindow();
	return TRUE;//返回正常初始化
}

//消息映射的分界宏
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)//参数：消息映射的窗口类和其父类
	ON_WM_LBUTTONDOWN() //鼠标左键按下的宏
END_MESSAGE_MAP()


MyFrame::MyFrame() {
	Create(NULL, TEXT("mfc窗口名"));
}

//鼠标左键按下的实现
void MyFrame::OnLButtonDown(UINT nFlags, CPoint point) {
	TCHAR buf[1024];
	wsprintf(buf, TEXT("x=%d,y=%d"), point.x, point.y);
	MessageBox(buf);

}