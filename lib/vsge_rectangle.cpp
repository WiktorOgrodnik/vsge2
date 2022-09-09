#include "vsge_rectangle.hpp"
#include "vsge_core.hpp"

namespace vsge {

	Rectangle::Rectangle(int layer) {
		internal = Core::getInstance().Rectangle_Factory(layer);
	}
}