#ifndef VSGE_COMMON_HPP
#define VSGE_COMMON_HPP

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
		unsigned r, g, b, a;

		Color(unsigned red, unsigned green, unsigned blue, unsigned alpha = 255);

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