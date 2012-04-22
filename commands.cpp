#include <cstdlib>
#include <iostream>

#include "commands.h"
#include "userInterface.h"
#include "varManager.h"

using namespace std;

string commands::clear (void)
{
	for (unsigned i = 0; i < 50; i++)
		cout << endl;
	return "";
}


void commands::exitMain (void)
{
	exit(0);	
}


string commands::help (void)
{
	userInterface::output ("");
	userInterface::output ("List of commands:");
	userInterface::output ("");
	userInterface::output ("exit\t\t\texits the program");	
	userInterface::output ("help\t\t\tshows this message");
	userInterface::output ("list\t\t\tlists all the storaged variables and its current values");
	userInterface::output ("remove <target>\tdeletes target variable");
	userInterface::output ("");
	userInterface::output ("Current program version suports the 4 basic operations with real");
	userInterface::output ("numbers. It's also possible to assign values to variables using");
	userInterface::output ("<variable> = <value>");
	return "";
}

string commands::list (void)
{
	userInterface::output ("\tVariables\t\tValue");
	userInterface::output ("");
	varManager::varSpreadsheet();
	return "";
}


string commands::remove (string input)
{
	unsigned commandPos;
	string variable;

	commandPos = input.find("remove");
	cout << commandPos << endl;	
	unsigned j = 0;
	for (unsigned i = (commandPos + 6); i < input.length(); i++)
		if (!isspace(input[i]))
		{
			variable = input.substr(i);
			break;
		}
	
	userInterface::output (variable);
	if (varManager::varRemove(variable))
		return "variavel removida " + variable;
	return "fail";
}


