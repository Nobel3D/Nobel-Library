#include "..\Base\NString.h"

namespace NobelLib
{
	namespace Math
	{
		class  Polynomial : NString
		{
		private:
			NString* str_Polynomy;
			int* KnownTerms;
		public:
			Polynomial(NString MyPolynomy);
		};
	}

}