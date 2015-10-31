#include "Form.h"
#include <Uxtheme.h>
#include <GL\glew.h>
#include "..\Base\NString.h"

using namespace NobelLib::Graphics;
using namespace NobelLib;

bool Form::form_bExit;
bool Form::pro_bQuit;
bool Form::pro_bActive;
bool Form::pro_bCreate;
bool Form::pro_bInput;
bool Form::pro_bMouseMove;
bool Form::pro_bTimer;
void(*Form::pro_Quit)();
void(*Form::pro_Active)();
void(*Form::pro_Create)();
void(*Form::pro_Input)();
void(*Form::pro_MouseMove)();
void(*Form::pro_Timer)();
MSG Form::msg;

Form::Form()
{
	hDC = NULL;
	hRC = NULL;
	hWnd = NULL;
}

Form::~Form()
{
	destroyWindow();
}

void Form::destroyWindow()
{
	if (scr_iMode == 0)
	{
		ChangeDisplaySettings(NULL, 0);
		ShowCursor(true);
	}

	destroyGL();
	if (hDC)
	{
		ReleaseDC(hWnd, hDC);
		hDC = NULL;
	}

	if (hWnd)
	{
		DestroyWindow(hWnd);
		hWnd = NULL;
	}

	UnregisterClass(__TEXT("OGL"), hInst);
	hInst = NULL;
}

bool Form::createGLWindow(NString title, int glBit)
{
	WNDCLASS	wc;
	DWORD		dwExStyle;
	DWORD		dwStyle;

	gl_iBit = glBit;
	int	width = scr_cResolution.scr_iWidth;
	int	height = scr_cResolution.scr_iHeight;

	scr_cPosition = Point(scr_cNative.scr_iWidth / 2 - width / 2, scr_cNative.scr_iHeight / 2 - height / 2);

	int	x = !scr_iMode ? 0 : scr_cPosition.x;
	int	y = !scr_iMode ? 0 : scr_cPosition.y;

	WindowRect.left = (long)x; 
	WindowRect.right = (long)x + width;
	WindowRect.top = (long)y;
	WindowRect.bottom = (long)y + height;

	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = (WNDPROC)WindowProcess;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInst;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_BACKGROUND;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = __TEXT("GLSample");
	RegisterClass(&wc);


	if (!scr_iMode)
	{
		DEVMODE dm;
		memset(&dm, 0, sizeof(dm));
		dm.dmSize = sizeof(dm);
		dm.dmPelsWidth = width;
		dm.dmPelsHeight = height;
		dm.dmBitsPerPel = gl_iBit;
		dm.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
		ChangeDisplaySettings(&dm, CDS_FULLSCREEN);
		dwExStyle = WS_EX_APPWINDOW;
		dwStyle = WS_POPUP;
		ShowCursor(false);
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
		if (scr_iMode == 0)
			dwStyle = WS_OVERLAPPED | WS_MINIMIZEBOX | WS_CAPTION | WS_SYSMENU;
		else
			dwStyle = WS_OVERLAPPEDWINDOW | WS_MINIMIZEBOX | WS_CAPTION | WS_SYSMENU;
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, false, dwExStyle);
	
	hWnd = CreateWindow(
		__TEXT("GLSample"), NString(title).toUnicode(),
		WS_CAPTION | WS_POPUPWINDOW | WS_VISIBLE | dwStyle,
		WindowRect.left, WindowRect.top,
		WindowRect.right - WindowRect.left,
		WindowRect.bottom - WindowRect.top,
		NULL, NULL, hInst, NULL);

	//RECT rcClient, rcWind;
	//GetClientRect(hWnd, &rcClient);
	//GetWindowRect(hWnd, &rcWind);
	//borderWidth = 2 * ((rcWind.right - rcWind.left) - rcClient.right) / 2;
	//borderHeight = 2 * ((rcWind.bottom - rcWind.top) - rcClient.bottom) / 2;

	initGL();

	SetForegroundWindow(hWnd);
	SetFocus(hWnd);
	return true;
}
void Form::initGL()
{
	PIXELFORMATDESCRIPTOR pfd;
	int iFormat;

	/* get the device context (DC) */
	hDC = GetDC(hWnd);

	/* set the pixel format for the DC */
	ZeroMemory(&pfd, sizeof(pfd));
	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW |
		PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = gl_iBit;
	pfd.cDepthBits = 16;
	pfd.iLayerType = PFD_MAIN_PLANE;
	iFormat = ChoosePixelFormat(hDC, &pfd);
	SetPixelFormat(hDC, iFormat, &pfd);

	/* create and enable the render context (RC) */
	hRC = wglCreateContext(hDC);
	wglMakeCurrent(hDC, hRC);
}


bool Form::Initialize()
{
	form_bActive = true;
	scr_iMode = 0; //debug only

	EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &nativeMode);
	//Auto detect native resolution for your win
	scr_cNative = Resolution(nativeMode.dmPelsWidth, nativeMode.dmPelsHeight);
	scr_cResolution = Resolution(nativeMode.dmPelsWidth, nativeMode.dmPelsHeight);
	return true;
}
bool Form::Initialize(Resolution useRes, int screenMode)
{
	form_bActive = true;
	scr_iMode = screenMode; 

	EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &nativeMode);
	scr_cNative = Resolution(nativeMode.dmPelsWidth, nativeMode.dmPelsHeight);
	scr_cResolution = useRes;
	return true;
}


bool Form::Show()
{
	while (!form_bExit)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				form_bExit = true;
				Form::~Form();
			}
		}
		else
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		DrawTriangles();
	}
	return true;
}

void Form::Resize(int w, int h)
{
	int	x = !scr_iMode ? 0 : scr_cPosition.x;
	int	y = !scr_iMode ? 0 : scr_cPosition.y;

	WindowRect.left = (long)x;
	WindowRect.right = (long)x + w;
	WindowRect.top = (long)y;
	WindowRect.bottom = (long)y + h;
}

LRESULT CALLBACK Form::WindowProcess(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	
	switch (message)
	{
	case WM_QUIT:
	{
		if (pro_bQuit)
		{
			pro_Quit();
			form_bExit = true;
		}
		break;
	}
	case WM_ACTIVATE:
	{
		if (pro_bActive)
			pro_Active();
		break;
	}
	case WM_CREATE:
	{
		if (pro_bCreate)
			pro_Create();
		break;
	}
	case WM_INPUT:
	{
		if (pro_bInput)
			pro_Input();
		break;
	}
	case WM_MOUSEMOVE:
	{
		if (pro_bMouseMove)
			pro_MouseMove();
		break;
	}
	case WM_LBUTTONDOWN:
	{
		break;
	}
	case WM_LBUTTONUP:
	{
		break;
	}
	case WM_RBUTTONDOWN:
	{
		break;
	}
	case WM_SIZE:
	{
		Resize(LOWORD(lParam), HIWORD(lParam));
		break;
	}
	case WM_GETMINMAXINFO:
	{
		break;
	}
	case WM_CLOSE:
		PostQuitMessage(0);
		return 0;

	case WM_DESTROY:
		return 0;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			return 0;
		}
		return 0;
	case WM_KEYUP:
	{
		break;
	}
	case WM_NCLBUTTONDOWN:
	{
		break;
	}
	case WM_NCLBUTTONUP:
	{
		break;
	}
	case WM_TIMER:
	{
		if (pro_bTimer)
			pro_Timer();
		break;
	}
	case WM_EXITSIZEMOVE:
	{
		break;
	}
	case WM_SETCURSOR:
	{
		break;
	}
	case WM_CANCELMODE:
	{
		break;
	}
	case WM_MOUSEWHEEL:
	{
		break;
	}
	default:
	{
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	}
}

RESULT Form::addProcess(UINT typeProcess, void (*process)())
{
	switch (typeProcess)
	{
	case WM_QUIT:
	{
		pro_Quit = process;
		break;
	}
	case WM_ACTIVATE:
	{
		pro_Active = process;
		break;
	}
	case WM_CREATE:
	{
		pro_Create = process;
		break;
	}
	case WM_INPUT:
	{
		pro_Input = process;
		break;
	}
	case WM_MOUSEMOVE:
	{
		pro_MouseMove = process;
		break;
	}
	case WM_LBUTTONDOWN:
	{
		break;
	}
	case WM_LBUTTONUP:
	{
		break;
	}
	case WM_RBUTTONDOWN:
	{
		break;
	}
	case WM_SIZE:
	{
		break;
	}
	case WM_GETMINMAXINFO:
	{
		break;
	}
	case WM_CLOSE:
	{
		PostQuitMessage(0);
		break;
	}
	case WM_DESTROY:
		return 0;

	case WM_KEYDOWN:
	{
		break;
	}
	case WM_KEYUP:
	{
		break;
	}
	case WM_NCLBUTTONDOWN:
	{
		break;
	}
	case WM_NCLBUTTONUP:
	{
		break;
	}
	case WM_TIMER:
	{
		pro_Timer = process;
		break;
	}
	case WM_EXITSIZEMOVE:
	{
		break;
	}
	case WM_SETCURSOR:
	{
		break;
	}
	default:
	{
		break;
	}
	}
}