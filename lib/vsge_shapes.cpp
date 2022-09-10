#include "vsge_shapes.hpp"
#include "vsge_core.hpp"

namespace vsge {
	
	Shape::Shape() {
		hidden = false;
	}

	Shape::~Shape() {
		Core::getInstance().Shape_Cementry(internal);
		delete internal;
	}

	Vector2f Shape::getPosition() const {
		return internal->getPosition();
	}

	void Shape::setPosition(Vector2f pos, bool animated) {
		internal->setPosition(pos);
	}

	Color Shape::getColor() const {
		return internal->getColor();
	}

	void Shape::setColor(Color color) {
		internal->setColor(color);
	}

	// Color Shape::getOutlineColor() const {
	// 	return internal->getOutlineColor();
	// }

	// void Shape::setOutlineColor(Color color) {
	// 	internal->setOutlineColor(color);
	// }

	Rectangle::Rectangle(int layer, bool hidden) {
		internal = Core::getInstance().Rectangle_Factory(layer);
	}

	Vector2f Rectangle::getSize() const {
		return static_cast<Internal_Rectangle*>(internal)->getSize();
	}

	void Rectangle::setSize(Vector2f size) {
		return static_cast<Internal_Rectangle*>(internal)->setSize(size);
	} 
}