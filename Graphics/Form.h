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

			//Controls
			static Input* form_xInput;

			//form
			bool form_bActive;
			NString form_sTitle;
			static bool form_bExit;

			//Resource
			int res_iIcon;
			Texture* res_cBackground;

			//Screen
			static ScreenMode scr_nMode; //screen mode 0 = fullscreen, 1=windowed, 2=borderless (programming)
			Resolution scr_cResolution;
			Resolution scr_cNative;
			static Point scr_cPosition;
			static RECT WindowRect;

			RESULT initGL();
			 
		public:
			Form();
			~Form();

			bool Initialize();
			bool Initialize(Resolution useRes, ScreenMode screenMode);
			bool createGLWindow(NString Title, WNDPROC WinProc);
			int getStatus();
			void Draw();
			void Destroy();
			void Resize(int w, int h);
			//void Background(Texture background);
		};
	}
}