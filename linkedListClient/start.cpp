#include "start.h"
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
	std::vector<std::string> tokens;
	getCommands(tokens);

	if (tokens[0] == "client")
	{
		if (tokens[1] == "start")
		{
			startClientThread();
		}
	}
}