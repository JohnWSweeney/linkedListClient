#include "client.h"
#include "tcp.h"
#include "atomicBool.h"

void Client::run()
{
	this->message();
}

void Client::message()
{
	tcp message;
	SOCKET socket = INVALID_SOCKET;
	int result = message.openClientSocket(socket, "127.0.0.1", 123);
	if (result != 0)
	{
		std::cout << "Client: message.openClientSocket failed.\n";
		closesocket(socket);
		WSACleanup();
		return;
	}

	// send message to server.
	const char *sendbuf = "hellyeah";
	int len = (int)strlen(sendbuf);
	result = message.tx(socket, sendbuf, len);
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
	result = message.closeConnection(socket, true);
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
	newClient.run();
}