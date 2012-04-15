#include <iostream>

#include "userInterface.h"
#include "stringError.h"
#include "stringCalc.h"

using namespace std;

//The Function gets a string from the keyboard.
//If not successfull, displays an error message
string userInterface::input (void)
{
	string str;
	
	cout << ">> ";
	getline(cin,str);

	if (stringError::treatment (str))
		return str;
	return "";
	//return functionSelector(str);
}

//displays the result
void userInterface::output (string str)
{
	cout << ">> " << str << endl;
}
