#ifndef VSGE_SHAPE_HPP
#define VSGE_SHAPE_HPP

namespace vsge {

	class Internal_Shape;

	class Shape {

		protected:

		Internal_Shape* internal;

		public:

		Shape() {};
		virtual ~Shape() {};
		void SetPosition(int x, int y); // to replace with vsge point
	};

}

#endif