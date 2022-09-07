#include "vsge_shape.hpp"
#include "vsge_core.hpp"

namespace vsge {
	
	Shape::Shape() {}
	Shape::~Shape() {
		Core::getInstance().Shape_Cementry(internal);
		delete internal;
	}

	void Shape::SetPosition(int x, int y) {
		internal->SetPosition(x, y);
	}
}