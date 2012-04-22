#include <vector>
#include <sstream> 

#include "varManager.h"
#include "userInterface.h"



std::vector<varType> varList;

//funciona
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


//funciona
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

