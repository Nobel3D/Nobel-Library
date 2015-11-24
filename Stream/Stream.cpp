#include "Stream.h"
#include <string.h>
using namespace NobelLib::IO;
using namespace NobelLib;

Stream::Stream()
{
}
//Stream::Stream(NString IP, int Port)
//{
//}
//Stream::Stream(DataType Database)
//Stream::Stream(CryptoAuth Authorization)


Stream::~Stream()
{
	Close();
}

int Stream::Close()
{
	return 1;
}

bool Stream::CanLoad()
{
	return false;
}

bool Stream::Open(OpenMode Mode)
{
	return CanLoad();
}

int Stream::Write()
{
	return 1;
}
void Stream::WriteLine(const char* Send)
{
	NString strSend = NString(Send) + "\n";
	createBuffer(strSend);
	Write();
}

void Stream::WriteStr(const char* Send)
{
	createBuffer(Send);
	Write();
}

void Stream::createBuffer(const char* sendBuffer)
{
	int strLen = strlen(sendBuffer);
	this->stmBuffer = new BYTE[strLen];

	for (int i = 0; i<strLen; i++)
	{
		stmBuffer[i] = sendBuffer[i];
	}
	stmSize = strLen;
}

Stream& Stream::operator<< (const char* str)
{
	WriteLine(str);
	return *this;
}
bool NobelLib::IO::Stream::isEoF()
{
	return stm_bEoF;
}
NString Stream::ReadLine()
{
	NString strRet = "";
	char c='!';
	do 
	{
		if (Read(&c, sizeof(char)))
			strRet += c;
	} 
	while (c != '\n' && !stm_bEoF);

	return NString(strRet);
}
NString Stream::ReadAll(void)
{
	NString strRet = "";
	char c = '!';
	do
	{
		if (Read(&c, sizeof(char)))
			strRet += c;
		else
			break;
	} while (true);

	return NString(strRet);
}
