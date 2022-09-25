#include <iostream>
#include "lib/vsge.hpp"

#include <unistd.h>

using namespace vsge;

void the_other_func() {
	std::cout << "TestTest\n";
}

int main() {

	std::cout << "Hello World!\n";

	Circle circ1(Vector2f(250, 110), 100, Color::Red, 10, false);

	Rectangle rect2(Vector2f(125, 55), Vector2f(50, 50), Color::Red, 5, false);
    {
		Rectangle rect(Vector2f(50, 50), Vector2f(100, 100), Color::Black);
		
		for (int i = 1; i <= 5; i++) {
			std::cout << i << '\n';
			rect.setPosition(Vector2f(50 + (i * 50), 50));
			rect.setColor(Color(0, 0, i * 50));
			the_other_func();
			sleep(1);
			if (i % 2) rect.hide();
			else rect.unhide();
		}
	}


	Rectangle rect3(Vector2f(70, 70), Vector2f(100, 100), Color::Green, 6);
	Rectangle rect4(Vector2f(50, 50), Vector2f(100, 100), Color::Yellow, 4);

	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) rect3.setLayer(3);
		else rect3.setLayer(6);
		sleep(1);
	}

	return 0;
}