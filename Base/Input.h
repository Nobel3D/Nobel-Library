#pragma once
#include <Windows.h>
#include <math.h>
#include <tchar.h>
#include "..\Definitions.h"
#include "Array.h"
extern "C"
{
#include <hidsdi.h> 
}

#define		NUM_KEYS		256
#define		NUM_BUTTONS		10
#define		NUM_M_BUTTONS	2

namespace NobelLib
{
	class KeyBoard
	{
	public:
		Array<bool> xin_bMap = Array<bool>(NUM_KEYS);

		KeyBoard();
		~KeyBoard();

		void	update();

		void	keyDown(BYTE key);
		void	keyUp(BYTE key);

		bool operator[](BYTE input);
	};

	class Mouse
	{
	public:
		bool	bButtons[NUM_M_BUTTONS];
		bool	bButtons_state[2][NUM_M_BUTTONS];
		long	lX;
		long	lX_state[2];
		long	lY;
		long	lY_state[2];
		int		input_state;

		Mouse();
		~Mouse();

		void	update();

		long	ldX();
		long	ldY();

		bool	buttonPressed();
		bool	buttonReleased();
		bool	buttonDown();
		bool	buttonUp();
	};

	typedef enum GP_HatDirection
	{
		GPH_UP = 0,
		GPH_RIGHTUP = 1,
		GPH_RIGHT = 2,
		GPH_RIGHTDOWN = 3,
		GPH_DOWN = 4,
		GPH_LEFTDOWN = 5,
		GPH_LEFT = 6,
		GPH_LEFTUP = 7
	} GP_HatDirection;

	typedef enum GP_Button
	{
		GPB_A = 0,
		GPB_B = 1,
		GPB_X = 2,
		GPB_Y = 3,
		GPB_LB = 4,
		GPB_RB = 5,
		GPB_SL = 6,
		GPB_ST = 7,
		GPB_LS = 8,
		GPB_RS = 9
	} GP_Button;

	typedef enum GP_AxisDirection
	{
		GPA_LEFT = 1,
		GPA_RIGHT = 2
	} GP_AxisDirection;

	class Input
	{
	public:
		KeyBoard	keyboard;
		Mouse		mouse;

		Input();
		~Input();

		void		update();
	};
}