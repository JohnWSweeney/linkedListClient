#include "start.h"
#include "commands.h"
#include "threads.h"
#include "atomicBool.h"

void getCommands(std::vector<std::string> &tokens)
{
	do {
		std::string input, tempStr;
		std::getline(std::cin, input, '\n');
		std::stringstream strStream(input);
		while (getline(strStream, tempStr, ' '))
		{
			tokens.push_back(tempStr);
		}
	} while (tokens.empty());
}

void startMenu(bool &running)
{
	cmd cmd;
	int result;

	while(running)
	{
		std::vector<std::string> tokens;
		getCommands(tokens);

		if (tokens[0] == "start")
		{
			result = populateCmd(tokens, cmd);
			if (result == 0)
			{
				clientStatus = true;
				startClientThread(cmd);
			}
		}
	}
}