#ifndef VSGE_SHAPE_HPP
#define VSGE_SHAPE_HPP

#include "vsge_common.hpp"

namespace vsge
{
	class Internal_Shape;

	class Shape {

	protected:
		Internal_Shape *internal;

	public:
		Shape();
		virtual ~Shape();
		void setPosition(Vector2f pos);
		void setColor(Color color);
	};

	class Rectangle : public Shape {

	public: 
		Rectangle(int layer = 0);
	};
}

#endif