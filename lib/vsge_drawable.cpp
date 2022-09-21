#include "vsge_drawable.hpp"
#include <iostream>
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
	Internal_Grid::Internal_Grid(int* array[], int x, int y, int cellSize, Color* mapping) : colorMode(LIST), size(x, y) {
		shape = new sf::Shape* [x*y];
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                shape[y*i+j] = new sf::RectangleShape(sf::Vector2f(cellSize, cellSize));
                shape[y*i+j]->setPosition(cellSize*i, cellSize*j);
				Color c = mapping[array[i][j]];
                shape[y*i+j]->setFillColor(sf::Color(c.r, c.g, c.b, c.a));
            }
        }
	}
	Internal_Grid::Internal_Grid(float* array[], int x, int y, int cellSize, Color* mapping) : colorMode(GRADIENT), size(x, y) {
		shape = new sf::Shape* [x*y];
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                shape[y*i+j] = new sf::RectangleShape(sf::Vector2f(cellSize, cellSize));
                shape[y*i+j]->setPosition(cellSize*i, cellSize*j);
				Color low = mapping[0], high = mapping[1];
				
                shape[y*i+j]->setFillColor(sf::Color(low.r+(int)(array[i][j]*(high.r-low.r)), low.g+(int)(array[i][j]*(high.g-low.g)), low.b+(int)(array[i][j]*(high.b-low.b)), low.a+(int)(array[i][j]*(high.a-low.a))));
            }
        }
	}
    void Internal_Grid::Draw(sf::RenderWindow* window) {
		for(int i = 0; i < size.x; i++){
            for(int j = 0; j < size.y; j++){
                window->draw(*shape[size.y*i+j]);
            }
        }
        
	}
	Vector2u Internal_Grid::getSize() const {
		return size;
	}
}