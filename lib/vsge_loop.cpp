#include "vsge_loop.hpp"

#include <iostream>
#include <thread>

void user_main_handler() {
	user_main();
	exit(0);
}

void pollEvents(sf::RenderWindow& window) {
	sf::Event event;

	while (window.pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
		}
	}
}

using namespace vsge;

int main(int argc, char* argv[]) {

	argc = argc;

	std::cout << "This is the vsge loop function!\n";

	sf::VideoMode videoMode = sf::VideoMode(1024, 768);
	sf::RenderWindow window(videoMode, sf::String(argv[0]), sf::Style::Titlebar | sf::Style::Close);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	std::thread user(user_main_handler);

	while (window.isOpen()) {
		window.clear(sf::Color(sf::Color::White));
		pollEvents(window);

		for (auto obj : Core::getInstance().drawables) {
			obj->Draw(window);
		}
		
		window.display();
	}

	return 0;
}