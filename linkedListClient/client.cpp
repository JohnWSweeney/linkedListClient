#include "client.h"
#include "tcp.h"
#include "atomicBool.h"
#include <nlohmann/json.hpp>

void convertCmdToString(cmd &cmd, std::string &tempStr)
{
	// convert cmd struct to JSON, then JSON to string.
	nlohmann::json tempJSON;
	tempJSON["demoType"] = cmd.demoType;
	tempJSON["demoStatus"] = cmd.demoStatus;
	tempJSON["function"] = cmd.function;
	tempJSON["input1"] = cmd.input1;
	tempStr = tempJSON.dump();
}

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
	std::cout << "Client started.\n";
	int result = 0;
	std::unique_lock<std::mutex> lk(m);
	cv.notify_one();
	while (clientStatus)
	{
		cv.wait(lk);
		std::string tempStr;
		convertCmdToString(cmd, tempStr);
		// send message to server.
		const char *sendbuf = tempStr.c_str();
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
			//return;
			clientStatus = false;
		}
		cv.notify_one();

		// receive message from server.
		msg newMsg;
		result = client.rx(socket, newMsg.buffer, newMsg.bufferLen);
		if (result == -1) // peer closed connection gracefully.
		{
			client.closeConnection(socket, false);
			clientStatus = false;
			return;
		}
	}
	cv.notify_one();

	// gracefully close connection.
	result = client.closeConnection(socket, true);
	if (result != 0)
	{
		std::cout << "Client::stateMachine.closeConnection failed.\n";
		return;
	}
	std::cout << "Client stopped.\n";
}

void startClient(std::mutex &m, std::condition_variable &cv, cmd &cmd)
{
	Client newClient;
	newClient.connectToServer(m, cv, cmd);
}