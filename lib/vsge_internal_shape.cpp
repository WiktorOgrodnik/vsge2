#include "vsge_internal_shape.hpp"

namespace vsge {

	Internal_Shape::Internal_Shape() {
		;
	}

	void Internal_Shape::SetPosition(int x, int y) {
		shape->setPosition(sf::Vector2f(x, y));
	}

	void Internal_Shape::Draw(sf::RenderWindow& window) {
		window.draw(*shape);
	}

	Internal_Shape::~Internal_Shape() {
		delete shape;
	}
}