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
}

#endif