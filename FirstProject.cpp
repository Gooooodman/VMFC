#include<windows.h>
//MB_  MessageBox  
int WINAPI WinMain(HINSTANCE hInstance,  //句柄
	HINSTANCE hPrevInstance,             //显示内容
	LPSTR     lpCmdLine,                 //标题
	int       nCmdShow)                  //MB_ABORTRETRYIGNORE 2
	                                     //MB_OKCANCEL  1
	                                     //MB_RETRYCANCEL  5
	                                     //MB_YESNO 4
	                                     //MB_YESNOCANCEL 3
	                                     //MB_OK   0
//MB_OKCANCEL|MB_ICONHAND  可以是图标与按钮的组合  按钮可以为数字
//MB_ICONHAND 10（16）  MB_ICONQUESTION 20（32） 
//MB_ICONEXCLAMATION 30（64） MB_ICONASTERISK 40（128）

//#define IDOK           1
//#define IDCANCEL       2
//#define IDABORY        3
//#define IDRETRY        4
//#define IDIGNORE       5
//#define IDYES          6
//#define IDNO           7

{
	int nRet= MessageBox(NULL,"这是第一个windows程序","温馨提示：",
		MB_OKCANCEL| 16);
	if (nRet == IDOK)
		MessageBox(NULL, "你点击了确定按钮", "返回值", 0);
    if(nRet==2)
		MessageBox(NULL, "你点击了取消按钮", "返回值", 0);
	return 0;
}
