#ifndef VSGE_DRAWABLE_HPP
#define VSGE_DRAWABLE_HPP

#include "vsge_config.hpp"

namespace vsge {

	class Drawable {

	public: // Internal API
		
		Drawable();
		virtual ~Drawable();

		virtual void Draw(sf::RenderWindow* window) = 0;

		virtual Vector2f getPosition() = 0;
		virtual void setPosition(Vector2f pos) = 0;
	};

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

	class Internal_Rectangle : public Internal_Shape {

		public: //maybe "friend" in a future

		Internal_Rectangle();
	};
}

#endif