#include "MyApp.h"

MyApp app;//Ӧ�ó���������ҽ���һ��

BOOL MyApp::InitInstance() {
	//��������
	this->m_pMainWnd = new MyFrame; //����ָ��Ӧ�ó��������ڵ�ָ��
	//��ʾ�͸���
	this->m_pMainWnd->ShowWindow(SW_SHOWNORMAL);
	this->m_pMainWnd->UpdateWindow();
	return TRUE;//����������ʼ��
}

//��Ϣӳ��ķֽ��
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)//��������Ϣӳ��Ĵ�������丸��
	ON_WM_LBUTTONDOWN() //���������µĺ�
END_MESSAGE_MAP()


MyFrame::MyFrame() {
	Create(NULL, TEXT("mfc������"));
}

//���������µ�ʵ��
void MyFrame::OnLButtonDown(UINT nFlags, CPoint point) {
	TCHAR buf[1024];
	wsprintf(buf, TEXT("x=%d,y=%d"), point.x, point.y);
	MessageBox(buf);

}