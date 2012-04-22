#include <string>

#ifndef COMMANDS_H
#define COMMANDS_H "commands.h"

//commands avaiable: clear, exit, help, list, remove <target>
namespace commands
{
	// clears the screen
	std::string clear (void);

	//exits the program
	void exitMain (void);

	//shows a help message
	std::string help (void);

	//prints a spreadsheet with all the
	//storaged variables
	std::string list (void);

	//removes the target variable
	std::string remove (std::string input);
}

#endif
