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
    {
		Rectangle rect(1);
		rect.setPosition(Vector2f(0, 0));
		rect2.setPosition(Vector2f(100, 30));

		rect2.setColor(Color(255, 0, 0));
		
		for (int i = 1; i <= 5; i++) {
			std::cout << i << '\n';
			rect.setPosition(Vector2f(i * 50, 0));
			the_other_func();
			sleep(1);
		}
	}

	sleep(1);

	return 0;
}