#pragma once

#include <windows.h>
#include "..\Base\NString.h"

namespace NobelLib
{
	namespace Graphics
	{
		class Form
		{
		private:

			// Global Variables:
			HINSTANCE hInst;								// current instance
			TCHAR* szTitle;					// The title bar text
			TCHAR* szWindowClass;			// the main window class name
			HWND hWnd;
			MSG msg;
			int intCmdShow;

			//Form Variables:
			int heightForm;
			int widthForm;
			int iconForm;

			// Forward declarations of functions included in this code module:
			ATOM MyRegisterClass();
			BOOL InitInstance();
			static LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);

		public:
			static TCHAR* charToTCHAR(char* strChar);
			static char* TCHARToChar(TCHAR* strTCHAR);

			bool Show();
			bool setForm(char* Title, int heightWnd, int widthWnd,int iconWnd);
			Form(_In_ HINSTANCE hInstance,
				_In_opt_ HINSTANCE hPrevInstance,
				_In_ LPTSTR    lpCmdLine,
				_In_ int       nCmdShow);
		};
	}
}