#include "vsge_shape.hpp"
#include "vsge_core.hpp"

namespace vsge {

	void Shape::SetPosition(int x, int y) {
		internal->SetPosition(x, y);
	}
}