#include <cstdlib>

#include "functionSelector.h"
#include "stringCalc.h"
#include "commands.h"

using namespace std;

string functionSelector(string input)
{
	if (input.find("exit") != string::npos)
		commands::exitMain();
	if (input.find("help") != string::npos)
		return commands::help();
	if (input.find("vars") != string::npos)	
		return commands::spreadsheet();
	if (input.find("remove") != string::npos)
		return commands::remove(input);
	return stringCalc(input);
}
