#include "client.h"
#include "tcp.h"
#include "atomicBool.h"
#include <nlohmann/json.hpp>

//struct cmdJSON
//{
//	std::string function;
//	int integer;
//};

void Client::connectToServer(std::mutex &m, std::condition_variable &cv, cmd &cmd)
{
	tcp client;
	SOCKET socket = INVALID_SOCKET;
	int result = client.openClientSocket(socket, cmd.serverIP, cmd.serverPort);
	if (result != 0)
	{
		std::cout << "Client::connectToServer failed.\n";
		closesocket(socket);
		WSACleanup();
		return;
	}
	this->stateMachine(std::move(socket), std::move(client), std::ref(m), std::ref(cv), std::ref(cmd));
}

void Client::stateMachine(SOCKET socket, tcp client, std::mutex &m, std::condition_variable &cv, cmd &cmd)
{
	//
	//cmdJSON test;
	//test.function = "init";
	//test.integer = 1234;
	int result = 0;

	std::unique_lock<std::mutex> lk(m);
	cv.notify_one();
	while (result == 0)
	{
		cv.wait(lk);

		nlohmann::json j;
		//j["function"] = test.function;
		//j["integer"] = test.integer;
		j["function"] = cmd.function;
		j["integer"] = cmd.input1;

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
		cv.notify_one();
	}
	cv.notify_one();

	// gracefully close connection.
	result = client.closeConnection(socket, true);
	if (result != 0)
	{
		std::cout << "Client: message.closeConnection failed.\n";
		return;
	}
	std::cout << "Client: message ended.\n";
}

void startClient(std::mutex &m, std::condition_variable &cv, cmd &cmd)
{
	Client newClient;
	newClient.connectToServer(m, cv, cmd);
}