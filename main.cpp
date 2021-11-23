#include <iostream>
#include "includes/vector.hpp"
#include "vector"
#include <string>

int main () {
	std::vector<int> myvector(30, 9);
	myvector[0] = 4;
	myvector[1] = 5;
	myvector[2] = 6;
	std::cout << "before: "<< &myvector[0] << std::endl;
	myvector.resize(3, 8);
	std::cout << "after: "<< &myvector[0] << std::endl;
	for (size_t i = 0; i < myvector.size(); i++)
	{
		std::cout << myvector[i] << std::endl;
	}
	// No, resize ing to a smaller size will never reallocate.
	// while(1) {
	// 	/* code */
	// }
	
  	return 0;
}

