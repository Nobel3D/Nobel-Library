#include "VideoMode.h"
#include "NFloat.h"

using namespace NobelLib::Graphics;
using namespace NobelLib;

Resolution::Resolution(int w, int h)
{
	if (NFloat(16.0f / 9.0f).getRound(1) == NFloat(float(w) / float(h)).getRound(1))
		scr_iResolution = 0;
	else if(float(4) / float(3) == float(w) / float(h))
		scr_iResolution = 1;
	//FIX ME: ADD ERROR WARNING

	scr_iWidth = w; scr_iHeight = h;
};