#include "vsge_internal_rectangle.hpp"

namespace vsge {

	Internal_Rectangle::Internal_Rectangle() {
		shape = new sf::RectangleShape(sf::Vector2f(100, 100));
		shape->setFillColor(sf::Color::Black);
	}
}