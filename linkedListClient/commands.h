#pragma once
#include <iostream>
#include <string>
#include <vector>

struct cmd
{
	std::string serverIP;
	int serverPort;
};

int populateCmd(std::vector<std::string> tokens, cmd &cmd);