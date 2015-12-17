#include "VideoMode.h"
#include "NFloat.h"

using namespace NobelLib::Graphics;
using namespace NobelLib;

Resolution::Resolution(int w, int h)
{
	scr_fRatio =  NFloat(float(w) / float(h));
	//FIX ME: ADD ERROR WARNING

	scr_iWidth = w; scr_iHeight = h;
};