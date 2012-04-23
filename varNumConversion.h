#include <string>

#ifndef VAR_NUM_CONVERSION_H
#define VAR_NUM_CONVERSION_H "varNumConversion.h"

namespace varNumConversion
{
	// assigns the result from the right of the expression to the variable
	// on the left of the '=' sign
	std::string numberToVar(std::string);

	// returns the input expression with the variables replaced with its values
	std::string varToNumber(std::string &);
}

#endif
