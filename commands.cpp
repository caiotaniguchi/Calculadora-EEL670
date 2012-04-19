#include <cstdlib>

#include "commands.h"
#include "userInterface.h"

using namespace std;

//exits the program
void commands::exitMain (void)
{
	exit(0);	
}

//shows help message
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

//prints a spreadsheet with all the
//storaged variables
string commands::list (void)
{
	userInterface::output ("\tVariables\t\tValue");
	userInterface::output ("");
	userInterface::output ("lista");
	return "";
}

//removes the target variable
string commands::remove (string input)
{
	return "variavel removida " + input;
}


