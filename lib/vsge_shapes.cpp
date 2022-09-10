#include "vsge_shapes.hpp"
#include "vsge_core.hpp"

namespace vsge {
	
	Shape::Shape() {}
	Shape::~Shape() {
		Core::getInstance().Shape_Cementry(internal);
		delete internal;
	}

	void Shape::setPosition(Vector2f pos) {
		internal->setPosition(pos);
	}

	void Shape::setColor(Color color) {
		internal->setColor(color);
	}

	Rectangle::Rectangle(int layer) {
		internal = Core::getInstance().Rectangle_Factory(layer);
	}
}