#pragma once
#include <iostream>
#include <string>
#include <vector>

struct cmd
{
	std::string serverIP;
	int serverPort;
	std::string function;
	int input1;
};

int populateCmd(std::vector<std::string> tokens, cmd &cmd);