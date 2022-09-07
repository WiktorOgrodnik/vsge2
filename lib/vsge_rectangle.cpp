#include "vsge_rectangle.hpp"
#include "vsge_core.hpp"

namespace vsge {

	Rectangle::Rectangle() {
		internal = Core::getInstance().Rectangle_Factory();
	}

	Rectangle::~Rectangle() {
		
	}
}