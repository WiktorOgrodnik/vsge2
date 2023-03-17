#include "vsge_drawable.hpp"
#define _GNU_SOURCE
#include <cmath>
#include <cassert>
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

	std::string Internal_Line::printPoint(float x, float y) {
		return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
	}

	float Internal_Line::lineLength(Vector2f point1, Vector2f point2) {
		return sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
	}

	std::pair<float, float> Internal_Line::measureAngle() {

		// cos angle : (a dot b) / (|a| * |b|)
		// we are comparing vector b = [point1.x - center.x, point1.y - center.y] to
		// vector a = [1, 0]

		// So dot product  = (point1.x - center.x) * 1 + (point1.y - center.y) * 0
		// |a| = lineLength(point1, center), |b| = 1 
		float cos = (point1.x - center.x) / lineLength(point1, center);

		// sin angle : sqrt(1 - cos^2)

		assert(1 - cos*cos >= 0);

		float sin = sqrt(1 - cos*cos);
		
		return std::make_pair(sin, cos);
	}

	sf::Vector2f Internal_Line::xyRotation(Vector2f origin, float x, float y, float sin, float cos) {
		// Matrix multiplication to rotate line
		// [x', y'] = [cos  -sin] [x][y]
		//            [sin   cos]

		std::cout << "Before transition: " << printPoint(x, y) << "\n";

		x -= origin.x;
		y -= origin.y;

		std::cout << "After transition: " << printPoint(x, y) << "\n";

		sf::Vector2f new_point = sf::Vector2f(x * cos + y * sin, -y * cos + -x * sin);

		std::cout << "After rotate" << printPoint(new_point.x, new_point.y) << "\n";
		
		new_point.x += origin.x;
		new_point.y += origin.y;

		std::cout << "After transition2: " << printPoint(new_point.x, new_point.y) << "\n";

		return new_point;
	}

	Internal_Line::Internal_Line(int layer,
								 Vector2f point1,
								 Vector2f point2,
								 float thickness,
								 Color color) 
	{
		this->layer = layer;
		this->center = Vector2f((point1.x + point2.x) / 2.0,
								(point1.y + point2.y) / 2.0);

		this->thickness = thickness;
		this->vertex = sf::VertexArray(sf::Quads, 4);

		setPoints(point1, point2);
		setColor(color);
	}

	void Internal_Line::setPoints(Vector2f point1, Vector2f point2) {

		auto [sin, cos] = measureAngle();
		std::cout << "sin: " << sin << "\ncos: " << cos << "\n";

		this->vertex[0].position = xyRotation(point1, point1.x, point1.y - thickness / 2.0, sin, cos);
		this->vertex[1].position = xyRotation(point1, point1.x, point1.y + thickness / 2.0, sin, cos);
		this->vertex[2].position = xyRotation(point2, point2.x, point2.y + thickness / 2.0, sin, cos);
		this->vertex[3].position = xyRotation(point2, point2.x, point2.y - thickness / 2.0, sin, cos);
	}

	void Internal_Line::setThickness(float thickness) {
		this->thickness = thickness;

		setPoints(point1, point2);
	}

	float Internal_Line::getThickness() const {
		return this->thickness;
	}
}