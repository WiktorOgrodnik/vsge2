#include "vsge_loop.hpp"

#include <iostream>
#include <thread>

void user_main_handler() {
	user_main();
	exit(0);
}

using namespace vsge;

int main(int argc, char* argv[]) {

	argc = argc;

	Core& engine = Core::getInstance();
	engine.initWindow(argv[0]);
	std::thread user(user_main_handler);

	while (engine.isRunning()) {
		engine.pollEvents();
		engine.render();
	}

	return 0;
}