#ifndef VSGE_CORE_HPP
#define VSGE_CORE_HPP

#include "vsge_drawable.hpp"
#include <vector>
#include <map>

namespace vsge {

	class Layers_container {

		std::map<int, std::vector<Drawable*>> layers;

		std::vector<Drawable*>::iterator findObject(std::vector<Drawable*>& vec, Drawable* object);

		public:

		Layers_container();
		~Layers_container();

		void addToLayer(int layer, Drawable* drawable);
		void deleteFromLayer(Drawable* drawable);

		void draw(sf::RenderWindow* window);
	};

	class Core {

		private:

		sf::RenderWindow* window;
		Layers_container layers;

		Core();
		~Core();

		public:

		void initWindow(char* title);

		// Manage render queues

		static Core& getInstance();
		void pollEvents();
		void render();
		bool isRunning() const;

		// Factories

		Internal_Rectangle* Rectangle_Factory(unsigned layer);

		// Cemeteries

		void Shape_Cementry(Internal_Shape* shape);
	};
}

#endif