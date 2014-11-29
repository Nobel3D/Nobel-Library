#include "NCScript.h"
#include <iostream>

using namespace std;

using namespace NobelLib;
using namespace NobelLib::Sys::NCScript;

#define MAX_SUPPORT_STRING 100

void NCScript::sendOutput(NString& Message)
{
	cout << Message << endl;
}

//void NCScript::addLog(NString& Message)
//{
//	if (LogFile->IsStarted())
//		LogFile->WriteLine(Sys::DateTime::NowTime() + "->" + NString(Message));
//	else
//	{
//		LogFile = new IO::NFile("Log.txt");
//		LogFile->Open(IO::OpenMode::Append);
//	}
//}

NCScript::NCScript( Array<NCommand>* arrayCommand)
{

		cmdUploaded = *arrayCommand;

	
		sendOutput(NString("Starting Nobel CScript Console"));
}


bool NCScript::WaitCommand()
{
	char strCommand[MAX_SUPPORT_STRING];
	cout << (Sys::DateTime::NowTime() + "-> ");
	cin >> strCommand;
	if (checkSyntax(strCommand) == 0)
	{
		int Index = checkCommand();
		if (Index == -1)
		{
			throw "Fail";
		}
		else
		{
			sendOutput(cmdUploaded[Index].exeCommand().getOutput());
		}
	}

	return true;
}

int NCScript::checkSyntax(NString strCommand)
{
	if (strCommand.Find("(") && strCommand.Find(")")) /*if this is funcion...*/
	{
		IsFuncion = true;
		Array<NString> arraySplit;
		strCommand.Split('(', arraySplit);
		Header = arraySplit[0];
		arraySplit[1].Replace(")", "\0");
		if (arraySplit[1].Null())
		{
			IsVoid = true;
		}
		else if (arraySplit[1].Find(","))
		{
			arraySplit[1].Split(',', arraySplit);
			for (int i = 0; i < arraySplit.SizeArray(); i++)
				Params.addItem(arraySplit[i]);
		}
	}
	else if (!strCommand.Find("(") && !strCommand.Find(")"))/*if this is variable*/
	{
		IsVarible = true;
		Header = strCommand;
	}
	return 0;
}

int NCScript::checkCommand()
{
	for (int i = 0; i < cmdUploaded.SizeArray(); i++)
	if (cmdUploaded[i] == this->Header)
	{
		return i;
	}
	return -1;
}