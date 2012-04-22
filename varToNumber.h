#include <string>

#ifndef VAR_TO_NUMBER_H
#define VAR_TO_NUMBER_H "varToNumber.h"

namespace varToNumber
{
	// assigns the result from the right of the expression to the variable
	// on the left of the '=' sign
	std::string assignment(std::string);

	// returns the input expression with the variables replaced with its values
	std::string variableToNumber(std::string &);
}

#endif
