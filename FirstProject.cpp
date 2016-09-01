#include<windows.h>
//MB_  MessageBox
int WINAPI WinMain(HINSTANCE hInstance,  //句柄
	HINSTANCE hPrevInstance,             //显示内容
	LPSTR     lpCmdLine,                 //标题
	int       nCmdShow)                  //MB_ABORTRETRYIGNORE  2
	                                     //MB_OKCANCEL  1
	                                     //MB_RETRYCANCEL   5
	                                     //MB_YESNO   4
	                                     //MB_YESNOCANCEL   3
	                                     //MB_OK   或者 0
//MB_OKCANCEL|MB_ICONHAND  可以是图标与按钮的组合  按钮可以为数字
//MB_ICONHAND 10  MB_ICONQUESTION 20 MB_ICONEXCLAMATION 30 MB_ICONASTERISK 40
{
	MessageBox(NULL,"这是第一个windows程序","温馨提示：",MB_OKCANCEL|MB_ICONHAND);
	return 0;
}
