#include <iostream>

#include "userInterface.h"
#include "stringError.h"
#include "functionSelector.h"

using namespace std;

// The Function gets a string from the keyboard and
// evaluates if it's a command or a math expression.
// If not successfull, displays an error message
string userInterface::input (void)
{
	string inputString;
	
	cout << ">> ";
	getline(cin,inputString);

	if (stringError::treatment (inputString))
		return functionSelector(inputString);
	return "";
}

//displays a string
void userInterface::output (string outputString)
{
	cout << ">> " << outputString << endl;
}
