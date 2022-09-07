#include "vsge_core.hpp"

namespace vsge {

	Core::Core() {

	}

	Core::~Core() {
		
	}

	Core& Core::getInstance() {
		static Core core;
		return core;
	}

	Internal_Rectangle* Core::Rectangle_Factory() {

		Internal_Rectangle* t = new Internal_Rectangle();

		drawables.push_back(t);
		return t;
	}


}