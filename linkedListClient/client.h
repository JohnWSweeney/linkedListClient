#pragma once
#include <iostream>
#include "commands.h"
#include "tcp.h"

class Client
{
public:
	void connectToServer(cmd &cmd);
	void stateMachine(SOCKET socket, tcp client);
};

void startClient(cmd &cmd);