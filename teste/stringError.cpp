#include <iostream>
#include <boost/regex.hpp>

#include "stringError.h"

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
	return "There are brackets missing";
}


bool stringError::treatment (string input)
{
	// search for invalid characters
	boost::regex validChars("([[:alnum:]]|[[:space:]]|[:=,\\+,\\-,\\*,/,%,\\^,\\.,\\(,\\),;])*");
	if (!boost::regex_match(input, validChars))
	{	
		cout << ">> " << stringError::messages(1) << endl;
		return false;
	}

	// verifies if the first character is alphanumeric, space, '-' or '('
	boost::regex validFirstChar("([[:alnum:]]|\\(|\\-)[[:print:]]*");	
	if (!boost::regex_match(input, validFirstChar))
	{	
		cout << ">> " << stringError::messages(2) << endl;
		return false;
	}

	// verifies if the last character is alphanumeric, space, ';' or ')'
	boost::regex validLastChar("[[:print:]]*([[:alnum:]]|\\)|;)");	
	if (!boost::regex_match(input, validLastChar))
	{	
		cout << ">> " << stringError::messages(3) << endl;
		return false;
	}

	// verifies if all brackets are closed
	int bracketCtrl = 0;
	for (i = 0; i < input.length(); i++)
	{
		if (input[i] == '(')
			bracketCtrl++;
		if (input[i] == ')')
			bracketCtrl--;
		if (bracketCtrl < 0)
		{		
			cout << ">> " << stringError::messages(4) << endl;
			return false;
		}
	};
	if (bracketCtrl != 0)
	{		
		cout << ">> " << stringError::messages(4) << endl;
		return false;
	}

	
	return true;
}

