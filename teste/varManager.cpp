#include <vector>
#include "varManager.h"

struct varType{
   std::string name;
   double value;
};

std::vector<varType> varList;

void varManager::varAssign(std::string id, double val)
{
   struct varType newVar;
   newVar.name = id;
   newVar.value = val;
   for (register int i = 0 ; i < varList.size() ; i++)
   {
      if (varList[i].name == newVar.name)
      {
         varList[i].value = newVar.value;
         return;
      }
   }
   varList.push_back(newVar);
}

int varManager::varSearch(std::string id, double &val)
{
   for (register int i = 0 ; i < varList.size() ; i++)
   {
      if (varList[i].name == id)
      {
         val = varList[i].value;
         return 0;
      }
   }
   return 1;
}

int varManager::varRemove(std::string id)
{
   for (register int i = 0 ; i < varList.size() ; i++)
   {
      if (varList[i].name == id)
      {
         varList.erase(varList.begin()+i);
         return 0;
      }
   }
   return 1;
}
