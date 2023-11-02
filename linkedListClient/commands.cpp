#include "commands.h"
#include "atomicBool.h"

std::vector<std::string> demoTypes = { "sList" };

int checkStringVector(std::string token, std::vector<std::string> strVector, std::string &cmdStr)
{
	if (token.empty())
	{
		return 1;
	}

	auto result = std::find(strVector.begin(), strVector.end(), token);
	if (result != strVector.end())
	{
		cmdStr = token;
		return 0;
	}
	else
	{
		return 1;
	}
}

int getServerIP(std::string token, std::string &serverIP)
{
	if (token == "host")
	{
		serverIP = "127.0.0.1";
	}
	else
	{
		serverIP = token;
	}
	return 0;
}

int getInteger(std::string token, int &integer)
{
	if (token.empty())
	{
		std::cout << "No integer entered.\n";
		return 1;
	}

	try {
		integer = std::stoi(token);
		return 0;
	}
	catch (std::invalid_argument)
	{
		std::cout << "Invalid integer.\n";
		return 1;
	}
	catch (std::out_of_range)
	{
		std::cout << "Integer out of range.\n";
		return 1;
	}
}

int populateCmd(std::vector<std::string> tokens, cmd &cmd)
{
	int result;
	// check if user is starting new client or entering commands for running client, or ...
	if (tokens[0] == "start" and clientStatus == false) // start new client.
	{
		// get server IP address.
		result = getServerIP(tokens[1], cmd.serverIP);
		if (result == 1)
		{
			std::cout << "Invalid server address.\n";
			return 1;
		}
		// get server port number.
		result = getInteger(tokens[2], cmd.serverPort);
		if (result == 1)
		{
			std::cout << "Invalid server port number.\n";
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (tokens[0] == "start" and clientStatus == true) // client running, start demo on server.
	{
		// check if user entered a valid demo type.
		result = checkStringVector(tokens[1], demoTypes, cmd.demoType);
		if (result == 0)
		{
			cmd.demoStatus = "start";
			return 2;
		}
		else
		{
			std::cout << "Invalid demo type.\n";
			return 1;
		}
	}
	else // client is running, get new commands.
	{
		// function
		cmd.function = tokens[0];
		// get integer.
		result = getInteger(tokens[1], cmd.input1);
		return result;
	}
}