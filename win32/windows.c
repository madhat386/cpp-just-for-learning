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

	//2.注册窗口类

	//3.创建窗口类

	//4.显示和更新窗口

	//5.通过循环获取各种消息

	//6.处理各种消息（窗口过程）



	return 0;
}