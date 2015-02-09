#include <cstdlib>

#include "commands.h"
#include "userInterface.h"
#include "varManager.h"

using namespace std;

string commands::clear (void)
{
	for (unsigned i = 0; i < 50; i++)
		userInterface::output ("");
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
	userInterface::output ("");
	userInterface::output ("\tVariables\t\tValue");
	varManager::varSpreadsheet();
	return "";
}


string commands::remove (string input)
{
	unsigned commandPos;
	string variable = "haha";

	commandPos = input.find("remove");

	for (unsigned i = (commandPos + 6); i < input.length(); i++)
		if (!isspace(input[i]))
		{
			variable = input.substr(i);
			break;
		}
	if (true);
	
	if (varManager::varRemove(variable))
		return "'" + variable + "'" + " was successfully removed";
	return "Variable not found";
}


