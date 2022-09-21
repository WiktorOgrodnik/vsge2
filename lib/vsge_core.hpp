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
		void deleteFromLayer(int layer, Drawable* drawable);

		void draw(sf::RenderWindow* window);
	};

	class Core {

		private:

		sf::RenderWindow* window;
		Layers_container layers;

		Core();
		~Core();

		void cleanup();

		public:

		void initWindow(char* title);

		// Manage render queues

		static Core& getInstance();
		void pollEvents();
		void render();
		
		// Running and closing

		bool isRunning() const;
		void terminate();

		// Manage layers

		void addToLayer(int layer, Drawable* drawable);
		void deleteFromLayer(int layer, Drawable* drawable);

		// Factories

		Internal_Rectangle* Rectangle_Factory(int layer);
		Internal_Grid* Grid_Factory(int layer, int* array[], int x, int y, int cellSize, Color* mapping);
		Internal_Grid* Grid_Factory(int layer, float* array[], int x, int y, int cellSize, Color* mapping);

		// Cemeteries

		void Shape_Cementry(Internal_Shape* shape);
	};
}

#endif