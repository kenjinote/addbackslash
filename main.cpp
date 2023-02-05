#define UNICODE
#pragma comment(lib,"shlwapi")
#pragma comment(linker,"/opt:nowin98")
#include<shlwapi.h>
TCHAR szClassName[]=TEXT("Window");

LRESULT CALLBACK WndProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	static HWND hEidt,hStatic;
	switch(msg)
	{
	case WM_CREATE:
		hEidt=CreateWindowEx(WS_EX_CLIENTEDGE,TEXT("EDIT"),TEXT("C:\\WINDOWS"),WS_VISIBLE|WS_CHILD,10,10,512,30,hWnd,(HMENU)100,((LPCREATESTRUCT)lParam)->hInstance,0);
		hStatic=CreateWindow(TEXT("STATIC"),0,WS_VISIBLE|WS_CHILD,10,50,512,30,hWnd,0,((LPCREATESTRUCT)lParam)->hInstance,0);
		CreateWindow(TEXT("BUTTON"),TEXT("u\\v•t‰Á"),WS_VISIBLE|WS_CHILD,512+20,10,128,30,hWnd,(HMENU)101,((LPCREATESTRUCT)lParam)->hInstance,0);
		break;
	case WM_COMMAND:
		if(LOWORD(wParam)==101)
		{
			TCHAR szFilePath[MAX_PATH];
			GetWindowText(hEidt,szFilePath,MAX_PATH);
			PathAddBackslash(szFilePath);
			SetWindowText(hStatic,szFilePath);
		}
		else if(LOWORD(wParam)==100 && HIWORD(wParam)==EN_CHANGE)
		{
			SetWindowText(hStatic,0);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd,msg,wParam,lParam);
	}
	return 0;
}

EXTERN_C void __cdecl WinMainCRTStartup()
{
	MSG msg;
	HINSTANCE hInstance=GetModuleHandle(0);
	WNDCLASS wndclass={CS_HREDRAW|CS_VREDRAW,WndProc,0,0,hInstance,0,LoadCursor(0,IDC_ARROW),(HBRUSH)(COLOR_WINDOW+1),0,szClassName};
	RegisterClass(&wndclass);
	HWND hWnd=CreateWindow(szClassName,TEXT("Window"),WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,0,CW_USEDEFAULT,0,0,0,hInstance,0);
	ShowWindow(hWnd,SW_SHOWDEFAULT);
	UpdateWindow(hWnd);
	while(GetMessage(&msg,0,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	ExitProcess(0);
}

#if _DEBUG
void main(){}
#endif