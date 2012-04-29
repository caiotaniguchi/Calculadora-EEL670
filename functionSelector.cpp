#include "functionSelector.h"
#include "commands.h"
#include "varManager.h"

using namespace std;

std::string functionSelector(std::string input)
{
	if (input.find("clear") != string::npos)
		return commands::clear();
	if (input.find("exit") != string::npos)
		commands::exitMain();
	if (input.find("help") != string::npos)
		return commands::help();
	if (input.find("list") != string::npos)	
		return commands::list();
	if (input.find("remove") != string::npos)
		return commands::remove(input);
	return varManager::numberToVar(input);
}
