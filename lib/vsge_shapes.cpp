#include "vsge_shapes.hpp"
#include "vsge_core.hpp"

namespace vsge {

	Shape::Shape() {
		hidden = false;
	}

	Shape::~Shape() {
		if (!hidden) Core::getInstance().Shape_Cementry(internal);

		delete internal;
	}

	Vector2f Shape::getPosition() const {
		return internal->getPosition();
	}

	void Shape::setPosition(Vector2f pos, bool animated) {
		internal->setPosition(pos);
	}

	Color Shape::getColor() const {
		return internal->getColor();
	}

	void Shape::setColor(Color color) {
		internal->setColor(color);
	}

	// Color Shape::getOutlineColor() const {
	// 	return internal->getOutlineColor();
	// }

	// void Shape::setOutlineColor(Color color) {
	// 	internal->setOutlineColor(color);
	// }

	int Shape::getLayer() {
		return internal->getLayer();
	}

	void Shape::setLayer(int layer) {
		if (layer != internal->getLayer()) {
			if (!hidden) Core::getInstance().deleteFromLayer(internal->getLayer(), internal);
			internal->setLayer(layer);
			if (!hidden) Core::getInstance().addToLayer(internal->getLayer(), internal);
		}
	}

	void Shape::hide() {
		if (!hidden) {
			Core::getInstance().deleteFromLayer(internal->getLayer(), internal);
			hidden = true;
		}
	}

	void Shape::unhide() {
		if (hidden) {
			Core::getInstance().addToLayer(internal->getLayer(), internal);
			hidden = false;
		}
	}

	Rectangle::Rectangle(Vector2f position,
						 Vector2f size,
						 Color color,
						 int layer,
						 bool hidden)
	{
		internal = Core::getInstance().Rectangle_Factory(layer, position, size, color);
	}

	Vector2f Rectangle::getSize() const {
		return static_cast<Internal_Rectangle*>(internal)->getSize();
	}

	void Rectangle::setSize(Vector2f size) {
		return static_cast<Internal_Rectangle*>(internal)->setSize(size);
	}
}