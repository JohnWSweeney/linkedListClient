#include "threads.h"
#include "client.h"
#include "atomicBool.h"

void startClientThread()
{
	try {
		clientStatus = true;
		std::thread clientThread(startClient);
		clientThread.detach();
	}
	catch (...)
	{
		std::cout << "Client start failed.\n";
	}
}