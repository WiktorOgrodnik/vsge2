#ifndef VSGE_INTERNAL_SHAPE_HPP
#define VSGE_INTERNAL_SHAPE_HPP

#include "vsge_drawable.hpp"

namespace vsge
{
	class Internal_Shape : public Drawable {

	protected:
		sf::Shape *shape;
		Internal_Shape();

	public: // maybe "friend" in a future

		void Draw(sf::RenderWindow* window) override;
		virtual ~Internal_Shape();

		Vector2f getPosition() override;
		void setPosition(Vector2f pos) override;
		void setColor(int i);
	};
}

#endif