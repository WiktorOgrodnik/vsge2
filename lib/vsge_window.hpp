#ifndef VSGE_WINDOW_HPP
#define VSGE_WINDOW_HPP

#include "vsge_common.hpp"
#include "vsge_config.hpp"

namespace vsge {

	class Window {

		sf::RenderWindow* window;

	public:

		Window();
		~Window();

		bool isOpen() const;
		void close();

		void pollEvents();
		void clear(const Color& color);
		void display();

		void setTitle(std::string title);

		void draw(sf::Drawable* drawable);
	};
}

#endif