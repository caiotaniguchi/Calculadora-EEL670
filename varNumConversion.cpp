#include "varNumConversion.h"
#include "stringCalc.h"
#include "varManager.h"
#include "userInterface.h"
#include "expressionError.h"

using namespace std;

string varNumConversion::numberToVar(string expression)
{

	unsigned i = 0;
	unsigned numberOfAssignments = 0;
	string numericExpression, assignedVariable, result;

	if (!expressionError (expression))
		return "";

	// searches for ';' and splits the expression in two or more
	for (; i < expression.length(); i++)
	{
		if (expression[i] == ';')
		{
			varNumConversion::numberToVar(expression.substr(0,i));
			return varNumConversion::numberToVar(expression.substr(i+1));
		}
	}

	for (unsigned j = 0; j < expression.length(); j++)
		if (expression[j] == '=')
			for (unsigned k = 0; k < j; k++)
				if (!isalpha(expression[k]))
				{
					userInterface::output (invalidExpression);
					return "";
				}

	// separates the assigned variable from the rest of
	// the expression
	for (i = 0; i < expression.length(); i++)
	{
		if (expression[i] == '=')
		{
			assignedVariable = expression.substr(0,i);
			expression = expression.substr(i+1);
			numberOfAssignments++;
		}
	}

	// verifies if there is only one assigment and calculates the value
	// of the expression to assign
	if (numberOfAssignments == 1)
	{
		//&& expression.find(varNotFound)
		while (expression.compare("") != 0 )
			numericExpression += varNumConversion::varToNumber(expression);
		result = stringCalc(numericExpression);
		if (result.compare("") != 0 )
			varManager::varAssign(assignedVariable, strToDouble(result));
		else
			varManager::varAssign(assignedVariable, 0);
	}
	else
	{
		while (expression.compare("") != 0)
			numericExpression += varNumConversion::varToNumber(expression);
		result = stringCalc(numericExpression);
	}
	return result;
}


string varNumConversion::varToNumber(string &expression)
{

	string var, newExpression, preVar;
	double varValue = 0;
	unsigned i = 0;
	unsigned j = 0;

	// searches for variables (alpha chars)
	for (i = 0; i < expression.length(); i++)
	{
		if (isalpha(expression[i]))
		j++;
	}

	// if variables don't exist, returns the input expression
	if (j == 0)
	{
		var = expression;
		expression = "";
		return var;
	}

	// preVar stores everything before the first variable
	for (i = 0; !isalpha(expression[i]); i++);
	preVar = expression.substr(0,i);

	for (j = i; isalpha(expression[j]); j++);
	if (expression.compare("") == 0)
		return expression;

	// var stores the variable value, if found
	var = expression.substr(i,(j-i));
	if (!varManager::varSearch(var, varValue))
	{
		userInterface::output (varNotFound);
		expression = "";
		return varNotFound;
	}
	var = doubleToStr(varValue);
	for (i = j; !isalpha(expression[i]) && i < expression.length(); i++);

	// the concatenation of preVar, var and everything that comes after
	// is returned in newExpression
	newExpression = preVar + var + expression.substr(j, i-j);
	if (expression.length() == 1)
		expression = "";
	else
		expression = expression.substr(i);
	return newExpression;
}


