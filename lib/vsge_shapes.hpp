#ifndef VSGE_SHAPE_HPP
#define VSGE_SHAPE_HPP

#include "vsge_common.hpp"

namespace vsge
{
	class Internal_Shape;
	class Internal_Line;

	class Shape {

	protected:
		Internal_Shape *internal;
		bool hidden;

	public:
		Shape();
		virtual ~Shape();
		Vector2f getPosition() const;
		void setPosition(Vector2f pos, bool animation = false);
		Color getColor() const;
		void setColor(Color color);
		// Color getOutlineColor() const;
		// void setOutlineColor(Color color);

		int getLayer();
		void setLayer(int layer);

		void hide();
		void unhide();
	};

	class Rectangle : public Shape {

	public:
		Rectangle(Vector2f position,
			      Vector2f size,
				  Color color,
				  int layer = 0,
				  bool hidden = false);

		Vector2f getSize() const;
		void setSize(Vector2f size);
	};

	class Circle : public Shape {
	
	public:
		Circle(Vector2f position,
			   float radius,
			   Color color,
			   int layer = 0,
			   bool hidden = false);
		
		float getRadius() const;
		void setRadius(float radius);
	};
}

#endif