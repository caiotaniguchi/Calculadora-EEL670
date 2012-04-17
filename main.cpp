#include "userInterface.h"
#include "stringCalc.h"

using namespace std;

int main (void)
{
	string str;
	bool i = true;	

	do
	{	
		str = userInterface::input();
		if (str != "")
			userInterface::output(stringCalc(str));	
	} while (i == true);
}
