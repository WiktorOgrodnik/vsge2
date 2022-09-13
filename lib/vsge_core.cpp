#include "vsge_core.hpp"
#include <cassert>

namespace vsge {

	Layers_container::Layers_container() {

	}

	Layers_container::~Layers_container() {

	}

	std::vector<Drawable*>::iterator Layers_container::findObject(std::vector<Drawable*>& vec, Drawable* object) {

		for (auto it = vec.begin(); it != vec.end(); it++) {
			if (*it == object) return it;
		}

		return vec.end();
	}

	void Layers_container::addToLayer(int layer, Drawable* drawable) {
		layers[layer].push_back(drawable);
	}

	void Layers_container::deleteFromLayer(int layer, Drawable* drawable) {

		assert((void("This layer does not exists!"), layers.find(layer) != layers.end()));

		std::vector<Drawable*>& vec = layers[layer];

		auto index = findObject(vec, drawable);

		assert((void("This shape does not exist in the render engine!"), index != vec.end()));

		vec.erase(index);
	}

	void Layers_container::draw(sf::RenderWindow* window) {

		for (auto it = layers.begin(); it != layers.end(); it++) {
			for (auto& k : it->second) {
				k->Draw(window);
			}
		}
	}

	Core::Core() {
		sf::VideoMode videoMode = sf::VideoMode(1024, 768);
		window = new sf::RenderWindow(videoMode, "vsge", sf::Style::Titlebar | sf::Style::Close);
		window->setVerticalSyncEnabled(true);
		window->setFramerateLimit(60);
	}

	Core::~Core() {
		cleanup();
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
		layers.draw(window);
		window->display();
	}

	bool Core::isRunning() const {
		return window->isOpen();
	}

	void Core::terminate() {
		window->close();
	}

	void Core::cleanup() {

		// also layers cleanup in a future

		//delete window; // it causes segfault for some reason!
	}

	// Manage layers

	void Core::addToLayer(int layer, Drawable* drawable) {
		layers.addToLayer(layer, drawable);
	}

	void Core::deleteFromLayer(int layer, Drawable* drawable) {
		layers.deleteFromLayer(layer, drawable);
	}
	
	// Factories

	Internal_Rectangle* Core::Rectangle_Factory(int layer) {

		Internal_Rectangle* t = new Internal_Rectangle(layer);

		layers.addToLayer(layer, t);
		return t;
	}
	
	// Cementries

	void Core::Shape_Cementry(Internal_Shape* shape) {
		layers.deleteFromLayer(shape->getLayer(), shape);
	}
}