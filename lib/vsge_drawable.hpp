#ifndef VSGE_DRAWABLE_HPP
#define VSGE_DRAWABLE_HPP

#include "vsge_config.hpp"

namespace vsge {

	class Drawable {

		public: // Internal API
		
		Drawable();
		virtual ~Drawable();

		virtual void Draw(sf::RenderWindow* window) = 0;

		virtual Vector2f getPosition() = 0;
		virtual void setPosition(Vector2f pos) = 0;
	};
}

#endif