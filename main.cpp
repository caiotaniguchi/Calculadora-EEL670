#include "userInterface.h"
#include "stringCalc.h"

using namespace std;

int main (void)
{
	bool i = true;	

	do
	{	
		userInterface::output(userInterface::input());
	} while (i == true);
}
