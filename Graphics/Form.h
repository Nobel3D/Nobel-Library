#pragma once

#include <windows.h>
#include "..\Base\NString.h"
#include "Point.h"
#include "VideoMode.h"
#include "OpenGL.h"
#include "..\Definitions.h"
#include "..\Base\Input.h"
#include "Texture.h"

namespace NobelLib
{
	namespace Graphics
	{
		class Form : GLObject
		{
		private:

			// Global Variables:
			HINSTANCE hInst;								// current instance	
			HWND hWnd;

			//form
			bool form_bActive;
			NString form_sTitle;
			static bool form_bExit;

			//Resource
			int res_iIcon;
			Texture* res_cBackground;

			//Screen
			static ScreenMode scr_nMode; //screen mode 0 = fullscreen, 1=windowed, 2=borderless (programming)
			Resolution scr_cNative;
			static Point scr_cPosition;
			static RECT WindowRect;
			DEVMODE	nativeMode;

			RESULT initGL();
			static void(*form_Input)();
			 
		public:
			//Controls
			static Input* form_xInput;

			Form();
			~Form();

			bool Initialize();
			bool Initialize(Resolution useRes, ScreenMode screenMode);
			bool createGLWindow(NString Title, void (*funcInput)());
			static LRESULT CALLBACK WindowProcess(HWND handle, UINT message, WPARAM wParam, LPARAM lParam);
			RESULT getStatus();
			void Draw();
			void gl_Clear();
			void Destroy();
			static void Resize(int w, int h);
			void Load(void* null = nullptr);
			bool winLoop(MSG* msg);
			//void Background(Texture background);
		};
	}
}