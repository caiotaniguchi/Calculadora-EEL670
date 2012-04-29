#ifndef VAR_MANAGER_H
#define VAR_MANAGER_H "varManager.h"

#include <string>

namespace varManager
{

	// Assigns the value to the specified variable. If it doesn't
	// exist, creates it
	void varAssign(std::string, double);

	// Returns error code, value is returned in the second parameter
	bool varSearch(std::string, double &);

	// Returns error code
	bool varRemove(std::string);

	// Prints a spreadsheet of the variables stored
	void varSpreadsheet(void);

	// Replaces a variable with its value in an expression
	std::string varToNumber(std::string &);

	// Assigns a value to a variable
	std::string numberToVar(std::string);
}

struct varType{
   std::string name;
   double value;
};

#endif
