#include "Form.h"
#include <tchar.h>

using namespace NobelLib::Graphics;

Form::Form(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPTSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	intCmdShow = nCmdShow;
	szWindowClass = charToTCHAR("Window Class");
	hInst = hInstance;
}

bool Form::Show()
{
	/* Make the window visible on the screen */
	ShowWindow(hWnd, intCmdShow);

	/* Run the message loop. It will run until GetMessage() returns 0 */
	while (GetMessage(&msg, NULL, 0, 0))
	{
		/* Translate virtual-key messages into character messages */
		TranslateMessage(&msg);
		/* Send message to WindowProcedure */
		DispatchMessage(&msg);
	}

	/* The program return-value is 0 - The value that PostQuitMessage() gave */
	return msg.wParam;
}

ATOM Form::MyRegisterClass()
{
	WNDCLASSEX wincl;
	/* The Window structure */
	wincl.hInstance = hInst;
	wincl.lpszClassName = szWindowClass;
	wincl.lpfnWndProc = WndProc;      /* This function is called by windows */
	wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
	wincl.cbSize = sizeof(WNDCLASSEX);

	/* Use default icon and mouse-pointer */
	wincl.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(iconForm));
	wincl.hIconSm = LoadIcon(NULL, MAKEINTRESOURCE(iconForm));
	wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wincl.lpszMenuName = NULL;                 /* No menu */
	wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
	wincl.cbWndExtra = 0;                      /* structure or the window instance */
	/* Use Windows's default color as the background of the window */
	wincl.hbrBackground = (HBRUSH)COLOR_BACKGROUND;

	/* Register the window class, and if it fails quit the program */
	if (!RegisterClassEx(&wincl))
		return 0;
}

bool Form::setForm(char* Title, int heightWnd, int widthWnd, int iconWnd)
{
	szTitle = charToTCHAR(Title);
	heightForm = heightWnd;
	widthForm = widthWnd;
	iconForm = iconWnd;
	MyRegisterClass();

	InitInstance();
	return true;
}

BOOL Form::InitInstance()
{
	/* The class is registered, let's create the program*/
	hWnd = CreateWindowEx(
		0,                   /* Extended possibilites for variation */
		szWindowClass,       /* Classname */
		szTitle,             /* Title Text */
		WS_OVERLAPPEDWINDOW, /* default window */
		CW_USEDEFAULT,       /* Windows decides the position */
		CW_USEDEFAULT,       /* where the window ends up on the screen */
		widthForm,                 /* The programs width */
		widthForm,                 /* and height in pixels */
		HWND_DESKTOP,        /* The window is a child-window to desktop */
		NULL,                /* No menu */
		hInst,               /* Program Instance handler */
		NULL                 /* No Window Creation data */
		);
	return TRUE;
}



//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK Form::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)                  /* handle the messages */
	{
	case WM_DESTROY:
		PostQuitMessage(0);       /* send a WM_QUIT to the message queue */
		break;
	default:                      /* for messages that we don't deal with */
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

TCHAR* Form::charToTCHAR(char* strChar)
{
	int sizeTCHAR = strlen(strChar) + 1;
	TCHAR* newt = new TCHAR[sizeTCHAR];
	for (int i = 0; i < sizeTCHAR; i++)
		newt[i] = _T('\0');

	char * ct = new char[sizeTCHAR];
	for (int i = 0; i < sizeTCHAR; i++)
		ct[i] = '\0';

	mbstowcs((wchar_t *)newt, strChar, sizeTCHAR - 1);
	return newt;
}
char* Form::TCHARToChar(TCHAR* strTCHAR)
{
	int sizeTCHAR = wcslen(strTCHAR) + 1;
	TCHAR* newt = new TCHAR[sizeTCHAR];
	for (int i = 0; i < sizeTCHAR; i++)
		newt[i] = _T('\0');

	char * ct = new char[sizeTCHAR];
	for (int i = 0; i < sizeTCHAR; i++)
		ct[i] = '\0';

	wcstombs(ct, (wchar_t *)strTCHAR, sizeTCHAR - 1);

	return ct;
}