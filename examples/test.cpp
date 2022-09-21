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
		float* array[10];
		srand(time(NULL));
		for(int i = 0; i < 10; i++){
			array[i] = new float[5];
			for(int j = 0; j < 5; j++){
				int a = rand();
				
				array[i][j] = (float)(a % 100)/100;
				//std::cout << array[i][j] << "\n";
			}
		}
		Color mapping[2] = {Color(0, 0, 0), Color(255, 0, 0)};
		Grid grid(0, array, 10, 5, 100, mapping);
		for (int i = 0; i < 5; i++) {
			sleep(1);
		}

	}




	return 0;
}
