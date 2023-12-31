#include "threads.h"
#include "client.h"
#include "atomicBool.h"

void startClientThread(std::mutex &m, std::condition_variable &cv, cmd &cmd)
{
	try {
		clientStatus = true;
		std::thread clientThread(startClient, std::ref(m), std::ref(cv), std::ref(cmd));
		clientThread.detach();
	}
	catch (...)
	{
		clientStatus = false;
		std::cout << "Client start failed.\n";
	}
}