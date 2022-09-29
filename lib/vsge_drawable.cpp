#include "vsge_drawable.hpp"
#define _GNU_SOURCE
#include <cmath>

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

	}

	void Internal_Shape::Draw(Window* window) {
		window->draw(vertex);
	}

	Vector2f Internal_Shape::getPosition() const {
		return center;
	}

	void Internal_Shape::setPosition(Vector2f pos) {

		Vector2f delta = Vector2f(pos.x - center.x, pos.y - center.y);

		for (std::size_t i = 0; i < vertex.getVertexCount(); i++) {
			sf::Vertex& t = vertex[i];
			t.position += sf::Vector2f(delta.x, delta.y);
		}

		center = pos;
	}

	Color Internal_Shape::getColor() const {
		return color;
	}

	void Internal_Shape::setColor(Color color) {

		for (std::size_t i = 0; i < vertex.getVertexCount(); i++) {
			sf::Vertex& t = vertex[i];
			t.color = COLOR_VSGE_TO_SF(color);
		}

		this->color = color;
	}

	// Color Internal_Shape::getOutlineColor() const {
	// 	return color;
	// }

	// void Internal_Shape::setOutlineColor(Color color) {

	// }

	Internal_Rectangle::Internal_Rectangle(int layer,
										   Vector2f position,
										   Vector2f size,
										   Color color)
	{
		this->layer = layer;
		this->center = position;
		vertex = sf::VertexArray(sf::Quads, 4);

		setSize(size);
		setColor(color);
	}

	Vector2f Internal_Rectangle::getSize() const {
		return size;
	}

	void Internal_Rectangle::setSize(Vector2f size) {

		this->size = size;

		for (std::size_t i = 0; i < vertex.getVertexCount(); i++) {
			vertex[i].position = sf::Vector2f(center.x + ((i == 3) | (i == 0) ? -1 : 1) * (size.x / 2), 
											  center.y + (i < 2 ? -1 : 1) * (size.y / 2));
		}
	}

	Internal_Circle::Internal_Circle(int layer,
									 Vector2f position,
									 float radius,
									 Color color)
	{
		this->layer = layer;
		this->center = position;
		vertex = sf::VertexArray(sf::TriangleFan, this->points + 2);


		setRadius(radius);
		setColor(color);
	}

	float Internal_Circle::getRadius() const {
		return radius;
	}

	void Internal_Circle::setRadius(float radius) {
		
		this->radius = radius;

		vertex[0].position = sf::Vector2f(center.x, center.y);

		for (std::size_t i = 1; i < vertex.getVertexCount(); i++) {
			vertex[i].position = sf::Vector2f(center.x + radius * std::cos(2*i*M_PI/this->points),
											  center.y + radius * std::sin(2*i*M_PI/this->points));
		}
	}
}