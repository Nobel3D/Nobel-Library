#include "input.h"

using namespace NobelLib;

KeyBoard::KeyBoard()
{
	for (int i = 0; i < NUM_KEYS; i++)
		xin_bMap[i] = false;
}

KeyBoard::~KeyBoard()
{
}

void KeyBoard::update()
{
}

void KeyBoard::keyDown(BYTE key)
{

	xin_bMap[key] = true;
}

void KeyBoard::keyUp(BYTE key)
{

	xin_bMap[key] = false;
}

bool KeyBoard::operator[](BYTE input)
{
	return xin_bMap[input];
}
Mouse::Mouse()
{
	input_state = 0;
	lX = 0;
	lY = 0;
	ZeroMemory(bButtons, sizeof(bButtons));
}

Mouse::~Mouse()
{
}

void Mouse::update()
{
	input_state ^= 1;
	memcpy(bButtons_state[input_state], bButtons_state, NUM_M_BUTTONS);
	lX_state[input_state] = lX;
	lY_state[input_state] = lY;
}

long Mouse::ldX()
{
	return (lX_state[input_state] - lX_state[input_state ^ 1]);
}

long Mouse::ldY()
{
	return (lY_state[input_state] - lY_state[input_state ^ 1]);
}

Input::Input()
{
}

Input::~Input()
{
}

void Input::update()
{
	keyboard.update();
	mouse.update();
}