#include "vsge_loop.hpp"

#include <iostream>
#include <thread>
#include <future>

using namespace vsge;

int user_main_handler() {
	int ret = user_main();
	Core::getInstance().terminate();
	return ret;
}

int main(int argc, char* argv[]) {

	argc = argc;

	Core& engine = Core::getInstance();
	engine.initWindow(argv[0]);
	std::future<int> user_thread = std::async(user_main_handler);

	while (engine.isRunning()) {
		engine.pollEvents();
		engine.render();
	}

	return user_thread.get();
}