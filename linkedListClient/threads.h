#pragma once
#include <iostream>
#include <mutex>
#include <condition_variable>
//#include <thread>
#include "commands.h"

void startClientThread(std::mutex &m, std::condition_variable &cv, cmd &cmd);