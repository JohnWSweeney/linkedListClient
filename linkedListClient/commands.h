#pragma once
#include <iostream>
#include <string>
#include <vector>

struct cmd
{
	std::string serverIP;
	int serverPort;
	std::string demoType;
	std::vector<std::string> func;
	std::vector<std::string> funcInt;
	std::vector<std::string> funcBool;
	std::string demoStatus;
	std::string function;
	int input1;
	int input2;
	int input3;
	bool isAscending;
};

int populateCmd(std::vector<std::string> tokens, cmd &cmd);