#include "client.h"
#include "tcp.h"
#include "atomicBool.h"
#include <nlohmann/json.hpp>

struct cmd
{
	std::string function;
	int integer;
};

void Client::connectToServer()
{
	tcp client;
	SOCKET socket = INVALID_SOCKET;
	int result = client.openClientSocket(socket, "127.0.0.1", 123);
	if (result != 0)
	{
		std::cout << "Client: message.openClientSocket failed.\n";
		closesocket(socket);
		WSACleanup();
		return;
	}
	this->stateMachine(std::move(socket), std::move(client));
}

void Client::stateMachine(SOCKET socket, tcp client)
{
	//
	cmd test;
	test.function = "init";
	test.integer = 1234;

	nlohmann::json j;
	j["function"] = test.function;
	j["integer"] = test.integer;
	std::string s = j.dump();

	// send message to server.
	const char *sendbuf = s.c_str();
	int len = (int)strlen(sendbuf);
	int result = client.tx(socket, sendbuf, len);
	if (result > 0)
	{
		std::cout << "Client sent: " << sendbuf << '\n';
	}
	else if (result == -1)
	{
		std::cout << "Client: message.tx failed.\n";
		closesocket(socket);
		WSACleanup();
		return;
	}

	// gracefully close connection.
	result = client.closeConnection(socket, true);
	if (result != 0)
	{
		std::cout << "Client: message.closeConnection failed.\n";
		return;
	}
	std::cout << "Client: message ended.\n";
}

void startClient()
{
	Client newClient;
	newClient.connectToServer();
}