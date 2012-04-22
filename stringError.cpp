#include <cctype>
#include <boost/regex.hpp>

#include "stringError.h"
#include "userInterface.h"

using namespace std;

string stringError::messages(int error)
{
	switch (error)
	{	
		case 1:
			return "Invalid character";
		case 2:
			return "Only alphanumeric characters '-' or '(' can begin a sentence";
		case 3:
			return "Only alphanumeric characters, ';' or ')' can end a sentence";			
	};
	return "There are parens missing";
}

bool stringError::treatment (string input)
{
	
	// searches for invalid characters
	boost::regex validChars("([[:alnum:]]|[[:space:]]|[=,\\+,\\-,\\*,/,%,\\^,\\.,\\(,\\),;])*");
	if (!boost::regex_match(input, validChars))
	{	
		userInterface::output (stringError::messages(1));
		return false;
	}

	// verifies if the first character is alphanumeric, '-' or '('
	boost::regex validFirstChar("([[:alnum:]]|\\(|\\-)[[:print:]]*");	
	if (!boost::regex_match(input, validFirstChar))
	{	
		userInterface::output (stringError::messages(2));
		return false;
	}

	// verifies if the last character is alphanumeric, ';' or ')'
	boost::regex validLastChar("[[:print:]]*([[:alnum:]]|\\)|;)");	
	if (!boost::regex_match(input, validLastChar))
	{	
		userInterface::output (stringError::messages(3));
		return false;
	}

	// verifies if all brackets are closed
	int bracketCtrl = 0;
	for (unsigned i = 0; i < input.length(); i++)
	{
		if (input[i] == '(')
			bracketCtrl++;
		if (input[i] == ')')
			bracketCtrl--;
		if (bracketCtrl < 0)
		{		
			userInterface::output (stringError::messages(4));
			return false;
		}
	};
	if (bracketCtrl != 0)
	{		
		userInterface::output (stringError::messages(4));
		return false;
	}

	
	return true;
}

