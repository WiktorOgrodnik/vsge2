#ifndef VSGE_CORE_HPP
#define VSGE_CORE_HPP

#include "vsge_internal_rectangle.hpp"
#include <vector>

namespace vsge {

	class Core {

		private:

		Core();
		~Core();

		public:

		sf::RenderWindow window;

		static Core& getInstance();

		// Factories

		Internal_Rectangle* Rectangle_Factory();

		std::vector<Internal_Shape*> drawables;

	};


}

#endif