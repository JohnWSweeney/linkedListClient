#include "commands.h"

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