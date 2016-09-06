#include <Windows.h>
#include "resource.h"
//hInstance：资源总管
INT_PTR CALLBACK theProc(HWND   hwndDlg, UINT   uMsg, WPARAM wParam, LPARAM lParam)
{//消息回调函数
	switch (uMsg)
	{
	case WM_COMMAND:                      //判断消息类型
		if (LOWORD(wParam) == IDOK)       //判断单击的按钮
		{
			int nLeft = GetDlgItemInt(hwndDlg, IDC_LEFT1,NULL,TRUE);
			int nRight = GetDlgItemInt(hwndDlg, IDC_RIGHT1, NULL, TRUE);
			SetDlgItemInt(hwndDlg,IDC_RESULT1,nLeft + nRight,TRUE);

			 nLeft = GetDlgItemInt(hwndDlg, IDC_LEFT2, NULL, TRUE);
             nRight = GetDlgItemInt(hwndDlg, IDC_RIGHT2, NULL, TRUE);
			SetDlgItemInt(hwndDlg, IDC_RESULT2, nLeft - nRight, TRUE);

			 nLeft = GetDlgItemInt(hwndDlg, IDC_LEFT6, NULL, TRUE);
			 nRight = GetDlgItemInt(hwndDlg, IDC_RIGHT6, NULL, TRUE);
			SetDlgItemInt(hwndDlg, IDC_RESULT6, nLeft * nRight, TRUE);

			 nLeft = GetDlgItemInt(hwndDlg, IDC_LEFT7, NULL, TRUE);
			nRight = GetDlgItemInt(hwndDlg, IDC_RIGHT7, NULL, TRUE);
			if (nRight != 0)
				SetDlgItemInt(hwndDlg, IDC_RESULT7, nLeft / nRight, TRUE);
			else
				SetDlgItemText(hwndDlg,IDC_RESULT7, "除数不能为0");

			 nLeft = GetDlgItemInt(hwndDlg, IDC_LEFT8, NULL, TRUE);
			 nRight = GetDlgItemInt(hwndDlg, IDC_RIGHT8, NULL, TRUE);
			SetDlgItemInt(hwndDlg, IDC_RESULT8, nLeft % nRight, TRUE);

			return TRUE;    //处理好的返回TRUE
		}
		if (LOWORD(wParam) == IDCANCEL)   //判断单击的按钮
		{
			EndDialog(hwndDlg,IDCANCEL);  
			return TRUE;    //处理好的返回TRUE
		}
		if (LOWORD(wParam) == ID_EXIT)
		{
			EndDialog(hwndDlg, IDCANCEL);
			return TRUE;    //处理好的返回TRUE
		}
		break;
	}
	return FALSE; //FALSE代表缺省的处理由系统完成
}

int WINAPI WinMain(HINSTANCE hInstance,
	               HINSTANCE hPrev,
	               LPSTR     lpCmd,
	               int       nCmdShow)
{
	DialogBox(hInstance,(LPCTSTR)IDD_MAIN_DLG,NULL,theProc);//theProc 回调函数名
	return 0;
}