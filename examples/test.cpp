#include <iostream>
#include "lib/vsge.hpp"

#include <unistd.h>

using namespace vsge;

void the_other_func() {
	std::cout << "TestTest\n";
}

int main() {

	std::cout << "Hello World!\n";

	Rectangle* rect = new Rectangle();
	rect->SetPosition(0, 0);

	for (int i = 1; i <= 5; i++) {
		std::cout << i << '\n';
		rect->SetPosition(i * 50, 0);
		the_other_func();
		sleep(1);
	}

	return 0;
}