#include "vsge_core.hpp"

namespace vsge {

	Core::Core() {
		sf::VideoMode videoMode = sf::VideoMode(1024, 768);
		window = new sf::RenderWindow(videoMode, "vsge", sf::Style::Titlebar | sf::Style::Close);
		window->setVerticalSyncEnabled(true);
		window->setFramerateLimit(60);
	}

	Core::~Core() {
		
	}

	void Core::initWindow(char* title) {
		window->setTitle(title);
	}

	Core& Core::getInstance() {
		static Core core;
		return core;
	}

	void Core::pollEvents() {
		sf::Event event;

		while (window->pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed:
					window->close();
					break;
				default:
					break;
			}
		}
	}

	void Core::render() {
		window->clear(sf::Color(sf::Color::White));

		for (auto obj : drawables) {
			obj->Draw(*window);
		}

		window->display();
	}

	bool Core::isRunning() const {
		return window->isOpen();
	}

	Internal_Rectangle* Core::Rectangle_Factory() {

		Internal_Rectangle* t = new Internal_Rectangle();

		drawables.push_back(t);
		return t;
	}


}