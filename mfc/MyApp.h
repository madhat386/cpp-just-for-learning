#pragma once
#include<afxwin.h>//mfc��Ҫ������ͷ�ļ�

//Ӧ�ó�����
class MyApp :public CWinApp {
	//Ӧ�ó������
	BOOL InitInstance() override;
};


//���ڿ����
class MyFrame :public CFrameWnd {
public:
	MyFrame();//���ڹ��캯��

	//ʹ����Ϣӳ����ƣ�����ʹ�������꣨����������Ͷ�Ӧ�ķֽ�꣨ʵ�֣�
	DECLARE_MESSAGE_MAP()//������

	afx_msg void OnLButtonDown(UINT, CPoint);//���������´���������
	afx_msg void OnChar(UINT, UINT, UINT);//����������̧��ǰ�����ķ�������
	afx_msg void OnPaint();//��ͼ�¼�������

};

