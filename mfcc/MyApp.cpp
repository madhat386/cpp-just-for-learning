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
	ON_WM_CHAR() //���̰��µĺ�
	ON_WM_PAINT() //��ͼ�ĺ�
END_MESSAGE_MAP()


MyFrame::MyFrame() {
	Create(NULL, TEXT("mfc������"));
}

//���������µ�ʵ��
void MyFrame::OnLButtonDown(UINT nFlags, CPoint point) {
	//TCHAR buf[1024];
	//wsprintf(buf, TEXT("x=%d,y=%d"), point.x, point.y);
	//MessageBox(buf);
	CString str;//MFC��ʹ�õ��ַ���
	//��ʽ���ַ���
	str.Format(TEXT("x=%d,y=%d"), point.x, point.y);
	MessageBox(str);

}

//����������̧��ǰ�����ķ���ʵ��
void MyFrame::OnChar(UINT key, UINT, UINT) {
	CString str;
	str.Format(TEXT("������%C��"), key);
	MessageBox(str);
}

//��ͼ�¼���ʵ��
void MyFrame::OnPaint() {
	CPaintDC dc(this);//dc�൱�ڻ��ң�this�ǻ��Ƶ����ڴ���
	dc.TextOutW(100, 100, TEXT("Hello world"));//��������
	dc.Ellipse(10, 10, 100, 100);//���ݾ��Σ��Խ��ߵ������㣩��������Բ
}
