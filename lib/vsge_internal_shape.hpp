#ifndef VSGE_INTERNAL_SHAPE_HPP
#define VSGE_INTERNAL_SHAPE_HPP

#include "vsge_config.hpp"

namespace vsge
{
	class Internal_Shape {

	protected:
		sf::Shape *shape;
		Internal_Shape();

	public: // maybe "friend" in a future

		void SetPosition(int x, int y); // to replace with vsge point
		void Draw(sf::RenderWindow &window);
	};
}

#endif