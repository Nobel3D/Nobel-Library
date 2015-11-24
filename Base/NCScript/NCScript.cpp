#include "NCScript.h"
#include <iostream>

using namespace std;

using namespace NobelLib;
using namespace NobelLib::NCS;
using namespace NobelLib::Management;

NCScript::NCScript( Array<NCommand*>* arrayCommand, Console cmdConsole)
{
	this->fileLog = new IO::NFile("NLog.txt");
	this->fileLog->Open(IO::Append);
	addLog("[SYS] Loaded Logs stream!");
	ncs_cConsole = cmdConsole;
	addLog("[SYS] Loading console: WIN32");
	ncs_cConsole.setColor(DBlack, LGreen);
	ncs_cConsole << NString("Starting Nobel CScript Console: Loading commands...");
	cmdUploaded = *arrayCommand;
	logCommands();
}

void NCScript::addLog(const NString strMessage)
{
	this->fileLog->WriteLine(DateTime::NowTime() + " -> " + strMessage);
}

bool NCScript::WaitCommand()
{
	char charCommand[250];
	NString strCommand;
	cout << (DateTime::NowTime() + "-> ");
	cin >> charCommand;

	strCommand = charCommand;

	if (strCommand == "Kill" || strCommand == "KILL" || strCommand == "kill")
	{
		this->~NCScript();
		return false;
	}
	int TypeOperation = checkSyntax(strCommand);
	if (TypeOperation == 1 || TypeOperation == 0) //If function...
	{
		int Index = checkCommand();
		if (Index == -1)
		{
			ncs_cConsole << NString("ERROR: Command \"") + NString(strCommand) + NString("\" not found.");
		}
		else
		{
			if (TypeOperation == 1)
				cmdUploaded[Index]->loadParams(Params);

			ncs_cConsole << cmdUploaded[Index]->exeCommand().getOutput();
		}
	}
	else if (TypeOperation == 2 || TypeOperation == 3)
	{

		int index = indexVariable(this->Header);
		ncs_cConsole << Variables[index]->getOutput();
	}
	else
	{
		ncs_cConsole << NString("ERROR: Wrong Syntax.");
	}
	Reset();
	return true;
}

int NCScript::checkSyntax(NString strCommand)
{
	Array<NString> arraySplit;
	if (strCommand.Find("(") && strCommand.Find(")")) /*if this is funcion...*/
	{
		strCommand.Split('(', arraySplit);
		Header = arraySplit[0];
		arraySplit[1] = arraySplit[1].Replace(")", "\0");
		if (arraySplit[1].Null())
		{
			arraySplit.Delete();
			return 0;
		}
		else if (arraySplit[1].Find(","))
		{
			arraySplit[1].Split(',', arraySplit);
			for (int i = 0; i < arraySplit.SizeArray(); i++)
			{
				Params.addItem(NResult(arraySplit[i]));
			}
			arraySplit.Delete();
			return 1;
		}
	}
	else if (!strCommand.Find("(") && !strCommand.Find(")"))/*if this is variable*/
	{
		if (strCommand.Find("="))
		{
			strCommand.Split('=', arraySplit);
			arraySplit[0] = arraySplit[0].Trim();
			arraySplit[1] = arraySplit[1].Trim();
			this->Header = arraySplit[0];
			if (arraySplit[1].Find("\""))
				Variables.addItem(NResult(arraySplit[1],arraySplit[0]));
			else
				Variables.addItem(NResult(arraySplit[1].toDouble(), arraySplit[0]));
			return 3;
		}
		else
		{
			Header = strCommand;
			arraySplit.Delete();
			return 2;
		}
	}
	return -1;
}

int NCScript::checkCommand()
{
	for (int i = 0; i < cmdUploaded.SizeArray(); i++)
	{
		if (*cmdUploaded[i] == this->Header)
		{
			return i;
		}
	}
	return -1;
}
void NCScript::logCommands()
{
	for (int i = 0; i < cmdUploaded.SizeArray();i++)
		addLog(NString("[CMD] Loading command: ") + cmdUploaded[i]->getName());
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
	if (Params.getLength()>0)
		Params.Clear();
}

NCScript::~NCScript()
{
	addLog("[SYS] Closing NCScript...");
 	this->cmdUploaded.Delete();
	addLog("[SYS] Cleaning resources");
	this->fileLog->Close();
}

int NCScript::indexVariable(NString nameVariable)
{
	for (int i = 0; i < this->Variables.getLength(); i++)
	if (Variables[i]->compareName(nameVariable))
		return i;
}