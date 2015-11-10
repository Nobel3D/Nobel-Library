#pragma once

#include "..\Base\NString.h"

namespace NobelLib
{
	namespace Net
	{
		class IP
		{
		private:
			NString net_sIP;

			bool chk_bIP();
			public:
			IP(NString stringIp);
			IP(char* class4, char* class3, char* class2, char* class1);
			IP(int class4, int class3, int class2, int class1);

			NString getIP();

			static IP localhost();
		};
	}
}