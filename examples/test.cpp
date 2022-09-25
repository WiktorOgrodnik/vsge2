#include <iostream>
#include "lib/vsge.hpp"

#include <unistd.h>

using namespace vsge;

void the_other_func() {
	std::cout << "TestTest\n";
}

int main() {

	std::cout << "Hello World!\n";
	Rectangle rect2(5);
	rect2.setSize(Vector2f(50, 50));
    {
		Rectangle rect(1);
		rect.setPosition(Vector2f(0, 0));
		rect2.setPosition(Vector2f(100, 30));

		rect2.setColor(Color::Red);
		
		for (int i = 1; i <= 5; i++) {
			std::cout << i << '\n';
			rect.setPosition(Vector2f(i * 50, 0));
			rect.setColor(Color(0, 0, i*50));
			the_other_func();
			sleep(1);
			if (i % 2) rect.hide();
			else rect.unhide();
		}
	}


	Rectangle rect3(6); rect3.setColor(Color::Green); rect3.setPosition(Vector2f(20, 20));
	Rectangle rect4(4); rect4.setColor(Color::Yellow); rect4.setPosition(Vector2f(0, 0));

	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) rect3.setLayer(3);
		else rect3.setLayer(6);
		sleep(1);
	}
	
	return 0;
}