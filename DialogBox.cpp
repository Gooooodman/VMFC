#include "resource.h"
#include <Windows.h>

//hInstance：资源总管
INT_PTR CALLBACK theProc(HWND   hwndDlg, UINT   uMsg, WPARAM wParam, LPARAM lParam)
{//消息回调函数
	switch (uMsg)
	{
	case WM_COMMAND:                      //判断消息类型
		if (LOWORD(wParam) == IDOK)       //判断单击的按钮
		{
			int nLeft = GetDlgItemInt(hwndDlg, IDC_LEFT,NULL,TRUE);
			int nRight = GetDlgItemInt(hwndDlg, IDC_RIGHT, NULL, TRUE);
			SetDlgItemInt(hwndDlg,IDC_RESULT,nLeft+nRight,TRUE);
		}
		if (LOWORD(wParam) == IDCANCEL)   //判断单击的按钮
		{
			EndDialog(hwndDlg,IDCANCEL);
		}
		break;
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance,
	               HINSTANCE hPrev,
	               LPSTR     lpCmd,
	               int       nCmdShow)
{

	DialogBox(hInstance,(LPCTSTR)IDD_MAIN_DLG,NULL,theProc);//theProc 回调函数名
	return 0;

}