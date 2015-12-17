#include "NColor.h"

using namespace NobelLib::Graphics;

NColor::NColor(NFloat _red, NFloat _green, NFloat _blue)
{
	Red = _red;
	Green = _green;
	Blue = _blue;
}

NColor::NColor()
{
	Red = 0.0f;
	Green = 0.0f;
	Blue = 0.0f;
}
