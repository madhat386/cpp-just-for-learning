#include <windows.h>

//6.���������Ϣ���������ڹ��̣�
LRESULT CALLBACK WindowProc(//CALLBACK��������__stdcall,ָ�������ݵ�˳��Ϊ�����������ε���ջ�������ں�������ǰ���Զ����ջ
	HWND hwnd,//��Ϣ�����Ĵ��ھ��
	UINT uMsg,//������Ϣ����
	WPARAM wParam,//���̸�����Ϣ
	LPARAM lParam //��긽����Ϣ
) {
	switch (uMsg) {
	case WM_CLOSE://����رմ��ڲ����¼�
		DestroyWindow(hwnd);//���ٴ��ڣ�����δ�������̣�DestroyWindow�ᴥ����һ����Ϣ������WM_DESTROY��
		break;
	case WM_DESTROY://���������˵���Ϣ
		PostQuitMessage(0);//�������������0�ᴫ�ݸ�WinMain������Ϊѭ������������
		break;
	case WM_LBUTTONDOWN://���������µ���Ϣ

		break;
	}

	//Ĭ�ϵĴ��ڴ�����
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}



//WINAPI��������__stdcall,ָ�������ݵ�˳��Ϊ�����������ε���ջ�������ں�������ǰ���Զ����ջ
int WINAPI WinMain(
	_In_ HINSTANCE hInstance, //Ӧ�ó����ʵ�����
	_In_opt_ HINSTANCE hPrevInstance, //ǰһ��Ӧ�ó����ʵ���������win32�����»���Ϊnull
	_In_ LPSTR lpCmdLine, //����char *argv[]�����в�������
	_In_ int nShowCmd //���ڵ���ʾ�����������󻯣���С���ȵȣ�
) {

	//ʵ�ֵײ�Ĵ�����6��
	//1.��ƴ�����
	WNDCLASS windowClass;
	windowClass.cbClsExtra = 0;//�����������ڴ棬ͨ��Ϊ0
	windowClass.cbWndExtra = 0;//���ڶ�����ڴ棬ͨ��Ϊ0
	windowClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//���ñ�����������msdn
	windowClass.hCursor = LoadCursor(NULL, IDC_HAND);//���ù��,��һ������Ϊnull������ʹ��ϵͳ��Ĭ�Ϲ��
	windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);//����ͼ��,��һ������Ϊnull������ʹ��ϵͳ��ͼ��
	windowClass.hInstance = hInstance;//��ǰ��ʵ�����,ʹ��winmain�����еĲ�������
	windowClass.lpfnWndProc = WindowProc;//��ָ���ڹ��̺������ص�����,�����Զ������������
	windowClass.lpszClassName = TEXT("MYWINDOW");//ָ����������
	windowClass.lpszMenuName = NULL;//�˵����ƣ�û����null
	windowClass.style = 0;//0����Ĭ��

	//2.ע�ᴰ����
	RegisterClass(&windowClass);

	//3.��������
	/*
		����:
		lpClassName ����
		lpWindowName ������
		dwStyle ��ʾ���
		x��y  ��������
		nWidth��nHeight ���ڵĿ��
		hWndParent �����ڣ�û��дnull
		hMenu �˵���û��дnull
		hInstance ʵ�������ʹ�ô������Ĳ���
		lpParam ����������û��дnull
	*/
	HWND hwnd = CreateWindow(windowClass.lpszClassName,
		TEXT("TEXT WINDOW"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	//4.��ʾ�͸��´���
	ShowWindow(hwnd, SW_NORMAL);//�ڶ���������ʾ������ʾ

	//5.ͨ��ѭ����ȡ������Ϣ
	UpdateWindow(hwnd);
	/*
	 MSG�ṹ���ڲ�����
	 struct {
		HWND    ;hwnd ������
		UINT    ;message ��Ϣ���� WM_XXXX (WINDOW MESSAGE)
		WPARAM  ;wParam  ������Ϣ������
		LPARAM  ;lParam  ������Ϣ��������Ҽ�
		DWORD   ;time    ��Ϣ����ʱ��
		POINT   ;pt      ������Ϣ�����������Ϣ
	}
	 */
	MSG msg;
	while (1) {
		/*
			��һ��������Ϣ�ṹ��
			�ڶ������������Ĵ��ڣ�NULL���������д��ڵ���Ϣ
			������������������С��Ϣ����
			���ĸ�����������������Ϣ����(������С�����д0��������������Ϣ)

		 */

		 //�����ȡ������flase,˵�������ϵ���˹رհ�ť
		if (GetMessage(&msg, NULL, 0, 0) == FALSE) {
			break;
		}

		//������Ϣ(�罫��ϵİ�������ɶ�Ӧ����Ϣ)
		TranslateMessage(&msg);

		//�ַ���Ϣ
		DispatchMessage(&msg);
	}

	return 0;
}