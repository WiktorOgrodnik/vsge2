#include "vsge_window.hpp"
#include <cassert>

namespace vsge {

	Window::Window() {
		sf::VideoMode videoMode = sf::VideoMode(1024, 768);
		window = new sf::RenderWindow(videoMode, "vsge", sf::Style::Titlebar | sf::Style::Close);
		window->setVerticalSyncEnabled(true);
		window->setFramerateLimit(60);
	}

	Window::~Window() {
		delete window;
	}

	bool Window::isOpen() const {
		return window->isOpen();
	}

	void Window::close() {
		window->close();
	}

	void Window::pollEvents() {
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

	void Window::clear(const Color& color) {
		window->clear(COLOR_VSGE_TO_SF(color));
	}

	void Window::display() {
		window->display();
	}

	void Window::setTitle(std::string title) {
		window->setTitle(title);
	}

	void Window::draw(sf::VertexArray& vertexArray) {
		window->draw(vertexArray);
	}
}