#pragma once
namespace NobelLib
{
	namespace Graphics
	{
		enum ScreenMode
		{
			FULLSCREEN = 0,
			WINDOWED = 1,
			BORDERLESS = 2 //Programming
		};
		class Resolution
		{	private:
			public:
			int scr_iWidth;
			int scr_iHeight;
			int scr_iResolution; //16:9 = 0 - 4:3 = 1

			Resolution() {};
			Resolution(int w, int h);
			~Resolution() {};
		};
	}
}