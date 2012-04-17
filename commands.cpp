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
	return "string de ajuda";
}

//prints a spreadsheet with all the
//storaged variable
string commands::spreadsheet (void)
{
	userInterface::output ("	variables		value");
	userInterface::output ("     lista");
	return "";
}

//removes the target variable
string commands::remove (string input)
{
	return "variavel removida";
}


