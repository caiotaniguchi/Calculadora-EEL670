#ifndef VAR_MANAGER_H
#define VAR_MANAGER_H "varManager.h"

#include <string>

namespace varManager
{

// Assigns the value to the specified variable. If it doesn't
// exist, creates it
void varAssign(std::string, double);

// Returns error code, value is return in the second parameter
int varSearch(std::string, double &);

// Returns error code
int varRemove(std::string);

}

#endif
