#pragma once

#include "Array.h"
#include <tchar.h>

namespace NobelLib
{
		
	class NString
	{
	private: 
		NString& addString(const char* add);
		NString& addString(const char add);
		bool Equal(const char* Compare);
		char* BasicString(const char* My);

	protected:
		char* str_Pointer;
		int str_Length;
	public:

		NString();
		NString(const char* Const);
		NString(const NString& CopyCC);

		void Clear();
		bool Null();
		static bool Null(const char*  IsEmpty);
		static NString Zero();

		bool chk_Number(); //this string is a number?

		Array<NString>& Split(const char Splitter, Array<NString> &arrayStr);
		bool Find(const NString* str_My);
		bool Find(const char* char_My);
		NString Sub(int IndexStart);
		NString Sub(int IndexStart, int IndexLen);

		NString Trim();
		NString Replace(const char* str, const char* strReplace);
		NString toLower();
		NString toUpper();
		NString toReverse();
		int toInt();
		double toDouble();
		wchar_t* toUnicode();
		static NString toHex(int Decimal);
		static NString toBinary(int Decimal);
		static NString fromUnicode(wchar_t* struni);
		static NString fromInt(int IntToString);
		static NString fromDouble(double Convert);

		int getLength();
		
		operator char* ();
		operator const char* ();
		operator const char*() const;
		operator wchar_t*();
		operator const wchar_t*();

		NString operator=(const char* newChar);
		NString operator=(NString& strCopy);
		NString operator=(char newChar);
		NString operator+=(const char* addMe);
		NString operator+=(const char addMe);
		NString operator+=(const NString& addMe);
		NString operator+(const char* addMe);
		NString operator+(const NString& addMe);
		friend NString operator+(char* addMe, NString str)
		{
			return NString(addMe) + str;
		}

		char operator[](int index);

		bool operator==(const char* equal);
		bool operator!=(const char* equal);
		bool operator==(const NString& equal);
		bool operator!=(const NString& equal);
	};
}