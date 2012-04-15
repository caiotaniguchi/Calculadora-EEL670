#include <iostream>

#include "stringError.h"

using namespace std;

string stringError::messages(int error)
{
	switch (error)
	{	
		case 1:
			return "Invalid character";
		case 2:
			return "Only alphanumeric characters and '(' can begin a sentence";
		case 3:
			return "Only alphanumeric characters, ';' and ')' can end a sentence";
		case 4:
			return "There are brackets missing";
	};
}


bool stringError::treatment (string input)
{
	// search for invalid characters
	int i = 0;
	for (; i < input.length(); i++)
		if (!(isalnum(input[i])) && (!(isspace(input[i]))) && (input[i] != ':')
		    && (input[i] != '=') && (input[i] != '+') && (input[i] != '-')
		    && (input[i] != '*') && (input[i] != '/') && (input[i] != '^')
		    && (input[i] != '.') && (input[i] != '(') && (input[i] != ')')
		    && (input[i] != '%'))
		{		
			cout << ">> " << stringError::messages(1) << endl;
			return false;
		}

	// verifies if the first character is alphanumeric, space, '-' or '('
	if ((!isalnum(input[0])) && (!isspace(input[0]))
	    && (input[0] != '(') && (input[0] != '-') && (input[0] != '\n'))
	{		
		cout << ">> " << stringError::messages(2) << endl;
		return false;
	}

	// verifies if the last character is alphanumeric, space, ';' or ')'
	if (!(isalnum(input[i-1])) && !(isspace(input[i-1]))
	    && (input[i-1] != ';') && (input[i-1] != ')'))
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

