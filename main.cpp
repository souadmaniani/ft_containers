#include <iostream>
#include "includes/vector.hpp"
#include "vector"
#include <string>

int main () {
	ft::vector<int> myvector(30, 9);
	myvector[0] = 4;
	myvector[1] = 5;
	myvector[2] = 6;
	myvector.resize(40, 8);
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << myvector[i] << std::endl;
	}
	std::cout << myvector.capacity() << "|" << myvector.size()  << std::endl;
	std::cout << myvector << std::endl;
	// No, resize ing to a smaller size will never reallocate.
	// while(1) {
	// 	/* code */
	// }
	
  	return 0;
}

