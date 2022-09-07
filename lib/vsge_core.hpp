#ifndef VSGE_CORE_HPP
#define VSGE_CORE_HPP

#include "vsge_internal_rectangle.hpp"
#include <vector>

namespace vsge {

	class Core {

		private:

		std::vector<Internal_Shape*> drawables;

		Core();
		~Core();

		public:

		sf::RenderWindow* window;

		void initWindow(char* title);

		static Core& getInstance();
		void pollEvents();
		void render();
		bool isRunning() const;

		// Factories

		Internal_Rectangle* Rectangle_Factory();

	};


}

#endif