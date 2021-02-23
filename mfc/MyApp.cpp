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
	ON_WM_CHAR() //键盘按下的宏
	ON_WM_PAINT() //绘图的宏
END_MESSAGE_MAP()


MyFrame::MyFrame() {
	Create(NULL, TEXT("mfc窗口名"));
}

//鼠标左键按下的实现
void MyFrame::OnLButtonDown(UINT nFlags, CPoint point) {
	//TCHAR buf[1024];
	//wsprintf(buf, TEXT("x=%d,y=%d"), point.x, point.y);
	//MessageBox(buf);
	CString str;//MFC中使用的字符串
	//格式化字符串
	str.Format(TEXT("x=%d,y=%d"), point.x, point.y);
	MessageBox(str);

}

//按键按下且抬起前触发的方法实现
void MyFrame::OnChar(UINT key, UINT, UINT) {
	CString str;
	str.Format(TEXT("按下了%C键"), key);
	MessageBox(str);
}

//绘图事件的实现
void MyFrame::OnPaint() {
	CPaintDC dc(this);//dc相当于画家，this是绘制的所在窗口
	dc.TextOutW(100, 100, TEXT("Hello world"));//绘制文字
	dc.Ellipse(10, 10, 100, 100);//根据矩形（对角线的两个点）绘制内切圆
}
