#include "vsge_drawable.hpp"

namespace vsge {

	Drawable::Drawable() {

	}

	Drawable::~Drawable() {
		
	}

	Internal_Shape::Internal_Shape() {

	}

	Internal_Shape::~Internal_Shape() {
		delete shape;
	}

	void Internal_Shape::Draw(sf::RenderWindow* window) {
		window->draw(*shape);
	}

	Vector2f Internal_Shape::getPosition() {
		sf::Vector2f pos = shape->getPosition();
		return Vector2f(pos.x, pos.y);
	}

	void Internal_Shape::setPosition(Vector2f pos) {
		shape->setPosition(sf::Vector2f(pos.x, pos.y));
	}

	void Internal_Shape::setColor(int i) {
		switch (i) {
			case 0:
				shape->setFillColor(sf::Color::Black);
				break;
			case 1:
				shape->setFillColor(sf::Color::Red);
				break;
			case 2:
			 	shape->setFillColor(sf::Color::Yellow);
				break;
			default:
				shape->setFillColor(sf::Color::Blue);
				break;
		}
	}

	Internal_Rectangle::Internal_Rectangle() {
		shape = new sf::RectangleShape(sf::Vector2f(100, 100));
		shape->setFillColor(sf::Color::Black);
	}
}