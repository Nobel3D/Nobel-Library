#pragma once

#include "..\Base\NString.h"
#include "..\Definitions.h"

namespace NobelLib
{
	namespace IO
	{
		enum OpenMode { Writing = 8, Reading = 16, Append = 32 };
		enum TypeStream { LocalFile=8, NetworkConnection=16, DataBase=32, Crypter=64 };

		class Stream
		{
		protected:
			BYTE* stmBuffer;
			UINT stmSize;

			UINT stmUsed;

			void createBuffer(const char* sendBuffer);
			virtual bool CanLoad();
			virtual int Write() = 0;
			virtual int Read(void* vpGet, UINT length) = 0;
		public:
			Stream();
			~Stream();

			virtual bool Open(OpenMode OpenFile);
			virtual int Close();

			void WriteLine(const char* Send);
			void WriteStr(const char* Send);

			NString ReadLine();
			NString ReadAll();

			Stream& operator <<(const char* str);
			Stream& operator >>(NString &str)  { str=ReadLine(); return *this; }
		};
	}
}