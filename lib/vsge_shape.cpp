#include "vsge_shape.hpp"
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

	void Shape::setColor(int i) {
		internal->setColor(i);
	}
}