#ifndef VSGE_CORE_HPP
#define VSGE_CORE_HPP

#include "vsge_internal_rectangle.hpp"
#include <vector>

namespace vsge {

	class Core {

		private:

		sf::RenderWindow* window;
		std::vector<Internal_Shape*> drawables;

		Core();
		~Core();

		std::vector<Internal_Shape*>::iterator findObject(Internal_Shape* object);

		public:

		void initWindow(char* title);

		// Manage render queues

		static Core& getInstance();
		void pollEvents();
		void render();
		bool isRunning() const;

		// Factories

		Internal_Rectangle* Rectangle_Factory();

		// Cemeteries

		void Shape_Cementry(Internal_Shape* shape);
	};
}

#endif