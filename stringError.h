#include <string>

#ifndef STRING_ERROR_H
#define STRING_ERROR_H "stringError.h"

// verifies if the input string is valid
// and if not returns an error message
namespace stringError
{
	std::string messages(int error);
	bool treatment (std::string input);
}

#endif
