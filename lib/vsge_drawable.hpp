#ifndef VSGE_DRAWABLE_HPP
#define VSGE_DRAWABLE_HPP

#include "vsge_window.hpp"

namespace vsge {

	class Drawable {

	protected:

		int layer;
    
	public: // Internal API
		
		Drawable();
		virtual ~Drawable();

		virtual void Draw(Window* window) = 0;

		virtual Vector2f getPosition() const = 0;
		virtual void setPosition(Vector2f pos) = 0;

		int getLayer();
		void setLayer(int layer);
	};

	class Internal_Shape : public Drawable {

	protected:
		sf::Shape* shape;
		Internal_Shape();

	public: // maybe "friend" in a future

		void Draw(Window* window) override;
		virtual ~Internal_Shape();

		Vector2f getPosition() const override;
		void setPosition(Vector2f pos) override;
		Color getColor() const;
		void setColor(Color color);
		Color getOutlineColor() const;
		void setOutlineColor(Color col);
	};

	class Internal_Rectangle : public Internal_Shape {

		public: //maybe "friend" in a future

		Internal_Rectangle(int layer);

		Vector2f getSize() const;
		void setSize(Vector2f size);
	};
}

#endif