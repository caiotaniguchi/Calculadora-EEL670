#include <string>
#include <boost/regex.hpp>

#include "expressionError.h"
#include "userInterface.h"

using namespace std;

bool expressionError (string &expression)
{
	//removes any spaces from the string
	for (unsigned i = 0; i < expression.length(); i++)
		if (isspace(expression[i]))
		{
			expression = expression.substr(0,i) + expression.substr(i+1);
			i--;
		}

	//checks if there is a variable on the left side of the assignment
	/*for (unsigned i = 0; i < expression.length(); i++)
		if (expression[i] == '=')
			for (unsigned j = 0; j < i; j++)
				if (!isalpha(expression[j]))
				{
					userInterface::output (invalidExpression);
					return false;
				}*/

	// searches for operators followed by open parens (eg. (*a+b+))
	// and points not followed nor preceded by digits
	for (unsigned i = 0; i < expression.length(); i++)
	{
		if (expression[i] == '(')
			if (!isalnum(expression[i+1]) && expression[i+1] != '(' && expression[i+1] != ')' && expression[i+1] != '-')
			{
				userInterface::output (invalidExpression);
				return false;
			}
		
		if (i > 0)
		{
			if (expression[i] == '(')			
				if (expression[i-1] != '+' && expression[i-1] != '-' && expression[i-1] != '='
			 		&&	expression[i-1] != '*' && expression[i-1] != '/' && expression[i-1] != '(')
				{
					userInterface::output (invalidExpression);
					return false;
				}
				
			if (expression[i] == (')'))
				if (!isalnum(expression[i-1]) && expression[i-1] != '(' && expression[i+1] != ')'
					&& expression[i-1] != ')')
				{
					userInterface::output (invalidExpression);
					return false;
				}
			if (expression[i] == ('.'))
				if ((!isdigit(expression[i-1])) || (!isdigit(expression[i+1])))
				{
					userInterface::output (invalidExpression);
					return false;
				}
		}
	}
	return true;
}
