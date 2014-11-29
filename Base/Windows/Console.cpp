#include "Console.h"

using namespace NobelLib::Sys::Windows;
#define m_pszClassName "MyClass"
NWindow::NWindow()
{

}

LRESULT CALLBACK NWindow::WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	switch (uMsg) {

	case WM_NCCREATE: {
						  CREATESTRUCT * pcs = (CREATESTRUCT*)lParam;
						  NWindow* WND = (NWindow*)pcs->lpCreateParams;
						  WND->hwnd = hwnd;
						  SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG)pcs->lpCreateParams);
						  return TRUE;
	}

	case WM_DESTROY: {
						 NWindow* Window = (NWindow*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
						 if (Window) Window->hwnd = 0;
						 break;
	}

	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);

	}

	return 0;

}

NWindow* NWindow::Create(HINSTANCE hInst)
{
	WNDCLASS wincl;
	if (!GetClassInfo(hInst, (LPCWSTR)m_pszClassName, &wincl)) {
		wincl.style = 0;
		wincl.hInstance = hInst;
		wincl.lpszClassName = (LPCWSTR)m_pszClassName;
		wincl.cbClsExtra = 0;
		wincl.cbWndExtra = 0;
		wincl.hIcon = NULL;
		wincl.hCursor = NULL;
		wincl.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
		wincl.lpszMenuName = NULL;
		if (RegisterClass(&wincl) == 0) {
			MessageBox(NULL, (LPCWSTR) "The window class failed to register.", (LPCWSTR) "Error", 0);
			return 0;
		}
	}

	NWindow * Wnd = new NWindow;
	HWND hWnd = CreateWindow((LPCWSTR)m_pszClassName, (LPCWSTR)"Test", WS_VISIBLE | WS_OVERLAPPED, 50, 50, 200, 200, NULL, NULL, hInst, Wnd);
	if (hWnd == NULL) {
		delete Wnd;
		MessageBox(NULL, (LPCWSTR)"Problem creating the window.", (LPCWSTR)"Error", 0);
		return 0;
	}

	return Wnd;
}

void NWindow::Show()
{
	ShowWindow(hwnd, 10);
}

void CALLBACK NWindow::MsgRouter(HWND hwnd, UINT message,
	WPARAM wparam, LPARAM lparam)
{
	NWindow* wnd = nullptr;

	// retrieve associated Window instance
	wnd = reinterpret_cast<NWindow*>(::GetWindowLong(hwnd, GWL_USERDATA));

	// call the windows message handler
	wnd->WndProc(hwnd,message, wparam, lparam);
}