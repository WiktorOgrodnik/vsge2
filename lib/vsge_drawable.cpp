#include "vsge_drawable.hpp"

namespace vsge {

	Drawable::Drawable() {

	}

	Drawable::~Drawable() {
		
	}

	int Drawable::getLayer() {
		return layer;
	}

	/**
	 * Warning: this function does not change real objects layer! It only changes the number!
	 * Do not use if you do not have to!
	 */
	void Drawable::setLayer(int layer) {
		this->layer = layer;	
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

	Internal_Rectangle::Internal_Rectangle(int layer) {
		this->layer = layer;
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
	Internal_Grid::Internal_Grid(int* array[], int x, int y) {
		shape = new sf::Shape* [10*10];
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                shape[10*i+j] = new sf::RectangleShape(sf::Vector2f(100, 100));
                shape[10*i+j]->setPosition(100*i, 100*j);
                shape[10*i+j]->setFillColor(array[i][j] ? sf::Color::Black : sf::Color::White);
            }
        }
		//shape->setFillColor(sf::Color::Black);
	}
    void Internal_Grid::Draw(sf::RenderWindow* window) {
		for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                window->draw(*shape[10*i+j]);
            }
        }
        
	}
}