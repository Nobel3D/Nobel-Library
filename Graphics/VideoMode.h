#pragma once
namespace NobelLib
{
	namespace Graphics
	{
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