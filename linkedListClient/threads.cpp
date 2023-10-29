#include "threads.h"
#include "client.h"
#include "atomicBool.h"

void startClientThread(cmd &cmd)
{
	try {
		clientStatus = true;
		std::thread clientThread(startClient, std::ref(cmd));
		clientThread.detach();
	}
	catch (...)
	{
		std::cout << "Client start failed.\n";
	}
}