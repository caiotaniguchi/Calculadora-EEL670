#include <vector>
#include <sstream> 

#include "varManager.h"
#include "userInterface.h"
#include "stringCalc.h"
#include "expressionError.h"

std::vector<varType> varList;

void varManager::varAssign(std::string id, double val)
{
   struct varType newVar;
   newVar.name = id;
   newVar.value = val;
   for (register unsigned i = 0 ; i < varList.size() ; i++)
   {
      if (varList[i].name == newVar.name)
      {
         varList[i].value = newVar.value;
         return;
      }
   }
   varList.push_back(newVar);
}


bool varManager::varSearch(std::string id, double &val)
{
   for (register unsigned i = 0 ; i < varList.size() ; i++)
   {
      if (varList[i].name == id)
      {
         val = varList[i].value;
         return true;
      }
   }
   return false;
}

bool varManager::varRemove(std::string id)
{
   for (register unsigned i = 0 ; i < varList.size() ; i++)
   {
      if (varList[i].name == id)
      {
         varList.erase(varList.begin()+i);
         return true;
      }
   }
   return false;
}

void varManager::varSpreadsheet(void)
{

	std::string output;
	std::ostringstream line;
	
	line << "";
	line.clear();
	for (register unsigned i = 0 ; i < varList.size() ; i++)
	{	
		line << '\t' << varList[i].name << "\t\t\t" << varList[i].value << std::endl << ">>";
		output = line.str();
	}
	userInterface::output (output);
}


std::string varManager::numberToVar(std::string expression)
{

	unsigned i = 0;
	unsigned numberOfAssignments = 0;
	std::string numericExpression, assignedVariable, result;

	if (!expressionError (expression))
		return "";

	// searches for ';' and splits the expression in two or more
	for (; i < expression.length(); i++)
	{
		if (expression[i] == ';')
		{
			varManager::numberToVar(expression.substr(0,i));
			return varManager::numberToVar(expression.substr(i+1));
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
			numericExpression += varManager::varToNumber(expression);
		result = stringCalc(numericExpression);
		if (result.compare("") != 0 )
			varManager::varAssign(assignedVariable, strToDouble(result));
		else
			varManager::varAssign(assignedVariable, 0);
	}
	else
	{
		while (expression.compare("") != 0)
			numericExpression += varManager::varToNumber(expression);
		result = stringCalc(numericExpression);
	}
	return result;
}


std::string varManager::varToNumber(std::string &expression)
{

	std::string var, newExpression, preVar;
	double varValue = 0;
	unsigned i = 0;
	unsigned j = 0;

	// searches for variables (alpha chars)
	for (; i < expression.length(); i++)
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
