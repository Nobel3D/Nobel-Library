#pragma once

#include "..\NString.h"

namespace NobelLib
{
	namespace NCS
	{
		class NResult
		{
		private:
			NString name;
			NString value;
		public:
			bool forceString = false;

			NResult(NString get);
			NResult(double get);
			NResult(NResult& Other);
			NResult(NString get, NString strName);
			NResult(double get, NString strName);

			bool compareName(NString other);
			bool compareValue(NString other);
			NString getOutput();
			double toValue();
			NString toString();

			bool operator==(NResult& Compare);
			bool operator!=(NResult& Compare);
		};
	}
}