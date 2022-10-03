#include "vsge_common.hpp"

namespace vsge {

	const Color Color::Red     = Color(255, 0,   0);
	const Color Color::Green   = Color(0,   255, 0);
	const Color Color::Blue    = Color(0,   0,   255);
	const Color Color::Yellow  = Color(255, 255, 0);
	const Color Color::Cyan    = Color(0,   255, 255);
	const Color Color::Magenta = Color(255, 0,   255);
	const Color Color::White   = Color(255, 255, 255);
	const Color Color::Black   = Color(0,   0,   0);

	Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
		r = red; g = green; b = blue; a = alpha;
	}
}