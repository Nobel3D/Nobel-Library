#include "NCScript.h"
#include <iostream>

using namespace std;

using namespace NobelLib;
using namespace NobelLib::Sys::NCScript;

#define MAX_SUPPORT_STRING 100


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

NCScript::NCScript( Array<NCommand*>* arrayCommand, Sys::Windows::NConsole* cmdConsole)
{
	this->Console = cmdConsole;
	Console->sendOutput(NString("Starting Nobel CScript Console: Loading commands..."));
	cmdUploaded = *arrayCommand;
}


bool NCScript::WaitCommand()
{
	char strCommand[MAX_SUPPORT_STRING];
	cout << (Sys::DateTime::NowTime() + "-> ");
	cin >> strCommand;
	int TypeOperation = checkSyntax(strCommand);
	if (TypeOperation == 1 || TypeOperation == 0) //If function...
	{
		int Index = checkCommand();
		if (Index == -1)
		{
			Console->sendOutput(NString(NString("ERROR: Command \"") + NString(strCommand) + NString("\" not found.")));
		}
		else
		{
			if (TypeOperation == 1)
				cmdUploaded[Index]->loadParams(Params);

			Console->sendOutput(cmdUploaded[Index]->exeCommand().getOutput());
		}
	}
	else if (TypeOperation == 2)
	{

	}
	else
	{
		Console->sendOutput(NString("ERROR: Wrong Syntax."));
	}
	Reset();
	return true;
}

int NCScript::checkSyntax(NString strCommand)
{
	if (strCommand.Find("(") && strCommand.Find(")")) /*if this is funcion...*/
	{
		Array<NString> arraySplit;
		strCommand.Split('(', arraySplit);
		Header = arraySplit[0];
		arraySplit[1] = arraySplit[1].Replace(")", "\0");
		if (arraySplit[1].Null())
		{
			return 0;
		}
		else if (arraySplit[1].Find(","))
		{
			arraySplit[1].Split(',', arraySplit);
			for (int i = 0; i < arraySplit.SizeArray(); i++)
			{
				Params.addItem(NResult(arraySplit[i]));
			}
			return 1;
		}
	}
	else if (!strCommand.Find("(") && !strCommand.Find(")"))/*if this is variable*/
	{
		Header = strCommand;
		return 2;
	}
	return -1;
}

int NCScript::checkCommand()
{
	for (int i = 0; i < cmdUploaded.SizeArray(); i++)
	if (*cmdUploaded[i] == this->Header)
	{
		return i;
	}
	return -1;
}

int NCScript::Start()
{
	while (WaitCommand())
	{
		continue;
	}
	return 0;
}

void NCScript::Reset()
{
	Params.Clear();
}