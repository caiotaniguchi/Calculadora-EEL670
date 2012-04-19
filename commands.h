#include <string>

#ifndef COMMANDS_H
#define COMMANDS_H "commands.h"

//commands avaiable: exit, help, list, remove <target>
namespace commands
{
	void exitMain (void);
	std::string help (void);
	std::string list (void);
	std::string remove (std::string input);
}

#endif
