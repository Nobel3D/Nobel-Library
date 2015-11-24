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
			bool stm_bEoF = false;
			void createBuffer(const char* sendBuffer);
			virtual bool CanLoad();
		public:
			Stream();
			~Stream();

			virtual bool Open(OpenMode OpenFile);
			virtual int Close();
			
			void WriteLine(const char* Send);
			void WriteStr(const char* Send);

			virtual int Write() = 0;
			virtual LLINT Read(void* vpGet, LLINT length, LLINT count = 1) = 0;

			NString ReadLine();
			NString ReadAll();

			Stream& operator <<(const char* str);
			Stream& operator >>(NString &str)  { str=ReadLine(); return *this; }

			bool isEoF();
		};
	}
}