#include "Stream.h"
#include <string.h>
using namespace NobelLib::IO;
using namespace NobelLib;

Stream::Stream(NString Path)
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

void Stream::Close()
{
}

bool Stream::CanLoad()
{
	return false;
}

bool Stream::Open(OpenMode Mode)
{
	return CanLoad();
}

void Stream::Write()
{
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
NString Stream::ReadLine(void)
{
	NString strRet = "";
	char c='!';
	do 
	{
		if (Read(&c, sizeof(char)))
			strRet += c;
		else
			break;
	} 
	while (c != '\n');

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
