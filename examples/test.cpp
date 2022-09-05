#include <iostream>
#include "lib/vsge.hpp"

#include <unistd.h>

int main() {

	std::cout << "Hello World!\n";

	for (int i = 0; i < 5; i++) {
		std::cout << i << '\n';
		sleep(1);
	}

	return 0;
}