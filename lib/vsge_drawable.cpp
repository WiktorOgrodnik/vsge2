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

	Vector2f Internal_Shape::getPosition() const {
		sf::Vector2f pos = shape->getPosition();
		return Vector2f(pos.x, pos.y);
	}

	void Internal_Shape::setPosition(Vector2f pos) {
		shape->setPosition(sf::Vector2f(pos.x, pos.y));
	}

	Color Internal_Shape::getColor() const {
		const sf::Color col = shape->getFillColor();
		return Color(col.r, col.g, col.b, col.a);
	}

	void Internal_Shape::setColor(Color color) {
		shape->setFillColor(sf::Color(color.r, color.g, color.b, color.a));
	}

	Color Internal_Shape::getOutlineColor() const {
		const sf::Color col = shape->getOutlineColor();
		return Color(col.r, col.g, col.b, col.a);
	}

	void Internal_Shape::setOutlineColor(Color color) {
		shape->setOutlineColor(sf::Color(color.r, color.g, color.b, color.a));
	}

	Internal_Rectangle::Internal_Rectangle() {
		shape = new sf::RectangleShape();
		this->setSize(Vector2f(100, 100));
		this->setColor(Color(0, 0, 0));
	}

	Vector2f Internal_Rectangle::getSize() const {
		sf::Vector2f size = static_cast<sf::RectangleShape*>(shape)->getSize();
		return Vector2f(size.x, size.y);
	}

	void Internal_Rectangle::setSize(Vector2f pos) {
		static_cast<sf::RectangleShape*>(shape)->setSize(sf::Vector2f(pos.x, pos.y));
	}
}