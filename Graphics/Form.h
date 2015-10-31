#pragma once

#include <windows.h>
#include "..\Base\NString.h"
#include <windows.h>
#include "Point.h"
#include "VideoMode.h"
#include "OpenGL.h"
#include "..\Definitions.h"

namespace NobelLib
{
	namespace Graphics
	{
		class Form : GLClass
		{
		private:

			// Global Variables:
			HINSTANCE hInst;								// current instance	
			TCHAR* szWindowClass;			// the main window class name
			HWND hWnd;
			static MSG msg;
			int intCmdShow;


			//form
			bool form_bActive;
			TCHAR* form_sTitle;
			static bool form_bExit;

			//Resource
			int res_iIcon;

			//Screen
			static int scr_iMode; //screen mode 0 = fullscreen, 1=windowed, 2=borderless (programming)
			Resolution scr_cResolution;
			Resolution scr_cNative;
			static Point scr_cPosition;
			static RECT WindowRect;

			//Form processes
			static bool pro_bQuit;
			static bool pro_bActive;
			static bool pro_bCreate;
			static bool pro_bInput;
			static bool pro_bMouseMove;
			static bool pro_bTimer;
			static bool pro_bResize;
			static void(*pro_Resize)();
			static void(*pro_Quit)();
			static void(*pro_Active)();
			static void(*pro_Create)();
			static void(*pro_Input)();
			static void(*pro_MouseMove)();
			static void(*pro_Timer)();

			void initGL();
			void destroyWindow();
			static void Resize(int w, int h);
			 
			static LRESULT CALLBACK WindowProcess(HWND hWnd, UINT message,WPARAM wParam, LPARAM lParam);
		public:
			Form();
			~Form();

			bool Show();
			bool Initialize();
			bool Initialize(Resolution useRes, int screenMode);
			RESULT addProcess(UINT typeProcess, void (*process)());
			bool createGLWindow(NString Title, int glBit);
		};
	}
}