#include <windows.h>

//WINAPI这个宏代表__stdcall,指参数传递的顺序为从右往左，依次的入栈，并且在函数返回前会自动清空栈
int WINAPI WinMain(
	_In_ HINSTANCE hInstance, //应用程序的实例句柄
	_In_opt_ HINSTANCE hPrevInstance, //前一个应用程序的实例句柄，在win32环境下基本为null
	_In_ LPSTR lpCmdLine, //等于char *argv[]命令行参数数组
	_In_ int nShowCmd //窗口的显示命令（正常，最大化，最小化等等）
) {

	//实现底层的窗口有6步
	//1.设计窗口类
	WNDCLASS windowClass;
	windowClass.cbClsExtra = 0;//窗口类额外的内存，通常为0
	windowClass.cbWndExtra = 0;//窗口额外的内存，通常为0
	windowClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//设置背景，参数查msdn
	windowClass.hCursor = LoadCursor(NULL, IDC_HAND);//设置光标,第一个参数为null，代表使用系统的默认光标
	windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);//设置图标,第一个参数为null，代表使用系统的图标
	windowClass.hInstance = hInstance;//当前的实例句柄,使用winmain函数中的参数即可
	//windowClass.lpfnWndProc = WindowProc;//是指窗口过程函数，回调函数,函数自定，名字随便起
	windowClass.lpszClassName = TEXT("MYWINDOW");//指定窗口类名
	windowClass.lpszMenuName = NULL;//菜单名称，没有填null
	windowClass.style = 0;//0代表默认

	//2.注册窗口类
	RegisterClass(&windowClass);

	//3.创建窗口
	/*
		参数:
		lpClassName 类名
		lpWindowName 窗口名
		dwStyle 显示风格
		x，y  窗口坐标
		nWidth，nHeight 窗口的宽高
		hWndParent 父窗口，没有写null
		hMenu 菜单，没有写null
		hInstance 实例句柄，使用传进来的参数
		lpParam 其他参数，没有写null
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

	//4.显示和更新窗口
	ShowWindow(hwnd, SW_NORMAL);//第二个参数表示正常显示

	//5.通过循环获取各种消息
	UpdateWindow(hwnd);
	/*
	 MSG结构体内部数据
	 struct {
		HWND    ;hwnd 主窗口
		UINT    ;message 消息名称 WM_XXXX (WINDOW MESSAGE)
		WPARAM  ;wParam  附加消息，键盘
		LPARAM  ;lParam  附加消息，鼠标左右键
		DWORD   ;time    消息产生时间
		POINT   ;pt      附加消息，鼠标坐标消息
	}
	 */
	MSG msg;
	while (1) {
		/*
			第一个参数消息结构体
			第二个参数不过的窗口，NULL代表捕获所有窗口的消息
			第三个参数，过滤最小消息数量
			第四个参数，过滤最大的消息数量(过滤最小和最大都写0，代表捕获所有消息)

		 */

		 //如果获取到的是flase,说明窗口上点击了关闭按钮
		if (GetMessage(&msg, NULL, 0, 0) == FALSE) {
			break;
		}

		//翻译消息(如将组合的按键翻译成对应的消息)
		TranslateMessage(&msg);

		//分发消息
		DispatchMessage(&msg);

		//6.处理各种消息（窗口过程）
	}

	return 0;
}