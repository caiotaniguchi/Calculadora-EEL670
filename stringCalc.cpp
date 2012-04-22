#include <sstream>
#include <locale>

#include "stringCalc.h"

// Receives an expression and returns a string containing the result.
// This function does not detect errors on the expression. The expression
// must contain no spaces and must have a matching number of ( and ).
// It must only contain numbers, (, ), +, -, *, /.
// The numbers can be integer or real.

double strToDouble(std::string s)
{
   std::istringstream st(s);
   double result;
   st >> result;
   return result;
}


std::string doubleToStr(double d)
{
   std::ostringstream st;
   st << d;
   return st.str();
}


std::string stringCalc(std::string expression)
{
   std::string subExpression, subExpression2, result, result2;
   int startPos, endPos;
   double val1, val2;
	
   
   do                    // Searches for (), calculates the expression inside, then
   {                     // replaces the () with the result. Will start from the
      startPos = -1;     // innermost (). Repeats until there are no more ().
      endPos = -1;
      for(register int i = 0 ; unsigned(i) < expression.length() ; i++)
      {
         if (expression[i] == '(')
         {
            startPos = i;
            for (register int j = i; unsigned(j) < expression.length() ; j++)
            {
               if (expression[j] == ')')
               {
                  endPos = j;
                  break;
               }
            }
         }
      }
      if (startPos != -1)   // () found
      {
         subExpression = expression.substr(startPos+1, endPos-startPos-1);
         result = stringCalc(subExpression);  // Calls same function with expression inside ()
         expression.erase(startPos, endPos-startPos+1);
         expression.insert(startPos, result);
      }
   }
   while(startPos != -1);
   
   // At this point the expression will have no ( or ) and only numbers, +, -, *, /
   
   do     // Searches for + and - then calculates the rest of the expression
   {      // Will calculate last the + or - that is most to the right
      startPos = -1;
      for(register int i = 0 ; unsigned(i) < expression.length() ; i++)
      {
         if ((expression[i] == '+')||(expression[i] == '-'))
         {
            startPos = i;
         }
      }
           // Expression[startPos] is the last + or - found in the entire string
      if (startPos != -1)
      {
      
         if(expression[startPos]=='-')   // Special case for negative numbers
         {
            if(startPos > 0)
            {
               if(!isdigit(expression[startPos-1]))
               {
                  endPos = startPos;
                  for(register int i = 0 ; unsigned(i) < startPos ; i++)
                  {
                     if ((expression[i] == '+')||(expression[i] == '-'))
                     {
                        startPos = i;
                     }
                  }
                  if (startPos == endPos)
                  {
                     break;
                  }
               }
            }
            else
            {
               break;
            }
         }
                      // Separates the 2 expressions before and after the + or -
         subExpression = expression.substr(0, startPos);
         subExpression2 = expression.substr(startPos+1, expression.length()-startPos);
         result = stringCalc(subExpression);     // Calls the same function for
         result2 = stringCalc(subExpression2);   // each of the new expressions
         val1 = strToDouble(result);
         val2 = strToDouble(result2);
         if (expression[startPos] == '+')
         {
            expression = doubleToStr(val1 + val2);
         }
         else
         {
            expression = doubleToStr(val1 - val2);
         }
         
      }
   }
   while(startPos != -1);
   
   do     // Searches for * and / then calculates the rest of the expression
   {      // Same logic as the +- block
      startPos = -1;
      for(register int i = 0 ; unsigned(i) < expression.length() ; i++)
      {
         if ((expression[i] == '*')||(expression[i] == '/'))
         {
            startPos = i;
         }
      }
      if (startPos != -1)
      {
         subExpression = expression.substr(0, startPos);
         subExpression2 = expression.substr(startPos+1, expression.length()-startPos);
         result = stringCalc(subExpression);
         result2 = stringCalc(subExpression2);
         val1 = strToDouble(result);
         val2 = strToDouble(result2);
         if(expression[startPos] == '*')
         {
            expression = doubleToStr(val1 * val2);
         }
         else
         {
            expression = doubleToStr(val1 / val2);
         }
         
      }
   }
   while(startPos != -1);
   
   if (expression.length() == 0)  // If the expression is empty, assume 0
   {                              // Used to calculate negative numbers
      expression = "0";
   }
   
   return expression;
}
