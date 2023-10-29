#pragma once
#include <iostream>
#include <mutex>
#include <condition_variable>
#include "commands.h"
#include "tcp.h"

class Client
{
public:
	void connectToServer(std::mutex &m, std::condition_variable &cv, cmd &cmd);
	void stateMachine(SOCKET socket, tcp client, std::mutex &m, std::condition_variable &cv, cmd &cmd);
};

void startClient(std::mutex &m, std::condition_variable &cv, cmd &cmd);