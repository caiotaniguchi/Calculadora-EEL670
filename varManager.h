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

	void varSpreadsheet(void);

}

struct varType{
   std::string name;
   double value;
};

#endif
