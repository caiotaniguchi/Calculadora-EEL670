#include "userInterface.h"

using namespace std;

int main (void)
{
	string str;
	bool i = true;	

	do
	{	
		str = userInterface::input();
		if (str != "")
			userInterface::output(str);	
	} while (i == true);
}
