#pragma once
#include <iostream>
#include "tcp.h"

class Client
{
public:
	void connectToServer();
	void stateMachine(SOCKET socket, tcp client);
};

void startClient();