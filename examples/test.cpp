#include <iostream>
#include "lib/vsge.hpp"

#include <unistd.h>

using namespace vsge;

void the_other_func() {
	std::cout << "TestTest\n";
}

int main() {

	std::cout << "Hello World!\n";
	//Rectangle rect2(5);
	//rect2.setSize(Vector2f(50, 50));
    {

		//Rectangle rect;
		//rect.SetPosition(0, 0);
		int* array[10];
		srand(time(NULL));
		for(int i = 0; i < 10; i++){
			array[i] = new int[10];
			for(int j = 0; j < 10; j++){
				int a = rand();
				//std::cout << a << "\n";
				array[i][j] = a % 2;
			}
		}
		Grid grid(0, array, 10, 10);
		for (int i = 0; i < 5; i++) {
			sleep(1);
		}

	}




	return 0;
}
