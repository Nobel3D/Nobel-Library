#pragma once
#include "..\NString.h"
#include <Windows.h>

namespace NobelLib
{
	namespace Systems
	{

		namespace Windows
		{
			class NWindow
			{
			private:
				LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
				void CALLBACK MsgRouter(HWND hwnd, UINT message,
					WPARAM wparam, LPARAM lparam);
			protected:
				HWND hwnd;               /* This is the handle for our window */
				MSG messages;            /* Here messages to the application are saved */
				WNDCLASSEX wincl;        /* Data structure for the windowclass */
			public:
				NWindow();
				static NWindow* Create(HINSTANCE hInst);
				void Show();
			};
		}
	}
}