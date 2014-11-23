#include <cstdlib>
#include <string.h>
#include "NString.h"
#include "Array.h"

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

using namespace NobelLib;

NString::NString()
{
	str_Pointer="";
	str_Length=0;
}

NString::NString(const char* Const)
{
	this->str_Pointer = BasicString(Const);
	this->str_Length = strlen(Const);
}

NString::NString(const NString& CopyCC)
{
	this->str_Pointer=BasicString(CopyCC);
	this->str_Length = strlen(CopyCC);
}

NString::~NString()
{
	if (!this->Null()) 
	{
		delete[] str_Pointer;
		str_Length = -1;
	}
}

char* NString::BasicString(const char* My)
{
	int str_Len = strlen(My);
	char* Pointer = new char[str_Len+1];
	int i=0;
	for(i; i<str_Len; i++) 
	{
    Pointer[i] = My[i];
	}
	Pointer[i]= '\0';

	return Pointer;
}

NString& NString::addString(const char* add)
{
	char* oldPointer = this->str_Pointer;
	int oldLength = this->str_Length;

	this->Clear();

	this->str_Pointer = new char[oldLength + strlen(add) + 1];

	int copy = 0;
	for (int i = 0; i<oldLength; i++)
	{
		this->str_Pointer[copy] = oldPointer[i];
		copy++;
	}

	for (int i = 0; i<strlen(add); i++)
	{
		this->str_Pointer[copy] = add[i];
		copy++;
	}

	this->str_Pointer[copy] = '\0';
	this->str_Length = oldLength + strlen(add);

	if (!this->Null(add))
	{
		delete[] oldPointer;
	}
	return *this;
}

NString& NString::addString(const char add)
{
	char* Old = this->str_Pointer;
	int length = strlen(this->str_Pointer);

	this->str_Pointer = new char[length + 2];

	int Count = 0;

	for (int i = 0; i < length; i++)
	{
		this->str_Pointer[Count] = Old[i];
		Count++;
	}

	this->str_Pointer[Count] = add;
	Count++;
	this->str_Pointer[Count] = '\0';
	this->str_Length = strlen(this->str_Pointer);

	if (!Null(Old))
	{
		delete[] Old;
	}

	return *this;
}

void NString::Clear()
{
	this->str_Length=0;
	this->str_Pointer="";
}
bool NString::Null()
{
	if (this->str_Pointer == "" || this->str_Length == 0)
	{
		return true;
		this->Clear();
	}
	else
		return false;
}

bool NString::Null(const char* IsEmpty)
{
	if (IsEmpty == "" || strlen(IsEmpty) <= 0)
		return true;
	else
		return false;
}
bool NString::Find(const NString* str_My)
{
	int trueCount=0;
	int c=0;
	for(int i=0; i<str_Length;i++)
	{
		if(str_Pointer[i]==str_My->str_Pointer[0])
	{
		for(c; c<str_My->str_Length;c++)
			if(str_My->str_Pointer[c]==str_Pointer[i+c])
				trueCount++;
		if(trueCount==c)
			return true;
		else
			return false;
	}
	}
	return false;
}

bool NString::Find(const char* char_My)
{
	int lengthof=strlen(char_My);
	int trueCount=0;
	int c=0;
	for(int i=0; i<this->str_Length;i++)
	{
		if(str_Pointer[i]==char_My[0])
	{
		for(c; c<lengthof;c++)
			if(char_My[c]==this->str_Pointer[i+c])
				trueCount++;
		if(trueCount==c)
			return true;
		else
			return false;
	}
	}
	return false;
}


int NString::toInt()
{
	return atoi(this->str_Pointer);
}
NString NString::toBinary(int Decimal)
{
	char buffer[1024];
	return NString(_itoa(Decimal, buffer, 2));
}
NString NString::toHex(int Decimal)
{
	char buffer[1024];
	return NString(_itoa(Decimal, buffer, 16));
}
NString NString::fromInt(int IntToString)
{
	char buffer[1024];
	return NString(_itoa(IntToString, buffer, 10));
}
NString NString::Sub(int IndexStart)
{
	if (IndexStart<0 || IndexStart>this->str_Length)
		return *this;

	return NString(this->str_Pointer + IndexStart); //This step is very important, I must return the fisical copy of Exit, if not after use of sub() Exit will be deleted, and with it the pointer of char
}
NString NString::Sub(int IndexStart, int IndexLen)
{
	NString Exit(this->str_Pointer+IndexStart);

	if (IndexLen > strlen(Exit))
		return Sub(IndexStart);

	Exit.str_Pointer[IndexLen] = '\0';
	return NString(Exit); //This step is very important, I must return the fisical copy of Exit, if not after use of sub() Exit will be deleted, and with it the pointer of char
}
void NString::Split(const char Splitter, Array<NString> &arrayStr)
{
	arrayStr.Clear();
	arrayStr.New(1);
	int memoryCount=0; //char counter
	int slotCount=1; //counter for next element
		for(int i=0; i<this->str_Length;i++)
		{
			if (this->str_Pointer[i] == Splitter)
			{
				arrayStr[slotCount-1] = NString(this->Sub(memoryCount, i-memoryCount));
				slotCount++;
				arrayStr.expArray(slotCount);
				memoryCount=i+1;
			}
		}
		arrayStr[slotCount-1] = NString(this->Sub(memoryCount));
}

NString NString::toLower()
{
	return NString(_strlwr(this->str_Pointer));
}
NString NString::toUpper()
{
	return NString(_strupr(this->str_Pointer));
}

NString NString::toReverse()
{
	return NString(_strrev(this->str_Pointer));
}

NString::operator const char *()
{
  return this->str_Pointer;
}

NString::operator const char *() const
{
  return this->str_Pointer;
}

NString& NString::operator =(const char* newChar)
{
	this->Clear();
	this->str_Pointer = BasicString(newChar);
	this->str_Length = strlen(newChar);
	return *this;
}

NString& NString::operator =(char newChar)
{
	this->Clear();
	this->str_Pointer= &newChar;
	this->str_Length=1;
	return *this;
}

NString& NString::operator =(NString& strCopy)
{
	this->Clear();
	this->str_Pointer = BasicString(strCopy);
	this->str_Length = strlen(strCopy);
	return *this;
}
NString& NString::operator+=(const char addMe)
{
	return addString(addMe);
}

NString& NString::operator+=(const char* addMe)
{
	return addString(addMe);
}

NString& NString::operator+=(const NString& addMe)
{
	return addString(addMe);
}

NString& NString::operator+(const char* addMe)
{
	return addString(addMe);
}

NString& NString::operator+(const NString& addMe)
{
	return addString(addMe);
}

char NString::operator[](int index)
{
	if(index>=0 && index<=str_Length)
	return str_Pointer[index];

}

bool NString::Equal(const char* Compare)
{
	int trueCount = 0;
	int compareLength = strlen(Compare);
	bool result;

	if (compareLength == this->str_Length)
	{
		for (int i = 0; i<compareLength; i++)
		if (Compare[i] == this->str_Pointer[i])
			result = true;
		else
			return false;
		return result;
	}
	else
		return false;
}

bool NString::operator ==(const NString& equal)
{
	return Equal(equal);
}

bool NString::operator !=(const NString& equal)
{
	return !Equal(equal);
}

bool NString::operator ==(const char* equal)
{
	return Equal(equal);
}
bool NString::operator !=(const char* equal)
{
	return !Equal(equal);
}


int NString::getLength(){ return str_Length; }