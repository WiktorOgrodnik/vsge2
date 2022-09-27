#ifndef VSGE_COMMON_HPP
#define VSGE_COMMON_HPP

#include <cstdint>

namespace vsge {

	template <typename T>
	class Vector2 {
	public:
		T x, y;

		Vector2(const T& x, const T& y) {
			this->x = x;
			this->y = y;
		}
	};

	typedef Vector2<unsigned> Vector2u;
	typedef Vector2<float> Vector2f;

	class Color {
	public:
		uint8_t r, g, b, a;

		Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255);

		static const Color Red;
		static const Color Green;
		static const Color Blue;
		static const Color Yellow;
		static const Color Cyan;
		static const Color Magenta;
		static const Color White;
		static const Color Black;
	};
}

#endif