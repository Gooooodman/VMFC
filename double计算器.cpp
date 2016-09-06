#include <Windows.h>
#include<stdio.h>
#include "resource.h"
#define _CRT_SECURE_NO_WARNINGS
//hInstance：资源总管
double GetDlgItemDouble(HWND hwnd, UINT nID)
{
	char s[256];
	GetDlgItemText(hwnd,nID,s,sizeof(s));
	return atof(s);  //将字符串转换为浮点数
}
//由字符串转化为整数：atoi   转化为浮点数：atof
//由整数转化为字符串：itoa   浮点数转化为字符串   没有函数（ftoa）
//sprintf各种类型的数字转化为字符串：格式化函数
void SetDlgItemDouble(HWND hwnd, UINT nID,double db)
{
	char s[256];
	sprintf(s,"%lf",db);
	SetDlgItemText(hwnd, nID, s);
	
}

INT_PTR CALLBACK theProc(HWND   hwndDlg, UINT   uMsg, WPARAM wParam, LPARAM lParam)
{//消息回调函数
	switch (uMsg)
	{
	case WM_COMMAND:                      //判断消息类型
		if (LOWORD(wParam) == IDOK)       //判断单击的按钮
		{
			double nLeft = GetDlgItemDouble(hwndDlg, IDC_LEFT1);
			double nRight = GetDlgItemDouble(hwndDlg, IDC_RIGHT1);
			SetDlgItemDouble(hwndDlg,IDC_RESULT1,nLeft + nRight);

			 nLeft = GetDlgItemDouble(hwndDlg, IDC_LEFT2);
             nRight = GetDlgItemDouble(hwndDlg, IDC_RIGHT2);
			SetDlgItemDouble(hwndDlg, IDC_RESULT2, nLeft - nRight);

			 nLeft = GetDlgItemDouble(hwndDlg, IDC_LEFT6);
			 nRight = GetDlgItemDouble(hwndDlg, IDC_RIGHT6);
			SetDlgItemDouble(hwndDlg, IDC_RESULT6, nLeft * nRight);

			 nLeft = GetDlgItemDouble(hwndDlg, IDC_LEFT7);
			nRight = GetDlgItemDouble(hwndDlg, IDC_RIGHT7);
			if (nRight != 0)
				SetDlgItemDouble(hwndDlg, IDC_RESULT7, nLeft / nRight);
			else
				SetDlgItemText(hwndDlg,IDC_RESULT7, "除数不能为0");

			 /*nLeft = GetDlgItemDouble(hwndDlg, IDC_LEFT8);
			 nRight = GetDlgItemDouble(hwndDlg, IDC_RIGHT8);
			SetDlgItemDouble(hwndDlg, IDC_RESULT8, nLeft % nRight);*/

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